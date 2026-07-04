Bai viet nay gioi thieu phan mo dau cua so hoc.

<span id="&#x6574;&#x9664;"></span>
## Tinh chia het

???+ note "Dinh nghia"
    Cho $a,b\in\mathbf{Z}$, $a\ne 0$. Neu $\exists q\in\mathbf{Z}$ sao cho $b=aq$, ta noi $b$ **chia het** cho $a$, ki hieu $a\mid b$; $b$ khong chia het cho $a$ duoc ki hieu $a\nmid b$.

Tinh chat cua quan he chia het:

-   $a\mid b\iff-a\mid b\iff a\mid-b\iff|a|\mid|b|$
-   $a\mid b\land b\mid c\implies a\mid c$
-   $a\mid b\land a\mid c\iff\forall x,y\in\mathbf{Z}, a\mid(xb+yc)$
-   $a\mid b\land b\mid a\implies b=\pm a$
-   Cho $m\ne0$, khi do $a\mid b\iff ma\mid mb$.
-   Cho $b\ne0$, khi do $a\mid b\implies|a|\le|b|$.
-   Cho $a\ne0,b=qa+c$, khi do $a\mid b\iff a\mid c$.

<span id="&#x7EA6;&#x6570;"></span>
### Uoc so

???+ note "Dinh nghia"
    Neu $a\mid b$, thi $b$ duoc goi la **boi so** cua $a$, con $a$ duoc goi la **uoc so** cua $b$.

$0$ la boi so cua moi so nguyen khac $0$. Voi so nguyen $b\ne0$, $b$ chi co huu han uoc so.

Uoc so tam thuong (nhan tu tam thuong): voi so nguyen $b\ne0$, $\pm1$, $\pm b$ la cac uoc so tam thuong cua $b$. Khi $b=\pm1$, $b$ chi co hai uoc so tam thuong.

Voi so nguyen $b\ne 0$, cac uoc so con lai cua $b$ duoc goi la uoc so thuc su (nhan tu thuc su, uoc so khong tam thuong, nhan tu khong tam thuong).

Tinh chat cua uoc so:

-   Cho so nguyen $b\ne0$. Khi $d$ chay qua tat ca cac uoc so cua $b$, $\dfrac{b}{d}$ cung chay qua tat ca cac uoc so cua $b$.
-   Cho so nguyen $b\gt 0$. Khi $d$ chay qua tat ca cac uoc so duong cua $b$, $\dfrac{b}{d}$ cung chay qua tat ca cac uoc so duong cua $b$.

Trong cac bai toan cu the, **neu khong noi ro, uoc so luon duoc hieu la uoc so duong.**

<span id="&#x5E26;&#x4F59;&#x6570;&#x9664;&#x6CD5;"></span>
## Phep chia co du

???+ note "So du"
    Cho $a,b$ la hai so nguyen da cho, $a\ne0$. Cho $d$ la mot so nguyen da cho. Khi do ton tai duy nhat mot cap so nguyen $q$ va $r$ thoa man $b=qa+r,d\le r<|a|+d$.

Voi moi gia tri nguyen cua $d$, $r$ duoc goi chung la so du. $a\mid b$ tuong duong voi $a\mid r$.

Thong thuong lay $d=0$; khi do dang $b=qa+r,0\le r<|a|$ duoc goi la phep chia co du. So du $r$ o day duoc goi la so du khong am nho nhat.

So du con co hai cach chon thuong gap:

-   So du co tri tuyet doi nho nhat: lay $d$ bang so doi cua mot nua $|a|$, tuc la $b=qa+r,-\dfrac{|a|}{2}\le r<|a|-\dfrac{|a|}{2}$.
-   So du duong nho nhat: lay $d=1$, tuc la $b=qa+r,1\le r<|a|+1$.

So du trong phep chia co du chi la so du khong am nho nhat. **Neu khong noi ro, so du luon duoc hieu la so du khong am nho nhat.**

Tinh chat cua so du:

-   Mot so nguyen bat ky khi chia cho so nguyen duong $a$ co so du chac chan va chi co the la mot trong $a$ so $0$ den $a-1$.
-   $a$ so nguyen lien tiep khi chia cho so nguyen duong $a$ se nhan dung mot lan moi so du noi tren. Dac biet, chac chan co dung mot so chia het cho $a$.

<span id="&#x6700;&#x5927;&#x516C;&#x7EA6;&#x6570;&#x4E0E;&#x6700;&#x5C0F;&#x516C;&#x500D;&#x6570;"></span>
## Uoc chung lon nhat va boi chung nho nhat

Ve cac dinh nghia uoc chung, boi chung, uoc chung lon nhat va boi chung nho nhat, xem [Uoc chung lon nhat](./gcd.md).

???+ warning "Canh bao"
    Mot so tac gia xem uoc chung lon nhat cua $0$ va $0$ la khong duoc dinh nghia; cac tac gia khac thuong xem no bang $0$. Cach cai dat trong C++ STL dung quan diem sau, tuc la uoc chung lon nhat cua $0$ va $0$ bang $0$[^gcdcpp].

Uoc chung lon nhat co cac tinh chat sau:

-   $(a_1,\dots,a_n)=(|a_1|,\dots,|a_n|)$;
-   $(a,b)=(b,a)$;
-   Neu $a\ne 0$, thi $(a,0)=(a,a)=|a|$;
-   $(bq+r,b)=(r,b)$;
-   $(a_1,\dots,a_n)=((a_1,a_2),a_3,\dots,a_n)$. Suy ra $\forall 1<k<n-1,~(a_1,\dots,a_n)=((a_1,\dots,a_k),(a_{k+1},\dots,a_n))$;
-   Voi cac so nguyen $a_1,\dots,a_n$ khong dong thoi bang $0$ va so nguyen khac khong $m$, $(ma_1,\dots,ma_n)=|m|(a_1,\dots,a_n)$;
-   Voi cac so nguyen $a_1,\dots,a_n$ khong dong thoi bang $0$, neu $(a_1,\dots,a_n)=d$, thi $(a_1/d,\dots,a_n/d)=1$;
-   $(a^n,b^n)=(a,b)^n$.

Uoc chung lon nhat con co cac tinh chat lien quan den tinh nguyen to cung nhau:

-   Neu $b|ac$ va $(a,b)=1$, thi $b\mid c$;
-   Neu $b|c$, $a|c$ va $(a,b)=1$, thi $ab\mid c$;
-   Neu $(a,b)=1$, thi $(a,bc)=(a,c)$;
-   Neu $(a_i,b_j)=1,~\forall 1\leq i\leq n,1\leq j\leq m$, thi $\left(\prod_i a_i,\prod_j b_j\right)=1$. Dac biet, neu $(a,b)=1$, thi $(a^n,b^m)=1$;
-   Voi cac so nguyen $a_1,\dots,a_n$, neu $\exists v\in \mathbf{Z},~\prod_i a_i=v^m$, va $(a_i,a_j)=1,~\forall i\ne j$, thi $\forall 1\leq i\leq n,~\sqrt[m]{a_i}\in\mathbf{Z}$.

Boi chung nho nhat co cac tinh chat sau:

-   $[a_1,\dots,a_n]=[|a_1|,\dots,|a_n|]$;
-   $[a,b]=[b,a]$;
-   Neu $a\ne 0$, thi $[a,1]=[a,a]=|a|$;
-   Neu $a\mid b$, thi $[a,b]=|b|$;
-   $[a_1,\dots,a_n]=[[a_1,a_2],a_3,\dots,a_n]$. Suy ra $\forall 1<k<n-1,~[a_1,\dots,a_n]=[[a_1,\dots,a_k],[a_{k+1},\dots,a_n]]$;
-   Neu $a_i\mid m,~\forall 1\leq i\leq n$, thi $[a_1,\dots,a_n]\mid m$;
-   $[ma_1,\dots,ma_n]=|m|[a_1,\dots,a_n]$;
-   $[a,b,c][ab,bc,ca]=[a,b][b,c][c,a]$;
-   $[a^n,b^n]=[a,b]^n$.

Uoc chung lon nhat va boi chung nho nhat co the ket hop thanh nhieu dang thuc dep, chang han:

-   $(a,b)[a,b]=|ab|$;
-   $(ab,bc,ca)[a,b,c]=|abc|$;
-   $\dfrac{(a,b,c)^2}{(a,b)(b,c)(a,c)}=\dfrac{[a,b,c]^2}{[a,b][b,c][a,c]}$.

Tat ca cac tinh chat nay deu co the chung minh tu dinh nghia hoac tu [dinh ly phan tich duy nhat](#%E7%AE%97%E6%9C%AF%E5%9F%BA%E6%9C%AC%E5%AE%9A%E7%90%86); chung minh dung dinh ly phan tich duy nhat thuong de hieu hon.

<span id="&#x4E92;&#x7D20;"></span>
### Nguyen to cung nhau

???+ note "Dinh nghia"
    Neu $(a_1,a_2)=1$, thi $a_1$ va $a_2$ duoc goi la **nguyen to cung nhau** (**toi gian**).
    
    Neu $(a_1,\ldots,a_k)=1$, thi $a_1,\ldots,a_k$ duoc goi la **nguyen to cung nhau** (**toi gian**).

Nhieu so nguyen nguyen to cung nhau khong nhat thiet phai nguyen to cung nhau tung doi. Vi du $6$, $10$ va $15$ nguyen to cung nhau, nhung bat ky hai so nao trong do cung khong nguyen to cung nhau.

Tinh chat cua nguyen to cung nhau va ly thuyet uoc chung lon nhat: dinh ly Bezout (Bézout's identity). Xem [Dinh ly Bezout](./bezouts.md).

<span id="&#x8F97;&#x8F6C;&#x76F8;&#x9664;&#x6CD5;"></span>
### Thuat toan Euclid

Thuat toan Euclid la mot thuat toan, con goi la phep chia lien tiep. Xem [Uoc chung lon nhat](./gcd.md).

<span id="&#x7D20;&#x6570;&#x4E0E;&#x5408;&#x6570;"></span>
## So nguyen to va hop so

Ve cac thuat toan lien quan den so nguyen to, xem [So nguyen to](./prime.md).

???+ note "Dinh nghia"
    Cho so nguyen $p\ne0,\pm1$. Neu $p$ khong co uoc so nao ngoai cac uoc so tam thuong, thi $p$ duoc goi la **so nguyen to** (**so bat kha quy**).
    
    Neu so nguyen $a\ne0,\pm 1$ va $a$ khong phai so nguyen to, thi $a$ duoc goi la **hop so**.

$p$ va $-p$ luon dong thoi la so nguyen to hoac dong thoi la hop so. **Neu khong noi ro, so nguyen to luon duoc hieu la so nguyen to duong.**

Neu mot nhan tu cua so nguyen la so nguyen to, thi so nguyen to do duoc goi la thua so nguyen to (uoc nguyen to) cua so nguyen ay.

Tinh chat don gian cua so nguyen to va hop so:

-   So nguyen $a$ lon hon $1$ la hop so khi va chi khi $a$ co the bieu dien thanh tich cua hai so nguyen $d$ va $e$ voi $1<d,e<a$.
-   Neu so nguyen to $p$ co uoc so $d$ lon hon $1$, thi $d=p$.
-   Moi so nguyen lon hon $1$ deu co the bieu dien thanh tich cac so nguyen to.
-   Voi hop so $a$, chac chan ton tai so nguyen to $p\le\sqrt{a}$ sao cho $p\mid a$.
-   Co vo han so nguyen to.
-   Moi so nguyen to lon hon $3$ deu co dang $6n\pm 1$[^ref1].

<span id="&#x7B97;&#x672F;&#x57FA;&#x672C;&#x5B9A;&#x7406;"></span>
## Dinh ly co ban cua so hoc

???+ note "Bo de co ban cua so hoc"
    Cho $p$ la so nguyen to, $p\mid a_1a_2$. Khi do it nhat mot trong hai menh de $p\mid a_1$ va $p\mid a_2$ dung.

Menh de dao cua bo de co ban cua so hoc, sau khi dieu chinh nhe, cung cho mot dinh nghia khac cua so nguyen to.

???+ note "Mot dinh nghia khac cua so nguyen to"
    Voi so nguyen $p\ne 0,\pm 1$, neu voi moi cap so nguyen $a_1,a_2$ thoa man $p\mid a_1a_2$ deu co $p\mid a_1$ hoac $p\mid a_2$, thi $p$ la so nguyen to.

??? tip "Meo"
    Dong co cua dinh nghia nay co the tim thay trong [ideal nguyen to](../algebra/ring-theory.md#%E7%B4%A0%E7%90%86%E6%83%B3).

???+ note "Dinh ly co ban cua so hoc (dinh ly phan tich duy nhat)"
    Cho so nguyen duong $a$, khi do luon co bieu dien:
    
    $$
    a=p_1p_2\cdots p_s
    $$
    
    trong do $p_j(1\le j\le s)$ la cac so nguyen to. Hon nua, bieu dien nay la duy nhat neu khong ke den thu tu cac thua so.

???+ note "Dang phan tich thua so nguyen to chuan"
    Gom cac so nguyen to giong nhau trong bieu dien tren, ta duoc:
    
    $$
    a={p_1}^{\alpha_1}{p_2}^{\alpha_2}\cdots{p_s}^{\alpha_s},p_1<p_2<\cdots<p_s
    $$
    
    Day duoc goi la dang phan tich thua so nguyen to chuan cua so nguyen duong $a$.

Dinh ly co ban cua so hoc va bo de co ban cua so hoc la hai dinh ly tuong duong.

<span id="&#x540C;&#x4F59;"></span>
## Dong du

???+ note "Dinh nghia"
    Cho so nguyen $m\ne0$. Neu $m\mid(a-b)$, ta goi $m$ la **modun** (**modulo**), noi $a$ dong du voi $b$ theo modulo $m$, va $b$ la **thang du** cua $a$ theo modulo $m$. Ki hieu $a\equiv b\pmod m$.
    
    Nguoc lai, $a$ khong dong du voi $b$ theo modulo $m$, va $b$ khong phai thang du cua $a$ theo modulo $m$. Ki hieu $a\not\equiv b\pmod m$.
    
    Mot dang thuc nhu vay duoc goi la dong du thuc modulo $m$, goi tat la **dong du thuc**.

Theo tinh chat chia het, dong du thuc tren cung tuong duong voi $a\equiv b\pmod{(-m)}$.

Trong phan sau, neu khong noi ro, modun luon la **so nguyen duong**.

$b$ trong bieu thuc la thang du cua $a$ theo modulo $m$; khai niem nay hoan toan trung voi so du. Bang cach gioi han pham vi cua $b$, ta co thang du khong am nho nhat, thang du co tri tuyet doi nho nhat, va thang du duong nho nhat cua $a$ theo modulo $m$.

Tinh chat cua dong du:

-   Dong du la mot [quan he tuong duong](../order-theory.md#%E4%BA%8C%E5%85%83%E5%85%B3%E7%B3%BB), nghia la dong du co:
    -   Tinh phan xa: $a\equiv a\pmod m$.
    -   Tinh doi xung: neu $a\equiv b\pmod m$, thi $b\equiv a\pmod m$.
    -   Tinh bac cau: neu $a\equiv b\pmod m,b\equiv c\pmod m$, thi $a\equiv c\pmod m$.
-   Phep toan tuyen tinh: neu $a,b,c,d\in\mathbf{Z},m\in\mathbf{N}^*,a\equiv b\pmod m,c\equiv d\pmod m$ thi:
    -   $a\pm c\equiv b\pm d\pmod m$.
    -   $a\times c\equiv b\times d\pmod m$.
-   Cho $f(x)=\sum_{i=0}^n a_ix^i$ va $g(x)=\sum_{i=0}^n b_ix^i$ la hai da thuc he so nguyen, $m\in\mathbf{N}^*$, va $a_i\equiv b_i\pmod m,~0\leq i\leq n$. Khi do voi moi so nguyen $x$ deu co $f(x)\equiv g(x)\pmod m$. Hon nua, neu $s\equiv t\pmod m$, thi $f(s)\equiv g(t)\pmod m$.
-   Neu $a,b\in\mathbf{Z},k,m\in\mathbf{N}^*,a\equiv b\pmod m$, thi $ak\equiv bk\pmod{mk}$.
-   Neu $a,b\in\mathbf{Z},d,m\in\mathbf{N}^*,d\mid a,d\mid b,d\mid m$, thi khi $a\equiv b\pmod m$ dung, ta co $\dfrac{a}{d}\equiv\dfrac{b}{d}\left(\bmod\;{\dfrac{m}{d}}\right)$.
-   Neu $a,b\in\mathbf{Z},d,m\in\mathbf{N}^*,d\mid m$, thi khi $a\equiv b\pmod m$ dung, ta co $a\equiv b\pmod d$.
-   Neu $a,b\in\mathbf{Z},d,m\in\mathbf{N}^*$, thi khi $a\equiv b\pmod m$ dung, ta co $(a,m)=(b,m)$. Neu $d$ chia het $m$ va chia het mot trong hai so $a,b$, thi $d$ cung chia het so con lai.

Con mot tinh chat khac la nghich dao nhan. Xem [Nghich dao nhan](./inverse.md).

<span id="&#x540C;&#x4F59;&#x7C7B;&#x4E0E;&#x5269;&#x4F59;&#x7CFB;"></span>
## Lop dong du va he thang du

De thuan tien thao luan, voi tap hop $A,B$ va phan tu $r$, ta dung cac ki hieu sau:

-   $r+A:=\{r+a:a\in A\}$;
-   $rA:=\{ra:a\in A\}$;
-   $A+B:=\{a+b:a\in A,b\in B\}$;
-   $AB:=\{ab:a\in A,b\in B\}$.

???+ note "Lop dong du"
    Voi so nguyen khac khong $m$, chia tat ca cac so nguyen thanh $|m|$ tap hop doi mot khong giao nhau, sao cho hai so bat ky trong cung mot tap hop deu dong du theo modulo $m$. Moi tap hop trong $|m|$ tap hop do duoc goi la **lop dong du** hoac **lop thang du** modulo $m$. Dung $r\bmod m$ de chi lop dong du modulo $m$ chua so nguyen $r$.
    
    Khong kho de chung minh voi moi so nguyen khac khong $m$, cach phan hoach tren luon ton tai va duy nhat.

Tu dinh nghia lop dong du, ta co:

-   $r\bmod m=\{r+km:k\in\mathbf{Z}\}$;
-   $r\bmod m=s\bmod m\iff r\equiv s\pmod m$;
-   Voi moi $r,s\in\mathbf{Z}$, hoac $r\bmod m=s\bmod m$, hoac $(r\bmod m)\cap (s\bmod m)=\varnothing$;
-   Neu $m_1\mid m$, thi voi moi so nguyen $r$ deu co $r+m\mathbf{Z}\subseteq r+m_1\mathbf{Z}$.

Vi dong du la quan he tuong duong, lop dong du chinh la lop tuong duong cua quan he dong du.

Ta ki hieu tap hop tat ca cac lop dong du modulo $m$ la $\mathbf{Z}_m$, tuc la

$$
\mathbf{Z}_m:=\{r\bmod m:0\leq r<m\}
$$

De thay rang:

-   Voi moi so nguyen $a$, $a+\mathbf{Z}_m=\mathbf{Z}_m$;
-   Voi moi so nguyen $b$ nguyen to cung nhau voi $m$, $b\mathbf{Z}_m=\mathbf{Z}_m$.

Theo dinh nghia [nhom thuong](../algebra/group-theory.md#%E5%95%86%E7%BE%A4), $\mathbf{Z}_m=\mathbf{Z}/m\mathbf{Z}$, vi vay doi khi ta cung dung $\mathbf{Z}/m\mathbf{Z}$ de bieu dien $\mathbf{Z}_m$.

Theo [nguyen ly chuong chim](../combinatorics/drawer-principle.md), ta co:

-   Lay tuy y $m+1$ so nguyen, chac chan co hai so dong du theo modulo $m$.
-   Ton tai $m$ so nguyen doi mot khong dong du theo modulo $m$.

Tu do ta dua ra dinh nghia he thang du day du:

???+ note "He thang du (day du)"
    Voi $m$ so nguyen $a_1,a_2,\dots,a_m$, neu voi moi so $x$ co dung mot so $a_i$ sao cho $x$ dong du voi $a_i$ theo modulo $m$, thi $m$ so nguyen $a_1,a_2,\dots,a_m$ duoc goi la **he thang du day du** modulo $m$, goi tat la **he thang du**.

Ta con co the dinh nghia cac he sau modulo $m$:

-   He thang du khong am nho nhat (day du): $0,\dots,m-1$;
-   He thang du duong nho nhat (day du): $1,\dots,m$;
-   He thang du co tri tuyet doi nho nhat (day du): $-\lfloor m/2\rfloor,\dots,-\lfloor -m/2\rfloor-1$;
-   He thang du khong duong lon nhat (day du): $-m+1,\dots,0$;
-   He thang du am lon nhat (day du): $-m,\dots,-1$.

Neu khong co ghi chu dac biet, thong thuong ta chi dung he thang du khong am nho nhat.

Ta luu y menh de sau la dung:

-   Trong mot lop dong du bat ky modulo $m$, lay tuy y hai so nguyen $a_1,a_2$ deu co $(a_1,m)=(a_2,m)$.

Xet lop dong du $r\bmod m$. Neu $(r,m)=1$, thi moi phan tu cua lop dong du nay deu nguyen to cung nhau voi $m$; dieu nay cho thay co the dung cach tuong tu de tim cau truc cua tap hop cac so nguyen nguyen to cung nhau voi $m$.

???+ note "Lop dong du thu gon"
    Voi lop dong du $r\bmod m$, neu $(r,m)=1$, thi lop dong du nay duoc goi la **lop dong du thu gon** hoac **lop thang du thu gon**.
    
    So luong lop thang du thu gon modulo $m$ duoc ki hieu la $\varphi(m)$ va duoc goi la [ham Euler](./euler-totient.md).

Ta ki hieu tap hop tat ca cac lop dong du thu gon modulo $m$ la $\mathbf{Z}_m^*$, tuc la

$$
\mathbf{Z}_m^*:=\{r\bmod m:0\leq r<m,(r,m)=1\}
$$

???+ warning "Canh bao"
    Voi so nguyen bat ky $a$ va so nguyen $b$ nguyen to cung nhau voi $m$, ta co $b\mathbf{Z}_m^*=\mathbf{Z}_m^*$, nhung $a+\mathbf{Z}_m^*$ khong nhat thiet bang $\mathbf{Z}_m^*$. Diem nay khac voi $\mathbf{Z}_m$.

Theo [nguyen ly chuong chim](../combinatorics/drawer-principle.md), ta co:

-   Lay tuy y $\varphi(m)+1$ so nguyen nguyen to cung nhau voi $m$, chac chan co hai so dong du theo modulo $m$.
-   Ton tai $\varphi(m)$ so nguyen nguyen to cung nhau voi $m$ va doi mot khong dong du theo modulo $m$.

Tu do ta dua ra dinh nghia he thang du thu gon:

???+ note "He thang du thu gon"
    Voi $t=\varphi(m)$ so nguyen $a_1,a_2,\dots,a_t$, neu $(a_i,m)=1,~\forall 1\leq i\leq t$, va voi moi so $x$ thoa man $(x,m)=1$ co dung mot so $a_i$ sao cho $x$ dong du voi $a_i$ theo modulo $m$, thi $t$ so nguyen $a_1,a_2,\dots,a_t$ duoc goi la **he thang du thu gon** modulo $m$.

Tuong tu, ta cung co the dinh nghia he thang du thu gon khong am nho nhat va cac khai niem khac.

Neu khong co ghi chu dac biet, thong thuong ta chi dung he thang du thu gon khong am nho nhat.

<span id="&#x5269;&#x4F59;&#x7CFB;&#x7684;&#x590D;&#x5408;"></span>
### Phep ghep he thang du

Voi so nguyen duong $m$, ta co dinh ly sau:

-   Neu $m=m_1m_2,~1\leq m_1,m_2$, goi $Z_{m_1},Z_{m_2}$ lan luot la cac he thang du **day du** modulo $m_1,m_2$, thi voi moi $a$ nguyen to cung nhau voi $m_1$ ta co:

    $$
    Z_m=aZ_{m_1}+m_1Z_{m_2}.
    $$

    Day la mot he thang du **day du** modulo $m$. Hon nua, neu $m=\prod_{i=1}^k m_i,~1\leq m_1,m_2,\dots,m_k$, goi $Z_{m_1},\dots,Z_{m_k}$ lan luot la cac he thang du **day du** modulo $m_1,\dots,m_k$, thi:

    $$
    Z_m=\sum_{i=1}^k\left(\prod_{j=1}^{i-1}m_j\right)Z_{m_i}.
    $$

    Day la mot he thang du **day du** modulo $m$.

???+ note "Chung minh"
    Chi can chung minh voi moi $x,x'\in Z_{m_1}$, $y,y'\in Z_{m_2}$ thoa man $ax+m_1y\equiv ax'+m_1y'\pmod{m_1m_2}$, ta deu co:
    
    $$
    ax+m_1y=ax'+m_1y'.
    $$
    
    Thuc vay, tu $m_1\mid m_1m_2$, ta co $ax+m_1y\equiv ax'+m_1y'\pmod{m_1}$, suy ra $ax\equiv ax'\pmod{m_1}$. Do $(a,m_1)=1$, suy ra $x\equiv x'\pmod{m_1}$, nen $x=x'$.
    
    Tiep theo, $m_1y\equiv m_1y'\pmod{m_1m_2}$, nen $y\equiv y'\pmod{m_2}$, tuc la $y=y'$.
    
    Vi vay,
    
    $$
    ax+m_1y=ax'+m_1y'.
    $$

-   Neu $m=m_1m_2,~1\leq m_1,m_2,(m_1,m_2)=1$, goi $Z_{m_1}^*,Z_{m_2}^*$ lan luot la cac he thang du **thu gon** modulo $m_1,m_2$, thi:

    $$
    Z_m^*=m_2Z_{m_1}^*+m_1Z_{m_2}^*.
    $$

    Day la mot he thang du **thu gon** modulo $m$.

???+ tip "Meo"
    Dinh ly nay tuong duong voi viec chung minh ham Euler la [ham nhan tinh](#%E7%A7%AF%E6%80%A7%E5%87%BD%E6%95%B0).

???+ note "Chung minh"
    Goi $Z_{m_1},Z_{m_2}$ lan luot la cac he thang du day du modulo $m_1,m_2$. Ta da chung minh
    
    $$
    Z_m=m_2Z_{m_1}+m_1Z_{m_2}
    $$
    
    la mot he thang du day du modulo $m$. Dat $M=\{a\in Z_m:(a,m)=1\}\subseteq Z_m$; ro rang $M$ la mot he thang du thu gon modulo $m$, nen chi can chung minh $M=Z_m^*$.
    
    Hien nhien $Z_m^*\subseteq Z_m$.
    
    Lay tuy y $m_2x+m_1y\in M$, trong do $x\in Z_{m_1}$ va $y\in Z_{m_2}$. Ta co $(m_2x+m_1y,m_1m_2)=1$. Tu $(m_1,m_2)=1$ suy ra
    
    $$
    1=(m_2x+m_1y,m_1)=(m_2x,m_1)=(x,m_1),
    $$
    
    $$
    1=(m_2x+m_1y,m_2)=(m_1y,m_2)=(y,m_2).
    $$
    
    Do do $x\in Z_{m_1}^*$ va $y\in Z_{m_2}^*$, tuc la $M\subseteq Z_m^*$.
    
    Lay tuy y $m_2x+m_1y\in Z_m^*$, trong do $x\in Z_{m_1}^*$ va $y\in Z_{m_2}^*$. Ta co $(x,m_1)=1$ va $(y,m_2)=1$. Tu $(m_1,m_2)=1$ suy ra
    
    $$
    (m_2x+m_1y,m_1)=(m_2x,m_1)=(x,m_1)=1,
    $$
    
    $$
    (m_2x+m_1y,m_2)=(m_1y,m_2)=(x,m_2)=1,
    $$
    
    nen $(m_2x+m_1y,m_1m_2)=1$, tuc la $Z_m^*\subseteq M$.
    
    Tong hop lai,
    
    $$
    Z_m^*=m_2Z_{m_1}^*+m_1Z_{m_2}^*.
    $$
    
    Day la mot he thang du **thu gon** modulo $m$.

<span id="&#x6570;&#x8BBA;&#x51FD;&#x6570;"></span>
## Ham so hoc

Ham so hoc (con goi la ham so so hoc) la ham co mien xac dinh la cac so nguyen duong. Ham so hoc cung co the xem nhu mot day so.

<span id="&#x79EF;&#x6027;&#x51FD;&#x6570;"></span>
### Ham nhan tinh

???+ note "Dinh nghia"
    Trong so hoc, neu ham $f(n)$ thoa man $f(1)=1$ va $f(xy)=f(x)f(y)$ voi moi cap $x, y \in\mathbf{N}^*$ nguyen to cung nhau, thi $f(n)$ la **ham nhan tinh**.
    
    Trong so hoc, neu ham $f(n)$ thoa man $f(1)=1$ va $f(xy)=f(x)f(y)$ voi moi $x, y \in\mathbf{N}^*$, thi $f(n)$ la **ham nhan tinh hoan toan**.

<span id="&#x6027;&#x8D28;"></span>
#### Tinh chat

Neu $f(x)$ va $g(x)$ deu la ham nhan tinh, thi cac ham sau cung la ham nhan tinh:

$$
\begin{aligned}
h(x)&=f(x^p)\\
h(x)&=f^p(x)\\
h(x)&=f(x)g(x)\\
h(x)&=\sum_{d\mid x}f(d)g\left(\dfrac{x}{d}\right)
\end{aligned}
$$

Voi so nguyen duong $x$, gia su phan tich thua so nguyen to duy nhat cua no la $x=\prod p_i^{k_i}$, trong do $p_i$ la so nguyen to.

Neu $F(x)$ la ham nhan tinh, thi $F(x)=\prod F(p_i^{k_i})$.

Neu $F(x)$ la ham nhan tinh hoan toan, thi $F(x)=\prod F(p_i^{k_i})=\prod F(p_i)^{k_i}$.

<span id="&#x4F8B;&#x5B50;"></span>
#### Vi du

-   Ham don vi: $\varepsilon(n)=[n=1]$. (nhan tinh hoan toan)
-   Ham dong nhat: $\operatorname{id}_k(n)=n^k$, $\operatorname{id}_{1}(n)$ thuong duoc viet gon la $\operatorname{id}(n)$. (nhan tinh hoan toan)
-   Ham hang: $1(n)=1$. (nhan tinh hoan toan)
-   Ham uoc so: $\sigma_{k}(n)=\sum_{d\mid n}d^{k}$. $\sigma_{0}(n)$ thuong duoc viet gon la $d(n)$ hoac $\tau(n)$, $\sigma_{1}(n)$ thuong duoc viet gon la $\sigma(n)$.
-   Ham Euler: $\varphi(n)=\sum_{i=1}^n[(i,n)=1]$.
-   Ham Mobius: $\mu(n)=\begin{cases}1&n=1\\0&\exists d>1,d^{2}\mid n\\(-1)^{\omega(n)}&\text{otherwise}\end{cases}$, trong do $\omega(n)$ la so luong thua so nguyen to phan biet cua $n$.

<span id="&#x52A0;&#x6027;&#x51FD;&#x6570;"></span>
### Ham cong tinh

???+ note "Dinh nghia"
    Trong so hoc, neu ham $f(n)$ thoa man $f(1)=0$ va $f(xy)=f(x)+f(y)$ voi moi cap $x, y \in\mathbf{N}^*$ nguyen to cung nhau, thi $f(n)$ la **ham cong tinh**.
    
    Trong so hoc, neu ham $f(n)$ thoa man $f(1)=0$ va $f(xy)=f(x)+f(y)$ voi moi $x, y \in\mathbf{N}^*$, thi $f(n)$ la **ham cong tinh hoan toan**.

???+ warning "Ham cong tinh"
    Ham cong tinh trong muc nay chi ham cong tinh trong so hoc (Additive function), can phan biet voi Additive map trong dai so.

<span id="&#x6027;&#x8D28;_1"></span>
#### Tinh chat

Voi so nguyen duong $x$, gia su phan tich thua so nguyen to duy nhat cua no la $x=\prod p_i^{k_i}$, trong do $p_i$ la so nguyen to.

Neu $F(x)$ la ham cong tinh, thi $F(x)=\sum F(p_i^{k_i})$.

Neu $F(x)$ la ham cong tinh hoan toan, thi $F(x)=\sum F(p_i^{k_i})=\sum F(p_i)\cdot k_i$.

<span id="&#x4F8B;&#x5B50;_1"></span>
#### Vi du

De thuan tien trinh bay, goi tap hop tat ca cac so nguyen to la $\mathbf P$.

-   So mu cua $p$ trong phan tich thua so nguyen to: $\nu_p(n) = \max\{k\in\mathbf N: p^k\mid n\}$, trong do $p\in\mathbf P$. (cong tinh hoan toan)
-   Tong so thua so nguyen to ke ca boi so: $\Omega(n)=\sum_{p \in\mathbf P} \nu_p(n)$. (cong tinh hoan toan)
-   So thua so nguyen to phan biet: $\omega(n)=\sum_{p \in\mathbf P} [p \mid n]$.
-   Tong cac thua so nguyen to ke ca boi so: $a_0(n)=\sum_{p \in\mathbf P} \nu_p(n)\cdot p$. (cong tinh hoan toan)
-   Tong cac thua so nguyen to phan biet: $a_1(n)=\sum_{p \in\mathbf P} [p \mid n] \cdot p$.

<span id="&#x53D6;&#x6574;&#x51FD;&#x6570;"></span>
## Ham lay phan nguyen

Voi so thuc $x$, dinh nghia **ham san** (floor function) va **ham tran** (ceiling function) lan luot la

$$
\lfloor x\rfloor = \max\{k\in\mathbf Z:k\le x\},~\lceil x\rceil = \min\{k\in\mathbf Z:k\ge x\}.
$$

Dung ham san, mot so thuc co the tach thanh phan nguyen va phan thap phan: $x = \lfloor x\rfloor + \{x\}$. Trong do, $\{x\}$ bieu thi phan thap phan cua $x$.

Ham lay phan nguyen co cac tinh chat co ban sau: ($x\in\mathbf R,~n\in\mathbf Z$)

-   $x\in\mathbf Z \iff x = \lfloor x\rfloor = \lceil x\rceil$.
-   $\lceil x\rceil - \lfloor x\rfloor = [x\notin\mathbf Z]$.
-   $x - 1 < \lfloor x\rfloor \le x \le \lceil x\rceil < x + 1$.
-   $\lfloor -x\rfloor = -\lceil x\rceil,~\lceil -x\rceil = -\lfloor x\rfloor$.
-   $\lfloor x + n\rfloor = \lfloor x\rfloor + n,~\lceil x + n\rceil = \lceil x \rceil + n$.
-   $\lfloor x\rfloor$ va $\lceil x\rceil$ deu la cac ham don dieu khong giam theo $x$.

Khi chung minh cac dang thuc ve ham san (ham tran), thuong dung cac dang tuong duong sau: ($x\in\mathbf R,~n\in\mathbf Z$)

-   $\lfloor x\rfloor = n \iff n \le x < n + 1 \iff x - 1 < n \le x$.
-   $\lceil x\rceil = n \iff n - 1 < x \le n \iff x \le n < x + 1$.

Khi chung minh cac bat dang thuc ve ham san (ham tran), thuong dung cac dang tuong duong sau: ($x\in\mathbf R,~n\in\mathbf Z$)

-   $x < n \iff \lfloor x\rfloor < n$.
-   $n < x \iff n < \lceil x\rceil$.
-   $x \le n \iff \lceil x\rceil \le n$.
-   $n \le x \iff n \le \lfloor x\rfloor$.

Tinh chat lien quan den tong va hieu: ($x,y\in\mathbf R$)

-   $\lfloor x\rfloor + \lfloor y\rfloor \le \lfloor x + y\rfloor \le \lfloor x\rfloor + \lfloor y\rfloor + 1$, va dung dung mot dau bang.
-   $\lceil x\rceil +\lceil y\rceil -1\leq \lceil x+y\rceil \leq \lceil x\rceil +\lceil y\rceil$, va dung dung mot dau bang.
-   $\lfloor|x - y|\rfloor \le |\lfloor x\rfloor - \lfloor y\rfloor| \le \lceil|x - y|\rceil$.
-   $\lfloor|x - y|\rfloor \le |\lceil x\rceil - \lceil y\rceil| \le \lceil|x-y|\rceil$.

Tinh chat lien quan den thuong: ($x\in\mathbf R,~n\in\mathbf Z,~m\in\mathbf Z_+$)

-   $\left\lceil\dfrac{n}{m}\right\rceil = \left\lfloor\dfrac{n+m-1}{m}\right\rfloor,~\left\lfloor\dfrac{n}{m}\right\rfloor = \left\lceil\dfrac{n-m+1}{m}\right\rceil$.
-   $\left\lfloor\dfrac{x + n}{m} \right\rfloor = \left\lfloor\dfrac{\lfloor x\rfloor + n}{m} \right\rfloor,~\left\lceil\dfrac{x + n}{m} \right\rceil = \left\lceil\dfrac{\lceil x\rceil + n}{m} \right\rceil$.
-   $\left\lfloor\dfrac{\lfloor x/n\rfloor}{m}\right\rfloor = \left\lfloor\dfrac{x}{nm}\right\rfloor,~\left\lceil\dfrac{\lceil x/n\rceil}{m}\right\rceil = \left\lceil\dfrac{x}{nm}\right\rceil$.
-   Voi $x > 0$, co $\displaystyle\left\lfloor\dfrac{x}{m}\right\rfloor = \sum_{k=1}^{\lfloor x\rfloor}[m\mid k]$.

Trong do, tinh chat thu hai va thu ba deu co the xem la he qua truc tiep cua ket luan sau:

-   Cho $f$ la ham lien tuc, don dieu tang, va cu moi khi $f(x)\in\mathbf Z$ thi $x\in\mathbf Z$. Khi do

    $$
    \lfloor f(x)\rfloor = \lfloor f(\lfloor x\rfloor)\rfloor,~ \lceil f(x)\rceil = \lceil f(\lceil x\rceil)\rceil.
    $$

    ??? note "Chung minh"
        Do tinh doi xung, chi can chung minh dang thuc thu nhat. Neu $x$ la so nguyen thi menh de hien nhien. Nguoc lai, $\lfloor x\rfloor < x$. Tu tinh don dieu cua $f$ va cua ham san, ta co $\lfloor f(x)\rfloor \ge \lfloor f(\lfloor x\rfloor)\rfloor$. Neu dau bang khong dung, dat $y = \lfloor f(x)\rfloor$; khi do $\lfloor f(\lfloor x\rfloor)\rfloor < y \le \lfloor f(x)\rfloor$, tuong duong voi $f(\lfloor x\rfloor) < y \le f(x)$. Do $f$ lien tuc, ton tai $\lfloor x\rfloor < x_0 \le x$ sao cho $f(x_0)=y$. Vi $y\in\mathbf Z$, suy ra $x_0\in\mathbf Z$, mau thuan voi dinh nghia cua $\lfloor x\rfloor$. Vi vay dau bang dung, tuc la $\lfloor f(x)\rfloor = \lfloor f(\lfloor x\rfloor)\rfloor$.

Cuoi cung la mot nhom ket luan ve cac tong co ham lay phan nguyen: ($x\in\mathbf R,~n\in\mathbf Z,~m\in\mathbf Z_+$)

-   $n = \left\lfloor\dfrac{n}{2}\right\rfloor + \left\lceil\dfrac{n}{2}\right\rceil$.
-   $n = \left\lfloor\dfrac{n}{m} \right\rfloor + \left\lfloor\dfrac{n+1}{m} \right\rfloor + \cdots + \left\lfloor\dfrac{n+m-1}{m} \right\rfloor$.
-   $n = \left\lceil\dfrac{n}{m} \right\rceil + \left\lceil\dfrac{n-1}{m} \right\rceil + \cdots + \left\lceil\dfrac{n-m+1}{m} \right\rceil$.
-   $\lfloor mx\rfloor = \lfloor x\rfloor + \left\lfloor x+\dfrac{1}{m}\right\rfloor + \cdots + \left\lfloor x+\dfrac{m-1}{m}\right\rfloor$.
-   $\lceil mx\rceil = \lceil x\rceil + \left\lceil x - \dfrac{1}{m}\right\rceil + \cdots + \left\lceil x - \dfrac{m-1}{m}\right\rceil$.
-   Khi $m\perp n$, $\displaystyle\sum_{k=1}^{m-1}\left\lfloor\dfrac{kn}{m}\right\rfloor=\dfrac{1}{2}(n-1)(m-1)$.
-   Khi $m\perp n$, $\displaystyle\sum_{k=1}^{m-1}\left\lceil\dfrac{kn}{m}\right\rceil=\dfrac{1}{2}(n+1)(m-1)$.

Cach suy ra cac tong dang nay va cac dang tong tuong tu tong quat hon co the tham khao trang [thuat toan Euclid mo rong dang lop](./euclidean.md).

Co the tham khao them cac tinh chat va ung dung cua ham lay phan nguyen o cac trang sau:

-   Phep modulo: $n\bmod m = n - \left\lfloor\dfrac{n}{m}\right\rfloor m$. No co the dung de [toi uu phep modulo so nguyen](./mod-arithmetic.md#%E7%9B%B8%E5%85%B3%E7%AE%97%E6%B3%95).
-   Dung bo de Gauss de chung minh [luat tuong ho bac hai](./quad-residue.md#%E4%BA%8C%E6%AC%A1%E4%BA%92%E5%8F%8D%E5%BE%8B).
-   [Chia khoi so hoc](./sqrt-decomposition.md), dac biet la phan chung minh tinh chat cua no.
-   Tinh so mu cua thua so nguyen to trong giai thua bang [cong thuc Legendre](./factorial.md#legendre-%E5%85%AC%E5%BC%8F).
-   [Day Beatty](../game-theory/impartial-game.md#wythoff-%E6%B8%B8%E6%88%8F), dinh ly Rayleigh va tro choi Wythoff.

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x6CE8;&#x91CA;"></span>
## Tai lieu tham khao va ghi chu

-   Pan Chengdong, Pan Chengbiao. *So hoc so cap*. Nha xuat ban Dai hoc Bac Kinh.
-   [Floor and ceiling functions - Wikipedia](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions)
-   Graham, Ronald L., Donald E. Knuth, and Oren Patashnik. "Concrete mathematics: a foundation for computer science." (1989).

[^ref1]: [Are all primes (past 2 and 3) of the forms 6n+1 and 6n-1?](https://primes.utm.edu/notes/faq/six.html)

[^gcdcpp]: [std::gcd - cppreference.com](https://en.cppreference.com/w/cpp/numeric/gcd)
