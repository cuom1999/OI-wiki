Cây AA là một cấu trúc cây cân bằng dùng để lưu trữ và truy xuất dữ liệu có thứ tự một cách hiệu quả. Giáo sư Arne Andersson giới thiệu cấu trúc này vào năm 1993 trong bài báo "Balanced search trees made simple", với mục tiêu giảm số trường hợp cần xét so với cây đỏ-đen. Cây AA có thể thực hiện tìm kiếm, chèn và xóa trong thời gian $O(\log N)$. Dưới đây là một ví dụ về cây AA.

![Ví dụ cây AA](images/aa-tree-1.jpg)

Cây AA là một biến thể của cây đỏ-đen. Khác với cây đỏ-đen, trong cây AA, nút đỏ chỉ được xuất hiện dưới dạng con phải. Điều này khiến cây AA mô phỏng cây 2-3 thay vì cây 2-3-4, qua đó đơn giản hóa đáng kể các thao tác duy trì cân bằng. Thuật toán duy trì cân bằng của cây đỏ-đen cần xét bảy trường hợp khác nhau để cân bằng cây một cách chính xác.

![Cây đỏ-đen tương ứng](images/aa-tree-2.svg)

Vì nút đỏ chỉ có thể là con phải, cây AA chỉ cần xét hai trường hợp.

![Cây AA tương ứng](images/aa-tree-3.svg)

## Định nghĩa

Cây AA tuân theo các quy tắc giống cây đỏ-đen, nhưng bổ sung thêm một quy tắc mới: **nút đỏ không được xuất hiện dưới dạng con trái**.

1.  Mỗi nút có thể là đỏ hoặc đen.
2.  Nút gốc luôn là nút đen.
3.  Nút lá (NULL) luôn là nút đen.
4.  Hai nút con của một nút đỏ đều phải là nút đen, tức là không có hai nút đỏ kề nhau.
5.  Mọi đường đi từ nút gốc đến nút NULL đều có cùng số lượng nút đen.
6.  Nút đỏ chỉ có thể là con phải.

## Duy trì cân bằng

Mỗi nút của cây AA duy trì một trường **mức** (`level`), tương tự như mỗi nút của cây đỏ-đen duy trì một trường màu (`color`, "RED" hoặc "BLACK"). Quy định về mức phải thỏa mãn 5 điều kiện sau:

1.  Mức của mỗi nút lá là 1.

2.  Mức của mỗi con trái bằng mức của nút cha trừ 1.

3.  Mức của mỗi con phải bằng mức của nút cha hoặc bằng mức của nút cha trừ 1.

4.  Mức của mỗi cháu phải phải nhỏ hơn nghiêm ngặt mức của nút ông.

5.  Mỗi nút có mức lớn hơn 1 đều có hai con.

![Mức trong cây AA](images/aa-tree-4.jpg)

### Liên kết ngang

Liên kết mà mức của nút con bằng mức của nút cha được gọi là **liên kết ngang**, tương tự liên kết đỏ trong cây đỏ-đen. Một liên kết ngang bên phải đơn lẻ được cho phép, nhưng các liên kết ngang bên phải liên tiếp thì không; liên kết ngang bên trái cũng không được phép. Những ràng buộc này chặt hơn các ràng buộc của cây đỏ-đen, vì vậy quy trình cân bằng cây AA đơn giản hơn nhiều về mặt cài đặt so với cây đỏ-đen.

![Liên kết ngang trong cây AA](images/aa-tree-5.jpg)

Các thao tác chèn và xóa có thể tạm thời làm cây AA mất cân bằng, tức là vi phạm các bất biến của cây AA. Để khôi phục cân bằng, chỉ cần hai thao tác khác nhau: **nghiêng** (xoay phải để loại bỏ liên kết ngang bên trái) và **tách** (xoay trái và tăng mức để xử lý các liên kết ngang bên phải liên tiếp). Thao tác nghiêng xoay phải một cây con có liên kết ngang bên trái để thay bằng một cây con có liên kết ngang bên phải. Thao tác tách xoay trái và tăng mức để thay một cây con có từ hai liên kết ngang bên phải liên tiếp trở lên bằng một cây con có ít liên kết ngang bên phải liên tiếp hơn. Việc cài đặt chèn và xóa có duy trì cân bằng trở nên đơn giản hơn nhờ dựa vào hai thao tác nghiêng và tách để chỉ chỉnh sửa cây khi cần, thay vì để phía gọi tự quyết định có thực hiện thao tác nào hay không.

### Tách (xoay trái)

Xuất hiện một chuỗi liên kết ngang liên tiếp sang phải, tức là ba nút liên tiếp theo hướng con phải cùng thuộc một mức; nút R và nút X đều là nút đỏ.

Khi đó xoay trái nút *T*, xem các nút có mức nhỏ hơn hoặc bằng mức này là một cây con.

1.  Con phải của gốc cây con trở thành gốc mới của cây con;
2.  Gốc cũ của cây con trở thành con trái của gốc mới;
3.  Mức của gốc mới tăng thêm 1.

![Thao tác tách trong cây AA](images/aa-tree-split.svg)

???+ note "Cài đặt giả mã"
    $$
    \begin{array}{ll}
    1 & \textbf{hàm } \text{split}(\text{root}) \\
    2 & \qquad \textbf{nếu } \text{root}\rightarrow\text{right}\rightarrow\text{right}\rightarrow\text{level} == \text{root}\rightarrow\text{level} \\
    3 & \qquad\qquad \text{rotate\_left}(\text{root}) \\
    4 & \textbf{kết thúc hàm}
    \end{array}
    $$

### Nghiêng (xoay phải)

Xuất hiện một liên kết ngang sang trái, tức là hai nút liên tiếp theo hướng con trái cùng thuộc một mức.

Xoay phải nút *T*, xem các nút có mức nhỏ hơn hoặc bằng mức này là một cây con.

1.  Con trái của gốc cây con trở thành gốc mới của cây con;
2.  Gốc cũ của cây con trở thành con phải của gốc mới.

![Thao tác nghiêng trong cây AA](images/aa-tree-skew.svg)

???+ note "Cài đặt giả mã"
    $$
    \begin{array}{ll}
    1 & \textbf{hàm } \text{skew}(\text{root}) \\
    2 & \qquad \textbf{nếu } \text{root}\rightarrow\text{left}\rightarrow\text{level} == \text{root}\rightarrow\text{level} \\
    3 & \qquad\qquad \text{rotate\_right}(\text{root}) \\
    4 & \textbf{kết thúc hàm}
    \end{array}
    $$

## Các thao tác trên cây AA

Bản thân cây AA là một cây tìm kiếm nhị phân, nên thao tác tìm kiếm giống như trên các cây tìm kiếm nhị phân khác. Thao tác chèn và xóa giống cây *AVL*: trước hết chèn hoặc xóa key trong cây, sau đó lần ngược theo đường tìm kiếm về nút gốc và tái cấu trúc cây trong quá trình đó.

### Chèn

???+ note "Cài đặt giả mã"
    $$
    \begin{array}{ll}
    1 & \textbf{hàm } \text{insert}(\text{root}, \text{add}) \\
    2 & \qquad \textbf{nếu } \text{root} == \text{NULL} \\
    3 & \qquad\qquad \text{root} \gets \text{add} \\
    4 & \qquad \textbf{ngược lại nếu } \text{add}\rightarrow\text{key} < \text{root}\rightarrow\text{key} \qquad // \text{nếu cho phép phần tử trùng lặp thì dùng } <= \\
    5 & \qquad\qquad \text{insert}(\text{root}\rightarrow\text{left}, \text{add}) \\
    6 & \qquad \textbf{ngược lại nếu } \text{add}\rightarrow\text{key} > \text{root}\rightarrow\text{key} \\
    7 & \qquad\qquad \text{insert}(\text{root}\rightarrow\text{right}, \text{add}) \\
    8 & \qquad \textbf{kết thúc nếu} \\
    9 & \qquad \text{// nếu không cho phép phần tử trùng lặp, thực hiện skew và split ở mỗi mức} \\
    10 & \qquad \text{skew}(\text{root}); \\
    11 & \qquad \text{split}(\text{root}); \\
    12 & \textbf{kết thúc hàm}
    \end{array}
    $$

### Xóa

Quá trình xóa tương tự các cây cân bằng nhị phân khác: trước hết chuyển việc xóa một nút trong thành việc xóa một nút lá. Cách làm cụ thể là thay nút trong bằng nút tiền nhiệm hoặc nút kế nhiệm gần nhất của nó. Vì mọi nút trong cây AA có mức lớn hơn 1 đều có hai nút con, nút tiền nhiệm hoặc kế nhiệm sẽ nằm ở mức 1, nên việc xóa một nút mức 1 tương đối đơn giản.

???+ note "Cài đặt giả mã"
    $$
    \begin{array}{ll}
    1 &  \text{// Tái cân bằng cây} \\
    2 &  \textbf{nếu} \ \text{root->left->level} < \text{root->level} -1 \ \textbf{hoặc} \ \text{root->right->level} < \text{root->level} -1 \\
    3 &  \{ \\
    4 & \qquad \textbf{nếu} \ \text{root->right->level} > \text{--root->level} \\
    5 & \qquad \{ \\
    6 & \qquad\qquad \text{root->right->level} \gets \text{root->level} \\
    7 & \qquad \} \\
    8 & \qquad \text{skew}(\text{root}) \\
    9 & \qquad \text{skew}(\text{root->right}) \\
    10 & \qquad \text{skew}(\text{root->right->right}) \\
    11 & \qquad \text{split}(\text{root}) \\
    12 & \qquad \text{split}(\text{root->right}) \\
    13 &  \} \\
    \end{array}
    $$

## Hiệu năng

Hiệu năng của cây AA tương đương cây đỏ-đen. Tuy cây AA thực hiện nhiều phép xoay hơn cây đỏ-đen, thuật toán của cây AA đơn giản hơn, nên cuối cùng vẫn cho hiệu năng xấp xỉ. Hiệu năng của cây đỏ-đen ổn định hơn trong nhiều tình huống, còn cây AA thường phẳng hơn, giúp thao tác tìm kiếm trên cây AA nhanh hơn đôi chút.

## Tài liệu tham khảo

1.  [AA tree - Wikipedia](https://en.wikipedia.org/wiki/AA_tree)
2.  [Introduction to AA trees](https://iq.opengenus.org/aa-trees/)
3.  [AA tree - Visualization](https://kubokovac.eu/gnarley-trees/AAtree.html)
4.  [CMSC 420 Lecture 6: 2-3, Red-black, and AA trees](https://www.cs.umd.edu/class/fall2019/cmsc420-0201/Lects/lect06-aa.pdf)
