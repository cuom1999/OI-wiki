Số Bernoulli $B_n$ là một dãy số hữu tỉ có liên hệ chặt chẽ với số học. Một vài số Bernoulli đầu tiên là:

$B_0=1,B_1=-\frac{1}{2},B_2=\frac{1}{6},B_3=0,B_4=-\frac{1}{30},\dots$

<span id="&#x7B49;&#x5E42;&#x6C42;&#x548C;"></span>
## Tổng các lũy thừa cùng bậc

Số Bernoulli được đặt theo tên Jacob Bernoulli. Khi nghiên cứu công thức tổng các lũy thừa bậc $m$, ông phát hiện ra một quan hệ rất đẹp. Kí hiệu

$$
S_{m}(n)=\sum_{k=0}^{n-1}k^m=0^m+1^m+\dots+(n-1)^m
$$

Bernoulli quan sát dãy công thức sau và nhận ra một mẫu chung:

$$
\begin{aligned}
S_0(n)&=n\\
S_1(n)&=\frac{1}{2}n^2-\frac{1}{2}n\\
S_2(n)&=\frac{1}{3}n^3-\frac{1}{2}n^2+\frac{1}{6}n\\
S_3(n)&=\frac{1}{4}n^4-\frac{1}{2}n^3+\frac{1}{4}n^2\\
S_4(n)&=\frac{1}{5}n^5-\frac{1}{2}n^4+\frac{1}{3}n^3-\frac{1}{30}n
\end{aligned}
$$

Có thể thấy trong $S_m(n)$, hệ số của $n^{m+1}$ luôn là $\frac{1}{m+1}$, hệ số của $n^m$ luôn là $-\frac{1}{2}$, hệ số của $n^{m-1}$ luôn là $\frac{m}{12}$, hệ số của $n^{m-3}$ là $-\frac{m(m-1)(m-2)}{720}$, hệ số của $n^{m-4}$ luôn bằng không, v.v.

Hơn nữa, hệ số của $n^{m-k}$ luôn là một hằng số nào đó nhân với $m^{\underline{k}}$, trong đó $m^{\underline{k}}$ là lũy thừa giai thừa giảm, tức $\frac{m!}{(m-k)!}$.

<span id="&#x9012;&#x63A8;&#x516C;&#x5F0F;"></span>
## Công thức truy hồi

$$
\begin{aligned}
S_m{(n)}&=\frac{1}{m+1}(B_0n^{m+1}+\binom{m+1}{1}B_1 n^m+\dots+\binom{m+1}{m}B_m n) \\
&=\frac{1}{m+1}\sum_{k=0}^{m}\binom{m+1}{k}B_kn^{m+1-k}
\end{aligned}
$$

Số Bernoulli được định nghĩa bởi hệ thức truy hồi ẩn:

$$
\begin{aligned}
\sum_{j=0}^{m}\binom{m+1}{j}B_j&=0,(m>0)\\
B_0&=1
\end{aligned}
$$

Ví dụ, $\binom{2}{0}B_0+\binom{2}{1}B_1=0$. Một vài giá trị đầu tiên là

|  $n$  | $0$ |       $1$      |      $2$      | $3$ |       $4$       | $5$ |       $6$      | $7$ |       $8$       | $\dots$ |
| :---: | :-: | :------------: | :-----------: | :-: | :-------------: | :-: | :------------: | :-: | :-------------: | :-----: |
| $B_n$ | $1$ | $-\frac{1}{2}$ | $\frac{1}{6}$ | $0$ | $-\frac{1}{30}$ | $0$ | $\frac{1}{42}$ | $0$ | $-\frac{1}{30}$ | $\dots$ |

<span id="&#x8BC1;&#x660E;"></span>
### Chứng minh

<span id="&#x5229;&#x7528;&#x5F52;&#x7EB3;&#x6CD5;&#x8BC1;&#x660E;"></span>
#### Chứng minh bằng quy nạp

Cách chứng minh này lấy từ mục 6.5 BERNOULLI NUMBER của Concrete Mathematics.

Ta dùng đồng nhất thức biến đổi hệ số nhị thức và quy nạp:

$$
\begin{aligned}
S_{m+1}(n)+n^{m+1}&= \sum_{k=0}^{n-1}(k+1)^{m+1}\\
&=\sum_{k=0}^{n-1}\sum_{j=0}^{m+1}\binom{m+1}{j}k^j\\
&=\sum_{j=0}^{m+1}\binom{m+1}{j}S_j(n)
\end{aligned}
$$

Đặt $\hat{S}_{m}(n)=\frac{1}{m+1} \sum_{k=0}^{m} \binom{m+1}{k}B_kn^{m+1-k}$. Ta muốn chứng minh $S_m(n)=\hat{S}_m(n)$; giả sử với mọi $j\in[0,m)$, ta đã có $S_j(n)=\hat{S}_j(n)$.

Trừ $S_{m+1}(n)$ ở hai vế của công thức ban đầu, ta được:

$$
\begin{aligned}
S_{m+1}(n)+n^{m+1}&=\sum_{j=0}^{m+1}\binom{m+1}{j}S_j(n)\\
n^{m+1}&=\sum_{j=0}^{m}\binom{m+1}{j}S_j(n)\\
&=\sum_{j=0}^{m-1}\binom{m+1}{j}\hat{S}_j(n)+\binom{m+1}{m}S_m(n)
\end{aligned}
$$

Thử cộng thêm $\binom{m+1}{m}\hat{S}_m(n)-\binom{m+1}{m}\hat{S}_m(n)$ vào vế phải rồi rút gọn, ta được:

$$
n^{m+1}=\sum_{j=0}^{m}\binom{m+1}{j}\hat{S}_j(n)+(m+1)(S_m(n)-\hat{S}_m(n))
$$

Đặt $\Delta = S_m(n)-\hat{S}_m(n)$ và khai triển $\hat{S}_j(n)$, ta có

$$
\begin{aligned}
n^{m+1}&=\sum_{j=0}^{m}\binom{m+1}{j}\hat{S}_j(n)+(m+1)\Delta\\
&=\sum_{j=0}^{m}\binom{m+1}{j}\frac{1}{j+1}\sum_{k=0}^{j}\binom{j+1}{k}B_kn^{j+1-k}+(m+1)\Delta\\
\end{aligned}
$$

Đổi thứ tự trong tổng thứ hai theo chiều ngược lại, rồi biến đổi đồng nhất thức tổ hợp, ta được:

$$
\begin{aligned}
n^{m+1}&=\sum_{j=0}^{m}\binom{m+1}{j}\frac{1}{j+1}\sum_{k=0}^{j}\binom{j+1}{j-k}B_{j-k}n^{k+1}+(m+1)\Delta\\
&=\sum_{j=0}^{m}\binom{m+1}{j}\frac{1}{j+1}\sum_{k=0}^{j}\binom{j+1}{k+1}B_{j-k}n^{k+1}+(m+1)\Delta\\
&=\sum_{j=0}^{m}\binom{m+1}{j}\frac{1}{j+1}\sum_{k=0}^{j}\frac{j+1}{k+1}\binom{j}{k}B_{j-k}n^{k+1}+(m+1)\Delta\\
&=\sum_{j=0}^{m}\binom{m+1}{j}\sum_{k=0}^{j}\binom{j}{k}\frac{B_{j-k}}{k+1}n^{k+1}+(m+1)\Delta
\end{aligned}
$$

Hoán đổi hai dấu tổng, ta được:

$$
n^{m+1}=\sum_{k=0}^{m}\frac{n^{k+1}}{k+1}\sum_{j=k}^{m}\binom{m+1}{j}\binom{j}{k}B_{j-k}+(m+1)\Delta
$$

Biến đổi $\binom{m+1}{j}\binom{j}{k}$:

$$
\binom{m+1}{j}\binom{j}{k}=\binom{m+1}{k}\binom{m-k+1}{j-k}
$$

Khi đó công thức trở thành:

$$
\begin{aligned}
n^{m+1}&=\sum_{k=0}^{m}\frac{n^{k+1}}{k+1}\sum_{j=k}^{m}\binom{m+1}{k}\binom{m-k+1}{j-k}B_{j-k}+(m+1)\Delta\\
&=\sum_{k=0}^{m}\frac{n^{k+1}}{k+1}\binom{m+1}{k}\sum_{j=k}^{m}\binom{m-k+1}{j-k}B_{j-k}+(m+1)\Delta\\
\end{aligned}
$$

Thay mọi $j-k$ bằng $j$, ta được:

$$
n^{m+1}=\sum_{k=0}^{m}\frac{n^{k+1}}{k+1}\binom{m+1}{k}\sum_{j=0}^{m-k}\binom{m-k+1}{j}B_{j}+(m+1)\Delta
$$

Xét hệ thức truy hồi đã nêu:

$$
\begin{aligned}
\sum_{j=0}^{m}\binom{m+1}{j}B_j&=0,(m>0)\\
B_0&=1\\
\sum_{j=0}^{m}\binom{m+1}{j}B_j&=[m = 0]
\end{aligned}
$$

Thay vào, ta được:

$$
\begin{aligned}
n^{m+1}&=\sum_{k=0}^{m}\frac{n^{k+1}}{k+1}\binom{m+1}{k}[m - k = 0]+(m+1)\Delta\\
&=\frac{n^{m+1}}{m+1}\binom{m+1}{m}+(m+1)\Delta\\
&=n^{m+1}+(m+1)\Delta
\end{aligned}
$$

Vậy $\Delta=0$, tức $S_m(n)=\hat{S}_m(n)$.

<span id="&#x5229;&#x7528;&#x6307;&#x6570;&#x751F;&#x6210;&#x51FD;&#x6570;&#x8BC1;&#x660E;"></span>
#### Chứng minh bằng hàm sinh mũ

Với truy hồi $\sum_{j=0}^{m}\binom{m+1}{j}B_j=[m=0]$,

cộng thêm $B_{m + 1}$ vào hai vế, ta được:

$$
\begin{aligned}
\sum_{j=0}^{m+1}\binom{m+1}{j}B_j&=[m=0]+B_{m+1}\\
\sum_{j=0}^{m}\binom{m}{j}B_j&=[m=1]+B_{m}\\
\sum_{j=0}^{m}\dfrac{B_j}{j!}\cdot\dfrac{1}{(m-j)!}&=[m=1]+\dfrac{B_{m}}{m!}
\end{aligned}
$$

Đặt $B(z) = \sum\limits_{i\ge 0}\dfrac{B_i}{i!}z^i$. Vì vế trái có dạng tích chập, nên:

$$
\begin{aligned}
B(z)\mathrm{e}^z &= z+B(z)\\
B(z)&=\dfrac{z}{\mathrm{e}^z - 1}
\end{aligned}
$$

Đặt $F_n(z) = \sum_{m\ge 0}\dfrac{S_m(n)}{m!}z^m$, khi đó:

$$
\begin{aligned}
F_n(z) &= \sum_{m\ge 0}\dfrac{S_m(n)}{m!}z^m\\
&= \sum_{m\ge 0}\sum_{i=0}^{n-1}\dfrac{i^mz^m}{m!}\\
\end{aligned}
$$

Đổi thứ tự lấy tổng:

$$
\begin{aligned}
F_n(z) &=\sum_{i=0}^{n-1}\sum_{m\ge 0}\dfrac{i^mz^m}{m!}\\
       &=\sum_{i=0}^{n-1}\mathrm{e}^{iz}\\
       &=\dfrac{\mathrm{e}^{nz} - 1}{\mathrm{e}^z - 1}\\
       &=\dfrac{z}{\mathrm{e}^z - 1}\cdot\dfrac{\mathrm{e}^{nz} - 1}{z}
\end{aligned}
$$

Thay $B(z)=\dfrac{z}{\mathrm{e}^z - 1}$:

$$
\begin{aligned}
F_n(z) &= B(z)\cdot\dfrac{\mathrm{e}^{nz} - 1}{z}\\
&= \left(\sum_{i\ge 0}\dfrac{B_i z^i}{i!} \right)\left(\sum_{i\ge 1}\dfrac{n^i z^{i - 1}}{i!}\right)\\
&= \left(\sum_{i\ge 0}\dfrac{B_i z^i}{i!} \right)\left(\sum_{i\ge 0}\dfrac{n^{i+1} z^{i}}{(i+1)!}\right)
\end{aligned}
$$

Vì $F_n(z) = \sum_{m\ge 0}\dfrac{S_m(n)}{m!}z^m$, tức $S_m(n)=m![z^m]F_n(z)$:

$$
\begin{aligned}
S_m(n)&=m![z^m]F_n(z)\\
             &= m!\sum_{i=0}^{m}\dfrac{B_i}{i!}\cdot\dfrac{n^{m-i+1}}{(m-i+1)!}\\
             &=\dfrac{1}{m+1}\sum_{i=0}^{m}\binom{m+1}{i}B_in^{m-i+1}
\end{aligned}
$$

Do đó điều phải chứng minh được suy ra.

??? note "Cài đặt tham khảo"
    ```cpp
    using ll = long long;
    constexpr int MAXN = 10000;
    constexpr int mod = 1e9 + 7;
    ll B[MAXN];        // Số Bernoulli
    ll C[MAXN][MAXN];  // Số tổ hợp
    ll inv[MAXN];      // Nghịch đảo (để tính số Bernoulli)
    
    void init() {
      // Tiền xử lý số tổ hợp
      for (int i = 0; i < MAXN; i++) {
        C[i][0] = C[i][i] = 1;
        for (int k = 1; k < i; k++) {
          C[i][k] = (C[i - 1][k] % mod + C[i - 1][k - 1] % mod) % mod;
        }
      }
      // Tiền xử lý nghịch đảo
      inv[1] = 1;
      for (int i = 2; i < MAXN; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
      }
      // Tiền xử lý số Bernoulli
      B[0] = 1;
      for (int i = 1; i < MAXN; i++) {
        ll ans = 0;
        if (i == MAXN - 1) break;
        for (int k = 0; k < i; k++) {
          ans += C[i + 1][k] * B[k];
          ans %= mod;
        }
        ans = (ans * (-inv[i + 1]) % mod + mod) % mod;
        B[i] = ans;
      }
    }
    ```
