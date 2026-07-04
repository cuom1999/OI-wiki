Kiến thức nền: [định lí nhỏ Fermat](./fermat.md#%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86), [định lí Euler](./fermat.md#%E6%AC%A7%E6%8B%89%E5%AE%9A%E7%90%86), [định lí Lagrange](./congruence-equation.md#%E5%AE%9A%E7%90%86-3lagrange-%E5%AE%9A%E7%90%86)

Bậc và căn nguyên thủy là các công cụ quan trọng để hiểu cấu trúc nhân của
[hệ thặng dư thu gọn](./basic.md#%E5%90%8C%E4%BD%99%E7%B1%BB%E4%B8%8E%E5%89%A9%E4%BD%99%E7%B3%BB)
$\mathbf Z_m^*$ modulo $m$. Dựa trên chúng, ta có thể định nghĩa các khái niệm
như [logarit rời rạc](./discrete-logarithm.md). Phần thảo luận tổng quát hơn có
thể xem ở các mục liên quan trong phần đại số trừu tượng, chẳng hạn
[lý thuyết nhóm](../algebra/group-theory.md#%E9%98%B6) và
[lý thuyết vành](../algebra/ring-theory.md#%E5%BA%94%E7%94%A8%E6%95%B4%E6%95%B0%E5%90%8C%E4%BD%99%E7%B1%BB%E7%9A%84%E4%B9%98%E6%B3%95%E7%BE%A4).

<span id="&#x9636;"></span>

## Bậc

Trong mục này, ta luôn giả sử modulo $m\in\mathbf N_+$ và cơ số
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
    Trong [đại số trừu tượng](../algebra/group-theory.md#%E9%98%B6), "bậc" ở
    đây chính là bậc của phần tử $a$ trong nhóm tạo bởi hệ thặng dư thu gọn
    modulo $m$ theo phép nhân. Ký hiệu $\delta$ để biểu diễn bậc chỉ dùng cho
    nhóm đặc biệt này. Nhiều tính chất bên dưới có thể mở rộng trực tiếp thành
    tính chất về bậc của phần tử trong nhóm ở đại số trừu tượng.

    Ngoài ra còn có khái niệm "nửa bậc", trong số học thường dùng ký hiệu
    $\delta^-$. Đó là số nguyên dương nhỏ nhất thỏa mãn đồng dư
    $a^n \equiv -1 \pmod m$. Nửa bậc không phải là khái niệm trong lý thuyết
    nhóm. Bậc luôn tồn tại, còn nửa bậc thì không nhất thiết tồn tại.

<span id="&#x5E42;&#x7684;&#x5FAA;&#x73AF;&#x7ED3;&#x6784;"></span>

### Cấu trúc tuần hoàn của lũy thừa

Dùng bậc, ta có thể mô tả cấu trúc tuần hoàn của lũy thừa. Với lũy thừa
$a^n\bmod m$, chia số mũ $n$ cho bậc $\delta_m(a)$ có dư:

$$
n = \delta_m(a)q + r, ~ 0\le r < \delta_m(a).
$$

Tiếp theo, dùng các quy tắc tính lũy thừa, ta có

$$
a^n = a^{\delta_m(a)q + r} = (a^{\delta_m(a)})^q \cdot a^r \equiv a^r \pmod m.
$$

Điều này cho thấy với lũy thừa có số mũ bất kỳ, ta có thể tiến nó về chu kỳ
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

Trong [định lí Euler](./fermat.md#%E6%AC%A7%E6%8B%89%E5%AE%9A%E7%90%86), đồng
dư $a^{\varphi(m)}\equiv 1\pmod m$ đúng với mọi $a\perp m$. Kết hợp với
[Tính chất 2](#ord-prop-2), điều này cho thấy với mọi $a\perp m$ đều có
$\delta_m(a)\mid\varphi(m)$. Nói cách khác, $\varphi(m)$ là một bội chung của
bậc của tất cả các $a\perp m$. Với một số nguyên dương $m$, bội chung nhỏ nhất
của tất cả các bậc $\delta_m(a)$ với $a\perp m$, ký hiệu là $\lambda(m)$, chính
là [hàm Carmichael](#carmichael-%E5%87%BD%E6%95%B0) của $m$. Phần sau sẽ thảo
luận chi tiết các tính chất của nó.

Tương tự các cấu trúc tuần hoàn khác, ta có thể tính bậc của $a^k$ dựa trên
bậc của $a$.

<a id="ord-prop-3"></a>

???+ note "Tính chất 3"
    Với $k,a\in\mathbf Z,m\in\mathbf N_+$ và $a\perp m$, ta có

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

<span id="&#x4E58;&#x79EF;&#x7684;&#x9636;"></span>

### Bậc của tích

Giả sử $a,b$ là các số nguyên khác nhau và cùng nguyên tố với $m$. Nếu đã biết
các bậc $\delta_m(a)$ và $\delta_m(b)$, ta cũng có thể thu được một số thông
tin về bậc $\delta_{m}(ab)$ của tích $ab$.

<a id="ord-prop-4"></a>

???+ note "Tính chất 4"
    Với $a,b\in\mathbf Z,m\in\mathbf N_+$ và $a,b\perp m$, ta có

    $$
    \dfrac{[\delta_m(a),\delta_m(b)]}{(\delta_m(a),\delta_m(b))} \mid \delta_m(ab) \mid [\delta_m(a),\delta_m(b)].
    $$

??? note "Chứng minh"
    Vì $[\delta_m(a),\delta_m(b)]$ là bội của cả $\delta_m(a)$ lẫn
    $\delta_m(b)$, theo [Tính chất 2](#ord-prop-2) ta có

    $$
    (ab)^{[\delta_m(a),\delta_m(b)]} = a^{[\delta_m(a),\delta_m(b)]} b^{[\delta_m(a),\delta_m(b)]} \equiv 1 \pmod m.
    $$

    Áp dụng Tính chất 2 một lần nữa, ta được

    $$
    \delta_m(ab) \mid [\delta_m(a),\delta_m(b)].
    $$

    Đây là quan hệ chia hết ở phía phải.

    Ngược lại, vì

    $$
    1 \equiv (ab)^{\delta_m(ab)\delta_m(b)} \equiv a^{\delta_m(ab)\delta_m(b)} \pmod m,
    $$

    nên áp dụng Tính chất 2 ta được $\delta_m(a)\mid\delta_m(ab)\delta_m(b)$.
    Rút gọn $(\delta_m(a),\delta_m(b))$ ở hai phía, ta có

    $$
    \dfrac{\delta_m(a)}{(\delta_m(a),\delta_m(b))}\mid\delta_m(ab)\dfrac{\delta_m(b)}{(\delta_m(a),\delta_m(b))}.
    $$

    Sau khi rút gọn ước chung, hai phân số là nguyên tố cùng nhau, nên

    $$
    \dfrac{\delta_m(a)}{(\delta_m(a),\delta_m(b))}\mid\delta_m(ab).
    $$

    Tương tự, ta cũng có

    $$
    \dfrac{\delta_m(b)}{(\delta_m(a),\delta_m(b))}\mid\delta_m(ab).
    $$

    Vì hai vế trái của hai quan hệ chia hết này nguyên tố cùng nhau, ta có

    $$
    \dfrac{[\delta_m(a),\delta_m(b)]}{(\delta_m(a),\delta_m(b))} =\dfrac{\delta_m(a)\delta_m(b)}{(\delta_m(a),\delta_m(b))^2}\mid\delta_m(ab).
    $$

    Đây là quan hệ chia hết ở phía trái.

Với trường hợp bậc của $a$ và $b$ nguyên tố cùng nhau, kết luận này có dạng đơn
giản hơn.

<a id="ord-prop-4p"></a>

???+ note "Tính chất 4'"
    Với $a,b\in\mathbf Z,m\in\mathbf N_+$ và $a,b\perp m$, ta có

    $$
    \delta_m(ab) = \delta_m(a)\delta_m(b) \iff \delta_m(a)\perp\delta_m(b).
    $$

??? note "Chứng minh"
    Nếu $\delta_m(a)\perp\delta_m(b)$, thì mọi quan hệ chia hết trong
    [Tính chất 4](#ord-prop-4) đều là dạng bằng, nên

    $$
    \delta_m(ab) = [\delta_m(a),\delta_m(b)] = \delta_m(a)\delta_m(b).
    $$

    Ngược lại, nếu $\delta_m(ab)=\delta_m(a)\delta_m(b)$, theo Tính chất 4 ta có

    $$
    \delta_m(a)\delta_m(b) = \delta_m(ab) \mid [\delta_m(a),\delta_m(b)].
    $$

    Điều này lập tức cho thấy $(\delta_m(a),\delta_m(b))=1$, tức là
    $\delta_m(a)\perp\delta_m(b)$.

Trong trường hợp tổng quát, các cận thu được từ [Tính chất 4](#ord-prop-4) đã
là chặt. Trường hợp bậc của tích đạt cận dưới rất dễ xây dựng: chẳng hạn với
$(a,b,m)=(3,5,7)$, ta có $\delta_m(a)=\delta_m(b)=6$, nhưng bậc của tích là
$\delta_m(ab)=1$.

Mặc dù trong trường hợp tổng quát, bậc của tích $ab$ không nhất thiết là bội
chung nhỏ nhất của các bậc của chúng, ta luôn có thể tìm một phần tử có bậc
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
    [Tính chất 3](#ord-prop-3), ta có

    $$
    \begin{aligned}
    \delta_m(a^{\gamma_B}) &= \dfrac{\delta_m(a)}{(\delta_m(a),\gamma_B)} = \dfrac{\delta_m(a)}{\gamma_B} = \gamma_A,\\
    \delta_m(b^{\eta_A}) &= \dfrac{\delta_m(b)}{(\delta_m(b),\eta_A)} = \dfrac{\delta_m(b)}{\eta_A} = \eta_B.
    \end{aligned}
    $$

    Vì $\gamma_A\perp\eta_B$, theo [Tính chất 4'](#ord-prop-4p), ta có

    $$
    \delta_m(a^{\gamma_B}b^{\eta_A}) = \gamma_A\eta_B = \prod_p p^{\max\{\alpha_p,\beta_p\}} = [\delta_m(a),\delta_m(b)].
    $$

    Do đó $c=a^{\gamma_B}b^{\eta_A}$ là phần tử có bậc bằng
    $[\delta_m(a),\delta_m(b)]$.

Kết luận này thường được dùng để xây dựng phần tử có bậc chỉ định.

<span id="&#x539F;&#x6839;"></span>

## Căn nguyên thủy

Căn nguyên thủy là các phần tử đặc biệt: bậc của nó đúng bằng số phần tử của
hệ thặng dư thu gọn modulo $m$.

???+ abstract "Căn nguyên thủy"
    Với $m\in\mathbf N_+$, nếu tồn tại $g\in\mathbf Z$ và $g\perp m$ sao cho
    $\delta_m(g)=|\mathbf Z_m^*|=\varphi(m)$, thì $g$ được gọi là **căn nguyên
    thủy modulo $m$** (primitive root modulo $m$). Ở đây, $\varphi(m)$ là
    [hàm Euler](./euler-totient.md).

Không phải mọi số nguyên dương $m$ đều có căn nguyên thủy modulo $m$. Theo
[Tính chất 1](#ord-prop-1), nếu căn nguyên thủy $g$ modulo $m$ tồn tại, thì các
lớp đồng dư chứa $g,g^2,\cdots,g^{\varphi(m)}$ đôi một khác nhau và tạo thành
hệ thặng dư thu gọn modulo $m$. Đặc biệt, với số nguyên tố $p$, các thặng dư
$g^i\bmod p$ đôi một khác nhau với $i=1,2,\cdots,p-1$.

???+ tip "Ghi chú"
    Trong [đại số trừu tượng](../algebra/ring-theory.md#%E5%BA%94%E7%94%A8%E6%95%B4%E6%95%B0%E5%90%8C%E4%BD%99%E7%B1%BB%E7%9A%84%E4%B9%98%E6%B3%95%E7%BE%A4),
    căn nguyên thủy chính là phần tử sinh của nhóm cyclic. Khái niệm này chỉ có
    tên "căn nguyên thủy" trong nhóm tạo bởi hệ thặng dư thu gọn modulo $m$ theo
    phép nhân; trong nhóm cyclic tổng quát, nó được gọi là "phần tử sinh".
    Không phải mọi nhóm tạo bởi hệ thặng dư thu gọn modulo $m$ theo phép nhân
    đều là nhóm cyclic; việc tồn tại căn nguyên thủy cho thấy nó đẳng cấu với
    một nhóm cyclic, còn nếu không tồn tại căn nguyên thủy thì không đẳng cấu.

Khi modulo bằng $1$, nhóm nhân các số nguyên modulo $1$ là $\{0\}$. Hiển nhiên
đây là nhóm cyclic, nên căn nguyên thủy là $0$.

<span id="&#x539F;&#x6839;&#x5224;&#x5B9A;&#x5B9A;&#x7406;"></span>

### Định lí kiểm tra căn nguyên thủy

Nếu đã biết tất cả các thừa số nguyên tố của $\varphi(m)$, ta có thể dễ dàng
kiểm tra một số có phải căn nguyên thủy modulo $m$ hay không.

???+ note "Định lí"
    Với số nguyên $m\ge 3$ và $g\perp m$, $g$ là căn nguyên thủy modulo $m$ khi
    và chỉ khi với mọi thừa số nguyên tố $p$ của $\varphi(m)$, ta đều có

    $$
    g^{\frac{\varphi(m)}{p}}\not\equiv 1 \pmod m.
    $$

??? note "Chứng minh"
    Chiều cần là hiển nhiên. Để chứng minh chiều đủ, ta dùng phản chứng. Nếu
    $g$ không phải là căn nguyên thủy modulo $m$, thì chắc chắn
    $\delta_m(g)< \varphi(m)$. Theo [Tính chất 2](#ord-prop-2) và định lí
    Euler, $\delta_m(g)\mid\varphi(m)$. Do đó, lấy $p$ là một thừa số nguyên tố
    của $\dfrac{\varphi(m)}{\delta_m(g)}$, ta có
    $\delta_m(g)\mid\dfrac{\varphi(m)}{p}$. Áp dụng lại Tính chất 2, suy ra

    $$
    g^{\frac{\varphi(m)}{p}} \equiv 1 \pmod m.
    $$

    Nhưng $p$ cũng là một ước của $\varphi(m)$, mâu thuẫn với giả thiết. Vì vậy
    chiều đủ của mệnh đề được chứng minh.

<span id="&#x539F;&#x6839;&#x4E2A;&#x6570;"></span>

### Số lượng căn nguyên thủy

Căn nguyên thủy nếu tồn tại thì cũng không nhất thiết duy nhất. Tổng quát hơn,
với các bậc có thể có của mỗi phần tử trong hệ thặng dư thu gọn modulo $m$ và
số phần tử có một bậc nào đó, ta có kết luận sau:

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

<span id="&#x539F;&#x6839;&#x5B58;&#x5728;&#x5B9A;&#x7406;"></span>

### Dinh ly ton tai can nguyen thuy

Muc nay se thiet lap dinh ly ton tai can nguyen thuy sau:

???+ note "Dinh ly"
    Can nguyen thuy modulo $m$ ton tai khi va chi khi $m=1,2,4,p^e,2p^e$, trong do $p$ la so nguyen to le va $e\in\mathbf N_+$.

De chung minh ket luan nay, can lan luot xet bon truong hop sau:

1.  $m=1,2,4$, cac can nguyen thuy lan luot la $g=0,1,3$, hien nhien ton tai.

2.  $m=p^{e}$ la luy thua cua mot so nguyen to le, trong do $p$ la so nguyen to le va $e\in\mathbf N_+$.

    ???+ note "Bo de 1"
        Voi so nguyen to le $p$, can nguyen thuy modulo $p$ ton tai.

    ??? note "Chung minh"
        Chung minh chia thanh hai buoc.
        
        **Buoc 1**: Voi $d\mid(p-1)$, phuong trinh dong du $x^d\equiv 1\pmod p$ co dung $d$ nghiem doi mot khac nhau.
        
        Dat $p-1=kd$, xet da thuc
        
        $$
        f(x) = x^{d(k-1)} + x^{d(k-2)} + \cdots + x^d + 1. 
        $$
        
        Theo [dinh ly Euler](./fermat.md#%E6%AC%A7%E6%8B%89%E5%AE%9A%E7%90%86), phuong trinh dong du $(x^d-1)f(x)=x^{p-1}-1\equiv 0\pmod{p}$ co dung $p-1$ nghiem doi mot khac nhau. Cac nghiem nay lan luot la nghiem cua $x^d-1$ va $f(x)$. Theo [dinh ly Lagrange](./congruence-equation.md#%E5%AE%9A%E7%90%86-3lagrange-%E5%AE%9A%E7%90%86), chung lan luot co nhieu nhat $d$ va $d(k-1)$ nghiem doi mot khac nhau. Vi $d+d(k-1)=p-1$, truong hop dau chi co the co dung $d$ nghiem doi mot khac nhau. Dieu nay chung minh phuong trinh dong du $x^d\equiv 1\pmod p$ co dung $d$ nghiem doi mot khac nhau.
        
        **Buoc 2**: Voi $d\mid(p-1)$, so phan tu bac $d$ dung bang $\varphi(d)$.
        
        Sap xep tat ca cac uoc cua $\varphi(p)$, roi dung quy nap. Vi phan tu bac $1$ chi co the la $1$, nen co dung mot phan tu va co so quy nap dung. Voi $d\mid(p-1)$, theo [Tinh chat 2](#ord-prop-2) o tren, moi nghiem cua phuong trinh dong du $x^d\equiv 1\pmod p$ deu thoa man $\delta_p(x)\mid d$. Do do, so phan tu bac $d$ trong do la
        
        $$
        N(d) = d - \sum_{e\mid d,~e\neq d} N(e) =  d - \sum_{e\mid d,~e\neq d} \varphi(e) = \varphi(d).
        $$
        
        Dau bang thu hai dung theo gia thiet quy nap, dau bang thu ba la tinh chat cua ham Euler. Theo quy nap toan hoc, voi moi $d\mid(p-1)$ deu co dung $\varphi(d)$ phan tu bac $d$.
        
        Dac biet, voi $d=p-1$, co dung $\varphi(p-1)$ phan tu bac $(p-1)$. Vi vay can nguyen thuy modulo $p$ ton tai.

    ???+ note "Bo de 2"
        Voi so nguyen to le $p$ va $e \in \mathbf{N}_+$, can nguyen thuy modulo $p^e$ ton tai.

    ??? note "Chung minh"
        Chung minh chia thanh ba buoc.
        
        **Buoc 1**: Ton tai can nguyen thuy $g$ modulo $p$ sao cho $g^{p-1}\not\equiv 1\pmod{p^2}$.
        
        Lay tuy y mot can nguyen thuy $g$ modulo $p$. Neu no khong thoa man dieu kien, tuc la $g^{p-1}\equiv 1\pmod{p^2}$, thi co the chung minh $g+p$ thoa man dieu kien: $g+p$ cung la can nguyen thuy modulo $p$, va
        
        $$
        \begin{aligned}
        (g+p)^{p-1} &\equiv \binom{p-1}{0}g^{p-1} + \binom{p-1}{1}g^{p-2}p \\
        &= g^{p-1} + g^{p-2}p(p-1) \\ 
        &\equiv 1 - pg^{p-2} \not\equiv 1 \pmod{p^2}.
        \end{aligned}
        $$
        
        **Buoc 2**: Voi $g$ da chon o tren, voi moi $e\ge 1$ deu co $g^{\varphi(p^e)}\not\equiv 1\pmod{p^{e+1}}$.
        
        Cach chon $g$ bao dam bieu thuc nay dung khi $e=1$. Gia su bieu thuc dung voi truong hop $e$, ta chung minh no cung dung voi truong hop $e+1$. Voi moi $e \ge 1$, theo dinh ly Euler ton tai $\lambda$ sao cho
        
        $$
        g^{\varphi(p^e)} = 1 + \lambda p^e
        $$
        
        dung. Theo gia thiet quy nap, $\lambda\perp p$. Vi $\varphi(p^{e+1})=p\varphi(p^e)$, nen
        
        $$
        g^{\varphi(p^{e+1})} = \left(g^{\varphi(p^{e})}\right)^p = (1 + \lambda p^e)^p \equiv 1 + \lambda p^{e+1} \pmod{p^{e+2}}.
        $$
        
        Ket hop voi $\lambda\perp p$, ta duoc $g^{\varphi(p^{e+1})}\not\equiv 1\pmod{p^{e+2}}$. Theo quy nap toan hoc, menh de dung.
        
        **Buoc 3**: Voi $g$ da chon o tren, voi moi $e\ge 1$, $g$ deu la can nguyen thuy modulo $p^e$.
        
        Cach chon $g$ bao dam menh de dung khi $e=1$. Gia su menh de dung voi $e$, ta chung minh no dung voi $e+1$. Viet gon $\delta_{p^{e+1}}(g)$ la $\delta$. Vi $g^\delta\equiv 1\pmod{p^{e+1}}$, tat yeu cung co $g^\delta\equiv 1\pmod{p^e}$. Theo gia thiet quy nap, $\delta_{p^e}(g) = \varphi(p^e)$. Do do, theo [Tinh chat 2](#ord-prop-2) ve bac o tren, $\varphi(p^e)\mid\delta$. Lai theo dinh ly Euler, $\delta\mid\varphi(p^{e+1})$. Nhung $\varphi(p^{e+1})=p\varphi(p^e)$. Vi vay chi co hai kha nang: $\delta=\varphi(p^e)$ hoac $\delta=\varphi(p^{e+1})$. Tuy nhien, ket luan o buoc 2 cho thay $g^{\varphi(p^e)}\not\equiv 1\pmod{p^{e+1}}$. Do do kha nang $\delta=\varphi(p^e)$ khong dung. Kha nang duy nhat la $\delta=\varphi(p^{e+1})$. Dieu nay chung minh $g$ la can nguyen thuy modulo $p^{e+1}$. Theo quy nap toan hoc, menh de dung voi moi $e\ge 1$.

3.  $m=2p^{e}$, trong do $p$ la so nguyen to le va $e\in\mathbf N_+$.

    ???+ note "Bo de 3"
        Voi so nguyen to le $p$ va $e \in \mathbf{N}_+$, can nguyen thuy modulo $2p^e$ ton tai.

    ??? note "Chung minh"
        Gia su $g$ la can nguyen thuy modulo $p^{e}$, khi do $g+p^e$ cung la can nguyen thuy modulo $p^{e}$. Trong hai so nay chac chan co mot so le; khong mat tinh tong quat, gia su do la $g$. Hien nhien $(g,2p^e)=1$. Dat $\delta=\delta_{2p^e}(g)$, can chung minh $\delta=\varphi(2p^e)$. Theo dinh ly Euler, $\delta\mid\varphi(2p^e)$. Dong thoi, theo dinh nghia $g^\delta\equiv 1\pmod{2p^e}$, nen $g^\delta\equiv 1\pmod{p^e}$. Do do, theo [Tinh chat 2](#ord-prop-2) ve bac va cach chon $g$, ta co $\delta_{p^e}(g)=\varphi(p^e)\mid \delta$. Theo cong thuc ham Euler, $\varphi(2p^e) = \varphi(p^e)$. Vi vay $\delta=\delta_{2p^e}(g)=\varphi(p^e)$. Dieu nay chung minh $g$ la can nguyen thuy modulo $2p^e$.

4.  $m\ne 1,2,4,p^{e},2p^{e}$, trong do $p$ la so nguyen to le va $e\in\mathbf N_+$.

    <a id="prim-root-lem-4"></a>

    ???+ note "Bo de 4"
        Gia su $m\neq 1,2,4$ va khong ton tai so nguyen to le $p$ cung so nguyen duong $e$ sao cho $m=p^e$ hoac $m=2p^e$. Khi do can nguyen thuy modulo $m$ khong ton tai.

    ??? note "Chung minh"
        Voi $m=2^e$ va $e\ge 3$, gia su can nguyen thuy $g$ modulo $m$ ton tai. Vi $g\perp m$, no phai la so le. Gia su $g=2k+1$ voi $k\in\mathbf N$, khi do
        
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
        
        O dong gan cuoi, vi $k$ va $(2^{e-2}-1)k^2$ co cung tinh chan le, tong cua chung la so chan. Theo dinh nghia bac, $\delta_{2^{e}}(g)\le 2^{e-2}< \varphi(2^{e}) = 2^{e-1}$. Dieu nay mau thuan voi gia thiet $g$ la can nguyen thuy. Theo phan chung, can nguyen thuy nhu vay khong ton tai.
        
        Gia su $m$ thoa man cac dieu kien da neu va khong phai luy thua cua $2$. Khi do chac chan ton tai $2 < m_1 < m_2$ va $m_1\perp m_2$ sao cho $m=m_1m_2$. Gia su can nguyen thuy $g$ modulo $m$ ton tai. Vi $g\perp m$, nen voi $i=1,2$ deu co $g\perp m_i$. Theo dinh ly Euler,
        
        $$
        g^{\varphi(m_i)} \equiv 1 \pmod{m_i}.
        $$
        
        Vi $m_i > 2$, $\varphi(m_i)$ la so chan, nen voi $i=1,2$ ta co
        
        $$
        g^{\frac{1}{2}\varphi(m_1)\varphi(m_2)} \equiv 1 \pmod{m_i}.
        $$
        
        Theo [dinh ly thang du Trung Hoa](./crt.md), suy ra
        
        $$
        g^{\frac{1}{2}\varphi(m_1)\varphi(m_2)} \equiv 1 \pmod{m}.
        $$
        
        Lai vi $\varphi(m)=\varphi(m_1)\varphi(m_2)$, theo dinh nghia bac ta co
        
        $$
        \delta_m(g) \le \frac{1}{2}\varphi(m_1)\varphi(m_2) = \dfrac{1}{2}\varphi(m) < \varphi(m).
        $$
        
        Dieu nay mau thuan voi gia thiet $g$ la can nguyen thuy modulo $m$. Vi vay, theo phan chung, can nguyen thuy modulo $m$ khong ton tai.

Tong hop bon bo de tren, ta da dua ra dieu kien can va du de mot so co can nguyen thuy.

<span id="&#x6C42;&#x539F;&#x6839;&#x7684;&#x7B97;&#x6CD5;"></span>

### Thuat toan tim can nguyen thuy

Voi bat ky modulo $m$ nao co can nguyen thuy, de tim mot can nguyen thuy $g$, chi can liet ke cac so nguyen duong co the va lan luot kiem tra chung co phai can nguyen thuy hay khong. Khi liet ke, thuong co hai cach xu ly: liet ke tu nho den lon, hoac sinh ngau nhien mot so so nguyen duong. Hieu qua thuc te cua hai cach nay tuong duong nhau.

Khi liet ke tu nho den lon, ta thu duoc can nguyen thuy nho nhat $g_m$ modulo $m$; do do do phuc tap cua phan liet ke phu thuoc vao kich thuoc cua $g_m$. Ve diem nay, co cac uoc luong sau:

-   Uoc luong can tren: Wang Yuan[^yuan1959note] va Burgess[^burgess1962character] chung minh rang can nguyen thuy nho nhat cua so nguyen to $p$ thoa man $g_p=O\left(p^{0.25+\epsilon}\right)$, trong do $\epsilon>0$. Cohen, Odoni, and Stothers[^cohen1974least] va Elliott and Murata[^elliott1998least] lan luot chung minh uoc luong nay cung dung cho modulo $p^2$ va $2p^2$, trong do $p$ la so nguyen to le. Vi voi $e>2$, can nguyen thuy modulo $p^2$ (hoac $2p^2$) cung la can nguyen thuy modulo $p^e$ (hoac $2p^e$), nen can tren $O\left(p^{0.25+\epsilon}\right)$ cua can nguyen thuy nho nhat dung cho moi truong hop.
-   Uoc luong can duoi: Fridlander[^fridlender1949least] va Salie[^salie1949kleinsten] chung minh rang ton tai $C>0$ sao cho voi vo han so nguyen to $p$, can nguyen thuy nho nhat thoa man $g_p > C\log p$.
-   Uoc luong trong truong hop trung binh: Burgess and Elliott[^burgess1968average] chung minh rang trong truong hop trung binh, can nguyen thuy nho nhat cua so nguyen to $p$ thoa man $g_p=O((\log p)^2(\log\log p)^4)$. Elliott and Murata[^elliott1997average] tiep tuc du doan gia tri trung binh cua can nguyen thuy nho nhat cua so nguyen to $p$ la mot hang so, va qua kiem chung so[^more-evidence] thu duoc gia tri xap xi $4.926$. Sau do, Elliott and Murata[^elliott1998least] mo rong du doan nay sang truong hop modulo $2p^2$.

Theo cac phan tich nay, khi tim can nguyen thuy nho nhat bang vét can, do phuc tap $O(g_m(\log m)^2)$ cua phan liet ke la chap nhan duoc.

Ngoai viec liet ke tu nho den lon, ta con co the tim can nguyen thuy bang cach sinh ngau nhien cac so nguyen duong roi kiem tra. Mat do can nguyen thuy khong thap:[^density-prim-root]

$$
\dfrac{\varphi(\varphi(m))}{m} = \Omega\left(\dfrac{1}{\log\log m}\right).
$$

Vi vay, khi tim can nguyen thuy bang phuong phap ngau nhien, do phuc tap ky vong cua phan liet ke la $O((\log m)^2\log\log m)$.

Can luu y rang khi kiem tra can nguyen thuy, ta can biet phan tich thua so nguyen to cua $\varphi(m)$. Trong cac [thuat toan phan tich thua so nguyen to thuong dung](./pollard-rho.md) trong lap trinh thi dau, thuat toan Pollard Rho co do phuc tap toi uu cung can thoi gian $O(m^{1/4+\varepsilon})$. Vi vay, chi can phan tich thua so nguyen to cua $\varphi(m)$ chua biet, bat ke dung cach liet ke nao, nut that do phuc tap cua viec tim can nguyen thuy nam o buoc phan tich thua so nguyen to, chu khong phai phan liet ke va kiem tra.

<span id="carmichael-&#x51FD;&#x6570;"></span>

## Ham Carmichael

So voi khai niem cuc bo la bac cua mot phan tu modulo $m$, ham Carmichael la mot khai niem toan cuc. No la chu ky chung nho nhat cua luy thua cua tat ca cac so nguyen nguyen to cung nhau voi $m$.

???+ abstract "Ham Carmichael"
    Voi $m\in\mathbf N_+$, dinh nghia $\lambda(m)$ la so nguyen duong nho nhat $n$ sao cho dong du $a^n\equiv 1\pmod m$ dung voi moi $a\perp m$. Ham $\lambda:\mathbf N_+\to\mathbf N_+$ duoc goi la **ham Carmichael**.

Theo [Tinh chat 2](#ord-prop-2), viec $a^n\equiv 1\pmod m$ dung voi moi $a\perp m$ co nghia la $\delta_m(a)\mid n$ voi moi $a\perp m$. Noi cach khac, so nguyen duong $n$ thoa man dieu kien nay nhat dinh la boi chung cua tat ca cac $\delta_m(a)$. Do do, so $n$ nho nhat nhu vay chinh la boi chung nho nhat cua chung:

$$
\lambda(m) = \operatorname{lcm}\{\delta_m(a) : a\perp m\}.
$$

Day cung thuong duoc dung lam dinh nghia tuong duong cua ham Carmichael.

Ap dung lap lai [Tinh chat 5](#ord-prop-5), ta biet chac chan ton tai mot phan tu $a\perp m$ sao cho $\delta_m(a)=\lambda(m)$. Do do cong thuc tren cung co the viet thanh

$$
\lambda(m) = \max\{\delta_m(a) : a\perp m\}.
$$

Phan tu $a\perp m$ dat gia tri lon nhat nay cung duoc goi la **$\lambda$-can nguyen thuy** modulo $m$. No ton tai voi moi modulo $m$.

<span id="&#x9012;&#x63A8;&#x516C;&#x5F0F;"></span>

### Cong thuc truy hoi

Ham Carmichael la mot [ham so hoc](./basic.md#%E6%95%B0%E8%AE%BA%E5%87%BD%E6%95%B0). Muc nay thao luan mot cong thuc truy hoi cua no, tu do dua ra mot chung minh khac cho dinh ly ton tai can nguyen thuy.

Tuy khong phai ham nhan tinh, khi tinh ham Carmichael ta van co the xu ly rieng cac thua so nguyen to cung nhau.

???+ note "Bo de"
    Voi hai so nguyen duong nguyen to cung nhau $m_1,m_2$, ta co $\lambda(m_1m_2)=[\lambda(m_1),\lambda(m_2)]$.

??? note "Chung minh"
    Gia su $a_1$ va $a_2$ lan luot la $\lambda$-can nguyen thuy modulo $m_1$ va modulo $m_2$. Dat $m=m_1m_2$. Theo [dinh ly thang du Trung Hoa](./crt.md), ton tai $a\perp m$ sao cho $a\equiv a_i\pmod{m_i}$ voi $i=1,2$. Vi $a^{\lambda(m)}\equiv 1\pmod m$, nen voi $i=1,2$ deu co $a_i^{\lambda(m)} \equiv 1\pmod{m_i}$. Tu do theo [Tinh chat 2](#ord-prop-2) va cach chon $a_i$, ta co $\lambda(m_i)=\delta_{m_i}(a_i)\mid \lambda(m)$. Dieu nay chung minh $[\lambda(m_1),\lambda(m_2)]\mid\lambda(m)$.
    
    Nguoc lai, voi moi $a\perp m$ va $i=1,2$, ta deu co $a^{[\lambda(m_1),\lambda(m_2)]} \equiv 1 \pmod{m_i}$. Ap dung dinh ly thang du Trung Hoa, ta duoc $a^{[\lambda(m_1),\lambda(m_2)]} \equiv 1 \pmod{m}$ voi moi $a\perp m$. Theo dinh nghia ham Carmichael, $\lambda(m)\mid [\lambda(m_1),\lambda(m_2)]$.
    
    Do do dang bang trong menh de dung.

Vi vay, tiep theo chi can tinh gia tri cua ham Carmichael tai cac luy thua nguyen to. Truoc het, xu ly truong hop luy thua cua $2$.

???+ note "Bo de"
    Voi $m=2^e$ va $e\in\mathbf N_+$, ta co $\lambda(2)=1$, $\lambda(4)=2$, va voi moi $e\ge 3$ deu co $\lambda(m)=2^{e-2}$.

??? note "Chung minh"
    Truong hop $m=2,4$ co the xet rieng. Voi $m=2^e$ va $e\ge 3$, truoc het lap lai phan dau trong chung minh [Bo de 4](#prim-root-lem-4) o tren, ta duoc $\lambda(m)\le 2^{e-2}$. Tiep theo, chi can chung minh ton tai phan tu bac $2^{e-2}$. De lam viec nay, co
    
    $$
    5^{2^{e-3}} = (1 + 2^2)^{2^{e-3}} = 1 + 2^2\times 2^{e-3} = 1 + 2^{e-1} \not\equiv 1 \pmod{2^e}.
    $$
    
    Dieu nay cho thay $\delta_m(5)\nmid 2^{e-3}$, lai vi $\delta_m(5) \mid 2^{e-2}$, nen $5$ chi co the la phan tu bac $2^{e-2}$. Do do $\lambda(m)=2^{e-2}$.

Trong qua trinh chung minh bo de nay, thuc ra ta da thu duoc mo ta ve cau truc cua he thang du thu gon modulo $2^e$:

<a id="mod-pow-2"></a>

???+ note "He qua"
    Gia su modulo la $2^e$ va $e \ge 2$. Khi do moi so le deu dong du voi dung mot so nguyen co dang $\pm 5^k$, trong do $k\in\mathbf N$ va $k < 2^{e-2}$. Noi cach khac, $\pm 1,\pm 5,\cdots,\pm 5^{2^{e-2}-1}$ doi mot khong dong du, va tao thanh mot he thang du thu gon.

??? note "Chung minh"
    De dang kiem tra truong hop $e=2$ dung. Voi $e \ge 3$, trong chung minh o tren ta da co bac cua $5$ modulo $2^e$ la $2^{e-2}$, nen $1,5,\cdots,5^{2^{e-2}-1}$ doi mot khong dong du. Vi cac so nguyen nay deu du $1$ modulo $4$, con cac so doi cua chung deu du $3$ modulo $4$, nen $\pm 1,\pm 5,\cdots,\pm 5^{2^{e-2}-1}$ doi mot khong dong du modulo $2^e$. Vi tong cong co $2^{e-1}$ so, dung bang kich thuoc cua he thang du thu gon modulo $2^{e}$, chung tao thanh chinh he thang du thu gon.

Sau do, xu ly truong hop luy thua cua so nguyen to le.

???+ note "Bo de"
    Voi $m=p^e$, trong do $p$ la so nguyen to le va $e\in\mathbf N_+$, ta co $\lambda(m)=p^{e-1}(p-1)$.

??? note "Chung minh"
    Truoc het chung minh menh de dung voi $e=1$, tuc $m=p$ la so nguyen to le. Theo dinh nghia ham Carmichael, moi so nguyen $a$ nguyen to cung nhau voi $p$ deu la nghiem cua phuong trinh dong du $x^{\lambda(p)}\equiv 1\pmod{p}$. Theo nghia modulo $p$, phuong trinh nay co tong cong $p-1$ nghiem doi mot khac nhau. Theo [dinh ly Lagrange](./congruence-equation.md#%E5%AE%9A%E7%90%86-3lagrange-%E5%AE%9A%E7%90%86), ta co $p-1\le\lambda(p)$. Dong thoi, dinh ly Euler yeu cau $\lambda(p)\mid\varphi(p)=p-1$. Do do $\lambda(p)=p-1$.
    
    Voi $m=p^e$ va $e> 1$, co the bat dau bang viec chung minh $1+p$ la phan tu bac $p^{e-1}$. Thuc vay,
    
    $$
    (1+p)^{p^{e-1}} \equiv 1,\quad (1+p)^{p^{e-2}} \equiv 1 + p^{e-1} \not\equiv 1 \pmod{p^e}.
    $$
    
    Nen $\delta_m(1+p)=p^{e-1}$. Ngoai ra, gia su $g$ la can nguyen thuy modulo $p$. Khi do, vi $g^{\delta_m(g)}\equiv 1 \pmod{p}$, theo [Tinh chat 2](#ord-prop-2) ve bac, ta co $p-1\mid\delta_m(g)$. Theo dinh nghia ham Carmichael va dinh ly Euler,
    
    $$
    p^{e-1}(p-1) = [\delta_m(g),p^{e-1}]\mid\lambda(m) \mid \varphi(m) = p^{e-1}(p-1).
    $$
    
    Do do $\lambda(m)=p^{e-1}(p-1)$.

Tom tat cac ket qua cua muc nay, ta thu duoc cong thuc truy hoi cua ham Carmichael:

???+ note "Dinh ly"
    Voi moi so nguyen duong $m$, ta co
    
    $$
    \lambda(m) = \begin{cases}
    \varphi(m), & \text{if }m=1,2,4,p^e\text{ for odd prime }p\text{ and }e \ge 1,\\
    \frac{1}{2}\varphi(m), &\text{if }m=2^e,~e\ge 3,\\
    \operatorname{lcm}\{\lambda(p_1^{e_1}),\lambda(p_2^{e_2}),\cdots,\lambda(p_s^{e_s})\}, &\text{if }m = p_1^{e_1}p_2^{e_2}\cdots p_s^{e_s}\text{ for distinct }p_1,p_2,\cdots,p_s.
    \end{cases}
    $$

Dung cong thuc truy hoi nay co the lam manh ket qua phia tren:

???+ note "He qua"
    Voi cac so nguyen duong $m_1,m_2$, ta co $\lambda([m_1,m_2])=[\lambda(m_1),\lambda(m_2)]$.

So sanh dinh nghia can nguyen thuy va ham Carmichael, ta thay can nguyen thuy modulo $m$ ton tai khi va chi khi $\lambda(m)=\varphi(m)$. Tu cong thuc truy hoi cua ham Carmichael, de dang quy nap ra ket qua sau:

???+ note "He qua"
    Can nguyen thuy modulo $m$ ton tai khi va chi khi $m=1,2,4,p^e,2p^e$, trong do $p$ la so nguyen to le va $e\in\mathbf N_+$.

Vi chung minh cong thuc truy hoi trong muc nay khong dung den dinh ly ton tai can nguyen thuy, day tao thanh mot chung minh khac cho dinh ly do.

<span id="carmichael-&#x6570;"></span>

### So Carmichael

Dung ham Carmichael, ta co the thao luan tinh chat va phan bo cua so Carmichael (OEIS:[A002997](https://oeis.org/A002997)). Day la cac hop so ma [kiem tra tinh nguyen to Fermat](./prime.md#fermat-%E7%B4%A0%E6%80%A7%E6%B5%8B%E8%AF%95) chac chan khong the loai bo chinh xac.

???+ abstract "So Carmichael"
    Voi hop so $n$, neu voi moi so nguyen $a\perp n$ deu co dong du $a^{n-1} \equiv 1 \pmod n$, thi $n$ duoc goi la **so Carmichael**.

So Carmichael nho nhat la $561 = 3 \times 11 \times 17$.

Theo dinh nghia ham Carmichael, hop so $n$ la so Carmichael khi va chi khi $\lambda(n)\mid n-1$, trong do $\lambda(n)$ la ham Carmichael. Hon nua, ta co phuong phap sau de xac dinh hop so $n$ co phai so Carmichael hay khong:

???+ note "Tieu chuan Korselt[^korselt1899probleme]"
    Hop so $n$ la so Carmichael khi va chi khi $n$ khong co thua so chinh phuong va voi moi thua so nguyen to $p$ cua $n$ deu co $(p-1) \mid (n-1)$.

??? note "Chung minh"
    Truoc het chung minh tinh can thiet. Gia su $\lambda(n)\mid (n-1)$. Kiem tra cong thuc truy hoi cua ham Carmichael, neu $n$ co thua so chinh phuong $p$, thi chac chan $p\mid \lambda(n)$. Nhung $p\nmid (n-1)$, mau thuan. Tuong tu, cong thuc truy hoi cua ham Carmichael cho thay $(p-1)\mid \lambda(n)$, nen cung co $(p-1) \mid (n-1)$.
    
    Tiep theo chung minh tinh du. Vi $n$ la hop so, no chac chan co thua so nguyen to le $p$, do do $n-1$ la so chan, va $n$ cung chac chan la so le. Voi hop so le khong co thua so chinh phuong $n$, theo cong thuc truy hoi cua ham Carmichael, $\lambda(n)=\operatorname{lcm}\{p-1:p\mid n\}$. Vi vay, chi can $(p-1) \mid (n-1)$ dung voi moi thua so nguyen to $p$, thi chac chan $\lambda(n)\mid (n-1)$.

Tu tieu chuan nay, co the thiet lap mot so tinh chat don gian cua so Carmichael:

???+ note "He qua"
    So Carmichael la so le, khong co thua so chinh phuong, va co it nhat $3$ thua so nguyen to phan biet.

??? note "Chung minh"
    Hai tinh chat dau co the suy truc tiep tu tieu chuan Korselt va chung minh cua no. De thu duoc tinh chat thu ba, chi can chung minh them: tich $n=p_1p_2$ cua hai so nguyen to phan biet $p_1,p_2$ chac chan khong phai so Carmichael. Gia su $n=p_1p_2$ la so Carmichael. Theo tieu chuan Korselt, $(p_i-1)\mid (n-1)$. Nhung ta co
    
    $$
    n-1=p_1p_2-1\equiv p_2-1 \pmod{p_1-1}.
    $$
    
    Do do $(p_1-1)\mid(p_2-1)$. Tuong tu, $(p_2-1)\mid(p_1-1)$. Nghia la $p_1=p_2$. Dieu nay mau thuan voi gia thiet. Vi vay so Carmichael $n$ co it nhat $3$ thua so nguyen to phan biet.

Dung so hoc giai tich, ta con co the thu duoc mot so tinh chat ve phan bo cua so Carmichael. Goi $C(n)$ la so luong so Carmichael khong vuot qua $n$. Alford, Granville, and Pomerance[^alford1994infinitely] chung minh rang voi $n$ du lon, ta co $C(n)>n^{2/7}$. Tu do, co vo han so Carmichael. Truoc do, Erdos[^erdos1956pseudoprimes] da chung minh $C(n) < n\exp\left(-c\dfrac{\ln n\ln\ln\ln n}{\ln\ln n}\right)$, trong do $c$ la hang so. Vi vay phan bo cua so Carmichael rat thua (so voi so nguyen to). Thuc te, co[^pinchcarmichael] $C(10^9)=646$, $C(10^{18})=1~401~644$.

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x6CE8;&#x91CA;"></span>

## Tai lieu tham khao va ghi chu

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

[^more-evidence]: Co the xem them cac ket qua tai [Least prime primitive root of prime numbers](https://sweet.ua.pt/tos/p_roots.html).

[^density-prim-root]: Neu can nguyen thuy modulo $m$ ton tai, thi $\varphi(m)\ge\dfrac{1}{3}m$, va dau bang chi dat tai $m=2\times 3^e~(e\in\mathbf N_+)$. Hon nua, khi $m > 2$, co uoc luong cho ham Euler $\varphi(m)$: $\varphi(m)>\dfrac{m}{e^{\gamma}\log\log m+\frac{3}{\log\log m}}$. Ket hop hai ket qua nay, ta thu duoc bieu thuc trong bai. Ve uoc luong nay cua ham Euler, co the tham khao bai bao Rosser, J. Barkley, and Lowell Schoenfeld. "Approximate formulas for some functions of prime numbers." Illinois Journal of Mathematics 6, no. 1 (1962): 64-94.

[^korselt1899probleme]: Korselt, A. R. (1899). "Probleme chinois." L'Intermediaire des Mathematiciens. 6: 142-143.

[^alford1994infinitely]: W. R. Alford; Andrew Granville; Carl Pomerance (1994). "There are Infinitely Many Carmichael Numbers." Annals of Mathematics. 140 (3): 703-722.

[^erdos1956pseudoprimes]: Erdos, P. (1956). "On pseudoprimes and Carmichael numbers." Publ. Math. Debrecen. 4 (3-4): 201-206.

[^pinchcarmichael]: PINCH, Richard GE. The Carmichael numbers up to ${10}^{20}$.
