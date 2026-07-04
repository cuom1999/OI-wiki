author: 383494, buuzzing, c-forrest, cr4c1an, Emp7iness, Enter-tainer, Great-designer, HeRaNO, jifbt, Kaiser-Yang, Koishilll, ksyx, Marcythm, Qiu-Quanzhi, Saisyc, sshwy, StarryReverie, StudyingFather, Tiphereth-A, Xeonacid, xyf007

Trong lap trinh thi dau, mot phan quan trong cua so hoc la **so hoc modulo** (modular arithmetic), tuc la thuc hien cac phep toan tren so nguyen duoi mot modulo nao do. Ngoai bon phep toan co ban va phep luy thua, ta con co the thuan tien tinh logarit roi rac, khai can bac bat ky, tinh giai thua, to hop va nhieu phep toan khac.

So hoc modulo xuat hien trong nhieu loai bai toan, khong chi trong phan so hoc. Dap an that su cua nhieu bai toan co the rat lon, vuot qua mien luu tru cua cac kieu so nguyen thong dung. Khi do, de tranh dung so nguyen lon va in ra chuoi chu so dai, de bai thuong yeu cau in dap an sau khi lay modulo. Vi vay can nam vung cac ky thuat so hoc modulo.

<span id="c/c++-&#x7684;&#x6574;&#x6570;&#x9664;&#x6CD5;&#x548C;&#x53D6;&#x6A21;&#x8FD0;&#x7B97;"></span>
## Phep chia nguyen va phep modulo trong C/C++

Trong C/C++, phep chia nguyen va phep modulo khong trung voi phep modulo va phep chia quen dung trong toan hoc.

Trong moi phien ban tieu chuan C/C++, phep chia nguyen duoc quy dinh nhu sau:

1.  Neu so chia bang 0, hanh vi la khong xac dinh;
2.  Neu khong, ket qua cua `(a / b) * b + a % b` bang `a`.

Noi cach khac, dau cua ket qua modulo phu thuoc vao cach lam tron thuong; con cach lam tron thuong tung la hanh vi do cai dat quyet dinh (do trinh bien dich quyet dinh).

Tu tieu chuan [C99](https://en.cppreference.com/w/c/language/operator_arithmetic) va [C++11](https://en.cppreference.com/w/cpp/language/operator_arithmetic) tro di, **thuong duoc lam tron ve 0** (bo phan thap phan); vi vay dau cua phep modulo trung voi dau cua so bi chia. Tu do, cac khang dinh sau luon dung:

```c
assert(5 % 3 == 2);
assert(5 % -3 == 2);
assert(-5 % 3 == -2);
assert(-5 % -3 == -2);
```

<span id="&#x6A21;&#x6574;&#x6570;&#x7C7B;"></span>
## Lop so nguyen modulo

So hoc modulo co the xem la viec thuc hien cac phep toan tren [lop dong du](./basic.md#%E5%90%8C%E4%BD%99%E7%B1%BB%E4%B8%8E%E5%89%A9%E4%BD%99%E7%B3%BB) theo mot modulo. Neu dung mot struct de bieu dien mot lop dong du, va dong goi phep cong, tru, nhan giua cac lop dong du thanh phuong thuc cua struct hoac toan tu nap chong, so hoc modulo co the duoc cai dat tu nhien thanh mot lop so nguyen modulo. Vi du don gian sau ho tro cong, tru, nhan va luy thua nhanh tren so nguyen co dau $32$ bit voi modulo $M < 2^{30}$:

???+ example "Mot lop so nguyen modulo don gian"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/mod-arithmetic.cpp:core"
    ```

Cach cai dat nay co y giam so lan thuc hien modulo, vi phep modulo thuong ton thoi gian hon phep cong, tru, nhan hoac so sanh thong thuong. Trong chu thich ma nguon co dua ra cach cai dat tuong duong va truc tiep hon. Y tuong chinh cua cac toi uu don gian nay la: khi cong tru hai so nguyen trong $[0,M)$, ket qua chac chan nam trong khoang $(-M,2M)$, nen co the dua ve lai $[0,M)$ bang mot lan cong hoac tru. Phep luy thua trong cai dat nay dung ky thuat [luy thua nhanh](../binary-exponentiation.md#%E6%A8%A1%E6%84%8F%E4%B9%89%E4%B8%8B%E5%8F%96%E5%B9%82).

Ngoai cac phep toan co ban nay, ta con co the thuc hien cac phep sau duoi nhieu modulo:

-   [Nghich dao](./inverse.md)
-   [Phep chia](./linear-equation.md)
-   [Giai thua](./factorial.md)
-   [To hop](./lucas.md)
-   [Khai can bac hai](./quad-residue.md#%E6%A8%A1%E6%84%8F%E4%B9%89%E4%B8%8B%E5%BC%80%E5%B9%B3%E6%96%B9)
-   [Logarit roi rac](./discrete-logarithm.md)
-   [Khai can](./residue.md#%E6%A8%A1%E6%84%8F%E4%B9%89%E4%B8%8B%E5%BC%80%E6%96%B9)

Cac phep toan nay thuong de hon khi modulo la so nguyen to. Voi modulo hop so, thuong can dung cac phien ban mo rong cua thuat toan tuong ung va [dinh ly phan du Trung Hoa](./crt.md). Phan lon cac phep toan duoi modulo co the xem la bai toan giai mot loai phuong trinh dong du. Ve phuong phap chung de giai phuong trinh dong du, co the tham khao trang [Phuong trinh dong du](./congruence-equation.md).

<span id="&#x76F8;&#x5173;&#x7B97;&#x6CD5;"></span>
## Thuat toan lien quan

Muc nay gioi thieu mot vai phuong phap toi uu phep modulo, phep nhan va luy thua nhanh duoi modulo. Voi dai da so bai toan, cach cai dat don gian o tren da du nhanh. Tuy nhien, khi bai toan yeu cau chat ve hang so thoi gian, cac toi uu nay co the phat huy tac dung bang cach giam tinh toan va thao tac modulo khong can thiet.

<span id="&#x5FEB;&#x901F;&#x4E58;"></span>
### Nhan nhanh

Trong kiem tra tinh nguyen to va phan tich thua so, ta thuong gap phep nhan lay modulo voi modulo nam trong pham vi `long long`. De tranh tran so nguyen trong qua trinh tinh, muc nay gioi thieu mot cach "nhan nhanh" xu ly duoc modulo trong pham vi `long long`, khong can dung `__int128`, va co do phuc tap $O(1)$. Thuat toan yeu cau tren he thong cham, `long double` it nhat phai duoc bieu dien bang so dau phay dong mo rong $80$ bit[^long-double-80bit].

Gia su $0 \le a, b < m$, can tinh $ab\bmod m$. Luu y:

$$
ab\bmod m=ab-\left\lfloor \dfrac{ab}m \right\rfloor m.
$$

Dung tran tu nhien cua `unsigned long long`:

$$
ab\bmod m=ab-\left\lfloor \dfrac{ab}m \right\rfloor m=\left(ab-\left\lfloor \dfrac{ab}m \right\rfloor m\right)\bmod 2^{64}.
$$

Chi can tinh duoc thuong $\left\lfloor\dfrac{ab}m\right\rfloor$, cac phep nhan va tru trong bieu thuc ben phai deu co the tinh truc tiep bang `unsigned long long`.

Bay gio chi con can xet cach tinh $\left\lfloor\dfrac {ab}m\right\rfloor$. Cach lam la dung `long double` de tinh $\dfrac am$ truoc roi nhan voi $b$. Da dung `long double` thi chac chan co sai so do chinh xac. Gia su `long double` duoc bieu dien bang so dau phay dong mo rong $80$ bit (gom $1$ bit dau, $15$ bit mu va $64$ bit tri), thi so chu so co nghia toi da ma `long double` co the bieu dien chinh xac la $64$[^floating-format]. Vi vay $\dfrac am$ trong truong hop xau nhat bat dau sai tu bit thu $65$, voi mien sai so[^ld-mul-err] la $\left(-2^{-64},2^{-64}\right)$. Nhan voi $b$, mot so nguyen co dau $64$ bit, mien sai so thanh $(-0.5,0.5)$. De don gian hoa phan thao luan sau, ta cong them $0.5$ roi lay phan nguyen; mien sai so cuoi cung la $\{0,1\}$.

Cuoi cung, khi thay vao cong thuc tren can nhan voi $-m$, nen mien sai so cuoi cung la $\{0,-m\}$. Vi $m$ nam trong pham vi `long long`, khi ket qua $r\in[0,m)$ thi tra ve truc tiep $r$, neu khong thi tra ve $r+m$.

Cai dat nhu sau:

???+ example "Cai dat tham khao"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/i64-mul.cpp:ld-mul"
    ```

Hien nay, hau het trinh bien dich C/C++ tren cac he thong cham deu ho tro kieu `__int128`[^int128], vi vay cung co the nang kieu cua thua so len `__int128` roi lay modulo truc tiep:

???+ example "Cai dat tham khao"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/i64-mul.cpp:i128-mul"
    ```

Tat nhien, phep modulo tren `__int128` cung khong re. Neu can toi uu hang so hon nua, co the xet cac phuong phap trong hai muc tiep theo.

<span id="barrett-&#x7EA6;&#x51CF;"></span>
### Rut gon Barrett

Nhu da noi o tren, phep chia va modulo thuong ton thoi gian hon cac phep toan so hoc khac. De giam chi phi modulo, co mot so thuat toan cho ket qua tuong tu ma khong truc tiep thuc hien modulo. Barrett reduction, hay phep rut gon Barrett, la mot trong so do.

Cho $m$ la modulo co dinh, gia su can tinh $a\bmod m$ nhieu lan voi cac gia tri $a > 0$ khac nhau. Theo phep chia co du,

$$
z = a\bmod m = a - \left\lfloor\dfrac{a}{m}\right\rfloor m.
$$

Diem then chot nam o viec tinh thuong $\left\lfloor\dfrac{a}{m}\right\rfloor$. Dat $R$ la mot hang so nao do, ta co[^floor-barrett]

$$
\left\lfloor\dfrac{a}{m}\right\rfloor = \left\lfloor a\dfrac{R}{m} / R\right\rfloor \approx \left\lfloor a\left\lfloor\dfrac{R}{m}\right\rfloor/R\right\rfloor.
$$

Neu chon $R = 2^k$, thi $\left\lfloor\dfrac{R}{m}\right\rfloor$ trong ve phai co the tien xu ly, va phep chia cho $R$ co the thuc hien bang dich bit. Do do, tinh thuong bang ve phai chi can mot phep nhan va mot phep dich. Thay vao bieu thuc cua $a\bmod m$, ta thu duoc uoc luong $z'$ cua so du can tim.

Phan tich sai so cua cach lam nay. [Ham lay phan nguyen](./basic.md#%E5%8F%96%E6%95%B4%E5%87%BD%E6%95%B0) co tinh chat: voi $x > y > 0$, luon co $\lfloor x\rfloor - \lfloor y\rfloor \le \lceil x - y\rceil$. Vi vay sai so

$$
\begin{aligned}
\Delta &= |z' - z| = m\left|\left\lfloor\dfrac{a}{m}\right\rfloor - \left\lfloor a\left\lfloor\dfrac{R}{m}\right\rfloor/R\right\rfloor\right|\\
&\le m\left\lceil a\left(\dfrac{R}{m} - \left\lfloor\dfrac{R}{m}\right\rfloor\right) /R\right\rceil \le m\left\lceil\dfrac{a}{R}\right\rceil.
\end{aligned}
$$

Chi can $a \le R$, sai so $\Delta$ khong vuot qua $m$. Do $z' \ge z$, gia tri uoc luong $z'$ chi co the la $z$ hoac $z + m$. Sau khi co uoc luong, neu $z' \ge m$ thi tru di phan $m$ thua la du de bao dam dap an dung.

Trong qua trinh tinh Barrett reduction, chi can hai phep nhan, mot phep dich bit va toi da hai phep tru de hoan thanh modulo so nguyen. Tuy nhien, hieu nang tang khong phai mien phi: cac bien trung gian trong Barrett reduction thuong dai hon bien dau vao. De thay rang bien trung gian dai nhat trong Barrett reduction la $a\left\lfloor\dfrac{R}{m}\right\rfloor$. Dat $\ell(x)$ la do dai bieu dien nhi phan cua so nguyen $x$. Khi do

$$
\ell\left(a\left\lfloor\dfrac{R}{m}\right\rfloor\right) \approx \ell(a) + \ell(R) - \ell(m).
$$

Vi cach chon $R$ can thoa man $a < R$, do dai nay it nhat la $2\ell(a) - \ell(m)$. Nhung khi can modulo, thuong co $\ell(m)\le\ell(a)$, nen do dai bien trung gian nay co the lon hon do dai dau vao $\ell(a)$. Vi du, neu can lay modulo mot so nguyen $64$ bit theo mot so nguyen $32$ bit, thuc te can bien trung gian $64 \times 2 - 32 = 96$ bit.

Mot ung dung cua Barrett reduction la tinh so du cua tich $ab\bmod m$. Neu mot thua so co dinh, chang han $b$ co dinh, co the uoc luong tuong tu bang

$$
ab\bmod m = ab - \left\lfloor a\left\lfloor\dfrac{bR}{m}\right\rfloor/R\right\rfloor m
$$

chi can tien xu ly gia tri $\left\lfloor\dfrac{bR}{m}\right\rfloor$. Truong hop $b$ co dinh nay doi khi duoc goi la phep nhan modulo Shoup[^shoup].

Truong hop pho bien hon la ca $a,b$ deu khong co dinh. Khi do can tinh gia tri $ab$ truoc, roi dung Barrett reduction de thu duoc $ab\bmod m$. Vi du, khi cai dat phep nhan modulo, can tinh $ab\bmod m$ voi $0 \le a,b < m$. Luc nay $R$ duoc chon can thoa man $ab < R$. Theo phan tich tren, bien trung gian dai nhat trong qua trinh tinh co do dai $2\ell(ab)-\ell(m)$. Khi $\ell(a)\approx\ell(b)\approx\ell(m)$, do dai nay la $3\ell(m)$. Noi cach khac, neu dung Barrett reduction de cai dat phep nhan modulo cho so nguyen $32$ bit, bien trung gian can so nguyen $96$ bit. Day cung la mot han che cua Barrett reduction khi ap dung trong lap trinh thi dau.

Lam vi du, cai dat tham khao cho phep nhan modulo so nguyen co dau 32 bit bang Barrett reduction nhu sau:

???+ example "Cai dat tham khao"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/i32-mul.cpp:barrett"
    ```

Cai dat nay can dung so nguyen 128 bit[^int128].

<span id="montgomery-&#x6A21;&#x4E58;"></span>
### Phep nhan modulo Montgomery

Thuat toan nhan modulo Montgomery co chuc nang rat giong thuat toan Barrett: no cung giam chi phi modulo trong qua trinh tinh so nguyen modulo. Khac voi hai thuat toan truoc deu dua tren xap xi thuong, phep nhan modulo Montgomery anh xa moi so nguyen vao khong gian Montgomery, noi cac phep toan tuong doi de thuc hien, tu do giam chi phi tinh toan tong the.

Cho modulo $m$ la so le, va chon $R = 2^k > m$. Khi do dang Montgomery cua lop dong du $a \bmod m$ la

$$
aR\bmod m.
$$

Vi $R\perp m$, co mot song anh giua lop dong du $a \bmod m$ va dang Montgomery cua no $aR\bmod m$. Do do, co the chuyen so nguyen sang dang Montgomery, thuc hien mot so phep toan modulo $m$, roi chuyen dang Montgomery thu duoc ve so nguyen; ket qua luon dung.

Dang Montgomery cho phep thuc hien thuan tien nhieu phep toan so nguyen modulo. Nhu da noi, de so sanh hai lop dong du co giong nhau hay khong, chi can so sanh dang Montgomery cua chung. Lai co

$$
(a+b)R\bmod m = ((aR\bmod m)\pm(bR\bmod m)) \bmod{m},
$$

nen phep cong, tru tren lop dong du tuong ung voi phep cong, tru tren dang Montgomery cua chung. Tuy nhien, de tinh phep nhan lop dong du, khong the truc tiep nhan hai dang Montgomery. Vi

$$
(ab)R\bmod m =  ((aR\bmod m)(bR\bmod m)R^{-1}) \bmod{m},
$$

nen khi tinh tich cua hai dang Montgomery, can thuc hien **phep rut gon Montgomery** (Montgomery reduction) sau tren tich $x$ cua chung:

$$
\operatorname{REDC}: x \mapsto xR^{-1}\bmod m.
$$

Dung thao tac nay, dang Montgomery cua tich $ab$ la $\operatorname{REDC}((aR\bmod m)(bR\bmod m))$. Phep rut gon Montgomery la thao tac cot loi cua phep nhan modulo Montgomery:

-   Chuyen $a$ sang dang Montgomery cua no la $\operatorname{REDC}((a\bmod m)(R^2\bmod m))$.
-   Chuyen dang Montgomery cua $a$ ve $a\bmod m$ la $\operatorname{REDC}(aR\bmod m)$.
-   Dang Montgomery ung voi nghich dao modulo $a^{-1}\bmod m$ la $\operatorname{REDC}((aR\bmod m)^{-1}(R^3\bmod m))$.

Bay gio xet cach cai dat phep rut gon Montgomery $\operatorname{REDC}$. Khi tinh $\operatorname{REDC}(x)$, luon gia su $0 \le x < m^2$, dieu nay dung voi cac truong hop tren. Vi $R\perp m$, theo [dinh ly Bezout](./bezouts.md), ton tai cac so nguyen $R^{-1},m'$ sao cho

$$
RR^{-1} + mm' = 1.
$$

Do do, dat $q=\lfloor xm' / R\rfloor$, ta co

$$
\begin{aligned}
xR^{-1} &= x\dfrac{1 - mm'}{R} \equiv \dfrac{x-xmm' + qmR}{R} = \dfrac{x - m(xm'\bmod R)}{R} \pmod{m}.
\end{aligned}
$$

Vi $0 \le x < m^2 < mR$ va $0 \le xm'\bmod R < R$, nen

$$
-m < \dfrac{x - m(xm'\bmod R)}{R} < m.
$$

Noi cach khac, thuong nay va $xR^{-1}\bmod m$ chen nhau nhieu nhat mot $m$. Chi can neu thuong am thi cong them $m$ la thu duoc $\operatorname{REDC}(x)$. Tinh thuong nay chi can hai phep nhan so nguyen, mot phep tru so nguyen va hai thao tac bit (lan luot la lay modulo theo $R=2^k$ va thuc hien phep chia). Vi vay, phep rut gon Montgomery co the thuc hien hieu qua.

De thuc hien phep nhan modulo Montgomery, can tien xu ly mot loat hang so. Truoc het, phep rut gon Montgomery can $m' = m^{-1}\bmod R$, co the tinh bang phuong phap Newton-Hensel gioi thieu [ben duoi](#%E6%A8%A1-2-%E7%9A%84%E5%B9%82%E6%AC%A1%E7%9A%84%E6%95%B4%E6%95%B0%E7%B1%BB). Tiep theo, khi quy cac thao tac khac ve phep rut gon Montgomery, con can cac hang so nhu $R^2\bmod m$. De tinh no, truoc het tinh $R\bmod m$, cong no voi chinh no de duoc $2R\bmod m$. Sau do xem no la dang Montgomery cua $2$, tinh luy thua nhanh truc tiep, se thu duoc $2^kR\bmod m = R^2\bmod m$.

Lam vi du, cai dat phep nhan modulo Montgomery cho so nguyen co dau $32$ bit nhu sau:

???+ example "Cai dat tham khao"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/i32-mul.cpp:montgomery"
    ```

So voi viec dung Barrett reduction de cai dat phep nhan modulo, phep nhan modulo Montgomery gom nhieu buoc nhu chuyen doi, nhan trong dang Montgomery va chuyen nguoc. Vi vay, chi khi so phep toan modulo giua chuyen doi va chuyen nguoc du nhieu, chi phi chuyen doi moi duoc khau hao va hieu nang tong the moi cao. Tuy nhien, do qua trinh cai dat phep nhan modulo Montgomery chi can bien trung gian co do dai $2\ell(m)$, no linh hoat hon. Vi du, phep nhan modulo cho so nguyen $32$ bit chi can bien trung gian $64$ bit. Do do, neu can cai dat mot lop so nguyen modulo de thuc hien nhieu tinh toan so hoc, phep nhan modulo Montgomery phu hop hon.

<span id="&#x6A21;-2-&#x7684;&#x5E42;&#x6B21;&#x7684;&#x6574;&#x6570;&#x7C7B;"></span>
### Lop so nguyen modulo luy thua cua 2

Muc nay thao luan cach cai dat lop so nguyen modulo khi modulo la luy thua cua $2$. Trong truong hop dac biet nay, phep chia va modulo co the thuc hien bang thao tac bit, nen rat hieu qua. Barrett reduction va phep nhan modulo Montgomery deu tan dung dac tinh nay khi dung $2^e$ lam so chia va modulo de tang toc. Dac biet, khi modulo dung bang cac so dac biet nhu $2^{32}$ va $2^{64}$, co the dung so nguyen khong dau co do dai bit tuong ung ket hop voi tran tu nhien de cai dat lop so nguyen modulo, khong can phep modulo tuong minh nao. Ngay ca khi modulo khong dung bang nhu vay, cung co the chuyen ve cac modulo dac biet nay. Vi du voi modulo $2^{58}$, co the hoan thanh tinh toan trung gian duoi modulo $2^{64}$, roi cuoi cung lay ket qua modulo $2^{58}$. Ngoai modulo de tinh, lop so nguyen modulo $2^e$ con co nhieu cach cai dat dac biet cho cac thao tac khac. Muc nay tap trung gioi thieu cach cai dat nghich dao va luy thua.

Truoc het la phep lay nghich dao: cho so le $a$ va modulo $m=2^e~(e > 2)$, can tinh $a^{-1}\bmod m$. Cac cach lay nghich dao thuong gap gom thuat toan Euclid mo rong va luy thua nhanh. Qua trinh Euclid mo rong lien quan den phep modulo theo modulo tong quat; luy thua nhanh thong thuong can tinh $a^{\varphi(m)-1}\bmod{m}$, can $\Theta(e)$ phep nhan so nguyen. Phuong phap hieu qua hon la [Newton-Hensel](../poly/newton.md). Cu the, xet ket luan sau:[^newton-hensel]

$$
mx \equiv 1 \pmod{2^e} \implies mx(2 - mx) \equiv 1\pmod{2^{2e}}.
$$

Theo bieu thuc nay, chi can bat dau tu $x = 1$ va lap lai $x \gets x(2-mx)$, sau $\lceil\log_2 e\rceil$ lan lap se thu duoc $m^{-1}\bmod R$.

Lam vi du, cai dat tham khao cho phep lay nghich dao modulo $2^{32}$ nhu sau:

???+ example "Cai dat tham khao"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/mod-32-inv-pow.cpp:inv"
    ```

Tiep theo, xet phep luy thua: cho $x,a,b$ va modulo $m=2^e~(e > 2)$, can tinh $xa^b\bmod m$, trong do $a$ la so le. Theo [phan tich](./primitive-root.md#mod-pow-2) cau truc nhan cua cac so nguyen modulo $2^e$, $a$ luon co the viet duoi dang $\pm g^{\ell}$[^mod-2-g], va dau tru xuat hien khi va chi khi $a\equiv 3\pmod 4$. Trong truong hop nay, co the thay $a$ bang $-a$, roi nhan ket qua cuoi cung voi $(-1)^b$. Vi vay, tiep theo co the gia su $a\equiv 1\pmod 4$. Y tuong cot loi cua thuat toan la viet $a$ thanh $g^{L(a)}\bmod m$, roi dung $xg^{bL(a)}\bmod m$ de tinh luy thua can tim.

Tinh $L(a)$ chinh la tinh logarit roi rac $\operatorname{ind}_ga$. Luu y rang neu $a\equiv 1\pmod 4$, thi $a$ luon co the viet duoi dang

$$
a \equiv (2^{e_1}+1)(2^{e_2}+1)\cdots(2^{e_s}+1) \pmod{m},
$$

trong do $1 < e_1 < e_2 < \cdots < e_s < e$. Ly do la khi khai trien truc tiep tich nay, bit bang $1$ thap thu hai trong bieu dien nhi phan cua $a$ chinh la bit thu $e_1$ (chi so bat dau tu $0$), tu do co the tim bieu dien nay mot cach de quy. Theo [tinh chat](./discrete-logarithm.md#%E6%80%A7%E8%B4%A8) cua logarit roi rac, ta co

$$
4L(a) \equiv 4L(2^{e_1}+1) + 4L(2^{e_2}+1) + \cdots + 4L(2^{e_s}+1) \pmod{m}. 
$$

Vi modulo cua logarit roi rac bang bac $\delta_m(g)=2^{e-2}=m/4$, o day nhan ca dong du thuc voi $4$ de bao dam qua trinh tinh co the thuc hien trong cac lop thang du modulo $m$. Do do, chi can tien xu ly tat ca gia tri $4L(2^d+1)$ voi $1 < d < e$, la co the tinh nhanh $4L(a)$.

Nguoc lai, tu $L(a)$ cung de thu duoc gia tri $g^a\bmod{m}$. Theo [dinh ly nhi thuc](../combinatorics/combination.md#%E4%BA%8C%E9%A1%B9%E5%BC%8F%E5%AE%9A%E7%90%86), voi $1 < d < e$ deu co

$$
\begin{aligned}
(2^d+1)^{2^{e-d}} \equiv 1 \pmod{m},\quad
(2^d+1)^{2^{e-d-1}} \equiv 1 + 2^{e-1} \pmod{m},
\end{aligned}
$$

nen $\delta_m(2^d+1) = 2^{e-d}$. Theo tinh chat cua bac,

$$
\delta_m(2^d+1) = \dfrac{\delta_m(g)}{\gcd(\delta_m(g), \operatorname{ind}_g(2^d+1))}.
$$

Do do, $\gcd(\delta_m(g), \operatorname{ind}_g(2^d+1)) = 2^{d-2}$. Dieu nay cho thay $L(2^d+1) = \operatorname{ind}_g(2^d+1) = 2^{d-2}r$, trong do $2\nmid r$. Vi vay, bit bang $1$ thap nhat trong bieu dien nhi phan cua $4L(2^d+1)$ chinh la bit thu $d$ (chi so bat dau tu $0$). Nho do, cung co the dua vao bieu dien nhi phan de de quy phan tich $4L(a)$ thanh tong cac so co dang $4L(2^d+1)$, tu do thu duoc gia tri cua $a$.

Khi cai dat cu the, co mot vai diem co the toi uu them. Truoc het, viec phan tich $a$ thanh dang tich van can dung phep chia. Cach thuan tien hon la tinh phan tich cua $a^{-1}$, tuc la tim $1 < e_1 < e_2 < \cdots < e_s < e$ sao cho

$$
a(2^{e_1}+1)(2^{e_2}+1)\cdots(2^{e_s}+1) \equiv 1 \pmod{m}
$$

dung. Van xac dinh $e_1$ bang cach tim bit bang $1$ thap thu hai, nhung de khu nhan tu $2^{e_1}+1$ trong $a^{-1}$, chi can nhan $a$ voi $2^{e_1}+1$, thao tac nay co the thuc hien bang bit. Lai vi $4L(a^{-1})=-4L(a)$, nen khi cong don $4L(a)$ can dung phep tru thay cho phep cong. Thu hai, voi lua chon co so $g$ dac biet, vong lap khong can chay den $d = e-1$, ma chi can chay den $d = \lceil e/2\rceil - 1$. De lam vay, can chon $g$ sao cho

$$
4L(2^{\lceil e/2\rceil} + 1) = 2^{\lceil e/2\rceil}.
$$

Voi $d \ge e / 2$, deu co

$$
(2^d+1)^2 = 2^{2d} + 2^{d+1} + 1 \equiv 2^{d+1} + 1 \pmod{m}.
$$

Do do, quy nap tu $d = \lceil e/2\rceil$ cho thay $L(2^d+1)=2^d$ dung voi moi $d \ge e/2$. Suy ra, chi can $e/2 \le e_1 < e_2 < \cdots < e_s < e$, ta co

$$
(2^{e_1}+1)(2^{e_2}+1)\cdots(2^{e_s}+1) \equiv 1 + 2^{e_1} + 2^{e_2} + \cdots + 2^{e_s} \pmod{m}
$$

va

$$
4L((2^{e_1}+1)(2^{e_2}+1)\cdots(2^{e_s}+1)) = 2^{e_1} + 2^{e_2} + \cdots + 2^{e_s}.
$$

Vi vay, sau khi xu ly tat ca cac bit $d < e/2$, co the truc tiep thu duoc logarit roi rac cua phan con lai ma khong can tinh tung bit. Sau toi uu thu nhat, toan bo phep luy thua chi can $O(e)$ phep cong tru, thao tac bit va $1$ phep nhan; sau toi uu thu hai, co the tiet kiem gan mot nua so phep cong tru va thao tac bit, doi lai can them $1$ phep nhan.

Lam vi du, cai dat tham khao cho phep luy thua modulo $2^{32}$ nhu sau:

???+ example "Cai dat tham khao"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/mod-32-inv-pow.cpp:pow"
    ```

Tien xu ly logarit roi rac co the thuc hien bang thuat toan Pohlig-Hellman, va co the chon co so $g$ la

$$
5^{\operatorname{ind}_5(2^{\lceil e/2\rceil})/2^{\lceil e/2\rceil - 2}}\bmod{2^e}.
$$

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x6CE8;&#x91CA;"></span>
## Tai lieu tham khao va ghi chu

-   [Fast modular multiplication by orz - Codeforces](https://codeforces.com/blog/entry/96759)
-   [Barrett Reduction - Wikipedia](https://en.wikipedia.org/wiki/Barrett_reduction)
-   [Barrett Reduction - A41](https://encrypt.a41.io/primitives/modular-arithmetic/modular-reduction/barrett-reduction#cost-analysis-of-modular-multiplication)
-   [Nguyen ly va chung minh tinh dung cua Barrett reduction by Chen - Zhihu](https://zhuanlan.zhihu.com/p/690876166)
-   [Montgomery Multiplication - CP Algorithms](https://cp-algorithms.com/algebra/montgomery_multiplication.html)
-   [Phep nhan modulo Montgomery by Chen - Zhihu](https://zhuanlan.zhihu.com/p/645428404)
-   [Binary Exponentiation by Factoring - CP Algorithms](https://cp-algorithms.com/algebra/factoring-exp.html)
-   Barrett, Paul. "Implementing the Rivest Shamir and Adleman public key encryption algorithm on a standard digital signal processor." In Conference on the Theory and Application of Cryptographic Techniques, pp. 311-323. Berlin, Heidelberg: Springer Berlin Heidelberg, 1986.
-   Becker, Hanno, Vincent Hwang, Matthias J. Kannwischer, Bo-Yin Yang, and Shang-Yi Yang. "Neon NTT: Faster Dilithium, Kyber, and Saber on Cortex-A72 and Apple M1." IACR Transactions on Cryptographic Hardware and Embedded Systems (2022): 221-244.
-   Montgomery, Peter L. "Modular multiplication without trial division." Mathematics of computation 44, no. 170 (1985): 519-521.

[^long-double-80bit]: Dieu nay dung voi GCC hoac Clang tren phan lon he thong 64 bit.

[^floating-format]: Xem [Double-precision floating-point format - Wikipedia](https://en.wikipedia.org/wiki/Double-precision_floating-point_format).

[^ld-mul-err]: O day dung dieu kien $a < m$, tuc la $a / m \in [0,1)$.

[^int128]: Trong cac moi truong bien dich pho bien hien nay, chi MSVC tren Windows khong ho tro kieu `__int128`. Neu can viet ma tuong thich nhieu nen tang, co the phat hien moi truong MSVC bang macro `_MSC_VER`, roi trong dieu kien do include [`<intrin.h>`](https://learn.microsoft.com/en-us/cpp/intrinsics/x64-amd64-intrinsics-list?view=msvc-170) va dung cac ham noi tai duoc cung cap (nhu `_umul128`) de gian tiep cai dat so nguyen 128 bit (chi kha dung tren nen tang 64 bit).

[^floor-barrett]: O day $\left\lfloor\dfrac{r}{m}\right\rfloor$ cung co the thay bang cac uoc luong nguyen khac cua $\dfrac{r}{m}$, chang han ham tran $\left\lceil\dfrac{r}{m}\right\rceil$ va ham lam tron gan nhat $\left\lfloor\dfrac{r}{m}\right\rceil$, mien la dieu chinh buoc sua sai so cua gia tri uoc luong tuong ung.

[^shoup]: Shoup da cai dat mo rong nay cua Barrett reduction trong thu vien tinh toan so hoc [NTL](https://libntl.org/), nen cach lam duoc dat ten nhu vay.

[^newton-hensel]: Kiem tra truc tiep: tu $mx \equiv 1 \pmod{2^e}$, dat $mx = 1 + \lambda 2^e$, khi do $mx(2-mx) = (1+\lambda 2^e)(1-\lambda 2^e) = 1 - \lambda^2 2^{2e} \equiv 1\pmod{2^{2e}}$.

[^mod-2-g]: Trang duoc dan trong bai chi chung minh $g$ co the lay bang $5$. Thuc ra, lap lai hoan toan chung minh do cho thay $g$ co the la bat ky so nguyen nao dong du $5$ theo modulo $8$. Phan sau se thao luan cach chon $g$.
