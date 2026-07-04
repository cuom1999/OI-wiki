<span id="&#x5B9A;&#x4E49;"></span>
## Định nghĩa

Tìm kiếm có ghi nhớ là một cách cài đặt tìm kiếm bằng việc ghi lại thông tin của các trạng thái đã duyệt, từ đó tránh duyệt lặp lại cùng một trạng thái.

Vì tìm kiếm có ghi nhớ bảo đảm mỗi trạng thái chỉ được truy cập một lần, nó cũng là một cách cài đặt quy hoạch động thường gặp.

<span id="&#x5F15;&#x5165;"></span>
## Dẫn nhập

???+ note "[\[NOIP2005\] Hái thuốc](https://www.luogu.com.cn/problem/P1048)"
    Trong hang có $M$ cây thuốc khác nhau. Hái mỗi cây cần một lượng thời gian $t_i$, và mỗi cây cũng có giá trị riêng $v_i$. Cho bạn một khoảng thời gian $T$; trong khoảng thời gian này, bạn có thể hái một số cây thuốc. Hãy làm cho tổng giá trị của các cây thuốc hái được là lớn nhất.
    
    $1 \leq T \leq 10^3$, $1 \leq t_i,v_i,M \leq 100$

<span id="&#x6734;&#x7D20;&#x7684;-dfs-&#x505A;&#x6CD5;"></span>
### Cách làm [DFS](../search/dfs.md) đơn giản

Rất dễ cài đặt một cách tìm kiếm đơn giản như sau: trong quá trình tìm kiếm, ghi lại ba tham số gồm đang chuẩn bị xét vật phẩm thứ mấy, thời gian còn lại là bao nhiêu và giá trị đã thu được là bao nhiêu; sau đó liệt kê xem vật phẩm hiện tại có được chọn hay không và chuyển tới trạng thái tương ứng.

???+ note "Cài đặt"
    === "C++"
        ```cpp
        int n, t;
        int tcost[103], mget[103];
        int ans = 0;
        
        void dfs(int pos, int tleft, int tans) {
          if (tleft < 0) return;
          if (pos == n + 1) {
            ans = max(ans, tans);
            return;
          }
          dfs(pos + 1, tleft, tans);
          dfs(pos + 1, tleft - tcost[pos], tans + mget[pos]);
        }
        
        int main() {
          cin >> t >> n;
          for (int i = 1; i <= n; i++) cin >> tcost[i] >> mget[i];
          dfs(1, t, 0);
          cout << ans << endl;
          return 0;
        }
        ```
    
    === "Python"
        ```python
        tcost = [0] * 103
        mget = [0] * 103
        ans = 0
        
        
        def dfs(pos, tleft, tans):
            global ans
            if tleft < 0:
                return
            if pos == n + 1:
                ans = max(ans, tans)
                return
            dfs(pos + 1, tleft, tans)
            dfs(pos + 1, tleft - tcost[pos], tans + mget[pos])
        
        
        t, n = map(lambda x: int(x), input().split())
        for i in range(1, n + 1):
            tcost[i], mget[i] = map(lambda x: int(x), input().split())
        dfs(1, t, 0)
        print(ans)
        ```

Độ phức tạp thời gian của cách làm này là cấp số mũ, nên không thể vượt qua bài này.

<span id="&#x4F18;&#x5316;"></span>
### Tối ưu

Vì sao cách làm trên có hiệu quả thấp? Vì cùng một trạng thái sẽ bị truy cập nhiều lần.

Nếu sau khi truy vấn xong một trạng thái, ta lưu thông tin của trạng thái đó lại, thì khi cần truy cập trạng thái này lần nữa có thể dùng trực tiếp kết quả đã tính trước đó, nhờ vậy tránh tính toán lặp. Điều này tận dụng đầy đủ đặc điểm nhiều bài toán quy hoạch động có rất nhiều bài toán con chồng lặp, thuộc tư tưởng "ghi nhớ" dùng bộ nhớ đổi lấy thời gian.

Cụ thể với bài này, trên cơ sở DFS đơn giản, ta thêm một mảng `mem` để ghi lại giá trị trả về của từng `dfs(pos,tleft)`. Ban đầu đặt mọi giá trị trong `mem` bằng `-1` (biểu thị chưa từng được giải). Mỗi khi cần truy cập một trạng thái, nếu giá trị của trạng thái tương ứng trong `mem` là `-1` thì đệ quy truy cập trạng thái đó. Ngược lại, ta dùng trực tiếp giá trị đã lưu trong `mem`.

Thông qua cách xử lý này, ta bảo đảm mỗi trạng thái chỉ bị truy cập một lần, vì vậy độ phức tạp thời gian của thuật toán là $O(TM)$.

???+ note "Cài đặt"
    === "C++"
        ```cpp
        int n, t;
        int tcost[103], mget[103];
        int mem[103][1003];
        
        int dfs(int pos, int tleft) {
          if (mem[pos][tleft] != -1)
            return mem[pos][tleft];  // Trang thai da truy cap, tra ve gia tri da ghi lai
          if (pos == n + 1) return mem[pos][tleft] = 0;
          int dfs1, dfs2 = -INF;
          dfs1 = dfs(pos + 1, tleft);
          if (tleft >= tcost[pos])
            dfs2 = dfs(pos + 1, tleft - tcost[pos]) + mget[pos];  // Chuyen trang thai
          return mem[pos][tleft] = max(dfs1, dfs2);  // Luu gia tri cua trang thai hien tai
        }
        
        int main() {
          memset(mem, -1, sizeof(mem));
          cin >> t >> n;
          for (int i = 1; i <= n; i++) cin >> tcost[i] >> mget[i];
          cout << dfs(1, t) << endl;
          return 0;
        }
        ```
    
    === "Python"
        ```python
        tcost = [0] * 103
        mget = [0] * 103
        mem = [[-1 for i in range(1003)] for j in range(103)]
        
        
        def dfs(pos, tleft):
            if mem[pos][tleft] != -1:
                return mem[pos][tleft]
            if pos == n + 1:
                mem[pos][tleft] = 0
                return mem[pos][tleft]
            dfs1 = dfs2 = -INF
            dfs1 = dfs(pos + 1, tleft)
            if tleft >= tcost[pos]:
                dfs2 = dfs(pos + 1, tleft - tcost[pos]) + mget[pos]
            mem[pos][tleft] = max(dfs1, dfs2)
            return mem[pos][tleft]
        
        
        t, n = map(lambda x: int(x), input().split())
        for i in range(1, n + 1):
            tcost[i], mget[i] = map(lambda x: int(x), input().split())
        print(dfs(1, t))
        ```

<span id="&#x4E0E;&#x9012;&#x63A8;&#x7684;&#x8054;&#x7CFB;&#x4E0E;&#x533A;&#x522B;"></span>
## Liên hệ và khác biệt với cài đặt lặp

Khi giải các bài toán quy hoạch động, mã của tìm kiếm có ghi nhớ và cài đặt lặp thường rất giống nhau về hình thức. Điều này là do chúng dùng cùng một cách biểu diễn trạng thái và các chuyển trạng thái tương tự nhau. Cũng vì vậy, nói chung độ phức tạp thời gian của hai cách cài đặt là như nhau.

Dưới đây là mã cài đặt bằng vòng lặp (để tiện so sánh, không thêm tối ưu mảng cuộn). Qua đối chiếu có thể thấy hai cách cài đặt giống nhau về hình thức.

```cpp
int n, t, w[105], v[105], f[105][1005];

int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= t; j++) {
      f[i][j] = f[i - 1][j];
      if (j >= w[i])
        f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);  // Phuong trinh chuyen trang thai
    }
  cout << f[n][t];
  return 0;
}
```

Khi giải các bài toán quy hoạch động, cả tìm kiếm có ghi nhớ lẫn cài đặt lặp đều bảo đảm cùng một trạng thái nhiều nhất chỉ được giải một lần. Tuy nhiên, cách chúng đạt được điều này hơi khác nhau: cài đặt lặp tránh truy cập lặp bằng cách đặt ra thứ tự truy cập rõ ràng; tìm kiếm có ghi nhớ tuy không quy định rõ thứ tự truy cập, nhưng cũng đạt được mục đích tương tự bằng cách đánh dấu các trạng thái đã truy cập.

So với cài đặt lặp, tìm kiếm có ghi nhớ đôi khi dễ cài đặt hơn vì không cần quy định rõ thứ tự truy cập, đồng thời xử lý biên khá thuận tiện; đây là một ưu điểm lớn của tìm kiếm có ghi nhớ. Nhưng mặt khác, tìm kiếm có ghi nhớ khó dùng các tối ưu như mảng cuộn, và do có đệ quy nên hiệu suất chạy sẽ thấp hơn cài đặt lặp. Vì vậy nên chọn cách cài đặt phù hợp hơn tùy theo bài toán.

<span id="&#x5982;&#x4F55;&#x5199;&#x8BB0;&#x5FC6;&#x5316;&#x641C;&#x7D22;"></span>
## Cách viết tìm kiếm có ghi nhớ

<span id="&#x65B9;&#x6CD5;&#x4E00;"></span>
### Cách 1

1.  Viết trạng thái DP và phương trình của bài này ra
2.  Dựa vào chúng để viết hàm dfs
3.  Thêm mảng ghi nhớ

Ví dụ:

$dp_{i} = \max\{dp_{j}+1\}\quad (1 \leq j < i \land a_{j}<a_{i})$ (dãy con tăng dài nhất)

Chuyển thành

=== "C++"
    ```cpp
    int dfs(int i) {
      if (mem[i] != -1) return mem[i];
      int ret = 1;
      for (int j = 1; j < i; j++)
        if (a[j] < a[i]) ret = max(ret, dfs(j) + 1);
      return mem[i] = ret;
    }
    
    int main() {
      memset(mem, -1, sizeof(mem));
      // Bo qua phan doc du lieu
      int ret = 0;
      for (int j = 1; j <= n; j++) {
        ret = max(ret, dfs(j));
      }
      cout << ret << endl;
    }
    ```

=== "Python"
    ```python
    def dfs(i):
        if mem[i] != -1:
            return mem[i]
        ret = 1
        for j in range(1, i):
            if a[j] < a[i]:
                ret = max(ret, dfs(j) + 1)
        mem[i] = ret
        return mem[i]
    ```

<span id="&#x65B9;&#x6CD5;&#x4E8C;"></span>
### Cách 2

1.  Viết chương trình tìm kiếm vét cạn cho bài này (tốt nhất là [dfs](../search/dfs.md))
2.  Sửa dfs này thành dfs "không cần biến bên ngoài"
3.  Thêm mảng ghi nhớ

Ví dụ: ví dụ "Hái thuốc" trong bài viết này
