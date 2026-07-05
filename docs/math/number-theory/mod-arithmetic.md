author: 383494, buuzzing, c-forrest, cr4c1an, Emp7iness, Enter-tainer, Great-designer, HeRaNO, jifbt, Kaiser-Yang, Koishilll, ksyx, Marcythm, Qiu-Quanzhi, Saisyc, sshwy, StarryReverie, StudyingFather, Tiphereth-A, Xeonacid, xyf007

Trong lập trình thi đấu, một phần quan trọng của số học là **số học modulo**
(modular arithmetic), tức là thực hiện các phép toán trên số nguyên dưới một
modulo nào đó. Ngoài bốn phép toán cơ bản và phép lũy thừa, ta còn có thể
thuận tiện tính logarit rời rạc, khai căn bậc bất kỳ, tính giai thừa, tổ hợp
và nhiều phép toán khác.

Số học modulo xuất hiện trong nhiều loại bài toán, không chỉ trong phần số học.
Đáp án thật sự của nhiều bài toán có thể rất lớn, vượt quá miền lưu trữ của các
kiểu số nguyên thông dụng. Khi đó, để tránh dùng số nguyên lớn và in ra chuỗi
chữ số dài, đề bài thường yêu cầu in đáp án sau khi lấy modulo. Vì vậy cần nắm
vững các kỹ thuật số học modulo.

<span id="c/c++-&#x7684;&#x6574;&#x6570;&#x9664;&#x6CD5;&#x548C;&#x53D6;&#x6A21;&#x8FD0;&#x7B97;"></span>
## Phép chia nguyên và phép modulo trong C/C++

Trong C/C++, phép chia nguyên và phép modulo không trùng với phép modulo và
phép chia quen dùng trong toán học.

Trong mọi phiên bản tiêu chuẩn C/C++, phép chia nguyên được quy định như sau:

1.  Nếu số chia bằng 0, hành vi là không xác định;
2.  Nếu không, kết quả của `(a / b) * b + a % b` bằng `a`.

Nói cách khác, dấu của kết quả modulo phụ thuộc vào cách làm tròn thương; còn
cách làm tròn thương từng là hành vi do cài đặt quyết định (do trình biên dịch
quyết định).

Từ tiêu chuẩn [C99](https://en.cppreference.com/w/c/language/operator_arithmetic)
và [C++11](https://en.cppreference.com/w/cpp/language/operator_arithmetic) trở
đi, **thương được làm tròn về 0** (bỏ phần thập phân); vì vậy dấu của phép
modulo trùng với dấu của số bị chia. Từ đó, các khẳng định sau luôn đúng:

```c
assert(5 % 3 == 2);
assert(5 % -3 == 2);
assert(-5 % 3 == -2);
assert(-5 % -3 == -2);
```

<span id="&#x6A21;&#x6574;&#x6570;&#x7C7B;"></span>
## Lớp số nguyên modulo

Số học modulo có thể xem là việc thực hiện các phép toán trên [lớp đồng
dư](./basic.md#lớp-đồng-dư-và-hệ-thặng-dư)
theo một modulo. Nếu dùng một struct để biểu diễn một lớp đồng dư, rồi đóng
gói phép cộng, trừ, nhân giữa các lớp đồng dư thành phương thức của struct hoặc
toán tử nạp chồng, số học modulo có thể được cài đặt tự nhiên thành một lớp số
nguyên modulo. Ví dụ đơn giản sau hỗ trợ cộng, trừ, nhân và lũy thừa nhanh trên
số nguyên có dấu $32$ bit với modulo $M < 2^{30}$:

???+ example "Một lớp số nguyên modulo đơn giản"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/mod-arithmetic.cpp:core"
    ```

Cách cài đặt này cố ý giảm số lần thực hiện modulo, vì phép modulo thường tốn
thời gian hơn phép cộng, trừ, nhân hoặc so sánh thông thường. Trong chú thích
mã nguồn có đưa ra cách cài đặt tương đương và trực tiếp hơn. Ý tưởng chính của
các tối ưu đơn giản này là: khi cộng trừ hai số nguyên trong $[0,M)$, kết quả
chắc chắn nằm trong khoảng $(-M,2M)$, nên có thể đưa về lại $[0,M)$ bằng một
lần cộng hoặc trừ. Phép lũy thừa trong cài đặt này dùng kỹ thuật [lũy thừa
nhanh](../binary-exponentiation.md#lũy-thừa-theo-mô-đun).

Ngoài các phép toán cơ bản này, ta còn có thể thực hiện các phép sau dưới nhiều
modulo:

-   [Nghịch đảo](./inverse.md)
-   [Phép chia](./linear-equation.md)
-   [Giai thừa](./factorial.md)
-   [Tổ hợp](./lucas.md)
-   [Khai căn bậc hai](./quad-residue.md#%E6%A8%A1%E6%84%8F%E4%B9%89%E4%B8%8B%E5%BC%80%E5%B9%B3%E6%96%B9)
-   [Logarit rời rạc](./discrete-logarithm.md)
-   [Khai căn](./residue.md#%E6%A8%A1%E6%84%8F%E4%B9%89%E4%B8%8B%E5%BC%80%E6%96%B9)

Các phép toán này thường dễ hơn khi modulo là số nguyên tố. Với modulo hợp số,
thường cần dùng các phiên bản mở rộng của thuật toán tương ứng và [định lý phần
dư Trung Hoa](./crt.md). Phần lớn các phép toán dưới modulo có thể xem là bài
toán giải một loại phương trình đồng dư. Về phương pháp chung để giải phương
trình đồng dư, có thể tham khảo trang [Phương trình đồng dư](./congruence-equation.md).

<span id="&#x76F8;&#x5173;&#x7B97;&#x6CD5;"></span>
## Thuật toán liên quan

Mục này giới thiệu một vài phương pháp tối ưu phép modulo, phép nhân và lũy
thừa nhanh dưới modulo. Với đại đa số bài toán, cách cài đặt đơn giản ở trên
đã đủ nhanh. Tuy nhiên, khi bài toán yêu cầu chặt về hằng số thời gian, các tối
ưu này có thể phát huy tác dụng bằng cách giảm tính toán và thao tác modulo
không cần thiết.

<span id="&#x5FEB;&#x901F;&#x4E58;"></span>
### Nhân nhanh

Trong kiểm tra tính nguyên tố và phân tích thừa số, ta thường gặp phép nhân lấy
modulo với modulo nằm trong phạm vi `long long`. Để tránh tràn số nguyên trong
quá trình tính, mục này giới thiệu một cách "nhân nhanh" xử lý được modulo
trong phạm vi `long long`, không cần dùng `__int128`, và có độ phức tạp
$O(1)$. Thuật toán yêu cầu trên hệ thống chấm, `long double` ít nhất phải được
biểu diễn bằng số dấu phẩy động mở rộng $80$ bit[^long-double-80bit].

Giả sử $0 \le a, b < m$, cần tính $ab\bmod m$. Lưu ý:

$$
ab\bmod m=ab-\left\lfloor \dfrac{ab}m \right\rfloor m.
$$

Dùng tràn tự nhiên của `unsigned long long`:

$$
ab\bmod m=ab-\left\lfloor \dfrac{ab}m \right\rfloor m=\left(ab-\left\lfloor \dfrac{ab}m \right\rfloor m\right)\bmod 2^{64}.
$$

Chỉ cần tính được thương $\left\lfloor\dfrac{ab}m\right\rfloor$, các phép nhân
và trừ trong biểu thức bên phải đều có thể tính trực tiếp bằng
`unsigned long long`.

Bây giờ chỉ còn cần xét cách tính $\left\lfloor\dfrac {ab}m\right\rfloor$.
Cách làm là dùng `long double` để tính $\dfrac am$ trước rồi nhân với $b$. Đã
dùng `long double` thì chắc chắn có sai số do độ chính xác. Giả sử
`long double` được biểu diễn bằng số dấu phẩy động mở rộng $80$ bit (gồm $1$
bit dấu, $15$ bit mũ và $64$ bit trị), thì số chữ số có nghĩa tối đa mà
`long double` có thể biểu diễn chính xác là $64$[^floating-format]. Vì vậy
$\dfrac am$ trong trường hợp xấu nhất bắt đầu sai từ bit thứ $65$, với miền sai
số[^ld-mul-err] là $\left(-2^{-64},2^{-64}\right)$. Nhân với $b$, một số nguyên
có dấu $64$ bit, miền sai số thành $(-0.5,0.5)$. Để đơn giản hóa phần thảo luận
sau, ta cộng thêm $0.5$ rồi lấy phần nguyên; miền sai số cuối cùng là
$\{0,1\}$.

Cuối cùng, khi thay vào công thức trên cần nhân với $-m$, nên miền sai số cuối
cùng là $\{0,-m\}$. Vì $m$ nằm trong phạm vi `long long`, khi kết quả
$r\in[0,m)$ thì trả về trực tiếp $r$, nếu không thì trả về $r+m$.

Cài đặt như sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/i64-mul.cpp:ld-mul"
    ```

Hiện nay, hầu hết trình biên dịch C/C++ trên các hệ thống chấm đều hỗ trợ kiểu
`__int128`[^int128], vì vậy cũng có thể nâng kiểu của thừa số lên `__int128`
rồi lấy modulo trực tiếp:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/i64-mul.cpp:i128-mul"
    ```

Tất nhiên, phép modulo trên `__int128` cũng không rẻ. Nếu cần tối ưu hằng số
hơn nữa, có thể xét các phương pháp trong hai mục tiếp theo.

<span id="barrett-&#x7EA6;&#x51CF;"></span>
### Rút gọn Barrett

Như đã nói ở trên, phép chia và modulo thường tốn thời gian hơn các phép toán số
học khác. Để giảm chi phí modulo, có một số thuật toán cho kết quả tương tự mà
không trực tiếp thực hiện modulo. Barrett reduction, hay phép rút gọn Barrett,
là một trong số đó.

Cho $m$ là modulo cố định, giả sử cần tính $a\bmod m$ nhiều lần với các giá trị
$a > 0$ khác nhau. Theo phép chia có dư,

$$
z = a\bmod m = a - \left\lfloor\dfrac{a}{m}\right\rfloor m.
$$

Điểm then chốt nằm ở việc tính thương $\left\lfloor\dfrac{a}{m}\right\rfloor$.
Đặt $R$ là một hằng số nào đó, ta có[^floor-barrett]

$$
\left\lfloor\dfrac{a}{m}\right\rfloor = \left\lfloor a\dfrac{R}{m} / R\right\rfloor \approx \left\lfloor a\left\lfloor\dfrac{R}{m}\right\rfloor/R\right\rfloor.
$$

Nếu chọn $R = 2^k$, thì $\left\lfloor\dfrac{R}{m}\right\rfloor$ trong vế phải
có thể tiền xử lý, và phép chia cho $R$ có thể thực hiện bằng dịch bit. Do đó,
tính thương bằng vế phải chỉ cần một phép nhân và một phép dịch. Thay vào biểu
thức của $a\bmod m$, ta thu được ước lượng $z'$ của số dư cần tìm.

Phân tích sai số của cách làm này.
[Hàm lấy phần nguyên](./basic.md#hàm-lấy-phần-nguyên) có tính
chất: với $x > y > 0$, luôn có
$\lfloor x\rfloor - \lfloor y\rfloor \le \lceil x - y\rceil$. Vì vậy sai số

$$
\begin{aligned}
\Delta &= |z' - z| = m\left|\left\lfloor\dfrac{a}{m}\right\rfloor - \left\lfloor a\left\lfloor\dfrac{R}{m}\right\rfloor/R\right\rfloor\right|\\
&\le m\left\lceil a\left(\dfrac{R}{m} - \left\lfloor\dfrac{R}{m}\right\rfloor\right) /R\right\rceil \le m\left\lceil\dfrac{a}{R}\right\rceil.
\end{aligned}
$$

Chỉ cần $a \le R$, sai số $\Delta$ không vượt quá $m$. Do $z' \ge z$, giá trị
ước lượng $z'$ chỉ có thể là $z$ hoặc $z + m$. Sau khi có ước lượng, nếu
$z' \ge m$ thì trừ đi phần $m$ thừa là đủ để bảo đảm đáp án đúng.

Trong quá trình tính Barrett reduction, chỉ cần hai phép nhân, một phép dịch bit
và tối đa hai phép trừ để hoàn thành modulo số nguyên. Tuy nhiên, hiệu năng tăng
không miễn phí: các biến trung gian trong Barrett reduction thường dài hơn biến
đầu vào. Dễ thấy biến trung gian dài nhất trong Barrett reduction là
$a\left\lfloor\dfrac{R}{m}\right\rfloor$. Đặt $\ell(x)$ là độ dài biểu diễn nhị
phân của số nguyên $x$. Khi đó

$$
\ell\left(a\left\lfloor\dfrac{R}{m}\right\rfloor\right) \approx \ell(a) + \ell(R) - \ell(m).
$$

Vì cách chọn $R$ cần thỏa mãn $a < R$, độ dài này ít nhất là
$2\ell(a) - \ell(m)$. Nhưng khi cần modulo, thường có $\ell(m)\le\ell(a)$, nên
độ dài biến trung gian này có thể lớn hơn độ dài đầu vào $\ell(a)$. Ví dụ, nếu
cần lấy modulo một số nguyên $64$ bit theo một số nguyên $32$ bit, thực tế cần
biến trung gian $64 \times 2 - 32 = 96$ bit.

Một ứng dụng của Barrett reduction là tính số dư của tích $ab\bmod m$. Nếu một
thừa số cố định, chẳng hạn $b$ cố định, có thể ước lượng tương tự bằng

$$
ab\bmod m = ab - \left\lfloor a\left\lfloor\dfrac{bR}{m}\right\rfloor/R\right\rfloor m
$$

chỉ cần tiền xử lý giá trị $\left\lfloor\dfrac{bR}{m}\right\rfloor$. Trường hợp
$b$ cố định này đôi khi được gọi là phép nhân modulo Shoup[^shoup].

Trường hợp phổ biến hơn là cả $a,b$ đều không cố định. Khi đó cần tính giá trị
$ab$ trước, rồi dùng Barrett reduction để thu được $ab\bmod m$. Ví dụ, khi cài
đặt phép nhân modulo, cần tính $ab\bmod m$ với $0 \le a,b < m$. Lúc này $R$
được chọn cần thỏa mãn $ab < R$. Theo phân tích trên, biến trung gian dài nhất
trong quá trình tính có độ dài $2\ell(ab)-\ell(m)$. Khi
$\ell(a)\approx\ell(b)\approx\ell(m)$, độ dài này là $3\ell(m)$. Nói cách khác,
nếu dùng Barrett reduction để cài đặt phép nhân modulo cho số nguyên $32$ bit,
biến trung gian cần số nguyên $96$ bit. Đây cũng là một hạn chế của Barrett
reduction khi áp dụng trong lập trình thi đấu.

Làm ví dụ, cài đặt tham khảo cho phép nhân modulo số nguyên có dấu $32$ bit bằng
Barrett reduction như sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/i32-mul.cpp:barrett"
    ```

Cài đặt này cần dùng số nguyên $128$ bit[^int128].

<span id="montgomery-&#x6A21;&#x4E58;"></span>
### Phép nhân modulo Montgomery

Thuật toán nhân modulo Montgomery có chức năng rất giống thuật toán Barrett: nó
cũng giảm chi phí modulo trong quá trình tính số nguyên modulo. Khác với hai
thuật toán trước đều dựa trên xấp xỉ thương, phép nhân modulo Montgomery ánh xạ
mỗi số nguyên vào không gian Montgomery, trong đó các phép toán tương đối dễ
thực hiện, từ đó giảm chi phí tính toán tổng thể.

Cho modulo $m$ là số lẻ, và chọn $R = 2^k > m$. Khi đó dạng Montgomery của lớp
đồng dư $a \bmod m$ là

$$
aR\bmod m.
$$

Vì $R\perp m$, có một song ánh giữa lớp đồng dư $a \bmod m$ và dạng Montgomery
của nó $aR\bmod m$. Do đó, có thể chuyển số nguyên sang dạng Montgomery, thực
hiện một số phép toán modulo $m$, rồi chuyển dạng Montgomery thu được về số
nguyên; kết quả luôn đúng.

Dạng Montgomery cho phép thực hiện thuận tiện nhiều phép toán số nguyên modulo.
Như đã nói, để so sánh hai lớp đồng dư có giống nhau hay không, chỉ cần so sánh
dạng Montgomery của chúng. Lại có

$$
(a+b)R\bmod m = ((aR\bmod m)\pm(bR\bmod m)) \bmod{m},
$$

nên phép cộng, trừ trên lớp đồng dư tương ứng với phép cộng, trừ trên dạng
Montgomery của chúng. Tuy nhiên, để tính phép nhân lớp đồng dư, không thể trực
tiếp nhân hai dạng Montgomery. Vì

$$
(ab)R\bmod m =  ((aR\bmod m)(bR\bmod m)R^{-1}) \bmod{m},
$$

nên khi tính tích của hai dạng Montgomery, cần thực hiện **phép rút gọn
Montgomery** (Montgomery reduction) sau trên tích $x$ của chúng:

$$
\operatorname{REDC}: x \mapsto xR^{-1}\bmod m.
$$

Dùng thao tác này, dạng Montgomery của tích $ab$ là
$\operatorname{REDC}((aR\bmod m)(bR\bmod m))$. Phép rút gọn Montgomery là thao
tác cốt lõi của phép nhân modulo Montgomery:

-   Chuyển $a$ sang dạng Montgomery của nó là
    $\operatorname{REDC}((a\bmod m)(R^2\bmod m))$.
-   Chuyển dạng Montgomery của $a$ về $a\bmod m$ là
    $\operatorname{REDC}(aR\bmod m)$.
-   Dạng Montgomery ứng với nghịch đảo modulo $a^{-1}\bmod m$ là
    $\operatorname{REDC}((aR\bmod m)^{-1}(R^3\bmod m))$.

Bây giờ xét cách cài đặt phép rút gọn Montgomery $\operatorname{REDC}$. Khi tính
$\operatorname{REDC}(x)$, luôn giả sử $0 \le x < m^2$, điều này đúng với các
trường hợp trên. Vì $R\perp m$, theo [định lý Bezout](./bezouts.md), tồn tại
các số nguyên $R^{-1},m'$ sao cho

$$
RR^{-1} + mm' = 1.
$$

Do đó, đặt $q=\lfloor xm' / R\rfloor$, ta có

$$
\begin{aligned}
xR^{-1} &= x\dfrac{1 - mm'}{R} \equiv \dfrac{x-xmm' + qmR}{R} = \dfrac{x - m(xm'\bmod R)}{R} \pmod{m}.
\end{aligned}
$$

Vì $0 \le x < m^2 < mR$ và $0 \le xm'\bmod R < R$, nên

$$
-m < \dfrac{x - m(xm'\bmod R)}{R} < m.
$$

Nói cách khác, thương này và $xR^{-1}\bmod m$ chênh nhau nhiều nhất một $m$.
Chỉ cần nếu thương âm thì cộng thêm $m$ là thu được $\operatorname{REDC}(x)$.
Tính thương này chỉ cần hai phép nhân số nguyên, một phép trừ số nguyên và hai
thao tác bit (lần lượt là lấy modulo theo $R=2^k$ và thực hiện phép chia). Vì
vậy, phép rút gọn Montgomery có thể thực hiện hiệu quả.

Để thực hiện phép nhân modulo Montgomery, cần tiền xử lý một loạt hằng số. Trước
hết, phép rút gọn Montgomery cần $m' = m^{-1}\bmod R$, có thể tính bằng phương
pháp Newton-Hensel giới thiệu [bên dưới](#%E6%A8%A1-2-%E7%9A%84%E5%B9%82%E6%AC%A1%E7%9A%84%E6%95%B4%E6%95%B0%E7%B1%BB).
Tiếp theo, khi quy các thao tác khác về phép rút gọn Montgomery, còn cần các
hằng số như $R^2\bmod m$. Để tính nó, trước hết tính $R\bmod m$, cộng nó với
chính nó để được $2R\bmod m$. Sau đó xem nó là dạng Montgomery của $2$, tính lũy
thừa nhanh trực tiếp, sẽ thu được $2^kR\bmod m = R^2\bmod m$.

Làm ví dụ, cài đặt phép nhân modulo Montgomery cho số nguyên có dấu $32$ bit như
sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/i32-mul.cpp:montgomery"
    ```

So với việc dùng Barrett reduction để cài đặt phép nhân modulo, phép nhân modulo
Montgomery gồm nhiều bước như chuyển đổi, nhân trong dạng Montgomery và chuyển
ngược. Vì vậy, chỉ khi số phép toán modulo giữa chuyển đổi và chuyển ngược đủ
nhiều, chi phí chuyển đổi mới được khấu hao và hiệu năng tổng thể mới cao. Tuy
nhiên, do quá trình cài đặt phép nhân modulo Montgomery chỉ cần biến trung gian
có độ dài $2\ell(m)$, nó linh hoạt hơn. Ví dụ, phép nhân modulo cho số nguyên
$32$ bit chỉ cần biến trung gian $64$ bit. Do đó, nếu cần cài đặt một lớp số
nguyên modulo để thực hiện nhiều tính toán số học, phép nhân modulo Montgomery
phù hợp hơn.

<span id="&#x6A21;-2-&#x7684;&#x5E42;&#x6B21;&#x7684;&#x6574;&#x6570;&#x7C7B;"></span>
### Lớp số nguyên modulo lũy thừa của 2

Mục này thảo luận cách cài đặt lớp số nguyên modulo khi modulo là lũy thừa của
$2$. Trong trường hợp đặc biệt này, phép chia và modulo có thể thực hiện bằng
thao tác bit, nên rất hiệu quả. Barrett reduction và phép nhân modulo Montgomery
đều tận dụng đặc tính này khi dùng $2^e$ làm số chia và modulo để tăng tốc. Đặc
biệt, khi modulo đúng bằng các số đặc biệt như $2^{32}$ và $2^{64}$, có thể
dùng số nguyên không dấu có độ dài bit tương ứng kết hợp với tràn tự nhiên để
cài đặt lớp số nguyên modulo, không cần phép modulo tường minh nào. Ngay cả khi
modulo không đúng bằng như vậy, cũng có thể chuyển về các modulo đặc biệt này.
Ví dụ với modulo $2^{58}$, có thể hoàn thành tính toán trung gian dưới modulo
$2^{64}$, rồi cuối cùng lấy kết quả modulo $2^{58}$. Ngoài modulo để tính, lớp
số nguyên modulo $2^e$ còn có nhiều cách cài đặt đặc biệt cho các thao tác khác.
Mục này tập trung giới thiệu cách cài đặt nghịch đảo và lũy thừa.

Trước hết là phép lấy nghịch đảo: cho số lẻ $a$ và modulo $m=2^e~(e > 2)$, cần
tính $a^{-1}\bmod m$. Các cách lấy nghịch đảo thường gặp gồm thuật toán Euclid
mở rộng và lũy thừa nhanh. Quá trình Euclid mở rộng liên quan đến phép modulo
theo modulo tổng quát; lũy thừa nhanh thông thường cần tính
$a^{\varphi(m)-1}\bmod{m}$, cần $\Theta(e)$ phép nhân số nguyên. Phương pháp
hiệu quả hơn là [Newton-Hensel](../poly/newton.md). Cụ thể, xét kết luận
sau:[^newton-hensel]

$$
mx \equiv 1 \pmod{2^e} \implies mx(2 - mx) \equiv 1\pmod{2^{2e}}.
$$

Theo biểu thức này, chỉ cần bắt đầu từ $x = 1$ và lặp lại
$x \gets x(2-mx)$, sau $\lceil\log_2 e\rceil$ lần lặp sẽ thu được
$m^{-1}\bmod R$.

Làm ví dụ, cài đặt tham khảo cho phép lấy nghịch đảo modulo $2^{32}$ như sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/mod-32-inv-pow.cpp:inv"
    ```

Tiếp theo, xét phép lũy thừa: cho $x,a,b$ và modulo $m=2^e~(e > 2)$, cần tính
$xa^b\bmod m$, trong đó $a$ là số lẻ. Theo
[phân tích](./primitive-root.md#mod-pow-2) cấu trúc nhân của các số nguyên
modulo $2^e$, $a$ luôn có thể viết dưới dạng $\pm g^{\ell}$[^mod-2-g], và dấu
trừ xuất hiện khi và chỉ khi $a\equiv 3\pmod 4$. Trong trường hợp này, có thể
thay $a$ bằng $-a$, rồi nhân kết quả cuối cùng với $(-1)^b$. Vì vậy, tiếp theo
có thể giả sử $a\equiv 1\pmod 4$. Ý tưởng cốt lõi của thuật toán là viết $a$
thành $g^{L(a)}\bmod m$, rồi dùng $xg^{bL(a)}\bmod m$ để tính lũy thừa cần tìm.

Việc tính $L(a)$ chính là tính logarit rời rạc $\operatorname{ind}_ga$. Lưu ý
rằng nếu $a\equiv 1\pmod 4$, thì $a$ luôn có thể viết dưới dạng

$$
a \equiv (2^{e_1}+1)(2^{e_2}+1)\cdots(2^{e_s}+1) \pmod{m},
$$

trong đó $1 < e_1 < e_2 < \cdots < e_s < e$. Lý do là khi khai triển trực tiếp
tích này, bit bằng $1$ thấp thứ hai trong biểu diễn nhị phân của $a$ chính là
bit thứ $e_1$ (chỉ số bắt đầu từ $0$), từ đó có thể tìm biểu diễn này một cách
đệ quy. Theo [tính chất](./discrete-logarithm.md#tính-chất) của
logarit rời rạc, ta có

$$
4L(a) \equiv 4L(2^{e_1}+1) + 4L(2^{e_2}+1) + \cdots + 4L(2^{e_s}+1) \pmod{m}.
$$

Vì modulo của logarit rời rạc bằng bậc $\delta_m(g)=2^{e-2}=m/4$, ở đây nhân cả
đồng dư thức với $4$ để bảo đảm quá trình tính có thể thực hiện trong các lớp
thặng dư modulo $m$. Do đó, chỉ cần tiền xử lý tất cả giá trị $4L(2^d+1)$ với
$1 < d < e$, là có thể tính nhanh $4L(a)$.

Ngược lại, từ $L(a)$ cũng dễ thu được giá trị $g^a\bmod{m}$. Theo
[định lý nhị thức](../combinatorics/combination.md#%E4%BA%8C%E9%A1%B9%E5%BC%8F%E5%AE%9A%E7%90%86),
với $1 < d < e$ đều có

$$
\begin{aligned}
(2^d+1)^{2^{e-d}} \equiv 1 \pmod{m},\quad
(2^d+1)^{2^{e-d-1}} \equiv 1 + 2^{e-1} \pmod{m},
\end{aligned}
$$

nên $\delta_m(2^d+1) = 2^{e-d}$. Theo tính chất của bậc,

$$
\delta_m(2^d+1) = \dfrac{\delta_m(g)}{\gcd(\delta_m(g), \operatorname{ind}_g(2^d+1))}.
$$

Do đó, $\gcd(\delta_m(g), \operatorname{ind}_g(2^d+1)) = 2^{d-2}$. Điều này cho
thấy $L(2^d+1) = \operatorname{ind}_g(2^d+1) = 2^{d-2}r$, trong đó $2\nmid r$.
Vì vậy, bit bằng $1$ thấp nhất trong biểu diễn nhị phân của $4L(2^d+1)$ chính
là bit thứ $d$ (chỉ số bắt đầu từ $0$). Nhờ đó, cũng có thể dựa vào biểu diễn
nhị phân để đệ quy phân tích $4L(a)$ thành tổng các số có dạng $4L(2^d+1)$, từ
đó thu được giá trị của $a$.

Khi cài đặt cụ thể, có một vài điểm có thể tối ưu thêm. Trước hết, việc phân
tích $a$ thành dạng tích vẫn cần dùng phép chia. Cách thuận tiện hơn là tính
phân tích của $a^{-1}$, tức là tìm $1 < e_1 < e_2 < \cdots < e_s < e$ sao cho

$$
a(2^{e_1}+1)(2^{e_2}+1)\cdots(2^{e_s}+1) \equiv 1 \pmod{m}
$$

đúng. Vẫn xác định $e_1$ bằng cách tìm bit bằng $1$ thấp thứ hai, nhưng để khử
nhân tử $2^{e_1}+1$ trong $a^{-1}$, chỉ cần nhân $a$ với $2^{e_1}+1$, thao tác
này có thể thực hiện bằng bit. Lại vì $4L(a^{-1})=-4L(a)$, nên khi cộng dồn
$4L(a)$ cần dùng phép trừ thay cho phép cộng. Thứ hai, với lựa chọn cơ sở $g$
đặc biệt, vòng lặp không cần chạy đến $d = e-1$, mà chỉ cần chạy đến
$d = \lceil e/2\rceil - 1$. Để làm vậy, cần chọn $g$ sao cho

$$
4L(2^{\lceil e/2\rceil} + 1) = 2^{\lceil e/2\rceil}.
$$

Với $d \ge e / 2$, đều có

$$
(2^d+1)^2 = 2^{2d} + 2^{d+1} + 1 \equiv 2^{d+1} + 1 \pmod{m}.
$$

Do đó, quy nạp từ $d = \lceil e/2\rceil$ cho thấy $L(2^d+1)=2^d$ đúng với mọi
$d \ge e/2$. Suy ra, chỉ cần $e/2 \le e_1 < e_2 < \cdots < e_s < e$, ta có

$$
(2^{e_1}+1)(2^{e_2}+1)\cdots(2^{e_s}+1) \equiv 1 + 2^{e_1} + 2^{e_2} + \cdots + 2^{e_s} \pmod{m}
$$

và

$$
4L((2^{e_1}+1)(2^{e_2}+1)\cdots(2^{e_s}+1)) = 2^{e_1} + 2^{e_2} + \cdots + 2^{e_s}.
$$

Vì vậy, sau khi xử lý tất cả các bit $d < e/2$, có thể trực tiếp thu được
logarit rời rạc của phần còn lại mà không cần tính từng bit. Sau tối ưu thứ
nhất, toàn bộ phép lũy thừa chỉ cần $O(e)$ phép cộng trừ, thao tác bit và $1$
phép nhân; sau tối ưu thứ hai, có thể tiết kiệm gần một nửa số phép cộng trừ và
thao tác bit, đổi lại cần thêm $1$ phép nhân.

Làm ví dụ, cài đặt tham khảo cho phép lũy thừa modulo $2^{32}$ như sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/mod-arithmetic/mod-32-inv-pow.cpp:pow"
    ```

Tiền xử lý logarit rời rạc có thể thực hiện bằng thuật toán Pohlig-Hellman, và
có thể chọn cơ sở $g$ là

$$
5^{\operatorname{ind}_5(2^{\lceil e/2\rceil})/2^{\lceil e/2\rceil - 2}}\bmod{2^e}.
$$

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x6CE8;&#x91CA;"></span>
## Tài liệu tham khảo và ghi chú

-   [Fast modular multiplication by orz - Codeforces](https://codeforces.com/blog/entry/96759)
-   [Barrett Reduction - Wikipedia](https://en.wikipedia.org/wiki/Barrett_reduction)
-   [Barrett Reduction - A41](https://encrypt.a41.io/primitives/modular-arithmetic/modular-reduction/barrett-reduction#cost-analysis-of-modular-multiplication)
-   [Nguyên lý và chứng minh tính đúng của Barrett reduction by Chen - Zhihu](https://zhuanlan.zhihu.com/p/690876166)
-   [Montgomery Multiplication - CP Algorithms](https://cp-algorithms.com/algebra/montgomery_multiplication.html)
-   [Phép nhân modulo Montgomery by Chen - Zhihu](https://zhuanlan.zhihu.com/p/645428404)
-   [Binary Exponentiation by Factoring - CP Algorithms](https://cp-algorithms.com/algebra/factoring-exp.html)
-   Barrett, Paul. "Implementing the Rivest Shamir and Adleman public key encryption algorithm on a standard digital signal processor." In Conference on the Theory and Application of Cryptographic Techniques, pp. 311-323. Berlin, Heidelberg: Springer Berlin Heidelberg, 1986.
-   Becker, Hanno, Vincent Hwang, Matthias J. Kannwischer, Bo-Yin Yang, and Shang-Yi Yang. "Neon NTT: Faster Dilithium, Kyber, and Saber on Cortex-A72 and Apple M1." IACR Transactions on Cryptographic Hardware and Embedded Systems (2022): 221-244.
-   Montgomery, Peter L. "Modular multiplication without trial division." Mathematics of computation 44, no. 170 (1985): 519-521.

[^long-double-80bit]: Điều này đúng với GCC hoặc Clang trên phần lớn hệ thống
    64 bit.

[^floating-format]: Xem [Double-precision floating-point format - Wikipedia](https://en.wikipedia.org/wiki/Double-precision_floating-point_format).

[^ld-mul-err]: Ở đây dùng điều kiện $a < m$, tức là $a / m \in [0,1)$.

[^int128]: Trong các môi trường biên dịch phổ biến hiện nay, chỉ MSVC trên
    Windows không hỗ trợ kiểu `__int128`. Nếu cần viết mã tương thích nhiều nền
    tảng, có thể phát hiện môi trường MSVC bằng macro `_MSC_VER`, rồi trong điều
    kiện đó include [`<intrin.h>`](https://learn.microsoft.com/en-us/cpp/intrinsics/x64-amd64-intrinsics-list?view=msvc-170)
    và dùng các hàm nội tại được cung cấp (như `_umul128`) để gián tiếp cài đặt
    số nguyên 128 bit (chỉ khả dụng trên nền tảng 64 bit).

[^floor-barrett]: Ở đây $\left\lfloor\dfrac{r}{m}\right\rfloor$ cũng có thể
    thay bằng các ước lượng nguyên khác của $\dfrac{r}{m}$, chẳng hạn hàm trần
    $\left\lceil\dfrac{r}{m}\right\rceil$ và hàm làm tròn gần nhất
    $\left\lfloor\dfrac{r}{m}\right\rceil$, miễn là điều chỉnh bước sửa sai số
    của giá trị ước lượng tương ứng.

[^shoup]: Shoup đã cài đặt mở rộng này của Barrett reduction trong thư viện tính
    toán số học [NTL](https://libntl.org/), nên cách làm được đặt tên như vậy.

[^newton-hensel]: Kiểm tra trực tiếp: từ $mx \equiv 1 \pmod{2^e}$, đặt
    $mx = 1 + \lambda 2^e$, khi đó
    $mx(2-mx) = (1+\lambda 2^e)(1-\lambda 2^e) = 1 - \lambda^2 2^{2e} \equiv 1\pmod{2^{2e}}$.

[^mod-2-g]: Trang được dẫn trong bài chỉ chứng minh $g$ có thể lấy bằng $5$.
    Thực ra, lặp lại hoàn toàn chứng minh đó cho thấy $g$ có thể là bất kỳ số
    nguyên nào đồng dư $5$ theo modulo $8$. Phần sau sẽ thảo luận cách chọn
    $g$.
