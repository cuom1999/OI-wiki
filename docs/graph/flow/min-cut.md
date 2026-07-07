## Khái niệm

### Lát cắt

Với một mạng luồng $G=(V,E)$, một lát cắt được định nghĩa là một **cách phân hoạch các đỉnh**:
chia toàn bộ các đỉnh thành hai tập $S$ và $T=V-S$, trong đó đỉnh nguồn $s\in S$ và đỉnh đích $t\in T$.

### Dung lượng của lát cắt

Dung lượng $c(S,T)$ của lát cắt $(S,T)$ là tổng dung lượng của tất cả các cạnh đi từ $S$ sang $T$,
tức $c(S,T)=\sum_{u\in S,v\in T}c(u,v)$.
Đôi khi ký hiệu $c(s,t)$ cũng được dùng để chỉ dung lượng của lát cắt đang xét.

### Lát cắt nhỏ nhất

Lát cắt nhỏ nhất là lát cắt $(S,T)$ có dung lượng $c(S,T)$ nhỏ nhất.

## Chứng minh

### Định lý luồng cực đại - lát cắt nhỏ nhất

Xem phần định lý luồng cực đại - lát cắt nhỏ nhất trong trang [luồng cực đại](max-flow.md).

## Mã nguồn

### Lát cắt nhỏ nhất

Từ **định lý luồng cực đại - lát cắt nhỏ nhất**, có thể trực tiếp thu được đoạn mã sau:

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <queue>
    
    constexpr int N = 1e4 + 5, M = 2e5 + 5;
    int n, m, s, t, tot = 1, lnk[N], ter[M], nxt[M], val[M], dep[N], cur[N];
    
    void add(int u, int v, int w) {
      ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, val[tot] = w;
    }
    
    void addedge(int u, int v, int w) { add(u, v, w), add(v, u, 0); }
    
    int bfs(int s, int t) {
      memset(dep, 0, sizeof(dep));
      memcpy(cur, lnk, sizeof(lnk));
      std::queue<int> q;
      q.push(s), dep[s] = 1;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = lnk[u]; i; i = nxt[i]) {
          int v = ter[i];
          if (val[i] && !dep[v]) q.push(v), dep[v] = dep[u] + 1;
        }
      }
      return dep[t];
    }
    
    int dfs(int u, int t, int flow) {
      if (u == t) return flow;
      int ans = 0;
      for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
        int v = ter[i];
        if (val[i] && dep[v] == dep[u] + 1) {
          int x = dfs(v, t, std::min(val[i], flow - ans));
          if (x) val[i] -= x, val[i ^ 1] += x, ans += x;
        }
      }
      if (ans < flow) dep[u] = -1;
      return ans;
    }
    
    int dinic(int s, int t) {
      int ans = 0;
      while (bfs(s, t)) {
        int x;
        while ((x = dfs(s, t, 1 << 30))) ans += x;
      }
      return ans;
    }
    
    int main() {
      scanf("%d%d%d%d", &n, &m, &s, &t);
      while (m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
      }
      printf("%d\n", dinic(s, t));
      return 0;
    }
    ```

### Truy xuất phương án

Sau khi tìm xong luồng cực đại, có thể bắt đầu DFS từ đỉnh nguồn $s$ trên đồ thị dư.
Mỗi bước chỉ đi qua các cạnh còn dung lượng dư lớn hơn $0$.
Tập các đỉnh thăm được chính là phía $S$ của một lát cắt nhỏ nhất.

```cpp
void dfs(int u) {
  vis[u] = 1;
  for (int i = lnk[u]; i; i = nxt[i]) {
    int v = ter[i];
    if (!vis[v] && val[i]) dfs(v);
  }
}
```

### Số cạnh bị cắt

Nếu cần tối thiểu hóa số cạnh bị cắt với điều kiện kết quả vẫn là một lát cắt nhỏ nhất,
trước hết hãy tìm một lát cắt nhỏ nhất.
Sau đó đổi dung lượng của các cạnh chưa bão hòa thành $\infty$, đổi dung lượng của các cạnh đã bão hòa thành $1$,
rồi chạy lại bài toán lát cắt nhỏ nhất để thu được số cạnh bị cắt nhỏ nhất.

Nếu không yêu cầu lát cắt thu được phải là lát cắt nhỏ nhất theo dung lượng ban đầu,
chỉ cần đặt dung lượng của mọi cạnh bằng $1$ rồi tìm lát cắt nhỏ nhất một lần.

## Mô hình bài toán 1

Có $n$ vật phẩm và hai tập $A,B$.
Nếu vật phẩm thứ $i$ không được đưa vào tập $A$ thì tốn chi phí $a_i$;
nếu không được đưa vào tập $B$ thì tốn chi phí $b_i$.
Ngoài ra còn có một số ràng buộc dạng $u_i,v_i,w_i$:
nếu $u_i$ và $v_i$ không cùng nằm trong một tập thì tốn chi phí $w_i$.
Mỗi vật phẩm bắt buộc thuộc đúng một tập.
Cần tìm chi phí nhỏ nhất.

Đây là một bài toán lát cắt nhỏ nhất kinh điển thuộc dạng **chọn một trong hai**.
Đặt đỉnh nguồn $s$ và đỉnh đích $t$ lần lượt tương ứng với hai tập $A$ và $B$.
Với vật phẩm thứ $i$, nối một cạnh từ $s$ đến đỉnh của nó có dung lượng $a_i$,
và một cạnh từ đỉnh đó đến $t$ có dung lượng $b_i$.
Với mỗi ràng buộc $u,v,w$, nối cạnh hai chiều có dung lượng $w$ giữa $u$ và $v$.

Khi đỉnh nguồn và đỉnh đích không còn liên thông, phía của $s$ biểu thị các vật phẩm được chọn vào $A$,
còn phía của $t$ biểu thị các vật phẩm được chọn vào $B$.
Nếu cạnh $s\to i$ bị cắt, vật phẩm $i$ không được đặt vào $A$ và phát sinh chi phí $a_i$.
Nếu cạnh $i\to t$ bị cắt, vật phẩm $i$ không được đặt vào $B$ và phát sinh chi phí $b_i$.
Nếu cạnh giữa hai vật phẩm bị cắt, hai vật phẩm đó không nằm trong cùng một tập và phát sinh chi phí ràng buộc.

Lát cắt nhỏ nhất chính là chi phí nhỏ nhất.

## Mô hình bài toán 2

Bài toán đồ thị đóng có tổng trọng số lớn nhất được phát biểu như sau:
cho một đồ thị có hướng, mỗi đỉnh có một trọng số, có thể dương, âm hoặc bằng $0$.
Cần chọn một tập đỉnh có tổng trọng số lớn nhất sao cho với mọi đỉnh đã chọn,
tất cả các đỉnh kề theo cạnh đi ra từ nó cũng được chọn.

Cách làm: tạo siêu nguồn $s$ và siêu đích $t$.
Nếu đỉnh $u$ có trọng số dương, nối cạnh $s\to u$ với dung lượng bằng trọng số của $u$.
Nếu đỉnh $u$ có trọng số âm, nối cạnh $u\to t$ với dung lượng bằng số đối của trọng số đó.
Đổi dung lượng của tất cả các cạnh trong đồ thị ban đầu thành $\infty$.
Chạy luồng cực đại trên mạng mới; lấy tổng mọi trọng số dương trừ đi giá trị luồng cực đại để thu được đáp án.

Một vài nhận xét để chứng minh:

1.  Mỗi tập đỉnh thỏa mãn tính đóng tương ứng với một lát cắt hữu hạn trong mạng luồng:
    đặt các đỉnh được chọn ở phía $s$, các đỉnh còn lại ở phía $t$.
    Ngược lại, với một lát cắt hữu hạn, phía $s$ không thể có cạnh gốc nào đi sang phía $t$,
    vì các cạnh gốc đều có dung lượng $\infty$.
2.  Vì vậy, các cạnh bị cắt bởi lát cắt nhỏ nhất hữu hạn chỉ có thể là cạnh nối với $s$ hoặc $t$.
3.  Với tập đỉnh được chọn, tổng trọng số bằng:
    tổng mọi trọng số dương $-$ tổng trọng số của các đỉnh dương không được chọn
    $+$ tổng trọng số của các đỉnh âm được chọn.
    Khi không chọn một đỉnh có trọng số dương, cạnh từ $s$ đến nó bị cắt.
    Khi chọn một đỉnh có trọng số âm, cạnh từ nó đến $t$ bị cắt.
    Do đó dung lượng lát cắt đúng bằng phần bị trừ khỏi tổng mọi trọng số dương.
4.  Suy ra kết luận:
    tổng trọng số lớn nhất $=$ tổng mọi trọng số dương $-$ lát cắt nhỏ nhất
    $=$ tổng mọi trọng số dương $-$ luồng cực đại.

## Bài tập

-   [USACO 4.4 - Pollutant Control](https://www.luogu.com.cn/problem/P1344)
-   [USACO 5.4 - Telecowmunication](https://www.luogu.com.cn/problem/P1345)
-   [Luogu 1361 - Crops of Little M](https://www.luogu.com.cn/problem/P1361)
-   [SHOI 2007 - Goodwill Voting](https://www.luogu.com.cn/problem/P2057)
-   [Space Flight Plan](https://www.luogu.com.cn/problem/P2762)
