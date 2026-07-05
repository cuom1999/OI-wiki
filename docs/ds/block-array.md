<span id="xây-dựng-mảng-chia-khối"></span>
## Xây dựng mảng chia khối

Mảng chia khối là cách chia một mảng thành vài khối
và lưu thông tin tổng hợp bên trong mỗi khối.
Khi truy vấn gặp hai khối biên không đầy đủ,
các phần tử ở hai biên được xử lý trực tiếp bằng vét cạn.
Thông thường, độ dài khối là $O(\sqrt{n})$.
Phần phân tích chi tiết có thể xem trong bài viết của Xu Mingkuan,
"Bước đầu tìm hiểu thuật toán chia khối kích thước phi thông thường",
trong tuyển tập luận văn đội tuyển quốc gia năm 2017.

Dưới đây là một cách xây dựng mảng chia khối.

???+ note "Cài đặt"
    ```cpp
    num = sqrt(n);
    for (int i = 1; i <= num; i++)
      st[i] = n / num * (i - 1) + 1, ed[i] = n / num * i;
    ed[num] = n;
    for (int i = 1; i <= num; i++) {
      for (int j = st[i]; j <= ed[i]; j++) {
        belong[j] = i;
      }
      size[i] = ed[i] - st[i] + 1;
    }
    ```

Trong đó `st[i]` và `ed[i]` lần lượt là đầu và cuối của khối, còn `size[i]` là kích thước của khối.

<span id="lưu-và-sửa-thông-tin-trong-khối"></span>
## Lưu và sửa thông tin trong khối

<span id="ví-dụ-1-phép-thuật-của-giáo-chủ"></span>
### Ví dụ 1: [Phép thuật của giáo chủ](https://www.luogu.com.cn/problem/P2801)

Có hai loại thao tác:

1.  Cộng $z$ vào mỗi số trong đoạn $[x,y]$;
2.  Hỏi số lượng số lớn hơn hoặc bằng $z$ trong đoạn $[x,y]$.

Cần hỏi số lượng số trong một khối lớn hơn hoặc bằng một giá trị,
vì vậy dùng mảng `t` để lưu các phần tử trong khối sau khi sắp xếp;
`a` là mảng ban đầu, chưa sắp xếp.
Với cập nhật trên cả khối,
có thể dùng cách tương tự đánh dấu lười được lưu bền vững:
mảng `delta` ghi lại giá trị đang được cộng vào toàn bộ khối.
Gọi $q$ là tổng số thao tác truy vấn và cập nhật,
độ phức tạp thời gian là $O(q\sqrt{n}\log n)$.

Dùng mảng `delta` để ghi lại lượng cộng toàn khối của từng khối.

???+ note "Cài đặt"
    ```cpp
    void Sort(int k) {
      for (int i = st[k]; i <= ed[k]; i++) t[i] = a[i];
      sort(t + st[k], t + ed[k] + 1);
    }
    
    void Modify(int l, int r, int c) {
      int x = belong[l], y = belong[r];
      if (x == y)  // Nếu đoạn nằm trong cùng một khối thì sửa trực tiếp
      {
        for (int i = l; i <= r; i++) a[i] += c;
        Sort(x);
        return;
      }
      for (int i = l; i <= ed[x]; i++) a[i] += c;     // Sửa trực tiếp đoạn đầu
      for (int i = st[y]; i <= r; i++) a[i] += c;     // Sửa trực tiếp đoạn cuối
      for (int i = x + 1; i < y; i++) delta[i] += c;  // Gắn đánh dấu lười cho toàn bộ các khối ở giữa
      Sort(x);
      Sort(y);
    }
    
    int Answer(int l, int r, int c) {
      int ans = 0, x = belong[l], y = belong[r];
      if (x == y) {
        for (int i = l; i <= r; i++)
          if (a[i] + delta[x] >= c) ans++;
        return ans;
      }
      for (int i = l; i <= ed[x]; i++)
        if (a[i] + delta[x] >= c) ans++;
      for (int i = st[y]; i <= r; i++)
        if (a[i] + delta[y] >= c) ans++;
      for (int i = x + 1; i <= y - 1; i++)
        ans +=
            ed[i] - (lower_bound(t + st[i], t + ed[i] + 1, c - delta[i]) - t) + 1;
      // Dùng lower_bound để tìm vị trí số đầu tiên >= c trong từng khối nguyên ở giữa
      return ans;
    }
    ```

<span id="ví-dụ-2-ark-trong-đêm-lạnh"></span>
### Ví dụ 2: Ark trong đêm lạnh

Có hai loại thao tác:

1.  Gán mọi số trong đoạn $[x,y]$ thành $z$;
2.  Hỏi số lượng số nhỏ hơn hoặc bằng $z$ trong đoạn $[x,y]$.

Dùng mảng `delta` để ghi lại giá trị mà cả khối hiện đang được gán.
Khi khối chưa bị gán toàn bộ,
dùng một giá trị đặc biệt (chẳng hạn `0x3f3f3f3f3f3f3f3fll`) để biểu diễn.
Với các khối ở biên, trước khi truy vấn cần `pushdown`,
tức đẩy thông tin đang lưu trong khối xuống từng phần tử.
Sau khi gán, cần `sort` lại.
Các phần còn lại giống bài trước.

???+ note "Cài đặt"
    ```cpp
    void Sort(int k) {
      for (int i = st[k]; i <= ed[k]; i++) t[i] = a[i];
      sort(t + st[k], t + ed[k] + 1);
    }
    
    void PushDown(int x) {
      if (delta[x] != 0x3f3f3f3f3f3f3f3fll)  // Giá trị này đánh dấu khối chưa bị gán toàn bộ
        for (int i = st[x]; i <= ed[x]; i++) a[i] = t[i] = delta[x];
      delta[x] = 0x3f3f3f3f3f3f3f3fll;
    }
    
    void Modify(int l, int r, int c) {
      int x = belong[l], y = belong[r];
      PushDown(x);
      if (x == y) {
        for (int i = l; i <= r; i++) a[i] = c;
        Sort(x);
        return;
      }
      PushDown(y);
      for (int i = l; i <= ed[x]; i++) a[i] = c;
      for (int i = st[y]; i <= r; i++) a[i] = c;
      Sort(x);
      Sort(y);
      for (int i = x + 1; i < y; i++) delta[i] = c;
    }
    
    int Binary_Search(int l, int r, int c) {
      int ans = l - 1, mid;
      while (l <= r) {
        mid = (l + r) / 2;
        if (t[mid] <= c)
          ans = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      return ans;
    }
    
    int Answer(int l, int r, int c) {
      int ans = 0, x = belong[l], y = belong[r];
      PushDown(x);
      if (x == y) {
        for (int i = l; i <= r; i++)
          if (a[i] <= c) ans++;
        return ans;
      }
      PushDown(y);
      for (int i = l; i <= ed[x]; i++)
        if (a[i] <= c) ans++;
      for (int i = st[y]; i <= r; i++)
        if (a[i] <= c) ans++;
      for (int i = x + 1; i <= y - 1; i++) {
        if (0x3f3f3f3f3f3f3f3fll == delta[i])
          ans += Binary_Search(st[i], ed[i], c) - st[i] + 1;
        else if (delta[i] <= c)
          ans += size[i];
      }
      return ans;
    }
    ```

<span id="bài-tập"></span>
## Bài tập

1.  [Sửa một điểm, truy vấn đoạn](https://loj.ac/problem/130)
2.  [Sửa đoạn, truy vấn đoạn](https://loj.ac/problem/132)
3.  [Mẫu: Cây đoạn 2](https://www.luogu.com.cn/problem/P3373)
4.  [Ynoi2019 mô phỏng: Yuno loves sqrt technology III](https://www.luogu.com.cn/problem/P5048)
5.  [Violet: Bồ công anh](https://www.luogu.com.cn/problem/P4168)
6.  [Làm thơ](https://www.luogu.com.cn/problem/P4135)
