author: inclyc

Ngôn ngữ lập trình thường dùng trong OI là C++. Khi dùng C++, khó tránh việc
làm việc với trình biên dịch và tiêu chuẩn ngôn ngữ. C++ có nhiều chi tiết phức
tạp; bài viết này chỉ tập trung vào những kiến thức thực dụng về trình biên dịch,
đủ dùng cho thi đấu.

<a id="giới-thiệu-về-tối-ưu-hóa-của-trình-biên-dịch"></a>
## Giới thiệu về tối ưu hóa của trình biên dịch

<a id="tối-ưu-hóa-là-gì-optimization"></a>
### Tối ưu hóa là gì

Theo [quy tắc as-if](https://en.cppreference.com/w/cpp/language/as_if), trình
biên dịch được phép cải thiện tốc độ chạy hoặc kích thước tệp thực thi, miễn là
giữ nguyên ngữ nghĩa quan sát được của chương trình.

### Những cuộc thi nào bật tối ưu hóa?

Việc có bật tối ưu hóa hay không phụ thuộc vào quy chế và hệ thống chấm của từng
cuộc thi. Trước khi thi, cần đọc kỹ thông báo môi trường biên dịch, đặc biệt là
tiêu chuẩn C++ và các cờ như `-O2`, `-std=gnu++17`, `-Wall`. Khi luyện tập trên
OJ, cũng nên kiểm tra trang trợ giúp hoặc phần cấu hình ngôn ngữ của hệ thống để
biết chương trình sẽ được biên dịch bằng lệnh nào.

Nếu môi trường chính thức bật `-O2`, nên luyện tập và kiểm thử bằng đúng mức tối
ưu hóa đó. Một số lỗi liên quan đến hành vi không xác định chỉ bộc lộ rõ khi bật
tối ưu hóa, nên không thể chỉ dựa vào kết quả chạy ở chế độ không tối ưu.

<a id="các-tối-ưu-hóa-trình-biên-dịch-thường-gặp"></a>
## Các tối ưu hóa trình biên dịch thường gặp

<a id="gấp-hằng-số-constant-folding"></a>
### Gấp hằng số

Gấp hằng số thường đi cùng lan truyền hằng số: nếu một biểu thức có thể xác định
được ngay tại thời gian biên dịch, giá trị đó có thể được thay vào các vị trí dùng
nó cho đến trước lần định nghĩa kế tiếp.

```cpp
int x = 1;
int y = x;  // x = 1, => y = 1
x = 3;
int z = 2 * y;   // z => 2 * y = 2 * 1 = 2
int y2 = x * 2;  // x = 3, => y2 = 6
```

Đoạn mã này có thể được biến đổi ngay trong thời gian biên dịch thành:

```cpp
int x = 1;
int y = 1;
x = 3;
int z = 2;
int y2 = 6;
```

Ví dụ: <https://godbolt.org/z/oEfY35TTd>

<a id="loại-bỏ-mã-chết-deadcode-elimination"></a>
### Loại bỏ mã chết

Đúng như tên gọi, đoạn mã không ảnh hưởng đến kết quả quan sát được sẽ bị xóa bỏ.

```cpp
int test() {
  int a = 233;
  int b = a * 2;
  int c = 234;
  return c;
}
```

sẽ được biến đổi thành

```cpp
int test() { return 234; }
```

Lưu ý rằng đoạn mã này được gấp hằng số trước, nên giá trị trả về có thể xác định
là 234. Hai biến `a` và `b` không còn sống, tức là không ảnh hưởng đến kết quả
quan sát được, nên bị xóa bỏ.

<a id="xoay-vòng-lặp-loop-rotate"></a>
### Xoay vòng lặp

Phép tối ưu này biến vòng lặp dạng `for` thành dạng `do-while`, đồng thời thêm
một điều kiện kiểm tra ở trước vòng lặp. Mục đích chính của nó là chuẩn bị cho các
phép biến đổi tiếp theo.

```cpp
for (int i = 0; i < n; ++i) {
  auto v = *p;
  use(v);
}
```

Biến đổi thành

```cpp
if (0 < n) {
  do {
    auto v = *p;
    use(v);
    ++i;
  } while (i < n);
}
```

<a id="đưa-bất-biến-vòng-lặp-ra-ngoài-loop-invariant-code-motion"></a>
### Đưa bất biến vòng lặp ra ngoài

Dựa trên phân tích bí danh, trình biên dịch có thể đưa những đoạn mã đã chứng
minh là bất biến ra khỏi thân vòng lặp. Những đoạn này đôi khi bao gồm thao tác
đọc hoặc ghi bộ nhớ, nên việc chứng minh phụ thuộc vào phân tích bí danh. Kết quả
là thân vòng lặp còn ít mã hơn.

```cpp
for (int i = 0; i < n; ++i) {
  auto v = *p;
  use(v);
}
```

Trực quan, đoạn mã này có thể được đưa ra ngoài thành:

```cpp
auto v = *p;
for (int i = 0; i < n; ++i) {
  use(v);
}
```

Nhưng thực tế, nếu `n <= 0` thì thân vòng lặp không bao giờ được thực thi, trong
khi lại thực thi thêm một lệnh (có thể có tác dụng phụ!). Vì vậy, vòng lặp thường
được xoay thành dạng `do-while` để có thể chèn một "điều kiện bảo vệ vòng lặp" dễ
hơn, rồi sau đó mới đưa bất biến vòng lặp ra ngoài.

```cpp
if (0 < n) {  // điều kiện bảo vệ vòng lặp
  auto v = *p;
  do {
    use(v);
    ++i;
  } while (i < n);
}
```

<a id="mở-vòng-lặp-loop-unroll"></a>
### Mở vòng lặp

Vòng lặp gồm thân vòng lặp và các câu lệnh rẽ nhánh, nên CPU hiện đại phải dự
đoán nhánh ở một mức độ nhất định. Mở vòng lặp là cách chấp nhận mã dài hơn để
đổi lấy thời gian chạy ngắn hơn.

```cpp
for (int i = 0; i < 3; i++) {
  a[i] = i;
}
```

Biến đổi thành:

```cpp
a[0] = 0;
a[1] = 1;
a[2] = 2;
```

<a id="đưa-điều-kiện-vòng-lặp-ra-ngoài-loop-unswitching"></a>
### Đưa điều kiện vòng lặp ra ngoài

Kỹ thuật này đưa biểu thức điều kiện trong thân vòng lặp ra ngoài, rồi đặt hai
vòng lặp riêng trong hai nhánh điều kiện bên ngoài. Cách làm đó có thể tăng khả
năng vector hóa và song song hóa vòng lặp, vì vòng lặp càng đơn giản thì càng dễ
được vector hóa.

```cpp
// clang-format off
void before(int x) {
  for(;/* i in some range */;) {
    /* A */;
    if (/* condition */ x % 2) {
      /* B */;
    }
    /* C */;
  }
}

void after(int x) {
  if (/* condition */ x % 2) {
    for(;/* i in some range */;) {
      /* A */;
      /* B */; // Thực thi B luôn, không kiểm tra trong vòng lặp
      /* C */;
    }
  } else {
     for(;/* i in some range */;) {
      /* A */;
               // Không thực thi B
      /* C */;
    }
  }
}
```

<a id="tối-ưu-hóa-bố-cục-mã-code-layout-optimizations"></a>
### Tối ưu hóa bố cục mã

Khi chương trình thực thi, các đường đi có thể được chia thành đường nóng và
đường lạnh. Trong hầu hết trường hợp, CPU nhảy đến một vị trí khác không nhanh
bằng thực thi tuần tự liền mạch; kiểu thực thi sau thường được tác giả trình biên
dịch gọi là "đi tiếp" (fall-through). Theo cách gọi này, mã thường được thực thi
là mã nóng, còn phần hiếm khi chạy là mã lạnh. Trong mã OI, nếu có một đoạn xử lý
điều kiện biên đặc biệt trong vòng lặp, xử lý ngoại lệ, hoặc logic tương tự, đoạn
đó thường là mã lạnh.

Khối cơ bản là đơn vị nền tảng của luồng điều khiển. Một thủ tục gồm nhiều khối
cơ bản, tạo thành một đồ thị có hướng. Khi sinh tệp thực thi, trình biên dịch cần
sắp xếp vị trí của các khối cơ bản; cách sắp xếp này là trọng tâm của tối ưu hóa
bố cục mã.

Về nguyên tắc, nên ưu tiên đặt các đoạn mã nóng gần nhau và tách mã lạnh ra. Cách
này tận dụng bộ nhớ đệm lệnh tốt hơn, vì mã nóng có tính cục bộ cao hơn.

```cpp
// clang-format off
int hotpath; // <-- nóng!
if (/* điều kiện biên */ false) {
    // <-- lạnh!
}
int hotpath_again;  // <-- nóng!
```

<a id="đặt-khối-cơ-bản-basic-block-placement"></a>
#### Đặt khối cơ bản

Dùng nhãn để biểu diễn một dạng "mã máy giả". Chương trình C++ này có hai cách
bố trí:

???+ note "Bố cục 1"
    ```cpp
    // clang-format off
    hotblock1:
        Stmts; // <-- nóng!
        if (/* điều kiện biên không thỏa */ true)
            goto hotblock2; // Thường xảy ra! ------+
    coldblock:                           /*   |   */
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |  Phải đi qua nhiều lệnh, chi phí cao!
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |
    hotblock2:                          /*    |   */
        Stmts; // <- nóng!          <----------+
    ```

Một bố cục khác là:

???+ note "Bố cục 2"
    ```cpp
    // clang-format off
    hotblock1:
        Stmts; // <-- nóng!
        if (/* điều kiện biên */ false)
            goto coldblock; // Hiếm khi xảy ra
    hotblock2:                         /*   |  chi phí thấp!  */
        Stmts; // <- nóng! <-----------------+
    coldblock:
        Stmt; // <- lạnh
        Stmt; // <- lạnh
        Stmt; // <- lạnh
        Stmt; // <- lạnh
        Stmt; // <- lạnh
    ```

Trong bố cục thứ hai, hai khối mã nóng được đặt gần nhau, nên hiệu năng thực thi
tốt hơn.

Để báo cho trình biên dịch biết một nhánh có khả năng được thực thi cao hay thấp,
có thể dùng `[[likely]]` và `[[unlikely]]` của C++20:
<https://en.cppreference.com/w/cpp/language/attributes/likely>

Nếu cuộc thi không dùng tiêu chuẩn C++20 trở lên, có thể dùng `__builtin_expect`
(mở rộng GNU).

```cpp
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

if (unlikely(/* một số kiểm tra điều kiện biên */ false)) {
  // Mã lạnh
}
```

<a id="tách-mã-nóng-lạnh-hot-cold-splitting"></a>
#### Tách mã nóng/lạnh

Một thủ tục có thể chứa đồng thời cả đường nóng và đường lạnh. Khi mã lạnh dài,
cách tốt hơn là tách mã lạnh thành một lời gọi hàm, thay vì để nó chen vào đường
nóng. Điều này cũng nhắc rằng không nên tự tin quá mức mà biến mọi hàm thành
`inline`. Trở ngại mà mã lạnh gây ra cho tốc độ thực thi có thể lớn hơn đáng kể
so với chi phí gọi hàm.

???+ note "Bố cục mã không tốt"
    ```cpp
    // clang-format off
    void foo() {
          // clang-format off
    hotblock1:
        Stmts; // <-- nóng!
        if (/* điều kiện biên không thỏa */ true)
            goto hotblock2; // Thường xảy ra! ------+
    coldblock:                           /*   |   */
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |  Phải đi qua nhiều lệnh, chi phí cao!
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |
        Stmt; // <- lạnh                      |
    hotblock2:                          /*    |   */
        Stmts; // <- nóng!          <----------+
    }
    ```

???+ note "Bố cục mã tốt"
    ```cpp
    // clang-format off
    void foo() {
    hotblock1:
      Stmts;  // <-- nóng!
      if (/* điều kiện biên */ false)
        coldBlock();  // Tách mã lạnh ra để đường nóng phù hợp với cache hơn
    hotblock2:
      Stmts;  // <- nóng!
    }

    void coldBlock() {
      Stmt;  // <- lạnh
      Stmt;  // <- lạnh
      Stmt;  // <- lạnh
      Stmt;  // <- lạnh
      Stmt;  // <- lạnh
      Stmt;  // <- lạnh
      Stmt;  // <- lạnh
    }
    ```

Tách mã nóng/lạnh là thao tác ngược với nội tuyến hàm. Sự tồn tại của tối ưu hóa
này cho thấy nội tuyến hàm không nhất thiết làm chương trình chạy nhanh hơn. Nếu
đoạn mã được nội tuyến là mã lạnh, nó thậm chí có thể làm chương trình chạy chậm
hơn. Một số trình biên dịch có tùy chọn ép nội tuyến, nhưng không nên dùng tùy
tiện. Bên trong trình biên dịch có quá trình phân tích tĩnh để ước lượng xác suất
của mỗi khối cơ bản và mỗi nhánh, cùng với một mô hình chi phí liên quan đến lời
gọi hàm, rồi dựa vào đó quyết định có nội tuyến hay không. Tự quyết định nội
tuyến không hẳn tốt hơn quyết định của trình biên dịch.

Thực tế, khi không có thông tin bổ sung, trình biên dịch thường giả định xác suất
nhảy nhánh và không nhảy nhánh là như nhau, rồi dựa vào đó lan truyền mức nóng
hoặc lạnh của các đường luồng điều khiển. Một phần của PGO (tối ưu hóa dựa trên
hồ sơ chạy) là chạy chương trình nhiều lần trong các phép đo và thử nghiệm hiệu
năng để thu được xác suất nhánh trong môi trường thực; thông tin này giúp bố cục
mã tốt hơn.

<a id="nội-tuyến-hàm-function-inlining"></a>
### Nội tuyến hàm

Lời gọi hàm thường cần thanh ghi và ngăn xếp để truyền tham số; cả bên gọi và bên
được gọi đều phải lưu một số trạng thái thanh ghi. Cơ chế này thường được gọi là
quy ước gọi hàm. Vì vậy, lời gọi hàm luôn có một phần chi phí thời gian. Nội
tuyến hàm nghĩa là chép thân hàm vào thủ tục của bên gọi, không thực hiện lời gọi
hàm thật sự.

```cpp
int add(int x) { return x + 1; }

int foo() {
  int a = 1;
  a = add(a);
}
```

`add()` có thể được nội tuyến vào trong `foo()`:

```cpp
int foo() {
  int a = 1;
  a = a + 1;  // <-- thân hàm add(), không cần truyền tham số
}
```

#### `always_inline`, `__force_inline`

<https://clang.llvm.org/docs/AttributeReference.html#always-inline-force-inline>

Một số trình biên dịch cung cấp cách yêu cầu nội tuyến lời gọi hàm thủ công bằng
cách thêm `__attribute__((always_inline))` trước hàm. Cách này không nhất thiết
nhanh hơn lời gọi hàm; lúc đó trình biên dịch tin rằng lập trình viên có đủ cơ sở
để tự phán đoán.

<a id="tối-ưu-hóa-lời-gọi-đuôi-tail-call-optimization"></a>
### Tối ưu hóa lời gọi đuôi

Khi một lời gọi hàm nằm ở vị trí cuối thân hàm, lời gọi đó được gọi là lời gọi
đuôi. Với dạng lời gọi đặc biệt này, có thể thực hiện một số tối ưu hóa riêng.
Hầu hết kiến trúc có con trỏ khung (FP) và con trỏ ngăn xếp (SP) để duy trì khung
gọi hàm; nếu lời gọi nằm ở cuối hàm, có thể không cần giữ lại bản ghi gọi của hàm
bên ngoài mà chuyển thẳng sang hàm bên trong.

<a id="dùng-lệnh-nhảy-thay-cho-lời-gọi-hàm"></a>
#### Dùng lệnh nhảy thay cho lời gọi hàm

Trên hầu hết kiến trúc, lời gọi hàm cần lưu vị trí bộ đếm chương trình hiện tại
`$pc`, đồng thời lưu một số thanh ghi do bên gọi chịu trách nhiệm lưu để có thể
quay lại ngữ cảnh cũ. Lời gọi đuôi không cần quá trình này và sẽ được dịch thành
lệnh nhảy, vì nó không bao giờ quay lại vị trí đang chạy của hàm hiện tại.

Một ví dụ đơn giản: <https://godbolt.org/z/e7b1safaW>

```cpp
int test(int a);

int tailCall(int x) { return test(x); }
```

```nasm
tailCall(int):                           ; @tailCall(int)
        jmp     test(int)@PLT                    ; TAILCALL
```

<a id="tự-động-viết-lại-đệ-quy-đuôi"></a>
#### Tự động viết lại đệ quy đuôi

Nếu lời gọi đuôi của một hàm gọi lại chính hàm đó, hàm này là hàm đệ quy đuôi.
Nói rộng hơn, đệ quy gián tiếp, tức đệ quy tạo bởi hai hàm trở lên, cũng thuộc
phạm vi này nếu mọi lời gọi đệ quy đều là lời gọi đuôi. Đệ quy đuôi có thể được
trình biên dịch tối ưu thành dạng không đệ quy, nhờ đó giảm chi phí ngăn xếp và
chi phí gọi hàm. Nhiều thí sinh OI thích viết mã không đệ quy; khi không bật tối
ưu hóa, cách này có thể cải thiện hằng số đáng kể. Khi đã bật tối ưu hóa, chất
lượng mã máy sinh ra từ phiên bản đệ quy và phiên bản tự viết vòng lặp thường
không khác nhau nhiều.

```cpp
int fac(int n) {
  if (n < 2) return 1;
  return /* dùng */ n * fac(n - 1); /* còn dùng n, nên chưa thể tối ưu thành đệ quy đuôi! */
}
```

Lưu ý rằng hàm này không phải đệ quy đuôi, nhưng có thể viết lại thành:

```cpp
int fac(int acc, int n) {
  if (n < 2) return acc;
  return fac(acc * n, n - 1);
}
```

Đoạn mã mới là đệ quy đuôi.

Trình biên dịch hiện đại có thể tự động làm việc này. Nếu mã có thể được viết lại
thành đệ quy đuôi, trình biên dịch có thể nhận diện dạng này và hoàn tất việc
viết lại.

<a id="loại-bỏ-đệ-quy-đuôi-rpass-tailcallelim"></a>
#### Loại bỏ đệ quy đuôi -Rpass=tailcallelim

Khi hàm đã là đệ quy đuôi, có thể xóa câu lệnh đệ quy và, thông qua một số phân
tích tĩnh, biến hàm thành dạng không đệ quy. Phần này không đi sâu vào cách tác
giả trình biên dịch làm được điều đó. Từ trải nghiệm thực tế, phần lớn mã OI nếu
có cả phiên bản đệ quy và không đệ quy thì thường có thể được tự động tối ưu thành
phiên bản không đệ quy. Sau đây là một số ví dụ cụ thể:

???+ note "[GCD](https://godbolt.org/z/8Wb6WEnzv)"
    ```cpp
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    ```

???+ note "[Dãy Fibonacci](https://godbolt.org/z/4enof6Wcb)"
    ```cpp
    // Mở hạng tử fib(n - 2)
    // fib(n - 1) không thể biến đổi thành không đệ quy; mã tối ưu vẫn có độ phức tạp lũy thừa
    int fib(int n) {
      if (n < 2) return 1;
      return fib(n - 1) + fib(n - 2);
    }
    ```

???+ note "[Giai thừa](https://godbolt.org/z/n64e75xrf)"
    ```cpp
    // Mở thành vòng lặp vô hướng, rồi tự động vector hóa; mã sinh ra là SIMD
    unsigned fac(unsigned n) {
      if (n < 2) return 1;
      return n * fac(n - 1);
    }
    ```

Hợp ngữ sau tối ưu hóa của các hàm này hoàn toàn giống phiên bản không đệ quy; đệ
quy sẽ bị loại bỏ. Với thí sinh OI, khi bật `-O2`, có thể yên tâm viết các thuật
toán dạng đệ quy trong những trường hợp phù hợp, vì mã sinh ra thường không khác
dạng không đệ quy. Nếu hàm về bản chất không thể được viết lại thành dạng không
đệ quy, trình biên dịch cũng không thể tối ưu theo cách này.

<a id="giảm-độ-mạnh-phép-toán-strength-reduction"></a>
### Giảm độ mạnh phép toán

Đây là một tối ưu hóa biên dịch phổ biến. Ví dụ đơn giản là biến `x * 2` thành
`x << 1`, một cách viết rất thường gặp trong OI. Trình biên dịch sẽ tự động thực
hiện các tối ưu hóa tương tự; khi bật tối ưu hóa, `x * 2` và `x << 1` thường sinh
ra mã tương đương. Giảm độ mạnh phép toán nghĩa là thay các lệnh chi phí cao bằng
các lệnh chi phí thấp hơn.

<a id="biến-đổi-toán-tử-scalar"></a>
#### Biến đổi toán tử vô hướng

<a id="dùng-dịch-bit-thay-cho-phép-nhân"></a>
##### Dùng dịch bit thay cho phép nhân

```cpp
int a;
a = x * 2;   // không tốt!
a = x << 1;  // tốt!
```

Cần lưu ý rằng số có dấu và số không dấu khác nhau rõ ở cấp độ dịch bit và nâng
kiểu. Khi dịch bit, bit dấu được xử lý đặc biệt; hai dạng thường gặp là dịch số
học và dịch logic. Điều này thể hiện rõ khi viết tìm kiếm nhị phân, cây đoạn và
các cấu trúc có nhiều phép chia đôi: phép chia số nguyên có dấu không phải lúc nào
cũng tối ưu được thành một lệnh dịch phải duy nhất.

```cpp
int l, r;
/* codes */
int mid = (l + r) / 2; /* Nếu trình biên dịch không thể giả định l, r không âm, nó sẽ sinh mã kém hơn */
                       // Không thể tối ưu thành
                       // mid = (l + r) >> 1
                       // Phản ví dụ:
                       // mid = -127
                       // mid / 2 = -63
                       // mid >> 1 = -64
```

```cpp
int mid = (l + r);
int sign = mid >> 31; /* dịch phải số học, lấy bit dấu */
mid += sign;
mid >>= 1; /* dịch phải số học */
```

Các cách giải quyết khả thi:

-   Nếu bài toán bảo đảm chỉ số không âm, có thể dùng `unsigned l, r;`
-   Dùng dịch bit ngay trong mã nguồn

<a id="dùng-phép-nhân-thay-cho-phép-chia"></a>
##### Dùng phép nhân thay cho phép chia

```cpp
int x = a / 3;
```

Phép chia này có thể được biến đổi thành `x = a * 0x55555556 >> 32`; chi tiết xem
[bài trả lời Zhihu này](https://zhuanlan.zhihu.com/p/151038723) hoặc
[bài báo gốc](https://dl.acm.org/doi/10.1145/773473.178249).

<a id="giảm-độ-mạnh-cho-biến-chỉ-số-indvars"></a>
#### Giảm độ mạnh cho biến chỉ số

Trình biên dịch tự động nhận diện các biến chỉ số trong vòng lặp và thay các phép
tính liên quan có chi phí cao bằng phép tính chi phí thấp hơn.

```cpp
int a = 0;
for (int i = 1; i < 10; i++) {
  a = 3 * i;  // không tốt!
  a = a + 3;  // tốt!
}
```

Việc viết `a = 3 * i` thường gặp trong OI, nhưng trình biên dịch có thể tự động
phân tích phép biến đổi tương đương `a = a + 3`, dùng phép cộng rẻ hơn thay cho
phép nhân. Phân tích tiến triển của biến vòng lặp được gọi là SCEV (Scalar
Evolution, tiến triển vô hướng).

SCEV còn có thể tối ưu một số vòng lặp:

```cpp
int test(int n) {
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans += i * (i + 1);
  }
  return ans;
}
```

Hàm này sẽ được tối ưu thành công thức tính tổng $O(1)$; xem ví dụ tại
<https://godbolt.org/z/ET8d89vvK>. Hiện tượng này hiện chỉ xuất hiện ở các trình
biên dịch dựa trên LLVM; GCC bảo thủ hơn.

```nasm
test(int):                               # @test(int)
        test    edi, edi
        jle     .LBB0_1
        lea     eax, [rdi - 1]
        lea     ecx, [rdi - 2]
        imul    rcx, rax
        lea     eax, [rdi - 3]
        imul    rax, rcx
        shr     rax
        imul    eax, eax, 1431655766
        and     ecx, -2
        lea     eax, [rax + 2*rcx]
        lea     eax, [rax + 2*rdi]
        dec     eax
        ret
.LBB0_1:
        mov     eax, 1
        ret
```

<a id="tự-động-vector-hóa-auto-vectorization"></a>
### Tự động vector hóa

Một luồng lệnh trên nhiều phần tử dữ liệu là cách tốt để khai thác song song hóa
trong một lõi CPU. Các lệnh này tận dụng thanh ghi SIMD của CPU, vốn rộng hơn
thanh ghi đa dụng; chẳng hạn, có thể nạp 4 số nguyên rồi tính toán trong một lượt.
Thí sinh OI không cần hiểu sâu chi tiết tự động vector hóa. Thông thường, Clang
tự động vector hóa mạnh hơn GCC:

```cpp
// https://godbolt.org/z/h1hx5sWoE
void test(int *a, int *b, int n) {
  for (int i = 0; i < n; i++) {
    a[i] += b[i];
  }
}
```

#### Bộ chỉ định kiểu `__restrict` (GNU, MSVC)

Hai vùng nhớ tương ứng với hai con trỏ bất kỳ có thể bị chồng lấp, khi đó cần xử
lý riêng xem có thể dùng mã vector hay không. Hình sau minh họa một ví dụ về
chồng lấp con trỏ:

![](./images/overlap.png)

`__restrict` là một quy ước giúp trình biên dịch giả định rằng hai vùng nhớ được
hai con trỏ trỏ tới sẽ không bao giờ chồng lấp.

```cpp
void test(int* __restrict a, int* __restrict b, int n) {
  for (int i = 0; i < n; i++) {
    a[i] += b[i];
  }
}
```

`__restrict` không phải một phần của chuẩn C++, nhưng các trình biên dịch lớn đều
hỗ trợ. Từ khóa này ảnh hưởng đến chất lượng mã sinh ra khi tự động vector hóa;
có thể dùng trong các trường hợp cần tối ưu hằng số thật chặt.

<a id="các-cách-dùng-ngôn-ngữ-sai-thường-gặp-liên-quan-đến-tối-ưu-hóa-biên-dịch"></a>
## Các cách dùng ngôn ngữ sai thường gặp liên quan đến tối ưu hóa biên dịch

<a id="inline---nội-tuyến"></a>
### inline - nội tuyến

Khi bật `-O2`, việc nội tuyến hàm thường do trình biên dịch tự quyết định.
`inline` trong định nghĩa `struct` hầu như là thừa; nếu cuộc thi bật tối ưu hóa
`-O2` thì không cần khai báo nội tuyến thủ công. Nếu không bật `-O2`, thêm
`inline` cũng không bảo đảm trình biên dịch sẽ thật sự nội tuyến.

Trong C++ hiện đại, từ khóa `inline` chủ yếu mang ý nghĩa về liên kết và xuất ký
hiệu, chứ không phải là mệnh lệnh buộc trình biên dịch nội tuyến hàm.

<a id="register---gợi-ý-thanh-ghi-không-còn-thực-chất"></a>
### register - gợi ý thanh ghi không còn ý nghĩa thực tế

Trình biên dịch hiện đại sẽ bỏ qua từ khóa `register`; cách tự chọn thanh ghi
thường không tốt bằng việc để trình biên dịch chạy thuật toán phân bổ thanh ghi.
Từ khóa này không còn được khuyến nghị từ C++11 và bị xóa từ C++17[^p0001r1].

<https://en.cppreference.com/w/cpp/keyword/register>

<a id="hành-vi-không-xác-định-undefined-behavior-và-tối-ưu-hóa-biên-dịch"></a>
## Hành vi không xác định (UB) và tối ưu hóa biên dịch

Trình biên dịch có thể giả định rằng chương trình C++ không có
[hành vi không xác định](https://en.cppreference.com/w/cpp/language/ub) (UB).
Vì vậy, khi biên dịch một chương trình có UB, trình biên dịch có thể tạo ra kết
quả ngoài dự kiến. Đồng thời, nó cũng dựa trên giả định không có UB để tối ưu hóa
tự do và mạnh tay hơn.

Các UB thường gặp gồm:

1.  [Tràn số có dấu](https://users.cs.utah.edu/~regehr/papers/overflow12.pdf);
2.  Dùng biến chưa khởi tạo;
3.  Truy cập vượt biên;
4.  Giải tham chiếu con trỏ null;
5.  Vòng lặp vô hạn không có tác dụng phụ.

Xem thêm các UB khác và ví dụ ở phần đọc thêm.

<a id="tràn-số-có-dấu"></a>
### Tràn số có dấu

```cpp
int f(int x) { return x * 2 / 2; }
```

Trình biên dịch có thể giả định chương trình không có hành vi tràn số có dấu, nên
hàm này có thể được tối ưu thành

```cpp
int f(int x) { return x; }
```

Ví dụ: <https://godbolt.org/z/WKv3W5hvM>, <https://godbolt.org/z/qqE9nxP1j>.

Có thể dùng tùy chọn
[`-fwrapv`](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Code-Gen-Options.html#index-fwrapv)
để tắt giả định này. Ví dụ: <https://godbolt.org/z/5x3K5KGnr>,
<https://godbolt.org/z/4r4a4EzMW>.

<a id="dùng-biến-chưa-khởi-tạo"></a>
### Dùng biến chưa khởi tạo

```cpp
int f(int x) {
  int a;
  if (x)  // hoặc x khác 0, hoặc xảy ra UB
    a = 42;
  return a;
}
```

Trình biên dịch có thể giả định chương trình không dùng biến chưa khởi tạo, nên
`a` đã được khởi tạo, và hàm này có thể được tối ưu thành

```cpp
int f(int) { return 42; }
```

Ví dụ: <https://godbolt.org/z/8WYMYYjdG>, <https://godbolt.org/z/qvGd1nvv9>.

<a id="truy-cập-vượt-biên"></a>
### Truy cập vượt biên

```cpp
int table[4] = {};

bool exists_in_table(int v) {
  // trả về true trong một trong 4 lượt lặp đầu tiên,
  // hoặc xảy ra UB do truy cập vượt biên
  for (int i = 0; i <= 4; i++)
    if (table[i] == v) return true;
  return false;
}
```

Trình biên dịch có thể giả định chương trình không truy cập vượt biên, nên hàm
này sẽ trả về trước khi truy cập vượt biên xảy ra. Do đó nó có thể được tối ưu
thành

```cpp
bool exists_in_table(int) { return true; }
```

Ví dụ: <https://godbolt.org/z/xfePeYsE3>.

<a id="giải-tham-chiếu-con-trỏ-null"></a>
### Giải tham chiếu con trỏ null

```cpp
int f(int* p) {
  int x = *p;
  if (!p)
    return x;  // Hoặc đã xảy ra UB ở trên, hoặc nhánh này không bao giờ được đi tới
  else
    return 0;
}
```

Trình biên dịch có thể giả định chương trình không giải tham chiếu con trỏ null,
nên `!p` luôn là `false`, và hàm này có thể được tối ưu thành

```cpp
int f(int*) { return 0; }
```

Ví dụ: <https://godbolt.org/z/GY1jvsrb5>, <https://godbolt.org/z/4ronPsnxf>.

<a id="vòng-lặp-vô-hạn-không-có-tác-dụng-phụ"></a>
### Vòng lặp vô hạn không có tác dụng phụ

???+ note "Kiểm chứng Định lý lớn Fermat"
    Theo [Định lý lớn Fermat](https://en.wikipedia.org/wiki/Fermat%27s_Last_Theorem),
    phương trình vô định $a^3=b^3+c^3$ không có nghiệm nguyên dương. Chương trình
    sau thử liệt kê các số nguyên trong $[1,1000]$ để kiểm chứng phương trình này.
    Nếu trả về `true` thì nghĩa là đã tìm thấy một bộ nghiệm nguyên trong phạm vi
    $[1,1000]$, kéo theo Định lý lớn Fermat không đúng.

    ```cpp
    #include <iostream>

    bool fermat() {
      const int max_value = 1000;

      // Vòng lặp vô hạn không có tác dụng phụ là UB
      for (int a = 1, b = 1, c = 1; true;) {
        if (((a * a * a) == ((b * b * b) + (c * c * c))))
          return true;  // đã bị bác bỏ :(
        a++;
        if (a > max_value) {
          a = 1;
          b++;
        }
        if (b > max_value) {
          b = 1;
          c++;
        }
        if (c > max_value) c = 1;
      }

      return false;  // chưa bị bác bỏ
    }

    int main() {
      std::cout << "Định lý lớn Fermat ";
      fermat() ? std::cout << "đã bị bác bỏ!\n"
               : std::cout << "chưa bị bác bỏ.\n";
    }
    ```

Trình biên dịch có thể giả định chương trình không có vòng lặp vô hạn không có
tác dụng phụ, nên nó cho rằng vòng `for` trong hàm `fermat()` sẽ kết thúc tại một
thời điểm nào đó và trả về `true`. Cuối cùng chương trình có thể in ra:

```text
Định lý lớn Fermat đã bị bác bỏ!
```

Ví dụ: <https://godbolt.org/z/d834MK7bz>, <https://godbolt.org/z/Eov9nsKqf>.

## Công cụ sanitizer

Sanitizer là công cụ hỗ trợ bảo đảm tính đúng đắn: nó kiểm tra lúc chạy xem
chương trình có hành vi không xác định, truy cập vượt biên, con trỏ null và các
lỗi tương tự hay không.
Ở chế độ gỡ lỗi cục bộ, nên bật một số sanitizer; chúng có thể rút ngắn đáng kể
thời gian gỡ lỗi. Các sanitizer này do Google phát triển, phần lớn có thể dùng với
GCC và Clang. Sanitizer trong LLVM trưởng thành hơn, vì vậy nên dùng Clang để gỡ
lỗi các vấn đề liên quan trên máy cá nhân.

<span id="address-sanitizer-fsanitizeaddress"></span>
### AddressSanitizer `-fsanitize=address`

<https://clang.llvm.org/docs/AddressSanitizer.html>

Cả GCC và Clang đều hỗ trợ sanitizer này. Nó bao gồm các mục kiểm tra sau:

-   Vượt biên
-   Dùng sau khi giải phóng
-   Dùng sau khi trả về
-   Giải phóng lặp lại
-   Rò rỉ bộ nhớ
-   Dùng sau khi rời khỏi phạm vi

Áp dụng kiểm tra này sẽ làm chương trình chậm khoảng 2x.

<span id="undefined-behavior-sanitizer-fsanitizeundefined"></span>
### UndefinedBehaviorSanitizer `-fsanitize=undefined`

<https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html>

UndefinedBehaviorSanitizer (còn gọi là UBSan) dùng để kiểm tra hành vi không xác
định trong mã. Cả GCC và Clang đều hỗ trợ sanitizer này. Nó tự động kiểm tra
chương trình có UB hay không. Các mục kiểm tra của UBSan gồm:

-   Tràn phép dịch bit, ví dụ dịch trái một số nguyên 32 bit thêm 72 bit
-   Tràn số nguyên có dấu
-   Tràn dữ liệu khi chuyển đổi số thực dấu phẩy động sang số nguyên

Các mục kiểm tra của UBSan có thể tùy chọn; mức ảnh hưởng đến chương trình được
mô tả trong trang tài liệu đã dẫn.

<a id="linh-tinh"></a>
## Linh tinh

<span id="compiler-explorer-trình-khám-phá-biên-dịch"></span>
### Trình khám phá biên dịch

Quan sát hành vi và mã hợp ngữ của các trình biên dịch tại đây: <https://godbolt.org>

<a id="đọc-thêm"></a>
## Đọc thêm

1.  [The LLVM Project Blog: What Every C Programmer Should Know About Undefined Behavior #1/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know.html)
2.  [The LLVM Project Blog: What Every C Programmer Should Know About Undefined Behavior #2/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know_14.html)
3.  [The LLVM Project Blog: What Every C Programmer Should Know About Undefined Behavior #3/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know_21.html)

<a id="tài-liệu-tham-khảo-và-chú-thích"></a>
## Tài liệu tham khảo và chú thích

[^p0001r1]: [Remove Deprecated Use of the register Keyword (open-std.org)](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0001r1.html)
