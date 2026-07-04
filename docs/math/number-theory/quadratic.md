Bài viết này giới thiệu ngắn gọn các khái niệm liên quan đến trường bậc hai.
Hai ví dụ quan trọng có liên quan là số nguyên Gauss và số nguyên Eisenstein;
chúng có thể dùng để giải một số bài toán số học.

<span id="&#x57fa;&#x672c;&#x6982;&#x5ff5;"></span>
## Khái niệm cơ bản

Phần này trước hết giới thiệu một loạt khái niệm cơ bản. Trường bậc hai và
vành số nguyên bậc hai đều là các trường hợp đặc biệt của khái niệm tổng quát
hơn là mở rộng đại số và vành số nguyên đại số, vì vậy hầu hết định nghĩa và
kết quả trong phần này đều có thể mở rộng một cách thích hợp sang trường hợp
tổng quát. Ở đây ta chỉ thảo luận riêng trường hợp trường bậc hai, không dựa
vào quá nhiều nội dung của số học đại số.

<span id="&#x4e8c;&#x6b21;&#x57df;"></span>
### Trường bậc hai

Các phần tử của trường bậc hai đều là số đại số bậc hai.

**Số đại số bậc hai** (quadratic algebraic number) là số phức có thể biểu diễn
như nghiệm của một phương trình bậc hai một ẩn với hệ số nguyên. Từ công thức
nghiệm của phương trình bậc hai, mọi số đại số bậc hai đều có thể viết dưới
dạng

$$
a+b\sqrt{d}
$$

trong đó $a$ và $b$ là các số hữu tỉ, $d$ là số nguyên không chứa nhân tử chính
phương. Mọi số có dạng này cũng là số đại số bậc hai. Số đại số bậc hai có thể
chia thành số hữu tỉ và **số vô tỉ bậc hai** (quadratic irrational number).
Hiển nhiên, cách biểu diễn một số vô tỉ bậc hai dưới dạng trên là duy nhất.

Với mỗi số nguyên không chứa nhân tử chính phương $d\neq 0,1$, có thể kiểm tra
tập $Q(\sqrt{d})=\{a+b\sqrt{d}:a,b\in\mathbf Q\}$ đóng dưới phép cộng, trừ,
nhân, chia. Vì một tập đóng dưới bốn phép toán số học được gọi là
[trường](../algebra/basic.md#%E5%9F%9F), tập $Q(\sqrt{d})$ được gọi là
**trường bậc hai** (quadratic field). Mọi trường bậc hai đều chứa toàn bộ các
số hữu tỉ, do đó chúng đều là [mở rộng bậc hai](../algebra/field-theory.md#%E5%9F%9F%E7%9A%84%E6%89%A9%E5%BC%A0)
của trường số hữu tỉ $\mathbf Q$. Khi $d>0$, mọi số trong trường bậc hai
$\mathbf Q(\sqrt{d})$ đều là số thực; khi đó $\mathbf Q(\sqrt{d})$ được gọi là
trường bậc hai thực. Khi $d<0$, trong trường bậc hai, ngoài các số hữu tỉ ra
đều là số phức; khi đó $\mathbf Q(\sqrt{d})$ được gọi là trường bậc hai ảo.

<span id="&#x5171;&#x8f6d;&#x4e0e;&#x8303;&#x6570;"></span>
### Liên hợp và chuẩn

**Liên hợp** (conjugate) của số vô tỉ bậc hai $a+b\sqrt{d}$ được định nghĩa là
$a-b\sqrt{d}$. Hai số vô tỉ bậc hai liên hợp là hai nghiệm phân biệt của cùng
một phương trình bậc hai với hệ số nguyên. Trong trường bậc hai thực, liên hợp
của số vô tỉ bậc hai không trùng với liên hợp phức của nó; trong trường bậc hai
ảo, liên hợp của số vô tỉ bậc hai chính là liên hợp phức của nó. Cuối cùng,
liên hợp của một số hữu tỉ được quy ước là chính nó. Như vậy khái niệm liên hợp
được định nghĩa cho tất cả các số đại số bậc hai.

Trong bất kì trường bậc hai nào, các đẳng thức sinh ra từ bốn phép cộng, trừ,
nhân, chia không phân biệt được quan hệ liên hợp. Nói cách khác, nếu thay mỗi
số trong một đẳng thức bằng liên hợp của nó, tức đổi dấu mọi căn bậc hai, thì
đẳng thức vẫn đúng.

Dùng liên hợp có thể xây dựng một số ánh xạ từ số đại số bậc hai đến số hữu tỉ,
giúp chuyển các thảo luận về số đại số bậc hai thành thảo luận về số hữu tỉ.
Ánh xạ đơn giản hơn là **vết** (trace) của số đại số bậc hai $\alpha$, tức tổng
của một số và liên hợp của nó, kí hiệu $\operatorname{tr}(\alpha)$. Vì nó thực
chất chỉ là hai lần phần hữu tỉ của số đó, nên không cung cấp nhiều thông tin.

Hữu ích hơn là chuẩn của số đại số bậc hai. Tích của số đại số bậc hai với liên
hợp của nó được gọi là **chuẩn** (norm) của nó:

$$
N(a+b\sqrt{d})=a^2-db^2
$$

Hiển nhiên, trong trường bậc hai ảo, khái niệm chuẩn trùng với bình phương
modun của số phức; nhưng trong trường bậc hai thực, hai khái niệm này không
trùng nhau.

Chuẩn có các tính chất tốt. Trước hết, vì $d$ không chứa nhân tử chính phương
nên không thể là số chính phương; do đó chỉ có $0$ mới có chuẩn bằng $0$. Tiếp
theo, chuẩn bảo toàn phép nhân và phép chia:

$$
N(a_1+b_1\sqrt{d})N(a_2+b_2\sqrt{d})=N((a_1+b_1\sqrt{d})(a_2+b_2\sqrt{d})),
$$

$$
\frac{N(a_1+b_1\sqrt{d})}{N(a_2+b_2\sqrt{d})}=N\left(\frac{a_1+b_1\sqrt{d}}{a_2+b_2\sqrt{d}}\right).
$$

Ngoài ra, nghịch đảo của một số đại số bậc hai bằng thương của liên hợp và
chuẩn của nó:

$$
\dfrac{1}{a+b\sqrt{d}}=\frac{a-b\sqrt{d}}{N(a+b\sqrt{d})}.
$$

Theo định lý Vieta, số đại số bậc hai $\alpha$ thực ra là nghiệm của phương
trình

$$
x^2-\operatorname{tr}(\alpha)x+N(\alpha)=0
$$

Biệt thức của phương trình này cũng được gọi là **biệt thức** (discriminant)
của số đại số bậc hai đó, kí hiệu $\operatorname{disc}(\alpha)$, và có giá trị
$4db^2$.

???+ note "Biểu diễn ma trận"
    Tương tự số phức, số đại số bậc hai cũng có thể biểu diễn bằng ma trận. Cho
    $d\neq 0,1$ là số nguyên không chứa nhân tử chính phương và $a,b$ là các số
    hữu tỉ, khi đó $a+b\sqrt{d}$ có thể biểu diễn bởi ma trận
    
    $$
    \begin{pmatrix}a & b \\ db & a\end{pmatrix}.
    $$
    
    Có thể kiểm tra rằng kết quả của các phép cộng, trừ, nhân, chia trên ma
    trận này tương ứng với kết quả phép toán trên số đại số bậc hai. Vết và
    định thức của ma trận lần lượt tương ứng với vết và chuẩn của số đại số bậc
    hai; biệt thức của đa thức đặc trưng của ma trận chính là biệt thức của số
    đại số bậc hai. Ma trận phụ hợp của ma trận tương ứng với số đại số bậc hai
    liên hợp.

<span id="&#x4e8c;&#x6b21;&#x6574;&#x6570;&#x73af;"></span>
### Vành số nguyên bậc hai

Một lớp đặc biệt trong các số đại số bậc hai là số nguyên bậc hai. **Số nguyên
bậc hai** (quadratic integer) là số phức có thể biểu diễn như nghiệm của một
phương trình bậc hai một ẩn với hệ số nguyên và hệ số bậc hai bằng một. Khác
biệt duy nhất với số đại số bậc hai nằm ở ràng buộc trên hệ số bậc hai. Theo
công thức nghiệm, hai nghiệm của phương trình bậc hai $x^2+px+q=0$ là

$$
\frac{-p\pm\sqrt{p^2-4q}}{2}.
$$

Nếu $p$ chẵn, tức $p=2k$, thì hai nghiệm có thể viết là
$-k\pm\sqrt{k^2-q}$; nếu $p$ lẻ, tức $p=2k+1$, thì hai nghiệm có thể viết là
$-k-\dfrac{1\pm\sqrt{4(k^2+k-q)+1}}{2}$. Từ hai trường hợp này có thể suy ra
các số nguyên bậc hai trong $\mathbf Q(\sqrt{d})$ nhất định có thể viết dưới
dạng

$$
a+b\omega
$$

trong đó $a$ và $b$ là các số nguyên, còn

$$
\omega=\begin{cases}
\dfrac{1+\sqrt{d}}{2}, & d\equiv 1\pmod 4,\\
\sqrt{d}, & d\equiv 2,3\pmod 4.
\end{cases}
$$

Ngược lại, mọi số phức có dạng này đều là số nguyên bậc hai. Với mọi số nguyên
bậc hai không hữu tỉ, cách viết dưới dạng này là duy nhất.

Tập hợp tất cả số nguyên bậc hai trong trường bậc hai $\mathbf Q(\sqrt{d})$
được kí hiệu là $\mathbf Z[\omega]$. Vì tập này đóng dưới phép cộng, trừ, nhân,
nó cũng được gọi là **vành số nguyên bậc hai** (quadratic integer ring). Các số
hữu tỉ trong vành số nguyên bậc hai đúng bằng toàn bộ các số nguyên. Nếu xét
tập tất cả các thương của các số nguyên bậc hai trong $\mathbf Z[\omega]$, ta
thu được trường bậc hai tương ứng $\mathbf Q(\sqrt{d})$.

Vết, chuẩn và biệt thức của số nguyên bậc hai đều là số nguyên. Giá trị nhỏ
nhất của biệt thức trong tất cả số vô tỉ bậc hai thuộc vành số nguyên bậc hai
$\mathbf Z[\omega]$ cũng được gọi là biệt thức của trường bậc hai tương ứng
$\mathbf Q(\sqrt{d})$. Khi $d\equiv 1\pmod 4$, biệt thức là $d$; khi
$d\equiv 2,3\pmod 4$, biệt thức là $4d$.

<span id="&#x6574;&#x9664;&#x3001;&#x76f8;&#x4f34;&#x4e0e;&#x5355;&#x4f4d;&#x6570;"></span>
### Chia hết, liên kết và đơn vị

Tương tự số nguyên, ta cũng có thể xây dựng lí thuyết chia hết cho số nguyên
bậc hai. Dĩ nhiên việc thảo luận phải được thực hiện trong cùng một vành số
nguyên bậc hai.

Với các số nguyên bậc hai $\alpha$ và $\beta$ trong vành số nguyên bậc hai
$\mathbf Z[\omega]$, nếu tồn tại số nguyên bậc hai $\gamma$ trong cùng vành sao
cho $\beta=\alpha\gamma$, thì nói $\alpha$ chia hết $\beta$, kí hiệu
$\alpha\mid\beta$. Quan hệ chia hết là một quan hệ [thứ tự bộ phận](../order-theory.md#%E4%BA%8C%E5%85%83%E5%85%B3%E7%B3%BB)
trên vành số nguyên bậc hai. Nếu đồng thời có $\alpha\mid\beta$ và
$\beta\mid\alpha$, thì khi nghiên cứu lí thuyết chia hết có thể xem $\alpha$
và $\beta$ như cùng một số; chúng được gọi là **liên kết** (associate). Quan hệ
liên kết là một quan hệ tương đương trên vành số nguyên bậc hai.

Trong lí thuyết chia hết của số nguyên, quan hệ liên kết chính là quan hệ đối
nhau. Thông thường chỉ cần xét các số tự nhiên trong lí thuyết chia hết, không
cần xét trường hợp số âm. Đối với số nguyên bậc hai, quan hệ liên kết có thể
phức tạp hơn. Nếu hai số nguyên bậc hai $\alpha$ và $\beta$ liên kết, thì tồn
tại các số nguyên bậc hai $\gamma$ và $\delta$ sao cho $\beta=\alpha\gamma$ và
$\alpha=\beta\delta$. Do đó, thương $\gamma$ của $\beta$ và $\alpha$ nhất định
là một số nguyên bậc hai đặc biệt: tồn tại số nguyên bậc hai $\delta$ sao cho
$\gamma\delta=1$. Số nguyên bậc hai $\gamma$ như vậy được gọi là **đơn vị**
(unit), hay phần tử khả nghịch. Hai số nguyên bậc hai liên kết khi và chỉ khi
thương của chúng là đơn vị. Vì vậy, muốn hiểu quan hệ liên kết trên vành số
nguyên bậc hai thì cần hiểu cấu trúc các đơn vị của vành đó.

Vì chuẩn bảo toàn phép nhân và chuẩn của số nguyên bậc hai luôn là số nguyên,
ta có thể dùng chuẩn để chuyển quan hệ chia hết của số nguyên bậc hai thành
quan hệ chia hết của số nguyên. Nói cách khác, nếu $\alpha\mid\beta$ thì nhất
định $N(\alpha)\mid N(\beta)$. Tương tự, số nguyên bậc hai $\alpha$ là đơn vị
khi và chỉ khi chuẩn của nó $N(\alpha)=\pm 1$. Do đó, để tìm tất cả đơn vị
trong vành số nguyên bậc hai $\mathbf Z[\omega]$, chỉ cần giải phương trình vô
định:

$$
N(a+b\sqrt{d})=1,
$$

trong đó biểu thức của chuẩn là

$$
N(a+b\sqrt{d})=\begin{cases}
a^2+ab+\dfrac{1-d}{4}b^2, & d\equiv 1\pmod 4,\\
a^2-db^2, & d\equiv 2,3\pmod 4.
\end{cases}
$$

Với vành số nguyên bậc hai ảo, tức $d<0$, vì chuẩn nhất định là số nguyên không
âm, dễ dàng kiểm tra rằng với mọi số âm không chứa nhân tử chính phương
$d\neq -1,-3$, nghiệm chỉ là $(a,b)=(\pm 1,0)$; tức ngoài
$\mathbf Z[\sqrt{-1}]$ và $\mathbf Z[\frac{1+\sqrt{-3}}{2}]$, các vành số
nguyên bậc hai ảo chỉ có các đơn vị $\pm 1$. Đặt $\mathrm{i}=\sqrt{-1}$, vành
số nguyên bậc hai $\mathbf Z[\mathrm{i}]$ còn được gọi là vành số nguyên Gauss;
tập đơn vị của nó là $\{\pm 1,\pm\mathrm{i}\}$. Đặt
$\omega=\frac{1+\sqrt{-3}}{2}$, vành số nguyên bậc hai $\mathbf Z[\omega]$ còn
được gọi là vành số nguyên Eisenstein; tập đơn vị của nó là
$\{\pm 1,\pm\omega,\pm\omega^2\}$.

Với vành số nguyên bậc hai thực, tức $d>0$, tình hình phức tạp hơn và có thể
chuyển thành thảo luận về [phương trình Pell](./pell-equation.md). Từ các kết
quả về phương trình Pell, tập tất cả đơn vị khi đó có thể viết là
$\{\pm u^k:k\in\mathbf Z\}$, trong đó $u$ được gọi là **đơn vị cơ bản**
(fundamental unit). Có thể tìm đơn vị cơ bản thông qua phương trình Pell tương
ứng. Đơn vị cơ bản không duy nhất: nếu $u$ là đơn vị cơ bản thì liên hợp
$\bar u$ của nó, cũng như $-u$ và $-\bar u$, đều là đơn vị cơ bản.

Cấu trúc các đơn vị của vành số nguyên bậc hai có thể mở rộng sang [vành số
nguyên đại số](../algebra/field-theory.md#%E4%BB%A3%E6%95%B0%E6%89%A9%E5%BC%A0)
tổng quát. [Định lý đơn vị Dirichlet](https://en.wikipedia.org/wiki/Dirichlet%27s_unit_theorem)
trong số học đại số phát biểu rằng tất cả đơn vị của mọi vành số nguyên đại số
lập thành một [nhóm Abel hữu hạn sinh](../algebra/group-theory.md#%E6%9C%89%E9%99%90%E7%94%9F%E6%88%90-abel-%E7%BE%A4),
đồng thời định lý này cũng cho biết hạng của nhóm đó.

Các nội dung trong lí thuyết chia hết của số nguyên như ước chung lớn nhất,
phép chia có dư, định lý Bézout, định lý phân tích duy nhất, v.v. đều có thể
mở rộng lên một phần hoặc toàn bộ các vành số nguyên bậc hai. Việc có thể thực
hiện các mở rộng như vậy trên một vành số nguyên bậc hai hay không thực ra phản
ánh tính chất của vành đó có đủ gần với vành số nguyên hay không. Không phải
mọi vành số nguyên bậc hai đều thỏa mãn định lý phân tích duy nhất; trong các
vành thỏa mãn định lý phân tích duy nhất, cũng chỉ một phần cho phép thực hiện
phép chia có dư. Có thể tham khảo mục [vành số nguyên bậc hai](../algebra/ring-theory.md#%E4%BE%8B%E5%AD%90%E4%BA%8C%E6%AC%A1%E6%95%B4%E6%95%B0%E7%8E%AF)
trong phần lí thuyết vành hoặc các sách liên quan để biết thêm về nội dung này.

<span id="&#x552f;&#x4e00;&#x5206;&#x89e3;"></span>
### Phân tích duy nhất

Nếu định lý phân tích duy nhất của số nguyên có thể mở rộng lên vành số nguyên
bậc hai, nó nên có dạng sau: mọi số nguyên bậc hai trong vành
$\mathbf Z[\omega]$ đều có thể viết thành tích của một số phần tử bất khả quy,
và phân tích này là duy nhất nếu bỏ qua liên kết và thứ tự. Ở đây [phần tử bất
khả quy](../algebra/ring-theory.md#%E6%95%B4%E9%99%A4%E5%85%B3%E7%B3%BB) là số
nguyên bậc hai không thể tiếp tục phân tích thành tích của các phần tử không
phải đơn vị, tương tự số nguyên tố trong định lý phân tích duy nhất của số
nguyên. Nhưng như đã nói, không phải mọi vành số nguyên bậc hai đều thỏa mãn
định lý phân tích duy nhất.

Ví dụ, trong $\mathbf Z[\sqrt{-5}]$ có phân tích
$9=3\times 3=(2+\sqrt{-5})\times(2-\sqrt{-5})$, nhưng $3$ và
$2\pm\sqrt{-5}$ đều đã là phần tử bất khả quy, nên phân tích không duy nhất. Để
chỉ ra ba số này đều bất khả quy, có thể xét chuẩn của chúng: chuẩn của chúng
đều bằng $9$; nếu chúng có thể phân tích thành tích của các phần tử không phải
đơn vị, thì chuẩn của các thừa số thu được chỉ có thể bằng $3$, nhưng trong
$\mathbf Z[\sqrt{-5}]$ không có số nguyên bậc hai nào có chuẩn bằng $3$.

Nguyên nhân chính khiến định lý phân tích duy nhất không đúng trong vành số
nguyên bậc hai tổng quát là việc phân tích chỉ bằng số nguyên bậc hai chưa đủ
tinh vi. Chuyện tương tự là cần phân tích tích $abcd$, nhưng các phần tử cơ bản
khả dụng chỉ là $\{ab,cd,ac,bd\}$, thì phân tích thu được tất nhiên không duy
nhất; để có định lý phân tích duy nhất, phải xét thêm $\{a,b,c,d\}$. Trong
vành số nguyên bậc hai, cấu trúc tinh vi hơn số nguyên bậc hai là [ideal](../algebra/ring-theory.md#%E7%90%86%E6%83%B3)
của vành số nguyên bậc hai. Ánh xạ một số nguyên bậc hai đến ideal chính tương
ứng của nó sẽ nhúng lớp liên kết của nó vào tập các ideal, vì vậy phân tích số
nguyên chỉ là trường hợp đặc biệt của phân tích ideal. Nếu xét phân tích ideal
trong vành số nguyên bậc hai, có thể chứng minh mọi ideal của vành số nguyên
bậc hai đều phân tích duy nhất thành tích của một số ideal nguyên tố. Điều này
cho thấy các vành số nguyên bậc hai đều là [miền Dedekind](https://en.wikipedia.org/wiki/Dedekind_domain).
Tổng quát hơn, mọi vành số nguyên đại số đều là miền Dedekind.

Nếu một vành số nguyên bậc hai thỏa mãn định lý phân tích duy nhất, thì các
ideal nguyên tố của nó tương ứng một-một với các phần tử bất khả quy (theo lớp
tương đương liên kết). Vì vậy, với lớp vành số nguyên bậc hai này, phân tích
ideal thành ideal nguyên tố tương đương với phân tích số nguyên bậc hai thành
phần tử bất khả quy. Hơn nữa, khi đó các phần tử bất khả quy cũng được gọi là
[phần tử nguyên tố](../algebra/ring-theory.md#%E6%95%B4%E9%99%A4%E5%85%B3%E7%B3%BB),
tương ứng với khái niệm số nguyên tố trong số nguyên. Phần thảo luận dưới đây
sẽ dùng ideal nguyên tố và các khái niệm liên quan; độc giả chưa quen khái
niệm này có thể thay chúng từng chữ một bằng phần tử nguyên tố, khi đó các phát
biểu vẫn đúng trong trường hợp định lý phân tích duy nhất đúng.

Để hiểu hoàn toàn phân tích duy nhất trên vành số nguyên bậc hai tổng quát
$\mathbf Z[\omega]$, cần biết các ideal nguyên tố trong $\mathbf Z[\omega]$ là
những ideal nào. Trước hết, mọi ideal nguyên tố trong $\mathbf Z[\omega]$ đều
chia chuẩn của nó (dưới dạng ideal chính). Phân tích chuẩn của nó trong các số
nguyên thành tích các số nguyên tố; theo định lý phân tích duy nhất, ideal
nguyên tố đó nhất định chia một trong các thừa số nguyên tố này (dưới dạng
ideal chính). Vì vậy, các ideal nguyên tố trong $\mathbf Z[\omega]$ nhất định
thu được bằng cách phân tích tiếp các số nguyên tố trong $\mathbf Z$. Để liệt
kê toàn bộ ideal nguyên tố trong $\mathbf Z[\omega]$, chỉ cần cho phân tích duy
nhất của số nguyên tố $p$ của $\mathbf Z$ (dưới dạng ideal chính) trong
$\mathbf Z[\omega]$. Vì chuẩn của số nguyên tố $p$ (dưới dạng ideal chính)
trong $\mathbf Z[\omega]$ là $p^2$, mà phân tích của nó thành ideal nguyên tố
có nghĩa chuẩn của các ideal nguyên tố chỉ có thể là ước của $p^2$, nên chỉ có
thể là $p$ hoặc $p^2$. Điều này cho thấy chỉ có ba khả năng sau:

1.  $p$ **bất động** (inert) trong $\mathbf Z[\omega]$, tức $(p)$ vẫn là ideal
    nguyên tố trong $\mathbf Z[\omega]$;
2.  $p$ **tách** (split) trong $\mathbf Z[\omega]$, tức $(p)$ có thể viết thành
    tích của hai ideal nguyên tố liên hợp khác nhau trong $\mathbf Z[\omega]$;
3.  $p$ **phân nhánh** (ramify) trong $\mathbf Z[\omega]$, tức $(p)$ có thể
    viết thành bình phương của một ideal nguyên tố.

Có thể chứng minh thêm rằng, để xác định một số nguyên tố $p$ rơi vào trường
hợp nào trong ba trường hợp trên, chỉ cần tính [kí hiệu Kronecker](https://en.wikipedia.org/wiki/Kronecker_symbol)
$\left(\dfrac{D}{p}\right)$ với biệt thức $D$ của trường bậc hai chứa
$\mathbf Z[\omega]$ và số nguyên tố $p$. Ba trường hợp này tương ứng với ba giá
trị của kí hiệu Kronecker: $-1$, $+1$ và $0$. Khi $p$ là số nguyên tố lẻ, kí
hiệu Kronecker chính là [kí hiệu Legendre](./quad-residue.md#legendre-%E7%AC%A6%E5%8F%B7),
và ba trường hợp tương ứng với $D$ là [không thặng dư bậc hai](./quad-residue.md),
$D$ là [thặng dư bậc hai](./quad-residue.md), và $p$ chia $D$. Khi $p=2$, ba
trường hợp lần lượt tương ứng với $D\equiv \pm 3\pmod 8$,
$D\equiv \pm 1\pmod 8$ và $2$ chia $D$.

<span id="gauss-&#x6574;&#x6570;"></span>
## So nguyen Gauss

Trong phan nay, dat $\mathrm{i}=\sqrt{-1}$ la don vi ao. Truong bac hai $\mathbf Q(\mathrm{i})$ con duoc goi la truong Gauss, dong thoi la [truong cyclotomic](../algebra/field-theory.md#%E5%88%86%E5%9C%86%E5%9F%9F) bac bon. Vanh so nguyen bac hai tuong ung $\mathbf Z[\mathrm{i}]$ duoc goi la vanh so nguyen Gauss; cac phan tu cua no duoc goi la **so nguyen Gauss** (Gaussian integer). So nguyen Gauss co bon don vi, la $\pm 1$ va $\pm\mathrm{i}$, nen moi so nguyen Gauss khac khong co bon phan tu lien ket (ke ca chinh no). Tren mat phang phuc, so nguyen Gauss bieu dien tat ca diem nguyen, va chuan $N(a+b\mathrm{i})=a^2+b^2$ cua so nguyen Gauss chinh la chuan tren mat phang phuc.

![](./images/gaussian-integer.svg)

Tren so nguyen Gauss co the thuc hien phep chia co du: voi cac so nguyen Gauss $a$ va $b\neq 0$, luon ton tai cac so nguyen Gauss $q$ va $r$ sao cho $a=bq+r$ va $N(r)<N(b)$. De tinh phep chia co du nay, truoc het tinh $\dfrac{a}{b}$ trong $\mathbf Q(\mathrm{i})$, sau do tim diem nguyen gan nhat trong mat phang phuc lam $q$, roi tinh $r=a-bq$; phan du thu duoc luon thoa $N(r)\le\dfrac{1}{2}N(b)$. Dung phep chia co du, co the chuyen thuat toan Euclid va dinh li Bezout sang so nguyen Gauss, tu do thiet lap dinh li phan tich duy nhat.

<span id="gauss-&#x7d20;&#x6570;"></span>
### So nguyen to Gauss

Dung ket qua cua phan truoc co the tim cac phan tu nguyen to trong so nguyen Gauss (cung goi la so nguyen to Gauss). Vi biet thuc cua vanh so nguyen Gauss la $-4$, con ki hieu Kronecker $\left(\dfrac{-4}{n}\right)$ nhan gia tri $0$ tren $n$ chan, va tren $n$ le co gia tri bang $\left(\dfrac{-1}{n}\right)=(-1)^{(n-1)/2}$, nen

$$
\left(\dfrac{-4}{n}\right) = \begin{cases}
+1,& n\equiv 1\pmod 4,\\
-1,& n\equiv 3\pmod 4,\\
0,& 2\mid n.
\end{cases}
$$

Do do, so nguyen to Gauss gom ba loai sau:

1.  Cac so nguyen to dang $4k+3$ trong so nguyen;
2.  Hai thua so nguyen to Gauss lien hop cua cac so nguyen to dang $4k+1$ trong so nguyen;
3.  Thua so $1+\mathrm{i}$ cua so nguyen to $2$, lien hop cua no lien ket voi no.

Vi du trong $\mathbf Z[\mathrm{i}]$ co phan tich $60=2^2\times 3\times 5=-(1+\mathrm{i})^4\times 3\times(2+\mathrm{i})\times(2-\mathrm{i})$.

Thao luan o day ve viec so nguyen to $p$ co the phan tich tiep trong $\mathbf Z[\mathrm{i}]$ thuc ra tuong duong voi thao luan ve viec $p$ co the viet duoi dang tong hai binh phuong nguyen $a^2+b^2$. Vi vay tu ket qua nay suy ra: so nguyen to $p$ co the viet thanh tong hai binh phuong khi va chi khi $p=2$ hoac $p\equiv 1\pmod 4$. Day la [dinh li Fermat ve tong hai binh phuong](https://en.wikipedia.org/wiki/Fermat%27s_theorem_on_sums_of_two_squares).

<span id="&#x5706;&#x4e0a;&#x6574;&#x70b9;&#x95ee;&#x9898;"></span>
### Bai toan diem nguyen tren duong tron

Tren mat phang phuc, so nguyen Gauss bieu dien moi diem nguyen. Chuan cua so nguyen Gauss chinh la binh phuong khoang cach Euclid tu diem luoi den goc toa do. Vi vay, cac so nguyen bac hai co cung chuan tuong ung voi cac diem nguyen tren duong tron tam goc toa do trong mat phang phuc. Noi cach khac, so diem nguyen tren duong tron $x^2+y^2=n$ chinh la so so nguyen Gauss $x+y\mathrm{i}$ co chuan bang $n$.

De giai phuong trinh $N(x+y\mathrm{i})=n$, co the xet phan tich so nguyen Gauss $x+y\mathrm{i}$ thanh thua so nguyen to; khi do tich chuan cua cac thua so nguyen to nay bang $n$. Do do, chi can truoc het co phan tich thua so cua $n$, ta co the dua vao cac thua so nguyen to cua $n$ de xac dinh nhung thua so nguyen to ma $x+y\mathrm{i}$ co the co. Gia su phan tich thua so nguyen to cua so nguyen $n$ la

$$
n=2^kp_1^{r_1}\cdots p_\ell^{r_\ell}q_1^{s_1}\cdots q_{m}^{s_m},
$$

trong do $p_1,\cdots,p_\ell$ la cac thua so nguyen to dang $4k+1$, con $q_1,\cdots,q_m$ la cac thua so nguyen to dang $4k+3$.

Truoc het, phuong trinh $N(x+y\mathrm{i})=n$ co nghiem khi va chi khi cac so mu $s_1,\cdots,s_m$ cua thua so nguyen to dang $4k+3$ trong $n$ deu chan; do $q_1,\cdots,q_m$ cung la so nguyen to Gauss, chuan cua chung bang binh phuong cua chinh chung, nen trong phan tich thua so nguyen to cua chuan chung bat buoc xuat hien thanh cap.

Bay gio gia su phuong trinh co nghiem. Khi do nghiem cua phuong trinh nhat dinh co dang

$$
u(1+\mathrm{i})^k(a_1+b_1\mathrm{i})^{r_{1}^+}(a_1-b_1\mathrm{i})^{r_{1}^-}\cdots(a_\ell+ b_\ell\mathrm{i})^{r_\ell^+}(a_\ell-b_\ell\mathrm{i})^{r_\ell^-}q_1^{s_1/2}\cdots q_{m}^{s_m/2},
$$

trong do $u$ la don vi, $a_j\pm b_j\mathrm{i}$ la hai thua so nguyen to lien hop cua $p_j$ trong vanh so nguyen Gauss, va $r_j^++r_j^-=r_j$. Do do, so nghiem cua phuong trinh bang

$$
4(1+r_1)\cdots(1+r_\ell).
$$

Dat $f(n)$ la so nghiem nguyen cua phuong trinh $x^2+y^2=n$. Khi phuong trinh co nghiem, $f(n)$ duoc cho boi bieu thuc tren; neu khong thi $f(n)=0$. De thay, $\dfrac14f(n)$ la [ham nhan tinh](./basic.md#%E7%A7%AF%E6%80%A7%E5%87%BD%E6%95%B0). Gia tri cua ham nhan tinh duoc xac dinh boi gia tri tren cac luy thua nguyen to. Tu bieu thuc cua $f(n)$ co the xac dinh gia tri cua $\dfrac14f(n)$ tren luy thua nguyen to $p^k$ nhu sau:

1.  Neu $p$ la so nguyen to dang $4k+3$, thi $\dfrac14f(1)=1,\dfrac14f(p)=0,\dfrac14f(p^2)=1,\dfrac14f(p^3)=0,\cdots$;
2.  Neu $p$ la so nguyen to dang $4k+1$, thi $\dfrac14f(p^k)=k+1$;
3.  Neu $p=2$, thi $\dfrac14f(2^k)=1$.

De thay ba truong hop nay deu co the viet thanh

$$
\dfrac14f(p^k) = \sum_{j=0}^k\left(\dfrac{-4}{p}\right)^k = \sum_{j=0}^k\left(\dfrac{-4}{p^k}\right) = \sum_{d\mid p^k}\left(\dfrac{-4}{d}\right).
$$

Vi ki hieu Kronecker $\left(\dfrac{-4}{n}\right)$ la ham hoan toan nhan tinh, ta thu duoc

$$
f(n) = 4\sum_{d\mid n}\left(\dfrac{-4}{d}\right)=4\sum_{d\mid n}\chi_{4,3}(d).
$$

Ki hieu trong tong ben phai cung dung su that rang ki hieu Kronecker $\left(\dfrac{-4}{n}\right)$ la [dac trung Dirichlet](https://en.wikipedia.org/wiki/Dirichlet_character) thuc modulo $4$.

<span id="&#x52fe;&#x80a1;&#x65b9;&#x7a0b;"></span>
### Phuong trinh Pythagoras

Dung so nguyen Gauss co the tim nghiem tong quat cua phuong trinh Pythagoras. Phuong trinh Pythagoras la phuong trinh vo dinh bac hai sau:

$$
x^2+y^2=z^2.
$$

So sanh voi noi dung phan truoc, dieu nay tuong duong voi viec giai phuong trinh $N(x+y\mathrm{i})=z^2$. Gia su $z$ co phan tich thua so nguyen to trong $\mathbf Z$ la

$$
z=2^kp_1^{r_1}\cdots p_\ell^{r_\ell}q_1^{s_1}\cdots q_{m}^{s_m},
$$

thi nghiem $x+y\mathrm{i}$ cua no trong $\mathbf Z[\mathrm{i}]$ co phan tich thua so nguyen to

$$
x+y\mathrm{i} = u(1+\mathrm{i})^{2k}(a_1+b_1\mathrm{i})^{r_{1}^+}(a_1-b_1\mathrm{i})^{r_{1}^-}\cdots(a_\ell+ b_\ell\mathrm{i})^{r_\ell^+}(a_\ell-b_\ell\mathrm{i})^{r_\ell^-}q_1^{s_1}\cdots q_{m}^{s_m}
$$

va $r_j^++r_j^-=2r_j$. Co the tinh uoc chung lon nhat cua $x+y\mathrm{i}$ va $z$, thu duoc so nguyen sau:

$$
\kappa = 2^kp_1^{\min\{r_1^+,r_1^-\}}\cdots p_\ell^{\min\{r_\ell^+,r_\ell^-\}}q_1^{s_1}\cdots q_m^{s_m}.
$$

Rut gon uoc chung nay, thi $\kappa^{-1}(x+y\mathrm{i})$ chi chua cac thua so nguyen to dang $a_j\pm b_j\mathrm{i}$, cac thua so lien hop khong xuat hien thanh cap, va cac so mu $|r_j^+-r_j^-|$ cua chung nhat dinh chan (vi tong cua chung $2r_j$ la chan). Do do, $\kappa^{-1}(x+y\mathrm{i})$ la binh phuong cua mot so nguyen bac hai nao do $u+v\mathrm{i}$. Tu day thu duoc phuong trinh:

$$
x+y\mathrm{i} = \kappa(u+v\mathrm{i})^2,\ z=\kappa N(u+v\mathrm{i}).
$$

Trong so nguyen $\mathbf Z$, dieu nay tuong duong voi he phuong trinh

$$
x = \kappa(u^2-v^2),\ y = 2\kappa uv,\ z = \kappa(u^2+v^2).
$$

Nguoc lai, voi moi so nguyen $u$ va $v$, bieu thuc tren cho bo ba $(x,y,z)$ thoa man phuong trinh Pythagoras. Vi vay, day la nghiem tong quat cua phuong trinh Pythagoras.

Tu qua trinh tren co the biet rang, trong bo so Pythagoras nguyen thuy $(x,y,z)$ (tuc $x,y,z$ co uoc chung bang mot), $x,y$ nhat dinh mot le mot chan, $z$ le va chi chua cac thua so nguyen to dang $4k+1$.

Dung phuong phap tuong tu con co the tim nghiem tong quat cua phuong trinh $x^2+y^2=z^3$, hoac chung minh phuong trinh $x^4+y^4=z^4$ vo nghiem. Di nhien, dung nghiem tong quat cua phuong trinh Pythagoras va phuong phap lui vo han, co the chung minh ket qua manh hon: phuong trinh $x^4+y^4=z^2$ vo nghiem.

<span id="eisenstein-&#x6574;&#x6570;"></span>
## So nguyen Eisenstein

Trong phan nay, dat $\omega=\dfrac{-1+\sqrt{3}\mathrm{i}}{2}=e^{2\pi\mathrm{i}/3}$.[^omega] Truong bac hai $\mathbf Q(\sqrt{3}\mathrm{i})$ la [truong cyclotomic](../algebra/field-theory.md#%E5%88%86%E5%9C%86%E5%9F%9F) bac ba va bac sau; cac so nguyen dai so trong do duoc goi la so nguyen Eisenstein. Vanh gom tat ca so nguyen Eisenstein $\mathbf Z[\omega]$ duoc goi la vanh so nguyen Eisenstein. Vanh so nguyen Eisenstein co sau don vi, lan luot la $\pm 1$, $\pm\omega$ va $\pm\omega^2$. Tren mat phang phuc, tat ca so nguyen Eisenstein tao thanh cac diem cua luoi tam giac. Khac voi so nguyen Gauss, cac diem luoi o day noi chung khong phai diem nguyen.

![](./images/eisenstein-integer.svg)

Chuan cua so nguyen Eisenstein la

$$
N(a+b\omega) = a^2-ab+b^2,
$$

va no cung la binh phuong khoang cach tu diem luoi tren den goc toa do trong mat phang phuc.

So nguyen Eisenstein cung rat giong so nguyen Gauss. Tren so nguyen Eisenstein cung co the dung chuan $N(\cdot)$ de dinh nghia phep chia co du, roi thiet lap thuat toan Euclid, dinh li Bezout, dinh li phan tich duy nhat, v.v. Tuong tu phan tren, co the suy ra cac thua so cua so nguyen to trong vanh so nguyen Eisenstein. De lam viec nay, chu y rang biet thuc cua $\mathbf Z[\omega]$ la $-3$, va ki hieu Kronecker

$$
\left(\dfrac{-3}{n}\right) = \begin{cases}
+1, & n\equiv 1\pmod 3,\\
-1, & n\equiv 2\pmod 3,\\
0,  & 3\mid n,
\end{cases}
$$

Do do, cac phan tu nguyen to trong vanh so nguyen Eisenstein, hay so nguyen to Eisenstein, co ba loai sau:

1.  Cac so nguyen to dang $3k+2$ trong so nguyen, tuc $2$ va cac so nguyen to dang $6k+5$;
2.  Hai thua so nguyen to Eisenstein lien hop cua cac so nguyen to dang $3k+1$ trong so nguyen (tuc so nguyen to dang $6k+1$);
3.  Thua so $(3+\sqrt{3}\mathrm{i})/2$ cua so nguyen to $3$, lien hop cua no lien ket voi no.

Dung phuong phap cua phan truoc, co the tim so so nguyen Eisenstein co chuan bang $n$. Ki hieu so nay la $f(n)$, khi do

$$
f(n)=6\sum_{d\mid n}\left(\dfrac{-3}{d}\right)=6\sum_{d\mid n}\chi_{3,2}(d). 
$$

Trong do $\chi_{3,2}(n)=\left(\dfrac{-3}{n}\right)$ la dac trung Dirichlet thuc modulo $3$. Bieu thuc nay cho thay cac so nguyen Eisenstein nhu vay ton tai khi va chi khi moi thua so nguyen to dang $3k+2$ cua $n$ deu co so mu chan.

Theo cong thuc chuan o tren, $f(n)$ cung la so nghiem cua phuong trinh vo dinh $x^2-xy+y^2=n$ hoac $x^2+xy+y^2=n$. Y nghia hinh hoc cua no la so diem nguyen tren cac ellipse xieng $x^2\pm xy+y^2=n$.

Lien quan chat che voi cac phuong trinh nay la mot phuong trinh vo dinh khac, $x^2+3y^2=n$; nghiem nguyen cua no tuong ung voi cac diem nguyen tren ellipse chuan. Doi bien $x=(u+v)/2$ va $y=(u-v)/2$ co the chuyen no thanh phuong trinh da giai $u^2-uv+v^2=n$. Tuy nhien, mac du moi nghiem nguyen cua $x^2+3y^2=n$ deu tuong ung voi mot nghiem nguyen cua $u^2-uv+v^2=n$, chieu nguoc lai khong nhat thiet dung. Neu $n$ chan, thi $u$ va $v$ nhat dinh deu chan, nghia la $x$ va $y$ nhat dinh la so nguyen; khi do so nghiem nguyen cua $x^2+3y^2=n$ van la $f(n)$. Nhung neu $n$ le, thi $u$ va $v$ co the mot le mot chan, hoac deu le, nen $x$ va $y$ tuong ung co the deu la ban nguyen hoac deu la so nguyen. Truong hop nay can thao luan ki hon.

Khi biet mot nghiem nguyen $(u,v)$ cua phuong trinh $u^2-uv+v^2=n$, cac so nguyen Eisenstein lien ket voi $u+v\omega$ (ke ca chinh no) tuong ung voi cac nghiem nguyen sau:

$$
(u,v),(u-v,u),(-v,u-v),(-u,-v),(v-u,-u),(v,v-u).
$$

Vi trong ba so nguyen $u,v,u-v$, neu khong phai tat ca deu chan thi nhat dinh co hai so le va mot so chan, nen trong sau nghiem nguyen tren nhat dinh co hai nghiem toan le va bon nghiem mot le mot chan. Dieu nay cho thay khi $n$ le, chi co $\dfrac13$ so nghiem nguyen cua phuong trinh $u^2-uv+v^2=n$ la toan le, va chi khi do chung moi tuong ung voi nghiem nguyen cua $x^2+3y^2=n$. Vi vay khi $n$ le, so nghiem nguyen cua $x^2+3y^2=n$ la $\dfrac13f(n)$.

Cuoi cung, tuong tu cach giai phuong trinh Pythagoras, co the dung so nguyen Eisenstein de giai cac phuong trinh vo dinh sau:

$$
x^2-xy+y^2=z^2
$$

$$
x^2+xy+y^2=z^2
$$

$$
x^2+3y^2=z^2
$$

$$
x^2+3y^2=z^3
$$

Nghiem tong quat cua chung khong duoc trinh bay them o day. Phuong phap tuong tu cung co the dung de chung minh $x^3+y^3=z^3$ vo nghiem.

<span id="&#x53c2;&#x8003;&#x6587;&#x732e;&#x4e0e;&#x6ce8;&#x91ca;"></span>
## Tai lieu tham khao va chu thich

-   [Quadratic field - Wikipedia](https://en.wikipedia.org/wiki/Quadratic_field)
-   [Quadratic integer - Wikipedia](https://en.wikipedia.org/wiki/Quadratic_integer)
-   [Gaussian integer - Wikipedia](https://en.wikipedia.org/wiki/Gaussian_integer)
-   [Eisenstein integer - Wikipedia](https://en.wikipedia.org/wiki/Eisenstein_integer)
-   [Kronecker symbol - Wolfram MathWorld](https://mathworld.wolfram.com/KroneckerSymbol.html)
-   [Dirichlet character - Wikipedia](https://en.wikipedia.org/wiki/Dirichlet_character)
-   [Theodorus J. Dekker's Notes on Primes in Quadratic Fields](https://staff.science.uva.nl/t.j.dekker/PrimesPaper/Primes.pdf)
-   [Franz Lemmermeyer's Notes on Ideals in Quadratic Number Fields](http://www.fen.bilkent.edu.tr/~franz/ant/ant02.pdf)
-   [J.S. Milne - Algebraic Number Theory](https://www.jmilne.org/math/CourseNotes/ANT301.pdf)

[^omega]: Chu y rang cach chon $\omega$ o day khac voi cach chon o tren. Theo quy uoc, khi thao luan vanh so nguyen bac hai tong quat, thuong quy dinh $\omega=(1+\sqrt{d})/2$ (khi $d\equiv 1\pmod4$), con voi vanh so nguyen Eisenstein lai thuong quy dinh $\omega=(-1+\sqrt{-3})/2$. Khac biet nay khong co anh huong ban chat nao, nhung co the lam thay doi hinh thuc cua mot so bieu thuc. Chu y khong nen viet vanh so nguyen Eisenstein thanh $\mathbf Z[\sqrt{-3}]$.
