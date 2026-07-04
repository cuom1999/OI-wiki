Trang này giới thiệu các bài toán bước đi ngẫu nhiên trên đồ thị. Nội dung chủ yếu khảo sát từ ba góc độ: đồ thị lưới, đồ thị thưa và đồ thị tổng quát; đồng thời trình bày nhiều phương pháp giải loại bài toán này và so sánh ưu, nhược điểm của chúng trong các tình huống khác nhau.

## Định nghĩa

Cho một đồ thị đơn có hướng $G=(V, E)(V=\{v_1, v_2, \cdots, v_{|V|}\})$, đỉnh xuất phát $s \in V$ và đỉnh kết thúc $t \in V$. Mỗi cạnh $e=\left(x, y\right)$ có trọng số dương $w_e$, thỏa mãn $\forall x \in V \backslash\left\{t\right\}$, $\sum_{\left(x, y\right) \in E} w_{\left(x, y\right)}=1$, và với mọi đỉnh $x$ đều tồn tại một đường đi từ $x$ đến $t$. Một quân cờ xuất phát từ đỉnh đầu; mỗi giây, nếu đang ở đỉnh $x$, nó chọn cạnh ra $\left(x, y\right)$ với xác suất $w_{(x, y)}$ rồi đi tới $y$. Khi đến đỉnh kết thúc thì dừng lại. Hãy tính kỳ vọng thời gian cần dùng.

Thực ra, bài toán này cũng có thể viết dưới dạng ma trận. Định nghĩa ma trận $P$:

$$
P_{x, y}=
\begin{cases}
w_{(x, y)} & \text{if } (x, y) \in E \text{ and } x \neq t \\
0 & \text{if } (x, y) \notin E \text{ or } x=t \\
\end{cases}
$$

Đáp án cần tìm là:

$$
\sum_{k \geq 0} k \times\left(P^k\right)_{s, t}
$$

Trong đó $\left(P^k\right)_{s, t}$ biểu thị xác suất lần đầu đến đỉnh kết thúc sau đúng $k$ bước. Khi đồ thị hữu hạn và mọi đỉnh đều đi được đến đỉnh kết thúc, từ định nghĩa của $P$ có thể chứng minh mọi giá trị riêng của nó đều nhỏ hơn 1, nên đáp án chắc chắn hội tụ.

Để tiện trình bày, trong trang này nếu không nói gì thêm, ta dùng $n$ để chỉ $|V|$ và $m$ để chỉ $|E|$.

Ngoài ra, trong trang này, đồ thị thưa là đồ thị có số cạnh cùng bậc với số đỉnh.

## Đồ thị lưới

???+ note "Bài ví dụ 1 [Circles of Waiting](https://codeforces.com/problemset/problem/963/E)"
    Ban đầu có một quân cờ được đặt tại điểm $(0,0)$ trên mặt phẳng tọa độ Descartes. Mỗi giây quân cờ sẽ di chuyển ngẫu nhiên. Giả sử hiện tại nó ở $(x, y)$; trong giây tiếp theo, nó di chuyển đến $(x-1, y)$ với xác suất $p_1$, đến $(x, y-1)$ với xác suất $p_2$, đến $(x+1, y)$ với xác suất $p_3$, và đến $(x, y+1)$ với xác suất $p_4$. Đảm bảo $p_1+p_2+p_3+p_4=1$.
    Hãy tính kỳ vọng thời gian để nó di chuyển đến một vị trí có khoảng cách Euclid tới gốc tọa độ lớn hơn $R$. $0 \leq R \leq 50$, $p_1, p_2, p_3, p_4>0$, đáp án lấy modulo $10^9+7$.

### Cách làm đơn giản

Gọi $f(i, j)$ là kỳ vọng thời gian để quân cờ, khi đang ở $(i, j)$, di chuyển đến một vị trí có khoảng cách Euclid tới gốc tọa độ lớn hơn $R$. Phương trình chuyển là:

$$
f(i, j)=
\begin{cases}
p_1 f(i-1, j) + p_2 f(i, j-1) + p_3 f(i+1, j) + p_4 f(i, j+1) + 1 & i^2 + j^2 \leq R^2 \\
0 & i^2 + j^2 > R^2
\end{cases}
$$

Do các chuyển trạng thái không có thứ tự topo, ta cần dùng khử Gauss để giải. Độ phức tạp thời gian là $O\left(R^6\right)$, không đủ để qua bài này.

### Phương pháp khử trực tiếp

Nhận thấy hầu hết các hệ số trong những phương trình cần khử đều bằng 0; khi khử, nếu chỉ tính trên các vị trí có giá trị khác 0 thì có thể giảm độ phức tạp.

Xét quá trình khử. Ta khử các phương trình theo thứ tự từ trên xuống dưới trong hệ tọa độ, và trong cùng một lớp thì từ trái sang phải. Tô các phương trình đã khử màu vàng, các điểm kề với điểm vàng màu xanh lá, còn lại màu đen, như hình dưới:

![graph-random-walk-1](images/graph-random-walk-1.svg)

Tiếp theo cần khử phương trình tương ứng với ô xanh lá kế tiếp. Trong phương trình này, chỉ các hệ số của biến tương ứng với các ô xanh lá và ô đen đầu tiên bên dưới nó mới có thể khác 0; ngược lại, chỉ trong các phương trình tương ứng với các ô xanh lá và ô đen đầu tiên bên dưới nó thì hệ số của biến ứng với ô hiện tại mới có thể khác 0.

Vì chỉ có $O(R)$ ô xanh lá, độ phức tạp khử cho một phương trình là $O\left(R^2\right)$. Tổng cộng chỉ có $O\left(R^2\right)$ phương trình, nên độ phức tạp thời gian giảm xuống $O\left(R^4\right)$ và có thể qua bài này.

### Phương pháp phần tử trụ

Cả số phương trình lẫn số biến đều là $O\left(R^2\right)$. Nếu có thể thu nhỏ quy mô xuống $O(R)$, khử Gauss đơn giản sẽ đủ để qua bài.

Đặt biến tương ứng với ô đầu tiên từ trái sang phải trên mỗi hàng làm phần tử trụ, tổng cộng có $2 R+1$ phần tử trụ, rồi tìm cách biểu diễn các biến tương ứng với những ô khác dưới dạng hàm tuyến tính theo các phần tử trụ này. Xét từng cột từ trái sang phải; với mỗi ô $(i, j)$ trong cột hiện tại, nhận thấy $f(i, j)$, $f(i-1, j)$, $f(i, j-1)$, $f(i, j+1)$ đều đã là các hàm tuyến tính đã biết theo các phần tử trụ. Chuyển vế phương trình chuyển, ta có:

$$
f(i+1, j)=\frac{f(i, j)-p_1 f(i-1, j)-p_2 f(i, j-1)-p_4 f(i, j+1)-1}{p_3}
$$

Như vậy ta có thể nhận được biểu diễn tuyến tính của $f(i+1, j)$ theo các phần tử trụ. Nếu $(i+1, j)$ đã có khoảng cách Euclid tới gốc tọa độ vượt quá $R$, ta nhận được một phương trình: $f(i+1, j)=0$. Cuối cùng sẽ thu được $2 R+1$ phương trình, chỉ cần khử Gauss trên các phương trình này.

Ở giai đoạn truy hồi các hàm tuyến tính theo phần tử trụ, có tổng cộng $O\left(R^2\right)$ biến, và việc truy hồi một biến tốn $O(R)$ thời gian. Sau đó, quy mô bài toán đã được giảm xuống $O(R)$. Độ phức tạp thời gian của cả hai phần đều là $O\left(R^3\right)$, nên tổng độ phức tạp cũng là $O\left(R^3\right)$ và có thể qua bài này.

### So sánh hai cách làm

Dưới đây so sánh hai cách làm trên nhiều khía cạnh:

Về độ phức tạp thời gian, phương pháp phần tử trụ trên đồ thị lưới có độ phức tạp xấu nhất là $O(n \sqrt{n})$ (đạt cao nhất khi cả chiều dài và chiều rộng của đồ thị lưới đều ở mức $O(\sqrt{n})$), còn phương pháp khử trực tiếp trên đồ thị lưới có độ phức tạp xấu nhất là $O\left(n^2\right)$. Vì vậy phương pháp phần tử trụ tốt hơn.

Về độ chính xác, với một số bài cần tính số thực thay vì lấy modulo, phương pháp khử trực tiếp có độ chính xác tốt hơn phương pháp phần tử trụ.

Về phạm vi áp dụng, hai cách làm phù hợp với các tình huống khác nhau.

Khi trong đồ thị lưới có chướng ngại, hoặc xác suất đi qua một số cạnh bằng $0$, phương pháp phần tử trụ cần thêm một phần tử trụ cho mỗi chướng ngại hoặc mỗi cạnh có xác suất bằng $0$. Khi số lượng chướng ngại hoặc cạnh xác suất $0$ vượt quá $O(R)$, độ phức tạp thời gian của phương pháp phần tử trụ sẽ tăng, còn độ phức tạp của phương pháp khử trực tiếp vẫn không đổi.

Tuy nhiên, phương pháp phần tử trụ còn có thể khử các phương trình chuyển tương tự đồ thị lưới, chẳng hạn $f(i, j)=p_1 f(i+1, j)+p_2 f(i, j+1)+p_3 f(\operatorname{pre}(i, j))+1$, trong đó $\operatorname{pre}(i, j)=(x, y)(x \leq i, y \leq j)$ là giá trị do đề bài cho; còn phân tích độ phức tạp của phương pháp khử trực tiếp không áp dụng được trong mô hình này.

Ngoài ra, việc tính định thức của ma trận kề của đồ thị lưới cũng không thể dùng phương pháp phần tử trụ, mà chỉ có thể dùng phương pháp khử trực tiếp để tối ưu độ phức tạp thời gian.

Tóm lại, hai cách làm đều có sở trường riêng; cần phân tích theo từng bài cụ thể để chọn phương pháp phù hợp.

## Đồ thị thưa

???+ note "Bài ví dụ 2 Expected Value"
    Cho một đồ thị đơn vô hướng liên thông và thưa $G=(V, E)$. Ban đầu có một quân cờ được đặt tại $v_1$; mỗi giây, quân cờ chọn đều ngẫu nhiên một cạnh trong các cạnh nối với đỉnh hiện tại rồi đi đến đỉnh mà cạnh đó dẫn tới. Hãy tính kỳ vọng thời gian để đến $v_n$. $n \leq 2000$, đáp án lấy modulo $p$, trong đó $p$ là một số nguyên tố được sinh ngẫu nhiên trong khoảng $\left[10^9, 1.01 \times 10^9\right]$.

### Kiến thức cơ sở

**Định nghĩa 4.1.** Mọi đa thức $p(λ)$ thỏa mãn $p(A) = 0$ được gọi là đa thức triệt tiêu của ma trận $A$.

**Định nghĩa 4.2.** Gọi $I_n$ là ma trận đơn vị cấp $n$. Đa thức đặc trưng của một ma trận $n × n$ $A$ được định nghĩa là $p(λ) = \det(λI_n - A)$, trong đó $\det$ biểu thị định thức của một ma trận.
Dễ thấy bậc của đa thức đặc trưng của một ma trận cấp $n$ $A$ không vượt quá $n$.

**Định lý 4.2.** (Định lý Cayley–Hamilton) Đa thức đặc trưng của một ma trận bất kỳ là đa thức triệt tiêu của nó.

Do đó, bậc của đa thức triệt tiêu có bậc nhỏ nhất của một ma trận cấp $n$ cũng không vượt quá $n$.

### Giải bài toán ban đầu

Nhận thấy kỳ vọng thời gian đi là $E(t)=\sum_{i\geq0}\Pr[t>i]$. Nếu ta tính được xác suất sau $i$ bước vẫn chưa kết thúc, thì tổng trên mọi $i ≥ 0$ chính là đáp án.

Gọi $f(i, j)$ là xác suất sau khi đi $i$ bước, quân cờ đang ở $j$ và chưa từng đi tới $n$. Khi đó:

$$
f(i,j)=\sum_{(k,j)\in E}\frac{f(i-1,k)}{\deg_k}(j\neq n)
$$

Trong đó $\deg_k$ biểu thị bậc của $k$.

Nhận thấy chuyển trạng thái của $f$ không phụ thuộc vào $i$, có thể xem một lần chuyển là nhân với một ma trận, tức $f_{i+1}=f_iM$. Vì đa thức triệt tiêu bậc nhỏ nhất của $M$ có bậc không vượt quá $n$, độ dài công thức truy hồi ngắn nhất của $f$ cũng không vượt quá $n$. Do đó độ dài công thức truy hồi ngắn nhất của $\Pr[t>i]=\sum_{j=1}^{n-1}f(i,j)$ cũng không vượt quá $n$. Ta có thể tính $\Pr[t>0],\Pr[t>1],\cdots,\Pr[t>3n]$ trong $O(nm)$ thời gian, rồi dùng thuật toán *Berlekamp–Massey* để tìm công thức truy hồi ngắn nhất của $\Pr[t > i]$ trong $O(n^2)$ thời gian.

Xét việc tìm hàm sinh của một dãy truy hồi tuyến tính bậc $k$ là $a$. Giả sử khi $i ≥ i_0$ thì $a_i=\sum_{j=1}^kc_ja_{i-j}$. Gọi hàm sinh của $a$ và $c$ lần lượt là $A(x)$ và $C(x)$, khi đó $A(x)=A(x)C(x)+A_0(x)$, trong đó $A_0(x)$ được quyết định bởi các hạng tử có $i < i_0$.

Quay lại bài toán ban đầu, vì ta có thể tìm công thức truy hồi ngắn nhất của $\Pr[t > i]$, nên có thể tính $C(x)$ và $A_0(x)$ (định nghĩa như đoạn trước). Chuyển vế được $A(x)=\frac{A_0(x)}{1-C(x)}$. Đại lượng cần tìm là $\sum_{i\geq0}[x^i]A(x)$; dễ thấy giá trị này bằng $A(1)$, vì vậy chỉ cần thay $x = 1$ vào để giải bài toán ban đầu. Do modulo là một số nguyên tố ngẫu nhiên, có thể xem như mẫu số sẽ không bằng $0$.

Như vậy, ta giải được bài này với độ phức tạp thời gian $O(nm+n^2)$. Nếu số đỉnh và số cạnh của đồ thị $G$ cùng bậc, trong bài này có thể xem độ phức tạp thời gian là $O(n^2)$.

## Đồ thị tổng quát

???+ note "Bài ví dụ 3 Frank"
    Cho một đồ thị đơn có hướng liên thông mạnh $G = (V, E)$. Với mọi $1 ≤ s ≤ n$, $1 ≤ t ≤ n$, $s ≠ t$, hãy trả lời câu hỏi sau:
    Ban đầu có một quân cờ được đặt tại $v_s$; mỗi giây, quân cờ chọn đều ngẫu nhiên một cạnh trong các cạnh ra của đỉnh hiện tại rồi đi đến đỉnh mà cạnh đó chỉ tới. Hãy tính kỳ vọng thời gian để đến $v_t$. $3 ≤ n ≤ 400$.

### Phân tích và biến đổi

Gọi $p_{i, j}$ là xác suất quân cờ, khi đang ở $i$, chọn cạnh ra $(i, j)$ để đi tới $j$; đặc biệt, nếu cạnh ra không tồn tại thì xác suất là $0$. Gọi $f_{i,j}$ là kỳ vọng thời gian để bước đi ngẫu nhiên từ $i$ đến $j$; đặc biệt, $f_{i,i} = 0$. Khi $i ≠ j$, phương trình chuyển là:

$$
f_{i,j}=1+\sum_{1\leq k\leq n}p_{i,k}f_{k,j}
$$

Khi $i = j$, gọi $g_i$ là kỳ vọng thời gian để bắt đầu bước đi ngẫu nhiên từ $i$ rồi lần đầu quay lại $i$. Khi đó:

$$
f_{i,i}=1-g_i+\sum_{1\le k\le n}p_{i,k}f_{k,i}
$$

Để dễ quan sát, ta viết phương trình chuyển dưới dạng ma trận. Gọi $P$ là ma trận chuyển của đồ thị này, $F$ là ma trận đáp án, $I$ là ma trận đơn vị cấp $n$, $J$ là ma trận cấp $n$ toàn số $1$, và $G$ là một ma trận cấp $n$ thỏa mãn $G_{i,i} = g_i$, còn các vị trí khác bằng $0$. Khi đó:

$$
F=J-G+PF
$$

Nếu tìm được $G$, ta chỉ cần giải phương trình:

$$
(I − P)F = J − G
$$

### Cách tìm G

**Định nghĩa 5.1.** Phân phối dừng của một ma trận chuyển cấp $n$ $P$ được định nghĩa là một vector $n$ chiều $π$, thỏa mãn $\sum_{i=1}^{n}\pi_{i}=1$, $πP = π$. Trong đó, giá trị ở mỗi chiều của $π$ đều nằm trong khoảng $[0,1]$.

Ta dễ dàng thấy ý nghĩa thực tế của phân phối dừng. Nếu tại một thời điểm nào đó, quân cờ ở $v_i$ với xác suất $π_i$, thì tại mọi thời điểm về sau, quân cờ vẫn thỏa mãn phân phối xác suất này. Ta có thể giải hệ phương trình bằng khử Gauss trong $O(n^3)$ thời gian để tìm $π$. Vậy $π$ có quan hệ gì với $G$?

**Định lý 5.1.** Với mọi $1 ≤ i ≤ n$, có $π_ig_i = 1$.

???+ note "Chứng minh"
    Từ $F = J - G + PF$, chuyển vế được:

    $$
    G = PF + J − F
    $$

    Nhân đồng thời hai vế ở bên trái với $π$, ta có:

    $$
    πG = πPF + πJ − πF
    $$

    Theo định nghĩa của $π$, có $πP = π$, do đó:

    $$
    πG = πJ
    $$

    Vì vậy:

    $$
    \pi_ig_i=\sum_{j=1}^n\pi_j=1
    $$

Mệnh đề ban đầu được chứng minh.

Vì vậy, bằng cách đưa vào phân phối dừng, ta có thể tìm $G$ trong $O(n^3)$ thời gian.

### Giải bài toán ban đầu

Trong quá trình giải phương trình, ta gặp một vấn đề: $(I - P)$ không đầy hạng, nên không thể giải bằng cách nhân với ma trận nghịch đảo.

**Định nghĩa 5.2.** Cây khung có hướng của đồ thị có hướng $G = (V,E)$ với gốc $r\in V$ được định nghĩa là một đồ thị con $T = (V,A)$ của $G$, thỏa mãn:

1.  Với mọi $i ≠ r$, bậc ra của $i$ là $1$.
2.  Bậc ra của $r$ là $0$.
3.  Trong $T$ không tồn tại chu trình.

**Bổ đề 5.1.** (Định lý ma trận-cây trên đồ thị có hướng) Với một đồ thị có hướng $G$, gọi $D$ là ma trận bậc ra của nó, tức $D_{i,i} = d_i$, $D_{i,j} = 0(i ≠ j)$, trong đó $d_i$ là bậc ra của $i$; gọi $A$ là ma trận kề của nó. Khi đó số cây khung có hướng gốc $r$ bằng định thức của ma trận thu được từ $D - A$ sau khi xóa hàng $r$ và cột $r$.

**Định lý 5.2.** Với ma trận chuyển $P$ của một đồ thị liên thông mạnh $G = (V,E)$, hạng của $(I - P)$ là $n - 1$.

???+ note "Chứng minh"
    Vì nhân một hàng của ma trận với một hằng số khác 0 không làm thay đổi hạng, ta nhân hàng thứ $i$ của $(I - P)$ với bậc ra của $v_i$ để nhận được một ma trận mới $L$. Khi đó chỉ cần chứng minh hạng của $L$ là $n - 1$.
    Do tổng trên mỗi hàng của $L$ đều bằng $0$, khi lấy tổng tất cả các vector cột của $L$ sẽ thu được vector không, tức các vector này phụ thuộc tuyến tính, nên hạng của $L$ không phải là $n$.
    Dễ thấy $L$ bằng ma trận bậc ra của đồ thị $G$ trừ đi ma trận kề của nó. Theo Bổ đề 5.1, định thức của $L$ sau khi xóa hàng thứ $i$ và cột thứ $i$ biểu thị số cây khung có hướng gốc $v_i$.
    Vì G liên thông mạnh, số cây khung có hướng gốc ở bất kỳ đỉnh nào đều khác $0$, tức $L$ sau khi xóa hàng thứ $i$ và cột thứ $i$ vẫn đầy hạng.
    Vì thêm một cột không thể làm hạng giảm, tất cả các vector hàng của $L$ sau khi xóa hàng thứ $i$ là độc lập tuyến tính. Do đó hạng của $L$ là $n - 1$.
    Quay lại bài toán ban đầu, xét việc giải phương trình trong bài toán ban đầu. Để tiện, ta viết phương trình dưới dạng $AX = B$, trong đó $A$, $B$ đã biết và cần tìm $X$. Vì $A$ không đầy hạng, phương trình có vô số nghiệm; trước hết ta tìm một nghiệm riêng.
    Thực hiện khử Gauss đồng thời trên $A$ và $B$. Khử $n - 1$ hàng đầu của $A$ thành dạng chỉ có đường chéo chính và cột thứ $n$ có giá trị, còn hàng cuối cùng toàn $0$, tức dạng sau:

    $$
    \begin{bmatrix}
    1 & 0 & 0 & \cdots & 0 & a_1 \\0&1&0&\cdots&0&a_2\\0&0&1&\cdots&0&a_3\\
    \vdots&\vdots&\vdots&\ddots&\vdots&\vdots
    \\0&0&0&\cdots&1&a_{n-1}\\0&0&0&\cdots&0&0
    \end{bmatrix}
    X=
    \begin{bmatrix}
    b_{1,1}&b_{1,2}&b_{1,3}&\cdots&b_{1,n-1}&b_{1,n}
    \\b_{2,1}&b_{2,2}&b_{2,3}&\cdots&b_{2,n-1}&b_{2,n}
    \\b_{3,1}&b_{3,2}&b_{3,3}&\cdots&b_{3,n-1}&b_{3,n}
    \\\vdots&\vdots&\vdots&\ddots&\vdots&\vdots
    \\b_{n-1,1}&b_{n-1,2}&b_{n-1,3}&\cdots&b_{n-1,n-1}&b_{n-1,n}
    \\0&0&0&\cdots&0&0
    \end{bmatrix}
    $$

    Đặt $X_{n,i} = 0$, ta có thể giải ra một nghiệm riêng, ký hiệu là $Y$. Tiếp theo điều chỉnh nghiệm riêng thành nghiệm thực sự.
    Chú ý $X_{n,i} = 0$; xét ý nghĩa tổ hợp, có $Y_{i,j} = 1 + Y_{j,j} + P_{i,k}X_{k,j}$, từ đó không khó để giải ra $X_{i,j} = Y_{i,j} - Y_{j,j}$.
    Cuối cùng, bài toán này được giải trong độ phức tạp thời gian $O(n^3)$.

## Tham khảo

1.  Bàn sơ lược về bài toán bước đi ngẫu nhiên trên mô hình đồ thị. Tuyển tập luận văn đội tuyển ứng viên quốc gia Trung Quốc IOI2019 (pp. 17-26)
