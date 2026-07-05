<span id="số-entringer"></span>
## Số Entringer

Số Entringer (Entringer number, [OEIS A008281](http://oeis.org/A008281)) $E(n,k)$ là số hoán vị của $n+1$ số từ $0$ đến $n$ thỏa mãn các điều kiện sau:

-   Phần tử đầu tiên là $k$;
-   Phần tử kế tiếp của phần tử đầu tiên nhỏ hơn nó, phần tử tiếp theo nữa lớn hơn phần tử trước đó, phần tử tiếp theo nữa nhỏ hơn phần tử trước đó, v.v. Quan hệ lớn nhỏ giữa các phần tử kề nhau về sau đều tuân theo quy luật này.

Các giá trị ban đầu của số Entringer là:

$$
E(0,0)=1
$$

$$
E(n,0)=0
$$

Hệ thức truy hồi:

$$
E(n,k)=E(n,k-1)+E(n-1,n-k)
$$

<span id="tam-giác-seidel-entringer-arnold"></span>
## Tam giác Seidel-Entringer-Arnold

Một tam giác số thu được bằng cách sắp xếp số Entringer một cách thích hợp được gọi là tam giác Seidel-Entringer-Arnold (Seidel-Entringer-Arnold triangle, [OEIS A008280](http://oeis.org/A008280)). Tam giác này sắp xếp các số Entringer $E(n,k)$ theo thứ tự "cày ruộng bằng bò" (ox-plowing order):

$$
\begin{aligned}
& E(0,0) \\
& E(1,0) \rightarrow E(1,1) \\
& E(2,2) \leftarrow E(2,1) \leftarrow E(2,0) \\
& E(3,0) \rightarrow E(3,1) \rightarrow E(3,2) \rightarrow E(3,3) \\
& E(4,4) \leftarrow E(4,3) \leftarrow E(4,2) \leftarrow E(4,1) \leftarrow E(4,0)
\end{aligned}
$$

tức là:

$$
\begin{aligned}
& 1 \\
& 0 \rightarrow 1 \\
& 1 \leftarrow 1 \leftarrow 0 \\
& 0 \rightarrow 1 \rightarrow 2 \rightarrow 2 \\
& 5 \leftarrow 5 \leftarrow 4 \leftarrow 2 \leftarrow 0
\end{aligned}
$$

Ưu điểm của cách sắp xếp số Entringer này là nó khớp với hệ thức truy hồi $E(n,k)=E(n,k-1)+E(n-1,n-k)$, nên dễ ghi nhớ và dễ hiểu.

Số Entringer có một hàm sinh mũ:

$$
\sum_{m=0}^\infty\sum_{n=0}^\infty E\left(m+n,\frac{1}{2}\left(m+n+{(-1)}^{m+n}(n-m)\right)\right)\frac{x^m}{m!}\frac{x^n}{n!}=\frac{\cos x+\sin x}{\cos (x+y)}
$$

Phân bố hệ số của hàm sinh này thực chất là một biến dạng kéo giãn đơn giản của tam giác Seidel-Entringer-Arnold ở trên:

$$
\begin{array}{ccccc}
E(0,0) & E(1,1) & E(2,0) & E(3,3) & E(4,0) \\
E(1,0) & E(2,1) & E(3,2) & E(4,1) & \\
E(2,2) & E(3,1) & E(4,2) & & \\
E(3,0) & E(4,3) & & & \\
E(4,4) & & & &
\end{array}
$$

tức là:

$$
\begin{aligned}
& 1\quad 1\quad 0\quad 2\quad 0\\
& 0\quad 1\quad 2\quad 2\\
& 1\quad 1\quad 4\\
& 0\quad 5\\
& 5
\end{aligned}
$$

<span id="hoán-vị-zigzag"></span>
## Hoán vị zigzag

Một hoán vị zigzag (zigzag permutation) là một hoán vị $c_1$ đến $c_i$ của các số từ $1$ đến $n$, sao cho mọi phần tử $c_i$ đều không nằm giữa $c_{i-1}$ và $c_{i+1}$ về giá trị.

Với số hoán vị zigzag $Z_n$ ([OEIS A001250](http://oeis.org/A001250)), bắt đầu từ $n=0$ ta có:

$$
1, 1, 2, 4, 10, 32, 122, 544, \cdots
$$

Ví dụ, các hoán vị luân phiên với một vài giá trị $n$ đầu tiên là:

$$
\begin{aligned}
n=1: & \{1\}\\
n=2: & \{1,2\}, \{2,1\}\\
n=3: & \{1,3,2\}, \{2,1,3\}, \{2,3,1\}, \{3,1,2\}\\
n=4: & \{1,3,2,4\}, \{1,4,2,3\}, \{2,1,4,3\}, \{2,3,1,4\}, \{2,4,1,3\}, \\
& \{3,1,4,2\}, \{3,2,4,1\}, \{3,4,1,2\}, \{4,1,3,2\}, \{4,2,3,1\}
\end{aligned}
$$

<span id="hoán-vị-luân-phiên-và-số-zigzag"></span>
## Hoán vị luân phiên và số zigzag

Lưu ý phân biệt khái niệm này với hoán vị sai vị trí.

Với $n>1$, mỗi hoán vị zigzag khi đảo ngược vẫn là một hoán vị zigzag, nên chúng có thể ghép cặp từng đôi một; do đó số lượng chắc chắn là số chẵn.

Sau đây là một cách ghép cặp khác: chia hoán vị zigzag thành hoán vị luân phiên (alternating permutation) và hoán vị phản luân phiên (reverse alternating permutation).

Hoán vị luân phiên có phần tử đầu tiên lớn hơn phần tử thứ hai, với quan hệ lớn nhỏ:

$$
c_1>c_2<c_3>\cdots
$$

Hoán vị phản luân phiên có phần tử đầu tiên nhỏ hơn phần tử thứ hai, với quan hệ lớn nhỏ:

$$
c_1<c_2>c_3<\cdots
$$

Nếu hoán đổi vị trí của $1$ và $n$, của $2$ và $n-1$, rồi tiếp tục như vậy, ta sẽ biến tập hoán vị luân phiên thành tập hoán vị phản luân phiên và ngược lại. Vì vậy, số hoán vị luân phiên và số hoán vị phản luân phiên bằng nhau, đúng bằng một nửa số hoán vị zigzag.

Với $n>1$, đặt:

$$
A_n=\frac{Z_n}{2}
$$

Định nghĩa giá trị ban đầu:

$$
A_0=A_1=1
$$

$A_n$ ở đây được gọi là số zigzag (Euler zigzag number, [OEIS A000111](http://oeis.org/A000111)); bắt đầu từ $n=0$, ta có:

$$
1, 1, 1, 2, 5, 16, 61, 272, \cdots
$$

Tiếp theo thử tìm $A_n$.

Trong các số từ $1$ đến $n$, chọn $k$ số tạo thành một tập con, có $\dbinom{n}{k}$ cách chọn.

Trong tập con $k$ phần tử này, chọn một hoán vị phản luân phiên $u$, có $A_k$ cách chọn; lấy phần bù của tập con này trong tập toàn cục, với tập con còn lại gồm $n-k$ phần tử, chọn một hoán vị phản luân phiên $v$, có $A_{n-k}$ cách chọn.

Xét hoán vị $w$ gồm $n+1$ phần tử: đặt đảo ngược của $u$ ở đầu, nối thêm $n+1$, rồi nối thêm $v$. Khi đó $w$ chắc chắn là một hoán vị zigzag; hơn nữa, mọi hoán vị zigzag gồm $n+1$ phần tử đều có thể cắt tại $n+1$ để thu được các hoán vị phản luân phiên tương ứng $u$ và $v$, và các hoán vị zigzag khác nhau tương ứng với các cặp $u$ và $v$ khác nhau.

Vì vậy có hệ thức truy hồi:

$$
2A_{n+1}=\sum_{k=0}^n \dbinom{n}{k} A_k A_{n-k}
$$

$$
2(n+1)\frac{A_{n+1}}{(n+1)!}=\sum_{k=0}^n \frac{A_k}{k!}\frac{A_{n-k}}{(n-k)!}
$$

Khi $n=0$, hệ thức này không thỏa mãn; các giá trị đầu $A_0$ và $A_1$ đều bằng $1$.

Có thể thấy đây là một tích chập của hàm sinh mũ. Giả sử hàm sinh mũ của $A_n$ là $y$, ta có phương trình vi phân:

$$
2\frac{\mathrm{d}y}{\mathrm{d}x}=y^2+1
$$

Vế phải cộng thêm $1$ để xử lý trường hợp đặc biệt $n=0$. Nghiệm tổng quát của phương trình là:

$$
y=\tan\left(\frac{1}{2}x+C\right)
$$

Thay số hạng thứ $0$ bằng $1$, ta thu được nghiệm riêng:

$$
y=\tan x+\sec x
$$

Hàm tang là hàm lẻ, hàm sec là hàm chẵn; tổng của chúng tạo thành hàm sinh của số zigzag.

<span id="quan-hệ-giữa-số-entringer-và-số-zigzag"></span>
## Quan hệ giữa số Entringer và số zigzag

Theo định nghĩa của số Entringer, $E(n,k)$ là số hoán vị luân phiên của các số từ $0$ đến $n$ có phần tử đầu tiên là $k$. Vì vậy số Entringer thật ra có liên hệ với số zigzag:

$$
A_n=E(n,n)
$$

Việc gọi $A_n$ là "số zigzag" cũng có lý do: ký hiệu $E_n$ là số Euler (Euler number), $B_n$ là số Bernoulli.

Khi $n$ chẵn, các số zigzag có chỉ số chẵn còn được gọi là "số sec" $S_n$ hoặc "số zig". Có quan hệ:

$$
A_n=(-1)^{n/2}E_n
$$

Một vài số hạng đầu là ([OEIS A000364](http://oeis.org/A000364)):

$$
1, 1, 5, 61, 1385, \cdots
$$

Khi $n$ lẻ, các số zigzag có chỉ số lẻ còn được gọi là "số tang" $T_n$ hoặc "số zag". Có quan hệ:

$$
A_n=\frac{(-1)^{(n-1)/2}2^{n+1}(2^{n+1}-1)B_{n+1}}{n+1}
$$

Một vài số hạng đầu là ([OEIS A000182](http://oeis.org/A000182)):

$$
1, 2, 16, 272, 7936, \cdots
$$

Do đó, với khai triển Taylor tại $x=0$, ta có thể biểu diễn số sec và số tang:

$$
\sec x=A_0+A_2\frac{x^2}{2!}+A_4\frac{x^4}{4!}+\cdots
$$

$$
\tan x=A_1x+A_3\frac{x^3}{3!}+A_5\frac{x^5}{5!}+\cdots
$$

Hoặc viết gộp:

$$
\sec x+\tan x=A_0+A_1x+A_2\frac{x^2}{2!}+A_3\frac{x^3}{3!}+A_4\frac{x^4}{4!}+A_5\frac{x^5}{5!}+\cdots
$$

đây là hàm sinh của số zigzag.

<span id="tài-liệu-tham-khảo-và-liên-kết"></span>
## Tài liệu tham khảo và liên kết

1.  [Alternating permutation - Wikipedia](https://en.wikipedia.org/wiki/Alternating_permutation)
