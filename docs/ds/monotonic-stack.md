## Giới thiệu

Ngăn xếp đơn điệu là gì? Đúng như tên gọi, ngăn xếp đơn điệu là một cấu trúc ngăn xếp thỏa mãn tính đơn điệu. So với hàng đợi đơn điệu, nó chỉ thực hiện thao tác đưa vào và lấy ra ở một đầu.

Để tiện mô tả, các ví dụ và mã giả dưới đây lấy việc duy trì một ngăn xếp số nguyên đơn điệu tăng làm ví dụ.

## Quá trình

### Chèn

Khi chèn một phần tử vào ngăn xếp đơn điệu, để duy trì tính đơn điệu của ngăn xếp, ta cần bật ra số phần tử ít nhất sao cho sau khi đưa phần tử đó lên đỉnh, toàn bộ ngăn xếp vẫn thỏa mãn tính đơn điệu.

Ví dụ, các phần tử trong ngăn xếp từ đỉnh xuống đáy là $\{0,11,45,81\}$.

![](images/monotonic-stack-before.svg)

Khi chèn phần tử $14$, để bảo đảm tính đơn điệu, cần lần lượt bật ra các phần tử $0,11$; sau thao tác, ngăn xếp trở thành $\{14,45,81\}$.

![](images/monotonic-stack-after.svg)

Dùng mã giả có thể mô tả như sau:

???+ note "Cài đặt"
    ```text
    insert x
    while !sta.empty() && sta.top()<x
        sta.pop()
    sta.push(x)
    ```

### Sử dụng

Ta đọc phần tử ở đỉnh ngăn xếp; phần tử này chính là một đầu theo tính đơn điệu.

Chẳng hạn trong ví dụ trên, phần tử lấy ra chính là giá trị nhỏ nhất trong ngăn xếp.

## Ứng dụng

??? note "[POJ3250 Bad Hair Day](http://poj.org/problem?id=3250)"
    Có $N$ con bò xếp thành một hàng từ trái sang phải, mỗi con bò có chiều cao $h_i$. Gọi $c_i$ là số con bò nằm giữa con bò thứ $i$ tính từ trái sang và "con bò đầu tiên ở bên phải nó có chiều cao $≥h_i$". Hãy tính $\sum_{i=1}^{N} c_i$.

Một ứng dụng khá cơ bản là bài này: chỉ cần dùng ngăn xếp đơn điệu một cách đơn giản, ghi lại vị trí mà mỗi con bò bị bật ra; nếu chưa từng bị bật ra thì xem như tới đầu xa nhất. Xử lý thêm một chút là có thể tính được kết quả bài toán yêu cầu.

Ngoài ra, ngăn xếp đơn điệu cũng có thể dùng để giải bài toán RMQ theo kiểu offline.

Ta có thể sắp xếp tất cả truy vấn theo đầu mút phải, sau đó mỗi lần quét dãy từ trái sang phải tới đầu mút phải của truy vấn hiện tại và chèn các phần tử đã quét vào ngăn xếp đơn điệu. Như vậy, mỗi khi trả lời truy vấn, các giá trị được lưu trong ngăn xếp đơn điệu đều là những điểm quyết định có vị trí $\le r$ và có khả năng trở thành đáp án, đồng thời các phần tử này thỏa mãn tính đơn điệu. Khi đó, phần tử đầu tiên trên ngăn xếp đơn điệu có vị trí $\ge l$ chính là đáp án của truy vấn hiện tại; bước này có thể thực hiện bằng tìm kiếm nhị phân. Dùng ngăn xếp đơn điệu để giải RMQ có độ phức tạp thời gian $O(q\log q + q\log n)$ và độ phức tạp bộ nhớ $O(n)$.

## Bài tập

-   [Luogu P5788【Mẫu】Ngăn xếp đơn điệu](https://www.luogu.com.cn/problem/P5788)
-   [Luogu P1901 Trạm phát](https://www.luogu.com.cn/problem/P1901)
