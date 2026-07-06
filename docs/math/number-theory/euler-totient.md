author: iamtwz, Chrogeek, Enter-tainer, StudyingFather, aofall, CCXXXI, CoelacanthusHex, frank-xjh, Great-designer, greyqz, guodong2005, henrytbtrue, Ir1d, kZime, lihaoyu1234, Marcythm, MegaOwIer, Menci, nalemy, orzAtalod, ouuan, Persdre, segment-tree, ShaoChenHeng, shuzhouliu, sshwy, Struggler-q, Tiphereth-A, TrisolarisHD, Xeonacid, yuhuoji

<span id="định-nghĩa"></span>
## Định nghĩa

Hàm Euler (Euler's totient function), tức $\varphi(n)$, biểu thị số lượng số không vượt quá $n$ và nguyên tố cùng nhau với $n$.

Ví dụ $\varphi(1) = 1$.

Khi $n$ là số nguyên tố, $\varphi(n) = n - 1$.

<span id="tính-chất"></span>
## Tính chất

-   Hàm Euler là [hàm nhân tính](./basic.md#hàm-nhân-tính).

    Tức với mọi số nguyên $a,b$ thỏa $\gcd(a, b) = 1$, có $\varphi(ab) = \varphi(a)\varphi(b)$.

    Đặc biệt, khi $n$ là số lẻ, $\varphi(2n) = \varphi(n)$.

    Chứng minh xem tại [hợp thành hệ thặng dư](./basic.md#phép-ghép-hệ-thặng-dư).

-   $n = \sum_{d \mid n}{\varphi(d)}$.

    ???+ note "Chứng minh"
        Có thể suy ra bằng kiến thức liên quan đến [đảo Möbius](./mobius.md).
        
        Cũng có thể suy nghĩ như sau: nếu $\gcd(k, n) = d$, thì $\gcd(\dfrac{k}{d},\dfrac{n}{d}) = 1, ( k < n )$.
        
        Nếu đặt $f(x)$ là số lượng số thỏa $\gcd(k, n) = x$, thì $n = \sum_{i = 1}^n{f(i)}$.
        
        Theo chứng minh trên, $f(x) = \varphi(\dfrac{n}{x})$, nên $n = \sum_{d \mid n}\varphi(\dfrac{n}{d})$. Lưu ý rằng ước $d$ và $\dfrac{n}{d}$ có tính đối xứng, do đó công thức trở thành $n = \sum_{d \mid n}\varphi(d)$.

-   Nếu $n = p^k$, trong đó $p$ là số nguyên tố, thì $\varphi(n) = p^k - p^{k - 1}$.
    (Suy ra trực tiếp từ định nghĩa.)

-   Theo định lý phân tích duy nhất, đặt $n = \prod_{i=1}^{s}p_i^{k_i}$, trong đó $p_i$ là số nguyên tố, có $\varphi(n) = n \times \prod_{i = 1}^s{\dfrac{p_i - 1}{p_i}}$.

    ???+ note "Chứng minh"
        -   Bổ đề: với mọi số nguyên tố $p$, $\varphi(p^k)=p^{k-1}\times(p-1)$.
        
            Chứng minh: trong các số từ 1 đến $p^k$, ngoài $p^{k-1}$ bội của $p$, các số còn lại đều nguyên tố cùng nhau với $p^k$, nên $\varphi(p^k)=p^k-p^{k-1}=p^{k-1}\times(p-1)$. Chứng minh xong.
        
        Tiếp theo chứng minh $\varphi(n) = n \times \prod_{i = 1}^s{\dfrac{p_i - 1}{p_i}}$. Từ định lý phân tích duy nhất và tính nhân tính của hàm $\varphi(x)$,
        
        $$
        \begin{aligned}
            \varphi(n) &= \prod_{i=1}^{s} \varphi(p_i^{k_i}) \\
            &= \prod_{i=1}^{s} (p_i-1)\times {p_i}^{k_i-1}\\
            &=\prod_{i=1}^{s} {p_i}^{k_i} \times(1 - \frac{1}{p_i})\\
            &=n~ \prod_{i=1}^{s} (1- \frac{1}{p_i})
            &\square
        \end{aligned}
        $$

-   Với mọi số nguyên $m,n$ không đồng thời bằng $0$, $\varphi(mn)\varphi(\gcd(m,n))=\varphi(m)\varphi(n)\gcd(m,n)$.

    Có thể tính trực tiếp từ tính chất trước.

<span id="cài-đặt"></span>
## Cài đặt

Nếu chỉ cần tính giá trị hàm Euler của một số, có thể vừa phân tích thừa số nguyên tố theo định nghĩa vừa tính trực tiếp. Quá trình này có thể được tối ưu bằng thuật toán [Pollard Rho](./pollard-rho.md).

???+ note "Cài đặt tham khảo"
    === "C++"
        ```cpp
        #include <cmath>
        
        int euler_phi(int n) {
          int ans = n;
          for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
              ans = ans / i * (i - 1);
              while (n % i == 0) n /= i;
            }
          if (n > 1) ans = ans / n * (n - 1);
          return ans;
        }
        ```
    
    === "Python"
        ```python
        import math
        
        
        def euler_phi(n):
            ans = n
            for i in range(2, math.isqrt(n) + 1):
                if n % i == 0:
                    ans = ans // i * (i - 1)
                    while n % i == 0:
                        n = n // i
            if n > 1:
                ans = ans // n * (n - 1)
            return ans
        ```

Nếu cần giá trị hàm Euler của nhiều số, có thể dùng sàng tuyến tính sẽ nhắc ở phần sau.

Xem chi tiết: [tính hàm Euler bằng sàng](./sieve.md#tính-hàm-euler-bằng-sàng)

<span id="ứng-dụng"></span>
## Ứng dụng

Hàm Euler thường được dùng để rút gọn tổng của một dãy ước chung lớn nhất. Một số bài viết tiếng Trung gọi kỹ thuật này là **đảo Euler**[^1].

Thay $n=\gcd(a,b)$ vào kết luận

$$
n=\sum_{d|n}\varphi(d),
$$

suy ra

$$
\gcd(a,b) = \sum_{d|\gcd(a,b)}\varphi(d) = \sum_d [d|a][d|b]\varphi(d),
$$

trong đó $[\cdot]$ là ngoặc Iverson. Lấy tổng hai vế, thu được

$$
\sum_{i=1}^n\gcd(i,n)=\sum_{d}\sum_{i=1}^n[d|i][d|n]\varphi(d)=\sum_d\left\lfloor\frac{n}{d}\right\rfloor[d|n]\varphi(d)=\sum_{d|n}\left\lfloor\frac{n}{d}\right\rfloor\varphi(d).
$$

Quan sát then chốt là $\sum_{i=1}^n[d|i]=\lfloor\frac{n}{d}\rfloor$, tức số lượng $i$ trong khoảng từ $1$ đến $n$ chia hết cho $d$ là $\lfloor\frac{n}{d}\rfloor$.

Dùng công thức này, có thể duyệt các ước để tính tổng. Khi có nhiều truy vấn, có thể tiền xử lý tổng tiền tố của hàm Euler rồi dùng chia khối số học để trả lời.

???+ note "[GCD SUM](https://www.luogu.com.cn/problem/P2398)"
    Cho $n\le 100000$, cần tính
    
    $$
    \sum_{i=1}^n\sum_{j=1}^n\gcd(i,j).
    $$
    
    ??? note "Ý tưởng"
        Tương tự suy luận ở trên, có thể thu được
        
        $$
        \sum_{i=1}^n\sum_{j=1}^n\gcd(i,j) = \sum_{d=1}^n\left\lfloor\frac{n}{d}\right\rfloor^2\varphi(d).
        $$
        
        Lúc này cần duyệt từ $1$ đến $n$ để tính hàm Euler; dùng sàng tuyến tính có thể nhận đáp án trong $O(n)$.

<span id="định-lý-euler"></span>
## Định lý Euler

Một định lý liên quan chặt chẽ đến hàm Euler là định lý Euler. Nội dung như sau:

Nếu $\gcd(a, m) = 1$, thì $a^{\varphi(m)} \equiv 1 \pmod{m}$.

<span id="định-lý-euler-mở-rộng"></span>
### Định lý Euler mở rộng

Cũng có định lý Euler mở rộng để xử lý trường hợp tổng quát của $a$ và $m$.

$$
a^b\equiv
\begin{cases}
a^{b\bmod\varphi(m)},\,&\gcd(a,\,m)=1\\
a^b,&\gcd(a,\,m)\ne1,\,b<\varphi(m)\\
a^{b\bmod\varphi(m)+\varphi(m)},&\gcd(a,\,m)\ne1,\,b\ge\varphi(m)
\end{cases}
\pmod m
$$

Chứng minh và bài tập xem tại [định lý Euler](./fermat.md).

<span id="bài-tập"></span>
## Bài tập

-   [SPOJ ETF. Euler Totient Function](http://www.spoj.com/problems/ETF/)
-   [UVa 10179. Irreducible Basic Fractions](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1120)
-   [UVa 10299. Relatives](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1240)
-   [UVa 11327. Enumerating Rational Numbers](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2302)
-   [TIMUS 1673. Admission to Exam](http://acm.timus.ru/problem.aspx?space=1&num=1673)
-   [Luogu P1390 Tổng các ước chung](https://www.luogu.com.cn/problem/P1390)
-   [Luogu P2155 [SDOI2008] Nỗi băn khoăn của công chúa salad](https://www.luogu.com.cn/problem/P2155)
-   [Luogu P2568 GCD](https://www.luogu.com.cn/problem/P2568)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

[^1]: Cách gọi này chưa thấy xuất hiện trong tạp chí học thuật hoặc diễn đàn nước ngoài; cần lưu ý khi sử dụng.
