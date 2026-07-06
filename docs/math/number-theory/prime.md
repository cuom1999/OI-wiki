author: Ir1d, Tiphereth-A, c-forrest, Xeonacid, Enter-tainer, StudyingFather, iamtwz, ksyx, Marcythm, MegaOwIer, 383494, Alpacabla, HeRaNO, abc1763613206, alphagocc, Backl1ght, CCXXXI, drkelo, Early0v0, Great-designer, greyqz, GuanghaoYe, H-J-Granger, HHH2309, isdanni, kenlig, lazyasn, Menci, ouuan, r-value, shawlleyw, shopee-jin, shuzhouliu, Siger Young, TrisolarisHD, untitledunrevised, void-mian, Voileexperiments, weilycoder, xtlsoft, yusancky, YuzhenQin1, sun2snow

Định nghĩa số nguyên tố và hợp số xem tại [cơ sở lý thuyết số](./basic.md).

Hàm đếm số nguyên tố: số lượng số nguyên tố nhỏ hơn hoặc bằng $x$, ký hiệu là
$\pi(x)$. Khi $x$ tăng, có xấp xỉ: $\pi(x) \sim \dfrac{x}{\ln(x)}$.

<span id="kiểm-tra-tính-nguyên-tố"></span>
## Kiểm tra tính nguyên tố

**Kiểm tra tính nguyên tố** (Primality test) dùng để xác định một số tự nhiên
cho trước có phải là số nguyên tố hay không.

Có hai loại kiểm tra tính nguyên tố:

1.  Kiểm tra tất định: xác định một số có phải số nguyên tố hay
    không. Các ví dụ thường gặp gồm phép thử chia, kiểm tra Lucas-Lehmer và
    chứng minh tính nguyên tố bằng đường cong elliptic.
2.  Kiểm tra xác suất: thường nhanh hơn rất nhiều so với kiểm tra tất định,
    nhưng có khả năng, dù rất nhỏ, nhận nhầm [hợp số](../number-theory/basic.md#số-nguyên-tố-và-hợp-số)
    thành số nguyên tố; chiều ngược lại thì không xảy ra. Vì vậy, những số vượt
    qua kiểm tra xác suất được gọi là **số có khả năng nguyên tố** cho đến khi
    tính nguyên tố của chúng được chứng minh một cách tất định. Những số vượt
    qua kiểm tra nhưng là hợp số được gọi là **giả nguyên tố**. Có
    nhiều kiểu giả nguyên tố cụ thể, thường gặp nhất là giả nguyên tố Fermat,
    tức các hợp số thỏa mãn định lý nhỏ Fermat. Ví dụ thường gặp của kiểm tra
    xác suất là kiểm tra Miller-Rabin.

<span id="thử-chia"></span>
### Thử chia

Cách làm vét cạn tự nhiên là liệt kê mọi số từ nhỏ đến lớn và xem nó có chia
hết hay không.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        bool isPrime(int a) {
          if (a < 2) return false;
          for (int i = 2; i < a; ++i)
            if (a % i == 0) return false;
          return true;
        }
        ```

    === "Python"
        ```python
        def isPrime(a):
            if a < 2:
                return False
            for i in range(2, a):
                if a % i == 0:
                    return False
            return True
        ```

Cách này đáng tin cậy, nhưng có cần kiểm tra từng số hay không?

Nhận thấy rằng: nếu $x$ là ước của $a$ thì $\frac{a}{x}$ cũng là ước của $a$.

Kết luận này cho biết với mỗi cặp $(x, \frac{a}{x} )$, chỉ cần kiểm tra một
trong hai số. Để thuận tiện, chỉ xét số nhỏ hơn trong mỗi cặp; tất cả các số
nhỏ hơn đó đều nằm trong khoảng $[1, \sqrt{a}]$.

Vì $1$ luôn là ước nên không cần kiểm tra nó.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        bool isPrime(int a) {
          if (a < 2) return 0;
          for (int i = 2; (long long)i * i <= a; ++i)  // tránh tràn số
            if (a % i == 0) return 0;
          return 1;
        }
        ```

    === "Python"
        ```python
        def isPrime(a):
            if a < 2:
                return False
            for i in range(2, int(sqrt(a)) + 1):
                if a % i == 0:
                    return False
            return True
        ```

<span id="kiểm-tra-tính-nguyên-tố-fermat"></span>
### Kiểm tra tính nguyên tố Fermat

**Kiểm tra tính nguyên tố Fermat** là phép kiểm tra tính nguyên tố xác suất đơn
giản nhất.

Từ [định lý nhỏ Fermat](./fermat.md#định-lý-nhỏ-fermat),
có một ý tưởng để kiểm tra số nguyên tố:

Ý tưởng cơ bản là liên tục chọn cơ số $a$ trong $[2, n-1]$ và kiểm tra mỗi lần
có $a^{n-1} \equiv 1 \pmod n$ hay không.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        bool fermat(int n) {
          if (n < 3) return n == 2;
          // test_time là số lần kiểm tra; nên đặt không nhỏ hơn 8
          // để bảo đảm độ chính xác, nhưng cũng không nên quá lớn để tránh chậm
          for (int i = 1; i <= test_time; ++i) {
            int a = rand() % (n - 2) + 2;
            if (quickPow(a, n - 1, n) != 1) return false;
          }
          return true;
        }
        ```

    === "Python"
        ```python
        def fermat(n):
            if n < 3:
                return n == 2
            # test_time là số lần kiểm tra; nên đặt không nhỏ hơn 8
            # để bảo đảm độ chính xác, nhưng cũng không nên quá lớn để tránh chậm
            for i in range(1, test_time + 1):
                a = random.randint(0, 32767) % (n - 2) + 2
                if quickPow(a, n - 1, n) != 1:
                    return False
            return True
        ```

Nếu $a^{n−1} \equiv 1 \pmod n$ nhưng $n$ không phải số nguyên tố, $n$ được gọi
là **giả nguyên tố Fermat** có cơ số $a$. Trong thực tế, khi
$a^{n−1} \equiv 1 \pmod n$, $n$ thường là số nguyên tố. Tuy nhiên có phản ví
dụ: với $n = 341$ và $a = 2$, tuy $2^{340}\equiv 1 {\pmod {341}}$, nhưng
$341 = 11 \cdot 31$ là hợp số. Với mỗi cơ số cố định $a$, có vô hạn
phản ví dụ như vậy[^inf-fermat-pp].

Vì kiểm tra Fermat không bảo đảm đúng với một cơ số đơn lẻ, một ý tưởng tự
nhiên là kiểm tra nhiều cơ số. Tuy nhiên, ngay cả khi kiểm tra tất cả cơ số $a$
nguyên tố cùng nhau với $n$, vẫn không thể bảo đảm $n$ là số nguyên tố. Nói cách
khác, mệnh đề đảo của định lý nhỏ Fermat không đúng: ngay cả khi với mọi
$a\perp n$ đều có $a^{n-1}\equiv 1\pmod n$, $n$ vẫn có thể không phải số nguyên
tố. Các số như vậy được gọi là [số Carmichael](./primitive-root.md#số-carmichael),
và cũng có vô hạn số. Do đó cần tìm phép kiểm tra tính nguyên tố chặt
chẽ hơn.

<span id="kiểm-tra-tính-nguyên-tố-miller-rabin"></span>
### Kiểm tra tính nguyên tố Miller-Rabin

**Kiểm tra tính nguyên tố Miller-Rabin** (Miller-Rabin primality test) là một
phương pháp xác định số nguyên tố tốt hơn. Nó do Miller và Rabin cải tiến từ
kiểm tra Fermat. Giống các kiểm tra số nguyên tố xác suất khác, nó chỉ có thể
phát hiện giả nguyên tố. Nếu cần xác định tất định một số là số nguyên tố, phải
dùng các thuật toán tất định chậm hơn nhiều. Tuy vậy, chưa biết số nào vượt qua
Miller-Rabin và các kiểm tra xác suất mạnh khác nhưng lại là hợp số, nên có
thể yên tâm sử dụng.

Nếu không xét độ phức tạp của phép nhân, thực hiện $k$ vòng kiểm tra cho số
$n$ có độ phức tạp thời gian $O(k \log n)$. Kiểm tra Miller-Rabin thường dùng
cho số độ chính xác cao; khi đó độ phức tạp thời gian là $O(k \log^3n)$, và có
thể tối ưu bằng FFT cùng các kỹ thuật khác thành
[$O(k \log^2n \log \log n \log \log \log n)$](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Complexity).

Để xử lý thách thức từ các số Carmichael, kiểm tra Miller-Rabin xét thêm tính
chất sau của số nguyên tố:

???+ note "Định lý căn bậc hai"
    Nếu $p$ là số nguyên tố lẻ, nghiệm của $x^2 \equiv 1 \pmod p$ là
    $x \equiv 1 \pmod p$ hoặc $x \equiv p - 1 \pmod p$.

??? note "Chứng minh"
    Dễ kiểm tra trực tiếp rằng khi $p$ là số nguyên tố lẻ, cả
    $x\equiv 1\pmod p$ và $x\equiv p-1\pmod p$ đều làm công thức trên đúng.
    Theo [định lý Lagrange](./congruence-equation.md#định-lý-3-lagrange),
    đây là tất cả nghiệm của phương trình.

Kết hợp định lý nhỏ Fermat với định lý căn bậc hai, thu được kiểm tra tính
nguyên tố Miller-Rabin:

1.  Phân tích số mũ $n-1$ trong $a^{n-1} \equiv 1 \pmod n$ thành
    $n-1=u \times 2^t$;
2.  Trong mỗi vòng kiểm tra, với $a$ được chọn ngẫu nhiên, tính trước
    $v = a^{u} \bmod n$, sau đó bình phương giá trị này tối đa $t$ lần;
3.  Trong quá trình đó, nếu phát hiện căn bậc hai không tầm thường của $1$ (tức
    nghiệm khác $\pm 1$), có thể kết luận số đó không phải số nguyên tố;
4.  Nếu không, dùng tiếp kiểm tra tính nguyên tố Fermat để phán định.

Một vài chi tiết khi cài đặt:

-   Trong một vòng kiểm tra, nếu tại thời điểm nào đó
    $a^{u \times 2^s} \equiv n-1 \pmod n$, các lần bình phương sau đó đều cho
    $1$, nên có thể cho vòng này vượt qua ngay.
-   Nếu tìm được một căn bậc hai không tầm thường
    $a^{u \times 2^s} \not\equiv n-1 \pmod n$, các lần bình phương sau đó đều
    cho $1$. Có thể trả về `false` ngay, hoặc đợi đến sau $t$ lần bình phương
    mới trả về `false`.

Thu được phiên bản Miller-Rabin khá đúng sau (từ fjzzq2002):

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        bool millerRabin(int n) {
          if (n < 3 || n % 2 == 0) return n == 2;
          if (n % 3 == 0) return n == 3;
          int u = n - 1, t = 0;
          while (u % 2 == 0) u /= 2, ++t;
          // test_time là số lần kiểm tra; nên đặt không nhỏ hơn 8
          // để bảo đảm độ chính xác, nhưng cũng không nên quá lớn để tránh chậm
          for (int i = 0; i < test_time; ++i) {
            // 0, 1, n-1 có thể vượt qua trực tiếp; a nằm trong [2, n-2]
            int a = rand() % (n - 3) + 2, v = quickPow(a, u, n);
            if (v == 1) continue;
            int s;
            for (s = 0; s < t; ++s) {
              if (v == n - 1) break;  // gặp căn tầm thường n-1, vòng này đạt
              v = (long long)v * v % n;
            }
            // Nếu gặp căn không tầm thường thì không break sớm và chạy đến s == t
            // Nếu kiểm tra Fermat không đạt, trước s == t thì v sẽ không bằng -1
            if (s == t) return 0;
          }
          return 1;
        }
        ```

    === "Python"
        ```python
        def millerRabin(n):
            if n < 3 or n % 2 == 0:
                return n == 2
            if n % 3 == 0:
                return n == 3
            u, t = n - 1, 0
            while u % 2 == 0:
                u = u // 2
                t = t + 1
            # test_time là số lần kiểm tra; nên đặt không nhỏ hơn 8
            # để bảo đảm độ chính xác, nhưng cũng không nên quá lớn để tránh chậm
            for i in range(test_time):
                # 0, 1, n-1 có thể vượt qua trực tiếp; a nằm trong [2, n-2]
                a = random.randint(2, n - 2)
                v = pow(a, u, n)
                if v == 1:
                    continue
                s = 0
                while s < t:
                    if v == n - 1:
                        break
                    v = v * v % n
                    s = s + 1
                # Nếu gặp căn không tầm thường thì không break sớm và chạy đến s == t
                # Nếu kiểm tra Fermat không đạt, trước s == t thì v sẽ không bằng -1
                if s == t:
                    return False
            return True
        ```

Có thể chứng minh[^millerrabinproof] rằng với hợp số lẻ $n > 9$, xác suất để
$n$ vượt qua kiểm tra Miller-Rabin với một cơ sở $a$ chọn ngẫu nhiên không quá
$1/4$. Do đó, sau khi chọn ngẫu nhiên $k$ cơ sở, xác suất vẫn nhận nhầm hợp số
là số nguyên tố không vượt quá $1/4^k$.

??? note "Chứng minh"
    Đặt $n-1=u2^t$, trong đó $u$ là số lẻ và $t$ là số nguyên dương. Việc số
    nguyên $n$ vượt qua kiểm tra Miller-Rabin với cơ sở $a$ có nghĩa là

    $$
    a^u\equiv 1{\textstyle\pmod n},\text{ hoặc }a^{u2^i}\equiv -1{\textstyle\pmod n}\text{ với một số }0\le i < t.
    $$

    Gọi $S$ là tập các lớp đồng dư của những $a$ như vậy. Cần chứng minh

    $$
    |S| \le \dfrac14\varphi(n).
    $$

    Trong đó $\varphi(n)$ là [hàm Euler](./euler-totient.md). Chứng minh gồm ba
    bước.

    **Bước 1**: Gọi $\ell$ là số nguyên dương lớn nhất sao cho
    $2^\ell \mid p-1$ đúng với mọi thừa số nguyên tố $p$ của $n$. Khi đó có thể
    chứng minh

    $$
    S\subseteq S' = \{a\bmod n:a^{u2^{\ell-1}}\equiv\pm 1{\textstyle\pmod n}\}.
    $$

    Phần tử $a$ trong tập $S$ chỉ có hai khả năng. Nếu $a^u\equiv 1\pmod n$, rõ
    ràng $a^{u2^{\ell-1}}\equiv 1\pmod n$ cũng đúng, tức $a\in S'$. Nếu tồn tại
    $0\le i < t$ sao cho $a^{u2^i}\equiv -1\pmod n$, thì với mọi thừa số nguyên
    tố $p\mid n$ đều có $a^{u2^i}\equiv-1\pmod p$. Gọi $\delta_p(a)$ là
    [cấp](./primitive-root.md#bậc) của $a$ theo modulo $p$. Khi đó
    $\delta_p(a)\mid u2^{i+1}$ nhưng $\delta_p(a)\nmid u2^{i}$, nên trong phân
    tích thừa số nguyên tố của $\delta_p(a)$, số mũ của $2$ đúng bằng $i+1$, vì
    vậy $2^{i+1}\mid\delta_p(a)$. Theo định lý nhỏ Fermat,
    $\delta_p(a)\mid p-1$, do đó $2^{i+1}\mid p-1$. Điều này đúng với mọi thừa
    số nguyên tố $p$ của $n$, suy ra $i+1\le\ell$. Vậy
    $a^{u2^{\ell-1}} = (a^{u2^i})^{2^{\ell-1-i}} \equiv \pm 1 \pmod n$, nên
    cũng có $a\in S'$. Tổng hợp hai khả năng, thu được $S\subseteq S'$.

    **Bước 2**: Tính kích thước $|S'|$.

    Giả sử $n$ có phân tích thừa số nguyên tố
    $n = p_1^{e_1}p_2^{e_2}\cdots p_k^{e_k}$. Theo
    [định lý thặng dư Trung Hoa](./crt.md), điều kiện
    $a^{u2^{\ell - 1}}\equiv 1\pmod n$ tương đương với
    $a^{u2^{\ell - 1}}\equiv 1\pmod{p_i^{e_i}}$ đúng với mọi $p_i^{e_i}$. Vì
    [căn nguyên thủy](./primitive-root.md#căn-nguyên-thủy) modulo lũy thừa
    của số nguyên tố lẻ $p_i^{e_i}$ luôn tồn tại, số
    [nghiệm](./residue.md#tính-chất) của phương trình đồng dư
    $a^{u2^{\ell - 1}}\equiv 1\pmod{p_i^{e_i}}$ là

    $$
    \gcd(u2^{\ell-1},p_i^{e_i-1}(p_i-1)) = \gcd(u2^{\ell-1},p_i-1) = 2^{\ell-1}\gcd(u,p_i-1).
    $$

    Đẳng thức đầu tiên đúng vì $u$ là ước của $n-1$, nên không thể là bội của
    $p_i$; đẳng thức thứ hai đúng theo cách chọn $\ell$. Vì vậy, theo định lý
    thặng dư Trung Hoa, số nghiệm của phương trình đồng dư
    $a^{u2^{\ell-1}}\equiv 1\pmod n$ là

    $$
    \prod_{p\mid n}2^{\ell-1}\gcd(u,p-1).
    $$

    Tương tự, điều kiện $a^{u2^{\ell - 1}}\equiv -1\pmod n$ tương đương với
    $a^{u2^{\ell - 1}}\equiv -1\pmod{p_i^{e_i}}$ đúng với mọi $p_i^{e_i}$. Với
    mỗi thừa số $p_i^{e_i}$, điều kiện
    $a^{u2^{\ell - 1}}\equiv -1\pmod{p_i^{e_i}}$ tương đương với
    $a^{u2^{\ell - 1}}\not\equiv 1\pmod{p_i^{e_i}}$ và
    $a^{u2^{\ell}}\equiv 1\pmod{p_i^{e_i}}$ cùng đúng. Tương tự phần trên, có
    thể tính số nghiệm của phương trình đồng dư
    $a^{u2^{\ell}}\equiv 1\pmod{p_i^{e_i}}$ là $2^{\ell}\gcd(u,p_i-1)$, do đó
    số nghiệm của phương trình đồng dư
    $a^{u2^{\ell - 1}}\equiv -1\pmod{p_i^{e_i}}$ cũng bằng

    $$
    2^{\ell}\gcd(u,p_i-1) - 2^{\ell-1}\gcd(u,p_i-1) = 2^{\ell-1}\gcd(u,p_i-1).
    $$

    Lại áp dụng định lý thặng dư Trung Hoa, số nghiệm của phương trình đồng dư
    $a^{u2^{\ell - 1}}\equiv -1\pmod n$ bằng

    $$
    \prod_{p\mid n}2^{\ell-1}\gcd(u,p-1).
    $$

    Vì vậy, gộp hai trường hợp lại, có

    $$
    |S'| = 2\prod_{p\mid n}2^{\ell-1}\gcd(u,p-1).
    $$

    **Bước 3**: Chứng minh $|S'|\le\varphi(n)/4$.

    Kết hợp công thức của hàm Euler $\varphi(n)=\prod_ip_i^{e_i-1}(p_i-1)$,
    có

    $$
    \dfrac{\varphi(n)}{|S'|} = \dfrac{1}{2}\prod_ip_i^{e_i-1}\dfrac{p_i-1}{2^{\ell-1}\gcd(u,p_i-1)}.
    $$

    Với mọi $i$, thừa số tương ứng
    $p_i^{e_i-1}\dfrac{p_i-1}{2^{\ell-1}\gcd(u,p_i-1)}$ đều là số chẵn, nên
    $\varphi(n)/|S'|$ là một số nguyên. Giả sử $|S'|\le\varphi(n)/4$ không đúng.
    Khi đó tất yếu $\varphi(n)/|S'|=1,2,3$, tức

    $$
    \prod_ip_i^{e_i-1}\dfrac{p_i-1}{2^{\ell-1}\gcd(u,p_i-1)} = 2,4,6.
    $$

    Vì mọi thừa số trong tích đều là số chẵn, tích này hoặc chỉ có một thừa số
    và thừa số đó bằng $2,4,6$, hoặc chỉ có hai thừa số và cả hai đều bằng $2$.

    Trước hết xét trường hợp có hai thừa số. Khi đó hai thừa số đều không có
    thừa số nguyên tố lẻ, nên $p_i^{e_i-1}=1$, tức $n$ không có thừa số bình
    phương. Giả sử $n=p_1p_2$ với $p_1<p_2$ đều là số nguyên tố. Hai thừa số đều
    bằng $2$, nên luôn có $p_i-1=2^{\ell}\gcd(u,p_i-1)$. Do đó
    $p_i=1+2^\ell m_i$, trong đó $m_i$ là số lẻ và $m_i\mid u$. Lấy
    $p_1p_2=n=1+u2^t$ modulo $m_1$ được $p_1p_2\equiv 1\pmod{m_1}$, vì thế
    $p_2\equiv 1\pmod{m_1}$, suy ra $m_1\mid m_2$. Chiều ngược lại cũng đúng.
    Vậy $m_1=m_2$, tức $p_1=p_2$, mâu thuẫn với $p_1<p_2$. Trường hợp này không
    thể xảy ra.

    Cuối cùng xét trường hợp chỉ có một thừa số, tức hợp số $n=p^e$ với $e>1$.
    Khi đó tất yếu $p^{e-1}\mid 2,4,6$. Trường hợp duy nhất là $p=3,e=2$, tức
    $n=9$, mâu thuẫn với giả thiết của mệnh đề. Trường hợp này cũng không thể
    xảy ra.

    Tổng hợp mọi trường hợp, $|S'|\le\varphi(n)/4$ đúng.

    Kết hợp ba bước trên, $|S|\le |S'|\le \varphi(n)/4$ đúng với mọi hợp số lẻ
    $n>9$.

Ngoài ra, nếu giả sử
[giả thuyết Riemann tổng quát](https://en.wikipedia.org/wiki/Generalized_Riemann_hypothesis)
(generalized Riemann hypothesis, GRH) đúng, thì với số $n$ chỉ cần kiểm tra tất
cả các số nguyên trong $[2, \min\{n-2, \lfloor 2\ln^2 n \rfloor\}]$ là có thể
**xác định tất định** tính nguyên tố của $n$.[^deterministic-proof]

Trong phạm vi OI, thường cần kiểm tra tính nguyên tố của các số trong khoảng
$[1, 2^{64})$. Với khoảng $[1, 2^{32})$, chọn ba số $\{2, 7, 61\}$ làm cơ sở
cho kiểm tra Miller-Rabin là đủ để xác định tất định tính nguyên tố; với khoảng
$[1, 2^{64})$, chọn bảy số
$\{2, 325, 9375, 28178, 450775, 9780504, 1795265022\}$ làm cơ sở là đủ để xác
định tất định tính nguyên tố.[^witnesses]

Cũng có thể chọn $\{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37\}$, tức $12$
số nguyên tố đầu tiên, để kiểm tra các số trong khoảng $[1, 2^{64})$.

Lưu ý nếu dùng các số $a$ trong dãy trên làm cơ sở để xét tính nguyên tố của
$n$:

-   Phải thử hết tất cả các số, không chỉ chọn những số nhỏ hơn $n$;
-   Thay $a$ bằng $a \bmod n$;
-   Nếu $a \equiv 0 \pmod n$ hoặc $a \equiv \pm 1 \pmod n$, thì vòng kiểm tra
    đó vượt qua trực tiếp.

<span id="số-phản-nguyên-tố"></span>
## Số phản nguyên tố

Theo tên gọi, số nguyên tố là số chỉ có hai ước, còn số phản nguyên tố là số có
nhiều ước nhất, và nếu số ước bằng nhau thì lấy giá trị nhỏ nhất. Vì vậy, số
phản nguyên tố được định nghĩa tương đối với một tập hợp.

Một định nghĩa trực quan là: trong một tập số nguyên dương, số có nhiều ước nhất
và giá trị nhỏ nhất là số phản nguyên tố.

???+ abstract "Số phản nguyên tố"
    Với một số nguyên dương $n$, nếu mọi số nguyên dương nhỏ hơn $n$ đều có số
    ước nhỏ hơn số ước của $n$, thì $n$ được gọi là **số phản nguyên tố**
    (anti-prime, a.k.a., highly composite numbers).

???+ warning "Lưu ý"
    Cần phân biệt với [emirp](https://en.wikipedia.org/wiki/Emirp), là số
    nguyên tố mà khi đảo ngược các chữ số thì thu được một số nguyên tố khác (ví
    dụ 149 và 941 đều là emirp, còn 101 không phải emirp).

<span id="quá-trình"></span>
### Quá trình

Vậy tính số phản nguyên tố như thế nào?

Trước hết, vì cần tính số ước nên cần phân tích thừa số nguyên tố. Viết $n$ dưới
dạng $n=p_{1}^{k_{1}}p_{2}^{k_{2}} \cdots p_{n}^{k_{n}}$, trong đó $p$ là số
nguyên tố và $k$ là số mũ của nó. Khi đó tổng số ước là
$(k_1+1) \times (k_2+1) \times (k_3+1) \cdots \times (k_n+1)$.

Nhưng độ phức tạp của phân tích thừa số nguyên tố rất cao, và kết quả
của số trước không dùng lại được cho số sau. Vì vậy cần đổi cách làm.

Cần quan sát đặc điểm của số phản nguyên tố.

1.  Số phản nguyên tố là tích của các lũy thừa của các số nguyên tố
    liên tiếp bắt đầu từ $2$.

2.  Số mũ của số nguyên tố có giá trị nhỏ hơn phải lớn hơn hoặc bằng số mũ của
    số nguyên tố có giá trị lớn hơn. Tức trong
    $n=p_{1}^{k_{1}}p_{2}^{k_{2}} \cdots p_{n}^{k_{n}}$ có
    $k_1 \geq k_2 \geq k_3 \geq \cdots \geq k_n$.

Giải thích:

1.  Nếu không phải các số nguyên tố liên tiếp bắt đầu từ $2$, thì giữ nguyên số
    mũ và thay một số nguyên tố bằng số nguyên tố nhỏ hơn sẽ giữ nguyên số ước
    nhưng làm giá trị $n$ nhỏ đi. Khi đổi đến dãy các số nguyên tố liên tiếp
    bắt đầu từ $2$, giá trị $n$ là nhỏ nhất.

2.  Nếu số mũ của số nguyên tố nhỏ hơn lại nhỏ hơn số mũ của số nguyên tố lớn
    hơn, thì đổi chỗ hai số nguyên tố đó (giữ nguyên số mũ) sẽ giữ nguyên số
    ước của $n$ nhưng làm giá trị $n$ nhỏ đi.

Còn hai câu hỏi:

1.  Với $n$ cho trước, cần liệt kê đến số nguyên tố nào?

    Trường hợp cực đoan nhất chỉ là $n=p_{1}p_{2} \cdots p_{n}$, nên chỉ cần
    nhân liên tiếp các số nguyên tố đến khi tích vừa không vượt quá $n$. Nếu
    liệt kê đến số nguyên tố lớn hơn nữa, nghĩa là bắt buộc có một số nguyên tố
    trước đó có số mũ bằng $0$, khi đó không thể tạo thành số phản nguyên tố.

2.  Cần liệt kê số mũ đến bao nhiêu?

    Xét trường hợp cực đoan: khi một lũy thừa nào đó của số nguyên tố nhỏ nhất
    đã lớn hơn $n$ cho trước (giá trị lớn nhất của $n$), thì nếu khai triển
    thành các dạng khác, số mũ lớn nhất sẽ nhỏ hơn số mũ đó. Trong
    trường hợp cực đoan $n$ là lũy thừa của $2$, chỉ cần liệt kê đến
    $\lfloor\log_2 n\rfloor$.

Với các chi tiết trên, cài đặt cụ thể ra sao?

Có thể xem trạng thái trước khi đi đến mỗi số nguyên tố như một nút gốc của
cây, rồi tìm dần theo từng tầng. Khi nào dừng?

1.  Giá trị hiện tại đã lớn hơn giá trị cần xét;

2.  Thừa số đang liệt kê không còn cần dùng;

3.  Số ước hiện tại đã lớn hơn số ước mong muốn;

4.  Số ước hiện tại vừa bằng số ước mong muốn; khi đó xét có cần cập nhật
    $\mathit{ans}$ nhỏ nhất hay không.

Sau đó trong DFS, liên tục liệt kê số mũ theo từng tầng và đệ quy xuống dưới.

<span id="bài-tập-ví-dụ"></span>
### Bài tập ví dụ

???+ example "[Codeforces 27E. A number with a given number of divisors](https://codeforces.com/problemset/problem/27/E)"
    Tìm số tự nhiên nhỏ nhất có số lượng ước cho trước. Đáp án được bảo đảm
    không vượt quá $10^{18}$.

??? note "Ý tưởng giải"
    Với dạng bài này, chỉ cần lấy số ước làm điều kiện dừng của DFS, liên tục
    cập nhật giá trị nhỏ nhất tìm được.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/prime/prime_1.cpp"
    ```

???+ example "[ZOJ 2562 More Divisors](https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?problemSetProblemId=91827366061)"
    Tìm số không vượt quá $n$ có nhiều ước nhất.

??? note "Ý tưởng giải"
    Ý tưởng giống trên, chỉ cần sửa điều kiện dừng của DFS. Lưu ý phạm vi dữ
    liệu của bài này: số nguyên 32 bit có thể bị tràn.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/prime/prime_2.cpp"
    ```

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

1.  Rui-Juan Jing, Marc Moreno-Maza, Delaram Talaashrafi, "[Complexity Estimates for Fourier-Motzkin Elimination](https://arxiv.org/abs/1811.01510)", Journal of Functional Programming 16:2 (2006) pp 197-217.
2.  [Phần lý thuyết số, bài 1: số nguyên tố và kiểm tra tính nguyên tố](http://www.matrix67.com/blog/archives/234)
3.  [Ghi chú học Miller-Rabin và Pollard-Rho - Bill Yang's Blog](https://blog.bill.moe/miller-rabin-notes/)
4.  [Primality test - Wikipedia](https://en.wikipedia.org/wiki/Primality_test)
5.  [Fermat pseudoprime - Wikipedia](https://en.wikipedia.org/wiki/Fermat_pseudoprime)
6.  [Ghi chú thuật toán của Taozi: giải thích số phản nguyên tố (acm/OI)](https://zhuanlan.zhihu.com/p/41759808)
7.  [The Rabin-Miller Primality Test](http://home.sandiego.edu/~dhoffoss/teaching/cryptography/10-Rabin-Miller.pdf)
8.  [Highly composite number - Wikipedia](https://en.wikipedia.org/wiki/Highly_composite_number)

[^inf-fermat-pp]: Định lý 1 trong Pomerance, Carl, John L. Selfridge, and Samuel S. Wagstaff. "The pseudoprimes to 25⋅ 10⁹." Mathematics of Computation 35, no. 151 (1980): 1003-1026 cho thấy với cơ sở $a$ cố định, cũng có vô hạn hợp số vượt qua kiểm tra Miller-Rabin mạnh hơn.

[^millerrabinproof]: Kết quả này và chứng minh của nó tham khảo mục 3.5 trong Crandall, Richard, and Carl Pomerance. Prime numbers: a computational perspective. New York, NY: Springer New York, 2005.

[^deterministic-proof]: Bach, Eric , "[Explicit bounds for primality testing and related problems](https://doi.org/10.2307%2F2008811)", Mathematics of Computation, 55:191 (1990) pp 355–380.

[^witnesses]: Xem thêm các kết quả tương tự tại [Deterministic variant of the Miller-Rabin primality test](https://miller-rabin.appspot.com/#).
