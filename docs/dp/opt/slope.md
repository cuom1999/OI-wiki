author: Marcythm, hsfzLZH1, abc1763613206, greyqz, Ir1d, billchenchina, Chrogeek, Enter-tainer, StudyingFather, MrFoodinChina, luoguyuntianming, sshwy, wood3

## Dẫn nhập bằng ví dụ

???+ note "[「HNOI2008」Đóng gói đồ chơi](https://loj.ac/problem/10188)"
    Có $n$ món đồ chơi xếp thành một hàng, món thứ $i$ có giá trị $c_i$. Cần chia $n$ món đồ chơi thành một số đoạn. Với một đoạn $[l,r]$, chi phí của nó là $(r-l+\sum_{i=l}^r c_i-L)^2$, trong đó $L$ là hằng số. Yêu cầu tìm chi phí chia đoạn nhỏ nhất.
    
    $1\le n\le 5\times 10^4, 1\le L, c_i\le 10^7$.

### Cách DP đơn giản

Đặt $f_i$ là chi phí nhỏ nhất khi chia $i$ vật phẩm đầu tiên thành một số đoạn.

Phương trình chuyển trạng thái: $f_i=\min_{j<i}\{f_j+(i-(j+1)+pre_i-pre_j-L)^2\}=\min_{j<i}\{f_j+(pre_i-pre_j+i-j-1-L)^2\}$.

Trong đó $pre_i$ là tổng của $i$ số đầu tiên, tức $\sum_{j=1}^i c_j$.

Cách làm này có độ phức tạp thời gian $O(n^2)$, không đủ để giải bài này.

### Tối ưu

Xét đơn giản hóa phương trình chuyển ở trên. Đặt $s_i=pre_i+i,L'=L+1$, khi đó $f_i=\min_{j<i}\{f_j+(s_i-s_j-L')^2\}$.

Đưa các phần không liên quan tới $j$ ra ngoài, thu được:

$$
f_i - (s_i-L')^2=\min_{j<i}\{f_j+s_j^2 + 2s_j(L'-s_i) \} 
$$

Xét dạng hệ số góc - tung độ gốc của hàm bậc nhất $y=kx+b$, chuyển vế được $b=y-kx$. Biểu diễn thông tin liên quan tới $j$ dưới dạng $y$, thông tin liên quan đồng thời tới $i,j$ dưới dạng $kx$, và thông tin cần tối thiểu hóa (liên quan tới $i$) dưới dạng $b$, tức tung độ gốc. Cụ thể, đặt:

$$
\begin{aligned}
x_j&=s_j\\
y_j&=f_j+s_j^2\\
k_i&=-2(L'-s_i)\\
b_i&=f_i-(s_i-L')^2\\
\end{aligned}
$$

Khi đó phương trình chuyển viết thành $b_i=\min_{j<i}\{y_j-k_ix_j\}$. Xem $(x_j,y_j)$ là một điểm trên mặt phẳng hai chiều, $k_i$ là hệ số góc của đường thẳng, còn $b_i$ là tung độ gốc của đường thẳng có hệ số góc $k_i$ đi qua $(x_j,y_j)$. Bài toán chuyển thành chọn $j$ phù hợp ($1\le j<i$) để tối thiểu hóa tung độ gốc của đường thẳng.

![Tịnh tiến đường thẳng để tìm điểm tối ưu trên bao lồi](../images/optimization.svg)

Như hình trên, tịnh tiến đường thẳng có hệ số góc $k_i$ từ dưới lên trên cho tới khi có một điểm $(x_p,y_p)$ nằm trên đường thẳng đó. Khi ấy $b_i=y_p-k_ix_p$, và $b_i$ đạt giá trị nhỏ nhất. Sau khi tính xong $f_i$, thêm điểm $(x_i,y_i)$ vào tập điểm để làm quyết định DP mới. Vậy cần duy trì tập điểm thế nào?

Các điểm có thể làm $b_i$ đạt giá trị nhỏ nhất đều nằm trên bao lồi dưới. Vì vậy khi tìm $p$, không cần duyệt tất cả $i-1$ điểm, chỉ cần xét các điểm trên bao lồi. Trong bài này, $k_i$ tăng theo $i$, nên có thể dùng hàng đợi đơn điệu để duy trì bao lồi.

Cụ thể, đặt $K(a,b)$ là hệ số góc của đường thẳng đi qua $(x_a,y_a)$ và $(x_b,y_b)$. Xét hàng đợi $q_l,q_{l+1},\ldots,q_r$, duy trì các điểm trên bao lồi dưới. Nói cách khác, với $l<i<r$, luôn có $K(q_{i-1},q_i)<K(q_i,q_{i+1})$.

Duy trì một con trỏ $e$ để tính giá trị nhỏ nhất của $b_i$. Cần tìm $e$ sao cho $K(q_{e-1},q_e)\le k_i<K(q_e,q_{e+1})$ (đặc biệt, khi $e=l$ hoặc $e=r$ cần xử lý riêng). Khi đó $p=q_e$, tức $q_e$ là điểm quyết định tối ưu của $i$. Vì $k_i$ tăng đơn điệu, số lần di chuyển của $e$ là khấu hao $O(1)$.

Khi chèn một điểm $(x_i,y_i)$, cần kiểm tra liệu $K(q_{r-1},q_r)<K(q_r,i)$ có đúng không. Nếu bất đẳng thức không đúng, loại $q_r$ khỏi cuối hàng đợi cho tới khi điều kiện thỏa, rồi chèn $i$ vào cuối hàng đợi $q$.

Như vậy độ phức tạp của DP được tối ưu xuống $O(n)$.

Tóm tắt thuật toán của bài mẫu tối ưu bằng độ dốc ở trên:

1.  Đưa trạng thái ban đầu vào hàng đợi.
2.  Mỗi lần dùng một đường thẳng $f(i)$ liên quan tới $i$ để cắt bao lồi đang duy trì, tìm quyết định tối ưu và cập nhật $dp_i$.
3.  Thêm trạng thái $dp_i$. Nếu một trạng thái (tức một điểm trên bao lồi) không còn thuộc bao lồi sau khi thêm $dp_i$, cần loại bỏ nó trước khi thêm $dp_i$.

Tiếp theo giới thiệu các ứng dụng nâng cao của tối ưu bằng độ dốc: kết hợp nó với tìm kiếm nhị phân, chia để trị, cấu trúc dữ liệu, v.v. để duy trì các phương trình DP có tính chất không thuận lợi lắm (thiếu một số tính đơn điệu).

## Tối ưu DP bằng nhị phân/CDQ/cây cân bằng

Khi tìm quyết định tối ưu tại điểm $i$, dùng một đường thẳng $f(i)$ liên quan tới $i$ để cắt bao lồi đang duy trì. Điểm được cắt tới chính là quyết định tối ưu.

Trong ví dụ trên, hệ số góc của đường thẳng biến thiên đơn điệu theo $i$, nhưng trong một số bài, hệ số góc không đơn điệu. Khi đó cần duy trì mọi nút trên bao lồi, rồi mỗi lần dùng đường thẳng hiện tại để cắt bao lồi này. Quá trình đó có thể giải bằng tìm kiếm nhị phân, vì hệ số góc giữa hai điểm kề nhau trên bao lồi có tính đơn điệu.

???+ note "Đóng gói đồ chơi - phiên bản sửa"
    Có $n$ món đồ chơi xếp thành một hàng, món thứ $i$ có giá trị $c_i$. Cần chia $n$ món đồ chơi thành một số đoạn. Với đoạn $[l,r]$, chi phí là $(r-l+\sum_{i=l}^r c_i-L)^2$, trong đó $L$ là hằng số. Yêu cầu tìm chi phí chia đoạn nhỏ nhất.
    
    $1\le n\le 5\times 10^4,1\le L\le 10^7,-10^7\le c_i\le 10^7$.

Khác biệt duy nhất giữa bài này và "Đóng gói đồ chơi" là giá trị của đồ chơi có thể âm. Tiếp tục dùng ý tưởng trước, đặt $f_i$ là chi phí nhỏ nhất khi chia $i$ vật phẩm đầu tiên thành một số đoạn.

Phương trình chuyển trạng thái: $f_i=\min_{j<i}\{f_j+(pre_i-pre_j+i-j-1-L)^2\}$.

Trong đó $pre_i=\sum_{j=1}^i c_j$.

Biến đổi phương trình tương tự:

$$
f_i - (s_i-L')^2=\min_{j<i}\{f_j+s_j^2 + 2s_j(L'-s_i) \} 
$$

Tuy nhiên lúc này có hai điều kiện không còn đúng:

1.  Hệ số góc của đường thẳng không còn đơn điệu;
2.  Hoành độ của các điểm quyết định được thêm vào không còn đơn điệu.

Vẫn xét việc duy trì bao lồi.

Khi tìm điểm quyết định tối ưu, tức dùng đường thẳng cắt bao lồi, thay thao tác lấy đầu hàng đợi đơn điệu bằng tìm kiếm nhị phân trên bao lồi. Tìm kiếm nhị phân cạnh trên bao lồi có hệ số góc gần nhất với hệ số góc của đường thẳng sẽ tìm được quyết định tối ưu.

Khi thêm điểm quyết định, tức thêm một điểm vào bao lồi, có hai cách duy trì.

Cách thứ nhất là trực tiếp dùng cây cân bằng để duy trì bao lồi. Khi đó thao tác tìm nhị phân quyết định trở thành tìm trên cây cân bằng, còn chèn điểm quyết định trở thành chèn một nút vào cây cân bằng và xóa một số điểm bị loại khỏi bao lồi. Ý tưởng cách này gọn nhưng cài đặt rườm rà.

Dưới đây giới thiệu một cách làm dựa trên [chia để trị CDQ](../../misc/cdq-divide.md).

Đặt $\text{CDQ}(l,r)$ là quá trình tính $f_i,i\in[l,r]$. Xét $\text{CDQ}(1,n)$:

-   Trước hết gọi $\text{CDQ}(1,mid)$ để tính $f_i,i\in[1,mid]$. Sau đó dựng bao lồi từ các điểm quyết định trong đoạn $[1,mid]$, rồi dùng bao lồi này để cập nhật $f_i,i\in[mid+1,n]$. Lúc này tập điểm quyết định là cố định, không giống trước đó vừa tính giá trị DP vừa thêm điểm quyết định. Vì vậy có thể sắp xếp trước các $f_i$ với $i\in[mid+1,n]$ theo hệ số góc $k_i$ của đường thẳng, rồi dùng hàng đợi đơn điệu để tính giá trị DP. Ngoài ra, cũng có thể tìm nhị phân trên bao lồi tĩnh để tính giá trị DP.

-   Với mỗi điểm trong $[mid+1,n]$, nếu vị trí quyết định tối ưu của nó nằm trong $[1,mid]$, thì nó sẽ được cập nhật thành đáp án tối ưu ở bước này. Sau khi thực hiện xong, mọi điểm trong $[1,mid]$ đã phát huy hết tác dụng; việc chúng còn trong bao lồi hay không không ảnh hưởng tới các cập nhật sau. Do đó có thể trực tiếp bỏ các điểm quyết định của đoạn này, rồi dùng $\text{CDQ}(mid+1,n)$ để giải phần còn lại của đoạn phải.

Độ phức tạp thời gian là $O(n\log^2 n)$.

So sánh "Đóng gói đồ chơi" và "Đóng gói đồ chơi - phiên bản sửa", có thể rút ra hai điểm:

-   Nhị phân/CDQ/cây cân bằng có thể tối ưu việc tính phương trình DP và giảm độ phức tạp ở mức nhất định, nhưng không thay đổi bản thân phương trình.
-   Tính chất của phương trình DP phụ thuộc vào đặc trưng dữ liệu, còn bản thân phương trình DP phụ thuộc vào mô hình toán học của đề bài.

## Tổng kết

Tối ưu DP bằng độ dốc cần được dùng linh hoạt. Mục tiêu cốt lõi là chuyển bài toán tối ưu thành bài toán cực trị tung độ gốc liên quan tới bao lồi trên mặt phẳng hai chiều. Khi gặp phương trình có tính chất không thuận lợi, đôi khi cần hỗ trợ bằng cấu trúc dữ liệu; lúc đó cần phân tích theo từng bài cụ thể.

## Bài tập

-   [「SDOI2016」Hành trình](https://loj.ac/problem/2035)
-   [「ZJOI2007」Xây dựng kho](https://loj.ac/problem/10189)
-   [「APIO2010」Đội hành động đặc biệt](https://loj.ac/problem/10190)
-   [「JSOI2011」Chanh](https://www.luogu.com.cn/problem/P5504)
-   [「Codeforces 311B」Cats Transport](http://codeforces.com/problemset/problem/311/B)
-   [「NOI2007」Đổi tiền](https://loj.ac/problem/2353)
-   [「NOI2019」Đường về nhà](https://loj.ac/problem/3156)
-   [「NOI2016」Chuyện nhà vua uống nước](https://uoj.ac/problem/223)
-   [「NOI2014」Mua vé](https://uoj.ac/problem/7)
