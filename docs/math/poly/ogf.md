author: sshwy

Hàm sinh thường (ordinary generating function, OGF) của dãy $a$ được định nghĩa là chuỗi lũy thừa hình thức:

$$
F(x)=\sum_{n}a_n x^n
$$

$a$ có thể là dãy hữu hạn hoặc dãy vô hạn. Một vài ví dụ thường gặp (giả sử dãy $a$ bắt đầu từ chỉ số $0$):

1.  Hàm sinh thường của dãy $a=\langle 1,2,3\rangle$ là $1+2x+3x^2$.
2.  Hàm sinh thường của dãy $a=\langle 1,1,1,\cdots\rangle$ là $\sum_{n\ge 0}x^n$.
3.  Hàm sinh của dãy $a=\langle 1,2,4,8,16,\cdots\rangle$ là $\sum_{n\ge 0}2^nx^n$.
4.  Hàm sinh của dãy $a=\langle 1,3,5,7,9,\cdots\rangle$ là $\sum_{n\ge 0}(2n+1)x^n$.

Nói cách khác, nếu dãy $a$ có công thức tổng quát thì các hệ số của hàm sinh thường chính là công thức tổng quát đó.

<span id="&#x57fa;&#x672c;&#x8fd0;&#x7b97;"></span>
## Phép toán cơ bản

Xét hai dãy $a,b$ có hàm sinh thường lần lượt là $F(x),G(x)$. Khi đó

$$
F(x)\pm G(x)=\sum_n (a_n\pm b_n)x^n
$$

Vì vậy $F(x)\pm G(x)$ là hàm sinh thường của dãy $\langle a_n\pm b_n\rangle$.

Xét phép nhân, tức là tích chập:

$$
F(x)G(x)=\sum_n x^n \sum_{i=0}^na_ib_{n-i}
$$

Vì vậy $F(x)G(x)$ là hàm sinh thường của dãy $\langle \sum_{i=0}^n a_ib_{n-i} \rangle$.

<span id="&#x5c01;&#x95ed;&#x5f62;&#x5f0f;"></span>
## Dạng đóng

Khi sử dụng hàm sinh, ta không phải lúc nào cũng làm việc trực tiếp với dạng chuỗi lũy thừa hình thức; tùy lúc ta sẽ chuyển sang dạng đóng để rút gọn tốt hơn.

Ví dụ, hàm sinh thường của $\langle 1,1,1,\cdots\rangle$ là $F(x)=\sum_{n\ge 0}x^n$. Ta nhận thấy

$$
F(x)x+1=F(x)
$$

Giải phương trình này được

$$
F(x)=\frac{1}{1-x}
$$

Đây là dạng đóng của $\sum_{n\ge 0}x^n$.

Xét cấp số nhân $\langle 1,p,p^2,p^3,p^4,\cdots\rangle$ với hàm sinh $F(x)=\sum_{n\ge 0}p^nx^n$, ta có

$$
\begin{aligned}F(x)px+1 &=F(x)\\F(x) &=\frac{1}{1-px}\end{aligned}
$$

Dạng đóng và dạng khai triển của cấp số nhân là hai phép biến đổi rất thường dùng.

???+ note "Bài tập nhỏ"
    Hãy tìm hàm sinh thường của các dãy sau (cả dạng chuỗi lũy thừa hình thức và dạng đóng). Độ khó tăng dần.
    
    1.  $a=\langle 0,1,1,1,1,\cdots\rangle$.
    2.  $a=\langle 1,0,1,0,1,\cdots \rangle$.
    3.  $a=\langle 1,2,3,4,\cdots \rangle$.
    4.  $a_n=\binom{m}{n}$ ($m$ là hằng số, $n\ge 0$).
    5.  $a_n=\binom{m+n}{n}$ ($m$ là hằng số, $n\ge 0$).

??? note "Đáp án"
    Câu thứ nhất:
    
    $$
    F(x)=\sum_{n\ge 1}x^n=\dfrac{x}{1-x}
    $$
    
    Câu thứ hai:
    
    $$
    \begin{aligned}
    F(x)&=\sum_{n\ge 0}x^{2n}\\
    &=\sum_{n\ge 0}(x^2)^{n}\\
    &=\frac{1}{1-x^2}
    \end{aligned}
    $$
    
    Câu thứ ba (lấy đạo hàm):
    
    $$
    \begin{aligned}F(x)&=\sum_{n\ge 0}(n+1)x^n\\&=\sum_{n\ge 1}nx^{n-1}\\&=\sum_{n\ge 0}(x^n)'\\&=\left(\frac{1}{1-x}\right)'\\&=\frac{1}{(1-x)^2}\end{aligned}
    $$
    
    Câu thứ tư (định lý nhị thức):
    
    $$
    F(x)=\sum_{n\ge 0}\binom{m}{n}x^n=(1+x)^m
    $$
    
    Câu thứ năm:
    
    $$
    F(x)=\sum_{n\ge 0}\binom{m+n}{n}x^n=\frac{1}{(1-x)^{m+1}}
    $$
    
    Có thể chứng minh bằng quy nạp.
    
    Trước hết, khi $m=0$ thì $F(x)=\dfrac{1}{1-x}$.
    
    Khi $m>0$, ta có
    
    $$
    \begin{aligned}
    \frac{1}{(1-x)^{m+1}}
    &=\frac{1}{(1-x)^m}\frac{1}{1-x}\\
    &=\left(\sum_{n\ge 0}\binom{m+n-1}{n}x^n \right)\left(\sum_{n\ge 0}x^n \right)\\
    &=\sum_{n\ge 0} x^n\sum_{i=0}^n \binom{m+i-1}{i}\\
    &=\sum_{n\ge 0}\binom{m+n}{n}x^n
    \end{aligned}
    $$

<span id="&#x6590;&#x6ce2;&#x90a3;&#x5951;&#x6570;&#x5217;&#x7684;&#x751f;&#x6210;&#x51fd;&#x6570;"></span>
## Hàm sinh của dãy Fibonacci

Tiếp theo ta suy ra hàm sinh của dãy Fibonacci.

Dãy Fibonacci được định nghĩa bởi $a_0=0,a_1=1,a_n=a_{n-1}+a_{n-2}\;(n>1)$. Giả sử hàm sinh thường của nó là $F(x)$. Dựa trên công thức truy hồi, ta có thể lập phương trình cho $F(x)$ tương tự:

$$
F(x)=xF(x)+x^2F(x)-a_0x+a_1x+a_0
$$

Giải ra được

$$
F(x)=\frac{x}{1-x-x^2}
$$

Câu hỏi tiếp theo là: làm thế nào tìm dạng khai triển của nó?

<span id="&#x5c55;&#x5f00;&#x65b9;&#x5f0f;&#x4e00;"></span>
### Cách khai triển thứ nhất

Ta có thể xem $x+x^2$ như một khối, khi đó

$$
\begin{aligned}
F(x) &= \dfrac{x}{1-(x+x^2)} \\
&= x\sum_{k=0}^{\infty}(x+x^2)^k \\
&= x\sum_{k=0}^{\infty}\sum_{i=0}^k\binom{k}{i}x^{k-i}(x^2)^i \\
&= \sum_{k=0}^{\infty}\sum_{i=0}^k\binom{k}{i}x^{k+i+1} \\
&= \sum_{n=1}^{\infty}\sum_{i=0}^{\lfloor(n-1)/2\rfloor}\binom{n-i-1}{i}x^n.
\end{aligned}
$$

Ở bước cuối, đặt $n=k+i+1$ rồi đổi thứ tự lấy tổng. Từ đó thu được công thức tổng quát:

$$
a_n = \sum_{i=0}^{\lfloor(n-1)/2\rfloor}\binom{n-i-1}{i}.
$$

Đây chưa phải dạng liên quan tới tỉ lệ vàng mà ta quen thuộc.

<span id="&#x5c55;&#x5f00;&#x65b9;&#x5f0f;&#x4e8c;"></span>
### Cách khai triển thứ hai

Xét việc giải phương trình hệ số chưa biết:

$$
\frac{A}{1-ax}+\frac{B}{1-bx}= \frac{x}{1-x-x^2}
$$

Quy đồng mẫu số được

$$
\frac{A-Abx+B-aBx}{(1-ax)(1-bx)} = \frac{x}{1-x-x^2}
$$

So sánh các hệ số chưa biết, ta nhận được

$$
\begin{cases}
A+B=0\\
-Ab-aB=1\\
a+b=1\\
ab=-1
\end{cases}
$$

Giải ra

$$
\begin{cases}
A=\frac{1}{\sqrt{5}}\\
B=-\frac{1}{\sqrt{5}}\\
a=\frac{1+\sqrt{5}}{2}\\
b=\frac{1-\sqrt{5}}{2}
\end{cases}
$$

Dựa vào khai triển của cấp số nhân, ta thu được công thức tổng quát của dãy Fibonacci:

$$
\frac{x}{1-x-x^2}=\sum_{n\ge 0}x^n
\frac{1}{\sqrt{5}}\left( \left(\frac{1+\sqrt{5}}{2}\right)^n-\left(\frac{1-\sqrt{5}}{2}\right)^n \right)
$$

Dạng này cũng được gọi là một dạng đóng khác của dãy Fibonacci ($\frac{x}{1-x-x^2}$ cũng là một dạng đóng).

Với đa thức bất kỳ $P(x),Q(x)$, khai triển của hàm sinh $\dfrac{P(x)}{Q(x)}$ đều có thể tìm bằng phương pháp trên. Trong thực tế, ta thường tìm các nghiệm của $Q(x)$ trước, viết mẫu số dưới dạng $\prod (1-p_ix)^{d_i}$, rồi mới tìm tử số.

Khi phân tích mẫu số mà có nghiệm bội, mỗi bội thêm một phân thức nữa. Ví dụ xét hàm sinh

$$
G(x)=\frac{1}{(1-x)(1-2x)^2}
$$

và công thức tổng quát cho hệ số của nó, ta có

$$
G(x)=\frac{c_0}{1-x}+\frac{c_1}{1-2x}+\frac{c_2}{(1-2x)^2}
$$

Giải ra

$$
\begin{cases}
c_0&=1\\
c_1&=-2\\
c_2&=2
\end{cases}
$$

Suy ra

$$
[x^n]G(x)=1-2^{n+1}+(n+1)\cdot 2^{n+1}
$$

<span id="&#x725b;&#x987f;&#x4e8c;&#x9879;&#x5f0f;&#x5b9a;&#x7406;"></span>
## Định lý nhị thức Newton

Ta định nghĩa lại phép toán tổ hợp:

$$
\binom{r}{k}=\frac{r^{\underline{k}}}{k!}\quad(r\in\mathbf{C},k\in\mathbf{N})
$$

Lưu ý rằng miền giá trị của $r$ là trường số phức. Trong trường hợp này, với $\alpha\in\mathbf{C}$, ta có

$$
(1+x)^{\alpha}=\sum_{n\ge 0}\binom{\alpha}{n}x^n
$$

Định lý nhị thức thông thường thực ra là một trường hợp đặc biệt của định lý nhị thức Newton.

<span id="&#x5361;&#x7279;&#x5170;&#x6570;&#x7684;&#x751f;&#x6210;&#x51fd;&#x6570;"></span>
## Hàm sinh của số Catalan

Xem [suy diễn đại số cho dạng số Catalan](../combinatorics/catalan.md#%E4%BB%A3%E6%95%B0%E6%8E%A8%E6%BC%94).

<span id="&#x5e94;&#x7528;"></span>
## Ứng dụng

Sau đây là một vài bài ví dụ để giới thiệu cách dùng hàm sinh trong OI.

<span id="&#x98df;&#x7269;"></span>
### Thức ăn

???+ note "[Thức ăn](https://hydro.ac/p/bzoj-P3028)"
    Chọn $n$ món từ nhiều loại thức ăn khác nhau, với ràng buộc của từng loại như sau:
    
    1.  Bánh burger Chengde: số lượng chẵn.
    2.  Coca: $0$ hoặc $1$ cái.
    3.  Đùi gà: $0$, $1$ hoặc $2$ cái.
    4.  Mật đào: số lượng lẻ.
    5.  Nugget gà: bội của $4$ cái.
    6.  Bánh bao: $0$, $1$, $2$ hoặc $3$ cái.
    7.  Thịt xào khoai tây lát: không quá một cái.
    8.  Bánh mì: bội của $3$ cái.
    
    Mỗi loại thức ăn đều tính theo đơn vị "cái"; chỉ cần tổng số lượng cộng lại bằng $n$ thì tính là một phương án. Với $n$ cho trước, hãy tính số phương án modulo $10007$.

Đây là một bài hàm sinh kinh điển. Với một loại thức ăn, đặt $a_n$ là số phương án chọn $n$ cái của loại đó, rồi tìm hàm sinh của nó. Hàm sinh cho số phương án chọn tổng cộng $n$ cái từ hai loại thức ăn chính là tích chập của hai hàm sinh tương ứng. Với nhiều loại thức ăn, hàm sinh cũng là tích chập của các hàm sinh.

Sau khi hiểu rằng số phương án có thể biểu diễn bằng tích chập, ta xây dựng các hàm sinh sau (chỉ số tương ứng với số thứ tự loại thức ăn trong đề):

1.  $\displaystyle\sum_{n\ge 0}x^{2n}=\dfrac{1}{1-x^2}$.
2.  $1+x$.
3.  $1+x+x^2=\dfrac{1-x^3}{1-x}$.
4.  $\dfrac{x}{1-x^2}$.
5.  $\displaystyle \sum_{n\ge 0}x^{4n}=\dfrac{1}{1-x^4}$.
6.  $1+x+x^2+x^3=\dfrac{1-x^4}{1-x}$.
7.  $1+x$.
8.  $\dfrac{1}{1-x^3}$.

Nhân tất cả lại, ta được hàm sinh của đáp án:

$$
F(x)=\frac{(1+x)(1-x^3)x(1-x^4)(1+x)}{(1-x^2)(1-x)(1-x^2)(1-x^4)(1-x)(1-x^3)}
=\frac{x}{(1-x)^4}
$$

Sau đó chuyển nó sang dạng khai triển (dùng bài tập thứ năm trong phần luyện tập về dạng đóng):

$$
F(x)=\sum_{n\ge 1}\binom{n+2}{n-1}x^n
$$

Vì vậy đáp án là $\dbinom{n+2}{n-1}=\dbinom{n+2}{3}$.

### Sweet

???+ note "[CEOI2004 Sweet](https://hydro.ac/p/bzoj-P3027)"
    Có $n$ đống kẹo. Các đống khác nhau có loại kẹo khác nhau (nghĩa là kẹo trong cùng một đống là cùng loại, còn kẹo ở các đống khác nhau thuộc các loại khác nhau). Đống thứ $i$ có $m_i$ viên kẹo. Bây giờ cần ăn ít nhất $a$ viên và không quá $b$ viên. Hỏi có bao nhiêu phương án.
    
    Hai phương án khác nhau khi và chỉ khi số viên ăn khác nhau, hoặc trong số kẹo đã ăn, có một loại kẹo mà số lượng của nó khác nhau giữa hai phương án.
    
    $n\le 10,0\le a\le b\le 10^7,m_i\le 10^6$.

Hàm sinh cho số phương án ăn $j$ viên từ đống thứ $i$ (rõ ràng bằng $1$) là

$$
F_i(x)=\sum_{j=0}^{m_i}x^j=\frac{1-x^{m_i+1}}{1-x}
$$

Vì vậy hàm sinh cho số phương án ăn tổng cộng $i$ viên kẹo là

$$
G(x)=\prod_{i=1}^n F_i(x)=(1-x)^{-n}\prod_{i=1}^n(1-x^{m_i+1})
$$

Ta cần tính $\sum_{i=a}^b[x^i]G(x)$.

Do $n\le 10$, ta có thể khai triển trực tiếp $\prod_{i=1}^n(1-x^{m_i+1})$ (tối đa chỉ có $2^n$ hạng tử).

Sau đó áp dụng định lý nhị thức Newton cho $(1-x)^{-n}$:

$$
\begin{aligned}
(1-x)^{-n}
&=\sum_{i\ge 0}\binom{-n}{i}(-x)^i\\
&=\sum_{i\ge 0}\binom{n-1+i}{i}x^i
\end{aligned}
$$

Ta liệt kê hạng tử $x^k$ trong $\prod_{i=1}^n(1-x^{m_i+1})$, giả sử hệ số của nó là $c_k$. Khi nhân với $(1-x)^{-n}$, đóng góp của nó vào đáp án là

$$
c_k\sum_{i=a-k}^{b-k}\binom{n-1+i}{i}=c_k\left(
\binom{n+b-k}{b-k}-
\binom{n+a-k-1}{a-k-1}
\right)
$$

Như vậy có thể tính đáp án trong $O(b)$.

Độ phức tạp thời gian là $O(2^n+b)$.
