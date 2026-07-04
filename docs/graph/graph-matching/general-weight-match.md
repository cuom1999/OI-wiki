author: accelsao, Henry-ZHR, yuhuoji

Trang này đi từ ghép cặp hoàn hảo trọng số lớn nhất trên đồ thị tổng quát đến ghép cặp trọng số lớn nhất trên đồ thị tổng quát. Có thể biến ghép cặp trọng số lớn nhất thành ghép cặp hoàn hảo trọng số lớn nhất bằng cách thêm các cạnh có trọng số bằng 0.

## Kiến thức chuẩn bị

### Blossom/hoa (blossom)

Điểm khác nhau giữa ghép cặp trên đồ thị tổng quát và ghép cặp trên đồ thị hai phía là đồ thị có thể có chu trình lẻ. Chu trình chẵn có thể được xem như đồ thị hai phía.

Cách xử lý của thuật toán blossom (Blossom Algorithm) là khi gặp một chu trình lẻ thì co nó lại thành một **blossom/hoa (Blossom)**, đồng thời đặt tất cả các đỉnh trong hoa thành đỉnh chẵn. Vì mọi đỉnh trên hoa đều có thể trở thành đỉnh chẵn, ta có thể co cả hoa trực tiếp thành một đỉnh chẵn. Lưu ý rằng một hoa có thể chứa các hoa khác.

Vấn đề này cũng có thể được chuyển thành quy hoạch tuyến tính và bài toán đối ngẫu, nhưng cần xử lý thêm đối với hoa.

### Nhãn đỉnh (vertex labeling) và cạnh đẳng thức (Equality Edge)

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

1.  GROW (cạnh đẳng thức): dùng "cạnh đẳng thức" để xây dựng cây luân phiên.
2.  AUGMENT (tăng cường): tìm đường tăng cường và mở rộng ghép cặp.
3.  SHRINK (co hoa): co hoa thành một đỉnh.
4.  EXPAND (bung hoa): tách hoa ra.

![general-weight-match-1](images/general-weight-match-1.png)

Trong giai đoạn AUGMENT, vì mọi đỉnh chưa ghép cặp nằm trên các cây luân phiên khác nhau, nên khi hai đỉnh chẵn của hai cây luân phiên được nối với nhau trong lúc tăng cường, điều đó có nghĩa là đã tìm được một đường tăng cường.

### Không tìm được cạnh đẳng thức để mở rộng

Giống như trong đồ thị hai phía, cũng có trường hợp không tìm được "cạnh đẳng thức" để mở rộng. Khi đó cần điều chỉnh vertex labeling.

### Điều chỉnh VERTEX LABELING

Vertex labeling vẫn phải duy trì tính chất lớn hơn hoặc bằng, các "cạnh đẳng thức" đã có không được thay đổi, đồng thời cần làm cho $z_B$ nhỏ nhất có thể.

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

Phần trên tìm ghép cặp hoàn hảo trọng số lớn nhất. Để tìm ghép cặp trọng số lớn nhất, cần thêm một ràng buộc vào vertex labeling: với mọi đỉnh đã ghép cặp $u$, $z_u>0$.

Ban đầu đặt mọi $z_u=max(\{w(e):e\in E\})/2$.

Các đỉnh có vertex labeling bằng $0$ cuối cùng sẽ trở thành đỉnh chưa ghép cặp.

### Code tham khảo

Ở đây, để tiện cài đặt, ta nhân trọng số cạnh với $2$ khi tính giá trị $z_e$, nhờ vậy sẽ không có sai số số thực.

???+ note "Lưu trữ"
    ```cpp
    constexpr int INF = INT_MAX;
    constexpr int MAXN = 400;
    
    struct edge {
      int u, v, w;
    
      // Bieu thi (u,v) la mot canh co trong so w
      edge() {}
    
      edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };
    
    int n, n_x;
    // Co n dinh, danh so tu 1 den n
    // n_x bieu thi tong so dinh hien tai cong voi so hoa,
    // cac dinh hoa duoc danh so tu n+1 den n_x
    edge g[MAXN * 2 + 1][MAXN * 2 + 1];
    // Do thi duoc luu bang ma tran ke, vi toi da co n-1 hoa nen kich thuoc la MAXN*2
    vector<int> flower[MAXN * 2 + 1];
    // flower[b] ghi lai nhung dinh nao nam trong hoa b
    // Cach ghi cac dinh trong hoa chi ghi cac hoa ngoai cung nam trong hoa do
    ```

Dưới đây là ví dụ về hoa lồng nhau.

![general-weight-match-2](images/general-weight-match-2.png)

Trong đó $\{ 6, 5, 8\} \in b1,\{ b1, 4, 3, 2, 11, 10, 9\} \in b2$. Lưu trữ thành:

```text
flower[b2] = {b1, 4, 3, 2, 11, 10, 9} 
flower[b1] = {6, 5, 8}
```

![general-weight-match-3](images/general-weight-match-3.png)

```text
flower[b2] = {9, b1, 4, 3, 2, 11, 10} 
flower[b1] = {5, 8, 6}
```

```cpp
int lab[MAXN * 2 + 1];
// lab[u] dung de ghi z_u, lab[b] dung de ghi z_B
int match[MAXN * 2 + 1], slack[MAXN * 2 + 1], st[MAXN * 2 + 1],
    pa[MAXN * 2 + 1];
// match[x]=y bieu thi (x,y) la cap ghep, o day x va y co the la hoa
// slack[x]=u bieu thi z(x,u) la nho nhat trong cac canh ke voi x
// st[x]=b bieu thi hoa chua nut x la b. Neu x=b va b<=n thi x
// la mot nut thong thuong khong thuoc bat ky hoa nao.
// pa[v]=u bieu thi trong cay luan phien, nut cha cua v la u
int flower_from[MAXN * 2 + 1][MAXN + 1], S[MAXN * 2 + 1], vis[MAXN * 2 + 1];
/*
flower_from[b][x]=xs bieu thi hoa con lon nhat cua b co chua x la xs
x la mot dinh trong b, xs la mot hoa hoac mot dinh trong b,
dong thoi x=xs hoac x la mot trong cac dinh cua xs
*/
// S[u]={-1: chua tham, 0: dinh chan, 1: dinh le}
// vis chi duoc dung khi tim lca de kiem tra da di qua hay chua
queue<int> q;
// queue dung cho BFS tim duong tang cuong
```

![general-weight-match-4](images/general-weight-match-4.png)

```text
flower_from[b2][6] = b1 
flower_from[b2][5] = b1 
flower_from[b2][9] = 9 
flower_from[b1][6] = 6 
Va cu the tiep
```

```cpp
int e_delta(const edge &e) {
  // Tinh ze. De tien loi, truoc do nhan trong so moi canh voi hai
  // Tinh truc tiep gia tri e_delta ben trong hoa se gay loi
  return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2;
}

void update_slack(int u, int x) {
  // Dung u de cap nhat gia tri slack[x]
  if (!slack[x] || e_delta(g[u][x]) < e_delta(g[slack[x]][x])) {
    slack[x] = u;
  }
}

void set_slack(int x) {
  // Tinh gia tri slack[x], slack[x]=0 bieu thi x la nut trong cay luan phien
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
  // Dua x vao queue, ta quy dinh queue khong the push truc tiep mot hoa
  if (x <= n)
    q.push(x);
  else {
    // Neu muon push mot hoa thi phai them tat ca dinh cua do thi goc trong hoa vao queue
    for (size_t i = 0; i < flower[x].size(); i++) {
      q_push(flower[x][i]);
    }
  }
}

void set_st(int x, int b) {
  // Dat hoa chua x thanh b
  st[x] = b;
  if (x > n) {
    // Neu x cung la hoa, phai dat hoa chua cac dinh ben trong x thanh b
    for (size_t i = 0; i < flower[x].size(); ++i) {
      set_st(flower[x][i], b);
    }
  }
}
```

```cpp
int get_pr(int b, int xr) {
  // xr la mot dinh trong flower[b], gia tri tra ve pr la vi tri cua no
  // De chuong trinh chay thuan tien, ta de flower[b][0]~flower[b][pr] la duong luan phien trong hoa
  int pr = find(flower[b].begin(), flower[b].end(), xr) - flower[b].begin();
  if (pr % 2 == 1) {
    // Kiem tra vi tri cua no trong hoa. Neu flower[b][0]~flower[b][pr] khong phai duong luan phien
    // thi dao nguoc ca hoa va tinh lai pr
    // De flower[b][0]~flower[b][pr] thanh duong luan phien trong hoa
    reverse(flower[b].begin() + 1, flower[b].end());
    return (int)flower[b].size() - pr;
  } else
    return pr;
}
```

![general-weight-match-5](images/general-weight-match-5.png)

Nếu dùng `get_pr(b2,11)`, `flower[b2]` sẽ trở thành `{9,10,11,2,3,4,b1}` và trả về 2.

Nếu dùng `get_pr(b2,2)`, `flower[b2]` sẽ trở thành `{9,b1,4,3,2,11,10}` và trả về 4.

```cpp
void set_match(int u, int v) {
  // Dat u va v thanh canh ghep cap, u va v co the la hoa
  match[u] = g[u][v].v;
  if (u > n) {
    // Neu u la hoa
    edge e = g[u][v];
    int xr = flower_from[u][e.u];  // Tim e.u nam tren hoa nao trong flower[u]
    int pr = get_pr(u, xr);  // Tim vi tri cua xr va de 0~pr la duong luan phien trong hoa
    for (int i = 0; i < pr; ++i) {  // Dao cac canh ghep va khong ghep tren duong luan phien trong hoa
      set_match(flower[u][i], flower[u][i ^ 1]);
    }
    set_match(xr, v);  // Dat (xr,v) thanh canh ghep cap
    rotate(flower[u].begin(), flower[u].begin() + pr, flower[u].end());
    // Cuoi cung dat pr thanh de hoa, vi cach luu hoa la flower[u][0] se la de hoa cua u
    // Nen can rotate flower[u][pr] ve dau
  }
}

void augment(int u, int v) {
  // Tang cuong toan bo u va cac to tien cua u, dong thoi dat (u,v) thanh canh ghep cap
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
  // Tim lca cua u, v tren cay luan phien
  static int t = 0;
  for (++t; u || v; swap(u, v)) {
    if (u == 0) continue;
    if (vis[u] == t) return u;
    vis[u] = t;  // Cach nay giup khong can xoa mang vis
    u = st[match[u]];
    if (u) u = st[pa[u]];
  }
  return 0;
}
```

???+ note "Thêm một hoa lẻ"
    ```cpp
    void add_blossom(int u, int lca, int v) {
      // Co hoa tao boi u, v, lca thanh mot dinh b
      // lca cua u, v tren cay luan phien chinh la de hoa
      int b = n + 1;
      while (b <= n_x && st[b]) ++b;
      if (b > n_x) ++n_x;
      // Tim chi so hoa hien chua duoc dung
      lab[b] = 0;             // Dat zB=0
      S[b] = 0;               // Ca hoa la mot dinh chan
      match[b] = match[lca];  // Dat canh ghep cua hoa thanh canh ghep cua de hoa
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
      // Dua tat ca dinh trong b vao flower[b] theo dang vong, va dat de hoa lam phan tu dau tien
      set_st(b, b);  // Dat hoa chua moi phan tu trong ca hoa thanh b
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
          // Dat canh ke giua b va x thanh canh trong b ke voi x co e_delta nho nhat
          if (g[b][x].w == 0 || e_delta(g[xs][x]) < e_delta(g[b][x])) {
            g[b][x] = g[xs][x];
            g[x][b] = g[x][xs];
          }
        }
        for (int x = 1; x <= n; ++x) {
          if (flower_from[xs][x]) {
            // Neu dinh xs ben trong b co chua x
            // Thi flower_from[b][x] se la xs
            flower_from[b][x] = xs;
          }
        }
      }
      set_slack(b);
      // Cuoi cung phai dat gia tri slack cua b
    }
    ```

???+ note "Bung hoa"
    ```cpp
    void expand_blossom(int b) {
      // Khi b la hoa le va zB=0, phai bung b ra
      // Vi chi bung b, nen neu ben trong b co chua cac hoa khac
      // thi khong can bung chung ra
      for (size_t i = 0; i < flower[b].size(); ++i) {
        set_st(flower[b][i], flower[b][i]);
        // Truoc tien dat hoa chua moi phan tu trong flower[b] thanh chinh no
      }
      int xr = flower_from[b][g[b][pa[b]].u];
      // xr bieu thi nut cha cua b tren duong luan phien nam tren hoa nao trong flower[b]
      int pr = get_pr(b, xr);  // Tim vi tri cua xr va de 0~pr la duong luan phien trong hoa
      for (int i = 0; i < pr; i += 2) {
        // Bung duong luan phien vao trong cay luan phien
        // Va dua cac dinh chan trong duong luan phien vao queue
        int xs = flower[b][i];
        int xns = flower[b][i + 1];
        pa[xs] = g[xns][xs].u;
        S[xs] = 1;
        S[xns] = 0;
        slack[xs] = 0;
        set_slack(xns);
        q_push(xns);
      }
      S[xr] = 1;  // Luc nay xr se la dinh le hoac hoa le
      pa[xr] = pa[b];
      for (size_t i = pr + 1; i < flower[b].size(); ++i) {
        // Dat moi dinh trong hoa khong nam tren duong luan phien thanh chua tham
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
      // Tim thay mot canh dang thuc e trong BFS
      // Can xu ly no theo cac buoc sau
      // O day u nhat dinh la dinh chan
      int u = st[e.u], v = st[e.v];
      if (S[v] == -1) {
        // v la nut chua tham
        pa[v] = e.u;
        S[v] = 1;
        int nu = st[match[v]];
        slack[v] = 0;
        slack[nu] = 0;
        S[nu] = 0;
        q_push(nu);
      } else if (S[v] == 0) {
        // v la dinh chan
        int lca = get_lca(u, v);
        if (!lca) {  // lca=0 bieu thi u, v o hai cay luan phien khac nhau, co duong tang cuong
          augment(u, v);
          augment(v, u);
          return true;  // Tim thay duong tang cuong
        } else
          add_blossom(u, lca, v);
        // Nguoc lai, u va v o cung mot cay thi se tao thanh mot hoa, can co hoa
      }
      return false;
    }
    ```

???+ note "Tăng cường"
    ```cpp
    bool matching() {
      memset(S + 1, -1, sizeof(int) * n_x);
      memset(slack + 1, 0, sizeof(int) * n_x);
      q = queue<int>();  // Xoa rong queue
      for (int x = 1; x <= n_x; ++x) {
        if (st[x] == x && !match[x]) {
          // Dua tat ca dinh chua ghep cap vao queue va dat thanh dinh chan
          pa[x] = 0;
          S[x] = 0;
          q_push(x);
        }
      }
      if (q.empty()) return false;  // Tat ca dinh deu da duoc ghep cap
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
        // Sua gia tri lab
        int d = INF;
        for (int u = 1; u <= n; ++u) {
          // De tranh xay ra truong hop lab<0
          // Chi can co bat ky lab[u]=0 nao thi ket thuc chuong trinh
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
            // Neu lab[u]=0 thi ket thuc truc tiep chuong trinh
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
        q = queue<int>();  // Xoa rong queue
        for (int x = 1; x <= n_x; ++x) {
          // Kiem tra xem co sinh ra duong tang cuong hay khong
          if (st[x] == x && slack[x] && st[slack[x]] != x &&
              e_delta(g[slack[x]][x]) == 0)
            if (on_found_edge(g[slack[x]][x])) return true;
        }
        for (int b = n + 1; b <= n_x; ++b) {
          // Thao tac EXPAND, bung moi hoa le co lab[b]=0
          if (st[b] == b && S[b] == 1 && lab[b] == 0) expand_blossom(b);
        }
      }
      return false;
    }
    ```

???+ note "Hàm chính"
    ```cpp
    pair<long long, int> weight_blossom() {
      // Ham chinh, ban dau khoi tao truoc
      memset(match + 1, 0, sizeof(int) * n);
      n_x = n;  // Ban dau chua co hoa
      int n_matches = 0;
      long long tot_weight = 0;
      for (int u = 0; u <= n; ++u) {
        // Truoc tien dat hoa chua chinh no thanh chinh no
        st[u] = u;
        flower[u].clear();
      }
      int w_max = 0;
      for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v) {
          // Khi u la mot dinh, cac dinh ma no chua chi co chinh no
          flower_from[u][v] = (u == v ? u : 0);
          w_max = max(w_max, g[u][v].w);
          // Tim trong so canh lon nhat
        }
      for (int u = 1; u <= n; ++u) lab[u] = w_max;
      // Dat moi lab bang trong so canh lon nhat
      // Vi phan cai dat nay dung trong so canh nhan hai de tinh ze, nen khong can chia hai
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
      // Phai khoi tao truoc khi nhap canh vao do thi
      // Vi day la ghep cap trong so lon nhat, dat canh khong ton tai bang 0
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
