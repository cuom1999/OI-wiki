<span id="&#x5B9A;&#x4E49;"></span>
## Dinh nghia

Uoc chung lon nhat trong tieng Anh la Greatest Common Divisor, thuong viet tat la gcd.

Uoc chung cua mot tap so nguyen la so dong thoi la uoc cua moi so trong tap do. $\pm 1$ la uoc chung cua moi tap so nguyen.

Uoc chung lon nhat cua mot tap so nguyen la so lon nhat trong tat ca cac uoc chung.

Voi hai so nguyen $a,b$ khong dong thoi bang $0$, uoc chung lon nhat cua chung duoc ky hieu la $\gcd(a,b)$; khi khong gay nham lan co the viet gon la $(a,b)$.

Voi cac so nguyen $a_1,\dots,a_n$ khong dong thoi bang $0$, uoc chung lon nhat cua chung duoc ky hieu la $\gcd(a_1,\dots,a_n)$; khi khong gay nham lan co the viet gon la $(a_1,\dots,a_n)$.

Tinh chat cua uoc chung lon nhat va boi chung nho nhat xem tai [co so ly thuyet so](./basic.md#%E6%9C%80%E5%A4%A7%E5%85%AC%E7%BA%A6%E6%95%B0%E4%B8%8E%E6%9C%80%E5%B0%8F%E5%85%AC%E5%80%8D%E6%95%B0).

Vay lam the nao de tim uoc chung lon nhat? Truoc het xet truong hop hai so.

<span id="&#x6B27;&#x51E0;&#x91CC;&#x5F97;&#x7B97;&#x6CD5;"></span>
### Thuat toan Euclid

<span id="&#x8FC7;&#x7A0B;"></span>
#### Qua trinh

Neu biet hai so $a$ va $b$, lam the nao de tim uoc chung lon nhat cua chung?

Gia su $a > b$.

Neu $b$ la uoc cua $a$, thi $b$ chinh la uoc chung lon nhat cua hai so.
Sau day xet truong hop khong chia het, tuc $a = b \times q + r$, trong do $r < b$.

Co the chung minh $\gcd(a,b)=\gcd(b,a \bmod b)$ nhu sau:

???+ note "Chung minh"
    Dat $a=bk+c$, ro rang $c=a \bmod b$. Neu $d \mid a,~d \mid b$ thi $c=a-bk, \frac{c}{d}=\frac{a}{d}-\frac{b}{d}k$.
    
    Tu ve phai suy ra $\frac{c}{d}$ la so nguyen, tuc $d \mid c$. Vi vay moi uoc chung cua $a,b$ cung la uoc chung cua $b,a \bmod b$.
    
    Chieu nguoc lai cung can chung minh:
    
    Neu $d \mid b,~d\mid (a \bmod b)$, tuong tu ta co $\frac{a\bmod b}{d}=\frac{a}{d}-\frac{b}{d}k,~\frac{a\bmod b}{d}+\frac{b}{d}k=\frac{a}{d}$.
    
    Vi ve trai ro rang la so nguyen, $\frac{a}{d}$ cung la so nguyen, tuc $d \mid a$. Vi vay moi uoc chung cua $b,a\bmod b$ cung la uoc chung cua $a,b$.
    
    Hai cap co cung tap uoc chung, nen uoc chung lon nhat cung bang nhau.
    
    Do do $\gcd(a,b)=\gcd(b,a\bmod b)$.

Sau khi co $\gcd(a, b) = \gcd(b, r)$, kich thuoc hai so khong tang len, nen ta thu duoc mot cach de quy de tinh uoc chung lon nhat cua hai so.

<span id="&#x5B9E;&#x73B0;"></span>
#### Cai dat

=== "C++"
    ```cpp
    // Version 1
    int gcd(int a, int b) {
      if (b == 0) return a;
      return gcd(b, a % b);
    }
    
    // Version 2
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    ```

=== "Java"
    ```java
    // Version 1
    public int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    // Version 2
    public int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    ```

=== "Python"
    ```python
    def gcd(a, b):
        if b == 0:
            return a
        return gcd(b, a % b)
    ```

De quy den khi `b == 0` (tuc `a % b == 0` o buoc truoc) thi tra ve gia tri.

Theo cach de quy tren, ta cung co the viet ban lap:

=== "C++"
    ```cpp
    int gcd(int a, int b) {
      while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
      }
      return a;
    }
    ```

=== "Java"
    ```java
    public int gcd(int a, int b) {
        while(b != 0) {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
    }
    ```

=== "Python"
    ```python
    def gcd(a, b):
        while b != 0:
            a, b = b, a % b
        return a
    ```

Cac thuat toan tren deu co the goi la thuat toan Euclid (Euclidean algorithm).

Ngoai ra, voi C++17, ta co the dung [`std::gcd`](https://en.cppreference.com/w/cpp/numeric/gcd) va [`std::lcm`](https://en.cppreference.com/w/cpp/numeric/lcm) trong header [`<numeric>`](https://en.cppreference.com/w/cpp/header/numeric) de tinh uoc chung lon nhat va boi chung nho nhat.

???+ warning "Luu y"
    Trong mot so trinh bien dich, C++14 co the dung ham `std::__gcd(a,b)` de tinh uoc chung lon nhat, nhung ham nay chi la ham phu rieng cua `std::rotate`.[^1] Dung ham nay co the gay cac van de ngoai du kien, nen nhin chung khong khuyen nghi.

Neu hai so $a$ va $b$ thoa man $\gcd(a, b) = 1$, ta noi $a$ va $b$ nguyen to cung nhau.

<span id="&#x6027;&#x8D28;"></span>
#### Tinh chat

Hieu qua thoi gian cua thuat toan Euclid ra sao? Sau day ta chung minh: khi dau vao la hai so nguyen nhi phan co do dai $n$, do phuc tap thoi gian cua thuat toan Euclid la $O(n)$. Noi cach khac, neu mac dinh $a, b$ cung bac, do phuc tap thoi gian la $O(\log\max(a, b))$.

???+ note "Chung minh"
    Khi tinh $\gcd(a,b)$, ta gap hai truong hop:
    
    -   $a < b$, khi do $\gcd(a,b)=\gcd(b,a)$;
    -   $a \geq b$, khi do $\gcd(a,b)=\gcd(b,a \bmod b)$, va phep lay modulo theo $a$ lam $a$ giam it nhat mot nua. Nghia la qua trinh nay xay ra toi da $O(\log a) = O(n)$ lan.
    
    Sau truong hop thu nhat nhat dinh se den truong hop thu hai, nen so lan xay ra truong hop thu nhat chac chan **khong nhieu hon** so lan xay ra truong hop thu hai.
    
    Vi vay chi can de quy toi da $O(n)$ lan la co ket qua.

Thuc te, neu dung thuat toan Euclid de tinh uoc chung lon nhat cua hai so hang xom trong [day Fibonacci](../combinatorics/fibonacci.md), thuat toan se dat do phuc tap xau nhat.

<span id="&#x66F4;&#x76F8;&#x51CF;&#x635F;&#x672F;"></span>
### Thuat toan tru dan

Voi so lon, phep lay modulo co do phuc tap cao, con cong tru thi thap hon. Vi vay co the dung cong tru thay cho nhan chia de tinh uoc chung lon nhat.

<span id="&#x8FC7;&#x7A0B;"></span>
#### Qua trinh

Cho hai so $a$ va $b$, can tinh $\gcd(a,b)$.

Gia su $a \ge b$. Neu $a = b$, thi $\gcd(a,b)=a=b$.
Neu khong, voi moi $\forall d\mid a, d\mid b$, co the chung minh $d\mid a-b$.

Do do **tat ca** uoc chung cua $a$ va $b$ deu la uoc chung cua $a-b$ va $b$, nen $\gcd(a,b) = \gcd(a-b, b)$.

<span id="stein-&#x7B97;&#x6CD5;&#x7684;&#x4F18;&#x5316;"></span>
#### Toi uu hoa bang thuat toan Stein

Neu $a\gg b$, do phuc tap $O(n)$ cua thuat toan tru dan se roi vao truong hop xau nhat.

Xet mot toi uu: neu $2\mid a,2\mid b$, thi $\gcd(a,b) = 2\gcd\left(\dfrac a2, \dfrac b2\right)$.

Neu khong, gia su $2\mid a$ (truong hop $2\mid b$ tuong tu). Vi truong hop $2\mid b$ da duoc xet, nen $2 \nmid b$. Do do $\gcd(a,b)=\gcd\left(\dfrac a2,b\right)$.

Thuat toan sau khi toi uu, tuc thuat toan Stein, co do phuc tap thoi gian $O(\log n)$.

???+ note "Chung minh"
    Neu $2\mid a$ hoac $2\mid b$, moi lan de quy se lam it nhat mot trong hai so $a,b$ giam mot nua.
    
    Neu khong, $2\mid a-b$, quay ve truong hop tren.
    
    Thuat toan de quy toi da $O(\log n)$ lan.

<span id="&#x5B9E;&#x73B0;"></span>
#### Cai dat

Mau so do chinh xac cao xem tai [tinh toan so lon](../bignum.md).

Voi so do chinh xac cao can cai dat: phep tru, so sanh kich thuoc, dich trai, dich phai (co the thay bang nhan chia do chinh xac thap), so bit $0$ lien tiep o cuoi bieu dien nhi phan (co the tinh vét can bang cach kiem tra chan le).

??? note "C++"
    ```cpp
    Big gcd(Big a, Big b) {
      if (a == 0) return b;
      if (b == 0) return a;
      // Ghi so lan thua so chung 2 xuat hien trong a va b;
      // countr_zero la so bit 0 lien tiep o cuoi bieu dien nhi phan
      int atimes = countr_zero(a);
      int btimes = countr_zero(b);
      int mintimes = min(atimes, btimes);
      a >>= atimes;
      for (;;) {
        // Thua so 2 chung cua a va b da duoc tinh; ve sau a khong the chan
        b >>= btimes;
        // Bao dam a <= b
        if (a > b) swap(a, b);
        b -= a;
        if (b == 0) break;
        btimes = countr_zero(b);
      }
      return a << mintimes;
    }
    ```

Doan code tren tham khao cach cai dat C++17 `std::gcd` cua [libstdc++](https://github.com/gcc-mirror/gcc/blob/1667962ae755db27965778b8c8c684c6c0c4da21/libstdc%2B%2B-v3/include/std/numeric#L173) va [MSVC](https://github.com/microsoft/STL/blob/9aca22477df4eed3222b4974746ee79129eb44e7/stl/inc/numeric#L591). Trong pham vi du lieu cua `unsigned int` va `unsigned long long`, neu co the tinh `countr_zero` rat nhanh thi thuat toan Stein nhanh hon thuat toan Euclid; nguoc lai no co the cham hon Euclid.

???+ note "Ve countr_zero"
    1.  gcc co [ham noi tai](../bit.md#gcc-%E5%86%85%E5%BB%BA%E5%87%BD%E6%95%B0) `__builtin_ctz` (32 bit) hoac `__builtin_ctzll` (64 bit), co the thay cho `countr_zero` trong doan code tren;
    2.  Tu C++20, header `<bit>` chua [`std::countr_zero`](https://en.cppreference.com/w/cpp/numeric/countr_zero);
    3.  Neu khong dung ham ngoai thu vien chuan va cung khong dung duoc C++20, doan code sau la mot cach cai dat $O(1)$ sau tien xu ly trong mo hinh Word-RAM with multiplication:
    
    ```cpp
    constexpr int loghash[64] = {0,  32, 48, 56, 60, 62, 63, 31, 47, 55, 59, 61, 30,
                                 15, 39, 51, 57, 28, 46, 23, 43, 53, 58, 29, 14, 7,
                                 35, 49, 24, 44, 54, 27, 45, 22, 11, 37, 50, 25, 12,
                                 38, 19, 41, 52, 26, 13, 6,  3,  33, 16, 40, 20, 42,
                                 21, 10, 5,  34, 17, 8,  36, 18, 9,  4,  2,  1};
    
    int countr_zero(unsigned long long x) {
      return loghash[(x & -x) * 0x9150D32D8EB9EFC0Ui64 >> 58];
    }
    ```
    
    Voi so do chinh xac cao, neu cach cai dat giong `bitset`, ket hop voi cach cai dat `countr_zero` tren se dat do phuc tap $O(n / w)$. Neu khong tien tach theo bit nhi phan, chi co the vét can de xac dinh thua so la luy thua lon nhat cua $2$, va do phuc tap phu thuoc vao cach cai dat. Vi du:
    
    ```cpp
    // Big nhi phan luu theo little-endian, yeu cau co the duyet tung phan tu
    int countr_zero(Big a) {
      int ans = 0;
      for (auto x : a) {
        if (x != 0) {
          ans += 32;  // do dai bit cua kieu du lieu moi phan tu
        } else {
          return ans + countr_zero(x);
        }
      }
      return ans;
    }
    
    // Tinh vét can; neu can dung nen viet truc tiep vao gcd de giam hang so
    int countr_zero(Big a) {
      int ans = 0;
      while ((a & 1) == 0) {
        a >>= 1;
        ++ans;
      }
      return ans;
    }
    ```

Doc them thao luan ve toc do cua cac cach cai dat `gcd` tai [Fastest way to compute the greatest common divisor](https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/).

<span id="&#x591A;&#x4E2A;&#x6570;&#x7684;&#x6700;&#x5927;&#x516C;&#x7EA6;&#x6570;"></span>
### Uoc chung lon nhat cua nhieu so

Vay tinh uoc chung lon nhat cua nhieu so nhu the nao? Ro rang dap an phai la uoc cua tung so, nen cung phai la uoc cua moi cap hai so lien tiep. Dung quy nap co the chung minh: moi lan lay hai so ra tinh dap an roi dua lai vao se khong anh huong den dap an can tim.

<span id="&#x6700;&#x5C0F;&#x516C;&#x500D;&#x6570;"></span>
## Boi chung nho nhat

Tiep theo ta gioi thieu cach tinh boi chung nho nhat (Least Common Multiple, LCM).

<span id="&#x5B9A;&#x4E49;"></span>
### Dinh nghia

Boi chung cua mot tap so nguyen la so dong thoi la boi cua moi so trong tap do. $0$ la boi chung cua moi tap so nguyen.

Boi chung nho nhat cua mot tap so nguyen la so nho nhat trong tat ca cac boi chung duong.

Voi hai so nguyen $a,b$, boi chung nho nhat cua chung duoc ky hieu la $\operatorname{lcm}(a,b)$; khi khong gay nham lan co the viet gon la $[a,b]$.

Voi cac so nguyen $a_1,\dots,a_n$, boi chung nho nhat cua chung duoc ky hieu la $\operatorname{lcm}(a_1,\dots,a_n)$; khi khong gay nham lan co the viet gon la $[a_1,\dots,a_n]$.

<span id="&#x4E24;&#x4E2A;&#x6570;"></span>
### Hai so

Dat $a = p_1^{k_{a_1}}p_2^{k_{a_2}} \cdots p_s^{k_{a_s}}$, $b = p_1^{k_{b_1}}p_2^{k_{b_2}} \cdots p_s^{k_{b_s}}$.

Voi $a$ va $b$, uoc chung lon nhat cua chung bang

$p_1^{\min(k_{a_1}, k_{b_1})}p_2^{\min(k_{a_2}, k_{b_2})} \cdots p_s^{\min(k_{a_s}, k_{b_s})}$

boi chung nho nhat bang

$p_1^{\max(k_{a_1}, k_{b_1})}p_2^{\max(k_{a_2}, k_{b_2})} \cdots p_s^{\max(k_{a_s}, k_{b_s})}$

Vi $k_a + k_b = \max(k_a, k_b) + \min(k_a, k_b)$,

suy ra $\gcd(a, b) \times \operatorname{lcm}(a, b) = a \times b$.

Muon tinh boi chung nho nhat cua hai so, chi can tinh uoc chung lon nhat truoc.

<span id="&#x591A;&#x4E2A;&#x6570;"></span>
### Nhieu so

Khi da tinh duoc $\gcd$ cua hai so, viec tinh boi chung nho nhat la $O(1)$. Vi vay voi nhieu so, thuc ra khong can tinh mot uoc chung lon nhat chung roi xu ly tiep. Cach truc tiep la: sau khi tinh $\gcd$ cua hai so, thay vi dua uoc chung lon nhat do vao day de tiep tuc tinh voi cac so sau, ta chuyen sang dua boi chung nho nhat vao day.

<span id="&#x6269;&#x5C55;&#x6B27;&#x51E0;&#x91CC;&#x5F97;&#x7B97;&#x6CD5;"></span>
## Thuat toan Euclid mo rong

Thuat toan Euclid mo rong (Extended Euclidean algorithm, EXGCD) thuong dung de tim mot nghiem kha thi cua $ax+by=\gcd(a,b)$.

<span id="&#x8FC7;&#x7A0B;"></span>
### Qua trinh

Dat

$ax_1+by_1=\gcd(a,b)$

$bx_2+(a\bmod b)y_2=\gcd(b,a\bmod b)$

Theo dinh ly Euclid: $\gcd(a,b)=\gcd(b,a\bmod b)$.

Do do $ax_1+by_1=bx_2+(a\bmod b)y_2$.

Lai vi $a\bmod b=a-(\lfloor\frac{a}{b}\rfloor\times b)$,

nen $ax_1+by_1=bx_2+(a-(\lfloor\frac{a}{b}\rfloor\times b))y_2$.

$ax_1+by_1=ay_2+bx_2-\lfloor\frac{a}{b}\rfloor\times by_2=ay_2+b(x_2-\lfloor\frac{a}{b}\rfloor y_2)$

Vi $a=a,b=b$, suy ra $x_1=y_2,y_1=x_2-\lfloor\frac{a}{b}\rfloor y_2$.

Lien tuc thay $x_2,y_2$ vao de quy cho den khi $b$ bang $0$, roi tra nguoc voi $x=1,y=0$ de tinh nghiem.

<span id="&#x5B9E;&#x73B0;"></span>
### Cai dat

=== "C++"
    ```cpp
    int Exgcd(int a, int b, int &x, int &y) {
      if (!b) {
        x = 1;
        y = 0;
        return a;
      }
      int d = Exgcd(b, a % b, x, y);
      int t = x;
      x = y;
      y = t - (a / b) * y;
      return d;
    }
    ```

=== "Python"
    ```python
    def Exgcd(a, b):
        if b == 0:
            return a, 1, 0
        d, x, y = Exgcd(b, a % b)
        return d, y, x - (a // b) * y
    ```

Ham tra ve gia tri $\gcd$; trong qua trinh do ta tinh duoc $x,y$.

<span id="&#x503C;&#x57DF;&#x5206;&#x6790;"></span>
### Phan tich mien gia tri

Phuong trinh $ax+by=\gcd(a,b)$ co vo so nghiem, va ro rang mot so nghiem co the lam tran `long long`.
May man la neu $b\not= 0$, nghiem kha thi do thuat toan Euclid mo rong tim duoc luon co $|x|\le b,|y|\le a$.
Sau day la chung minh cua tinh chat nay.

??? note "Chung minh"
    -   Khi $\gcd(a,b)=b$, ta co $a\bmod b=0$, nen de quy se dung o tang tiep theo.
        Thu duoc $x_1=0,y_1=1$, ro rang $a,b\ge 1\ge |x_1|,|y_1|$.
    -   Khi $\gcd(a,b)\not= b$, gia su $|x_2|\le (a\bmod b),|y_2|\le b$.
        Vi $x_1=y_2,y_1=x_2-{\left\lfloor\dfrac{a}{b}\right\rfloor}y_2$,
        nen $|x_1|=|y_2|\le b,|y_1|\le|x_2|+|{\left\lfloor\dfrac{a}{b}\right\rfloor}y_2|\le (a\bmod b)+{\left\lfloor\dfrac{a}{b}\right\rfloor}|y_2|$
        $\le a-{\left\lfloor\dfrac{a}{b}\right\rfloor}b+{\left\lfloor\dfrac{a}{b}\right\rfloor}|y_2|\le a-{\left\lfloor\dfrac{a}{b}\right\rfloor}(b-|y_2|)$
        $a\bmod b=a-{\left\lfloor\dfrac{a}{b}\right\rfloor}b\le a-{\left\lfloor\dfrac{a}{b}\right\rfloor}(b-|y_2|)\le a$
        Do do $|x_1|\le b,|y_1|\le a$ dung.

<span id="&#x8FED;&#x4EE3;&#x6CD5;&#x7F16;&#x5199;&#x6269;&#x5C55;&#x6B27;&#x51E0;&#x91CC;&#x5F97;&#x7B97;&#x6CD5;"></span>
### Viet thuat toan Euclid mo rong bang phuong phap lap

Ban dau, khi $x = 1$, $y = 0$, $x_1 = 0$, $y_1 = 1$, ro rang co:

$$
\begin{cases}
    ax + by     & = a \\
    ax_1 + by_1 & = b
\end{cases}
$$

dung.

Biet $a\bmod b = a - (\lfloor \frac{a}{b} \rfloor \times b)$, dat $q = \lfloor \frac{a}{b} \rfloor$. Tham khao cach lap tinh gcd, moi vong lap co the bieu dien la:

$$
(a, b) \rightarrow (b, a - qb)
$$

Thay $a$ trong qua trinh lap bang $ax + by = a$, thay $b$ bang $ax_1 + by_1 = b$, ta duoc:

$$
\begin{aligned}
                & \begin{cases}
                      ax + by     & = a \\
                      ax_1 + by_1 & = b
                  \end{cases}                    \\
    \rightarrow & \begin{cases}
                      ax_1 + by_1               & = b      \\
                      a(x - qx_1) + b(y - qy_1) & = a - qb
                  \end{cases}
\end{aligned}
$$

Tu do co the tinh exgcd bang phuong phap lap.

Vi cach lap tranh de quy, code se nhanh hon ban de quy mot chut.

```cpp
int gcd(int a, int b, int& x, int& y) {
  x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
```

Neu quan sat ky $a_1$ va $b_1$, ta se thay chung co gia tri hoan toan giong trong ban lap cua thuat toan Euclid, va cac cong thuc sau luon dung tai moi thoi diem (truoc vong `while` va sau moi lan lap): $x \cdot a +y \cdot b =a_1$ va $x_1 \cdot a +y_1 \cdot b= b_1$. Vi vay, thuat toan chac chan tinh dung $\gcd$.

Cuoi cung $a_1$ chinh la $\gcd$ can tim, va co $x \cdot a +y \cdot b = g$.

<span id="&#x77E9;&#x9635;&#x7684;&#x89E3;&#x91CA;"></span>
#### Giai thich bang ma tran

Voi hai so nguyen duong $a$ va $b$, mot buoc thuat toan Euclid $\gcd(a,b)=\gcd(b,a\bmod b)$ co the bieu dien bang ma tran:

$$
\begin{bmatrix}
b\\a\bmod b
\end{bmatrix}
=
\begin{bmatrix}
0&1\\1&-\lfloor a/b\rfloor
\end{bmatrix}
\begin{bmatrix}
a\\b
\end{bmatrix}
$$

Trong do ky hieu lam tron xuong $\lfloor c\rfloor$ la so nguyen lon nhat khong vuot qua $c$. Ta dinh nghia bien doi $\begin{bmatrix}a\\b\end{bmatrix}\mapsto \begin{bmatrix}0&1\\1&-\lfloor a/b\rfloor\end{bmatrix}\begin{bmatrix}a\\b\end{bmatrix}$.

De thay thuat toan Euclid chinh la viec lien tuc ap dung bien doi nay, nen co

$$
\begin{bmatrix}
\gcd(a,b)\\0
\end{bmatrix}
=
\left(
\cdots 
\begin{bmatrix}
0&1\\1&-\lfloor a/b\rfloor
\end{bmatrix}
\begin{bmatrix}
1&0\\0&1
\end{bmatrix}
\right)
\begin{bmatrix}
a\\b
\end{bmatrix}
$$

Dat

$$
\begin{bmatrix}
x_1&x_2\\x_3&x_4
\end{bmatrix}
=
\cdots 
\begin{bmatrix}
0&1\\1&-\lfloor a/b\rfloor
\end{bmatrix}
\begin{bmatrix}
1&0\\0&1
\end{bmatrix}
$$

Khi do

$$
\begin{bmatrix}
\gcd(a,b)\\0
\end{bmatrix}
=
\begin{bmatrix}
x_1&x_2\\x_3&x_4
\end{bmatrix}
\begin{bmatrix}
a\\b
\end{bmatrix}
$$

Thoa man $a\cdot x_1+b\cdot x_2=\gcd(a,b)$, tuc thuat toan Euclid mo rong. Luu y viec nhan them mot ma tran don vi o cuoi khong anh huong den ket qua; dieu nay goi y ta co the bat dau bang cach duy tri mot ma tran don vi $2\times 2$ de viet phuong phap lap gon hon:

```cpp
int exgcd(int a, int b, int &x, int &y) {
  int x1 = 1, x2 = 0, x3 = 0, x4 = 1;
  while (b != 0) {
    int c = a / b;
    std::tie(x1, x2, x3, x4, a, b) =
        std::make_tuple(x3, x4, x1 - x3 * c, x2 - x4 * c, b, a - b * c);
  }
  x = x1, y = x2;
  return a;
}
```

Cach dien giai nay don gian hon so voi de quy.

<span id="&#x5E94;&#x7528;"></span>
## Ung dung

-   [10104 - Euclid Problem](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045)
-   [GYM - (J) once upon a time](http://codeforces.com/gym/100963)
-   [UVa - 12775 - Gift Dilemma](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4628)

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x94FE;&#x63A5;"></span>
## Tai lieu tham khao va lien ket

[^1]: [libstdc++: std Namespace Reference](https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.4/a00978.html#a2686a128df5a576cb53a1ed5f674607)
