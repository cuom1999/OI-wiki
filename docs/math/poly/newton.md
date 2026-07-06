<span id="mô-tả"></span>
## Mô tả

Cho đa thức $G\left(x, y\right)$. Biết đa thức $f\left(x\right)$ thỏa mãn:

$$
G\left(x, f\left(x\right)\right)\equiv 0\pmod{x^{n}}
$$

và tồn tại một giá trị $f_1$ sao cho $G\left(x, y\right)$ thỏa các điều kiện sau:

-   $G(0, f_1) = 0$;
-   $\dfrac{\partial G}{\partial y}(0, f_1) \neq 0$.

Yêu cầu là tìm $f\left(x\right)$ theo modulo $x^{n}$.

<span id="newtons-method"></span>
## Phương pháp Newton

Xét cách nhân đôi độ dài.

Trước hết, khi $n=1$, nghiệm của $\left[x^{0}\right]G\left(x, f\left(x\right)\right)=0$ cần được tìm riêng; $f_1$ trong giả thiết chính là một nghiệm như vậy.

Giả sử hiện đã có nghiệm $f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)$ theo modulo $x^{\left\lceil\frac{n}{2}\right\rceil}$, và cần tìm nghiệm $f\left(x\right) = f_n\left(x\right)$ theo modulo $x^{n}$.

Khai triển Taylor $G\left(x, f(x)\right)$ theo $f(x)$ tại $f(x)=f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)$ cho:

$$
\sum_{i=0}^{+\infty}\frac{\frac{\partial^i G}{\partial y^i}\left(x, f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right)}{i!}\left(f\left(x\right)-f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right)^{i}\equiv 0\pmod{x^{n}}
$$

Vì hạng khác không bậc thấp nhất của $f\left(x\right)-f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)$ có bậc ít nhất là $\left\lceil\frac{n}{2}\right\rceil$, nên:

$$
\forall 2\leqslant i:\left(f\left(x\right)-f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right)^{i}\equiv 0\pmod{x^{n}}
$$

Do đó:

$$
\begin{aligned}
\sum_{i=0}^{+\infty}\frac{\frac{\partial^i G}{\partial y^i}\left(x, f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right)}{i!}\left(f\left(x\right)-f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right)^{i}&\equiv G\left(x, f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right)+\frac{\partial G}{\partial y}\left(x, f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right)\left[f\left(x\right)-f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right]\\
&\equiv 0\pmod{x^{n}}
\end{aligned}
$$

$$
f_n\left(x\right)\equiv f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)-\frac{G\left(x, f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right)}{\frac{\partial G}{\partial y}\left(x, f_{\left\lceil\frac{n}{2}\right\rceil}\left(x\right)\right)}\pmod{x^{n}}
$$

hoặc

$$
f_{2n}\left(x\right)\equiv f_n\left(x\right)-\frac{G\left(x, f_n\left(x\right)\right)}{\frac{\partial G}{\partial y}\left(x, f_n\left(x\right)\right)}\pmod{x^{2n}}
$$

<span id="ví-dụ"></span>
## Ví dụ

<span id="nghịch-đảo-đa-thức"></span>
### [Nghịch đảo đa thức](./elementary-func.md#nghịch-đảo-đa-thức)

Giả sử hàm đã cho là $h\left(x\right)$, đặt:

$$
G\left(x, y\right)=\frac{1}{y}-h\left(x\right)
$$

Áp dụng phương pháp Newton thu được:

$$
\begin{aligned}
    f_{2n}\left(x\right)&\equiv f_{n}\left(x\right)-\frac{1/f_{n}\left(x\right)-h\left(x\right)}{-1/f_{n}^{2}\left(x\right)}&\pmod{x^{2n}}\\
    &\equiv 2f_{n}\left(x\right)-f_{n}^{2}\left(x\right)h\left(x\right)&\pmod{x^{2n}}
\end{aligned}
$$

Độ phức tạp thời gian:

$$
T\left(n\right)=T\left(\frac{n}{2}\right)+O\left(n\log{n}\right)=O\left(n\log{n}\right)
$$

<span id="khai-căn-đa-thức"></span>
### [Khai căn đa thức](./elementary-func.md#khai-căn-đa-thức)

Giả sử hàm đã cho là $h\left(x\right)$, đặt:

$$
G\left(x, y\right)=y^{2}-h\left(x\right)\equiv 0
$$

Áp dụng phương pháp Newton thu được:

$$
\begin{aligned}
    f_{2n}\left(x\right)&\equiv f_{n}\left(x\right)-\frac{f_{n}^{2}\left(x\right)-h\left(x\right)}{2f_{n}\left(x\right)}&\pmod{x^{2n}}\\
    &\equiv\frac{f_{n}^{2}\left(x\right)+h\left(x\right)}{2f_{n}\left(x\right)}&\pmod{x^{2n}}
\end{aligned}
$$

Độ phức tạp thời gian:

$$
T\left(n\right)=T\left(\frac{n}{2}\right)+O\left(n\log{n}\right)=O\left(n\log{n}\right)
$$

<span id="hàm-mũ-của-đa-thức"></span>
### [Hàm mũ của đa thức](./elementary-func.md#hàm-logarit-và-hàm-mũ-của-đa-thức)

Giả sử hàm đã cho là $h\left(x\right)$, đặt:

$$
G\left(x, y\right)=\ln{y}-h\left(x\right)
$$

Áp dụng phương pháp Newton thu được:

$$
\begin{aligned}
    f_{2n}\left(x\right)&\equiv f_{n}\left(x\right)-\frac{\ln{f_{n}\left(x\right)}-h\left(x\right)}{1/f_{n}\left(x\right)}&\pmod{x^{2n}}\\
    &\equiv f_{n}\left(x\right)\left(1-\ln{f_{n}\left(x\right)}+h\left(x\right)\right)&\pmod{x^{2n}}
\end{aligned}
$$

Độ phức tạp thời gian:

$$
T\left(n\right)=T\left(\frac{n}{2}\right)+O\left(n\log{n}\right)=O\left(n\log{n}\right)
$$

<span id="minh-họa-tính-tay"></span>
## Minh họa tính tay

Để dễ hiểu, phần này đưa ra vài ví dụ minh họa quy trình thuật toán.

<span id="căn-bậc-hai-của-đa-thức-hệ-số-phức-theo-modulo-một-lũy-thừa-đa-thức"></span>
### Căn bậc hai của đa thức hệ số phức theo modulo một lũy thừa đa thức

Giả sử $h$ là một đa thức phức không chia hết cho $x$ (tức có hệ số tự do). Cần tìm căn bậc hai của nó theo modulo $x^n$.

Xét phương trình:

$$
G\left(f(x)\right) = f^2(x)-h(x) \equiv 0\pmod{x^{n}}
$$

Khai triển Taylor $G$ thu được công thức sau. Vì khai triển theo $f$, các đạo hàm đều là đạo hàm riêng theo $f$; $x$ được xem là hằng số.

$$
G(f(x)) = \sum_{i=0}^{+\infty}\frac{G^{\left(i\right)}\left(f_{0}(x)\right)}{i!}\left(f(x)-f_{0}(x)\right)^{i}
= G(f_0(x)) + 2f_0(x)(f(x)-f_0(x)) + (f(x)-f_0(x))^2
$$

Tính bằng cách nhân đôi. Giả sử các kết quả trung gian trong quá trình nhân đôi là $f_0(x), f_1(x), \ldots, f_j(x)$; nói chặt chẽ hơn, $f_j(x)$ là một đa thức phức thỏa $G(f_j(x))\equiv 0\pmod{x^{2^j}}$, đồng thời để bảo đảm tính duy nhất nó thỏa hai điều kiện sau:

-   bậc của $f_{j}(x)$ nhỏ hơn $2^j$;
-   $f_{j+k}(x)-f_j(x)\equiv 0\pmod{x^{2^j}}$ với mọi $k$.

Thay $f_{j+1}(x)$ và $f_j(x)$ vào công thức trên thu được:

$$
G(f_{j+1}(x)) = G(f_j(x)) + 2f_j(f_{j+1}(x)-f_j(x)) + (f_{j+1}(x)-f_{j}(x))^2  \equiv 0 \pmod{x^{2^{j+1}}}
$$

Theo điều kiện truy hồi, $f_{j+1}(x)-f_j(x)$ phải là bội của $x^{2^j}$. Vì vậy:

$$
f_{j+1}(x) \equiv f_j(x) - \frac{f_j^2(x)-h(x)}{2f_j(x)} \equiv \frac{f_j(x)^2 + h(x)}{2f_j(x)} \pmod{x^{2^{j+1}}}
$$

Nếu $f_j(x)$ tồn tại, thì $2f_j(x)$ không chia hết cho $x$ (có hệ số tự do), nên nó có nghịch đảo theo modulo $x^{2^{j+1}}$. Do đó dãy $f_0,f_1\ldots,f_j$ tồn tại khi và chỉ khi $f_0$ tồn tại. Với đa thức phức $h(x)$ không chia hết cho $x$, căn bậc hai của nó theo modulo $x$ luôn tồn tại, vì $h(x)$ sau khi lấy modulo $x$ chỉ là một số phức khác $0$ thông thường, luôn có hai căn bậc hai. Vì vậy thuật toán này dùng được cho mọi $h(x)$ có hệ số tự do.

Lấy $h(x)=x+1$ làm ví dụ:

-   $f_0(x)=1$,$f_1(x)=\dfrac{1^2+x+1}{2\times 1}\mod x^2 = \dfrac{1}{2}x+1$,$f_2(x)=\dfrac{\left(\dfrac{1}{2}x+1\right)^2+x+1}{2\times \left(\dfrac{1}{2}x+1\right)}\mod x^4 = \dfrac{1}{16}x^3-\dfrac{1}{8}x^2+\dfrac{1}{2}x+1$,$\ldots$
-   $f_0(x)=-1$,$f_1(x)=\dfrac{(-1)^2+x+1}{2\times (-1)}\mod x^2 = -\dfrac{1}{2}x-1$,$\ldots$ (bằng đối của dãy trước)

Kiểm chứng trực tiếp cho thấy cả hai đều là các dãy đa thức căn bậc hai đúng theo modulo tương ứng.

<span id="căn-bậc-hai-của-số-nguyên-theo-modulo-lũy-thừa-của-số-nguyên-tố"></span>
### Căn bậc hai của số nguyên theo modulo lũy thừa của số nguyên tố

Thuật toán lặp Newton cũng có thể chuyển sang trường hợp số nguyên modulo lũy thừa của một số nguyên tố.
Giả sử $h$ là một số nguyên "thuận tiện" không chia hết cho $3$. ("Thuận tiện" nghĩa là có nghiệm; điều kiện cụ thể sẽ nêu sau.) Giả sử cần tính căn bậc hai $f$ của $h$ theo modulo $3^n$. Xét phương trình:

$$
G\left(f\right) = f^2-h \equiv 0\pmod{3^{n}}
$$

Khai triển Taylor $G$:

$$
G(f) = \sum_{i=0}^{+\infty}\frac{G^{\left(i\right)}\left(f_{0}\right)}{i!}\left(f-f_{0}\right)^{i}
= G(f_0) + 2f_0(f-f_0) + (f-f_0)^2
$$

Tính bằng cách nhân đôi. Giả sử các kết quả trung gian thu được là $f_0, f_1, \ldots, f_j$; nói chặt chẽ hơn, $f_j$ là một số nguyên thỏa $G(f_j)\equiv 0\pmod{3^{2^j}}$, đồng thời để bảo đảm tính duy nhất nó thỏa hai điều kiện sau:

-   $0 < f_{j} < 3^{2^j}$;
-   $f_{j+k}-f_j\equiv 0\pmod{3^{2^j}}$ với mọi $k$.

Thay $f_{j+1}$ và $f_j$ vào công thức trên:

$$
G(f_{j+1}) = G(f_j) + 2f_j(f_{j+1}-f_j) + (f_{j+1}-f_{j})^2  \equiv 0 \pmod{3^{2^{j+1}}}
$$

Theo điều kiện truy hồi, $f_{j+1}-f_j$ phải là bội của $3^{2^j}$. Vì vậy:

$$
f_{j+1} \equiv f_j - \frac{f_j^2-h}{2f_j} \equiv \frac{f_j^2 + h}{2f_j} \pmod{3^{2^{j+1}}}
$$

Nếu $f_j$ tồn tại, thì $2f_j$ không chia hết cho $3$, nên nó có nghịch đảo modulo $3^{2^{j+1}}$. Do đó dãy $f_0,f_1\ldots,f_j$ tồn tại khi và chỉ khi $f_0$ tồn tại. Một số nguyên $h$ không chia hết cho $3$ hoặc không có căn bậc hai modulo $3$, hoặc có hai căn. Vì vậy việc $h$ có căn bậc hai modulo $3$ là điều kiện duy nhất để toàn bộ thuật toán chạy được.

Ví dụ tính cụ thể với $h=46$.

-   $f_0=1$,$f_1=\dfrac{1^2+46}{2\times 1}\mod 9 = 1$,$f_2=\dfrac{1^2+46}{2\times 1}\mod 81 = 64$,$f_3=\dfrac{64^2+46}{2\times 64}\mod 6561 = 955$,$\ldots$
-   $f_0=2$,$f_1=\dfrac{2^2+46}{2\times 2}\mod 9 = 8$,$f_2=\dfrac{8^2+46}{2\times 8}\mod 81 = 17$,$f_3=\dfrac{17^2+46}{2\times 17}\mod 6561 = 5606$,$\ldots$ (bằng đối của dãy trước)

Kiểm chứng trực tiếp cho thấy cả hai đều là các dãy căn bậc hai đúng theo modulo tương ứng.

<span id="chứng-minh-đại-số"></span>
## Chứng minh đại số

Phần này mở rộng nội dung phía trên và dùng ngôn ngữ đại số trừu tượng để chứng minh rằng chỉ cần $f$ thỏa điều kiện nghiệm ban đầu, phương pháp Newton sẽ cho nghiệm với mọi $n$, đồng thời có thể thu được toàn bộ nghiệm.

<span id="chứng-minh-sự-tồn-tại-nghiệm"></span>
### Chứng minh sự tồn tại nghiệm

???+ note "Bổ đề 1"
    Cho [miền nguyên](../algebra/ring-theory.md#miền-nguyên) $R$ có đa thức hoặc [chuỗi lũy thừa hình thức](../algebra/ring-theory.md#vành-chuỗi-lũy-thừa-hình-thức) $f(X) = \sum_{i\geq 0}a_iX^i$ và $r,p\in R$ sao cho $f(r)\in Rp$ (tức $r$ là nghiệm của $f(X)$ theo modulo $p$) và $f'(r)\in R$ khả nghịch theo modulo $p$. Trong đó $f'(X) := \sum_{i\geq 0}(i+1)a_{i+1}X^i$ là **đạo hàm hình thức** của $f(X)$. Khi đó $f\left(r-\dfrac{f(r)}{f'(r)}\right) \equiv 0\pmod {p^2}$.

??? note "Chứng minh"
    Với mọi $s\in R$,
    
    $$
    \begin{aligned}
    f(r+sp) &= \sum_{i\geq 0}a_i(r+sp)^i \\
    &= \sum_{i\geq 0}a_ir^i + sp\sum_{i\geq 1}ia_ir^{i-1} + s^2p^2\left(\ldots\right) \\
    &= f(r) + spf'(r) + s^2p^2\left(\frac{f''(r)}{2!} + \cdots\right),
    \end{aligned}
    $$
    
    nên
    
    $$
    f(r+sp) \in Rp^2 \iff f(r)+f'(r)sp \in Rp^2
    $$
    
    Vì $f(r)\in Rp$ và $f'(r)$ khả nghịch, chỉ cần lấy $sp = -\dfrac{f(r)}{f'(r)}$; trong đó $\dfrac{1}{f'(r)}$ là nghịch đảo theo modulo $p^2$. Do $f'(r)$ khả nghịch theo modulo $p$, nó cũng có nghịch đảo theo modulo $p^2$: giả sử tồn tại $a,b,c\in R$ sao cho $af'(r) = bp+1$ và $f(r)=cp$, khi đó $\left(a^2f'(r)-2\right)f'(r) = b^2p^2+1$, nên có thể lấy $s=c(2-a^2f'(r))$.

Với vành đa thức $k[X]$ trên trường $k$, giả sử có $G(X, Y)\in k[X, Y]$ và $f_n\in k[X]$ sao cho $G(X, f_n(X))\in k[X]X^n$. Áp dụng bổ đề 1 thu được

$$
G\left(X, f_n(X) - \frac{G(X, f_n(X))}{\frac{\partial G}{\partial Y}(X, f_n(X))} \right)\equiv 0 \pmod {X^{2n}}
$$

Điều kiện ban đầu cho phép nhân đôi chỉ cần tồn tại $f_1\in k$ sao cho $G(X, f_1)\equiv 0\pmod X$ và $\dfrac{\partial G}{\partial Y}(X, f_1)\not\equiv 0\pmod X$. Điều kiện sau bảo đảm $\dfrac{\partial G}{\partial Y}$ có hệ số tự do khác không; đồng thời vì $X\left| \dfrac{G(X, f_n(X))}{\frac{\partial G}{\partial Y}(X, f_n(X))} \right.$, nên với mọi $n$, $\dfrac{\partial G}{\partial Y}(X, f_n)$ luôn khả nghịch theo modulo $X^n$, tức thỏa điều kiện của lần lặp tiếp theo.

<span id="chứng-minh-thu-được-toàn-bộ-nghiệm"></span>
### Chứng minh thu được toàn bộ nghiệm

???+ note "Bổ đề 2"
    Nếu $R$ là [UFD](../algebra/ring-theory.md#miền-phân-tích-duy-nhất), và $f,r,p$ được định nghĩa như trong bổ đề 1, thì $r-\dfrac{f(r)}{f'(r)}$ do bổ đề 1 đưa ra là giá trị $x$ duy nhất theo modulo $p^{2}$ thỏa hai điều kiện sau:
    
    -   $f(x)\in Rp^{2}$
    -   $x-r\in Rp$
    
    tức là
    
    $$
    \forall x\in R,\qquad p^2\mid f(x)\wedge p\mid (x-r) \implies x\equiv r-\dfrac{f(r)}{f'(r)} \pmod {p^2}
    $$

??? note "Chứng minh"
    Đặt $s = -\dfrac{f(r)}{f'(r)p}$ và $u = r+sp$. Bổ đề 1 bảo đảm $u$ thỏa hai điều kiện, và $f(r) + f'(r)sp \in Rp^{2}$.
    Giả sử $v$ là một giá trị thỏa các điều kiện trên, khi đó $v = r+tp$ và $f(r) + f'(r)tp \in Rp^{2}$.
    Do đó $f'(r)(t-s)p\in Rp^{2}$ và $v-u\in Rp^{2}$.

Phương pháp Newton cho phép thu được toàn bộ nghiệm modulo $X^{2^n}$. Giả sử $G(X, h)\equiv 0\pmod {X^{2^n}}$. Đặt $h_{2^i} := h\pmod {X^{2^i}}$, rồi lấy $f_1 = h_1$ và áp dụng phương pháp Newton. Theo bổ đề 2, $f_{2^i} \equiv h_{2^i}\pmod {X^{2^i}}$, nên $f_{2^n} = h$.

Lập luận trên cũng cho thấy, khi $\dfrac{\partial G}{\partial y}(0, y)$ luôn khả nghịch, số nghiệm của $G(X, f)\equiv 0\pmod {X^n}$ bằng số nghiệm của $G(0, f)\equiv 0\pmod X$. Kết luận này không hề tầm thường; xem ví dụ dưới đây.

??? example "Ví dụ số nghiệm tăng theo bậc khi phương pháp Newton không áp dụng được"
    Theo modulo $X$, $X^2$ chỉ có một căn bậc hai là $0$, nhưng theo modulo $X^4$, các căn bậc hai của $X^2$ gồm $X, -X, X^3+X, \ldots$.
