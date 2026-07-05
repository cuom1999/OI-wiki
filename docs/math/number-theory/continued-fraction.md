author: 383494, CCXXXI, chunibyo-wly, Enter-tainer, Great-designer, megakite, Menci, shawlleyw, shuzhouliu, StudyingFather, Tiphereth-A, untitledunrevised, c-forrest

<span id="mở-đầu"></span>

## Mở đầu

Liên phân số có thể biểu diễn một số thực dưới dạng giới hạn của một dãy số hữu tỉ hội tụ. Các số hữu tỉ trong dãy này dễ tính, đồng thời cho xấp xỉ tốt nhất của số thực đó, nên liên phân số thường xuất hiện trong lập trình thi đấu. Ngoài ra, liên phân số có quan hệ chặt chẽ với thuật toán Euclid, vì vậy có thể áp dụng cho nhiều bài toán số học.

???+ info "Về các cài đặt thuật toán liên quan đến liên phân số"
    Bài viết này cung cấp một loạt cài đặt thuật toán về liên phân số. Một số thuật toán không bảo đảm mọi số nguyên trung gian đều nằm trong phạm vi của kiểu số nguyên 32 bit hoặc 64 bit. Trong các trường hợp đó, hãy tham khảo bản cài đặt Python tương ứng, hoặc thay kiểu số nguyên trong bản C++ bằng [lớp số nguyên chính xác cao](../bignum.md). Để tập trung vào ý chính, một số đoạn mã trong bài có thể gọi những hàm đã cài đặt ở phần trước mà không lặp lại phần cài đặt.

<span id="liên-phân-số"></span>

## Liên phân số

**Liên phân số** (continued fraction) về bản chất chỉ là một ký hiệu hình thức.

???+ abstract "Liên phân số hữu hạn"
    Với dãy $\{a_k\}_{i=0}^n$, liên phân số $[a_0,a_1,\cdots,a_n]$ biểu thị khai triển
    
    $$
    x = a_0+\dfrac{1}{a_1+\dfrac{1}{a_2+\dfrac{1}{\cdots+\dfrac{1}{a_n}}}}.
    $$
    
    Liên phân số có nghĩa khi và chỉ khi khai triển tương ứng có nghĩa. Các $a_k$ này được gọi là **hạng** (term) hoặc **hệ số** (coefficient) của liên phân số.

???+ info "Ký hiệu"
    Liên phân số tổng quát hơn cho phép các tử số trong khai triển không luôn bằng $1$; khi đó ký hiệu liên phân số cũng cần thay đổi, và nằm ngoài phạm vi bài viết này. Ngoài ra, một số tài liệu viết dấu phẩy đầu tiên "$,$" thành dấu chấm phẩy "$;$"; cách viết đó không khác về ý nghĩa so với ký hiệu dùng trong bài này.

Dĩ nhiên, liên phân số cũng có thể được mở rộng cho trường hợp dãy vô hạn.

???+ abstract "Liên phân số vô hạn"
    Với dãy vô hạn $\{a_k\}_{i=0}^\infty$, liên phân số $[a_0,a_1,\cdots]$ biểu thị giới hạn
    
    $$
    x = \lim_{k\rightarrow\infty} x_k = \lim_{k\rightarrow\infty} [a_0,a_1,\cdots,a_k].
    $$
    
    Liên phân số có nghĩa khi và chỉ khi giới hạn tương ứng có nghĩa. Trong đó, $x_k=[a_0,a_1,\cdots,a_k]$ được gọi là **phân số tiệm cận** thứ $k$ (convergent) của $x$, còn $r_k=[a_k,a_{k+1},\cdots]$ được gọi là **phần dư** thứ $k$ hoặc **thương đầy đủ** (complete quotient) của $x$. Tương ứng, hạng $a_k$ đôi khi cũng được gọi là **thương riêng** thứ $k$ (partial quotient).

<span id="liên-phân-số-đơn-giản"></span>

### Liên phân số đơn giản

Trong số học, ta chủ yếu xét trường hợp các hạng của liên phân số đều là số nguyên.

???+ abstract "Liên phân số đơn giản"
    Với liên phân số $[a_0,a_1,\cdots]$, nếu $a_0$ là số nguyên và $a_1,a_2,\cdots$ đều là số nguyên dương, thì nó được gọi là **liên phân số đơn giản** (simple continued fraction), hay gọi tắt là **liên phân số**. Nếu dãy $\{a_i\}$ hữu hạn, ta gọi đó là **liên phân số (đơn giản) hữu hạn**; ngược lại gọi là **liên phân số (đơn giản) vô hạn**. Ngoài ra, $a_0$ được gọi là **phần nguyên** (integer part) của nó.

Trừ khi nói rõ khác đi, "liên phân số" trong bài này đều chỉ liên phân số đơn giản. Có thể chứng minh rằng liên phân số đơn giản vô hạn luôn hội tụ, và phần dư của liên phân số đơn giản luôn dương.

Liên phân số có các tính chất cơ bản sau:

???+ note "Tính chất"
    Giả sử số thực $x=[a_0,a_1,a_2,\cdots]$. Khi đó các tính chất sau đúng:
    
    1.  Với mọi $k\in\mathbf Z$, ta có $x+k=[a_0+k,a_1,a_2,\cdots]$;
    2.  Với số thực $x>1$, ta có $a_0>0$, và nghịch đảo của nó là $x^{-1}=[0,a_0,a_1,a_2,\cdots]$.

Liên phân số hữu hạn tương ứng với số hữu tỉ. Mỗi số hữu tỉ có đúng hai cách biểu diễn thành liên phân số, và độ dài của hai cách này tất yếu một chẵn một lẻ. Khác biệt duy nhất giữa hai biểu diễn nằm ở việc hạng cuối có bằng $1$ hay không, tức là

$$
x = [a_0,a_1,\cdots,a_n] = [a_0,a_1,\cdots,a_n-1,1].
$$

Hai liên phân số này được gọi là **biểu diễn liên phân số** (continued fraction representation) của số hữu tỉ $x$. Trong đó, biểu diễn có hạng cuối khác $1$ được gọi là biểu diễn chuẩn, còn biểu diễn có hạng cuối bằng $1$ được gọi là biểu diễn không chuẩn.[^one-representation]

??? example "Ví dụ"
    Biểu diễn liên phân số của số hữu tỉ $x=\dfrac{5}{3}$ là
    
    $$
    \begin{aligned}
    x = [1,1,1,1] &= 1+\dfrac{1}{1+\dfrac{1}{1+\dfrac{1}{1}}},\\
    x = [1,1,2] &= 1+\dfrac{1}{1+\dfrac{1}{2}}.
    \end{aligned}
    $$

Liên phân số vô hạn tương ứng với số vô tỉ. Hơn nữa, mỗi số vô tỉ chỉ có một cách duy nhất để biểu diễn thành liên phân số, gọi là biểu diễn liên phân số của số vô tỉ đó.

<span id="cách-tìm-biểu-diễn-liên-phân-số"></span>

### Cách tìm biểu diễn liên phân số

Để tìm biểu diễn liên phân số của một số thực $x$, chỉ cần chú ý rằng nếu phần dư $r_k$ của nó không phải là số nguyên, thì luôn có

$$
r_k = [a_k,a_{k+1},\cdots] = [a_k,r_{k+1}] = a_k + \dfrac{1}{r_{k+1}}.
$$

Hơn nữa, $r_{k+1}>1$. Vì vậy, ta có thể bắt đầu từ $r_0=x$ và tính đệ quy

$$
a_k = \lfloor r_k\rfloor,\ r_{k+1} = \dfrac{1}{r_k-a_k}.
$$

Quá trình này luôn xác định duy nhất dãy $\{a_k\}$, trừ khi một phần dư $r_k$ trở thành số nguyên. Nếu xuất hiện $r_k$ nguyên, quá trình nên dừng lại; ta có thể chọn xuất ra biểu diễn chuẩn hoặc biểu diễn không chuẩn tương ứng.

Trong lập trình thi đấu, trường hợp thường gặp là số hữu tỉ $x=\dfrac{p}{q}$. Khi đó, mỗi phần dư $r_k$ đều là số hữu tỉ $\dfrac{p_k}{q_k}$; với $k>0$, vì $r_k>1$ nên luôn có $p_k>q_k$. Tính cụ thể công thức truy hồi trên, ta được

$$
a_k = \left\lfloor\frac{p_k}{q_k}\right\rfloor,\ r_{k+1} = \dfrac{1}{r_k-a_k} = \dfrac{q_k}{p_k-a_kq_k} = \dfrac{q_k}{p_k\bmod q_k}.
$$

Quá trình tính toán lúc này thực chất là áp dụng [thuật toán Euclid](./gcd.md#thuật-toán-euclid) cho $p$ và $q$. Điều này cũng cho thấy, với số hữu tỉ $r=\dfrac{p}{q}$, độ dài biểu diễn liên phân số là $O(\log\min\{p, q\})$. Độ phức tạp để tính biểu diễn của $\dfrac{p}{q}$ cũng là $O(\log\min\{p, q\})$.

???+ example "Cài đặt tham khảo"
    Cho tử số $p$ và mẫu số $q$ của một phân số, xuất ra dãy hệ số $[a_0,a_1,\cdots,a_n]$ của liên phân số.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/diophantine.cpp:fraction"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/diophantine.py:fraction"
        ```

<span id="phân-số-tiệm-cận"></span>

## Phân số tiệm cận

Khái niệm phân số tiệm cận đã được giới thiệu trong định nghĩa liên phân số. Phân số tiệm cận của một số thực chính là phân số tiệm cận của biểu diễn liên phân số của nó: trong biểu diễn liên phân số của số thực $x$, giữ lại $k$ hạng đầu để nhận được liên phân số $x_k$; đó được gọi là phân số tiệm cận thứ $k$ của $x$. Các phân số tiệm cận $x_k$ của số thực $x$ đều là số hữu tỉ, và dãy $\{x_k\}$ hội tụ về số thực $x$.

??? example "Ví dụ: phân số tiệm cận của tỉ lệ vàng"
    Một vài phân số tiệm cận đầu tiên của liên phân số $x=[1,1,1,1,\cdots]$ là
    
    $$
    \begin{aligned}
    x_0 &= [1]=1,\\
    x_1 &= [1,1]=2,\\
    x_2 &= [1,1,1]=\dfrac{3}{2},\\
    x_3 &= [1,1,1,1]=\dfrac{5}{3},\\
    x_4 &= [1,1,1,1,1]=\dfrac{8}{5}.
    \end{aligned}
    $$
    
    Có thể chứng minh bằng quy nạp rằng
    
    $$
    x_k = \frac{F_{k+2}}{F_{k+1}},
    $$
    
    Trong đó, $\{F_k\}$ là [dãy Fibonacci](../combinatorics/fibonacci.md). Theo công thức tổng quát của dãy này,
    
    $$
    x_k = \frac{\phi^{k+2}-(-\phi)^{-(k+2)}}{\phi^{k+1}-(-\phi)^{-(k+1)}},
    $$
    
    trong đó $\phi=\dfrac{1+\sqrt{5}}{2}$ là tỉ lệ vàng. Khi $k$ tiến tới vô hạn, ta có
    
    $$
    x=\lim_{k\rightarrow\infty}x_k=\phi.
    $$
    
    Vì vậy, liên phân số $x=[1,1,1,1,\cdots]$ biểu diễn tỉ lệ vàng $\phi$.

Các phân số tiệm cận này tiến tới số thực tương ứng, nên có thể dùng để xấp xỉ số thực đó. Do đó, ta cần hiểu các tính chất của phân số tiệm cận.

<span id="quan-hệ-truy-hồi"></span>

### Quan hệ truy hồi

Trước hết, cần giải quyết bài toán tính các phân số tiệm cận. Dù mỗi phân số tiệm cận chỉ thêm một hạng vào cuối liên phân số, ta không cần tính lại giá trị từ đầu mỗi lần. Thật ra, các phân số tiệm cận có quan hệ truy hồi sau:

???+ note "Công thức truy hồi"
    Với liên phân số $x=[a_0,a_1,a_2,\cdots]$, giả sử phân số tiệm cận thứ $k$ của nó là $x_k=\dfrac{p_k}{q_k}$. Khi đó,
    
    $$
    \begin{aligned}
    p_k &= a_kp_{k-1}+p_{k-2},\\
    q_k &= a_kq_{k-1}+q_{k-2}.
    \end{aligned}
    $$
    
    Điểm bắt đầu của truy hồi là các phân số hình thức
    
    $$
    x_{-1}=\frac{p_{-1}}{q_{-1}}=\frac{1}{0},\ x_{-2}=\frac{p_{-2}}{q_{-2}}=\frac{0}{1}.
    $$

??? note "Chứng minh"
    Tử số và mẫu số của phân số tiệm cận $x_k$ có thể xem là các đa thức nhiều biến theo $a_0, a_1, \cdots, a_k$:
    
    $$
    r_k = \frac{P_k(a_0, a_1, \cdots, a_k)}{Q_k(a_0,a_1, \cdots, a_k)}.
    $$
    
    Theo định nghĩa phân số tiệm cận, ta có
    
    $$
    r_k = a_0 + \frac{1}{[a_1,a_2,\cdots, a_k]}= a_0 + \frac{Q_{k-1}(a_1, \cdots, a_k)}{P_{k-1}(a_1, \cdots, a_k)} = \frac{a_0 P_{k-1}(a_1, \dots, a_k) + Q_{k-1}(a_1, \cdots, a_k)}{P_{k-1}(a_1, \cdots, a_k)}.
    $$
    
    So sánh với biểu thức trên, có thể đặt $Q_k(a_0, \cdots, a_k) = P_{k-1}(a_1, \cdots, a_k)$; khi đó phân số tiệm cận có thể viết thành
    
    $$
    r_k =  \frac{P_k(a_0, a_1, \cdots, a_k)}{P_{k-1}(a_1, \cdots, a_k)}
    $$
    
    và đa thức $P_k$ có quan hệ truy hồi
    
    $$
    P_k(a_0, \cdots, a_k) = a_0 P_{k-1}(a_1, \cdots, a_k) + P_{k-2}(a_2, \cdots, a_k).
    $$
    
    Vì
    
    $$
    r_0 = a_0,\ r_1 = a_0+\dfrac{1}{a_1} = \frac{a_0a_1+1}{a_1},
    $$
    
    nên điểm bắt đầu của truy hồi là
    
    $$
    P_0(a_0) = a_0,\ P_1(a_0,a_1) = a_0a_1 + 1.
    $$
    
    Nếu đặt
    
    $$
    P_{-1} = 1,\ P_{-2} = 0,
    $$
    
    ta có thể kiểm tra rằng quan hệ truy hồi trên cũng đúng với $k=0,1$. Điều này tương đương với việc quy ước các phân số hình thức $r_{-1}=\dfrac{1}{0}$ và $r_{-2}=\dfrac{0}{1}$.
    
    Dãy đa thức $P_k$ thỏa mãn quan hệ truy hồi trên được gọi là **continuant**[^continuant]. Nó có thể được viết dưới dạng định thức:
    
    $$
    P_k(a_0,\cdots,a_k)=\det
    \begin{pmatrix}
    a_0 & 1 & 0 & \cdots & 0 \\
    -1 & a_1 & 1 & \ddots & \vdots \\
    0 & -1 & a_2 & \ddots & 0 \\
    \vdots & \ddots & \ddots & \ddots & 1 \\
    0 & \cdots & 0 & -1 & a_k
    \end{pmatrix}.
    $$
    
    Đây là định thức của một [ma trận tam đường chéo](https://en.wikipedia.org/wiki/Tridiagonal_matrix). Khai triển từ góc trên trái, ta có thể kiểm tra rằng nó có quan hệ truy hồi và điều kiện đầu như trên. Ngược lại, khai triển từ góc dưới phải lại thu được quan hệ truy hồi
    
    $$
    P_k(a_0, \cdots, a_k) = a_k P_{k-1}(a_0, \cdots, a_{k-1}) + P_{k-2}(a_0, \cdots, a_{k-2}),
    $$
    
    Điều này chứng minh điều cần chứng minh.

???+ info "Ký hiệu"
    Khi bài viết ký hiệu phân số tiệm cận $x_k$ là $\dfrac{p_k}{q_k}$, ta luôn mặc định tử số $p_k$ và mẫu số $q_k$ được cho bởi quan hệ truy hồi trên. Phần sau sẽ chỉ ra rằng cách này luôn cho biểu diễn tối giản của phân số tiệm cận.

Công thức truy hồi này cho thấy

$$
x_k=\dfrac{a_kp_{k-1}+p_{k-2}}{a_kq_{k-1}+q_{k-2}}
$$

nằm giữa $x_{k-1}$ và $x_{k-2}$.

Từ quan hệ truy hồi của phân số tiệm cận, ta có các hệ quả sau: định lý đảo thứ tự và định lý nghịch đảo.

???+ note "Định lý đảo thứ tự"
    Giả sử phân số tiệm cận thứ $k$ của số thực $x=[a_0,a_1,a_2,\cdots]$ là $\dfrac{p_k}{q_k}$. Khi đó, tỉ số giữa tử số và mẫu số của hai phân số tiệm cận kề nhau lần lượt là
    
    $$
    \begin{aligned}
    \frac{p_k}{p_{k-1}}&=[a_k,a_{k-1},\cdots,a_1,a_0],\\
    \frac{q_k}{q_{k-1}}&=[a_k,a_{k-1},\cdots,a_1].
    \end{aligned}
    $$
    
    Nếu $a_0=0$, liên phân số đầu tiên nên được hiểu là bị cắt tại hạng áp chót, tức $[a_k,a_{k-1},\cdots,a_2]$.

??? note "Chứng minh"
    Trong quan hệ truy hồi của $p_k$ và $q_k$, chia hai vế lần lượt cho $p_{k-1}$ và $q_{k-1}$, ta được
    
    $$
    \begin{aligned}
    \frac{p_k}{p_{k-1}} &= a_k + \frac{p_{k-2}}{p_{k-1}},\\
    \frac{q_k}{q_{k-1}} &= a_k + \frac{q_{k-2}}{q_{k-1}}.
    \end{aligned}
    $$
    
    Lặp hai công thức này sẽ thu được hai liên phân số. Sau đó chỉ cần thay các giá trị đầu $\dfrac{p_0}{p_{-1}}=a_0$ và $\dfrac{q_1}{q_0}=a_1$. Với trường hợp $a_0=0$, hiểu liên phân số thu được như một biểu thức hình thức; khi đó phần dư của nó là
    
    $$
    [a_2,a_1,0]=a_2+\dfrac{1}{a_1+\dfrac{1}{0}}=a_2+\dfrac{0}{0a_1+1}=a_2.
    $$
    
    Vì thế có thể bỏ trực tiếp hai hạng cuối. Nếu cần chứng minh chặt chẽ, chỉ cần chú ý rằng công thức này có thể xem là giới hạn khi $a_0\rightarrow 0$.

???+ note "Định lý nghịch đảo"
    Nghịch đảo của các phân số tiệm cận của số thực $x>0$ là các phân số tiệm cận của $x^{-1}$.

??? note "Chứng minh"
    Không mất tính tổng quát, giả sử $x>1$ và có biểu diễn liên phân số $[a_0,a_1,a_2,\cdots]$. Khi đó biểu diễn liên phân số của $x^{-1}$ là $[0,a_0,a_1,a_2,\cdots]$. Các phân số tiệm cận của chúng có thể được tính từ quan hệ truy hồi. Hơn nữa, với $x$ có điều kiện đầu $x_{-2}=\dfrac{0}{1}$ và $x_{-1}=\dfrac{1}{0}$; với $y=x^{-1}$ có điều kiện đầu $y_{-1}=\dfrac{1}{0}$ và $y_{0}=\dfrac{0}{1}$. Do đó $x_{-2}=(y_{-1})^{-1}$ và $x_{-1}=(y_0)^{-1}$. Theo quan hệ truy hồi, ta có $x_k=y_{k+1}^{-1}$. Điều này cho thấy nghịch đảo của các phân số tiệm cận của $x$ là các phân số tiệm cận của $y=x^{-1}$. Trường hợp $0<x\le 1$ cũng có thể được thảo luận tương tự.

Dùng quan hệ truy hồi trong phần này, ta có thuật toán tính phân số tiệm cận như sau:

???+ example "Cài đặt tham khảo"
    Cho các hệ số $a_0,a_1,\cdots,a_n$ của một liên phân số, tìm dãy tử số và mẫu số của các phân số tiệm cận $(p_0,q_0),(p_1,q_1),\cdots,(p_n,q_n)$.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/diophantine.cpp:convergents"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/diophantine.py:convergents"
        ```

<span id="ước-lượng-sai-số"></span>

### Ước lượng sai số

Dùng công thức truy hồi của phân số tiệm cận, ta có thể ước lượng sai số khi dùng phân số tiệm cận để xấp xỉ số thực.

Trước hết, có thể tính hiệu của hai phân số tiệm cận kề nhau:

???+ note "Hiệu của phân số tiệm cận"
    Giả sử $x_k=\dfrac{p_k}{q_k}$ là phân số tiệm cận thứ $k$ của số thực $x$. Khi đó,
    
    $$
    p_{k+1}q_k − p_kq_{k+1} = (−1)^k.
    $$
    
    Vì vậy, hiệu giữa hai phân số tiệm cận kề nhau là
    
    $$
    x_{k+1} - x_k = \dfrac{(-1)^k}{q_{k+1}q_k}.
    $$

??? note "Chứng minh"
    Theo quan hệ truy hồi, ta có
    
    $$
    \begin{aligned}
    \det\begin{pmatrix}
    p_{k+1} & p_k \\
    q_{k+1} & q_k 
    \end{pmatrix}
    &=
    \det\begin{pmatrix}
    a_{k+1}p_{k}+p_{k-1} & p_k \\
    a_{k+1}q_{k}+q_{k-1} & q_k 
    \end{pmatrix}
    =
    \det\begin{pmatrix}
    p_{k-1} & p_k\\
    q_{k-1} & q_k
    \end{pmatrix}
    \\
    &=
    -
    \det\begin{pmatrix}
    p_k & p_{k-1}\\
    q_k & q_{k-1}
    \end{pmatrix}
    =
    (-1)^{k+2}
    \det\begin{pmatrix}
    1 & 0\\
    0 & 1
    \end{pmatrix}
    =(-1)^k.
    \end{aligned}
    $$
    
    Đây chính là $p_{k+1}q_k − p_kq_{k+1} = (−1)^k$. Chia hai vế cho $q_{k+1}q_k$ sẽ thu được kết luận về $x_{k+1}-x_k$.

Do đó, phân số tiệm cận có chỉ số lẻ luôn lớn hơn hai phân số kề nó, còn phân số tiệm cận có chỉ số chẵn luôn nhỏ hơn hai phân số kề nó: các phân số tiệm cận dao động luân phiên.

Nếu chỉ xét các phân số tiệm cận chỉ số chẵn (chỉ số lẻ), dãy cũng đơn điệu tăng (giảm). Điều này là vì

$$
x_{k+2}-x_k = \dfrac{(-1)^{k+1}}{q_{k+2}q_{k+1}}+\dfrac{(-1)^{k}}{q_{k+1}q_{k}} = \dfrac{(-1)^k(q_{k+2}-q_k)}{q_{k+2}q_{k+1}q_k} = \dfrac{(-1)^ka_{k+2}}{q_{k+2}q_k}
$$

khi $k$ chẵn (lẻ) thì giá trị này dương (âm). Đồng thời, do có quan hệ truy hồi $q_{k}=a_kq_{k-1}+q_{k-2}$, tốc độ tăng của mẫu số $q_k$ không chậm hơn tốc độ tăng của dãy Fibonacci. Vì thế, hiệu giữa hai hạng kề nhau chắc chắn tiến về không. Điều này cho thấy các phân số tiệm cận chỉ số chẵn và chỉ số lẻ lần lượt xấp xỉ cùng một giới hạn từ dưới lên và từ trên xuống. Như vậy liên phân số đơn giản vô hạn chắc chắn hội tụ. Hình dưới minh họa quá trình các phân số tiệm cận tiến tới số thực tương ứng:

![](./images/golden-ratio-convergents.svg)

???+ abstract "Phân số tiệm cận trên (dưới)"
    Với số thực $x$ và phân số tiệm cận $x_k$ của nó, nếu $x_k>x$ ($x_k<x$), thì $x_k$ được gọi là **phân số tiệm cận trên (dưới)** (upper (lower) convergent) của $x$.

Ở trên đã chỉ ra rằng phân số tiệm cận trên chính là phân số tiệm cận có chỉ số lẻ, còn phân số tiệm cận dưới chính là phân số tiệm cận có chỉ số chẵn.

Dùng công thức hiệu, có thể viết số thực $x$ dưới dạng chuỗi đan dấu:

$$
x = a_0+\sum_{k=0}^{\infty}\dfrac{(-1)^k}{q_{k+1}q_k}.
$$

Phân số tiệm cận và phần dư trong định nghĩa liên phân số chính là tổng riêng và phần dư của chuỗi này.

Dùng công thức hiệu, ta cũng có thể trực tiếp ước lượng sai số khi dùng phân số tiệm cận xấp xỉ số thực:

???+ note "Sai số"
    Giả sử $x_k=\dfrac{p_k}{q_k}\neq x$ là phân số tiệm cận thứ $k$ của số thực $x$. Khi đó,
    
    $$
    x_k - x = \dfrac{(-1)^k}{q_k\left(r_{k+1}q_k+q_{k-1}\right)},
    $$
    
    trong đó $r_{k+1}$ là phần dư thứ $k+1$ của số thực $x$. Hơn nữa,
    
    $$
    \dfrac{1}{2q_{k+1}^2} \le \dfrac{1}{q_k(q_k+q_{k+1})} \le \left|x-\frac{p_k}{q_k}\right| \le \dfrac{1}{q_kq_{k+1}} \le \dfrac{1}{q_k^2}.
    $$

??? note "Chứng minh"
    Vì $x=[a_0,a_1,\cdots,a_k,r_{k+1}]$, và công thức hiệu của phân số tiệm cận cũng đúng với liên phân số hình thức, nên
    
    $$
    x-x_k = \dfrac{(-1)^k}{q_k\left(r_{k+1}q_k+q_{k-1}\right)},
    $$
    
    trong đó $r_{k+1}q_k+q_{k-1}$ chính là mẫu số của phân số tiệm cận thứ $k+1$ của liên phân số hình thức này, tính theo công thức truy hồi.
    
    Để hoàn tất ước lượng bất đẳng thức sau đó, chỉ cần chú ý rằng khi $x_k\neq x$, ta luôn có
    
    $$
    1\le a_{k+1}\le r_{k+1} \le a_{k+1}+1,
    $$
    
    nên
    
    $$
    q_{k+1}=a_{k+1}q_k+q_{k-1}\le r_{k+1}q_k+q_{k-1} \le q_k+(a_{k+1}q_k+q_{k-1}) = q_k+q_{k+1}.
    $$
    
    Do đó có bất đẳng thức
    
    $$
    \dfrac{1}{q_k(q_k+q_{k+1})} \le \left|x-\frac{p_k}{q_k}\right| = \dfrac{1}{q_k\left(r_{k+1}q_k+q_{k-1}\right)} \le \dfrac{1}{q_kq_{k+1}}.
    $$
    
    Để có hai đánh giá ngoài cùng, chỉ cần chú ý thêm rằng $q_k\le q_{k+1}$.

Công thức hiệu trong phần này còn có một hệ quả đơn giản: các phân số tiệm cận $\dfrac{p_k}{q_k}$ đều là phân số tối giản.

???+ note "Hệ quả"
    Với mọi số thực $x$, nếu tử số và mẫu số của phân số tiệm cận $x_k=\dfrac{p_k}{q_k}$ được cho bởi công thức truy hồi, thì $\dfrac{p_k}{q_k}$ là phân số tối giản, tức $\gcd(p_k,q_k)=1$.

??? note "Chứng minh"
    Chỉ cần áp dụng [định lý Bezout](./bezouts.md) cho công thức hiệu.

Thực ra, nghiệm của phương trình Diophantine tuyến tính hai ẩn cũng có thể được tìm bằng phương pháp liên phân số.

???+ example "Giải phương trình Diophantine tuyến tính hai ẩn"
    Cho $A, B, C \in \mathbf Z$. Tìm $x, y \in \mathbf Z$ sao cho $Ax + By = C$.

??? note "Lời giải"
    Dù bài toán này thường được giải bằng [thuật toán Euclid mở rộng](./bezouts.md#trường-hợp-hai-biến), nó cũng có thể được giải bằng liên phân số.
    
    Giả sử $\dfrac{A}{B}=[a_0, a_1, \cdots, a_k]$. Ở trên đã chứng minh $p_k q_{k-1} - p_{k-1} q_k = (-1)^{k-1}$. Thay $p_k$ và $q_k$ bằng $A$ và $B$, ta được
    
    $$
    Aq_{k-1} - Bp_{k-1} = (-1)^{k-1} g,
    $$
    
    trong đó $g = \gcd(A, B)$. Nếu $g$ chia hết $C$, một nghiệm là $x = (-1)^{k-1}\dfrac{C}{g} q_{k-1}$ và $y = (-1)^{k}\dfrac{C}{g} p_{k-1}$; ngược lại vô nghiệm.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/diophantine.cpp:dio"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/diophantine.py:dio"
        ```

<span id="xấp-xỉ-diophantine"></span>

## Xấp xỉ Diophantine

Một ứng dụng quan trọng của lý thuyết liên phân số là lý thuyết xấp xỉ Diophantine. Xấp xỉ Diophantine (tiếng Anh: Diophantine approximation) là việc dùng số hữu tỉ để xấp xỉ số thực. Dĩ nhiên, do tính trù mật của số hữu tỉ, nếu không đặt ràng buộc thì có thể đạt sai số nhỏ tùy ý. Vì vậy, cần ràng buộc các số hữu tỉ được phép dùng, chẳng hạn chỉ chọn các số hữu tỉ có mẫu nhỏ hơn một giá trị nào đó. Phần này thảo luận mối quan hệ giữa xấp xỉ tốt nhất dưới ràng buộc như vậy và liên phân số.

<span id="dùng-phân-số-tiệm-cận-để-xấp-xỉ-số-thực"></span>

### Dùng phân số tiệm cận để xấp xỉ số thực

Trước hết, từ ước lượng sai số của phân số tiệm cận, ta lập tức có kết quả sau:

???+ note "Định lý (Dirichlet)"
    Với số vô tỉ $x$, tồn tại vô hạn phân số tối giản $\dfrac{p}{q}$ sao cho
    
    $$
    \left|x-\dfrac{p}{q}\right| < \dfrac{1}{q^2} 
    $$
    
    đúng.

??? note "Chứng minh"
    Theo ước lượng sai số của phân số tiệm cận, với phân số tiệm cận thứ $k$ là $x_k=\dfrac{p_k}{q_k}$ của số vô tỉ $x$, ta có
    
    $$
    \left|x-\dfrac{p_k}{q_k}\right|\le\frac{1}{q_k^2}.
    $$
    
    Xem lại chứng minh của công thức sai số, ta thấy với mọi số vô tỉ $x$, điều kiện để xảy ra dấu bằng không thể xảy ra. Vì vậy, tử số và mẫu số của mọi phân số tiệm cận của nó đều thỏa mãn yêu cầu.

Định lý này cũng có thể xem là hệ quả của [định lý xấp xỉ Dirichlet](https://en.wikipedia.org/wiki/Dirichlet%27s_approximation_theorem). Đây gần như đã là kết quả tốt nhất: số mũ $2$ ở mẫu của vế phải bất đẳng thức không thể cải thiện thêm, nhưng hằng số thì có thể tốt hơn. Định lý Hurwitz cho biết vế phải có thể giảm xuống $\dfrac{1}{\sqrt{5}q^2}$, và đây là cận tốt nhất.

???+ note "Định lý Hurwitz"
    Với số vô tỉ $x$, tồn tại vô hạn phân số tối giản $\dfrac{p}{q}$ sao cho
    
    $$
    \left|x-\dfrac{p}{q}\right| < \dfrac{1}{\sqrt{5}q^2} 
    $$
    
    đúng, và $\sqrt{5}$ ở vế phải của bất đẳng thức không thể thay bằng số thực lớn hơn.

??? note "Chứng minh (Borel)"
    Borel thật ra đã chứng minh rằng trong ba phân số tiệm cận liên tiếp của số vô tỉ $x$, chắc chắn có ít nhất một phân số thỏa mãn điều kiện trên. Vì có vô hạn phân số tiệm cận và chúng đều tối giản, phần đầu của định lý Hurwitz hiển nhiên đúng.
    
    Chứng minh phản chứng. Giả sử tồn tại số vô tỉ $x$ cùng ba phân số tiệm cận $x_{k-1},x_k,x_{k+1}$ của nó sao cho
    
    $$
    \left|x-\dfrac{p_{k-1}}{q_{k-1}}\right|\ge\dfrac{1}{\sqrt{5}q_{k-1}^2},\ 
    \left|x-\dfrac{p_{k}}{q_{k}}\right|\ge\dfrac{1}{\sqrt{5}q_{k}^2},\ 
    \left|x-\dfrac{p_{k+1}}{q_{k+1}}\right|\ge\dfrac{1}{\sqrt{5}q_{k+1}^2}
    $$
    
    đúng. Vì hai phân số tiệm cận kề nhau luôn nằm ở hai phía của $x$, theo công thức hiệu ta có
    
    $$
    \dfrac{1}{q_{k-1}q_{k}}=\left|\dfrac{p_{k-1}}{q_{k-1}}-\dfrac{p_{k}}{q_{k}}\right|=\left|x-\dfrac{p_{k-1}}{q_{k-1}}\right|+\left|x-\dfrac{p_{k}}{q_{k}}\right|\ge\dfrac{1}{\sqrt{5}q_{k-1}^2}+\dfrac{1}{\sqrt{5}q_{k}^2}.
    $$
    
    Có thể viết lại thành bất đẳng thức theo thương $\dfrac{q_{k}}{q_{k-1}}$:
    
    $$
    \dfrac{q_k}{q_{k-1}}+\dfrac{q_{k-1}}{q_k}\le\sqrt 5.
    $$
    
    Vì vế trái là số hữu tỉ còn vế phải là số vô tỉ, dấu bằng chắc chắn không xảy ra. Lại do $q_k\ge q_{k-1}$, ta giải được
    
    $$
    1\le \dfrac{q_{k}}{q_{k-1}} < \dfrac{\sqrt{5}+1}{2}.
    $$
    
    Tương tự, có thể chứng minh
    
    $$
    1\le \dfrac{q_{k+1}}{q_{k}} < \dfrac{\sqrt{5}+1}{2}.
    $$
    
    Nhưng theo công thức truy hồi và kết hợp hai bất đẳng thức trên,
    
    $$
    a_{k+1} = \frac{q_{k+1}}{q_k}-\frac{q_{k-1}}{q_k} < \dfrac{\sqrt{5}+1}{2}-\dfrac{\sqrt{5}-1}{2} = 1
    $$
    
    Điều này mâu thuẫn với định nghĩa liên phân số đơn giản. Vì vậy kết luận của Borel đúng.
    
    Để chứng minh cận thu được là tốt nhất, chỉ cần tìm $x$ sao cho với mọi $C>\sqrt{5}$, chỉ tồn tại hữu hạn phân số tối giản $\dfrac{p}{q}$ thỏa mãn bất đẳng thức
    
    $$
    \left|x-\dfrac{p}{q}\right| < \dfrac{1}{Cq^2} 
    $$
    
    đúng. Dưới đây chứng minh $\phi=\dfrac{\sqrt{5}+1}{2}$ chính là một $x$ như vậy.[^sqrt5]
    
    Gọi $\phi'=\dfrac{-\sqrt{5}+1}{2}$ là nghiệm liên hợp của $\phi$. Cả hai đều là nghiệm của phương trình $x^2-x-1=0$. Do đó, với mọi số thực $x$,
    
    $$
    x^2-x-1 = (x-\phi)(x-\phi').
    $$
    
    Thay phân số tối giản $\dfrac{p}{q}$ vào, ta được
    
    $$
    \dfrac{1}{q^2}\le\frac{|p^2-pq-q^2|}{q^2}=\left|\dfrac{p}{q}-\phi\right|\left|\dfrac{p}{q}-\phi'\right|\le\left|\dfrac{p}{q}-\phi\right|\left(\left|\dfrac{p}{q}-\phi\right|+|\phi-\phi'|\right)<\dfrac{1}{Cq^2}\left(\dfrac{1}{Cq^2}+\sqrt{5}\right).
    $$
    
    Với $C>\sqrt{5}$, có thể giải trực tiếp được $q<\sqrt{C(C-\sqrt{5})}$, vì vậy không thể có vô hạn nghiệm thỏa mãn bất đẳng thức trên.

Các chứng minh trên cho thấy phân số tiệm cận cung cấp xấp xỉ Diophantine khá tốt. Tuy nhiên, chúng chưa chắc là xấp xỉ tốt nhất. Để thảo luận xấp xỉ tốt nhất, cần nêu rõ thước đo mức độ xấp xỉ. Thường có hai lựa chọn.

???+ warning "Có những trường hợp kết luận về xấp xỉ tốt nhất không còn đúng"
    Hai phần tiếp theo trình bày một số kết quả về xấp xỉ tốt nhất. Các kết quả này có thể không đúng trong một vài trường hợp biên không thú vị. Chẳng hạn, cả hai định nghĩa xấp xỉ tốt nhất đều yêu cầu bất đẳng thức nghiêm ngặt, nhưng với nửa số lẻ $x=n+\dfrac12$ và $n\in\mathbf Z$, liên phân số của nó có thể có dạng $[n,1,1]$. Khi đó, hai phân số tiệm cận đầu $x_0=n$ và $x_1=n+1$ đều có mẫu bằng $1$, và khoảng cách tới $x$ bằng nhau. Điều này cho thấy chúng đều không phải là xấp xỉ tốt nhất. Khi đọc các kết luận trong phần này, nên mặc định rằng những trường hợp như vậy đã được loại trừ. Nếu không quan tâm tới vài phân số tiệm cận cuối cùng, hoặc chỉ quan tâm tới xấp xỉ số vô tỉ, thì có thể bỏ qua các trường hợp phức tạp bổ sung này.

<span id="xấp-xỉ-tốt-nhất-loại-một-phân-số-trung-gian"></span>

### Xấp xỉ tốt nhất loại một: phân số trung gian

Xấp xỉ tốt nhất loại một dùng

$$
\left|x-\dfrac{p}{q}\right|
$$

để đo mức độ xấp xỉ.

???+ abstract "Xấp xỉ tốt nhất loại một"
    Với số thực $x$ và số hữu tỉ $\dfrac{p}{q}$, nếu với mọi $\dfrac{p'}{q'}\neq \dfrac{p}{q}$ và $0<q'\le q$ ta đều có
    
    $$
    \left|x-\dfrac{p}{q}\right|<\left|x-\dfrac{p'}{q'}\right|,
    $$
    
    thì số hữu tỉ $\dfrac{p}{q}$ được gọi là **xấp xỉ tốt nhất loại một** của số thực $x$.

Xấp xỉ tốt nhất loại một không nhất thiết là phân số tiệm cận, mà thuộc một lớp phân số rộng hơn.

???+ abstract "Phân số trung gian"
    Giả sử số thực $x$ có phân số tiệm cận $x_{k+1}=[a_0,a_1,\cdots,a_k,a_{k+1}]$, và số nguyên $t$ thỏa mãn $0\le t\le a_{k+1}$[^semi-range]. Khi đó phân số $x_{k,t}=[a_0,a_1,\cdots,a_{k},t]$ được gọi là **phân số trung gian** (intermediate fraction), **bán hội tụ** (semiconvergent), hoặc **phân số tiệm cận phụ** (secondary convergent) của $x$.[^semiconvergent]
    
    Tương tự trường hợp phân số tiệm cận, phân số trung gian lớn hơn (nhỏ hơn) $x$ được gọi là **phân số trung gian trên (dưới)** (upper (lower) semiconvergent).

Theo công thức truy hồi, phân số trung gian có thể viết thành

$$
x_{k,t} = \frac{tp_{k}+p_{k-1}}{tq_{k}+q_{k-1}}.
$$

Nó chắc chắn là phân số tối giản và nằm giữa hai phân số tiệm cận $x_{k-1}$ và $x_{k+1}$. Khi $t$ tăng, nó cũng dần tiến tới $x_{k+1}$; ví dụ với trường hợp $k$ chẵn:

$$
x_{k-1} = x_{k,0} < x_{k,1} < x_{k,2} < \cdots < x_{k,a_{k+1}} = x_{k+1}.
$$

Vì tử số và mẫu số của các phân số tiệm cận đều tăng, tử số và mẫu số của phân số trung gian $x_{k,t}$ ($t\neq 0$) nằm giữa các giá trị tương ứng của $x_{k}$ và $x_{k+1}$. Nếu sắp các phân số này theo mẫu số, thì phân số trung gian chính là những phân số nằm giữa hai phân số tiệm cận kề nhau.

Mọi xấp xỉ tốt nhất loại một đều là phân số trung gian, nhưng không phải mọi phân số trung gian đều là xấp xỉ tốt nhất loại một.

???+ note "Định lý"
    Mọi xấp xỉ tốt nhất loại một đều là phân số trung gian.

??? note "Chứng minh"
    Vì $a_0\le x\le a_0+1$, nên xấp xỉ tốt nhất loại một chắc chắn nằm giữa $x_{1,0}=a_0$ và $x_{0,1}=a_0+1$. Tất cả phân số trung gian có thể được sắp tăng dần thành
    
    $$
    x_{1,0}<x_{1,1}< \cdots < x_{1,a_2}=x_{3,0}<\ldots<x<\ldots<x_{2,0}=x_{0,a_1}<\cdots<x_{0,1}.
    $$
    
    Các phân số trung gian cùng bậc xuất hiện liên tiếp, còn giữa các phân số trung gian khác bậc thì không có khoảng trống. Điều này nghĩa là mọi số hữu tỉ $\dfrac{p}{q}$ nằm giữa $x_{1,0}=a_0$ và $x_{0,1}=a_0+1$ chắc chắn rơi vào giữa hai phân số trung gian cùng bậc $x_{k,t}$ và $x_{k,t+1}$. Giả sử nó không phải phân số trung gian và nhỏ hơn $x$, khi đó
    
    $$
    x_{k,t}<\dfrac{p}{q}<x_{k,t+1}<x.
    $$
    
    Khi đó, một mặt
    
    $$
    \left|x_{k,t}-\dfrac{p}{q}\right| \le \left|x_{k,t}-x_{k,t+1}\right| = \dfrac{1}{((t+1)q_k+q_{k-1})(tq_k+q_{k-1})}.
    $$
    
    Mặt khác
    
    $$
    \left|x_{k,t}-\dfrac{p}{q}\right| = \dfrac{|q(tp_k+p_{k-1})-p((t+1)q_k+q_{k-1})|}{q(tq_k+q_{k-1})}\ge\dfrac{1}{q(tq_k+q_{k-1})}.
    $$
    
    Vì vậy, chắc chắn
    
    $$
    q>(t+1)q_k+q_{k-1}.
    $$
    
    Nói cách khác, mẫu số của số hữu tỉ $\dfrac{p}{q}$ chắc chắn lớn hơn mẫu số của $x_{k,t+1}$, nhưng nó không phải xấp xỉ tốt hơn:
    
    $$
    \left|x-\dfrac{p}{q}\right|>\left|x-x_{k,t+1}\right|
    $$
    
    Do đó, nó không thể là xấp xỉ tốt nhất loại một. Điều này cho thấy nếu không phải phân số trung gian thì không phải xấp xỉ tốt nhất loại một; tức mọi xấp xỉ tốt nhất loại một đều là phân số trung gian.

Chiều ngược lại không đúng: không thể khẳng định mọi phân số trung gian đều là xấp xỉ tốt nhất loại một. Tuy nhiên, có thể đưa ra điều kiện để một phân số trung gian là xấp xỉ tốt nhất loại một.

???+ note "Định lý"
    Mọi phân số tiệm cận đều là xấp xỉ tốt nhất loại một. Ngoài ra, giả sử $0<t<a_{k+1}$; khi đó phân số trung gian $x_{k,t}$ là xấp xỉ tốt nhất loại một khi và chỉ khi $t>\dfrac{a_{k+1}}{2}$, hoặc $t=\dfrac{a_{k+1}}{2}$ và $r_{k+2}>\dfrac{q_k}{q_{k-1}}$.

??? note "Chứng minh"
    Phần sau sẽ chứng minh rằng mọi phân số tiệm cận đều là xấp xỉ tốt nhất loại hai, nên chắc chắn là xấp xỉ tốt nhất loại một. Điểm chính nằm ở các phân số trung gian không phải phân số tiệm cận.
    
    Như đã nói ở trên, mẫu số của phân số trung gian $x_{k,t}$ nằm giữa mẫu số của $x_k$ và $x_{k+1}$, và tăng dần theo $t$; đồng thời $x_{k,t}$ cũng tiến dần tới $x_{k+1}$, nên gần $x$ hơn. Lấy ví dụ $x_{k,t}<x$, quan hệ vị trí tương đối của nó với các phân số trung gian kề nhau là:
    
    $$
    x_{k-1} < x_{k,t} < x_{k+1} < x < x_{k}.
    $$
    
    Vì mẫu số của $x_k$ nhỏ hơn mẫu số của $x_{k,t}$, điều kiện cần để $x_{k,t}$ trở thành xấp xỉ tốt nhất loại một là nó phải gần $x$ hơn $x_k$. Đây cũng là điều kiện đủ: vì $x_k$ là phân số tiệm cận, không có phân số nào có mẫu nhỏ hơn mà lại gần $x$ hơn; còn các phân số trung gian có mẫu lớn hơn $x_k$ thì tất yếu cùng bậc với $x_{k,t}$ nhưng có mẫu nhỏ hơn, nên chắc chắn xa $x$ hơn. Với sai số của phân số tiệm cận và phân số trung gian, tính toán cho thấy
    
    $$
    \begin{aligned}
    \left|x_k-x\right| &= \dfrac{1}{q_k(r_{k+1}q_k+q_{k-1})},\\
    \left|x_{k,t}-x\right| &= \left|\dfrac{tp_{k}+p_{k-1}}{tq_{k}+q_{k-1}}-\dfrac{r_{k+1}p_{k}+p_{k-1}}{r_{k+1}q_{k}+q_{k-1}}\right| \\
    &=\dfrac{r_{k+1}-t}{(tq_{k}+q_{k-1})(r_{k+1}q_{k}+q_{k-1})}.
    \end{aligned}
    $$
    
    trong đó dùng $r_{k+1}\ge a_{k+1}>t$. Vì vậy, $x_{k,t}$ gần $x$ hơn $x_k$, tức trở thành xấp xỉ tốt nhất loại một, khi và chỉ khi
    
    $$
    \dfrac{r_{k+1}-t}{tq_{k}+q_{k-1}}<\dfrac{1}{q_k} \iff r_{k+1}<2t+\dfrac{q_{k-1}}{q_k}.
    $$
    
    Lúc này có ba khả năng:
    
    1.  Nếu $t<\dfrac{a_{t+1}}{2}$, thì $2t<a_{t+1}$. Vì hai vế đều là số nguyên, $2t\le a_{k+1}-1$, nên $2t+\dfrac{q_{k-1}}{q_k}\le 2t+1\le a_{k+1}\le r_{t+1}$. Khi đó, $x_{k,t}$ không phải xấp xỉ tốt nhất loại một;
    2.  Nếu $t>\dfrac{a_{t+1}}{2}$, thì $2t>a_{t+1}$. Vì hai vế đều là số nguyên, $2t\ge a_{t+1}+1>r_{t+1}$. Khi đó, $x_{k,t}$ là xấp xỉ tốt nhất loại một;
    3.  Nếu $a_{t+1}$ là số chẵn, còn có khả năng thứ ba, tức $t=\dfrac{a_{t+1}}{2}$. Điều kiện trên tương đương với $\dfrac{1}{r_{k+1}}=r_{k+1}-a_{k+1}<\dfrac{q_{k-1}}{q_k}$, tức $r_{k+2}>\dfrac{q_k}{q_{k-1}}$.

Vì vậy, nếu sắp tất cả xấp xỉ tốt nhất loại một của số thực $x$ theo mẫu số tăng dần, chúng sẽ được chia thành nhiều đoạn theo quan hệ lớn nhỏ với $x$. Mỗi đoạn luôn gồm một số (có thể bằng không) phân số trung gian liên tiếp cùng bậc, và luôn kết thúc bằng một phân số tiệm cận. Trong mỗi đoạn, các phân số luôn nằm cùng một phía của số thực $x$; giữa các đoạn thì chúng luân phiên nằm ở hai phía của $x$.

??? example "Ví dụ: xấp xỉ tốt nhất loại một của số pi $\pi$"
    Số pi $\pi=[3,7,15,1,292,\cdots]$, nên 15 xấp xỉ tốt nhất loại một đầu tiên có mẫu nhỏ nhất của nó là:
    
    $$
    \begin{aligned}
    &x_0 = \dfrac{3}{1},\
    x_{0,4} = \dfrac{13}{4},\
    x_{0,5} = \dfrac{16}{5},\
    x_{0,6} = \dfrac{19}{6},\
    x_1 = \dfrac{22}{7},\\
    &x_{1,8} = \dfrac{179}{57},\
    x_{1,9} = \dfrac{201}{64},\
    x_{1,10} = \dfrac{223}{71},\
    x_{1,11} = \dfrac{245}{78},\
    x_{1,12} = \dfrac{267}{85},\\
    &x_{1,13} = \dfrac{289}{92},
    x_{1,14} = \dfrac{311}{99},\
    x_2 = \dfrac{333}{106},\
    x_3 = \dfrac{355}{113},\
    x_{3,146} = \dfrac{52163}{16604}.
    \end{aligned}
    $$

<span id="xấp-xỉ-tốt-nhất-loại-hai"></span>

### Xấp xỉ tốt nhất loại hai

Xấp xỉ tốt nhất loại hai dùng $|qx-p|$ để đo mức độ xấp xỉ.

???+ abstract "Xấp xỉ tốt nhất loại hai"
    Với số thực $x$ và số hữu tỉ $\dfrac{p}{q}$, nếu với mọi $\dfrac{p'}{q'}\neq \dfrac{p}{q}$ và $0<q'\le q$ ta đều có
    
    $$
    \left|qx-p\right|<\left|q'x-p'\right|,
    $$
    
    thì số hữu tỉ $\dfrac{p}{q}$ được gọi là **xấp xỉ tốt nhất loại hai** của số thực $x$.

Điều kiện của xấp xỉ tốt nhất loại hai tương đương với

$$
\left|x-\dfrac{p}{q}\right|<\dfrac{q'}{q}\left|x-\dfrac{p'}{q'}\right|.
$$

Vì $q'\le q$, điều kiện của xấp xỉ tốt nhất loại hai nghiêm ngặt hơn điều kiện của xấp xỉ tốt nhất loại một.

Xấp xỉ tốt nhất loại hai chính xác là các phân số tiệm cận.

???+ note "Định lý"
    Mọi xấp xỉ tốt nhất loại hai đều là phân số tiệm cận, và mọi phân số tiệm cận đều là xấp xỉ tốt nhất loại hai.

??? note "Chứng minh"
    Để chứng minh phần thứ nhất, vì xấp xỉ tốt nhất loại hai cũng chắc chắn là xấp xỉ tốt nhất loại một, chỉ cần chứng minh các phân số trung gian không phải phân số tiệm cận không thể là xấp xỉ tốt nhất loại hai. Đặt $x_{k,t}=\dfrac{p}{q}$ là phân số trung gian nhưng không phải phân số tiệm cận, và giả sử $x_{k,t}<x$, ta có
    
    $$
    x_{k-1} < x_{k,t} < x_{k+1} < x < x_{k}.
    $$
    
    Vì sai số giữa $x_{k,t}$ và $x$ là
    
    $$
    |x_{k,t}-x|\ge |x_{k,t}-x_{k+1}|=\left|\dfrac{p}{q}-\dfrac{p_{k+1}}{q_{k+1}}\right|=\dfrac{|pq_{k+1}-p_{k+1}q|}{qq_{k+1}}\ge\dfrac{1}{qq_{k+1}},
    $$
    
    và dùng ước lượng sai số của phân số tiệm cận, nên luôn có
    
    $$
    |qx_{k,t}-p| \ge \dfrac{1}{q_{k+1}} \ge |q_kx_k-p_k|,
    $$
    
    tức mức độ xấp xỉ của $x_{k,t}$ không tốt hơn mức độ xấp xỉ của $x_k$ có mẫu nhỏ hơn, nên nó không thể là xấp xỉ tốt nhất loại hai.
    
    Ngược lại, để chứng minh phần thứ hai, tức mọi phân số tiệm cận $x_k=\dfrac{p_k}{q_k}$ đều là xấp xỉ tốt nhất loại hai, ta cần chỉ ra rằng với mọi phân số $\dfrac{p}{q}$ có $q\le q_k$, luôn có $|q_kx-p_k|<|qx-p|$. Bỏ qua trường hợp nửa số lẻ, có thể giả sử $k>0$. Trước hết, theo ước lượng sai số của phân số tiệm cận khi xấp xỉ số thực, ta có
    
    $$
    |q_{k-1} x-p_{k-1}| \ge \frac{1}{q_{k-1}+q_{k}} \ge \dfrac{1}{q_{k+1}}\ge |q_kx-p_k|.
    $$
    
    Tất cả các bất đẳng thức cùng xảy ra dấu bằng khi và chỉ khi $a_{k+1}=1$ và đó là hạng cuối của liên phân số. Bỏ qua trường hợp này, $x_{k-1}=\dfrac{p_{k-1}}{q_{k-1}}$ kém nghiêm ngặt so với $x_k=\dfrac{p_k}{q_k}$.
    
    Lấy tùy ý một phân số $\dfrac{p}{q}\neq x_k$ với $0<q\le q_k$. Vì có công thức hiệu $p_{k}q_{k-1} − p_{k-1}q_{k} = (−1)^{k-1}$, theo quy tắc Cramer, hệ phương trình tuyến tính
    
    $$
    \begin{cases}
    \lambda p_k+\mu p_{k-1} = p,\\
    \lambda q_k+\mu q_{k-1} = q
    \end{cases}
    $$
    
    chắc chắn có nghiệm nguyên duy nhất $(\lambda,\mu)$. Nếu $\lambda\mu>0$, thì $q>|\lambda|q_k\ge q_k$, mâu thuẫn. Ngược lại, $\lambda\mu\le 0$, tức $\lambda$ và $\mu$ trái dấu. Vì $q_{k-1}x-p_{k-1}$ và $q_kx-p_k$ cũng trái dấu, nên $\lambda(q_{k-1}x-p_{k-1})$ và $\mu(q_kx-p_k)$ cùng dấu, do đó
    
    $$
    |qx-p|=|\lambda||q_kx-p_k|+|\mu||q_{k-1}x-p_{k-1}|>|q_{k}x-p_{k}|.
    $$
    
    Bất đẳng thức cuối là nghiêm ngặt, vì $x_{k-1}$ nghiêm ngặt kém hơn $x_k$, và $\dfrac{p}{q}\neq x_k$. Điều này chứng minh $x_k$ là xấp xỉ tốt nhất loại hai.

Tính chất này cho thấy phân số tiệm cận thật sự là các xấp xỉ Diophantine rất tốt.

<span id="nhận-biết-phân-số-tiệm-cận"></span>

### Nhận biết phân số tiệm cận

Xấp xỉ tốt nhất loại hai cung cấp điều kiện cần và đủ để xác định một phân số có phải là phân số tiệm cận hay không. Điều này cho thấy có thể kiểm tra mức độ xấp xỉ tương đối của một phân số để quyết định nó có phải là phân số tiệm cận hay không. Tiêu chuẩn Legendre cung cấp cách nhận biết phân số tiệm cận dựa trên mức độ xấp xỉ tuyệt đối. Phát biểu gốc của tiêu chuẩn Legendre cho điều kiện cần và đủ, nhưng dạng của nó không thực dụng. Phần này đưa ra phiên bản giản lược của tiêu chuẩn Legendre, đồng thời chỉ ra rằng nó không bỏ sót quá nhiều phân số tiệm cận.

???+ note "Định lý (Legendre)"
    Với số thực $x$ và phân số $\dfrac{p}{q}$, nếu
    
    $$
    \left|x−\dfrac{p}{q}\right|<\dfrac{1}{2q^2}
    $$
    
    thì $\dfrac{p}{q}$ chắc chắn là phân số tiệm cận của $x$.

??? note "Chứng minh"
    Gọi $\epsilon\in\{-1,1\}$ và $\theta\in(0,1/2)$ là các hằng số sao cho
    
    $$
    x−\dfrac{p}{q} = \dfrac{\epsilon\theta}{q^2}
    $$
    
    đúng. Khai triển số hữu tỉ $\dfrac{p}{q}$ thành liên phân số $[a_0,a_1,\cdots,a_n]$. Ở đây, số hữu tỉ có hai biểu diễn liên phân số, trong đó $n$ chênh nhau đúng một; vì vậy có thể chọn biểu diễn liên phân số sao cho $(-1)^n=\epsilon$, và ký hiệu các phân số tiệm cận của biểu diễn này là $\dfrac{p_k}{q_k}$. Giả sử số thực $\omega$ thỏa mãn
    
    $$
    x = \dfrac{\omega p_n+p_{n-1}}{\omega q_n+q_{n-1}}.
    $$
    
    Khi đó, chắc chắn
    
    $$
    \dfrac{\epsilon\theta}{q^2} = x−\dfrac{p}{q} = x-\dfrac{p_n}{q_n} = \dfrac{p_{n-1}q_n-p_nq_{n-1}}{(\omega q_n+q_{n-1})q_n} = \dfrac{(-1)^n}{(\omega q_n+q_{n-1})q_n}.
    $$
    
    Do đó,
    
    $$
    \theta = \dfrac{q_n}{\omega q_n+q_{n-1}}.
    $$
    
    Điều này cho thấy
    
    $$
    \omega=\dfrac{1}{\theta}-\dfrac{q_{n-1}}{q_n}>1.
    $$
    
    Khai triển cả $\omega$ thành liên phân số $[b_0,b_1,\cdots]$, ta có
    
    $$
    x = \dfrac{\omega p_n+p_{n-1}}{\omega q_n+q_{n-1}} = [a_0,a_1,\cdots,a_n,\omega] = [a_0,a_1,\cdots,a_n,b_0,b_1,\cdots].
    $$
    
    Đây là một liên phân số đơn giản hợp lệ, nên $\dfrac{p}{q}$ chính là phân số tiệm cận của $x$.
    
    Chứng minh này thật ra cho thấy điều kiện cần và đủ để $\dfrac{p}{q}$ là phân số tiệm cận chính là $\omega>1$ trong chứng minh trên; đó là dạng gốc của tiêu chuẩn Legendre.

Tiêu chuẩn này cho thấy chỉ cần mức xấp xỉ đủ tốt thì phân số đó chắc chắn là phân số tiệm cận. Định lý tiếp theo cho thấy có đủ nhiều phân số tiệm cận tốt như vậy: ít nhất một nửa các phân số tiệm cận thỏa mãn điều kiện này.

???+ note "Định lý (Valhen)"
    Trong hai phân số tiệm cận kề nhau của số thực $x$, ít nhất một phân số thỏa mãn
    
    $$
    \left|x−\dfrac{p}{q}\right|<\dfrac{1}{2q^2}.
    $$

??? note "Chứng minh"
    Giả sử ngược lại. Tồn tại số thực $x$ có hai phân số tiệm cận kề nhau $x_{k-1}$ và $x_k$ thỏa mãn
    
    $$
    \left|x-\dfrac{p_k}{q_k}\right|\ge \dfrac{1}{2q_{k}^2},\ \left|x-\dfrac{p_{k+1}}{q_{k+1}}\right|\ge \dfrac{1}{2q_{k+1}^2}.
    $$
    
    Vì $x$ nằm giữa $x_{k-1}$ và $x_k$, nên
    
    $$
    \dfrac{1}{2q_{k}^2} + \dfrac{1}{2q_{k+1}^2} \le \left|x-\dfrac{p_k}{q_k}\right| + \left|x-\dfrac{p_{k+1}}{q_{k+1}}\right| = \left|\dfrac{p_k}{q_k}-\dfrac{p_{k+1}}{q_{k+1}}\right| = \dfrac{1}{q_kq_{k+1}}.
    $$
    
    Điều này cho thấy $q_k=q_{k+1}$. Vì vậy chắc chắn $k=0$ và $a_1=1$. Khi đó hai phân số tiệm cận đầu là $x_0=a_0$ và $x_1=a_0+1$. Do đó phản ví dụ duy nhất của mệnh đề là nửa số lẻ; như đã nói ở trên, bài viết này không xét trường hợp đó.

<span id="diễn-giải-hình-học"></span>

## Diễn giải hình học

Lý thuyết liên phân số có một diễn giải hình học đẹp.

![](./images/continued-convergents-geometry.svg)

Như hình vẽ, với số thực $\xi>0$, đường thẳng $y=\xi x$ chia các điểm nguyên (lattice point) trong góc phần tư thứ nhất (bao gồm các điểm trên trục tọa độ $x$ và $y$ nhưng không bao gồm gốc tọa độ; dưới đây cũng hiểu như vậy) thành hai phần trên và dưới. Với trường hợp $\xi$ hữu tỉ, các điểm nằm trên đường thẳng $y=\xi x$ được tính vừa là điểm phía trên vừa là điểm phía dưới đường thẳng. Xét bao lồi của hai phần điểm này. Khi đó, các phân số tiệm cận chỉ số lẻ là các đỉnh của bao lồi phần trên, còn các phân số tiệm cận chỉ số chẵn là các đỉnh của bao lồi phần dưới. Các điểm nguyên trên đoạn nối giữa hai đỉnh kề nhau của bao lồi chính là các phân số trung gian. Hình vẽ minh họa các phân số tiệm cận và phân số trung gian (điểm xám) của $\xi=\dfrac{9}{7}$.

Phần lớn các kết luận ở trên về liên phân số đều có diễn giải hình học tương ứng:

??? note "Diễn giải hình học"
    -   Mỗi phân số $\nu=\dfrac{p}{q}$ tương ứng với một điểm nguyên $\vec\nu=(q,p)$ trong góc phần tư thứ nhất; độ lớn của phân số tương ứng với hệ số góc của đường nối điểm đó với gốc tọa độ.
    -   Véc-tơ chỉ phương của đường thẳng $y=\xi x$ là $\vec\xi=(1,\xi)$. Dùng khái niệm [tích có hướng](../linear-algebra/product.md#trường-hợp-vectơ-hai-chiều) $(x_1,y_1)\times(x_2,y_2)=x_1y_2-x_2y_1$, có thể xét dấu của $\vec\xi\times\vec\nu=p-q\xi$ để xác định điểm nằm phía trên hay phía dưới đường thẳng. Vì vậy, điểm phía trên đường thẳng tương ứng với phân số lớn hơn hoặc bằng $\xi$, còn điểm phía dưới đường thẳng tương ứng với phân số nhỏ hơn hoặc bằng $\xi$. Giá trị tuyệt đối của tích có hướng $|\vec\xi\times\vec\nu|$ tỉ lệ với khoảng cách từ điểm $\vec\nu$ tới đường thẳng $y=\xi x$:
    
        $$
        \dfrac{|p-qx|}{\sqrt{1+\xi^2}},
        $$
    
        và tương ứng với mức độ xấp xỉ số thực $\xi$ của phân số $\nu$.
    -   Gọi điểm tương ứng với phân số tiệm cận $\xi_k=\dfrac{p_k}{q_k}$ là $\vec\xi_k=(p_k,q_k)$, khi đó công thức truy hồi có thể viết thành
    
        $$
        \vec\xi_k = a_k\vec\xi_{k-1} + \vec\xi_{k-2}.
        $$
    
        Điểm bắt đầu của đệ quy là $\xi_{-2} = (1,0)$ và $\xi_{-1} = (0,1)$.
    -   Với số nguyên $t$, nếu $0\le t\le a_k$, thì điểm
    
        $$
        \vec\xi_{k-1,t} = t\vec\xi_{k-1} + \vec\xi_{k-2}
        $$
    
        nằm trên đoạn nối điểm $\vec\xi_{k-2}$ và điểm $\vec\xi_k$. Chúng tương ứng với các phân số trung gian $\xi_{k-1,t}$.
    -   Có thể dùng phương pháp hình học để dựng tất cả phân số tiệm cận và phân số trung gian. Bắt đầu từ điểm $\vec\xi_{-2}=(1,0)$ và điểm $\vec\xi_{-1}=(0,1)$; hai điểm này nằm ở hai phía của đường thẳng $y=\xi x$, nghĩa là $\vec\xi\times\vec\xi_{-2}$ và $\vec\xi\times\vec\xi_{-1}$ trái dấu. Cộng $\vec\xi_{-1}$ vào $\vec\xi_{-2}$ theo phép cộng véc-tơ cho đến khi không thể cộng tiếp mà không vượt qua đường thẳng $y=\xi x$; ký hiệu kết quả là $\vec\xi_0$, lúc này nó vẫn khác phía với $\vec\xi_{-1}$. Sau đó cộng $\vec\xi_0$ vào $\vec\xi_{-1}$ cho đến khi không thể cộng tiếp mà không vượt qua đường thẳng $y=\xi x$; ký hiệu kết quả là $\vec\xi_1$, lúc này nó vẫn khác phía với $\vec\xi_0$. Quá trình này có thể tiếp tục vô hạn, trừ khi sau hữu hạn bước có một $\vec\xi_n$ nằm đúng trên đường thẳng $y=\xi x$. Trường hợp sau nghĩa là véc-tơ $\vec\xi$ cùng phương với $\vec\xi_n$, tức $\xi=\dfrac{p_n}{q_n}$ là điểm hữu tỉ. Quá trình này tạo ra hình minh họa ở trên. Boris Delaunay gọi một cách hình tượng quá trình này là thuật toán kéo dài mũi (nose-streching algorithm)[^nose-streching].
    -   Nếu cần tính nhanh số lần phải cộng $\vec\xi_{k-1}$ vào $\vec\xi_{k-2}$ ở mỗi bước, có thể dùng tích có hướng. Vì $\vec\xi\times\vec\xi_{k-1}$ và $\vec\xi\times\vec\xi_{k-2}$ trái dấu, nếu ký hiệu $\vec\xi_{k-1,t}=t\vec\xi_{k-1}+\vec\xi_{k-2}$ là kết quả sau khi cộng $\vec\xi_{k-1}$ vào $\vec\xi_{k-2}$ đúng $t$ lần, thì việc $\vec\xi\times\vec\xi_{k-1,t}=t(\vec\xi\times\vec\xi_{k-1})+(\vec\xi\times\vec\xi_{k-2})$ không đổi dấu nghĩa là chưa vượt qua đường thẳng. Trước khi đổi dấu, giá trị tuyệt đối của $\vec\xi\times\vec\xi_{k-1,t}$ giảm dần. Ký hiệu
    
        $$
        r_{k} = \left|\dfrac{\vec\xi\times\vec\xi_{k-2}}{\vec\xi\times\vec\xi_{k-1}}\right| = -\dfrac{\vec\xi\times\vec\xi_{k-2}}{\vec\xi\times\vec\xi_{k-1}}.
        $$
    
        Khi đó, số lần tối đa có thể giảm là
    
        $$
        a_{k} = \lfloor r_{k}\rfloor = \left\lfloor\left|\dfrac{q_{k-1}\xi-p_{k-1}}{q_{k-2}\xi-p_{k-2}}\right|\right\rfloor.
        $$
    
        Đây chính là hạng thứ $k$ của khai triển liên phân số. Hơn nữa, $r_k$ là phần dư của khai triển liên phân số, và nó thỏa mãn hệ thức:
    
        $$
        r_k = -\dfrac{q_{k-1}\xi-p_{k-1}}{q_{k-2}\xi-p_{k-2}} \iff \xi = \dfrac{p_{k-1}r_k + p_{k-2}}{q_{k-1}r_k+q_{k-2}}.
        $$
    
        Đây chính là hệ thức liên phân số $\xi = [a_0,a_1,\cdots,a_{k-1},r_k]$.
    -   Vì mỗi lần cộng véc-tơ làm $\vec\xi\times\vec\xi_{k-1,t}$ thay đổi với bước đúng bằng $|\vec\xi\times\vec\xi_{k-1}|$, khoảng cách còn lại cuối cùng $|\vec\xi\times\vec\xi_k|$ chắc chắn nhỏ hơn nghiêm ngặt $|\vec\xi\times\vec\xi_{k-1}|$. Điều này cho thấy mức độ xấp xỉ của phân số tiệm cận (đo bằng $|qx-p|$) tốt lên nghiêm ngặt khi $k$ tăng.
    -   Dùng quy tắc tính của tích có hướng, ta có
    
        $$
        \vec\xi_{k}\times\vec\xi_{k+1} = \vec\xi_{k}\times(a_{k+1}\vec\xi_k+\vec\xi_{k-1}) = \vec\xi_{k}\times\vec\xi_{k-1} = -\vec\xi_{k-1}\times\vec\xi_{k}.
        $$
    
        Theo quy nạp,
    
        $$
        \vec\xi_{k}\times\vec\xi_{k+1} = (-1)^{k+2}\vec\xi_{k-2}\times\vec\xi_{k-1} = (-1)^{k}.
        $$
    
        Đây chính là công thức hiệu của phân số tiệm cận $p_{k+1}q_k-p_kq_{k+1}=(-1)^k$.
    -   Diện tích giữa hai bao lồi trên và dưới có thể được chia thành một số (có thể vô hạn) tam giác, trong đó mỗi tam giác có các đỉnh lần lượt là $\vec\xi_{k-2}$, $\vec\xi_k$ và $\vec 0$. Diện tích của tam giác như vậy là
    
        $$
        \dfrac12|\vec\xi_{k-2}\times\vec\xi_k| = \dfrac12|\vec\xi_{k-2}\times(a_k\vec\xi_{k-1}+\vec\xi_{k-2})| = \dfrac{a_k}{2}|\vec\xi_{k-2}\times\vec\xi_{k-1}| = \dfrac{a_k}{2}.
        $$
    
        Theo [định lý Pick](../../geometry/pick.md), điều này nghĩa là nếu gọi $I$ và $B$ lần lượt là số điểm nguyên bên trong và trên biên của tam giác, thì
    
        $$
        I + \dfrac{B}{2} - 1 = \dfrac{a_k}{2}.
        $$
    
        Mặt khác, trên biên tam giác đã có tổng cộng $a_k+2$ điểm nguyên là $\{\vec 0\}\cup\{\vec\xi_{k-1,t}:0\le t\le a_k\}$. Điều này cho thấy chắc chắn $I=0$ và $B=a_k+2$. Vì vậy, trên các cạnh của tam giác không còn điểm nguyên nào khác, và bên trong tam giác cũng không có điểm nguyên. Nói cách khác, $q_k$ và $p_k$ nguyên tố cùng nhau, các phân số trung gian là toàn bộ điểm nguyên trên cạnh nối $\vec\xi_{k-2}$ và $\vec\xi_k$, và tất cả điểm nguyên trong góc phần tư thứ nhất đều nằm trong hai bao lồi trên và dưới.

Hai bao lồi trên và dưới thu được như vậy được gọi là đa giác Klein. Trong không gian chiều cao hơn cũng có thể định nghĩa tương tự để thu được [đa diện Klein](https://en.wikipedia.org/wiki/Klein_polyhedron) (Klein polyhedron), qua đó mở rộng khái niệm liên phân số lên không gian nhiều chiều.

<span id="cây-của-liên-phân-số"></span>

## Cây của liên phân số

Bài chính: [Cây Stern-Brocot và dãy Farey](./stern-brocot.md)

Cây Stern-Brocot là một [cây tìm kiếm nhị phân](../../ds/bst.md) lưu tất cả các phân số nằm trong $[0,\infty]$. Liên phân số hữu hạn thực chất mã hóa đường đi trên cây Stern-Brocot từ gốc tới vị trí của một phân số. Nói cách khác, biểu diễn liên phân số $[a_0,a_1,\cdots,a_{n-1},1]$ của số hữu tỉ $x$ nghĩa là bắt đầu từ gốc cây $\dfrac{1}{1}$, trước hết đi sang con phải $a_0$ lần, rồi sang con trái $a_1$ lần, luân phiên hướng đi như vậy cho tới khi đã đi $a_{n-1}$ lần theo một hướng nào đó. Cần chú ý rằng ở đây chỉ được dùng biểu diễn liên phân số kết thúc bằng $1$.

Hiểu biểu diễn liên phân số như đường đi trên cây Stern-Brocot sẽ cho thuật toán so sánh độ lớn của hai liên phân số.

???+ example "So sánh độ lớn liên phân số"
    Cho hai liên phân số $\alpha=[\alpha_0,\alpha_1,\cdots,\alpha_n]$ và $\beta=[\beta_0,\beta_1,\cdots,\beta_m]$, hãy so sánh độ lớn của chúng.

??? note "Lời giải"
    Trước hết, chuyển cả hai biểu diễn liên phân số về dạng kết thúc bằng $1$. Không mất tính tổng quát, giả sử liên phân số đề bài cho đã ở dạng này, tức $\alpha_n=\beta_m=1$. Vì các vị trí chẵn (đánh số từ $0$) là số bước đi sang phải, còn các vị trí lẻ là số bước đi sang trái, nên $\alpha<\beta$ khi và chỉ khi theo so sánh [thứ tự từ điển](../../string/basic.md#thứ-tự-từ-điển), ta có
    
    $$
    (\alpha_0,-\alpha_1,\alpha_2,\cdots,(-1)^{n-1}\alpha_{n-1},0,\cdots)<(\beta_0,-\beta_1,\beta_2,\cdots,(-1)^{m-1}\beta_{m-1},0,\cdots).
    $$
    
    So với biểu diễn liên phân số, ta luân phiên thêm dấu dương âm, bỏ hạng $1$ cuối cùng, và điền $0$ vào các vị trí thiếu độ dài.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/compare.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/compare.py:core"
        ```

???+ example "Điểm trong tốt nhất"
    Với $\dfrac{0}{1}\le\dfrac{p_0}{q_0}<\dfrac{p_1}{q_1}\le\dfrac{1}{0}$, tìm số hữu tỉ $\dfrac{p}{q}$ sao cho $\dfrac{p_0}{q_0}<\dfrac{p}{q}<\dfrac{p_1}{q_1}$ và $(q,p)$ nhỏ nhất.

??? note "Lời giải"
    Vì cây Stern-Brocot vừa là cây tìm kiếm nhị phân của các phân số trong $[0,\infty]$, vừa là [cây Descartes](../../ds/cartesian-tree.md) của cặp $(q,p)$, nên ý bài gần như chuyển thành tìm LCA (tổ tiên chung gần nhất) của hai điểm trên cây Stern-Brocot. Tuy nhiên, LCA chỉ xử lý được trường hợp khoảng đóng, và LCA có thể chính là một đầu mút. Để tránh thảo luận phụ, trước hết có thể dựng $\dfrac{p_0}{q_0}+\varepsilon$ và $\dfrac{p_1}{q_1}-\varepsilon$, rồi tính LCA. Khi đã dùng liên phân số để tính đường đi từ gốc tới nút, LCA chỉ cần lấy đường đi chung dài nhất.
    
    Để dựng $x\pm\varepsilon$, tại nút $x$ chỉ cần trước hết đi sang phải (trái) một lần, rồi đi sang trái (phải) $\infty$ lần. Chuyển sang ngôn ngữ liên phân số, với phân số $x=[a_0,a_1,\cdots,a_{n-1},1]$, ta biết $x\pm\varepsilon$ chắc chắn là $[a_0,a_1,\cdots,a_{n-1}+1,\infty]$ và $[a_0,a_1,\cdots,a_{n-1},1,\infty]$; vì vậy chỉ cần so sánh hai liên phân số này, rồi định nghĩa liên phân số lớn hơn (nhỏ hơn) là $x\pm\varepsilon$.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/inner-point.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/inner-point.py:core"
        ```

???+ example "[GCJ 2019, Round 2 - New Elements: Part 2](https://github.com/google/coding-competitions-archive/blob/main/codejam/2019/round_2/new_elements_part_2/statement.pdf)"
    Cho $N$ cặp số nguyên dương $(C_i,J_i)$, tìm cặp số nguyên dương $(x,y)$ sao cho $\{C_ix+J_iy\}$ tăng nghiêm ngặt. Trong tất cả các cặp thỏa mãn, xuất cặp nhỏ nhất theo thứ tự từ điển.

??? note "Lời giải"
    Đặt $A_i=C_i-C_{i-1}$ và $B_i=J_i-J_{i-1}$. Bài toán chuyển thành tìm $(x,y)$ sao cho tất cả $A_ix+B_iy$ đều là số nguyên. Các cặp này có thể chia thành bốn trường hợp:
    
    1.  Trường hợp $A_i,B_i>0$ có thể bỏ qua, vì đã giả sử $(x,y)>0$;
    2.  Trường hợp $A_i,B_i\le 0$ thì xuất trực tiếp "IMPOSSIBLE";
    3.  Trường hợp $A_i>0,B_i\le 0$ tương đương với ràng buộc $\dfrac{y}{x}<\dfrac{A_i}{-B_i}$;
    4.  Trường hợp $A_i\le 0,B_i>0$ tương đương với ràng buộc $\dfrac{y}{x}>\dfrac{-A_i}{B_i}$.
    
    Vì vậy, lấy $\dfrac{p_0}{q_0}$ là giá trị lớn nhất của $\dfrac{-A_i}{B_i}$ trong trường hợp thứ tư, rồi lấy $\dfrac{p_1}{q_1}$ là giá trị nhỏ nhất của $\dfrac{A_i}{-B_i}$ trong trường hợp thứ ba. Bài toán ban đầu trở thành tìm $(q,p)$ nhỏ nhất theo thứ tự từ điển sao cho $\dfrac{p_0}{q_0}<\dfrac{p}{q}<\dfrac{p_1}{q_1}$.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/gcj-2019.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/gcj-2019.py:core"
        ```

Để tìm hiểu thêm về các tính chất và ứng dụng của cây Stern-Brocot, có thể tham khảo trang bài chính của nó.

<span id="biến-đổi-tuyến-tính-phân-thức"></span>

## Biến đổi tuyến tính phân thức

Một khái niệm quan trọng khác liên quan tới liên phân số là biến đổi tuyến tính phân thức.

???+ abstract "Biến đổi tuyến tính phân thức"
    **Biến đổi tuyến tính phân thức** (fractional linear transformation) là hàm $L:\mathbf R\rightarrow\mathbf R$ sao cho
    
    $$
    L(x) = \dfrac{ax+b}{cx+d},
    $$
    
    trong đó $a,b,c,d\in\mathbf R$ và $ad-bc\neq 0$.

???+ info "Về điều kiện $ad-bc\neq 0$"
    Dễ kiểm tra rằng khi $ad-bc=0$, hàm có thể không xác định hoặc là hàm hằng.

Biến đổi tuyến tính phân thức có các tính chất sau:

???+ note "Tính chất của biến đổi tuyến tính phân thức"
    Giả sử $L_1,L_2,L_3$ là các biến đổi tuyến tính phân thức, và ký hiệu ma trận tạo bởi các hệ số của $L_i$ là
    
    $$
    M_i=\begin{pmatrix}a_i & b_i \\ c_i & d_i\end{pmatrix}
    $$
    
    Khi đó chúng có các tính chất sau:[^pgl2]
    
    1.  Hợp thành $L_1\circ L_2$ và biến đổi ngược $L_1^{-1}$ của biến đổi tuyến tính phân thức vẫn là biến đổi tuyến tính phân thức, tức toàn bộ các biến đổi tuyến tính phân thức tạo thành một [nhóm](../algebra/basic.md#nhóm);
    2.  Biến đổi tuyến tính phân thức không đổi khi các hệ số cùng nhân với một hằng số khác không, tức với mọi $\lambda\neq 0$, nếu $M_2=\lambda M_1$ thì $L_2=L_1$;
    3.  Ma trận hệ số của hợp thành các biến đổi tuyến tính phân thức tương ứng với tích của các ma trận hệ số, tức nếu $M_1M_2=M_3$ thì $L_1\circ L_2=L_3$;
    4.  Ma trận hệ số của biến đổi ngược tương ứng với ma trận nghịch đảo của ma trận hệ số, tức nếu $M_1^{-1}=M_2$ thì $L_1^{-1}=L_2$.

??? note "Chứng minh"
    Ở đây chỉ đưa ra dạng của hợp thành và biến đổi ngược của biến đổi tuyến tính phân thức. Sau khi có dạng này, mọi tính chất đều dễ kiểm tra.
    
    Hợp thành của hai biến đổi tuyến tính phân thức $L_1$ và $L_2$:
    
    $$
    \begin{aligned}
    L_1\circ L_2 &= \dfrac{a_1\dfrac{a_2x+b_2}{c_2x+d_2}+b_1}{c_1\dfrac{a_2x+b_2}{c_2x+d_2}+d_1} = \dfrac{(a_1a_2+b_1c_2)x+(a_1b_2+b_1d_2)}{(c_1a_2+d_1c_2)x+(c_1b_2+d_1d_2)}.
    \end{aligned}
    $$
    
    Biến đổi ngược của biến đổi tuyến tính phân thức $L_1(x)$:
    
    $$
    y = L_1(x) = \dfrac{a_1x+b_1}{c_1x+d_1} \iff x = L_1^{-1}(y) = \dfrac{d_1y - b_1}{-c_1y + a_1}.
    $$

Liên phân số hữu hạn $[a_0,a_1,\cdots,a_n]$ có thể xem là kết quả hợp thành của một dãy biến đổi tuyến tính phân thức. Đặt

$$
L_i(x) = \dfrac{a_ix+1}{x} = [a_i,x]. 
$$

Khi đó liên phân số hữu hạn

$$
[a_0,a_1,\cdots,a_n] = L_0\circ L_1\circ \cdots L_n(\infty).
$$

Trong đó, giá trị của biến đổi tuyến tính phân thức $L(x)=\dfrac{ax+b}{cx+d}$ tại $x=\infty$ là $\dfrac{a}{c}$, tức giới hạn của hàm khi $x\rightarrow\pm\infty$.

Với liên phân số tổng quát, giả sử phần dư của số thực $x$ là $r_{k+1}$, tức $x=[a_0,\cdots,a_k,r_{k+1}]$, ta có

$$
x = L_0\circ L_1\circ \cdots L_k(r_{k+1}) = \dfrac{p_kr_{k+1}+p_{k-1}}{q_kr_{k+1}+q_{k-1}}.
$$

Điều này đồng thời cho dạng của biến đổi tuyến tính phân thức $L_0\circ L_1\circ\cdots\circ L_k$.

Dĩ nhiên, biểu thức này cũng có thể được kiểm tra trực tiếp. Ban đầu,

$$
x=\dfrac{x+0}{0x+1}=\dfrac{p_{-1}x+p_{-2}}{q_{-1}x+q_{-2}}.
$$

Sau đó, nếu $L_0\circ L_1\circ\cdots\circ L_{k-1}$ có dạng

$$
\dfrac{p_{k-1}x+p_{k-2}}{q_{k-1}x+q_{k-2}}
$$

thì theo công thức hợp thành của biến đổi tuyến tính phân thức, ta có

$$
L_0\circ L_1\circ\cdots\circ L_{k-1}\circ L_k = \dfrac{(p_{k-1}a_k+p_{k-2})x+p_{k-1}}{(q_{k-1}a_k+q_{k-2})x+q_{k-1}} = \dfrac{p_kx+p_{k-1}}{q_kx+q_{k-1}}.
$$

Từ đó có thể thu được dạng trên bằng quy nạp. Biến đổi tuyến tính phân thức cũng cung cấp một góc nhìn khác về công thức truy hồi và điều kiện đầu.

???+ example "[DMOPC '19 Contest 7 P4 - Bob and Continued Fractions](https://dmoj.ca/problem/dmopc19c7p4)"
    Cho mảng số nguyên dương $a_1,\cdots,a_n$ và $m$ truy vấn. Mỗi truy vấn cho $l\le r$ và yêu cầu tính giá trị $[a_l,\cdots,a_r]$.

??? note "Lời giải"
    Hiểu liên phân số là giá trị tại $x=\infty$ của hợp thành một dãy biến đổi tuyến tính phân thức, ta chỉ cần có khả năng truy vấn nhiều lần hợp thành của một đoạn biến đổi tuyến tính phân thức. Vì mỗi biến đổi tuyến tính phân thức đều có nghịch đảo, có thể tiền xử lý tiền tố rồi truy vấn bằng phương pháp hiệu, với độ phức tạp $O(n+m)$; nếu cần hỗ trợ cập nhật, cũng có thể lưu bằng cây phân đoạn hoặc cấu trúc tương tự.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/flt-presum.cpp"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/flt-presum.py"
        ```

<span id="bốn-phép-toán-trên-liên-phân-số"></span>

### Bốn phép toán trên liên phân số

Dùng biến đổi tuyến tính phân thức, có thể thực hiện bốn phép toán trên liên phân số. Thuật toán này được Gosper đề xuất đầu tiên.

Nền tảng của thuật toán là tính biến đổi tuyến tính phân thức của liên phân số. Phần này lấy liên phân số hữu hạn làm ví dụ, nhưng vì mỗi lần thuật toán xuất một chữ số thì chỉ cần đọc vào hữu hạn hạng của liên phân số, nên nó cũng áp dụng được cho liên phân số vô hạn và có thể tính tới độ chính xác tùy ý. Kết hợp với thuật toán so sánh liên phân số ở trên, có thể so sánh chính xác các số thực với độ chính xác tùy ý.

???+ example "Biến đổi tuyến tính phân thức của liên phân số"
    Cho biến đổi tuyến tính phân thức $L(x)=\dfrac{ax+b}{cx+d}$ và liên phân số $\alpha=[\alpha_0,\alpha_1,\cdots,\alpha_n]$, tìm biểu diễn liên phân số $[\beta_0,\beta_1,\cdots,\beta_m]$ của $\beta=L(\alpha)$.

??? note "Lời giải"
    Ý tưởng cơ bản của thuật toán là xác định từng giá trị $\beta_i$. Ký hiệu
    
    $$
    L_\gamma(x) = \gamma+\dfrac{1}{x} = \dfrac{\gamma x+1}{x}.
    $$
    
    Vì liên phân số
    
    $$
    L(\alpha) = L\circ L_{\alpha_0}\circ L_{\alpha_1}\circ \cdots \circ L_{\alpha_n}(\infty),
    $$
    
    nên có thể tính độ lớn của $L(\alpha)$ bằng cách lần lượt hợp thành $L_{\alpha_k}$ vào $L$. Tuy nhiên, nếu muốn nhận biểu diễn liên phân số của $L(\alpha)$, ta không cần tính hoàn toàn giá trị $L(\alpha)$ rồi mới tìm biểu diễn liên phân số. Ngay trong quá trình hợp thành các $L_{\alpha_i}$, ta đã có thể xác định các giá trị $\beta_0,\beta_1,\cdots$.
    
    Chẳng hạn, giả sử hiện tại đã tính tới
    
    $$
    L\circ L_{\alpha_0}\circ L_{\alpha_1}\circ \cdots \circ L_{\alpha_k}(x) = \dfrac{a_kx+b_k}{c_kx+d_k}
    $$
    
    và $c_k,d_k$ cùng dấu. Khi đó, $L\circ L_{\alpha_0}\circ L_{\alpha_1}\circ \cdots \circ L_{\alpha_k}(x)$ đơn điệu trên $[0,\infty]$, và giá trị của nó chắc chắn nằm giữa $\dfrac{a_k}{c_k}$ và $\dfrac{b_k}{d_k}$. Vì vậy, nếu
    
    $$
    \left\lfloor\dfrac{a_k}{c_k}\right\rfloor = \left\lfloor\dfrac{b_k}{d_k}\right\rfloor,
    $$
    
    thì có thể xác định đó chính là phần nguyên $\beta_0$ của $L\circ L_{\alpha_0}\circ L_{\alpha_1}\circ \cdots \circ L_{\alpha_k}(x)$. Khi đó, hợp thành bên trái với $L_{\beta_0}^{-1}$ sẽ thu được
    
    $$
    L_{\beta_0}^{-1}\circ L\circ L_{\alpha_0}\circ L_{\alpha_1}\circ \cdots \circ L_{\alpha_k}.
    $$
    
    Lúc này, tiếp tục thêm $L_{\alpha_{k+1}},L_{\alpha_{k+2}},\cdots$ để xác định phần nguyên mới, tức $\beta_1$. Cứ tính như vậy cho tới khi xác định xong mọi giá trị $\beta_j$.
    
    Thuật toán yêu cầu $c$ và $d$ cùng dấu để bảo đảm điểm gián đoạn của hàm không nằm trong phạm vi $[0,\infty]$. Điều này luôn có thể đạt được, vì định nghĩa liên phân số đơn giản yêu cầu các hệ số (trừ $\alpha_0$) đều là số nguyên dương. Từ đó có thể chứng minh rằng sau hữu hạn bước, $c$ và $d$ chắc chắn cùng dấu, và sau đó luôn giữ cùng dấu.
    
    Khi cài đặt cụ thể, chỉ cần duy trì ma trận hệ số hiện tại của biến đổi tuyến tính phân thức $\begin{pmatrix}a&b\\c&d\end{pmatrix}$, rồi kiểm tra $c$ và $d$ có cùng dấu hay không, cũng như $\dfrac{a}{c}$ và $\dfrac{b}{d}$ có cùng phần nguyên hay không. Khi hợp thành bên phải với $L_{\alpha_i}$, ta thu được $\begin{pmatrix}a\alpha_i+b&a\\ c\alpha_i+d&c\end{pmatrix}$. Nếu hai phần nguyên giống nhau và bằng $\beta_j$, thì thêm $\beta_j$ vào liên phân số kết quả, rồi hợp thành bên trái với $L_{\beta_j}^{-1}$; việc này tương đương với tính $\begin{pmatrix}c&d\\ a\bmod c & b \bmod d \end{pmatrix}$.

Biến đổi tuyến tính phân thức của liên phân số đã đủ để tính bốn phép toán giữa một phân số và một liên phân số:

$$
\dfrac{p}{q}\pm x = \dfrac{\pm qx+p}{0x+q},\ \dfrac{p}{q}x = \dfrac{px+0}{0x+q},\ \frac{p}{q}/x = \dfrac{0x+p}{qx+0}.
$$

Với bốn phép toán giữa hai liên phân số tổng quát, cần dùng biến đổi tuyến tính phân thức hai biến:

$$
x+y = \dfrac{0xy+x+y+0}{0xy+0x+0y+1},\ xy = \dfrac{1xy+0x+0y+0}{0xy+0x+0y+1},\ \dfrac{x}{y} = \dfrac{0xy+x+0y+0}{0xy+0x+y+0}.
$$

???+ example "Biến đổi tuyến tính phân thức hai biến của liên phân số"
    Cho biến đổi tuyến tính phân thức hai biến $L(x,y)=\dfrac{axy+bx+cy+d}{exy+fx+gy+h}$ và hai liên phân số $\alpha=[\alpha_0,\alpha_1,\cdots,\alpha_n]$, $\beta=[\beta_0,\beta_1,\cdots,\beta_m]$, tìm biểu diễn liên phân số $[\gamma_0,\gamma_1,\cdots,\gamma_\ell]$ của $\gamma=L(\alpha,\beta)$.

??? note "Lời giải"
    Tương tự trường hợp biến đổi tuyến tính phân thức một biến, để xác định phần nguyên chỉ cần bảo đảm phần nguyên của biến đổi tuyến tính phân thức hiện tại không đổi trên $(x,y)\in[0,\infty]\times[0,\infty]$, tức $e,f,g,h$ đều cùng dấu và
    
    $$
    \left\lfloor\dfrac{a}{e}\right\rfloor = \left\lfloor\dfrac{b}{f}\right\rfloor = \left\lfloor\dfrac{c}{g}\right\rfloor = \left\lfloor\dfrac{d}{h}\right\rfloor.
    $$
    
    Hợp thành bên phải được thay bằng việc tính $L(x,y)\mapsto L(L_{\alpha_i}(x),y)$ và $L(x,y)\mapsto L(x,L_{\beta_j}(y))$; việc này cũng có thể biểu diễn thành biến đổi tuyến tính trên các hệ số. Hợp thành bên trái thì hoàn toàn giống trường hợp một biến, chỉ cần tính phép lấy dư.
    
    So với trường hợp một biến, trường hợp hai biến cần quyết định nên hợp thành $L_{\alpha_i}$ hay $L_{\beta_j}$ trước. Vì thứ tự hợp thành không ảnh hưởng tới kết quả cuối cùng, có thể tự do chọn thứ tự, chẳng hạn hợp thành xen kẽ $L_{\alpha_i}$ và $L_{\beta_j}$. Hoặc dùng quy tắc kinh nghiệm: ưu tiên hợp thành theo chiều có độ chênh tỉ số lớn hơn. Nếu $\left|\dfrac{b}{f}-\dfrac{d}{h}\right|>\left|\dfrac{c}{g}-\dfrac{d}{h}\right|$, thì hợp thành $L_{\alpha_i}$ trước; ngược lại, hợp thành $L_{\beta_j}$ trước.

<span id="liên-phân-số-tuần-hoàn"></span>

## Liên phân số tuần hoàn

Tương tự khái niệm số thập phân tuần hoàn, nếu các hệ số của liên phân số tạo thành chu kỳ thì ta gọi đó là liên phân số tuần hoàn.

???+ abstract "Liên phân số tuần hoàn"
    Giả sử liên phân số $x=[a_0,a_1,a_2,\cdots]$, và tồn tại số tự nhiên $K$ cùng số nguyên dương $L$ sao cho với mọi $k\ge K$, ta có $a_k=a_{k+L}$. Khi đó $x$ được gọi là **liên phân số tuần hoàn** (periodic continued fraction). Giá trị nhỏ nhất của $L$ thỏa mãn điều kiện này được gọi là chu kỳ dương nhỏ nhất của nó, còn dãy $a_{k},\cdots,a_{k+L-1}$ lặp lại trong liên phân số được gọi là khối tuần hoàn. Dùng khối tuần hoàn, liên phân số tuần hoàn có thể viết là $x=[a_0,\cdots,a_{k-1},\overline{a_k,\cdots,a_{k+L-1}}]$. Nếu có thể lấy $K=0$, tức $x=[\overline{a_0,\cdots,a_{L-1}}]$, thì nó được gọi là **liên phân số thuần tuần hoàn** (purely periodic continued fraction); ngược lại gọi là **liên phân số hỗn tuần hoàn** (eventually periodic continued fraction).

<span id="số-vô-tỉ-bậc-hai"></span>

### Số vô tỉ bậc hai

Một khái niệm liên quan mật thiết tới liên phân số tuần hoàn là [số vô tỉ bậc hai (thực)](./quadratic.md) (quadratic irrational), tức nghiệm vô tỉ của phương trình bậc hai với hệ số nguyên. Mọi số vô tỉ bậc hai đều có thể biểu diễn dưới dạng

$$
a+b\sqrt D
$$

trong đó $a,b$ là các số hữu tỉ và $D$ là số nguyên dương không chứa thừa số bình phương. Các số vô tỉ bậc hai được nhắc tới trong bài này mặc định là số thực. Ngoài ra, liên hợp của $a+b\sqrt D$ là $a-b\sqrt{D}$.

Kết quả của Euler cho thấy mọi liên phân số tuần hoàn đều là số vô tỉ bậc hai.

???+ note "Định lý (Euler)"
    Mọi liên phân số tuần hoàn đều biểu diễn số vô tỉ bậc hai.

??? note "Chứng minh"
    Với liên phân số tuần hoàn tổng quát $x=[a_0,\cdots,a_{k-1},\overline{a_k,\cdots,a_{k+L-1}}]$, đặt $y=[\overline{a_k,\cdots,a_{k+L-1}}]$. Khi đó
    
    $$
    \begin{aligned}
    x&=[a_0,\cdots,a_{k-1},y] = L_0(y),\\
    y&=[a_k,\cdots,a_{k+L-1},y] = L_1(y),
    \end{aligned}
    $$
    
    trong đó $L_0(\cdot)$ và $L_1(\cdot)$ đều là biến đổi tuyến tính phân thức. Do đó, ta thu được phương trình mà $x$ thỏa mãn:
    
    $$
    x = L_0\circ L_1\circ L_0^{-1}(x). 
    $$
    
    Giả sử biến đổi tuyến tính phân thức $L_0\circ L_1\circ L_0^{-1}(x) = \dfrac{ax+b}{cx+d}$. Khi đó phương trình mà $x$ thỏa mãn là
    
    $$
    cx^2+(d-a)x-b=0.
    $$
    
    Vì vậy, liên phân số tuần hoàn đều là nghiệm của phương trình bậc hai với hệ số nguyên. Lại do liên phân số vô hạn đều là số vô tỉ, nên liên phân số tuần hoàn đều biểu diễn số vô tỉ bậc hai.

Kết quả của Lagrange cho thấy chiều ngược lại cũng đúng, nên số vô tỉ bậc hai và liên phân số tuần hoàn là hai khái niệm tương đương.

???+ note "Định lý (Lagrange)"
    Số vô tỉ bậc hai có thể biểu diễn thành liên phân số tuần hoàn.

??? note "Chứng minh"
    Ý tưởng là chứng minh các phần dư sẽ lặp lại. Giả sử số vô tỉ bậc hai $x$ có thể viết thành
    
    $$
    x = \dfrac{P_0+\sqrt{D}}{Q_0}
    $$
    
    trong đó $P_0,Q_0,D$ đều là số nguyên và $Q_0\mid D-P_0^2$. Điều này luôn có thể làm được; chẳng hạn, một số vô tỉ bậc hai $x$ luôn có thể viết thành
    
    $$
    a+b\sqrt{D'} = \dfrac{p_a}{q_a}+\dfrac{p_b}{q_b}\sqrt{D'} = \dfrac{p_aq_b+p_bq_a\sqrt{D'}}{q_aq_b} = \dfrac{p_ap_bq_aq_b+\sqrt{(q_aq_b)^2D'}}{(q_aq_b)^2}
    $$
    
    rồi đặt $P=p_ap_bq_aq_b$, $Q=(q_aq_b)^2$ và $D=QD'$.
    
    Lợi ích của cách viết này là có thể chứng minh mọi phần dư của nó đều có dạng tương tự:
    
    $$
    r_k=\dfrac{P_k+\sqrt D}{Q_k},
    $$
    
    trong đó $P_k,Q_k$ là các số nguyên và $Q_k\mid D-P_k^2$. Điều kiện $Q_k\mid D-P_k^2$ bảo đảm hệ số đứng trước $\sqrt{D}$ trong tử số của mọi phần dư đều bằng $1$.
    
    Để thu được dạng của phần dư, có thể dùng quy nạp toán học. Với $k=0$ thì hiển nhiên. Giả sử đã có dạng của $r_k$, và đặt $a_k=\lfloor r_k\rfloor$, ta có
    
    $$
    r_k = a_k+\dfrac{1}{r_{k+1}}.
    $$
    
    Giả sử $r_{k+1}$ cũng có dạng tương tự, rồi thay cùng với $r_k$ vào công thức trên, ta được
    
    $$
    \dfrac{P_k+\sqrt D}{Q_k} = a_k + \dfrac{Q_{k+1}}{P_{k+1}+\sqrt{D}} = a_k + \dfrac{Q_{k+1}P_{k+1}-Q_{k+1}\sqrt{D}}{P_{k+1}^2-D}.
    $$
    
    Vì cách biểu diễn một số vô tỉ bậc hai dưới dạng $a+b\sqrt{D}$ là duy nhất, so sánh hệ số hai vế ta được
    
    $$
    \dfrac{P_k}{Q_k} = a_k+\dfrac{Q_{k+1}P_{k+1}}{P_{k+1}^2-D},\ \dfrac{1}{Q_k}=-\dfrac{Q_{k+1}}{P_{k+1}^2-D}.
    $$
    
    Thay đẳng thức thứ hai vào đẳng thức thứ nhất, ta giải được $P_{k+1}$:
    
    $$
    \dfrac{P_k}{Q_k} = a_k-\dfrac{P_{k+1}}{Q_k} \iff P_{k+1} = a_kQ_k-P_k.
    $$
    
    Thay tiếp vào đẳng thức thứ hai, ta giải được $Q_{k+1}$:
    
    $$
    Q_{k+1} = \dfrac{D-P_{k+1}^2}{Q_k} = \dfrac{D-(a_kQ_k-P_k)^2}{Q_k} = -a_k^2Q_k+2a_kP_k+\dfrac{D-P_k^2}{Q_k}.
    $$
    
    Theo giả thiết quy nạp, $Q_k\mid D-P_k^2$, nên đúng là $P_{k+1}$ và $Q_{k+1}$ đều là số nguyên; tức $r_{k+1}$ cũng có dạng yêu cầu.
    
    Cuối cùng, chứng minh phần dư chỉ có thể nhận hữu hạn giá trị, nên chắc chắn lặp lại. Ở trên đã tính được phần dư
    
    $$
    \dfrac{P_k+\sqrt{D}}{Q_k} = r_k = -\dfrac{q_{k-2}x-p_{k-2}}{q_{k-1}x-p_{k-1}}
    $$
    
    Hơn nữa, với số vô tỉ luôn có $r_k>1$. Đồng thời, liên hợp của nó là
    
    $$
    \dfrac{P_k-\sqrt{D}}{Q_k} = r_k^* = -\dfrac{q_{k-2}x^*-p_{k-2}}{q_{k-1}x^*-p_{k-1}} = -\dfrac{q_{k-2}}{q_{k-1}}\dfrac{x^*-\dfrac{p_{k-2}}{q_{k-2}}}{x^*-\dfrac{p_{k-1}}{q_{k-1}}}
    $$
    
    chắc chắn nhỏ hơn $0$ với $k$ đủ lớn, vì
    
    $$
    \dfrac{q_{k-2}}{q_{k-1}}>0,\ \lim_{k\rightarrow\infty}\dfrac{x^*-\dfrac{p_{k-2}}{q_{k-2}}}{x^*-\dfrac{p_{k-1}}{q_{k-1}}}=\dfrac{x^*-x}{x^*-x}=1.
    $$
    
    Điều này cho thấy
    
    $$
    \dfrac{2\sqrt{D}}{Q_k} = r_k-r_k^*>1 \iff 0<Q_k\le 2\sqrt{D}.
    $$
    
    Do đó, $Q_k$ chỉ có thể nhận hữu hạn giá trị. Hơn nữa,
    
    $$
    D-P_{k}^2=Q_kQ_{k-1}>0 \iff |P_k|<\sqrt{D},
    $$
    
    nên $P_k$ cũng chỉ có thể nhận hữu hạn giá trị. Vì vậy, phần dư $r_k$ chỉ có hữu hạn giá trị khả dĩ, nên chắc chắn lặp lại trong dãy vô hạn.

Chứng minh định lý cũng cung cấp công thức truy hồi để tính phần dư của số vô tỉ bậc hai:

???+ note "Công thức truy hồi phần dư của số vô tỉ bậc hai"
    Số vô tỉ bậc hai luôn có thể biểu diễn thành
    
    $$
    x=\dfrac{P_0+\sqrt{D}}{Q_0}
    $$
    
    với $Q_0\mid D-P^2_0$. Phần dư của nó
    
    $$
    r_{k}=\dfrac{P_k+\sqrt{D}}{Q_k}
    $$
    
    có $P_k,Q_k$ đều là số nguyên, và thỏa mãn quan hệ truy hồi
    
    $$
    \begin{aligned}
    P_{k+1} &= a_kQ_k-P_k,\\
    Q_{k+1} &= \dfrac{D-P_{k+1}^2}{Q_k}.
    \end{aligned}
    $$

Công thức truy hồi này có thể dùng trực tiếp để tính liên phân số của số vô tỉ bậc hai. Hơn nữa, theo chứng minh định lý, $|P_k|<\sqrt{D}$ và $Q_k\le 2\sqrt{D}$. Độ phức tạp của thuật toán phụ thuộc vào độ dài khối tuần hoàn, và có thể chứng minh độ dài này là $O(\sqrt{D}\log D)$.[^period-surd]

???+ example "Số vô tỉ bậc hai"
    Cho số vô tỉ bậc hai $\alpha=\dfrac{x+y\sqrt{n}}{z}$, hãy tìm biểu diễn liên phân số của nó. Trong đó $x,y,z,n\in\mathbf Z$ và $n>0$ không phải số chính phương.

??? note "Lời giải"
    Trước hết biểu diễn số vô tỉ bậc hai thành dạng trên, rồi dùng công thức truy hồi để tính. Các hạng của liên phân số được cho bởi $a_k=\lfloor r_k\rfloor$. Để tìm khối tuần hoàn, cần lưu chỉ số xuất hiện đầu tiên của mỗi $(P_k,Q_k)$.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/quadratic-irrational.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/quadratic-irrational.py:core"
        ```

???+ example "[Tavrida NU Akai Contest - Continued Fraction](https://timus.online/problem.aspx?space=1&num=1814)"
    Cho $x$ và $k$, trong đó $x$ không phải số chính phương, $0\le k\le 10^9$. Hãy tìm phân số tiệm cận thứ $k$ là $x_k$ của $\sqrt{x}$.

??? note "Lời giải"
    Trước hết dùng thuật toán trên để tìm chu kỳ của $\sqrt{x}$. Biểu diễn khối tuần hoàn thành biến đổi tuyến tính phân thức, rồi dùng [lũy thừa nhanh](../binary-exponentiation.md) để thu được giá trị $x_k$. Dĩ nhiên, phần chưa đi vào chu kỳ và phần chưa đủ một chu kỳ cần được xử lý riêng.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/surd-convergent.cpp"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/surd-convergent.py"
        ```

<span id="liên-phân-số-thuần-tuần-hoàn"></span>

### Liên phân số thuần tuần hoàn

Số vô tỉ bậc hai là điều kiện cần và đủ để có biểu diễn liên phân số tuần hoàn; phần này tiếp tục đưa ra điều kiện cần và đủ để một số thực có biểu diễn liên phân số thuần tuần hoàn.

Trước hết, vì liên phân số thuần tuần hoàn có dạng tương tự liên phân số hữu hạn, ta có thể thực hiện thao tác "đảo thứ tự". Tương tự định lý đảo thứ tự, biểu diễn liên phân số thu được theo cách này có quan hệ xác định với biểu diễn liên phân số ban đầu.

???+ note "Định lý (Galois)"
    Với liên phân số thuần tuần hoàn
    
    $$
    x = \left[\overline{a_0,a_1,\cdots,a_{\ell}}\right],
    $$
    
    ký hiệu
    
    $$
    x' = \left[\overline{a_{\ell},\cdots,a_1,a_0}\right].
    $$
    
    Khi đó $x$ và $x'$ là "liên hợp nghịch đảo âm" của nhau, tức số đối của nghịch đảo của liên hợp của $x$ là $x'$.

??? note "Chứng minh"
    Vì không yêu cầu $\ell+1$ là chu kỳ dương nhỏ nhất, có thể giả sử $\ell>0$. Theo định lý đảo thứ tự,
    
    $$
    \begin{aligned}
    \dfrac{p_\ell}{p_{\ell-1}} &= [a_\ell,\cdots,a_1,a_0] = \dfrac{p'_\ell}{q'_\ell},\\
    \dfrac{q_\ell}{q_{\ell-1}} &= [a_\ell,\cdots,a_1] = \dfrac{p'_{\ell-1}}{q'_{\ell-1}}.
    \end{aligned}
    $$
    
    Vì hai vế của các đẳng thức đều là phân số tối giản, nên
    
    $$
    p'_\ell = p_\ell,\ q'_\ell = p_{\ell-1},\ p'_{\ell-1}=q_\ell,\ q'_{\ell-1} = q_{\ell-1}.
    $$
    
    Với liên phân số thuần tuần hoàn $x$, phần dư thứ $\ell+1$ của nó chính là $x$, do đó
    
    $$
    x = \dfrac{xp_\ell+p_{\ell-1}}{xq_\ell+q_{\ell-1}}.
    $$
    
    Vì vậy, nó thỏa mãn phương trình bậc hai
    
    $$
    q_\ell x^2+(q_{\ell-1}-p_\ell)x-p_{\ell-1} = 0.
    $$
    
    Tương tự, $x'$ thỏa mãn phương trình bậc hai
    
    $$
    q'_\ell(x')^2+(q'_{\ell-1}-p'_\ell)x'-p'_{\ell-1} = 0.
    $$
    
    Dùng quan hệ giữa các hệ số, phương trình này có thể viết thành
    
    $$
    p_{\ell-1}(x')^2+(q_{\ell-1}-p_\ell)x'-q_\ell = 0.
    $$
    
    Đặt $y=-\dfrac{1}{x'}$, khi đó $x$ và $y$ thỏa mãn cùng một phương trình. Nhưng $x>0>y$, nên chúng không phải cùng một nghiệm, mà là hai nghiệm liên hợp. Điều này chứng minh mệnh đề.

Từ quan sát này, Galois tiếp tục đưa ra điều kiện cần và đủ để một số vô tỉ bậc hai có biểu diễn liên phân số thuần tuần hoàn.

???+ note "Định lý (Galois)"
    Số vô tỉ bậc hai $x$ có thể biểu diễn thành liên phân số thuần tuần hoàn khi và chỉ khi $x>1$ và liên hợp của nó thỏa mãn $-1<x^*<0$.

??? note "Chứng minh"
    Nếu $x$ là liên phân số thuần tuần hoàn, theo ký hiệu ở trên, $a_0=a_{\ell+1}\ge 1$, nên $x>1$. Lại vì liên hợp nghịch đảo âm của nó cũng là liên phân số tuần hoàn, nên liên hợp $x^*$ của nó thỏa mãn $-\dfrac{1}{x^*}>1$, tức $-1<x^*<0$. Điều này chứng minh mọi liên phân số thuần tuần hoàn đều thỏa mãn điều kiện.
    
    Ngược lại, giả sử số vô tỉ bậc hai $x>1$ và $-1<x^*<0$. Với phần dư $r_k$ của $x$, có quan hệ truy hồi
    
    $$
    r_k = a_k+\dfrac{1}{r_{k+1}}.
    $$
    
    Hai vế đều là số vô tỉ bậc hai; lấy liên hợp, ta được
    
    $$
    r_{k}^* = a_k+\dfrac{1}{r_{k+1}^*}.
    $$
    
    Dùng quan hệ truy hồi này, có thể chứng minh $-1<r_{k}^*<0$ với mọi $k\ge 0$.
    
    Trước hết, với $k=0$, hiển nhiên $-1<r_0^*=x_0^*<0$. Với $k\ge 0$, theo định nghĩa liên phân số đơn giản và $x>1$, ta có $a_k\ge 1$. Do đó, giả sử $-1<r_k^*<0$, thì
    
    $$
    -1<-\dfrac{1}{a_k}< r_{k+1}^* = \dfrac{1}{r_k^*-a_k} < -\dfrac{1}{1+a_k} < 0.
    $$
    
    Điều này chứng minh bằng quy nạp rằng $-1<r_{k}^*<0$ với mọi $k\ge 0$. Vì vậy,
    
    $$
    a_k = -\dfrac{1}{r_{k+1}^*}+r_k^* = \left\lfloor-\dfrac{1}{r_{k+1}^*}\right\rfloor.
    $$
    
    Vì số vô tỉ bậc hai chắc chắn là liên phân số tuần hoàn, tồn tại số nguyên dương $L$ và ít nhất một $k$ đủ lớn sao cho $r_{k}=r_{k+L}$. Nhưng khi đó chắc chắn cũng có
    
    $$
    a_{k-1} = \left\lfloor-\dfrac{1}{r_{k}^*}\right\rfloor = \left\lfloor-\dfrac{1}{r_{k+L}^*}\right\rfloor = a_{k+L-1}.
    $$
    
    Do đó,
    
    $$
    r_{k-1} = a_{k-1}+\dfrac{1}{r_k} = a_{k+L-1}+\dfrac{1}{r_{k+L}} = r_{k+L-1}.
    $$
    
    Điều này nghĩa là $k$ nhỏ nhất để $r_{k}=r_{k+L}$ có thể xảy ra chắc chắn là $0$. Nói cách khác, $x$ có thể biểu diễn thành liên phân số thuần tuần hoàn.

Định lý Galois cho thấy quy luật biểu diễn liên phân số của căn thức bậc hai thuần (pure quadratic surd), tức số vô tỉ bậc hai có dạng $\sqrt{r}$.

???+ note "Hệ quả"
    Với số hữu tỉ $r>1$, nếu $\sqrt{r}$ là số vô tỉ, thì
    
    $$
    \sqrt{r} = [\lfloor\sqrt{r}\rfloor,\overline{a_1,\cdots,a_{\ell},2\lfloor\sqrt{r}\rfloor}]
    $$
    
    và với mọi $1\le k\le\ell$, ta có $a_k = a_{\ell+1-k}$.

??? note "Chứng minh"
    Với số vô tỉ bậc hai $\sqrt{r}$, vì $\lfloor\sqrt{r}\rfloor+\sqrt{r}>1$ và $-1<\lfloor\sqrt{r}\rfloor-\sqrt{r}<0$, nên $\lfloor\sqrt{r}\rfloor+\sqrt{r}$ là liên phân số thuần tuần hoàn:
    
    $$
    \lfloor\sqrt{r}\rfloor+\sqrt{r} = [\overline{2\lfloor\sqrt{r}\rfloor,a_1,\cdots,a_\ell}].
    $$
    
    Theo định lý trên, liên hợp nghịch đảo âm của nó có dạng
    
    $$
    \dfrac{1}{\sqrt{r}-\lfloor\sqrt{r}\rfloor} = [\overline{a_\ell,\cdots,a_1,2\lfloor\sqrt{r}\rfloor}].
    $$
    
    Dùng các tính chất cơ bản của liên phân số, ta có
    
    $$
    \sqrt{r}=\lfloor\sqrt{r}\rfloor+\dfrac{1}{\dfrac{1}{\sqrt{r}-\lfloor\sqrt{r}\rfloor}}=[\lfloor\sqrt{r}\rfloor,\overline{a_\ell,\cdots,a_1,2\lfloor\sqrt{r}\rfloor}].
    $$
    
    Mặt khác, từ biểu diễn liên phân số của $\lfloor\sqrt{r}\rfloor+\sqrt{r}$,
    
    $$
    \sqrt{r} = -\lfloor\sqrt{r}\rfloor+\left(\lfloor\sqrt{r}\rfloor+\sqrt{r}\right) = [\lfloor\sqrt{r}\rfloor,\overline{a_1,\cdots,a_\ell,2\lfloor\sqrt{r}\rfloor}].
    $$
    
    Vì biểu diễn liên phân số của số vô tỉ là duy nhất, so sánh các hệ số ở giữa cho thấy $a_k=a_{\ell+1-k}$ với mọi $1\le k\le\ell$.

??? example "Ví dụ: khai triển liên phân số của $\sqrt{74}$"
    Liên phân số của $\sqrt{74}$ có thể tính như sau: (ở đây chỉ nhằm minh họa; khi lập trình nên dùng thuật toán truy hồi đã nêu ở trên)
    
    $$
    \begin{aligned}
    \sqrt{74}&=8+(-8)+\sqrt{74}=\left[8,\frac{8+\sqrt{74}}{10}\right]\\
    &=\left[8,1+\frac{-2+\sqrt{74}}{10}\right]=\left[8,1,\frac{2+\sqrt{74}}{7}\right]\\
    &=\left[8,1,1+\frac{-5+\sqrt{74}}{7}\right]=\left[8,1,1,\frac{5+\sqrt{74}}{7}\right]\\
    &=\left[8,1,1,1+\frac{-2+\sqrt{74}}{7}\right]=\left[8,1,1,1,\frac{2+\sqrt{74}}{10}\right]\\
    &=\left[8,1,1,1,1+\frac{-8+\sqrt{74}}{10}\right]=\left[8,1,1,1,1,8+\sqrt{74}\right]\\
    &=\left[8,1,1,1,1,16+(-8)+\sqrt{74}\right]=\left[8,\overline{1,1,1,1,16}\right]
    \end{aligned}
    $$
    
    Các phần dư lần lượt là:
    
    $$
    \begin{alignedat}{3}
    r_1&=\frac{8+\sqrt{74}}{10}&&=\left[\overline{1,1,1,1,16}\right]\\
    r_2&=\frac{2+\sqrt{74}}{7}&&=\left[\overline{1,1,1,16,1}\right]\\
    r_3&=\frac{5+\sqrt{74}}{7}&&=\left[\overline{1,1,16,1,1}\right]\\
    r_4&=\frac{2+\sqrt{74}}{10}&&=\left[\overline{1,16,1,1,1}\right]\\
    r_5&=8+\sqrt{74}&&=\left[\overline{16,1,1,1,1}\right]
    \end{alignedat}
    $$
    
    Theo kết luận của Galois, phần tuần hoàn của hai phần dư $r_k$ và $r_{L+1-k}$ đúng là ngược nhau, nên chúng là liên hợp nghịch đảo âm của nhau. Nếu độ dài khối tuần hoàn $L$ của $\sqrt{D}$ là lẻ, thì hạng ở giữa sẽ là liên hợp nghịch đảo âm của chính nó; nếu độ dài khối tuần hoàn $L$ là chẵn thì không có hạng như vậy. Phần về phương trình Pell sẽ cho thấy tính chẵn lẻ của độ dài khối tuần hoàn quyết định phương trình $x^2-Dy^2=-1$ có nghiệm hay không.

Khai triển liên phân số của số vô tỉ bậc hai $\sqrt{D}$ chủ yếu được dùng để giải [phương trình Pell](./pell-equation.md).

<span id="bài-tập-ví-dụ"></span>

## Bài tập ví dụ

Sau khi nắm được các khái niệm cơ bản, cần xét một số ví dụ cụ thể để hiểu cách áp dụng phương pháp liên phân số trong lập trình thi đấu.

???+ example "Bao lồi dưới đường thẳng"
    Cho $r=[a_0,a_1,\cdots,a_n]$, hãy tìm bao lồi của tập điểm nguyên $(x,y)$ thỏa mãn $0\le x\le N$ và $0\le y\le rx$.

??? note "Lời giải"
    Với tập không bị chặn $x\ge 0$, bao lồi trên chính là đường thẳng $y=rx$. Tuy nhiên, như hình dưới đây, nếu còn yêu cầu $x\le N$, thì bao lồi trên cuối cùng sẽ lệch khỏi đường thẳng.
    
    ![](./images/lattice-hull.svg)
    
    Bắt đầu từ $(0,0)$, có thể tìm tất cả điểm nguyên trên bao lồi trên từ trái sang phải. Giả sử điểm nguyên cuối cùng trên bao lồi trên đã tìm được là $(x,y)$. Ta cần tìm điểm nguyên tiếp theo $(x',y')$. Đỉnh $(x',y')$ nằm phía trên bên phải $(x,y)$; ký hiệu $(\Delta x,\Delta y)=(x'-x,y'-y)$ là hiệu giữa hai điểm. Khi đó chắc chắn
    
    $$
    0<\Delta x\le N-x,\ 0\le \Delta y\le r\Delta x.
    $$
    
    Bất đẳng thức thứ hai đúng vì điều kiện $\Delta y>r\Delta x$ mâu thuẫn với việc $(x,y)$ đã nằm trên bao lồi trên. Quan sát các điều kiện mà $(\Delta x,\Delta y)$ cần thỏa mãn: với các điểm $(x,y)$ khác nhau, chỉ cận trên của $\Delta x$ thay đổi. Vì vậy, chỉ cần giải được bài toán con này là có thể tìm đệ quy mọi điểm nguyên của bài toán ban đầu.
    
    Tiếp theo xét cách giải bài toán con. So với bài toán ban đầu, bài toán con tương đương với việc đổi cận trên của $x$ thành $N'$, rồi tìm điểm nguyên đầu tiên trên bao lồi trên kề với gốc tọa độ. Gọi nghiệm của bài toán con là $(q,p)$. Khi đó $p$ và $q$ chắc chắn nguyên tố cùng nhau (nếu không thì đó không phải điểm nguyên đầu tiên), và hệ số góc $\dfrac{p}{q}$ của đường nối với gốc tọa độ là lớn nhất trong các điểm nguyên nằm dưới đường thẳng $y=rx$ và có hoành độ không vượt quá $N'$ (nếu không thì điểm đó không nằm trên bao lồi). Kết hợp với [diễn giải hình học](#diễn-giải-hình-học) ở trên, điểm $(x,y)$ như vậy chắc chắn tương ứng với một phân số trung gian dưới của $r$. Vì phân số trung gian dưới có mẫu càng lớn thì càng gần $r$, nên nghiệm $(q,p)$ của bài toán con tương ứng với phân số trung gian dưới có mẫu lớn nhất trong tất cả các phân số trung gian dưới có mẫu không vượt quá $N'$.
    
    Dĩ nhiên, khi giải thực tế, không cần tìm lại phân số trung gian dưới như vậy cho từng bài toán con. Nên tìm tất cả phân số tiệm cận trước; điều này tương đương với việc có cách duyệt tất cả phân số trung gian dưới. Sau đó duyệt các phân số trung gian dưới theo mẫu giảm dần, mỗi lần thử cộng nó vào điểm nguyên trước đó $(x,y)$, cho tới khi không thể cộng nữa thì mới thử phân số trung gian dưới tiếp theo.
    
    Có một số tối ưu hiển nhiên. Trước hết, với phân số trung gian dưới $(q,p)$, chắc chắn tồn tại $k$ lẻ và $0\le t<a_k$ sao cho $(q,p)=(q_{k-1},p_{k-1})+t(q_k,p_k)$. Chỉ cần tìm $t$ lớn nhất thỏa mãn $q_{k-1}+tq_k+x\le N$, tức $t=\left\lfloor\dfrac{N-q_{k-1}-x}{q_k}\right\rfloor$. Không cần lo $t$ vượt giới hạn, vì phân số tiệm cận dưới lớn hơn $(q_{k+2},p_{k+2})$ đã được cộng xong. Mỗi lần xác định số lần cộng, chỉ cần tính trực tiếp $\left\lfloor\dfrac{N-x}{q}\right\rfloor$, không cần thử từng lần.
    
    Độ phức tạp của thuật toán sau tối ưu là $O(n)$. Dù có thể có nhiều điểm nguyên tương ứng với các phân số trung gian dưới, số điểm thật sự trở thành gia lượng không nhiều. Ta sẽ chỉ ra rằng trong tất cả phân số trung gian dưới $(q,p)=(q_{k-1},p_{k-1})+t(q_k,p_k)$ với $0\le t<a_k$, nhiều nhất chỉ có hai gia lượng xuất hiện. Giả sử trong các phân số trung gian dưới này thật sự có gia lượng, khi đó chắc chắn $q_{k-1}\le N-x<q_{k+1}$. Đặt $t=\left\lfloor\dfrac{N-q_{k-1}-x}{q_k}\right\rfloor$. Nếu $t=0$, gia lượng có $\Delta x=q_{k-1}$; sau khi cộng gia lượng, ta có $N-x'<q_{k-1}$, nên sẽ không xuất hiện gia lượng mới trong các phân số trung gian dưới này. Nếu $t>0$, sau khi cộng gia lượng, chắc chắn $N-x'=(N-q_{k-1}-x)\bmod q_k<q_k$; ngay cả nếu cùng đoạn phân số trung gian dưới này còn xuất hiện gia lượng mới, lần sau cũng chỉ có thể có $t'=0$. Vì vậy, trong một đoạn phân số trung gian dưới như vậy, nhiều nhất chỉ có hai gia lượng. Điều này chứng minh độ phức tạp tổng thể là $O(n)$.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/hull-under-line.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/hull-under-line.py:core"
        ```

???+ example "[Timus - Crime and Punishment](https://timus.online/problem.aspx?space=1&num=1430)"
    Cho các số nguyên dương $A,B,N \le 2\times 10^9$, tìm $x,y\ge 0$ sao cho $Ax+By\le N$ và $Ax+By$ lớn nhất có thể.

??? note "Lời giải"
    Bài toán này có lời giải độ phức tạp $O(\sqrt N)$: giả sử $A\ge B$, vì $A(B+x)+By=Ax+B(A+y)$, nên chỉ cần tìm đáp án trong miền $x\le\min\{N/A, B\}$. Điều này đủ để qua bài. Tuy nhiên, nếu áp dụng phương pháp liên phân số, độ phức tạp có thể giảm xuống $O(\log N)$.
    
    Để tiện thảo luận, trước hết đổi dấu của $x$ bằng phép thế $x\mapsto\left\lfloor N/A\right\rfloor-x$. Đặt $C=N\bmod A$ và $M=\left\lfloor N/A\right\rfloor$, bài toán ban đầu chuyển thành: trong điều kiện $0\le x\le M$ và $By-Ax\le C$, tìm $(x,y)$ tối ưu sao cho $By-Ax$ lớn nhất. Với mỗi $x$ cố định, giá trị tối ưu của $y$ là $\left\lfloor\dfrac{Ax+C}{B}\right\rfloor$.
    
    Tiếp theo, bài toán này có cách giải tương tự ví dụ trước. Tuy nhiên, khác với ví dụ trước dùng phân số trung gian dưới để rời khỏi đường thẳng, bài này cần dùng phân số trung gian trên để tiến gần đường thẳng. Cụ thể, giá trị $C-(By-Ax)$ tỉ lệ với khoảng cách từ điểm $(x,y)$ tới đường thẳng $By-Ax=C$. Tối đa hóa $By-Ax$ tương đương với tối thiểu hóa khoảng cách này. Mục tiêu của thuật toán là tìm điểm nguyên khả thi nằm dưới đường thẳng $By-Ax=C$ và gần đường thẳng nhất. Ý tưởng thuật toán là bắt đầu từ điểm bên trái nhất, tìm kiếm dọc bao lồi trên của các điểm nguyên này, từng bước giảm khoảng cách tới đường thẳng cho tới khi thu được nghiệm tối ưu.
    
    Trong hệ tọa độ $(x,y)$, thuật toán bắt đầu từ $(0,\lfloor C/B\rfloor)$, đệ quy tìm và cộng gia lượng tối ưu $(\Delta x,\Delta y)$, đồng thời bảo đảm điểm sau khi cộng gần đường thẳng $By-Ax=C$ hơn trước, nhưng không đi sang phía bên kia của đường thẳng và cũng không để hoành độ vượt quá $M$. Giả sử điểm đã thu được là $(x,y)$, thì gia lượng $(\Delta x,\Delta y)$ cần thỏa mãn
    
    $$
    0<B\Delta y-A\Delta x\le C-(By-Ax),\ 0<\Delta x\le M-x.
    $$
    
    Theo ý tưởng tìm dọc bao lồi dưới, chỉ cần tìm điểm có $\Delta x$ nhỏ nhất trong các điểm thỏa mãn các điều kiện này. Viết lại bất đẳng thức đầu tiên thành
    
    $$
    \Delta y \le \dfrac{A}{B}\Delta x+\dfrac{C-(By-Ax)}{B}.
    $$
    
    Kết hợp với [diễn giải hình học](#diễn-giải-hình-học) ở trên, chỉ cần hằng số phía sau nhỏ hơn $1$, thì trong các điểm nguyên $(\Delta x,\Delta y)$ thỏa mãn bất đẳng thức này, điểm có hoành độ nhỏ nhất chắc chắn tương ứng với một phân số trung gian trên. Lý do là nó là phân số xấp xỉ một số thực từ phía trên tốt nhất trong tất cả các phân số có mẫu không vượt quá mẫu của nó, và điều đó chỉ có thể là phân số trung gian trên. Sau mỗi lần cộng gia lượng, cận trên của $\Delta y$ sẽ chặt hơn, nghĩa là phải xét các phân số trung gian trên có mẫu lớn hơn.
    
    Làm tương tự ví dụ trước. Xét tất cả phân số trung gian trên theo mẫu tăng dần; nếu tìm được phân số trung gian trên có cả hoành độ và tung độ không vượt giới hạn, thì cộng nó vào và cập nhật cận trên tương ứng. Khi đã cộng xong mọi phân số trung gian trên khả thi, ta thu được nghiệm tối ưu. So với trước, bài này cần đồng thời bảo đảm cả hoành độ và tung độ không vượt giới hạn, nên cần đặc biệt chú ý. Dựa trên lập luận tương tự ví dụ trước, nhưng lần này dùng $B\Delta y-A\Delta x$ thay cho $\Delta x$, có thể chỉ ra rằng độ phức tạp của thuật toán là $O(\log\min\{A,B\})$.
    
    === "C++"
        ```py
        --8<-- "docs/math/code/continued-fraction/closest-dio.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/closest-dio.py:core"
        ```

???+ example "[June Challenge 2017 - Euler Sum](https://www.codechef.com/problems/ES)"
    Tính giá trị $\sum\limits_{x=1}^N \lfloor \mathrm{e}x \rfloor$, trong đó $\mathrm{e}$ là cơ số của logarit tự nhiên.
    
    Gợi ý: $e = [2,1,2,1,1,4,1,1,6,1,\cdots,1,2n,1, \cdots]$.[^continued-fraction-of-e]

??? note "Lời giải"
    Tổng này bằng số điểm nguyên trong tập $\{(x,y):1\le x\le N,1\le y\le\mathrm{e}x\}$. Sau khi dựng bao lồi của các điểm nguyên dưới đường thẳng $y=\mathrm{e}x$, có thể dùng [định lý Pick](../../geometry/pick.md) để tính số điểm nguyên. Độ phức tạp là $O(\log N)$.
    
    Bài gốc yêu cầu $N \le 10^{4000}$. Mã C++ ở đây chỉ mang tính minh họa và không cài đặt lớp tính toán chính xác cao.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/sum-floor.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/sum-floor.py:core"
        ```

???+ example "[NAIPC 2019 - It's a Mod, Mod, Mod, Mod World](https://open.kattis.com/problems/itsamodmodmodmodworld)"
    Cho các số nguyên dương $p,q,n$, hãy tính giá trị $\sum\limits_{i=1}^n [pi \bmod q]$.

??? note "Lời giải"
    Vì tổng có thể biến đổi thành
    
    $$
    \sum_{i=1}^n [pi \bmod q] 
    =\sum_{i=1}^n\left(pi - q\left\lfloor\dfrac{pi}{q}\right\rfloor\right) = \dfrac{pn(n+1)}{2} - q\sum_{i=1}^n\left\lfloor\dfrac{p}{q}i\right\rfloor,
    $$
    
    Bài toán này có thể chuyển thành bài toán trước, chỉ cần thay $\mathrm{e}$ bằng $\dfrac{p}{q}$. Độ phức tạp cho một truy vấn là $O(\log\min\{p,q\})$.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/mod-mod-mod.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/mod-mod-mod.py:core"
        ```

???+ example "[Library Checker - Sum of Floor of Linear](https://judge.yosupo.jp/problem/sum_of_floor_of_linear)"
    Cho các số nguyên dương $N,M,A,B$, hãy tính giá trị $\displaystyle\sum_{i=0}^{N-1} \left\lfloor \frac{A \cdot i + B}{M} \right\rfloor$.

??? note "Lời giải"
    Đây là bài toán phức tạp nhất cho tới đây. Nó có thể được tính bằng [thuật toán kiểu Euclid](./euclidean.md). Ở đây đưa ra thuật toán dựa trên liên phân số, với độ phức tạp $O(\log\min\{A,B\})$.
    
    Có thể dựng bao lồi của toàn bộ điểm nguyên nằm dưới đường thẳng $y=\dfrac{Ax+B}{M}$ và thỏa mãn $0\le x< N$, rồi dùng định lý Pick để tính số điểm nguyên. Trường hợp $B=0$ đã được giải ở trước. Với trường hợp tổng quát, có thể chia thành hai bước. Trước hết, cộng các phân số trung gian trên để từng bước tiến gần đường thẳng (ví dụ thứ hai), cho tới khi tìm được điểm gần đường thẳng nhất; sau đó cộng các phân số trung gian dưới để từng bước rời xa đường thẳng (ví dụ thứ nhất).
    
    === "C++"
        ```py
        --8<-- "docs/math/code/continued-fraction/sum-floor-axbc.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/sum-floor-axbc.py:core"
        ```

???+ example "[OKC 2 - From Modular to Rational](https://codeforces.com/gym/102354/problem/I)"
    Có một số hữu tỉ chưa biết $\dfrac{p}{q}$ với $1\le p, q\le 10^9$. Ta có thể hỏi giá trị của $pq^{-1}$ modulo một số nguyên tố $m\in[10^9,10^{12}]$. Hãy xác định $p$ và $q$ trong không quá mười lần hỏi.
    
    Bài toán này tương đương với việc tìm $x$ trong $[1,N]$ sao cho $Ax\bmod M$ nhỏ nhất.

??? note "Lời giải"
    Theo [định lý phần dư Trung Hoa](./crt.md), hỏi kết quả modulo nhiều số nguyên tố tương đương với hỏi kết quả modulo tích của các số nguyên tố đó. Vì vậy, bài này có thể xem là hỏi kết quả của phân số modulo một môđun đủ lớn $m$, rồi yêu cầu xác định tử số và mẫu số của phân số.
    
    Với một môđun $m$, cặp $(p,q)$ làm cho $qr\equiv p\pmod m$ đúng có thể không duy nhất. Giả sử $(p_1,q_1)$ và $(p_2,q_2)$ đều làm đẳng thức này đúng, thì chắc chắn $(p_1q_2-p_2q_1)r\equiv 0\pmod m$. Theo cách dựng $r$, $r$ nguyên tố cùng nhau với $m$, nên $p_1q_2-p_2q_1\equiv 0\pmod m$, tức $m\mid(p_1q_2-p_2q_1)$. Nếu $p_1q_2-p_2q_1$ khác không, giá trị tuyệt đối của nó ít nhất là $m$. Bài toán giới hạn $p,q\in[1,10^9]$, nghĩa là hiệu này không nên vượt quá $10^{18}$; vì vậy chỉ cần lấy $m>10^{18}$ là có thể bảo đảm $(p,q)$ tìm được là duy nhất.
    
    Bây giờ bài toán quy về: cho môđun $m$ và phần dư $r$, tìm cặp số nguyên dương $(p,q)$ không vượt quá $n$ sao cho $qr\equiv p\pmod m$. Khi đã biết nghiệm như vậy là duy nhất, thật ra chỉ cần tìm $q\in[1,n]$ làm cho $qr\bmod m$ nhỏ nhất, vì khi đó có đúng một $q$ khiến phần dư không vượt quá $n$. Đây chính là phát biểu tương đương đã nêu ở trên.
    
    Trong hệ tọa độ phẳng $(q,k)$, điều này tương đương với việc tìm điểm nguyên với $q\in[1,n]$ nằm dưới đường thẳng $qr-km=0$ và gần nó nhất, vì phần dư $qr\bmod m$ tỉ lệ với khoảng cách từ điểm nguyên tới đường thẳng. Kết hợp với [diễn giải hình học](#diễn-giải-hình-học) ở trên, điểm nguyên như vậy chắc chắn tương ứng với một phân số trung gian dưới của phân số hữu tỉ $\dfrac{r}{m}$. Độ phức tạp thuật toán là $O(\log\min\{r,m\})$.
    
    === "C++"
        ```cpp
        --8<-- "docs/math/code/continued-fraction/recover-fraction.cpp:core"
        ```
    
    === "Python"
        ```py
        --8<-- "docs/math/code/continued-fraction/recover-fraction.py:core"
        ```

<span id="bài-tập"></span>

## Bài tập

-   [UVa OJ - Continued Fractions](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=775)
-   [ProjectEuler+ #64: Odd period square roots](https://www.hackerrank.com/contests/projecteuler/challenges/euler064/problem)
-   [LibreOJ NOI Round #2 - Một mình một ngựa](https://loj.ac/p/573)
-   [Codeforces Round #184 (Div. 2) - Continued Fractions](https://codeforces.com/contest/305/problem/B)
-   [Codeforces Round #201 (Div. 1) - Doodle Jump](https://codeforces.com/contest/346/problem/E)
-   [Codeforces Round #325 (Div. 1) - Alice, Bob, Oranges and Apples](https://codeforces.com/contest/585/problem/C)
-   [POJ Founder Monthly Contest 2008.03.16 - A Modular Arithmetic Challenge](http://poj.org/problem?id=3530)
-   [2019 Multi-University Training Contest 5 - fraction](http://acm.hdu.edu.cn/showproblem.php?pid=6624)
-   [SnackDown 2019 Elimination Round - Election Bait](https://www.codechef.com/SNCKEL19/problems/EBAIT)
-   [Luogu P5179. Fraction](https://www.luogu.com.cn/problem/P5179)
-   [Luogu P7739. \[NOI2021\] Hộp mật mã](https://www.luogu.com.cn/problem/P7739)

<span id="tài-liệu-tham-khảo-và-đọc-thêm"></span>

## Tài liệu tham khảo và đọc thêm

-   Hardy, G. H., Wright, E. M., Heath-Brown, R., & Silverman, J. (2008). An Introduction to the Theory of Numbers. Oxford Mathematics.
-   Zhu Yaochen, Wang Lianxiang, *Nhập môn xấp xỉ Diophantine*
-   [Blog của FatFish - Nhập môn liên phân số](https://chaoli.club/index.php/2756)
-   [Simple continued fraction - Wikipedia](https://en.wikipedia.org/wiki/Simple_continued_fraction)
-   [Periodic continued fraction - Wikipedia](https://en.wikipedia.org/wiki/Periodic_continued_fraction)
-   [Gosper's original notes on continued fraction arithmetic algorithms](https://perl.plover.com/yak/cftalk/INFO/gosper.txt)
-   [Understanding Bill Gosper's continued fraction arithmetic (implemented in Python)](https://hsinhaoyu.github.io/cont_frac/)

**Nội dung chính của trang này được dịch từ bài viết [Continued fractions](https://cp-algorithms.com/algebra/continued-fractions.html), có giấy phép CC-BY-SA 4.0 và đã được chỉnh sửa.**

[^one-representation]: Số tự nhiên $1$ chỉ có biểu diễn không chuẩn: $1=[1]=[0,1]$.

[^continuant]: Tên gọi này tham khảo bản dịch tiếng Trung chương 6.7 của *Concrete Mathematics* do Zhang Mingyao và Zhang Fan dịch.

[^sqrt5]: Ở đây không thể mặc định phân số tối giản $\dfrac{p}{q}$ chắc chắn là phân số tiệm cận, dù định lý Legendre cho thấy $\dfrac{p}{q}$ thật ra chỉ có thể là một phân số tiệm cận nào đó. Với trường hợp phân số tiệm cận, có thể chứng minh từ sai số khi phân số tiệm cận xấp xỉ số thực.

[^semi-range]: Các tài liệu khác nhau có thể xử lý khác nhau về việc miền giá trị của $t$ ở đây có bao gồm hai đầu mút hay không.

[^semiconvergent]: Khi $t=0$, nên hiểu đây là liên phân số hình thức, tương đương với việc cắt liên phân số ở hạng áp chót.

[^nose-streching]: Cách gọi này không phải thuật ngữ chuyên môn. Có thể nó được dịch gián tiếp từ tài liệu tiếng Nga [ЦЕПНЫЕ ДРОБИ](https://old.mccme.ru/free-books/mmmf-lectures/book.14-full.pdf), phần Алгоритм «вытягивания носов».

[^pgl2]: Các tính chất này cho thấy nhóm gồm toàn bộ các biến đổi tuyến tính phân thức đẳng cấu với [nhóm tuyến tính xạ ảnh](https://en.wikipedia.org/wiki/Projective_linear_group) $PGL_2(\mathbf R)$.

[^period-surd]: Chứng minh có thể xem trong các tài liệu tham khảo của [trang Wikipedia](https://en.wikipedia.org/wiki/Periodic_continued_fraction#Length_of_the_repeating_block).

[^continued-fraction-of-e]: Có thể tham khảo chứng minh khai triển liên phân số của cơ số logarit tự nhiên $\mathrm{e}$ tại [đây](https://proofwiki.org/wiki/Continued_Fraction_Expansion_of_Euler%27s_Number).
