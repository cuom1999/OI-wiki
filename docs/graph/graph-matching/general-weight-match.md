author: accelsao, Henry-ZHR, yuhuoji

Trang này đi từ ghép cặp hoàn hảo trọng số lớn nhất trên đồ thị tổng quát đến ghép cặp trọng số lớn nhất trên đồ thị tổng quát. Có thể biến ghép cặp trọng số lớn nhất thành ghép cặp hoàn hảo trọng số lớn nhất bằng cách thêm các cạnh có trọng số bằng 0.

## Kiến thức chuẩn bị

<span id="blossomhoa-blossom"></span>
### Hoa (blossom)

Điểm khác nhau giữa ghép cặp trên đồ thị tổng quát và ghép cặp trên đồ thị hai phía là đồ thị có thể có chu trình lẻ. Chu trình chẵn có thể được xem như đồ thị hai phía.

Cách xử lý của thuật toán blossom (Blossom algorithm) là khi gặp một chu trình lẻ thì co nó lại thành một **hoa (blossom)**, đồng thời đặt tất cả các đỉnh trong hoa thành đỉnh chẵn. Vì mọi đỉnh trên hoa đều có thể trở thành đỉnh chẵn, ta có thể co cả hoa trực tiếp thành một đỉnh chẵn. Lưu ý rằng một hoa có thể chứa các hoa khác.

Vấn đề này cũng có thể được chuyển thành quy hoạch tuyến tính và bài toán đối ngẫu, nhưng cần xử lý thêm đối với hoa.

### Nhãn đỉnh (vertex labeling) và cạnh đẳng thức (equality edge)

Định nghĩa $z_u$ là nhãn đỉnh (vertex labeling) của đỉnh $u$, có ý nghĩa giống nhãn đỉnh trong thuật toán $KM$. Định nghĩa cạnh $e(u,v)$ là "cạnh đẳng thức" khi và chỉ khi tổng nhãn của đỉnh $u$ và đỉnh $v$ bằng trọng số của cạnh $e$ ($z_u + z_v = w(e)$). Khi đó nhãn của cạnh là $z_e = z_u + z_v - w(e) = 0$.

## Quy hoạch tuyến tính cho ghép cặp hoàn hảo trọng số lớn nhất trên đồ thị tổng quát

### Định nghĩa

Vì một hoa có ít nhất ba đỉnh và sau khi co hoa sẽ trở thành một đỉnh, đặt $O$ là tập hợp các tập có kích thước lẻ $≥3$ (bao gồm mọi hoa), và $\gamma(S)$ biểu thị tập các cạnh bên trong tập $S$.

$$
\begin{aligned}
& \text{Đặt} S\subseteq V \\
& \gamma(S)=\{(u,v)\in E:u\in S,v\in S\} \\
& O=\{B\subseteq V:|B|\text{ là số lẻ và }|B|\geq3\} \\
\end{aligned}
$$

### Bài toán đối ngẫu

???+ note "Bài toán gốc"
    $$
    \begin{aligned}
    & \max\sum_{e\in E}w(e)x_e \\
    & \text{Ràng buộc:} \\
    & x(\delta(u))=1:\forall u\in V \\
    & x(\gamma(B))\leq\lfloor\frac{|B|}{2}\rfloor:\forall B\in O \\
    & x_e\geq0:\forall e\in E \\
    \end{aligned}
    $$

Sau đó, dùng nguyên thủy - đối ngẫu (Primal-Dual) để chuyển bài toán thành bài toán đối ngẫu.

???+ note "Bài toán đối ngẫu"
    $$
    \begin{aligned}
    & \min\sum_{u\in V}z_u+\sum_{B\in O}\left\lfloor\frac{|B|}{2}\right\rfloor z_B \\
    & \text{Ràng buộc:} \\
    & z_B\geq0:\forall B\in O \\
    & z_e\geq0:\forall e\in E \\
    & \text{Đặt} e=(u,v),\text{ tại đây} \\
    & \begin{array}{lll}
    z_e & = & z_u + z_v - w(e) + \sum_{\substack{B \in O \\ u,v \in \gamma(B)}} z_B
    \end{array}
    \end{aligned}
    $$

Các cạnh có $x_e=1$ là cạnh ghép cặp, còn các cạnh có $x_e=0$ là cạnh không thuộc ghép cặp. Giống như đồ thị hai phía, ta phải thỏa mãn $x_e\in\{0,1\}:\forall e\in E$. Vì vậy, khi tìm ghép cặp hoàn hảo trọng số lớn nhất, mọi cạnh ghép cặp đều phải là **cạnh đẳng thức**.

Khác với đồ thị hai phía, đồ thị tổng quát có thêm $z_B$ cần xử lý. Sau đây xét khi nào $z_B$ lớn hơn $0$.

Có thể thấy cách tốt nhất là cố gắng để $z_B=0$, nhưng khi bắt buộc thì vẫn cần cho $z_B>0$. Khi $x(\gamma(B)) = \left\lfloor \dfrac{|B|}2 \right\rfloor \text{ và } x(\delta(B)) = 1$, ta có thể đặt $z_B>0$. Ngoài trường hợp này, $z_B>0$ không có ý nghĩa.

Theo điều kiện bổ đề chặt bổ sung, có các quan hệ tương ứng sau:

-   Với cạnh $e$ được chọn, nhất định có $z_e=0$.

    $$
    x_e>0 \longrightarrow z_e=0,\quad \forall e\in E
    $$

-   Với tập *B* được chọn, $z_B>0 \longrightarrow x(\gamma(B))= \left\lfloor \dfrac{|B|}2 \right\rfloor$, tức là mọi tập $B$ có $z_B>0$ đều đã chọn số cạnh bằng một nửa kích thước của tập, cũng có nghĩa tập $B$ là một hoa và ta chọn một cạnh trong hoa để tăng cường. Đồng thời, ta thêm một điều kiện: $x(\delta(B))=1$, tức là chỉ khi hoa $B$ nối ra ngoài bằng đúng một cạnh thì $z_B>0$ mới có ý nghĩa.

    $$
    z_B>0 \longrightarrow x(\gamma(B))=\left\lfloor\frac{|B|}2\right\rfloor, x(\delta(B))=1\quad \forall B\in O
    $$

Kết hợp khái niệm "**cạnh đẳng thức**" với thuật toán blossom đã nêu: liên tục mở rộng bằng các đường tăng cường được tạo từ "cạnh đẳng thức". Vì mọi cạnh dùng để mở rộng đều là "cạnh đẳng thức", ghép cặp hoàn hảo trọng số lớn nhất cuối cùng vẫn chỉ gồm các "cạnh đẳng thức".

### Xử lý hoa

Khi gặp một hoa, cần co nó thành một đỉnh chẵn. Đặt tất cả các đỉnh trong hoa thành đỉnh chẵn và đặt $z_B=0$ của nó.

Do sau khi co hoa ta sẽ lưu hoa lại cho đến khi thỏa mãn một số điều kiện mới bung ra, không thể dùng cách cũ để ghi nhận hoa.

Nếu không nói rõ thêm, những đỉnh được nhắc đến trước đây đều bao gồm cả các đỉnh chẵn hình thành từ việc co hoa.

Vì hoa cũng có thể được co thành một đỉnh rồi đưa vào hàng đợi, và số lượng hoa không cố định, ta không thể liệt kê từng đỉnh như trước để kiểm tra có đường tăng cường hay không. Vì vậy, khi thực hiện tìm kiếm theo chiều rộng (BFS), phải đưa mọi đỉnh chưa ghép cặp vào hàng đợi.

Như vậy sẽ đồng thời sinh ra nhiều cây luân phiên.

### Bốn bước của thuật toán

Thuật toán này có thể chia thành bốn bước.

1.  GROW (mở rộng bằng cạnh đẳng thức): dùng "cạnh đẳng thức" để xây dựng cây luân phiên.
2.  AUGMENT (tăng cường): tìm đường tăng cường và mở rộng ghép cặp.
3.  SHRINK (co hoa): co hoa thành một đỉnh.
4.  EXPAND (bung hoa): tách hoa ra.

![Bốn bước grow, augment, shrink và expand của thuật toán](images/general-weight-match-1.png)

Trong giai đoạn AUGMENT, vì mọi đỉnh chưa ghép cặp nằm trên các cây luân phiên khác nhau, nên khi hai đỉnh chẵn của hai cây luân phiên được nối với nhau trong lúc tăng cường, điều đó có nghĩa là đã tìm được một đường tăng cường.

### Không tìm được cạnh đẳng thức để mở rộng

Giống như trong đồ thị hai phía, cũng có trường hợp không tìm được "cạnh đẳng thức" để mở rộng. Khi đó cần điều chỉnh nhãn đỉnh (vertex labeling).

<span id="điều-chỉnh-vertex-labeling"></span>
### Điều chỉnh nhãn đỉnh (vertex labeling)

Nhãn đỉnh vẫn phải duy trì tính chất lớn hơn hoặc bằng, các "cạnh đẳng thức" đã có không được thay đổi, đồng thời cần làm cho $z_B$ nhỏ nhất có thể.

???+ note "Ký hiệu đỉnh chẵn lẻ"
    Dùng $u^-$ để biểu thị $u$ là đỉnh lẻ trên cây luân phiên.
    Dùng $u^+$ để biểu thị $u$ là đỉnh chẵn trên cây luân phiên.
    Dùng $u^\varnothing$ để biểu thị $u$ không nằm trên bất kỳ cây luân phiên nào.
    Mọi $B$ được nhắc đến sau đây mặc định là hoa, đồng thời cũng đại diện cho đỉnh sau khi co hoa.
    Hoa cũng có thể phân thành hoa lẻ và hoa chẵn, nên các ký hiệu như $B^+$, $B^-$, $B^\varnothing$ cũng áp dụng được.

Giả sử hiện có r cây luân phiên $T_i=(U_{t_i},V_{t_i}):1\leq i\leq r$, đặt

$$
\begin{aligned}
d1 &= \min(\{z_e : e = (u^+,v^\varnothing)\}) \\
d2 &= \min(\{z_e : e = (u^+,v^+), ~ u^+ \in T_i, ~ v^+ \in T_j, ~ i \neq j\}) / 2 \\
d3 &= \min(\{z_{B^-} : B^- \in O\}) / 2
\end{aligned}
$$

Lưu ý ở đây *B* là đỉnh sau khi co hoa, nên có thể có tính chẵn lẻ.

Đặt $d=min(d1,d2,d3)$, cho

$$
\begin{aligned}
z_{u^+} - &= d \\
z_{v^-} + &= d \\
z_{B^+} + &= 2d \\
z_{B^-} - &= 2d \\
\end{aligned}
$$

Nếu xuất hiện $z_B=0(d=d3)$, để tránh trường hợp $z_B<0$, cần bung hoa này ra (EXPAND).
Sau khi bung hoa, chỉ giữ lại đường luân phiên bên trong hoa, và đặt các đỉnh trong hoa không nằm trên đường luân phiên thành chưa thăm ($\varnothing$).

Như vậy ta tạo ra một hoặc nhiều cạnh đẳng thức, giữ nguyên các cạnh đẳng thức đã có, vẫn duy trì tính chất $z_e\geq0:\forall e\in E$, đồng thời chỉ tăng $z_B$ ở mức tối thiểu, rồi có thể tiếp tục tìm đường tăng cường.

## Ghép cặp trọng số lớn nhất trên đồ thị tổng quát

Phần trên tìm ghép cặp hoàn hảo trọng số lớn nhất. Để tìm ghép cặp trọng số lớn nhất, cần thêm một ràng buộc vào nhãn đỉnh: với mọi đỉnh đã ghép cặp $u$, $z_u>0$.

Ban đầu đặt mọi $z_u=max(\{w(e):e\in E\})/2$.

Các đỉnh có nhãn đỉnh bằng $0$ cuối cùng sẽ trở thành đỉnh chưa ghép cặp.

<span id="code-tham-khảo"></span>
### Mã tham khảo

Ở đây, để tiện cài đặt, ta nhân trọng số cạnh với $2$ khi tính giá trị $z_e$, nhờ vậy sẽ không có sai số số thực.

???+ note "Lưu trữ"
    ```cpp
    constexpr int INF = INT_MAX;
    constexpr int MAXN = 400;
    
    struct edge {
      int u, v, w;
    
      // Biểu thị (u,v) là một cạnh có trọng số w
      edge() {}
    
      edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };
    
    int n, n_x;
    // Có n đỉnh, đánh số từ 1 đến n
    // n_x biểu thị tổng số đỉnh hiện tại cộng với số hoa,
    // các đỉnh hoa được đánh số từ n+1 đến n_x
    edge g[MAXN * 2 + 1][MAXN * 2 + 1];
    // Đồ thị được lưu bằng ma trận kề, vì tối đa có n-1 hoa nên kích thước là MAXN*2
    vector<int> flower[MAXN * 2 + 1];
    // flower[b] ghi lại những đỉnh nào nằm trong hoa b
    // Cách ghi các đỉnh trong hoa chỉ ghi các hoa ngoài cùng nằm trong hoa đó
    ```

Dưới đây là ví dụ về hoa lồng nhau.

![Ví dụ hoa lồng nhau trong ghép cặp trọng số tổng quát](images/general-weight-match-2.png)

Trong đó $\{ 6, 5, 8\} \in b1,\{ b1, 4, 3, 2, 11, 10, 9\} \in b2$. Lưu trữ thành:

```text
flower[b2] = {b1, 4, 3, 2, 11, 10, 9} 
flower[b1] = {6, 5, 8}
```

![Cách lưu các đỉnh của hoa lồng nhau bằng mảng flower](images/general-weight-match-3.png)

```text
flower[b2] = {9, b1, 4, 3, 2, 11, 10} 
flower[b1] = {5, 8, 6}
```

```cpp
int lab[MAXN * 2 + 1];
// lab[u] dùng để ghi z_u, lab[b] dùng để ghi z_B
int match[MAXN * 2 + 1], slack[MAXN * 2 + 1], st[MAXN * 2 + 1],
    pa[MAXN * 2 + 1];
// match[x]=y biểu thị (x,y) là cặp ghép, ở đây x và y có thể là hoa
// slack[x]=u biểu thị z(x,u) là nhỏ nhất trong các cạnh kề với x
// st[x]=b biểu thị hoa chứa nút x là b. Nếu x=b và b<=n thì x
// là một nút thông thường không thuộc bất kỳ hoa nào.
// pa[v]=u biểu thị trong cây luân phiên, nút cha của v là u
int flower_from[MAXN * 2 + 1][MAXN + 1], S[MAXN * 2 + 1], vis[MAXN * 2 + 1];
/*
flower_from[b][x]=xs biểu thị hoa con lớn nhất của b có chứa x là xs
x là một đỉnh trong b, xs là một hoa hoặc một đỉnh trong b,
đồng thời x=xs hoặc x là một trong các đỉnh của xs
*/
// S[u]={-1: chưa thăm, 0: đỉnh chẵn, 1: đỉnh lẻ}
// vis chỉ được dùng khi tìm lca để kiểm tra đã đi qua hay chưa
queue<int> q;
// queue dùng cho BFS tìm đường tăng cường
```

![Ánh xạ flower_from trong hoa lồng nhau](images/general-weight-match-4.png)

```text
flower_from[b2][6] = b1 
flower_from[b2][5] = b1 
flower_from[b2][9] = 9 
flower_from[b1][6] = 6 
Và cứ thế tiếp
```

```cpp
int e_delta(const edge &e) {
  // Tính ze. Để tiện lợi, trước đó nhân trọng số mỗi cạnh với hai
  // Tính trực tiếp giá trị e_delta bên trong hoa sẽ gây lỗi
  return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2;
}

void update_slack(int u, int x) {
  // Dùng u để cập nhật giá trị slack[x]
  if (!slack[x] || e_delta(g[u][x]) < e_delta(g[slack[x]][x])) {
    slack[x] = u;
  }
}

void set_slack(int x) {
  // Tính giá trị slack[x], slack[x]=0 biểu thị x là nút trong cây luân phiên
  slack[x] = 0;
  for (int u = 1; u <= n; ++u) {
    if (g[u][x].w > 0 && st[u] != x && S[st[u]] == 0) {
      update_slack(u, x);
    }
  }
}
```

```cpp
void q_push(int x) {
  // Đưa x vào queue, ta quy định queue không thể push trực tiếp một hoa
  if (x <= n)
    q.push(x);
  else {
    // Nếu muốn push một hoa thì phải thêm tất cả đỉnh của đồ thị gốc trong hoa vào queue
    for (size_t i = 0; i < flower[x].size(); i++) {
      q_push(flower[x][i]);
    }
  }
}

void set_st(int x, int b) {
  // Đặt hoa chứa x thành b
  st[x] = b;
  if (x > n) {
    // Nếu x cũng là hoa, phải đặt hoa chứa các đỉnh bên trong x thành b
    for (size_t i = 0; i < flower[x].size(); ++i) {
      set_st(flower[x][i], b);
    }
  }
}
```

```cpp
int get_pr(int b, int xr) {
  // xr là một đỉnh trong flower[b], giá trị trả về pr là vị trí của nó
  // Để chương trình chạy thuận tiện, ta để flower[b][0]~flower[b][pr] là đường luân phiên trong hoa
  int pr = find(flower[b].begin(), flower[b].end(), xr) - flower[b].begin();
  if (pr % 2 == 1) {
    // Kiểm tra vị trí của nó trong hoa. Nếu flower[b][0]~flower[b][pr] không phải đường luân phiên
    // thì đảo ngược cả hoa và tính lại pr
    // Để flower[b][0]~flower[b][pr] thành đường luân phiên trong hoa
    reverse(flower[b].begin() + 1, flower[b].end());
    return (int)flower[b].size() - pr;
  } else
    return pr;
}
```

![Ví dụ tính vị trí trong hoa bằng get_pr](images/general-weight-match-5.png)

Nếu dùng `get_pr(b2,11)`, `flower[b2]` sẽ trở thành `{9,10,11,2,3,4,b1}` và trả về 2.

Nếu dùng `get_pr(b2,2)`, `flower[b2]` sẽ trở thành `{9,b1,4,3,2,11,10}` và trả về 4.

```cpp
void set_match(int u, int v) {
  // Đặt u và v thành cạnh ghép cặp, u và v có thể là hoa
  match[u] = g[u][v].v;
  if (u > n) {
    // Nếu u là hoa
    edge e = g[u][v];
    int xr = flower_from[u][e.u];  // Tìm e.u nằm trên hoa nào trong flower[u]
    int pr = get_pr(u, xr);  // Tìm vị trí của xr và để 0~pr là đường luân phiên trong hoa
    for (int i = 0; i < pr; ++i) {  // Đảo các cạnh ghép và không ghép trên đường luân phiên trong hoa
      set_match(flower[u][i], flower[u][i ^ 1]);
    }
    set_match(xr, v);  // Đặt (xr,v) thành cạnh ghép cặp
    rotate(flower[u].begin(), flower[u].begin() + pr, flower[u].end());
    // Cuối cùng đặt pr thành đế hoa, vì cách lưu hoa là flower[u][0] sẽ là đế hoa của u
    // Nên cần rotate flower[u][pr] về đầu
  }
}

void augment(int u, int v) {
  // Tăng cường toàn bộ u và các tổ tiên của u, đồng thời đặt (u,v) thành cạnh ghép cặp
  for (;;) {
    int xnv = st[match[u]];
    set_match(u, v);
    if (!xnv) return;
    set_match(xnv, st[pa[xnv]]);
    u = st[pa[xnv]];
    v = xnv;
  }
}

int get_lca(int u, int v) {
  // Tìm lca của u, v trên cây luân phiên
  static int t = 0;
  for (++t; u || v; swap(u, v)) {
    if (u == 0) continue;
    if (vis[u] == t) return u;
    vis[u] = t;  // Cách này giúp không cần xóa mảng vis
    u = st[match[u]];
    if (u) u = st[pa[u]];
  }
  return 0;
}
```

???+ note "Thêm một hoa lẻ"
    ```cpp
    void add_blossom(int u, int lca, int v) {
      // Co hoa tạo bởi u, v, lca thành một đỉnh b
      // lca của u, v trên cây luân phiên chính là đế hoa
      int b = n + 1;
      while (b <= n_x && st[b]) ++b;
      if (b > n_x) ++n_x;
      // Tìm chỉ số hoa hiện chưa được dùng
      lab[b] = 0;             // Đặt zB=0
      S[b] = 0;               // Cả hoa là một đỉnh chẵn
      match[b] = match[lca];  // Đặt cạnh ghép của hoa thành cạnh ghép của đế hoa
      flower[b].clear();
      flower[b].push_back(lca);
      for (int x = u, y; x != lca; x = st[pa[y]]) {
        flower[b].push_back(x);
        y = st[match[x]];
        flower[b].push_back(y);
        q_push(y);
      }
      reverse(flower[b].begin() + 1, flower[b].end());
      for (int x = v, y; x != lca; x = st[pa[y]]) {
        flower[b].push_back(x);
        y = st[match[x]];
        flower[b].push_back(y);
        q_push(y);
      }
      // Đưa tất cả đỉnh trong b vào flower[b] theo dạng vòng, và đặt đế hoa làm phần tử đầu tiên
      set_st(b, b);  // Đặt hoa chứa mỗi phần tử trong cả hoa thành b
      for (int x = 1; x <= n_x; ++x) {
        g[b][x].w = 0;
        g[x][b].w = 0;
      }
      for (int x = 1; x <= n; ++x) {
        flower_from[b][x] = 0;
      }
      for (size_t i = 0; i < flower[b].size(); ++i) {
        int xs = flower[b][i];
        for (int x = 1; x <= n_x; ++x) {
          // Đặt cạnh kề giữa b và x thành cạnh trong b kề với x có e_delta nhỏ nhất
          if (g[b][x].w == 0 || e_delta(g[xs][x]) < e_delta(g[b][x])) {
            g[b][x] = g[xs][x];
            g[x][b] = g[x][xs];
          }
        }
        for (int x = 1; x <= n; ++x) {
          if (flower_from[xs][x]) {
            // Nếu đỉnh xs bên trong b có chứa x
            // Thì flower_from[b][x] sẽ là xs
            flower_from[b][x] = xs;
          }
        }
      }
      set_slack(b);
      // Cuối cùng phải đặt giá trị slack của b
    }
    ```

???+ note "Bung hoa"
    ```cpp
    void expand_blossom(int b) {
      // Khi b là hoa lẻ và zB=0, phải bung b ra
      // Vì chỉ bung b, nên nếu bên trong b có chứa các hoa khác
      // thì không cần bung chúng ra
      for (size_t i = 0; i < flower[b].size(); ++i) {
        set_st(flower[b][i], flower[b][i]);
        // Trước tiên đặt hoa chứa mỗi phần tử trong flower[b] thành chính nó
      }
      int xr = flower_from[b][g[b][pa[b]].u];
      // xr biểu thị nút cha của b trên đường luân phiên nằm trên hoa nào trong flower[b]
      int pr = get_pr(b, xr);  // Tìm vị trí của xr và để 0~pr là đường luân phiên trong hoa
      for (int i = 0; i < pr; i += 2) {
        // Bung đường luân phiên vào trong cây luân phiên
        // Và đưa các đỉnh chẵn trong đường luân phiên vào queue
        int xs = flower[b][i];
        int xns = flower[b][i + 1];
        pa[xs] = g[xns][xs].u;
        S[xs] = 1;
        S[xns] = 0;
        slack[xs] = 0;
        set_slack(xns);
        q_push(xns);
      }
      S[xr] = 1;  // Lúc này xr sẽ là đỉnh lẻ hoặc hoa lẻ
      pa[xr] = pa[b];
      for (size_t i = pr + 1; i < flower[b].size(); ++i) {
        // Đặt mỗi đỉnh trong hoa không nằm trên đường luân phiên thành chưa thăm
        int xs = flower[b][i];
        S[xs] = -1;
        set_slack(xs);
      }
      st[b] = 0;
    }
    ```

???+ note "Thử tăng cường một cạnh đẳng thức"
    ```cpp
    bool on_found_edge(const edge &e) {
      // Tìm thấy một cạnh đẳng thức e trong BFS
      // Cần xử lý nó theo các bước sau
      // Ở đây u nhất định là đỉnh chẵn
      int u = st[e.u], v = st[e.v];
      if (S[v] == -1) {
        // v là nút chưa thăm
        pa[v] = e.u;
        S[v] = 1;
        int nu = st[match[v]];
        slack[v] = 0;
        slack[nu] = 0;
        S[nu] = 0;
        q_push(nu);
      } else if (S[v] == 0) {
        // v là đỉnh chẵn
        int lca = get_lca(u, v);
        if (!lca) {  // lca=0 biểu thị u, v ở hai cây luân phiên khác nhau, có đường tăng cường
          augment(u, v);
          augment(v, u);
          return true;  // Tìm thấy đường tăng cường
        } else
          add_blossom(u, lca, v);
        // Ngược lại, u và v ở cùng một cây thì sẽ tạo thành một hoa, cần co hoa
      }
      return false;
    }
    ```

???+ note "Tăng cường"
    ```cpp
    bool matching() {
      memset(S + 1, -1, sizeof(int) * n_x);
      memset(slack + 1, 0, sizeof(int) * n_x);
      q = queue<int>();  // Xóa rỗng queue
      for (int x = 1; x <= n_x; ++x) {
        if (st[x] == x && !match[x]) {
          // Đưa tất cả đỉnh chưa ghép cặp vào queue và đặt thành đỉnh chẵn
          pa[x] = 0;
          S[x] = 0;
          q_push(x);
        }
      }
      if (q.empty()) return false;  // Tất cả đỉnh đều đã được ghép cặp
      for (;;) {
        while (q.size()) {
          // BFS
          int u = q.front();
          q.pop();
          if (S[st[u]] == 1) continue;
          for (int v = 1; v <= n; ++v) {
            if (g[u][v].w > 0 && st[u] != st[v]) {
              if (e_delta(g[u][v]) == 0) {
                if (on_found_edge(g[u][v])) return true;
              } else
                update_slack(u, st[v]);
            }
          }
        }
        // Sửa giá trị lab
        int d = INF;
        for (int u = 1; u <= n; ++u) {
          // Để tránh xảy ra trường hợp lab<0
          // Chỉ cần có bất kỳ lab[u]=0 nào thì kết thúc chương trình
          if (S[st[u]] == 0) d = min(d, lab[u]);
        }
        for (int b = n + 1; b <= n_x; ++b) {
          if (st[b] == b && S[b] == 1) d = min(d, lab[b] / 2);
        }
        for (int x = 1; x <= n_x; ++x)
          if (st[x] == x && slack[x]) {
            if (S[x] == -1)
              d = min(d, e_delta(g[slack[x]][x]));
            else if (S[x] == 0)
              d = min(d, e_delta(g[slack[x]][x]) / 2);
          }
        for (int u = 1; u <= n; ++u) {
          if (S[st[u]] == 0) {
            if (lab[u] == d) return false;
            // Nếu lab[u]=0 thì kết thúc trực tiếp chương trình
            lab[u] -= d;
          } else if (S[st[u]] == 1)
            lab[u] += d;
        }
        for (int b = n + 1; b <= n_x; ++b) {
          if (st[b] == b) {
            if (S[st[b]] == 0)
              lab[b] += d * 2;
            else if (S[st[b]] == 1)
              lab[b] -= d * 2;
          }
        }
        q = queue<int>();  // Xóa rỗng queue
        for (int x = 1; x <= n_x; ++x) {
          // Kiểm tra xem có sinh ra đường tăng cường hay không
          if (st[x] == x && slack[x] && st[slack[x]] != x &&
              e_delta(g[slack[x]][x]) == 0)
            if (on_found_edge(g[slack[x]][x])) return true;
        }
        for (int b = n + 1; b <= n_x; ++b) {
          // Thao tác EXPAND, bung mỗi hoa lẻ có lab[b]=0
          if (st[b] == b && S[b] == 1 && lab[b] == 0) expand_blossom(b);
        }
      }
      return false;
    }
    ```

???+ note "Hàm chính"
    ```cpp
    pair<long long, int> weight_blossom() {
      // Hàm chính, ban đầu khởi tạo trước
      memset(match + 1, 0, sizeof(int) * n);
      n_x = n;  // Ban đầu chưa có hoa
      int n_matches = 0;
      long long tot_weight = 0;
      for (int u = 0; u <= n; ++u) {
        // Trước tiên đặt hoa chứa chính nó thành chính nó
        st[u] = u;
        flower[u].clear();
      }
      int w_max = 0;
      for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v) {
          // Khi u là một đỉnh, các đỉnh mà nó chứa chỉ có chính nó
          flower_from[u][v] = (u == v ? u : 0);
          w_max = max(w_max, g[u][v].w);
          // Tìm trọng số cạnh lớn nhất
        }
      for (int u = 1; u <= n; ++u) lab[u] = w_max;
      // Đặt mỗi lab bằng trọng số cạnh lớn nhất
      // Vì phần cài đặt này dùng trọng số cạnh nhân hai để tính ze, nên không cần chia hai
      while (matching()) ++n_matches;
      for (int u = 1; u <= n; ++u)
        if (match[u] && match[u] < u) tot_weight += g[u][match[u]].w;
      return make_pair(tot_weight, n_matches);
    }
    ```

???+ note "Khởi tạo"
    Rất quan trọng: nhất định phải khởi tạo trước khi dùng.
    
    ```cpp
    void init_weight_graph() {
      // Phải khởi tạo trước khi nhập cạnh vào đồ thị
      // Vì đây là ghép cặp trọng số lớn nhất, đặt cạnh không tồn tại bằng 0
      for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v) g[u][v] = edge(u, v, 0);
    }
    ```

## Phân tích độ phức tạp

Mỗi hoa chỉ bị co hoặc bung một lần trong một BFS. Mỗi lần co hoa hoặc bung hoa có độ phức tạp thời gian $O(|V|)$. Tổng cộng có nhiều nhất $O(|V|)$ hoa, nên phần xử lý hoa tốn $O(|V|^2)$ thời gian. Còn BFS có độ phức tạp thời gian $O(|V| + |E|)$. Vì vậy, tìm đường tăng cường tốn $O(|V| + |E|) + O(|V|^2) = O(|V|^2)$ thời gian.

Thực hiện nhiều nhất $|V|$ lần BFS. Do đó, tổng độ phức tạp thời gian là $O(|V|^3)$.

## Bài tập

-   [UOJ #81. Ghép cặp trọng số lớn nhất trên đồ thị tổng quát](https://uoj.ac/problem/81)

## Tài liệu tham khảo

1.  [Kolmogorov, Vladimir (2009), "Blossom V: A new implementation of a minimum cost perfect matching algorithm"](http://pub.ist.ac.at/~vnk/papers/BLOSSOM5.html)
2.  [Từ thuật toán Hungary đến cây blossom có trọng số - giải thích chi tiết ứng dụng của bài toán đối ngẫu trong ghép cặp đồ thị](https://www.luogu.com.cn/blog/potassium/solution-p6699)
