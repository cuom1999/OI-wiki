Trang này giới thiệu ngắn gọn về ứng dụng của sắp xếp.

## Hiểu đặc điểm của dữ liệu

Dùng sắp xếp để xử lý dữ liệu giúp hiểu rõ đặc điểm của dữ liệu, đồng thời hỗ
trợ việc phân tích và trực quan hóa sau đó. Trong đời sống, chẳng hạn như từ
điển hay thực đơn, nếu dữ liệu không được sắp theo một thứ tự nhất định, thời
gian để mọi người tìm thấy thứ mình cần sẽ tăng đáng kể.

Máy tính thường cần xử lý dữ liệu quy mô lớn. Sau khi sắp xếp, có thể dựa trên
đặc điểm và nhu cầu của dữ liệu để thiết kế quy trình xử lý tiếp theo.

## Giảm độ phức tạp thời gian

Dùng sắp xếp làm bước tiền xử lý có thể giảm độ phức tạp thời gian cần thiết để
giải bài toán. Đây thường là sự đánh đổi giữa chi phí tiền xử lý ban đầu và thời
gian xử lý về sau. Nếu một danh sách đã sắp xếp cần được phân tích nhiều lần,
việc chỉ tốn tài nguyên sắp xếp một lần là đáng giá, vì mỗi lần phân tích sau đó
đều có thể tiết kiệm thời gian.

???+ note "Ví dụ: kiểm tra xem dãy đã cho có phần tử bằng nhau hay không"
    Xét một dãy số và cần kiểm tra trong đó có hai phần tử nào bằng nhau hay không.
    
    Một cách làm trực tiếp là kiểm tra mọi cặp số và xác định hai số trong cặp
    đó có bằng nhau hay không. Độ phức tạp thời gian là $O(n^2)$.
    
    Có thể sắp xếp dãy số này trước. Sau đó nhận thấy rằng nếu có hai số bằng
    nhau, chúng nhất định nằm ở hai vị trí kề nhau trong dãy mới. Khi đó, quét
    dãy mới một lần trong $O(n)$ là đủ.
    
    Tổng độ phức tạp thời gian là độ phức tạp của bước sắp xếp, tức $O(n\log n)$.

## Làm tiền xử lý cho tìm kiếm

Sắp xếp là bước tiền xử lý cần thiết cho [tìm kiếm nhị phân](./binary.md). Sau
khi sắp xếp, có thể dùng tìm kiếm nhị phân để tìm một phần tử chỉ định trong dãy
với thời gian $O(\log n)$.
