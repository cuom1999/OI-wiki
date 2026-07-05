<span id="phân-rã-jordan"></span>
## Phân rã Jordan

Giả sử $T$ là một biến đổi tuyến tính trên không gian $n$ chiều $V$. Nếu đa thức tối tiểu của $T$ là:

$$
m_A(\lambda)={(\lambda-\lambda_1)}^{r_1}{(\lambda-\lambda_2)}^{r_2}\cdots{(\lambda-\lambda_k)}^{r_k}
$$

thì theo phân rã nguyên sơ, không gian $V$ có thể phân rã thành tổng trực tiếp của các không gian con:

$$
V=V_1\oplus V_2\oplus\cdots\oplus V_k
$$

trong đó $V_i=N\left({(A-\lambda_i I)}^{r_i}\right)$, với $A$ là ma trận tương ứng với $T$; các không gian con này đều bất biến dưới tác dụng của $T$.

Gọi biến đổi $T_i$ là phép chiếu của $V$ lên không gian con $V_i$, tức là xây dựng đa thức $u_i(T)$ sao cho:

-   $$
    T_i=u_i(T)\frac{m_A(T)}{{(T-\lambda_i T_e)}^{r_i}}
    $$
-   $$
    T_1+T_2+\cdots+T_k=T_e
    $$

trong đó $T_e$ biểu thị biến đổi đồng nhất của không gian $V$. Khi đó có các tính chất:

-   Hạn chế ${T_i|}_{V_i}$ của biến đổi $T_i$ trên không gian $V_i$ là biến đổi đồng nhất của không gian $V_i$.
-   Nếu $i$ và $j$ khác nhau, thì hạn chế ${T_i|}_{V_j}$ của biến đổi $T_i$ trên không gian $V_j$ là biến đổi không của không gian $V_j$.

Vì vậy biến đổi $T_i$ ánh xạ mỗi vectơ $\xi$ của không gian $V$ thành thành phần $\xi_i$ của nó trong không gian $V_i$.

Xây dựng biến đổi:

$$
T_D=\lambda_1 T_1+\lambda_2 T_2+\cdots+\lambda_k T_k
$$

Do mỗi biến đổi $T_i$ đều là một đa thức của biến đổi $T$, nên biến đổi $T_D$ cũng là một đa thức của biến đổi $T$; vì thế mỗi không gian con $V_i$ bất biến dưới biến đổi $T_D$.

Từ đẳng thức trên có thể biết rằng hạn chế ${T_D|}_{V_i}$ của biến đổi $T_D$ trên không gian con $V_i$ là một phép vị tự của không gian con $V_i$, với hệ số vị tự $\lambda_i$. Do đó biến đổi $T_D$ có thể chéo hóa.

Xây dựng:

$$
T_N=T-T_D
$$

Khi đó biến đổi $T_N$ cũng là một đa thức của biến đổi $T$, nên mỗi không gian con $V_i$ bất biến dưới biến đổi $T_N$. Với mọi vectơ $\xi_i$ trong không gian con $V_i$, ta có:

$$
{T_N}^{r_i}(\xi_i)={T-T_D}^{r_i}(\xi_i)={T-\lambda_i T_i}^{r_i}(\xi_i)=0
$$

Gọi $r$ là giá trị lớn nhất trong tất cả các $r_i$. Khi đó với mọi vectơ $\xi$ trong không gian $V$, lũy thừa bậc $r$ của biến đổi $T_N$ ánh xạ vectơ $\xi$ thành vectơ không. Vì vậy biến đổi $T_N$ là một biến đổi lũy linh.

Như vậy, mỗi biến đổi $T$ của không gian $V$ đều có thể viết thành:

$$
T=T_D+T_N
$$

trong đó $T_D$ chéo hóa được, còn $T_N$ là một biến đổi lũy linh. Vì $T_D$ và $T_N$ đều là các đa thức của biến đổi $T$, nên tích của chúng giao hoán:

$$
T_DT_N=T_NT_D
$$

Định lý: Giả sử $T_1$ và $T_2$ là hai biến đổi chéo hóa được của không gian $V$, và $T_1T_2=T_2T_1$. Khi đó tồn tại một cơ sở sao cho ma trận của $T_1$ và $T_2$ theo cùng cơ sở này đều có dạng đường chéo.

Định lý: Giả sử $T$ là một biến đổi tuyến tính trên không gian $n$ chiều $V$. Khi đó tồn tại một biến đổi chéo hóa được $T_D$ và một biến đổi lũy linh $T_N$ sao cho:

-   $$
    T=T_D+T_N
    $$
-   $$
    T_DT_N=T_NT_D
    $$

Chúng đều là các đa thức của biến đổi $T$, và được xác định duy nhất bởi biến đổi $T$.

Định lý này đưa ra một phân rã của biến đổi $T$, gọi là phân rã Jordan của $T$; $T_D$ được gọi là phần chéo hóa được của $T$, còn $T_N$ được gọi là phần lũy linh của $T$.

Tương tự, có phân rã Jordan của ma trận:

Định lý: Giả sử $A$ là một ma trận cấp $n$. Khi đó tồn tại một ma trận chéo hóa được $D$ và một ma trận lũy linh $N$ sao cho:

-   $$
    A=D+N
    $$
-   $$
    DN=ND
    $$

Chúng đều là các đa thức của ma trận $A$, và được xác định duy nhất bởi ma trận $A$.

Định lý này đưa ra một phân rã của ma trận $A$, gọi là phân rã Jordan của $A$; $D$ được gọi là phần chéo hóa được của $A$, còn $N$ được gọi là phần lũy linh của $A$.

<span id="ma-trận-lambda"></span>
## Ma trận lambda

Phần tiếp theo giới thiệu một loại ma trận tổng quát hơn có chứa tham số biến $\lambda$, không chỉ là một bảng số.

Đối với ma trận $\lambda$, trường tương ứng với không gian sẽ trở thành trường các biểu thức hữu tỉ chứa một biến $\lambda$.

Ma trận có phần tử là các đa thức theo $\lambda$ được gọi là ma trận $\lambda$, ký hiệu $A(\lambda)$.

Vì vành đa thức chứa trường số, ma trận số là một trường hợp đặc biệt của ma trận $\lambda$; ma trận đặc trưng $\lambda I-A$ của ma trận số $A$ là một loại ma trận $\lambda$.

<span id="biến-đổi-sơ-cấp-của-ma-trận-lambda"></span>
### Biến đổi sơ cấp của ma trận lambda

Với ma trận $\lambda$, ta cũng có thể định nghĩa phép cộng trừ, phép nhân, biến đổi sơ cấp, hạng. Với ma trận vuông $\lambda$, ta cũng có thể định nghĩa định thức, minor và phần bù đại số.

Với ma trận $\lambda$, các biến đổi sơ cấp phần lớn giống ma trận số, chỉ thay phép cộng bội thành (ở đây lấy biến đổi hàng làm ví dụ):

-   Nhân một hàng với đa thức $\varphi(\lambda)$ theo $\lambda$ rồi cộng vào một hàng khác.

Chú ý phép nhân một hàng với bội số không được sửa đổi. Lý do là phép cộng bội không làm thay đổi định thức, còn phép nhân bội làm thay đổi định thức. Để giữ tính chất hạng trên vành đa thức, định thức chỉ được phép thay đổi trên trường số.

Các ma trận sơ cấp tương ứng cũng được sửa đổi theo.

Dễ thấy định thức của cả ba loại ma trận sơ cấp đều là hằng số khác không, vì vậy chúng đều đủ hạng. Do đó nhân trái hoặc nhân phải với chúng không làm thay đổi hạng của ma trận $\lambda$.

Nếu $A(\lambda)$ qua hữu hạn lần biến đổi sơ cấp trở thành $B(\lambda)$, thì $A(\lambda)$ và $B(\lambda)$ được gọi là tương đương.

Với ma trận $\lambda$, nếu hai ma trận tương đương thì chúng có cùng hạng. Chiều ngược lại không đúng; đây là điểm khác với ma trận số.

<span id="dạng-chuẩn-smith"></span>
## Dạng chuẩn Smith

Định lý: Giả sử hạng của ma trận $\lambda$ là $r$, thì $A(\lambda)$ nhất định tương đương với:

$$
\begin{pmatrix}
D(\lambda) & 0\\
0 & 0\\
\end{pmatrix}
$$

trong đó:

$$
D(\lambda)=\begin{pmatrix}
d_1(\lambda) &  & \\
 & \ddots & \\
 &  & d_r(\lambda)\\
\end{pmatrix}
$$

Mỗi $d_i(\lambda)$ là một đa thức monic, và hai đa thức kề nhau có quan hệ chia hết $d_i(\lambda)|d_{i+1}(\lambda)$.

Dạng chuẩn này được gọi là dạng chuẩn Smith, và $d_i(\lambda)$ được gọi là nhân tử bất biến.

Cách cụ thể để tìm dạng chuẩn Smith là khử từ góc trên trái đến góc dưới phải; mỗi lần, phần tử ở góc trên trái là ước chung lớn nhất của toàn bộ các đa thức còn lại ở phía dưới bên phải, rồi dùng phần tử ở góc trên trái để khử toàn bộ hàng và cột đó về $0$.

Định lý: Điều kiện $A(\lambda)$ và $B(\lambda)$ tương đương tương đương với điều kiện $A(\lambda)$ và $B(\lambda)$ có đúng cùng các nhân tử bất biến.

<span id="nhân-tử-sơ-cấp"></span>
### Nhân tử sơ cấp

Theo định lý cơ bản của đại số, giả sử các nhân tử bất biến $d_1(\lambda),d_2(\lambda),\cdots,d_m(\lambda)$ của $A(\lambda)$ phân tích thành:

$$
d_i(\lambda)={(\lambda-\lambda_1)}^{e_{i1}}{(\lambda-\lambda_2)}^{e_{i2}}\cdots{(\lambda-\lambda_S)}^{e_{iS}}
$$

trong đó $\lambda_1,\cdots,\lambda_S$ đôi một khác nhau. Do:

$$
d_i(\lambda)|d_{i+1}(\lambda)
$$

nên các số mũ $e_{1j},e_{2j},\cdots,e_{mj}$ tăng dần, và các số mũ của mọi hạng tử trong hạng cuối $d_m(\lambda)$ đều khác không.

Toàn bộ các nhân tử có số mũ lớn hơn không trong công thức trên được gọi chung là các nhân tử sơ cấp của $A(\lambda)$.

Chú ý rằng nhân tử sơ cấp được tính cả bội. Nếu với một $j$ nào đó, số mũ $e_{ij}$ xuất hiện nhiều lần, thì nhân tử sơ cấp tương ứng ${(\lambda-\lambda_j)}^{e_{ij}}$ cũng phải xuất hiện số lần tương ứng.

Định lý trước cho biết $A(\lambda)$ và $B(\lambda)$ tương đương khi và chỉ khi chúng có hoàn toàn cùng các nhân tử bất biến. Nhân tử bất biến hoàn toàn giống nhau thì đương nhiên nhân tử sơ cấp cũng hoàn toàn giống nhau, nhưng chiều ngược lại không đúng. Thực ra có kết luận:

Định lý: $A(\lambda)$ và $B(\lambda)$ có hoàn toàn cùng nhân tử bất biến khi và chỉ khi chúng có hoàn toàn cùng nhân tử sơ cấp và cùng hạng.

Vì vậy, "nhân tử sơ cấp và hạng đều hoàn toàn giống nhau" cũng trở thành một điều kiện để phán đoán tính tương đương của ma trận $\lambda$.

Khi thực hiện biến đổi sơ cấp, cũng có thể trước tiên biến đổi $A(\lambda)$ thành ma trận đường chéo, rồi tìm nhân tử sơ cấp và hạng, sau đó tìm nhân tử bất biến để thu được dạng chuẩn. Có kết luận:

Định lý: Giả sử $A(\lambda)$ tương đương với ma trận đường chéo:

$$
\operatorname{diag}\{f_1(\lambda),f_2(\lambda),\cdots,f_r(\lambda),0,\cdots,0\}
$$

Khi đó toàn bộ các lũy thừa của nhân tử bậc nhất ${(\lambda-\lambda_j)}^{e_{ij}}$ trong $f_1(\lambda),f_2(\lambda),\cdots,f_r(\lambda)$ tạo thành các nhân tử sơ cấp của $A(\lambda)$.

Phương pháp cụ thể để xây dựng nhân tử bất biến từ nhân tử sơ cấp và hạng là: trước hết phân loại các nhân tử sơ cấp theo nhân tử, xếp thành bảng; với các nhân tử cùng loại, sắp theo lũy thừa giảm dần và đặt trong cùng một hàng; đặt lũy thừa cao nhất của mỗi loại nhân tử vào cùng một cột; dùng $1$ để bổ sung số cột đến hạng $r$; khi đó tích của từng cột tạo thành một nhân tử bất biến.

<span id="ứng-dụng-trong-ma-trận-đặc-trưng"></span>
### Ứng dụng trong ma trận đặc trưng

Nếu $A$ và $B$ là ma trận số, thì ma trận đặc trưng của chúng là ma trận $\lambda$. Có kết luận:

Định lý: Điều kiện ma trận số $A$ và $B$ tương tự tương đương với điều kiện ma trận đặc trưng $\lambda I-A$ và $\lambda I-B$ tương đương.

Vì ma trận đặc trưng $\lambda I-A$ chỉ chứa $n$ ký hiệu $\lambda$ trên đường chéo chính, nên hạng của nó là $n$. Từ suy luận trên, hạng của ma trận đặc trưng của các ma trận số cùng dạng luôn bằng nhau, do đó có tương đương:

Ma trận số $A$ và $B$ tương tự khi và chỉ khi các ma trận đặc trưng $\lambda I-A$ và $\lambda I-B$ có hoàn toàn cùng nhân tử sơ cấp.

Với ma trận đặc trưng $\lambda I-A$, biến đổi sơ cấp giữ tính tương đương, nên không làm thay đổi hạng.

Quan sát ba loại biến đổi sơ cấp: vì phép cộng bội duy nhất được sửa đổi không làm thay đổi định thức, trên thực tế ba loại biến đổi sơ cấp chỉ làm đa thức kết quả của định thức thay đổi bởi một bội hằng số, do đó không làm thay đổi phân tích nhân tử và bậc của đa thức kết quả của định thức.

Vì vậy định thức của ma trận đặc trưng $\lambda I-A$ là đa thức bậc $n$. Sau khi dùng biến đổi sơ cấp đưa nó về dạng chuẩn Smith, do hạng là $n$, định thức chính là tích của toàn bộ các nhân tử bất biến trên đường chéo chính, cũng bằng tích của toàn bộ các nhân tử sơ cấp. Do đó, tổng bậc của toàn bộ các nhân tử sơ cấp của ma trận đặc trưng $\lambda I-A$ bằng $n$.

<span id="dạng-chuẩn-jordan"></span>
## Dạng chuẩn Jordan

Ma trận:

$$
\begin{pmatrix}
\lambda & 1 & 0 & \cdots & 0 & 0\\
0 & \lambda & 1 & \cdots & 0 & 0\\
0 & 0 & \lambda & \cdots & 0 & 0\\
\vdots & \vdots & \vdots &  & \vdots & \vdots\\
0 & 0 & 0 & \cdots & \lambda & 1\\
0 & 0 & 0 & \cdots & 0 & \lambda\\
\end{pmatrix}
$$

có mọi phần tử trên đường chéo chính đều là $\lambda$, mọi phần tử ngay phía trên đường chéo chính đều là $1$, các vị trí còn lại đều là $0$, được gọi là một ma trận Jordan ứng với $\lambda$, hoặc khối Jordan.

Rõ ràng, ma trận Jordan lũy linh là một trường hợp đặc biệt của ma trận Jordan, tức trường hợp $\lambda$ bằng $0$.

Định lý: Giả sử $T$ là một biến đổi của không gian $n$ chiều $V$, và $\lambda_1,\cdots,\lambda_k$ là tất cả các giá trị riêng đôi một khác nhau của $T$. Khi đó tồn tại một cơ sở sao cho ma trận của $T$ theo cơ sở này có dạng:

$$
\begin{pmatrix}
B_1 &  &  & 0\\
 & B_2 &  & \\
 &  & \ddots & \\
0 &  &  & B_k\\
\end{pmatrix}
$$

trong đó:

$$
B_i=\begin{pmatrix}
J_{i1} &  &  & 0\\
 & J_{i2} &  & \\
 &  & \ddots & \\
0 &  &  & J_{is_i}\\
\end{pmatrix}
$$

và $J_{i1},\cdots,J_{is_i}$ đều là các khối Jordan ứng với $\lambda_i$.

Lý do là trước hết, theo đa thức tối tiểu:

$$
m_A(\lambda)={(\lambda-\lambda_1)}^{r_1}{(\lambda-\lambda_2)}^{r_2}\cdots{(\lambda-\lambda_k)}^{r_k}
$$

ta có phân rã nguyên sơ:

$$
V=V_1\oplus V_2\oplus\cdots\oplus V_k
$$

trong đó:

$$
V_i=N\left({(A-\lambda_i I)}^{r_i}\right)
$$

với $A$ là ma trận tương ứng với $T$.

Gọi biến đổi $S_i$ là hạn chế ${T|}_{V_i}$ của $T$ trên $V_i$; tiếp theo ta thử thực hiện phân rã Jordan cho từng $S_i$.

Ký hiệu $T_e$ là biến đổi đồng nhất trên $V$. Khác với phân rã Jordan ở phần trước, ký hiệu $T_i$ là phần lũy linh trong phân rã Jordan của $S_i$:

$$
S_i=\lambda_i T_e+T_i
$$

Khi đó $T_i$ là một biến đổi lũy linh của không gian con $V_i$, thực ra cũng là hạn chế ${(T-\lambda_i T_e)|}_{V_i}$ của $T-\lambda_i T_e$ trên $V_i$.

Không gian con $V_i$ có thể phân rã thành tổng trực tiếp của các không gian con cyclic của biến đổi lũy linh $T_i$:

$$
V_i=W_{i1}\oplus W_{i2}\oplus\cdots\oplus W_{is_i}
$$

Trong mỗi không gian con cyclic $W_{ij}$, chọn một cơ sở cyclic rồi sắp theo thứ tự ngược, ghép lại thành một cơ sở của $V_i$. Khi đó ma trận của $T_i$ theo cơ sở này có dạng:

$$
N_i=\begin{pmatrix}
N_{i1} &  &  & 0\\
 & N_{i2} &  & \\
 &  & \ddots & \\
0 &  &  & N_{is_i}\\
\end{pmatrix}
$$

Mọi $N_{ij}$ đều là khối Jordan lũy linh. Vì vậy với cơ sở được chọn ở trên của $V_i$, ma trận tương ứng với $S_i$ là:

$$
B_i=\begin{pmatrix}
\lambda_i &  &  & 0\\
 & \lambda_i &  & \\
 &  & \ddots & \\
0 &  &  & \lambda_i\\
\end{pmatrix}+\begin{pmatrix}
N_{i1} &  &  & 0\\
 & N_{i2} &  & \\
 &  & \ddots & \\
0 &  &  & N_{is_i}\\
\end{pmatrix}=\begin{pmatrix}
J_{i1} &  &  & 0\\
 & J_{i2} &  & \\
 &  & \ddots & \\
0 &  &  & J_{is_i}\\
\end{pmatrix}
$$

Ở đây $J_{i1},J_{i2},\cdots,J_{is_i}$ đều là các khối Jordan ứng với $\lambda_i$.

Với mỗi không gian con $V_i$, chọn một cơ sở theo cách trên, rồi ghép chúng lại thành cơ sở của $V$. Khi đó ma trận của $T$ theo cơ sở này chính là dạng được nêu trong định lý.

Ma trận cấp $n$ có dạng:

$$
\begin{pmatrix}
J_1 &  &  & 0\\
 & J_2 &  & \\
 &  & \ddots & \\
0 &  &  & J_m\\
\end{pmatrix}
$$

trong đó mỗi $J_i$ đều là một khối Jordan, được gọi là một dạng chuẩn Jordan.

Định lý: Mỗi ma trận cấp $n$ $A$ đều tương tự với một dạng chuẩn Jordan. Ngoài thứ tự sắp xếp của các khối Jordan, dạng chuẩn Jordan tương tự với $A$ được xác định duy nhất bởi $A$.

Chú ý rằng trong ma trận $B_i$ được xây dựng ở trên, hạng đầu là một bội của ma trận đơn vị, nên đương nhiên giao hoán với hạng thứ hai. Vì vậy hạng đầu chính là phần chéo hóa được trong phân rã Jordan của $B_i$, còn hạng thứ hai chính là phần lũy linh trong phân rã Jordan của $B_i$.

Trong dạng chuẩn Jordan tương ứng với một ma trận, ma trận đường chéo tạo bởi các phần tử trên đường chéo chính là phần chéo hóa được của dạng chuẩn Jordan tương ứng với ma trận đó; nếu thay các phần tử trên đường chéo chính bằng $0$, ta được phần lũy linh của dạng chuẩn Jordan tương ứng với ma trận đó.

Định lý: Trong dạng chuẩn Jordan của ma trận $A$, mỗi khối Jordan:

$$
J_i=\begin{pmatrix}
\lambda_i & 1 &  &  & \\
 & \lambda_i & 1 &  & \\
 &  & \ddots & \ddots & \\
 &  &  & \ddots & 1\\
 &  &  &  & \lambda_i\\
\end{pmatrix}
$$

tương ứng với một nhân tử sơ cấp ${(\lambda-\lambda_i)}^{n_i}$ của ma trận đặc trưng $\lambda I-A$; toàn bộ các nhân tử sơ cấp của ma trận đặc trưng $\lambda I-A$ tương ứng với toàn bộ các khối Jordan trong dạng chuẩn Jordan của ma trận $A$.

Lý do là ma trận $A$ tương tự với dạng chuẩn Jordan của nó, do đó ma trận đặc trưng của hai bên cũng tương đương; đưa ma trận đặc trưng của dạng chuẩn Jordan về dạng chuẩn Smith là có thể thấy điều này.

Từ định lý này, nhờ các nhân tử sơ cấp của ma trận đặc trưng $\lambda I-A$, ta có thể viết ra dạng chuẩn Jordan của ma trận $A$.

Một hệ quả là: ma trận $A$ chéo hóa được khi và chỉ khi các nhân tử sơ cấp của ma trận đặc trưng $\lambda I-A$ đều là bậc nhất.

<span id="định-lý-frobenius"></span>
## Định lý Frobenius

Phần trên đã chỉ ra rằng hạng của dạng chuẩn Smith của ma trận đặc trưng cấp $n$ là $n$.

Định lý: Giả sử dạng chuẩn Smith của ma trận đặc trưng $\lambda I-A$ của ma trận $A$ là:

$$
\operatorname{diag}\{d_1(\lambda),d_2(\lambda),\cdots,d_n(\lambda)\}
$$

thì nhân tử bất biến cuối cùng $d_n(\lambda)$ đúng bằng đa thức tối tiểu $m_A(\lambda)$ của ma trận $A$.

Hệ quả: Các điều kiện tương đương để ma trận $A$ chéo hóa được là:

-   Đa thức tối tiểu $m_A(\lambda)$ không có nghiệm bội.
-   Các nhân tử bất biến của ma trận đặc trưng $\lambda I-A$ không có nghiệm bội.
-   Các nhân tử sơ cấp của ma trận đặc trưng $\lambda I-A$ đều là bậc nhất.
