Kien thuc nen: [phan so lien tuc](./continued-fraction.md), [truong bac hai](./quadratic.md)

<span id="&#x5f15;&#x5165;"></span>
## Mo dau

Bai viet nay thao luan cach giai phuong trinh Pell (tong quat). Phuong trinh Pell tong quat la phuong trinh vo dinh theo $x$ va $y$

$$
x^2-Dy^2=N,
$$

trong do $D$ la so nguyen duong khong phai so chinh phuong[^not-square], va $N$ la so nguyen khac khong. Theo nghia hep, phuong trinh Pell chi truong hop dac biet $N=1$ hoac $N=\pm 1$, doi khi cung gom ca $N=\pm 4$. Phuong trinh Pell tong quat lien quan chat che den viec tim so nguyen bac hai co chuan bang $N$ trong vanh so nguyen bac hai thuc, con cac truong hop thuong duoc goi la phuong trinh Pell (nghia hep) co the xem nhu viec tim don vi trong vanh so nguyen bac hai thuc.

Khi bai viet nay noi den phuong trinh Pell, mac dinh la truong hop $N=1$. Tuong ung, truong hop $N=-1$ duoc goi la phuong trinh Pell am[^neg-pell] (negative Pell's equation).

<span id="&#x89e3;&#x7684;&#x7ed3;&#x6784;"></span>
## Cau truc nghiem

Nghiem nguyen $(x,y)$ cua phuong trinh Pell tong quat co lien he mat thiet voi so nguyen bac hai $x+y\sqrt{D}$, vi vay trong tai lieu nghiem cua phuong trinh Pell thuong duoc viet duoi dang $x+y\sqrt{D}$. Vi chuan cua so nguyen bac hai la

$$
N(x+y\sqrt{D}) = x^2-Dy^2,
$$

nen phuong trinh Pell tong quat ve co ban la bai toan tim so nguyen bac hai co chuan bang $N$. Tuy nhien, hai bai toan co khac biet nho. Khi $x$ va $y$ deu la so nguyen, $x+y\sqrt{D}$ nhat dinh la so nguyen bac hai; nguoc lai, so nguyen bac hai khong nhat thiet yeu cau $x$ va $y$ deu la so nguyen: trong truong hop $D\equiv 1\pmod 4$, $x$ va $y$ con co the dong thoi la ban nguyen[^half-int].

Khac biet nay dac biet quan trong khi tim don vi co ban. Don vi trong vanh so nguyen bac hai la so nguyen bac hai co chuan bang $\pm 1$. Voi $D\equiv 2,3\pmod 4$, de tim cac don vi nhu vay chi can giai phuong trinh Pell tong quat trong truong hop $N=\pm 1$; nhung voi $D\equiv 1\pmod 4$, can xet them truong hop $N=\pm 4$. [Phan duoi](#%E8%8C%83%E6%95%B0%E4%B8%BA-4-%E7%9A%84%E6%83%85%E5%BD%A2) se thao luan cach tim don vi.

De hieu cau truc nghiem cua phuong trinh Pell tong quat, can bat dau tu [dong nhat thuc Brahmagupta](https://en.wikipedia.org/wiki/Brahmagupta%27s_identity):

$$
(x_1^2-Dy_1^2)(x_2^2-Dy_2^2)=(x_1x_2+Dy_1y_2)^2-D(x_1y_2+x_2y_1)^2.
$$

No tuong duong voi tinh chat chuan cua so nguyen bac hai bao toan phep nhan, tuc

$$
\begin{aligned}
N\left(x_1+y_1\sqrt{D}\right)N\left(x_2+y_2\sqrt{D}\right) &= N\left((x_1+y_1\sqrt{D})(x_2+y_2\sqrt{D})\right) \\
&= N\left((x_1x_2+Dy_1y_2)+(x_1y_2+x_2y_1)\sqrt{D}\right).
\end{aligned}
$$

Dung dong nhat thuc nay, ta co the ghep nghiem nguyen cua phuong trinh $x^2-Dy^2=N_1$ va nghiem nguyen cua phuong trinh $x^2-Dy^2=N_2$ de thu nghiem nguyen cua phuong trinh $x^2-Dy^2=N_1N_2$. Di nhien, nhin tu goc do so nguyen bac hai, phep ghep nghiem chinh la phep nhan so nguyen bac hai; day la tien ich cua cach ghi nghiem phuong trinh Pell duoi dang so nguyen bac hai. Dac biet, lay $N_1=N$ va $N_2=1$ cho thay: neu da biet mot nghiem cua $x^2-Dy^2=N$ va tat ca nghiem cua phuong trinh Pell tuong ung $x^2-Dy^2=1$, ta co the thu them nhieu nghiem cua $x^2-Dy^2=N$. Tat nhien, phuong phap nay khong nhat thiet sinh ra tat ca nghiem. Nhung it nhat no cho thay viec hieu cau truc nghiem cua phuong trinh Pell co vai tro quan trong doi voi cau truc nghiem cua phuong trinh Pell tong quat.

<span id="pell-&#x65b9;&#x7a0b;"></span>
### Phuong trinh Pell

Y nghia hinh hoc cua phuong trinh $x^2-Dy^2=1$ la mot hyperbol co truc thuc theo truc $x$ va truc ao theo truc $y$. Moi diem tren hyperbol tuong ung duy nhat voi mot gia tri khac khong cua $x+y\sqrt{D}$: nhanh trai cua hyperbol tuong ung voi gia tri am cua $x+y\sqrt{D}$, nhanh phai tuong ung voi gia tri duong. Hon nua, tren moi nhanh, gia tri $x+y\sqrt{D}$ tuong ung voi cac diem tren hyperbol tang nghiem ngat tu duoi len tren. Gia tri cua so nguyen bac hai tao ra mot thu tu tu nhien cho cac nghiem cua phuong trinh Pell.

Hyperbol dong thoi doi xung qua truc $x$ va truc $y$, nen khi thao luan nghiem cua phuong trinh Pell chi can xet doan nam trong goc phan tu thu nhat; cac nghiem con lai thu duoc bang doi xung. Dieu nay tuong duong voi chi xet cac nghiem $x+y\sqrt{D}>1$. Neu ngoai $(\pm 1,0)$ phuong trinh con co nghiem khong tam thuong, thi trong goc phan tu thu nhat nhat dinh ton tai nghiem $(x_1,y_1)$ co gia tri $x+y\sqrt{D}$ nho nhat; day cung la diem nguyen trong goc phan tu thu nhat (khong ke truc toa do) co ca hoanh do va tung do nho nhat. No duoc goi la nghiem co ban (fundamental solution) cua phuong trinh Pell[^fundamental-solution]. Theo thao luan o tren, moi cap so nguyen $(x_k,y_k)$ thoa man $x_k+y_k\sqrt{D}=(x_1+y_1\sqrt{D})^k$ deu la nghiem cua phuong trinh Pell va deu nam trong goc phan tu thu nhat. Nguoc lai, day thuc su la tat ca nghiem cua phuong trinh Pell trong goc phan tu thu nhat. Ket hop voi doi xung, ta co ket luan sau:

???+ note "Dinh li"
    Gia su nghiem co ban cua phuong trinh Pell $x^2-Dy^2=1$ la $(x_1,y_1)$. Khi do toan bo nghiem cua no la
    
    $$
    \{(x,y):x+y\sqrt{D}=\pm(x_1+y_1\sqrt{D})^k,k\in\mathbf Z\}.
    $$

??? note "Chung minh"
    Truoc het chung minh trong goc phan tu thu nhat khong co nghiem nao khac. Gia su nguoc lai ton tai nghiem khac $x+y\sqrt{D}$ va voi mot $k\ge 0$ nao do co
    
    $$
    x_k+y_k\sqrt{D}< x+y\sqrt{D}< x_{k+1}+y_{k+1}\sqrt{D}.
    $$
    
    Ve hinh hoc, dieu nay co nghia diem nguyen $(x,y)$ nam tren hyperbol giua $(x_k,y_k)$ va $(x_{k+1},y_{k+1})$ (khong ke hai dau mut). Nhan dong thoi bat dang thuc voi $x_k-y_k\sqrt{D}=(x_k+y_k\sqrt{D})^{-1}$, ta duoc
    
    $$
    1< (x+y\sqrt{D})(x_k-y_k\sqrt{D})=(xx_k-Dyy_k)+(x_ky-xy_k)\sqrt{D} < x_1+y_1\sqrt{D}.
    $$
    
    Theo tinh don dieu da neu o tren, bat dang thuc nay cho thay $(xx_k-Dyy_k,x_ky-xy_k)$ la diem nguyen nam giua $(1,0)$ va $(x_1,y_1)$. Dieu nay mau thuan voi cach chon $(x_1,y_1)$.
    
    Khi mo rong nghiem tu goc phan tu thu nhat ra toan bo mat phang, doi dau so mu $k$ (tuc lay nghich dao toan bo) chinh la doi xung qua truc $x$, con doi dau toan bo la doi xung qua goc toa do. Them nghiem tam thuong khi $k=0$, ta thu duoc tat ca nghiem cua phuong trinh Pell.

Thao luan tren chi gia su ton tai nghiem co ban. Bay gio can chi ra phuong trinh Pell luon co nghiem khong tam thuong.

???+ note "Dinh li"
    Phuong trinh Pell $x^2-Dy^2=1$ luon co nghiem nguyen khac $(\pm 1,0)$.

??? note "Chung minh"
    Truoc het, [dinh li Dirichlet](./continued-fraction.md#%E7%94%A8%E6%B8%90%E8%BF%91%E5%88%86%E6%95%B0%E9%80%BC%E8%BF%91%E5%AE%9E%E6%95%B0) cho biet ton tai vo han cap so nguyen duong $(x,y)$ sao cho
    
    $$
    \left|\dfrac{x}{y}-\sqrt{D}\right| \le \dfrac{1}{y^2}
    $$
    
    dung. Chung deu thoa man bat dang thuc
    
    $$
    |x^2-Dy^2|=y^2\left|\dfrac{x}{y}-\sqrt{D}\right|\left|\dfrac{x}{y}+\sqrt{D}\right| \le \dfrac{1}{y^2}+2\sqrt{D}<1+2\sqrt{D}.
    $$
    
    Do do, nhat dinh ton tai so nguyen $m\in(-1-2\sqrt{D},1+2\sqrt{D})$ sao cho co vo han cap $(x,y)$ thoa man $x^2-Dy^2 = m$. Phan loai cac cap $(x,y)$ nay theo phan du modulo $m$, ta biet voi mot cap so nguyen $(x_0,y_0)$ nao do, nhat dinh ton tai vo han cap $(x,y)$ sao cho $x\equiv x_0\pmod m$ va $y\equiv y_0\pmod m$. Chon hai cap phan biet bat ki $(x_1,y_1)$ va $(x_2,y_2)$ thoa man cac dieu kien nay, khi do
    
    $$
    \dfrac{x_1+y_1\sqrt{D}}{x_2+y_2\sqrt{D}}=\dfrac{x_1x_2-Dy_1y_2}{m}+\dfrac{x_2y_1-x_1y_2}{m}\sqrt{D}.
    $$
    
    Vi theo quan he dong du co
    
    $$
    \begin{aligned}
    x_1x_2-Dy_1y_2 &\equiv x_0^2-Dy_0^2 = m \equiv 0 \pmod{|m|},\\
    x_2y_1-x_1y_2 &\equiv x_0y_0-x_0y_0 = 0 \pmod{|m|},
    \end{aligned}
    $$
    
    nen ve phai cua cong thuc tren la mot nghiem nguyen. Hon nua, vi $(x_1,y_1)\neq(x_2,y_2)$, nghiem nay khong tam thuong. Dieu nay chung minh phuong trinh Pell thuc su co nghiem khong tam thuong.

Tat nhien, phan nay dua ra chung minh khong xay dung. O phan duoi khi thao luan cach giai phuong trinh Pell, ta se truc tiep dung cac phan so gan dung cua phan so lien tuc de xay dung nghiem, qua do dua ra mot chung minh khac cho su ton tai nghiem khong tam thuong cua phuong trinh Pell. Ngoai ra, mac du cau truc nghiem cua phuong trinh Pell thu duoc o day phu hop voi cau truc don vi cua vanh so nguyen bac hai thuc, nhung voi truong hop $D\equiv 1\pmod 4$, phan nay van chua giai quyet hoan toan cau truc don vi cua vanh so nguyen bac hai tuong ung; phan duoi se thao luan tiep.

<span id="&#x5e7f;&#x4e49;-pell-&#x65b9;&#x7a0b;"></span>
### Phuong trinh Pell tong quat

Do thi cua phuong trinh Pell tong quat $x^2-Dy^2=N$ cung la hyperbol tren mat phang, cung nhan truc $x$ va truc $y$ lam truc doi xung. Nhu da chi ra, mot so nghiem cua phuong trinh $x^2-Dy^2=N$ co the chi khac nhau boi mot thua so la nghiem cua phuong trinh Pell, dieu nay co nghia ta co the chia nghiem cua phuong trinh $x^2-Dy^2=N$ thanh cac lop tuong duong. Voi hai nghiem $(x_1,y_1)$ va $(x_2,y_2)$ cua phuong trinh $x^2-Dy^2=N$, neu ton tai nghiem $(u,v)$ cua phuong trinh Pell sao cho $x_2+y_2\sqrt{D}=(x_1+y_1\sqrt{D})(u+v\sqrt{D})$, thi noi nghiem $(x_1,y_1)$ va $(x_2,y_2)$ tuong duong. Dieu kien can va du de hai nghiem tuong duong la

$$
N\mid (x_1x_2-Dy_1y_2),\ N\mid (x_2y_1-x_1y_2).
$$

Vi nghiem cua phuong trinh Pell tuong doi de tim, mot y tuong tu nhien la tim mot nghiem trong moi lop tuong duong noi tren. Mot khi biet cac nghiem nay, ta co the dung nghiem cua phuong trinh Pell tuong ung de thu tat ca nghiem cua phuong trinh Pell tong quat can tim. Trong cac lop tuong duong cua nghiem phuong trinh Pell tong quat, do tinh doi xung, moi lop deu ton tai nghiem co tung do $y$ khong am nhung nho nhat co the. Neu nghiem nhu vay duy nhat, no duoc goi la nghiem co ban cua lop tuong duong; neu khong, lop tuong duong do nhat dinh co hai nghiem co $y$ khong am va nho nhat, va chung doi xung qua truc $y$, khi do chon nghiem co $x>0$ lam nghiem co ban. Vi vay, giai phuong trinh Pell tong quat $x^2-Dy^2=N$ tuong duong voi tim tap nghiem co ban $U$ cua no. Gia su nghiem co ban cua phuong trinh Pell tuong ung la $(r,s)$, thi tap tat ca nghiem cua phuong trinh Pell tong quat la

$$
\{(x,y):x+y\sqrt{D}=\pm(r+s\sqrt{D})^k(u+v\sqrt{D}),k\in\mathbf Z,u+v\sqrt{D}\in U\}.
$$

So nghiem co ban cua phuong trinh Pell tong quat nhat dinh huu han. Vi tu bieu thuc nghiem tong quat o tren, gia tri tuyet doi $|u+v\sqrt{D}|$ nhat dinh nam giua $r-s\sqrt{D}$ va $r+s\sqrt{D}$. Tai lieu tham khao o cuoi bai cung cap cac uoc luong chat hon ve mien toa do cua nghiem co ban. Di nhien, khac voi truong hop phuong trinh Pell, phuong trinh Pell tong quat co the vo nghiem.

Ngoai viec dung phep ghep nghiem, de thu tat ca nghiem trong cung mot lop tuong duong tu mot nghiem $(u,v)$ cua phuong trinh Pell tong quat va nghiem co ban $(r,s)$ cua phuong trinh Pell, ta cung co the dung he thuc truy hoi

$$
x_{k} = 2rx_{k-1} - x_{k-2},\ y_{k} = 2ry_{k-1} - y_{k-2},
$$

trong do $x_k+y_k\sqrt{D}=(r+s\sqrt{D})^k(u+v\sqrt{D})$. Ly do la $x_n$ va $y_n$ deu co the viet duoi dang $A(r+s\sqrt{D})^k+B(r-s\sqrt{D})^k$ voi mot cap so thuc $(A,B)$ nao do; theo dinh li Vieta, $r\pm s\sqrt{D}$ la hai nghiem thuc cua phuong trinh $x^2-2rx+1=0$, nen $x_n$ va $y_n$ deu thoa man truy hoi tuyen tinh he so hang bac hai tren. So voi phep ghep nghiem, cong thuc truy hoi nay can it phep nhan hon.

<span id="&#x6c42;&#x89e3;&#x65b9;&#x6cd5;"></span>
## Phuong phap giai

Viec giai phuong trinh Pell va phuong trinh Pell tong quat deu co the dua tren phan so lien tuc.

<span id="pqa-&#x7b97;&#x6cd5;"></span>
### Thuat toan PQa

Nhung thuat toan duoc thao luan trong bai nay deu dua tren thuat toan PQa, dung de tim khai trien phan so lien tuc cua mot so vo ti bac hai cu the.

Gia su cac so nguyen $P_0,Q_0,D$ thoa man $Q_0\neq 0$, $D>0$ khong phai so chinh phuong, va $P_0^2\equiv D\pmod{Q_0}$. Khi do so vo ti bac hai

$$
\omega=\dfrac{P_0+\sqrt{D}}{Q_0}
$$

co khai trien phan so lien tuc $[a_0,a_1,\cdots]$ tinh duoc bang [cong thuc truy hoi](./continued-fraction.md#%E4%BA%8C%E6%AC%A1%E6%97%A0%E7%90%86%E6%95%B0) sau:

$$
a_k = \left\lfloor\dfrac{P_k+\sqrt{D}}{Q_k}\right\rfloor,\ P_{k+1} = a_kQ_k - P_k,\ Q_{k+1} = \dfrac{D-P_{k+1}^2}{Q_k}.
$$

Tiep theo, tu so va mau so $A_k$ va $B_k$ cua phan so gan dung thu $k$ cua $\omega$ duoc cho boi [cong thuc truy hoi](./continued-fraction.md#%E9%80%92%E6%8E%A8%E5%85%B3%E7%B3%BB)

$$
A_k = a_kA_{k-1} + A_{k-2},\ B_k = a_kB_{k-1} + B_{k-2}
$$

voi $A_{-1} = 1$, $A_{-2}=0$, $B_{-1}=0$, $B_{-2}=1$.

Tinh dung dan cua cac cong thuc nay da duoc chung minh trong bai phan so lien tuc. O do cung da giai thich rang vi so vo ti bac hai la [phan so lien tuc tuan hoan](./continued-fraction.md#%E4%BA%8C%E6%AC%A1%E6%97%A0%E7%90%86%E6%95%B0), nen bo ba $(P_k,Q_k,a_k)$ cuoi cung se di vao chu ki, va thuat toan luon ket thuc sau huu han buoc. Gia su do dai nho nhat cua chu ki la $\ell$, va vi tri bat dau som nhat cua chu ki la $k_0$, khi do khai trien phan so lien tuc cua so vo ti bac hai co the viet la

$$
\omega=[a_0,\cdots,a_{k_0-1},\overline{a_{k_0},\cdots,a_{k_0+\ell-1}}].
$$

De dung thuat toan PQa giai phuong trinh Pell, can thiet lap ket qua sau:

???+ note "Dinh li"
    Tiep tuc dung ki hieu tren. Dat $G_k=Q_0A_k-P_0B_k$. Khi do cap so nguyen $(G_{k-1},B_{k-1})$ thoa man
    
    $$
    G_{k-1}^2-DB_{k-1}^2=(-1)^{k}Q_0Q_{k},
    $$
    
    va uoc chung lon nhat cua chung $\gcd(G_{k-1},B_{k-1})$ chia het $Q_{k}$.

??? note "Chung minh"
    Gia su trong khai trien phan so lien tuc cua $\omega$, thuong hoan toan thu $k$ la $\omega_{k}$, tuc
    
    $$
    \omega = [a_0,a_1,\cdots,a_{k-1},\omega_k] = \dfrac{\omega_k A_{k-1}+A_{k-2}}{\omega_k B_{k-1}+B_{k-2}}.
    $$
    
    Thay $\omega=(P_0+\sqrt{D})/Q_0$ va $\omega_k=(P_k+\sqrt{D})/Q_k$ vao cong thuc tren, ta duoc
    
    $$
    \dfrac{P_0+\sqrt{D}}{Q_0} = \dfrac{(P_k+\sqrt{D})A_{k-1}+Q_kA_{k-2}}{(P_k+\sqrt{D})B_{k-1}+Q_kB_{k-2}}.
    $$
    
    Khu mau hai ve va so sanh he so cua phan huu ti va phan vo ti, roi thay bieu thuc cua $G_k$, thu duoc cac dang thuc
    
    $$
    \begin{aligned}
    G_{k-1} &= P_kB_{k-1} + Q_kB_{k-2},\\
    DB_{k-1} &= P_kG_{k-1} + Q_kG_{k-2}.
    \end{aligned}
    $$
    
    Do do, nhan dang thuc thu nhat voi $G_{k-1}$ roi tru dang thuc thu hai nhan voi $B_{k-1}$, ta co
    
    $$
    \begin{aligned}
    G_{k-1}^2-DB_{k-1}^2 &= (B_{k-2}G_{k-1}-B_{k-1}G_{k-2})Q_k \\
    &= (A_{k-1}B_{k-2}-B_{k-1}A_{k-2})Q_0Q_k \\
    &= (-1)^kQ_0Q_k.
    \end{aligned}
    $$
    
    Buoc cuoi dung [cong thuc sai phan](./continued-fraction.md#%E8%AF%AF%E5%B7%AE%E4%BC%B0%E8%AE%A1) cua phan so gan dung. Ket qua dau tien da duoc chung minh.
    
    De chung minh ket qua thu hai, thay bieu thuc cua $G_k$ vao ket qua dau tien:
    
    $$
    (Q_0A_{k-1}-P_0B_{k-1})^2 - DB_{k-1}^2 = (-1)^kQ_0Q_k.
    $$
    
    Do $Q_0\mid(P_0^2-D)$, suy ra
    
    $$
    Q_0A_{k-1}^2 +\left(\dfrac{P_0^2-D}{Q_0}B_{k-1}- 2P_0A_{k-1}\right)B_{k-1} = (-1)^kQ_k.
    $$
    
    Vi vay, $\gcd(G_{k-1},B_{k-1}) = \gcd(Q_0A_{k-1},B_{k-1})$ chia het $Q_k$.

Ket qua nay cung cap mot cach tim nghiem cua phuong trinh $x^2-Dy^2=N$. Neu chon hop li $Q_0>0$ va chon $P_0$ la mot nghiem cua dong du $P_0^2\equiv D\pmod{Q_0}$, roi chay thuat toan PQa tren $(P_0+\sqrt{D})/Q_0$ cho den khi tim duoc $(-1)^kQ_0Q_{k}=N$, thi $(G_{k-1},B_{k-1})$ tro thanh mot nghiem cua phuong trinh ban dau. Hon nua, neu $Q_k=\pm 1$, nghiem thu duoc theo cach nay nhat dinh la nghiem nguyen thuy, tuc $G_{k-1}$ va $B_{k-1}$ nhat dinh nguyen to cung nhau.

Y tuong nay la cot loi de giai phuong trinh Pell va phuong trinh Pell tong quat. Sau khi hieu y tuong nay, ta xu li mot so chi tiet cua thuat toan va chung minh moi nghiem deu co the thu duoc theo cach nay.

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
### Phuong trinh Pell am

Theo thao luan o phan truoc, nghiem cua phuong trinh Pell am cung nhat dinh tuong ung voi phan so gan dung cua $\sqrt{D}$, va chi co the xuat hien tai vi tri $(-1)^kQ_k=-1$. Dieu nay chi co the xuat hien o cuoi chu ki. Vi vay, phuong trinh Pell am co nghiem khi va chi khi do dai chu ki $\ell$ la le. Khi nghiem ton tai, $(A_{\ell-1},B_{\ell-1})$ la nghiem co ban cua phuong trinh Pell am. Cach giai cua no giong phan truoc.

Dung y tuong tuong tu chung minh cau truc nghiem cua phuong trinh Pell o tren, co the chung minh ket qua sau:

???+ note "Dinh li"
    Gia su phuong trinh $x^2-Dy^2=-1$ co nghiem va nghiem co ban la $(x_1,y_1)$. Khi do moi nghiem nguyen cua $x^2-Dy^2=\pm 1$ deu thuoc tap
    
    $$
    \{(x,y):x+y\sqrt{D}=\pm(x_1+y_1\sqrt{D})^k,k\in\mathbf Z\}.
    $$
    
    Dac biet, nghiem nguyen $(x_2,y_2)$ thoa man $x_2+y_2\sqrt{D}=(x_1+y_1\sqrt{D})^2$ chinh la nghiem co ban cua $x^2-Dy^2=1$.

??? note "Chung minh"
    Do tinh doi xung, chi can xet nghiem nguyen duong, tuc truong hop $x+y\sqrt{D}>1$. Nhung vi $x^2-Dy^2=\pm 1$ la hai cap hyperbol, nen khong the lap tuong ung mot-mot giua $x+y\sqrt{D}$ va $(x,y)$. De xu li kho khan nay, truoc het chung minh $(x_2,y_2)$ noi tren la nghiem co ban cua $x^2-Dy^2=1$.
    
    Hien nhien, $(x_2,y_2)$ la nghiem cua $x^2-Dy^2=1$. Neu dat $(z,w)$ la nghiem co ban cua $x^2-Dy^2=1$, thi nhat dinh $1<z+w\sqrt{D}\le x_2+y_2\sqrt{D}$. Neu bat dang thuc ben phai la nghiem ngat, chia bat dang thuc cho $x_1+y_1\sqrt{D}$ se duoc $-x_1+y_1\sqrt{D}<(z+w\sqrt{D})(-x_1+y_1\sqrt{D})<x_1+y_1\sqrt{D}$. Khai trien hang giua ta thu duoc dang $x'+y'\sqrt{D}$, co chuan $-1$ va $(x',y')$ cung la nghiem nguyen. Lay nghich dao bat dang thuc nay, ta thay $-x'+y'\sqrt{D}$ cung nam giua $-x_1+y_1\sqrt{D}$ va $x_1+y_1\sqrt{D}$. Hai so nguyen bac hai $\pm x'+y'\sqrt{D}$ la nghich dao cua nhau, nen nhat dinh co mot so lon hon $1$. Nhung giua $1$ va $x_1+y_1\sqrt{D}$ khong nen xuat hien so nguyen bac hai nao khac co chuan $-1$, mau thuan voi tinh nho nhat cua $x_1+y_1\sqrt{D}$. Vi vay phai co $x_2+y_2\sqrt{D}=z+w\sqrt{D}$, tuc $(x_2,y_2)$ la nghiem co ban cua phuong trinh $x^2-Dy^2=1$.
    
    Dua tren dieu nay, neu ton tai nghiem $(x,y)$ cua phuong trinh $x^2-Dy^2=\pm 1$ khong tuong ung voi mot luy thua $(x_1+y_1\sqrt{D})^k$, thi nhat dinh ton tai $k$ sao cho $(x_1+y_1\sqrt{D})^{2k}<x+y\sqrt{D}<(x_1+y_1\sqrt{D})^{2k+2}$. Khu thua so $(x_1+y_1)^{2k+1}$, ta suy ra ton tai so nguyen bac hai $x'+y'\sqrt{D}\neq 1$ co chuan $\pm 1$ nam giua $-x_1+y_1\sqrt{D}$ va $x_1+y_1\sqrt{D}$. Lap lai lap luan bang nghich dao cua doan truoc cho thay dieu nay mau thuan voi tinh nho nhat cua $x_1+y_1\sqrt{D}$. Menh de duoc chung minh.

Vi $(A_{\ell-1},B_{\ell-1})$ la nghiem nguyen duong nho nhat cua phuong trinh Pell am, va tat ca nghiem nguyen duong cua $x^2-Dy^2=\pm 1$ deu nam trong tap

$$
\{(x,y):x+y\sqrt{D}=(A_{\ell-1}+B_{\ell-1}\sqrt{D})^k,k\in\mathbf N_+\}
$$

hon nua cac nghiem nguyen duong nay nhat dinh tuong ung voi phan so gan dung cua $\sqrt{D}$ o vi tri cuoi chu ki (truoc mot vi tri), va tu so cung mau so cua phan so gan dung tang nghiem ngat, nen voi moi $k\in\mathbf N_+$ luon co

$$
(A_{\ell-1}+B_{\ell-1}\sqrt{D})^k = A_{k\ell-1}+B_{k\ell-1}\sqrt{D}.
$$

Trong tat ca cac nghiem nguyen duong nay, khi $k$ le thi la nghiem cua phuong trinh Pell am, khi $k$ chan thi la nghiem cua phuong trinh Pell; hai loai xuat hien xen ke.

De phan dinh phuong trinh Pell am co nghiem hay khong can tinh do dai chu ki cua khai trien phan so lien tuc cua $\sqrt{D}$; dieu nay khong de tinh, nen ta muon co tieu chuan don gian hon. Tuy nhien, hien chua co dieu kien nao vua ngan gon vua de tinh[^solubility-neg-pell]. O day chi dua ra mot ket qua don gian.

???+ note "Dinh li"
    Neu phuong trinh $x^2-Dy^2=-1$ co nghiem, thi $4$ khong chia het $D$ va $D$ khong chua thua so nguyen to dang $4k+3$. Nguoc lai, neu $D=2$ hoac $D$ la so nguyen to dang $4k+1$, thi phuong trinh nhat dinh co nghiem.

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
### Truong hop tong quat

Cuoi cung, thao luan cach giai phuong trinh Pell tong quat.

Voi truong hop $|N|<\sqrt{D}$ co mot cach giai don gian. Ket qua o tren cho biet nghiem $(x,y)$ cua phuong trinh $x^2-Dy^2=N$ nhat dinh thoa $\dfrac{x}{y}$ bang mot phan so gan dung nao do cua $\sqrt{D}$. Hon nua, theo cau truc nghiem da thao luan, moi nghiem co ban $(x,y)$ deu thoa $x+y\sqrt{D}$ khong vuot qua nghiem co ban $x_1+y_1\sqrt{D}$ cua phuong trinh Pell tuong ung $x^2-Dy^2=1$. Dung tinh don dieu cua day mau so $B_k$ trong thuat toan PQa, cac nghiem co ban nay cua phuong trinh Pell tong quat nhat dinh xuat hien truoc khi nghiem co ban cua phuong trinh Pell tuong ung xuat hien. Vi vay, chi can chay thuat toan PQa voi $(P_0,Q_0,D)=(0,1,D)$ cho den khi $Q_{\ell'}=1$ va $\ell'$ chan, trong qua trinh do kiem tra moi $(A_k,B_k)$ xuat hien xem co ton tai so nguyen $f$ sao cho

$$
A_k^2-DB_k^2 = (-1)^{k+1}Q_{k+1} = N/f^2
$$

hay khong. Neu co, ghi nhan $(fA_{k},fB_{k})$ la mot nghiem nguyen duong nho nhat. Tat ca cac $(fA_k,fB_k)$ duoc ghi nhan trong qua trinh nay chinh la toan bo nghiem nguyen duong nho nhat cua phuong trinh $x^2-Dy^2=N$. Dung $(A_{\ell'-1},B_{\ell'-1})$, tuc nghiem co ban cua phuong trinh Pell tuong ung, co the sinh tat ca nghiem cua phuong trinh Pell tong quat tu cac nghiem nguyen duong nho nhat vua tim duoc. Chu y tuy theo do dai chu ki $\ell$ chan hay le, $\ell'$ noi tren co the la $\ell$ hoac $2\ell$.

Voi truong hop $N$ tong quat hon, phuong phap tren khong con ap dung. Truoc het, liet ke moi nhan tu chinh phuong $f^2$ cua $N$, dat $m=N/f^2$, va liet ke moi nghiem $z$ cua dong du $z^2\equiv D\pmod{|m|}$ thoa $-|m|/2<z \le |m|/2$. Sau do chay thuat toan PQa voi $(P_0,Q_0,D)=(z,|m|,D)$ cho den khi $Q_k=\pm 1$ hoac da ket thuc mot chu ki. Trong truong hop thu hai, phuong trinh lien quan den cap $(f,z)$ nay khong co nghiem. Trong truong hop thu nhat, can kiem tra them $(-1)^kQ_k=N/|N|$ hay khong. Neu dau phu hop, $(fG_{k-1},fB_{k-1})$ la mot nghiem cua phuong trinh $x^2-Dy^2=N$. Neu khong, no la nghiem cua phuong trinh $x^2-Dy^2=-N$, va chi khi phuong trinh Pell am tuong ung co nghiem, moi co the ghep no voi nghiem co ban cua phuong trinh Pell am tuong ung de thu nghiem cua $x^2-Dy^2=N$. Sau khi duyet het moi cap $(f,z)$, ta thu duoc dung mot nghiem trong moi lop tuong duong cua nghiem phuong trinh $x^2-Dy^2=N$, va nghiem nay la nghiem co ban hoac nghiem nguyen duong nho nhat cua lop do. Dung chung va nghiem co ban cua phuong trinh Pell tuong ung, co the sinh tat ca nghiem nguyen cua phuong trinh. Thuat toan nay duoc goi la **thuat toan Lagrange–Matthews–Mollin**.

Tinh dung dan cua thuat toan duoc dam bao boi dinh li sau:

???+ note "Dinh li"
    Gia su phuong trinh $x^2-Dy^2=N$ co nghiem nguyen $(x,y)$ voi $x\ge 0, y>0,\gcd(x,y)=1$. Dat $Q_0=|N|$, khi do $\gcd(Q_0,y)=1$. Gia su $P_0$ la nghiem cua dong du $x\equiv -P_0y\pmod{Q_0}$ va $-Q_0/2<P_0\le Q_0/2$, dong thoi dat so nguyen $X$ sao cho $x=Q_0X-P_0y$. Khi do $P_0^2\equiv D\pmod{Q_0}$, $\dfrac{X}{y}$ la mot phan so gan dung $\dfrac{A_{k-1}}{B_{k-1}}$ cua $\omega=\dfrac{P_0+\sqrt{D}}{Q_0}$, va $Q_k=(-1)^k\dfrac{N}{|N|}$.

??? note "Chung minh"
    Dung $x\equiv -P_0y\pmod{Q_0}$ va $x^2-Dy^2=N\equiv 0\pmod{Q_0}$, hien nhien co $P_0^2\equiv D\pmod{Q_0}$. Do do
    
    $$
    P_0x+Dy\equiv -P_0^2y+Dy = (D-P_0^2)y\equiv 0\pmod{Q_0}.
    $$
    
    Tu day co the xet ma tran he so nguyen
    
    $$
    \begin{pmatrix}P & R \\ Q & S\end{pmatrix}
    =
    \begin{pmatrix}X & \dfrac{P_0x+Dy}{Q_0} \\ y & x\end{pmatrix}.
    $$
    
    Dinh thuc cua no la
    
    $$
    PS-QR = \dfrac{x(x+P_0y)-y(P_0x+Dy)}{Q_0} = \dfrac{x^2-Dy^2}{Q_0} = \pm 1.
    $$
    
    Hon nua, dat $\zeta =\sqrt{D} > 1$, ta co
    
    $$
    \dfrac{P\zeta+R}{Q\zeta+S} = \dfrac{(x+P_0y)\sqrt{D}+(P_0x+Dy)}{(x+y\sqrt{D})Q_0} = \dfrac{P_0+\sqrt{D}}{Q_0} = \omega.
    $$
    
    Tiep theo chung minh $\dfrac{P}{Q}$ la mot phan so gan dung cua $\omega$. Gia su $\dfrac{P}{Q}$ co [khai trien phan so lien tuc](./continued-fraction.md#%E7%AE%80%E5%8D%95%E8%BF%9E%E5%88%86%E6%95%B0)
    
    $$
    \dfrac{P}{Q} = [a_0,a_1,\cdots,a_k]
    $$
    
    va $PS-QR = (-1)^{k-1}$. Neu $\dfrac{p_k}{q_k}$ la phan so gan dung thu $k$ cua no, thi $(p_k,q_k)=(P,Q)$, va theo [cong thuc sai phan cua phan so gan dung](./continued-fraction.md#%E8%AF%AF%E5%B7%AE%E4%BC%B0%E8%AE%A1), $p_kq_{k-1}-q_kp_{k-1}=(-1)^{k-1}$. Dieu nay cho thay
    
    $$
    p_k(S-q_{k-1}) = q_k(R-p_{k-1}).
    $$
    
    Xet tung truong hop:
    
    -   Neu $S=0$, de thay $Q=R=1$, nen $\omega=P+\zeta^{-1}=[P,\zeta]$, do do $\dfrac{P}{Q}=P$ la phan so gan dung thu $0$ cua $\omega$;
    -   Neu $Q=S>0$, thi $Q=S=1$ va $P-R=\pm 1$. Khi do:
        -   Neu $P=R+1$, thi $\omega=R+\dfrac{1}{1+\zeta^{-1}}=[R,1,\zeta]$, do do $\dfrac{P}{Q}=\dfrac{R+1}{1}=[R,1]$ la phan so gan dung thu $1$ cua $\omega$;
        -   Neu $P=R-1$, thi $\omega=R-1+\dfrac{1}{1+\zeta}=[R-1,\zeta-1]$, do do $\dfrac{P}{Q}=R-1$ la phan so gan dung thu $0$ cua $\omega$;
    -   Neu $Q\neq S>0$, thi vi $Q=q_k\mid(S-q_{k-1})$, luon ton tai so nguyen $\kappa$ sao cho $S=\kappa q_k+q_{k-1}$ va $R=\kappa p_k+p_{k-1}$. Vi $q_k\ge q_{k-1}$ va $S>0$, nen $\kappa\ge 0$. Do do, $\omega=\dfrac{(\kappa+\zeta)p_k+p_{k-1}}{(\kappa+\zeta)q_k+q_{k-1}}=[a_0,a_1,\cdots,a_k,\kappa+\zeta]$, nen $\dfrac{P}{Q}$ la phan so gan dung thu $k$ cua no.
    
    Tom lai, $\dfrac{X}{y}$ luon la phan so gan dung cua $\omega=\dfrac{P_0+\sqrt{D}}{Q_0}$, va theo ki hieu trong thuat toan PQa duoc viet la $\dfrac{A_{k-1}}{B_{k-1}}$. Vi $A_{k-1}^2-DB_{k-1}^2=(-1)^kQ_0Q_k$, suy ra $Q_k=(-1)^k\dfrac{N}{|N|}$.

Dinh li nay dam bao moi nghiem duong cua phuong trinh deu nam trong cac phan so gan dung cua so vo ti bac hai tuong ung. Vi khi tinh phan so gan dung bang thuat toan PQa, mot khi di vao chu ki thi co the dam bao cac phan so gan dung luon duong. Do do, chi can liet ke moi so vo ti bac hai duoc dieu kien cua dinh li cho phep, tinh cac phan so gan dung cua no den het mot chu ki, ta co the tim duoc mot nghiem. Vi hai nghiem xuat hien trong cac phan so gan dung cua cung mot so vo ti bac hai nhat dinh tuong duong, nen khi thu duoc nghiem dau tien thoa $(-1)^kQ_k=N/|N|$, co the dung viec tinh tiep. Khac voi tat ca thuat toan truoc, o day chi so $k$ thoa dieu kien co the xuat hien truoc khi vao chu ki.

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
    
        Do dai chu ki $\ell=17$ la le, nen can xet trong hai chu ki cac truong hop ma $G_{k-1}^2-157B_{k-1}^2$ khac $12$ boi mot nhan tu chinh phuong, tuc cac truong hop $k=1,9,13,19,23,31$. Cac nghiem tuong ung la $(fG,fB)$ trong bang sau:
    
        |  $k$ | $f$ |    $fG_{k-1}$    |    $fB_{k-1}$   |    $x$    |   $y$   |
        | :--: | :-: | :--------------: | :-------------: | :-------: | :-----: |
        |  $1$ | $1$ |       $13$       |       $1$       |    $13$   |   $1$   |
        |  $9$ | $1$ |      $10663$     |      $851$      |  $10663$  |  $851$  |
        | $13$ | $2$ |     $579160$     |     $46222$     |  $579160$ | $46222$ |
        | $19$ | $2$ |    $483790960$   |    $38610722$   | $-579160$ | $46222$ |
        | $23$ | $1$ |   $26277068347$  |   $2097138361$  |  $-10663$ |  $851$  |
        | $31$ | $1$ | $21950079635497$ | $1751807067011$ |   $-13$   |   $1$   |
    
        Tat ca $(fG,fB)$ chinh la cac nghiem nguyen duong nho nhat trong moi lop tuong duong cua tap nghiem phuong trinh $x^2-157y^2=12$. De thu tat ca nghiem tu chung, co the dung nghiem co ban $(46698728731849,3726964292220)$ cua phuong trinh Pell tuong ung. Chang han, co the chuyen chung thanh nghiem co ban $(x,y)$ cua lop tuong duong do; cac nghiem tuong ung cung duoc liet ke trong bang tren.
    2.  Giai phuong trinh $x^2-157y^2=12$.
    
        Lan nay dung thuat toan Lagrange–Matthews–Mollin. Truoc het, liet ke cac nhan tu chinh phuong cua $N=12$:
    
        -   Khi $f^2=1^2$, co $m=12$, dong du $P^2\equiv 157\pmod{12}$ co nghiem $z=\pm 1,\pm 5$;
        -   Khi $f^2=2^2$, co $m=3$, dong du $P^2\equiv 157\pmod{3}$ co nghiem $z=\pm 1$.
    
        Voi moi to hop $(f,z)$ co the, chay thuat toan PQa voi tham so dau $(P_0,Q_0,D)=(z,|m|,D)$ va tim vi tri dau tien co $(-1)^kQ_k=1$; $(fG_{k-1},fB_{k-1})$ tuong ung la mot nghiem. Ket qua nhu bang sau:
    
        | $f$ |  $z$ |  $m$ |  $k$ |    $fG_{k-1}$    |    $fB_{k-1}$   |
        | :-: | :--: | :--: | :--: | :--------------: | :-------------: |
        | $1$ |  $1$ | $12$ | $32$ | $21950079635497$ | $1751807067011$ |
        | $1$ | $-1$ | $12$ |  $2$ |       $13$       |       $1$       |
        | $1$ |  $5$ | $12$ | $24$ |   $26277068347$  |   $2097138361$  |
        | $1$ | $-5$ | $12$ | $10$ |      $10663$     |      $851$      |
        | $2$ |  $1$ |  $3$ | $20$ |    $483790960$   |    $38610722$   |
        | $2$ | $-1$ |  $3$ | $14$ |     $579160$     |     $46222$     |
    
        Day chinh la cac nghiem nguyen duong nho nhat trong moi lop tuong duong da liet ke o tren; co the dung nghiem co ban cua phuong trinh Pell de chuyen chung thanh nghiem co ban.
    3.  Giai phuong trinh $x^2-79y^2=\pm 101$.
    
        Van dung thuat toan Lagrange–Matthews–Mollin. Vi $N=101$ la so nguyen to, nhat dinh $f=1$. Khi do $m=101$, va dong du tuong ung $P^2\equiv 79\pmod{101}$ co nghiem $P=\pm 33$.
    
        Chay thuat toan PQa voi $(P_0,Q_0,D)=(33,101,79)$ cho ket qua sau: (phan mau do la chu ki dau tien)
    
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
    
        Do dai chu ki $\ell=6$ la chan. Den het mot chu ki van khong ton tai $Q_k=\pm 1$, nen truong hop nay vo nghiem. Tuong tu, chay thuat toan PQa voi $(P_0,Q_0,D)=(-33,101,79)$ cung quan sat duoc tinh huong giong vay. Vi the phuong trinh vo nghiem.

<span id="&#x4e60;&#x9898;"></span>
## Bai tap

-   [LOJ 6687. Project Euler 66 - Giai phuong trinh](https://loj.ac/p/6687)
-   [SPOJ EQU2 - Yet Another Equation](https://www.spoj.com/problems/EQU2/)
-   [SPOJ PELL2 - Pell (Mid pelling)](https://www.spoj.com/problems/PELL2/)
-   [UVa 12909. Numeric Center](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=862&page=show_problem&problem=4774)
-   [UVa 10241. Semi-triangular and also Square](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1182)

<span id="&#x53c2;&#x8003;&#x6587;&#x732e;&#x4e0e;&#x6ce8;&#x91ca;"></span>
## Tai lieu tham khao va chu thich

-   [Pell's equation - Wikipedia](https://en.wikipedia.org/wiki/Pell%27s_equation)
-   [John P. Robertson - Solving the generalized Pell equation $x^2-Dy^2=N$](https://citeseerx.ist.psu.edu/document?repid=rep1&type=pdf&doi=5ac34a344ee346855184ff949eeaed18685b155c)
-   [Keith Matthews - The Diophantine Equation $x^2-Dy^2=N$,$D>0$](http://www.numbertheory.org/PDFS/patz5.pdf)
-   [Existence of Solution to Pell's Equation - Suryateja Gavva's Blog](https://surya-teja.com/2011/01/11/existence-of-solution-to-pells-equation/)
-   [Calculating the simple continued fraction of a quadratic irrational - Number Theory Web](http://www.numbertheory.org/php/surd.html) (thuat toan PQa)
-   [Solving the diophantine equation x2-Dy2 = N, D > 0 and not a perfect square, N != 0 - Number Theory Web](http://www.numbertheory.org/php/patz.html) (thuat toan Lagrange–Matthews–Mollin)

[^not-square]: Khi $D$ la so chinh phuong, chi can phan tich nhan tu la biet $(x+y\sqrt{D})(x-y\sqrt{D})=N$, vi vay moi nghiem co the tim bang cach duyet cac uoc cua $N$. Dac biet, khi $N=1$, phuong trinh chi co nghiem $(\pm 1,0)$; khi $N=-1$ va $D\neq 1$, phuong trinh vo nghiem.

[^neg-pell]: Mot so tai lieu tieng Trung cung goi no la phuong trinh Pell loai hai.

[^half-int]: Tuc so huu ti co dang $n+\dfrac12$ voi $n\in\mathbf Z$.

[^fundamental-solution]: Chu y dinh nghia nghiem co ban trong phuong trinh Pell khong trung voi dinh nghia don vi co ban trong vanh so nguyen bac hai thuc. Truoc het, trong mot so vanh so nguyen bac hai thuc, don vi co ban $x+y\sqrt{D}$ co $x,y$ la ban nguyen, nen khong phai nghiem cua phuong trinh Pell. Tiep theo, cung mot vanh so nguyen bac hai thuc co bon don vi co ban, nhung nghiem co ban chi co mot, vi nghiem co ban yeu cau $x,y$ deu duong.

[^solubility-neg-pell]: Mot phuong phap va cong cu phan dinh kha thuc dung nam o [day](http://www.numbertheory.org/php/hardy_williams.html) va trong tai lieu tham khao cua no. Danh sach cac so nguyen duong $D$ sao cho phuong trinh $x^2-Dy^2=-1$ co nghiem la [OEIS A031396](https://oeis.org/A031396).
