Bài viết này giới thiệu các đặc trưng số của biến ngẫu nhiên như kỳ vọng và phương sai.

<span id="kỳ-vọng"></span>

## Kỳ vọng

<span id="định-nghĩa"></span>

### Định nghĩa

<span id="biến-ngẫu-nhiên-rời-rạc"></span>

#### Biến ngẫu nhiên rời rạc

Giả sử biến ngẫu nhiên rời rạc $X$ có phân phối xác suất $p_i = P\{ X = x_i \}$. Nếu chuỗi

$$
\sum x_i p_i
$$

hội tụ tuyệt đối, thì giá trị của nó được gọi là **kỳ vọng** của $X$, ký hiệu là $EX$.

<span id="biến-ngẫu-nhiên-liên-tục"></span>

#### Biến ngẫu nhiên liên tục

Giả sử biến ngẫu nhiên liên tục $X$ có hàm mật độ $f(x)$. Nếu tích phân

$$
\int_{\mathbb{R}} xf(x) \text{d} x
$$

hội tụ tuyệt đối, thì giá trị của nó được gọi là **kỳ vọng** của $X$, ký hiệu là $EX$.

<span id="định-nghĩa-thống-nhất"></span>

#### Định nghĩa thống nhất

Giả sử biến ngẫu nhiên $X$ có hàm phân phối $F(x)$. Nếu [tích phân Stieltjes](https://en.wikipedia.org/wiki/Riemann%E2%80%93Stieltjes_integral)

$$
\int_{\mathbb{R}} x \text{d} F(x)
$$

hội tụ tuyệt đối, thì giá trị của nó được gọi là **kỳ vọng** của $X$, ký hiệu là $EX$.

??? example "Ví dụ kỳ vọng không tồn tại"
    Xét biến ngẫu nhiên rời rạc $X$ có phân phối như sau:
    
    $$
    P\left\{ X = (-1)^k \frac{2^k}{k} \right\} = \frac{1}{2^k}, \quad k = 1, 2, \cdots
    $$
    
    Tuy chuỗi $\sum x_i p_i$ hội tụ đến $- \ln 2$, nhưng vì nó không hội tụ tuyệt đối nên kỳ vọng của $X$ không tồn tại.
    
    Tiếp theo, xét biến ngẫu nhiên liên tục $Y$ có hàm mật độ như sau:
    
    $$
    f(y) = \frac{1}{\pi} \cdot \frac{1}{1 + y^2}, \quad y \in (-\infty, +\infty)
    $$
    
    Có thể kiểm chứng rằng kỳ vọng của $Y$ cũng không tồn tại.

<span id="tính-chất-của-kỳ-vọng"></span>

### Tính chất của kỳ vọng

<span id="tính-tuyến-tính"></span>

#### Tính tuyến tính

Nếu kỳ vọng của các biến ngẫu nhiên $X, Y$ tồn tại, thì:

-   Với mọi số thực $a, b$, có $E(aX + b) = a \cdot EX + b$.
-   $E(X + Y) = EX + EY$.

<span id="kỳ-vọng-của-tích-các-biến-ngẫu-nhiên"></span>

#### Kỳ vọng của tích các biến ngẫu nhiên

Nếu kỳ vọng của các biến ngẫu nhiên $X$, $Y$ tồn tại và $X$, $Y$ độc lập với nhau, thì:

$$
E(XY) = EX \cdot EY
$$

Lưu ý: tính độc lập trong tính chất trên **không phải** là điều kiện cần.

??? example "Phản ví dụ"
    Xét các biến ngẫu nhiên $X$ và $Y$, trong đó $X$ tuân theo phân phối đều trên $[-1, 1]$, còn $Y = X^2$.

<span id="chuyển-đổi-giữa-kỳ-vọng-và-xác-suất"></span>

### Chuyển đổi giữa kỳ vọng và xác suất

Với biến cố ngẫu nhiên $A$, xét hàm chỉ báo $I_A$ của nó:

$$
I_A(\omega) = \begin{cases}
    1, & \omega \in A \\
    0, & \omega \notin A
\end{cases}
$$

Theo định nghĩa, kỳ vọng của nó là $EI_A = P(A)$. Phép chuyển đổi này rất thường gặp trong ứng dụng thực tế.

??? example "Ví dụ"
    Giả sử với một dãy độ dài $n$, $\{ a_i \}$, trong đó $a_k$ nhận giá trị $k$ với xác suất $p_k$ và nhận giá trị $0$ với xác suất $1 - p_k$. Xét cách tính kỳ vọng của $S = \sum_{i=1}^{n} a_i$.
    
    Nếu tính trực tiếp theo định nghĩa, cần tìm xác suất để $S$ nhận từng giá trị có thể; quá trình tính toán này khá rườm rà nên phần chi tiết được lược bỏ.
    
    Mặt khác, dùng $I_k$ để biểu thị hàm chỉ báo của biến cố ngẫu nhiên $a_k = k$, có:
    
    $$
    S = \sum_{k=1}^{n} k \cdot I_k
    $$
    
    Từ đó suy ra:
    
    $$
    ES = E \left( \sum_{k=1}^{n} k \cdot I_k \right) = \sum_{k=1}^{n} k \cdot E[I_k] = \sum_{k=1}^{n} k \cdot p_k
    $$

<span id="phân-phối-có-điều-kiện-và-kỳ-vọng-có-điều-kiện"></span>

## Phân phối có điều kiện và kỳ vọng có điều kiện

Sau khi đã xét xác suất có điều kiện, có thể định nghĩa tương tự cho kỳ vọng có điều kiện.

<span id="định-nghĩa_1"></span>

### Định nghĩa

Với hai biến ngẫu nhiên $X$, $Y$, khi đã biết $Y = y$, phân phối của $X$ được gọi là **phân phối có điều kiện**. Trong trường hợp rời rạc, nếu $P(Y = y) > 0$, ký hiệu thường dùng là:

$$
P( X = x_i | Y = y )
$$

Trong trường hợp liên tục, khái niệm tương ứng được mô tả bằng **mật độ có điều kiện** $f_{X|Y}(x|y)$ khi mật độ này tồn tại. Kỳ vọng của $X$ theo phân phối có điều kiện đó được gọi là **kỳ vọng có điều kiện**, ký hiệu là $E[X|Y=y]$.

<span id="tính-chất-của-kỳ-vọng-có-điều-kiện"></span>

### Tính chất của kỳ vọng có điều kiện

Nhiều tính chất của kỳ vọng có điều kiện có thể suy ra từ xác suất có điều kiện, nên phần này không trình bày thêm.

Điều đáng nói là $E[X | Y]$ nói chung là một hàm của biến ngẫu nhiên $Y$, và hàm này thường không tuyến tính. Tuy nhiên, luôn có:

$$
E[E[X|Y]] = EX
$$

Công thức trên được gọi là **công thức kỳ vọng toàn phần**.

<span id="ứng-dụng"></span>

### Ứng dụng

???+ example "[HDU 5984 Pocky](https://acm.hdu.edu.cn/showproblem.php?pid=5984)"
    Có một thanh Pocky dài $L$, mỗi lần được bẻ ngẫu nhiên thành hai đoạn. Nếu đoạn bên phải có độ dài không lớn hơn $d$ thì dừng lại; ngược lại, lặp lại quá trình trên với đoạn bên phải. Tính kỳ vọng của số lần lặp.

??? note "Lời giải"
    Gọi $f(x)$ là kỳ vọng số lần lặp khi độ dài là $x$. Với $x \leq d$, quá trình luôn dừng sau lần bẻ đầu tiên nên $f(x) = 1$.
    
    Khi $x > d$, giả sử vị trí bẻ cách đầu bên phải một đoạn dài $k$; khi đó $k \sim U[0, x]$. Lúc này kỳ vọng của số lần lặp là:
    
    $$
    g(k) = \begin{cases}
        1, & k \leq d \\
        1 + f(k), & k > d
    \end{cases}
    $$
    
    Theo công thức kỳ vọng toàn phần, có:
    
    $$
    f(x) = Eg(k) = 1 + \frac{1}{x} \cdot \int_{d}^{x} f(t) \text{d} t
    $$
    
    Giải phương trình tích phân trên và thay điều kiện ban đầu vào, thu được:
    
    $$
    f(x) = 1 + \ln \frac{x}{d}
    $$

<span id="phương-sai"></span>

## Phương sai

<span id="định-nghĩa_2"></span>

### Định nghĩa

Giả sử kỳ vọng $EX$ của biến ngẫu nhiên $X$ tồn tại và kỳ vọng

$$
E(X - EX)^2
$$

cũng tồn tại. Khi đó giá trị của biểu thức trên được gọi là **phương sai** của biến ngẫu nhiên $X$, ký hiệu là $DX$ hoặc $Var(X)$. Căn bậc hai số học của phương sai được gọi là **độ lệch chuẩn**, ký hiệu là $\sigma(X) = \sqrt{DX}$.

<span id="tính-chất-của-phương-sai"></span>

### Tính chất của phương sai

Nếu phương sai của biến ngẫu nhiên $X$ tồn tại, thì:

-   Với mọi hằng số $a, b$, có $D(aX + b) = a^2 \cdot DX$.
-   $DX = E(X^2) - (EX)^2$.

<span id="hiệp-phương-sai-và-hệ-số-tương-quan"></span>

## Hiệp phương sai và hệ số tương quan

Nói chung, đẳng thức $D(X + Y) = DX + DY$ không đúng. Từ đó xuất hiện hai câu hỏi:

-   Phần chênh lệch giữa $D(X + Y)$ và $DX + DY$ rốt cuộc là gì?
-   Trong trường hợp nào thì $D(X + Y)$ bằng $DX + DY$?

Với câu hỏi thứ nhất, hiệp phương sai cho biết phần chênh lệch này.

<span id="định-nghĩa-hiệp-phương-sai"></span>

### Định nghĩa hiệp phương sai

Với các biến ngẫu nhiên $X, Y$, biểu thức

$$
E((X - EX)(Y - EY))
$$

được gọi là **hiệp phương sai** của $X$ và $Y$, ký hiệu là $\operatorname{Cov}(X, Y)$.

<span id="tính-chất-của-hiệp-phương-sai"></span>

### Tính chất của hiệp phương sai

Với các biến ngẫu nhiên $X, Y, Z$, có:

-   $\operatorname{Cov}(X, Y) = \operatorname{Cov}(Y, X)$.
-   Với mọi hằng số $a, b$, có $\operatorname{Cov}(aX + bY, Z) = a \cdot \operatorname{Cov}(X, Z) + b \cdot \operatorname{Cov}(Y, Z)$.

Đồng thời, hiệp phương sai và phương sai cũng có các liên hệ sau:

-   $DX = \operatorname{Cov}(X, X)$.
-   $D(X + Y) = DX + 2 \operatorname{Cov}(X, Y) + DY$.

??? note "Về hiệp phương sai"
    Các tính chất của hiệp phương sai có hình thức rất giống với các tính chất phép toán của tích vô hướng giữa các vectơ.
    
    Dưới góc nhìn của giải tích hàm, với một không gian xác suất cho trước, các biến ngẫu nhiên có mô men bậc hai hữu hạn tạo thành một không gian tuyến tính; hiệp phương sai là tích vô hướng trên không gian các biến đã quy tâm, hoặc tương đương trên không gian thương theo các biến hằng hầu chắc. Độ lệch chuẩn là chuẩn tương ứng.

Với câu hỏi thứ hai đã nêu ở trên, $D(X + Y) = DX + DY$ khi và chỉ khi $\operatorname{Cov}(X, Y) = 0$. Một điều kiện đủ trực quan là $X$ và $Y$ độc lập, vì khi đó:

$$
\operatorname{Cov}(X, Y) = E((X - EX)(Y - EY)) = E(X - EX) E(Y - EY) = 0
$$

Nhưng điều kiện này không cần thiết. Để mô tả quan hệ giữa các biến ngẫu nhiên $X$, $Y$ thỏa mãn $\operatorname{Cov}(X, Y) = 0$, dùng hệ số tương quan.

<span id="hệ-số-tương-quan"></span>

### Hệ số tương quan

Với các biến ngẫu nhiên $X, Y$ có $\sigma(X) > 0$ và $\sigma(Y) > 0$, biểu thức

$$
\frac{ \operatorname{Cov}(X, Y)}{ \sigma(X)\sigma(Y) }
$$

được gọi là **hệ số tương quan Pearson** của $X$ và $Y$, ký hiệu là $\rho_{X,Y}$.

Hệ số tương quan Pearson mô tả mức độ chặt chẽ của liên hệ tuyến tính giữa hai biến ngẫu nhiên. $|\rho_{X,Y}|$ càng lớn thì mức độ liên hệ tuyến tính giữa $X$ và $Y$ càng mạnh. Từ bất đẳng thức Cauchy-Schwarz suy ra $|\rho_{X,Y}| \leq 1$, và $|\rho_{X,Y}| = 1$ chỉ có thể xuất hiện trong hai trường hợp sau:

-   Khi tồn tại số thực $a$ và số thực dương $b$ sao cho $P(X = a + bY) = 1$, có $\rho_{X,Y} = 1$.
-   Khi tồn tại số thực $a$ và số thực âm $b$ sao cho $P(X = a + bY) = 1$, có $\rho_{X,Y} = -1$.

Khi $\rho_{X,Y} = 0$, các biến ngẫu nhiên $X$ và $Y$ được gọi là **không tương quan**; khi đó giữa $X$ và $Y$ không có tương quan tuyến tính theo nghĩa hiệp phương sai.

??? note "\"Không tương quan\" và \"độc lập\""
    Hai biến ngẫu nhiên không tương quan chỉ cho thấy giữa chúng không có liên hệ tuyến tính, chứ không có nghĩa là không có liên hệ dưới những hình thức khác.
    
    Khi các kỳ vọng liên quan tồn tại, độc lập suy ra không tương quan; chiều ngược lại không đúng.

Với câu hỏi thứ hai được nêu ở đầu tiểu mục này, kết luận là $D(X + Y) = DX + DY$ khi và chỉ khi $\operatorname{Cov}(X, Y) = 0$. Nếu $\sigma(X) > 0$ và $\sigma(Y) > 0$, điều kiện này tương đương với $\rho_{X,Y} = 0$; nếu một trong hai biến là hằng hầu chắc thì hiệp phương sai bằng $0$, nhưng hệ số tương quan Pearson không xác định.
