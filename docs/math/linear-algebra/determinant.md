Định thức là một phép toán trên ma trận vuông. Với ma trận vuông $A$, $\det A$ biểu thị định thức của $A$.

Bài này giới thiệu ba cách định nghĩa định thức. Có thể chứng minh rằng các định nghĩa trong bài là tương đương.

<span id="định-nghĩa-bằng-hoán-vị"></span>
## Định nghĩa bằng hoán vị

Kiến thức chuẩn bị: [hoán vị](../permutation.md), [số nghịch thế](../permutation.md#số-nghịch-thế).

Khi tính tay định thức bậc thấp, có thể dùng cách này; độ phức tạp thời gian của nó ở cấp giai thừa.

Dùng ký hiệu $\pi(j_1j_2\cdots j_n)$ để chỉ số nghịch thế của hoán vị $j_1j_2\cdots j_n$, và $S_n$ là tập tất cả hoán vị độ dài $n$. Ký hiệu như sau:

$$
\begin{aligned}
\det A &= \begin{vmatrix}
a_{11} & a_{12} & \cdots & a_{1n}\\
a_{21} & a_{22} & \cdots & a_{2n}\\
\vdots & \vdots &  & \vdots\\
a_{n1} & a_{n2} & \cdots & a_{nn}\\
\end{vmatrix} \\
&= \sum_{(j_1j_2\cdots j_n) \in S_n} (-1)^{\pi(j_1j_2\cdots j_n)} a_{1 j_1} a_{2 j_2}\dots a_{n j_n}
\end{aligned}
$$

Định thức bậc $n$ ở trên là tổng đại số gồm $n!$ hạng tử. Mỗi hạng tử là tích của $n$ phần tử lấy từ ma trận vuông $A$, sao cho các phần tử đó nằm trên các hàng khác nhau và các cột khác nhau, có dạng $a_{1j_1}a_{2j_2}\cdots a_{nj_n}$.

Dấu đứng trước hạng tử $a_{1j_1}a_{2j_2}\cdots a_{nj_n}$ là ${(-1)}^{\pi(j_1j_2\cdots j_n)}$. Nói cách khác, nếu $j_1j_2\cdots j_n$ là hoán vị chẵn thì dấu là dương, còn nếu là hoán vị lẻ thì dấu là âm.

Quy tắc đường chéo cho định thức bậc hai và bậc ba thực chất chính là dùng định nghĩa bằng hoán vị. Định thức từ bậc bốn trở lên không còn dùng được quy tắc đường chéo cũng vì lý do này. Đặc biệt, định thức bậc một chính là bản thân phần tử đó.

Định lý: Lấy các phần tử từ hàng thứ $i_1,i_2,\cdots,i_n$ và cột thứ $j_1,j_2,\cdots,j_n$ của một định thức bậc $n$, rồi nhân lại:

$$
a_{i_1j_1}a_{i_2j_2}\cdots a_{i_nj_n}
$$

Trong đó $i_1,i_2,\cdots,i_n$ và $j_1,j_2,\cdots,j_n$ đều là các hoán vị của $1,2,\cdots,n$. Khi đó dấu của hạng tử này trong định thức là ${(-1)}^{s+t}$, trong đó

$$
s=\pi(i_1i_2\cdots i_n)
$$

$$
t=\pi(j_1j_2\cdots j_n)
$$

Định lý: Một định thức bằng định thức chuyển vị của nó.

Định lý: Giả sử mọi phần tử ở hàng thứ $i$ của định thức $\det A$ đều có thể viết thành tổng của hai hạng:

$$
\begin{vmatrix}
a_{11} & a_{12} & \cdots & a_{1n}\\
\vdots & \vdots &  & \vdots\\
b_{i1}+c_{i1} & b_{i2}+c_{i2} & \cdots & b_{in}+c_{in}\\
\vdots & \vdots &  & \vdots\\
a_{n1} & a_{n2} & \cdots & a_{nn}\\
\end{vmatrix}
$$

Khi đó định thức này bằng tổng của hai định thức $\det A_1$ và $\det A_2$. Trong đó hàng thứ $i$ của $A_1$ là $b_{i1},b_{i2},\cdots,b_{in}$, hàng thứ $i$ của $A_2$ là $c_{i1},c_{i2},\cdots,c_{in}$, còn các hàng khác của $A_1$ và $A_2$ đều giống $A$. Tính chất tương tự cũng đúng với cột.

<span id="định-nghĩa-bằng-quy-nạp"></span>
## Định nghĩa bằng quy nạp

Cách này chỉ mô tả một tính chất đại số của định thức; độ phức tạp thời gian cũng ở cấp giai thừa, nên không phù hợp để tính toán.

<span id="phần-bù-đại-số"></span>
### Phần bù đại số

Trong định thức bậc $n$ $\det A$, chọn $k$ hàng và $k$ cột bất kỳ của ma trận $A$. Các phần tử nằm tại giao của những hàng và cột này tạo thành một ma trận con bậc $k$, và định thức của nó được gọi là một định thức con bậc $k$.

Với định thức bậc $n$ $\det A$, ma trận phụ $M_{ij}$ của phần tử $a_{ij}$ là ma trận con bậc $n-1$ còn lại sau khi xóa hàng và cột chứa $a_{ij}$ khỏi ma trận gốc $A$; định thức $\det M_{ij}$ của nó được gọi là phần bù.

Với định thức bậc $n$ $\det A$, sau khi gắn dấu ${(-1)}^{i+j}$ cho phần bù $\det M_{ij}$ của phần tử $a_{ij}$, thu được phần bù đại số của phần tử $a_{ij}$, ký hiệu là $A_{ij}$.

Từ định nghĩa bằng hoán vị ở phần trước có thể suy ra kết luận:

Định lý: Nếu trong một định thức bậc $n$ $\det A$, các phần tử ở hàng thứ $i$ hoặc cột thứ $j$ đều bằng $0$ trừ $a_{ij}$, thì định thức đó bằng tích của $a_{ij}$ và phần bù đại số $A_{ij}$ của nó.

<span id="khai-triển-định-thức"></span>
### Khai triển định thức

Vì định thức không đổi khi chuyển vị ma trận vuông, chỉ cần giới thiệu một trong hai cách khai triển theo hàng hoặc theo cột.

Định thức $\det A$ được định nghĩa là tổng các tích giữa mọi phần tử trên một hàng bất kỳ (hoặc một cột bất kỳ) với phần bù đại số tương ứng của chúng.

Nói cách khác, định thức có thể được định nghĩa đệ quy bằng khai triển theo hàng (hoặc theo cột):

$$
\begin{aligned}
\det A &= a_{i1}A_{i1}+a_{i2}A_{i2}+\cdots+a_{in}A_{in} \\
&= \sum_{j = 1}^{n} a_{ij}A_{ij} \\
&= \sum_{j = 1}^{n} (-1)^{i + j} a_{ij} \det M_{ij}
\end{aligned}
$$

$$
\begin{aligned}
\det A &= a_{1j}A_{1j}+a_{2j}A_{2j}+\cdots+a_{nj}A_{nj} \\
&= \sum_{i = 1}^{n} a_{ij}A_{ij} \\
&= \sum_{i = 1}^{n} (-1)^{i + j} a_{ij} \det M_{ij}
\end{aligned}
$$

Điểm dừng của đệ quy là định thức của ma trận bậc một, tức phần tử duy nhất trong ma trận đó.

Từ đó có kết luận:

Định lý: Tổng các tích giữa các phần tử của một hàng (hoặc một cột) của định thức $\det A$ với phần bù đại số tương ứng của một hàng khác (hoặc một cột khác) bằng $0$.

Nói cách khác, khi $i\neq j$:

$$
a_{i1}A_{j1}+a_{i2}A_{j2}+\cdots+a_{in}A_{jn}=0
$$

$$
a_{1i}A_{1j}+a_{2i}A_{2j}+\cdots+a_{ni}A_{nj}=0
$$

<span id="định-nghĩa-tiên-đề-hóa"></span>
## Định nghĩa tiên đề hóa

Định nghĩa tiên đề hóa nói rằng một phép toán thỏa một số tính chất nhất định thì chỉ có thể là định thức.

Kiến thức chuẩn bị: [phép biến đổi sơ cấp](./elementary-operations.md).

Ký hiệu $D_i(k)$ là [ma trận nhân hàng/cột](./elementary-operations.md#ma-trận-nhân-bội), $P_{ij}$ là [ma trận hoán đổi](./elementary-operations.md#ma-trận-hoán-đổi), $T_{ij}(k)$ là [ma trận cộng bội](./elementary-operations.md#ma-trận-cộng-bội).

Với một phép toán $\det$ trên ma trận bậc $n$ $A$, nếu thỏa bốn tính chất sau thì nó được gọi là định thức:

-   Nhân đồng thời mọi phần tử của một hàng hoặc một cột của định thức với một số $k$ thì định thức được nhân với $k$.

    $$
    \det(D_i(k)A) = \det(AD_i(k)) = k \det A
    $$

-   Đổi chỗ hai hàng hoặc hai cột của một định thức làm định thức đổi dấu.

    $$
    \det(P_{ij}A) = \det(AP_{ij}) = -\det A
    $$

-   Nhân các phần tử của một hàng hoặc một cột với cùng một số rồi cộng vào các phần tử tương ứng của hàng hoặc cột khác thì định thức không đổi.

    $$
    \det(T_{ij}(k)A) = \det(AT_{ij}(k))= \det A
    $$

-   Định thức của ma trận đơn vị bằng $1$.

    $$
    \det I = 1
    $$

Dùng các tính chất của định thức đối với biến đổi sơ cấp, có thể tính tay định thức bậc cao thuận tiện hơn. [Tính định thức bằng khử Gauss](../numerical/gauss.md#tính-định-thức) cũng dùng tính chất này, với độ phức tạp thời gian $O(n^3)$.

Các tính chất trên cũng có một số hệ quả:

-   Nhân tử chung của một hàng hoặc một cột trong định thức có thể đưa ra ngoài dấu định thức.
-   Nếu một hàng hoặc một cột của định thức toàn là $0$, thì định thức đó bằng $0$.
-   Nếu một định thức có hai hàng hoặc hai cột có các phần tử tương ứng tỉ lệ với nhau, thì định thức đó bằng $0$.
-   Nếu một định thức có hai hàng hoặc hai cột hoàn toàn giống nhau, thì định thức đó bằng $0$.

Các hệ quả này được dùng rất thường xuyên khi tính định thức bằng tay.
