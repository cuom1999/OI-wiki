author: inkydragon, TravorLZH, YOYO-UIAT, wood3, shuzhouliu, Mr-Python-in-China, HeRaNO, weilycoder

<span id="sàng-số-nguyên-tố"></span>
## Sàng số nguyên tố

<span id="giới-thiệu"></span>
### Giới thiệu

Nếu muốn biết có bao nhiêu số nguyên tố nhỏ hơn hoặc bằng $n$ thì làm thế nào?

Một ý tưởng tự nhiên là kiểm tra tính nguyên tố cho từng số không vượt quá
$n$. Cách vét cạn này không đạt độ phức tạp tối ưu.

<span id="sàng-eratosthenes"></span>
### Sàng Eratosthenes

<span id="quá-trình"></span>
#### Quá trình

Xét một nhận xét: với bất kỳ số nguyên dương $n$ lớn hơn $1$, bội $x$ của nó
là hợp số nếu $x > 1$. Dựa vào kết luận này, có thể tránh nhiều lần kiểm tra
không cần thiết.

Nếu xét từng số từ nhỏ đến lớn, đồng thời đánh dấu tất cả các bội số của số
hiện tại (lớn hơn chính nó) là hợp số, thì sau khi kết thúc, những số chưa bị
đánh dấu chính là số nguyên tố.

<span id="cài-đặt-eratosthenes"></span>
#### Cài đặt

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
            // Các bội từ 2 đến i - 1 đã được sàng trước đó, nên bắt đầu
            // trực tiếp từ bội của i để tăng tốc
            is_prime[j] = false;  // các bội của i đều không phải số nguyên tố
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

Trên đây là **sàng Eratosthenes** (gọi tắt là sàng Eratosthenes), có độ phức
tạp thời gian $O(n\log\log n)$.

???+ note "Chứng minh"
    Bây giờ xét quá trình suy ra:
    
    Nếu mỗi thao tác trên mảng tốn 1 đơn vị thời gian, độ phức tạp thời gian là:
    
    $$
    O\left(\sum_{k=1}^{\pi(n)}{\frac{n}{p_k}}\right)=O\left(n\sum_{k=1}^{\pi(n)}{\frac{1}{p_k}}\right)
    $$
    
    Trong đó $p_k$ là số nguyên tố nhỏ thứ $k$, $\pi(n)$ là số lượng số nguyên
    tố $\le n$. $\sum_{k=1}^{\pi(n)}$ biểu diễn vòng `for` lớp ngoài, với cận
    trên $\pi(n)$ là số lần `if (prime[i])` đi vào nhánh `true`;
    $\frac{n}{p_k}$ biểu diễn số lần thực hiện vòng `for` lớp trong.
    
    Theo định lý thứ hai của Mertens, tồn tại hằng số $B_1$ sao cho:
    
    $$
    \sum_{k=1}^{\pi(n)}{\frac{1}{p_k}}=\log\log n+B_1+O\left(\frac{1}{\log n}\right)
    $$
    
    Do đó độ phức tạp thời gian của **sàng Eratosthenes** là
    $O(n\log\log n)$. Tiếp theo chứng minh phiên bản yếu hơn của định lý thứ
    hai Mertens: $\sum_{k\le\pi(n)}1/p_k=O(\log\log n)$.
    
    Từ $\pi(n)=\Theta(n/\log n)$, suy ra số nguyên tố thứ $n$ có kích thước
    $\Theta(n\log n)$. Khi đó
    
    $$
    \begin{aligned}
    \sum_{k=1}^{\pi(n)}{\frac{1}{p_k}}
    &=O\left(\sum_{k=2}^{\pi(n)}{\frac{1}{k\log k}}\right) \\
    &=O\left(\int_2^{\pi(n)}{\frac{\mathrm dx}{x\log x}}\right) \\
    &=O(\log\log\pi(n))=O(\log\log n)
    \end{aligned}
    $$
    
    Tuy nhiên, cách trên vẫn chưa đủ nhanh trong thực tế; các phương pháp dưới
    đây có thể cải thiện hiệu năng một chút.

<span id="sàng-đến-căn-bậc-hai"></span>
#### Sàng đến căn bậc hai

Để tìm tất cả số nguyên tố đến $n$, chỉ cần sàng bằng các số nguyên tố
không vượt quá $\sqrt n$.

=== "C++"
    ```cpp
    vector<int> prime;
    bool is_prime[N];
    
    void Eratosthenes(int n) {
      is_prime[0] = is_prime[1] = false;
      for (int i = 2; i <= n; ++i) is_prime[i] = true;
      // i * i <= n nghĩa là i <= sqrt(n)
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
        # Cho i lặp đến <= sqrt(n)
        for i in range(2, isqrt(n) + 1):  # `isqrt` là hàm mới trong Python 3.8
            if is_prime[i]:
                for j in range(i * i, n + 1, i):
                    is_prime[j] = False
        for i in range(2, n + 1):
            if is_prime[i]:
                prime.append(i)
    ```

Tối ưu này không ảnh hưởng đến độ phức tạp tiệm cận. Trên thực tế, lặp lại
chứng minh trên sẽ thu được $n \ln \ln \sqrt n + o(n)$; theo tính chất của
logarit, chúng tương đương về tiệm cận, nhưng số thao tác giảm đáng kể.

<span id="chỉ-sàng-số-lẻ"></span>
#### Chỉ sàng số lẻ

Vì mọi số chẵn ngoài $2$ đều là hợp số, có thể bỏ qua trực tiếp và chỉ quan
tâm đến số lẻ.

Trước hết, cách này làm giảm một nửa nhu cầu bộ nhớ; tiếp theo, số thao tác cần
thiết cũng xấp xỉ giảm một nửa.

<span id="giảm-dung-lượng-bộ-nhớ"></span>
#### Giảm dung lượng bộ nhớ

Nhận thấy khi sàng chỉ cần mảng kiểu `bool`. Một phần tử của mảng `bool`
thường chiếm $1$ byte (tức $8$ bit), nhưng để lưu một giá trị boolean chỉ cần
$1$ bit.

Có thể dùng kiến thức về [thao tác bit](../bit.md) để nén mỗi giá trị boolean
vào một bit. Khi đó chỉ cần $n$ bit (tức $\dfrac n 8$ byte) thay vì $n$ byte,
giúp giảm đáng kể bộ nhớ. Cách này gọi là "nén ở mức bit".

Đáng lưu ý là có những cấu trúc dữ liệu tự động thực hiện nén mức bit, như
`vector<bool>` và `bitset<>` trong C++.

Ngoài ra, `vector<bool>` và `bitset<>` có tối ưu hằng số cho chương trình; sàng
Eratosthenes có độ phức tạp $O(n \log \log n)$ sau khi tối ưu bằng `bitset<>`
hoặc `vector<bool>` thậm chí có hiệu năng vượt qua sàng Euler có độ phức tạp
$O(n)$.

Xem [bitset: kết hợp với sàng Eratosthenes](../../lang/csl/bitset.md#kết-hợp-với-sàng-eratosthenes).

<span id="sàng-theo-khối"></span>
#### Sàng theo khối

Từ tối ưu "sàng đến căn bậc hai", không cần giữ toàn bộ mảng
`is_prime[1...n]`. Để sàng, chỉ cần giữ các số nguyên tố đến $\sqrt n$, tức
`prime[1...sqrt(n)]`, rồi chia toàn bộ miền thành các khối và sàng riêng từng
khối. Như vậy không cần giữ nhiều khối trong bộ nhớ cùng lúc, và CPU cũng xử lý
cache tốt hơn.

Gọi $s$ là một hằng số quyết định kích thước khối, khi đó có
$\lceil {\frac n s} \rceil$ khối, và khối $k$
($k = 0 \dots \lfloor {\frac n s} \rfloor$) chứa các số trong đoạn
$[ks, ks + s - 1]$. Xử lý từng khối lần lượt: với mỗi khối $k$, duyệt tất cả
các số nguyên tố (từ $1$ đến $\sqrt n$) và dùng chúng để sàng.

Cần lưu ý khi xử lý các số đầu tiên phải sửa chiến lược một chút: thứ nhất, cần
giữ tất cả số nguyên tố trong $[1, \sqrt n]$; thứ hai, số $0$ và $1$ phải được
đánh dấu là không phải số nguyên tố. Khi xử lý khối cuối, không được quên rằng
số cuối cùng $n$ không nhất thiết nằm ở cuối khối.

Cài đặt dưới đây dùng sàng theo khối để tính số lượng số nguyên tố không vượt
quá $n$.

???+ note "Cài đặt"
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

Độ phức tạp tiệm cận của sàng theo khối giống sàng Eratosthenes (trừ khi khối
quá nhỏ), nhưng bộ nhớ cần dùng giảm xuống $O(\sqrt{n} + S)$ và có hiệu quả
cache tốt hơn. Mặt khác, với mỗi cặp gồm một khối và một số nguyên tố trong
đoạn $[1, \sqrt{n}]$, đều phải thực hiện phép chia; với khối nhỏ, điều này
tệ hơn nhiều. Vì vậy cần cân bằng khi chọn hằng số $S$.

Kích thước khối $S$ trong khoảng $10^4$ đến $10^5$ thường cho tốc độ tốt nhất.

<span id="sàng-tuyến-tính"></span>
### Sàng tuyến tính

Sàng Eratosthenes vẫn còn không gian tối ưu, vì nó đánh dấu một hợp số nhiều
lần. Có cách nào bỏ qua các bước vô nghĩa này không? Câu trả lời là có.

Nếu mỗi hợp số chỉ bị đánh dấu một lần, độ phức tạp thời gian có thể giảm xuống
$O(n)$.

???+ note "Cài đặt"
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
                // Nói cách khác, i đã bị sàng bởi pri_j trước đó
                // Vì các số nguyên tố trong pri tăng dần, nên kết quả của i nhân
                // với các số nguyên tố khác sẽ bị sàng bởi bội của pri_j;
                // không cần sàng trước tại đây, nên break trực tiếp
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
                        Nói cách khác, i đã bị sàng bởi pri_j trước đó
                        Vì các số nguyên tố trong pri tăng dần, nên kết quả của i nhân
                        với các số nguyên tố khác sẽ bị sàng bởi bội của pri_j;
                        không cần sàng trước tại đây, nên break trực tiếp
                        """
                        break
        ```

Kiểu sàng trên được gọi là **sàng tuyến tính**, hay **sàng Euler**.

???+ note "Ghi chú"
    Khi dùng sàng để tìm số nguyên tố, đồng thời thu được thừa số nguyên tố
    nhỏ nhất của mỗi số.

<span id="tính-hàm-euler-bằng-sàng"></span>
## Tính hàm Euler bằng sàng

Trong sàng tuyến tính, mỗi hợp số đều bị sàng bởi thừa số nguyên tố nhỏ nhất.
Ví dụ, gọi $p_1$ là thừa số nguyên tố nhỏ nhất của $n$,
$n' = \frac{n}{p_1}$; trong quá trình sàng tuyến tính, $n$ bị sàng qua
$n' \times p_1$.

Quan sát quá trình sàng tuyến tính, còn cần xử lý hai phần; sau đây chia
trường hợp theo $n' \bmod p_1$.

Nếu $n' \bmod p_1 = 0$, thì $n'$ chứa tất cả thừa số nguyên tố của $n$.

$$
\begin{aligned}
\varphi(n) & = n \times \prod_{i = 1}^s{\frac{p_i - 1}{p_i}} \\\\
& = p_1 \times n' \times \prod_{i = 1}^s{\frac{p_i - 1}{p_i}} \\\\
& = p_1 \times \varphi(n')
\end{aligned}
$$

Còn nếu $n' \bmod p_1 \neq 0$ thì sao? Khi đó $n'$ và $p_1$ nguyên tố cùng
nhau; theo tính chất của hàm Euler, có:

$$
\begin{aligned}
\varphi(n) & = \varphi(p_1) \times \varphi(n') \\\\
& = (p_1 - 1) \times \varphi(n')
\end{aligned}
$$

<span id="cài-đặt-hàm-euler"></span>
### Cài đặt

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

<span id="tính-hàm-möbius-bằng-sàng"></span>
## Tính hàm Möbius bằng sàng

<span id="định-nghĩa-hàm-möbius"></span>
### Định nghĩa

Theo định nghĩa hàm Möbius, giả sử $n$ là hợp số, $p_1$ là thừa số nguyên tố
nhỏ nhất của $n$, $n'=\frac{n}{p_1}$, có:

$$
\mu(n)=
\begin{cases}
    0 & n' \bmod p_1 = 0\\\\
    -\mu(n') & \text{ngược lại}
\end{cases}
$$

Nếu $n$ là số nguyên tố, $\mu(n)=-1$.

<span id="cài-đặt-hàm-möbius"></span>
### Cài đặt

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

<span id="tính-số-lượng-ước-bằng-sàng"></span>
## Tính số lượng ước bằng sàng

Dùng $d_i$ để biểu diễn số lượng ước của $i$, và $num_i$ để biểu diễn số lần
xuất hiện của thừa số nguyên tố nhỏ nhất của $i$.

<span id="định-lý-về-số-lượng-ước"></span>
### Định lý về số lượng ước

Định lý: nếu $n=\prod_{i=1}^m p_i^{c_i}$ thì
$d_i=\prod_{i=1}^m (c_i+1)$.

Chứng minh: các ước của $p_i^{c_i}$ là
$p_i^0,p_i^1,\dots ,p_i^{c_i}$, tổng cộng $c_i+1$ ước. Theo quy tắc nhân, số
lượng ước của $n$ chính là $\prod_{i=1}^m (c_i+1)$.

<span id="cài-đặt-số-lượng-ước"></span>
### Cài đặt

Vì $d_i$ là hàm nhân tính, có thể dùng sàng tuyến tính.

Sau đây giới thiệu ngắn gọn nguyên lý cài đặt sàng tuyến tính.

1.  Khi $i$ là số nguyên tố, $\textit{num}_i \gets 1,\textit{d}_i \gets 2$;
    đồng thời đặt $q = \left\lfloor \dfrac {i}{p} \right\rfloor$, trong đó $p$
    là thừa số nguyên tố nhỏ nhất của $i$.
2.  Khi $p$ là thừa số nguyên tố của $q$,
    $\textit{num}_i \gets \textit{num}_q + 1,\textit{d}_i \gets \dfrac{\textit{d}_q}{\textit{num}_i} \times (\textit{num}_i + 1)$.
3.  Khi $p,q$ nguyên tố cùng nhau,
    $\textit{num}_i \gets 1,\textit{d}_i \gets \textit{d}_q \times (\textit{num}_i+1)$.

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

<span id="tính-tổng-ước-bằng-sàng"></span>
## Tính tổng ước bằng sàng

$f_i$ biểu diễn tổng các ước của $i$, $g_i$ biểu diễn
$p^0+p^1+p^2+\dots p^k$ ứng với thừa số nguyên tố nhỏ nhất của $i$.

<span id="cài-đặt-tổng-ước"></span>
### Cài đặt

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

<span id="hàm-nhân-tính-tổng-quát"></span>
## Hàm nhân tính tổng quát

Giả sử một [hàm nhân tính](./basic.md#hàm-nhân-tính) $f$
thỏa mãn: với mọi số nguyên tố $p$ và số nguyên dương $k$, có thể tính $f(p^k)$
trong thời gian đa thức bậc thấp theo $k$. Khi đó có thể sàng các giá trị
$f(1),f(2),\dots,f(n)$ trong thời gian $O(n)$.

Giả sử hợp số $n$ có phân tích thừa số nguyên tố là
$\prod_{i=1}^k p_i^{\alpha_i}$, trong đó $p_1<p_2<\dots<p_k$ là các số nguyên
tố. Trong sàng tuyến tính, lưu $g_n=p_1^{\alpha_1}$. Nếu $n$ bị sàng bởi
$x\cdot p$ (với $p$ là số nguyên tố), thì $g$ thỏa mãn truy hồi sau:

$$
g_n=
\begin{cases}
    g_x\cdot p & x\bmod p=0\\\\
    p & \text{ngược lại}
\end{cases}
$$

Nếu $n=g_n$, nghĩa là $n$ chính là lũy thừa của một số nguyên tố nào đó, có thể
tính $f(n)$ trong $O(1)$; ngược lại, $f(n)=f(\frac{n}{g_n})\cdot f(g_n)$.

**Một phần nội dung mục này được dịch từ bài viết [Resheto Eratosthena](http://e-maxx.ru/algo/eratosthenes_sieve)
và bản dịch tiếng Anh [Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html).
Bản tiếng Nga có giấy phép Public Domain + Leave a Link; bản tiếng Anh có giấy
phép CC-BY-SA 4.0.**
