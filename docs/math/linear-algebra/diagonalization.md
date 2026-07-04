<span id="&#x7279;&#x5F81;&#x5B50;&#x7A7A;&#x95F4;"></span>
## Không gian con riêng

Toàn bộ các vectơ riêng của ma trận $A$ ứng với $\lambda_0$, sau khi thêm vectơ không, tạo thành một không gian tuyến tính, gọi là một không gian con riêng của ma trận $A$, ký hiệu $E(\lambda_0)$. Nó là không gian nghiệm của hệ phương trình tuyến tính thuần nhất:

$$
(\lambda_0 I-A)X=0
$$

Với không gian con riêng $E(\lambda_i)=N(\lambda_i I-A)$, theo định lý hạng và độ khuyết ta có:

$$
r(\lambda_i I-A)+\operatorname{dim} N(\lambda_i I-A)=n
$$

Vì vậy, số chiều của không gian con riêng $E(\lambda_i)$ là:

$$
\operatorname{dim} E(\lambda_i)=n-r(\lambda_i I-A)
$$

Số này cũng được gọi là **bội hình học** của $\lambda_i$.

<span id="&#x4E0D;&#x53D8;&#x5B50;&#x7A7A;&#x95F4;"></span>
## Không gian con bất biến

Khi nghiên cứu biến đổi tuyến tính $T$, ta thường muốn chọn một cơ sở của không gian $V$ sao cho ma trận của biến đổi tuyến tính $T$ theo cơ sở đó có dạng càng đơn giản càng tốt.

Giả sử $V$ là không gian tuyến tính trên trường số $F$, $W$ là một không gian con của $V$, và $T$ là một biến đổi tuyến tính trên $V$. Nếu với mọi vectơ $x$ trong $W$, $T(x)$ cũng thuộc $W$ (cũng nói là không gian bất biến hoặc ổn định dưới biến đổi), thì $W$ được gọi là một không gian con bất biến của $T$.

Không gian bất biến dưới biến đổi không có nghĩa là tọa độ thật sự "không đổi" dưới biến đổi; nó có thể bị kéo giãn hoặc biến dạng tương tự, chỉ là sau biến dạng vẫn rơi trong không gian đó.

-   Mọi không gian con của không gian tuyến tính $V$ đều là không gian con bất biến của phép nhân vô hướng.
-   Với mọi biến đổi tuyến tính $T$ trên $V$, không gian $V$ và không gian con không đều là các không gian con bất biến của $T$, gọi là các không gian con bất biến tầm thường.
-   Giao và tổng của các không gian con bất biến cũng là không gian con bất biến.

Giả sử $W$ là một không gian con bất biến của biến đổi tuyến tính $T$. Chỉ xét tác dụng của $T$ trên không gian con bất biến $W$, ta thu được một biến đổi tuyến tính của chính không gian con $W$, gọi là hạn chế của $T$ trên không gian con $W$, ký hiệu ${T|}_W$.

Với mọi biến đổi tuyến tính $T$ trên $V$, không gian ảnh $R(T)$ và không gian hạt nhân $N(T)$ là các không gian con bất biến của $T$. Ý nghĩa của hai trường hợp này là: trước và sau biến đổi, không gian $V$ đã hoàn thành việc nén chính nó (không gian ảnh), hoặc bị nén về $0$ (không gian hạt nhân).

Với mọi biến đổi tuyến tính $T$ trên $V$, không gian con riêng của $T$ là không gian con bất biến của $T$.

<span id="&#x51C6;&#x7D20;&#x5206;&#x89E3;"></span>
## Phân rã nguyên sơ

Theo định lý cơ bản của đại số, đa thức tối tiểu có thể phân tích thành:

$$
m_A(\lambda)={(\lambda-\lambda_1)}^{r_1}\cdots{(\lambda-\lambda_S)}^{r_S}
$$

Xét các không gian hạt nhân của từng nhân tử sau khi thay biến $\lambda$ trong đa thức tối tiểu bằng ma trận $A$; chúng tạo thành một loạt không gian con bất biến của ma trận $A$:

$$
W_i=N({(\lambda_i I-A)}^{r_i})
$$

Định lý: Số chiều của không gian con bất biến $W_i$ này đúng bằng bội đại số của giá trị riêng $\lambda_i$.

Nhắc lại, bội đại số là bậc của từng nhân tử trong phân tích đa thức đặc trưng, còn bội hình học là số chiều của không gian con riêng $E(\lambda_i)=N(\lambda_i I-A)$. Không gian con bất biến $W_i$ và không gian con riêng $E(\lambda_i)$ đều là không gian hạt nhân của ma trận, và hai ma trận liên hệ với nhau bằng lũy thừa bậc $r_i$ trong đa thức tối tiểu. Nói cách khác, số chiều của không gian con riêng là bội hình học; sau khi "không gian con riêng" đi qua lũy thừa bậc $r_i$ trong đa thức tối tiểu thì đến một "không gian con bất biến", và số chiều của không gian con bất biến đạt đến bội đại số của đa thức đặc trưng.

Định lý này thực ra là một hệ quả của định lý phân rã nguyên sơ dưới đây.

Ký hiệu biến đổi tuyến tính tương ứng với ma trận $A$ là $T$, và hạn chế của nó trên mỗi không gian con $W_i$ là $T_i={T|}_{W_i}$. Khi đó đa thức tối tiểu của $T_i$ là $(x-\lambda_i)^{r_i}$.

Định lý: Giả sử $V$ là không gian tuyến tính trên trường $F$, và $T$ là một biến đổi tuyến tính trên $V$. Khi đó không gian $V$ có thể được phân rã nguyên sơ theo biến đổi tuyến tính $T$, tách thành tổng trực tiếp của một số không gian con bất biến $W_i$.

$$
V=W_1\oplus W_2\oplus\cdots\oplus W_S
$$

Điều này có nghĩa là ma trận của $T$ theo một cơ sở nào đó là ma trận gần đường chéo:

$$
\operatorname{diag}\{A_1,A_2,\cdots,A_S\}
$$

trong đó $A_i$ là ma trận của $T_i$ theo cơ sở tương ứng.

Định lý này cho thấy có thể dùng không gian con bất biến để đơn giản hóa ma trận của biến đổi tuyến tính.

<span id="&#x53EF;&#x5BF9;&#x89D2;&#x5316;&#x77E9;&#x9635;"></span>
## Ma trận chéo hóa được

Với ma trận vuông cấp $n$ $A$, nếu nó tương tự với một ma trận đường chéo, thì $A$ được gọi là ma trận chéo hóa được, hoặc ma trận đơn thuần.

-   Tổng, tích, và nghịch đảo nếu tồn tại của các ma trận đường chéo vẫn là ma trận đường chéo; các phần tử trên đường chéo chính là các giá trị riêng của chúng.
-   Ma trận của biến đổi tuyến tính $T$ là ma trận chéo hóa được khi và chỉ khi ma trận của $T$ theo một cơ sở nào đó là ma trận đường chéo.

Định lý: Giả sử tất cả các nghiệm riêng phân biệt của ma trận $A$ là $\lambda_1,\cdots,\lambda_m$. Khi đó các mệnh đề sau tương đương:

-   Ma trận $A$ chéo hóa được.
-   Ma trận $A$ có $n$ vectơ riêng độc lập tuyến tính.
-   Công thức sau đúng:

$$
\operatorname{dim} E(\lambda_1)+\cdots+\operatorname{dim} E(\lambda_m)=n
$$

Phần trước đã chỉ ra rằng bậc xuất hiện của giá trị riêng trong phân tích đa thức đặc trưng được gọi là bội đại số, còn số chiều của không gian con riêng được gọi là bội hình học. Định lý này cũng cho thấy ma trận $A$ chéo hóa được khi và chỉ khi với mỗi giá trị riêng $\lambda$ của $A$, bội đại số của nó bằng bội hình học của nó.

Hệ quả: Nếu ma trận vuông cấp $n$ $A$ có đúng $n$ giá trị riêng phân biệt, thì nó chắc chắn chéo hóa được. Chiều ngược lại không nhất thiết đúng.

Định lý: Ma trận $A$ chéo hóa được khi và chỉ khi đa thức tối tiểu của $A$ không có nghiệm bội.

Tương tự ma trận cũng giữ nguyên quan hệ phụ thuộc tuyến tính giữa các vectơ riêng.

Vectơ riêng hoàn toàn có thể không phải là số thực, và cũng hoàn toàn có thể không tìm được $n$ vectơ riêng độc lập tuyến tính.

Với giá trị riêng bội, các vectơ riêng sinh ra một không gian. Để mô tả không gian này, cần chọn các đại diện từ đó.

Khi chọn đại diện, thường chọn các đại diện độc lập tuyến tính; số lượng đại diện chính là số chiều của không gian.

Khi chọn đại diện, người ta thường trực giao hóa và chuẩn hóa chúng. Kết quả cuối cùng là một hệ đại diện trực chuẩn.

Vectơ riêng không nhất thiết trực giao; các vectơ riêng ứng với giá trị riêng khác nhau có thể không trực giao. Vì vậy trực giao hóa chỉ có thể thực hiện đối với các vectơ riêng của giá trị riêng bội. Tuy nhiên chuẩn hóa có thể thực hiện với mọi vectơ riêng.

<span id="&#x5E42;&#x96F6;&#x77E9;&#x9635;"></span>
## Ma trận lũy linh

Giả sử $T$ là một biến đổi tuyến tính của không gian $V$. Nếu tồn tại một số nguyên dương $r$ sao cho $T^r$ là biến đổi không, thì $T$ được gọi là một biến đổi lũy linh của không gian $V$.

Ma trận thỏa mãn $N^r=0$ với một số nguyên dương $r$ nào đó được gọi là ma trận lũy linh.

Thông thường có thể giả sử thêm rằng $r$ là số nguyên dương nhỏ nhất khiến $T^r$ là biến đổi không; khi đó đa thức tối tiểu của $T$ là $x^r$. Vì vậy tồn tại một vectơ $\xi_0$ sao cho:

-   $$
    T^r(\xi_0)=0
    $$
-   $$
    T^{r-1}(\xi_0)\neq 0
    $$

<span id="&#x5FAA;&#x73AF;&#x5B50;&#x7A7A;&#x95F4;"></span>
### Không gian con cyclic

Định lý: Giả sử $T$ là một biến đổi tuyến tính của không gian $V$, và $\xi$ là một vectơ của không gian $V$. Nếu tồn tại một số nguyên dương $s$ sao cho:

-   $$
    T^s(\xi)=0
    $$
-   $$
    T^{s-1}(\xi)\neq 0
    $$

thì các vectơ $\xi,T(\xi),\cdots,T^{s-1}(\xi)$ độc lập tuyến tính.

Từ định lý này có thể đưa ra một định nghĩa:

Giả sử $T$ là một biến đổi tuyến tính của không gian $V$, và $W$ là một không gian con của $V$. Nếu tồn tại một vectơ $\xi_0$ và một số nguyên dương $r$ sao cho:

-   Các vectơ $\xi_0,T(\xi_0),\cdots,T^{r-1}(\xi_0)$ tạo thành một cơ sở của $W$.
-   Đẳng thức sau đúng:

    $$
    T^r(\xi_0)=0
    $$

thì không gian con $W$ được gọi là một không gian con cyclic đối với $T$, gọi tắt là không gian con $T$-cyclic. Khi đó $\xi_0$ được gọi là một vectơ sinh của không gian con cyclic $W$, còn các vectơ $\xi_0,T(\xi_0),\cdots,T^{r-1}(\xi_0)$ được gọi là một cơ sở cyclic của $W$.

Rõ ràng, một không gian con $T$-cyclic $W$ bất biến dưới tác dụng của $T$, và với mọi vectơ $\xi$ trong không gian con cyclic $W$, đều có $T^r(\xi)=0$, trong đó $r$ là số chiều của không gian con cyclic.

<span id="&#x5E42;&#x96F6;-jordan-&#x5757;"></span>
### Khối Jordan lũy linh

Nếu không gian $W$ là không gian con cyclic của biến đổi $T$, thì hạn chế ${T|}_W$ của $T$ trên $W$ là một biến đổi lũy linh của $W$, và ma trận của ${T|}_W$ theo cơ sở cyclic của $W$ được sắp theo thứ tự ngược $T^{r-1}(\xi_0),T^{r-2}(\xi_0),\cdots,\xi_0$ là ma trận tam giác trên cấp $r$ có dạng:

$$
N_r=\begin{pmatrix}
0 & 1 & 0 & \cdots & 0 & 0\\
0 & 0 & 1 & \cdots & 0 & 0\\
0 & 0 & 0 & \cdots & 0 & 0\\
\vdots & \vdots & \vdots &   & \vdots& \vdots\\
0 & 0 & 0 & \cdots & 0 & 1\\
0 & 0 & 0 & \cdots & 0 & 0\\
\end{pmatrix}
$$

Ma trận $N_r$ được gọi là một ma trận Jordan lũy linh cấp $r$, hoặc khối Jordan lũy linh cấp $r$.

Giả sử $T$ là một biến đổi lũy linh của không gian $n$ chiều $V$. Dãy số nguyên dương duy nhất $r_1\geq\cdots\geq r_S$ xuất hiện trong phân rã của $V$ thành các không gian con cyclic đối với $T$ được gọi là các chỉ số bất biến của $T$.

Với ma trận lũy linh cấp $n$ $A$, $A$ tương tự với một ma trận $N$ có dạng như trên, và cũng xác định duy nhất một dãy số nguyên dương $r_1\geq\cdots\geq r_S$, gọi là các chỉ số bất biến của ma trận $A$.

Ma trận lũy linh tuy không thể tương tự với ma trận đường chéo, nhưng có thể tương tự với dạng chuẩn như vậy. Trong dạng chuẩn Jordan, việc chéo hóa tương tự và dạng chuẩn của ma trận lũy linh được kết hợp để đưa ra dạng chuẩn mà một ma trận tổng quát có thể đạt được thông qua biến đổi tương tự.

<span id="&#x4E00;&#x4E9B;&#x5B9A;&#x7406;"></span>
### Một số định lý

1.  Giả sử $T$ là một biến đổi lũy linh của không gian $V$, và

    $$
    h(x)=a_0+a_1x+\cdots+a_mx^m
    $$

    là một đa thức. Khi đó biến đổi tuyến tính $h(T)$ có biến đổi nghịch đảo khi và chỉ khi $a_0\neq 0$. Khi $h(T)$ khả nghịch, biến đổi nghịch đảo của $h(T)$ cũng là một đa thức của $T$.

2.  Giả sử $T$ là một biến đổi lũy linh của không gian $V$, $W$ là một không gian con $T$-cyclic $r$ chiều, và $\xi$ là một vectơ trong $W$. Nếu tồn tại một số nguyên $k$ sao cho:

    $$
    T^{r-k}(\xi)=0
    $$

    thì tồn tại vectơ $\eta$ trong $W$ sao cho:

    $$
    \xi=T^k(\eta)
    $$

3.  Giả sử $T$ là một biến đổi lũy linh của không gian $n$ chiều $V$, $x^r$ là đa thức tối tiểu của $T$, và $W_1$ là một không gian con $T$-cyclic $r$ chiều. Khi đó tồn tại một không gian con bù $W_2$ của $W_1$ sao cho:

    $$
    V=W_1\oplus W_2
    $$

    đồng thời $W_2$ cũng bất biến dưới tác dụng của $T$.

4.  Giả sử $T$ là một biến đổi lũy linh của không gian $n$ chiều $V$. Khi đó $V$ có thể phân rã thành tổng trực tiếp của các không gian con $T$-cyclic:

    $$
    V=W_1\oplus W_2\oplus\cdots\oplus W_S
    $$

5.  Mỗi ma trận lũy linh cấp $n$ đều tương tự với một ma trận có dạng:

    $$
    N=\begin{pmatrix}
    N_{r_1} &   &   & 0\\
      & N_{r_2} &   &  \\
      &   & \cdots &  \\
    0 &   &   & N_{r_S}\\
    \end{pmatrix}
    $$

    trong đó mỗi $N_{r_i}$ là một khối Jordan lũy linh cấp $r_i$.

6.  Nếu quy định các không gian con $T$-cyclic $W_i$ được sắp theo số chiều $r_i$ giảm dần $r_1\geq\cdots\geq r_S$, thì cách phân rã $V$ thành các không gian con $T$-cyclic được xác định duy nhất bởi $T$.
