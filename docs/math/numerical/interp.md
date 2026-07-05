author: AtomAlpaca, billchenchina, caibyte, Chrogeek, Early0v0, EndlessCheng, Enter-tainer, Henry-ZHR, hly1204, hsfzLZH1, Ir1d, Ghastlcon, kenlig, Marcythm, megakite, Peanut-Tang, qwqAutomaton, qz-cqy, StudyingFather, swift-zym, swiftqwq, Tiphereth-A, TrisolarisHD, Watersail2005, x4Cx58x54, Xeonacid, xiaopangfeiyu, YanWQ-monad

<span id="mở-đầu"></span>
## Mở đầu

Nội suy là phương pháp suy ra các điểm dữ liệu mới trong một phạm vi nhất định từ những điểm dữ liệu rời rạc đã biết. Phương pháp nội suy thường được dùng trong khớp hàm.

Ví dụ, với các điểm dữ liệu:

| $x$    | $0$ | $1$      | $2$      | $3$      | $4$       | $5$       | $6$       |
| ------ | --- | -------- | -------- | -------- | --------- | --------- | --------- |
| $f(x)$ | $0$ | $0.8415$ | $0.9093$ | $0.1411$ | $-0.7568$ | $-0.9589$ | $-0.2794$ |

![](../images/interp-1.svg)

Trong đó $f(x)$ chưa biết; phương pháp nội suy có thể ước lượng các điểm dữ liệu chưa biết bằng cách khớp $f(x)$ theo một dạng nhất định.

Chẳng hạn, ta có thể dùng hàm tuyến tính từng đoạn để khớp $f(x)$:

![](../images/interp-2.svg)

Cách nội suy này được gọi là [nội suy tuyến tính](https://en.wikipedia.org/wiki/Linear_interpolation).

Ta cũng có thể dùng đa thức để khớp $f(x)$:

![](../images/interp-3.svg)

Cách nội suy này được gọi là [nội suy đa thức](https://en.wikipedia.org/wiki/Polynomial_interpolation).

Dạng tổng quát của nội suy đa thức như sau:

???+ note "Nội suy đa thức"
    Với $n+1$ điểm đã biết $(x_0,y_0),(x_1,y_1),\dots,(x_n,y_n)$, hãy tìm đa thức $f(x)$ có dạng $f(x)=\sum_{i=0}^n a_ix^i$ và thỏa mãn
    
    $$
    f(x_i)=y_i,\qquad\forall i=0,1,\dots,n
    $$
    
    với mọi điểm đã cho.

Dưới đây giới thiệu hai phương pháp trong nội suy đa thức: nội suy Lagrange và nội suy Newton. Không khó để chứng minh hai phương pháp này cho cùng một kết quả.

<span id="phương-pháp-nội-suy-lagrange"></span>
## Phương pháp nội suy Lagrange

Ta cần xây dựng một hàm $f(x)$ đi qua các điểm $P_1(x_1, y_1), P_2(x_2,y_2),\cdots,P_n(x_n,y_n)$. Trước hết, đặt hình chiếu của điểm thứ $i$ lên trục $x$ là $P_i^{\prime}(x_i,0)$.

Xét việc xây dựng $n$ hàm $f_1(x), f_2(x), \cdots, f_n(x)$ sao cho với hàm thứ $i$, tức $f_i(x)$, đồ thị của nó đi qua $\begin{cases}P_j^{\prime}(x_j,0),(j\neq i)\\P_i(x_i,y_i)\end{cases}$. Khi đó hàm cần tìm là $f(x)=\sum\limits_{i=1}^nf_i(x)$.

Vì vậy có thể đặt $f_i(x)=a\cdot\prod_{j\neq i}(x-x_j)$. Thay điểm $P_i(x_i,y_i)$ vào, ta được $a=\dfrac{y_i}{\prod_{j\neq i} (x_i-x_j)}$, do đó

$$
f_i(x)=y_i\cdot\dfrac{\prod_{j\neq i} (x-x_j)}{\prod_{j\neq i} (x_i-x_j)}=y_i\cdot\prod_{j\neq i}\dfrac{x-x_j}{x_i-x_j}
$$

Từ đó suy ra dạng của nội suy Lagrange:

$$
f(x)=\sum_{i=1}^ny_i\cdot\prod_{j\neq i}\dfrac{x-x_j}{x_i-x_j}
$$

Cài đặt trực tiếp có độ phức tạp thời gian $O(n^2)$; có thể tối ưu xuống $O(n\log^2 n)$, xem [nội suy nhanh đa thức](../poly/multipoint-eval-interpolation.md#nội-suy-nhanh-đa-thức).

???+ note "[Luogu P4781 [Mẫu] Nội suy Lagrange](https://www.luogu.com.cn/problem/P4781)"
    Cho $n$ cặp điểm $(x_i,y_i)$ và $k$, đồng thời với mọi $i,j$ có $i\neq j \iff x_i\neq x_j$, $f(x_i)\equiv y_i\pmod{998244353}$ và $\deg(f(x)) < n$ (định nghĩa $\deg(0)=-\infty$). Hãy tính $f(k)\bmod{998244353}$.
    
    ??? note "Lời giải"
        Trong bài này chỉ cần tìm giá trị $f(k)$, nên khi tính công thức trên có thể thay trực tiếp $k$ vào. Đôi khi ta cần tính giá trị nhiều lần hoặc thực hiện các thao tác phức tạp hơn; khi đó cần tìm các hệ số của $f$. Mã nguồn đưa ra một cách cài đặt để tìm các hệ số.
        
        $$
        f(k)=\sum_{i=1}^{n}y_i\prod_{j\neq i }\frac{k-x_j}{x_i-x_j}
        $$
        
        Bài này còn cần tính nghịch đảo modulo. Nếu trước tiên lần lượt tính tử số và mẫu số, rồi nhân tử số với nghịch đảo của mẫu số và cộng vào đáp án cuối cùng, nút thắt độ phức tạp thời gian sẽ không nằm ở việc tính nghịch đảo; độ phức tạp là $O(n^2)$.
        
        Vì các phép toán được thực hiện dưới modulo cố định $998244353$, ở đây ta tạm xem độ phức tạp thời gian của việc tính nghịch đảo nhân là hằng số.
    
    ??? note "Cài đặt mã nguồn"
        ```cpp
        --8<-- "docs/math/code/numerical/interp/interp_1.cpp"
        ```

<span id="nội-suy-lagrange-khi-hoành-độ-là-các-số-nguyên-liên-tiếp"></span>
### Nội suy Lagrange khi hoành độ là các số nguyên liên tiếp

Nếu hoành độ của các điểm đã biết là các số nguyên liên tiếp, ta có thể nội suy trong $O(n)$.

Đặt đa thức cần tìm là $f(x)$, ta đã biết $f(1),\cdots,f(n+1)$ ($1\le i\le n+1$). Xét thay vào công thức nội suy ở trên:

$$
\begin{aligned}
f(x)&=\sum\limits_{i=1}^{n+1}y_i\prod\limits_{j\ne i}\frac{x-x_j}{x_i-x_j}\\
&=\sum\limits_{i=1}^{n+1}y_i\prod\limits_{j\ne i}\frac{x-j}{i-j}
\end{aligned}
$$

Với tích phía sau, có thể xét riêng tử số và mẫu số. Không khó để thấy tử số là:

$$
\dfrac{\prod\limits_{j=1}^{n+1}(x-j)}{x-i}
$$

Tích $i-j$ ở mẫu số có thể tách thành hai đoạn giai thừa:

$$
(-1)^{n+1-i}\cdot(i-1)!\cdot(n+1-i)!
$$

Do đó công thức nội suy khi hoành độ là $1,\cdots,n+1$ là:

$$
f(x)=\sum\limits_{i=1}^{n+1}(-1)^{n+1-i}y_i\cdot\frac{\prod\limits_{j=1}^{n+1}(x-j)}{(i-1)!(n+1-i)!(x-i)}
$$

Tiền xử lý tích tiền tố và hậu tố của $(x-i)$, giai thừa và nghịch đảo giai thừa, rồi thay vào công thức này; độ phức tạp là $O(n)$.

???+ note "Bài ví dụ [CF622F The Sum of the k-th Powers](https://codeforces.com/contest/622/problem/F)"
    Cho $n,k$, hãy tính giá trị của $\sum\limits_{i=1}^ni^k$ modulo $10^9+7$.
    
    ??? note "Lời giải"
        Trong bài này, đáp án là một đa thức bậc $k+1$, vì vậy ta có thể dùng sàng tuyến tính để tính các giá trị $1^i,\cdots,(k+2)^i$, rồi nội suy trong $O(n)$.
        
        Cũng có thể dùng kiến thức tổ hợp để suy ra công thức sau từ phương pháp sai phân:
        
        $$
        f(x)=\sum_{i=1}^{n+1}\binom{x-1}{i-1}\sum_{j=1}^{i}(-1)^{i+j}\binom{i-1}{j-1}y_{j}=\sum\limits_{i=1}^{n+1}y_i\cdot\frac{\prod\limits_{j=1}^{n+1}(x-j)}{(x-i)\cdot(-1)^{n+1-i}\cdot(i-1)!\cdot(n+1-i)!}
        $$
    
    ??? note "Cài đặt mã nguồn"
        ```cpp
        --8<-- "docs/math/code/numerical/interp/interp_2.cpp"
        ```

<span id="phương-pháp-nội-suy-newton"></span>
## Phương pháp nội suy Newton

Nội suy Newton là phương pháp nội suy dựa trên sai phân bậc cao; ưu điểm của nó là hỗ trợ chèn điểm dữ liệu mới trong $O(n)$.

Để thực hiện việc chèn điểm dữ liệu mới trong $O(n)$, đặt:

$$
f(x)=\sum_{j=0}^n a_jn_j(x)
$$

Trong đó $n_j(x):=\prod_{i=0}^{j-1}(x-x_i)$ được gọi là **cơ sở Newton** (Newton basis).

Nếu tìm được $a_j$, ta sẽ thu được đa thức nội suy của $f(x)$. Ta định nghĩa **sai phân chia tiến** (forward divided differences) như sau:

$$
\begin{aligned}
    \lbrack y_k\rbrack  & := y_k,                                                                & k=0,\dots,n, \\
    [y_k,\dots,y_{k+j}] & := \dfrac{[y_{k+1},\dots,y_{k+j}]-[y_k,\dots,y_{k+j-1}]}{x_{k+j}-x_k}, & k=0,\dots,n-j,~j=1,\dots,n.
\end{aligned}
$$

Khi đó:

$$
\begin{aligned}
    f(x)&=[y_0]+[y_0,y_1](x-x_0)+\dots+[y_0,\dots,y_n](x-x_0)\dots(x-x_{n-1})\\
    &=\sum_{j=0}^n [y_0,\dots,y_j]n_j(x)
\end{aligned}
$$

Đây chính là dạng của nội suy Newton. Cài đặt trực tiếp có độ phức tạp thời gian $O(n^2)$.

Nếu các điểm mẫu cách đều nhau (tức $x_i=x_0+ih$, $i=1,\dots,n$), ta có thể suy ra

$$
[y_k,\dots,y_{k+j}]=\frac{1}{j!h^j}\Delta^{(j)}y_k,
$$

trong đó $\Delta^{(j)}y_k$ là **sai phân tiến** (forward differences), được định nghĩa như sau:

$$
\begin{aligned}
    \Delta^{(0)}y_k & := y_k,                                       & k=0,\dots,n, \\
    \Delta^{(j)}y_k & := \Delta^{(j-1)} y_{k+1}-\Delta^{(j-1)} y_k, & k=0,\dots,n-j,~j=1,\dots,n.
\end{aligned}
$$

Đặt $x=x_0+sh$, khi đó công thức nội suy Newton có thể được biến đổi thành

$$
f(x)=\sum_{j=0}^n \binom{s}{j}j!h^j[y_0,\dots,y_j]=\sum_{j=0}^n \binom{s}{j}\Delta^{(j)}y_0.
$$

??? note "Cài đặt mã nguồn ([Luogu P4781 [Mẫu] Nội suy Lagrange](https://www.luogu.com.cn/problem/P4781))"
    ```cpp
    --8<-- "docs/math/code/numerical/interp/interp_3.cpp"
    ```

<span id="nội-suy-newton-khi-hoành-độ-là-các-số-nguyên-liên-tiếp"></span>
### Nội suy Newton khi hoành độ là các số nguyên liên tiếp

Ví dụ: cần tìm các hệ số của đa thức $f(x)=\sum_{i=0}^{3} a_ix^i$, biết các giá trị từ $f(1)$ đến $f(6)$ lần lượt là $1, 5, 14, 30, 55, 91$.

$$
\begin{array}{cccccccccccc}
1 &    &  5 &    & 14 &    & 30 &    & 55 &    & 91 & \\
&  4 &    &  9 &    & 16 &    & 25  &    & 36 & \\
&    &  5 &    &  7 &    &  9 &    &  11 & \\
&    &    &  2 &    &  2 &    &  2 & \\
\end{array}
$$

Hàng đầu tiên là $n$ giá trị liên tiếp đầu tiên của $f(x)$; mỗi hàng sau đó là hiệu của hai hạng kề nhau tương ứng trong hàng trước. Có thể quan sát rằng nếu thực hiện thao tác này đủ nhiều lần (với điều kiện $f(x)$ là đa thức), cuối cùng ta luôn thu được một hằng số.

Tính được phần tử đầu tiên của sai phân bậc $i-1$ là $\sum_{j=1}^{i}(-1)^{i+j}\binom{i-1}{j-1}f(j)$; đóng góp của phần tử đầu tiên của sai phân bậc $i-1$ vào $f(k)$ là $\binom{k-1}{i-1}$ lần.

$$
f(k)=\sum_{i=1}^n\binom{k-1}{i-1}\sum_{j=1}^{i}(-1)^{i+j}\binom{i-1}{j-1}f(j)
$$

Độ phức tạp thời gian là $O(n^2)$.

<span id="cài-đặt-trong-c"></span>
## Cài đặt trong C++

Từ C++20 trở đi, thư viện chuẩn bổ sung các hàm [`std::midpoint`](https://en.cppreference.com/w/cpp/numeric/midpoint) và [`std::lerp`](https://en.cppreference.com/w/cpp/numeric/lerp), lần lượt dùng để tính trung điểm và nội suy tuyến tính.

<span id="bài-tập"></span>
## Bài tập

-   ["NOIP2020" Số bước WeChat](https://loj.ac/p/3389)
-   ["Tuyển chọn liên tỉnh 2022" Điền cây](https://loj.ac/p/3701)
-   ["NOI2019" Robot](https://loj.ac/p/3157)

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

1.  [Interpolation - Wikipedia](https://en.wikipedia.org/wiki/Interpolation)
2.  [Newton polynomial - Wikipedia](https://en.wikipedia.org/wiki/Newton_polynomial)
