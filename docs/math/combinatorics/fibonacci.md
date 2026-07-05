Dãy Fibonacci (The Fibonacci sequence, [OEIS A000045](http://oeis.org/A000045)) được định nghĩa như sau:

$$
F_0 = 0, F_1 = 1, F_n = F_{n-1} + F_{n-2}
$$

Một vài số hạng đầu của dãy là:

$$
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \dots
$$

<span id="dãy-lucas"></span>
## Dãy Lucas

Dãy Lucas (The Lucas sequence, [OEIS A000032](http://oeis.org/A000032)) được định nghĩa như sau:

$$
L_0 = 2, L_1 = 1, L_n = L_{n-1} + L_{n-2}
$$

Một vài số hạng đầu của dãy là:

$$
2, 1, 3, 4, 7, 11, 18, 29, 47, 76, 123, 199, \dots
$$

Khi nghiên cứu dãy Fibonacci, trong nhiều trường hợp ta cần dùng dãy Lucas như một công cụ.

<span id="công-thức-tổng-quát-của-dãy-fibonacci"></span>
## Công thức tổng quát của dãy Fibonacci

Số Fibonacci thứ $n$ có thể được tính bằng công thức truy hồi trong thời gian $\Theta(n)$. Tuy nhiên vẫn có các cách tính nhanh hơn.

<span id="nghiệm-giải-tích"></span>
### Nghiệm giải tích

Nghiệm giải tích là nghiệm dạng công thức. Ta có công thức tổng quát của dãy Fibonacci (Binet's Formula):

$$
F_n = \frac{\left(\frac{1 + \sqrt{5}}{2}\right)^n - \left(\frac{1 - \sqrt{5}}{2}\right)^n}{\sqrt{5}}
$$

Công thức này có thể chứng minh dễ dàng bằng quy nạp; cũng có thể suy ra bằng hàm sinh, hoặc bằng cách giải một phương trình.

Dễ thấy số hạng thứ hai trên tử số luôn có trị tuyệt đối nhỏ hơn $1$ và giảm theo tốc độ mũ. Vì vậy ta có thể viết công thức trên thành

$$
F_n = \left[\frac{\left(\frac{1 + \sqrt{5}}{2}\right)^n}{\sqrt{5}}\right]
$$

Trong đó cặp ngoặc vuông biểu thị việc lấy số nguyên gần nhất.

Hai công thức này đòi hỏi độ chính xác rất cao khi tính toán nên hiếm khi được dùng trực tiếp trong thực tế. Tuy vậy không nên bỏ qua chúng: kết hợp với khái niệm thặng dư bậc hai và nghịch đảo trong modulo, công thức này vẫn hữu ích trong OI.

<span id="công-thức-tổng-quát-của-dãy-lucas"></span>
### Công thức tổng quát của dãy Lucas

Ta có công thức tổng quát của dãy Lucas:

$$
L_n = \left(\frac{1 + \sqrt{5}}{2}\right)^n + \left(\frac{1 - \sqrt{5}}{2}\right)^n
$$

Công thức này rất giống với dãy Fibonacci. Thật vậy:

$$
\frac{L_n + F_n\sqrt{5}}{2} = \left(\frac{1 + \sqrt{5}}{2}\right)^n
$$

Nói cách khác, $L_n$ và $F_n$ chính là các hệ số ở tử số sau khi khai triển nhị thức của $\left(\frac{1 + \sqrt{5}}{2}\right)^n$ rồi gom các hạng tử đồng dạng. Do đó, toàn bộ nghiệm của phương trình Pell

$$
x^2-5y^2=-4
$$

chính là

$$
\frac{x_n + y_n\sqrt{5}}{2} = \frac{L_n + F_n\sqrt{5}}{2}
$$

tức là dãy Lucas và dãy Fibonacci. Vì thế:

$$
{L_n}^2-5{F_n}^2=-4
$$

<span id="dạng-ma-trận"></span>
### Dạng ma trận

Công thức truy hồi của dãy Fibonacci có thể biểu diễn bằng phép nhân ma trận:

$$
\begin{bmatrix}F_{n-1} & F_{n} \cr\end{bmatrix} = \begin{bmatrix}F_{n-2} & F_{n-1} \cr\end{bmatrix} \begin{bmatrix}0 & 1 \cr 1 & 1 \cr\end{bmatrix}
$$

Đặt $P = \begin{bmatrix}0 & 1 \cr 1 & 1 \cr\end{bmatrix}$, ta có

$$
\begin{bmatrix}F_n & F_{n+1} \cr\end{bmatrix} = \begin{bmatrix}F_0 & F_1 \cr\end{bmatrix} P^n
$$

Vì vậy ta có thể tính số Fibonacci bằng phép nhân ma trận trong thời gian $\Theta(\log n)$. Ngoài ra, công thức ở phần trước cũng có thể được suy ra bằng kỹ thuật chéo hóa ma trận.

<span id="phương-pháp-nhân-đôi-nhanh"></span>
### Phương pháp nhân đôi nhanh

Từ các công thức trên, ta thu được các đẳng thức:

$$
\begin{aligned}
F_{2k} &= F_k (2 F_{k+1} - F_{k}) \\
F_{2k+1} &= F_{k+1}^2 + F_{k}^2
\end{aligned}
$$

Nhờ đó có thể tính nhanh hai số Fibonacci liên tiếp; hằng số nhỏ hơn so với nhân ma trận. Đoạn mã dưới đây trả về bộ đôi $(F_n,F_{n+1})$.

```cpp
pair<int, int> fib(int n) {
  if (n == 0) return {0, 1};
  auto p = fib(n >> 1);
  int c = p.first * (2 * p.second - p.first);
  int d = p.first * p.first + p.second * p.second;
  if (n & 1)
    return {d, c + d};
  else
    return {c, d};
}
```

<span id="tính-chất"></span>
## Tính chất

Dãy Fibonacci có nhiều tính chất thú vị; dưới đây là một số tính chất cơ bản:

1.  Đồng nhất thức Cassini (Cassini's identity): $F_{n-1} F_{n+1} - F_n^2 = (-1)^n$.
2.  Tính chất cộng chỉ số: $F_{n+k} = F_k F_{n+1} + F_{k-1} F_n$.
3.  Lấy $k = n$ trong tính chất trên, ta được $F_{2n} = F_n (F_{n+1} + F_{n-1})$.
4.  Từ tính chất trên có thể chứng minh bằng quy nạp rằng $\forall k\in \mathbb{N},F_n|F_{nk}$.
5.  Chiều ngược lại cũng đúng, tức là $\forall F_a|F_b,a|b$.
6.  Tính chất GCD: $(F_m, F_n) = F_{(m, n)}$.
7.  Khi đầu vào là hai số Fibonacci liên tiếp, thuật toán Euclid đạt độ phức tạp xấu nhất; xem thêm [Wikipedia - Lame](https://en.wikipedia.org/wiki/Gabriel_Lam%C3%A9).

<span id="quan-hệ-giữa-dãy-fibonacci-và-dãy-lucas"></span>
### Quan hệ giữa dãy Fibonacci và dãy Lucas

Không khó để nhận thấy các đẳng thức liên quan đến dãy Lucas và dãy Fibonacci có độ tương đồng cao với các công thức lượng giác. Chẳng hạn:

$$
\frac{L_n + F_n\sqrt{5}}{2} = \left(\frac{1 + \sqrt{5}}{2}\right)^n
$$

rất giống với

$$
\cos nx + i\sin nx = \left(\cos x + i\sin x\right)^n
$$

và

$$
{L_n}^2-5{F_n}^2=-4
$$

rất giống với

$$
\cos^2 x + \sin^2 x = 1
$$

Do đó, dãy Lucas giống hàm cos, còn dãy Fibonacci giống hàm sin. Ví dụ, từ

$$
\left(\frac{1 + \sqrt{5}}{2}\right)^m\left(\frac{1 + \sqrt{5}}{2}\right)^n = \left(\frac{1 + \sqrt{5}}{2}\right)^{m+n}
$$

có thể suy ra các đẳng thức cho tổng hai chỉ số:

$$
2L_{m+n}=5F_mF_n+L_mL_n
$$

$$
2F_{m+n}=F_mL_n+L_mF_n
$$

Từ đó có các hệ quả cho chỉ số gấp đôi:

$$
L_{2n}={L_n}^2-2{\left(-1\right)}^n
$$

$$
F_{2n}=F_nL_n
$$

Đây cũng là một cách nhân đôi chỉ số nhanh. Tương tự, ta có thể mô phỏng các công thức lượng giác như tính chẵn lẻ, biến tổng thành tích, biến tích thành tổng, công thức nửa góc, phép thế vạn năng, v.v. để suy ra thêm nhiều đẳng thức tương ứng cho dãy Lucas và dãy Fibonacci.

<span id="mã-hóa-fibonacci"></span>
## Mã hóa Fibonacci

Ta có thể dùng dãy Fibonacci để mã hóa số nguyên dương. Theo [định lý Zeckendorf](https://en.wikipedia.org/wiki/Zeckendorf%27s_theorem), mọi số tự nhiên $n$ đều có thể được biểu diễn duy nhất thành tổng của một số số Fibonacci:

$$
N = F_{k_1} + F_{k_2} + \ldots + F_{k_r}
$$

với $k_1 \ge k_2 + 2,\ k_2 \ge k_3 + 2,\  \ldots,\  k_r \ge 2$, tức là không được dùng hai số Fibonacci liên tiếp.

Vì vậy ta có thể biểu diễn một số nguyên dương bằng mã $d_0 d_1 d_2 \dots d_s 1$, trong đó $d_i=1$ nghĩa là $F_{i+2}$ được sử dụng. Ở cuối mã ta bắt buộc thêm một chữ số 1; khi đó sẽ xuất hiện hai chữ số 1 liên tiếp, đánh dấu điểm kết thúc của chuỗi mã. Một số ví dụ:

$$
\begin{aligned}
1 &=& 1 &=& F_2 &=& (11)_F \\
2 &=& 2 &=& F_3 &=& (011)_F \\
6 &=& 5 + 1 &=& F_5 + F_2 &=& (10011)_F \\
8 &=& 8 &=& F_6 &=& (000011)_F \\
9 &=& 8 + 1 &=& F_6 + F_2 &=& (100011)_F \\
19 &=& 13 + 5 + 1 &=& F_7 + F_5 + F_2 &=& (1001011)_F
\end{aligned}
$$

Quá trình mã hóa $n$ có thể giải bằng thuật toán tham lam:

1.  Duyệt các số Fibonacci $F_i$ từ lớn đến nhỏ cho đến khi $F_i\le n$.
2.  Trừ $F_i$ khỏi $n$, rồi đặt một chữ số 1 vào vị trí $i-2$ của mã; vị trí trong mã được đánh số từ trái sang phải bắt đầu từ 0.
3.  Nếu $n$ vẫn dương, quay lại bước 1.
4.  Cuối cùng thêm một chữ số 1 vào cuối mã để biểu thị vị trí kết thúc.

Giải mã cũng tương tự: trước hết xóa chữ số 1 cuối cùng; với mỗi vị trí $i$ có mã bằng 1, cộng $F_{i+2}$ vào đáp án. Kết quả cuối cùng chính là số ban đầu.

<span id="tính-tuần-hoàn-trong-modulo"></span>
## Tính tuần hoàn trong modulo

Với dãy Fibonacci xét theo modulo $m$, nguyên lý Dirichlet cho phép chứng minh dễ dàng rằng dãy này có tính tuần hoàn. Vì mỗi số Fibonacci phụ thuộc vào hai số liền trước, cần mô tả trạng thái của dãy bằng cặp hai số Fibonacci liên tiếp. Xét $m^2+1$ cặp Fibonacci đầu tiên trong modulo:

$$
(F_0,\ F_1),\ (F_1,\ F_2),\ \ldots,\ (F_{m^2},\ F_{m^2 + 1})
$$

Hệ thặng dư modulo $m$ có kích thước $m$, nên có nhiều nhất $m^2$ cặp khác nhau. Do đó, trong $m^2+1$ cặp đầu tiên chắc chắn có hai cặp bằng nhau; từ hai cặp đó về sau sẽ sinh ra cùng một dãy Fibonacci. Vì vậy dãy Fibonacci là tuần hoàn, và chu kỳ dương nhỏ nhất không vượt quá $m^2$.

<span id="chu-kỳ-pisano"></span>
### Chu kỳ Pisano

Chu kỳ dương nhỏ nhất của dãy Fibonacci trong modulo $m$ được gọi là **chu kỳ Pisano** (Pisano period, [OEIS A001175](http://oeis.org/A001175)). Trong bài này, ký hiệu $\pi(m)$ là chu kỳ Pisano modulo $m$.

Quan sát này có thể dùng để tính giá trị của số Fibonacci thứ $n$ modulo $m$. Nếu $n$ rất lớn, ta cần tính chu kỳ của dãy Fibonacci modulo $m$. Dĩ nhiên chỉ cần tìm được một chu kỳ, không nhất thiết là chu kỳ dương nhỏ nhất.

Để làm vậy, ta có các kết luận sau:

1.  Với hai modulo nguyên tố cùng nhau $m_1,m_2$, có $\pi(m_1m_2)=\operatorname{lcm}(\pi(m_1),\pi(m_2))$.
2.  Với số nguyên tố $p$ và số nguyên dương $e$, có $\pi(p^{e})\mid p^{e-1}\pi(p)$.
3.  Với $m=2^e~(e\in\mathbf N_+)$, có $\pi(m)=3\cdot 2^{e-1}$.
4.  Với $m=5^e~(e\in\mathbf N_+)$, có $\pi(m)=4\cdot 5^e$.
5.  Cuối cùng, với số nguyên tố $p\equiv\pm1\pmod{10}$, có $\pi(p)\mid(p-1)$; với số nguyên tố $p\equiv\pm3\pmod{10}$, có $\pi(p)\mid 2(p+1)$.

Kết hợp các trường hợp này, ta suy ra: chu kỳ Pisano modulo $m$ không vượt quá $6m$, và dấu bằng xảy ra khi và chỉ khi $m = 2\times 5^e~(e\in\mathbf N_+)$.

Dựa trên các kết luận trên, ta có thể dùng phân tích thừa số nguyên tố để thu được phương pháp tính nhanh chu kỳ Pisano như sau:

??? example "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/combinatorics/fibonacci/pisano_estimate.cpp:pisano"
    ```

Chu kỳ thu được theo cách này có thể chỉ là một bội của chu kỳ Pisano. Để tìm chu kỳ Pisano chính xác, có thể tiếp tục xét các ước của chu kỳ đó; hoặc trực tiếp dùng [thuật toán BSGS](../number-theory/discrete-logarithm.md#thuật-toán-bước-lớn-bước-nhỏ) để tính trong độ phức tạp $O(\sqrt{m})$.

<span id="chứng-minh"></span>
### Chứng minh

Cuối cùng, bài viết chứng minh ngắn gọn các kết luận nêu trên về chu kỳ Pisano. Cần lưu ý rằng phương pháp dưới đây có thể mở rộng cho dãy truy hồi tuyến tính thuần nhất bậc hai với hệ số hằng nói chung. Dù hằng số cụ thể khác nhau, chu kỳ Pisano modulo $m$ của các dãy này đều là $O(m)$.

Quan sát đầu tiên là: nhờ [định lý số dư Trung Hoa](../number-theory/crt.md), ta có thể giới hạn việc thảo luận ở trường hợp modulo lũy thừa nguyên tố. Giả sử $m_1,m_2$ là hai modulo nguyên tố cùng nhau. Chu kỳ của dãy Fibonacci modulo $m_1$ là $\pi(m_1)$ và các bội của nó; chu kỳ modulo $m_2$ là $\pi(m_2)$ và các bội của nó. Do đó chu kỳ dương nhỏ nhất modulo $m_1m_2$ chính là bội chung nhỏ nhất của $\pi(m_1)$ và $\pi(m_2)$. Đây là kết luận 1 ở trên.

Một quan sát khác là: chu kỳ Pisano modulo $m$ thực chất là số nguyên dương nhỏ nhất $k$ sao cho

$$
A^k = \begin{pmatrix} 1&1\\1&0 \end{pmatrix}^k \equiv I \pmod{m}.
$$

Nói cách khác, nó là [bậc](../algebra/group-theory.md#cấp) của ma trận $A$ trong modulo $m$[^mod-m].

Với modulo lũy thừa nguyên tố $m=p^e$, ta có thể dùng lập luận nâng lũy thừa cổ điển để liên hệ với trường hợp modulo nguyên tố tương ứng. Đặt $k=\pi(p^e)$, khi đó tồn tại một ma trận vuông cấp hai $\Lambda$ sao cho

$$
A^k = p^e\Lambda + I 
$$

Do [định lý nhị thức](./combination.md#định-lý-nhị-thức), ta có

$$
A^{kp} = (p^e\Lambda + I)^p = I + \sum_{i=1}^p\binom{p}{i}(p^e\Lambda)^i \equiv I\pmod{p^{e+1}}. 
$$

Vì vậy, theo [tính chất của bậc](../number-theory/primitive-root.md#cấu-trúc-tuần-hoàn-của-lũy-thừa), có $\pi(p^{e+1})\mid kp = p\pi(p^e)$. Quy nạp theo $e$ cho thấy $\pi(p^e)\mid p^{e-1}\pi(p)$ luôn đúng.

Với trường hợp modulo nguyên tố $p$, bài viết xét hai cách chứng minh.

=== "Dùng công thức tổng quát"
    Một cách là dùng công thức tổng quát của dãy Fibonacci:
    
    $$
    F_n = \dfrac{1}{\sqrt{5}}\left(\dfrac{1+\sqrt{5}}{2}\right)^n - \dfrac{1}{\sqrt{5}}\left(\dfrac{1-\sqrt{5}}{2}\right)^n.
    $$
    
    Khai triển nó bằng định lý nhị thức và khử các hạng tử chứa căn:
    
    $$
    F_n = \dfrac{1}{2^{n-1}}\sum_{i=0}^{\lfloor(n-1)/2\rfloor}\binom{n}{2i+1}5^i.
    $$
    
    Với $p=2$, biểu thức này không thể lấy modulo trực tiếp, nhưng có thể kiểm tra rằng chu kỳ Pisano tương ứng là $\pi(2)=3$. Với $p=5$, có $F_n\equiv n\cdot 3^{n-1}\pmod{p}$, và có thể kiểm tra trực tiếp chu kỳ Pisano tương ứng là $\pi(5)=20$. Với các modulo nguyên tố lẻ còn lại, chia thành hai trường hợp:
    
    -   Nếu $p\equiv 1,4\pmod{5}$, ta có
    
        $$
        \begin{aligned}
        F_{p} &\equiv \dfrac{1}{2^{p-1}}\binom{p}{p}5^{(p-1)/2} \equiv 1 \pmod{p},\\
        F_{p+1} &\equiv \dfrac{1}{2^p}\left(\binom{p+1}{1} + \binom{p+1}{p}5^{(p-1)/2}\right) \equiv 1 \pmod{p}.
        \end{aligned}
        $$
    
        Trong quá trình rút gọn, ta dùng các kết luận sau: theo [định lý Lucas](../number-theory/lucas.md), với $0 < k < p$ đều có $\dbinom{p}{k}\equiv 0\pmod{p}$, và với $1 < k < p$ đều có $\dbinom{p+1}{k}\equiv 0\pmod{p}$; theo [định lý nhỏ Fermat](../number-theory/fermat.md#định-lý-nhỏ-fermat), có $2^{p-1}\equiv 5^{p-1}\equiv 1\pmod{p}$; với $p\equiv 1,4\pmod{5}$, $p$ là thặng dư bậc hai modulo $5$, nên theo [luật tương hỗ bậc hai](../number-theory/quad-residue.md#luật-thuận-nghịch-bậc-hai), $5$ cũng là thặng dư bậc hai modulo $p$, do đó $5^{(p-1)/2} \equiv 1\pmod{p}$. Suy ra $(F_p,F_{p+1}) \equiv (F_1,F_2) \pmod{p}$, nên $(p-1)$ là một chu kỳ modulo $p$. Vì vậy $\pi(p)\mid(p-1)$.
    -   Nếu $p\equiv 2,3\pmod{5}$, ta có
    
        $$
        \begin{aligned}
        F_{2p} &\equiv \dfrac{1}{2^{2p-1}}\binom{2p}{p}5^{(p-1)/2} \equiv -1 \pmod{p},\\
        F_{2p+1} &\equiv \dfrac{1}{2^{2p}}\left(\binom{2p+1}{1} + \binom{2p+1}{p}5^{(p-1)/2} + \binom{2p+1}{2p+1}5^p\right) \equiv -1\pmod{p}.
        \end{aligned}
        $$
    
        Trong quá trình rút gọn, ta dùng các kết luận sau: theo định lý Lucas, với $0 < k < p$ và $p < k < 2p$ đều có $\dbinom{p}{k}\equiv 0\pmod{p}$, đồng thời $\dbinom{2p}{p}\equiv 2\pmod{p}$; với $1 < k < p$ và $p + 1 < k < 2p$ đều có $\dbinom{p}{k}\equiv 0\pmod{p}$, đồng thời $\dbinom{2p+1}{p}\equiv 2\pmod{p}$; theo định lý nhỏ Fermat, có $2^{p-1}\equiv 5^{p-1}\equiv 1\pmod{p}$; với $p\equiv 2,3\pmod{5}$, $p$ là bất thặng dư bậc hai modulo $5$, nên theo luật tương hỗ bậc hai, $5$ cũng là bất thặng dư bậc hai modulo $p$, do đó $5^{(p-1)/2} \equiv -1\pmod{p}$. Suy ra $(F_{2p},F_{2p+1}) \equiv (F_{-2},F_{-1}) \pmod{p}$, nên $2(p+1)$ là một chu kỳ modulo $p$. Vì vậy $\pi(p)\mid 2(p+1)$.
    
    Chứng minh hoàn tất. Hạn chế của phương pháp này là nó phụ thuộc mạnh vào công thức tổng quát của dãy Fibonacci, nên khó mở rộng trực tiếp sang trường hợp tổng quát.

=== "Dùng trường mở rộng"
    Một cách chứng minh khác là trực tiếp tính bậc của ma trận $A=\begin{pmatrix}1&1\\1&0\end{pmatrix}$. [Đa thức đặc trưng](../linear-algebra/char-poly.md) của nó là $f(x) = x^2-x-1$, với biệt thức tương ứng $\Delta = 5$. Với modulo $p=5$, có $\Delta\equiv 0\pmod{5}$, ma trận $A$ có hai trị riêng trùng nhau $\lambda=3$ và không chéo hóa được, nên cần tính riêng. Với modulo $p\equiv 1,4\pmod{5}$, theo luật tương hỗ bậc hai, biệt thức $\Delta=5$ là thặng dư bậc hai modulo $p$, nên ma trận $A$ có hai trị riêng phân biệt $\lambda_1\neq\lambda_2$ trong trường $\mathbf F_p$; bậc của ma trận $A$ là $\operatorname{lcm}(\operatorname{ord}(\lambda_1),\operatorname{ord}(\lambda_2))$, tất yếu chia hết cho $|\mathbf F_p^\times|=p-1$. Với modulo $p\equiv 2,3\pmod{5}$, theo luật tương hỗ bậc hai, biệt thức $\Delta=5$ là bất thặng dư bậc hai modulo $p$, nên ma trận $A$ không có trị riêng trong trường $\mathbf F_p$, mà chỉ có hai trị riêng phân biệt $\lambda_1\neq\lambda_2$ trong [trường mở rộng](../algebra/field-theory.md#mở-rộng-trường) $\mathbf F_p[\sqrt{5}]$. Do tự đẳng cấu Frobenius $x\mapsto x^p$ hoán đổi hai nghiệm, ta có $\lambda_2=\lambda_1^p$, vì vậy $\lambda_1^{p+1}=\lambda_2^{p+1}=\lambda_1\lambda_2=-1$, tức là $\lambda_1^{2(p+1)}=\lambda_2^{2(p+1)}=1$. Từ đó, bậc của ma trận $A$ là $\operatorname{lcm}(\operatorname{ord}(\lambda_1),\operatorname{ord}(\lambda_2))$, tất yếu chia hết cho $2(p+1)$. Điều này cho kết luận giống phương pháp trước.

Tóm lại, với các trường hợp khác nhau, ta có tương ứng:

-   $\pi(2^e)=\dfrac{3}{2}\cdot 2^e,~\dfrac{1}{4}\pi(5^e)=5^e$.
-   Khi $p\equiv\pm1\pmod{10}$, $\pi(p^e) \mid (p-1)p^{e-1}$, nên $\pi(p^e)\le p^e$.
-   Khi $p\equiv\pm3\pmod{10}$, $\dfrac{1}{4}\pi(p^e) \mid \dfrac{p+1}{2}p^{e-1}$, nên $\dfrac{1}{4}\pi(p^e)\le p^e$.

Do đó, dùng kết luận 1, với modulo tổng quát $m=\prod_i p_i^{e_i}$, ta có

$$
\begin{aligned}
\pi(m)&=\operatorname{lcm}\{\pi(p_i^{e_i}):p_i\in\mathbf P\} \\
&\le \operatorname{lcm}\{\pi(p_i^{e_i}):p_i=2\text{ or }p_i\equiv\pm1~(\operatorname{mod}{10})\}\\
&\quad \cdot 4\cdot\operatorname{lcm}\{\pi(p_i^{e_i})/4:p_i=5\text{ or }p_i\equiv\pm3~(\operatorname{mod}{10})\}\\
&\le \prod\{\pi(p_i^{e_i}):p_i=2\text{ or }p_i\equiv\pm1~(\operatorname{mod}{10})\}\\
&\quad \cdot 4\cdot\prod\{\pi(p_i^{e_i})/4:p_i=5\text{ or }p_i\equiv\pm3~(\operatorname{mod}{10})\}\\
&\le \dfrac{3}{2}\cdot\prod\{p_i^{e_i}:p_i=2\text{ or }p_i\equiv\pm1~(\operatorname{mod}{10})\}\\
&\quad \cdot 4\cdot\prod\{p_i^{e_i}:p_i=5\text{ or }p_i\equiv\pm3~(\operatorname{mod}{10})\}\\
&= 6m.
\end{aligned}
$$

Điều này chứng tỏ chu kỳ Pisano của dãy Fibonacci modulo $m$ luôn không vượt quá $6m$, và dấu bằng xảy ra khi và chỉ khi $m=2\cdot 5^e$.

<span id="bài-tập"></span>
## Bài tập

-   [SPOJ - Euclid Algorithm Revisited](http://www.spoj.com/problems/MAIN74/)
-   [SPOJ - Fibonacci Sum](http://www.spoj.com/problems/FIBOSUM/)
-   [HackerRank - Is Fibo](https://www.hackerrank.com/challenges/is-fibo/problem)
-   [Project Euler - Even Fibonacci numbers](https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem)
-   [Luogu P4000 Fibonacci sequence](https://www.luogu.com.cn/problem/P4000)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [Fibonacci sequence - Wikipedia](https://en.wikipedia.org/wiki/Fibonacci_sequence)
-   [Zeckendorf's theorem - Wikipedia](https://en.wikipedia.org/wiki/Zeckendorf%27s_theorem)
-   [Pisano period - Wikipedia](https://en.wikipedia.org/wiki/Pisano_period)

**Trang này chủ yếu được dịch từ bài viết [Chisla Fibonachchi](http://e-maxx.ru/algo/fibonacci_numbers) và bản dịch tiếng Anh [Fibonacci Numbers](https://cp-algorithms.com/algebra/fibonacci-numbers.html). Bản tiếng Nga có giấy phép Public Domain + Leave a Link; bản tiếng Anh có giấy phép CC-BY-SA 4.0. Nội dung đã được chỉnh sửa.**

[^mod-m]: Nói chính xác, đó là bậc của ma trận $A$ trong nhóm tuyến tính tổng quát $GL_2(\mathbf Z_m)$.
