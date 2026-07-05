author: orzAtalod

Nội dung phần này được đăng lại và chỉnh sửa từ [Thời gian phức tạp - bàn sơ về phân tích thế năng](https://www.luogu.com.cn/blog/Atalod/shi-jian-fu-za-du-shi-neng-fen-xi-qian-tan), đã được tác giả gốc cho phép.

<span id="định-nghĩa"></span>
## Định nghĩa

<span id="hàm-ackermann"></span>
### Hàm Ackermann

Trước hết, ta đưa ra định nghĩa của $\alpha(n)$. Để định nghĩa nó, trước tiên cần định nghĩa $A_k(j)$.

Định nghĩa $A_k(j)$ như sau:

$$
A_k(j)=\left\{
\begin{aligned}
&j+1& &k=0&\\
&A_{k-1}^{(j+1)}(j)& &k\geq1&
\end{aligned}
\right.
$$

Đây chính là hàm Ackermann.

Ở đây, $f^i(x)$ biểu thị việc áp dụng liên tiếp $f$ lên $x$ tổng cộng $i$ lần, tức là $f^0(x)=x$, $f^i(x)=f(f^{i-1}(x))$.

Tiếp theo, định nghĩa $\alpha(n)$ là giá trị nguyên nhỏ nhất sao cho $A_{\alpha(n)}(1)\geq n$. Lưu ý rằng trước đây ta mô tả nó bằng $A_{\alpha(n)}(\alpha(n))\geq n$; dù sao tốc độ tăng của chúng đều rất chậm, và giá trị đều không vượt quá 4.

<span id="định-nghĩa-cơ-bản"></span>
### Định nghĩa cơ bản

Mỗi nút đều có một hạng. Ở đây hạng không phải là số lượng nút, mà là độ sâu. Hạng ban đầu của một nút là 0; khi hợp nhất, nếu hạng của hai nút khác nhau thì gắn nút có hạng nhỏ hơn vào nút có hạng lớn hơn, đồng thời không cập nhật hạng của nút lớn hơn. Nếu hạng bằng nhau, tùy ý gắn một nút vào nút còn lại và tăng hạng của nút gốc thêm 1. Ở đây hạng của nút gốc cho biết chiều cao của cây. Ký hiệu hạng của $x$ là $rnk(x)$; tương tự, ký hiệu nút cha của $x$ là $fa(x)$. Ta luôn có $rnk(x)+1\leq rnk(fa(x))$.

Để định nghĩa hàm thế năng, trước hết cần định nghĩa một hàm phụ trợ $level(x)$. Trong đó, $level(x)=\max(k:rnk(fa(x))\geq A_k(rnk(x)))$. Khi $rnk(x)\geq1$, định nghĩa thêm một hàm phụ trợ $iter(x)=\max(i:rnk(fa(x))\geq A_{level(x)}^i(rnk(x)))$. Các hàm này được định nghĩa cho những $x$ thỏa $rnk(x)>0$ và $x$ không phải là gốc của một cây.

Những định nghĩa trên có thể hơi rối. Sắp xếp lại một chút: với một $x$ và $fa(x)$, nếu $rnk(x)>0$, ta luôn có thể tìm một cặp $i,k$ sao cho $rnk(fa(x))\geq A_k^i(rnk(x))$; khi đó $level(x)=\max(k)$, và dưới tiền đề này $iter(x)=\max(i)$. $level$ mô tả cấp lặp lớn nhất của $A$, còn $iter$ mô tả số lần lặp lớn nhất ở cấp lặp lớn nhất đó.

Đối với hai hàm này, trong quá trình thực hiện các thao tác, $level(x)$ luôn tăng hoặc giữ nguyên; nếu $level(x)$ không tăng thì $iter(x)$ cũng chỉ tăng hoặc giữ nguyên. Hơn nữa, chúng luôn thỏa hai bất đẳng thức sau:

$$
0\leq level(x)<\alpha(n)
$$

$$
1\leq iter(x)\leq rnk(x)
$$

Dựa vào định nghĩa của $level(x)$, $iter(x)$ và $A_k^j$, các bất đẳng thức này rất dễ chứng minh; phần này xin để lại cho bạn đọc nhằm làm quen với các định nghĩa.

Định nghĩa hàm thế năng $\Phi(S)=\sum\limits_{x\in S}\Phi(x)$, trong đó $S$ biểu thị toàn bộ một DSU, còn $x$ là một nút trong DSU. Định nghĩa $\Phi(x)$ như sau:

$$
\Phi(x)=
\begin{cases}
\alpha(n)\times \mathit{rnk}(x)& \mathit{rnk}(x)=0\ \text{hoặc}\ x\ \text{là gốc của một cây}\\
(\alpha(n)-\mathit{level}(x))\times \mathit{rnk}(x)-iter(x)& \text{ngược lại}
\end{cases}
$$

Tiếp theo ta sẽ chứng minh độ phức tạp thời gian khấu hao là $\Theta(\alpha(n))$ thông qua biến thiên thế năng do các thao tác gây ra. Lưu ý rằng thao tác $union(x,y)$ được thảo luận ở đây bảo đảm $x$ và $y$ đều là gốc của một cây, vì vậy không cần thực hiện thêm $find(x)$ và $find(y)$.

Dễ thấy thế năng luôn là một số không âm. Ngoài ra, ở thời điểm ban đầu, thế năng của DSU bằng $0$.

<span id="chứng-minh"></span>
## Chứng minh

<span id="thao-tác-unionxy"></span>
### Thao tác union(x,y)

Thời gian tiêu tốn của nó là $\Theta(1)$, vì vậy ta xét biến thiên thế năng mà nó gây ra.

Ở đây, giả sử $rnk(x)\leq rnk(y)$, tức là $x$ được nối vào $y$. Khi đó, các nút có thể tăng thế năng chỉ gồm $x$ (từ gốc cây trở thành không phải gốc), $y$ (hạng có thể tăng) và các nút con của $y$ trước thao tác (hạng của nút cha có thể tăng). Trước hết, ta chứng minh rằng thế năng của một nút con $c$ của $y$ trước thao tác không thể tăng; nếu giảm thì giảm ít nhất $1$.

Gọi thế năng của $c$ trước thao tác là $\Phi(c)$ và sau thao tác là $\Phi(c')$. Ở đây $c$ có thể là bất kỳ nút không phải gốc nào với $rnk(c)>0$, và thao tác có thể là bất kỳ thao tác nào, bao gồm cả thao tác find bên dưới. Ta xét bốn trường hợp.

1.  $iter(c)$ và $level(c)$ đều không tăng. Rõ ràng $\Phi(c)=\Phi(c')$.
2.  $iter(c)$ tăng, còn $level(c)$ không tăng. Khi đó $iter(c)$ tăng ít nhất một, tức là $\Phi(c')\leq \Phi(c)-1$; hàm thế năng giảm, và giảm ít nhất 1.
3.  $level(c)$ tăng, còn $iter(c)$ có thể giảm. Tuy nhiên, vì $0<iter(c)\leq rnk(c)$, $iter(c)$ nhiều nhất chỉ giảm $rnk(c)-1$, trong khi $level(c)$ tăng ít nhất $1$. Theo định nghĩa $\Phi(c)=(\alpha(n)-level(c))\times rnk(c)-iter(c)$, suy ra $\Phi(c')\leq\Phi(c)-1$.
4.  Các trường hợp khác. Vì $rnk(c)$ không đổi và $rnk(fa(c))$ không giảm, nên chúng không thể xảy ra.

Vì vậy, các nút có thế năng tăng chỉ có thể là $x$ hoặc $y$. Còn $x$ từ gốc cây trở thành không phải gốc; nếu $rnk(x)=0$ thì luôn có $\Phi(x)=\Phi(x')=0$. Ngược lại, nhất định có $\alpha(x)\times rnk(x)\geq(\alpha(n)-level(x))\times rnk(x)-iter(x)$. Tức là $\Phi(x')\leq \Phi(x)$.

Do đó, điểm duy nhất mà thế năng có thể tăng là $y$. Thế năng của $y$ tăng nhiều nhất $\alpha(n)$. Vì vậy, độ phức tạp thời gian khấu hao của thao tác $union$ là $\Theta(\alpha(n))$.

<span id="thao-tác-finda"></span>
### Thao tác find(a)

Nếu đường tìm kiếm chứa $\Theta(s)$ nút, rõ ràng thời gian tìm kiếm là $\Theta(s)$. Nếu do thao tác tìm kiếm không có nút nào tăng thế năng, và có ít nhất $s-\alpha(n)$ nút giảm thế năng ít nhất $1$, thì có thể chứng minh độ phức tạp thời gian của thao tác $find(a)$ là $\Theta(\alpha(n))$. Để tránh nhầm lẫn, ở đây dùng $a$ làm tham số, còn các $x$ xuất hiện đều chỉ chung một nút nào đó trong DSU.

Trước hết chứng minh rằng không có nút nào tăng thế năng. Điều này rất rõ ràng: ở trên ta đã chứng minh thế năng của mọi nút không phải gốc không tăng, còn $rnk$ của nút gốc không thay đổi, nên không có nút nào tăng thế năng.

Tiếp theo chứng minh rằng có ít nhất $s-\alpha(n)$ nút giảm thế năng ít nhất $1$. Ở trên ta đã chứng minh rằng nếu $level(x)$ hoặc $iter(x)$ thay đổi thì thế năng của chúng giảm ít nhất $1$. Vì vậy, chỉ cần chứng minh rằng có ít nhất $s-\alpha(n)$ nút có $level(x)$ hoặc $iter(x)$ thay đổi.

Nhắc lại định nghĩa thế năng của nút không phải gốc: $\Phi(x)=(\alpha(n)-level(x))\times rnk(x)-iter(x)$, trong đó $level(x)$ và $iter(x)$ là các giá trị lớn nhất sao cho $rnk(fa(x))\geq A_{level(x)}^{iter(x)}(rnk(x))$.

Vì vậy, nếu $root_x$ biểu thị gốc của cây chứa $x$, ta chỉ cần chứng minh $rnk(root_x)\geq A_{level(x)}^{iter(x)+1}(rnk(x))$. Theo định nghĩa của $A_k^i$, $A_{level(x)}^{iter(x)+1}(rnk(x))=A_{level(x)}(A_{level(x)}^{iter(x)}(rnk(x)))$.

Lưu ý rằng ta có thể dùng $k(x)$ thay cho $level(x)$ và $i(x)$ thay cho $iter(x)$ để tránh công thức quá dài. Ở đây, điều cần chứng minh trở thành $rnk(root_x)\geq A_{k(x)}(A_{k(x)}^{i(x)}(rnk(x)))$.

Khi nhìn đến đây, bạn có thể có cảm giác "đây là cái gì vậy". Điều đó có nghĩa là có lẽ bạn cần đọc lại vài lần, hoặc tạm bỏ qua một số nội dung rồi quay lại sau.

Ở đây, ta cần thêm một lớp $A_{k(x)}$ ở bên ngoài, nghĩa là có thể cần tìm thêm một điểm $y$. Cho $y$ là điểm nằm sau $x$ trên đường tìm kiếm và thỏa $k(y)=k(x)$; ở đây "nằm sau trên đường tìm kiếm" tương đương với "là tổ tiên của $x$". Rõ ràng không phải mọi $x$ đều có một $y$ như vậy. Dễ chứng minh rằng số lượng $x$ không có $y$ như vậy không vượt quá $\alpha(n)+2$, vì chỉ có $x$ cuối cùng của mỗi $k$, cùng với $a$ và $root_a$, là không có $y$ như vậy.

Nhấn mạnh lại: $fa(x)$ chỉ nút cha của $x$ **trước** khi nén đường đi; sau khi nén đường đi, nút cha của $x$ luôn được ký hiệu là $root_x$. Với mỗi $x$ có tồn tại $y$, luôn có $rnk(y)\geq rnk(fa(x))$. Đồng thời, ta có $rnk(fa(x))\geq A_{k(x)}^{i(x)}(rnk(x))$. Vì $k(x)=k(y)$, ta gọi chung là $k$, tức là $rnk(fa(x))\geq A_k^{i(x)}(rnk(x))$. Ta cần tạo ra một $A_k$, nên có thể không cần quan tâm đến giá trị của $iter(y)$ mà dùng trực tiếp phiên bản yếu hơn $rnk(fa(y))\geq A_k(rnk(y))$.

Nếu kết hợp các bất đẳng thức lại, điều thú vị sẽ xảy ra. Ta nhận thấy $rnk(fa(y))\geq A_k^{i(x)+1}(rnk(x))$. Nói cách khác, để lặp từ $rnk(x)$ đến $rnk(fa(y))$, có thể lặp $A_k$ ít nhất $i(x)+1$ lần mà vẫn không vượt quá $rnk(fa(y))$.

Rõ ràng $rnk(root_y)\geq rnk(fa(y))$, và $rnk(x)$ không đổi khi nén đường đi. Vì vậy, ta có thể suy ra $rnk(root_x)\geq A_k^{i(x)+1}(rnk(x))$, nghĩa là giá trị $iter(x)$ tăng ít nhất 1; nếu $iter(x)$ không tăng thì chắc chắn $level(x)$ đã tăng.

Do đó, $\Phi(x)$ giảm ít nhất 1. Vì có ít nhất $s-\alpha(n)-2$ nút $x$ như vậy, cuối cùng $\Phi(S)$ giảm ít nhất $s-\alpha(n)-2$, nên độ phức tạp thời gian khấu hao là $\Theta(\alpha(n)+2)=\Theta(\alpha(n))$.

<span id="vì-sao-dsu-có-thể-bị-hack"></span>
## Vì sao DSU có thể bị hack

Câu hỏi này thực chất là: nếu ta không hợp nhất theo hạng, những tính chất nào sẽ bị phá vỡ, khiến độ phức tạp thời gian của DSU không còn được bảo đảm là $\Theta(m\alpha(n))$.

Nếu khi hợp nhất, nút có $rnk$ lớn hơn bị hợp nhất vào nút có $rnk$ nhỏ hơn, thì ta đặt $rnk$ của nút có $rnk$ nhỏ hơn đó bằng $rnk$ của nút còn lại cộng một. Như vậy ta vẫn bảo đảm được $rnk(fa(x))\geq rnk(x)+1$, tránh việc các tính chất cần dùng bị sai hàng loạt như compile error đầy màn hình.

Rõ ràng, nếu làm như vậy, thứ bị phá vỡ chính là câu trong hàm $union(x,y)$: "thế năng của y tăng nhiều nhất $\alpha(n)$".

Tồn tại một cấu trúc có thể làm độ phức tạp thời gian của DSU có nén đường đi xấu đến $\Omega(m\log_{1+\frac{m}{n}}n)$, được định nghĩa như sau:

Cây nhị thức (thực ra không hoàn toàn giống cây nhị thức thông thường), trong đó j là hằng số, $T_k$ được tạo bằng cách lấy một $T_{k-1}$ rồi thêm một $T_{k-j}$ làm con của nút gốc.

![Cây nhị thức](./images/dsu-complexity.svg)

Điều kiện biên: $T_1$ đến $T_j$ đều là một điểm đơn lẻ.

Đặt $rnk(T_k)=r_k$; ở đây ta có $r_k=(k-1)/j$ (lược bỏ chứng minh). Trong mỗi vòng thao tác, ta nối nó vào một nút đơn rồi truy vấn $j$ nút ở đáy. Nói cách khác, khi ta nối nó vào nút đơn, thế năng của nút đơn tăng thêm $(k-1)/j+1$. Khi $j=\lfloor\frac{m}{n}\rfloor$, $i=\lfloor\log_{j+1}\frac{n}{2}\rfloor$, $k=ij$, lượng tăng thế năng là:

$$
\alpha(n)\times((ij-1)/j+1)=\alpha(n)\times((\lfloor\log_{\lfloor\frac{m}{n}\rfloor+1}\frac{n}{2}\rfloor\times \lfloor\frac{m}{n}\rfloor-1)/\lfloor\frac{m}{n}\rfloor+1)
$$

Biến đổi một chút và bỏ mọi ký hiệu lấy phần nguyên, ta có thể suy ra lượng tăng thế năng $\geq \alpha(n)\times(\log_{1+\frac{m}{n}}n-\frac{n}{m})$; với $m$ thao tác, kết quả là $\Omega(m\log_{1+\frac{m}{n}}n-n)=\Omega(m\log_{1+\frac{m}{n}}n)$.

<span id="về-hợp-nhất-theo-heuristic"></span>
## Về hợp nhất theo heuristic

Vì hợp nhất theo hạng khó viết hơn hợp nhất theo heuristic, nên nhiều cao thủ chọn dùng hợp nhất theo heuristic để viết DSU. Cụ thể, ta duy trì một $size(x)$ cho mỗi gốc, và mỗi lần hợp nhất thì gắn cây có $size$ nhỏ hơn vào cây lớn hơn.

Vậy hợp nhất theo heuristic có bị hack không?

Trước hết, có thể giải thích từ các tính chất mà hạng tham gia trong chứng minh. Nếu $size$ có thể thay thế vai trò của $rnk$, thì có thể dùng hợp nhất theo heuristic. Tóm tắt nhanh, hạng tham gia vào chứng minh thông qua ba tính chất sau:

1.  Mỗi lần hợp nhất, nhiều nhất một nút tăng hạng, và tăng nhiều nhất 1.
2.  Luôn có $rnk(fa(x))\geq rnk(x)+1$.
3.  Hạng của nút không giảm.

Với tính chất thứ hai và thứ ba, $siz$ rõ ràng thỏa mãn; tuy nhiên tính chất thứ nhất thì không, vì nếu hợp nhất $x$ vào $y$, $siz(y)$ sẽ tăng thêm đúng $siz(x)$.

Vì vậy, có thể cân nhắc dùng $\log_2 siz(x)$ thay cho $rnk(x)$.

Đối với tính chất thứ nhất, vì $siz$ của một nút nhiều nhất chỉ gấp đôi, nên $\log_2 siz(x)$ tăng nhiều nhất 1. Đối với tính chất thứ hai và thứ ba, kết luận khá rõ ràng, nên lược bỏ chứng minh ở đây.

Tóm lại, nếu không muốn viết hợp nhất theo hạng thì cứ viết hợp nhất theo heuristic; độ phức tạp thời gian vẫn là $\Theta(m\alpha(n))$.
