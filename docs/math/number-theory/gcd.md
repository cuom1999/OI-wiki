<span id="định-nghĩa"></span>
## Định nghĩa

Ước chung lớn nhất trong tiếng Anh là Greatest Common Divisor, thường viết tắt
là gcd.

Ước chung của một tập số nguyên là số đồng thời là ước của mọi số trong tập đó.
$\pm 1$ là ước chung của mọi tập số nguyên.

Ước chung lớn nhất của một tập số nguyên là số lớn nhất trong tất cả các ước
chung.

Với hai số nguyên $a,b$ không đồng thời bằng $0$, ước chung lớn nhất của chúng
được ký hiệu là $\gcd(a,b)$; khi không gây nhầm lẫn có thể viết gọn là
$(a,b)$.

Với các số nguyên $a_1,\dots,a_n$ không đồng thời bằng $0$, ước chung lớn nhất
của chúng được ký hiệu là $\gcd(a_1,\dots,a_n)$; khi không gây nhầm lẫn có thể
viết gọn là $(a_1,\dots,a_n)$.

Tính chất của ước chung lớn nhất và bội chung nhỏ nhất xem tại [cơ sở lý thuyết
số](./basic.md#ước-chung-lớn-nhất-và-bội-chung-nhỏ-nhất).

Vậy làm thế nào để tìm ước chung lớn nhất? Trước hết xét trường hợp hai số.

<span id="thuật-toán-euclid"></span>
### Thuật toán Euclid

<span id="quá-trình-thuật-toán-euclid"></span>
#### Quá trình

Nếu biết hai số $a$ và $b$, làm thế nào để tìm ước chung lớn nhất của chúng?

Giả sử $a > b$.

Nếu $b$ là ước của $a$, thì $b$ chính là ước chung lớn nhất của hai số. Sau đây
xét trường hợp không chia hết, tức $a = b \times q + r$, trong đó $r < b$.

Có thể chứng minh $\gcd(a,b)=\gcd(b,a \bmod b)$ như sau:

???+ note "Chứng minh"
    Đặt $a=bk+c$, khi đó $c=a \bmod b$. Nếu $d \mid a,~d \mid b$ thì
    $c=a-bk, \frac{c}{d}=\frac{a}{d}-\frac{b}{d}k$.
    
    Từ vế phải suy ra $\frac{c}{d}$ là số nguyên, tức $d \mid c$. Vì vậy mọi
    ước chung của $a,b$ cũng là ước chung của $b,a \bmod b$.
    
    Chiều ngược lại cũng cần chứng minh:
    
    Nếu $d \mid b,~d\mid (a \bmod b)$, tương tự có
    $\frac{a\bmod b}{d}=\frac{a}{d}-\frac{b}{d}k,~\frac{a\bmod b}{d}+\frac{b}{d}k=\frac{a}{d}$.
    
    Vì vế trái là số nguyên, $\frac{a}{d}$ cũng là số nguyên, tức
    $d \mid a$. Vì vậy mọi ước chung của $b,a\bmod b$ cũng là ước chung của
    $a,b$.
    
    Hai cặp có cùng tập ước chung, nên ước chung lớn nhất cũng bằng nhau.
    
    Do đó $\gcd(a,b)=\gcd(b,a\bmod b)$.

Sau khi có $\gcd(a, b) = \gcd(b, r)$, kích thước của cặp số giảm xuống, nên thu
được một cách đệ quy để tính ước chung lớn nhất của hai số.

<span id="cài-đặt-thuật-toán-euclid"></span>
#### Cài đặt

=== "C++"
    ```cpp
    // Version 1
    int gcd(int a, int b) {
      if (b == 0) return a;
      return gcd(b, a % b);
    }
    
    // Version 2
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    ```

=== "Java"
    ```java
    // Version 1
    public int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    // Version 2
    public int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    ```

=== "Python"
    ```python
    def gcd(a, b):
        if b == 0:
            return a
        return gcd(b, a % b)
    ```

Đệ quy đến khi `b == 0` (tức `a % b == 0` ở bước trước) thì trả về giá trị.

Từ cách đệ quy trên, cũng có thể viết bản lặp:

=== "C++"
    ```cpp
    int gcd(int a, int b) {
      while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
      }
      return a;
    }
    ```

=== "Java"
    ```java
    public int gcd(int a, int b) {
        while(b != 0) {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
    }
    ```

=== "Python"
    ```python
    def gcd(a, b):
        while b != 0:
            a, b = b, a % b
        return a
    ```

Các thuật toán trên đều có thể gọi là thuật toán Euclid (tiếng Anh: Euclidean algorithm).

Ngoài ra, với C++17, có thể dùng
[`std::gcd`](https://en.cppreference.com/w/cpp/numeric/gcd) và
[`std::lcm`](https://en.cppreference.com/w/cpp/numeric/lcm) trong tệp tiêu đề
[`<numeric>`](https://en.cppreference.com/w/cpp/header/numeric) để tính ước
chung lớn nhất và bội chung nhỏ nhất.

???+ warning "Lưu ý"
    Trong một số trình biên dịch, C++14 có thể dùng hàm `std::__gcd(a,b)` để
    tính ước chung lớn nhất, nhưng hàm này chỉ là hàm phụ riêng của
    `std::rotate`.[^1] Dùng hàm này có thể gây các vấn đề ngoài dự kiến, nên
    nhìn chung không khuyến nghị.

Nếu hai số $a$ và $b$ thỏa mãn $\gcd(a, b) = 1$, gọi $a$ và $b$ là nguyên tố
cùng nhau.

<span id="tính-chất-thuật-toán-euclid"></span>
#### Tính chất

Thuật toán Euclid cần bao nhiêu bước chia lấy dư? Sau đây chứng minh: khi đầu
vào là hai số nguyên nhị phân có độ dài $n$, số bước đệ quy của thuật toán
Euclid là $O(n)$. Nói cách khác, nếu mặc định $a, b$ cùng bậc, số bước là
$O(\log\max(a, b))$.

???+ note "Chứng minh"
    Khi tính $\gcd(a,b)$, có hai trường hợp:
    
    -   $a < b$, khi đó $\gcd(a,b)=\gcd(b,a)$;
    -   $a \geq b$, khi đó $\gcd(a,b)=\gcd(b,a \bmod b)$, và phép lấy dư
        theo $a$ làm $a$ giảm ít nhất một nửa. Nghĩa là quá trình này xảy ra
        tối đa $O(\log a) = O(n)$ lần.
    
    Sau trường hợp thứ nhất luôn đến trường hợp thứ hai, nên số lần xảy ra
    trường hợp thứ nhất **không nhiều hơn** số lần xảy ra trường hợp thứ hai.
    
    Vì vậy chỉ cần đệ quy tối đa $O(n)$ lần là có kết quả.

Thực tế, nếu dùng thuật toán Euclid để tính ước chung lớn nhất của hai số kề
nhau trong [dãy Fibonacci](../combinatorics/fibonacci.md), thuật toán sẽ đạt số
bước xấu nhất.

<span id="thuật-toán-trừ-dần"></span>
### Thuật toán trừ dần

Với số lớn, phép lấy dư có độ phức tạp cao, còn cộng trừ thì thấp hơn. Vì
vậy có thể dùng cộng trừ thay cho nhân chia để tính ước chung lớn nhất.

<span id="quá-trình-thuật-toán-trừ-dần"></span>
#### Quá trình

Cho hai số $a$ và $b$, cần tính $\gcd(a,b)$.

Giả sử $a \ge b$. Nếu $a = b$, thì $\gcd(a,b)=a=b$. Nếu không, với mọi
$d\mid a$ và $d\mid b$, có thể chứng minh $d\mid a-b$.

Do đó **tất cả** ước chung của $a$ và $b$ đều là ước chung của $a-b$ và $b$,
nên $\gcd(a,b) = \gcd(a-b, b)$.

<span id="tối-ưu-hóa-bằng-thuật-toán-stein"></span>
#### Tối ưu hóa bằng thuật toán Stein

Nếu $a\gg b$, độ phức tạp $O(n)$ của thuật toán trừ dần sẽ rơi vào trường hợp
xấu nhất.

Xét một tối ưu: nếu $2\mid a,2\mid b$, thì
$\gcd(a,b) = 2\gcd\left(\dfrac a2, \dfrac b2\right)$.

Nếu không, giả sử $2\mid a$ (trường hợp $2\mid b$ tương tự). Vì trường hợp
$2\mid b$ đã được xét, nên $2 \nmid b$. Do đó
$\gcd(a,b)=\gcd\left(\dfrac a2,b\right)$.

Thuật toán sau khi tối ưu, tức thuật toán Stein, cần $O(\log\max(a,b))$ bước đệ
quy.

???+ note "Chứng minh"
    Nếu $2\mid a$ hoặc $2\mid b$, mỗi lần đệ quy sẽ làm ít nhất một trong hai
    số $a,b$ giảm một nửa.
    
    Nếu không, $2\mid a-b$, quay về trường hợp trên.
    
    Thuật toán đệ quy tối đa $O(\log n)$ lần.

<span id="cài-đặt-thuật-toán-stein"></span>
#### Cài đặt

Mẫu số độ chính xác cao xem tại [tính toán số lớn](../bignum.md).

Với số độ chính xác cao cần cài đặt: phép trừ, so sánh kích thước, dịch trái,
dịch phải (có thể thay bằng nhân chia độ chính xác thấp), số bit $0$ liên tiếp
ở cuối biểu diễn nhị phân (có thể tính vét cạn bằng cách kiểm tra chẵn lẻ).

??? note "C++"
    ```cpp
    Big gcd(Big a, Big b) {
      if (a == 0) return b;
      if (b == 0) return a;
      // Ghi số lần thừa số chung 2 xuất hiện trong a và b;
      // countr_zero là số bit 0 liên tiếp ở cuối biểu diễn nhị phân
      int atimes = countr_zero(a);
      int btimes = countr_zero(b);
      int mintimes = min(atimes, btimes);
      a >>= atimes;
      for (;;) {
        // Thừa số 2 chung của a và b đã được tính; về sau a không thể chẵn
        b >>= btimes;
        // Bảo đảm a <= b
        if (a > b) swap(a, b);
        b -= a;
        if (b == 0) break;
        btimes = countr_zero(b);
      }
      return a << mintimes;
    }
    ```

Đoạn mã trên tham khảo cách cài đặt C++17 `std::gcd` của
[libstdc++](https://github.com/gcc-mirror/gcc/blob/1667962ae755db27965778b8c8c684c6c0c4da21/libstdc%2B%2B-v3/include/std/numeric#L173)
và [MSVC](https://github.com/microsoft/STL/blob/9aca22477df4eed3222b4974746ee79129eb44e7/stl/inc/numeric#L591).
Trong phạm vi dữ liệu của `unsigned int` và `unsigned long long`, nếu có thể
tính `countr_zero` rất nhanh thì thuật toán Stein nhanh hơn thuật toán Euclid;
ngược lại nó có thể chậm hơn Euclid.

???+ note "Về countr_zero"
    1.  gcc có [hàm nội tại](../bit.md#hàm-nội-tại-của-gcc)
        `__builtin_ctz` (32 bit) hoặc `__builtin_ctzll` (64 bit), có thể thay
        cho `countr_zero` trong đoạn mã trên;
    2.  Từ C++20, tệp tiêu đề `<bit>` chứa
        [`std::countr_zero`](https://en.cppreference.com/w/cpp/numeric/countr_zero);
    3.  Nếu không dùng hàm ngoài thư viện chuẩn và cũng không dùng được C++20,
        đoạn mã sau là một cách cài đặt $O(1)$ sau tiền xử lý trong mô hình
        Word-RAM with multiplication:
    
    ```cpp
    constexpr int loghash[64] = {0,  32, 48, 56, 60, 62, 63, 31, 47, 55, 59, 61, 30,
                                 15, 39, 51, 57, 28, 46, 23, 43, 53, 58, 29, 14, 7,
                                 35, 49, 24, 44, 54, 27, 45, 22, 11, 37, 50, 25, 12,
                                 38, 19, 41, 52, 26, 13, 6,  3,  33, 16, 40, 20, 42,
                                 21, 10, 5,  34, 17, 8,  36, 18, 9,  4,  2,  1};
    
    int countr_zero(unsigned long long x) {
      return loghash[(x & -x) * 0x9150D32D8EB9EFC0Ui64 >> 58];
    }
    ```
    
    Với số độ chính xác cao, nếu cách cài đặt giống `bitset`, kết hợp với cách
    cài đặt `countr_zero` trên sẽ đạt độ phức tạp $O(n / w)$. Nếu không tiện
    tách theo bit nhị phân, chỉ có thể vét cạn để xác định thừa số là lũy thừa
    lớn nhất của $2$, và độ phức tạp phụ thuộc vào cách cài đặt. Ví dụ:
    
    ```cpp
    // Big nhị phân lưu theo little-endian, yêu cầu có thể duyệt từng phần tử
    int countr_zero(Big a) {
      int ans = 0;
      for (auto x : a) {
        if (x == 0) {
          ans += 32;  // độ dài bit của kiểu dữ liệu mỗi phần tử
        } else {
          return ans + countr_zero(x);
        }
      }
      return ans;
    }
    
    // Tính vét cạn; nếu cần dùng nên viết trực tiếp vào gcd để giảm hằng số
    int countr_zero(Big a) {
      int ans = 0;
      while ((a & 1) == 0) {
        a >>= 1;
        ++ans;
      }
      return ans;
    }
    ```

Đọc thêm thảo luận về tốc độ của các cách cài đặt `gcd` tại [Fastest way to
compute the greatest common divisor](https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/).

<span id="ước-chung-lớn-nhất-của-nhiều-số"></span>
### Ước chung lớn nhất của nhiều số

Vậy tính ước chung lớn nhất của nhiều số như thế nào? Đáp án phải là ước của
từng số, nên cũng phải là ước của mỗi cặp hai số liên tiếp. Dùng quy nạp có thể
chứng minh: mỗi lần lấy hai số ra tính đáp án rồi đưa lại vào sẽ không ảnh
hưởng đến đáp án cần tìm.

<span id="bội-chung-nhỏ-nhất"></span>
## Bội chung nhỏ nhất

Phần tiếp theo giới thiệu cách tính bội chung nhỏ nhất (Least Common Multiple,
LCM).

<span id="định-nghĩa-bội-chung-nhỏ-nhất"></span>
### Định nghĩa

Bội chung của một tập số nguyên là số đồng thời là bội của mọi số trong tập đó.
$0$ là bội chung của mọi tập số nguyên.

Bội chung nhỏ nhất của một tập số nguyên là số nhỏ nhất trong tất cả các bội
chung dương.

Với hai số nguyên $a,b$, bội chung nhỏ nhất của chúng được ký hiệu là
$\operatorname{lcm}(a,b)$; khi không gây nhầm lẫn có thể viết gọn là $[a,b]$.

Với các số nguyên $a_1,\dots,a_n$, bội chung nhỏ nhất của chúng được ký hiệu là
$\operatorname{lcm}(a_1,\dots,a_n)$; khi không gây nhầm lẫn có thể viết gọn là
$[a_1,\dots,a_n]$.

<span id="hai-số"></span>
### Hai số

Đặt $a = p_1^{k_{a_1}}p_2^{k_{a_2}} \cdots p_s^{k_{a_s}}$,
$b = p_1^{k_{b_1}}p_2^{k_{b_2}} \cdots p_s^{k_{b_s}}$.

Với $a$ và $b$, ước chung lớn nhất của chúng bằng

$p_1^{\min(k_{a_1}, k_{b_1})}p_2^{\min(k_{a_2}, k_{b_2})} \cdots p_s^{\min(k_{a_s}, k_{b_s})}$

bội chung nhỏ nhất bằng

$p_1^{\max(k_{a_1}, k_{b_1})}p_2^{\max(k_{a_2}, k_{b_2})} \cdots p_s^{\max(k_{a_s}, k_{b_s})}$

Vì $k_a + k_b = \max(k_a, k_b) + \min(k_a, k_b)$,

suy ra $\gcd(a, b) \times \operatorname{lcm}(a, b) = a \times b$.

Muốn tính bội chung nhỏ nhất của hai số, chỉ cần tính ước chung lớn nhất trước.

<span id="nhiều-số"></span>
### Nhiều số

Khi đã tính được $\gcd$ của hai số, việc tính bội chung nhỏ nhất là $O(1)$. Vì
vậy với nhiều số, không cần tính một ước chung lớn nhất chung rồi xử lý tiếp.
Cách trực tiếp là: sau khi tính $\gcd$ của hai số, thay vì đưa ước chung lớn
nhất đó vào dãy để tiếp tục tính với các số sau, chuyển sang đưa bội chung nhỏ
nhất vào dãy.

<span id="thuật-toán-euclid-mở-rộng"></span>
## Thuật toán Euclid mở rộng

Thuật toán Euclid mở rộng (Extended Euclidean algorithm, EXGCD) thường dùng để
tìm một nghiệm khả thi của $ax+by=\gcd(a,b)$.

<span id="quá-trình-thuật-toán-euclid-mở-rộng"></span>
### Quá trình

Đặt

$ax_1+by_1=\gcd(a,b)$

$bx_2+(a\bmod b)y_2=\gcd(b,a\bmod b)$

Theo định lý Euclid: $\gcd(a,b)=\gcd(b,a\bmod b)$.

Do đó $ax_1+by_1=bx_2+(a\bmod b)y_2$.

Lại vì $a\bmod b=a-(\lfloor\frac{a}{b}\rfloor\times b)$,

nên $ax_1+by_1=bx_2+(a-(\lfloor\frac{a}{b}\rfloor\times b))y_2$.

$ax_1+by_1=ay_2+bx_2-\lfloor\frac{a}{b}\rfloor\times by_2=ay_2+b(x_2-\lfloor\frac{a}{b}\rfloor y_2)$

Vì $a=a,b=b$, suy ra $x_1=y_2,y_1=x_2-\lfloor\frac{a}{b}\rfloor y_2$.

Liên tục thay $x_2,y_2$ vào đệ quy cho đến khi $b$ bằng $0$, rồi trả ngược với
$x=1,y=0$ để tính nghiệm.

<span id="cài-đặt-thuật-toán-euclid-mở-rộng"></span>
### Cài đặt

=== "C++"
    ```cpp
    int Exgcd(int a, int b, int &x, int &y) {
      if (!b) {
        x = 1;
        y = 0;
        return a;
      }
      int d = Exgcd(b, a % b, x, y);
      int t = x;
      x = y;
      y = t - (a / b) * y;
      return d;
    }
    ```

=== "Python"
    ```python
    def Exgcd(a, b):
        if b == 0:
            return a, 1, 0
        d, x, y = Exgcd(b, a % b)
        return d, y, x - (a // b) * y
    ```

Hàm trả về giá trị $\gcd$; trong quá trình đó tính được $x,y$.

<span id="phân-tích-miền-giá-trị"></span>
### Phân tích miền giá trị

Phương trình $ax+by=\gcd(a,b)$ có vô số nghiệm, và một số nghiệm có thể
làm tràn `long long`. May mắn là nếu $b\not= 0$, nghiệm khả thi do thuật toán
Euclid mở rộng tìm được luôn có $|x|\le b,|y|\le a$. Sau đây là chứng minh của
tính chất này.

??? note "Chứng minh"
    -   Khi $\gcd(a,b)=b$, có $a\bmod b=0$, nên đệ quy sẽ dừng ở tầng tiếp
        theo. Thu được $x_1=0,y_1=1$, và
        $a,b\ge 1\ge |x_1|,|y_1|$.
    -   Khi $\gcd(a,b)\not= b$, giả sử $|x_2|\le (a\bmod b),|y_2|\le b$.
        Vì $x_1=y_2,y_1=x_2-{\left\lfloor\dfrac{a}{b}\right\rfloor}y_2$, nên
        $|x_1|=|y_2|\le b,|y_1|\le|x_2|+|{\left\lfloor\dfrac{a}{b}\right\rfloor}y_2|\le (a\bmod b)+{\left\lfloor\dfrac{a}{b}\right\rfloor}|y_2|$
        $\le a-{\left\lfloor\dfrac{a}{b}\right\rfloor}b+{\left\lfloor\dfrac{a}{b}\right\rfloor}|y_2|\le a-{\left\lfloor\dfrac{a}{b}\right\rfloor}(b-|y_2|)$
        $a\bmod b=a-{\left\lfloor\dfrac{a}{b}\right\rfloor}b\le a-{\left\lfloor\dfrac{a}{b}\right\rfloor}(b-|y_2|)\le a$
        Do đó $|x_1|\le b,|y_1|\le a$ đúng.

<span id="viết-thuật-toán-euclid-mở-rộng-bằng-phương-pháp-lặp"></span>
### Viết thuật toán Euclid mở rộng bằng phương pháp lặp

Ban đầu, khi $x = 1$, $y = 0$, $x_1 = 0$, $y_1 = 1$, có:

$$
\begin{cases}
    ax + by     & = a \\
    ax_1 + by_1 & = b
\end{cases}
$$

đúng.

Biết $a\bmod b = a - (\lfloor \frac{a}{b} \rfloor \times b)$, đặt
$q = \lfloor \frac{a}{b} \rfloor$. Tham khảo cách lặp tính gcd, mỗi vòng lặp
có thể biểu diễn là:

$$
(a, b) \rightarrow (b, a - qb)
$$

Thay $a$ trong quá trình lặp bằng $ax + by = a$, thay $b$ bằng
$ax_1 + by_1 = b$, thu được:

$$
\begin{aligned}
                & \begin{cases}
                      ax + by     & = a \\
                      ax_1 + by_1 & = b
                  \end{cases}                    \\
    \rightarrow & \begin{cases}
                      ax_1 + by_1               & = b      \\
                      a(x - qx_1) + b(y - qy_1) & = a - qb
                  \end{cases}
\end{aligned}
$$

Từ đó có thể tính exgcd bằng phương pháp lặp.

Vì cách lặp tránh đệ quy, mã sẽ nhanh hơn bản đệ quy một chút.

```cpp
int gcd(int a, int b, int& x, int& y) {
  x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
```

Quan sát kỹ $a_1$ và $b_1$ sẽ nhận thấy chúng có giá trị hoàn toàn giống trong
bản lặp của thuật toán Euclid, và các công thức sau luôn đúng tại mọi thời điểm
(trước vòng `while` và sau mỗi lần lặp):
$x \cdot a +y \cdot b =a_1$ và $x_1 \cdot a +y_1 \cdot b= b_1$. Vì vậy, thuật
toán tính đúng $\gcd$.

Cuối cùng $a_1$ chính là $\gcd$ cần tìm, và có
$x \cdot a +y \cdot b = g$.

<span id="giải-thích-bằng-ma-trận"></span>
#### Giải thích bằng ma trận

Với hai số nguyên dương $a$ và $b$, một bước thuật toán Euclid
$\gcd(a,b)=\gcd(b,a\bmod b)$ có thể biểu diễn bằng ma trận:

$$
\begin{bmatrix}
b\\a\bmod b
\end{bmatrix}
=
\begin{bmatrix}
0&1\\1&-\lfloor a/b\rfloor
\end{bmatrix}
\begin{bmatrix}
a\\b
\end{bmatrix}
$$

Trong đó ký hiệu làm tròn xuống $\lfloor c\rfloor$ là số nguyên lớn nhất không
vượt quá $c$. Định nghĩa biến đổi
$\begin{bmatrix}a\\b\end{bmatrix}\mapsto \begin{bmatrix}0&1\\1&-\lfloor a/b\rfloor\end{bmatrix}\begin{bmatrix}a\\b\end{bmatrix}$.

Thuật toán Euclid chính là việc liên tục áp dụng biến đổi này, nên có

$$
\begin{bmatrix}
\gcd(a,b)\\0
\end{bmatrix}
=
\left(
\cdots 
\begin{bmatrix}
0&1\\1&-\lfloor a/b\rfloor
\end{bmatrix}
\begin{bmatrix}
1&0\\0&1
\end{bmatrix}
\right)
\begin{bmatrix}
a\\b
\end{bmatrix}
$$

Đặt

$$
\begin{bmatrix}
x_1&x_2\\x_3&x_4
\end{bmatrix}
=
\cdots 
\begin{bmatrix}
0&1\\1&-\lfloor a/b\rfloor
\end{bmatrix}
\begin{bmatrix}
1&0\\0&1
\end{bmatrix}
$$

Khi đó

$$
\begin{bmatrix}
\gcd(a,b)\\0
\end{bmatrix}
=
\begin{bmatrix}
x_1&x_2\\x_3&x_4
\end{bmatrix}
\begin{bmatrix}
a\\b
\end{bmatrix}
$$

Thỏa mãn $a\cdot x_1+b\cdot x_2=\gcd(a,b)$, tức thuật toán Euclid mở rộng. Lưu
ý việc nhân thêm một ma trận đơn vị ở cuối không ảnh hưởng đến kết quả; điều
này gợi ý có thể bắt đầu bằng cách duy trì một ma trận đơn vị $2\times 2$ để
viết phương pháp lặp gọn hơn:

```cpp
int exgcd(int a, int b, int &x, int &y) {
  int x1 = 1, x2 = 0, x3 = 0, x4 = 1;
  while (b != 0) {
    int c = a / b;
    std::tie(x1, x2, x3, x4, a, b) =
        std::make_tuple(x3, x4, x1 - x3 * c, x2 - x4 * c, b, a - b * c);
  }
  x = x1, y = x2;
  return a;
}
```

Cách diễn giải này gọn hơn so với đệ quy.

<span id="ứng-dụng"></span>
## Ứng dụng

-   [10104 - Euclid Problem](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045)
-   [GYM - (J) once upon a time](http://codeforces.com/gym/100963)
-   [UVa - 12775 - Gift Dilemma](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4628)

<span id="tài-liệu-tham-khảo-và-liên-kết"></span>
## Tài liệu tham khảo và liên kết

[^1]: [libstdc++: std Namespace Reference](https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.4/a00978.html#a2686a128df5a576cb53a1ed5f674607)
