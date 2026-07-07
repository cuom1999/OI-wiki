author: HeRaNO, Xeonacid, saffahyjp

Tên đầy đủ của thư viện pb\_ds là Policy-Based Data Structures, nghĩa là các
cấu trúc dữ liệu dựa trên chính sách.

Thư viện pb\_ds cung cấp nhiều cấu trúc dữ liệu, chẳng hạn bảng băm (hash
table), cây nhị phân cân bằng, trie, đống (hàng đợi ưu tiên), v.v.

Giống như `vector`, `set`, `map`, nhiều thành phần của pb\_ds cố gắng tuân theo
quy ước giao diện của STL. Một số thành phần (như hàng đợi ưu tiên) có đầy đủ
chức năng của thành phần tương ứng trong STL, đồng thời cung cấp thêm nhiều chức
năng hơn.

pb\_ds là phần mở rộng của GNU libstdc++, nên chỉ dùng được với trình biên dịch
sử dụng libstdc++ làm thư viện chuẩn.

Với các cấu trúc hỗ trợ duyệt, có thể dùng `begin()` và `end()` để lấy bộ lặp
rồi duyệt các phần tử.

Một số cấu trúc hỗ trợ thao tác sửa khóa, chẳng hạn `increase_key`,
`decrease_key`, và xóa từng phần tử riêng lẻ.

Vì nội dung chính của thư viện pb\_ds nằm trong không gian tên `__gnu_pbds`, bắt
đầu bằng dấu gạch dưới, tính hợp lệ của nó trong các hoạt động thuộc hệ thống
NOI từng chưa được xác định rõ. Ngày 1 tháng 9 năm 2021, theo
[bổ sung về giới hạn sử dụng ngôn ngữ lập trình trong các hoạt động thuộc hệ
thống NOI](https://www.noi.cn/xw/2021-09-01/735729.shtml), việc dùng hàm thư
viện hoặc macro bắt đầu bằng dấu gạch dưới được cho phép, trừ các hàm thư viện
và macro bị cấm tường minh. Vì vậy, việc dùng thư viện pb\_ds trong các hoạt
động thuộc hệ thống NOI đã có cơ sở tường minh trong văn bản quy định.

**Tài liệu tham khảo:** [Ứng dụng thư viện pb\_ds của C++ trong OI][pbds-oi]

[pbds-oi]: https://github.com/OI-Wiki/libs/blob/master/lang/pb-ds/C%2B%2B%E7%9A%84pb_ds%E5%BA%93%E5%9C%A8OI%E4%B8%AD%E7%9A%84%E5%BA%94%E7%94%A8.pdf
