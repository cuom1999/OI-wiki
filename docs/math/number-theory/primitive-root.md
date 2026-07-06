Kiến thức nền: [định lí nhỏ Fermat](./fermat.md#định-lý-nhỏ-fermat), [định lí Euler](./fermat.md#định-lý-euler), [định lí Lagrange](./congruence-equation.md#định-lý-3-lagrange)

Bậc và căn nguyên thủy là các công cụ quan trọng để hiểu cấu trúc nhân của
[hệ thặng dư thu gọn](./basic.md#lớp-đồng-dư-và-hệ-thặng-dư)
$\mathbf Z_m^*$ modulo $m$. Dựa trên chúng, có thể định nghĩa các khái niệm
như [logarit rời rạc](./discrete-logarithm.md). Phần thảo luận tổng quát hơn có
thể xem ở các mục liên quan trong phần đại số trừu tượng, chẳng hạn
[lý thuyết nhóm](../algebra/group-theory.md#cấp) và
[lý thuyết vành](../algebra/ring-theory.md#ứng-dụng-nhóm-nhân-của-các-lớp-đồng-dư-số-nguyên).

<span id="bậc"></span>

## Bậc

Trong mục này, luôn giả sử modulo $m\in\mathbf N_+$ và cơ số
$a\in\mathbf Z$ nguyên tố cùng nhau, tức là $(a,m)=1$, cũng viết là
$a\perp m$.

Với $n\in\mathbf Z$, lũy thừa $a^n\bmod m$ thể hiện một cấu trúc tuần hoàn. Độ
dài nhỏ nhất của chu kỳ này chính là bậc của $a$ modulo $m$. Bậc được định
nghĩa là số mũ tại đó lũy thừa $a^n \bmod m$ lần đầu quay về điểm đầu
$a^0\bmod m = 1$:

???+ abstract "Bậc"
    Với $a\in\mathbf Z,m\in\mathbf N_+$ và $a\perp m$, số nguyên dương nhỏ nhất
    $n$ thỏa mãn đồng dư $a^n \equiv 1 \pmod m$ được gọi là **bậc của $a$
    modulo $m$** (the order of $a$ modulo $m$), ký hiệu là $\delta_m(a)$ hoặc
    $\operatorname{ord}_m(a)$.

???+ tip "Ghi chú"
    Trong [đại số trừu tượng](../algebra/group-theory.md#cấp), "bậc" ở
    đây chính là bậc của phần tử $a$ trong nhóm tạo bởi hệ thặng dư thu gọn
    modulo $m$ theo phép nhân. Ký hiệu $\delta$ để biểu diễn bậc chỉ dùng cho
    nhóm đặc biệt này. Nhiều tính chất bên dưới có thể mở rộng trực tiếp thành
    tính chất về bậc của phần tử trong nhóm ở đại số trừu tượng.

    Ngoài ra còn có khái niệm "nửa bậc", trong số học thường dùng ký hiệu
    $\delta^-$. Đó là số nguyên dương nhỏ nhất thỏa mãn đồng dư
    $a^n \equiv -1 \pmod m$. Nửa bậc không phải là khái niệm trong lý thuyết
    nhóm. Bậc luôn tồn tại, còn nửa bậc thì không nhất thiết tồn tại.

<span id="cấu-trúc-tuần-hoàn-của-lũy-thừa"></span>

### Cấu trúc tuần hoàn của lũy thừa

Dùng bậc, có thể mô tả cấu trúc tuần hoàn của lũy thừa. Với lũy thừa
$a^n\bmod m$, chia số mũ $n$ cho bậc $\delta_m(a)$ có dư:

$$
n = \delta_m(a)q + r, ~ 0\le r < \delta_m(a).
$$

Tiếp theo, dùng các quy tắc tính lũy thừa, có

$$
a^n = a^{\delta_m(a)q + r} = (a^{\delta_m(a)})^q \cdot a^r \equiv a^r \pmod m.
$$

Điều này cho thấy với lũy thừa có số mũ bất kỳ, có thể đưa nó về chu kỳ
không âm đầu tiên. Từ đó suy ra một loạt tính chất về bậc.

<a id="ord-prop-1"></a>

???+ note "Tính chất 1"
    Với $a\in\mathbf Z,m\in\mathbf N_+$ và $a\perp m$, các lũy thừa
    $a^0(=1),a,a^2,\cdots,a^{\delta_m(a)-1}$ đôi một không đồng dư modulo $m$.

??? note "Chứng minh"
    Xét phản chứng. Giả sử tồn tại hai số $0\le i< j<\delta_m(a)$ sao cho
    $a^i\equiv a^j\pmod m$. Khi đó $a^{j - i}\equiv 1\pmod m$. Nhưng
    $0 < j - i < \delta_m(a)$. Điều này mâu thuẫn với tính nhỏ nhất trong định
    nghĩa bậc, nên mệnh đề đúng.

<a id="ord-prop-2"></a>

???+ note "Tính chất 2"
    Với $a,n\in\mathbf Z,m\in\mathbf N_+$ và $a\perp m$, đồng dư
    $a^n \equiv 1 \pmod m$ đúng khi và chỉ khi $\delta_m(a)\mid n$.

??? note "Chứng minh"
    Như đã nói ở trên, $a^{n}\equiv a^{n\bmod\delta_m(a)}\pmod m$. Theo
    [Tính chất 1](#ord-prop-1), trong các $r$ thỏa mãn
    $0\le r < \delta_m(a)$, giá trị duy nhất khiến $a^r\equiv 1\pmod m$ là
    $r=0$. Do đó $a^n \equiv 1 \pmod m$ khi và chỉ khi
    $n\bmod \delta_m(a) = 0$, tức là $\delta_m(a)\mid n$.

Trong [định lí Euler](./fermat.md#định-lý-euler), đồng
dư $a^{\varphi(m)}\equiv 1\pmod m$ đúng với mọi $a\perp m$. Kết hợp với
[Tính chất 2](#ord-prop-2), điều này cho thấy với mọi $a\perp m$ đều có
$\delta_m(a)\mid\varphi(m)$. Nói cách khác, $\varphi(m)$ là một bội chung của
bậc của tất cả các $a\perp m$. Với một số nguyên dương $m$, bội chung nhỏ nhất
của tất cả các bậc $\delta_m(a)$ với $a\perp m$, ký hiệu là $\lambda(m)$, chính
là [hàm Carmichael](#hàm-carmichael) của $m$. Phần sau sẽ thảo
luận chi tiết các tính chất của nó.

Tương tự các cấu trúc tuần hoàn khác, có thể tính bậc của $a^k$ dựa trên
bậc của $a$.

<a id="ord-prop-3"></a>

???+ note "Tính chất 3"
    Với $k,a\in\mathbf Z,m\in\mathbf N_+$ và $a\perp m$, có

    $$
    \delta_m(a^k) = \dfrac{\delta_m(a)}{(\delta_m(a),k)}.
    $$

??? note "Chứng minh"
    Theo [Tính chất 2](#ord-prop-2), đồng dư
    $(a^k)^n = a^{kn} \equiv 1\pmod m$ đúng khi và chỉ khi
    $\delta_m(a) \mid kn$. Điều kiện này tương đương với

    $$
    \dfrac{\delta_m(a)}{\left(\delta_m(a),k\right)} \mid n.
    $$

    Số nguyên dương nhỏ nhất khiến điều kiện này đúng là

    $$
    \delta_m(a^k)=\dfrac{\delta_m(a)}{\left(\delta_m(a),k\right)}.
    $$

<span id="bậc-của-tích"></span>

### Bậc của tích

Giả sử $a,b$ là các số nguyên khác nhau và cùng nguyên tố với $m$. Nếu đã biết
các bậc $\delta_m(a)$ và $\delta_m(b)$, cũng có thể thu được một số thông
tin về bậc $\delta_{m}(ab)$ của tích $ab$.

<a id="ord-prop-4"></a>

???+ note "Tính chất 4"
    Với $a,b\in\mathbf Z,m\in\mathbf N_+$ và $a,b\perp m$, có

    $$
    \dfrac{[\delta_m(a),\delta_m(b)]}{(\delta_m(a),\delta_m(b))} \mid \delta_m(ab) \mid [\delta_m(a),\delta_m(b)].
    $$

??? note "Chứng minh"
    Vì $[\delta_m(a),\delta_m(b)]$ là bội của cả $\delta_m(a)$ lẫn
    $\delta_m(b)$, theo [Tính chất 2](#ord-prop-2) có

    $$
    (ab)^{[\delta_m(a),\delta_m(b)]} = a^{[\delta_m(a),\delta_m(b)]} b^{[\delta_m(a),\delta_m(b)]} \equiv 1 \pmod m.
    $$

    Áp dụng Tính chất 2 một lần nữa, thu được

    $$
    \delta_m(ab) \mid [\delta_m(a),\delta_m(b)].
    $$

    Đây là quan hệ chia hết ở phía phải.

    Ngược lại, vì

    $$
    1 \equiv (ab)^{\delta_m(ab)\delta_m(b)} \equiv a^{\delta_m(ab)\delta_m(b)} \pmod m,
    $$

    nên áp dụng Tính chất 2 thu được $\delta_m(a)\mid\delta_m(ab)\delta_m(b)$.
    Rút gọn $(\delta_m(a),\delta_m(b))$ ở hai phía, có

    $$
    \dfrac{\delta_m(a)}{(\delta_m(a),\delta_m(b))}\mid\delta_m(ab)\dfrac{\delta_m(b)}{(\delta_m(a),\delta_m(b))}.
    $$

    Sau khi rút gọn ước chung, hai phân số là nguyên tố cùng nhau, nên

    $$
    \dfrac{\delta_m(a)}{(\delta_m(a),\delta_m(b))}\mid\delta_m(ab).
    $$

    Tương tự, cũng có

    $$
    \dfrac{\delta_m(b)}{(\delta_m(a),\delta_m(b))}\mid\delta_m(ab).
    $$

    Vì hai vế trái của hai quan hệ chia hết này nguyên tố cùng nhau, có

    $$
    \dfrac{[\delta_m(a),\delta_m(b)]}{(\delta_m(a),\delta_m(b))} =\dfrac{\delta_m(a)\delta_m(b)}{(\delta_m(a),\delta_m(b))^2}\mid\delta_m(ab).
    $$

    Đây là quan hệ chia hết ở phía trái.

Với trường hợp bậc của $a$ và $b$ nguyên tố cùng nhau, kết luận này có dạng đơn
giản hơn.

<a id="ord-prop-4p"></a>

???+ note "Tính chất 4'"
    Với $a,b\in\mathbf Z,m\in\mathbf N_+$ và $a,b\perp m$, có

    $$
    \delta_m(ab) = \delta_m(a)\delta_m(b) \iff \delta_m(a)\perp\delta_m(b).
    $$

??? note "Chứng minh"
    Nếu $\delta_m(a)\perp\delta_m(b)$, thì mọi quan hệ chia hết trong
    [Tính chất 4](#ord-prop-4) đều là dạng bằng, nên

    $$
    \delta_m(ab) = [\delta_m(a),\delta_m(b)] = \delta_m(a)\delta_m(b).
    $$

    Ngược lại, nếu $\delta_m(ab)=\delta_m(a)\delta_m(b)$, theo Tính chất 4 có

    $$
    \delta_m(a)\delta_m(b) = \delta_m(ab) \mid [\delta_m(a),\delta_m(b)].
    $$

    Điều này lập tức cho thấy $(\delta_m(a),\delta_m(b))=1$, tức là
    $\delta_m(a)\perp\delta_m(b)$.

Trong trường hợp tổng quát, các cận thu được từ [Tính chất 4](#ord-prop-4) đã
là chặt. Trường hợp bậc của tích đạt cận dưới rất dễ xây dựng: chẳng hạn với
$(a,b,m)=(3,5,7)$, có $\delta_m(a)=\delta_m(b)=6$, nhưng bậc của tích là
$\delta_m(ab)=1$.

Mặc dù trong trường hợp tổng quát, bậc của tích $ab$ không nhất thiết là bội
chung nhỏ nhất của các bậc của chúng, luôn có thể tìm một phần tử có bậc
bằng bội chung nhỏ nhất đó.

<a id="ord-prop-5"></a>

???+ note "Tính chất 5"
    Với $a,b\in\mathbf Z,m\in\mathbf N_+$ và $a,b\perp m$, luôn tồn tại
    $c\in\mathbf Z$ và $c\perp m$ sao cho

    $$
    \delta_m(c) = [\delta_m(a),\delta_m(b)].
    $$

??? note "Chứng minh"
    Xét phân tích thừa số nguyên tố:

    $$
    \delta_m(a) = \prod_p p^{\alpha_p},~ \delta_m(b) = \prod_p p^{\beta_p}.
    $$

    Dựa trên quan hệ lớn nhỏ giữa $\alpha_p$ và $\beta_p$, chia tất cả các thừa
    số nguyên tố thành hai loại:

    $$
    A = \{p : \alpha_p \ge \beta_p\}, ~ B = \{p : \alpha_p < \beta_p\}.
    $$

    Từ đó, lần lượt đặt

    $$
    \gamma_A = \prod_{p\in A}p^{\alpha_p},~\gamma_B = \prod_{p\in B}p^{\alpha_p},~\eta_A = \prod_{p\in A}p^{\beta_p},~\eta_B = \prod_{p\in B}p^{\beta_p},
    $$

    thì $\delta_m(a) = \gamma_A\gamma_B$ và $\delta_m(b)=\eta_A\eta_B$. Theo
    [Tính chất 3](#ord-prop-3), có

    $$
    \begin{aligned}
    \delta_m(a^{\gamma_B}) &= \dfrac{\delta_m(a)}{(\delta_m(a),\gamma_B)} = \dfrac{\delta_m(a)}{\gamma_B} = \gamma_A,\\
    \delta_m(b^{\eta_A}) &= \dfrac{\delta_m(b)}{(\delta_m(b),\eta_A)} = \dfrac{\delta_m(b)}{\eta_A} = \eta_B.
    \end{aligned}
    $$

    Vì $\gamma_A\perp\eta_B$, theo [Tính chất 4'](#ord-prop-4p), có

    $$
    \delta_m(a^{\gamma_B}b^{\eta_A}) = \gamma_A\eta_B = \prod_p p^{\max\{\alpha_p,\beta_p\}} = [\delta_m(a),\delta_m(b)].
    $$

    Do đó $c=a^{\gamma_B}b^{\eta_A}$ là phần tử có bậc bằng
    $[\delta_m(a),\delta_m(b)]$.

Kết luận này thường được dùng để xây dựng phần tử có bậc chỉ định.

<span id="căn-nguyên-thủy"></span>

## Căn nguyên thủy

Căn nguyên thủy là các phần tử đặc biệt: bậc của nó đúng bằng số phần tử của
hệ thặng dư thu gọn modulo $m$.

???+ abstract "Căn nguyên thủy"
    Với $m\in\mathbf N_+$, nếu tồn tại $g\in\mathbf Z$ và $g\perp m$ sao cho
    $\delta_m(g)=|\mathbf Z_m^*|=\varphi(m)$, thì $g$ được gọi là **căn nguyên
    thủy modulo $m$** (primitive root modulo $m$). Trong đó, $\varphi(m)$ là
    [hàm Euler](./euler-totient.md).

Không phải mọi số nguyên dương $m$ đều có căn nguyên thủy modulo $m$. Theo
[Tính chất 1](#ord-prop-1), nếu căn nguyên thủy $g$ modulo $m$ tồn tại, thì các
lớp đồng dư chứa $g,g^2,\cdots,g^{\varphi(m)}$ đôi một khác nhau và tạo thành
hệ thặng dư thu gọn modulo $m$. Đặc biệt, với số nguyên tố $p$, các thặng dư
$g^i\bmod p$ đôi một khác nhau với $i=1,2,\cdots,p-1$.

???+ tip "Ghi chú"
    Trong [đại số trừu tượng](../algebra/ring-theory.md#ứng-dụng-nhóm-nhân-của-các-lớp-đồng-dư-số-nguyên),
    căn nguyên thủy chính là phần tử sinh của nhóm cyclic. Khái niệm này chỉ có
    tên "căn nguyên thủy" trong nhóm tạo bởi hệ thặng dư thu gọn modulo $m$ theo
    phép nhân; trong nhóm cyclic tổng quát, nó được gọi là "phần tử sinh".
    Không phải mọi nhóm tạo bởi hệ thặng dư thu gọn modulo $m$ theo phép nhân
    đều là nhóm cyclic; việc tồn tại căn nguyên thủy cho thấy nó đẳng cấu với
    một nhóm cyclic, còn nếu không tồn tại căn nguyên thủy thì không đẳng cấu.

Khi modulo bằng $1$, nhóm nhân các số nguyên modulo $1$ là $\{0\}$. Đây là
nhóm cyclic, nên căn nguyên thủy là $0$.

<span id="định-lí-kiểm-tra-căn-nguyên-thủy"></span>

### Định lí kiểm tra căn nguyên thủy

Nếu đã biết tất cả các thừa số nguyên tố của $\varphi(m)$, có thể kiểm tra một
số có phải căn nguyên thủy modulo $m$ hay không.

???+ note "Định lí"
    Với số nguyên $m\ge 3$ và $g\perp m$, $g$ là căn nguyên thủy modulo $m$ khi
    và chỉ khi với mọi thừa số nguyên tố $p$ của $\varphi(m)$, điều kiện sau
    đều đúng:

    $$
    g^{\frac{\varphi(m)}{p}}\not\equiv 1 \pmod m.
    $$

??? note "Chứng minh"
    Chiều cần suy ra trực tiếp từ định nghĩa bậc. Để chứng minh chiều đủ, dùng
    phản chứng. Nếu $g$ không phải là căn nguyên thủy modulo $m$, thì chắc chắn
    $\delta_m(g)< \varphi(m)$. Theo [Tính chất 2](#ord-prop-2) và định lí
    Euler, $\delta_m(g)\mid\varphi(m)$. Do đó, lấy $p$ là một thừa số nguyên tố
    của $\dfrac{\varphi(m)}{\delta_m(g)}$, có
    $\delta_m(g)\mid\dfrac{\varphi(m)}{p}$. Áp dụng lại Tính chất 2, suy ra

    $$
    g^{\frac{\varphi(m)}{p}} \equiv 1 \pmod m.
    $$

    Nhưng $p$ cũng là một ước của $\varphi(m)$, mâu thuẫn với giả thiết. Vì vậy
    chiều đủ của mệnh đề được chứng minh.

<span id="số-lượng-căn-nguyên-thủy"></span>

### Số lượng căn nguyên thủy

Căn nguyên thủy nếu tồn tại thì cũng không nhất thiết duy nhất. Tổng quát hơn,
với các bậc có thể có của mỗi phần tử trong hệ thặng dư thu gọn modulo $m$ và
số phần tử có một bậc nào đó, có kết luận sau:

???+ note "Định lí"
    Nếu số nguyên dương $m$ có căn nguyên thủy $g$, thì phần tử bậc $d$ modulo
    $m$ tồn tại khi và chỉ khi $d\mid\varphi(m)$, và khi tồn tại thì có đúng
    $\varphi(d)$ phần tử như vậy. Đặc biệt, số căn nguyên thủy modulo $m$ bằng
    $\varphi(\varphi(m))$.

??? note "Chứng minh"
    Theo định nghĩa căn nguyên thủy, mọi lớp đồng dư thu gọn modulo $m$ đều có
    thể viết dưới dạng $g^k\bmod m$, trong đó $k$ là một trong các số
    $1,2,\cdots,\varphi(m)$. Theo [Tính chất 3](#ord-prop-3), bậc của các phần
    tử này bằng

    $$
    \delta_m(g^k) = \dfrac{\varphi(m)}{(\varphi(m),k)}.
    $$

    Do đó phần tử bậc $d$ tồn tại khi và chỉ khi $d\mid\varphi(m)$. Hơn nữa,
    với $d\mid\varphi(m)$, đặt $d'=\varphi(m)/d$, tập các phần tử đó là

    $$
    \begin{aligned}
    A &= \{g^k : (\varphi(m),k)=d',~1\le k \le\varphi(m)\} \\
    &= \{g^k : d'\mid k,~ (d, k/d') = 1,~ 1 \le k/d' \le d\}.
    \end{aligned}
    $$

    Các $k'=k/d'$ ứng với những phần tử này chính là các số nguyên dương không
    vượt quá $d$ và nguyên tố cùng nhau với $d$. Theo định nghĩa hàm Euler, số
    lượng đó là $\varphi(d)$.

<span id="định-lí-tồn-tại-căn-nguyên-thủy"></span>

### Định lí tồn tại căn nguyên thủy

Mục này sẽ thiết lập định lí tồn tại căn nguyên thủy sau:

???+ note "Định lí"
    Căn nguyên thủy modulo $m$ tồn tại khi và chỉ khi
    $m=1,2,4,p^e,2p^e$, trong đó $p$ là số nguyên tố lẻ và $e\in\mathbf N_+$.

Để chứng minh kết luận này, cần lần lượt xét bốn trường hợp sau:

1.  $m=1,2,4$, các căn nguyên thủy lần lượt là $g=0,1,3$, nên tồn tại.

2.  $m=p^{e}$ là lũy thừa của một số nguyên tố lẻ, trong đó $p$ là số nguyên
    tố lẻ và $e\in\mathbf N_+$.

    ???+ note "Bổ đề 1"
        Với số nguyên tố lẻ $p$, căn nguyên thủy modulo $p$ tồn tại.

    ??? note "Chứng minh"
        Chứng minh chia thành hai bước.

        **Bước 1**: Với $d\mid(p-1)$, phương trình đồng dư
        $x^d\equiv 1\pmod p$ có đúng $d$ nghiệm đôi một khác nhau.

        Đặt $p-1=kd$, xét đa thức

        $$
        f(x) = x^{d(k-1)} + x^{d(k-2)} + \cdots + x^d + 1.
        $$

        Theo [định lí Euler](./fermat.md#định-lý-euler),
        phương trình đồng dư
        $(x^d-1)f(x)=x^{p-1}-1\equiv 0\pmod{p}$ có đúng $p-1$ nghiệm đôi một
        khác nhau. Các nghiệm này lần lượt là nghiệm của $x^d-1$ và $f(x)$.
        Theo [định lí Lagrange](./congruence-equation.md#định-lý-3-lagrange),
        chúng lần lượt có nhiều nhất $d$ và $d(k-1)$ nghiệm đôi một khác nhau.
        Vì $d+d(k-1)=p-1$, trường hợp đầu chỉ có thể có đúng $d$ nghiệm đôi một
        khác nhau. Điều này chứng minh phương trình đồng dư
        $x^d\equiv 1\pmod p$ có đúng $d$ nghiệm đôi một khác nhau.

        **Bước 2**: Với $d\mid(p-1)$, số phần tử bậc $d$ đúng bằng
        $\varphi(d)$.

        Sắp xếp tất cả các ước của $\varphi(p)$, rồi dùng quy nạp. Vì phần tử
        bậc $1$ chỉ có thể là $1$, nên có đúng một phần tử và cơ sở quy nạp
        đúng. Với $d\mid(p-1)$, theo [Tính chất 2](#ord-prop-2) ở trên, mọi
        nghiệm của phương trình đồng dư $x^d\equiv 1\pmod p$ đều thỏa mãn
        $\delta_p(x)\mid d$. Do đó, số phần tử bậc $d$ trong đó là

        $$
        N(d) = d - \sum_{e\mid d,~e\neq d} N(e) =  d - \sum_{e\mid d,~e\neq d} \varphi(e) = \varphi(d).
        $$

        Dấu bằng thứ hai đúng theo giả thiết quy nạp, dấu bằng thứ ba là tính
        chất của hàm Euler. Theo quy nạp toán học, với mọi $d\mid(p-1)$ đều có
        đúng $\varphi(d)$ phần tử bậc $d$.

        Đặc biệt, với $d=p-1$, có đúng $\varphi(p-1)$ phần tử bậc $(p-1)$. Vì
        vậy căn nguyên thủy modulo $p$ tồn tại.

    ???+ note "Bổ đề 2"
        Với số nguyên tố lẻ $p$ và $e \in \mathbf{N}_+$, căn nguyên thủy modulo
        $p^e$ tồn tại.

    ??? note "Chứng minh"
        Chứng minh chia thành ba bước.

        **Bước 1**: Tồn tại căn nguyên thủy $g$ modulo $p$ sao cho
        $g^{p-1}\not\equiv 1\pmod{p^2}$.

        Lấy tùy ý một căn nguyên thủy $g$ modulo $p$. Nếu nó không thỏa mãn điều
        kiện, tức là $g^{p-1}\equiv 1\pmod{p^2}$, thì có thể chứng minh $g+p$
        thỏa mãn điều kiện: $g+p$ cũng là căn nguyên thủy modulo $p$, và

        $$
        \begin{aligned}
        (g+p)^{p-1} &\equiv \binom{p-1}{0}g^{p-1} + \binom{p-1}{1}g^{p-2}p \\
        &= g^{p-1} + g^{p-2}p(p-1) \\
        &\equiv 1 - pg^{p-2} \not\equiv 1 \pmod{p^2}.
        \end{aligned}
        $$

        **Bước 2**: Với $g$ đã chọn ở trên, với mọi $e\ge 1$ đều có
        $g^{\varphi(p^e)}\not\equiv 1\pmod{p^{e+1}}$.

        Cách chọn $g$ bảo đảm biểu thức này đúng khi $e=1$. Giả sử biểu thức
        đúng với trường hợp $e$, cần chứng minh nó cũng đúng với trường hợp
        $e+1$. Với mọi $e \ge 1$, theo định lí Euler tồn tại $\lambda$ sao cho

        $$
        g^{\varphi(p^e)} = 1 + \lambda p^e
        $$

        đúng. Theo giả thiết quy nạp, $\lambda\perp p$. Vì
        $\varphi(p^{e+1})=p\varphi(p^e)$, nên

        $$
        g^{\varphi(p^{e+1})} = \left(g^{\varphi(p^{e})}\right)^p = (1 + \lambda p^e)^p \equiv 1 + \lambda p^{e+1} \pmod{p^{e+2}}.
        $$

        Kết hợp với $\lambda\perp p$, thu được
        $g^{\varphi(p^{e+1})}\not\equiv 1\pmod{p^{e+2}}$. Theo quy nạp toán
        học, mệnh đề đúng.

        **Bước 3**: Với $g$ đã chọn ở trên, với mọi $e\ge 1$, $g$ đều là căn
        nguyên thủy modulo $p^e$.

        Cách chọn $g$ bảo đảm mệnh đề đúng khi $e=1$. Giả sử mệnh đề đúng với
        $e$, cần chứng minh nó đúng với $e+1$. Viết gọn $\delta_{p^{e+1}}(g)$ là
        $\delta$. Vì $g^\delta\equiv 1\pmod{p^{e+1}}$, tất yếu cũng có
        $g^\delta\equiv 1\pmod{p^e}$. Theo giả thiết quy nạp,
        $\delta_{p^e}(g) = \varphi(p^e)$. Do đó, theo
        [Tính chất 2](#ord-prop-2) về bậc ở trên, $\varphi(p^e)\mid\delta$.
        Lại theo định lí Euler, $\delta\mid\varphi(p^{e+1})$. Nhưng
        $\varphi(p^{e+1})=p\varphi(p^e)$. Vì vậy chỉ có hai khả năng:
        $\delta=\varphi(p^e)$ hoặc $\delta=\varphi(p^{e+1})$. Tuy nhiên, kết
        luận ở bước 2 cho thấy
        $g^{\varphi(p^e)}\not\equiv 1\pmod{p^{e+1}}$. Do đó khả năng
        $\delta=\varphi(p^e)$ không đúng. Khả năng duy nhất là
        $\delta=\varphi(p^{e+1})$. Điều này chứng minh $g$ là căn nguyên thủy
        modulo $p^{e+1}$. Theo quy nạp toán học, mệnh đề đúng với mọi
        $e\ge 1$.

3.  $m=2p^{e}$, trong đó $p$ là số nguyên tố lẻ và $e\in\mathbf N_+$.

    ???+ note "Bổ đề 3"
        Với số nguyên tố lẻ $p$ và $e \in \mathbf{N}_+$, căn nguyên thủy modulo
        $2p^e$ tồn tại.

    ??? note "Chứng minh"
        Giả sử $g$ là căn nguyên thủy modulo $p^{e}$, khi đó $g+p^e$ cũng là
        căn nguyên thủy modulo $p^{e}$. Trong hai số này chắc chắn có một số
        lẻ; không mất tính tổng quát, giả sử đó là $g$. Khi đó
        $(g,2p^e)=1$. Đặt $\delta=\delta_{2p^e}(g)$, cần chứng minh
        $\delta=\varphi(2p^e)$. Theo định lí Euler,
        $\delta\mid\varphi(2p^e)$. Đồng thời, theo định nghĩa
        $g^\delta\equiv 1\pmod{2p^e}$, nên $g^\delta\equiv 1\pmod{p^e}$. Do
        đó, theo [Tính chất 2](#ord-prop-2) về bậc và cách chọn $g$, có
        $\delta_{p^e}(g)=\varphi(p^e)\mid \delta$. Theo công thức hàm Euler,
        $\varphi(2p^e) = \varphi(p^e)$. Vì vậy
        $\delta=\delta_{2p^e}(g)=\varphi(p^e)$. Điều này chứng minh $g$ là căn
        nguyên thủy modulo $2p^e$.

4.  $m\ne 1,2,4,p^{e},2p^{e}$, trong đó $p$ là số nguyên tố lẻ và
    $e\in\mathbf N_+$.

    <a id="prim-root-lem-4"></a>

    ???+ note "Bổ đề 4"
        Giả sử $m\neq 1,2,4$ và không tồn tại số nguyên tố lẻ $p$ cùng số
        nguyên dương $e$ sao cho $m=p^e$ hoặc $m=2p^e$. Khi đó căn nguyên thủy
        modulo $m$ không tồn tại.

    ??? note "Chứng minh"
        Với $m=2^e$ và $e\ge 3$, giả sử căn nguyên thủy $g$ modulo $m$ tồn tại.
        Vì $g\perp m$, nó phải là số lẻ. Giả sử $g=2k+1$ với $k\in\mathbf N$,
        khi đó

        $$
        \begin{aligned}
        g^{2^{e-2}}
        &=(2k+1)^{2^{e-2}} \\
        &\equiv 1 + \binom{2^{e-2}}{1}(2k) + \binom{{2^{e-2}}}{2}(2k)^2 \\
        &= 1 + 2^{e-1}k + 2^{e-1}(2^{e-2}-1)k^2 \\
        &= 1 + 2^{e-1}(k + (2^{e-2}-1)k^2) \\
        &\equiv 1 \pmod{2^{e}}.
        \end{aligned}
        $$

        Ở dòng gần cuối, vì $k$ và $(2^{e-2}-1)k^2$ có cùng tính chẵn lẻ, tổng
        của chúng là số chẵn. Theo định nghĩa bậc,
        $\delta_{2^{e}}(g)\le 2^{e-2}< \varphi(2^{e}) = 2^{e-1}$. Điều này mâu
        thuẫn với giả thiết $g$ là căn nguyên thủy. Theo phản chứng, căn nguyên
        thủy như vậy không tồn tại.

        Giả sử $m$ thỏa mãn các điều kiện đã nêu và không phải lũy thừa của
        $2$. Khi đó chắc chắn tồn tại $2 < m_1 < m_2$ và $m_1\perp m_2$ sao cho
        $m=m_1m_2$. Giả sử căn nguyên thủy $g$ modulo $m$ tồn tại. Vì
        $g\perp m$, nên với $i=1,2$ đều có $g\perp m_i$. Theo định lí Euler,

        $$
        g^{\varphi(m_i)} \equiv 1 \pmod{m_i}.
        $$

        Vì $m_i > 2$, $\varphi(m_i)$ là số chẵn, nên với $i=1,2$ có

        $$
        g^{\frac{1}{2}\varphi(m_1)\varphi(m_2)} \equiv 1 \pmod{m_i}.
        $$

        Theo [định lí thặng dư Trung Hoa](./crt.md), suy ra

        $$
        g^{\frac{1}{2}\varphi(m_1)\varphi(m_2)} \equiv 1 \pmod{m}.
        $$

        Lại vì $\varphi(m)=\varphi(m_1)\varphi(m_2)$, theo định nghĩa bậc có

        $$
        \delta_m(g) \le \frac{1}{2}\varphi(m_1)\varphi(m_2) = \dfrac{1}{2}\varphi(m) < \varphi(m).
        $$

        Điều này mâu thuẫn với giả thiết $g$ là căn nguyên thủy modulo $m$. Vì
        vậy, theo phản chứng, căn nguyên thủy modulo $m$ không tồn tại.

Tổng hợp bốn bổ đề trên cho điều kiện cần và đủ để một số có căn
nguyên thủy.

<span id="thuật-toán-tìm-căn-nguyên-thủy"></span>

### Thuật toán tìm căn nguyên thủy

Với bất kỳ modulo $m$ nào có căn nguyên thủy, để tìm một căn nguyên thủy $g$,
chỉ cần liệt kê các số nguyên dương có thể và lần lượt kiểm tra chúng có phải
căn nguyên thủy hay không. Khi liệt kê, thường có hai cách xử lý: liệt kê từ
nhỏ đến lớn, hoặc sinh ngẫu nhiên một vài số nguyên dương. Hiệu quả thực tế của
hai cách này tương đương nhau.

Khi liệt kê từ nhỏ đến lớn, thu được căn nguyên thủy nhỏ nhất $g_m$ modulo
$m$; do đó độ phức tạp của phần liệt kê phụ thuộc vào kích thước của $g_m$. Về
điểm này, có các ước lượng sau:

-   Ước lượng cận trên: Wang Yuan[^yuan1959note] và
    Burgess[^burgess1962character] chứng minh rằng căn nguyên thủy nhỏ nhất của
    số nguyên tố $p$ thỏa mãn $g_p=O\left(p^{0.25+\epsilon}\right)$, trong đó
    $\epsilon>0$. Cohen, Odoni và Stothers[^cohen1974least] cùng Elliott và
    Murata[^elliott1998least] lần lượt chứng minh ước lượng này cũng đúng cho
    modulo $p^2$ và $2p^2$, trong đó $p$ là số nguyên tố lẻ. Vì với $e>2$, căn
    nguyên thủy modulo $p^2$ (hoặc $2p^2$) cũng là căn nguyên thủy modulo $p^e$
    (hoặc $2p^e$), nên cận trên $O\left(p^{0.25+\epsilon}\right)$ của căn
    nguyên thủy nhỏ nhất đúng cho mọi trường hợp.
-   Ước lượng cận dưới: Fridlander[^fridlender1949least] và
    Salie[^salie1949kleinsten] chứng minh rằng tồn tại $C>0$ sao cho với vô hạn
    số nguyên tố $p$, căn nguyên thủy nhỏ nhất thỏa mãn $g_p > C\log p$.
-   Ước lượng trong trường hợp trung bình: Burgess và
    Elliott[^burgess1968average] chứng minh rằng trong trường hợp trung bình,
    căn nguyên thủy nhỏ nhất của số nguyên tố $p$ thỏa mãn
    $g_p=O((\log p)^2(\log\log p)^4)$. Elliott và Murata[^elliott1997average]
    tiếp tục dự đoán giá trị trung bình của căn nguyên thủy nhỏ nhất của số
    nguyên tố $p$ là một hằng số, và qua kiểm chứng số[^more-evidence] thu được
    giá trị xấp xỉ $4.926$. Sau đó, Elliott và Murata[^elliott1998least] mở
    rộng dự đoán này sang trường hợp modulo $2p^2$.

Theo các phân tích này, khi tìm căn nguyên thủy nhỏ nhất bằng vét cạn, độ phức
tạp $O(g_m(\log m)^2)$ của phần liệt kê là chấp nhận được.

Ngoài việc liệt kê từ nhỏ đến lớn, còn có thể tìm căn nguyên thủy bằng cách
sinh ngẫu nhiên các số nguyên dương rồi kiểm tra. Mật độ căn nguyên thủy không
thấp:[^density-prim-root]

$$
\dfrac{\varphi(\varphi(m))}{m} = \Omega\left(\dfrac{1}{\log\log m}\right).
$$

Vì vậy, khi tìm căn nguyên thủy bằng phương pháp ngẫu nhiên, độ phức tạp kỳ vọng
của phần liệt kê là $O((\log m)^2\log\log m)$.

Cần lưu ý rằng khi kiểm tra căn nguyên thủy, cần biết phân tích thừa số
nguyên tố của $\varphi(m)$. Trong các
[thuật toán phân tích thừa số nguyên tố thường dùng](./pollard-rho.md) trong
lập trình thi đấu, thuật toán Pollard Rho có độ phức tạp tối ưu cũng cần thời
gian $O(m^{1/4+\varepsilon})$. Vì vậy, chỉ cần phân tích thừa số nguyên tố của
$\varphi(m)$ chưa biết, bất kể dùng cách liệt kê nào, nút thắt độ phức tạp của
việc tìm căn nguyên thủy nằm ở bước phân tích thừa số nguyên tố, chứ không phải
phần liệt kê và kiểm tra.

<span id="hàm-carmichael"></span>

## Hàm Carmichael

So với khái niệm cục bộ là bậc của một phần tử modulo $m$, hàm Carmichael là
một khái niệm toàn cục. Nó là chu kỳ chung nhỏ nhất của lũy thừa của tất cả các
số nguyên nguyên tố cùng nhau với $m$.

???+ abstract "Hàm Carmichael"
    Với $m\in\mathbf N_+$, định nghĩa $\lambda(m)$ là số nguyên dương nhỏ nhất
    $n$ sao cho đồng dư $a^n\equiv 1\pmod m$ đúng với mọi $a\perp m$. Hàm
    $\lambda:\mathbf N_+\to\mathbf N_+$ được gọi là **hàm Carmichael**.

Theo [Tính chất 2](#ord-prop-2), việc $a^n\equiv 1\pmod m$ đúng với mọi
$a\perp m$ có nghĩa là $\delta_m(a)\mid n$ với mọi $a\perp m$. Nói cách khác,
số nguyên dương $n$ thỏa mãn điều kiện này nhất định là bội chung của tất cả các
$\delta_m(a)$. Do đó, số $n$ nhỏ nhất như vậy chính là bội chung nhỏ nhất của
chúng:

$$
\lambda(m) = \operatorname{lcm}\{\delta_m(a) : a\perp m\}.
$$

Đây cũng thường được dùng làm định nghĩa tương đương của hàm Carmichael.

Áp dụng lặp lại [Tính chất 5](#ord-prop-5), biết chắc chắn tồn tại một phần
tử $a\perp m$ sao cho $\delta_m(a)=\lambda(m)$. Do đó công thức trên cũng có thể
viết thành

$$
\lambda(m) = \max\{\delta_m(a) : a\perp m\}.
$$

Phần tử $a\perp m$ đạt giá trị lớn nhất này cũng được gọi là **$\lambda$-căn
nguyên thủy** modulo $m$. Nó tồn tại với mọi modulo $m$.

<span id="công-thức-truy-hồi"></span>

### Công thức truy hồi

Hàm Carmichael là một [hàm số học](./basic.md#hàm-số-học).
Mục này thảo luận một công thức truy hồi của nó, từ đó đưa ra một chứng minh
khác cho định lí tồn tại căn nguyên thủy.

Tuy không phải hàm nhân tính, khi tính hàm Carmichael vẫn có thể xử lý riêng
các thừa số nguyên tố cùng nhau.

???+ note "Bổ đề"
    Với hai số nguyên dương nguyên tố cùng nhau $m_1,m_2$, có
    $\lambda(m_1m_2)=[\lambda(m_1),\lambda(m_2)]$.

??? note "Chứng minh"
    Giả sử $a_1$ và $a_2$ lần lượt là $\lambda$-căn nguyên thủy modulo $m_1$ và
    modulo $m_2$. Đặt $m=m_1m_2$. Theo
    [định lí thặng dư Trung Hoa](./crt.md), tồn tại $a\perp m$ sao cho
    $a\equiv a_i\pmod{m_i}$ với $i=1,2$. Vì $a^{\lambda(m)}\equiv 1\pmod m$,
    nên với $i=1,2$ đều có $a_i^{\lambda(m)} \equiv 1\pmod{m_i}$. Từ đó theo
    [Tính chất 2](#ord-prop-2) và cách chọn $a_i$, có
    $\lambda(m_i)=\delta_{m_i}(a_i)\mid \lambda(m)$. Điều này chứng minh
    $[\lambda(m_1),\lambda(m_2)]\mid\lambda(m)$.

    Ngược lại, với mọi $a\perp m$ và $i=1,2$, đều có
    $a^{[\lambda(m_1),\lambda(m_2)]} \equiv 1 \pmod{m_i}$. Áp dụng định lí
    thặng dư Trung Hoa, thu được
    $a^{[\lambda(m_1),\lambda(m_2)]} \equiv 1 \pmod{m}$ với mọi $a\perp m$.
    Theo định nghĩa hàm Carmichael, $\lambda(m)\mid [\lambda(m_1),\lambda(m_2)]$.

    Do đó dạng bằng trong mệnh đề đúng.

Vì vậy, tiếp theo chỉ cần tính giá trị của hàm Carmichael tại các lũy thừa
nguyên tố. Trước hết, xử lý trường hợp lũy thừa của $2$.

???+ note "Bổ đề"
    Với $m=2^e$ và $e\in\mathbf N_+$, có $\lambda(2)=1$, $\lambda(4)=2$, và
    với mọi $e\ge 3$ đều có $\lambda(m)=2^{e-2}$.

??? note "Chứng minh"
    Trường hợp $m=2,4$ có thể xét riêng. Với $m=2^e$ và $e\ge 3$, trước hết lặp
    lại phần đầu trong chứng minh [Bổ đề 4](#prim-root-lem-4) ở trên, thu được
    $\lambda(m)\le 2^{e-2}$. Tiếp theo, chỉ cần chứng minh tồn tại phần tử bậc
    $2^{e-2}$. Để làm việc này, có

    $$
    5^{2^{e-3}} = (1 + 2^2)^{2^{e-3}} = 1 + 2^2\times 2^{e-3} = 1 + 2^{e-1} \not\equiv 1 \pmod{2^e}.
    $$

    Điều này cho thấy $\delta_m(5)\nmid 2^{e-3}$, lại vì
    $\delta_m(5) \mid 2^{e-2}$, nên $5$ chỉ có thể là phần tử bậc $2^{e-2}$. Do
    đó $\lambda(m)=2^{e-2}$.

Trong quá trình chứng minh bổ đề này, thực ra đã thu được mô tả về cấu trúc
của hệ thặng dư thu gọn modulo $2^e$:

<a id="mod-pow-2"></a>

???+ note "Hệ quả"
    Giả sử modulo là $2^e$ và $e \ge 2$. Khi đó mọi số lẻ đều đồng dư với đúng
    một số nguyên có dạng $\pm 5^k$, trong đó $k\in\mathbf N$ và
    $k < 2^{e-2}$. Nói cách khác, $\pm 1,\pm 5,\cdots,\pm 5^{2^{e-2}-1}$ đôi
    một không đồng dư, và tạo thành một hệ thặng dư thu gọn.

??? note "Chứng minh"
    Có thể kiểm tra trực tiếp trường hợp $e=2$ đúng. Với $e \ge 3$, trong
    chứng minh ở trên đã có bậc của $5$ modulo $2^e$ là $2^{e-2}$, nên
    $1,5,\cdots,5^{2^{e-2}-1}$ đôi một không đồng dư. Vì các số nguyên này đều
    dư $1$ modulo $4$, còn các số đối của chúng đều dư $3$ modulo $4$, nên
    $\pm 1,\pm 5,\cdots,\pm 5^{2^{e-2}-1}$ đôi một không đồng dư modulo $2^e$.
    Vì tổng cộng có $2^{e-1}$ số, đúng bằng kích thước của hệ thặng dư thu gọn
    modulo $2^{e}$, chúng tạo thành chính hệ thặng dư thu gọn.

Sau đó, xử lý trường hợp lũy thừa của số nguyên tố lẻ.

???+ note "Bổ đề"
    Với $m=p^e$, trong đó $p$ là số nguyên tố lẻ và $e\in\mathbf N_+$, có
    $\lambda(m)=p^{e-1}(p-1)$.

??? note "Chứng minh"
    Trước hết chứng minh mệnh đề đúng với $e=1$, tức $m=p$ là số nguyên tố lẻ.
    Theo định nghĩa hàm Carmichael, mọi số nguyên $a$ nguyên tố cùng nhau với
    $p$ đều là nghiệm của phương trình đồng dư
    $x^{\lambda(p)}\equiv 1\pmod{p}$. Theo nghĩa modulo $p$, phương trình này có
    tổng cộng $p-1$ nghiệm đôi một khác nhau. Theo
    [định lí Lagrange](./congruence-equation.md#định-lý-3-lagrange),
    có $p-1\le\lambda(p)$. Đồng thời, định lí Euler yêu cầu
    $\lambda(p)\mid\varphi(p)=p-1$. Do đó $\lambda(p)=p-1$.

    Với $m=p^e$ và $e> 1$, có thể bắt đầu bằng việc chứng minh $1+p$ là phần tử
    bậc $p^{e-1}$. Thật vậy,

    $$
    (1+p)^{p^{e-1}} \equiv 1,\quad (1+p)^{p^{e-2}} \equiv 1 + p^{e-1} \not\equiv 1 \pmod{p^e}.
    $$

    Nên $\delta_m(1+p)=p^{e-1}$. Ngoài ra, giả sử $g$ là căn nguyên thủy modulo
    $p$. Khi đó, vì $g^{\delta_m(g)}\equiv 1 \pmod{p}$, theo
    [Tính chất 2](#ord-prop-2) về bậc, có $p-1\mid\delta_m(g)$. Theo định
    nghĩa hàm Carmichael và định lí Euler,

    $$
    p^{e-1}(p-1) = [\delta_m(g),p^{e-1}]\mid\lambda(m) \mid \varphi(m) = p^{e-1}(p-1).
    $$

    Do đó $\lambda(m)=p^{e-1}(p-1)$.

Tóm tắt các kết quả của mục này, thu được công thức truy hồi của hàm
Carmichael:

???+ note "Định lí"
    Với mọi số nguyên dương $m$, có

    $$
    \lambda(m) = \begin{cases}
    \varphi(m), & \text{nếu }m=1,2,4,p^e\text{ với }p\text{ nguyên tố lẻ và }e \ge 1,\\
    \frac{1}{2}\varphi(m), &\text{nếu }m=2^e,~e\ge 3,\\
    \operatorname{lcm}\{\lambda(p_1^{e_1}),\lambda(p_2^{e_2}),\cdots,\lambda(p_s^{e_s})\}, &\text{nếu }m = p_1^{e_1}p_2^{e_2}\cdots p_s^{e_s}\text{ với }p_1,p_2,\cdots,p_s\text{ đôi một phân biệt}.
    \end{cases}
    $$

Dùng công thức truy hồi này có thể làm mạnh kết quả phía trên:

???+ note "Hệ quả"
    Với các số nguyên dương $m_1,m_2$, có
    $\lambda([m_1,m_2])=[\lambda(m_1),\lambda(m_2)]$.

So sánh định nghĩa căn nguyên thủy và hàm Carmichael, thấy rằng căn nguyên thủy
modulo $m$ tồn tại khi và chỉ khi $\lambda(m)=\varphi(m)$. Từ công thức truy
hồi của hàm Carmichael, có thể quy nạp ra kết quả sau:

???+ note "Hệ quả"
    Căn nguyên thủy modulo $m$ tồn tại khi và chỉ khi $m=1,2,4,p^e,2p^e$, trong
    đó $p$ là số nguyên tố lẻ và $e\in\mathbf N_+$.

Vì chứng minh công thức truy hồi trong mục này không dùng đến định lí tồn tại
căn nguyên thủy, đây tạo thành một chứng minh khác cho định lí đó.

<span id="số-carmichael"></span>

### Số Carmichael

Dùng hàm Carmichael, có thể thảo luận tính chất và phân bố của số Carmichael
(OEIS:[A002997](https://oeis.org/A002997)). Đây là các hợp số mà
[kiểm tra tính nguyên tố Fermat](./prime.md#kiểm-tra-tính-nguyên-tố-fermat)
chắc chắn không thể loại bỏ chính xác.

???+ abstract "Số Carmichael"
    Với hợp số $n$, nếu với mọi số nguyên $a\perp n$ đều có đồng dư
    $a^{n-1} \equiv 1 \pmod n$, thì $n$ được gọi là **số Carmichael**.

Số Carmichael nhỏ nhất là $561 = 3 \times 11 \times 17$.

Theo định nghĩa hàm Carmichael, hợp số $n$ là số Carmichael khi và chỉ khi
$\lambda(n)\mid n-1$, trong đó $\lambda(n)$ là hàm Carmichael. Hơn nữa, có
phương pháp sau để xác định hợp số $n$ có phải số Carmichael hay không:

???+ note "Tiêu chuẩn Korselt[^korselt1899probleme]"
    Hợp số $n$ là số Carmichael khi và chỉ khi $n$ không có thừa số chính phương
    và với mọi thừa số nguyên tố $p$ của $n$ đều có $(p-1) \mid (n-1)$.

??? note "Chứng minh"
    Trước hết chứng minh tính cần thiết. Giả sử $\lambda(n)\mid (n-1)$. Kiểm
    tra công thức truy hồi của hàm Carmichael: nếu $n$ có thừa số chính phương
    $p$, thì chắc chắn $p\mid \lambda(n)$. Nhưng $p\nmid (n-1)$, mâu thuẫn.
    Tương tự, công thức truy hồi của hàm Carmichael cho thấy
    $(p-1)\mid \lambda(n)$, nên cũng có $(p-1) \mid (n-1)$.

    Tiếp theo chứng minh tính đủ. Vì $n$ là hợp số, nó chắc chắn có thừa số
    nguyên tố lẻ $p$, do đó $n-1$ là số chẵn, và $n$ cũng chắc chắn là số lẻ.
    Với hợp số lẻ không có thừa số chính phương $n$, theo công thức truy hồi
    của hàm Carmichael, $\lambda(n)=\operatorname{lcm}\{p-1:p\mid n\}$. Vì vậy,
    chỉ cần $(p-1) \mid (n-1)$ đúng với mọi thừa số nguyên tố $p$, thì chắc chắn
    $\lambda(n)\mid (n-1)$.

Từ tiêu chuẩn này, có thể thiết lập một số tính chất đơn giản của số
Carmichael:

???+ note "Hệ quả"
    Số Carmichael là số lẻ, không có thừa số chính phương, và có ít nhất $3$
    thừa số nguyên tố phân biệt.

??? note "Chứng minh"
    Hai tính chất đầu có thể suy trực tiếp từ tiêu chuẩn Korselt và chứng minh
    của nó. Để thu được tính chất thứ ba, chỉ cần chứng minh thêm: tích
    $n=p_1p_2$ của hai số nguyên tố phân biệt $p_1,p_2$ chắc chắn không phải số
    Carmichael. Giả sử $n=p_1p_2$ là số Carmichael. Theo tiêu chuẩn Korselt,
    $(p_i-1)\mid (n-1)$. Nhưng có

    $$
    n-1=p_1p_2-1\equiv p_2-1 \pmod{p_1-1}.
    $$

    Do đó $(p_1-1)\mid(p_2-1)$. Tương tự,
    $(p_2-1)\mid(p_1-1)$. Nghĩa là $p_1=p_2$. Điều này mâu thuẫn với giả thiết.
    Vì vậy số Carmichael $n$ có ít nhất $3$ thừa số nguyên tố phân biệt.

Dùng số học giải tích, còn có thể thu được một số tính chất về phân bố của
số Carmichael. Gọi $C(n)$ là số lượng số Carmichael không vượt quá $n$. Alford,
Granville, and Pomerance[^alford1994infinitely] chứng minh rằng với $n$ đủ lớn,
có $C(n)>n^{2/7}$. Từ đó, có vô hạn số Carmichael. Trước đó,
Erdos[^erdos1956pseudoprimes] đã chứng minh
$C(n) < n\exp\left(-c\dfrac{\ln n\ln\ln\ln n}{\ln\ln n}\right)$, trong đó $c$
là hằng số. Vì vậy phân bố của số Carmichael rất thưa (so với số nguyên tố).
Thực tế, có[^pinchcarmichael] $C(10^9)=646$, $C(10^{18})=1~401~644$.

<span id="tài-liệu-tham-khảo-và-ghi-chú"></span>

## Tài liệu tham khảo và ghi chú

-   [Primitive root modulo n - Wikipedia](https://en.wikipedia.org/wiki/Primitive_root_modulo_n)
-   [The order of a unit - Course Notes](https://crypto.stanford.edu/pbc/notes/numbertheory/order.html)
-   [The primitive root theorem - Amin Witno's notes](http://witno.com/philadelphia/notes/won5.pdf)
-   [Carmichael function - Wikipedia](https://en.wikipedia.org/wiki/Carmichael_function)
-   [Carmichael's Lambda Function - Brilliant Math & Science Wiki](https://brilliant.org/wiki/carmichaels-lambda-function/)
-   [Carmichael number - Wikipedia](https://en.wikipedia.org/wiki/Carmichael_number)
-   [Carmichael Number - Wolfram MathWorld](https://mathworld.wolfram.com/CarmichaelNumber.html)

[^yuan1959note]: Wang Y. "On the least primitive root of a prime." (in Chinese). Acta Math Sinica, 1959, 4: 432-441; English transl. in *Sci. Sinica*, 1961, 10: 1-14.

[^burgess1962character]: BURGESS, David A. "On character sums and primitive roots." Proceedings of the London Mathematical Society, 1962, 3.1: 179-192.

[^cohen1974least]: Cohen, S. D., R. W. K. Odoni, and W. W. Stothers. "On the least primitive root modulo p 2." Bulletin of the London Mathematical Society 6, no. 1 (1974): 42-46.

[^elliott1998least]: Elliott, P. D. T. A., and L. Murata. "The least primitive root mod 2p2." Mathematika 45, no. 2 (1998): 371-379.

[^fridlender1949least]: FRIDLENDER, V. R. "On the least n-th power non-residue." Dokl. Akad. Nauk SSSR. 1949. p. 351-352.

[^salie1949kleinsten]: SALIE, Hans. "Uber den kleinsten positiven quadratischen Nichtrest nach einer Primzahl." Mathematische Nachrichten, 1949, 3.1: 7-8.

[^burgess1968average]: Burgess, D. A., and P. D. T. A. Elliott. "The average of the least primitive root." Mathematika 15, no. 1 (1968): 39-50.

[^elliott1997average]: Elliott, Peter DTA, and Leo Murata. "On the average of the least primitive root modulo p." Journal of The london Mathematical Society 56, no. 3 (1997): 435-454.

[^more-evidence]: Có thể xem thêm các kết quả tại [Least prime primitive root of prime numbers](https://sweet.ua.pt/tos/p_roots.html).

[^density-prim-root]: Nếu căn nguyên thủy modulo $m$ tồn tại, thì
    $\varphi(m)\ge\dfrac{1}{3}m$, và dấu bằng chỉ đạt tại
    $m=2\times 3^e~(e\in\mathbf N_+)$. Hơn nữa, khi $m > 2$, có ước lượng cho
    hàm Euler $\varphi(m)$:
    $\varphi(m)>\dfrac{m}{e^{\gamma}\log\log m+\frac{3}{\log\log m}}$. Kết hợp
    hai kết quả này, thu được biểu thức trong bài. Về ước lượng này của hàm
    Euler, có thể tham khảo bài báo Rosser, J. Barkley, and Lowell Schoenfeld.
    "Approximate formulas for some functions of prime numbers." Illinois Journal
    of Mathematics 6, no. 1 (1962): 64-94.

[^korselt1899probleme]: Korselt, A. R. (1899). "Probleme chinois." L'Intermediaire des Mathematiciens. 6: 142-143.

[^alford1994infinitely]: W. R. Alford; Andrew Granville; Carl Pomerance (1994). "There are Infinitely Many Carmichael Numbers." Annals of Mathematics. 140 (3): 703-722.

[^erdos1956pseudoprimes]: Erdos, P. (1956). "On pseudoprimes and Carmichael numbers." Publ. Math. Debrecen. 4 (3-4): 201-206.

[^pinchcarmichael]: PINCH, Richard GE. The Carmichael numbers up to ${10}^{20}$.
