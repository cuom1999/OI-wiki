Trong tổ hợp, đếm đồ thị (Graph Enumeration) là nhánh nghiên cứu bài toán đếm các đồ thị thỏa mãn những tính chất nhất định. [Hàm sinh](../poly/intro.md), [định lý đếm Polya](./polya.md), [phương pháp ký hiệu](../poly/symbolic-method.md#cấu-trúc-cycle-của-tập-hợp) và [OEIS](https://oeis.org/) là những công cụ toán học quan trọng nhất khi giải lớp bài toán này. Đếm đồ thị có thể chia thành hai nhóm lớn: có nhãn và không nhãn. Trong đa số trường hợp[^1], phiên bản có nhãn đơn giản hơn phiên bản không nhãn tương ứng, vì vậy phần này xét việc đếm các bài toán có nhãn trước.

[^1]: Có lẽ cây nhị phân không nhãn là một phản ví dụ. Khi cấu trúc đơn giản, nhóm hoán vị tương ứng là nhóm đồng nhất (Identity Group), lúc đó phiên bản có nhãn có thể thu được trực tiếp bằng cách nhân với $n!$.

<span id="cây-có-nhãn"></span>
## Cây có nhãn

Đây chính là công thức Cayley; xem bài về [dãy Prüfer](../../graph/prufer.md). Cũng có thể dùng [định lý cây ma trận Kirchhoff](../../graph/matrix-tree.md), hoặc [hàm sinh](../poly/intro.md#hàm-sinh) và [định lý Lagrange](https://codeforces.com/blog/entry/104184) để thu được kết quả này.

<span id="bài-tập"></span>
### Bài tập

-   [Hihocoder 1047. Random Tree](https://vjudge.net/problem/HihoCoder-1047)

<span id="đồ-thị-liên-thông-có-nhãn"></span>
## Đồ thị liên thông có nhãn

<span id="ví-dụ-poj-1737-connected-graph"></span>
### Ví dụ "POJ 1737" Connected Graph

???+ note "Ví dụ [\"POJ 1737\" Connected Graph](http://poj.org/problem?id=1737)"
    Tóm tắt đề bài: tính số cách lập đồ thị liên thông có nhãn trên $n$ đỉnh ($n \leq 50$).

Loại bài toán này xuất hiện rất sớm trong bộ "tám bài của nam nhân" của Lou Jiaozhu. Đặt $g_n$ là số đồ thị có nhãn trên $n$ đỉnh, và $c_n$ là dãy cần tính. Đồ thị trên $n$ đỉnh có nhiều nhất $\binom{n}{2}$ cạnh; mỗi cạnh có hai trạng thái tùy theo có xuất hiện hay không, và các trạng thái độc lập với nhau, nên $g_n = 2^{\binom{n}{2}}$. Cố định một đỉnh, rồi liệt kê kích thước thành phần liên thông chứa đỉnh đó; khi đó cần chọn thêm $i-1$ đỉnh từ $n-1$ đỉnh còn lại để tạo thành một thành phần liên thông. Các đỉnh nằm ngoài thành phần liên thông này có thể nối cạnh tùy ý, do đó có truy hồi:

$$
\begin{align}
\sum_{i=1}^{n} \binom{n-1}{i-1} c_i g_{n-i} &= g_n \\
c_n &= g_n - \sum_{i=1}^{n-1} \binom{n-1}{i-1} c_i g_{n-i} 
\end{align}
$$

Chuyển vế thu được công thức truy hồi $O(n^2)$ cho dãy $c_n$, đủ để qua bài này.

<span id="ví-dụ-bài-tập-đội-tuyển-tập-huấn-2013-quy-hoạch-thành-phố"></span>
### Ví dụ "Bài tập đội tuyển tập huấn 2013" Quy hoạch thành phố

???+ note "Ví dụ [\"Bài tập đội tuyển tập huấn 2013\" Quy hoạch thành phố](https://www.luogu.com.cn/problem/P4841)"
    Tóm tắt đề bài: tính số cách lập đồ thị liên thông có nhãn trên $n$ đỉnh ($n \leq 130000$).

Với các bài toán về dãy có miền dữ liệu lớn hơn, thường cần xây dựng hàm sinh của các dãy này để có thể dùng các thuật toán đa thức hiệu quả.

<span id="cách-1-chia-để-trị-fft"></span>
#### Cách 1: chia để trị FFT

Truy hồi ở trên có thể xem là một dạng tự tích chập, nên có thể dùng chia để trị FFT để tính, với độ phức tạp $O(n\log^2n)$.

<span id="cách-2-nghịch-đảo-đa-thức"></span>
#### Cách 2: nghịch đảo đa thức

Khai triển hệ số tổ hợp trong truy hồi ở trên và biến đổi:

$$
\begin{align}
\sum_{i=1}^{n} \binom{n-1}{i-1} c_i g_{n-i} &= g_n \\
\sum_{i=1}^{n} \frac{c_i}{(i-1)!} \frac{g_{n-i}}{(n-i)!} &= \frac{g_n}{(n-1)!}
\end{align}
$$

Xây dựng các đa thức:

$$
\begin{align}
C(x) &= \sum_{n=1} \frac{c_n}{(n-1)!} x^n \\
G(x) &= \sum_{n=0} \frac{g_n}{n!} x^n \\
H(x) &= \sum_{n=1} \frac{g_n}{(n-1)!} x^n
\end{align}
$$

Thế vào biểu thức trên được $CG = H$. Sau khi dùng [nghịch đảo đa thức](../poly/elementary-func.md#nghịch-đảo-đa-thức), tích chập một lần nữa là giải được $C(x)$.

<span id="cách-3-exp-của-đa-thức"></span>
#### Cách 3: exp của đa thức

Một cách khác là dùng [ý nghĩa tổ hợp của exp đa thức trong EGF](../poly/egf.md#ý-nghĩa-tổ-hợp-của-exp-đa-thức-trong-egf). Đặt EGF của dãy đồ thị liên thông có nhãn và đồ thị đơn lần lượt là $C(x)$ và $G(x)$, khi đó chúng có quan hệ:

$$
\begin{align}
\exp(C(x)) &= G(x) \\
C(x) &= \ln(G(x))
\end{align}
$$

Dùng [ln đa thức](../poly/elementary-func.md#hàm-logarit-và-hàm-mũ-của-đa-thức) là giải được $C(x)$.

<span id="đồ-thị-euler-và-đồ-thị-hai-phía-có-nhãn"></span>
## Đồ thị Euler và đồ thị hai phía có nhãn

<span id="ví-dụ-spoj-kpgraphs-counting-graphs"></span>
### Ví dụ "SPOJ KPGRAPHS" Counting Graphs

???+ note "Ví dụ [\"SPOJ KPGRAPHS\" Counting Graphs](http://www.spoj.com/problems/KPGRAPHS/)"
    Tóm tắt đề bài: tính số đồ thị có nhãn trên $n$ đỉnh thỏa mãn từng tính chất sau ($n \leq 1000$).
    
    -   Đồ thị liên thông [A001187](https://oeis.org/A001187).
    -   Đồ thị Euler [A033678](https://oeis.org/A033678).
    -   Đồ thị hai phía [A047864](https://oeis.org/A047864).

Bài này giới hạn độ dài mã nguồn, nên không thể trực tiếp dùng template đa thức, nhưng hàm sinh vẫn giúp ích cho phân tích.

Bài toán đồ thị liên thông đã được giải trong các ví dụ trước; bây giờ xét đồ thị Euler. Lưu ý rằng vài cách đếm đồ thị liên thông ở trên đều có thể mở rộng cho đồ thị liên thông có nhãn thỏa mãn một tính chất bất kỳ. Chẳng hạn, trong công thức truy hồi liên thông, có thể thay $g_n$ từ "đồ thị bất kỳ" thành "đồ thị mà mọi đỉnh đều có bậc chẵn"; khi đó $c_n$ thu được chính là số đồ thị Euler.

Đóng gói quá trình truy hồi liên thông hóa của POJ 1737 thành hàm liên thông hóa:

```cpp
void ln(Int C[], Int G[]) {
  for (int i = 1; i <= n; ++i) {
    C[i] = G[i];
    for (int j = 1; j <= i - 1; ++j)
      C[i] -= binom[i - 1][j - 1] * C[j] * G[i - j];
  }
}
```

Hai câu đầu có thể giải trực tiếp:

```cpp
for (int i = 1; i <= n; ++i) G[i] = pow(2, binom[i][2]);
ln(C, G);
for (int i = 1; i <= n; ++i) G[i] = pow(2, binom[i - 1][2]);
ln(E, G);
```

Lưu ý rằng quá trình truy hồi liên thông hóa này thực chất tương đương với việc lấy ln đa thức trên EGF của nó. Tương tự, cũng có thể viết hàm liên thông hóa ngược, tương đương với việc lấy exp đa thức trên EGF.

```cpp
void exp(Int G[], Int C[]) {
  for (int i = 1; i <= n; ++i) {
    G[i] = C[i];
    for (int j = 1; j <= i - 1; ++j)
      G[i] += binom[i - 1][j - 1] * C[j] * G[i - j];
  }
}
```

Tiếp theo thảo luận việc đếm đồ thị hai phía có nhãn.

Đặt $b_n$ là số đồ thị hai phía trên n đỉnh, và $g_n$ là số đồ thị trên $n$ đỉnh sau khi tô 2 màu các đỉnh sao cho không tồn tại cạnh giữa hai đỉnh cùng màu. Liệt kê số đỉnh của một trong hai màu, có[^2]:

$$
g_n = \sum_{i=0}^{n} \binom{n}{i}2^{i(n-i)}
$$

[^2]: [Blog của PinkRabbit](https://www.luogu.com.cn/blog/PinkRabbit/solution-sp4420) cho biết dãy này cũng có thể tối ưu bằng [Chirp Z-Transform](../poly/czt.md).

Tiếp theo dùng hai cách khác nhau để lập quan hệ giữa $g_n$ và $b_n$.

<span id="cách-1-đếm-hai-lần"></span>
#### Cách 1: đếm hai lần

Đặt $c_{n, k}$ là số đồ thị hai phía có k thành phần liên thông; khi đó có quan hệ sau:

$$
\begin{align}
b_n &= \sum_{i=1}^{n} c_{n, i} \\
g_n &= \sum_{i=1}^{n} c_{n, i} 2^i 
\end{align}
$$

So sánh hai biểu diễn của $g_n$ và khai triển, thu được:

$$
\begin{align}
\sum_{i=0}^{n} \binom{n}{i}2^{i(n-i)} &= \sum_{i=1}^{n} c_{n, i} 2^i \\
c_{n, i} &= \sum_{i=0}{n-1} \binom{n-1}{i-1} c_{n, 1}c_{n-i,k-1}
\end{align}
$$

Từ đó suy ra truy hồi cho $b_n$, với độ phức tạp $O(n^3)$. Nếu tiếp tục dùng nguyên lý bao hàm - loại trừ, có thể tối ưu xuống $O(n^2)$ và qua bài này.

<span id="cách-2-truy-hồi-liên-thông-hóa"></span>
#### Cách 2: truy hồi liên thông hóa

Cả cách 2 và cách 3 đều dùng số đồ thị hai phía liên thông $b1_n$ [A001832](https://oeis.org/A001832) để làm cầu nối giữa $g_n$ và $b_n$.

Lưu ý rằng với mỗi đồ thị hai phía liên thông, có đúng hai cách tô màu khác nhau, tương ứng với hai đồ thị tô 2 màu liên thông khác nhau. Vì vậy liên thông hóa $g_n$ sẽ cho dãy đúng bằng hai lần $b1_n$, còn $b_n$ thu được bằng cách liên thông hóa ngược từ $b1_n$.

Do đó:

```cpp
for (int i = 1; i <= n; ++i) {
  G[i] = 0;
  for (int j = 0; j < i + 1; ++j) G[i] += binom[i][j] * pow(2, j * (i - j));
}
ln(B1, G);
for (int i = 1; i <= n; ++i) B1[i] /= 2;
exp(B, B1);
```

Cả hai quá trình truy hồi đều có độ phức tạp $O(n^2)$ và đều qua được bài này.

<span id="cách-3-exp-của-đa-thức_1"></span>
#### Cách 3: exp của đa thức

Cũng có thể dùng EGF để hiểu quá trình truy hồi ở trên.

Đặt $G(x)$ là EGF của $g_n$, $B1(x)$ là EGF của $b1_n$, và $B(x)$ là EGF của $b_n$. Áp dụng cách 2, có:

$$
\begin{align}
G(x) &= \exp(2B1(x)) \\
B(x) &= \exp(B1(x))  \\
     &= \exp(\frac{\ln{G(x)}}{2}) \\
     &= \sqrt{G}
\end{align}
$$

Có thể đạo hàm hai vế của đẳng thức rồi so sánh hệ số hai vế để thu được công thức truy hồi dễ cài đặt, đủ để qua bài này. Lưu ý rằng cách 2 và cách 3 về bản chất là như nhau, và trong trường hợp tổng quát cách 3 có thể đạt độ phức tạp tốt hơn.

$$
\begin{align}
B_n^2 &= G  \\
2B_nB_n' &= G' 
\end{align}
$$

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/combinatorics/graph-enumeration/graph-enumeration_1.cpp"
    ```

<span id="bài-tập_1"></span>
### Bài tập

-   [UOJ Goodbye Jihai D. Cuộc truy đuổi năm mới](https://uoj.ac/contest/50/problem/498)
-   [BZOJ 3864. Người bạn lớn và cây đa phân](https://hydro.ac/p/bzoj-P3864)
-   [BZOJ 2863. Nguyên thủ phẫn nộ](https://hydro.ac/p/bzoj-P2863)
-   [Luogu P6295. Đếm DAG có nhãn](https://www.luogu.com.cn/problem/P6295)
-   [LOJ 6569. Đếm cactus](https://loj.ac/p/6569)
-   [LOJ 6570. Đếm caterpillar](https://loj.ac/p/6570)
-   [Luogu P5434. Đếm sa mạc có nhãn](https://www.luogu.com.cn/problem/P5434)
-   [Luogu P3343. \[ZJOI2015\] Vùng đất ảo tưởng sau động đất](https://www.luogu.com.cn/problem/P3343)
-   [HDU 5279. YJC plays Minecraft](https://acm.hdu.edu.cn/showproblem.php?pid=5279)
-   [Luogu P7364. Đếm đồ thị hai phía có nhãn](https://www.luogu.com.cn/problem/P7364)
-   [Luogu P5827. Đếm đồ thị song liên thông đỉnh](https://www.luogu.com.cn/problem/P5827)
-   [Luogu P5827. Đếm đồ thị song liên thông cạnh](https://www.luogu.com.cn/problem/P5828)
-   [Luogu P6596. How Many of Them](https://www.luogu.com.cn/problem/P6596)
-   [Luogu U152448. Đếm đồ thị liên thông mạnh có nhãn](https://www.luogu.com.cn/problem/U152448)
-   [Project Euler 434. Rigid graphs](https://projecteuler.net/problem=434)

<span id="riddells-formula"></span>
## Công thức Riddell

Cách dùng exp của EGF ở trên đôi khi được gọi là công thức Riddell cho đồ thị có nhãn. [Biến đổi Euler](../poly/symbolic-method.md#cấu-trúc-multiset-của-tập-hợp) của hàm sinh đôi khi cũng được gọi là công thức Riddell cho đồ thị không nhãn; công thức sau xuất hiện sớm nhất trong nghiên cứu của Euler về số phân hoạch. Ngoài việc giải các bài toán đếm đồ thị, nó còn xuất hiện trong bài toán ba lô hoàn toàn.

Với dãy cho trước $a_i$ và OGF tương ứng $A(x)$, định nghĩa biến đổi Euler của $A(x)$ là:

$$
\begin{align}
\mathcal{E}(A(x)) &= \prod_{i} (1-x^i)^{-a_i}  \\
                  &= \exp (\sum_{i} \frac{A(x^i)}{i})  
\end{align}
$$

Đặt các hệ số của $\mathcal{E}(A(x))$ là $b_i$, và định nghĩa mảng phụ $c_i = \sum_{d|n} d a_d$, khi đó có truy hồi

$$
n b_n = c_n + \sum_{i=1}^{n-1} c_i b_{n-i}
$$

<span id="cây-không-nhãn"></span>
## Cây không nhãn

<span id="ví-dụ-spoj-pt07d-let-us-count-1-2-3"></span>
### Ví dụ "SPOJ PT07D" Let us count 1 2 3

???+ note "Ví dụ [\"SPOJ PT07D\" Let us count 1 2 3](https://www.spoj.com/problems/PT07D/)"
    Tóm tắt đề bài: tính số cây trên n đỉnh thỏa mãn từng tính chất sau.
    
    -   Cây có gốc có nhãn [A000169](https://oeis.org/A000169).
    -   Cây không gốc có nhãn [A000272](https://oeis.org/A000272).
    -   Cây có gốc không nhãn [A000081](https://oeis.org/A000081).
    -   Cây không gốc không nhãn [A000055](https://oeis.org/A000055).

<span id="cây-có-gốc"></span>
#### Cây có gốc

Trường hợp có nhãn đã được giải quyết ở phần trước. Bây giờ xét cây có gốc không nhãn; đặt OGF của nó là $F(x)$, áp dụng biến đổi Euler thu được:

$$
F(x) = x\mathcal{E}(F(x))
$$

Lấy hệ số là được.

<span id="cây-không-gốc"></span>
#### Cây không gốc

Xét bao hàm - loại trừ: lấy số phương án cây có gốc trừ đi số phương án mà gốc không phải trọng tâm, và thảo luận theo tính chẵn lẻ của $n$.

Khi $n$ lẻ:

Tất yếu tồn tại một cây con có kích thước $\geq \left\lceil \frac{n}{2}\right\rceil$; liệt kê kích thước của cây con đó, có:

$$
g_n = f_n - \sum_{i=\left\lceil\frac{n}{2}\right\rceil}^{n-1} f_i f_{n-i}
$$

Khi $n$ chẵn:

Lưu ý rằng khi có hai trọng tâm, quá trình trên chỉ trừ một lần, nên cần trừ thêm

$$
g_n = f_n - \sum_{i=\left\lceil\frac{n}{2}\right\rceil}^{n-1} f_i f_{n-i} - \binom{f_{\frac{n}{2}}}{2}
$$

<span id="ví-dụ-luogu-p5900-đếm-cây-không-gốc-không-nhãn"></span>
### Ví dụ "Luogu P5900" Đếm cây không gốc không nhãn

???+ note "Ví dụ [\"Luogu P5900\" Đếm cây không gốc không nhãn](https://www.luogu.com.cn/problem/P5900)"
    Tóm tắt đề bài: tính số cây không gốc không nhãn trên n đỉnh ($n \leq 200000$).

Với miền dữ liệu lớn hơn, cách làm cũng tương tự; sau biến đổi Euler chỉ cần dùng template đa thức.

<span id="đồ-thị-đơn-không-nhãn"></span>
## Đồ thị đơn không nhãn

<span id="ví-dụ-sgu-282-isomorphism-isomorphism"></span>
### Ví dụ "SGU 282. Isomorphism" Isomorphism

???+ note "Ví dụ [\"SGU 282. Isomorphism\" Isomorphism](https://codeforces.com/problemsets/acmsguru/problem/99999/282)"
    Tóm tắt đề bài: tính số cách tô m màu các cạnh của đồ thị đầy đủ không nhãn trên n đỉnh.

Lưu ý rằng khi m = 2, đối tượng cần tính chính là đồ thị đơn không nhãn [A000088](https://oeis.org/A000088). Xét định lý đếm Polya:

$$
\frac{1}{|G|}\sum_{g\in G} m^{c(g)}
$$

Trong bài này, nhóm hoán vị $G$ là nhóm hoán vị trên tập cạnh sinh bởi nhóm đối xứng cấp $n$ trên các đỉnh, nhưng cách làm vét cạn liệt kê $O(n!)$ trường hợp nên không qua được.

Xét phân loại theo cấu trúc chu trình của hoán vị; mỗi cấu trúc chu trình tương ứng với một phân hoạch số. Dùng dfs() để sinh các phân hoạch, khi đó bài toán chuyển thành tính số hoán vị $w(p)$ ứng với mỗi phân hoạch $p$ và số chu trình $c(p)$ trong mỗi lớp hoán vị. Đáp án là

$$
\frac{1}{|G|} \sum_{p \in P} w(p) m^{c(p)}
$$

Xét $w(p)$: mỗi phân hoạch tương ứng với một sắp xếp chu trình, đồng thời thứ tự giữa các phần có cùng kích thước là không quan trọng, nên có:

$$
w(p) = \frac{n!}{\prod_{i}(p_i)\prod_{i}(q_i!)} 
$$

Trong đó $q_i$ biểu thị số lần phần có kích thước $i$ xuất hiện trong $p$.

Xét $c(p)$: các chu trình trên tập đỉnh bị $p$ tác động có số lượng là $|p|$, nhưng đề bài xét tô màu cạnh, nên cần xét thêm hoán vị cạnh do hoán vị đỉnh sinh ra.

Nếu một cạnh nối hai đỉnh nằm trong cùng một chu trình, đặt kích thước chu trình đó là $p_i$, thì số chu trình do cạnh sinh ra đúng bằng $\left\lfloor \frac{p_i}{2} \right\rfloor$.

Nếu một cạnh nối hai đỉnh nằm trong hai chu trình khác nhau, đặt chúng lần lượt là $p_i$ và $p_j$; mỗi chu trình con đều có độ dài $\operatorname{lcm}(p_i,p_j)$, nên số chu trình do cạnh sinh ra đúng bằng $\frac{p_i p_j}{\operatorname{lcm}(p_i,p_j)} = \gcd(p_i, p_j)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/combinatorics/graph-enumeration/graph-enumeration_2.cpp"
    ```

<span id="bài-tập_2"></span>
## Bài tập

-   [CodeForces 438 E. The Child and Binary Tree](https://codeforces.com/problemset/problem/438/E)
-   [Luogu P5448. \[THUPC2018\] Đếm đồ thị tốt](https://www.luogu.com.cn/problem/P5448)
-   [Luogu P5818. \[JSOI2011\] Đếm đồng phân cấu tạo](https://www.luogu.com.cn/problem/P5818)
-   [Luogu P6597. Đếm anken](https://www.luogu.com.cn/problem/P6597)
-   [Luogu P6598. Đếm ankan](https://www.luogu.com.cn/problem/P6598)
-   [Luogu P4128. \[SHOI2006\] Đồ thị tô màu](https://www.luogu.com.cn/problem/P4128)
-   [Luogu P4727. \[HNOI2009\] Đếm đẳng cấu của đồ thị](https://www.luogu.com.cn/problem/P4727)
-   [AtCoder Beginner Contest 222 H. Binary Tree](https://atcoder.jp/contests/abc222/tasks/abc222_h)
-   [AtCoder Beginner Contest 284 Ex. Count Unlabeled Graphs](https://atcoder.jp/contests/abc284/tasks/abc284_h)
-   [Luogu P4708. Vẽ tranh](https://www.luogu.com.cn/problem/P4708)
-   [Luogu P7592. Đếm cây (2021 CoE-II E)](https://www.luogu.com.cn/problem/P7592)
-   [Luogu P5206. \[WC2019\] Đếm cây](https://www.luogu.com.cn/problem/P5206)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

1.  [WC2015, tài liệu trao đổi của trại viên Gu Yuzhou: Graphical Enumeration](https://github.com/lychees/ACM-Training/blob/master/Note/%E5%86%AC%E4%BB%A4%E8%90%A5/2015/%E9%A1%BE%E6%98%B1%E6%B4%B2%E8%90%A5%E5%91%98%E4%BA%A4%E6%B5%81%E8%B5%84%E6%96%99%20Graphical%20Enumeration.pdf)
2.  [WC2019, hàm sinh, thuật toán đa thức và đếm đồ thị](https://github.com/lychees/ACM-Training/tree/master/Note/%E5%86%AC%E4%BB%A4%E8%90%A5/2019/d4)
3.  [Counting labeled graphs - Algorithms for Competitive Programming](https://cp-algorithms.com/combinatorics/counting_labeled_graphs.html)
4.  [Graphical Enumeration Paperback, Frank Harary, Edgar M. Palmer](https://github.com/lychees/ACM-Training/blob/master/Note/Book/)
5.  [The encyclopedia of integer sequences, N. J. A. Sloane, Simon Plouffe](https://github.com/lychees/ACM-Training/blob/master/Note/Book/The%20encyclopedia%20of%20integer%20sequences%20\(N.%20J.A.%20Sloane%2C%20Simon%20Plouffe\).pdf)
6.  [Combinatorial Problems and Exercises, László Lovász](https://github.com/lychees/ACM-Training/blob/master/Note/Book/Combinatorial%20Problems%20and%20Exercises_L%C3%A1szl%C3%B3%20Lov%C3%A1sz.pdf)
7.  [Graph Theory and Additive Combinatorics](https://yufeizhao.com/gtacbook/)
