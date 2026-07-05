Bài viết này giới thiệu khác biệt giữa C++ và các ngôn ngữ thường dùng khác,
tập trung vào những khác biệt quan trọng hoặc dễ bị bỏ qua giữa C và C++. Dù C++
thường được xem là khá gần với C, không phải mọi mã C đều giữ nguyên ý nghĩa khi
biên dịch bằng C++. Hiểu các khác biệt quan trọng giữa C/C++ có thể giúp tránh
một số lỗi khó hiểu. Với OIer đang dùng C làm ngôn ngữ chính, bài viết này
cũng giúp việc chuyển sang C++ thuận lợi hơn. Các tính năng riêng mà C++ bổ sung
so với C có thể đọc trong phần hướng dẫn [C++ nâng cao](./class.md). Ngoài ra,
bài viết cũng giới thiệu ngắn gọn khác biệt giữa Python, Java và C++.

## Khác biệt giữa C và C++

<span id="macro-và-template"></span>

### Macro và template

Một trong các mục đích ban đầu khi thiết kế template của C++ là thay thế một phần
cách dùng macro. Học lập trình template là một bước quan trọng khi chuyển từ C
sang C++. Khác với việc thay thế văn bản của macro, template được trình biên dịch
kiểm tra kiểu toàn diện hơn trong lúc biên dịch, giúp viết mã vững chắc hơn. Sau
C++11, template hỗ trợ danh sách tham số có độ dài biến đổi, có thể dùng để thay
thế nhiều trường hợp hàm tham số biến thiên trong C và bảo đảm an toàn kiểu.

### Con trỏ và tham chiếu

Trong C++, vẫn có thể dùng con trỏ kiểu C; tuy nhiên khi truyền biến, thường nên
dùng [tham chiếu](./reference.md) của C++ để thực hiện chức năng tương tự. Vì
tham chiếu phải ràng buộc với một đối tượng hợp lệ, nó có thể tránh một số vấn
đề do truy cập con trỏ rỗng. Tuy vậy, con trỏ vẫn có chỗ dùng nhờ tính linh hoạt
của nó. Đáng nói là từ C++11, con trỏ rỗng `NULL` trong C có phương án thay thế
an toàn kiểu là `nullptr`. Có thể lấy địa chỉ bằng toán tử `&`, rồi giải tham
chiếu con trỏ bằng toán tử `*`.

### Kiểu `bool`

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

Từ C23, `true`, `false` và `bool` trở thành từ khóa trong ngôn ngữ C; dùng chúng
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

Dù C và C++ đều có khái niệm `struct`, không nên xem hai khái niệm này là hoàn
toàn giống nhau. `struct` trong C dùng để mô tả một cấu trúc tổ chức bộ nhớ cố
định, còn `struct` trong C++ chính là một loại lớp. **Khác biệt mặc định giữa
`struct` và `class` trong C++ là quyền truy cập thành viên và quyền kế thừa mặc
định của `struct` là `public`**, còn mặc định của `class` là `private`. Điểm này
đặc biệt dễ gây lỗi khi viết mã trộn C/C++.

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

Trong C, `const` chủ yếu dùng để giới hạn việc sửa đổi một đối tượng thông qua
tên hoặc lối truy cập đó. Còn trong C++, do có thêm nhiều tính năng ngôn ngữ,
`const` cũng có nhiều cách dùng hơn. Nếu cần hằng số có thể dùng ở thời điểm
biên dịch, C++ thường dùng `constexpr`; còn cách dùng `const` trong C++ được
giải thích ở trang [hằng](./const.md).

### Cấp phát bộ nhớ

C++ thêm từ khóa `new` và `delete` để cấp phát đối tượng trong vùng lưu trữ động
(dynamic storage). Cơ chế này phối hợp với hệ thống lớp của C++: `new` gọi hàm
tạo, `delete` gọi hàm hủy, còn `delete[]` dùng để giải phóng mảng động đã cấp
phát bằng `new[]`. So với các hàm `malloc()`, `realloc()`, `free()` trong C,
`new`/`delete` gắn với kiểu đối tượng rõ hơn và xử lý vòng đời đối tượng đúng
hơn.

Nói ngắn gọn, nếu chỉ cần một vùng nhớ thô, `malloc()` vẫn có thể dùng được.
Nhưng nếu đối tượng cần cấp phát có hàm tạo, hàm hủy hoặc yêu cầu quản lý vòng
đời kiểu C++, nên dùng `new` hoặc các công cụ thư viện chuẩn thích hợp. Cần chú ý
rằng dù `new` và `malloc()` đều trả về con trỏ, con trỏ sinh bởi `new` **chỉ** có
thể thu hồi bằng `delete`, còn con trỏ sinh bởi `malloc()` cũng chỉ có thể thu
hồi bằng `free()`; dùng lẫn hai cơ chế này sẽ gây hành vi không xác định hoặc rò
rỉ bộ nhớ.

### Khai báo biến

Trước C99, khai báo biến trong C phải nằm ở đầu khối lệnh; C++ và C sau C99
không có giới hạn này.

### Mảng độ dài biến đổi

C99 yêu cầu hỗ trợ VLA (mảng độ dài biến đổi); từ C11, VLA trở thành tính năng
tùy chọn. C++ chuẩn không hỗ trợ VLA, dù một số trình biên dịch có cung cấp dưới
dạng phần mở rộng.

### Khởi tạo cấu trúc

Sau C99, ngôn ngữ C hỗ trợ
[khởi tạo có chỉ định](https://en.cppreference.com/w/c/language/struct_initialization)
cho cấu trúc (nhưng trong C11 đây là tính năng tùy chọn). C++ đến C++20 mới hỗ
trợ khởi tạo có chỉ định theo thứ tự khai báo; các cách viết C hỗ trợ như chỉ định
sai thứ tự, chỉ định lồng nhau, trộn với bộ khởi tạo thông thường, hoặc chỉ định
phần tử mảng đều không được C++ hỗ trợ[^cpp-designated-init].

### Cú pháp chú thích

Chú thích một dòng kiểu C++ `//` không được C hỗ trợ trước C99.

## Khác biệt giữa Python và C++

Python được dùng rất rộng rãi trong học máy. So với C++, ưu điểm của Python là
dễ học và dễ thực hành. Python có cú pháp đơn giản, trực tiếp hơn; chẳng hạn khi
định nghĩa biến, thường không cần khai báo trước kiểu của biến. Tuy nhiên sự đơn
giản này cũng có cái giá của nó: Python thường có hiệu năng thấp hơn C++. C++ gần
như áp dụng được trên mọi nền tảng, bao gồm cả hệ thống nhúng, và có tốc độ thực
thi nhanh hơn. C++ cũng gần với phần cứng và hệ thống hơn, nên có thể dùng để
viết hệ điều hành.

## Khác biệt giữa Java và C++

Java và C++ đều là ngôn ngữ hướng đối tượng và đều dùng các tư tưởng hướng đối
tượng như đóng gói, kế thừa, đa hình. Vì hướng đối tượng có nhiều tính chất hữu
ích, như kế thừa và kết hợp, cả hai đều hỗ trợ tái sử dụng mã tốt. Vì vậy, so
với Python, Java và C++ giống nhau hơn.

Khác biệt lớn nhất giữa hai ngôn ngữ nằm ở cơ chế JVM của Java. JVM là viết tắt
của Java Virtual Machine, tức máy ảo Java. Một tính chất rất quan trọng của Java
là tính độc lập với nền tảng. Máy ảo Java là mấu chốt để đạt được tính chất này.
Nếu muốn chạy trên các nền tảng khác nhau, ngôn ngữ bậc cao thông thường ít nhất
cần biên dịch thành các mã máy khác nhau. Với Java, trình biên dịch sinh bytecode
chạy trên JVM; JVM che giấu nhiều khác biệt nền tảng cụ thể, nhờ đó cùng một
chương trình Java có thể chạy trên nhiều nền tảng mà không cần sửa mã nguồn.

Vì đặc điểm này, Java thường được dùng để phát triển các chương trình cần chuyển
sang nhiều nền tảng khác nhau. Nhưng vì quá trình thực thi thường đi qua tầng JVM
và bytecode, hiệu năng của Java trong thi đấu thường khó đạt mức của C++.

## Tài liệu tham khảo

[^cpp-designated-init]: <https://en.cppreference.com/w/cpp/language/aggregate_initialization>

[^boolean-keyword]: <https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3054.pdf>.

[^reserved-identifiers]: C và C++ đều quy định rằng định danh bắt đầu bằng một
    dấu gạch dưới theo sau là một chữ cái in hoa là định danh được giữ riêng; xem
    chi tiết tại <https://en.cppreference.com/w/c/language/identifier>.
