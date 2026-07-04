author: billchenchina, c-forrest, CCXXXI, danielqfmai, Enter-tainer, Great-designer, HeRaNO, lychees, Menci, Nanarikom, ouuan, shuzhouliu, sshwy, Tiphereth-A

Bài viết này giới thiệu tích chập Dirichlet và hàm sinh Dirichlet.

<span id="dirichlet-&#x5377;&#x79ef;"></span>
## Tích chập Dirichlet

Với hai hàm số học $f(n)$ và $g(n)$, **tích chập Dirichlet** (Dirichlet convolution), ký hiệu là $f \ast g$, được định nghĩa là hàm số học

$$
(f \ast g)(n) = \sum_{k\mid n}f(k)g\left(\dfrac{n}{k}\right) = \sum_{k\ell=n}f(k)g(\ell).
$$

Tích chập Dirichlet là một phép toán quan trọng trên các hàm số học. Nhiều tính chất của hàm số học được khai thác thông qua phép toán này.

???+ example "Ví dụ"
    1.  Hàm đơn vị $\varepsilon$ là tích chập Dirichlet của hàm Mobius $\mu$ và hàm hằng $1$:
    
        $$
        \varepsilon=\mu \ast 1 \iff\varepsilon(n)=\sum_{d\mid n}\mu(d).
        $$
    
    2.  Hàm đếm số ước $\tau$ là tích chập Dirichlet của hàm hằng $1$ với chính nó:
    
        $$
        \tau=1 \ast 1 \iff \tau(n)=\sum_{d\mid n}1.
        $$
    
    3.  Hàm tổng ước $\sigma$ là tích chập Dirichlet của hàm đồng nhất $\mathrm{id}$ và hàm hằng $1$:
    
        $$
        \sigma=\mathrm{id} \ast 1 \iff\sigma(n)=\sum_{d\mid n}d.
        $$
    
    4.  Hàm Euler $\varphi$ là tích chập Dirichlet của hàm đồng nhất $\mathrm{id}$ và hàm Mobius $\mu$:
    
        $$
        \varphi=\mathrm{id}\ast \mu \iff\varphi(n)=\sum_{d\mid n}d\cdot\mu\left(\frac{n}{d}\right).
        $$

[Phép đảo Mobius](./mobius.md) chính là việc dùng $\varepsilon=\mu \ast 1$ để biến đổi các đồng nhất thức giữa hàm số học.

<span id="&#x6027;&#x8d28;"></span>
### Tính chất

Tích chập Dirichlet có một loạt tính chất đại số.

???+ note "Định lý"
    Giả sử $f,g,h$ đều là hàm số học. Khi đó:
    
    1.  **Giao hoán**: $f\ast g=g\ast f$.
    2.  **Kết hợp**: $(f\ast g)\ast h=f\ast(g\ast h)$.
    3.  **Phân phối**: $(f+g)\ast h = f\ast h + g\ast h$.
    4.  **Đơn vị**: $f\ast\varepsilon = \varepsilon \ast f = f$, trong đó $\varepsilon(n) = [n=1]$ là phần tử đơn vị của tích chập, còn $[\cdot]$ là ngoặc Iverson.
    5.  **Nghịch đảo**: tồn tại $g$ sao cho $f\ast g=g\ast f=\varepsilon$ khi và chỉ khi $f(1)\neq 0$; khi đó $g$ được gọi là **nghịch đảo Dirichlet** (Dirichlet inverse) của $f$, có thể ký hiệu là $f^{-1}$. Hơn nữa, nghịch đảo $g$ thỏa công thức truy hồi
    
        $$
        g(n) = \dfrac{\varepsilon(n) - \sum_{k\ell = n,~k\neq 1}f(k)g(\ell)}{f(1)}.
        $$

??? note "Chứng minh"
    Để kiểm tra tính giao hoán, tính trực tiếp ta có
    
    $$
    (f\ast g)(n) = \sum_{k\ell=n}f(k)g(\ell) = (g\ast f)(n).
    $$
    
    Để kiểm tra tính kết hợp, tính trực tiếp ta có
    
    $$
    ((f\ast g)\ast h)(n) = \sum_{k\ell m = n}f(k)g(\ell)h(m) = (f\ast (g\ast h))(n).
    $$
    
    Để kiểm tra tính phân phối, tính trực tiếp ta có
    
    $$
    \begin{aligned}
    ((f+g)\ast h)(n) &= \sum_{k\ell = n}(f(k) + g(k))h(\ell) \\
    &= \sum_{k\ell=n}f(k)h(\ell) + \sum_{k\ell=n}g(k)h(\ell) = (f\ast h+g\ast h)(n).
    \end{aligned}
    $$
    
    Để kiểm tra $\varepsilon(n)$ là phần tử đơn vị, tính trực tiếp ta có
    
    $$
    (f\ast\varepsilon)(n) = \sum_{k\ell = n}f(k)\varepsilon(\ell) = f(n).
    $$
    
    Dấu bằng thứ hai đúng vì $\varepsilon(\ell)$ chỉ khác không khi $\ell=1$, tức là khi $k=n$.
    
    Cuối cùng, cần chứng minh $f^{-1}$ tồn tại khi và chỉ khi $f(1)\neq 0$. Với một hàm $f$ bất kỳ, giả sử tồn tại $g$ sao cho $f\ast g=\varepsilon$. Điều này nghĩa là
    
    $$
    (f\ast g)(n) = \sum_{k\ell = n}f(k)g(\ell) = \varepsilon(n).
    $$
    
    Thực chất, đây là một hệ các phương trình về giá trị của $g(n)$, từ đó có thể giải trực tiếp $g(n)$. Đặc biệt, khi $n=1$, đẳng thức trở thành $f(1)g(1)=1$, nên để $g$ tồn tại thì tối thiểu phải có $f(1)\neq 0$. Ngược lại, chỉ cần $f(1)\neq 0$, ta có thể giải trực tiếp
    
    $$
    g(n) = \dfrac{\varepsilon(n) - \sum_{k\ell = n,~k\neq 1}f(k)g(\ell)}{f(1)}.
    $$
    
    Công thức này có thể dùng để tính đệ quy các giá trị của $g(n)$. Vì vậy, nghịch đảo $g$ tồn tại khi và chỉ khi $f(1)\neq 0$.

Theo ngôn ngữ đại số trừu tượng, các tính chất đại số này nói rằng toàn bộ các hàm số học, với phép cộng theo điểm và tích chập Dirichlet, tạo thành một [vành giao hoán](../algebra/basic.md#%E7%8E%AF); tập các phần tử khả nghịch của vành này chính là các hàm nhận giá trị khác không tại $n=1$. Vành này được gọi là **vành Dirichlet** (Dirichlet ring).

Hàm nhân tính là một lớp hàm số học đặc biệt. Lớp này đóng với tích chập Dirichlet và nghịch đảo Dirichlet.

???+ note "Định lý"
    Giả sử $f,g$ là các hàm nhân tính. Khi đó $f\ast g$ cũng là hàm nhân tính. Hơn nữa, nghịch đảo $f^{-1}$ chắc chắn tồn tại và cũng là hàm nhân tính.

??? note "Chứng minh"
    Với ý thứ nhất, đặt $h=f\ast g$. Kiểm tra trực tiếp cho thấy, với $n_1\perp n_2$, ta luôn có
    
    $$
    \begin{aligned}
    h(n_1)h(n_2) &= \left(\sum_{k_1\ell_1=n_1}f(k_1)g(\ell_1)\right)\left(\sum_{k_2\ell_2=n_2}f(k_2)g(\ell_2)\right)\\
    &= \sum_{k_1\ell_1=n_1,~k_2\ell_2=n_2}f(k_1)f(k_2)g(\ell_1)g(\ell_2)\\
    &= \sum_{k\ell = n_1n_2}f(k)g(\ell) \\
    &= h(n_1n_2).
    \end{aligned}
    $$
    
    Trong đó, logic đổi thứ tự lấy tổng ở dấu bằng thứ ba là: khi $k$ chạy qua các ước của $n_1n_2$, các thừa số nguyên tố của $k$ có thể được chia thành hai loại tùy theo chúng là thừa số nguyên tố của $n_1$ hay của $n_2$; nhân riêng các thừa số nguyên tố trong hai loại đó, kể cả bội số lặp lại, ta thu được $k_1$ và $k_2$, lần lượt chạy qua các ước của $n_1$ và $n_2$. Ngược lại, từ các ước $k_1$ của $n_1$ và $k_2$ của $n_2$, luôn thu được một ước $k=k_1k_2$ của $n_1n_2$.
    
    Với ý thứ hai, đặt $g=f^{-1}$ và dùng quy nạp toán học. Trước hết, $g(1)=1/f(1)=1$. Lúc này, công thức truy hồi của nghịch đảo có thể viết là
    
    $$
    g(n) = \varepsilon(n) - \sum_{k\ell = n,~k\neq 1} f(k)g(\ell).
    $$
    
    Vì vậy, với $n_1\perp n_2$ và $n_1n_2 > 1$, ta có
    
    $$
    \begin{aligned}
    g(n_1n_2) &= -\sum_{k\ell=n_1n_2,~k\neq 1}f(k)g(\ell) \\
    &= -\sum_{k_1\ell_1=n_1,~k_2\ell_2=n_2,~k_1k_2\neq 1}f(k_1)f(k_2)g(\ell_1)g(\ell_2)\\
    &= f(1)f(1)g(n_1)g(n_2) - \sum_{k_1\ell_1=n_1,~k_2\ell_2=n_2}f(k_1)f(k_2)g(\ell_1)g(\ell_2)\\
    &= g(n_1)g(n_2) - \left(\sum_{k_1\ell_1=n_1}f(k_1)g(\ell_1)\right)\left(\sum_{k_2\ell_2=n_2}f(k_2)g(\ell_2)\right) \\
    &= g(n_1)g(n_2) - \varepsilon(n_1)\varepsilon(n_2)\\
    &= g(n_1)g(n_2).
    \end{aligned}
    $$
    
    Trong đó, dấu bằng thứ hai dùng giả thiết quy nạp: với $\ell_1\ell_2 < n_1n_2$ và $\ell_1\perp\ell_2$, điều kiện $g(\ell_1\ell_2)=g(\ell_1)g(\ell_2)$ đã đúng.

Theo ngôn ngữ đại số trừu tượng, toàn bộ các hàm nhân tính, với phép toán tích chập Dirichlet, tạo thành một [nhóm con](../algebra/group-theory.md#%E5%AD%90%E7%BE%A4) của nhóm nhân các phần tử khả nghịch trong vành Dirichlet.

Đặc biệt hơn nữa là các hàm hoàn toàn nhân tính.

???+ note "Định lý"
    Giả sử $\alpha$ là hàm hoàn toàn nhân tính, còn $f,g$ là các hàm số học. Khi đó:
    
    1.  Luật phân phối: $(\alpha f)\ast(\alpha g) = \alpha\cdot(f\ast g)$.
    2.  Nghịch đảo: $(\alpha f)^{-1}=\alpha f^{-1}$, miễn là $f^{-1}$ tồn tại.
    3.  Hàm nhân tính $f$ là hàm hoàn toàn nhân tính khi và chỉ khi $f^{-1}=\mu f$, trong đó $\mu$ là [hàm Mobius](./mobius.md#%E8%8E%AB%E6%AF%94%E4%B9%8C%E6%96%AF%E5%87%BD%E6%95%B0).

??? note "Chứng minh"
    Với ý thứ nhất, kiểm tra trực tiếp ta có
    
    $$
    \begin{aligned}
    ((\alpha f)\ast(\alpha g))(n) &= \sum_{k\ell = n}(\alpha f)(k)(\alpha g)(\ell) \\
    &= \sum_{k\ell = n}\alpha(k)f(k)\alpha(\ell)g(\ell) \\
    &= \sum_{k\ell = n}\alpha(n)f(k)g(\ell) \\
    &= \alpha(n)(f\ast g)(n).
    \end{aligned}
    $$
    
    Trong đó, dấu bằng thứ ba dùng tính chất của hàm hoàn toàn nhân tính: $\alpha(n)=\alpha(k)\alpha(\ell)$ đúng với mọi $n=k\ell$.
    
    Với ý thứ hai, dùng ý thứ nhất ta có
    
    $$
    (\alpha f)\ast(\alpha f^{-1}) = \alpha(f\ast f^{-1}) = \alpha\varepsilon = \varepsilon.
    $$
    
    Trong đó, dấu bằng cuối chỉ dùng $\alpha(1)=1$. Theo định nghĩa nghịch đảo, $(\alpha f)^{-1}=\alpha f^{-1}$.
    
    Với ý thứ ba, dùng ý thứ hai và $1^{-1}=\mu$, ta thấy nếu $f$ là hàm hoàn toàn nhân tính thì
    
    $$
    f^{-1} = (1f)^{-1} = 1^{-1}\cdot f = \mu f.
    $$
    
    Trong đó, $1$ là hàm hằng. Ngược lại, nếu $f$ là hàm nhân tính và $f^{-1}=\mu f$, thì chỉ cần chứng minh với mọi số nguyên tố $p$ và $e\in\mathbf N_+$, ta đều có $f(p^e)=f(p)^e$; khi đó suy ra $f$ là hàm hoàn toàn nhân tính. Để làm điều này, áp dụng quy nạp toán học theo $e\in\mathbf N_+$. Cơ sở quy nạp tại $e=1$ là hiển nhiên. Với $e > 1$ bất kỳ, áp dụng công thức truy hồi của nghịch đảo, ta có
    
    $$
    \begin{aligned}
    f^{-1}(p^e) &= -\sum_{i=1}^{e}f(p^i)f^{-1}(p^{e-i}) \\
    &= -\sum_{i=1}^{e}f(p^i)\mu(p^{e-i})f(p^{e-i})\\
    &= -f(p^e)f(1)\mu(1) - f(p^{e-1})\mu(p)f(p)\\
    &= -f(p^e) + f(p)^e.
    \end{aligned}
    $$
    
    Trong đó, dấu bằng cuối dùng giả thiết quy nạp $f(p^{e-1})=f(p)^{e-1}$. Áp dụng $f^{-1}=\mu f$, ta thu được
    
    $$
    f^{-1}(p^e) = \mu(p^e)f(p^e) = 0.
    $$
    
    Thay vào công thức trước, ta được
    
    $$
    f(p^e) = f(p)^e.
    $$
    
    Vì vậy, bước quy nạp đúng. Mệnh đề ban đầu được chứng minh.

Theo ngôn ngữ đại số trừu tượng, nếu $\alpha$ là hàm hoàn toàn nhân tính, ánh xạ $f\mapsto \alpha f$ là một [tự đồng cấu](../algebra/ring-theory.md#%E7%90%86%E6%83%B3) của vành Dirichlet.

<span id="dirichlet-&#x751f;&#x6210;&#x51fd;&#x6570;"></span>
## Hàm sinh Dirichlet

Liên hệ chặt chẽ với tích chập Dirichlet là hàm sinh Dirichlet.

Với hàm số học $f(n)$, tức dãy $\{f(n)\}$, **hàm sinh Dirichlet** (Dirichlet series generating function, DGF) tương ứng được định nghĩa là chuỗi Dirichlet hình thức (formal Dirichlet series):

$$
F(s) = \sum_{n=1}^{\infty}\dfrac{f(n)}{n^s}.
$$

Trong chuỗi này, $s$ là biến hình thức. Với các hàm sinh Dirichlet thường gặp, $s$ nhiều khi có thể xem là biến phức, rồi tiếp tục xét tính chất giải tích của chuỗi Dirichlet; tuy nhiên phần đó vượt ra ngoài phạm vi thi lập trình.

Tích của các hàm sinh Dirichlet tương ứng với tích chập Dirichlet của các hàm số học tương ứng:

???+ note "Định lý"
    Với các hàm số học $f,g$ và các hàm sinh Dirichlet $F,G$ của chúng, hàm sinh của tích chập Dirichlet $f\ast g$ bằng $F\cdot G$.

??? note "Chứng minh"
    Kiểm tra trực tiếp:
    
    $$
    \begin{aligned}
    F(s)G(s) &= \left(\sum_{k=1}^\infty\dfrac{f(k)}{k^s}\right)\left(\sum_{\ell=1}^\infty\dfrac{g(\ell)}{\ell^s}\right)= \sum_{k=1}^\infty\sum_{\ell=1}^\infty\dfrac{f(k)g(\ell)}{(k\ell)^s}\\
    &= \sum_{n=1}^{\infty}\dfrac{\sum_{k\ell = n}f(k)g(\ell)}{n^s} = \sum_{n=1}^\infty\dfrac{(f\ast g)(n)}{n^s}.
    \end{aligned}
    $$

Dựa vào sự tương ứng giữa tích chập Dirichlet và phép nhân hàm sinh Dirichlet, ta có thể hiểu các tính chất của tích chập Dirichlet từ góc nhìn hàm sinh Dirichlet. Vì phép nhân các chuỗi Dirichlet hình thức thỏa luật giao hoán, luật kết hợp và luật phân phối đối với phép cộng, tích chập Dirichlet của các hàm số học cũng thỏa các tính chất đại số tương tự.

<span id="euler-&#x4e58;&#x79ef;"></span>
### Tích Euler

Tính đặc biệt của hàm nhân tính cũng được phản ánh trên hàm sinh Dirichlet. Do số nguyên có [định lý phân tích duy nhất](./basic.md#%E7%AE%97%E6%9C%AF%E5%9F%BA%E6%9C%AC%E5%AE%9A%E7%90%86), hàm sinh $F(s)$ của hàm nhân tính $f(n)$ có thể viết dưới dạng sau:

$$
\begin{aligned}
F(s) &= \sum_{n=1}^{\infty}\dfrac{f(n)}{n^s} = \sum_{n=1}^{\infty}\prod_{p\in\mathbf P}\dfrac{f(p^{e})}{p^{es}} = \prod_{p\in\mathbf P}\sum_{e=0}^{\infty}\dfrac{f(p^e)}{p^{es}}\\
&= \prod_{p\in\mathbf P}\left(1 + \dfrac{f(p)}{p^s} + \dfrac{f(p^2)}{p^{2s}} + \dfrac{f(p^3)}{p^{3s}} + \cdots\right).
\end{aligned}
$$

Điều này nghĩa là $F(s)$ có thể phân tích thành tích của nhiều $F_p(s)$, trong đó mỗi $F_p(s)$ tương ứng với một hàm số học chỉ có thể khác không tại các lũy thừa của $p$. Tích vô hạn này cũng được gọi là **tích Euler** (Euler product). Nếu $F(s)$ và $G(s)$ đều có thể phân tích thành dạng tương tự, thì tích của chúng cũng có dạng đó; chuyển quan sát này về phía hàm số học, ta thu được kết luận rằng tích chập Dirichlet của các hàm nhân tính vẫn là hàm nhân tính.

Hơn nữa, nếu $f(n)$ còn là hàm hoàn toàn nhân tính, thì $f(p^e)=f(p)^e$, nên công thức trên có thể tiếp tục rút gọn:

$$
F(s) = \prod_{p\in\mathbf P}\sum_{e=0}^{\infty}\dfrac{f(p)^e}{p^{es}} = \prod_{p\in\mathbf P}\left(1-\dfrac{f(p)}{p^s}\right)^{-1}.
$$

Khác với hàm nhân tính, dạng hàm sinh Dirichlet của hàm hoàn toàn nhân tính không đóng dưới phép nhân. Vì vậy, tích chập Dirichlet và nghịch đảo Dirichlet của các hàm hoàn toàn nhân tính chưa chắc là hàm hoàn toàn nhân tính, nhưng chắc chắn là hàm nhân tính.

???+ example "Ví dụ"
    1.  Hàm đơn vị $\varepsilon(n)$ là hàm hoàn toàn nhân tính. Hàm sinh Dirichlet của nó là hàm hằng theo biến bất định $s$:
    
        $$
        E(s) = \sum_{n=1}^{\infty}\dfrac{\varepsilon(n)}{n^s} = 1.
        $$
    
    2.  Hàm hằng $1(n)$ là hàm hoàn toàn nhân tính. Hàm sinh Dirichlet của nó là hàm zeta Riemann
    
        $$
        I(s) = \sum_{n=1}^{\infty}\dfrac{1}{n^s} = \prod_{p\in\mathbf P}\dfrac{1}{1-p^{-s}} = \zeta(s).
        $$
    
    3.  Hàm Mobius $\mu(n)$ là nghịch đảo Dirichlet của hàm hằng. Hàm sinh Dirichlet của nó là nghịch đảo của $\zeta(s)$:
    
        $$
        M(s) = \sum_{n=1}^{\infty}\dfrac{\mu(n)}{n^s} = \prod_{p\in\mathbf P}(1-p^{-s}) = \dfrac{1}{\zeta(s)}.
        $$
    
    4.  Hàm lũy thừa $\operatorname{id}_k(n)=n^k$ là hàm hoàn toàn nhân tính. Đặc biệt, khi $k=0$, nó chính là hàm hằng; khi $k=1$, nó chính là hàm đồng nhất. Hàm sinh Dirichlet của nó là
    
        $$
        I_k(s) = \sum_{n=1}^{\infty}\dfrac{n^k}{n^s} = \prod_{p\in\mathbf P}\dfrac{1}{1-p^{k-s}} = \zeta(s-k).
        $$
    
    5.  Hàm Euler $\varphi(n)$ là hàm nhân tính. Hàm sinh Dirichlet của nó là
    
        $$
        \begin{aligned}
        \Phi(s) &= \prod_{p\in\mathbf P}\left(1+\dfrac{p-1}{p^s} + \dfrac{p(p-1)}{p^{2s}} + \dfrac{p^2(p-1)}{p^{3s}}+\cdots\right)\\
        &= \prod_{p\in\mathbf P}\left(\dfrac{1}{1-p^{1-s}}-\dfrac{1}{p^s}\dfrac{1}{1-p^{1-s}}\right) = \prod_{p\in\mathbf P}\dfrac{1-p^{-s}}{1-p^{1-s}} = \dfrac{\zeta(s-1)}{\zeta(s)}.
        \end{aligned}
        $$
    
        Kết hợp với biểu thức hàm sinh Dirichlet của hàm lũy thừa, ta thu được $\mathrm{id} = \varphi\ast 1$.
    
    6.  Hàm tổng ước $\sigma_k(n)=\sum_{d\mid n}d^k$ là hàm nhân tính. Hàm sinh Dirichlet của nó là
    
        $$
        \begin{aligned}
        \Sigma_k(s) &= \prod_{p\in\mathbf P}\left(1+\dfrac{1+p^k}{p^s}+\dfrac{1+p^k+p^{2k}}{p^{2s}}+\dfrac{1+p^k+p^{2k}+p^{3k}}{p^{3s}}+\cdots\right) \\
        &= \prod_{p\in\mathbf P}\dfrac{1}{1-p^k}\left((1-p^k)+\dfrac{1-p^{2k}}{p^s}+\dfrac{1-p^{3k}}{p^{2s}}+\dfrac{1-p^{4k}}{p^{3k}}+\cdots\right)\\
        &= \prod_{p\in\mathbf P}\dfrac{1}{1-p^k}\left(\dfrac{1}{1-p^{-s}} - \dfrac{p^k}{1-p^{k-s}}\right)\\
        &= \prod_{p\in\mathbf P}\dfrac{1}{(1-p^{-s})(1-p^{k-s})} = \zeta(s-k)\zeta(s).
        \end{aligned}
        $$
    
        Kết hợp với biểu thức Dirichlet của hàm lũy thừa, ta thu được $\sigma_k = \mathrm{id}_k\ast 1$. Đây chính là công thức định nghĩa của $\sigma_k$.
    
    7.  Hàm chỉ thị của các số không có thừa số chính phương $u(n)=|\mu(n)|$ là hàm nhân tính. Hàm sinh Dirichlet của nó là
    
        $$
        U(s) = \prod_{p\in\mathbf P}(1+p^{-s}) = \prod_{p\in\mathbf P}\dfrac{1-p^{-2s}}{1-p^{-s}} = \dfrac{\zeta(s)}{\zeta(2s)}.
        $$

<span id="&#x5e94;&#x7528;"></span>
### Ứng dụng

Hàm sinh Dirichlet có thể dùng để biểu diễn hàm nhân tính dưới dạng tích chập Dirichlet.

Ví dụ, trong quá trình dùng sàng Du, để tính tổng tiền tố của một hàm nhân tính $f$, cần tìm một hàm nhân tính khác $g$ sao cho cả $f\ast g$ và $g$ đều có thể tính tổng tiền tố nhanh. Có thể dùng hàm sinh Dirichlet để suy ra quá trình này.

Lấy bài ví dụ [Luogu P3768 Bài toán đơn giản](../number-theory/du.md#%E9%97%AE%E9%A2%98%E4%BA%8C) trong mục sàng Du làm ví dụ. Ta cần xây dựng hàm số học $g(n)$ thỏa điều kiện trên cho $f(n)=n^2\varphi(n)$. Vì $f$ là hàm nhân tính, hàm sinh Dirichlet của nó là

$$
F(s) = \prod_{p\in\mathbf P}\left(1 + \sum_{k=1}^{\infty}\dfrac{p^{3k-1}(p-1)}{p^{ks}}\right) = \prod_{p\in\mathbf P}\dfrac{1-p^{2-s}}{1-p^{3-s}} = \dfrac{\zeta(s-3)}{\zeta(s-2)}.
$$

So sánh với hàm sinh Dirichlet của hàm lũy thừa, chỉ cần lấy $g = \mathrm{id}_2$ thì ta có $f \ast g = \mathrm{id}_3$. Cả hai đều có thể tính tổng tiền tố nhanh.

<span id="dirichlet-&#x5377;&#x79ef;&#x7684;&#x8ba1;&#x7b97;"></span>
## Tính tích chập Dirichlet

Mục này thảo luận bài toán tính tích chập Dirichlet: cho hai dãy $\{f(k)\}_{k=1}^n$ và $\{g(k)\}_{k=1}^n$, cần tìm một số hạng đầu của tích chập Dirichlet $h=f\ast g$, tức $\{h(k)\}_{k=1}^n$. Tùy theo tính chất của các hàm liên quan, độ phức tạp thuật toán cũng hơi khác nhau.

<span id="&#x4e00;&#x822c;&#x60c5;&#x5f62;"></span>
### Trường hợp tổng quát

Nếu $f,g,h$ đều không có tính chất đặc biệt, thì việc tính tích chập Dirichlet chỉ có thể dựa vào định nghĩa:

$$
h(n) = \sum_{k\ell = n}f(k)g(\ell).
$$

Liệt kê $k$ và $\ell$, rồi cộng đóng góp $f(k)g(\ell)$ vào $h(k\ell)$ là đủ. Độ phức tạp liệt kê là

$$
O\left(\sum_{k=1}^{n}\dfrac{n}{k}\right) = O(n\log n).
$$

Cài đặt tham khảo như sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/dirichlet/dirichlet-1.cpp:core"
    ```

<span id="&#x4e0e;&#x79ef;&#x6027;&#x51fd;&#x6570;&#x5377;&#x79ef;&#x7684;&#x60c5;&#x5f62;"></span>
### Trường hợp chập với hàm nhân tính

Nếu $g$ là hàm nhân tính, ta có thể dùng tích Euler để tăng tốc việc tính tích chập Dirichlet. Tính $h$ tương đương với tính các hệ số trong hàm sinh Dirichlet $H$ của nó. Vì

$$
H(s) = F(s)G(s) = F(s)\prod_{p\in\mathbf P}G_p(s).
$$

Trong đó, $G_p(s)$ là thừa số trong phân tích tích Euler của $G(s)$, chỉ chứa các hệ số tại lũy thừa của $p$:

$$
G_p(s) = \sum_{p^k\le n}\dfrac{f(p^k)}{p^{ks}} = 1 + \dfrac{f(p)}{p^s} + \dfrac{f(p^2)}{p^{2s}} + \cdots.
$$

Vậy, bắt đầu từ $F(s)$, duyệt tất cả số nguyên tố $p$ không vượt quá $n$ và lần lượt nhân thêm $G_p(s)$, ta cũng thu được kết quả cuối cùng $H(s)$. Khi nhân thêm $G_p(s)$, chỉ cần áp dụng trực tiếp thuật toán liệt kê vét cạn trong trường hợp tổng quát. Tổng số lần liệt kê là

$$
\sum_{p\in\mathbf P,~p\le n}\sum_{k=1}^{\infty}\left\lfloor\dfrac{n}{p^k}\right\rfloor \le \sum_{p\in\mathbf P,~p\le n}\dfrac{n}{p-1} \le \sum_{p\in\mathbf P,~p\le n}\dfrac{2n}{p} \in O(n\log\log n).
$$

Ước lượng độ phức tạp ở bước cuối giống với chứng minh độ phức tạp của [sàng Eratosthenes](./sieve.md#%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95). Vì vậy, độ phức tạp thời gian của thuật toán này là $O(n\log\log n)$.

Cài đặt tham khảo như sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/dirichlet/dirichlet-2.cpp:core"
    ```

Đặc biệt, khi hàm nhân tính $g$ là hàm hoàn toàn nhân tính hoặc là nghịch đảo Dirichlet của một hàm hoàn toàn nhân tính, chẳng hạn $g = 1$ hoặc $g = \mu$, thuật toán còn có thể được đơn giản hóa hơn nữa. Lúc này, việc tính tích chập Dirichlet $h = f\ast g$ có thể dùng thuật toán [tổng tiền tố/sai phân Dirichlet](./mobius.md#dirichlet-%E5%89%8D%E7%BC%80%E5%92%8C) với hằng số nhỏ hơn, nhưng độ phức tạp thời gian vẫn là $O(n\log\log n)$.

<span id="&#x7ed3;&#x679c;&#x4e3a;&#x79ef;&#x6027;&#x51fd;&#x6570;&#x7684;&#x60c5;&#x5f62;"></span>
### Trường hợp kết quả là hàm nhân tính

Cuối cùng, xét trường hợp $h$ là hàm nhân tính. Đặc biệt, khi $f,g$ đều là hàm nhân tính, $h=f \ast g$ sẽ là hàm nhân tính. Để tính $h$, chỉ cần xác định giá trị của nó tại các lũy thừa nguyên tố, rồi dùng [sàng tuyến tính](./sieve.md#%E7%BA%BF%E6%80%A7%E7%AD%9B%E6%B3%95) để tính trong thời gian $O(n)$. Với giá trị $h(p^e)$ tại lũy thừa nguyên tố $p^e$, ta cứ tính vét cạn trực tiếp:

$$
h(p^e) = \sum_{i=0}^e f(p^i)g(p^{e-i}).
$$

Số lần liệt kê cần thiết cho các phép tính vét cạn này là

$$
\begin{aligned}
\sum_{p\in\mathbf P,~p\le n}\sum_{e=1}^{\lfloor\log_p n\rfloor}(e+1) &\le \sum_{p\in\mathbf P,~p\le\sqrt{n}}\lfloor\log_p n\rfloor^2 + \sum_{p\in\mathbf P,~\sqrt{n} < p\le n}1 \\
&\le \sqrt{n}(\log_2 n)^2 + n \in O(n).
\end{aligned}
$$

Do đó, tổng độ phức tạp thời gian của thuật toán này là $O(n)$.

Cài đặt tham khảo như sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/dirichlet/dirichlet-3.cpp:core"
    ```

<span id="&#x53c2;&#x8003;&#x8d44;&#x6599;&#x4e0e;&#x6ce8;&#x91ca;"></span>
## Tài liệu tham khảo và ghi chú

-   [Dirichlet convolution - Wikipedia](https://en.wikipedia.org/wiki/Dirichlet_convolution)
-   [Dirichlet series - Wikipedia](https://en.wikipedia.org/wiki/Dirichlet_series)
-   [Euler product - Wikipedia](https://en.wikipedia.org/wiki/Euler_product)
-   [Tích Dirichlet và tổng tích lũy của hàm số học by maspy](https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c)
