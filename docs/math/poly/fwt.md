author: Xeonacid, nocriz, ZnPdCo

<span id="giới-thiệu"></span>
## Giới thiệu

Biến đổi Walsh (Walsh Transform)[^note1] là một phương pháp thay thế biến đổi Fourier rời rạc trong phân tích phổ, và được ứng dụng rộng rãi trong xử lý tín hiệu. FFT làm việc với kiểu `double`, còn Walsh phân rã tín hiệu theo các sóng vuông có tần số dao động khác nhau, nên mọi hệ số đều là số nguyên có cùng độ lớn tuyệt đối. Nhờ đó không cần thực hiện phép nhân số thực, giúp tăng tốc độ tính toán.

Vì vậy, ý tưởng cốt lõi của FWT và FFT về bản chất là giống nhau: đều là biến đổi trên mảng. Ký hiệu kết quả sau khi thực hiện biến đổi Walsh nhanh trên mảng $A$ là $FWT[A]$.

Ý tưởng cốt lõi của FWT như sau:

Cần một dãy mới $C$, thu được từ hai dãy $A$ và $B$ thông qua một quy tắc phép toán nào đó, tức $C = A \cdot B$.

Trước hết tính biến đổi xuôi để lấy $FWT[A], FWT[B]$, sau đó dựa vào $FWT[C]=FWT[A] \cdot FWT[B]$ để tính $FWT[C]$ trong $O(n)$, trong đó $\cdot$ là phép nhân từng vị trí tương ứng của hai dãy.

Cuối cùng thực hiện biến đổi ngược để thu lại dãy ban đầu $C$. Độ phức tạp thời gian là $O(n \log{n})$.

Trong lập trình thi đấu, FWT là phương pháp dùng để giải các bài toán tích chập theo phép toán bit trên chỉ số.

Công thức: $C_{i} = \sum_{i=j \oplus k}A_{j} B_{k}$

Trong đó $\oplus$ là một phép toán bit nhị phân nào đó.

Dưới đây lấy $\cup$ (OR theo bit), $\cap$ (AND theo bit) và $\oplus$ (XOR theo bit) làm ví dụ.

<span id="các-phép-toán-của-fwt"></span>
## Các phép toán của FWT

<span id="phép-or"></span>
### Phép OR

Nếu có $k=i\cup j$, thì các vị trí bit bằng $1$ của $i$ và các vị trí bit bằng $1$ của $j$ chắc chắn đều là tập con của các vị trí bit bằng $1$ của $k$.

Bây giờ muốn có $FWT[C] = FWT[A] \cdot FWT[B]$, cần xây dựng quy tắc cho FWT này.

Theo định nghĩa, có thể xây dựng $FWT[A]_i = A'_i = \sum_{i=i\cup j}A_{j}$, biểu diễn tổng trên các $j$ sao cho tập vị trí bit $1$ của $j$ là tập con của tập vị trí bit $1$ của $i$.

Khi đó:

$$
\begin{aligned}
FWT[A]_i\cdot FWT[B]_i&=\left(\sum_{i\cup j=i} A_j\right)\left(\sum_{i\cup k=i} B_k\right) \\
&=\sum_{i\cup j=i}\sum_{i\cup k=i}A_jB_k \\
&=\sum_{i\cup(j\cup k)=i}A_jB_k \\
&= FWT[C]_i
\end{aligned}
$$

Tiếp theo xét cách tính $FWT[A]$.

Không thể duyệt tất cả, vì độ phức tạp sẽ là $O(n^2)$. Khi không thể duyệt toàn bộ, xét cách chia để trị.

Chia đôi toàn bộ đoạn. Sau khi chia đôi đoạn, chỉ số viết dưới dạng nhị phân sẽ có quy luật.

Gọi $A_0$ là nửa đầu của $A$, $A_1$ là nửa sau của đoạn. Khi đó $A_0$ ứng với các chỉ số có bit cao nhất bằng $0$; các tập con của nó chính là tập con bên trong nó (vì bit cao nhất đã bằng $0$). Còn $A_1$ có bit cao nhất bằng $1$; các tập con thỏa điều kiện không chỉ gồm những phần tử trong chính nó, mà còn gồm cả các tập con có bit cao nhất bằng $0$, tức

$$
FWT[A] = merge(FWT[A_0], FWT[A_0] + FWT[A_1])
$$

Trong đó `merge` nghĩa là ghép hai mảng lại như ghép chuỗi, còn $+$ là phép cộng thông thường, cộng các vị trí tương ứng.

Như vậy, bằng cách chia đôi có thể hoàn thành việc ghép qua $O(\log{n})$ tầng; mỗi lần ghép cần thực hiện một lượt tính toán. Vì thế thu được $FWT[A]$ trong $O(n\log{n})$.

Phần còn lại là biến đổi ngược. Biến đổi ngược thực ra rất đơn giản: đã biết các tập con của $A_0$ chỉ nằm trong chính nó ($A_0 = FWT[A_0]$), còn tập con của $A_1$ là $FWT[A_0] + FWT[A_1]$, nên có thể suy ra trực tiếp công thức truy hồi cho biến đổi ngược:

$$
UFWT[A'] = merge(UFWT[A_0'], UFWT[A_1'] - UFWT[A_0'])
$$

Dưới đây là cài đặt. Biến đổi xuôi và ngược có thể gộp vào một hàm; khi biến đổi xuôi $\text{type}=1$, khi biến đổi ngược $\text{type}=-1$.

???+ note "Cài đặt"
    ```cpp
    void Or(ll *a, ll type) {  // cài đặt lặp, hằng số nhỏ hơn
      for (ll x = 2; x <= n; x <<= 1) {
        ll k = x >> 1;
        for (ll i = 0; i < n; i += x) {
          for (ll j = 0; j < k; j++) {
            (a[i + j + k] += a[i + j] * type) %= P;
          }
        }
      }
    }
    ```

<span id="phép-and"></span>
### Phép AND

Với phép AND, lập luận tương tự phép OR cho kết luận tương ứng:

$$
FWT[A] = merge(FWT[A_0] + FWT[A_1], FWT[A_1])
$$

$$
UFWT[A'] = merge(UFWT[A_0'] - UFWT[A_1'], UFWT[A_1'])
$$

Dưới đây là cài đặt. Khi biến đổi xuôi $\text{type}=1$, khi biến đổi ngược $\text{type}=-1$.

???+ note "Cài đặt"
    ```cpp
    void And(ll *a, ll type) {
      for (ll x = 2; x <= n; x <<= 1) {
        ll k = x >> 1;
        for (ll i = 0; i < n; i += x) {
          for (ll j = 0; j < k; j++) {
            (a[i + j] += a[i + j + k] * type) %= P;
          }
        }
      }
    }
    ```

<span id="phép-xor"></span>
### Phép XOR

Tích chập XOR dựa trên nguyên lý sau:

Nếu đặt $x\circ y$ là tính chẵn lẻ của số bit $1$ trong $x\cap y$, tức $x\circ y=\text{popcnt}(x\cap y)\bmod 2$, thì có $(x\circ y)\oplus (x\circ z)=x\circ(y\oplus z)$.

Phép tính $FWT[A]$ cũng có thể suy ra rất tự nhiên.

Đặt $FWT[A]_i=\sum_{i\circ j=0}A_j-\sum_{i\circ j=1}A_j$. Tính đúng đắn của $FWT[C] = FWT[A] \cdot FWT[B]$ được chứng minh như sau:

$$
\begin{aligned}
FWT[A]_iFWT[B]_i&=\left(\sum_{i\circ j=0}A_j-\sum_{i\circ j=1}A_j\right)\left(\sum_{i\circ k=0}B_k-\sum_{i\circ k=1}B_k\right) \\
&=\left(\sum_{i\circ j=0}A_j\sum_{i\circ k=0}B_k+\sum_{i\circ j=1}A_j\sum_{i\circ k=1}B_k\right)-\left(\sum_{i\circ j=0}A_j\sum_{i\circ k=1}B_k+\sum_{i\circ j=1}A_j\sum_{i\circ k=0}B_k\right) \\
&=\sum_{(j\oplus k)\circ i=0}A_jB_k-\sum_{(j\oplus k)\circ i=1}A_jB_k \\
&=FWT[C]_i
\end{aligned}
$$

Tiếp theo xét cách tính nhanh giá trị của $A,B$; vẫn dùng chia để trị:

Với dãy con $FWT[A_0]$ ứng với $i$ có bit hiện tại bằng $0$, khi thực hiện phép $\circ$ thì kết quả với $0$ hay với $1$ đều không đổi (vì $0\cap 0=0,0\cap1=0$). Do đó trong $FWT[A]=\sum_{i\circ j=0}A_j-\sum_{i\circ j=1}A_j$, phần $\sum_{i\circ j=1}A_j=0$.

Với dãy con $A_1$ ứng với $i$ có bit hiện tại bằng $1$, khi thực hiện phép $\circ$ thì kết quả với $0$ là $0$, còn với $1$ là $1$ (vì $1\cap 0=0,1\cap1=1$).

Tổng hợp lại, có:

$$
FWT[A]=merge((FWT[A_0]+FWT[A_1])-0, FWT[A_0]-FWT[A_1])
$$

Tức là:

$$
FWT[A] = merge(FWT[A_0] + FWT[A_1], FWT[A_0] - FWT[A_1])
$$

Biến đổi ngược dễ suy ra:

$$
UFWT[A'] = merge(\frac{UFWT[A_0'] + UFWT[A_1']}{2}, \frac{UFWT[A_0'] - UFWT[A_1']}{2})
$$

Dưới đây là mã nguồn. Khi biến đổi xuôi $\text{type}=1$, khi biến đổi ngược $\text{type}=\frac{1}{2}$.

???+ note "Cài đặt"
    ```cpp
    void Xor(ll *a, ll type) {
      for (ll x = 2; x <= n; x <<= 1) {
        ll k = x >> 1;
        for (ll i = 0; i < n; i += x) {
          for (ll j = 0; j < k; j++) {
            (a[i + j] += a[i + j + k]) %= P;
            (a[i + j + k] = a[i + j] - a[i + j + k] * 2) %= P;
            (a[i + j] *= type) %= P;
            (a[i + j + k] *= type) %= P;
          }
        }
      }
    }
    ```

<span id="phép-xnor"></span>
### Phép XNOR

Bằng cách lập luận tương tự phép XOR, có công thức:

$FWT[A]_{i} = \sum_{C_1}A_{j} - \sum_{C_2}A_{j}$ (trong đó $C_1$ biểu diễn điều kiện $\text{popcnt}(x\cup y)\bmod 2$ bằng $0$, $C_2$ biểu diễn điều kiện $\text{popcnt}(x\cup y)\bmod 2$ bằng $1$)

$$
FWT[A] = merge(FWT[A_1] - FWT[A_0], FWT[A_1] + FWT[A_0])
$$

$$
UFWT[A'] = merge(\frac{UFWT[A_1'] - UFWT[A_0']}{2}, \frac{UFWT[A_1'] + UFWT[A_0']}{2})
$$

<span id="một-góc-nhìn-khác-về-fwt"></span>
## Một góc nhìn khác về FWT

Đặt $c(i,j)$ là hệ số đóng góp của $A_j$ vào $FWT[A]_i$. Quá trình biến đổi FWT có thể mô tả lại như sau:

$$
FWT[A]_i = \sum_{j=0}^{n-1} c(i,j) A_j
$$

Vì có:

$$
FWT[A]_i\cdot FWT[B]_i=FWT[C]_i
$$

Do đó, bằng một chứng minh đơn giản có thể thu được: $c(i,j)c(i,k)=c(i,j\odot k)$. Trong đó $\odot$ là một phép toán bit bất kỳ.

Đồng thời, hàm $c$ còn có một tính chất quan trọng: nó có thể được xử lý theo từng bit.

Ví dụ, khi biến đổi:

$$
FWT[A]_i = \sum_{j=0}^{n-1} c(i,j) A_j
$$

Làm trực tiếp như vậy là kém hiệu quả. Tách nó thành:

$$
FWT[A]_i = \sum_{j=0}^{n/2-1} c(i,j) A_j+\sum_{j=n/2}^{n-1} c(i,j) A_j
$$

Xét sự khác nhau của $i,j$ trong biểu thức trước và biểu thức sau, có thể thấy chỉ có bit cao nhất là khác nhau.

Do đó loại bỏ bit cao nhất của $i,j$ để được $i',j'$, và ký hiệu $i_0$ là bit cao nhất của $i$. Khi đó:

$$
FWT[A]_i = c(i_0,0)\sum_{j=0}^{n/2-1} c(i',j') A_j+c(i_0,1)\sum_{j=n/2}^{n-1} c(i',j') A_j
$$

Nếu $i_0=0$, có:

$$
FWT[A]_i = c(0,0)\sum_{j=0}^{n/2-1} c(i',j') A_j+c(0,1)\sum_{j=n/2}^{n-1} c(i',j') A_j
$$

Nếu $i_0=1$, có:

$$
FWT[A]_i = c(1,0)\sum_{j=0}^{n/2-1} c(i',j') A_j+c(1,1)\sum_{j=n/2}^{n-1} c(i',j') A_j
$$

Nói cách khác, chỉ cần:

$$
\begin{bmatrix}
c(0,0) & c(0,1) \\
c(1,0) & c(1,1)
\end{bmatrix}
$$

bốn số này là có thể hoàn thành biến đổi. Gọi ma trận này là ma trận bit.

Nếu muốn thực hiện biến đổi ngược, cần ma trận nghịch đảo của ma trận bit trên.

Nếu ma trận nghịch đảo là $c^{-1}$, có thể dùng thao tác tương tự để thu lại dãy ban đầu:

$$
A_i = \sum_{j=0}^n c^{-1}(i,j) FWT[A]_j
$$

Ma trận nghịch đảo không phải lúc nào cũng tồn tại. Chẳng hạn, nếu có một hàng toàn $0$ hoặc một cột toàn $0$, ma trận sẽ không có nghịch đảo; vì vậy cần đặc biệt cẩn thận khi xây dựng.

<span id="or-theo-bit"></span>
### OR theo bit

Có thể xây dựng:

$$
\begin{bmatrix}
1 & 0 \\
1 & 1
\end{bmatrix}
$$

Như vậy thỏa mãn $c(i,j)c(i,k)=c(i,j\cup k)$. Điều này hoàn toàn trùng với công thức $FWT[A]=\text{merge}(FWT[A_0], FWT[A_0]+FWT[A_1])$ đã suy ra ở trên. Tương tự, ma trận dưới đây cũng thỏa mãn điều kiện này, nhưng thông thường dùng ma trận phía trên:

$$
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}
$$

Mặc dù ma trận sau đây cũng thỏa mãn $c(i,j)c(i,k)=c(i,j\cup k)$, nhưng nó có một hàng toàn $0$, không tồn tại nghịch đảo, nên không hợp lệ:

$$
\begin{bmatrix}
0 & 0 \\
1 & 1
\end{bmatrix}
$$

Nếu muốn thực hiện biến đổi ngược, cần lấy nghịch đảo của ma trận. Lấy ma trận **trên cùng** làm ví dụ, thu được:

$$
\begin{bmatrix}
1 & 0 \\
-1 & 1
\end{bmatrix}
$$

Sau đó chỉ cần đưa ma trận biến đổi ngược vào theo cách làm của biến đổi xuôi.

<span id="and-theo-bit"></span>
### AND theo bit

Có thể xây dựng:

$$
\begin{bmatrix}
1 & 1 \\
0 & 1
\end{bmatrix}
$$

Như vậy thỏa mãn $c(i,j)c(i,k)=c(i,j\cap k)$.

Ma trận nghịch đảo:

$$
\begin{bmatrix}
1 & -1 \\
0 & 1
\end{bmatrix}
$$

<span id="xor-theo-bit"></span>
### XOR theo bit

Có thể xây dựng:

$$
\begin{bmatrix}
1 & 1 \\
1 & -1
\end{bmatrix}
$$

Như vậy thỏa mãn $c(i,j)c(i,k)=c(i,j\oplus k)$.

Ma trận nghịch đảo:

$$
\begin{bmatrix}
0.5 & 0.5 \\
0.5 & -0.5
\end{bmatrix}
$$

<span id="fwt-là-biến-đổi-tuyến-tính"></span>
## FWT là biến đổi tuyến tính

FWT là một biến đổi tuyến tính. Nghĩa là nó thỏa mãn:

$$
FWT[A+B]=FWT[A]+FWT[B]
$$

và:

$$
FWT[c\cdot A]=c\cdot FWT[A]
$$

<span id="fwt-k-chiều"></span>
## FWT K chiều

Bản chất của phép toán bit là phép toán trên một vector $\{0,1\}$ có $n$ chiều. Phép OR lấy $\max$ trên từng chiều. Phép AND lấy $\min$ trên từng chiều. Phép XOR cộng từng chiều rồi lấy $\bmod 2$.

Phép toán bit có một đặc điểm: mỗi bit của vector đều độc lập với nhau.

Mở rộng $\{0,1\}$ thành $[0,K)\cap \mathbf{Z}$, tức mở rộng sang hệ cơ số $K$, rồi xét kết quả thu được.

<span id="phép-max"></span>
### Phép max

Mở rộng phép $\cup$ sang hệ cơ số $K$, định nghĩa $i\cup j$ là lấy $\max$ theo từng chữ số, khi đó:

$$
c(i,j)c(i,k)=c(i,j\cup k)
$$

Nếu $j=k$, công thức trên trở thành:

$$
c(i,j)c(i,j)=c(i,j)
$$

Nói cách khác, trong mỗi hàng, các $1$ bắt buộc chỉ có thể nằm trước các $0$; nếu nằm phía sau thì không hợp lệ. Thử tay có thể tìm được một cách xây dựng hợp lệ:

$$
\begin{bmatrix}
1 & 0 & 0 & 0 \\
1 & 1 & 0 & 0 \\
1 & 1 & 1 & 0 \\
1 & 1 & 1 & 1
\end{bmatrix}
$$

Lấy nghịch đảo thu được:

$$
\begin{bmatrix}
1 & 0 & 0 & 0 \\
-1 & 1 & 0 & 0 \\
0 & -1 & 1 & 0 \\
0 & 0 & -1 & 1
\end{bmatrix}
$$

<span id="phép-min"></span>
### Phép min

Mở rộng phép $\cap$ sang hệ cơ số $K$, định nghĩa $i\cap j$ là lấy $\min$ theo từng chữ số, khi đó:

$$
c(i,j)c(i,k)=c(i,j\cap k)
$$

Nếu $j=k$, công thức trên trở thành:

$$
c(i,j)c(i,j)=c(i,j)
$$

Nói cách khác, trong mỗi hàng, các $1$ bắt buộc chỉ có thể nằm sau các $0$; nếu nằm phía trước thì không hợp lệ. Thử tay có thể tìm được một cách xây dựng hợp lệ:

$$
\begin{bmatrix}
1 & 1 & 1 & 1 \\
0 & 1 & 1 & 1 \\
0 & 0 & 1 & 1 \\
0 & 0 & 0 & 1
\end{bmatrix}
$$

Lấy nghịch đảo thu được:

$$
\begin{bmatrix}
1 & -1 & 0 & 0 \\
0 & 1 & -1 & 0 \\
0 & 0 & 1 & -1 \\
0 & 0 & 0 & 1
\end{bmatrix}
$$

Hai phép đầu được dùng ít hơn; phép được dùng nhiều hơn là:

<span id="phép-cộng-không-nhớ"></span>
### Phép cộng không nhớ

Mở rộng phép $\oplus$ sang hệ cơ số $K$, định nghĩa $i\oplus j$ là cộng theo từng chữ số rồi lấy $\bmod K$, khi đó:

$$
c(i,j)c(i,k)=c(i,j\oplus k)
$$

Xây dựng $c(i,j)=\omega_{K}^j$ là đủ thỏa mãn yêu cầu:

$$
\omega_{K}^j\omega_{K}^k=\omega_{K}^{j\oplus k}
$$

Nhưng nếu mỗi hàng của ma trận đều giống nhau thì ma trận cũng không có nghịch đảo, nên có thể xây dựng $c(i,j)=\omega_{K}^{(i-1)j}$.

Khi đó có ma trận sau:

$$
\begin{bmatrix}
1 & 1 & 1 & \cdots & 1 \\
1 & \omega_{K}^1 & \omega_{K}^2 & \cdots & \omega_{K}^{k-1} \\
1 & \omega_{K}^2 & \omega_{K}^4 & \cdots & \omega_{K}^{2(k-1)} \\
1 & \omega_{K}^3 & \omega_{K}^6 & \cdots & \omega_{K}^{3(k-1)} \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
1 & \omega_{K}^{k-1} & \omega_{K}^{2(k-1)} & \cdots & \omega_{K}^{(k-1)(k-1)}
\end{bmatrix}
$$

Đây chính là [ma trận Vandermonde](https://en.wikipedia.org/wiki/Vandermonde_matrix). Lấy nghịch đảo thu được:

$$
\frac{1}{K}\begin{bmatrix}
1 & 1 & 1 & \cdots & 1 \\
1 & \omega_{K}^{-1} & \omega_{K}^{-2} & \cdots & \omega_{K}^{-(k-1)} \\
1 & \omega_{K}^{-2} & \omega_{K}^{-4} & \cdots & \omega_{K}^{-2(k-1)} \\
1 & \omega_{K}^{-3} & \omega_{K}^{-6} & \cdots & \omega_{K}^{-3(k-1)} \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
1 & \omega_{K}^{-(k-1)} & \omega_{K}^{-2(k-1)} & \cdots & \omega_{K}^{-(k-1)(k-1)}
\end{bmatrix}
$$

Nếu modulo của đề bài có căn đơn vị, có thể cài đặt đơn giản.

Tuy nhiên **căn đơn vị có thể không tồn tại theo modulo**, nên xét mở rộng trường: tự định nghĩa một $x$ thỏa $x^K=1$, rồi thay trực tiếp $x$ vào để tính. Khi đó mỗi số là một đa thức theo $x$ bậc $k-1$. Chỉ cần tính dưới modulo $x^K-1$. Khi ấy ma trận có thể biểu diễn như sau:

$$
\begin{bmatrix}
1 & 1 & 1 & \cdots & 1 \\
1 & x^1 & x^2 & \cdots & x^{k-1} \\
1 & x^2 & x^4 & \cdots & x^{2(k-1)} \\
1 & x^3 & x^6 & \cdots & x^{3(k-1)} \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
1 & x^{k-1} & x^{2(k-1)} & \cdots & x^{(k-1)(k-1)}
\end{bmatrix}
$$

Nhưng cách làm này có thể sinh ước không, tức **một số có nhiều cách biểu diễn**; không thể xác định giá trị thật của một số.

Vì thế không tính theo $\bmod {x^K-1}$ nữa, mà tính theo $\bmod$ đa thức cyclotomic $\Phi_{K}(x)$. Đa thức này bảo đảm cấp của $x$ là $k$ và bất khả quy trên $\mathbb{Q}$. Do đó, định nghĩa phép tính bên trên được thực hiện dưới $\bmod {\Phi_{K}(x)}$.

Vẫn còn một vấn đề: tính theo $\bmod \Phi_{K}(x)$ có hằng số lớn (vì bản thân $\Phi$ là một đa thức). Nhưng vì $\Phi_{K}(x)\mid x^k-1$, khi tính chỉ cần lấy $\bmod x^k -1$, đến cuối mới lấy tiếp $\bmod \Phi_{K}(x)$.

<span id="ví-dụ"></span>
## Ví dụ

???+ note "[CF 1103E - Radix sum](https://www.luogu.com.cn/problem/CF1103E)"
    Cho một dãy $a_1,a_2,...,a_n$ độ dài $n$. Với mỗi $p \in [0,n-1]$, tính số dãy số nguyên $i_1,i_2,...,i_n$ thỏa mãn các điều kiện sau, lấy modulo $2^{58}$:
    
    -   $\forall j \in [1,n] , i_j \in [1,n]$;
    -   $\sum\limits_{j=1}^n a_{i_j} = p$, trong đó phép cộng được định nghĩa là phép cộng thập phân không nhớ.
    
    $n\le10^5,a_i\le10^5$
    
    ??? note "Lời giải"
        Có thể nghĩ đến DP: thiết kế trạng thái $f_{i,s}$ biểu diễn đã xét đến số thứ $i$, và trạng thái phép cộng hiện tại là $s$. Vì biến đổi FWT là tuyến tính, có thể biến đổi trước sang biểu diễn giá trị điểm FWT, sau đó đưa thành lũy thừa bậc $n$ của chính nó, cuối cùng biến đổi ngược lại.
        
        Phần trên là trực tiếp, nhưng đề bài cho modulo $2^{58}$. Do không có căn đơn vị, cần xét mở rộng trường.
        
        Đa thức cyclotomic trong trường hợp này là $\Phi_{10}(x)=x^4-x^3+x^2-x+1$.
        
        Tuy nhiên khi UFWT, cần chia cho cơ số $10$, mà $10$ không có nghịch đảo modulo $2^{58}$. Thực ra $5$ có nghịch đảo modulo $2^{58}$: $57646075230342349$; chỉ cần chia thêm một thừa số $2$. Giả sử đáp án sau khi đã chia cho $5$ là $x$, đáp án thật là $y$, tức $2^5y\equiv x\pmod{2^{64}}$. Khi đó $y\equiv \frac{x}{2^5}\pmod{2^{64-5}}$, tức $y\equiv \frac{x}{2^5}\pmod{2^{59}}$. Vì vậy chỉ cần chia đáp án cuối cùng cho $2^5$. Mặc dù không rõ vì sao tác giả đề bài lại yêu cầu modulo $2^{58}$, sau đó chỉ cần lấy modulo lại là đủ.

???+ note "[CF103329F, XXII Opencup, Grand Prix of XiAn - The Struggle](https://codeforces.com/gym/103329/problem/F)"
    Cho một ellipse $E$, trong đó tọa độ của mọi điểm nguyên đều nằm trong $[1,4 \cdot 10^6]$. Tính giá trị $\sum_{(x,y) \in E} (x \oplus y)^{33}x^{-2}y^{-1} \mod 10^9+7$.
    
    ??? note "Lời giải"
        Đây là một bài không quá mẫu mực. Tác giả đề bài đã cung cấp lời giải tiếng Anh chi tiết; xem cụ thể tại [liên kết này](https://codeforces.com/blog/entry/96518).

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

-   [Ghi chú thuật toán của Taojiang](https://zhuanlan.zhihu.com/p/41867199)
-   [Blog của ZnPdCo](https://znpdco.github.io/%E7%AE%97%E6%B3%95/2024/05/07/FWT.html)

[^note1]: [Wikipedia](https://en.wikipedia.org/wiki/Fast_Walsh%E2%80%93Hadamard_transform)
