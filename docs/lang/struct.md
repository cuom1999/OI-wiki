author: Ir1d, cjsoft, Lans1ot

**Cấu trúc** (`struct`) là một kiểu dùng để gom nhiều thành viên liên quan vào
cùng một đơn vị dữ liệu.

`struct` cho phép tự định nghĩa một kiểu dữ liệu mới.

???+ note "Ghi chú"
    `struct` được mô tả trong trang này không hoàn toàn giống `struct` trong C.
    Trong C++, `struct` được mở rộng thành một khóa khai báo lớp (class-key),
    tương tự [`class`](./class.md).

## Định nghĩa cấu trúc

```cpp
struct Object {
  int weight;
  int value;
} e[array_length];

const Object a{};
Object b, B[array_length], tmp;
Object *c;
```

Ví dụ trên định nghĩa một cấu trúc tên `Object` với hai thành viên `weight` và
`value`, cả hai đều thuộc kiểu `int`.

Đoạn mã trên cũng khai báo mảng `e`, hằng `a`, các biến `b` và `tmp`, mảng `B`
cùng con trỏ `c`; tất cả đều có kiểu `Object`. Với bất kỳ kiểu đã có, cũng có thể
dùng cách này để định nghĩa hằng, biến, con trỏ, mảng, v.v. Ở đây `a` là đối
tượng `const`, nên ví dụ dùng `{}` để khởi tạo giá trị ban đầu cho các thành viên.

*Về con trỏ: chưa cần nắm vững ngay ở thời điểm này.*

### Khai báo con trỏ

Khi khai báo con trỏ tới kiểu dựng sẵn, cách viết giống như khai báo con trỏ
thông thường.

Khi khai báo con trỏ tới cấu trúc, dùng dạng `StructName*` trong khai báo.

```cpp
struct Edge {
  /*
  ...
  */
  Edge* nxt;
};
```

Ví dụ trên minh họa rằng một cấu trúc có thể chứa con trỏ tới chính kiểu của nó.

## Truy cập/sửa thành viên

Có thể dùng `tên_biến.tên_thành_viên` để truy cập thành viên. Ví dụ, có thể
dùng `cout << var.v` để in thành viên `v` của `var`.

Với con trỏ, có thể dùng `tên_con_trỏ->tên_thành_viên` hoặc
`(*tên_con_trỏ).tên_thành_viên` để truy cập. Ví dụ, `(*ptr).v = tmp` hoặc
`ptr->v = tmp` đều gán `tmp` cho thành viên `v` của cấu trúc mà con trỏ `ptr`
đang trỏ tới.

## Vì sao cần cấu trúc?

Trước hết, có nhiều cách để đạt cùng một kết quả: không dùng cấu trúc vẫn có thể
viết được chương trình tương tự. Tuy vậy, cấu trúc cho phép gom tường minh các
thành viên liên quan (trong lập trình thi đấu thường là các biến) lại với nhau.
Chẳng hạn, cấu trúc `Object` trong ví dụ đặt `weight` và `value` cùng một chỗ để
biểu diễn trọng lượng và giá trị của một vật phẩm. Lợi ích là phạm vi sử dụng các
thành viên được giới hạn rõ hơn. Nếu không dùng cấu trúc mà dùng hai mảng
`value[]`, `Value[]`, người viết dễ nhầm lẫn. Khi dùng cấu trúc, khả năng dùng
nhầm biến sẽ giảm đi.

Ngoài ra, các kiểu cấu trúc khác nhau (như `Object`) hoặc các đối tượng cấu trúc
khác nhau (như các phần tử trong mảng `e` ở trên) có thể có thành viên cùng tên,
chẳng hạn `tmp.value` và `b.value`. Các thành viên cùng tên này độc lập với nhau
và có vùng nhớ riêng; sửa `tmp.value` sẽ không ảnh hưởng đến giá trị của
`b.value`. Nhờ đó, có thể dùng những tên giống hoặc gần nhau để mô tả các đối
tượng khác nhau. Ví dụ, `Object` có thành viên `value`; ta cũng có thể định nghĩa
một cấu trúc `Car` và cho nó một thành viên `value`. Nếu không dùng cấu trúc, cần
đặt các mảng bằng những tên khác nhau như `valueOfObject[]`, `valueOfCar[]` để
phân biệt.

*Nếu muốn mô tả một đối tượng chi tiết hơn, có thể định nghĩa thêm hàm thành
viên. Xem [lớp](./class.md) để biết thêm chi tiết.*

## Các thao tác khác

Xem [lớp](./class.md).

## Lưu ý

Để truy cập bộ nhớ hiệu quả hơn, khi sắp xếp cách lưu trữ thực tế của các thành
viên trong cấu trúc, trình biên dịch có thể căn chỉnh thành viên theo những ranh
giới byte nhất định. Điều này có nghĩa là bên trong cấu trúc có thể có phần đệm
giữa các thành viên. Vì vậy, kích thước bộ nhớ mà cấu trúc chiếm có thể lớn hơn
tổng kích thước của tất cả thành viên.

## Tài liệu tham khảo

1.  [Lớp - cppreference.com](https://en.cppreference.com/w/cpp/language/class)
2.  [Cấu trúc dữ liệu - cplusplus.com](http://www.cplusplus.com/doc/tutorial/structures/)
3.  [Căn chỉnh - Microsoft Learn](https://learn.microsoft.com/en-us/cpp/cpp/alignment-cpp-declarations)
