Trang này giới thiệu Tim sort (Timsort), một thuật toán sắp xếp lai và ổn định.

## Giới thiệu

Timsort do Tim Peters, một lập trình viên lõi của Python, thiết kế năm 2002 và
được áp dụng trong ngôn ngữ Python. Thuật toán này kết hợp ưu điểm của sắp xếp
chèn và sắp xếp trộn, đồng thời tận dụng rất tốt mức độ có thứ tự sẵn trong dữ
liệu; vì vậy nó đặc biệt phù hợp với các tập dữ liệu chứa nhiều dãy con đã có
thứ tự một phần. Từ Python 2.3, Timsort được chọn làm thuật toán sắp xếp mặc
định của thư viện chuẩn Python, và cũng được dùng rộng rãi trong các môi trường
lập trình khác, chẳng hạn Java SE 7 dùng nó để sắp xếp mảng đối tượng không
nguyên thủy.

## Các bước

Ý tưởng cốt lõi của Timsort là nhận diện và tận dụng tính có thứ tự đã tồn tại
trong dữ liệu để tăng hiệu quả sắp xếp. Thuật toán chủ yếu gồm các bước sau:

1.  **Nhận diện đoạn đã có thứ tự**: Quét mảng cần sắp xếp và nhận diện các dãy con liên tiếp đã có thứ tự.
2.  **Mở rộng đoạn đã có thứ tự**: Nếu đoạn nhận diện được có độ dài nhỏ hơn `MIN_RUN`, dùng sắp xếp chèn để mở rộng đoạn đó.
3.  **Trộn đoạn đã có thứ tự**: Timsort duy trì một ngăn xếp đặc biệt và dùng
    chiến lược trộn cụ thể để hợp nhất các đoạn hiện có trong ngăn xếp thành
    những dãy có thứ tự lớn hơn.

### Nhận diện đoạn đã có thứ tự

Trước hết, Timsort quét mảng từ trái sang phải để nhận diện các dãy liên tiếp
đã có thứ tự; những dãy này được gọi là đoạn đã có thứ tự:

-   **Đoạn tăng dần**: Nếu phần tử sau lớn hơn hoặc bằng phần tử trước, tiếp tục mở rộng đoạn.
-   **Đoạn giảm dần**: Nếu phần tử sau nhỏ hơn phần tử trước, tiếp tục mở rộng đoạn, sau đó đảo ngược đoạn này thành tăng dần.

### Mở rộng đoạn đã có thứ tự

Để tăng hiệu quả sắp xếp trên dữ liệu nhỏ, Timsort đưa vào một độ dài đoạn tối
thiểu `MIN_RUN`. Giá trị này thường được tính động theo độ dài mảng cần sắp
xếp, thông thường nằm trong khoảng từ $32$ đến $64$.

-   Nếu đoạn nhận diện được có độ dài lớn hơn hoặc bằng `MIN_RUN`, không cần thao tác bổ sung, trực tiếp đẩy đoạn vào ngăn xếp.
-   Nếu đoạn nhận diện được có độ dài nhỏ hơn `MIN_RUN`, dùng sắp xếp chèn nhị
    phân để chèn các phần tử tiếp theo vào đoạn cho đến khi độ dài đoạn đạt
    `MIN_RUN`, rồi đẩy đoạn vào ngăn xếp.

### Trộn đoạn đã có thứ tự

Trong Timsort, quá trình sắp xếp trộn được quản lý và điều khiển bằng **ngăn
xếp**. Ngăn xếp lưu các đoạn có thứ tự đã được nhận diện, rồi dùng những quy
tắc trộn cụ thể để điều khiển việc hợp nhất các đoạn trong ngăn xếp; mục đích
là giữ cho quá trình hợp nhất cân bằng và ổn định.

#### Quy tắc trộn

Timsort là một thuật toán sắp xếp ổn định, tức là các phần tử bằng nhau vẫn giữ
thứ tự tương đối ban đầu sau khi sắp xếp. Để bảo đảm điều này, khi trộn,
Timsort chỉ hợp nhất các đoạn kề nhau và liên tiếp, chứ không trực tiếp hợp
nhất các đoạn không kề nhau. Lý do là giữa các đoạn không kề nhau có thể tồn
tại những phần tử bằng nhau; nếu trộn trực tiếp, thứ tự tương đối của chúng rất
dễ bị phá vỡ.

Đồng thời, để bảo đảm tính cân bằng của quá trình hợp nhất, Timsort đưa vào các
quy tắc trộn cụ thể. Trước mỗi thao tác hợp nhất, thuật toán kiểm tra ba đoạn ở
đỉnh ngăn xếp là X, Y và Z để bảo đảm thỏa mãn hai điều kiện sau:

-   **Điều kiện 1**: `len(Z) > len(Y) + len(X)`
-   **Điều kiện 2**: `len(Y) > len(X)`

Nếu ba đoạn ở đỉnh ngăn xếp không thỏa mãn các điều kiện trên, Timsort sẽ hợp
nhất Y với đoạn nhỏ hơn trong X và Z, rồi kiểm tra lại điều kiện. Khi các điều
kiện đã thỏa mãn, thuật toán tiếp tục tìm đoạn mới, thêm nó vào ngăn xếp và bắt
đầu vòng trộn tiếp theo.

![Quy tắc trộn](./images/tim-sort-1.png)

#### Tối ưu hóa quá trình trộn

Để tăng hiệu quả và giảm chi phí bộ nhớ khi trộn các đoạn có độ dài khác nhau,
trước khi trộn, Timsort dùng tìm kiếm nhị phân để xác định chính xác phạm vi
phần tử cần xử lý, chỉ trộn phần thật sự cần di chuyển. Cách làm cụ thể như
sau:

1.  **Xác định điểm chèn**: Dùng tìm kiếm nhị phân để tìm vị trí chèn của phần
    tử đầu tiên của đoạn thứ hai trong đoạn thứ nhất, cũng như vị trí chèn của
    phần tử cuối cùng của đoạn thứ nhất trong đoạn thứ hai. Nhờ vậy có thể thu
    hẹp phạm vi cần trộn và chỉ xử lý các phần tử cần di chuyển.

2.  **Bộ đệm tạm thời**: Các thuật toán hợp nhất tại chỗ truyền thống có hiệu
    quả thấp và cần di chuyển rất nhiều phần tử. Để giảm chi phí này, Timsort
    dùng một bộ đệm tạm thời, sao chép đoạn ngắn hơn vào bộ đệm, rồi dần sao
    chép các phần tử từ bộ đệm trở lại mảng ban đầu.

Ví dụ, giả sử có hai đoạn A và B lần lượt là:

-   Đoạn A: $[1, 2, 3, 6, 10]$
-   Đoạn B: $[4, 5, 7, 9, 12, 14, 17]$

Thông qua tìm kiếm nhị phân, có thể xác định:

-   Phần tử $4$ nên được chèn vào vị trí thứ tư của đoạn A.
-   Phần tử $10$ nên được chèn vào vị trí thứ năm của đoạn B.

Do đó, $3$ phần tử đầu của đoạn A và $3$ phần tử cuối của đoạn B đã ở đúng vị
trí, không cần xử lý. Chỉ cần trộn $[6, 10]$ của đoạn A với $[4, 5, 7, 9]$ của
đoạn B; quá trình trộn được minh họa như hình sau:

![Quá trình trộn trong Timsort](./images/tim-sort-2.apng)

#### Chế độ galloping

Để tiếp tục nâng cao hiệu quả trộn, Timsort đưa vào **chế độ phi nước đại**
(galloping). Trong quá trình trộn chuẩn, thuật toán so sánh từng phần tử của hai
đoạn và đưa phần tử nhỏ hơn vào mảng kết quả. Tuy nhiên, nếu một phía có nhiều
phần tử liên tiếp nhỏ hơn phần tử hiện tại của phía còn lại, việc so sánh từng
phần tử sẽ gây chi phí không cần thiết.

Để xử lý vấn đề này, Timsort đặt một ngưỡng `Min_Gallop` (giá trị mặc định là
$7$). Khi các phần tử ở một phía thắng liên tiếp trong số lần so sánh đạt
`Min_Gallop`, thuật toán chuyển sang chế độ galloping để định vị nhanh vị trí
phần tử. Các bước cụ thể như sau:

1.  **Tìm kiếm mũ**: Từ vị trí hiện tại, thuật toán tìm trong một phía
    với bước nhảy tăng theo lũy thừa $(1, 2, 4, 8, \dots)$ cho đến khi tìm được
    một khoảng chứa phần tử mục tiêu.
2.  **Tìm kiếm nhị phân**: Sau khi xác định được khoảng chứa phần tử mục tiêu,
    thuật toán dùng tìm kiếm nhị phân trong khoảng đó để định vị chính xác vị
    trí của phần tử mục tiêu.

Bằng cách này, Timsort có thể bỏ qua rất nhiều phép so sánh không cần thiết,
nhanh chóng xử lý các phần tử liên tiếp nhỏ hơn (hoặc lớn hơn) trong một phía
và chuyển hàng loạt chúng vào kết quả hợp nhất.

Tuy nhiên, chế độ galloping không phải lúc nào cũng hiệu quả hơn. Với một số
phân bố dữ liệu, chế độ galloping có thể làm tăng số lần so sánh. Vì vậy,
Timsort dùng chiến lược điều chỉnh động:

-   **Điều chỉnh ngưỡng**: Duy trì một tham số `Min_Gallop` có thể thay đổi.
    Khi chế độ galloping hoạt động tốt (tức là liên tiếp chọn phần tử nhiều lần
    từ cùng một đoạn), `Min_Gallop` giảm $1$ để khuyến khích tiếp tục dùng chế
    độ galloping; khi chế độ galloping hoạt động không tốt (thường xuyên chuyển
    qua lại giữa hai đoạn), `Min_Gallop` tăng $1$ để giảm tần suất dùng chế độ
    galloping.

Bằng cách điều chỉnh động giá trị `Min_Gallop`, thuật toán có thể cân bằng giữa
chế độ trộn thông thường và chế độ galloping tùy theo dữ liệu thực tế. Với dữ
liệu có thứ tự một phần hoặc có mức độ có thứ tự cao, chế độ galloping có thể
cải thiện hiệu quả rõ rệt, khiến hiệu năng của Timsort tiến gần $O(n)$; còn với
dữ liệu ngẫu nhiên, thuật toán sẽ dần nghiêng về trộn thông thường để bảo đảm
độ phức tạp thời gian $O(n \log n)$.

## Độ phức tạp

Độ phức tạp thời gian của Timsort phụ thuộc vào mức độ có thứ tự của dữ liệu:

-   **Trường hợp tốt nhất**: $O(n)$
    -   Khi dữ liệu đã có thứ tự hoặc gần như có thứ tự, các đoạn mà thuật toán
        nhận diện được có độ dài gần $n$, số lần trộn giảm, và độ phức tạp tiến
        gần $O(n)$.
-   **Trường hợp xấu nhất**: $O(n \log n)$
    -   Khi dữ liệu hoàn toàn không có thứ tự, độ dài của mỗi đoạn đều gần $1$,
        do đó cần $O(\log n)$ lần trộn; mỗi lần trộn có chi phí $O(n)$, nên
        tổng độ phức tạp là $O(n \log n)$.

**Chứng minh**:

-   **Nhận diện và mở rộng đoạn**:
    -   Nhận diện đoạn cần duyệt tuyến tính mảng một lần, độ phức tạp là
        $O(n)$.
    -   Dùng sắp xếp chèn để mở rộng đoạn cũng cần duyệt tuyến tính mảng, độ
        phức tạp là $O(n)$.

-   **Trộn đoạn**:
    -   Tổng số thao tác trộn liên quan đến tổng số đoạn. Trong trường hợp xấu
        nhất, số đoạn là `n / MIN_RUN`; vì `MIN_RUN` là hằng số, số đoạn có thể
        xem là $O(n)$.
    -   Với $O(n)$ đoạn, số lần trộn cần thực hiện là $O(\log n)$; mỗi thao tác
        trộn có chi phí $O(n)$, nên tổng độ phức tạp của các thao tác trộn là
        $O(n \log n)$.

Về độ phức tạp bộ nhớ, do Timsort nhìn chung cần thêm $O(n)$ không gian để lưu
ngăn xếp và bộ đệm tạm thời, tổng độ phức tạp bộ nhớ là $O(n)$.

## Cài đặt

???+ note "Cài đặt bằng mã giả"
    $$
    \begin{array}{ll}
    1 & nRemaining \gets \text{độ dài mảng} \\
    2 & minRun \gets \text{chọn giá trị MinRun phù hợp}(nRemaining) \\
    3 & startIndex \gets 0 \\
    4 & \textbf{trong khi } nRemaining > 0 \ \textbf{thực hiện} \\
    5 & \qquad runLength \gets \text{nhận diện đoạn }(array, startIndex, nRemaining) \\
    6 & \qquad \textbf{nếu } runLength < minRun \ \textbf{thì} \\
    7 & \qquad \qquad extendLength \gets \min(minRun, nRemaining) \\
    8 & \qquad \qquad \text{dùng sắp xếp chèn để mở rộng đoạn } [startIndex, startIndex + extendLength - 1]\\
    9 & \qquad \qquad runLength \gets extendLength \\
    10 & \qquad \textbf{kết thúc nếu} \\
    11 & \qquad \text{đẩy đoạn } (startIndex, runLength) \text{ vào ngăn xếp} \\
    12 & \qquad \textbf{gọi } \text{mergeCollapse(ngăn xếp)} \ \text{để kiểm tra và hợp nhất các đoạn trong ngăn xếp} \\
    13 & \qquad startIndex \gets startIndex + runLength \ \text{cập nhật vị trí bắt đầu} \\
    14 & \qquad nRemaining \gets nRemaining - runLength \ \text{cập nhật độ dài còn lại} \\
    15 & \textbf{kết thúc vòng lặp} \\
    16 & \textbf{gọi } \text{mergeForceCollapse(ngăn xếp)} \ \text{để hợp nhất lần cuối tất cả đoạn trong ngăn xếp} \\
    \end{array}
    $$

## Tài liệu tham khảo

1.  [Timsort](https://en.wikipedia.org/wiki/Timsort)
2.  [On the Worst-Case Complexity of TimSort](https://drops.dagstuhl.de/opus/volltexte/2018/9467/pdf/LIPIcs-ESA-2018-4.pdf)
3.  [Original Explanation by Tim Peters](https://github.com/python/cpython/blob/main/Objects/listsort.txt)
4.  [Cài đặt Java](https://cs.android.com/android/platform/superproject/main/+/main:libcore/ojluni/src/main/java/java/util/TimSort.java)
5.  [Cài đặt ngôn ngữ C](https://github.com/python/cpython/blob/main/Objects/listobject.c)
