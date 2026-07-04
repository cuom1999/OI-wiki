author: Ir1d, Tiphereth-A, c-forrest, Xeonacid, Enter-tainer, StudyingFather, iamtwz, ksyx, Marcythm, MegaOwIer, 383494, Alpacabla, HeRaNO, abc1763613206, alphagocc, Backl1ght, CCXXXI, drkelo, Early0v0, Great-designer, greyqz, GuanghaoYe, H-J-Granger, HHH2309, isdanni, kenlig, lazyasn, Menci, ouuan, r-value, shawlleyw, shopee-jin, shuzhouliu, Siger Young, TrisolarisHD, untitledunrevised, void-mian, Voileexperiments, weilycoder, xtlsoft, yusancky, YuzhenQin1, sun2snow

Dinh nghia so nguyen to va hop so xem tai [co so ly thuyet so](./basic.md).

Ham dem so nguyen to: so luong so nguyen to nho hon hoac bang $x$, ky hieu la $\pi(x)$. Khi $x$ tang, ta co xap xi: $\pi(x) \sim \dfrac{x}{\ln(x)}$.

<span id="&#x7D20;&#x6027;&#x6D4B;&#x8BD5;"></span>
## Kiem tra tinh nguyen to

**Kiem tra tinh nguyen to** (Primality test) dung de xac dinh mot so tu nhien cho truoc co phai la so nguyen to hay khong.

Co hai loai kiem tra tinh nguyen to:

1.  Kiem tra tat dinh: xac dinh chac chan mot so co phai so nguyen to hay khong. Cac vi du thuong gap gom phep thu chia, kiem tra Lucas-Lehmer va chung minh tinh nguyen to bang duong cong elliptic.
2.  Kiem tra xac suat: thuong nhanh hon rat nhieu so voi kiem tra tat dinh, nhung co kha nang, du rat nho, nhan nham [hop so](../number-theory/basic.md#%E7%B4%A0%E6%95%B0%E4%B8%8E%E5%90%88%E6%95%B0) thanh so nguyen to; chieu nguoc lai thi khong xay ra. Vi vay, nhung so vuot qua kiem tra xac suat duoc goi la **so co kha nang nguyen to** cho den khi tinh nguyen to cua chung duoc chung minh mot cach tat dinh. Nhung so vuot qua kiem tra nhung thuc ra la hop so duoc goi la **gia nguyen to**. Co nhieu kieu gia nguyen to cu the, thuong gap nhat la gia nguyen to Fermat, tuc cac hop so thoa man dinh ly nho Fermat. Vi du thuong gap cua kiem tra xac suat la kiem tra Miller-Rabin.

<span id="&#x8BD5;&#x9664;&#x6CD5;"></span>
### Thu chia

Cach lam vét can tu nhien la liet ke moi so tu nho den lon va xem no co chia het hay khong.

???+ example "Cai dat tham khao"
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

Cach nay rat chac chan, nhung co can kiem tra tung so hay khong?

De thay rang: neu $x$ la uoc cua $a$ thi $\frac{a}{x}$ cung la uoc cua $a$.

Ket luan nay cho biet voi moi cap $(x, \frac{a}{x} )$, chi can kiem tra mot trong hai so. De thuan tien, ta chi xet so nho hon trong moi cap. Khong kho thay tat ca cac so nho hon do deu nam trong khoang $[1, \sqrt{a}]$.

Vi $1$ chac chan la uoc nen ta khong can kiem tra no.

???+ example "Cai dat tham khao"
    === "C++"
        ```cpp
        bool isPrime(int a) {
          if (a < 2) return 0;
          for (int i = 2; (long long)i * i <= a; ++i)  // tranh tran so
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
### Kiem tra tinh nguyen to Fermat

**Kiem tra tinh nguyen to Fermat** la phep kiem tra tinh nguyen to xac suat don gian nhat.

Tu [dinh ly nho Fermat](./fermat.md#%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86), ta co mot y tuong de kiem tra so nguyen to:

Y tuong co ban la lien tuc chon co so $a$ trong $[2, n-1]$ va kiem tra moi lan co $a^{n-1} \equiv 1 \pmod n$ hay khong.

???+ example "Cai dat tham khao"
    === "C++"
        ```cpp
        bool fermat(int n) {
          if (n < 3) return n == 2;
          // test_time la so lan kiem tra; nen dat khong nho hon 8
          // de bao dam do chinh xac, nhung cung khong nen qua lon de tranh cham
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
            # test_time la so lan kiem tra; nen dat khong nho hon 8
            # de bao dam do chinh xac, nhung cung khong nen qua lon de tranh cham
            for i in range(1, test_time + 1):
                a = random.randint(0, 32767) % (n - 2) + 2
                if quickPow(a, n - 1, n) != 1:
                    return False
            return True
        ```

Neu $a^{n−1} \equiv 1 \pmod n$ nhung $n$ khong phai so nguyen to, ta goi $n$ la **gia nguyen to Fermat** co co so $a$. Trong thuc te, khi $a^{n−1} \equiv 1 \pmod n$, $n$ thuong la so nguyen to. Tuy nhien co phan vi du: voi $n = 341$ va $a = 2$, tuy $2^{340}\equiv 1 {\pmod {341}}$, nhung $341 = 11 \cdot 31$ la hop so. Thuc ra, voi moi co so co dinh $a$, co vo han phan vi du nhu vay[^inf-fermat-pp].

Vi kiem tra Fermat khong bao dam dung voi mot co so don le, mot y tuong tu nhien la kiem tra nhieu co so. Tuy nhien, ngay ca khi kiem tra tat ca co so $a$ nguyen to cung nhau voi $n$, van khong the bao dam $n$ la so nguyen to. Noi cach khac, menh de dao cua dinh ly nho Fermat khong dung: ngay ca khi voi moi $a\perp n$ deu co $a^{n-1}\equiv 1\pmod n$, $n$ van co the khong phai so nguyen to. Cac so nhu vay duoc goi la [so Carmichael](./primitive-root.md#carmichael-%E6%95%B0), va cung co vo han so. Dieu nay buoc ta tim phep kiem tra tinh nguyen to chat che hon.

<span id="miller–rabin-&#x7D20;&#x6027;&#x6D4B;&#x8BD5;"></span>
### Kiem tra tinh nguyen to Miller-Rabin

**Kiem tra tinh nguyen to Miller-Rabin** (Miller-Rabin primality test) la mot phuong phap xac dinh so nguyen to tot hon. No do Miller va Rabin cai tien tu kiem tra Fermat. Giong cac kiem tra so nguyen to xac suat khac, no chi co the phat hien gia nguyen to. Neu can chac chan la so nguyen to, phai dung cac thuat toan tat dinh cham hon nhieu. Tuy vay, tren thuc te chua biet so nao vuot qua Miller-Rabin va cac kiem tra xac suat manh khac nhung lai la hop so, nen ta co the yen tam su dung.

Neu khong xet do phuc tap cua phep nhan, thuc hien $k$ vong kiem tra cho so $n$ co do phuc tap thoi gian $O(k \log n)$. Kiem tra Miller-Rabin thuong dung cho so do chinh xac cao; khi do do phuc tap thoi gian la $O(k \log^3n)$, va co the toi uu bang FFT cung cac ky thuat khac thanh [$O(k \log^2n \log \log n \log \log \log n)$](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Complexity).

De xu ly thach thuc tu cac so Carmichael, kiem tra Miller-Rabin xet them tinh chat sau cua so nguyen to:

???+ note "Dinh ly can bac hai"
    Neu $p$ la so nguyen to le, nghiem cua $x^2 \equiv 1 \pmod p$ la $x \equiv 1 \pmod p$ hoac $x \equiv p - 1 \pmod p$.

??? note "Chung minh"
    De kiem tra truc tiep rang khi $p$ la so nguyen to le, ca $x\equiv 1\pmod p$ va $x\equiv p-1\pmod p$ deu lam cong thuc tren dung. Theo [dinh ly Lagrange](./congruence-equation.md#%E5%AE%9A%E7%90%86-3lagrange-%E5%AE%9A%E7%90%86), day la tat ca nghiem cua phuong trinh.

Ket hop dinh ly nho Fermat voi dinh ly can bac hai, ta thu duoc kiem tra tinh nguyen to Miller-Rabin:

1.  Phan tich so mu $n−1$ trong $a^{n-1} \equiv 1 \pmod n$ thanh $n−1=u \times 2^t$;
2.  Trong moi vong kiem tra, voi $a$ duoc chon ngau nhien, tinh truoc $v = a^{u} \bmod n$, sau do binh phuong gia tri nay toi da $t$ lan;
3.  Trong qua trinh do, neu phat hien can bac hai khong tam thuong cua $1$ (tuc nghiem khac $\pm 1$), co the ket luan so do khong phai so nguyen to;
4.  Neu khong, dung tiep kiem tra tinh nguyen to Fermat de phan dinh.

Mot vai chi tiet khi cai dat:

-   Trong mot vong kiem tra, neu tai thoi diem nao do $a^{u \times 2^s} \equiv n-1 \pmod n$, cac lan binh phuong sau do deu cho $1$, nen co the cho vong nay vuot qua ngay.
-   Neu tim duoc mot can bac hai khong tam thuong $a^{u \times 2^s} \not\equiv n-1 \pmod n$, cac lan binh phuong sau do deu cho $1$. Co the tra ve `false` ngay, hoac doi den sau $t$ lan binh phuong moi tra ve `false`.

Ta thu duoc phien ban Miller-Rabin kha dung sau (tu fjzzq2002):

???+ example "Cai dat tham khao"
    === "C++"
        ```cpp
        bool millerRabin(int n) {
          if (n < 3 || n % 2 == 0) return n == 2;
          if (n % 3 == 0) return n == 3;
          int u = n - 1, t = 0;
          while (u % 2 == 0) u /= 2, ++t;
          // test_time la so lan kiem tra; nen dat khong nho hon 8
          // de bao dam do chinh xac, nhung cung khong nen qua lon de tranh cham
          for (int i = 0; i < test_time; ++i) {
            // 0, 1, n-1 co the vuot qua truc tiep; a nam trong [2, n-2]
            int a = rand() % (n - 3) + 2, v = quickPow(a, u, n);
            if (v == 1) continue;
            int s;
            for (s = 0; s < t; ++s) {
              if (v == n - 1) break;  // gap can tam thuong n-1, vong nay dat
              v = (long long)v * v % n;
            }
            // Neu gap can khong tam thuong thi khong break som va chay den s == t
            // Neu kiem tra Fermat khong dat, truoc s == t thi v se khong bang -1
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
            # test_time la so lan kiem tra; nen dat khong nho hon 8
            # de bao dam do chinh xac, nhung cung khong nen qua lon de tranh cham
            for i in range(test_time):
                # 0, 1, n-1 co the vuot qua truc tiep; a nam trong [2, n-2]
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
                # Neu gap can khong tam thuong thi khong break som va chay den s == t
                # Neu kiem tra Fermat khong dat, truoc s == t thi v se khong bang -1
                if s == t:
                    return False
            return True
        ```

Co the chung minh[^millerrabinproof] rang voi hop so le $n > 9$, xac suat de $n$ vuot qua kiem tra Miller-Rabin voi mot co so $a$ chon ngau nhien khong qua $1/4$. Do do, sau khi chon ngau nhien $k$ co so, xac suat van nhan nham hop so la so nguyen to khong vuot qua $1/4^k$.

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

1.  So phan nguyen to chac chan la tich cua cac luy thua cua cac so nguyen to lien tiep bat dau tu $2$.

2.  So mu cua so nguyen to co gia tri nho hon phai lon hon hoac bang so mu cua so nguyen to co gia tri lon hon. Tuc trong $n=p_{1}^{k_{1}}p_{2}^{k_{2}} \cdots p_{n}^{k_{n}}$ co $k_1 \geq k_2 \geq k_3 \geq \cdots \geq k_n$.

Giai thich:

1.  Neu khong phai cac so nguyen to lien tiep bat dau tu $2$, thi giu nguyen so mu va thay mot so nguyen to bang so nguyen to nho hon se giu nguyen so uoc nhung lam gia tri $n$ nho di. Khi doi den day cac so nguyen to lien tiep bat dau tu $2$, gia tri $n$ la nho nhat.

2.  Neu so mu cua so nguyen to nho hon lai nho hon so mu cua so nguyen to lon hon, thi doi cho hai so nguyen to do (giu nguyen so mu) se giu nguyen so uoc cua $n$ nhung lam gia tri $n$ nho di.

Con hai cau hoi:

1.  Voi $n$ cho truoc, can liet ke den so nguyen to nao?

    Truong hop cuc doan nhat chi la $n=p_{1}p_{2} \cdots p_{n}$, nen chi can nhan lien tiep cac so nguyen to den khi tich vua khong vuot qua $n$. Neu liet ke den so nguyen to lon hon nua, nghia la bat buoc co mot so nguyen to truoc do co so mu bang $0$, khi do khong the tao thanh so phan nguyen to.

2.  Can liet ke so mu den bao nhieu?

    Xet truong hop cuc doan: khi mot luy thua nao do cua so nguyen to nho nhat da lon hon $n$ cho truoc (gia tri lon nhat cua $n$), thi neu khai trien thanh cac dang khac, so mu lon nhat chac chan nho hon so mu do. Trong truong hop cuc doan $n$ la luy thua cua $2$, chi can liet ke den $\lfloor\log_2 n\rfloor$.

Da co cac chi tiet tren, ta cai dat cu the ra sao?

Co the xem trang thai truoc khi di den moi so nguyen to nhu mot nut goc cua cay, roi tim dan theo tung tang. Khi nao dung?

1.  Gia tri hien tai da lon hon gia tri can xet;

2.  Thua so dang liet ke khong con can dung;

3.  So uoc hien tai da lon hon so uoc mong muon;

4.  So uoc hien tai vua bang so uoc mong muon; khi do xet co can cap nhat $\mathit{ans}$ nho nhat hay khong.

Sau do trong dfs, lien tuc liet ke so mu theo tung tang va de quy xuong duoi.

<span id="&#x4F8B;&#x9898;"></span>
### Bai tap vi du

???+ example "[Codeforces 27E. A number with a given number of divisors](https://codeforces.com/problemset/problem/27/E)"
    Tim so tu nhien nho nhat co so luong uoc cho truoc. Dap an duoc dam bao khong vuot qua $10^{18}$.

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
