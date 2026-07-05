Trước khi vào bài, cần nói rõ một vấn đề về thuật ngữ dịch. Vì lý do lịch sử, trong toán học và vật lý, từ "vector" thường được dịch khác nhau.

Trong vật lý, từ này thường được hiểu là "đại lượng vectơ", đối lập với "đại lượng vô hướng". Trong toán học, thường dùng "vectơ". Sự khác biệt kiểu này còn gặp ở các cặp thuật ngữ như "eigen" và "characteristic", "unitary" và các cách dịch tương ứng, v.v.

Trên **OI Wiki**, nội dung chủ yếu hướng tới các ngành kỹ thuật như khoa học máy tính, gần với toán học hơn, nên bài này dùng thuật ngữ "vectơ".

<span id="&#23450;&#20041;&#21450;&#30456;&#20851;&#27010;&#24565;"></span>
## Định nghĩa và các khái niệm liên quan

**Vectơ**: Đại lượng vừa có độ lớn vừa có hướng được gọi là vectơ. Vectơ được nghiên cứu trong toán học là **vectơ tự do**, tức là miễn không thay đổi độ lớn và hướng, điểm đầu và điểm cuối có thể tịnh tiến song song tùy ý. Ký hiệu là $\vec a$ hoặc $\boldsymbol{a}$.

**Đoạn thẳng có hướng**: Đoạn thẳng mang hướng được gọi là đoạn thẳng có hướng. Đoạn thẳng có hướng có ba yếu tố: **điểm đầu, hướng, độ dài**; biết ba yếu tố này thì điểm cuối được xác định duy nhất. Thông thường dùng đoạn thẳng có hướng để biểu diễn vectơ.

**Độ dài của vectơ**: Độ dài của đoạn thẳng có hướng $\overrightarrow{AB}$ được gọi là độ dài của vectơ, tức độ lớn của vectơ đó. Ký hiệu: $|\overrightarrow{AB}|$ hoặc $|\boldsymbol{a}|$.

**Vectơ không**: Vectơ có độ dài bằng $0$. Hướng của vectơ không là tùy ý. Ký hiệu: $\vec 0$ hoặc $\boldsymbol{0}$.

**Vectơ đơn vị**: Vectơ có độ dài bằng $1$ được gọi là vectơ đơn vị theo hướng đó. Thường ký hiệu là $\vec e$ hoặc $\boldsymbol{e}$.

**Vectơ song song**: Hai vectơ **khác không** có cùng hướng hoặc ngược hướng. Ký hiệu: $\boldsymbol a\parallel \boldsymbol b$. Với nhiều vectơ song song nhau, ta có thể chọn một đường thẳng bất kỳ song song với chúng; khi đó mọi nhóm vectơ song song đều có thể tịnh tiến lên cùng một đường thẳng, nên vectơ song song còn được gọi là **vectơ cùng phương**.

**Vectơ bằng nhau**: Các vectơ có độ dài bằng nhau và cùng hướng.

**Vectơ đối**: Các vectơ có độ dài bằng nhau và ngược hướng.

**Góc giữa hai vectơ**: Với hai vectơ khác không $\boldsymbol a,\boldsymbol b$, dựng $\overrightarrow{OA}=\boldsymbol a,\overrightarrow{OB}=\boldsymbol b$. Khi đó $\theta=\angle AOB$ là góc giữa vectơ $\boldsymbol a$ và vectơ $\boldsymbol b$. Ký hiệu: $\langle \boldsymbol a,\boldsymbol b\rangle$. Rõ ràng khi $\theta=0$ thì hai vectơ cùng hướng, khi $\theta=\pi$ thì hai vectơ ngược hướng, khi $\theta=\frac{\pi}{2}$ thì hai vectơ vuông góc, ký hiệu $\boldsymbol a\perp \boldsymbol b$, và quy ước $\theta \in [0,\pi]$.

Cần chú ý rằng vectơ phẳng có hướng, nên không thể so sánh lớn nhỏ giữa hai vectơ (nhưng có thể so sánh độ dài của chúng). Tuy vậy, hai vectơ có thể bằng nhau.

<span id="&#21521;&#37327;&#30340;&#32447;&#24615;&#36816;&#31639;"></span>
## Phép toán tuyến tính trên vectơ

<span id="&#21521;&#37327;&#30340;&#21152;&#20943;&#27861;"></span>
### Cộng và trừ vectơ

Sau khi định nghĩa một đại lượng, ta thường muốn đại lượng đó có phép toán. Phép toán trên vectơ có thể được xét bằng cách tương tự phép toán trên số, cũng có thể được nghiên cứu từ góc nhìn vật lý.

Tương tự khái niệm độ dời trong vật lý, giả sử một người đi từ $A$ qua $B$ đến $C$, thì độ dời người đó đi qua là $\overrightarrow{AB}+\overrightarrow{BC}$. Điều này thực ra tương đương với việc người đó đi thẳng từ $A$ đến $C$, tức $\overrightarrow{AB}+\overrightarrow{BC}=\overrightarrow{AC}$.

Quy tắc tổng hợp lực, tức quy tắc hình bình hành, cũng có thể được xem là một phép cộng vectơ.

Tóm tắt quy tắc cộng vectơ:

1.  **Quy tắc tam giác của phép cộng vectơ**: Nếu các vectơ cần cộng được nối đầu đuôi liên tiếp, thì tổng của chúng là vectơ đi từ điểm đầu của vectơ đầu tiên đến điểm cuối của vectơ cuối cùng.
2.  **Quy tắc hình bình hành của phép cộng vectơ**: Nếu hai vectơ cần cộng có **chung điểm đầu**, thì vectơ tổng là đường chéo của hình bình hành có hai vectơ đó làm hai cạnh kề; điểm đầu là điểm đầu chung của hai vectơ, hướng theo hướng đường chéo của hình bình hành.

Như vậy, phép cộng vectơ có ý nghĩa hình học. Có thể kiểm chứng rằng phép cộng vectơ thỏa **tính giao hoán và tính kết hợp**.

Vì phép trừ số thực có thể viết thành cộng với số đối, khi trừ vectơ ta cũng xét cách viết này. Tức là: $\boldsymbol a-\boldsymbol b=\boldsymbol a+(-\boldsymbol b)$.

Với các vectơ có chung điểm đầu, nếu dựng hiệu của chúng theo quy tắc hình bình hành rồi tịnh tiến, ta thấy **"hiệu của hai vectơ chung điểm đầu" là đoạn thẳng có hướng đi từ "vectơ bị trừ" đến "vectơ trừ"**. Đây cũng là ý nghĩa hình học của phép trừ vectơ.

Đôi khi có hai điểm $A,B$ và muốn biết $\overrightarrow{AB}$, ta có thể dùng phép trừ $\overrightarrow{AB}=\overrightarrow{OB}-\overrightarrow{OA}$.

<span id="&#21521;&#37327;&#30340;&#25968;&#20056;"></span>
### Nhân vectơ với số

Quy ước "tích của số thực $\lambda$ với vectơ $\boldsymbol a$" là một vectơ. Phép toán này gọi là **phép nhân vectơ với số**, ký hiệu $\lambda \boldsymbol a$, với độ dài và hướng được quy định như sau:

1.  $|\lambda \boldsymbol a|=|\lambda||\boldsymbol a|$;
2.  Khi $\lambda >0$, $\lambda\boldsymbol a$ cùng hướng với $\boldsymbol a$; khi $\lambda =0$, $\lambda \boldsymbol a=\boldsymbol 0$; khi $\lambda<0$, $\lambda \boldsymbol a$ ngược hướng với $\boldsymbol a$.

Theo định nghĩa phép nhân với số, có thể kiểm chứng các luật toán sau:

$$
\begin{aligned}
\lambda(\mu \boldsymbol a)&=(\lambda \mu)\boldsymbol a\\
(\lambda+\mu)\boldsymbol a&=\lambda \boldsymbol a+\mu \boldsymbol a\\
\lambda(\boldsymbol a+\boldsymbol b)&=\lambda \boldsymbol a+\lambda \boldsymbol b
\end{aligned}
$$

Đặc biệt:

$$
\begin{gathered}
(-\lambda)\boldsymbol a=-(\lambda \boldsymbol a)=-\lambda(\boldsymbol a)\\
\lambda(\boldsymbol a-\boldsymbol b)=\lambda \boldsymbol a-\lambda \boldsymbol b
\end{gathered}
$$

<span id="&#21028;&#23450;&#20004;&#21521;&#37327;&#20849;&#32447;"></span>
### Kiểm tra hai vectơ cùng phương

Hai vectơ **khác không** $\boldsymbol a$ và $\boldsymbol b$ cùng phương $\iff$ tồn tại duy nhất số thực $\lambda$ sao cho $\boldsymbol b=\lambda \boldsymbol a$.

Chứng minh: Theo định nghĩa phép nhân với số, với vectơ **khác không** $\boldsymbol a$, nếu tồn tại số thực $\lambda$ sao cho $\boldsymbol b=\lambda \boldsymbol a$, thì $\boldsymbol a \parallel \boldsymbol b$.

Ngược lại, nếu $\boldsymbol a\parallel \boldsymbol b$, $\boldsymbol a \not = \boldsymbol 0$, và $|\boldsymbol b|=\mu |\boldsymbol a|$, thì khi $\boldsymbol a$ và $\boldsymbol b$ cùng hướng, $\boldsymbol b=\mu \boldsymbol a$; khi ngược hướng, $\boldsymbol b=-\mu \boldsymbol a$.

Cuối cùng, phép cộng, phép trừ và phép nhân với số của vectơ được gọi chung là các phép toán tuyến tính trên vectơ.

<span id="&#24179;&#38754;&#21521;&#37327;&#30340;&#22522;&#26412;&#23450;&#29702;&#21450;&#22352;&#26631;&#34920;&#31034;"></span>
## Định lý cơ bản của vectơ phẳng và biểu diễn tọa độ

<span id="&#24179;&#38754;&#21521;&#37327;&#22522;&#26412;&#23450;&#29702;"></span>
### Định lý cơ bản của vectơ phẳng

Nội dung định lý: Nếu hai vectơ $\boldsymbol{e_1},\boldsymbol{e_2}$ không cùng phương, thì tồn tại duy nhất cặp số thực $(x,y)$ sao cho mọi vectơ $\boldsymbol p$ cùng mặt phẳng với $\boldsymbol{e_1},\boldsymbol{e_2}$ thỏa $\mathbf p=x\boldsymbol{e_1}+y\boldsymbol{e_2}$.

Có rất nhiều vectơ phẳng; làm thế nào để biểu diễn tất cả vectơ phẳng bằng lượng thông tin ít nhất?

Chỉ dùng một vectơ để biểu diễn tất cả vectơ hiển nhiên là không thể, nhiều nhất chỉ biểu diễn được các vectơ trên một đường thẳng nào đó.

Thêm một vectơ nữa, dùng hai vectơ **không cùng phương** để biểu diễn (hai vectơ cùng phương ở đây có thể xem như cùng một vectơ), khi đó có thể phân tích bất kỳ vectơ phẳng nào theo hai hướng của hai vectơ này.

Hai vectơ không cùng phương trong cùng một mặt phẳng được gọi là **cơ sở**. Nếu các vectơ cơ sở vuông góc với nhau, thì quá trình phân tích vectơ là **phân tích trực giao**.

<span id="&#24179;&#38754;&#21521;&#37327;&#30340;&#22352;&#26631;&#34920;&#31034;"></span>
### Biểu diễn tọa độ của vectơ phẳng

Nếu chọn các vectơ đơn vị $i,j$ cùng hướng với trục hoành và trục tung làm một cơ sở, theo định lý cơ bản của vectơ phẳng, mọi vectơ trên mặt phẳng tương ứng một-một với cặp số thực có thứ tự $(x,y)$.

Cặp số thực có thứ tự $(x,y)$ lại tương ứng một-một với điểm trên hệ tọa độ Descartes phẳng. Vì vậy, dựng $\overrightarrow{OP}=\boldsymbol p$, thì điểm cuối $P(x,y)$ cũng được xác định duy nhất. Do đối tượng nghiên cứu là vectơ tự do và điểm đầu có thể tịnh tiến tùy ý, trong hệ tọa độ Descartes phẳng, mỗi vectơ đều có thể được biểu diễn duy nhất bằng một cặp số thực có thứ tự.

<span id="&#24179;&#38754;&#21521;&#37327;&#30340;&#22352;&#26631;&#36816;&#31639;"></span>
## Phép toán tọa độ của vectơ phẳng

<span id="&#24179;&#38754;&#21521;&#37327;&#32447;&#24615;&#36816;&#31639;"></span>
### Phép toán tuyến tính của vectơ phẳng

Từ các phép toán tuyến tính của vectơ phẳng có thể suy ra phép toán trên tọa độ. Cách làm chính là đổi toàn bộ tọa độ thành biểu diễn theo cơ sở, rồi dùng các luật toán để gộp lại, sau đó viết tọa độ của kết quả.

Nếu hai vectơ $\boldsymbol a=(m,n)$, $\boldsymbol b=(p,q)$, thì:

$$
\begin{aligned}
\boldsymbol a+\boldsymbol b&=(m+p,n+q)\\
\boldsymbol a-\boldsymbol b&=(m-p,n-q)\\
k\boldsymbol a&=(km,kn)
\end{aligned}
$$

<span id="&#27714;&#19968;&#20010;&#21521;&#37327;&#30340;&#22352;&#26631;&#34920;&#31034;"></span>
### Tìm biểu diễn tọa độ của một vectơ

Biết hai điểm $A(a,b),B(c,d)$, dễ chứng minh $\overrightarrow{AB}=(c-a,d-b)$.

<span id="&#24179;&#31227;&#19968;&#28857;"></span>
### Tịnh tiến một điểm

Đôi khi cần tịnh tiến một điểm $P$ theo một hướng nhất định một độ dài đơn vị nào đó. Khi đó ta ghép hướng và khoảng cách cần tịnh tiến thành một vectơ, rồi dùng quy tắc tam giác của phép cộng vectơ để cộng vectơ này vào $\overrightarrow{OP}$; điểm cuối của vectơ thu được chính là điểm sau khi tịnh tiến.

<span id="&#19977;&#28857;&#20849;&#32447;&#30340;&#21028;&#23450;"></span>
### Kiểm tra ba điểm thẳng hàng

Nếu ba điểm $A,B,C$ thẳng hàng, thì $\overrightarrow{OB}=\lambda \overrightarrow{OA}+(1-\lambda)\overrightarrow{OC}$.

<span id="&#19977;&#28857;&#20849;&#32447;&#21028;&#23450;&#30340;&#25299;&#23637;"></span>
### Mở rộng kiểm tra ba điểm thẳng hàng

Trong tam giác $ABC$, nếu $D$ là điểm chia đoạn $BC$ theo tỉ lệ $n\ BD=k\ DC$, thì có: $\overrightarrow{AD}=\frac{n}{k+n}\overrightarrow{AB}+\frac{k}{k+n}\overrightarrow{AC}$

<span id="&#22312;&#19977;&#32500;&#31354;&#38388;&#20013;&#30340;&#25299;&#23637;&#65288;&#31435;&#20307;&#20960;&#20309;/&#31354;&#38388;&#21521;&#37327;&#65289;"></span>
## Mở rộng trong không gian ba chiều (hình học không gian/vectơ không gian)

Trong không gian, mọi nội dung ở trên đều vẫn đúng. Ngoài ra còn có:

<span id="&#31354;&#38388;&#21521;&#37327;&#22522;&#26412;&#23450;&#29702;"></span>
### Định lý cơ bản của vectơ không gian

Nội dung định lý: Nếu ba vectơ $\boldsymbol{e_1},\boldsymbol{e_2},\boldsymbol{e_3}$ không đồng phẳng, thì tồn tại duy nhất bộ số thực $(x,y,z)$ sao cho mọi vectơ $\boldsymbol p$ trong không gian thỏa $\mathbf p=x\boldsymbol{e_1}+y\boldsymbol{e_2}+z\boldsymbol{e_3}$.
Theo định lý cơ bản của vectơ không gian, ta cũng có thể dùng ba vectơ cơ sở đôi một vuông góc $\boldsymbol{e_1},\boldsymbol{e_2},\boldsymbol{e_3}$ làm cơ sở trực giao, thiết lập **hệ tọa độ Descartes trong không gian** và dùng bộ ba $(x,y,z)$ làm tọa độ để biểu diễn vectơ không gian.

<span id="&#20849;&#38754;&#21521;&#37327;&#22522;&#26412;&#23450;&#29702;"></span>
### Định lý cơ bản về vectơ đồng phẳng

Nếu tồn tại hai vectơ không cùng phương $\boldsymbol{x},\boldsymbol{y}$, thì điều kiện cần và đủ để vectơ $\boldsymbol{p}$ đồng phẳng với $\boldsymbol{x},\boldsymbol{y}$ là tồn tại duy nhất cặp số thực $(a,b)$ sao cho $\boldsymbol{p}=a\boldsymbol{x}+b\boldsymbol{y}$.

<span id="&#26041;&#21521;&#21521;&#37327;"></span>
### Vectơ chỉ phương

Hướng của một đường thẳng trong không gian được biểu diễn bằng một vectơ khác không song song với đường thẳng đó; vectơ này được gọi là một vectơ chỉ phương của đường thẳng. Vị trí của đường thẳng trong không gian được **xác định hoàn toàn** bởi một điểm trong không gian mà nó đi qua và một vectơ chỉ phương của nó.

Chú ý rằng đường thẳng trong mặt phẳng cũng có vectơ chỉ phương.

Với đường thẳng trong **không gian**, có các cách tìm vectơ chỉ phương sau:

-   Nếu có $A(x_1,y_1,z_1),B(x_2,y_2,z_2)$, thì một vectơ chỉ phương của đường thẳng chứa $AB$ là $\boldsymbol{s}=(x_2-x_1,y_2-y_1,z_2-z_1)$.

-   Nếu biết một mặt phẳng **vuông góc** với đường thẳng cần tìm, và phương trình tổng quát của mặt phẳng đó là $ax+by+cz+d=0$, thì một vectơ chỉ phương của đường thẳng vuông góc với mặt phẳng này là $\boldsymbol{s}=(a,b,c)$; vectơ chỉ phương này cũng là **một vectơ pháp tuyến** của mặt phẳng đó.

<span id="&#27861;&#21521;&#37327;"></span>
### Vectơ pháp tuyến

Với một mặt $ABCD$, vectơ pháp tuyến $\boldsymbol{n}$ của nó vuông góc với mặt đó.

Cách tính: chọn tùy ý hai đường thẳng trong mặt, chẳng hạn $\overrightarrow{AB},\overrightarrow{AD}$, sao cho $\overrightarrow{AB} \cdot \boldsymbol{n}=\boldsymbol{0}$ và $\overrightarrow{AD} \cdot \boldsymbol{n}=\boldsymbol{0}$, rồi dùng phương pháp tọa độ để tính.

<span id="&#21521;&#37327;&#19982;&#30697;&#38453;"></span>
## Vectơ và ma trận

Trong đại số tuyến tính, biến đổi tuyến tính có thể được biểu diễn bằng ma trận. Gọi $T$ là một biến đổi tuyến tính ánh xạ từ $\mathbf R^n$ sang $\mathbf R^m$, và $\mathbf x$ là một vectơ cột $n$ chiều. Khi đó tồn tại một ma trận $m\times n$ $A$ sao cho

$$
T(\mathbf x)=A\mathbf x.
$$

Ma trận $A$ được gọi là ma trận biến đổi của biến đổi tuyến tính $T$. Trong các bài toán thuật toán, thông thường biến đổi tuyến tính được thực hiện trong cùng số chiều, nên $A$ là ma trận vuông. Như vậy, bài toán biến đổi tuyến tính trên vectơ có thể chuyển thành bài toán nhân ma trận.

Tiếp theo, ta xét ba loại biến đổi thường gặp trong thi đấu và ma trận biến đổi tương ứng của chúng: biến đổi co giãn (ma trận biến đổi ký hiệu $S$), biến đổi quay (ma trận biến đổi ký hiệu $R$) và biến đổi tịnh tiến (ma trận biến đổi ký hiệu $T$).

<span id="&#25918;&#32553;&#21464;&#25442;"></span>
### Biến đổi co giãn

Với vectơ cột $n$ chiều $\boldsymbol a$, co giãn từng chiều của nó lần lượt $v_1,v_2,\ldots,v_n$ lần. Dễ thấy ma trận biến đổi của thao tác co giãn là ma trận đường chéo $n\times n$, tức $S=\operatorname{diag}\{v_1,v_2,\ldots,v_n\}$.

<span id="&#26059;&#36716;&#21464;&#25442;"></span>
### Biến đổi quay

Quay vectơ là thao tác tương đối phức tạp; ở đây chỉ thảo luận trường hợp hai chiều và ba chiều.

<span id="&#21521;&#37327;&#32469;&#28857;&#26059;&#36716;"></span>
#### Quay vectơ quanh một điểm

Quay vectơ quanh một điểm thường là quay vectơ quanh gốc tọa độ. Với việc quay một điểm quanh điểm khác $P$, có thể dùng biến đổi tịnh tiến để đưa điểm $P$ về gốc tọa độ, thực hiện quay vectơ rồi tịnh tiến hệ tọa độ về vị trí ban đầu. Gọi ma trận biến đổi tịnh tiến là $T$, ma trận biến đổi quay quanh gốc tọa độ là $R$, thì ma trận biến đổi của toàn bộ quá trình là $TRT^{-1}$. Theo ý nghĩa hình học, $T^{-1}$ chắc chắn tồn tại.

Trong không gian hai chiều, giả sử $\boldsymbol a=(x,y)$, góc nghiêng là $\theta$, độ dài là $l=\sqrt{x^2+y^2}$. Khi đó $x=l\cos \theta,y=l\sin\theta$. Cho vectơ quay ngược chiều kim đồng hồ quanh gốc tọa độ một góc $\alpha$, ta được vectơ $\boldsymbol b=(l\cos(\theta+\alpha),l\sin(\theta+\alpha))$.

![](./images/vector-rotation.svg)

Theo các hằng đẳng thức lượng giác,

$$
\boldsymbol{b}=(l(\cos\theta\cos\alpha-\sin\theta\sin\alpha),l(\sin\theta\cos\alpha+\cos\theta\sin\alpha))
$$

Rút gọn,

$$
\boldsymbol b=(l\cos\theta\cos\alpha-l\sin\theta\sin\alpha,l\sin\theta\cos\alpha+l\cos\theta\sin\alpha)
$$

Thay $x,y$ ở trên vào, ta được

$$
\boldsymbol b=(x\cos\alpha-y\sin\alpha,y\cos\alpha+x\sin\alpha)
$$

Vì vậy trong không gian hai chiều, ma trận biến đổi $R$ là

$$
R=
\begin{bmatrix}
\cos\alpha & -\sin\alpha\\
\sin\alpha & \cos\alpha
\end{bmatrix}.
$$

Trong không gian ba chiều, quay vectơ cần dùng hai tham số góc, tức góc thiên đỉnh và góc phương vị; có thể dùng [hệ tọa độ cầu trong không gian](../coordinate.md#hệ-tọa-độ-cầu-trong-không-gian) để thực hiện phép quay.

<span id="&#21521;&#37327;&#32469;&#30452;&#32447;&#26059;&#36716;"></span>
#### Quay vectơ quanh một đường thẳng

Với vectơ ba chiều, trường hợp thường gặp hơn là quay quanh một đường thẳng. Tương tự, để thuận tiện, giả sử đường thẳng này đi qua gốc tọa độ. Nếu đường thẳng không đi qua gốc tọa độ, ta vẫn có thể tịnh tiến hệ tọa độ để chuyển về trường hợp này.

Lấy vectơ chỉ phương của đường thẳng là $\boldsymbol u=(u_x,u_y,u_z)$, giả sử vectơ ba chiều quay quanh nó ngược chiều kim đồng hồ một góc $\theta$. Khi đó ma trận biến đổi tương ứng $R$ là[^note1]

$$
R=
\begin{bmatrix}
u_x^2 \left(1-\cos \theta\right) + \cos \theta & u_x u_y \left(1-\cos \theta\right) - u_z \sin \theta & u_x u_z \left(1-\cos \theta\right) + u_y \sin \theta \\ 
u_x u_y \left(1-\cos \theta\right) + u_z \sin \theta & u_y^2\left(1-\cos \theta\right) + \cos \theta & u_y u_z \left(1-\cos \theta\right) - u_x \sin \theta \\ 
u_x u_z \left(1-\cos \theta\right) - u_y \sin \theta & u_y u_z \left(1-\cos \theta\right) + u_x \sin \theta & u_z^2\left(1-\cos \theta\right) + \cos \theta
\end{bmatrix}.
$$

<span id="&#24179;&#31227;&#21464;&#25442;"></span>
### Biến đổi tịnh tiến

Biến đổi tịnh tiến không phải là biến đổi tuyến tính, mà là biến đổi affine. Tuy nhiên, biến đổi affine trong $\mathbf R^n$ vẫn có thể được biểu diễn bằng biến đổi tuyến tính trong $\mathbf R^{n+1}$.

Xét vectơ $n$ chiều $\boldsymbol a=(a_1,a_2, \ldots , a_n)$, cần tịnh tiến nó theo vectơ $\boldsymbol t=(t_1, t_2, \ldots , t_n)$. Ta thêm một chiều vào vectơ cột $\boldsymbol a$ và đặt bằng $1$, thu được vectơ cột mới $\boldsymbol a'=(a_1, a_2, \ldots , a_n, 1)$. Khi đó ma trận biến đổi $T$ có thể viết là

$$
T=
\begin{bmatrix}
1 &   &        &   & t_1    \\
  & 1 &        &   & t_2    \\
  &   & \ddots &   & \vdots \\
  &   &        & 1 & t_n    \\
  &   &        &   & 1      \\
\end{bmatrix}.
$$

Với các ma trận biến đổi tuyến tính khác, chỉ cần thêm một hàng và một cột vào ma trận, điền $0$ vào các phần khác trừ phần tử góc dưới bên phải bằng $1$. Bằng cách này, mọi ma trận biến đổi tuyến tính đều có thể chuyển thành ma trận biến đổi affine. Ví dụ, với phép quay vectơ hai chiều, ma trận biến đổi có thể trở thành

$$
R'=
\begin{bmatrix}
\cos\alpha & -\sin\alpha & 0\\
\sin\alpha & \cos\alpha & 0\\
0 & 0 & 1
\end{bmatrix}.
$$

<span id="&#21521;&#37327;&#30340;&#26356;&#20005;&#26684;&#23450;&#20041;"></span>
## Định nghĩa chặt chẽ hơn về vectơ

Ở trên, vectơ được định nghĩa là đoạn thẳng có hướng trong không gian. Tuy nhiên, nói chặt chẽ, vectơ không chỉ là đoạn thẳng có hướng. Để đưa ra định nghĩa chặt chẽ hơn về vectơ, trước hết cần định nghĩa [không gian tuyến tính](./vector-space.md); nội dung cụ thể xem phần giới thiệu trong trang [không gian tuyến tính](./vector-space.md).

[^note1]: Xem [Rotation matrix from axis and angle - Wikipedia](https://en.wikipedia.org/wiki/Rotation_matrix#Rotation_matrix_from_axis_and_angle)
