author: Ir1d, Tiphereth-A, c-forrest, Xeonacid, Enter-tainer, StudyingFather, iamtwz, ksyx, Marcythm, MegaOwIer, 383494, Alpacabla, HeRaNO, abc1763613206, alphagocc, Backl1ght, CCXXXI, drkelo, Early0v0, Great-designer, greyqz, GuanghaoYe, H-J-Granger, HHH2309, isdanni, kenlig, lazyasn, Menci, ouuan, r-value, shawlleyw, shopee-jin, shuzhouliu, Siger Young, TrisolarisHD, untitledunrevised, void-mian, Voileexperiments, weilycoder, xtlsoft, yusancky, YuzhenQin1, sun2snow

Định nghĩa số nguyên tố và hợp số xem tại [cơ sở lý thuyết số](./basic.md).

Hàm đếm số nguyên tố: số lượng số nguyên tố nhỏ hơn hoặc bằng $x$, ký hiệu là
$\pi(x)$. Khi $x$ tăng, ta có xấp xỉ: $\pi(x) \sim \dfrac{x}{\ln(x)}$.

<span id="&#x7D20;&#x6027;&#x6D4B;&#x8BD5;"></span>
## Kiểm tra tính nguyên tố

**Kiểm tra tính nguyên tố** (Primality test) dùng để xác định một số tự nhiên
cho trước có phải là số nguyên tố hay không.

Có hai loại kiểm tra tính nguyên tố:

1.  Kiểm tra tất định: xác định chắc chắn một số có phải số nguyên tố hay
    không. Các ví dụ thường gặp gồm phép thử chia, kiểm tra Lucas-Lehmer và
    chứng minh tính nguyên tố bằng đường cong elliptic.
2.  Kiểm tra xác suất: thường nhanh hơn rất nhiều so với kiểm tra tất định,
    nhưng có khả năng, dù rất nhỏ, nhận nhầm [hợp số](../number-theory/basic.md#%E7%B4%A0%E6%95%B0%E4%B8%8E%E5%90%88%E6%95%B0)
    thành số nguyên tố; chiều ngược lại thì không xảy ra. Vì vậy, những số vượt
    qua kiểm tra xác suất được gọi là **số có khả năng nguyên tố** cho đến khi
    tính nguyên tố của chúng được chứng minh một cách tất định. Những số vượt
    qua kiểm tra nhưng thực ra là hợp số được gọi là **giả nguyên tố**. Có
    nhiều kiểu giả nguyên tố cụ thể, thường gặp nhất là giả nguyên tố Fermat,
    tức các hợp số thỏa mãn định lý nhỏ Fermat. Ví dụ thường gặp của kiểm tra
    xác suất là kiểm tra Miller-Rabin.

<span id="&#x8BD5;&#x9664;&#x6CD5;"></span>
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

Cách này rất chắc chắn, nhưng có cần kiểm tra từng số hay không?

Dễ thấy rằng: nếu $x$ là ước của $a$ thì $\frac{a}{x}$ cũng là ước của $a$.

Kết luận này cho biết với mỗi cặp $(x, \frac{a}{x} )$, chỉ cần kiểm tra một
trong hai số. Để thuận tiện, ta chỉ xét số nhỏ hơn trong mỗi cặp. Không khó
thấy tất cả các số nhỏ hơn đó đều nằm trong khoảng $[1, \sqrt{a}]$.

Vì $1$ chắc chắn là ước nên ta không cần kiểm tra nó.

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

<span id="fermat-&#x7D20;&#x6027;&#x6D4B;&#x8BD5;"></span>
### Kiểm tra tính nguyên tố Fermat

**Kiểm tra tính nguyên tố Fermat** là phép kiểm tra tính nguyên tố xác suất đơn
giản nhất.

Từ [định lý nhỏ Fermat](./fermat.md#%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86),
ta có một ý tưởng để kiểm tra số nguyên tố:

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

Nếu $a^{n−1} \equiv 1 \pmod n$ nhưng $n$ không phải số nguyên tố, ta gọi $n$
là **giả nguyên tố Fermat** có cơ số $a$. Trong thực tế, khi
$a^{n−1} \equiv 1 \pmod n$, $n$ thường là số nguyên tố. Tuy nhiên có phản ví
dụ: với $n = 341$ và $a = 2$, tuy $2^{340}\equiv 1 {\pmod {341}}$, nhưng
$341 = 11 \cdot 31$ là hợp số. Thực ra, với mỗi cơ số cố định $a$, có vô hạn
phản ví dụ như vậy[^inf-fermat-pp].

Vì kiểm tra Fermat không bảo đảm đúng với một cơ số đơn lẻ, một ý tưởng tự
nhiên là kiểm tra nhiều cơ số. Tuy nhiên, ngay cả khi kiểm tra tất cả cơ số $a$
nguyên tố cùng nhau với $n$, vẫn không thể bảo đảm $n$ là số nguyên tố. Nói cách
khác, mệnh đề đảo của định lý nhỏ Fermat không đúng: ngay cả khi với mọi
$a\perp n$ đều có $a^{n-1}\equiv 1\pmod n$, $n$ vẫn có thể không phải số nguyên
tố. Các số như vậy được gọi là [số Carmichael](./primitive-root.md#carmichael-%E6%95%B0),
và cũng có vô hạn số. Điều này buộc ta tìm phép kiểm tra tính nguyên tố chặt
chẽ hơn.

<span id="miller–rabin-&#x7D20;&#x6027;&#x6D4B;&#x8BD5;"></span>
### Kiểm tra tính nguyên tố Miller-Rabin

**Kiểm tra tính nguyên tố Miller-Rabin** (Miller-Rabin primality test) là một
phương pháp xác định số nguyên tố tốt hơn. Nó do Miller và Rabin cải tiến từ
kiểm tra Fermat. Giống các kiểm tra số nguyên tố xác suất khác, nó chỉ có thể
phát hiện giả nguyên tố. Nếu cần chắc chắn là số nguyên tố, phải dùng các thuật
toán tất định chậm hơn nhiều. Tuy vậy, trên thực tế chưa biết số nào vượt qua
Miller-Rabin và các kiểm tra xác suất mạnh khác nhưng lại là hợp số, nên ta có
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
    Theo [định lý Lagrange](./congruence-equation.md#%E5%AE%9A%E7%90%86-3lagrange-%E5%AE%9A%E7%90%86),
    đây là tất cả nghiệm của phương trình.

Kết hợp định lý nhỏ Fermat với định lý căn bậc hai, ta thu được kiểm tra tính
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

Ta thu được phiên bản Miller-Rabin khá đúng sau (từ fjzzq2002):

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

??? note "Chung minh"
    Dat $n-1=u2^t$, trong do $u$ la so le va $t$ la so nguyen duong. Viec so nguyen $n$ vuot qua kiem tra Miller-Rabin voi co so $a$ co nghia la
    
    $$
    a^u\equiv 1{\textstyle\pmod n},\text{ or }a^{u2^i}\equiv -1{\textstyle\pmod n}\text{ for some }0\le i < t.
    $$
    
    Goi $S$ la tap cac lop dong du cua nhung $a$ nhu vay. Can chung minh
    
    $$
    |S| \le \dfrac14\varphi(n).
    $$
    
    Trong do $\varphi(n)$ la [ham Euler](./euler-totient.md). Chung minh gom ba buoc.
    
    **Buoc 1**: Goi $\ell$ la so nguyen duong lon nhat sao cho $2^\ell \mid p-1$ dung voi moi thua so nguyen to $p$ cua $n$. Khi do co the chung minh
    
    $$
    S\subseteq S' = \{a\bmod n:a^{u2^{\ell-1}}\equiv\pm 1{\textstyle\pmod n}\}.
    $$
    
    Phan tu $a$ trong tap $S$ chi co hai kha nang. Neu $a^u\equiv 1\pmod n$, ro rang $a^{u2^{\ell-1}}\equiv 1\pmod n$ cung dung, tuc $a\in S'$. Neu ton tai $0\le i < t$ sao cho $a^{u2^i}\equiv -1\pmod n$, thi voi moi thua so nguyen to $p\mid n$ deu co $a^{u2^i}\equiv-1\pmod p$. Goi $\delta_p(a)$ la [cap](./primitive-root.md#%E9%98%B6) cua $a$ theo modulo $p$. Khi do ro rang $\delta_p(a)\mid u2^{i+1}$ nhung $\delta_p(a)\nmid u2^{i}$, nen trong phan tich thua so nguyen to cua $\delta_p(a)$, so mu cua $2$ dung bang $i+1$, vi vay $2^{i+1}\mid\delta_p(a)$. Theo dinh ly nho Fermat, $\delta_p(a)\mid p-1$, do do $2^{i+1}\mid p-1$. Dieu nay dung voi moi thua so nguyen to $p$ cua $n$, suy ra $i+1\le\ell$. Vay $a^{u2^{\ell-1}} = (a^{u2^i})^{2^{\ell-1-i}} \equiv \pm 1 \pmod n$, nen cung co $a\in S'$. Tong hop hai kha nang, ta duoc $S\subseteq S'$.
    
    **Buoc 2**: Tinh kich thuoc $|S'|$.
    
    Gia su $n$ co phan tich thua so nguyen to $n = p_1^{e_1}p_2^{e_2}\cdots p_k^{e_k}$. Theo [dinh ly thang du Trung Hoa](./crt.md), dieu kien $a^{u2^{\ell - 1}}\equiv 1\pmod n$ tuong duong voi $a^{u2^{\ell - 1}}\equiv 1\pmod{p_i^{e_i}}$ dung voi moi $p_i^{e_i}$. Vi [can nguyen thuy](./primitive-root.md#%E5%8E%9F%E6%A0%B9) modulo luy thua cua so nguyen to le $p_i^{e_i}$ luon ton tai, so [nghiem](./residue.md#%E6%80%A7%E8%B4%A8) cua phuong trinh dong du $a^{u2^{\ell - 1}}\equiv 1\pmod{p_i^{e_i}}$ la
    
    $$
    \gcd(u2^{\ell-1},p_i^{e_i-1}(p_i-1)) = \gcd(u2^{\ell-1},p_i-1) = 2^{\ell-1}\gcd(u,p_i-1).
    $$
    
    Dang thuc dau tien dung vi $u$ la uoc cua $n-1$, nen khong the la boi cua $p_i$; dang thuc thu hai dung theo cach chon $\ell$. Vi vay, theo dinh ly thang du Trung Hoa, so nghiem cua phuong trinh dong du $a^{u2^{\ell-1}}\equiv 1\pmod n$ la
    
    $$
    \prod_{p\mid n}2^{\ell-1}\gcd(u,p-1).
    $$
    
    Tuong tu, dieu kien $a^{u2^{\ell - 1}}\equiv -1\pmod n$ tuong duong voi $a^{u2^{\ell - 1}}\equiv -1\pmod{p_i^{e_i}}$ dung voi moi $p_i^{e_i}$. Voi moi thua so $p_i^{e_i}$, dieu kien $a^{u2^{\ell - 1}}\equiv -1\pmod{p_i^{e_i}}$ tuong duong voi $a^{u2^{\ell - 1}}\not\equiv 1\pmod{p_i^{e_i}}$ va $a^{u2^{\ell}}\equiv 1\pmod{p_i^{e_i}}$ cung dung. Tuong tu phan tren, co the tinh so nghiem cua phuong trinh dong du $a^{u2^{\ell}}\equiv 1\pmod{p_i^{e_i}}$ la $2^{\ell}\gcd(u,p_i-1)$, do do so nghiem cua phuong trinh dong du $a^{u2^{\ell - 1}}\equiv -1\pmod{p_i^{e_i}}$ cung bang
    
    $$
    2^{\ell}\gcd(u,p_i-1) - 2^{\ell-1}\gcd(u,p_i-1) = 2^{\ell-1}\gcd(u,p_i-1).
    $$
    
    Lai ap dung dinh ly thang du Trung Hoa, so nghiem cua phuong trinh dong du $a^{u2^{\ell - 1}}\equiv -1\pmod n$ bang
    
    $$
    \prod_{p\mid n}2^{\ell-1}\gcd(u,p-1).
    $$
    
    Vi vay, gop hai truong hop lai, ta co
    
    $$
    |S'| = 2\prod_{p\mid n}2^{\ell-1}\gcd(u,p-1).
    $$
    
    **Buoc 3**: Chung minh $|S'|\le\varphi(n)/4$.
    
    Ket hop cong thuc cua ham Euler $\varphi(n)=\prod_ip_i^{e_i-1}(p_i-1)$, ta co
    
    $$
    \dfrac{\varphi(n)}{|S'|} = \dfrac{1}{2}\prod_ip_i^{e_i-1}\dfrac{p_i-1}{2^{\ell-1}\gcd(u,p_i-1)}.
    $$
    
    Voi moi $i$, thua so tuong ung $p_i^{e_i-1}\dfrac{p_i-1}{2^{\ell-1}\gcd(u,p_i-1)}$ deu la so chan, nen $\varphi(n)/|S'|$ la mot so nguyen. Gia su $|S'|\le\varphi(n)/4$ khong dung. Khi do tat yeu $\varphi(n)/|S'|=1,2,3$, tuc
    
    $$
    \prod_ip_i^{e_i-1}\dfrac{p_i-1}{2^{\ell-1}\gcd(u,p_i-1)} = 2,4,6.
    $$
    
    Vi moi thua so trong tich deu la so chan, tich nay hoac chi co mot thua so va thua so do bang $2,4,6$, hoac chi co hai thua so va ca hai deu bang $2$.
    
    Truoc het xet truong hop co hai thua so. Khi do hai thua so deu khong co thua so nguyen to le, nen $p_i^{e_i-1}=1$, tuc $n$ khong co thua so binh phuong. Gia su $n=p_1p_2$ voi $p_1<p_2$ deu la so nguyen to. Hai thua so deu bang $2$, nen luon co $p_i-1=2^{\ell}\gcd(u,p_i-1)$. Do do $p_i=1+2^\ell m_i$, trong do $m_i$ la so le va $m_i\mid u$. Lay $p_1p_2=n=1+u2^t$ modulo $m_1$ duoc $p_1p_2\equiv 1\pmod{m_1}$, vi the $p_2\equiv 1\pmod{m_1}$, suy ra $m_1\mid m_2$. Chieu nguoc lai cung dung. Vay $m_1=m_2$, tuc $p_1=p_2$, mau thuan voi $p_1<p_2$. Truong hop nay khong the xay ra.
    
    Cuoi cung xet truong hop chi co mot thua so, tuc hop so $n=p^e$ voi $e>1$. Khi do tat yeu $p^{e-1}\mid 2,4,6$. Truong hop duy nhat la $p=3,e=2$, tuc $n=9$, mau thuan voi gia thiet cua menh de. Truong hop nay cung khong the xay ra.
    
    Tong hop moi truong hop, $|S'|\le\varphi(n)/4$ dung.
    
    Ket hop ba buoc tren, $|S|\le |S'|\le \varphi(n)/4$ dung voi moi hop so le $n>9$.

Ngoai ra, neu gia su [gia thuyet Riemann tong quat](https://en.wikipedia.org/wiki/Generalized_Riemann_hypothesis) (generalized Riemann hypothesis, GRH) dung, thi voi so $n$ chi can kiem tra tat ca cac so nguyen trong $[2, \min\{n-2, \lfloor 2\ln^2 n \rfloor\}]$ la co the **xac dinh tat dinh** tinh nguyen to cua $n$.[^deterministic-proof]

Trong pham vi OI, ta thuong kiem tra tinh nguyen to cua cac so trong khoang $[1, 2^{64})$. Voi khoang $[1, 2^{32})$, chon ba so $\{2, 7, 61\}$ lam co so cho kiem tra Miller-Rabin la du de xac dinh tat dinh tinh nguyen to; voi khoang $[1, 2^{64})$, chon bay so $\{2, 325, 9375, 28178, 450775, 9780504, 1795265022\}$ lam co so la du de xac dinh tat dinh tinh nguyen to.[^witnesses]

Cung co the chon $\{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37\}$, tuc $12$ so nguyen to dau tien, de kiem tra cac so trong khoang $[1, 2^{64})$.

Luu y neu dung cac so $a$ trong day tren lam co so de xet tinh nguyen to cua $n$:

-   Phai thu het tat ca cac so, khong chi chon nhung so nho hon $n$;
-   Thay $a$ bang $a \bmod n$;
-   Neu $a \equiv 0 \pmod n$ hoac $a \equiv \pm 1 \pmod n$, thi vong kiem tra do vuot qua truc tiep.

<span id="&#x53CD;&#x7D20;&#x6570;"></span>
## So phan nguyen to

Theo ten goi, so nguyen to la so chi co hai uoc, con so phan nguyen to la so co nhieu uoc nhat, va neu so uoc bang nhau thi lay gia tri nho nhat. Vi vay, so phan nguyen to duoc dinh nghia tuong doi voi mot tap hop.

Mot dinh nghia truc quan la: trong mot tap so nguyen duong, so co nhieu uoc nhat va gia tri nho nhat la so phan nguyen to.

???+ abstract "So phan nguyen to"
    Voi mot so nguyen duong $n$, neu moi so nguyen duong nho hon $n$ deu co so uoc nho hon so uoc cua $n$, thi $n$ duoc goi la **so phan nguyen to** (anti-prime, a.k.a., highly compositive numbers).

???+ warning "Luu y"
    Can phan biet voi [emirp](https://en.wikipedia.org/wiki/Emirp), la so nguyen to ma khi dao nguoc cac chu so thi thu duoc mot so nguyen to khac (vi du 149 va 941 deu la emirp, con 101 khong phai emirp).

<span id="&#x8FC7;&#x7A0B;"></span>
### Qua trinh

Vay tinh so phan nguyen to nhu the nao?

Truoc het, vi can tinh so uoc nen can phan tich thua so nguyen to. Viet $n$ duoi dang $n=p_{1}^{k_{1}}p_{2}^{k_{2}} \cdots p_{n}^{k_{n}}$, trong do $p$ la so nguyen to va $k$ la so mu cua no. Khi do tong so uoc la $(k_1+1) \times (k_2+1) \times (k_3+1) \cdots \times (k_n+1)$.

Nhung do phuc tap cua phan tich thua so nguyen to ro rang rat cao, va ket qua cua so truoc khong dung lai duoc cho so sau. Vi vay can doi cach lam.

Hay quan sat dac diem cua so phan nguyen to.

1.  Số phản nguyên tố chắc chắn là tích của các lũy thừa của các số nguyên tố
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
    thành các dạng khác, số mũ lớn nhất chắc chắn nhỏ hơn số mũ đó. Trong
    trường hợp cực đoan $n$ là lũy thừa của $2$, chỉ cần liệt kê đến
    $\lfloor\log_2 n\rfloor$.

Đã có các chi tiết trên, ta cài đặt cụ thể ra sao?

Có thể xem trạng thái trước khi đi đến mỗi số nguyên tố như một nút gốc của
cây, rồi tìm dần theo từng tầng. Khi nào dừng?

1.  Giá trị hiện tại đã lớn hơn giá trị cần xét;

2.  Thừa số đang liệt kê không còn cần dùng;

3.  Số ước hiện tại đã lớn hơn số ước mong muốn;

4.  Số ước hiện tại vừa bằng số ước mong muốn; khi đó xét có cần cập nhật
    $\mathit{ans}$ nhỏ nhất hay không.

Sau đó trong DFS, liên tục liệt kê số mũ theo từng tầng và đệ quy xuống dưới.

<span id="&#x4F8B;&#x9898;"></span>
### Bài tập ví dụ

???+ example "[Codeforces 27E. A number with a given number of divisors](https://codeforces.com/problemset/problem/27/E)"
    Tìm số tự nhiên nhỏ nhất có số lượng ước cho trước. Đáp án được đảm bảo
    không vượt quá $10^{18}$.

??? note "Y tuong giai"
    Voi dang bai nay, chi can lay so uoc lam dieu kien dung cua dfs, lien tuc cap nhat gia tri nho nhat tim duoc.

??? note "Ma tham khao"
    ```cpp
    --8<-- "docs/math/code/prime/prime_1.cpp"
    ```

???+ example "[ZOJ 2562 More Divisors](https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?problemSetProblemId=91827366061)"
    Tim so khong vuot qua $n$ co nhieu uoc nhat.

??? note "Y tuong giai"
    Y tuong giong tren, chi can sua dieu kien dung cua dfs. Luu y pham vi du lieu cua bai nay: so nguyen 32 bit co the bi tran.

??? note "Ma tham khao"
    ```cpp
    --8<-- "docs/math/code/prime/prime_2.cpp"
    ```

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x6CE8;&#x91CA;"></span>
## Tai lieu tham khao va chu thich

1.  Rui-Juan Jing, Marc Moreno-Maza, Delaram Talaashrafi, "[Complexity Estimates for Fourier-Motzkin Elimination](https://arxiv.org/abs/1811.01510)", Journal of Functional Programming 16:2 (2006) pp 197-217.
2.  [Phan ly thuyet so, bai 1: so nguyen to va kiem tra tinh nguyen to](http://www.matrix67.com/blog/archives/234)
3.  [Ghi chu hoc Miller-Rabin va Pollard-Rho - Bill Yang's Blog](https://blog.bill.moe/miller-rabin-notes/)
4.  [Primality test - Wikipedia](https://en.wikipedia.org/wiki/Primality_test)
5.  [Fermat pseudoprime - Wikipedia](https://en.wikipedia.org/wiki/Fermat_pseudoprime)
6.  [Ghi chu thuat toan cua Taozi: giai thich so phan nguyen to (acm/OI)](https://zhuanlan.zhihu.com/p/41759808)
7.  [The Rabin-Miller Primality Test](http://home.sandiego.edu/~dhoffoss/teaching/cryptography/10-Rabin-Miller.pdf)
8.  [Highly composite number - Wikipedia](https://en.wikipedia.org/wiki/Highly_composite_number)

[^inf-fermat-pp]: Dinh ly 1 trong Pomerance, Carl, John L. Selfridge, and Samuel S. Wagstaff. "The pseudoprimes to 25⋅ 10⁹." Mathematics of Computation 35, no. 151 (1980): 1003-1026 cho thay voi co so $a$ co dinh, cung co vo han hop so vuot qua kiem tra Miller-Rabin manh hon.

[^millerrabinproof]: Ket qua nay va chung minh cua no tham khao muc 3.5 trong Crandall, Richard, and Carl Pomerance. Prime numbers: a computational perspective. New York, NY: Springer New York, 2005.

[^deterministic-proof]: Bach, Eric , "[Explicit bounds for primality testing and related problems](https://doi.org/10.2307%2F2008811)", Mathematics of Computation, 55:191 (1990) pp 355–380.

[^witnesses]: Xem them cac ket qua tuong tu tai [Deterministic variant of the Miller-Rabin primality test](https://miller-rabin.appspot.com/#).
