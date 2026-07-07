## Phân loại

![](images/container1.png)

### Bộ chứa tuần tự

-   **Vector** (`vector`): dãy cho phép thêm phần tử hiệu quả ở cuối.
-   **Array** (`array`) **C++11**: dãy có độ dài cố định, đóng vai trò như lớp
    bọc đơn giản cho mảng kiểu C.
-   **Deque** (`deque`): dãy cho phép thêm phần tử hiệu quả ở cả hai đầu.
-   **List** (`list`): danh sách liên kết có thể duyệt hai chiều.
-   **Forward list** (`forward_list`): danh sách liên kết chỉ có thể duyệt một
    chiều.

### Bộ chứa kết hợp

-   **Set** (`set`): bộ chứa dùng để lưu các phần tử **khác nhau** theo thứ tự.
    Cấu trúc nội bộ thường là cây đỏ-đen gồm các nút; mỗi nút chứa một phần tử,
    các nút được sắp xếp theo một vị từ so sánh phần tử.
-   **Multiset** (`multiset`): bộ chứa dùng để lưu các phần tử có thứ tự, đồng
    thời cho phép các phần tử bằng nhau.
-   **Map** (`map`): tập hợp các cặp {khóa, giá trị}, được sắp xếp theo vị từ so
    sánh giữa các khóa.
-   **Multimap** (`multimap`): tương tự `map`, nhưng cho phép nhiều phần tử có
    khóa bằng nhau.

???+ note "Vị từ ([predicate](https://en.wikipedia.org/wiki/Predicate_%28mathematical_logic%29)) là gì?"
    Vị từ là hàm trả về đúng hoặc sai. Trong bộ chứa STL, vị từ thường được dùng
    làm tham số template.

### Bộ chứa không thứ tự (kết hợp)

-   **Tập/đa tập không thứ tự** (`unordered_set`/`unordered_multiset`) **C++11**:
    khác `set`/`multiset` ở chỗ phần tử không được duy trì theo thứ tự, chỉ quan
    tâm "phần tử có tồn tại hay không", và được cài đặt bằng bảng băm.
-   **Ánh xạ/đa ánh xạ không thứ tự** (`unordered_map`/`unordered_multimap`) **C++11**:
    khác `map`/`multimap` ở chỗ khóa (`key`) không được duy trì theo thứ tự, chỉ
    quan tâm quan hệ giữa khóa và giá trị, và được cài đặt bằng bảng băm.

### Bộ chuyển đổi bộ chứa

Bộ chuyển đổi bộ chứa không hẳn là bộ chứa. Chúng không có một số đặc điểm của bộ
chứa, chẳng hạn bộ lặp hoặc hàm `clear()`.

> "Bộ chuyển đổi là cơ chế làm cho một đối tượng có hành vi giống một đối tượng
> khác"; bộ chuyển đổi bọc một bộ chứa để cung cấp cách sử dụng khác.

-   **Ngăn xếp** (`stack`): cấu trúc vào sau ra trước (LIFO), mặc định bọc
    `deque`.
-   **Hàng đợi** (`queue`): cấu trúc vào trước ra trước (FIFO), mặc định bọc
    `deque`.
-   **Hàng đợi ưu tiên** (`priority_queue`): hàng đợi mà thứ tự phần tử được quyết
    định bởi một vị từ tác động lên các giá trị được lưu, mặc định bọc `vector`.

## Điểm chung

### Khai báo bộ chứa

Các khai báo thường có dạng `containerName<typeName,...> name`, nhưng số lượng và
hình thức tham số template (các tham số trong `<>`) thay đổi theo từng bộ chứa cụ
thể.

Lý do là STL viết tắt của Standard Template Library, nên các bộ chứa đều là mẫu
lớp.

### Bộ lặp

Vui lòng tham khảo [bộ lặp](./iterator.md).

### Hàm chung

`=`: có toán tử gán và hàm dựng sao chép.

`begin()`: trả về bộ lặp trỏ đến phần tử đầu.

`end()`: trả về bộ lặp trỏ đến vị trí sau phần tử cuối. `end()` không trỏ đến một
phần tử nào, mà là vị trí ngay sau phần tử cuối.

`size()`: trả về số phần tử trong bộ chứa.

`max_size()`: trả về số phần tử tối đa mà bộ chứa **về lý thuyết** có thể lưu. Giá
trị này thay đổi theo loại bộ chứa và kiểu biến được lưu.

`empty()`: trả về `true` nếu bộ chứa rỗng, ngược lại trả về `false`.

`swap()`: hoán đổi hai bộ chứa.

`clear()`: xóa sạch bộ chứa.

`==`/`!=`/`<`/`>`/`<=`/`>=`: so sánh hai bộ chứa theo **thứ tự từ điển**. Khi so
sánh từng phần tử, mỗi phần tử của `map` tương đương một `pair<key, value>`; bộ
chứa không thứ tự không hỗ trợ `<`/`>`/`<=`/`>=`.
