author: StudyingFather, Backl1ght, countercurrent-time, Ir1d, greyqz, MicDZ, ouuan, YOYO-UIAT

## Giới thiệu

Trong một số bài toán, khi chuyển trạng thái giữa các đoạn, có thể thao tác thêm hoặc xóa không hiện thực được. Khi chỉ thao tác thêm không hiện thực được, hoặc chỉ thao tác xóa không hiện thực được, ta có thể dùng Mo rollback để giải trong thời gian $O(n \sqrt m)$. Ý tưởng cốt lõi của Mo rollback là: nếu chỉ hiện thực được một thao tác, thì chỉ dùng thao tác đó, phần còn lại giao cho cơ chế rollback xử lý.

Mo rollback được chia thành loại chỉ dùng thao tác thêm và loại chỉ dùng thao tác xóa. Phần dưới chỉ giới thiệu Mo rollback chỉ dùng thao tác thêm; loại chỉ dùng thao tác xóa chỉ khác đôi chút trong hiện thực thuật toán, nên không trình bày thêm.

## Ví dụ [JOISC 2014 Day1 Historical Research](https://loj.ac/problem/2874)

Cho một mảng $A$ độ dài $n$ và $m$ truy vấn $(1 \leq n, m \leq 10^5)$. Mỗi truy vấn hỏi số có độ quan trọng lớn nhất trong đoạn $[L, R]$, và yêu cầu **in ra độ quan trọng đó**. Độ quan trọng của một số $i$ được định nghĩa là $i$ nhân với số lần $i$ xuất hiện trong đoạn.

Trong bài toán này, cập nhật đáp án khi thêm phần tử rất dễ hiện thực, nhưng cập nhật đáp án khi xóa phần tử lại khó. Nếu thao tác thêm làm thay đổi đáp án, đáp án mới chắc chắn là độ quan trọng của số vừa được thêm. Còn nếu sau khi xóa, số có độ quan trọng lớn nhất trong đoạn thay đổi, ta khó xác định số mới có độ quan trọng lớn nhất là số nào. Vì vậy Mo thông thường khó giải được bài này.

## Quy trình

-   Chia khối dãy ban đầu, rồi sắp xếp các truy vấn với khóa thứ nhất là chỉ số khối chứa đầu trái theo thứ tự tăng dần, khóa thứ hai là đầu phải theo thứ tự tăng dần.
-   Xử lý các truy vấn theo thứ tự:
    -   Nếu khối $B$ chứa đầu trái của truy vấn khác khối chứa đầu trái của truy vấn trước đó, khởi tạo đầu trái của đoạn Mo bằng đầu phải của khối $B$ cộng $1$, và khởi tạo đầu phải của đoạn Mo bằng đầu phải của khối $B$.
    -   Nếu hai đầu mút của truy vấn nằm trong cùng một khối, quét trực tiếp đoạn để trả lời truy vấn.
    -   Nếu hai đầu mút của truy vấn nằm trong hai khối khác nhau:
        -   Nếu đầu phải của truy vấn lớn hơn đầu phải của đoạn Mo, liên tục mở rộng đầu phải cho đến khi đầu phải của đoạn Mo bằng đầu phải của truy vấn.
        -   Liên tục mở rộng đầu trái của đoạn Mo cho đến khi đầu trái của đoạn Mo bằng đầu trái của truy vấn.
        -   Trả lời truy vấn.
        -   Hủy các thay đổi trên đầu trái của đoạn Mo, để đầu trái rollback về đầu phải của khối $B$ cộng $1$.

## Chứng minh độ phức tạp

Giả sử kích thước khối của Mo rollback là $b$:

-   Với truy vấn có đầu trái và đầu phải nằm trong cùng một khối, có thể tính trong thời gian $O(b)$.
-   Với các truy vấn còn lại, xét các truy vấn có đầu trái nằm trong cùng một khối. Đầu phải của chúng tăng đơn điệu, nên độ phức tạp để di chuyển đầu phải là $O(n)$; còn đầu trái của mỗi truy vấn di chuyển không quá $b$. Vì có $\frac{n}{b}$ khối, tổng độ phức tạp là $O(mb+\frac{n^2}{b})$. Lấy $b=\frac{n}{\sqrt{m}}$ là tối ưu, cho độ phức tạp thời gian $O(n\sqrt{m})$.

## Hiện thực

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/rollback-mo-algo/rollback-mo-algo_1.cpp"
    ```

## Tài liệu tham khảo

-   [Mo rollback và ứng dụng đơn giản | Parsnip's Blog](https://www.cnblogs.com/Parsnip/p/10969989.html)
