???+ warning "Nhắc nhở"
    Trang này không giới thiệu [**sắp xếp đếm**](./counting-sort.md).

Trang này giới thiệu ngắn gọn về sắp xếp cơ số.

## Định nghĩa

Sắp xếp cơ số (tiếng Anh: Radix sort) là một thuật toán sắp xếp không dựa trên so sánh, ban đầu được dùng để giải bài toán sắp xếp thẻ. Sắp xếp cơ số tách các phần tử cần sắp xếp thành $k$ khóa, rồi lần lượt sắp xếp theo từng khóa để hoàn tất việc sắp xếp tất cả phần tử.

Nếu so sánh lần lượt từ khóa thứ $1$ đến khóa thứ $k$, dạng sắp xếp cơ số đó được gọi là sắp xếp cơ số MSD (Most Significant Digit first);

Nếu so sánh lần lượt từ khóa thứ $k$ đến khóa thứ $1$, dạng sắp xếp cơ số đó được gọi là sắp xếp cơ số LSD (Least Significant Digit first).

## So sánh phần tử có k khóa

Dưới đây dùng $a_i$ để biểu thị khóa thứ $i$ của phần tử $a$.

Giả sử mỗi phần tử có $k$ khóa. Với hai phần tử $a$ và $b$, phương pháp so sánh mặc định là:

-   So sánh khóa thứ $1$ của hai phần tử, tức $a_1$ và $b_1$; nếu $a_1 < b_1$ thì $a < b$, nếu $a_1 > b_1$ thì $a > b$, nếu $a_1 = b_1$ thì chuyển sang bước tiếp theo;
-   So sánh khóa thứ $2$ của hai phần tử, tức $a_2$ và $b_2$; nếu $a_2 < b_2$ thì $a < b$, nếu $a_2 > b_2$ thì $a > b$, nếu $a_2 = b_2$ thì chuyển sang bước tiếp theo;
-   ……
-   So sánh khóa thứ $k$ của hai phần tử, tức $a_k$ và $b_k$; nếu $a_k < b_k$ thì $a < b$, nếu $a_k > b_k$ thì $a > b$, nếu $a_k = b_k$ thì $a = b$.

Ví dụ:

-   Nếu so sánh các số tự nhiên, sau khi căn các số theo hàng đơn vị và bù $0$ ở các chữ số cao còn thiếu, chữ số thứ $i$ tính từ trái sang phải có thể được xem là khóa thứ $i$;
-   Nếu so sánh xâu theo thứ tự từ điển, ký tự thứ $i$ tính từ trái sang phải của một xâu có thể được xem là khóa thứ $i$;
-   Phương pháp so sánh mặc định của `std::pair` và `std::tuple` trong C++ cũng giống như trên.

## Sắp xếp cơ số MSD

Dựa trên phương pháp so sánh phần tử có k khóa, ta có thể nghĩ như sau: trước hết so sánh khóa thứ $1$ của tất cả phần tử để xác định quan hệ lớn nhỏ tương đối giữa chúng; sau đó, với **các phần tử có cùng khóa thứ $1$**, tiếp tục so sánh khóa thứ $2$ của chúng…… cứ tiếp tục như vậy.

Vì việc so sánh diễn ra lần lượt từ khóa thứ $1$ đến khóa thứ $k$, thuật toán sắp xếp suy ra từ ý tưởng trên được gọi là sắp xếp cơ số MSD (Most Significant Digit first).

### Quy trình thuật toán

Tách các phần tử cần sắp xếp thành $k$ khóa; trước hết sắp xếp ổn định theo khóa thứ $1$, rồi với mỗi nhóm **phần tử có cùng khóa**, tiếp tục sắp xếp ổn định theo khóa thứ $2$ (thực hiện đệ quy)…… cuối cùng với mỗi nhóm **phần tử có cùng khóa**, sắp xếp ổn định theo khóa thứ $k$.

Nói chung, ta mặc định sắp xếp cơ số là ổn định, nên trong sắp xếp cơ số MSD, ta cũng chỉ xét việc dùng **thuật toán ổn định** (thường là sắp xếp đếm) để sắp xếp các khóa ở tầng bên trong.

Tính đúng đắn có thể tham khảo phần so sánh phần tử có k khóa ở trên.

### Mã tham khảo

#### Sắp xếp số tự nhiên

Dưới đây là mã C++ tham khảo dùng sắp xếp cơ số MSD dạng lặp để sắp xếp các phần tử trong phạm vi `unsigned int`. Có thể điều chỉnh giá trị $W$ và $\log_2 W$ (khuyến nghị đặt $\log_2 W$ là $2^k$ để tiện tối ưu bằng phép toán bit).

??? example "Mã tham khảo"
    ```cpp
    --8<-- "docs/basic/code/radix-sort/radix-sort_1.cpp:core"
    ```

#### Sắp xếp xâu

Dưới đây là mã C++ tham khảo dùng sắp xếp cơ số MSD dạng lặp để sắp xếp [xâu byte kết thúc bằng ký tự rỗng](https://en.cppreference.com/w/cpp/string/byte) theo thứ tự từ điển:

??? example "Mã tham khảo"
    ```cpp
    --8<-- "docs/basic/code/radix-sort/radix-sort_2.cpp:core"
    ```

Do việc so sánh hai xâu rất dễ đạt đến độ phức tạp tuyến tính $O(n)$, nên trong bài toán sắp xếp xâu, sắp xếp cơ số MSD tốt hơn phần lớn các thuật toán sắp xếp dựa trên so sánh cả về độ phức tạp thời gian lẫn thời gian chạy thực tế.

### Quan hệ với sắp xếp theo xô

Kiến thức cần biết trước: [Sắp xếp theo xô](./bucket-sort.md)

Sắp xếp theo xô cần các thuật toán sắp xếp khác để hoàn tất việc sắp xếp các phần tử bên trong từng xô. Nhưng thực ra, hoàn toàn có thể tiếp tục thực hiện sắp xếp theo xô trên mỗi xô cho đến một bước mà số phần tử trong xô $\le 1$.

Vì vậy, một cách hiểu khác về sắp xếp cơ số MSD là: sắp xếp theo xô được cài đặt bằng chính sắp xếp theo xô.

Cũng từ đó, có thể đưa ra một cách tối ưu hằng số thời gian cho sắp xếp cơ số MSD: nếu ở một bước nào đó số phần tử trong xô $\le B$ (với $B$ là một hằng số tự chọn), thì trực tiếp chạy sắp xếp chèn rồi trả về, nhằm giảm số lần đệ quy.

## Sắp xếp cơ số LSD

Sắp xếp cơ số MSD so sánh lần lượt từ khóa thứ $1$ đến khóa thứ $k$, nên cần dùng đệ quy hoặc lặp để cài đặt; hằng số thời gian vẫn khá lớn, và khi so sánh số tự nhiên thì cũng hơi bất tiện.

Nếu đảo ngược thao tác đệ quy, tức so sánh lần lượt từ khóa thứ $k$ đến khóa thứ $1$, ta thu được sắp xếp cơ số LSD (Least Significant Digit first), một thuật toán sắp xếp có thể hoàn thành mà không cần đệ quy.

### Quy trình thuật toán

Tách các phần tử cần sắp xếp thành $k$ khóa; trước hết sắp xếp ổn định theo khóa thứ $k$ của **tất cả phần tử**, rồi sắp xếp ổn định theo khóa thứ $k-1$ của **tất cả phần tử**, rồi sắp xếp ổn định theo khóa thứ $k-2$ của **tất cả phần tử**…… cuối cùng sắp xếp ổn định theo khóa thứ $1$ của **tất cả phần tử**. Như vậy ta hoàn tất việc sắp xếp ổn định toàn bộ dãy cần sắp xếp.

![Ví dụ toàn bộ quy trình của một lượt sắp xếp cơ số LSD](images/radix-sort-1.png "Ví dụ toàn bộ quy trình của một lượt sắp xếp cơ số LSD")

Sắp xếp cơ số LSD cũng cần dùng một **thuật toán ổn định** để sắp xếp các khóa ở tầng bên trong. Tương tự, thường dùng sắp xếp đếm để hoàn thành việc này.

Tính đúng đắn của sắp xếp cơ số LSD có thể tham khảo [lời giải bài 8.3-3 trong *Introduction to Algorithms* (bản thứ ba)](https://walkccc.github.io/CLRS/Chap08/8.3/#83-3), hoặc tham khảo phần giải thích dưới đây:

### Tính đúng đắn

Nhắc lại phương pháp so sánh phần tử có k khóa:

-   Nếu muốn so sánh được hai phần tử $a$ và $b$ chỉ bằng $a_1$ và $b_1$, ta cần biết trước kết luận thu được khi so sánh $a_2$ và $b_2$, để xử lý trường hợp $a_1 = b_1$;
-   Nếu muốn so sánh được hai phần tử $a$ và $b$ chỉ bằng $a_2$ và $b_2$, ta cần biết trước kết luận thu được khi so sánh $a_3$ và $b_3$, để xử lý trường hợp $a_2 = b_2$;
-   ……
-   Nếu muốn so sánh được hai phần tử $a$ và $b$ chỉ bằng $a_{k-1}$ và $b_{k-1}$, ta cần biết trước kết luận thu được khi so sánh $a_k$ và $b_k$, để xử lý trường hợp $a_{k-1} = b_{k-1}$;
-   $a_k$ và $b_k$ có thể được so sánh trực tiếp.

Bây giờ, đảo ngược thứ tự:

-   $a_k$ và $b_k$ có thể được so sánh trực tiếp;
-   Sau khi biết kết luận thu được khi so sánh $a_k$ và $b_k$, ta có thể suy ra kết luận khi so sánh $a_{k-1}$ và $b_{k-1}$;
-   ……
-   Sau khi biết kết luận thu được khi so sánh $a_2$ và $b_2$, ta có thể suy ra kết luận khi so sánh $a_1$ và $b_1$;
-   Sau khi biết kết luận thu được khi so sánh $a_1$ và $b_1$, cuối cùng ta thu được kết luận khi so sánh $a$ và $b$.

Trong quá trình này, vừa so sánh từng khóa vừa sắp xếp lại thứ tự các phần tử, ta thu được sắp xếp cơ số LSD.

### Mã giả

$$
\begin{array}{ll}
1 & \textbf{Input. } \text{An array } A \text{ consisting of }n\text{ elements, where each element has }k\text{ keys.}\\
2 & \textbf{Output. } \text{Array }A\text{ will be sorted in nondecreasing order stably.} \\
3 & \textbf{Method. }  \\
4 & \textbf{for }i\gets k\textbf{ down to }1\\
5 & \qquad\text{sort }A\text{ into nondecreasing order by the }i\text{-th key stably}
\end{array}
$$

### Mã tham khảo

Dưới đây là cách dùng sắp xếp cơ số LSD để sắp xếp phần tử có k khóa.

??? example "Mã tham khảo"
    ```cpp
    --8<-- "docs/basic/code/radix-sort/radix-sort_lsd.cpp:core"
    ```

Thực ra, để có một phép sắp xếp ổn định, không nhất thiết phải duyệt từ sau ra trước; chỉ cần thực hiện trên mảng `cnt` một thao tác tương đương với `std::exclusive_scan`.

???+ note "Bài mẫu [Luogu P1177 [Mẫu] Sắp xếp](https://www.luogu.com.cn/problem/P1177)"
    Cho $n$ số nguyên dương, hãy xuất chúng theo thứ tự tăng dần.
    
    ```cpp
    #include <algorithm>
    #include <iostream>
    #include <utility>
    
    void radix_sort(int n, int a[]) {
      int *b = new int[n];  // Không gian tạm
      int *cnt = new int[1 << 8];
      int mask = (1 << 8) - 1;
      int *x = a, *y = b;
      for (int i = 0; i < 32; i += 8) {
        for (int j = 0; j != (1 << 8); ++j) cnt[j] = 0;
        for (int j = 0; j != n; ++j) ++cnt[x[j] >> i & mask];
        for (int sum = 0, j = 0; j != (1 << 8); ++j) {
          // Tương đương std::exclusive_scan(cnt, cnt + (1 << 8), cnt, 0);
          sum += cnt[j], cnt[j] = sum - cnt[j];
        }
        for (int j = 0; j != n; ++j) y[cnt[x[j] >> i & mask]++] = x[j];
        std::swap(x, y);
      }
      delete[] cnt;
      delete[] b;
    }
    
    int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      int n;
      std::cin >> n;
      int *a = new int[n];
      for (int i = 0; i < n; ++i) std::cin >> a[i];
      radix_sort(n, a);
      for (int i = 0; i < n; ++i) std::cout << a[i] << ' ';
      delete[] a;
      return 0;
    }
    ```

## Tính chất

### Tính ổn định

Nếu phép sắp xếp theo khóa ở tầng bên trong là ổn định, thì cả sắp xếp cơ số MSD và sắp xếp cơ số LSD đều là thuật toán sắp xếp ổn định.

### Độ phức tạp thời gian

Thông thường, sắp xếp cơ số nhanh hơn các thuật toán sắp xếp dựa trên so sánh (chẳng hạn như sắp xếp nhanh). Tuy nhiên, do cần thêm bộ nhớ phụ, khi bộ nhớ khan hiếm, các thuật toán hoán vị tại chỗ (chẳng hạn như sắp xếp nhanh) có thể là lựa chọn tốt hơn.[^ref1]

Nói chung, nếu miền giá trị của mỗi khóa đều không lớn, ta có thể dùng [sắp xếp đếm](./counting-sort.md) làm thuật toán sắp xếp bên trong; khi đó độ phức tạp là $O(kn+\sum\limits_{i=1}^k w_i)$, trong đó $w_i$ là kích thước miền giá trị của khóa thứ $i$. Nếu miền giá trị của khóa rất lớn, có thể trực tiếp dùng sắp xếp dựa trên so sánh với độ phức tạp $O(nk\log n)$ mà không cần dùng sắp xếp cơ số.

### Độ phức tạp không gian

Độ phức tạp không gian của sắp xếp cơ số MSD và sắp xếp cơ số LSD đều là $O(k+n)$.

## Tài liệu tham khảo và chú thích

[^ref1]: Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein.*Introduction to Algorithms*(3rd ed.). MIT Press and McGraw-Hill, 2009. ISBN 978-0-262-03384-8. "8.3 Radix sort", pp. 199.
