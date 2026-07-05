<span id="&#x591A;&#x9879;&#x5F0F;&#x4E0E;&#x751F;&#x6210;&#x51FD;&#x6570;"></span>

## Đa thức và hàm sinh

Thao tác với các đa thức có số hạng hữu hạn hoặc vô hạn là một nội dung quan trọng trong toán học OI, đặc biệt là trong hàm sinh.

Các thuật toán đa thức dựa trên nền tảng [biến đổi Fourier nhanh](./fft.md) trao cho thí sinh lập trình khả năng thao tác trực tiếp với hàm sinh.

<span id="&#x57FA;&#x672C;&#x6982;&#x5FF5;"></span>

## Khái niệm cơ bản

Với tổng $\sum a_nx^n$, nếu tổng chỉ gồm hữu hạn số hạng, ta gọi nó là đa thức, ký hiệu $f(x)=\sum_{n=0}^m a_nx^n$.

Tổng gồm một số đếm được các số hạng được gọi là chuỗi. Trong tổng $\sum_{n=0}^\infty a_nx^n$, mỗi số hạng đều là một lũy thừa không âm của biến nhân với một hệ số hằng; chuỗi có dạng này được gọi là chuỗi lũy thừa.

Khi nghiên cứu số học đa thức, trước hết ta xét các đa thức đơn giản hơn; khái niệm chuỗi lũy thừa chỉ dùng để tiện cho việc hiểu. Trong giải tích toán học, tính hội tụ hay phân kỳ của chuỗi lũy thừa sẽ được nghiên cứu sâu hơn.

Định nghĩa tổng quát về vành, trường và các cấu trúc dẫn xuất của chúng xem tại [khái niệm cơ bản của đại số trừu tượng](../algebra/basic.md).

Với một vành tổng quát $R$, định nghĩa **vành đa thức** (polynomial ring) trên $R$ là $R[x]$.

Mỗi phần tử $f$ được gọi là một **đa thức** (polynomial) trên $R$, và có thể biểu diễn dưới dạng

$$
f=\left<f_0,f_1,f_2,\cdots,f_n\right>\quad(f_0,f_1,f_2,\cdots,f_n\in R)
$$

Nói cách khác, ta định nghĩa trực tiếp đa thức là dãy các hệ số. Cũng có thể viết thành

$$
f(x)=f_0+f_1x+f_2x^2+\cdots+f_nx^n
$$

Ở đây ta xem $x$ chỉ là một **ký hiệu hình thức**, một dấu hiệu để nhận diện vị trí của hệ số.

Nếu ta còn cho phép có vô hạn số hạng, tức là

$$
f(x)=f_0+f_1x+f_2x^2+\cdots
$$

thì thu được **vành chuỗi lũy thừa hình thức** (formal power series ring) $R[[x]]$, trong đó mỗi phần tử $f$ được gọi là **chuỗi lũy thừa hình thức** (formal power series), dưới đây gọi tắt là chuỗi lũy thừa.

<span id="&#x591A;&#x9879;&#x5F0F;&#x7684;&#x6B21;&#x6570;"></span>

### Bậc của đa thức

Với một đa thức $f(x)$, bậc của số hạng có bậc cao nhất được gọi là **bậc** (degree) của đa thức, ký hiệu $\operatorname{deg}{f}$.

<span id="&#x591A;&#x9879;&#x5F0F;&#x7684;&#x4E58;&#x6CD5;"></span>

### Phép nhân đa thức

Phép toán cốt lõi nhất là phép nhân hai đa thức, tức là cho các đa thức $f(x)$ và $g(x)$:

$$
\begin{alignedat}{3}
f(x)&=a_0+a_1x+\dots+a_nx^n\quad \quad &(1)\\
g(x)&=b_0+b_1x+\dots+b_mx^m\quad \quad &(2)
\end{alignedat}
$$

Cần tính đa thức $Q(x)=f(x)\cdot g(x)$:

$$
\boxed {Q(x) = \sum \limits_ {i = 0} ^ n \sum \limits_ {j = 0 } ^ m a_i b_j x ^ {i + j}} = c_0 + c_1 x + \dots + c_ {n + m} x ^ {n + m}
$$

Phép nhân đa thức hoặc chuỗi lũy thừa thỏa mãn tính kết hợp và tính phân phối đối với phép cộng. Nếu $R$ là vành giao hoán hoặc vành có đơn vị, phép nhân tương ứng có tính giao hoán và phần tử đơn vị.

Nếu trên $R$ tồn tại căn đơn vị bậc $2^n$, [biến đổi Fourier nhanh](./fft.md) cho phép tính tích của hai đa thức bậc $2^n$ trong thời gian $O(n2^n)$ thay vì $O(2^{2n})$.

<span id="&#x590D;&#x5408;"></span>

### Phép hợp thành

Định nghĩa lũy thừa của phần tử $f$ trong $R[[x]]$ là

$$
f^1=f,f^k=f^{k-1}\times f
$$

Trên cơ sở đó, định nghĩa phép hợp thành của hai phần tử $f,g$ trong $R[[x]]$ là

$$
(f\circ g)(x)=f(g(x))=f_0+\sum_{k=1}^{+\infty}f_kg^k(x)
$$

Ta quy ước $f\circ g$ tồn tại khi và chỉ khi $f$ có hữu hạn số hạng hoặc $g_0=0$, như vậy không cần xét giới hạn trên $R$.

$\circ$ thỏa mãn tính kết hợp khi cả $(f\circ g)\circ h$ và $f\circ (g\circ h)$ đều tồn tại, nhưng không thỏa mãn tính giao hoán. Khi $R$ là vành có đơn vị, $\circ$ có phần tử đơn vị $1\times x$.

Phép hợp thành đa thức và nghịch đảo hợp thành có cách làm $\Theta(n\log^2 n)$, được Yasunori Kinoshita và Li Baitian đề xuất năm 2024; xem chi tiết tại [hợp thành chuỗi lũy thừa hình thức | nghịch đảo hợp thành](./comp-rev.md).

<span id="&#x5BFC;&#x6570;"></span>

### Đạo hàm

Dù một vành tổng quát thậm chí có thể không tồn tại giới hạn, ta vẫn có thể định nghĩa **đạo hàm hình thức** (formal derivative) của chuỗi lũy thừa hình thức là

$$
\left(\sum_{k=0}^{+\infty}f_kx^k\right)'=\sum_{k=1}^{+\infty}kf_kx^{k-1}
$$

trong đó

$$
kf_k=\underbrace{f_k+f_k+\cdots+f_k}_{k \text{ lần } f_k}
$$

Những quy tắc đạo hàm cơ bản, gồm quy tắc cộng, quy tắc nhân và quy tắc dây chuyền khi phép hợp thành được phép, vẫn đúng.

Nếu trên $R$ cho phép thực hiện phép chia, ta cũng có thể định nghĩa tương tự **nguyên hàm hình thức** (formal indefinite integral) của chuỗi lũy thừa hình thức.

<span id="&#x4E58;&#x6CD5;&#x9006;&#x5143;"></span>

### Nghịch đảo nhân

Từ ví dụ

$$
\dfrac{1}{1-x}=1+x+x^2+\cdots
$$

có thể thấy nghịch đảo của một đa thức có thể khai triển thành một chuỗi vô hạn. Nghịch đảo tồn tại khi và chỉ khi hạng tự do khác $0$, và nghịch đảo cũng có hạng tự do khác $0$.

Vì vậy định nghĩa: đối với chuỗi lũy thừa hình thức $f$, nếu $f_0\not=0$, **nghịch đảo nhân** (multiplicative inversion) $f^{-1}$ của nó là một chuỗi lũy thừa hình thức khác thỏa mãn

$$
f\times f^{-1}=f^{-1}\times f=1
$$

Khai triển công thức này theo định nghĩa phép nhân chuỗi lũy thừa hình thức, ta được công thức truy hồi cho các hệ số của $f^{-1}$:

$$
f^{-1}_0=\dfrac{1}{f_0},f^{-1}_n=\dfrac{-1}{f_0}\sum_{k=0}^{n-1}f^{-1}_kf_{n-k}
$$

Tính trực tiếp $n$ số hạng đầu bằng công thức truy hồi mất $O(n^2)$; [sử dụng FFT](./elementary-func.md#%E5%A4%9A%E9%A1%B9%E5%BC%8F%E6%B1%82%E9%80%86) có thể thu được thuật toán $O(n\log n)$.

???+ note "Ghi chú"
    Dễ thấy rằng nghịch đảo của $f(x)$ chính là khai triển Maclaurin vô hạn số hạng của $\frac{1}{f(x)}$, tức khai triển Taylor vô hạn số hạng tại $x=0$.

<span id="&#x5E38;&#x89C1;&#x7684;&#x5E42;&#x7EA7;&#x6570;&#x5C55;&#x5F00;&#x5F0F;"></span>

### Các khai triển chuỗi lũy thừa thường gặp

Trong giải tích toán học, một hàm một biến khả vi đến một số bậc nào đó tại một điểm hoặc trên một khoảng có thể được khai triển thành đa thức trong phạm vi tương ứng; nói chung gọi là khai triển Taylor. Nếu khai triển tại $0$, nó cũng được gọi là khai triển Maclaurin.

Nếu khả vi vô hạn bậc, có thể thực hiện khai triển thành chuỗi lũy thừa. Trường hợp thường gặp nhất vẫn là khai triển tại $0$.

Trong hàm biến phức, một số hàm tuy không thể khai triển Taylor tại điểm kỳ dị, nhưng có thể khai triển Laurent.

Những đẳng thức dưới đây chỉ đúng khi chuỗi lũy thừa hội tụ, và không đúng khi không hội tụ. Ở đây chỉ liệt kê các khai triển, không thảo luận miền hội tụ.

Hai khai triển cơ bản là của hàm mũ và hàm lũy thừa:

$$
\mathrm{e}^x=1+x+\frac{1}{2!}x^2+\ldots+\frac{1}{n!}x^n+\ldots
$$

$$
(1+x)^a=1+ax+\frac{a(a-1)}{2!}x^2+\ldots+\frac{a(a-1)\ldots(a-n+1)}{n!}x^n+\ldots
$$

Nhiều khai triển khác thường được suy ra bằng biến đổi hai khai triển trên. Cosin và sin thu được bằng cách thay số phức vào hàm mũ:

$$
\cos x=1-\frac{1}{2!}x^2+\frac{1}{4!}x^4+\ldots+\frac{(-1)^n}{(2n)!}x^{2n}+\ldots
$$

$$
\sin x=x-\frac{1}{3!}x^3+\frac{1}{5!}x^5+\ldots+\frac{(-1)^n}{(2n+1)!}x^{2n+1}+\ldots
$$

Logarit, arctan và arcsin thu được từ phép tích phân:

$$
\frac{1}{1+x}=1-x+x^2+\ldots+{(-1)}^n x^n+\ldots
$$

$$
\ln(1+x)=x-\frac{1}{2}x^2+\frac{1}{3}x^3+\ldots+\frac{{(-1)}^{n-1}}{n}x^n+\ldots
$$

$$
\frac{1}{1+x^2}=1-x^2+x^4+\ldots+{(-1)}^n x^{2n}+\ldots
$$

$$
\arctan x=x-\frac{1}{3}x^3+\frac{1}{5}x^5+\ldots+\frac{{(-1)}^{n}}{2n+1}x^{2n+1}+\ldots
$$

$$
\frac{1}{\sqrt{1+x}}=1-\frac{1}{2}x+\frac{3}{8}x^2+\ldots+{(-1)}^n\frac{(2n)!}{{(n!)}^2 4^n} x^{n}+\ldots
$$

$$
\frac{1}{\sqrt{1-x^2}}=1+\frac{1}{2}x^2+\frac{3}{8}x^4+\ldots+\frac{(2n)!}{{(n!)}^2 4^n} x^{2n}+\ldots
$$

$$
\arcsin x=x+\frac{1}{6}x^3+\frac{3}{40}x^5+\ldots+\frac{(2n)!}{{(n!)}^2(2n+1)4^n} x^{2n+1}+\ldots
$$

<span id="&#x590D;&#x5408;&#x9006;"></span>

### Nghịch đảo hợp thành

**Nghịch đảo hợp thành** (compound inversion) là sự mở rộng của khái niệm hàm ngược trên vành chuỗi lũy thừa hình thức.

Đối với chuỗi lũy thừa hình thức $f$ thỏa mãn $f_0=0$ và $f_1\not=0$, nghịch đảo hợp thành của nó là chuỗi lũy thừa hình thức $g$ thỏa mãn $g(f(x))=f(g(x))=x$. Từ đảo ngược Lagrange, với mọi số nguyên $n,k$ có

$$
n[x^n]f^k=k[x^{n-k}]\left(\dfrac{x}{g}\right)^n
$$

trong đó $[x^k]f(x)$ biểu thị hệ số của $f(x)$ tại $x^k$.

<span id="&#x591A;&#x9879;&#x5F0F;&#x6574;&#x9664;"></span>

### Tính chia hết của đa thức

Đối với hai đa thức $f(x)$ và $g(x)$, nếu tồn tại một đa thức $h(x)$ sao cho:

$$
f(x)=g(x)h(x)
$$

thì đa thức $g(x)$ chia hết đa thức $f(x)$.

Hiển nhiên, đa thức $g(x)$ chia hết đa thức $f(x)$ khi và chỉ khi tất cả các nghiệm của $g(x)$ đều là nghiệm của $f(x)$, và bội số của chúng trong $g(x)$ không vượt quá bội số tương ứng trong $f(x)$.

<span id="&#x591A;&#x9879;&#x5F0F;&#x7684;&#x4F59;&#x6570;&#x548C;&#x5546;"></span>

### Số dư và thương của đa thức

Đối với các đa thức $f(x), g(x)$, tồn tại **duy nhất** $Q(x), R(x)$ thỏa mãn:

$$
\begin{aligned}
    f(x) &= Q(x) g(x) + R(x) \\
    \operatorname{deg}{R} &< \operatorname{deg}{g}
\end{aligned}
$$

Khi $\operatorname{deg}{f} \ge \operatorname{deg}{g}$, có $\operatorname{deg}{Q} = \operatorname{deg}{f} - \operatorname{deg}{g}$; ngược lại $Q(x) = 0$. Ta gọi $Q(x)$ là **thương** (quotient) khi chia $f(x)$ cho $g(x)$, và $R(x)$ là **số dư** (remainder) khi chia $f(x)$ cho $g(x)$.

<span id="&#x6A21;&#x591A;&#x9879;&#x5F0F;"></span>

## Đa thức modulo

Đa thức modulo là vành thương của vành đa thức, thu được bằng cách lấy vành đa thức theo quan hệ tương đương đồng dư.

Trong phép chia có dư nói ở trên, đa thức $f(x)$ và số dư $R(x)$ của nó đồng dư theo modulo đa thức $g(x)$.

$$
f(x) \equiv R(x) \pmod{g(x)}
$$

Đồng dư thức này cũng có nghĩa là: với bất kỳ nghiệm $x_0$ nào của đa thức $g(x)$, khi thay vào $f(x)$ và $R(x)$, giá trị điểm thu được là như nhau. Tức là:

$$
f(x_0)=R(x_0)
$$

Hơn nữa, nếu nghiệm $x_0$ có bội số $k$ trong đa thức $g(x)$, tức $(x-x_0)^k$ chia hết $g(x)$, thì với mọi số nguyên $t$ thỏa mãn $0\le t<k$, có:

$$
f^{t}(x_0)=R^{t}(x_0)
$$

Ký hiệu ở đây biểu thị đạo hàm bậc $t$.

Đồng dư modulo đa thức có thể áp dụng cho chuỗi lũy thừa. Một chuỗi lũy thừa có vô hạn số hạng có thể đồng dư với một đa thức hữu hạn số hạng trong trường hợp modulo một đa thức cụ thể. Ví dụ:

$$
1+x+x^2+x^3+\ldots \equiv 1+x+\ldots+x^{n-1} \pmod{x^n}
$$

Rõ ràng tất cả các số hạng còn lại đều chia hết cho $x^n$, vì vậy phép toán modulo $x^n$ tương đương với "cắt cụt": cắt chuỗi lũy thừa vô hạn thành $n$ số hạng đầu và trực tiếp bỏ mất thông tin ở các bậc cao hơn.

Trong một số trường hợp cụ thể, cũng có thể lấy modulo theo các đa thức khác; phần sau sẽ giải thích những trường hợp tương ứng.

<span id="&#x591A;&#x9879;&#x5F0F;&#x7684;&#x591A;&#x70B9;&#x6C42;&#x503C;&#x548C;&#x63D2;&#x503C;"></span>

### Tính giá trị nhiều điểm và nội suy đa thức

**Tính giá trị nhiều điểm của đa thức** (multi-point evaluation) là bài toán: cho một đa thức $f(x)$ và $n$ điểm $x_{1}, x_{2}, \dots, x_{n}$, tính

$$
f(x_{1}), f(x_{2}), \dots, f(x_{n})
$$

**Nội suy đa thức** (interpolation) là bài toán: cho $n+1$ điểm

$$
(x_{0}, y_{0}), (x_{1}, y_{1}), \dots, (x_{n}, y_{n})
$$

tìm một đa thức bậc $n$ là $f(x)$ sao cho cả $n+1$ điểm đó nằm trên $f(x)$.

Bản chất của hai thao tác này là chuyển đổi đa thức giữa **biểu diễn hệ số** và **biểu diễn giá trị điểm**. Tính giá trị nhiều điểm biến biểu diễn hệ số của đa thức thành biểu diễn giá trị điểm; nội suy biến biểu diễn giá trị điểm của đa thức thành biểu diễn hệ số.

???+ note "Ghi chú"
    Nhìn theo quan điểm chuỗi lũy thừa, tính giá trị nhiều điểm tương đương với việc "nén" thông tin vô hạn số hạng thành biểu diễn bằng hữu hạn giá trị điểm, nên sẽ mất một phần thông tin; còn nội suy tương đương với khôi phục về biểu diễn hệ số ở bậc tương ứng.

    Các phép tính giá trị và nội suy thường gặp trong lập trình, chẳng hạn biến đổi Fourier rời rạc và biến đổi ngược của nó, chọn $n+1$ điểm đều có bội số $1$, tức đôi một khác nhau, nên tránh được phiền phức của việc tính đạo hàm.

    Việc "nén" này chỉ bảo đảm sự nhất quán trên $n+1$ điểm đó. Theo giải thích về đồng dư modulo đa thức ở trên, nếu chuỗi lũy thừa $f(x)$ được tính giá trị tại các điểm từ $x_0$ đến $x_n$ rồi nội suy để thu được đa thức $R(x)$, thì đặt đa thức:

    $$
    g(x)=(x-x_0)\ldots(x-x_n)
    $$

    sẽ có:

    $$
    f(x) \equiv R(x) \pmod{g(x)}
    $$

    Vì bậc của $R(x)$ nhỏ hơn nghiêm ngặt bậc của $g(x)$, $R(x)$ tìm được bằng tính giá trị và nội suy chính là số dư. Do đó trong trường hợp này, nếu chuỗi lũy thừa có thể tính giá trị tại các nghiệm, thì có thể lấy modulo đa thức. Một phản ví dụ là:

    $$
    \frac{1}{1-x}=1+x+x^2+x^3+\ldots
    $$

    Tại $x=1$ nó không thể tính giá trị, vì vậy chuỗi $1+x+x^2+x^3+\ldots$ không thể lấy modulo đa thức $x-1$.

    Vì đạo hàm bậc bất kỳ của chuỗi lũy thừa tại $0$ luôn tồn tại, modulo $x^n$ luôn có thể tính được, phù hợp với ý nghĩa "cắt cụt" đã nêu ở trên. Biến đổi Fourier rời rạc và biến đổi ngược của nó tương đương với modulo đa thức $x^n-1$.

<span id="&#x56E0;&#x5F0F;&#x5206;&#x89E3;&#x548C;&#x6B27;&#x51E0;&#x91CC;&#x5F97;"></span>

### Phân tích nhân tử và Euclid

Nhiều kết luận trong số học sơ cấp có thể mở rộng sang đa thức.

Trên trường số phức, từ định lý cơ bản của đại số suy ra: đối với đa thức bậc $n$ là $f$, phương trình

$$
f(x)=0
$$

có đúng $n$ nghiệm, tính cả nghiệm bội theo bội số.

Do đó $f(x)$ có thể phân tích duy nhất trên trường số phức thành dạng

$$
a(x-x_1)^{c_1}(x-x_2)^{c_2}\cdots(x-x_m)^{c_m}
$$

$$
c_1+c_2+\cdots+c_m=n,x_1,x_2,\cdots,x_m \text{ đôi một khác nhau}
$$

Khi đó, tương tự ước chung lớn nhất của các số nguyên dương, ta có [**ước chung lớn nhất**](../number-theory/gcd.md) (greatest common divisor, gcd) của đa thức. Nó có thể được tính bằng thuật toán Euclid

$$
\gcd(f,0)=f,\gcd(f,g)=\gcd(g,f\bmod g)
$$

Tính chất này có thể mở rộng đến trường hợp tổng quát hơn:

> Đối với vành đa thức $P[x]$ trên một trường bất kỳ $P$,
> mọi đa thức đều có thể phân tích nhân tử duy nhất, và có thể dùng thuật toán Euclid để tính ước chung lớn nhất.
> Cần chú ý rằng, với đa thức trên vành tổng quát, kết luận này chưa chắc đúng.

Khi thuật toán Euclid dùng được, có thể dùng Euclid mở rộng để tìm một nghiệm riêng $(P(x),Q(x))$ của phương trình vô định

$$
f(x)P(x)+g(x)Q(x)=\gcd(f(x),g(x))
$$

và dùng [định lý Bezout](../number-theory/bezouts.md) để xét tính giải được của phương trình vô định

$$
f(x)P(x)+g(x)Q(x)=h(x)
$$

[HALF-GCD](https://loj.ac/p/172) cho phép tính Euclid đa thức trong thời gian $O(n\log^2 n)$.

<span id="&#x6A21;&#x591A;&#x9879;&#x5F0F;&#x7684;&#x4E58;&#x6CD5;&#x9006;&#x5143;"></span>

### Nghịch đảo nhân modulo đa thức

Theo modulo đa thức $h(x)$, chuỗi lũy thừa $f(x)$ đôi khi có nghịch đảo. Nghịch đảo chính là số dư thu được khi lấy nghịch đảo của chuỗi lũy thừa $f(x)$ theo modulo đa thức $h(x)$.

Định nghĩa này cũng tương đương với: đối với đa thức $f(x)$, nếu tồn tại $g(x)$ thỏa mãn:

$$
\begin{aligned}
    f(x) g(x) & \equiv 1 \pmod{h(x)}
\end{aligned}
$$

thì gọi $g(x)$ là **nghịch đảo** (inverse element) của $f(x)$ theo modulo $h(x)$. Khi có thể dùng Euclid đa thức, nghịch đảo tồn tại khi và chỉ khi $\gcd(f,h)=1$.

Nghịch đảo theo modulo đa thức $h(x)$ luôn là duy nhất. Nếu bậc của đa thức $f(x)$ cũng nhỏ hơn bậc của $h(x)$, thì $g(x)$ thu được và $f(x)$ là nghịch đảo của nhau.

Xét khái niệm "cắt cụt", thông thường nghịch đảo theo modulo $x^n$ được ký hiệu là $f^{-1}(x)$, và đây cũng là khái niệm nghịch đảo mặc định được dùng ở các phần sau. Nếu không nói rõ, modulo của nghịch đảo được hiểu là $x^n$.

???+ note "Ghi chú"
    Một câu hỏi là: có thể dùng các phép biến đổi nội suy để trực tiếp tìm "nghịch đảo" hay không, chẳng hạn tính:

    $$
    IDFT\left(\frac{DFT(1)}{DFT(f(x))}\right)
    $$

    Câu trả lời là không. Theo giải thích ở trên, nghịch đảo thu được trực tiếp bằng biến đổi Fourier rời rạc và biến đổi ngược của nó là nghịch đảo theo modulo đa thức $x^n-1$, không phải nghịch đảo theo modulo đa thức $x^n$ thông thường. Hơn nữa, vì đa thức ban đầu có thể bằng $0$ tại một số giá trị điểm, cách tính này chưa chắc thực hiện được.

<span id="&#x751F;&#x6210;&#x51FD;&#x6570;"></span>

## Hàm sinh

Hàm sinh (generating function), còn gọi là hàm mẹ, là một loại chuỗi lũy thừa hình thức mà hệ số của mỗi số hạng có thể cung cấp thông tin về dãy đó.

Hàm sinh có nhiều loại khác nhau, nhưng phần lớn có thể biểu diễn bằng một dạng duy nhất:

$$
F(x)=\sum_n a_nk_n(x)
$$

trong đó $k_n(x)$ được gọi là hàm nhân. Các hàm nhân khác nhau sẽ sinh ra các hàm sinh khác nhau, có các tính chất khác nhau. Ví dụ:

1.  Hàm sinh thường: $k_n(x)=x^n$.
2.  Hàm sinh mũ: $k_n(x)=\dfrac{x^n}{n!}$.
3.  [Hàm sinh Dirichlet](../number-theory/dirichlet.md#hàm-sinh-dirichlet): $k_n(x)=\dfrac{1}{n^x}$.

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x62D3;&#x5C55;&#x9605;&#x8BFB;"></span>

## Tài liệu tham khảo và đọc thêm

-   [**Picks's Blog**](https://picks.logdown.com)
-   [**Miskcoo's Space**](https://blog.miskcoo.com)
-   [**Polynomial ring - Wikipedia**](https://en.wikipedia.org/wiki/Polynomial_ring)
-   [**Formal power series - Wikipedia**](https://en.wikipedia.org/wiki/Formal_power_series#The_ring_of_formal_power_series)
-   Khung lý thuyết tính toán hàm sinh trong thi lập trình tin học
