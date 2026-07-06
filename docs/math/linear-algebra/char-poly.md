Phần về đặc trưng này chỉ xét ma trận vuông, tức là biến đổi tuyến tính tương ứng với ma trận $A$ ánh xạ $n$ vectơ thành $n$ vectơ.

Trong các bài toán thực tế, thường phải xét việc thực hiện liên tiếp các biến đổi lặp lại. Nếu chỉ dùng mô tả "biến đổi tuyến tính tương ứng với ma trận $A$ biến ma trận đơn vị $I$ thành $A$", thì sẽ rất trừu tượng. Lúc này cách tốt nhất là tìm "điểm bất động", tức phần không thay đổi trong biến đổi.

Tuy nhiên trên thực tế, biến đổi tuyến tính tương ứng với ma trận $A$ rất có thể không có điểm bất động, nên cần lùi một bước và tìm các phần cộng tuyến hoặc gần giống một biến dạng đơn giản.

<span id="giá-trị-riêng-và-vectơ-riêng"></span>
## Giá trị riêng và vectơ riêng

Dưới tác dụng của biến đổi tuyến tính tương ứng với ma trận $A$, hướng của một số vectơ không thay đổi, chỉ bị co giãn.

Giả sử $V$ là không gian tuyến tính trên $F$, và $T$ là một biến đổi tuyến tính trên $V$. Nếu tồn tại $\lambda$ trong $F$ và một **vectơ khác không** $\xi$ trong $V$ sao cho:

$$
T\xi=\lambda\xi
$$

thì $\lambda$ được gọi là một **giá trị riêng** của $T$, còn $\xi$ được gọi là **một vectơ riêng của $T$ ứng với giá trị riêng $\lambda$**.

Các vectơ riêng nằm trên cùng một đường thẳng vẫn giữ nguyên hướng dưới tác dụng của biến đổi tuyến tính (bị nén về không cũng được xem là không đổi hướng). Vectơ riêng không duy nhất; mọi vectơ cộng tuyến với một vectơ riêng đều là vectơ riêng, nhưng theo quy ước vectơ không không phải là vectơ riêng, vì vectơ có hướng đương nhiên phải khác không. Giá trị riêng của một vectơ riêng chính là hệ số co giãn của nó.

Trong ứng dụng thực tế, với các vectơ riêng có cùng giá trị riêng, thường chọn một cơ sở làm đại diện cho toàn bộ chúng.

Giả sử $\alpha_1,\alpha_2,\cdots,\alpha_n$ là một cơ sở của $V$, và ma trận của $T$ theo cơ sở này là $A$, tức là:

$$
T(\alpha_1,\alpha_2,\cdots,\alpha_n)=(\alpha_1,\alpha_2,\cdots,\alpha_n)A
$$

Giả sử $\lambda_0$ là một giá trị riêng của $T$, $\xi$ là một vectơ riêng của $T$ ứng với giá trị riêng $\lambda_0$, và tồn tại vectơ khác không $X$ thỏa mãn:

$$
\xi=(\alpha_1,\alpha_2,\cdots,\alpha_n)X
$$

Khi đó:

$$
T\xi=\lambda_0\xi
$$

$$
T(\alpha_1,\alpha_2,\cdots,\alpha_n)X=\lambda_0(\alpha_1,\alpha_2,\cdots,\alpha_n)X
$$

$$
(\alpha_1,\alpha_2,\cdots,\alpha_n)AX=\lambda_0(\alpha_1,\alpha_2,\cdots,\alpha_n)X
$$

$$
AX=\lambda_0X
$$

$$
(A-\lambda_0I)X=0
$$

Vì vậy định thức tương ứng cũng bằng $0$.

<span id="đa-thức-đặc-trưng"></span>
## Đa thức đặc trưng

Xét một ma trận $n\times n$ là $A$, trong đó $n\geq 0\land n\in\mathbb{Z}$. Gọi $\lambda$ là một tham số, ma trận $\lambda I-A$ được gọi là **ma trận đặc trưng** của $A$.

Định thức của ma trận đặc trưng được gọi là **đa thức đặc trưng** của $A$; khi khai triển là một đa thức bậc $n$, các nghiệm của nó là các giá trị riêng của $A$, ký hiệu là $p_A(\lambda)$:

$$
p_A(\lambda)=\det(\lambda I_n-A)=\begin{vmatrix}
\lambda-a_{11} & -a_{12} &  \cdots & -a_{1n} \\
-a_{21} & \lambda-a_{22} &  \cdots & -a_{2n} \\
\vdots & \vdots &  & \vdots  \\
-a_{n1} & -a_{n2} &  \cdots & \lambda-a_{nn} \\
\end{vmatrix}
$$

Trong đó $I_n$ là ma trận đơn vị $n\times n$. Một số nơi định nghĩa $p_A(\lambda)=\det(A-\lambda I_n)$; định nghĩa đó chỉ khác định nghĩa đang dùng một dấu $(-1)^n$. Theo định nghĩa này, $p_A(\lambda)$ là đa thức monic, còn định nghĩa kia chỉ monic khi $n$ chẵn. Cần lưu ý rằng định thức của ma trận $0\times 0$ bằng $1$ là một định nghĩa tốt.

Vectơ nghiệm khác không $X$ tương ứng với $(\lambda_0 I-A)X=0$ được gọi là vectơ riêng của $A$ ứng với $\lambda_0$.

Biến đổi tuyến tính $T$ có giá trị riêng $\lambda_0$ khi và chỉ khi ma trận $A$ có giá trị riêng $\lambda_0$.

Biến đổi tuyến tính $T$ có vectơ riêng $\xi$ khi và chỉ khi ma trận $A$ có vectơ riêng $X$, trong đó:

$$
\xi=(\alpha_1,\cdots,\alpha_n)X
$$

Theo định lý cơ bản của đại số, đa thức đặc trưng có thể phân tích thành:

$$
f(\lambda)=|\lambda I-A|={(\lambda-\lambda_1)}^{d_1}\cdots{(\lambda-\lambda_m)}^{d_m}
$$

Gọi $d_i$ là **bội đại số** của giá trị riêng $\lambda_i$. Tổng của tất cả các bội đại số bằng số chiều không gian $n$.

<span id="tìm-toàn-bộ-giá-trị-riêng-và-vectơ-riêng-của-ma-trận"></span>
### Tìm toàn bộ giá trị riêng và vectơ riêng của ma trận

Chia thành các bước sau:

-   Tính định thức $|\lambda I-A|$.
-   Tìm toàn bộ nghiệm của đa thức $f(\lambda)=|\lambda I-A|$ trong trường $F$, tức các giá trị riêng của $A$.
-   Với mỗi giá trị riêng $\lambda$ của $A$, giải hệ phương trình tuyến tính thuần nhất $(\lambda I-A)X=0$ để tìm một hệ nghiệm cơ sở $X_1,\cdots,X_t$. Khi đó toàn bộ vectơ riêng của $A$ ứng với $\lambda$ là:

$$
k_1X_1+k_2X_2+\cdots+k_tX_t
$$

trong biểu thức này, các $k_i$ không đồng thời bằng không.

-   Vectơ riêng của biến đổi tuyến tính $T$ ứng với $\lambda$ là:

$$
\xi_i=(\alpha_1,\cdots,\alpha_n)X_i
$$

Vì vậy, toàn bộ vectơ riêng ứng với $\lambda$ là:

$$
k_1\xi_1+k_2\xi_2+\cdots+k_t\xi_t
$$

trong biểu thức này, các $k_i$ không đồng thời bằng không.

Việc giá trị riêng và vectơ riêng có tồn tại hay không phụ thuộc vào trường chứa $V$.

<span id="biến-đổi-tương-tự"></span>
## Biến đổi tương tự

<span id="dẫn-nhập"></span>
### Dẫn nhập

Nếu ma trận $n\times n$ $A$ là ma trận tam giác trên như sau:

$$
A=
\begin{bmatrix}
a_{1,1}&a_{1,2}&\cdots &a_{1,n}\\
&a_{2,2}&\cdots &a_{2,n}\\
&&\ddots &\vdots \\
&&&a_{n,n}
\end{bmatrix}
$$

thì:

$$
\begin{aligned}
p_A(x)&=\det(xI_n-A)\\
&=
\begin{bmatrix}
x-a_{1,1}&-a_{1,2}&\cdots &-a_{1,n}\\
&x-a_{2,2}&\cdots &-a_{2,n}\\
&&\ddots &\vdots \\
&&&x-a_{n,n}
\end{bmatrix}
\\
&=\prod_{i=1}^n(x-a_{i,i})
\end{aligned}
$$

có thể tính rất dễ; với ma trận tam giác dưới cũng tương tự. Nhưng nếu $A$ không thuộc hai loại ma trận này, cần dùng biến đổi tương tự để đưa ma trận về dạng dễ tính đa thức đặc trưng.

<span id="định-nghĩa"></span>
### Định nghĩa

Với hai ma trận $n\times n$ $A$ và $B$, nếu tồn tại ma trận khả nghịch $n\times n$ $P$ sao cho:

$$
B=P^{-1}AP
$$

thì hai ma trận $A$ và $B$ tương tự; phép biến đổi $A\mapsto P^{-1}AP$ được gọi là biến đổi tương tự. Khi đó $A$ và $P^{-1}AP$ có cùng đa thức đặc trưng.

Xét:

$$
\begin{aligned}
\det(xI_n-P^{-1}AP)&=\det(xP^{-1}I_nP-P^{-1}AP)\\
&=\det(P^{-1}xI_nP-P^{-1}AP)\\
&=\det(P^{-1})\cdot \det(P)\cdot \det(xI_n-A)\\
&=\det(xI_n-A)\\
&=p_A(x)
\end{aligned}
$$

Suy ra điều phải chứng minh; với $A\mapsto PAP^{-1}$ cũng tương tự. Ngoài ra $p_A(0)=(-1)^n\cdot \det(A)$, vì $p_A(0)=\det(-1\cdot I_nA)=\det(-1\cdot I_n)\cdot \det(A)$, nên $\det(A)=\det(P^{-1}AP)$.

Định lý: Các ma trận tương tự có cùng đa thức đặc trưng và cùng giá trị riêng; chiều ngược lại không đúng.

Định lý này cho thấy đa thức đặc trưng của ma trận của một biến đổi tuyến tính không phụ thuộc vào cách chọn cơ sở, mà được quyết định trực tiếp bởi biến đổi tuyến tính, nên có thể gọi là đa thức đặc trưng của biến đổi tuyến tính.

Đa thức đặc trưng $f(\lambda)=|\lambda I-A|$ của ma trận $A$ là một đa thức monic. Theo định lý Vieta, hệ số bậc $n-1$ của nó là:

$$
-(\lambda_1+\cdots+\lambda_n)=-(a_{11}+\cdots+a_{nn})=-tr A
$$

trong đó $tr A$ được gọi là vết của $A$, bằng tổng các phần tử trên đường chéo chính của $A$.

Theo định lý Vieta, hạng tử tự do của đa thức đặc trưng là:

$$
{(-1)}^n|A|={(-1)}^n(\lambda_1\cdots\lambda_n)
$$

Định lý: Các ma trận tương tự có cùng vết.

<span id="công-thức-đổi-chỗ"></span>
### Công thức đổi chỗ

Định lý: Bất kể ma trận $A$ và ma trận $B$ có là ma trận vuông hay không, miễn là phép nhân thực hiện được, thì vết của ma trận $AB$ bằng vết của ma trận $BA$.

Một cách chứng minh là khai triển trực tiếp, khi đó xong. Một cách chứng minh khác dùng công thức đổi chỗ.

Định lý: Giả sử $A$ là ma trận $m$ hàng $n$ cột, và $B$ là ma trận $n$ hàng $m$ cột. Khi đó:

$$
\lambda^n|\lambda I_m-AB|=\lambda^m|\lambda I_n-BA|
$$

Công thức này cho thấy $AB$ và $BA$ có cùng các giá trị riêng khác không.

<span id="bổ-đề-schur"></span>
### Bổ đề Schur

Mọi ma trận cấp $n$ $A$ đều tương tự với một ma trận tam giác trên, tức tồn tại ma trận đủ hạng $P$ sao cho $P^{-1}AP$ là ma trận tam giác trên, và các phần tử trên đường chéo chính của nó là toàn bộ các giá trị riêng của $A$.

Hệ quả: Giả sử $n$ giá trị riêng của $A$ là $\lambda_1,\cdots,\lambda_n$, và $\phi(x)$ là một đa thức bất kỳ. Khi đó $n$ giá trị riêng của đa thức ma trận $\phi(A)$ là:

$$
\phi(\lambda_1),\cdots,\phi(\lambda_n)
$$

Đặc biệt, các giá trị riêng của $kA$ là $k\lambda_1,\cdots,k\lambda_n$, các giá trị riêng của $A^m$ là ${\lambda_1}^m,\cdots,{\lambda_n}^m$.

<span id="dùng-khử-gauss-để-thực-hiện-biến-đổi-tương-tự"></span>
### Dùng khử Gauss để thực hiện biến đổi tương tự

Với ma trận $n\times n$ $B$, có thể thực hiện khử Gauss; các thao tác cơ bản là các phép biến đổi sơ cấp trên hàng.

Sau khi áp dụng các thao tác trên cho ma trận (nhân trái với ma trận sơ cấp), lại nhân phải với ma trận nghịch đảo của nó thì thu được một biến đổi tương tự. Nhân trái là biến đổi hàng, còn nhân phải tương ứng với biến đổi cột.

Nếu có thể đưa ma trận bằng biến đổi tương tự về dạng tam giác trên hoặc tam giác dưới, thì có thể tính đa thức đặc trưng khá dễ. Tuy nhiên, nếu áp dụng phép biến đổi $A\mapsto T_{ij}(k)AT_{ij}(-k)$ lên các phần tử trên đường chéo chính, thì sau khi dùng $A\mapsto T_{ij}(k)A$ để khử phần tử ở hàng $i$ cột $j$ về không, việc nhân phải với $T_{ij}(-k)$, tức cộng $-k$ lần cột thứ $i$ của $A$ vào cột thứ $j$, có thể làm phần tử đã khử về không trước đó lại khác không; vì thế có thể không đưa được về dạng tam giác trên hoặc tam giác dưới.

Phần sau sẽ giải thích rằng sau khi áp dụng phép biến đổi lên các phần tử trên đường chéo phụ, ma trận thu được vẫn có thể được dùng để tính đa thức đặc trưng một cách thuận tiện.

<span id="ma-trận-hessenberg-trên"></span>
### Ma trận Hessenberg trên

Với $n\gt 2$, ma trận có dạng:

$$
H=
\begin{bmatrix}
\alpha_{1}&h_{12}&\dots&\dots&h_{1n}\\
\beta_{2}&\alpha_{2}&h_{23}&\dots &\vdots \\
&\ddots &\ddots & \ddots &\vdots \\
& &\ddots &\ddots & h_{(n-1)n}\\
&&& \beta_{n}& \alpha_{n}
\end{bmatrix}
$$

được gọi là ma trận Hessenberg trên, trong đó $\beta$ là đường chéo phụ.

Dùng biến đổi tương tự để khử các phần tử bên dưới đường chéo phụ về không, từ đó thu được ma trận Hessenberg trên; còn việc tính đa thức đặc trưng của một ma trận Hessenberg trên $n\times n$ có thể hoàn thành trong thời gian $O(n^3)$.

Ký hiệu $H_i$ là ma trận chỉ giữ lại $i$ hàng đầu và $i$ cột đầu của $H$, ký hiệu $p_i(x)=\det(xI_i-H_i)$. Khi đó:

$$
H_0=
\begin{bmatrix}
\end{bmatrix},\quad
p_0(x)=1
$$

$$
H_1=
\begin{bmatrix}
\alpha_1
\end{bmatrix},\quad
p_1(x)=\det(x I_1-H_1)=x -\alpha_1
$$

$$
H_2=
\begin{bmatrix}
\alpha_1&h_{12}\\
\beta_2&\alpha_2
\end{bmatrix},\quad
p_2(x)=\det(xI_2-H_2)=(x-\alpha_2)p_1(x)-\beta_2h_{12}p_0(x)
$$

Khi tính định thức, thường chọn khai triển theo phần bù đại số của hàng hoặc cột có nhiều số không nhất. Phần bù tương ứng với một phần tử là ma trận thu được sau khi xóa hàng và cột chứa phần tử đang xét. Trong phần này chọn khai triển theo hàng cuối, có:

$$
\begin{aligned}
p_3(x)&=
\det(xI_3-H_3)\\
&=\begin{vmatrix}
x-\alpha_1&-h_{12}&-h_{13}\\
-\beta_2&x-\alpha_2&-h_{23}\\
&-\beta_3&x-\alpha_3
\end{vmatrix}\\
&=(x-\alpha_3)\cdot (-1)^{3+3}p_2(x)-\beta_3\cdot (-1)^{3+2}
\begin{vmatrix}
x-\alpha_1&-h_{13}\\
-\beta_2&-h_{23}
\end{vmatrix}\\
&=(x-\alpha_3)p_2(x)-\beta_3(h_{23}p_1(x)+\beta_2h_{13}p_0(x))
\end{aligned}
$$

Quan sát và quy nạp, với $2\leq i\leq n$ có:

$$
p_i(x)=(x-\alpha_i)p_{i-1}(x)-
\sum_{m=1}^{i-1}h_{i-m,i}
\left(
\prod_{j=i-m+1}^{i}\beta_j
\right)
p_{i-m-1}(x)
$$

Đến đây toàn bộ thuật toán đã hoàn tất; thuật toán này thường được gọi là thuật toán Hessenberg.

<span id="định-lý-cayley-hamilton"></span>
## Định lý Cayley-Hamilton

Với mọi ma trận cấp $n$ $A$, nếu đa thức đặc trưng là $f(\lambda)=|\lambda I-A|$, thì nhất định có $f(A)=0$.

Với biến đổi tuyến tính $T$ cũng có kết quả song song: nếu $f(\lambda)$ là đa thức đặc trưng của $T$, thì $f(T)$ là biến đổi không.

Từ định lý này có thể biết rằng, với mọi ma trận $A$, luôn tồn tại một đa thức triệt tiêu nó.

<span id="đa-thức-tối-tiểu"></span>
## Đa thức tối tiểu

Giả sử $V$ là một không gian vectơ $n$ chiều. Vì ma trận tương ứng với một biến đổi tuyến tính có $n^2$ phần tử, nên toàn bộ các biến đổi tuyến tính tạo thành một không gian tuyến tính $n^2$ chiều.

Với một biến đổi tuyến tính cụ thể $T$, xét từ tác dụng $0$ lần đến tác dụng $n$ lần, tổng cộng có $n^2+1$ biến đổi tuyến tính; các ma trận tương ứng với chúng phụ thuộc tuyến tính. Vì vậy tồn tại đa thức khác không $f$ sao cho $f(T)$ là biến đổi không; khi đó nói biến đổi $T$ thỏa mãn đa thức $f$. Trong tất cả các đa thức $f$ mà $T$ thỏa mãn, tồn tại một đa thức có bậc thấp nhất.

Đa thức monic có bậc nhỏ nhất có thể triệt tiêu ma trận $A$ được gọi là đa thức tối tiểu của $A$, ký hiệu $m_A(\lambda)$.

Theo phép chia Euclid của đa thức, đa thức tối tiểu là duy nhất và chia hết mọi đa thức triệt tiêu của $A$. Đặc biệt, đa thức tối tiểu chia đa thức đặc trưng.

Định lý: Nếu không tính bội, đa thức đặc trưng $f(\lambda)$ và đa thức tối tiểu $m_A(\lambda)$ của ma trận $A$ có cùng tập nghiệm.

Định lý: Các vectơ riêng của ma trận $A$ ứng với các giá trị riêng khác nhau thì độc lập tuyến tính.

<span id="ứng-dụng"></span>
## Ứng dụng

Trong tin học, thường xét các ma trận trên $(\mathbb{Z}/m\mathbb{Z})^{n\times n}$; thông thường $m$ là số nguyên tố, khi đó thực hiện các biến đổi tương tự ở trên là đơn giản. Khi $m$ là hợp số, có thể xét cách làm tương tự thuật toán Euclid.

??? note "Cài đặt"
    ```cpp
    #include <cassert>
    #include <iostream>
    #include <random>
    #include <vector>
    
    using Matrix = std::vector<std::vector<int>>;
    using i64 = int64_t;
    
    Matrix to_upper_Hessenberg(const Matrix &M, int mod) {
      Matrix H(M);
      int n = H.size();
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if ((H[i][j] %= mod) < 0) H[i][j] += mod;
        }
      }
      for (int i = 0; i < n - 1; ++i) {
        int pivot = i + 1;
        for (; pivot < n; ++pivot) {
          if (H[pivot][i] != 0) break;
        }
        if (pivot == n) continue;
        if (pivot != i + 1) {
          for (int j = i; j < n; ++j) std::swap(H[i + 1][j], H[pivot][j]);
          for (int j = 0; j < n; ++j) std::swap(H[j][i + 1], H[j][pivot]);
        }
        for (int j = i + 2; j < n; ++j) {
          for (;;) {
            if (H[j][i] == 0) break;
            if (H[i + 1][i] == 0) {
              for (int k = i; k < n; ++k) std::swap(H[i + 1][k], H[j][k]);
              for (int k = 0; k < n; ++k) std::swap(H[k][i + 1], H[k][j]);
              break;
            }
            if (H[j][i] >= H[i + 1][i]) {
              int q = H[j][i] / H[i + 1][i], mq = mod - q;
              for (int k = i; k < n; ++k)
                H[j][k] = (H[j][k] + i64(mq) * H[i + 1][k]) % mod;
              for (int k = 0; k < n; ++k)
                H[k][i + 1] = (H[k][i + 1] + i64(q) * H[k][j]) % mod;
            } else {
              int q = H[i + 1][i] / H[j][i], mq = mod - q;
              for (int k = i; k < n; ++k)
                H[i + 1][k] = (H[i + 1][k] + i64(mq) * H[j][k]) % mod;
              for (int k = 0; k < n; ++k)
                H[k][j] = (H[k][j] + i64(q) * H[k][i + 1]) % mod;
            }
          }
        }
      }
      return H;
    }
    
    std::vector<int> get_charpoly(const Matrix &M, int mod) {
      Matrix H(to_upper_Hessenberg(M, mod));
      int n = H.size();
      std::vector<std::vector<int>> p(n + 1);
      p[0] = {1 % mod};
      for (int i = 1; i <= n; ++i) {
        const std::vector<int> &pi_1 = p[i - 1];
        std::vector<int> &pi = p[i];
        pi.resize(i + 1, 0);
        int v = mod - H[i - 1][i - 1];
        if (v == mod) v -= mod;
        for (int j = 0; j < i; ++j) {
          pi[j] = (pi[j] + i64(v) * pi_1[j]) % mod;
          if ((pi[j + 1] += pi_1[j]) >= mod) pi[j + 1] -= mod;
        }
        int t = 1;
        for (int j = 1; j < i; ++j) {
          t = i64(t) * H[i - j][i - j - 1] % mod;
          int prod = i64(t) * H[i - j - 1][i - 1] % mod;
          if (prod == 0) continue;
          prod = mod - prod;
          for (int k = 0; k <= i - j - 1; ++k)
            pi[k] = (pi[k] + i64(prod) * p[i - j - 1][k]) % mod;
        }
      }
      return p[n];
    }
    
    bool verify(const Matrix &M, const std::vector<int> &charpoly, int mod) {
      if (mod == 1) return true;
      int n = M.size();
      std::vector<int> randvec(n), sum(n, 0);
      std::mt19937 gen(std::random_device{}());
      std::uniform_int_distribution<int> dis(1, mod - 1);
      for (int i = 0; i < n; ++i) randvec[i] = dis(gen);
      for (int i = 0; i <= n; ++i) {
        int v = charpoly[i];
        for (int j = 0; j < n; ++j) sum[j] = (sum[j] + i64(v) * randvec[j]) % mod;
        std::vector<int> prod(n, 0);
        for (int j = 0; j < n; ++j) {
          for (int k = 0; k < n; ++k) {
            prod[j] = (prod[j] + i64(M[j][k]) * randvec[k]) % mod;
          }
        }
        randvec.swap(prod);
      }
      for (int i = 0; i < n; ++i)
        if (sum[i] != 0) return false;
      return true;
    }
    
    int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      int n, mod;
      std::cin >> n >> mod;
      Matrix M(n, std::vector<int>(n));
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) std::cin >> M[i][j];
      std::vector<int> charpoly(get_charpoly(M, mod));
      for (int i = 0; i <= n; ++i) std::cout << charpoly[i] << ' ';
      assert(verify(M, charpoly, mod));
      return 0;
    }
    ```

Thuật toán Hessenberg ở trên không ổn định về mặt số học, vì vậy với ma trận trên $\mathbb{R}^{n\times n}$ cần dùng thuật toán khác để điều chỉnh trước khi áp dụng, hoặc chuyển sang thuật toán khác có tính ổn định số tốt hơn.

Có thể liên hệ đa thức đặc trưng với truy hồi tuyến tính thuần nhất hệ số hằng, cũng có thể kết hợp định lý Cayley-Hamilton và phép lấy dư đa thức để tăng tốc một số thuật toán tính lũy thừa ma trận trên trường.

Định lý Cayley-Hamilton chỉ ra:

$$
\begin{aligned}
p_A(A)&=A^n+c_1A^{n-1}+\cdots +c_{n-1}A+c_nI\\
&=O
\end{aligned}
$$

trong đó $O$ là ma trận không $n\times n$, $A\in\mathbb{C}^{n\times n}$ và $p_A(x)=x^n+\sum_{i=1}^nc_ix^{n-i}\in\mathbb{C}[x]$ là đa thức đặc trưng của $A$.

Nếu cần tính $A^K$ với $K$ khá lớn, có thể tìm $f(x)=x^K\bmod{p_A(x)}$ rồi dùng $f(A)=A^K$.

Có $\deg(f(x))\lt n$. Đặt $f(x)=\sum_{i=0}^{n-1}f_ix^i$ và $n=km$, khi đó:

$$
\begin{aligned}
f_{km-1}x^{km-1}+\cdots +f_1x+f_0&=(\cdots (f_{km-1}x^{k-1}+\cdots +f_{k(m-1)})x^k\\
&+f_{k(m-1)-1}x^{k-1}+\cdots +f_{k(m-2)})x^k\\
&+\cdots\\
&+f_{k-1}x^{k-1}+\cdots +f_1x+f_0
\end{aligned}
$$

Lấy $k=\sqrt{n}$, việc tính $f(A)$ cần khoảng $O(\sqrt{n})$ phép nhân ma trận với ma trận.

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

-   Rizwana Rehman, Ilse C.F. Ipsen.[La Budde's Method for Computing Characteristic Polynomials](https://ipsen.math.ncsu.edu/ps/charpoly3.pdf).
-   Marshall Law.[Computing Characteristic Polynomials of Matrices of Structured Polynomials](http://summit.sfu.ca/system/files/iritems1/17301/etd10125_.pdf).
-   Mike Paterson.[On the Number of Nonscalar Multiplications Necessary to Evaluate Polynomials](https://epubs.siam.org/doi/10.1137/0202007).
