author: Marcythm, iamtwz, nutshellfool, sshwy, allenanswerzq, countercurrent-time, Enter-tainer, H-J-Granger, hly1204, Ir1d, Menci, NachtgeistW, SukkaW, Tiphereth-A, Xeonacid

<span id="dẫn-nhập"></span>
## Dẫn nhập

Bài viết này giới thiệu cách dùng phương pháp Newton (Newton's method for finding roots) để tìm nghiệm xấp xỉ của phương trình. Phương pháp này được Newton đề xuất vào thế kỷ 17.

Nhiệm vụ cụ thể là: với hàm $f(x)$ liên tục và đơn điệu trên $[a,b]$, tìm nghiệm xấp xỉ của phương trình $f(x)=0$.

<span id="giải-thích"></span>
## Giải thích

Ban đầu, xuất phát từ hàm $f(x)$ đã cho và một nghiệm xấp xỉ $x_0$; vấn đề chọn giá trị ban đầu liên quan đến fractal Newton, có thể tham khảo video [Newton fractal](https://www.bilibili.com/video/BV1HQ4y1q78v) của 3Blue1Brown.

Giả sử nghiệm xấp xỉ hiện tại là $x_i$. Vẽ đường thẳng $l$ tiếp xúc với $f(x)$ tại điểm $(x_i,f(x_i))$, rồi ký hiệu hoành độ giao điểm của $l$ với trục $x$ là $x_{i+1}$. Đây sẽ là một nghiệm xấp xỉ tốt hơn. Quá trình này được lặp lại.
Theo ý nghĩa hình học của đạo hàm, có quan hệ sau:

$$
 f'(x_i) = \frac{f(x_i)}{x_{i} - x_{i+1}}
$$

Biến đổi lại, thu được công thức truy hồi

$$
 x_{i+1} = x_i - \frac{f(x_i)}{f'(x_i)}
$$

Trực quan mà nói, nếu $f(x)$ tương đối trơn, thì khi số lần lặp tăng lên, $x_i$ sẽ ngày càng tiến gần nghiệm của phương trình.

Phương pháp Newton có tốc độ hội tụ bậc hai, nghĩa là sau mỗi lần lặp, số chữ số chính xác của nghiệm xấp xỉ sẽ tăng gấp đôi.
Chứng minh tính hội tụ của phương pháp Newton có thể tham khảo [citizendium - Newton method Convergence analysis](http://en.citizendium.org/wiki/Newton%27s_method#Convergence_analysis).

Phương pháp Newton cũng có nhược điểm; xem phân tích ở trang 18-20 trong [Xiaolin Wu - Roots of Equations](https://www.ece.mcmaster.ca/~xwu/part2.pdf).

<span id="tìm-căn-bậc-hai"></span>
## Tìm căn bậc hai

Thử dùng phương pháp Newton để tính căn bậc hai. Đặt $f(x)=x^2-n$, nghiệm xấp xỉ của phương trình này chính là giá trị xấp xỉ của $\sqrt{n}$. Từ đó có

$$
x_{i+1}=x_i-\frac{x_i^2-n}{2x_i}=\frac{x_i+\frac{n}{x_i}}{2}
$$

Khi cài đặt, cần đặt độ chính xác phù hợp. Mã như sau:

<span id="cài-đặt"></span>
### Cài đặt

=== "C++"
    ```cpp
    double sqrt_newton(double n) {
      constexpr static double eps = 1E-15;
      double x = 1;
      while (true) {
        double nx = (x + n / x) / 2;
        if (abs(x - nx) < eps) break;
        x = nx;
      }
      return x;
    }
    ```

=== "Python"
    ```python
    def sqrt_newton(n):
        eps = 1e-15
        x = 1
        while True:
            nx = (x + n / x) / 2
            if abs(x - nx) < eps:
                break
            x = nx
        return x
    ```

<span id="tìm-căn-bậc-hai-nguyên"></span>
## Tìm căn bậc hai nguyên

Dù có thể gọi hàm `sqrt()` để lấy giá trị căn bậc hai, phần này vẫn trình bày một biến thể của phương pháp Newton dùng để tìm nghiệm nguyên lớn nhất của bất đẳng thức $x^2\le n$. Vẫn xét một quá trình tương tự lặp Newton, nhưng cần điều chỉnh nhẹ ở điều kiện biên. Nếu trong quá trình lặp, lần lặp trước làm nghiệm xấp xỉ giảm, còn lần lặp này lại làm nghiệm xấp xỉ tăng, thì không thực hiện lần lặp này nữa và thoát vòng lặp.

<span id="cài-đặt_1"></span>
### Cài đặt

=== "C++"
    ```cpp
    int isqrt_newton(int n) {
      int x = 1;
      bool decreased = false;
      for (;;) {
        int nx = (x + n / x) >> 1;
        if (x == nx || (nx > x && decreased)) break;
        decreased = nx < x;
        x = nx;
      }
      return x;
    }
    ```

=== "Python"
    ```python
    def isqrt_newton(n):
        x = 1
        decreased = False
        while True:
            nx = (x + n // x) // 2
            if x == nx or (nx > x and decreased):
                break
            decreased = nx < x
            x = nx
        return x
    ```

<span id="căn-bậc-hai-độ-chính-xác-cao"></span>
## Căn bậc hai độ chính xác cao

Cuối cùng, xét phương pháp Newton độ chính xác cao. Cách lặp không đổi, nhưng lần này cần quan tâm đến cách đặt nghiệm xấp xỉ ban đầu, tức giá trị $x_0$. Vì các số cần tính với độ chính xác cao thường rất lớn, giá trị ban đầu khác nhau có ảnh hưởng lớn đến hiệu quả thuật toán. Một ý tưởng tự nhiên là xét $x_0=2^{\left\lfloor\frac{1}{2}\log_2n\right\rfloor}$; giá trị này vừa tính được nhanh, vừa khá gần nghiệm xấp xỉ của căn bậc hai.

<span id="cài-đặt_2"></span>
### Cài đặt

Dưới đây là cài đặt bằng Java:

```java
public static BigInteger isqrtNewton(BigInteger n) {
  BigInteger a = BigInteger.ONE.shiftLeft(n.bitLength() / 2);
  boolean p_dec = false;
  for (;;) {
    BigInteger b = n.divide(a).add(a).shiftRight(1);
    if (a.compareTo(b) == 0 || a.compareTo(b) < 0 && p_dec)
      break;
    p_dec = a.compareTo(b) > 0;
    a = b;
  }
  return a;
}
```

Hiệu quả thực tế: khi $n=10^{1000}$, thời gian chạy của thuật toán là 60 ms. Nếu không tối ưu giá trị $x_0$ mà bắt đầu lặp trực tiếp từ $x_0=1$, thời gian chạy sẽ tăng lên 120 ms.

<span id="bài-tập"></span>
## Bài tập

-   [UVa 10428 - The Roots](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1369)
-   [LeetCode 69. Căn bậc hai của x](https://leetcode-cn.com/problems/sqrtx/)

    **Trang này chủ yếu được dịch từ bài viết [Метод Ньютона (касательных) для поиска корней](http://e-maxx.ru/algo/roots_newton) và bản dịch tiếng Anh [Newton's method for finding roots](https://cp-algorithms.com/num_methods/roots_newton.html). Bản tiếng Nga có giấy phép Public Domain + Leave a Link; bản tiếng Anh có giấy phép CC-BY-SA 4.0.**
