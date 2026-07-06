<a id="kiểu-dữ-liệu"></a>

## Kiểu dữ liệu

Hệ thống kiểu của C++ gồm các phần sau:

1.  Kiểu cơ bản (trong ngoặc là từ khóa hoặc kiểu đại diện)
    1.  Kiểu không có giá trị, tức kiểu `void` (`void`)
    2.  (Từ C++11) kiểu con trỏ null (`std::nullptr_t`)
    3.  Kiểu số học
        1.  Kiểu số nguyên (`int`)
        2.  Kiểu luận lý, tức kiểu `bool` (`bool`)
        3.  Kiểu ký tự (`char`)
        4.  Kiểu số thực dấu phẩy động (`float`, `double`)
2.  Kiểu hợp thành[^note11]

<a id="kiểu-luận-lý"></a>

### Kiểu luận lý

Một biến kiểu `bool` chỉ có thể nhận một trong hai giá trị: `true` và `false`.

Thông thường, một biến kiểu `bool` chiếm $1$ byte bộ nhớ; số bit trong một byte
tùy thuộc nền tảng, nhưng thường là $8$ bit.

???+ tip "Mẹo"
    Có thể lấy số bit trong một byte thông qua hằng macro `CHAR_BIT` trong tệp
    tiêu đề `<climits>` (C++)/`<limits.h>` (C).

???+ note "Kiểu luận lý trong ngôn ngữ C"
    Xem thêm [Khác biệt giữa C++ và các ngôn ngữ thường dùng khác - bool](./cpp-other-langs.md#bool).

    Ban đầu ngôn ngữ C không có kiểu luận lý. Đến C99, từ khóa `_Bool` mới được
    đưa vào làm kiểu luận lý, và kiểu này được xem như một kiểu số nguyên không
    dấu.

    ???+ note "Ghi chú"
        Từ C23, kiểu `bool` của C không còn được định nghĩa bằng giá trị nguyên
        bằng không và khác không nữa, mà được định nghĩa là kiểu có thể lưu hai
        hằng `true` và `false`.

    Để tiện sử dụng, `stdbool.h` cung cấp ba macro `bool`, `true`, `false`,
    thường được định nghĩa như sau:

    ```c
    #define bool _Bool
    #define true 1
    #define false 0
    ```

    Các macro này bị loại bỏ trong C23. Từ C23, `true`, `false` và `bool` được
    đưa vào làm từ khóa, đồng thời vẫn giữ `_Bool` như một cách viết thay
    thế[^note10].

    Ngoài ra, từ C23 cũng có thể lấy độ rộng bit của kiểu luận lý thông qua hằng
    macro `BOOL_WIDTH` trong `<limits.h>`.

<a id="kiểu-số-nguyên"></a>

### Kiểu số nguyên

Kiểu số nguyên dùng để lưu các giá trị nguyên. Kiểu số nguyên cơ bản nhất là
`int`.

???+ warning "Lưu ý"
    Do nguyên nhân lịch sử, trong C++, kiểu luận lý và kiểu ký tự được xem là các
    kiểu số nguyên đặc biệt.

    Trong hầu hết mọi trường hợp, **không nên** dùng các kiểu ký tự như
    `signed char` và `unsigned char` thay cho kiểu số nguyên thông thường.

Các kiểu số nguyên thường được chia thành 5 mức theo độ rộng bit: `char`,
`short`, `int`, `long`, `long long`.

Chuẩn C++ bảo đảm
`1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)`.

Do nguyên nhân lịch sử, độ rộng bit của kiểu số nguyên có nhiều mô hình phổ biến
khác nhau. Để giải quyết vấn đề này, C99/C++11 đã đưa vào [kiểu số nguyên có độ
rộng cố định](#kiểu-số-nguyên-có-độ-rộng-cố-định).

???+ note "Kích thước của kiểu `int`"
    Trong chuẩn C++, số bit của `int` được quy định là **ít nhất** $16$ bit.

    Trên đa số nền tảng hiện nay, `int` có $32$ bit.

Với từ khóa `int`, có thể dùng các từ khóa bổ nghĩa sau:

Tính có dấu:

-   `signed`: biểu thị số nguyên có dấu (mặc định);
-   `unsigned`: biểu thị số nguyên không dấu.

Kích thước:

-   `short`: biểu thị số nguyên **ít nhất** $16$ bit;
-   `long`: biểu thị số nguyên **ít nhất** $32$ bit;
-   (Từ C++11) `long long`: biểu thị số nguyên **ít nhất** $64$ bit.

Bảng sau cho biết độ rộng bit và phạm vi biểu diễn của các kiểu số nguyên trong
**trường hợp thông thường** (trên một số ít nền tảng, phạm vi biểu diễn của vài
kiểu có thể khác bảng này):

| Tên kiểu                                                               | Kiểu tương đương          | Độ rộng bit (chuẩn C++) | Độ rộng bit (thường gặp) | Độ rộng bit (hiếm gặp hơn)               |
| --------------------------------------------------------------------- | ------------------------ | ----------------------- | ------------------------ | ---------------------------------------- |
| `signed char`                                                         | `signed char`            | $\geq 8$                | $8$                      | -                                        |
| `unsigned char`                                                       | `unsigned char`          | $\geq 8$                | $8$                      | -                                        |
| `short`, `short int`, `signed short`, `signed short int`              | `short int`              | $\geq 16$               | $16$                     | -                                        |
| `unsigned short`, `unsigned short int`                                | `unsigned short int`     | $\geq 16$               | $16$                     | -                                        |
| `int`, `signed`, `signed int`                                         | `int`                    | $\geq 16$               | $32$                     | $16$ (thường gặp trong Win16 API)        |
| `unsigned`, `unsigned int`                                            | `unsigned int`           | $\geq 16$               | $32$                     | $16$ (thường gặp trong Win16 API)        |
| `long`, `long int`, `signed long`, `signed long int`                  | `long int`               | $\geq 32$               | $32$                     | $64$ (thường gặp trên Linux, macOS 64-bit) |
| `unsigned long`, `unsigned long int`                                  | `unsigned long int`      | $\geq 32$               | $32$                     | $64$ (thường gặp trên Linux, macOS 64-bit) |
| `long long`, `long long int`, `signed long long`, `signed long long int` | `long long int`        | $\geq 64$               | $64$                     | -                                        |
| `unsigned long long`, `unsigned long long int`                        | `unsigned long long int` | $\geq 64$               | $64$                     | -                                        |

Khi độ rộng bit là $x$, phạm vi biểu diễn của kiểu có dấu là
$-2^{x-1}\sim 2^{x-1}-1$[^note16], còn phạm vi biểu diễn của kiểu không dấu là
$0 \sim 2^x-1$. Cụ thể như bảng sau:

| Độ rộng bit | Phạm vi biểu diễn                                      |
| ----------- | ------------------------------------------------------ |
| $8$         | Có dấu: $-2^{7}\sim 2^{7}-1$, không dấu: $0 \sim 2^{8}-1$ |
| $16$        | Có dấu: $-2^{15}\sim 2^{15}-1$, không dấu: $0 \sim 2^{16}-1$ |
| $32$        | Có dấu: $-2^{31}\sim 2^{31}-1$, không dấu: $0 \sim 2^{32}-1$ |
| $64$        | Có dấu: $-2^{63}\sim 2^{63}-1$, không dấu: $0 \sim 2^{64}-1$ |

???+ note "Các cách viết kiểu tương đương"
    Khi không gây nhập nhằng, có thể lược bỏ một số từ khóa bổ nghĩa, hoặc điều
    chỉnh thứ tự của các từ khóa bổ nghĩa. Điều này có nghĩa là cùng một kiểu có
    thể có nhiều cách viết tương đương.

    Ví dụ, `int`, `signed`, `int signed`, `signed int` biểu thị cùng một kiểu,
    còn `unsigned long` và `unsigned long int` biểu thị cùng một kiểu.

Ngoài ra, một số trình biên dịch triển khai các kiểu số nguyên mở rộng. Chẳng hạn
GCC hỗ trợ số nguyên 128 bit: bản có dấu `__int128_t` và bản không dấu
`__uint128_t`. Nếu muốn dùng các kiểu này trong kỳ thi, **cần đọc kỹ quy định
của kỳ thi** để xác định việc dùng kiểu số nguyên mở rộng có được cho phép hoặc
được hỗ trợ hay không.

???+ warning "Lưu ý"
    STL không nhất thiết hỗ trợ đầy đủ các kiểu số nguyên mở rộng, vì vậy cần đặc
    biệt cẩn thận khi dùng chúng.

    ???+ note "Mã ví dụ"
        ```cpp
        #include <cmath>
        #include <iostream>

        int f1(int n) {
          return abs(n);  // Đúng
        }

        int f2(int n) {
          return std::abs(n);  // Đúng
        }

        __int128_t f3(__int128_t n) {
          return abs(n);  // Sai
        }

        // Sai
        // __int128_t f4(__int128_t n) {
        //   return std::abs(n);
        // }

        int main() {
          std::cout << "f1: " << f1(-42) << std::endl;
          std::cout << "f2: " << f2(-42) << std::endl;
          // std::cout << "f3: " << f3(-42) << std::endl; // Sai
          // std::cout << "f4: " << f4(-42) << std::endl; // Sai
          return 0;
        }
        ```

    Mã ví dụ trên có các vấn đề sau:

    1.  Trong `__int128_t f3(__int128_t)`, hàm trị tuyệt đối được dùng là hàm
        kiểu C, có chữ ký `int abs(int)`, nên trước hết `n` sẽ bị chuyển kiểu
        thành `int`, rồi mới gọi hàm `abs`.
    2.  Trong `__int128_t f4(__int128_t)`, hàm trị tuyệt đối được dùng là hàm
        kiểu C++. Hàm này không có overload với chữ ký
        `__int128_t std::abs(__int128_t)`, nên không thể biên dịch.
    3.  Xuất luồng của C++ không hỗ trợ `__int128_t` và `__uint128_t`.

    Sau đây là một cách giải quyết:

    ??? note "Mã sau khi sửa"
        ```cpp
        #include <cmath>
        #include <iostream>

        __int128_t abs(__int128_t n) { return n < 0 ? -n : n; }

        std::ostream &operator<<(std::ostream &os, __uint128_t n) {
          if (n > 9) os << n / 10;
          os << (int)(n % 10);
          return os;
        }

        std::ostream &operator<<(std::ostream &os, __int128_t n) {
          if (n < 0) {
            os << '-';
            n = -n;
          }
          return os << (__uint128_t)n;
        }

        int f1(int n) { return abs(n); }

        int f2(int n) { return std::abs(n); }

        __int128_t f3(__int128_t n) { return abs(n); }

        int main() {
          std::cout << "f1: " << f1(-42) << std::endl;
          std::cout << "f2: " << f2(-42) << std::endl;
          std::cout << "f3: " << f3(-42) << std::endl;
        }
        ```

<a id="kiểu-ký-tự"></a>

### Kiểu ký tự

Kiểu ký tự được chia thành "kiểu ký tự hẹp" và "kiểu ký tự rộng". Vì trong các
kỳ thi lập trình thuật toán ít dùng đến kiểu ký tự rộng, phần này chỉ giới thiệu
kiểu ký tự hẹp.

Kiểu ký tự hẹp thường có $8$ bit. Về cách lưu trữ tầng dưới, ký tự vẫn là số
nguyên; trong các bài toán OI thông thường, quan hệ giữa ký tự và số nguyên
thường được hiểu theo [mã ASCII](http://www.asciitable.com/). Có ba loại sau:

-   `signed char`: kiểu biểu diễn ký tự có dấu, phạm vi biểu diễn từ
    $-128 \sim 127$.
-   `unsigned char`: kiểu biểu diễn ký tự không dấu, phạm vi biểu diễn từ
    $0 \sim 255$.
-   `char` có cùng cách biểu diễn và căn chỉnh với một trong hai kiểu
    `signed char` hoặc `unsigned char`, nhưng luôn là một kiểu độc lập.

    Tính có dấu của `char` phụ thuộc vào trình biên dịch và nền tảng đích: cấu
    hình mặc định trên ARM và PowerPC thường là không dấu, còn cấu hình mặc định
    trên x86 và x64 thường là có dấu.

    Với GCC, có thể thêm `-fsigned-char` hoặc `-funsigned-char` vào tham số biên
    dịch để chỉ định xem `char` là `signed char` hay `unsigned char`; với các
    trình biên dịch khác, cần tham khảo tài liệu tương ứng. Cần lưu ý rằng việc
    chỉ định tính có dấu khác với giá trị mặc định của kiến trúc có thể phá vỡ
    ABI, khiến chương trình không hoạt động bình thường.

???+ warning "Lưu ý"
    Khác với các kiểu số nguyên khác, `char`, `signed char`, `unsigned char` là
    **ba kiểu khác nhau**.

    Thông thường, không nên dùng `signed char`, `unsigned char` để lưu ký tự.
    Trong hầu hết trường hợp, hai kiểu này được xem như kiểu số nguyên.

<a id="kiểu-số-thực-dấu-phẩy-động"></a>

### Kiểu số thực dấu phẩy động

Dùng để lưu "số thực" (lưu ý rằng đây không phải số thực theo nghĩa chặt chẽ, mà
là giá trị xấp xỉ của số thực theo một số quy tắc nhất định), gồm ba kiểu sau:

-   `float`: kiểu dấu phẩy động độ chính xác đơn. Nếu được hỗ trợ, kiểu này khớp
    với định dạng IEEE-754 binary32.
-   `double`: kiểu dấu phẩy động độ chính xác kép. Nếu được hỗ trợ, kiểu này khớp
    với định dạng IEEE-754 binary64.
-   `long double`: kiểu dấu phẩy động độ chính xác mở rộng. Nếu được hỗ trợ, kiểu
    này khớp với định dạng IEEE-754 binary128; nếu không, nếu được hỗ trợ thì
    khớp với định dạng mở rộng IEEE-754 binary64; nếu không nữa thì khớp với một
    định dạng dấu phẩy động mở rộng không phải IEEE-754 có độ chính xác tốt hơn
    binary64 và miền giá trị ít nhất tốt bằng binary64; nếu không nữa thì khớp
    với định dạng IEEE-754 binary64.

| Định dạng dấu phẩy động            | Độ rộng bit | Số dương lớn nhất              | Số chữ số chính xác |
| ---------------------------------- | ----------- | ------------------------------ | ------------------- |
| Định dạng IEEE-754 binary32        | $32$        | $3.4\times 10^{38}$            | $6\sim 9$           |
| Định dạng IEEE-754 binary64        | $64$        | $1.8\times 10^{308}$           | $15\sim 17$         |
| Định dạng mở rộng IEEE-754 binary64 | $\geq 80$  | $\geq 1.2\times 10^{4932}$     | $\geq 18\sim 21$    |
| Định dạng IEEE-754 binary128       | $128$       | $1.2\times 10^{4932}$          | $33\sim 36$         |

> Số âm nhỏ nhất của định dạng dấu phẩy động IEEE-754 là số đối của số dương lớn
> nhất.

Vì kiểu `float` có phạm vi biểu diễn nhỏ và độ chính xác không cao, trong thực tế
thường dùng kiểu `double` để biểu diễn số thực dấu phẩy động.

Ngoài ra, kiểu dấu phẩy động có thể hỗ trợ một số giá trị đặc biệt:

-   Vô cùng (dương hoặc âm): `INFINITY`.
-   Âm không: `-0.0`, ví dụ `1.0 / 0.0 == INFINITY`, `1.0 / -0.0 == -INFINITY`.
-   Không phải số (NaN): `std::nan`, `NAN`, thường có thể sinh ra bởi các phép
    tính như `0.0 / 0.0`. Nó không bằng bất kỳ giá trị nào khi so sánh (kể cả
    chính nó); từ C++11 có thể dùng `std::isnan` để kiểm tra một số dấu phẩy
    động có phải NaN hay không.

<a id="kiểu-không-có-giá-trị"></a>

### Kiểu không có giá trị

Kiểu `void` là kiểu không có giá trị. Khác với các kiểu ở trên, không thể khai báo một biến có kiểu `void`. Tuy nhiên, giá trị trả về của hàm được phép có kiểu `void`, biểu thị rằng hàm đó không trả về giá trị.

<a id="kiểu-con-trỏ-null"></a>

### Kiểu con trỏ null

Vui lòng xem [phần tương ứng](./pointer.md#con-trỏ-null) của bài về con trỏ.

<a id="kiểu-số-nguyên-có-độ-rộng-cố-định"></a>

## Kiểu số nguyên có độ rộng cố định

Từ C++11, C++ cung cấp hỗ trợ cho số nguyên có độ rộng cố định, cụ thể như sau:

-   `<cstdint>`: cung cấp một số kiểu số nguyên có độ rộng cố định và các hằng macro như giá trị lớn nhất, giá trị nhỏ nhất của từng kiểu số nguyên có độ rộng cố định.
-   `<cinttypes>`: cung cấp các hằng macro định dạng dùng cho họ hàm `std::fprintf` và họ hàm `std::fscanf` đối với các kiểu số nguyên có độ rộng cố định.

Số nguyên có độ rộng cố định có các loại sau:

-   `intN_t`: kiểu số nguyên có dấu có độ rộng **đúng bằng** $N$ bit, ví dụ `int32_t`.
-   `int_fastN_t`: kiểu số nguyên có dấu **nhanh nhất** có độ rộng **ít nhất** $N$ bit, ví dụ `int_fast32_t`.
-   `int_leastN_t`: kiểu số nguyên có dấu **nhỏ nhất** có độ rộng **ít nhất** $N$ bit, ví dụ `int_least32_t`.

Phiên bản không dấu thêm tiền tố `u` trước phiên bản có dấu, ví dụ `uint32_t`, `uint_least8_t`.

Chuẩn quy định bắt buộc phải triển khai 16 kiểu sau:

`int_fast8_t`, `int_fast16_t`, `int_fast32_t`, `int_fast64_t`,

`int_least8_t`, `int_least16_t`, `int_least32_t`, `int_least64_t`,

`uint_fast8_t`, `uint_fast16_t`, `uint_fast32_t`, `uint_fast64_t`,

`uint_least8_t`, `uint_least16_t`, `uint_least32_t`, `uint_least64_t`.

Trên cơ sở đó, hầu hết trình biên dịch còn triển khai thêm 8 kiểu sau:

`int8_t`, `int16_t`, `int32_t`, `int64_t`,

`uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`.

Khi đã triển khai kiểu tương ứng, chuẩn C++ quy định bắt buộc phải triển khai các hằng macro biểu diễn giá trị lớn nhất, giá trị nhỏ nhất và độ rộng bit của kiểu tương ứng. Tên của chúng có dạng: bỏ `_t` ở cuối tên kiểu, đổi sang chữ hoa và thêm hậu tố:

-   `_MAX` biểu thị giá trị lớn nhất, ví dụ `INT32_MAX` là giá trị lớn nhất của `int32_t`.
-   `_MIN` biểu thị giá trị nhỏ nhất, ví dụ `INT32_MIN` là giá trị nhỏ nhất của `int32_t`.

???+ warning "Lưu ý"
    Về bản chất, kiểu số nguyên có độ rộng cố định là bí danh kiểu của các kiểu số nguyên thông thường, nên việc trộn lẫn kiểu số nguyên có độ rộng cố định và kiểu số nguyên thông thường có thể ảnh hưởng đến khả năng biên dịch đa nền tảng. Ví dụ:

    ???+ note "Mã ví dụ"
        ```cpp
        #include <algorithm>
        #include <cstdint>
        #include <iostream>

        int main() {
          long long a;
          int64_t b;
          std::cin >> a >> b;
          std::cout << std::max(a, b) << std::endl;
          return 0;
        }
        ```

    `int64_t` trên Windows 64-bit thường là `long long int`, còn trên Linux 64-bit thường là `long int`. Vì vậy, đoạn mã này không thể biên dịch với GCC trên Linux 64-bit, nhưng có thể biên dịch với MSVC trên Windows 64-bit, vì `std::max` yêu cầu hai tham số đầu vào phải có cùng kiểu.

Ngoài ra, từ C++17, `<limits>` cung cấp mẫu lớp `std::numeric_limits`, dùng để truy vấn các tính chất của nhiều kiểu số học khác nhau, chẳng hạn giá trị lớn nhất, giá trị nhỏ nhất, có phải kiểu số nguyên hay không, có dấu hay không.

```cpp
#include <cstdint>
#include <limits>

std::numeric_limits<int32_t>::max();  // giá trị lớn nhất của int32_t, 2'147'483'647
std::numeric_limits<int32_t>::min();  // giá trị nhỏ nhất của int32_t, -2'147'483'648

std::numeric_limits<double>::min();  // giá trị dương chuẩn hóa nhỏ nhất của double, khoảng 2.22507e-308
std::numeric_limits<double>::epsilon();  // hiệu giữa 1.0 và giá trị kế tiếp có thể biểu diễn của double,
                                         // khoảng 2.22045e-16
```

<a id="chuyển-đổi-kiểu"></a>

## Chuyển đổi kiểu

Trong một số trường hợp (chẳng hạn một hàm nhận tham số kiểu `int`, nhưng biến truyền vào lại có kiểu `double`), cần chuyển một kiểu nào đó thành một kiểu khác.

Cơ chế chuyển đổi kiểu trong C++ tương đối phức tạp. Phần này chủ yếu giới thiệu hai loại chuyển đổi đối với kiểu dữ liệu cơ bản: nâng hạng số học và chuyển đổi số học.

<a id="nâng-hạng-số-học"></a>

### Nâng hạng số học

Trong quá trình nâng hạng số học, bản thân giá trị không đổi.

???+ note "Ghi chú"
    Danh sách tham số biến thiên kiểu C sẽ thực hiện nâng hạng tham số mặc định khi truyền giá trị. Ví dụ:

    ???+ note "Mã ví dụ"
        ```c
        #include <stdarg.h>
        #include <stdio.h>

        void test(int tot, ...) {
          va_list valist;
          int i;

          // Khởi tạo danh sách tham số biến thiên
          va_start(valist, tot);

          for (i = 0; i < tot; ++i) {
            // Lấy giá trị của biến thứ i
            double xx = va_arg(valist, double);  // Đúng
            // float xx = va_arg(valist, float); // Sai

            // In biểu diễn lưu trữ tầng dưới của biến thứ i
            printf("i = %d, value = 0x%016llx\n", i, *(long long *)(&xx));
          }

          // Dọn bộ nhớ của danh sách tham số biến thiên
          va_end(valist);
        }

        int main() {
          float f;
          double fd, d;
          f = 123.;   // 0x42f60000
          fd = 123.;  // 0x405ec00000000000
          d = 456.;   // 0x407c800000000000
          test(3, f, fd, d);
        }
        ```

    Khi gọi `test`, `f` được nâng hạng thành `double`, nên biểu diễn lưu trữ tầng dưới giống với `fd`; kết quả in ra là

    ```text
    i = 0, value = 0x405ec00000000000
    i = 1, value = 0x405ec00000000000
    i = 2, value = 0x407c800000000000
    ```

    Nếu đổi `double xx = va_arg(valist, double);` thành `float xx = va_arg(valist, float);`, GCC sẽ đưa ra một cảnh báo tương tự như sau:

    ```text
    In file included from test.c:2:
    test.c: In function 'test':
    test.c:14:35: warning: 'float' is promoted to 'double' when passed through '...'
      14 |         float xx = va_arg(valist, float);
         |                                   ^
    test.c:14:35: note: (so you should pass 'double' not 'float' to 'va_arg')
    test.c:14:35: note: if this code is reached, the program will abort
    ```

    Khi đó chương trình sẽ kết thúc trước khi in kết quả.

    Điều này cũng giải thích vì sao `%f` của `printf` có thể khớp cả `float` lẫn `double`.

<a id="nâng-hạng-số-nguyên"></a>

#### Nâng hạng số nguyên

Giá trị thuần phải (prvalue) của kiểu số nguyên nhỏ (như `char`) có thể được chuyển thành giá trị thuần phải của kiểu số nguyên lớn hơn (như `int`).

Nói cụ thể hơn, toán tử số học không nhận kiểu nhỏ hơn `int` làm đối số. Sau phép chuyển từ lvalue sang rvalue, nếu phù hợp thì nâng hạng số nguyên sẽ tự động được áp dụng.

Cụ thể có các quy tắc sau:

-   Khi kiểu nguồn là `signed char`, `signed short / short`, có thể nâng hạng thành `int`.
-   Khi kiểu nguồn là `unsigned char`, `unsigned short`, nếu `int` có thể chứa toàn bộ phạm vi giá trị của kiểu nguồn thì có thể nâng hạng thành `int`, nếu không thì nâng hạng thành `unsigned int`. (Từ `C++20`, `char8_t` cũng áp dụng quy tắc này.)
-   Quy tắc nâng hạng của `char` phụ thuộc vào kiểu tầng dưới của nó là `signed char` hay `unsigned char`.
-   Kiểu `bool` có thể chuyển sang `int`: `false` trở thành `0`, `true` trở thành `1`.
-   Nếu phạm vi giá trị của kiểu đích chứa phạm vi giá trị của kiểu nguồn, và phạm vi giá trị của kiểu nguồn không thể được chứa bởi `int` và `unsigned int`, thì kiểu nguồn có thể được nâng hạng thành kiểu đích.[^note12]

???+ warning "Lưu ý"
    `char`->`short` không phải là nâng hạng số học, vì `char` được ưu tiên nâng hạng thành `int / unsigned int`, sau đó mới là `int / unsigned int`->`short`, không thỏa điều kiện của nâng hạng số học.

Ví dụ (sau đây giả sử `int` là 32 bit, `unsigned short` là 16 bit, `signed char` và `unsigned char` là 8 bit, `bool` là 1 bit):

-   `(signed char)'\0' - (signed char)'\xff'` trước hết sẽ nâng `(signed char)'\0'` thành `(int)0`, nâng `(signed char)'\xff'` thành `(int)-1`, rồi thực hiện phép toán giữa các `int`; kết quả cuối cùng là `(int)1`.
-   `(unsigned char)'\0' - (unsigned char)'\xff'` trước hết sẽ nâng `(unsigned char)'\0'` thành `(int)0`, nâng `(unsigned char)'\xff'` thành `(int)255`, rồi thực hiện phép toán giữa các `int`; kết quả cuối cùng là `(int)-255`.
-   `false - (unsigned short)12` trước hết sẽ nâng `false` thành `(int)0`, nâng `(unsigned short)12` thành `(int)12`, rồi thực hiện phép toán giữa các `int`; kết quả cuối cùng là `(int)-12`.

<a id="nâng-hạng-dấu-phẩy-động"></a>

#### Nâng hạng dấu phẩy động

Số dấu phẩy động có độ rộng bit nhỏ hơn có thể được nâng hạng thành số dấu phẩy động có độ rộng bit lớn hơn (ví dụ khi một biến kiểu `float` và một biến kiểu `double` tham gia phép toán số học, biến kiểu `float` sẽ được nâng hạng thành biến kiểu `double`), và giá trị của nó không đổi.

<a id="chuyển-đổi-số-học"></a>

### Chuyển đổi số học

Trong quá trình chuyển đổi số học, giá trị có thể thay đổi.

???+ warning "Lưu ý"
    Nâng hạng số học có độ ưu tiên cao hơn chuyển đổi số học. Ví dụ, `bool`->`int` là nâng hạng số học chứ không phải chuyển đổi số học.

<a id="chuyển-đổi-số-nguyên"></a>

#### Chuyển đổi số nguyên

<!-- scripts.linter.preprocess.fix_details off -->

-   Nếu kiểu đích là kiểu số nguyên không dấu có độ rộng bit $x$, kết quả chuyển đổi là giá trị ban đầu sau khi lấy $\bmod 2^x$.

    -   Nếu độ rộng bit của kiểu đích lớn hơn độ rộng bit của kiểu nguồn:

        -   Nếu kiểu nguồn là kiểu có dấu, thông thường cần mở rộng bit dấu trước rồi mới chuyển đổi.

            Ví dụ:

            -   Khi chuyển `(short)-1` (`(short)0b1111'1111'1111'1111`) sang kiểu `unsigned int`, trước hết mở rộng bit dấu, thu được `0b1111'1111'1111'1111'1111'1111'1111'1111`, rồi thực hiện chuyển đổi số nguyên; kết quả là `(unsigned int)4'294'967'295` (`(unsigned int)0b1111'1111'1111'1111'1111'1111'1111'1111`).
            -   Khi chuyển `(short)32'767` (`(short)0b0111'1111'1111'1111`) sang kiểu `unsigned int`, trước hết mở rộng bit dấu, thu được `0b0000'0000'0000'0000'0111'1111'1111'1111`, rồi thực hiện chuyển đổi số nguyên; kết quả là `(unsigned int)32'767` (`(unsigned int)0b0000'0000'0000'0000'0111'1111'1111'1111`).

        -   Nếu kiểu nguồn là kiểu không dấu, cần mở rộng bằng bit 0 trước rồi mới chuyển đổi.

            Ví dụ, khi chuyển `(unsigned short)65'535` (`(unsigned short)0b1111'1111'1111'1111`) sang kiểu `unsigned int`, trước hết mở rộng bằng bit 0, thu được `0b0000'0000'0000'0000'1111'1111'1111'1111`, rồi thực hiện chuyển đổi số nguyên; kết quả là `(unsigned int)65'535` (`(unsigned int)0b0000'0000'0000'0000'1111'1111'1111'1111`).

    -   Nếu độ rộng bit của kiểu đích không lớn hơn độ rộng bit của kiểu nguồn, cần cắt bớt trước rồi mới chuyển đổi.

        Ví dụ, khi chuyển `(unsigned int)4'294'967'295` (`(unsigned int)0b1111'1111'1111'1111'1111'1111'1111'1111`) sang kiểu `unsigned short`, trước hết cắt bớt, thu được `0b1111'1111'1111'1111`, rồi thực hiện chuyển đổi số nguyên; kết quả là `(unsigned short)65'535` (`(unsigned short)0b1111'1111'1111'1111`).

-   Nếu kiểu đích là kiểu số nguyên có dấu có độ rộng bit $x$, thì **trong trường hợp thông thường**, kết quả chuyển đổi có thể được xem là kết quả của giá trị ban đầu sau khi lấy $\bmod 2^x$.[^note13]

    Ví dụ, khi chuyển `(unsigned int)4'294'967'295` (`(unsigned int)0b1111'1111'1111'1111'1111'1111'1111'1111`) sang kiểu `short`, kết quả là `(short)-1` (`(short)0b1111'1111'1111'1111`).

-   Nếu kiểu đích là `bool`, đó là [chuyển đổi luận lý](#chuyển-đổi-luận-lý).

-   Nếu kiểu nguồn là `bool`, thì `false` chuyển thành 0 của kiểu tương ứng, còn `true` chuyển thành 1 của kiểu tương ứng.

<!-- scripts.linter.preprocess.fix_details on -->

<a id="chuyển-đổi-dấu-phẩy-động"></a>

#### Chuyển đổi dấu phẩy động

Khi số dấu phẩy động có độ rộng bit lớn hơn được chuyển sang số dấu phẩy động có độ rộng bit nhỏ hơn, số đó sẽ được làm tròn về giá trị gần nhất trong kiểu đích.

<a id="chuyển-đổi-giữa-dấu-phẩy-động-và-số-nguyên"></a>

#### Chuyển đổi giữa dấu phẩy động và số nguyên

-   Khi chuyển số dấu phẩy động sang số nguyên, toàn bộ phần thập phân của số dấu phẩy động sẽ bị bỏ đi.

    Nếu kiểu đích là `bool`, đó là [chuyển đổi luận lý](#chuyển-đổi-luận-lý).

-   Khi chuyển số nguyên sang số dấu phẩy động, giá trị sẽ được làm tròn về giá trị gần nhất trong kiểu đích.

    Nếu giá trị đó không thể chứa trong kiểu đích, hành vi là không xác định.

    Nếu kiểu nguồn là `bool`, thì `false` chuyển thành không, còn `true` chuyển thành một.

<a id="chuyển-đổi-luận-lý"></a>

#### Chuyển đổi luận lý

Khi chuyển các kiểu khác sang kiểu `bool`, giá trị bằng không chuyển thành `false`, giá trị khác không chuyển thành `true`.

<a id="định-nghĩa-biến"></a>

## Định nghĩa biến

Nói đơn giản[^note14], để định nghĩa một biến, cần có bộ mô tả kiểu (chỉ rõ kiểu của biến) và tên biến cần định nghĩa.

Ví dụ, các câu lệnh sau đều là câu lệnh định nghĩa biến.

```cpp
int oi;
double wiki;
char org = 'c';
```

Trong các đoạn chương trình cơ bản trong phần này, biến được định nghĩa trong phạm vi được bao bởi cặp ngoặc nhọn là biến cục bộ, còn biến được định nghĩa bên ngoài các khối đó là biến toàn cục. C++ vẫn có ngoại lệ phức tạp hơn, nhưng chưa cần xét trong phần nhập môn này.

Biến toàn cục không có giá trị khởi tạo khi định nghĩa sẽ được khởi tạo bằng $0$. Biến cục bộ không có tính chất này, nên cần gán giá trị ban đầu cụ thể; nếu không có thể gây ra lỗi khó phát hiện.

<a id="phạm-vi-của-biến"></a>

## Phạm vi của biến

Phạm vi là khối mã mà biến có thể có hiệu lực.

Phạm vi của biến toàn cục bắt đầu từ nơi nó được định nghĩa[^note15] cho đến cuối tệp.

Phạm vi của biến cục bộ bắt đầu từ nơi nó được định nghĩa cho đến cuối khối mã.

Một số câu lệnh được bao bởi một cặp ngoặc nhọn tạo thành một khối mã.

```cpp
int g = 20;  // Định nghĩa biến toàn cục

int main() {
  int g = 10;         // Định nghĩa biến cục bộ
  printf("%d\n", g);  // In g
  return 0;
}
```

Nếu trong khối lồng bên trong của một khối mã có định nghĩa biến cùng tên, thì tên ở khối bên trong sẽ che khuất biến cùng tên ở khối bên ngoài.

Ví dụ trong đoạn mã trên, giá trị $g$ được in ra sẽ là $10$. Vì vậy, để tránh lỗi ngoài dự kiến, nên cố gắng tránh để biến cục bộ trùng tên với biến toàn cục.

<a id="hằng"></a>

## Hằng

Hằng là giá trị cố định, không thay đổi trong quá trình chương trình thực thi.

Giá trị của hằng không thể bị sửa sau khi định nghĩa. Khi định nghĩa, thêm từ khóa `const`.

```cpp
const int a = 2;
a = 3;
```

Nếu sửa giá trị của hằng, lỗi sẽ xuất hiện ở giai đoạn biên dịch: `error: assignment of read-only variable 'a'`.

<a id="tài-liệu-tham-khảo-và-chú-thích"></a>

## Tài liệu tham khảo và chú thích

1.  [Working Draft, Standard for Programming Language C++](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/n4917.pdf)
2.  [Kiểu - cppreference.com](https://en.cppreference.com/w/cpp/language/type)
3.  [Kiểu số học - cppreference.com](https://en.cppreference.com/w/c/language/arithmetic_types) của ngôn ngữ C
4.  [Kiểu cơ bản - cppreference.com](https://en.cppreference.com/w/cpp/language/types)
5.  [Kiểu số nguyên có độ rộng cố định (từ C++11) - cppreference.com](https://en.cppreference.com/w/cpp/types/integer)
6.  William Kahan (1 October 1997).["Lecture Notes on the Status of IEEE Standard 754 for Binary Floating-Point Arithmetic"](https://people.eecs.berkeley.edu/~wkahan/ieee754status/IEEE754.PDF).
7.  [Chuyển đổi ngầm định - cppreference.com](https://en.cppreference.com/w/cpp/language/implicit_conversion)
8.  [Khai báo - cppreference](https://en.cppreference.com/w/cpp/language/declarations)
9.  [Phạm vi - cppreference.com](https://en.cppreference.com/w/cpp/language/scope)

[^note10]: Xem <https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3054.pdf>

[^note11]: Bao gồm kiểu mảng, kiểu tham chiếu, kiểu con trỏ, kiểu lớp, kiểu hàm và các kiểu khác. Vì bài viết này hướng tới người mới bắt đầu, nên các kiểu đó không được giới thiệu cụ thể tại đây. Xem chi tiết tại [Kiểu - cppreference.com](https://en.cppreference.com/w/cpp/language/type)

[^note12]: Không bao gồm kiểu ký tự rộng, trường bit và kiểu liệt kê; xem chi tiết tại [chuyển đổi số nguyên - cppreference](https://en.cppreference.com/w/cpp/language/implicit_conversion#Integral_conversions).

[^note13]: Có hiệu lực từ C++20. Trước C++20, kết quả là do bản triển khai định nghĩa (implementation-defined). Xem chi tiết tại [chuyển đổi số nguyên - cppreference](https://en.cppreference.com/w/cpp/language/implicit_conversion#Integral_conversions).

[^note14]: Khi định nghĩa một biến, ngoài bộ mô tả kiểu, còn có thể chứa các bộ mô tả khác. Xem chi tiết tại [khai báo - cppreference](https://en.cppreference.com/w/cpp/language/declarations).

[^note15]: Nói chính xác hơn là [điểm khai báo](https://en.cppreference.com/w/cpp/language/scope#Point_of_declaration).

[^note16]: Trước C++20, chuẩn quy định số nguyên có dấu ít nhất phải bao phủ phạm vi biểu diễn của [mã bù một](../math/bit.md#số-nguyên-và-chuỗi-bit) (tức $-2^{x-1}+1\sim 2^{x-1}-1$), nhưng hầu hết bản triển khai đều dùng [mã bù hai](../math/bit.md#số-nguyên-và-chuỗi-bit); từ C++20, chuẩn quy định thêm rằng số nguyên có dấu bắt buộc phải dùng mã bù hai. Xem chi tiết tại [Range of values - cppreference](https://en.cppreference.com/w/cpp/language/types.html#Range_of_values).
