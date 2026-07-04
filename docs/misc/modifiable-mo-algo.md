author: StudyingFather, Backl1ght, countercurrent-time, Ir1d, greyqz, MicDZ, ouuan, renbaoshuo, Lixuannan

Hãy chắc rằng bạn đã biết thuật toán Mo thông thường. Nếu chưa, hãy đọc trước phần [thuật toán Mo thông thường](./mo-algo.md).

## Đặc điểm

Mo thông thường không xử lý được thao tác sửa đổi.

Ta có thể cưỡng ép nó hỗ trợ sửa đổi, tương tự như trong DP: thêm một chiều **thời gian** để biểu diễn thời điểm của thao tác hiện tại.

Chiều thời gian biểu diễn số lần sửa đổi đã trải qua.

Tức là biến truy vấn $[l,r]$ thành $[l,r,\text{time}]$.

Khi đó tọa độ của ta cũng có thể di chuyển trên chiều thời gian. Nói cách khác, $[l,r,\text{time}]$ có thêm một chiều di chuyển và có thể chuyển thành:

-   $[l-1,r,\text{time}]$
-   $[l+1,r,\text{time}]$
-   $[l,r-1,\text{time}]$
-   $[l,r+1,\text{time}]$
-   $[l,r,\text{time}-1]$
-   $[l,r,\text{time}+1]$

Các chuyển trạng thái như vậy cũng là $O(1)$, nhưng khi sắp xếp ta có thêm một khóa nữa cần xử lý.

Có thể sắp xếp thứ tự chuyển trạng thái bằng cách tương tự Mo thông thường và đạt $O(n^{5/3})$.

Ở đây ta lấy $n^{2/3}$ làm độ dài khối, chia thành $n^{1/3}$ khối. Khóa thứ nhất là khối chứa đầu trái, khóa thứ hai là khối chứa đầu phải, khóa thứ ba là thời gian.

???+ note "Độ dài khối tối ưu và phân tích độ phức tạp thời gian"
    Giả sử độ dài dãy là $n$, có $m$ truy vấn và $t$ lần sửa đổi.

    Khác với Mo thông thường, khóa thứ hai khi sắp xếp Mo có sửa đổi là chỉ số khối chứa đầu phải.

    Hãy xét điều gì xảy ra nếu không chia khối đầu phải:

    -   Nếu đầu phải lộn xộn, với mỗi truy vấn nó có thể di chuyển $n$ lần.
    -   Nếu đầu phải có thứ tự, thời gian lại bị lộn xộn, mỗi truy vấn có thể phải di chuyển $t$ lần.

    Trong cả hai trường hợp, chi phí thời gian đều không chấp nhận được.

    Tiếp theo ta phân tích độ phức tạp thời gian.

    Gọi độ dài khối là $s$, khi đó có $\dfrac{n}{s}$ khối. Với hai khối $i$ và $j$, ký hiệu $q_{i,j}$ là số truy vấn có đầu trái nằm trong khối $i$ và đầu phải nằm trong khối $j$.

    Với mỗi "nhóm" truy vấn $(i,j)$ mà hai đầu mút không đổi khối, các đầu mút mỗi lần di chuyển $O(s)$ bước, còn thời gian tăng đơn điệu với chi phí $O(t)$.

    Thời gian do hai đầu mút đổi khối có thể bỏ qua trong phân tích này.

    Viết thành công thức:

    $$
    \begin{aligned}
    &\sum_{i=1}^{n/s}\sum_{j=i+1}^{n/s}(q_{i,j}\cdot s+t)\\
    =&ms+\left(\dfrac{n}{s}\right)^2t\\
    =&ms+\dfrac{n^2t}{s^2}
    \end{aligned}
    $$

    Lấy đạo hàm để tìm giá trị nhỏ nhất của biểu thức này. Đặt $f(s)=ms+\dfrac{n^2t}{s^2}$. Khi đó $f'(s)=m-\dfrac{2n^2t}{s^3}=0$.

    Suy ra $s=\sqrt[3]{\dfrac{2n^2t}{m}}=\dfrac{2^{1/3}n^{2/3}t^{1/3}}{m^{1/3}}=s_0$.

    Tức là khi lấy độ dài khối $\dfrac{n^{2/3}t^{1/3}}{m^{1/3}}$, ta có độ phức tạp thời gian tối ưu $O\left(n^{2/3}m^{2/3}t^{1/3}\right)$.

    Độ phức tạp thường được nói là $O\left(n^{5/3}\right)$ chính là trường hợp xem $n,m,t$ cùng bậc.

    Trong hiện thực thực tế, vẫn nên đặt độ dài khối là $n^{2/3}$.

## Ví dụ

???+ note "Ví dụ [Luogu P1903 Đếm màu / duy trì hàng đợi](https://www.luogu.com.cn/problem/P1903)"
    Tóm tắt đề bài: Cho một dãy và $M$ thao tác, gồm hai loại:

    1.  Sửa số ở một vị trí trong dãy.
    2.  Hỏi số loại giá trị khác nhau trong đoạn $[l,r]$ (nhiều số giống nhau chỉ tính một loại).

Không khó nhận thấy rằng nếu không có thao tác 1 (sửa đổi), ta có thể dễ dàng giải bằng Mo thông thường.

Nhưng đề bài còn có sửa đổi tại một điểm, nên ta dùng **Mo có sửa đổi**.

### Quy trình

Trước hết xét cách làm của Mo thông thường:

-   Mỗi khi mở rộng đoạn, với mỗi số được thêm vào, thống kê số lần nó đã xuất hiện. Nếu trước khi thêm, số lần xuất hiện của giá trị này là $0$, nghĩa là đây là một giá trị mới, đáp án $+1$. Sau đó tăng số lần xuất hiện của giá trị này thêm $1$.
-   Mỗi khi thu hẹp đoạn, với mỗi số bị xóa ra, thống kê số lần xuất hiện của nó sau khi xóa. Nếu sau khi xóa, số lần xuất hiện của giá trị này là $0$, nghĩa là giá trị này đã bị xóa hết khỏi đoạn hiện tại, tức đoạn hiện tại giảm một màu, đáp án $-1$. Sau đó giảm số lần xuất hiện của giá trị này đi $1$.

Bây giờ xét thao tác sửa đổi:

-   Sửa đổi tại một điểm là thay số ở một vị trí. Giả sử ta chuyển từ một truy vấn đã trải qua $i$ lần sửa đổi sang một truy vấn đã trải qua $j$ lần sửa đổi, và $i<j$, thì cần áp dụng cưỡng ép các sửa đổi từ lần thứ $i+1$ đến lần thứ $j$.
-   Nếu $j<i$, thì cần hoàn tác cưỡng ép các sửa đổi từ lần thứ $i$ về lần thứ $j+1$.

Làm thế nào để áp dụng cưỡng ép một sửa đổi? Giả sử một sửa đổi thay màu ở vị trí $pos$: màu ban đầu tại $pos$ là $a$, sau khi sửa là $b$. Đồng thời giả sử đoạn hiện tại của Mo là $[l,r]$.

-   Áp dụng sửa đổi này: trước hết kiểm tra $pos$ có nằm trong đoạn $[l,r]$ hay không. Nếu có, việc này tương đương xóa màu $a$ khỏi đoạn, thêm màu $b$, rồi đổi màu của phần tử thứ $pos$ trong dãy màu hiện tại thành $b$. Nếu không nằm trong đoạn $[l,r]$, ta chỉ cần trực tiếp đổi phần tử thứ $pos$ trong dãy màu hiện tại thành $b$.
-   Hoàn tác sửa đổi này: tương đương áp dụng một sửa đổi tại phần tử thứ $pos$, đổi màu $b$ trở lại màu $a$.

Vì vậy bài này có thể được giải trực tiếp bằng Mo có sửa đổi.

### Hiện thực

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/modifiable-mo-algo/modifiable-mo-algo_1.cpp"
    ```
