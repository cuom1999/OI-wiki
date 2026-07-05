<span id="mở-đầu"></span>
## Mở đầu

Cho một số nguyên dương $N \in \mathbf{N}_{+}$, hãy nhanh chóng tìm một [ước không tầm thường](basic.md) của nó.

Xét thuật toán đơn giản: các ước xuất hiện theo từng cặp, nên mọi ước của $N$ có thể chia thành hai phần, tức $[2, \sqrt N]$ và $[\sqrt N+1,N)$. Chỉ cần duyệt các số trong $[2, \sqrt N]$, rồi dùng phép chia là có thể tìm được ít nhất hai ước. Cách này có độ phức tạp thời gian $O(\sqrt N)$.

Khi $N\ge10^{18}$, thời gian chạy của thuật toán này là không chấp nhận được, nên ta cần một thuật toán tốt hơn. Một ý tưởng là dùng phương pháp ngẫu nhiên để đoán xem một số có phải là ước của $N$ hay không. Nếu may mắn, ta có thể tìm được đáp án trong $O(1)$, nhưng với dữ liệu $N\ge10^{18}$, xác suất đoán trúng chỉ là $\frac{1}{10^{18}}$, nên số lần đoán kỳ vọng là $10^{18}$. Nếu chỉ đoán trong $[2,\sqrt N]$ thì xác suất thành công lớn hơn một chút. Ta muốn có cách tối ưu hóa quá trình đoán này.

<span id="thuật-toán-đơn-giản"></span>
## Thuật toán đơn giản

Thuật toán đơn giản nhất là duyệt trong khoảng $[2, \sqrt N]$.

=== "C++"
    ```cpp
    vector<int> breakdown(int N) {
      vector<int> result;
      for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {  // Nếu i chia hết N, i là một thừa số nguyên tố của N.
          while (N % i == 0) N /= i;
          result.push_back(i);
        }
      }
      if (N != 1) {  // Sau các bước trên, phần còn lại của N là một số nguyên tố.
        result.push_back(N);
      }
      return result;
    }
    ```

=== "Python"
    ```python
    def breakdown(N):
        result = []
        for i in range(2, int(sqrt(N)) + 1):
            if N % i == 0:  # Nếu i chia hết N, i là một thừa số nguyên tố của N.
                while N % i == 0:
                    N //= i
                result.append(i)
        if N != 1:  # Sau các bước trên, phần còn lại của N là một số nguyên tố.
            result.append(N)
        return result
    ```

Ta có thể chứng minh rằng mọi phần tử trong `result` chính là toàn bộ các thừa số nguyên tố của `N`.

??? note "Chứng minh rằng `result` chứa toàn bộ thừa số nguyên tố của $N$"
    Trước hết xét sự thay đổi của `N`. Khi vòng lặp kết thúc tại `i`, vì vừa thực hiện xong đoạn `while(N % i == 0) N /= i`, nên `i` không còn chia hết `N`. Hơn nữa, mỗi lần loại bỏ một thừa số đều bảo đảm `N` vẫn là ước của $N$ ban đầu. Hai điểm này bảo đảm rằng khi vòng lặp bắt đầu tại `i`, `N` là một ước của $N$ ban đầu và không chia hết cho bất kỳ số nguyên nào nhỏ hơn `i`.

    Tiếp theo, chứng minh các phần tử trong `result` đều là ước của $N$ ban đầu. Khi vòng lặp đang xét `i`, điều kiện để đưa `i` vào `result` là `N % i == 0`; điều này cho thấy `i` chia hết `N` hiện tại. Do đã biết `N` hiện tại là ước của $N$ ban đầu, suy ra `i` là ước của $N$ ban đầu. Khi vòng lặp trên `i` kết thúc, nếu `N` khác một thì cũng đưa `N` vào `result`; theo lập luận phía trên, giá trị này cũng là một ước của $N$ ban đầu.

    Tiếp theo, chứng minh mọi phần tử trong `result` đều là số nguyên tố. Giả sử tồn tại một hợp số $K$ trong `result`; khi đó phải có một `i` không vượt quá $\sqrt K$ sao cho `i` là một ước của `K`. Một $K$ như vậy không thể được đưa vào `result` dưới dạng một giá trị `i` trong vòng lặp, vì đoạn đầu đã cho thấy khi vòng lặp đến $K$, `N` không chia hết cho bất kỳ `i` nào nhỏ hơn $K$. $K$ cũng không thể được thêm sau khi vòng lặp kết thúc, vì điều kiện thoát vòng lặp là `i * i > N`, tức là đã duyệt hết mọi `i` không vượt quá $\sqrt K$; theo lập luận trên, các `i` này chắc chắn không thể chia hết `N` hiện tại, tức $K$.

    Cuối cùng, chứng minh mọi thừa số nguyên tố của $N$ ban đầu chắc chắn xuất hiện trong `result`. Giả sử $p$ là một thừa số nguyên tố của $N$ ban đầu nhưng không xuất hiện trong `result`. Theo các lập luận phía trên, $p$ không thể là một `i` đã xuất hiện trong vòng lặp. Gọi `i` là giá trị cuối cùng trước khi thoát vòng lặp, khi đó `i` nhỏ hơn hẳn $p$, và `N` sau khi thoát vòng lặp không chia hết cho các `i` trước đó, nên $p$ chia hết `N`. Vì vậy `N` cuối cùng lớn hơn một; theo phần trên nó phải là số nguyên tố, tức `N` bằng $p$, và chắc chắn sẽ được thêm vào `result`, mâu thuẫn với giả thiết.

Cần lưu ý rằng nếu đã có sẵn bảng số nguyên tố, độ phức tạp thời gian sẽ giảm từ $O(\sqrt N)$ xuống $O(\frac {\sqrt{N}} {\ln N})$. Xem thêm thông tin về cách lập bảng tại [sàng](./sieve.md).

Bài tập ví dụ: [CF 1445C](https://codeforces.com/problemset/problem/1445/C)

<span id="thuật-toán-pollard-rho"></span>
## Thuật toán Pollard Rho

<span id="mở-đầu-pollard-rho"></span>
### Mở đầu

Dùng thuật toán vét cạn để tìm một ước không tầm thường có độ phức tạp $O(p)=O(\sqrt N)$, trong đó $p$ là thừa số nguyên tố nhỏ nhất của $N$. Thuật toán Pollard-Rho được giới thiệu dưới đây là một thuật toán ngẫu nhiên hóa, có thể tìm được một ước không tầm thường trong độ phức tạp kỳ vọng $O(\sqrt p)=O(N^{1/4})$ (**chú ý**: ước không tầm thường không nhất thiết là thừa số nguyên tố).

Ý tưởng cốt lõi là: với một ánh xạ tự thân ngẫu nhiên $f: \mathbb Z_p \rightarrow \mathbb Z_p$, xuất phát từ một điểm bất kỳ $x_1$ và lặp $x_n = f(x_{n-1})$, dãy sẽ đi vào chu trình trong thời gian kỳ vọng $O(\sqrt p)$. Nếu có thể tìm được $x_i \equiv x_j \pmod p$, thì $p$ chia hết $\gcd(|x_i-x_j|, N)$, và ước chung lớn nhất này là một ước không tầm thường của $N$.

Để hiểu vì sao thời gian kỳ vọng để đi vào chu trình là $O(\sqrt p)$, có thể lấy cảm hứng từ nghịch lý ngày sinh.

<span id="nghịch-lý-ngày-sinh"></span>
### Nghịch lý ngày sinh

Bỏ qua năm sinh (giả sử mỗi năm có 365 ngày), hỏi: trong một căn phòng cần ít nhất bao nhiêu người để xác suất có hai người cùng ngày sinh đạt $50\%$?

Lời giải: giả sử một năm có $n$ ngày, trong phòng có $k$ người, đánh số những người này bằng các số nguyên $1, 2,\dots, k$. Giả định ngày sinh của mỗi người phân bố đều trên $n$ ngày và ngày sinh của hai người bất kỳ độc lập với nhau.

Gọi $A$ là sự kiện $k$ người có ngày sinh đôi một khác nhau. Khi đó xác suất của sự kiện $A$ là

$$
P(A)=\prod_{i=0}^{k-1}\frac{n-i}{n}
$$

Xác suất có ít nhất hai người cùng ngày sinh là $P(\overline A)=1-P(A)$. Theo yêu cầu đề bài, $P(\overline A)\ge\frac{1}{2}$, nên ta có

$$
P(A)=\prod_{i=0}^{k-1}\frac{n-i}{n} \le \frac{1}{2}
$$

Từ bất đẳng thức $1+x\le \mathrm{e}^x$, suy ra

$$
P(A) \le \prod_{i=1}^{k-1}\exp\left({-\frac{i}{n}}\right)=\exp \left({-\frac{k(k-1)}{2n}}\right)
$$

Do đó

$$
\exp\left({-\dfrac{k(k-1)}{2n}}\right) \le \frac{1}{2}\implies P(A) \le \frac{1}{2}
$$

Thay $n=365$, ta giải được $k\geq 23$. Vì vậy, chỉ cần ít nhất $23$ người trong một căn phòng là xác suất có hai người cùng ngày sinh đã đạt $50\%$; sự thật toán học này khá trái trực giác, nên được gọi là một nghịch lý.

Khi $k>56$ và $n=365$, xác suất có hai người sinh cùng ngày sẽ lớn hơn $99\%$[^ref1]. Nói chung, khi một năm có $n$ ngày, nếu trong phòng có $\frac{1}{2}(\sqrt{8n\ln 2+1}+1)\approx \sqrt{2n\ln 2}$ người thì xác suất có ít nhất hai người cùng ngày sinh xấp xỉ $50\%$.

Tương tự, ta có thể tính rằng nếu chọn ngẫu nhiên đều một dãy ngày sinh, số người kỳ vọng cần chọn để lần đầu gặp một ngày sinh bị lặp cũng là $O(\sqrt n)$. Gọi số người đó là $X$, ta có

$$
E(X) = \sum_{x=1}^{n+1}P(X\ge x+1) = \sum_{x=0}^n\frac{n!}{(n-x)!n^x} = \sqrt{\frac{\pi n}{2}}-\frac13+o(1).
$$

Điều này gợi ý rằng nếu có thể chọn ngẫu nhiên một dãy số, kích thước mẫu kỳ vọng để xuất hiện số bị lặp cũng là $O(\sqrt n)$.

<span id="dùng-ước-chung-lớn-nhất-để-tìm-một-ước"></span>
### Dùng ước chung lớn nhất để tìm một ước

Việc thật sự xây dựng một dãy số ngẫu nhiên modulo $p$ là không thực tế, vì $p$ chính là thứ cần tìm. Vì vậy, ta dùng $f(x)=(x^2+c)\bmod N$ để sinh một dãy giả ngẫu nhiên $\{x_i\}$: chọn ngẫu nhiên một $x_1$, đặt $x_2=f(x_1),\ x_3=f(x_2),\ \dots,\ x_i=f(x_{i-1})$, trong đó $c\in[1,N)$ là một hằng số được chọn ngẫu nhiên.

Hàm được chọn ở đây dễ tính và thường sinh ra dãy khá ngẫu nhiên, nhưng nó không hoàn toàn ngẫu nhiên. Ví dụ, đặt $n=50,\ c=6,\ x_1=1$, dữ liệu do $f(x)$ sinh ra là

$$
1, 7, 5, 31, 17, 45, 31, 17, 45, 31,\dots
$$

Có thể thấy từ sau $x_4$, dãy chỉ tuần hoàn giữa $31,17,45$. Nếu sắp các số này như hình dưới, ta sẽ thấy hình dạng rất giống chữ $\rho$, và đó cũng là nguồn gốc tên gọi rho của thuật toán.

![Dãy giả ngẫu nhiên có chu trình trong thuật toán Pollard Rho](./images/pollard-rho.svg)

Quan trọng hơn, hàm như vậy đúng là cung cấp một ánh xạ tự thân trên $\mathbb Z_p$. Nói cách khác, nó thỏa mãn tính chất: nếu $x\equiv y\pmod p$ thì $f(x)\equiv f(y)\pmod p$.

???+ note "Chứng minh"
    Nếu $x\equiv y\pmod p$, thì $x^2+c\equiv y^2+c\pmod p$. Chú ý rằng $f(x)=x^2+c-k_xN$, trong đó $k_x$ là một số nguyên phụ thuộc vào $x$, và $p|N$, nên $f(x)=x^2+c\pmod p$. Vì vậy $f(x)=f(y)\pmod p$.

Dãy thu được bằng cách lặp ánh xạ tự thân giả ngẫu nhiên trên $\mathbb Z_p$, tức $\{x_n\bmod p\}$, sẽ xuất hiện giá trị lặp trong thời gian kỳ vọng $O(\sqrt p)$. Chỉ cần quan sát được một lần lặp như vậy $x_i\equiv x_j\pmod p$, ta có thể tìm một ước không tầm thường của $N$ bằng $\gcd(|x_i-x_j|,N)$. Lưu ý rằng vì $p$ chưa biết, ta không thể trực tiếp kiểm tra việc lặp có xảy ra hay không; một cách kiểm tra đơn giản chính là xem $\gcd(|x_i-x_j|,N)$ có lớn hơn một hay không.

Thuật toán này không phải lúc nào cũng thành công, vì $\gcd(|x_i-x_j|,N)$ có thể bằng $N$. Nói cách khác, $x_i\equiv x_j\pmod N$. Khi đó, đúng vào thời điểm $\{x_n\bmod p\}$ lần đầu bị lặp, bản thân $\{x_n\}$ cũng bị lặp. Ta không thu được một ước không tầm thường. Hơn nữa, sau khi $\{x_n\}$ bắt đầu tuần hoàn, tiếp tục lặp cũng không còn ý nghĩa vì sau đó chỉ lặp lại chu trình này. Thuật toán nên trả về việc phân tích thất bại; khi đó cần thay hằng số ngẫu nhiên $c$ trong $f(x)$ rồi phân tích lại.

Theo phân tích trên, về mặt lý thuyết, mọi hàm $f(x)$ thỏa mãn $\forall x \equiv y \pmod p, f(x) \equiv f(y) \pmod p$ và bảo đảm được một mức giả ngẫu nhiên nhất định (ví dụ một số hàm đa thức) đều có thể dùng ở đây. Trong thực tế, ta chủ yếu dùng $f(x)=x^2+c\ (c\neq 0,-2)$.[^pseudo]

<span id="cài-đặt"></span>
### Cài đặt

Thuật toán cần cài đặt phải nhanh chóng phát hiện trong quá trình lặp xem $\{x_n\bmod p\}$ đã xuất hiện giá trị lặp hay chưa. Nếu xem $f$ là các cạnh trên đồ thị có hướng với tập đỉnh $\mathbb Z_p$, việc ta cần làm thực chất là phát hiện chu trình. Khác biệt là phép kiểm tra bằng nhau được thay bằng kiểm tra liệu $\gcd(|x_i-x_j|,N)$ có lớn hơn một hay không.

<span id="phát-hiện-chu-trình-bằng-floyd"></span>
#### Phát hiện chu trình bằng Floyd

Giả sử có hai người đang chạy đua, A chạy nhanh còn B chạy chậm. Sau một khoảng thời gian, A chắc chắn sẽ gặp B, và tại thời điểm gặp nhau, hiệu giữa tổng quãng đường A đã chạy và tổng quãng đường B đã chạy chắc chắn là bội của độ dài vòng.

Đặt $a=f(0),b=f(f(0))$. Mỗi lần cập nhật $a=f(a),b=f(f(b))$, chỉ cần kiểm tra trong quá trình cập nhật xem $a$ và $b$ có bằng nhau hay không; nếu bằng nhau thì đã xuất hiện chu trình.

Mỗi lần ta đặt $d=\gcd(|x_i-x_j|,N)$ và kiểm tra liệu $d$ có thỏa $1< d< N$ hay không. Nếu có, có thể trả về ngay $d$. Nếu $d=N$, điều đó cho thấy $\{x_i\}$ đã tạo thành chu trình; khi chu trình đã hình thành thì không thể tiếp tục thao tác có ích, nên trả về chính $N$, rồi trong bước sau điều chỉnh hằng số ngẫu nhiên $c$ và phân tích lại.

??? note "Thuật toán Pollard-Rho dựa trên phát hiện chu trình Floyd"
    === "C++"
        ```cpp
        ll Pollard_Rho(ll N) {
          if (N == 4) return 2;  // Vì ban đầu nhảy hai bước, cần xử lý riêng 4.
          ll c = rand() % (N - 1) + 1;
          ll t = f(0, c, N);
          ll r = f(f(0, c, N), c, N);
          while (t != r) {
            ll d = gcd(abs(t - r), N);
            if (d > 1) return d;
            t = f(t, c, N);
            r = f(f(r, c, N), c, N);
          }
          return N;
        }
        ```

    === "Python"
        ```python
        import random


        def Pollard_Rho(N):
            if N == 4:
                return 2  # Vì ban đầu nhảy hai bước, cần xử lý riêng 4.
            c = random.randint(1, N - 1)
            t = f(0, c, N)
            r = f(f(0, c, N), c, N)
            while t != r:
                d = gcd(abs(t - r), N)
                if d > 1:
                    return d
                t = f(t, c, N)
                r = f(f(r, c, N), c, N)
            return N
        ```

<span id="phát-hiện-chu-trình-bằng-brent"></span>
#### Phát hiện chu trình bằng Brent

Thực ra, thuật toán phát hiện chu trình Floyd có thể được cải thiện về hằng số. Phát hiện chu trình Brent bắt đầu với $k=1$ rồi tăng dần $k$; ở vòng thứ $k$, để A đứng yên, cho B đi tiếp $2^k$ bước. Nếu trong quá trình đó B gặp A thì đã tìm được chu trình; nếu không, cho A nhảy đến vị trí của B rồi tiếp tục vòng tiếp theo.

Có thể chứng minh[^brent] rằng số lần gọi $f$ trước khi tìm được chu trình theo cách này luôn không lớn hơn thuật toán Floyd. Thử nghiệm trong bài báo gốc cho thấy thời gian trung bình của Brent giảm $24\%$ so với Floyd.

<span id="tối-ưu-nhân-đôi"></span>
#### Tối ưu nhân đôi

Dù dùng Floyd hay Brent để phát hiện chu trình, số lần lặp đều là $O(\sqrt p)$. Tuy nhiên, nếu mỗi lần lặp đều dùng $\gcd$ để kiểm tra chu trình thì thuật toán sẽ chậm đi. Có thể dùng phép tích lũy bằng nhân để giảm số lần tính $\gcd$.

Nói đơn giản, nếu $\gcd(a,N)>1$ thì $\gcd(ab\bmod N,N)=\gcd(ab,N)>1$ đúng với mọi $b\in\mathbb N_+$. Nghĩa là nếu tính được $\gcd(\prod |x_i-x_j| \bmod N,N)>1$, thì chắc chắn tồn tại một cặp $(x_i,x_j)$ thỏa $\gcd(|x_i-x_j|,N)>1$. Nếu tích này tại một thời điểm nào đó bằng không, phép phân tích thất bại; thoát ra và trả về chính $N$.

Nếu cứ mỗi $k$ cặp mới tính $\gcd$ một lần, độ phức tạp của thuật toán giảm xuống $O(\sqrt p+k^{-1}\sqrt p\log N)$, trong đó $\log N$ là chi phí của một lần tính $\gcd$. Lưu ý rằng khi $k$ cùng bậc với $\log N$, ta có thể đạt độ phức tạp kỳ vọng $O(\sqrt p)$. Trong cài đặt cụ thể, thường chọn $k=128$.

Dưới đây là cài đặt Pollard-Rho dùng phát hiện chu trình Brent kèm tối ưu nhân đôi.

??? note "Cài đặt"
    === "C++"
        ```cpp
        ll Pollard_Rho(ll x) {
          ll t = 0;
          ll c = rand() % (x - 1) + 1;
          ll s = t;
          int step = 0, goal = 1;
          ll val = 1;
          for (goal = 1;; goal <<= 1, s = t, val = 1) {
            for (step = 1; step <= goal; ++step) {
              t = f(t, c, x);
              val = val * abs(t - s) % x;
              // Nếu val bằng 0, thoát ra để phân tích lại.
              if (!val) return x;
              if (step % 127 == 0) {
                ll d = gcd(val, x);
                if (d > 1) return d;
              }
            }
            ll d = gcd(val, x);
            if (d > 1) return d;
          }
        }
        ```

    === "Python"
        ```python
        from random import randint
        from math import gcd


        def Pollard_Rho(x):
            c = randint(1, x - 1)
            s = t = f(0, c, x)
            goal = val = 1
            while True:
                for step in range(1, goal + 1):
                    t = f(t, c, x)
                    val = val * abs(t - s) % x
                    if val == 0:
                        return x  # Nếu val bằng 0, thoát ra để phân tích lại.
                    if step % 127 == 0:
                        d = gcd(val, x)
                        if d > 1:
                            return d
                d = gcd(val, x)
                if d > 1:
                    return d
                s = t
                goal <<= 1
                val = 1
        ```

<span id="độ-phức-tạp"></span>
#### Độ phức tạp

Số lần lặp kỳ vọng trong thuật toán Pollard-Rho là $O(\sqrt p)$, trong đó $p$ là thừa số nguyên tố nhỏ nhất của $N$. Trong cài đặt cụ thể, dù dùng Floyd hay Brent để phát hiện chu trình, nếu không dùng tối ưu nhân đôi thì độ phức tạp kỳ vọng đều là $O(\sqrt p\log N)$; sau khi thêm tối ưu nhân đôi, có thể xấp xỉ đạt độ phức tạp kỳ vọng $O(\sqrt p)$.

Cần nói thêm rằng phân tích phía trên dựa trên hàm ánh xạ tự thân hoàn toàn ngẫu nhiên, trong khi thuật toán Pollard-Rho thực tế dùng hàm giả ngẫu nhiên. Vì vậy thuật toán này không có phân tích độ phức tạp chặt chẽ, nhưng trong thực tế thường chạy nhanh.

<span id="bài-tập-ví-dụ-tìm-thừa-số-nguyên-tố-lớn-nhất-của-một-số"></span>
#### Bài tập ví dụ: tìm thừa số nguyên tố lớn nhất của một số

Bài tập ví dụ: [P4718 - Mẫu thuật toán Pollard-Rho](https://www.luogu.com.cn/problem/P4718)

Với một số $n$, dùng [thuật toán Miller Rabin](./prime.md#kiểm-tra-tính-nguyên-tố-miller-rabin) để kiểm tra nó có phải số nguyên tố hay không. Nếu có thì có thể trả về trực tiếp; nếu không, dùng thuật toán Pollard-Rho để tìm một thừa số $p$, rồi chia $n$ cho thừa số $p$. Sau đó tiếp tục phân tích đệ quy $n$ và $p$, dùng Miller Rabin để nhận biết các thừa số nguyên tố xuất hiện, và cập nhật `max_factor` để tìm thừa số nguyên tố lớn nhất. Vì dữ liệu của bài này rất lớn, cách phát hiện chu trình Floyd là chưa đủ; ở đây ta dùng phương pháp tối ưu nhân đôi.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/pollard-rho/pollard-rho_1.cpp"
    ```

<span id="tài-liệu-tham-khảo-và-liên-kết"></span>
## Tài liệu tham khảo và liên kết

[^ref1]: <https://en.wikipedia.org/wiki/Birthday_problem#Reverse_problem>

[^pseudo]: Menezes, Alfred J.; van Oorschot, Paul C.; Vanstone, Scott A. (2001). Handbook of Applied Cryptography. Section 3.11 and 3.12.

[^brent]: Brent, R. P. (1980), An improved Monte Carlo factorization algorithm, BIT Numerical Mathematics, 20(2): 176-184, doi:10.1007/BF01933190
