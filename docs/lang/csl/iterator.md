Trong STL, iterator là đối tượng dùng để truy cập và kiểm tra phần tử trong STL
container. Mô hình hành vi của nó tương tự con trỏ, nhưng nó đóng gói thêm một
số kiểm tra tính hợp lệ và cung cấp một định dạng truy cập thống nhất. Khái niệm
tương tự cũng tồn tại trong nhiều ngôn ngữ bậc cao khác, như hàm `__iter__` của
Python hoặc `IEnumerator` của C#.

## Cách dùng cơ bản

Iterator nghe có vẻ khó, nhưng bản thân iterator có thể xem như một con trỏ dữ
liệu. Iterator chủ yếu hỗ trợ hai toán tử: tự tăng (`++`) và giải tham chiếu
(toán tử một ngôi `*`). Trong đó, tự tăng dùng để di chuyển iterator, còn giải
tham chiếu có thể lấy hoặc sửa phần tử mà nó trỏ tới.

Kiểu iterator trỏ đến phần tử trong một [STL container](./container.md)
`container` thường là `container::iterator`.

Iterator có thể dùng để duyệt container. Ví dụ, hai vòng lặp `for` dưới đây có
tác dụng giống nhau:

```cpp
vector<int> data(10);

for (int i = 0; i < data.size(); i++)
  cout << data[i] << endl;  // truy cập phần tử bằng chỉ số

for (vector<int>::iterator iter = data.begin(); iter != data.end(); iter++)
  cout << *iter << endl;  // truy cập phần tử bằng iterator
// Từ C++11 trở đi có thể dùng auto iter = data.begin() để rút gọn đoạn mã trên
```

???+ tip "Dùng `auto` trong thi đấu"
    Phần lớn thí sinh đều thích dùng `auto` thay cho khai báo iterator rườm rà.
    Theo [bổ sung về giới hạn sử dụng ngôn ngữ lập trình trong các hoạt động
    thuộc hệ thống NOI](https://www.noi.cn/xw/2021-09-01/735729.shtml) công bố
    tháng 9 năm 2021, các cuộc thi thuộc hệ thống NOI (bao gồm CSP J/S) sẽ dùng
    **C++14** khi chấm, và phiên bản này đã hỗ trợ từ khóa `auto`.

## Phân loại

Trong định nghĩa của STL, iterator được chia theo các thao tác mà nó hỗ trợ,
lần lượt gồm các loại sau:

-   InputIterator (iterator nhập): chỉ yêu cầu hỗ trợ sao chép, tự tăng và truy
    cập bằng giải tham chiếu.
-   OutputIterator (iterator xuất): chỉ yêu cầu hỗ trợ sao chép, tự tăng và gán
    thông qua giải tham chiếu.
-   ForwardIterator (iterator tiến): trên cơ sở InputIterator, hỗ trợ duyệt
    nhiều lần và bảo đảm kết quả truy cập bằng giải tham chiếu nhiều lần là nhất
    quán.
-   BidirectionalIterator (iterator hai chiều): trên cơ sở ForwardIterator, hỗ
    trợ tự giảm, tức truy cập ngược.
-   RandomAccessIterator (iterator truy cập ngẫu nhiên): trên cơ sở
    BidirectionalIterator, hỗ trợ phép cộng trừ và phép so sánh, tức truy cập
    ngẫu nhiên.
-   ContiguousIterator (iterator liên tục): trên cơ sở RandomAccessIterator, yêu
    cầu với iterator có thể giải tham chiếu `a + n`, biểu thức `*(a + n)` tương
    đương `*(std::address_of(*a) + n)`, tức lưu trữ liên tục; ở đây `a` là
    iterator liên tục và `n` là giá trị số nguyên.

    ContiguousIterator được chính thức đưa vào từ C++17.

???+ tip "Vì sao input iterator gọi là iterator nhập?"
    "Nhập" nghĩa là "có thể lấy input từ iterator", còn "xuất" nghĩa là "có thể
    output vào iterator".
    
    Chủ thể thực hiện "nhập" và "xuất" là các phần khác của chương trình, không
    phải bản thân iterator.

Các phân loại iterator này không loại trừ lẫn nhau. Trên thực tế, ngoài output
iterator, các iterator đứng trước trong danh sách đều bao hàm iterator đứng sau.
Ví dụ, nơi yêu cầu dùng forward iterator cũng có thể dùng bidirectional iterator.
Bắt đầu từ forward iterator, nếu những iterator này cũng hiện thực chức năng của
output iterator (tức cho phép ghi), chúng được gọi là mutable iterator. Từ đó có
thể sinh ra các loại như "mutable random access iterator".

Các [STL container](./container.md) khác nhau hỗ trợ các loại iterator khác
nhau; khi dùng cần chú ý.

Con trỏ mảng thỏa mãn mọi yêu cầu của contiguous iterator (hoặc random access
iterator với C++14 trở về trước), nên có thể dùng như contiguous iterator.

## Hàm liên quan

Nhiều [hàm STL](./algorithm.md) dùng iterator làm tham số.

Có thể dùng `std::advance(it, n)` để di chuyển iterator `it` về sau `n` bước;
nếu `n` âm thì tương ứng di chuyển về trước, khi đó iterator phải thỏa mãn
bidirectional iterator, nếu không hành vi không xác định.

Từ C++11 trở đi, có thể dùng `std::next(it)` để lấy hậu kế của forward iterator
`it` (iterator `it` không đổi), và `std::next(it, n)` để lấy hậu kế thứ `n` của
forward iterator `it`.

Từ C++11 trở đi, có thể dùng `std::prev(it)` để lấy tiền nhiệm của
bidirectional iterator `it` (iterator `it` không đổi), và `std::prev(it, n)` để
lấy tiền nhiệm thứ `n` của bidirectional iterator `it`.

[STL container](./container.md) thường hỗ trợ truy cập từ một đầu hoặc hai đầu,
cũng như hỗ trợ [bộ sửa đổi const](../const.md). Ví dụ, hàm `begin()` của
container có thể lấy iterator trỏ đến phần tử đầu tiên của container; `rbegin()`
có thể lấy reverse iterator trỏ đến phần tử cuối cùng của container; `cbegin()`
có thể lấy const iterator trỏ đến phần tử đầu tiên; `end()` có thể lấy iterator
trỏ đến cuối container ("cuối" không phải phần tử cuối, mà có thể xem là hậu kế
của phần tử cuối; tiền nhiệm của "cuối" là phần tử cuối trong container, còn bản
thân nó không trỏ đến phần tử nào).

Bạn có thể xem thêm cách dùng tại [Iterator library - cppreference.com](https://en.cppreference.com/w/cpp/iterator).
