## Giới thiệu

Thuật toán leo đồi là một phương pháp chọn tối ưu cục bộ. Đây là một phương pháp theo kinh nghiệm, có thể xem như một cải tiến của tìm kiếm theo chiều sâu, dùng thông tin phản hồi để hỗ trợ việc sinh quyết định cho lời giải.

Nói trực tiếp hơn, khi hiện tại không thể đi thẳng tới nghiệm tối ưu, nhưng có thể so sánh được hai nghiệm để biết nghiệm nào tốt hơn, thuật toán sẽ dựa trên một số thông tin phản hồi để sinh ra một nghiệm khả dĩ mới.

Vì vậy, mỗi lần thuật toán leo đồi sẽ tìm một phương án mới ở gần phương án tốt nhất hiện tại $x$. Nếu nghiệm mới $x'$ tốt hơn, chuyển sang $x'$; nếu không thì giữ nguyên.

Thuật toán này phù hợp với hàm đơn đỉnh.

Q: Nếu đã biết là hàm đơn đỉnh thì tại sao không dùng tìm kiếm tam phân?

A: Ưu điểm của leo đồi là trong các tình huống chưa rõ cách viết lời giải chuẩn, thường gặp ở các bài hình học tính toán hoặc toán khó, hoặc khi bản thân trạng thái có nhiều chiều khiến việc viết chia để trị trở nên khó, vẫn có thể tìm nghiệm tối ưu bằng cách tính toán khá brute force. Chẳng hạn, ví dụ 2 bên dưới vẫn có thể dùng nhị phân để có lời giải chuẩn.

Tuy nhiên, với phần lớn các hàm cần giải, thuật toán leo đồi rất dễ rơi vào một nghiệm tối ưu cục bộ, như hình dưới đây. Nghiệm tối ưu là $\color{green}{\Uparrow}$, còn nghiệm tốt nhất mà leo đồi có thể tìm được là $\color{red}{\Downarrow}$.

![](./images/hill-climbing.png)

## Cài đặt cụ thể

Thuật toán leo đồi thường đưa vào một tham số nhiệt độ, tương tự mô phỏng luyện kim. Ở nhiệt độ cao, mỗi lần cập nhật có thể tạo một bước nhảy lớn theo hướng được đánh giá là tốt hơn, dù hướng này chỉ mang tính xấp xỉ. Khi nhiệt độ giảm, độ dài bước nhảy giảm dần, nhờ đó nghiệm hiện tại ổn định hơn và tiến tới điểm tối ưu phù hợp.

Quá trình hạ nhiệt tương ứng với việc tham số nhiệt độ liên tục giảm trong khi leo đồi.

Về hạ nhiệt: hệ số hạ nhiệt là một hằng số hơi nhỏ hơn $1$, thường được chọn trong $[0.985, 0.999]$.

## Ví dụ

???+ example "[JSOI2008 - Bộ sinh không gian hình cầu](https://www.luogu.com.cn/problem/P4035)"
    Cho $n + 1$ điểm trong không gian $n$ chiều. Biết rằng chúng cùng nằm trên một mặt cầu $n$ chiều, cần tìm tâm cầu. $n \leq 10$, trị tuyệt đối của tọa độ không vượt quá $20000$.

??? note "Lời giải"
    Đây là một hàm đơn đỉnh, có thể dùng leo đồi để giải. Quy trình thuật toán của bài này:
    
    1.  Khởi tạo tâm cầu là trọng tâm của các điểm đã cho, tức là ở mỗi chiều, tọa độ của nó bằng trung bình tọa độ tương ứng của tất cả các điểm đã cho, để giảm lượng liệt kê.
    2.  Với tâm cầu hiện tại, tính giá trị trung bình của khoảng cách Euclid từ mỗi điểm đã biết tới tâm này.
    3.  Duyệt tất cả các điểm đã biết. Ghi lại một lượng thay đổi $\textit{cans}$, ghi riêng cho từng chiều. Với khoảng cách Euclid của mỗi điểm, nếu lớn hơn giá trị trung bình thì cộng hiệu vào lượng thay đổi, nếu không thì trừ đi. Không bắt buộc phải xét quan hệ lớn nhỏ này; nếu không xét trị tuyệt đối, có thể tính trực tiếp bằng tọa độ. Quá trình này tương đương việc biến đổi thành một tâm cầu mới rồi điều chỉnh trong không gian: gặp điểm quá xa thì kéo tâm về phía điểm đó một chút, gặp điểm quá gần thì đẩy tâm theo hướng ngược lại điểm đó một chút.
    4.  Nhân $\textit{cans}$ đã ghi lại với nhiệt độ, cập nhật tâm cầu, rồi quay lại bước 2.
    5.  Kết thúc khi nhiệt độ nhỏ hơn một ngưỡng cho trước.
    
    Vì vậy, khi cập nhật tâm cầu, không cộng trực tiếp lượng thay đổi mà phải cộng tích của lượng thay đổi với nhiệt độ.
    
    Không phải mọi bài leo đồi đều có thể giải cụ thể bằng nhiệt độ; đây chỉ là một ví dụ.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/hill-climbing/hill-climbing_1.cpp"
    ```

???+ example "[BZOJ 3680 - Đánh bại XXX](https://hydro.ac/p/bzoj-P3680)"
    Tìm điểm Fermat dạng có trọng số của $n$ điểm.

??? note "Lời giải"
    Khung thuật toán tương tự, có dùng một chút kiến thức vật lý.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/hill-climbing/hill-climbing_2.cpp"
    ```

## Tối ưu hóa

Một cách tự nhiên để cố gắng thu được đáp án tốt hơn là chạy leo đồi nhiều lần. Các cách làm gồm thay đổi trạng thái ban đầu, thay đổi hệ số hạ nhiệt, thay đổi nhiệt độ ban đầu, v.v. Sau đó duy trì một nghiệm tối ưu toàn cục để ghi đáp án. Sau mỗi lần leo đồi kết thúc, cập nhật nghiệm tối ưu toàn cục.

Vấn đề có thể gặp khi làm như vậy là quá thời gian. Trong kỳ thi chính thức, nên tự tạo dữ liệu lớn để kiểm thử và chỉnh tham số.

## Nhược điểm

Nhược điểm của thuật toán leo đồi đã được nhắc ở trên: nó dễ rơi vào một nghiệm tối ưu cục bộ. Khi hàm mục tiêu không phải hàm đơn đỉnh, nhược điểm này có thể trở nên chí mạng. Vì vậy cần đưa vào [**mô phỏng luyện kim**](./simulated-annealing.md).
