author: Ir1d, cjsoft, Lans1ot

**Cấu trúc** (`struct`) có thể xem là một tổ hợp gồm nhiều phần tử thành viên.

Nó cũng có thể được xem như một kiểu dữ liệu tự định nghĩa.

???+ note "Ghi chú"
    `struct` được mô tả trong trang này khác với `struct` trong C. Trong C++,
    `struct` được mở rộng thành một class-key tương tự [`class`](./class.md).

## Định nghĩa cấu trúc

```cpp
struct Object {
  int weight;
  int value;
} e[array_length];

const Object a;
Object b, B[array_length], tmp;
Object *c;
```

Ví dụ trên định nghĩa một cấu trúc tên là `Object`, có hai phần tử thành viên
`value, weight`, đều thuộc kiểu `int`.

Sau dấu `}`, ví dụ còn định nghĩa hằng `a`, biến `b`, biến `tmp`, mảng `B` và
con trỏ `c`, tất cả đều có kiểu dữ liệu là `Object`. Với bất kỳ kiểu đã tồn tại
nào, ta đều có thể dùng cách này để định nghĩa hằng, biến, con trỏ, mảng, v.v.

*Về con trỏ: không cần ép bản thân phải nắm vững ngay.*

### Định nghĩa con trỏ

Nếu định nghĩa con trỏ của kiểu dựng sẵn, cách viết giống định nghĩa con trỏ
thông thường.

Nếu định nghĩa con trỏ tới cấu trúc, dùng `StructName*` trong khai báo.

```cpp
struct Edge {
  /*
  ...
  */
  Edge* nxt;
};
```

Ví dụ trên chỉ để minh họa, không cần bận tâm quá nhiều đến ý nghĩa thực tế.

## Truy cập/sửa phần tử thành viên

Có thể dùng `tên_biến.tên_thành_viên` để truy cập. Ví dụ, có thể dùng
`cout << var.v` để in thành viên `v` của `var`.

Cũng có thể dùng `tên_con_trỏ->tên_thành_viên` hoặc
`(*tên_con_trỏ).tên_thành_viên` để truy cập. Ví dụ, `(*ptr).v = tmp` hoặc
`ptr->v = tmp` đều gán `tmp` cho thành viên `v` của cấu trúc mà con trỏ cấu
trúc `ptr` đang trỏ tới.

## Vì sao cần cấu trúc?

Trước hết, có nhiều con đường dẫn tới cùng một kết quả: ta có thể không dùng cấu
trúc mà vẫn đạt hiệu quả tương tự. Tuy vậy, cấu trúc cho phép gom tường minh các
phần tử thành viên (trong lập trình thi đấu thường là các biến) lại với nhau.
Chẳng hạn, cấu trúc `Object` trong ví dụ đặt `value, weight` cùng một chỗ; ý
nghĩa thực tế của cấu trúc này là biểu diễn trọng lượng và giá trị của một vật
phẩm. Lợi ích là phạm vi dùng các phần tử thành viên được giới hạn rõ hơn. Hãy
tưởng tượng nếu không dùng cấu trúc mà có hai mảng `value[], Value[]`, ta rất dễ
nhầm lẫn khi viết. Khi dùng cấu trúc, xác suất dùng nhầm biến sẽ giảm đi.

Ngoài ra, các cấu trúc khác nhau (kiểu cấu trúc, như `Object`) hoặc các biến cấu
trúc khác nhau (thực thể của cấu trúc, như mảng `e` ở trên) có thể có các phần
tử thành viên cùng tên, chẳng hạn `tmp.value, b.value`. Các phần tử cùng tên này
độc lập với nhau và có vùng nhớ riêng; ví dụ sửa `tmp.value` sẽ không ảnh hưởng
đến giá trị của `b.value`. Lợi ích là ta có thể dùng những tên biến giống hoặc
gần giống nhau để mô tả một sự vật. Ví dụ `Object` có thành viên `value`; ta
cũng có thể định nghĩa một cấu trúc `Car` và cũng cho nó một thành viên
`value`. Nếu không dùng cấu trúc, có lẽ ta phải định nghĩa các mảng với tên khác
nhau như `valueOfObject[], valueOfCar[]` để phân biệt.

*Nếu muốn mô tả một sự vật chi tiết hơn, có thể định nghĩa thêm hàm thành viên.
Xem [lớp](./class.md) để biết thêm chi tiết.*

## Còn thao tác nào khác?

Xem [lớp](./class.md).

## Lưu ý

Để truy cập bộ nhớ hiệu quả hơn, khi xử lý cách lưu trữ thực tế của các thành
viên trong cấu trúc, trình biên dịch có thể căn chỉnh thành viên vào một vị trí
byte nhất định. Điều này có nghĩa là trong cấu trúc có thể có phần trống. Vì vậy
kích thước bộ nhớ mà cấu trúc chiếm có thể lớn hơn tổng kích thước của tất cả
thành viên bên trong.

## Tài liệu tham khảo

1.  [Class - cppreference.com](https://en.cppreference.com/w/cpp/language/class)
2.  [Data structures - cplusplus.com](http://www.cplusplus.com/doc/tutorial/structures/)
3.  [Alignment - Microsoft Learn](https://learn.microsoft.com/en-us/cpp/cpp/alignment-cpp-declarations)
