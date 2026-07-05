author: hly1204, ShaoChenHeng, Chrogeek, Enter-tainer, Great-designer, iamtwz, monkeysui, nanmenyangde, rgw2010, sshwy, StudyingFather, TachikakaMin, Tiphereth-A, Xeonacid, xyf007, marscheng1

<span id="mở-đầu"></span>
## Mở đầu

Có thể xem thặng dư bậc hai là việc bàn về tính khả thi của phép **khai căn bậc hai** trong nghĩa modulo. Với khai căn bậc cao hơn, xem [thặng dư bậc $k$](./residue.md).

<span id="định-nghĩa"></span>
## Định nghĩa

???+ abstract "Thặng dư bậc hai"
    Cho các số nguyên $a$, $p$ thỏa $(a,p)=1$. Nếu tồn tại số nguyên $x$ sao cho
    
    $$
    x^2\equiv a\pmod p,
    $$
    
    thì $a$ được gọi là thặng dư bậc hai modulo $p$; ngược lại, $a$ được gọi là bất thặng dư bậc hai modulo $p$. Khi modulo $p$ đã rõ, phần sau có thể viết ngắn gọn là thặng dư/bất thặng dư bậc hai.

<span id="tiêu-chuẩn-euler"></span>
## Tiêu chuẩn Euler

Khi modulo là số nguyên tố lẻ, ta có định lý sau:

???+ abstract "Tiêu chuẩn Euler"
    Với số nguyên tố lẻ $p$ và số nguyên $a$ thỏa $(a,p)=1$, ta có
    
    $$
    a^{\frac{p-1}{2}}\equiv\begin{cases}
        1 \pmod p,  & (\exists x\in\mathbf{Z}),~~a\equiv x^2\pmod p,\\
        -1 \pmod p, & \text{otherwise}.
    \end{cases}
    $$
    
    Tức với $p$ và $a$ như trên,
    
    1.  $a$ là thặng dư bậc hai modulo $p$ khi và chỉ khi $a^{\frac{p-1}{2}}\equiv 1 \pmod p$.
    2.  $a$ là bất thặng dư bậc hai modulo $p$ khi và chỉ khi $a^{\frac{p-1}{2}}\equiv -1 \pmod p$.

??? note "Chứng minh"
    Trước hết, từ [định lý nhỏ Fermat](./fermat.md#định-lý-nhỏ-fermat) ta có $a^{p-1}\equiv 1\pmod p$, nên
    
    $$
    \left(a^{\frac{p-1}{2}}+1\right)\left(a^{\frac{p-1}{2}}-1\right)\equiv 0\pmod p,
    $$
    
    do đó với mọi $a$ thỏa $(a,p)=1$ đều có $a^{(p-1)/2}\equiv \pm 1\pmod p.$
    
    Mặt khác, vì $p$ là số nguyên tố lẻ, ta có:
    
    $$
    x^{p-1}-a^{\frac{p-1}{2}}={\left(x^2\right)}^{\frac{p-1}{2}}-a^{\frac{p-1}{2}}=(x^2-a)P(x),
    $$
    
    trong đó $P(x)$ là một đa thức hệ số nguyên nào đó. Suy ra:
    
    $$
    \begin{aligned}
        x^p-x&=x\left(x^{p-1}-a^{\frac{p-1}{2}}\right)+x\left(a^{\frac{p-1}{2}}-1\right)\\
        &=(x^2-a)xP(x)+\left(a^{\frac{p-1}{2}}-1\right)x.
    \end{aligned}
    $$
    
    Theo [Định lý 5 về phương trình đồng dư](./congruence-equation.md#định-lý-5), $a$ là thặng dư bậc hai modulo $p$ khi và chỉ khi $a^{(p-1)/2}\equiv 1\pmod p$. Do đó $a$ là bất thặng dư bậc hai modulo $p$ khi và chỉ khi $a^{(p-1)/2}\equiv -1\pmod p$.

Dựa trên tiêu chuẩn Euler, ta có hệ quả sau:

???+ note "Số lượng thặng dư bậc hai"
    Với số nguyên tố lẻ $p$, trong nghĩa modulo $p$, số thặng dư bậc hai và số bất thặng dư bậc hai đều bằng $\dfrac{p-1}{2}$.

??? note "Chứng minh"
    Theo tiêu chuẩn Euler, xét $a^{\frac{p-1}{2}}\equiv 1\pmod p.$
    
    Chú ý rằng $\dfrac{p-1}{2}\mid (p-1)$. Theo [Định lý 6 về phương trình đồng dư](./congruence-equation.md#định-lý-6), phương trình $a^{\frac{p-1}{2}}\equiv 1\pmod p$ có $\dfrac{p-1}{2}$ nghiệm. Vì vậy trong nghĩa modulo $p$, số thặng dư bậc hai và số bất thặng dư bậc hai đều bằng $\dfrac{p-1}{2}$.

<span id="ký-hiệu-legendre"></span>
## Ký hiệu Legendre

Để thuận tiện cho phần thảo luận tiếp theo, ta đưa vào ký hiệu sau:

???+ abstract "Ký hiệu Legendre"
    Với **số nguyên tố lẻ** $p$ và số nguyên $a$, định nghĩa ký hiệu Legendre như sau:
    
    $$
    \left(\frac{a}{p}\right)=\begin{cases}
        0,  & p\mid a,\\
        1,  & (p\nmid a) \land ((\exists x\in\mathbf{Z}),~~a\equiv x^2\pmod p),\\
        -1, & \text{otherwise}.
    \end{cases}
    $$

Tức với $a$ thỏa $(a,p)=1$,

-   $a$ là thặng dư bậc hai modulo $p$ khi và chỉ khi $\left(\dfrac{a}{p}\right)=1.$
-   $a$ là bất thặng dư bậc hai modulo $p$ khi và chỉ khi $\left(\dfrac{a}{p}\right)=-1.$

Bảng dưới đây liệt kê một phần giá trị của ký hiệu Legendre (theo [Wikipedia](https://en.wikipedia.org/wiki/Legendre_symbol#Table_of_values)).

![](./images/quad_residue.png)

<span id="tính-chất"></span>
### Tính chất

1.  Với mọi số nguyên $a$,

    $$
    a^{\frac{p-1}{2}}\equiv \left(\frac{a}{p}\right)\pmod p.
    $$

    Suy ra:

    -   $$
        \left(\dfrac{1}{p}\right)=1.
        $$
    -   $$
        \left(\dfrac{-1}{p}\right)=(-1)^{\frac{p-1}{2}}=\begin{cases}
            1,  & p\equiv 1\pmod 4,\\
            -1, & p\equiv 3\pmod 4.
            \end{cases}
        $$

2.  $a_1\equiv a_2\pmod p\implies \left(\dfrac{a_1}{p}\right)=\left(\dfrac{a_2}{p}\right).$

3.  ([Tính nhân hoàn toàn](./basic.md#hàm-nhân-tính)) Với mọi số nguyên $a_1,a_2$,

    $$
    \left(\frac{a_1a_2}{p}\right)=\left(\frac{a_1}{p}\right)\left(\frac{a_2}{p}\right).
    $$

    Ta có hệ quả: với các số nguyên $a,b$ và $p\nmid b$,

    $$
    \left(\frac{ab^2}{p}\right)=\left(\frac{a}{p}\right).
    $$

4.  $$
    \left(\frac{2}{p}\right)=(-1)^{\frac{p^2-1}{8}}=\begin{cases}
            1,  & p\equiv \pm 1\pmod 8, \\
            -1, & p\equiv \pm 3\pmod 8. \\
        \end{cases}
    $$

??? note "Chứng minh"
    1.  Suy ra trực tiếp từ [định nghĩa ký hiệu Legendre](#ký-hiệu-legendre) và [tiêu chuẩn Euler](#tiêu-chuẩn-euler).
    2.  Chú ý rằng
    
        $$
        a_1\equiv a_2\pmod p\implies \left(\frac{a_1}{p}\right)\equiv\left(\frac{a_2}{p}\right)\pmod p,
        $$
    
        mà $\left|\left(\dfrac{a_1}{p}\right)-\left(\dfrac{a_2}{p}\right)\right|\leq 2$ và $p>2$, nên:
    
        $$
        a_1\equiv a_2\pmod p\implies \left(\frac{a_1}{p}\right)=\left(\frac{a_2}{p}\right).
        $$
    3.  Từ 1, ta có
    
        $$
        \left(\frac{a_1a_2}{p}\right)\equiv a_1^{\frac{p-1}{2}}a_2^{\frac{p-1}{2}}\equiv\left(\frac{a_1}{p}\right)\left(\frac{a_2}{p}\right)\pmod p.
        $$
    
        Mà $\left|\left(\dfrac{a_1a_2}{p}\right)-\left(\dfrac{a_1}{p}\right)\left(\dfrac{a_2}{p}\right)\right|\leq 2$ và $p>2$, nên
    
        $$
        \left(\frac{a_1a_2}{p}\right)=\left(\frac{a_1}{p}\right)\left(\frac{a_2}{p}\right).
        $$
    4.  Xem [luật thuận nghịch bậc hai](#luật-thuận-nghịch-bậc-hai).

Dựa trên các tính chất trên, nếu tính được giá trị của $\left(\dfrac{p}{q}\right)$ với mọi số nguyên tố lẻ $p$ và $q$, thì ta có thể tính ký hiệu Legendre trong mọi trường hợp hợp lệ. Tiếp theo là một định lý đẹp, thiết lập liên hệ khéo léo giữa $\left(\dfrac{p}{q}\right)$ và $\left(\dfrac{q}{p}\right)$, nhờ đó ta có thể tính theo ý tưởng tương tự [thuật toán Euclid](./gcd.md#thuật-toán-euclid).

<span id="luật-thuận-nghịch-bậc-hai"></span>
### Luật thuận nghịch bậc hai

???+ note "Luật thuận nghịch bậc hai"
    Gọi $p$, $q$ là hai số nguyên tố lẻ khác nhau. Khi đó
    
    $$
    \left(\frac{p}{q}\right)\left(\frac{q}{p}\right)=(-1)^{\frac{p-1}{2}\frac{q-1}{2}}.
    $$

Có nhiều cách chứng minh định lý này[^ref5]. Một cách chứng minh dựa trên bổ đề sau[^ref6]:

???+ note "Bổ đề Gauss"
    Gọi $p$ là số nguyên tố lẻ, $(n,p)=1$. Với số nguyên $k~\left(1\leq k\leq (p-1)/2\right)$, đặt $r_k=nk\bmod p$, và đặt $A=\{r_k:r_k < p/2\}$, $B=\{r_k:r_k > p/2\}$. Khi đó
    
    $$
    \left(\frac{n}{p}\right)=(-1)^{|B|}.
    $$

??? note "Chứng minh"
    Đặt $\lambda=|A|$, $\mu=|B|$. Rõ ràng $\lambda+\mu=(p-1)/2$, nên
    
    $$
    n^{\frac{p-1}{2}}\left(\frac{p-1}{2}\right)!=\prod_{k=1}^{\frac{p-1}{2}} nk\equiv\prod_{a\in A}a\prod_{b\in B}b\pmod{p}.
    $$
    
    Với mọi phần tử $b$ trong $B$, ta có $\dfrac{p}{2} < b < p$, nên $0 < p-b < \dfrac{p}{2}$. Hơn nữa, với mọi $b$ trong $B$, ta có $p-b\notin A$; nếu không, giả sử trong $A,B$ lần lượt có $a,b$ sao cho $a=p-b$, thì tồn tại các số nguyên $0 < k_1,k_2 < (p-1)/2$ sao cho $a=nk_1$, $b=nk_2$ và $p\mid n(k_1+k_2)$. Vì $(n,p)=1$, suy ra $p\mid (k_1+k_2)$; nhưng $0 < k_1+k_2 < p$, mâu thuẫn. Do đó
    
    $$
    n^{\frac{p-1}{2}}\left(\frac{p-1}{2}\right)!\equiv(-1)^{\mu}\prod_{a\in A}a\prod_{b\in B}(p-b)=(-1)^{\mu}\left(\frac{p-1}{2}\right)!\pmod{p},
    $$
    
    tức là
    
    $$
    n^{\frac{p-1}{2}}\equiv(-1)^{\mu}\pmod{p}.
    $$
    
    Từ [tính chất 1](#tính-chất) của ký hiệu Legendre, suy ra điều phải chứng minh.

??? tip "Mở rộng"
    Bổ đề Gauss có thể được mở rộng như sau[^ref7]:
    
    Gọi $p$ là số nguyên tố lẻ. Cho $I\subset\mathbf{Z}_p^*$ thỏa $I\cup -I=\mathbf{Z}_p^*$ và $I\cap -I=\varnothing$, trong đó $-I:=\{-i:i\in I\}$. Khi đó với mọi số nguyên $n$ nguyên tố cùng nhau với $p$,
    
    $$
    \left(\frac{n}{p}\right)=(-1)^{|J|},
    $$
    
    trong đó $J=\{j\in I:nj\in -I\}$.
    
    Dễ thấy lấy $I=\{1,2,\dots,(p-1)/2\}$ sẽ thu được bổ đề Gauss. Cách chứng minh gần giống chứng minh bổ đề Gauss, nên lược bỏ.

Dễ thu được các hệ quả sau:

???+ note "Hệ quả"
    Với số nguyên tố lẻ $p$, ta có
    
    $$
    \left(\frac{2}{p}\right)=(-1)^{\frac{p^2-1}{8}}=\begin{cases}
            1,  & p\equiv \pm 1\pmod 8, \\
            -1, & p\equiv \pm 3\pmod 8. \\
        \end{cases}
    $$
    
    Với số nguyên tố lẻ $p$ và số lẻ $n$ thỏa $(n,p)=1$, ta có
    
    $$
    \left(\frac{n}{p}\right)=(-1)^{\sum_{i=1}^{(p-1)/2}\lfloor ni/p \rfloor}.
    $$

??? note "Chứng minh"
    Với $n,k,r_k,A,B,\lambda,\mu$ trong bổ đề Gauss, ta có $nk=p\left\lfloor\dfrac{nk}{p}\right\rfloor+r_k$, do đó
    
    $$
    \begin{aligned}
        n\cdot\frac{p^2-1}{8}=\sum_{k=1}^{\frac{p-1}{2}}nk&=p\sum_{k=1}^{\frac{p-1}{2}}\left\lfloor\dfrac{nk}{p}\right\rfloor+\sum_{a\in A}a+\sum_{b\in B}b\\
        &=p\sum_{k=1}^{\frac{p-1}{2}}\left\lfloor\dfrac{nk}{p}\right\rfloor+\sum_{a\in A}a+\sum_{b\in B}(p-b)+2\sum_{b\in B}b-p\mu\\
        &=p\sum_{k=1}^{\frac{p-1}{2}}\left\lfloor\dfrac{nk}{p}\right\rfloor+\sum_{k=1}^{\frac{p-1}{2}}k+2\sum_{b\in B}b-p\mu\\
        &=p\sum_{k=1}^{\frac{p-1}{2}}\left\lfloor\dfrac{nk}{p}\right\rfloor+\frac{p^2-1}{8}+2\sum_{b\in B}b-p\mu,
    \end{aligned}
    $$
    
    Vì vậy
    
    $$
    (n-1)\frac{p^2-1}{8}=p\sum_{k=1}^{\frac{p-1}{2}}\left\lfloor\dfrac{nk}{p}\right\rfloor+2\sum_{b\in B}b-p\mu.
    $$
    
    Nếu $n=2$, thì $0 < \dfrac{nk}{p}\leq\dfrac{p-1}{p} < 1$, suy ra
    
    $$
    \frac{p^2-1}{8}\equiv\mu\pmod{2}.
    $$
    
    Nếu $2\nmid n$, thì
    
    $$
    \sum_{k=1}^{\frac{p-1}{2}}\left\lfloor\dfrac{nk}{p}\right\rfloor\equiv\mu\pmod{2}.
    $$

Theo hệ quả trên, để chứng minh luật thuận nghịch bậc hai, chỉ cần kiểm tra

$$
\frac{p-1}{2}\frac{q-1}{2}=\sum_{k=1}^{\frac{p-1}{2}}\left\lfloor\dfrac{qk}{p}\right\rfloor+\sum_{k=1}^{\frac{q-1}{2}}\left\lfloor\dfrac{pk}{q}\right\rfloor.
$$

Xét tập $S$ gồm các điểm $(px,qy)$ với $1\leq x\leq \dfrac{q-1}{2},1\leq y\leq \dfrac{p-1}{2}$. Chia tập này thành hai phần theo quan hệ lớn nhỏ giữa $px$ và $qy$ (rõ ràng $px\neq qy$), rồi kiểm tra kích thước của ba tập tương ứng là đủ.

Luật thuận nghịch bậc hai không chỉ dùng để phán đoán số $n$ có phải là thặng dư bậc hai modulo $p$ hay không, mà còn dùng để xác định cấu trúc của các modulo khiến $n$ là thặng dư bậc hai.

???+ example "Ví dụ"
    -   Các số nguyên tố lẻ $p$ sao cho $5$ là thặng dư bậc hai modulo $p$ thỏa $p\equiv \pm 1\pmod 5.$
    -   Các số nguyên tố lẻ $p$ sao cho $-3$ là thặng dư bậc hai modulo $p$ thỏa $p\equiv 1\pmod 3.$
    -   Các số nguyên tố lẻ $p$ sao cho $-2$ và $3$ đồng thời là thặng dư bậc hai modulo $p$ thỏa $p\equiv 11\pmod{24}.$

Ngoài ra, ta còn có thể chứng minh các kết luận như "có vô hạn số nguyên tố dạng $4k+1$". Loại kết luận này thực ra là hệ quả đơn giản của [định lý Dirichlet](https://en.wikipedia.org/wiki/Dirichlet%27s_theorem_on_arithmetic_progressions).

<span id="ký-hiệu-jacobi"></span>
## Ký hiệu Jacobi

Từ luật thuận nghịch bậc hai, ta có thể nghĩ một cách tự nhiên đến việc mở rộng ký hiệu Legendre:

???+ abstract "Ký hiệu Jacobi"
    Với **số lẻ dương** $m=p_1^{\alpha_1}\dots p_k^{\alpha_k}$ và số nguyên $a$, trong đó $p_1,\dots,p_k$ là các số nguyên tố và $\alpha_1,\dots,\alpha_k$ là các số nguyên dương, định nghĩa ký hiệu Jacobi như sau:
    
    $$
    \left(\frac{a}{m}\right):=\prod_{i=1}^k\left(\frac{a}{p_i}\right)^{\alpha_i}.
    $$
    
    Trong đó $\left(\frac{a}{p_i}\right)$ ở vế phải là [ký hiệu Legendre](#ký-hiệu-legendre). Ngoài ra, với số nguyên $a$ ta có $\left(\dfrac{a}{1}\right)=1.$

???+ warning "Cảnh báo"
    Thông thường ta không phân biệt ký hiệu Legendre và ký hiệu Jacobi, vì từ tính nhân hoàn toàn có thể thấy ký hiệu Jacobi có các tính chất giống ký hiệu Legendre, nên cách tính hai ký hiệu này là như nhau. Tuy nhiên cần chú ý một điểm: khi $m$ **không phải số nguyên tố lẻ**, giá trị $\left(\dfrac{a}{m}\right)$ **không liên quan** đến việc $a$ có là thặng dư bậc hai modulo $m$ hay không. Nhưng nếu $\left(\dfrac{a}{m}\right)=-1$, thì $m$ có ít nhất một (thực ra là số lẻ) thừa số nguyên tố $p$ sao cho $a$ là bất thặng dư bậc hai modulo $p$; do đó lúc này $a$ là bất thặng dư bậc hai modulo $m$.

Ta còn có thể mở rộng modulo thêm một bước thành **số nguyên** bằng cách bổ sung định nghĩa cho $\left(\dfrac{a}{-1}\right)$, $\left(\dfrac{a}{0}\right)$ và $\left(\dfrac{a}{2}\right)$. Như vậy thu được [ký hiệu Kronecker](https://en.wikipedia.org/wiki/Kronecker_symbol).

<span id="khai-căn-bậc-hai-trong-nghĩa-modulo"></span>
## Khai căn bậc hai trong nghĩa modulo

Phần này thảo luận các thuật toán khai căn bậc hai trong nghĩa modulo. Cụ thể, phần này chủ yếu giới thiệu trường hợp modulo nguyên tố. Với modulo tổng quát, có thể tham khảo phần thảo luận về [khai căn bậc cao trong nghĩa modulo](./residue.md#khai-căn-theo-modulo).

<span id="thuật-toán-cho-các-trường-hợp-đặc-biệt"></span>
### Thuật toán cho các trường hợp đặc biệt

Với phương trình đồng dư $x^2\equiv a\pmod p$, trong đó $p$ là số nguyên tố lẻ và $a$ là thặng dư bậc hai, khi $p\bmod 4=3$ có cách giải đơn giản hơn. Xét

$$
\begin{aligned}
\left(a^{(p+1)/4}\right)^2&\equiv a^{(p+1)/2}&\pmod p\\
&\equiv x^{p+1}&\pmod p\\
&\equiv \left(x^2\right)\left(x^{p-1}\right)&\pmod p\\
&\equiv x^2&\pmod p&\quad (\because{\text{Fermat's little theorem}})
\end{aligned}
$$

Khi đó $a^{(p+1)/4}\bmod p$ là một nghiệm.

<span id="thuật-toán-atkin"></span>
#### Thuật toán Atkin

Vẫn xét phương trình đồng dư ở trên. Khi $p\bmod 8=5$, đặt $b\equiv (2a)^{(p-5)/8}\pmod p$ và $\mathrm{i}\equiv 2ab^2\pmod p$. Khi đó $\mathrm{i}^2\equiv -1\pmod p$ và $ab(\mathrm{i}-1)\bmod p$ là một nghiệm.

???+ note "Chứng minh"
    $$
    \begin{aligned}
    \mathrm{i}^2&\equiv\left(2ab^2\right)^2&\pmod p\\
    &\equiv \left(2a\cdot \left(2a\right)^{(p-5)/4}\right)^2&\pmod p\\
    &\equiv \left(\left(2a\right)^{(p-1)/4}\right)^2&\pmod p\\
    &\equiv \left(2a\right)^{\frac{p-1}{2}}&\pmod p\\
    &\equiv -1&\pmod p
    \end{aligned}
    $$
    
    Khi đó
    
    $$
    \begin{aligned}
    \left(ab(\mathrm{i}-1)\right)^2&\equiv a^2\cdot \left(2a\right)^{(p-5)/4}\cdot (-2\mathrm{i})&\pmod p\\
    &\equiv a\cdot (-\mathrm{i})\cdot \left(2a\right)^{(p-1)/4}&\pmod p\\
    &\equiv a&\pmod p
    \end{aligned}
    $$

<span id="thuật-toán-cipolla"></span>
### Thuật toán Cipolla

Thuật toán Cipolla dùng để giải phương trình đồng dư $y^2\equiv a\pmod p$, trong đó $p$ là số nguyên tố lẻ và $a$ là thặng dư bậc hai.

Phần này xét phép toán trong $\mathbf{F}_p\lbrack x\rbrack /(x^2-g)$, với $g \in \mathbf{F}_p$.

??? note "Cách tính"
    Nếu chưa quen với [vành đa thức](../algebra/ring-theory.md#vành-đa-thức), có thể hiểu đơn giản rằng mỗi phần tử của tập này đều có dạng $a_0+a_1x$ với $a_0,a_1\in\mathbf F_p$, và tuân theo các quy tắc tính sau:
    
    $$
    \begin{aligned}
    (a_0+a_1x)+(b_0+b_1x) &\equiv (a_0+b_0)+(a_1+b_1)x &\pmod{(x^2-g)}\\
    (a_0+a_1x)(b_0+b_1x) &\equiv (a_0b_0+a_1b_1g)+(a_1b_0+a_0b_1)x &\pmod{(x^2-g)}
    \end{aligned}
    $$
    
    Cần chú ý rằng $x$ ở đây không phải một số cụ thể, mà là ký hiệu hình thức trong đa thức. Điểm then chốt của phép toán là dùng $x^2 \equiv g \pmod{(x^2-g)}$ để chuyển hạng bậc hai thành hạng bậc nhất và hạng hằng. Ngoài ra, mọi phép toán số nguyên đều cần lấy modulo $p$.
    
    Để biết thêm về cấu trúc này, xem các trang [đa thức](../poly/intro.md) và [lý thuyết trường](../algebra/field-theory.md).

Bước đầu tiên của thuật toán là tìm một $r$ sao cho $r^2-a$ là bất thặng dư bậc hai. Dĩ nhiên với $a \equiv 0 \pmod p$ thì không thể tìm được $r$ như vậy, nên cần xử lý riêng. Phần dưới chỉ xét trường hợp $a \not\equiv 0 \pmod p$. Khi đó có thể chọn ngẫu nhiên một $r$ rồi kiểm tra; kỳ vọng tìm được sau $2$ bước. Khi ấy, $(r-x)^{\frac{p+1}{2}}\bmod (x^2-(r^2-a))$ là một nghiệm, có thể tính bằng lũy thừa nhanh.

??? note "Vì sao kỳ vọng chỉ cần hai bước"
    Xét trường hợp $r^2-a$ là thặng dư bậc hai. Khi đó tồn tại $x$ sao cho $r^2-a \equiv x^2 \pmod p$, chuyển vế được $(r+x)(r-x) \equiv a \pmod p$. Dễ thấy mỗi giá trị $(r+x) \in [1, p-1]$ tương ứng một-một với một nghiệm $(r,x)$, nên phương trình này có tổng cộng $p-1$ nghiệm. Ta chia thành hai trường hợp $x \equiv 0$ và $x \not\equiv 0$. Với $x \equiv 0$, vì $a$ là thặng dư bậc hai, có $2$ giá trị $r$ tương ứng; với $x \not\equiv 0$, có $p-1-2$ trường hợp, mỗi $r$ tương ứng với hai trường hợp trong đó, nên có tổng cộng $\dfrac{p-3}{2}$ giá trị $r$. Tóm lại, có $2+\dfrac{p-3}{2}=\dfrac{p+1}{2}$ trường hợp khiến $r^2-a$ là thặng dư bậc hai. Vì vậy xác suất nhận được bất thặng dư bậc hai trong mỗi lần chọn ngẫu nhiên là $\dfrac{p-1}{2p}$, và số bước kỳ vọng là $\dfrac{2p}{p-1} \approx 2$.

???+ note "Chứng minh"
    Để tiện trình bày, trước hết đặt $f(x)=x^2-(r^2-a)\in\mathbf{F}_p\lbrack x\rbrack$.
    
    Cần chứng minh rằng $(r-x)^{\frac{p+1}{2}} \bmod f(x)$ là nghiệm của phương trình ban đầu và thuộc $\mathbf{F}_p$. Trước hết chứng minh vế đầu, tức chứng minh $(r-x)^{p+1}\equiv a\pmod {f(x)}$. Để làm việc này, ta cần hai bổ đề:
    
    **Bổ đề 1:** $x^p \equiv -x \pmod {f(x)}$
    
    Chứng minh:
    
    $$
    \begin{aligned}
    x^p&= x(x^2)^{\frac{p-1}{2}}\\
    &\equiv x(r^2-a)^{\frac{p-1}{2}}&\pmod{f(x)}&\quad (\because{x^2\equiv r^2-a\pmod{f(x)}})\\
    &\equiv -x&\pmod{f(x)}&\quad (\because{r^2-a}\text{ is quadratic non-residue})
    \end{aligned}
    $$
    
    **Bổ đề 2:** $(a+b)^p \equiv a^p+b^p \pmod p$
    
    Dùng định lý nhị thức, dễ thấy ngoài hạng đầu và hạng cuối, thừa số $p$ ở tử không thể bị khử hết, nên chỉ còn lại $a^p+b^p$.
    
    $$
    \begin{aligned}
    (a+b)^p&=\sum_{i=0}^p\binom{p}{i}a^ib^{p-i}\\
    &=\sum_{i=0}^p\frac{p!}{i!(p-i)!}a^ib^{p-i}\\
    &\equiv a^p+b^p\pmod p
    \end{aligned}
    $$
    
    Có hai bổ đề này, ta quay lại chứng minh biểu thức ban đầu:
    
    $$
    \begin{aligned}
    (r-x)^{p+1}
    &= (r-x)^p(r-x)\\
    &\equiv (r^p-x^p)(r-x)&\pmod{f(x)}\\
    &\equiv (r+x)(r-x)&\pmod{f(x)}\\
    &= r^2-x^2\\
    &\equiv r^2-(r^2-a)&\pmod{f(x)}\\
    &= a\\
    \end{aligned}
    $$
    
    Tiếp theo, dùng phản chứng để chứng minh nghiệm tìm được thuộc $\mathbf{F}_p$, tức hệ số của $x$ bằng $0$.
    
    Giả sử tồn tại một nghiệm $(a_0+a_1x)^2 \equiv a \pmod {f(x)}$ thỏa $a_1 \not\equiv 0 \pmod p$, tức $a_0^2+2a_0a_1x+a_1^2x^2 \equiv a \pmod {f(x)}$. Chuyển vế và rút gọn, ta được:
    
    $$
    a_0^2+a_1^2(r^2-a)-a \equiv -2a_0a_1x \pmod {f(x)}
    $$
    
    Hệ số của $x$ ở vế trái là $0$, nên hệ số của $x$ ở vế phải cũng bằng $0$, tức $a_0a_1 \equiv 0 \pmod p$. Vì ta đã giả sử $a_1 \not\equiv 0 \pmod p$, nhất định có $a_0 \equiv 0 \pmod p$. Khi đó $(a_1x)^2 \equiv a \pmod {f(x)}$, tức $r^2-a \equiv aa_1^{-2} \pmod p$.
    
    Vì $a$ và $a_1^{-2}$ đều là thặng dư bậc hai, từ tính nhân của ký hiệu Legendre suy ra $aa_1^{-2}$ cũng là thặng dư bậc hai. Điều này mâu thuẫn với việc $r^2-a$ là bất thặng dư bậc hai. Vậy không tồn tại nghiệm nào của phương trình ban đầu có hệ số của $x$ khác $0$; nghiệm ta tìm được cũng nhất định có hệ số của $x$ bằng $0$.

??? example "Bài mẫu [Luogu P5491 [Mẫu] Thặng dư bậc hai](https://www.luogu.com.cn/problem/P5491)"
    ```cpp
    --8<-- "docs/math/code/quad-residue/quad-residue_1.cpp"
    ```

<span id="thuật-toán-bostan-mori"></span>
### Thuật toán Bostan-Mori

Thuật toán này dựa trên thuật toán Cipolla: ta chuyển bài toán thành [truy hồi tuyến tính thuần nhất hệ số hằng](../poly/linear-recurrence.md), rồi áp dụng thuật toán Bostan-Mori. Xét một cách mô tả thường gặp khác của thuật toán Cipolla: $b=x^{\left(p+1\right)/2}\bmod{\left(x^2-tx+a\right)}$ là một nghiệm thỏa $b^2\equiv a\pmod{p}$[^ref3], trong đó $x^2-tx+a\in \mathbf{F}_p\lbrack x\rbrack$ là đa thức bất khả quy. Hệ số $t$ cũng được chọn bằng phương pháp ngẫu nhiên. Phần chứng minh lược bỏ. Dựa trên thuật toán trong bài báo của Bostan và Mori[^ref4], có thể thấy bài toán được chuyển thành việc tìm một hệ số của nghịch đảo nhân của chuỗi lũy thừa hình thức:

$$
b=\left\lbrack x^{(p+1)/2}\right\rbrack\dfrac{1}{1-tx+ax^2}
$$

và

$$
\left\lbrack x^n\right\rbrack\dfrac{k_0+k_1x}{1+k_2x+k_3x^2}=
\begin{cases}
\left\lbrack x^{(n-1)/2}\right\rbrack\dfrac{k_1-k_0k_2+k_1k_3x}{1+(2k_3-k_2^2)x+k_3^2x^2},&\text{if }n\bmod 2=1\\
\left\lbrack x^{n/2}\right\rbrack\dfrac{k_0+(k_0k_3-k_1k_2)x}{1+(2k_3-k_2^2)x+k_3^2x^2},&\text{else if }n\neq 0
\end{cases}
$$

Khi $n=0$ thì hiển nhiên $\left\lbrack x^0\right\rbrack\dfrac{k_0+k_1x}{1+k_2x+k_3x^2}=k_0$. Thuật toán này dùng ít phép nhân hơn thuật toán Cipolla. Các thuật toán liên quan có số phép nhân ít hơn có thể xem trong bài viết của Müller[^ref2].

<span id="thuật-toán-legendre"></span>
### Thuật toán Legendre

Với phương trình đồng dư $x^2\equiv a\pmod p$, trong đó $p$ là số nguyên tố lẻ và $a$ là thặng dư bậc hai, thuật toán Legendre có thể mô tả như sau: tìm $r$ thỏa $r^2-a$ là bất thặng dư bậc hai, đặt $a_0+a_1x=(r-x)^{\frac{p-1}{2}}\bmod (x^2-a)$. Khi đó $a_0\equiv 0\pmod p$ và $a_1^{-2}\equiv a\pmod p$.

???+ note "Chứng minh"
    Chọn một $b$ thỏa $b^2\equiv a\pmod p$. Khi đó $(r-b)(r+b)=r^2-a$ là bất thặng dư bậc hai, nên
    
    $$
    (r-b)^{\frac{p-1}{2}}(r+b)^{\frac{p-1}{2}}\equiv -1\pmod p
    $$
    
    Tồn tại đồng cấu vành
    
    $$
    \begin{aligned}
    \phi:\mathbf{F}_p\lbrack x\rbrack/(x^2-a)&\to \mathbf{F}_p\times \mathbf{F}_p\\
    x&\mapsto (b,-b)
    \end{aligned}
    $$
    
    Khi đó
    
    $$
    \begin{aligned}
    (a_0+a_1b,a_0-a_1b)&=\phi(a_0+a_1x)\\
    &=\phi(r-x)^{\frac{p-1}{2}}\\
    &=((r-b)^{\frac{p-1}{2}},(r+b)^{\frac{p-1}{2}})\\
    &=(\pm 1,\mp 1)
    \end{aligned}
    $$
    
    Vì vậy $2a_0=(\pm 1)+(\mp 1)=0$ và $2a_1b=(\pm 1)-(\mp 1)=\pm 2$.

<span id="thuật-toán-tonelli-shanks"></span>
### Thuật toán Tonelli-Shanks

Thuật toán Tonelli-Shanks là thuật toán dựa trên logarit rời rạc để giải phương trình đồng dư $x^2\equiv a\pmod p$[^ref1], trong đó $p$ là số nguyên tố lẻ và $a$ là thặng dư bậc hai modulo $p$.

Đặt $p-1=m2^n$, trong đó $m$ là số lẻ. Vẫn dùng phương pháp ngẫu nhiên để tìm $r\in\mathbf{F}_p$ sao cho $r$ là bất thặng dư bậc hai. Đặt $g\equiv r^m\pmod p$ và $b\equiv a^{(m-1)/2}\pmod p$. Khi đó tồn tại số nguyên $e\in\lbrace 0,1,2,\dots ,2^n-1\rbrace$ thỏa $ab^2\equiv g^e\pmod p$. Nếu $a$ là thặng dư bậc hai, thì $e$ là số chẵn và $\left(abg^{-e/2}\right)^2\equiv a\pmod p$.

???+ note "Chứng minh"
    Theo định lý nhỏ Fermat,
    
    $$
    g^{2^n} \equiv r^{m2^n} = r^{p-1} \equiv 1 \pmod p.
    $$
    
    Lại vì $r$ là bất thặng dư bậc hai, ta có
    
    $$
    g^{2^{n-1}} \equiv r^{m2^{n-1}} = r^{\frac{p-1}{2}} \equiv -1 \pmod p.  
    $$
    
    Vì vậy, bậc của $g$ modulo $p$ là $2^n$. Mặt khác, vì $ab^2\equiv a^m\pmod p$ là nghiệm của $x^{2^n}\equiv 1\pmod p$, nên $a^m$ là một lũy thừa của $g$. Ký hiệu $a^m\equiv g^e\pmod p$.
    
    Vì $a$ là thặng dư bậc hai, nên
    
    $$
    g^{e2^{n-1}} \equiv a^{m2^{n-1}} = a^{\frac{p-1}{2}} \equiv 1 \pmod p.
    $$
    
    Theo tính chất của bậc, $2^n\mid e2^{n-1}$, nên $e$ là số chẵn. Do đó $abg^{-e/2}\bmod p$ được định nghĩa tốt, và
    
    $$
    \left(abg^{-e/2}\right)^2 = a^2b^2g^{-e} \equiv a^{m+1}g^{-e} \equiv a \pmod p.
    $$

Vấn đề còn lại là tính $e$. Tonelli và Shanks đề xuất xác định từng bit nhị phân của $e$. Viết $e$ dưới dạng nhị phân $e=e_0+2e_1+4e_2+\cdots$, trong đó $e_k\in\lbrace 0,1\rbrace$. Vì $a$ là thặng dư bậc hai, ban đầu $e_0=0$. Sau đó dùng tính chất sau để lần lượt xác định giá trị của $e_k$:

$$
\left(g^eg^{-(e\bmod 2^k)}\right)^{2^{n-1-k}}\equiv g^{2^{n-1}\cdot e_k}\equiv 
\begin{cases}
1\pmod p,&\text{if }e_k=0\\
-1\pmod p,&\text{if }e_k=1
\end{cases}
$$

Trong đó $g^e\equiv ab^2\pmod p$ đã biết, còn giá trị $e\bmod 2^k$ có thể tính từ các bit trước đó $e_0,e_1,\cdots,e_{k-1}$. Khi cài đặt thuật toán, chỉ cần trực tiếp duy trì tích $g^eg^{-(e\bmod 2^k)}\bmod p$.

<span id="bài-tập"></span>
## Bài tập

-   [Luogu P5491 [Mẫu] Thặng dư bậc hai](https://www.luogu.com.cn/problem/P5491)
-   ["Timus 1132" Square Root](https://acm.timus.ru/problem.aspx?space=1&num=1132)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

1.  [Quadratic residue - Wikipedia](https://en.wikipedia.org/wiki/Quadratic_residue)
2.  [Euler's criterion - Wikipedia](https://en.wikipedia.org/wiki/Euler%27s_criterion)

[^ref1]: Daniel. J. Bernstein. Faster Square Roots in Annoying Finite Fields.

[^ref2]: S. Müller, On the computation of square roots in finite fields, Design, Codes and Cryptography, Vol.31, pp. 301-312, 2004.

[^ref3]: A. Menezes, P. van Oorschot and S. Vanstone. Handbook of Applied Cryptography, 1996.

[^ref4]: Alin Bostan, Ryuhei Mori. A Simple and Fast Algorithm for Computing the N-th Term of a Linearly Recurrent Sequence. Available at <https://arxiv.org/abs/2008.08822>.

[^ref5]: [Proofs of quadratic reciprocity - Wikipedia](https://en.wikipedia.org/wiki/Proofs_of_quadratic_reciprocity)

[^ref6]: Carl Friedrich Gauss. Untersuchungen über höhere Arithmetik, 1965. Page 458-462.

[^ref7]: Kobi Kremnizer. [Lectures in number theory 2022](https://courses.maths.ox.ac.uk/pluginfile.php/29788/mod_resource/content/1/numbertheory-2022.pdf). Proposition 4.3.
