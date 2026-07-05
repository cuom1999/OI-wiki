author: H-J-Granger, ranwen, abc1763613206, Ahacad, Allenyou1126, AndrewWayne, AngelKitty, AtomAlpaca, Backl1ght, billchenchina, c-forrest, CCXXXI, Cheuring, Chrogeek, ChungZH, countercurrent-time, DepletedPrism, Early0v0, EarthMessenger, Enter-tainer, F1shAndCat, GavinZhengOI, Gesrua, Great-designer, greyqz, Haohu Shen, henryrabbit, heroming, hly1204, Ir1d, isdanni, jiang1997, kenlig, Lewy Zeng, lucifer1004, Menci, muoshuosha, NachtgeistW, needtocalmdown, opsiff, ouuan, ouuan, partychicken, schtonn, Sshwy, sshwy, StudyingFather, SukkaW, Taoran-01, Tiphereth-A, TrisolarisHD, untitledunrevised, Xeonacid, YouXam, Yukimaikoriya

Kiến thức nền: [số phức](../complex.md).

Bài viết này giới thiệu một thuật toán hỗ trợ tính tích của hai đa thức bậc $n$ trong thời gian $O(n\log n)$, hiệu quả hơn thuật toán trực tiếp $O(n^2)$. Vì phép nhân hai số nguyên cũng có thể xem như phép nhân đa thức, thuật toán này cũng có thể dùng để tăng tốc phép nhân số nguyên lớn.

<span id="mở-đầu"></span>
## Mở đầu

Ta xét hai đa thức $A$ và $B$:

$$
\begin{aligned}
A ={}& 5x^2 + 3x + 7 \\
B ={}& 7x^2 + 2x + 1 \\
\end{aligned}
$$

Tích $C = A \times B$ của hai đa thức có thể tính trong độ phức tạp thời gian $O(n^2)$ (ở đây $n$ là bậc của đa thức $A$ hoặc $B$):

$$
\begin{aligned}
C ={}& A \times B \\
  ={}& 35x^4 + 31x^3 + 60x^2 + 17x + 7
\end{aligned}
$$

Rõ ràng hệ số $c_i$ của đa thức $C$ thỏa mãn $c_i = \sum_{j = 0}^i a_j b_{i - j}$. Với thuật toán trực tiếp này, mỗi hạng cần thời gian $O(n)$ để tính, và có tổng cộng $O(n)$ hạng, nên độ phức tạp thời gian là $O(n^2)$.

Có thể tăng tốc để giảm độ phức tạp thời gian không? Nếu dùng biến đổi Fourier nhanh, ta có thể giảm độ phức tạp xuống $O(n \log n)$.

<span id="biến-đổi-fourier"></span>
## Biến đổi Fourier

Biến đổi Fourier (Fourier Transform) là một phương pháp phân tích tín hiệu: nó có thể phân tích các thành phần của tín hiệu, và cũng có thể tổng hợp tín hiệu từ các thành phần đó. Nhiều dạng sóng có thể được dùng làm thành phần của tín hiệu; biến đổi Fourier dùng sóng sin làm thành phần tín hiệu.

Đặt $f(t)$ là hàm theo thời gian $t$. Khi đó biến đổi Fourier có thể đo mức độ xuất hiện của chu kỳ có tần số $\omega$ trong $f(t)$:

$$
F(\omega)=\mathbb{F}[f(t)]=\int_{-\infty}^{\infty}f(t)\mathrm{e}^{-\mathrm{i}{\omega}t}dt
$$

Biến đổi ngược của nó là

$$
f(t)=\mathbb{F}^{-1}[F(\omega)]=\frac{1}{2\pi}\int_{-\infty}^{\infty}F(\omega)\mathrm{e}^{\mathrm{i}{\omega}t}d\omega
$$

Dạng của biến đổi ngược rất giống biến đổi thuận; mẫu số $2\pi$ đúng bằng chu kỳ của hàm mũ.

Biến đổi Fourier tương đương với việc lấy tích vô hướng liên tục giữa hàm trong miền thời gian và hàm mũ phức có chu kỳ $2\pi$. Biến đổi ngược vẫn là một tích vô hướng.

Biến đổi Fourier có định lý chập tương ứng: nó có thể chuyển phép chập trong miền thời gian thành phép nhân trong miền tần số, và cũng có thể chuyển phép chập trong miền tần số thành phép nhân trong miền thời gian.

<span id="biến-đổi-fourier-rời-rạc"></span>
## Biến đổi Fourier rời rạc

**Biến đổi Fourier rời rạc** (Discrete Fourier transform, DFT) là dạng rời rạc của biến đổi Fourier trên cả miền thời gian lẫn miền tần số; nó biến đổi các mẫu trong miền thời gian của tín hiệu thành các mẫu trong miền tần số của DTFT (discrete-time Fourier transform).

Biến đổi Fourier là tích vô hướng của các hàm liên tục dưới dạng tích phân, còn biến đổi Fourier rời rạc là tích vô hướng dưới dạng tổng.

Đặt $\{x_n\}_{n=0}^{N-1}$ là một dãy thỏa mãn điều kiện hữu hạn nào đó. Biến đổi Fourier rời rạc (DFT) của nó là:

$$
X_k=\sum_{n=0}^{N-1}x_n\mathrm{e}^{-\mathrm{i}\frac{2\pi}{N}kn}
$$

Trong đó $\mathrm{e}$ là cơ số của logarit tự nhiên, $i$ là đơn vị ảo. Thường dùng ký hiệu $\mathcal {F}$ để biểu diễn phép biến đổi này, tức là

$$
\hat{x}=\mathcal{F}x
$$

Tương tự dạng tích phân, **biến đổi Fourier rời rạc ngược** (IDFT) là:

$$
x_n=\frac{1}{N}\sum_{k=0}^{N-1}X_k\mathrm{e}^{\mathrm{i}\frac{2\pi}{N}kn}
$$

Có thể viết là:

$$
x=\mathcal{F}^{-1}\hat{x}
$$

Thực ra, hệ số chuẩn hóa đứng trước các tổng trong công thức DFT và IDFT không quá quan trọng. Trong định nghĩa trên, hệ số trước DFT và IDFT lần lượt là $1$ và $\frac {1}{N}$. Đôi khi ta sẽ đổi cả hai hệ số thành $\frac{1}{{\sqrt{N}}}$.

Biến đổi Fourier rời rạc vẫn là phép biến đổi từ miền thời gian sang miền tần số. Do dạng tổng có tính chất đặc biệt, ta có thể giải thích nó theo những cách khác.

Nếu xem dãy $x_n$ là các hệ số của hạng $x^n$ trong đa thức $f(x)$, thì $X_k$ tính được đúng bằng giá trị của đa thức $f(x)$ tại căn đơn vị $\mathrm{e}^{\frac{-2\pi \mathrm{i}k}{N}}$, tức $f(\mathrm{e}^{\frac{-2\pi \mathrm{i}k}{N}})$.

Điều này tạo thành một cách giải thích khác cho định lý chập: thực hiện phép tính giá trị đặc biệt trên đa thức. Biến đổi Fourier rời rạc chính là tính giá trị của đa thức tại các căn đơn vị.

Ví dụ tính:

$$
\dbinom{n}{3}+\dbinom{n}{7}+\dbinom{n}{11}+\dbinom{n}{15}+\ldots
$$

Định nghĩa hàm $f(x)$:

$$
f(x)={(1+x)}^n=\dbinom{n}{0}x^0+\dbinom{n}{1}x^1+\dbinom{n}{2}x^2+\dbinom{n}{3}x^3+\ldots
$$

Khi thay căn bậc bốn của đơn vị $f(\mathrm{i})$, ta thu được dãy sau:

$$
f(\mathrm{i})={(1+\mathrm{i})}^n=\dbinom{n}{0}+\dbinom{n}{1}\mathrm{i}-\dbinom{n}{2}-\dbinom{n}{3}\mathrm{i}+\ldots
$$

Do đó tổng dưới đây vừa đúng triệt tiêu các hạng còn lại:

$$
f(1)+\mathrm{i}f(\mathrm{i})-f(-1)-\mathrm{i}f(-\mathrm{i})=4\dbinom{n}{3}+4\dbinom{n}{7}+4\dbinom{n}{11}+4\dbinom{n}{15}+\ldots
$$

Vì vậy đáp án của bài toán này là:

$$
\dbinom{n}{3}+\dbinom{n}{7}+\dbinom{n}{11}+\dbinom{n}{15}+\ldots=\frac{2^n+\mathrm{i}(1+\mathrm{i})^n-\mathrm{i}(1-\mathrm{i})^n}{4}
$$

Bài toán này tính giá trị tại các căn đơn vị, vừa đúng tạo thành biến đổi Fourier rời rạc.

<span id="công-thức-ma-trận"></span>
### Công thức ma trận

Vì biến đổi Fourier rời rạc là một toán tử **tuyến tính**, nó có thể được mô tả bằng phép nhân ma trận. Trong biểu diễn ma trận, biến đổi Fourier rời rạc có dạng:

$$
\begin{bmatrix}
    X_{0}  \\
    X_{1}  \\
    X_{2}  \\
    \vdots \\
    X_{N-1}
\end{bmatrix}
=
\begin{bmatrix}
    1      & 1            & 1               & \cdots & 1                   \\
    1      & \alpha       & \alpha^{2}      & \cdots & \alpha^{N-1}        \\
    1      & \alpha^{2}   & \alpha^{4}      & \cdots & \alpha^{2(N-1)}     \\
    \vdots & \vdots       & \vdots          & \ddots & \vdots              \\
    1      & \alpha^{N-1} & \alpha^{2(N-1)} & \cdots & \alpha^{(N-1)(N-1)}
\end{bmatrix}
\begin{bmatrix}
    x_{0}  \\
    x_{1}  \\
    x_{2}  \\
    \vdots \\
    x_{N-1}
\end{bmatrix}
$$

Trong đó $\alpha = \mathrm{e}^{-\mathrm{i}\frac{2\pi}{N}}$.

<span id="biến-đổi-fourier-nhanh"></span>
## Biến đổi Fourier nhanh

FFT là một thuật toán cài đặt DFT hiệu quả, gọi là biến đổi Fourier nhanh (Fast Fourier Transform, FFT). Nó không phát hiện thêm điều gì mới về lý thuyết biến đổi Fourier, nhưng đối với việc ứng dụng biến đổi Fourier rời rạc trong hệ thống máy tính, hay nói cách khác là hệ thống số, có thể nói đây là một bước tiến lớn. Biến đổi số học nhanh (NTT) là cách cài đặt biến đổi Fourier nhanh (FFT) trên cơ sở số học.

Năm 1965, Cooley và Tukey công bố thuật toán biến đổi Fourier nhanh. Thực ra FFT đã được phát hiện trước đó, nhưng máy tính hiện đại khi ấy chưa ra đời, nên người ta chưa nhận ra tầm quan trọng của FFT. Một số nhà khảo cứu cho rằng FFT do Runge và König phát hiện năm 1924. Nhưng thực tế Gauss đã phát minh thuật toán này từ năm 1805, chỉ là không công bố.

<span id="cài-đặt-bằng-chia-để-trị"></span>
### Cài đặt bằng chia để trị

Tư tưởng cơ bản của thuật toán FFT là chia để trị. Với DFT, nó dùng chia để trị để tính giá trị của $f(x)$ khi $x=\omega_n^k$. Tư tưởng chia để trị của FFT cơ số 2 nằm ở việc tách đa thức thành các hạng bậc chẵn và bậc lẻ.

Lấy ví dụ đa thức có tổng cộng $8$ hạng:

$$
f(x) = a_0 + a_1x + a_2x^2+a_3x^3+a_4x^4+a_5x^5+a_6x^6+a_7x^7
$$

Tách thành hai nhóm theo tính chẵn lẻ của bậc, rồi rút $x$ ra ở phần bên phải:

$$
\begin{aligned}
f(x) &= (a_0+a_2x^2+a_4x^4+a_6x^6) + (a_1x+a_3x^3+a_5x^5+a_7x^7)\\
     &= (a_0+a_2x^2+a_4x^4+a_6x^6) + x(a_1+a_3x^2+a_5x^4+a_7x^6)
\end{aligned}
$$

Lần lượt dùng các hệ số bậc chẵn và bậc lẻ để lập hàm mới:

$$
\begin{aligned}
G(x) &= a_0+a_2x+a_4x^2+a_6x^3\\
H(x) &= a_1+a_3x+a_5x^2+a_7x^3
\end{aligned}
$$

Khi đó $f(x)$ ban đầu có thể biểu diễn bằng các hàm mới:

$$
f(x)=G\left(x^2\right) + x  \times  H\left(x^2\right)
$$

Dùng tính chất của căn đơn vị bậc chẵn $\omega^i_n = -\omega^{i + n/2}_n$, và vì $G\left(x^2\right)$ cũng như $H\left(x^2\right)$ là các hàm chẵn, ta biết trên mặt phẳng phức, tại $\omega^i_n$ và $\omega^{i+n/2}_n$, các giá trị tương ứng của $G(x^2)$ và $H(x^2)$ là như nhau. Suy ra:

$$
\begin{aligned}
f(\omega_n^k) &= G((\omega_n^k)^2) + \omega_n^k  \times H((\omega_n^k)^2) \\
              &= G(\omega_n^{2k}) + \omega_n^k  \times H(\omega_n^{2k}) \\
              &= G(\omega_{n/2}^k) + \omega_n^k  \times H(\omega_{n/2}^k)
\end{aligned}
$$

và:

$$
\begin{aligned}
f(\omega_n^{k+n/2}) &= G(\omega_n^{2k+n}) + \omega_n^{k+n/2}  \times H(\omega_n^{2k+n}) \\
                    &= G(\omega_n^{2k}) - \omega_n^k  \times H(\omega_n^{2k}) \\
                    &= G(\omega_{n/2}^k) - \omega_n^k  \times H(\omega_{n/2}^k)
\end{aligned}
$$

Do đó sau khi tính được $G(\omega_{n/2}^k)$ và $H(\omega_{n/2}^k)$, ta có thể đồng thời tính $f(\omega_n^k)$ và $f(\omega_n^{k+n/2})$. Vì vậy chỉ cần đệ quy DFT riêng cho $G$ và $H$.

Vì DFT chia để trị chỉ xử lý được độ dài đa thức bằng $2^m(m \in \mathbf{N}^ \ast )$; nếu không, khi chia để trị hai bên sẽ không dài bằng nhau và phần bên phải sẽ không lấy được hệ số. Vì thế trước lần DFT đầu tiên cần bổ sung dãy lên độ dài $2^m(m \in \mathbf{N}^\ast )$ (bổ sung hệ số bậc cao bằng $0$), thành một đa thức có bậc cao nhất là $2^m-1$.

Khi thay giá trị, vì cần thay $n$ giá trị khác nhau, ta thay $\omega_n^0,\omega_n^1,\omega_n^2,\cdots, \omega_n^{n-1} (n=2^m(m \in \mathbf{N}^ \ast ))$, tổng cộng $2^m$ giá trị khác nhau.

Về cài đặt, STL cung cấp mẫu số phức; tất nhiên cũng có thể tự cài đặt thủ công. Điểm khác nhau là khi dùng `complex` của STL, có thể gọi hàm `exp` để tính $\omega_n$. Nhưng thực ra dùng số phức thu được từ công thức Euler để tính $\omega_n$ cũng tương đương.

Trên đây là phần giới thiệu DFT trong thuật toán FFT: nó chuyển một đa thức từ biểu diễn hệ số sang biểu diễn bằng giá trị tại điểm.

Cần lưu ý là, vì ta dùng các căn phức của đơn vị, nên cần bổ sung các hạng bậc cao của đa thức $n$ hạng bằng không, sao cho $n = 2 ^ k, k \in \mathbf{N}^ \ast$.

???+ note "FFT đệ quy"
    ```cpp
    #include <cmath>
    #include <complex>
    
    using Comp = std::complex<double>;  // complex của STL
    
    constexpr Comp I(0, 1);  // i
    constexpr int MAX_N = 1 << 20;
    
    Comp tmp[MAX_N];
    
    // rev=1: DFT; rev=-1: IDFT
    // Sau khi gọi hàm này cần chú ý xử lý hệ số chuẩn hóa
    void DFT(Comp* f, int n, int rev) {
      if (n == 1) return;
      for (int i = 0; i < n; ++i) tmp[i] = f[i];
      // Đưa chỉ số chẵn sang trái, chỉ số lẻ sang phải
      for (int i = 0; i < n; ++i) {
        if (i & 1)
          f[n / 2 + i / 2] = tmp[i];
        else
          f[i / 2] = tmp[i];
      }
      Comp *g = f, *h = f + n / 2;
      // DFT đệ quy
      DFT(g, n / 2, rev), DFT(h, n / 2, rev);
      // cur là căn phức đơn vị hiện tại; với k = 0, nó ứng với omega^0_n = 1.
      // step là khoảng cách giữa hai căn phức đơn vị, thỏa mãn omega^k_n = step*omega^{k-1}*n,
      // định nghĩa tương đương với exp(I*(-2*M_PI/n*rev))
      Comp cur(1, 0), step(cos(2 * M_PI / n), sin(-2 * M_PI * rev / n));
      for (int k = 0; k < n / 2;
           ++k) {  // F(omega^k_n) = G(omega^k*{n/2}) + omega^k*n\*H(omega^k*{n/2})
        tmp[k] = g[k] + cur * h[k];
        // F(omega^{k+n/2}*n) = G(omega^k*{n/2}) - omega^k_n*H(omega^k\_{n/2})
        tmp[k + n / 2] = g[k] - cur * h[k];
        cur *= step;
      }
      for (int i = 0; i < n; ++i) f[i] = tmp[i];
    }
    ```

Độ phức tạp thời gian là $O(n\log n)$.

<span id="cài-đặt-bằng-phương-pháp-nhân-đôi"></span>
### Cài đặt bằng phương pháp nhân đôi

Thuật toán này còn có thể tiếp tục tối ưu theo góc nhìn "chia để trị". Với FFT cơ số 2, mỗi lần ta tách hệ số của các hạng bậc lẻ và bậc chẵn trong toàn bộ đa thức, cho đến khi chỉ còn một hệ số. Tuy nhiên, quá trình đệ quy này cần nhiều bộ nhớ hơn. Do đó, ta có thể trước hết "mô phỏng đệ quy" để "tách" các hệ số này ngay trong mảng ban đầu, rồi sau đó "nhân đôi" để gộp các giá trị đã tính.

Việc "tách" có thể thực hiện bằng hoán vị đảo bit.

Việc "gộp" có thể dùng phép toán cánh bướm để tối ưu, chỉ cần thêm $O(1)$ bộ nhớ phụ.

<span id="hoán-vị-đảo-bit"></span>
#### Hoán vị đảo bit

Lấy đa thức $8$ hạng làm ví dụ, mô phỏng quá trình tách:

-   Dãy ban đầu là $\{x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7\}$
-   Sau một lần chia đôi: $\{x_0, x_2, x_4, x_6\},\{x_1, x_3, x_5, x_7 \}$
-   Sau hai lần chia đôi: $\{x_0,x_4\} \{x_2, x_6\},\{x_1, x_5\},\{x_3, x_7 \}$
-   Sau ba lần chia đôi: $\{x_0\}\{x_4\}\{x_2\}\{x_6\}\{x_1\}\{x_5\}\{x_3\}\{x_7 \}$

Quy luật: thực ra đó là dãy ban đầu, mỗi số được biểu diễn nhị phân, rồi đảo ngược các bit nhị phân, ta được chỉ số của vị trí cuối cùng. Ví dụ $x_1$ là 001, đảo ngược thành 100, tức là 4, và vị trí cuối cùng thật sự là 4. Ta gọi phép biến đổi này là hoán vị đảo bit (bit-reversal permutation); phần chứng minh dành cho bạn đọc tự kiểm chứng.

Theo định nghĩa, ta có thể tính kết quả biến đổi của mỗi số trong thời gian $O(n)$:

???+ note "Cài đặt hoán vị đảo bit ($O(n)$)"
    ```cpp
    /*
     * Biến đổi đảo vị trí trước khi thực hiện FFT và IFFT
     * Hoán đổi vị trí i với vị trí thu được sau khi đảo bit nhị phân của i
     * len phải là lũy thừa của 2
     */
    void change(Complex y[], int len) {
      // Ban đầu i là 0...01, còn j là 10...0; chúng đối xứng nhau trong nhị phân.
      // Sau đó i tăng dần một đơn vị, còn j vẫn duy trì đối xứng ngược với i cho đến i = 1...11.
      for (int i = 1, j = len / 2, k; i < len - 1; i++) {
        // Hoán đổi hai phần tử có chỉ số đảo bit của nhau; i < j đảm bảo chỉ đổi một lần
        if (i < j) swap(y[i], y[j]);
        // i tăng bình thường thêm 1, j tăng theo kiểu đảo bit, luôn giữ i và j là đảo bit của nhau.
        // Ở đây k biểu thị bit cao nhất nơi 0 xuất hiện. j trước hết trừ đi số có các bit cao đều là 1,
        // cho đến khi gặp 0, sau đó cộng lại là được.
        // Xét số lần lật bit trong j: bit cao nhất sẽ lật n lần,
        // bit cao thứ hai sẽ lật n/2 lần, và cứ tiếp tục như vậy, nên độ phức tạp thời gian là:
        // T(n) = n + n/2 + n/4 + ... = O(n)
        k = len / 2;
        while (j >= k) {
          j = j - k;
          k = k / 2;
        }
        j += k;
      }
    }
    ```

Hoán vị đảo bit cũng có thể được suy dẫn từ nhỏ đến lớn trong $O(n)$. Đặt $len=2^k$, trong đó $k$ là độ dài của số nhị phân; đặt $R(x)$ là số thu được sau khi đảo ngược số nhị phân $x$ có độ dài $k$ (bổ sung $0$ ở bit cao). Giá trị cần tính là $R(0),R(1),\cdots,R(n-1)$.

Trước hết $R(0)=0$.

Ta tính $R(x)$ từ nhỏ đến lớn. Vì vậy khi tính $R(x)$, giá trị $R\left(\left\lfloor \dfrac{x}{2} \right\rfloor\right)$ đã biết. Do đó ta dịch phải $x$ một bit (chia cho $2$), rồi đảo bit, sau đó dịch phải một bit, sẽ thu được kết quả đảo bit của $x$ **trừ bit hàng đơn vị (trong nhị phân)**.

Xét kết quả đảo của bit hàng đơn vị: nếu bit hàng đơn vị là $0$, sau khi đảo, bit cao nhất là $0$. Nếu bit hàng đơn vị là $1$, sau khi đảo, bit cao nhất là $1$, nên còn phải cộng $\dfrac{len}{2}=2^{k-1}$. Tóm lại

$$
R(x)=\left\lfloor \frac{R\left(\left\lfloor \frac{x}{2} \right\rfloor\right)}{2} \right\rfloor + (x\bmod 2)\times \frac{len}{2}
$$

Ví dụ: đặt $k=5$, $len=(100000)_2$. Để đảo $(11001)_2$:

1.  Xét $(1100)_2$, ta biết $R((1100)_2)=R((01100)_2)=(00110)_2$, dịch phải một bit sẽ được $(00011)_2$.
2.  Xét bit hàng đơn vị: nếu là $1$, nó sẽ được đảo lên bit cao nhất của số, tức là cộng thêm $(10000)_2=2^{k-1}$ vào số đã đảo; nếu là $0$ thì không cần thay đổi.

???+ note "Cài đặt hoán vị đảo bit ($O(n)$)"
    ```cpp
    // Cũng cần đảm bảo len là lũy thừa của 2
    // Gọi rev[i] là giá trị sau khi đảo bit của i
    void change(Complex y[], int len) {
      for (int i = 0; i < len; ++i) {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1) {  // Nếu bit cuối là 1, đảo thành len/2
          rev[i] |= len >> 1;
        }
      }
      for (int i = 0; i < len; ++i) {
        if (i < rev[i]) {  // Đảm bảo mỗi cặp số chỉ đảo một lần
          swap(y[i], y[rev[i]]);
        }
      }
      return;
    }
    ```

<span id="tối-ưu-bằng-phép-toán-cánh-bướm"></span>
#### Tối ưu bằng phép toán cánh bướm

Sau khi biết $G(\omega_{n/2}^k)$ và $H(\omega_{n/2}^k)$, cần dùng hai công thức sau để tính $f(\omega_n^k)$ và $f(\omega_n^{k+n/2})$:

$$
\begin{aligned}
    f(\omega_n^k)       & = G(\omega_{n/2}^k) + \omega_n^k \times H(\omega_{n/2}^k) \\
    f(\omega_n^{k+n/2}) & = G(\omega_{n/2}^k) - \omega_n^k \times H(\omega_{n/2}^k)
\end{aligned}
$$

Sau khi dùng hoán vị đảo bit, với $n, k$ cho trước:

-   Giá trị $G(\omega_{n/2}^k)$ được lưu ở vị trí có chỉ số mảng $k$, giá trị $H(\omega_{n/2}^k)$ được lưu ở vị trí có chỉ số mảng $k + \dfrac{n}{2}$.
-   Giá trị $f(\omega_n^k)$ sẽ được lưu ở vị trí có chỉ số mảng $k$, giá trị $f(\omega_n^{k+n/2})$ sẽ được lưu ở vị trí có chỉ số mảng $k + \dfrac{n}{2}$.

Do đó có thể ghi đè trực tiếp tại các vị trí có chỉ số mảng $k$ và $k + \frac{n}{2}$ mà không cần mở mảng phụ để lưu giá trị. Phương pháp này được gọi là **phép toán cánh bướm**, hay chính xác hơn là phép toán cánh bướm cơ số 2.

Giải thích chi tiết hơn cách dùng phép toán cánh bướm để hoàn thành tất cả các phép gộp có độ dài đoạn $\frac{n}{2}$:

1.  Đặt độ dài đoạn là $s = \frac{n}{2}$;
2.  Đồng thời duyệt đầu trái $l_g = 0, 2s, 4s, \cdots, N-2s$ của dãy $\{G(\omega_{n/2}^k)\}$ và đầu trái $l_h = s, 3s, 5s, \cdots, N-s$ của dãy $\{H(\omega_{n/2}^k)\}$;
3.  Khi gộp hai đoạn, duyệt $k = 0, 1, 2, \cdots, s-1$; lúc này $G(\omega_{n/2}^k)$ được lưu ở vị trí có chỉ số mảng $l_g + k$, và $H(\omega_{n/2}^k)$ được lưu ở vị trí có chỉ số mảng $l_h + k$;
4.  Dùng phép toán cánh bướm để tính $f(\omega_n^k)$ và $f(\omega_n^{k+n/2})$, rồi ghi đè trực tiếp tại vị trí ban đầu.

<span id="biến-đổi-fourier-ngược-nhanh"></span>
## Biến đổi Fourier ngược nhanh

Biến đổi Fourier ngược có thể biểu diễn bằng biến đổi Fourier. Ta có hai cách hiểu điều này.

<span id="theo-góc-nhìn-đại-số-tuyến-tính"></span>
### Theo góc nhìn đại số tuyến tính

Tác dụng của IDFT (biến đổi Fourier ngược) là chuyển dạng giá trị tại điểm của đa thức mục tiêu về dạng hệ số. Bản thân DFT là một phép biến đổi tuyến tính; có thể hiểu là xem đa thức mục tiêu như một vector, nhân bên trái với một ma trận để thu được vector sau biến đổi, qua đó mô phỏng quá trình thay các căn phức của đơn vị vào đa thức:

$$
\begin{bmatrix}y_0 \\ y_1 \\ y_2 \\ y_3 \\ \vdots \\ y_{n-1} \end{bmatrix}
=
\begin{bmatrix}1 & 1 & 1 & 1 & \cdots & 1 \\
1 & \omega_n^1 & \omega_n^2 & \omega_n^3 & \cdots & \omega_n^{n-1} \\
1 & \omega_n^2 & \omega_n^4 & \omega_n^6 & \cdots & \omega_n^{2(n-1)} \\
1 & \omega_n^3 & \omega_n^6 & \omega_n^9 & \cdots & \omega_n^{3(n-1)} \\
\vdots & \vdots & \vdots & \vdots & \ddots & \vdots \\
1 & \omega_n^{n-1} & \omega_n^{2(n-1)} & \omega_n^{3(n-1)} & \cdots & \omega_n^{(n-1)^2} \end{bmatrix}
\begin{bmatrix} a_0 \\ a_1 \\ a_2 \\ a_3 \\ \vdots \\ a_{n-1} \end{bmatrix}
$$

Bây giờ ta đã có kết quả ở vế trái. Các giá trị $x$ trong ma trận giữa cũng tương ứng một-một với biểu diễn bằng giá trị tại điểm của đa thức mục tiêu. Vì vậy, theo kiến thức cơ bản về ma trận, chỉ cần nhân bên trái cả hai vế với ma trận nghịch đảo của ma trận lớn ở giữa.

Do các phần tử của ma trận này rất đặc biệt, ma trận nghịch đảo của nó cũng có tính chất đặc biệt: chỉ cần **lấy nghịch đảo** từng phần tử, rồi **chia cho độ dài biến đổi $n$**, là thu được ma trận nghịch đảo.

Lưu ý: độ dài của biến đổi Fourier không phải là độ dài của đa thức; độ dài biến đổi phải lớn hơn độ dài của đa thức tích. Các đa thức cần nhân nếu chưa đủ dài thì cần bổ sung $0$ ở các hạng bậc cao.

Để kết quả tính được là nghịch đảo của ban đầu, theo công thức Euler, ta có

$$
\frac{1}{\omega_k}=\omega_k^{-1}=\mathrm{e}^{-\frac{2\pi \mathrm{i}}{k}}=\cos\left(\frac{2\pi}{k}\right)+\mathrm{i} \sin\left(-\frac{2\pi}{k}\right)
$$

Do đó ta có thể thử chọn căn đơn vị $\omega_k$ là $\mathrm{e}^{-\frac{2\pi \mathrm{i}}{k}}$, như vậy kết quả tính được sẽ thành nghịch đảo của ban đầu; sau đó thao tác duy nhất thêm vào là **chia cho độ dài $n$** của nó, còn các thao tác khác hoàn toàn giống DFT. Ta có thể định nghĩa một hàm, thêm một tham số $1$ hoặc $-1$ trong hàm, rồi nhân nó với $\pi$. Truyền vào $1$ là DFT, truyền vào $-1$ là IDFT.

<span id="tính-chu-kỳ-của-căn-phức-đơn-vị"></span>
### Tính chu kỳ của căn phức đơn vị

Dùng tính chu kỳ của căn phức đơn vị cũng có thể hiểu quan hệ giữa IDFT và DFT.

Xét đa thức ban đầu $f(x)=a_0+a_1x+a_2x^2+\cdots+a_{n-1}x^{n-1}=\sum_{i=0}^{n-1}a_ix^i$. IDFT chính là khôi phục biểu diễn bằng giá trị tại điểm về biểu diễn hệ số.

Xét **phương pháp xây dựng**. Đã biết $y_i=f\left( \omega_n^i \right),i\in\{0,1,\cdots,n-1\}$, cần tìm $\{a_0,a_1,\cdots,a_{n-1}\}$. Lập đa thức sau:

$$
A(x)=\sum_{i=0}^{n-1}y_ix^i
$$

Tương đương với việc xem $\{y_0,y_1,y_2,\cdots,y_{n-1}\}$ là biểu diễn hệ số của đa thức $A$.

Lúc này ta có hai cách suy diễn, tương ứng với hai cách cài đặt.

<span id="cách-1"></span>
#### Cách 1

Đặt $b_i=\omega_n^{-i}$, khi đó biểu diễn bằng giá trị tại các điểm $x=b_0,b_1,\cdots,b_{n-1}$ của đa thức $A$ là $\left\{ A(b_0),A(b_1),\cdots,A(b_{n-1}) \right\}$.

Biến đổi một chút công thức định nghĩa của $A(x)$, có thể biểu diễn $A(b_k)$ thành

$$
\begin{aligned}
A(b_k)&=\sum_{i=0}^{n-1}f(\omega_n^i)\omega_n^{-ik}=\sum_{i=0}^{n-1}\omega_n^{-ik}\sum_{j=0}^{n-1}a_j(\omega_n^i)^{j}\\
&=\sum_{i=0}^{n-1}\sum_{j=0}^{n-1}a_j\omega_n^{i(j-k)}=\sum_{j=0}^{n-1}a_j\sum_{i=0}^{n-1}\left(\omega_n^{j-k}\right)^i\\
\end{aligned}
$$

Ký hiệu $S\left(\omega_n^a\right)=\sum_{i=0}^{n-1}\left(\omega_n^a\right)^i$.

Khi $a=0 \pmod{n}$, $S\left(\omega_n^a\right)=n$.

Khi $a\neq 0 \pmod{n}$, dùng phép trừ lệch chỉ số:

$$
\begin{aligned}
S\left(\omega_n^a\right)&=\sum_{i=0}^{n-1}\left(\omega_n^a\right)^i\\
\omega_n^a S\left(\omega_n^a\right)&=\sum_{i=1}^{n}\left(\omega_n^a\right)^i\\
S\left(\omega_n^a\right)&=\frac{\left(\omega_n^a\right)^n-\left(\omega_n^a\right)^0}{\omega_n^a-1}=0\\
\end{aligned}
$$

Nói cách khác

$$
S\left(\omega_n^a\right)=
\begin{cases}
n,&a=0\\
0,&a\neq 0
\end{cases}
$$

Thế lại vào công thức ban đầu:

$$
A(b_k)=\sum_{j=0}^{n-1}a_jS\left(\omega_n^{j-k}\right)=a_k\cdot n
$$

Nói cách khác, với các điểm $b_i=\omega_n^{-i}$, biểu diễn bằng giá trị tại điểm của $A$ là

$$
\begin{aligned}
&\left\{ (b_0,A(b_0)),(b_1,A(b_1)),\cdots,(b_{n-1},A(b_{n-1})) \right\}\\
=&\left\{ (b_0,a_0\cdot n),(b_1,a_1\cdot n),\cdots,(b_{n-1},a_{n-1}\cdot n) \right\}
\end{aligned}
$$

Tóm lại, ta lấy căn đơn vị thành nghịch đảo của nó, chạy FFT một lần trên $\{y_0,y_1,y_2,\cdots,y_{n-1}\}$, rồi chia cho $n$ là thu được biểu diễn hệ số của $f(x)$.

<span id="cách-2"></span>
#### Cách 2

Ta trực tiếp thế $\omega_n^i$ vào $A(x)$.

Quá trình suy diễn gần giống cách 1; cuối cùng ta thu được $A(\omega_n^k) = \sum_{j=0}^{n-1}a_jS\left(\omega_n^{j+k}\right)$.

Khi và chỉ khi $j+k=0 \pmod{n}$ thì $S\left(\omega_n^{j+k}\right) = n$, ngược lại bằng $0$. Do đó $A(\omega_n^k) = a_{n-k}\cdot n$.

Điều này có nghĩa là sau khi thực hiện DFT trên $\{y_0,y_1,y_2,\cdots,y_{n-1}\}$, chia cho $n$, rồi đảo ngược $n - 1$ phần tử phía sau, ta cũng khôi phục được biểu diễn hệ số của $f(x)$.

<span id="cài-đặt-mã-nguồn"></span>
### Cài đặt mã nguồn

Vì vậy hàm FFT của ta có thể kiêm nhiệm cả DFT lẫn IDFT. Cài đặt như sau:

???+ note "FFT không đệ quy (tương ứng cách 1)"
    ```cpp
    /*
     * Thực hiện FFT
     * len phải có dạng 2^k
     * on == 1 là DFT, on == -1 là IDFT
     */
    void fft(Complex y[], int len, int on) {
      // Hoán vị đảo bit
      change(y, len);
      // Mô phỏng quá trình gộp: ban đầu gộp từ độ dài 1 lên độ dài 2, tiếp tục đến độ dài len.
      for (int h = 2; h <= len; h <<= 1) {
        // wn: khoảng cách giữa các căn đơn vị hiện tại, w^1_h
        Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
        // Gộp, tổng cộng len / h lần.
        for (int j = 0; j < len; j += h) {
          // Tính căn đơn vị hiện tại, ban đầu là 1 = w^0_n, sau đó tăng theo khoảng cách wn: w^1_n
          // ...
          Complex w(1, 0);
          for (int k = j; k < j + h / 2; k++) {
            // Phần bên trái và bên phải là lời giải của các bài toán con
            Complex u = y[k];
            Complex t = w * y[k + h / 2];
            // Đây là việc cộng kết quả chia để trị của hai phần lại với nhau
            y[k] = u + t;
            y[k + h / 2] = u - t;
            // omega trong nửa "step" sau nhất định đối dấu với omega trong "nửa trước"
            // Điểm trên "vòng tròn đỏ" quay tròn một vòng sẽ "quay về", quay nửa vòng thì thành số đối
            // Bình phương của số đối bằng bình phương của chính số đó
            w = w * wn;
          }
        }
      }
      // Nếu là IDFT, mỗi phần tử của ma trận nghịch đảo không chỉ là nghịch đảo của phần tử gốc, mà còn phải chia cho độ dài len.
      if (on == -1) {
        for (int i = 0; i < len; i++) {
          y[i].x /= len;
          y[i].y /= len;
        }
      }
    }
    ```

???+ note "FFT không đệ quy (tương ứng cách 2)"
    ```cpp
    /*
     * Thực hiện FFT
     * len phải có dạng 2^k
     * on == 1 là DFT, on == -1 là IDFT
     */
    void fft(Complex y[], int len, int on) {
      change(y, len);
      for (int h = 2; h <= len; h <<= 1) {             // Mô phỏng quá trình gộp
        Complex wn(cos(2 * PI / h), sin(2 * PI / h));  // Tính căn đơn vị hiện tại
        for (int j = 0; j < len; j += h) {
          Complex w(1, 0);  // Tính căn đơn vị hiện tại
          for (int k = j; k < j + h / 2; k++) {
            Complex u = y[k];
            Complex t = w * y[k + h / 2];
            y[k] = u + t;  // Đây là việc cộng kết quả chia để trị của hai phần lại với nhau
            y[k + h / 2] = u - t;
            // omega trong nửa "step" sau nhất định đối dấu với omega trong "nửa trước"
            // Điểm trên "vòng tròn đỏ" quay tròn một vòng sẽ "quay về", quay nửa vòng thì thành số đối
            // Bình phương của số đối bằng bình phương của chính số đó
            w = w * wn;
          }
        }
      }
      if (on == -1) {
        reverse(y + 1, y + len);
        for (int i = 0; i < len; i++) {
          y[i].x /= len;
          y[i].y /= len;
        }
      }
    }
    ```

??? note "Mẫu FFT ([HDU 1402 - A * B Problem Plus](http://acm.hdu.edu.cn/showproblem.php?pid=1402))"
    ```cpp
    --8<-- "docs/math/code/poly/fft/fft_3.cpp"
    ```

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

1.  [Ghi chú thuật toán của Taojiang](https://zhuanlan.zhihu.com/p/41867199).
