author: linehk, persdre

Độ phức tạp thời gian và độ phức tạp bộ nhớ là những tiêu chí quan trọng để đánh giá hiệu quả của một thuật toán.

## Số phép toán cơ bản

Cùng một thuật toán có thể chạy với tốc độ khác nhau trên các máy tính khác nhau. Tốc độ chạy thực tế lại khó tính bằng lý thuyết, còn việc đo trực tiếp cũng khá phiền phức, vì vậy ta thường không xét thời gian chạy thực tế của thuật toán, mà xét số phép toán cơ bản mà thuật toán cần thực hiện.

Trên một máy tính thông thường, các phép cộng, trừ, nhân, chia, truy cập biến (biến kiểu dữ liệu cơ bản, tương tự ở bên dưới), gán giá trị cho biến, v.v. đều có thể xem là phép toán cơ bản.

Việc đếm hoặc ước lượng số phép toán cơ bản có thể dùng làm chỉ số đánh giá thời gian chạy của thuật toán.

## Độ phức tạp thời gian

### Định nghĩa

Khi đánh giá một thuật toán nhanh hay chậm, ta nhất định phải xét kích thước dữ liệu. Kích thước dữ liệu thường là số lượng số trong đầu vào, số đỉnh và số cạnh của đồ thị được cho trong đầu vào, v.v. Nói chung, kích thước dữ liệu càng lớn thì thuật toán chạy càng lâu. Trong lập trình thi đấu, khi đánh giá hiệu quả của một thuật toán, điều quan trọng nhất không phải là thời gian chạy tại một kích thước dữ liệu cụ thể, mà là xu hướng thời gian chạy tăng lên khi kích thước dữ liệu tăng, tức **độ phức tạp thời gian**.

### Dẫn nhập

Các lý do chính khiến ta xét xu hướng thời gian chạy thay đổi theo kích thước dữ liệu là:

1.  Máy tính hiện đại có thể xử lý hàng trăm triệu phép toán cơ bản, thậm chí nhiều hơn, trong mỗi giây, nên kích thước dữ liệu ta xử lý thường rất lớn. Nếu thuật toán A chạy trong $100n$ trên dữ liệu kích thước $n$, còn thuật toán B chạy trong $n^2$, thì khi kích thước dữ liệu nhỏ hơn $100$, thuật toán B chạy nhanh hơn. Nhưng trong một giây, thuật toán A có thể xử lý dữ liệu cỡ hàng triệu, còn thuật toán B chỉ xử lý được dữ liệu cỡ hàng chục nghìn. Khi cho phép thuật toán chạy lâu hơn, ảnh hưởng của độ phức tạp thời gian lên kích thước dữ liệu có thể xử lý sẽ càng rõ rệt, lớn hơn rất nhiều so với ảnh hưởng của thời gian chạy ở cùng một kích thước dữ liệu.
2.  Ta dùng số phép toán cơ bản để biểu diễn thời gian chạy của thuật toán, nhưng thời gian thực tế của các phép toán cơ bản khác nhau là khác nhau; chẳng hạn phép cộng trừ nhanh hơn phép chia rất nhiều. Khi tính độ phức tạp thời gian, việc bỏ qua khác biệt giữa các phép toán cơ bản, cũng như khác biệt giữa một phép toán cơ bản và mười phép toán cơ bản, giúp loại bỏ ảnh hưởng của sự khác nhau về thời gian thực hiện giữa các phép toán cơ bản.

Dĩ nhiên, thời gian chạy của thuật toán không hoàn toàn do kích thước đầu vào quyết định, mà còn liên quan đến nội dung đầu vào. Vì vậy, độ phức tạp thời gian còn được chia thành một số loại, chẳng hạn:

1.  Độ phức tạp thời gian trong trường hợp xấu nhất, tức độ phức tạp ứng với đầu vào tốn thời gian nhất trong mỗi kích thước đầu vào. Trong lập trình thi đấu, vì đầu vào có thể là bất kỳ dữ liệu nào trong phạm vi đã cho, để bảo đảm thuật toán chạy được với mọi dữ liệu trong phạm vi đó, ta thường xét độ phức tạp thời gian trong trường hợp xấu nhất.
2.  Độ phức tạp thời gian trung bình (kỳ vọng), tức độ phức tạp của giá trị trung bình thời gian chạy trên tất cả đầu vào có thể có trong mỗi kích thước đầu vào (độ phức tạp thời gian chạy kỳ vọng với đầu vào ngẫu nhiên).

Cụm “xu hướng thời gian chạy tăng theo kích thước dữ liệu” là một khái niệm còn mơ hồ; ta cần dùng **ký hiệu tiệm cận** được giới thiệu bên dưới để biểu diễn độ phức tạp thời gian một cách hình thức.

## Định nghĩa ký hiệu tiệm cận

Ký hiệu tiệm cận là cách mô tả chuẩn cho bậc của hàm. Nói đơn giản, ký hiệu tiệm cận bỏ qua những phần tăng chậm hơn trong một hàm và các hệ số của từng hạng tử (trong phân tích độ phức tạp thời gian, hệ số thường được gọi là “hằng số”), đồng thời giữ lại những phần quan trọng thể hiện xu hướng tăng trưởng của hàm đó.

Cách nhớ đơn giản là: có dấu bằng (không nghiêm ngặt) thì dùng chữ hoa, không có dấu bằng (nghiêm ngặt) thì dùng chữ thường; bằng nhau là $\Theta$, nhỏ hơn là $O$, lớn hơn là $\Omega$. Chữ $O$ lớn và $o$ nhỏ vốn là chữ cái Hy Lạp Omicron; do hình dạng giống nhau, cũng có thể hiểu như chữ cái Latin $O$ lớn và $o$ nhỏ.

Trong tiếng Anh, các gốc từ “-micro-” và “-mega-” thường dùng để chỉ $10^{-6}$ (một phần triệu) và $10^6$ (một triệu), đồng thời cũng gợi ý nghĩa “nhỏ” và “lớn”. “Nhỏ” và “lớn” cũng là ý nghĩa thường gặp của hai chữ cái Hy Lạp Omicron và Omega.

### Ký hiệu Θ lớn

Với hai hàm $f(n)$ và $g(n)$, $f(n)=\Theta(g(n))$ khi và chỉ khi $\exists c_1,c_2,n_0>0$ sao cho $\forall n \ge n_0, 0\le c_1\cdot g(n)\le f(n) \le c_2\cdot g(n)$.

Nói cách khác, nếu $f(n)=\Theta(g(n))$, ta có thể tìm được hai số dương $c_1, c_2$ sao cho $f(n)$ bị kẹp giữa $c_1\cdot g(n)$ và $c_2\cdot g(n)$.

Ví dụ, $3n^2+5n-3=\Theta(n^2)$, trong đó $c_1, c_2, n_0$ có thể lần lượt là $2, 4, 100$. Với $n\sqrt {n} + n{\log^5 n} + m{\log m} +nm=\Theta(n\sqrt {n} + m{\log m} + nm)$, $c_1, c_2, n_0$ có thể lần lượt là $1, 2, 100$.

### Ký hiệu O lớn

Ký hiệu $\Theta$ đồng thời cho ta cận trên và cận dưới của một hàm. Nếu chỉ biết cận trên tiệm cận của một hàm mà chưa biết cận dưới tiệm cận của nó, ta có thể dùng ký hiệu $O$. $f(n)=O(g(n))$ khi và chỉ khi $\exists c,n_0$ sao cho $\forall n \ge n_0,0\le f(n)\le c\cdot g(n)$.

Khi nghiên cứu độ phức tạp thời gian, ta thường dùng ký hiệu $O$, vì điều ta quan tâm thường là cận trên của thời gian chạy chương trình, chứ không phải cận dưới của nó.

Cần chú ý rằng “cận trên” và “cận dưới” ở đây nói về xu hướng biến thiên của hàm, chứ không nói trực tiếp về thuật toán. Cận trên của thời gian chạy thuật toán tương ứng với “độ phức tạp thời gian trong trường hợp xấu nhất”, chứ không phải ký hiệu $O$ lớn. Vì vậy, dùng ký hiệu $\Theta$ để biểu diễn độ phức tạp thời gian trong trường hợp xấu nhất là hoàn toàn được; thậm chí có thể nói $\Theta$ chính xác hơn $O$. Những lý do chính khiến ta dùng ký hiệu $O$ là: thứ nhất, đôi khi ta chỉ chứng minh được cận trên của độ phức tạp thời gian mà không chứng minh được cận dưới (thường gặp trong các thuật toán và phân tích độ phức tạp phức tạp hơn); thứ hai, $O$ dễ gõ trên máy tính hơn.

### Ký hiệu Ω lớn

Tương tự, ta dùng ký hiệu $\Omega$ để mô tả cận dưới tiệm cận của một hàm. $f(n)=\Omega(g(n))$ khi và chỉ khi $\exists c,n_0$ sao cho $\forall n \ge n_0,0\le c\cdot g(n)\le f(n)$.

### Ký hiệu o nhỏ

Nếu ký hiệu $O$ tương đương với dấu nhỏ hơn hoặc bằng, thì ký hiệu $o$ tương đương với dấu nhỏ hơn.

Ký hiệu $o$ nhỏ được dùng nhiều trong giải tích toán học. Khai triển Taylor của hàm tại một điểm có phần dư Peano; ký hiệu $o$ nhỏ biểu diễn quan hệ nhỏ hơn nghiêm ngặt, từ đó phục vụ phân tích tiệm cận của các vô cùng bé tương đương.

$f(n)=o(g(n))$ khi và chỉ khi với mọi số dương $c$ cho trước, $\exists n_0$ sao cho $\forall n \ge n_0,0\le f(n)< c\cdot g(n)$.

### Ký hiệu ω nhỏ

Nếu ký hiệu $\Omega$ tương đương với dấu lớn hơn hoặc bằng, thì ký hiệu $\omega$ tương đương với dấu lớn hơn.

$f(n)=\omega(g(n))$ khi và chỉ khi với mọi số dương $c$ cho trước, $\exists n_0$ sao cho $\forall n \ge n_0,0\le c\cdot g(n)< f(n)$.

![](images/order.png)

### Các tính chất thường gặp

-   $f(n) = \Theta(g(n))\iff f(n)=O(g(n))\land f(n)=\Omega(g(n))$
-   $f_1(n) + f_2(n) = O(\max(f_1(n), f_2(n)))$
-   $f_1(n) \times f_2(n) = O(f_1(n) \times f_2(n))$
-   $\forall a \neq 1, \log_a{n} = O(\log_2 n)$. Từ công thức đổi cơ số, có thể thấy mọi hàm logarit, bất kể cơ số là gì, đều có cùng tốc độ tăng trưởng; vì vậy trong độ phức tạp thời gian tiệm cận, cơ số của logarit thường được lược bỏ.

## Ví dụ đơn giản về tính độ phức tạp thời gian

### Vòng lặp `for`

=== "C++"
    ```cpp
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < m; ++k) {
          std::cout << "hello world\n";
        }
      }
    }
    ```

=== "Python"
    ```python
    n = int(input())
    m = int(input())
    for i in range(0, n):
        for j in range(0, n):
            for k in range(0, m):
                print("hello world")
    ```

=== "Java"
    ```java
    int n, m;
    n = input.nextInt();
    m = input.nextInt();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                System.out.println("hello world");
            }
        }
    }
    ```

Nếu lấy độ lớn của các giá trị đầu vào $n$ và $m$ làm kích thước dữ liệu, độ phức tạp thời gian của đoạn mã trên là $\Theta(n^2m)$.

### DFS

Khi thực hiện [DFS](../graph/dfs.md) trên một đồ thị có $n$ đỉnh và $m$ cạnh, vì mỗi đỉnh và mỗi cạnh chỉ được thăm số lần hằng số, độ phức tạp là $\Theta(n+m)$.

## Những đại lượng nào là hằng số?

Khi cần thực hiện một số phép toán nào đó, làm sao để biết các phép toán này có ảnh hưởng đến độ phức tạp thời gian hay không? Ví dụ:

=== "C++"
    ```cpp
    constexpr int N = 100000;
    for (int i = 0; i < N; ++i) {
      std::cout << "hello world\n";
    }
    ```

=== "Python"
    ```python
    N = 100000
    for i in range(0, N):
        print("hello world")
    ```

=== "Java"
    ```java
    final int N = 100000;
    for (int i = 0; i < N; ++i) {
        System.out.println("hello world");
    }
    ```

Nếu độ lớn của $N$ không được xem là kích thước đầu vào, độ phức tạp thời gian của đoạn mã này là $O(1)$.

Khi tính độ phức tạp thời gian, việc xác định biến nào được xem là kích thước đầu vào là rất quan trọng. Mọi đại lượng không liên quan đến kích thước đầu vào đều được xem là hằng số và có thể coi là $1$ khi tính độ phức tạp.

Cần chú ý rằng trong các thảo luận lý thuyết về độ phức tạp thời gian, “thuật toán có thể giải bài toán ở mọi kích thước” là một giả định cơ bản (dĩ nhiên trong thực tế, do giới hạn thời gian và bộ nhớ, ta không thể giải các bài toán có kích thước quá lớn). Vì vậy, việc có thể giải trong thời gian hằng số một bài toán có kích thước dữ liệu hữu hạn (ví dụ, tính trước đáp án cho mọi đầu vào có thể trong phạm vi dữ liệu) không làm cho độ phức tạp thời gian của thuật toán trở thành $O(1)$.

## Định lý Master

Ta có thể dùng định lý Master để nhanh chóng tìm độ phức tạp của các thuật toán đệ quy.
Hệ thức truy hồi của định lý Master như sau

$$
T(n) = a T\left(\frac{n}{b}\right)+f(n)\qquad \forall n > b
$$

Khi đó

$$
T(n) = \begin{cases}\Theta(n^{\log_b a}) & f(n) = O(n^{\log_b (a)-\epsilon}),\epsilon > 0 \\ \Theta(f(n)) & f(n) = \Omega(n^{\log_b (a)+\epsilon}),\epsilon\ge 0\\ \Theta(n^{\log_b a}\log^{k+1} n) & f(n)=\Theta(n^{\log_b a}\log^k n),k\ge 0 \end{cases}
$$

Cần chú ý rằng trường hợp thứ hai ở đây còn phải thỏa điều kiện chính quy (regularity condition), tức $a f(n/b) \leq c f(n)$ với một hằng số $c < 1$ nào đó và $n$ đủ lớn.

Ý tưởng chứng minh là chia bài toán kích thước $n$ thành $a$ bài toán con kích thước $(\frac{n}{b})$, sau đó lần lượt gộp lại cho đến khi gộp tới tầng cao nhất. Mỗi lần gộp các bài toán con cần tốn thời gian $f(n)$.

??? note "Chứng minh"
    Dựa trên ý tưởng chứng minh đã nêu ở trên, quá trình chứng minh cụ thể như sau
    
    Ở tầng $0$ (tầng cao nhất), việc gộp các bài toán con cần tốn thời gian $f(n)$
    
    Ở tầng $1$ (các bài toán con được chia ra lần đầu), có tổng cộng $a$ bài toán con, mỗi bài toán con cần $f\left(\frac{n}{b}\right)$ thời gian để gộp, nên tổng thời gian gộp là $a f\left(\frac{n}{b}\right)$.
    
    Tiếp tục truy hồi qua từng tầng, ta có thể viết cây truy hồi như sau: ![](./images/master-theorem-proof.svg)
    
    Cây này có chiều cao ${\log_b n}$ và có tổng cộng $n^{\log_b a}$ lá, do đó $T(n) = \Theta(n^{\log_b a}) + g(n)$, trong đó $g(n) = \sum_{j = 0}^{\log_{b}{n - 1}} a^{j} f(n / b^{j})$.
    
    Với trường hợp thứ nhất: $f(n) = O(n^{\log_b a-\epsilon})$, nên $g(n) = O(n^{\log_b a})$.
    
    Với trường hợp thứ hai: trước hết $g(n) = \Omega(f(n))$; hơn nữa, vì $a f(\dfrac{n}{b}) \leq c f(n)$, miễn là $c$ là một số dương đủ nhỏ và $n$ đủ lớn, ta suy ra được $g(n) = O(f(n)$). Kẹp hai phía cho ta $g(n) = \Theta(f(n))$.
    
    Với trường hợp thứ ba: $f(n) = \Theta(n^{\log_b a})$, nên $g(n) = O(n^{\log_b a} {\log n})$. Sau khi có $g(n)$, kết quả của $T(n)$ được suy ra một cách hiển nhiên.

Dưới đây là một vài ví dụ minh họa cách dùng định lý chính.

1.  $T(n) = 2T\left(\frac{n}{2}\right) + 1$, khi đó $a=2, b=2, {\log_2 2} = 1$, và $\epsilon$ có thể nhận giá trị trong $(0, 1]$, nên thỏa trường hợp thứ nhất. Do đó $T(n) = \Theta(n)$.

2.  $T(n) = T\left(\frac{n}{2}\right) + n$, khi đó $a=1, b=2, {\log_2 1} = 0$, và $\epsilon$ có thể nhận giá trị trong $(0, 1]$, nên thỏa trường hợp thứ hai. Do đó $T(n) = \Theta(n)$.

3.  $T(n) = T\left(\frac{n}{2}\right) + {\log n}$, khi đó $a=1, b=2, {\log_2 1}=0$, và $k$ có thể nhận giá trị $1$, nên thỏa trường hợp thứ ba. Do đó $T(n) = \Theta(\log^2 n)$.

4.  $T(n) = T\left(\frac{n}{2}\right) + 1$, khi đó $a=1, b=2, {\log_2 1} = 0$, và $k$ có thể nhận giá trị $0$, nên thỏa trường hợp thứ ba. Do đó $T(n) = \Theta(\log n)$.

## Độ phức tạp khấu hao

Xem chi tiết tại [Độ phức tạp khấu hao](./amortized-analysis.md).

## Độ phức tạp bộ nhớ

Tương tự, xu hướng lượng bộ nhớ mà thuật toán sử dụng thay đổi theo kích thước đầu vào có thể được đo bằng **độ phức tạp bộ nhớ**.

## Độ phức tạp tính toán

Bài viết này chủ yếu giới thiệu độ phức tạp từ góc nhìn phân tích thuật toán. Nếu quan tâm, bạn có thể tìm hiểu sâu hơn tại [Độ phức tạp tính toán](../misc/cc-basic.md).
