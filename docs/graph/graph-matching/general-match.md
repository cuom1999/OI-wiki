author: H-J-Granger, accelsao, Ir1d, Early0v0, Henry-ZHR, HeliumOI, AntiLeaf, ShizuhaAki, pukui

## Thuật toán blossom (Blossom Algorithm)

Thuật toán blossom (Blossom Algorithm, còn được gọi là cây hoa) có thể giải bài toán ghép cặp lớn nhất trong đồ thị tổng quát (maximum cardinality matchings). Thuật toán này được Jack Edmonds đề xuất vào năm 1961.
Sau một số sửa đổi, nó cũng có thể giải bài toán ghép cặp trọng số lớn nhất trong đồ thị tổng quát.
Đây là thuật toán đầu tiên đưa ra chứng minh rằng bài toán ghép cặp lớn nhất có độ phức tạp đa thức.

Điểm khác biệt giữa ghép cặp trong đồ thị tổng quát và ghép cặp trong đồ thị hai phía (bipartite matching) là đồ thị có thể chứa chu trình lẻ.

![general-matching-1](./images/general-matching-1.png)

Lấy đồ thị này làm ví dụ. Nếu trực tiếp đảo trạng thái các cạnh (đổi cạnh ghép cặp và cạnh chưa ghép cặp cho nhau), thì $M$ sau khi đảo sẽ không hợp lệ: một số đỉnh sẽ xuất hiện trong hai cạnh ghép cặp. Vấn đề nằm ở chu trình lẻ.

Sau đây xét thuật toán tìm đường tăng cho đồ thị tổng quát.
Nhìn từ góc độ đồ thị hai phía, mỗi lần ta liệt kê một đỉnh chưa được ghép cặp, đặt đỉnh xuất phát làm gốc và đánh dấu là **"o"**, sau đó đánh dấu xen kẽ **"o"** và **"i"**. Không khó để nhận thấy đoạn cạnh từ **"i"** đến **"o"** là cạnh ghép cặp.

Giả sử đỉnh hiện tại là $v$, đỉnh kề là $u$, có thể chia thành hai trường hợp sau:

1.  $u$ chưa được thăm. Nếu $u$ là đỉnh chưa ghép cặp thì tìm được đường tăng; ngược lại tiếp tục tìm đường tăng từ đỉnh đang ghép với $u$.
2.  $u$ đã được thăm. Nếu gặp nhãn "o" thì cần **co hoa**; nếu không thì đang gặp chu trình chẵn, bỏ qua.

Trường hợp gặp chu trình chẵn có thể xem như xử lý trong đồ thị hai phía, nên có thể bỏ qua. Sau khi **co hoa**, tiếp tục tìm đường tăng trong đồ thị mới.

![general-matching-2](./images/general-matching-2.png)

Gọi đồ thị ban đầu là $G$, đồ thị sau khi **co hoa** là $G'$. Ta chỉ cần chứng minh:

1.  Nếu $G$ tồn tại đường tăng, thì $G'$ cũng tồn tại.
2.  Nếu $G'$ tồn tại đường tăng, thì $G$ cũng tồn tại.

![general-matching-3](./images/general-matching-3.png)

Gọi cạnh không thuộc cây (cạnh tạo thành chu trình) là $(u,v)$, định nghĩa gốc hoa $h=LCA(u,v)$.
Chu trình lẻ là chu trình xen kẽ, và chỉ có hai cạnh kề với $h$ có cùng loại, đều là cạnh không ghép cặp.
Khi đó cạnh cây đi vào $h$ chắc chắn là cạnh ghép cặp; ngoài $h$, mọi cạnh từ các đỉnh khác trên chu trình đi ra ngoài chu trình đều là cạnh không ghép cặp.

Quan sát cho thấy khi đi ra bằng một cạnh ngoài chu trình, có hai khả năng: theo chiều kim đồng hồ hoặc ngược chiều kim đồng hồ.

![general-matching-4](./images/general-matching-4.png)

Vì vậy, **co hoa** hay **không co hoa** đều không ảnh hưởng đến tính đúng đắn.

Khi hiện thực, sau khi tìm được **hoa**, ta không cần thật sự **co hoa**; có thể dùng mảng để ghi lại mỗi đỉnh đang nằm trong bông hoa có gốc là đỉnh nào.

### Phân tích độ phức tạp

Mỗi lần tìm đường tăng, ta duyệt qua tất cả các cạnh; khi gặp **hoa** thì cần duy trì các đỉnh trên **hoa**, độ phức tạp là $O(|E|^2)$.

Liệt kê tất cả các đỉnh chưa ghép cặp để tìm đường tăng, tổng cộng là $O(|V||E|^2)$.

### Mã tham khảo

??? note "Mã tham khảo"
    ```cpp
    // graph
    template <typename T>
    class graph {
     public:
      struct edge {
        int from;
        int to;
        T cost;
      };
    
      vector<edge> edges;
      vector<vector<int>> g;
      int n;
    
      graph(int _n) : n(_n) { g.resize(n); }
    
      virtual int add(int from, int to, T cost) = 0;
    };
    
    // undirectedgraph
    template <typename T>
    class undirectedgraph : public graph<T> {
     public:
      using graph<T>::edges;
      using graph<T>::g;
      using graph<T>::n;
    
      undirectedgraph(int _n) : graph<T>(_n) {}
    
      int add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
      }
    };
    
    // blossom / find_max_unweighted_matching
    template <typename T>
    vector<int> find_max_unweighted_matching(const undirectedgraph<T> &g) {
      std::mt19937 rng(std::random_device{}());
      vector<int> match(g.n, -1);   // ghep cap
      vector<int> aux(g.n, -1);     // dau thoi gian
      vector<int> label(g.n);       // "o" hoac "i"
      vector<int> orig(g.n);        // goc hoa
      vector<int> parent(g.n, -1);  // nut cha
      queue<int> q;
      int aux_time = -1;
    
      auto lca = [&](int v, int u) {
        aux_time++;
        while (true) {
          if (v != -1) {
            if (aux[v] == aux_time) {  // tìm thấy đỉnh đã thăm, tức LCA
              return v;
            }
            aux[v] = aux_time;
            if (match[v] == -1) {
              v = -1;
            } else {
              v = orig[parent[match[v]]];  // tiep tuc tim tu nut cha cua dinh ghep cap
            }
          }
          swap(v, u);
        }
      };  // lca
    
      auto blossom = [&](int v, int u, int a) {
        while (orig[v] != a) {
          parent[v] = u;
          u = match[v];
          if (label[u] == 1) {  // đặt điểm ban đầu là "o" để tìm đường tăng
            label[u] = 0;
            q.push(u);
          }
          orig[v] = orig[u] = a;  // co hoa
          v = parent[u];
        }
      };  // blossom
    
      auto augment = [&](int v) {
        while (v != -1) {
          int pv = parent[v];
          int next_v = match[pv];
          match[v] = pv;
          match[pv] = v;
          v = next_v;
        }
      };  // augment
    
      auto bfs = [&](int root) {
        fill(label.begin(), label.end(), -1);
        iota(orig.begin(), orig.end(), 0);
        while (!q.empty()) {
          q.pop();
        }
        q.push(root);
        // Dat diem ban dau la "o"; o day dung "0" thay cho "o", "1" thay cho "i"
        label[root] = 0;
        while (!q.empty()) {
          int v = q.front();
          q.pop();
          for (int id : g.g[v]) {
            auto &e = g.edges[id];
            int u = e.from ^ e.to ^ v;
            if (label[u] == -1) {  // tìm thấy đỉnh chưa thăm
              label[u] = 1;        // đánh dấu "i"
              parent[u] = v;
              if (match[u] == -1) {  // tìm thấy đỉnh chưa ghép cặp
                augment(u);          // tìm đường tăng
                return true;
              }
              // Tìm thấy đỉnh đã ghép cặp; đưa đỉnh ghép với nó vào queue để mở rộng cây xen kẽ
              label[match[u]] = 0;
              q.push(match[u]);
              continue;
            } else if (label[u] == 0 && orig[v] != orig[u]) {
              // Tìm thấy đỉnh đã thăm và cùng có nhãn "o", nghĩa là tìm thấy "hoa"
              int a = lca(orig[v], orig[u]);
              // Tìm LCA rồi co hoa
              blossom(u, v, a);
              blossom(v, u, a);
            }
          }
        }
        return false;
      };  // bfs
    
      auto greedy = [&]() {
        vector<int> order(g.n);
        // Xao tron ngau nhien order
        iota(order.begin(), order.end(), 0);
        shuffle(order.begin(), order.end(), rng);
    
        // Ghep cac dinh co the ghep cap
        for (int i : order) {
          if (match[i] == -1) {
            for (auto id : g.g[i]) {
              auto &e = g.edges[id];
              int to = e.from ^ e.to ^ i;
              if (match[to] == -1) {
                match[i] = to;
                match[to] = i;
                break;
              }
            }
          }
        }
      };  // greedy
    
      // Ban đầu ghép cặp ngẫu nhiên
      greedy();
      // Tìm đường tăng từ các đỉnh chưa ghép cặp
      for (int i = 0; i < g.n; i++) {
        if (match[i] == -1) {
          bfs(i);
        }
      }
      return match;
    }
    ```

??? note "[UOJ #79. Ghép cặp lớn nhất trong đồ thị tổng quát](https://uoj.ac/problem/79)"
    ```cpp
    --8<-- "docs/graph/code/graph-matching/general-match/general-match_1.cpp"
    ```

## Thuật toán ghép cặp trong đồ thị tổng quát dựa trên khử Gauss

???+ tip "Gợi ý"
    Trước khi đọc phần sau, có thể bạn cần đọc trước nội dung về ma trận trong phần "Đại số tuyến tính":
    
    -   [Ma trận](../../math/linear-algebra/matrix.md)
    -   [Định thức](../../math/linear-algebra/determinant.md)
    -   [Khử Gauss](../../math/numerical/gauss.md)

Phần này giới thiệu một thuật toán ghép cặp trong đồ thị tổng quát dựa trên khử Gauss. So với thuật toán cây hoa truyền thống, ưu điểm của nó là dễ hiểu và dễ viết hơn, đồng thời thuận tiện để giải các bài toán như "đỉnh bắt buộc trong ghép cặp lớn nhất"; nhược điểm là hằng số khá lớn, vì phần $O(n^3)$ của khử Gauss về cơ bản chạy đủ, còn cây hoa thường không chạy hết như vậy.

### Kiến thức chuẩn bị: Ma trận Tutte

**Định nghĩa**: Với một đồ thị vô hướng $G = (V, E)$ có $n$ đỉnh, ma trận Tutte $\tilde{A}(G)$ của nó là một ma trận $n \times n$, trong đó:

$$
\tilde{A}(G)_{i,j} = \begin{cases}
x_{i,j}, & i<j,\; (v_i, v_j)\in E \\
-x_{i,j}, & i > j,\; (v_i, v_j) \in E \\
0, & \text{otherwise}
\end{cases}
$$

Trong đó $x_{i, j}$ là một biến, nên trong $\tilde{A}(G)$ có tổng cộng $|E|$ biến.

Khi không gây nhầm lẫn, bên dưới viết tắt $\tilde{A}(G)$ thành $\tilde{A}$.

**Định lý** (định lý Tutte): $G$ tồn tại ghép cặp hoàn hảo khi và chỉ khi $\det \tilde{A} \ne 0$.

??? note "Chứng minh"
    Ở đây đưa vào khái niệm "phủ chu trình chẵn": một phủ chu trình chẵn của đồ thị vô hướng $G$ là cách dùng một số chu trình chẵn (bao gồm cả chu trình hai cạnh) để phủ tất cả các đỉnh, không trùng và không sót.
    
    Dễ chứng minh rằng $G$ tồn tại ghép cặp hoàn hảo khi và chỉ khi $G$ tồn tại phủ chu trình chẵn.
    
    -   Nếu $G$ tồn tại phủ chu trình chẵn, ta chỉ cần lấy xen kẽ các cạnh trên mỗi chu trình để thu được một ghép cặp hoàn hảo.
    -   Nếu $G$ tồn tại ghép cặp hoàn hảo, ta chỉ cần lấy ra các chu trình hai cạnh tương ứng với các cạnh ghép cặp để thu được một phủ chu trình chẵn.
    
    Tiếp theo chứng minh $G$ tồn tại phủ chu trình chẵn khi và chỉ khi $\tilde{A} \ne 0$.
    
    Xét định nghĩa của định thức:
    
    $$
    \det A = \sum_{\pi} (-1)^{\pi} \prod_{i} A_{i, \pi_i}
    $$
    
    Trong đó $\pi$ là một hoán vị bất kỳ, $(-1)^{\pi}$ nghĩa là nếu số cặp nghịch thế trong $\pi$ là lẻ thì lấy $-1$, ngược lại lấy $1$.
    
    Không khó thấy rằng mỗi hoán vị đều có thể được xem là một phủ chu trình của $G$. Nếu trong phủ chu trình này có chu trình lẻ, thì tổng sau khi đảo chiều chu trình đó chắc chắn bằng $0$. Do đó chỉ phủ chu trình chẵn mới có thể làm định thức khác $0$, chứng minh hoàn tất.

**Định lý**: $\operatorname{rank}\tilde{A}$ luôn là số chẵn, và kích thước ghép cặp lớn nhất của $G$ bằng một nửa $\operatorname{rank}\tilde{A}$.

??? note "Chứng minh"
    Hạng của ma trận phản đối xứng chỉ có thể là số chẵn; phần sau xin để bạn đọc tự suy nghĩ.

Trong ứng dụng thực tế, không thể tính toán với $|E|$ biến. Tuy nhiên, ta có thể chọn một trường số, chẳng hạn trường thặng dư $\mathcal{Z}_p$ theo một số nguyên tố $p$, rồi thay ngẫu nhiên từng biến bằng một phần tử trong $\mathcal{Z}_p$ trước khi tính toán. Để tiện trình bày, khi không gây nhầm lẫn, bên dưới dùng $\tilde{A}$ để chỉ trực tiếp ma trận sau khi thay thế.

**Định lý**: $\operatorname{rank}\tilde{A}$ không vượt quá hai lần kích thước ghép cặp lớn nhất của $G$, và xác suất để hai đại lượng này bằng nhau ít nhất là $1 - \frac n p$.

Xét rằng trong bài toán ghép cặp lớn nhất trên đồ thị tổng quát, $n$ thường không vượt quá $10^3$, nên trên thực tế chọn $p$ là một số nguyên tố cỡ $10^9$ là đủ.

Từ định lý có thể thấy, nếu chỉ cần tìm số lượng cạnh trong ghép cặp lớn nhất mà không cần phương án ghép cặp, thì chỉ cần dùng một lần khử Gauss để tính $\operatorname{rank}\tilde{A}$, ngắn gọn hơn cây hoa rất nhiều. Tuy nhiên, nếu cần xuất phương án, bài toán sẽ phức tạp hơn một chút và cần dùng thuật toán được giới thiệu dưới đây.

### Xây dựng ghép cặp hoàn hảo

Từ định lý Tutte và định lý ở trên, nếu $G$ tồn tại ghép cặp hoàn hảo, thì $\tilde{A}$ có xác suất rất lớn là khả nghịch. Để tiện trình bày, trong phần sau đều lược bỏ cụm "với xác suất rất lớn".

Ký hiệu đỉnh có nhãn $i$ trong $G$ là $v_i$. Hơn nữa, ta có định lý sau:

**Định lý**: $\tilde{A}^{-1}_{j,i} \ne 0 \iff G - \{v_i, v_j\}$ có ghép cặp hoàn hảo.

???+ tip "Ma trận nghịch đảo và ma trận phụ hợp"
    Với ma trận vuông cấp $n$ bất kỳ $A$, định nghĩa ma trận phụ hợp của nó là $A^*_{i, j} = (-1)^{i + j} M_{j, i}$, trong đó $M_{j, i}$ là định thức con thu được sau khi xóa hàng thứ $j$ và cột thứ $i$. Nói cách khác, nếu ma trận các phần bù đại số của $A$ là $M$, thì $A^* = M^T$.
    
    **Định lý**: Nếu $A$ khả nghịch, thì $A^{-1} = \frac 1 {\det A} A^*$.
    
    Vì vậy ở đây $A^{-1}_{j, i} \ne 0 \iff M_{i, j} \ne 0$, tức là phần ma trận sau khi xóa hàng thứ $i$ và cột thứ $j$ của $A$ có hạng đầy đủ.

Nói cách khác, nếu $(v_i, v_j) \in E$ và $\tilde{A}^{-1}_{j, i} \ne 0$, thì tồn tại một phương án ghép cặp hoàn hảo chứa cạnh $(v_i, v_j)$. Bên dưới gọi những cạnh như vậy là **cạnh khả thi**.

Từ định lý trên, với một đồ thị vô hướng $G$ có ghép cặp hoàn hảo, ta có thể đưa ra một thuật toán vét cạn khá hiển nhiên để tìm một ghép cặp hoàn hảo: mỗi lần liệt kê $i, j$; nếu $(v_i, v_j)$ là một cạnh khả thi (có cạnh nối và $\tilde{A}^{-1}_{j, i} \ne 0$), thì thêm $(v_i, v_j)$ vào phương án ghép cặp, xóa cả hai đỉnh này khỏi $G$, rồi tính lại $\tilde{A}^{-1}$ mới.

Cần thực hiện tổng cộng $\frac n 2$ vòng, mỗi vòng đều là $O(n^3)$, nên tổng độ phức tạp là $O(n ^ 4)$, hơi chậm. Thực ra khi tính lại $\tilde{A}^{-1}$, ta không cần mỗi lần đều dùng khử Gauss để tính lại ma trận nghịch đảo từ đầu, mà có thể sử dụng định lý sau:

**Định lý** (định lý khử): Gọi

$$
A = \begin{bmatrix}
  a_{1, 1} & v^T \\
  u & B
\end{bmatrix} \quad A^{-1} = \begin{bmatrix}
  \hat a^{1, 1} & \hat v^T \\
  \hat u & \hat B
\end{bmatrix}
$$

và $\hat a_{1, 1} \ne 0$, khi đó có:

$$
B^{-1} = \hat B - \frac {\hat u \hat v^T} {\hat a_{1, 1}}
$$

Định lý mô tả trường hợp khử hàng đầu tiên và cột đầu tiên. Trên thực tế, nó có thể được mở rộng một cách rất rõ ràng sang trường hợp khử một hàng và một cột bất kỳ. Do đó ta chỉ cần tính $\tilde{A}^{-1}$ một lần ở đầu thuật toán; về sau mỗi lần xóa hai đỉnh, chỉ cần thực hiện hai lần quá trình khử $O(n^2)$.

??? note "Mô tả hơi trừu tượng, có thể tham khảo mã C++"
    ```cpp
    void eliminate(int A[][MAXN], int r, int c) {  // khu hang r cot c
      row_marked[r] = col_marked[c] = true;        // da bi khu
    
      int inv = quick_power(A[r][c], p - 2);  // nghich dao modulo
    
      for (int i = 1; i <= n; i++)
        if (!row_marked[i] && A[i][c]) {
          int tmp = (long long)A[i][c] * inv % p;
    
          for (int j = 1; j <= n; j++)
            if (!col_marked[j] && A[r][j])
              A[i][j] = (A[i][j] - (long long)tmp * A[r][j]) % p;
        }
    }
    ```

Cần thực hiện tổng cộng $\frac n 2$ vòng, mỗi vòng có độ phức tạp $O(n^2)$, nên thuật toán trên có thể tìm một ghép cặp hoàn hảo trong thời gian $O(n^3)$.

### Xây dựng ghép cặp lớn nhất

Ta vừa giải quyết bài toán xây dựng một ghép cặp hoàn hảo, nhưng khi giải bài thường cần ghép cặp lớn nhất.

Phần trước đã nhắc rằng kích thước ghép cặp lớn nhất của $G$ bằng một nửa $\operatorname{rank}\tilde{A}$. Nếu ta tìm được một ma trận con vuông hạng đầy đủ lớn nhất của $\tilde{A}$, thì chỉ cần tìm một ghép cặp hoàn hảo trên đồ thị con cảm sinh tương ứng với ma trận con đó là có thể tìm được một ghép cặp lớn nhất của $G$.

Xét theo góc nhìn khác, nếu $G$ có ghép cặp hoàn hảo, thì $\tilde{A}$ có hạng đầy đủ, nói cách khác, các hàng/cột của $\tilde{A}$ độc lập tuyến tính. Vậy nếu $\tilde{A}$ không có hạng đầy đủ, ta có thể tìm một cơ sở tuyến tính của $\tilde{A}$, rồi chỉ giữ lại các hàng và cột tương ứng với cơ sở tuyến tính đó để thu được một ma trận con vuông hạng đầy đủ lớn nhất của $\tilde{A}$.

Sau khi tìm được ma trận con vuông hạng đầy đủ lớn nhất, dùng thuật toán ở trên để tìm một ghép cặp hoàn hảo của đồ thị con cảm sinh, từ đó thu được một ghép cặp lớn nhất của đồ thị ban đầu. Lưu ý rằng trong khử Gauss có thể xảy ra hoán đổi hàng, nên khi hiện thực cần duy trì cẩn thận chỉ số của các đỉnh.

??? note "[UOJ #79. Ghép cặp lớn nhất trong đồ thị tổng quát](https://uoj.ac/problem/79)"
    ```cpp
    --8<-- "docs/graph/code/graph-matching/general-match/general-match_2.cpp"
    ```

## Bài tập

-   [UOJ #79. Ghép cặp lớn nhất trong đồ thị tổng quát](https://uoj.ac/problem/79)
-   [UOJ #171. [WC2016] Thử thách NPC](https://uoj.ac/problem/171)

## Tài liệu tham khảo

1.  Mucha M, Sankowski P. [Maximum matchings via Gaussian elimination](http://web.eecs.umich.edu/~pettie/matching/Mucha-Sankowski-maximum-matching-matrix-multiplication.pdf)
2.  Zhou Zixin, Yang Jiaqi, "Ghép cặp trong đồ thị tổng quát dựa trên đại số tuyến tính"
3.  ZYQN, ["Thuật toán ghép cặp trong đồ thị tổng quát dựa trên đại số tuyến tính"](https://oi.cyo.ng/wp-content/uploads/2017/02/maximum_matchings_via_gaussian_elimination.pdf)
