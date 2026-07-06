Bài toán Josephus đã có lịch sử lâu đời, và các cách giải của nó cũng liên tục được cải tiến. Tuy vậy, hiện vẫn chưa có thuật toán cực kỳ hiệu quả, chẳng hạn dưới mức logarit, để giải bài toán này.

## Mô tả bài toán

> Có $n$ người được đánh số $0,1,\cdots, n-1$. Họ đứng thành một vòng tròn theo chiều ngược kim đồng hồ. Bắt đầu từ người số $0$, mỗi lần đếm ngược chiều kim đồng hồ $k$ người kể từ người hiện tại, rồi loại người đó khỏi vòng. Hỏi người cuối cùng còn lại là ai.

Bài toán kinh điển này được Josephus nêu ra vào thế kỷ 1 sau Công nguyên, dù khi đó ông chỉ xét trường hợp $k=2$. Hiện nay đã có nhiều thuật toán hiệu quả để giải bài toán này.

## Cách làm

### Thuật toán vét cạn

Thuật toán đơn giản nhất là mô phỏng trực tiếp. Dùng một danh sách liên kết vòng để mô phỏng quá trình xóa, lặp lại $n-1$ lần để thu được đáp án. Độ phức tạp là $\Theta (n^2)$.

### Tối ưu đơn giản

Có thể tối ưu quá trình tìm người tiếp theo bằng cây đoạn. Cụ thể, xây một cây đoạn trên các vị trí $0,1,\cdots, n-1$, rồi lưu số người còn lại trong mỗi đoạn. Khi cần tìm vị trí của người hiện tại và người thứ $k$ sau đó, có thể nhị phân trên cây đoạn.

### Thuật toán tuyến tính

Gọi $J_{n,k}$ là đáp án của bài toán Josephus với tham số $n,k$. Công thức truy hồi là:

$$
J_{n,k}=(J_{n-1,k}+k)\bmod n
$$

Công thức này cũng dễ suy ra. Bắt đầu đếm từ $0$ qua $k$ người, sau khi người thứ $k-1$ bị loại thì còn lại $n-1$ người. Nếu đã tính được đáp án trong vòng gồm $n-1$ người đó, cộng thêm độ lệch tương đối $k$ để thu được đáp án thật. Độ phức tạp của thuật toán này là $\Theta (n)$.

???+ note "Cài đặt"
    ```cpp
    int josephus(int n, int k) {
      int res = 0;
      for (int i = 1; i <= n; ++i) res = (res + k) % i;
      return res;
    }
    ```

### Thuật toán logarit

Khi $k$ nhỏ và $n$ lớn, bài toán còn có một thuật toán độ phức tạp $\Theta (k\log n)$.

Vì mỗi lần đi qua $k$ người rồi xóa một người, trong một vòng có thể xóa $\left\lfloor\frac{n}{k}\right\rfloor$ người, và còn lại $n-\left\lfloor\frac{n}{k}\right\rfloor$ người. Khi đó vị trí hiện tại là người thứ $\left\lfloor\frac{n}{k}\right\rfloor\cdot k$, tức là $n-n\bmod k$. Tiếp tục xử lý đệ quy, rồi khôi phục vị trí tương đối sau khi tính xong. Cơ sở của việc khôi phục là: mỗi lần xóa sẽ loại người thứ $k$ được đếm tới, và chỉ số của họ được những người phía sau kế thừa lần lượt. Vì vậy, khi tính trên vòng gồm $n-\left\lfloor\frac{n}{k}\right\rfloor$ người, cứ mỗi $k$ người lại có $1$ vị trí bị lệch. Nếu kết quả nhỏ hơn $0$, lấy modulo $n$ trên vòng $n$ người mà các chỉ số bội của $k$ chưa bị xóa; nếu kết quả không âm, có thể khôi phục trực tiếp bằng cách nhân với $\frac{k}{k-1}$. Từ đó thu được thuật toán sau:

???+ note "Cài đặt"
    ```cpp
    int josephus(int n, int k) {
      if (n == 1) return 0;
      if (k == 1) return n - 1;
      if (k > n) return (josephus(n - 1, k) + k) % n;  // thuật toán tuyến tính
      int res = josephus(n - n / k, k);
      res -= n % k;
      if (res < 0)
        res += n;  // mod n
      else
        res += res / (k - 1);  // khôi phục vị trí
      return res;
    }
    ```

Có thể chứng minh độ phức tạp của thuật toán này là $\Theta (k\log n)$. Gọi số lần đệ quy của quá trình là $x$. Sau mỗi lần, kích thước bài toán xấp xỉ trở thành $\displaystyle n\left(1-\frac{1}{k}\right)$, nên có

$$
n\left(1-\frac{1}{k}\right)^x=1
$$

Giải phương trình này được

$$
x=-\frac{\ln n}{\ln\left(1-\frac{1}{k}\right)}
$$

Sau đây chứng minh độ phức tạp của thuật toán là $\Theta (k\log n)$.

???+ note "Chứng minh"
    Xét $\displaystyle \lim _{k \rightarrow \infty} k \log \left(1-\frac{1}{k}\right)$, có
    
    $$
    \begin{aligned}
    \lim _{k \rightarrow \infty} k \log \left(1-\frac{1}{k}\right)&=\lim _{k \rightarrow \infty} \frac{\log \left(1-\frac{1}{k}\right)}{1 / k}\\
    &=\lim _{k \rightarrow \infty} \frac{\frac{\mathrm d}{\mathrm d k} \log \left(1-\frac{1}{k}\right)}{\frac{\mathrm d}{\mathrm d k}\left(\frac{1}{k}\right)}\\
    &=\lim _{k \rightarrow \infty} \frac{\frac{1}{k^{2}\left(1-\frac{1}{k}\right)}}{-\frac{1}{k^{2}}}\\
    &=\lim _{k \rightarrow \infty}-\frac{k}{k-1}\\
    &=-\lim _{k \rightarrow \infty} \frac{1}{1-\frac{1}{k}}\\
    &=-1
    \end{aligned}
    $$
    
    Do đó $x \sim k \ln n, k\to \infty$, tức là $-\dfrac{\ln n}{\ln\left(1-\frac{1}{k}\right)}= \Theta (k\log n)$.

**Trang này chủ yếu được dịch từ bài viết [Задача Иосифа](https://e-maxx.ru/algo/joseph_problem) và bản dịch tiếng Anh [Josephus Problem](https://cp-algorithms.com/others/josephus_problem.html). Bản tiếng Nga được cấp phép theo Public Domain + Leave a Link; bản tiếng Anh được cấp phép theo CC-BY-SA 4.0.**
