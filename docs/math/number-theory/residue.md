Kiến thức nền tảng: [Logarit rời rạc](./discrete-logarithm.md)

Bài viết này thảo luận về thặng dư bậc cao và căn đơn vị theo modulo, đồng thời giới thiệu các thuật toán khai căn theo modulo.

<span id="&#39640;&#27425;&#21097;&#20313;"></span>
## Thặng dư bậc cao

Thặng dư bậc cao trong phép toán modulo có thể được hiểu là việc xét khả năng khai lũy thừa bậc cao theo modulo. Đây là một sự tổng quát hóa của [thặng dư bậc hai](./quad-residue.md).

???+ abstract "Thặng dư bậc $k$"
    Cho so nguyen $k\geq 2$, so nguyen $a$ va so nguyen duong $m$ nguyen to cung nhau. Neu ton tai so nguyen $x$ sao cho
    
    $$
    x^k\equiv a\pmod m,
    $$
    
    thi $a$ duoc goi la **thang du bac $k$** ($k$-th residue) modulo $m$, va $x$ duoc goi la **can bac $k$** ($k$-th root) cua $a$ modulo $m$; nguoc lai, $a$ duoc goi la **bat thang du bac $k$** ($k$-th nonresidue) modulo $m$.

Noi cach khac, can bac $k$ cua $a$ modulo $m$ ton tai khi va chi khi $a$ la thang du bac $k$ modulo $m$.

<span id="&#24615;&#36136;"></span>
### Tính chất

Tuong tu thang du bac hai, ta co the thao luan ve bai toan kiem tra thang du bac $k$, so luong nghiem va so lop thang du bac $k$. Giong cac bai toan [phuong trinh dong du](./congruence-equation.md) khac, co the dung [dinh ly thang du Trung Hoa](./crt.md) de dua chung ve truong hop modulo luy thua cua so nguyen to. Tuy theo viec co ton tai can nguyen thuy hay khong, truong hop nay tiep tuc tach thanh modulo luy thua cua so nguyen to le va modulo luy thua cua $2$.

Truong hop modulo luy thua cua so le tuong doi don gian. Thuc ra, trong moi truong hop co can nguyen thuy, ta co ket qua sau:

???+ note "Định lý"
    Cho so nguyen $k\geq 2$, so nguyen $a$ va so nguyen duong $m$ nguyen to cung nhau. Gia su ton tai can nguyen thuy modulo $m$, va $g$ la mot can nguyen thuy modulo $m$. Dat $d=\gcd(k,\varphi(m))$ va $d'=\dfrac{\varphi(m)}{d}$, trong do $\varphi(m)$ la [ham Euler](./euler-totient.md). Khi do:
    
    1.  $a$ la thang du bac $k$ modulo $m$ khi va chi khi
    
        $$
        a^{d'} \equiv 1 \pmod m.
        $$
    2.  Khi $a$ la thang du bac $k$ modulo $m$, xet theo dong du, $a$ co dung $d$ can bac $k$ phan biet modulo $m$, va chung co dang
    
        $$
        x \equiv g^{y_0+id'}\pmod{\varphi(m)},~0\le y_0 < d',~i=0,1,\cdots,d-1.
        $$
    3.  So lop thang du bac $k$ modulo $m$ la $d'$, va toan bo cac lop do la
    
        $$
        \{g^{di}\bmod m : 0 \le i < d'\}.
        $$

??? note "Chứng minh"
    Vi $a\perp m$, nen $x\perp m$. Vi $g$ la can nguyen thuy modulo $m$, ca $x$ va $a$ deu dong du voi mot luy thua nao do cua $g$. Dat $x\equiv g^y\pmod m$, phuong trinh $x^k\equiv a\pmod m$ tuong duong voi
    
    $$
    g^{ky} \equiv g^{\operatorname{ind}_g a}\pmod m.
    $$
    
    Trong do, $\operatorname{ind}_g a$ la logarit roi rac. Theo [tinh chat cua cap](./primitive-root.md#%E5%B9%82%E7%9A%84%E5%BE%AA%E7%8E%AF%E7%BB%93%E6%9E%84) va $\delta_m(g)=\varphi(m)$, dieu nay tuong duong voi phuong trinh dong du
    
    $$
    ky \equiv \operatorname{ind}_g a \pmod{\varphi(m)}.
    $$
    
    Day la [phuong trinh dong du tuyen tinh](./linear-equation.md) theo $y$. Ap dung phan tich ve cau truc nghiem o trang do, phuong trinh co nghiem khi va chi khi $d\mid\operatorname{ind}_g a$, va nghiem tong quat co dang
    
    $$
    y = y_0 + id' \pmod{\varphi(m)},~0\le y_0 < d',~i=0,1,\cdots,d-1.
    $$
    
    Tu day gan nhu suy ra toan bo noi dung dinh ly; diem duy nhat can giai thich them la tieu chuan $a^{d'} \equiv 1 \pmod m$. Theo [tinh chat 3 cua cap](./primitive-root.md#ord-prop-3), ta co
    
    $$
    \delta_m(a) = \delta_m(g^{\operatorname{ind}_g a}) = \dfrac{\varphi(m)}{\gcd(\varphi(m),\operatorname{ind}_g a)} = \dfrac{\varphi(m)}{\operatorname{ind}_g a}.
    $$
    
    Mat khac, da biet phuong trinh co nghiem khi va chi khi $d\mid \operatorname{ind}_g a$, tuc la $\delta_m(a)\mid d'$. Theo [tinh chat 2 cua cap](./primitive-root.md#ord-prop-2), dieu nay tuong duong voi tieu chuan tren.

Truong hop modulo luy thua cua $2$ dac biet hon. De xu ly truong hop nay, can dung mot [ket qua](./primitive-root.md#mod-pow-2) ve cau truc he thang du thu gon modulo $2^e$: moi so le $a$ deu dong du duy nhat voi mot so co dang $(-1)^s5^r\bmod 2^e$, trong do $s\in\{0,1\}$ va $0\le r < 2^{e-2}$. Nho ket qua nay, ta co ket luan sau:

???+ note "Định lý"
    Cho so nguyen $k\ge 2$, so le $a$ va so nguyen duong $m=2^e$ voi $e \ge 2$. Khi $k$ la so le:
    
    1.  $a$ luon la thang du bac $k$ modulo $m$.
    2.  $a$ co dung mot can bac $k$ modulo $m$.
    3.  So lop thang du bac $k$ modulo $m$ la $2^{e-1}$, va chung chinh la toan bo cac lop thang du thu gon.
    
    Khi $k$ la so chan, dat $d=\gcd(k,2^{e-2})$ va $d'=\dfrac{2^{e-2}}{d}$, ta co:
    
    1.  $a$ la thang du bac $k$ modulo $m$ khi va chi khi $a\equiv 1\pmod 4$ va $a^{d'}\equiv 1\pmod m$.
    2.  Khi $a$ la thang du bac $k$ modulo $m$, xet theo dong du, $a$ co dung $2d$ can bac $k$ phan biet modulo $m$, va chung co dang
    
        $$
        x \equiv \pm 5^{y_0 + id'} \pmod{2^{e-1}},~ 0 \le y_0 < d',~i = 0, 1,\cdots,d-1. 
        $$
    3.  So lop thang du bac $k$ modulo $m$ la $d'$, va toan bo cac lop do la
    
        $$
        \{5^{di}\bmod m : 0 \le i < d'\}.
        $$

??? note "Chứng minh"
    Vi $a\perp m$, nen $x\perp m$. Vi $x$ va $a$ deu la so le, theo ket qua vua neu, co the dat $a\equiv (-1)^s5^r\pmod{2^e}$ va $x=(-1)^z5^{y}\pmod{2^e}$. Do bieu dien la duy nhat, phuong trinh dong du $x^k\equiv a\pmod{2^e}$ tuong duong voi he [phuong trinh dong du tuyen tinh](./linear-equation.md)
    
    $$
    \begin{aligned}
    kz &\equiv s \pmod{2},\\
    ky &\equiv r \pmod{2^{e-2}}.
    \end{aligned}
    $$
    
    Ket hop voi phan tich ve nghiem cua phuong trinh dong du tuyen tinh o trang do, ta thu duoc cau truc nghiem cua phuong trinh dong du $x^k\equiv a\pmod{2^e}$. Tuy theo tinh chan le cua $k$, co hai truong hop:
    
    -   Khi $k$ la so le, vi $\gcd(k,2)=\gcd(k,2^{e-2})=1$, ca hai phuong trinh dong du tuyen tinh deu co nghiem voi moi $s,r$, nen phuong trinh ban dau luon co nghiem voi moi so le $a$.
    -   Khi $k$ la so chan, phuong trinh thu nhat co nghiem khi va chi khi $2\mid s$, phuong trinh thu hai co nghiem khi va chi khi $d=\gcd(k,2^{e-2})\mid r$. Ket hop hai dieu kien nay se cho toan bo cac lop thang du bac $k$. Tinh truc tiep thay dieu kien thu nhat tuong duong voi $a\equiv 1\pmod 4$; lap lai phan tich trong truong hop modulo luy thua cua so nguyen to le, dieu kien thu hai tuong duong voi $a^{d'}=1$. Ket hop hai diem nay se cho tieu chuan trong dinh ly. Nghiem tong quat cua hai phuong trinh dong du tuyen tinh cung da biet:
    
        $$
        \begin{aligned}
        z &\equiv0,1\pmod 2, \\
        y &\equiv y_0 + id' \pmod{2^{e-2}},~ 0\le y_0 < 2^{e-2}.
        \end{aligned}
        $$
    
        Ket hop chung se thu duoc nghiem tong quat cua phuong trinh ban dau.

Nhu vay bai toan kiem tra thang du bac $k$ voi cac modulo khac nhau da duoc giai quyet day du. Ky hieu Legendre va luat tuong ho bac hai trong thang du bac hai cung co the tong quat hoa sang thang du bac cao, nhung dieu nay khong de va can den cac khai niem nhu [truong chia duong tron](../algebra/field-theory.md#%E5%88%86%E5%9C%86%E5%9F%9F). Trong ly thuyet so dai so, luat tuong ho bac hai cuoi cung co the duoc tong quat thanh [luat tuong ho Artin](https://en.wikipedia.org/wiki/Artin_reciprocity).

<span id="&#21333;&#20301;&#26681;"></span>
## Căn đơn vị

La mot truong hop dac biet cua can bac $k$, muc nay thao luan ve khai niem can don vi (nguyen thuy) bac $k$. No co the xem la doi ung cua khai niem [can don vi](../complex.md#%E5%8D%95%E4%BD%8D%E6%A0%B9) bac $k$ trong truong so phuc $\mathbf C$ tren he thang du thu gon $\mathbf Z_m^*$ modulo $m$. Khi modulo $m$ phu hop, co the dung can don vi nguyen thuy bac $k$ modulo $m$ thay cho can phuc $\omega_k$ de tang toc tinh toan.

Tuong tu truong hop tren truong so phuc, ta co dinh nghia sau:

???+ abstract "Căn đơn vị bậc $k$ modulo $m$"
    Voi modulo $m$, can bac $k$ cua phan tu $1$ duoc goi la **can don vi bac $k$ modulo $m$** ($k$-th root of unity modulo $m$). Dac biet, neu $x$ la mot can don vi bac $k$ modulo $m$ va khong phai la can don vi bac $k' < k$ nao modulo $m$, thi $x$ duoc goi la **can don vi nguyen thuy bac $k$ modulo $m$** ($k$-th primitive root of unity modulo $m$).

So sanh voi [dinh nghia can nguyen thuy](./primitive-root.md#%E5%8E%9F%E6%A0%B9), ta thay can nguyen thuy $g$ chinh la can don vi nguyen thuy bac $\varphi(m)$ modulo $m$, trong do $\varphi(m)$ la [ham Euler](./euler-totient.md).

Khi can don vi nguyen thuy bac $k$ modulo $m$ ton tai, cac tinh chat dai so cua no trung voi can don vi phuc nguyen thuy bac $k$ la $\omega_k$, nen co the dung no thay $\omega_k$ trong nhieu phep tinh. Vi du, ap dung no vao [bien doi Fourier nhanh](../poly/fft.md) se thu duoc [bien doi so hoc nhanh](../poly/ntt.md) tren truong huu han[^fnnt].

<span id="&#24615;&#36136;_1"></span>
### Tính chất

Trong truong so phuc, can don vi (nguyen thuy) bac bat ky deu ton tai. Nhung trong so hoc, can don vi (nguyen thuy) khong phai luc nao cung ton tai.

???+ note "Tính chất"
    Voi modulo $m$, dat $\lambda(m)$ la [ham Carmichael](./primitive-root.md#carmichael-%E5%87%BD%E6%95%B0) cua no. Khi do:
    
    1.  Moi so nguyen $a$ nguyen to cung nhau voi $m$ deu la can don vi nguyen thuy bac $\delta_m(a)$ modulo $m$, trong do $\delta_m(a)$ la [cap](./primitive-root.md#%E9%98%B6) cua $a$ modulo $m$.
    2.  Neu phan tu $a$ la can don vi bac $k$ modulo $m$, va $k'$ la mot boi bat ky cua $k$, thi $a$ cung la can don vi bac $k'$ modulo $m$.
    3.  Neu phan tu $a$ la can don vi (nguyen thuy) bac $k$ modulo $m$, thi phan tu $a^{\ell}$ la can don vi bac $\dfrac{k}{\gcd(k,\ell)}$ modulo $m$ (tuong ung la nguyen thuy).
    4.  Khi $k'$ chay qua cac uoc cua $k$, toan bo can don vi nguyen thuy bac $k'$ modulo $m$ lap thanh mot phan hoach cua tap can don vi bac $k$ modulo $m$. Hon nua, voi $\ell\perp k$, anh xa $x\mapsto x^\ell$ cho mot song anh tren cac can don vi bac $k$ va giu nguyen phan hoach do: no van anh xa can don vi nguyen thuy bac $k'\mid k$ thanh can don vi nguyen thuy bac $k'$.
    5.  Can don vi nguyen thuy bac $k$ modulo $m$ ton tai khi va chi khi $k\mid\lambda(m)$. Dac biet, can don vi nguyen thuy bac $\lambda(m)$ modulo $m$ ton tai va duoc goi la **$\lambda$-can nguyen thuy modulo $m$**.
    6.  Phan tu $a$ la can don vi bac $k$ modulo $m$ khi va chi khi $a^k\equiv 1\pmod{m}$ va voi moi uoc nguyen to $p\mid k$ deu co $a^{k/p}\not\equiv 1\pmod{m}$.

??? note "Chứng minh"
    Theo dinh nghia cua cap, moi so nguyen $a$ nguyen to cung nhau voi $m$ deu la can don vi nguyen thuy bac $\delta_m(a)$ modulo $m$, trong do $\delta_m(a)$ la cap cua $a$ modulo $m$. Nguoc lai, neu $a$ la can don vi bac $k$ modulo $m$, thi $\gcd(a^k,m)=1$, nen $\gcd(a,m)=1$. Do do, $a$ la can don vi (nguyen thuy) modulo $m$ khi va chi khi $a$ nguyen to cung nhau voi $m$. Day la tinh chat 1.
    
    Kiem tra truc tiep tu dinh nghia thay rang chi can $k\mid k'$, tu $a^k\equiv 1\pmod m$ suy ra $a^{k'}\equiv 1\pmod m$; day la tinh chat 2. Theo [tinh chat cua cap](./primitive-root.md#ord-prop-3), ta co
    
    $$
    \delta(a^\ell) = \dfrac{\delta_m(a)}{\gcd(\delta_m(a),\ell)}.
    $$
    
    Neu $a$ la can don vi nguyen thuy bac $k$ modulo $m$, thi $\delta_m(a)=k$, thay truc tiep vao cong thuc tren se duoc $a^\ell$ la can don vi nguyen thuy bac $\dfrac{k}{\gcd(k,\ell)}$ modulo $m$. Neu $a$ chi la can don vi bac $k$ modulo $m$, gia su no la can don vi nguyen thuy bac $k'\mid k$, thi $a^\ell$ la can don vi nguyen thuy bac $\dfrac{k'}{\gcd(k',\ell)}$ modulo $m$. Vi $k'\mid k$, ta co
    
    $$
    \dfrac{k'}{\gcd(k',\ell)} \mid \dfrac{k}{\gcd(k,\ell)},
    $$
    
    roi theo tinh chat 2, $a^\ell$ la can don vi bac $\dfrac{k}{\gcd(k,\ell)}$ modulo $m$. Day la tinh chat 3.
    
    Voi $k'\mid k$, theo tinh chat 2, can don vi nguyen thuy bac $k'$ modulo $m$ tat nhien la can don vi bac $k$ modulo $m$. Cac tap nay doi mot khong giao nhau, nen tao thanh mot phan hoach. Voi $\ell\perp k$, luon co $\ell\perp k'$, do do neu $a$ la can don vi nguyen thuy bac $k'$ modulo $m$ thi $a^\ell$ van la can don vi nguyen thuy bac $k'$ modulo $m$. Lay $\ell'=\ell^{-1}\bmod k$, co the kiem tra $x\mapsto x^\ell$ va $x\mapsto x^{\ell'}$ la hai anh xa nguoc nhau; vi vay $x\mapsto x^\ell$ la song anh. Day la tinh chat 4.
    
    Theo tinh chat cua ham Carmichael, can don vi nguyen thuy bac $\lambda(m)$ modulo $m$ luon ton tai; goi no la $a$, voi $\delta_m(a)=\lambda(m)$. Voi $k\mid\lambda(m)$, dat $k'=\dfrac{\lambda(m)}{k}$, luon co
    
    $$
    \delta_m(a^{k'}) = \dfrac{\lambda(m)}{(\lambda(m),k')} = \dfrac{\lambda(m)}{k'} = k.
    $$
    
    Vi vay, $a^{k'}$ la can don vi nguyen thuy bac $k$. Mat khac, theo dinh nghia ham Carmichael, cap cua moi $x\perp m$ deu la uoc cua $\lambda(m)$. Suy ra tinh chat 5.
    
    Gan nhu lap lai chung minh cua [dinh ly kiem tra can nguyen thuy](./primitive-root.md#%E5%8E%9F%E6%A0%B9%E5%88%A4%E5%AE%9A%E5%AE%9A%E7%90%86) se thu duoc tinh chat 6. Tieu chuan nay thuc chat dang kiem tra $\delta_m(a)=k$.

Tu cac tinh chat tren co the thay, so voi truong hop ton tai can nguyen thuy, $\lambda$-can nguyen thuy modulo $m$ dong vai tro nen tang tuong tu. Khac voi can nguyen thuy, cac luy thua cua $\lambda$-can nguyen thuy khong the sinh ra toan bo cac can don vi modulo $m$. Du vay, vi mat do cua $\lambda$-can nguyen thuy khong qua thap[^lambda-density], neu can tim mot can don vi nguyen thuy bac $k$, co the truoc het dung phuong phap ngau nhien de tim mot $\lambda$-can nguyen thuy, roi lay luy thua cua no de thu duoc can don vi nguyen thuy bac $k$.

Neu da biet mot can bac $k$ cua $a$ modulo $m$, co the dung toan bo can don vi bac $k$ modulo $m$ de sinh ra toan bo can bac $k$ cua $a$ modulo $m$.

???+ note "Định lý"
    Gia su $x$ la mot can bac $k$ cua $a$ modulo $m$. Khi $r$ chay qua toan bo cac can don vi bac $k$ modulo $m$, $xr$ chay qua toan bo cac can bac $k$ cua $a$ modulo $m$.

??? note "Chứng minh"
    Voi hai can bac $k$ la $x,y$ cua $a$ modulo $m$, dat $r=x^{-1}y\bmod m$. Khi do $r$ thoa man $r^k\equiv 1\pmod m$, nen la can don vi bac $k$ modulo $m$. Nguoc lai, neu $r$ la can don vi bac $k$ modulo $m$, thi $(xr)^{k}= x^kr^k\equiv a\pmod m$, tuc la $xr$ la can bac $k$ cua $a$ modulo $m$.

Dung can don vi bac $k$ de sinh ra toan bo can bac $k$ tuong tu viec dung nghiem cua he phuong trinh tuyen tinh thuan nhat de sinh nghiem tong quat cua he phuong trinh tuyen tinh khong thuan nhat.

Phan tren thao luan truong hop tong quat. Rieng khi can nguyen thuy ton tai, cau truc cua can don vi don gian hon:

???+ note "Định lý"
    Voi modulo $m$, gia su ton tai can nguyen thuy modulo $m$, va $a$ la can don vi nguyen thuy bac $k$ modulo $m$. Khi do, $b$ la can don vi bac $k$ modulo $m$ khi va chi khi $b$ co the bieu dien thanh mot luy thua cua $a$.

??? note "Chứng minh"
    Goi $g$ la can nguyen thuy modulo $m$. Khi do moi phan tu nguyen to cung nhau voi $m$ deu co the bieu dien thanh mot luy thua cua $g$. Do do, $a$ la can don vi nguyen thuy bac $k$ modulo $m$ khi va chi khi
    
    $$
    \delta_m(a) = \delta_m(g^{\operatorname{ind}_ga}) = \dfrac{\varphi(m)}{\gcd(\varphi(m),\operatorname{ind}_ga)} = k.
    $$
    
    Tuong tu, $b$ la can don vi bac $k$ modulo $m$ khi va chi khi
    
    $$
    \delta_m(b) = \delta_m(g^{\operatorname{ind}_gb}) = \dfrac{\varphi(m)}{\gcd(\varphi(m),\operatorname{ind}_gb)} = k' \mid k.
    $$
    
    Vi vay, ta co
    
    $$
    \gcd(\varphi(m),\operatorname{ind}_ga) \mid \gcd(\varphi(m),\operatorname{ind}_gb)\mid \operatorname{ind}_gb.
    $$
    
    Theo [phan tich](./linear-equation.md) ve phuong trinh dong du tuyen tinh, dieu kien nay tuong duong voi viec phuong trinh
    
    $$
    (\operatorname{ind}_ga) x \equiv \operatorname{ind}_gb \pmod{\varphi(m)}
    $$
    
    co nghiem. Lay luy thua co co so $g$ cho dieu kien nay se duoc $a^x\equiv b\pmod{m}$, tuc la $b$ co the bieu dien thanh mot luy thua cua $a$.

Dinh ly nay cho thay, khi can nguyen thuy ton tai, toan bo cac can don vi bac $k$ co cau truc [nhom cyclic](../algebra/group-theory.md#%E5%BE%AA%E7%8E%AF%E7%BE%A4), va cac can don vi nguyen thuy bac $k$ la phan tu sinh cua nhom cyclic do. Ngay sau day ta se thay thuat toan Tonelli-Shanks tan dung diem nay de tang toc phan tinh logarit roi rac trong phep khai can.

<span id="&#27169;&#24847;&#20041;&#19979;&#24320;&#26041;"></span>
## Khai căn theo modulo

Cuoi cung, bai viet thao luan cach tim can bac $k$. Voi $k=2$, co [nhieu thuat toan hieu qua](./quad-residue.md#%E6%A8%A1%E6%84%8F%E4%B9%89%E4%B8%8B%E5%BC%80%E5%B9%B3%E6%96%B9) de khai can bac hai theo modulo. Tuy nhien, voi $k$ tong quat, hien chua biet thuat toan thoi gian da thuc. Muc nay gioi thieu hai thuat toan pho bien, lan luot co the tim mot can bac $k$ trong thoi gian $O(m^{1/2})$ va $O(m^{1/4+\varepsilon})$. Dung dinh ly thang du Trung Hoa luon co the dua bai toan ve truong hop modulo luy thua cua so nguyen to, vi vay muc nay chu yeu thao luan loi giai trong truong hop modulo luy thua cua so nguyen to.

<span id="&#26420;&#32032;&#31639;&#27861;"></span>
### Thuật toán trực tiếp

[Phan tich](#%E6%80%A7%E8%B4%A8) ve tinh chat cua thang du bac $k$ o tren thuc ra da chi ra mot cach tim can bac $k$ theo modulo luy thua cua so nguyen to. Noi chinh xac, phan tren da giai quyet truong hop so duoc khai can $a$ nguyen to cung nhau voi modulo $m$. Qua trinh thuat toan tom tat nhu sau:

-   Khi $m=p^e$ la luy thua cua so nguyen to le, gia su $g$ la mot can nguyen thuy modulo $m$. Khi do, phuong trinh $x^k\equiv a\pmod m$ co the chuyen thanh phuong trinh dong du tuyen tinh

    $$
    ky \equiv \operatorname{ind}_g a \pmod{\varphi(m)}.
    $$

    Trong do, $\operatorname{ind}_g a$ co the duoc tinh bang [thuat toan BSGS](./discrete-logarithm.md#%E5%A4%A7%E6%AD%A5%E5%B0%8F%E6%AD%A5%E7%AE%97%E6%B3%95), con toan bo nghiem cua [phuong trinh dong du tuyen tinh](./linear-equation.md) thi de tim. Tu do thu duoc tat ca can bac $k$ cua $a$, co dang $x\equiv g^y\pmod m$.

    Ngoai ra con mot y tuong tuong tu. Van dat $x\equiv g^y\pmod m$, co the bien doi

    $$
    x^k \equiv (g^k)^y \equiv a \pmod m
    $$

    thanh bai toan tim logarit roi rac cua $a$ voi co so $g^k$. Bai toan nay cung co the dung BSGS de tim mot nghiem rieng. Nghiem tong quat cua no co the suy ra tu bieu thuc nghiem o phan tren, tuc la nhan nghiem rieng lan luot voi toan bo can don vi bac $k$.

    Du dung y tuong nao, khi da biet can nguyen thuy, do phuc tap de tim mot nghiem cua thuat toan nay la $O(m^{1/2})$. Vi co the tim mot can nguyen thuy trong thoi gian $o(m^{1/2})$, tong do phuc tap van la $O(m^{1/2})$.

-   Khi $m=2^e$ va $e\in\mathbf N_+$, truoc het co the tim $s,r$ trong $a\equiv (-1)^s5^r\pmod m$. Trong hai so mu nay, $s$ co the xac dinh trong $O(1)$:

    $$
    s = \begin{cases}0, & a\equiv 1\pmod 4, \\ 1, & a\equiv 3\pmod 4.\end{cases}
    $$

    Con $r=\operatorname{ind}_5((-1)^sa)$ co the tinh bang thuat toan BSGS trong $O(m^{1/2})$. Tiep theo chi can giai he phuong trinh dong du tuyen tinh:

    $$
    \begin{aligned}
    kz &\equiv s \pmod{2},\\
    ky &\equiv r \pmod{2^{e-2}}.
    \end{aligned}
    $$

    Nghiem tong quat $(z,y)$ cua he tuyen tinh nay de tim, va $x=(-1)^z5^y$ chinh la can can tim. Do phuc tap de tim mot nghiem cua thuat toan nay van la $O(m^{1/2})$.

Tat nhien, voi truong hop vo nghiem, thuc ra co the dung tieu chuan da neu o tren de kiem tra nhanh trong $O(\log m)$, khong can doi den qua trinh giai moi phat hien.

Ma tham khao de tim can bac $k$ modulo so nguyen to nhu sau: (ma chi mang tinh minh hoa; do do phuc tap qua cao, khong the vuot qua bai nay)

??? example "Bài mẫu [Library Checker - Kth Root (Mod)](https://judge.yosupo.jp/problem/kth_root_mod), mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/residue/bsgs-mod-p.cpp"
    ```

<span id="&#25913;&#33391; Tonelli&#8211;Shanks &#31639;&#27861;"></span>
### Thuật toán Tonelli-Shanks cải tiến

Mo rong phu hop [thuat toan Tonelli-Shanks](./quad-residue.md#tonellishanks-%E7%AE%97%E6%B3%95) dung cho khai can bac hai theo modulo se giai quyet duoc phep khai can theo modulo luy thua cua so nguyen to. Mot cach mo rong truc tiep hon la thuat toan Adleman-Manders-Miller[^amm], nhung do phuc tap cua no van chua du tot[^amm-comp]. Muc nay gioi thieu thuat toan Tonelli-Shanks cai tien do sugarknri, Min\_25, 37zigen va nhung nguoi khac de xuat. No co the tim mot can bac $k$ trong thoi gian $O(m^{1/4+\varepsilon})$.

Y tuong cot loi cua thuat toan Tonelli-Shanks la dua viec tinh logarit roi rac vao nhom co cap $2^e$, tu do giam do phuc tap. Tuong tu, logarit roi rac trong nhom co cap la luy thua nguyen to bat ky $p^e$ cung co the duoc giai kha hieu qua, nhung do phuc tap cua thuat toan la $\Omega\left(\sqrt{p}\right)$. Thuat toan Adleman-Manders-Miller tach viec tim can bac $k$ thanh nhieu phep tinh logarit roi rac trong cac nhom co cap la luy thua nguyen to, nhung do bi gioi han boi kich thuoc cua thua so nguyen to lon nhat $p_\text{max}(k)$ cua $k$, do phuc tap van la $\Omega\left(\sqrt{p_\text{max}(k)}\right)$. Thuat toan trong muc nay cai tien them qua trinh do, tranh tinh logarit roi rac voi cac thua so nguyen to lon, va khong che tong do phuc tap o muc $O(m^{1/4+\varepsilon})$.

<span id="&#36807;&#31243;"></span>
#### Quy trình

Xet viec tinh can bac $k$ cua $a$ modulo luy thua so nguyen to $m$, tuc la giai phuong trinh dong du:

$$
x^k \equiv a \pmod m.
$$

Dac biet, voi truong hop $m=2^e$, con can bao dam $a\equiv 1\pmod{4}$, de $a$ co the viet thanh luy thua cua $g=5$. Tuong tu phan da thao luan, viec tinh can bac $k$ modulo $2^e$ luon co the chuyen ve truong hop nay. Khi xu ly truong hop modulo $2^e$, moi $\varphi(m)$ duoc nhac den trong muc nay deu nen thay bang $\delta_m(5)=2^{e-2}$.

Truoc het, bai toan co the duoc dua ve truong hop bac khai can chia het $\varphi(m)$. Dat $d=\gcd(k,\varphi(m))$. Khi do, theo tinh chat cua thang du bac $k$, neu $a$ la thang du bac $k$ modulo $m$, thi $a$ luon la can don vi bac $\dfrac{\varphi(m)}{d}$ modulo $m$. Theo tinh chat cua can don vi, voi moi $\ell\perp\dfrac{\varphi(m)}{d}$, anh xa $x\mapsto x^{\ell}$ deu la song anh tren cac can don vi bac $\dfrac{\varphi(m)}{d}$. Vi vay co the chon

$$
\ell = \left(\dfrac{k}{d}\right)^{-1}\bmod\dfrac{\varphi(m)}{d}.
$$

Lay luy thua bac $\ell$ hai ve cua phuong trinh dong du ban dau, ta duoc

$$
x^d\equiv x^{k\ell} \equiv a^{\ell} =: b \pmod{m}.
$$

Dong du dau tien dung [dinh ly Euler](./fermat.md#%E6%AC%A7%E6%8B%89%E5%AE%9A%E7%90%86) va quan he dong du sau: ($c\in\mathbf Z$)

$$
k\ell = d\left(\frac{k}{d}\ell\right) = d\left(c\dfrac{\varphi(m)}{d}+1\right) \equiv d \pmod{\varphi(m)}.
$$

Voi bai toan da chuyen doi, xet phan tich thua so nguyen to cua $d$:

$$
d = \prod_{p\in\mathbf P}p^e.
$$

Co the bat dau tu $b=a^\ell$, voi moi $p^e\neq 1$ thi lan luot khai can bac $p^e$; cuoi cung se thu duoc can bac $d$ cua $b$, cung chinh la can bac $k$ cua $a$.

Sau cung, bai toan chuyen thanh cach tim nghiem cua phuong trinh

$$
x^{p^e} \equiv b \pmod m.
$$

Khong mat tinh tong quat, gia su $\varphi(m)=p^sr$ va $p\perp r$. Goi $q\in\mathbf N_+$ la nghiem cua phuong trinh $qr\equiv -1\pmod{p^e}$. Khi do, vi $b$ la can don vi bac $rp^{s-e}$, $b^{qr}$ chac chan la can don vi bac $p^{s-e}$. Lai goi $\zeta$ la can don vi nguyen thuy bac $p^s$ modulo $m$. Khi do $\zeta^{p^e}$ la can don vi nguyen thuy bac $p^{s-e}$, nen ton tai $h\in\mathbf N$ sao cho $b^{qr}\equiv \zeta^{hp^{e}}\pmod{m}$. Vi vay, kiem tra truc tiep cho thay

$$
x\equiv b^{(qr+1)/p^e}\zeta^{-h} \pmod{m}
$$

la mot can bac $p^e$ cua $b$ modulo $m$.

De tinh $x$, can tim mot bat thang du bac $p$ la $\eta$ modulo $m$. Theo cac tinh chat da neu, chi can chon ngau nhien $\eta\perp m$ va kiem tra $\eta^{\varphi(m)/p}\bmod{m}\neq 1$. Mat do cua cac so nhu vay la

$$
\dfrac{\varphi(m)}{m}\left(1-\dfrac{1}{p}\right) \ge \dfrac{1}{4}.
$$

Do do, ky vong chi can thu khong qua $4$ so nguyen de tim duoc no. Chu y rang $\eta^{rp^{s-1}}\not\equiv 1\pmod m$ va $\eta^{rp^s}\equiv 1\pmod m$, nen neu dat $\zeta=\eta^r\bmod m$ va $\xi=\eta^{rp^{s-1}}\bmod m$, thi chung lan luot la can don vi nguyen thuy bac $p^s$ va bac $p$.

Cuoi cung, can tinh $h\in\mathbf N$. Hien nhien co the lay $h < p^{s-e}$. Xet bieu dien co so $p$ cua $h$:

$$
h = \sum_{j=0}^{s-e-1}h_jp^j = h_0 + h_1p + h_2p^2 +\cdots.
$$

Tinh tung chu so nay. Khi $j$ chu so dau da duoc tinh xong, tat yeu co

$$
\left(b^{qr}\zeta^{-p^e(h_0+h_1p+\cdots + h_{j-1}p^{j-1})}\right)^{p^{s-e-j-1}} \equiv \zeta^{h_jp^{s-1}} \equiv \xi^{h_j} \pmod{m}.
$$

Vi vay, $h_j$ co the tim bang cach tinh logarit roi rac theo co so $\xi$. De co do phuc tap tot hon, can dung thuat toan BSGS. Tong cong can tinh logarit roi rac $(s-e)$ lan; gia su tien xu ly $B$ luy thua cua $\xi$, thi thoi gian cho mot lan giai logarit roi rac la $O(p/B)$, va tong do phuc tap la

$$
O\left(B+(s-e)\dfrac{p}{B}\right).
$$

Khi $B=\sqrt{(s-e)p}$, tong do phuc tap dat nho nhat, bang $O\left(\sqrt{(s-e)p}\right)$. Sau khi thu duoc $h$, thay vao bieu thuc cua $x$ o tren se tim duoc mot nghiem rieng.

<span id="&#26102;&#38388;&#22797;&#26434;&#24230;"></span>
#### Độ phức tạp thời gian

Do phuc tap thoi gian cua thuat toan nay la $O(m^{1/4+\varepsilon})$. Khi thao luan ve do phuc tap trong muc nay, luon gia su mot phep nhan mat $O(1)$ thoi gian, va khi tinh luy thua thi luon dung dinh ly Euler de giam so mu; vi vay viec tinh tung luy thua lien quan luon co the hoan thanh trong $O(\log m)$.

Truoc het xet viec tinh mot can bac $p^e$. Tim bat thang du bac $p$ chi can kiem tra ky vong $O(1)$ so, tong thoi gian la $O(\log m)$. Tinh $s,r,\zeta,\eta,b^{qr}$ moi phan chi can $O(\log m)$. Khi tinh $h$, moi chu so can $O(\log m)$ thoi gian de tinh luy thua; tong cong co $(s-e)$ chu so, nen tong do phuc tap la $O((s-e)\log m)$. Phan tren da chi ra rang tong thoi gian tien xu ly va $(s-e)$ truy van de tinh logarit roi rac la $O\left(\sqrt{(s-e)p}\right)$. Vi $s-e\in O(\log m)$, do phuc tap thoi gian de tinh mot can bac $p^e$ la $O(p^{1/2+\varepsilon})$. Dac biet, khi $s=e$, do phuc tap co the giam them xuong $O(\log m)$.

Tiep theo xet tong do phuc tap cua thuat toan. Viec tinh $\varphi(m),d,\ell$ deu co do phuc tap $O(\log m)$. Ngay sau do can phan tich thua so nguyen to $d=\prod_p{p^e}$; buoc nay co the dung [thuat toan Pollard Rho](./pollard-rho.md#pollard-rho-%E7%AE%97%E6%B3%95) trong $O(m^{1/4})$. Cuoi cung, tong thoi gian de lan luot khai can bac $p^e$ la

$$
O\left(\sum_{e < s}p^{1/2+\varepsilon}\right).
$$

Vi moi thua so nguyen to $p$ thoa man $e < s$ xuat hien it nhat $2$ lan trong $\varphi(m)$, nen chac chan $p < m^{1/2}$. Do do, tong do phuc tap thoi gian la $O(m^{1/4+\varepsilon})$.

Thuc ra, trong boi canh nay, khong can dung thuat toan Pollard Rho de phan tich thua so nguyen to ma van co the dat do phuc tap $O(m^{1/4+\varepsilon})$. Chi can thu chia truc tiep $d$ va chi liet ke cac thua so nguyen to khong vuot qua $m^{1/4}$. Goi so nguyen con lai sau khi loai cac thua so nho nay la $z$. Khi do, voi thua so nguyen to $p > m^{1/4}$ cua $z$, chac chan co $\nu_p(\varphi(m)) < 4$, trong do $\nu_p(n)$ la so mu cua $p$ trong phan tich thua so nguyen to cua $n$. Vi chi can xet truong hop

$$
1 \le e = \nu_p(d) < s = \nu_p(\varphi(m)) < 4
$$

nen thua so nguyen to $p$ thoa man dieu kien nay nhieu nhat chi co mot; neu khong, chung deu xuat hien trong $\varphi(m)$ voi so mu it nhat $2$, va tich tong se vuot qua $m$. De tach thua so nguyen to lon duy nhat nay (neu ton tai), chi can tinh

$$
p^\star=\gcd\left(z,\dfrac{\varphi(m)}{z}\right) = \prod_{p : \nu_p(d) < \nu_p(\varphi(m))}p^{\min\{\nu_p(d),\nu_p(\varphi(m))-\nu_p(d)\}}.
$$

Liet ke moi kha nang cua $\nu_p(d),\nu_p(\varphi(m))$ cho thay so mu cua $p$ trong tich chac chan bang $1$, vi vay gia tri tinh duoc chinh la thua so nguyen to lon duy nhat $p^\star$ (neu ton tai). Phan con lai $z/p^\star$ chi co the gom mot so thua so nguyen to thoa man $e=s$, nen khong can tiep tuc phan tich.

Ma tham khao de tim can bac $k$ modulo so nguyen to nhu sau:

??? example "Bài mẫu [Library Checker - Kth Root (Mod)](https://judge.yosupo.jp/problem/kth_root_mod), mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/residue/tonelli-shanks-mod-p.cpp"
    ```

<span id="&#19968;&#33324;&#24773;&#24418;&#30340;&#22788;&#29702;"></span>
### Xử lý trường hợp tổng quát

Xet truong hop tong quat, van gia su modulo $m$ la luy thua so nguyen to $p^e$, nhung $\gcd(a,m)>1$. Neu $a\equiv 0\pmod{m}$, thi

$$
x = p^{\lceil e/k \rceil}\ell\pmod{p^e},~\ell=0,1,\cdots,p^{e-\lceil e/k\rceil}-1
$$

deu la nghiem cua phuong trinh ban dau. Tiep theo xet truong hop $a\not\equiv 0\pmod{m}$. Dat $a = p^sa'$ va $p\perp a'$. Khi do, dat $x=p^zx'$ va $p\perp x'$, ta co

$$
x^k = p^{kz}(x')^k\equiv p^sa'\pmod{p^e}.
$$

Vi $(x')^k\perp p$, cong thuc tren dung khi va chi khi $kz = s$ va $(x')^k\equiv a'\pmod{p^{e-s}}$. Phuong trinh thu nhat co nghiem $z=\dfrac{s}{k}$ khi va chi khi $k\mid s$; con phuong trinh thu hai da duoc giai o tren. Can chu y rang do modulo cua nghiem tong quat trong phuong trinh thu hai khac voi modulo cua nghiem tong quat ban dau, moi nghiem $x'$ cua phuong trinh thu hai tuong ung voi mot so nghiem cua phuong trinh ban dau:

$$
x \equiv p^{s/k}(x' + \ell p^{e-s})\pmod{p^e},~\ell = 0,1,\cdots, p^{s-s/k}-1.
$$

Ma tham khao de tim toan bo can bac $k$ theo modulo bat ky nhu sau:

??? example "Bài mẫu [Luogu P5668 - mẫu N-th residue](https://www.luogu.com.cn/problem/P5668), mã tham khảo"
    === "Thuật toán trực tiếp"
        ```cpp
        --8<-- "docs/math/code/residue/bsgs.cpp"
        ```
    
    === "Thuật toán Tonelli-Shanks cải tiến"
        ```cpp
        --8<-- "docs/math/code/residue/tonelli-shanks.cpp"
        ```

<span id="&#21442;&#32771;&#36164;&#26009;&#19982;&#27880;&#37322;"></span>
## Tài liệu tham khảo và ghi chú

-   Feng Keqin. Elementary Number Theory and Its Applications.
-   [Root of unity modulo n - Wikipedia](https://en.wikipedia.org/wiki/Root_of_unity_modulo_n)
-   [No.981 General Power Root, editorial by 37zigen](https://yukicoder.me/problems/no/981/editorial)

[^fnnt]: Thuc ra, modulo $m$ khong nhat thiet la so nguyen to. Chi can $a$ la can don vi nguyen thuy bac $k=2^e$ modulo $m$, no co the duoc dung cho bien doi so hoc nhanh modulo $m$. Tuy nhien, vi $2^e$ can xu ly thuong kha lon, moi thua so nguyen to cua modulo $m$ phai co dang $c2^e+1$. Do do chi mot thua so nguyen to da rat lon, con modulo $m$ thuong lon hon nua; vi vay truong hop modulo tong quat khong thong dung bang truong hop modulo so nguyen to.

[^lambda-density]: Theo [ket qua ve so luong can nguyen thuy](./primitive-root.md#%E5%8E%9F%E6%A0%B9%E4%B8%AA%E6%95%B0), so luong $\lambda$-can nguyen thuy dung bang $\varphi(\lambda(m))$, trong do $\varphi(\cdot)$ va $\lambda(\cdot)$ lan luot la ham Euler va ham Carmichael. Vi voi hau het so nguyen $m$, ta co $\lambda(m)/m = \exp(-(1+o(1))\log\log m\log\log\log m)$, va ton tai $C > 0$ sao cho voi moi so nguyen $m > 2$ deu co $\varphi(m)/m = C / \log\log m$, nen voi hau het so nguyen $m$, ta co $\varphi(\lambda(m))/m = \exp(-(1+o(1))\log\log m\log\log\log m)$. O day, $o(1)$ trong he so cua phan mu da hap thu dong gop cua thua so $\varphi(\lambda(m))/\lambda(m)$. Vi vay, co the tim $\lambda$-can nguyen thuy sau ky vong $\exp((1+o(1))\log\log m\log\log\log m)$ lan thu. Ve uoc luong cho ham Euler, co the tham khao bai bao Rosser, J. Barkley, and Lowell Schoenfeld. "Approximate formulas for some functions of prime numbers." Illinois Journal of Mathematics 6, no. 1 (1962): 64-94. Ve uoc luong cho ham Carmichael, co the tham khao bai bao Erdos, Paul, Carl Pomerance, and Eric Schmutz. "Carmichael's lambda function." Acta Arith 58, no. 4 (1991): 363-385.

[^amm]: Bai bao goc: Adleman, Leonard, Kenneth Manders, and Gary Miller. "On taking roots in finite fields." In 18th Annual Symposium on Foundations of Computer Science (sfcs 1977), pp. 175-178. IEEE Computer Society, 1977. Mot phan gioi thieu de doc hon co trong Cao, Zhengjun, Qian Sha, and Xiao Fan. "Adleman-Manders-Miller root extraction method revisited." In International Conference on Information Security and Cryptology, pp. 77-85. Berlin, Heidelberg: Springer Berlin Heidelberg, 2011.

[^amm-comp]: Vi thuat toan nay yeu cau $k$ la so nguyen to, trong truong hop xau nhat no can tim can bac $p$ cua $a$ modulo $m$, voi $p$ la thua so nguyen to lon nhat cua $\varphi(m)$. Trong qua trinh nay, can tinh logarit roi rac cua $a$ modulo $m$ theo can don vi nguyen thuy bac $p$. Ngay ca khi dung thuat toan BSGS, qua trinh nay cung can $O(\sqrt{p})$ thoi gian. Tuy nhien, bai bao Fouvry, Etienne. "Theoreme de Brun-Titchmarsh; application au theoreme de Fermat." Inventiones mathematicae 79, no. 2 (1985): 383-407 chi ra rang ton tai mot tap so nguyen to $m$ co mat do duong sao cho thua so nguyen to lon nhat $p$ cua $\varphi(m)=m-1$ thoa man $p=\Omega(m^{2/3})$. Dieu nay co nghia do phuc tap cua thuat toan it nhat la $\Omega(m^{1/3})$, kem hon thuat toan Tonelli-Shanks cai tien duoc gioi thieu trong bai.
