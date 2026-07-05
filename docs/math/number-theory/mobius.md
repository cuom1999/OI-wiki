author: hydingsy, hyp1231, ranwen, 383494

Kiến thức cần biết trước: [phân khối số học](./sqrt-decomposition.md), [tích chập Dirichlet](./dirichlet.md#dirichlet-%E5%8D%B7%E7%A7%AF)

Đảo Möbius là một nội dung quan trọng trong lý thuyết số. Với một số hàm $f(n)$, nếu khó tính trực tiếp giá trị của nó nhưng dễ tính tổng trên các bội hoặc tổng trên các ước $g(n)$, ta có thể dùng đảo Möbius để đơn giản hóa phép tính và tìm được giá trị của $f(n)$.

<span id="&#33707;&#27604;&#20044;&#26031;&#20989;&#25968;"></span>
## Hàm Möbius

Hàm Möbius được định nghĩa là

$$
\mu(n)=
\begin{cases}
1,&n=1,\\
0,&n\text{ chia hết cho một số chính phương }>1,\\
(-1)^k,&n\text{ là tích của }k\text{ số nguyên tố phân biệt}.
\end{cases}
$$

Cụ thể, giả sử số nguyên dương $n$ có phân tích thừa số nguyên tố $n=\prod_{i=1}^kp_i^{e_i}$, trong đó $p_i$ là số nguyên tố và $e_i$ là số nguyên dương. Khi đó ba trường hợp tương ứng là:

1.  $\mu(1) = 1$;
2.  nếu tồn tại $i$ sao cho $e_i > 1$, tức có một thừa số nguyên tố nào đó xuất hiện hơn một lần, thì $\mu(n)=0$;
3.  ngược lại, với mọi $i$ đều có $e_i = 1$, tức mọi thừa số nguyên tố đều chỉ xuất hiện một lần, thì $\mu(n)=(-1)^k$, trong đó $k$ là số lượng thừa số nguyên tố phân biệt.

<span id="&#24615;&#36136;"></span>
### Tính chất

Từ định nghĩa có thể kiểm tra dễ dàng rằng hàm Möbius $\mu(n)$ là hàm nhân tính, nhưng không phải hàm hoàn toàn nhân tính. Ngoài ra, tính chất quan trọng nhất là hằng đẳng thức sau:

???+ note "Tính chất"
    Với số nguyên dương $n$, ta có
    
    $$
    \sum_{d\mid n}\mu(d) = [n = 1] =
    \begin{cases}
    1,&n=1,\\
    0,&n\neq 1.
    \end{cases}
    $$
    
    Trong đó $[\cdot]$ là ngoặc Iverson.

??? note "Chứng minh"
    Đặt $n=\prod_{i=1}^kp_i^{e_i}$ và $n' = \prod_{i=1}^kp_i$. Theo [định lý nhị thức](../combinatorics/combination.md#%E4%BA%8C%E9%A1%B9%E5%BC%8F%E5%AE%9A%E7%90%86), ta có
    
    $$
    \sum_{d\mid n}\mu(d) = \sum_{d\mid n'}\mu(d) = \sum_{i=0}^k\binom{k}{i}(-1)^i = (1 + (-1))^k = [k = 0] = [n = 1].
    $$

Dùng tích chập Dirichlet, biểu thức này có thể viết thành $\varepsilon = 1 * \mu$. Nói cách khác, hàm Möbius là nghịch đảo Dirichlet của hàm hằng $1$.

Tính chất này có một ứng dụng rất thường gặp:

$$
[i\perp j] = [\gcd(i,j) = 1] = \sum_{d\mid\gcd(i,j)} \mu(d) = \sum_{d}[d\mid i][d\mid j]\mu(d).
$$

Nó biến điều kiện nguyên tố cùng nhau thành một tổng theo hàm Möbius, thuận tiện cho các bước suy luận tiếp theo.

<span id="&#27714;&#27861;"></span>
### Cách tính

Nếu cần tính giá trị hàm Möbius $\mu(n)$ cho một $n$ riêng lẻ, có thể dùng [phân tích thừa số nguyên tố](./pollard-rho.md). Chẳng hạn, khi $n$ không quá lớn, ta có thể tính $\mu(n)$ trong thời gian $O(\sqrt{n})$.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/mobius/mobius-func-1.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/mobius/mobius-func-1.py:core"
        ```

Nếu cần tiền xử lý giá trị $\mu(n)$ cho $n$ số nguyên dương đầu tiên, có thể dùng tính nhân tính của nó và tính bằng [sàng tuyến tính](./sieve.md#%E7%AD%9B%E6%B3%95%E6%B1%82%E8%8E%AB%E6%AF%94%E4%B9%8C%E6%96%AF%E5%87%BD%E6%95%B0) trong thời gian $O(n)$.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/mobius/mobius-func-2.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/mobius/mobius-func-2.py:core"
        ```

<span id="&#33707;&#27604;&#20044;&#26031;&#21453;&#28436;"></span>
## Đảo Möbius

Ứng dụng quan trọng nhất của hàm Möbius là đảo Möbius.

???+ note "Đảo Möbius"
    Giả sử $f(n),g(n)$ là hai hàm số học. Khi đó
    
    $$
    f(n) = \sum_{d\mid n}g(d) \iff g(n) = \sum_{d\mid n}\mu\left(\dfrac{n}{d}\right)f(d).
    $$

??? note "Chứng minh 1"
    Kiểm tra trực tiếp:
    
    $$
    \begin{aligned}
    \sum_{d\mid n}\mu\left(\dfrac{n}{d}\right)f(d)
    &= \sum_{d\mid n}\mu\left(\dfrac{n}{d}\right)\sum_{k\mid d}g(k)\\
    &= \sum_{k\mid n}g(k)\sum_d[k\mid d\mid n]\mu\left(\dfrac{n}{d}\right)\\
    &= \sum_{k\mid n}g(k)\sum_{d\mid n}\left[\frac{n}{d}\mid\frac{n}{k}\right]\mu\left(\dfrac{n}{d}\right)\\
    &= \sum_{k\mid n}g(k)\left[\frac{n}{k} = 1\right] \\
    &= g(n).
    \end{aligned}
    $$
    
    Điểm then chốt của phép biến đổi là đổi thứ tự lấy tổng và chú ý rằng $k\mid d\mid n$ tương đương với $\dfrac{n}{d}\mid\dfrac{n}{k}$. Dấu bằng áp chót chính là tổng hàm Möbius trên các ước $\dfrac{n}{d}$ của $\dfrac{n}{k}$, nên bằng $\left[\dfrac{n}{k} = 1\right]$. Biểu thức này chỉ khác $0$ tại $n=k$, do đó cuối cùng thu được $g(n)$.

??? note "Chứng minh 2"
    Dùng tích chập Dirichlet, mệnh đề tương đương với
    
    $$
    f = 1 * g \iff g = \mu * f.
    $$
    
    Dùng $1 * \mu = \varepsilon$, lấy tích chập với $\mu$ ở hai vế của đẳng thức bên trái, ta được
    
    $$
    f * \mu = (1 * g) * \mu = (1 * \mu) * g = \varepsilon * g = g.
    $$

Trong các tổng hàm số học liên quan đến quan hệ chia hết, đảo Möbius là một công cụ biến đổi rất mạnh.

???+ example "Ví dụ"
    1.  [Hàm Euler](./euler-totient.md) $\varphi(n)$ thỏa quan hệ $n = \sum_{d\mid n}\varphi(d)$, tức $\mathrm{id}=1*\varphi$. Đảo công thức này, ta được $\varphi = \mu * \mathrm{id}$, tức
    
        $$
        \varphi(n) = \sum_{d\mid n}d\mu\left(\dfrac{n}{d}\right).
        $$
    2.  Hàm tổng lũy thừa các ước $\sigma_k(n) = \sum_{d\mid n}d^k$, tức $\sigma_k = 1 * \mathrm{id}_k$. Đảo công thức này, ta được $\mathrm{id}_k = \mu * \sigma_k$, tức
    
        $$
        n^k = \sum_{d\mid n}\mu\left(\dfrac{n}{d}\right)\sigma_k(d).
        $$
    3.  Hàm đếm số thừa số nguyên tố phân biệt $\omega(n)=\sum_{d\mid n}[d\in\mathbf P]$, tức $\omega = 1* \mathbf{1}_{\mathbf P}$, trong đó $\mathbf{1}_{\mathbf P}$ là hàm chỉ thị của tập số nguyên tố $\mathbf P$. Đảo công thức này, ta được $\mathbf{1}_{\mathbf P} = \mu * \omega$, tức
    
        $$
        [n\in\mathbf P] = \sum_{d\mid n}\mu\left(\dfrac{n}{d}\right)\omega(d).
        $$
    4.  Xét hàm số học $\Lambda(n)$ thỏa $\log n = \sum_{d\mid n}\Lambda(d)$. Nó chính là đảo Möbius của hàm logarit, còn gọi là hàm von Mangoldt:
    
        $$
        \Lambda(n) = \sum_{d\mid n}\mu\left(\dfrac{n}{d}\right)\log d = 
        \begin{cases}
        \log p, & n = p^e,~p\in\mathbf P,~e\in\mathbf N_+, \\
        0, &\text{otherwise}.
        \end{cases}
        $$

??? note "Phụ lục: chứng minh biểu thức của $\Lambda(n)$"
    Với lũy thừa nguyên tố $n=p^e~(e\in\mathbf N_+)$, ta có
    
    $$
    \Lambda(n) = \sum_{i=0}^e\mu(p^{e-i})\log p^i = \log p^{e} - \log p^{e-1} = \log p.
    $$
    
    Với $n=1$, hiển nhiên $\Lambda(n)=\log 1=0$. Với hợp số $n$ khác, ta có
    
    $$
    \Lambda(n) = \sum_{d\mid n}\mu(d)(\log n-\log d) = \left(\sum_{d\mid n}\mu(d)\right)\log n-\sum_{d\mid n}\mu(d)\log d.
    $$
    
    Theo tính chất của hàm Möbius, hệ số của hạng $\log n$ là $[n=1]=0$. Với hạng phía sau, có thể tiếp tục phân tích $d$ thành tích các thừa số nguyên tố. Với mọi số nguyên tố $p\mid n$, xét hệ số của $\log p$, ta đều có:
    
    $$
    -\sum_{p\mid d\mid n}\mu(d) = \sum_{(d/p)\mid(n/p)}\mu\left(\dfrac{d}{p}\right) = \left[\dfrac{n}{p}=1\right]=0.
    $$
    
    Do đó, với mọi hợp số $n$ có nhiều hơn một thừa số nguyên tố, ta đều có $\Lambda(n)=0$.

<span id="&#25299;&#23637;&#24418;&#24335;"></span>
### Các dạng mở rộng

Ngoài dạng cơ bản trên, đảo Möbius còn có một số dạng mở rộng thường gặp. Trước hết, có thể xét dạng tổng trên các bội.

???+ note "Mở rộng 1"
    Giả sử $f(n),g(n)$ là hai hàm số học. Khi đó
    
    $$
    f(n) = \sum_{n\mid d}g(d) \iff g(n) = \sum_{n\mid d}\mu\left(\dfrac{d}{n}\right)f(d).
    $$

??? note "Chứng minh"
    Kiểm tra trực tiếp:
    
    $$
    \begin{aligned}
    \sum_{n\mid d}\mu\left(\dfrac{d}{n}\right)f(d)
    &= \sum_{n\mid d}\mu\left(\dfrac{d}{n}\right)\sum_{d\mid k}g(k)\\
    &= \sum_{n\mid k}g(k)\sum_{d}[n\mid d\mid k]\mu\left(\dfrac{d}{n}\right)\\
    &= \sum_{n\mid k}g(k)\sum_{n\mid d}\left[\dfrac{d}{n}\mid\dfrac{k}{n}\right]\mu\left(\dfrac{d}{n}\right)\\
    &= \sum_{n\mid k}g(k)\left[\dfrac{k}{n}=1\right]\\
    &= g(n).
    \end{aligned}
    $$
    
    Suy luận này hoàn toàn đối ngẫu với dạng cơ bản.

Tiếp theo, đảo Möbius không chỉ giới hạn ở phép cộng; thực ra nó đúng với phép toán trong bất kỳ [nhóm Abel](../algebra/basic.md#nhóm) nào. Chẳng hạn, nó có dạng nhân sau:

???+ note "Mở rộng 2"
    Giả sử $f(n),g(n)$ là hai hàm số học. Khi đó
    
    $$
    f(n) = \prod_{d\mid n}g(d) \iff g(n) = \prod_{d\mid n}f(d)^{\mu(n/d)}.
    $$

??? note "Chứng minh"
    Kiểm tra trực tiếp:
    
    $$
    \begin{aligned}
    \prod_{d\mid n}f(d)^{\mu(n/d)}
    &= \prod_{d\mid n}\left(\prod_{k\mid d}g(k)\right)^{\mu(n/d)}\\
    &= \prod_{k\mid n}g(k)\uparrow\left(\sum_d[k\mid d\mid n]\mu\left(\dfrac{n}{d}\right)\right)\\
    &= \prod_{k\mid n}g(k)\uparrow\left(\sum_{d\mid n}\left[\frac{n}{d}\mid\frac{n}{k}\right]\mu\left(\dfrac{n}{d}\right)\right)\\
    &= \prod_{k\mid n}g(k)\uparrow\left[\frac{n}{k} = 1\right] \\
    &= g(n).
    \end{aligned}
    $$
    
    Trong đó $a\uparrow b = a^b$ là ký hiệu mũi tên Knuth. So sánh với chứng minh của dạng cơ bản, ta thấy khác biệt duy nhất là phép cộng được thay bằng phép nhân, còn phép nhân được thay bằng phép lũy thừa.

Nhìn từ góc độ tích chập Dirichlet, đảo Möbius chỉ dùng sự thật rằng "hàm Möbius là nghịch đảo Dirichlet của hàm hằng". Có thể hình dung các quan hệ tương tự đảo Möbius cũng đúng với [nghịch đảo Dirichlet](./dirichlet.md#dirichlet-%E5%8D%B7%E7%A7%AF) tổng quát.

???+ note "Mở rộng 3"
    Giả sử $f(n),g(n),\alpha(n)$ đều là các hàm số học, và $\alpha^{-1}(n)$ là nghịch đảo Dirichlet của $\alpha(n)$, tức
    
    $$
    [n=1] = \sum_{d\mid n}\alpha\left(\dfrac{n}{d}\right)\alpha^{-1}(d).
    $$
    
    Khi đó
    
    $$
    f(n) = \sum_{d\mid n}\alpha\left(\dfrac{n}{d}\right)g(d) \iff g(n) = \sum_{d\mid n}\alpha^{-1}\left(\dfrac{n}{d}\right)f(d).
    $$

??? note "Chứng minh"
    Kiểm tra trực tiếp:
    
    $$
    \begin{aligned}
    \sum_{d\mid n}\alpha^{-1}\left(\dfrac{n}{d}\right)f(d)
    &= \sum_{d\mid n}\alpha^{-1}\left(\dfrac{n}{d}\right)\sum_{k\mid d}\alpha\left(\dfrac{d}{k}\right)g(k)\\
    &= \sum_{k\mid n}g(k)\sum_d[k\mid d\mid n]\alpha\left(\dfrac{d}{k}\right)\alpha^{-1}\left(\dfrac{n}{d}\right)\\
    &= \sum_{k\mid n}g(k)\sum_{d\mid n}\left[\frac{n}{d}\mid\frac{n}{k}\right]\alpha\left(\dfrac{d}{k}\right)\alpha^{-1}\left(\dfrac{n/k}{d/k}\right)\\
    &= \sum_{k\mid n}g(k)\left[\frac{n}{k} = 1\right] \\
    &= g(n).
    \end{aligned}
    $$
    
    So với chứng minh của dạng cơ bản, chỉ cần thay dấu bằng áp chót bằng định nghĩa của nghịch đảo Dirichlet.

???+ note "Hệ quả"
    Giả sử $f(n),g(n)$ là các hàm số học và $t(n)$ là hàm hoàn toàn nhân tính. Khi đó
    
    $$
    f(n) = \sum_{d\mid n}t\left(\dfrac{n}{d}\right)g(d) \iff g(n) = \sum_{d\mid n}\mu\left(\dfrac{n}{d}\right)t\left(\dfrac{n}{d}\right)f(d).
    $$

??? note "Chứng minh"
    Từ [tính chất](./dirichlet.md#%E6%80%A7%E8%B4%A8) của tích chập Dirichlet, với hàm hoàn toàn nhân tính $t(n)$, nghịch đảo Dirichlet của nó chính là $\mu(n)t(n)$.

Cuối cùng, đảo Möbius còn có thể được mở rộng cho các hàm phức trên $[1,+\infty)$, chứ không chỉ giới hạn trong các hàm số học. Dạng cơ bản của đảo Möbius có thể xem là trường hợp đặc biệt trong đó hàm phức nhận giá trị bằng không tại mọi điểm không nguyên.

???+ note "Mở rộng 4"
    Giả sử $F(x)$ và $G(x)$ đều là các hàm phức trên $[1,+\infty)$. Khi đó
    
    $$
    F(x) = \sum_{n = 1}^{\lfloor x\rfloor}G\left(\dfrac{x}{n}\right) \iff G(x) = \sum_{n = 1}^{\lfloor x\rfloor}\mu(n)F\left(\dfrac{x}{n}\right).
    $$

??? note "Chứng minh"
    Ta có thể bổ sung định nghĩa cho $F$ và $G$: khi $x < 1$, luôn có $F(x)=G(x)=0$. Khi đó mệnh đề tương đương với:
    
    $$
    F(x) = \sum_n G\left(\dfrac{x}{n}\right) \iff G(x) = \sum_n \mu(n)F\left(\dfrac{x}{n}\right).
    $$
    
    Các tổng này đều lấy trên $n\in\mathbf N_+$.
    
    Kiểm tra trực tiếp:
    
    $$
    \begin{aligned}
    \sum_n \mu(n)F\left(\dfrac{x}{n}\right)
    &= \sum_n\mu(n)\sum_d G\left(\dfrac{x/n}{d}\right)\\
    &= \sum_k G\left(\dfrac{x}{k}\right)\sum_{n\mid k}\mu(n)\\
    &= \sum_k G\left(\dfrac{x}{k}\right)[k=1]\\
    &= G(x).
    \end{aligned}
    $$
    
    Trong đó, để thu được dấu bằng thứ hai, đặt $k = nd$.

???+ note "Hệ quả"
    Giả sử $f(n),g(n)$ là các hàm số học. Khi đó
    
    $$
    f(n) = \sum_{k=1}^ng\left(\left\lfloor\dfrac{n}{k}\right\rfloor\right) \iff g(n)=\sum_{k=1}^n\mu(k)f\left(\left\lfloor\dfrac{n}{k}\right\rfloor\right).
    $$

??? note "Chứng minh"
    Chỉ cần lấy $F(x)=f(\lfloor x\rfloor)$ và $G(x)=g(\lfloor x\rfloor)$.

Các dạng mở rộng này có thể kết hợp với nhau, từ đó thu được những quan hệ đảo phức tạp hơn.

<span id="dirichlet-&#21069;&#32512;&#21644;"></span>
### Tổng tiền tố Dirichlet

Kiến thức cần biết trước: [tổng tiền tố và sai phân](../../basic/prefix-sum.md)

Xét quan hệ đảo Möbius dạng cơ bản:

$$
f(n) = \sum_{d\mid n}g(d) \iff g(n) = \sum_{d\mid n}\mu\left(\dfrac{n}{d}\right)f(d).
$$

Ở đẳng thức bên trái, giá trị $f(n)$ là tổng các giá trị của $g(n)$ tại mọi ước của $n$. Nếu hiểu $a\mid b$ là $a$ đứng trước $b$, thì $f(n)$ có thể được xem như một dạng tổng tiền tố của $g(n)$. Vì vậy, trong giới thi lập trình Trung Quốc, quá trình tính $\{f(k)\}_{k=1}^n$ từ $\{g(k)\}_{k=1}^n$ còn được gọi là **tổng tiền tố Dirichlet**, còn quá trình ngược lại được gọi là sai phân Dirichlet. Các phương pháp này chủ yếu xuất hiện khi cần tiền xử lý giá trị của một hàm số học tại $N$ điểm đầu tiên.

Tiếp theo, xét cách tính tổng tiền tố Dirichlet. Nếu xem mỗi số nguyên tố là một chiều, đây chính là một dạng tổng tiền tố nhiều chiều. Nhắc lại [thuật toán tổng tiền tố theo từng chiều](../../basic/prefix-sum.md#%E9%80%90%E7%BB%B4%E5%89%8D%E7%BC%80%E5%92%8C) của tổng tiền tố nhiều chiều: lần lượt duyệt mọi chiều và cộng giá trị của mỗi vị trí sang vị trí kế tiếp theo chiều đó. Với hàm số học, điều này tương đương với việc duyệt các số nguyên tố $p$ theo thứ tự tăng dần, rồi cộng giá trị hàm tại $n$ sang $np$. Thứ tự duyệt này trùng với [sàng Eratosthenes](./sieve.md#%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95). Do đó, thuật toán này có thể tính tổng tiền tố Dirichlet của một dãy độ dài $n$ trong thời gian $O(n\log\log n)$. Tương tự, dùng sai phân theo từng chiều cũng có thể tính sai phân Dirichlet của dãy trong cùng độ phức tạp.

???+ example "Cài đặt tham khảo"
    === "Tổng tiền tố Dirichlet"
        ```cpp
        --8<-- "docs/math/code/mobius/mobius-func-3.cpp:presum"
        ```
    
    === "Sai phân Dirichlet"
        ```cpp
        --8<-- "docs/math/code/mobius/mobius-func-3.cpp:diff"
        ```

Cách tính này có thể mở rộng sang tổng trên các bội (mở rộng 1), dạng tích (mở rộng 2), hoặc dạng dùng hàm hoàn toàn nhân tính thay cho hàm hằng (hệ quả của mở rộng 3).

<span id="&#20363;&#39064;"></span>
## Bài tập ví dụ

Phần này dùng các bài tập để minh họa cách ứng dụng đảo Möbius và một số kỹ thuật biến đổi thường gặp. Trước hết, hãy làm quen với kỹ thuật cơ bản để xử lý điều kiện ước chung lớn nhất trong tổng.

???+ example "[Luogu P2522 \[HAOI 2011\] Problem b](https://www.luogu.com.cn/problem/P2522)"
    Có $T$ bộ dữ liệu. Với mỗi bộ dữ liệu, hãy tính:
    
    $$
    \sum_{i=x}^{n}\sum_{j=y}^{m}[\gcd(i,j)=k].
    $$
    
    Giới hạn dữ liệu: $1\le T,x,y,n,m,k\le 5\times 10^4$.

??? note "Lời giải"
    Theo nguyên lý bao hàm - loại trừ, biểu thức ban đầu có thể tách thành $4$ phần, và mỗi phần đều có dạng
    
    $$
    f(n,m,k)=\sum_{i=1}^{n}\sum_{j=1}^{m}[\gcd(i,j)=k].
    $$
    
    Với loại biểu thức này, tiếp theo là một quy trình suy luận chuẩn: tách ước chung, áp dụng tính chất của hàm Möbius, rồi đổi thứ tự lấy tổng.
    
    Trước hết, vì $i,j$ đều chỉ có thể nhận các bội của $k$, ta có thể tách nhân tử này ra trước, tương đương với thay $i=ki'$ và $j=kj'$, thu được:
    
    $$
    f(n,m,k)=\sum_{i=1}^{\lfloor n/k\rfloor}\sum_{j=1}^{\lfloor m/k\rfloor}[\gcd(i,j)=1].
    $$
    
    Lại dùng tính chất của hàm Möbius:
    
    $$
    [\gcd(i,j)=1] = \sum_{d\mid\gcd(i,j)}\mu(d) = \sum_d[d\mid i][d\mid j]\mu(d).
    $$
    
    Thay nó vào biểu thức và đổi thứ tự lấy tổng, ta được:
    
    $$
    f(n,m,k)=\sum_d\mu(d)\left(\sum_{i=1}^{\lfloor n/k\rfloor}[d\mid i]\right)\left(\sum_{j=1}^{\lfloor m/k\rfloor}[d\mid j]\right).
    $$
    
    Lợi ích của bước biến đổi này là khi cố định $d$, các hạng liên quan đến $i$ và $j$ trong tổng được tách rời và có thể tính riêng. Tiếp theo, vì
    
    $$
    \sum_{i=1}^{\lfloor n/k\rfloor}[d\mid i] = \left\lfloor\dfrac{\lfloor n/k\rfloor}{d}\right\rfloor,~\sum_{j=1}^{\lfloor m/k\rfloor}[d\mid j]=\left\lfloor\dfrac{\lfloor m/k\rfloor}{d}\right\rfloor,
    $$
    
    nên
    
    $$
    f(n,m,k)=\sum_d\mu(d)\left\lfloor\dfrac{\lfloor n/k\rfloor}{d}\right\rfloor\left\lfloor\dfrac{\lfloor m/k\rfloor}{d}\right\rfloor.
    $$
    
    Sau khi dùng sàng tuyến tính để tiền xử lý $\mu(d)$ và tổng tiền tố của nó, có thể giải bằng phân khối số học. Tổng độ phức tạp thời gian là $O(N + T\sqrt{N})$, trong đó $N$ là cận trên của $n,m$, còn $T$ là số bộ dữ liệu.

??? note "Code tham khảo"
    ```cpp
    --8<-- "docs/math/code/mobius/mobius_1.cpp"
    ```

Hai bài tiếp theo minh họa cách xử lý bằng cách liệt kê ước chung, đồng thời dùng [sàng](./sieve.md#%E4%B8%80%E8%88%AC%E7%9A%84%E7%A7%AF%E6%80%A7%E5%87%BD%E6%95%B0) để tính giá trị của hàm nhân tính tổng quát.

???+ example "[SPOJ LCMSUM](https://www.spoj.com/problems/LCMSUM/)"
    Có $T$ bộ dữ liệu. Với mỗi bộ dữ liệu, hãy tính:
    
    $$
    \sum_{i=1}^n \operatorname{lcm}(i,n).
    $$
    
    Giới hạn dữ liệu: $1\le T\le 3\times 10^5,~1\le n\le 10^6$.

??? note "Lời giải 1"
    Đề bài cho bội chung nhỏ nhất, nhưng ước chung lớn nhất thường dễ xử lý hơn. Vì vậy trước hết biến đổi:
    
    $$
    f(n)=\sum_{i=1}^n \operatorname{lcm}(i,n) = \sum_{i=1}^n \frac{i\cdot n}{\gcd(i,n)}.
    $$
    
    Tách $n$ ra ngoài và liệt kê ước chung lớn nhất $k$:
    
    $$
    f(n)=n\sum_{k\mid n}\sum_{i=1}^n\dfrac{i}{k}[\gcd(i,n)=k].
    $$
    
    Với tổng bên trong, đây là dạng thường gặp nhất có chứa ước chung lớn nhất. Lặp lại quy trình chuẩn, ta có:
    
    $$
    \begin{aligned}
    f(n) &= n\sum_{k\mid n}\sum_{i=1}^{n/k}i\left[\gcd\left(i,\dfrac{n}{k}\right)=1\right]\\
    &= n\sum_{k\mid n}\sum_{i=1}^{n/k}i\sum_d\mu(d)[d\mid i]\left[d\mid \dfrac{n}{k}\right]\\
    &= n\sum_{k\mid n}\sum_d\mu(d)\left[d\mid \dfrac{n}{k}\right]\left(\sum_{i=1}^{n/k}i[d\mid i]\right).
    \end{aligned}
    $$
    
    Một lần nữa, tổng theo $i$ được tách khỏi phần còn lại và có thể xử lý riêng. Tổng cuối thực chất là tổng cấp số cộng: lấy $i=di'$, ta có
    
    $$
    \sum_{i=1}^{n/k}i[d\mid i] = d\frac{1}{2}\left(\dfrac{n}{kd}+1\right)\dfrac{n}{kd}=:dG\left(\dfrac{n}{kd}\right).
    $$
    
    Từ đó thu được biểu thức:
    
    $$
    f(n) = n\sum_{k\mid n}\sum_d\mu(d)\left[d\mid \dfrac{n}{k}\right]dG\left(\dfrac{n}{kd}\right).
    $$
    
    Sau khi liệt kê ước chung, dạng tổng kép như vậy rất thường gặp. Với nó, cũng có một cách xử lý cố định: đặt tích thành biến mới $\ell=kd$, rồi lại đổi thứ tự lấy tổng. Vì $d\mid(n/k)$ tương đương với $d\mid\ell\mid n$, biểu thức ban đầu biến thành:
    
    $$
    f(n) = n\sum_{\ell\mid n}G\left(\dfrac{n}{\ell}\right)\sum_{d\mid\ell}\mu(d)d.
    $$
    
    Đặt $F(\ell)=\sum_{d\mid\ell}\mu(d)d$, biểu thức ban đầu có dạng:
    
    $$
    f(n) = n\sum_{\ell\mid n}G\left(\dfrac{n}{\ell}\right)F(\ell).
    $$
    
    Vì $\mu(d)d$ là hàm nhân tính, tích chập của nó với hàm hằng $1$, tức $F(n)$, cũng là hàm nhân tính. Dù tổng trên có dạng tích chập Dirichlet, $G(n)$ không phải hàm nhân tính, nên toàn bộ tổng không phải hàm nhân tính. Tuy nhiên, $G(n)$ là đa thức, nên thực ra nó là tổ hợp tuyến tính của một số hàm hoàn toàn nhân tính. Do đó
    
    $$
    f(n) = \dfrac{1}{2}n\left(\sum_{\ell}\left(\dfrac{n}{\ell}\right)^2F(\ell) + \sum_{\ell}\dfrac{n}{\ell}F(\ell)\right).
    $$
    
    Hai hạng này (không tính hệ số) đều là hàm nhân tính, có thể tiền xử lý trực tiếp bằng sàng tuyến tính; cũng có thể sàng tuyến tính hàm bên trong trước rồi dùng tổng tiền tố Dirichlet để tiền xử lý trong thời gian $O(N\log\log N)$. Cụ thể, đặt
    
    $$
    H_s(n) = \sum_{\ell}\left(\dfrac{n}{\ell}\right)^sF(\ell),~s=1,2.
    $$
    
    Để suy ra biểu thức của chúng, chỉ cần xác định giá trị tại lũy thừa nguyên tố. Với số nguyên tố $p$ và số mũ dương $e$, ta có
    
    $$
    \begin{aligned}
    F(p^e) &= \mu(1) + \mu(p)p + \sum_{j=2}^e\mu(p^j)p^j = 1-p,\\
    H_s(p^e) &= (p^e)^{s}F(1) + \sum_{j=1}^e(p^{e-j})^sF(p^j) = p^{es} + (1-p)\dfrac{1-p^{es}}{1-p^s},~s=1,2.
    \end{aligned}
    $$
    
    Đặc biệt, $H_1(p^e)\equiv 1$ là hàm hằng, còn
    
    $$
    H_2(p^e) = p^{2e} + (1-p)\dfrac{1-p^{2e}}{1-p^2} = H_2(p^{e-1}) + p^{2e} - p^{2e-1}.
    $$
    
    Công thức này rất dễ tính bằng sàng tuyến tính. Sau khi sàng tuyến tính tiền xử lý $H_2(n)$, mỗi truy vấn có thể được trả lời trong $O(1)$ bằng biểu thức $f(n)=(n/2)(H_2(n)+1)$. Tổng độ phức tạp thời gian là $O(N+T)$, trong đó $N$ là cận trên của $n$, còn $T$ là số bộ dữ liệu.
    
    Trong cài đặt tham khảo, do tính đặc biệt của biểu thức trong bài này, phần sàng tuyến tính được suy luận sâu hơn; điều này không bắt buộc. Chỉ dùng giá trị tại lũy thừa nguyên tố vẫn có thể hoàn thành tiền xử lý trong $O(N)$. Các suy luận này được trình bày trong lời giải 2.

??? note "Lời giải 2"
    Riêng với bài này, có một cách xử lý linh hoạt hơn. Từ lời giải 1 có thể thấy
    
    $$
    f(n) = n\sum_{k\mid n}\sum_{i=1}^{n/k}i\left[\gcd\left(i,\dfrac{n}{k}\right)=1\right] = n\sum_{k\mid n}F\left(\dfrac{n}{k}\right).
    $$
    
    Nếu ở bước này không tiếp tục dùng đảo Möbius, mà quan sát rằng tổng phía sau thực chất là tổng các số nguyên không vượt quá $d=n/k$ và nguyên tố cùng nhau với nó. Với $d>1$, vì các số nguyên tố cùng nhau với $d$ xuất hiện thành cặp, tức $i$ và $d-i$ chắc chắn đồng thời nguyên tố cùng nhau với $d$, nên
    
    $$
    F(d)=\sum_{i=1}^{d}i[i\perp d] = \sum_{i=1}^{d}(d-i)[i\perp d] = \dfrac{1}{2}d\sum_{i=1}^{d}[i\perp d] = \dfrac{1}{2}d\varphi(d).
    $$
    
    Với $d=1$, ta có
    
    $$
    F(d)=1=\dfrac{1}{2}+\dfrac{1}{2}d\varphi(d).
    $$
    
    Suy ra biểu thức ban đầu có thể viết thành
    
    $$
    f(n) = \dfrac{1}{2}n\left(\sum_{d\mid n}d\varphi(d) + 1\right).
    $$
    
    Vì $G(n)=\sum_{d\mid n}d\varphi(d)$ là tích chập Dirichlet của hàm nhân tính $n\varphi(n)$ với hàm hằng $1$, nên nó cũng là hàm nhân tính và có thể tiền xử lý bằng sàng tuyến tính. Để làm điều đó, chỉ cần xác định giá trị của nó tại lũy thừa nguyên tố. Với số nguyên tố $p$ và số mũ dương $e$, ta có
    
    $$
    G(p^e) = 1 + \sum_{i=1}^ep^e(p^e-1) = G(p^{e-1}) + p^{2e} - p^{2e-1}.
    $$
    
    Có thể thấy biểu thức này nhất quán với kết quả suy ra ở lời giải 1. Độ phức tạp thời gian tổng thể của phương pháp này vẫn là $O(N+T)$.
    
    Cuối cùng, dùng biểu thức hàm nhân tính của bài này, ta có thể tối ưu thêm quá trình tính bằng sàng tuyến tính. Với số nguyên tố $p$, ta có
    
    $$
    G(p) = 1 - p + p^2.
    $$
    
    Điểm then chốt của sàng tuyến tính là với $n$ tổng quát, cần tính giá trị $G(pn)$. Việc này lại chia thành hai trường hợp. Khi $p\perp n$, vì $G$ là hàm nhân tính nên
    
    $$
    G(pn) = G(p)G(n).
    $$
    
    Ngược lại, khi $p\mid n$, đặt $n=p^em$ và $p\perp m$, ta có
    
    $$
    \begin{aligned}
    G(pn) &= G(p^{e+1})G(m)\\
    &= G(p^e)G(m) + (p^{2e+2} - p^{2e+1})G(m)\\
    &= G(n) + (p^{2e+2} - p^{2e+1})G(m).
    \end{aligned}
    $$
    
    Kiểm tra trực tiếp cho thấy biểu thức này cũng đúng trong trường hợp $p\perp n$. Vì vậy
    
    $$
    G(n) - G\left(\dfrac{n}{p}\right) = (p^{2e}-p^{2e-1})G(m).
    $$
    
    Thay vào biểu thức trên, ta được
    
    $$
    G(pn) = G(n) + p^2\left(G(n) - G\left(\dfrac{n}{p}\right)\right).
    $$
    
    Điều này đơn giản hóa phần tính sàng tuyến tính. Tất nhiên, suy luận này không bắt buộc; với hàm nhân tính không có tính chất đặc biệt, dùng trực tiếp $G(pn)=G(p^{e+1})G(m)$ vẫn có thể hoàn thành sàng tuyến tính.

??? note "Code tham khảo"
    ```cpp
    --8<-- "docs/math/code/mobius/mobius_2.cpp"
    ```

???+ example "[BZOJ 2154 \[National Training Team\] Number Table of Crash](https://hydro.ac/p/bzoj-P2154)"
    Tính:
    
    $$
    \sum_{i=1}^n\sum_{j=1}^m\operatorname{lcm}(i,j)\mod{20101009}.
    $$
    
    Giới hạn dữ liệu: $1\le n,m\le 10^7$.

??? note "Lời giải"
    Trong quá trình suy luận, tạm bỏ qua modulo. Đặt
    
    $$
    f(n,m) = \sum_{i=1}^n\sum_{j=1}^m\operatorname{lcm}(i,j).
    $$
    
    Vẫn chuyển bội chung nhỏ nhất thành ước chung lớn nhất, liệt kê ước chung và áp dụng quy trình xử lý chuẩn, ta được
    
    $$
    \begin{aligned}
    f(n,m)
    &= \sum_k\sum_{i=1}^n\sum_{j=1}^m\dfrac{ij}{k}[\gcd(i,j)=k] \\
    &= \sum_k\sum_{i=1}^{\lfloor n/k\rfloor}\sum_{j=1}^{\lfloor m/k\rfloor} kij[\gcd(i,j)=1]\\
    &= \sum_k\sum_{i=1}^{\lfloor n/k\rfloor}\sum_{j=1}^{\lfloor m/k\rfloor} kij\sum_d\mu(d)[d\mid i][d\mid j]\\
    &= \sum_kk\sum_d\mu(d)\left(\sum_{i=1}^{\lfloor n/k\rfloor}i[d\mid i]\right)\left(\sum_{j=1}^{\lfloor m/k\rfloor}j[d\mid j]\right).
    \end{aligned}
    $$
    
    Một lần nữa, tổng được tách rời theo $i$ và $j$. Trước hết tính các tổng bên trong này; tách nhân tử, tức lấy $i=di'$, ta có
    
    $$
    \sum_{i=1}^{\lfloor n/k\rfloor}i[d\mid i] = d\sum_{i=1}^{\lfloor\lfloor n/k\rfloor/d\rfloor}i = dG\left(\left\lfloor\dfrac{\lfloor n/k\rfloor}{d}\right\rfloor\right) = dG\left(\left\lfloor\dfrac{n}{kd}\right\rfloor\right).
    $$
    
    Trong đó $G(n)=\dfrac{1}{2}n(n+1)$ là tổng cấp số cộng, còn dấu bằng cuối dùng tính chất của [hàm lấy phần nguyên dưới](./basic.md#%E5%8F%96%E6%95%B4%E5%87%BD%E6%95%B0). Tổng còn lại được tính tương tự. Thay trở lại biểu thức trước đó, ta có
    
    $$
    f(n,m) = \sum_k k\sum_{d}\mu(d)d^2G\left(\left\lfloor\dfrac{n}{kd}\right\rfloor\right)G\left(\left\lfloor\dfrac{m}{kd}\right\rfloor\right).
    $$
    
    Giống trường hợp trước, với các biểu thức liệt kê ước chung kiểu này, thường cần liệt kê tích $\ell = kd$ rồi đổi thứ tự lấy tổng lần nữa:
    
    $$
    f(n,m) = \sum_{\ell}\left(\sum_{d\mid\ell}\mu(d)d\ell\right)G\left(\left\lfloor\dfrac{n}{\ell}\right\rfloor\right)G\left(\left\lfloor\dfrac{m}{\ell}\right\rfloor\right).
    $$
    
    Đặt
    
    $$
    F(\ell) = \sum_{d\mid\ell}\mu(d)d\ell.
    $$
    
    Đây là tích của hàm nhân tính $\ell$ và hàm nhân tính $\sum_{d\mid\ell}\mu(d)d$, nên cũng là hàm nhân tính. Có thể dùng sàng tuyến tính để tiền xử lý trực tiếp, đồng thời tiền xử lý tổng tiền tố của nó. Sau đó, dùng phân khối số học để tính giá trị $f(n,m)$. Tổng độ phức tạp thời gian là $O(\min\{n,m\})$.

??? note "Code tham khảo"
    ```cpp
    --8<-- "docs/math/code/mobius/mobius_3.cpp"
    ```

Bài ví dụ tiếp theo tương đối đặc biệt, cần biến đổi hàm đếm số ước của một tích.

???+ example "[LOJ 2185. \[SDOI2015\] Sum of Divisor Counts](https://loj.ac/problem/2185)"
    Có $T$ bộ dữ liệu. Với mỗi bộ dữ liệu, hãy tính:
    
    $$
    \sum_{i=1}^n\sum_{j=1}^m\sigma_0(ij).
    $$
    
    Trong đó $\sigma_0(n)=\sum_{d \mid n}1$ biểu thị số lượng ước của $n$.
    
    Giới hạn dữ liệu: $1\le n,m,T\le 5\times 10^4$.

??? note "Lời giải"
    Điểm khó của bài này là biến đổi $\sigma_0(ij)$ thành biểu thức theo ước chung lớn nhất. Vì $\sigma_0$ là hàm nhân tính, trước hết có thể xét trường hợp lũy thừa nguyên tố. Với số nguyên tố $p$ và các số mũ không âm $e_1,e_2$, đặt $i=p^{e_1},~j=p^{e_2}$, ta có
    
    $$
    \sigma_0(ij) = 1 + e_1 + e_2 = \sum_{x\mid i}\sum_{y\mid j}[x\perp y].
    $$
    
    Với trường hợp tổng quát, giả sử $i=\prod_p i_p$ và $j=\prod_p j_p$, trong đó $i_p,j_p$ lần lượt là lũy thừa của $p$ trong phân tích thừa số nguyên tố của $i,j$. Khi đó
    
    $$
    \sigma_0(ij) = \prod_p\sigma_0(i_pj_p)= \prod_p\sum_{x_p\mid i_p}\sum_{y_p\mid j_p}[x_p\perp y_p].
    $$
    
    Chú ý rằng với mỗi thừa số lũy thừa nguyên tố $i_p$ của $i$, liệt kê ước $x_p$ của nó tương đương với liệt kê một ước $x$ của $i$ rồi tách ra mọi thừa số lũy thừa nguyên tố $x_p$; với $j$ cũng tương tự. Do đó, dùng luật phân phối của phép nhân, biểu thức trên trở thành
    
    $$
    \sigma_0(ij) = \sum_{x\mid i}\sum_{y\mid j}\prod_p[x_p\perp y_p] = \sum_{x\mid i}\sum_{y\mid j}[x\perp y].
    $$
    
    Bước cuối dùng kết luận: $x\perp y$ khi và chỉ khi với mỗi thừa số nguyên tố $p$, đều có $x_p\perp y_p$.
    
    Sau khi có biểu thức này, có thể áp dụng quy trình xử lý chuẩn:
    
    $$
    \begin{aligned}
    \sigma_0(ij) 
    &= \sum_{x\mid i}\sum_{y\mid j}[x\perp y]\\
    &= \sum_{x\mid i}\sum_{y\mid j}\sum_d\mu(d)[d\mid x][d\mid y]\\
    &= \sum_d\mu(d)\left(\sum_{x}[d\mid x\mid i]\right)\left(\sum_{y}[d\mid y\mid j]\right)\\
    &= \sum_d\mu(d)[d\mid i][d\mid j]\sigma_0\left(\dfrac{i}{d}\right)\sigma_0\left(\dfrac{j}{d}\right).
    \end{aligned}
    $$
    
    Ý nghĩa của bước suy luận cuối là: hàm chỉ nhận giá trị khác không khi $d\mid i$ và $d\mid j$; khi đó, liệt kê $x$ thỏa $d\mid x\mid i$ tương đương với liệt kê ước $\dfrac{x}{d}$ của $\dfrac{i}{d}$, và với $y$ cũng tương tự.
    
    Thay biểu thức này trở lại công thức ban đầu và đổi thứ tự lấy tổng:
    
    $$
    \begin{aligned}
    f(n,m)
    &= \sum_{i=1}^n\sum_{j=1}^m\sigma_0(ij)\\
    &= \sum_{i=1}^n\sum_{j=1}^m\sum_d\mu(d)[d\mid i][d\mid j]\sigma_0\left(\dfrac{i}{d}\right)\sigma_0\left(\dfrac{j}{d}\right)\\
    &= \sum_d\mu(d)\left(\sum_{i=1}^n[d\mid i]\sigma_0\left(\dfrac{i}{d}\right)\right)\left(\sum_{j=1}^m[d\mid j]\sigma_0\left(\dfrac{j}{d}\right)\right)\\
    &= \sum_d\mu(d)\left(\sum_{i=1}^{\lfloor n/d\rfloor}\sigma_0(i)\right)\left(\sum_{j=1}^{\lfloor m/d\rfloor}\sigma_0(j)\right).
    \end{aligned}
    $$
    
    Đặt $G(n)=\sum_{i=1}^n\sigma_0(i)$, ta có
    
    $$
    f(n,m)=\sum_{d}\mu(d)G\left(\left\lfloor\dfrac{n}{d}\right\rfloor\right)G\left(\left\lfloor\dfrac{m}{d}\right\rfloor\right).
    $$
    
    Công thức này có thể giải bằng phân khối số học. Chỉ cần tiền xử lý $\mu(n)$ và tổng tiền tố của $\sigma_0(n)$. Tổng độ phức tạp thời gian là $O(N+T\sqrt{N})$, trong đó $N$ là cận trên của $n,m$, còn $T$ là số bộ dữ liệu.

??? note "Code tham khảo"
    ```cpp
    --8<-- "docs/math/code/mobius/mobius_4.cpp"
    ```

Bài ví dụ cuối cùng minh họa cách áp dụng phiên bản nhân của đảo Möbius.

???+ example "[Luogu P5221 Product](https://www.luogu.com.cn/problem/P5221)"
    Tính:
    
    $$
    \prod_{i=1}^n\prod_{j=1}^n\dfrac{\operatorname{lcm}(i,j)}{\gcd(i,j)}\pmod{104857601}.
    $$
    
    Giới hạn dữ liệu: $1\le n\le 1\times 10^6$.

??? note "Lời giải 1"
    Trong quá trình suy luận, tạm bỏ qua modulo. Đặt
    
    $$
    f(n) = \prod_{i=1}^n\prod_{j=1}^n\dfrac{\operatorname{lcm}(i,j)}{\gcd(i,j)}.
    $$
    
    Vẫn chuyển bội chung nhỏ nhất thành ước chung lớn nhất:
    
    $$
    f(n) = \prod_{i=1}^n\prod_{j=1}^n\dfrac{ij}{(\gcd(i,j))^2}.
    $$
    
    Chú ý rằng tích của các nhân tử này độc lập với nhau và có thể tính riêng. Đặt
    
    $$
    g(n) = \prod_{i=1}^n\prod_{j=1}^n\gcd(i,j).
    $$
    
    Biểu thức ban đầu bằng
    
    $$
    f(n) = \dfrac{(n!)^{2n}}{g(n)^2}.
    $$
    
    Trọng tâm là tính $g(n)$. Quy trình xử lý nó tương tự như đã mô tả ở trên, nhưng cần chuyển sang phiên bản nhân tương ứng. Trước hết liệt kê và tách ước chung:
    
    $$
    \begin{aligned}
    g(n) &= \prod_k\prod_{i=1}^n\prod_{j=1}^nk\uparrow[\gcd(i,j)=k]\\
    &= \prod_k\prod_{i=1}^{\lfloor n/k\rfloor}\prod_{j=1}^{\lfloor n/k\rfloor}k\uparrow[\gcd(i,j)=1].
    \end{aligned}
    $$
    
    Trong đó $a\uparrow b=a^b$ là ký hiệu mũi tên Knuth. Sau đó, thay $[\gcd(i,j)=1]=\sum_d\mu(d)[d\mid i][d\mid j]$ và chuyển tổng ở số mũ thành tích các lũy thừa, thu được:
    
    $$
    g(n) = \prod_k\prod_d\prod_{i=1}^{\lfloor n/k\rfloor}\prod_{j=1}^{\lfloor n/k\rfloor}k\uparrow(\mu(d)[d\mid i][d\mid j]).
    $$
    
    Tiếp tục tách nhân tử, tức đặt $i=di'$, $j=dj'$, và áp dụng tính chất của [hàm lấy phần nguyên dưới](./basic.md#%E5%8F%96%E6%95%B4%E5%87%BD%E6%95%B0), ta được:
    
    $$
    g(n) = \prod_k\prod_d\prod_{i=1}^{\lfloor n/(kd)\rfloor}\prod_{j=1}^{\lfloor n/(kd)\rfloor}k\uparrow\mu(d).
    $$
    
    Sau đó tách tích theo $i,j$. Ta thấy trong tích không còn chứa $i,j$, nên điều này tương đương với lấy lũy thừa của tích:
    
    $$
    g(n) = \prod_k\prod_d k\uparrow\left(\mu(d)\left\lfloor\dfrac{n}{kd}\right\rfloor^2\right).
    $$
    
    Vì phía trước đã liệt kê ước chung, với biểu thức này cần đổi thứ tự lấy tích một lần nữa. Đặt $\ell = kd$, ta có:
    
    $$
    \begin{aligned}
    g(n) &= \prod_{\ell}\prod_{d\mid\ell}\left(\dfrac{\ell}{d}\right)\uparrow\left(\mu(d)\left\lfloor\dfrac{n}{\ell}\right\rfloor^2\right)\\
    &= \prod_\ell\left(\prod_{d\mid\ell}\left(\dfrac{\ell}{d}\right)\uparrow\mu(d)\right)\uparrow\left\lfloor\dfrac{n}{\ell}\right\rfloor^2.
    \end{aligned}
    $$
    
    Đặt
    
    $$
    F(n) = \prod_{d\mid n}\left(\dfrac{n}{d}\right)\uparrow\mu(d).
    $$
    
    Dễ thấy đây là đảo Möbius dạng tích đối với $\tilde F(n)=n$. Ngay cả khi không biết biểu thức của nó, ta vẫn có thể dùng phương pháp [sai phân Dirichlet](#dirichlet-%E5%89%8D%E7%BC%80%E5%92%8C) để tiền xử lý trong thời gian $O(n\log\log n)$. Tất nhiên, vì dạng của $\tilde F(n)$ rất đơn giản, biểu thức của $F(n)$ có thể tính trực tiếp:
    
    $$
    F(n) = 
    \begin{cases}
    p, & n = p^e,~p\in\mathbf P,~e\in\mathbf N_+, \\
    1, &\text{otherwise}.
    \end{cases}
    $$
    
    [Hàm von Mangoldt](#%E8%8E%AB%E6%AF%94%E4%B9%8C%E6%96%AF%E5%8F%8D%E6%BC%94) chính là logarit tự nhiên của nó. Sau khi có giá trị của $F(n)$, dùng trực tiếp phân khối số học phiên bản nhân là có thể tính giá trị của $g(n)$ trong thời gian $O(\sqrt{n})$, rồi từ đó tính được $f(n)$. Tổng độ phức tạp thời gian là $O(n)$.
    
    Cần chú ý rằng khi tính các tích, ta thường phải dùng [định lý Euler](./fermat.md), nên modulo dùng cho phần số mũ không giống modulo đề bài cho.

??? note "Lời giải 2"
    Điểm khó của suy luận phiên bản nhân nằm ở việc xử lý tích và lũy thừa còn khá lạ. Vì vậy, với loại bài này cũng có thể lấy logarit rồi suy luận. Trong bài này, chỉ xét phần suy luận cho $g(n)$. Lấy logarit, ta có:
    
    $$
    \log g(n) = \sum_{i=1}^n\sum_{j=1}^n\log\gcd(i,j).
    $$
    
    Với dạng biểu thức chứa ước chung lớn nhất như vậy, áp dụng trực tiếp quy trình suy luận chuẩn, ta được:
    
    $$
    \begin{aligned}
    \log g(n) 
    &= \sum_k\log k\sum_{i=1}^n\sum_{j=1}^n[\gcd(i,j)=k]\\
    &= \sum_k\log k\sum_{i=1}^{\lfloor n/k\rfloor}\sum_{j=1}^{\lfloor n/k\rfloor}[\gcd(i,j)=1]\\
    &= \sum_k\log k\sum_d\mu(d)\left(\sum_{i=1}^{\lfloor n/k\rfloor}[d\mid i]\right)\left(\sum_{j=1}^{\lfloor n/k\rfloor}[d\mid j]\right)\\
    &= \sum_k\log k\sum_d\mu(d)\left\lfloor\dfrac{n}{kd}\right\rfloor^2\\
    &= \sum_{\ell}\left(\sum_d\mu(d)\log\dfrac{\ell}{d}\right)\left\lfloor\dfrac{n}{\ell}\right\rfloor^2\\
    &= \sum_{\ell}\Lambda(\ell)\left\lfloor\dfrac{n}{\ell}\right\rfloor^2.
    \end{aligned}
    $$
    
    Trong đó $\Lambda(n)$ là [hàm von Mangoldt](#%E8%8E%AB%E6%AF%94%E4%B9%8C%E6%96%AF%E5%8F%8D%E6%BC%94). Lấy mũ kết quả suy luận này, ta thu được kết quả của lời giải 1.

??? note "Code tham khảo"
    ```cpp
    --8<-- "docs/math/code/mobius/mobius_5.cpp"
    ```

<span id="&#20064;&#39064;"></span>
## Bài tập

-   [Luogu P3312 \[SDOI2014\] Number Table](https://www.luogu.com.cn/problem/P3312)
-   [Luogu P3700 \[CQOI2017\] Table of Little Q](https://www.luogu.com.cn/problem/P3700)
-   [Luogu P3704 \[SDOI2017\] Number Table](https://www.luogu.com.cn/problem/P3704)
-   [Luogu P3768 Simple Math Problem](https://www.luogu.com.cn/problem/P3768)
-   [Luogu P4464 \[National Training Team\] JZPKIL](https://www.luogu.com.cn/problem/P4464)
-   [Luogu P4619 \[SDOI2018\] Old Problem](https://www.luogu.com.cn/problem/P4619)
-   [Luogu P5518 \[MtOI2019\] Ghost Orchestra](https://www.luogu.com.cn/problem/P5518)
-   [Luogu P6222 Simple Problem, Enhanced Version](https://www.luogu.com.cn/problem/P6222)
-   [Luogu P6825 \[EZEC-4\] Sum](https://www.luogu.com.cn/problem/P6825)
-   [Luogu P7486 \[Stoi2031\] Rainbow](https://www.luogu.com.cn/problem/P7486)
-   [AtCoder Grand Contest 038 C - LCMs](https://atcoder.jp/contests/agc038/tasks/agc038_c)
-   [Codeforces 1139 D. Steps to One](https://codeforces.com/problemset/problem/1139/D)

<span id="&#21442;&#32771;&#25991;&#29486;"></span>
## Tài liệu tham khảo

-   [Möbius function - Wikipedia](https://en.wikipedia.org/wiki/M%C3%B6bius_function)
-   [Möbius inversion formula - Wikipedia](https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula)
-   [Von Mangoldt function - Wikipedia](https://en.wikipedia.org/wiki/Von_Mangoldt_function)
-   [algocode algorithm blog](https://web.archive.org/web/20190523150159/https://algocode.net/2018/04/18/20180418-KB-Mobius-Inversion-Formula/)
