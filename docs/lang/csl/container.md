## Phân loại

![](images/container1.png)

### Bộ chứa tuần tự

-   **Vector** (`vector`): bảng tuần tự có thể thêm phần tử ở cuối hiệu quả.
-   **Array** (`array`) **C++11**: bảng tuần tự độ dài cố định, lớp bọc đơn giản
    cho mảng kiểu C.
-   **Deque** (`deque`): bảng tuần tự có thể thêm phần tử hiệu quả ở cả hai đầu.
-   **List** (`list`): danh sách liên kết có thể duyệt hai chiều.
-   **Forward list** (`forward_list`): danh sách liên kết chỉ có thể duyệt một
    chiều.

### Bộ chứa kết hợp

-   **Set** (`set`): bộ chứa dùng để lưu có thứ tự các phần tử **khác nhau**.
    Hiện thực của nó là cây đỏ-đen gồm các nút; mỗi nút chứa một phần tử, các
    nút được sắp xếp theo một vị từ so sánh phần tử.
-   **Multiset** (`multiset`): bộ chứa dùng để lưu có thứ tự các phần tử, cho
    phép có các phần tử bằng nhau.
-   **Map** (`map`): tập hợp các cặp {khóa, giá trị}, được sắp xếp theo một
    vị từ so sánh quan hệ lớn nhỏ giữa các khóa.
-   **Multimap** (`multimap`): multiset gồm các cặp {khóa, giá trị}, tức là map
    cho phép các khóa bằng nhau.

???+ note "Vị từ ([predicate](https://en.wikipedia.org/wiki/Predicate_%28mathematical_logic%29)) là gì?"
    Vị từ là hàm trả về đúng hoặc sai. Trong bộ chứa STL, vị từ thường được dùng
    làm tham số khuôn mẫu.

### Bộ chứa không thứ tự (kết hợp)

-   **Tập/đa tập không thứ tự** (`unordered_set`/`unordered_multiset`) **C++11**:
    khác `set`/`multiset` ở chỗ phần tử không có thứ tự, chỉ quan tâm "phần tử
    có tồn tại hay không", và được hiện thực bằng băm.
-   **Ánh xạ/đa ánh xạ không thứ tự** (`unordered_map`/`unordered_multimap`) **C++11**:
    khác `map`/`multimap` ở chỗ khóa (`key`) không có thứ tự, chỉ quan tâm "quan
    hệ tương ứng giữa khóa và giá trị", và được hiện thực bằng băm.

### Bộ chuyển đổi bộ chứa

Bộ chuyển đổi bộ chứa thật ra không phải là bộ chứa. Chúng không có một số đặc
điểm của bộ chứa, chẳng hạn bộ lặp hoặc hàm `clear()`.

> "Bộ chuyển đổi là cơ chế làm hành vi của một sự vật giống hành vi của một sự
> vật khác"; bộ chuyển đổi bọc bộ chứa để nó thể hiện một hành vi khác.

-   **Stack** (`stack`): ngăn xếp vào sau ra trước (LIFO), mặc định bọc
    `deque`.
-   **Queue** (`queue`): hàng đợi vào trước ra trước (FIFO), mặc định bọc
    `deque`.
-   **Hàng đợi ưu tiên** (`priority_queue`): hàng đợi mà thứ tự phần tử được quyết
    định bởi một vị từ tác động lên các giá trị được lưu, mặc định bọc
    `vector`.

## Điểm chung

### Khai báo bộ chứa

Đều có dạng `containerName<typeName,...> name`, nhưng số lượng và hình thức tham
số khuôn mẫu (các tham số trong `<>`) thay đổi theo từng bộ chứa cụ thể.

Nguyên nhân bản chất: STL chính là "thư viện khuôn mẫu chuẩn", nên các bộ chứa
đều là mẫu lớp.

### Bộ lặp

Vui lòng tham khảo [bộ lặp](./iterator.md).

### Hàm chung

`=`: có toán tử gán và hàm dựng sao chép.

`begin()`: trả về bộ lặp trỏ đến phần tử đầu.

`end()`: trả về bộ lặp trỏ đến vị trí sau phần tử cuối. `end()` không trỏ đến
một phần tử nào, nhưng nó là hậu kế của phần tử cuối.

`size()`: trả về số phần tử trong bộ chứa.

`max_size()`: trả về số phần tử tối đa mà bộ chứa **về lý thuyết** có thể lưu.
Giá trị này thay đổi theo loại bộ chứa và kiểu biến được lưu.

`empty()`: trả về việc bộ chứa có rỗng hay không.

`swap()`: hoán đổi hai bộ chứa.

`clear()`: xóa sạch bộ chứa.

`==`/`!=`/`<`/`>`/`<=`/`>=`: so sánh hai bộ chứa theo **thứ tự từ điển**. Khi
so sánh kích thước phần tử, mỗi phần tử của `map` tương đương
`set<pair<key, value>>`; bộ chứa không thứ tự không hỗ trợ `<`/`>`/`<=`/`>=`.
