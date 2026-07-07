author: Jerry3128

Kiến thức tiên quyết: [cây phân đoạn](./seg.md)

## Dẫn nhập bài toán

Cho dãy hàm tuyến tính một biến $F=\{f_1,\dots,f_n\}$:
$f_i: \mathbb{R} \rightarrow \mathbb{R}$,
trong đó $f_i(x)=k_ix+b_i$ và $k_i,b_i \in \mathbb{R}$.
Cần duy trì các thao tác sau:

-   $\operatorname{QueryMax}(l,r)$: cho $l$ và $r$, trả về $\max_{i=l}^r{f_i(0)}$.
-   $\operatorname{TranslateLeft}(l,r,\delta)$: cho $l$, $r$ và $\delta$,
    với mọi $i\in[l,r]$, thực hiện $f_i(x) \leftarrow f_i(x+\delta)$.
    Thao tác này tương đương với $b_i\leftarrow b_i+k_i\delta$, trong đó $\delta > 0$.

Để tiện trình bày, giả sử mọi hàm đều khác nhau đôi một.

Bản chất của phép tịnh tiến sang trái trên một đoạn các hàm bậc nhất là $b_i \leftarrow b_i+k_i\cdot \delta$: với hằng
số tự do $b_i$, cộng thêm hệ số góc $k_i$ nhân với lượng tịnh tiến theo trục hoành $\delta$.

Thao tác này tương đương với kiểu "cộng đoạn có trọng số theo hệ số vị trí" thường gặp trong nhiều bài toán cấu trúc dữ
liệu: với mỗi chỉ số $i$ trong đoạn $[l, r]$, cộng vào giá trị của nó một số cố định $\delta$ nhân với hệ số riêng $k_i$
của vị trí đó. Vì vậy, về bản chất, tịnh tiến đoạn các hàm bậc nhất chính là phép cộng đoạn có trọng số theo hệ số vị
trí.

Để thể hiện cấu trúc chia để trị nhị phân đặc trưng của KTT, phần này bắt đầu ngay từ phép tịnh tiến đoạn.

<span id="cấu-trúc-dữ-liệu-động-học"></span>
## Cấu trúc dữ liệu động học

Cấu trúc dữ liệu động học (Kinetic Data Structures, viết tắt là KDS) dùng để duy trì các thuộc tính của một hệ đối tượng
hình học trong quá trình chuyển động liên tục.

### Hàng đợi sự kiện

Giả sử mỗi điểm đều có một kế hoạch chuyển động đã biết;
kế hoạch này có thể cung cấp toàn bộ hoặc một phần thông tin chuyển động của nó.
Chẳng hạn, đường cong hoặc đường thẳng do hàm $f_i(x)$ tạo thành
có thể mô tả tốt quỹ đạo chuyển động của điểm động $i$.
Kế hoạch chuyển động có thể thay đổi bất cứ lúc nào,
chẳng hạn do va chạm hoặc do tương tác với môi trường;
nguyên nhân làm thay đổi kế hoạch chuyển động được gọi là sự kiện.
Hàng đợi sự kiện sẽ đưa ra các sự kiện theo thứ tự thời gian.

Một điểm then chốt của KDS là cần có các sự kiện dễ duy trì.
Nói cách khác, kiểu sự kiện trong hàng đợi sự kiện phải tương ứng với những thay đổi tổ hợp có thể xảy ra, và mỗi thay
đổi chỉ liên quan đến một số lượng đối tượng không đổi, thường là rất ít.
Ví dụ, trong phần duy trì của bài toán này,
một kiểu sự kiện được dùng là "quan hệ lớn nhỏ giữa hàm $f_i(0)$ và hàm $f_{j}(0)$ thay đổi".

Hàng đợi sự kiện có thể được duy trì ngầm định.

### Chứng chỉ

Các sự kiện này nên tương đương với việc được xác nhận bởi giao của một loạt điều kiện đại số bậc thấp,
trong đó mỗi điều kiện đại số chỉ liên quan đến hữu hạn đối tượng.
Những điều kiện này được gọi là chứng chỉ của KDS.
Ví dụ: $[f_i(0) > f_j(0)]$.

<span id="cây-đấu-loại-động-học"></span>
## Cây đấu loại động học

### Giới thiệu

Cây đấu loại động học (Kinetic Tournament Tree, viết tắt là KTT) thuộc nhóm cấu trúc dữ liệu động học. Cấu trúc này xuất
hiện lần đầu trong bài báo [Data Structures for Mobile Data](https://www.sciencedirect.com/science/article/pii/S0196677498909889)
năm 1999, dùng để duy trì dữ liệu biến đổi liên tục.
Tổng quát hơn, mọi cấu trúc áp dụng chiến lược động học hóa sau đây đều có thể được gọi là cây đấu loại động học:

-   Sinh chứng chỉ kiểm chứng tính đúng đắn cho các thao tác then chốt trong thuật toán tĩnh (chẳng hạn phép so sánh),
    rồi gắn mỗi chứng chỉ với một hàng đợi sự kiện toàn cục,
    ghi lại thời điểm chứng chỉ đó có thể mất hiệu lực.
-   Khi một chứng chỉ mất hiệu lực, cập nhật đầu ra của thuật toán và duy trì hiệu quả tập chứng chỉ.

Trong cộng đồng lập trình thi đấu, cấu trúc này trở nên phổ biến nhờ luận văn đội tuyển tập huấn quốc gia Trung Quốc năm
2020, "[Bàn về việc duy trì động giá trị cực trị của hàm số][ktt-training-2020]".
KTT trong giới học thuật và KTT trong giới lập trình thi đấu khác nhau ở lĩnh vực ứng dụng và cách cài đặt,
nên phần này giới thiệu KTT đã được tối ưu phần nào cho lập trình thi đấu.

### Cấu trúc cơ bản

Trước hết, xét việc thiết kế một cấu trúc dữ liệu tương tự cây phân đoạn để duy trì giá trị lớn nhất tĩnh. Dựng cấu trúc
của cây phân đoạn; với mỗi nút không phải lá, trọng số của nó là trọng số lớn hơn trong hai nút con. Sau $O(n)$ phép so
sánh, trọng số ở gốc chính là giá trị lớn nhất toàn cục.
Bây giờ, các trọng số bắt đầu thay đổi.
Nếu KTT phát hiện được mỗi lần nguồn gốc của giá trị lớn nhất tại một nút trên cây thay đổi,
có thể duy trì giá trị lớn nhất toàn cục.

Để KTT phát hiện được mọi lần nguồn gốc của giá trị lớn nhất trên cây thay đổi, với một nút $x$ trên cây và hai hàm
$f_L$, $f_R$ do con trái và con phải của nó cung cấp, định nghĩa chứng chỉ là "$f_L$ và $f_R$ giữ nguyên quan hệ lớn
nhỏ".
Khi chứng chỉ mất hiệu lực,
cần đi theo đường đi trên cây đến nút có chứng chỉ vừa mất hiệu lực để cập nhật thông tin của nó.
Để duy trì thời điểm mất hiệu lực của mỗi chứng chỉ,
nhận thấy thời điểm chứng chỉ mất hiệu lực chính là thời điểm hai hàm có cùng giá trị.
Khi đó bài toán trở thành tìm tọa độ $x$ của giao điểm giữa hai hàm tuyến tính, có thể giải trong $O(1)$.

Với mỗi nút trên cây, duy trì hàm đạt giá trị lớn nhất tại $0$,
thời điểm chứng chỉ hiện tại mất hiệu lực,
và thời điểm mất hiệu lực sớm nhất của một chứng chỉ trong toàn bộ cây con.
Nhờ vậy, với thời điểm mất hiệu lực của mỗi chứng chỉ, có thể tìm thấy nó ở đúng thời điểm đó và cập nhật thông tin
tương ứng.
Những thông tin này dùng để ghi lại chính các hàm. Tiếp theo xét việc duy trì thao tác tịnh tiến đoạn; vì thao tác này
có thể cộng dồn đơn giản, có thể dùng đánh dấu lười để xử lý.

Định nghĩa đánh dấu lười $\Delta_v$ biểu thị rằng mọi hàm trên các nút khác trong cây con của nút $v$ đều cần được tịnh
tiến sang trái $\Delta_v$ đơn vị. Lúc này, với nút $v$ trên cây, một thao tác mới muốn tịnh tiến sang trái mọi hàm trong
cây con của nó thêm $\delta$, tức $f(x)\leftarrow f(x+\delta)$.
Cần cập nhật đánh dấu lười:
$\Delta_v\leftarrow \Delta_v + \delta$,
tức cộng dồn độ lệch của mọi nút khác trong cây con.
Đồng thời, tịnh tiến sang trái cũng đồng nghĩa với việc giá trị của hàm tại điểm $0$ thay đổi.
Nếu tọa độ $x$ mất hiệu lực của một chứng chỉ là $t$,
thì sau khi tịnh tiến, tọa độ $x$ mất hiệu lực sẽ là $t-\delta$.
Nếu lúc này $t-\delta$ vượt qua điểm $0$, chứng chỉ đã mất hiệu lực;
khi đó cần đệ quy xuống dưới để tìm nút chứa chứng chỉ hiện tại,
cập nhật nút đó, rồi cập nhật thông tin mới ngược lên gốc.
Quá trình này có thể thực hiện cùng lúc với thao tác sửa đổi.

Từ đó thu được một cách cài đặt đơn giản.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/ktt/ktt_1.cpp:core"
    ```

### Phân tích độ phức tạp

Chứng minh độ phức tạp thời gian của KTT cần dùng phân tích thế năng.

Gọi $d(x)$ là độ sâu của nút $x$ trên cây phân đoạn, với độ sâu của gốc bằng $1$. Định nghĩa thế năng của nút $x$ trên
cây phân đoạn là:

$$
\alpha(x) = \begin{cases}
d(x) & \text{nếu hàm có hệ số góc nhỏ hơn có giá trị lớn hơn}  \\
0    & \text{ngược lại}\\
\end{cases}
$$

Nói cách khác, trong hai hàm được so sánh tại $x$,
nếu hàm có hệ số góc nhỏ hơn lại có giá trị tại điểm $0$ lớn hơn,
thì thế năng của nút hiện tại là $d(x)$; nếu không thì bằng $0$.

Định nghĩa thế năng của toàn bộ KTT là tổng thế năng của mọi nút:

$$
\Phi = \sum_x \alpha(x)
$$

Xét một lần cập nhật trên nút $x$ và cha của nó là $p$, với chi phí thực tế $c=1$.
Gọi thế năng trước và sau khi cập nhật lần lượt là $\Phi$ và $\Phi'$.
Tính chi phí cập nhật khấu hao của việc cập nhật nút $x$.
Vì nút hiện tại $x$ được cập nhật,
tại thời điểm đó thế năng của nó giảm từ $d(x)$ xuống $0$.
Còn với $p$, trong trường hợp xấu nhất,
thế năng của nó có thể tăng từ $0$ lên $d(p)$:

$$
\begin{aligned}
\hat{c} &= 1 + \Phi' - \Phi\\
    &= 1 + (\alpha'(p) + \alpha'(x)) - (\alpha(p) + \alpha(x))\\
    &= 1 + (\alpha'(p) - \alpha(p)) + (\alpha'(x) - \alpha(x))\\
    &\leq 1 + d(p) - d(x)\\
    &= 0
\end{aligned}
$$

Cộng theo chi phí thực tế, định nghĩa thế năng ban đầu là $\Phi_s$ và thế năng cuối cùng là $\Phi_t$:

$$
\begin{aligned}
\sum c  &= \sum \hat{c} + \Phi_{s} - \Phi_{t}\\
    &\leq \Phi_{s} - \Phi_{t}\\
    &=O(n\log n)
\end{aligned}
$$

Đây là số lần KTT cập nhật xong tất cả chứng chỉ mất hiệu lực trong trường hợp chỉ có sửa đổi toàn cục.

Ngoài ra, xét ảnh hưởng của tịnh tiến đoạn lên thế năng.
Với một lần tịnh tiến đoạn, các nút cần xét là những nút mà trong cây con của chúng
có một số nhưng không phải toàn bộ nút của cây chịu tác động của thao tác tịnh tiến đoạn.
Những nút như vậy chính là các nút đi qua trên cây khi thực hiện thao tác sửa đổi;
số lượng của chúng không vượt quá $O(\log n)$.
Trong trường hợp xấu nhất, thế năng của mỗi nút tăng thêm $d(x)\le \log n$,
nên mỗi thao tác làm thế năng tăng $O(\log^2 n)$.

Để duy trì tịnh tiến đoạn, thao tác cập nhật chứng chỉ sẽ xảy ra
$O(n\log n + m\log^2 n)$ lần.
Mỗi lần cập nhật chứng chỉ,
cần đi theo một đường đi trên cây đến nút có chứng chỉ mất hiệu lực; phần này tốn $O(\log n)$.
Vì vậy tổng độ phức tạp thời gian là $O(n\log^2 n+ m\log^3 n)$.

Ưu điểm của phương pháp này là nó đã chạm tới cận dưới độ phức tạp thời gian của bài toán,
$O(\lambda_{s}(n)\log^2 n)$.
$\lambda_{s}(n)$ biểu thị độ dài của dãy Davenport-Schinzel $(n, s)$ dài nhất.
Trong đó, các hàm tuyến tính tương ứng với $s=1$ và $\lambda_1(n)=n$.
Phần này thuộc nội dung hình học tính toán, nên bài viết không trình bày thêm.

### Trường hợp bậc cao

Nếu cần duy trì hàm đa thức hoặc các hàm phức tạp hơn thay vì hàm tuyến tính,
hai hàm có thể có nhiều giao điểm.
Cho dãy hàm một biến liên tục và được định nghĩa đầy đủ $F=\{f_1,\dots,f_n\}$:
$f_i: \mathbb{R} \rightarrow \mathbb{R}$.
Trong đó đồ thị của mỗi cặp hàm giao nhau tại nhiều nhất $s$ điểm.
Một ví dụ tiêu biểu là tập các hàm đa thức bậc $s$, vốn thỏa mãn yêu cầu này.

Với cùng bài toán, dùng phân tích thế năng.

$d(x)$ là độ sâu của nút $x$ trên cây phân đoạn, với độ sâu của gốc bằng $1$.
Định nghĩa $I(x)$ là số giao điểm sau điểm $0$ của hai hàm được so sánh tại nút $x$.
Định nghĩa thế năng của nút $x$ trên cây phân đoạn là:

$$
\alpha(x)=d(x)^{\log_2(s+1)}I(x)
$$

Định nghĩa thế năng của toàn bộ KTT là tổng thế năng của mọi nút:

$$
\Phi = \sum_x \alpha(x)
$$

Xét một lần cập nhật trên nút $x$ và cha của nó là $p$, với chi phí thực tế $c=1$.
Gọi thế năng trước và sau khi cập nhật lần lượt là $\Phi$ và $\Phi'$.
Tính chi phí cập nhật khấu hao của việc cập nhật nút $x$.
Vì nút hiện tại $x$ được cập nhật,
tại thời điểm đó thế năng của nó giảm từ
$d(x)^{\log_2(s+1)}I(x)$ xuống $d(x)^{\log_2(s+1)}(I(x)-1)$.
Còn với $p$, trong trường hợp xấu nhất,
thế năng của nó có thể tăng từ $0$ lên $d(p)^{\log_2(s+1)}$:

$$
\begin{aligned}
        \hat{c} &= 1 + \Phi' - \Phi\\
                &= 1 + (\alpha'(x) - \alpha(x)) + (\alpha'(p) - \alpha(p))\\
                &\leq 1 - d(x)^{\log_2{(s+1)}} + s(d(x)-1)^{\log_2{(s+1)}}\\
                &\leq 0
    \end{aligned}
$$

Từ dòng thứ ba sang dòng thứ tư đã dùng ràng buộc rằng $d(x)$ là số nguyên dương.

Cộng theo chi phí thực tế, định nghĩa thế năng ban đầu là $\Phi_s$ và thế năng cuối cùng là $\Phi_t$:

$$
\begin{aligned}
    \sum c  &= \sum \hat{c} - \Phi_t + \Phi_s\\
            &\leq \Phi_s - \Phi_t\\
            &= O(ns (\log n)^{\log_2{(s+1)}})
\end{aligned}
$$

Nhận được cận trên độ phức tạp là
$O(ns (\log n)^{1+\log_2{(s+1)}} + ms (\log n)^{2+\log_2{(s+1)}})$.[^ref1]

### Trường hợp xấp xỉ

Cho dãy hàm một biến liên tục và được định nghĩa đầy đủ $F=\{f_1,\dots,f_n\}$.
Định nghĩa $\mathfrak U_F(x)$, $\mathfrak L_F(x)$ và $\mathfrak E_F(x)$
lần lượt là bao trên, bao dưới và biên độ.

$$
\begin{aligned}
    \mathfrak U_F(x) & = \max\{f_i(x) \mid f_i \in F\} \\
    \mathfrak L_F(x) & = \min\{f_i(x) \mid f_i \in F\} \\
    \mathfrak E_F(x) & = \mathfrak U_F(x) - \mathfrak L_F(x)
\end{aligned}
$$

Chỉ yêu cầu chương trình trả về $\tilde{\mathfrak U}_F(x)$ thỏa mãn

$$
\mathfrak U_F(x) \geq \tilde{\mathfrak U}_F(x) \geq \mathfrak U_F(x) - \epsilon \mathfrak E_F(x)
$$

Khi đó, trong trường hợp phức tạp, có thể đạt $O((1/\epsilon^2)n\log^3 n)$,
không phụ thuộc vào bậc đa thức,
đồng thời cho phép các hàm được tịnh tiến đoạn sang trái hoặc sang phải.

## Tài liệu tham khảo và chú thích

[^ref1]: Cần lưu ý rằng đây chỉ là cận trên;
    cận dưới của độ phức tạp phải là $O(\lambda_{s}(n)\log n)$.
    Tác giả đoán rằng cách xây dựng phân tích thế năng trong phần này
    nên tham khảo công thức tổng quát của $\lambda_{s}(n)$ ứng với dãy Davenport-Schinzel
    để thu được cận trên chặt hơn.

-   P. K. Agarwal, S. Har-Peled, and K. R. Varadarajan. Approximating extent measures of points. J. ACM,
    51(4):606-635, July 2004.
-   J. Basch, L. J. Guibas, and J. Hershberger. Data structures for mobile data. Journal of Algorithms, 31(1):1-28,
    1999.
-   G. Alexandron, H. Kaplan, and M. Sharir. Kinetic and dynamic data structures for convex hulls and upper envelopes.
    Computational Geometry, 36(2):144-158, 2007.

[ktt-training-2020]: https://github.com/OI-wiki/libs
