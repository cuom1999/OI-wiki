Bài viết này giới thiệu nghịch đảo nhân theo môđun và các cách thường dùng để
tính nó.

<span id="khái-niệm-cơ-bản"></span>
## Khái niệm cơ bản

Nghịch đảo nhân của số thực khác $0$ $a\in\mathbf R$ chính là số nghịch đảo
$a^{-1}$. Tương tự, trong số học có thể định nghĩa nghịch đảo của một số nguyên
$a$ theo môđun $m$, ký hiệu là $a^{-1}\bmod m$, hoặc viết gọn là $a^{-1}$. Đây
là **nghịch đảo nhân theo môđun** (modular multiplicative inverse).

???+ abstract "Nghịch đảo"
    Với các số nguyên khác $0$ $a,m$, nếu tồn tại $b$ sao cho
    $ab\equiv 1\pmod m$, thì gọi $b$ là **nghịch đảo** (inverse) của $a$ theo
    môđun $m$.

Điều này tương đương với việc $b$ là nghiệm của phương trình đồng dư tuyến tính
$ax\equiv 1\pmod m$. Theo tính chất của [phương trình đồng dư tuyến tính](./linear-equation.md),
nghịch đảo $a^{-1}\bmod m$ tồn tại khi và chỉ khi $\gcd(a,m)=1$, tức $a,m$
nguyên tố cùng nhau; khi tồn tại, nó là duy nhất theo môđun $m$.

<span id="cách-tính-một-nghịch-đảo"></span>
## Cách tính một nghịch đảo

Dùng thuật toán Euclid mở rộng hoặc lũy thừa nhị phân, có thể tính nghịch đảo
của một số nguyên trong thời gian $O(\log m)$.

<span id="thuật-toán-euclid-mở-rộng"></span>
### Thuật toán Euclid mở rộng

Tính nghịch đảo tương đương với giải phương trình đồng dư tuyến tính. Vì vậy có
thể dùng [thuật toán Euclid mở rộng](./gcd.md#thuật-toán-euclid-mở-rộng) để tính
nghịch đảo trong thời gian $O(\log\min\{a,m\})$. Đồng thời, vì phương trình
tuyến tính tương ứng với nghịch đảo khá đặc biệt, có thể giản lược một số bước.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/inverse/inverse-1.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/inverse/inverse-1.py:core"
        ```

Thuật toán này áp dụng cho mọi trường hợp nghịch đảo tồn tại.

<span id="phương-pháp-lũy-thừa-nhị-phân"></span>
### Phương pháp lũy thừa nhị phân

Phương pháp này chủ yếu áp dụng khi môđun là số nguyên tố $p$. Khi đó, theo
[định lý nhỏ Fermat](./fermat.md#định-lý-nhỏ-fermat), với mọi $a\perp p$ đều có

$$
a\cdot a^{p-2} = a^{p-1} \equiv 1 \pmod p.
$$

Theo tính duy nhất của nghịch đảo, nghịch đảo $a^{-1}\bmod p$ bằng
$a^{p-2}\bmod p$, nên có thể trực tiếp dùng [lũy thừa nhị phân](../binary-exponentiation.md)
để tính trong thời gian $O(\log p)$:

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/inverse/inverse-2.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/inverse/inverse-2.py:core"
        ```

Về lý thuyết, phương pháp này có thể được mở rộng sang môđun tổng quát $m$ bằng
[định lý Euler](./fermat.md#định-lý-euler), tức dùng
$a^{\varphi(m)-1}\bmod m$ để tính nghịch đảo. Tuy nhiên, tính riêng
[hàm Euler](./euler-totient.md) $\varphi(m)$ không dễ, nên thuật toán này không
hiệu quả trong trường hợp tổng quát.

<span id="cách-tính-nhiều-nghịch-đảo"></span>
## Cách tính nhiều nghịch đảo

Trong một số tình huống, cần xử lý nhanh nghịch đảo của nhiều số nguyên
$a_1,a_2,\cdots,a_n$ theo môđun $m$. Nếu tính từng nghịch đảo riêng lẻ thì tổng
thời gian là $O(n\log m)$. Thực tế, nếu xử lý chung, có thể tính tất cả nghịch
đảo trong thời gian $O(n+\log m)$.

Xét tích tiền tố của dãy $\{a_i\}$:

$$
S_0 = 1,~ S_i = a_iS_{i-1},~ i=1,2,\cdots,n.
$$

Chỉ cần mỗi $a_i$ đều nguyên tố cùng nhau với $m$, tích của chúng $S_n$ cũng
nguyên tố cùng nhau với $m$. Vì vậy có thể dùng thuật toán ở trên để tính
$S_n^{-1}\bmod m$. Vì nghịch đảo của tích bằng tích các nghịch đảo, từ
$S_n^{-1}$ duyệt ngược dãy sẽ tính được nghịch đảo của từng $S_i$:

$$
S_{i-1}^{-1} = a_iS_i^{-1} \bmod m,~ i = n,n-1,\cdots,1.
$$

Từ đó nghịch đảo của từng $a_i$ có thể được tính bằng:

$$
a_i^{-1} = S_{i-1}S_i^{-1} \bmod m,~ i = 1,2,\cdots,n.
$$

Cài đặt tham khảo:

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/inverse/inverse-3.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/inverse/inverse-3.py:core"
        ```

Trong thuật toán chỉ tính nghịch đảo của một phần tử một lần, nên tổng độ phức
tạp thời gian là $O(n+\log m)$.

<span id="tiền-xử-lý-nghịch-đảo-trong-thời-gian-tuyến-tính"></span>
## Tiền xử lý nghịch đảo trong thời gian tuyến tính

Nếu cần tiền xử lý nghịch đảo của $n$ số nguyên dương đầu tiên theo môđun nguyên
tố $p$, có thể dùng hệ thức truy hồi trong phần này để tính trong thời gian
$O(n)$. Phương pháp này thường dùng khi tiền xử lý nghịch đảo của giai thừa các
số nguyên dương đầu tiên trong tính tổ hợp.

Với số nguyên dương $i$ thỏa $1< i < p$, xét phép chia có dư:

$$
p = \left\lfloor \dfrac{p}{i} \right\rfloor i + (p\bmod i).
$$

Lấy hai vế theo môđun số nguyên tố $p$:

$$
0 \equiv \left\lfloor \dfrac{p}{i} \right\rfloor i + (p\bmod i) \pmod p.
$$

Nhân hai vế với $i^{-1}(p\bmod i)^{-1}$, thu được

$$
i^{-1} \equiv - \left\lfloor \dfrac{p}{i} \right\rfloor (p\bmod i)^{-1} \pmod p.
$$

Đây chính là công thức truy hồi tính nghịch đảo trong thời gian tuyến tính. Vì
$p\bmod i < i$, công thức này chuyển bài toán tính $i^{-1}\bmod p$ thành bài
toán nhỏ hơn $(p\bmod i)^{-1}\bmod p$. Do đó, bắt đầu từ
$1^{-1}\bmod p=1$, áp dụng công thức lần lượt cho từng $i$ sẽ thu được nghịch
đảo của $n$ số nguyên đầu tiên trong thời gian $O(n)$.

Cài đặt tham khảo:

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/inverse/inverse-4.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/inverse/inverse-4.py:core"
        ```

Thuật toán này chỉ áp dụng khi môđun là số nguyên tố. Nếu môđun $m$ không phải
số nguyên tố, không thể bảo đảm $m\bmod i$ trong công thức truy hồi vẫn nguyên
tố cùng nhau với $m$, nên nghịch đảo $(m\bmod i)^{-1}$ cần cho truy hồi có thể
không tồn tại. Một ví dụ là $m=8,i=3$: khi đó $m\bmod i = 2$, và không tồn tại
nghịch đảo theo môđun $m$.

Sau khi có công thức truy hồi này, một ý tưởng tự nhiên là dùng đệ quy để tính
nghịch đảo của một số bất kỳ $a$. Mỗi lần đệ quy dùng công thức truy hồi để
chuyển nó thành nghịch đảo của số dư nhỏ hơn $p\bmod a$, cho đến khi số dư bằng
$1$. Hiện chưa rõ độ phức tạp của cách làm này[^linear-recursion], nên khuyến
nghị dùng các phương pháp thông thường đã nêu ở trên.

<span id="bài-tập"></span>
## Bài tập

-   [LOJ 110 Nghịch đảo nhân](https://loj.ac/problem/110)
-   [LOJ 161 Nghịch đảo nhân 2](https://loj.ac/problem/161)
-   [LOJ 2605 [NOIP2012] Phương trình đồng dư](https://loj.ac/problem/2605)
-   [Luogu P2054 [AHOI2005] Xáo bài](https://www.luogu.com.cn/problem/P2054)
-   [LOJ 2034 [SDOI2016] Đếm hoán vị](https://loj.ac/problem/2034)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [Modular multiplicative inverse - Wikipedia](https://en.wikipedia.org/wiki/Modular_multiplicative_inverse)

[^linear-recursion]: [Câu trả lời của riteme trên Zhihu](https://www.zhihu.com/question/59033693/answer/323292359)
    chỉ ra rằng cận trên độ phức tạp đã biết về lý thuyết của cách này là
    $O(p^{1/3+\varepsilon})$, còn trên dữ liệu ngẫu nhiên thực tế thì biểu hiện
    gần với $O(\log p)$.
