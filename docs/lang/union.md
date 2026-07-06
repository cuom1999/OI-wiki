**Liên hiệp** (`union`) là một loại lớp đặc biệt; tại mỗi thời điểm, chỉ một thành
viên dữ liệu không tĩnh của nó được xem là đang hoạt động.

Liên hiệp chính thức được thêm vào đề cương NOI cấp nhập môn từ năm 2023.

## Định nghĩa liên hiệp

Phần khai báo liên hiệp có cú pháp tương tự khai báo lớp hoặc [cấu trúc](./struct.md):

```cpp
union MyUnion {
  int x;
  long long y;
} u;
```

Cách định nghĩa liên hiệp tương tự cấu trúc. Theo định nghĩa trên, `MyUnion` có
thể được dùng như một kiểu tự định nghĩa, còn `u` là một biến có kiểu `MyUnion`.
Nếu không cần dùng lại kiểu này, có thể bỏ qua tên `MyUnion`.

## Truy cập/sửa thành viên

Tương tự cấu trúc, có thể dùng `tên_biến.tên_thành_viên` để truy cập thành viên.

Kích thước vùng nhớ mà liên hiệp chiếm **không nhỏ hơn** kích thước của thành viên
lớn nhất; mọi thành viên **dùng chung vùng nhớ và địa chỉ**. Khi một thành viên
được gán giá trị, thành viên đó trở thành thành viên đang hoạt động. Vì bộ nhớ
được chia sẻ, giá trị của các thành viên khác không còn được bảo toàn. Do đó, tại
cùng một thời điểm, chỉ nên xem giá trị của thành viên đang hoạt động là hợp lệ.

Xem thêm các cách dùng liên hiệp tại
[cppreference: khai báo union](https://en.cppreference.com/w/cpp/language/union).
