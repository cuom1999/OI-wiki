Mo hai chiều, đúng như tên gọi, là biến thể trong đó mỗi trạng thái có bốn hướng để mở rộng.

Trong Mo hai chiều, mỗi lần di chuyển con trỏ cần thao tác trên một hàng hoặc một cột các số. Cách hiện thực cụ thể tương tự Mo một chiều thông thường, nên không nhắc lại ở đây. Phần này tập trung vào cách chọn độ dài khối.

## Chọn độ dài khối

Ký hiệu số truy vấn là $q$, tọa độ góc trên trái của ma trận hiện tại là $(x_1,\ y_1)$, tọa độ góc dưới phải là $(x_2,\ y_2)$, và lấy độ dài khối là $B$.

Khi đó con trỏ $x_1$ di chuyển $\Theta(q\cdot B)$ lần, còn con trỏ $y_2$ di chuyển $\Theta(n^4\cdot B^{-3})$ lần.

Vì vậy chỉ cần đặt $q\cdot B=n^4\cdot B^{-3}$, tức $B=n\cdot q^{-\frac 14}$.

Lưu ý rằng giá trị $B$ tính theo cách này **có thể bằng $0$**, cần **xử lý riêng**.

Cuối cùng, độ phức tạp thời gian của phần tính toán là $\Theta(n^2\cdot q^{\frac 34})$. Cộng thêm quá trình sắp xếp truy vấn, tổng độ phức tạp thời gian là $\Theta(n^2\cdot q^{\frac 34}+q\log q)$.

## Ví dụ 1

???+ note "[BZOJ 2639 Tính toán hình chữ nhật](https://hydro.ac/p/bzoj-P2639)"
    Cho một ma trận $n\times m$, mỗi phần tử của ma trận là một số nguyên. Sau đó có $q$ truy vấn, mỗi truy vấn hỏi trọng số của một ma trận con. Trọng số của ma trận được định nghĩa như sau: với một số nguyên $x$, nếu nó xuất hiện $p$ lần trong ma trận đó, thì nó đóng góp $p^2$ vào trọng số của ma trận.

    Giới hạn dữ liệu: $1\leq n,\ m\leq 200$, $0\leq q\leq 10^5$, $|$ giá trị phần tử ma trận $| \leq 2\times 10^9$.

??? note "Ý tưởng lời giải"
    Trước hết rời rạc hóa. Khi chạy Mo hai chiều, chỉ cần dùng một mảng để ghi số lần xuất hiện hiện tại của mỗi giá trị.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/misc/code/mo-algo-2dimen/mo-algo-2dimen_1.cpp"
    ```

## Ví dụ 2

???+ note "[Luogu P1527 \[Đội tuyển quốc gia\] Phép nhân ma trận](https://www.luogu.com.cn/problem/P1527)"
    Cho một ma trận $n\times n$ và $q$ truy vấn, mỗi truy vấn hỏi số nhỏ thứ $k$ trong một hình chữ nhật con.

    Giới hạn dữ liệu: $1\leq n\leq 500$, $1\leq q\leq 6\times 10^4$, $0\leq a_{i,j}\leq 10^9$.

Trước hết, giống bài trước, cần rời rạc hóa toàn bộ ma trận. Tuy nhiên cần chú ý rằng trong bài này, ngoài việc chia khối theo giá trị, ta còn cần chia khối theo miền giá trị để tìm được đáp án.

Ở đây còn cần dùng sắp xếp chẵn lẻ để tối ưu; xem chi tiết tại [thuật toán Mo thông thường](../misc/mo-algo.md#tối-ưu-mo-thông-thường).

Với bài này, giới hạn thời gian không quá rộng, nên cần chú ý hằng số trong mã. Giá trị độ dài khối tính ra thường khá nhỏ; khi $n,\ q$ đều đạt cực đại, độ dài khối xấp xỉ $11$, vì vậy có thể đặt trực tiếp thành hằng số để giảm thời gian chạy của mã.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/misc/code/mo-algo-2dimen/mo-algo-2dimen_2.cpp"
    ```
