Trước khi đọc bài này, nên xem phần định nghĩa trong bài [Giới thiệu về luồng mạng](../flow.md).

## Luồng chi phí

Cho một mạng $G=(V,E)$.
Ngoài giới hạn dung lượng $c(u,v)$, mỗi cạnh còn có chi phí trên một đơn vị luồng $w(u,v)$.

Khi luồng trên $(u,v)$ là $f(u,v)$, chi phí cần trả là $f(u,v)\times w(u,v)$.

$w$ cũng thỏa mãn tính phản đối xứng, tức là $w(u,v)=-w(v,u)$.

Khi đó, luồng cực đại có tổng chi phí nhỏ nhất trong mạng được gọi là **luồng cực đại chi phí nhỏ nhất**.
Nói cách khác, ta cần tối thiểu hóa $\sum_{(u,v)\in E}f(u,v)\times w(u,v)$
với điều kiện giá trị $\sum_{(s,v)\in E}f(s,v)$ đã được tối đa hóa.

## Thuật toán SSP

Thuật toán SSP (Successive Shortest Path) là một thuật toán tham lam.
Ở mỗi bước, thuật toán tìm một đường tăng luồng có chi phí đơn vị nhỏ nhất rồi tăng luồng theo đường đó,
cho đến khi trên đồ thị không còn đường tăng luồng nào.

Nếu trong đồ thị có chu trình với tổng chi phí âm, thuật toán SSP có thể không tìm đúng luồng cực đại chi phí nhỏ nhất.
Khi đó cần dùng thuật toán khử chu trình để loại bỏ các chu trình âm trước.

### Chứng minh

Dùng quy nạp toán học và phản chứng để chứng minh tính đúng đắn của thuật toán SSP.

Gọi chi phí nhỏ nhất khi lượng luồng bằng $i$ là $f_i$.
Giả sử mạng ban đầu **không có chu trình âm**, khi đó $f_0=0$.

Giả sử $f_i$ do thuật toán SSP tìm được là chi phí nhỏ nhất.
Từ trạng thái ứng với $f_i$, thuật toán tìm một đường tăng luồng ngắn nhất để suy ra $f_{i+1}$.
Khi đó $f_{i+1}-f_i$ chính là độ dài của đường tăng luồng ngắn nhất này.

Giả sử tồn tại một giá trị nhỏ hơn, ký hiệu là $f'_{i+1}$.
Vì $f_{i+1}-f_i$ đã là đường tăng luồng ngắn nhất,
nên phần chênh lệch $f'_{i+1}-f_i$ chỉ có thể đạt được bằng một đường tăng luồng đi qua **ít nhất một chu trình âm**.

Điều này mâu thuẫn với giả thiết $f_i$ là chi phí nhỏ nhất.
Thật vậy, nếu tồn tại một chu trình âm như vậy, chỉ cần đẩy thêm luồng trên chu trình đó
là có thể giảm chi phí ứng với cùng lượng luồng $i$ mà không làm tăng lượng luồng đi ra từ $s$.

Do đó, thuật toán SSP có thể tìm đúng luồng cực đại chi phí nhỏ nhất của một mạng không có chu trình âm.

### Độ phức tạp thời gian

Nếu dùng [thuật toán Bellman–Ford](../shortest-path.md#thuật-toán-bellman-ford) để tìm đường đi ngắn nhất,
độ phức tạp cho mỗi lần tìm đường tăng luồng là $O(nm)$.
Gọi giá trị luồng cực đại của mạng là $f$, độ phức tạp xấu nhất là $O(nmf)$.
Nói cách khác, thuật toán SSP có [thời gian giả đa thức](../../misc/cc-basic.md#pseudo-polynomial-time).

???+ note "Vì sao thuật toán SSP có thời gian giả đa thức?"
    Độ phức tạp thời gian của thuật toán SSP có cận trên $O(nmf)$.
    Đây là một đa thức theo miền giá trị, nên là thời gian giả đa thức.
    
    Có thể xây dựng một mạng[^note1] với $m=n^2,f=2^{n/2}$,
    làm cho độ phức tạp thời gian của thuật toán SSP đạt $O(n^3 2^{n/2})$.
    Vì vậy thuật toán SSP không phải là thuật toán thời gian đa thức.

### Cài đặt

Chỉ cần thay quá trình tìm đường tăng luồng trong thuật toán EK hoặc thuật toán Dinic
bằng việc dùng thuật toán đường đi ngắn nhất để tìm đường tăng luồng có chi phí đơn vị nhỏ nhất.

??? note "Cài đặt dựa trên thuật toán EK"
    ```cpp
    struct qxx {
      int nex, t, v, c;
    };
    
    qxx e[M];
    int h[N], cnt = 1;
    
    void add_path(int f, int t, int v, int c) {
      e[++cnt] = qxx{h[f], t, v, c}, h[f] = cnt;
    }
    
    void add_flow(int f, int t, int v, int c) {
      add_path(f, t, v, c);
      add_path(t, f, 0, -c);
    }
    
    int dis[N], pre[N], incf[N];
    bool vis[N];
    
    bool spfa() {
      memset(dis, 0x3f, sizeof(dis));
      queue<int> q;
      q.push(s), dis[s] = 0, incf[s] = INF, incf[t] = 0;
      while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = h[u]; i; i = e[i].nex) {
          const int &v = e[i].t, &w = e[i].v, &c = e[i].c;
          if (!w || dis[v] <= dis[u] + c) continue;
          dis[v] = dis[u] + c, incf[v] = min(w, incf[u]), pre[v] = i;
          if (!vis[v]) q.push(v), vis[v] = true;
        }
      }
      return incf[t];
    }
    
    int maxflow, mincost;
    
    void update() {
      maxflow += incf[t];
      for (int u = t; u != s; u = e[pre[u] ^ 1].t) {
        e[pre[u]].v -= incf[t], e[pre[u] ^ 1].v += incf[t];
        mincost += incf[t] * e[pre[u]].c;
      }
    }
    
    // Gọi: while(spfa())update();
    ```

??? note "Cài đặt dựa trên thuật toán Dinic"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <queue>
    
    constexpr int N = 5e3 + 5, M = 1e5 + 5;
    constexpr int INF = 0x3f3f3f3f;
    int n, m, tot = 1, lnk[N], cur[N], ter[M], nxt[M], cap[M], cost[M], dis[N], ret;
    bool vis[N];
    
    void add(int u, int v, int w, int c) {
      ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, cap[tot] = w, cost[tot] = c;
    }
    
    void addedge(int u, int v, int w, int c) { add(u, v, w, c), add(v, u, 0, -c); }
    
    bool spfa(int s, int t) {
      memset(dis, 0x3f, sizeof(dis));
      memcpy(cur, lnk, sizeof(lnk));
      std::queue<int> q;
      q.push(s), dis[s] = 0, vis[s] = true;
      while (!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = false;
        for (int i = lnk[u]; i; i = nxt[i]) {
          int v = ter[i];
          if (cap[i] && dis[v] > dis[u] + cost[i]) {
            dis[v] = dis[u] + cost[i];
            if (!vis[v]) q.push(v), vis[v] = true;
          }
        }
      }
      return dis[t] != INF;
    }
    
    int dfs(int u, int t, int flow) {
      if (u == t) return flow;
      vis[u] = true;
      int ans = 0;
      for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
        int v = ter[i];
        if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
          int x = dfs(v, t, std::min(cap[i], flow - ans));
          if (x) ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
        }
      }
      vis[u] = false;
      return ans;
    }
    
    int mcmf(int s, int t) {
      int ans = 0;
      while (spfa(s, t)) {
        int x;
        while ((x = dfs(s, t, INF))) ans += x;
      }
      return ans;
    }
    
    int main() {
      int s, t;
      scanf("%d%d%d%d", &n, &m, &s, &t);
      while (m--) {
        int u, v, w, c;
        scanf("%d%d%d%d", &u, &v, &w, &c);
        addedge(u, v, w, c);
      }
      int ans = mcmf(s, t);
      printf("%d %d\n", ans, ret);
      return 0;
    }
    ```

### Thuật toán Primal-Dual

Thuật toán Primal-Dual, hay thuật toán nguyên thủy-đối ngẫu,
dùng thế năng để biến đổi trọng số cạnh trước khi chạy Dijkstra.
Nếu dùng Bellman–Ford để tìm đường đi ngắn nhất thì mỗi lượt cần $O(nm)$ thời gian;
cả trên đồ thị thưa lẫn đồ thị dày, cận này đều kém Dijkstra[^note2].
Tuy nhiên, trong mạng có thể tồn tại cạnh có chi phí đơn vị âm,
nên không thể dùng trực tiếp thuật toán Dijkstra.

Ý tưởng của thuật toán này tương tự
[thuật toán Johnson tìm đường đi ngắn nhất mọi cặp](../shortest-path.md#thuật-toán-johnson-tìm-đường-đi-ngắn-nhất-mọi-cặp):
đặt một thế năng cho mỗi đỉnh để biến chi phí của mọi cạnh trong mạng thành giá trị không âm.
Sau phép biến đổi đó, ta có thể dùng Dijkstra để tìm đường tăng luồng có chi phí đơn vị nhỏ nhất.

Trước hết chạy một lần thuật toán đường đi ngắn nhất để tìm khoảng cách ngắn nhất từ nguồn đến mỗi đỉnh;
giá trị đó được dùng làm thế năng ban đầu $h_i$ của đỉnh $i$.
Tiếp theo, giống thuật toán Johnson, với một cạnh từ $u$ đến $v$ có chi phí đơn vị $w$,
đặt lại trọng số cạnh thành $w+h_u-h_v$.

Sau khi đặt thế năng như vậy, đường đi ngắn nhất trên mạng mới tương ứng với đường đi ngắn nhất trên mạng gốc.
Chứng minh đã được đưa ra khi giới thiệu thuật toán Johnson, nên không trình bày lại trong phần này.

Khác với bài toán đường đi ngắn nhất thông thường, sau mỗi lần tăng luồng, đồ thị dư sẽ thay đổi.
Vì vậy thế năng của các đỉnh cũng cần được cập nhật.

Cách cập nhật như sau.
Giả sử sau khi tăng luồng, khoảng cách ngắn nhất từ nguồn đến đỉnh $i$ là $d'_i$;
khoảng cách này được tính theo trọng số đã biến đổi.
Khi đó chỉ cần cộng $d'_i$ vào $h_i$.
Dưới đây chứng minh rằng sau cách cập nhật này, trọng số của mọi cạnh trên đồ thị đều không âm.

Sau một lượt tăng luồng, với mỗi cạnh $(i,j)$ nằm trên đường tăng luồng,
mạng dư sẽ xuất hiện cạnh ngược $(j,i)$.
Vì $(i,j)$ nằm trên đường ngắn nhất nên
$d'_i+(w(i,j)+h_i-h_j)=d'_j$.
Biến đổi công thức này sẽ được $w(j,i)+(h_j+d'_j)-(h_i+d'_i)=0$.
Vì vậy trọng số của các cạnh mới thêm là không âm.

Còn với các cạnh đã có, trước khi tăng luồng ta có
$d'_i+(w(i,j)+h_i-h_j)-d'_j \geq 0$,
do đó $w(i,j)+(d'_i+h_i)-(d'_j+h_j) \geq 0$.
Nói cách khác, dùng $h_i+d'_i$ làm thế năng mới sẽ không khiến trọng số của cạnh $(i,j)$ trở thành âm.

Tóm lại, sau khi tăng luồng, trọng số của mọi cạnh đều không âm, nên có thể dùng thuật toán Dijkstra để tìm đúng đường đi ngắn nhất trên đồ thị.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <queue>
    constexpr int INF = 0x3f3f3f3f;
    using namespace std;
    
    struct edge {
      int v, f, c, next;
    } e[100005];
    
    struct node {
      int v, e;
    } p[10005];
    
    struct mypair {
      int dis, id;
    
      bool operator<(const mypair& a) const { return dis > a.dis; }
    
      mypair(int d, int x) { dis = d, id = x; }
    };
    
    int head[5005], dis[5005], vis[5005], h[5005];
    int n, m, s, t, cnt = 1, maxf, minc;
    
    void addedge(int u, int v, int f, int c) {
      e[++cnt].v = v;
      e[cnt].f = f;
      e[cnt].c = c;
      e[cnt].next = head[u];
      head[u] = cnt;
    }
    
    bool dijkstra() {
      priority_queue<mypair> q;
      for (int i = 1; i <= n; i++) dis[i] = INF;
      memset(vis, 0, sizeof(vis));
      dis[s] = 0;
      q.push(mypair(0, s));
      while (!q.empty()) {
        int u = q.top().id;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next) {
          int v = e[i].v, nc = e[i].c + h[u] - h[v];
          if (e[i].f && dis[v] > dis[u] + nc) {
            dis[v] = dis[u] + nc;
            p[v].v = u;
            p[v].e = i;
            if (!vis[v]) q.push(mypair(dis[v], v));
          }
        }
      }
      return dis[t] != INF;
    }
    
    void spfa() {
      queue<int> q;
      memset(h, 63, sizeof(h));
      h[s] = 0, vis[s] = 1;
      q.push(s);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next) {
          int v = e[i].v;
          if (e[i].f && h[v] > h[u] + e[i].c) {
            h[v] = h[u] + e[i].c;
            if (!vis[v]) {
              vis[v] = 1;
              q.push(v);
            }
          }
        }
      }
    }
    
    int main() {
      scanf("%d%d%d%d", &n, &m, &s, &t);
      for (int i = 1; i <= m; i++) {
        int u, v, f, c;
        scanf("%d%d%d%d", &u, &v, &f, &c);
        addedge(u, v, f, c);
        addedge(v, u, 0, -c);
      }
      spfa();  // Tính thế năng ban đầu
      while (dijkstra()) {
        int minf = INF;
        for (int i = 1; i <= n; i++) h[i] += dis[i];
        for (int i = t; i != s; i = p[i].v) minf = min(minf, e[p[i].e].f);
        for (int i = t; i != s; i = p[i].v) {
          e[p[i].e].f -= minf;
          e[p[i].e ^ 1].f += minf;
        }
        maxf += minf;
        minc += minf * h[t];
      }
      printf("%d %d\n", maxf, minc);
      return 0;
    }
    ```

## Bài tập

-   [Luogu 3381 - Mẫu: Luồng cực đại chi phí nhỏ nhất](https://www.luogu.com.cn/problem/P3381)
-   [Luogu 4452 - Sắp xếp chuyến bay](https://www.luogu.com.cn/problem/P4452)
-   [SDOI 2009 - Chạy buổi sáng](https://www.luogu.com.cn/problem/P2153)
-   [SCOI 2007 - Sửa xe](https://www.luogu.com.cn/problem/P2053)
-   [HAOI 2010 - Đặt hàng](https://www.luogu.com.cn/problem/P2517)
-   [NOI 2012 - Lễ hội ẩm thực](https://loj.ac/problem/2674)

## Tài liệu tham khảo và chú thích

[^note1]: Có thể tham khảo cách xây dựng chi tiết trong [blog của min\_25](https://web.archive.org/web/20211009144446/https://min-25.hatenablog.com/entry/2018/03/19/235802).

[^note2]: Trên đồ thị thưa, dùng tối ưu bằng đống có thể đạt độ phức tạp thời gian $O(m \log n)$; còn trên đồ thị dày, không dùng tối ưu bằng đống có thể đạt độ phức tạp thời gian $O(n^2)$.
