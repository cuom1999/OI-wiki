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
### Chia het, lien ket va don vi

Tuong tu so nguyen, ta cung co the xay dung li thuyet chia het cho so nguyen bac hai. Di nhien viec thao luan phai duoc thuc hien trong cung mot vanh so nguyen bac hai.

Voi cac so nguyen bac hai $\alpha$ va $\beta$ trong vanh so nguyen bac hai $\mathbf Z[\omega]$, neu ton tai so nguyen bac hai $\gamma$ trong cung vanh sao cho $\beta=\alpha\gamma$, thi noi $\alpha$ chia het $\beta$, ki hieu $\alpha\mid\beta$. Quan he chia het la mot quan he [thu tu bo phan](../order-theory.md#%E4%BA%8C%E5%85%83%E5%85%B3%E7%B3%BB) tren vanh so nguyen bac hai. Neu dong thoi co $\alpha\mid\beta$ va $\beta\mid\alpha$, thi khi nghien cuu li thuyet chia het co the xem $\alpha$ va $\beta$ nhu cung mot so; chung duoc goi la **lien ket** (associate). Quan he lien ket la mot quan he tuong duong tren vanh so nguyen bac hai.

Trong li thuyet chia het cua so nguyen, quan he lien ket chinh la quan he doi nhau. Thong thuong chi can xet cac so tu nhien trong li thuyet chia het, khong can xet truong hop so am. Doi voi so nguyen bac hai, quan he lien ket co the phuc tap hon. Neu hai so nguyen bac hai $\alpha$ va $\beta$ lien ket, thi ton tai cac so nguyen bac hai $\gamma$ va $\delta$ sao cho $\beta=\alpha\gamma$ va $\alpha=\beta\delta$. Do do, thuong $\gamma$ cua $\beta$ va $\alpha$ nhat dinh la mot so nguyen bac hai dac biet: ton tai so nguyen bac hai $\delta$ sao cho $\gamma\delta=1$. So nguyen bac hai $\gamma$ nhu vay duoc goi la **don vi** (unit), hay phan tu kha nghich. Hai so nguyen bac hai lien ket khi va chi khi thuong cua chung la don vi. Vi vay, muon hieu quan he lien ket tren vanh so nguyen bac hai thi can hieu cau truc cac don vi cua vanh do.

Vi chuan bao toan phep nhan va chuan cua so nguyen bac hai luon la so nguyen, ta co the dung chuan de chuyen quan he chia het cua so nguyen bac hai thanh quan he chia het cua so nguyen. Noi cach khac, neu $\alpha\mid\beta$ thi nhat dinh $N(\alpha)\mid N(\beta)$. Tuong tu, so nguyen bac hai $\alpha$ la don vi khi va chi khi chuan cua no $N(\alpha)=\pm 1$. Do do, de tim tat ca don vi trong vanh so nguyen bac hai $\mathbf Z[\omega]$, chi can giai phuong trinh vo dinh:

$$
N(a+b\sqrt{d})=1,
$$

trong do bieu thuc cua chuan la

$$
N(a+b\sqrt{d})=\begin{cases}
a^2+ab+\dfrac{1-d}{4}b^2, & d\equiv 1\pmod 4,\\
a^2-db^2, & d\equiv 2,3\pmod 4.
\end{cases}
$$

Voi vanh so nguyen bac hai ao, tuc $d<0$, vi chuan nhat dinh la so nguyen khong am, de dang kiem tra rang voi moi so am khong chua nhan tu chinh phuong $d\neq -1,-3$, nghiem chi la $(a,b)=(\pm 1,0)$; tuc ngoai $\mathbf Z[\sqrt{-1}]$ va $\mathbf Z[\frac{1+\sqrt{-3}}{2}]$, cac vanh so nguyen bac hai ao chi co cac don vi $\pm 1$. Dat $\mathrm{i}=\sqrt{-1}$, vanh so nguyen bac hai $\mathbf Z[\mathrm{i}]$ con duoc goi la vanh so nguyen Gauss; tap don vi cua no la $\{\pm 1,\pm\mathrm{i}\}$. Dat $\omega=\frac{1+\sqrt{-3}}{2}$, vanh so nguyen bac hai $\mathbf Z[\omega]$ con duoc goi la vanh so nguyen Eisenstein; tap don vi cua no la $\{\pm 1,\pm\omega,\pm\omega^2\}$.

Voi vanh so nguyen bac hai thuc, tuc $d>0$, tinh hinh phuc tap hon va co the chuyen thanh thao luan ve [phuong trinh Pell](./pell-equation.md). Tu cac ket qua ve phuong trinh Pell, tap tat ca don vi khi do co the viet la $\{\pm u^k:k\in\mathbf Z\}$, trong do $u$ duoc goi la **don vi co ban** (fundamental unit). Co the tim don vi co ban thong qua phuong trinh Pell tuong ung. Don vi co ban khong duy nhat: neu $u$ la don vi co ban thi lien hop $\bar u$ cua no, cung nhu $-u$ va $-\bar u$, deu la don vi co ban.

Cau truc cac don vi cua vanh so nguyen bac hai co the mo rong sang [vanh so nguyen dai so](../algebra/field-theory.md#%E4%BB%A3%E6%95%B0%E6%89%A9%E5%BC%A0) tong quat. [Dinh li don vi Dirichlet](https://en.wikipedia.org/wiki/Dirichlet%27s_unit_theorem) trong so hoc dai so phat bieu rang tat ca don vi cua moi vanh so nguyen dai so lap thanh mot [nhom Abel huu han sinh](../algebra/group-theory.md#%E6%9C%89%E9%99%90%E7%94%9F%E6%88%90-abel-%E7%BE%A4), dong thoi dinh li nay cung cho biet hang cua nhom do.

Cac noi dung trong li thuyet chia het cua so nguyen nhu uoc chung lon nhat, phep chia co du, dinh li Bezout, dinh li phan tich duy nhat, v.v. deu co the mo rong len mot phan hoac toan bo cac vanh so nguyen bac hai. Viec co the thuc hien cac mo rong nhu vay tren mot vanh so nguyen bac hai hay khong thuc ra phan anh tinh chat cua vanh do co du gan voi vanh so nguyen hay khong. Khong phai moi vanh so nguyen bac hai deu thoa man dinh li phan tich duy nhat; trong cac vanh thoa man dinh li phan tich duy nhat, cung chi mot phan cho phep thuc hien phep chia co du. Co the tham khao muc [vanh so nguyen bac hai](../algebra/ring-theory.md#%E4%BE%8B%E5%AD%90%E4%BA%8C%E6%AC%A1%E6%95%B4%E6%95%B0%E7%8E%AF) trong phan li thuyet vanh hoac cac sach lien quan de biet them ve noi dung nay.

<span id="&#x552f;&#x4e00;&#x5206;&#x89e3;"></span>
### Phan tich duy nhat

Neu dinh li phan tich duy nhat cua so nguyen co the mo rong len vanh so nguyen bac hai, no nen co dang sau: moi so nguyen bac hai trong vanh $\mathbf Z[\omega]$ deu co the viet thanh tich cua mot so phan tu bat kha quy, va phan tich nay la duy nhat neu bo qua lien ket va thu tu. O day [phan tu bat kha quy](../algebra/ring-theory.md#%E6%95%B4%E9%99%A4%E5%85%B3%E7%B3%BB) la so nguyen bac hai khong the tiep tuc phan tich thanh tich cua cac phan tu khong phai don vi, tuong tu so nguyen to trong dinh li phan tich duy nhat cua so nguyen. Nhung nhu da noi, khong phai moi vanh so nguyen bac hai deu thoa man dinh li phan tich duy nhat.

Vi du, trong $\mathbf Z[\sqrt{-5}]$ co phan tich $9=3\times 3=(2+\sqrt{-5})\times(2-\sqrt{-5})$, nhung $3$ va $2\pm\sqrt{-5}$ deu da la phan tu bat kha quy, nen phan tich khong duy nhat. De chi ra ba so nay deu bat kha quy, co the xet chuan cua chung: chuan cua chung deu bang $9$; neu chung co the phan tich thanh tich cua cac phan tu khong phai don vi, thi chuan cua cac thua so thu duoc chi co the bang $3$, nhung trong $\mathbf Z[\sqrt{-5}]$ khong co so nguyen bac hai nao co chuan bang $3$.

Nguyen nhan chinh khien dinh li phan tich duy nhat khong dung trong vanh so nguyen bac hai tong quat la viec phan tich chi bang so nguyen bac hai chua du tinh vi. Chuyen tuong tu la can phan tich tich $abcd$, nhung cac phan tu co ban kha dung chi la $\{ab,cd,ac,bd\}$, thi phan tich thu duoc tat nhien khong duy nhat; de co dinh li phan tich duy nhat, phai xet them $\{a,b,c,d\}$. Trong vanh so nguyen bac hai, cau truc tinh vi hon so nguyen bac hai la [ideal](../algebra/ring-theory.md#%E7%90%86%E6%83%B3) cua vanh so nguyen bac hai. Anh xa mot so nguyen bac hai den ideal chinh tuong ung cua no se nhung lop lien ket cua no vao tap cac ideal, vi vay phan tich so nguyen chi la truong hop dac biet cua phan tich ideal. Neu xet phan tich ideal trong vanh so nguyen bac hai, co the chung minh moi ideal cua vanh so nguyen bac hai deu phan tich duy nhat thanh tich cua mot so ideal nguyen to. Dieu nay cho thay cac vanh so nguyen bac hai deu la [mien Dedekind](https://en.wikipedia.org/wiki/Dedekind_domain). Tong quat hon, moi vanh so nguyen dai so deu la mien Dedekind.

Neu mot vanh so nguyen bac hai thoa man dinh li phan tich duy nhat, thi cac ideal nguyen to cua no tuong ung mot-mot voi cac phan tu bat kha quy (theo lop tuong duong lien ket). Vi vay, voi lop vanh so nguyen bac hai nay, phan tich ideal thanh ideal nguyen to tuong duong voi phan tich so nguyen bac hai thanh phan tu bat kha quy. Hon nua, khi do cac phan tu bat kha quy cung duoc goi la [phan tu nguyen to](../algebra/ring-theory.md#%E6%95%B4%E9%99%A4%E5%85%B3%E7%B3%BB), tuong ung voi khai niem so nguyen to trong so nguyen. Phan thao luan duoi day se dung ideal nguyen to va cac khai niem lien quan; doc gia chua quen khai niem nay co the thay chung tung chu mot bang phan tu nguyen to, khi do cac phat bieu van dung trong truong hop dinh li phan tich duy nhat dung.

De hieu hoan toan phan tich duy nhat tren vanh so nguyen bac hai tong quat $\mathbf Z[\omega]$, can biet cac ideal nguyen to trong $\mathbf Z[\omega]$ la nhung ideal nao. Truoc het, moi ideal nguyen to trong $\mathbf Z[\omega]$ deu chia chuan cua no (duoi dang ideal chinh). Phan tich chuan cua no trong cac so nguyen thanh tich cac so nguyen to; theo dinh li phan tich duy nhat, ideal nguyen to do nhat dinh chia mot trong cac thua so nguyen to nay (duoi dang ideal chinh). Vi vay, cac ideal nguyen to trong $\mathbf Z[\omega]$ nhat dinh thu duoc bang cach phan tich tiep cac so nguyen to trong $\mathbf Z$. De liet ke toan bo ideal nguyen to trong $\mathbf Z[\omega]$, chi can cho phan tich duy nhat cua so nguyen to $p$ cua $\mathbf Z$ (duoi dang ideal chinh) trong $\mathbf Z[\omega]$. Vi chuan cua so nguyen to $p$ (duoi dang ideal chinh) trong $\mathbf Z[\omega]$ la $p^2$, ma phan tich cua no thanh ideal nguyen to co nghia chuan cua cac ideal nguyen to chi co the la uoc cua $p^2$, nen chi co the la $p$ hoac $p^2$. Dieu nay cho thay chi co ba kha nang sau:

1.  $p$ **bat dong** (inert) trong $\mathbf Z[\omega]$, tuc $(p)$ van la ideal nguyen to trong $\mathbf Z[\omega]$;
2.  $p$ **tach** (split) trong $\mathbf Z[\omega]$, tuc $(p)$ co the viet thanh tich cua hai ideal nguyen to lien hop khac nhau trong $\mathbf Z[\omega]$;
3.  $p$ **phan nhanh** (ramify) trong $\mathbf Z[\omega]$, tuc $(p)$ co the viet thanh binh phuong cua mot ideal nguyen to.

Co the chung minh them rang, de xac dinh mot so nguyen to $p$ roi vao truong hop nao trong ba truong hop tren, chi can tinh [ki hieu Kronecker](https://en.wikipedia.org/wiki/Kronecker_symbol) $\left(\dfrac{D}{p}\right)$ voi biet thuc $D$ cua truong bac hai chua $\mathbf Z[\omega]$ va so nguyen to $p$. Ba truong hop nay tuong ung voi ba gia tri cua ki hieu Kronecker: $-1$, $+1$ va $0$. Khi $p$ la so nguyen to le, ki hieu Kronecker chinh la [ki hieu Legendre](./quad-residue.md#legendre-%E7%AC%A6%E5%8F%B7), va ba truong hop tuong ung voi $D$ la [khong thang du bac hai](./quad-residue.md), $D$ la [thang du bac hai](./quad-residue.md), va $p$ chia $D$. Khi $p=2$, ba truong hop lan luot tuong ung voi $D\equiv \pm 3\pmod 8$, $D\equiv \pm 1\pmod 8$ va $2$ chia $D$.

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
