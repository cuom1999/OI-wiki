author: Backl1ght

Euler Tour Tree (cây Euler Tour, sau đây viết tắt là ETT) là một cấu trúc dữ liệu dùng để giải bài toán **cây động**.
ETT chuyển các thao tác trên cây động thành thao tác đoạn trên dãy DFS tương ứng, rồi dùng cấu trúc dữ liệu khác để duy
trì các thao tác đoạn đó. Chẳng hạn, thao tác thêm cạnh trên cây động được chuyển thành một số thao tác tách dãy và gộp
dãy; nếu duy trì được hai thao tác này thì cũng có thể duy trì thao tác thêm cạnh.

LCT cũng là một cấu trúc dữ liệu cho bài toán cây động, và phổ biến hơn ETT. Tuy nhiên, LCT phù hợp hơn để duy trì thông
tin trên đường đi của cây, còn ETT phù hợp hơn để duy trì thông tin của **cây con**. Ví dụ, ETT có thể duy trì giá trị
nhỏ nhất trong cây con, còn LCT thì không.

ETT có thể được duy trì bằng bất kỳ cấu trúc dữ liệu nào, miễn là cấu trúc đó hỗ trợ các thao tác đoạn tương ứng trên dãy
và đạt yêu cầu về độ phức tạp. Thông thường, các cây tìm kiếm nhị phân cân bằng như Splay hoặc Treap được dùng để duy
trì dãy. Các cấu trúc này đều duy trì thao tác đoạn với độ phức tạp $O(\log n)$, nhờ đó cũng có thể duy trì thao tác trên
cây động trong thời gian $O(\log n)$. Nếu dùng cây tìm kiếm cân bằng nhiều nhánh, chẳng hạn B-tree, để duy trì thao tác
đoạn thì cũng có thể đạt độ phức tạp tốt hơn.

Có thể hiểu ETT như một tư tưởng: duy trì một dãy tương ứng một-một với cây ban đầu, từ đó duy trì cây ban đầu. Bài viết
này chỉ giới thiệu một vài cách cài đặt và ứng dụng khả thi của tư tưởng đó.

## Biểu diễn chu trình Euler của cây

Nếu xem mỗi cạnh của cây là hai cạnh có hướng, có thể biểu diễn một cây thành một chu trình Euler trong đồ thị có hướng.
Biểu diễn này được gọi là biểu diễn chu trình Euler của cây (Euler tour representation, ETR).

Dãy cần duy trì ở phần sau thực ra là một biến thể của ETR: xem các đỉnh trong cây như các khuyên tự nối và cũng đưa
chúng vào ETR. Tuy nhiên, vì tác giả trong bài báo gốc không đặt tên mới cho biến thể này, bài viết vẫn gọi nó là ETR.

Có thể thu được biểu diễn chu trình Euler của cây $T$ bằng thuật toán sau:

$$
\begin{array}{ll}
1 & \textbf{Đầu vào. } \text{Một cây có gốc }T\\
2 & \textbf{Đầu ra. } \text{Thứ tự DFS của cây có gốc }T\\
3 & \operatorname{ET}(u)\\
4 & \qquad \text{thăm đỉnh }u\\
5 & \qquad \text{với mọi con } v \text{ của } u\\
6 & \qquad \qquad \text{thăm cạnh có hướng } u \to v\\
7 & \qquad \qquad \operatorname{ET}(v)\\
8 & \qquad \qquad \text{thăm cạnh có hướng } v \to u\\
\end{array}
$$

Biểu diễn chu trình Euler $\operatorname{ETR}(T)$ của cây $T$ ban đầu rỗng. Trong quá trình DFS, mỗi khi thăm một đỉnh
hoặc một cạnh có hướng, thêm nó vào cuối $\operatorname{ETR}(T)$; làm như vậy sẽ thu được $\operatorname{ETR}(T)$.

Nếu $T$ có $n$ đỉnh thì nó chứa $2n - 2$ cạnh có hướng. Trong quá trình DFS, mỗi đỉnh và mỗi cạnh có hướng đều được thăm
đúng một lần, nên độ dài của $\operatorname{ETR}(T)$ là $3n - 2$.

Xem đỉnh $u$ là một khuyên tự nối, khi đó $\operatorname{ETR}(T)$ có thể được xem như một chu trình Euler trong đồ thị có
hướng. Có thể cắt chu trình Euler tại một vị trí nào đó và xem nó như một chuỗi gồm các cạnh nối đầu-cuối; cũng có thể
dán chuỗi đó lại tại chỗ cắt để trở về chu trình Euler. Ngoài ra, có thể thêm một vài cạnh mới để ghép hai chuỗi như vậy
thành một chu trình Euler mới.

Trong phần sau, nếu không nói rõ, dãy được duy trì mặc định là biểu diễn chu trình Euler của cây.

## Các thao tác cơ bản của ETT

Ba thao tác sau được xem là các thao tác cơ bản của ETT. Chúng đều có thể chuyển thành một số hằng thao tác trên dãy, vì
vậy độ phức tạp của ba thao tác này cùng bậc với thao tác trên dãy.

Cách trình bày dưới đây chỉ là một cài đặt khả thi; chỉ cần dùng được một số hằng thao tác trên dãy để ghép ra dãy tương
ứng sau khi sửa đổi là được.

### MakeRoot(u)

Đây là thao tác đổi gốc. Trong ETT, thao tác đổi gốc được chuyển thành $1$ thao tác tách dãy và $1$ thao tác gộp dãy;
cũng có thể hiểu là $1$ thao tác tịnh tiến đoạn.

Gọi cây chứa đỉnh $u$ là $T$, gốc hiện tại của nó là $r$, và cần đổi gốc thành $u$. Dãy tương ứng với cây $T$ là $L$.
Tách $L$ tại $(u, u)$ thành hai dãy $L^1$ và $L^2$. Dãy trước chứa các phần tử đứng trước $(u, u)$ trong $L$ cùng với
$(u, u)$, còn dãy sau chứa các phần tử còn lại. Khi đó, dãy thu được bằng cách lần lượt gộp $L^2$ và $L^1$ chính là dãy
tương ứng với cây sau khi đổi gốc.

Có thể hiểu thao tác này là xoay một chu trình Euler. Chu trình Euler là một vòng, nên xoay sẽ không thay đổi cấu trúc
của chu trình Euler, tức cũng không thay đổi cấu trúc của cây; nó chỉ xoay đỉnh $u$ đến vị trí gốc.

### Insert(u, v)

Đây là thao tác thêm cạnh. Trong ETT, thao tác thêm cạnh được chuyển thành $2$ thao tác tách dãy và $5$ thao tác gộp dãy.

Gọi cây chứa đỉnh $u$ là $T_1$, cây chứa đỉnh $v$ là $T_2$; sau khi thêm cạnh, hai cây sẽ gộp thành một cây $T$. Dãy tương
ứng với cây $T_1$ là $L_1$, và dãy tương ứng với cây $T_2$ là $L_2$.

Tách $L_1$ tại $(u, u)$ thành hai dãy $L_1^1$ và $L_1^2$. Dãy trước chứa các phần tử đứng trước $(u, u)$ trong $L_1$ cùng
với $(u, u)$, còn dãy sau chứa các phần tử còn lại. Tương tự, tách $L_2$ tại $(v, v)$ thành hai dãy $L_2^1$ và $L_2^2$.
Khi đó, lần lượt gộp $L_1^2, L_1^1, [(u, v)], L_2^2, L_2^1, [(v, u)]$ là thu được dãy $L$ tương ứng với cây $T$.

Có thể hiểu thao tác này là thực hiện hai lần đổi gốc, rồi cắt hai chu trình Euler tại vị trí gốc hiện tại. Sau đó dùng
hai cạnh có hướng mới thêm để ghép hai chu trình Euler thành một chu trình Euler mới.

### Delete(u, v)

Đây là thao tác xóa cạnh. Trong ETT, thao tác xóa cạnh được chuyển thành $4$ thao tác tách dãy và $1$ thao tác gộp dãy.

Gọi cây chứa cạnh $(u, v)$ và cạnh $(v, u)$ là $T$, dãy tương ứng của nó là $L$. Sau khi xóa cạnh, $T$ tách thành hai cây.

Tách $L$ thành $L_1, [(u, v)], L_2, [(v, u)], L_3$. Hai cây được tạo ra sau khi xóa cạnh có các dãy tương ứng lần lượt là
$L_2$ và dãy ghép từ $L_1, L_3$. Lưu ý rằng trong dãy $L$, $[(u, v)]$ có thể xuất hiện phía sau $[(v, u)]$; khi đó có thể
hoán đổi giá trị của $u$ và $v$ trước rồi mới thao tác.

Có thể hiểu thao tác này là cắt một chu trình Euler tại hai cạnh có hướng để tạo thành hai chuỗi. Sau đó mỗi chuỗi tự nối
đầu-cuối để tạo thành hai chu trình Euler mới.

## Cài đặt

Phần dưới lấy Treap không xoay làm ví dụ để giới thiệu cách cài đặt ETT. Người đọc cần biết trước các nội dung liên quan
đến việc dùng Treap không xoay để duy trì thao tác đoạn.

`Split` và `Merge` đều là các thao tác cơ bản của Treap không xoay, nên phần này không trình bày lại.

### SplitUp2(u)

Giả sử dãy chứa $u$ là $L$. Tách $L$ tại $u$ thành hai dãy $L^1$ và $L^2$. Dãy trước chứa các phần tử đứng trước $u$ trong
$L$ cùng với $u$, còn dãy sau chứa các phần tử còn lại.

Nếu mỗi nút của Treap duy trì thêm nút cha của chính nó, có thể tính vị trí trong dãy của phần tử tương ứng với một nút
Treap trong thời gian $O(\log n)$, rồi dựa vào vị trí đó để `Split` và thực hiện chức năng trên.

Cũng có thể tách từ dưới lên để thực hiện chức năng trên; cách này hiệu quả hơn so với phương pháp vừa nêu. Cụ thể, trong
quá trình nhảy từ nút tương ứng với $u$ lên gốc, dựa vào tính chất của cây tìm kiếm nhị phân, có thể xác định mỗi nút nằm
trước hay sau $u$ trong $L$. Từ đó có thể tính vị trí của $u$ trong dãy, đồng thời xác định mỗi nút thuộc cây nào sau khi
tách.

```cpp
/*
 * Tách treap p từ dưới lên thành 2 treap a và b.
 *   - a: treap chứa các nút có vị trí nhỏ hơn hoặc bằng p.
 *   - b: treap chứa các nút có vị trí lớn hơn p.
 *
 * Nói cách khác, tách dãy chứa p thành hai dãy: dãy thứ nhất chứa các phần tử
 * đứng trước p và chính p, dãy thứ hai chứa các phần tử đứng sau p.
 */
static std::pair<Node*, Node*> SplitUp2(Node* p) {
  Node *a = nullptr, *b = nullptr;
  b = p->right_;
  if (b) b->parent_ = nullptr;
  p->right_ = nullptr;

  bool is_p_left_child_of_parent = false;
  bool is_from_left_child = false;
  while (p) {
    Node* parent = p->parent_;

    if (parent) {
      is_p_left_child_of_parent = (parent->left_ == p);
      if (is_p_left_child_of_parent) {
        parent->left_ = nullptr;
      } else {
        parent->right_ = nullptr;
      }
      p->parent_ = nullptr;
    }

    if (!is_from_left_child) {
      a = Merge(p, a);
    } else {
      b = Merge(b, p);
    }

    is_from_left_child = is_p_left_child_of_parent;
    p->Maintain();
    p = parent;
  }

  return {a, b};
}
```

### SplitUp3(u)

Giả sử dãy chứa $u$ là $L$. Tách $L$ tại $u$ thành các phần $L^1$, $u$ và $L^2$. Phần trước chứa các phần tử đứng trước
$u$ trong $L$, còn phần sau chứa các phần tử còn lại.

Chỉ cần sửa nhẹ trên cơ sở `SplitUp2` là được.

### MakeRoot(u)

Có thể thu được trực tiếp từ `SplitUp2` và `Merge`.

```cpp
void MakeRoot(int u) {
  Node* vertex_u = vertices_[u];
  auto [L1, L2] = Treap::SplitUp2(vertex_u);
  Treap::Merge(L2, L1);
}
```

### Insert(u, v)

Có thể thu được trực tiếp từ `SplitUp2` và `Merge`.

```cpp
void Insert(int u, int v) {
  Node* vertex_u = vertices_[u];
  Node* vertex_v = vertices_[v];

  Node* edge_uv = AllocateNode(u, v);
  Node* edge_vu = AllocateNode(v, u);
  tree_edges_[u][v] = edge_uv;
  tree_edges_[v][u] = edge_vu;

  auto [L11, L12] = Treap::SplitUp2(vertex_u);
  auto [L21, L22] = Treap::SplitUp2(vertex_v);

  Node* L = L12;
  L = Treap::Merge(L, L11);
  L = Treap::Merge(L, edge_uv);
  L = Treap::Merge(L, L22);
  L = Treap::Merge(L, L21);
  L = Treap::Merge(L, edge_vu);
}
```

### Delete(u, v)

Có thể thu được trực tiếp từ `SplitUp3` và `Merge`.

```cpp
void Delete(int u, int v) {
  Node* edge_uv = tree_edges_[u][v];
  Node* edge_vu = tree_edges_[v][u];
  tree_edges_[u].erase(v);
  tree_edges_[v].erase(u);

  int position_uv = Treap::GetPosition(edge_uv);
  int position_vu = Treap::GetPosition(edge_vu);
  if (position_uv > position_vu) {
    std::swap(edge_uv, edge_vu);
    std::swap(position_uv, position_vu);
  }

  auto [L1, uv, _] = Treap::SplitUp3(edge_uv);
  auto [L2, vu, L3] = Treap::SplitUp3(edge_vu);
  Treap::Merge(L1, L3);

  FreeNode(edge_uv);
  FreeNode(edge_vu);
}
```

## Duy trì tính liên thông

Đỉnh $u$ và đỉnh $v$ liên thông khi và chỉ khi hai đỉnh thuộc cùng một cây $T$, tức $(u, u)$ và $(v, v)$ cùng thuộc
$\operatorname{ETR}(T)$. Có thể phán đoán điều này dựa trên việc hai nút Treap tương ứng với đỉnh $u$ và đỉnh $v$ có
cùng gốc Treap hay không.

### Bài tập ví dụ [P2147\[SDOI2008\] Thăm dò hang động](https://www.luogu.com.cn/problem/P2147)

Bài mẫu về duy trì tính liên thông.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/ett/ett_connectivity.cpp"
    ```

## Duy trì thông tin cây con

Phần dưới minh họa bằng số lượng đỉnh trong cây con.

Với mỗi phần tử trong $\operatorname{ETR}(T)$, nếu phần tử đó tương ứng với một đỉnh trong cây thì đặt trọng số của nó là
$1$; nếu phần tử đó tương ứng với một cạnh trong cây thì đặt trọng số của nó là $0$. Khi đó, số lượng đỉnh của cây $T$ có
thể được xem là tổng trọng số của các phần tử trong $\operatorname{ETR}(T)$. Chỉ cần duy trì thêm tổng trọng số của dãy là
có thể duy trì số lượng đỉnh trong cây con. Việc duy trì tổng trọng số của dãy là thao tác kinh điển của Treap không
xoay.

Tương tự, có thể chuyển các thao tác như giá trị nhỏ nhất trong cây con thành các thao tác kinh điển trên cây cân bằng,
chẳng hạn giá trị nhỏ nhất trên dãy, rồi duy trì chúng.

### Bài tập ví dụ [LOJ #2230. BJOI2014 - Đại dung hợp](https://loj.ac/p/2230)

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/ett/ett_subtree_size.cpp"
    ```

## Duy trì thông tin trên đường đi của cây

Có thể dùng một kỹ thuật khá phổ biến: dựa vào tính chất của dãy ngoặc để chuyển thông tin trên đường đi của cây thành
thông tin trên đoạn, rồi dùng cấu trúc dữ liệu duy trì dãy để duy trì thông tin trên đường đi. Tuy nhiên, kỹ thuật này
yêu cầu thông tin được duy trì phải có **tính trừ được**.

Các thao tác trên dãy tương ứng với thao tác cây động đã giới thiệu ở trên có thể di chuyển ngoặc phải trong dãy ngoặc lên
trước ngoặc trái. Vì vậy, khi duy trì các thông tin như tổng trọng số đỉnh trên đường đi của cây, cần đặc biệt chú ý rằng
thao tác không được làm thay đổi thứ tự trước-sau của cặp ngoặc trái và phải tương ứng. Điều này có thể đòi hỏi phải suy
nghĩ lại các thao tác trên dãy tương ứng với thao tác cây động, thậm chí suy nghĩ lại việc nên duy trì dãy DFS nào.

Ngoài ra, ETT rất khó duy trì các phép sửa đổi trên đường đi của cây.

### Bài tập ví dụ [Khám phá giữa các vì sao](https://hydro.ac/p/bzoj-P3786)

Trong bài này, thao tác cây động chỉ có đổi cha; có thể xem là xóa cạnh rồi thêm cạnh. Tuy nhiên, làm vậy có thể thay đổi
thứ tự trước-sau của cặp ngoặc tương ứng.

Có thể chuyển trọng số đỉnh thành trọng số cạnh, duy trì dãy ngoặc của cây, và chuyển thao tác đổi cha thành thao tác tịnh
tiến toàn bộ dãy ngoặc tương ứng với cây con đến ngay sau ngoặc trái của cha.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/ett/ett_1.cpp"
    ```

## Tài liệu tham khảo

-   Dynamic trees as search trees via euler tours, applied to the network simplex algorithm - Robert E. Tarjan
-   Randomized fully dynamic graph algorithms with polylogarithmic time per operation - Henzinger et al.
