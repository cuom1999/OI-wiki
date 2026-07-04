<span id="&#24341;&#35328;"></span>

## Giới thiệu

**Matroid** là một cấu trúc đại số trừu tượng do Hassler Whitney đề xuất vào năm 1935, nhằm thống nhất và khái quát hóa các khái niệm về tính độc lập, chẳng hạn như tính độc lập tuyến tính trong đại số tuyến tính và tính không chứa chu trình trong lý thuyết đồ thị.

Matroid cung cấp một công cụ lý thuyết mạnh để xử lý các bài toán tối ưu hóa liên quan đến tính độc lập. Nó được ứng dụng rộng rãi trong tổ hợp, lý thuyết đồ thị, thiết kế thuật toán và đặc biệt đóng vai trò quan trọng trong việc cung cấp cơ sở toán học cho các phương pháp tối ưu hóa như thuật toán tham lam.

<span id="&#23450;&#20041;"></span>

## Định nghĩa

<span id="&#25311;&#38453;"></span>

### Matroid

Một **matroid** có thể được biểu diễn bởi $M = (E, \mathcal{I})$, trong đó:

-   $E$ là một tập hữu hạn, gọi là **tập nền** (Ground Set).
-   $\mathcal{I}$ là một họ các tập con của $E$, gọi là **họ tập độc lập** (Family of Independent Sets); các tập trong họ này được gọi là **tập độc lập** (Independent Set). Họ này thỏa mãn ba tính chất sau:

    -   **Không rỗng**: tập rỗng là độc lập, tức là $\emptyset \in \mathcal{I}$.

    -   **Tính di truyền**: mọi tập con của một tập độc lập cũng là độc lập. Nếu $I \in \mathcal{I}$ thì với mọi $I' \subseteq I$ ta có $I' \in \mathcal{I}$.

    -   **Tính mở rộng**: nếu $I, J \in \mathcal{I}$ và $|I| < |J|$, thì tồn tại $j \in J \setminus I$ sao cho $I \cup \{j\} \in \mathcal{I}$.

Nếu một cấu trúc dạng $(E, \mathcal{I})$ thỏa mãn ba tính chất trên, ta gọi nó là một matroid.

<span id="&#22522;"></span>

### Cơ sở

**Cơ sở** (Basis) là một tập độc lập cực đại trong matroid, tức là một tập độc lập mà không thể thêm phần tử nào nữa mà vẫn giữ được tính độc lập. Tập hợp tất cả các cơ sở được gọi là **họ cơ sở**, ký hiệu là $\mathcal{B}$.

**Tính chất**:

1.  **Cùng lực lượng**: mọi cơ sở đều có cùng kích thước, gọi là **hạng** (Rank) của matroid.

2.  **Tính mở rộng**: mọi tập độc lập đều có thể được mở rộng thành một cơ sở bằng cách thêm các phần tử thuộc một cơ sở.

<span id="&#22280;"></span>

### Mạch

**Mạch** (Circuit) là một tập phụ thuộc tối tiểu trong matroid: mọi tập con thực sự của nó đều độc lập, nhưng bản thân nó không độc lập. Giữa hai mạch bất kỳ không tồn tại quan hệ bao hàm.

<span id="&#31209;"></span>

### Hạng

**Hàm hạng** (Rank Function) $r: 2^E \rightarrow \mathbb{Z}_{\geq 0}$ ánh xạ mỗi tập con của tập nền $E$ tới một số nguyên không âm. Với mọi $S \subseteq E$, $r(S)$ được định nghĩa là kích thước của tập độc lập lớn nhất trong $S$, tức là

$$
r(S) = \max \{ |I| \mid I \subseteq S \wedge I \in \mathcal{I} \}.
$$

**Tính chất**:

1.  **Không âm**: với mọi $S \subseteq E$, ta có $0 \leq r(S) \leq |S|$.

2.  **Đơn điệu**: nếu $A \subseteq B \subseteq E$ thì $r(A) \leq r(B)$.

3.  **Dưới mô-đun**: với mọi $A, B \subseteq E$, ta có $r(A \cup B) + r(A \cap B) \leq r(A) + r(B)$.

<span id="&#20856;&#22411;&#31034;&#20363;"></span>

## Các ví dụ điển hình

<span id="1-&#22343;&#21248;&#25311;&#38453;uniform-matroid"></span>

### 1. Matroid đều (Uniform Matroid)

**Định nghĩa**: cho tập nền $E$ và số nguyên không âm $k$, họ tập độc lập của matroid đều $U_{k,E}$ gồm tất cả các tập con có kích thước không vượt quá $k$, được biểu diễn bởi:

$$
\mathcal{I} = \{ I \subseteq E \mid |I| \leq k \}.
$$

-   **Cơ sở** (Bases): tất cả các tập con có kích thước bằng $k$.

-   **Mạch** (Circuits): tất cả các tập con có kích thước bằng $k + 1$.

-   **Hạng** (Rank): $r(E) = \min(k, |E|)$, tức là một tập độc lập có nhiều nhất $k$ phần tử.

<span id="2-&#22270;&#25311;&#38453;graphical-matroid"></span>

### 2. Matroid đồ thị (Graphical Matroid)

**Định nghĩa**: cho một đồ thị vô hướng $G = (V, E)$, tập nền của matroid đồ thị $M(G)$ là tập cạnh $E$, còn họ tập độc lập của nó gồm tất cả các tập cạnh không chứa chu trình, tức là tất cả các rừng.

-   **Cơ sở**: các cây khung trong đồ thị (trong trường hợp đồ thị liên thông). Cây khung là tập độc lập cực đại, vì không thể thêm cạnh nào nữa mà không tạo thành chu trình.

-   **Mạch**: các chu trình đơn trong đồ thị; nếu bỏ đi bất kỳ một cạnh nào trên chu trình thì phần còn lại là một tập độc lập.

-   **Hạng**: $r(E) = |V|  - c$, trong đó $c$ là số thành phần liên thông của đồ thị. Với một đồ thị vô hướng liên thông, hạng của nó bằng số đỉnh trừ đi một, tức là $|V|  - 1$.

<span id="3-&#32447;&#24615;&#25311;&#38453;linear-matroid"></span>

### 3. Matroid tuyến tính (Linear Matroid)

**Định nghĩa**: matroid tuyến tính được xây dựng trên không gian vectơ. Cho không gian vectơ $V$, tập nền $E$ là một tập hữu hạn các vectơ trong $V$, và họ tập độc lập của nó gồm tất cả các tập con vectơ độc lập tuyến tính của $E$.

-   **Cơ sở**: tập vectơ độc lập tuyến tính cực đại, có kích thước bằng số chiều của không gian vectơ.

-   **Mạch**: tập vectơ phụ thuộc tuyến tính tối tiểu; mọi tập con thực sự của nó đều độc lập, còn bản thân nó phụ thuộc tuyến tính.

-   **Hạng**: hạng của matroid tuyến tính là $r(E) = \dim(V)$, tức là số chiều của không gian vectơ. Kích thước của một tập độc lập không thể vượt quá số chiều của không gian vectơ.

<span id="4-&#21010;&#20998;&#25311;&#38453;partition-matroid"></span>

### 4. Matroid phân hoạch (Partition Matroid)

**Định nghĩa**: chia tập nền $E$ thành các tập con rời nhau $E_1, E_2, \dots, E_m$, rồi gán cho mỗi tập con $E_i$ một số nguyên không âm $k_i$. Họ tập độc lập của matroid phân hoạch gồm các tập con sao cho số phần tử được chọn trong mỗi phần không vượt quá $k_i$, được biểu diễn bởi:

$$
\mathcal{I} = \left\{ I \subseteq E \mid \forall i,\, |I \cap E_i|  \leq k_i \right\}.
$$

-   **Cơ sở**: một tập độc lập thỏa mãn $|I \cap E_i| = k_i$ là một cơ sở của matroid phân hoạch. Mỗi cơ sở chọn đúng $k_i$ phần tử trong từng tập con.

-   **Mạch**: mạch của matroid phân hoạch là tập phụ thuộc tối tiểu, tức là một tập chứa ít nhất một phần có số phần tử vượt quá $k_i$.

-   **Hạng**: hạng của matroid phân hoạch là $r(E) = \sum_{i=1}^m k_i$, tức là kích thước của tập độc lập lớn nhất bằng tổng số phần tử tối đa được phép chọn trong từng tập con.

<span id="5-&#26377;&#33394;&#25311;&#38453;colored-matroid"></span>

### 5. Matroid màu (Colored Matroid)

**Định nghĩa**: matroid màu là một dạng đặc biệt của matroid phân hoạch, trong đó mỗi phần tử được gán một màu. Cho tập nền $E$ và tập màu $C$, mỗi phần tử $e \in E$ được liên kết với một màu $c \in C$. Tập độc lập của matroid màu không chỉ cần thỏa mãn điều kiện độc lập thông thường của matroid, mà còn phải tuân thủ các ràng buộc theo màu, chẳng hạn số phần tử cùng một màu được chọn vào tập độc lập không vượt quá một giới hạn nhất định.

-   **Cơ sở**: cơ sở của matroid màu là tập độc lập cực đại thỏa mãn cả ràng buộc màu lẫn điều kiện độc lập.

-   **Mạch**: mạch là tập phụ thuộc tối tiểu, chứa ít nhất một tập phần tử vi phạm điều kiện độc lập hoặc ràng buộc màu.

-   **Hạng**: hạng của matroid màu là kích thước tập độc lập lớn nhất dưới các ràng buộc màu. Nó phụ thuộc cả vào cấu trúc của matroid lẫn quy định cụ thể của các ràng buộc màu.

<span id="&#26500;&#36896;&#21644;&#36816;&#31639;"></span>

## Cấu tạo và phép toán

<span id="&#23545;&#20598;"></span>

### Đối ngẫu

Cho matroid $M = (E, \mathcal{I})$, **matroid đối ngẫu** $M^* = (E, \mathcal{I}^*)$ của nó được định nghĩa bởi:

$$
\mathcal{I}^* = \{ I^* \subseteq E \mid \exists B \in \mathcal{I}, |B| = r(E), B \subseteq E \setminus I^* \}.
$$

**Tính chất**:

-   **Cơ sở**: cơ sở của matroid đối ngẫu $M^*$ là phần bù trong tập nền $E$ của các cơ sở của $M$. Nói cách khác, nếu $B$ là một cơ sở của $M$, thì $E \setminus B$ là một cơ sở của $M^*$.

-   **Hàm hạng**: hàm hạng của matroid đối ngẫu là $r^*(S) = |S| - r(E) + r(E \setminus S)$, trong đó $S$ là một tập con của $E$. Điều này có nghĩa là hạng của matroid đối ngẫu có thể được tính từ kích thước tập nền, hạng của matroid gốc và hạng sau khi loại bỏ $S$ khỏi tập nền.

-   **Tính phản thân**: đối ngẫu của matroid đối ngẫu chính là matroid ban đầu, tức là $(M^*)^* = M$.

**Ví dụ**:

Với một đồ thị vô hướng $G = (V, E)$, đối ngẫu $M(G)^*$ của matroid đồ thị $M(G)$ là matroid tạo bởi các tập cắt của đồ thị. Cơ sở của matroid đồ thị $M(G)$ là các cây khung trong đồ thị, còn cơ sở của đối ngẫu $M(G)^*$ là phần bù của các cây khung đó. Mạch của đối ngẫu $M(G)^*$ là các tập cắt tối tiểu của đồ thị, tức là các tập cạnh nhỏ nhất làm đồ thị bị chia thành hai phần không liên thông.

Chẳng hạn, xét một đồ thị tam giác đơn giản $G$ có tập cạnh $E = \{e_1, e_2, e_3\}$. Cơ sở của matroid đồ thị $M(G)$ là các tập gồm hai cạnh (ví dụ $\{e_1, e_2\}$), còn cơ sở của matroid đối ngẫu $M(G)^*$ là các tập gồm một cạnh (ví dụ $\{e_3\}$). Mạch của $M(G)^*$ là các tập gồm hai cạnh (tức là các tập cắt tối tiểu, chẳng hạn $\{e_2,e_3\}$), vì bỏ đi một cạnh trong đó sẽ chia đồ thị thành hai thành phần liên thông.

<span id="&#21024;&#38500;&#21644;&#25910;&#32553;"></span>

### Xóa và co

**Xóa** (Deletion):

Với $A \subseteq E$, sau khi xóa $A$ khỏi matroid $M$, ta thu được matroid mới $M \setminus A$ có họ tập độc lập $\mathcal{I}'$ được định nghĩa bởi:

$$
\mathcal{I}' = \{ I \subseteq E \setminus A \mid I \in \mathcal{I} \}.
$$

Có thể thấy phép xóa chỉ loại bỏ một số phần tử khỏi matroid và giữ lại các tập độc lập tạo bởi những phần tử còn lại; nó không làm thay đổi tính độc lập gốc, mà chỉ bỏ bớt phần tử.

**Co** (Contraction):

Với $A \subseteq E$, sau khi co $A$ trong matroid $M$, ta thu được matroid $M / A$ có họ tập độc lập $\mathcal{I}''$ được định nghĩa bởi:

$$
\mathcal{I}'' = \left\{ I \subseteq E \setminus A \,\bigg|\, \exists B \subseteq A,\, B \in \mathcal{I},\, r(B) = r(A),\, I \cup B \in \mathcal{I} \right\}
$$

Phép co có thể được hiểu là co các phần tử trong tập $A$, rồi xét các phần tử còn lại khi ghép với một cơ sở của $A$ để tạo thành tập độc lập. Kết quả của phép co phụ thuộc vào cơ sở của $A$; các tập độc lập sau khi co thực chất là kết quả rút gọn các tập con có hạng cao hơn trong matroid ban đầu.

**Ví dụ - matroid đồ thị**:

-   **Xóa**: trong matroid đồ thị, phép xóa tương ứng với việc xóa một số cạnh khỏi đồ thị. Sau khi một đồ thị $G$ bị xóa một cạnh, ta xét các tập độc lập tạo bởi những cạnh còn lại, tức là các tập cạnh không chứa chu trình. Ví dụ, nếu xóa một cạnh khỏi đồ thị tam giác, hai cạnh còn lại vẫn là một rừng.

-   **Co**: phép co tương ứng với việc co một cạnh thành một đỉnh. Với matroid đồ thị, co một cạnh tương đương với hợp nhất hai đầu mút của cạnh đó thành một đỉnh rồi xóa cạnh đó; sau khi hợp nhất đỉnh, các cạnh còn lại trong đồ thị vẫn có thể tạo thành tập độc lập. Ví dụ, trong một đồ thị tam giác, co bất kỳ một cạnh nào sẽ hợp nhất hai đỉnh thành một, và hai cạnh còn lại sẽ tạo thành một matroid mới.

<span id="&#25311;&#38453;&#21644;&#36138;&#24515;"></span>

## Matroid và tham lam

**Mô tả bài toán**:

Một trong những ứng dụng của matroid là giải các bài toán tối ưu trong thuật toán tham lam. Cụ thể, cho một matroid $M = (S, \mathcal{I})$, trong đó $S$ là tập nền và $\mathcal{I}$ là họ tập độc lập. Với mỗi phần tử $x \in S$, gán một trọng số nguyên dương $w(x)$; mục tiêu là tìm tập độc lập có tổng trọng số lớn nhất, được hình thức hóa như sau:

$$
\max_{A \in \mathcal{I}} w(A) = \max_{A \in \mathcal{I}} \sum_{x \in A} w(x)
$$

Rõ ràng, tập độc lập có trọng số lớn nhất phải là tập độc lập cực đại. Nếu một tập độc lập $A$ chưa cực đại, thì tồn tại một phần tử $x$ có thể thêm vào $A$; do $w(x) > 0$, sau khi thêm phần tử đó thì tổng trọng số tăng lên, nên $A$ không thể là tập độc lập có trọng số lớn nhất.

<span id="&#27493;&#39588;"></span>

### Các bước

Các bước của thuật toán tham lam để tìm tập độc lập có trọng số lớn nhất như sau:

1.  **Sắp xếp phần tử**: sắp xếp tập nền $S$ theo trọng số giảm dần, thu được dãy $e_1, e_2, \dots, e_n$.
2.  **Khởi tạo**: đặt tập độc lập $A = \emptyset$.
3.  **Xây dựng tập độc lập**: lần lượt xét các phần tử đã sắp xếp $e_i$; nếu $A \cup \{ e_i \} \in \mathcal{I}$, cập nhật $A = A \cup \{ e_i \}$.
4.  **Xuất kết quả**: tập $A$ cuối cùng chính là tập độc lập có trọng số lớn nhất.

**Phân tích độ phức tạp**:

Gọi $n = |S|$ là kích thước tập nền, và $f(n)$ là độ phức tạp của việc kiểm tra một tập có độc lập hay không. Độ phức tạp thời gian của thuật toán tham lam là:

$$
O(n \log n + n f(n))
$$

Trong đó, $O(n \log n)$ là độ phức tạp của sắp xếp, còn $O(n f(n))$ là độ phức tạp của việc kiểm tra tính độc lập từng phần tử một.

???+ note "Ghi chú"
    -   Trong matroid đồ thị, có thể dùng [DSU](../ds/dsu.md) để phát hiện hiệu quả việc thêm cạnh có tạo chu trình hay không, qua đó làm cho $f(n)$ gần với thời gian hằng số.
    -   Trong matroid tuyến tính, kiểm tra tính độc lập thường liên quan đến các phép toán ma trận, và độ phức tạp phụ thuộc vào cách cài đặt cụ thể.

**Chứng minh tính đúng đắn**:

Giả sử $M = (S, \mathcal{I})$ là một matroid, $A \in \mathcal{I}$ là một tập độc lập, và $A$ là tập con của một tập độc lập $T$ có trọng số lớn nhất nào đó. Định nghĩa tập $P = \{ x \in S \setminus A \mid A \cup \{x\} \in \mathcal{I} \}$, tức là tập tất cả các phần tử mà khi thêm vào $A$ vẫn giữ cho $A$ độc lập.

Gọi $y$ là phần tử có trọng số lớn nhất trong $P$. Khi đó $A' = A \cup \{ y \}$ cũng là tập con của một tập độc lập có trọng số lớn nhất. Chứng minh như sau:

Giả sử $A' = A \cup \{ y \}$ không phải là tập con của bất kỳ tập độc lập có trọng số lớn nhất nào. Khi đó tồn tại một tập độc lập $T$ có trọng số lớn nhất và $|A'| < |T|$.

Vì $|A'|< |T|$, theo **tính mở rộng** của matroid, tồn tại $x \in T \setminus A'$ sao cho $A' \cup \{ x \} \in \mathcal{I}$.

Dùng **tính mở rộng**, liên tục thêm $x$ vào $A'$ để cuối cùng xây dựng được một tập độc lập mới $A''$ sao cho $|A''| = |T|$.

Đặt $K = A'' \cap T$. Khi đó có $x = T \setminus K$ và $y = A'' \setminus K$. Vì $y$ là phần tử có trọng số lớn nhất trong $P$, ta có $w(x) \leq w(y)$.

Do đó $w(A'') = w(K) + w(y) \geq w(K) + w(x) = w(T)$. Khi ấy:

-   Nếu $w(A'') > w(T)$, thì $T$ không phải là tập độc lập có trọng số lớn nhất, mâu thuẫn với giả thiết.
-   Nếu $w(A'') = w(T)$, thì $A''$ là một tập độc lập có trọng số lớn nhất và $A'$ là tập con của nó, mâu thuẫn với giả thiết rằng $A'$ không phải là tập con của bất kỳ tập độc lập có trọng số lớn nhất nào.

Tóm lại, giả thiết không đúng; tức là $A' = A \cup \{ y \}$ phải là tập con của một tập độc lập có trọng số lớn nhất nào đó. Vì vậy, bằng cách liên tục áp dụng chiến lược tham lam, cuối cùng ta có thể tìm được tập độc lập có trọng số lớn nhất.

<span id="&#31034;&#20363;"></span>

### Ví dụ

**Cây khung nhỏ nhất**:

Cho một đồ thị vô hướng liên thông $G = (V, E)$, mỗi cạnh $e \in E$ có trọng số $w(e)$. Mục tiêu là tìm một cây khung chứa tất cả các đỉnh và có tổng trọng số nhỏ nhất.

**Xây dựng matroid**:

Để hình thức hóa bài toán cây khung nhỏ nhất thành bài toán matroid, ta có thể xây dựng matroid đồ thị $M(G)$:

-   **Tập nền**: $S = E$, tức là tất cả các cạnh trong đồ thị.
-   **Họ tập độc lập**: $\mathcal{I}$ gồm tất cả các tập cạnh không chứa chu trình, tức là tất cả các rừng.

**Thuật toán tham lam**:

Trong khuôn khổ matroid đồ thị, [thuật toán Kruskal](../graph/mst.md#thuật-toán-kruskal) là một thuật toán tham lam điển hình dựa trên lý thuyết matroid, có thể dùng để xây dựng cây khung nhỏ nhất. Dù [thuật toán Prim](../graph/mst.md#thuật-toán-prim) cũng là một thuật toán tham lam hiệu quả và cũng tìm được cây khung nhỏ nhất, nó không phụ thuộc chặt chẽ vào tham lam của matroid. Vì vậy, trong thảo luận về lý thuyết matroid, thuật toán Kruskal là ví dụ chính của thuật toán tham lam.

-   **Thuật toán Kruskal**:
    1.  **Sắp xếp cạnh**: sắp xếp tất cả các cạnh theo trọng số tăng dần.
    2.  **Chọn dần**: lần lượt chọn cạnh có trọng số nhỏ nhất; nếu thêm cạnh đó không tạo thành chu trình, đưa nó vào cây khung.
    3.  **Điều kiện dừng**: lặp lại quá trình trên cho đến khi cây khung chứa $|V| - 1$ cạnh.

-   **Thuật toán Prim**:
    -   **Nguyên lý**: thuật toán Prim bắt đầu từ một đỉnh xuất phát, rồi mở rộng cây khung từng bước; mỗi lần chọn cạnh có trọng số nhỏ nhất nối giữa phần trong cây và phần ngoài cây.
    -   Dù thuật toán Prim cũng là tham lam, chiến lược lựa chọn của nó khác với các thuật toán tham lam dựa trên tính mở rộng của matroid. Vì vậy, theo nghĩa chặt chẽ trong lý thuyết matroid, Prim không được xem là một thuật toán tham lam matroid điển hình.

<span id="&#25311;&#38453;&#20132;"></span>

## Giao matroid

Với hai matroid $M_1 = (S, \mathcal{I}_1)$ và $M_2 = (S, \mathcal{I}_2)$ được định nghĩa trên cùng tập nền $S$, nếu $\mathcal{I} = \mathcal{I}_1 \cap \mathcal{I}_2$ thỏa mãn ba tính chất của họ tập độc lập trong định nghĩa matroid, thì $M = (S, \mathcal{I})$ được gọi là **giao** của $M_1$ và $M_2$.

**Chú ý**: không phải giao của hai matroid bất kỳ cũng là một matroid. Chỉ khi giao của hai họ tập độc lập thỏa mãn ba tính chất trong định nghĩa họ tập độc lập của matroid thì giao đó mới tạo thành một matroid.

<span id="&#38382;&#39064;&#25551;&#36848;"></span>

### Mô tả bài toán

1.  **Tập độc lập lớn nhất**: tìm tập độc lập lớn nhất trong $\mathcal{I}_1 \cap \mathcal{I}_2$ (tức là tập độc lập có lực lượng lớn nhất).
2.  **Tập độc lập có trọng số lớn nhất**: cho hàm trọng số $w: S \to \mathbb{R}$, tìm tập độc lập có tổng trọng số lớn nhất trong $\mathcal{I}_1 \cap \mathcal{I}_2$.

<span id="&#31639;&#27861;"></span>

### Thuật toán

**Phiên bản không trọng số**:

1.  **Khởi tạo**: chọn một tập độc lập ban đầu $I \in \mathcal{I}_1 \cap \mathcal{I}_2$, thường đặt $I = \emptyset$.
2.  **Lặp**:
    -   **Xây dựng đồ thị trao đổi**: dựa trên tập độc lập hiện tại $I$, xây dựng đồ thị trao đổi $D_{M_1, M_2}(I)$.
    -   **Chọn đường đi**: trong đồ thị trao đổi, tìm một đường tăng $P$ từ nguồn $s$ đến đích $t$.
    -   **Tăng**: duyệt từng nút trên đường đi $P$ từ $s$ đến $t$:
        -   Nếu nút thuộc phần trái (tức là phần tử trong $I$), loại phần tử đó khỏi $I$.
        -   Nếu nút thuộc phần phải (tức là phần tử trong $S \setminus I$), thêm phần tử đó vào $I$.
    -   **Lặp lại**: sau khi cập nhật tập độc lập $I$, lặp lại các bước trên cho đến khi không tìm được đường tăng mới.
3.  **Kết quả**: tập độc lập $I$ cuối cùng là một tập độc lập lớn nhất trong giao matroid $M = M_1 \cap M_2$.

**Phiên bản có trọng số**:

Để tìm tập độc lập có tổng trọng số lớn nhất, thuật toán cần tối ưu hóa cách chọn đường tăng.

1.  **Gán trọng số**: với mỗi phần tử $e \in S$, định nghĩa trọng số $w'(e)$ của nó trong đồ thị trao đổi:
    -   **Đỉnh phần trái** (phần tử trong $I$): $w'(e) = -w(e)$.
    -   **Đỉnh phần phải** (phần tử trong $S \setminus I$): $w'(e) = w(e)$.
2.  **Chọn đường đi**: trong đồ thị trao đổi $D_{M_1, M_2}(I)$, tìm một **đường tăng** $P$ từ nguồn $s$ đến đích $t$ sao cho sau khi tăng theo đường đi đó, tổng trọng số của tập độc lập $I$ tăng nhiều nhất.
    -   **Điều kiện tăng**: tổng trọng số của các phần tử được thêm trên đường đi $P$ lớn hơn tổng trọng số của các phần tử bị loại bỏ, tức là $\sum_{y \in \text{phần tử được thêm}} w(y) > \sum_{x \in \text{phần tử bị loại bỏ}} w(x)$
3.  **Thao tác tăng**: duyệt từng nút trên đường đi $P$ từ $s$ đến $t$:
    -   Nếu nút thuộc phần trái (tức là phần tử trong $I$), loại phần tử đó khỏi $I$.
    -   Nếu nút thuộc phần phải (tức là phần tử trong $S \setminus I$), thêm phần tử đó vào $I$.
4.  **Lặp**: lặp lại các bước 1 đến 3, liên tục xây dựng đồ thị trao đổi và tìm đường tăng để từng bước tối ưu hóa tổng trọng số của tập độc lập $I$.
5.  **Điều kiện dừng**: khi không thể tìm được đường đi thỏa mãn điều kiện tăng trong đồ thị trao đổi, thuật toán dừng.
6.  **Kết quả**: tập độc lập $I$ cuối cùng là một **tập độc lập có trọng số lớn nhất** trong giao matroid $M = M_1 \cap M_2$.

**Độ phức tạp**:

-   **Số lần tăng**: giả sử hạng lớn nhất của hai matroid lần lượt là $r_1$ và $r_2$, thì số lần tăng tối đa là $\min(r_1, r_2)$.

-   **Độ phức tạp của mỗi lần tăng**:
    -   Độ phức tạp xây dựng đồ thị trao đổi là $O(n^2)$, trong đó $n = |S|$.
    -   Độ phức tạp tìm đường tăng phụ thuộc vào chiến lược tìm kiếm đường đi, thường là $O(n^2)$, chẳng hạn khi dùng tìm kiếm theo chiều rộng.

-   **Tổng độ phức tạp thời gian**: độ phức tạp thời gian tổng thể là $O(r \cdot n^2)$, trong đó $r = \min(r_1, r_2)$.

<span id="&#20363;&#39064;"></span>

## Bài tập ví dụ

**Cây khung nhỏ nhất**:

Cho một đồ thị vô hướng $G = (V, E)$, mỗi cạnh $e \in E$ đều có trọng số $w(e)$. Tìm một cây khung chứa tất cả các đỉnh và có tổng trọng số nhỏ nhất.

-   Giới thiệu chi tiết: [Cây khung nhỏ nhất](../graph/mst.md).
-   Bài mẫu: [Luogu P3366 [Mẫu] Cây khung nhỏ nhất](https://www.luogu.com.cn/problem/P3366).

??? note "Ý tưởng lời giải"
    Dùng thuật toán Kruskal: sắp xếp tất cả các cạnh theo trọng số tăng dần, rồi chọn cạnh từng bước; nếu thêm cạnh đó không tạo thành chu trình thì đưa nó vào cây khung. Cây khung thu được cuối cùng chính là cây khung nhỏ nhất.

**Colorful Graph**:

Cho một đồ thị vô hướng $G = (V, E)$ có nhiều màu, mỗi cạnh có một thuộc tính màu. Tìm một tập cạnh lớn nhất sao cho:

1.  Các cạnh được chọn không tạo thành bất kỳ chu trình nào.
2.  Số cạnh của mỗi màu không vượt quá $k$ cạnh ($k$ là một số nguyên dương cho trước).

??? note "Ý tưởng lời giải"
    1.  **Mô hình hóa bằng matroid**:

        -   **Matroid đồ thị ($M_1$)**: định nghĩa bởi tất cả các tập cạnh không tạo thành chu trình, tức là họ tập độc lập $\mathcal{I}_1$ chứa mọi tập cạnh không chứa chu trình.
        -   **Matroid màu ($M_2$)**: định nghĩa bởi các tập cạnh có số cạnh của mỗi màu không vượt quá $k$, tức là họ tập độc lập $\mathcal{I}_2$ chứa mọi tập cạnh thỏa mãn số cạnh của mỗi màu $\leq k$.
    2.  **Giải giao matroid**: bằng cách giải $M = M_1 \cap M_2$, ta tìm được tập cạnh lớn nhất vừa không tạo chu trình vừa thỏa mãn số cạnh mỗi màu không vượt quá $k$.

**Bài toán phân bổ tài nguyên có ràng buộc**:

Trong một bài toán phân bổ tài nguyên, có một tập tài nguyên $R = \{r_1, r_2, \dots, r_n\}$ và một tập dự án $P = \{p_1, p_2, \dots, p_m\}$. Mỗi dự án $p_i$ cần được phân bổ một lượng tài nguyên nhất định, và tổng lượng phân bổ của mỗi loại tài nguyên không được vượt quá lượng cung ứng của nó.

**Mục tiêu**: tìm một phương án phân bổ tài nguyên sao cho thỏa mãn nhu cầu của mọi dự án và không vượt quá lượng cung ứng tài nguyên.

??? note "Ý tưởng lời giải"
    1.  **Mô hình hóa bằng matroid**:

        -   **Matroid nhu cầu ($M_1$)**: định nghĩa bởi các phương án phân bổ thỏa mãn nhu cầu tài nguyên của từng dự án, tức là họ tập độc lập $\mathcal{I}_1$ chứa mọi tập phân bổ tài nguyên thỏa mãn nhu cầu dự án.
        -   **Matroid cung ứng ($M_2$)**: định nghĩa bởi các phương án phân bổ không vượt quá lượng cung ứng của từng loại tài nguyên, tức là họ tập độc lập $\mathcal{I}_2$ chứa mọi tập phân bổ thỏa mãn giới hạn cung ứng tài nguyên.
    2.  **Giải giao matroid**: bằng cách giải $M = M_1 \cap M_2$, ta tìm được phương án phân bổ tài nguyên vừa thỏa mãn nhu cầu của mọi dự án vừa không vượt quá lượng cung ứng tài nguyên.

<span id="&#21442;&#32771;&#36164;&#26009;&#19982;&#27880;&#37322;"></span>

## Tài liệu tham khảo và chú thích

1.  [Wikipedia - Matroid](https://en.wikipedia.org/wiki/Matroid)
2.  [Baidu Baike - Matroid](https://baike.baidu.com/item/%E6%8B%9F%E9%98%B5)
3.  [Luogu - Matroid và bài toán tối ưu hóa](https://www.luogu.com.cn/article/87d02q9f)
4.  [Luogu - Từ cơ sở matroid đến trò chơi công tắc Shannon](https://www.luogu.com.cn/article/fuj3x886)
