Cây AVL là một loại cây tìm kiếm nhị phân cân bằng. Do nhiều giáo trình thuật toán trình bày AVL khá dài dòng, không ít
người có ấn tượng rằng cây AVL phức tạp và thiếu thực dụng. Tuy vậy, nguyên lý của cây AVL đơn giản, cách cài đặt cũng
không quá phức tạp.

## Tính chất

1.  Cây nhị phân rỗng là một cây AVL.
2.  Nếu T là một cây AVL, thì cây con trái và cây con phải của nó cũng là cây AVL, đồng thời
    $|h(ls) - h(rs)| \leq 1$, trong đó $h$ là chiều cao của cây con trái/phải tương ứng.
3.  Chiều cao của cây là $O(\log n)$.

Hệ số cân bằng được định nghĩa là: chiều cao cây con phải trừ chiều cao cây con trái.

???+ note "Chứng minh chiều cao của cây"
    Gọi $f_n$ là số nút ít nhất trong một cây AVL có chiều cao $n$, có:

    $$
    f_n=
    \begin{cases}
    1&(n=1)\\
    2&(n=2)\\
    f_{n-1}+f_{n-2}+1& (n>2)
    \end{cases}
    $$

    Theo cách giải phương trình sai phân tuyến tính không thuần nhất với hệ số hằng, $\{f_n+1\}$ là một dãy Fibonacci.
    Công thức tổng quát của $f_n$ là:

    $$
    f_n=\frac{5+2\sqrt{5}}{5}\left(\frac{1+\sqrt{5}}{2}\right)^n+\frac{5-2\sqrt{5}}{5}\left(\frac{1-\sqrt{5}}{2}\right)^n-1
    $$

    Dãy Fibonacci tăng theo tốc độ hàm mũ. Với chiều cao cây $n$, có:

    $$
    n<\log_{\frac{1+\sqrt{5}}{2}} (f_n+1)<\frac{3}{2}\log_2 (f_n+1)
    $$

    Vì vậy chiều cao của cây AVL là $O(\log f_n)$, trong đó $f_n$ là số nút.

## Quy trình

### Chèn nút

Tương tự cây tìm kiếm nhị phân (BST), trước hết thực hiện một lần tìm kiếm thất bại để xác định vị trí chèn. Sau khi
chèn nút, dựa vào hệ số cân bằng để quyết định có cần điều chỉnh hay không.

### Xóa nút

Thao tác xóa tương tự cây tìm kiếm nhị phân: hoán đổi nút cần xóa với nút kế nhiệm của nó rồi xóa.

Việc xóa có thể làm thay đổi chiều cao cây và hệ số cân bằng. Khi đó cần điều chỉnh dọc theo đường đi từ nút bị xóa đến
gốc.

### Duy trì cân bằng

Sau khi chèn hoặc xóa nút, tính chất 2 của cây AVL có thể bị phá vỡ. Vì vậy cần duy trì cây dọc theo đường đi từ nút
vừa được chèn/xóa đến gốc. Nếu tại một nút nào đó, tính chất 2 không còn thỏa mãn, do chỉ chèn/xóa một nút nên ảnh
hưởng đến chiều cao cây không vượt quá 1; vì thế trị tuyệt đối của hệ số cân bằng tại nút đó nhiều nhất là 2.

Do tính đối xứng, chỉ xét trường hợp cây con trái cao hơn cây con phải 2 đơn vị, tức $h(B)-h(E)=2$ trong hình dưới. Khi
đó còn cần chia hai trường hợp theo quan hệ lớn nhỏ giữa $h(A)$ và $h(C)$. Vì quá trình duy trì cân bằng đi từ dưới lên
trên, với mọi hậu duệ của nút D, tính chất 2 vẫn đang được thỏa mãn.

![](./images/avl1.svg)

#### Trường hợp 1: chiều cao cây tại A không nhỏ hơn chiều cao cây tại C

Giả sử $h(E)=x$, có:

$$
\begin{cases}
    h(B)=x+2\\
    h(A)=x+1\\
    x\leq h(C)\leq x+1
\end{cases}
$$

Trong đó $h(C)\geq x$ là vì nút B thỏa mãn tính chất 2, nên độ chênh giữa $h(C)$ và $h(A)$ không vượt quá 1. Lúc này
thực hiện một phép xoay phải trên nút D (thao tác xoay giống như trong các loại cây tìm kiếm nhị phân cân bằng khác),
như hình dưới.

![](./images/avl2.svg)

Chiều cao của các nút A, C, E không thay đổi, đồng thời có:

$$
\begin{cases}
    0\leq h(C)-h(E)\leq 1\\
    x+1\leq h'(D)=\max(h(C),h(E))+1=h(C)+1\leq x+2\\
    0\leq h'(D)-h(A)\leq 1
\end{cases}
$$

Vì vậy sau phép xoay, các nút B và D đều thỏa mãn tính chất 2.

#### Trường hợp 2: chiều cao cây tại A nhỏ hơn chiều cao cây tại C

Giả sử $h(E)=x$, tương tự như trên, có:

$$
\begin{cases}
    h(B)=x+2\\
    h(C)=x+1\\
    h(A)=x
\end{cases}
$$

Lúc này trước hết thực hiện một phép xoay trái trên nút B, rồi thực hiện một phép xoay phải trên nút D, như hình dưới.

![](./images/avl3.svg)

Chiều cao của các nút A và E không thay đổi. Ngoài ra, con phải mới của B và con trái mới của D lần lượt là con trái và
con phải ban đầu của C, nên có:

$$
\begin{cases}
    x-1\leq h'(rs_B),h'(ls_D)\leq x\\
    0\leq h(A)-h'(rs_B)\leq 1\\
    0\leq h(E)-h'(ls_D)\leq 1\\
    h'(B)=\max(h(A),h'(rs_B))+1=x+1\\
    h'(D)=\max(h(E),h'(ls_D))+1=x+1\\
    h'(B)-h'(D)=0
\end{cases}
$$

Vì vậy sau các phép xoay, các nút B, C, D đều thỏa mãn tính chất 2.

???+ note "Thao tác duy trì cân bằng: mã giả"
    $$
    \begin{array}{ll}
    1 &  \textbf{hàm } \mathrm{MaintainBalance}(p) \\
    2 &  \qquad l \gets ls_p, r \gets rs_p \\
    3 &  \qquad \textbf{nếu } h(l)-h(r)=2 \\
    4 &  \qquad\qquad \textbf{nếu } h(ls_l) \ge h(rs_l) \\
    5 &  \qquad\qquad\qquad \mathrm{RightRotate}(p) \\
    6 &  \qquad\qquad \textbf{ngược lại} \\
    7 &  \qquad\qquad\qquad \mathrm{LeftRotate}(l) \\
    8 &  \qquad\qquad\qquad \mathrm{RightRotate}(p) \\
    9 &  \qquad \textbf{ngược lại nếu } h(l)-h(r)=-2 \\
    10 &  \qquad\qquad \textbf{nếu } h(ls_r) \le h(rs_r) \\
    11 &  \qquad\qquad\qquad \mathrm{LeftRotate}(p) \\
    12 &  \qquad\qquad \textbf{ngược lại} \\
    13 &  \qquad\qquad\qquad \mathrm{RightRotate}(r) \\
    14 &  \qquad\qquad\qquad \mathrm{LeftRotate}(p) \\
    \end{array}
    $$

Giống như các cây tìm kiếm nhị phân cân bằng khác, các thông tin như chiều cao nút, kích thước cây con trong cây AVL cần
được cập nhật khi xoay.

## Các thao tác khác

Các thao tác khác trên cây AVL (Predecessor, Successor, Select, Rank, v.v.) giống như trên cây tìm kiếm nhị phân thông
thường.

## Mã tham khảo

Đoạn mã dưới đây cài đặt `Map` bằng cây AVL, tức một ánh xạ có thứ tự, không cho phép khóa trùng:

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/avl-tree/AvlTreeMap.hpp"
    ```

## Tài liệu khác

Có thể quan sát quá trình duy trì cân bằng của cây AVL tại
[AVL Tree Visualization](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html).

[Wikipedia -- AVL tree](https://en.wikipedia.org/wiki/AVL_tree)
