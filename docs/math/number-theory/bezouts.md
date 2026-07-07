Định lý Bézout cho thấy mối liên hệ sâu sắc giữa ước chung lớn nhất và tổ hợp
tuyến tính nguyên. Đây là một trong những kết quả cơ bản và quan trọng nhất của
số học. Dựa trên đó, bài này tiếp tục thảo luận cách giải phương trình nghiệm
nguyên tuyến tính.

<span id="định-lý-bézout"></span>
## Định lý Bézout

**Định lý Bézout** (Bézout's lemma), còn gọi là **đồng nhất thức Bézout**
(Bézout's identity), cho điều kiện cần và đủ để một số nguyên có thể biểu diễn
thành tổ hợp tuyến tính với hệ số nguyên của hai số nguyên.

???+ note "Định lý Bézout"
    Cho $a,b$ là hai số nguyên không đồng thời bằng $0$. Khi đó, với mọi số
    nguyên $x,y$, luôn có $\gcd(a,b)\mid ax+by$; đồng thời tồn tại các số nguyên
    $x,y$ sao cho $ax+by=\gcd(a,b)$.

??? note "Chứng minh"
    Đặt $d=\gcd(a,b)$. Vì $d\mid a,b$, tồn tại các số nguyên $u,v$ sao cho
    $a=du,~b=dv$. Do đó luôn có

    $$
    ax + by = d(ux+vy).
    $$

    Suy ra $d\mid ax+by$.

    Ngược lại, cần chứng minh tồn tại $x,y$ để đẳng thức trên đúng. Nếu một
    trong hai số $a,b$ bằng $0$, không mất tính tổng quát giả sử $b=0$; khi đó
    ước chung lớn nhất của chúng là $d=|a|$, chọn $x=1$ nếu $a>0$ và $x=-1$ nếu
    $a<0$, cùng $y=0$, thì đẳng thức đúng. Tiếp theo xét trường hợp $a,b$ đều
    khác $0$. Do $\gcd(a,b)=\gcd(-a,b)=\gcd(a,-b)$, có thể giả sử $a,b$ đều
    dương.

    Xét quá trình thuật toán Euclid:

    $$
    \begin{aligned}
    a   &= q_1b   + r_1, && 0\le r_1 < b,\\
    b   &= q_2r_1 + r_2, && 0\le r_2 < r_1,\\
    r_1 &= q_3r_2 + r_3, && 0\le r_3 < r_2,\\
        & \cdots \\
    r_{n-3} &= q_{n-1}r_{n-2} + r_{n-1}, && 0\le r_{n-1} < r_{n-2},\\
    r_{n-2} &= q_nr_{n-1} + r_n,         && 0\le r_n     < r_{n-1},\\
    r_{n-1} &= q_{n+1}r_n.
    \end{aligned}
    $$

    Vì ước chung lớn nhất là $d$, ở bước cuối của thuật toán Euclid có
    $r_n=d$. Do đó đẳng thức áp chót có thể viết thành

    $$
    d = r_n = r_{n-2} - q_nr_{n-1}.
    $$

    Từ đẳng thức đứng trước nó, suy ra

    $$
    r_{n-1} = r_{n-3} - q_{n-1}r_{n-2}
    $$

    rồi thế vào đẳng thức trên để khử $r_{n-1}$:

    $$
    \begin{aligned}
    d &= r_{n-2} - q_n(r_{n-3} - q_{n-1}r_{n-2}) \\
    &= (1 + q_nq_{n-1})r_{n-2} - q_nr_{n-3}.
    \end{aligned}
    $$

    Tương tự, có thể lần lượt khử tất cả $r_{n-2},r_{n-3},\cdots,r_2,r_1$, cuối
    cùng thu được

    $$
    d = xa + yb.
    $$

    Vậy tồn tại $x,y$ sao cho $ax+by=d$. Kết hợp với phần trên, mệnh đề ban đầu
    được chứng minh.

Chứng minh về tính tồn tại này mang tính xây dựng, đồng thời cho một cách tính
các hệ số. Cách tính đó chính là [thuật toán Euclid mở rộng](./gcd.md#thuật-toán-euclid-mở-rộng).

Xét trường hợp đặc biệt $\gcd(a,b)=1$ của định lý Bézout, thu được hệ quả sau:

???+ note "Hệ quả"
    Hai số nguyên $a,b$ nguyên tố cùng nhau khi và chỉ khi tồn tại các số nguyên
    $x,y$ sao cho $ax+by=1$.

<span id="trường-hợp-nhiều-số-nguyên"></span>
### Trường hợp nhiều số nguyên

Định lý Bézout có thể mở rộng cho trường hợp nhiều số nguyên.

???+ note "Định lý"
    Cho $a_1,a_2,\cdots,a_n$ là các số nguyên không đồng thời bằng $0$. Khi đó,
    với mọi số nguyên $x_1,x_2,\cdots,x_n$, luôn có
    $\gcd(a_1,a_2,\cdots,a_n)\mid a_1x_1+a_2x_2+\cdots+a_nx_n$; đồng thời tồn
    tại các số nguyên $x_1,x_2,\cdots,x_n$ sao cho
    $\gcd(a_1,a_2,\cdots,a_n)=a_1x_1+a_2x_2+\cdots+a_nx_n$.

??? note "Chứng minh"
    Sử dụng đẳng thức
    $\gcd(a_1,a_2,\cdots,a_n)=\gcd(\gcd(a_1,a_2,\cdots,a_{n-1}),a_n)$ và quy
    nạp theo $n$.

<span id="ví-dụ"></span>
### Ví dụ

???+ example "[Codeforces 510 D. Fox And Jumping](https://codeforces.com/problemset/problem/510/D)"
    Cho $n\le 300$ tấm thẻ, tấm thứ $i$ có hai giá trị $l_i$ và $c_i$. Trên một
    băng giấy dài vô hạn, được phép trả $c_i$ để mua thẻ $i$; từ đó trở đi, được
    phép nhảy sang trái hoặc sang phải đúng $l_i$ đơn vị với số lần bất kỳ. Hỏi
    cần ít nhất bao nhiêu tiền để có thể nhảy tới mọi vị trí trên băng giấy. Nếu
    không thể, in ra $-1$.

??? note "Lời giải"
    Phân tích bài toán cho thấy: muốn nhảy tới mọi ô, các số đã chọn
    $l_{i_1}, \cdots, l_{i_k}$ phải có thể cộng hoặc trừ một số lần để thu được
    giá trị tuyệt đối bằng $1$. Nói cách khác, tồn tại các số nguyên
    $x_1, \cdots, x_k$ sao cho
    $l_{i_1} x_1 + \cdots + l_{i_k} x_k = 1$. Theo định lý Bézout cho nhiều số
    nguyên, điều này tương đương với việc chọn một số phần tử từ mảng
    $l_1, \cdots, l_n$ sao cho ước chung lớn nhất của chúng bằng $1$, đồng thời
    tổng chi phí nhỏ nhất.

    **Cách 1**: Xem tổng chi phí nhỏ nhất là một bài toán đường đi ngắn nhất và
    giải bằng thuật toán Dijkstra. Mỗi đỉnh của đồ thị lưu giá trị ước chung lớn
    nhất hiện tại. Đỉnh bắt đầu là $0$, đỉnh đích là $1$. Mỗi bước, từ đỉnh hiện
    tại $x$, đi theo cạnh có độ dài $c_i$ đến đỉnh $\gcd(x,l_i)$. Độ phức tạp
    thời gian của thuật toán này là $O(n^2\log n)$.

    **Cách 2**: Chọn một số phần tử từ mảng $l_1, \cdots, l_n$ sao cho ước chung
    lớn nhất của chúng bằng $1$ và tổng chi phí nhỏ nhất; từ đó có thể liên
    tưởng đến bài toán ba lô 0-1.

    Đặt $f_{i, j}$ là chi phí nhỏ nhất khi xét $i$ số đầu tiên và ước chung lớn
    nhất bằng $j$. Khi đó có chuyển trạng thái:

    $$
    f_{i, j} = \min_{\gcd(k, l_i) = j} f_{i - 1, k} + c_i.
    $$

    Sau DP, tổng chi phí cần tìm là $f_{n, 1}$.

    Giống bài toán ba lô 0-1 thông thường, có thể dùng mảng cuộn để bỏ chiều đầu
    tiên. Hơn nữa, với 300 số, các giá trị ước chung lớn nhất $j$ có thể tạo ra
    khá thưa, nên có thể dùng bảng băm để lưu trữ.

    Đồ thị được xây dựng trong cách 1 chính là đồ thị chuyển trạng thái của quy
    hoạch động trong cách 2; cách 2 tương đương với việc dùng quy hoạch động để
    tìm đường đi ngắn nhất trên đồ thị có hướng không chu trình. Vì vậy cách 1 và
    cách 2 là tương đương. Tuy nhiên, cách 2 không cần lưu toàn bộ đồ thị, và độ
    phức tạp thời gian của DP là $O(n + m)$, nhỏ hơn Dijkstra, nên tốt hơn về cả
    thời gian lẫn bộ nhớ.

<span id="phương-trình-nghiệm-nguyên-tuyến-tính"></span>
## Phương trình nghiệm nguyên tuyến tính

**Phương trình nghiệm nguyên tuyến tính** (linear Diophantine equation) có dạng

$$
a_1x_1 + a_2x_2 + \cdots + a_nx_n = b
$$

trong đó $a_1,a_2,\cdots,a_n$ đều là số nguyên. Mục tiêu của phần này là tìm
toàn bộ nghiệm nguyên của nó.

<span id="trường-hợp-hai-biến"></span>
### Trường hợp hai biến

Trước hết xét phương trình nghiệm nguyên tuyến tính hai biến:

$$
a_1x_1 + a_2x_2 = b.
$$

Định lý Bézout chỉ ra rằng phương trình có nghiệm khi và chỉ khi

$$
d = \gcd(a_1,a_2) \mid b.
$$

Tiếp theo, giả sử điều kiện này đúng. Dùng thuật toán Euclid mở rộng có thể tìm
được một nghiệm nguyên $(x_1^*,x_2^*)$ của phương trình
$a_1x_1 + a_2x_2 = d$. Từ đó thu được một nghiệm riêng của phương trình ban đầu:

$$
(x_1^\circ,x_2^\circ) = \left(\frac{b}{d}x_1^*,\frac{b}{d}x_2^*\right).
$$

Để thu được tất cả nghiệm, lấy phương trình ban đầu trừ đi đồng nhất thức
$a_1x_1^\circ+a_2x_2^\circ = b$, thu được

$$
a_1(x_1 - x_1^\circ) + a_2(x_2 - x_2^\circ) = 0.
$$

Đây là một phương trình nghiệm nguyên tuyến tính thuần nhất theo
$(x_1-x_1^\circ,x_2-x_2^\circ)$, với nghiệm tổng quát

$$
(x_1-x_1^\circ,x_2-x_2^\circ) = \left(t\dfrac{a_2}{d},-t\dfrac{a_1}{d}\right).\quad(t\in\mathbf Z)
$$

Do đó nghiệm tổng quát của phương trình ban đầu là

$$
(x_1,x_2) = \left(x_1^\circ + t\dfrac{a_2}{d},x_2^\circ - t\dfrac{a_1}{d}\right).\quad(t\in\mathbf Z)
$$

Đây là một dãy các điểm nguyên cách đều trên đường thẳng $a_1x_1+a_2x_2 = b$.

<span id="trường-hợp-nhiều-biến"></span>
### Trường hợp nhiều biến

Sau khi giải được trường hợp hai biến, trường hợp nhiều biến cũng dễ xử lý. Với
phương trình nghiệm nguyên tuyến tính $n$ biến

$$
a_1x_1 + a_2x_2 + \cdots + a_nx_n = b,\quad (n>2)
$$

theo định lý Bézout, phương trình có nghiệm khi và chỉ khi

$$
\gcd(a_1,a_2,\cdots,a_n) \mid b.
$$

Tương tự trường hợp hai biến, nghiệm tổng quát của phương trình nghiệm nguyên
tuyến tính nhiều biến cũng có thể viết dưới dạng

$$
(x_1^\circ,x_2^\circ,\cdots,x_n^\circ) + \sum_{k=1}^{n-1} t_k(x_1^{(k)},x_2^{(k)},\cdots,x_n^{(k)})
$$

trong đó $x^\circ$ là một nghiệm riêng, còn $x^{(k)}$ là $(n-1)$ nghiệm của
phương trình thuần nhất tương ứng.

Để tìm dạng cụ thể của nghiệm tổng quát, có thể đưa phương trình $n$ biến về
phương trình $(n-1)$ biến. Không mất tính tổng quát, đặt
$d_1 = \gcd(a_1,a_2)$. Khi đó, theo định lý Bézout, tập tất cả giá trị của
$a_1x_1+a_2x_2$ chính là tập các bội của $d_1$. Vì vậy, trước hết giải phương
trình nghiệm nguyên tuyến tính $(n-1)$ biến:

$$
d_1y_1 + a_3x_3 + a_4x_4 + \cdots + a_nx_n = b.
$$

Giả sử nghiệm tổng quát của phương trình này là

$$
\begin{aligned}
y_1 &= y_1^\circ + \sum_{k=2}^{n-1}t_ky_1^{(k)}, \\
x_i &= x_i^\circ + \sum_{k=2}^{n-1}t_kx_i^{(k)},\quad i=3,\cdots,n.
\end{aligned}
$$

Giả sử $(x_1^*,x_2^*)$ là một nghiệm riêng của $a_1x_1+a_2x_2=d_1$. Khi đó,
theo phần trước, nghiệm tổng quát theo $x_1,x_2$ của phương trình hai biến
$a_1x_1+a_2x_2=d_1y_1$ là

$$
x_1 = x_1^*y_1 + t_1\dfrac{a_2}{d_1},~x_2 = x_2^*y_1 - t_1\dfrac{a_1}{d_1}.
$$

Thế biểu thức của $y_1$ vào sẽ thu được nghiệm tổng quát của phương trình ban
đầu:

$$
\begin{aligned}
x_1 &= x_1^*y_1^\circ + t_1\dfrac{a_2}{d_1} + \sum_{k=2}^{n-1}t_kx_1^*y_1^{(k)}, \\
x_2 &= x_2^*y_1^\circ - t_1\dfrac{a_1}{d_1} + \sum_{k=2}^{n-1}t_kx_2^*y_1^{(k)}, \\
x_i &= x_i^\circ + \sum_{k=2}^{n-1}t_kx_i^{(k)},\quad i=3,\cdots,n.
\end{aligned}
$$

<span id="bài-toán-đồng-xu-frobenius"></span>
## Bài toán đồng xu Frobenius

Định lý Bézout cho điều kiện cần và đủ để một số nguyên có thể được biểu diễn
tuyến tính bởi một số số nguyên. Gần với nó là **bài toán đồng xu Frobenius**
(Frobenius coin problem, bài toán đổi tiền Frobenius):

-   Nếu có các loại đồng xu với mệnh giá nguyên $a_1,a_2,\cdots,a_n$ và
    $\gcd(a_1,a_2,\cdots,a_n)=1$, thì số nguyên lớn nhất không thể tạo thành từ
    các đồng xu này là bao nhiêu?

Bài toán vẫn xét khi nào một số nguyên $k$ có thể biểu diễn dưới dạng
$a_1x_1+a_2x_2+\cdots+a_nx_n$. Trong định lý Bézout, $x_i$ có thể là số nguyên
bất kỳ, còn trong bài toán đồng xu Frobenius, $x_i$ chỉ được là số tự nhiên.

Trường hợp chỉ có một loại đồng xu khá dễ xử lý, vì khi đó chỉ có thể có $a_1=1$
và mọi số tự nhiên đều biểu diễn được. Trường hợp $n>2$ lại quá phức tạp, nên
mục này chỉ thảo luận trường hợp $n=2$.

<span id="định-lý-sylvester"></span>
### Định lý Sylvester

Năm 1882, Sylvester đã giải quyết trọn vẹn bài toán đồng xu Frobenius khi
$n = 2$:

???+ note "Định lý (Sylvester)"
    Với hai số nguyên dương nguyên tố cùng nhau $a_1,a_2$, số nguyên lớn nhất
    không thể viết dưới dạng $a_1x_1+a_2x_2~(x_1,x_2\in\mathbf N)$ là
    $C = a_1a_2 - a_1 - a_2$. Hơn nữa, với mọi $k\in\mathbf Z$, trong hai số
    nguyên $k$ và $C-k$, có đúng một số có thể viết dưới dạng đó.

Để tiện trình bày, gọi những số nguyên có thể viết dưới dạng
$a_1x_1+a_2x_2~(x_1,x_2\in\mathbf N)$ là **biểu diễn được**.

??? note "Chứng minh 1"
    Vì $a_1,a_2$ nguyên tố cùng nhau, với mọi số nguyên $k$, phương trình
    $a_1x_1+a_2x_2=k$ luôn có nghiệm, và nghiệm tổng quát là

    $$
    (x_1,x_2) = (x_1^\circ + ta_2, x_2^\circ - ta_1).\quad(t\in\mathbf Z)
    $$

    Chọn $t$ là thương khi chia $x_2^\circ$ cho $a_1$ có dư, khi đó phần dư
    $x_2 = x_2^\circ-ta_1$ nằm giữa $0$ và $a_1-1$. Xét nghiệm $(x_1,x_2)$ thu
    được lúc này. Vì $x_2$ là giá trị không âm nhỏ nhất mà nó có thể nhận, nên
    $k$ biểu diễn được khi và chỉ khi $x_1\ge 0$.

    **Bước 1**: Chứng minh mọi số nguyên lớn hơn $C$ đều biểu diễn được.

    Khi $k > C$, suy ra

    $$
    a_1x_1 = k - a_2x_2 > C - a_2(a_1-1) = -a_1.
    $$

    Do đó $x_1 > -1$, tức là $x_1\ge 0$. Suy ra $(x_1,x_2)$ là một nghiệm trong
    các số tự nhiên. Khi đó $k$ có thể viết dưới dạng cần tìm.

    **Bước 2**: Chứng minh $C$ không biểu diễn được. Từ đó $C$ là số nguyên
    không biểu diễn được lớn nhất, và $k$ với $C-k$ không thể đồng thời biểu diễn
    được.

    Chứng minh bằng phản chứng. Giả sử $C$ biểu diễn được, tức là tồn tại
    $x_1,x_2\in\mathbf N$ sao cho $a_1x_1+a_2x_2=C$. Thế biểu thức của $C$ vào,
    thu được

    $$
    a_1a_2 = a_1(x_1+1) + a_2(x_2+1).
    $$

    Do đó $a_2\mid (x_1+1)$ và $a_1\mid (x_2+1)$. Lại vì $x_1+1,x_2+1$ đều
    dương, suy ra

    $$
    a_1a_2 \ge a_1a_2 + a_2a_1 = 2a_1a_2.
    $$

    Mâu thuẫn. Vậy $C$ không biểu diễn được. Kết hợp với bước 1, nó chính là số
    nguyên không biểu diễn được lớn nhất.

    Nếu $k$ và $C-k$ đều biểu diễn được, thì cộng các hệ số trong biểu diễn của
    $k$ và $C-k$ sẽ cho biểu diễn của $C$, mâu thuẫn với việc $C$ không biểu diễn
    được. Vì vậy trong $k$ và $C-k$ có nhiều nhất một số biểu diễn được.

    **Bước 3**: Chứng minh nếu $k$ không biểu diễn được thì $C-k$ biểu diễn được.

    Đặt $(x_1,x_2)$ là nghiệm nguyên của phương trình $a_1x_1+a_2x_2=k$ như đã
    chọn. Phần trước đã cho thấy $k$ không biểu diễn được tương đương với
    $x_1<0$. Khi đó

    $$
    C - k = a_1a_2 - a_1 - a_2 - a_1x_1 - a_2x_2 = a_1(-1-x_1) + a_2(a_1-1-x_2).
    $$

    Trong đó $-1-x_1$ và $a_1-1-x_2$ đều là số nguyên không âm, nên $C-k$ biểu
    diễn được.

??? note "Chứng minh 2"
    Phần này chỉ chứng minh $C=a_1a_2-a_1-a_2$ là số tự nhiên không biểu diễn
    được lớn nhất; các phần còn lại được chứng minh tương tự Chứng minh 1.

    Xét trong từng lớp thặng dư theo môđun $a_2$, số tự nhiên biểu diễn được nhỏ
    nhất. Vì các số tự nhiên khác nhau trong cùng một lớp thặng dư có thể chuyển
    hóa qua lại bằng cách cộng trừ một số bội của $a_2$, nên khi xét số biểu
    diễn được nhỏ nhất, chỉ cần xét khả năng cộng trừ $a_1$. Do $a_1$ và $a_2$
    nguyên tố cùng nhau, số tự nhiên biểu diễn được nhỏ nhất trong mỗi lớp thặng
    dư chính là các bội sau của $a_1$:

    $$
    0,~a_1,~2a_1,~\cdots,~(a_2-1)a_1.
    $$

    Do đó số không biểu diễn được lớn nhất là

    $$
    \max_{0\le i < a_2} ia_1 - a_2 = (a_2-1)a_1 - a_2 = C.
    $$

<span id="ý-nghĩa-hình-học"></span>
### Ý nghĩa hình học

Xem phương trình $a_1x_1 + a_2x_2 = k$ là một đường thẳng. Khi đó $k$ biểu diễn
được khi và chỉ khi đường thẳng này đi qua một điểm nguyên trong góc phần tư thứ
nhất, tính cả các trục tọa độ. Khi $k < a_1a_2$, đường thẳng này đi qua nhiều
nhất một điểm nguyên trong góc phần tư thứ nhất. Vì vậy, với
$0\le k < a_1a_2$, số nguyên $k$ biểu diễn được khi và chỉ khi đường thẳng ứng
với $k$ đi qua đúng một điểm nguyên trong góc phần tư thứ nhất.

Do đó, số lượng số tự nhiên nhỏ hơn hoặc bằng $k < a_1a_2$ và biểu diễn được
bằng đúng số điểm nguyên trong góc phần tư thứ nhất nằm bên dưới đường thẳng
$a_1x_1 + a_2x_2 = k$ (tính cả các điểm trên biên). Số lượng này bằng

$$
\sum_{i=0}^{\lfloor k / a_1 \rfloor} \left\lfloor\dfrac{k-ia_1}{a_2}\right\rfloor.
$$

Đây là bài toán kinh điển đếm điểm nguyên dưới đường thẳng, có thể giải bằng
[thuật toán Euclid tương tự](./euclidean.md#thuật-toán-euclid-tương-tự) trong
thời gian $O(\log\min\{a_1,a_2,k\})$.

<span id="bài-tập"></span>
### Bài tập

-   [Luogu P3951 NOIP2017 nâng cao, Nghi vấn của Xiao Kai / Lanqiao Cup 2013 cấp tỉnh, Số lượng không mua được](https://www.luogu.com.cn/problem/P3951)
