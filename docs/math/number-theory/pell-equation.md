Kiến thức nền: [phân số liên tục](./continued-fraction.md), [trường bậc hai](./quadratic.md)

<span id="&#x5f15;&#x5165;"></span>
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

<span id="&#x89e3;&#x7684;&#x7ed3;&#x6784;"></span>
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
thêm trường hợp $N=\pm 4$. [Phần dưới](#%E8%8C%83%E6%95%B0%E4%B8%BA-4-%E7%9A%84%E6%83%85%E5%BD%A2)
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

<span id="pell-&#x65b9;&#x7a0b;"></span>
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
    Trước hết, [định lý Dirichlet](./continued-fraction.md#%E7%94%A8%E6%B8%90%E8%BF%91%E5%88%86%E6%95%B0%E9%80%BC%E8%BF%91%E5%AE%9E%E6%95%B0)
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

<span id="&#x5e7f;&#x4e49;-pell-&#x65b9;&#x7a0b;"></span>
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

<span id="&#x6c42;&#x89e3;&#x65b9;&#x6cd5;"></span>
## Phương pháp giải

Việc giải phương trình Pell và phương trình Pell tổng quát đều có thể dựa trên
phân số liên tục.

<span id="pqa-&#x7b97;&#x6cd5;"></span>
### Thuật toán PQa

Những thuật toán được thảo luận trong bài này đều dựa trên thuật toán PQa, dùng
để tìm khai triển phân số liên tục của một số vô tỉ bậc hai cụ thể.

Giả sử các số nguyên $P_0,Q_0,D$ thỏa mãn $Q_0\neq 0$, $D>0$ không phải số chính
phương, và $P_0^2\equiv D\pmod{Q_0}$. Khi đó số vô tỉ bậc hai

$$
\omega=\dfrac{P_0+\sqrt{D}}{Q_0}
$$

có khai triển phân số liên tục $[a_0,a_1,\cdots]$ tính được bằng
[công thức truy hồi](./continued-fraction.md#%E4%BA%8C%E6%AC%A1%E6%97%A0%E7%90%86%E6%95%B0)
sau:

$$
a_k = \left\lfloor\dfrac{P_k+\sqrt{D}}{Q_k}\right\rfloor,\ P_{k+1} = a_kQ_k - P_k,\ Q_{k+1} = \dfrac{D-P_{k+1}^2}{Q_k}.
$$

Tiếp theo, tử số và mẫu số $A_k$ và $B_k$ của phân số gần đúng thứ $k$ của
$\omega$ được cho bởi [công thức truy hồi](./continued-fraction.md#%E9%80%92%E6%8E%A8%E5%85%B3%E7%B3%BB)

$$
A_k = a_kA_{k-1} + A_{k-2},\ B_k = a_kB_{k-1} + B_{k-2}
$$

với $A_{-1} = 1$, $A_{-2}=0$, $B_{-1}=0$, $B_{-2}=1$.

Tính đúng đắn của các công thức này đã được chứng minh trong bài phân số liên
tục. Ở đó cũng đã giải thích rằng vì số vô tỉ bậc hai là
[phân số liên tục tuần hoàn](./continued-fraction.md#%E4%BA%8C%E6%AC%A1%E6%97%A0%E7%90%86%E6%95%B0),
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

    Bước cuối dùng [công thức sai phân](./continued-fraction.md#%E8%AF%AF%E5%B7%AE%E4%BC%B0%E8%AE%A1)
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

<span id="pell-&#x65b9;&#x7a0b;_1"></span>
### Phuong trinh Pell

De giai phuong trinh Pell $x^2-Dy^2=1$, chi can chay thuat toan PQa voi $(P_0,Q_0,D)=(0,1,D)$ cho den khi xuat hien $(-1)^kQ_k=1$; khi do $(A_{k-1},B_{k-1})$ la mot nghiem cua phuong trinh Pell (vi luc nay $G_{k-1}$ chinh la $A_{k-1}$). Di nhien, voi phuong trinh Pell, co the mo ta qua trinh nay chinh xac hon.

Truoc het, nghiem nhat dinh xuat hien o cuoi chu ki. Qua trinh tren tuong duong voi khai trien phan so lien tuc cua $\sqrt{D}$. Ve dieu nay, da co [ket qua](./continued-fraction.md#%E7%BA%AF%E5%BE%AA%E7%8E%AF%E8%BF%9E%E5%88%86%E6%95%B0):

$$
\sqrt{D} = [\lfloor\sqrt{D}\rfloor,\overline{a_1,\cdots,a_{\ell-1},2\lfloor\sqrt{D}\rfloor}].
$$

O day do dai chu ki la $\ell$, va vi tri bat dau la hang thu $1$ (chi so bat dau tu $0$). Hon nua, thuong hoan toan thu $\ell$ cua no bang $\lfloor\sqrt{D}\rfloor+\sqrt{D}$, cho thay $Q_{\ell}=1$. Do do, neu $\ell$ chan thi $(A_{\ell-1},B_{\ell-1})$ la mot nghiem khong tam thuong cua phuong trinh Pell; neu $\ell$ le thi $(A_{2\ell-1},B_{2\ell-1})$ la mot nghiem khong tam thuong cua phuong trinh Pell.

Tiep theo can chi ra nghiem vua thu duoc nhat dinh la nghiem co ban. Ket qua nay dua tren hai ly do: thu nhat, moi nghiem nguyen duong $(x,y)$ cua phuong trinh Pell deu co phan so $x/y$ xuat hien trong cac phan so gan dung cua $\sqrt{D}$, dam bao $(x,y)$ nhat dinh la mot $(A_k,B_k)$ nao do trong qua trinh PQa; thu hai, ngoai cuoi chu ki se khong co vi tri nao khac co $Q_k=1$, vi he thuc truy hoi cua $A_k$ va $B_k$ dam bao kich thuoc cua chung tang theo chi so, nen nghiem nguyen duong nho nhat (tuc nghiem co ban) nhat dinh xuat hien tai vi tri vua chi ra. Hai ly do nay lan luot suy ra tu hai dinh li sau:

???+ note "Dinh li"
    Gia su phuong trinh $x^2-Dy^2=N$ co nghiem nguyen duong $(x,y)$. Neu $|N|<\sqrt{D}$, thi $\dfrac{x}{y}$ nhat dinh la mot phan so gan dung cua $\sqrt{D}$.

??? note "Chung minh"
    Khi $N>0$, vi $x^2-Dy^2>0$, nen $x>y\sqrt{D}$. Do do

    $$
    \left|\dfrac{x}{y}-\sqrt{D}\right| = \dfrac{N}{y(x+y\sqrt{D})}<\dfrac{N}{2y^2\sqrt{D}}<\dfrac{1}{2y^2}.
    $$

    Theo [tieu chuan Legendre](./continued-fraction.md#%E6%B8%90%E8%BF%91%E5%88%86%E6%95%B0%E7%9A%84%E5%88%A4%E5%AE%9A), $\dfrac{x}{y}$ la phan so gan dung cua $\sqrt{D}$.

    Khi $N<0$, bat dang thuc $x>y\sqrt{D}$ khong con dung. Do do xet phuong trinh $y^2-\dfrac{1}{D}x^2=-\dfrac{N}{D}$. Vi $\dfrac{|N|}{D}<\sqrt{\dfrac{1}{D}}$, lap lai lap luan tren van dung. Dieu nay cho thay $\dfrac{y}{x}$ la phan so gan dung cua $\dfrac{1}{\sqrt{D}}$. Theo [dinh li nghich dao](./continued-fraction.md#%E9%80%92%E6%8E%A8%E5%85%B3%E7%B3%BB), $\dfrac{x}{y}$ cung la phan so gan dung cua $\sqrt{D}$.

???+ note "Dinh li"
    Trong qua trinh chay thuat toan PQa o tren voi $(P_0,Q_0,D)=(0,1,D)$, $Q_k=1$ nhat dinh keo theo $\ell\mid k$.

??? note "Chung minh"
    Trong khai trien phan so lien tuc cua $\sqrt{D}$, ngoai thuong hoan toan thu $0$, moi thuong hoan toan khac deu la [phan so lien tuc thuan tuan hoan](./continued-fraction.md#%E7%BA%AF%E5%BE%AA%E7%8E%AF%E8%BF%9E%E5%88%86%E6%95%B0). Gia su $Q_k=1$. Theo ket qua cua Galois, nhat dinh co thuong hoan toan $\omega_k=P_k+\sqrt{D}>1$, va lien hop cua no $-1<P_k-\sqrt{D}<0$, suy ra $P_k=\lfloor\sqrt{D}\rfloor$. Do do thuong hoan toan $\omega_k$ bang $\omega_\ell$. Nhung su lap lai cua thuong hoan toan co nghia phan so lien tuc vao chu ki; neu $k$ khong phai boi cua $\ell$, dieu nay mau thuan voi viec $\ell$ la chu ki duong nho nhat. Vi vay nhat dinh $\ell\mid k$.

Tong hop thao luan trong phan nay: chi can khai trien phan so lien tuc cua $\sqrt{D}$, tuc chay thuat toan PQa tu $(P_0,Q_0,D)=(0,1,D)$; khi lan dau co $Q_\ell=1$ thi da den cuoi chu ki dau tien. Neu $\ell$ chan, $(A_{\ell-1},B_{\ell-1})$ la nghiem co ban cua phuong trinh Pell; neu khong, $(A_{2\ell-1},B_{2\ell-1})$ la nghiem co ban cua phuong trinh Pell. Khi do dai chu ki $\ell$ le, khong can tiep tuc PQa den hai lan chu ki, vi ngay sau day se thay $A_{2\ell-1}+B_{2\ell-1}\sqrt{D}=(A_{\ell-1}+B_{\ell-1}\sqrt{D})^2$, nen co the tinh truc tiep nghiem co ban cua phuong trinh Pell tu $(A_{\ell-1},B_{\ell-1})$. Moi nghiem khac cua phuong trinh Pell deu co the tinh tu nghiem co ban.

??? example "Vi du"
    1.  Giai phuong trinh $x^2-14y^2=1$.

        Chay thuat toan PQa voi $(P_0,Q_0,D)=(0,1,14)$ cho ket qua sau: (phan mau do la chu ki dau tien)

        | $k$ | $P$ | $Q$ |        $a$       |  $A$  |  $B$ |  $G$  | $G^2-DB^2$ |
        | :-: | :-: | :-: | :--------------: | :---: | :--: | :---: | :--------: |
        | $0$ | $0$ | $1$ |        $3$       |  $3$  |  $1$ |  $3$  |    $-5$    |
        | $1$ | $3$ | $5$ | $\color{red}{1}$ |  $4$  |  $1$ |  $4$  |     $2$    |
        | $2$ | $2$ | $2$ | $\color{red}{2}$ |  $11$ |  $3$ |  $11$ |    $-5$    |
        | $3$ | $2$ | $5$ | $\color{red}{1}$ |  $15$ |  $4$ |  $15$ |     $1$    |
        | $4$ | $3$ | $1$ | $\color{red}{6}$ | $101$ | $27$ | $101$ |    $-5$    |
        | $5$ | $3$ | $5$ |        $1$       | $116$ | $31$ | $116$ |     $2$    |

        Do dai chu ki $\ell=4$ la chan. Nghiem nguyen duong nho nhat cua phuong trinh la $(G_3,B_3)=(15,4)$.
    2.  Giai phuong trinh $x^2-41y^2=1$.

        Chay thuat toan PQa voi $(P_0,Q_0,D)=(0,1,41)$ cho ket qua sau: (phan mau do la chu ki dau tien)

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

        Do dai chu ki $\ell=3$ la le. Nghiem nguyen duong nho nhat cua phuong trinh la $(G_5,B_5)=(2049,320)$. No cung co the duoc tinh tu $(G_2,B_2)=(32,5)$:

        $$
        (32+5\sqrt{41})^2=2049+320\sqrt{41}.
        $$

<span id="&#x8d1f;-pell-&#x65b9;&#x7a0b;"></span>
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

??? note "Chung minh"
    Truoc het, phuong trinh Pell am co nghiem co nghia $-1$ la thang du bac hai modulo $D$, nen $-1$ cung la thang du bac hai modulo moi uoc $d$ cua $D$; do do $d\neq 4$ va $d$ khong phai so nguyen to dang $4k+3$. Nguoc lai, phuong trinh $x^2-2y^2=-1$ co nghiem khong tam thuong $(1,1)$. Phan con lai la truong hop $D$ la so nguyen to dang $4k+1$.

    Gia su $D$ la so nguyen to dang $4k+1$, can chung minh phuong trinh $x^2-Dy^2=-1$ co nghiem. Y tuong la bat dau tu nghiem co ban $(u,v)$ cua phuong trinh Pell $x^2-Dy^2=1$, roi xay dung nghiem $(\alpha,\beta)$ cua $x^2-Dy^2=-1$. Neu $u$ chan, lay dong du hai ve cua $u^2-Dv^2=1$ modulo $4$ se duoc $v^2\equiv -1\pmod 4$, nhung $-1$ khong phai thang du bac hai modulo $4$. Mau thuan nay cho thay $u$ le. Xet dang thuc $Dv^2=u^2-1=(u+1)(u-1)$. Vi $u$ le, $\gcd(u+1,u-1)=\gcd(u+1,2)=2$. Dua vao dieu nay, khi phan bo cac thua so cua $Dv^2$ vao $u+1$ va $u-1$, nhat dinh mot trong hai la $2\alpha^2$, so con lai la $2D\beta^2$, trong do $\alpha$ va $\beta$ la cac so nguyen duong nguyen to cung nhau va $v=2\alpha\beta$. Thay $u=\alpha^2+D\beta^2$ va $v=2\alpha\beta$ vao $u^2-Dv^2=1$, ta duoc $\alpha^2-D\beta^2=\pm 1$. Vi $(u,v)$ la nghiem co ban cua phuong trinh Pell va $(\alpha,\beta)$ la cap so nguyen duong nho hon $(u,v)$, ve phai cua dang thuc nay khong the la $+1$, nen chi co the la $-1$. Dieu nay chung minh $x^2-Dy^2=-1$ co nghiem $(\alpha,\beta)$.

Neu $D$ la hop so, dieu kien khong chua thua so nguyen to dang $4k+3$ va khong chua nhan tu chinh phuong cung khong dam bao phuong trinh $x^2-Dy^2=-1$ co nghiem; chang han $x^2-34y^2=-1$ vo nghiem.

??? example "Vi du"
    Tu ket qua tinh toan trong cac vi du tren, phuong trinh $x^2-14y^2=-1$ vo nghiem, va nghiem nguyen duong nho nhat cua phuong trinh $x^2-41y^2=-1$ la $(G_2,B_2)=(32,5)$.

<span id="&#x8303;&#x6570;&#x4e3a;-4-&#x7684;&#x60c5;&#x5f62;"></span>
### Truong hop chuan bang ±4

Tiep theo thao luan nghiem cua phuong trinh $x^2-Dy^2=\pm 4$. Luc nay tinh chat cua nghiem phu thuoc vao gia tri cua $D\bmod 4$.

Mot so truong hop rat de xu li. Neu $D\equiv 0\pmod 4$, thi $x$ chan, nen $(x/2,y)$ la nghiem cua phuong trinh $u^2-(D/4)v^2=\pm 1$. Cac truong hop con lai, nhat dinh $x,y$ dong thoi le hoac dong thoi chan. Neu $x,y$ dong thoi le, lay modulo $4$ hai ve phuong trinh cho $D\equiv 1\pmod 4$. Vi vay, neu $D\equiv 2,3\pmod 4$, thi $x,y$ chi co the dong thoi chan, nen $(x/2,y/2)$ la nghiem cua phuong trinh $u^2-Dv^2=\pm 1$. Do do, ngoai tru truong hop $D\equiv 1\pmod 4$, nghiem cua phuong trinh $x^2-Dy^2=\pm 4$ deu co the thu duoc tu nghiem cua phuong trinh Pell (am) tuong ung.

Bay gio xet truong hop $D\equiv 1\pmod 4$; no khong the chuyen don gian ve cac truong hop da giai. De tim nghiem co ban, co the ap dung thuat toan PQa cho $(P_0,Q_0,D)=(1,2,D)$. Khi lan dau thu duoc $Q_\ell=2$, ta den cuoi chu ki dau tien. Neu do dai chu ki $\ell$ chan, $(G_{\ell-1},B_{\ell-1})$ la nghiem co ban cua phuong trinh $x^2-Dy^2=4$; neu khong, $(G_{\ell-1},B_{\ell-1})$ la nghiem co ban cua phuong trinh $x^2-Dy^2=-4$. Tu $(G_{\ell-1},B_{\ell-1})$, co the thu tat ca nghiem cua phuong trinh $x^2-Dy^2=\pm 4$:

$$
\left\{(x,y):\dfrac{x+y\sqrt{D}}{2}=\pm\left(\dfrac{G_{\ell-1}+B_{\ell-1}\sqrt{D}}{2}\right)^k,k\in\mathbf Z\right\}.
$$

Neu do dai chu ki $\ell$ chan, tat ca chung deu la nghiem cua phuong trinh $x^2-Dy^2=4$; neu khong, khi $k$ le thi $(x,y)$ la nghiem cua phuong trinh $x^2-Dy^2=-4$, con khi $k$ chan thi $(x,y)$ la nghiem cua phuong trinh $x^2-Dy^2=4$.

Tinh dung dan cua thuat toan nay dua tren cac su kien sau:

???+ note "Dinh li"
    Gia su phuong trinh $x^2-Dy^2=\pm 4$ co nghiem nguyen duong $(x,y)$. Neu $D\equiv 1\pmod 4$, thi $\dfrac{(x+y)/2}{y}$ nhat dinh la mot phan so gan dung cua $\dfrac{1+\sqrt{D}}{2}$.

??? note "Chung minh"
    Truoc het chu y rang khi do $x,y$ nhat dinh cung tinh chan le, nen $(x+y)/2$ la so nguyen. Neu $(x,y)$ la nghiem cua phuong trinh $x^2-Dy^2=4$, thi $x>y\sqrt{D}>2y$, do do

    $$
    \left|\dfrac{(x+y)/2}{y}-\dfrac{1+\sqrt{D}}{2}\right| = \dfrac{2}{y(x+y\sqrt{D})}<\dfrac{1}{2y^2}.
    $$

    Theo [tieu chuan Legendre](./continued-fraction.md#%E6%B8%90%E8%BF%91%E5%88%86%E6%95%B0%E7%9A%84%E5%88%A4%E5%AE%9A), $\dfrac{(x+y)/2}{y}$ la phan so gan dung cua $\dfrac{1+\sqrt{D}}{2}$.

    Neu $(x,y)$ la nghiem cua phuong trinh $x^2-Dy^2=-4$, de thiet lap bat dang thuc tren chi can chung minh $4y<x+y\sqrt{D}$. Dieu nay dung it nhat voi moi truong hop ngoai $D=5,13$. Voi $D=5,13$, thay $x=\sqrt{Dy^2-4}$ vao bat dang thuc cho thay no tuong duong voi $2(\sqrt{D}-2)y^2>1$. Ngoai $(D,y)=(5,1)$, bat dang thuc nay dung voi moi $D=5,13$ va so nguyen duong $y$. Con lai chi can kiem tra truong hop $(D,y)=(5,1)$; khi do nghiem cua phuong trinh $x^2-5y^2=-4$ la $(x,y)=(1,1)$, va can kiem tra $\dfrac{1}{1}$ la phan so gan dung cua $\dfrac{1+\sqrt{5}}{2}=[\overline{1}]$, dieu nay hien nhien dung.

???+ note "Dinh li"
    Gia su $D$ la so nguyen duong khong phai so chinh phuong. Khai trien phan so lien tuc cua so vo ti bac hai $\omega=\dfrac{1+\sqrt{D}}{2}$ co dang

    $$
    \omega = [\lfloor\omega\rfloor,\overline{a_1,\cdots,a_{\ell-1},2\lfloor\omega\rfloor-1}],
    $$

    trong do $\ell$ la do dai chu ki, va $a_k=a_{\ell-k}$ voi moi $1<k<\ell$.

??? note "Chung minh"
    Vi $\lfloor\omega\rfloor-1+\omega>1$, va lien hop cua no bang $\lfloor\omega\rfloor - \omega$, nam giua $-1$ va $0$, nen theo [ket qua cua Galois](./continued-fraction.md#%E7%BA%AF%E5%BE%AA%E7%8E%AF%E8%BF%9E%E5%88%86%E6%95%B0), $\lfloor\omega\rfloor-1+\omega$ la phan so lien tuc thuan tuan hoan, co the viet thanh

    $$
    \lfloor\omega\rfloor-1+\omega = [\overline{2\lfloor\omega\rfloor-1,a_1,\cdots,a_{\ell-1}}].
    $$

    Ket qua cua Galois ve nghich dao cua lien hop doi dau cho biet

    $$
    \dfrac{1}{\omega-\lfloor\omega\rfloor} = [\overline{a_{\ell-1},\cdots,a_1,2\lfloor\omega\rfloor-1}].
    $$

    Do do, theo dinh nghia phan so lien tuc,

    $$
    \lfloor\omega\rfloor-1+\omega = 2\lfloor\omega\rfloor-1 + \dfrac{1}{\dfrac{1}{\omega-\lfloor\omega\rfloor}} = [2\lfloor\omega\rfloor-1,\overline{a_{\ell-1},\cdots,a_1,2\lfloor\omega\rfloor-1}].
    $$

    Tinh duy nhat cua khai trien phan so lien tuc cho thay $a_k=a_{\ell-k}$ voi moi $1<k<\ell$, va do do dang khai trien can chung minh cung dung.

???+ note "Dinh li"
    Gia su $D\equiv 1\pmod 4$. Trong qua trinh chay thuat toan PQa o tren voi $(P_0,Q_0,D)=(1,2,D)$, $Q_k=2$ nhat dinh keo theo $\ell\mid k$.

??? note "Chung minh"
    Trong khai trien phan so lien tuc cua $\dfrac{1+\sqrt{D}}{2}$, ngoai thuong hoan toan thu $0$, moi thuong hoan toan khac deu la [phan so lien tuc thuan tuan hoan](./continued-fraction.md#%E7%BA%AF%E5%BE%AA%E7%8E%AF%E8%BF%9E%E5%88%86%E6%95%B0). Gia su $Q_k=2$. Theo ket qua cua Galois, lien hop cua thuong hoan toan $\omega_k=\dfrac{P_k+\sqrt{D}}{2}$ nhat dinh thoa $-1<\dfrac{P_k-\sqrt{D}}{2}<0$, tuc $\sqrt{D}-2<P_k<\sqrt{D}$. Vi trong thuat toan PQa luon co $Q_k\mid P_k^2-D$ (xem [chung minh tinh dung dan cua thuat toan](./continued-fraction.md#%E4%BA%8C%E6%AC%A1%E6%97%A0%E7%90%86%E6%95%B0)), nen $P_k$ nhat dinh le; dieu nay cho thay gia tri cua $P_k$ la duy nhat, tuc $P_k=P_0+2(\lfloor\omega\rfloor-1)$, hay thuong hoan toan $\omega_k=\omega_\ell$. Nhung su lap lai cua thuong hoan toan co nghia phan so lien tuc vao chu ki; neu $k$ khong phai boi cua $\ell$, dieu nay mau thuan voi viec $\ell$ la chu ki duong nho nhat. Vi vay nhat dinh $\ell\mid k$.

???+ note "Dinh li"
    Gia su nghiem nguyen duong nho nhat cua phuong trinh $x^2-Dy^2=\pm 4$ la $(x_1,y_1)$. Khi do toan bo nghiem cua no la

    $$
    \left\{(x,y):\dfrac{x+y\sqrt{D}}{2}=\pm\left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^k,k\in\mathbf Z\right\}.
    $$

??? note "Chung minh"
    Do tinh doi xung, chi can xet nghiem nguyen duong $(x,y)$. O day chi can chung minh cac cap so thuc $(x,y)$ trong tap tren thuc su la nghiem nguyen cua phuong trinh $x^2-Dy^2=\pm 4$. Phan con lai chi can lap lai chung minh cau truc nghiem cua phuong trinh $x^2-Dy^2=\pm 1$.

    Thuc chat can chung minh rang voi bat ki hai nghiem nguyen $(x_1,y_1)$ va $(x_2,y_2)$ cua phuong trinh $x^2-Dy^2=\pm 4$, cap so thuc duong $(x_3,y_3)$ dinh nghia boi

    $$
    \dfrac{x_3+y_3\sqrt{D}}{2} = \dfrac{x_1+y_1\sqrt{D}}{2}\dfrac{x_2+y_2\sqrt{D}}{2}
    $$

    van la nghiem nguyen:

    $$
    x_3=\dfrac{x_1x_2+Dy_1y_2}{2},\ y_3=\dfrac{x_1y_2+x_2y_1}{2}.
    $$

    Vi voi $i=1,2$ co $x_i\equiv x_i^2\equiv Dy_i^2\equiv Dy_i\pmod 2$, nen

    $$
    \begin{aligned}
    2x_3 &= x_1x_2+Dy_1y_2 \equiv D^2y_1y_2+Dy_1y_2=D(D+1)y_1y_2 \equiv 0 \pmod 2,\\
    2y_3 &= x_1y_2+x_2y_1 \equiv Dy_1y_2+Dy_2y_1 = 2Dy_1y_2 \equiv 0 \pmod 2.
    \end{aligned}
    $$

    Dieu nay cho thay $x_3$ va $y_3$ deu la so nguyen. Lai dung tinh chat chuan bao toan phep nhan, ta biet $(x_3,y_3)$ la nghiem cua $x^2-Dy^2=\pm 4$.

Tong hop cac su kien nay va lap lai lap luan cua cac phan truoc, co the chung minh tinh dung dan cua thuat toan giai phuong trinh $x^2-Dy^2=\pm 4$ neu tren. Cac ket qua nay cho thay phuong trinh $x^2-Dy^2=\pm 4$ co cau truc nghiem don gian tuong tu phuong trinh $x^2-Dy^2=\pm 1$: tat ca nghiem deu co the bieu dien bang nghiem nguyen duong nho nhat cua no, khong can giai cac phuong trinh khac.

Thuc ra, moi nghiem cua phuong trinh $x^2-Dy^2=\pm 1$ deu co the tim thay trong nghiem cua phuong trinh $x^2-Dy^2=\pm 4$; tu goc nhin nay, phuong trinh $x^2-Dy^2=\pm 4$ co tinh co ban hon. Hien nhien, $(x,y)$ la nghiem cua $x^2-Dy^2=\pm 1$ khi va chi khi $(2x,2y)$ la nghiem cua $x^2-Dy^2=\pm 4$. Phan tich tren chi ra rang khi $D\equiv 2,3\pmod 4$, moi nghiem cua phuong trinh $x^2-Dy^2=\pm 4$ deu dong thoi chan, nen tuong ung voi nghiem cua $x^2-Dy^2=\pm 1$.

Khi $D\equiv 0\pmod 4$, trong nghiem $(x,y)$ cua phuong trinh $x^2-Dy^2=\pm 4$, $x$ nhat dinh chan nhung $y$ co the le. Neu trong nghiem nguyen duong nho nhat $(x_1,y_1)$ cua phuong trinh $x^2-Dy^2=\pm 4$, $y_1$ chan, thi trong moi nghiem $y$ cung nhat dinh chan; khi do cac nghiem nguyen nay tuong ung mot-mot voi nghiem nguyen cua $x^2-Dy^2=\pm 1$. Nhung neu trong nghiem nguyen nho nhat $(x_1,y_1)$, $y_1$ le, thi tinh chan le cua $y_k$ se trung voi tinh chan le cua $k$ va thay doi xen ke; vi vay chi khi $k$ chan moi tuong ung voi nghiem cua $x^2-Dy^2=\pm 1$. Neu trong nghiem nguyen duong nho nhat cua $x^2-Dy^2=\pm 4$, $y_1$ le va chuan cua $x_1+y_1\sqrt{D}$ la $-4$, thi voi $D$ nhu vay, $x^2-Dy^2=-4$ co nghiem nhung $x^2-Dy^2=-1$ vo nghiem.

Khi $D\equiv 1\pmod 4$, nghiem $(x,y)$ cua phuong trinh $x^2-Dy^2=\pm 4$ co the dong thoi le, cung co the dong thoi chan. Neu nghiem nguyen duong nho nhat $(x_1,y_1)$ da dong thoi chan, thi moi nghiem nguyen cua no cung nhat dinh dong thoi chan, nen luon tuong ung voi nghiem nguyen cua phuong trinh $x^2-Dy^2=\pm 1$. Neu nghiem nguyen duong nho nhat $(x_1,y_1)$ dong thoi le, ta co ket qua sau:

???+ note "Dinh li"
    Gia su nghiem nguyen duong nho nhat cua phuong trinh $x^2-Dy^2=\pm 4$ la $(x_1,y_1)$. Neu $x_1$ va $y_1$ dong thoi le, thi $D\equiv 5\pmod 8$, va nghiem nguyen $(x,y)$ cua phuong trinh do dong thoi chan khi va chi khi

    $$
    \dfrac{x+y\sqrt{D}}{2} = \pm\left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^{3k},k\in\mathbf Z.
    $$

??? note "Chung minh"
    Lay modulo $8$ hai ve cua dang thuc $x_1^2-Dy_1^2=\pm 4$, ta duoc $D\equiv 5\pmod 8$. De chung minh ket qua thu hai, truoc het chung minh $(x_3,y_3)$ deu chan, vi

    $$
    \dfrac{x_3+y_3\sqrt{D}}{2} = \left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^{3} = \dfrac{x_1^3+3Dx_1y_1^2}{8}+\dfrac{3x_1^2y_1+Dy_1^3}{8}\sqrt{D},
    $$

    nen chi can chung minh ve phai la so nguyen. Vi binh phuong cua so le dong du $1$ modulo $8$, ta co

    $$
    \begin{aligned}
    &x_1^3+3Dx_1y_1^2 = x_1(x_1^2+3Dy_1^2) \equiv x_1(1+3\times 5\times 1) = 16x_1 = 0 \pmod 8,\\
    &3x_1^2y_1+Dy_1^3 = y_1(3x_1^2+Dy_1^2) \equiv y_1(3\times 1+5\times 1) = 8y_1 = 0 \pmod 8.
    \end{aligned}
    $$

    Dieu nay cho thay $x_3,y_3$ deu chan. Do do, voi moi $k\in\mathbf Z$,

    $$
    \dfrac{x+y\sqrt{D}}{2} = \pm\left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^{3k} = \pm\left(\dfrac{x_3+y_3\sqrt{D}}{2}\right)^k \in \mathbf Z,
    $$

    nen $(x,y)$ khi do deu chan. Nguoc lai, voi $r=1,2$, luon co

    $$
    \pm\left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^{3k+r} = \pm\left(\dfrac{x_3+y_3\sqrt{D}}{2}\right)^k\left(\dfrac{x_r+y_r\sqrt{D}}{2}\right).
    $$

    De chung minh $(x,y)$ tuong ung khong phai so nguyen, chi can chung minh bieu thuc nay khong phai so nguyen, tuc thua so thu hai trong tich ben phai khong phai so nguyen. Voi $r=1$ day la gia thiet; voi $r=2$, vi

    $$
    \dfrac{x_2+y_2\sqrt{D}}{2} = \left(\dfrac{x_1+y_1\sqrt{D}}{2}\right)^2 = \dfrac{x_1^2+Dy_1^2}{4} + \dfrac{x_1y_1}{2}\sqrt{D},
    $$

    va $x_1^2+Dy_1^2\equiv 1+1\times 1=2\pmod 4$, $x_1y_1\equiv 1\pmod 2$, nen bieu thuc nay cung khong phai so nguyen. Vay chi khi so mu la boi cua $3$, nghiem tuong ung moi deu chan.

Noi cach khac, trong moi ba nghiem cua phuong trinh $x^2-Dy^2=\pm 4$ co mot nghiem dong thoi chan, va no tuong ung voi nghiem nguyen cua $x^2-Dy^2=\pm 1$. Dieu nay cung cho thay voi $D\equiv 1\pmod 4$, phuong trinh $x^2-Dy^2=-4$ co nghiem khi va chi khi phuong trinh $x^2-Dy^2=-1$ co nghiem.

Den day, cac thao luan da du de tinh don vi co ban cua vanh so nguyen bac hai thuc. Gia su $D$ la so nguyen duong khong chua nhan tu chinh phuong. Voi $D\equiv 2,3\pmod 4$, chi can tim nghiem nguyen duong nho nhat cua $x^2-Dy^2=\pm 1$; con voi $D\equiv 1\pmod 4$, chi can tim nghiem nguyen duong nho nhat cua $x^2-Dy^2=\pm 4$. Khi thu duoc nghiem nguyen duong nho nhat $(x,y)$, voi $D\equiv 2,3\pmod 4$, don vi co ban la $\pm x\pm y\sqrt{D}$; voi $D\equiv 1\pmod 4$, don vi co ban la $\dfrac{\pm x\pm y\sqrt{D}}{2}$.

??? example "Vi du"
    1.  Giai phuong trinh $x^2-14y^2=\pm 4$.

        Tu ket qua tinh toan trong vi du o tren, nghiem nguyen duong nho nhat cua phuong trinh $x^2-14y^2=4$ la $(30,8)$, con phuong trinh $x^2-14y^2=-4$ vo nghiem.
    2.  Giai phuong trinh $x^2-41y^2=\pm 4$.

        Chay thuat toan PQa voi $(P_0,Q_0,D)=(1,2,41)$ cho ket qua sau: (phan mau do la chu ki dau tien)

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

        Do dai chu ki $\ell=5$ la le. Nghiem nguyen duong nho nhat cua phuong trinh $x^2-41y^2=-4$ la $(G_4,B_4)=(64,10)$, va nghiem nguyen duong nho nhat cua phuong trinh $x^2-41y^2=4$ la $(G_9,B_9)=(4098,640)$. Giua chung co quan he

        $$
        \dfrac{4098+640\sqrt{41}}{2} = \left(\dfrac{64+10\sqrt{41}}{2}\right)^2.
        $$

        Tat nhien, vi $D\equiv 1\pmod 8$, theo ket qua o tren, nghiem nguyen duong nho nhat cua phuong trinh $x^2-41y^2=\pm 4$ khi do nhat dinh deu chan, va luon bang hai lan nghiem nguyen duong nho nhat cua $x^2-41y^2=\pm 1$; do do cung co the suy truc tiep tu vi du truoc.
    3.  Giai phuong trinh $x^2-13y^2=\pm 4$.

        Chay thuat toan PQa voi $(P_0,Q_0,D)=(1,2,13)$ cho ket qua sau: (phan mau do la chu ki dau tien)

        | $k$ | $P$ | $Q$ |        $a$       |  $A$ |  $B$ |  $G$  | $G^2-DB^2$ |
        | :-: | :-: | :-: | :--------------: | :--: | :--: | :---: | :--------: |
        | $0$ | $1$ | $2$ |        $2$       |  $2$ |  $1$ |  $3$  |    $-4$    |
        | $1$ | $3$ | $2$ | $\color{red}{3}$ |  $7$ |  $3$ |  $11$ |     $4$    |
        | $2$ | $3$ | $2$ |        $3$       | $23$ | $10$ |  $36$ |    $-4$    |
        | $3$ | $3$ | $2$ |        $3$       | $74$ | $33$ | $119$ |     $4$    |

        Do dai chu ki $\ell=1$ la le. Nghiem nguyen duong nho nhat cua phuong trinh $x^2-13y^2=-4$ la $(G_0,B_0)=(3,1)$, va nghiem nguyen duong nho nhat cua phuong trinh $x^2-13y^2=4$ la $(G_1,B_1)=(11,3)$.

        Vi nghiem nguyen duong nho nhat cua phuong trinh nay deu le, co the dung cap tai cuoi chu ki thu ba $(G_2,B_2)=(36,10)$ de thu nghiem nguyen duong nho nhat $(18,5)$ cua phuong trinh Pell (am) tuong ung $x^2-13y^2=\pm 1$. No cung co the tinh truc tiep:

        $$
        \dfrac{36+10\sqrt{13}}{2}=\left(\dfrac{3+\sqrt{13}}{2}\right)^3.
        $$

        Hon nua, day la nghiem cua phuong trinh Pell am. Nghiem nguyen duong nho nhat cua phuong trinh Pell tuong ung la $(649,180)$.
    4.  Giai phuong trinh $x^2-52y^2=\pm 4$.

        Vi nghiem nguyen duong nho nhat cua phuong trinh $x^2-13y^2=\pm 1$ lan luot la $(18,5)$ va $(649,180)$, nen nghiem nguyen duong nho nhat cua phuong trinh $x^2-52y^2=\pm 4$ lan luot la $(36,10)$ va $(1298,360)$.

<span id="&#x4e00;&#x822c;&#x60c5;&#x5f62;"></span>
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
    Giả sử $\dfrac{P}{Q}$ có [khai triển phân số liên tục](./continued-fraction.md#%E7%AE%80%E5%8D%95%E8%BF%9E%E5%88%86%E6%95%B0)

    $$
    \dfrac{P}{Q} = [a_0,a_1,\cdots,a_k]
    $$

    và $PS-QR = (-1)^{k-1}$. Nếu $\dfrac{p_k}{q_k}$ là phân số gần đúng thứ $k$
    của nó, thì $(p_k,q_k)=(P,Q)$, và theo [công thức sai phân của phân số gần đúng](./continued-fraction.md#%E8%AF%AF%E5%B7%AE%E4%BC%B0%E8%AE%A1),
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

??? example "Vi du"
    1.  Giai phuong trinh $x^2-157y^2=12$.

        Vi $12^2<157$, chay thuat toan PQa voi $(P_0,Q_0,D)=(0,1,157)$ cho ket qua sau: (phan mau do la chu ki dau tien)

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

<span id="&#x4e60;&#x9898;"></span>
## Bài tập

-   [LOJ 6687. Project Euler 66 - Giải phương trình](https://loj.ac/p/6687)
-   [SPOJ EQU2 - Yet Another Equation](https://www.spoj.com/problems/EQU2/)
-   [SPOJ PELL2 - Pell (Mid pelling)](https://www.spoj.com/problems/PELL2/)
-   [UVa 12909. Numeric Center](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=862&page=show_problem&problem=4774)
-   [UVa 10241. Semi-triangular and also Square](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1182)

<span id="&#x53c2;&#x8003;&#x6587;&#x732e;&#x4e0e;&#x6ce8;&#x91ca;"></span>
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
