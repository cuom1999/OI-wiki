<span id="các-khái-niệm-liên-quan"></span>
## Các khái niệm liên quan

<span id="biến-ngẫu-nhiên"></span>
### Biến ngẫu nhiên

Cho không gian xác suất $(\Omega, \mathcal{F}, P)$. Nếu hàm $X : \Omega \to \mathbb{R}$ định nghĩa trên không gian mẫu $\Omega$ thỏa mãn: với mọi $t \in \mathbb{R}$ đều có

$$
\{ \omega \in \Omega : X(\omega) \le t \} \in \mathcal{F}
$$

thì $X$ được gọi là một **biến ngẫu nhiên**.

<span id="hàm-chỉ-báo"></span>
### Hàm chỉ báo

Với biến cố $A$ trên không gian mẫu $\Omega$, định nghĩa biến ngẫu nhiên

$$
I_A(\omega) = \begin{cases}
    1, & \omega \in A \\
    0, & \omega \notin A
\end{cases}
$$

Khi đó $I_A$ được gọi là **hàm chỉ báo** của biến cố $A$.

<span id="hàm-phân-phối"></span>
### Hàm phân phối

Với biến ngẫu nhiên $X$, hàm

$$
F(x) = P( X \leq x )
$$

được gọi là **hàm phân phối** của biến ngẫu nhiên $X$. Ký hiệu là $X \sim F(x)$.

Hàm phân phối có các tính chất sau:

-   **Liên tục phải**: $F(x) = F(x + 0)$
-   **Tính đơn điệu**: tăng đơn điệu trên $\mathbb{R}$ (không nhất thiết tăng nghiêm ngặt)
-   $F(-\infty) = 0$,$F(+\infty) = 1$

Đồng thời, có thể chứng minh rằng mọi hàm thỏa mãn các yêu cầu trên đều là hàm phân phối của một biến ngẫu nhiên nào đó. Vì vậy, hàm phân phối và biến ngẫu nhiên tương ứng một-một với nhau.

<span id="phân-loại-biến-ngẫu-nhiên"></span>
## Phân loại biến ngẫu nhiên

Theo việc miền giá trị của biến ngẫu nhiên (theo định nghĩa, biến ngẫu nhiên là một hàm) có đếm được hay không, biến ngẫu nhiên được chia thành hai loại: **rời rạc** và **liên tục**.

<span id="biến-ngẫu-nhiên-rời-rạc"></span>
### Biến ngẫu nhiên rời rạc

Giả sử $X$ là biến ngẫu nhiên rời rạc, mọi giá trị có thể nhận của nó là $x_1, x_2, \cdots$. Khi đó có thể dùng một dãy các đẳng thức dạng $P\{ X = x_i \} = p_i$ để mô tả $X$. Đây chính là **bảng phân phối** thường gặp trong sách giáo khoa phổ thông.

<span id="biến-ngẫu-nhiên-liên-tục"></span>
### Biến ngẫu nhiên liên tục

Giả sử $X$ là biến ngẫu nhiên liên tục. Việc xét $P\{ X = x \}$ thường không có nhiều ý nghĩa (vì xác suất này rất có thể bằng $0$).

??? note "Vì sao nói xác suất này rất có thể bằng $0$"
    Xét biến ngẫu nhiên $X$ như sau: nó nhận giá trị $0$ với xác suất $\frac{1}{2}$, và với xác suất $\frac{1}{2}$ thì tuân theo phân phối đều trên khoảng mở $(0, 1)$. Khi phân loại theo miền giá trị, $X$ thuộc loại biến ngẫu nhiên liên tục.

    Với mọi số thực $r \in (0, 1)$, có $P\{ X = r \} = 0$, nhưng đồng thời $P\{ X = 0 \} = \frac{1}{2}$.

Mặt khác, giả sử $X \sim F(x)$, khi đó

$$
P( l < X \leq l + \Delta x ) = F(l + \Delta x) - F(l)
$$

Một ý tưởng tự nhiên là dùng giới hạn $\lim\limits_{\Delta x \to 0^+} \frac{F(l + \Delta x) - F(l)}{\Delta x}$ để mô tả khả năng $X$ nhận giá trị $l$.

Biểu thức này chính là đạo hàm quen thuộc. Vì vậy, bài toán chuyển thành tìm một hàm không âm $f(x)$ sao cho

$$
F(x) = \int_{-\infty}^{x} f(x) \text{d} x
$$

Nếu tồn tại $f(x)$ như vậy, nó được gọi là **hàm mật độ** của $X$.

<span id="tính-độc-lập-của-biến-ngẫu-nhiên"></span>
## Tính độc lập của biến ngẫu nhiên

Phần trước đã thảo luận tính độc lập của các biến cố ngẫu nhiên. Do biến ngẫu nhiên và biến cố ngẫu nhiên có liên hệ chặt chẽ, tính độc lập của biến ngẫu nhiên cũng có thể được định nghĩa theo cách tương tự.

<span id="định-nghĩa"></span>
### Định nghĩa

Nếu các biến ngẫu nhiên $X, Y$ thỏa mãn với mọi $x, y \in \mathbb{R}$:

$$
P( X \leq x, Y \leq y ) = P( X \leq x ) P( Y \leq y )
$$

thì các biến ngẫu nhiên $X, Y$ được gọi là **độc lập**.

??? note "Ghi chú"
    Trong sách giáo khoa phổ thông, tính độc lập của biến ngẫu nhiên thường được định nghĩa bằng các xác suất dạng $P(X = \alpha)$. Tuy nhiên, vì xác suất để biến ngẫu nhiên liên tục nhận một giá trị cụ thể thường bằng $0$, trong trường hợp tổng quát hơn, định nghĩa thông qua hàm phân phối là lựa chọn hợp lý hơn.

<span id="tính-chất"></span>
### Tính chất

Nếu các biến ngẫu nhiên $X$,$Y$ độc lập với nhau, thì với mọi hàm $f, g$, các biến ngẫu nhiên $f(X)$ và $g(Y)$ cũng độc lập với nhau.

??? warning "Lưu ý"
    Đôi khi cần nghiên cứu phân phối của một hàm $f(X, Y)$ (ví dụ $XY^2$) của hai biến ngẫu nhiên độc lập $X$,$Y$.

    Mặc dù $X$ và $Y$ độc lập, không thể mặc nhiên cho rằng với một giá trị $y$ nào đó của $Y$, $f(X, y)$ và $f(X, Y)$ tuân theo cùng một phân phối.
