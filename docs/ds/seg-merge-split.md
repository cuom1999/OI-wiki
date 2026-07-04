author: ChungZH, billchenchina, Chrogeek, Early0v0, ethan-enhe, HeRaNO, hsfzLZH1, iamtwz, Ir1d, konnyakuxzy, luoguojie, Marcythm, orzAtalod, StudyingFather, wy-luke, Xeonacid, CCXXXI, chenryang, chenzheAya, CJSoft, cjsoft, countercurrent-time, DawnMagnet, Enter-tainer, GavinZhengOI, Haohu Shen, Henry-ZHR, hjsjhn, hly1204, jaxvanyang, Jebearssica, kenlig, ksyx, megakite, Menci, moon-dim, NachtgeistW, onelittlechildawa, ouuan, shadowice1984, shawlleyw, shuzhouliu, SukkaW, Tiphereth-A, x2e6, Ycrpro, yifan0305, zeningc

Hợp nhất và tách cây phân đoạn là những kỹ thuật thường dùng với cây phân đoạn, phổ biến trong các bài toán dùng cây phân đoạn theo giá trị để duy trì đa tập.

Chẳng hạn, nếu trên một số đỉnh của cây có một vài thao tác, ta cần truyền thông tin từ các đỉnh con lên đỉnh cha theo hướng từ dưới lên, và thông tin tại từng đỉnh lại thuận tiện để duy trì bằng cây phân đoạn, thì có thể dùng kỹ thuật hợp nhất cây phân đoạn để khống chế độ phức tạp tổng thể.

## Hợp nhất cây phân đoạn

### Quy trình

Đúng như tên gọi, hợp nhất cây phân đoạn là xây dựng một cây phân đoạn mới, trong đó mỗi nút là kết quả sau khi hợp nhất hai nút tương ứng của hai cây phân đoạn ban đầu. Kỹ thuật này thường được dùng để duy trì thông tin trên cây hoặc trên đồ thị.

Hiển nhiên, ta không thể thật sự xây đầy đủ một cây phân đoạn mới mỗi lần hợp nhất, vì vậy cần dùng cây phân đoạn mở nút động đã trình bày ở phần trước.

Về bản chất, quy trình hợp nhất cây phân đoạn khá trực tiếp:

Giả sử hai cây phân đoạn là A và B, ta bắt đầu hợp nhất đệ quy từ nút số 1.

Khi đệ quy đến một nút, nếu nút tương ứng trên cây A hoặc cây B rỗng, ta trả về trực tiếp nút tương ứng trên cây còn lại. Bước này tận dụng đặc tính của cây phân đoạn mở nút động.

Nếu đệ quy đến nút lá, ta hợp nhất hai nút tương ứng của hai cây.

Cuối cùng, cập nhật nút hiện tại dựa trên các nút con rồi trả về.

???+ note "Độ phức tạp của hợp nhất cây phân đoạn"
    Hiển nhiên, với hai cây phân đoạn đầy đủ, độ phức tạp của một thao tác hợp nhất là $O(n)$. Tuy nhiên, trong thực tế ta thường dùng cây phân đoạn theo giá trị, và tổng số nút của tất cả các cây phân đoạn cần hợp nhất thường không chênh lệch nhiều so với quy mô $n$. Ngoài ra, khi hợp nhất, thông thường ta không hợp nhất lặp lại cùng một cây phân đoạn, nên tổng số nút tăng thêm cuối cùng xấp xỉ cấp $n\log n$. Do đó, độ phức tạp tổng để hợp nhất tất cả các cây phân đoạn là cấp $O(n\log n)$. Dĩ nhiên, trong một số trường hợp, heap hợp nhất được có thể là lựa chọn tốt hơn.

### Cài đặt

```cpp
int merge(int a, int b, int l, int r) {
  if (!a) return b;
  if (!b) return a;
  if (l == r) {
    // làm gì đó...
    return a;
  }
  int mid = (l + r) >> 1;
  tr[a].l = merge(tr[a].l, tr[b].l, l, mid);
  tr[a].r = merge(tr[a].r, tr[b].r, mid + 1, r);
  pushup(a);
  return a;
}
```

### Bài mẫu

???+ note "[Luogu P4556 \[Vani có hẹn\] Cái đuôi ngày mưa/[Mẫu] Hợp nhất cây phân đoạn](https://www.luogu.com.cn/problem/P4556)"
    ??? note "Ý tưởng giải"
        Đây là bài mẫu về hợp nhất cây phân đoạn. Dùng hiệu sai phân để chuyển các phép sửa trên cây thành sửa điểm đơn, sau đó DFS từ dưới lên, hợp nhất các cây phân đoạn và thống kê đáp án là được.

    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/ds/code/seg/seg_6.cpp"
        ```

## Tách cây phân đoạn

### Quy trình

Về bản chất, tách cây phân đoạn là quá trình ngược lại của hợp nhất cây phân đoạn. Tách cây phân đoạn chỉ áp dụng cho dãy có thứ tự; với dãy không có thứ tự thì thao tác này không có ý nghĩa. Kỹ thuật này thường dùng trên cây phân đoạn theo giá trị mở nút động.

Lưu ý rằng khi cả tách và hợp nhất cùng tồn tại, ta phải thu hồi nút trong lúc hợp nhất, để tránh khả năng một nút bị chiếm dụng lặp lại khi tách.

Để tách đoạn $[l,r]$ từ một cây phân đoạn có miền $[1,N]$ và xây một cây mới:

Bắt đầu tách đệ quy từ nút số 1. Khi nút không tồn tại, hoặc đoạn $[s,t]$ mà nút đại diện không giao với $[l,r]$, ta quay lui trực tiếp.

Khi $[s,t]$ giao với $[l,r]$, cần mở một nút mới.

Khi $[s,t]$ được chứa trong $[l,r]$, cần nối trực tiếp nút hiện tại vào cây mới và cắt cạnh cũ.

???+ note "Độ phức tạp của tách cây phân đoạn"
    Có thể thấy số cạnh bị cắt nhiều nhất chỉ là $\log n$, nên độ phức tạp thời gian của mỗi lần tách cuối cùng là $O(\log n)$, tương đương độ phức tạp của truy vấn đoạn.

### Cài đặt

```cpp
void split(int &p, int &q, int s, int t, int l, int r) {
  if (t < l || r < s) return;
  if (!p) return;
  if (l <= s && t <= r) {
    q = p;
    p = 0;
    return;
  }
  if (!q) q = New();
  int m = s + t >> 1;
  if (l <= m) split(ls[p], ls[q], s, m, l, r);
  if (m < r) split(rs[p], rs[q], m + 1, t, l, r);
  push_up(p);
  push_up(q);
}
```

### Bài mẫu

???+ note "[P5494 [Mẫu] Tách cây phân đoạn](https://www.luogu.com.cn/problem/P5494)"
    ??? note "Ý tưởng giải"
        Đây là bài mẫu về tách cây phân đoạn: tách đoạn $[x,y]$ ra.

        -   Hợp nhất cây $t$ vào cây $p$: chỉ cần hợp nhất một lần.

        -   Chèn $x$ phần tử $q$ vào cây $p$: sửa điểm đơn.

        -   Truy vấn số lượng phần tử trong $[x,y]$: lấy tổng trên đoạn.

        -   Truy vấn phần tử nhỏ thứ $k$.

    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/ds/code/seg/seg_7.cpp"
        ```

## Bài tập

-   [Luogu P4556 \[Vani có hẹn\] Cái đuôi ngày mưa/[Mẫu] Hợp nhất cây phân đoạn](https://www.luogu.com.cn/problem/P4556)
-   [Luogu P5494 [Mẫu] Tách cây phân đoạn](https://www.luogu.com.cn/problem/P5494)
-   [Luogu P1600 Ngày nào cũng thích chạy](https://www.luogu.com.cn/problem/P1600)
-   [Luogu P4577 \[FJOI2018\] Bài toán tập đoàn lãnh đạo](https://www.luogu.com.cn/problem/P4577)
-   [Luogu P2824 \[HEOI2016/TJOI2016\] Sắp xếp](https://www.luogu.com.cn/problem/P2824)
