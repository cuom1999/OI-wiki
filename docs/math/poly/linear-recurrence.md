<span id="&#x7B80;&#x4ECB;"></span>

## Giới thiệu

Dãy truy hồi tuyến tính thuần nhất hệ số hằng, còn gọi là dãy C-finite hoặc C-recursive, là một lớp dãy truy hồi cơ bản thường gặp.

Với dãy $\left(a_j\right)_{j\geq 0}$ và công thức truy hồi

$$
a_n=\sum_{j=1}^{d}c_ja_{n-j},\qquad (n\geq d)
$$

trong đó các $c_j$ không đồng thời bằng không, mục tiêu là tính $a_k$ khi đã biết các giá trị đầu $a_0,\dots ,a_{d-1}$ và các hệ số $c_1,\dots ,c_d$ trong công thức truy hồi. Nếu $k\gg d$, ta muốn có thuật toán nhanh hơn.

Ở đây $\left(a_j\right)_{j\geq 0}$ được gọi là dãy truy hồi tuyến tính thuần nhất hệ số hằng bậc $d$.

<span id="fiduccia-&#x7B97;&#x6CD5;"></span>

### Thuật toán Fiduccia

Thuật toán Fiduccia dùng phép lấy dư đa thức và lũy thừa nhanh để tính $a_k$ trong thời gian $O(\mathsf{M}(d)\log k)$, trong đó $O(\mathsf{M}(d))$ là thời gian nhân hai đa thức bậc $O(d)$.

**Thuật toán**: xây dựng đa thức $\Gamma(x):=x^d-\sum_{j=0}^{d-1}c_{d-j}x^j$ và $A(x):=\sum_{j=0}^{d-1}a_jx^j$. Khi đó

$$
a_k=\left\langle x^k\bmod{\Gamma(x)},A(x)\right\rangle
$$

trong đó định nghĩa $\left\langle \left(\sum_{j=0}^{n-1}f_jx^j\right),\left(\sum_{j=0}^{n-1}g_jx^j\right) \right\rangle :=\sum_{j=0}^{n-1}f_jg_j$ là tích vô hướng.

**Chứng minh**: ta định nghĩa ma trận đồng hành của $\Gamma(x)$ là

$$
C_\Gamma:=
\begin{bmatrix}
&&&c_d \\
1&&&c_{d-1} \\
&\ddots &&\vdots \\
&&1&c_1
\end{bmatrix}
$$

Ta định nghĩa đa thức $b(x):=\sum_{j=0}^{d-1}b_jx^j$ và

$$
B_b:=\begin{bmatrix}b_0&b_1&\cdots &b_{d-1}\end{bmatrix}^{\intercal}
$$

Quan sát rằng

$$
\underbrace{\begin{bmatrix}
&&&c_d \\
1&&&c_{d-1} \\
&\ddots &&\vdots \\
&&1&c_1
\end{bmatrix}}_{C_\Gamma}
\underbrace{\begin{bmatrix}
b_0 \\
b_1 \\
\vdots \\
b_{d-1}
\end{bmatrix}}_{B_b}=
\underbrace{\begin{bmatrix}
c_db_{d-1} \\
b_0+c_{d-1}b_{d-1} \\
\vdots \\
b_{d-2}+c_1b_{d-1}
\end{bmatrix}} _ {B_{xb\bmod{\Gamma}}}
$$

và

$$
\begin{aligned}
C_\Gamma&=\begin{bmatrix}B_{x\bmod{\Gamma}}&B_{x^2\bmod{\Gamma}}&\cdots &B_{x^d\bmod{\Gamma}}\end{bmatrix}, \\
\left(C_\Gamma\right)^2&=\begin{bmatrix}B_{x^2\bmod{\Gamma}}&B_{x^3\bmod{\Gamma}}&\cdots &B_{x^{d+1}\bmod{\Gamma}}\end{bmatrix}, \\
\cdots \\
\left(C_\Gamma\right)^k&=\begin{bmatrix}B_{x^k\bmod{\Gamma}}&B_{x^{k+1}\bmod{\Gamma}}&\cdots &B_{x^{k+d}\bmod{\Gamma}}\end{bmatrix}.
\end{aligned}
$$

Viết truy hồi này dưới dạng ma trận, ta có

$$
\begin{bmatrix}
a_{k} \\
a_{k+1} \\
\vdots \\
a_{k+d-1}
\end{bmatrix}=\underbrace{\begin{bmatrix}
&1&& \\
&&\ddots & \\
&&&1 \\
c_d&c_{d-1}&\cdots &c_1
\end{bmatrix}^k} _ {\left(\left(C_\Gamma\right)^{\intercal}\right)^k=\left(\left(C_\Gamma\right)^{k}\right)^{\intercal}}
\begin{bmatrix}
a_0 \\
a_{1} \\
\vdots \\
a_{d-1}
\end{bmatrix}.
$$

Do đó hàng đầu tiên của $\left(\left(C_\Gamma\right)^{k}\right)^{\intercal}$ là $B_{x^k\bmod{\Gamma}}$. Kết luận suy ra trực tiếp từ định nghĩa của phép nhân ma trận.

<span id="&#x8868;&#x793A;&#x4E3A;&#x6709;&#x7406;&#x51FD;&#x6570;"></span>

### Biểu diễn bằng hàm hữu tỉ

Với dãy $\left(a_j\right)_{j\geq 0}$ ở trên, luôn tồn tại hàm hữu tỉ

$$
\frac{P(x)}{Q(x)}=\sum_{j\geq 0}a_jx^j
$$

với $Q(x)=x^d\Gamma\left(x^{-1}\right)$ và $\deg{P}<d$. Ta gọi nó là "**hàm hữu tỉ**" vì $P(x),Q(x)$ là "**đa thức**".

**Chứng minh**: với $P(x)=\sum_{j=0}^{d-1}p_jx^j$ và $Q(x):=\sum_{j=0}^{d}q_jx^j$, xét định nghĩa hệ số của $\dfrac{P(x)}{Q(x)}=\sum_{j\geq 0}\tilde{q}_jx^j$. Điều này gần như chính là định nghĩa phép "**chia**" chuỗi lũy thừa hình thức:

$$
\tilde{q}_N=
\begin{cases}
p_0q_0^{-1},&\text{ if }N=0, \\
\left(p_N-\sum_{j=1}^{N}q_j\tilde{q}_{N-j}\right)\cdot q_0^{-1},&\text{ else if }N<d, \\
-q_0^{-1}\sum_{j=1}^{d}q_j\tilde{q}_{N-j},&\text{ otherwise}.
\end{cases}
$$

Ta chỉ cần đặt

$$
P(x)=\left(\left(\sum_{j\geq 0}a_jx^j\right)\cdot x^d\Gamma\left(x^{-1}\right)\right)\bmod{x^d}.
$$

Khi đó theo định nghĩa của $\tilde{q}_N$, tất yếu có $\dfrac{P(x)}{Q(x)}=\sum_{j\geq 0}a_jx^j$.

<span id="bostan&#x2013;mori-&#x7B97;&#x6CD5;"></span>

### Thuật toán Bostan-Mori

<span id="&#x8BA1;&#x7B97;&#x5355;&#x9879;"></span>

#### Tính một hạng

Mục tiêu vẫn là: cho các đa thức $P(x),Q(x)$ như trên, tính $\left\lbrack x^k\right\rbrack\dfrac{P(x)}{Q(x)}$.

Thuật toán Bostan-Mori dựa trên lặp Graeffe. Với các đa thức $P(x),Q(x)$ ở trên, ta có

$$
\frac{P(x)}{Q(x)}=\frac{P(x)Q(-x)}{Q(x)Q(-x)}=\frac{U_0(x^2)+xU_1(x^2)}{V(x^2)}.
$$

Vì mẫu số $V(x^2)$ là hàm chẵn, bài toán con chỉ cần xét một nửa tương ứng:

$$
\left\lbrack x^k\right\rbrack\dfrac{P(x)}{Q(x)}=\left\lbrack x^{\left\lfloor k/2\right\rfloor}\right\rbrack \frac{U_{k\bmod{2}}(x)}{V(x)}.
$$

Ta trả giá bằng hai phép nhân đa thức để giảm kích thước bài toán xuống ít nhất một nửa. Khi $k=0$ thì hiển nhiên $\left\lbrack x^0\right\rbrack \dfrac{P(x)}{Q(x)}=\dfrac{P(0)}{Q(0)}$, nên độ phức tạp thời gian giống như trên.

<span id="&#x8BA1;&#x7B97;&#x8FDE;&#x7EED;&#x82E5;&#x5E72;&#x9879;"></span>

#### Tính một đoạn nhiều hạng liên tiếp

Mục tiêu là: cho các đa thức $P(x),Q(x)$ như trên, tính $\left\lbrack x^{\left\lbrack L,R\right)}\right\rbrack\dfrac{P(x)}{Q(x)}$. Trong các phép tính dưới đây, ta chỉ cần xét những hệ số "**có ảnh hưởng**" tới đáp án; đây là điểm then chốt của thuật toán Bostan-Mori.

Ta có thể giả sử $\deg{P}<\deg{Q}$. Nếu không, chỉ cần chia đa thức có dư một lần để đưa bài toán về trường hợp này.

Trước hết xét bài toán đơn giản hơn:

$$
\left\lbrack x^{\left\lbrack L,R\right)}\right\rbrack\frac{1}{Q(x)}=\left\lbrack x^{\left\lbrack L,R\right)}\right\rbrack\frac{1}{Q(x)Q(-x)}\cdot Q(-x).
$$

Ta cần tính $\left\lbrack x^{\left\lbrack L-\deg{Q},R\right)}\right\rbrack\dfrac{1}{Q(x)Q(-x)}$, sau đó nhân một lần và lấy các hệ số của $x^L,\dots ,x^{R-1}$. Đặt $V(x^2)=Q(x)Q(-x)$, khi đó ta chỉ cần tính

$$
\left\lbrack x^{\left\lbrack \left\lceil\frac{L-\deg{Q}}{2}\right\rceil,\left\lceil\frac{R}{2}\right\rceil\right)}\right\rbrack\frac{1}{V(x)}.
$$

Từ đó có thể khôi phục $\left\lbrack x^{\left\lbrack L-\deg{Q},R\right)}\right\rbrack\dfrac{1}{Q(x)Q(-x)}$. Tiếp theo, ta chỉ cần tính $\left\lbrack x^{\left\lbrack L-\deg{P},R\right)}\right\rbrack\dfrac{1}{Q(x)}$ rồi nhân với $P(x)$ một lần là thu được $\left\lbrack x^{\left\lbrack L,R\right)}\right\rbrack\dfrac{P(x)}{Q(x)}$.

Thuật toán trên đã chạy được, nhưng độ phức tạp của mỗi lần đệ quy còn phụ thuộc vào $R-L$. Ta muốn, ít nhất trong phần đệ quy, thoát khỏi sự phụ thuộc vào $R-L$. Cụ thể hơn, trước hết xét việc tính $\left\lbrack x^{\left\lbrack L,L+\deg Q+1\right)}\right\rbrack \dfrac{1}{Q(x)}$. Xét

$$
\left\lbrack x^{\left\lbrack L,L+\deg Q+1\right)}\right\rbrack \frac{1}{Q(x)}=\left\lbrack x^{\left\lbrack L,L+\deg Q+1\right)}\right\rbrack \dfrac{1}{Q(x)Q(-x)}\cdot Q(-x).
$$

Ta cần tính

$$
\left\lbrack x^{\left\lbrack L-\deg Q,L+\deg Q+1\right)}\right\rbrack \dfrac{1}{Q(x)Q(-x)}.
$$

Với $V(x^2)=Q(x)Q(-x)$, ta chỉ cần tính

$$
\left\lbrack x^{\left\lbrack \lceil (L-\deg Q)/2 \rceil,\lceil (L+\deg Q+1)/2 \rceil\right)}\right\rbrack \frac{1}{V(x)}
$$

vì

$$
\left\lbrack x^{k}\right\rbrack\dfrac{1}{Q(x)Q(-x)}=
\begin{cases}
\left\lbrack x^{k/2}\right\rbrack\dfrac{1}{V(x)},&\text{if }k\equiv 0\pmod{2}, \\
0,&\text{otherwise}.
\end{cases}
$$

Ta biết $L+\deg Q$ và $L-\deg Q$ có cùng tính chẵn lẻ, nên

$$
\left\lceil \frac{L+\deg Q+1}{2}\right\rceil -\left\lceil \frac{L-\deg Q}{2}\right\rceil =
\begin{cases}
\deg Q+1,&\text{if }L+\deg Q\equiv 0\pmod{2}, \\
\deg Q,&\text{otherwise}.
\end{cases}
$$

Như vậy có thể viết mã giả:

$$
\begin{array}{ll}
&\textbf{Algorithm }\operatorname{Slice-Coefficients}(Q,L)\text{:} \\
&\textbf{Input}\text{: }Q(x)\in\mathbb{C}\left\lbrack x\right\rbrack,L\in\mathbb{Z}\text{.} \\
&\textbf{Output}\text{: }\left\lbrack x^{\left\lbrack L,L+\deg Q+1\right)}\right\rbrack Q(x)^{-1}\text{.} \\
1&\textbf{if }L\leq 1\textbf{ then return }\left\lbrack x^{\left\lbrack L,L+\deg Q+1\right)}\right\rbrack Q(x)^{-1} \\
&\text{Use other algorithm to compute }Q(x)^{-1} \\
2&V(x^2)\gets Q(x)Q(-x) \\
3&k\gets \left\lceil \frac{L-\deg Q}{2}\right\rceil \\
4&(t_k,\dots ,t_{k+\deg Q})\gets \operatorname{Slice-Coefficients}\left(V,k\right) \\
5&T(x)\gets x^{(L-\deg Q)\bmod{2}}\sum_{j=0}^{\deg Q}t_{j+k}x^{2j} \\
6&\textbf{return }\left\lbrack x^{\left\lbrack \deg Q,2\deg Q+1\right)}\right\rbrack T(x)Q(-x)
\end{array}
$$

Tuy nhiên chỉ thuật toán này vẫn chưa đủ; ta cần tìm lại một biểu diễn hàm hữu tỉ và tính thêm nhiều hệ số hơn.

<span id="&#x627E;&#x5230;&#x65B0;&#x7684;&#x6709;&#x7406;&#x51FD;&#x6570;&#x8868;&#x793A;"></span>

#### Tìm biểu diễn hàm hữu tỉ mới

Ta biết chính $Q(x)$ và một đoạn hệ số liên tiếp của $Q(x)^{-1}$, chẳng hạn $\left\lbrack x^{\left\lbrack L,L+\deg Q\right)}\right\rbrack Q(x)^{-1}$ với $L\geq 0$. Ta muốn tính $\left\lbrack x^{\left\lbrack L+\deg Q,L+2\deg Q\right)}\right\rbrack Q(x)^{-1}$. Điều này tương đương với việc tìm một $P(x)$ nào đó, $\deg P< \deg Q$, sao cho $\dfrac{P(x)}{Q(x)}$ có $\deg Q$ hạng đầu bằng $\left\lbrack x^{\left\lbrack L,L+\deg Q\right)}\right\rbrack Q(x)^{-1}$. Nói ngắn gọn: quan hệ truy hồi, tức mẫu số của hàm hữu tỉ, không đổi; việc ta làm chỉ là thay các giá trị đầu, tức tử số của hàm hữu tỉ.

Cụ thể, xét

$$
\frac{P(x)}{Q(x)}=\sum_{j\geq 0}a_jx^j.
$$

Nay ta muốn đẩy truy hồi tiến thêm $n$ hạng, tức là

$$
\sum_{j\geq n}a_jx^{j-n}=\frac{P(x)}{Q(x)x^n}-\frac{Q(x)\sum_{j=0}^{n-1}a_jx^j}{Q(x)x^n}.
$$

Trước hết dùng một lần $\operatorname{Slice-Coefficients}(Q,L-\deg{P})$ để tính $\left\lbrack x^{\left\lbrack L-\deg{P},L-\deg{P}+\deg{Q}+1\right)}\right\rbrack Q(x)^{-1}$. Sau đó mở rộng và ghép để có $\left\lbrack x^{\left\lbrack L-\deg{P},L+\deg{Q}\right)}\right\rbrack Q(x)^{-1}$, rồi tính lại một tử số sao cho

$$
\frac{\widetilde{P}(x)}{Q(x)}=\sum_{j\geq 0}\left(\left\lbrack x^{L+j}\right\rbrack \frac{P(x)}{Q(x)}\right)x^j.
$$

Cuối cùng dùng phép chia chuỗi lũy thừa hình thức để tính $\left\lbrack x^{\left\lbrack 0,R-L\right)}\right\rbrack\dfrac{\widetilde{P}(x)}{Q(x)}$. Độ phức tạp thời gian là $O(\mathsf{M}(d)\log L+\mathsf{M}(R-L))$.

<span id="&#x53C2;&#x8003;&#x6587;&#x732E;"></span>

## Tài liệu tham khảo

1.  Alin Bostan, Ryuhei Mori. [A Simple and Fast Algorithm for Computing the $N$-th Term of a Linearly Recurrent Sequence](https://arxiv.org/abs/2008.08822).
