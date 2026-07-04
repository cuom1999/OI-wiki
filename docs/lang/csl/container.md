## Phân loại

![](images/container1.png)

### Container tuần tự

-   **Vector** (`vector`): bảng tuần tự có thể thêm phần tử ở cuối hiệu quả.
-   **Array** (`array`) **C++11**: bảng tuần tự độ dài cố định, lớp bọc đơn giản
    cho mảng kiểu C.
-   **Deque** (`deque`): bảng tuần tự có thể thêm phần tử hiệu quả ở cả hai đầu.
-   **List** (`list`): danh sách liên kết có thể duyệt hai chiều.
-   **Forward list** (`forward_list`): danh sách liên kết chỉ có thể duyệt một
    chiều.

### Container kết hợp

-   **Set** (`set`): container dùng để lưu có thứ tự các phần tử **khác nhau**.
    Hiện thực của nó là cây đỏ-đen gồm các nút; mỗi nút chứa một phần tử, các
    nút được sắp xếp theo một predicate so sánh phần tử.
-   **Multiset** (`multiset`): container dùng để lưu có thứ tự các phần tử, cho
    phép có các phần tử bằng nhau.
-   **Map** (`map`): tập hợp các cặp {khóa, giá trị}, được sắp xếp theo một
    predicate so sánh quan hệ lớn nhỏ giữa các khóa.
-   **Multimap** (`multimap`): multiset gồm các cặp {khóa, giá trị}, tức là map
    cho phép các khóa bằng nhau.

???+ note "Predicate ([**vị từ**](https://en.wikipedia.org/wiki/Predicate_%28mathematical_logic%29)) là gì?"
    Predicate là hàm trả về đúng hoặc sai. Trong STL container, predicate thường
    được dùng làm tham số template.

### Container không thứ tự (kết hợp)

-   **Unordered (multi)set** (`unordered_set`/`unordered_multiset`) **C++11**:
    khác `set`/`multiset` ở chỗ phần tử không có thứ tự, chỉ quan tâm "phần tử
    có tồn tại hay không", và được hiện thực bằng hash.
-   **Unordered (multi)map** (`unordered_map`/`unordered_multimap`) **C++11**:
    khác `map`/`multimap` ở chỗ khóa (key) không có thứ tự, chỉ quan tâm "quan
    hệ tương ứng giữa khóa và giá trị", và được hiện thực bằng hash.

### Container adaptor

Container adaptor thật ra không phải container. Chúng không có một số đặc điểm
của container, chẳng hạn iterator hoặc hàm `clear()`.

> "Adaptor là cơ chế làm hành vi của một sự vật giống hành vi của một sự vật
> khác"; adaptor bọc container để nó thể hiện một hành vi khác.

-   **Stack** (`stack`): container vào sau ra trước (LIFO), mặc định bọc
    `deque`.
-   **Queue** (`queue`): container vào trước ra trước (FIFO), mặc định bọc
    `deque`.
-   **Priority queue** (`priority_queue`): hàng đợi mà thứ tự phần tử được quyết
    định bởi một predicate tác động lên các giá trị được lưu, mặc định bọc
    `vector`.

## Điểm chung

### Khai báo container

Đều có dạng `containerName<typeName,...> name`, nhưng số lượng và hình thức tham
số template (các tham số trong `<>`) thay đổi theo từng container cụ thể.

Nguyên nhân bản chất: STL chính là "thư viện mẫu chuẩn", nên các container đều
là lớp template.

### Iterator

Vui lòng tham khảo [iterator](./iterator.md).

### Hàm chung

`=`: có toán tử gán và copy constructor.

`begin()`: trả về iterator trỏ đến phần tử đầu.

`end()`: trả về iterator trỏ đến vị trí sau phần tử cuối. `end()` không trỏ đến
một phần tử nào, nhưng nó là hậu kế của phần tử cuối.

`size()`: trả về số phần tử trong container.

`max_size()`: trả về số phần tử tối đa mà container **về lý thuyết** có thể lưu.
Giá trị này thay đổi theo loại container và kiểu biến được lưu.

`empty()`: trả về container có rỗng hay không.

`swap()`: hoán đổi hai container.

`clear()`: xóa sạch container.

`==`/`!=`/`<`/`>`/`<=`/`>=`: so sánh hai container theo **thứ tự từ điển**. Khi
so sánh kích thước phần tử, mỗi phần tử của `map` tương đương
`set<pair<key, value>>`; container không thứ tự không hỗ trợ `<`/`>`/`<=`/`>=`.
