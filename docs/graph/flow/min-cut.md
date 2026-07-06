## Khái niệm

### Lát cắt

Với một đồ thị luồng mạng $G=(V,E)$, một lát cắt được định nghĩa là một **cách phân hoạch các đỉnh**: chia toàn bộ các đỉnh thành hai tập $S$ và $T=V-S$, trong đó đỉnh nguồn $s\in S$ và đỉnh đích $t\in T$.

### Dung lượng của lát cắt

Dung lượng $c(S,T)$ của lát cắt $(S,T)$ được định nghĩa là tổng dung lượng của tất cả các cạnh đi từ $S$ sang $T$, tức $c(S,T)=\sum_{u\in S,v\in T}c(u,v)$. Cũng có thể dùng $c(s,t)$ để biểu diễn $c(S,T)$.

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

### Phương án

Có thể bắt đầu DFS từ đỉnh nguồn $s$, mỗi lần chỉ đi qua các cạnh có dung lượng dư lớn hơn $0$, để tìm tất cả các đỉnh thuộc tập $S$.

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

Nếu cần tối thiểu hóa số cạnh bị cắt với điều kiện vẫn là một lát cắt nhỏ nhất, trước hết tìm lát cắt nhỏ nhất, đổi dung lượng của các cạnh chưa bão hòa thành $\infty$, đổi dung lượng của các cạnh đã bão hòa thành $1$, rồi chạy lại bài toán lát cắt nhỏ nhất để thu được số cạnh bị cắt nhỏ nhất. Nếu không có điều kiện phải là lát cắt nhỏ nhất, chỉ cần đặt dung lượng của mọi cạnh bằng $1$ rồi tìm lát cắt nhỏ nhất một lần.

## Mô hình bài toán 1

Có $n$ vật phẩm và hai tập $A,B$. Nếu vật phẩm thứ $i$ không được đưa vào tập $A$ thì tốn chi phí $a_i$, nếu không được đưa vào tập $B$ thì tốn chi phí $b_i$. Ngoài ra còn có một số ràng buộc dạng $u_i,v_i,w_i$, nghĩa là nếu $u_i$ và $v_i$ không cùng nằm trong một tập thì tốn chi phí $w_i$. Mỗi vật phẩm bắt buộc thuộc đúng một tập. Cần tìm chi phí nhỏ nhất.

Đây là một bài toán lát cắt nhỏ nhất kinh điển thuộc dạng **chọn một trong hai**. Đặt đỉnh nguồn $s$ và đỉnh đích $t$ tương ứng với hai tập; với đỉnh thứ $i$, nối một cạnh từ $s$ đến nó có dung lượng $a_i$, và một cạnh từ nó đến $t$ có dung lượng $b_i$. Với mỗi ràng buộc $u,v,w$, nối cạnh hai chiều có dung lượng $w$ giữa $u$ và $v$.

Khi đỉnh nguồn và đỉnh đích không còn liên thông, các đỉnh ở mỗi phía đại diện cho việc chọn một trong hai tập. Nếu cắt cạnh nối với $s$ hoặc $t$, điều đó biểu thị vật phẩm không được đặt vào tập $A$ hoặc $B$; nếu cắt cạnh giữa hai vật phẩm, điều đó biểu thị hai vật phẩm này không được đặt trong cùng một tập.

Lát cắt nhỏ nhất chính là chi phí nhỏ nhất.

## Mô hình bài toán 2

Đồ thị đóng có tổng trọng số lớn nhất: cho một đồ thị có hướng, mỗi đỉnh có một trọng số (có thể dương, âm hoặc bằng $0$). Cần chọn một đồ thị con có tổng trọng số lớn nhất sao cho với mọi đỉnh trong đồ thị con, tất cả các đỉnh kề đi ra từ nó cũng nằm trong đồ thị con.

Cách làm: tạo siêu nguồn $s$ và siêu đích $t$. Nếu đỉnh $u$ có trọng số dương, nối một cạnh có hướng từ $s$ đến $u$ với dung lượng bằng trọng số của đỉnh đó. Nếu đỉnh $u$ có trọng số âm, nối một cạnh có hướng từ $u$ đến $t$ với dung lượng bằng số đối của trọng số đỉnh đó. Đổi dung lượng của tất cả các cạnh trong đồ thị ban đầu thành $\infty$. Chạy luồng cực đại trên mạng; lấy tổng mọi trọng số dương trừ đi giá trị luồng cực đại để thu được đáp án.

Một vài nhận xét để chứng minh:

1.  Mỗi đồ thị con thỏa mãn điều kiện đều tương ứng với một lát cắt trong mạng luồng. Vì mỗi lát cắt chia mạng thành hai phần, phần liên thông với $s$ không có cạnh nào đi sang phần còn lại, nên thỏa mãn điều kiện trên. Mệnh đề này là điều kiện cần và đủ.
2.  Các cạnh bị loại bỏ bởi lát cắt nhỏ nhất bắt buộc phải nối với một trong hai đỉnh $s$ hoặc $t$. Nếu không, dung lượng cạnh là $\infty$ nên cạnh đó không thể thuộc lát cắt nhỏ nhất.
3.  Với phần đồ thị con được chọn, tổng trọng số $=$ tổng mọi trọng số dương $-$ tổng trọng số của các đỉnh dương không được chọn $+$ tổng trọng số của các đỉnh âm được chọn. Khi không chọn một đỉnh có trọng số dương, cạnh nối nó với $s$ bị cắt; khi chọn một đỉnh có trọng số âm, cạnh nối nó với $t$ bị cắt. Tổng dung lượng của các cạnh bị cắt chính là dung lượng của lát cắt. Do đó công thức trên trở thành: tổng trọng số $=$ tổng mọi trọng số dương $-$ dung lượng lát cắt.
4.  Suy ra kết luận: tổng trọng số lớn nhất $=$ tổng mọi trọng số dương $-$ lát cắt nhỏ nhất $=$ tổng mọi trọng số dương $-$ luồng cực đại.

## Bài tập

-   [USACO 4.4 - Pollutant Control](https://www.luogu.com.cn/problem/P1344)
-   [USACO 5.4 - Telecowmunication](https://www.luogu.com.cn/problem/P1345)
-   [Luogu 1361 - Crops of Little M](https://www.luogu.com.cn/problem/P1361)
-   [SHOI 2007 - Goodwill Voting](https://www.luogu.com.cn/problem/P2057)
-   [Space Flight Plan](https://www.luogu.com.cn/problem/P2762)
