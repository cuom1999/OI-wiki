**Liên hiệp** (`union`) là một loại lớp đặc biệt; tại một thời điểm nó chỉ có
một thành viên dữ liệu không tĩnh đang hoạt động.

Liên hiệp chính thức được thêm vào đề cương NOI cấp nhập môn từ năm 2023.

## Định nghĩa liên hiệp

Bộ chỉ định lớp trong khai báo liên hiệp tương tự khai báo lớp hoặc
[cấu trúc](./struct.md):

```cpp
union MyUnion {
  int x;
  long long y;
} u;
```

Cách định nghĩa liên hiệp tương tự cấu trúc. Theo định nghĩa trên, `MyUnion`
có thể được dùng như một kiểu tự định nghĩa, còn `u` là một biến có kiểu
`MyUnion`. Có thể bỏ qua tên `MyUnion` nếu không cần dùng lại kiểu này.

## Truy cập/sửa thành viên

Tương tự cấu trúc, cũng có thể dùng `tên_biến.tên_thành_viên` để truy cập.

Kích thước vùng nhớ mà liên hiệp chiếm **không nhỏ hơn** kích thước thành viên
lớn nhất của nó; mọi thành viên **dùng chung vùng nhớ và địa chỉ**. Khi một
thành viên được gán giá trị, thành viên đó trở thành thành viên đang hoạt động.
Do bộ nhớ được chia sẻ, giá trị của các thành viên khác không còn được bảo toàn.
Nói cách khác, tại cùng một thời điểm, chỉ nên xem giá trị của thành viên đang
hoạt động là hợp lệ.

Xem thêm các cách dùng liên hiệp tại
[cppreference: khai báo union](https://en.cppreference.com/w/cpp/language/union).
