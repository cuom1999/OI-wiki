autor: iamtwz, billchenchina, CBW2007, CCXXXI, chinggg, Enter-tainer, eyedeng, FFjet, gaojude, Great-designer, H-J-Granger, Henry-ZHR, hsfzLZH1, Ir1d, kenlig, Konano, ksyx, luoguyuntianming, Marcythm, Menci, NachtgeistW, ouuan, Peanut-Tang, qwqAutomaton, sshwy, StudyingFather, Tiphereth-A, TrisolarisHD, TRSWNCA, Xeonacid, Yuuko10032, Zhangjiacheng2006, Zhoier, Hszzzx, shenshuaijie, kfy666

<span id="giới-thiệu"></span>
## Giới thiệu

**Lũy thừa nhanh** (fast exponentiation), còn gọi là **lũy thừa nhị phân** (binary exponentiation) hoặc **phương pháp bình phương liên tiếp** (exponentiation by squaring), là một kỹ thuật nhỏ để tính $a^n$ trong thời gian $\Theta(\log n)$, trong khi cách tính trực tiếp cần thời gian $\Theta(n)$.

Kỹ thuật này áp dụng được trong mọi tình huống mà phép nhân của $a$ có tính kết hợp, chẳng hạn lũy thừa theo mô đun, lũy thừa ma trận, v.v. Xem thêm phần [Ứng dụng](#ứng-dụng) ở bên dưới.

<span id="quy-trình"></span>
## Quy trình

Tính lũy thừa bậc $n$ của $a$ nghĩa là nhân $n$ thừa số $a$ với nhau: $a^{n} = \underbrace{a \times a \cdots \times a}_{n\text{ thừa số }a}$. Tuy nhiên, khi $n$ quá lớn hoặc chi phí cho một phép nhân quá cao, cách này sẽ không còn phù hợp. Ý tưởng của lũy thừa nhị phân là chia bài toán lũy thừa thành các bài toán nhỏ hơn theo **biểu diễn nhị phân** của số mũ.

???+ example "Ví dụ"
    Giả sử cần tính $3^{13}$. Nếu khai triển thành tích liên tiếp thì cần $13-1=12$ phép nhân. Tuy nhiên, do
    
    $$
    3^{13} = 3^{(1101)_2} = 3^8 \times 3^4 \times 3^1,
    $$
    
    nên nếu có thể nhanh chóng tính được $3^{1},3^{2},3^{4},3^{8}$, chỉ cần thêm $2$ phép nhân để thu được giá trị của $3^{13}$. Vì vậy, chỉ cần một cách nhanh để tính dãy các lũy thừa $2^k$ của $3$ nói trên. Điều này khá đơn giản, vì trong dãy đó, mỗi phần tử (trừ phần tử đầu tiên) đều là bình phương của phần tử đứng ngay trước nó.
    
    Từ phân tích trên, quá trình tính $3^{13}$ là:
    
    $$
    \begin{aligned}
    3^1 &= 3, \\
    3^2 &= \left(3^1\right)^2 = 3^2 = 9, \\
    3^4 &= \left(3^2\right)^2 = 9^2 = 81, \\
    3^8 &= \left(3^4\right)^2 = 81^2 = 6561, \\
    3^{13} &= 6561 \times 81 \times 3 = 1594323.
    \end{aligned}
    $$
    
    Trong toàn bộ quá trình chỉ cần $5$ phép nhân.

Đó là ý tưởng cơ bản của lũy thừa nhanh. Về cách cài đặt cụ thể, có hai phiên bản thường gặp.

<span id="phiên-bản-lặp"></span>
### Phiên bản lặp

Giả sử biểu diễn nhị phân của $n$ là $(n_tn_{t-1}\cdots n_1n_0)_2$, nghĩa là

$$
n = n_t2^t + n_{t-1}2^{t-1} + \cdots + n_12^1 + n_02^0,
$$

trong đó $n_i\in\{0,1\}$. Khi đó có

$$
\begin{aligned}
a^n & = a^{n_t2^t + n_{t-1}2^{t-1} + \cdots + n_12^1 + n_02^0}\\
& = a^{n_0 2^0} \times a^{n_1 2^1}\times \cdots \times a^{n_{t-1}2^{t-1}} \times a^{n_t2^t}.
\end{aligned}
$$

Lưu ý rằng chỉ các hạng ứng với $n_i=1$ mới thực sự xuất hiện trong phép nhân.

Dựa trên biểu thức này, trước hết có thể tính $\Theta(\log n)$ giá trị lũy thừa dạng $2^k$ của $a$ trong thời gian $\Theta(\log n)$, rồi dùng thêm $\Theta(\log n)$ thời gian để chọn các lũy thừa tương ứng với bit nhị phân bằng $1$ và nhân chúng vào kết quả cuối cùng. Đây chính là cách cài đặt lũy thừa nhanh dạng lặp.

Mã giả như sau:

$$
\begin{array}{l}
\textbf{Thuật toán }\text{FastPow}(a, n): \\
\textbf{Đầu vào. }\text{Cơ số }a\text{ và số mũ }n.\\
\textbf{Đầu ra. }\text{Lũy thừa }a^n.\\
\textbf{Phương pháp.}\\
\begin{array}{ll}
1 & \textit{result}\gets\mathrm{Id}\\
2 & \textbf{trong khi }n > 0\textbf{ thực hiện}\\
3 & \qquad \textbf{nếu }n \bmod 2 = 1\textbf{ thì}\\
4 & \qquad \qquad \textit{result} \gets \textit{result}\cdot a\\
5 & \qquad \textbf{kết thúc nếu}\\
6 & \qquad a \gets a \cdot a\\
7 & \qquad n \gets n / 2\\
8 & \textbf{kết thúc vòng lặp}\\
9 & \textbf{trả về }\textit{result}
\end{array}
\end{array}
$$

Khi dùng phương pháp này để tính lũy thừa nhanh, cần $\Theta(\log n)$ phép nhân.

<span id="phiên-bản-đệ-quy"></span>
### Phiên bản đệ quy

Quy trình trên cũng có thể được cài đặt bằng đệ quy. Lưu ý rằng khai triển nhị phân của số mũ $n$ có thể được viết đệ quy như sau:

$$
(n_tn_{t-1}\cdots n_1n_0)_2 = 2 \times (n_tn_{t-1}\cdots n_1)_2 + n_0.
$$

Do đó, lũy thừa $a^n$ có thể được tính đệ quy theo công thức

$$
a^n = \begin{cases}
1, & n = 0,\\
(a^{\lfloor n/2\rfloor})^2, & n > 0 \text{ và }n\text{ chẵn},\\
(a^{\lfloor n/2\rfloor})^2\cdot a, & n > 0 \text{ và }n\text{ lẻ}.\\
\end{cases}
$$

Đây là cách cài đặt lũy thừa nhanh dạng đệ quy.

Mã giả như sau:

$$
\begin{array}{l}
\textbf{Thuật toán }\text{FastPow}(a, n): \\
\textbf{Đầu vào. }\text{Cơ số }a\text{ và số mũ }n.\\
\textbf{Đầu ra. }\text{Lũy thừa }a^n.\\
\textbf{Phương pháp.}\\
\begin{array}{ll}
1 & \textbf{nếu }n = 0\textbf{ thì}\\
2 & \qquad \textbf{trả về }\mathrm{Id}\\
3 & \textbf{kết thúc nếu}\\
4 & \textit{result} \gets \text{FastPow}(a, n / 2) \\
5 & \textbf{nếu }n\bmod 2 = 0\textbf{ thì}\\
6 & \qquad \textbf{trả về }\textit{result}\cdot\textit{result}\\
7 & \textbf{ngược lại}\\
8 & \qquad \textbf{trả về }\textit{result}\cdot\textit{result}\cdot a\\
9 & \textbf{kết thúc nếu}
\end{array}
\end{array}
$$

Khi dùng phương pháp này để tính lũy thừa nhanh, cần $\Theta(\log n)$ tầng đệ quy và cũng cần $\Theta(\log n)$ phép nhân. Dù độ phức tạp giống nhau, bản lặp thường nhanh hơn trong thực tế vì bản đệ quy có thêm chi phí gọi hàm.

<span id="ứng-dụng"></span>
## Ứng dụng

<span id="lũy-thừa-theo-mô-đun"></span>
### Lũy thừa theo mô đun

???+ example "[Luogu P1226 - Mẫu lũy thừa nhanh](https://www.luogu.com.cn/problem/P1226)"
    Cho ba số nguyên $a,b,p$, cần tính $a^b\bmod p$, trong đó $p\ge 2$.

Đây là một ứng dụng rất thường gặp; chẳng hạn, nó có thể được dùng để tính nghịch đảo nhân theo mô đun. Vì phép lấy mô đun không làm ảnh hưởng đến phép nhân, chỉ cần lấy mô đun trong quá trình tính.

Trước hết, có thể cài đặt trực tiếp theo phương pháp đệ quy ở trên:

???+ note "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/binary-exponentiation/luogu-P1226-1.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/binary-exponentiation/luogu-P1226-1.py:core"
        ```

Cách cài đặt thứ hai là dạng không đệ quy. Trong vòng lặp, nó nhân dồn vào đáp án những lũy thừa tương ứng với các bit nhị phân bằng 1. Tuy hai cách có cùng độ phức tạp lý thuyết, cách thứ hai thường nhanh hơn trong thực tế vì không phải trả chi phí đệ quy.

???+ note "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/binary-exponentiation/luogu-P1226-2.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/binary-exponentiation/luogu-P1226-2.py:core"
        ```

???+ warning "Lưu ý"
    -   Thông thường mô đun lớn hơn $1$. Trong trường hợp rất đặc biệt, mô đun $p$ có thể bằng $1$; khi đó cần xét riêng trường hợp $b=0$.
    -   Khi số mũ rất lớn, cần dùng [định lý Euler mở rộng](./number-theory/fermat.md#định-lý-euler-mở-rộng) để hạ bậc trước khi tính.

<span id="tính-số-fibonacci"></span>
### Tính số Fibonacci

Dựa vào công thức truy hồi của dãy Fibonacci $F_n = F_{n-1} + F_{n-2}$, có thể xây dựng một ma trận $2\times 2$ để biểu diễn phép biến đổi từ $F_i,F_{i+1}$ sang $F_{i+1},F_{i+2}$. Khi cần tính lũy thừa bậc $n$ của ma trận này, dùng ý tưởng lũy thừa nhanh để thu được kết quả trong thời gian $\Theta(\log n)$. Xem thêm chi tiết tại [dãy Fibonacci](./combinatorics/fibonacci.md); phần cài đặt lũy thừa nhanh cho ma trận có thể tham khảo ở [tăng tốc truy hồi bằng ma trận](../math/linear-algebra/matrix.md#dùng-ma-trận-tăng-tốc-truy-hồi).

<span id="hoán-vị-nhiều-lần"></span>
### Hoán vị nhiều lần

???+ note "Mô tả bài toán"
    Cho một dãy độ dài $n$ và một hoán vị, cần áp dụng hoán vị đó lên dãy $k$ lần.

Chỉ cần lấy lũy thừa bậc $k$ của hoán vị này, rồi áp dụng nó lên dãy. Độ phức tạp thời gian là $O(n \log k)$. Xem thêm chi tiết tại [hợp thành hoán vị](./permutation.md#hợp-thành).

???+ warning "Lưu ý"
    Nếu dựng đồ thị cho hoán vị rồi xử lý riêng từng chu trình bằng cách lấy lũy thừa bậc $k$ (thực chất tương đương với lấy $k$ theo mô đun độ dài chu trình), bài toán có thể được giải trong thời gian $O(n)$.

<span id="tăng-tốc-thao-tác-trên-tập-điểm-trong-hình-học"></span>
### Tăng tốc thao tác trên tập điểm trong hình học

???+ example "[HDU 4087 A Letter to Programmers](https://acm.hdu.edu.cn/showproblem.php?pid=4087)"
    Cho $n$ điểm $p_i$ trong không gian ba chiều, cần áp dụng $m$ thao tác lên các điểm này. Có 3 loại thao tác:
    
    1.  Tịnh tiến vị trí điểm theo một véc-tơ nào đó (Shift).
    2.  Co giãn tọa độ của điểm theo một tỉ lệ (Scale).
    3.  Quay quanh một đường thẳng nào đó (Rotate).
    
    Ngoài ra còn có một thao tác đặc biệt: lặp lại một dãy thao tác $k$ lần (Repeat). Các thao tác Repeat có thể lồng nhau. Cần xuất tọa độ của từng điểm sau khi thực hiện xong mọi thao tác.

Theo nội dung trong [véc-tơ và ma trận](./linear-algebra/vector.md#vectơ-và-ma-trận), mỗi thao tác đều có thể được biểu diễn bằng một ma trận biến đổi, và một chuỗi biến đổi liên tiếp có thể được biểu diễn bằng tích các ma trận. Một thao tác Repeat tương đương với việc lấy lũy thừa bậc $k$ của một ma trận. Nhờ vậy, có thể tính ma trận cuối cùng của toàn bộ dãy biến đổi trong thời gian $O(m \log k)$. Cuối cùng áp dụng ma trận đó lên $n$ điểm, tổng độ phức tạp là $O(n + m \log k)$.

<span id="đếm-đường-đi-có-độ-dài-cố-định"></span>
### Đếm đường đi có độ dài cố định

???+ note "Mô tả bài toán"
    Cho một đồ thị có hướng (trọng số mỗi cạnh bằng 1), cần tính số đường đi độ dài $k$ từ $u$ đến $v$ với mọi cặp đỉnh $u,v$.

Lấy lũy thừa bậc $k$ của ma trận kề $M$ của đồ thị. Khi đó $M_{i,j}$ biểu thị số đường đi độ dài $k$ từ $i$ đến $j$. Độ phức tạp của thuật toán này là $O(n^3 \log k)$. Chi tiết của thuật toán có thể xem ở trang [ma trận](./linear-algebra/matrix.md#đếm-đường-đi-độ-dài-cố-định).

<span id="phép-nhân-số-nguyên-theo-mô-đun"></span>
### Phép nhân số nguyên theo mô đun

???+ note "Mô tả bài toán"
    Cho các số nguyên không âm $a,b$ và số nguyên dương $m$, cần tính $a\times b\bmod m$, trong đó $a,b\le m\le 10^{18}$.

Tương tự ý tưởng lũy thừa nhị phân, lần này biểu diễn một trong hai thừa số dưới dạng tổng của một số lũy thừa nguyên của 2. Khi thực hiện phép nhân một số với 2 rồi lấy mô đun, có thể chuyển nó thành phép cộng trừ để tránh tràn số nguyên. Nhờ vậy bài toán có thể được giải trong thời gian $O(\log m)$. Công thức đệ quy như sau:

$$
a \cdot b = \begin{cases}
0 &\text{nếu }a = 0 \\
2 \cdot \frac{a}{2} \cdot b &\text{nếu }a > 0 \text{ và }a \text{ chẵn} \\
2 \cdot \frac{a-1}{2} \cdot b + b &\text{nếu }a > 0 \text{ và }a \text{ lẻ}
\end{cases}
$$

Tuy nhiên, trong thực tế, phương pháp này không có hiệu quả thời gian tốt vì đưa vào độ phức tạp tính toán lớn hơn. Khi lập trình, với phép nhân có mô đun trong phạm vi `long long`, thường dùng [nhân nhanh](./number-theory/mod-arithmetic.md#nhân-nhanh).

<span id="lũy-thừa-nhanh-độ-chính-xác-cao"></span>
### Lũy thừa nhanh độ chính xác cao

Kỹ năng cần có: [nhân số nguyên lớn](./bignum.md#phép-nhân)

???+ example "[Luogu P1045 - \[NOIP 2003 Nhóm phổ cập\] Số Mersenne](https://www.luogu.com.cn/problem/P1045)"
    Cho số nguyên $P$ ($1000 < P < 3100000$), cần tính số chữ số của $2^P−1$ và $500$ chữ số cuối cùng của nó (biểu diễn theo hệ thập phân). Nếu chưa đủ $500$ chữ số thì thêm các chữ số 0 ở đầu.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/binary-exponentiation/luogu-P1045.cpp"
    ```

<span id="lũy-thừa-nhanh-tiền-xử-lý-với-cơ-số-cố-định"></span>
## Lũy thừa nhanh tiền xử lý với cơ số cố định

Khi cơ số $a$ cố định, có thể dùng [tư tưởng phân khối](../ds/decompose.md) để tiền xử lý trong một khoảng thời gian nhất định, rồi trả lời mỗi truy vấn lũy thừa trong thời gian $O(1)$. Thuật toán này cũng thường được gọi là lũy thừa tốc độ ánh sáng. Quy trình như sau:

1.  Chọn một số $s$, tiền xử lý các giá trị $a^0,a^1,\cdots,a^{s-1}$ và $a^0,a^s,\cdots,a^{\lfloor p/s\rfloor s}$ rồi lưu vào hai mảng;
2.  Với mỗi truy vấn $a^b$, tách $b$ thành $\lfloor b/s\rfloor s+(b\bmod s)$, khi đó $a^b=a^{\lfloor b/s\rfloor s}\cdot a^{b\bmod s}$, nên có thể tìm đáp án trong thời gian $O(1)$.

Giả sử phạm vi của số mũ $b$ là $[0,n]$, khi đó độ dài khối $s$ thường được chọn là $\sqrt{n}$ hoặc một lũy thừa của $2$ gần với giá trị này. Chọn $\sqrt{n}$ cho độ phức tạp tiền xử lý tối ưu $O(\sqrt{n})$, còn chọn lũy thừa của $2$ giúp đơn giản hóa phép tính bằng thao tác bit.

Đặc biệt, đối với phép tính lũy thừa theo mô đun, việc cơ số $a$ giống nhau cũng ngầm yêu cầu mô đun $m$ phải giống nhau. Theo [định lý Euler mở rộng](./number-theory/fermat.md#định-lý-euler-mở-rộng), với mô đun bất kỳ $m$, cận trên của phạm vi số mũ cần tiền xử lý là $n = 2\varphi(m)$; với mô đun nguyên tố $p$, cận trên là $n = p - 1$. Trong cả hai trường hợp, độ phức tạp tiền xử lý đều là $O(\sqrt{m})$.

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/binary-exponentiation/pre-exp.cpp:core"
    ```

<span id="bài-tập"></span>
## Bài tập

-   [UVa 1230 - MODEX](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3671)
-   [UVa 374 - Big Mod](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=310)
-   [UVa 11029 - Leading and Trailing](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1970)
-   [Codeforces - Parking Lot](http://codeforces.com/problemset/problem/630/I)
-   [SPOJ - The last digit](http://www.spoj.com/problems/LASTDIG/)
-   [SPOJ - Locker](http://www.spoj.com/problems/LOCKER/)
-   [SPOJ - Just add it](http://www.spoj.com/problems/ZSUM/)

**Một phần nội dung của trang này được dịch từ bài viết [Бинарное возведение в степень](http://e-maxx.ru/algo/binary_pow) và bản dịch tiếng Anh của bài viết đó, [Binary Exponentiation](https://cp-algorithms.com/algebra/binary-exp.html). Bản tiếng Nga được cấp phép theo Public Domain + Leave a Link; bản tiếng Anh được cấp phép theo CC-BY-SA 4.0.**
