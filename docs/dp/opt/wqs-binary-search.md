<span id="giới-thiệu"></span>
## Giới thiệu

Bài viết này giới thiệu cách dùng tìm kiếm nhị phân WQS để tối ưu các bài toán quy hoạch động. Trong các tài liệu khác, kỹ thuật này cũng thường được gọi là tìm kiếm nhị phân có trọng số, DP tối ưu lồi, DP đơn điệu hoàn toàn lồi, phương pháp nhân tử Lagrange, hay ở nước ngoài là Aliens Trick. Nó được Wang Qinshi tổng kết sớm nhất trong bài viết "Phân tích sơ lược một lớp phương pháp nhị phân".

Tìm kiếm nhị phân WQS thường dùng để giải một lớp bài toán tối ưu như sau: bài toán có ràng buộc về số lượng nên giải trực tiếp rất tốn kém; nhưng khi bỏ ràng buộc này đi, bản thân bài toán trở nên dễ hơn nhiều.

Ví dụ, giả sử cần chọn $m$ trong $n$ vật phẩm và tối ưu một hàm mục tiêu khá phức tạp. Nếu đặt $f(i,j)$ là giá trị tối ưu của hàm mục tiêu khi chọn $j$ vật phẩm trong $i$ vật phẩm đầu tiên, thì đáp án bài toán gốc là $f(n,m)$. Trong các bài toán dạng này, phương trình chuyển trạng thái thường là hai chiều. Cài đặt trực tiếp phương trình chuyển trạng thái có độ phức tạp thời gian $O(nm)$, thường không chấp nhận được.

Giả sử thêm rằng bài toán tối ưu không có ràng buộc số lượng dễ giải. Tuy nhiên, số lượng được chọn trong nghiệm tối ưu chưa chắc thỏa ràng buộc của bài toán gốc. Nếu số vật phẩm được chọn quá nhiều, ta có thể thêm một khoản phạt cố định $k$ cho mỗi vật phẩm được chọn (đó là "trọng số" trong "tìm kiếm nhị phân có trọng số"), rồi vẫn giải bài toán tối ưu không có ràng buộc số lượng. Với các giá trị $k$ khác nhau, số lượng được chọn tối ưu cũng khác nhau; hơn nữa, khi $k$ thay đổi, số lượng được chọn tối ưu biến thiên đơn điệu. Vì vậy có thể dùng tìm kiếm nhị phân để tìm $k$ sao cho số lượng được chọn tối ưu đúng bằng $m$. Giả sử khi đó giá trị tối ưu của hàm mục tiêu là $f_k(n)$, thì chỉ cần loại bỏ phần mất mát do khoản phạt phụ thêm gây ra là thu được đáp án bài toán gốc $f(n,m)=f_k(n)+km$. Nếu độ phức tạp của một lần giải bài toán có phạt là $O(T(n))$, thì độ phức tạp tổng thể giảm xuống $O(T(n)\log L)$, trong đó $O(\log L)$ là số lần cần nhị phân trên $k$.

Đó là ý tưởng cơ bản của tìm kiếm nhị phân WQS. Tuy nhiên, để ý tưởng này hoạt động được, $f(n,m)$ phải là hàm lồi theo $m$. Nếu không, có thể không tồn tại khoản phạt phụ thêm $k$ làm cho số lượng tối ưu đúng bằng $m$. Đây cũng là lý do phương pháp tối ưu DP này thường được gọi là "DP tối ưu lồi" hoặc "DP đơn điệu hoàn toàn lồi".

<span id="phương-pháp-truyền-thống"></span>
## Phương pháp truyền thống

Gọi tập không rỗng $X$ là không gian quyết định (hữu hạn), $f:X\rightarrow\mathbf R$ là hàm mục tiêu, và có thêm hàm $g:X\rightarrow\mathbf R^d$ dùng để áp ràng buộc. Bài toán cần giải có thể xem là việc tính giá trị của hàm giá trị $v(y)$ của bài toán tối ưu sau tại một điểm nào đó:

$$
\begin{aligned}
v(y)=\min_{x\in X}\;&f(x)\\
\text{với ràng buộc }&g(x)=y.
\end{aligned}
$$

Ví dụ, với bài toán ràng buộc số lượng đã nêu ở trên, $X$ có thể hiểu là họ tất cả các tập con của tập vật phẩm, $x\in X$ là một tập con cụ thể, $f(x)$ là hàm giá trị của tập con đó, còn $g(x)$ là số phần tử trong tập con $x$. Tất nhiên, $g(x)$ không chỉ có thể là ràng buộc số lượng; phần sau sẽ đưa ra các ví dụ về những điều kiện ràng buộc tổng quát hơn.

???+ info "Quy ước"
    Để trình bày thuận tiện, bài viết này chỉ thảo luận các bài toán cực tiểu hóa hàm mục tiêu. Bài toán cực đại hóa hàm mục tiêu cũng tương tự, chỉ cần thay các hàm lồi (dưới) trong bài viết bằng hàm lõm (còn gọi là lồi trên). Hoặc có thể thêm dấu âm để chuyển bài toán cực đại hóa hàm mục tiêu thành bài toán cực tiểu hóa hàm đối của nó.

<span id="trực-quan-hình-học"></span>
### Trực quan hình học

Vì phần lớn bài toán trong lập trình thi đấu là bài toán tối ưu tổ hợp, không gian quyết định $X$ thường không có cấu trúc tốt. Do đó, ta chuyển sang xét tập

$$
\mathcal D = \{(g(x),f(x))\in\mathbf R\times\mathbf R^d:x\in X\}.
$$

Phương pháp truyền thống chủ yếu giải được trường hợp $d=1$, tức là chỉ có một ràng buộc. Hình dưới đây minh họa một khả năng của tập điểm $\mathcal D$ trong trường hợp đó.

![](../images/wqs-binary-search/wqs-f-g-space.svg)

Các điểm đỏ và xanh trong hình là tập $\mathcal D$ thu được khi chiếu mọi lựa chọn có thể trong $X$ lên mặt phẳng $(g(x),f(x))$. Khi đó, bài toán gốc cần tìm giá trị nhỏ nhất của tung độ $v(y)$ trong các điểm có hoành độ bằng $y$. Khi $y$ thay đổi, tất cả các điểm $(y,v(y))$ như vậy tạo thành tập các điểm đỏ trong hình.

Để tìm tung độ của điểm $(y,v(y))$, có thể dùng một đường thẳng có hệ số góc $\lambda\in\mathbf R$ để "tiếp" tập $\mathcal D$. Như hình minh họa, khi chọn hệ số góc của đường thẳng thích hợp, đường thẳng đi qua điểm $(y,v(y))$ là đường có tung độ gốc $f(x)-\lambda g(x)$ nhỏ nhất trong tất cả các đường thẳng có hệ số góc $\lambda$ và đi qua một điểm của tập $\mathcal D$. Ký hiệu giá trị nhỏ nhất này là

$$
h(\lambda) = \min_{x\in X}f(x)-\lambda g(x).
$$

Vì $(y,v(y))$ cũng nằm trên đường thẳng đó, ta thu được nghiệm của bài toán gốc

$$
v(y) = h(\lambda) + \lambda y.
$$

Giả sử với mọi $\lambda$ trong phạm vi hợp lý, hàm $h(\lambda)$ ở trên đều dễ tính. Trong lập trình thi đấu điều này thường đúng, vì nó đã bỏ đi điều kiện ràng buộc trong bài toán gốc. Khi đó, hai vấn đề quan trọng nhất còn lại là

1.  có tồn tại hệ số góc $\lambda$ của đường thẳng sao cho giá trị tung độ gốc nhỏ nhất đạt được đúng tại điểm $(y,v(y))$ hay không, và
2.  nếu tồn tại, làm thế nào để tìm hệ số góc đó.

Vấn đề thứ nhất tương đối dễ giải quyết. Khi hệ số góc $\lambda$ thay đổi, tập được cắt ra bởi tất cả các đường thẳng này (tức giao của các nửa mặt phẳng phía trên tương ứng) nhất định là một tập lồi. Vì vậy, các đường thẳng này có thể đi qua một điểm khi và chỉ khi điểm đó nằm trên bao lồi dưới của tập lồi này. Điều đó tương đương với việc hàm $v(y)$ là [hàm lồi](./slope-trick.md#hàm-lồi-trên-tập-điểm-rời-rạc).

Vấn đề thứ hai tinh tế hơn. Vì hoành độ của điểm cần tìm đã biết là $y$, một ý tưởng tự nhiên là khi tính $h(\lambda)$, đồng thời tính giá trị của hàm ràng buộc $g(x)$ tại nghiệm tối ưu hiện tại $x_\lambda$. Chẳng hạn, trong ví dụ ở trên, khi giải bài toán có phạt, ta có thể ghi lại số vật phẩm được chọn khi hàm mục tiêu có phạt đạt tối ưu. Sau đó so sánh $g(x_\lambda)$ với $y$ mong muốn và điều chỉnh giá trị $\lambda$ cho lần tính tiếp theo. Đây là phương pháp tìm kiếm nhị phân WQS truyền thống nhất.

Tóm lại, quy trình cơ bản của tìm kiếm nhị phân WQS truyền thống như sau:

1.  Ban đầu chọn một khoảng hợp lý cho $\lambda$;
2.  chọn một $\lambda$ trong khoảng hiện tại;
3.  giải bài toán có phạt $h(\lambda)=\min_{x\in X}f(x)-\lambda g(x)$, đồng thời ghi lại giá trị $g(x_\lambda)$ của $g(x)$ tại nghiệm tối ưu $x_\lambda$;
4.  nếu $g(x_\lambda)=y$, thu được giá trị tối ưu của bài toán gốc $v(y)=h(\lambda)+\lambda y$ và kết thúc thuật toán;
5.  nếu không, dựa vào quan hệ lớn nhỏ giữa $g(x_\lambda)$ và $y$ để điều chỉnh khoảng của $\lambda$, rồi quay lại bước 2.

Quy trình cơ bản này đã đủ để giải một số bài toán, nhưng chưa hoàn chỉnh. Tiếp theo, bài viết sẽ thảo luận các cải tiến cho quy trình cơ bản này.

<span id="xử-lý-trường-hợp-thẳng-hàng"></span>
### Xử lý trường hợp thẳng hàng

Vấn đề đầu tiên gặp phải khi áp dụng quy trình cơ bản là trường hợp thẳng hàng không được xử lý đúng.

Nếu trên bao lồi dưới của tập điểm $\mathcal D$ có ba điểm đỏ trở lên thẳng hàng, thì trong quy trình cơ bản ở trên, có thể không phán đoán đúng quan hệ giữa $g(x_\lambda)$ và $y$. Chẳng hạn, giả sử ba điểm đỏ thẳng hàng có hoành độ lần lượt là $y_1,y_2,y_3$, và đường thẳng đi qua chúng có hệ số góc $\lambda^*$. Khi đó, để giải đúng $v(y_2)$, phải bảo đảm rằng bài toán được tính ở lần cuối khi thuật toán dừng là $h(\lambda^*)$, vì $\lambda^*$ là hệ số góc duy nhất của đường thẳng có thể đi qua điểm $(y_2,v(y_2))$ khi tối thiểu hóa tung độ gốc. Tuy nhiên, khi giải $h(\lambda^*)$, giá trị $g(x_{\lambda^*})$ được ghi lại có thể là bất kỳ giá trị nào trong $y_1,y_2,y_3$. Nếu giá trị ghi được không bằng $y_2$, thuật toán sẽ tiếp tục chạy sai và điều chỉnh khoảng $\lambda$ theo hướng rời xa $y_2$, cuối cùng thu được kết quả sai.

Để xử lý trường hợp thẳng hàng, một cách làm là khi ghi lại $g(x_\lambda)$ của nghiệm tối ưu $x_\lambda$, luôn làm cho nó lớn nhất có thể (hoặc nhỏ nhất có thể). Đồng thời, thay điều kiện dừng của nhị phân từ việc tìm $\lambda$ thỏa chính xác $g(x_\lambda)=y$ thành tìm $\lambda$ nhỏ nhất (hoặc lớn nhất) thỏa $g(x_\lambda)\ge y$ (hoặc $g(x_\lambda)\le y$). Trong ví dụ ở đoạn trước, điều này tương đương với việc khi tính $h(\lambda^*)$, giá trị $g(x_{\lambda^*})$ xuất ra là $y_3$. Như vậy có thể bảo đảm rằng bài toán được tính ở lần cuối khi thuật toán dừng là $h(\lambda^*)$. Khi cài đặt cách này, cần chú ý giá trị xuất cuối cùng không phải là $h(\lambda)+\lambda g(x_{\lambda})$ mà là $h(\lambda)+\lambda y$, vì $g(x_\lambda)$ được ghi lại chưa chắc bằng ràng buộc thực tế $y$.

Một cách xử lý khác là nhị phân trên số thực. Nếu các con số trong bài toán đều là số nguyên, rõ ràng hệ số góc trong tìm kiếm nhị phân WQS cũng là số nguyên. Việc đưa số thực vào nhị phân nhằm bảo đảm rằng khi loại nhầm lựa chọn đúng $\lambda^*$, ta vẫn có thể nhờ phần thập phân để điều chỉnh quay lại và cuối cùng tiệm cận đáp án đúng $\lambda^*$. Ví dụ, trong ví dụ trên, nếu khi tính $h(\lambda^*)$, giá trị $g(x_{\lambda^*})$ được ghi là $y_1$, nhỏ hơn $y_2$ mong muốn, thuật toán sẽ chuyển sang xét khoảng $(\lambda^*,\lambda_r]$, trong đó $\lambda_r$ là đầu phải của khoảng chứa $\lambda$. Với trường hợp nguyên, khoảng này thực ra phải viết là $[\lambda_*+1,\lambda_r]$, nên đã loại bỏ khả năng tiến gần đáp án đúng $\lambda^*$ trong các bước sau. Nhưng khi nhị phân trên số thực, khoảng được xét vẫn là $(\lambda^*,\lambda_r]$; hơn nữa, với mọi $\lambda$ trong khoảng này, khi giải $h(\lambda)$ thì $g(x_\lambda)$ được ghi luôn không nhỏ hơn $y_3$, do đó lớn hơn hẳn $y_2$. Vì vậy, khi thuật toán tiếp tục, nó sẽ liên tục bỏ nửa phải, cuối cùng bảo đảm khoảng của $\lambda$ nằm gần $\lambda^*$. Tất nhiên, vì đã biết hệ số góc cần tìm là một số nguyên, độ chính xác khi dừng nhị phân thực không cần quá cao; chỉ cần bảo đảm trong khoảng nhị phân chỉ còn một số nguyên, số nguyên đó chính là $\lambda^*$ cần tìm.

Sau khi xử lý đúng trường hợp thẳng hàng, tìm kiếm nhị phân WQS đã đủ để giải phần lớn các bài toán WQS trong lập trình thi đấu. Tuy nhiên, phương pháp này vẫn có một số thiếu sót: nó không xử lý được trường hợp khó ghi lại $g(x_\lambda)$, cũng không xử lý được trường hợp nhiều điểm đồng phẳng trong WQS nhiều chiều. Bài viết sẽ tiếp tục khảo sát tính chất của bài toán tối ưu $v(y)$ và đưa ra phương pháp tổng quát hơn.

<span id="phương-pháp-đối-ngẫu"></span>
## Phương pháp đối ngẫu

Mục này giới thiệu một cách cài đặt tìm kiếm nhị phân WQS chỉ yêu cầu với mọi $\lambda\in\mathbf R^d$, ta có thể tính hiệu quả giá trị của

$$
h(\lambda) = \min_{x\in X}f(x)-\lambda\cdot g(x)
$$

và giá trị tối ưu $v(y)$ của bài toán gốc là hàm lồi theo $y\in\mathbf R^d$[^high-d-convex]. Tóm gọn trong một câu, mục này sẽ chứng minh rằng hàm giá trị $v(y)$ của bài toán gốc đúng bằng giá trị tối ưu của bài toán đối ngẫu

$$
v^\star(y) = \sup_{\lambda\in\mathbf R^d} h(\lambda)+\lambda\cdot y,
$$

còn hàm mục tiêu của bài toán đối ngẫu là hàm lõm theo $\lambda\in\mathbf R^d$, do đó là hàm đơn đỉnh và có thể được giải hiệu quả bằng [tìm kiếm tam phân](../../basic/binary.md#tìm-kiếm-tam-phân) hoặc [tìm kiếm tỉ lệ vàng](../../basic/binary.md#tối-ưu-phương-pháp-lát-cắt-vàng), với độ phức tạp vẫn là $O(T(n)\log^d L)$. Điều này giải quyết hoàn toàn vấn đề giá trị $g(x_\lambda)$ được ghi trong phương pháp WQS truyền thống có thể gây lỗi, đồng thời cho phép áp dụng tư tưởng WQS cho trường hợp nhiều chiều.

Ngoài ra, mục này còn chỉ ra rằng phạm vi của $g(x_\lambda)$ có thể được suy ra từ $h(\lambda)$ mà không cần ghi thêm khi giải $h(\lambda)$. Ví dụ, với $d=1$ và bài toán chỉ liên quan đến số nguyên, có thể chứng minh phạm vi giá trị của $g(x_\lambda)$ đúng bằng

$$
[h(\lambda-1)-h(\lambda),h(\lambda)-h(\lambda+1)].
$$

Trên thực tế, điều này cũng cung cấp thêm một cách xử lý vấn đề thẳng hàng cho những bài vẫn buộc phải dùng quy trình nhị phân đã nêu ở trước.

Tiếp theo, mục này sẽ dùng lý thuyết giải tích lồi để chứng minh các kết luận trên. Về ứng dụng cụ thể của những phương pháp này, có thể tham khảo mục [Ví dụ](#ví-dụ).

<span id="đối-ngẫu-lagrange"></span>
### Đối ngẫu Lagrange

Xét việc dùng [phương pháp nhân tử Lagrange](https://en.wikipedia.org/wiki/Lagrange_multiplier) để giải bài toán. Đưa vào nhân tử Lagrange $\lambda\in\mathbf R^d$, khi đó Lagrangian có thể viết là

$$
L(x,\lambda,y) = f(x) - \lambda\cdot g(x)+\lambda\cdot y.
$$

Vì chỉ cần $g(x)-y$ có một thành phần khác không, ta có thể cho thành phần tương ứng của $\lambda$ tiến tới vô cùng (dương hoặc âm), nên

$$
\sup_{\lambda\in\mathbf R^d}L(x,\lambda,y)
= \begin{cases}
f(x),&g(x)=y,\\
+\infty,&\text{ngược lại}.
\end{cases}
$$

Điều này cho thấy bài toán gốc có thể viết thành

$$
\begin{aligned}
v(y) &= \min_{x\in X}\sup_{\lambda\in\mathbf R^d}L(x,\lambda,y).
\end{aligned}
$$

Hoán đổi hai phép cực trị sẽ thu được [bài toán đối ngẫu](https://en.wikipedia.org/wiki/Duality_%28optimization%29):

$$
\begin{aligned}
v^\star(y)&=\sup_{\lambda\in\mathbf R^d}\min_{x\in X}L(x,\lambda,y)\\
&=\sup_{\lambda\in\mathbf R^d}h(\lambda)+\lambda\cdot y.
\end{aligned}
$$

Điều sắp chứng minh là: dưới điều kiện $v(y)$ là hàm lồi theo $y$, đối ngẫu mạnh (strong duality) được thỏa mãn, tức là $v^\star(y)=v(y)$.

<span id="liên-hợp-lồi"></span>
### Liên hợp lồi

Để chứng minh đối ngẫu mạnh, cần đưa vào khái niệm liên hợp lồi.

???+ abstract "Liên hợp lồi"
    Với hàm $f:\mathbf R^d\rightarrow\mathbf R\cup\{\pm\infty\}$, **liên hợp lồi** (convex conjugate) của nó, hay còn gọi là **biến đổi Legendre-Fenchel** (Legendre-Fenchel transformation), là hàm
    
    $$
    f^*(x^*) = \sup_{x\in\mathbf R^d}x^*\cdot x - f(x).
    $$

Nhìn từ biến $x^*$, $f^*(x^*)$ là cận trên đúng của một họ các hàm tuyến tính, nên nhất định là hàm lồi trên $\mathbf R^d$.

???+ info ""Vector hệ số góc" và "tung độ gốc" của siêu phẳng"
    Các phương trình siêu phẳng trong không gian vector $\mathbf R^{d+1}$ được thảo luận trong bài viết này đều có dạng
    
    $$
    y = k\cdot x + b.
    $$
    
    Nói cách khác, bài viết này không xét các siêu phẳng song song với trục $y$. Để tiện trình bày, bài viết gọi không hoàn toàn chặt chẽ $k$ là "vector hệ số góc" của siêu phẳng, và $b$ là "tung độ gốc" của nó. Viết phương trình siêu phẳng này theo dạng chuẩn hơn sẽ là
    
    $$
    k\cdot x - y = -b.
    $$
    
    Một vector pháp tuyến của nó là $(k,-1)$. Vì vậy, cái gọi là vector hệ số góc thực ra là $d$ thành phần đầu của vector pháp tuyến thu được sau khi chuẩn hóa vector pháp tuyến của siêu phẳng sao cho thành phần cuối của nó bằng $-1$.

Về trực quan hình học, liên hợp lồi của hàm $f(x)$ mô tả điều sau: với mọi siêu phẳng có vector hệ số góc $x^*$ và cắt epigraph

$$
\operatorname{epi}f = \{(x,y)\in\mathbf R^d\times\mathbf R:f(x)\le y\}
$$

của hàm $f(x)$, giá trị nhỏ nhất của tung độ gốc $f(x)-x^*\cdot x$ là $-f^*(x^*)$. Nói cách khác, hàm $f(x)$ luôn nằm phía trên siêu phẳng $y = x^*\cdot x-f^*(x^*)$ và tiếp xúc với siêu phẳng đó tại điểm $(x_0,f(x_0))$; tất nhiên có thể tồn tại các điểm tiếp xúc khác. Siêu phẳng như vậy được gọi là **siêu phẳng đỡ** (supporting hyperplane) của $f(x)$ tại $x_0$. Tung độ gốc của một siêu phẳng đỡ của hàm $f(x)$ được xác định duy nhất bởi vector hệ số góc của nó; liên hợp lồi chính là ánh xạ từ vector hệ số góc đến tung độ gốc.

Việc cực tiểu hóa $f(x)-\lambda\cdot g(x)$ trên tập $X$ tương đương với việc cực tiểu hóa $v(y)-\lambda\cdot y$ trên tập $\{(y,v(y))\}$:

$$
\begin{aligned}
\min_x f(x)-\lambda\cdot g(x) &= \min_{y\in g(X)}\left(\min_{x\in X:g(x)=y} f(x) - \lambda\cdot g(x)\right)\\
&= \min_{y\in g(X)}\left(\min_{x\in X:g(x)=y} f(x)\right) - \lambda\cdot y \\
&= \min_{y\in g(X)}v(y) - \lambda\cdot y.
\end{aligned}
$$

Do đó,

$$
h(\lambda) = \min_{y\in g(X)}v(y) - \lambda\cdot y = -v^*(\lambda).
$$

Điều này cho thấy $h(\lambda)$ là hàm lõm theo $\lambda\in\mathbf R^d$. Hơn nữa,

$$
v^\star(y) = \sup_{\lambda\in\mathbf R^d}\lambda\cdot y-v^*(\lambda) = v^{**}(y).
$$

Nói cách khác, hàm giá trị $v^{\star}(y)$ của bài toán đối ngẫu là liên hợp lồi hai lần của hàm giá trị $v(y)$ của bài toán gốc, còn gọi là **song liên hợp** (biconjugate).

Vì vậy, bài toán được chuyển thành: loại hàm $v(y)$ nào có song liên hợp đúng bằng chính nó? Câu trả lời được cho bởi định lý sau:

???+ note "Định lý (Fenchel-Moreau)"
    Với hàm $f:\mathbf R^d\rightarrow\mathbf R\cup\{\pm\infty\}$, song liên hợp của nó bằng chính nó, tức $f^{**}=f$, khi và chỉ khi một trong ba điều kiện sau thỏa mãn:
    
    1.  $f(x)$ là hàm lồi proper và [nửa liên tục dưới](https://en.wikipedia.org/wiki/Semi-continuity),
    2.  $f(x)\equiv+\infty$, hoặc
    3.  $f(x)\equiv-\infty$.

??? note "Chứng minh"
    Một hàm là proper khi và chỉ khi nó không bao giờ nhận giá trị $-\infty$ và không luôn luôn nhận giá trị $+\infty$.
    
    Với trường hợp hàm không proper, có thể kiểm chứng $f(x)\equiv+\infty$ và $f(x)\equiv-\infty$ là liên hợp của nhau. Ngoài ra, chỉ cần $f(x)$ nhận giá trị $-\infty$ tại bất kỳ điểm nào thì nhất định có $f^*(x^*)\equiv+\infty$. Vì vậy, các hàm không proper thỏa $f^{**}=f$ chỉ có hai trường hợp này. Phần thảo luận sau chỉ xét hàm proper. Với hàm proper, điều kiện nửa liên tục dưới và lồi tương đương với epigraph của nó là một tập lồi đóng.
    
    Tính cần thiết của điều kiện này khá dễ thấy. Vì $f=f^{**}$ là liên hợp lồi của $f^*$, và với tư cách là cận trên đúng của một họ các hàm tuyến tính, epigraph của nó nhất định là giao của một họ các tập lồi đóng, nên nhất định là tập lồi đóng. Điều này cho thấy hàm proper thỏa $f^{**}=f$ nhất định là nửa liên tục dưới và lồi.
    
    Chiều ngược lại, các điều kiện này cũng là đủ. Giống chứng minh của các định lý đối ngẫu mạnh khác, chứng minh có thể chia thành hai bước.
    
    Bước thứ nhất, chứng minh đối ngẫu yếu, tức $f(x)\ge f^{**}(x)$. Theo định nghĩa của liên hợp lồi, với mọi $x,x^*\in\mathbf R^d$, ta có
    
    $$
    f^*(x^*) \ge x^*\cdot x-f(x).
    $$
    
    Điều này suy ra với mọi $x,x^*\in\mathbf R^d$ cũng có
    
    $$
    f(x) \ge x^*\cdot x-f^*(x^*).
    $$
    
    Lấy cận trên đúng theo $x^*$ ở vế phải bất đẳng thức, ta được $f(x)\ge f^{**}(x)$.
    
    Bước thứ hai, dùng [định lý tách siêu phẳng](https://en.wikipedia.org/wiki/Hyperplane_separation_theorem) để chứng minh $f(x)\le f^{**}(x)$. Giả sử ngược lại, tồn tại $x_0\in\mathbf R^d$ sao cho $f(x_0)>f^{**}(x_0)$. Vì epigraph $\operatorname{epi}(f)$ của $f(x)$ là tập lồi đóng, còn tập một điểm $\{(x_0,f^{**}(x_0))\}$ là tập lồi compact, nên theo định lý tách siêu phẳng, tồn tại $(\lambda,t)\in\mathbf R^d\times\mathbf R$ và $\alpha\in\mathbf R$ sao cho với mọi $x\in\operatorname{dom} f:=\{x\in\mathbf R^d:f(x)<+\infty\}$ và mọi $y\ge f(x)$ đều có
    
    $$
    \lambda\cdot x-ty <\alpha <\lambda\cdot x_0 - tf^{**}(x_0)
    $$
    
    đúng. Vì $y$ có thể được chọn lớn tùy ý, nhất định phải có $t\ge 0$. Lại chia thành hai trường hợp.
    
    Trước hết xét trường hợp $t>0$. Khi đó, chia mọi phần của bất đẳng thức cho $t$, đặt $\lambda'=t^{-1}\lambda$ và $\alpha'=t^{-1}\alpha$, ta được
    
    $$
    \lambda'\cdot x-y < \alpha'< \lambda'\cdot x_0-f^{**}(x_0).
    $$
    
    Với mọi $x\in\operatorname{dom} f$, lấy $y=f(x)$, đều có
    
    $$
    \alpha' > \lambda'\cdot x - f(x).
    $$
    
    Do đó, lấy cận trên đúng theo $x$ ở vế phải,
    
    $$
    \alpha' \ge \sup_{x\in\mathbf R^d}\lambda'\cdot x - f(x) = f^*(\lambda').
    $$
    
    Suy ra
    
    $$
    f^{**}(x_0) < \lambda'\cdot x_0-f^*(\lambda') \le \sup_{x^*\in\mathbf R^d}x^*\cdot x_0-f^*(x^*) = f^{**}(x_0).
    $$
    
    Mâu thuẫn này cho thấy trường hợp $t>0$ không thể xảy ra.
    
    Cuối cùng xét trường hợp $t=0$. Trên thực tế, ta sẽ chứng minh rằng có thể dùng nhiễu nhỏ để chuyển nó về trường hợp $t>0$. Lấy tùy ý $\lambda_0\in\operatorname{dom}f^*$, theo định nghĩa liên hợp lồi, với mọi $x\in\operatorname{dom}f$ và $y\ge f(x)$ đều có
    
    $$
    \lambda_0\cdot x-y\le f^*(\lambda_0).
    $$
    
    Vì vậy, với mọi $\varepsilon>0$, ta có
    
    $$
    (\lambda+\varepsilon\lambda_0)\cdot x - \varepsilon y<\alpha+\varepsilon f^*(\lambda_0).
    $$
    
    Đồng thời, vì $\alpha<\lambda\cdot x_0$, nên với $\varepsilon>0$ đủ nhỏ, lại có
    
    $$
    \alpha+\varepsilon f^*(\lambda_0) < (\lambda+\varepsilon\lambda_0)\cdot x_0 - \varepsilon f^{**}(x_0).
    $$
    
    Do đó, nếu lấy $\lambda'=\lambda+\varepsilon\lambda_0$, $t'=\varepsilon$ và $\alpha'=\alpha+\varepsilon f^*(\lambda_0)$, thì có
    
    $$
    \lambda'\cdot x-t'y <\alpha' <\lambda'\cdot x_0 - t'f^{**}(x_0).
    $$
    
    Điều này lại quay về trường hợp trước và vẫn dẫn đến mâu thuẫn.
    
    Mâu thuẫn này cho thấy không tồn tại điểm $x_0\in\mathbf R^d$ thỏa $f(x_0)>f^{**}(x_0)$. Vì vậy luôn có $f(x_0)\le f^{**}(x_0)$.
    
    Kết hợp kết quả của hai bước chứng minh, ta thu được $f^{**}(x)=f(x)$.

Do đó, đối ngẫu mạnh được thỏa mãn khi và chỉ khi $v(y)$ là hàm lồi theo $y\in\mathbf R^d$[^other-conditions].

<span id="dưới-gradient"></span>
### Dưới gradient

Mục trước đã chỉ ra rằng hàm giá trị $h(\lambda)$ của bài toán có phạt là số đối của liên hợp lồi của hàm giá trị $v(y)$ của bài toán gốc. Vì định nghĩa liên hợp lồi thực chất là một bài toán tối ưu có tham số, nó cũng có kết luận tương tự [định lý bao](https://en.wikipedia.org/wiki/Envelope_theorem). Tuy nhiên, vì hàm lồi không khả vi ở mọi nơi, trước hết cần mở rộng định nghĩa đạo hàm cho trường hợp hàm lồi. Điều này dẫn đến khái niệm dưới gradient.

???+ abstract "Dưới gradient"
    Với hàm lồi $f:\mathbf R^d\rightarrow\mathbf R\cup\{\pm\infty\}$ và $x_0\in\operatorname{dom}f$, nếu vector $x^*\in\mathbf R^d$ thỏa với mọi $x\in\mathbf R^d$,
    
    $$
    f(x) \ge f(x_0)+x^*\cdot(x-x_0),
    $$
    
    thì gọi $x^*$ là một **dưới gradient** (subgradient) của $f(x)$ tại $x_0$. Tập tất cả các dưới gradient của hàm $f(x)$ tại $x_0$ được gọi là **dưới vi phân** (subdifferential) tại đó, ký hiệu $\partial f(x_0)$.

Về trực quan hình học, dưới vi phân của hàm lồi $f(x)$ tại $x_0$ chính là tập vector hệ số góc của tất cả các siêu phẳng đỡ của nó tại đó. Với trường hợp một chiều, dưới vi phân

$$
\partial f(x_0) = [\partial_-f(x_0),\partial_+f(x_0)],
$$

trong đó $\partial_-f(x_0)$ và $\partial_+f(x_0)$ lần lượt là đạo hàm trái và đạo hàm phải của hàm $f(x)$ tại $x_0$. Hơn nữa, với $\tilde f(x)$ được mở rộng từ hàm lồi $f:\mathbf Z\rightarrow\mathbf R\cup\{\pm\infty\}$ trên tập số nguyên, đạo hàm trái và phải của nó tại điểm nguyên $x=k$ chính là sai phân bậc một ở hai phía:

$$
\partial\tilde f(k) = [f(k)-f(k-1),f(k+1)-f(k)]. 
$$

Rõ ràng, hàm lồi $f(x)$ khả vi tại điểm $x_0$ khi và chỉ khi dưới vi phân $\partial f(x_0)$ của nó tại đó là tập một điểm.

Vì liên hợp lồi cung cấp ánh xạ từ vector hệ số góc của siêu phẳng đỡ đến tung độ gốc của nó, ta có thể dùng liên hợp lồi để phán đoán liệu một vector hệ số góc $x^*$ có phải là một dưới gradient của hàm lồi $f(x)$ tại điểm đã cho $x$ hay không.

???+ note "Định lý (liên hợp lồi và dưới gradient)"
    Với hàm lồi proper $f:\mathbf R^d\rightarrow\mathbf R$ và mọi $x,x^*\in\mathbf R^d$, ta có
    
    $$
    x^*\in\partial f(x) \iff x^*\cdot x = f(x) + f^*(x^*).
    $$
    
    Hơn nữa, nếu $f$ còn nửa liên tục dưới, thì hai điều kiện này đều tương đương với $x\in\partial f^*(x^*)$.

??? note "Chứng minh"
    Theo định nghĩa dưới gradient, $x^*\in\partial f(x)$ khi và chỉ khi
    
    $$
    f(x') \ge f(x) + x^*\cdot(x'-x),~\forall x'\in\mathbf R^d.
    $$
    
    Điều này tương đương với
    
    $$
    x^*\cdot x - f(x) \ge x^*\cdot x'-f(x'),~\forall x'\in\mathbf R^d.
    $$
    
    Lại tương đương với
    
    $$
    x^*\cdot x - f(x) \ge \sup_{x'\in\mathbf R^d}x^*\cdot x'-f(x') = f^*(x^*).
    $$
    
    Nhưng theo định nghĩa liên hợp lồi, luôn có
    
    $$
    x^*\cdot x - f(x) \le f^*(x^*).
    $$
    
    Vì vậy, dấu lớn hơn hoặc bằng trong biểu thức trước thực ra tương đương với dấu bằng, tức tương đương với
    
    $$
    x^*\cdot x = f(x) + f^*(x^*).
    $$
    
    Điều này hoàn thành phần chứng minh thứ nhất.
    
    Khi $f$ là hàm lồi proper nửa liên tục dưới, theo định lý Fenchel-Moreau, có $f^{**}=f$. Do đó, hai điều kiện này tương đương với
    
    $$
    x^*\cdot x = f^*(x^*) + f^{**}(x).
    $$
    
    Áp dụng lại kết luận ở phần thứ nhất, chúng cũng tương đương với $x\in\partial f^*(x^*)$.

Kết luận này cho thấy nếu $f^{**}=f$, thì dưới vi phân $\partial f^{*}(x^*)$ của liên hợp lồi $f^*$ tại $x^*$ chính là tập các thành phần $x$ của những giao điểm giữa siêu phẳng đỡ có vector hệ số góc $x^*$ và epigraph $\operatorname{epi}f$.

???+ note "Hệ quả"
    Với hàm lồi proper nửa liên tục dưới $f:\mathbf R^d\rightarrow\mathbf R$ và mọi $x,x^*\in\mathbf R^d$, ta có
    
    $$
    \begin{aligned}
    \partial f(x) &= \arg\max_{y^*\in\mathbf R^d} x\cdot y^* - f^*(y^*),\\
    \partial f^*(x^*) &= \arg\max_{y\in\mathbf R^d} x^*\cdot y - f(y).
    \end{aligned}
    $$

??? note "Chứng minh"
    Sau đây chứng minh đẳng thức thứ hai. Đẳng thức thứ nhất chứng minh tương tự.
    
    Theo định nghĩa liên hợp lồi, có
    
    $$
    f^*(x^*) = \sup_{y\in\mathbf R^d} x^*\cdot y - f(y),
    $$
    
    nên
    
    $$
    x \in \arg\max_{y\in\mathbf R^d} x^*\cdot y - f(y)
    $$
    
    khi và chỉ khi $f^*(x^*) = x^*\cdot x - f(x)$; mà đẳng thức này đúng khi và chỉ khi $x\in\partial f^*(x^*)$. Điều này chứng minh hai tập bằng nhau.

Áp dụng vào bối cảnh của bài viết, kết luận này cho thấy khi giải bài toán

$$
h(\lambda) = \min_{x\in X}f(x)-\lambda\cdot g(x) = \min_{y\in g(X)}v(y) - \lambda\cdot y
$$

thì các giá trị của hàm ràng buộc $g(x)$ trên tập quyết định tối ưu đúng bằng $\partial(-h(\lambda))$. Với $d=1$ và bài toán chỉ liên quan đến số nguyên, tập này chính là khoảng

$$
[h(\lambda-1)-h(\lambda),h(\lambda)-h(\lambda+1)].
$$

Với các $\lambda$ nguyên liên tiếp, những khoảng này nối đầu đuôi với nhau, nên nếu dùng cho nhị phân, chỉ cần tính một đầu mút là đủ.

<span id="chứng-minh-tính-lồi"></span>
## Chứng minh tính lồi

Điều kiện tiên quyết để áp dụng tìm kiếm nhị phân WQS là tính lồi của hàm giá trị. Trong lập trình thi đấu, có thể đoán tính lồi bằng cách lập bảng, trực giác, v.v. Tuy nhiên, chứng minh chặt chẽ tính lồi thường không dễ. Mục này kết hợp với bài toán kinh điển sau để giới thiệu các phương pháp chứng minh tính lồi thường gặp trong lập trình thi đấu.

???+ example "Bài toán trồng cây"
    Có $n$ hố cây, cần trồng $m$ cây. Không được trồng cây ở hai hố kề nhau. Cho dãy độ dài $n$ là $\{a_i\}$, biểu thị lợi ích khi trồng cây ở mỗi hố, lợi ích có thể dương hoặc âm. Hãy tìm tổng lợi ích lớn nhất có thể sau khi trồng đủ $m$ cây.
    
    Nói ngắn gọn, đây là bài toán tìm tập độc lập trọng số lớn nhất có kích thước $m$ trên một đường thẳng độ dài $n$.

Các phương pháp này có thể chia sơ bộ thành bốn loại:

-   Quy về tính lồi theo tham số của hàm giá trị trong bài toán tối ưu lồi (bao gồm [quy hoạch tuyến tính](../../math/linear-programming.md), v.v.), trong đó có các cách như xây dựng mô hình [luồng chi phí](../../graph/flow/min-cost.md);
-   dùng phương trình chuyển trạng thái để chứng minh quy nạp tính lồi, trong quá trình đó có thể dùng một số [phép biến đổi bảo toàn tính lồi](./slope-trick.md#các-phép-biến-đổi-hàm-lồi);
-   với các bài toán phân đoạn khoảng, có thể kiểm chứng hàm chi phí của mỗi đoạn thỏa [bất đẳng thức tứ giác](./quadrangle.md);
-   cuối cùng, với các bài toán đặc biệt, cũng có thể dùng lập luận trao đổi để trực tiếp chứng minh tính lồi.

Bản thân các phương pháp chứng minh này thường gắn với một cách giải nào đó của bài toán.

<span id="quy-về-tối-ưu-lồi-có-tham-số"></span>
### Quy về tối ưu lồi có tham số

Xét bài toán tối ưu lồi có tham số dạng sau:

$$
v(y)=\inf_{x\in\mathcal D(y)} f(x,y).
$$

Trong đó, với mỗi $y\in\mathbf R^d$, hàm mục tiêu $f:\mathbf R^n\times\mathbf R^d\rightarrow\mathbf R\cup\{\pm\infty\}$ là hàm lồi theo $x\in\mathbf R^m$, còn miền khả thi $\mathcal D:\mathbf R^d\rightarrow \mathcal P(\mathbf R^m)$ là hàm nhận giá trị là tập trên $\mathbf R^d$, và với mỗi $y\in\mathbf R^d$, tập $\mathcal D(y)$ đều là tập lồi. Các điều kiện này bảo đảm rằng với mọi tham số $y\in\mathbf R^d$, đây đều là một bài toán tối ưu lồi.

???+ note "Định lý"
    Giả sử bài toán tối ưu lồi có tham số ở trên thỏa các điều kiện sau:
    
    1.  Hàm mục tiêu $f(x,y)$ là hàm lồi theo $(x,y)$;
    2.  đồ thị $\{(x,y):x\in\mathcal D(y)\}$ của ánh xạ miền khả thi $y\mapsto\mathcal D(y)$ là tập lồi.
    
    Nếu với mọi $y\in\mathbf R^d$ đều có $v(y)>-\infty$, thì hàm giá trị $v(y)$ là hàm lồi proper theo $y$.

??? note "Chứng minh"
    Với mọi $y_1,y_2\in\mathbf R^d$ và $\alpha\in(0,1)$, cần chứng minh
    
    $$
    v(\alpha y_1+(1-\alpha)y_2) \le \alpha v(y_1) + (1-\alpha) v(y_2).
    $$
    
    Nếu $v(y_1)=+\infty$ hoặc $v(y_2)=+\infty$, vế phải của bất đẳng thức là $+\infty$, nên bất đẳng thức hiển nhiên đúng. Ngược lại, $v(y_1)$ và $v(y_2)$ đều hữu hạn. Với mọi $\varepsilon>0$ và $i=1,2$, tồn tại $x_i\in\mathcal D(y_i)$ sao cho $f(x_i,y_i)< v(y_i)+\varepsilon$. Dùng tính lồi của đồ thị ánh xạ $\mathcal D$, ta có
    
    $$
    \alpha x_1+(1-\alpha)x_2 \in \mathcal D(\alpha y_1+(1-\alpha)y_2).
    $$
    
    Nói cách khác, $\alpha x_1+(1-\alpha)x_2$ là một nghiệm khả thi của bài toán tối ưu có tham số $\alpha y_1+(1-\alpha)y_2$. Dùng điều kiện tối ưu và tính lồi của hàm mục tiêu, ta được
    
    $$
    \begin{aligned}
    v(\alpha y_1+(1-\alpha)y_2)
    &\le f(\alpha x_1+(1-\alpha)x_2,\alpha y_1+(1-\alpha)y_2) \\
    &\le \alpha f(x_1,y_1) + (1-\alpha)f(x_2,y_2) \\
    &< \alpha v(y_1) + (1-\alpha) v(y_2) + \varepsilon.
    \end{aligned}
    $$
    
    Vì $\varepsilon$ được chọn tùy ý, cho $\varepsilon\rightarrow 0$, ta có
    
    $$
    v(\alpha y_1+(1-\alpha)y_2) \le \alpha v(y_1) + (1-\alpha) v(y_2).
    $$
    
    Do đó, tính lồi của hàm giá trị $v(y)$ được chứng minh.

Trong lập trình thi đấu, bài toán tối ưu lồi thường gặp nhất là quy hoạch tuyến tính.

???+ note "Hệ quả"
    Gọi $c\in\mathbf R^n$, $A_1\in\mathbf R^{d_1\times n}$, $A_2\in\mathbf R^{d_2\times n}$, $y_1\in\mathbf R^{d_1}$, $y_2\in\mathbf R^{d_2}$. Xét bài toán quy hoạch tuyến tính có tham số sau:
    
    $$
    v(y_1,y_2)=\min_{x\in\mathbf R^n} c\cdot x \text{ với ràng buộc }A_1x\le y_1,A_2x=y_2,x\ge 0.
    $$
    
    Khi đó, hàm giá trị $v(y_1,y_2)$ là hàm lồi theo $(y_1,y_2)$.

Bất kể là ràng buộc bất đẳng thức hay ràng buộc đẳng thức, hàm giá trị của quy hoạch tuyến tính đều là hàm lồi theo tham số trong điều kiện ràng buộc.

Nhiều bài toán đồ thị có thể viết dưới dạng bài toán quy hoạch tuyến tính:

-   Bài toán luồng mạng: luồng cực đại, cắt cực tiểu, luồng chi phí nhỏ nhất;
-   bài toán đường đi ngắn nhất không có chu trình âm;
-   ghép cặp cực đại (có trọng số) trên đồ thị hai phía, phủ đỉnh nhỏ nhất, v.v.;
-   ghép cặp cực đại (có trọng số) trên đồ thị tổng quát;
-   bài toán cây khung nhỏ nhất[^mst].

Vì vậy, hàm giá trị của các bài toán này đều là hàm lồi (hoặc lõm) theo tham số của bài toán.

???+ warning "Ràng buộc nguyên"
    Khi dùng mô hình đồ thị để mô hình hóa bài toán thực tế, thường có ràng buộc nguyên ẩn, ví dụ một cạnh chỉ có thể được chọn hoặc không được chọn, lưu lượng chỉ có thể là số nguyên, v.v. Do đó, chúng chỉ có thể chuyển thành bài toán quy hoạch tuyến tính nguyên (integer linear programming, ILP) chứ không phải bài toán quy hoạch tuyến tính (LP). Vì ILP không phải bài toán tối ưu lồi, hàm giá trị của nó chưa chắc là hàm lồi theo tham số bài toán. Sau khi nới lỏng ràng buộc nguyên trong một bài toán ILP, ta thu được một bài toán LP, nhưng bài toán sau chưa chắc tồn tại nghiệm tối ưu thỏa ràng buộc nguyên. Vì vậy, giá trị tối ưu của LP sau khi nới lỏng ràng buộc nguyên có thể tốt hơn hẳn bài toán ILP tương ứng; hai bài toán chưa chắc tương đương.
    
    Các bài toán đồ thị được liệt kê ở trên đều có thể viết thành một bài toán LP mà không cần áp ràng buộc nguyên; nhưng với một số bài toán khác, chẳng hạn bài toán tập độc lập cực đại trên đồ thị tổng quát, ràng buộc nguyên là cần thiết. Ngoài ra, ngay cả khi một bài toán đồ thị có thể viết dưới dạng LP, sau khi thêm ràng buộc tuyến tính bổ sung vào bài toán, tính tương đương giữa ILP và LP tương ứng vẫn có thể bị phá vỡ, khiến bài toán đồ thị có ràng buộc đó không còn viết được dưới dạng quy hoạch tuyến tính.

Ví dụ, trong ngữ cảnh luồng chi phí, có kết luận thường gặp sau:

???+ note "Hệ quả"
    Trong [mô hình luồng chi phí nhỏ nhất](../../graph/flow/min-cost.md), chi phí nhỏ nhất $v(m)$ là hàm lồi theo lưu lượng $m$.

??? note "Chứng minh"
    Gọi đồ thị có hướng là $G=(V,E)$, dung lượng cạnh $(i,j)$ là $c_{ij}$, chi phí cho một đơn vị lưu lượng là $w_{ij}$, đỉnh nguồn và đỉnh đích lần lượt là $s$ và $t$. Ký hiệu các biến quyết định là $\{f_{ij}\}$, trong đó $f_{ij}$ là lưu lượng trên cạnh $(i,j)\in E$. Khi đó, luồng chi phí nhỏ nhất có thể viết thành bài toán quy hoạch tuyến tính sau:
    
    $$
    \begin{aligned}
    v(m)=\min_{\{f_{ij}\}}\;&\sum_{(i,j)\in E}w_{ij}f_{ij}\\
    \text{với ràng buộc }&\sum_{(j,i)\in E}f_{ji} - \sum_{(i,j)\in E}f_{ij} =
    \begin{cases}
    -m, & i=s,\\
    m,  & i=t,\\
    0,  & \text{ngược lại},
    \end{cases}
    ~\forall i\in V,\\
    &0\le f_{ij}\le c_{ij},~\forall (i,j)\in E.
    \end{aligned}
    $$
    
    Vì vậy, chi phí nhỏ nhất $v(m)$ là hàm lồi theo tham số $m$.

Trong lập trình thi đấu, nhiều bài toán có thể quy về các bài toán đồ thị như luồng mạng, từ đó có thể thiết lập tính lồi của hàm giá trị bằng cách tương tự.

Dùng phương pháp này, ta có chứng minh tính lồi đầu tiên cho bài toán trồng cây:

??? example "Chứng minh tính lồi 1"
    Lợi ích lớn nhất của bài toán trồng cây thực ra có thể được suy ra từ mô hình luồng cực đại chi phí lớn nhất sau:
    
    -   Từ nguồn $s$ nối một cạnh đến nút $r$ với dung lượng $m$ và chi phí $0$;
    -   từ nút $r$ nối đến mỗi nút lẻ $i=1,3,\cdots,2\lceil n/2\rceil-1$ một cạnh có dung lượng $1$ và chi phí $0$;
    -   từ mỗi nút chẵn $i=0,2,\cdots,2\lfloor n/2\rfloor$ nối đến đích $t$ một cạnh có dung lượng $1$ và chi phí $0$;
    -   với mỗi $i=1,\cdots,n$, từ nút lẻ trong hai nút $i-1$ và $i$ nối đến nút chẵn một cạnh có dung lượng $1$ và chi phí $a_i$.
    
    Đáp án cuối cùng là chi phí lớn nhất tìm được. Chuyển mô hình đồ thị này thành bài toán quy hoạch tuyến tính tương ứng (cụ thể xem chứng minh của hệ quả ở trên), khi đó tổng lưu lượng $m$ sẽ xuất hiện trong bất đẳng thức biểu thị giới hạn lưu lượng của cạnh $(s,r)$. Theo hệ quả, chi phí lớn nhất $v(m)$ là hàm lõm theo lưu lượng $m$.
    
    Dùng mô hình luồng chi phí này, có thể giải bài toán trong độ phức tạp $O(n\log n)$ bằng cách mô phỏng luồng chi phí hoặc [tham lam hối tiếc](../../basic/greedy.md#lời-giải-hối-tiếc).

<span id="dùng-phương-trình-chuyển-trạng-thái"></span>
### Dùng phương trình chuyển trạng thái

Dù phương trình chuyển trạng thái không cung cấp cách tính hiệu quả, nó thường có thể dùng để chứng minh hàm trạng thái $f(i,j)$ có tính lồi theo tham số $j$. Cụ thể, xem hàm $f(i,\cdot)$ là trạng thái tại $i$, ta có thể xem phương trình chuyển trạng thái của $f(i,j)$ là quan hệ truy hồi của $f(i,\cdot)$, từ đó chứng minh quy nạp rằng mỗi $f(i,\cdot)$ đều là hàm lồi. Kiểu chứng minh tính lồi này thường gặp hơn trong bối cảnh [tối ưu DP bằng Slope Trick](./slope-trick.md); trang đó cũng thảo luận các phép biến đổi thường gặp giúp bảo toàn tính lồi.

Phương pháp này cũng có thể dùng để chứng minh tính lồi của bài toán trồng cây:

??? example "Chứng minh tính lồi 2"
    Gọi $f(i,j)$ là lợi ích lớn nhất khi trồng $j$ cây trong $i$ hố đầu tiên. Xét phương trình chuyển trạng thái sau:
    
    $$
    f(i,j) = \max\{f(i-1,j),f(i-2,j-1)+a_i\}.
    $$
    
    Xem phương trình chuyển trạng thái này là quan hệ truy hồi của hàm $f(i,\cdot)$. Vì trong ký hiệu cực trị có hai hàm khác nhau, nó không thể biểu diễn thành dạng chập lấy cận trên đúng. Tuy nhiên, vẫn có thể chứng minh bằng quy nạp rằng hàm $f(i,\cdot)$ là hàm lõm.
    
    Thực ra, cần chứng minh quy nạp hai điểm sau:
    
    -   $f(i,j)-f(i-2,j-1)$ giảm theo $j$;
    -   $f(i,j)-f(i-1,j)$ tăng theo $j$.
    
    Cơ sở quy nạp là hiển nhiên. Giả sử chúng đúng với mọi số tự nhiên từ $i-1$ trở về trước, ta chứng minh chúng cũng đúng với $i$. Chỉ cần kiểm tra trực tiếp.
    
    Trước hết, theo giả thiết quy nạp,
    
    $$
    f(i-1,j) - f(i-2,j-1) = (f(i,j)-f(i-2,j-1)) - (f(i,j)-f(i-1,j))
    $$
    
    giảm theo $j$. Vì vậy,
    
    $$
    f(i,j) - f(i-2,j-1) = \max\{f(i-1,j) - f(i-2,j-1), a_i\}
    $$
    
    giảm theo $j$, và
    
    $$
    f(i,j) - f(i-1,j) = \max\{0,a_i-(f(i,j) - f(i-2,j-1))\}
    $$
    
    tăng theo $j$. Như vậy hoàn tất quy nạp.
    
    Hơn nữa,
    
    $$
    f(i,j) - f(i,j-1) = (f(i,j)-f(i-2,j-1)) - (f(i,j-1) - f(i-1,j-1)) - (f(i-1,j-1) - f(i-2,j-1))
    $$
    
    giảm theo $j$. Điều này cho thấy $f(i,j)$ là hàm lõm theo $j$, do đó hàm giá trị $v(m)=f(n,m)$ là hàm lõm theo $m$.
    
    Một sản phẩm phụ của chứng minh này là với mọi $i$, đều tồn tại $p_i$ sao cho
    
    $$
    f(i,j) =
    \begin{cases}
    f(i-1,j), & j\le p_i,\\
    f(i-2,j-1) + a_i, & j> p_i.
    \end{cases}
    $$
    
    Điều này cho thấy có thể dùng cây cân bằng để trực tiếp duy trì dãy $f(i,\cdot)$, với độ phức tạp $O(n\log^2n)$. Ưu điểm là có thể xử lý trường hợp tổng quát với khoảng cách trồng cây bất kỳ, đồng thời thu được tất cả giá trị $v(m)$ trong một lần.

<span id="bất-đẳng-thức-tứ-giác"></span>
### Bất đẳng thức tứ giác

Trong lập trình thi đấu, một lớp bài toán thường gặp khác có tính lồi là [bài toán phân đoạn khoảng](./quadrangle.md#bài-toán-phân-tách-khoảng). Trang đó chứng minh rằng nếu hàm chi phí của một khoảng đơn lẻ thỏa bất đẳng thức tứ giác, thì chi phí nhỏ nhất của bài toán phân đoạn khoảng với số đoạn bị ràng buộc là hàm lồi theo số đoạn. Trang đó cũng cung cấp một số cách phán đoán liệu một hàm $w(l,r)$ có thỏa bất đẳng thức tứ giác hay không. Cách trực tiếp nhất là tính sai phân hỗn hợp bậc hai của nó:

$$
\begin{aligned}
\Delta_l \Delta_r w(l,r) &= \Delta_l(w(l,r+1)-w(l,r)) \\
&= w(l+1,r+1)-w(l+1,r)-w(l,r+1)+w(l,r).
\end{aligned}
$$

Hàm $w(l,r)$ thỏa bất đẳng thức tứ giác khi và chỉ khi $\Delta_l \Delta_r w(l,r)$ không dương. Trực quan mà nói, hàm thỏa bất đẳng thức tứ giác thường có nghĩa là việc mở rộng khoảng sang hai phía, tức dịch đầu trái sang trái và đầu phải sang phải, có một loại hiệu ứng cộng hưởng nào đó.

Bài toán trồng cây cũng có thể xem là một bài toán phân đoạn khoảng và có thể được chứng minh bằng cách kiểm chứng bất đẳng thức tứ giác.

??? example "Chứng minh tính lồi 3"
    Thêm một $a_0$ vào đầu dãy lợi ích trồng cây; giá trị này có thể tùy ý. Khi đó, bài toán trồng cây tương đương với việc chia dãy $\{a_0,a_1,\cdots,a_n\}$ thành $m$ đoạn, trong đó hàm lợi ích của mỗi đoạn là
    
    $$
    w(l,r) = \max_{i\in[l+1,r]} a_i
    $$
    
    của bài toán phân đoạn khoảng. Nói cách khác, lợi ích của mỗi đoạn là giá trị lớn nhất trong các cây còn lại sau khi bỏ cây đầu tiên, điều này bảo đảm việc trồng cách nhau.
    
    Vì đây là bài toán cực đại hóa, cần kiểm chứng "giao lớn hơn chứa", tức với mọi $a<b<c<d$ đều có
    
    $$
    w(a,c)+w(b,d) \ge w(a,d)+w(b,c).
    $$
    
    Thay biểu thức của hàm lợi ích vào, đặt
    
    $$
    A = \max_{i\in[a+1,b]} a_i,~ B = \max_{i\in[b+1,c]} a_i,~ C = \max_{i\in[c+1,d]}a_i,
    $$
    
    thì bất đẳng thức cần chứng minh có thể viết thành
    
    $$
    \max\{A,B\} + \max\{B,C\} \ge \max\{A,B,C\} + B.
    $$
    
    Chú ý rằng trong hai hạng tử $\max\{A,B\}$ và $\max\{B,C\}$ ở vế trái, hạng tử lớn hơn đúng bằng $\max\{A,B,C\}$, còn hạng tử nhỏ hơn luôn không nhỏ hơn $B$, nên bất đẳng thức đúng.
    
    Sau khi chuyển bài toán trồng cây thành bài toán phân đoạn khoảng, chỉ cần dùng bảng ST hoặc cách tương tự để tiền xử lý giá trị cực trị trên khoảng, có thể tính chi phí của một khoảng đơn lẻ trong $O(1)$ mỗi lần, rồi áp dụng thuật toán cho bài toán phân đoạn khoảng với độ phức tạp thời gian $O(n\log n\log L)$ hoặc $O(n(n+m))$. Phương pháp này cũng có thể xử lý bài toán với khoảng cách trồng cây bất kỳ.

<span id="lập-luận-trao-đổi"></span>
### Lập luận trao đổi

Trong các bài toán tối ưu tổ hợp, chứng minh tính lồi của hàm giá trị thường dùng lập luận trao đổi (exchange argument). Cụ thể, xuất phát từ các nghiệm tối ưu của bài toán với tham số $m-1$ và $m+1$, thông qua trao đổi một phần phần tử, ta xây dựng nghiệm khả thi có tham số $m$ và giá trị không vượt quá $(v(m-1)+v(m+1))/2$, từ đó dùng tính tối ưu của $v(m)$ để chứng minh tính lồi. So với trường hợp tối ưu lồi, trong bài toán tối ưu tổ hợp không tồn tại cách tự nhiên để xây dựng "dạng trung gian" của hai nghiệm, nên việc áp dụng lập luận trao đổi thường cần một số kỹ thuật.

???+ warning ""Chi phí biên tăng dần" không nhất thiết dẫn đến tính lồi"
    Trong bài toán tối ưu tổ hợp, hàm mục tiêu thường có một số tính chất "chi phí biên tăng dần", nhưng điều này không tất yếu dẫn đến tính lồi. Một ví dụ điển hình là [\[IOI 2005\] Riv](https://www.luogu.com.cn/problem/P3354); phiên bản trên đường thẳng của bài toán này thỏa bất đẳng thức tứ giác nên có tính lồi, nhưng phiên bản trên cây có ví dụ mà tính lồi không đúng.
    
    Một tính chất thường dùng để mô tả "chi phí biên tăng dần" là siêu mô-đun (supermodularity) của hàm. Với hàm $f:\mathcal PX\rightarrow\mathbf R$ trên họ tập con $\mathcal PX$ của một tập hữu hạn $X$, nếu nó thỏa một trong hai tính chất tương đương sau:
    
    1.  (Giao nhỏ hơn chứa) Với mọi tập con $A,B\subseteq X$, đều có $f(A)+f(B) \le f(A\cup B) + f(A\cap B)$;
    2.  (Chi phí biên tăng dần) Với mọi tập con $A\subseteq B\subseteq X$ và $x\in X\setminus B$, đều có $f(A\cup\{x\})-f(A)\le f(B\cup\{x\})-f(B)$;
    
    thì gọi $f$ là **siêu mô-đun** (supermodular). Tuy nhiên, trong bài toán tối ưu dùng hàm siêu mô-đun làm hàm mục tiêu, hàm giá trị
    
    $$
    v(m) = \min_{A\subseteq X} f(A) \text{ với ràng buộc }|A|=m
    $$
    
    **chưa chắc** là hàm lồi theo $m$. Nguyên nhân là từ các nghiệm tối ưu có kích thước tập con lần lượt là $m-1$ và $m+1$, nhìn chung không thể xây dựng được nghiệm khả thi có kích thước tập con $m$ và thỏa quan hệ giá trị nêu trên.

Lập luận trao đổi cung cấp một cách chứng minh khác cho tính lồi của bài toán trồng cây.

??? example "Chứng minh tính lồi 4"
    Dùng lập luận trao đổi. Gọi các phương án tối ưu khi trồng $m-1$ cây và $m+1$ cây lần lượt là $\{x_i^{(m-1)}\}\in\{0,1\}^n$ và $\{x_i^{(m+1)}\}\in\{0,1\}^n$, trong đó giá trị $1$ nghĩa là hố đó được trồng cây, còn $0$ nghĩa là không trồng. Định nghĩa dãy $\{z_i\}\in\{0,\pm 1\}^n$ thỏa
    
    $$
    z_i = x_i^{(m+1)} - x_i^{(m-1)},~i=1,\cdots,n.
    $$
    
    Dãy này đánh dấu sự khác biệt giữa hai phương án trồng cây. Vị trí có giá trị $0$ trong dãy nghĩa là hố đó hoặc được trồng trong cả hai phương án, hoặc không được trồng trong cả hai phương án; còn các vị trí có giá trị $-1$ và $+1$ lần lượt nghĩa là chỉ trong phương án $x^{(m-1)}$ hoặc chỉ trong phương án $x^{(m+1)}$, hố đó được trồng cây. Vì trong bất kỳ phương án nào cũng không được trồng cây ở hai hố kề nhau, ta có các quan sát sau:
    
    -   Trong một đoạn con liên tiếp khác không, các giá trị $z_i$ nhất định luân phiên giữa $\pm 1$;
    -   các số $0$ ở hai bên của một đoạn con liên tiếp khác không cực đại nhất định biểu thị các hố không được trồng cây trong cả hai phương án.
    
    Do đó, nếu trong một đoạn con liên tiếp khác không cực đại nào đó, tổng của $z_i$ đúng bằng $+1$, tức trong đoạn hố này phương án $x^{(m+1)}$ trồng nhiều hơn phương án $x^{(m-1)}$ một cây, thì có thể trao đổi vị trí trồng cây của hai phương án trong đoạn đó. Như vậy thu được hai phương án khả thi, mỗi phương án trồng $m$ cây. Vì không thay đổi tổng vị trí và tổng số lượng cây trồng trong hai phương án, mà chỉ phân phối lại chúng, tổng lợi ích không đổi và vẫn là $v(m-1)+v(m+1)$. Nhưng hai phương án trồng $m$ cây này chưa chắc tối ưu, nên lợi ích của từng phương án không vượt quá $v(m)$. Điều này chứng minh
    
    $$
    v(m-1) + v(m+1) \le 2v(m),
    $$
    
    tức là $v(m)$ là hàm lõm theo $m$.
    
    Bây giờ chỉ còn một vấn đề: có tồn tại đoạn con liên tiếp khác không cực đại có tổng đúng bằng $+1$ hay không. Vì đây là tổng của một số giá trị $\pm 1$ luân phiên, tổng của một đoạn con liên tiếp khác không chỉ có thể là $0$ hoặc $\pm 1$. Lại vì tổng của tất cả các đoạn con liên tiếp khác không cực đại này bằng $2$, nhất định tồn tại ít nhất hai đoạn con cực đại có tổng đúng bằng $+1$. Như vậy hoàn tất chứng minh.

<span id="ví-dụ"></span>
## Ví dụ

Mục này giới thiệu một số ví dụ áp dụng phương pháp tìm kiếm nhị phân WQS trong các bối cảnh khác nhau.

<span id="bài-mẫu"></span>
### Bài mẫu

???+ example "[Luogu P1484 Trồng cây](https://www.luogu.com.cn/problem/P1484)"
    Có $n$ hố cây, được trồng **nhiều nhất** $m$ cây. Không được trồng cây ở hai hố kề nhau. Cho dãy độ dài $n$ là $\{a_i\}$, biểu thị lợi ích khi trồng cây ở mỗi hố, lợi ích có thể dương hoặc âm. Hãy tìm tổng lợi ích lớn nhất có thể sau khi trồng xong các cây này.

??? note "Lời giải"
    Hơi khác với bài toán trồng cây đã thảo luận ở trên, bài này yêu cầu trồng nhiều nhất $m$ cây, chứ không phải đúng $m$ cây. Vẫn dùng $v(m)$ để biểu thị hàm giá trị của bài toán trồng cây đã thảo luận, đáp án bài này thực ra là $\tilde v(m)=\max_{k\le m}v(k)$. Vì $v(m)$ là hàm lõm, tức là một hàm đơn đỉnh, đáp án bài này tương đương với việc chỉ giữ phần $v(m)$ tăng lên tới đỉnh, rồi hàm sẽ giữ nguyên ở đỉnh; điều này tương đương với việc chỉ giữ phần có hệ số góc tiếp tuyến không âm. Vì vậy, khác biệt duy nhất giữa bài này và bài đã thảo luận ở trước là khi tìm kiếm nhị phân WQS, phạm vi hệ số góc ban đầu là $[0,\max_ia_i]$ chứ không phải $[\min_ia_i,\max_ia_i]$.
    
    Sau khi dùng tìm kiếm nhị phân WQS để loại bỏ ràng buộc số lượng, bài toán chuyển thành tính tập độc lập trọng số lớn nhất trên một đường thẳng, chỉ khác là dãy lợi ích ban đầu $\{a_i\}$ được thay bằng $\{a_i+k\}$. Đây là bài toán quy hoạch động kinh điển. Có thể đặt $f(i,j)$ là lợi ích lớn nhất của bài toán con trên $i$ hố đầu tiên khi hố thứ $i$ được chọn trồng cây ($j=1$) hoặc không trồng cây ($j=0$). Từ đó viết được phương trình chuyển trạng thái:
    
    $$
    \begin{aligned}
    f(i,0) &= \max\{f(i-1,0),f(i-1,1)\},\\
    f(i,1) &= f(i-1,0) + a_i + k.
    \end{aligned}
    $$
    
    Điều kiện ban đầu là $f(0,0)=0$ và $f(0,1)=-\infty$, đáp án cuối cùng là $\max\{f(n,0),f(n,1)\}$. Độ phức tạp của một lần tính là $O(n)$, độ phức tạp tổng thể là $O(n\log L)$, trong đó $L=\max_i|a_i|$.
    
    Cài đặt tham khảo như sau:
    
    === "Phương pháp truyền thống"
        ```cpp
        --8<-- "docs/dp/code/opt/wqs-binary-search/plant-tree-1.cpp"
        ```
    
    === "Phương pháp đối ngẫu"
        ```cpp
        --8<-- "docs/dp/code/opt/wqs-binary-search/plant-tree-2.cpp"
        ```

???+ example "[Luogu P2619 Đội tuyển quốc gia Tree I](https://www.luogu.com.cn/problem/P2619)"
    Cho một đồ thị vô hướng liên thông có trọng số, mỗi cạnh màu đen hoặc trắng. Hãy tìm cây khung có đúng $m$ cạnh trắng và tổng trọng số nhỏ nhất.

??? note "Lời giải"
    Trước hết, có thể dùng lập luận trao đổi để chứng minh $v(m)$ là hàm lồi. Không mất tính tổng quát, giả sử trọng số của mọi cạnh đều khác nhau: những trường hợp có hai cạnh cùng trọng số có thể được biến thành trường hợp trọng số khác nhau bằng nhiễu nhỏ; sau đó chỉ cần cho biên độ nhiễu tiến tới $0$ là có thể chứng minh tính lồi của hàm vẫn đúng trong trường hợp giới hạn, tức trường hợp tồn tại hai cạnh cùng trọng số. Mấu chốt của chứng minh nằm ở bổ đề sau:[^edge-swap]
    
    ???+ note "Bổ đề"
        Gọi $S$ và $T$ là hai cây khung của đồ thị vô hướng liên thông $G=(V,E)$. Với mọi $e\in S\setminus T$, đều tồn tại ít nhất một cạnh $f\in T\setminus S$ sao cho $S-e+f$ và $T-f+e$ đều là cây khung của đồ thị $G$.
    
    ??? note "Chứng minh"
        Đặt $e=(u,v)$, và $P$ là đường đi duy nhất nối $u$ và $v$ trong cây $T$. Vì $P+e$ là chu trình duy nhất trong đồ thị $T+e$, xóa bất kỳ cạnh $f$ nào trong $P$ đều làm cho $T-f+e$ là một cây khung. Đồng thời, đồ thị $S-e$ là một rừng có hai thành phần liên thông, gọi tập đỉnh của chúng lần lượt là $V_1$ và $V_2$. Vì vậy, chỉ cần chọn cạnh $f\in P$ sao cho $f$ nối $V_1$ và $V_2$, sẽ bảo đảm $S-e+f$ là một cây khung. Cạnh $f$ như vậy luôn tồn tại, vì $u$ và $v$ lần lượt thuộc $V_1$ và $V_2$, còn $P$ nối $u$ với $v$. Hơn nữa, $f\notin S$, vì trong đồ thị $S-e$, $V_1$ và $V_2$ không liên thông. Như vậy chứng minh xong.
    
    Gọi $T_{m-1}$ và $T_{m+1}$ là các cây khung nhỏ nhất có số cạnh trắng lần lượt là $m-1$ và $m+1$. Gọi $e$ là một cạnh trắng thuộc $T_{m+1}\setminus T_{m-1}$. Áp dụng bổ đề trên cho $e$, tồn tại cạnh $f\in T_{m-1}\setminus T_{m+1}$ sao cho $T'=T_{m+1}-e+f$ và $T''=T_{m-1}+e-f$ đều là cây khung. Vì chỉ trao đổi một cặp cạnh, tổng trọng số của cây $T'$ và cây $T''$ vẫn là $v(m-1)+v(m+1)$. Tiếp theo xét hai trường hợp:
    
    -   Nếu $f$ là cạnh đen, thì số cạnh trắng trong cả $T'$ và $T''$ đều là $m$. Tổng trọng số của mỗi cây đều không nhỏ hơn $v(m)$. Điều này chứng minh $2v(m)\le v(m-1)+v(m+1)$, do đó $v(m)$ lồi theo $m$.
    -   Nếu $f$ là cạnh trắng, thì số cạnh trắng trong $T'$ và $T''$ lần lượt là $m+1$ và $m-1$, nên tổng trọng số của chúng lần lượt không nhỏ hơn $v(m+1)$ và $v(m-1)$. Nhưng ở trên đã chỉ ra tổng trọng số của chúng cộng lại bằng $v(m-1)+v(m+1)$. Điều này cho thấy tổng trọng số của $T'$ đúng bằng $v(m+1)$. So sánh $T'$ với $T_{m+1}$, ta biết trọng số của $e$ và $f$ nhất định bằng nhau. Điều này mâu thuẫn với giả thiết, nên trường hợp này không xảy ra.
    
    Như vậy đã chứng minh $v(m)$ là hàm lồi theo $m$.
    
    Sau khi thiết lập tính lồi của hàm $v(m)$, có thể dùng tìm kiếm nhị phân WQS để giải bài toán. Loại bỏ ràng buộc số lượng bằng cách trừ $k$ khỏi trọng số của mỗi cạnh trắng, rồi giải bài toán cây khung nhỏ nhất. Có thể dùng [thuật toán Kruskal](../../graph/mst.md#thuật-toán-kruskal). Dùng DSU để duy trì tính liên thông, độ phức tạp thuật toán là $O(E\log E+E\alpha(V))$, trong đó $E$ và $V$ lần lượt là số cạnh và số đỉnh, còn $\alpha(\cdot)$ là hàm ngược Ackermann. Phần chính của độ phức tạp, $O(E\log E)$, là độ phức tạp sắp xếp cạnh; trong bài này có thể tối ưu thêm. Dù trong quá trình nhị phân WQS cần tính cây khung nhỏ nhất nhiều lần, mỗi lần chỉ có trọng số của các cạnh trắng đồng loạt cộng hoặc trừ một số. Vì vậy, có thể tiền xử lý bằng cách sắp xếp riêng cạnh trắng và cạnh đen, rồi mỗi lần tính cây khung nhỏ nhất chỉ cần trộn các cạnh trắng sau khi điều chỉnh trọng số với các cạnh đen. Như vậy độ phức tạp tổng thể giảm xuống $O(E\log E+E\alpha(V)\log L)$, trong đó $L$ là độ dài phạm vi giá trị của trọng số cạnh.
    
    Cài đặt tham khảo như sau:
    
    === "Phương pháp truyền thống"
        ```cpp
        --8<-- "docs/dp/code/opt/wqs-binary-search/black-white-mst-1.cpp"
        ```
    
    === "Phương pháp đối ngẫu"
        ```cpp
        --8<-- "docs/dp/code/opt/wqs-binary-search/black-white-mst-2.cpp"
        ```

<span id="bài-toán-phân-đoạn-khoảng"></span>
### Bài toán phân đoạn khoảng

???+ example "[Luogu P6246 IOI 2000 Bưu điện, bản tăng cường](https://www.luogu.com.cn/problem/P6246)"
    Cho dãy số nguyên dương tăng dần độ dài $n$, $\{a_i\}$, biểu thị vị trí của $n$ ngôi làng bên một đường cao tốc. Cần xây $m$ bưu điện. Việc chọn vị trí bưu điện cần tối thiểu hóa tổng khoảng cách từ mỗi làng đến bưu điện gần nó nhất. Hãy tìm giá trị nhỏ nhất này.

??? note "Lời giải"
    Đây là một [bài toán phân đoạn khoảng](./quadrangle.md#bài-toán-phân-tách-khoảng) điển hình. Chi tiết cài đặt hàng đợi nhị phân có thể tham khảo trang đó.
    
    Mỗi bưu điện phục vụ các làng gần nó nhất, nên những làng này nhất định là một số làng liên tiếp bên đường cao tốc. Vì vậy, xây $m$ bưu điện tương đương với chia tất cả các làng thành $m$ đoạn liên tiếp, rồi xây một bưu điện có chi phí thấp nhất cho mỗi đoạn làng. Như đã biết, bưu điện nên được xây tại vị trí trung vị của các làng. Từ đó có thể viết hàm chi phí của khoảng $[l,r]$ là
    
    $$
    w(l,r) = \sum_{i=l}^r|a_i-a_{\lfloor(l+r)/2\rfloor}|.
    $$
    
    Nó thỏa bất đẳng thức tứ giác, vì sai phân hỗn hợp bậc hai của nó không dương:
    
    $$
    \Delta_l\Delta_r w(l,r)
    = \Delta_l(a_{r+1} - a_{\lfloor(l+r+1)/2\rfloor})
    = a_{\lfloor(l+r+1)/2\rfloor}-a_{\lfloor(l+r+2)/2\rfloor} \le 0.
    $$
    
    Điều này cho thấy có thể dùng hàng đợi nhị phân kết hợp với tìm kiếm nhị phân WQS để giải bài toán trong độ phức tạp $O(n\log n\log L)$.
    
    Cài đặt tham khảo như sau:
    
    === "Phương pháp truyền thống"
        ```cpp
        --8<-- "docs/dp/code/opt/wqs-binary-search/post-office-1.cpp"
        ```
    
    === "Phương pháp đối ngẫu"
        ```cpp
        --8<-- "docs/dp/code/opt/wqs-binary-search/post-office-2.cpp"
        ```

<span id="điều-kiện-ràng-buộc-hai-chiều"></span>
### Điều kiện ràng buộc hai chiều

???+ example "[Codeforces 739 E. Gosha is hunting](https://codeforces.com/problemset/problem/739/E)"
    Có $n$ Pokemon, hai dãy $\{p_i\}$ và $\{q_i\}$ lần lượt biểu thị xác suất bắt được Pokemon thứ $i$ bằng Poke Ball và Great Ball. Có thể ném vào một Pokemon một Poke Ball, hoặc một Great Ball, hoặc mỗi loại một quả, hoặc không ném quả nào. Hiện có $m_1$ Poke Ball và $m_2$ Great Ball, cần phân phối hợp lý và ném đồng thời. Việc bắt thành công hay không trong mỗi lần độc lập với kết quả của các lần bắt khác. Hãy tìm giá trị kỳ vọng lớn nhất của số Pokemon bắt được.
    
    Tổng quát hơn, có thể trừu tượng hóa thành bài toán sau:
    
    Cho ba dãy số thực dương độ dài $n$ là $\{A_i\},\{B_i\},\{C_i\}$, và với mọi $i=1,\cdots,n$ đều có $C_i\le A_i+B_i$. Hãy tìm các tập chỉ số tối ưu $X$ và $Y$ thỏa $|X|=m_1$ và $|Y|=m_2$, đồng thời cực đại hóa
    
    $$
    \sum_{i\in X\setminus Y}A_i + \sum_{i\in Y\setminus X}B_i + \sum_{i\in X\cap Y}C_i.
    $$

??? note "Lời giải"
    Bài toán gốc có thể xem là trường hợp đặc biệt của bài toán tổng quát hơn này khi
    
    $$
    A_i = p_i,~ B_i = q_i,~ C_i = p_i+q_i-p_iq_i
    $$
    
    Vì vậy, chỉ cần thảo luận lời giải cho bài toán tổng quát hơn.
    
    Dùng $v(m_1,m_2)$ để biểu thị hàm giá trị của bài toán này; cần chứng minh nó là hàm lõm theo $(m_1,m_2)$. Xét mô hình luồng chi phí sau:
    
    -   Từ nguồn $s$ nối lần lượt đến các nút $x$ và $y$ một cạnh, dung lượng lần lượt là $m_1$ và $m_2$, chi phí đều là $0$;
    -   với mọi $i=1,\cdots,n$, từ các nút $x$ và $y$ lần lượt nối đến nút $i$ một cạnh, dung lượng đều là $1$, chi phí lần lượt là $A_i$ và $B_i$;
    -   với mọi $i=1,\cdots,n$, từ nút $i$ nối đến đích $t$ hai cạnh, dung lượng đều là $1$, chi phí lần lượt là $0$ và $C_i-A_i-B_i$.
    
    Đáp án của bài toán là luồng cực đại chi phí lớn nhất của mô hình luồng chi phí này. Điều kiện $C_i-A_i-B_i\le 0$ bảo đảm rằng khi lưu lượng đi qua nút $i$ bằng $1$, nó sẽ ưu tiên chọn cạnh ra có chi phí $0$. Viết mô hình luồng chi phí này thành bài toán quy hoạch tuyến tính, $m_1$ và $m_2$ sẽ lần lượt xuất hiện trong các bất đẳng thức biểu thị giới hạn lưu lượng của cạnh $(s,x)$ và cạnh $(s,y)$. Do đó, $v(m_1,m_2)$ quả thật là hàm lõm theo $(m_1,m_2)$.
    
    Để áp dụng tìm kiếm nhị phân WQS, cần xét bài toán tối ưu sau khi bỏ ràng buộc số lượng. Gọi $k_1$ và $k_2$ lần lượt là phần thưởng phụ thêm khi đưa một chỉ số vào tập $X$ và $Y$. Sau khi không còn ràng buộc số lượng, quyết định đối với mỗi chỉ số là độc lập, do đó
    
    $$
    h(k_1,k_2) = \sum_{i=1}^n\max\{0,A_i+k_1,B_i+k_2,C_i+k_1+k_2\}.
    $$
    
    Đáp án của bài toán gốc được cho bởi
    
    $$
    v(m_1,m_2) = \min_{k_1,k_2} h(k_1,k_2) - k_1m_1 - k_2m_2
    $$
    
    Tổng độ phức tạp thời gian là $O(n\log^2L)$, trong đó $O(\log L)$ là số lần nhị phân trên một chiều.
    
    Cài đặt tham khảo cho bài toán bắt Pokemon như sau:
    
    ```cpp
    --8<-- "docs/dp/code/opt/wqs-binary-search/gosha-is-hunting.cpp"
    ```

<span id="điều-kiện-ràng-buộc-tổng-quát-hơn"></span>
### Điều kiện ràng buộc tổng quát hơn

???+ example "[Codeforces 1661 F. Teleporters](https://codeforces.com/problemset/problem/1661/F)"
    Có $n$ đoạn thẳng, độ dài của chúng được cho bởi dãy $\{a_i\}$. Có thể cắt chúng tùy ý thành một số đoạn có độ dài nguyên; mục tiêu là tối thiểu hóa tổng bình phương độ dài của mọi đoạn. Hỏi cần cắt ít nhất bao nhiêu lần để tổng bình phương này giảm xuống không vượt quá $V$.

??? note "Lời giải"
    Gọi $f(a,m)$ là tổng bình phương nhỏ nhất có thể đạt được khi cắt đoạn thẳng độ dài $a$ đúng $m$ lần. Theo bất đẳng thức trung bình, khi tổng của hai số cố định, hai số càng gần nhau thì tổng bình phương của chúng càng nhỏ. Vì vậy, sau khi cắt, độ dài các đoạn càng đều nhau thì tổng bình phương độ dài càng nhỏ. Nhưng do tồn tại ràng buộc nguyên, trường hợp đều nhất là thu được $a\bmod (m+1)$ đoạn có độ dài $\lceil a/(m+1)\rceil$ và $m+1-(a\bmod (m+1))$ đoạn có độ dài $\lfloor a/(m+1)\rfloor$. Do đó có biểu thức sau:
    
    $$
    \begin{aligned}
    f(a,m) &= (a\bmod (m+1))\left\lceil\dfrac{a}{m+1}\right\rceil^2 + (m+1-(a\bmod (m+1)))\left\lfloor\dfrac{a}{m+1}\right\rfloor^2 \\
    &= (a\bmod (m+1))\left(\left\lfloor\dfrac{a}{m+1}\right\rfloor+1\right)^2 + (m+1-(a\bmod (m+1)))\left\lfloor\dfrac{a}{m+1}\right\rfloor^2.
    \end{aligned}
    $$
    
    Dấu bằng ở bước thứ hai đúng vì $\lceil a/(m+1)\rceil \neq \lfloor a/(m+1)\rfloor + 1$ khi và chỉ khi $a\bmod (m+1) = 0$.
    
    Có thể chứng minh hàm $f(a,m)$ là hàm lồi theo $m$. Để làm điều này, cần mở rộng nó sang trường hợp $m\in\mathbf R_{+}$. Khi $\lfloor a/(m+1)\rfloor = q$, ta có
    
    $$
    \begin{aligned}
    f(a,m) &= (a-(m+1)q)(q+1)^2 + ((m+1)(q+1)-a)q^2 \\
    &= a(2q+1) - q(q+1)(m+1).
    \end{aligned}
    $$
    
    Đây là đường thẳng có hệ số góc $-q(q+1)$. Vì vậy, $f(a,m)$ là hàm tuyến tính từng đoạn, và hệ số góc tăng khi $m$ tăng. Điều này cho thấy $f(a,m)$ là hàm lồi, nên giới hạn của nó trên các điểm nguyên đương nhiên cũng là hàm lồi[^conv-int].
    
    Dùng $f(\cdot,\cdot)$, có thể viết tổng bình phương nhỏ nhất thu được khi cắt tất cả đoạn thẳng tổng cộng $m$ lần thành hàm giá trị của bài toán tối ưu sau:
    
    $$
    v(m) = \min_{\{m_i\}}\sum_i f(a_i,m_i)\text{ với ràng buộc }\sum_i m_i=m,~m_i\in\mathbf N.
    $$
    
    Đây là [chập lấy cận dưới đúng](./slope-trick.md#tích-chập-dưới-đúng-tổng-minkowski) của một số hàm lồi, nên cũng là hàm lồi. Nếu đề bài yêu cầu $v(m)$, có thể dùng phương pháp nhất quán với các ví dụ trước để giải, với độ phức tạp thời gian $O(n\log^2L)$. Tuy nhiên, bài này yêu cầu $m$ nhỏ nhất thỏa $v(m)\le V$. Cách dùng tìm kiếm nhị phân WQS để tính $v(m)$ rồi lại nhị phân trên $m$ không khả thi, vì độ phức tạp lên tới $O(n\log^3L)$. Với bài này, có hai cách xử lý sau.
    
    **Cách một**: Vẫn nhị phân hệ số góc $k$, nhưng căn cứ nhị phân là ước lượng cận trên và cận dưới của $v(m)$.
    
    Trong phương pháp tìm kiếm nhị phân WQS truyền thống, với hệ số góc $k$ cho trước, có thể tính ra phạm vi giá trị tối ưu tương ứng của $m$. Vì các điểm $(m,v(m))$ này thẳng hàng, điều này tương đương với việc xác định phạm vi giá trị của $v(m)$. Do đó, có thể nhị phân trực tiếp trên hệ số góc $k$. Sau khi thu được hệ số góc $k$, có thể dùng phương trình đường thẳng
    
    $$
    v(m) = h(k) + km
    $$
    
    để tính $m$ nhỏ nhất. Độ phức tạp tổng thể là $O(n\log^2L)$.
    
    Để xác định phạm vi giá trị của $v(m)$, cần xác định phạm vi của $m$. Một cách làm là khi tính $h(k)$, ghi lại nghiệm tối ưu lớn nhất tương ứng, dùng nó để tính cận dưới tương ứng của $v(m)$. Một cách khác là dùng $h(k)-h(k-1)$ để thu được cận trên tương ứng của $m$, rồi suy ra cận dưới tương ứng của $v(m)$. Trong cài đặt tham khảo, cách thứ hai được sử dụng; nó không phụ thuộc vào cấu trúc cụ thể của bài toán và không cần xử lý đặc biệt.
    
    **Cách hai**: Viết lại bài toán tối ưu sao cho hàm giá trị của bài toán đối ngẫu chính là nghiệm của bài này.
    
    Bài này có thể được xem trực tiếp là bài toán tối ưu sau:
    
    $$
    m(v) = \min_{\{m_i\}} \sum_i m_i \text{ với ràng buộc }\sum_i f(a_i,m_i) \le V.
    $$
    
    Phân tích trong bài viết này vẫn áp dụng cho bài toán này. Vì vậy, có thể dùng bài toán đối ngẫu của nó để giải $m(v)$ cần tìm:
    
    $$
    m(v) = \max_{k} \sum_i\min_{m_i}(m_i - \lambda f(a_i,m_i)) + \lambda V.
    $$
    
    Độ phức tạp tổng thể của thuật toán vẫn là $O(n\log^2L)$.
    
    Mã tham khảo như sau:
    
    === "Cách một"
        Mã chỉ mang tính minh họa; để vượt qua phạm vi dữ liệu gốc, cần dùng số nguyên 128 bit và điều chỉnh khoảng nhị phân ban đầu thành $[0,10^{60}]$.
        
        ```cpp
        --8<-- "docs/dp/code/opt/wqs-binary-search/teleporters-1.cpp"
        ```
    
    === "Cách hai"
        Mã chỉ mang tính minh họa; do vấn đề độ chính xác số thực nên không thể vượt qua phạm vi dữ liệu gốc.
        
        ```cpp
        --8<-- "docs/dp/code/opt/wqs-binary-search/teleporters-2.cpp"
        ```

<span id="bài-tập"></span>
## Bài tập

Cuối cùng, liệt kê một số bài có thể giải bằng tìm kiếm nhị phân WQS để luyện tập:

-   [Luogu P1484 Trồng cây](https://www.luogu.com.cn/problem/P1484)
-   [Luogu P1792 Đội tuyển quốc gia: Trồng cây](https://www.luogu.com.cn/problem/P1792)
-   [Luogu P2619 Đội tuyển quốc gia: Tree I](https://www.luogu.com.cn/problem/P2619)
-   [Luogu P3620 APIO/CTSC2007 Sao lưu dữ liệu](https://www.luogu.com.cn/problem/P3620)
-   [Luogu P4072 SDOI2016 Hành trình](https://www.luogu.com.cn/problem/P4072)
-   [Luogu P4383 Liên khảo tám tỉnh 2018: Cây Link-Cut](https://www.luogu.com.cn/problem/P4383)
-   [Luogu P4983 Quên tình](https://www.luogu.com.cn/problem/P4983)
-   [Luogu P5308 COCI 2018/2019 #4 Akvizna](https://www.luogu.com.cn/problem/P5308)
-   [Luogu P5633 Cây khung có ràng buộc bậc nhỏ nhất](https://www.luogu.com.cn/problem/P5633)
-   [Luogu P5896 IOI 2016 aliens](https://www.luogu.com.cn/problem/P5896)
-   [Luogu P6246 IOI 2000 Bưu điện, bản tăng cường](https://www.luogu.com.cn/problem/P6246)
-   [AtCoder Beginner Contest 218 H - Red and Blue Lamps](https://atcoder.jp/contests/abc218/tasks/abc218_h)
-   [AtCoder Beginner Contest 305 Ex - Shojin](https://atcoder.jp/contests/abc305/tasks/abc305_h)
-   [AtCoder Regular Contest 164 E - Segment-Tree Optimization](https://atcoder.jp/contests/arc164/tasks/arc164_e)
-   [Codeforces 125 E. MST Company](https://codeforces.com/problemset/problem/125/E)
-   [Codeforces 321 E. Ciel and Gondolas](https://codeforces.com/problemset/problem/321/E)
-   [Codeforces 739 E. Gosha is hunting](https://codeforces.com/problemset/problem/739/E)
-   [Codeforces 802 O. April Fools' Problem (hard)](https://codeforces.com/contest/802/problem/O)
-   [Codeforces 958 E2. Guard Duty (medium)](https://codeforces.com/problemset/problem/958/E2)
-   [Codeforces 1279 F. New Year and Handle Change](https://codeforces.com/problemset/problem/1279/F)
-   [Codeforces 1661 F. Teleporters](https://codeforces.com/problemset/problem/1661/F)
-   [Codeforces 1799 F. Halve or Subtract](https://codeforces.com/problemset/problem/1799/F)
-   [2019 Summer Petrozavodsk Camp H. Honorable Mention](https://codeforces.com/gym/102331/problem/H)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [Wang Qinshi, "Phân tích sơ lược một lớp phương pháp nhị phân"](https://github.com/hzwer/shareOI/blob/master/%E5%9F%BA%E7%A1%80%E7%AE%97%E6%B3%95/%E6%B5%85%E6%9E%90%E4%B8%80%E7%B1%BB%E4%BA%8C%E5%88%86%E6%96%B9%E6%B3%95_%E7%8E%8B%E9%92%A6%E7%9F%B3.pdf)
-   [Theoretical grounds of lambda optimization by adamant - Codeforces blog](https://codeforces.com/blog/entry/98334)
-   [Phương pháp WQS nhị phân chặt chẽ by YeahPotato - Luogu Blog](https://www.luogu.com.cn/article/vsffwrc3)
-   [Ghi chú học tập: giải thích chi tiết WQS nhị phân và các hiểu lầm thường gặp by ikrvxt - CSDN Blog](https://blog.csdn.net/Emm_Titan/article/details/124035796)
-   [Convex conjugate - Wikipedia](https://en.wikipedia.org/wiki/Convex_conjugate)
-   [Fenchel-Moreau theorem - Wikipedia](https://en.wikipedia.org/wiki/Fenchel%E2%80%93Moreau_theorem)
-   [Subderivative - Wikipedia](https://en.wikipedia.org/wiki/Subderivative)
-   [Boyd, Stephen P., and Lieven Vandenberghe. Convex optimization. Cambridge university press, 2004.](https://web.stanford.edu/~boyd/cvxbook/bv_cvxbook.pdf)
-   Papadimitriou, Christos H., and Kenneth Steiglitz. Combinatorial optimization: algorithms and complexity. Courier Corporation, 1998.
-   Conforti, Michele, Gerard Cornuejols, and Giacomo Zambelli. Integer programming. Springer International Publishing, 2014.
-   Schrijver, Alexander. Combinatorial optimization: polyhedra and efficiency. Vol. 24, no. 2. Berlin: Springer, 2003.

[^high-d-convex]: Trong bài toán thực tế, $y$ có thể chỉ nhận hữu hạn nhiều điểm lưới trong $\mathbf R^d$. Điều kiện thật sự cần ở đây là nghiệm $v(y)$ của bài toán gốc có thể được mở rộng thành một hàm lồi $\tilde v:\mathbf R^d\rightarrow \mathbf R\cup\{\pm\infty\}$ trên $\mathbf R^d$, tức $v(y)$ là **có thể mở rộng lồi** (convex-extensible). Để tiện trình bày, trong phần chính vẫn dùng $v(y)$ để chỉ hàm sau khi mở rộng. Về trực quan hình học, điều này tương đương với việc toàn bộ tập điểm $\{(y,v(y))\}$ đều nằm trên bao lồi dưới của bao lồi của chúng. Với trường hợp một chiều, điều kiện này [rất dễ mô tả](./slope-trick.md#hàm-lồi-trên-tập-điểm-rời-rạc) bằng ngôn ngữ đại số; nhưng với trường hợp nhiều chiều thì hơi phức tạp hơn, và [bài giảng này](https://kzmurota.fpark.tmu.ac.jp/paper/HIMSummerSchool15Murota.pdf) cung cấp một số điều kiện đủ đơn giản.

[^other-conditions]: Các điều kiện trong định lý trông có vẻ mạnh hơn tính lồi một chút, nhưng với các trường hợp thường gặp trong lập trình thi đấu, đặc biệt khi $X$ là tập hữu hạn, chỉ nhấn mạnh tính lồi đã đủ. Hàm $\tilde v$ được mở rộng từ hàm lồi proper $v$ trên tập rời rạc nhất định là hàm lồi nửa liên tục dưới, vì bao lồi của hữu hạn điểm nhất định là bao lồi đóng, còn cái gọi là hàm lồi nửa liên tục dưới tương đương với việc epigraph của nó là bao lồi đóng. Còn từ "proper" trong hàm lồi proper được bảo đảm miễn là $v(y)$ nhận giá trị hữu hạn tại ít nhất một điểm và là hàm lồi.

[^mst]: Bài toán cây khung nhỏ nhất có hai [cách](https://math.arizona.edu/~glickenstein/math443f14/golari.pdf) thường gặp để viết thành bài toán quy hoạch tuyến tính: mô hình khử chu trình con (subtour-elimination formulation) và mô hình dựa trên tập cắt (cut-based formulation). Chỉ cách mô hình hóa thứ nhất mới bảo đảm bài toán quy hoạch tuyến tính thu được tương đương với bài toán gốc.

[^edge-swap]: Bổ đề này cũng đúng với [matroid](../../math/matroid.md) tổng quát. Nó được gọi là **tính chất trao đổi cơ sở đối xứng** (symmetric base-exchange property); có thể tham khảo [trang Wikipedia](https://en.wikipedia.org/wiki/Basis_of_a_matroid) để biết thêm. Vì vậy, kết luận về tính lồi của bài này có thể mở rộng sang matroid tổng quát.

[^conv-int]: Tất nhiên, $f(a,m)$ và bao lồi của hàm thu được khi giới hạn nó trên các điểm nguyên không giống nhau, vì $f(a,m)$ có thể có điểm cực trị tại vị trí không nguyên. Điều này cho thấy không thể trực tiếp dùng $f(a,m)$ có miền xác định là số thực trong bài toán tối ưu của đề này.
