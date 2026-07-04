author: Ir1d, HeRaNO, Chrogeek, abc1763613206, mxdyzmx

## Định nghĩa góc

Ở tiểu học hoặc trung học cơ sở, ta đã học **định nghĩa tĩnh** của góc: hình gồm hai tia có chung điểm đầu được gọi là góc.

Tuy nhiên, định nghĩa này giới hạn số đo góc trong $[0, 360^\circ]$, gây khó khăn cho việc nghiên cứu sâu hơn. Nó cũng không giải thích rõ được những vấn đề khác, chẳng hạn: quay $720^\circ$ có nghĩa là gì?

Trong toán học phổ thông, góc được định nghĩa theo **nghĩa động**: hình tạo bởi một tia trong mặt phẳng quay quanh đầu mút của nó từ một vị trí đến một vị trí khác được gọi là góc.

Vị trí ban đầu được gọi là **cạnh đầu**, vị trí kết thúc được gọi là **cạnh cuối**. Quy ước:

-   Góc tạo bởi phép quay theo chiều **ngược chiều kim đồng hồ** được gọi là **góc dương**, số đo góc là dương;
-   Góc tạo bởi phép quay theo chiều **cùng chiều kim đồng hồ** được gọi là **góc âm**, số đo góc là âm;
-   Góc mà cạnh cuối không quay so với cạnh đầu được gọi là **góc không**, số đo góc là $0^\circ$.

Như vậy, khái niệm góc được mở rộng thành **góc tùy ý**.

???+ note "Lưu ý"
    Với góc không, cạnh đầu và cạnh cuối trùng nhau; nhưng không phải mọi góc có cạnh đầu và cạnh cuối trùng nhau đều là góc không, ví dụ các góc là bội số của $360^\circ$.

## Hệ radian

Trong ứng dụng thực tế, ta thường phải chuyển đổi giữa số đo góc và nhiều tham số khác; dùng hệ radian để mô tả góc có thể làm giảm số hệ số cần dùng. Vì vậy, tiếp theo ta giới thiệu **hệ radian**:

Góc ở tâm chắn bởi một cung có độ dài bằng bán kính được gọi là góc $1$ radian, ký hiệu là $\text{rad}$ và đọc là radian.

Theo quy ước ở trên, radian của góc dương là dương, radian của góc âm là âm, radian của góc không là $0$. Nếu trong đường tròn bán kính $r$, góc ở tâm $\alpha$ chắn cung có độ dài $l$, thì:

$$
|\alpha|=\dfrac{l}{r}
$$

Từ công thức này cũng có thể viết công thức độ dài cung và diện tích hình quạt; ở đây bỏ qua.

Do đó, góc $360^\circ$ có số đo radian là $2\pi$. Khi đã có quan hệ tương ứng này, ta có thể chuyển đổi giữa đơn vị độ và radian:

$$
k \operatorname{rad} = \frac{\pi}{180^\circ} n^\circ
$$

Xét một góc. Nếu tiếp tục quay cạnh cuối thêm một vòng, thậm chí nhiều vòng, trong khi vị trí cạnh đầu giữ nguyên, thì vị trí cạnh cuối vẫn luôn như cũ; các góc này được gọi là các góc có cùng vị trí cạnh cuối.

Tập hợp các góc có cùng vị trí cạnh cuối với góc $\alpha$ rất dễ xác định, là $\{\varphi \mid \varphi = \alpha + 2k\pi, k \in \mathbf{Z}\}$.

Có thể hiểu là: liên tục quay thêm tròn một vòng cho cạnh của góc thì vị trí cạnh cuối không đổi.

???+ note "Hai hằng số toán học $\pi$ và $\tau$"
    Hiện nay trong giới toán học phương Tây có quan điểm cho rằng "hằng số đường tròn thật sự" nên là $2\pi$, và ký hiệu giá trị này bằng chữ cái Hy Lạp $\tau$. Những người ủng hộ hằng số đường tròn mới chọn ngày 28 tháng 6 để kỷ niệm ngày của hằng số đường tròn "thật sự".
    
    Chẳng hạn, trong hệ radian, một góc đầy đủ là $2\pi$; chia trực tiếp $2\pi$ sẽ thu được các phần bằng nhau của góc đầy đủ. Một ví dụ khác là trong hàm biến phức, cụm $2\pi$ xuất hiện rất thường xuyên.
    
    Để phù hợp với thói quen quy ước phổ biến ở các khu vực Trung Quốc, trong **OI Wiki**, tham số $\pi$ được dùng để biểu diễn hằng số đường tròn.

???+ note "Cách viết hằng số đường tròn khi lập trình"
    Trong ngôn ngữ C/C++, thông thường lấy $\pi$ bằng `acos(-1)`, vì chỉ giá trị này là số chấm động gần $\pi$ nhất. Giá trị $\pi$ viết bằng `acos(-1)` hoặc `4 * atan(1)` là $3.14159265358979310000$.
    
    Nếu dùng các giá trị khác, ví dụ `acos(-1.0/2.0)`, `acos(1.0/2.0)`, `asin(1.0/2.0)`, v.v., giá trị $\pi$ thu được là $3.14159265358979360000$, không phải số chấm động gần $\pi$ nhất.
    
    Nếu bạn nhớ được, cũng có thể viết trực tiếp $3.1415926535897932$.

## Hệ tọa độ Descartes trong mặt phẳng

Hai trục số trên cùng một mặt phẳng, vuông góc với nhau và có chung gốc tọa độ tạo thành hệ tọa độ Descartes trong mặt phẳng (Rectangular Coordinates).

Thông thường, hai trục số được đặt theo phương ngang và phương dọc; chiều sang phải và chiều lên trên lần lượt được lấy làm chiều dương của hai trục. Trục số nằm ngang gọi là trục $x$ (x-axis) hay trục hoành, trục số thẳng đứng gọi là trục $y$ (y-axis) hay trục tung. Trục $x$ và trục $y$ được gọi chung là các trục tọa độ; điểm gốc chung $O$ của chúng được gọi là gốc tọa độ (origin) của hệ tọa độ Descartes trong mặt phẳng. Hệ tọa độ Descartes trong mặt phẳng có gốc $O$ được ký hiệu là hệ tọa độ $xOy$.

Trục $x$ và trục $y$ chia mặt phẳng tọa độ thành bốn góc phần tư (quadrant). Phần bên phải phía trên gọi là góc phần tư thứ nhất; ba phần còn lại lần lượt theo chiều ngược chiều kim đồng hồ gọi là góc phần tư thứ hai, thứ ba và thứ tư. Các góc phần tư được giới hạn bởi các trục số; các điểm trên trục hoành, trục tung và gốc tọa độ không nằm trong bất kỳ góc phần tư nào. Thông thường, trục $x$ và trục $y$ dùng cùng một đơn vị độ dài, nhưng trong trường hợp đặc biệt cũng có thể dùng các đơn vị độ dài khác nhau.

### Mô tả vị trí trong hệ tọa độ Descartes phẳng

Trong hệ tọa độ Descartes phẳng, với mỗi điểm bất kỳ trên mặt phẳng, có duy nhất một cặp số có thứ tự (tức tọa độ (coordinates) của điểm) tương ứng với nó; ngược lại, với mỗi cặp số có thứ tự bất kỳ, có duy nhất một điểm trên mặt phẳng tương ứng với cặp số đó.

Với một điểm bất kỳ $C$ trong mặt phẳng, từ $C$ kẻ các đường vuông góc xuống trục $x$ và trục $y$. Các điểm chân trên trục $x$ và trục $y$ tương ứng là $a, b$, lần lượt được gọi là hoành độ và tung độ của điểm $C$; cặp có thứ tự (ordered pair) $(a, b)$ được gọi là tọa độ Descartes của điểm $C$. Khi một điểm nằm ở các góc phần tư khác nhau hoặc trên các trục tọa độ khác nhau, tọa độ của nó cũng khác nhau.

<span id="&#24179;&#38754;&#26497;&#22352;&#26631;&#31995;"></span>

## Hệ tọa độ cực trong mặt phẳng

Xét tình huống thực tế, chẳng hạn trong hàng hải, người ta nói "điểm $B$ nằm theo hướng lệch đông $30^\circ$ so với hướng bắc từ điểm $A$, cách $100$ mét", chứ không nói "dựng hệ tọa độ Descartes phẳng với $A$ làm gốc tọa độ, khi đó $B(50,50\sqrt 3)$".

Như vậy:

1.  Chọn một điểm cố định $O$ trên mặt phẳng, gọi là **cực**;
2.  Từ cực vẽ một tia $Ox$, gọi là **trục cực**;
3.  Chọn một đơn vị độ dài (trong các bài toán toán học thường là $1$), một đơn vị góc (thường là radian) và chiều dương của nó (thường là ngược chiều kim đồng hồ);

ta lập được **hệ tọa độ cực**.

### Mô tả vị trí trong hệ tọa độ cực

Giả sử $A$ là một điểm trên mặt phẳng.

-   Khoảng cách $|OA|$ giữa cực $O$ và $A$ được gọi là **bán kính cực**, ký hiệu $\rho$;
-   Góc $\angle xOA$ có cạnh đầu là trục cực và cạnh cuối là $OA$ được gọi là **góc cực**, ký hiệu $\varphi$;

Khi đó cặp có thứ tự $(\rho,\varphi)$ là **tọa độ cực** của $A$.

Theo định nghĩa các góc có cùng vị trí cạnh cuối, $(\rho,\varphi)$ và $(\rho,\varphi + 2k\pi)\ (k\in \mathbf{Z})$ thực ra biểu diễn cùng một điểm. Đặc biệt, tọa độ cực của cực là $(0,\varphi)\ (\varphi \in \mathbf{R})$, vì vậy tọa độ cực của một điểm trong mặt phẳng có vô số cách biểu diễn.

Nếu quy ước $\rho \ge 0,0 \le \varphi < 2\pi$, thì ngoài cực ra, mọi điểm khác trong mặt phẳng có thể được biểu diễn bằng duy nhất một cặp có thứ tự $(\rho,\varphi)$; còn điểm được biểu diễn bởi tọa độ cực $(\rho,\varphi)$ thì được xác định duy nhất.

<span id="&#24179;&#38754;&#30452;&#35282;&#22352;&#26631;&#31995;&#19982;&#26497;&#22352;&#26631;&#31995;&#30340;&#30456;&#20114;&#36716;&#25442;"></span>

### Chuyển đổi giữa hệ tọa độ Descartes phẳng và hệ tọa độ cực

Tất nhiên, đôi khi nghiên cứu hình trong hệ tọa độ cực không thuận tiện. Nếu muốn chuyển sang hệ tọa độ Descartes để nghiên cứu, ta có các công thức chuyển đổi. Tọa độ Descartes $(x,y)$ của điểm $A(\rho,\varphi)$ có thể biểu diễn như sau:

$$
\begin{aligned}
x &= \rho \cos \varphi \\
y &= \rho \sin \varphi
\end{aligned}
$$

Suy ra:

$$
\begin{aligned}
\rho^2 &= x^2 + y^2\\
\tan \varphi &= \frac{y}{x}\ \ \ \ (x\not =0)
\end{aligned}
$$

Do đó $\rho = \sqrt{x^2+y^2}$.

Nhưng với cùng một giá trị $\dfrac{y}{x}$, $\tan\varphi$ có hai giá trị $\varphi$ khả dĩ; lúc này cần dựa vào giá trị của $x, y$ để xác định hướng. Cụ thể, định nghĩa hàm:

$$
\operatorname{atan2}(y, x) = \begin{cases}
\arctan(\frac{y}{x}) & \text{if } x > 0 \\
\arctan(\frac{y}{x}) + \pi & \text{if } y \ge 0, x < 0 \\
\arctan(\frac{y}{x}) - \pi & \text{if } y < 0, x < 0 \\
\pi/2 & \text{if } y > 0, x = 0 \\
-\pi/2 & \text{if } y < 0, x = 0 \\
\text{any} & \text{if } y = 0, x = 0
\end{cases}
$$

Khi đó $\varphi = \operatorname{atan2}(y, x)$. Lưu ý miền giá trị của hàm trên là $(-\pi, \pi]$.

Trong thư viện `<math.h>` hoặc `<cmath>` của ngôn ngữ C/C++, [hàm này](https://zh.cppreference.com/w/cpp/numeric/math/atan2) đã được định nghĩa; chỉ cần gọi `atan2(y, x)`.

## Hệ tọa độ Descartes trong không gian

Lập hệ tọa độ Descartes trong không gian bằng cách sau:

1.  Chọn một điểm $O$ trong không gian;
2.  Qua điểm $O$ vẽ ba trục số đôi một vuông góc với nhau $\overrightarrow{Ox}, \overrightarrow{Oy}, \overrightarrow{Oz}$, lần lượt gọi là trục $x$ (trục hoành), trục $y$ (trục tung), trục $z$ (trục đứng), gọi chung là các trục tọa độ. Chiều dương của chúng tuân theo quy tắc bàn tay phải: nắm bàn tay phải quanh trục $z$; khi bốn ngón tay của bàn tay phải quay từ chiều dương của trục $x$ sang chiều dương của trục $y$, hướng của ngón cái chính là chiều dương của trục $z$;
3.  Đặt đơn vị độ dài trên mỗi trục, thông thường đều lấy bằng $1$.

Như vậy ta được một hệ tọa độ Descartes trong không gian, gọi là hệ tọa độ $O-xyz$. Điểm cố định $O$ được gọi là gốc tọa độ của hệ này.

Hai trục tọa độ bất kỳ xác định một mặt phẳng; như vậy có thể xác định ba mặt phẳng đôi một vuông góc, gọi chung là các mặt phẳng tọa độ. Trong đó, mặt phẳng xác định bởi trục $x$ và trục $y$ được gọi là mặt phẳng $xOy$; tương tự có mặt phẳng $yOz$ và mặt phẳng $zOx$. Ba mặt phẳng tọa độ chia không gian thành tám phần, mỗi phần gọi là một bát phần.

### Mô tả vị trí trong hệ tọa độ Descartes không gian

Sau khi cố định hệ tọa độ Descartes không gian $O-xyz$, ta có thể lập được tương ứng một-một giữa các điểm trong không gian và các bộ ba số.

Giả sử $M$ là một điểm trong không gian. Qua điểm $M$, vẽ các mặt phẳng lần lượt vuông góc với trục $x$, trục $y$ và trục $z$. Giả sử ba mặt phẳng này cắt trục $x$, trục $y$ và trục $z$ lần lượt tại $P, Q, R$; các điểm $P, Q, R$ lần lượt được gọi là hình chiếu của điểm $M$ trên trục $x$, trục $y$ và trục $z$. Lại giả sử tọa độ của $P, Q, R$ trên trục $x$, trục $y$ và trục $z$ lần lượt là $x, y, z$; khi đó điểm $M$ xác định một bộ ba $(x, y, z)$.

Ngược lại, nếu cho một bộ ba $(x, y, z)$, có thể lấy điểm $P$ có tọa độ $x$ trên trục $x$, điểm $Q$ có tọa độ $y$ trên trục $y$, và điểm $R$ có tọa độ $z$ trên trục $z$. Sau đó qua các điểm $P, Q, R$ lần lượt vẽ ba mặt phẳng vuông góc với trục $x$, trục $y$ và trục $z$; chúng cắt nhau tại một điểm $M$ trong không gian. Điểm $M$ chính là điểm do bộ ba $(x, y, z)$ xác định.

Như vậy, giữa điểm $M$ trong không gian và bộ ba $(x, y, z)$ có một tương ứng một-một. Bộ ba $(x, y, z)$ được gọi là tọa độ của điểm $M$, ký hiệu $M(x, y, z)$; trong đó $x$ gọi là hoành độ, $y$ gọi là tung độ, $z$ gọi là cao độ.

## Hệ tọa độ trụ trong không gian

Hệ tọa độ trụ trong không gian là cách mở rộng hệ tọa độ cực lên ba chiều: bắt đầu từ hệ tọa độ cực áp dụng trong mặt phẳng, rồi thêm trục $z$ đi qua cực $O$, vuông góc với mặt phẳng đó và hướng lên trên.

Để tìm điểm được mô tả bởi tọa độ trụ $(\rho, \varphi, z)$, trước hết có thể xử lý $\rho$ và $\varphi$ trong hệ tọa độ cực, sau đó dựa vào tọa độ $z$ để di chuyển "lên" hoặc "xuống" dọc theo trục $z$.

### Chuyển đổi giữa hệ tọa độ trụ và hệ tọa độ Descartes không gian

Giá trị $z$ trong hai hệ tọa độ là như nhau.

Phần chuyển đổi giữa $(x,y)$ và $(\rho, \varphi)$ xem mục trên [chuyển đổi giữa hệ tọa độ Descartes phẳng và hệ tọa độ cực](#%E5%B9%B3%E9%9D%A2%E7%9B%B4%E8%A7%92%E5%9D%90%E6%A0%87%E7%B3%BB%E4%B8%8E%E6%9E%81%E5%9D%90%E6%A0%87%E7%B3%BB%E7%9A%84%E7%9B%B8%E4%BA%92%E8%BD%AC%E6%8D%A2).

<span id="&#31354;&#38388;&#29699;&#22352;&#26631;&#31995;"></span>

## Hệ tọa độ cầu trong không gian

Tọa độ cầu có thể được xác định bằng cách sau:

1.  Đứng tại gốc tọa độ, mặt hướng về phía trục cực nằm ngang; trục thẳng đứng có hướng từ chân lên đầu;
2.  Đưa cánh tay lên trên, chỉ theo hướng trục cực thẳng đứng;
3.  Quay ngược chiều kim đồng hồ một góc $\varphi$;
4.  Hạ cánh tay xuống một góc $\vartheta$; lúc này cánh tay chỉ theo hướng do $\varphi$ và $\vartheta$ xác định;
5.  Di chuyển từ gốc tọa độ một khoảng cách $r$ theo hướng đó.

Như vậy sẽ đến điểm được mô tả bởi tọa độ cầu $(r,\vartheta,\varphi)$. Trong đó $\vartheta$ được gọi là **góc thiên đỉnh**, $\varphi$ được gọi là **góc phương vị**.

???+ warning "Cảnh báo"
    Vì nhiều lý do, một số tài liệu dùng $\phi$ để biểu diễn góc thiên đỉnh và dùng $\theta$ để biểu diễn góc phương vị. Khi đọc bài viết gặp hệ tọa độ cầu, nhất định cần chú ý điểm này.
    
    Đồng thời, khi viết bài, nếu dùng hệ tọa độ cầu, nên tuyên bố rõ từ trước ký hiệu nào biểu diễn góc thiên đỉnh và góc phương vị.

<span id="&#26609;&#22352;&#26631;&#31995;&#19982;&#29699;&#22352;&#26631;&#31995;&#30340;&#30456;&#20114;&#36716;&#25442;"></span>

### Chuyển đổi giữa hệ tọa độ trụ và hệ tọa độ cầu

Giá trị $\varphi$ trong hai hệ tọa độ là như nhau.

Từ hệ tọa độ trụ sang hệ tọa độ cầu:

$$
\begin{aligned}
r &= \sqrt{\rho^2 + z^2} \\
\vartheta &= \begin{cases}
\arctan\left(\frac{\rho}{z}\right) & \text{if }z > 0 \\
\pi/2 & \text{if }z = 0, \rho \not= 0 \\
\arctan\left(\frac{\rho}{z}\right) + \pi & \text{if }z < 0 \\
\end{cases}
\end{aligned}
$$

Lưu ý với điểm $(0,0,0)$ trong hệ tọa độ trụ, tọa độ cầu $\vartheta$ của nó không xác định.

Từ hệ tọa độ cầu sang hệ tọa độ trụ:

$$
\begin{aligned}
\rho &= r \sin \vartheta \\
z &= r \cos \vartheta
\end{aligned}
$$

### Chuyển đổi giữa hệ tọa độ Descartes không gian và hệ tọa độ cầu

Có thể kết hợp mục trên [chuyển đổi giữa hệ tọa độ Descartes phẳng và hệ tọa độ cực](#%E5%B9%B3%E9%9D%A2%E7%9B%B4%E8%A7%92%E5%9D%90%E6%A0%87%E7%B3%BB%E4%B8%8E%E6%9E%81%E5%9D%90%E6%A0%87%E7%B3%BB%E7%9A%84%E7%9B%B8%E4%BA%92%E8%BD%AC%E6%8D%A2) và mục trên [chuyển đổi giữa hệ tọa độ trụ và hệ tọa độ cầu](#%E6%9F%B1%E5%9D%90%E6%A0%87%E7%B3%BB%E4%B8%8E%E7%90%83%E5%9D%90%E6%A0%87%E7%B3%BB%E7%9A%84%E7%9B%B8%E4%BA%92%E8%BD%AC%E6%8D%A2), hoặc dùng trực tiếp các công thức dưới đây:

Từ hệ tọa độ Descartes không gian sang hệ tọa độ cầu:

$$
\begin{aligned}
r &= \sqrt{x^2 + y^2 + z^2} \\
\vartheta &= \arccos\left(\frac{z}{\sqrt{x^2 + y^2 + z^2}}\right) \\
\varphi &= \operatorname{atan2}(y, x)
\end{aligned}
$$

Trong đó định nghĩa của $\operatorname{atan2}$ xem tại [chuyển đổi giữa hệ tọa độ Descartes phẳng và hệ tọa độ cực](#%E5%B9%B3%E9%9D%A2%E7%9B%B4%E8%A7%92%E5%9D%90%E6%A0%87%E7%B3%BB%E4%B8%8E%E6%9E%81%E5%9D%90%E6%A0%87%E7%B3%BB%E7%9A%84%E7%9B%B8%E4%BA%92%E8%BD%AC%E6%8D%A2).

Lưu ý với điểm $(0,0,0)$ trong hệ tọa độ Descartes không gian, các giá trị $\vartheta$ và $\varphi$ của tọa độ cầu không xác định.

Từ hệ tọa độ cầu sang hệ tọa độ Descartes không gian:

$$
\begin{aligned}
x &= r \sin \vartheta \cos \varphi \\
y &= r \sin \vartheta \sin \varphi \\
z &= r \cos \vartheta
\end{aligned}
$$
