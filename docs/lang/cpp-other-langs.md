Bài viết này giới thiệu khác biệt giữa C++ và các ngôn ngữ thường dùng khác,
tập trung vào những khác biệt quan trọng hoặc dễ bị bỏ qua giữa C và C++. Dù C++
gần như là một siêu tập của C, và trộn mã C/C++ nhìn chung cũng không có vấn đề
lớn, hiểu các khác biệt quan trọng giữa C/C++ có thể giúp tránh một số bug kỳ
lạ. Nếu bạn là OIer dùng C làm ngôn ngữ chính, bài viết này cũng giúp bạn chuyển
sang C++ thuận lợi hơn. Các đặc tính riêng mà C++ bổ sung so với C có thể đọc
trong phần hướng dẫn [C++ nâng cao](./class.md). Ngoài ra, bài viết cũng giới
thiệu ngắn gọn khác biệt giữa Python, Java và C++.

## Khác biệt giữa C và C++

<span id="macro-và-template"></span>

### Macro và mẫu

Một trong các mục đích ban đầu khi thiết kế mẫu của C++ là thay thế định
nghĩa macro. Học lập trình mẫu là một bước quan trọng khi chuyển từ C sang
C++. Khác với việc thay thế văn bản của macro, mẫu nhận được kiểm tra trình
biên dịch toàn diện hơn trong lúc biên dịch, giúp viết mã vững chắc hơn. Sau
C++11, mẫu hỗ trợ danh sách tham số mẫu có độ dài biến đổi, có thể
dùng để thay thế hàm tham số biến thiên trong C và bảo đảm an toàn kiểu.

### Con trỏ và tham chiếu

Trong C++, bạn vẫn có thể dùng con trỏ kiểu C, nhưng với việc truyền biến, nên
dùng đặc tính [tham chiếu](./reference.md) của C++ để thực hiện chức năng tương
tự. Vì đối tượng mà tham chiếu trỏ tới không thể rỗng, tham chiếu có thể tránh
một số vấn đề truy cập địa chỉ rỗng. Tuy vậy, con trỏ vẫn có chỗ dùng nhờ tính
linh hoạt của nó. Đáng nói là từ C++11, con trỏ rỗng `NULL` trong C có phương án
thay thế an toàn kiểu là `nullptr`. Tham chiếu và con trỏ có thể chuyển đổi qua
lại bằng [toán tử `*` và `&`](./op.md).

### bool

Xem thêm [kiểu luận lý](var.md#kiểu-luận-lý).

Khác với C++, ban đầu ngôn ngữ C không có kiểu luận lý.

Chuẩn C99 thêm từ khóa `_Bool`, macro tương đương `bool`, cùng hai macro `true`
và `false`. Nếu cần dùng ba macro `bool`, `true`, `false`, chương trình cần
nạp tệp tiêu đề `stdbool.h`. Còn nếu dùng `_Bool` thì không cần nạp tệp tiêu đề
bổ sung nào.

```c
bool x = true;  // cần include stdbool.h
_Bool x = 1;    // không cần include stdbool.h
```

Từ C23, `true`,`false` và `bool` trở thành từ khóa trong ngôn ngữ C; dùng chúng
không cần nạp tệp tiêu đề `stdbool.h` nữa, đồng thời vẫn giữ `_Bool` làm cách
viết thay thế cho `bool`[^boolean-keyword].

Bảng dưới đây cho thấy sự thay đổi về hỗ trợ kiểu `bool` trong các chuẩn C khác
nhau, kèm C++ để đối chiếu:

| Chuẩn ngôn ngữ | `bool` | `true`/`false` | `_Bool` |
| -------------- | ------ | -------------- | ------- |
| C89 | / | / | được giữ riêng[^reserved-identifiers] |
| Từ C99 đến trước C23 | macro, tương đương `_Bool`, cần tệp tiêu đề `stdbool.h` | macro, `true` tương đương `1`, `false` tương đương `0`, cần tệp tiêu đề `stdbool.h` | từ khóa |
| Từ C23 | từ khóa | từ khóa | cách viết thay thế của từ khóa `bool` |
| C++ | từ khóa | từ khóa | được giữ riêng[^reserved-identifiers] |

### struct

Dù C và C++ đều có khái niệm `struct`, những thứ chúng tương ứng không thể dùng
lẫn lộn! `struct` trong C dùng để mô tả một cấu trúc tổ chức bộ nhớ cố định, còn
`struct` trong C++ chính là một loại lớp. **Khác biệt duy nhất giữa nó và lớp là
thành viên và hành vi kế thừa mặc định là public**, còn thành viên mặc định của
lớp thông thường là private. Điểm này đặc biệt dễ gây lỗi khi viết mã trộn C/C++.

Ngoài ra, khi khai báo `struct`, C++ cũng không cần rườm rà như C. Phiên bản C:

```c
typedef struct Node_t {
  struct Node_t *next;
  int key;
} Node;
```

Phiên bản C++:

```cpp
struct Node {
  Node *next;
  int key;
};
```

### const

Trong C, `const` chỉ có chức năng giới hạn biến không thể bị sửa. Còn trong C++,
do có nhiều đặc tính mới xuất hiện, `const` cũng được trao thêm nhiều cách dùng.
Kế nhiệm của `const` trong C ở C++ là `constexpr`, còn cách dùng `const` trong
C++ xem giải thích ở trang [hằng](./const.md).

### Cấp phát bộ nhớ

C++ thêm từ khóa `new` và `delete` để cấp phát không gian trên "free store". Free
store này có thể là heap hoặc vùng lưu trữ tĩnh; chúng xuất hiện để phối hợp với
"lớp". Trong đó `delete[]` còn có thể trực tiếp giải phóng bộ nhớ của mảng động,
rất tiện lợi. Từ khóa `new` và `delete` sẽ gọi hàm tạo và hàm hủy của kiểu; so
với các hàm `malloc()`, `realloc()`, `free()` trong C, chúng hỗ trợ kiểu đầy đủ
hơn, nhưng hiệu suất không bằng các hàm của C.

Nói ngắn gọn, nếu đối tượng cần cấp phát động là kiểu cơ bản hoặc mảng của chúng,
bạn có thể dùng `malloc()` để cấp phát bộ nhớ hiệu quả hơn. Nhưng nếu đối tượng
mới là kiểu không cơ bản, nên dùng `new` để có kiểm tra an toàn. Cần chú ý rằng
dù `new` và `malloc()` đều trả về con trỏ, con trỏ sinh bởi `new` **chỉ** có thể
thu hồi bằng `delete`, còn con trỏ sinh bởi `malloc()` cũng chỉ có thể thu hồi
bằng `free()`, nếu không sẽ có nguy cơ rò rỉ bộ nhớ.

### Khai báo biến

Trước C99, khai báo biến trong C phải nằm ở đầu khối lệnh; C++ và C sau C99
không có giới hạn này.

### Mảng độ dài biến đổi

Sau C99, ngôn ngữ C hỗ trợ VLA (mảng độ dài biến đổi), còn C++ luôn không hỗ trợ.

### Khởi tạo cấu trúc

Sau C99, ngôn ngữ C hỗ trợ [khởi tạo bằng designator](https://en.cppreference.com/w/c/language/struct_initialization)
cho cấu trúc (nhưng trong C11 đây là đặc tính tùy chọn). C++ đến C++20 mới hỗ trợ
khởi tạo bằng designator có yêu cầu về thứ tự, và các đặc tính C hỗ trợ như sai
thứ tự, lồng nhau, trộn với initializer thông thường, hoặc designator cho mảng
đều không được C++ hỗ trợ[^cpp-designated-init].

### Cú pháp chú thích

Chú thích một dòng kiểu C++ `//` không được C hỗ trợ trước C99.

## Khác biệt giữa Python và C++

Python hiện là ngôn ngữ được dùng phổ biến nhất trong giới học máy. So với C++,
ưu điểm của Python là dễ học và dễ thực hành. Python có cú pháp đơn giản, trực
tiếp hơn; chẳng hạn khi định nghĩa biến, không cần khai báo trước kiểu của biến.
Tuy nhiên sự đơn giản này cũng có cái giá của nó. Python hy sinh hiệu năng so
với C++. C++ gần như áp dụng được trên mọi nền tảng, bao gồm cả hệ thống nhúng,
và có tốc độ thực thi nhanh hơn, còn Python chỉ có thể dùng trên một số nền tảng
hỗ trợ ngôn ngữ bậc cao. C++ gần với tầng thấp hơn, nên có thể dùng để viết hệ
điều hành.

## Khác biệt giữa Java và C++

Java và C++ đều là ngôn ngữ hướng đối tượng và đều dùng tư tưởng hướng đối tượng
(đóng gói, kế thừa, đa hình). Vì hướng đối tượng có nhiều đặc tính rất tốt, như
kế thừa và kết hợp, cả hai đều có khả năng tái sử dụng tốt. Vì vậy, so với
Python, Java và C++ giống nhau hơn.

Khác biệt lớn nhất giữa hai ngôn ngữ nằm ở cơ chế JVM của Java. JVM là viết tắt
của Java Virtual Machine, tức máy ảo Java. Một đặc điểm rất quan trọng của ngôn
ngữ Java là tính độc lập với nền tảng. Sử dụng máy ảo Java là mấu chốt để thực
hiện đặc điểm này. Nếu muốn chạy trên các nền tảng khác nhau, ngôn ngữ bậc cao
thông thường ít nhất cần biên dịch thành các mã đích khác nhau. Sau khi đưa máy
ảo ngôn ngữ Java vào, Java không cần biên dịch lại khi chạy trên các nền tảng
khác nhau. Java dùng máy ảo Java để che giấu thông tin liên quan đến nền tảng cụ
thể, khiến trình biên dịch Java chỉ cần sinh mã đích (bytecode) chạy trên máy ảo
Java là có thể chạy trên nhiều nền tảng mà không cần sửa đổi.

Vì đặc điểm này, Java thường được dùng để phát triển các chương trình cần chuyển
sang nhiều nền tảng khác nhau. Nhưng cũng vì khi biên dịch chương trình Java cần
bắt đầu từ bytecode, hiệu năng của Java không tốt bằng C++.

## Tài liệu tham khảo

[^cpp-designated-init]: <https://en.cppreference.com/w/cpp/language/aggregate_initialization>

[^boolean-keyword]: <https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3054.pdf>.

[^reserved-identifiers]: C và C++ đều quy định rằng định danh bắt đầu bằng một dấu gạch dưới theo sau là một chữ cái in hoa là định danh được giữ riêng; xem chi tiết tại <https://en.cppreference.com/w/c/language/identifier>.
