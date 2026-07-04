author: Ir1d, YZircon, huhaoo, QAQAutoMaton, Enter-tainer, Marcythm, sshwy, partychicken, Konano, H-J-Granger, baker221, isdanni, ksyx

<span id="&#24341;&#20837;"></span>
## Mở đầu

Quy hoạch tuyến tính (linear programming, LP) là tên gọi chung cho các phương pháp nghiên cứu bài toán tối ưu một hàm mục tiêu tuyến tính dưới các ràng buộc tuyến tính. Đây là một nhánh của vận trù học và có ứng dụng trong nhiều lĩnh vực. Một số trường hợp đặc biệt của quy hoạch tuyến tính, chẳng hạn như luồng mạng và luồng đa hàng hóa, có thể xuất hiện trong các bài toán thi lập trình. Trong thi thuật toán, hiếm khi có bài toán chỉ có thể giải bằng thuật toán quy hoạch tuyến tính; phần lớn các bài toán kiểu này có thể được mô hình hóa bằng luồng mạng hoặc các phương pháp chuyên biệt khác để giải hiệu quả hơn.

<span id="&#19968;&#20010;&#31616;&#21333;&#30340;&#20363;&#23376;"></span>
### Một ví dụ đơn giản

Để một bài toán có thể viết dưới dạng quy hoạch tuyến tính, nó cần có một số ràng buộc tuyến tính và một hàm mục tiêu tuyến tính.

Xét ví dụ sau:

???+ example "Ví dụ"
    Mỗi ngày một người bán bữa sáng có thể làm một số lượng bánh bao và quẩy nhất định; hai món này đều được khách hàng ưa chuộng. Để tối đa hóa lợi nhuận, người bán muốn làm càng nhiều càng tốt, nhưng trong thực tế bị giới hạn bởi nguyên liệu, thời gian và các tài nguyên khác. Người bán thống kê lượng nguyên liệu, thời gian chế biến và lợi nhuận tương ứng của mỗi phần như bảng sau:
    
    | Bữa sáng | Dầu thực vật | Bột mì | Thời gian | Lợi nhuận |
    | :-: | :-: | :-: | :-: | :-: |
    | Bánh bao | $4$ | $7$ | $8$ | $5$ |
    | Quẩy | $7$ | $3$ | $6$ | $6$ |
    
    Giả sử mỗi ngày người bán mua được nhiều nhất $66$ đơn vị dầu thực vật và $60$ đơn vị bột mì, đồng thời chỉ có thể dành nhiều nhất $96$ đơn vị thời gian chế biến. Vậy nên sắp xếp số lượng bánh bao và quẩy như thế nào để lợi nhuận hằng ngày lớn nhất?

Dùng ngôn ngữ toán học, đặt $x_1$ và $x_2$ lần lượt là số lượng bánh bao và quẩy được làm. Khi đó, điều kiện "tổng lượng dầu thực vật cần dùng không vượt quá $66$ đơn vị" có thể viết là

$$
4x_1 + 7x_2 \le 66.
$$

Tương tự, "tổng lượng bột mì không vượt quá $60$ đơn vị" và "tổng thời gian không vượt quá $96$ đơn vị" có thể viết là

$$
\begin{aligned}
7x_1 + 3x_2 &\le 60,\\
8x_1 + 6x_2 &\le 96.
\end{aligned}
$$

Ngoài ra, người bán không thể sản xuất số lượng bữa sáng âm, nên còn có điều kiện

$$
x_1,x_2\ge 0.
$$

Mục tiêu là tối đa hóa lợi nhuận dưới các ràng buộc này:

$$
z = 5x_1 + 6x_2.
$$

Đây là một bài toán quy hoạch tuyến tính điển hình. Hàm mục tiêu là một hàm tuyến tính theo các biến quyết định, còn các ràng buộc là các đẳng thức hoặc bất đẳng thức tuyến tính tạo bởi các biến quyết định.

<span id="&#22270;&#35299;&#27861;"></span>
### Phương pháp đồ thị

Với bài toán quy hoạch tuyến tính chỉ có hai biến quyết định, ta có thể giải trực quan bằng phương pháp đồ thị.

Xét bài toán trong phần này:

$$
\begin{aligned}
\max_{x_1,x_2}\;& z = 5x_1 + 6x_2 \\
\text{subject to } & 4x_1 + 7x_2 \le 66,\\
& 7x_1 + 3x_2 \le 60,\\
& 8x_1 + 6x_2 \le 96,\\
& x_1,x_2\ge 0
\end{aligned}
$$

Hình học tương ứng như sau. Ràng buộc ở dòng cuối nói rằng các điểm có thể chọn $(x_1,x_2)$ đều nằm trong góc phần tư thứ nhất; ba ràng buộc còn lại nói rằng các điểm có thể chọn phải nằm phía dưới các đường thẳng $4x_1 + 7x_2 = 66$, $7x_1 + 3x_2 = 60$ và $8x_1 + 6x_2 = 96$. Giao của các miền này (miền màu xanh trong hình dưới) chính là tập tất cả các điểm có thể chọn:

![](images/linear-programming.svg)

Tiếp theo cần tối đa hóa giá trị của $z=5x_1+6x_2$. Nếu xem đẳng thức này là phương trình đường thẳng $5x_1+6x_2=z$, thì khi $z$ thay đổi ta thu được một họ đường thẳng song song; $z$ càng lớn thì đường thẳng càng dịch về phía trên bên phải. Vì vậy chỉ cần liên tục dịch đường thẳng đến một vị trí tới hạn, sao cho nếu dịch thêm một chút về phía trên bên phải thì nó không còn giao với miền trong hình nữa. Giá trị $z$ ứng với đường thẳng lúc đó chính là giá trị lớn nhất cần tìm.

Như hình vẽ, tình huống này xảy ra tại điểm đỏ. Đó là giao điểm của hai đường thẳng $4x_1 + 7x_2 = 66$ và $7x_1 + 3x_2 = 60$. Giải hệ hai phương trình đường thẳng cho tọa độ $(6,6)$. Đây là nghiệm tối ưu duy nhất của bài toán. Lợi nhuận lớn nhất của người bán là $z=66$.

Khi bài toán có nhiều hơn hai biến quyết định, phương pháp đồ thị không còn dùng được. Tuy vậy, một số quan sát trong ví dụ này vẫn đúng. Mỗi ràng buộc bất đẳng thức trong bài toán quy hoạch tuyến tính mô tả một "nửa mặt phẳng"; tập các nghiệm khả thi là giao của các "nửa mặt phẳng" đó, nên luôn là một "đa giác lồi". Nghiệm tối ưu của bài toán quy hoạch luôn có thể đạt tại một "đỉnh" nào đó của "đa giác lồi". Tọa độ các "đỉnh" này có thể tìm bằng cách giải hệ phương trình của các "biên" của các "nửa mặt phẳng". Mở rộng các quan sát này lên không gian nhiều chiều sẽ dẫn tới một phương pháp hiệu quả để giải quy hoạch tuyến tính: phương pháp đơn hình. Đây cũng là phương pháp thường được dùng nhất trong thi thuật toán.

Một điểm khác đáng chú ý là về nguyên tắc, số bánh bao và quẩy người bán làm ra không thể chia nhỏ vô hạn mà phải là số nguyên nào đó. Tuy trong quá trình giải bài toán này ta không ràng buộc rõ điều đó, nghiệm tối ưu cuối cùng quả thực là số nguyên, nên đáp án vẫn khả thi ngay cả khi thêm ràng buộc nguyên. Nhưng với nhiều bài toán quy hoạch, nghiệm tối ưu có thể không đạt tại điểm nguyên; những bài toán đó thực chất thuộc lớp quy hoạch nguyên, chứ không phải quy hoạch tuyến tính đơn giản. Cuối bài viết sẽ bàn ngắn gọn về lớp bài toán này.

<span id="&#22522;&#26412;&#27010;&#24565;"></span>
## Khái niệm cơ bản

Phần này giới thiệu các khái niệm cơ bản của quy hoạch tuyến tính.

<span id="&#32447;&#24615;&#35268;&#21010;&#38382;&#39064;"></span>
### Bài toán quy hoạch tuyến tính

Một bài toán quy hoạch tuyến tính $P$ thường gồm hai phần sau:

-   Hàm mục tiêu tuyến tính, tức một hàm có dạng

    $$
    f(x_1,x_2,\cdots,x_n)=c_1x_1+c_2x_2+\cdots+c_nx_n
    $$

    trong đó $c_i\in\mathbf R$ là hằng số;

-   Ràng buộc tuyến tính, tức các ràng buộc bất đẳng thức hoặc đẳng thức có dạng

    $$
    g_j(x_1,x_2,\cdots,x_n)=a_{j1}x_1+a_{j2}x_2+\cdots+a_{jn}x_n \le (=,\ge) b_j
    $$

    trong đó $a_{ji},b_j\in\mathbf R$ đều là hằng số.

Bài toán quy hoạch tuyến tính yêu cầu tối đa hóa hoặc tối thiểu hóa hàm mục tiêu với điều kiện các ràng buộc đã cho được thỏa mãn. Một nghiệm $(x_1,x_2,\cdots,x_n)\in\mathbf R^n$ thỏa mãn các ràng buộc gọi là **nghiệm khả thi** (feasible solution); trong tất cả nghiệm khả thi, nghiệm làm hàm mục tiêu đạt cực trị gọi là **nghiệm tối ưu** (optimal solution).

<span id="&#26631;&#20934;&#24418;&#24335;"></span>
### Dạng chuẩn

Để tiện mô tả và xử lý tiếp, thông thường cần quy định một dạng chuẩn cho bài toán quy hoạch tuyến tính. Các tài liệu khác nhau có thể có quy ước khác nhau; trong bài này, dạng chuẩn của quy hoạch tuyến tính được quy định như sau:

$$
\begin{aligned}
\min_{\{x_i\}}\;& \sum_{i=1}^n c_ix_i \\
\text{subject to }& \sum_{i=1}^n a_{ji}x_i = b_i \ge 0,~j=1,\cdots,m,\\
& x_i \ge 0,~i = 1,\cdots,n.
\end{aligned}
$$

Nói cách khác, bài toán quy hoạch tuyến tính là bài toán tối thiểu hóa, mọi biến quyết định đều có ràng buộc không âm, và ngoài ra chỉ chứa một số ràng buộc đẳng thức có hằng số vế phải không âm. Dùng [ma trận](./linear-algebra/matrix.md), bài toán này có thể được viết gọn hơn:

$$
\max\{c^Tx : Ax = b \ge 0,~ x\ge 0\}.
$$

Ở đây, $x=(x_i)\in\mathbf R^n$ là biến quyết định, $b=(b_j)\in\mathbf R^m$ và $A=(a_{ji})\in\mathbf R^{m\times n}$ là các hằng số xuất hiện trong ràng buộc. Kích thước của một bài toán quy hoạch tuyến tính là số biến quyết định và số ràng buộc của nó.

???+ tip "Bất đẳng thức vector"
    Trong bài này sẽ nhiều lần xuất hiện bất đẳng thức vector như $b \ge 0$. Nói chung, với các vector $x,y\in\mathbf R^n$, bất đẳng thức $x\le y$ nghĩa là $\forall i(x_i\le y_i)$, tức so sánh theo nghĩa số thực trên từng chiều. Quan hệ này là một [quan hệ thứ tự bộ phận](./order-theory.md#%E4%BA%8C%E5%85%83%E5%85%B3%E7%B3%BB) trên không gian vector; vì vậy có thể tồn tại hai vector không so sánh được với nhau.

Việc chọn dạng chuẩn chỉ nhằm thuận tiện cho trình bày, chứ không có gì đặc biệt, vì mọi bài toán quy hoạch tuyến tính đều có thể viết tương đương dưới một trong sáu dạng sau:

$$
\begin{aligned}
&\min\{c^Tx : Ax = b,~ x\ge 0\},\\
&\min\{c^Tx : Ax \ge b\},\\
&\min\{c^Tx : Ax \ge b,~ x\ge 0\},\\
&\max\{c^Tx : Ax = b,~ x\ge 0\}, \\
&\max\{c^Tx : Ax \le b\},\\
&\max\{c^Tx : Ax \le b,~ x\ge 0\}.
\end{aligned}
$$

Các thao tác sau có thể biến mọi bài toán quy hoạch tuyến tính một cách tương đương về một trong sáu dạng trên:

1.  Thêm dấu âm, tức thay $c$ bằng $-c$, để chuyển đổi qua lại giữa bài toán tối đa hóa và tối thiểu hóa.
2.  Thêm dấu âm, tức thay $a_j^Tx \lesseqqgtr b_j$ bằng $-a_j^Tx \gtreqqless -b_j$, để đổi chiều bất đẳng thức, hoặc để biến hằng số vế phải của ràng buộc đẳng thức thành số không âm.
3.  Mọi ràng buộc đẳng thức $a_j^Tx = b_j$ đều có thể thay bằng hai ràng buộc bất đẳng thức ngược chiều $a_j^Tx \ge b_j$ và $a_j^Tx \le b_j$.
4.  Mọi ràng buộc bất đẳng thức $a_j^Tx \le(\ge) b_j$ đều có thể chuyển thành ràng buộc đẳng thức $a_j^Tx +(-) s_j = b_j$ bằng cách thêm biến dư không âm $s_j$, kèm ràng buộc không âm tương ứng $s_j\ge 0$.
5.  Nếu một biến quyết định $x_i$ không có ràng buộc không âm, có thể thay nó bằng hiệu của hai biến không âm, tức $x_j = x^+_j - x^-_j$ với $x^+_j,x^-_j \ge 0$.

Kích thước của bài toán quy hoạch tuyến tính thu được sau các thao tác này không vượt quá hai lần kích thước bài toán ban đầu, và nghiệm khả thi cũng như nghiệm tối ưu của các bài toán này rất dễ chuyển đổi qua lại. Do đó, với bài toán quy hoạch tuyến tính tổng quát, ta luôn có thể trước hết chuyển nó về dạng chuẩn (hoặc một trong sáu dạng trên) rồi mới giải.

??? example "Ví dụ"
    Xét bài toán quy hoạch tuyến tính
    
    $$
    \begin{aligned}
    \max\;& 3x_1 - 2x_2 + x_3 \\
    \text{subject to }& 2x_1 + 3x_2 + 4x_3 \ge 1,\\
    & 3x_1 + 4x_2 \le 5,\\
    & 5x_2 - x_3 = -1, \\
    & x_1, x_2 \ge 0.
    \end{aligned}
    $$
    
    Dùng các thao tác 1, 2 và 3, có thể chuyển nó về dạng $\min\{c^Tx : Ax \ge b\}$, tức
    
    $$
    \begin{aligned}
    \min\;& -3x_1 + 2x_2 - x_3 \\
    \text{subject to }& 2x_1 + 3x_2 + 4x_3 \ge 1,\\
    & -3x_1 - 4x_2 \ge -5,\\
    & 5x_2 - x_3 \ge -1, \\
    & -5x_2 + x_3 \ge 1, \\
    & x_1 \ge 0,\\
    & x_2 \ge 0.
    \end{aligned}
    $$
    
    Dùng các thao tác 4 và 5, có thể chuyển nó về dạng $\max\{c^Tx : Ax = b,~ x\ge 0\}$, tức
    
    $$
    \begin{aligned}
    \max\;& 3x_1 - 2x_2 + x^+_3 - x^-_3 \\
    \text{subject to }& 2x_1 + 3x_2 + 4x^+_3 - 4x^-_3 - x_4 = 1,\\
    & 3x_1 + 4x_2 + x_5 = 5,\\
    & 5x_2 - x^+_3 + x^-_3 = -1, \\
    & x_1, x_2, x^+_3, x^-_3, x_4, x_5 \ge 0.
    \end{aligned}
    $$

<span id="&#21487;&#34892;&#22495;&#19982;&#38382;&#39064;&#30340;&#35299;"></span>
### Miền khả thi và nghiệm của bài toán

Tập tất cả nghiệm khả thi $\mathcal D\subseteq\mathbf R^n$ gọi là **miền khả thi** (feasible region) của bài toán quy hoạch tuyến tính $P$. Về mặt hình học, mỗi ràng buộc bất đẳng thức $a_j^T x \le b_j$ mô tả một nửa không gian $\{x\in\mathbf R^n:a_j^T x \le b_j\}$, và mỗi ràng buộc đẳng thức $a^T_jx = b_j$ mô tả một siêu phẳng $\{x\in\mathbf R^n:a_j^Tx=b_j\}$. Vì vậy miền khả thi luôn là giao của hữu hạn nửa không gian và siêu phẳng. Trong tối ưu hóa[^poly-names], hình học như vậy thường được gọi là **đa diện** (polyhedron) trong $\mathbf R^n$. Đa diện luôn là tập lồi đóng, nhưng không nhất thiết bị chặn. Đa diện bị chặn còn gọi là **đa bào** (polytope). Đa bào có thể xem là sự mở rộng của đa giác phẳng lên không gian nhiều chiều, còn đa diện tiếp tục mở rộng khái niệm đó sang trường hợp có thể không bị chặn.

???+ example "Ví dụ về đa diện"
    Dưới đây là một số đa diện thường gặp:
    
    1.  Tập rỗng $\varnothing$, còn gọi là **nullitope**, được quy ước có chiều $-1$.
    2.  **Không gian con affine** (affine subspace), tức giao của một số siêu phẳng $\{x\in\mathbf R^n:Ax = b\}$. Nó tương đương với tập nghiệm của hệ phương trình tuyến tính $Ax = b$: khi hệ vô nghiệm, nó là tập rỗng; ngược lại, nó luôn có thể viết dưới dạng $x_0+V$, trong đó $x_0\in\mathbf R^n$ và $V\subseteq\mathbf R^n$ là không gian con tuyến tính có chiều $n-\operatorname{rank}(A)$. Đặc biệt, siêu phẳng cũng là không gian con affine.
    3.  **Nón đa diện** (polyhedral cone), tức toàn bộ các tổ hợp tuyến tính không âm của hữu hạn điểm $\{x_i\}$ trong không gian: $\{\sum_i\alpha_ix_i:\alpha_i\ge 0\}$. Đây là một nón lồi có đỉnh tại gốc tọa độ. Tương đương, nó có thể xem là đa diện được bao bởi một số siêu phẳng đi qua gốc tọa độ, tức $\{x\in\mathbf R^n : Ax\le 0\}$. Đặc biệt, nửa không gian cũng là nón đa diện.
    4.  Đa bào, tức đa diện bị chặn. Đặc biệt, các đa bào chiều $-1$, $0$, $1$, $2$, $3$ lần lượt là tập rỗng, điểm, đoạn thẳng, đa giác và đa diện theo nghĩa thông thường. Một tập là đa bào khi và chỉ khi nó là bao lồi của hữu hạn điểm $\{x_i\}$: $\{\sum_i\alpha_ix_i:\alpha_i\ge 0,~\sum_i\alpha_i=1\}$. Một đa bào $k$ chiều ít nhất được sinh bởi bao lồi của $k+1$ điểm.
    5.  **Đơn hình** (simplex), tức đa bào $k$ chiều được sinh đúng bởi $k+1$ điểm. Đây là đa bào $k$ chiều đơn giản nhất. Đặc biệt, các đa bào chiều $-1$, $0$, $1$, $2$, $3$ lần lượt là tập rỗng, điểm, đoạn thẳng, tam giác và tứ diện. Ví dụ đơn giản nhất của đơn hình $k$ chiều là $\{x\in\mathbf R^k:x_i\ge 0,~\sum_ix_i=1\}$. Thực ra, mọi đơn hình $k$ chiều đều có thể biến thành trường hợp đặc biệt này bằng một phép biến đổi affine (tịnh tiến và co giãn). Cần chú ý rằng phương pháp đơn hình không thực sự chạy trên một đơn hình.
    
    Mọi đa diện đều có thể xem là [tổng Minkowski](../geometry/convex-hull.md#%E9%97%B5%E5%8F%AF%E5%A4%AB%E6%96%AF%E5%9F%BA%E5%92%8C) của một nón đa diện và một đa bào: phần trước mô tả phần không bị chặn của đa diện, phần sau mô tả hình dạng phần bị chặn của đa diện. Nón đa diện này là duy nhất: nón đa diện thu được khi phân rã đa diện $\{x\in\mathbf R^n:Ax\le b\}$ nhất định là $\{x\in\mathcal R^n:Ax\le 0\}$.

Nghiệm của quy hoạch tuyến tính gắn chặt với cấu trúc của đa diện. Với đa diện $\mathcal D\in\mathbf R^n$ và vector $c\in\mathbf R^n\setminus\{0\}$, xét bài toán quy hoạch tuyến tính $P$ sau (trường hợp tối thiểu hóa có thể bàn tương tự):

$$
\max\{c^Tx:x\in\mathcal D\}.
$$

Về hình học, việc này tương đương với di chuyển siêu phẳng $H:c^Tx = z$ theo hướng vector $c$, với điều kiện $H$ và miền khả thi $\mathcal{D}$ có ít nhất một giao điểm, sao cho $z$ lớn nhất có thể. Có ba khả năng:

-   Miền khả thi $\mathcal D$ là tập rỗng. Điều này nói rằng bài toán $P$ không có nghiệm khả thi, một số ràng buộc của nó mâu thuẫn với nhau. Khi đó, bài toán $P$ gọi là **không khả thi** (infeasible), và giá trị tối ưu của nó được quy ước là $-\infty$.

-   Miền khả thi $\mathcal D$ không rỗng, nhưng chứa một tia có vector chỉ phương là $c$, tức tồn tại $x_0\in\mathbf R^n$ sao cho $x_0+tc\in\mathcal D$ với mọi $t\ge 0$. Vì có thể liên tục di chuyển siêu phẳng $H$ theo hướng vector $c$, và trong quá trình di chuyển tập $H\cap\mathcal D$ luôn chứa ít nhất một điểm trên tia đó nên không rỗng, hàm mục tiêu $c^Tx = c^Tx_0 + tc^Tc$ có thể nhận giá trị lớn tùy ý. Khi đó, bài toán $P$ gọi là **không bị chặn** (unbounded), và giá trị tối ưu của nó được quy ước là $+\infty$.

-   Miền khả thi $\mathcal D$ không rỗng và không chứa tia nào có vector chỉ phương là $c$. Khi đó, bài toán $P$ gọi là **bị chặn** (bounded). Gọi $z^*\in\mathbf R$ là giá trị tối ưu của $P$. Siêu phẳng $H^*:c^Tx = z^*$ nằm ở một vị trí tới hạn: nó cắt đa diện $\mathcal D$, và $\mathcal D$ nằm trong nửa không gian $\{x:c^Tx\le z^*\}$. Siêu phẳng như vậy gọi là một **siêu phẳng đỡ** (supporting hyperplane) của đa diện $\mathcal D$. Tập nghiệm tối ưu của $P$ là $H^*\cap\mathcal D$. Là giao của một siêu phẳng đỡ và đa diện, tập $H^*\cap\mathcal D$ cũng là đa diện và nằm trên biên của $\mathcal D$. Nó gọi là một **mặt** (face) của đa diện $\mathcal D$. Nói một cách trực quan, đa diện được bao bởi các mặt này. Ngoài các mặt hình thành từ giao của siêu phẳng đỡ và đa diện, nói chung đa diện còn có hai mặt: tập rỗng và chính đa diện. Tất cả các mặt của một đa diện, dưới quan hệ bao hàm tập hợp, tạo thành cấu trúc [dàn](../math/order-theory.md#%E6%9C%89%E5%90%91%E9%9B%86%E4%B8%8E%E6%A0%BC).

    Chiều của một mặt của đa diện $d$ chiều luôn là một số nguyên từ $0$ đến $d$. Mặt có chiều $0$ (tức một điểm) gọi là **đỉnh** (vertex) hoặc **điểm góc** (corner point) của đa diện $\mathcal D$; mặt có chiều $1$ gọi là **cạnh** (edge); mặt có chiều $d-1$ gọi là **diện** (facet) của đa diện $\mathcal D$. Tuy nhiên, không phải đa diện nào cũng có đỉnh. Vì mặt của một mặt của đa diện vẫn là mặt của đa diện, và chỉ có không gian con affine mới không có mặt không rỗng nhỏ hơn nghiêm ngặt, nên mọi mặt cực tiểu của đa diện $\mathcal D$ đều là không gian con affine. Hơn nữa, các mặt cực tiểu của cùng một đa diện có cùng chiều; đặc biệt, chiều của mặt cực tiểu của đa diện $\mathcal D=\{x\in\mathbf R^n:Ax\le b\}$ là $n-\operatorname{rank}A$.

    Vì mặt của đa diện chính là tập nghiệm của một bài toán quy hoạch tuyến tính bị chặn, cần hiểu cách xác định phương trình của các mặt của đa diện. Giả sử đa diện $\mathcal D$ được mô tả bởi một số ràng buộc $a_j^Tx \lesseqqgtr b_j$, và $F$ là một mặt của $\mathcal D$. Nếu một ràng buộc đạt dấu bằng tại mọi $x\in F$, ta nói ràng buộc đó **chặt** (tight) trên mặt $F$. Các điểm trên $F$ hiển nhiên thỏa mãn hệ phương trình thu được bằng cách đặt dấu bằng cho các ràng buộc chặt này, và giao của không gian con affine xác định bởi hệ đó với đa diện $\mathcal D$ chính là mặt $F$. Ngược lại, chọn tùy ý một tập con các ràng buộc của đa diện $\mathcal D$, đặt chúng thành đẳng thức, giải hệ để được một không gian con affine rồi lấy giao với đa diện, ta thu được một mặt của $\mathcal D$. Hơn nữa, càng chọn nhiều ràng buộc chặt thì mặt thu được càng nhỏ theo nghĩa bao hàm.

    Đặc biệt, miền khả thi của quy hoạch tuyến tính dạng chuẩn $\mathcal D=\{x\in\mathbf R^n:Ax=b,~x\ge 0\}$ có ma trận hệ số $\begin{pmatrix}A\\ I\end{pmatrix}$ với hạng bằng $n$, nên các mặt cực tiểu của nó chính là các đỉnh. Nói cách khác, nếu bài toán bị chặn thì luôn có thể chọn một nghiệm tối ưu là một đỉnh nào đó. Hơn nữa, đỉnh này có thể thu được bằng cách chọn $n$ ràng buộc chặt độc lập tuyến tính rồi giải hệ. Đây chính là điểm thuận tiện của dạng chuẩn của quy hoạch tuyến tính.

???+ example "Ví dụ"
    Trong hình dưới, $\mathcal D$ là miền khả thi. Khi các hệ số trong hàm mục tiêu là $c_1,c_2,c_3$, chúng lần lượt ứng với ba trường hợp: nghiệm tối ưu duy nhất, nhiều nghiệm tối ưu và không bị chặn. Với hai trường hợp đầu, các đường liền đỏ đậm tương ứng là một siêu phẳng đỡ của tập nghiệm; tập nghiệm tối ưu lần lượt là đỉnh $B$ và cạnh $\overline{CD}$ của đa diện $\mathcal D$. Với trường hợp thứ ba, vì miền khả thi $\mathcal D$ chứa một tia theo hướng $c_3$, nên siêu phẳng có vector pháp tuyến $c_3$ có thể liên tục dịch theo hướng $c_3$, và bài toán không bị chặn.
    
    ![](./images/lp-feasible.svg)

Các thảo luận trên bỏ qua trường hợp $c=0$. Khi đó, bài toán quy hoạch tuyến tính hiển nhiên không thể không bị chặn, nên hoặc bản thân bài toán không khả thi, hoặc giá trị tối ưu bằng $0$ và tập nghiệm tối ưu chính là $\mathcal D$. Loại quy hoạch tuyến tính đặc biệt này còn gọi là **quy hoạch tuyến tính khả thi** (feasibility linear programming).

Cần chỉ ra rằng các bài toán như quyết định một quy hoạch tuyến tính có khả thi hay không, có bị chặn hay không, hoặc tìm nghiệm khả thi của một hệ bất đẳng thức, đều khó tương đương với việc giải chính bài toán quy hoạch tuyến tính[^reducible]. Chẳng hạn, chứng minh định lý đối ngẫu mạnh dưới đây cho thấy việc giải một bài toán quy hoạch tuyến tính bị chặn tương đương với việc tìm nghiệm khả thi của một hệ bất đẳng thức. Vì vậy, với các nhiệm vụ như kiểm tra hệ bất đẳng thức có nghiệm hay không hoặc kiểm tra hệ phương trình có nghiệm không âm hay không, cách hiệu quả nhất là giải quy hoạch tuyến tính khả thi tương ứng[^other-methods].

Ngoài ra, nếu một ràng buộc của bài toán quy hoạch tuyến tính không chặt trên mọi mặt của miền khả thi, thì ràng buộc đó là **dư thừa** (redundant). Trong ví dụ người bán bữa sáng ở đầu bài, ràng buộc về thời gian làm việc là một ràng buộc dư thừa. Để quyết định một bất đẳng thức $a_j^Tx\le b_j$ trong hệ đã cho có dư thừa hay không, có thể giải bài toán quy hoạch tuyến tính $\max\{a_j^Tx:x\in\mathcal D\}$ rồi so sánh kết quả với $b_j$.

<span id="&#24120;&#35265;&#31639;&#27861;"></span>
## Các thuật toán thường gặp

Trong thi thuật toán, hiếm khi có bài toán chỉ có thể giải bằng thuật toán quy hoạch tuyến tính. Phần lớn bài toán có thể giải bằng phương pháp quy hoạch tuyến tính thường cũng có thể giải bằng luồng mạng hoặc các thuật toán chuyên biệt hơn và hiệu quả hơn.

Các thuật toán thường gặp để giải quy hoạch tuyến tính gồm:

-   [Phương pháp đơn hình](./simplex.md)
-   Phương pháp ellipsoid
-   Phương pháp điểm trong

Dù độ phức tạp trường hợp xấu nhất của phương pháp đơn hình là cấp mũ, còn độ phức tạp của phương pháp điểm trong là đa thức, cả hai loại thuật toán này đều thể hiện rất tốt trong đa số bài toán thực tế. Ngược lại, tuy phương pháp ellipsoid có độ phức tạp lý thuyết cấp đa thức, nó thường chạy chậm và không thực dụng.

Hiện vẫn chưa rõ liệu bài toán quy hoạch tuyến tính có thuật toán độ phức tạp đa thức mạnh hay không.

<span id="&#23545;&#20598;&#38382;&#39064;"></span>
## Bài toán đối ngẫu

Mỗi bài toán quy hoạch tuyến tính đều có một bài toán đối ngẫu tương ứng. Nghiệm của bài toán gốc và bài toán đối ngẫu có liên hệ chặt chẽ. Thông qua bài toán đối ngẫu, ta không chỉ hiểu sâu hơn cấu trúc bài toán mà còn thường có thể cải thiện hiệu quả giải bài toán gốc.

Với bài toán quy hoạch tuyến tính $P$ sau (các biến chữ thường xuất hiện đều là vector)

$$
\begin{aligned}
\min_{x_1,x_2,x_3}\;& c_1^Tx_1 + c_2^Tx_2 + c_3^Tx_3 \\
\text{subject to }& A_{11}x_1 + A_{12}x_2 + A_{13}x_3 \ge b_1,\\
& A_{21}x_1 + A_{22}x_2 + A_{23}x_3 = b_2,\\
& A_{31}x_1 + A_{32}x_2 + A_{33}x_3 \le b_3,\\
& x_1\ge 0,~ x_3\le 0,
\end{aligned}
$$

bài toán đối ngẫu $D$ của nó là bài toán quy hoạch tuyến tính

$$
\begin{aligned}
\max_{y_1,y_2,y_3}\;&b_1^Ty_1+b_2^Ty_2+b_3^Ty_3 \\
\text{subject to }&A_{11}^Ty_1 + A_{21}^Ty_2 + A_{31}^Ty_3\le c_1,\\
&A_{12}^Ty_1 + A_{22}^Ty_2 + A_{32}^Ty_3 = c_2,\\
&A_{13}^Ty_1 + A_{23}^Ty_2 + A_{33}^Ty_3 \ge c_3,\\
&y_1\ge 0,~ y_3\le 0.
\end{aligned}
$$

Trong đó, các biến quyết định $y_1,y_2,y_3$ của bài toán đối ngẫu lần lượt là các hệ số nhân Lagrange của ba loại ràng buộc trong bài toán gốc; ngược lại, các biến quyết định $x_1,x_2,x_3$ của bài toán gốc cũng lần lượt là các hệ số nhân Lagrange của ba loại ràng buộc trong bài toán đối ngẫu. Dễ kiểm chứng rằng đối ngẫu của bài toán đối ngẫu chính là bài toán gốc.

Quan hệ tương ứng giữa bài toán gốc $P$ và bài toán đối ngẫu $D$ như sau:

| Bài toán tối thiểu hóa | Bài toán tối đa hóa |
| :----: | :----: |
| Ràng buộc lớn hơn hoặc bằng | Biến không âm |
| Ràng buộc nhỏ hơn hoặc bằng | Biến không dương |
| Ràng buộc đẳng thức | Biến tự do |
| Biến không âm | Ràng buộc nhỏ hơn hoặc bằng |
| Biến không dương | Ràng buộc lớn hơn hoặc bằng |
| Biến tự do | Ràng buộc đẳng thức |
| Hệ số hàm mục tiêu | Hằng số vế phải của ràng buộc |
| Hằng số vế phải của ràng buộc | Hệ số hàm mục tiêu |

Đặc biệt, bài toán quy hoạch tuyến tính dạng chuẩn

$$
\min\{c^Tx:Ax=b,~x\ge 0\}
$$

có bài toán đối ngẫu là

$$
\max\{b^Ty:A^Ty\le c\}.
$$

<span id="&#23545;&#20598;&#21407;&#29702;"></span>
### Nguyên lý đối ngẫu

Bài toán gốc và bài toán đối ngẫu không chỉ là ảnh gương nhau về hình thức; nghiệm của chúng cũng liên hệ chặt chẽ. Điều này gọi là **nguyên lý đối ngẫu** (duality principle). Để tiện trình bày, phần này dùng bài toán gốc ở dạng chuẩn khi phát biểu và chứng minh các định lý.

Trước hết, **định lý đối ngẫu yếu** (weak duality theorem) nói rằng giá trị lớn nhất của bài toán đối ngẫu không vượt quá giá trị nhỏ nhất của bài toán gốc.

???+ note "Định lý đối ngẫu yếu"
    Với mọi $A\in\mathbf R^{m\times n}$, $b\in\mathbf R^m$ và $c\in\mathbf R^n$, luôn có
    
    $$
    \max\{b^Ty:A^Ty\le c\} \le \min\{c^Tx:Ax=b,~x\ge 0\}.
    $$

??? note "Chứng minh"
    Nếu một trong hai bài toán gốc và đối ngẫu không khả thi, bất đẳng thức là hiển nhiên. Giả sử cả hai đều khả thi. Khi đó, với mọi $x$ và $y$ khả thi, ta có
    
    $$
    b^Ty = x^TA^Ty \le x^Tc.
    $$
    
    Do đó, lấy cực trị hai vế sẽ cho định lý đối ngẫu yếu.

Dựa trên định lý đối ngẫu yếu, trạng thái nghiệm của bài toán gốc và bài toán đối ngẫu chỉ có bốn khả năng sau:

1.  Bài toán gốc và bài toán đối ngẫu đều không khả thi, tức $-\infty\le+\infty$;
2.  Bài toán gốc không khả thi, bài toán đối ngẫu không bị chặn, tức $+\infty\le+\infty$;
3.  Bài toán gốc không bị chặn, bài toán đối ngẫu không khả thi, tức $-\infty\le-\infty$;
4.  Bài toán gốc và bài toán đối ngẫu đều bị chặn.

Định lý đối ngẫu yếu có nhiều hệ quả. Chẳng hạn, nó thực chất đưa ra cách dùng tính khả thi của bài toán gốc và đối ngẫu để quyết định bài toán gốc có không bị chặn hay không.

???+ note "Hệ quả"
    Một bài toán quy hoạch tuyến tính không bị chặn khi và chỉ khi nó khả thi và bài toán đối ngẫu của nó không khả thi.

Áp dụng định lý đối ngẫu yếu cho quy hoạch tuyến tính khả thi sẽ thu được bổ đề Farkas (và các biến thể của nó).

???+ note "Bổ đề Farkas"
    Với $A\in\mathbf R^{m\times n}$ và $b\in\mathbf R^n$, đúng đúng một trong hai trường hợp sau:
    
    1.  Tồn tại $x\in\mathbf R^n$ sao cho $Ax=b$ và $x\ge 0$;
    2.  Tồn tại $y\in\mathbf R^m$ sao cho $A^T y\ge 0$ và $b^Ty<0$.

??? note "Chứng minh"
    Xét bài toán quy hoạch tuyến tính $\max\{0:Ax=b,~x\ge 0\}$; bài toán đối ngẫu của nó là $\min\{b^Ty:A^Ty\ge 0\}$. Bài toán đối ngẫu hiển nhiên khả thi, vì ít nhất $0\in\mathbf R^m$ là một nghiệm khả thi. Do đó, theo định lý đối ngẫu yếu, hoặc bài toán gốc khả thi, hoặc bài toán đối ngẫu không bị chặn, và đúng một trong hai trường hợp xảy ra. Bài toán gốc khả thi chính là trường hợp 1 trong bổ đề Farkas, còn bài toán đối ngẫu không bị chặn tương đương với trường hợp 2. Vậy bổ đề Farkas được chứng minh.

Farkas thực chất là một [định lý tách siêu phẳng](https://en.wikipedia.org/wiki/Hyperplane_separation_theorem). Trường hợp 1 nói rằng điểm $b$ nằm trong nón đa diện $C$ sinh bởi các vector cột của $A$; vì vậy, bổ đề Farkas nói rằng khi và chỉ khi điểm $b$ không nằm trong nón lồi $C$ này, tồn tại một siêu phẳng $H:y^Tx = 0$ đi qua gốc tọa độ và có vector pháp tuyến $y$ tách mạnh điểm $b$ khỏi nón đa diện $C$.

Thực ra, với khả năng thứ tư mà định lý đối ngẫu yếu cho phép, còn có một kết luận mạnh hơn: giá trị tối ưu của bài toán gốc và bài toán đối ngẫu bằng nhau. Gộp ba khả năng sau lại, ta thu được **định lý đối ngẫu mạnh** (strong duality theorem): miễn là một trong hai bài toán gốc hoặc đối ngẫu khả thi, giá trị tối ưu của chúng nhất định bằng nhau.

???+ note "Định lý đối ngẫu mạnh"
    Với mọi $A\in\mathbf R^{m\times n}$, $b\in\mathbf R^m$ và $c\in\mathbf R^n$, ta có
    
    $$
    \max\{b^Ty:A^Ty\le c\} = \min\{c^Tx:Ax=b,~x\ge 0\}.
    $$
    
    miễn là một trong hai tập là không rỗng.

??? note "Chứng minh"
    Trường hợp duy nhất chưa được định lý đối ngẫu yếu bao phủ là cả bài toán gốc và bài toán đối ngẫu đều khả thi. Khi đó xét bài toán quy hoạch tuyến tính khả thi $Q$ sau:
    
    $$
    \max\{0:c^Tx \le b^Ty,~Ax=b,~x\ge 0,~A^Ty\le c\}.
    $$
    
    Nếu bài toán $Q$ có nghiệm khả thi $(x^*,y^*)\in\mathbf R^n\times\mathbf R^m$, thì theo định lý đối ngẫu yếu và tính tối ưu, ta có
    
    $$
    b^Ty^* \le \max\{b^Ty:A^Ty\le c\} \le \min\{c^Tx:Ax=b,~x\ge 0\} \le c^Tx^*,
    $$
    
    nhưng $c^Tx^*\le b^Ty^*$, nên tất cả các bất đẳng thức này đều đạt dấu bằng. Nói cách khác, không chỉ đối ngẫu mạnh đúng, mà $x^*$ và $y^*$ lần lượt là nghiệm tối ưu của bài toán gốc và bài toán đối ngẫu.
    
    Vì vậy chỉ cần chứng minh bài toán $Q$ khả thi. Giả sử ngược lại. Bắt chước chứng minh bổ đề Farkas, xét bài toán đối ngẫu $DQ$ của $Q$:
    
    $$
    \min\{c^T\mu - b^T\lambda : ct - A^T\lambda \ge 0,~ -bt + A\mu = 0,~t\ge 0,~\mu\ge 0\}.
    $$
    
    Vì $(t,\lambda,\mu)=(0,0,0)$ là một nghiệm khả thi của bài toán đối ngẫu $DQ$, theo định lý đối ngẫu yếu, việc $Q$ không khả thi kéo theo $DQ$ không bị chặn. Tức tồn tại một bộ $(t^*,\lambda^*,\mu^*)$ sao cho
    
    $$
    c^T\mu^* - b^T\lambda^* <0,~ ct^* - A^T\lambda^* \ge 0,~ -bt^* + A\mu^* = 0,~t^*\ge 0,~\mu^*\ge 0.
    $$
    
    Khi đó, nếu $t^*>0$, các bất đẳng thức này thực ra nói rằng $(x,y)=(\mu^*/t^*,\lambda^*/t^*)$ là một nghiệm khả thi của bài toán nói trên, mâu thuẫn với giả thiết. Do đó chỉ có thể có $t^*=0$. Điều này cho
    
    $$
    c^T\mu^* < b^T\lambda^*,~ A^T\lambda^*\le 0,~ A\mu^*=0,~\mu^*\ge 0.
    $$
    
    Nhưng vì đã giả sử bài toán gốc và bài toán đối ngẫu trong định lý đều khả thi, tức tồn tại $(x_0,y_0)$ sao cho
    
    $$
    Ax_0 = b,~ x_0\ge 0,~ A^Ty_0\le c
    $$
    
    nên
    
    $$
    0 = (A\mu^*)^Ty_0 = (A^Ty_0)^T\mu^* \le c^T\mu^* < b^T\lambda^* = x_0^TA^T\lambda^* \le 0.
    $$
    
    Đây là mâu thuẫn hiển nhiên. Mâu thuẫn này chứng tỏ $Q$ khả thi, từ đó suy ra đối ngẫu mạnh.

Từ quá trình chứng minh định lý đối ngẫu mạnh còn suy ra hệ quả sau:

???+ note "Hệ quả"
    Giả sử $x^*$ và $y^*$ là một cặp nghiệm khả thi của bài toán gốc và đối ngẫu thỏa mãn đối ngẫu mạnh, tức $c^Tx^* = b^Ty^*$. Khi đó chúng cũng lần lượt là nghiệm tối ưu của bài toán gốc và bài toán đối ngẫu.

Định lý đối ngẫu mạnh nói rằng với một bài toán quy hoạch tuyến tính khả thi, chỉ cần giải bài toán đối ngẫu của nó là có thể thu được giá trị tối ưu của bài toán gốc.

<span id="&#20114;&#34917;&#26494;&#24347;&#26465;&#20214;"></span>
### Điều kiện bù trừ độ lỏng

Giống các bài toán tối ưu khác, điều kiện bù trừ độ lỏng là một phần của điều kiện tối ưu của bài toán quy hoạch tuyến tính. Hơn nữa, vì hàm mục tiêu là tuyến tính, nên với quy hoạch tuyến tính, điều kiện bù trừ độ lỏng là điều kiện cần và đủ để một nghiệm khả thi trở thành nghiệm tối ưu.

Cái gọi là điều kiện **bù trừ độ lỏng** (complementary slackness) nghĩa là chỉ khi một ràng buộc trong bài toán gốc (bài toán đối ngẫu) đạt dấu bằng, tức ràng buộc đó chặt, thì biến tương ứng trong bài toán đối ngẫu (bài toán gốc) mới có thể nhận giá trị khác không. Nếu cũng xem việc biến nhận giá trị khác không là một ràng buộc không bị lỏng, thì điều này tương đương với nói rằng biến và ràng buộc tương ứng trong bài toán gốc và đối ngẫu không thể đồng thời bị lỏng. Vì vậy điều kiện này gọi là điều kiện bù trừ độ lỏng.

Với bài toán quy hoạch tuyến tính dạng chuẩn, kết luận sau đúng:

???+ note "Định lý"
    Giả sử $x^*$ và $y^*$ lần lượt là nghiệm khả thi của bài toán gốc $\min\{c^Tx:Ax=b,~x\ge 0\}$ và bài toán đối ngẫu $\max\{b^Ty:A^Ty\le c\}$. Khi đó, $x^*$ và $y^*$ cũng lần lượt là nghiệm tối ưu của bài toán gốc và bài toán đối ngẫu khi và chỉ khi điều kiện bù trừ độ lỏng đúng, tức
    
    $$
    x^T(A^Ty-c) = 0
    $$
    
    đúng.

??? note "Chứng minh"
    Vì $x^*$ và $y^*$ đều là nghiệm khả thi, ta có
    
    $$
    b^Ty^* - c^Tx^* = (x^*)^T(A^T y^* - c).
    $$
    
    Vì vậy điều kiện bù trừ độ lỏng đúng khi và chỉ khi $b^Ty^* = c^Tx^*$. Theo hệ quả của định lý đối ngẫu mạnh, điều kiện này đúng khi và chỉ khi $x^*$ và $y^*$ lần lượt là nghiệm tối ưu của bài toán gốc.

Dạng chuẩn có thể hơi đặc biệt. Một dạng tổng quát hơn một chút của định lý là:

???+ note "Định lý"
    Giả sử $x^*$ và $y^*$ lần lượt là nghiệm khả thi của bài toán gốc $\min\{c^Tx:Ax\ge b,~x\ge 0\}$ và bài toán đối ngẫu $\max\{b^Ty:A^Ty\le c,~y\ge 0\}$. Khi đó, $x^*$ và $y^*$ cũng lần lượt là nghiệm tối ưu của bài toán gốc và bài toán đối ngẫu khi và chỉ khi điều kiện bù trừ độ lỏng đúng, tức
    
    $$
    x^T(A^Ty-c) = y^T(Ax-b) = 0
    $$
    
    đúng.

??? note "Chứng minh"
    Chứng minh gần như trên, chỉ khác là lần này cần viết hiệu thành
    
    $$
    b^Ty^* - c^Tx^* = (x^*)^T(A^T y^* - c) - (y^*)^T(Ax^*-b).
    $$

Điều kiện bù trừ độ lỏng cung cấp một điều kiện đơn giản để kiểm tra tính tối ưu của nghiệm khả thi của bài toán quy hoạch tuyến tính.

<span id="&#21407;&#22987;&#8209;&#23545;&#20598;&#26041;&#27861;"></span>
### Phương pháp nguyên thủy-đối ngẫu

Bài toán đối ngẫu có thể hỗ trợ giải bài toán gốc. Khi giải quy hoạch tuyến tính, một phương pháp thường dùng là **phương pháp nguyên thủy-đối ngẫu** (primal-dual method). Phương pháp này giải một chuỗi các bài toán phụ tương đối đơn giản, dần cải thiện nghiệm của bài toán đối ngẫu, rồi thu được nghiệm tối ưu của bài toán nguyên thủy.

Với bài toán gốc dạng chuẩn

$$
(P)\qquad\min\{c^Tx : Ax=b\ge 0,~ x\ge 0\}
$$

và bài toán đối ngẫu của nó

$$
(D)\qquad\max\{b^Ty : A^Ty\le c\},
$$

phần trước đã chỉ ra rằng để tìm nghiệm tối ưu của chúng, chỉ cần tìm một cặp nghiệm khả thi của $(P)$ và $(D)$ thỏa mãn điều kiện bù trừ độ lỏng $x^T(A^Ty-c)=0$. Vì vậy có thể xét quy trình sau:

1.  Bắt đầu từ một nghiệm khả thi $y$ của bài toán đối ngẫu $(D)$, tính tập các ràng buộc chặt của bài toán đối ngẫu:

    $$
    I = \{i : (A^Ty - c)_i = 0\}.
    $$

2.  Theo điều kiện bù trừ độ lỏng, nếu tồn tại nghiệm khả thi $x$ của bài toán $(P)$ sao cho $x_i>0$ chỉ xảy ra trên $i\in I$, thì ta đã tìm được một cặp nghiệm tối ưu. Do đó, xét bài toán quy hoạch tuyến tính

    $$
    (RP)\qquad
    \begin{aligned}
    \min_{x,s}\;& \mathbf 1^Ts \\
    \text{subject to } & Ax + s = b, \\
    & x_i \ge 0,~\forall i \in I,\\
    & x_i = 0,~\forall i \notin I,\\
    & s \ge 0.
    \end{aligned}
    $$

3.  Nếu giá trị nhỏ nhất của $(RP)$ là $0$, thì $x^*$ trong nghiệm tối ưu $(x^*,0)$ chính là nghiệm tối ưu của bài toán gốc $(P)$. Ngược lại, có thể tìm nghiệm $\bar y$ của bài toán đối ngẫu $(DRP)$ của nó:

    $$
    (DRP)\qquad
    \begin{aligned}
    \max_{y}\;& b^Ty \\
    \text{subject to }& \sum_{j}a_{ji}y_j \le 0,~\forall i\in I,\\
    & y \le 1.
    \end{aligned}
    $$

    Theo định lý đối ngẫu mạnh, $b^T\bar y = 1^Ts^*>0$.

4.  Dùng nghiệm của $(DRP)$ để cải thiện nghiệm khả thi của bài toán đối ngẫu $(D)$. Đặt $y' = y + \varepsilon \bar y$, trong đó $\varepsilon>0$; khi đó chắc chắn $b^Ty' = b^Ty + \varepsilon b^T\bar y > b^Ty$. Vì vậy, miễn là bảo đảm $y'$ vẫn là nghiệm khả thi của bài toán đối ngẫu $(D)$, ta nên chọn $\varepsilon$ lớn nhất có thể.

    Với $i\in I$, ta có

    $$
    \sum_ja_{ji}y'_j = \sum_ja_{ji}y_j + \varepsilon \sum_ja_{ji}\bar y_j \le c_i,
    $$

    nên các ràng buộc này của $(D)$ luôn được thỏa mãn.

    Với các ràng buộc còn lại, tức $i\notin I$, chỉ cần lấy

    $$
    \varepsilon = \min\left\{\dfrac{c_i - \sum_{j}a_{ji}y_j}{\sum_{j}a_{ji}\bar y_j}:i\notin I,~\textstyle\sum_{j}a_{ji}\bar y_j>0\right\}
    $$

    là có thể cải thiện nghiệm của bài toán đối ngẫu nhiều nhất có thể trong khi vẫn bảo đảm tính khả thi, rồi quay lại bước 1 để lặp tiếp. Đặc biệt, nếu tập trong công thức trên rỗng, tức $\varepsilon=+\infty$, thì bài toán đối ngẫu $(D)$ không bị chặn và bài toán gốc $(P)$ không khả thi.

Trong quá trình này, thực ra chỉ có bài toán $(DRP)$ thật sự cần giải; nó liên hệ với bài toán $(RP)$ qua định lý đối ngẫu mạnh. Bài toán $(DRP)$ cung cấp một hướng cải thiện nghiệm của bài toán đối ngẫu, và so với bản thân bài toán đối ngẫu $(D)$, dạng của $(DRP)$ đơn giản hơn. Tính khả thi của $(DRP)$ được bảo đảm bởi bổ đề Farkas, còn ràng buộc $y\le 1$ chỉ là một nhóm điều kiện chuẩn hóa để bảo đảm $(DRP)$ bị chặn.

Trong thi thuật toán, phương pháp nguyên thủy-đối ngẫu được dùng rộng rãi trong nhiều bài toán tối ưu tổ hợp. Ví dụ, [thuật toán Hungary](../graph/graph-matching/bigraph-weight-match.md#hungarian-algorithmkuhnmunkres-algorithm) cho ghép cặp hai phía trọng số lớn nhất, [thuật toán khử chu trình](../graph/flow/min-cost.md) và [thuật toán SSP (thuật toán nguyên thủy-đối ngẫu)](../graph/flow/min-cost.md#ssp-%E7%AE%97%E6%B3%95) cho luồng chi phí nhỏ nhất, [thuật toán Dijkstra](../graph/shortest-path.md#thuật-toán-dijkstra) cho đường đi ngắn nhất, [thuật toán tăng luồng Ford-Fulkerson](../graph/flow/max-flow.md#fordfulkerson-%E5%A2%9E%E5%B9%BF) cho luồng cực đại, v.v. đều có thể xem là ứng dụng trực tiếp của phương pháp nguyên thủy-đối ngẫu.

<span id="&#25972;&#25968;&#35268;&#21010;"></span>
## Quy hoạch nguyên

**Quy hoạch nguyên** (integer programming) thường chỉ **quy hoạch tuyến tính nguyên** (integer linear programming, ILP). Dạng chuẩn của quy hoạch tuyến tính nguyên như sau:

$$
\begin{aligned}
\min_{x}\; & c^Tx \\
\text{subject to } & Ax = b \ge 0,\\
& x \ge 0,\\
& x \in \mathbf Z^n,
\end{aligned}
$$

trong đó $A\in\mathbf R^{m\times n}$, $b\in\mathbf R^m$, $c\in\mathbf R^n$. Nói cách khác, quy hoạch tuyến tính nguyên là bài toán thu được bằng cách thêm ràng buộc các biến quyết định phải là số nguyên vào một bài toán quy hoạch tuyến tính.

Ràng buộc nguyên làm tăng đáng kể độ phức tạp của bài toán quy hoạch nguyên. Nhiều bài toán tối ưu tổ hợp, chẳng hạn bài toán ba lô, bài toán thỏa mãn và rất nhiều bài toán tối ưu trong lý thuyết đồ thị, đều có thể biểu diễn bằng mô hình quy hoạch nguyên; phần lớn các bài toán đó đã được chứng minh là NP-khó.

<span id="&#20840;&#24186;&#27169;&#30697;&#38453;"></span>
### Ma trận hoàn toàn đơn môđun

Chính vì vậy, với nhiều bài toán tối ưu nguyên quy mô lớn, đôi khi người ta nới lỏng ràng buộc nguyên và chuyển sang giải một bài toán quy hoạch tuyến tính. Thông thường, giá trị tối ưu của quy hoạch tuyến tính sau khi nới lỏng chỉ là một cận dưới của bài toán quy hoạch nguyên ban đầu (giả sử là bài toán tối thiểu hóa). Nhưng nếu nghiệm tối ưu của bài toán quy hoạch tuyến tính sau khi nới lỏng tình cờ là nghiệm nguyên, thì nó nhất định cũng là nghiệm tối ưu của bài toán quy hoạch nguyên ban đầu.

Một câu hỏi tự nhiên là liệu có điều kiện nào bảo đảm nghiệm tối ưu của bài toán quy hoạch tuyến tính đều là nghiệm nguyên hay không. Khái niệm ma trận hoàn toàn đơn môđun cung cấp một điều kiện như vậy.

???+ abstract "Ma trận hoàn toàn đơn môđun"
    Nếu định thức của mọi ma trận con vuông của ma trận $A\in\mathbf R^{m\times n}$ đều là $0$ hoặc $\pm 1$, thì $A$ gọi là một **ma trận hoàn toàn đơn môđun** (totally unimodular matrix).

Đặc biệt, mọi phần tử của ma trận hoàn toàn đơn môđun đều là $0$ hoặc $\pm 1$. Dùng khái niệm này, có thể phát biểu kết luận sau:

???+ note "Định lý"
    Với ma trận hoàn toàn đơn môđun $A\in\mathbf Z^{m\times n}$, $b\in\mathbf Z^{m}$ và $c\in\mathbf Z^n$, bài toán quy hoạch tuyến tính và bài toán đối ngẫu của nó
    
    $$
    \min\{c^Tx : Ax=b,x\ge 0\} = \max\{b^Ty: A^Ty\le c\}
    $$
    
    đều có nghiệm tối ưu nguyên, miễn là chúng đều bị chặn.

??? note "Chứng minh"
    Phần trước đã chỉ ra rằng tập nghiệm tối ưu của bài toán quy hoạch tuyến tính có thể lấy là một mặt cực tiểu của nó, và mặt này là nghiệm của hệ phương trình thu được bằng cách chọn một số ràng buộc chặt độc lập tuyến tính rồi đặt chúng thành đẳng thức:
    
    $$
    \{x\in\mathbf R^n : a_j^Tx = b_j,~\forall j\in J\}.
    $$
    
    Ký hiệu hệ phương trình này là $A_Jx=b_J$, và đặt $A_J=(A_1,A_2)$, trong đó $A_1$ là ma trận vuông đầy hạng có định thức $\pm 1$. Theo quy tắc Cramer, nghiệm
    
    $$
    x = \begin{pmatrix}A_1^{-1}b_J \\ 0\end{pmatrix}
    $$
    
    là một nghiệm nguyên trên mặt cực tiểu.

Trong các mô hình đồ thị thường gặp, ma trận hệ số của các bài toán quy hoạch tuyến tính tương ứng với luồng mạng, đường đi ngắn nhất, đồ thị hai phía, v.v. đều là ma trận hoàn toàn đơn môđun. Vì vậy, miễn là các bài toán này chỉ chứa tham số nguyên, nghiệm tối ưu của chúng có thể chọn là nghiệm nguyên, không cần lo nghiệm của bài toán quy hoạch tuyến tính tương ứng là luồng phân số, ghép cặp phân số, v.v. Do đó, các bài toán như [luồng cực đại](../graph/flow/max-flow.md), [cắt nhỏ nhất](../graph/flow/min-cut.md), [luồng chi phí nhỏ nhất](../graph/flow/min-cost.md), [đường đi ngắn nhất](../graph/shortest-path.md), [ràng buộc hiệu](../graph/diff-constraints.md), [ghép cặp lớn nhất (có trọng số) và phủ đỉnh nhỏ nhất trong đồ thị hai phía](../graph/graph-matching/bigraph-match.md#%E7%BA%BF%E6%80%A7%E8%A7%84%E5%88%92%E5%BD%A2%E5%BC%8F), v.v. đều có thể chuyển thành bài toán quy hoạch tuyến tính để giải. Hơn nữa, luồng cực đại và cắt nhỏ nhất, đường đi ngắn nhất và ràng buộc hiệu, ghép cặp lớn nhất trong đồ thị hai phía và phủ đỉnh nhỏ nhất, từng cặp một là các bài toán đối ngẫu của nhau.

Ngoài ra, còn có một số mô hình đồ thị thường gặp mà mọi nghiệm khả thi của chúng vừa đúng là toàn bộ các đỉnh của một đa bào có các đỉnh nguyên. Vì vậy, bằng cách chọn ràng buộc khéo léo, có thể làm cho nghiệm của bài toán tối ưu tổ hợp tương ứng đúng bằng nghiệm tối ưu của một bài toán quy hoạch tuyến tính. Ví dụ, ghép cặp trong đồ thị tổng quát và cây khung đều thuộc trường hợp này, nên các bài toán [ghép cặp lớn nhất (có trọng số) trong đồ thị tổng quát](../graph/graph-matching/general-weight-match.md) và [cây khung nhỏ nhất](../graph/mst.md) cũng có thể chuyển thành bài toán quy hoạch tuyến tính.

<span id="&#21442;&#32771;&#25991;&#29486;&#19982;&#27880;&#37322;"></span>
## Tài liệu tham khảo và ghi chú

-   Schrijver, Alexander. Theory of linear and integer programming. John Wiley & Sons, 1998.
-   Papadimitriou, Christos H., and Kenneth Steiglitz. Combinatorial optimization: algorithms and complexity. Courier Corporation, 1998.
-   [Duality in linear programming. Part 1: definition and construction. by adamant - Codeforces blog](https://codeforces.com/blog/entry/105049)
-   [Duality in linear programming. Part 2: in competitive programming. by adamant - Codeforces blog](https://codeforces.com/blog/entry/105789)

[^poly-names]: Các tài liệu khác nhau có thể định nghĩa hai thuật ngữ này theo những cách khác nhau: một số tài liệu gọi trường hợp bị chặn là "đa diện" và trường hợp không bị chặn là "đa bào"; một số tài liệu không giả định chúng nhất định là tập lồi; một số tài liệu dùng "đa diện" để chỉ đa bào trong không gian ba chiều. Bài này dùng định nghĩa nhất quán với các tài liệu như Schrijver (1998) và Boyd and Vandenberghe (2004).

[^reducible]: Phát biểu chặt chẽ hơn là các bài toán này có thể quy giảm lẫn nhau trong thời gian đa thức.

[^other-methods]: Các phương pháp khác để giải hệ bất đẳng thức còn có khử Fourier-Motzkin, phương pháp nới lỏng Agmon-Motzkin-Schoenberg, v.v. Chúng trực tiếp hơn nhưng thường không hiệu quả.
