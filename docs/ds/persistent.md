author: morris821028

## Giới thiệu

Cấu trúc dữ liệu bền vững có thể giữ lại mọi phiên bản lịch sử,
đồng thời cho phép thao tác trên dữ liệu theo cách không phá hủy phiên bản cũ.

## Phân loại cấu trúc bền vững

<span id="một-phần-bền-vững-partially-persistent"></span>
### Một phần bền vững

Mọi phiên bản đều có thể được truy cập, nhưng chỉ phiên bản mới nhất có thể được sửa đổi.

<span id="hoàn-toàn-bền-vững-fully-persistent"></span>
### Hoàn toàn bền vững

Mọi phiên bản đều có thể vừa được truy cập vừa được sửa đổi.

Nếu còn hỗ trợ hợp nhất hai phiên bản lịch sử, cấu trúc đó được gọi là bền vững hợp lưu (confluently persistent).

## Ứng dụng thực tế

### Tính toán hình học

Trong tính toán hình học có nhiều thuật toán ngoại tuyến,
chẳng hạn thuật toán đường quét có thể trả lời mọi truy vấn trong một lần quét với độ phức tạp rất tốt.
Nhưng nếu bị buộc phải xử lý trực tuyến,
mỗi lần lại phải quét một lượt, khiến độ phức tạp truy vấn từ mức logarit rơi xuống tuyến tính.
Để giải quyết tình huống này, kỹ thuật bền vững hóa đưa ra một cách nhìn khác:
xem trục thời gian của đường quét là căn cứ biến đổi và bền vững hóa cấu trúc liên quan.
Chỉ cần truy vấn có thể di chuyển trên trục thời gian này trong thời gian logarit,
có thể xử lý bài toán ban đầu trong bối cảnh động.

### Xử lý chuỗi

Để hợp nhất hiệu quả và tránh suy giảm hiệu năng do tạo ra lượng lớn chuỗi lặp lại,
nhiều thao tác cần có độ phức tạp thấp hơn tuyến tính đáng kể.
Ví dụ, `rope` trong C++ là một cấu trúc dữ liệu bền vững.
Không chỉ trong thao tác chuỗi,
khi kiểu dữ liệu cần xử lý có nhiều phần lặp lại,
khái niệm cấu trúc bền vững cũng có thể phát huy tác dụng.

### Quay lui phiên bản

Về bản chất, ứng dụng này tương ứng với redo/undo trong phần lớn phần mềm.
Nếu dữ liệu hoặc thao tác biến đổi cần đi kèm cấu trúc phức tạp để đạt hiệu quả cao
(không giống `hash` hay `set`, nơi thao tác đảo ngược thường chỉ cần thời gian hằng số hoặc logarit),
thì để nhanh chóng quay lui kết quả biến đổi,
cấu trúc bền vững có thể giảm chi phí redo/undo.

Bản thân cơ sở dữ liệu có thể quay lui trong thời gian hằng số nếu chỉ ghi lại phần đã thay đổi.
Nhưng ở tầng ứng dụng, đa số cài đặt sẽ bỏ cache rồi tính lại một cấu trúc mới.
Đôi khi phần thay đổi cần quay lui có kích thước $m$,
nhưng để tính lại toàn bộ cấu trúc lại tốn $n+m$;
nếu $n$ và $m$ chênh lệch rất lớn, trải nghiệm khi quay lui liên tiếp sẽ rất tệ.

### Lập trình hàm

Lập trình hàm cần các cấu trúc dữ liệu đặc biệt để phù hợp với đặc tính ngôn ngữ;
trong đó tính bất biến càng quan trọng vì có lợi cho môi trường song song và gỡ lỗi.
Chẳng hạn, Java hướng đối tượng từ Java 8 đã đưa vào lớp `stream`,
hỗ trợ viết cú pháp theo phong cách hàm và cung cấp các khả năng đặc biệt
như đánh giá lười, miền giá trị vô hạn, v.v.

## Tài liệu tham khảo

-   <https://en.wikipedia.org/wiki/Persistent_data_structure>
-   [Khóa học MIT][mit-persistent]

[mit-persistent]: https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-854j-advanced-algorithms-fall-2005/lecture-notes/persistent.pdf
