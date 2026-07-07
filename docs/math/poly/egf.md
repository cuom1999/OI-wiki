author: sshwy, ComeIntoCalm

Hàm sinh mũ (exponential generating function, EGF) của dãy $a$ được định nghĩa là chuỗi lũy thừa hình thức:

$$
\hat{F}(x)=\sum_{n}a_n \frac{x^n}{n!}
$$

<span id="phép-toán-cơ-bản"></span>
## Phép toán cơ bản

Phép cộng và trừ của hàm sinh mũ giống với hàm sinh thường, tức là cộng các hệ số tương ứng.

Xét phép nhân của hàm sinh mũ. Với hai dãy $a,b$, giả sử hàm sinh mũ của chúng lần lượt là $\hat{F}(x),\hat{G}(x)$. Khi đó

$$
\begin{aligned}
\hat{F}(x)\hat{G}(x)
&=\sum_{i\ge 0}a_i\frac{x^i}{i!}\sum_{j\ge 0}b_j\frac{x^j}{j!}\\
&=\sum_{n\ge 0}x^{n}\sum_{i=0}^na_ib_{n-i}\frac{1}{i!(n-i)!}\\
&=\sum_{n\ge 0}\frac{x^{n}}{n!}\sum_{i=0}^n\binom{n}{i}a_ib_{n-i}
\end{aligned}
$$

Do đó $\hat{F}(x)\hat{G}(x)$ là hàm sinh mũ của dãy

$$
\left\langle \sum_{i=0}^n \binom{n}{i}a_ib_{n-i} \right\rangle
$$

<span id="dạng-đóng"></span>
## Dạng đóng

Tiếp theo xét dạng đóng của hàm sinh mũ.

Hàm sinh mũ của dãy $\langle 1,1,1,\cdots\rangle$ là:

$$
\hat{F}(x) = \sum_{n \ge 0}\frac{x^n}{n!} = \mathrm{e}^x
$$

Vì khai triển Maclaurin của $\mathrm{e}^x$ chính là chuỗi vô hạn này.

Tương tự, hàm sinh mũ của cấp số nhân $\langle 1,p,p^2,\cdots\rangle$ là:

$$
\hat{F}(x) = \sum_{n\ge 0}\frac{p^nx^n}{n!}=\mathrm{e}^{px}
$$

<span id="hàm-sinh-mũ-và-hàm-sinh-thường"></span>
## Hàm sinh mũ và hàm sinh thường

Hàm sinh mũ có thể được hiểu từ định nghĩa của nó. Hàm sinh mũ của dãy $a$ là:

$$
F(x)=\sum_{n\ge 0}a_n\frac{x^n}{n!}
$$

Mặt khác, $F(x)$ cũng là hàm sinh thường của dãy $\left\langle \dfrac{a_n}{n!} \right\rangle$.

Cả hai cách hiểu đều không có vấn đề. Nói cách khác, các loại hàm sinh khác nhau chỉ là những cách chuyển đổi góc nhìn đối với bài toán.

<span id="ý-nghĩa-tổ-hợp-của-exp-đa-thức-trong-egf"></span>
## Ý nghĩa tổ hợp của exp đa thức trong EGF

Có thể bỏ qua phần này nếu chưa học exp đa thức. Nội dung dưới đây rút ra ý nghĩa từ cách hiểu exp và giúp làm rõ hơn EGF.

Trong EGF, $f$ trong $f^n(x)$ mặc định là một EGF. Trước hết xét tích của hai EGF bất kỳ:

$$
\hat{H}(x) = \hat{F}(x)\hat{G}(x) = \sum_{n\geq 0} \left[ \sum_{i = 0}^n\binom {n}{i}f_ig_{n-i} \right] \frac{x^n}{n!}
$$

Với $[x^k]\hat{H}(x)$ thu được từ tích của hai EGF, về bản chất đó là một tích chập. Nếu xét $[x^k]\hat{H}(x)$ thu được từ tích của nhiều EGF, thì đó là tổng hệ số của mọi cách chọn một hạng tử $x^{a_i}$ từ mỗi EGF sao cho $\sum_ia_i=k$.
Nhìn theo góc độ tập hợp, đó là số cách chia $n$ phần tử có nhãn thành $k>0$ tập hợp có nhãn.

> Nếu $k=0$ thì hệ số bằng tích các hằng số của từng EGF. Tuy nhiên, một số yêu cầu trong exp đa thức khiến hằng số của $f(x)$ trong $\exp$ phải bằng $0$; nguyên nhân cụ thể sẽ được giải thích ở bên dưới.

Trong định nghĩa hệ số đa thức (xem ý nghĩa tổ hợp của hệ số đa thức trong phần hoán vị và tổ hợp), mặc định các tập hợp có thứ tự. Nhưng trong $\exp(f(x))$, các EGF thu được từ $f^k(x)$, tức tích của $k$ bản sao $f(x)$, là như nhau; còn phép chia tập hợp không có thứ tự. Vì vậy hệ số phải nhân thêm $\dfrac{1}{k!}$.

Gọi $F_k(n)$ là số cách chia $n$ phần tử có nhãn thành $k$ tập con không rỗng, không thứ tự (vì là $\exp$ nên yêu cầu không rỗng). Gọi $f_i$ là số cấu trúc tổ hợp cụ thể trên một tập hữu hạn gồm $i$ phần tử khi một tập có $i$ phần tử (đây là EGF ban đầu, đếm phương án trên phần tử của một tập, chỉ phụ thuộc vào kích thước tập). Khi đó

$$
F_k(n)=\frac{n!}{k!}\sum_{\sum_{i}^ka_i=n}\prod_{j=1}^{k}\frac{f_{a_j}}{a_j!}
$$

Gọi EGF của $f_n$ là $\hat{F}(x)$, tức là:

$$
\hat{F}(x) = \sum_{n \geq 0} f_n\frac{x^n}{n!}
$$

Gọi EGF của $F_k(n)$ là $G_k(x)$, thu được:

$$
\begin{aligned}
G_k(x)&=\sum_{n \geq 0} F_k(n)\frac{x^n}{n!}\\
&=\sum_{n \geq 0} x^n\frac{1}{k!}\sum_{\sum_i^k a_i=n}\prod_{j=1}^{k}\frac{f_{a_j}}{a_j!}\\
&=\frac{1}{k!}\sum_{n \geq 0}\sum_{\sum_i^k a_i=n}\prod_{j=1}^{k}\frac{f_{a_j}x^{a_j}}{a_j!}\\
&=\frac{1}{k!}\hat{F}^k(x)
\end{aligned}
$$

Với mọi $k \geq 0$:

$$
\sum_{k \geq 0}G_k(x) = \sum_{k \geq 0}\frac{\hat{F}^k(x)}{k!} = \exp{\hat{F}(x)}
$$

Phần trên là cách lập biểu thức trực tiếp từ góc độ tổ hợp. Quan hệ giữa $\exp(f(x))$ và $f(x)$ cũng có thể được chứng minh bằng truy hồi.

Tương tự, gọi $F_k(n)$ là số cách chia $n$ phần tử có nhãn thành $k$ tập con không rỗng (không có nhãn), $g_i$ là số phương án bên trong một tập gồm $i$ phần tử (ý nghĩa giống $f_i$ ở trên). Đặt $G(x)$ là EGF của $\{g_i\}$ và $H_k(x)$ là EGF của $\{F_k(n)\}$.

Trong $n$ phần tử, chọn $i$ phần tử làm một tập riêng biệt có $g_i$ phương án. $n-i$ phần tử còn lại tạo thành $k-1$ tập, có $F_{k-1}(n-i)$ phương án. Nhưng trong phương án chia cuối cùng, mỗi tập đều sẽ được liệt kê như tập riêng được tách ra, nên bị đếm lặp $k$ lần; do đó cần chia thêm cho $k$.

$$
\begin{aligned}
H_k(x) &= \sum_{n\ge 0}\cfrac{x^n}{n!}F_k(n)\\
&=\sum_{n\ge 0}\cfrac{x^n}{n!}\sum_{i=1}^{n-k+1}\binom n {i} F_{k-1}(n-i)\times g_i\times \cfrac{1}{k}\\
&=\cfrac{1}{k}\sum_{n\ge 0}\cfrac{x^n}{n!}\sum_{i=0}^{n}\binom n {i}F_{k-1}(n-i)\times g_i\\
&=\cfrac{1}{k}\cdot  H_{k-1}(x)G(x)
\end{aligned}
$$

Cận trên xuất phát từ điều kiện chia thành các tập không rỗng: $n-(k-1)\geq i$ (mỗi tập trong $k-1$ tập trước ít nhất có một phần tử). Nếu đặt $F_{k-1}(n-i)=0$ khi vượt quá cận liệt kê, kết quả không đổi.

Sau khi có truy hồi, khai triển đệ quy với biên $H_1(x)=G(x)$ khi $k=1$.

$$
\begin{aligned}
H_k(x) &= \cfrac{1}{k}\cdot   H_{k-1}(x)G(x)\\
&= \cfrac{1}{k}\cdot\cfrac{1}{k-1}\cdot   H_{k-2}(x)G^2(x)\\
&=\cdots \\
&= \cfrac{1}{k}\cdot\cfrac{1}{k-1} \cdots\cfrac{1}{2}\cdot H_{1}(x)G^{k-1}(x)\\
&= \cfrac{1}{k!}G^{k}(x)\\
\end{aligned}
$$

Tương tự:

$$
\begin{aligned}
\sum_{k\ge 0}H_k(x)=\sum_{k\ge 0}\cfrac{G^k(x)}{k!}=\exp G(x)
\end{aligned}
$$

Do đó, **định nghĩa là chia thành các tập không rỗng** ($g_0=0$) phù hợp với ý nghĩa vốn có. Nếu **cho phép tập rỗng** ($g_0=1$), thì trong $[x^n]G^k$ sẽ có đóng góp từ $[x^n]G^y,y>k$ (do chọn hằng số ở ít nhất một $G$), gây đếm lặp và không thu được đại lượng cần tìm.

Từ góc độ truy hồi, tích của nhiều EGF cũng có thể xem như một dạng tổ hợp giống bài toán ba lô (quá trình gộp hai nhóm đối tượng đếm).

Tóm lại, ý nghĩa của $\exp$ đa thức là: **số cách tạo một họ tập hợp từ các phần tử có nhãn**, hoặc tổng số phương án chia thành tùy ý số tập con không rỗng.

<span id="hoán-vị-và-hoán-vị-vòng"></span>
## Hoán vị và hoán vị vòng

Hàm sinh mũ của số hoán vị độ dài $n$ là

$$
\hat{P}(x)=\sum_{n\ge 0}\frac{n!x^n}{n!}=\sum_{n\ge 0}x^n=\frac{1}{1-x}
$$

Hoán vị vòng được định nghĩa là số cách xếp $1,2,\cdots,n$ thành một vòng. Nói cách khác, các cách chỉ khác nhau bởi phép quay là tương đương (nhưng phép lật thì không tương đương).

Số hoán vị vòng của $n$ số là $(n-1)!$. Vì vậy hàm sinh mũ của số hoán vị vòng của $n$ số là

$$
\hat{Q}(x)=\sum_{n\ge 1}\frac{(n-1)!x^n}{n!}=\sum_{n\ge 1}\frac{x^n}{n}=-\ln(1-x)=\ln\left( \frac{1}{1-x} \right)
$$

Nói cách khác, $\exp \hat{Q}(x)=\hat{P}(x)$. Nhưng đó chỉ là suy luận ở mức toán học. Trực giác nên hiểu thế nào: vì sao $\exp$ của EGF của hoán vị vòng lại là EGF của hoán vị?

Một hoán vị được tạo bởi một số chu trình hoán vị. Ví dụ $p=[4,3,2,5,1]$ có hai chu trình hoán vị:

![](./images/p1.png)

(tức là nối cạnh có hướng từ $p_i$ tới $i$)

Các chu trình hoán vị khác nhau sẽ dẫn đến các hoán vị khác nhau. Ví dụ đổi chu trình hoán vị thứ hai thành

![](./images/p2.png)

thì hoán vị tương ứng là $[5,3,2,1,4]$.

Nói cách khác, số phương án của hoán vị độ dài $n$ là:

1.  Chia $1,2,\cdots,n$ thành một số tập.
2.  Mỗi tập tạo thành một chu trình hoán vị.

Số cách để các phần tử trong một tập tạo thành chu trình hoán vị chính là số hoán vị vòng theo kích thước của tập đó. Vì vậy số hoán vị độ dài $n$ bằng số cách chia $1,2,\cdots,n$ thành một số tập, rồi lấy tích số phương án hoán vị vòng của từng tập.

Đó là trực giác của $\exp$ đa thức.

Tổng quát hơn:

-   Nếu EGF của cây sinh **có nhãn** trên $n$ đỉnh là $\hat{F}(x)$, thì EGF của rừng sinh **có nhãn** trên $n$ đỉnh là $\exp \hat{F}(x)$: trực giác là chia $n$ đỉnh thành một số tập, mỗi tập tạo thành một cây sinh, rồi nhân số phương án của từng tập.
-   Nếu EGF của đồ thị vô hướng liên thông có nhãn trên $n$ đỉnh là $\hat{F}(x)$, thì EGF của đồ thị vô hướng có nhãn trên $n$ đỉnh là $\exp \hat{F}(x)$. EGF sau có thể tính trực tiếp:

    $$
    \exp \hat{F}(x)=\sum_{n\ge 0}2^{\binom{n}{2}}\frac{x^n}{n!}
    $$

    Vì vậy muốn tính EGF trước, chỉ cần thực hiện một lần $\ln$ đa thức.

Tiếp theo xét một số ứng dụng của hàm sinh mũ.

<span id="ứng-dụng"></span>
## Ứng dụng

<span id="số-derangement"></span>
### Số derangement

???+ note "Số derangement"
    Định nghĩa một derangement độ dài $n$ là một hoán vị thỏa mãn $p_i\ne i$.
    
    Tìm hàm sinh mũ của số derangement.

Xét theo góc độ chu trình hoán vị, derangement nghĩa là trong các chu trình hoán vị không tồn tại vòng tự thân. Nói cách khác, không có chu trình hoán vị độ dài $1$. Hàm sinh mũ của phần còn lại là

$$
\sum_{n\ge 2}\frac{x^n}{n}=-\ln\left(1-x\right)-x
$$

Do đó hàm sinh mũ của số derangement là $\exp(-\ln(1-x)-x)$.

<span id="điểm-bất-động"></span>
### Điểm bất động

???+ note "[Điểm bất động](https://www.51nod.com/Html/Challenge/Problem.html#problemId=1728)"
    Đề bài: hỏi có bao nhiêu ánh xạ $f:\{1,2,\cdots,n\}\to \{1,2,\cdots,n\}$ sao cho
    
    $$
    \underbrace{f\circ f\circ\cdots\circ f}_{k}=\underbrace{f\circ f\circ\cdots\circ f}_{k-1}
    $$
    
    $nk\le 2\times 10^6,1\le k\le 3$.

Xét cạnh từ $i$ tới $f(i)$. Điều kiện tương đương với việc từ một $i$ bất kỳ, đi $k$ bước và đi $k-1$ bước đều đến cùng một điểm. Nói cách khác, chu trình trong cây có chu trình cơ sở là vòng tự thân và độ sâu không vượt quá $k$ (độ sâu của gốc là $1$). Xem cây có chu trình cơ sở này như một cây có gốc cũng tương đương. Vì vậy bài toán chuyển thành: đếm rừng cây có gốc, có nhãn trên $n$ đỉnh, với độ sâu không vượt quá $k$.

Xét cây có gốc có nhãn trên $n$ đỉnh và độ sâu không vượt quá $k$. Giả sử hàm sinh của nó là:

$$
\hat{F_k}(x)=\sum_{n\ge 0}f_{n,k}\frac{x^n}{n!}
$$

Xét cách truy hồi để tìm $\hat{F_k}(x)$. Một cây có gốc với độ sâu không vượt quá $k$ thực chất là một số cây có gốc với độ sâu không vượt quá $k-1$, rồi nối toàn bộ gốc của chúng vào một đỉnh mới. Do đó

$$
\hat{F_k}(x)=x\exp \hat{F}_{k-1}(x)
$$

Khi đó hàm sinh mũ của đáp án là $\exp \hat{F}_k(x)$. Chỉ cần lấy hạng tử thứ $n$ của nó.

### Lust

???+ note "[Lust](https://codeforces.com/contest/891/problem/E)"
    Cho một dãy $n$ số $a_1,a_2,\cdots,a_n$ và một biến $s$ ban đầu bằng $0$. Yêu cầu lặp thao tác sau $k$ lần:
    
    -   Chọn ngẫu nhiên đều một $x$ trong $1,2,\cdots,n$.
    -   Cộng $\prod_{i\ne x}a_i$ vào $s$.
    -   Giảm $a_x$ đi một.
    
    Tính kỳ vọng của $s$ sau $k$ thao tác.
    
    $1\le n\le 5000,1\le k\le 10^9,0\le a_i\le 10^9$.

Giả sử sau $k$ thao tác, $a_i$ đã giảm đi $b_i$. Khi đó

$$
s=\prod_{i=1}^n a_i-\prod_{i=1}^n(a_i- b_i)
$$

Vì vậy bài toán chuyển thành tìm kỳ vọng của $\prod_{i=1}^n (a_i- b_i)$ sau $k$ thao tác.

Xét việc tính tổng $\prod_{i=1}^n (a_i- b_i)$ trên mọi phương án, rồi cuối cùng chia cho $n^k$.

Trong chuỗi $k$ thao tác, số phương án để $i$ xuất hiện $b_i$ lần là

$$
\frac{k!}{b_1!b_2!\cdots b_n!}
$$

Điều này tương tự hệ số trong phép nhân hàm sinh mũ.

Đặt hàm sinh mũ của $a_j$ là

$$
F_j(x)=\sum_{i\ge 0}(a_j-i)\frac{x^i}{i!}
$$

Khi đó đáp án là

$$
[x^k]\prod_{j=1}^nF_j(x)
$$

Để tính nhanh đáp án, cần chuyển $F_j(x)$ sang dạng đóng:

$$
\begin{aligned}
F_j(x)&=\sum_{i\ge 0}a_j\frac{x^i}{i!}-\sum_{i\ge 1}\frac{x^i}{(i-1)!}\\
&=a_j\mathrm{e}^x-x\mathrm{e}^x\\
&=(a_j-x)\mathrm{e}^x
\end{aligned}
$$

Do đó

$$
\prod_{j=1}^nF_j(x)=\mathrm{e}^{nx}\prod_{j=1}^n(a_j-x)
$$

Trong đó $\prod_{j=1}^n(a_j-x)$ là một đa thức bậc $n$, có thể tính trực tiếp. Giả sử khai triển của nó là $\sum_{i=0}^nc_ix^i$, khi đó

$$
\begin{aligned}
\prod_{j=1}^nF_j(x)
&=\left(\sum_{i\ge 0} \frac{n^ix^i}{i!}\right)\left(\sum_{i=0}^nc_ix^i\right)\\
&=\sum_{i\ge 0}\sum_{j=0}^i c_jx^j\frac{n^{i-j}x^{i-j}}{(i-j)!}\\
&=\sum_{i\ge 0}\frac{x^{i}}{i!}\sum_{j=0}^i n^{i-j}i^{\underline{j}}c_j
\end{aligned}
$$

Chỉ cần tính hệ số của hạng tử $x^k$ trong đa thức này.
