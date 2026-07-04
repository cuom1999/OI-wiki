Cho một cây có gốc. Trên một đỉnh nào đó của cây có một đồng xu. Tại mỗi thời điểm, đồng xu sẽ di chuyển đến một đỉnh kề với xác suất bằng nhau. Hỏi kỳ vọng khoảng cách mà đồng xu cần đi để di chuyển đến một đỉnh kề.

## Các định nghĩa cần dùng

-   $T=(V,E)$: cây đang xét
-   $d(u)$: bậc của đỉnh $u$
-   $w(u,v)$: trọng số của cạnh giữa đỉnh $u$ và đỉnh $v$
-   $p_u$: đỉnh cha của đỉnh $u$
-   $\textit{root}$: đỉnh gốc của cây
-   $\textit{son}_u$: tập các đỉnh con của đỉnh $u$
-   $\textit{sibling}_u$: tập các đỉnh anh em của đỉnh $u$

## Kỳ vọng khoảng cách khi đi về đỉnh cha

Đặt $f(u)$ là kỳ vọng khoảng cách để đi từ đỉnh $u$ đến đỉnh cha $p_u$ của nó. Khi đó:

$$
f(u) = \cfrac{w(u,p_u) + \sum\limits_{v \in \textit{son}_u}(w(u,v) + f(v) + f(u))}{d(u)}
$$

Phần đầu của tử số biểu thị trường hợp đi trực tiếp đến đỉnh cha, còn phần sau biểu thị trường hợp trước tiên đi đến một đỉnh con, rồi từ đỉnh con đó quay lại, sau đó mới đi về đỉnh cha. Mẫu số $d(u)$ biểu thị rằng từ đỉnh $u$, xác suất đi đến mỗi đỉnh kề là như nhau.

Rút gọn như sau:

$$
\begin{aligned}
    f(u) &= \cfrac{w(u,p_u) + \sum\limits_{v \in \textit{son}_u}(w(u,v) + f(v) + f(u))}{d(u)} \\
         &= \cfrac{w(u,p_u) + \sum\limits_{v \in \textit{son}_u}(w(u,v) + f(v)) + (d(u)-1)f(u)}{d(u)} \\
         &= w(u,p_u) + \sum\limits_{v \in \textit{son}_u}(w(u,v) + f(v)) \\
         &= \sum\limits_{(u,t) \in E}w(u,t) + \sum\limits_{v \in \textit{son}_u}f(v)
\end{aligned}
$$

Với đỉnh lá $l$, trạng thái ban đầu là $f(l) = w(p_l, l)$.

Khi mọi cạnh trên cây đều có trọng số bằng $1$, công thức trên có thể rút gọn thành:

$$
f(u) = d(u) + \sum\limits_{v \in \textit{son}_u}f(v)
$$

Tức là tổng bậc của tất cả các đỉnh trong cây con của $u$, cũng chính là hai lần kích thước cây con của $u$ trừ $1$. Lý do là mỗi đỉnh đều có đúng một cạnh nối với cha của nó. Ngoại trừ cạnh giữa $u$ và $p_u$ chỉ đóng góp $1$ đơn vị bậc, mỗi cạnh còn lại đóng góp $2$ đơn vị bậc.

## Kỳ vọng khoảng cách khi đi đến đỉnh con

Đặt $g(u)$ là kỳ vọng khoảng cách để đi từ đỉnh $p_u$ đến đỉnh con $u$ của nó. Khi đó:

$$
g(u) = \cfrac{w(p_u,u) + \left(w(p_u,p_{p_u})+g(p_u)+g(u)\right) + \sum\limits_{s \in \textit{sibling}_u}(w(p_u,s)+f(s)+g(u))}{d(p_u)}
$$

Phần thứ nhất của tử số biểu thị trường hợp đi trực tiếp đến đỉnh con $u$. Phần thứ hai biểu thị trường hợp trước tiên đi đến đỉnh cha, rồi từ đỉnh cha đó quay lại, sau đó mới đi đến đỉnh $u$. Phần thứ ba biểu thị trường hợp trước tiên đi đến một đỉnh anh em của $u$, rồi từ đỉnh đó quay lại, sau đó mới đi đến đỉnh $u$. Mẫu số $d(p_u)$ biểu thị rằng từ đỉnh $p_u$, xác suất đi đến mỗi đỉnh kề là như nhau.

Rút gọn như sau:

$$
\begin{aligned}
    g(u) &= \cfrac{w(p_u,u) + \left(w(p_u,p_{p_u})+g(p_u)+g(u)\right) + \sum\limits_{s \in \textit{sibling}_u}(w(p_u,s)+f(s)+g(u))}{d(p_u)} \\
         &= \cfrac{w(p_u,u) + w(p_u,p_{p_u}) + g(p_u) + \sum\limits_{s \in \textit{sibling}_u}\left(w(p_u,s)+f(s)\right)+(d(p_u)-1)g(u)}{d(p_u)} \\
         &= w(p_u,u) + w(p_u,p_{p_u}) + g(p_u) + \sum\limits_{s \in \textit{sibling}_u}(w(p_u,s)+f(s)) \\
         &= \sum\limits_{(p_u,t) \in E}w(p_u,t) + g(p_u) + \sum\limits_{s \in \textit{sibling}_u}f(s) \\
         &= \sum\limits_{(p_u,t) \in E}w(p_u,t) + g(p_u) + \left(f(p_u)-\sum\limits_{(p_u,t) \in E}w(p_u,t)-f(u)\right) \\
         &= g(p_u) + f(p_u) - f(u)
\end{aligned}
$$

Trạng thái ban đầu là $g(\text{root}) = 0$.

## Cài đặt mã nguồn (ví dụ với cây không trọng số)

```cpp
vector<int> G[MAXN];

void dfs1(int u, int p) {
  f[u] = G[u].size();
  for (auto v : G[u]) {
    if (v == p) continue;
    dfs1(v, u);
    f[u] += f[v];
  }
}

void dfs2(int u, int p) {
  if (u != root) g[u] = g[p] + f[p] - f[u];
  for (auto v : G[u]) {
    if (v == p) continue;
    dfs2(v, u);
  }
}
```
