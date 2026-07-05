Bài này giới thiệu các phép toán đơn giản giữa các vectơ.

Trước khi vào bài, cần nói rõ một vấn đề về thuật ngữ dịch. Vì lý do lịch sử, trong toán học và vật lý, các thuật ngữ "inner product" và "outer product" có nhiều cách dịch khác nhau.

Trong vật lý, thường dùng cách gọi nhấn mạnh kết quả của phép toán là vô hướng hay vectơ. Sách toán phổ thông cũng thường dùng cách dịch theo nghĩa này, chẳng hạn "tích vô hướng" và "tích có hướng".

Trong toán học, hai thuật ngữ này cũng có thể dịch trực tiếp là "tích trong" và "tích ngoài". "Tích chấm" và "tích chéo" là cách gọi thông dụng dựa trên ký hiệu phép toán.

Trong phép "tích chấm", dấu chấm của phép toán thường được lược bỏ; trong đại số tuyến tính, nó còn thường được xem trực tiếp như phép nhân ma trận và không viết dấu chấm.

<span id="tích-trong"></span>
## Tích trong

Khái niệm tích trong **áp dụng cho vectơ ở mọi số chiều**.

<span id="định-nghĩa"></span>
### Định nghĩa

Tích trong có nhiều cách định nghĩa khác nhau nhưng tương đương. Dưới đây giới thiệu một vài cách.

<span id="định-nghĩa-hình-học"></span>
#### Định nghĩa hình học

Trong không gian Euclid $n$ chiều $\mathbf{R}^n$, cho hai vectơ $\boldsymbol{a}, \boldsymbol{b}$, góc giữa chúng là $\theta$, khi đó:

$$
\boldsymbol{a} \cdot \boldsymbol{b} = |\boldsymbol{a}| |\boldsymbol{b}| \cos \theta
$$

được gọi là **tích trong** của hai vectơ này, cũng gọi là **tích chấm** hoặc **tích vô hướng**. Trong đó $|\boldsymbol{b}|\cos \theta$ được gọi là hình chiếu của $\boldsymbol{b}$ lên hướng của $\boldsymbol{a}$. Ý nghĩa hình học của tích trong là: tích trong $\boldsymbol{a} \cdot \boldsymbol{b}$ bằng tích giữa độ dài của $\boldsymbol{a}$ và hình chiếu của $\boldsymbol{b}$ lên hướng của $\boldsymbol{a}$.

<span id="định-nghĩa-đại-số"></span>
#### Định nghĩa đại số

Trong không gian Euclid $n$ chiều $\mathbf{R}^n$, cho hai vectơ $\boldsymbol{a} = (a_1, a_2, \dots, a_n), \boldsymbol{b} = (b_1, b_2, \dots, b_n)$, khi đó:

$$
\boldsymbol{a} \cdot \boldsymbol{b} = \sum_{i = 1}^{n} a_i b_i
$$

được gọi là **tích trong** của hai vectơ này, cũng gọi là **tích chấm** hoặc **tích vô hướng**. Định nghĩa hình học và định nghĩa đại số của tích trong là tương đương trong không gian Euclid, còn định nghĩa đại số thuận tiện hơn khi sử dụng.

Khi không gây nhầm lẫn, dấu chấm của tích trong có thể được lược bỏ. Nếu ở góc trên bên phải của vectơ có số mũ $2$, đó là cách viết tắt của tích trong của vectơ với chính nó, tức **bình phương độ dài vectơ**, lược bỏ ký hiệu độ dài. Số mũ $2$ này không được hiểu là bình phương vectơ, vì kết quả của tích trong vectơ là một vô hướng, và không tồn tại tích trong của số lượng vectơ khác $2$. Tương tự, bình phương của bình phương độ dài vectơ không thể viết tắt bằng số mũ $4$, mà phải xem kết quả mang số mũ $2$ là một chỉnh thể rồi tiếp tục xử lý.

<span id="tính-chất"></span>
### Tính chất

Có thể thấy kết quả của tích trong là một vô hướng. Điểm đặc biệt của nó là phép toán song tuyến tính theo từng vectơ. Cụ thể, tích trong thỏa:

$$
\begin{aligned}
(\boldsymbol{a} + \boldsymbol{b}) \cdot \boldsymbol{c} &= \boldsymbol{a} \cdot \boldsymbol{c} + \boldsymbol{b} \cdot \boldsymbol{c} \\
\boldsymbol{a} \cdot (\boldsymbol{b} + \boldsymbol{c}) &= \boldsymbol{a} \cdot \boldsymbol{b} + \boldsymbol{a} \cdot \boldsymbol{c} \\
(\lambda \boldsymbol{a}) \cdot \boldsymbol{b} &= \lambda (\boldsymbol{a} \cdot \boldsymbol{b}) \\
\boldsymbol{a} \cdot (\lambda \boldsymbol{b}) &= \lambda (\boldsymbol{a} \cdot \boldsymbol{b})
\end{aligned}
$$

Tích trong còn thỏa tính giao hoán:

$$
\boldsymbol{a} \cdot \boldsymbol{b} = \boldsymbol{b} \cdot \boldsymbol{a}
$$

<span id="ứng-dụng"></span>
### Ứng dụng

Dưới đây giới thiệu một số ứng dụng thường gặp của phép tích trong.

1.  Kiểm tra hai vectơ vuông góc:

    $$
    \boldsymbol{a} \perp \boldsymbol{b} \iff \boldsymbol{a} \cdot \boldsymbol{b} = 0
    $$

    Tức là tích trong của hai vectơ vuông góc bằng $0$; tích trong của một vectơ với vectơ không cũng bằng $0$. Nếu dùng tích trong bằng không làm định nghĩa của vuông góc, thì có thể suy ra vectơ không vuông góc với mọi vectơ.

2.  Kiểm tra hai vectơ cùng phương:

    $$
    \exists\lambda \in \mathbf{R} (\boldsymbol{a} = \lambda \boldsymbol{b}) \iff |\boldsymbol{a} \cdot \boldsymbol{b}| = |\boldsymbol{a}| |\boldsymbol{b}|
    $$

3.  Tính độ dài vectơ:

    $$
    |\boldsymbol a| = \sqrt{\boldsymbol{a} \cdot \boldsymbol{a}}
    $$

4.  Tính góc giữa hai vectơ:

    $$
    \theta = \arccos \frac{\boldsymbol{a} \cdot \boldsymbol{b}}{|\boldsymbol a| |\boldsymbol b|}
    $$

<span id="định-thức-bậc-hai-và-bậc-ba"></span>
## Định thức bậc hai và bậc ba

Định thức bậc hai và bậc ba có thể được định nghĩa riêng như những trường hợp đơn giản hơn của định thức. Trong phần cuối của giải tích về trường vectơ, công thức Green dùng định thức bậc hai, công thức Gauss dùng tích chấm, và công thức Stokes dùng định thức bậc ba.

Định thức bậc hai có thể xem là một hàm bốn biến, được định nghĩa là:

$$
\begin{vmatrix}
    a & b \\
    c & d
\end{vmatrix}=ad-bc
$$

Định thức bậc ba có thể xem là một hàm chín biến, được định nghĩa là:

$$
\begin{vmatrix}
    a & b & c \\
    d & e & f \\
    g & h & i
\end{vmatrix}=aei+dhc+gbf-ahf-dbi-gec
$$

Một cách ghi nhớ đặc biệt là dùng "quy tắc đường chéo"; quy tắc này chỉ áp dụng cho định thức bậc hai và bậc ba.

Cần đặc biệt chú ý: định thức bậc bốn khi khai triển có tổng cộng 24 hạng tử, và hạng tử theo đường chéo phụ có dấu dương. Nếu cố áp dụng "quy tắc đường chéo" của định thức bậc ba, không chỉ thiếu hạng tử mà dấu của hạng tử theo đường chéo phụ cũng sai. Vì vậy, "quy tắc đường chéo" của định thức bậc ba không áp dụng cho định thức bậc cao hơn, và định thức bậc cao hơn cũng không thích hợp để tính bằng cách khai triển trực tiếp.

<span id="tích-ngoài"></span>
## Tích ngoài

Tích ngoài là phép toán **riêng của vectơ ba chiều**.

Trong vật lý, vectơ ba chiều mặc định là vectơ liên quan đến vị trí trong không gian và đều được biểu diễn bằng chữ đậm. Tuy nhiên, vectơ bốn chiều liên quan đến thuyết tương đối trong vật lý không dùng chữ đậm, mà dùng ký hiệu và chỉ số đặc biệt.

Trong đại số tuyến tính, mọi vectơ đều được biểu diễn bằng chữ đậm; hơn nữa vì khá phiền, và trong đại số tuyến tính phần lớn là phép toán giữa vectơ và ma trận nên khó gây nhầm lẫn, khi viết tay có thể lược bỏ ký hiệu vectơ.

<span id="định-nghĩa_1"></span>
### Định nghĩa

Tích ngoài có nhiều cách định nghĩa khác nhau nhưng tương đương. Dưới đây giới thiệu một vài cách.

<span id="định-nghĩa-hình-học_1"></span>
#### Định nghĩa hình học

Trong không gian Euclid ba chiều $\mathbf{R}^3$, định nghĩa tích ngoài của hai vectơ $\boldsymbol{a}, \boldsymbol{b}$ là một vectơ, ký hiệu $\boldsymbol{a} \times \boldsymbol{b}$, có độ dài và hướng được định nghĩa như sau:

1.  $|\boldsymbol{a} \times \boldsymbol{b}| = |\boldsymbol{a}| |\boldsymbol{b}| \sin \langle \boldsymbol{a}, \boldsymbol{b} \rangle$;
2.  $\boldsymbol{a} \times \boldsymbol{b}$ vuông góc với cả $\boldsymbol{a}, \boldsymbol{b}$, và hướng của $\boldsymbol{a}, \boldsymbol{b}, \boldsymbol{a} \times \boldsymbol{b}$ tuân theo quy tắc bàn tay phải.

Nhìn vào độ dài của tích ngoài và liên hệ với công thức diện tích tam giác $S=\frac{1}{2}ab\sin C$, ta thấy ý nghĩa hình học của tích ngoài là: **$|\boldsymbol{a} \times \boldsymbol{b}|$ là diện tích hình bình hành có $\boldsymbol{a}, \boldsymbol{b}$ làm hai cạnh kề**.

<span id="định-nghĩa-đại-số_1"></span>
#### Định nghĩa đại số

Trong không gian Euclid ba chiều $\mathbf{R}^3$, định nghĩa tích ngoài của hai vectơ $\boldsymbol{a} = (x_1, y_1, z_1), \boldsymbol{b} = (x_2, y_2, z_2)$ là một vectơ $\boldsymbol{c}$, ký hiệu $\boldsymbol{c} = \boldsymbol{a} \times \boldsymbol{b}$. Kết quả của nó có thể biểu diễn bằng định thức bậc ba:

$$
\begin{vmatrix}
    \boldsymbol{i} & \boldsymbol{j} & \boldsymbol{k} \\
    x_1 & y_1 & z_1  \\
    x_2 & y_2 & z_2
\end{vmatrix}
$$

Trong đó $\boldsymbol{i}, \boldsymbol{j}, \boldsymbol{k}$ biểu thị các vectơ đơn vị hướng theo các trục tọa độ $x, y, z$, và được viết ở vị trí tọa độ tương ứng. Khai triển được

$$
\begin{aligned}
\boldsymbol{c} &= \boldsymbol{a} \times \boldsymbol{b} \\
&= (y_1z_2 - y_2z_1)\boldsymbol{i} + (z_1x_2 - z_2x_1)\boldsymbol{j} + (x_1y_2 - x_2y_1)\boldsymbol{k} \\
&= (y_1z_2 - y_2z_1, z_1x_2 - z_2x_1, x_1y_2 - x_2y_1)
\end{aligned}
$$

<span id="tính-chất_1"></span>
### Tính chất

1.  Tích ngoài là phép toán song tuyến tính theo từng vectơ. Cụ thể, tích ngoài thỏa:

    $$
    \begin{aligned}
    (\boldsymbol{a} + \boldsymbol{b}) \times \boldsymbol{c} &= \boldsymbol{a} \times \boldsymbol{c} + \boldsymbol{b} \times \boldsymbol{c} \\
    \boldsymbol{a} \times (\boldsymbol{b} + \boldsymbol{c}) &= \boldsymbol{a} \times \boldsymbol{b} + \boldsymbol{a} \times \boldsymbol{c} \\
    (\lambda \boldsymbol{a}) \times \boldsymbol{b} &= \lambda (\boldsymbol{a} \times \boldsymbol{b}) \\
    \boldsymbol{a} \times (\lambda \boldsymbol{b}) &= \lambda (\boldsymbol{a} \times \boldsymbol{b})
    \end{aligned}
    $$

    Hai dòng tính chất đầu cũng có thể gọi là luật phân phối, tức tích ngoài phân phối đối với phép cộng vectơ.

2.  Tích ngoài thỏa tính phản giao hoán:

    $$
    \boldsymbol a \times \boldsymbol b=-\boldsymbol b \times \boldsymbol a
    $$

3.  Theo định nghĩa hình học của tích trong và tích ngoài ở trên:

    $$
    \begin{aligned}
    |\boldsymbol a \times \boldsymbol b| &= |\boldsymbol a| |\boldsymbol b| \sin \langle \boldsymbol a, \boldsymbol b \rangle \\
    \boldsymbol a \cdot \boldsymbol b &= |\boldsymbol a| |\boldsymbol b| \cos \theta \\
    &= |\boldsymbol a| |\boldsymbol b| \cos \langle \boldsymbol a, \boldsymbol b\rangle
    \end{aligned}
    $$

    Có thể viết ra hằng đẳng thức:

    $$
    (\boldsymbol a\times \boldsymbol b) \cdot (\boldsymbol a\times \boldsymbol b) = |\boldsymbol a|^2 |\boldsymbol b|^2-{(\boldsymbol a \cdot \boldsymbol b)}^2
    $$

4.  Tích ngoài thỏa đẳng thức Jacobi:

    $$
    \boldsymbol a \times (\boldsymbol b \times \boldsymbol c) + \boldsymbol b \times (\boldsymbol c \times \boldsymbol a) + \boldsymbol c \times (\boldsymbol a \times \boldsymbol b) = \boldsymbol 0
    $$

<span id="ứng-dụng_1"></span>
### Ứng dụng

Dưới đây giới thiệu một số ứng dụng thường gặp của phép tích ngoài.

1.  Kiểm tra hai vectơ có cùng phương hay không:

    $$
    \exists\lambda \in \mathbf{R} (\boldsymbol{a} = \lambda \boldsymbol{b}) \iff \boldsymbol{a} \times \boldsymbol{b} = \boldsymbol{0}
    $$

    Tức là tích ngoài của hai vectơ ba chiều cùng phương bằng $\boldsymbol 0$; tích ngoài của một vectơ ba chiều với chính nó bằng $\boldsymbol 0$; tích ngoài của một vectơ ba chiều với vectơ không bằng $\boldsymbol 0$. Nếu dùng tích ngoài bằng không làm định nghĩa hai vectơ cùng phương, thì có thể suy ra vectơ không cùng phương với mọi vectơ.

2.  Tính diện tích hình bình hành căng bởi hai vectơ:

    $$
    S \langle \boldsymbol a, \boldsymbol b \rangle = |\boldsymbol a \times \boldsymbol b|
    $$

<span id="trường-hợp-vectơ-hai-chiều"></span>
#### Trường hợp vectơ hai chiều

Với vectơ hai chiều, không thể tính tích ngoài, nhưng vẫn có thể tính diện tích hình bình hành căng bởi hai vectơ:

Ký hiệu $\boldsymbol{a} = (m, n), \boldsymbol{b} = (p, q)$. Mở rộng hệ tọa độ Descartes phẳng thành hệ tọa độ Descartes trong không gian; mặt phẳng ban đầu nằm trên mặt phẳng $xOy$ của hệ tọa độ mới, các tọa độ ban đầu $(m, n)$ và $(p, q)$ trở thành $(m, n, 0)$ và $(p, q, 0)$.

Khi đó tích ngoài của hai vectơ là $(0, 0, mq - np)$, nên diện tích hình bình hành là $|mq - np|$, có thể xem là giá trị tuyệt đối của kết quả phép tính định thức bậc hai.

Lúc này, theo quy tắc bàn tay phải và dấu của tọa độ $z$, có thể suy ra hướng của $\boldsymbol b$ so với $\boldsymbol a$: nếu theo chiều ngược kim đồng hồ thì tọa độ $z$ dương, ngược lại là âm. Có thể ghi nhớ ngắn gọn là **thuận âm, nghịch dương**.

<span id="tích-hỗn-hợp"></span>
## Tích hỗn hợp

Giống như tích ngoài, tích hỗn hợp của vectơ là phép toán **riêng của vectơ ba chiều**.

<span id="định-nghĩa_2"></span>
### Định nghĩa

Giả sử $\boldsymbol a, \boldsymbol b, \boldsymbol c$ là ba vectơ trong không gian ba chiều. Khi đó $(\boldsymbol a \times \boldsymbol b) \cdot \boldsymbol c$ được gọi là tích hỗn hợp của ba vectơ $\boldsymbol a, \boldsymbol b, \boldsymbol c$, ký hiệu là $[\boldsymbol a \boldsymbol b \boldsymbol c]$ hoặc $(\boldsymbol a, \boldsymbol b, \boldsymbol c)$ hoặc $(\boldsymbol a \boldsymbol b \boldsymbol c)$ hoặc $\det(\boldsymbol a, \boldsymbol b, \boldsymbol c)$. Ý nghĩa hình học của giá trị tuyệt đối $|(\boldsymbol a \times \boldsymbol b) \cdot \boldsymbol c|$ của tích hỗn hợp là thể tích hình hộp song song có $\boldsymbol a, \boldsymbol b, \boldsymbol c$ làm các cạnh.

Tích hỗn hợp của vectơ có thể biểu diễn bằng định thức bậc ba:

$$
\begin{aligned}
(\boldsymbol a \times \boldsymbol b) \cdot \boldsymbol c &= \det(\boldsymbol a, \boldsymbol b, \boldsymbol c) \\
&= \begin{vmatrix}
    a_x & b_x & c_x \\
    a_y & b_y & c_y \\
    a_z & b_z & c_z
\end{vmatrix} \\
&= a_x b_y c_z + a_y b_z c_x + a_z b_x c_y - a_z b_y c_x -a _y b_x c_z - a_x b_z c_y
\end{aligned}
$$

<span id="tính-chất_2"></span>
### Tính chất

1.  Tích hỗn hợp tuyến tính theo từng vectơ. Cụ thể, có:

    $$
    \begin{aligned}
    \det(\lambda\boldsymbol{u} + \mu\boldsymbol{v}, \boldsymbol{b}, \boldsymbol{c}) &= \lambda\det(\boldsymbol{u}, \boldsymbol{b}, \boldsymbol{c}) + \mu\det(\boldsymbol{v}, \boldsymbol{b}, \boldsymbol{c}) \\
    \det(\boldsymbol{a}, \lambda\boldsymbol{u} + \mu\boldsymbol{v}, \boldsymbol{c}) &= \lambda\det(\boldsymbol{a}, \boldsymbol{u}, \boldsymbol{c}) + \mu\det(\boldsymbol{a}, \boldsymbol{v}, \boldsymbol{c}) \\
    \det(\boldsymbol{a}, \boldsymbol{b}, \lambda\boldsymbol{u} + \mu\boldsymbol{v}) &= \lambda\det(\boldsymbol{a}, \boldsymbol{b}, \boldsymbol{u}) + \mu\det(\boldsymbol{a}, \boldsymbol{b}, \boldsymbol{v})
    \end{aligned}
    $$

2.  Tích hỗn hợp có tính phản đối xứng: đổi chỗ hai vectơ sẽ biến tích hỗn hợp thành số đối của nó. Do đó có:

    $$
    \det(\boldsymbol a, \boldsymbol b, \boldsymbol c) = \det(\boldsymbol b, \boldsymbol c, \boldsymbol a) = \det(\boldsymbol c, \boldsymbol a, \boldsymbol b) = -\det(\boldsymbol b, \boldsymbol a, \boldsymbol c) = -\det(\boldsymbol a, \boldsymbol c, \boldsymbol b)= -\det(\boldsymbol c, \boldsymbol b, \boldsymbol a)
    $$

    Từ đó còn có thể thu được quan hệ sau giữa tích trong và tích ngoài:

    $$
    (\boldsymbol a \times \boldsymbol b) \cdot \boldsymbol c = \boldsymbol a \cdot (\boldsymbol b \times \boldsymbol c)
    $$

<span id="ứng-dụng_2"></span>
### Ứng dụng

Tích hỗn hợp của vectơ có các ứng dụng thường gặp sau.

1.  Tính thể tích tứ diện $ABCD$:

    $$
    V=\frac{1}{6}\left|\det(\overrightarrow{AB}, \overrightarrow{AC}, \overrightarrow{AD})\right|
    $$

2.  Kiểm tra $\boldsymbol a, \boldsymbol b, \boldsymbol c$ có đồng phẳng hay không;

    Điều kiện cần và đủ để ba vectơ ba chiều $\boldsymbol a, \boldsymbol b, \boldsymbol c$ đồng phẳng là $\det(\boldsymbol a, \boldsymbol b, \boldsymbol c)=0$.

3.  Xác định tính thuận tay của hệ tọa độ do $\boldsymbol a, \boldsymbol b, \boldsymbol c$ tạo thành;

    Dấu của tích hỗn hợp $\det(\boldsymbol a, \boldsymbol b, \boldsymbol c)$ là dương hay âm phụ thuộc vào góc giữa $\boldsymbol a \times \boldsymbol b$ và $\boldsymbol c$ là góc nhọn hay góc tù, tức chúng hướng về cùng phía hay khác phía so với mặt phẳng căng bởi $\boldsymbol a$ và $\boldsymbol b$. Điều này tương đương với việc ba vectơ $\boldsymbol a, \boldsymbol b, \boldsymbol c$ theo thứ tự tạo thành hệ tay phải hay hệ tay trái. Cụ thể:

    -   $\det(\boldsymbol a, \boldsymbol b, \boldsymbol c) < 0$ tương đương với $\boldsymbol a, \boldsymbol b, \boldsymbol c$ theo thứ tự tạo thành hệ tay trái;
    -   $\det(\boldsymbol a, \boldsymbol b, \boldsymbol c) > 0$ tương đương với $\boldsymbol a, \boldsymbol b, \boldsymbol c$ theo thứ tự tạo thành hệ tay phải.

<span id="tích-ngoài-kép"></span>
## Tích ngoài kép

Tích hỗn hợp của vectơ ba chiều là sự kết hợp giữa tích trong và tích ngoài, có tính đối xứng luân phiên. Tích ngoài của hai vectơ ba chiều vẫn là một vectơ ba chiều, vậy tích ngoài của tích ngoài có kết luận liên quan nào không?

Trước hết chứng minh một bổ đề.

$$
(\boldsymbol a \times \boldsymbol b)\times \boldsymbol a = (\boldsymbol a \cdot \boldsymbol a) \boldsymbol b - (\boldsymbol a \cdot \boldsymbol b) \boldsymbol a
$$

Chứng minh: Theo quy tắc bàn tay phải, $\boldsymbol a \times \boldsymbol b$ vuông góc với cả $\boldsymbol a$ và $\boldsymbol b$. Vế trái của đẳng thức cần chứng minh vuông góc với $\boldsymbol a \times \boldsymbol b$, nên vế trái đồng phẳng với $\boldsymbol a$ và $\boldsymbol b$.

Do đó có thể giả sử:

$$
(\boldsymbol a \times \boldsymbol b)\times \boldsymbol a = \lambda \boldsymbol a + \mu \boldsymbol b
$$

Theo các kết luận liên quan đến tích hỗn hợp, lấy tích trong của hai vế với $\boldsymbol a$ và $\boldsymbol b$ lần lượt, ta có:

$$
\begin{aligned}
\lambda (\boldsymbol a \cdot \boldsymbol a)+\mu (\boldsymbol a \cdot \boldsymbol b) &= 0 \\
\lambda (\boldsymbol a \cdot \boldsymbol b) + \mu (\boldsymbol b \cdot \boldsymbol b) &= \det(\boldsymbol b, \boldsymbol a \times \boldsymbol b, \boldsymbol a) \\
&= (\boldsymbol a \times \boldsymbol b) \cdot (\boldsymbol a \times \boldsymbol b)
\end{aligned}
$$

Từ hằng đẳng thức đã suy ra ở trên:

$$
(\boldsymbol a \times \boldsymbol b) \cdot (\boldsymbol a \times \boldsymbol b) = |\boldsymbol a|^2|\boldsymbol b|^2-(\boldsymbol a \cdot \boldsymbol b)^2
$$

có thể giải được:

$$
\begin{aligned}
\lambda &= -\boldsymbol a \cdot \boldsymbol b \\
\mu &= \boldsymbol a \cdot \boldsymbol a
\end{aligned}
$$

Chứng minh xong.

Trong chứng minh trên đã nhắc rằng $\boldsymbol a \times \boldsymbol b$ tích chéo với một vectơ bất kỳ sẽ cho ra một vectơ đồng phẳng với $\boldsymbol a$ và $\boldsymbol b$. Tiếp theo chứng minh kết luận của **tích ngoài kép**:

$$
(\boldsymbol a\times \boldsymbol b)\times \boldsymbol c=(\boldsymbol a \cdot \boldsymbol c)\boldsymbol b - (\boldsymbol b \cdot \boldsymbol c)\boldsymbol a
$$

Tính đồng phẳng nói trên giúp ghi nhớ kết luận về tích ngoài kép. Có thể thấy bổ đề ở trên là trường hợp đặc biệt của tích ngoài kép.

Chứng minh: Ở đây chỉ cần xét trường hợp ba vectơ đều khác không và không cùng phương; các trường hợp đặc biệt khác là hiển nhiên.

Ba vectơ ba chiều $\boldsymbol a$, $\boldsymbol b$ và $\boldsymbol a \times \boldsymbol b$ không đồng phẳng, nên có thể giả sử:

$$
\boldsymbol c = \alpha \boldsymbol a + \beta \boldsymbol b + \gamma(\boldsymbol a \times \boldsymbol b)
$$

Do đó:

$$
\begin{aligned}
(\boldsymbol a \times \boldsymbol b) \times \boldsymbol c &= (\boldsymbol a \times \boldsymbol b) \times (\alpha \boldsymbol a + \beta \boldsymbol b + \gamma(\boldsymbol a \times \boldsymbol b)) \\
&= \alpha(\boldsymbol a \times \boldsymbol b) \times \boldsymbol a + \beta(\boldsymbol a \times \boldsymbol b) \times \boldsymbol b
\end{aligned}
$$

Theo bổ đề ở trên:

$$
\begin{aligned}
(\boldsymbol a \times \boldsymbol b) \times \boldsymbol a &=(\boldsymbol a \cdot \boldsymbol a) \boldsymbol b - (\boldsymbol a \cdot \boldsymbol b) \boldsymbol a \\
(\boldsymbol a \times \boldsymbol b) \times \boldsymbol b
&= -(\boldsymbol b \times \boldsymbol a) \times \boldsymbol b \\
&= -(\boldsymbol b \cdot \boldsymbol b)\boldsymbol a+(\boldsymbol a \cdot \boldsymbol b) \boldsymbol b
\end{aligned}
$$

Vì vậy:

$$
\begin{aligned}
(\boldsymbol a \times \boldsymbol b) \times \boldsymbol c &= \alpha((\boldsymbol a \cdot \boldsymbol a)\boldsymbol b - (\boldsymbol a \cdot \boldsymbol b)\boldsymbol a) + \beta((\boldsymbol a \cdot \boldsymbol b)\boldsymbol b - (\boldsymbol b \cdot \boldsymbol b)\boldsymbol a) \\
&=(\alpha(-\boldsymbol a \cdot \boldsymbol b) + \beta(-\boldsymbol b \cdot \boldsymbol b))\boldsymbol a + (\alpha \boldsymbol a \cdot \boldsymbol a + \beta \boldsymbol a \cdot \boldsymbol b)\boldsymbol b \\
&= (\boldsymbol a \cdot \boldsymbol c) \boldsymbol b - (\boldsymbol b \cdot \boldsymbol c) \boldsymbol a
\end{aligned}
$$

Chứng minh xong.

Theo tính phản giao hoán của tích ngoài, có thể thu được hai công thức của tích ngoài kép:

$$
\begin{aligned}
(\boldsymbol a\times \boldsymbol b)\times \boldsymbol c &=(\boldsymbol a \cdot \boldsymbol c)\boldsymbol b - (\boldsymbol b \cdot \boldsymbol c)\boldsymbol a \\
\boldsymbol a \times(\boldsymbol b \times \boldsymbol c) &= (\boldsymbol a \cdot \boldsymbol c)\boldsymbol b - (\boldsymbol a \cdot \boldsymbol b)\boldsymbol c
\end{aligned}
$$

Có thể thấy tích ngoài kép có yêu cầu rất nghiêm ngặt về thứ tự phép toán.

Nhờ tích hỗn hợp và tích ngoài kép, còn có thể chứng minh đẳng thức Lagrange.

$$
(\boldsymbol a \times \boldsymbol b) \cdot (\boldsymbol c \times \boldsymbol d)=(\boldsymbol a \cdot \boldsymbol c)(\boldsymbol b \cdot \boldsymbol d)-(\boldsymbol a \cdot \boldsymbol d)(\boldsymbol b \cdot \boldsymbol c)
$$

Chứng minh:

$$
\begin{aligned}
(\boldsymbol a \times \boldsymbol b) \cdot (\boldsymbol c \times \boldsymbol d) &= \det(\boldsymbol c, \boldsymbol d, \boldsymbol a \times \boldsymbol b) \\
&= \det(\boldsymbol a \times \boldsymbol b, \boldsymbol c, \boldsymbol d) \\
&= ((\boldsymbol a \times \boldsymbol b)\times \boldsymbol c)\cdot \boldsymbol d \\
&= (\boldsymbol b(\boldsymbol a \cdot \boldsymbol c)- \boldsymbol a(\boldsymbol b \cdot \boldsymbol c))\cdot \boldsymbol d \\
&= (\boldsymbol a \cdot \boldsymbol c)(\boldsymbol b \cdot \boldsymbol d) - (\boldsymbol a \cdot \boldsymbol d)(\boldsymbol b \cdot \boldsymbol c)
\end{aligned}
$$

Có thể thấy hằng đẳng thức ở trên

$$
(\boldsymbol a \times \boldsymbol b) \cdot (\boldsymbol a \times \boldsymbol b) = |\boldsymbol a|^2|\boldsymbol b|^2 - (\boldsymbol a \cdot \boldsymbol b)^2
$$

là một trường hợp đặc biệt của đẳng thức Lagrange.
