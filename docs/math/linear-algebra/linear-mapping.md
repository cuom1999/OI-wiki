Nghiên cứu ánh xạ tuyến tính là nghiên cứu các ánh xạ giữa những không gian tuyến tính.

Ánh xạ tuyến tính có thể được biểu diễn dưới dạng ma trận, vì vậy nhiều khái niệm của ma trận đều có đối ứng trong ánh xạ tuyến tính.

<span id="ánh-xạ-tuyến-tính-và-biến-đổi-tuyến-tính"></span>
## Ánh xạ tuyến tính và biến đổi tuyến tính

Giả sử $V$ và $W$ là hai không gian tuyến tính trên trường $F$, và $T$ là một ánh xạ từ $V$ đến $W$.

Nếu với mọi vectơ $x$ và $y$ trong $V$, mọi vô hướng $k$ và $l$ trong trường $F$, đẳng thức sau luôn đúng:

$$
T(kx+ly)=kTx+lTy
$$

thì $T$ được gọi là một ánh xạ tuyến tính từ $V$ đến $W$. Nếu $W=V$, thì $T$ được gọi là một biến đổi tuyến tính trên $V$.

Ví dụ, biến đổi đồng nhất $T_e$ giữ nguyên không gian, còn biến đổi không $T_0$ ánh xạ không gian vào không gian không.

Ký hiệu $L(V,W)$ biểu thị tập hợp tất cả các ánh xạ tuyến tính từ $V$ đến $W$. Tập hợp toàn bộ các biến đổi tuyến tính $L(V,V)$ cũng được ký hiệu là $L(V)$.

<span id="tính-chất"></span>
### Tính chất

-   Ánh xạ tuyến tính đưa vectơ không thành vectơ không.
-   Ánh xạ tuyến tính bảo toàn dạng của phép toán tuyến tính, tức là ánh xạ tuyến tính của một tổ hợp tuyến tính bằng tổ hợp tuyến tính của các ảnh.
-   Ánh xạ tuyến tính bảo toàn tính phụ thuộc tuyến tính: nếu trước khi ánh xạ là phụ thuộc tuyến tính, thì sau khi ánh xạ vẫn phụ thuộc tuyến tính.

Tuy nhiên ánh xạ tuyến tính không bảo toàn tính độc lập tuyến tính. Các vectơ độc lập tuyến tính trước khi ánh xạ không nhất thiết vẫn độc lập tuyến tính sau khi ánh xạ.

<span id="biểu-diễn-ma-trận-của-ánh-xạ-tuyến-tính"></span>
## Biểu diễn ma trận của ánh xạ tuyến tính

Giả sử $V$ có số chiều là $n$, một cơ sở của $V$ là $\alpha_1,\cdots,\alpha_n$, $W$ có số chiều là $m$, một cơ sở của $W$ là $\beta_1,\cdots,\beta_m$, và $T$ là một ánh xạ tuyến tính từ $V$ đến $W$.

Biểu diễn ảnh của mỗi $\alpha$ qua $T$ theo cơ sở $\beta$:

$$
T\alpha_j=a_{1j}\beta_1+\cdots+a_{mj}\beta_m
$$

Dùng ký hiệu ma trận:

$$
T(\alpha_1,\cdots,\alpha_n)=(T\alpha_1,\cdots,T\alpha_n)=(\beta_1,\cdots,\beta_m)A
$$

Ma trận $A$ được gọi là biểu diễn ma trận của ánh xạ tuyến tính $T$ theo hai cơ sở này.

<span id="không-gian-hạt-nhân-và-không-gian-ảnh-của-ánh-xạ-tuyến-tính"></span>
## Không gian hạt nhân và không gian ảnh của ánh xạ tuyến tính

Phần này mô tả không gian hạt nhân và không gian ảnh từ góc nhìn của ánh xạ tuyến tính. Dưới biểu diễn ma trận, không gian hạt nhân và không gian ảnh của ánh xạ tuyến tính tương ứng với không gian hạt nhân và không gian ảnh của ma trận.

Giả sử $T$ là ánh xạ tuyến tính từ không gian $V$ đến không gian $W$, đặt:

$$
N(T)=\{x\in V|Tx=0\}
$$

$$
R(T)=Im(T)=\{y\in W|\exists x\in V,y=Tx\}
$$

$N(T)$ là một không gian con của $V$, còn $R(T)$ là một không gian con của $W$. $N(T)$ và $R(T)$ lần lượt được gọi là không gian hạt nhân và không gian ảnh của $T$; số chiều của $N(T)$ được gọi là **độ không** hoặc **độ khuyết** của $T$, còn số chiều của $R(T)$ được gọi là **hạng** của $T$.

Định lý: Giả sử $T$ là ánh xạ tuyến tính từ không gian $V$ đến không gian $W$, và $V$ hữu hạn chiều. Khi đó $N(T)$ và $R(T)$ đều hữu hạn chiều, đồng thời:

$$
\operatorname{dim} N(T)+\operatorname{dim} R(T)=\operatorname{dim} V
$$

tức là độ khuyết cộng với hạng của $T$ bằng số chiều của miền xác định $V$.

<span id="biểu-diễn-ma-trận-của-biến-đổi-tuyến-tính"></span>
## Biểu diễn ma trận của biến đổi tuyến tính

Giả sử $V$ có số chiều là $n$, một cơ sở của $V$ là $\alpha_1,\cdots,\alpha_n$, và $T$ là một biến đổi tuyến tính trên $V$. Khi đó:

$$
T\alpha_j=a_{1j}\alpha_1+\cdots+a_{nj}\alpha_n
$$

Dùng ký hiệu ma trận:

$$
T(\alpha_1,\cdots,\alpha_n)=(T\alpha_1,\cdots,T\alpha_n)=(\alpha_1,\cdots,\alpha_n)A
$$

Ma trận $A$ được gọi là biểu diễn ma trận của biến đổi tuyến tính $T$ theo cơ sở này.

Do cấu trúc không gian và tính tuyến tính của $T$, $T$ được xác định hoàn toàn bởi $T\alpha_1,\cdots,T\alpha_n$, vì vậy $T$ xác định duy nhất một ma trận $A$.

Định lý: Giả sử $V$ có số chiều là $n$, $\alpha_1,\cdots,\alpha_n$ là một cơ sở của $V$. Với mọi ma trận vuông cấp $n$ bất kỳ $A$, tồn tại duy nhất một biến đổi tuyến tính $T$ từ $V$ đến $V$ sao cho ma trận của $T$ đúng bằng $A$.

Hệ quả: Có một song ánh giữa $L(V,V)$ và toàn bộ các ma trận vuông cấp $n$.

Ví dụ: biến đổi không tương ứng với ma trận không, biến đổi đồng nhất tương ứng với ma trận đơn vị.

<span id="không-gian-tạo-bởi-các-biến-đổi-tuyến-tính"></span>
## Không gian tạo bởi các biến đổi tuyến tính

Định lý: $L(V)$ cũng có thể tạo thành một không gian tuyến tính. Trang bị cho $L(V)$ các phép toán sau: với mọi $T_1$ và $T_2$ trong $L(V)$, mọi $x$ trong $V$, và mọi $k$ trong trường $F$,

$$
(T_1+T_2)x=T_1x+T_2x
$$

$$
(kT_1)x=k(T_1x)
$$

$L(V)$ là một không gian tuyến tính trên $F$, tức là không gian các biến đổi tuyến tính.

Với hai biến đổi tuyến tính $T_1$ và $T_2$ trong $L(V)$, định nghĩa tích $T_1T_2$ của $T_1$ và $T_2$ là:

$$
(T_1T_2)x=T_1(T_2x)
$$

Có thể kiểm chứng $(T_1T_2)$ cũng là một biến đổi tuyến tính trong $L(V)$, và tích của các biến đổi tuyến tính thỏa mãn luật kết hợp nhưng không thỏa mãn luật giao hoán, tương tự tích ma trận.

Với biến đổi tuyến tính $T_1$ trong $L(V)$, nếu tồn tại biến đổi tuyến tính $T_2$ trong $L(V)$ sao cho với mọi vectơ $x$ trong $V$:

$$
(T_1T_2)x=T_1(T_2x)=x
$$

thì $T_2$ được gọi là biến đổi nghịch đảo của $T_1$, ký hiệu:

$$
T_2=T_1^{-1}
$$

khi đó:

$$
T_1T_2=T_2T_1=T_e
$$

Định lý: Giả sử $V$ có số chiều là $n$, $\alpha_1,\cdots,\alpha_n$ là một cơ sở của $V$. Theo cơ sở này, ma trận của biến đổi tuyến tính $T_1$ là $A$, ma trận của $T_2$ là $B$. Khi đó:

-   Ma trận của biến đổi tuyến tính $T_1+T_2$ là $A+B$.
-   Ma trận của bội vô hướng $kT_1$ là $kA$.
-   Ma trận của tích biến đổi tuyến tính $T_1T_2$ là $AB$.
-   Nếu biến đổi nghịch đảo của $T_1$ tồn tại, thì ma trận của nó là $A^{-1}$.

<span id="tọa-độ"></span>
## Tọa độ

Giả sử $n$ vectơ $x$ là một cơ sở của không gian $n$ chiều $V$. Với mọi vectơ $y$ trong $V$, đặt $y$ là:

$$
y=a_1x_1+a_2x_2+\cdots+a_nx_n=(x_1,x_2,\cdots,x_n)\begin{pmatrix}a_1\\a_2\\\vdots\\a_n\end{pmatrix}
$$

Vectơ cột:

$$
\begin{pmatrix}a_1\\a_2\\\vdots\\a_n\end{pmatrix}
$$

được gọi là **tọa độ** của vectơ $y$ theo cơ sở $x_1,x_2,\cdots,x_n$.

Tọa độ là vectơ cột tạo bởi các vô hướng trong trường, cần phân biệt với vectơ trong nhóm Abel.

<span id="công-thức-đổi-tọa-độ"></span>
## Công thức đổi tọa độ

Giả sử $V$ có số chiều là $n$, trong $L(V)$ có biến đổi $T$, và ma trận của $T$ theo cơ sở $\alpha_1,\cdots,\alpha_n$ là $A$. Giả sử:

$$
\xi=(\alpha_1,\cdots,\alpha_n)\begin{pmatrix}x_1\\x_2\\\vdots\\x_n\end{pmatrix}
$$

và:

$$
T\xi=T(\alpha_1,\cdots,\alpha_n)\begin{pmatrix}y_1\\y_2\\\vdots\\y_n\end{pmatrix}
$$

khi đó:

$$
T\xi=T(\alpha_1,\cdots,\alpha_n)\begin{pmatrix}y_1\\y_2\\\vdots\\y_n\end{pmatrix}=(\alpha_1,\cdots,\alpha_n)A\begin{pmatrix}x_1\\x_2\\\vdots\\x_n\end{pmatrix}
$$

Về bản chất, các điểm dạng vectơ cột trong không gian $V$ đều có dạng "cơ sở nhân với tọa độ". Điểm vectơ cột $x$ trong không gian $V$ tự nó dùng ma trận đơn vị $I$ làm cơ sở, tức là $x=Ix$.

Chỉ khi cùng một cơ sở được giữ cố định, biến đổi tuyến tính thuần túy $T$ mới chính là việc nhân tọa độ ở bên trái với một ma trận thông thường.

Có thể xem biến đổi tuyến tính $T$ như một bộ lọc quan sát đối với không gian $V$. Đối tượng tác động của biến đổi tuyến tính $T$ là không gian $V$, làm biến dạng không gian $V$. Sau khi thêm bộ lọc, vị trí của bản thân điểm không đổi.

Định lý này cũng cho thấy, với biến đổi tuyến tính $T$ trên cơ sở vectơ cột, điều đó tương đương với việc nhân bên phải cơ sở với một ma trận chuyển.

Vì vậy, giữa các cơ sở khác nhau, quan hệ tọa độ là nhân bên trái với ma trận nghịch đảo của ma trận chuyển cơ sở.

<span id="ma-trận-chuyển-cơ-sở"></span>
## Ma trận chuyển cơ sở

Giả sử $n$ vectơ $x$ và $n$ vectơ $y$ là hai cơ sở của không gian $V$. Với $1\leq i\leq n$, gọi tọa độ của mỗi vectơ $y_i$ theo cơ sở $x_1,x_2,\cdots,x_n$ là:

$$
y_i=(x_1,x_2,\cdots,x_n)\begin{pmatrix}a_{1i}\\a_{2i}\\\vdots\\a_{ni}\end{pmatrix}
$$

Khi đó $n$ vectơ $y$ ghép thành ma trận ở vế trái, còn $n$ tọa độ ghép thành ma trận $A$ ở vế phải:

$$
(y_1,y_2,\cdots,y_n)=(x_1,x_2,\cdots,x_n)A
$$

Ma trận $A$ được gọi là **ma trận chuyển cơ sở** từ cơ sở $x_1,x_2\cdots,x_n$ sang cơ sở $y_1,y_2\cdots,y_n$, cũng gọi là ma trận biến đổi.

Ma trận chuyển cơ sở là khả nghịch. Theo đẳng thức trên, ma trận chuyển cơ sở từ cơ sở $y_1,y_2\cdots,y_n$ sang cơ sở $x_1,x_2\cdots,x_n$ là $A^{-1}$.

Ma trận chuyển cơ sở là ma trận tạo bởi các vô hướng trong trường, không phải ma trận ghép từ các vectơ trong nhóm Abel, nên cần phân biệt hai khái niệm này.

Giả sử $n$ vectơ $x$ và $n$ vectơ $y$ là hai cơ sở của không gian $V$. Với cùng một vectơ $z$ trong không gian $V$, có đẳng thức:

$$
z=(x_1,x_2,\cdots,x_n)\begin{pmatrix}\xi_1\\\xi_2\\\vdots\\\xi_n\end{pmatrix}=(y_1,y_2\cdots,y_n)\begin{pmatrix}\eta_1\\\eta_2\\\vdots\\\eta_n\end{pmatrix}
$$

Thay vào công thức ở trên:

$$
(y_1,y_2\cdots,y_n)=(x_1,x_2\cdots,x_n)A
$$

Do tính duy nhất, thu được:

$$
\begin{pmatrix}\xi_1\\\xi_2\\\vdots\\\xi_n\end{pmatrix}=A\begin{pmatrix}\eta_1\\\eta_2\\\vdots\\\eta_n\end{pmatrix}
$$

hoặc:

$$
\begin{pmatrix}\eta_1\\\eta_2\\\vdots\\\eta_n\end{pmatrix}=A^{-1}\begin{pmatrix}\xi_1\\\xi_2\\\vdots\\\xi_n\end{pmatrix}
$$

Đây là phép biến đổi thuần túy giữa các tọa độ; các công thức đổi tọa độ đều nằm trong trường vô hướng. Như đã phân biệt ở phần trước, vectơ trong không gian tuyến tính và nhóm Abel là "vectơ trừu tượng", còn tọa độ và các phần tử của ma trận chuyển cơ sở đều nằm trong trường vô hướng, có thể coi là "vectơ cụ thể"; cần xem hai loại vectơ này là hai khái niệm khác nhau.

Ma trận có thể biến đổi toàn bộ không gian, tức toàn bộ các tọa độ; vectơ cột $x$ với vai trò tọa độ trải khắp toàn bộ không gian.

Ma trận đơn vị $I$ được tạo bởi các vectơ đơn vị. Ma trận $A$ sẽ biến đổi ma trận đơn vị $I$ thành từng vectơ cột của ma trận $A$, tức là biến đổi từng vectơ đơn vị thành từng vectơ cột của ma trận $A$. Vì vậy nhân bên trái với ma trận $A$ cũng có thể được xem là thực hiện một biến đổi như vậy lên không gian.

Vectơ nhân trái với ma trận cũng có thể được xem là tọa độ nhân trái với một hệ vectơ. Nhìn theo quan điểm tọa độ thì:

$$
Iy=Xa
$$

Cùng một vectơ cột $y$, trong không gian "bình thường", tức không gian do ma trận đơn vị $I$ biểu diễn, có tọa độ là $y$; trong không gian mới sau biến đổi, tọa độ được ký hiệu là $a$. Như vậy, ma trận $X$ không chỉ là một cơ sở trong không gian bình thường, mà còn là ma trận chuyển cơ sở từ hệ vectơ $I$ sang hệ vectơ $X$.

Biến đổi tuyến tính $T$ ánh xạ một cơ sở thành một cơ sở khác, nên tọa độ cũng được ánh xạ thành một tọa độ khác.

Nếu ma trận chuyển cơ sở của biến đổi tuyến tính $T$ ánh xạ cơ sở $\alpha$ sang $\beta$ là $A$, thì ma trận cơ sở tương ứng thỏa mãn $\beta=\alpha A$.

Vì vậy quan hệ tọa độ đúng là đảo ngược lại. Giả sử tọa độ sau khi qua biến đổi tuyến tính $T$ là $b$, tức là tọa độ quan sát được sau khi thêm bộ lọc là $b$, thì biểu diễn của điểm trong $V$ là $\beta b$. Cách khôi phục là dùng ma trận chuyển cơ sở để viết biểu diễn của điểm trong $V$ thành $\alpha Ab$. Khi đó việc đổi tọa độ tương ứng với nhân bên trái với nghịch đảo của ma trận chuyển cơ sở.

<span id="biến-đổi-tuyến-tính-và-tương-tự-ma-trận"></span>
## Biến đổi tuyến tính và tương tự ma trận

Quan hệ của một biến đổi tuyến tính $T$ trong không gian $V$ đối với cơ sở $\alpha$ của không gian $V$ là:

Biến đổi tuyến tính $T$ tác động lên cơ sở $\alpha$, ánh xạ cơ sở $\alpha$ thành $T(\alpha)$, tương đương với việc nhân bên phải cơ sở $\alpha$ với một ma trận $A$, tức là $T(\alpha)=\alpha A$.

Vấn đề mà tương tự ma trận xét đến là: cùng một biến đổi tuyến tính $T$, khi mô tả trong không gian $V$ với cơ sở $\beta$ thì có ma trận $B$, còn khi mô tả trong không gian $V$ với cơ sở $\alpha$ thì có ma trận $A$.

Nếu ma trận chuyển cơ sở là $C$, tức $\beta=\alpha C$, thì hai mô tả $B$ và $A$ liên hệ với nhau như thế nào?

Vì cùng xét một biến đổi $T$, quan hệ ma trận chuyển cơ sở trước và sau biến đổi luôn được giữ nguyên, tức là:

$$
T(\beta)=T(\alpha)C=\alpha AC
$$

Biến đổi tuyến tính $T$ nhìn từ cơ sở $\beta$ vẫn là nhân bên phải; chuyển cơ sở $\beta$ về cơ sở $\alpha$ rồi nhân bên phải với $C$, quan hệ ma trận chuyển cơ sở $C$ được giữ nguyên trước và sau biến đổi:

$$
T(\beta)=\beta B=\alpha CB
$$

Từ đó bài toán được giải:

$$
B=C^{-1}AC
$$

Định lý: Nếu trong $L(V)$ có biến đổi $T$, thì các ma trận của $T$ theo những cơ sở khác nhau là **tương tự**.

Với hai ma trận vuông $A$ và $B$, nếu tồn tại ma trận khả nghịch $C$ sao cho $B=C^{-1}AC$, thì $A$ và $B$ tương tự.

Tương tự ma trận bảo toàn hạng, nên từ hai ma trận tương tự có thể suy ra hai ma trận tương đương. Tuy nhiên, hai ma trận tương đương không nhất thiết tương tự.

Vì tương tự ma trận liên quan chặt chẽ đến hình dạng của ma trận, nên tương tự ma trận không liên quan đến tính tương đương của hệ vectơ hay việc các hệ phương trình có cùng nghiệm.

Nhìn lại, cách giải thích tương tự ma trận chính là 4 đẳng thức: $\beta=\alpha C$, $T(\alpha)=\alpha A$, $T(\beta)=\beta B$, $T(\beta)=T(\alpha)C$.

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

-   [Tuyển tập song ngữ chính thức: Bản chất của đại số tuyến tính - P13 09 - Đổi cơ sở](https://www.bilibili.com/video/BV1Ls411b7r2)
