Trang này giới thiệu Tim sort (Timsort), một thuật toán sắp xếp lai và ổn định.

## Giới thiệu

Timsort do Tim Peters, một lập trình viên lõi của Python, thiết kế năm 2002 và được áp dụng trong ngôn ngữ Python. Thuật toán này kết hợp khéo léo ưu điểm của sắp xếp chèn và sắp xếp trộn, đồng thời tối ưu rất sát theo mức độ có thứ tự sẵn trong dữ liệu; vì vậy nó đặc biệt phù hợp với các tập dữ liệu chứa nhiều dãy con đã có thứ tự một phần. Từ Python 2.3, Timsort được chọn làm thuật toán sắp xếp mặc định của thư viện chuẩn Python, và cũng được dùng rộng rãi trong các môi trường lập trình khác, chẳng hạn Java SE 7 dùng nó để sắp xếp mảng đối tượng không nguyên thủy.

## Các bước

Ý tưởng cốt lõi của Timsort là nhận diện và tận dụng tính có thứ tự đã tồn tại trong dữ liệu để tăng hiệu quả sắp xếp. Thuật toán chủ yếu gồm các bước sau:

1.  **Nhận diện Run**: Quét mảng cần sắp xếp và nhận diện các dãy con liên tiếp đã có thứ tự (Run).
2.  **Mở rộng Run**: Nếu Run nhận diện được có độ dài nhỏ hơn `MIN_RUN`, dùng sắp xếp chèn để mở rộng Run đó.
3.  **Trộn Run**: Timsort duy trì một ngăn xếp đặc biệt, dùng chiến lược trộn cụ thể để hợp nhất các Run hiện có trong ngăn xếp thành những dãy có thứ tự lớn hơn.

### Nhận diện Run

Trước hết, Timsort quét mảng từ trái sang phải để nhận diện các dãy liên tiếp đã có thứ tự; những dãy này được gọi là Run:

-   **Run tăng dần**: Nếu phần tử sau lớn hơn hoặc bằng phần tử trước, tiếp tục mở rộng Run.
-   **Run giảm dần**: Nếu phần tử sau nhỏ hơn phần tử trước, tiếp tục mở rộng Run, sau đó đảo ngược Run này thành tăng dần.

### Mở rộng Run

Để tăng hiệu quả sắp xếp trên dữ liệu nhỏ, Timsort đưa vào một độ dài Run tối thiểu `MIN_RUN`. Giá trị này thường được tính động theo độ dài mảng cần sắp xếp, thông thường nằm trong khoảng từ $32$ đến $64$.

-   Nếu Run nhận diện được có độ dài lớn hơn hoặc bằng `MIN_RUN`, không cần thao tác bổ sung, trực tiếp đẩy Run vào ngăn xếp.
-   Nếu Run nhận diện được có độ dài nhỏ hơn `MIN_RUN`, dùng sắp xếp chèn nhị phân để chèn các phần tử tiếp theo vào Run cho đến khi độ dài Run đạt `MIN_RUN`, rồi đẩy Run vào ngăn xếp.

### Trộn Run

Trong Timsort, quá trình sắp xếp trộn được quản lý và điều khiển bằng **ngăn xếp**. Ngăn xếp lưu các Run có thứ tự đã được nhận diện, rồi dùng những quy tắc trộn cụ thể để điều khiển việc hợp nhất các Run trong ngăn xếp; mục đích là giữ cho quá trình hợp nhất cân bằng và ổn định.

#### Quy tắc trộn

Timsort là một thuật toán sắp xếp ổn định, tức là các phần tử bằng nhau vẫn giữ thứ tự tương đối ban đầu sau khi sắp xếp. Để bảo đảm điều này, khi trộn, Timsort chỉ hợp nhất các Run kề nhau và liên tiếp, chứ không trực tiếp hợp nhất các Run không kề nhau. Lý do là giữa các Run không kề nhau có thể tồn tại những phần tử bằng nhau; nếu trộn trực tiếp, thứ tự tương đối của chúng rất dễ bị phá vỡ.

Đồng thời, để bảo đảm tính cân bằng của quá trình hợp nhất, Timsort đưa vào các quy tắc trộn cụ thể. Trước mỗi thao tác hợp nhất, thuật toán kiểm tra ba Run ở đỉnh ngăn xếp là X, Y và Z để bảo đảm thỏa mãn hai điều kiện sau:

-   **Điều kiện 1**: `len(Z) > len(Y) + len(X)`
-   **Điều kiện 2**: `len(Y) > len(X)`

Nếu ba Run ở đỉnh ngăn xếp không thỏa mãn các điều kiện trên, Timsort sẽ hợp nhất Y với Run nhỏ hơn trong X và Z, rồi kiểm tra lại điều kiện. Khi các điều kiện đã thỏa mãn, thuật toán tiếp tục tìm Run mới, thêm nó vào ngăn xếp và bắt đầu vòng trộn tiếp theo.

![Merge Rules](./images/tim-sort-1.png)

#### Tối ưu hóa quá trình trộn

Để tăng hiệu quả và giảm chi phí bộ nhớ khi trộn các Run có độ dài khác nhau, trước khi trộn, Timsort dùng tìm kiếm nhị phân để xác định chính xác phạm vi phần tử cần xử lý, chỉ trộn phần thật sự cần di chuyển. Cách làm cụ thể như sau:

1.  **Xác định điểm chèn**: Dùng tìm kiếm nhị phân để tìm vị trí chèn của phần tử đầu tiên của Run thứ hai trong Run thứ nhất, cũng như vị trí chèn của phần tử cuối cùng của Run thứ nhất trong Run thứ hai. Nhờ vậy có thể thu hẹp phạm vi cần trộn và chỉ xử lý các phần tử cần di chuyển.

2.  **Bộ đệm tạm thời**: Các thuật toán hợp nhất tại chỗ truyền thống có hiệu quả thấp và cần di chuyển rất nhiều phần tử. Để giảm chi phí này, Timsort dùng một bộ đệm tạm thời, sao chép Run ngắn hơn vào bộ đệm, rồi dần sao chép các phần tử từ bộ đệm trở lại mảng ban đầu.

Ví dụ, giả sử có hai Run A và B lần lượt là:

-   Run A: $[1, 2, 3, 6, 10]$
-   Run B: $[4, 5, 7, 9, 12, 14, 17]$

Thông qua tìm kiếm nhị phân, có thể xác định:

-   Phần tử $4$ nên được chèn vào vị trí thứ tư của Run A.
-   Phần tử $10$ nên được chèn vào vị trí thứ năm của Run B.

Do đó, $3$ phần tử đầu của Run A và $3$ phần tử cuối của Run B đã ở đúng vị trí, không cần xử lý. Ta chỉ cần trộn $[6, 10]$ của Run A với $[4, 5, 7, 9]$ của Run B; quá trình trộn được minh họa như hình sau:

![Timsort Merge](./images/tim-sort-2.apng)

#### Chế độ tăng tốc

Để tiếp tục nâng cao hiệu quả trộn, Timsort đưa vào **chế độ tăng tốc (Galloping Mode)**. Trong quá trình trộn chuẩn, thuật toán so sánh từng phần tử của hai Run và đưa phần tử nhỏ hơn vào mảng kết quả. Tuy nhiên, nếu một phía của Run có nhiều phần tử liên tiếp nhỏ hơn phần tử hiện tại của phía còn lại, việc so sánh từng phần tử sẽ gây chi phí không cần thiết.

Để xử lý vấn đề này, Timsort đặt một ngưỡng `Min_Gallop` (giá trị mặc định là $7$). Khi các phần tử ở một phía Run thắng liên tiếp trong so sánh với số lần đạt `Min_Gallop`, thuật toán chuyển sang chế độ tăng tốc để định vị nhanh vị trí phần tử. Các bước cụ thể như sau:

1.  **Tìm kiếm lũy tiến**: Từ vị trí hiện tại, thuật toán tìm trong một phía Run với bước nhảy tăng theo lũy thừa $(1, 2, 4, 8, \dots)$ cho đến khi tìm được một khoảng chứa phần tử mục tiêu.
2.  **Tìm kiếm nhị phân**: Sau khi xác định được khoảng chứa phần tử mục tiêu, thuật toán dùng tìm kiếm nhị phân trong khoảng đó để định vị chính xác vị trí của phần tử mục tiêu.

Bằng cách này, Timsort có thể bỏ qua rất nhiều phép so sánh không cần thiết, nhanh chóng xử lý các phần tử liên tiếp nhỏ hơn (hoặc lớn hơn) trong một phía Run và chuyển hàng loạt chúng vào kết quả hợp nhất.

Tuy nhiên, chế độ tăng tốc không phải lúc nào cũng hiệu quả hơn. Với một số phân bố dữ liệu, chế độ tăng tốc có thể làm tăng số lần so sánh. Vì vậy, Timsort dùng chiến lược điều chỉnh động:

-   **Điều chỉnh ngưỡng**: Duy trì một tham số `Min_Gallop` có thể thay đổi. Khi chế độ tăng tốc hoạt động tốt (tức là liên tiếp chọn phần tử nhiều lần từ cùng một Run), `Min_Gallop` giảm $1$ để khuyến khích tiếp tục dùng chế độ tăng tốc; khi chế độ tăng tốc hoạt động không tốt (thường xuyên chuyển qua lại giữa hai Run), `Min_Gallop` tăng $1$ để giảm tần suất dùng chế độ tăng tốc.

Bằng cách điều chỉnh động giá trị `Min_Gallop`, thuật toán có thể cân bằng giữa chế độ trộn thông thường và chế độ tăng tốc tùy theo dữ liệu thực tế. Với dữ liệu có thứ tự một phần hoặc có mức độ có thứ tự cao, chế độ tăng tốc có thể cải thiện hiệu quả rõ rệt, khiến hiệu năng của Timsort tiến gần $O(n)$; còn với dữ liệu ngẫu nhiên, thuật toán sẽ dần nghiêng về trộn thông thường để bảo đảm độ phức tạp thời gian $O(n \log n)$.

## Độ phức tạp

Độ phức tạp thời gian của Timsort phụ thuộc vào mức độ có thứ tự của dữ liệu:

-   **Trường hợp tốt nhất**: $O(n)$
    -   Khi dữ liệu đã có thứ tự hoặc gần như có thứ tự, các Run mà thuật toán nhận diện được có độ dài gần $n$, số lần trộn giảm, và độ phức tạp tiến gần $O(n)$.
-   **Trường hợp xấu nhất**: $O(n \log n)$
    -   Khi dữ liệu hoàn toàn không có thứ tự, độ dài của mỗi Run đều gần $1$, do đó cần $O(\log n)$ lần trộn; mỗi lần trộn có chi phí $O(n)$, nên tổng độ phức tạp là $O(n \log n)$.

**Chứng minh**:

-   **Nhận diện và mở rộng Run**:
    -   Nhận diện Run cần duyệt tuyến tính mảng một lần, độ phức tạp là $O(n)$.
    -   Dùng sắp xếp chèn để mở rộng Run cũng cần duyệt tuyến tính mảng, độ phức tạp là $O(n)$.

-   **Trộn Run**:
    -   Tổng số thao tác trộn liên quan đến tổng số Run. Trong trường hợp xấu nhất, số Run là `n / MIN_RUN`; vì `MIN_RUN` là hằng số, số Run có thể xem là $O(n)$.
    -   Với $O(n)$ Run, số lần trộn cần thực hiện là $O(\log n)$; mỗi thao tác trộn có chi phí $O(n)$, nên tổng độ phức tạp của các thao tác trộn là $O(n \log n)$.

Về độ phức tạp bộ nhớ, do Timsort nhìn chung cần thêm $O(n)$ không gian để lưu ngăn xếp và bộ đệm tạm thời, tổng độ phức tạp bộ nhớ là $O(n)$.

## Cài đặt

???+ note "Cài đặt bằng mã giả"
    $$
    \begin{array}{ll}
    1 & nRemaining \gets \text{độ dài mảng} \\
    2 & minRun \gets \text{chọn giá trị MinRun phù hợp}(nRemaining) \\
    3 & startIndex \gets 0 \\
    4 & \textbf{while } nRemaining > 0 \ \textbf{do} \\
    5 & \qquad runLength \gets \text{nhận diện Run }(array, startIndex, nRemaining) \\
    6 & \qquad \textbf{if } runLength < minRun \ \textbf{then} \\
    7 & \qquad \qquad extendLength \gets \min(minRun, nRemaining) \\
    8 & \qquad \qquad \text{dùng sắp xếp chèn để mở rộng đoạn } [startIndex, startIndex + extendLength - 1]\\
    9 & \qquad \qquad runLength \gets extendLength \\
    10 & \qquad \textbf{end if} \\
    11 & \qquad \text{đẩy Run } (startIndex, runLength) \text{ vào ngăn xếp} \\
    12 & \qquad \textbf{gọi } \text{mergeCollapse(ngăn xếp)} \ \text{để kiểm tra và hợp nhất các Run trong ngăn xếp} \\
    13 & \qquad startIndex \gets startIndex + runLength \ \text{cập nhật vị trí bắt đầu} \\
    14 & \qquad nRemaining \gets nRemaining - runLength \ \text{cập nhật độ dài còn lại} \\
    15 & \textbf{end while} \\
    16 & \textbf{gọi } \text{mergeForceCollapse(ngăn xếp)} \ \text{để hợp nhất lần cuối tất cả Run trong ngăn xếp} \\
    \end{array}
    $$

## Tài liệu tham khảo

1.  [Timsort](https://en.wikipedia.org/wiki/Timsort)
2.  [On the Worst-Case Complexity of TimSort](https://drops.dagstuhl.de/opus/volltexte/2018/9467/pdf/LIPIcs-ESA-2018-4.pdf)
3.  [Original Explanation by Tim Peters](https://github.com/python/cpython/blob/main/Objects/listsort.txt)
4.  [Cài đặt Java](https://cs.android.com/android/platform/superproject/main/+/main:libcore/ojluni/src/main/java/java/util/TimSort.java)
5.  [Cài đặt ngôn ngữ C](https://github.com/python/cpython/blob/main/Objects/listobject.c)
