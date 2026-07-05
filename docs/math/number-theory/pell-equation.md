Kiến thức nền: [phân số liên tục](./continued-fraction.md), [trường bậc hai](./quadratic.md)

<span id="mở-đầu"></span>
## Mở đầu

Bài viết này thảo luận cách giải phương trình Pell (tổng quát). Phương trình
Pell tổng quát là phương trình vô định theo $x$ và $y$

$$
x^2-Dy^2=N,
$$

trong đó $D$ là số nguyên dương không phải số chính phương[^not-square], và
$N$ là số nguyên khác không. Theo nghĩa hẹp, phương trình Pell chỉ trường hợp
đặc biệt $N=1$ hoặc $N=\pm 1$, đôi khi cũng gồm cả $N=\pm 4$. Phương trình Pell
tổng quát liên quan chặt chẽ đến việc tìm số nguyên bậc hai có chuẩn bằng $N$
trong vành số nguyên bậc hai thực, còn các trường hợp thường được gọi là phương
trình Pell (nghĩa hẹp) có thể xem như việc tìm đơn vị trong vành số nguyên bậc
hai thực.

Khi bài viết này nói đến phương trình Pell, mặc định là trường hợp $N=1$. Tương
ứng, trường hợp $N=-1$ được gọi là phương trình Pell âm[^neg-pell] (negative
Pell's equation).

<span id="cấu-trúc-nghiệm"></span>
## Cấu trúc nghiệm

Nghiệm nguyên $(x,y)$ của phương trình Pell tổng quát có liên hệ mật thiết với
số nguyên bậc hai $x+y\sqrt{D}$, vì vậy trong tài liệu nghiệm của phương trình
Pell thường được viết dưới dạng $x+y\sqrt{D}$. Vì chuẩn của số nguyên bậc hai là

$$
N(x+y\sqrt{D}) = x^2-Dy^2,
$$

nên phương trình Pell tổng quát về cơ bản là bài toán tìm số nguyên bậc hai có
chuẩn bằng $N$. Tuy nhiên, hai bài toán có khác biệt nhỏ. Khi $x$ và $y$ đều là
số nguyên, $x+y\sqrt{D}$ nhất định là số nguyên bậc hai; ngược lại, số nguyên
bậc hai không nhất thiết yêu cầu $x$ và $y$ đều là số nguyên: trong trường hợp
$D\equiv 1\pmod 4$, $x$ và $y$ còn có thể đồng thời là bán nguyên[^half-int].

Khác biệt này đặc biệt quan trọng khi tìm đơn vị cơ bản. Đơn vị trong vành số
nguyên bậc hai là số nguyên bậc hai có chuẩn bằng $\pm 1$. Với
$D\equiv 2,3\pmod 4$, để tìm các đơn vị như vậy chỉ cần giải phương trình Pell
tổng quát trong trường hợp $N=\pm 1$; nhưng với $D\equiv 1\pmod 4$, cần xét
thêm trường hợp $N=\pm 4$. [Phần dưới](#trường-hợp-chuẩn-bằng-4)
sẽ thảo luận cách tìm đơn vị.

Để hiểu cấu trúc nghiệm của phương trình Pell tổng quát, cần bắt đầu từ
[đồng nhất thức Brahmagupta](https://en.wikipedia.org/wiki/Brahmagupta%27s_identity):

$$
(x_1^2-Dy_1^2)(x_2^2-Dy_2^2)=(x_1x_2+Dy_1y_2)^2-D(x_1y_2+x_2y_1)^2.
$$

Nó tương đương với tính chất chuẩn của số nguyên bậc hai bảo toàn phép nhân, tức

$$
\begin{aligned}
N\left(x_1+y_1\sqrt{D}\right)N\left(x_2+y_2\sqrt{D}\right) &= N\left((x_1+y_1\sqrt{D})(x_2+y_2\sqrt{D})\right) \\
&= N\left((x_1x_2+Dy_1y_2)+(x_1y_2+x_2y_1)\sqrt{D}\right).
\end{aligned}
$$

Dùng đồng nhất thức này, ta có thể ghép nghiệm nguyên của phương trình
$x^2-Dy^2=N_1$ và nghiệm nguyên của phương trình $x^2-Dy^2=N_2$ để thu nghiệm
nguyên của phương trình $x^2-Dy^2=N_1N_2$. Dĩ nhiên, nhìn từ góc độ số nguyên
bậc hai, phép ghép nghiệm chính là phép nhân số nguyên bậc hai; đây là tiện ích
của cách ghi nghiệm phương trình Pell dưới dạng số nguyên bậc hai. Đặc biệt,
lấy $N_1=N$ và $N_2=1$ cho thấy: nếu đã biết một nghiệm của $x^2-Dy^2=N$ và tất
cả nghiệm của phương trình Pell tương ứng $x^2-Dy^2=1$, ta có thể thu thêm
nhiều nghiệm của $x^2-Dy^2=N$. Tất nhiên, phương pháp này không nhất thiết sinh
ra tất cả nghiệm. Nhưng ít nhất nó cho thấy việc hiểu cấu trúc nghiệm của
phương trình Pell có vai trò quan trọng đối với cấu trúc nghiệm của phương trình
Pell tổng quát.

<span id="phương-trình-pell"></span>
### Phương trình Pell

Ý nghĩa hình học của phương trình $x^2-Dy^2=1$ là một hyperbol có trục thực
theo trục $x$ và trục ảo theo trục $y$. Mỗi điểm trên hyperbol tương ứng duy
nhất với một giá trị khác không của $x+y\sqrt{D}$: nhánh trái của hyperbol tương
ứng với giá trị âm của $x+y\sqrt{D}$, nhánh phải tương ứng với giá trị dương.
Hơn nữa, trên mỗi nhánh, giá trị $x+y\sqrt{D}$ tương ứng với các điểm trên
hyperbol tăng nghiêm ngặt từ dưới lên trên. Giá trị của số nguyên bậc hai tạo ra
một thứ tự tự nhiên cho các nghiệm của phương trình Pell.

Hyperbol đồng thời đối xứng qua trục $x$ và trục $y$, nên khi thảo luận nghiệm
của phương trình Pell chỉ cần xét đoạn nằm trong góc phần tư thứ nhất; các
nghiệm còn lại thu được bằng đối xứng. Điều này tương đương với chỉ xét các
nghiệm $x+y\sqrt{D}>1$. Nếu ngoài $(\pm 1,0)$ phương trình còn có nghiệm không
tầm thường, thì trong góc phần tư thứ nhất nhất định tồn tại nghiệm $(x_1,y_1)$
có giá trị $x+y\sqrt{D}$ nhỏ nhất; đây cũng là điểm nguyên trong góc phần tư thứ
nhất (không kể trục tọa độ) có cả hoành độ và tung độ nhỏ nhất. Nó được gọi là
nghiệm cơ bản (fundamental solution) của phương trình Pell[^fundamental-solution].
Theo thảo luận ở trên, mọi cặp số nguyên $(x_k,y_k)$ thỏa mãn
$x_k+y_k\sqrt{D}=(x_1+y_1\sqrt{D})^k$ đều là nghiệm của phương trình Pell và đều
nằm trong góc phần tư thứ nhất. Ngược lại, đây thực sự là tất cả nghiệm của
phương trình Pell trong góc phần tư thứ nhất. Kết hợp với đối xứng, ta có kết
luận sau:

???+ note "Định lý"
    Giả sử nghiệm cơ bản của phương trình Pell $x^2-Dy^2=1$ là $(x_1,y_1)$.
    Khi đó toàn bộ nghiệm của nó là

    $$
    \{(x,y):x+y\sqrt{D}=\pm(x_1+y_1\sqrt{D})^k,k\in\mathbf Z\}.
    $$

??? note "Chứng minh"
    Trước hết chứng minh trong góc phần tư thứ nhất không có nghiệm nào khác.
    Giả sử ngược lại tồn tại nghiệm khác $x+y\sqrt{D}$ và với một $k\ge 0$ nào
    đó có

    $$
    x_k+y_k\sqrt{D}< x+y\sqrt{D}< x_{k+1}+y_{k+1}\sqrt{D}.
    $$

    Về hình học, điều này có nghĩa điểm nguyên $(x,y)$ nằm trên hyperbol giữa
    $(x_k,y_k)$ và $(x_{k+1},y_{k+1})$ (không kể hai đầu mút). Nhân đồng thời
    bất đẳng thức với $x_k-y_k\sqrt{D}=(x_k+y_k\sqrt{D})^{-1}$, ta được

    $$
    1< (x+y\sqrt{D})(x_k-y_k\sqrt{D})=(xx_k-Dyy_k)+(x_ky-xy_k)\sqrt{D} < x_1+y_1\sqrt{D}.
    $$

    Theo tính đơn điệu đã nêu ở trên, bất đẳng thức này cho thấy
    $(xx_k-Dyy_k,x_ky-xy_k)$ là điểm nguyên nằm giữa $(1,0)$ và $(x_1,y_1)$.
    Điều này mâu thuẫn với cách chọn $(x_1,y_1)$.

    Khi mở rộng nghiệm từ góc phần tư thứ nhất ra toàn bộ mặt phẳng, đổi dấu số
    mũ $k$ (tức lấy nghịch đảo toàn bộ) chính là đối xứng qua trục $x$, còn đổi
    dấu toàn bộ là đối xứng qua gốc tọa độ. Thêm nghiệm tầm thường khi $k=0$, ta
    thu được tất cả nghiệm của phương trình Pell.

Thảo luận trên chỉ giả sử tồn tại nghiệm cơ bản. Bây giờ cần chỉ ra phương trình
Pell luôn có nghiệm không tầm thường.

???+ note "Định lý"
    Phương trình Pell $x^2-Dy^2=1$ luôn có nghiệm nguyên khác $(\pm 1,0)$.

??? note "Chứng minh"
    Trước hết, [định lý Dirichlet](./continued-fraction.md#dùng-phân-số-tiệm-cận-để-xấp-xỉ-số-thực)
    cho biết tồn tại vô hạn cặp số nguyên dương $(x,y)$ sao cho

    $$
    \left|\dfrac{x}{y}-\sqrt{D}\right| \le \dfrac{1}{y^2}
    $$

    đúng. Chúng đều thỏa mãn bất đẳng thức

    $$
    |x^2-Dy^2|=y^2\left|\dfrac{x}{y}-\sqrt{D}\right|\left|\dfrac{x}{y}+\sqrt{D}\right| \le \dfrac{1}{y^2}+2\sqrt{D}<1+2\sqrt{D}.
    $$

    Do đó, nhất định tồn tại số nguyên $m\in(-1-2\sqrt{D},1+2\sqrt{D})$ sao cho
    có vô hạn cặp $(x,y)$ thỏa mãn $x^2-Dy^2 = m$. Phân loại các cặp $(x,y)$
    này theo phần dư modulo $m$, ta biết với một cặp số nguyên $(x_0,y_0)$ nào
    đó, nhất định tồn tại vô hạn cặp $(x,y)$ sao cho $x\equiv x_0\pmod m$ và
    $y\equiv y_0\pmod m$. Chọn hai cặp phân biệt bất kỳ $(x_1,y_1)$ và
    $(x_2,y_2)$ thỏa mãn các điều kiện này, khi đó

    $$
    \dfrac{x_1+y_1\sqrt{D}}{x_2+y_2\sqrt{D}}=\dfrac{x_1x_2-Dy_1y_2}{m}+\dfrac{x_2y_1-x_1y_2}{m}\sqrt{D}.
    $$

    Vì theo quan hệ đồng dư có

    $$
    \begin{aligned}
    x_1x_2-Dy_1y_2 &\equiv x_0^2-Dy_0^2 = m \equiv 0 \pmod{|m|},\\
    x_2y_1-x_1y_2 &\equiv x_0y_0-x_0y_0 = 0 \pmod{|m|},
    \end{aligned}
    $$

    nên vế phải của công thức trên là một nghiệm nguyên. Hơn nữa, vì
    $(x_1,y_1)\neq(x_2,y_2)$, nghiệm này không tầm thường. Điều này chứng minh
    phương trình Pell thực sự có nghiệm không tầm thường.

Tất nhiên, phần này đưa ra chứng minh không xây dựng. Ở phần dưới khi thảo luận
cách giải phương trình Pell, ta sẽ trực tiếp dùng các phân số gần đúng của phân
số liên tục để xây dựng nghiệm, qua đó đưa ra một chứng minh khác cho sự tồn
tại nghiệm không tầm thường của phương trình Pell. Ngoài ra, mặc dù cấu trúc
nghiệm của phương trình Pell thu được ở đây phù hợp với cấu trúc đơn vị của
vành số nguyên bậc hai thực, nhưng với trường hợp $D\equiv 1\pmod 4$, phần này
vẫn chưa giải quyết hoàn toàn cấu trúc đơn vị của vành số nguyên bậc hai tương
ứng; phần dưới sẽ thảo luận tiếp.

<span id="phương-trình-pell-tổng-quát"></span>
### Phương trình Pell tổng quát

Đồ thị của phương trình Pell tổng quát $x^2-Dy^2=N$ cũng là hyperbol trên mặt
phẳng, cũng nhận trục $x$ và trục $y$ làm trục đối xứng. Như đã chỉ ra, một số
nghiệm của phương trình $x^2-Dy^2=N$ có thể chỉ khác nhau bởi một thừa số là
nghiệm của phương trình Pell, điều này có nghĩa ta có thể chia nghiệm của
phương trình $x^2-Dy^2=N$ thành các lớp tương đương. Với hai nghiệm $(x_1,y_1)$
và $(x_2,y_2)$ của phương trình $x^2-Dy^2=N$, nếu tồn tại nghiệm $(u,v)$ của
phương trình Pell sao cho
$x_2+y_2\sqrt{D}=(x_1+y_1\sqrt{D})(u+v\sqrt{D})$, thì nói nghiệm $(x_1,y_1)$ và
$(x_2,y_2)$ tương đương. Điều kiện cần và đủ để hai nghiệm tương đương là

$$
N\mid (x_1x_2-Dy_1y_2),\ N\mid (x_2y_1-x_1y_2).
$$

Vì nghiệm của phương trình Pell tương đối dễ tìm, một ý tưởng tự nhiên là tìm
một nghiệm trong mỗi lớp tương đương nói trên. Một khi biết các nghiệm này, ta
có thể dùng nghiệm của phương trình Pell tương ứng để thu tất cả nghiệm của
phương trình Pell tổng quát cần tìm. Trong các lớp tương đương của nghiệm
phương trình Pell tổng quát, do tính đối xứng, mỗi lớp đều tồn tại nghiệm có
tung độ $y$ không âm nhưng nhỏ nhất có thể. Nếu nghiệm như vậy duy nhất, nó được
gọi là nghiệm cơ bản của lớp tương đương; nếu không, lớp tương đương đó nhất
định có hai nghiệm có $y$ không âm và nhỏ nhất, và chúng đối xứng qua trục $y$,
khi đó chọn nghiệm có $x>0$ làm nghiệm cơ bản. Vì vậy, giải phương trình Pell
tổng quát $x^2-Dy^2=N$ tương đương với tìm tập nghiệm cơ bản $U$ của nó. Giả sử
nghiệm cơ bản của phương trình Pell tương ứng là $(r,s)$, thì tập tất cả nghiệm
của phương trình Pell tổng quát là

$$
\{(x,y):x+y\sqrt{D}=\pm(r+s\sqrt{D})^k(u+v\sqrt{D}),k\in\mathbf Z,u+v\sqrt{D}\in U\}.
$$

Số nghiệm cơ bản của phương trình Pell tổng quát nhất định hữu hạn. Vì từ biểu
thức nghiệm tổng quát ở trên, giá trị tuyệt đối $|u+v\sqrt{D}|$ nhất định nằm
giữa $r-s\sqrt{D}$ và $r+s\sqrt{D}$. Tài liệu tham khảo ở cuối bài cung cấp các
ước lượng chặt hơn về miền tọa độ của nghiệm cơ bản. Dĩ nhiên, khác với trường
hợp phương trình Pell, phương trình Pell tổng quát có thể vô nghiệm.

Ngoài việc dùng phép ghép nghiệm, để thu tất cả nghiệm trong cùng một lớp tương
đương từ một nghiệm $(u,v)$ của phương trình Pell tổng quát và nghiệm cơ bản
$(r,s)$ của phương trình Pell, ta cũng có thể dùng hệ thức truy hồi

$$
x_{k} = 2rx_{k-1} - x_{k-2},\ y_{k} = 2ry_{k-1} - y_{k-2},
$$

trong đó $x_k+y_k\sqrt{D}=(r+s\sqrt{D})^k(u+v\sqrt{D})$. Lý do là $x_n$ và
$y_n$ đều có thể viết dưới dạng $A(r+s\sqrt{D})^k+B(r-s\sqrt{D})^k$ với một cặp
số thực $(A,B)$ nào đó; theo định lý Vieta, $r\pm s\sqrt{D}$ là hai nghiệm thực
của phương trình $x^2-2rx+1=0$, nên $x_n$ và $y_n$ đều thỏa mãn truy hồi tuyến
tính hệ số hằng bậc hai trên. So với phép ghép nghiệm, công thức truy hồi này
cần ít phép nhân hơn.

<span id="phương-pháp-giải"></span>
## Phương pháp giải

Việc giải phương trình Pell và phương trình Pell tổng quát đều có thể dựa trên
phân số liên tục.

<span id="thuật-toán-pqa"></span>
### Thuật toán PQa

Những thuật toán được thảo luận trong bài này đều dựa trên thuật toán PQa, dùng
để tìm khai triển phân số liên tục của một số vô tỉ bậc hai cụ thể.

Giả sử các số nguyên $P_0,Q_0,D$ thỏa mãn $Q_0\neq 0$, $D>0$ không phải số chính
phương, và $P_0^2\equiv D\pmod{Q_0}$. Khi đó số vô tỉ bậc hai

$$
\omega=\dfrac{P_0+\sqrt{D}}{Q_0}
$$

có khai triển phân số liên tục $[a_0,a_1,\cdots]$ tính được bằng
[công thức truy hồi](./continued-fraction.md#số-vô-tỉ-bậc-hai)
sau:

$$
a_k = \left\lfloor\dfrac{P_k+\sqrt{D}}{Q_k}\right\rfloor,\ P_{k+1} = a_kQ_k - P_k,\ Q_{k+1} = \dfrac{D-P_{k+1}^2}{Q_k}.
$$

Tiếp theo, tử số và mẫu số $A_k$ và $B_k$ của phân số gần đúng thứ $k$ của
$\omega$ được cho bởi [công thức truy hồi](./continued-fraction.md#quan-hệ-truy-hồi)

$$
A_k = a_kA_{k-1} + A_{k-2},\ B_k = a_kB_{k-1} + B_{k-2}
$$

với $A_{-1} = 1$, $A_{-2}=0$, $B_{-1}=0$, $B_{-2}=1$.

Tính đúng đắn của các công thức này đã được chứng minh trong bài phân số liên
tục. Ở đó cũng đã giải thích rằng vì số vô tỉ bậc hai là
[phân số liên tục tuần hoàn](./continued-fraction.md#số-vô-tỉ-bậc-hai),
nên bộ ba $(P_k,Q_k,a_k)$ cuối cùng sẽ đi vào chu kỳ, và thuật toán luôn kết
thúc sau hữu hạn bước. Giả sử độ dài nhỏ nhất của chu kỳ là $\ell$, và vị trí
bắt đầu sớm nhất của chu kỳ là $k_0$, khi đó khai triển phân số liên tục của số
vô tỉ bậc hai có thể viết là

$$
\omega=[a_0,\cdots,a_{k_0-1},\overline{a_{k_0},\cdots,a_{k_0+\ell-1}}].
$$

Để dùng thuật toán PQa giải phương trình Pell, cần thiết lập kết quả sau:

???+ note "Định lý"
    Tiếp tục dùng ký hiệu trên. Đặt $G_k=Q_0A_k-P_0B_k$. Khi đó cặp số nguyên
    $(G_{k-1},B_{k-1})$ thỏa mãn

    $$
    G_{k-1}^2-DB_{k-1}^2=(-1)^{k}Q_0Q_{k},
    $$

    và ước chung lớn nhất của chúng $\gcd(G_{k-1},B_{k-1})$ là ước của $Q_{k}$.

??? note "Chứng minh"
    Giả sử trong khai triển phân số liên tục của $\omega$, thương hoàn toàn thứ
    $k$ là $\omega_{k}$, tức

    $$
    \omega = [a_0,a_1,\cdots,a_{k-1},\omega_k] = \dfrac{\omega_k A_{k-1}+A_{k-2}}{\omega_k B_{k-1}+B_{k-2}}.
    $$

    Thay $\omega=(P_0+\sqrt{D})/Q_0$ và $\omega_k=(P_k+\sqrt{D})/Q_k$ vào công
    thức trên, ta được

    $$
    \dfrac{P_0+\sqrt{D}}{Q_0} = \dfrac{(P_k+\sqrt{D})A_{k-1}+Q_kA_{k-2}}{(P_k+\sqrt{D})B_{k-1}+Q_kB_{k-2}}.
    $$

    Khử mẫu hai vế và so sánh hệ số của phần hữu tỉ và phần vô tỉ, rồi thay biểu
    thức của $G_k$, thu được các đẳng thức

    $$
    \begin{aligned}
    G_{k-1} &= P_kB_{k-1} + Q_kB_{k-2},\\
    DB_{k-1} &= P_kG_{k-1} + Q_kG_{k-2}.
    \end{aligned}
    $$

    Do đó, nhân đẳng thức thứ nhất với $G_{k-1}$ rồi trừ đẳng thức thứ hai nhân
    với $B_{k-1}$, ta có

    $$
    \begin{aligned}
    G_{k-1}^2-DB_{k-1}^2 &= (B_{k-2}G_{k-1}-B_{k-1}G_{k-2})Q_k \\
    &= (A_{k-1}B_{k-2}-B_{k-1}A_{k-2})Q_0Q_k \\
    &= (-1)^kQ_0Q_k.
    \end{aligned}
    $$

    Bước cuối dùng [công thức sai phân](./continued-fraction.md#ước-lượng-sai-số)
    của phân số gần đúng. Kết quả đầu tiên đã được chứng minh.

    Để chứng minh kết quả thứ hai, thay biểu thức của $G_k$ vào kết quả đầu
    tiên:

    $$
    (Q_0A_{k-1}-P_0B_{k-1})^2 - DB_{k-1}^2 = (-1)^kQ_0Q_k.
    $$

    Do $Q_0\mid(P_0^2-D)$, suy ra

    $$
    Q_0A_{k-1}^2 +\left(\dfrac{P_0^2-D}{Q_0}B_{k-1}- 2P_0A_{k-1}\right)B_{k-1} = (-1)^kQ_k.
    $$

    Vì vậy, $\gcd(G_{k-1},B_{k-1}) = \gcd(Q_0A_{k-1},B_{k-1})$ là ước của
    $Q_k$.

Kết quả này cung cấp một cách tìm nghiệm của phương trình $x^2-Dy^2=N$. Nếu
chọn hợp lý $Q_0>0$ và chọn $P_0$ là một nghiệm của đồng dư
$P_0^2\equiv D\pmod{Q_0}$, rồi chạy thuật toán PQa trên
$(P_0+\sqrt{D})/Q_0$ cho đến khi tìm được $(-1)^kQ_0Q_{k}=N$, thì
$(G_{k-1},B_{k-1})$ trở thành một nghiệm của phương trình ban đầu. Hơn nữa, nếu
$Q_k=\pm 1$, nghiệm thu được theo cách này nhất định là nghiệm nguyên thủy, tức
$G_{k-1}$ và $B_{k-1}$ nhất định nguyên tố cùng nhau.

Ý tưởng này là cốt lõi để giải phương trình Pell và phương trình Pell tổng quát.
Sau khi hiểu ý tưởng này, ta xử lý một số chi tiết của thuật toán và chứng minh
mọi nghiệm đều có thể thu được theo cách này.

<span id="phương-trình-pell_1"></span>
### Phương trình Pell

Để giải phương trình Pell $x^2-Dy^2=1$, chỉ cần chạy thuật toán PQa với
$(P_0,Q_0,D)=(0,1,D)$ cho đến khi xuất hiện $(-1)^kQ_k=1$; khi đó
$(A_{k-1},B_{k-1})$ là một nghiệm của phương trình Pell (vì lúc này
$G_{k-1}$ chính là $A_{k-1}$). Dĩ nhiên, với phương trình Pell, có thể mô tả
quá trình này chính xác hơn.

Trước hết, nghiệm nhất định xuất hiện ở cuối chu kỳ. Quá trình trên tương đương
với khai triển phân số liên tục của $\sqrt{D}$. Về điều này, đã có
[kết quả](./continued-fraction.md#liên-phân-số-thuần-tuần-hoàn):

$$
\sqrt{D} = [\lfloor\sqrt{D}\rfloor,\overline{a_1,\cdots,a_{\ell-1},2\lfloor\sqrt{D}\rfloor}].
$$

Ở đây độ dài chu kỳ là $\ell$, và vị trí bắt đầu là hạng thứ $1$ (chỉ số bắt
đầu từ $0$). Hơn nữa, thương hoàn toàn thứ $\ell$ của nó bằng
$\lfloor\sqrt{D}\rfloor+\sqrt{D}$, cho thấy $Q_{\ell}=1$. Do đó, nếu $\ell$
chẵn thì $(A_{\ell-1},B_{\ell-1})$ là một nghiệm không tầm thường của phương
trình Pell; nếu $\ell$ lẻ thì $(A_{2\ell-1},B_{2\ell-1})$ là một nghiệm không
tầm thường của phương trình Pell.

Tiếp theo cần chỉ ra nghiệm vừa thu được nhất định là nghiệm cơ bản. Kết quả này
dựa trên hai lý do: thứ nhất, mọi nghiệm nguyên dương $(x,y)$ của phương trình
Pell đều có phân số $x/y$ xuất hiện trong các phân số gần đúng của $\sqrt{D}$,
đảm bảo $(x,y)$ nhất định là một $(A_k,B_k)$ nào đó trong quá trình PQa; thứ
hai, ngoài cuối chu kỳ sẽ không có vị trí nào khác có $Q_k=1$, vì hệ thức truy
hồi của $A_k$ và $B_k$ đảm bảo kích thước của chúng tăng theo chỉ số, nên nghiệm
nguyên dương nhỏ nhất (tức nghiệm cơ bản) nhất định xuất hiện tại vị trí vừa chỉ
ra. Hai lý do này lần lượt suy ra từ hai định lý sau:

???+ note "Định lý"
    Giả sử phương trình $x^2-Dy^2=N$ có nghiệm nguyên dương $(x,y)$. Nếu
    $|N|<\sqrt{D}$, thì $\dfrac{x}{y}$ nhất định là một phân số gần đúng của
    $\sqrt{D}$.

??? note "Chứng minh"
    Khi $N>0$, vì $x^2-Dy^2>0$, nên $x>y\sqrt{D}$. Do đó

    $$
    \left|\dfrac{x}{y}-\sqrt{D}\right| = \dfrac{N}{y(x+y\sqrt{D})}<\dfrac{N}{2y^2\sqrt{D}}<\dfrac{1}{2y^2}.
    $$

    Theo [tiêu chuẩn Legendre](./continued-fraction.md#nhận-biết-phân-số-tiệm-cận),
    $\dfrac{x}{y}$ là phân số gần đúng của $\sqrt{D}$.

    Khi $N<0$, bất đẳng thức $x>y\sqrt{D}$ không còn đúng. Do đó xét phương
    trình $y^2-\dfrac{1}{D}x^2=-\dfrac{N}{D}$. Vì
    $\dfrac{|N|}{D}<\sqrt{\dfrac{1}{D}}$, lặp lại lập luận trên vẫn đúng. Điều
    này cho thấy $\dfrac{y}{x}$ là phân số gần đúng của $\dfrac{1}{\sqrt{D}}$.
    Theo [định lý nghịch đảo](./continued-fraction.md#quan-hệ-truy-hồi),
    $\dfrac{x}{y}$ cũng là phân số gần đúng của $\sqrt{D}$.

???+ note "Định lý"
    Trong quá trình chạy thuật toán PQa ở trên với $(P_0,Q_0,D)=(0,1,D)$,
    $Q_k=1$ nhất định kéo theo $\ell\mid k$.

??? note "Chứng minh"
    Trong khai triển phân số liên tục của $\sqrt{D}$, ngoài thương hoàn toàn thứ
    $0$, mọi thương hoàn toàn khác đều là [phân số liên tục thuần tuần hoàn](./continued-fraction.md#liên-phân-số-thuần-tuần-hoàn).
    Giả sử $Q_k=1$. Theo kết quả của Galois, nhất định có thương hoàn toàn
    $\omega_k=P_k+\sqrt{D}>1$, và liên hợp của nó $-1<P_k-\sqrt{D}<0$, suy ra
    $P_k=\lfloor\sqrt{D}\rfloor$. Do đó thương hoàn toàn $\omega_k$ bằng
    $\omega_\ell$. Nhưng sự lặp lại của thương hoàn toàn có nghĩa phân số liên
    tục vào chu kỳ; nếu $k$ không phải bội của $\ell$, điều này mâu thuẫn với
    việc $\ell$ là chu kỳ dương nhỏ nhất. Vì vậy nhất định $\ell\mid k$.

Tổng hợp thảo luận trong phần này: chỉ cần khai triển phân số liên tục của
$\sqrt{D}$, tức chạy thuật toán PQa từ $(P_0,Q_0,D)=(0,1,D)$; khi lần đầu có
$Q_\ell=1$ thì đã đến cuối chu kỳ đầu tiên. Nếu $\ell$ chẵn,
$(A_{\ell-1},B_{\ell-1})$ là nghiệm cơ bản của phương trình Pell; nếu không,
$(A_{2\ell-1},B_{2\ell-1})$ là nghiệm cơ bản của phương trình Pell. Khi độ dài
chu kỳ $\ell$ lẻ, không cần tiếp tục PQa đến hai lần chu kỳ, vì ngay sau đây sẽ
thấy $A_{2\ell-1}+B_{2\ell-1}\sqrt{D}=(A_{\ell-1}+B_{\ell-1}\sqrt{D})^2$, nên
có thể tính trực tiếp nghiệm cơ bản của phương trình Pell từ
$(A_{\ell-1},B_{\ell-1})$. Mọi nghiệm khác của phương trình Pell đều có thể
tính từ nghiệm cơ bản.

??? example "Ví dụ"
    1.  Giải phương trình $x^2-14y^2=1$.

        Chạy thuật toán PQa với $(P_0,Q_0,D)=(0,1,14)$ cho kết quả sau: (phần màu đỏ là chu kỳ đầu tiên)

        | $k$ | $P$ | $Q$ |        $a$       |  $A$  |  $B$ |  $G$  | $G^2-DB^2$ |
        | :-: | :-: | :-: | :--------------: | :---: | :--: | :---: | :--------: |
        | $0$ | $0$ | $1$ |        $3$       |  $3$  |  $1$ |  $3$  |    $-5$    |
        | $1$ | $3$ | $5$ | $\color{red}{1}$ |  $4$  |  $1$ |  $4$  |     $2$    |
        | $2$ | $2$ | $2$ | $\color{red}{2}$ |  $11$ |  $3$ |  $11$ |    $-5$    |
        | $3$ | $2$ | $5$ | $\color{red}{1}$ |  $15$ |  $4$ |  $15$ |     $1$    |
        | $4$ | $3$ | $1$ | $\color{red}{6}$ | $101$ | $27$ | $101$ |    $-5$    |
        | $5$ | $3$ | $5$ |        $1$       | $116$ | $31$ | $116$ |     $2$    |

        Độ dài chu kỳ $\ell=4$ là chẵn. Nghiệm nguyên dương nhỏ nhất của phương trình là $(G_3,B_3)=(15,4)$.
    2.  Giải phương trình $x^2-41y^2=1$.

        Chạy thuật toán PQa với $(P_0,Q_0,D)=(0,1,41)$ cho kết quả sau: (phần màu đỏ là chu kỳ đầu tiên)

        | $k$ | $P$ | $Q$ |        $a$        |   $A$   |   $B$  |   $G$   | $G^2-DB^2$ |
        | :-: | :-: | :-: | :---------------: | :-----: | :----: | :-----: | :--------: |
        | $0$ | $0$ | $1$ |        $6$        |   $6$   |   $1$  |   $6$   |    $-5$    |
        | $1$ | $6$ | $5$ |  $\color{red}{2}$ |   $13$  |   $2$  |   $13$  |     $5$    |
        | $2$ | $4$ | $5$ |  $\color{red}{2}$ |   $32$  |   $5$  |   $32$  |    $-1$    |
        | $3$ | $6$ | $1$ | $\color{red}{12}$ |  $397$  |  $62$  |  $397$  |     $5$    |
        | $4$ | $6$ | $5$ |        $2$        |  $826$  |  $129$ |  $826$  |    $-5$    |
        | $5$ | $4$ | $5$ |        $2$        |  $2049$ |  $320$ |  $2049$ |     $1$    |
        | $6$ | $6$ | $1$ |        $12$       | $25414$ | $3969$ | $25414$ |    $-5$    |
        | $7$ | $6$ | $5$ |        $2$        | $52877$ | $8258$ | $52877$ |     $5$    |

        Độ dài chu kỳ $\ell=3$ là lẻ. Nghiệm nguyên dương nhỏ nhất của phương trình là $(G_5,B_5)=(2049,320)$. Nó cũng có thể được tính từ $(G_2,B_2)=(32,5)$:

        $$
        (32+5\sqrt{41})^2=2049+320\sqrt{41}.
        $$

<span id="phương-trình-pell-âm"></span>
### Phương trình Pell âm

Theo thảo luận ở phần trước, nghiệm của phương trình Pell âm cũng nhất định
tương ứng với phân số gần đúng của $\sqrt{D}$, và chỉ có thể xuất hiện tại vị
trí $(-1)^kQ_k=-1$. Điều này chỉ có thể xảy ra ở cuối chu kỳ. Vì vậy, phương
trình Pell âm có nghiệm khi và chỉ khi độ dài chu kỳ $\ell$ là lẻ. Khi nghiệm
tồn tại, $(A_{\ell-1},B_{\ell-1})$ là nghiệm cơ bản của phương trình Pell âm.
Cách giải của nó giống phần trước.

Dùng ý tưởng tương tự chứng minh cấu trúc nghiệm của phương trình Pell ở trên,
có thể chứng minh kết quả sau:

???+ note "Định lý"
    Giả sử phương trình $x^2-Dy^2=-1$ có nghiệm và nghiệm cơ bản là
    $(x_1,y_1)$. Khi đó mọi nghiệm nguyên của $x^2-Dy^2=\pm 1$ đều thuộc tập

    $$
    \{(x,y):x+y\sqrt{D}=\pm(x_1+y_1\sqrt{D})^k,k\in\mathbf Z\}.
    $$

    Đặc biệt, nghiệm nguyên $(x_2,y_2)$ thỏa mãn
    $x_2+y_2\sqrt{D}=(x_1+y_1\sqrt{D})^2$ chính là nghiệm cơ bản của
    $x^2-Dy^2=1$.

??? note "Chứng minh"
    Do tính đối xứng, chỉ cần xét nghiệm nguyên dương, tức trường hợp
    $x+y\sqrt{D}>1$. Nhưng vì $x^2-Dy^2=\pm 1$ là hai cặp hyperbol, nên không
    thể lập tương ứng một-một giữa $x+y\sqrt{D}$ và $(x,y)$. Để xử lý khó khăn
    này, trước hết chứng minh $(x_2,y_2)$ nói trên là nghiệm cơ bản của
    $x^2-Dy^2=1$.

    Hiển nhiên, $(x_2,y_2)$ là nghiệm của $x^2-Dy^2=1$. Nếu đặt $(z,w)$ là
    nghiệm cơ bản của $x^2-Dy^2=1$, thì nhất định
    $1<z+w\sqrt{D}\le x_2+y_2\sqrt{D}$. Nếu bất đẳng thức bên phải là nghiêm
    ngặt, chia bất đẳng thức cho $x_1+y_1\sqrt{D}$ sẽ được
    $-x_1+y_1\sqrt{D}<(z+w\sqrt{D})(-x_1+y_1\sqrt{D})<x_1+y_1\sqrt{D}$. Khai
    triển hạng giữa ta thu được dạng $x'+y'\sqrt{D}$, có chuẩn $-1$ và
    $(x',y')$ cũng là nghiệm nguyên. Lấy nghịch đảo bất đẳng thức này, ta thấy
    $-x'+y'\sqrt{D}$ cũng nằm giữa $-x_1+y_1\sqrt{D}$ và
    $x_1+y_1\sqrt{D}$. Hai số nguyên bậc hai $\pm x'+y'\sqrt{D}$ là nghịch đảo
    của nhau, nên nhất định có một số lớn hơn $1$. Nhưng giữa $1$ và
    $x_1+y_1\sqrt{D}$ không nên xuất hiện số nguyên bậc hai nào khác có chuẩn
    $-1$, mâu thuẫn với tính nhỏ nhất của $x_1+y_1\sqrt{D}$. Vì vậy phải có
    $x_2+y_2\sqrt{D}=z+w\sqrt{D}$, tức $(x_2,y_2)$ là nghiệm cơ bản của phương
    trình $x^2-Dy^2=1$.

    Dựa trên điều này, nếu tồn tại nghiệm $(x,y)$ của phương trình
    $x^2-Dy^2=\pm 1$ không tương ứng với một lũy thừa
    $(x_1+y_1\sqrt{D})^k$, thì nhất định tồn tại $k$ sao cho
    $(x_1+y_1\sqrt{D})^{2k}<x+y\sqrt{D}<(x_1+y_1\sqrt{D})^{2k+2}$.
    Khử thừa số $(x_1+y_1\sqrt{D})^{2k+1}$, ta suy ra tồn tại số nguyên bậc hai
    $x'+y'\sqrt{D}\neq 1$ có chuẩn $\pm 1$ nằm giữa $-x_1+y_1\sqrt{D}$ và
    $x_1+y_1\sqrt{D}$. Lặp lại lập luận bằng nghịch đảo của đoạn trước cho thấy
    điều này mâu thuẫn với tính nhỏ nhất của $x_1+y_1\sqrt{D}$. Mệnh đề được
    chứng minh.

Vì $(A_{\ell-1},B_{\ell-1})$ là nghiệm nguyên dương nhỏ nhất của phương trình
Pell âm, và tất cả nghiệm nguyên dương của $x^2-Dy^2=\pm 1$ đều nằm trong tập

$$
\{(x,y):x+y\sqrt{D}=(A_{\ell-1}+B_{\ell-1}\sqrt{D})^k,k\in\mathbf N_+\}
$$

hơn nữa các nghiệm nguyên dương này nhất định tương ứng với phân số gần đúng của
$\sqrt{D}$ ở vị trí cuối chu kỳ (trước một vị trí), và tử số cùng mẫu số của
phân số gần đúng tăng nghiêm ngặt, nên với mọi $k\in\mathbf N_+$ luôn có

$$
(A_{\ell-1}+B_{\ell-1}\sqrt{D})^k = A_{k\ell-1}+B_{k\ell-1}\sqrt{D}.
$$

Trong tất cả các nghiệm nguyên dương này, khi $k$ lẻ thì là nghiệm của phương
trình Pell âm, khi $k$ chẵn thì là nghiệm của phương trình Pell; hai loại xuất
hiện xen kẽ.

Để phán định phương trình Pell âm có nghiệm hay không cần tính độ dài chu kỳ của
khai triển phân số liên tục của $\sqrt{D}$; điều này không dễ tính, nên ta muốn
có tiêu chuẩn đơn giản hơn. Tuy nhiên, hiện chưa có điều kiện nào vừa ngắn gọn
vừa dễ tính[^solubility-neg-pell]. Ở đây chỉ đưa ra một kết quả đơn giản.

???+ note "Định lý"
    Nếu phương trình $x^2-Dy^2=-1$ có nghiệm, thì $4\nmid D$ và $D$ không chứa
    thừa số nguyên tố dạng $4k+3$. Ngược lại, nếu $D=2$ hoặc $D$ là số nguyên tố
    dạng $4k+1$, thì phương trình nhất định có nghiệm.

??? note "Chứng minh"
    Trước hết, phương trình Pell âm có nghiệm có nghĩa $-1$ là thặng dư bậc hai
    modulo $D$, nên $-1$ cũng là thặng dư bậc hai modulo mọi ước $d$ của $D$; do
    đó $d\neq 4$ và $d$ không phải số nguyên tố dạng $4k+3$. Ngược lại, phương
    trình $x^2-2y^2=-1$ có nghiệm không tầm thường $(1,1)$. Phần còn lại là
    trường hợp $D$ là số nguyên tố dạng $4k+1$.

    Giả sử $D$ là số nguyên tố dạng $4k+1$, cần chứng minh phương trình
    $x^2-Dy^2=-1$ có nghiệm. Ý tưởng là bắt đầu từ nghiệm cơ bản $(u,v)$ của
    phương trình Pell $x^2-Dy^2=1$, rồi xây dựng nghiệm $(\alpha,\beta)$ của
    $x^2-Dy^2=-1$. Nếu $u$ chẵn, lấy đồng dư hai vế của $u^2-Dv^2=1$ modulo $4$
    sẽ được $v^2\equiv -1\pmod 4$, nhưng $-1$ không phải thặng dư bậc hai modulo
    $4$. Mâu thuẫn này cho thấy $u$ lẻ. Xét đẳng thức
    $Dv^2=u^2-1=(u+1)(u-1)$. Vì $u$ lẻ,
    $\gcd(u+1,u-1)=\gcd(u+1,2)=2$. Dựa vào điều này, khi phân bổ các thừa số của
    $Dv^2$ vào $u+1$ và $u-1$, nhất định một trong hai là $2\alpha^2$, số còn
    lại là $2D\beta^2$, trong đó $\alpha$ và $\beta$ là các số nguyên dương
    nguyên tố cùng nhau và $v=2\alpha\beta$. Thay $u=\alpha^2+D\beta^2$ và
    $v=2\alpha\beta$ vào $u^2-Dv^2=1$, ta được
    $\alpha^2-D\beta^2=\pm 1$. Vì $(u,v)$ là nghiệm cơ bản của phương trình Pell
    và $(\alpha,\beta)$ là cặp số nguyên dương nhỏ hơn $(u,v)$, vế phải của đẳng
    thức này không thể là $+1$, nên chỉ có thể là $-1$. Điều này chứng minh
    $x^2-Dy^2=-1$ có nghiệm $(\alpha,\beta)$.

Nếu $D$ là hợp số, điều kiện không chứa thừa số nguyên tố dạng $4k+3$ và không
chứa nhân tử chính phương cũng không đảm bảo phương trình $x^2-Dy^2=-1$ có
nghiệm; chẳng hạn $x^2-34y^2=-1$ vô nghiệm.

??? example "Ví dụ"
    Từ kết quả tính toán trong các ví dụ trên, phương trình $x^2-14y^2=-1$ vô
    nghiệm, và nghiệm nguyên dương nhỏ nhất của phương trình $x^2-41y^2=-1$ là
    $(G_2,B_2)=(32,5)$.

<span id="trường-hợp-chuẩn-bằng-4"></span>
### Trường hợp chuẩn bằng ±4

Tiếp theo thảo luận nghiệm của phương trình $x^2-Dy^2=\pm 4$. Lúc này tính
chất của nghiệm phụ thuộc vào giá trị của $D\bmod 4$.

Một số trường hợp rất dễ xử lý. Nếu $D\equiv 0\pmod 4$, thì $x$ chẵn, nên
$(x/2,y)$ là nghiệm của phương trình $u^2-(D/4)v^2=\pm 1$. Các trường hợp còn
lại, nhất định $x,y$ đồng thời lẻ hoặc đồng thời chẵn. Nếu $x,y$ đồng thời lẻ,
lấy modulo $4$ hai vế phương trình cho $D\equiv 1\pmod 4$. Vì vậy, nếu
$D\equiv 2,3\pmod 4$, thì $x,y$ chỉ có thể đồng thời chẵn, nên $(x/2,y/2)$ là
nghiệm của phương trình $u^2-Dv^2=\pm 1$. Do đó, ngoài trừ trường hợp
$D\equiv 1\pmod 4$, nghiệm của phương trình $x^2-Dy^2=\pm 4$ đều có thể thu
được từ nghiệm của phương trình Pell (âm) tương ứng.

Bây giờ xét trường hợp $D\equiv 1\pmod 4$; nó không thể chuyển đơn giản về các
trường hợp đã giải. Để tìm nghiệm cơ bản, có thể áp dụng thuật toán PQa cho
$(P_0,Q_0,D)=(1,2,D)$. Khi lần đầu thu được $Q_\ell=2$, ta đến cuối chu kỳ đầu
tiên. Nếu độ dài chu kỳ $\ell$ chẵn, $(G_{\ell-1},B_{\ell-1})$ là nghiệm cơ bản
của phương trình $x^2-Dy^2=4$; nếu không, $(G_{\ell-1},B_{\ell-1})$ là nghiệm
cơ bản của phương trình $x^2-Dy^2=-4$. Từ $(G_{\ell-1},B_{\ell-1})$, có thể thu
tất cả nghiệm của phương trình $x^2-Dy^2=\pm 4$:

$$
\left\{(x,y):\dfrac{x+y\sqrt{D}}{2}=\pm\left(\dfrac{G_{\ell-1}+B_{\ell-1}\sqrt{D}}{2}\right)^k,k\in\mathbf Z\right\}.
$$

Nếu độ dài chu kỳ $\ell$ chẵn, tất cả chúng đều là nghiệm của phương trình
$x^2-Dy^2=4$; nếu không, khi $k$ lẻ thì $(x,y)$ là nghiệm của phương trình
$x^2-Dy^2=-4$, còn khi $k$ chẵn thì $(x,y)$ là nghiệm của phương trình
$x^2-Dy^2=4$.

Tính đúng đắn của thuật toán này dựa trên các sự kiện sau:

???+ note "Định lý"
    Giả sử phương trình $x^2-Dy^2=\pm 4$ có nghiệm nguyên dương $(x,y)$. Nếu
    $D\equiv 1\pmod 4$, thì $\dfrac{(x+y)/2}{y}$ nhất định là một phân số gần
    đúng của $\dfrac{1+\sqrt{D}}{2}$.

??? note "Chứng minh"
    Trước hết chú ý rằng khi đó $x,y$ nhất định cùng tính chẵn lẻ, nên
    $(x+y)/2$ là số nguyên. Nếu $(x,y)$ là nghiệm của phương trình
    $x^2-Dy^2=4$, thì $x>y\sqrt{D}>2y$, do đó

    $$
    \left|\dfrac{(x+y)/2}{y}-\dfrac{1+\sqrt{D}}{2}\right| = \dfrac{2}{y(x+y\sqrt{D})}<\dfrac{1}{2y^2}.
    $$

    Theo [tiêu chuẩn Legendre](./continued-fraction.md#nhận-biết-phân-số-tiệm-cận),
    $\dfrac{(x+y)/2}{y}$ là phân số gần đúng của $\dfrac{1+\sqrt{D}}{2}$.

    Nếu $(x,y)$ là nghiệm của phương trình $x^2-Dy^2=-4$, để thiết lập bất đẳng
    thức trên chỉ cần chứng minh $4y<x+y\sqrt{D}$. Điều này đúng ít nhất với mọi
    trường hợp ngoài $D=5,13$. Với $D=5,13$, thay $x=\sqrt{Dy^2-4}$ vào bất đẳng
    thức cho thấy nó tương đương với $2(\sqrt{D}-2)y^2>1$. Ngoài
    $(D,y)=(5,1)$, bất đẳng thức này đúng với mọi $D=5,13$ và số nguyên dương
    $y$. Còn lại chỉ cần kiểm tra trường hợp $(D,y)=(5,1)$; khi đó nghiệm của
    phương trình $x^2-5y^2=-4$ là $(x,y)=(1,1)$, và cần kiểm tra $\dfrac{1}{1}$
    là phân số gần đúng của $\dfrac{1+\sqrt{5}}{2}=[\overline{1}]$, điều này
    hiển nhiên đúng.

???+ note "Định lý"
    Giả sử $D$ là số nguyên dương không phải số chính phương. Khai triển phân số
    liên tục của số vô tỉ bậc hai $\omega=\dfrac{1+\sqrt{D}}{2}$ có dạng

    $$
    \omega = [\lfloor\omega\rfloor,\overline{a_1,\cdots,a_{\ell-1},2\lfloor\omega\rfloor-1}],
    $$

    trong đó $\ell$ là độ dài chu kỳ, và $a_k=a_{\ell-k}$ với mọi $1<k<\ell$.

??? note "Chứng minh"
    Vì $\lfloor\omega\rfloor-1+\omega>1$, và liên hợp của nó bằng
    $\lfloor\omega\rfloor - \omega$, nằm giữa $-1$ và $0$, nên theo
    [kết quả của Galois](./continued-fraction.md#liên-phân-số-thuần-tuần-hoàn),
    $\lfloor\omega\rfloor-1+\omega$ là phân số liên tục thuần tuần hoàn, có thể
    viết thành

    $$
    \lfloor\omega\rfloor-1+\omega = [\overline{2\lfloor\omega\rfloor-1,a_1,\cdots,a_{\ell-1}}].
    $$

    Kết quả của Galois về nghịch đảo của liên hợp đổi dấu cho biết

    $$
    \dfrac{1}{\omega-\lfloor\omega\rfloor} = [\overline{a_{\ell-1},\cdots,a_1,2\lfloor\omega\rfloor-1}].
    $$

    Do đó, theo định nghĩa phân số liên tục,

    $$
    \lfloor\omega\rfloor-1+\omega = 2\lfloor\omega\rfloor-1 + \dfrac{1}{\dfrac{1}{\omega-\lfloor\omega\rfloor}} = [2\lfloor\omega\rfloor-1,\overline{a_{\ell-1},\cdots,a_1,2\lfloor\omega\rfloor-1}].
    $$

    Tính duy nhất của khai triển phân số liên tục cho thấy $a_k=a_{\ell-k}$ với
    mọi $1<k<\ell$, và do đó dạng khai triển cần chứng minh cũng đúng.

???+ note "Định lý"
    Giả sử $D\equiv 1\pmod 4$. Trong quá trình chạy thuật toán PQa ở trên với
    $(P_0,Q_0,D)=(1,2,D)$, $Q_k=2$ nhất định kéo theo $\ell\mid k$.

??? note "Chứng minh"
    Trong khai triển phân số liên tục của $\dfrac{1+\sqrt{D}}{2}$, ngoài thương
    hoàn toàn thứ $0$, mọi thương hoàn toàn khác đều là
    [phân số liên tục thuần tuần hoàn](./continued-fraction.md#liên-phân-số-thuần-tuần-hoàn).
    Giả sử $Q_k=2$. Theo kết quả của Galois, liên hợp của thương hoàn toàn
    $\omega_k=\dfrac{P_k+\sqrt{D}}{2}$ nhất định thỏa
    $-1<\dfrac{P_k-\sqrt{D}}{2}<0$, tức $\sqrt{D}-2<P_k<\sqrt{D}$. Vì trong
    thuật toán PQa luôn có $Q_k\mid P_k^2-D$ (xem
    [chứng minh tính đúng đắn của thuật toán](./continued-fraction.md#số-vô-tỉ-bậc-hai)),
    nên $P_k$ nhất định lẻ; điều này cho thấy giá trị của $P_k$ là duy nhất,
    tức $P_k=P_0+2(\lfloor\omega\rfloor-1)$, hay thương hoàn toàn
    $\omega_k=\omega_\ell$. Nhưng sự lặp lại của thương hoàn toàn có nghĩa phân
    số liên tục vào chu kỳ; nếu $k$ không phải bội của $\ell$, điều này mâu
    thuẫn với việc $\ell$ là chu kỳ dương nhỏ nhất. Vì vậy nhất định
    $\ell\mid k$.

???+ note "Định lý"
    Giả sử nghiệm nguyên dương nhỏ nhất của phương trình $x^2-Dy^2=\pm 4$ là
    $(x_1,y_1)$. Khi đó toàn bộ nghiệm của nó là

    $$
    \left\{(x,y):\dfrac{x+y\sqrt{D}}{2}=\pm\left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^k,k\in\mathbf Z\right\}.
    $$

??? note "Chứng minh"
    Do tính đối xứng, chỉ cần xét nghiệm nguyên dương $(x,y)$. Ở đây chỉ cần
    chứng minh các cặp số thực $(x,y)$ trong tập trên thực sự là nghiệm nguyên
    của phương trình $x^2-Dy^2=\pm 4$. Phần còn lại chỉ cần lặp lại chứng minh
    cấu trúc nghiệm của phương trình $x^2-Dy^2=\pm 1$.

    Thực chất cần chứng minh rằng với bất kỳ hai nghiệm nguyên $(x_1,y_1)$ và
    $(x_2,y_2)$ của phương trình $x^2-Dy^2=\pm 4$, cặp số thực dương
    $(x_3,y_3)$ định nghĩa bởi

    $$
    \dfrac{x_3+y_3\sqrt{D}}{2} = \dfrac{x_1+y_1\sqrt{D}}{2}\dfrac{x_2+y_2\sqrt{D}}{2}
    $$

    vẫn là nghiệm nguyên:

    $$
    x_3=\dfrac{x_1x_2+Dy_1y_2}{2},\ y_3=\dfrac{x_1y_2+x_2y_1}{2}.
    $$

    Vì với $i=1,2$ có $x_i\equiv x_i^2\equiv Dy_i^2\equiv Dy_i\pmod 2$, nên

    $$
    \begin{aligned}
    2x_3 &= x_1x_2+Dy_1y_2 \equiv D^2y_1y_2+Dy_1y_2=D(D+1)y_1y_2 \equiv 0 \pmod 2,\\
    2y_3 &= x_1y_2+x_2y_1 \equiv Dy_1y_2+Dy_2y_1 = 2Dy_1y_2 \equiv 0 \pmod 2.
    \end{aligned}
    $$

    Điều này cho thấy $x_3$ và $y_3$ đều là số nguyên. Lại dùng tính chất chuẩn
    bảo toàn phép nhân, ta biết $(x_3,y_3)$ là nghiệm của $x^2-Dy^2=\pm 4$.

Tổng hợp các sự kiện này và lặp lại lập luận của các phần trước, có thể chứng
minh tính đúng đắn của thuật toán giải phương trình $x^2-Dy^2=\pm 4$ nêu trên.
Các kết quả này cho thấy phương trình $x^2-Dy^2=\pm 4$ có cấu trúc nghiệm đơn
giản tương tự phương trình $x^2-Dy^2=\pm 1$: tất cả nghiệm đều có thể biểu diễn
bằng nghiệm nguyên dương nhỏ nhất của nó, không cần giải các phương trình khác.

Thực ra, mọi nghiệm của phương trình $x^2-Dy^2=\pm 1$ đều có thể tìm thấy trong
nghiệm của phương trình $x^2-Dy^2=\pm 4$; từ góc nhìn này, phương trình
$x^2-Dy^2=\pm 4$ có tính cơ bản hơn. Hiển nhiên, $(x,y)$ là nghiệm của
$x^2-Dy^2=\pm 1$ khi và chỉ khi $(2x,2y)$ là nghiệm của $x^2-Dy^2=\pm 4$. Phân
tích trên chỉ ra rằng khi $D\equiv 2,3\pmod 4$, mọi nghiệm của phương trình
$x^2-Dy^2=\pm 4$ đều đồng thời chẵn, nên tương ứng với nghiệm của
$x^2-Dy^2=\pm 1$.

Khi $D\equiv 0\pmod 4$, trong nghiệm $(x,y)$ của phương trình
$x^2-Dy^2=\pm 4$, $x$ nhất định chẵn nhưng $y$ có thể lẻ. Nếu trong nghiệm
nguyên dương nhỏ nhất $(x_1,y_1)$ của phương trình $x^2-Dy^2=\pm 4$, $y_1$
chẵn, thì trong mọi nghiệm $y$ cũng nhất định chẵn; khi đó các nghiệm nguyên này
tương ứng một-một với nghiệm nguyên của $x^2-Dy^2=\pm 1$. Nhưng nếu trong
nghiệm nguyên nhỏ nhất $(x_1,y_1)$, $y_1$ lẻ, thì tính chẵn lẻ của $y_k$ sẽ
trùng với tính chẵn lẻ của $k$ và thay đổi xen kẽ; vì vậy chỉ khi $k$ chẵn mới
tương ứng với nghiệm của $x^2-Dy^2=\pm 1$. Nếu trong nghiệm nguyên dương nhỏ
nhất của $x^2-Dy^2=\pm 4$, $y_1$ lẻ và chuẩn của $x_1+y_1\sqrt{D}$ là $-4$, thì
với $D$ như vậy, $x^2-Dy^2=-4$ có nghiệm nhưng $x^2-Dy^2=-1$ vô nghiệm.

Khi $D\equiv 1\pmod 4$, nghiệm $(x,y)$ của phương trình $x^2-Dy^2=\pm 4$ có thể
đồng thời lẻ, cũng có thể đồng thời chẵn. Nếu nghiệm nguyên dương nhỏ nhất
$(x_1,y_1)$ đã đồng thời chẵn, thì mọi nghiệm nguyên của nó cũng nhất định đồng
thời chẵn, nên luôn tương ứng với nghiệm nguyên của phương trình
$x^2-Dy^2=\pm 1$. Nếu nghiệm nguyên dương nhỏ nhất $(x_1,y_1)$ đồng thời lẻ, ta
có kết quả sau:

???+ note "Định lý"
    Giả sử nghiệm nguyên dương nhỏ nhất của phương trình $x^2-Dy^2=\pm 4$ là
    $(x_1,y_1)$. Nếu $x_1$ và $y_1$ đồng thời lẻ, thì $D\equiv 5\pmod 8$, và
    nghiệm nguyên $(x,y)$ của phương trình đó đồng thời chẵn khi và chỉ khi

    $$
    \dfrac{x+y\sqrt{D}}{2} = \pm\left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^{3k},k\in\mathbf Z.
    $$

??? note "Chứng minh"
    Lấy modulo $8$ hai vế của đẳng thức $x_1^2-Dy_1^2=\pm 4$, ta được
    $D\equiv 5\pmod 8$. Để chứng minh kết quả thứ hai, trước hết chứng minh
    $(x_3,y_3)$ đều chẵn, vì

    $$
    \dfrac{x_3+y_3\sqrt{D}}{2} = \left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^{3} = \dfrac{x_1^3+3Dx_1y_1^2}{8}+\dfrac{3x_1^2y_1+Dy_1^3}{8}\sqrt{D},
    $$

    nên chỉ cần chứng minh vế phải là số nguyên. Vì bình phương của số lẻ đồng
    dư $1$ modulo $8$, ta có

    $$
    \begin{aligned}
    &x_1^3+3Dx_1y_1^2 = x_1(x_1^2+3Dy_1^2) \equiv x_1(1+3\times 5\times 1) = 16x_1 = 0 \pmod 8,\\
    &3x_1^2y_1+Dy_1^3 = y_1(3x_1^2+Dy_1^2) \equiv y_1(3\times 1+5\times 1) = 8y_1 = 0 \pmod 8.
    \end{aligned}
    $$

    Điều này cho thấy $x_3,y_3$ đều chẵn. Do đó, với mọi $k\in\mathbf Z$,

    $$
    \dfrac{x+y\sqrt{D}}{2} = \pm\left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^{3k} = \pm\left(\dfrac{x_3+y_3\sqrt{D}}{2}\right)^k \in \mathbf Z[\sqrt D],
    $$

    nên $(x,y)$ khi đó đều chẵn. Ngược lại, với $r=1,2$, luôn có

    $$
    \pm\left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^{3k+r} = \pm\left(\dfrac{x_3+y_3\sqrt{D}}{2}\right)^k\left(\dfrac{x_r+y_r\sqrt{D}}{2}\right).
    $$

    Để chứng minh $(x,y)$ tương ứng không phải cặp số nguyên đồng thời chẵn, chỉ
    cần chứng minh biểu thức này không thuộc $\mathbf Z[\sqrt D]$, tức thừa số
    thứ hai trong tích bên phải không thuộc $\mathbf Z[\sqrt D]$. Với $r=1$ đây
    là giả thiết; với $r=2$, vì

    $$
    \dfrac{x_2+y_2\sqrt{D}}{2} = \left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^2 = \dfrac{x_1^2+Dy_1^2}{4} + \dfrac{x_1y_1}{2}\sqrt{D},
    $$

    và $x_1^2+Dy_1^2\equiv 1+1\times 1=2\pmod 4$, $x_1y_1\equiv 1\pmod 2$,
    nên biểu thức này cũng không thuộc $\mathbf Z[\sqrt D]$. Vậy chỉ khi số mũ
    là bội của $3$, nghiệm tương ứng mới đều chẵn.

Nói cách khác, trong mỗi ba nghiệm của phương trình $x^2-Dy^2=\pm 4$ có một
nghiệm đồng thời chẵn, và nó tương ứng với nghiệm nguyên của $x^2-Dy^2=\pm 1$.
Điều này cũng cho thấy với $D\equiv 1\pmod 4$, phương trình $x^2-Dy^2=-4$ có
nghiệm khi và chỉ khi phương trình $x^2-Dy^2=-1$ có nghiệm.

Đến đây, các thảo luận đã đủ để tính đơn vị cơ bản của vành số nguyên bậc hai
thực. Giả sử $D$ là số nguyên dương không chứa nhân tử chính phương. Với
$D\equiv 2,3\pmod 4$, chỉ cần tìm nghiệm nguyên dương nhỏ nhất của
$x^2-Dy^2=\pm 1$; còn với $D\equiv 1\pmod 4$, chỉ cần tìm nghiệm nguyên dương
nhỏ nhất của $x^2-Dy^2=\pm 4$. Khi thu được nghiệm nguyên dương nhỏ nhất
$(x,y)$, với $D\equiv 2,3\pmod 4$, đơn vị cơ bản là $\pm x\pm y\sqrt{D}$; với
$D\equiv 1\pmod 4$, đơn vị cơ bản là $\dfrac{\pm x\pm y\sqrt{D}}{2}$.

??? example "Ví dụ"
    1.  Giải phương trình $x^2-14y^2=\pm 4$.

        Từ kết quả tính toán trong ví dụ ở trên, nghiệm nguyên dương nhỏ nhất
        của phương trình $x^2-14y^2=4$ là $(30,8)$, còn phương trình
        $x^2-14y^2=-4$ vô nghiệm.
    2.  Giải phương trình $x^2-41y^2=\pm 4$.

        Chạy thuật toán PQa với $(P_0,Q_0,D)=(1,2,41)$ cho kết quả sau: (phần
        màu đỏ là chu kỳ đầu tiên)

        |  $k$ | $P$ | $Q$ |        $a$       |   $A$   |   $B$  |   $G$   | $G^2-DB^2$ |
        | :--: | :-: | :-: | :--------------: | :-----: | :----: | :-----: | :--------: |
        |  $0$ | $1$ | $2$ |        $3$       |   $3$   |   $1$  |   $5$   |    $-16$   |
        |  $1$ | $5$ | $8$ | $\color{red}{1}$ |   $4$   |   $1$  |   $7$   |     $8$    |
        |  $2$ | $3$ | $4$ | $\color{red}{2}$ |   $11$  |   $3$  |   $19$  |    $-8$    |
        |  $3$ | $5$ | $4$ | $\color{red}{2}$ |   $26$  |   $7$  |   $45$  |    $16$    |
        |  $4$ | $3$ | $8$ | $\color{red}{1}$ |   $37$  |  $10$  |   $64$  |    $-4$    |
        |  $5$ | $5$ | $2$ | $\color{red}{5}$ |  $211$  |  $57$  |  $365$  |    $16$    |
        |  $6$ | $5$ | $8$ |        $1$       |  $248$  |  $67$  |  $429$  |    $-8$    |
        |  $7$ | $3$ | $4$ |        $2$       |  $707$  |  $191$ |  $1223$ |     $8$    |
        |  $8$ | $5$ | $4$ |        $2$       |  $1662$ |  $449$ |  $2875$ |    $-16$   |
        |  $9$ | $3$ | $8$ |        $1$       |  $2369$ |  $640$ |  $4098$ |     $4$    |
        | $10$ | $5$ | $2$ |        $5$       | $13507$ | $3649$ | $23365$ |    $-16$   |
        | $11$ | $5$ | $8$ |        $1$       | $15876$ | $4289$ | $27463$ |     $8$    |

        Độ dài chu kỳ $\ell=5$ là lẻ. Nghiệm nguyên dương nhỏ nhất của phương
        trình $x^2-41y^2=-4$ là $(G_4,B_4)=(64,10)$, và nghiệm nguyên dương nhỏ
        nhất của phương trình $x^2-41y^2=4$ là $(G_9,B_9)=(4098,640)$. Giữa
        chúng có quan hệ

        $$
        \dfrac{4098+640\sqrt{41}}{2} = \left(\dfrac{64+10\sqrt{41}}{2}\right)^2.
        $$

        Tất nhiên, vì $D\equiv 1\pmod 8$, theo kết quả ở trên, nghiệm nguyên
        dương nhỏ nhất của phương trình $x^2-41y^2=\pm 4$ khi đó nhất định đều
        chẵn, và luôn bằng hai lần nghiệm nguyên dương nhỏ nhất của
        $x^2-41y^2=\pm 1$; do đó cũng có thể suy trực tiếp từ ví dụ trước.
    3.  Giải phương trình $x^2-13y^2=\pm 4$.

        Chạy thuật toán PQa với $(P_0,Q_0,D)=(1,2,13)$ cho kết quả sau: (phần
        màu đỏ là chu kỳ đầu tiên)

        | $k$ | $P$ | $Q$ |        $a$       |  $A$ |  $B$ |  $G$  | $G^2-DB^2$ |
        | :-: | :-: | :-: | :--------------: | :--: | :--: | :---: | :--------: |
        | $0$ | $1$ | $2$ |        $2$       |  $2$ |  $1$ |  $3$  |    $-4$    |
        | $1$ | $3$ | $2$ | $\color{red}{3}$ |  $7$ |  $3$ |  $11$ |     $4$    |
        | $2$ | $3$ | $2$ |        $3$       | $23$ | $10$ |  $36$ |    $-4$    |
        | $3$ | $3$ | $2$ |        $3$       | $74$ | $33$ | $119$ |     $4$    |

        Độ dài chu kỳ $\ell=1$ là lẻ. Nghiệm nguyên dương nhỏ nhất của phương
        trình $x^2-13y^2=-4$ là $(G_0,B_0)=(3,1)$, và nghiệm nguyên dương nhỏ
        nhất của phương trình $x^2-13y^2=4$ là $(G_1,B_1)=(11,3)$.

        Vì nghiệm nguyên dương nhỏ nhất của phương trình này đều lẻ, có thể dùng
        cặp tại cuối chu kỳ thứ ba $(G_2,B_2)=(36,10)$ để thu được nghiệm nguyên
        dương nhỏ nhất $(18,5)$ của phương trình Pell âm tương ứng
        $x^2-13y^2=\pm 1$. Điều này cũng có thể tính trực tiếp:

        $$
        \dfrac{36+10\sqrt{13}}{2}=\left(\dfrac{3+\sqrt{13}}{2}\right)^3.
        $$

        Hơn nữa, đây là nghiệm của phương trình Pell âm. Nghiệm nguyên dương nhỏ
        nhất của phương trình Pell tương ứng là $(649,180)$.
    4.  Giải phương trình $x^2-52y^2=\pm 4$.

        Vì nghiệm nguyên dương nhỏ nhất của phương trình $x^2-13y^2=\pm 1$ lần
        lượt là $(18,5)$ và $(649,180)$, nên nghiệm nguyên dương nhỏ nhất của
        phương trình $x^2-52y^2=\pm 4$ lần lượt là $(36,10)$ và $(1298,360)$.

<span id="trường-hợp-tổng-quát"></span>
### Trường hợp tổng quát

Cuối cùng, ta thảo luận cách giải phương trình Pell tổng quát.

Với trường hợp $|N|<\sqrt{D}$ có một cách giải đơn giản. Kết quả ở trên cho
biết nghiệm $(x,y)$ của phương trình $x^2-Dy^2=N$ nhất định thỏa
$\dfrac{x}{y}$ bằng một phân số gần đúng nào đó của $\sqrt{D}$. Hơn nữa, theo
cấu trúc nghiệm đã thảo luận, mọi nghiệm cơ bản $(x,y)$ đều thỏa
$x+y\sqrt{D}$ không vượt quá nghiệm cơ bản $x_1+y_1\sqrt{D}$ của phương trình
Pell tương ứng $x^2-Dy^2=1$. Dùng tính đơn điệu của dãy mẫu số $B_k$ trong
thuật toán PQa, các nghiệm cơ bản này của phương trình Pell tổng quát nhất định
xuất hiện trước khi nghiệm cơ bản của phương trình Pell tương ứng xuất hiện. Vì
vậy, chỉ cần chạy thuật toán PQa với $(P_0,Q_0,D)=(0,1,D)$ cho đến khi
$Q_{\ell'}=1$ và $\ell'$ chẵn; trong quá trình đó, kiểm tra mỗi $(A_k,B_k)$
xuất hiện xem có tồn tại số nguyên $f$ sao cho

$$
A_k^2-DB_k^2 = (-1)^{k+1}Q_{k+1} = N/f^2
$$

hay không. Nếu có, ghi nhận $(fA_{k},fB_{k})$ là một nghiệm nguyên dương nhỏ
nhất. Tất cả các $(fA_k,fB_k)$ được ghi nhận trong quá trình này chính là toàn
bộ nghiệm nguyên dương nhỏ nhất của phương trình $x^2-Dy^2=N$. Dùng
$(A_{\ell'-1},B_{\ell'-1})$, tức nghiệm cơ bản của phương trình Pell tương ứng,
có thể sinh tất cả nghiệm của phương trình Pell tổng quát từ các nghiệm nguyên
dương nhỏ nhất vừa tìm được. Chú ý tùy theo độ dài chu kỳ $\ell$ chẵn hay lẻ,
$\ell'$ nói trên có thể là $\ell$ hoặc $2\ell$.

Với trường hợp $N$ tổng quát hơn, phương pháp trên không còn áp dụng. Trước hết,
liệt kê mọi $f>0$ sao cho $f^2\mid |N|$, đặt $m=N/f^2$, và liệt kê mọi nghiệm
$z$ của đồng dư $z^2\equiv D\pmod{|m|}$ thỏa $-|m|/2<z \le |m|/2$. Sau đó chạy
thuật toán PQa với $(P_0,Q_0,D)=(z,|m|,D)$ cho đến khi $Q_k=\pm 1$ hoặc đã kết
thúc một chu kỳ. Trong trường hợp thứ hai, phương trình liên quan đến cặp
$(f,z)$ này không có nghiệm. Trong trường hợp thứ nhất, cần kiểm tra thêm
$(-1)^kQ_k=N/|N|$ hay không. Nếu dấu phù hợp, $(fG_{k-1},fB_{k-1})$ là một
nghiệm của phương trình $x^2-Dy^2=N$. Nếu không, nó là nghiệm của phương trình
$x^2-Dy^2=-N$, và chỉ khi phương trình Pell âm tương ứng có nghiệm, mới có thể
ghép nó với nghiệm cơ bản của phương trình Pell âm tương ứng để thu nghiệm của
$x^2-Dy^2=N$. Sau khi duyệt hết mọi cặp $(f,z)$, ta thu được đúng một nghiệm
trong mỗi lớp tương đương của nghiệm phương trình $x^2-Dy^2=N$, và nghiệm này
là nghiệm cơ bản hoặc nghiệm nguyên dương nhỏ nhất của lớp đó. Dùng chúng và
nghiệm cơ bản của phương trình Pell tương ứng, có thể sinh tất cả nghiệm nguyên
của phương trình. Thuật toán này được gọi là **thuật toán Lagrange–Matthews–Mollin**.

Tính đúng đắn của thuật toán được bảo đảm bởi định lý sau:

???+ note "Định lý"
    Giả sử phương trình $x^2-Dy^2=N$ có nghiệm nguyên $(x,y)$ với
    $x\ge 0, y>0,\gcd(x,y)=1$. Đặt $Q_0=|N|$, khi đó $\gcd(Q_0,y)=1$. Giả sử
    $P_0$ là nghiệm của đồng dư $x\equiv -P_0y\pmod{Q_0}$ và
    $-Q_0/2<P_0\le Q_0/2$, đồng thời đặt số nguyên $X$ sao cho
    $x=Q_0X-P_0y$. Khi đó $P_0^2\equiv D\pmod{Q_0}$, $\dfrac{X}{y}$ là một phân
    số gần đúng $\dfrac{A_{k-1}}{B_{k-1}}$ của
    $\omega=\dfrac{P_0+\sqrt{D}}{Q_0}$, và $Q_k=(-1)^k\dfrac{N}{|N|}$.

??? note "Chứng minh"
    Dùng $x\equiv -P_0y\pmod{Q_0}$ và $x^2-Dy^2=N\equiv 0\pmod{Q_0}$, hiển
    nhiên có $P_0^2\equiv D\pmod{Q_0}$. Do đó

    $$
    P_0x+Dy\equiv -P_0^2y+Dy = (D-P_0^2)y\equiv 0\pmod{Q_0}.
    $$

    Từ đây có thể xét ma trận hệ số nguyên

    $$
    \begin{pmatrix}P & R \\ Q & S\end{pmatrix}
    =
    \begin{pmatrix}X & \dfrac{P_0x+Dy}{Q_0} \\ y & x\end{pmatrix}.
    $$

    Định thức của nó là

    $$
    PS-QR = \dfrac{x(x+P_0y)-y(P_0x+Dy)}{Q_0} = \dfrac{x^2-Dy^2}{Q_0} = \pm 1.
    $$

    Hơn nữa, đặt $\zeta =\sqrt{D} > 1$, ta có

    $$
    \dfrac{P\zeta+R}{Q\zeta+S} = \dfrac{(x+P_0y)\sqrt{D}+(P_0x+Dy)}{(x+y\sqrt{D})Q_0} = \dfrac{P_0+\sqrt{D}}{Q_0} = \omega.
    $$

    Tiếp theo chứng minh $\dfrac{P}{Q}$ là một phân số gần đúng của $\omega$.
    Giả sử $\dfrac{P}{Q}$ có [khai triển phân số liên tục](./continued-fraction.md#liên-phân-số-đơn-giản)

    $$
    \dfrac{P}{Q} = [a_0,a_1,\cdots,a_k]
    $$

    và $PS-QR = (-1)^{k-1}$. Nếu $\dfrac{p_k}{q_k}$ là phân số gần đúng thứ $k$
    của nó, thì $(p_k,q_k)=(P,Q)$, và theo [công thức sai phân của phân số gần đúng](./continued-fraction.md#ước-lượng-sai-số),
    $p_kq_{k-1}-q_kp_{k-1}=(-1)^{k-1}$. Điều này cho thấy

    $$
    p_k(S-q_{k-1}) = q_k(R-p_{k-1}).
    $$

    Xét từng trường hợp:

    -   Nếu $S=0$, dễ thấy $Q=R=1$, nên $\omega=P+\zeta^{-1}=[P,\zeta]$, do đó $\dfrac{P}{Q}=P$ là phân số gần đúng thứ $0$ của $\omega$;
    -   Nếu $Q=S>0$, thì $Q=S=1$ và $P-R=\pm 1$. Khi đó:
        -   Nếu $P=R+1$, thì $\omega=R+\dfrac{1}{1+\zeta^{-1}}=[R,1,\zeta]$, do đó $\dfrac{P}{Q}=\dfrac{R+1}{1}=[R,1]$ là phân số gần đúng thứ $1$ của $\omega$;
        -   Nếu $P=R-1$, thì $\omega=R-1+\dfrac{1}{1+\zeta}=[R-1,\zeta-1]$, do đó $\dfrac{P}{Q}=R-1$ là phân số gần đúng thứ $0$ của $\omega$;
    -   Nếu $Q\neq S>0$, thì vì $Q=q_k\mid(S-q_{k-1})$, luôn tồn tại số nguyên $\kappa$ sao cho $S=\kappa q_k+q_{k-1}$ và $R=\kappa p_k+p_{k-1}$. Vì $q_k\ge q_{k-1}$ và $S>0$, nên $\kappa\ge 0$. Do đó, $\omega=\dfrac{(\kappa+\zeta)p_k+p_{k-1}}{(\kappa+\zeta)q_k+q_{k-1}}=[a_0,a_1,\cdots,a_k,\kappa+\zeta]$, nên $\dfrac{P}{Q}$ là phân số gần đúng thứ $k$ của nó.

    Tóm lại, $\dfrac{X}{y}$ luôn là phân số gần đúng của
    $\omega=\dfrac{P_0+\sqrt{D}}{Q_0}$, và theo ký hiệu trong thuật toán PQa
    được viết là $\dfrac{A_{k-1}}{B_{k-1}}$. Khi đó
    $x=Q_0A_{k-1}-P_0B_{k-1}=G_{k-1}$. Vì
    $G_{k-1}^2-DB_{k-1}^2=(-1)^kQ_0Q_k$, suy ra
    $Q_k=(-1)^k\dfrac{N}{|N|}$.

Định lý này bảo đảm mọi nghiệm dương của phương trình đều nằm trong các phân số
gần đúng của số vô tỉ bậc hai tương ứng. Vì khi tính phân số gần đúng bằng thuật
toán PQa, một khi đi vào chu kỳ thì có thể bảo đảm các phân số gần đúng luôn
dương. Do đó, chỉ cần liệt kê mọi số vô tỉ bậc hai được điều kiện của định lý
cho phép, tính các phân số gần đúng của nó đến hết một chu kỳ, ta có thể tìm
được một nghiệm. Vì hai nghiệm xuất hiện trong các phân số gần đúng của cùng một
số vô tỉ bậc hai nhất định tương đương, nên khi thu được nghiệm đầu tiên thỏa
$(-1)^kQ_k=N/|N|$, thì không cần tính tiếp nữa. Khác với tất cả thuật toán
trước, ở đây chỉ số $k$ thỏa điều kiện có thể xuất hiện trước khi vào chu kỳ.

??? example "Ví dụ"
    1.  Giải phương trình $x^2-157y^2=12$.

        Vì $12^2<157$, chạy thuật toán PQa với $(P_0,Q_0,D)=(0,1,157)$ cho kết
        quả sau: (phần màu đỏ là chu kỳ đầu tiên)

        |  $k$ |  $P$ |  $Q$ |        $a$        |         $A$        |        $B$       |         $G$        | $G^2-DB^2$ |
        | :--: | :--: | :--: | :---------------: | :----------------: | :--------------: | :----------------: | :--------: |
        |  $0$ |  $0$ |  $1$ |        $12$       |        $12$        |        $1$       |        $12$        |    $-13$   |
        |  $1$ | $12$ | $13$ |   $\color{red}1$  |        $13$        |        $1$       |        $13$        |    $12$    |
        |  $2$ |  $1$ | $12$ |   $\color{red}1$  |        $25$        |        $2$       |        $25$        |    $-3$    |
        |  $3$ | $11$ |  $3$ |   $\color{red}7$  |        $188$       |       $15$       |        $188$       |    $19$    |
        |  $4$ | $10$ | $19$ |   $\color{red}1$  |        $213$       |       $17$       |        $213$       |    $-4$    |
        |  $5$ |  $9$ |  $4$ |   $\color{red}5$  |       $1253$       |       $100$      |       $1253$       |     $9$    |
        |  $6$ | $11$ |  $9$ |   $\color{red}2$  |       $2719$       |       $217$      |       $2719$       |    $-12$   |
        |  $7$ |  $7$ | $12$ |   $\color{red}1$  |       $3972$       |       $317$      |       $3972$       |    $11$    |
        |  $8$ |  $5$ | $11$ |   $\color{red}1$  |       $6691$       |       $534$      |       $6691$       |    $-11$   |
        |  $9$ |  $6$ | $11$ |   $\color{red}1$  |       $10663$      |       $851$      |       $10663$      |    $12$    |
        | $10$ |  $5$ | $12$ |   $\color{red}1$  |       $17354$      |      $1385$      |       $17354$      |    $-9$    |
        | $11$ |  $7$ |  $9$ |   $\color{red}2$  |       $45371$      |      $3621$      |       $45371$      |     $4$    |
        | $12$ | $11$ |  $4$ |   $\color{red}5$  |      $244209$      |      $19490$     |      $244209$      |    $-19$   |
        | $13$ |  $9$ | $19$ |   $\color{red}1$  |      $289580$      |      $23111$     |      $289580$      |     $3$    |
        | $14$ | $10$ |  $3$ |   $\color{red}7$  |      $2271269$     |     $181267$     |      $2271269$     |    $-12$   |
        | $15$ | $11$ | $12$ |   $\color{red}1$  |      $2560849$     |     $204378$     |      $2560849$     |    $13$    |
        | $16$ |  $1$ | $13$ |   $\color{red}1$  |      $4832118$     |     $385645$     |      $4832118$     |    $-1$    |
        | $17$ | $12$ |  $1$ | $\color{red}{24}$ |     $118531681$    |     $9459858$    |     $118531681$    |    $13$    |
        | $18$ | $12$ | $13$ |        $1$        |     $123363799$    |     $9845503$    |     $123363799$    |    $-12$   |
        | $19$ |  $1$ | $12$ |        $1$        |     $241895480$    |    $19305361$    |     $241895480$    |     $3$    |
        | $20$ | $11$ |  $3$ |        $7$        |    $1816632159$    |    $144983030$   |    $1816632159$    |    $-19$   |
        | $21$ | $10$ | $19$ |        $1$        |    $2058527639$    |    $164288391$   |    $2058527639$    |     $4$    |
        | $22$ |  $9$ |  $4$ |        $5$        |    $12109270354$   |    $966424985$   |    $12109270354$   |    $-9$    |
        | $23$ | $11$ |  $9$ |        $2$        |    $26277068347$   |   $2097138361$   |    $26277068347$   |    $12$    |
        | $24$ |  $7$ | $12$ |        $1$        |    $38386338701$   |   $3063563346$   |    $38386338701$   |    $-11$   |
        | $25$ |  $5$ | $11$ |        $1$        |    $64663407048$   |   $5160701707$   |    $64663407048$   |    $11$    |
        | $26$ |  $6$ | $11$ |        $1$        |   $103049745749$   |   $8224265053$   |   $103049745749$   |    $-12$   |
        | $27$ |  $5$ | $12$ |        $1$        |   $167713152797$   |   $13384966760$  |   $167713152797$   |     $9$    |
        | $28$ |  $7$ |  $9$ |        $2$        |   $438476051343$   |   $34994198573$  |   $438476051343$   |    $-4$    |
        | $29$ | $11$ |  $4$ |        $5$        |   $2360093409512$  |  $188355959625$  |   $2360093409512$  |    $19$    |
        | $30$ |  $9$ | $19$ |        $1$        |   $2798569460855$  |  $223350158198$  |   $2798569460855$  |    $-3$    |
        | $31$ | $10$ |  $3$ |        $7$        |  $21950079635497$  |  $1751807067011$ |  $21950079635497$  |    $12$    |
        | $32$ | $11$ | $12$ |        $1$        |  $24748649096352$  |  $1975157225209$ |  $24748649096352$  |    $-13$   |
        | $33$ |  $1$ | $13$ |        $1$        |  $46698728731849$  |  $3726964292220$ |  $46698728731849$  |     $1$    |
        | $34$ | $12$ |  $1$ |        $24$       | $1145518138660728$ | $91422300238489$ | $1145518138660728$ |    $-13$   |
        | $35$ | $12$ | $13$ |        $1$        | $1192216867392577$ | $95149264530709$ | $1192216867392577$ |    $12$    |

        Độ dài chu kỳ $\ell=17$ là lẻ, nên cần xét trong hai chu kỳ các trường hợp mà $G_{k-1}^2-157B_{k-1}^2 = 12/f^2$ với $f^2\mid 12$, tức các trường hợp $k=1,9,13,19,23,31$. Các nghiệm tương ứng là $(fG,fB)$ trong bảng sau:

        |  $k$ | $f$ |    $fG_{k-1}$    |    $fB_{k-1}$   |    $x$    |   $y$   |
        | :--: | :-: | :--------------: | :-------------: | :-------: | :-----: |
        |  $1$ | $1$ |       $13$       |       $1$       |    $13$   |   $1$   |
        |  $9$ | $1$ |      $10663$     |      $851$      |  $10663$  |  $851$  |
        | $13$ | $2$ |     $579160$     |     $46222$     |  $579160$ | $46222$ |
        | $19$ | $2$ |    $483790960$   |    $38610722$   | $-579160$ | $46222$ |
        | $23$ | $1$ |   $26277068347$  |   $2097138361$  |  $-10663$ |  $851$  |
        | $31$ | $1$ | $21950079635497$ | $1751807067011$ |   $-13$   |   $1$   |

        Tất cả $(fG,fB)$ chính là các nghiệm nguyên dương nhỏ nhất trong mỗi lớp tương đương của tập nghiệm phương trình $x^2-157y^2=12$. Để thu tất cả nghiệm từ chúng, có thể dùng nghiệm cơ bản $(46698728731849,3726964292220)$ của phương trình Pell tương ứng. Chẳng hạn, có thể chuyển chúng thành nghiệm cơ bản $(x,y)$ của lớp tương đương đó; các nghiệm tương ứng cũng được liệt kê trong bảng trên.
    2.  Giải phương trình $x^2-157y^2=12$.

        Lần này dùng thuật toán Lagrange–Matthews–Mollin. Trước hết, liệt kê các nhân tử chính phương của $N=12$:

        -   Khi $f^2=1^2$, có $m=12$, đồng dư $P^2\equiv 157\pmod{12}$ có nghiệm $z=\pm 1,\pm 5$;
        -   Khi $f^2=2^2$, có $m=3$, đồng dư $P^2\equiv 157\pmod{3}$ có nghiệm $z=\pm 1$.

        Với mọi tổ hợp $(f,z)$ có thể, chạy thuật toán PQa với tham số đầu $(P_0,Q_0,D)=(z,|m|,D)$ và tìm vị trí đầu tiên có $(-1)^kQ_k=1$; $(fG_{k-1},fB_{k-1})$ tương ứng là một nghiệm. Kết quả như bảng sau:

        | $f$ |  $z$ |  $m$ |  $k$ |    $fG_{k-1}$    |    $fB_{k-1}$   |
        | :-: | :--: | :--: | :--: | :--------------: | :-------------: |
        | $1$ |  $1$ | $12$ | $32$ | $21950079635497$ | $1751807067011$ |
        | $1$ | $-1$ | $12$ |  $2$ |       $13$       |       $1$       |
        | $1$ |  $5$ | $12$ | $24$ |   $26277068347$  |   $2097138361$  |
        | $1$ | $-5$ | $12$ | $10$ |      $10663$     |      $851$      |
        | $2$ |  $1$ |  $3$ | $20$ |    $483790960$   |    $38610722$   |
        | $2$ | $-1$ |  $3$ | $14$ |     $579160$     |     $46222$     |

        Đây chính là các nghiệm nguyên dương nhỏ nhất trong mỗi lớp tương đương đã liệt kê ở trên; có thể dùng nghiệm cơ bản của phương trình Pell để chuyển chúng thành nghiệm cơ bản.
    3.  Giải phương trình $x^2-79y^2=\pm 101$.

        Vẫn dùng thuật toán Lagrange–Matthews–Mollin. Vì $N=101$ là số nguyên tố, nhất định $f=1$. Khi đó $m=101$, và đồng dư tương ứng $P^2\equiv 79\pmod{101}$ có nghiệm $P=\pm 33$.

        Chạy thuật toán PQa với $(P_0,Q_0,D)=(33,101,79)$ cho kết quả sau: (phần màu đỏ là chu kỳ đầu tiên)

        | $k$ |  $P$  |  $Q$  |       $a$      |  $A$  |   $B$  |   $G$   | $G^2-DB^2$ |
        | :-: | :---: | :---: | :------------: | :---: | :----: | :-----: | :--------: |
        | $0$ |  $33$ | $101$ |       $0$      |  $0$  |   $1$  |  $-33$  |   $1010$   |
        | $1$ | $-33$ | $-10$ |       $2$      |  $1$  |   $2$  |   $35$  |    $909$   |
        | $2$ |  $13$ |  $9$  |       $2$      |  $2$  |   $5$  |   $37$  |   $-606$   |
        | $3$ |  $5$  |  $6$  | $\color{red}2$ |  $5$  |  $12$  |  $109$  |    $505$   |
        | $4$ |  $7$  |  $5$  | $\color{red}3$ |  $17$ |  $41$  |  $364$  |   $-303$   |
        | $5$ |  $8$  |  $3$  | $\color{red}5$ |  $90$ |  $217$ |  $1929$ |   $1010$   |
        | $6$ |  $7$  |  $10$ | $\color{red}1$ | $107$ |  $258$ |  $2293$ |   $-707$   |
        | $7$ |  $3$  |  $7$  | $\color{red}1$ | $197$ |  $475$ |  $4222$ |    $909$   |
        | $8$ |  $4$  |  $9$  | $\color{red}1$ | $304$ |  $733$ |  $6515$ |   $-606$   |
        | $9$ |  $5$  |  $6$  |       $2$      | $805$ | $1941$ | $17252$ |    $505$   |

        Độ dài chu kỳ $\ell=6$ là chẵn. Đến hết một chu kỳ vẫn không tồn tại $Q_k=\pm 1$, nên trường hợp này vô nghiệm. Tương tự, chạy thuật toán PQa với $(P_0,Q_0,D)=(-33,101,79)$ cũng quan sát được tình huống giống vậy. Vì thế phương trình vô nghiệm.

<span id="bài-tập"></span>
## Bài tập

-   [LOJ 6687. Project Euler 66 - Giải phương trình](https://loj.ac/p/6687)
-   [SPOJ EQU2 - Yet Another Equation](https://www.spoj.com/problems/EQU2/)
-   [SPOJ PELL2 - Pell (Mid pelling)](https://www.spoj.com/problems/PELL2/)
-   [UVa 12909. Numeric Center](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=862&page=show_problem&problem=4774)
-   [UVa 10241. Semi-triangular and also Square](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1182)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [Pell's equation - Wikipedia](https://en.wikipedia.org/wiki/Pell%27s_equation)
-   [John P. Robertson - Solving the generalized Pell equation $x^2-Dy^2=N$](https://citeseerx.ist.psu.edu/document?repid=rep1&type=pdf&doi=5ac34a344ee346855184ff949eeaed18685b155c)
-   [Keith Matthews - The Diophantine Equation $x^2-Dy^2=N$,$D>0$](http://www.numbertheory.org/PDFS/patz5.pdf)
-   [Existence of Solution to Pell's Equation - Suryateja Gavva's Blog](https://surya-teja.com/2011/01/11/existence-of-solution-to-pells-equation/)
-   [Calculating the simple continued fraction of a quadratic irrational - Number Theory Web](http://www.numbertheory.org/php/surd.html) (thuật toán PQa)
-   [Solving the diophantine equation x2-Dy2 = N, D > 0 and not a perfect square, N != 0 - Number Theory Web](http://www.numbertheory.org/php/patz.html) (thuật toán Lagrange–Matthews–Mollin)

[^not-square]: Khi $D$ là số chính phương, chỉ cần phân tích nhân tử là biết $(x+y\sqrt{D})(x-y\sqrt{D})=N$, vì vậy mọi nghiệm có thể tìm bằng cách duyệt các ước của $N$. Đặc biệt, khi $N=1$, phương trình chỉ có nghiệm $(\pm 1,0)$; khi $N=-1$ và $D\neq 1$, phương trình vô nghiệm.

[^neg-pell]: Một số tài liệu tiếng Trung cũng gọi nó là phương trình Pell loại hai.

[^half-int]: Tức số hữu tỉ có dạng $n+\dfrac12$ với $n\in\mathbf Z$.

[^fundamental-solution]: Chú ý định nghĩa nghiệm cơ bản trong phương trình Pell không trùng với định nghĩa đơn vị cơ bản trong vành số nguyên bậc hai thực. Trước hết, trong một số vành số nguyên bậc hai thực, đơn vị cơ bản $x+y\sqrt{D}$ có $x,y$ là bán nguyên, nên không phải nghiệm của phương trình Pell. Tiếp theo, cùng một vành số nguyên bậc hai thực có bốn đơn vị cơ bản, nhưng nghiệm cơ bản chỉ có một, vì nghiệm cơ bản yêu cầu $x,y$ đều dương.

[^solubility-neg-pell]: Một phương pháp và công cụ phán định khá thực dụng nằm ở [đây](http://www.numbertheory.org/php/hardy_williams.html) và trong tài liệu tham khảo của nó. Danh sách các số nguyên dương $D$ sao cho phương trình $x^2-Dy^2=-1$ có nghiệm là [OEIS A031396](https://oeis.org/A031396).
