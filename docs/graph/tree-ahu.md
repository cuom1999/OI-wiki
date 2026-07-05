author: Backl1ght

Thuật toán AHU được dùng để xác định hai cây có gốc có đẳng cấu hay không.

Ngoài AHU, một cách phổ biến khác để kiểm tra đẳng cấu cây là [băm cây](tree-hash.md).

Kiến thức cần có: [kiến thức cơ bản về cây](tree-basic.md), [trọng tâm của cây](tree-centroid.md).

Nên đọc kèm các ví dụ trong phần tài liệu tham khảo.

## Định nghĩa đẳng cấu cây

### Đẳng cấu cây có gốc

Với hai cây có gốc $T_1(V_1,E_1,r_1)$ và $T_2(V_2,E_2,r_2)$, nếu tồn tại một song ánh $\varphi: V_1 \rightarrow V_2$ sao cho

$$
\forall u,v \in V_1,(u,v) \in E_1 \iff (\varphi(u),\varphi(v))  \in E_2
$$

**và** $\varphi(r_1)=r_2$, thì ta nói hai cây có gốc $T_1(V_1,E_1,r_1)$ và $T_2(V_2,E_2,r_2)$ đẳng cấu.

### Đẳng cấu cây không gốc

Với hai cây không gốc $T_1(V_1,E_1)$ và $T_2(V_2,E_2)$, nếu tồn tại một song ánh $\varphi: V_1 \rightarrow V_2$ sao cho

$$
\forall u,v \in V_1,(u,v) \in E_1 \iff (\varphi(u),\varphi(v))  \in E_2
$$

thì ta nói hai cây không gốc $T_1(V_1,E_1)$ và $T_2(V_2,E_2)$ đẳng cấu.

Nói đơn giản, nếu có thể đánh nhãn lại toàn bộ các đỉnh của cây $T_1$ để $T_1$ và $T_2$ **hoàn toàn giống nhau**, thì hai cây đó được gọi là đẳng cấu.

## Chuyển hóa bài toán

Bài toán đẳng cấu cây không gốc có thể chuyển thành bài toán đẳng cấu cây có gốc. Cách làm cụ thể như sau:

Với hai cây không gốc $T_1(V_1, E_1)$ và $T_2(V_2,E_2)$, trước hết tìm **tất cả** các trọng tâm của từng cây.

-   Nếu số lượng trọng tâm của hai cây không gốc khác nhau, thì hai cây không đẳng cấu.
-   Nếu mỗi cây không gốc đều có đúng $1$ trọng tâm, lần lượt ký hiệu là $c_1$ và $c_2$, thì nếu cây có gốc $T_1(V_1,E_1,c_1)$ và cây có gốc $T_2(V_2,E_2,c_2)$ đẳng cấu, hai cây không gốc $T_1(V_1, E_1)$ và $T_2(V_2,E_2)$ cũng đẳng cấu. Ngược lại, chúng không đẳng cấu.
-   Nếu mỗi cây không gốc đều có đúng $2$ trọng tâm, lần lượt ký hiệu là $c_1,c'_1$ và $c_2,c'_2$, thì nếu cây có gốc $T_1(V_1,E_1,c_1)$ và cây có gốc $T_2(V_2,E_2,c_2)$ đẳng cấu **hoặc** cây có gốc $T_1(V_1,E_1,c'_1)$ và $T_2(V_2,E_2,c_2)$ đẳng cấu, hai cây không gốc $T_1(V_1, E_1)$ và $T_2(V_2,E_2)$ đẳng cấu. Ngược lại, chúng không đẳng cấu.

Vì vậy, chỉ cần giải được bài toán đẳng cấu cây có gốc, ta có thể chuyển bài toán đẳng cấu cây không gốc thành bài toán đẳng cấu cây có gốc theo cách trên, từ đó giải bài toán đẳng cấu cây không gốc.

Giả sử có một thuật toán giải bài toán đẳng cấu cây có gốc trong $O(\left|V\right|)$, thì theo cách trên ta cũng có thể giải bài toán đẳng cấu cây không gốc trong thời gian $O(\left|V\right|)$.

## Thuật toán AHU đơn giản

Thuật toán AHU đơn giản dựa trên dãy ngoặc.

### Nguyên lý 1

Ta biết rằng một dãy ngoặc hợp lệ tương ứng duy nhất với một cây có gốc, và dãy ngoặc của một cây được tạo bằng cách nối các dãy ngoặc của những cây con của nó. Nếu ta thay đổi thứ tự nối các dãy ngoặc của cây con để thu được một dãy ngoặc mới, thì cây tương ứng với dãy ngoặc mới đẳng cấu với cây tương ứng với dãy ngoặc ban đầu.

### Nguyên lý 2

Quan hệ đẳng cấu của cây có tính bắc cầu. Tức là nếu $T_1$ đẳng cấu với $T_2$, và $T_2$ đẳng cấu với $T_3$, thì $T_1$ đẳng cấu với $T_3$.

### Hệ quả

Xét thuật toán đệ quy để tính dãy ngoặc của cây: khi quay lui, ta nối các dãy ngoặc của cây con. Nếu khi nối, ta đặt các dãy có thứ tự từ điển nhỏ hơn lên trước, và ký hiệu kết quả cuối cùng là $NAME$.

Lấy $NAME$ của cây con gốc tại đỉnh $r$ làm $NAME$ của đỉnh $r$, ký hiệu là $NAME(r)$. Khi đó với hai cây có gốc $T_1(V_1,E_1,r_1)$ và $T_2(V_2,E_2,r_2)$, nếu $NAME(r_1)=NAME(r_2)$, thì $T_1$ và $T_2$ đẳng cấu.

### Thuật toán đặt tên

???+ note "Cài đặt"
    $$
    \begin{array}{ll}
    1 & \textbf{Đầu vào. } \text{Một cây có gốc }T\\
    2 & \textbf{Đầu ra. } \text{Tên của cây có gốc }T\\
    3 & \text{ASSIGN-NAME(u)}\\
    4 & \qquad \text{nếu } u \text{ là lá}\\
    5 & \qquad \qquad \text{NAME(} u \text{) = (0)}\\
    6 & \qquad \text{ngược lại }\\
    7 & \qquad \qquad \text{với mọi con } v \text{ của } u\\
    8 & \qquad \qquad \qquad \text{ASSIGN-NAME(}v\text{)}\\
    9 & \qquad \text{sắp xếp tên của các con của }u\\
    10 & \qquad \text{nối tên của mọi con của }u\text{ vào temp}\\
    11 & \qquad \text{NAME(} u \text{) = (temp)}
    \end{array}
    $$

### Thuật toán AHU

???+ note "Cài đặt"
    $$
    \begin{array}{ll}
    1 & \textbf{Đầu vào. } \text{Hai cây có gốc }T_1(V_1,E_1,r_1)\text{ và }T_2(V_2,E_2,r_2) \\
    2 & \textbf{Đầu ra. } \text{Hai cây có đẳng cấu hay không}\\
    3 & \text{AHU}(T_1(V_1,E_1,r_1), T_2(V_2,E_2,r_2))\\
    4 & \qquad \text{ASSIGN-NAME(}r_1\text{)}\\
    5 & \qquad \text{ASSIGN-NAME(}r_2\text{)}\\
    6 & \qquad \text{nếu NAME}(r_1) = \text{NAME}(r_2)\\
    7 & \qquad \qquad \text{trả về true}\\
    8 & \qquad \text{ngược lại}\\
    10 & \qquad \qquad \text{trả về false}
    \end{array}
    $$

### Chứng minh độ phức tạp

Với một cây có gốc gồm $n$ đỉnh, giả sử cây có dạng một đường thẳng, thì độ dài tên của một đỉnh có thể lớn nhất là $n$. Khi đó độ phức tạp của thuật toán ASSIGN-NAME là một hằng số nhân với $1+2+\cdots+n$, tức $\Theta(n^2)$. Do đó, độ phức tạp của thuật toán AHU đơn giản là $O(n^2)$.

## Thuật toán AHU tối ưu hóa

Nhược điểm của thuật toán AHU đơn giản là độ dài $NAME$ của cây có thể quá lớn, nên ta có thể tối ưu ở điểm này.

### Nguyên lý 1

Chia cây thành các tầng: đỉnh ở tầng thứ $i$ có khoảng cách ngắn nhất tới gốc bằng $i$. $NAME$ của một đỉnh ở tầng thứ $i$ có thể được tạo **chỉ** bằng cách nối $NAME$ của các đỉnh ở tầng thứ $i+1$.

### Nguyên lý 2

Trong cùng một tầng, $NAME$ của một đỉnh có thể được biểu diễn duy nhất bằng thứ hạng của nó trong tầng đó.

**Lưu ý**, thứ hạng ở đây được xét trên cả hai cây. Giả sử đỉnh $u$ nằm ở tầng thứ $i$, thì thứ hạng của đỉnh $u$ bằng số đỉnh ở tầng thứ $i$ của cả $T_1$ và $T_2$ có $NAME$ nhỏ hơn $NAME(u)$.

### Hệ quả

Ta có thể thay $NAME$ ban đầu của một đỉnh bằng thứ hạng của nó trong tầng, rồi thay thao tác nối các $NAME$ của đỉnh bằng thao tác thêm phần tử vào mảng.

Cách dùng số nguyên và mảng để thay thế chuỗi này không ảnh hưởng đến tính đúng đắn của thuật toán, đồng thời giảm đáng kể độ phức tạp.

### Chứng minh độ phức tạp

Trước hết, nhận thấy tổng độ dài của các $NAME$ được tạo bằng phép nối ở tầng thứ $i$ bằng tổng bậc của các đỉnh ở tầng thứ $i$, tức tổng số đỉnh ở tầng thứ $i+1$; dưới đây ký hiệu là $L_i$. Bước tiếp theo của thuật toán sẽ xem các $NAME$ này như chuỗi (mảng) rồi sắp xếp, sau đó thay chúng bằng thứ hạng trong tầng (tức ánh xạ lại thành một số). Các bổ đề sau cho biết độ phức tạp khi sắp xếp $m$ chuỗi có tổng độ dài là $L$:

1.  Có thể dùng sắp xếp cơ số để hoàn thành việc sắp xếp trong $O(L+|\Sigma|)$, trong đó $|\Sigma|$ là kích thước bảng chữ cái. Có một số chi tiết cài đặt, xem phần tài liệu tham khảo.
2.  Có thể dùng quicksort để hoàn thành việc sắp xếp trong $O(L \log m)$. Ý tưởng chứng minh đại khái là chiều cao của cây đệ quy quicksort là $O(\log m)$, và độ phức tạp khi so sánh trực tiếp hai chuỗi có độ dài $\ell_1$ và $\ell_2$ là $O(\min\{\ell_1,\ell_2\})$.

Trong thuật toán AHU, kích thước bảng chữ cái của các chuỗi ở tầng thứ $i$ nhiều nhất bằng số đỉnh ở tầng thứ $i+1$, tức $L_i$, nên độ phức tạp của sắp xếp cơ số là tuyến tính. Từ $\sum_i L_i=O(n)$, cộng độ phức tạp của từng tầng lại, ta thấy nếu dùng sắp xếp cơ số cho chuỗi thì tổng độ phức tạp của thuật toán là $T(n)=O(n)$. Tương tự, nếu dùng quicksort để sắp xếp chuỗi, thì $T(n)=O(n \log n)$.

## Bài tập ví dụ

[SPOJ-TREEISO](https://www.spoj.com/problems/TREEISO/en/)

Dịch đề: Cho hai cây không gốc, hãy xác định hai cây đó có đẳng cấu hay không.

???+ note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-ahu/tree-ahu_1.cpp"
    ```

## Tài liệu tham khảo

Phần lớn nội dung bài viết này được dịch từ [Paper](http://wwwmayr.in.tum.de/konferenzen/Jass08/courses/1/smal/Smal_Paper.pdf) và [Slide](https://logic.pdmi.ras.ru/~smal/files/smal_jass08_slides.pdf). Các chứng minh trong tài liệu tham khảo đầy đủ và chặt chẽ hơn; bài viết này đã lược giản một phần.

Về phân tích độ phức tạp của thuật toán AHU, cũng như thuật toán sắp xếp cơ số tuyến tính cho chuỗi, có thể tham khảo mục 3.2 Sắp xếp cơ số và Ví dụ 3.2 trong *The Design and Analysis of Computer Algorithms*.
