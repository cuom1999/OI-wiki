author: c-forrest, Enter-tainer, hhc0001, Ir1d, KingMario, ksyx, Lutra-Fs, MegaOwIer, niujiaxing, StudyingFather, Tiphereth-A, TOMWT-qwq, ZnPdCo

**Hệ cơ số có nhớ** (carry system), còn gọi là **hệ cơ số**, **hệ ghi số theo vị trí** (positional notation), **cách ghi theo giá trị hàng** (place-value notation) hay **hệ thống số theo vị trí** (positional numeral system), là một hệ thống chữ số có thể biểu diễn mọi số tự nhiên bằng một số hữu hạn ký hiệu. Số lượng ký hiệu mà một hệ cơ số có thể dùng được gọi là **cơ số** (radix/base). Hệ có cơ số $n$ được gọi là hệ cơ số $n$ ($n>1$). Ví dụ, hệ thập phân mà ta dùng thường xuyên nhất thường chỉ dùng mười ký hiệu `0, 1, 2, 3, 4, 5, 6, 7, 8, 9` để ghi số. Phép nhớ là thao tác: khi một chữ số ở một hàng đạt đến cơ số, đặt nó thành 0 và cộng 1 vào hàng cao hơn.

Thông thường, ta ký hiệu một số trong hệ cơ số $n$ là $(a_k\cdots a_1a_0)_n$, $(a_k\cdots a_1a_0)_{(n)}$, ${a_k\cdots a_1a_0}_{(n)}$, ${a_k\cdots a_1a_0}_{n}$, v.v. Nếu cơ số đã rõ từ ngữ cảnh, ta cũng có thể bỏ chỉ số dưới. Lưu ý rằng $a_k\cdots a_1a_0$ ở đây không phải tích của $k+1$ số, mà là một dãy ký hiệu.

Với số hệ $k$ là $a_n\cdots a_1a_0$, giá trị của nó là $a_nk^n+\cdots+a_1k^1+a_0k^0=\sum_{i=0}^n a_ik^i$. Với một số $m$, giả sử biểu diễn của nó trong hệ $k$ là $a_n\cdots a_1a_0$, ta có:

$$
\begin{array}{cc}
    a_0=m-q_0k,&q_0=f(m/k),\\
    a_1=q_0-q_1k,&q_1=f(q_0/k),\\
    \vdots&\vdots\\
    a_n=q_{n-1}-q_nk,&q_n=f(q_{n-1}/k)=0,\\
\end{array}
$$

trong đó $f(x)=\lfloor x\rfloor$.

Độ dài biểu diễn của số $n$ trong hệ $k$ là $\lceil\log_k (n+1)\rceil$.

Thông thường, ta thêm dấu thập phân "$.$" để biểu diễn số thập phân[^note4], thêm dấu trừ "$-$" để biểu diễn số âm, và thêm gạch ngang trên một đoạn cuối phần thập phân để biểu diễn số thập phân vô hạn tuần hoàn. Để dễ đọc, ta có thể chèn ký hiệu phân cách sau mỗi vài chữ số (như khoảng trắng, $,$, `'`, v.v.), chẳng hạn $12~345$ biểu diễn $12345$.

Trong máy tính, các hệ cơ số thường dùng gồm nhị phân, bát phân và thập lục phân.

<span id="&#19981;&#21516;&#36827;&#20301;&#21046;&#38388;&#30340;&#36716;&#25442;"></span>
## Chuyển đổi giữa các hệ cơ số

<span id="&#21313;&#36827;&#21046;&#36716;&#20854;&#20182;&#36827;&#21046;"></span>
### Từ thập phân sang hệ cơ số khác

Ở đây ta minh họa bằng hệ nhị phân; nguyên lý của các hệ cơ số khác cũng tương tự.

Với phần nguyên, liên tục chia số thập phân cho $2$ cho đến khi thương bằng $0$, sau đó lấy tất cả các số dư theo thứ tự từ dưới lên trên; đó chính là các chữ số của phần nguyên trong hệ nhị phân. Với phần thập phân, nhân nó với $2$, lấy phần nguyên của kết quả, rồi tiếp tục lặp lại với phần thập phân mới cho đến khi phần thập phân bằng $0$; sau đó lấy các phần nguyên thu được theo thứ tự từ trên xuống dưới, đó chính là các chữ số của phần thập phân trong hệ nhị phân.

???+ example "Ví dụ"
    Chuyển $35.25$ sang số nhị phân.
    
    Phần nguyên:
    
    $$
    \begin{aligned}
        35/2&=17  &\dots 1,\\
        17/2&=8   &\dots 1,\\
        8/2&=4    &\dots 0,\\
        4/2&=2    &\dots 0,\\
        2/2&=1    &\dots 0,\\
        1/2&=0    &\dots 1.
    \end{aligned}
    $$
    
    Phần thập phân:
    
    $$
    \begin{aligned}
        0.25\times 2&=0.5  &\dots 0,\\
        0.5\times 2&=1     &\dots 1.
    \end{aligned}
    $$
    
    Suy ra $35.25 = (100011.01)_2$.

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/base/base_1.cpp:from_dec"
    ```

<span id="&#20854;&#20182;&#36827;&#21046;&#36716;&#21313;&#36827;&#21046;"></span>
### Từ hệ cơ số khác sang thập phân

Vẫn lấy hệ nhị phân làm ví dụ. Để chuyển một số nhị phân sang thập phân, chỉ cần nhân giá trị của từng chữ số với $2^i$, trong đó $i$ là vị trí của chữ số hiện tại, và vị trí hàng đơn vị là $0$.

???+ example "Ví dụ"
    Chuyển $(11010.01)_{2}$ sang số thập phân.
    
    $$
    \begin{aligned}
        (11010.01)_{2}&=\phantom{+~}1\times 2^4+1\times 2^3+0\times 2^2+1\times 2^1+0\times 2^0\\
        &\phantom{=}+~0\times 2^{-1}+1\times 2^{-2} \\
                    &=26.25.
    \end{aligned}
    $$
    
    Suy ra $(11010.01)_2 = (26.25)_{10}$.

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/base/base_1.cpp:to_dec"
    ```

<span id="&#20108;&#36827;&#21046;&#20843;&#36827;&#21046;&#21313;&#20845;&#36827;&#21046;&#38388;&#30340;&#30456;&#20114;&#36716;&#25442;"></span>
### Chuyển đổi qua lại giữa nhị phân, bát phân và thập lục phân

Một chữ số bát phân có thể biểu diễn bằng 3 bit nhị phân (vì $2^3 = 8$), một chữ số thập lục phân có thể biểu diễn bằng 4 bit nhị phân (vì $2^4 = 16$), và chiều ngược lại cũng tương tự.

<span id="&#34917;&#25968;&#27861;"></span>
## Phương pháp bù

Xem thêm: [Mã bù một và mã bù hai](../bit.md#số-nguyên-và-chuỗi-bit)

**Phương pháp bù** (method of complements) là phương pháp dùng số dương để biểu diễn số âm, nhằm tính phép trừ bằng cùng thuật toán, mạch điện hoặc cấu trúc cơ khí như phép cộng số dương. Phương pháp bù được dùng rộng rãi trong thiết kế máy tính bỏ túi và máy tính điện tử để đơn giản hóa cấu trúc.

Với số $n$ chữ số $a$ trong hệ cơ số $b$, **số bù theo cơ số** của nó (radix complement, gọi là bù $b$) là $b^n-a$; **số bù theo cơ số giảm** của nó (diminished radix complement, gọi là bù $b-1$, gọi tắt là **bù giảm**) là $b^n-1-a$. Trong hệ nhị phân, số bù theo cơ số được gọi là bù $2$ (two's complement), hay **mã bù hai**; số bù theo cơ số giảm được gọi là bù $1$ (ones' complement), hay **mã bù một**. Trong hệ thập phân, số bù theo cơ số còn gọi là bù $10$ (ten's complement), số bù theo cơ số giảm còn gọi là bù $9$ (nine's complement); các hệ cơ số khác suy ra tương tự.

Với hai số $n$ chữ số $x,y$ trong hệ cơ số $b$, khi tính $x-y$, ta có các cách sau (nếu kết quả vượt quá $n$ chữ số thì bỏ phần cao hơn):

1.  Xét bù giảm $x'=b^n-1-x$ của $x$, tính $x'+y=b^n-1-x+y$; bù giảm của kết quả này chính là đáp án.
2.  Xét bù giảm $y'=b^n-1-y$ của $y$, tính $x+y'=b^n-1+x-y$; cộng thêm một trực tiếp sẽ được đáp án.
3.  Xét bù theo cơ số $x'=b^n-x$ của $x$, tính $x'+y=b^n-x+y$; bù theo cơ số của kết quả này chính là đáp án.
4.  Xét bù theo cơ số $y'=b^n-y$ của $y$, tính $x+y'=b^n+x-y$; đây chính là đáp án.

Ngoài ra, với số trong hệ $k$, đặt $d=k-1$, ta có $\cdots dd=:\overline{d}=\sum_{i=0}^{\infty} dk^i=-1$. Do đó, với số $n$ chữ số $x$, giả sử biểu diễn theo hệ $k$ của số bù theo cơ số của nó là $a_{n-1}\cdots a_1a_0$, thì $\overline{d}a_{n-1}\cdots a_1a_0$ bằng $\sum_{i=0}^{n-1}a_ik^i+\sum_{i=n}^{\infty} dk^i=k^n-x+(-k^n)=-x$. Ý tưởng về "số có vô hạn chữ số" này có thể tổng quát thành [**số $p$-adic**](https://en.wikipedia.org/wiki/P-adic_number) ($p$-adic number).

Bên cạnh đó, ta có một định lý thú vị về phần bù và số thập phân vô hạn tuần hoàn:

???+ note "Định lý Midy"
    Giả sử $a$ là số nguyên dương, $p$ là số nguyên tố dương, và biểu diễn của $a/p$ trong hệ cơ số $b$ là $0.\overline{a_1a_2\cdots a_l}$, trong đó $l$ là độ dài chu kỳ (ngắn nhất). Nếu $l$ là số chẵn[^note5], đặt $l=2k$, thì $a_1a_2\cdots a_k$ là bù giảm của $a_{k+1}a_{k+2}\cdots a_{2k}$, tức là:
    
    -   $a_i+a_{i+k}=b$,
    -   $a_1a_2\cdots a_k+a_{k+1}a_{k+2}\cdots a_{2k}=b^k-1$.
    
    Hơn nữa, nếu $l$ có ước không tầm thường $k$, đặt $l=nk$, thì $\sum_{i=0}^{n-1}a_{ik+1}a_{ik+2}\cdots a_{(i+1)k}$ là bội của $b^k-1$.

??? example "Ví dụ"
    Với $1/19=0.\overline{052~631~578~947~368~421}=0.\overline{032~745}_{(8)}$, ta có:
    
    -   $052~631~578+947~368~421=999~999~999$,
    -   $052+631+578+947+368+421=3\times 999$,
    -   $032_{(8)}+745_{(8)}=777_{(8)}$,
    -   $03_{(8)}+27_{(8)}+45_{(8)}=77_{(8)}$.

??? note "Chứng minh"
    Với $a,b,p,l,n,k$ trong định lý, dễ thấy rằng $1\leq a<p$, $b>1$ và $(a,p)=(b,p)=1$.
    
    Với số nguyên $0\leq i<l$, đặt $f(i)=b^i\cdot a/p-\lfloor b^i\cdot a/p\rfloor$, ta có
    
    $$
    0<f(i)=0.\overline{a_{i+1}a_{i+2}\cdots a_{nk}a_1a_2\cdots a_i}<1 \implies 0<pf(i)<p.
    $$
    
    Lưu ý $pf(i)\in\mathbf{N}_+$ và $pf(i)\equiv ab^i\pmod p$, nên $pf(i)=ab^i\bmod p$.
    
    Đặt $S_n=\sum_{i=0}^{n-1}f(ik)=\sum_{i=0}^{n-1}0.\overline{a_{ik+1}a_{ik+2}\cdots a_{nk}a_1a_2\cdots a_{ik}}$. Ta có thể "hoán đổi" một số chữ số giữa các số thập phân (ví dụ $0.\overline{{\color{Orchid}{14}}{\color{RoyalBlue}{28}}{\color{YellowGreen}{57}}}+0.\overline{{\color{RoyalBlue}{28}}{\color{YellowGreen}{57}}{\color{Orchid}{14}}}+0.\overline{{\color{YellowGreen}{57}}{\color{Orchid}{14}}{\color{RoyalBlue}{28}}}=0.\overline{\color{Orchid}{141414}}+0.\overline{\color{RoyalBlue}{282828}}+0.\overline{\color{YellowGreen}{575757}}=0.\overline{\color{Orchid}{14}}+0.\overline{\color{RoyalBlue}{28}}+0.\overline{\color{YellowGreen}{57}}=14/99+28/99+57/99=1$), do đó
    
    $$
    \begin{aligned}
        S_n&=\sum_{i=0}^{n-1}0.\overline{a_{ik+1}a_{ik+2}\cdots a_{(i+1)k}}\\
        &=\sum_{i=0}^{n-1}a_{ik+1}a_{ik+2}\cdots a_{(i+1)k}/\left(b^k-1\right),
    \end{aligned}
    $$
    
    suy ra
    
    $$
    pS_n=p\sum_{i=0}^{n-1}a_{ik+1}a_{ik+2}\cdots a_{(i+1)k}/\left(b^k-1\right)= \sum_{i=0}^{n-1} \left(ab^{ik}\bmod p\right),
    $$
    
    vì thế
    
    $$
    \sum_{i=0}^{n-1}a_{ik+1}a_{ik+2}\cdots a_{(i+1)k}=\left(b^k-1\right)\frac{\sum_{i=0}^{n-1} \left(ab^{ik}\bmod p\right)}{p}.
    $$
    
    Nếu $p\mid \left(b^k-1\right)$, lưu ý rằng
    
    $$
    \left(b^k-1\right)a/p=a_1a_2\cdots a_k.\overline{a_{k+1}a_{k+2}\cdots a_{nk}a_1a_2\cdots a_k}-0.\overline{a_{1}a_{2}\cdots a_{nk}},
    $$
    
    nên $a_{k+1}a_{k+2}\cdots a_{nk}a_1a_2\cdots a_k=a_{1}a_{2}\cdots a_{nk}$, suy ra $a_1a_2\cdots a_k=a_{k+1}a_{k+2}\cdots a_{2k}=\dots=a_{(n-1)k+1}a_{(n-1)k+2}\cdots a_{nk}$, tức là $0.\overline{a_1a_2\cdots a_l}=0.\overline{a_1a_2\cdots a_k}$, mâu thuẫn với định nghĩa của $l$. Do đó $p\nmid \left(b^k-1\right)$.
    
    Vì vậy tồn tại số nguyên dương $c=\dfrac{\sum_{i=0}^{n-1} \left(ab^{ik}\bmod p\right)}{p}$ sao cho
    
    $$
    \sum_{i=0}^{n-1}a_{ik+1}a_{ik+2}\cdots a_{(i+1)k}=c\left(b^k-1\right).
    $$

???+ note "Hệ quả"
    Với $b,n,k,p$ như trên, ta có
    
    $$
    \sum_{i=0}^{n-1} b^{ik}\equiv 0\pmod p.
    $$

<span id="&#24191;&#20041;&#36827;&#21046;&#31995;&#32479;"></span>
## Hệ cơ số tổng quát

Trong hệ cơ số tiêu chuẩn, cơ số $b$ luôn là một số dương cố định, mỗi chữ số được chọn từ $b$ ký hiệu khác nhau để biểu diễn một số không âm (không xét dấu thập phân và dấu âm). Thực ra vẫn có nhiều hệ ghi số và hệ cơ số có đặc điểm tương tự, nhưng không hoàn toàn phù hợp với định nghĩa của hệ cơ số. Ta gọi các hệ ghi số như vậy là **hệ cơ số tổng quát** hay **hệ cơ số phi chuẩn** (Non-standard positional numeral systems). Dưới đây là một số hệ cơ số tổng quát thường gặp.

<span id="&#21452;&#23556;&#35760;&#25968;&#31995;&#32479;"></span>
### Hệ ghi số song ánh

Hệ cơ số tiêu chuẩn không tạo được song ánh với các số mà nó biểu diễn; chẳng hạn $1$, $01$, $001$ đều biểu diễn cùng một số[^note1]. Ngược lại, **hệ ghi số song ánh** (bijective numeral system) có thể tạo song ánh với các số mà nó biểu diễn.

Hệ song ánh cơ số $k$ ($k\geq 1$) dùng tập số $\{1,2,\dots,k\}$ để biểu diễn duy nhất một số, theo quy tắc:

1.  Dùng chuỗi rỗng để biểu diễn $0$;
2.  Dùng chuỗi khác rỗng $a_n\cdots a_1a_0$ để biểu diễn số $a_nk^n+\cdots+a_1k^1+a_0k^0=\sum_{i=0}^n a_ik^i$.

Với một số dương $m$, giả sử biểu diễn của nó trong hệ song ánh cơ số $k$ là $a_n\cdots a_1a_0$, ta có:

$$
\begin{array}{cc}
    a_0=m-q_0k,&q_0=f(m/k),\\
    a_1=q_0-q_1k,&q_1=f(q_0/k),\\
    \vdots&\vdots\\
    a_n=q_{n-1}-q_nk,&q_n=f(q_{n-1}/k)=0,\\
\end{array}
$$

trong đó $f(x)=\lceil x\rceil-1$.

Ví dụ, nhãn cột trong Microsoft Excel dùng hệ song ánh cơ số $26$.

Trong hệ ghi số song ánh, ta có [hệ một phân](https://en.wikipedia.org/wiki/Unary_numeral_system); chuỗi khác rỗng trong hệ một phân chỉ gồm các ký hiệu $1$, và độ dài chuỗi chính là số mà nó biểu diễn.

Tương tự mô tả trong [phương pháp bù](#%E8%A1%A5%E6%95%B0%E6%B3%95), với hệ song ánh cơ số $k$ và $k>1$, đặt $d=k-1$, ta có $\cdots dd=:\overline{d}=\sum_{i=0}^{\infty} dk^i=-1$, suy ra $\overline{d}k=0$. Do đó, nếu biểu diễn của $x$ trong hệ song ánh cơ số $k$ là $a_{n-1}\cdots a_1a_0$, thì $\overline{d}ka_{n-1}\cdots a_1a_0$ chính là $-x$.

Dưới đây là một số tính chất của số trong hệ song ánh cơ số $k$:

-   Có $k^l$ số có độ dài $l\geq 0$.
-   Khi $k\geq 2$, độ dài biểu diễn của số $n$ trong hệ song ánh cơ số $k$ là $\lfloor\log_k (n+1)(k-1)\rfloor$.
-   Khi $k\geq 2$, nếu biểu diễn của một số $n$ trong hệ cơ số $k$ không chứa $0$, thì biểu diễn của nó trong hệ cơ số $k$ và trong hệ song ánh cơ số $k$ là như nhau.

Mã chuyển từ hệ song ánh cơ số $k$ sang thập phân giống với mã chuyển từ hệ cơ số $k$ sang thập phân. Sau đây là cài đặt tham khảo để chuyển từ thập phân sang hệ song ánh cơ số $k$.

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/base/base_1.cpp:from_dec_bi"
    ```

<span id="&#26377;&#31526;&#21495;&#20301;&#25968;&#36827;&#21046;"></span>
### Hệ cơ số có chữ số mang dấu

Một số hệ cơ số cho phép chữ số nhận giá trị âm, chẳng hạn [hệ tam phân cân bằng](./balanced-ternary.md).

<span id="gray-&#30721;"></span>
### Mã Gray

Mục chính: [Mã Gray](./gray-code.md)

Mã Gray còn gọi là **mã nhị phân vòng** hoặc **mã nhị phân phản xạ** (reflected binary code, RBC), là một hệ số nhị phân đặc biệt, thường dùng trong kiểm tra dữ liệu.

<span id="&#38750;&#27491;&#22522;&#25968;&#36827;&#21046;"></span>
### Hệ cơ số không dương

Ta biết với số hệ $k$ là $a_n\cdots a_1a_0$, giá trị của nó là $\sum_{i=0}^n a_ik^i$. Chỉ cần sửa đổi nhẹ, ta có thể định nghĩa số hệ $-k$ là ${a_n\cdots a_1a_0}_{(-k)}$ biểu diễn $\sum_{i=0}^n a_i(-k)^i$, trong đó $a_n,\dots,a_1,a_0\in \{0,1,\dots,k-1\}$. Ví dụ $12345_{(-10)}=8265_{(10)}$. Hệ cơ số này được gọi là [**hệ cơ số âm**](https://en.wikipedia.org/wiki/Negative_base) (negative-base system).

Tương tự, ta cũng có thể định nghĩa [**hệ cơ số phức**](https://en.wikipedia.org/wiki/Complex-base_system) (complex-base system), như [**hệ cơ số $2\mathrm{i}$**](https://en.wikipedia.org/wiki/Quater-imaginary_base) (quater-imaginary base, quater-imaginary numeral system). Ta còn có thể định nghĩa [**hệ cơ số không nguyên**](https://en.wikipedia.org/wiki/Non-integer_base_of_numeration) (non-integer base of numeration) để biểu diễn **khai triển $\beta$** ($\beta$-expansion) của số thực, v.v.

<span id="&#28151;&#21512;&#22522;&#25968;&#36827;&#21046;"></span>
### Hệ cơ số hỗn hợp

Trong hệ cơ số tiêu chuẩn, cơ số tương ứng với mỗi chữ số đều cố định, còn hệ cơ số hỗn hợp cho phép mỗi chữ số có một cơ số riêng. Ứng dụng phổ biến nhất của hệ cơ số hỗn hợp là đo thời gian: giờ dùng hệ $24$, phút và giây dùng hệ $60$.

$a_n\cdots a_1a_0$ biểu diễn số $\sum_{i=0}^n a_ib^i$ trong hệ cơ số $b$; trong hệ cơ số hỗn hợp, nó biểu diễn số $\sum_{i=0}^n a_i\prod_{j=0}^{i-1}b_j$, trong đó $b_j$ là cơ số tương ứng với $a_j$.

Trong lập trình thi đấu, hệ cơ số hỗn hợp thường gặp nhất là [**hệ cơ số giai thừa**](https://en.wikipedia.org/wiki/Factorial_number_system) (factorial number system). Số trong hệ này có thể ký hiệu là ${a_n\cdots a_1a_0}_{~!}$, và biểu diễn giá trị $\sum_{i=0}^na_i i!$[^note2]. Ứng dụng của hệ cơ số giai thừa trong lập trình thi đấu có thể xem tại [mã Lehmer/khai triển Cantor](../permutation.md#%E6%8E%92%E5%90%8D).

???+ note "Cài đặt (thập phân sang hệ cơ số giai thừa)"
    ```cpp
    --8<-- "docs/math/code/base/base_1.cpp:from_dec_factorial"
    ```

???+ note "Cài đặt (hệ cơ số giai thừa sang thập phân)"
    ```cpp
    --8<-- "docs/math/code/base/base_1.cpp:to_dec_factorial"
    ```

<span id="c-&#20013;&#30340;&#23454;&#29616;"></span>
## Cài đặt trong C++

Với số không âm, C++ biểu diễn một literal số nguyên bằng `<tiền_tố><chữ_số><hậu_tố>`, trong đó `<chữ_số>` và `<hậu_tố>` đều có thể rỗng. `<hậu_tố>` dùng để biểu diễn kiểu của literal, chẳng hạn `u` hoặc `U` cho biết literal có kiểu `unsigned`, `l` hoặc `L` cho biết literal có kiểu `long`, v.v. Với `<tiền_tố>`:

-   Khi `<tiền_tố>` là `0x` hoặc `0X`, đây là literal thập lục phân; khi đó các ký tự trong `<chữ_số>` chỉ có thể chọn từ `0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, A, b, B, c, C, d, D, e, E, f, F`. Ví dụ `0x1234ABCD` là $\text{1234ABCD}_{(16)}=305~441~741$;
-   Khi `<tiền_tố>` là `0`, đây là literal bát phân; khi đó các ký tự trong `<chữ_số>` chỉ có thể chọn từ `0, 1, 2, 3, 4, 5, 6, 7`. Ví dụ `01234567` là $1234567_{(8)}=342391$;[^note3]
-   Khi `<tiền_tố>` là `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8` hoặc `9`, đây là literal thập phân; khi đó các ký tự trong `<chữ_số>` chỉ có thể chọn từ `0, 1, 2, 3, 4, 5, 6, 7, 8, 9`;
-   Từ C++14, khi `<tiền_tố>` là `0b` hoặc `0B`, đây là literal nhị phân; khi đó các ký tự trong `<chữ_số>` chỉ có thể chọn từ `0, 1`. Ví dụ `0b11001010` là $11001010_{(2)}=202$.

<span id="&#21442;&#32771;&#36164;&#26009;&#19982;&#27880;&#37322;"></span>
## Tài liệu tham khảo và ghi chú

-   [Positional notation - Wikipedia](https://en.wikipedia.org/wiki/Positional_notation)
-   [Method of complements - Wikipedia](https://en.wikipedia.org/wiki/Method_of_complements)
-   [Non-standard positional numeral systems - Wikipedia](https://en.wikipedia.org/wiki/Non-standard_positional_numeral_systems)
-   [Bijective numeration - Wikipedia](https://en.wikipedia.org/wiki/Bijective_numeration)
-   [Midy's theorem - Wikipedia](https://en.wikipedia.org/wiki/Midy%27s_theorem)
-   [N3472 - Binary Literals in the C++ Core Language](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3472.pdf)

[^note1]: Các chữ số $0$ nằm trước chữ số khác $0$ cao nhất được gọi là [**số 0 dẫn đầu**](https://en.wikipedia.org/wiki/Leading_zero) (leading zero). Tương tự, ta có thể định nghĩa [**số 0 theo sau**](https://en.wikipedia.org/wiki/Trailing_zero) (trailing zero).

[^note2]: Cơ số tương ứng với $a_i$ là $i+1$, và $0\leq a_i\leq i$. Lưu ý $(n+1)!-n!=n\cdot n!$, nên biểu diễn của một số trong hệ cơ số giai thừa là duy nhất nếu bỏ các số 0 dẫn đầu.

[^note3]: `0` là literal bát phân.

[^note4]: Một số khu vực dùng "$,$" làm dấu thập phân.

[^note5]: Khi $a=1$, trong hệ thập phân, dãy các số nguyên tố thỏa mãn điều kiện này là [A028416](https://oeis.org/A028416).
