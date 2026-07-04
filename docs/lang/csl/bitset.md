author: i-Yirannn, Xeonacid, ouuan

<span id="&#20171;&#32461;"></span>
## Giới thiệu

`std::bitset` là một container có kích thước cố định trong thư viện chuẩn, dùng để lưu các giá trị `0/1`. Nói chặt chẽ, nó không thuộc STL.

??? note "bitset và STL"
    > Thư viện chuẩn C++ cung cấp một số lớp container đặc biệt, gọi là container adapter (stack, queue, priority queue). Ngoài ra, một vài lớp cung cấp giao diện giống container, ví dụ string, bitset và valarray. Tất cả các lớp này được trình bày riêng. Container adapter và bitset được nói ở Chương 12.
    >
    > Thư viện chuẩn C++ không chỉ cung cấp các container cho khung STL, mà còn có những container phù hợp với các nhu cầu đặc biệt và đưa ra giao diện đơn giản, gần như tự giải thích. Có thể chia chúng thành container adapter, tức các lớp điều chỉnh container STL chuẩn cho nhu cầu đặc biệt, hoặc bitset, một container cho bit hay giá trị Boolean. Có ba container adapter chuẩn: stack, queue và priority queue. Trong priority queue, các phần tử được tự động sắp xếp theo một tiêu chí sắp xếp; vì vậy phần tử "kế tiếp" của priority queue là phần tử có giá trị "cao nhất". Bitset là một bitfield với số bit tùy ý nhưng cố định. Lưu ý rằng thư viện chuẩn C++ cũng cung cấp một container đặc biệt có kích thước thay đổi được cho giá trị Boolean: vector.
    
    Trích từ *The C++ Standard Library 2nd Edition*
    
    Như vậy, `bitset` không thuộc STL mà là một "Special Container" trong thư viện chuẩn. Trên thực tế, dù nó là một container, nó cũng không thỏa mãn các yêu cầu của container STL. Gọi nó là adapter cũng không chính xác, vì nó không dựa vào container STL nào khác làm tầng hiện thực bên dưới.

Vì địa chỉ bộ nhớ được đánh địa chỉ theo byte, chứ không phải theo bit, nên một biến kiểu `bool`, dù chỉ biểu diễn được `0/1`, vẫn chiếm 1 byte bộ nhớ.

`bitset` dùng cách tối ưu cố định để tám bit trong một byte có thể riêng rẽ lưu 8 giá trị `0/1`.

Với một biến `int` 4 byte, nếu chỉ xét mục đích lưu `0/1`, `bitset` chỉ tốn dung lượng bằng $\frac{1}{32}$ của nó; khi tính một số thông tin, thời gian cần thiết cũng chỉ bằng $\frac 1{32}$.

Trong một số trường hợp, `bitset` có thể tối ưu hiệu năng chạy của chương trình. Việc tối ưu này được xem là tối ưu độ phức tạp hay chỉ là hằng số phụ thuộc vào góc nhìn phân tích. Thông thường, độ phức tạp của `bitset` có các cách ghi sau (giả sử độ phức tạp ban đầu là $O(n)$):

1.  $O(n)$: cách ghi này xem như `bitset` hoàn toàn không tối ưu độ phức tạp.
2.  $O(\frac n{32})$: cách ghi này không thật chặt chẽ (không nên có hằng số trong ký hiệu độ phức tạp), nhưng thể hiện rằng `bitset` có thể giảm thời gian cần thiết xuống $\frac 1{32}$.
3.  $O(\frac n w)$, trong đó $w=32$ (số bit của máy tính); đây là cách ghi được chấp nhận phổ biến hơn.
4.  $O(\frac n {\log w})$, trong đó $w$ là kích thước của một biến số nguyên trên máy tính.

Ngoài ra, một phiên bản đặc biệt hóa của `vector`, là `vector<bool>`, có cách lưu trữ giống `bitset`. Điểm khác là nó hỗ trợ cấp phát kích thước động, còn `bitset` giống mảng tĩnh thông thường: kích thước được xác định từ lúc biên dịch. Tuy nhiên, `bitset` có một số hàm thư viện rất tiện dụng; chúng không chỉ thuận tiện mà đôi khi còn có thể được hiện thực bằng SIMD để giảm hằng số. Bên cạnh đó, một phần hành vi của `vector<bool>` không nhất quán với `vector` (ví dụ với `std::vector<bool> vec`, `&vec[0] + i` không bằng `&vec[i]`). Vì vậy thông thường không dùng `vector<bool>`.

<span id="&#20351;&#29992;"></span>
## Cách sử dụng

Xem [std::bitset - cppreference.com](https://en.cppreference.com/w/cpp/utility/bitset).

<span id="&#22836;&#25991;&#20214;"></span>
### Tệp tiêu đề

```cpp
#include <bitset>
```

<span id="&#25351;&#23450;&#22823;&#23567;"></span>
### Chỉ định kích thước

```cpp
std::bitset<1000> bs;  // một bitset gồm 1000 bit
```

<span id="&#26500;&#36896;&#20989;&#25968;"></span>
### Hàm khởi tạo

-   `bitset()`: mọi bit đều là `false`.
-   `bitset(unsigned long val)`: gán thành dạng nhị phân của `val`.
-   `bitset(const string& str)`: gán thành xâu $01$ `str`.

<span id="&#36816;&#31639;&#31526;"></span>
### Toán tử

-   `operator []`: truy cập một bit cụ thể.

-   `operator ==`/`operator !=`: so sánh xem nội dung hai `bitset` có hoàn toàn giống nhau hay không.

-   `operator &`/`operator &=`/`operator |`/`operator |=`/`operator ^`/`operator ^=`/`operator ~`: thực hiện các phép bitwise AND/OR/XOR/NOT.

    Lưu ý: **`bitset` chỉ có thể thực hiện phép toán bit với `bitset`**. Nếu muốn tính bitwise với số nguyên, cần chuyển số nguyên đó thành `bitset` trước.

-   `operator <<`/`operator >>`/`operator <<=`/`operator >>=`: thực hiện dịch trái/dịch phải nhị phân.

Ngoài ra, `bitset` còn hỗ trợ IO kiểu stream của C++, nghĩa là có thể nhập xuất bằng `cin`/`cout`.

<span id="&#25104;&#21592;&#20989;&#25968;"></span>
### Hàm thành viên

-   `count()`: trả về số bit có giá trị `true`.
-   `size()`: trả về kích thước của `bitset`.
-   `test(pos)`: có tác dụng giống `at()` trong `vector`; khác với toán tử `[]` ở chỗ có kiểm tra vượt biên.
-   `any()`: nếu tồn tại ít nhất một bit là `true` thì trả về `true`, ngược lại trả về `false`.
-   `none()`: nếu mọi bit đều là `false` thì trả về `true`, ngược lại trả về `false`.
-   `all()`: nếu mọi bit đều là `true` thì trả về `true`, ngược lại trả về `false`.
-   1.  `set()`: gán toàn bộ `bitset` thành `true`.
    2.  `set(pos, val = true)`: gán một bit cụ thể thành `true`/`false`.
-   1.  `reset()`: gán toàn bộ `bitset` thành `false`.
    2.  `reset(pos)`: gán một bit cụ thể thành `false`, tương đương `set(pos, false)`.
-   1.  `flip()`: lật mọi bit ($0\leftrightarrow1$, tương đương XOR với một `bitset` toàn bit $1$).
    2.  `flip(pos)`: lật một bit cụ thể.
-   `to_string()`: trả về biểu diễn xâu sau khi chuyển đổi.
-   `to_ulong()`: trả về biểu diễn `unsigned long` sau khi chuyển đổi (`long` giống `int` trên NT và hệ POSIX 32 bit, giống `long long` trên POSIX 64 bit).
-   `to_ullong()`: (từ **C++11**) trả về biểu diễn `unsigned long long` sau khi chuyển đổi.

Ngoài ra, trong libstdc++ có một số hàm thành viên nội bộ khá hữu dụng[^bitset1]:

-   `_Find_first()`: trả về chỉ số của bit `true` đầu tiên trong `bitset`; nếu không có bit `true` nào thì trả về kích thước của `bitset`.
-   `_Find_next(pos)`: trả về chỉ số của bit `true` đầu tiên nằm sau `pos` (vị trí có chỉ số lớn hơn hẳn `pos`); nếu sau `pos` không có bit `true` nào thì trả về kích thước của `bitset`.

<span id="&#24212;&#29992;"></span>
## Ứng dụng

<span id="libreoj-&#946;-round-2&#36138;&#24515;&#21482;&#33021;&#36807;&#26679;&#20363;"></span>
<span id="LibreOJ-&#946;-Round-2-&#36138;&#24515;&#21482;&#33021;&#36807;&#26679;&#20363;"></span>
### [LibreOJ β Round #2: Tham lam chỉ qua được ví dụ mẫu](https://loj.ac/problem/515)

Có thể giải bài này bằng DP, công thức chuyển rất đơn giản:

$f(i,j)$ biểu diễn việc tổng bình phương của $i$ số đầu có thể bằng $j$ hay không. Khi đó $f(i,j)=\bigvee\limits_{k=a}^bf(i-1,j-k^2)$ (lấy OR).

Nhưng nếu làm trực tiếp thì là $O(n^5)$, (có vẻ) không qua được.

Nhận thấy có thể dùng `bitset` để tối ưu: chỉ cần dịch trái rồi OR lại:

??? note "Bản nộp: [std::bitset](https://loj.ac/submission/395274)"
    ```cpp
    #include <bitset>
    #include <cstdio>
    #include <iostream>
    
    using namespace std;
    
    constexpr int N = 101;
    
    int n, a[N], b[N];
    bitset<N * N * N> f[N];
    
    int main() {
      int i, j;
    
      cin >> n;
    
      for (i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    
      f[0][0] = 1;
    
      for (i = 1; i <= n; ++i) {
        for (j = a[i]; j <= b[i]; ++j) {
          f[i] |= (f[i - 1] << (j * j));
        }
      }
    
      cout << f[n].count();
    
      return 0;
    }
    ```

Vì hiện thực của libstdc++ nén các bit theo từng nhóm `__CHAR_BIT__ * sizeof(unsigned long)`[^bitset2], trên một số nền là $32$. Do đó, có thể tự viết `bitset` (chỉ cần hỗ trợ thao tác dịch trái rồi OR) nén $64$ bit (`__CHAR_BIT__ * sizeof(unsigned long long)`) để tối ưu tiếp:

??? note "Bản nộp: [bitset tự viết](https://loj.ac/submission/395619)"
    ```cpp
    #include <cstdio>
    #include <iostream>
    
    using namespace std;
    
    constexpr int N = 101;
    constexpr int W = 64;
    
    struct Bitset {
      unsigned long long a[N * N * N >> 6];
    
      void shiftor(const Bitset &y, int p, int l, int r) {
        int t = p - p / W * W;
        int tt = (t == 0 ? 0 : W - t);
        int to = (r + p) / W;
        int qaq = (p + W - 1) / W;
    
        for (int i = (l + p) / W; i <= to; ++i) {
          if (i - qaq >= 0) a[i] |= y.a[i - qaq] >> tt;
    
          a[i] |= ((y.a[i - qaq + 1] & ((1ull << tt) - 1)) << t);
        }
      }
    } f[N];
    
    int main() {
      int n, a, b, l = 0, r = 0, ans = 0;
    
      scanf("%d", &n);
    
      f[0].a[0] = 1;
    
      for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a, &b);
    
        for (int j = a; j <= b; ++j) f[i].shiftor(f[i - 1], j * j, l, r);
    
        l += a * a;
        r += b * b;
      }
    
      for (int i = l / W; i <= r / W; ++i)
        ans += __builtin_popcount(f[n].a[i] & 0xffffffffu) +
               __builtin_popcount(f[n].a[i] >> 32);
    
      printf("%d", ans);
    
      return 0;
    }
    ```

Ngoài ra, cách vét cạn có thêm vài nhánh cắt tỉa cũng có thể qua:

??? note "Bản nộp: [vét cạn có vài nhánh cắt tỉa](https://loj.ac/submission/395673)"
    ```cpp
    #include <cstdio>
    #include <iostream>
    
    using namespace std;
    
    constexpr int N = 101;
    constexpr int W = 64;
    
    bool f[N * N * N];
    
    int main() {
      int n, i, j, k, a, b, l = 0, r = 0, ans = 0;
    
      scanf("%d", &n);
    
      f[0] = true;
    
      for (i = 1; i <= n; ++i) {
        scanf("%d%d", &a, &b);
        l += a * a;
        r += b * b;
    
        for (j = r; j >= l; --j) {
          f[j] = false;
    
          for (k = a; k <= b; ++k) {
            if (j - k * k < l - a * a) break;
    
            if (f[j - k * k]) {
              f[j] = true;
              break;
            }
          }
        }
      }
    
      for (i = l; i <= r; ++i) ans += f[i];
    
      printf("%d", ans);
    
      return 0;
    }
    ```

### [CF1097F Alex and a TV Show](https://codeforces.com/contest/1097/problem/F)

<span id="&#39064;&#24847;"></span>
#### Tóm tắt đề bài

Cho $n$ đa tập hợp, hỗ trợ bốn loại thao tác:

1.  Gán một đa tập hợp nào đó thành một số.
2.  Gán một đa tập hợp nào đó thành tổng của hai đa tập hợp khác.
3.  Gán một đa tập hợp nào đó thành tập các $\gcd$ khi chọn mỗi đa tập hợp khác một số. Cụ thể: $A=\{\gcd(x,y)|x\in B,y\in C\}$.
4.  Hỏi số lần xuất hiện của một số trong một đa tập hợp, **theo modulo 2**.

Số đa tập hợp là $10^5$, số thao tác là $10^6$, miền giá trị là $7000$.

<span id="&#20570;&#27861;"></span>
#### Cách làm

Thấy cụm "theo modulo $2$", ta có thể nghĩ đến việc dùng `bitset` để duy trì mỗi đa tập hợp.

Khi đó, thao tác $1$ gán trực tiếp, thao tác $2$ là XOR (vì tính theo modulo $2$), thao tác $4$ là truy vấn trực tiếp. Nhưng thao tác $3$ thì sao?

Ta có thể thử duy trì đa tập hợp gồm tất cả ước của các phần tử trong mỗi đa tập hợp. Khi đó thao tác $3$ chính là AND bitwise trực tiếp.

Có thể tiền xử lý `bitset` gồm các ước của mỗi số trong miền giá trị, như vậy thao tác $1$ được giải quyết. Thao tác $2$ vẫn là XOR.

Vấn đề lúc này là: làm sao từ đa tập hợp các ước của một đa tập hợp để lấy được số lần xuất hiện của một số trong đa tập hợp gốc.

Gọi đa tập hợp gốc là $A$, đa tập hợp các ước của nó là $A'$. Ta cần số lần xuất hiện của $x$ trong $A$; dùng [nghịch đảo Möbius](../../math/number-theory/mobius.md) để suy ra:

$$
\begin{aligned}&\sum\limits_{i\in A}[\frac i x=1]\\=&\sum\limits_{i\in A}\sum\limits_{d|\frac i x}\mu(d)\\=&\sum\limits_{d\in A',x|d}\mu(\frac d x)\end{aligned}
$$

Vì tính theo modulo $2$, $-1$ và $1$ là như nhau, nên chỉ cần xem $\frac d x$ có chứa thừa số bình phương hay không. Do đó, với mỗi số trong miền giá trị, có thể tiền xử lý `bitset` gồm các bội của nó mà sau khi chia cho nó thì không chứa thừa số bình phương. Khi tính đáp án, chỉ cần AND rồi `count()`.

Như vậy, độ phức tạp cho mỗi truy vấn là $O(\frac v w)$ ($v=7000,\,w=32$).

Phần tiền xử lý có thể làm đơn giản với $O(v\sqrt v)$ hoặc $O(v^2)$. Cách tiền xử lý theo $\log$ như trong mã dưới đây có độ phức tạp là tổng điều hòa, nên là $O(v\log v)$.

??? note "Mã tham khảo"
    ```cpp
    #include <bitset>
    #include <cctype>
    #include <cmath>
    #include <cstdio>
    #include <iostream>
    
    using namespace std;
    
    int read() {
      int out = 0;
      char c;
      while (!isdigit(c = getchar()));
      for (; isdigit(c); c = getchar()) out = out * 10 + c - '0';
      return out;
    }
    
    constexpr int N = 100005;
    constexpr int M = 1000005;
    constexpr int V = 7005;
    
    bitset<V> pre[V], pre2[V], a[N], mu;
    int n, m, tot;
    char ans[M];
    
    int main() {
      int i, j, x, y, z;
    
      n = read();
      m = read();
    
      mu.set();
      for (i = 2; i * i < V; ++i) {
        for (j = 1; i * i * j < V; ++j) {
          mu[i * i * j] = 0;
        }
      }
      for (i = 1; i < V; ++i) {
        for (j = 1; i * j < V; ++j) {
          pre[i * j][i] = 1;
          pre2[i][i * j] = mu[j];
        }
      }
    
      while (m--) {
        switch (read()) {
          case 1:
            x = read();
            y = read();
            a[x] = pre[y];
            break;
          case 2:
            x = read();
            y = read();
            z = read();
            a[x] = a[y] ^ a[z];
            break;
          case 3:
            x = read();
            y = read();
            z = read();
            a[x] = a[y] & a[z];
            break;
          case 4:
            x = read();
            y = read();
            ans[tot++] = ((a[x] & pre2[y]).count() & 1) + '0';
            break;
        }
      }
    
      printf("%s", ans);
    
      return 0;
    }
    ```

<span id="&#19982;&#22467;&#27663;&#31579;&#32467;&#21512;"></span>
### Kết hợp với sàng Eratosthenes

Do hiệu năng đọc ghi liên tiếp của `bitset` rất nhanh, nó rất phù hợp để kết hợp với [sàng Eratosthenes](../../math/number-theory/sieve.md#%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95) khi tạo bảng số nguyên tố.

Cách dùng cũng rất đơn giản: chỉ cần thay mảng Boolean trong sàng Eratosthenes bằng `bitset`.

??? note "Kiểm thử tốc độ"
    Sử dụng [Quick C++ Benchmarks](https://quick-bench.com) để kiểm thử, trình biên dịch là `GCC 13.2`, tham số biên dịch là `-std=c++20 -O2`.
    
    | Thuật toán                                                       | Tên hàm                    |
    | --------------------------------------------------------------- | -------------------------- |
    | Sàng Eratosthenes + mảng Boolean kiểu C, không lưu số nguyên tố | `Eratosthenes_CArray`      |
    | Sàng Eratosthenes + `vector<bool>`, không lưu số nguyên tố      | `Eratosthenes_vector`      |
    | Sàng Eratosthenes + `bitset`, không lưu số nguyên tố            | `Eratosthenes_bitset`      |
    | Sàng Eratosthenes + mảng Boolean kiểu C, lưu số nguyên tố       | `Eratosthenes_CArray_sp`   |
    | Sàng Eratosthenes + `vector<bool>`, lưu số nguyên tố            | `Eratosthenes_vector_sp`   |
    | Sàng Eratosthenes + `bitset`, lưu số nguyên tố                  | `Eratosthenes_bitset_sp`   |
    | Sàng Euler + mảng Boolean kiểu C                                | `Euler_CArray`             |
    | Sàng Euler + `vector<bool>`                                     | `Euler_vector`             |
    | Sàng Euler + `bitset`                                           | `Euler_bitset`             |
    
    -   Khi sàng Eratosthenes **có lưu** các số nguyên tố tìm được:
    
        -   [Kết quả kiểm thử](https://quick-bench.com/q/iQL9FhsZ6PVV81HKABsidRw8hB8) với $N=5 \times 10^7 + 1$:
    
            ![](./images/bitset-5e7sp.png)
        -   [Kết quả kiểm thử](https://quick-bench.com/q/pwEamEFUW-6nXeXEALRsYPd8FWI) với $N=10^8 + 1$:
    
            ![](./images/bitset-1e8sp.png)
    -   Khi sàng Eratosthenes **không lưu** các số nguyên tố tìm được:
    
        -   [Kết quả kiểm thử](https://quick-bench.com/q/rg2mCUxT02a44w9fWvHtZoNTJyU) với $N=5 \times 10^7 + 1$:
    
            ![](./images/bitset-5e7.png)
        -   [Kết quả kiểm thử](https://quick-bench.com/q/lusNWxWsR0VXoRBof7uBtqfvJuY) với $N=10^8 + 1$:
    
            ![](./images/bitset-1e8.png)
    
    Từ kết quả kiểm thử có thể thấy:
    
    1.  Sàng Eratosthenes có độ phức tạp thời gian $O(n \log \log n)$, sau khi được tối ưu bằng `bitset` hoặc `vector<bool>`, hiệu năng thực tế thậm chí vượt cả sàng Euler có độ phức tạp $O(n)$;
    2.  Hiệu quả tối ưu của `bitset` hoặc `vector<bool>` với sàng Euler nhìn chung không rõ rệt trong đa số trường hợp;
    3.  Hiệu quả tối ưu của `bitset` mạnh hơn một chút so với `vector<bool>`.

??? note "Mã tham khảo"
    Cần cài đặt [google/benchmark](https://github.com/google/benchmark).
    
    ```cpp
    #include <benchmark/benchmark.h>
    #include <bits/stdc++.h>
    using namespace std;
    using u32 = uint32_t;
    using u64 = uint64_t;
    
    #define ERATOSTHENES_STORAGE_PRIME
    #define ENABLE_EULER
    constexpr u32 N = 5e7 + 1;
    
    #ifndef ERATOSTHENES_STORAGE_PRIME
    
    void Eratosthenes_CArray(benchmark::State &state) {
      static bool is_prime[N];
      for (auto _ : state) {
        fill(is_prime, is_prime + N, true);
        is_prime[0] = is_prime[1] = false;
        for (u32 i = 2; (u64)i * i < N; ++i)
          if (is_prime[i])
            for (u32 j = i * i; j < N; j += i) is_prime[j] = false;
        benchmark::DoNotOptimize(0);
      }
    }
    
    BENCHMARK(Eratosthenes_CArray);
    
    void Eratosthenes_vector(benchmark::State &state) {
      static vector<bool> is_prime(N);
      for (auto _ : state) {
        fill(is_prime.begin(), is_prime.end(), true);
        is_prime[0] = is_prime[1] = false;
        for (u32 i = 2; (u64)i * i < N; ++i)
          if (is_prime[i])
            for (u32 j = i * i; j < N; j += i) is_prime[j] = false;
        benchmark::DoNotOptimize(0);
      }
    }
    
    BENCHMARK(Eratosthenes_vector);
    
    void Eratosthenes_bitset(benchmark::State &state) {
      static bitset<N> is_prime;
      for (auto _ : state) {
        is_prime.set();
        is_prime.reset(0);
        is_prime.reset(1);
        for (u32 i = 2; (u64)i * i < N; ++i)
          if (is_prime[i])
            for (u32 j = i * i; j < N; j += i) is_prime.reset(j);
        benchmark::DoNotOptimize(0);
      }
    }
    
    BENCHMARK(Eratosthenes_bitset);
    
    #else
    
    void Eratosthenes_CArray_sp(benchmark::State &state) {
      static bool is_prime[N];
      for (auto _ : state) {
        vector<u32> prime;
        fill(is_prime, is_prime + N, true);
        is_prime[0] = is_prime[1] = false;
        for (u32 i = 2; (u64)i * i < N; ++i)
          if (is_prime[i])
            for (u32 j = i * i; j < N; j += i) is_prime[j] = false;
        for (u32 i = 2; i < N; ++i)
          if (is_prime[i]) prime.push_back(i);
        benchmark::DoNotOptimize(prime);
      }
    }
    
    BENCHMARK(Eratosthenes_CArray_sp);
    
    void Eratosthenes_vector_sp(benchmark::State &state) {
      static vector<bool> is_prime(N);
      for (auto _ : state) {
        vector<u32> prime;
        fill(is_prime.begin(), is_prime.end(), true);
        is_prime[0] = is_prime[1] = false;
        for (u32 i = 2; (u64)i * i < N; ++i)
          if (is_prime[i])
            for (u32 j = i * i; j < N; j += i) is_prime[j] = false;
        for (u32 i = 2; i < N; ++i)
          if (is_prime[i]) prime.push_back(i);
        benchmark::DoNotOptimize(prime);
      }
    }
    
    BENCHMARK(Eratosthenes_vector_sp);
    
    void Eratosthenes_bitset_sp(benchmark::State &state) {
      static bitset<N> is_prime;
      for (auto _ : state) {
        vector<u32> prime;
        is_prime.set();
        is_prime.reset(0);
        is_prime.reset(1);
        for (u32 i = 2; (u64)i * i < N; ++i)
          if (is_prime[i])
            for (u32 j = i * i; j < N; j += i) is_prime.reset(j);
        for (u32 i = 2; i < N; ++i)
          if (is_prime[i]) prime.push_back(i);
        benchmark::DoNotOptimize(prime);
      }
    }
    
    BENCHMARK(Eratosthenes_bitset_sp);
    
    #endif
    
    #ifdef ENABLE_EULER
    
    void Euler_CArray(benchmark::State &state) {
      static bool not_prime[N];
      for (auto _ : state) {
        vector<u32> prime;
        fill(not_prime, not_prime + N, false);
        not_prime[0] = not_prime[1] = true;
        for (u32 i = 2; i < N; ++i) {
          if (!not_prime[i]) prime.push_back(i);
          for (u32 pri_j : prime) {
            if (i * pri_j >= N) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) break;
          }
        }
        benchmark::DoNotOptimize(prime);
      }
    }
    
    BENCHMARK(Euler_CArray);
    
    void Euler_vector(benchmark::State &state) {
      static vector<bool> not_prime(N);
      for (auto _ : state) {
        vector<u32> prime;
        fill(not_prime.begin(), not_prime.end(), false);
        not_prime[0] = not_prime[1] = true;
        for (u32 i = 2; i < N; ++i) {
          if (!not_prime[i]) prime.push_back(i);
          for (u32 pri_j : prime) {
            if (i * pri_j >= N) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) break;
          }
        }
        benchmark::DoNotOptimize(prime);
      }
    }
    
    BENCHMARK(Euler_vector);
    
    void Euler_bitset(benchmark::State &state) {
      static bitset<N> not_prime;
      for (auto _ : state) {
        vector<u32> prime;
        not_prime.reset();
        not_prime.set(0);
        not_prime.set(1);
        for (u32 i = 2; i < N; ++i) {
          if (!not_prime[i]) prime.push_back(i);
          for (u32 pri_j : prime) {
            if (i * pri_j >= N) break;
            not_prime.set(i * pri_j);
            if (i % pri_j == 0) break;
          }
        }
        benchmark::DoNotOptimize(prime);
      }
    }
    
    BENCHMARK(Euler_bitset);
    
    #endif
    
    static void Noop(benchmark::State &state) {
      for (auto _ : state) benchmark::DoNotOptimize(0);
    }
    
    BENCHMARK(Noop);
    BENCHMARK_MAIN();
    ```

<span id="&#19982;&#26641;&#20998;&#22359;&#32467;&#21512;"></span>
### Kết hợp với phân khối trên cây

`bitset` kết hợp với phân khối trên cây có thể giải một lớp bài toán hỏi hợp thông tin của nhiều đường đi trên cây. Xem thêm [Cấu trúc dữ liệu / phân khối trên cây](../../ds/tree-decompose.md).

<span id="&#19982;&#33707;&#38431;&#32467;&#21512;"></span>
### Kết hợp với thuật toán Mo

Xem thêm [Tạp mục / thuật toán Mo kết hợp bitset](../../misc/mo-algo-with-bitset.md).

<span id="&#35745;&#31639;&#39640;&#32500;&#20559;&#24207;"></span>
### Tính thứ tự riêng phần nhiều chiều

Xem thêm [slide của FHR](https://github.com/OI-wiki/libs/blob/master/lang/csl/FHR-%E5%88%86%E5%9D%97bitset%E6%B1%82%E9%AB%98%E7%BB%B4%E5%81%8F%E5%BA%8F.pdf).

<span id="&#21442;&#32771;&#36164;&#26009;&#19982;&#27880;&#37322;"></span>
## Tài liệu tham khảo và ghi chú

[^bitset1]: [libstdc++: SGI STL extensions](https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.4/a00994.html#g32541eb0d6581b915af48b5a51006dff)

[^bitset2]: [libstdc++: std::bitset<\_Nb> Class Template Reference](https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.4/a00219.html)
