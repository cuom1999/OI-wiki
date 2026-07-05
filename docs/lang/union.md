**Liên hiệp** (`union`) là một loại lớp đặc biệt; tại một thời điểm nó chỉ có
thể lưu giữ một thành viên dữ liệu không tĩnh.

Liên hiệp chính thức được thêm vào đề cương NOI cấp nhập môn từ năm 2023.

## Định nghĩa liên hiệp

Bộ chỉ định lớp trong khai báo liên hiệp tương tự khai báo lớp hoặc
[cấu trúc](./struct.md):

```cpp
union MyUnion {
  int x;
  long long y;
} x;
```

Cách định nghĩa liên hiệp tương tự cấu trúc. Theo định nghĩa trên, `MyUnion`
cũng có thể được dùng như một kiểu tự định nghĩa. Tên `MyUnion` có thể được bỏ
qua.

## Truy cập/sửa phần tử thành viên

Tương tự cấu trúc, cũng có thể dùng `tên_biến.tên_thành_viên` để truy cập.

Kích thước vùng nhớ mà liên hiệp chiếm **không nhỏ hơn** kích thước thành viên
lớn nhất của nó; mọi thành viên **dùng chung vùng nhớ và địa chỉ**. Khi một
thành viên được gán giá trị, do bộ nhớ được chia sẻ, các thành viên khác trong
liên hiệp sẽ bị ghi đè. Nói cách khác, tại cùng một thời điểm, liên hiệp chỉ có
thể lưu giá trị của một thành viên.

Xem thêm các cách dùng liên hiệp tại
[cppreference: khai báo union](https://en.cppreference.com/w/cpp/language/union).
