Chương này giới thiệu cách tiếp cận của thuật toán ngoại tuyến, các thuật toán thường gặp và những cách tối ưu liên quan.

Thuật toán ngoại tuyến được thiết kế dựa trên giả thiết "**đã biết tất cả dữ liệu trước khi giải**", phù hợp với các bài toán có nhiều truy vấn. Đối lập với nó là [thuật toán trực tuyến](https://en.wikipedia.org/wiki/Online_algorithm).

Ví dụ, [sắp xếp chọn](../basic/selection-sort.md) phải biết phần tử nhỏ nhất toàn cục của mảng mới có thể thực hiện, nên đó là thuật toán ngoại tuyến. Trong khi đó, [sắp xếp chèn](../basic/insertion-sort.md) có thể nhận dữ liệu động để sắp xếp và không bắt buộc phải biết toàn bộ dữ liệu trước khi chạy, nên đó là thuật toán trực tuyến.

Với cùng một bài toán, xét về độ khó khi thiết kế lời giải, thuật toán ngoại tuyến thường dễ hơn thuật toán trực tuyến. Để ngăn thí sinh dùng thuật toán ngoại tuyến, đôi khi đề bài sẽ dùng cơ chế "bắt buộc trực tuyến"; trường hợp phổ biến là cần đáp án của truy vấn trước để tính tham số của truy vấn tiếp theo ([bài tương tác](../contest/problems.md#bai-tuong-tac) và [bài truyền tin](../contest/problems.md#bai-truyen-tin) cũng thuộc nhóm này).

Những hướng tiếp cận thường gặp của thuật toán ngoại tuyến gồm giải các truy vấn một cách tập trung (ví dụ [chia để trị CDQ](./cdq-divide.md)), hoặc suy ra đáp án của một truy vấn từ đáp án của các truy vấn tương tự khác (ví dụ [nhị phân tổng thể](./parallel-binsearch.md) và [thuật toán Mo](./mo-algo-intro.md)).

Vì thuật toán ngoại tuyến là một cách tiếp cận chứ không phải một thuật toán cụ thể, nó thường được kết hợp với nhiều cấu trúc dữ liệu hoặc thuật toán khác nhau; các dạng bài liên quan vì thế cũng phức tạp và đa dạng hơn.
