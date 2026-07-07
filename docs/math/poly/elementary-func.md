author: 97littleleaf11, abc1763613206, CCXXXI, EndlessCheng, Enter-tainer, fps5283, Great-designer, H-J-Granger, hly1204, hsfzLZH1, huayucaiji, Ir1d, kenlig, Marcythm, ouuan, SamZhangQingChuan, shuzhouliu, sshwy, StudyingFather, test12345-pupil, Tiphereth-A, TrisolarisHD, untitledunrevised

Trang này trình bày các phép toán hàm sơ cấp thường gặp trên đa thức. Cụ thể, trang này gồm các nội dung sau:

1.  Nghịch đảo đa thức
2.  Khai căn đa thức
3.  Chia đa thức
4.  Lấy dư đa thức
5.  Hàm mũ của đa thức
6.  Hàm logarit của đa thức
7.  Hàm lượng giác của đa thức
8.  Hàm lượng giác ngược của đa thức

??? note "Hàm sơ cấp và hàm không sơ cấp"
    Định nghĩa hàm sơ cấp như sau[^ref1]:
    
    Nếu trên trường $F$ tồn tại ánh xạ $u\to \partial u$ thỏa:
    
    1.  $\partial(u+v)=\partial u+\partial v$
    2.  $\partial(uv)=u\partial v+v\partial u$
    
    thì trường đó được gọi là **trường vi phân**.
    
    Nếu một hàm $u$ trên trường vi phân $F$ thỏa bất kỳ điều kiện nào sau đây, thì $u$ được gọi là hàm sơ cấp:
    
    1.  $u$ là một hàm đại số trên $F$.
    2.  $u$ là một hàm kiểu mũ, tức tồn tại $a\in F$ sao cho $\partial u=u\partial a$.
    3.  $u$ là một hàm kiểu logarit, tức tồn tại $a\in F$ sao cho $\partial u=\frac{\partial a}{a}$.
    
    Các hàm sơ cấp thường gặp gồm:
    
    1.  Hàm đại số: hàm $f(x)$ sao cho tồn tại đa thức hữu hạn bậc $P$ thỏa $P(f(x))=0$, chẳng hạn $2x+1$,$\sqrt{x}$,$(1+x^2)^{-1}$,$|x|$.
    2.  Hàm mũ
    3.  Hàm logarit
    4.  Hàm lượng giác
    5.  Hàm lượng giác ngược
    6.  Hàm hyperbol
    7.  Hàm hyperbol ngược
    8.  Hợp của các hàm trên, ví dụ:
    
        $$
        \frac{\mathrm{e}^{\tan x}}{1+x^2}\sin\left(\sqrt{1+\ln^2 x}\right)
        $$
    
        $$
        -\mathrm{i} \ln\left(x+\mathrm{i}\sqrt{1-x^2}\right)
        $$
    
    Các hàm không sơ cấp thường gặp gồm:
    
    1.  Hàm sai số:
    
        $$
        \operatorname{erf}(x):=\frac{2}{\sqrt{\pi}}\int_{0}^{x}\exp\left(-t^2\right)\mathrm{d}t
        $$

<span id="nghịch-đảo-đa-thức"></span>
## Nghịch đảo đa thức

Cho đa thức $f\left(x\right)$, cần tìm $f^{-1}\left(x\right)$.

<span id="cách-giải"></span>
### Cách giải

<span id="phương-pháp-nhân-đôi"></span>
#### Phương pháp nhân đôi

Trước hết, có

$$
\left[x^{0}\right]f^{-1}\left(x\right)=\left(\left[x^{0}\right]f\left(x\right)\right)^{-1}
$$

Giả sử hiện đã tìm được nghịch đảo $f^{-1}_{0}\left(x\right)$ của $f\left(x\right)$ theo môđun $x^{\left\lceil\frac{n}{2}\right\rceil}$. Khi đó:

$$
\begin{aligned}
    f\left(x\right)f^{-1}_{0}\left(x\right)&\equiv 1 &\pmod{x^{\left\lceil\frac{n}{2}\right\rceil}}\\
    f\left(x\right)f^{-1}\left(x\right)&\equiv 1 &\pmod{x^{\left\lceil\frac{n}{2}\right\rceil}}\\
    f^{-1}\left(x\right)-f^{-1}_{0}\left(x\right)&\equiv 0 &\pmod{x^{\left\lceil\frac{n}{2}\right\rceil}}
\end{aligned}
$$

Bình phương hai vế, thu được:

$$
f^{-2}\left(x\right)-2f^{-1}\left(x\right)f^{-1}_{0}\left(x\right)+f^{-2}_{0}\left(x\right)\equiv 0 \pmod{x^{n}}
$$

Nhân hai vế với $f\left(x\right)$ rồi chuyển vế:

$$
f^{-1}\left(x\right)\equiv f^{-1}_{0}\left(x\right)\left(2-f\left(x\right)f^{-1}_{0}\left(x\right)\right) \pmod{x^{n}}
$$

Sau đó tính đệ quy.

**Độ phức tạp thời gian**

$$
T\left(n\right)=T\left(\frac{n}{2}\right)+O\left(n\log{n}\right)=O\left(n\log{n}\right)
$$

#### Phương pháp Newton

Xem [phương pháp Newton](./newton.md#newtons-method).

<span id="phương-pháp-graeffe"></span>
#### Phương pháp Graeffe

Để tìm $f^{-1}(x)\bmod x^{2n}$, xét

$$
\begin{aligned}
f^{-1}(x)\bmod x^{2n}&= f(-x)(f(x)f(-x))^{-1}\bmod x^{2n}\\
&=f(-x)g^{-1}(x^2)\bmod x^{2n}
\end{aligned}
$$

Chỉ cần tìm $g^{-1}(x)\bmod x^n$ rồi khôi phục $g^{-1}(x^2)\bmod x^{2n}$, vì $f(x)f(-x)$ là hàm chẵn. Độ phức tạp thời gian như trên.

<span id="mã-nguồn"></span>
### Mã nguồn

??? note "Nghịch đảo đa thức"
    ```cpp
    constexpr int MAXN = 262144;
    constexpr int mod = 998244353;
    
    using i64 = long long;
    using poly_t = int[MAXN];
    using poly = int *const;
    
    void polyinv(const poly &h, const int n, poly &f) {
      /* f = 1 / h = f_0 (2 - f_0 h) */
      static poly_t inv_t;
      std::fill(f, f + n + n, 0);
      f[0] = fpow(h[0], mod - 2);
      for (int t = 2; t <= n; t <<= 1) {
        const int t2 = t << 1;
        std::copy(h, h + t, inv_t);
        std::fill(inv_t + t, inv_t + t2, 0);
    
        DFT(f, t2);
        DFT(inv_t, t2);
        for (int i = 0; i != t2; ++i)
          f[i] = (i64)f[i] * sub(2, (i64)f[i] * inv_t[i] % mod) % mod;
        IDFT(f, t2);
    
        std::fill(f + t, f + t2, 0);
      }
    }
    ```

<span id="ví-dụ"></span>
### Ví dụ

1.  Đếm số đồ thị vô hướng đơn liên thông có nhãn: [POJ 1737 - Đồ thị liên thông](http://poj.org/problem?id=1737)

<span id="khai-căn-đa-thức"></span>
## Khai căn đa thức

Cho đa thức $g\left(x\right)$, cần tìm $f\left(x\right)$ thỏa:

$$
f^{2}\left(x\right)\equiv g\left(x\right) \pmod{x^{n}}
$$

<span id="cách-giải_1"></span>
### Cách giải

<span id="phương-pháp-nhân-đôi_1"></span>
#### Phương pháp nhân đôi

Trước hết xét trường hợp $\left[x^0\right]g(x)$ khác $0$.

Có:

$$
\left[x^0\right]f(x) = \sqrt{\left[x^0\right]g(x)}
$$

Nếu $\left[x^0\right]g(x)$ không có căn bậc hai, thì đa thức $g(x)$ không có căn bậc hai.

> $\left[x^0\right]g(x)$ có thể có nhiều căn bậc hai; chọn các căn khác nhau sẽ cho các $f(x)$ khác nhau.

Giả sử hiện đã tìm được căn bậc hai $f_{0}\left(x\right)$ của $g\left(x\right)$ theo môđun $x^{\left\lceil\frac{n}{2}\right\rceil}$, khi đó:

$$
\begin{aligned}
    f_{0}^{2}\left(x\right)&\equiv g\left(x\right) &\pmod{x^{\left\lceil\frac{n}{2}\right\rceil}}\\
    f_{0}^{2}\left(x\right)-g\left(x\right)&\equiv 0 &\pmod{x^{\left\lceil\frac{n}{2}\right\rceil}}\\
    \left(f_{0}^{2}\left(x\right)-g\left(x\right)\right)^{2}&\equiv 0 &\pmod{x^{n}}\\
    \left(f_{0}^{2}\left(x\right)+g\left(x\right)\right)^{2}&\equiv 4f_{0}^{2}\left(x\right)g\left(x\right) &\pmod{x^{n}}\\
    \left(\frac{f_{0}^{2}\left(x\right)+g\left(x\right)}{2f_{0}\left(x\right)}\right)^{2}&\equiv g\left(x\right) &\pmod{x^{n}}\\
    \frac{f_{0}^{2}\left(x\right)+g\left(x\right)}{2f_{0}\left(x\right)}&\equiv f\left(x\right) &\pmod{x^{n}}\\
    2^{-1}f_{0}\left(x\right)+2^{-1}f_{0}^{-1}\left(x\right)g\left(x\right)&\equiv f\left(x\right) &\pmod{x^{n}}
\end{aligned}
$$

Sau đó tính bằng cách nhân đôi.

**Độ phức tạp thời gian**

$$
T\left(n\right)=T\left(\frac{n}{2}\right)+O\left(n\log{n}\right)=O\left(n\log{n}\right)
$$

Còn một cách viết có hằng số nhỏ hơn: khi nhân đôi và duy trì $f\left(x\right)$, đồng thời duy trì luôn $f^{-1}\left(x\right)$ thay vì mỗi lần đều tính nghịch đảo.

> Khi $\left[x^{0}\right]g\left(x\right)\neq 1$, có thể cần dùng thặng dư bậc hai để tính $\left[x^{0}\right]f\left(x\right)$.

Phương pháp trên cần biết nghịch đảo của $f_{0}(x)$, nên hệ số tự do không được bằng $0$.

Nếu $\left[x^0\right]g(x) = 0$, phân tích $g(x)$ thành $x^{k}h(x)$, trong đó $\left[x^0\right]h(x) \not = 0$.

-   Nếu $k$ lẻ, thì $g(x)$ không có căn bậc hai.

-   Nếu $k$ chẵn, tìm căn bậc hai $\sqrt{h(x)}$ của $h(x)$, rồi thu được $f(x) \equiv x^{k/2} \sqrt{h(x)} \pmod{x^{n}}$.

??? note "Mã tham khảo cho bài mẫu Luogu [P5205 [Mẫu] Khai căn đa thức](https://www.luogu.com.cn/problem/P5205)"
    ```cpp
    --8<-- "docs/math/code/poly/sqrt/sqrt_1.cpp"
    ```

#### Phương pháp Newton

Xem [phương pháp Newton](./newton.md#newtons-method).

<span id="ví-dụ_1"></span>
### Ví dụ

1.  [Codeforces Round #250 - E. Đứa trẻ và cây nhị phân](https://codeforces.com/contest/438/problem/E)

<span id="chia-đa-thức-và-lấy-dư"></span>
## Chia đa thức và lấy dư

Cho hai đa thức $f\left(x\right),g\left(x\right)$, cần tìm thương $Q\left(x\right)$ và dư $R\left(x\right)$ khi chia $f\left(x\right)$ cho $g\left(x\right)$.

<span id="cách-giải_2"></span>
### Cách giải

Nhận thấy nếu có thể khử ảnh hưởng của $R\left(x\right)$ thì có thể trực tiếp dùng [nghịch đảo đa thức](#nghịch-đảo-đa-thức) để giải.

Xét phép biến đổi

$$
f^{R}\left(x\right)=x^{\operatorname{deg}{f}}f\left(\frac{1}{x}\right)
$$

Quan sát cho thấy bản chất của nó là đảo ngược thứ tự hệ số của $f\left(x\right)$.

Đặt $n=\operatorname{deg}{f},m=\operatorname{deg}{g}$.

Thay $x$ trong $f\left(x\right)=Q\left(x\right)g\left(x\right)+R\left(x\right)$ bằng $\frac{1}{x}$ rồi nhân cả hai vế với $x^{n}$, thu được:

$$
\begin{aligned}
    x^{n}f\left(\frac{1}{x}\right)&=x^{n-m}Q\left(\frac{1}{x}\right)x^{m}g\left(\frac{1}{x}\right)+x^{n-m+1}x^{m-1}R\left(\frac{1}{x}\right)\\
    f^{R}\left(x\right)&=Q^{R}\left(x\right)g^{R}\left(x\right)+x^{n-m+1}R^{R}\left(x\right)
\end{aligned}
$$

Lưu ý rằng trong công thức trên, $R^{R}\left(x\right)$ được nhân với $x^{n-m+1}$, nên khi xét theo môđun $x^{n-m+1}$ thì có thể khử ảnh hưởng do $R^{R}\left(x\right)$ gây ra.

Lại vì bậc của $Q^{R}\left(x\right)$ là $\left(n-m\right)<\left(n-m+1\right)$, nên $Q^{R}\left(x\right)$ không bị ảnh hưởng.

Do đó:

$$
f^{R}\left(x\right)\equiv Q^{R}\left(x\right)g^{R}\left(x\right)\pmod{x^{n-m+1}}
$$

Dùng nghịch đảo đa thức là có thể tìm $Q\left(x\right)$; thay ngược lại sẽ thu được $R\left(x\right)$.

**Độ phức tạp thời gian**  $O\left(n\log{n}\right)$.

<span id="hàm-logarit-và-hàm-mũ-của-đa-thức"></span>
## Hàm logarit và hàm mũ của đa thức

Cho đa thức $f(x)$, cần tìm $\ln{f(x)}$ và $\exp{f(x)}$ theo môđun $x^{n}$.

<span id="cách-giải_3"></span>
### Cách giải

<span id="phương-pháp-thông-thường"></span>
#### Phương pháp thông thường

=== "Hàm logarit của đa thức"
    Trước hết, với đa thức $f(x)$, nếu $\ln{f(x)}$ tồn tại, thì theo [định nghĩa](./intro.md#phép-hợp-thành), nó phải thỏa:
    
    $$
    [x^{0}]f(x)=1
    $$
    
    Lấy đạo hàm của $\ln{f(x)}$ rồi tích phân, thu được:
    
    $$
    \begin{aligned}
        \frac{\mathrm{d} \ln{f(x)}}{\mathrm{d} x} & \equiv \frac{f'(x)}{f(x)} & \pmod{x^{n}} \\
        \ln{f(x)} & \equiv \int \mathrm{d} \ln{f(x)} \equiv \int\frac{f'(x)}{f(x)} \mathrm{d} x & \pmod{x^{n}}
    \end{aligned}
    $$
    
    Đạo hàm và tích phân đa thức có độ phức tạp $O(n)$, nghịch đảo đa thức có độ phức tạp $O(n\log{n})$, nên tính $\ln$ của đa thức có độ phức tạp $O(n\log{n})$.

=== "Hàm mũ của đa thức"
    Trước hết, với đa thức $f(x)$, nếu $\exp{f(x)}$ tồn tại, thì nó phải thỏa:
    
    $$
    [x^{0}]f(x)=0
    $$
    
    Nếu không, hệ số tự do của $\exp{f(x)}$ sẽ không hội tụ.
    
    Lấy đạo hàm của $\exp{f(x)}$, thu được:
    
    $$
    \frac{\mathrm{d} \exp{f(x)}}{\mathrm{d} x} \equiv \exp{f(x)}f'(x)\pmod{x^{n}}
    $$
    
    So sánh hệ số hai vế:
    
    $$
    [x^{n-1}]\frac{\mathrm{d} \exp{f(x)}}{\mathrm{d} x} = \sum_{i = 0}^{n - 1} \left([x^{i}]\exp{f(x)}\right) \left([x^{n-i-1}]f'(x)\right)
    $$
    
    $$
    n[x^{n}]\exp{f(x)} = \sum_{i = 0}^{n - 1} \left([x^{i}]\exp{f(x)}\right) \left((n - i)[x^{n - i}]f(x)\right)
    $$
    
    Dùng chia để trị FFT là có thể giải.
    
    **Độ phức tạp thời gian**  $O(n\log^{2}{n})$.

#### Phương pháp Newton

Dùng [phương pháp Newton](./newton.md#newtons-method) có thể giải $\exp$ của đa thức trong độ phức tạp $O(n\log{n})$.

<span id="mã-nguồn_1"></span>
### Mã nguồn

??? note "Logarit/mũ của đa thức"
    ```cpp
    constexpr int MAXN = 262144;
    constexpr int mod = 998244353;
    
    using i64 = long long;
    using poly_t = int[MAXN];
    using poly = int *const;
    
    void derivative(const poly &h, const int n, poly &f) {
      for (int i = 1; i != n; ++i) f[i - 1] = (i64)h[i] * i % mod;
      f[n - 1] = 0;
    }
    
    void integrate(const poly &h, const int n, poly &f) {
      for (int i = n - 1; i; --i) f[i] = (i64)h[i - 1] * inv[i] % mod;
      f[0] = 0; /* C */
    }
    
    void polyln(const poly &h, const int n, poly &f) {
      /* f = ln h = ∫ h' / h dx */
      assert(h[0] == 1);
      static poly_t ln_t;
      const int t = n << 1;
    
      derivative(h, n, ln_t);
      std::fill(ln_t + n, ln_t + t, 0);
      polyinv(h, n, f);
    
      DFT(ln_t, t);
      DFT(f, t);
      for (int i = 0; i != t; ++i) ln_t[i] = (i64)ln_t[i] * f[i] % mod;
      IDFT(ln_t, t);
    
      integrate(ln_t, n, f);
    }
    
    void polyexp(const poly &h, const int n, poly &f) {
      /* f = exp(h) = f_0 (1 - ln f_0 + h) */
      assert(h[0] == 0);
      static poly_t exp_t;
      std::fill(f, f + n + n, 0);
      f[0] = 1;
      for (int t = 2; t <= n; t <<= 1) {
        const int t2 = t << 1;
    
        polyln(f, t, exp_t);
        exp_t[0] = sub(pls(h[0], 1), exp_t[0]);
        for (int i = 1; i != t; ++i) exp_t[i] = sub(h[i], exp_t[i]);
        std::fill(exp_t + t, exp_t + t2, 0);
    
        DFT(f, t2);
        DFT(exp_t, t2);
        for (int i = 0; i != t2; ++i) f[i] = (i64)f[i] * exp_t[i] % mod;
        IDFT(f, t2);
    
        std::fill(f + t, f + t2, 0);
      }
    }
    ```

<span id="ví-dụ_2"></span>
### Ví dụ

1.  Tính $f^{k}(x)$

    Cách thông thường là lũy thừa nhanh đa thức, độ phức tạp thời gian $O(n\log{n}\log{k})$.

    Khi $[x^{0}]f(x)=1$, có:

    $$
    f^{k}(x)=\exp{\left(k\ln{f(x)}\right)}
    $$

    Khi $[x^{0}]f(x)\neq 1$, giả sử hạng bậc thấp nhất của $f(x)$ là $f_{i}x^{i}$, khi đó:

    $$
    f^{k}(x)=f_{i}^{k}x^{ik}\exp{\left(k\ln{\frac{f(x)}{f_{i}x^{i}}}\right)}
    $$

    **Độ phức tạp thời gian**  $O(n\log{n})$.

<span id="hàm-lượng-giác-của-đa-thức"></span>
## Hàm lượng giác của đa thức

Cho đa thức $f\left(x\right)$, cần tìm $\sin{f\left(x\right)}, \cos{f\left(x\right)}$ và $\tan{f\left(x\right)}$ theo môđun $x^{n}$.

<span id="cách-giải_4"></span>
### Cách giải

Trước hết, từ [Euler's formula](../complex.md#công-thức-euler) $\left(\mathrm{e}^{\mathrm{i}x} = \cos{x} + \mathrm{i}\sin{x}\right)$, có thể suy ra [một biểu diễn khác của hàm lượng giác](https://en.wikipedia.org/wiki/Trigonometric_functions#Relationship_to_exponential_function_and_complex_numbers):

$$
\begin{aligned}
    \sin{x} &= \frac{\mathrm{e}^{\mathrm{i}x} - \mathrm{e}^{-\mathrm{i}x}}{2\mathrm{i}} \\
    \cos{x} &= \frac{\mathrm{e}^{\mathrm{i}x} + \mathrm{e}^{-\mathrm{i}x}}{2}
\end{aligned}
$$

Thay $f\left(x\right)$ vào, có:

$$
\begin{aligned}
    \sin{f\left(x\right)} &= \frac{\exp{\left(\mathrm{i}f\left(x\right)\right)} - \exp{\left(-\mathrm{i}f\left(x\right)\right)}}{2\mathrm{i}} \\
    \cos{f\left(x\right)} &= \frac{\exp{\left(\mathrm{i}f\left(x\right)\right)} + \exp{\left(-\mathrm{i}f\left(x\right)\right)}}{2}
\end{aligned}
$$

Viết chương trình trực tiếp theo các biểu thức trên là có thể thu được $\sin{f\left(x\right)}$ và $\cos{f\left(x\right)}$ theo môđun $x^{n}$. Sau đó dùng $\tan{f\left(x\right)} = \frac{\sin{f\left(x\right)}}{\cos{f\left(x\right)}}$ để tính $\tan{f\left(x\right)}$.

<span id="mã-nguồn_2"></span>
### Mã nguồn

??? note "Hàm lượng giác của đa thức"
    Lưu ý rằng đang làm NTT trên $\mathbb{Z}_{998244353}$, nên tương ứng, đơn vị ảo $\mathrm{i}$ cần được thay bằng $86583718$ hoặc $911660635$:
    
    $$
    \begin{aligned}
               & \mathrm{i} = \sqrt{-1} \equiv \sqrt{998244352} \pmod{998244353}       \\
      \implies & \phantom{\text{hoặc}} \quad \mathrm{i} \equiv 86583718 \pmod{998244353} \\
               & \text{hoặc} \quad \mathrm{i} \equiv 911660635 \pmod{998244353}
    \end{aligned}
    $$
    
    ```cpp
    constexpr int MAXN = 262144;
    constexpr int mod = 998244353;
    constexpr int imgunit = 86583718; /* sqrt(-1) = sqrt(998233452) */
    
    using i64 = long long;
    using poly_t = int[MAXN];
    using poly = int *const;
    
    void polytri(const poly &h, const int n, poly &sin_t, poly &cos_t) {
      /* sin(f) = (exp(i * f) - exp(- i * f)) / 2i */
      /* cos(f) = (exp(i * f) + exp(- i * f)) / 2 */
      /* tan(f) = sin(f) / cos(f) */
      assert(h[0] == 0);
      static poly_t tri1_t, tri2_t;
    
      for (int i = 0; i != n; ++i) tri2_t[i] = (i64)h[i] * imgunit % mod;
      polyexp(tri2_t, n, tri1_t);
      polyinv(tri1_t, n, tri2_t);
    
      if (sin_t != nullptr) {
        const int invi = fpow(pls(imgunit, imgunit), mod - 2);
        for (int i = 0; i != n; ++i)
          sin_t[i] = (i64)(tri1_t[i] - tri2_t[i] + mod) * invi % mod;
      }
      if (cos_t != nullptr) {
        for (int i = 0; i != n; ++i) cos_t[i] = div2(pls(tri1_t[i], tri2_t[i]));
      }
    }
    ```

<span id="hàm-lượng-giác-ngược-của-đa-thức"></span>
## Hàm lượng giác ngược của đa thức

Cho đa thức $f\left(x\right)$, cần tìm $\arcsin{f\left(x\right)}, \arccos{f\left(x\right)}$ và $\arctan{f\left(x\right)}$ theo môđun $x^{n}$.

<span id="cách-giải_5"></span>
### Cách giải

Mô phỏng cách tính $\ln$ của đa thức: lấy đạo hàm của hàm lượng giác ngược rồi tích phân, thu được:

$$
\begin{aligned}
    \frac{\mathrm{d}}{\mathrm{d} x} \arcsin{x} &= \frac{1}{\sqrt{1 - x^{2}}} \\
    \arcsin{x} &= \int \frac{1}{\sqrt{1 - x^{2}}} \mathrm{d} x \\
    \frac{\mathrm{d}}{\mathrm{d} x} \arccos{x} &= - \frac{1}{\sqrt{1 - x^{2}}} \\
    \arccos{x} &= - \int \frac{1}{\sqrt{1 - x^{2}}} \mathrm{d} x \\
    \frac{\mathrm{d}}{\mathrm{d} x} \arctan{x} &= \frac{1}{1 + x^{2}} \\
    \arctan{x} &= \int \frac{1}{1 + x^{2}} \mathrm{d} x
\end{aligned}
$$

Thay $f\left(x\right)$ vào, có:

$$
\begin{aligned}
    \frac{\mathrm{d}}{\mathrm{d} x} \arcsin{f\left(x\right)} &= \frac{f'\left(x\right)}{\sqrt{1 - f^{2}\left(x\right)}} \\
    \arcsin{f\left(x\right)} &= \int \frac{f'\left(x\right)}{\sqrt{1 - f^{2}\left(x\right)}} \mathrm{d} x \\
    \frac{\mathrm{d}}{\mathrm{d} x} \arccos{f\left(x\right)} &= - \frac{f'\left(x\right)}{\sqrt{1 - f^{2}\left(x\right)}} \\
    \arccos{f\left(x\right)} &= - \int \frac{f'\left(x\right)}{\sqrt{1 - f^{2}\left(x\right)}} \mathrm{d} x \\
    \frac{\mathrm{d}}{\mathrm{d} x} \arctan{f\left(x\right)} &= \frac{f'\left(x\right)}{1 + f^{2}\left(x\right)} \\
    \arctan{f\left(x\right)} &= \int \frac{f'\left(x\right)}{1 + f^{2}\left(x\right)} \mathrm{d} x
\end{aligned}
$$

Chỉ cần tính trực tiếp theo các công thức này.

<span id="mã-nguồn_3"></span>
### Mã nguồn

??? note "Hàm lượng giác ngược của đa thức"
    ```cpp
    constexpr int MAXN = 262144;
    constexpr int mod = 998244353;
    
    using i64 = long long;
    using poly_t = int[MAXN];
    using poly = int *const;
    
    void derivative(const poly &h, const int n, poly &f) {
      for (int i = 1; i != n; ++i) f[i - 1] = (i64)h[i] * i % mod;
      f[n - 1] = 0;
    }
    
    void integrate(const poly &h, const int n, poly &f) {
      for (int i = n - 1; i; --i) f[i] = (i64)h[i - 1] * inv[i] % mod;
      f[0] = 0; /* C */
    }
    
    void polyarcsin(const poly &h, const int n, poly &f) {
      /* arcsin(f) = ∫ f' / sqrt(1 - f^2) dx  */
      static poly_t arcsin_t;
      const int t = n << 1;
      std::copy(h, h + n, arcsin_t);
      std::fill(arcsin_t + n, arcsin_t + t, 0);
    
      DFT(arcsin_t, t);
      for (int i = 0; i != t; ++i) arcsin_t[i] = sqr(arcsin_t[i]);
      IDFT(arcsin_t, t);
    
      arcsin_t[0] = sub(1, arcsin_t[0]);
      for (int i = 1; i != n; ++i)
        arcsin_t[i] = arcsin_t[i] ? mod - arcsin_t[i] : 0;
    
      polysqrt(arcsin_t, n, f);
      polyinv(f, n, arcsin_t);
      derivative(h, n, f);
    
      DFT(f, t);
      DFT(arcsin_t, t);
      for (int i = 0; i != t; ++i) arcsin_t[i] = (i64)f[i] * arcsin_t[i] % mod;
      IDFT(arcsin_t, t);
    
      integrate(arcsin_t, n, f);
    }
    
    void polyarccos(const poly &h, const int n, poly &f) {
      /* arccos(f) = - ∫ f' / sqrt(1 - f^2) dx  */
      polyarcsin(h, n, f);
      for (int i = 0; i != n; ++i) f[i] = f[i] ? mod - f[i] : 0;
    }
    
    void polyarctan(const poly &h, const int n, poly &f) {
      /* arctan(f) = ∫ f' / (1 + f^2) dx  */
      static poly_t arctan_t;
      const int t = n << 1;
      std::copy(h, h + n, arctan_t);
      std::fill(arctan_t + n, arctan_t + t, 0);
    
      DFT(arctan_t, t);
      for (int i = 0; i != t; ++i) arctan_t[i] = sqr(arctan_t[i]);
      IDFT(arctan_t, t);
    
      inc(arctan_t[0], 1);
      std::fill(arctan_t + n, arctan_t + t, 0);
    
      polyinv(arctan_t, n, f);
      derivative(h, n, arctan_t);
    
      DFT(f, t);
      DFT(arctan_t, t);
      for (int i = 0; i != t; ++i) arctan_t[i] = (i64)f[i] * arctan_t[i] % mod;
      IDFT(arctan_t, t);
    
      integrate(arctan_t, n, f);
    }
    ```

<span id="tài-liệu-tham-khảo-và-liên-kết"></span>
## Tài liệu tham khảo và liên kết

[^ref1]: [Hàm sơ cấp - Wikipedia](https://en.wikipedia.org/wiki/Elementary_function)
