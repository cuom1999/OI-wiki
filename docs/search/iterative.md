## Định nghĩa

Tìm kiếm sâu dần là một dạng tìm kiếm theo chiều sâu **giới hạn độ sâu tìm kiếm
ở mỗi lần chạy**.

## Giải thích

Bản chất của tìm kiếm sâu dần vẫn là tìm kiếm theo chiều sâu, chỉ khác là khi
tìm kiếm sẽ mang theo một độ sâu $d$; khi $d$ đạt đến độ sâu đã đặt thì trả về.
Nó thường dùng để tìm lời giải tối ưu. Nếu một lần tìm kiếm không tìm được lời
giải hợp lệ, tăng độ sâu đã đặt thêm một và tìm lại từ gốc.

Nếu mục tiêu là tìm lời giải tối ưu, tại sao không dùng BFS? Ta biết nền tảng
của BFS là hàng đợi, mà hàng đợi có độ phức tạp không gian lớn. Khi số trạng
thái nhiều hoặc mỗi trạng thái lớn, BFS dùng hàng đợi sẽ bộc lộ nhược điểm. Trên
thực tế, tìm kiếm sâu dần giống như dùng DFS để hiện thực BFS, nên độ phức tạp
không gian tương đối nhỏ.

Khi cây tìm kiếm có nhiều nhánh, mỗi khi tăng thêm một tầng, độ phức tạp tìm
kiếm có thể tăng bùng nổ theo cấp số mũ. Khi đó phần bị lặp lại ở các tầng phía
trước gần như có thể bỏ qua, đây cũng là lý do vì sao tìm kiếm sâu dần có thể
xem xấp xỉ như BFS.

## Quy trình

Trước hết đặt một độ sâu nhỏ làm biến toàn cục rồi chạy DFS. Mỗi khi đi vào DFS,
tăng độ sâu hiện tại lên một; nếu phát hiện $d$ lớn hơn độ sâu giới hạn
$\textit{limit}$ thì trả về. Nếu trong quá trình tìm kiếm phát hiện đáp án thì
có thể quay lui, đồng thời ghi lại đường đi trong quá trình quay lui. Nếu không
tìm được đáp án, quay lại điểm vào của hàm, tăng độ sâu giới hạn và tiếp tục tìm
kiếm.

???+ note "Hiện thực (mã giả)"
    ```text
    IDDFS(u,d)
        if d>limit
            return
        else
            for each edge (u,v)
                IDDFS(v,d+1)
    return
    ```

## Chú ý

Trong đa số bài toán, tìm kiếm theo chiều rộng vẫn tiện hơn và dễ đánh dấu trạng
thái trùng hơn. Khi phát hiện tìm kiếm theo chiều rộng không tốt về không gian,
đồng thời bài toán cần tìm lời giải tối ưu, nên cân nhắc tìm kiếm sâu dần.
