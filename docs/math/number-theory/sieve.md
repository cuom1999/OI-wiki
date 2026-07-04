author: inkydragon, TravorLZH, YOYO-UIAT, wood3, shuzhouliu, Mr-Python-in-China, HeRaNO, weilycoder

<span id="&#x7D20;&#x6570;&#x7B5B;&#x6CD5;"></span>
## Sang so nguyen to

<span id="&#x5F15;&#x5165;"></span>
### Gioi thieu

Neu muon biet co bao nhieu so nguyen to nho hon hoac bang $n$ thi lam the nao?

Mot y tuong tu nhien la kiem tra tinh nguyen to cho tung so khong vuot qua $n$. Cach vét can nay ro rang khong dat do phuc tap toi uu.

<span id="&#x57C3;&#x62C9;&#x6258;&#x65AF;&#x7279;&#x5C3C;&#x7B5B;&#x6CD5;"></span>
### Sang Eratosthenes

<span id="&#x8FC7;&#x7A0B;"></span>
#### Qua trinh

Xet mot nhan xet: voi bat ky so nguyen duong $n$ lon hon $1$, boi $x$ cua no la hop so neu $x > 1$. Dua vao ket luan nay, ta co the tranh nhieu lan kiem tra khong can thiet.

Neu xet tung so tu nho den lon, dong thoi danh dau tat ca cac boi so cua so hien tai (lon hon chinh no) la hop so, thi sau khi ket thuc, nhung so chua bi danh dau chinh la so nguyen to.

<span id="&#x5B9E;&#x73B0;"></span>
#### Cai dat

=== "C++"
    ```cpp
    vector<int> prime;
    bool is_prime[N];
    
    void Eratosthenes(int n) {
      is_prime[0] = is_prime[1] = false;
      for (int i = 2; i <= n; ++i) is_prime[i] = true;
      for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
          prime.push_back(i);
          if ((long long)i * i > n) continue;
          for (int j = i * i; j <= n; j += i)
            // Cac boi tu 2 den i - 1 da duoc sang truoc do, nen o day bat dau
            // truc tiep tu boi cua i de tang toc
            is_prime[j] = false;  // cac boi cua i deu khong phai so nguyen to
        }
      }
    }
    ```

=== "Python"
    ```python
    prime = []
    is_prime = [False] * N
    
    
    def Eratosthenes(n):
        is_prime[0] = is_prime[1] = False
        for i in range(2, n + 1):
            is_prime[i] = True
        for i in range(2, n + 1):
            if is_prime[i]:
                prime.append(i)
                if i * i > n:
                    continue
                for j in range(i * i, n + 1, i):
                    is_prime[j] = False
    ```

Tren day la **sang Eratosthenes** (goi tat la sang Eratosthenes), co do phuc tap thoi gian $O(n\log\log n)$.

???+ note "Chung minh"
    Bay gio xet qua trinh suy ra:
    
    Neu moi thao tac tren mang ton 1 don vi thoi gian, do phuc tap thoi gian la:
    
    $$
    O\left(\sum_{k=1}^{\pi(n)}{\frac{n}{p_k}}\right)=O\left(n\sum_{k=1}^{\pi(n)}{\frac{1}{p_k}}\right)
    $$
    
    Trong do $p_k$ la so nguyen to nho thu $k$, $\pi(n)$ la so luong so nguyen to $\le n$. $\sum_{k=1}^{\pi(n)}$ bieu dien vong `for` lop ngoai, voi can tren $\pi(n)$ la so lan `if (prime[i])` di vao nhanh `true`; $\frac{n}{p_k}$ bieu dien so lan thuc hien vong `for` lop trong.
    
    Theo dinh ly thu hai cua Mertens, ton tai hang so $B_1$ sao cho:
    
    $$
    \sum_{k=1}^{\pi(n)}{\frac{1}{p_k}}=\log\log n+B_1+O\left(\frac{1}{\log n}\right)
    $$
    
    Do do do phuc tap thoi gian cua **sang Eratosthenes** la $O(n\log\log n)$. Tiep theo ta chung minh phien ban yeu hon cua dinh ly thu hai Mertens: $\sum_{k\le\pi(n)}1/p_k=O(\log\log n)$.
    
    Tu $\pi(n)=\Theta(n/\log n)$, suy ra so nguyen to thu $n$ co kich thuoc $\Theta(n\log n)$. Khi do
    
    $$
    \begin{aligned}
    \sum_{k=1}^{\pi(n)}{\frac{1}{p_k}}
    &=O\left(\sum_{k=2}^{\pi(n)}{\frac{1}{k\log k}}\right) \\
    &=O\left(\int_2^{\pi(n)}{\frac{\mathrm dx}{x\log x}}\right) \\
    &=O(\log\log\pi(n))=O(\log\log n)
    \end{aligned}
    $$
    
    Tat nhien, cach tren van chua du nhanh trong thuc te; cac phuong phap duoi day co the cai thien hieu nang mot chut.

<span id="&#x7B5B;&#x81F3;&#x5E73;&#x65B9;&#x6839;"></span>
#### Sang den can bac hai

Ro rang, de tim tat ca so nguyen to den $n$, chi can sang bang cac so nguyen to khong vuot qua $\sqrt n$.

=== "C++"
    ```cpp
    vector<int> prime;
    bool is_prime[N];
    
    void Eratosthenes(int n) {
      is_prime[0] = is_prime[1] = false;
      for (int i = 2; i <= n; ++i) is_prime[i] = true;
      // i * i <= n nghia la i <= sqrt(n)
      for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i])
          for (int j = i * i; j <= n; j += i) is_prime[j] = false;
      }
      for (int i = 2; i <= n; ++i)
        if (is_prime[i]) prime.push_back(i);
    }
    ```

=== "Python"
    ```python
    prime = []
    is_prime = [False] * N
    
    
    def Eratosthenes(n):
        is_prime[0] = is_prime[1] = False
        for i in range(2, n + 1):
            is_prime[i] = True
        # Cho i lap den <= sqrt(n)
        for i in range(2, isqrt(n) + 1):  # `isqrt` la ham moi trong Python 3.8
            if is_prime[i]:
                for j in range(i * i, n + 1, i):
                    is_prime[j] = False
        for i in range(2, n + 1):
            if is_prime[i]:
                prime.append(i)
    ```

Toi uu nay khong anh huong den do phuc tap tiem can. Tren thuc te, lap lai chung minh tren se thu duoc $n \ln \ln \sqrt n + o(n)$; theo tinh chat cua logarit, chung tuong duong ve tiem can, nhung so thao tac giam dang ke.

<span id="&#x53EA;&#x7B5B;&#x5947;&#x6570;"></span>
#### Chi sang so le

Vi moi so chan ngoai $2$ deu la hop so, ta co the bo qua truc tiep va chi quan tam den so le.

Truoc het, cach nay lam giam mot nua nhu cau bo nho; tiep theo, so thao tac can thiet cung xap xi giam mot nua.

<span id="&#x51CF;&#x5C11;&#x5185;&#x5B58;&#x7684;&#x5360;&#x7528;"></span>
#### Giam dung luong bo nho

Ta nhan thay khi sang chi can mang kieu `bool`. Mot phan tu cua mang `bool` thuong chiem $1$ byte (tuc $8$ bit), nhung de luu mot gia tri boolean chi can $1$ bit.

Co the dung kien thuc ve [thao tac bit](../bit.md) de nen moi gia tri boolean vao mot bit. Khi do chi can $n$ bit (tuc $\dfrac n 8$ byte) thay vi $n$ byte, giup giam dang ke bo nho. Cach nay goi la "nen o muc bit".

Dang chu y la co nhung cau truc du lieu tu dong thuc hien nen muc bit, nhu `vector<bool>` va `bitset<>` trong C++.

Ngoai ra, `vector<bool>` va `bitset<>` co toi uu hang so cho chuong trinh; sang Eratosthenes co do phuc tap $O(n \log \log n)$ sau khi toi uu bang `bitset<>` hoac `vector<bool>` tham chi co hieu nang vuot qua sang Euler co do phuc tap $O(n)$.

Xem [bitset: ket hop voi sang Eratosthenes](../../lang/csl/bitset.md#%E4%B8%8E%E5%9F%83%E6%B0%8F%E7%AD%9B%E7%BB%93%E5%90%88).

<span id="&#x5206;&#x5757;&#x7B5B;&#x9009;"></span>
#### Sang theo khoi

Tu toi uu "sang den can bac hai", ta biet khong can giu toan bo mang `is_prime[1...n]`. De sang, chi can giu cac so nguyen to den $\sqrt n$, tuc `prime[1...sqrt(n)]`, roi chia toan bo mien thanh cac khoi va sang rieng tung khoi. Nhu vay khong can giu nhieu khoi trong bo nho cung luc, va CPU cung xu ly cache tot hon.

Goi $s$ la mot hang so quyet dinh kich thuoc khoi, khi do co $\lceil {\frac n s} \rceil$ khoi, va khoi $k$ ($k = 0 \dots \lfloor {\frac n s} \rfloor$) chua cac so trong doan $[ks, ks + s - 1]$. Ta xu ly tung khoi lan luot: voi moi khoi $k$, duyet tat ca cac so nguyen to (tu $1$ den $\sqrt n$) va dung chung de sang.

Can luu y khi xu ly cac so dau tien phai sua chien luoc mot chut: thu nhat, can giu tat ca so nguyen to trong $[1, \sqrt n]$; thu hai, so $0$ va $1$ phai duoc danh dau la khong phai so nguyen to. Khi xu ly khoi cuoi, khong duoc quen rang so cuoi cung $n$ khong nhat thiet nam o cuoi khoi.

Cai dat duoi day dung sang theo khoi de tinh so luong so nguyen to khong vuot qua $n$.

???+ note "Cai dat"
    ```cpp
    int count_primes(int n) {
      constexpr static int S = 10000;
      vector<int> primes;
      int nsqrt = sqrt(n);
      vector<char> is_prime(nsqrt + 1, true);
      for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
          primes.push_back(i);
          for (int j = i * i; j <= nsqrt; j += i) is_prime[j] = false;
        }
      }
      int result = 0;
      vector<char> block(S);
      for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
          int start_idx = (start + p - 1) / p;
          int j = max(start_idx, p) * p - start;
          for (; j < S; j += p) block[j] = false;
        }
        if (k == 0) block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
          if (block[i]) result++;
        }
      }
      return result;
    }
    ```

Do phuc tap tiem can cua sang theo khoi giong sang Eratosthenes (tru khi khoi qua nho), nhung bo nho can dung giam xuong $O(\sqrt{n} + S)$ va co hieu qua cache tot hon.
Mat khac, voi moi cap gom mot khoi va mot so nguyen to trong doan $[1, \sqrt{n}]$, ta deu phai thuc hien phep chia; voi khoi nho, dieu nay te hon nhieu.
Vi vay can can bang khi chon hang so $S$.

Kich thuoc khoi $S$ trong khoang $10^4$ den $10^5$ thuong cho toc do tot nhat.

<span id="&#x7EBF;&#x6027;&#x7B5B;&#x6CD5;"></span>
### Sang tuyen tinh

Sang Eratosthenes van con khong gian toi uu, vi no danh dau mot hop so nhieu lan. Co cach nao bo qua cac buoc vo nghia nay khong? Cau tra loi la co.

Neu moi hop so chi bi danh dau mot lan, do phuc tap thoi gian co the giam xuong $O(n)$.

???+ note "Cai dat"
    === "C++"
        ```cpp
        vector<int> pri;
        bool not_prime[N];
        
        void pre(int n) {
          for (int i = 2; i <= n; ++i) {
            if (!not_prime[i]) {
              pri.push_back(i);
            }
            for (int pri_j : pri) {
              if (i * pri_j > n) break;
              not_prime[i * pri_j] = true;
              if (i % pri_j == 0) {
                // i % pri_j == 0
                // Noi cach khac, i da bi sang boi pri_j truoc do
                // Vi cac so nguyen to trong pri tang dan, nen ket qua cua i nhan
                // voi cac so nguyen to khac chac chan se bi sang boi boi cua pri_j;
                // khong can sang truoc o day, nen break truc tiep
                break;
              }
            }
          }
        }
        ```
    
    === "Python"
        ```python
        pri = []
        not_prime = [False] * N
        
        
        def pre(n):
            for i in range(2, n + 1):
                if not not_prime[i]:
                    pri.append(i)
                for pri_j in pri:
                    if i * pri_j > n:
                        break
                    not_prime[i * pri_j] = True
                    if i % pri_j == 0:
                        """
                        i % pri_j == 0
                        Noi cach khac, i da bi sang boi pri_j truoc do
                        Vi cac so nguyen to trong pri tang dan, nen ket qua cua i nhan
                        voi cac so nguyen to khac chac chan se bi sang boi boi cua pri_j;
                        khong can sang truoc o day, nen break truc tiep
                        """
                        break
        ```

Kieu sang tren duoc goi la **sang tuyen tinh**, hay **sang Euler**.

???+ note "Ghi chu"
    Khi dung sang de tim so nguyen to, ta dong thoi thu duoc thua so nguyen to nho nhat cua moi so.

<span id="&#x7B5B;&#x6CD5;&#x6C42;&#x6B27;&#x62C9;&#x51FD;&#x6570;"></span>
## Tinh ham Euler bang sang

Trong sang tuyen tinh, moi hop so deu bi sang boi thua so nguyen to nho nhat. Vi du, goi $p_1$ la thua so nguyen to nho nhat cua $n$, $n' = \frac{n}{p_1}$; trong qua trinh sang tuyen tinh, $n$ bi sang qua $n' \times p_1$.

Quan sat qua trinh sang tuyen tinh, ta con can xu ly hai phan; sau day chia truong hop theo $n' \bmod p_1$.

Neu $n' \bmod p_1 = 0$, thi $n'$ chua tat ca thua so nguyen to cua $n$.

$$
\begin{aligned}
\varphi(n) & = n \times \prod_{i = 1}^s{\frac{p_i - 1}{p_i}} \\\\
& = p_1 \times n' \times \prod_{i = 1}^s{\frac{p_i - 1}{p_i}} \\\\
& = p_1 \times \varphi(n')
\end{aligned}
$$

Con neu $n' \bmod p_1 \neq 0$ thi sao? Khi do $n'$ va $p_1$ nguyen to cung nhau; theo tinh chat cua ham Euler, ta co:

$$
\begin{aligned}
\varphi(n) & = \varphi(p_1) \times \varphi(n') \\\\
& = (p_1 - 1) \times \varphi(n')
\end{aligned}
$$

<span id="&#x5B9E;&#x73B0;"></span>
### Cai dat

=== "C++"
    ```cpp
    vector<int> pri;
    bool not_prime[N];
    int phi[N];
    
    void pre(int n) {
      phi[1] = 1;
      for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
          pri.push_back(i);
          phi[i] = i - 1;
        }
        for (int pri_j : pri) {
          if (i * pri_j > n) break;
          not_prime[i * pri_j] = true;
          if (i % pri_j == 0) {
            phi[i * pri_j] = phi[i] * pri_j;
            break;
          }
          phi[i * pri_j] = phi[i] * phi[pri_j];
        }
      }
    }
    ```

=== "Python"
    ```python
    pri = []
    not_prime = [False] * N
    phi = [0] * N
    
    
    def pre(n):
        phi[1] = 1
        for i in range(2, n + 1):
            if not not_prime[i]:
                pri.append(i)
                phi[i] = i - 1
            for pri_j in pri:
                if i * pri_j > n:
                    break
                not_prime[i * pri_j] = True
                if i % pri_j == 0:
                    phi[i * pri_j] = phi[i] * pri_j
                    break
                phi[i * pri_j] = phi[i] * phi[pri_j]
    ```

<span id="&#x7B5B;&#x6CD5;&#x6C42;&#x83AB;&#x6BD4;&#x4E4C;&#x65AF;&#x51FD;&#x6570;"></span>
## Tinh ham Mobius bang sang

<span id="&#x5B9A;&#x4E49;"></span>
### Dinh nghia

Theo dinh nghia ham Mobius, gia su $n$ la hop so, $p_1$ la thua so nguyen to nho nhat cua $n$, $n'=\frac{n}{p_1}$, ta co:

$$
\mu(n)=
\begin{cases}
    0 & n' \bmod p_1 = 0\\\\
    -\mu(n') & \text{otherwise}
\end{cases}
$$

Neu $n$ la so nguyen to, $\mu(n)=-1$.

<span id="&#x5B9E;&#x73B0;"></span>
### Cai dat

=== "C++"
    ```cpp
    vector<int> pri;
    bool not_prime[N];
    int mu[N];
    
    void pre(int n) {
      mu[1] = 1;
      for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
          mu[i] = -1;
          pri.push_back(i);
        }
        for (int pri_j : pri) {
          if (i * pri_j > n) break;
          not_prime[i * pri_j] = true;
          if (i % pri_j == 0) {
            mu[i * pri_j] = 0;
            break;
          }
          mu[i * pri_j] = -mu[i];
        }
      }
    }
    ```

=== "Python"
    ```python
    pri = []
    not_prime = [False] * N
    mu = [0] * N
    
    
    def pre(n):
        mu[1] = 1
        for i in range(2, n + 1):
            if not not_prime[i]:
                pri.append(i)
                mu[i] = -1
            for pri_j in pri:
                if i * pri_j > n:
                    break
                not_prime[i * pri_j] = True
                if i % pri_j == 0:
                    mu[i * pri_j] = 0
                    break
                mu[i * pri_j] = -mu[i]
    ```

<span id="&#x7B5B;&#x6CD5;&#x6C42;&#x7EA6;&#x6570;&#x4E2A;&#x6570;"></span>
## Tinh so luong uoc bang sang

Dung $d_i$ de bieu dien so luong uoc cua $i$, va $num_i$ de bieu dien so lan xuat hien cua thua so nguyen to nho nhat cua $i$.

<span id="&#x7EA6;&#x6570;&#x4E2A;&#x6570;&#x5B9A;&#x7406;"></span>
### Dinh ly ve so luong uoc

Dinh ly: neu $n=\prod_{i=1}^m p_i^{c_i}$ thi $d_i=\prod_{i=1}^m (c_i+1)$.

Chung minh: ta biet cac uoc cua $p_i^{c_i}$ la $p_i^0,p_i^1,\dots ,p_i^{c_i}$, tong cong $c_i+1$ uoc. Theo quy tac nhan, so luong uoc cua $n$ chinh la $\prod_{i=1}^m (c_i+1)$.

<span id="&#x5B9E;&#x73B0;"></span>
### Cai dat

Vi $d_i$ la ham nhan tinh, co the dung sang tuyen tinh.

Sau day gioi thieu ngan gon nguyen ly cai dat sang tuyen tinh.

1.  Khi $i$ la so nguyen to, $\textit{num}_i \gets 1,\textit{d}_i \gets 2$; dong thoi dat $q = \left\lfloor \dfrac {i}{p} \right\rfloor$, trong do $p$ la thua so nguyen to nho nhat cua $i$.
2.  Khi $p$ la thua so nguyen to cua $q$, $\textit{num}_i \gets \textit{num}_q + 1,\textit{d}_i \gets \dfrac{\textit{d}_q}{\textit{num}_i} \times (\textit{num}_i + 1)$.
3.  Khi $p,q$ nguyen to cung nhau, $\textit{num}_i \gets 1,\textit{d}_i \gets \textit{d}_q \times (\textit{num}_i+1)$.

=== "C++"
    ```cpp
    vector<int> pri;
    bool not_prime[N];
    int d[N], num[N];
    
    void pre(int n) {
      d[1] = 1;
      for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
          pri.push_back(i);
          d[i] = 2;
          num[i] = 1;
        }
        for (int pri_j : pri) {
          if (i * pri_j > n) break;
          not_prime[i * pri_j] = true;
          if (i % pri_j == 0) {
            num[i * pri_j] = num[i] + 1;
            d[i * pri_j] = d[i] / num[i * pri_j] * (num[i * pri_j] + 1);
            break;
          }
          num[i * pri_j] = 1;
          d[i * pri_j] = d[i] * 2;
        }
      }
    }
    ```

=== "Python"
    ```python
    pri = []
    not_prime = [False] * N
    d = [0] * N
    num = [0] * N
    
    
    def pre(n):
        d[1] = 1
        for i in range(2, n + 1):
            if not not_prime[i]:
                pri.append(i)
                d[i] = 2
                num[i] = 1
            for pri_j in pri:
                if i * pri_j > n:
                    break
                not_prime[i * pri_j] = True
                if i % pri_j == 0:
                    num[i * pri_j] = num[i] + 1
                    d[i * pri_j] = d[i] // num[i * pri_j] * (num[i * pri_j] + 1)
                    break
                num[i * pri_j] = 1
                d[i * pri_j] = d[i] * 2
    ```

<span id="&#x7B5B;&#x6CD5;&#x6C42;&#x7EA6;&#x6570;&#x548C;"></span>
## Tinh tong uoc bang sang

$f_i$ bieu dien tong cac uoc cua $i$, $g_i$ bieu dien $p^0+p^1+p^2+\dots p^k$ ung voi thua so nguyen to nho nhat cua $i$.

<span id="&#x5B9E;&#x73B0;"></span>
### Cai dat

=== "C++"
    ```cpp
    vector<int> pri;
    bool not_prime[N];
    int g[N], f[N];
    
    void pre(int n) {
      g[1] = f[1] = 1;
      for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
          pri.push_back(i);
          g[i] = i + 1;
          f[i] = i + 1;
        }
        for (int pri_j : pri) {
          if (i * pri_j > n) break;
          not_prime[i * pri_j] = true;
          if (i % pri_j == 0) {
            g[i * pri_j] = g[i] * pri_j + 1;
            f[i * pri_j] = f[i] / g[i] * g[i * pri_j];
            break;
          }
          f[i * pri_j] = f[i] * f[pri_j];
          g[i * pri_j] = 1 + pri_j;
        }
      }
    }
    ```

=== "Python"
    ```python
    pri = []
    not_prime = [False] * N
    f = [0] * N
    g = [0] * N
    
    
    def pre(n):
        g[1] = f[1] = 1
        for i in range(2, n + 1):
            if not not_prime[i]:
                pri.append(i)
                g[i] = i + 1
                f[i] = i + 1
            for pri_j in pri:
                if i * pri_j > n:
                    break
                not_prime[i * pri_j] = True
                if i % pri_j == 0:
                    g[i * pri_j] = g[i] * pri_j + 1
                    f[i * pri_j] = f[i] // g[i] * g[i * pri_j]
                    break
                f[i * pri_j] = f[i] * f[pri_j]
                g[i * pri_j] = 1 + pri_j
    ```

<span id="&#x4E00;&#x822C;&#x7684;&#x79EF;&#x6027;&#x51FD;&#x6570;"></span>
## Ham nhan tinh tong quat

Gia su mot [ham nhan tinh](./basic.md#%E7%A7%AF%E6%80%A7%E5%87%BD%E6%95%B0) $f$ thoa man: voi moi so nguyen to $p$ va so nguyen duong $k$, co the tinh $f(p^k)$ trong thoi gian da thuc bac thap theo $k$. Khi do co the sang cac gia tri $f(1),f(2),\dots,f(n)$ trong thoi gian $O(n)$.

Gia su hop so $n$ co phan tich thua so nguyen to la $\prod_{i=1}^k p_i^{\alpha_i}$, trong do $p_1<p_2<\dots<p_k$ la cac so nguyen to. Trong sang tuyen tinh, ta luu $g_n=p_1^{\alpha_1}$. Neu $n$ bi sang boi $x\cdot p$ (voi $p$ la so nguyen to), thi $g$ thoa man truy hoi sau:

$$
g_n=
\begin{cases}
    g_x\cdot p & x\bmod p=0\\\\
    p & \text{otherwise}
\end{cases}
$$

Neu $n=g_n$, nghia la $n$ chinh la luy thua cua mot so nguyen to nao do, co the tinh $f(n)$ trong $O(1)$; nguoc lai, $f(n)=f(\frac{n}{g_n})\cdot f(g_n)$.

**Mot phan noi dung muc nay duoc dich tu bai viet [Resheto Eratosthena](http://e-maxx.ru/algo/eratosthenes_sieve) va ban dich tieng Anh [Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html). Ban tieng Nga co giay phep Public Domain + Leave a Link; ban tieng Anh co giay phep CC-BY-SA 4.0.**
