Trong STL, bộ lặp là đối tượng dùng để truy cập và kiểm tra các phần tử trong
bộ chứa STL. Mô hình hành vi của nó tương tự con trỏ, nhưng nó đóng gói thêm
một số kiểm tra tính hợp lệ và cung cấp một giao diện truy cập thống nhất. Khái
niệm tương tự cũng tồn tại trong nhiều ngôn ngữ bậc cao khác, như hàm
`__iter__` của Python hoặc `IEnumerator` của C#.

## Cách dùng cơ bản

Bộ lặp nghe có vẻ khó, nhưng về bản chất có thể xem như một con trỏ dữ
liệu. Bộ lặp chủ yếu hỗ trợ hai toán tử: tự tăng (`++`) và giải tham chiếu
(toán tử một ngôi `*`). Trong đó, tự tăng dùng để di chuyển bộ lặp, còn giải
tham chiếu dùng để lấy hoặc sửa phần tử mà nó trỏ tới.

Kiểu bộ lặp trỏ đến phần tử trong một [bộ chứa STL](./container.md)
`container` thường là `container::iterator`.

Bộ lặp có thể dùng để duyệt bộ chứa. Ví dụ, hai vòng lặp `for` dưới đây có
tác dụng giống nhau:

```cpp
vector<int> data(10);

for (int i = 0; i < data.size(); i++)
  cout << data[i] << endl;  // truy cập phần tử bằng chỉ số

for (vector<int>::iterator iter = data.begin(); iter != data.end(); iter++)
  cout << *iter << endl;  // truy cập phần tử bằng bộ lặp
// Từ C++11 trở đi có thể dùng auto iter = data.begin() để rút gọn đoạn mã trên
```

???+ tip "Dùng `auto` trong thi đấu"
    Phần lớn thí sinh thường dùng `auto` thay cho khai báo bộ lặp rườm rà.
    Theo [bổ sung về giới hạn sử dụng ngôn ngữ lập trình trong các hoạt động
    thuộc hệ thống NOI](https://www.noi.cn/xw/2021-09-01/735729.shtml) công bố
    tháng 9 năm 2021, các cuộc thi thuộc hệ thống NOI (bao gồm CSP J/S) sẽ dùng
    **C++14** khi chấm, và phiên bản này đã hỗ trợ từ khóa `auto`.

## Phân loại

Trong định nghĩa của STL, bộ lặp được chia theo các thao tác mà nó hỗ trợ,
lần lượt gồm các loại sau:

-   `InputIterator` (bộ lặp nhập): chỉ yêu cầu hỗ trợ sao chép, tự tăng và truy
    cập bằng giải tham chiếu.
-   `OutputIterator` (bộ lặp xuất): chỉ yêu cầu hỗ trợ sao chép, tự tăng và gán
    qua toán tử giải tham chiếu.
-   `ForwardIterator` (bộ lặp tiến): dựa trên `InputIterator`, hỗ trợ duyệt
    nhiều lần và bảo đảm kết quả của nhiều lần giải tham chiếu là nhất quán.
-   `BidirectionalIterator` (bộ lặp hai chiều): dựa trên `ForwardIterator`, hỗ
    trợ tự giảm, tức truy cập ngược.
-   `RandomAccessIterator` (bộ lặp truy cập ngẫu nhiên): dựa trên
    `BidirectionalIterator`, hỗ trợ phép cộng trừ và phép so sánh, tức truy cập
    ngẫu nhiên.
-   `ContiguousIterator` (bộ lặp liên tục): dựa trên `RandomAccessIterator`,
    yêu cầu nếu `a + n` có thể giải tham chiếu thì biểu thức `*(a + n)` tương
    đương `*(std::address_of(*a) + n)`, tức các phần tử được lưu trữ liên tục;
    trong đó `a` là bộ lặp liên tục và `n` là giá trị số nguyên.

    `ContiguousIterator` được chính thức đưa vào từ C++17.

???+ tip "Vì sao bộ lặp nhập gọi là bộ lặp nhập?"
    "Nhập" nghĩa là "có thể lấy dữ liệu nhập từ bộ lặp", còn "xuất" nghĩa là "có
    thể xuất dữ liệu vào bộ lặp".

    Phần thực hiện thao tác "nhập" và "xuất" là các phần khác của chương
    trình, không phải bản thân bộ lặp.

Các phân loại bộ lặp này không loại trừ lẫn nhau. Trong thực tế, ngoài bộ lặp
xuất, các bộ lặp đứng sau trong danh sách đều đáp ứng yêu cầu của bộ lặp đứng
trước. Ví dụ, nơi yêu cầu dùng bộ lặp tiến cũng có thể dùng bộ lặp hai chiều.
Bắt đầu từ bộ lặp tiến, nếu những bộ lặp này cũng hỗ trợ thao tác ghi của bộ lặp
xuất, chúng là bộ lặp khả biến. Từ đó có thể sinh ra các loại như
"bộ lặp truy cập ngẫu nhiên khả biến" (`mutable random access iterator`).

Mỗi [bộ chứa STL](./container.md) hỗ trợ những loại bộ lặp khác nhau, vì vậy cần
lưu ý khi sử dụng.

Con trỏ mảng thỏa mãn mọi yêu cầu của bộ lặp liên tục (hoặc bộ lặp truy cập
ngẫu nhiên với C++14 trở về trước), nên có thể dùng như bộ lặp liên tục.

## Hàm liên quan

Nhiều [hàm STL](./algorithm.md) dùng bộ lặp làm tham số.

Có thể dùng `std::advance(it, n)` để di chuyển bộ lặp `it` tiến thêm `n` bước;
nếu `n` âm thì tương ứng di chuyển lùi lại, khi đó bộ lặp phải thỏa mãn yêu cầu
của bộ lặp hai chiều, nếu không hành vi không xác định.

Từ C++11 trở đi, có thể dùng `std::next(it)` để lấy bộ lặp ngay sau bộ lặp tiến
`it` (bộ lặp `it` không đổi), và `std::next(it, n)` để lấy bộ lặp cách `it`
`n` bước về phía sau.

Từ C++11 trở đi, có thể dùng `std::prev(it)` để lấy bộ lặp ngay trước bộ lặp hai
chiều `it` (bộ lặp `it` không đổi), và `std::prev(it, n)` để lấy bộ lặp cách
`it` `n` bước về phía trước.

[Bộ chứa STL](./container.md) thường hỗ trợ truy cập từ một đầu hoặc hai đầu,
cũng như hỗ trợ [bộ sửa đổi const](../const.md). Ví dụ, hàm `begin()` của
bộ chứa có thể lấy bộ lặp trỏ đến phần tử đầu tiên của bộ chứa; `rbegin()`
có thể lấy bộ lặp ngược trỏ đến phần tử cuối cùng của bộ chứa; `cbegin()`
có thể lấy bộ lặp hằng trỏ đến phần tử đầu tiên; `end()` có thể lấy bộ lặp
trỏ đến cuối bộ chứa ("cuối" không phải phần tử cuối, mà có thể xem là vị trí
ngay sau phần tử cuối; vị trí ngay trước "cuối" là phần tử cuối trong bộ chứa,
còn bản thân nó không trỏ đến phần tử nào).

Có thể xem thêm cách dùng tại [thư viện bộ lặp trên cppreference.com](https://en.cppreference.com/w/cpp/iterator).
