Phép hợp thành và nghịch đảo hợp thành của chuỗi lũy thừa hình thức cũng là những thao tác thường gặp trên chuỗi lũy thừa hình thức. Với $f$ không có tính chất đặc biệt, trước đây thường dùng thuật toán $O\left(n^2\right)$ (vẫn cần FFT) để tính $f(g) \bmod{x^n}$, trong đó $f\in\mathbb{C}\left\lbrack\left\lbrack x\right\rbrack\right\rbrack,g\in x\mathbb{C}\left\lbrack\left\lbrack x\right\rbrack\right\rbrack$. Tuy nhiên, do hiệu năng thấp nên cách này ít được áp dụng. Phần này giới thiệu thuật toán $O\left(\mathsf{M}\left(n\right)\log n\right)$ của Kinoshita-Li, trong đó $O\left(\mathsf{M}\left(n\right)\right)$ là thời gian nhân hai đa thức bậc $O\left(n\right)$.

<span id="hợp-thành-chuỗi-lũy-thừa-hình-thứcđa-thức"></span>
## Hợp thành chuỗi lũy thừa hình thức/đa thức

Để tính $f\left(g\left(x\right)\right)\bmod{x^n}$, mỗi hệ số của $f\left(g\left(x\right)\right)$ phải là tổng hữu hạn số hạng. Vì vậy trước đây cần yêu cầu $f(x)\in\mathbb{C}\left\lbrack\left\lbrack x\right\rbrack\right\rbrack,g(x)\in x\mathbb{C}\left\lbrack\left\lbrack x\right\rbrack\right\rbrack$; nếu $f(x),g(x)\in\mathbb{C}\left\lbrack x\right\rbrack$ thì điều kiện này cũng được thỏa mãn. Vì cần cắt cụt hệ số của $f\left(g\left(x\right)\right)$, có thể trực tiếp xét trường hợp cả $f(x)$ và $g(x)$ đều là đa thức. Với $f(x)=\sum_{j=0}^{n-1}f_jx^j$, có

$$
f\left(g\left(x\right)\right)=\sum_{j=0}^{n-1}f_jg\left(x\right)^j
$$

Xét hàm hữu tỉ trên vành $\mathbb{C}\left\lbrack x\right\rbrack\left(\left( y\right)\right)$:

$$
\begin{aligned}
\frac{f\left(y^{-1}\right)}{1-y\cdot g(x)}&=\sum_{j\geq 0}\left(\cdots +f_jy^{-j}+\cdots\right)g(x)^jy^j \\
f\left(g\left(x\right)\right)&=\left\lbrack y^0\right\rbrack\frac{f\left(y^{-1}\right)}{1-y\cdot g(x)}
\end{aligned}
$$

Theo thuật toán Bostan-Mori đã được nhắc trong [truy hồi tuyến tính thuần nhất hệ số hằng](./linear-recurrence.md), Kinoshita và Li chỉ ra rằng có thể sửa nó thành dạng hai biến:

$$
\begin{aligned}
\frac{P\left(y\right)}{Q\left(x,y\right)}\bmod{x^n}&=\left(\frac{P\left(y\right)}{Q\left(x,y\right)Q\left(-x,y\right)}\bmod{x^n}\right)Q\left(-x,y\right)\bmod{x^n} \\
&=\left(\frac{P(y)}{V(x^2,y)}\bmod{x^n}\right)Q\left(-x,y\right)\bmod{x^n} \\
&=\left.\left(\frac{P(y)}{V(z,y)}\bmod{z^{\left\lceil n/2\right\rceil}}\right)\right|_{z=x^2}Q\left(-x,y\right)\bmod{x^n}
\end{aligned}
$$

Khi tính đệ quy như vậy, tại $n=1$ chỉ cần tính

$$
\frac{P(y)}{Q(x,y)}\bmod{x}=\frac{P(y)}{Q(0,y)}\in\mathbb{C}\left(\left( y\right)\right)
$$

Khi tính $\dfrac{P(y)}{V(z,y)}\bmod{z^{\left\lceil n/2\right\rceil}}\in\mathbb{C}\left\lbrack z\right\rbrack\left(\left( y\right)\right)$, không cần giữ tất cả hệ số theo $y$, vì cuối cùng chỉ cần lấy hệ số của $y^0$. Do đó các hệ số của $y^{>0}$ là không cần thiết. Mặt khác, sau khi tính được biểu thức trên, cần nhân nó với một số "**đa thức**" có dạng $Q(-x,y)\in\mathbb{C}\left\lbrack x,y\right\rbrack$, nên chỉ cần giữ những hệ số có đóng góp vào $y^0$. Giả mã như sau:

$$
\begin{array}{ll}
&\textbf{Thuật toán }\operatorname{\mathsf{Comp}}\left(P(y),Q(x,y),n,m\right)\text{:} \\
&\textbf{Đầu vào}\text{: }P=\sum_{0\leq j< n}p_jy^{-j}\in\mathbb{C}((y)),Q\in\mathbb{C}\left\lbrack x,y\right\rbrack ,n,m\in\mathbb{N}_{>0}\text{.} \\
&\textbf{Đầu ra}\text{: }\left\lbrack y^{\left(-m,0\right\rbrack}\right\rbrack\dfrac{P(y)}{Q(x,y)}\bmod{x^n}\text{.} \\
&\textbf{Yêu cầu}\text{: }\left\lbrack x^0y^0\right\rbrack Q=1\text{.} \\
1&\textbf{nếu }n=1\textbf{ thì trả về }\left(\left\lbrack y^{-m+1}\right\rbrack\frac{P(y)}{Q(0,y)},\dots ,\left\lbrack y^0\right\rbrack\frac{P(y)}{Q(0,y)}\right) \\
2&V(x^2,y)\gets Q(x,y)Q(-x,y)\bmod{x^n} \\
3&d\gets\deg_y Q\left(-x,y\right)\\
4&\left(t_{-(m+d)+1},\dots ,t_0\right)\gets \operatorname{\mathsf{Comp}}\left(P(y),V(x,y),\left\lceil n/2\right\rceil,m+d\right) \\
5&T(x,y)\gets \sum_{j=-(m+d)+1}^0t_jy^j \\
6&U(x,y)=\sum_{j=-(m+d)+1}^d u_jy^j\gets T(x^2,y)Q(-x,y)\bmod{x^n} \\
7&\textbf{trả về }\left(u_{-m+1},\dots ,u_0\right)
\end{array}
$$

Khi đó

$$
f\left(g\left(x\right)\right)\bmod{x^n}=\operatorname{\mathsf{Comp}}\left(f\left(y^{-1}\right),1-y\cdot g(x),\max\left\lbrace 1+\deg f,n\right\rbrace ,1\right)\bmod{x^n}
$$

Lưu ý tham số thứ ba là để xử lí trường hợp $g(0)$ có thể khác không. Nếu $\deg f\geq n$ thì lúc này không thể cắt cụt $f(x)$ để tính $f\left(g(x)\right)$. Cũng có thể chọn tính $f(g)=f\circ \left(x+g(0)\right)\circ \left(g-g(0)\right)$; khi đó đặt $F:=f\left(x+g(0)\right)\bmod{x^n}$ và $G:=g-g(0)$, rồi chuyển sang tính $\operatorname{\mathsf{Comp}}\left(F\left(y^{-1}\right),1-y\cdot G(x),n,1\right)$.

Ngoài ra, do giới hạn của lời gọi, khi đệ quy kết thúc thì $Q(0,y)^{-1}$ có thể được suy ra trực tiếp, không cần dùng thuật toán nghịch đảo nhân của chuỗi lũy thừa hình thức. Chỉ cần tính một phép nhân rồi trích các hệ số cần thiết.

<span id="các-dạng-hợp-thành-đặc-biệt-thường-gặp"></span>
## Các dạng hợp thành đặc biệt thường gặp

Các [hàm sơ cấp của đa thức](./elementary-func.md) thường dùng đều có thể tính bằng phép hợp thành:

$$
\begin{aligned}
g(0)=1&,\space g^{-1}=1+(1-g)+(1-g)^2+\cdots \\
g(0)=1&,\space \log g=-\dfrac{1-g}{1}-\dfrac{(1-g)^2}{2}-\dfrac{(1-g)^3}{3}-\cdots \\
g(0)=0&,\space \exp g=1+\dfrac{g}{1!}+\dfrac{g^2}{2!}+\dfrac{g^3}{3!}+\cdots \\
g(0)=1&,\space g^e=1+\dfrac{e}{1!}(g-1)+\dfrac{e(e-1)}{2!}(g-1)^2+\cdots
\end{aligned}
$$

Trong quá trình tính nghịch đảo hợp thành, cũng sẽ dùng đến hàm lũy thừa.

<span id="thế-kronecker"></span>
### Thế Kronecker

Trước khi phân tích độ phức tạp thời gian, xét cách thực hiện phép nhân đa thức hai biến. Một ý tưởng là "đóng gói" các hệ số. Phương pháp này được Kronecker đưa ra năm 1882: thông qua phép thay $y\mapsto x^N$, phép nhân trên $R\left\lbrack x,y\right\rbrack$ được đưa về phép nhân trên $R\left\lbrack x\right\rbrack$, với điều kiện $N$ đủ lớn.

Giả sử $\deg_x \left(AB\right)<N$. Khi đó sau khi tính $A\left(x,x^N\right)B\left(x,x^N\right)$, vẫn có thể khôi phục $A(x,y)B(x,y)$, và thời gian "đóng gói" cũng như "mở gói" là tuyến tính.

Dùng thế Kronecker rồi tính phép nhân đa thức một biến. Khi $n$ là lũy thừa của hai, thuật toán trên hoàn thành trong $O\left(\mathsf{M}\left(n\right)\log n\right)$ thời gian, vì trong mỗi lần đệ quy bậc theo $y$ tăng gấp đôi còn bậc theo $x$ giảm một nửa.

??? note "Mẫu ([P5373 Mẫu hàm hợp thành đa thức](https://www.luogu.com.cn/problem/P5373))"
    Mã đã được đơn giản hóa và sửa đổi một phần so với thuật toán gốc, giúp ngắn gọn hơn.
    
    ```cpp
    --8<-- "docs/math/code/poly/comp-rev/comp_1.cpp"
    ```

<span id="nghịch-đảo-hợp-thành-của-chuỗi-lũy-thừa-hình-thức"></span>
## Nghịch đảo hợp thành của chuỗi lũy thừa hình thức

Cho $f\in x\mathbb{C}\left\lbrack\left\lbrack x\right\rbrack\right\rbrack$ và $f'(0)\neq 0$. Cần tìm $g(x)\bmod{x^n}$ sao cho $f(g)\equiv g(f)\equiv x\pmod{x^n}$.

Theo [nghịch đảo Lagrange](./lagrange-inversion.md), với $n>1,k\geq 0$ có

$$
\left\lbrack x^{n-1}\right\rbrack f(x)^k=\frac{k}{n-1}\left\lbrack x^{n-1-k}\right\rbrack \left(\frac{g(x)}{x}\right)^{-(n-1)}
$$

Nghĩa là nếu tính được $\left\lbrack x^{n-1}\right\rbrack f(x)^k$ cho $k=0,1,\dots ,n-1$, có thể suy ra nghịch đảo hợp thành.

Kinoshita và Li chỉ ra rằng có thể xét hàm hữu tỉ hai biến

$$
\frac{1}{1-y\cdot f(x)}=\sum_{j\geq 0}f(x)^jy^j
$$

Vấn đề này có một dạng tổng quát hơn, gọi là bài toán Power Projection: xét việc tính

$$
u:=\left\lbrack x^{n-1}\right\rbrack\frac{P(x,y)}{Q(x,y)}\bmod{y^m}
$$

Khi $n-1=0$, có $u=\dfrac{P(0,y)}{Q(0,y)}\bmod{y^m}$. Ngược lại, có

$$
\frac{P(x,y)}{Q(x,y)}=\frac{P(x,y)Q(-x,y)}{Q(x,y)Q(-x,y)}=\frac{U_e\left(x^2,y\right)+xU_o\left(x^2,y\right)}{V\left(x^2,y\right)}
$$

Do đó

$$
\begin{aligned}
u&=\begin{cases}
\left\lbrack x^{n-1}\right\rbrack\dfrac{U_e\left(x^2,y\right)}{V\left(x^2,y\right)}&\text{ nếu }n-1\text{ chẵn,} \\
\left\lbrack x^{n-1}\right\rbrack\dfrac{xU_o\left(x^2,y\right)}{V\left(x^2,y\right)}&\text{ nếu }n-1\text{ lẻ.}
\end{cases} \\
&=\begin{cases}
\left\lbrack x^{\left\lceil n/2\right\rceil-1}\right\rbrack\dfrac{U_e\left(x,y\right)}{V\left(x,y\right)}&\text{ nếu }n-1\text{ chẵn,} \\
\left\lbrack x^{\left\lceil n/2\right\rceil-1}\right\rbrack\dfrac{U_o\left(x,y\right)}{V\left(x,y\right)}&\text{ nếu }n-1\text{ lẻ.}
\end{cases}
\end{aligned}
$$

Giả mã:

$$
\begin{array}{ll}
&\textbf{Thuật toán }\operatorname{\mathsf{PowProj}}\left(P(x,y),Q(x,y),n,m\right)\text{:} \\
&\textbf{Đầu vào}\text{: }P,Q\in\mathbb{C}\left\lbrack x,y\right\rbrack ,n,m\in\mathbb{N}_{>0}\text{.} \\
&\textbf{Đầu ra}\text{: }\left\lbrack x^{n-1}\right\rbrack\dfrac{P(x,y)}{Q(x,y)}\bmod{y^m}\text{.} \\
&\textbf{Yêu cầu}\text{: }\left\lbrack x^0y^0\right\rbrack Q=1\text{.} \\
1&\textbf{trong khi }n>1\textbf{ làm} \\
2&\qquad U(x,y)\gets P(x,y)Q(-x,y)\bmod{x^n}\bmod{y^m} \\
3&\qquad \textbf{nếu }n-1\text{ là chẵn }\textbf{thì} \\
4&\qquad\qquad P(x,y)\gets \sum_{j=0}^{\left\lceil n/2\right\rceil +1}\left(\left\lbrack x^{2j}\right\rbrack U(x,y)\right)x^j \\
5&\qquad \textbf{ngược lại} \\
6&\qquad\qquad P(x,y)\gets \sum_{j=0}^{\left\lceil n/2\right\rceil +1}\left(\left\lbrack x^{2j+1}\right\rbrack U(x,y)\right)x^j \\
7&\qquad \textbf{kết thúc nếu} \\
8&\qquad V(x,y)\gets Q(x,y)Q(-x,y)\bmod{x^n}\bmod{y^m} \\
9&\qquad Q(x,y)\gets \sum_{j=0}^{\left\lceil n/2\right\rceil +1}\left(\left\lbrack x^{2j}\right\rbrack V(x,y)\right)x^j \\
10&\qquad n\gets \left\lceil n/2\right\rceil \\
11&\textbf{kết thúc vòng lặp} \\
12&\textbf{trả về }\left(\frac{P(0,y)}{Q(0,y)}\bmod{y^m}\right)
\end{array}
$$

Tương tự, cũng có thể suy ra trực tiếp $Q(0,y)^{-1}$ mà không cần tính nghịch đảo nhân của chuỗi lũy thừa hình thức. Khi đó thuật toán nghịch đảo hợp thành là

$$
\begin{array}{ll} &\textbf{Thuật toán }\operatorname{\mathsf{Rev}}(f(x),n)\text{:} \\
&\textbf{Đầu vào}\text{: }f\in x\mathbb{C}\left\lbrack\left\lbrack x\right\rbrack\right\rbrack, f'(0)\neq 0,n\in\mathbb{N}_{\geq 2}\text{.} \\
&\textbf{Đầu ra}\text{: }g(x)\bmod{x^n} \text{ sao cho }f(g)\equiv g(f)\equiv x\pmod{x^n}\text{.} \\
1&t\gets f'(0) \\
2&F(x)\gets f\left(t^{-1}x\right) \\
3&\sum_{k=0}^{n-1}a_ky^k\gets \operatorname{\mathsf{PowProj}}\left(1,1-y\cdot F(x),n,n\right) \\
4&G(x)\gets \sum_{k=1}^{n-1}\frac{n-1}{k}a_{k}x^{n-1-k} \\
5&H(x)\gets \left(G(x)^{1/(n-1)}\right)^{-1}\bmod{x^{n-1}} \\
6&\textbf{trả về }\left((t^{-1}x) \circ \left(x\cdot H\right)\right)
\end{array}
$$

??? note "Mẫu ([P5809 Mẫu nghịch đảo hợp thành đa thức](https://www.luogu.com.cn/problem/P5809))"
    Mã đã được đơn giản hóa và sửa đổi một phần so với thuật toán gốc, giúp ngắn gọn hơn.
    
    ```cpp
    --8<-- "docs/math/code/poly/comp-rev/rev_1.cpp"
    ```

<span id="suy-ra-từ-nguyên-lý-chuyển-vị"></span>
### Suy ra từ nguyên lý chuyển vị

Bài toán Power Projection là bài toán chuyển vị của Modular Composition. Kinoshita và Li chỉ ra rằng thuật toán hợp thành ở phần trên có thể thu được trực tiếp bằng cách chuyển vị thuật toán Power Projection. Tương tự, nếu một tối ưu hóa áp dụng được cho thuật toán Power Projection thì nó cũng áp dụng được cho thuật toán Modular Composition. Phần chi tiết được lược bỏ.

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

1.  Yasunori Kinoshita, Baitian Li.[Power Series Composition in Near-Linear Time](https://arxiv.org/abs/2404.05177). FOCS 2024.
2.  Alin Bostan, Ryuhei Mori.[A Simple and Fast Algorithm for Computing the N-th Term of a Linearly Recurrent Sequence](https://arxiv.org/abs/2008.08822). SOSA 2021: 118-132
3.  R. P. Brent and H. T. Kung. 1978.[Fast Algorithms for Manipulating Formal Power Series](https://doi.org/10.1145/322092.322099). J. ACM 25, 4 (Oct. 1978), 581-595.
4.  Daniel J. Bernstein. "[Fast multiplication and its applications](https://cr.yp.to/papers.html#multapps)." Pages 325-384 in Algorithmic number theory: lattices, number fields, curves and cryptography, edited by Joe Buhler, Peter Stevenhagen, Cambridge University Press, 2008, ISBN 978-0521808545.
