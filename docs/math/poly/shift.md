<span id="tịnh-tiến-đa-thức"></span>

## Tịnh tiến đa thức

Tịnh tiến đa thức là một trường hợp đơn giản của phép hợp thành đa thức. Cho các hệ số của $f(x)=\sum _ {i=0}^nf_ix^i$ và một hằng số $c$, cần tìm các hệ số của $f(x+c)$, tức phép biến đổi $f(x)\mapsto f(x+c)$.

<span id="phương-pháp-chia-để-trị"></span>

### Phương pháp chia để trị

Đặt

$$
f(x)=f_0(x)+x^{\left\lfloor n/2\right\rfloor}f_1(x).
$$

Khi đó

$$
f(x+c)=f_0(x+c)+(x+c)^{\left\lfloor n/2\right\rfloor}f_1(x+c).
$$

Các hệ số của $(x+c)^{\left\lfloor n/2\right\rfloor}$ là các hệ số nhị thức, nên

$$
T(n)=2T(n/2)+O(n\log n)=O(n\log^2 n),
$$

trong đó $O(n\log n)$ là thời gian nhân đa thức.

<span id="phương-pháp-công-thức-taylor"></span>

### Phương pháp công thức Taylor

Áp dụng công thức Taylor cho $f(x)$ tại $c$, có

$$
f(x)=f(c)+\frac{f'(c)}{1!}(x-c)+\frac{f''(c)}{2!}(x-c)^2+\cdots +\frac{f^{(n)}(c)}{n!}(x-c)^n.
$$

Khi đó

$$
f(x+c)=f(c)+\frac{f'(c)}{1!}x+\frac{f''(c)}{2!}x^2+\cdots +\frac{f^{(n)}(c)}{n!}x^n.
$$

Quan sát rằng với $t\geq 0$,

$$
\begin{aligned}
t!\lbrack x^t\rbrack f(x+c)&=f^{(t)}(c)\\
&=\sum _ {i=t}^nf_ii!\frac{c^{i-t}}{(i-t)!}\\
&=\sum _ {i=0}^{n-t}f _ {i+t}(i+t)!\frac{c^i}{i!}.
\end{aligned}
$$

Đặt

$$
\begin{aligned}
A_0(x)&=\sum _ {i=0}^nf _ {n-i}(n-i)!x^i\\
B_0(x)&=\sum _ {i=0}^n\frac{c^i}{i!}x^i.
\end{aligned}
$$

Khi đó

$$
\begin{aligned}
\lbrack x^{n-t}\rbrack (A_0(x)B_0(x))&=\sum _ {i=0}^{n-t} (\lbrack x^{n-t-i}\rbrack A_0(x))(\lbrack x^i\rbrack B_0(x))\\
&=\sum _ {i=0}^{n-t}f _ {i+t}(i+t)!\frac{c^i}{i!}\\
&=t!\lbrack x^t\rbrack f(x+c).
\end{aligned}
$$

<span id="phương-pháp-định-lí-nhị-thức"></span>

### Phương pháp định lí nhị thức

Xét định lí nhị thức $\displaystyle (a+b)^n=\sum _ {i=0}^n\binom{n}{i}a^ib^{n-i}$. Khi đó

$$
\begin{aligned}
f(x+c)&=\sum _ {i=0}^nf_i(x+c)^i\\
&=\sum _ {i=0}^nf_i\left(\sum _ {j=0}^i\binom{i}{j}x^jc^{i-j}\right)\\
&=\sum _ {i=0}^nf_ii!\left(\sum _ {j=0}^i\frac{x^j}{j!}\frac{c^{i-j}}{(i-j)!}\right)\\
&=\sum _ {i=0}^n\frac{x^i}{i!}\left(\sum _ {j=i}^{n}f_jj!\frac{c^{j-i}}{(j-i)!}\right).
\end{aligned}
$$

Kết quả thu được giống với phương pháp trên.

<span id="tịnh-tiến-các-giá-trị-tại-điểm-liên-tiếp"></span>

## Tịnh tiến các giá trị tại điểm liên tiếp

???+ note "Bài tập [LOJ 166. Nội suy Lagrange 2](https://loj.ac/p/166)"
    Cho các giá trị tại điểm liên tiếp $f(0),f(1),\dots ,f(n)$ của một đa thức $f$ có bậc không vượt quá $n$. Tính $f(c),f(c+1),\dots ,f(c+n)$ theo modulo $998244353$, trong đó $1\leq n\leq 10^5,n < m\leq 10^8$.

<span id="phương-pháp-công-thức-nội-suy-lagrange"></span>

### Phương pháp công thức nội suy Lagrange

Xét [công thức nội suy Lagrange](../numerical/interp.md#phương-pháp-nội-suy-lagrange):

$$
\begin{aligned}
f(x)&=\sum _ {0\leq i\leq n}f(i)\prod _ {0\leq j\leq n\,\land \,j\neq i}\frac{x-j}{i-j}\\
&=\sum _ {0\leq i\leq n}f(i)\frac{x!}{(x-n-1)!(x-i)}\frac{(-1)^{n-i}}{i!(n-i)!}\\
&=\frac{x!}{(x-n-1)!}\sum _ {0\leq i\leq n}\frac{f(i)}{(x-i)}\frac{(-1)^{n-i}}{i!(n-i)!}.
\end{aligned}
$$

Biểu thức trên tuy có dạng tích chập nhưng không bảo đảm mẫu số $x-i\neq 0$. Vì vậy dưới đây chỉ xét trường hợp $c > n$; các trường hợp khác có thể xử lí bằng phân loại, chẳng hạn khi hệ số được lấy theo modulo số nguyên tố thì cần tránh mẫu số của hệ số trong $B_0(x)$ bằng không. Đặt

$$
\begin{aligned}
A_0(x)&=\sum _ {0\leq i\leq n}\frac{f(i)(-1)^{n-i}}{i!(n-i)!}x^i\\
B_0(x)&=\sum _ {i\geq 0}\frac{1}{c-n+i}x^i.
\end{aligned}
$$

Khi đó với $t\geq 0$,

$$
\begin{aligned}
\lbrack x^{n+t}\rbrack (A_0(x)B_0(x))&=\sum _ {i=0}^{n+t}(\lbrack x^i\rbrack A_0(x))(\lbrack x^{n+t-i}\rbrack B_0(x))\\
&=\sum _ {i=0}^{n}\frac{f(i)(-1)^{n-i}}{i!(n-i)!}\frac{1}{c+t-i}\\
&=\frac{(c+t-n-1)!}{(c+t)!}f(c+t).
\end{aligned}
$$

Trong cài đặt, lấy phần cắt cần thiết của $B_0(x)$ là có thể tính thêm nhiều giá trị tại điểm; đồng thời có thể tận dụng tích chập vòng.

Nếu sửa bài toán một chút, giả sử với một $d$ nào đó, các giá trị được cho là $f(d),f(d+k),\dots ,f(d+nk)$. Có thể tính $f(c+d),f(c+d+k),\dots ,f(c+d+nk)$ bằng cách xem đây là tịnh tiến các giá trị của $g(x)=f(d+kx)$ từ $g(0),g(1),\dots ,g(n)$ sang $g(c/k),g(c/k+1),\dots ,g(c/k+n)$.

Công thức nội suy Lagrange cũng cho một phương pháp tính một giá trị tại điểm trong thời gian tuyến tính bằng cách duy trì một số tích tiền tố và hậu tố.

<span id="ứng-dụng"></span>

## Ứng dụng

<span id="các-số-stirling-không-dấu-loại-một-trên-cùng-một-hàng"></span>

### Các số Stirling không dấu loại một trên cùng một hàng

???+ note "Bài tập [P5408. Hàng của số Stirling loại một](https://www.luogu.com.cn/problem/P5408)"
    Theo modulo số nguyên tố $167772161$, tính $\displaystyle {n\brack 0},{n\brack 1},\dots ,{n\brack n}$, trong đó $1\leq n< 262144$.

Xét

$$
x^{\overline{n}}=\sum _ {i=0}^n{n\brack i}x^i,\quad n\geq 0,
$$

trong đó $x^{\overline{n}}=x\cdot (x+1)\cdots (x+n-1)$ là lũy thừa giai thừa tăng. Đặt $f_n(x)=x^{\overline{n}}$, khi đó

$$
f_{2n}(x)=x^{\overline{n}}\cdot (x+n)^{\overline{n}}=f_n(x)f_n(x+n).
$$

Dùng tịnh tiến đa thức có thể tính $f_n(x+n)$ trong $O(n\log n)$; bài toán được thu nhỏ còn một nửa, tức là tính các hệ số của $f_n(x)$. Do đó

$$
T(n)=T(n/2)+O(n\log n)=O(n\log n).
$$

<span id="giai-thừa-theo-modulo-số-nguyên-tố"></span>

### Giai thừa theo modulo số nguyên tố

???+ note "Bài tập [P5282. Mẫu thuật toán giai thừa nhanh](https://www.luogu.com.cn/problem/P5282)"
    Tính $n!\bmod p$, trong đó $p$ là số nguyên tố và $1\leq n< p\leq 2^{31}-1$.

Đặt $v=\lfloor\sqrt{n}\rfloor$ và $g(x)=\prod _ {i=1}^v(x+i)$. Khi đó

$$
n!\equiv \left(\prod _ {i=0}^{v-1}g(iv)\right)\cdot \prod _ {i=v^2+1}^n i\pmod{p}.
$$

Trong đó $\prod _ {i=v^2+1}^n i$ có thể tính trong $O(\sqrt{n})$. Cần tính nhanh nửa trước của biểu thức trên.

<span id="tính-giá-trị-đa-thức-tại-nhiều-điểm"></span>

#### Tính giá trị đa thức tại nhiều điểm

Các hệ số của $g(x)$ có thể được tính bằng thuật toán tịnh tiến đa thức ở trên trong thời gian $O(n\log n)$, nhưng việc tính giá trị tại nhiều điểm $g(0),g(v),g(2v),\dots ,g(v^2-v)$ cần thời gian $O(\sqrt{n}\log ^2n)$.

<span id="tịnh-tiến-các-giá-trị-tại-điểm-liên-tiếp_1"></span>

#### Tịnh tiến các giá trị tại điểm liên tiếp

Đặt $g_d(x)=\prod _ {i=1}^d(x+i)$. Có thể dùng $d+1$ giá trị $g_d(0),g_d(v),\dots ,g_d(dv)$ để xác định duy nhất đa thức bậc $d$ này. Lại có

$$
g _ {2d}(x)=g_d(x)g_d(x+d).
$$

Vì vậy chỉ cần $2d+1$ giá trị là có thể xác định duy nhất $g _ {2d}(x)$. Khi đó dùng tịnh tiến các giá trị tại điểm liên tiếp để tính $g_d((d+1)v),g_d((d+2)v),\dots ,g_d(2dv)$, tức tịnh tiến các giá trị của $h(x)=g_d(vx)$ từ $h(0),h(1),\dots ,h(d)$ sang $h(d+1),h(d+2),\dots ,h(2d)$; đồng thời tính $g_d(d),g_d(v+d),\dots ,g_d(2dv+d)$, tức tịnh tiến các giá trị của $h(x)=g_d(vx)$ từ $h(0),h(1),\dots ,h(d)$ sang $h(d/v),h(d/v+1),h(d/v+2),\dots ,h(d/v+2d)$. Sau đó nhân từng cặp giá trị tương ứng là thu được $g _ {2d}(0),g _ {2d}(v),\dots ,g _ {2d}(2dv)$.

Để tính $g _ {d+1}(0),g _ {d+1}(v),\dots ,g _ {d+1}(dv),g _ {d+1}((d+1)v)$ từ $g_d(0),g_d(v),\dots ,g_d(dv)$, xét

$$
g _ {d+1}(x)=(x+d+1)\cdot g_d(x).
$$

Giá trị điểm tăng thêm có thể tính bằng thuật toán thời gian tuyến tính. Khi bắt đầu, duy trì $g_1(0)=1,g_1(v)=v+1$, rồi dùng tịnh tiến các giá trị tại điểm liên tiếp để nhân đôi và duy trì các giá trị đó. Khi ấy

$$
T(n)=T(n/2)+O(n\log n)=O(n\log n).
$$

Mà chỉ cần khoảng $\sqrt{n}$ giá trị tại điểm, nên độ phức tạp thời gian là $O(\sqrt{n}\log n)$.

<span id="tổng-tiền-tố-hệ-số-nhị-thức-theo-modulo-số-nguyên-tố"></span>

### Tổng tiền tố hệ số nhị thức theo modulo số nguyên tố

???+ note "Bài tập [LOJ 6386. Tổng tiền tố tổ hợp](https://loj.ac/p/6386)"
    Tính $\displaystyle \sum _ {i=0}^m\binom{n}{i}\bmod 998244353$, trong đó $0\leq m\leq n\leq 9\times 10^8$.

Xét cách dùng ma trận để mô tả bước truy hồi $n!=n\cdot (n-1)!$. Có

$$
\begin{bmatrix}
n!
\end{bmatrix}
=\left(
\prod _ {i=0}^{n-1}
\begin{bmatrix}i+1\end{bmatrix}
\right)
\begin{bmatrix}
1
\end{bmatrix}.
$$

Tương tự, có thể mô tả truy hồi của tổng tiền tố hệ số nhị thức bằng

$$
\begin{bmatrix}
\binom{n}{m+1}\\
\sum _ {i=0}^m\binom{n}{i}
\end{bmatrix}=
\begin{bmatrix}
(n-m)/(m+1)&0\\
1&1
\end{bmatrix}
\begin{bmatrix}
\binom{n}{m}\\
\sum _ {i=0}^{m-1}\binom{n}{i}
\end{bmatrix}.
$$

Lưu ý thứ tự của phép nhân ma trận. Khi đó

$$
\begin{aligned}
\begin{bmatrix}
\binom{n}{m+1}\\
\sum _ {i=0}^m\binom{n}{i}
\end{bmatrix}
&=\left(
\prod _ {i=0}^{m}
\begin{bmatrix}
(n-i)/(i+1)&0\\1&1
\end{bmatrix}
\right)
\begin{bmatrix}
1\\0
\end{bmatrix}\\
&=
\frac{1}{(m+1)!}
\left(
\prod _ {i=0}^{m}
\begin{bmatrix}
n-i&0\\i+1&i+1
\end{bmatrix}
\right)
\begin{bmatrix}
1\\0
\end{bmatrix}.
\end{aligned}
$$

Đặt $v=\lfloor\sqrt{m}\rfloor$, xét duy trì ma trận

$$
\begin{aligned}
M _ d(x)&=
\prod _ {i=1}^d
\begin{bmatrix}
-x+n+1-i&0\\
x+i&x+i
\end{bmatrix}\\
&=
\begin{bmatrix}
f_d(x)&0\\
g_d(x)&h_d(x)
\end{bmatrix}
\end{aligned}
$$

tại các giá trị $M _ d(0),M _ d(v),\dots ,M_d(dv)$, tức là $f_d(0),f_d(v),\dots ,f_d(dv)$, $h_d(0),\dots ,h_d(dv)$ và $g_d(0),\dots ,g_d(dv)$. Lại có

$$
\begin{aligned}
M _ {2d}(x)&=
\prod _ {i=1}^{2d}
\begin{bmatrix}
-x+n+1-i&0\\
x+i&x+i
\end{bmatrix}\\
&=
\left(
\prod _ {i=1}^d
\begin{bmatrix}
-x-d+n+1-i&0\\
x+d+i&x+d+i
\end{bmatrix}
\right)
\left(
\prod _ {i=1}^d
\begin{bmatrix}
-x+n+1-i&0\\
x+i&x+i
\end{bmatrix}
\right) \\
&=
\begin{bmatrix}
f_d(x+d)&0\\
g_d(x+d)&h_d(x+d)
\end{bmatrix}
\begin{bmatrix}
f_d(x)&0\\
g_d(x)&h_d(x)
\end{bmatrix} \\
&=
\begin{bmatrix}
f_d(x+d)f_d(x)&0\\
g_d(x+d)f_d(x)+h_d(x+d)g_d(x)&h_d(x+d)h_d(x)
\end{bmatrix}.
\end{aligned}
$$

Phần tử góc dưới bên phải của ma trận chính là đại lượng đã được duy trì trong thuật toán giai thừa. Vì vậy

$$
\begin{aligned}
\prod _ {i=0}^{m}
\begin{bmatrix}
n-i&0\\i+1&i+1
\end{bmatrix}=
\left(
\prod _ {i=(k+1)v}^m
\begin{bmatrix}
n-i&0\\
i+1&i+1
\end{bmatrix}
\right)
\begin{bmatrix}
f_v(kv)&0\\
g_v(kv)&h_v(kv)
\end{bmatrix}
\cdots
\begin{bmatrix}
f_v(0)&0\\
g_v(0)&h_v(0)
\end{bmatrix}
\end{aligned}
$$

có thể được tính xong trong thời gian $O(\sqrt m\log m)$.

<span id="số-điều-hòa-theo-modulo-số-nguyên-tố"></span>

### Số điều hòa theo modulo số nguyên tố

???+ note "Bài tập [P5702. Tính tổng cấp số điều hòa](https://www.luogu.com.cn/problem/P5702)"
    Tính $\sum _ {i=1}^ni^{-1}\bmod p$, trong đó $p$ là số nguyên tố và $1\leq n< p< 2^{30}$.

Kí hiệu $H_n=\sum _ {k=1}^nk^{-1}$. Một bước truy hồi là

$$
\begin{bmatrix}
(n+1)!\\(n+1)!H _ {n+1}
\end{bmatrix}=
\begin{bmatrix}
n+1&0\\1&n+1
\end{bmatrix}
\begin{bmatrix}
n!\\n!H_n
\end{bmatrix}.
$$

Khi đó

$$
\begin{bmatrix}
{n+1\brack 1}\\{n+1\brack 2}
\end{bmatrix}=
\begin{bmatrix}
n!\\n!H_n
\end{bmatrix}=
\left(
\prod _ {i=0}^{n-1}
\begin{bmatrix}
i+1&0\\1&i+1
\end{bmatrix}
\right)
\begin{bmatrix}
1\\0
\end{bmatrix}.
$$

Trong đó $\displaystyle {n+1\brack 1}$ và $\displaystyle {n+1\brack 2}$ là các số Stirling không dấu loại một. Phương pháp duy trì ma trận giá trị tại điểm giống như trên.

<span id="truy-hồi-đa-thức"></span>

## Truy hồi đa thức

Với trường hợp tổng quát hơn, tương tự ví dụ thuật toán giai thừa nhanh ở trên, cần một thuật toán như thế nào?

???+ note "Bài tập [P6115. Mẫu truy hồi đa thức](https://www.luogu.com.cn/problem/P6115)"
    Hiện có dãy $a$ thỏa mãn $\forall n\ge m,\sum_{k=0}^ma_{n-k}P_k(n)=0$, trong đó $P_k$ là đa thức bậc không vượt quá $d$.<br>
    Cho các hệ số của mọi $P_k$ và $a_0,a_1,\dots,a_{m-1}$, tính $a_n$.
    Lấy kết quả modulo $998244353$. $n\le6\times10^8$, $1\le m,d\le7$, giới hạn thời gian $7s$.

Để mô tả có hệ thống hơn quá trình xây dựng ma trận trong vài bài tập trên, đưa vào khái niệm [ma trận $\lambda$](../linear-algebra/jordan.md#ma-trận-lambda).

Để thực hiện truy hồi đa thức, cần lưu ý rằng trong thuật toán giai thừa nhanh, các giá trị tại điểm được duy trì không phải là $n!$, mà là $\prod_{i=0}^{T-1}(aT+i)$, tức là **quan hệ bội số giữa một cặp giá trị**.

Vì bậc truy hồi đa thức $m$ không còn chỉ là $1$, **không thể trực tiếp duy trì quan hệ bội số giữa một cặp số**; thay vào đó, cần duy trì **biến đổi tuyến tính giữa một cặp vector $m$ chiều**, tức một ma trận $m\times m$, trong đó **mỗi phần tử của ma trận tương ứng với một giá trị tại điểm của một đa thức**.

Với bài toán tính hệ số xa trong truy hồi đa thức tổng quát, có thể xây dựng

$$
-{\frac{1}{P_0(n)}}\begin{bmatrix}P_1(n)&P_2(n)&P_3(n)&\cdots&P_{m-1}(n)&P_m(n)\\-P_0(n)\\&-P_0(n)\\&&-P_0(n)\\&&&\ddots\\&&&&-P_0(n)\\\end{bmatrix}
\begin{bmatrix}a_{n-1}\\a_{n-2}\\a_{n-3}\\\vdots\\a_{n-m+1}\\a_{n-m}\end{bmatrix}
=\begin{bmatrix}a_n\\a_{n-1}\\a_{n-2}\\\vdots\\a_{n-m+2}\\a_{n-m+1}\end{bmatrix}.
$$

Đặt

$$
B(\lambda)=\begin{bmatrix}
    P_1(\lambda)&P_2(\lambda)&P_3(\lambda)&\cdots&P_{m-1}(\lambda)&P_m(\lambda)\\
    -P_0(\lambda)\\
    &-P_0(\lambda)\\
    &&-P_0(\lambda)\\
    &&&\ddots\\
    &&&&-P_0(\lambda)\\
\end{bmatrix}
$$

Trước hết tạm bỏ qua nhân tử $-\frac1{P_0(n)}$ ở phía trước. Khi đó cần duy trì đại lượng dạng $\prod_{i=0}^{T-1}B(aT+m+i)$, trong đó phép nhân được thực hiện từ phải sang trái.

$B_T(\lambda)=\prod_{i=0}^{T-1}B(\lambda+i)$ là một ma trận $\lambda$ mà bậc của mỗi phần tử không vượt quá $dT$, nên chỉ cần $dT+1$ giá trị là đủ để duy trì.

Vì vậy duy trì các **giá trị tại điểm** là những ma trận $\lambda$ sau: $B_T(m)$, $B_T(m+T)$, $B_T(m+2T)$, $\dots$, $B_T(m+(dT-1)T)$, $B_T(m+dT^2)$. Sau đó dùng cách tương tự thuật toán giai thừa nhanh để tịnh tiến và nhân đôi các giá trị đa thức tại điểm một cách trực tiếp.

Cụ thể, để tăng $t=\log_2T$ lên $1$, thực hiện như sau:

1.  Trong thời gian $O(m^2dT\log(dT))$, lấy $B_T(p+dT^2)$, $B_T(p+(dT+1)T)$, $B_T(p+(dT+2)T)$, $\cdots$, $B_T(p+(2dT-1)T)$, $B_T(p+(2dT)dT)$.
2.  Trong thời gian $O(m^2dT\log(dT))$, lấy $B_T(p+2dT^2)$, $B_T(p+(2dT+1)T)$, $B_T(p+(2dT+2)T)$, $\cdots$, $B_T(p+(3dT-1)T)$, $B_T(p+(3dT)dT)$.
3.  Trong thời gian $O(m^2dT\log(dT))$, lấy $B_T(p+3dT^2)$, $B_T(p+(3dT+1)T)$, $B_T(p+(3dT+2)T)$, $\cdots$, $B_T(p+(4dT-1)T)$, $B_T(p+(4dT)dT)$.
4.  Tính $B_{2T}(v)=B_{T}(v+T)B_{T}(v)$.

Mỗi vòng tốn độ phức tạp $O(m^2dT\log(dT))$ cho phần tịnh tiến; đồng thời, mỗi vòng chỉ cần thực hiện $\Theta(dT)$ phép nhân ma trận, với độ phức tạp có thể xem là $O(m^3dT)$.

Cuối cùng, chỉ cần làm đến khi $T\ge\sqrt{n/d}$.

Nhân tử $-\frac1{P_0(n)}$ trước đó cũng có thể xử lí bằng phương pháp tương tự.

Như vậy độ phức tạp tiền xử lí là $\Theta(\sqrt{nd}(m^3+m^2\log(nd)))$.

Xét truy vấn, chỉ cần $\Theta(n/T)$ phép nhân vector với ma trận, cùng $O(T)$ lần chuyển trạng thái trực tiếp.

Phần tính toán này không phải nút thắt cổ chai về độ phức tạp.

Do đó tổng độ phức tạp của thuật toán là $\Theta(\sqrt{nd}(m^3+m^2\log(nd)))$.

Khi viết mã, có thể dùng kĩ thuật tích chập vòng để giảm hằng số của NTT.

Trong ứng dụng thực tế, thường cần trích hệ số xa của một GF vi phân hữu hạn đã biết, do đó $m,d$ đều là hằng số, tức đạt được việc tính hệ số xa trong $\Theta(\sqrt n\log n)$.

<span id="tài-liệu-tham-khảo"></span>

## Tài liệu tham khảo

-   Alin Bostan, Pierrick Gaudry, and Eric Schost. Linear recurrences with polynomial coefficients and application to integer factorization and Cartier-Manin operator.
-   Blog của Min\_25
-   [Blog của ZZQ - Giai thừa modulo số nguyên tố lớn](https://www.cnblogs.com/zzqsblog/p/8408691.html)
