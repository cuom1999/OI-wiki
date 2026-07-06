Trước khi học cây khung đường kính nhỏ nhất (Minimum Diameter Spanning Tree), nên đọc nội dung về [đường kính của cây](./tree-diameter.md).

## Định nghĩa

Trong tất cả các cây khung của một đồ thị vô hướng, cây khung có đường kính nhỏ nhất chính là cây khung đường kính nhỏ nhất.

## Tâm tuyệt đối của đồ thị

Để tìm cây khung có đường kính nhỏ nhất, trước hết cần tìm **tâm tuyệt đối của đồ thị**. **Tâm tuyệt đối của đồ thị** có thể nằm trên một cạnh hoặc tại một đỉnh; nó là vị trí sao cho giá trị lớn nhất trong các khoảng cách ngắn nhất từ vị trí đó đến mọi đỉnh là nhỏ nhất.

Theo định nghĩa của **tâm tuyệt đối của đồ thị**, có thể biết rằng có ít nhất hai đỉnh xa tâm tuyệt đối nhất.

Gọi $d(i,j)$ là độ dài đường đi ngắn nhất giữa hai đỉnh $i,j$. Dùng thuật toán đường đi ngắn nhất đa nguồn để tính đường đi ngắn nhất giữa mọi cặp đỉnh.

$\textit{rk}(i,j)$ ghi lại đỉnh có khoảng cách nhỏ thứ $j$ từ đỉnh $i$ trong tất cả các đỉnh còn lại.

Tâm tuyệt đối của đồ thị có thể nằm trên một cạnh nào đó. Duyệt từng cạnh $w=(u,v)$ và giả sử tâm tuyệt đối của đồ thị $c$ nằm trên cạnh này. Khi đó khoảng cách từ $c$ đến $u$ là $x$ ($x \leq w$), còn khoảng cách từ $c$ đến $v$ là $w - x$.

Với một đỉnh bất kỳ $i$ trong đồ thị, khoảng cách từ tâm tuyệt đối của đồ thị $c$ đến $i$ là $d(c,i)=\min(d(u,i) + x, d(v,i) + (w - x))$.

Lấy một đỉnh $i$ làm ví dụ, quan hệ vị trí giữa đỉnh này và tâm tuyệt đối của đồ thị được minh họa như sau.

![Quan hệ vị trí giữa đỉnh và tâm tuyệt đối của đồ thị](./images/mdst-graph.svg)

Khi tâm tuyệt đối của đồ thị $c$ thay đổi vị trí trên cạnh, thu được đồ thị hàm số biểu diễn khoảng cách theo vị trí của $c$. Đồ thị hàm số của $d(c,i)$ hiện tại là một đường gấp khúc gồm hai đoạn thẳng có hệ số góc cố định.

![Đồ thị hàm khoảng cách từ tâm tuyệt đối đến một đỉnh](./images/mdst-plot1.svg)

Với mọi đỉnh trên đồ thị, hàm số mô tả khoảng cách từ tâm tuyệt đối của đồ thị đến đỉnh xa nhất được viết là $f = \max\{ d(c,i)\},i \in[1,n]$; đồ thị hàm số của nó như sau.

![Đồ thị hàm khoảng cách lớn nhất từ tâm tuyệt đối đến các đỉnh](./images/mdst-plot2.svg)

Điểm thấp nhất trong các giao điểm của những đường gấp khúc này có hoành độ chính là vị trí của tâm tuyệt đối của đồ thị.

Tâm tuyệt đối của đồ thị cũng có thể nằm tại một đỉnh. Khi đó dùng đỉnh xa nhất so với đỉnh đang xét để cập nhật, tức là $\textit{ans}\leftarrow \min(\textit{ans},d(i,\textit{rk}(i,n))\times 2)$.

### Quy trình

1.  Dùng thuật toán đường đi ngắn nhất đa nguồn ([Floyd](./shortest-path.md#thuật-toán-floyd), [Johnson](./shortest-path.md#thuật-toán-johnson-tìm-đường-đi-ngắn-nhất-mọi-cặp), v.v.) để tính mảng $d$;

2.  Tính $\textit{rk}(i,j)$ và sắp xếp nó theo thứ tự tăng dần;

3.  Tâm tuyệt đối của đồ thị có thể nằm tại một đỉnh. Dùng đỉnh xa nhất so với đỉnh đang xét để cập nhật; duyệt mọi đỉnh và cập nhật giá trị nhỏ nhất bằng $\textit{ans}\leftarrow \min(\textit{ans},d(i,\textit{rk}(i,n)) \times 2)$.

4.  Tâm tuyệt đối của đồ thị có thể nằm trên một cạnh, nên duyệt tất cả các cạnh. Với một cạnh $w(u,v)$, bắt đầu cập nhật từ đỉnh xa $u$ nhất. Khi xuất hiện trường hợp $d(v,\textit{rk}(u,i)) > \max_{j=i+1}^n d(v,\textit{rk}(u,j))$, dùng $\textit{ans}\leftarrow  \min(\textit{ans}, d(u,\textit{rk}(u,i))+\max_{j=i+1}^n d(v,\textit{rk}(u,j))+w(u,v))$ để cập nhật. Lý do là trường hợp này sẽ làm vị trí tâm tuyệt đối của đồ thị thay đổi.

??? note "Cài đặt"
    ```cpp
    bool cmp(int a, int b) { return val[a] < val[b]; }
    
    void Floyd() {
      for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    
    void solve() {
      Floyd();
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          rk[i][j] = j;
          val[j] = d[i][j];
        }
        sort(rk[i] + 1, rk[i] + 1 + n, cmp);
      }
      int ans = INF;
      // Tâm tuyệt đối của đồ thị có thể nằm tại đỉnh
      for (int i = 1; i <= n; i++) ans = min(ans, d[i][rk[i][n]] * 2);
      // Tâm tuyệt đối của đồ thị có thể nằm trên cạnh
      for (int i = 1; i <= m; i++) {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        for (int p = n, i = n - 1; i >= 1; i--) {
          if (d[v][rk[u][i]] > d[v][rk[u][p]]) {
            ans = min(ans, d[u][rk[u][i]] + d[v][rk[u][p]] + w);
            p = i;
          }
        }
      }
    }
    ```

### Bài tập ví dụ

-   [CodeForce 266D BerDonalds](https://codeforces.com/contest/266/problem/D)

## Cây khung đường kính nhỏ nhất

Theo định nghĩa của tâm tuyệt đối của đồ thị, tâm tuyệt đối của đồ thị là trung điểm của đường kính trong cây khung đường kính nhỏ nhất.

Để tìm cây khung đường kính nhỏ nhất, trước hết cần tìm tâm tuyệt đối của đồ thị. Lấy tâm tuyệt đối của đồ thị làm điểm bắt đầu và sinh một cây đường đi ngắn nhất, khi đó thu được cây khung đường kính nhỏ nhất.

??? note "Cài đặt"
    ```cpp
    #include <algorithm>
    #include <climits>
    #include <iostream>
    #include <vector>
    using namespace std;
    constexpr int MAXN = 502;
    using ll = long long;
    using pii = pair<int, int>;
    ll d[MAXN][MAXN], dd[MAXN][MAXN], rk[MAXN][MAXN], val[MAXN];
    constexpr ll INF = 1e17;
    int n, m;
    
    bool cmp(int a, int b) { return val[a] < val[b]; }
    
    void floyd() {
      for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    
    struct node {
      ll u, v, w;
    } a[MAXN * (MAXN - 1) / 2];
    
    void solve() {
      // Tìm tâm tuyệt đối của đồ thị
      floyd();
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          rk[i][j] = j;
          val[j] = d[i][j];
        }
        sort(rk[i] + 1, rk[i] + 1 + n, cmp);
      }
      ll P = 0, ansP = INF;
      // Nằm tại đỉnh
      for (int i = 1; i <= n; i++) {
        if (d[i][rk[i][n]] * 2 < ansP) {
          ansP = d[i][rk[i][n]] * 2;
          P = i;
        }
      }
      // Nằm trên cạnh
      int f1 = 0, f2 = 0;
      ll disu = INT_MIN, disv = INT_MIN, ansL = INF;
      for (int i = 1; i <= m; i++) {
        ll u = a[i].u, v = a[i].v, w = a[i].w;
        for (int p = n, i = n - 1; i >= 1; i--) {
          if (d[v][rk[u][i]] > d[v][rk[u][p]]) {
            if (d[u][rk[u][i]] + d[v][rk[u][p]] + w < ansL) {
              ansL = d[u][rk[u][i]] + d[v][rk[u][p]] + w;
              f1 = u, f2 = v;
              disu = (d[u][rk[u][i]] + d[v][rk[u][p]] + w) / 2 - d[u][rk[u][i]];
              disv = w - disu;
            }
            p = i;
          }
        }
      }
      cout << min(ansP, ansL) / 2 << '\n';
      // Cây khung đường đi ngắn nhất
      vector<pii> pp;
      for (int i = 1; i <= 501; ++i)
        for (int j = 1; j <= 501; ++j) dd[i][j] = INF;
      for (int i = 1; i <= 501; ++i) dd[i][i] = 0;
      if (ansP <= ansL) {
        for (int j = 1; j <= n; j++) {
          for (int i = 1; i <= m; ++i) {
            ll u = a[i].u, v = a[i].v, w = a[i].w;
            if (dd[P][u] + w == d[P][v] && dd[P][u] + w < dd[P][v]) {
              dd[P][v] = dd[P][u] + w;
              pp.push_back({u, v});
            }
            u = a[i].v, v = a[i].u, w = a[i].w;
            if (dd[P][u] + w == d[P][v] && dd[P][u] + w < dd[P][v]) {
              dd[P][v] = dd[P][u] + w;
              pp.push_back({u, v});
            }
          }
        }
        for (auto [x, y] : pp) cout << x << ' ' << y << '\n';
      } else {
        d[n + 1][f1] = disu;
        d[f1][n + 1] = disu;
        d[n + 1][f2] = disv;
        d[f2][n + 1] = disv;
        a[m + 1].u = n + 1, a[m + 1].v = f1, a[m + 1].w = disu;
        a[m + 2].u = n + 1, a[m + 2].v = f2, a[m + 2].w = disv;
        n += 1;
        m += 2;
        floyd();
        P = n;
        for (int j = 1; j <= n; j++) {
          for (int i = 1; i <= m; ++i) {
            ll u = a[i].u, v = a[i].v, w = a[i].w;
            if (dd[P][u] + w == d[P][v] && dd[P][u] + w < dd[P][v]) {
              dd[P][v] = dd[P][u] + w;
              pp.push_back({u, v});
            }
            u = a[i].v, v = a[i].u, w = a[i].w;
            if (dd[P][u] + w == d[P][v] && dd[P][u] + w < dd[P][v]) {
              dd[P][v] = dd[P][u] + w;
              pp.push_back({u, v});
            }
          }
        }
        cout << f1 << ' ' << f2 << '\n';
        for (auto [x, y] : pp)
          if (x != n && y != n) cout << x << ' ' << y << '\n';
      }
    }
    
    void init() {
      for (int i = 1; i <= 501; ++i)
        for (int j = 1; j <= 501; ++j) d[i][j] = INF;
      for (int i = 1; i <= 501; ++i) d[i][i] = 0;
    }
    
    int main() {
      init();
      cin >> n >> m;
      for (int i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        w *= 2;
        d[u][v] = w, d[v][u] = w;
        a[i].u = u, a[i].v = v, a[i].w = w;
      }
      solve();
      return 0;
    }
    ```

### Bài tập ví dụ

[SPOJ MDST](https://www.spoj.com/problems/MDST/)

[timus 1569. Networking the "Iset"](https://acm.timus.ru/problem.aspx?space=1&num=1569)

[SPOJ PT07C - The GbAaY Kingdom](https://www.spoj.com/problems/PT07C)

## Tài liệu tham khảo

[Play with Trees Solutions The GbAaY Kingdom](https://adn.botao.hu/adn-backup/blog/attachments/month_0705/32007531153238.pdf)
