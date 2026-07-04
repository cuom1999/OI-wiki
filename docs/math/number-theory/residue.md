Kiến thức nền tảng: [Logarit rời rạc](./discrete-logarithm.md)

Bài viết này thảo luận về thặng dư bậc cao và căn đơn vị theo modulo, đồng thời giới thiệu các thuật toán khai căn theo modulo.

<span id="&#39640;&#27425;&#21097;&#20313;"></span>
## Thặng dư bậc cao

Thặng dư bậc cao trong phép toán modulo có thể được hiểu là việc xét khả năng khai lũy thừa bậc cao theo modulo. Đây là một sự tổng quát hóa của [thặng dư bậc hai](./quad-residue.md).

???+ abstract "Thặng dư bậc $k$"
    Cho số nguyên $k\geq 2$, số nguyên $a$ và số nguyên dương $m$ nguyên tố
    cùng nhau. Nếu tồn tại số nguyên $x$ sao cho

    $$
    x^k\equiv a\pmod m,
    $$

    thì $a$ được gọi là **thặng dư bậc $k$** ($k$-th residue) modulo $m$, và
    $x$ được gọi là **căn bậc $k$** ($k$-th root) của $a$ modulo $m$; ngược lại,
    $a$ được gọi là **bất thặng dư bậc $k$** ($k$-th nonresidue) modulo $m$.

Nói cách khác, căn bậc $k$ của $a$ modulo $m$ tồn tại khi và chỉ khi $a$ là
thặng dư bậc $k$ modulo $m$.

<span id="&#24615;&#36136;"></span>
### Tính chất

Tương tự thặng dư bậc hai, ta có thể thảo luận bài toán kiểm tra thặng dư bậc
$k$, số lượng nghiệm và số lớp thặng dư bậc $k$. Giống các bài toán
[phương trình đồng dư](./congruence-equation.md) khác, có thể dùng
[định lí thặng dư Trung Hoa](./crt.md) để đưa chúng về trường hợp modulo lũy
thừa của số nguyên tố. Tùy theo việc căn nguyên thủy có tồn tại hay không,
trường hợp này tiếp tục tách thành modulo lũy thừa của số nguyên tố lẻ và
modulo lũy thừa của $2$.

Trường hợp modulo lũy thừa của số lẻ tương đối đơn giản. Thực ra, trong mọi
trường hợp có căn nguyên thủy, ta có kết quả sau:

???+ note "Định lí"
    Cho số nguyên $k\geq 2$, số nguyên $a$ và số nguyên dương $m$ nguyên tố cùng
    nhau. Giả sử căn nguyên thủy modulo $m$ tồn tại, và $g$ là một căn nguyên
    thủy modulo $m$. Đặt $d=\gcd(k,\varphi(m))$ và
    $d'=\dfrac{\varphi(m)}{d}$, trong đó $\varphi(m)$ là
    [hàm Euler](./euler-totient.md). Khi đó:

    1.  $a$ là thặng dư bậc $k$ modulo $m$ khi và chỉ khi

        $$
        a^{d'} \equiv 1 \pmod m.
        $$
    2.  Khi $a$ là thặng dư bậc $k$ modulo $m$, xét theo đồng dư, $a$ có đúng
        $d$ căn bậc $k$ phân biệt modulo $m$, và chúng có dạng

        $$
        x \equiv g^{y_0+id'}\pmod{m},~0\le y_0 < d',~i=0,1,\cdots,d-1.
        $$
    3.  Số lớp thặng dư bậc $k$ modulo $m$ là $d'$, và toàn bộ các lớp đó là

        $$
        \{g^{di}\bmod m : 0 \le i < d'\}.
        $$

??? note "Chứng minh"
    Vì $a\perp m$, nên $x\perp m$. Vì $g$ là căn nguyên thủy modulo $m$, cả $x$
    và $a$ đều đồng dư với một lũy thừa nào đó của $g$. Đặt
    $x\equiv g^y\pmod m$, phương trình $x^k\equiv a\pmod m$ tương đương với

    $$
    g^{ky} \equiv g^{\operatorname{ind}_g a}\pmod m.
    $$

    Trong đó, $\operatorname{ind}_g a$ là logarit rời rạc. Theo
    [tính chất của bậc](./primitive-root.md#%E5%B9%82%E7%9A%84%E5%BE%AA%E7%8E%AF%E7%BB%93%E6%9E%84)
    và $\delta_m(g)=\varphi(m)$, điều này tương đương với phương trình đồng dư

    $$
    ky \equiv \operatorname{ind}_g a \pmod{\varphi(m)}.
    $$

    Đây là [phương trình đồng dư tuyến tính](./linear-equation.md) theo $y$. Áp
    dụng phân tích về cấu trúc nghiệm ở trang đó, phương trình có nghiệm khi và
    chỉ khi $d\mid\operatorname{ind}_g a$, và nghiệm tổng quát có dạng

    $$
    y = y_0 + id' \pmod{\varphi(m)},~0\le y_0 < d',~i=0,1,\cdots,d-1.
    $$

    Từ đây gần như suy ra toàn bộ nội dung định lí; điểm duy nhất cần giải thích
    thêm là tiêu chuẩn $a^{d'} \equiv 1 \pmod m$. Theo
    [tính chất 3 của bậc](./primitive-root.md#ord-prop-3), ta có

    $$
    \delta_m(a) = \delta_m(g^{\operatorname{ind}_g a}) = \dfrac{\varphi(m)}{\gcd(\varphi(m),\operatorname{ind}_g a)}.
    $$

    Mặt khác, đã biết phương trình có nghiệm khi và chỉ khi
    $d\mid \operatorname{ind}_g a$, tức là $\delta_m(a)\mid d'$. Theo
    [tính chất 2 của bậc](./primitive-root.md#ord-prop-2), điều này tương đương
    với tiêu chuẩn trên.

Trường hợp modulo lũy thừa của $2$ đặc biệt hơn. Để xử lý trường hợp này, cần
dùng một [kết quả](./primitive-root.md#mod-pow-2) về cấu trúc hệ thặng dư thu
gọn modulo $2^e$: mọi số lẻ $a$ đều đồng dư duy nhất với một số có dạng
$(-1)^s5^r\bmod 2^e$, trong đó $s\in\{0,1\}$ và $0\le r < 2^{e-2}$. Nhờ kết quả
này, ta có kết luận sau:

???+ note "Định lí"
    Cho số nguyên $k\ge 2$, số lẻ $a$ và số nguyên dương $m=2^e$ với
    $e \ge 2$. Khi $k$ là số lẻ:

    1.  $a$ luôn là thặng dư bậc $k$ modulo $m$.
    2.  $a$ có đúng một căn bậc $k$ modulo $m$.
    3.  Số lớp thặng dư bậc $k$ modulo $m$ là $2^{e-1}$, và chúng chính là toàn
        bộ các lớp thặng dư thu gọn.

    Khi $k$ là số chẵn, đặt $d=\gcd(k,2^{e-2})$ và
    $d'=\dfrac{2^{e-2}}{d}$, ta có:

    1.  $a$ là thặng dư bậc $k$ modulo $m$ khi và chỉ khi
        $a\equiv 1\pmod 4$ và $a^{d'}\equiv 1\pmod m$.
    2.  Khi $a$ là thặng dư bậc $k$ modulo $m$, xét theo đồng dư, $a$ có đúng
        $2d$ căn bậc $k$ phân biệt modulo $m$, và chúng có dạng

        $$
        x \equiv \pm 5^{y_0 + id'} \pmod{2^e},~ 0 \le y_0 < d',~i = 0, 1,\cdots,d-1.
        $$
    3.  Số lớp thặng dư bậc $k$ modulo $m$ là $d'$, và toàn bộ các lớp đó là

        $$
        \{5^{di}\bmod m : 0 \le i < d'\}.
        $$

??? note "Chứng minh"
    Vì $a\perp m$, nên $x\perp m$. Vì $x$ và $a$ đều là số lẻ, theo kết quả vừa
    nêu, có thể đặt $a\equiv (-1)^s5^r\pmod{2^e}$ và
    $x=(-1)^z5^{y}\pmod{2^e}$. Do biểu diễn là duy nhất, phương trình đồng dư
    $x^k\equiv a\pmod{2^e}$ tương đương với hệ
    [phương trình đồng dư tuyến tính](./linear-equation.md)

    $$
    \begin{aligned}
    kz &\equiv s \pmod{2},\\
    ky &\equiv r \pmod{2^{e-2}}.
    \end{aligned}
    $$

    Kết hợp với phân tích về nghiệm của phương trình đồng dư tuyến tính ở trang
    đó, ta thu được cấu trúc nghiệm của phương trình đồng dư
    $x^k\equiv a\pmod{2^e}$. Tùy theo tính chẵn lẻ của $k$, có hai trường hợp:

    -   Khi $k$ là số lẻ, vì $\gcd(k,2)=\gcd(k,2^{e-2})=1$, cả hai phương trình
        đồng dư tuyến tính đều có nghiệm với mọi $s,r$, nên phương trình ban đầu
        luôn có nghiệm với mọi số lẻ $a$.
    -   Khi $k$ là số chẵn, phương trình thứ nhất có nghiệm khi và chỉ khi
        $2\mid s$, phương trình thứ hai có nghiệm khi và chỉ khi
        $d=\gcd(k,2^{e-2})\mid r$. Kết hợp hai điều kiện này sẽ cho toàn bộ các
        lớp thặng dư bậc $k$. Tính trực tiếp thấy điều kiện thứ nhất tương đương
        với $a\equiv 1\pmod 4$; lặp lại phân tích trong trường hợp modulo lũy
        thừa của số nguyên tố lẻ, điều kiện thứ hai tương đương với $a^{d'}=1$.
        Kết hợp hai điểm này sẽ cho tiêu chuẩn trong định lí. Nghiệm tổng quát
        của hai phương trình đồng dư tuyến tính cũng đã biết:

        $$
        \begin{aligned}
        z &\equiv0,1\pmod 2, \\
        y &\equiv y_0 + id' \pmod{2^{e-2}},~ 0\le y_0 < d',~i=0,1,\cdots,d-1.
        \end{aligned}
        $$

        Kết hợp chúng sẽ thu được nghiệm tổng quát của phương trình ban đầu.

Như vậy, bài toán kiểm tra thặng dư bậc $k$ với các modulo khác nhau đã được
giải quyết đầy đủ. Ký hiệu Legendre và luật tương hỗ bậc hai trong thặng dư bậc
hai cũng có thể tổng quát hóa sang thặng dư bậc cao, nhưng điều này không dễ và
cần đến các khái niệm như
[trường chia đường tròn](../algebra/field-theory.md#%E5%88%86%E5%9C%86%E5%9F%9F).
Trong lý thuyết số đại số, luật tương hỗ bậc hai cuối cùng có thể được tổng
quát thành [luật tương hỗ Artin](https://en.wikipedia.org/wiki/Artin_reciprocity).

<span id="&#21333;&#20301;&#26681;"></span>
## Căn đơn vị

Là một trường hợp đặc biệt của căn bậc $k$, mục này thảo luận khái niệm căn đơn
vị (nguyên thủy) bậc $k$. Nó có thể xem là đối ứng của khái niệm
[căn đơn vị](../complex.md#%E5%8D%95%E4%BD%8D%E6%A0%B9) bậc $k$ trong trường số
phức $\mathbf C$ trên hệ thặng dư thu gọn $\mathbf Z_m^*$ modulo $m$. Khi modulo
$m$ phù hợp, có thể dùng căn đơn vị nguyên thủy bậc $k$ modulo $m$ thay cho căn
phức $\omega_k$ để tăng tốc tính toán.

Tương tự trường hợp trên trường số phức, ta có định nghĩa sau:

???+ abstract "Căn đơn vị bậc $k$ modulo $m$"
    Với modulo $m$, căn bậc $k$ của phần tử $1$ được gọi là **căn đơn vị bậc
    $k$ modulo $m$** ($k$-th root of unity modulo $m$). Đặc biệt, nếu $x$ là một
    căn đơn vị bậc $k$ modulo $m$ và không phải là căn đơn vị bậc $k' < k$ nào
    modulo $m$, thì $x$ được gọi là **căn đơn vị nguyên thủy bậc $k$ modulo
    $m$** ($k$-th primitive root of unity modulo $m$).

So sánh với [định nghĩa căn nguyên thủy](./primitive-root.md#%E5%8E%9F%E6%A0%B9),
ta thấy căn nguyên thủy $g$ chính là căn đơn vị nguyên thủy bậc $\varphi(m)$
modulo $m$, trong đó $\varphi(m)$ là [hàm Euler](./euler-totient.md).

Khi căn đơn vị nguyên thủy bậc $k$ modulo $m$ tồn tại, các tính chất đại số của
nó trùng với căn đơn vị phức nguyên thủy bậc $k$ là $\omega_k$, nên có thể dùng
nó thay $\omega_k$ trong nhiều phép tính. Ví dụ, áp dụng nó vào
[biến đổi Fourier nhanh](../poly/fft.md) sẽ thu được
[biến đổi số học nhanh](../poly/ntt.md) trên trường hữu hạn[^fnnt].

<span id="&#24615;&#36136;_1"></span>
### Tính chất

Trong trường số phức, căn đơn vị (nguyên thủy) bậc bất kỳ đều tồn tại. Nhưng
trong số học, căn đơn vị (nguyên thủy) không phải lúc nào cũng tồn tại.

???+ note "Tính chất"
    Với modulo $m$, đặt $\lambda(m)$ là
    [hàm Carmichael](./primitive-root.md#carmichael-%E5%87%BD%E6%95%B0) của nó.
    Khi đó:

    1.  Mọi số nguyên $a$ nguyên tố cùng nhau với $m$ đều là căn đơn vị nguyên
        thủy bậc $\delta_m(a)$ modulo $m$, trong đó $\delta_m(a)$ là
        [bậc](./primitive-root.md#%E9%98%B6) của $a$ modulo $m$.
    2.  Nếu phần tử $a$ là căn đơn vị bậc $k$ modulo $m$, và $k'$ là một bội bất
        kỳ của $k$, thì $a$ cũng là căn đơn vị bậc $k'$ modulo $m$.
    3.  Nếu phần tử $a$ là căn đơn vị (nguyên thủy) bậc $k$ modulo $m$, thì phần
        tử $a^{\ell}$ là căn đơn vị bậc $\dfrac{k}{\gcd(k,\ell)}$ modulo $m$
        (tương ứng là nguyên thủy).
    4.  Khi $k'$ chạy qua các ước của $k$, toàn bộ căn đơn vị nguyên thủy bậc
        $k'$ modulo $m$ lập thành một phân hoạch của tập căn đơn vị bậc $k$
        modulo $m$. Hơn nữa, với $\ell\perp k$, ánh xạ $x\mapsto x^\ell$ cho
        một song ánh trên các căn đơn vị bậc $k$ và giữ nguyên phân hoạch đó: nó
        vẫn ánh xạ căn đơn vị nguyên thủy bậc $k'\mid k$ thành căn đơn vị nguyên
        thủy bậc $k'$.
    5.  Căn đơn vị nguyên thủy bậc $k$ modulo $m$ tồn tại khi và chỉ khi
        $k\mid\lambda(m)$. Đặc biệt, căn đơn vị nguyên thủy bậc $\lambda(m)$
        modulo $m$ tồn tại và được gọi là **$\lambda$-căn nguyên thủy modulo
        $m$**.
    6.  Phần tử $a$ là căn đơn vị nguyên thủy bậc $k$ modulo $m$ khi và chỉ khi
        $a^k\equiv 1\pmod{m}$ và với mọi ước nguyên tố $p\mid k$ đều có
        $a^{k/p}\not\equiv 1\pmod{m}$.

??? note "Chứng minh"
    Theo định nghĩa của bậc, mọi số nguyên $a$ nguyên tố cùng nhau với $m$ đều
    là căn đơn vị nguyên thủy bậc $\delta_m(a)$ modulo $m$, trong đó
    $\delta_m(a)$ là bậc của $a$ modulo $m$. Ngược lại, nếu $a$ là căn đơn vị
    bậc $k$ modulo $m$, thì $\gcd(a^k,m)=1$, nên $\gcd(a,m)=1$. Do đó, $a$ là
    căn đơn vị (nguyên thủy) modulo $m$ khi và chỉ khi $a$ nguyên tố cùng nhau
    với $m$. Đây là tính chất 1.

    Kiểm tra trực tiếp từ định nghĩa thấy rằng chỉ cần $k\mid k'$, từ
    $a^k\equiv 1\pmod m$ suy ra $a^{k'}\equiv 1\pmod m$; đây là tính chất 2.
    Theo [tính chất của bậc](./primitive-root.md#ord-prop-3), ta có

    $$
    \delta_m(a^\ell) = \dfrac{\delta_m(a)}{\gcd(\delta_m(a),\ell)}.
    $$

    Nếu $a$ là căn đơn vị nguyên thủy bậc $k$ modulo $m$, thì $\delta_m(a)=k$;
    thay trực tiếp vào công thức trên sẽ được $a^\ell$ là căn đơn vị nguyên thủy
    bậc $\dfrac{k}{\gcd(k,\ell)}$ modulo $m$. Nếu $a$ chỉ là căn đơn vị bậc $k$
    modulo $m$, giả sử nó là căn đơn vị nguyên thủy bậc $k'\mid k$, thì
    $a^\ell$ là căn đơn vị nguyên thủy bậc $\dfrac{k'}{\gcd(k',\ell)}$ modulo
    $m$. Vì $k'\mid k$, ta có

    $$
    \dfrac{k'}{\gcd(k',\ell)} \mid \dfrac{k}{\gcd(k,\ell)},
    $$

    rồi theo tính chất 2, $a^\ell$ là căn đơn vị bậc
    $\dfrac{k}{\gcd(k,\ell)}$ modulo $m$. Đây là tính chất 3.

    Với $k'\mid k$, theo tính chất 2, căn đơn vị nguyên thủy bậc $k'$ modulo
    $m$ tất nhiên là căn đơn vị bậc $k$ modulo $m$. Các tập này đôi một không
    giao nhau, nên tạo thành một phân hoạch. Với $\ell\perp k$, luôn có
    $\ell\perp k'$, do đó nếu $a$ là căn đơn vị nguyên thủy bậc $k'$ modulo $m$
    thì $a^\ell$ vẫn là căn đơn vị nguyên thủy bậc $k'$ modulo $m$. Lấy
    $\ell'=\ell^{-1}\bmod k$, có thể kiểm tra $x\mapsto x^\ell$ và
    $x\mapsto x^{\ell'}$ là hai ánh xạ ngược nhau; vì vậy $x\mapsto x^\ell$ là
    song ánh. Đây là tính chất 4.

    Theo tính chất của hàm Carmichael, căn đơn vị nguyên thủy bậc $\lambda(m)$
    modulo $m$ luôn tồn tại; gọi nó là $a$, với $\delta_m(a)=\lambda(m)$. Với
    $k\mid\lambda(m)$, đặt $k'=\dfrac{\lambda(m)}{k}$, luôn có

    $$
    \delta_m(a^{k'}) = \dfrac{\lambda(m)}{(\lambda(m),k')} = \dfrac{\lambda(m)}{k'} = k.
    $$

    Vì vậy, $a^{k'}$ là căn đơn vị nguyên thủy bậc $k$. Mặt khác, theo định
    nghĩa hàm Carmichael, bậc của mọi $x\perp m$ đều là ước của $\lambda(m)$.
    Suy ra tính chất 5.

    Gần như lặp lại chứng minh của
    [định lí kiểm tra căn nguyên thủy](./primitive-root.md#%E5%8E%9F%E6%A0%B9%E5%88%A4%E5%AE%9A%E5%AE%9A%E7%90%86)
    sẽ thu được tính chất 6. Tiêu chuẩn này thực chất đang kiểm tra
    $\delta_m(a)=k$.

Từ các tính chất trên có thể thấy, so với trường hợp tồn tại căn nguyên thủy,
$\lambda$-căn nguyên thủy modulo $m$ đóng vai trò nền tảng tương tự. Khác với
căn nguyên thủy, các lũy thừa của $\lambda$-căn nguyên thủy không thể sinh ra
toàn bộ các căn đơn vị modulo $m$. Dù vậy, vì mật độ của $\lambda$-căn nguyên
thủy không quá thấp[^lambda-density], nếu cần tìm một căn đơn vị nguyên thủy bậc
$k$, có thể trước hết dùng phương pháp ngẫu nhiên để tìm một $\lambda$-căn
nguyên thủy, rồi lấy lũy thừa của nó để thu được căn đơn vị nguyên thủy bậc
$k$.

Nếu đã biết một căn bậc $k$ của $a$ modulo $m$, có thể dùng toàn bộ căn đơn vị
bậc $k$ modulo $m$ để sinh ra toàn bộ căn bậc $k$ của $a$ modulo $m$.

???+ note "Định lý"
    Giả sử $x$ là một căn bậc $k$ của $a$ modulo $m$. Khi $r$ chạy qua toàn bộ
    các căn đơn vị bậc $k$ modulo $m$, $xr$ chạy qua toàn bộ các căn bậc $k$ của
    $a$ modulo $m$.

??? note "Chứng minh"
    Với hai căn bậc $k$ là $x,y$ của $a$ modulo $m$, đặt
    $r=x^{-1}y\bmod m$. Khi đó $r$ thỏa mãn $r^k\equiv 1\pmod m$, nên là căn
    đơn vị bậc $k$ modulo $m$. Ngược lại, nếu $r$ là căn đơn vị bậc $k$ modulo
    $m$, thì $(xr)^{k}= x^kr^k\equiv a\pmod m$, tức là $xr$ là căn bậc $k$ của
    $a$ modulo $m$.

Dùng căn đơn vị bậc $k$ để sinh ra toàn bộ căn bậc $k$ tương tự việc dùng nghiệm
của hệ phương trình tuyến tính thuần nhất để sinh nghiệm tổng quát của hệ phương
trình tuyến tính không thuần nhất.

Phần trên thảo luận trường hợp tổng quát. Riêng khi căn nguyên thủy tồn tại, cấu
trúc của căn đơn vị đơn giản hơn:

???+ note "Định lý"
    Với modulo $m$, giả sử căn nguyên thủy modulo $m$ tồn tại, và $a$ là căn đơn
    vị nguyên thủy bậc $k$ modulo $m$. Khi đó, $b$ là căn đơn vị bậc $k$ modulo
    $m$ khi và chỉ khi $b$ có thể biểu diễn thành một lũy thừa của $a$.

??? note "Chứng minh"
    Gọi $g$ là căn nguyên thủy modulo $m$. Khi đó mọi phần tử nguyên tố cùng
    nhau với $m$ đều có thể biểu diễn thành một lũy thừa của $g$. Do đó, $a$ là
    căn đơn vị nguyên thủy bậc $k$ modulo $m$ khi và chỉ khi

    $$
    \delta_m(a) = \delta_m(g^{\operatorname{ind}_ga}) = \dfrac{\varphi(m)}{\gcd(\varphi(m),\operatorname{ind}_ga)} = k.
    $$

    Tương tự, $b$ là căn đơn vị bậc $k$ modulo $m$ khi và chỉ khi

    $$
    \delta_m(b) = \delta_m(g^{\operatorname{ind}_gb}) = \dfrac{\varphi(m)}{\gcd(\varphi(m),\operatorname{ind}_gb)} = k' \mid k.
    $$

    Vì vậy, ta có

    $$
    \gcd(\varphi(m),\operatorname{ind}_ga) \mid \gcd(\varphi(m),\operatorname{ind}_gb)\mid \operatorname{ind}_gb.
    $$

    Theo [phân tích](./linear-equation.md) về phương trình đồng dư tuyến tính,
    điều kiện này tương đương với việc phương trình

    $$
    (\operatorname{ind}_ga) x \equiv \operatorname{ind}_gb \pmod{\varphi(m)}
    $$

    có nghiệm. Lấy lũy thừa cơ số $g$ cho điều kiện này sẽ được
    $a^x\equiv b\pmod{m}$, tức là $b$ có thể biểu diễn thành một lũy thừa của
    $a$.

Định lí này cho thấy, khi căn nguyên thủy tồn tại, toàn bộ các căn đơn vị bậc
$k$ có cấu trúc [nhóm cyclic](../algebra/group-theory.md#%E5%BE%AA%E7%8E%AF%E7%BE%A4),
và các căn đơn vị nguyên thủy bậc $k$ là phần tử sinh của nhóm cyclic đó. Ngay
sau đây ta sẽ thấy thuật toán Tonelli-Shanks tận dụng điểm này để tăng tốc phần
tính logarit rời rạc trong phép khai căn.

<span id="&#27169;&#24847;&#20041;&#19979;&#24320;&#26041;"></span>
## Khai căn theo modulo

Cuoi cung, bai viet thao luan cach tim can bac $k$. Voi $k=2$, co [nhieu thuat toan hieu qua](./quad-residue.md#%E6%A8%A1%E6%84%8F%E4%B9%89%E4%B8%8B%E5%BC%80%E5%B9%B3%E6%96%B9) de khai can bac hai theo modulo. Tuy nhien, voi $k$ tong quat, hien chua biet thuat toan thoi gian da thuc. Muc nay gioi thieu hai thuat toan pho bien, lan luot co the tim mot can bac $k$ trong thoi gian $O(m^{1/2})$ va $O(m^{1/4+\varepsilon})$. Dung dinh ly thang du Trung Hoa luon co the dua bai toan ve truong hop modulo luy thua cua so nguyen to, vi vay muc nay chu yeu thao luan loi giai trong truong hop modulo luy thua cua so nguyen to.

<span id="&#26420;&#32032;&#31639;&#27861;"></span>
### Thuật toán trực tiếp

[Phan tich](#%E6%80%A7%E8%B4%A8) ve tinh chat cua thang du bac $k$ o tren thuc ra da chi ra mot cach tim can bac $k$ theo modulo luy thua cua so nguyen to. Noi chinh xac, phan tren da giai quyet truong hop so duoc khai can $a$ nguyen to cung nhau voi modulo $m$. Qua trinh thuat toan tom tat nhu sau:

-   Khi $m=p^e$ la luy thua cua so nguyen to le, gia su $g$ la mot can nguyen thuy modulo $m$. Khi do, phuong trinh $x^k\equiv a\pmod m$ co the chuyen thanh phuong trinh dong du tuyen tinh

    $$
    ky \equiv \operatorname{ind}_g a \pmod{\varphi(m)}.
    $$

    Trong do, $\operatorname{ind}_g a$ co the duoc tinh bang [thuat toan BSGS](./discrete-logarithm.md#%E5%A4%A7%E6%AD%A5%E5%B0%8F%E6%AD%A5%E7%AE%97%E6%B3%95), con toan bo nghiem cua [phuong trinh dong du tuyen tinh](./linear-equation.md) thi de tim. Tu do thu duoc tat ca can bac $k$ cua $a$, co dang $x\equiv g^y\pmod m$.

    Ngoai ra con mot y tuong tuong tu. Van dat $x\equiv g^y\pmod m$, co the bien doi

    $$
    x^k \equiv (g^k)^y \equiv a \pmod m
    $$

    thanh bai toan tim logarit roi rac cua $a$ voi co so $g^k$. Bai toan nay cung co the dung BSGS de tim mot nghiem rieng. Nghiem tong quat cua no co the suy ra tu bieu thuc nghiem o phan tren, tuc la nhan nghiem rieng lan luot voi toan bo can don vi bac $k$.

    Du dung y tuong nao, khi da biet can nguyen thuy, do phuc tap de tim mot nghiem cua thuat toan nay la $O(m^{1/2})$. Vi co the tim mot can nguyen thuy trong thoi gian $o(m^{1/2})$, tong do phuc tap van la $O(m^{1/2})$.

-   Khi $m=2^e$ va $e\in\mathbf N_+$, truoc het co the tim $s,r$ trong $a\equiv (-1)^s5^r\pmod m$. Trong hai so mu nay, $s$ co the xac dinh trong $O(1)$:

    $$
    s = \begin{cases}0, & a\equiv 1\pmod 4, \\ 1, & a\equiv 3\pmod 4.\end{cases}
    $$

    Con $r=\operatorname{ind}_5((-1)^sa)$ co the tinh bang thuat toan BSGS trong $O(m^{1/2})$. Tiep theo chi can giai he phuong trinh dong du tuyen tinh:

    $$
    \begin{aligned}
    kz &\equiv s \pmod{2},\\
    ky &\equiv r \pmod{2^{e-2}}.
    \end{aligned}
    $$

    Nghiem tong quat $(z,y)$ cua he tuyen tinh nay de tim, va $x=(-1)^z5^y$ chinh la can can tim. Do phuc tap de tim mot nghiem cua thuat toan nay van la $O(m^{1/2})$.

Tat nhien, voi truong hop vo nghiem, thuc ra co the dung tieu chuan da neu o tren de kiem tra nhanh trong $O(\log m)$, khong can doi den qua trinh giai moi phat hien.

Ma tham khao de tim can bac $k$ modulo so nguyen to nhu sau: (ma chi mang tinh minh hoa; do do phuc tap qua cao, khong the vuot qua bai nay)

??? example "Bài mẫu [Library Checker - Kth Root (Mod)](https://judge.yosupo.jp/problem/kth_root_mod), mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/residue/bsgs-mod-p.cpp"
    ```

<span id="&#25913;&#33391; Tonelli&#8211;Shanks &#31639;&#27861;"></span>
### Thuật toán Tonelli-Shanks cải tiến

Mo rong phu hop [thuat toan Tonelli-Shanks](./quad-residue.md#tonellishanks-%E7%AE%97%E6%B3%95) dung cho khai can bac hai theo modulo se giai quyet duoc phep khai can theo modulo luy thua cua so nguyen to. Mot cach mo rong truc tiep hon la thuat toan Adleman-Manders-Miller[^amm], nhung do phuc tap cua no van chua du tot[^amm-comp]. Muc nay gioi thieu thuat toan Tonelli-Shanks cai tien do sugarknri, Min\_25, 37zigen va nhung nguoi khac de xuat. No co the tim mot can bac $k$ trong thoi gian $O(m^{1/4+\varepsilon})$.

Y tuong cot loi cua thuat toan Tonelli-Shanks la dua viec tinh logarit roi rac vao nhom co cap $2^e$, tu do giam do phuc tap. Tuong tu, logarit roi rac trong nhom co cap la luy thua nguyen to bat ky $p^e$ cung co the duoc giai kha hieu qua, nhung do phuc tap cua thuat toan la $\Omega\left(\sqrt{p}\right)$. Thuat toan Adleman-Manders-Miller tach viec tim can bac $k$ thanh nhieu phep tinh logarit roi rac trong cac nhom co cap la luy thua nguyen to, nhung do bi gioi han boi kich thuoc cua thua so nguyen to lon nhat $p_\text{max}(k)$ cua $k$, do phuc tap van la $\Omega\left(\sqrt{p_\text{max}(k)}\right)$. Thuat toan trong muc nay cai tien them qua trinh do, tranh tinh logarit roi rac voi cac thua so nguyen to lon, va khong che tong do phuc tap o muc $O(m^{1/4+\varepsilon})$.

<span id="&#36807;&#31243;"></span>
#### Quy trình

Xet viec tinh can bac $k$ cua $a$ modulo luy thua so nguyen to $m$, tuc la giai phuong trinh dong du:

$$
x^k \equiv a \pmod m.
$$

Dac biet, voi truong hop $m=2^e$, con can bao dam $a\equiv 1\pmod{4}$, de $a$ co the viet thanh luy thua cua $g=5$. Tuong tu phan da thao luan, viec tinh can bac $k$ modulo $2^e$ luon co the chuyen ve truong hop nay. Khi xu ly truong hop modulo $2^e$, moi $\varphi(m)$ duoc nhac den trong muc nay deu nen thay bang $\delta_m(5)=2^{e-2}$.

Truoc het, bai toan co the duoc dua ve truong hop bac khai can chia het $\varphi(m)$. Dat $d=\gcd(k,\varphi(m))$. Khi do, theo tinh chat cua thang du bac $k$, neu $a$ la thang du bac $k$ modulo $m$, thi $a$ luon la can don vi bac $\dfrac{\varphi(m)}{d}$ modulo $m$. Theo tinh chat cua can don vi, voi moi $\ell\perp\dfrac{\varphi(m)}{d}$, anh xa $x\mapsto x^{\ell}$ deu la song anh tren cac can don vi bac $\dfrac{\varphi(m)}{d}$. Vi vay co the chon

$$
\ell = \left(\dfrac{k}{d}\right)^{-1}\bmod\dfrac{\varphi(m)}{d}.
$$

Lay luy thua bac $\ell$ hai ve cua phuong trinh dong du ban dau, ta duoc

$$
x^d\equiv x^{k\ell} \equiv a^{\ell} =: b \pmod{m}.
$$

Dong du dau tien dung [dinh ly Euler](./fermat.md#%E6%AC%A7%E6%8B%89%E5%AE%9A%E7%90%86) va quan he dong du sau: ($c\in\mathbf Z$)

$$
k\ell = d\left(\frac{k}{d}\ell\right) = d\left(c\dfrac{\varphi(m)}{d}+1\right) \equiv d \pmod{\varphi(m)}.
$$

Voi bai toan da chuyen doi, xet phan tich thua so nguyen to cua $d$:

$$
d = \prod_{p\in\mathbf P}p^e.
$$

Co the bat dau tu $b=a^\ell$, voi moi $p^e\neq 1$ thi lan luot khai can bac $p^e$; cuoi cung se thu duoc can bac $d$ cua $b$, cung chinh la can bac $k$ cua $a$.

Sau cung, bai toan chuyen thanh cach tim nghiem cua phuong trinh

$$
x^{p^e} \equiv b \pmod m.
$$

Khong mat tinh tong quat, gia su $\varphi(m)=p^sr$ va $p\perp r$. Goi $q\in\mathbf N_+$ la nghiem cua phuong trinh $qr\equiv -1\pmod{p^e}$. Khi do, vi $b$ la can don vi bac $rp^{s-e}$, $b^{qr}$ chac chan la can don vi bac $p^{s-e}$. Lai goi $\zeta$ la can don vi nguyen thuy bac $p^s$ modulo $m$. Khi do $\zeta^{p^e}$ la can don vi nguyen thuy bac $p^{s-e}$, nen ton tai $h\in\mathbf N$ sao cho $b^{qr}\equiv \zeta^{hp^{e}}\pmod{m}$. Vi vay, kiem tra truc tiep cho thay

$$
x\equiv b^{(qr+1)/p^e}\zeta^{-h} \pmod{m}
$$

la mot can bac $p^e$ cua $b$ modulo $m$.

De tinh $x$, can tim mot bat thang du bac $p$ la $\eta$ modulo $m$. Theo cac tinh chat da neu, chi can chon ngau nhien $\eta\perp m$ va kiem tra $\eta^{\varphi(m)/p}\bmod{m}\neq 1$. Mat do cua cac so nhu vay la

$$
\dfrac{\varphi(m)}{m}\left(1-\dfrac{1}{p}\right) \ge \dfrac{1}{4}.
$$

Do do, ky vong chi can thu khong qua $4$ so nguyen de tim duoc no. Chu y rang $\eta^{rp^{s-1}}\not\equiv 1\pmod m$ va $\eta^{rp^s}\equiv 1\pmod m$, nen neu dat $\zeta=\eta^r\bmod m$ va $\xi=\eta^{rp^{s-1}}\bmod m$, thi chung lan luot la can don vi nguyen thuy bac $p^s$ va bac $p$.

Cuoi cung, can tinh $h\in\mathbf N$. Hien nhien co the lay $h < p^{s-e}$. Xet bieu dien co so $p$ cua $h$:

$$
h = \sum_{j=0}^{s-e-1}h_jp^j = h_0 + h_1p + h_2p^2 +\cdots.
$$

Tinh tung chu so nay. Khi $j$ chu so dau da duoc tinh xong, tat yeu co

$$
\left(b^{qr}\zeta^{-p^e(h_0+h_1p+\cdots + h_{j-1}p^{j-1})}\right)^{p^{s-e-j-1}} \equiv \zeta^{h_jp^{s-1}} \equiv \xi^{h_j} \pmod{m}.
$$

Vi vay, $h_j$ co the tim bang cach tinh logarit roi rac theo co so $\xi$. De co do phuc tap tot hon, can dung thuat toan BSGS. Tong cong can tinh logarit roi rac $(s-e)$ lan; gia su tien xu ly $B$ luy thua cua $\xi$, thi thoi gian cho mot lan giai logarit roi rac la $O(p/B)$, va tong do phuc tap la

$$
O\left(B+(s-e)\dfrac{p}{B}\right).
$$

Khi $B=\sqrt{(s-e)p}$, tong do phuc tap dat nho nhat, bang $O\left(\sqrt{(s-e)p}\right)$. Sau khi thu duoc $h$, thay vao bieu thuc cua $x$ o tren se tim duoc mot nghiem rieng.

<span id="&#26102;&#38388;&#22797;&#26434;&#24230;"></span>
#### Độ phức tạp thời gian

Do phuc tap thoi gian cua thuat toan nay la $O(m^{1/4+\varepsilon})$. Khi thao luan ve do phuc tap trong muc nay, luon gia su mot phep nhan mat $O(1)$ thoi gian, va khi tinh luy thua thi luon dung dinh ly Euler de giam so mu; vi vay viec tinh tung luy thua lien quan luon co the hoan thanh trong $O(\log m)$.

Truoc het xet viec tinh mot can bac $p^e$. Tim bat thang du bac $p$ chi can kiem tra ky vong $O(1)$ so, tong thoi gian la $O(\log m)$. Tinh $s,r,\zeta,\eta,b^{qr}$ moi phan chi can $O(\log m)$. Khi tinh $h$, moi chu so can $O(\log m)$ thoi gian de tinh luy thua; tong cong co $(s-e)$ chu so, nen tong do phuc tap la $O((s-e)\log m)$. Phan tren da chi ra rang tong thoi gian tien xu ly va $(s-e)$ truy van de tinh logarit roi rac la $O\left(\sqrt{(s-e)p}\right)$. Vi $s-e\in O(\log m)$, do phuc tap thoi gian de tinh mot can bac $p^e$ la $O(p^{1/2+\varepsilon})$. Dac biet, khi $s=e$, do phuc tap co the giam them xuong $O(\log m)$.

Tiep theo xet tong do phuc tap cua thuat toan. Viec tinh $\varphi(m),d,\ell$ deu co do phuc tap $O(\log m)$. Ngay sau do can phan tich thua so nguyen to $d=\prod_p{p^e}$; buoc nay co the dung [thuat toan Pollard Rho](./pollard-rho.md#pollard-rho-%E7%AE%97%E6%B3%95) trong $O(m^{1/4})$. Cuoi cung, tong thoi gian de lan luot khai can bac $p^e$ la

$$
O\left(\sum_{e < s}p^{1/2+\varepsilon}\right).
$$

Vi moi thua so nguyen to $p$ thoa man $e < s$ xuat hien it nhat $2$ lan trong $\varphi(m)$, nen chac chan $p < m^{1/2}$. Do do, tong do phuc tap thoi gian la $O(m^{1/4+\varepsilon})$.

Thuc ra, trong boi canh nay, khong can dung thuat toan Pollard Rho de phan tich thua so nguyen to ma van co the dat do phuc tap $O(m^{1/4+\varepsilon})$. Chi can thu chia truc tiep $d$ va chi liet ke cac thua so nguyen to khong vuot qua $m^{1/4}$. Goi so nguyen con lai sau khi loai cac thua so nho nay la $z$. Khi do, voi thua so nguyen to $p > m^{1/4}$ cua $z$, chac chan co $\nu_p(\varphi(m)) < 4$, trong do $\nu_p(n)$ la so mu cua $p$ trong phan tich thua so nguyen to cua $n$. Vi chi can xet truong hop

$$
1 \le e = \nu_p(d) < s = \nu_p(\varphi(m)) < 4
$$

nen thua so nguyen to $p$ thoa man dieu kien nay nhieu nhat chi co mot; neu khong, chung deu xuat hien trong $\varphi(m)$ voi so mu it nhat $2$, va tich tong se vuot qua $m$. De tach thua so nguyen to lon duy nhat nay (neu ton tai), chi can tinh

$$
p^\star=\gcd\left(z,\dfrac{\varphi(m)}{z}\right) = \prod_{p : \nu_p(d) < \nu_p(\varphi(m))}p^{\min\{\nu_p(d),\nu_p(\varphi(m))-\nu_p(d)\}}.
$$

Liet ke moi kha nang cua $\nu_p(d),\nu_p(\varphi(m))$ cho thay so mu cua $p$ trong tich chac chan bang $1$, vi vay gia tri tinh duoc chinh la thua so nguyen to lon duy nhat $p^\star$ (neu ton tai). Phan con lai $z/p^\star$ chi co the gom mot so thua so nguyen to thoa man $e=s$, nen khong can tiep tuc phan tich.

Ma tham khao de tim can bac $k$ modulo so nguyen to nhu sau:

??? example "Bài mẫu [Library Checker - Kth Root (Mod)](https://judge.yosupo.jp/problem/kth_root_mod), mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/residue/tonelli-shanks-mod-p.cpp"
    ```

<span id="&#19968;&#33324;&#24773;&#24418;&#30340;&#22788;&#29702;"></span>
### Xử lý trường hợp tổng quát

Xet truong hop tong quat, van gia su modulo $m$ la luy thua so nguyen to $p^e$, nhung $\gcd(a,m)>1$. Neu $a\equiv 0\pmod{m}$, thi

$$
x = p^{\lceil e/k \rceil}\ell\pmod{p^e},~\ell=0,1,\cdots,p^{e-\lceil e/k\rceil}-1
$$

deu la nghiem cua phuong trinh ban dau. Tiep theo xet truong hop $a\not\equiv 0\pmod{m}$. Dat $a = p^sa'$ va $p\perp a'$. Khi do, dat $x=p^zx'$ va $p\perp x'$, ta co

$$
x^k = p^{kz}(x')^k\equiv p^sa'\pmod{p^e}.
$$

Vi $(x')^k\perp p$, cong thuc tren dung khi va chi khi $kz = s$ va $(x')^k\equiv a'\pmod{p^{e-s}}$. Phuong trinh thu nhat co nghiem $z=\dfrac{s}{k}$ khi va chi khi $k\mid s$; con phuong trinh thu hai da duoc giai o tren. Can chu y rang do modulo cua nghiem tong quat trong phuong trinh thu hai khac voi modulo cua nghiem tong quat ban dau, moi nghiem $x'$ cua phuong trinh thu hai tuong ung voi mot so nghiem cua phuong trinh ban dau:

$$
x \equiv p^{s/k}(x' + \ell p^{e-s})\pmod{p^e},~\ell = 0,1,\cdots, p^{s-s/k}-1.
$$

Ma tham khao de tim toan bo can bac $k$ theo modulo bat ky nhu sau:

??? example "Bài mẫu [Luogu P5668 - mẫu N-th residue](https://www.luogu.com.cn/problem/P5668), mã tham khảo"
    === "Thuật toán trực tiếp"
        ```cpp
        --8<-- "docs/math/code/residue/bsgs.cpp"
        ```
    
    === "Thuật toán Tonelli-Shanks cải tiến"
        ```cpp
        --8<-- "docs/math/code/residue/tonelli-shanks.cpp"
        ```

<span id="&#21442;&#32771;&#36164;&#26009;&#19982;&#27880;&#37322;"></span>
## Tài liệu tham khảo và ghi chú

-   Feng Keqin. Elementary Number Theory and Its Applications.
-   [Root of unity modulo n - Wikipedia](https://en.wikipedia.org/wiki/Root_of_unity_modulo_n)
-   [No.981 General Power Root, editorial by 37zigen](https://yukicoder.me/problems/no/981/editorial)

[^fnnt]: Thuc ra, modulo $m$ khong nhat thiet la so nguyen to. Chi can $a$ la can don vi nguyen thuy bac $k=2^e$ modulo $m$, no co the duoc dung cho bien doi so hoc nhanh modulo $m$. Tuy nhien, vi $2^e$ can xu ly thuong kha lon, moi thua so nguyen to cua modulo $m$ phai co dang $c2^e+1$. Do do chi mot thua so nguyen to da rat lon, con modulo $m$ thuong lon hon nua; vi vay truong hop modulo tong quat khong thong dung bang truong hop modulo so nguyen to.

[^lambda-density]: Theo [ket qua ve so luong can nguyen thuy](./primitive-root.md#%E5%8E%9F%E6%A0%B9%E4%B8%AA%E6%95%B0), so luong $\lambda$-can nguyen thuy dung bang $\varphi(\lambda(m))$, trong do $\varphi(\cdot)$ va $\lambda(\cdot)$ lan luot la ham Euler va ham Carmichael. Vi voi hau het so nguyen $m$, ta co $\lambda(m)/m = \exp(-(1+o(1))\log\log m\log\log\log m)$, va ton tai $C > 0$ sao cho voi moi so nguyen $m > 2$ deu co $\varphi(m)/m = C / \log\log m$, nen voi hau het so nguyen $m$, ta co $\varphi(\lambda(m))/m = \exp(-(1+o(1))\log\log m\log\log\log m)$. O day, $o(1)$ trong he so cua phan mu da hap thu dong gop cua thua so $\varphi(\lambda(m))/\lambda(m)$. Vi vay, co the tim $\lambda$-can nguyen thuy sau ky vong $\exp((1+o(1))\log\log m\log\log\log m)$ lan thu. Ve uoc luong cho ham Euler, co the tham khao bai bao Rosser, J. Barkley, and Lowell Schoenfeld. "Approximate formulas for some functions of prime numbers." Illinois Journal of Mathematics 6, no. 1 (1962): 64-94. Ve uoc luong cho ham Carmichael, co the tham khao bai bao Erdos, Paul, Carl Pomerance, and Eric Schmutz. "Carmichael's lambda function." Acta Arith 58, no. 4 (1991): 363-385.

[^amm]: Bai bao goc: Adleman, Leonard, Kenneth Manders, and Gary Miller. "On taking roots in finite fields." In 18th Annual Symposium on Foundations of Computer Science (sfcs 1977), pp. 175-178. IEEE Computer Society, 1977. Mot phan gioi thieu de doc hon co trong Cao, Zhengjun, Qian Sha, and Xiao Fan. "Adleman-Manders-Miller root extraction method revisited." In International Conference on Information Security and Cryptology, pp. 77-85. Berlin, Heidelberg: Springer Berlin Heidelberg, 2011.

[^amm-comp]: Vi thuat toan nay yeu cau $k$ la so nguyen to, trong truong hop xau nhat no can tim can bac $p$ cua $a$ modulo $m$, voi $p$ la thua so nguyen to lon nhat cua $\varphi(m)$. Trong qua trinh nay, can tinh logarit roi rac cua $a$ modulo $m$ theo can don vi nguyen thuy bac $p$. Ngay ca khi dung thuat toan BSGS, qua trinh nay cung can $O(\sqrt{p})$ thoi gian. Tuy nhien, bai bao Fouvry, Etienne. "Theoreme de Brun-Titchmarsh; application au theoreme de Fermat." Inventiones mathematicae 79, no. 2 (1985): 383-407 chi ra rang ton tai mot tap so nguyen to $m$ co mat do duong sao cho thua so nguyen to lon nhat $p$ cua $\varphi(m)=m-1$ thoa man $p=\Omega(m^{2/3})$. Dieu nay co nghia do phuc tap cua thuat toan it nhat la $\Omega(m^{1/3})$, kem hon thuat toan Tonelli-Shanks cai tien duoc gioi thieu trong bai.
