## Chuẩn C++

Trước hết cần giới thiệu các phiên bản của chính C++. C++ là một ngôn ngữ,
nhưng các trình biên dịch khác nhau có thể triển khai chi tiết khác nhau; vì
vậy cần có chuẩn để ràng buộc cách triển khai và giúp mã C++ có hành vi nhất
quán trên nhiều trình biên dịch. Từ khi ra đời năm 1985, C++ đã có 7 chuẩn chính
thức do Tổ chức Tiêu chuẩn hóa Quốc tế (ISO) công bố, lần lượt là C++98, C++03,
C++11 (còn gọi là C++0x), C++14 (còn gọi là C++1y), C++17 (còn gọi là C++1z),
C++20 (còn gọi là C++2a), C++23 (còn gọi là C++2b). Dự thảo chuẩn C++ có trên
trang [open-std](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/); tiến độ
xây dựng các chuẩn mới xem tại
[Current Status : Standard C++](https://isocpp.org/std/status).
Ngoài ra còn có một số chuẩn bổ sung, chẳng hạn C++ TR1.

Mỗi phiên bản chuẩn C++ không chỉ quy định cú pháp và tính năng ngôn ngữ, mà còn
quy định đặc tả cho một bộ thư viện dựng sẵn; đó chính là thư viện chuẩn C++.
Thư viện chuẩn C++ chứa rất nhiều mã thường dùng đã được cài đặt sẵn, như nhập
xuất, cấu trúc dữ liệu cơ bản, quản lý bộ nhớ, hỗ trợ đa luồng và nhiều thành
phần khác. Nắm được thư viện chuẩn C++ là bước cần thiết để viết mã C++ hiện đại
hơn.

Tài liệu chi tiết của thư viện chuẩn C++ có trên
[cppreference](https://en.cppreference.com/); tài liệu này giới thiệu cách dùng,
hiệu suất và các điểm cần lưu ý của kiểu dữ liệu và hàm trong thư viện chuẩn,
nên rất đáng tham khảo.

Lưu ý rằng các nền tảng OJ khác nhau hỗ trợ phiên bản C++ khác nhau. Ví dụ,
[quy tắc môi trường lập trình ICPC](https://docs.icpc.global/worldfinals-programming-environment/)
hỗ trợ chuẩn C++20. Theo nghị quyết của Ủy ban Khoa học NOI, từ ngày 1 tháng 9
năm 2021, [NOI Linux 2.0](https://www.noi.cn/gynoi/jsgz/2021-07-16/732450.shtml)
được dùng làm môi trường chuẩn cho hệ thống cuộc thi NOI và các hoạt động như
CSP-J/S. g++ 9.3.0 trong NOI Linux 2.0
[mặc định hỗ trợ](https://gcc.gnu.org/projects/cxx-status.html#cxx14) chuẩn
C++14, đồng thời hỗ trợ C++17, đủ đáp ứng nhu cầu của hầu hết thí sinh. Vì vậy,
khi học C++, cần lưu ý chuẩn mà cuộc thi hỗ trợ để tránh lỗi biên dịch trên sân
thi.

## Thư viện template chuẩn (STL)

STL, tức Thư viện Template Chuẩn (Standard Template Library), là một phần của
thư viện chuẩn C++ và chứa nhiều cấu trúc dữ liệu cùng thuật toán tổng quát được
viết bằng template. Nhờ cơ chế template, STL dùng được với kiểu dữ liệu tự định
nghĩa và giúp tránh nhiều việc "tự chế lại" mã có sẵn. Các cuộc thi NOI và ICPC
đều cho phép dùng STL, vì vậy sử dụng STL hợp lý có thể giảm lượng mã phải tự
viết, đồng thời tận dụng tối ưu hóa của trình biên dịch cho mã thư viện dựa trên
template để cải thiện hiệu suất. Giới thiệu chi tiết về STL nằm ở các trang
tương ứng: [bộ chứa STL](./container.md) và
[thuật toán STL](./algorithm.md).

??? note "Tự chế lại bánh xe là gì?"
    Tự chế lại bánh xe ([Reinventing\_the\_wheel](https://en.wikipedia.org/wiki/Reinventing_the_wheel))
    nghĩa là phát minh lại thuật toán đã có, hoặc viết lại đoạn mã đã được tối
    ưu sẵn. Việc này thường tốn thời gian và công sức, trong khi hiệu quả có thể
    không bằng mã đã có. Tuy nhiên, nếu mục đích là học tập hoặc luyện tập thì
    tự viết lại vẫn cần thiết.

## Thư viện Boost

[Boost](https://www.boost.org/) là một thư viện công cụ C++ mã nguồn mở nổi
tiếng bên cạnh thư viện chuẩn. Mã của Boost có tính khả chuyển, chất lượng cao,
hiệu năng cao và độ tin cậy cao. Boost có số lượng mô-đun rất lớn, chức năng
toàn diện và hỗ trợ đa nền tảng đầy đủ, nên thường được xem như một thư viện gần
chuẩn của C++. Không ít tính năng trong chuẩn C++ cũng bắt nguồn từ Boost, như
con trỏ thông minh, lập trình meta, thư viện ngày giờ và các thành phần khác.

Dù trong OI không thể dùng Boost, thư viện này vẫn có nhiều "bánh xe" hữu ích
để kiểm chứng thuật toán hoặc đối chiếu kết quả. Ví dụ, Boost.Geometry có cài
đặt R-tree, Boost.Graph có các thuật toán đồ thị, còn Boost.Intrusive cung cấp
bộ chứa xâm nhập có cách dùng tương tự bộ chứa STL. Có thể tự tìm thêm hướng dẫn
trên mạng nếu cần.

## Tài liệu tham khảo

1.  [C++ reference](https://en.cppreference.com/)
2.  [Sổ tay tham khảo C++](https://en.cppreference.com/)
3.  [Wikipedia - C++](https://en.wikipedia.org/wiki/C%2B%2B)
4.  [Trang chính thức Boost](https://www.boost.org/)
5.  [Trang hướng dẫn Boost](https://theboostcpplibraries.com/)
