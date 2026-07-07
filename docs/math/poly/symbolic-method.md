Phương pháp ký hiệu (symbolic method) là một cách nhanh để chuyển các đối tượng tổ hợp thành hàm sinh. Bài viết sẽ xét một số phép toán cụ thể được định nghĩa trên các tập hợp, rồi suy ra phép toán tương ứng trên hàm sinh.

Một lớp tổ hợp, hoặc gọi tắt là lớp, là $(\mathcal{A},\lvert \cdot \rvert)$, trong đó $\mathcal{A}$ là tập các đối tượng tổ hợp, còn hàm $\lvert \cdot \rvert$ ánh xạ mỗi đối tượng tổ hợp tới một số nguyên không âm, thường gọi là hàm kích thước. Cần lưu ý rằng số nguyên không âm này không được là vô hạn. Ví dụ, với chuỗi trên bảng chữ cái $\lbrace 0,1\rbrace$, có thể lấy độ dài chuỗi làm hàm kích thước; với cây hoặc đồ thị, có thể lấy số đỉnh làm hàm kích thước. Điều này không phải tuyệt đối: đôi khi cũng có thể gán kích thước $0$ cho một vài loại đỉnh đặc biệt.

Bài viết này là một bản giản lược dựa trên chương 1 của sách Tổ hợp giải tích.

<span id="hệ-không-gắn-nhãn"></span>

## Hệ không gắn nhãn

Trong hệ không gắn nhãn, dùng hàm sinh thường (OGF). Với tập $\mathcal{A}$, OGF tương ứng được ký hiệu là

$$
A(z)=\sum_{\alpha\in\mathcal{A}}z^{\lvert \alpha \rvert}=\sum_{n\geq 0}a_nz^n.
$$

Quy ước dùng cùng một nhóm chữ cái để biểu thị hàm sinh của cùng một lớp. Ví dụ, dùng $a_n$ để biểu thị $\lbrack z^n\rbrack A(z)$, tức hệ số của $z^n$ trong $A(z)$, và dùng $\mathcal{A}_n$ để biểu thị tập các đối tượng trong $\mathcal{A}$ có hàm kích thước bằng $n$; do đó $a_n=\operatorname{card}(\mathcal{A}_n)$, trong đó $\operatorname{card}$ là lực lượng (cardinality).

Bài viết này không thảo luận về tính chấp nhận được (admissibility); có thể tham khảo thêm nội dung trong tài liệu tham khảo.

Dưới đây là hai lớp tổ hợp và đối tượng tổ hợp đặc biệt:

-   Ký hiệu $\epsilon$ là đối tượng trung hòa (neutral object), và $\mathcal{E}=\lbrace \epsilon \rbrace$ là lớp trung hòa (neutral class). Kích thước của đối tượng trung hòa là $0$, và OGF của lớp trung hòa là $E(z)=1$.
-   Ký hiệu $\circ$ hoặc $\bullet$ là đối tượng nguyên tử (atom object), và $\mathcal{Z}_{\circ}=\lbrace \circ\rbrace$, $\mathcal{Z}_{\bullet}=\lbrace \bullet\rbrace$, hoặc viết tắt $\mathcal{Z}$, là lớp nguyên tử (atom class). Kích thước của đối tượng nguyên tử là $1$, và OGF của lớp nguyên tử là $Z(z)=z$.

Với hai lớp tổ hợp $\mathcal{A}$ và $\mathcal{B}$, quan hệ đẳng cấu theo nghĩa tổ hợp được ký hiệu là $\mathcal{A}=\mathcal{B}$ hoặc $\mathcal{A}\cong\mathcal{B}$, nhưng ký hiệu sau chỉ được dùng khi đẳng cấu đó không tầm thường.

Có

$$
\mathcal{A}\cong\mathcal{E}\times \mathcal{A}\cong\mathcal{A}\times\mathcal{E},
$$

trong đó $\times$ là phép toán hai ngôi, biểu thị tích Descartes của các tập hợp.

<span id="cấu-trúc-hợp-rời-nhau-của-tập-hợp"></span>

### Cấu trúc hợp rời nhau của tập hợp

Với hai lớp $\mathcal{A}$ và $\mathcal{B}$, hợp của chúng được ký hiệu là

$$
\mathcal{A}+\mathcal{B}=(\mathcal{E}_{1}\times\mathcal{A})+(\mathcal{E}_2\times\mathcal{B}).
$$

Cách định nghĩa như vậy không trái với yêu cầu các tập phải rời nhau trong lý thuyết tập hợp. Có thể hình dung bằng cách tô màu đỏ cho các đối tượng trong $\mathcal{A}$ và tô màu xanh cho các đối tượng trong $\mathcal{B}$.

OGF tương ứng là

$$
A(z)+B(z).
$$

Xét

$$
A(z)+B(z)=\sum _ {\alpha\in\mathcal{A}}z^{\lvert \alpha\rvert} + \sum _ {\beta\in\mathcal{B}}z^{\lvert \beta\rvert}=\sum_{n\geq 0}(a_n+b_n)z^n,
$$

tương ứng với phép cộng chuỗi lũy thừa hình thức.

<span id="cấu-trúc-tích-descartes-của-tập-hợp"></span>

### Cấu trúc tích Descartes của tập hợp

Với hai lớp $\mathcal{A}$ và $\mathcal{B}$, tích Descartes của chúng được ký hiệu là

$$
\mathcal{A}\times \mathcal{B}=\left\lbrace (\alpha, \beta)\mid \alpha \in \mathcal{A},\beta\in\mathcal{B}\right\rbrace.
$$

OGF tương ứng là

$$
A(z)\cdot B(z).
$$

Kích thước của $(\alpha,\beta)$ được định nghĩa là tổng kích thước của các thành phần. Khi đó cũng có

$$
\gamma =(\alpha_1,\alpha_2,\dots ,\alpha_n)\implies \lvert \gamma\rvert =\lvert \alpha_1\rvert +\lvert \alpha_2\rvert +\cdots +\lvert \alpha_n\rvert.
$$

Do đó

$$
A(z)\cdot B(z)=\left(\sum _ {\alpha\in\mathcal{A}}z^{\lvert \alpha\rvert}\right)\left(\sum _ {\beta\in\mathcal{B}}z^{\lvert \beta\rvert}\right)=\sum _ {(\alpha, \beta)\in(\mathcal{A}\times \mathcal{B})}z^{\lvert \alpha\rvert +\lvert \beta\rvert}=\sum_{n\geq 0}\sum_{i+j=n}a_ib_jz^n,
$$

tương ứng với phép nhân chuỗi lũy thừa hình thức.

<span id="cấu-trúc-sequence-của-tập-hợp"></span>

### Cấu trúc dãy (Sequence) của tập hợp

Cấu trúc dãy (Sequence) sinh ra tất cả các tổ hợp có thể.

???+ note "Ví dụ"
    $$
    \begin{aligned}
    \operatorname{SEQ}(\lbrace a\rbrace)&=\lbrace \epsilon\rbrace +\lbrace a\rbrace +\lbrace (a,a)\rbrace +\lbrace (a,a,a)\rbrace +\cdots\\
    \operatorname{SEQ}(\lbrace a,b\rbrace)&=\lbrace \epsilon\rbrace +\lbrace a,b\rbrace +\lbrace (a,b)\rbrace + \lbrace(b,a)\rbrace +\lbrace (a,a)\rbrace +\lbrace (b,b)\rbrace\\
    &+\lbrace (a,b,a)\rbrace +\lbrace (a,b,b)\rbrace +\lbrace (a,a,b)\rbrace\\
    &+\lbrace (b,b,a)\rbrace +\lbrace (b,a,b)\rbrace +\lbrace (b,b,b)\rbrace +\lbrace (a,a,a)\rbrace +\lbrace (b,a,a)\rbrace\\
    &+\cdots
    \end{aligned}
    $$
    
    Các phần tử như $\lbrace (a,b)\rbrace$ và $\lbrace (b,a)\rbrace$, tức các phần tử có thứ tự thành phần khác nhau, đều được sinh ra. Vì vậy có thể xem cấu trúc dãy sinh ra các tổ hợp có thứ tự.

Định nghĩa

$$
\operatorname{SEQ}(\mathcal{A})=\mathcal{E}+\mathcal{A}+(\mathcal{A}\times \mathcal{A})+(\mathcal{A}\times \mathcal{A}\times \mathcal{A})+\cdots
$$

và yêu cầu $\mathcal{A}_0=\varnothing$, tức là trong $\mathcal{A}$ không có đối tượng kích thước $0$.

OGF tương ứng là

$$
Q(A(z))=1+A(z)+A(z)^2+A(z)^3+\cdots =\frac{1}{1-A(z)},
$$

trong đó $Q$ là giả nghịch đảo Pólya (quasi-inversion).

???+ note "Ví dụ: cây có gốc có thứ tự (ordered rooted tree)"
    Có thể dùng cấu trúc dãy để định nghĩa cây có gốc có thứ tự, tức cây có gốc mà thứ tự giữa các con có ý nghĩa. Gọi lớp tổ hợp này là $\mathcal{T}$. Khi đó một cây gồm một nút gốc và một dãy các cây, tức là
    
    $$
    \mathcal{T}=\lbrace \bullet\rbrace\times\operatorname{SEQ}(\mathcal{T})
    $$
    
    OGF tương ứng là
    
    $$
    T(z)=\frac{z}{1-T(z)}.
    $$
    
    Các hệ số đầu tiên là `0 1 1 2 5 14 42 132 429 1430 4862 16796`; bỏ qua hằng số thì chính là OEIS [A000108](http://oeis.org/A000108).

<span id="cấu-trúc-multiset-của-tập-hợp"></span>

### Cấu trúc Multiset của tập hợp

Cấu trúc Multiset sinh ra tất cả các tổ hợp có thể, nhưng không phân biệt thứ tự giữa các phần tử thành phần.

???+ note "Ví dụ"
    $$
    \begin{aligned}
    \operatorname{MSET}(\lbrace a\rbrace)&=\lbrace \epsilon\rbrace +\lbrace a\rbrace +\lbrace (a,a)\rbrace +\lbrace (a,a,a)\rbrace +\cdots\\
    \operatorname{MSET}(\lbrace a,b\rbrace)&=\lbrace \epsilon\rbrace +\lbrace a\rbrace +\lbrace (a,a)\rbrace +\lbrace (a,a,a)\rbrace +\cdots\\
    &+\lbrace b\rbrace +\lbrace (a,b)\rbrace +\lbrace (a,a,b)\rbrace +\cdots \\
    &+\lbrace (b,b)\rbrace + \lbrace (a,b,b)\rbrace +\lbrace (a,a,b,b)\rbrace + \cdots\\
    &+\cdots
    \end{aligned}
    $$
    
    Lưu ý rằng $\lbrace (b,a)\rbrace$ và $\lbrace (a,b,a)\rbrace$ xuất hiện trong $\operatorname{SEQ}(\lbrace a,b\rbrace)$, nhưng không xuất hiện trong $\operatorname{MSET}(\lbrace a,b\rbrace)$. Có thể xem Multiset sinh ra các tổ hợp không thứ tự.

Định nghĩa truy hồi của nó là

$$
\operatorname{MSET}(\lbrace \alpha_0,\alpha_1,\dots, \alpha_n\rbrace)=\operatorname{MSET}(\lbrace \alpha_0,\alpha_1,\dots, \alpha_{n-1}\rbrace)\times \operatorname{SEQ}(\lbrace \alpha_n\rbrace).
$$

Tức là

$$
\operatorname{MSET}(\mathcal{A})=\prod _ {\alpha\in\mathcal{A}}\operatorname{SEQ}(\lbrace \alpha\rbrace)
$$

và yêu cầu $\mathcal{A}_0=\varnothing$. Hoặc cũng có thể đưa ra định nghĩa tương đương:

$$
\operatorname{MSET}(\mathcal{A})=\operatorname{SEQ}(\mathcal{A})/\mathbf{R}.
$$

Trong đó $\mathbf{R}$ là một quan hệ tương đương. Hai bộ $(\alpha_1,\dots,\alpha_n)$ và $(\beta_1,\dots,\beta_n)$ thỏa mãn $(\alpha_1,\dots,\alpha_n)\mathbf{R}(\beta_1,\dots,\beta_n)$ khi và chỉ khi tồn tại một hoán vị $\sigma$ sao cho với mọi $j$, $\beta_{j}=\alpha_{\sigma(j)}$.

OGF tương ứng là

$$
\operatorname{Exp}(A(z))=\prod _ {\alpha \in\mathcal{A}}\left(1-z^{\lvert \alpha \rvert}\right)^{-1}=\prod _ {n\geq 1}\left(1-z^n\right)^{-a_n}.
$$

Lưu ý rằng

$$
\ln(1+z)=\frac{z}{1}-\frac{z^2}{2}+\frac{z^3}{3}-\cdots =\sum_{n\geq 1}\frac{(-1)^{n-1}z^n}{n}
$$

và $A(z)=\exp(\ln(A(z)))$, nên

$$
\begin{aligned}
\operatorname{Exp}(A(z))&=\exp\left(\sum _ {n\geq 1}-a_n\cdot \ln\left(1-z^n\right)\right)\\
&=\exp\left(\sum _ {n\geq 1}-a_n\cdot \sum _ {m\geq 1}\frac{-z^{nm}}{m}\right)\\
&=\exp\left(\frac{A(z)}{1}+\frac{A(z^2)}{2}+\frac{A(z^3)}{3}+\cdots \right).
\end{aligned}
$$

Trong đó $\operatorname{Exp}$ là chỉ số Pólya, cũng được gọi là biến đổi Euler.

???+ note "Bài tập [LOJ 6268. Số phân hoạch](https://loj.ac/p/6268)"
    **Đề bài**: gọi $f(n)$ là số cách phân hoạch $n$. Tính $f(1),f(2),\dots,f(10^5)$ modulo $998244353$.
    
    **Lời giải**: gọi lớp của toàn bộ các số nguyên dương là $\mathcal{I}$, khi đó $\mathcal{I}=\operatorname{SEQ}_{\geq 1}(\mathcal{Z})=\mathcal{Z}\times \operatorname{SEQ}(\mathcal{Z})$, trong đó chỉ số dưới $\geq 1$ là cấu trúc có ràng buộc, xem phần sau. Đại lượng cần tìm là
    
    $$
    \operatorname{MSET}(\mathcal{I})
    $$
    
    Các hệ số đầu tiên của OGF tương ứng là `1 2 3 5 7 11 15 22 30 42`; bỏ qua hằng số thì chính là OEIS [A000041](https://oeis.org/A000041).

???+ note "Bài tập [Luogu P4389. Balo của công chúa Fu](https://www.luogu.com.cn/problem/P4389)"
    **Đề bài**: cho $n$ loại hàng hóa có thể tích lần lượt là $v_1,\dots ,v_n$ và số nguyên dương $m$. Tính số cách lấp đầy balo có thể tích $1,2,\dots,m$ modulo $998244353$, trong đó số lượng hàng hóa không bị giới hạn và các hàng hóa khác loại nhưng cùng thể tích vẫn được phân biệt. Quy ước $1\leq n,m\leq 10^5$ và $1\leq v_i\leq m$.
    
    **Lời giải**: gọi lớp tổ hợp của các hàng hóa là $\mathcal{A}$. Đại lượng cần tìm chính là các hệ số của OGF tương ứng với $\operatorname{MSET}(\mathcal{A})$.

???+ note "Bài tập [Luogu P5900. Đếm cây không gốc không gắn nhãn](https://www.luogu.com.cn/problem/P5900)"
    **Đề bài**: tính số cây không gắn nhãn, không gốc, có $n$ đỉnh modulo $998244353$. Quy ước $1\leq n\leq 2\times 10^5$.
    
    **Lời giải**: gọi lớp tổ hợp của cây có gốc không gắn nhãn là $\mathcal{T}$. Khi đó
    
    $$
    \mathcal{T}=\lbrace \bullet\rbrace\times\operatorname{MSET}(\mathcal{T})
    $$
    
    Theo mô tả trong bài báo [The Number of Trees](https://users.math.msu.edu/users/magyarp/Math482/Otter-Trees.pdf) của Richard Otter, OGF tương ứng với cây không gốc là
    
    $$
    T(z)-\frac{1}{2}T^2(z)+\frac{1}{2}T(z^2).
    $$
    
    Các hệ số đầu tiên là `1 1 1 2 3 6 11 23 47 106`; bỏ qua hằng số thì chính là OEIS [A000055](https://oeis.org/A000055).

<span id="cấu-trúc-powerset-của-tập-hợp"></span>

### Cấu trúc Powerset của tập hợp

Cấu trúc Powerset sinh ra tất cả các tập con.

???+ note "Ví dụ"
    $$
    \begin{aligned}
    \operatorname{PSET}(\lbrace a\rbrace)&=\lbrace \epsilon\rbrace +\lbrace a\rbrace \\
    \operatorname{PSET}(\lbrace a,b\rbrace)&=\lbrace \epsilon\rbrace +\lbrace a\rbrace +\lbrace b\rbrace +\lbrace (a,b)\rbrace \\
    \operatorname{PSET}(\lbrace a,b,c\rbrace)&=\lbrace \epsilon\rbrace +\lbrace a\rbrace +\lbrace b\rbrace +\lbrace (a,b)\rbrace +\lbrace c\rbrace +\lbrace (a,c)\rbrace +\lbrace (b,c)\rbrace +\lbrace (a,b,c)\rbrace\\
    \end{aligned}
    $$

Định nghĩa truy hồi của nó là

$$
\operatorname{PSET}(\lbrace \alpha_0,\alpha_1,\dots, \alpha_n\rbrace)=\operatorname{PSET}(\lbrace \alpha_0,\alpha_1,\dots, \alpha_{n-1}\rbrace)\times (\lbrace \epsilon\rbrace +\lbrace \alpha_n\rbrace).
$$

Tức là

$$
\operatorname{PSET}(\mathcal{A})\cong \prod _ {\alpha\in\mathcal{A}}\left(\lbrace \epsilon \rbrace +\lbrace \alpha\rbrace\right)
$$

và yêu cầu $\mathcal{A}_0=\varnothing$.

OGF tương ứng là

$$
\begin{aligned}
\overline{\operatorname{Exp}}(A(z))&=\prod _ {\alpha\in\mathcal{A}}\left(1+z^{\lvert \alpha \rvert}\right)=\prod _ {n\geq 1}\left(1+z^n\right)^{a_n}\\
&=\exp\left(\sum _ {n\geq 1}a_n\cdot \ln\left(1+z^n\right)\right)\\
&=\exp\left(\sum _ {n\geq 1}a_n\cdot \sum _ {m\geq 1}\frac{(-1)^{m-1}z^{nm}}{m}\right)\\
&=\exp\left(\frac{A(z)}{1}-\frac{A(z^2)}{2}+\frac{A(z^3)}{3}-\cdots \right).
\end{aligned}
$$

Trong đó $\overline{\operatorname{Exp}}$ là chỉ số Pólya sửa đổi.

Theo định nghĩa, $\operatorname{PSET}(\mathcal{A})\subset \operatorname{MSET}(\mathcal{A})$.

<span id="cấu-trúc-cycle-của-tập-hợp"></span>

### Cấu trúc Cycle của tập hợp

Cấu trúc Cycle sinh ra tất cả các tổ hợp có thể, nhưng không phân biệt các tổ hợp chỉ khác nhau bởi phép quay vòng.

Định nghĩa

$$
\operatorname{CYC}(\mathcal{A})=\left(\operatorname{SEQ}(\mathcal{A})\setminus\lbrace \epsilon\rbrace\right)/\mathbf{S}.
$$

Trong đó $\mathbf{S}$ là một quan hệ tương đương. Hai bộ $(\alpha_1,\dots,\alpha_n)$ và $(\beta_1,\dots,\beta_n)$ thỏa mãn $(\alpha_1,\dots,\alpha_n)\mathbf{S}(\beta_1,\dots,\beta_n)$ khi và chỉ khi tồn tại một phép dịch vòng $\tau$ sao cho với mọi $j$, $\beta_j=\alpha_{\tau(j)}$.

???+ note "Ví dụ"
    Để đơn giản, đặt $\texttt{a},\texttt{b}$ đều là kí tự có kích thước $1$. Ví dụ này chỉ liệt kê các chuỗi có kích thước $3$ và $4$:
    
    $$
    \operatorname{CYC}(\lbrace \texttt{a},\texttt{b}\rbrace)_3=\lbrace \texttt{aaa}\rbrace +\lbrace \texttt{aab}\rbrace+\lbrace \texttt{abb}\rbrace+\lbrace \texttt{bbb}\rbrace
    $$
    
    Trong đó $\texttt{aab}\mathbf{S}\texttt{baa}\mathbf{S}\texttt{aba}$ nên chỉ giữ lại một đại diện; tương tự, $\texttt{abb}\mathbf{S}\texttt{bab}\mathbf{S}\texttt{bba}$ cũng chỉ giữ lại một đại diện.
    
    $$
    \operatorname{CYC}(\lbrace \texttt{a},\texttt{b}\rbrace)_4=\lbrace \texttt{aaaa}\rbrace +\lbrace \texttt{aaab}\rbrace+\lbrace \texttt{aabb}\rbrace+\lbrace \texttt{abbb}\rbrace+\lbrace \texttt{bbbb}\rbrace +\lbrace \texttt{abab}\rbrace
    $$
    
    Trong đó $\texttt{aaab}\mathbf{S}\texttt{baaa}\mathbf{S}\texttt{abaa}\mathbf{S}\texttt{aaba}$, $\texttt{aabb}\mathbf{S}\texttt{baab}\mathbf{S}\texttt{bbaa}\mathbf{S}\texttt{abba}$, $\texttt{abbb}\mathbf{S}\texttt{babb}\mathbf{S}\texttt{bbab}\mathbf{S}\texttt{bbba}$ và $\texttt{abab}\mathbf{S}\texttt{baba}$.

OGF tương ứng là

$$
\operatorname{Log}(A(z))=\sum _ {n\geq 1}\frac{\varphi(n)}{n}\ln\frac{1}{1-A(z^n)},
$$

trong đó $\varphi$ là hàm Euler, còn $\operatorname{Log}$ là logarit Pólya.

Vì chứng minh khá phức tạp, có thể tham khảo bài báo [The Cycle Construction](https://epubs.siam.org/doi/10.1137/0404006) của Flajolet hoặc phụ lục của Tổ hợp giải tích.

<span id="cấu-trúc-có-ràng-buộc"></span>

### Cấu trúc có ràng buộc

Với tất cả các cấu trúc nói trên, số lượng "thành phần" vẫn chưa bị ràng buộc. Nếu ở chỉ số dưới của $\operatorname{SEQ}$ đặt một vị từ tác động lên số nguyên để ràng buộc số thành phần, chẳng hạn

$$
\operatorname{SEQ}_{=k}(\mathcal{B}),\quad \operatorname{SEQ}_{\geq k}(\mathcal{B}),\quad \operatorname{SEQ}_{1..k}(\mathcal{B}),
$$

trong đó $\operatorname{SEQ}_{=k}(\mathcal{B})$ cũng thường được viết tắt là $\operatorname{SEQ}_k(\mathcal{B})$, còn $\operatorname{SEQ}_{1..k}(\mathcal{B})$ biểu thị ràng buộc trên đoạn $\lbrack 1..k\rbrack$.

Đặt $\mathfrak{K}$ là một trong các cấu trúc $\operatorname{SEQ},\operatorname{PSET},\operatorname{MSET},\operatorname{CYC}$ nói trên, và

$$
\mathcal{A}=\mathfrak{K}_k(\mathcal{B}).
$$

Tức là mỗi $\alpha\in\mathcal{A}$ gồm đúng $k$ thành phần lấy từ $\mathcal{B}$, có dạng

$$
\alpha=(\beta_1,\beta_2,\dots,\beta_k),\qquad \beta_i\in\mathcal{B}.
$$

Gọi $\chi$ là hàm tác động lên đối tượng tổ hợp và trả về số lượng thành phần của nó, tức là yêu cầu $\chi(\alpha)=k$. Có thể thêm một biến để "theo dõi" số lượng thành phần.

Đặt

$$
A _ {n,k}=\operatorname{card}\left\lbrace \alpha\in\mathcal{A}\mid \lvert \alpha\rvert =n,\chi(\alpha)=k\right\rbrace.
$$

Khi đó

$$
A(z,u)=\sum _ {n,k}A _ {n,k}u^kz^n=\sum _ {\alpha\in\mathcal{A}}z^{\lvert \alpha\rvert}u^{\chi(\alpha)}.
$$

Sau đó chỉ cần trích hệ số của $u^k$ là thu được biểu thức tương ứng. Ví dụ, với $\mathcal{A}=\operatorname{SEQ}_k(\mathcal{B})$, có thể trực tiếp suy ra

$$
\begin{aligned}
&{}A(z,u)=\sum _ {k\geq 0}u^kB(z)^k=\frac{1}{1-uB(z)}\\
\implies &{}A(z)=B(z)^k.
\end{aligned}
$$

Cũng có

$$
\mathcal{A}=\operatorname{SEQ}_{\geq k}(\mathcal{B})\implies A(z)=\frac{B(z)^k}{1-B(z)}.
$$

Còn với $\operatorname{MSET} _ k(\mathcal{B})$ và $\operatorname{PSET} _ k(\mathcal{B})$ thì đã có

$$
\begin{aligned}
&{}A(z,u)=\prod_n\left(1-uz^n\right)^{-b_n}\\
\implies &{}A(z)=\lbrack u^k\rbrack \exp\left(\frac{u}{1}B(z)+\frac{u^2}{2}B(z^2)+\frac{u^3}{3}B(z^3)+\cdots\right)
\end{aligned}
$$

và

$$
\begin{aligned}
&{}A(z,u)=\prod_n\left(1+uz^n\right)^{b_n}\\
\implies &{}A(z)=\lbrack u^k\rbrack \exp\left(\frac{u}{1}B(z)-\frac{u^2}{2}B(z^2)+\frac{u^3}{3}B(z^3)-\cdots\right).
\end{aligned}
$$

Với $\operatorname{CYC}_k(\mathcal{B})$ cũng tương tự.

??? note "Dùng công thức trên để tính OGF tương ứng với $\operatorname{MSET}_3(\mathcal{B})$ và $\operatorname{MSET}_4(\mathcal{B})$"
    Thử tính $\mathcal{A}=\operatorname{MSET}_3(\mathcal{B})$:
    
    $$
    \begin{aligned}
    \lbrack u^3\rbrack A(z,u)&= \frac{1}{0!}\left(\lbrack u^3\rbrack 1\right)+\frac{1}{1!}\left(\lbrack u^3\rbrack \left(\frac{u}{1}B(z)+\frac{u^2}{2}B(z^2)+\frac{u^3}{3}B(z^3)+\cdots \right)\right)\\
    &+\frac{1}{2!}\left(\lbrack u^3\rbrack \left(\frac{u}{1}B(z)+\frac{u^2}{2}B(z^2)+\cdots \right)^2\right)\\
    &+\frac{1}{3!}\left(\lbrack u^3\rbrack \left(\frac{u}{1}B(z)+\cdots \right)^3\right)\\
    &=\frac{B(z)^3}{6}+\frac{B(z)B(z^2)}{2}+\frac{B(z)^3}{3}
    \end{aligned}
    $$
    
    Thử tính $\mathcal{A}=\operatorname{MSET}_4(\mathcal{B})$:
    
    $$
    \begin{aligned}
    \lbrack u^4\rbrack A(z,u)&= \frac{1}{0!}\left(\lbrack u^4\rbrack 1\right)+\frac{1}{1!}\left(\lbrack u^4\rbrack \left(\frac{u}{1}B(z)+\frac{u^2}{2}B(z^2)+\frac{u^3}{3}B(z^3)+\frac{u^4}{4}B(z^4)+\cdots \right)\right)\\
    &+\frac{1}{2!}\left(\lbrack u^4\rbrack \left(\frac{u}{1}B(z)+\frac{u^2}{2}B(z^2)+\frac{u^3}{3}B(z^3)+\cdots \right)^2\right)\\
    &+\frac{1}{3!}\left(\lbrack u^4\rbrack \left(\frac{u}{1}B(z)+\frac{u^2}{2}B(z^2)+\cdots \right)^3\right)\\
    &+\frac{1}{4!}\left(\lbrack u^4\rbrack \left(\frac{u}{1}B(z)+\cdots \right)^4\right)\\
    &=\frac{B(z^4)}{4}+\frac{1}{2!}\left(\frac{B(z^2)^2}{4}+\frac{2B(z)B(z^3)}{3}\right)+\frac{1}{3!}\left(\frac{3B(z)^2B(z^2)}{2}\right)+\frac{B(z)^4}{4!}\\
    &=\frac{B(z)^4}{24}+\frac{B(z)^2B(z^2)}{4}+\frac{B(z)B(z^3)}{3}+\frac{B(z^2)^2}{8}+\frac{B(z^4)}{4}
    \end{aligned}
    $$

Nhận thấy với $\mathcal{A}=\mathfrak{K}_k(\mathcal{B})$, $A(z)$ là một biểu thức theo $B(z),B(z^2),\dots ,B(z^k)$.

Cần lưu ý rằng với cấu trúc có ràng buộc $\mathfrak{K}_k(\mathcal{B})$, không yêu cầu $\mathcal{B}_0=\varnothing$.

???+ note "Các cấu trúc có ràng buộc thường dùng"
    $$
    \begin{aligned}
    \operatorname{PSET} _ {2}(\mathcal{A})&:\quad \frac{A(z)^2}{2}-\frac{A(z^2)}{2}\\
    \operatorname{MSET} _ {2}(\mathcal{A})&:\quad \frac{A(z)^2}{2}+\frac{A(z^2)}{2}\\
    \operatorname{CYC} _ {2}(\mathcal{A})&:\quad \frac{A(z)^2}{2}+\frac{A(z^2)}{2}
    \end{aligned}
    $$
    
    $$
    \begin{aligned}
    \operatorname{PSET} _ {3}(\mathcal{A})&:\quad \frac{A(z)^3}{6}-\frac{A(z)A(z^2)}{2}+\frac{A(z^3)}{3}\\
    \operatorname{MSET} _ {3}(\mathcal{A})&:\quad \frac{A(z)^3}{6}+\frac{A(z)A(z^2)}{2}+\frac{A(z^3)}{3}\\
    \operatorname{CYC} _ {3}(\mathcal{A})&:\quad \frac{A(z)^3}{3}+\frac{2A(z^3)}{3}\\
    \end{aligned}
    $$
    
    $$
    \begin{aligned}
    \operatorname{PSET} _ {4}(\mathcal{A})&:\quad \frac{A(z)^4}{24}-\frac{A(z)^2A(z^2)}{4}+\frac{A(z)A(z^3)}{3}+\frac{A(z^2)^2}{8}-\frac{A(z^4)}{4}\\
    \operatorname{MSET} _ {4}(\mathcal{A})&:\quad \frac{A(z)^4}{24}+\frac{A(z)^2A(z^2)}{4}+\frac{A(z)A(z^3)}{3}+\frac{A(z^2)^2}{8}+\frac{A(z^4)}{4}\\
    \operatorname{CYC} _ {4}(\mathcal{A})&:\quad \frac{A(z)^4}{4}+\frac{A(z^2)^2}{4}+\frac{A(z^4)}{2}\\
    \end{aligned}
    $$

Cách tính trên tuy hiệu quả nhưng khá rườm rà. Có thể đọc thêm các mục [định lý đếm Pólya](https://mathworld.wolfram.com/PolyaEnumerationTheorem.html) và [chỉ số chu trình](https://mathworld.wolfram.com/CycleIndex.html) trên Wolfram MathWorld; chỉ số chu trình cũng thường xuất hiện trong biểu thức hàm sinh trên OEIS.

???+ note "Bài tập [LOJ 6538. Đếm alkyl, bản tăng cường hai lần](https://loj.ac/p/6538)"
    **Đề bài**: tính số cây không thứ tự có $n$ đỉnh, có gốc và bậc của nút gốc không vượt quá $3$, còn bậc của các nút còn lại không vượt quá $4$, modulo $998244353$. Quy ước $1\leq n\leq 10^5$.
    
    **Lời giải**: gọi lớp tổ hợp là $\mathcal{T}$. Khi đó
    
    $$
    \mathcal{T}=\lbrace \bullet\rbrace\times\operatorname{MSET}_{0,1,2,3}(\mathcal{T})
    $$
    
    Hoặc đặt lớp tổ hợp $\hat{\mathcal{T}}=\mathcal{T}+\lbrace \epsilon\rbrace$. Khi đó
    
    $$
    \hat{\mathcal{T}}=\lbrace \epsilon\rbrace +\lbrace \bullet\rbrace\times\operatorname{MSET}_{3}(\hat{\mathcal{T}})
    $$
    
    và sẽ thu được cùng một kết quả.

<span id="tài-liệu-tham-khảo"></span>

## Tài liệu tham khảo

-   Philippe Flajolet and Robert Sedgewick. [Tổ hợp giải tích](http://algo.inria.fr/flajolet/Publications/books.html).
