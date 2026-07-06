## Giới thiệu

Bổ đề Lindström–Gessel–Viennot, tức bổ đề LGV, có thể dùng để xử lý các bài toán như đếm các đường đi không giao nhau trên đồ thị có hướng không chu trình.

Kiến thức chuẩn bị: phần cơ bản trong [các khái niệm liên quan đến đồ thị](./concept.md), [ma trận](../math/linear-algebra/matrix.md), [khử Gauss để tính định thức](../math/numerical/gauss.md).

Bổ đề LGV chỉ áp dụng cho **đồ thị có hướng không chu trình**.

## Định nghĩa

$\omega(P)$ biểu thị tích trọng số của tất cả các cạnh trên đường đi $P$. (Khi đếm số đường đi, có thể đặt trọng số của mọi cạnh bằng $1$.) (Trọng số cạnh cũng có thể là hàm sinh.)

$e(u, v)$ biểu thị tổng $\omega(P)$ trên **mọi** đường đi $P$ từ $u$ đến $v$, tức $e(u, v)=\sum\limits_{P:u\rightarrow v}\omega(P)$.

Tập điểm xuất phát $A$ là một tập con của tập đỉnh trong đồ thị có hướng không chu trình, có kích thước $n$.

Tập điểm kết thúc $B$ cũng là một tập con của tập đỉnh trong đồ thị có hướng không chu trình, và cũng có kích thước $n$.

Một bộ các đường đi không giao nhau theo đỉnh $S$ từ $A\rightarrow B$: $S_i$ là một đường đi từ $A_i$ đến $B_{\sigma(S)_i}$ ($\sigma(S)$ là một hoán vị), và với mọi $i\ne j$, $S_i$ và $S_j$ không có đỉnh chung.

$t(\sigma)$ biểu thị số cặp nghịch thế của hoán vị $\sigma$.

## Bổ đề

$$
M = \begin{bmatrix}e(A_1,B_1)&e(A_1,B_2)&\cdots&e(A_1,B_n)\\
e(A_2,B_1)&e(A_2,B_2)&\cdots&e(A_2,B_n)\\
\vdots&\vdots&\ddots&\vdots\\
e(A_n,B_1)&e(A_n,B_2)&\cdots&e(A_n,B_n)\end{bmatrix}
$$

$$
\det(M)=\sum\limits_{S:A\rightarrow B}(-1)^{t(\sigma(S))}\prod\limits_{i=1}^n \omega(S_i)
$$

Trong đó $\sum\limits_{S:A\rightarrow B}$ biểu thị tổng trên mọi bộ đường đi không giao nhau theo đỉnh $S$ từ $A\rightarrow B$ thỏa mãn yêu cầu ở trên.

### Chứng minh

Từ định nghĩa của định thức, có

$$
\begin{align}
\det(M)&=\sum_{\sigma}(-1)^{t(\sigma)}\prod_{i=1}^n e(a_i,b_{\sigma(i)})\\
&=\sum_{\sigma}(-1)^{t(\sigma)}\prod_{i=1}^n \sum_{P:a_i\to b_{\sigma(i)}} \omega(P)
\end{align}
$$

Nhận thấy $\prod\limits_{i=1}^n \sum\limits_{P:a_i\to b_{\sigma(i)}} \omega(P)$ thực chất là tổng $\omega(P)$ của tất cả các bộ đường đi $P$ từ $A$ đến $B$ có hoán vị là $\sigma$.

$$
\begin{align}
&\sum_{\sigma}(-1)^{t(\sigma)}\prod_{i=1}^n \sum_{P:a_i\to b_{\sigma(i)}} \omega(P)\\
=&\sum_{\sigma}(-1)^{t(\sigma)}\sum_{P=\sigma}\omega(P)\\
=&\sum_{P:A\to B}(-1)^{t(\sigma)}\prod_{i=1}^n \omega(P_i)
\end{align}
$$

Trong đó $P$ là một bộ đường đi tùy ý.

Gọi $U$ là các bộ đường đi không giao nhau theo đỉnh, và $V$ là các bộ đường đi có giao nhau,

$$
\begin{align}
&\sum_{P:A\to B}(-1)^{t(\sigma)}\prod_{i=1}^n \omega(P_i)\\
=&\sum_{U:A\to B}(-1)^{t(U)}\prod_{i=1}^n \omega(U_i)+\sum_{V:A\to B}(-1)^{t(V)}\prod_{i=1}^n \omega(V_i)
\end{align}
$$

Giả sử trong $P$ tồn tại một bộ đường đi giao nhau $P_i:a_1 \to u \to b_1,P_j:a_2 \to u \to b_2$. Khi đó tồn tại một bộ đường đi giao nhau tương ứng $P_i'=a_1\to u\to b_2,P_j'=a_2\to u\to b_1$, còn các đường đi khác của $P'$ giống với $P$. Suy ra $\omega(P)=\omega(P'),t(P)=t(P')\pm 1$.

Do đó có $\sum\limits_{V:A\to B}(-1)^{t(\sigma)}\prod\limits_{i=1}^n \omega(V_i)=0$.

Vậy $\det(M)=\sum\limits_{U:A\to B}(-1)^{t(U)}\prod\limits_{i=1}^n \omega(U_i)$.

Chứng minh hoàn tất[^1].

## Ví dụ

???+ note "Ví dụ 1 [CF348D Turtles](https://codeforces.com/contest/348/problem/D)"
    Tóm tắt đề bài: Có một bàn cờ dạng lưới $n\times m$, trong đó một số ô có thể đi qua và một số ô không thể đi qua. Một con rùa ở $(x, y)$ chỉ có thể đi đến $(x+1, y)$ và $(x, y+1)$. Cần tính số cặp đường đi không giao nhau theo đỉnh của rùa từ $(1, 1)$ đến $(n, m)$, lấy kết quả modulo $10^9+7$. $2\le n,m\le3000$.

Đây là một ứng dụng khá trực tiếp của bổ đề LGV. Xét tất cả các đường đi hợp lệ, mọi đường đi xuất phát từ $(1,1)$ đều phải đi qua $A=\{(1,2), (2,1)\}$, còn mọi đường đi đến đích đều phải đi qua $B=\{(n-1, m), (n, m-1)\}$. Vì vậy có thể chọn ngay $A, B$. Áp dụng bổ đề LGV, đáp án là:

$$
\begin{vmatrix}
f(a_1, b_1) & f(a_1, b_2) \\
f(a_2, b_1) & f(a_2, b_2)
\end{vmatrix} = f(a_1, b_1)\times f(a_2, b_2) - f(a_1, b_2)\times f(a_2, b_1)
$$

Trong đó $f(a, b)$ là số đường đi từ $a\rightarrow b$ trên đồ thị. Bài toán đếm đường đi có các ô chướng ngại có thể được giải trực tiếp bằng quy hoạch động $O(nm)$, nên dễ tính được $f$. Độ phức tạp cuối cùng là $O(nm)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/lgv/lgv_2.cpp"
    ```

???+ note "Ví dụ 2 [HDU 5852 Intersection is not allowed!](https://acm.hdu.edu.cn/showproblem.php?pid=5852)"
    Tóm tắt đề bài: Có một bàn cờ $n\times n$. Một quân cờ ở $(x, y)$ chỉ có thể đi đến $(x, y+1)$ hoặc $(x + 1, y)$. Có $k$ quân cờ, ban đầu quân cờ thứ $i$ đặt tại $(1, a_i)$, cuối cùng cần đi đến $(n, b_i)$. Các đường đi phải đôi một không giao nhau theo đỉnh. Cần tính số phương án modulo $10^9+7$. $1\le n\le 10^5$, $1\le k\le 100$, thỏa $1\le a_1<a_2<\dots<a_n\le n$, $1\le b_1<b_2<\dots<b_n\le n$.

Nhận thấy nếu các đường đi không giao nhau thì đường đi từ $a_i$ phải đến $b_i$, vì vậy trong bổ đề LGV có $\sigma(S)_i=i$, không cần xét vấn đề dấu. Đặt trọng số cạnh bằng $1$ rồi áp dụng trực tiếp bổ đề.

Số đường đi từ $(1, a_i)$ đến $(n, b_j)$ tương đương với việc chọn $n-1$ bước đi xuống trong tổng cộng $n-1+b_j-a_i$ bước, nên $e(A_i, B_j)=\binom{n-1+b_j-a_i}{n-1}$.

Có thể dùng khử Gauss để tính định thức.

Độ phức tạp là $O(n+k(k^2 + \log p))$, trong đó $\log p$ là độ phức tạp tính nghịch đảo modulo.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/lgv/lgv_1.cpp"
    ```

## Tài liệu tham khảo

[^1]: Chứng minh lấy từ [Zhihu - Chứng minh bổ đề LGV](https://zhuanlan.zhihu.com/p/517819133)
