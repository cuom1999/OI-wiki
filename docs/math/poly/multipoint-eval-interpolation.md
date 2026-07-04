<span id="&#x591A;&#x9879;&#x5F0F;&#x7684;&#x591A;&#x70B9;&#x6C42;&#x503C;"></span>
## Tính giá trị đa thức tại nhiều điểm

<span id="&#x63CF;&#x8FF0;"></span>
### Mô tả

Cho một đa thức $f\left(x\right)$ và $n$ điểm $x_{1},x_{2},\dots,x_{n}$, hãy tính

$$
f\left(x_{1}\right),f\left(x_{2}\right),\dots,f\left(x_{n}\right)
$$

<span id="&#x89E3;&#x6CD5;"></span>
### Cách giải

Xét dùng chia để trị để giảm một nửa kích thước bài toán.

Chia các điểm đã cho thành hai phần:

$$
\begin{aligned}
    X_{0}&=\left\{x_{1},x_{2},\dots,x_{\left\lfloor\frac{n}{2}\right\rfloor}\right\}\\
    X_{1}&=\left\{x_{\left\lfloor\frac{n}{2}\right\rfloor+1},x_{\left\lfloor\frac{n}{2}\right\rfloor+2},\dots,x_{n}\right\}
\end{aligned}
$$

Xây dựng đa thức

$$
g_{0}\left(x\right)=\prod_{x_{i}\in X_{0}}\left(x-x_{i}\right)
$$

Khi đó $\forall x\in X_{0}:g_{0}\left(x\right)=0$.

Xét biểu diễn $f\left(x\right)$ dưới dạng $g_{0}\left(x\right)Q\left(x\right)+f_{0}\left(x\right)$, tức là:

$$
f_{0}\left(x\right)\equiv f\left(x\right)\pmod{g_{0}\left(x\right)}
$$

Khi đó $\forall x\in X_{0}:f\left(x\right)=g_{0}\left(x\right)Q\left(x\right)+f_{0}\left(x\right)=f_{0}\left(x\right)$; với $X_{1}$ ta làm tương tự.

Đến đây, kích thước bài toán đã bị giảm một nửa, nên có thể giải bằng chia để trị + lấy dư đa thức.

Độ phức tạp thời gian

$$
T\left(n\right)=2T\left(\frac{n}{2}\right)+O\left(n\log{n}\right)=O\left(n\log^{2}{n}\right)
$$

<span id="&#x591A;&#x9879;&#x5F0F;&#x7684;&#x5FEB;&#x901F;&#x63D2;&#x503C;"></span>
## Nội suy nhanh đa thức

<span id="&#x63CF;&#x8FF0;_1"></span>
### Mô tả

Cho tập gồm $n+1$ điểm

$$
X=\left\{\left(x_{0},y_{0}\right),\left(x_{1},y_{1}\right),\dots,\left(x_{n},y_{n}\right)\right\}
$$

Hãy tìm một đa thức bậc $n$ là $f\left(x\right)$ sao cho nó thỏa mãn $\forall\left(x,y\right)\in X:f\left(x\right)=y$.

<span id="&#x89E3;&#x6CD5;_1"></span>
### Cách giải

Xét công thức nội suy Lagrange

$$
f(x) = \sum_{i=1}^{n} \prod_{j\neq i }\frac{x-x_j}{x_i-x_j} y_i
$$

Đặt đa thức $M(x) = \prod_{i=1}^n (x - x_i)$. Theo quy tắc L'Hopital,

$$
\prod_{j\neq i} (x_i - x_j) = \lim_{x\rightarrow x_i} \frac{\prod_{j=1}^n (x - x_j)}{x - x_i} = M'(x_i)
$$

Vậy đa thức có thể được biểu diễn thành

$$
f(x) = \sum_{i = 1}^n \frac{y_i}{M'(x_i)}\prod_{j \neq i}(x - x_j)
$$

Trước hết, ta dùng chia để trị để tính biểu diễn hệ số của $M(x)$; sau đó có thể tính tất cả $M'(x_i)$ bằng tính giá trị tại nhiều điểm trong thời gian $O(n\log^2 n)$.

Đặt $v_i = \frac{y_i}{M'(x_i)}$. Tiếp theo xét cách tính $f(x)$. Với trường hợp $n = 1$, ta có $f(x) = v_1, M(x) = x - x_1$. Nếu không, đặt

$$
\begin{aligned}
f_0(x) & = \sum_{i = 1}^{\left\lfloor \frac n2 \right \rfloor} v_i\prod_{j \neq i \wedge j \le \left\lfloor \frac n2 \right \rfloor}(x - x_j)\\
M_0(x) & = \prod_{i = 1}^{\left\lfloor \frac n2 \right \rfloor} (x - x_i)\\
f_1(x) & = \sum_{i = \left\lfloor \frac n2 \right \rfloor+1}^n v_i\prod_{j \neq i \wedge \left\lfloor \frac n2 \right \rfloor < j \le n}(x - x_j) \\
M_1(x) & = \prod_{i = \left\lfloor \frac n2 \right \rfloor+1}^n (x - x_i)
\end{aligned}
$$

Suy ra $f(x) = f_0(x)M_1(x) + f_1(x)M_0(x), M(x) = M_0(x)M_1(x)$. Do đó có thể tính bằng chia để trị; phần này cũng có độ phức tạp $O(n\log^2 n)$.
