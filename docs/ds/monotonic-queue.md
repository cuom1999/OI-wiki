author: Link-cute, Xeonacid, ouuan, Alphnia, Lyccrius

## Giới thiệu

Trước khi vào hàng đợi đơn điệu, xét một bài ví dụ.

???+ note "Ví dụ"
    [Sliding Window](http://poj.org/problem?id=2823)
    
    Nội dung chính của bài là: cho một mảng độ dài $n$, viết chương trình in ra
    giá trị lớn nhất và nhỏ nhất trong mỗi đoạn gồm $k$ số liên tiếp.

Cách vét cạn rất đơn giản: với mỗi đoạn $i \sim i+k-1$, so sánh từng phần tử để
tìm giá trị lớn nhất (và nhỏ nhất), độ phức tạp thời gian khoảng
$O(n \times k)$.

Cách này thực hiện rất nhiều công việc lặp lại. Ngoài $k-1$ số ở đầu và
$k-1$ số ở cuối, mỗi số đều bị so sánh $k$ lần; trong khi $100\%$ dữ liệu của
bài có $n \le 1000000$, nên khi $k$ tương đối lớn thì chắc chắn sẽ TLE.

Lúc này cần dùng hàng đợi đơn điệu.

## Định nghĩa

Đúng như tên gọi, trọng tâm của hàng đợi đơn điệu nằm ở hai phần: "đơn điệu"
và "hàng đợi".

"Đơn điệu" chỉ quy luật của các phần tử: tăng dần (hoặc giảm dần).

"Hàng đợi" nghĩa là các phần tử chỉ được thao tác ở đầu hàng đợi và cuối hàng đợi.

Lưu ý rằng "hàng đợi" trong hàng đợi đơn điệu có một số khác biệt so với hàng đợi
thông thường; phần sau sẽ nhắc tới.

## Phân tích ví dụ

### Giải thích

Với khái niệm "hàng đợi đơn điệu" ở trên, có thể dùng nó để tối ưu.

Cần tìm giá trị lớn nhất (nhỏ nhất) trong mỗi $k$ số liên tiếp. Khi một số đi
vào phạm vi đang "tìm" giá trị lớn nhất, nếu số này lớn hơn những số đứng trước
nó (vào hàng đợi trước), thì các số phía trước sẽ rời hàng đợi trước số này và
không còn khả năng trở thành giá trị lớn nhất nữa.

Nói cách khác, khi thỏa mãn điều kiện trên, có thể "bật ra" các số phía trước,
rồi mới thật sự push số hiện tại vào cuối hàng đợi.

Điều này tương đương với việc duy trì một hàng đợi giảm dần, phù hợp với định
nghĩa hàng đợi đơn điệu và giảm số lần so sánh lặp lại. Hơn nữa, vì hàng đợi
được duy trì chỉ gồm các phần tử trong phạm vi truy vấn và đang giảm dần, đầu
hàng đợi chắc chắn là giá trị lớn nhất trong vùng truy vấn, nên khi in kết quả
chỉ cần in đầu hàng đợi.

Trong thuật toán này, mỗi số chỉ vào hàng đợi và ra khỏi hàng đợi nhiều nhất một lần,
vì vậy độ phức tạp thời gian giảm xuống $O(n)$.

Do độ dài đoạn truy vấn là cố định, một giá trị dù lớn đến đâu cũng không được
in nếu đã vượt ra ngoài phạm vi truy vấn. Vì vậy, còn cần mảng `site` ghi lại
vị trí trong mảng gốc của phần tử thứ $i$ trong hàng đợi, để bật ra đầu hàng
đợi đã nằm ngoài phạm vi.

### Quá trình

Ví dụ, quá trình xây dựng một hàng đợi đơn điệu tăng như sau:

Dãy ban đầu là:

```text
1 3 -1 -3 5 3 6 7
```

Vì cần luôn duy trì tính chất **tăng dần** của hàng đợi, các thao tác sẽ diễn ra
như sau (giả sử $k = 3$):

| Thao tác                                                     | Trạng thái hàng đợi |
| ------------------------------------------------------------ | ------------------- |
| 1 vào hàng đợi                                               | `{1}`               |
| 3 lớn hơn 1, 3 vào hàng đợi                                  | `{1 3}`             |
| -1 nhỏ hơn mọi phần tử trong hàng đợi, nên xóa hàng đợi rồi cho -1 vào hàng đợi | `{-1}`              |
| -3 nhỏ hơn mọi phần tử trong hàng đợi, nên xóa hàng đợi rồi cho -3 vào hàng đợi | `{-3}`              |
| 5 lớn hơn -3, vào hàng đợi trực tiếp                         | `{-3 5}`            |
| 3 nhỏ hơn 5, 5 ra khỏi hàng đợi, 3 vào hàng đợi              | `{-3 3}`            |
| -3 đã nằm ngoài cửa sổ, nên -3 ra khỏi hàng đợi; 6 lớn hơn 3, 6 vào hàng đợi | `{3 6}`             |
| 7 lớn hơn 6, 7 vào hàng đợi                                  | `{3 6 7}`           |

???+ note "Mã tham khảo cho ví dụ"
    ```cpp
    --8<-- "docs/ds/code/monotonic-queue/monotonic-queue_1.cpp"
    ```

Một khác biệt lớn giữa "hàng đợi" trong cấu trúc này và hàng đợi thông thường
là có thể thao tác ở cuối hàng đợi;
trong STL có cấu trúc dữ liệu tương tự là `deque`.

???+ note "Ví dụ 2 [Luogu P2698 Flowerpot S](https://www.luogu.com.cn/problem/P2698)"
    Cho tọa độ của $N$ giọt nước, trong đó $y$ biểu thị độ cao của giọt nước,
    còn $x$ biểu thị vị trí nó rơi xuống trục $x$. Mỗi giọt nước rơi với tốc độ
    1 đơn vị độ dài mỗi giây. Cần đặt chậu hoa ở một vị trí nào đó trên trục
    $x$ sao cho từ lúc giọt nước đầu tiên được chậu hứng đến lúc giọt nước cuối
    cùng được chậu hứng, độ chênh lệch thời gian ít nhất là $D$.

    Coi một giọt nước là được hứng nếu khi nó rơi xuống trục $x$, nó thẳng hàng
    với mép chậu hoa. Cho tọa độ của $N$ giọt nước và giá trị $D$, tính chiều
    rộng nhỏ nhất $W$ của chậu hoa.
    $1\leq N \leq 100000 , 1 \leq D \leq 1000000, 0 \leq x,y\leq 10^6$

Sau khi sắp xếp tất cả giọt nước theo tọa độ $x$, bài toán có thể chuyển thành
tìm một đoạn có hiệu tọa độ $x$ nhỏ nhất sao cho trong đoạn đó, hiệu giữa giá
trị lớn nhất và nhỏ nhất của tọa độ $y$ ít nhất là $D$. Bài này giống ví dụ
trước ở chỗ đều liên quan tới giá trị lớn nhất và nhỏ nhất trong một đoạn.
Điểm khác là kích thước đoạn không cố định, và chính kích thước đoạn cũng là
đáp án cần tìm.

Có thể dùng hai hàng đợi đơn điệu, một tăng và một giảm, để duy trì giá trị lớn
nhất và nhỏ nhất trong $[L,R]$ khi $R$ liên tục dịch sang phải. Lúc này, nếu cố
định $L$, thì giá trị lớn nhất trong $[L,R]$ chỉ có thể ngày càng lớn, còn giá
trị nhỏ nhất chỉ có thể ngày càng nhỏ. Do đó, đặt
$f(R) = \max[L,R]-\min[L,R]$, thì $f(R)$ là một hàm tăng theo $R$, nên
$f(R)\geq D \implies f(r)\geq D,R\lt r \leq N$. Điều này cho thấy với mỗi $L$
cố định, $R$ đầu tiên ở bên phải thỏa mãn điều kiện chính là lựa chọn tối ưu.

Vì vậy, toàn bộ quá trình giải là: trước hết cố định $L$, rồi di chuyển $R$ từ
trước ra sau, dùng hai hàng đợi đơn điệu để duy trì các giá trị cực trị của
$[L,R]$. Khi tìm được $R$ đầu tiên thỏa mãn điều kiện, cập nhật đáp án và cũng
dịch $L$ sang phải. Khi $L$ dịch sang phải, cả hai hàng đợi đơn điệu đều cần
kịp thời bật đầu hàng đợi. Như vậy, cho tới khi $R$ đi tới cuối, mỗi phần tử
vẫn chỉ vào và ra khỏi hàng đợi một lần, bảo đảm độ phức tạp thời gian $O(n)$.

???+ note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/monotonic-queue/monotonic-queue_2.cpp"
    ```
