Bài viết này giới thiệu phần mở đầu của số học.

<span id="&#x6574;&#x9664;"></span>
## Tính chia hết

???+ note "Định nghĩa"
    Cho $a,b\in\mathbf{Z}$, $a\ne 0$. Nếu $\exists q\in\mathbf{Z}$ sao cho
    $b=aq$, ta nói $b$ **chia hết** cho $a$, kí hiệu $a\mid b$; $b$ không chia
    hết cho $a$ được kí hiệu $a\nmid b$.

Tính chất của quan hệ chia hết:

-   $a\mid b\iff-a\mid b\iff a\mid-b\iff|a|\mid|b|$
-   $a\mid b\land b\mid c\implies a\mid c$
-   $a\mid b\land a\mid c\iff\forall x,y\in\mathbf{Z}, a\mid(xb+yc)$
-   $a\mid b\land b\mid a\implies b=\pm a$
-   Cho $m\ne0$, khi đó $a\mid b\iff ma\mid mb$.
-   Cho $b\ne0$, khi đó $a\mid b\implies|a|\le|b|$.
-   Cho $a\ne0,b=qa+c$, khi đó $a\mid b\iff a\mid c$.

<span id="&#x7EA6;&#x6570;"></span>
### Ước số

???+ note "Định nghĩa"
    Nếu $a\mid b$, thì $b$ được gọi là **bội số** của $a$, còn $a$ được gọi là
    **ước số** của $b$.

$0$ là bội số của mọi số nguyên khác $0$. Với số nguyên $b\ne0$, $b$ chỉ có
hữu hạn ước số.

Ước số tầm thường (nhân tử tầm thường): với số nguyên $b\ne0$, $\pm1$, $\pm b$
là các ước số tầm thường của $b$. Khi $b=\pm1$, $b$ chỉ có hai ước số tầm
thường.

Với số nguyên $b\ne 0$, các ước số còn lại của $b$ được gọi là ước số thực sự
(nhân tử thực sự, ước số không tầm thường, nhân tử không tầm thường).

Tính chất của ước số:

-   Cho số nguyên $b\ne0$. Khi $d$ chạy qua tất cả các ước số của $b$,
    $\dfrac{b}{d}$ cũng chạy qua tất cả các ước số của $b$.
-   Cho số nguyên $b\gt 0$. Khi $d$ chạy qua tất cả các ước số dương của $b$,
    $\dfrac{b}{d}$ cũng chạy qua tất cả các ước số dương của $b$.

Trong các bài toán cụ thể, **nếu không nói rõ, ước số luôn được hiểu là ước số
dương.**

<span id="&#x5E26;&#x4F59;&#x6570;&#x9664;&#x6CD5;"></span>
## Phép chia có dư

???+ note "Số dư"
    Cho $a,b$ là hai số nguyên đã cho, $a\ne0$. Cho $d$ là một số nguyên đã
    cho. Khi đó tồn tại duy nhất một cặp số nguyên $q$ và $r$ thỏa mãn
    $b=qa+r,d\le r<|a|+d$.

Với mọi giá trị nguyên của $d$, $r$ được gọi chung là số dư. $a\mid b$ tương
đương với $a\mid r$.

Thông thường lấy $d=0$; khi đó dạng $b=qa+r,0\le r<|a|$ được gọi là phép chia
có dư. Số dư $r$ ở đây được gọi là số dư không âm nhỏ nhất.

Số dư còn có hai cách chọn thường gặp:

-   Số dư có trị tuyệt đối nhỏ nhất: lấy $d$ bằng số đối của một nửa $|a|$, tức
    là $b=qa+r,-\dfrac{|a|}{2}\le r<|a|-\dfrac{|a|}{2}$.
-   Số dư dương nhỏ nhất: lấy $d=1$, tức là $b=qa+r,1\le r<|a|+1$.

Số dư trong phép chia có dư chỉ là số dư không âm nhỏ nhất. **Nếu không nói rõ,
số dư luôn được hiểu là số dư không âm nhỏ nhất.**

Tính chất của số dư:

-   Một số nguyên bất kỳ khi chia cho số nguyên dương $a$ có số dư chắc chắn và
    chỉ có thể là một trong $a$ số $0$ đến $a-1$.
-   $a$ số nguyên liên tiếp khi chia cho số nguyên dương $a$ sẽ nhận đúng một
    lần mỗi số dư nói trên. Đặc biệt, chắc chắn có đúng một số chia hết cho
    $a$.

<span id="&#x6700;&#x5927;&#x516C;&#x7EA6;&#x6570;&#x4E0E;&#x6700;&#x5C0F;&#x516C;&#x500D;&#x6570;"></span>
## Ước chung lớn nhất và bội chung nhỏ nhất

Về các định nghĩa ước chung, bội chung, ước chung lớn nhất và bội chung nhỏ
nhất, xem [Ước chung lớn nhất](./gcd.md).

???+ warning "Cảnh báo"
    Một số tác giả xem ước chung lớn nhất của $0$ và $0$ là không được định
    nghĩa; các tác giả khác thường xem nó bằng $0$. Cách cài đặt trong C++ STL
    dùng quan điểm sau, tức là ước chung lớn nhất của $0$ và $0$ bằng
    $0$[^gcdcpp].

Ước chung lớn nhất có các tính chất sau:

-   $(a_1,\dots,a_n)=(|a_1|,\dots,|a_n|)$;
-   $(a,b)=(b,a)$;
-   Nếu $a\ne 0$, thì $(a,0)=(a,a)=|a|$;
-   $(bq+r,b)=(r,b)$;
-   $(a_1,\dots,a_n)=((a_1,a_2),a_3,\dots,a_n)$. Suy ra $\forall 1<k<n-1,~(a_1,\dots,a_n)=((a_1,\dots,a_k),(a_{k+1},\dots,a_n))$;
-   Với các số nguyên $a_1,\dots,a_n$ không đồng thời bằng $0$ và số nguyên
    khác không $m$, $(ma_1,\dots,ma_n)=|m|(a_1,\dots,a_n)$;
-   Với các số nguyên $a_1,\dots,a_n$ không đồng thời bằng $0$, nếu
    $(a_1,\dots,a_n)=d$, thì $(a_1/d,\dots,a_n/d)=1$;
-   $(a^n,b^n)=(a,b)^n$.

Ước chung lớn nhất còn có các tính chất liên quan đến tính nguyên tố cùng nhau:

-   Nếu $b|ac$ và $(a,b)=1$, thì $b\mid c$;
-   Nếu $b|c$, $a|c$ và $(a,b)=1$, thì $ab\mid c$;
-   Nếu $(a,b)=1$, thì $(a,bc)=(a,c)$;
-   Nếu $(a_i,b_j)=1,~\forall 1\leq i\leq n,1\leq j\leq m$, thì
    $\left(\prod_i a_i,\prod_j b_j\right)=1$. Đặc biệt, nếu $(a,b)=1$, thì
    $(a^n,b^m)=1$;
-   Với các số nguyên $a_1,\dots,a_n$, nếu
    $\exists v\in \mathbf{Z},~\prod_i a_i=v^m$, và
    $(a_i,a_j)=1,~\forall i\ne j$, thì
    $\forall 1\leq i\leq n,~\sqrt[m]{a_i}\in\mathbf{Z}$.

Bội chung nhỏ nhất có các tính chất sau:

-   $[a_1,\dots,a_n]=[|a_1|,\dots,|a_n|]$;
-   $[a,b]=[b,a]$;
-   Nếu $a\ne 0$, thì $[a,1]=[a,a]=|a|$;
-   Nếu $a\mid b$, thì $[a,b]=|b|$;
-   $[a_1,\dots,a_n]=[[a_1,a_2],a_3,\dots,a_n]$. Suy ra $\forall 1<k<n-1,~[a_1,\dots,a_n]=[[a_1,\dots,a_k],[a_{k+1},\dots,a_n]]$;
-   Nếu $a_i\mid m,~\forall 1\leq i\leq n$, thì $[a_1,\dots,a_n]\mid m$;
-   $[ma_1,\dots,ma_n]=|m|[a_1,\dots,a_n]$;
-   $[a,b,c][ab,bc,ca]=[a,b][b,c][c,a]$;
-   $[a^n,b^n]=[a,b]^n$.

Ước chung lớn nhất và bội chung nhỏ nhất có thể kết hợp thành nhiều đẳng thức
đẹp, chẳng hạn:

-   $(a,b)[a,b]=|ab|$;
-   $(ab,bc,ca)[a,b,c]=|abc|$;
-   $\dfrac{(a,b,c)^2}{(a,b)(b,c)(a,c)}=\dfrac{[a,b,c]^2}{[a,b][b,c][a,c]}$.

Tất cả các tính chất này đều có thể chứng minh từ định nghĩa hoặc từ [định lý
phân tích duy nhất](#%E7%AE%97%E6%9C%AF%E5%9F%BA%E6%9C%AC%E5%AE%9A%E7%90%86);
chứng minh dùng định lý phân tích duy nhất thường dễ hiểu hơn.

<span id="&#x4E92;&#x7D20;"></span>
### Nguyên tố cùng nhau

???+ note "Định nghĩa"
    Nếu $(a_1,a_2)=1$, thì $a_1$ và $a_2$ được gọi là **nguyên tố cùng nhau**
    (**tối giản**).
    
    Nếu $(a_1,\ldots,a_k)=1$, thì $a_1,\ldots,a_k$ được gọi là **nguyên tố
    cùng nhau** (**tối giản**).

Nhiều số nguyên nguyên tố cùng nhau không nhất thiết phải nguyên tố cùng nhau
từng đôi. Ví dụ $6$, $10$ và $15$ nguyên tố cùng nhau, nhưng bất kỳ hai số nào
trong đó cũng không nguyên tố cùng nhau.

Tính chất của nguyên tố cùng nhau và lý thuyết ước chung lớn nhất: định lý
Bézout (Bézout's identity). Xem [Định lý Bézout](./bezouts.md).

<span id="&#x8F97;&#x8F6C;&#x76F8;&#x9664;&#x6CD5;"></span>
### Thuật toán Euclid

Thuật toán Euclid là một thuật toán, còn gọi là phép chia liên tiếp. Xem [Ước
chung lớn nhất](./gcd.md).

<span id="&#x7D20;&#x6570;&#x4E0E;&#x5408;&#x6570;"></span>
## Số nguyên tố và hợp số

Về các thuật toán liên quan đến số nguyên tố, xem [Số nguyên tố](./prime.md).

???+ note "Định nghĩa"
    Cho số nguyên $p\ne0,\pm1$. Nếu $p$ không có ước số nào ngoài các ước số
    tầm thường, thì $p$ được gọi là **số nguyên tố** (**số bất khả quy**).
    
    Nếu số nguyên $a\ne0,\pm 1$ và $a$ không phải số nguyên tố, thì $a$ được
    gọi là **hợp số**.

$p$ và $-p$ luôn đồng thời là số nguyên tố hoặc đồng thời là hợp số. **Nếu
không nói rõ, số nguyên tố luôn được hiểu là số nguyên tố dương.**

Nếu một nhân tử của số nguyên là số nguyên tố, thì số nguyên tố đó được gọi là
thừa số nguyên tố (ước nguyên tố) của số nguyên ấy.

Tính chất đơn giản của số nguyên tố và hợp số:

-   Số nguyên $a$ lớn hơn $1$ là hợp số khi và chỉ khi $a$ có thể biểu diễn
    thành tích của hai số nguyên $d$ và $e$ với $1<d,e<a$.
-   Nếu số nguyên tố $p$ có ước số $d$ lớn hơn $1$, thì $d=p$.
-   Mọi số nguyên lớn hơn $1$ đều có thể biểu diễn thành tích các số nguyên tố.
-   Với hợp số $a$, chắc chắn tồn tại số nguyên tố $p\le\sqrt{a}$ sao cho
    $p\mid a$.
-   Có vô hạn số nguyên tố.
-   Mọi số nguyên tố lớn hơn $3$ đều có dạng $6n\pm 1$[^ref1].

<span id="&#x7B97;&#x672F;&#x57FA;&#x672C;&#x5B9A;&#x7406;"></span>
## Định lý cơ bản của số học

???+ note "Bổ đề cơ bản của số học"
    Cho $p$ là số nguyên tố, $p\mid a_1a_2$. Khi đó ít nhất một trong hai mệnh
    đề $p\mid a_1$ và $p\mid a_2$ đúng.

Mệnh đề đảo của bổ đề cơ bản của số học, sau khi điều chỉnh nhẹ, cũng cho một
định nghĩa khác của số nguyên tố.

???+ note "Một định nghĩa khác của số nguyên tố"
    Với số nguyên $p\ne 0,\pm 1$, nếu với mọi cặp số nguyên $a_1,a_2$ thỏa mãn
    $p\mid a_1a_2$ đều có $p\mid a_1$ hoặc $p\mid a_2$, thì $p$ là số nguyên
    tố.

??? tip "Mẹo"
    Động cơ của định nghĩa này có thể tìm thấy trong [ideal nguyên tố](../algebra/ring-theory.md#%E7%B4%A0%E7%90%86%E6%83%B3).

???+ note "Định lý cơ bản của số học (định lý phân tích duy nhất)"
    Cho số nguyên dương $a$, khi đó luôn có biểu diễn:
    
    $$
    a=p_1p_2\cdots p_s
    $$
    
    trong đó $p_j(1\le j\le s)$ là các số nguyên tố. Hơn nữa, biểu diễn này là
    duy nhất nếu không kể đến thứ tự các thừa số.

???+ note "Dạng phân tích thừa số nguyên tố chuẩn"
    Gom các số nguyên tố giống nhau trong biểu diễn trên, ta được:
    
    $$
    a={p_1}^{\alpha_1}{p_2}^{\alpha_2}\cdots{p_s}^{\alpha_s},p_1<p_2<\cdots<p_s
    $$
    
    Đây được gọi là dạng phân tích thừa số nguyên tố chuẩn của số nguyên dương
    $a$.

Định lý cơ bản của số học và bổ đề cơ bản của số học là hai định lý tương
đương.

<span id="&#x540C;&#x4F59;"></span>
## Đồng dư

???+ note "Định nghĩa"
    Cho số nguyên $m\ne0$. Nếu $m\mid(a-b)$, ta gọi $m$ là **modun**
    (**modulo**), nói $a$ đồng dư với $b$ theo modulo $m$, và $b$ là **thặng
    dư** của $a$ theo modulo $m$. Kí hiệu $a\equiv b\pmod m$.
    
    Ngược lại, $a$ không đồng dư với $b$ theo modulo $m$, và $b$ không phải
    thặng dư của $a$ theo modulo $m$. Kí hiệu $a\not\equiv b\pmod m$.
    
    Một đẳng thức như vậy được gọi là đồng dư thức modulo $m$, gọi tắt là
    **đồng dư thức**.

Theo tính chất chia hết, đồng dư thức trên cũng tương đương với
$a\equiv b\pmod{(-m)}$.

Trong phần sau, nếu không nói rõ, modun luôn là **số nguyên dương**.

$b$ trong biểu thức là thặng dư của $a$ theo modulo $m$; khái niệm này hoàn
toàn trùng với số dư. Bằng cách giới hạn phạm vi của $b$, ta có thặng dư không
âm nhỏ nhất, thặng dư có trị tuyệt đối nhỏ nhất, và thặng dư dương nhỏ nhất của
$a$ theo modulo $m$.

Tính chất của đồng dư:

-   Đồng dư là một [quan hệ tương đương](../order-theory.md#%E4%BA%8C%E5%85%83%E5%85%B3%E7%B3%BB),
    nghĩa là đồng dư có:
    -   Tính phản xạ: $a\equiv a\pmod m$.
    -   Tính đối xứng: nếu $a\equiv b\pmod m$, thì $b\equiv a\pmod m$.
    -   Tính bắc cầu: nếu $a\equiv b\pmod m,b\equiv c\pmod m$, thì
        $a\equiv c\pmod m$.
-   Phép toán tuyến tính: nếu
    $a,b,c,d\in\mathbf{Z},m\in\mathbf{N}^*,a\equiv b\pmod m,c\equiv d\pmod m$
    thì:
    -   $a\pm c\equiv b\pm d\pmod m$.
    -   $a\times c\equiv b\times d\pmod m$.
-   Cho $f(x)=\sum_{i=0}^n a_ix^i$ và $g(x)=\sum_{i=0}^n b_ix^i$ là hai đa
    thức hệ số nguyên, $m\in\mathbf{N}^*$, và
    $a_i\equiv b_i\pmod m,~0\leq i\leq n$. Khi đó với mọi số nguyên $x$ đều có
    $f(x)\equiv g(x)\pmod m$. Hơn nữa, nếu $s\equiv t\pmod m$, thì
    $f(s)\equiv g(t)\pmod m$.
-   Nếu $a,b\in\mathbf{Z},k,m\in\mathbf{N}^*,a\equiv b\pmod m$, thì
    $ak\equiv bk\pmod{mk}$.
-   Nếu $a,b\in\mathbf{Z},d,m\in\mathbf{N}^*,d\mid a,d\mid b,d\mid m$, thì khi
    $a\equiv b\pmod m$ đúng, ta có
    $\dfrac{a}{d}\equiv\dfrac{b}{d}\left(\bmod\;{\dfrac{m}{d}}\right)$.
-   Nếu $a,b\in\mathbf{Z},d,m\in\mathbf{N}^*,d\mid m$, thì khi
    $a\equiv b\pmod m$ đúng, ta có $a\equiv b\pmod d$.
-   Nếu $a,b\in\mathbf{Z},d,m\in\mathbf{N}^*$, thì khi $a\equiv b\pmod m$ đúng,
    ta có $(a,m)=(b,m)$. Nếu $d$ chia hết $m$ và chia hết một trong hai số
    $a,b$, thì $d$ cũng chia hết số còn lại.

Còn một tính chất khác là nghịch đảo nhân. Xem [Nghịch đảo nhân](./inverse.md).

<span id="&#x540C;&#x4F59;&#x7C7B;&#x4E0E;&#x5269;&#x4F59;&#x7CFB;"></span>
## Lớp đồng dư và hệ thặng dư

Để thuận tiện thảo luận, với tập hợp $A,B$ và phần tử $r$, ta dùng các kí hiệu
sau:

-   $r+A:=\{r+a:a\in A\}$;
-   $rA:=\{ra:a\in A\}$;
-   $A+B:=\{a+b:a\in A,b\in B\}$;
-   $AB:=\{ab:a\in A,b\in B\}$.

???+ note "Lớp đồng dư"
    Với số nguyên khác không $m$, chia tất cả các số nguyên thành $|m|$ tập hợp
    đôi một không giao nhau, sao cho hai số bất kỳ trong cùng một tập hợp đều
    đồng dư theo modulo $m$. Mỗi tập hợp trong $|m|$ tập hợp đó được gọi là
    **lớp đồng dư** hoặc **lớp thặng dư** modulo $m$. Dùng $r\bmod m$ để chỉ lớp
    đồng dư modulo $m$ chứa số nguyên $r$.

    Không khó để chứng minh với mọi số nguyên khác không $m$, cách phân hoạch
    trên luôn tồn tại và duy nhất.

Từ định nghĩa lớp đồng dư, ta có:

-   $r\bmod m=\{r+km:k\in\mathbf{Z}\}$;
-   $r\bmod m=s\bmod m\iff r\equiv s\pmod m$;
-   Với mọi $r,s\in\mathbf{Z}$, hoặc $r\bmod m=s\bmod m$, hoặc
    $(r\bmod m)\cap (s\bmod m)=\varnothing$;
-   Nếu $m_1\mid m$, thì với mọi số nguyên $r$ đều có
    $r+m\mathbf{Z}\subseteq r+m_1\mathbf{Z}$.

Vì đồng dư là quan hệ tương đương, lớp đồng dư chính là lớp tương đương của quan
hệ đồng dư.

Ta kí hiệu tập hợp tất cả các lớp đồng dư modulo $m$ là $\mathbf{Z}_m$, tức là

$$
\mathbf{Z}_m:=\{r\bmod m:0\leq r<m\}
$$

Dễ thấy rằng:

-   Với mọi số nguyên $a$, $a+\mathbf{Z}_m=\mathbf{Z}_m$;
-   Với mọi số nguyên $b$ nguyên tố cùng nhau với $m$,
    $b\mathbf{Z}_m=\mathbf{Z}_m$.

Theo định nghĩa [nhóm thương](../algebra/group-theory.md#%E5%95%86%E7%BE%A4),
$\mathbf{Z}_m=\mathbf{Z}/m\mathbf{Z}$, vì vậy đôi khi ta cũng dùng
$\mathbf{Z}/m\mathbf{Z}$ để biểu diễn $\mathbf{Z}_m$.

Theo [nguyên lý chuồng chim](../combinatorics/drawer-principle.md), ta có:

-   Lấy tùy ý $m+1$ số nguyên, chắc chắn có hai số đồng dư theo modulo $m$.
-   Tồn tại $m$ số nguyên đôi một không đồng dư theo modulo $m$.

Từ đó ta đưa ra định nghĩa hệ thặng dư đầy đủ:

???+ note "Hệ thặng dư (đầy đủ)"
    Với $m$ số nguyên $a_1,a_2,\dots,a_m$, nếu với mọi số $x$ có đúng một số
    $a_i$ sao cho $x$ đồng dư với $a_i$ theo modulo $m$, thì $m$ số nguyên
    $a_1,a_2,\dots,a_m$ được gọi là **hệ thặng dư đầy đủ** modulo $m$, gọi tắt
    là **hệ thặng dư**.

Ta còn có thể định nghĩa các hệ sau modulo $m$:

-   Hệ thặng dư không âm nhỏ nhất (đầy đủ): $0,\dots,m-1$;
-   Hệ thặng dư dương nhỏ nhất (đầy đủ): $1,\dots,m$;
-   Hệ thặng dư có trị tuyệt đối nhỏ nhất (đầy đủ):
    $-\lfloor m/2\rfloor,\dots,-\lfloor -m/2\rfloor-1$;
-   Hệ thặng dư không dương lớn nhất (đầy đủ): $-m+1,\dots,0$;
-   Hệ thặng dư âm lớn nhất (đầy đủ): $-m,\dots,-1$.

Nếu không có ghi chú đặc biệt, thông thường ta chỉ dùng hệ thặng dư không âm nhỏ
nhất.

Ta lưu ý mệnh đề sau là đúng:

-   Trong một lớp đồng dư bất kỳ modulo $m$, lấy tùy ý hai số nguyên $a_1,a_2$
    đều có $(a_1,m)=(a_2,m)$.

Xét lớp đồng dư $r\bmod m$. Nếu $(r,m)=1$, thì mọi phần tử của lớp đồng dư này
đều nguyên tố cùng nhau với $m$; điều này cho thấy có thể dùng cách tương tự để
tìm cấu trúc của tập hợp các số nguyên nguyên tố cùng nhau với $m$.

???+ note "Lớp đồng dư thu gọn"
    Với lớp đồng dư $r\bmod m$, nếu $(r,m)=1$, thì lớp đồng dư này được gọi là
    **lớp đồng dư thu gọn** hoặc **lớp thặng dư thu gọn**.

    Số lượng lớp thặng dư thu gọn modulo $m$ được kí hiệu là $\varphi(m)$ và
    được gọi là [hàm Euler](./euler-totient.md).

Ta kí hiệu tập hợp tất cả các lớp đồng dư thu gọn modulo $m$ là
$\mathbf{Z}_m^*$, tức là

$$
\mathbf{Z}_m^*:=\{r\bmod m:0\leq r<m,(r,m)=1\}
$$

???+ warning "Cảnh báo"
    Với số nguyên bất kỳ $a$ và số nguyên $b$ nguyên tố cùng nhau với $m$, ta có
    $b\mathbf{Z}_m^*=\mathbf{Z}_m^*$, nhưng $a+\mathbf{Z}_m^*$ không nhất thiết
    bằng $\mathbf{Z}_m^*$. Điểm này khác với $\mathbf{Z}_m$.

Theo [nguyên lý chuồng chim](../combinatorics/drawer-principle.md), ta có:

-   Lấy tùy ý $\varphi(m)+1$ số nguyên nguyên tố cùng nhau với $m$, chắc chắn có
    hai số đồng dư theo modulo $m$.
-   Tồn tại $\varphi(m)$ số nguyên nguyên tố cùng nhau với $m$ và đôi một không
    đồng dư theo modulo $m$.

Từ đó ta đưa ra định nghĩa hệ thặng dư thu gọn:

???+ note "Hệ thặng dư thu gọn"
    Với $t=\varphi(m)$ số nguyên $a_1,a_2,\dots,a_t$, nếu
    $(a_i,m)=1,~\forall 1\leq i\leq t$, và với mọi số $x$ thỏa mãn $(x,m)=1$ có
    đúng một số $a_i$ sao cho $x$ đồng dư với $a_i$ theo modulo $m$, thì $t$ số
    nguyên $a_1,a_2,\dots,a_t$ được gọi là **hệ thặng dư thu gọn** modulo $m$.

Tương tự, ta cũng có thể định nghĩa hệ thặng dư thu gọn không âm nhỏ nhất và các
khái niệm khác.

Nếu không có ghi chú đặc biệt, thông thường ta chỉ dùng hệ thặng dư thu gọn không
âm nhỏ nhất.

<span id="&#x5269;&#x4F59;&#x7CFB;&#x7684;&#x590D;&#x5408;"></span>
### Phép ghép hệ thặng dư

Với số nguyên dương $m$, ta có định lý sau:

-   Nếu $m=m_1m_2,~1\leq m_1,m_2$, gọi $Z_{m_1},Z_{m_2}$ lần lượt là các hệ
    thặng dư **đầy đủ** modulo $m_1,m_2$, thì với mọi $a$ nguyên tố cùng nhau
    với $m_1$ ta có:

    $$
    Z_m=aZ_{m_1}+m_1Z_{m_2}.
    $$

    Đây là một hệ thặng dư **đầy đủ** modulo $m$. Hơn nữa, nếu
    $m=\prod_{i=1}^k m_i,~1\leq m_1,m_2,\dots,m_k$, gọi
    $Z_{m_1},\dots,Z_{m_k}$ lần lượt là các hệ thặng dư **đầy đủ** modulo
    $m_1,\dots,m_k$, thì:

    $$
    Z_m=\sum_{i=1}^k\left(\prod_{j=1}^{i-1}m_j\right)Z_{m_i}.
    $$

    Đây là một hệ thặng dư **đầy đủ** modulo $m$.

???+ note "Chứng minh"
    Chỉ cần chứng minh với mọi $x,x'\in Z_{m_1}$, $y,y'\in Z_{m_2}$ thỏa mãn
    $ax+m_1y\equiv ax'+m_1y'\pmod{m_1m_2}$, ta đều có:
    
    $$
    ax+m_1y=ax'+m_1y'.
    $$
    
    Thật vậy, từ $m_1\mid m_1m_2$, ta có
    $ax+m_1y\equiv ax'+m_1y'\pmod{m_1}$, suy ra
    $ax\equiv ax'\pmod{m_1}$. Do $(a,m_1)=1$, suy ra
    $x\equiv x'\pmod{m_1}$, nên $x=x'$.
    
    Tiếp theo, $m_1y\equiv m_1y'\pmod{m_1m_2}$, nên
    $y\equiv y'\pmod{m_2}$, tức là $y=y'$.
    
    Vì vậy,
    
    $$
    ax+m_1y=ax'+m_1y'.
    $$

-   Nếu $m=m_1m_2,~1\leq m_1,m_2,(m_1,m_2)=1$, gọi
    $Z_{m_1}^*,Z_{m_2}^*$ lần lượt là các hệ thặng dư **thu gọn** modulo
    $m_1,m_2$, thì:

    $$
    Z_m^*=m_2Z_{m_1}^*+m_1Z_{m_2}^*.
    $$

    Đây là một hệ thặng dư **thu gọn** modulo $m$.

???+ tip "Mẹo"
    Định lý này tương đương với việc chứng minh hàm Euler là
    [hàm nhân tính](#%E7%A7%AF%E6%80%A7%E5%87%BD%E6%95%B0).

???+ note "Chứng minh"
    Gọi $Z_{m_1},Z_{m_2}$ lần lượt là các hệ thặng dư đầy đủ modulo $m_1,m_2$.
    Ta đã chứng minh
    
    $$
    Z_m=m_2Z_{m_1}+m_1Z_{m_2}
    $$
    
    là một hệ thặng dư đầy đủ modulo $m$. Đặt
    $M=\{a\in Z_m:(a,m)=1\}\subseteq Z_m$; rõ ràng $M$ là một hệ thặng dư thu
    gọn modulo $m$, nên chỉ cần chứng minh $M=Z_m^*$.
    
    Hiển nhiên $Z_m^*\subseteq Z_m$.
    
    Lấy tùy ý $m_2x+m_1y\in M$, trong đó $x\in Z_{m_1}$ và $y\in Z_{m_2}$.
    Ta có $(m_2x+m_1y,m_1m_2)=1$. Từ $(m_1,m_2)=1$ suy ra
    
    $$
    1=(m_2x+m_1y,m_1)=(m_2x,m_1)=(x,m_1),
    $$
    
    $$
    1=(m_2x+m_1y,m_2)=(m_1y,m_2)=(y,m_2).
    $$
    
    Do đó $x\in Z_{m_1}^*$ và $y\in Z_{m_2}^*$, tức là
    $M\subseteq Z_m^*$.
    
    Lấy tùy ý $m_2x+m_1y\in Z_m^*$, trong đó $x\in Z_{m_1}^*$ và
    $y\in Z_{m_2}^*$. Ta có $(x,m_1)=1$ và $(y,m_2)=1$. Từ $(m_1,m_2)=1$ suy ra
    
    $$
    (m_2x+m_1y,m_1)=(m_2x,m_1)=(x,m_1)=1,
    $$
    
    $$
    (m_2x+m_1y,m_2)=(m_1y,m_2)=(y,m_2)=1,
    $$
    
    nên $(m_2x+m_1y,m_1m_2)=1$, tức là $Z_m^*\subseteq M$.
    
    Tổng hợp lại,
    
    $$
    Z_m^*=m_2Z_{m_1}^*+m_1Z_{m_2}^*.
    $$
    
    Đây là một hệ thặng dư **thu gọn** modulo $m$.

<span id="&#x6570;&#x8BBA;&#x51FD;&#x6570;"></span>
## Hàm số học

Hàm số học (còn gọi là hàm số số học) là hàm có miền xác định là các số nguyên
dương. Hàm số học cũng có thể xem như một dãy số.

<span id="&#x79EF;&#x6027;&#x51FD;&#x6570;"></span>
### Hàm nhân tính

???+ note "Định nghĩa"
    Trong số học, nếu hàm $f(n)$ thỏa mãn $f(1)=1$ và $f(xy)=f(x)f(y)$ với mọi
    cặp $x, y \in\mathbf{N}^*$ nguyên tố cùng nhau, thì $f(n)$ là
    **hàm nhân tính**.
    
    Trong số học, nếu hàm $f(n)$ thỏa mãn $f(1)=1$ và $f(xy)=f(x)f(y)$ với mọi
    $x, y \in\mathbf{N}^*$, thì $f(n)$ là **hàm nhân tính hoàn toàn**.

<span id="&#x6027;&#x8D28;"></span>
#### Tính chất

Nếu $f(x)$ và $g(x)$ đều là hàm nhân tính, thì các hàm sau cũng là hàm nhân tính:

$$
\begin{aligned}
h(x)&=f(x^p)\\
h(x)&=f^p(x)\\
h(x)&=f(x)g(x)\\
h(x)&=\sum_{d\mid x}f(d)g\left(\dfrac{x}{d}\right)
\end{aligned}
$$

Với số nguyên dương $x$, giả sử phân tích thừa số nguyên tố duy nhất của nó là
$x=\prod p_i^{k_i}$, trong đó $p_i$ là số nguyên tố.

Nếu $F(x)$ là hàm nhân tính, thì $F(x)=\prod F(p_i^{k_i})$.

Nếu $F(x)$ là hàm nhân tính hoàn toàn, thì
$F(x)=\prod F(p_i^{k_i})=\prod F(p_i)^{k_i}$.

<span id="&#x4F8B;&#x5B50;"></span>
#### Ví dụ

-   Hàm đơn vị: $\varepsilon(n)=[n=1]$. (nhân tính hoàn toàn)
-   Hàm đồng nhất: $\operatorname{id}_k(n)=n^k$, $\operatorname{id}_{1}(n)$
    thường được viết gọn là $\operatorname{id}(n)$. (nhân tính hoàn toàn)
-   Hàm hằng: $1(n)=1$. (nhân tính hoàn toàn)
-   Hàm ước số: $\sigma_{k}(n)=\sum_{d\mid n}d^{k}$. $\sigma_{0}(n)$ thường
    được viết gọn là $d(n)$ hoặc $\tau(n)$, $\sigma_{1}(n)$ thường được viết gọn
    là $\sigma(n)$.
-   Hàm Euler: $\varphi(n)=\sum_{i=1}^n[(i,n)=1]$.
-   Hàm Mobius:
    $\mu(n)=\begin{cases}1&n=1\\0&\exists d>1,d^{2}\mid n\\(-1)^{\omega(n)}&\text{otherwise}\end{cases}$,
    trong đó $\omega(n)$ là số lượng thừa số nguyên tố phân biệt của $n$.

<span id="&#x52A0;&#x6027;&#x51FD;&#x6570;"></span>
### Hàm cộng tính

???+ note "Định nghĩa"
    Trong số học, nếu hàm $f(n)$ thỏa mãn $f(1)=0$ và $f(xy)=f(x)+f(y)$ với mọi
    cặp $x, y \in\mathbf{N}^*$ nguyên tố cùng nhau, thì $f(n)$ là
    **hàm cộng tính**.
    
    Trong số học, nếu hàm $f(n)$ thỏa mãn $f(1)=0$ và $f(xy)=f(x)+f(y)$ với mọi
    $x, y \in\mathbf{N}^*$, thì $f(n)$ là **hàm cộng tính hoàn toàn**.

???+ warning "Hàm cộng tính"
    Hàm cộng tính trong mục này chỉ hàm cộng tính trong số học (Additive
    function), cần phân biệt với ánh xạ cộng (Additive map) trong đại số.

<span id="&#x6027;&#x8D28;_1"></span>
#### Tính chất

Với số nguyên dương $x$, giả sử phân tích thừa số nguyên tố duy nhất của nó là
$x=\prod p_i^{k_i}$, trong đó $p_i$ là số nguyên tố.

Nếu $F(x)$ là hàm cộng tính, thì $F(x)=\sum F(p_i^{k_i})$.

Nếu $F(x)$ là hàm cộng tính hoàn toàn, thì
$F(x)=\sum F(p_i^{k_i})=\sum F(p_i)\cdot k_i$.

<span id="&#x4F8B;&#x5B50;_1"></span>
#### Ví dụ

Để thuận tiện trình bày, gọi tập hợp tất cả các số nguyên tố là $\mathbf P$.

-   Số mũ của $p$ trong phân tích thừa số nguyên tố:
    $\nu_p(n) = \max\{k\in\mathbf N: p^k\mid n\}$, trong đó $p\in\mathbf P$.
    (cộng tính hoàn toàn)
-   Tổng số thừa số nguyên tố kể cả bội số:
    $\Omega(n)=\sum_{p \in\mathbf P} \nu_p(n)$. (cộng tính hoàn toàn)
-   Số thừa số nguyên tố phân biệt: $\omega(n)=\sum_{p \in\mathbf P} [p \mid n]$.
-   Tổng các thừa số nguyên tố kể cả bội số:
    $a_0(n)=\sum_{p \in\mathbf P} \nu_p(n)\cdot p$. (cộng tính hoàn toàn)
-   Tổng các thừa số nguyên tố phân biệt:
    $a_1(n)=\sum_{p \in\mathbf P} [p \mid n] \cdot p$.

<span id="&#x53D6;&#x6574;&#x51FD;&#x6570;"></span>
## Hàm lấy phần nguyên

Với số thực $x$, định nghĩa **hàm sàn** (floor function) và **hàm trần**
(ceiling function) lần lượt là

$$
\lfloor x\rfloor = \max\{k\in\mathbf Z:k\le x\},~\lceil x\rceil = \min\{k\in\mathbf Z:k\ge x\}.
$$

Dùng hàm sàn, một số thực có thể tách thành phần nguyên và phần thập phân:
$x = \lfloor x\rfloor + \{x\}$. Trong đó, $\{x\}$ biểu thị phần thập phân của
$x$.

Hàm lấy phần nguyên có các tính chất cơ bản sau:
($x\in\mathbf R,~n\in\mathbf Z$)

-   $x\in\mathbf Z \iff x = \lfloor x\rfloor = \lceil x\rceil$.
-   $\lceil x\rceil - \lfloor x\rfloor = [x\notin\mathbf Z]$.
-   $x - 1 < \lfloor x\rfloor \le x \le \lceil x\rceil < x + 1$.
-   $\lfloor -x\rfloor = -\lceil x\rceil,~\lceil -x\rceil = -\lfloor x\rfloor$.
-   $\lfloor x + n\rfloor = \lfloor x\rfloor + n,~\lceil x + n\rceil = \lceil x \rceil + n$.
-   $\lfloor x\rfloor$ và $\lceil x\rceil$ đều là các hàm đơn điệu không giảm
    theo $x$.

Khi chứng minh các đẳng thức về hàm sàn (hàm trần), thường dùng các dạng tương
đương sau: ($x\in\mathbf R,~n\in\mathbf Z$)

-   $\lfloor x\rfloor = n \iff n \le x < n + 1 \iff x - 1 < n \le x$.
-   $\lceil x\rceil = n \iff n - 1 < x \le n \iff x \le n < x + 1$.

Khi chứng minh các bất đẳng thức về hàm sàn (hàm trần), thường dùng các dạng
tương đương sau: ($x\in\mathbf R,~n\in\mathbf Z$)

-   $x < n \iff \lfloor x\rfloor < n$.
-   $n < x \iff n < \lceil x\rceil$.
-   $x \le n \iff \lceil x\rceil \le n$.
-   $n \le x \iff n \le \lfloor x\rfloor$.

Tính chất liên quan đến tổng và hiệu: ($x,y\in\mathbf R$)

-   $\lfloor x\rfloor + \lfloor y\rfloor \le \lfloor x + y\rfloor \le \lfloor x\rfloor + \lfloor y\rfloor + 1$, và đúng một dấu bằng xảy ra.
-   $\lceil x\rceil +\lceil y\rceil -1\leq \lceil x+y\rceil \leq \lceil x\rceil +\lceil y\rceil$, và đúng một dấu bằng xảy ra.
-   $\lfloor|x - y|\rfloor \le |\lfloor x\rfloor - \lfloor y\rfloor| \le \lceil|x - y|\rceil$.
-   $\lfloor|x - y|\rfloor \le |\lceil x\rceil - \lceil y\rceil| \le \lceil|x-y|\rceil$.

Tính chất liên quan đến thương:
($x\in\mathbf R,~n\in\mathbf Z,~m\in\mathbf Z_+$)

-   $\left\lceil\dfrac{n}{m}\right\rceil = \left\lfloor\dfrac{n+m-1}{m}\right\rfloor,~\left\lfloor\dfrac{n}{m}\right\rfloor = \left\lceil\dfrac{n-m+1}{m}\right\rceil$.
-   $\left\lfloor\dfrac{x + n}{m} \right\rfloor = \left\lfloor\dfrac{\lfloor x\rfloor + n}{m} \right\rfloor,~\left\lceil\dfrac{x + n}{m} \right\rceil = \left\lceil\dfrac{\lceil x\rceil + n}{m} \right\rceil$.
-   $\left\lfloor\dfrac{\lfloor x/n\rfloor}{m}\right\rfloor = \left\lfloor\dfrac{x}{nm}\right\rfloor,~\left\lceil\dfrac{\lceil x/n\rceil}{m}\right\rceil = \left\lceil\dfrac{x}{nm}\right\rceil$.
-   Với $x > 0$, có
    $\displaystyle\left\lfloor\dfrac{x}{m}\right\rfloor = \sum_{k=1}^{\lfloor x\rfloor}[m\mid k]$.

Trong đó, tính chất thứ hai và thứ ba đều có thể xem là hệ quả trực tiếp của kết
luận sau:

-   Cho $f$ là hàm liên tục, đơn điệu tăng, và cứ mỗi khi $f(x)\in\mathbf Z$ thì
    $x\in\mathbf Z$. Khi đó

    $$
    \lfloor f(x)\rfloor = \lfloor f(\lfloor x\rfloor)\rfloor,~ \lceil f(x)\rceil = \lceil f(\lceil x\rceil)\rceil.
    $$

    ??? note "Chứng minh"
        Do tính đối xứng, chỉ cần chứng minh đẳng thức thứ nhất. Nếu $x$ là số
        nguyên thì mệnh đề hiển nhiên. Ngược lại, $\lfloor x\rfloor < x$. Từ
        tính đơn điệu của $f$ và của hàm sàn, ta có
        $\lfloor f(x)\rfloor \ge \lfloor f(\lfloor x\rfloor)\rfloor$. Nếu dấu
        bằng không đúng, đặt $y = \lfloor f(x)\rfloor$; khi đó
        $\lfloor f(\lfloor x\rfloor)\rfloor < y \le \lfloor f(x)\rfloor$, tương
        đương với $f(\lfloor x\rfloor) < y \le f(x)$. Do $f$ liên tục, tồn tại
        $\lfloor x\rfloor < x_0 \le x$ sao cho $f(x_0)=y$. Vì $y\in\mathbf Z$,
        suy ra $x_0\in\mathbf Z$, mâu thuẫn với định nghĩa của $\lfloor x\rfloor$.
        Vì vậy dấu bằng đúng, tức là
        $\lfloor f(x)\rfloor = \lfloor f(\lfloor x\rfloor)\rfloor$.

Cuối cùng là một nhóm kết luận về các tổng có hàm lấy phần nguyên:
($x\in\mathbf R,~n\in\mathbf Z,~m\in\mathbf Z_+$)

-   $n = \left\lfloor\dfrac{n}{2}\right\rfloor + \left\lceil\dfrac{n}{2}\right\rceil$.
-   $n = \left\lfloor\dfrac{n}{m} \right\rfloor + \left\lfloor\dfrac{n+1}{m} \right\rfloor + \cdots + \left\lfloor\dfrac{n+m-1}{m} \right\rfloor$.
-   $n = \left\lceil\dfrac{n}{m} \right\rceil + \left\lceil\dfrac{n-1}{m} \right\rceil + \cdots + \left\lceil\dfrac{n-m+1}{m} \right\rceil$.
-   $\lfloor mx\rfloor = \lfloor x\rfloor + \left\lfloor x+\dfrac{1}{m}\right\rfloor + \cdots + \left\lfloor x+\dfrac{m-1}{m}\right\rfloor$.
-   $\lceil mx\rceil = \lceil x\rceil + \left\lceil x - \dfrac{1}{m}\right\rceil + \cdots + \left\lceil x - \dfrac{m-1}{m}\right\rceil$.
-   Khi $m\perp n$,
    $\displaystyle\sum_{k=1}^{m-1}\left\lfloor\dfrac{kn}{m}\right\rfloor=\dfrac{1}{2}(n-1)(m-1)$.
-   Khi $m\perp n$,
    $\displaystyle\sum_{k=1}^{m-1}\left\lceil\dfrac{kn}{m}\right\rceil=\dfrac{1}{2}(n+1)(m-1)$.

Cách suy ra các tổng dạng này và các dạng tổng tương tự tổng quát hơn có thể
tham khảo trang [thuật toán Euclid mở rộng dạng lớp](./euclidean.md).

Có thể tham khảo thêm các tính chất và ứng dụng của hàm lấy phần nguyên ở các
trang sau:

-   Phép modulo: $n\bmod m = n - \left\lfloor\dfrac{n}{m}\right\rfloor m$.
    Nó có thể dùng để [tối ưu phép modulo số nguyên](./mod-arithmetic.md#%E7%9B%B8%E5%85%B3%E7%AE%97%E6%B3%95).
-   Dùng bổ đề Gauss để chứng minh
    [luật tương hỗ bậc hai](./quad-residue.md#%E4%BA%8C%E6%AC%A1%E4%BA%92%E5%8F%8D%E5%BE%8B).
-   [Chia khối số học](./sqrt-decomposition.md), đặc biệt là phần chứng minh
    tính chất của nó.
-   Tính số mũ của thừa số nguyên tố trong giai thừa bằng
    [công thức Legendre](./factorial.md#legendre-%E5%85%AC%E5%BC%8F).
-   [Dãy Beatty](../game-theory/impartial-game.md#wythoff-%E6%B8%B8%E6%88%8F),
    định lý Rayleigh và trò chơi Wythoff.

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x6CE8;&#x91CA;"></span>
## Tài liệu tham khảo và ghi chú

-   Pan Chengdong, Pan Chengbiao. *Số học sơ cấp*. Nhà xuất bản Đại học Bắc
    Kinh.
-   [Floor and ceiling functions - Wikipedia](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions)
-   Graham, Ronald L., Donald E. Knuth, and Oren Patashnik. "Concrete mathematics: a foundation for computer science." (1989).

[^ref1]: [Are all primes (past 2 and 3) of the forms 6n+1 and 6n-1?](https://primes.utm.edu/notes/faq/six.html)

[^gcdcpp]: [std::gcd - cppreference.com](https://en.cppreference.com/w/cpp/numeric/gcd)
