## Dẫn nhập

Tổng tiền tố và sai phân là các kỹ thuật thường dùng trong lập trình thi đấu. Tổng tiền tố dùng để tính nhanh tổng trên đoạn, còn sai phân dùng để thực hiện hiệu quả các phép sửa đổi trên đoạn.

???+ tip "Quy ước"
    Để tiện thảo luận, bài viết này mặc định mảng $\{a_i\}$ được đánh chỉ số từ $1$, và định nghĩa bổ sung $a_0 = 0$.

## Tổng tiền tố

Tổng tiền tố có thể hiểu đơn giản là "tổng của $n$ phần tử đầu của dãy", và là một phương pháp tiền xử lý quan trọng.

### Tổng tiền tố một chiều

Với dãy $\{a_i\}$ độ dài $n$, nếu cần truy vấn nhiều lần tổng các số trong đoạn $[l,r]$, có thể cân nhắc dùng tổng tiền tố. Tổng tiền tố của dãy là

$$
S_{i} = \sum_{j=1}^i a_j.
$$

Có thể tính nó lần lượt bằng công thức truy hồi

$$
S_0 = 0,~ S_i = S_{i-1} + a_i
$$

Để truy vấn tổng của dãy trên đoạn $[l,r]$, chỉ cần tính hiệu

$$
S([l,r]) = S_r - S_{l-1}.
$$

Như vậy, sau khi tiền xử lý trong thời gian $O(n)$, độ phức tạp của mỗi truy vấn tổng đoạn giảm xuống $O(1)$.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/basic/code/prefix-sum/prefix-sum_1.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/basic/code/prefix-sum/prefix-sum_1.py:core"
        ```

Thư viện chuẩn C++ cung cấp hàm tổng tiền tố [`std::partial_sum`](https://en.cppreference.com/w/cpp/algorithm/partial_sum), được định nghĩa trong tệp tiêu đề `<numeric>`. Từ C++17, thư viện chuẩn còn cung cấp hàm tổng tiền tố có chức năng tương tự là [`std::inclusive_scan`](https://en.cppreference.com/w/cpp/algorithm/inclusive_scan), cũng được định nghĩa trong tệp tiêu đề `<numeric>`.

### Tổng tiền tố hai chiều / nhiều chiều

Mở rộng tổng tiền tố một chiều sang trường hợp nhiều chiều sẽ thu được tổng tiền tố nhiều chiều. Có hai phương pháp thường gặp để tính tổng tiền tố nhiều chiều.

#### Dựa trên nguyên lý bao hàm - loại trừ

Phương pháp này thường dùng cho trường hợp tổng tiền tố hai chiều. Cho mảng hai chiều $A$ kích thước $m\times n$, cần tính tổng tiền tố $S$ của nó. Khi đó $S$ cũng là mảng hai chiều kích thước $m\times n$, và

$$
S_{i,j} = \sum_{i'\le i}\sum_{j'\le j}A_{i',j'}.
$$

Tương tự trường hợp một chiều, lẽ ra có thể tính $S_{i,j}$ dựa trên $S_{i-1,j}$ hoặc $S_{i,j-1}$ để tránh tính lặp tổng của một số phần tử phía trước. Tuy nhiên, nếu cộng trực tiếp $S_{i-1,j}$ và $S_{i,j-1}$ rồi cộng thêm $A_{i,j}$, phần giao nhau $S_{i-1,j-1}$ sẽ bị tính lặp, nên cần trừ phần này đi. Đây chính là [nguyên lý bao hàm - loại trừ](../math/combinatorics/inclusion-exclusion-principle.md). Từ đó thu được công thức truy hồi:

$$
S_{i,j} = A_{i,j} + S_{i-1,j} + S_{i,j-1} - S_{i-1,j-1}. 
$$

Khi cài đặt, chỉ cần duyệt trực tiếp các $(i,j)$ để tính tổng.

???+ note "Ví dụ"
    Xét một ví dụ cụ thể.
    
    ![Ví dụ tổng tiền tố hai chiều](./images/prefix-sum-2d.svg)
    
    Trong đó, $S$ là tổng tiền tố của ma trận $A$. Theo định nghĩa, $S_{3,3}$ là tổng của ma trận con trong khung nét đứt ở hình bên trái. Ngoài ra, $S_{3,2}$ là tổng của ma trận con màu xanh, $S_{2,3}$ là tổng của ma trận con màu đỏ, và tổng phần giao nhau của chúng là $S_{2,2}$. Vì vậy, nếu cộng trực tiếp $S_{3,2}$ và $S_{2,3}$, $S_{2,2}$ sẽ bị tính lặp, nên phải có
    
    $$
    S_{3,3} = A_{3,3} + S_{2,3} + S_{3,2} - S_{2,2} = 5 + 18 + 15 - 9 = 29.
    $$

Tương tự, sau khi đã tiền xử lý tổng tiền tố hai chiều, để truy vấn tổng của ma trận con có góc trên trái $(i_1,j_1)$ và góc dưới phải $(i_2,j_2)$, có thể tính

$$
S_{i_2,j_2} - S_{i_1-1,j_2} - S_{i_2,j_1-1} + S_{i_1-1,j_1-1}.
$$

Việc này hoàn thành trong thời gian $O(1)$.

Trong trường hợp hai chiều, độ phức tạp thời gian của thuật toán trên có thể xem đơn giản là $O(mn)$, tức tuyến tính theo kích thước mảng đã cho. Tuy nhiên, khi số chiều $k$ tăng lên, do số hạng liên quan đến nguyên lý bao hàm - loại trừ tăng theo cấp số mũ, độ phức tạp thời gian sẽ trở thành $O(2^kN)$, trong đó $k$ là số chiều của mảng và $N$ là kích thước mảng đã cho. Vì vậy, thuật toán này không còn phù hợp.

???+ example "[Luogu P1387 Hình vuông lớn nhất](https://www.luogu.com.cn/problem/P1387)"
    Trong một ma trận $n\times m$ chỉ gồm $0$ và $1$, tìm hình vuông lớn nhất không chứa $0$ và in ra độ dài cạnh của nó.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/basic/code/prefix-sum/prefix-sum_2.cpp:full-text"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/basic/code/prefix-sum/prefix-sum_2.py:full-text"
        ```

#### Tổng tiền tố theo từng chiều

Với trường hợp tổng quát, cho mảng $k$ chiều $A$ kích thước $N$, cũng cần tính tổng tiền tố $S$ của nó. Khi đó,

$$
S_{i_1,\cdots,i_k} = \sum_{i'_1\le i_1}\cdots\sum_{i'_k\le i_k} A_{i'_1,\cdots,i'_k}.
$$

Từ công thức trên, tổng tiền tố $k$ chiều chính là thực hiện phép lấy tổng $k$ lần. Vì vậy, một thuật toán trực tiếp là mỗi lần chỉ xét một chiều, cố định tất cả các chiều còn lại, rồi tính một số tổng tiền tố một chiều. Sau khi lần lượt tính tổng theo cả $k$ chiều, sẽ thu được tổng tiền tố $k$ chiều.

??? example "Cài đặt tham khảo cho tổng tiền tố ba chiều"
    ```cpp
    --8<-- "docs/basic/code/prefix-sum/prefix-sum_4.cpp:core"
    ```

Vì khi xét mỗi chiều, chỉ cần duyệt toàn bộ mảng một lần, độ phức tạp của thuật toán này là $O(kN)$ và thường chấp nhận được.

#### Trường hợp đặc biệt: DP tổng trên tập con

Trường hợp số chiều khá lớn thường xuất hiện trong một lớp bài toán gọi là **tổng trên tập con** (sum over subsets, SOS). Đây là một trường hợp đặc biệt của tổng tiền tố nhiều chiều.

Mô tả bài toán như sau. Xét một hàm $f$ được định nghĩa trên toàn bộ các tập con của một tập kích thước $n$. Cần tính hàm tổng trên tập con $g$, thỏa mãn

$$
g(S) = \sum_{T\subseteq S}f(T).
$$

Tức là $g(S)$ bằng tổng giá trị hàm $f(T)$ trên mọi tập con $T\subseteq S$ của nó.

Trước hết, bài toán tổng trên tập con có thể viết dưới dạng tổng tiền tố nhiều chiều. Lưu ý rằng tập con của $S$ có thể được biểu diễn bằng tư tưởng nén trạng thái thành chuỗi 0-1 độ dài $n$. Xem mỗi bit của chuỗi là một chiều trong chỉ số mảng, khi đó $f$ thực chất là một mảng $n$ chiều, và chỉ số ở mỗi chiều luôn nằm trong $\{0,1\}$. Đồng thời, quan hệ bao hàm giữa các tập con tương đương với quan hệ lớn nhỏ của chỉ số, tức là

$$
T\subseteq S \iff \forall i(t_i \le s_i). 
$$

Vì vậy, lấy tổng trên các tập con chính là tính tổng tiền tố của mảng $n$ chiều này.

Bây giờ, có thể dùng trực tiếp phương pháp tổng tiền tố theo từng chiều đã nêu ở trên để tính tổng trên tập con. Độ phức tạp thời gian là $O(n2^n)$.

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/basic/code/prefix-sum/prefix-sum_5.cpp:core"
    ```

Phép ngược của tổng trên tập con cần thực hiện bằng [nguyên lý bao hàm - loại trừ](../math/combinatorics/inclusion-exclusion-principle.md). Bài toán tổng trên tập con cũng là một trong những bước cần thiết của biến đổi Mobius nhanh.

### Tổng tiền tố trên cây

Tổng tiền tố một chiều còn có thể mở rộng sang trường hợp cây có gốc (gốc cây là $1$). Bằng cách tiền xử lý tổng tiền tố, có thể nhanh chóng tính tổng trọng số trên một đường đi của cây.

#### Trường hợp trọng số đỉnh

Trước hết xét trường hợp trọng số được lưu ở đỉnh. Giả sử đỉnh $x$ có trọng số $a_x$. Có thể dùng công thức truy hồi

$$
S_1 = a_1,~ S_{x} = S_{\operatorname{fa}(x)} + a_x
$$

để tính tổng trọng số các đỉnh trên đường đi từ gốc tới đỉnh $x$, trong đó $\operatorname{fa}(x)$ biểu thị cha của $x$. Sau khi tiền xử lý tổng tiền tố, có thể tính tổng trọng số đỉnh trên đường đi nối đỉnh $x$ và $y$ bằng

$$
S_x + S_y - S_{\operatorname{lca}(x, y)} - S_{\operatorname{fa}(\operatorname{lca}(x, y))}
$$

Trong đó, $\operatorname{lca}(x, y)$ biểu thị [tổ tiên chung gần nhất](../graph/lca.md) của đỉnh $x$ và $y$.

#### Trường hợp trọng số cạnh

Trường hợp trọng số lưu trên cạnh gần như có thể chuyển về trường hợp trọng số đỉnh. Với mọi đỉnh không phải gốc $x\neq 1$, ký hiệu $\operatorname{edge}(x)$ là cạnh nối đỉnh $x$ với cha của nó $\operatorname{fa}(x)$. Khi đó, có thể giả sử trọng số cạnh được lưu ở đỉnh xa gốc hơn. Nói cách khác, tại đỉnh $x$ lưu trọng số của cạnh $\operatorname{edge}(x)$. Trọng số lưu ở đỉnh gốc là $0$. Khi đó, bằng công thức truy hồi đã thảo luận ở tiểu mục trước, cũng có thể tiền xử lý tổng trọng số $S_x$ của tất cả các cạnh trên đường đi từ gốc tới đỉnh $x$.

Lúc này, tổng trọng số cạnh trên đường đi nối đỉnh $x$ và $y$ có thể được truy vấn bằng

$$
S_x + S_y - 2S_{\operatorname{lca}(x, y)}
$$

Lưu ý rằng khác với trường hợp trọng số đỉnh, tổng trọng số được truy vấn không bao gồm trọng số tại $\operatorname{lca}(x, y)$, vì trọng số cạnh được lưu ở đó không nằm trên đường đi cần tính.

#### Tổng cây con

Khác với trường hợp mảng, do cây không đối xứng đầu-cuối, kết quả tính "tổng tiền tố" từ dưới lên (từ lá tới gốc) và từ trên xuống (từ gốc tới lá) không giống nhau. Thông thường, "tổng tiền tố trên cây" chỉ tổng tiền tố được tính từ trên xuống. Để tiện thảo luận, bài viết này gọi "tổng tiền tố" tính từ dưới lên là **tổng cây con**.

Tổng trọng số đỉnh của cây con gốc $x$, tức tổng cây con tương ứng, là

$$
T_x = \sum_{y\in\operatorname{desc}(x)} a_y.
$$

Trong đó, $\operatorname{desc}(x)$ biểu thị tập mọi đỉnh con cháu của $x$ (bao gồm chính nó).

Khác với tổng tiền tố trên cây, tổng cây con không thể dùng để tính tổng trọng số đường đi trong $O(1)$, nhưng nó có thể giúp hiểu phần sai phân trên cây bên dưới.

## Sai phân

Sai phân là một chiến lược đối ngẫu với tổng tiền tố, là phép toán ngược của tổng tiền tố. So với việc cho một dãy rồi tính sai phân của nó, tình huống thường gặp hơn trong thi đấu là duy trì thông tin của dãy sai phân để thực hiện nhiều lần sửa đổi đoạn. Sau khi kết thúc các phép sửa đổi đoạn, có thể dùng tổng tiền tố để khôi phục thông tin của dãy ban đầu, rồi truy vấn dãy ban đầu. Lưu ý rằng mọi thao tác sửa đổi phải diễn ra trước thao tác truy vấn.

Nếu cần hỗ trợ nhiều thao tác sửa đổi và truy vấn xen kẽ, cần dùng [cây Fenwick](../ds/fenwick.md), nhưng hai cách làm này có chung ý tưởng.

### Sai phân một chiều

Với dãy $\{a_i\}$, dãy sai phân $\{D_i\}$ của nó được định nghĩa là

$$
D_i = a_i - a_{i-1},~ a_0 = 0.
$$

Thư viện chuẩn C++ cung cấp hàm sai phân [`std::adjacent_difference`](https://en.cppreference.com/w/cpp/algorithm/adjacent_difference), được định nghĩa trong tệp tiêu đề `<numeric>`.

Quan hệ giữa tổng tiền tố và sai phân như sau:

???+ note "Tính chất"
    Giả sử $\{D_i\}$ là dãy sai phân của $\{a_i\}$. Khi đó:
    
    -   Dãy $\{a_i\}$ là tổng tiền tố của dãy $\{D_i\}$, tức là
    
        $$
        a_i = \sum_{j=1}^i D_j.
        $$
    -   Tổng tiền tố của dãy $\{a_i\}$ là
    
        $$
        S_i = \sum_{j=1}^i\sum_{k=1}^jD_k = \sum_{j=1}^i(i-j+1)D_j. 
        $$

Thông tin sai phân thường được dùng để duy trì nhiều lần cộng một số vào một đoạn của dãy, rồi sau đó truy vấn một hoặc nhiều lần giá trị tại một vị trí của dãy.

Giả sử cần cộng $v$ vào mỗi số trong đoạn $[l,r]$ của dãy $\{a_i\}$. Có thể thực hiện thao tác sau trên dãy sai phân $\{D_i\}$ của nó:

$$
D_{l} \gets D_{l} + v,~ D_{r+1}\gets D_{r+1} - v.
$$

Sau khi mọi thao tác sửa đổi kết thúc, có thể dùng tổng tiền tố để khôi phục giá trị của $\{a_i\}$ sau cập nhật. Mỗi lần sửa đổi là $O(1)$. Khi truy vấn, cần thực hiện một lần tính tổng tiền tố $O(n)$, rồi mỗi truy vấn sau đó là $O(1)$.

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/basic/code/prefix-sum/prefix-sum_6.cpp:core"
    ```

### Sai phân hai chiều / nhiều chiều

Sai phân cũng có thể mở rộng sang trường hợp nhiều chiều. Xem sai phân nhiều chiều là phép toán ngược của tổng tiền tố nhiều chiều, thao tác tính mảng sai phân nhiều chiều tương đương với việc biết tổng tiền tố nhiều chiều rồi tính mảng gốc của nó. Theo thảo luận ở trên, có thể dùng nguyên lý bao hàm - loại trừ. Chẳng hạn, định nghĩa của sai phân hai chiều là

$$
D_{i,j} = a_{i,j} - a_{i-1,j} - a_{i,j-1} + a_{i-1,j-1}.
$$

Tuy nhiên, nếu cần tính toàn bộ mảng sai phân, cách đơn giản và hiệu quả hơn là sai phân theo từng chiều, tức liệt kê mọi chiều và dọc theo mỗi chiều tính sai phân của mảng một lần.

Thông tin sai phân hai chiều thường dùng để duy trì nhiều lần cộng trên hình chữ nhật của mảng hai chiều. Ví dụ, để cộng $v$ vào mỗi số trong ma trận có góc trên trái $(x_1,y_1)$ và góc dưới phải $(x_2,y_2)$, có thể thực hiện thao tác sau trên mảng sai phân $\{D_{i,j}\}$ của nó:

$$
\begin{aligned}
D_{x_1,y_1} &\gets D_{x_1,y_1} + v, \\
D_{x_1,y_2+1} &\gets D_{x_1,y_2+1} - v,\\
D_{x_2+1,y_1} &\gets D_{x_2+1,y_1} - v,\\
D_{x_2+1,y_2+1} &\gets D_{x_2+1,y_2+1} + v.
\end{aligned}
$$

Sau khi mọi thao tác sửa đổi kết thúc, chỉ cần thực hiện một lần tổng tiền tố hai chiều để nhanh chóng truy vấn giá trị của mảng sau cập nhật.

??? example "Mã tham khảo"
    ```cpp
    --8<-- "docs/basic/code/prefix-sum/prefix-sum_7.cpp:core"
    ```

Tư tưởng tương tự cũng đúng với số chiều $k>2$, nhưng độ phức tạp thời gian của một thao tác sửa đổi là $O(2^k)$, nên không còn thực dụng khi $k$ tăng.

### Sai phân trên cây

Sai phân có thể mở rộng sang trường hợp cây có gốc, dùng để thực hiện thao tác cộng trên đoạn là một đường đi của cây. Tùy thông tin được lưu trên đỉnh hay trên cạnh, sai phân trên cây có thể chia thành **sai phân đỉnh** và **sai phân cạnh**, cách cài đặt hơi khác nhau. Ngoài ra, so với thao tác tổng tiền tố trên cây, cách thường dùng hơn là sau mọi thao tác sửa đổi thì tính tổng cây con rồi truy vấn. Mục này thảo luận đúng trường hợp đó.

#### Sai phân đỉnh

Nếu cần cộng $v$ vào toàn bộ trọng số đỉnh trên đường đi giữa hai đỉnh $x$ và $y$, có thể thực hiện thao tác sau trên dãy sai phân $\{D_x\}$:

$$
\begin{aligned}
D_x &\gets D_x + v, \\
D_{\operatorname{lca}(x, y)} &\gets D_{\operatorname{lca}(x, y)} - v,\\
D_y &\gets D_y + v, \\
D_{\operatorname{fa}(\operatorname{lca}(x, y))} &\gets D_{\operatorname{fa}(\operatorname{lca}(x, y))} - v.
\end{aligned}
$$

Sau khi mọi thao tác sửa đổi hoàn tất, tính một lần tổng cây con là có thể nhận được trọng số đỉnh sau cập nhật.

???+ example "Ví dụ"
    Khi thực hiện thao tác cộng đoạn trên trọng số đỉnh của đường đi giữa hai đỉnh $S$ và $T$, hai công thức đầu ở trên là thao tác sai phân một chiều trên đường đi trong khung màu xanh, còn hai công thức sau là thao tác sai phân một chiều trên đường đi trong khung màu đỏ:
    
    ![](./images/prefix_sum1.svg)
    
    Tính tổng từ dưới lên tương đương với tính tổng tiền tố từ dưới lên trên hai đoạn này. Từ đó, so sánh với thao tác sai phân một chiều ở trên là có thể hiểu tính đúng đắn của sai phân đỉnh.

#### Sai phân cạnh

Nếu cần cộng $v$ vào toàn bộ trọng số cạnh trên đường đi giữa hai đỉnh $x$ và $y$, có thể thực hiện thao tác sau trên dãy sai phân $\{D_x\}$:

$$
\begin{aligned}
D_x &\gets D_x + v, \\
D_y &\gets D_y + v, \\
D_{\operatorname{lca}(x, y)} &\gets D_{\operatorname{lca}(x, y)} - 2v.
\end{aligned}
$$

Sau khi mọi thao tác sửa đổi hoàn tất, tính một lần tổng cây con là có thể nhận được trọng số cạnh sau cập nhật.

???+ example "Ví dụ"
    Như hình vẽ, thao tác sai phân cạnh có thể dùng để giải bài toán cộng đoạn trên trọng số cạnh của đường đi màu đỏ.
    
    ![](./images/prefix_sum2.svg)
    
    Vì thực hiện sai phân trực tiếp trên cạnh khá khó, chuyển giá trị vốn cần cộng vào cạnh màu đỏ xuống đỉnh kề phía dưới sẽ làm thao tác thuận tiện hơn. So sánh với công thức sai phân đỉnh là có thể hiểu công thức sai phân cạnh.

### Bài mẫu

???+ example "[Luogu 3128 Dòng chảy lớn nhất](https://www.luogu.com.cn/problem/P3128)"
    FJ lắp đặt $N-1$ đường ống giữa $N(2 \le N \le 50,000)$ ngăn trong chuồng bò của mình; các ngăn được đánh số từ $1$ đến $N$. Tất cả các ngăn đều được đường ống nối thông.
    
    FJ có $K(1 \le K \le 100,000)$ tuyến vận chuyển sữa. Tuyến thứ $i$ vận chuyển từ ngăn $s_i$ tới ngăn $t_i$. Một tuyến vận chuyển sẽ tạo một đơn vị áp lực vận chuyển lên hai ngăn ở hai đầu mút của nó cũng như mọi ngăn đi qua ở giữa. Cần tính áp lực lớn nhất trên một ngăn là bao nhiêu.

??? note "Ý tưởng giải"
    Cần thống kê mỗi đỉnh được đi qua bao nhiêu lần, vì vậy dùng sai phân trên cây để cộng một cho đường đi của mỗi lần, từ đó có thể nhanh chóng thu được số lần đi qua mỗi đỉnh. Lời giải này dùng phương pháp nhân đôi để tính LCA; cuối cùng DFS duyệt cả cây, khi quay lui thì tính tổng trên mảng sai phân để thu được đáp án.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/basic/code/prefix-sum/prefix-sum_3.cpp"
    ```

## Bài tập

Tổng tiền tố:

-   [Luogu B3612【Nhập môn sâu 1. Ví dụ 1】Tính tổng đoạn](https://www.luogu.com.cn/problem/B3612)
-   [Luogu U69096 Nghịch đảo của tổng tiền tố](https://www.luogu.com.cn/problem/U69096)
-   [AtCoder joi2007ho\_a Tổng lớn nhất](https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_a)
-   [「USACO16JAN」Subsequences Summing to Sevens](https://www.luogu.com.cn/problem/P3131)
-   [「USACO05JAN」Moo Volume S](https://www.luogu.com.cn/problem/P6067)

Tổng tiền tố hai chiều / nhiều chiều:

-   [HDU 6514 Monitor](https://acm.hdu.edu.cn/showproblem.php?pid=6514)
-   [Luogu P1387 Hình vuông lớn nhất](https://www.luogu.com.cn/problem/P1387)
-   [「HNOI2003」Bom laser](https://www.luogu.com.cn/problem/P2280)
-   [CF 165E Compatible Numbers](https://codeforces.com/contest/165/problem/E)
-   [CF 383E Vowels](https://codeforces.com/problemset/problem/383/E)
-   [ARC 100C Or Plus Max](https://atcoder.jp/contests/arc100/tasks/arc100_c)

Tổng tiền tố trên cây:

-   [LOJ 10134.Dis](https://loj.ac/problem/10134)
-   [LOJ 2491. Tính tổng](https://loj.ac/problem/2491)

Sai phân:

-   [Cây Fenwick 3: sửa đoạn, truy vấn đoạn](https://loj.ac/problem/132)
-   [「Poetize6」IncDec Sequence](https://www.luogu.com.cn/problem/P4552)
-   [Luogu P4231 Ba bước tất sát](https://www.luogu.com.cn/problem/P4231)

Sai phân hai chiều / nhiều chiều:

-   [Luogu P3397 Thảm](https://www.luogu.com.cn/problem/P3397)
-   [Luogu P8228「Wdoi-5」Lò phản ứng hạt nhân mô-đun hóa](https://www.luogu.com.cn/problem/P8228)

Sai phân trên cây:

-   [Luogu 3128 Dòng chảy lớn nhất](https://www.luogu.com.cn/problem/P3128)
-   [JLOI2014 Nhà mới của sóc](https://loj.ac/problem/2236)
-   [NOIP2015 Kế hoạch vận chuyển](http://uoj.ac/problem/150)
-   [NOIP2016 Chạy bộ mỗi ngày](http://uoj.ac/problem/261)
