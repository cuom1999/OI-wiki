author: iamtwz, aofall, CCXXXI, CoelacanthusHex, Great-designer, Marcythm, Persdre, shuzhouliu, Tiphereth-A, Xeonacid

<span id="&#23450;&#20041;"></span>
## Định nghĩa

???+ abstract "Phương trình đồng dư"
    Với số nguyên dương $m$ và đa thức một biến hệ số nguyên $f(x)=\sum_{i=0}^n a_ix^i$, trong đó ẩn $x\in\mathbf{Z}_m$, phương trình có dạng
    
    $$
    f(x)\equiv 0\pmod m\tag{1}
    $$
    
    được gọi là **phương trình đồng dư** (Congruence Equation) một ẩn theo $x$ modulo $m$.
    
    Nếu $a_n\not\equiv 0\pmod m$, phương trình trên được gọi là phương trình đồng dư bậc $n$.
    
    Có thể định nghĩa tương tự cho hệ phương trình đồng dư.

Nội dung liên quan đến phương trình đồng dư bậc nhất và hệ phương trình xem tại [phương trình đồng dư tuyến tính](./linear-equation.md) và [định lý thặng dư Trung Hoa](./crt.md).

Bài viết này trước hết nghiên cứu tính giải được và cấu trúc tập nghiệm của phương trình đồng dư, sau đó giới thiệu ngắn gọn cách giải phương trình đồng dư bậc cao.

Từ [định lý thặng dư Trung Hoa](./crt.md), việc giải phương trình đồng dư modulo hợp số $m$ có thể chuyển thành các bài toán modulo lũy thừa của số nguyên tố. Vì vậy phần dưới chỉ giới thiệu lý thuyết liên quan đến phương trình đồng dư modulo lũy thừa nguyên tố và modulo nguyên tố.

<span id="&#32032;&#25968;&#24130;&#27169;&#21516;&#20313;&#26041;&#31243;"></span>
## Phương trình đồng dư modulo lũy thừa nguyên tố

Dưới đây giả sử modulo có dạng $m=p^e~(p\in\mathbf{P},~e\in\mathbf{Z}_{>1})$.

Chú ý rằng nếu $x_0$ là nghiệm của phương trình

$$
f(x)\equiv 0\pmod{p^e}
$$

thì $x_0$ cũng là nghiệm của phương trình

$$
f(x)\equiv 0\pmod{p^{e-1}}.
$$

Điều này gợi ý ta dùng nghiệm theo modulo lũy thừa thấp hơn để xây dựng nghiệm theo modulo lũy thừa cao hơn. Ta có định lý sau:

<span id="&#23450;&#29702;-1"></span>

???+ note "Định lý 1 (bổ đề Hensel)"
    Với số nguyên tố $p$ và số nguyên $e>1$, lấy đa thức hệ số nguyên $f(x)=\sum_{i=0}^na_ix^i~(p^e\nmid a_n)$, và đặt đạo hàm của nó là $f'(x)=\sum_{i=1}^nia_ix^{i-1}$. Gọi $x_0$ là một nghiệm của phương trình
    
    $$
    f(x)\equiv 0\pmod{p^{e-1}}\tag{2}
    $$
    
    Khi đó:
    
    1.  Nếu $f'(x_0)\not\equiv 0\pmod p$, thì tồn tại số nguyên $t$ sao cho
    
        $$
        x=x_0+p^{e-1}t \tag{3}
        $$
    
        là nghiệm của phương trình
    
        $$
        f(x)\equiv 0\pmod{p^e}. \tag{4}
        $$
    
    2.  Nếu $f'(x_0)\equiv 0\pmod p$ và $f(x_0)\equiv 0\pmod{p^e}$, thì với $t=0,1,\dots,p-1$, mọi $x$ xác định bởi công thức $(3)$ đều là nghiệm của phương trình $(4)$.
    3.  Nếu $f'(x_0)\equiv 0\pmod p$ và $f(x_0)\not\equiv 0\pmod{p^e}$, thì không thể dùng công thức $(3)$ để tạo nghiệm của phương trình $(4)$.

???+ note "Chứng minh"
    Giả sử $(3)$ là nghiệm của phương trình $(4)$, tức là
    
    $$
    f(x_0+p^{e-1}t)\equiv 0\pmod{p^e}.
    $$
    
    Biến đổi ta được
    
    $$
    f(x_0)+p^{e-1}tf'(x_0)\equiv 0\pmod{p^e}.
    $$
    
    Suy ra
    
    $$
    tf'(x_0)\equiv -\frac{f(x_0)}{p^{e-1}}\pmod p.\tag{5}
    $$
    
    1.  Nếu $f'(x_0)\not\equiv 0\pmod p$, phương trình $(5)$ theo $t$ có nghiệm duy nhất $t_0$; thay vào $(3)$ có thể kiểm tra nó là nghiệm của $(4)$.
    2.  Nếu $f'(x_0)\equiv 0\pmod p$ và $f(x_0)\equiv 0\pmod{p^e}$, mọi $t$ đều làm $(5)$ đúng; thay vào $(3)$ có thể kiểm tra tất cả đều là nghiệm của $(4)$.
    3.  Nếu $f'(x_0)\equiv 0\pmod p$ và $f(x_0)\not\equiv 0\pmod{p^e}$, phương trình $(5)$ vô nghiệm, nên không thể dùng $(3)$ để tạo nghiệm của $(4)$.

Từ đó ta có hệ quả:

<span id="&#25512;&#35770;-1"></span>

???+ note "Hệ quả 1"
    Với $p$, $e$, $f(x)$, $x_0$ trong [Định lý 1](#%E5%AE%9A%E7%90%86-1),
    
    1.  Nếu $s$ là nghiệm của phương trình $f(x)\equiv 0\pmod p$ và $f'(s)\not\equiv 0\pmod p$, thì tồn tại $x_s\in\mathbf{Z}_{p^e}$, $x_s\equiv s\pmod p$ sao cho $x_s$ là nghiệm của phương trình $(4)$.
    2.  Nếu hai phương trình $f(x)\equiv 0\pmod p$ và $f'(x)\equiv 0\pmod p$ không có nghiệm chung, thì phương trình $(4)$ và phương trình $f(x)\equiv 0\pmod p$ có cùng số nghiệm.

Vậy ta có thể quy phương trình đồng dư modulo lũy thừa nguyên tố về trường hợp modulo nguyên tố.

<span id="&#32032;&#25968;&#27169;&#21516;&#20313;&#26041;&#31243;"></span>
## Phương trình đồng dư modulo nguyên tố

Dưới đây đặt $p\in\mathbf{P}$, đa thức hệ số nguyên $f(x)=\sum_{i=0}^na_ix^i$ với $p\nmid a_n$, và $x\in\mathbf{Z}_p$.

<span id="&#23450;&#29702;-2"></span>

???+ note "Định lý 2"
    Nếu phương trình
    
    $$
    f(x)\equiv 0\pmod p\tag{6}
    $$
    
    có $k$ nghiệm phân biệt $x_1,x_2,\dots,x_k~(k\leq n)$, thì
    
    $$
    f(x)\equiv g(x)\prod_{i=1}^k(x-x_i)\pmod p,
    $$
    
    trong đó $\deg g=n-k$ và $[x^{n-k}]g(x)=a_n$.

???+ note "Chứng minh"
    Dùng quy nạp toán học theo $k$.
    
    -   Với $k=1$, chia đa thức có dư: $f(x)=(x-x_1)g(x)+r$, trong đó $r\in\mathbf{Z}$.
    
        Từ $f(x_1)\equiv 0\pmod p$ suy ra $r\equiv 0\pmod p$, nên $f(x)\equiv(x-x_1)g(x)\pmod p$.
    -   Giả sử mệnh đề đúng với $k-1$($k>1$). Bây giờ cho $f(x)$ có $k$ nghiệm phân biệt $x_1,x_2,\dots,x_k$. Khi đó $f(x)\equiv(x-x_1)h(x)\pmod p$, và
    
        $$
        (\forall i=2,3,\dots,k),~~0\equiv f(x_i)\equiv (x_i-x_1)h(x_i)\pmod p.
        $$
    
        Do đó $h(x)$ có $k-1$ nghiệm phân biệt $x_2,x_3,\dots,x_k$. Theo giả thiết quy nạp,
    
        $$
        h(x)\equiv g(x)\prod_{i=2}^k(x-x_i)\pmod p,
        $$
    
        trong đó $\deg g=n-k$ và $[x^{n-k}]g(x)=a_n$.
    
        Vì vậy mệnh đề được chứng minh.

<span id="&#25512;&#35770;-2"></span>

???+ note "Hệ quả 2"
    Với số nguyên tố $p$,
    
    -   $(\forall x\in\mathbf{Z}),~~x^{p-1}-1 \equiv \prod_{i=1}^{p-1}(x-i)\pmod p$.
    -   ([Định lý Wilson](./factorial.md#wilson-%E5%AE%9A%E7%90%86)) $(p-1)! \equiv -1 \pmod p$.

<span id="&#23450;&#29702;-3lagrange-&#23450;&#29702;"></span>

???+ note "Định lý 3 (định lý Lagrange)"
    Phương trình $(6)$ có nhiều nhất $n$ nghiệm phân biệt.

???+ note "Chứng minh"
    Giả sử $f(x)$ có $n+1$ nghiệm phân biệt $x_1,x_2,\dots,x_{n+1}$. Khi đó theo [Định lý 2](#%E5%AE%9A%E7%90%86-2), với $x_1,x_2,\dots,x_n$ ta có
    
    $$
    f(x)\equiv a_n\prod_{i=1}^n(x-x_i)\pmod p.
    $$
    
    Cho $x=x_{n+1}$, khi đó
    
    $$
    0\equiv f(x_{n+1})\equiv a_n\prod_{i=1}^n(x_{n+1}-x_i)\pmod p.
    $$
    
    Vế phải rõ ràng không chia hết cho $p$, mâu thuẫn.

<span id="&#25512;&#35770;-3"></span>

???+ note "Hệ quả 3"
    Nếu phương trình đồng dư $\sum_{i=0}^nb_ix^i\equiv 0\pmod p$ có số nghiệm lớn hơn $n$, thì
    
    $$
    (\forall i=0,1,\dots,n),~~p\mid b_i.
    $$

<span id="&#23450;&#29702;-4"></span>

???+ note "Định lý 4"
    Nếu số nghiệm của phương trình $(6)$ không bằng $p$, thì tồn tại đa thức hệ số nguyên $r(x)$ với $\deg r<p$ sao cho $f(x)\equiv 0\pmod p$ và $r(x)\equiv 0\pmod p$ có cùng tập nghiệm.

???+ note "Chứng minh"
    Không mất tính tổng quát, giả sử $n\geq p$. Chia đa thức $f(x)$ cho
    
    $$
    f(x)=g(x)\left(x^p-x\right)+r(x),
    $$
    
    trong đó $\deg r<p$.
    
    Theo [định lý nhỏ Fermat](./fermat.md), với mọi số nguyên $x$ ta có $x^p\equiv x\pmod p$, do đó
    
    -   Nếu $r(x)\equiv 0\pmod p$, theo [Hệ quả 2](#%E6%8E%A8%E8%AE%BA-2), $f(x)$ có $p$ nghiệm phân biệt.
    -   Nếu $r(x)\not\equiv 0\pmod p$, từ $f(x)\equiv r(x)\pmod p$ suy ra $f(x)$ và $r(x)$ có cùng tập nghiệm.

Ta có thể dùng định lý này để hạ bậc phương trình đồng dư.

<span id="&#23450;&#29702;-5"></span>

???+ note "Định lý 5"
    Cho $n\leq p$. Phương trình
    
    $$
    x^n+\sum_{i=0}^{n-1}a_ix^i\equiv 0\pmod p\tag{7}
    $$
    
    có $n$ nghiệm khi và chỉ khi tồn tại các đa thức hệ số nguyên $q(x)$, $r(x)~(\deg r < n)$ sao cho
    
    $$
    x^p-x=f(x)q(x)+pr(x). \tag{8}
    $$

???+ note "Chứng minh"
    -   Tính cần thiết: theo phép chia đa thức, tồn tại các đa thức hệ số nguyên $q(x)$, $r_1(x)~(\deg r_1 < n)$ sao cho
    
        $$
        x^p-x=f(x)q(x)+r_1(x).
        $$
    
        Nếu phương trình $(7)$ có $n$ nghiệm, thì $r_1\equiv 0\pmod p$ cũng có đúng $n$ nghiệm đó. Theo [Hệ quả 3](#%E6%8E%A8%E8%AE%BA-3), tồn tại đa thức hệ số nguyên $r(x)$ sao cho $r_1(x)=pr(x)$, nên mệnh đề được chứng minh.
    -   Tính đủ: nếu $(8)$ đúng, theo [định lý nhỏ Fermat](./fermat.md), với mọi số nguyên $x$,
    
        $$
        0\equiv x^p-x\equiv f(x)q(x)\pmod p.
        $$
    
        Tức phương trình $f(x)q(x)\equiv 0\pmod p$ có $p$ nghiệm.
    
        Gọi số nghiệm của $(7)$ là $s$. Theo [định lý Lagrange](#%E5%AE%9A%E7%90%86-3lagrange-%E5%AE%9A%E7%90%86), ta có $s\leq n$.
    
        Mặt khác, vì $\deg q=p-n$, theo [định lý Lagrange](#%E5%AE%9A%E7%90%86-3lagrange-%E5%AE%9A%E7%90%86), phương trình $q(x)\equiv 0\pmod p$ có không quá $p-n$ nghiệm. Tập nghiệm của $f(x)q(x)\equiv 0\pmod p$ là hợp của tập nghiệm $f(x)\equiv 0\pmod p$ và tập nghiệm $q(x)\equiv 0\pmod p$, nên $s+(p-n)\geq p$, suy ra $s\geq n$.
    
        Vì vậy $s=n$.

Với đa thức không monic, vì $\mathbf{Z}_p$ là trường, có thể đưa nó về đa thức monic rồi áp dụng định lý trên.

<span id="&#23450;&#29702;-6"></span>

???+ note "Định lý 6"
    Cho $n\mid p-1$, $p\nmid a$. Phương trình
    
    $$
    x^n\equiv a\pmod p\tag{9}
    $$
    
    có nghiệm khi và chỉ khi
    
    $$
    a^{\frac{p-1}{n}}\equiv 1\pmod p.
    $$
    
    Hơn nữa, nếu $(9)$ có nghiệm, số nghiệm của nó là $n$.

???+ note "Ghi chú"
    Cấu trúc cụ thể của tập nghiệm phương trình $(9)$ có thể xem tại [thặng dư bậc $k$](./residue.md).

???+ note "Chứng minh"
    -   Tính cần thiết: nếu phương trình $(9)$ có nghiệm $x_0$, thì
    
        $$
        a^{\frac{p-1}{n}}\equiv {\left(x_0^n\right)}^{\frac{p-1}{n}}\equiv 1\pmod p.
        $$
    -   Tính đủ: nếu $a^{\frac{p-1}{n}}\equiv 1\pmod p$, thì
    
        $$
        \begin{aligned}
            x^p-x&=x\left(x^{p-1}-1\right)\\
            &=x\left(\left(x^n\right)^{\frac{p-1}{n}}-a^{\frac{p-1}{n}}+a^{\frac{p-1}{n}}-1\right)\\
            &=\left(x^n-a\right)P(x)+x\left(a^{\frac{p-1}{n}}-1\right)\\
        \end{aligned}
        $$
    
        trong đó $P(x)$ là một đa thức hệ số nguyên nào đó. Do đó theo [Định lý 5](#%E5%AE%9A%E7%90%86-5), phương trình $(9)$ có $n$ nghiệm.

<span id="&#39640;&#27425;&#21516;&#20313;&#26041;&#31243;&#65288;&#32452;&#65289;&#30340;&#27714;&#35299;&#26041;&#27861;"></span>
## Cách giải phương trình đồng dư bậc cao và hệ phương trình đồng dư

Trước hết, có thể dùng [định lý thặng dư Trung Hoa](./crt.md) để chuyển việc giải **hệ phương trình đồng dư** thành giải từng **phương trình đồng dư**, và chuyển việc giải phương trình đồng dư modulo **hợp số** $m$ thành giải các phương trình đồng dư modulo **lũy thừa nguyên tố**. Sau đó, dùng [Định lý 1](#%E5%AE%9A%E7%90%86-1) để chuyển việc giải phương trình đồng dư modulo **lũy thừa nguyên tố** thành giải phương trình đồng dư modulo **nguyên tố**.

Kết hợp với các định lý về phương trình đồng dư modulo nguyên tố, ta chỉ cần xét phương trình

$$
x^n+\sum_{i=0}^{n-1}a_ix^i\equiv 0\pmod p
$$

trong đó $p$ là số nguyên tố và $n<p$.

Có thể thay $x$ bằng $x-\dfrac{a_{n-1}}{n}$ để khử hạng $x^{n-1}$, nên chỉ cần xét phương trình

$$
x^n+\sum_{i=0}^{n-2}a_ix^i\equiv 0\pmod p\tag{10}
$$

trong đó $p$ là số nguyên tố và $n<p$.

-   Nếu $n=1$, cách giải xem tại [phương trình đồng dư tuyến tính](./linear-equation.md).
-   Nếu $n=2$, cách giải xem tại [thặng dư bậc hai](./quad-residue.md).
-   Nếu phương trình $(10)$ có thể đưa về dạng

    $$
    x^n\equiv a\pmod p,
    $$

    thì cách giải xem tại [thặng dư bậc $k$](./residue.md).

<span id="&#21442;&#32771;&#36164;&#26009;"></span>
## Tài liệu tham khảo

1.  [Congruence Equation -- from Wolfram MathWorld](https://mathworld.wolfram.com/CongruenceEquation.html)
2.  [Lagrange's theorem (number theory) - Wikipedia](https://en.wikipedia.org/wiki/Lagrange%27s_theorem_%28number_theory%29)
3.  Pan Chengdong, Pan Chengbiao. Số học sơ cấp.
4.  Feng Keqin. Số học sơ cấp và ứng dụng.
5.  Min Sihe, Yan Shijian. Số học sơ cấp.
