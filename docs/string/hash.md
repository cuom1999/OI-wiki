<span id="định-nghĩa"></span>
## Định nghĩa

Định nghĩa một hàm $f$ ánh xạ chuỗi thành số nguyên; hàm $f$ này được gọi là hàm băm (hash).

Mong muốn của hàm $f$ là giúp kiểm tra hai chuỗi có bằng nhau hay không một cách thuận tiện.

<span id="ý-tưởng-của-hash"></span>
## Ý tưởng của hàm băm (hash)

Ý tưởng cốt lõi của hàm băm là ánh xạ dữ liệu đầu vào vào một miền giá trị nhỏ hơn và dễ so sánh.

??? warning "Cảnh báo"
    "Miền giá trị nhỏ hơn" có ý nghĩa khác nhau trong từng tình huống.
    
    Trong [bảng băm](../ds/hash.md), miền giá trị cần đủ nhỏ để chấp nhận được độ phức tạp không gian và thời gian tuyến tính.
    
    Với băm xâu, miền giá trị cần đủ nhỏ để so sánh nhanh ($10^9$, $10^{18}$ đều có thể so sánh nhanh).
    
    Đồng thời, để giảm tỉ lệ va chạm băm, miền giá trị cũng không được quá nhỏ.

<span id="tính-chất"></span>
## Tính chất

Cụ thể, hai tính chất quan trọng nhất của hàm băm có thể tóm tắt như sau:

1.  Khi giá trị của hàm băm khác nhau, hai chuỗi là khác nhau;

2.  Khi giá trị của hàm băm bằng nhau, hai chuỗi không nhất thiết bằng nhau (nhưng xác suất cao là bằng nhau; trường hợp lý tưởng là chúng luôn bằng nhau).

    Hiện tượng giá trị hàm băm bằng nhau nhưng chuỗi gốc khác nhau được gọi là va chạm băm.

<span id="giải-thích"></span>
## Giải thích

Cần quan tâm điều gì?

Độ phức tạp thời gian và độ chính xác của hàm băm.

Thông thường dùng phương pháp hash đa thức. Với một chuỗi $s$ có độ dài $l$, có thể định nghĩa hàm hash đa thức như sau: $f(s) = \sum_{i=1}^{l} s[i] \times b^{l-i} \pmod M$. Ví dụ, với chuỗi $xyz$, giá trị hash của nó là $xb^2+yb+z$.

Cần đặc biệt lưu ý rằng cũng có nhiều người dùng một định nghĩa khác cho hàm hash, cụ thể là $f(s) = \sum_{i=1}^{l} s[i] \times b^{i-1} \pmod M$. Theo định nghĩa này, cùng chuỗi $xyz$ sẽ có giá trị hash là $x+yb+zb^2$.

Cả hai cách định nghĩa hàm hash trên đều khả thi, nhưng công thức dùng để tính hash của chuỗi con (sẽ trình bày ở phần sau) sẽ khác nhau. Vì vậy cần đặc biệt cẩn trọng để **không nhầm lẫn hai cách hash khác nhau này**.

Do định nghĩa hash đầu tiên tính toán gọn hơn, được dùng phổ biến hơn, và có thể hiểu như một số trong hệ cơ số $b$, phần còn lại của bài viết sẽ thảo luận hàm hash được định nghĩa bằng $f(s) = \sum_{i=1}^{l} s[i] \times b^{l-i} \pmod M$.

Ngoài ra, để tiện lợi và để mở rộng modulo, trong C++ đôi khi có thể dùng `unsigned long long` để lưu kết quả của hàm hash. Do đặc tính của C++, điều này tương đương với việc đặt modulo $M$ là $2^{64}$, cũng là một lựa chọn tốt.

Độ chính xác sẽ được thảo luận ở phần sau.

<span id="phân-tích-tỉ-lệ-lỗi-của-hash"></span>
## Phân tích tỉ lệ lỗi của hàm băm

### Va chạm băm

Va chạm băm là hiện tượng hai chuỗi khác nhau được ánh xạ đến cùng một giá trị băm.

Giả sử không gian giá trị của hash (số lượng tất cả chuỗi có thể xuất hiện) là $d$, và số lần tính (số chuỗi cần tính) là $n$.

Khi đó xác suất xảy ra va chạm băm là:

$$
p(n,d) = 1 - \frac{d!}{d^n\left(d-n\right)!} \approx 1 - \exp(-\frac{n(n-1)}{2d} )
$$

??? note "Chứng minh"
    Khi mỗi giá trị hash được sinh ra với xác suất như nhau, xác suất không xảy ra va chạm băm là:
    
    $$
    \overline{p}(n,d) = 1 \cdot \left (1 - \frac{1}{d} \right) \cdot \left ( 1- \frac{2}{d}\right) \cdots \left ( 1- \frac{n-1}{d}\right)
    $$
    
    Rút gọn được:
    
    $$
    \begin{aligned}
    \overline{p}(n,d) 
    & = \frac{d}{d}\cdot \frac{d-1}{d}\cdot \frac{d-2}{d} \cdots \frac{d-n+1}{d}\\
    & = \frac{d\cdot (d-1)\cdot (d-2)\cdots(d-n+1)}{d^n}\\
    & = \frac{d!}{d^n\left(d-n\right)!}
    \end{aligned}
    $$
    
    Vậy xác suất xảy ra va chạm băm là:
    
    $$
    p(n,d) = 1 - \frac{d!}{d^n\left(d-n\right)!}
    $$
    
    Công thức này vẫn quá phức tạp, cần rút gọn thêm.
    
    Theo công thức Taylor:
    
    $$
    \exp(x) = \sum_{k=0}^{\infty}\frac{x^k}{k!}=1+x+\frac{x^2}{2}+\frac{x^3}{6}+\frac{x^4}{24}+\cdots
    $$
    
    Khi $x$ là một giá trị rất nhỏ, $\exp(x)$ tiến gần đến $1+x$.
    
    Thay vào công thức gốc của xác suất không va chạm băm:
    
    $$
    \overline{p}(n,d) \approx 1 \cdot \exp(-\frac{1}{d}) \cdot \exp(-\frac{2}{d}) \cdots \exp(-\frac{n-1}{d})
    $$
    
    Rút gọn:
    
    $$
    \begin{aligned}
    \overline{p}(n,d) & \approx \exp(-\frac{1}{d} - \frac{2}{d} - \cdots -\frac{n-1}{d})\\
    &=\exp(-\frac{n(n-1)}{2d} )
    \end{aligned}
    $$
    
    Do đó xác suất xảy ra va chạm băm là:
    
    $$
    p(n,d) \approx 1 - \exp(-\frac{n(n-1)}{2d})
    $$

### Đánh bại hash modulo lớn

Xét công thức:

$$
p(n,d) \approx 1 - \exp(-\frac{n(n-1)}{2d} )
$$

Để đánh bại hash, cần thỏa mãn các điều kiện sau:

1.  $d$ phải lớn hơn modulo.
2.  $1-p(d,n)$ càng nhỏ càng tốt.

Lấy một ví dụ:

Nếu bảng chữ cái gồm **chữ cái hoa, chữ cái thường và chữ số**, và modulo là $10^9+7$:

$\log_{62}10^9+7\approx 6$

$p(10^6,62^{6}) \approx 0.9$

Vì vậy trong phạm vi này, nếu sinh ngẫu nhiên $10^6$ chuỗi có độ dài $6$, xác suất chúng có cùng giá trị hash có thể cao đến $90\%$.

### Đánh bại hash tràn tự nhiên

Vì loại hash này có modulo quá lớn, không thể đánh bại bằng cách trên, nên cần một phương pháp khác.

Trước hết, dạng hash này có dạng $f(s) = \sum_{i=1}^{l} s[i] \times b^{l-i}$; phân loại theo $b$ để thảo luận.

<span id="khi-b-là-số-chẵn"></span>
#### Khi b là số chẵn

Lúc này $f(s) = s_1\cdot b^{l-1} + s_2\cdot b^{l-2} + \cdots + s_l \pmod M$, trong đó $M$ là $2^{64}$.

Nếu hai chuỗi chỉ khác nhau ở ký tự đầu và có độ dài lớn hơn $64$, thì phần chênh lệch ở ký tự đầu chia hết cho $M$.

Vậy chỉ cần xây dựng các chuỗi có dạng:

`aaa...a`

`baa...a`

và có độ dài lớn hơn $64$ là có thể tạo va chạm.

<span id="khi-b-là-số-lẻ"></span>
#### Khi b là số lẻ

Định nghĩa $!s_i$ là chuỗi thu được khi đổi từng ký tự trong $s_i$.

Ví dụ:

$s_i = abaab$

$!s_i = babba$

Tức là biến `a` thành `b`, và biến `b` thành `a`.

Tiếp theo, định nghĩa $hash_i$ là giá trị hash của $s_i$, và $!hash_i$ là giá trị hash của $!s_i$.

Liên tục xây dựng $s_i = s_{i-1} + !s_{i-1}$.

$s_{12}$ và $!s_{12}$ chính là hai chuỗi cần tìm.

??? note "Suy luận"
    Trước hết, có:
    
    $$
    \begin{aligned}
    hash_i = hash_{i-1}\cdot base^{2^{i-2}} + !hash_{i-1}\\
    !hash_{i} = !hash_{i-1}\cdot base^{2^{i-2}}+hash_{i-1}
    \end{aligned}
    $$
    
    Thử lấy hiệu:
    
    $$
    \begin{aligned}
    &hash_i - !hash_i\\
    =\ &hash_{i-1}\cdot base^{2^{i-2}} + !hash_{i-1}-(!hash_{i-1}\cdot base^{2^{i-2}}+hash_{i-1})\\
    =\ &(hash_{i-1}-!hash_{i-1})\cdot (base^{2^{i-2}}-1)
    \end{aligned}
    $$
    
    Xuất hiện $2^i$, nhưng biểu thức gốc quá phức tạp, nên thử đổi biến:
    
    Đặt:
    
    $$
    \begin{aligned}
    f_i = hash_i - !hash_i\\
    g_i = base^{2^{i-2}}-1
    \end{aligned}
    $$
    
    Từ biểu thức gốc suy ra:
    
    $$
    \begin{aligned}
    f_i &= f_{i-1} \cdot g_i\\
        &=f_1 \cdot g_1 \cdot g_2 \cdots g_{i-1}\\
    \end{aligned}
    $$
    
    Vì $base^{2^{i-2}}$ là số lẻ, nên $g_i$ là số chẵn.
    
    Do đó:
    
    $$
    2^{i-1} | f_i
    $$
    
    Nhưng như vậy vẫn quá lớn, phải có $i-1\ge 64$ mới đánh bại được; tiếp tục rút gọn:
    
    $$
    g_i = base^{2^{i-2}}-1 = (base^{2^{i-3}}-1)\cdot(base^{2^{i-3}}+1)
    $$
    
    Tức là $g_i$ có dạng $g_{i-1} \cdot c\ (c \equiv 0 \pmod 2)$.
    
    Vậy $2 | g_1$, $4 | g_2$, ..., tức là
    
    $$
    \begin{aligned}
    & 2^i &| g_i\\
    &2^1\cdot2^2\cdot2^3\cdots2^{i-1} &| f_i\\
    &2^{i(i-1)/2} &| f_i
    \end{aligned}
    $$
    
    Nghĩa là khi $i=12$, có thể làm cho $2^{64} | hash_i - !hash_i$ và đạt yêu cầu.

<span id="bài-tập-ví-dụ"></span>
### Bài tập ví dụ

???+ note "[Ví dụ: BZOJ 3097 Hash Killer I](https://hydro.ac/p/bzoj-P3097)"
    Cho một hash được cài đặt bằng **tràn tự nhiên**; yêu cầu xây dựng một chuỗi để đánh bại nó.

???+ note "[Ví dụ: BZOJ 3097 Hash Killer II](https://hydro.ac/p/bzoj-P3098)"
    Cho một hash được cài đặt bằng **modulo lớn**; yêu cầu xây dựng một chuỗi để đánh bại nó.

???+ note "[Ví dụ: Luogu U461211 Băm xâu (dữ liệu tăng cường)](https://www.luogu.com.cn/problem/U461211)"
    Cho $n$ chuỗi, xác định có bao nhiêu chuỗi khác nhau.

## Cải tiến hash

<span id="hash-nhiều-giá-trị"></span>
### Hàm băm nhiều giá trị

Sau khi xét nhiều cách đánh bại hash ở trên, vẫn có các phương pháp khắc phục.

Hàm băm nhiều giá trị nghĩa là dùng nhiều hàm hash, mỗi hàm hash có modulo khác nhau; như vậy có thể giảm rủi ro va chạm băm.

Khi so sánh, chỉ cần một trong các giá trị hash khác nhau thì coi hai chuỗi là khác nhau; nếu tất cả giá trị hash đều giống nhau thì coi hai chuỗi là giống nhau.

Thông thường, hash hai giá trị là đủ dùng.

<span id="nhiều-truy-vấn-hash-chuỗi-con"></span>
### Nhiều truy vấn băm chuỗi con

Tính hash của một chuỗi một lần có độ phức tạp $O(n)$, trong đó $n$ là độ dài chuỗi; điều này không khác gì so khớp vét cạn. Nếu cần truy vấn hash của các chuỗi con trong cùng một chuỗi nhiều lần, tính lại mỗi lần sẽ rất kém hiệu quả.

Cách làm thông dụng là tiền xử lý giá trị hash của mỗi tiền tố trong toàn bộ chuỗi. Xem giá trị hash như kết quả của một số hệ cơ số $b$ lấy theo môđun $M$, khi đó mỗi lần có thể tính nhanh hash của chuỗi con:

Gọi $f_i(s)$ là $f(s[1..i])$, tức giá trị hash của tiền tố độ dài $i$ của chuỗi gốc. Theo định nghĩa, có $f_i(s)=s[1]\cdot b^{i-1}+s[2]\cdot b^{i-2}+\dots+s[i-1]\cdot b+s[i]$.

Bây giờ cần tính nhanh $f(s[l..r])$ theo cách tương tự tổng tiền tố. Theo định nghĩa, giá trị hash của chuỗi $s[l..r]$ là $f(s[l..r])=s[l]\cdot b^{r-l}+s[l+1]\cdot b^{r-l-1}+\dots+s[r-1]\cdot b+s[r]$.

So sánh hai công thức trên, có $f(s[l..r])=f_r(s)-f_{l-1}(s) \times b^{r-l+1}$ (có thể thay giá trị vào để kiểm tra). Vì vậy có thể dùng công thức này để tính nhanh hash của chuỗi con. Trong đó, có thể tiền xử lý $b^{r-l+1}$ trong $O(n)$ rồi trả lời mỗi truy vấn trong $O(1)$ (cũng có thể dùng lũy thừa nhanh để trả lời mỗi truy vấn trong $O(\log n)$).

<span id="cài-đặt"></span>
## Cài đặt

<span id="hash-modulo"></span>
### Hash theo môđun

Ghi chú: hiệu năng thấp, không khuyến nghị dùng trong thực tế.

=== "C++"
    ```cpp
    using std::string;
    
    constexpr int M = 1e9 + 7;
    constexpr int B = 233;
    
    using ll = long long;
    
    int get_hash(const string& s) {
      int res = 0;
      for (int i = 0; i < s.size(); ++i) {
        res = ((ll)res * B + s[i]) % M;
      }
      return res;
    }
    
    bool cmp(const string& s, const string& t) {
      return get_hash(s) == get_hash(t);
    }
    ```

=== "Python"
    ```python
    M = int(1e9 + 7)
    B = 233
    
    
    def get_hash(s):
        res = 0
        for char in s:
            res = (res * B + ord(char)) % M
        return res
    
    
    def cmp(s, t):
        return get_hash(s) == get_hash(t)
    ```

<span id="hash-hai-giá-trị"></span>
### Hash kép (hai giá trị)

=== "C++"
    ```cpp
    using ull = unsigned long long;
    ull base = 131;
    ull mod1 = 212370440130137957, mod2 = 1e9 + 7;
    
    ull get_hash1(std::string s) {
      int len = s.size();
      ull ans = 0;
      for (int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod1;
      return ans;
    }
    
    ull get_hash2(std::string s) {
      int len = s.size();
      ull ans = 0;
      for (int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod2;
      return ans;
    }
    
    bool cmp(const std::string s, const std::string t) {
      bool f1 = get_hash1(s) == get_hash1(t);
      bool f2 = get_hash2(s) == get_hash2(t);
      return f1 && f2;
    }
    ```

=== "Python"
    ```python
    def get_hash1(s: str) -> int:
        base = 131
        mod1 = 212370440130137957
        ans = 0
        for char in s:
            ans = (ans * base + ord(char)) % mod1
        return ans
    
    
    def get_hash2(s: str) -> int:
        base = 131
        mod2 = 1000000007
        ans = 0
        for char in s:
            ans = (ans * base + ord(char)) % mod2
        return ans
    
    
    def cmp(s: str, t: str) -> bool:
        f1 = get_hash1(s) == get_hash1(t)
        f2 = get_hash2(s) == get_hash2(t)
        return f1 and f2
    ```

## Ứng dụng của hash

<span id="so-khớp-chuỗi"></span>
### So khớp chuỗi

Sau khi tính giá trị hash của mẫu, tính giá trị hash của mỗi chuỗi con trong văn bản có độ dài bằng độ dài mẫu, rồi lần lượt so sánh với giá trị hash của mẫu.

<span id="so-khớp-chuỗi-cho-phép-k-vị-trí-khác-nhau"></span>
### So khớp chuỗi cho phép $k$ vị trí khác nhau

Bài toán: Cho chuỗi nguồn $s$ độ dài $n$ và chuỗi mẫu $p$ độ dài $m$, yêu cầu tìm trong chuỗi nguồn có bao nhiêu chuỗi con khớp với chuỗi mẫu. $s'$ khớp với $p$ khi và chỉ khi $s'$ và $p$ có cùng độ dài, và có nhiều nhất $k$ vị trí có ký tự khác nhau. Trong đó $1\leq n,m\leq 10^6$, $0\leq k\leq 5$.

Bài này không thể giải bằng KMP, nhưng có thể giải bằng hash + tìm kiếm nhị phân.

Liệt kê tất cả chuỗi con có thể khớp. Giả sử chuỗi con đang xét là $s'$, dùng hash + tìm kiếm nhị phân để nhanh chóng tìm vị trí đầu tiên mà $s'$ khác $p$. Sau đó xóa phần của $s'$ và $p$ tính đến hết vị trí sai khớp này, rồi tiếp tục tìm vị trí sai khớp tiếp theo. Quá trình này xảy ra tối đa $k$ lần.

Tổng độ phức tạp thời gian là $O(m+kn\log_2m)$.

<span id="chuỗi-con-đối-xứng-dài-nhất"></span>
### Chuỗi con đối xứng dài nhất

Tìm kiếm nhị phân đáp án; khi kiểm tra tính khả thi, liệt kê tâm đối xứng (trục đối xứng), rồi dùng hash để kiểm tra hai phía có bằng nhau hay không. Cần tiền xử lý riêng giá trị hash xuôi và ngược. Độ phức tạp thời gian $O(n\log n)$.

Bài toán này có thể giải bằng [thuật toán Manacher](./manacher.md) trong thời gian $O(n)$.

Phương pháp hash cũng có thể giải bài này trong $O(n)$. Cách làm cụ thể là đặt $R_i$ là độ dài chuỗi đối xứng dài nhất kết thúc tại $i$, khi đó đáp án là $\max_{i=1}^nR_i$. Vì $R_i\leq R_{i-1}+2$, chỉ cần vét cạn giảm dần từ $R_{i-1}+2$ cho đến khi tìm được chuỗi đối xứng đầu tiên. Đặt biến $z$ là $R_i$ đang liệt kê, ban đầu bằng $0$; mỗi khi $i$ tăng, $z$ sẽ tăng thêm $2$, sau đó mỗi lần lặp vét cạn sẽ giảm $1$, nên vòng lặp vét cạn xảy ra tối đa $2n$ lần. Tổng độ phức tạp thời gian là $O(n)$.

<span id="chuỗi-con-chung-dài-nhất"></span>
### Chuỗi con chung dài nhất

Bài toán: Cho $m$ chuỗi không rỗng có tổng độ dài không vượt quá $n$, tìm chuỗi con chung dài nhất của tất cả các chuỗi; nếu có nhiều đáp án, in ra một đáp án bất kỳ. Trong đó $1\leq m, n\leq 10^6$.

Nếu tồn tại chuỗi con chung dài nhất có độ dài $k$, thì chuỗi con chung độ dài $k-1$ cũng tồn tại. Vì vậy có thể tìm kiếm nhị phân độ dài của chuỗi con chung dài nhất. Giả sử độ dài hiện tại là $k$, logic của `check(k)` là: tính hash tất cả chuỗi con độ dài $k$ của từng chuỗi, rồi lưu các giá trị hash vào $n$ bảng băm. Sau đó lấy giao các bảng băm là đủ.

Độ phức tạp thời gian là $O(m+n\log n)$.

<span id="xác-định-số-lượng-chuỗi-con-khác-nhau-trong-một-chuỗi"></span>
### Xác định số lượng chuỗi con khác nhau trong một chuỗi

Bài toán: Cho chuỗi độ dài $n$ chỉ gồm các chữ cái thường tiếng Anh, tìm số lượng chuỗi con khác nhau của chuỗi đó.

Để giải bài toán này, duyệt tất cả chuỗi con có độ dài $l=1,\cdots ,n$. Với mỗi độ dài $l$, nhân giá trị hash của chuỗi con với cùng một lũy thừa của $b$ rồi lưu vào một mảng. Số lượng phần tử khác nhau trong mảng bằng số lượng chuỗi con khác nhau có độ dài $l$ trong chuỗi; cộng số này vào đáp án cuối cùng.

Để tiện lợi, dùng $h[i]$ làm giá trị hash tiền tố và định nghĩa $h[0]=0$.

??? note "Mã tham khảo"
    ```cpp
    int count_unique_substrings(string const& s) {
      int n = s.size();
    
      constexpr static int b = 31;
      constexpr static int m = 1e9 + 9;
      vector<long long> b_pow(n);
      b_pow[0] = 1;
      for (int i = 1; i < n; i++) b_pow[i] = (b_pow[i - 1] * b) % m;
    
      vector<long long> h(n + 1, 0);
      for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * b_pow[i]) % m;
    
      int cnt = 0;
      for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
          long long cur_h = (h[i + l] + m - h[i]) % m;
          cur_h = (cur_h * b_pow[n - i - 1]) % m;
          hs.insert(cur_h);
        }
        cnt += hs.size();
      }
      return cnt;
    }
    ```

<span id="bài-tập-ví-dụ_1"></span>
### Bài tập ví dụ

???+ note "[CF1200E Nén các từ](http://codeforces.com/contest/1200/problem/E)"
    Cho nhiều chuỗi. Chuỗi đáp án ban đầu rỗng. Ở bước thứ $i$, thêm chuỗi thứ $i$ vào cuối chuỗi đáp án, nhưng cố gắng loại bỏ phần lặp (tức loại bỏ chuỗi dài nhất vừa là hậu tố của đáp án hiện tại, vừa là tiền tố của chuỗi thứ $i$). Tìm chuỗi cuối cùng thu được.
    
    Số lượng chuỗi không vượt quá $10^5$, tổng độ dài không vượt quá $10^6$.
    
    ??? note "Lời giải"
        Mỗi lần cần tìm chuỗi dài nhất vừa là hậu tố của đáp án hiện tại, vừa là tiền tố của chuỗi thứ $i$. Liệt kê độ dài của chuỗi này và so sánh bằng hash là đủ.
        
        Ngoài ra, bài này cũng có thể giải bằng [thuật toán KMP](./kmp.md).
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/string/code/hash/hash_1.cpp"
        ```

**Một phần nội dung của trang này được dịch từ bài viết [строковый хеш](https://github.com/e-maxx-eng/e-maxx-eng/blob/61aff51f658644424c5e1b717f14fb7bf054ae80/src/string/string-hashing.md) và bản dịch tiếng Anh [băm chuỗi](https://cp-algorithms.com/string/string-hashing.html). Giấy phép của bản tiếng Nga là Public Domain + Leave a Link; giấy phép của bản tiếng Anh là CC-BY-SA 4.0.**
