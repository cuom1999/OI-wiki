## Tổng quan

Muốn sử dụng các kỹ thuật ngẫu nhiên hóa, trước hết phải có khả năng sinh số
ngẫu nhiên nhanh. Bài viết này giới thiệu những phương pháp sinh số ngẫu nhiên
thường gặp.

### Số ngẫu nhiên và số giả ngẫu nhiên

Nói một số riêng lẻ là "số ngẫu nhiên" không có ý nghĩa, vì vậy bên dưới ta
luôn ngầm xét một **dãy số ngẫu nhiên**. Khi nói "một số ngẫu nhiên", ta cũng
đang nói tới một phần tử của dãy đó.

Quá trình tính toán của máy tính hiện nay mang tính xác định. Vì thế, chỉ dựa
vào thuật toán thì không thể sinh một dãy số thật sự **không thể dự đoán** và
**không thể lặp lại**.

Tuy nhiên, trong phần lớn tình huống ta không cần tính ngẫu nhiên mạnh đến vậy;
chỉ cần dãy sinh ra có những đặc trưng thống kê của một dãy ngẫu nhiên, chẳng
hạn phân bố đều và độc lập lẫn nhau. Dãy như vậy được gọi là dãy **giả ngẫu
nhiên**.

Một số ứng dụng:

-   Khảo sát lấy mẫu thường chỉ cần số giả ngẫu nhiên vì mục tiêu là các đặc
    trưng thống kê.
-   An toàn mạng thường cần nguồn ngẫu nhiên mạnh hơn vì kẻ tấn công có thể
    khai thác tính dự đoán được.
-   Thuật toán ngẫu nhiên trong OI/ICPC hầu như chỉ cần số giả ngẫu nhiên. Chúng
    đưa xác suất vào phân tích độ phức tạp nên chỉ dùng các đặc trưng thống kê.
-   Một số thuật toán, chẳng hạn [thuật toán
    Moser](https://en.wikipedia.org/wiki/Algorithmic_Lov%C3%A1sz_local_lemma),
    sử dụng tính chất liên quan đến entropy nên cần số ngẫu nhiên thật.

## Phương pháp sinh số ngẫu nhiên

### `rand`

`rand` sinh số giả ngẫu nhiên, có nhược điểm là khá chậm và cần
`#include <cstdlib>`. Hàm `rand()` trả về số nguyên không âm trong
`[0,RAND_MAX]`. Trên Linux, `RAND_MAX` thường bằng $2^{31}-1$; có thể dùng phép
lấy dư để giới hạn kết quả.

Hàm `srand(seed)` đặt hạt giống. Nếu cùng chương trình chạy hai lần với cùng
`seed` trên cùng máy và trình biên dịch, kết quả sẽ giống nhau. Một lựa chọn
phổ biến là `srand(time(nullptr))`.

??? warning "Cảnh báo"
    Trên Windows, miền của `rand()` là $[0,2^{15})$. Khi cần số không nhỏ hơn
    $2^{15}$, nên dùng `(rand() << 15 | rand())` để tạo số lớn hơn.

Về chất lượng của `rand()` và `rand() % n`:

-   Chuẩn C/C++ không quy định chất lượng của số do `rand()` sinh ra.
-   Cài đặt của GCC bảo đảm các tính chất cơ bản như phân bố đều, nhưng các bit
    thấp có chu kỳ ngắn. Trên máy của tác giả, dãy `rand() % 2` có chu kỳ xấp
    xỉ $2\cdot10^6$.
-   Ngay cả khi `rand()` phân bố đều, `rand() % n` vẫn không nhất thiết đều vì
    số lần xuất hiện của từng số trong `[0,n)` có thể khác nhau. Xem [Daniel
    Lemire, *Fast Random Integer Generation in an
    Interval*](https://arxiv.org/abs/1805.10941) để biết cách bảo đảm tính đều.

### Các bộ sinh định nghĩa sẵn

Thư viện chuẩn định nghĩa một số thuật toán phổ biến trong `<random>`.

??? warning "Cảnh báo"
    Các bộ sinh này xuất hiện từ C++11.[^ref2]

#### Mersenne Twister

Mersenne Twister do Matsumoto và Nishimura đề xuất năm 1998.[^ref3] Một cài
đặt, MT19937, có chu kỳ dài bằng số nguyên tố Mersenne
$M_{19937}=2^{19937}-1$.

Từ C++11, `std::mersenne_twister_engine` cài đặt phương pháp này; thực tế
thường dùng `std::mt19937` và `std::mt19937_64`. Chúng cho số chất lượng cao và
nhanh hơn `rand()` đáng kể.

`mt19937` là phiên bản 32 bit, có miền kết quả bằng `unsigned int`. Khai báo
`mt19937 myrand(seed)` (có thể bỏ `seed`), rồi gọi `myrand()` để lấy số.
`mt19937_64` tương tự nhưng là phiên bản 64 bit, có miền kết quả bằng
`unsigned long long`.

??? note "Ví dụ mã"
    ```cpp
    --8<-- "docs/misc/code/random/random_1.cpp:core"
    ```

#### Bộ sinh đồng dư tuyến tính

Bộ sinh đồng dư tuyến tính (LCG) do Thomson và Rotenberg đề xuất năm 1958:

$$
s_i \equiv \begin{cases}
\operatorname{seed} & i=0,\\
s_{i-1}A+C & i\ge1
\end{cases}\pmod M,
$$

trong đó $A,C,M$ là các hằng số định trước. Từ C++11, lớp mẫu sau cài đặt nó:

```cpp
template <class UIntType, UIntType A, UIntType C, UIntType M>
class linear_congruential_engine;
```

Năm 1969, Lewis, Goodman và Miller chỉ ra rằng với $A=16807$, $C=0$ và
$M=2147483647$, thuật toán đạt chu kỳ gần cực đại $2^{31}-2$ (vì $16807$ là
[căn nguyên thủy](../math/number-theory/primitive-root.md)) và có đặc trưng
thống kê khá tốt. Park và Miller chọn bộ tham số này làm "tiêu chuẩn tối thiểu"
năm 1988; năm 1993, Park, Miller và Stockmeyer đổi $A$ thành $48271$.

C++11 định nghĩa sẵn hai phiên bản:

-   `minstd_rand0`: `std::uint_fast32_t`, $A=16807$, $C=0$,
    $M=2147483647$;
-   `minstd_rand`: `std::uint_fast32_t`, $A=48271$, $C=0$,
    $M=2147483647$.

Khai báo `std::minstd_rand myrand(seed)` (hạt giống mặc định là $1$), rồi gọi
`myrand()`. Nếu $A,C,M$ không phải hằng số, có thể tự cài đặt; cách này đơn
giản nhưng chu kỳ tối đa là $M$ và thường ngắn hơn.

??? note "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/misc/code/random/random_2.cpp"
    ```

### Bộ điều hợp động cơ ngẫu nhiên

Có thể bọc các bộ sinh định nghĩa sẵn để tạo bộ sinh mới. Xem danh sách tại
[cppreference](https://en.cppreference.com/w/cpp/numeric/random). Mã sau dùng
`std::independent_bits_engine` để bọc `std::minstd_rand`:

```cpp
--8<-- "docs/misc/code/random/random_3.cpp"
```

### Sinh số nguyên phân bố đều không xác định

`random_device` là bộ sinh phân bố đều dựa trên phần cứng và có thể sinh nhanh
trước khi **bể entropy cạn**. Nó có từ C++11 trong `<random>`. Vì hiệu năng giảm
mạnh sau khi bể entropy cạn, nên chỉ dùng nó làm hạt giống cho bộ sinh giả ngẫu
nhiên như `mt19937`.

Nếu hệ thống không hỗ trợ nguồn không xác định, cài đặt được phép dùng động cơ
giả ngẫu nhiên. Chưa có báo cáo máy chấm NOIP không hỗ trợ nguồn phần cứng,
nhưng để thận trọng vẫn chỉ nên dùng nó để sinh hạt giống.

```cpp
--8<-- "docs/misc/code/random/random_4.cpp"
```

Một đầu ra có thể là:

```plain
0 : ********************
1 : *******************
2 : ********************
3 : ********************
4 : ********************
5 : *******************
6 : ********************
7 : ********************
8 : *******************
9 : ********************
```

### Phân bố số ngẫu nhiên

Các lớp phân bố biến đầu ra của động cơ thành số tuân theo phân bố cho trước,
chẳng hạn [đều rời rạc](https://en.wikipedia.org/wiki/Discrete_uniform_distribution),
[Bernoulli](https://en.wikipedia.org/wiki/Bernoulli_distribution), [nhị
thức](https://en.wikipedia.org/wiki/Binomial_distribution), [hình
học](https://en.wikipedia.org/wiki/Geometric_distribution) hoặc [chuẩn
(Gauss)](https://en.wikipedia.org/wiki/Normal_distribution). Danh sách cụ thể
có tại [cppreference](https://en.cppreference.com/w/cpp/numeric/random#Random_number_distributions).

Chương trình sau mô phỏng xúc xắc sáu mặt:

```cpp
--8<-- "docs/misc/code/random/random_5.cpp:header"
--8<-- "docs/misc/code/random/random_5.cpp:real-using"
--8<-- "docs/misc/code/random/random_5.cpp:fake-using"
--8<-- "docs/misc/code/random/random_5.cpp:main"
```

### Các cách cài đặt khác

Đôi khi cần tự cài đặt bộ sinh. Sau đây là những phương pháp thường dùng.

#### Xorshift

Họ Xorshift do George Marsaglia đề xuất năm 2003, chủ yếu dựa trên phép XOR
một số với phiên bản dịch bit của nó. Trong thi đấu thường dùng `xorshift32`
và `xorshift64`:

```cpp
--8<-- "docs/misc/code/random/random_6.cpp:core"
```

Khai báo `xorshift32 rng32(seed)` hoặc `xorshift64 rng64(seed)`, rồi gọi đối
tượng. Với hạt giống khác $0$, chu kỳ lần lượt là $2^{32}-1$ và $2^{64}-1$.
Do cài đặt đơn giản, chúng thường được phát cùng hạt giống để thí sinh sinh dữ
liệu lớn và giảm chi phí vào/ra.

#### SplitMix

Họ SplitMix do Steele, Lea và Flood đề xuất năm 2014, được dùng trong
`java.util.SplittableRandom` của Java 8. Phiên bản phổ biến là `splitmix64`:

```cpp
--8<-- "docs/misc/code/random/random_7.cpp:core"
```

Một ứng dụng chính là băm lần hai một giá trị băm đã có, tránh dữ liệu được
thiết kế để làm bảng băm quá thời gian:

```cpp
--8<-- "docs/misc/code/random/random_8.cpp:core"
```

Nó cũng có thể sinh số: khai báo `splitmix64 rng64(seed)` rồi gọi `rng64()`.
Chu kỳ là $2^{64}$ vì các số cộng vào đều lẻ và mọi phép biến đổi tiếp theo đều
khả nghịch. Nếu không nhớ các hằng số, có thể dùng vài số lẻ đủ lớn kết hợp XOR
và dịch phải để đạt hiệu quả tương tự.

#### Bộ sinh Fibonacci trễ

Với $0<j<k$, sinh dãy $\{R_i\}$ bằng

$$
R_i\equiv R_{i-j}\star R_{i-k}\pmod P.
$$

$P$ thường là $2^{32}$ hoặc $2^{64}$; $\star$ có thể là cộng, trừ, nhân hoặc
XOR. Phương pháp có chu kỳ dài hơn LCG nhưng phụ thuộc nhiều vào điều kiện đầu.

??? note "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/misc/code/random/random_9.cpp:core"
    ```

Trong C++11, `std::subtract_with_carry_engine` là một cài đặt thuộc họ này;
`std::ranlux24_base`, `std::ranlux48_base` là các chuyên biệt hóa, còn
`std::ranlux24`, `std::ranlux48` bọc thêm `std::discard_block_engine`. Hiện nay
chúng thường không còn được khuyến nghị.

## Thuật toán ngẫu nhiên

Phần này giới thiệu một số thuật toán trong thư viện chuẩn C++ phụ thuộc vào
bộ sinh số ngẫu nhiên.

### `random_shuffle`

`std::random_shuffle` được đưa vào C++98 để xáo trộn ngẫu nhiên một dãy, cần
`#include <algorithm>`, và thường dùng [thuật toán
Fisher–Yates](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle).

Truyền đoạn nửa kín bằng `std::random_shuffle(first, last)`, hoặc thêm bộ sinh
tự định nghĩa bằng `std::random_shuffle(first, last, myrand)`. Mặc định hàm
dùng `rand()`.

Về tính ngẫu nhiên:

-   Chuẩn C++ yêu cầu chọn **đều** trong mọi hoán vị, nhưng libstdc++ mặc định
    của GCC[^note1] không tuân thủ nghiêm ngặt.
-   Một nguyên nhân là biểu thức dạng `rand() % n` không sinh số nguyên phân bố
    đều như đã giải thích ở trên.
-   Miền của `rand()` hữu hạn. Nếu đoạn dài hơn `RAND_MAX`, một số hoán vị sẽ
    **không thể** được sinh ra.[^ref1]

??? warning "Cảnh báo"
    `random_shuffle` bị đánh dấu lỗi thời trong C++14 và bị loại khỏi C++17.

### `shuffle`

`std::shuffle` xuất hiện từ C++11, có công dụng tương tự và cũng cần
`#include <algorithm>`. Khác biệt là phải truyền bộ sinh:
`std::shuffle(first, last, myrand)`. Cài đặt của GCC[^note1] tuân thủ yêu cầu
chọn đều trong mọi hoán vị.

Đây là bộ sinh dữ liệu nhỏ ngẫu nhiên cho [ZJOI2012 - Thảm
họa](https://www.luogu.com.cn/problem/P2597), dùng `rand()` và
`random_shuffle()`:

```cpp
--8<-- "docs/misc/code/random/random_10.cpp:header"
--8<-- "docs/misc/code/random/random_10.cpp:real-using"
--8<-- "docs/misc/code/random/random_10.cpp:fake-using"
--8<-- "docs/misc/code/random/random_10.cpp:main"
```

Cùng bộ sinh đó, viết bằng `mt19937` và `shuffle()`:

```cpp
--8<-- "docs/misc/code/random/random_11.cpp:header"
--8<-- "docs/misc/code/random/random_11.cpp:real-using"
--8<-- "docs/misc/code/random/random_11.cpp:fake-using"
--8<-- "docs/misc/code/random/random_11.cpp:main"
```

Ví dụ xáo trộn mười số nguyên dương đầu tiên:

```cpp
--8<-- "docs/misc/code/random/random_12.cpp:header"
--8<-- "docs/misc/code/random/random_12.cpp:real-using"
--8<-- "docs/misc/code/random/random_12.cpp:fake-using"
--8<-- "docs/misc/code/random/random_12.cpp:main"
```

### `sample`

`std::sample` xuất hiện từ C++17, dùng để chọn ngẫu nhiên $n$ phần tử trong một
dãy. Khác với xáo trộn rồi lấy $n$ phần tử đầu, các phần tử được chọn vẫn giữ
nguyên thứ tự tương đối. Cài đặt thường dùng [lấy mẫu hồ
chứa](https://en.wikipedia.org/wiki/Reservoir_sampling).

Cú pháp là `std::sample(first, last, dest, n, myrand)`, trong đó
`[first,last)` là đoạn nguồn, `[dest,dest+n)` là vùng đích và `myrand` là bộ
sinh. Ví dụ chọn ngẫu nhiên bốn trong mười một chữ cái viết hoa:

```cpp
--8<-- "docs/misc/code/random/random_13.cpp:header"
--8<-- "docs/misc/code/random/random_13.cpp:real-using"
--8<-- "docs/misc/code/random/random_13.cpp:fake-using"
--8<-- "docs/misc/code/random/random_13.cpp:main"
```

## Tài liệu tham khảo và chú thích

[^ref1]: [Don't use rand(): a guide to random number generators in C++](https://codeforces.com/blog/entry/61587)

[^ref2]: [Pseudo-random number generation - cppreference.com](https://en.cppreference.com/w/cpp/numeric/random)

[^ref3]: [Mersenne Twister algorithm](https://en.wikipedia.org/wiki/Mersenne_Twister)

[^note1]: Phiên bản GCC 9.2.0.
