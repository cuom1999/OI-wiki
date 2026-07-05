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
    [hàm Carmichael](./primitive-root.md#hàm-carmichael) của nó.
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

Cuối cùng, bài viết thảo luận cách tìm căn bậc $k$. Với $k=2$, có
[nhiều thuật toán hiệu quả](./quad-residue.md#%E6%A8%A1%E6%84%8F%E4%B9%89%E4%B8%8B%E5%BC%80%E5%B9%B3%E6%96%B9)
để khai căn bậc hai theo modulo. Tuy nhiên, với $k$ tổng quát, hiện chưa biết
thuật toán thời gian đa thức. Mục này giới thiệu hai thuật toán phổ biến, lần
lượt có thể tìm một căn bậc $k$ trong thời gian $O(m^{1/2})$ và
$O(m^{1/4+\varepsilon})$. Dùng định lí thặng dư Trung Hoa luôn có thể đưa bài
toán về trường hợp modulo lũy thừa của số nguyên tố, vì vậy mục này chủ yếu
thảo luận lời giải trong trường hợp modulo lũy thừa của số nguyên tố.

<span id="&#26420;&#32032;&#31639;&#27861;"></span>
### Thuật toán trực tiếp

[Phân tích](#%E6%80%A7%E8%B4%A8) về tính chất của thặng dư bậc $k$ ở trên thực
ra đã chỉ ra một cách tìm căn bậc $k$ theo modulo lũy thừa của số nguyên tố.
Nói chính xác, phần trên đã giải quyết trường hợp số được khai căn $a$ nguyên tố
cùng nhau với modulo $m$. Quá trình thuật toán tóm tắt như sau:

-   Khi $m=p^e$ là lũy thừa của số nguyên tố lẻ, giả sử $g$ là một căn nguyên
    thủy modulo $m$. Khi đó, phương trình $x^k\equiv a\pmod m$ có thể chuyển
    thành phương trình đồng dư tuyến tính

    $$
    ky \equiv \operatorname{ind}_g a \pmod{\varphi(m)}.
    $$

    Trong đó, $\operatorname{ind}_g a$ có thể được tính bằng
    [thuật toán BSGS](./discrete-logarithm.md#thuật-toán-bước-lớn-bước-nhỏ),
    còn toàn bộ nghiệm của
    [phương trình đồng dư tuyến tính](./linear-equation.md) thì dễ tìm. Từ đó
    thu được tất cả căn bậc $k$ của $a$, có dạng $x\equiv g^y\pmod m$.

    Ngoài ra còn một ý tưởng tương tự. Vẫn đặt $x\equiv g^y\pmod m$, có thể
    biến đổi

    $$
    x^k \equiv (g^k)^y \equiv a \pmod m
    $$

    thành bài toán tìm logarit rời rạc của $a$ với cơ số $g^k$. Bài toán này
    cũng có thể dùng BSGS để tìm một nghiệm riêng. Nghiệm tổng quát của nó có
    thể suy ra từ biểu thức nghiệm ở phần trên, tức là nhân nghiệm riêng lần
    lượt với toàn bộ căn đơn vị bậc $k$.

    Dù dùng ý tưởng nào, khi đã biết căn nguyên thủy, độ phức tạp để tìm một
    nghiệm của thuật toán này là $O(m^{1/2})$. Vì có thể tìm một căn nguyên thủy
    trong thời gian $o(m^{1/2})$, tổng độ phức tạp vẫn là $O(m^{1/2})$.

-   Khi $m=2^e$ và $e\in\mathbf N_+$, trước hết có thể tìm $s,r$ trong
    $a\equiv (-1)^s5^r\pmod m$. Trong hai số mũ này, $s$ có thể xác định trong
    $O(1)$:

    $$
    s = \begin{cases}0, & a\equiv 1\pmod 4, \\ 1, & a\equiv 3\pmod 4.\end{cases}
    $$

    Còn $r=\operatorname{ind}_5((-1)^sa)$ có thể tính bằng thuật toán BSGS trong
    $O(m^{1/2})$. Tiếp theo chỉ cần giải hệ phương trình đồng dư tuyến tính:

    $$
    \begin{aligned}
    kz &\equiv s \pmod{2},\\
    ky &\equiv r \pmod{2^{e-2}}.
    \end{aligned}
    $$

    Nghiệm tổng quát $(z,y)$ của hệ tuyến tính này dễ tìm, và $x=(-1)^z5^y$
    chính là căn cần tìm. Độ phức tạp để tìm một nghiệm của thuật toán này vẫn
    là $O(m^{1/2})$.

Tất nhiên, với trường hợp vô nghiệm, thực ra có thể dùng tiêu chuẩn đã nêu ở
trên để kiểm tra nhanh trong $O(\log m)$, không cần đợi đến quá trình giải mới
phát hiện.

Mã tham khảo để tìm căn bậc $k$ modulo số nguyên tố như sau: mã chỉ mang tính
minh họa; do độ phức tạp quá cao, không đủ để AC bài mẫu này.

??? example "Bài mẫu [Library Checker - Kth Root (Mod)](https://judge.yosupo.jp/problem/kth_root_mod), mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/residue/bsgs-mod-p.cpp"
    ```

<span id="&#25913;&#33391; Tonelli&#8211;Shanks &#31639;&#27861;"></span>
### Thuật toán Tonelli-Shanks cải tiến

Mở rộng phù hợp [thuật toán Tonelli-Shanks](./quad-residue.md#tonellishanks-%E7%AE%97%E6%B3%95)
dùng cho khai căn bậc hai theo modulo sẽ giải quyết được phép khai căn theo
modulo lũy thừa của số nguyên tố. Một cách mở rộng trực tiếp hơn là thuật toán
Adleman-Manders-Miller[^amm], nhưng độ phức tạp của nó vẫn chưa đủ tốt[^amm-comp].
Mục này giới thiệu thuật toán Tonelli-Shanks cải tiến do sugarknri, Min\_25,
37zigen và những người khác đề xuất. Nó có thể tìm một căn bậc $k$ trong thời
gian $O(m^{1/4+\varepsilon})$.

Ý tưởng cốt lõi của thuật toán Tonelli-Shanks là đưa việc tính logarit rời rạc
vào nhóm có bậc $2^e$, từ đó giảm độ phức tạp. Tương tự, logarit rời rạc trong
nhóm có bậc là lũy thừa nguyên tố bất kỳ $p^e$ cũng có thể được giải khá hiệu
quả, nhưng độ phức tạp của thuật toán là $\Omega\left(\sqrt{p}\right)$. Thuật
toán Adleman-Manders-Miller tách việc tìm căn bậc $k$ thành nhiều phép tính
logarit rời rạc trong các nhóm có bậc là lũy thừa nguyên tố, nhưng do bị giới
hạn bởi kích thước của thừa số nguyên tố lớn nhất $p_\text{max}(k)$ của $k$, độ
phức tạp vẫn là $\Omega\left(\sqrt{p_\text{max}(k)}\right)$. Thuật toán trong
mục này cải tiến thêm quá trình đó, tránh tính logarit rời rạc với các thừa số
nguyên tố lớn, và khống chế tổng độ phức tạp ở mức $O(m^{1/4+\varepsilon})$.

<span id="&#36807;&#31243;"></span>
#### Quy trình

Xét việc tính căn bậc $k$ của $a$ modulo lũy thừa số nguyên tố $m$, tức là giải
phương trình đồng dư:

$$
x^k \equiv a \pmod m.
$$

Đặc biệt, với trường hợp $m=2^e$, còn cần bảo đảm $a\equiv 1\pmod{4}$, để $a$
có thể viết thành lũy thừa của $g=5$. Tương tự phần đã thảo luận, việc tính căn
bậc $k$ modulo $2^e$ luôn có thể chuyển về trường hợp này. Khi xử lý trường hợp
modulo $2^e$, mọi $\varphi(m)$ được nhắc đến trong mục này đều nên thay bằng
$\delta_m(5)=2^{e-2}$.

Trước hết, bài toán có thể được đưa về trường hợp bậc khai căn chia hết
$\varphi(m)$. Đặt $d=\gcd(k,\varphi(m))$. Khi đó, theo tính chất của thặng dư
bậc $k$, nếu $a$ là thặng dư bậc $k$ modulo $m$, thì $a$ luôn là căn đơn vị bậc
$\dfrac{\varphi(m)}{d}$ modulo $m$. Theo tính chất của căn đơn vị, với mọi
$\ell\perp\dfrac{\varphi(m)}{d}$, ánh xạ $x\mapsto x^{\ell}$ đều là song ánh
trên các căn đơn vị bậc $\dfrac{\varphi(m)}{d}$. Vì vậy có thể chọn

$$
\ell = \left(\dfrac{k}{d}\right)^{-1}\bmod\dfrac{\varphi(m)}{d}.
$$

Lấy lũy thừa bậc $\ell$ hai vế của phương trình đồng dư ban đầu, ta được

$$
x^d\equiv x^{k\ell} \equiv a^{\ell} =: b \pmod{m}.
$$

Đồng dư đầu tiên dùng [định lí Euler](./fermat.md#định-lý-euler)
và quan hệ đồng dư sau: ($c\in\mathbf Z$)

$$
k\ell = d\left(\frac{k}{d}\ell\right) = d\left(c\dfrac{\varphi(m)}{d}+1\right) \equiv d \pmod{\varphi(m)}.
$$

Với bài toán đã chuyển đổi, xét phân tích thừa số nguyên tố của $d$:

$$
d = \prod_{p\in\mathbf P}p^e.
$$

Có thể bắt đầu từ $b=a^\ell$, với mỗi $p^e\neq 1$ thì lần lượt khai căn bậc
$p^e$; cuối cùng sẽ thu được căn bậc $d$ của $b$, cũng chính là căn bậc $k$ của
$a$.

Sau cùng, bài toán chuyển thành cách tìm nghiệm của phương trình

$$
x^{p^e} \equiv b \pmod m.
$$

Không mất tính tổng quát, giả sử $\varphi(m)=p^sr$ và $p\perp r$. Gọi
$q\in\mathbf N_+$ là nghiệm của phương trình $qr\equiv -1\pmod{p^e}$. Khi đó,
vì $b$ là căn đơn vị bậc $rp^{s-e}$, $b^{qr}$ chắc chắn là căn đơn vị bậc
$p^{s-e}$. Lại gọi $\zeta$ là căn đơn vị nguyên thủy bậc $p^s$ modulo $m$. Khi
đó $\zeta^{p^e}$ là căn đơn vị nguyên thủy bậc $p^{s-e}$, nên tồn tại
$h\in\mathbf N$ sao cho $b^{qr}\equiv \zeta^{hp^{e}}\pmod{m}$. Vì vậy, kiểm tra
trực tiếp cho thấy

$$
x\equiv b^{(qr+1)/p^e}\zeta^{-h} \pmod{m}
$$

là một căn bậc $p^e$ của $b$ modulo $m$.

Để tính $x$, cần tìm một bất thặng dư bậc $p$ là $\eta$ modulo $m$. Theo các
tính chất đã nêu, chỉ cần chọn ngẫu nhiên $\eta\perp m$ và kiểm tra
$\eta^{\varphi(m)/p}\bmod{m}\neq 1$. Mật độ của các số như vậy là

$$
\dfrac{\varphi(m)}{m}\left(1-\dfrac{1}{p}\right) \ge \dfrac{1}{4}.
$$

Do đó, kỳ vọng chỉ cần thử không quá $4$ số nguyên để tìm được nó. Chú ý rằng
$\eta^{rp^{s-1}}\not\equiv 1\pmod m$ và $\eta^{rp^s}\equiv 1\pmod m$, nên nếu
đặt $\zeta=\eta^r\bmod m$ và $\xi=\eta^{rp^{s-1}}\bmod m$, thì chúng lần lượt
là căn đơn vị nguyên thủy bậc $p^s$ và bậc $p$.

Cuối cùng, cần tính $h\in\mathbf N$. Hiển nhiên có thể lấy $h < p^{s-e}$. Xét
biểu diễn cơ số $p$ của $h$:

$$
h = \sum_{j=0}^{s-e-1}h_jp^j = h_0 + h_1p + h_2p^2 +\cdots.
$$

Ta tính lần lượt từng chữ số. Khi đã tính xong $j$ chữ số đầu, tất yếu có

$$
\left(b^{qr}\zeta^{-p^e(h_0+h_1p+\cdots + h_{j-1}p^{j-1})}\right)^{p^{s-e-j-1}} \equiv \zeta^{h_jp^{s-1}} \equiv \xi^{h_j} \pmod{m}.
$$

Vì vậy, có thể tìm $h_j$ bằng cách tính logarit rời rạc theo cơ số $\xi$. Để có
độ phức tạp tốt hơn, cần dùng thuật toán BSGS. Tổng cộng cần tính logarit rời
rạc $(s-e)$ lần; giả sử tiền xử lý $B$ lũy thừa của $\xi$, thì thời gian cho
một lần giải logarit rời rạc là $O(p/B)$, và tổng độ phức tạp là

$$
O\left(B+(s-e)\dfrac{p}{B}\right).
$$

Khi $B=\sqrt{(s-e)p}$, tổng độ phức tạp đạt nhỏ nhất, bằng
$O\left(\sqrt{(s-e)p}\right)$. Sau khi thu được $h$, thay vào biểu thức của $x$
ở trên sẽ tìm được một nghiệm riêng.

<span id="&#26102;&#38388;&#22797;&#26434;&#24230;"></span>
#### Độ phức tạp thời gian

Độ phức tạp thời gian của thuật toán này là $O(m^{1/4+\varepsilon})$. Khi thảo
luận về độ phức tạp trong mục này, luôn giả sử một phép nhân mất $O(1)$ thời
gian, và khi tính lũy thừa thì luôn dùng định lí Euler để giảm số mũ; vì vậy
việc tính từng lũy thừa liên quan luôn có thể hoàn thành trong $O(\log m)$.

Trước hết xét việc tính một căn bậc $p^e$. Việc tìm bất thặng dư bậc $p$ chỉ
cần kiểm tra kỳ vọng $O(1)$ số, nên tổng thời gian là $O(\log m)$. Việc tính
$s,r,\zeta,\eta,b^{qr}$ mỗi phần chỉ cần $O(\log m)$. Khi tính $h$, mỗi chữ số
cần $O(\log m)$ thời gian để tính lũy thừa; tổng cộng có $(s-e)$ chữ số, nên
tổng độ phức tạp là $O((s-e)\log m)$. Phần trên đã chỉ ra rằng tổng thời gian
tiền xử lý và $(s-e)$ truy vấn để tính logarit rời rạc là
$O\left(\sqrt{(s-e)p}\right)$. Vì $s-e\in O(\log m)$, độ phức tạp thời gian để
tính một căn bậc $p^e$ là $O(p^{1/2+\varepsilon})$. Đặc biệt, khi $s=e$, độ
phức tạp có thể giảm thêm xuống $O(\log m)$.

Tiếp theo xét tổng độ phức tạp của thuật toán. Việc tính $\varphi(m),d,\ell$
đều có độ phức tạp $O(\log m)$. Ngay sau đó cần phân tích thừa số nguyên tố
$d=\prod_p{p^e}$; bước này có thể dùng [thuật toán Pollard Rho](./pollard-rho.md#thuật-toán-pollard-rho)
trong $O(m^{1/4})$. Cuối cùng, tổng thời gian để lần lượt khai căn bậc $p^e$ là

$$
O\left(\sum_{e < s}p^{1/2+\varepsilon}\right).
$$

Vì mỗi thừa số nguyên tố $p$ thỏa mãn $e < s$ xuất hiện ít nhất $2$ lần trong
$\varphi(m)$, nên chắc chắn $p < m^{1/2}$. Do đó, tổng độ phức tạp thời gian là
$O(m^{1/4+\varepsilon})$.

Thật ra, trong bối cảnh này, không cần dùng thuật toán Pollard Rho để phân tích
thừa số nguyên tố mà vẫn có thể đạt độ phức tạp $O(m^{1/4+\varepsilon})$. Chỉ
cần thử chia trực tiếp $d$ và chỉ liệt kê các thừa số nguyên tố không vượt quá
$m^{1/4}$. Gọi số nguyên còn lại sau khi loại các thừa số nhỏ này là $z$. Khi
đó, với thừa số nguyên tố $p > m^{1/4}$ của $z$, chắc chắn có
$\nu_p(\varphi(m)) < 4$, trong đó $\nu_p(n)$ là số mũ của $p$ trong phân tích
thừa số nguyên tố của $n$. Vì chỉ cần xét trường hợp

$$
1 \le e = \nu_p(d) < s = \nu_p(\varphi(m)) < 4
$$

nên thừa số nguyên tố $p$ thỏa mãn điều kiện này nhiều nhất chỉ có một; nếu
không, chúng đều xuất hiện trong $\varphi(m)$ với số mũ ít nhất $2$, và tích
của chúng sẽ vượt quá $m$. Để tách thừa số nguyên tố lớn duy nhất này (nếu tồn
tại), chỉ cần tính

$$
p^\star=\gcd\left(z,\dfrac{\varphi(m)}{z}\right) = \prod_{p : \nu_p(d) < \nu_p(\varphi(m))}p^{\min\{\nu_p(d),\nu_p(\varphi(m))-\nu_p(d)\}}.
$$

Liệt kê mọi khả năng của $\nu_p(d),\nu_p(\varphi(m))$ cho thấy số mũ của $p$
trong tích chắc chắn bằng $1$, vì vậy giá trị tính được chính là thừa số nguyên
tố lớn duy nhất $p^\star$ (nếu tồn tại). Phần còn lại $z/p^\star$ chỉ có thể
gồm một số thừa số nguyên tố thỏa mãn $e=s$, nên không cần tiếp tục phân tích.

Mã tham khảo để tìm căn bậc $k$ theo modulo số nguyên tố như sau:

??? example "Bài mẫu [Library Checker - Kth Root (Mod)](https://judge.yosupo.jp/problem/kth_root_mod), mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/residue/tonelli-shanks-mod-p.cpp"
    ```

<span id="&#19968;&#33324;&#24773;&#24418;&#30340;&#22788;&#29702;"></span>
### Xử lý trường hợp tổng quát

Xét trường hợp tổng quát, vẫn giả sử modulo $m$ là lũy thừa số nguyên tố $p^e$,
nhưng $\gcd(a,m)>1$. Nếu $a\equiv 0\pmod{m}$, thì

$$
x = p^{\lceil e/k \rceil}\ell\pmod{p^e},~\ell=0,1,\cdots,p^{e-\lceil e/k\rceil}-1
$$

đều là nghiệm của phương trình ban đầu. Tiếp theo xét trường hợp
$a\not\equiv 0\pmod{m}$. Đặt $a = p^sa'$ và $p\perp a'$. Khi đó, đặt $x=p^zx'$
và $p\perp x'$, ta có

$$
x^k = p^{kz}(x')^k\equiv p^sa'\pmod{p^e}.
$$

Vì $(x')^k\perp p$, công thức trên đúng khi và chỉ khi $kz = s$ và
$(x')^k\equiv a'\pmod{p^{e-s}}$. Phương trình thứ nhất có nghiệm
$z=\dfrac{s}{k}$ khi và chỉ khi $k\mid s$; còn phương trình thứ hai đã được
giải ở trên. Cần chú ý rằng do modulo của nghiệm tổng quát trong phương trình
thứ hai khác với modulo của nghiệm tổng quát ban đầu, mỗi nghiệm $x'$ của
phương trình thứ hai tương ứng với một số nghiệm của phương trình ban đầu:

$$
x \equiv p^{s/k}(x' + \ell p^{e-s})\pmod{p^e},~\ell = 0,1,\cdots, p^{s-s/k}-1.
$$

Mã tham khảo để tìm toàn bộ căn bậc $k$ theo modulo bất kỳ như sau:

??? example "Bài mẫu [Luogu P5668 - mẫu căn bậc N](https://www.luogu.com.cn/problem/P5668), mã tham khảo"
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

[^fnnt]: Thật ra, modulo $m$ không nhất thiết là số nguyên tố. Chỉ cần $a$ là căn đơn vị nguyên thủy bậc $k=2^e$ modulo $m$, nó có thể được dùng cho biến đổi số học nhanh modulo $m$. Tuy nhiên, vì $2^e$ cần xử lý thường khá lớn, mỗi thừa số nguyên tố của modulo $m$ phải có dạng $c2^e+1$. Do đó chỉ một thừa số nguyên tố đã rất lớn, còn modulo $m$ thường lớn hơn nữa; vì vậy trường hợp modulo tổng quát không thông dụng bằng trường hợp modulo số nguyên tố.

[^lambda-density]: Theo [kết quả về số lượng căn nguyên thủy](./primitive-root.md#%E5%8E%9F%E6%A0%B9%E4%B8%AA%E6%95%B0), số lượng $\lambda$-căn nguyên thủy đúng bằng $\varphi(\lambda(m))$, trong đó $\varphi(\cdot)$ và $\lambda(\cdot)$ lần lượt là hàm Euler và hàm Carmichael. Vì với hầu hết số nguyên $m$, ta có $\lambda(m)/m = \exp(-(1+o(1))\log\log m\log\log\log m)$, và tồn tại $C > 0$ sao cho với mọi số nguyên $m > 2$ đều có $\varphi(m)/m = C / \log\log m$, nên với hầu hết số nguyên $m$, ta có $\varphi(\lambda(m))/m = \exp(-(1+o(1))\log\log m\log\log\log m)$. Ở đây, $o(1)$ trong hệ số của phần mũ đã hấp thụ đóng góp của thừa số $\varphi(\lambda(m))/\lambda(m)$. Vì vậy, có thể tìm $\lambda$-căn nguyên thủy sau kỳ vọng $\exp((1+o(1))\log\log m\log\log\log m)$ lần thử. Về ước lượng cho hàm Euler, có thể tham khảo bài báo Rosser, J. Barkley, and Lowell Schoenfeld. "Approximate formulas for some functions of prime numbers." Illinois Journal of Mathematics 6, no. 1 (1962): 64-94. Về ước lượng cho hàm Carmichael, có thể tham khảo bài báo Erdos, Paul, Carl Pomerance, and Eric Schmutz. "Carmichael's lambda function." Acta Arith 58, no. 4 (1991): 363-385.

[^amm]: Bài báo gốc: Adleman, Leonard, Kenneth Manders, and Gary Miller. "On taking roots in finite fields." In 18th Annual Symposium on Foundations of Computer Science (sfcs 1977), pp. 175-178. IEEE Computer Society, 1977. Một phần giới thiệu dễ đọc hơn có trong Cao, Zhengjun, Qian Sha, and Xiao Fan. "Adleman-Manders-Miller root extraction method revisited." In International Conference on Information Security and Cryptology, pp. 77-85. Berlin, Heidelberg: Springer Berlin Heidelberg, 2011.

[^amm-comp]: Vì thuật toán này yêu cầu $k$ là số nguyên tố, trong trường hợp xấu nhất nó cần tìm căn bậc $p$ của $a$ modulo $m$, với $p$ là thừa số nguyên tố lớn nhất của $\varphi(m)$. Trong quá trình này, cần tính logarit rời rạc của $a$ modulo $m$ theo căn đơn vị nguyên thủy bậc $p$. Ngay cả khi dùng thuật toán BSGS, quá trình này cũng cần $O(\sqrt{p})$ thời gian. Tuy nhiên, bài báo Fouvry, Etienne. "Theoreme de Brun-Titchmarsh; application au theoreme de Fermat." Inventiones mathematicae 79, no. 2 (1985): 383-407 chỉ ra rằng tồn tại một tập số nguyên tố $m$ có mật độ dương sao cho thừa số nguyên tố lớn nhất $p$ của $\varphi(m)=m-1$ thỏa mãn $p=\Omega(m^{2/3})$. Điều này có nghĩa độ phức tạp của thuật toán ít nhất là $\Omega(m^{1/3})$, kém hơn thuật toán Tonelli-Shanks cải tiến được giới thiệu trong bài.
