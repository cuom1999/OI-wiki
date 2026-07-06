author: Ir1d, tsagaanbar, yang-lile

## Khai báo hàm

Trong lập trình, hàm thường là một tập hợp gồm nhiều câu lệnh. Nếu có một số
đoạn xử lý bị lặp lại, có thể tách chúng ra thành một hàm. Hàm có thể nhận dữ
liệu đầu vào và cũng có thể trả về một giá trị; đó là giá trị trả về của hàm.

Để khai báo một hàm, cần có kiểu giá trị trả về, tên hàm và danh sách tham số
hình thức.

```cpp
// kiểu giá trị trả về: int
// tên hàm: some_function
// danh sách tham số: int, int
int some_function(int, int);
```

Như trên, ta đã khai báo một hàm tên là `some_function`. Hàm này nhận hai tham
số kiểu `int`, và kiểu giá trị trả về cũng là `int`. Nói cách khác, hàm này sẽ
thực hiện một số thao tác trên hai số nguyên được truyền vào rồi trả về một kết
quả cùng kiểu.

## Định nghĩa hàm

Chỉ khai báo hàm là chưa đủ. Khai báo chỉ cho biết **giao diện** khi gọi hàm
(tức nhận dữ liệu gì, trả về dữ liệu gì), nhưng chưa có phần thân cụ thể, tức
**định nghĩa** của hàm. Có thể viết phần định nghĩa này ở **một nơi khác sau
phần khai báo**. Cũng có thể định nghĩa hàm trong tệp khác, nhưng khi liên kết
cần cung cấp cả các tệp đã được biên dịch riêng.

Nếu hàm có giá trị trả về, cần dùng câu lệnh `return` để trả giá trị cho nơi
gọi. Khi hàm thực thi đến câu lệnh `return`, hàm hiện tại sẽ kết thúc ngay và
không thực thi các câu lệnh phía sau.

```cpp
int some_function(int, int);  // khai báo

/* some other code here... */

int some_function(int x, int y) {  // định nghĩa
  int result = 2 * x + y;
  return result;
  result = 3;  // câu lệnh này sẽ không được thực thi
}
```

Khi định nghĩa, cần đặt tên cho các biến trong danh sách tham số của hàm. Nhờ
vậy, có thể dùng các biến này trong định nghĩa hàm.

Nếu ở cùng một tệp, cũng có thể **gộp khai báo và định nghĩa với nhau**; nói
cách khác, hoàn thành định nghĩa ngay tại nơi khai báo.

```cpp
int some_function(int x, int y) { return 2 * x + y; }
```

Nếu hàm không cần trả về giá trị, dùng `void` làm kiểu giá trị trả về của hàm;
nếu hàm không cần tham số, có thể để danh sách tham số trống. Tương tự, khi một
hàm không có giá trị trả về thực thi đến câu lệnh `return;`, nó cũng sẽ kết
thúc.

```cpp
#include <iostream>

void say_hello() {
  std::cout << "hello!\n";
  std::cout << "hello!\n";
  std::cout << "hello!\n";
  return;
  std::cout << "hello!\n";  // câu lệnh này sẽ không được thực thi
}
```

## Gọi hàm

Giống như biến, hàm cần được khai báo trước rồi mới có thể sử dụng. Thao tác sử
dụng hàm được gọi là "gọi hàm". Bên trong một hàm có thể gọi hàm khác, kể cả
chính nó. Hành vi một hàm gọi chính nó được gọi là **đệ quy**.

Trong hầu hết ngôn ngữ lập trình, cách gọi hàm là **tên hàm kèm một cặp ngoặc**
`()`; ví dụ `foo()`. Nếu hàm cần dữ liệu đầu vào, điền các **đối số** cần thiết
vào trong ngoặc theo thứ tự, phân tách bằng dấu phẩy, ví dụ `foo(1, 2)`. Lời
gọi hàm cũng là một biểu thức, và **giá trị trả về của hàm** chính là **giá trị
của biểu thức**.

Các tham số xuất hiện trong khai báo hoặc định nghĩa hàm đóng vai trò như những
biến có thể dùng **bên trong lần gọi hiện tại** của hàm. Giá trị của các biến
này được khởi tạo bằng đối số truyền vào từ nơi gọi. Xem ví dụ sau:

```cpp
void foo(int, int);

void foo(int x, int y) {
  x = x * 2;
  y = y + 3;
}

int main() {
  int a = 1;
  int b = 1;
  // trước khi gọi: a = 1, b = 1
  foo(a, b);  // gọi foo
              // sau khi gọi: a = 1, b = 1
}
```

Trong ví dụ trên, `foo(a, b)` là một lần gọi `foo`. Khi gọi, các biến `x` và
`y` trong `foo` lần lượt được khởi tạo bằng giá trị của `a` và `b` tại nơi gọi.
Vì vậy, việc sửa biến `x` và `y` trong `foo` **không ảnh hưởng đến giá trị của
biến tại nơi gọi**.

Nếu cần sửa giá trị của biến tại nơi gọi, có thể dùng cách "truyền tham
chiếu".

```cpp
void foo(int& x, int& y) {
  x = x * 2;
  y = y + 3;
}

int main() {
  int a = 1;
  int b = 1;
  // trước khi gọi: a = 1, b = 1
  foo(a, b);  // gọi foo
              // sau khi gọi: a = 2, b = 4
}
```

Trong đoạn mã trên, sau `int` trong danh sách tham số hàm có thêm dấu `&`. Điều
này biểu thị **tham chiếu** tới kiểu `int`. Khi gọi `foo`, các biến `a` và `b`
tại nơi gọi lần lượt dùng để khởi tạo hai tham chiếu kiểu `int` là `x` và `y`
trong `foo`. Khi đó, `x` và `y` trong `foo` là "bí danh" của các biến `a` và
`b` tại nơi gọi; thao tác lên `x` và `y` trong `foo` chính là thao tác lên `a`
và `b` tại nơi gọi.

## Hàm `main`

Đặc biệt, trong môi trường thi lập trình thông thường, mỗi chương trình C/C++
đều cần có một hàm tên là `main`. Chương trình bắt đầu chạy từ hàm `main`.

> Hàm `main` cũng có thể có tham số. Thông qua tham số của hàm `main`, chương
> trình có thể nhận các chỉ thị được truyền từ bên ngoài (tức "tham số dòng
> lệnh") để đưa ra phản ứng khác nhau.

Sau đây là một đoạn mã có gọi hàm:

```cpp
// hello_subroutine.cpp

#include <iostream>

void say_hello() {
  std::cout << "hello!\n";
  std::cout << "hello!\n";
  std::cout << "hello!\n";
}

int main() {
  say_hello();
  say_hello();
}
```
