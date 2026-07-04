author: inclyc

Ngôn ngữ lập trình thường dùng trong giới OI là C++. Đã dùng ngôn ngữ này thì khó tránh việc phải làm việc với trình biên dịch và tiêu chuẩn ngôn ngữ. Ai cũng biết C++ khá rối rắm; bài viết này tập trung đưa ra những kiến thức thực dụng về trình biên dịch, đủ dùng cho thi đấu.

<a id="giới-thiệu-về-tối-ưu-hóa-của-trình-biên-dịch"></a>
## Giới thiệu về tối ưu hóa của trình biên dịch

<a id="tối-ưu-hóa-là-gì-optimization"></a>
### Tối ưu hóa là gì (Optimization)

Theo [quy tắc as-if](https://en.cppreference.com/w/cpp/language/as_if) (The as-if Rule), trình biên dịch có thể cải thiện tốc độ chạy của chương trình hoặc kích thước tệp thực thi, miễn là giữ nguyên ngữ nghĩa quan sát được của chương trình.

<!-- ### Những cuộc thi nào bật tối ưu hóa? -->

<!-- TODO: Các cuộc thi bật O2 -->

<a id="các-tối-ưu-hóa-trình-biên-dịch-thường-gặp"></a>
## Các tối ưu hóa trình biên dịch thường gặp

<a id="gấp-hằng-số-constant-folding"></a>
### Gấp hằng số (Constant Folding)

Gấp hằng số, cũng được gọi là lan truyền hằng số (Constant Propagation): nếu một biểu thức có thể được xác định là hằng số, giá trị hằng số đó có thể được lan truyền cho đến trước lần định nghĩa (Definition) kế tiếp của nó.

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
### Loại bỏ mã chết (Deadcode Elimination)

Đúng như tên gọi, một đoạn mã không được dùng đến sẽ bị xóa bỏ.

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

Lưu ý, đoạn mã này trước hết được gấp hằng số, nên giá trị trả về có thể xác định là 234; `a` và `b` là các biến không còn sống, vì vậy bị xóa bỏ.

<a id="xoay-vòng-lặp-loop-rotate"></a>
### Xoay vòng lặp (Loop Rotate)

Biến đổi vòng lặp từ dạng "for" sang dạng "do-while", đồng thời thêm một điều kiện kiểm tra ở phía trước. Phép biến đổi này chủ yếu để chuẩn bị cho các phép biến đổi khác.

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
### Đưa bất biến vòng lặp ra ngoài (Loop Invariant Code Motion)

Dựa trên phân tích bí danh (Alias Analysis), trình biên dịch đưa những đoạn mã trong vòng lặp đã được chứng minh là bất biến ra ngoài thân vòng lặp. Các đoạn mã này có thể bao gồm truy cập bộ nhớ, load/store, nên việc chứng minh phụ thuộc vào phân tích bí danh. Kết quả là thân vòng lặp có ít mã hơn.

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

Nhưng trên thực tế, nếu `n <= 0` thì vòng lặp không bao giờ được vào, trong khi ta lại thực thi thêm một lệnh (có thể có tác dụng phụ!). Vì vậy, vòng lặp thường được Rotate thành dạng do-while để có thể chèn một "loop guard" một cách thuận tiện, rồi sau đó mới thực hiện đưa bất biến vòng lặp ra ngoài.

```cpp
if (0 < n) {  // loop guard
  auto v = *p;
  do {
    use(v);
    ++i;
  } while (i < n);
}
```

<a id="mở-vòng-lặp-loop-unroll"></a>
### Mở vòng lặp (Loop Unroll)

Vòng lặp gồm thân vòng lặp và các câu lệnh rẽ nhánh, nên CPU hiện đại cần thực hiện một mức độ dự đoán nhánh nhất định. Mở trực tiếp vòng lặp là cách đổi thêm kích thước mã lấy thời gian chạy ngắn hơn.

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
### Đưa điều kiện vòng lặp ra ngoài (Loop Unswitching)

Loop unswitching đưa biểu thức điều kiện trong vòng lặp ra ngoài vòng lặp, rồi đặt hai vòng lặp riêng trong hai nhánh điều kiện bên ngoài. Cách này có thể tăng khả năng vector hóa và song song hóa vòng lặp (thông thường vòng lặp đơn giản dễ được vector hóa hơn).

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
      /* B */; // Thực thi B trực tiếp, không kiểm tra trong vòng lặp
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
### Tối ưu hóa bố cục mã (Code Layout Optimizations)

Khi chương trình thực thi, các đường chạy có thể được chia thành đường lạnh và đường nóng (cold/hot path). Trong tuyệt đại đa số trường hợp, CPU nhảy đến một vị trí khác không nhanh bằng thực thi tuần tự trực tiếp; kiểu thực thi sau thường được tác giả trình biên dịch gọi là "fallthrough". Tương ứng với nó, mã thường được thực thi là mã nóng, còn phần đối lập là mã lạnh. Trong mã OI, nếu có một đoạn xử lý điều kiện biên đặc biệt trong vòng lặp, xử lý ngoại lệ, hoặc logic tương tự, đoạn đó là mã lạnh.

Khối cơ bản (Basic Block) là cấu trúc cơ bản của luồng điều khiển. Một thủ tục (Procedure) gồm nhiều khối cơ bản, tạo thành một đồ thị có hướng. Trong quá trình sinh tệp thực thi, trình biên dịch cần sắp xếp bố cục (Layout) để đặt các khối cơ bản; cách sắp xếp bố cục chính là trọng tâm của tối ưu hóa này.

Về nguyên tắc, nên ưu tiên đặt các đoạn mã nóng gần nhau và tách mã lạnh ra. Lý do là cách này tận dụng instruction cache tốt hơn, vì mã nóng có tính cục bộ tốt hơn.

```cpp
// clang-format off
int hotpath; // <-- nóng!
if (/* điều kiện biên */ false) {
    // <-- lạnh!
}
int hotpath_again;  // <-- nóng!
```

<a id="đặt-khối-cơ-bản-basic-block-placement"></a>
#### Đặt khối cơ bản (Basic Block Placement)

Ta dùng label để biểu diễn một loại "mã máy giả". Chương trình C++ này có hai cách dịch:

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
        Stmt; // <- lạnh                      |  Vượt qua rất nhiều lệnh, chi phí cao!
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

Ta thấy trong bố cục thứ hai, hai khối mã nóng được đặt gần nhau, nên hiệu năng thực thi tốt hơn.

Để báo cho trình biên dịch biết một nhánh có dễ được thực thi hay không, có thể dùng `[[likely]]` và `[[unlikely]]` của C++20: <https://en.cppreference.com/w/cpp/language/attributes/likely>

Nếu cuộc thi không dùng tiêu chuẩn C++20 trở lên, có thể dùng `__builtin_expect` (GNU Extension).

```cpp
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

if (unlikely(/* một số kiểm tra điều kiện biên */ false)) {
  // Mã lạnh
}
```

<a id="tách-mã-nóng-lạnh-hot-cold-splitting"></a>
#### Tách mã nóng/lạnh (Hot Cold Splitting)

Một thủ tục (Procedure) có thể chứa đồng thời cả đường nóng và đường lạnh. Khi mã lạnh khá dài, cách tốt hơn là để mã lạnh thành một lời gọi hàm, thay vì chặn đường nóng. Điều này cũng nhắc ta không nên tự tin quá mức mà biến mọi hàm thành `inline`. Trở ngại mà mã lạnh gây ra cho tốc độ thực thi lớn hơn chi phí gọi hàm rất nhiều.

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
        Stmt; // <- lạnh                      |  Vượt qua rất nhiều lệnh, chi phí cao!
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
        coldBlock();  // Tách mã lạnh ra để đường nóng thân thiện với cache hơn
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

Tách mã nóng/lạnh thực ra là thao tác ngược với nội tuyến hàm (Function Inlining). Sự tồn tại của tối ưu hóa này cho thấy nội tuyến hàm không nhất thiết làm chương trình chạy nhanh hơn. Thậm chí nếu đoạn mã được nội tuyến là mã lạnh, nó còn có thể làm chương trình chạy chậm hơn. Một số trình biên dịch có tùy chọn biên dịch bắt buộc nội tuyến, nhưng không nên dùng. Bên trong trình biên dịch có quá trình phân tích tĩnh để tính xác suất của mỗi khối cơ bản và mỗi nhánh, cùng với một mô hình chi phí liên quan đến lời gọi hàm, rồi dựa vào đó quyết định có nội tuyến hay không. Tự quyết định nội tuyến không chắc tốt hơn quyết định của trình biên dịch.

Thực tế, khi không có thông tin bổ sung, trình biên dịch thường giả định xác suất nhảy nhánh và không nhảy nhánh là như nhau, rồi dựa vào đó lan truyền mức nóng/lạnh của các đường luồng điều khiển. Một phần của PGO (Profile Guided Optimization) là chạy nhiều lần benchmark và thí nghiệm hiệu năng để thu được xác suất nhánh trong môi trường thực, những thông tin này có thể giúp bố cục mã tốt hơn.

<a id="nội-tuyến-hàm-function-inlining"></a>
### Nội tuyến hàm (Function Inlining)

Lời gọi hàm thường cần thanh ghi và ngăn xếp để truyền tham số; cả bên gọi (caller) và bên được gọi (callee) đều cần lưu một số trạng thái thanh ghi. Quá trình này thường được gọi là quy ước gọi hàm (calling convention). Vì vậy một lời gọi hàm gây ra một số tổn hao thời gian, còn nội tuyến hàm nghĩa là viết trực tiếp thân hàm vào thủ tục của bên gọi, không thực hiện lời gọi hàm thật sự.

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

#### `always_inline`,`__force_inline`

<https://clang.llvm.org/docs/AttributeReference.html#always-inline-force-inline>

Một số trình biên dịch cung cấp cách nội tuyến lời gọi hàm thủ công bằng cách thêm `__attribute__((always_inline))` trước hàm. Dùng như vậy không nhất thiết nhanh hơn lời gọi hàm; lúc này trình biên dịch tin rằng lập trình viên có đủ năng lực phán đoán.

<a id="tối-ưu-hóa-lời-gọi-đuôi-tail-call-optimization"></a>
### Tối ưu hóa lời gọi đuôi (Tail Call Optimization)

Khi một lời gọi hàm nằm ở vị trí cuối thân hàm, lời gọi đó được gọi là lời gọi đuôi (Tail Call). Với dạng lời gọi đặc biệt này, có thể thực hiện một số tối ưu hóa riêng. Tuyệt đại đa số kiến trúc có Frame Pointer (a.k.a FP) và Stack Pointer (a.k.a SP) để duy trì khung gọi hàm (Frame) của hàm; nếu lời gọi nằm ở cuối hàm, ta có thể không giữ lại bản ghi gọi của hàm bên ngoài mà dùng trực tiếp hàm bên trong thay thế.

<a id="dùng-lệnh-nhảy-thay-cho-lời-gọi-hàm"></a>
#### Dùng lệnh nhảy thay cho lời gọi hàm

Trên tuyệt đại đa số kiến trúc, lời gọi hàm cần lưu vị trí bộ đếm chương trình hiện tại `$pc`, đồng thời lưu một số caller-saved register để có thể quay lại ngữ cảnh cũ. Tail call không cần quá trình này và sẽ được dịch trực tiếp thành lệnh nhảy, vì lời gọi đuôi không bao giờ quay lại vị trí đang chạy của hàm hiện tại.

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

Nếu lời gọi đuôi của một hàm là chính nó, hàm đó là hàm đệ quy đuôi. Nói rộng hơn, đệ quy gián tiếp (đệ quy tạo bởi hai hàm trở lên) nếu tất cả đều là lời gọi đuôi thì cũng thuộc phạm vi đệ quy đuôi. Đệ quy đuôi có thể được trình biên dịch tối ưu thành dạng không đệ quy, giảm chi phí ngăn xếp bổ sung và chi phí gọi hàm. Nhiều thí sinh lập trình thi đấu thích viết mã không đệ quy; khi không bật tối ưu hóa, cách này có thể cải thiện hằng số rất nhiều, nhưng nếu bật tối ưu hóa thì chất lượng nhị phân sinh ra từ mã đệ quy và mã viết tay không khác nhau bao nhiêu.

```cpp
int fac(int n) {
  if (n < 2) return 1;
  return /* dùng */ n * fac(n - 1); /* dùng biến n, không thể trực tiếp tối ưu đệ quy đuôi! */
}
```

Chú ý rằng hàm này không phải đệ quy đuôi, nhưng có thể viết lại thành:

```cpp
int fac(int acc, int n) {
  if (n < 2) return acc;
  return fac(acc * n, n - 1);
}
```

Đoạn mã mới là đệ quy đuôi.

Trình biên dịch hiện đại có thể tự động làm việc này cho bạn. Nếu mã của bạn có cơ hội được viết lại thành đệ quy đuôi, trình biên dịch có thể nhận diện dạng này và hoàn tất việc viết lại.

<a id="loại-bỏ-đệ-quy-đuôi-rpass-tailcallelim"></a>
#### Loại bỏ đệ quy đuôi -Rpass=tailcallelim

Khi hàm đã là đệ quy đuôi, có thể xóa trực tiếp câu lệnh đệ quy và, thông qua một số phân tích tĩnh, biến hàm thành dạng không đệ quy. Ở đây ta không đi sâu vào cách tác giả trình biên dịch làm được điều này. Từ trải nghiệm thực tế, phần lớn mã OI nếu có cả phiên bản đệ quy và không đệ quy thì thường có thể được tự động tối ưu thành phiên bản không đệ quy. Dưới đây là một số ví dụ cụ thể cho độc giả:

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
    // Mở thành vòng lặp scalar, rồi thực hiện auto-vectorization; mã sinh ra là SIMD
    unsigned fac(unsigned n) {
      if (n < 2) return 1;
      return n * fac(n - 1);
    }
    ```

Hợp ngữ sau tối ưu hóa của các hàm này hoàn toàn giống phiên bản không đệ quy; đệ quy sẽ bị loại bỏ trực tiếp. Với thí sinh OI, khi bật O2 có thể yên tâm viết các thuật toán dạng đệ quy, vì sẽ không khác dạng không đệ quy. Nếu hàm bạn viết về bản chất không thể được viết lại thành dạng không đệ quy, trình biên dịch cũng bó tay.

<a id="giảm-độ-mạnh-phép-toán-strength-reduction"></a>
### Giảm độ mạnh phép toán (Strength Reduction)

Đây là một tối ưu hóa biên dịch phổ biến. Ví dụ đơn giản nhất là biến `x * 2` thành `x << 1`; cách viết thứ hai rất thường gặp trong OI. Trình biên dịch sẽ tự động làm các tối ưu hóa tương tự; khi bật tùy chọn tối ưu hóa, `x * 2` và `x << 1` hoàn toàn tương đương. Strength Reduction biến các lệnh chi phí cao thành các lệnh chi phí thấp.

<a id="biến-đổi-toán-tử-scalar"></a>
#### Biến đổi toán tử scalar

<a id="dùng-dịch-bit-thay-cho-phép-nhân"></a>
##### Dùng dịch bit thay cho phép nhân

```cpp
int a;
a = x * 2;   // bad!
a = x << 1;  // good!
```

Cần lưu ý rằng số có dấu và số không dấu có khác biệt rõ rệt ở cấp độ dịch bit (shifting) và nâng kiểu (promotion). Bit dấu được xử lý đặc biệt khi dịch, gồm hai loại là dịch số học và dịch logic. Điều này thể hiện rõ khi viết tìm kiếm nhị phân, cây đoạn, và các cấu trúc có nhiều phép chia đôi: phép chia số nguyên có dấu không thể được tối ưu trực tiếp thành một lệnh dịch phải duy nhất.

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
int sign = mid >> 31; /* dịch phải logic, lấy bit dấu */
mid += sign;
mid >>= 1; /* dịch phải số học */
```

Các cách giải quyết khả thi:

-   Dùng `unsigned l, r;`, chỉ số vốn nên là số không dấu
-   Dùng dịch bit ngay trong mã nguồn

<a id="dùng-phép-nhân-thay-cho-phép-chia"></a>
##### Dùng phép nhân thay cho phép chia

```cpp
int x = a / 3;
```

Quá trình này có thể được biến đổi thành `x = a * 0x55555556 >> 32`; chi tiết có thể xem [bài trả lời Zhihu này](https://zhuanlan.zhihu.com/p/151038723) hoặc [bài báo gốc](https://dl.acm.org/doi/10.1145/773473.178249).

<a id="giảm-độ-mạnh-cho-biến-chỉ-số-indvars"></a>
#### Giảm độ mạnh cho biến chỉ số (IndVars)

Trình biên dịch tự động nhận diện các biến chỉ số trong vòng lặp và biến các quá trình liên quan có chi phí cao thành quá trình chi phí thấp.

```cpp
int a = 0;
for (int i = 1; i < 10; i++) {
  a = 3 * i;  // bad!
  a = a + 3;  // good!
}
```

Ở đây việc viết trực tiếp `a = 3 * i` rất thường gặp trong OI, nhưng trình biên dịch có thể tự động phân tích được phép biến đổi tương đương `a = a + 3`, dùng phép cộng rẻ hơn thay cho phép nhân. Phân tích quá trình lặp của biến vòng lặp được gọi là SCEV (Scalar Evolution).

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

Hàm này sẽ được tối ưu thành công thức tính tổng $O(1)$, tham khảo <https://godbolt.org/z/ET8d89vvK>. Hành vi này hiện chỉ xuất hiện ở các trình biên dịch dựa trên LLVM; GCC bảo thủ hơn.

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
### Tự động vector hóa (Auto-Vectorization)

Một luồng lệnh đơn trên nhiều luồng dữ liệu là cách tốt để cung cấp song song hóa trong một nhân. Dùng các lệnh này có thể tận dụng thanh ghi SIMD của CPU, vốn rộng hơn thanh ghi đa dụng; ví dụ, mỗi lần đặt 4 số nguyên vào rồi tính toán. Thí sinh OI không cần hiểu chi tiết về auto-vectorization. Thông thường, trình biên dịch Clang sẽ auto-vectorize mạnh tay hơn GCC:

```cpp
// https://godbolt.org/z/h1hx5sWoE
void test(int *a, int *b, int n) {
  for (int i = 0; i < n; i++) {
    a[i] += b[i];
  }
}
```

#### `__restrict` type specifier (GNU, MSVC)

Hai vùng nhớ tương ứng với hai con trỏ bất kỳ có thể bị chồng lấp (overlap), khi đó cần xử lý riêng xem có thể dùng mã vector hay không. Hình dưới đây minh họa một ví dụ về chồng lấp con trỏ:

![](./images/overlap.png)

`__restrict` là một quy ước giúp trình biên dịch giả định rằng hai vùng nhớ mà hai con trỏ trỏ tới sẽ không bao giờ chồng lấp.

```cpp
void test(int* __restrict a, int* __restrict b, int n) {
  for (int i = 0; i < n; i++) {
    a[i] += b[i];
  }
}
```

`__restrict` không phải một phần của chuẩn C++, nhưng các trình biên dịch lớn đều hỗ trợ. Từ khóa này ảnh hưởng đến chất lượng sinh mã của auto-vectorization; có thể dùng trong các trường hợp cần tối ưu hằng số rất gắt.

<a id="các-cách-dùng-ngôn-ngữ-sai-thường-gặp-liên-quan-đến-tối-ưu-hóa-biên-dịch"></a>
## Các cách dùng ngôn ngữ sai thường gặp liên quan đến tối ưu hóa biên dịch

<a id="inline---nội-tuyến"></a>
### inline - nội tuyến

Nội tuyến hàm khi bật O2 thường do trình biên dịch tự động hoàn thành. `inline` trong định nghĩa struct hoàn toàn thừa; nếu cuộc thi bật tối ưu hóa O2 thì không cần khai báo nội tuyến. Nếu không bật O2, dùng `inline` cũng không làm trình biên dịch thật sự nội tuyến.

Trong C++ hiện đại, từ khóa `inline` được xem là một hành vi ngữ nghĩa về liên kết và xuất ký hiệu, chứ không phải để thực hiện nội tuyến hàm.

<a id="register---gợi-ý-thanh-ghi-không-còn-thực-chất"></a>
### register - gợi ý thanh ghi không còn thực chất

Trình biên dịch hiện đại sẽ bỏ qua trực tiếp từ khóa `register`; cách phân bổ thanh ghi bạn tự nghĩ ra thường không thông minh bằng việc để trình biên dịch chạy thuật toán phân bổ thanh ghi. Từ khóa này bị deprecated từ C++11 và bị xóa từ C++17[^p0001r1].

<https://en.cppreference.com/w/cpp/keyword/register>

<a id="hành-vi-không-xác-định-undefined-behavior-và-tối-ưu-hóa-biên-dịch"></a>
## Hành vi không xác định (Undefined Behavior) và tối ưu hóa biên dịch

Trình biên dịch có thể coi chương trình C++ là không tồn tại [hành vi không xác định](https://en.cppreference.com/w/cpp/language/ub) (undefined behavior, UB). Vì vậy, khi biên dịch một chương trình có UB, trình biên dịch có thể tạo ra kết quả ngoài dự kiến. Đồng thời, trình biên dịch cũng có thể dựa trên giả định không có UB để thực hiện tối ưu hóa tự do và mạnh tay hơn.

Các UB thường gặp gồm:

1.  [Tràn số có dấu](https://users.cs.utah.edu/~regehr/papers/overflow12.pdf);
2.  Dùng biến chưa khởi tạo;
3.  Truy cập vượt biên;
4.  Giải tham chiếu con trỏ null;
5.  Vòng lặp vô hạn không có tác dụng phụ.

Các UB khác và ví dụ có thể xem chi tiết trong phần đọc thêm.

<a id="tràn-số-có-dấu"></a>
### Tràn số có dấu

```cpp
int f(int x) { return x * 2 / 2; }
```

Trình biên dịch có thể giả định chương trình không có hành vi tràn số có dấu, nên hàm này có thể được tối ưu thành

```cpp
int f(int x) { return x; }
```

Ví dụ: <https://godbolt.org/z/WKv3W5hvM>, <https://godbolt.org/z/qqE9nxP1j>.

Có thể dùng tùy chọn [`-fwrapv`](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Code-Gen-Options.html#index-fwrapv) để tắt giả định này. Ví dụ: <https://godbolt.org/z/5x3K5KGnr>, <https://godbolt.org/z/4r4a4EzMW>.

<a id="dùng-biến-chưa-khởi-tạo"></a>
### Dùng biến chưa khởi tạo

```cpp
int f(int x) {
  int a;
  if (x)  // either x nonzero or UB
    a = 42;
  return a;
}
```

Trình biên dịch có thể giả định chương trình không có hành vi dùng biến chưa khởi tạo, nên `a` chắc chắn được khởi tạo, và hàm này có thể được tối ưu thành

```cpp
int f(int) { return 42; }
```

Ví dụ: <https://godbolt.org/z/8WYMYYjdG>, <https://godbolt.org/z/qvGd1nvv9>.

<a id="truy-cập-vượt-biên"></a>
### Truy cập vượt biên

```cpp
int table[4] = {};

bool exists_in_table(int v) {
  // return true in one of the first 4 iterations or UB due to out-of-bounds
  // access
  for (int i = 0; i <= 4; i++)
    if (table[i] == v) return true;
  return false;
}
```

Trình biên dịch có thể giả định chương trình không có truy cập vượt biên, nên hàm này chắc chắn sẽ trả về trước khi truy cập vượt biên xảy ra, và do đó có thể được tối ưu thành

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
    return x;  // Either UB above or this branch is never taken
  else
    return 0;
}
```

Trình biên dịch có thể giả định chương trình không có hành vi giải tham chiếu con trỏ null, nên `!p` luôn là `false`, và hàm này có thể được tối ưu thành

```cpp
int f(int*) { return 0; }
```

Ví dụ: <https://godbolt.org/z/GY1jvsrb5>, <https://godbolt.org/z/4ronPsnxf>.

<a id="vòng-lặp-vô-hạn-không-có-tác-dụng-phụ"></a>
### Vòng lặp vô hạn không có tác dụng phụ

???+ note "Kiểm chứng Định lý lớn Fermat"
    Theo [Định lý lớn Fermat](https://en.wikipedia.org/wiki/Fermat%27s_Last_Theorem), phương trình vô định $a^3=b^3+c^3$ không có nghiệm nguyên dương. Chương trình dưới đây thử liệt kê các số nguyên trong $[1,1000]$ để kiểm chứng phương trình này có đúng hay không; nếu trả về `true` thì nghĩa là đã tìm thấy một bộ nghiệm nguyên trong phạm vi $[1,1000]$, từ đó Định lý lớn Fermat không đúng.

    ```cpp
    #include <iostream>

    bool fermat() {
      const int max_value = 1000;

      // Endless loop with no side effects is UB
      for (int a = 1, b = 1, c = 1; true;) {
        if (((a * a * a) == ((b * b * b) + (c * c * c))))
          return true;  // disproved :(
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

      return false;  // not disproved
    }

    int main() {
      std::cout << "Fermat's Last Theorem ";
      fermat() ? std::cout << "has been disproved!\n"
               : std::cout << "has not been disproved.\n";
    }
    ```

Trình biên dịch có thể giả định chương trình không có vòng lặp vô hạn không tác dụng phụ, nên nó cho rằng vòng `for` trong hàm `fermat()` chắc chắn sẽ kết thúc tại một thời điểm nào đó và trả về `true`. Cuối cùng chương trình có thể in ra:

```text
Fermat's Last Theorem has been disproved!
```

Ví dụ: <https://godbolt.org/z/d834MK7bz>, <https://godbolt.org/z/Eov9nsKqf>.

## Sanitizer

Sanitizer là công cụ bảo vệ tính đúng đắn: nó kiểm tra lúc chạy xem chương trình của bạn có hành vi không xác định, vượt biên mảng, con trỏ null, và các lỗi tương tự hay không.
Ở chế độ debug cục bộ, nên bật một số sanitizer; chúng có thể rút ngắn đáng kể thời gian Debug. Các sanitizer này do Google phát triển, phần lớn có thể dùng với GCC và Clang. Sanitizer trong LLVM trưởng thành hơn, vì vậy nên dùng trình biên dịch Clang để debug các vấn đề liên quan trên máy cá nhân.

### Address Sanitizer -fsanitize=address

<https://clang.llvm.org/docs/AddressSanitizer.html>

Cả GCC và Clang đều hỗ trợ sanitizer này. Nó bao gồm các mục kiểm tra sau:

-   Vượt biên
-   Dùng sau khi giải phóng (use-after-free)
-   Dùng sau khi trả về (use-after-return)
-   Giải phóng lặp lại (double-free)
-   Rò rỉ bộ nhớ (memory-leaks)
-   Dùng sau khi rời khỏi phạm vi (use-after-scope)

Áp dụng kiểm tra này sẽ làm chương trình chậm khoảng 2x.

### Undefined Behavior Sanitizer -fsanitize=undefined

<https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html>

Undefined Behavior Sanitizer (a.k.a UBSan) dùng để kiểm tra hành vi không xác định trong mã. Cả GCC và Clang đều hỗ trợ sanitizer này. Nó tự động kiểm tra chương trình của bạn có UB hay không. Các mục kiểm tra của UBSan gồm:

-   Tràn phép dịch bit, ví dụ dịch trái một số nguyên 32 bit thêm 72 bit
-   Tràn số nguyên có dấu
-   Tràn dữ liệu khi chuyển đổi số thực dấu chấm động sang số nguyên

Các mục kiểm tra của UBSan có thể tùy chọn; ảnh hưởng đến chương trình có thể tham khảo trang tài liệu đã dẫn.

<a id="linh-tinh"></a>
## Linh tinh

### Compiler Explorer

Quan sát hành vi và mã hợp ngữ của các trình biên dịch tại đây: <https://godbolt.org>

<a id="đọc-thêm"></a>
## Đọc thêm

1.  [The LLVM Project Blog: What Every C Programmer Should Know About Undefined Behavior #1/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know.html)
2.  [The LLVM Project Blog: What Every C Programmer Should Know About Undefined Behavior #2/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know_14.html)
3.  [The LLVM Project Blog: What Every C Programmer Should Know About Undefined Behavior #3/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know_21.html)

<a id="tài-liệu-tham-khảo-và-chú-thích"></a>
## Tài liệu tham khảo và chú thích

[^p0001r1]: [Remove Deprecated Use of the register Keyword (open-std.org)](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0001r1.html)
