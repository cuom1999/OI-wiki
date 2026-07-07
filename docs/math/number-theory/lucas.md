Kiến thức nền: [Giai thừa theo môđun](./factorial.md)

<span id="mở-đầu"></span>
## Mở đầu

Bài viết này thảo luận cách tính hệ số tổ hợp lớn theo môđun. Hệ số tổ hợp, còn
gọi là hệ số nhị thức, là biểu thức:

$$
\binom{n}{k} = \dfrac{n!}{k!(n-k)!}.
$$

Khi quy mô không lớn, hệ số tổ hợp có thể được tính bằng
[công thức truy hồi](../combinatorics/combination.md#tinh-chat-cua-so-to-hop-he-qua-nhi-thuc)
với độ phức tạp thời gian $O(nk)$. Nếu môđun là số nguyên tố lớn $p>n$, cũng có
thể tính giai thừa của tử số và mẫu số trong $O(n)$ thời gian. Tuy nhiên, khi
quy mô bài toán rất lớn ($n\sim 10^{18}$), các phương pháp này không còn phù
hợp.

Dựa trên định lý Lucas và các mở rộng của nó, bài viết này trình bày một phương
pháp tính hệ số tổ hợp khi môđun không quá lớn ($m \sim 10^6$). Chính xác hơn,
chỉ cần tổng các lũy thừa nguyên tố trong phân tích duy nhất
$m=\prod p_i^{e_i}$, tức $\sum p_i^{e_i}$, ở cỡ $10^6$ là có thể dùng phương
pháp này, vì phần tiền xử lý của thuật toán có quy mô xấp xỉ như vậy.

<span id="định-lý-lucas"></span>
## Định lý Lucas

Trước hết xét trường hợp môđun là số nguyên tố $p$. Khi đó có định lý Lucas:

???+ note "Định lý Lucas"
    Với số nguyên tố $p$, có

    $$
    \binom{n}{k}\equiv \binom{\lfloor n/p\rfloor}{\lfloor k/p\rfloor}\binom{n\bmod p}{k\bmod p}\pmod p.
    $$
    
    Trong đó, khi $n<k$, hệ số nhị thức $\dbinom{n}{k}$ được quy ước bằng $0$.

??? note "Chứng minh bằng hàm sinh"
    Xét giá trị của $\displaystyle\binom{p}{n} \bmod p$. Vì
    
    $$
    \binom{p}{n} = \frac{p!}{n!(p-n)!},
    $$
    
    nên khi $n\neq 0,p$, mẫu số không có thừa số $p$ nhưng tử số có thừa số $p$,
    do đó phân thức là bội của $p$ và có phần dư $0$ theo môđun $p$. Khi
    $n=0,p$, phân thức bằng $1$. Vì vậy
    
    $$
    \binom{p}{n} \equiv [n=0\lor n=p] \pmod p.
    $$
    
    Đặt $f(x) = ax^n + bx^m$. Tổng quát hơn, theo
    [khai triển nhị thức](../combinatorics/combination.md#định-lý-nhị-thức) và
    [định lý nhỏ Fermat](./fermat.md#định-lý-nhỏ-fermat), có
    
    $$
    \begin{aligned}
    (f(x))^p 
    &= \left(ax^n + bx^m\right)^p \\
    &= \sum_{k=0}^p\binom{p}{k}(ax^n)^k(bx^m)^{p-k}\\
    &\equiv a^px^{pn} + b^px^{pm} \\
    &\equiv a(x^p)^n+b(x^p)^m\\
    &= f(x^p) \pmod p.
    \end{aligned}
    $$
    
    Trong đó, phép đồng dư ở dòng thứ ba dùng kết luận vừa nêu: chỉ khi $k=0,p$ thì hệ số tổ hợp mới không phải bội của $p$.
    
    Dùng kết luận này, xét khai triển nhị thức:
    
    $$
    \begin{aligned}
    (1+x)^n &= (1+x)^{p\lfloor n/p\rfloor}(1+x)^{n\bmod p} \\
    &\equiv (1+x^p)^{\lfloor n/p\rfloor}(1+x)^{n\bmod p} \pmod p.
    \end{aligned}
    $$
    
    Ở vế trái, hệ số của hạng tử $x^k$ là
    
    $$
    \binom{n}{k}\bmod p.
    $$
    
    Bây giờ tính hệ số của $x^k$ ở vế phải. Bậc của mọi hạng tử trong nhân tử
    thứ nhất đều là bội của $p$; bậc của mọi hạng tử trong nhân tử thứ hai đều
    nhỏ hơn $p$. Cách phân tích $k$ thành tổng của hai phần như vậy là duy nhất,
    chính là phép chia có dư: $k=p\lfloor k/p\rfloor +(k\bmod p)$. Vì thế nhân
    tử thứ nhất chỉ có thể đóng góp hạng tử bậc $p\lfloor k/p\rfloor$, còn nhân
    tử thứ hai chỉ có thể đóng góp hạng tử bậc $k\bmod p$. Do đó hệ số của
    $x^k$ ở vế phải là tích của hai hệ số tương ứng trong hai nhân tử:
    
    $$
    \binom{\lfloor n/p\rfloor}{\lfloor k/p\rfloor}\binom{n\bmod p}{k\bmod p}\bmod p.
    $$
    
    Cho hai hệ số ở hai vế bằng nhau sẽ thu được định lý Lucas.

??? note "Chứng minh bằng kết quả về giai thừa theo môđun"
    Phần này đưa ra một chứng minh dựa trên các kết quả liên quan đến
    [giai thừa theo môđun](./factorial.md#trường-hợp-modulo-số-nguyên-tố), nhằm
    liên hệ thuận tiện với phương pháp ở phần exLucas phía sau. Hệ số nhị thức là
    
    $$
    \binom{n}{k} = \dfrac{n!}{k!(n-k)!}.
    $$
    
    Tách số mũ của $p$ trong giai thừa $n!$ và các thừa số còn lại, thu được
    phân tích:
    
    $$
    n! = p^{\nu_p(n!)}(n!)_p.
    $$
    
    Từ đó hệ số nhị thức có dạng:
    
    $$
    \binom{n}{k} = p^{\nu_p(n!)-\nu_p(k!)-\nu_p((n-k)!)}\dfrac{(n!)_p}{(k!)_p((n-k)!)_p}.
    $$
    
    Số mũ $\nu_p(n!)$ và phần dư giai thừa $(n!)_p\bmod p$ đều có công thức
    truy hồi:
    
    $$
    \begin{aligned}
    \nu_p(n!) &= \lfloor n/p\rfloor+\nu_p( \lfloor n/p\rfloor!),\\
    (n!)_p &\equiv (-1)^{\lfloor n/p\rfloor}\cdot (n\bmod p)!\cdot (\lfloor n/p\rfloor!)_p\pmod p.
    \end{aligned}
    $$
    
    Công thức thứ nhất là hệ quả của công thức Legendre, công thức thứ hai là hệ
    quả của định lý Wilson.
    
    Thay các công thức truy hồi vào biểu thức của hệ số nhị thức rồi rút gọn,
    thu được:
    
    $$
    \begin{aligned}
    \binom{n}{k} &\equiv (-p)^{\lfloor n/p\rfloor-\lfloor k/p\rfloor-\lfloor(n-k)/p\rfloor}\cdot\dfrac{(n\bmod p)!}{(k\bmod p)!((n-k)\bmod p)!} \\
    &\quad \cdot
    p^{\nu_p(\lfloor n/p\rfloor!)-\nu_p(\lfloor k/p\rfloor!)-\nu_p(\lfloor(n-k)/p\rfloor!)}\\
    &\quad \cdot
    \dfrac{(\lfloor n/p\rfloor!)_p}{(\lfloor k/p\rfloor!)_p(\lfloor(n-k)/p\rfloor!)_p}
    \pmod p.
    \end{aligned}
    $$
    
    Bây giờ xét giá trị của
    $\lfloor n/p\rfloor-\lfloor k/p\rfloor-\lfloor(n-k)/p\rfloor$. Vì
    
    $$
    \begin{aligned}
    n &= \lfloor n/p\rfloor p + (n\bmod p),\\
    k &= \lfloor k/p\rfloor p + (k\bmod p),\\
    n-k &= \lfloor (n-k)/p\rfloor p + ((n-k)\bmod p),\\
    \end{aligned}
    $$
    
    nên lấy công thức thứ nhất trừ hai công thức sau sẽ cho
    
    $$
    (\lfloor n/p\rfloor-\lfloor k/p\rfloor-\lfloor(n-k)/p\rfloor)p = (k\bmod p)+((n-k)\bmod p)-(n\bmod p).
    $$
    
    Ở vế phải, tổng của hai hạng tử đầu nhỏ hơn $2p$, còn hạng tử thứ ba
    $n\bmod p$ chính là phần dư của tổng hai hạng tử đầu. Vì vậy vế phải không
    âm, nhỏ hơn $2p$, đồng thời phải là bội của $p$, nên chỉ có thể là $0$ hoặc
    $p$. Điều này cho thấy
    $\lfloor n/p\rfloor-\lfloor k/p\rfloor-\lfloor(n-k)/p\rfloor$ chỉ có thể
    bằng $0$ hoặc $1$:

    -   Nếu nó bằng $0$, khi đó cũng có
        $(n\bmod p) = (k\bmod p)+((n-k)\bmod p)$. Vì thế số mũ của nhân tử thứ
        nhất trong công thức trên bằng $0$, nhân tử đó bằng một; nhân tử thứ hai
        là $\dbinom{n\bmod p}{k\bmod p}$; nhân tử thứ ba, theo khai triển phía
        trên, bằng $\dbinom{\lfloor n/p\rfloor}{\lfloor k/p\rfloor}$. Khi đó
        công thức Lucas đúng;
    -   Nếu nó bằng $1$, số mũ của nhân tử thứ nhất bằng $1$, nhân tử đó bằng
        không, nên phần dư của hệ số nhị thức bằng không. Đồng thời,
        $\dbinom{n\bmod p}{k\bmod p}$ ở vế phải của đẳng thức trong định lý
        Lucas cũng bằng không, vì lúc này phải có $(n\bmod p)<(k\bmod p)$. Nếu
        không, sẽ có
    
        $$
        ((n-k)\bmod p) = p + (n\bmod p)  - (k\bmod p) \ge p.
        $$
    
        Điều này mâu thuẫn với định nghĩa của phần dư.
    
    Kết hợp hai trường hợp, thu được định lý Lucas cần chứng minh. Chứng minh
    này cũng cho thấy khi tính hệ số tổ hợp theo môđun số nguyên tố, dùng định
    lý Lucas và dùng thuật toán exLucas cho cùng một kết quả.

Định lý Lucas chỉ ra rằng khi môđun là số nguyên tố $p$, việc tính hệ số tổ hợp
lớn có thể chuyển thành tính các hệ số tổ hợp có quy mô nhỏ hơn. Ở vế phải, hệ
số tổ hợp thứ nhất có thể tiếp tục xử lý đệ quy cho đến khi $n,k<p$; hệ số tổ
hợp thứ hai có thể tính trực tiếp hoặc tiền xử lý trước. Viết dưới dạng mã:

???+ example "Minh họa"
    ```cpp
    long long Lucas(long long n, long long k, long long p) {
      if (k == 0) return 1;
      return (C(n % p, k % p, p) * Lucas(n / p, k / p, p)) % p;
    }
    ```

Trong đó, `C(n, k, p)` dùng để tính hệ số tổ hợp quy mô nhỏ.

Đệ quy thực hiện nhiều nhất $O(\log_p n)$ lần, nên độ phức tạp của thuật toán là
$O(f(p)+g(p)\log_p n)$, trong đó $f(p)$ là độ phức tạp tiền xử lý hệ số tổ hợp,
còn $g(p)$ là độ phức tạp cho một lần tính hệ số tổ hợp.

<span id="cài-đặt-tham-khảo-lucas"></span>
### Cài đặt tham khảo

Cài đặt tham khảo dưới đây tiền xử lý giai thừa và nghịch đảo của chúng trong
phạm vi $p$ trong $O(p)$ thời gian, rồi tính một hệ số tổ hợp trong $O(1)$ thời
gian:

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/lucas/lucas.cpp"
    ```

Độ phức tạp thời gian của cài đặt này là $O(p+T\log_p n)$, trong đó $T$ là số
truy vấn.

<span id="thuật-toán-exlucas"></span>
## Thuật toán exLucas

Trong định lý Lucas, môđun $p$ bắt buộc phải là số nguyên tố. Khi $p$ không phải
số nguyên tố, cần dùng thuật toán exLucas. Dù tên gọi là vậy, khi vận hành thuật
toán này không thực sự dùng định lý Lucas. Bước mấu chốt của nó là
[tính giai thừa theo môđun lũy thừa nguyên tố](./factorial.md). Chứng minh thứ
hai ở trên đã chỉ ra mối liên hệ giữa nó và định lý Lucas.

<span id="trường-hợp-modulo-lũy-thừa-nguyên-tố"></span>
### Trường hợp môđun lũy thừa nguyên tố

Trước hết xét trường hợp môđun là lũy thừa nguyên tố $p^\alpha$. Tách số mũ của
$p$ trong giai thừa $n!$ và các thừa số còn lại, thu được phân tích:

$$
n! = p^{\nu_p(n!)}(n!)_p.
$$

Trong đó, $\nu_p(n!)$ là số mũ của $p$ trong phân tích thừa số nguyên tố của
$n!$, còn $(n!)_p$ nguyên tố cùng nhau với $p$. Vì vậy hệ số tổ hợp có thể viết
thành:

$$
\binom{n}{k} = p^{\nu_p(n!)-\nu_p(k!)-\nu_p((n-k)!)}\dfrac{(n!)_p}{(k!)_p((n-k)!)_p}.
$$

Các giá trị $\nu_p(n!)$ có thể tính bằng
[công thức Legendre](./factorial.md#công-thức-legendre), còn các giá trị
$(n!)_p$ có thể tính bằng
[quan hệ truy hồi](./factorial.md#trường-hợp-modulo-lũy-thừa-nguyên-tố). Vì phần
sau nguyên tố cùng nhau với $p^\alpha$, nghịch đảo của tích ở mẫu số có thể tính
bằng [thuật toán Euclid mở rộng](./inverse.md#thuật-toán-euclid-mở-rộng). Như
vậy bài toán được giải quyết.

Lưu ý rằng nếu số mũ $\nu_p(n!)-\nu_p(k!)-\nu_p((n-k)!)\ge\alpha$, phần dư bằng
không và không cần tính tiếp.

<span id="trường-hợp-modulo-tổng-quát"></span>
### Trường hợp môđun tổng quát

Với trường hợp $m$ là hợp số tổng quát, trước hết chỉ cần
[phân tích thừa số nguyên tố](./pollard-rho.md) của nó:

$$
m = p_1^{\alpha_1}p_2^{\alpha_2}\cdots p_s^{\alpha_s}.
$$

Sau đó, lần lượt tính phần dư của hệ số tổ hợp $\dbinom{n}{k}$ theo môđun
$p_i^{\alpha_i}$, thu được $s$ phương trình đồng dư:

$$
\begin{cases}
\dbinom{n}{k} \equiv r_1, &\pmod{p_1^{\alpha_1}}, \\
\dbinom{n}{k} \equiv r_2, &\pmod{p_2^{\alpha_2}}, \\
\quad\quad\cdots\\
\dbinom{n}{k} \equiv r_s, &\pmod{p_s^{\alpha_s}}.
\end{cases}
$$

Cuối cùng, dùng [định lý số dư Trung Hoa](./crt.md#định-nghĩa) để tìm phần dư
theo môđun $m$.

<span id="cài-đặt-tham-khảo-exlucas"></span>
### Cài đặt tham khảo

Cuối cùng là cài đặt tham khảo cho bài mẫu [Hệ số nhị thức](https://loj.ac/p/181).

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/lucas/exlucas.cpp"
    ```

Thuật toán này phân tích môđun $m$ thành các lũy thừa nguyên tố trong bước tiền
xử lý, sau đó với mọi $p^\alpha$ tiền xử lý tích của các số tự nhiên từ $1$ đến
$p^\alpha$ không phải bội của $p$, cũng như hệ số tương ứng khi gộp đáp án bằng
định lý số dư Trung Hoa. Độ phức tạp tiền xử lý là
$O(\sqrt{m}+\sum_ip_i^{\alpha_i})$. Với mỗi truy vấn, độ phức tạp là
$O(\log m+\sum_i\log_{p_i}n)$; hai hạng trong độ phức tạp lần lượt đến từ việc
tính nghịch đảo và việc tính số mũ, phần dư giai thừa.

<span id="bài-tập"></span>
## Bài tập

-   [Luogu P3807 [Mẫu] Định lý Lucas](https://www.luogu.com.cn/problem/P3807)
-   [SDOI2010 Ancient Pig Script - Định lý Lucas](https://loj.ac/problem/10229)
-   [Luogu P4720 [Mẫu] Lucas mở rộng](https://www.luogu.com.cn/problem/P4720)
-   [Ceizenpok's formula](http://codeforces.com/gym/100633/problem/J)
