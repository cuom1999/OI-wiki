author: H-J-Granger, Chrogeek, countercurrent-time, Enter-tainer, Great-designer, iamtwz, Ir1d, ksyx, mao1t, Menci, NachtgeistW, Nanarikom, ShaoChenHeng, StudyingFather, SukkaW, Tiphereth-A, zyj-111

<span id="định-nghĩa-tích-phân-xác-định"></span>
## Định nghĩa tích phân xác định

Nói đơn giản, tích phân xác định $\int_{l}^{r}f(x)\mathrm{d}x$ của hàm $f(x)$ trên đoạn $[l,r]$ là diện tích miền được bao bởi $f(x)$ và trục $x$ trên đoạn $[l,r]$; phần nằm phía trên trục $x$ được tính dương, còn phần nằm phía dưới trục $x$ được tính âm.

Trong nhiều tình huống, cần tính xấp xỉ một tích phân một cách hiệu quả và chính xác. **Phương pháp Simpson** được giới thiệu dưới đây là một phương pháp tích phân số như vậy.

<span id="phương-pháp-simpson"></span>
## Phương pháp Simpson

Ý tưởng của phương pháp này là chia khoảng lấy tích phân thành nhiều đoạn nhỏ, rồi trên mỗi đoạn áp dụng công thức tích phân của hàm bậc hai.

??? note "Công thức tích phân hàm bậc hai (công thức Simpson)"
    Với một hàm bậc hai $f(x)=ax^2+bx+c$, công thức sau đúng:
    
    $$
    \int_l^r f(x) {\mathrm d}x = \frac{(r-l)(f(l)+f(r)+4 f(\frac{l+r}{2}))}{6}
    $$
    
    Quá trình suy ra:
    với hàm bậc hai $f(x)=ax^2+bx+c$, nguyên hàm là $F(x)=\int_0^x f(x) {\mathrm d}x = \frac{a}{3}x^3+\frac{b}{2}x^2+cx+D$, trong đó $D$ là một hằng số. Khi đó
    
    $$
    \begin{aligned}
    \int_l^r f(x) {\mathrm d}x &= F(r)-F(l) \\
    &= \frac{a}{3}(r^3-l^3)+\frac{b}{2}(r^2-l^2)+c(r-l) \\
    &=(r-l)(\frac{a}{3}(l^2+r^2+lr)+\frac{b}{2}(l+r)+c) \\
    &=\frac{r-l}{6}(2al^2+2ar^2+2alr+3bl+3br+6c)\\
    &=\frac{r-l}{6}((al^2+bl+c)+(ar^2+br+c)+4(a(\frac{l+r}{2})^2+b(\frac{l+r}{2})+c)) \\
    &=\frac{r-l}{6}(f(l)+f(r)+4f(\frac{l+r}{2}))
    \end{aligned}
    $$

Dựa trên công thức Simpson này, trước hết xét phương pháp Simpson thông thường.

<span id="phương-pháp-simpson-thông-thường"></span>
### Phương pháp Simpson thông thường

Phương pháp này được công bố trong một bài báo của Thomas Simpson vào năm 1743.

<span id="mô-tả"></span>
#### Mô tả

Cho một số tự nhiên $n$, chia đoạn $[l, r]$ thành $2n$ đoạn con bằng nhau.

$x_i = l + i h, ~~ i = 0 \ldots 2n,$ $h = \frac {r-l} {2n}.$

Giá trị tích phân trên từng đoạn nhỏ $[x_ {2i-2}, x_ {2i}]$, $i = 1\ldots n$, có thể được tính riêng rồi cộng lại để thu được tích phân tổng.

Với một đoạn $[x_ {2i-2}, x_ {2i}]$, $i = 1\ldots n$, chọn ba điểm $(x_ {2i-2}, x_ {2i-1}, x_ {2i})$ sẽ xác định duy nhất một parabol, tức một hàm $P(x)$. Khi đó việc tính tích phân của hàm ban đầu trên đoạn này được chuyển thành tính tích phân của hàm bậc hai mới $P(x)$ trên cùng đoạn. Nhờ vậy, công thức Simpson cho xấp xỉ:

$\int_{x_ {2i-2}} ^ {x_ {2i}} f (x) ~dx \approx \int_{x_ {2i-2}} ^ {x_ {2i}} P (x) ~dx = \left(f(x_{2i-2}) + 4f(x_{2i-1})+(f(x_{2i})\right)\frac {h} {3}$

Cộng theo từng đoạn sẽ cho kết luận sau:

$\int_l ^ r f (x) dx \approx \left(f (x_0) + 4 f (x_1) + 2 f (x_2) + 4f(x_3) + 2 f(x_4) + \ldots + 4 f(x_{2N-1}) + f(x_{2N}) \right)\frac {h} {3}$

<span id="sai-số"></span>
#### Sai số

Kết luận về sai số của phương pháp Simpson thông thường là

$$
-\tfrac{1}{90} \left(\tfrac{r-l}{2}\right)^5 f^{(4)}(\xi)
$$

trong đó $\xi$ là một giá trị nào đó thuộc đoạn $[l,r]$.

<span id="cài-đặt"></span>
#### Cài đặt

=== "C++"
    ```cpp
    constexpr int N = 1000 * 1000;
    
    double simpson_integration(double a, double b) {
      double h = (b - a) / N;
      double s = f(a) + f(b);
      for (int i = 1; i <= N - 1; ++i) {
        double x = a + h * i;
        s += f(x) * ((i & 1) ? 4 : 2);
      }
      s *= h / 3;
      return s;
    }
    ```

=== "Python"
    ```python
    N = 1000 * 1000
    
    
    def simpson_integration(a, b):
        h = (b - a) / N
        s = f(a) + f(b)
        for i in range(1, N):
            x = a + h * i
            if i & 1:
                s = s + f(x) * 4
            else:
                s = s + f(x) * 2
        s = s * (h / 3)
        return s
    ```

<span id="phương-pháp-simpson-thích-nghi"></span>
### Phương pháp Simpson thích nghi

Để bảo đảm độ chính xác, thời gian chạy của phương pháp thông thường phụ thuộc vào $n$. Vì vậy, cần một phương pháp phù hợp hơn.

Vấn đề còn lại là cách chia đoạn. Nếu số đoạn quá ít thì sai số tính toán lớn; nếu số đoạn quá nhiều thì hiệu quả thời gian thấp. Cần tìm điểm cân bằng giữa độ chính xác và hiệu quả.

Quan sát then chốt là: nếu một đoạn đồ thị đã rất gần với một hàm bậc hai, thì việc thay trực tiếp vào công thức để lấy tích phân sẽ cho giá trị rất chính xác, và không cần tiếp tục chia nhỏ đoạn đó.

Từ đó thu được một cách chia đoạn: mỗi lần kiểm tra mức độ giống nhau giữa đoạn hiện tại và một hàm bậc hai; nếu đủ giống thì thay trực tiếp vào công thức để tính, ngược lại chia đoạn hiện tại thành hai nửa trái và phải rồi giải đệ quy.

Câu hỏi còn lại là cách đánh giá mỗi đoạn có đủ giống hàm bậc hai hay không.

Thay trực tiếp đoạn hiện tại vào công thức để tính tích phân, rồi chia đoạn hiện tại tại trung điểm thành hai đoạn và lại thay trực tiếp hai đoạn đó vào công thức. Nếu tích phân của đoạn hiện tại và tổng tích phân của hai đoạn sau khi chia chênh lệch rất nhỏ, thì có thể xem đoạn hiện tại rất giống một hàm bậc hai và không cần chia đệ quy nữa.

Trên đây là ý tưởng của phương pháp Simpson thích nghi. Khi kiểm tra chia để trị, ngoài việc kiểm tra độ chính xác, thông thường còn ép thực hiện một số lần lặp tối thiểu.

Mã tham khảo như sau:

=== "C++"
    ```cpp
    double simpson(double l, double r) {
      double mid = (l + r) / 2;
      return (r - l) * (f(l) + 4 * f(mid) + f(r)) / 6;  // Công thức Simpson
    }
    
    double asr(double l, double r, double eps, double ans, int step) {
      double mid = (l + r) / 2;
      double fl = simpson(l, mid), fr = simpson(mid, r);
      if (abs(fl + fr - ans) <= 15 * eps && step < 0)
        return fl + fr + (fl + fr - ans) / 15;  // Đủ giống thì trả về trực tiếp
      return asr(l, mid, eps / 2, fl, step - 1) +
             asr(mid, r, eps / 2, fr, step - 1);  // Nếu không, chia đôi rồi đệ quy
    }
    
    double calc(double l, double r, double eps) {
      return asr(l, r, eps, simpson(l, r), 12);
    }
    ```

=== "Python"
    ```python
    def simpson(l, r):
        mid = (l + r) / 2
        return (r - l) * (f(l) + 4 * f(mid) + f(r)) / 6  # Công thức Simpson
    
    
    def asr(l, r, eps, ans, step):
        mid = (l + r) / 2
        fl = simpson(l, mid)
        fr = simpson(mid, r)
        if abs(fl + fr - ans) <= 15 * eps and step < 0:
            return fl + fr + (fl + fr - ans) / 15  # Đủ giống thì trả về trực tiếp
        return asr(l, mid, eps / 2, fl, step - 1) + asr(
            mid, r, eps / 2, fr, step - 1
        )  # Nếu không, chia đôi rồi đệ quy
    
    
    def calc(l, r, eps):
        return asr(l, r, eps, simpson(l, r), 12)
    ```

<span id="bài-tập"></span>
## Bài tập

-   [Luogu4525【Mẫu】Phương pháp Simpson thích nghi 1](https://www.luogu.com.cn/problem/P4525)
-   [HDU1724 Ellipse](https://acm.hdu.edu.cn/showproblem.php?pid=1724)
-   [NOI2005 Cây chanh dưới trăng](https://www.luogu.com.cn/problem/P4207)

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

<https://doi.org/10.1145/321526.321537>: bài viết này thảo luận về các cải tiến của phương pháp Simpson thích nghi, trong đó trình bày chi tiết nguồn gốc và ưu điểm của hằng số `15` trong đoạn mã ở trên.
