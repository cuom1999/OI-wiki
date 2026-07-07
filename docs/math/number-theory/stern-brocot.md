<span id="mở-đầu"></span>
## Mở đầu

Bài viết này giới thiệu các cấu trúc dữ liệu dùng để lưu các phân số tối giản, cùng một số khái niệm liên quan. Chúng gắn rất chặt với [liên phân số](./continued-fraction.md), có thể dùng để giải một loạt bài toán số học trong lập trình thi đấu, và đôi khi xuất hiện như nền tảng ẩn của một số đề bài.

<span id="cây-stern-brocot"></span>
## Cây Stern-Brocot

Cây Stern-Brocot là một cấu trúc thanh nhã để quản lý phân số, chứa tất cả các số hữu tỉ dương phân biệt. Cấu trúc này được Moritz Stern phát hiện năm 1858 và Achille Brocot phát hiện độc lập năm 1861.

<span id="xây-dựng"></span>
### Xây dựng

<span id="xây-dựng-theo-từng-tầng"></span>
#### Xây dựng theo từng tầng

Cây Stern-Brocot có thể thu được trong quá trình lặp để xây dựng dãy Stern-Brocot bậc $k$ (Stern-Brocot sequence of order $k$). Dãy Stern-Brocot bậc $0$ gồm hai phân số biên:

$$
\frac{0}{1},\ \frac{1}{0}.
$$

Trong ngữ cảnh này, $\dfrac{1}{0}$ không phải là một phân số hữu tỉ theo nghĩa nghiêm ngặt; có thể hiểu nó là phân số tối giản biểu diễn $\infty$.

Giữa hai phân số kề nhau $\dfrac{a}{b}$ và $\dfrac{c}{d}$ trong dãy Stern-Brocot bậc $k$, chèn trung vị phân số (mediant)[^mediant] của chúng là $\dfrac{a+c}{b+d}$, thu được dãy Stern-Brocot bậc $k+1$. Dù định nghĩa của trung vị phân số có thể cho phép rút gọn phân số, trong quá trình xây dựng cây Stern-Brocot chỉ cần cộng riêng tử số và mẫu số, không cần lo việc rút gọn. Nhờ vậy, có thể xây dựng lặp các dãy Stern-Brocot ở mọi bậc. Một vài bước lặp đầu tiên như sau:

$$
\begin{array}{ccccccccc}
&&&\dfrac{0}{1}, & \dfrac{1}{1}, & \dfrac{1}{0} &&&\\\\
&&\dfrac{0}{1}, & \dfrac{1}{2}, & \dfrac{1}{1}, & \dfrac{2}{1}, & \dfrac{1}{0} &&\\\\
\dfrac{0}{1}, & \dfrac{1}{3}, & \dfrac{1}{2}, & \dfrac{2}{3}, & \dfrac{1}{1}, & \dfrac{3}{2}, & \dfrac{2}{1}, & \dfrac{3}{1}, & \dfrac{1}{0}
\end{array}
$$

Nối các phân số mới được thêm ở mỗi lần lặp thành một cấu trúc dạng cây sẽ nhận được cây Stern-Brocot, như hình dưới đây:

![](./images/stern-brocot-tree.svg)

Dãy Stern-Brocot bậc $k$, nếu bỏ hai đầu mút trái phải, chính là thứ tự duyệt trung tự của cây Stern-Brocot có độ sâu $k-1$.

<span id="xây-dựng-bằng-bộ-ba"></span>
#### Xây dựng bằng bộ ba

Một cách xây dựng tương đương khác là lấy bộ ba

$$
\left(\dfrac{0}{1},\dfrac{1}{1},\dfrac{1}{0}\right)
$$

làm nút gốc, và với mỗi nút

$$
\left(\dfrac{a}{b},\dfrac{p}{q},\dfrac{c}{d}\right)
$$

thì lần lượt thêm

$$
\left(\dfrac{a}{b},\dfrac{a+p}{b+q},\dfrac{p}{q}\right),\ \left(\dfrac{p}{q},\dfrac{p+c}{q+d},\dfrac{c}{d}\right)
$$

làm hai nút con trái và phải. Trong bộ ba được ghi ở mỗi nút của cây Stern-Brocot, phân số thực sự được lưu là phân số ở giữa $\dfrac{p}{q}$; hai phân số trái phải $\dfrac{a}{b}$ và $\dfrac{c}{d}$ là các phân số đã xuất hiện sớm hơn. Hơn nữa, nhìn từ cách xây dựng trước, phân số $\dfrac{p}{q}$ chính là trung vị phân số được chèn giữa $\dfrac{a}{b}$ và $\dfrac{c}{d}$.

<span id="biểu-diễn-ma-trận-và-hệ-đếm-stern-brocot"></span>
#### Biểu diễn ma trận và hệ đếm Stern-Brocot

Cách xây dựng bằng bộ ba cho thấy mỗi nút trên cây Stern-Brocot tương ứng với một ma trận

$$
S = \begin{pmatrix}
b & d\\
a & c
\end{pmatrix}.
$$

Nút gốc của cây Stern-Brocot là ma trận đơn vị $I$, còn di chuyển sang nút con trái và nút con phải lần lượt tương ứng với việc nhân phải ma trận hiện tại với

$$
L=\begin{pmatrix}
1 & 1 \\
0 & 1
\end{pmatrix},~
R=\begin{pmatrix}
1 & 0 \\
1 & 1
\end{pmatrix}.
$$

Phân số thực sự ứng với mỗi nút là $f(S)=\dfrac{a+c}{b+d}$. Ma trận $S$ của mỗi nút đều có thể viết thành tích của một dãy các ma trận $L$ và $R$; điều này cũng có thể hiểu là một chuỗi tạo bởi $L$ và $R$, biểu diễn đường đi từ gốc đến nút đó. Việc biểu diễn duy nhất mọi số hữu tỉ dương bằng một chuỗi như vậy có thể xem là một cách biểu diễn các số hữu tỉ dương, nên còn được gọi là **hệ đếm Stern-Brocot** (Stern-Brocot number system).

<span id="cài-đặt-xây-cây"></span>
#### Cài đặt xây cây

Thuật toán xây cây chỉ cần mô phỏng quá trình trên. Dưới đây là mã duyệt trung tự $n$ tầng đầu của cây Stern-Brocot.

???+ example "Xây cây"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/stern-brocot/tree-build.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/stern-brocot/tree-build.py:core"
        ```

Độ phức tạp của thuật toán xây cây là $O(n^2)$.

<span id="tính-chất"></span>
### Tính chất

Tiếp theo xét các tính chất của cây Stern-Brocot. Nói ngắn gọn, cây Stern-Brocot là một [cây tìm kiếm nhị phân](../../ds/bst.md) chứa tất cả các phân số hữu tỉ dương tối giản; nó cũng là một [đống](../../ds/binary-heap.md) theo tử số và mẫu số, đồng thời là [cây Descartes](../../ds/cartesian-tree.md) của các cặp gồm mẫu số và tử số. Nếu xét các đoạn được tạo bởi hai đầu mút trái phải trong cách xây dựng bằng bộ ba ở trên, cây Stern-Brocot cũng có thể xem là một [cây đoạn](../../ds/seg.md) trên $[0,\infty]$. Những phát biểu này đều có thể suy ra từ ba tính chất cơ bản sau.

<span id="tính-đơn-điệu"></span>
#### Tính đơn điệu

Trong cách xây dựng trên, các phân số ở mỗi tầng đều tăng đơn điệu. Chỉ cần chứng minh bằng quy nạp. Nếu $\dfrac{a}{b} < \dfrac{c}{d}$, thì tất yếu có

$$
\dfrac{a}{b} < \dfrac{a+c}{b+d} < \dfrac{c}{d}.
$$

Điều này nhận được bằng cách khử mẫu trong các bất đẳng thức. Cơ sở quy nạp là $\dfrac{0}{1} < \dfrac{1}{0}$, nên tính đơn điệu cũng đúng.

<span id="tính-tối-giản"></span>
#### Tính tối giản

Trong cách xây dựng trên, mọi phân số đều là phân số tối giản. Để chứng minh, cũng dùng quy nạp để chỉ ra rằng trong mỗi tầng của cách xây dựng trên, hai phân số kề nhau $\dfrac{a}{b}$ và $\dfrac{c}{d}$ luôn thỏa mãn

$$
bc-ad = \det\begin{pmatrix}
b & d\\
a & c
\end{pmatrix} = 1.
$$

Ở nút gốc có ma trận đơn vị, nên điều này đúng. Khi đi xuống, các ma trận được nhân thêm là $L$ và $R$, đều có định thức bằng $1$; theo tính chất của [định thức](../linear-algebra/determinant.md), ở tầng tiếp theo vẫn có

$$
\det\begin{pmatrix}b & b+d \\ a & a+c \end{pmatrix} = \det\begin{pmatrix}b+d & d \\ a+c & c\end{pmatrix} = 1.
$$

Với cơ sở quy nạp $\dfrac{0}{1}$ và $\dfrac{1}{0}$, điều này cũng đúng. Từ đó, theo [định lý Bezout](./bezouts.md), tử số và mẫu số của mọi phân số phải nguyên tố cùng nhau, tức mọi phân số đều tối giản.

<span id="tính-đầy-đủ"></span>
#### Tính đầy đủ

Cuối cùng, cần chỉ ra rằng cây Stern-Brocot chứa tất cả các phân số tối giản dương. Vì hai tính chất trước đã cho thấy cây Stern-Brocot là một cây tìm kiếm nhị phân, còn mọi phân số tối giản dương $\dfrac{p}{q}$ đều nằm giữa $\dfrac{0}{1}$ và $\dfrac{1}{0}$, nên theo cách tìm kiếm trên cây tìm kiếm nhị phân, khả năng duy nhất để trên cây không có $\dfrac{p}{q}$ là quá trình tìm kiếm kéo dài vô hạn. Điều này là không thể.

Giả sử hiện đã biết

$$
\dfrac{a}{b} < \dfrac{p}{q} < \dfrac{c}{d},
$$

khi đó tất yếu có

$$
bp-aq \ge 1,\ cq-dp \ge 1.
$$

Nhân hai bất đẳng thức lần lượt với $(c+d)$ và $(a+b)$, thu được

$$
(c+d)(bp-aq) + (a+b)(cq-dp) \ge a+b+c+d.
$$

Dùng đẳng thức đã chứng minh ở trên $bc-ad=1$, suy ra

$$
p+q \ge a+b+c+d.
$$

Mỗi lần quá trình tìm kiếm đi sâu thêm một tầng, vế phải của đẳng thức này tăng nghiêm ngặt, còn vế trái không đổi; do đó quá trình tìm kiếm sẽ dừng sau hữu hạn bước.

<span id="tìm-phân-số"></span>
### Tìm phân số

Trong ứng dụng thực tế của cây Stern-Brocot, thường cần truy vấn vị trí của một phân số cho trước trên cây Stern-Brocot.

<span id="thuật-toán-đơn-giản"></span>
#### Thuật toán đơn giản

Vì Stern-Brocot là cây tìm kiếm nhị phân, chỉ cần so sánh phân số hiện tại với phân số cần tìm để xác định đường đi từ gốc đến phân số đã cho. Ghi mỗi bước đi sang nút con trái và nút con phải lần lượt là $L$ và $R$, thì mỗi đường đi tương ứng với một chuỗi tạo bởi $L$ và $R$; đây chính là biểu diễn trong hệ đếm Stern-Brocot của số hữu tỉ đã nhắc ở trên. Quá trình tìm đường đi tới một số hữu tỉ tương đương với việc tìm biểu diễn của số hữu tỉ đó trong hệ đếm Stern-Brocot.

Cài đặt thuật toán tìm phân số đơn giản như sau:

???+ example "Tìm phân số đơn giản"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/stern-brocot/fraction-finding-1.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/stern-brocot/fraction-finding-1.py:core"
        ```

Độ phức tạp của thuật toán là $O(p+q)$, nên trong lập trình thi đấu nó không thực dụng.

Trong hệ đếm Stern-Brocot, mỗi số vô tỉ dương tương ứng với một chuỗi vô hạn duy nhất. Có thể dùng cùng thuật toán để xây dựng chuỗi này. Mỗi tiền tố của chuỗi vô hạn đó tương ứng với một phân số hữu tỉ tối giản. Khi xếp các phân số tối giản ấy thành một dãy, mẫu số của chúng tăng nghiêm ngặt và giới hạn của dãy chính là số vô tỉ đó. Vì vậy, cây Stern-Brocot có thể dùng để tìm xấp xỉ hữu tỉ với độ chính xác tùy ý cho một số vô tỉ. Tuy nhiên, khoảng cách giữa dãy số hữu tỉ này và số vô tỉ không nhất thiết giảm nghiêm ngặt. Để có lý thuyết chặt chẽ về xấp xỉ hữu tỉ, nên tham khảo mục [xấp xỉ Diophantine](./continued-fraction.md#xấp-xỉ-diophantine) trong trang liên phân số. Khi dùng cây Stern-Brocot để tìm xấp xỉ tốt nhất của một số thực với mẫu số không vượt quá một giới hạn nào đó, cuối cùng cần so sánh khoảng cách từ hai đầu mút của đoạn hiện tại đến số thực đó.

<span id="thuật-toán-nhanh"></span>
#### Thuật toán nhanh

Thuật toán tìm phân số đơn giản có hiệu quả không cao, nhưng chỉ cần tối ưu nhẹ là có thể thu được thuật toán tìm kiếm nhanh $O(\log(p+q))$. Điểm mấu chốt là gộp các đoạn $L$ liên tiếp và $R$ liên tiếp để xử lý cùng lúc.

Nếu phân số cần tìm $\dfrac{p}{q}$ nằm giữa $\dfrac{a}{b}$ và $\dfrac{c}{d}$, thì khi đi sang phải liên tiếp $t$ lần, biên phải giữ nguyên, còn nút biên trái chuyển đến $\dfrac{a+tc}{b+td}$; ngược lại, khi đi sang trái liên tiếp $t$ lần, biên trái giữ nguyên, còn nút biên phải chuyển đến $\dfrac{t a+c}{t b+d}$. Vì vậy, có thể trực tiếp dùng $\dfrac{a+tc}{b+td}<\dfrac{p}{q}$ hoặc $\dfrac{p}{q}<\dfrac{t a+c}{t b+d}$ để xác định số lần đi sang phải hoặc sang trái. Trong đoạn này dùng bất đẳng thức nghiêm ngặt vì thuật toán đang di chuyển hai đầu mút, còn phân số cần tìm xuất hiện dưới dạng trung vị phân số của hai đầu mút cuối cùng.

???+ example "Tìm phân số nhanh"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/stern-brocot/fraction-finding-2.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/stern-brocot/fraction-finding-2.py:core"
        ```

Thuật toán tìm kiếm hiện tại yêu cầu phân số $\dfrac{p}{q}$ đã biết. Nếu phân số mục tiêu chưa biết, thường cần tìm kiếm lũy thừa hai hoặc tìm kiếm nhị phân số bước mỗi lần đi sang phải hoặc sang trái. Khi đó, độ phức tạp của thuật toán tìm phân số là $O(\log^2(p+q))$.

<span id="thuật-toán-dựa-trên-liên-phân-số"></span>
#### Thuật toán dựa trên liên phân số

Với trường hợp phân số đã biết, có thể dùng liên phân số để thu được một thuật toán gọn hơn. Không mất tính tổng quát, giả sử nhóm bước đi đầu tiên là sang phải; nếu không, đặt số lần đi sang phải của nhóm đầu tiên bằng không. Di chuyển hai đầu mút xen kẽ sang phải và sang trái, rồi liệt kê vị trí đầu mút sau mỗi nhóm bước đi như sau:

$$
\dfrac{p_0}{q_0},~\dfrac{p_1}{q_1},~\dfrac{p_2}{q_2},~\cdots,~\dfrac{p_{n-2}}{q_{n-2}},~\dfrac{p_{n-1}}{q_{n-1}},~\dfrac{p_n}{q_n}.
$$

Trong đó, các nhóm chẵn là đi sang phải, nên ghi vị trí của đầu mút trái; các nhóm lẻ là đi sang trái, nên ghi vị trí của đầu mút phải. Trước dãy đầu mút này, thêm hai đầu mút

$$
\dfrac{p_{-2}}{q_{-2}}=\dfrac{0}{1},~\dfrac{p_{-1}}{q_{-1}}=\dfrac{1}{0}.
$$

Gọi số lần di chuyển của nhóm thứ $k$ là $t_k$. Theo quan hệ giữa số lần di chuyển và vị trí đầu mút đã suy ra ở trên, có

$$
\dfrac{p_k}{q_k} = \dfrac{t_kp_{k-1}+p_{k-2}}{t_kq_{k-1}+q_{k-2}}.
$$

Theo [quan hệ truy hồi](./continued-fraction.md#quan-hệ-truy-hồi) của liên phân số, biết rằng đầu mút

$$
\dfrac{p_k}{q_k} = [t_0,t_1,\cdots,t_k].
$$

Liên phân số cuối cùng nhận được là

$$
\dfrac{p}{q} = \dfrac{p_k+p_{k-1}}{q_k+q_{k-1}} = [t_0,t_1,\cdots,t_{n-1},t_n,1].
$$

Vì vậy, trong [biểu diễn liên phân số](./continued-fraction.md#liên-phân-số-đơn-giản) của phân số mục tiêu có phần tử cuối bằng một, nếu bỏ phần tử một cuối cùng thì các phần tử phía trước mã hóa đường đi từ gốc đến nút hiện tại trên cây Stern-Brocot. Trong đó, các phần tử chẵn (chỉ số bắt đầu từ $0$) là các cạnh đi sang nút con phải, còn các phần tử lẻ là các cạnh đi sang nút con trái.

Biểu diễn liên phân số của số hữu tỉ có thể tìm bằng thuật toán Euclid, nên thuật toán tìm phân số dựa trên biểu diễn liên phân số có độ phức tạp $O(\log\min\{p,q\})$.

???+ example "Tìm phân số dựa trên liên phân số"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/stern-brocot/fraction-finding-3.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/stern-brocot/fraction-finding-3.py:core"
        ```

Dùng biểu diễn liên phân số, có thể mô tả gọn nút cha và các nút con của một nút. Với nút $[t_0,t_1,\cdots,t_n,1]$, nút cha của nó là nút đi ít hơn một bước theo hướng di chuyển cuối cùng: khi $t_k>1$, nút cha là $[t_0,t_1,\cdots,t_n - 1,1]$; ngược lại, nút cha là $[t_0,t_1,\cdots,t_{n-1},1]$. Hai nút con của nó lần lượt là $[t_0,t_1,\cdots,t_n+1,1]$ và $[t_0,t_1,\cdots,t_n,1,1]$; nút nào là con trái và nút nào là con phải cần được xác định theo tính chẵn lẻ của $n$.

<span id="cây-calkin-wilf"></span>
## Cây Calkin-Wilf

Một cấu trúc gọn hơn để lưu các phân số hữu tỉ dương là cây Calkin-Wilf. Nó thường được vẽ như sau:

![Cây Calkin-Wilf của các phân số hữu tỉ dương](./images/calkin-wilf-tree.svg)

Nút gốc của cây là $\dfrac{1}{1}$. Với một nút chứa phân số $\dfrac{p}{q}$, hai nút con trái và phải lần lượt là $\dfrac{p}{p+q}$ và $\dfrac{p+q}{q}$. Tương tự cây Stern-Brocot, mọi phân số của nó đều tối giản, và nó chứa mỗi phân số tối giản dương đúng một lần.

<span id="quan-hệ-với-liên-phân-số"></span>
### Quan hệ với liên phân số

Khác với cây Stern-Brocot, cây Calkin-Wilf không phải cây tìm kiếm nhị phân, nên không thể dùng để tìm kiếm nhị phân các số hữu tỉ.

Trong cây Calkin-Wilf, khi $p>q$, nút cha của phân số $\dfrac{p}{q}$ là $\dfrac{p-q}{q}$; khi $p<q$, nút cha là $\dfrac{p}{q-p}$. Với trường hợp thứ nhất, bắt đầu từ $\dfrac{p}{q}$, nó là nút con phải của nút cha, nên có thể liên tục đi lên qua nhánh phải của nút cha cho đến khi tử số không còn lớn hơn mẫu số; khi đó phân số đang lưu ở nút là $\dfrac{p\bmod q}{q}$, và số lần di chuyển trong nhóm này là $\left\lfloor\dfrac{p}{q}\right\rfloor$. Với trường hợp thứ hai, nó là nút con trái của nút cha, nên có thể liên tục đi lên qua nhánh trái của nút cha cho đến khi mẫu số không còn lớn hơn tử số; khi đó phân số đang lưu ở nút là $\dfrac{p}{q\bmod p}$, và số lần di chuyển trong nhóm này là $\left\lfloor\dfrac{q}{p}\right\rfloor$.

Dùng ngôn ngữ liên phân số, giả sử nút hiện tại lưu một phần dư $s_k$ của liên phân số, thì đi lên theo nhánh phải của nút cha $\lfloor s_k\rfloor$ lần sẽ tới phân số $\dfrac{1}{s_{k+1}}$, sau đó đi theo nhánh trái của nút cha $\lfloor s_{k+1}\rfloor$ lần sẽ tới phân số $s_{k+2}$. Vì vậy, đường đi từ nút $s_0=\dfrac{p}{q}$ lên gốc $\dfrac{1}{1}$ được mã hóa bởi liên phân số $[t_0,t_1,\cdots,t_n,1]$: bỏ đi $1$ cuối cùng, các phần tử chẵn (chỉ số bắt đầu từ $0$) biểu thị số lần đi lên theo nhánh phải của nút cha, còn các phần tử lẻ biểu thị số lần đi lên theo nhánh trái của nút cha.

Với nút chứa phân số $\dfrac{p}{q}=[t_0,t_1,\cdots,t_n,1]$, nút cha của nó có biểu diễn như sau:

1.  Khi $t_0>0$, nút cha là $\dfrac{p-q}{q}=[t_0 - 1, t_1, \cdots, t_n,1]$.
2.  Khi $t_0=0$ và $t_1>1$, nút cha là $\dfrac{p}{q-p} = [0, t_1 - 1, t_2, \cdots, t_n,1]$.
3.  Khi $t_0=0$ và $t_1=1$, nút cha là $\dfrac{p}{q-p} = [t_2, t_3, \cdots, t_n,1]$.

Ngược lại, hai nút con của nó lần lượt là $\dfrac{p+q}{q}=[t_0+1,t_1,\cdots,t_n,1]$ và $\dfrac{p}{p+q}=[0,1,t_0,t_1,\cdots,t_n,1]$. Với biểu diễn liên phân số của nút con thứ hai, khi $t_0=0$ thì nên hiểu là $[0,1+t_1,\cdots,t_n,1]$.

<span id="quan-hệ-với-cây-stern-brocot"></span>
### Quan hệ với cây Stern-Brocot

Cùng thiết lập quan hệ với liên phân số, các nút trên đường đi trong cây Stern-Brocot thể hiện quan hệ truy hồi của các phân số hội tụ, còn các nút trên đường đi trong cây Calkin-Wilf thể hiện quan hệ truy hồi của các phần dư. Biểu diễn liên phân số của cùng một phân số là cố định, nên mã hóa đường đi từ nó đến gốc trong cây Calkin-Wilf hoàn toàn giống mã hóa đường đi từ gốc đến nó trong cây Stern-Brocot. Tuy nhiên, do hướng của đường đi ngược nhau, nên dù hai cây Stern-Brocot và Calkin-Wilf lưu cùng một tập phân số ở cùng một tầng, vị trí của chúng lại không giống nhau.

Nếu thực hiện [tìm kiếm theo chiều rộng](../../graph/bfs.md) trên hai cây và đánh số các nút theo thứ tự, với nút gốc được đánh số $1$, thì hai nút con trái và phải của nút số $v$ lần lượt là $2v$ và $2v+1$. Nhìn từ biểu diễn nhị phân của chỉ số, bỏ chữ số $1$ ở đầu, mỗi bit $1$ từ cao xuống thấp biểu thị đi sang nút con phải, còn mỗi bit $0$ biểu thị đi sang nút con trái. Trên cây Calkin-Wilf, chỉ số của nút chứa số hữu tỉ được biểu diễn bởi liên phân số $[t_0,t_1,\cdots,t_n,1]$ là

$$
1\cdots \underbrace{0\cdots 0}_{t_3}\underbrace{1\cdots 1}_{t_2}\underbrace{0\cdots 0}_{t_1}\underbrace{1\cdots 1}_{t_0}.
$$

Tương ứng, trên cây Stern-Brocot, chỉ số của nút chứa số hữu tỉ được biểu diễn bởi liên phân số $[t_0,t_1,\cdots,t_n,1]$ là

$$
1\underbrace{1\cdots 1}_{t_0}\underbrace{0\cdots 0}_{t_1}\underbrace{1\cdots 1}_{t_2}\underbrace{0\cdots 0}_{t_3}\cdots.
$$

Nếu xóa bit $1$ ban đầu, các bit nhị phân còn lại tạo thành chỉ số của đỉnh cùng tầng tính từ trái sang phải, bắt đầu từ $0$. Suy luận này cho thấy thứ tự các phân số ở cùng một tầng trong cây Stern-Brocot và cây Calkin-Wilf là hoán vị đảo bit (bit-reversal permutation) của nhau, tức hoán vị trên $0\sim (2^k-1)$ nhận được bằng cách đảo ngược các bit nhị phân của chỉ số sau khi bổ sung bit $0$ ở đầu nếu cần.

Chính vì vậy, các nút trên cây Stern-Brocot đôi khi được đánh số theo chỉ số của nút tương ứng trên cây Calkin-Wilf; cách đánh số đó được minh họa dưới đây:

![Đánh số các nút trên cây Stern-Brocot](./images/stern-brocot-index.svg)

Cách đánh số này có thể xây dựng đệ quy: nút gốc có chỉ số $1$; mỗi lần đi tới nút con trái, thay bit $1$ đầu tiên của chỉ số bằng $10$, còn khi đi tới nút con phải thì thay bit $1$ đầu tiên bằng $11$. Đọc chỉ số này từ phải sang trái sẽ thu được đường đi từ gốc đến nút đó.

<span id="dãy-hai-nguyên-tử-stern"></span>
### Dãy hai nguyên tử Stern

Sắp xếp tất cả phân số trong cây Calkin-Wilf theo chỉ số tìm kiếm theo chiều rộng, hoặc sắp xếp tất cả phân số trong cây Stern-Brocot theo cách đánh số trong hình trên, thu được dãy sau:

$$
\frac{1}{1},~\dfrac{1}{2},~\dfrac{2}{1},~\dfrac{1}{3},~\dfrac{3}{2},~\dfrac{2}{3},~\dfrac{3}{1},~\dfrac{1}{4},~\dfrac{4}{3},~\dfrac{3}{5},~\dfrac{5}{2},\cdots.
$$

Dùng quá trình xây dựng cây Calkin-Wilf, có thể chứng minh rằng với hai phân số kề nhau trong dãy này, mẫu số của phân số trước luôn bằng tử số của phân số sau. Lấy riêng các tử số ra sẽ thu được dãy hai nguyên tử Stern (Stern diatomic sequence, [OEIS A002487](https://oeis.org/A002487)), còn được gọi là dãy Stern-Brocot (Stern-Brocot sequence). Dãy phân số ở trên được đánh số bắt đầu từ $1$, đồng thời quy ước bổ sung phần tử thứ $0$ bằng $0$.

Gọi $a_n$ là phần tử thứ $n$ trong dãy hai nguyên tử Stern. Khi đó nó thỏa mãn quan hệ truy hồi:

$$
\begin{aligned}
a_{2n} &= a_n,\\
a_{2n+1} &= a_n + a_{n+1}. 
\end{aligned}
$$

Cơ sở truy hồi là $a_0=0$ và $a_1=1$. Để tính giá trị $a_n$ trong dãy hai nguyên tử Stern, dùng trực tiếp quan hệ truy hồi có độ phức tạp $O(\log^2n)$, chưa tốt. Cách tốt hơn là xem nó là tử số của phân số có chỉ số $n$ trên cây Calkin-Wilf, rồi dùng quan hệ truy hồi dựa trên liên phân số đã mô tả ở trên; độ phức tạp là $O(\log n)$.

<span id="dãy-farey"></span>
## Dãy Farey

Dãy Farey có những đặc trưng rất giống cây Stern-Brocot. Ký hiệu **dãy Farey bậc $n$** (Farey sequence of order $n$) là $F_n$. Nó là dãy thu được bằng cách sắp xếp theo thứ tự tăng dần tất cả các phân số tối giản nằm trong $[0,1]$ có mẫu số không vượt quá $n$:

$$
\begin{array}{lllllllllllll}
F_1=\bigg\{&\dfrac{0}{1},&&&&&&&&&&\dfrac{1}{1}&\bigg\}\\\\
F_2=\bigg\{&\dfrac{0}{1},&&&&&\dfrac{1}{2},&&&&&\dfrac{1}{1}&\bigg\}\\\\
F_3=\bigg\{&\dfrac{0}{1},&&&\dfrac{1}{3},&&\dfrac{1}{2},&&\dfrac{2}{3},&&&\dfrac{1}{1}&\bigg\}\\\\
F_4=\bigg\{&\dfrac{0}{1},&&\dfrac{1}{4},&\dfrac{1}{3},&&\dfrac{1}{2},&&\dfrac{2}{3},&\dfrac{3}{4},&&\dfrac{1}{1}&\bigg\}\\\\
F_5=\bigg\{&\dfrac{0}{1},&\dfrac{1}{5},&\dfrac{1}{4},&\dfrac{1}{3},&\dfrac{2}{5},&\dfrac{1}{2},&\dfrac{3}{5},&\dfrac{2}{3},&\dfrac{3}{4},&\dfrac{4}{5},&\dfrac{1}{1}&\bigg\}
\end{array}
$$

Theo định nghĩa của dãy Farey, nó tự nhiên thỏa mãn tính đơn điệu, tính tối giản và tính đầy đủ. Như hình trên cho thấy, các phân số mới được thêm vào $F_k$ so với $F_{k-1}$ luôn là trung vị phân số của hai phân số kề nhau trong $F_{k-1}$.

Thuật toán xây cây Stern-Brocot ở trên cũng có thể dùng để xây dựng dãy Farey. Vì cây Stern-Brocot chứa tất cả phân số tối giản, chỉ cần đổi điều kiện biên thành giới hạn trên mẫu số là có thể nhận được mã xây dựng dãy Farey. Có thể xem dãy Farey bậc $n$, tức $F_n$, là một dãy con của dãy Stern-Brocot bậc $n-1$.

???+ example "Xây dựng dãy Farey"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/stern-brocot/farey-build.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/stern-brocot/farey-build.py:core"
        ```

Độ phức tạp của việc xây dựng trực tiếp dãy Farey là $O(|F_n|)=O(n^2)$.

<span id="độ-dài-dãy-và-tìm-phân-số"></span>
### Độ dài dãy và tìm phân số

Độ dài của dãy Farey có thể tính bằng truy hồi. So với $F_{n-1}$, các phân số mới xuất hiện trong $F_n$ đều có mẫu số là $n$, còn tử số không vượt quá $n$ và nguyên tố cùng nhau với $n$, nên có:

$$
\begin{aligned}
|F_n| &= |F_{n-1}| + \varphi(n) = 1 + \sum_{k=1}^n\varphi(k).
\end{aligned}
$$

Tại đây $\varphi(n)$ là [hàm Euler](./euler-totient.md). Công thức này có thể được tính trong $O(n)$ bằng [sàng tuyến tính](./sieve.md#tính-hàm-euler-bằng-sàng), và giảm xuống $O(n^{2/3})$ bằng [sàng Du](./du.md#bài-toán-1).

So với việc trực tiếp tính độ dài dãy, tình huống thường gặp hơn là cần tìm chỉ số của một phân số $r=\dfrac{p}{q}$ trong dãy $F_k$. Điều này tương đương với việc tính

$$
1 + \sum_{k = 1}^n\sum_{i=1}^{\lfloor rk\rfloor}[i\perp k] = 1 + \sum_{d=1}^n\mu(d)\sum_{j=1}^{\lfloor n/d\rfloor}\lfloor rj\rfloor.
$$

Để thu được vế phải, áp dụng [nghịch đảo Möbius](./mobius.md). Kết hợp sàng tuyến tính với việc liệt kê ước, có thể đạt $O(n)$ tiền xử lý và $O(n\log n)$ cho mỗi truy vấn; kết hợp sàng Du với [thuật toán Euclid mở rộng](./euclidean.md), có thể đạt $O(n^{2/3})$ tiền xử lý và $O(\sqrt n\log n)$ cho mỗi truy vấn.

Ngược lại, nếu biết chỉ số và cần tìm phân số, cần tìm kiếm nhị phân trên các số thực trong $[0,1]$, hoặc [tìm kiếm nhị phân](#thuật-toán-nhanh) trên cây Stern-Brocot. Cách trước có thể chịu ảnh hưởng của sai số số thực, và cần $O(\log V)$ truy vấn chỉ số phân số, trong đó $V$ là phạm vi độ chính xác; cách sau không chịu giới hạn bởi sai số số thực, nhưng cần $O(\log^2n)$ truy vấn chỉ số phân số.

<span id="các-phần-tử-kề-farey"></span>
### Các phần tử kề Farey

Nếu hai phân số $\dfrac{a}{b}$ và $\dfrac{c}{d}$ kề nhau trong một dãy Farey nào đó, gọi chúng là **hai phần tử kề Farey** (Farey neighbors), cũng gọi là **cặp Farey** (Farey pair).

Giả sử $\dfrac{a}{b}<\dfrac{c}{d}$. Từ quá trình xây dựng dãy Farey, trong hai phân số kề nhau, phân số được thêm vào sau là trung vị phân số của phân số còn lại với phần tử kề trước đó của nó. Do vậy, hai phần tử kề Farey cũng kề nhau trong một dãy Stern-Brocot bậc nào đó; theo kết luận đã chứng minh trong phần [tính tối giản](#tính-tối-giản), tất yếu có

$$
bc-ad=1.
$$

Ngược lại, đây cũng là điều kiện đủ để hai phân số thực tối giản trở thành hai phần tử kề Farey. Chứng minh như sau. Không mất tính tổng quát, giả sử $\dfrac{a}{b}$ là phân số có mẫu số lớn hơn trong hai phân số, khi đó cả hai phân số đều xuất hiện trong $F_b$. Gọi $\dfrac{e}{f}$ là một phần tử trong dãy $F_b$ nằm ngay bên phải $\dfrac{a}{b}$. Theo tính cần thiết đã nêu, có $be-af=1$. Nhưng [phương trình đồng dư tuyến tính](./linear-equation.md) $bx-ay=1$ chỉ có một nghiệm nguyên dương với $y\le b$, nên tất yếu $(e,f)=(c,d)$.

Vì phân số tối giản tiếp theo sẽ xuất hiện giữa hai phân số đó là $\dfrac{a+c}{b+d}$, nên $\dfrac{a}{b}$ và $\dfrac{c}{d}$ kề nhau trong mọi dãy Farey từ bậc $\max\{b,d\}$ đến bậc $(b+d-1)$.

Quan hệ giữa các phần tử kề Farey có mẫu số không vượt quá $9$ được minh họa dưới đây:

![](./images/farey-diagram-ford-circle.svg)

Các đường tròn trong hình được gọi là [đường tròn Ford](https://en.wikipedia.org/wiki/Ford_circle): với mỗi phân số tối giản $\dfrac{p}{q}$ trong $[0,1]$, vẽ một đường tròn có tâm $\left(\dfrac{p}{q},\dfrac{1}{2q^2}\right)$ và bán kính $\dfrac{1}{2q^2}$. Hình này cho thấy hai đường tròn Ford ứng với hai phân số chỉ có thể tiếp xúc hoặc rời nhau, và hai đường tròn tiếp xúc khi và chỉ khi hai phân số là hai phần tử kề Farey. Hơn nữa, với bất kỳ hai đường tròn tiếp xúc nào trong hình, luôn tồn tại duy nhất một đường tròn thứ ba tiếp xúc với cả hai; phân số ứng với đường tròn thứ ba này chính là trung vị phân số của hai phân số ứng với hai đường tròn ban đầu.

Để kiểm tra rằng các đường tròn tiếp xúc luôn ứng với hai phần tử kề Farey, có thể tính trực tiếp khoảng cách giữa hai tâm:

$$
\left(\dfrac{a}{b}-\dfrac{c}{d}\right)^2 + \left(\dfrac{1}{2b^2}-\dfrac{1}{2d^2}\right)^2 = \left(\dfrac{1}{2b^2}+\dfrac{1}{2d^2}\right)^2+\frac{(bc-ad)^2-1}{b^2d^2}.
$$

Vì hai phân số tối giản là khác nhau, nên $|bc-ad|\ge 1$; do đó hai đường tròn chỉ có thể tiếp xúc hoặc rời nhau. Hơn nữa, hai đường tròn tiếp xúc khi và chỉ khi $|bc-ad|=1$, điều này tương đương với việc hai phân số là hai phần tử kề Farey.

Cuối cùng, tính số cặp phần tử kề Farey. Ngoại trừ $\left(\dfrac{0}{1},\dfrac{1}{1}\right)$, các cặp kề Farey còn lại đều có mẫu số khác nhau. Không mất tính tổng quát, giả sử $\dfrac{p}{q}$ là phân số có mẫu số lớn hơn trong cặp đó, thì phân số còn lại có thể được tìm từ phương trình Diophantine tuyến tính hai ẩn

$$
qx-py=\pm 1
$$

Hai phương trình này mỗi phương trình có đúng một nghiệm nguyên dương thỏa mãn $y<q$, lần lượt ứng với hai phần tử kề nằm bên trái và bên phải của $\dfrac{p}{q}$. Vì vậy, mỗi phân số thực trong $(0,1)$ đều có hai phần tử kề Farey với mẫu số nhỏ hơn mẫu số của nó; cộng thêm $\dfrac{0}{1}$ và $\dfrac{1}{1}$, suy ra dãy $F_n$ có tổng cộng $(2|F_n|-3)$ cặp phần tử kề Farey.

Hai phân số $\dfrac{a}{b}<\dfrac{c}{d}$ tìm được trong quá trình này chính là hai phần tử kề trái phải khi chèn $\dfrac{p}{q}$ vào dãy. Vì vậy, bản thân chúng là hai phần tử kề Farey và $\dfrac{p}{q}$ là trung vị phân số của chúng. Giả sử $\dfrac{p}{q}=[t_0,t_1,\cdots,t_n,1]$, thì hai phần tử kề Farey có mẫu số nhỏ hơn này lần lượt là $[t_0,t_1,\cdots,t_n]$ và $[t_0,t_1,\cdots,t_{n-1}]$.

Để tính các phần tử kề Farey khác của phân số hiện tại $\dfrac{p}{q}$, chỉ cần dùng [thuật toán Euclid mở rộng](./bezouts.md#trường-hợp-hai-biến) để tìm tất cả nghiệm thỏa mãn điều kiện.

<span id="quan-hệ-truy-hồi"></span>
### Quan hệ truy hồi

Dãy Farey có một quan hệ truy hồi gọn, có thể dùng để sinh toàn bộ phân số của dãy Farey bậc $n$ theo thứ tự từ trái sang phải.

Trước hết, phân tích ở trên chỉ ra rằng trong $F_n$, phần tử mới được thêm $\dfrac{p}{n}$ luôn là trung vị phân số của hai phân số kề trái phải. Quan hệ này đúng với mọi phân số trong $F_n$ trừ hai đầu mút. Giả sử $\dfrac{a}{b}<\dfrac{p}{q}<\dfrac{c}{d}$, theo điều kiện cần và đủ của hai phần tử kề Farey, luôn có

$$
bp-aq = 1 = cq-dp \iff \frac{p}{q} = \dfrac{a+c}{b+d}.
$$

Tuy nhiên, trong trường hợp tổng quát, phân số $\dfrac{a+c}{b+d}$ có thể cần được rút gọn.

Dùng quan sát này, có thể xây dựng quan hệ truy hồi sau. Giả sử đã biết $\dfrac{a}{b}$ và $\dfrac{p}{q}$, cần tìm giá trị của phân số thứ ba $\dfrac{c}{d}$. Khi đó tồn tại $k$ sao cho

$$
a+c = kp,\ b+d=kq
$$

đúng. Vì hiệu

$$
\frac{kp-a}{kq-b} - \dfrac{p}{q} = \dfrac{bp-aq}{q(kq-b)} = \dfrac{1}{q(kq-b)}
$$

giảm khi $k$ tăng, và phân số kề ngay $\dfrac{p}{q}$ phải là phân số có hiệu nhỏ nhất trong số các phân số thỏa mãn $kq-d\le n$, nên tất yếu có

$$
k = \left\lfloor\dfrac{n+b}{q}\right\rfloor.
$$

Có thể kiểm chứng rằng phân số nhận được theo cách này luôn nằm trong $F_n$. Vì vậy, tử số và mẫu số của các phân số trong $F_n$ thỏa mãn quan hệ truy hồi:

$$
\begin{aligned}
p_k &= \left\lfloor\frac{n + q_{k-2}}{q_{k-1}}\right\rfloor p_{k-1} - p_{k-2},\\
q_k &= \left\lfloor\frac{n + q_{k-2}}{q_{k-1}}\right\rfloor q_{k-1} - q_{k-2}.
\end{aligned}
$$

Cơ sở truy hồi là $(p_0,q_0)=(0,1)$ và $(p_1,q_1)=(1,n)$.

<span id="bài-tập"></span>
## Bài tập

Các bài toán có nền tảng là nội dung trong bài này:

-   [LOJ 6685. Mê cung](https://loj.ac/p/6685)
-   [UVa 10077. Hệ đếm Stern-Brocot](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=33&page=show_problem&problem=1018)
-   [Luogu P8058. \[BalkanOI2003\] Dãy Farey](https://www.luogu.com.cn/problem/P8058)
-   [UVa 12995. Dãy Farey](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=862&page=show_problem&problem=4878)
-   [UVa 10408. Các dãy Farey](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1349)
-   [UVa 12438. Đa giác Farey](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=279&page=show_problem&problem=3869)
-   [AtCoder ARC123F. Chèn phép cộng](https://atcoder.jp/contests/arc123/tasks/arc123_f)

Các bài toán cần tìm kiếm nhị phân trên cây Stern-Brocot:

-   [AtCoder ABC333G. Phân số gần nhất](https://atcoder.jp/contests/abc333/tasks/abc333_g)
-   [SPOJ DIVCNT1 - Đếm ước](https://www.spoj.com/problems/DIVCNT1/)
-   [SPOJ AFS3 - Dãy thừa số kỳ diệu (khó)](https://www.spoj.com/problems/AFS3/)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [Cây Stern-Brocot - Wikipedia](https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree)
-   [Cây Calkin-Wilf - Wikipedia](https://en.wikipedia.org/wiki/Calkin%E2%80%93Wilf_tree)
-   [Dãy Farey - Wikipedia](https://en.wikipedia.org/wiki/Farey_sequence)

**Một phần nội dung của trang này được dịch từ bài viết [Дерево Штерна-Броко. Ряд Фарея](http://e-maxx.ru/algo/stern_brocot_farey) và bản dịch tiếng Anh [Cây Stern-Brocot và dãy Farey](https://cp-algorithms.com/others/stern_brocot_tree_farey_sequences.html). Bản tiếng Nga có giấy phép Public Domain + Leave a Link; bản tiếng Anh có giấy phép CC-BY-SA 4.0. Trang này cũng có một phần nội dung được dịch từ bài viết [Liên phân số](https://cp-algorithms.com/algebra/continued-fractions.html), giấy phép CC-BY-SA 4.0. Nội dung đều đã được chỉnh sửa.**

[^mediant]: Tên gọi trong tiếng Việt được dịch theo nghĩa của thuật ngữ "mediant".
