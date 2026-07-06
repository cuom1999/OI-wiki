<span id="chuỗi-laurent-hình-thức"></span>

## Chuỗi Laurent hình thức

Từ vành chuỗi lũy thừa hình thức $\mathbb{C}\lbrack\lbrack x\rbrack\rbrack$, định nghĩa vành chuỗi Laurent hình thức:

$$
\mathbb{C}\left(\left(x\right)\right):=\left\lbrace \sum_{k\geq N}a_kx^k : N\in\mathbb{Z},a_k\in \mathbb{C}\right\rbrace
$$

Có thể mô phỏng định nghĩa nghịch đảo nhân trong chuỗi lũy thừa hình thức để định nghĩa nghịch đảo nhân của phần tử trong $\mathbb{C}\left(\left(x\right)\right)$:

Nếu với $f:=\sum_{k\geq N}f_kx^k$ và $f_N\neq 0$, tồn tại $g=\sum_{k\geq -N}g_kx^k$ thỏa mãn $fg=1$, thì

$$
g_k:=
\begin{cases}
f_N^{-1}, &\text{ nếu }k=-N\text{,} \\
-f_N^{-1}\sum_{i> N}f_ig_{k-i}, &\text{ ngược lại}
\end{cases}
$$

Tương tự chuỗi lũy thừa hình thức, với $f(x)=\sum_{k\geq N}f_kx^k$ khác không, cũng định nghĩa:

$$
\operatorname{ord} f:=\min\lbrace k:f_k\neq 0\rbrace
$$

Với $g\neq 0$, có

$$
\operatorname{ord} (fg)=\operatorname{ord}(f)+\operatorname{ord}(g).
$$

<span id="thặng-dư-hình-thức"></span>

## Thặng dư hình thức

Thặng dư hình thức là hệ số của hạng $x^{-1}$ trong chuỗi Laurent hình thức. Ký hiệu $\operatorname{res} f:=\lbrack x^{-1}\rbrack f$.

**Bổ đề**: với mọi chuỗi Laurent hình thức $f$, có $\operatorname{res} f'=0$.

**Chứng minh**: xét định nghĩa đạo hàm hình thức $\left(x^k\right)'=kx^{k-1}$.

**Bổ đề**: với mọi chuỗi Laurent hình thức $f,g$, có $\operatorname{res}(f'g)=-\operatorname{res}(fg')$.

**Chứng minh**: xét quy tắc nhân $(fg)'=f'g+fg'$, nên $0=\operatorname{res}((fg)')=\operatorname{res}(f'g)+\operatorname{res}(fg')$.

**Bổ đề**: với chuỗi Laurent hình thức $f(x)\neq 0$, có $\operatorname{res}(f'/f)=\operatorname{ord}f$.

**Chứng minh**: đặt $\operatorname{ord}f=k$. Khi đó

$$
\begin{aligned}
\operatorname{res}\left(\frac{f'}{f}\right)&=\operatorname{res}\left(\frac{kf_kx^{k-1}+\cdots}{f_kx^k+f_{k+1}x^{k+1}+\cdots}\right) \\
&=\operatorname{res}\left(\frac{kf_kx^{-1}+\cdots}{f_k+f_{k+1}x+\cdots}\right) \\
&=k.
\end{aligned}
$$

**Bổ đề**: với chuỗi Laurent hình thức $f$ và chuỗi lũy thừa hình thức $g\neq 0$, có $\operatorname{res}(f)\operatorname{ord}(g)=\operatorname{res}(f(g)g')$.

**Chứng minh**: xét tính tuyến tính, chỉ cần chứng minh trường hợp $f=x^k$, trong đó $k\in\mathbb{Z}$. Nếu $k\neq -1$ thì

$$
\begin{aligned}
\operatorname{res}x^k&=0 \\
\operatorname{res}(g^kg')&=\operatorname{res}\left(\frac{1}{k+1}\left(g^{k+1}\right)'\right) \\
&=\frac{1}{k+1}\operatorname{res}\left(\left(g^{k+1}\right)'\right) \\
&=0.
\end{aligned}
$$

Nếu $k=-1$ thì

$$
\begin{aligned}
\operatorname{res}f&=\operatorname{res}\left(x^{-1}\right)=1 \\
\operatorname{res}(f(g)g')&=\operatorname{res}(g'/g) \\
&=\operatorname{ord}(g) \\
&=\operatorname{res}(f)\operatorname{ord}(g).
\end{aligned}
$$

<span id="nghịch-đảo-hợp-thành"></span>

## Nghịch đảo hợp thành

Ký hiệu $A(x)\circ B(x):=A(B(x))$.

**Mệnh đề**: $f(x):=\sum_{k\geq 1}f_kx^k$ có nghịch đảo hợp thành $f^{\langle -1\rangle}(x)$ khi và chỉ khi $f(0)=0\neq f'(0)$; khi đó $f^{\langle -1\rangle}(x)$ là duy nhất. Nói thêm: nếu $g(x)=\sum_{k\geq 1}g_kx^k$ thỏa mãn $f(g(x))=x$ hoặc $g(f(x))=x$, thì $g(x)=f^{\langle -1\rangle}(x)$.

**Chứng minh**: xét

$$
\begin{aligned}
g(f(x))&=g_1(f_1x+f_2x^2+f_3x^3+\cdots ) \\
&+g_2(f_1x+f_2x^2+\cdots )^2 \\
&+g_3(f_1x+\cdots )^3 \\
&+\cdots \\
&=g_1f_1x+(g_1f_2+g_2f_1^2)x^2+(g_1f_3+2g_2f_1f_2+g_3f_1^3)x^3+\cdots
\end{aligned}
$$

Vì $g(f(x))=x$, có hệ phương trình sau:

$$
\begin{cases}
g_1f_1&=1 \\
g_1f_2+g_2f_1^2&=0 \\
g_1f_3+2g_2f_1f_2+g_3f_1^3&=0 \\
\vdots
\end{cases}
$$

Phương trình đầu tiên chỉ giải được khi $f_1\neq 0$, sau đó lần lượt giải được $g_2,\dots$.

Đặc biệt, xét $f(h(x))=x$. Khi đó $g(f(h(x)))=g(x)$, suy ra $g(x)=g\circ f\circ h(x)=x\circ h(x)=h(x)$.

<span id="công-thức-nghịch-đảo-lagrange"></span>

## Công thức nghịch đảo Lagrange

Cho $f(x),g(x)\in\mathbb{C}\lbrack\lbrack x\rbrack\rbrack$ thỏa mãn $f(g(x))=g(f(x))=x$. Lấy $\Phi(x)\in\mathbb{C}\lbrack\lbrack x\rbrack\rbrack$ hoặc $\Phi(x)\in\mathbb{C}\left(\left(x\right)\right)$. Khi đó

$$
\begin{aligned}
\lbrack x^n\rbrack\Phi(f(x))&=\lbrack x^{n-1}\rbrack\Phi(x)\frac{g'(x)}{g(x)}\left(\frac{x}{g(x)}\right)^n \\
&=\lbrack x^{-1}\rbrack\frac{\Phi(x)g'(x)}{g(x)^{n+1}}.
\end{aligned}
$$

**Chứng minh**:

$$
\begin{aligned}
\lbrack x^n\rbrack\Phi(f(x))&=\operatorname{res}\left(\frac{\Phi(f(x))}{x^{n+1}}\right) \\
&=\operatorname{res}\left(\frac{\Phi(f(g(x)))g'(x)}{g(x)^{n+1}}\right)\cdot \left(\operatorname{ord}(g(x))\right)^{-1} \\
&=\operatorname{res}\left(\frac{\Phi(x)g'(x)}{g(x)^{n+1}}\right).
\end{aligned}
$$

Một số độc giả có thể quen thuộc hơn với phiên bản sau: với $k\in\mathbb{Z}_{\geq 0},n\in\mathbb{Z}_{>0}$, có

$$
\lbrack x^n\rbrack f(x)^k=\frac{k}{n}\lbrack x^{n-k}\rbrack\left(\frac{x}{g(x)}\right)^n
$$

hoặc

$$
\begin{aligned}
\lbrack x^n\rbrack \Phi(f(x))&=\frac{1}{n}\lbrack x^{n-1}\rbrack \Phi'(x)\left(\frac{x}{g(x)}\right)^n \\
&=\frac{1}{n}\lbrack x^{-1}\rbrack\frac{\Phi'(x)}{g(x)^n}.
\end{aligned}
$$

Nhận thấy

$$
\begin{aligned}
\operatorname{res}\left(\frac{\Phi'(x)}{g(x)^n}-n\frac{\Phi(x)g'(x)}{g(x)^{n+1}}\right)&=\operatorname{res}\left(\left(\frac{\Phi(x)}{g(x)^n}\right)'\right) \\
&=0,
\end{aligned}
$$

nên phiên bản này có thể được suy ra từ phần đã chứng minh.

<span id="tài-liệu-tham-khảo"></span>

## Tài liệu tham khảo

1.  Richard P. Stanley and Sergey P. Fomin. Enumerative Combinatorics Volume 2 (Edition 1).
2.  Ira M. Gessel. Lagrange Inversion.
