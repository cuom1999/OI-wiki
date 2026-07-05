author: Chrogeek, frank-xjh, ChungZH, hsfzLZH1, Marcythm, Planet6174, partychicken, i-Yirannn

## Khoảng cách Euclid

### Không gian hai chiều

#### Định nghĩa

Khoảng cách Euclid là khoảng cách thông thường trong hình học phẳng. Trong hệ tọa độ Descartes phẳng, giả sử tọa độ của hai điểm $A,B$ lần lượt là $A(x_1,y_1),B(x_2,y_2)$, khi đó khoảng cách Euclid giữa hai điểm là:

$$
\left | AB \right | = \sqrt{\left ( x_2 - x_1 \right )^2 + \left ( y_2 - y_1 \right )^2}
$$

#### Giải thích

Ví dụ, trong hệ tọa độ Descartes phẳng, nếu có hai điểm $A(6,5),B(2,2)$, từ công thức ta dễ dàng tính được khoảng cách Euclid giữa $A$ và $B$:

$$
\left | AB \right | = \sqrt{\left ( 2 - 6 \right )^2 + \left ( 2 - 5 \right )^2} = \sqrt{4^2+3^2} = 5
$$

Ngoài ra, khoảng cách Euclid từ $P(x,y)$ đến gốc tọa độ có thể được biểu diễn bằng công thức:

$$
|P| = \sqrt{x^2+y^2}
$$

### Không gian n chiều

#### Dẫn nhập

Vậy công thức khoảng cách Euclid giữa hai điểm trong không gian ba chiều là gì? Hãy quan sát hình dưới đây.

![Khoảng cách trong không gian ba chiều](./images/distance-0.png)

Ta dễ thấy rằng trong $\triangle ADC$, $\angle ADC = 90^\circ$; trong $\triangle ACB$, $\angle ACB = 90^\circ$.

$$
\begin{aligned}
\therefore ~ |AB| &= \sqrt{|AC|^2+|BC|^2} \\
&= \sqrt{|AD|^2+|CD|^2+|BC|^2}
\end{aligned}
$$

#### Định nghĩa

Từ đó suy ra công thức khoảng cách Euclid trong không gian ba chiều là:

$$
\begin{gathered}
\left | AB \right | = \sqrt{\left ( x_2 - x_1 \right )^2 + \left ( y_2 - y_1 \right )^2 + \left ( z_2 - z_1 \right )^2} \\
|P| = \sqrt{x^2+y^2+z^2}
\end{gathered}
$$

#### Giải thích

[NOIP2017 Advanced Group Cheese](https://uoj.ac/problem/332) sử dụng kiến thức này và có thể xem là một bài ví dụ về khoảng cách Euclid.

Tương tự, ta thu được công thức khoảng cách Euclid trong không gian $n$ chiều: với $\vec A(x_{11}, x_{12}, \cdots,x_{1n}) ,~ \vec B(x_{21}, x_{22}, \cdots,x_{2n})$, ta có

$$
\begin{aligned}
\lVert\overrightarrow{AB}\rVert &= \sqrt{\left ( x_{11} - x_{21} \right )^2 + \left ( x_{12} - x_{22} \right )^2 + \cdot \cdot \cdot +\left ( x_{1n} - x_{2n} \right )^2}\\
&= \sqrt{\sum_{i = 1}^{n}(x_{1i} - x_{2i})^2}
\end{aligned}
$$

Khoảng cách Euclid rất hữu ích, nhưng cũng có nhược điểm rõ ràng. Khi tính khoảng cách Euclid giữa hai điểm nguyên, kết quả thường là số thực, nên có thể phát sinh sai số nhất định.

## Khoảng cách Manhattan

### Định nghĩa

Trong không gian hai chiều, khoảng cách Manhattan (Manhattan distance, còn gọi là khoảng cách khối phố) giữa hai điểm là tổng của trị tuyệt đối hiệu hoành độ và trị tuyệt đối hiệu tung độ. Giả sử hai điểm là $A(x_1,y_1),B(x_2,y_2)$, khoảng cách Manhattan giữa $A$ và $B$ có thể được biểu diễn bằng công thức:

$$
d(A,B) = |x_1 - x_2| + |y_1 - y_2|
$$

### Giải thích

Quan sát hình dưới đây:

![Các đường đi khác nhau có cùng khoảng cách Manhattan](./images/distance-1.png)

Giữa $A$ và $B$, đường màu vàng và đường màu cam đều biểu diễn khoảng cách Manhattan, đường màu đỏ và đường màu xanh dương biểu diễn các khoảng cách Manhattan tương đương, còn đường màu xanh lá biểu diễn khoảng cách Euclid.

Vẫn với ví dụ tương tự, trong hình dưới đây tọa độ của $A,B$ lần lượt là $A(25,20),B(10,10)$.

![Khoảng cách Manhattan](./images/distance-2.svg)

Từ công thức, ta dễ dàng tính được khoảng cách Manhattan giữa hai điểm $A,B$:

$$
d(A,B) = |20 - 10| + |25 - 10| = 10 + 15 = 25
$$

Sau khi suy diễn, ta có công thức khoảng cách Manhattan trong không gian $n$ chiều:

$$
\begin{aligned}
d(A,B) &= |x_1 - y_1| + |x_2 - y_2| + \cdot \cdot \cdot + |x_n - y_n|\\
&= \sum_{i = 1}^{n}|x_i - y_i|
\end{aligned}
$$

### Tính chất

Ngoài công thức, khoảng cách Manhattan còn có các tính chất toán học sau:

-   Tính không âm: khoảng cách Manhattan là một số không âm, tức là $d(i,j)\geq 0$.
-   Tính đồng nhất: khoảng cách Manhattan từ một điểm đến chính nó bằng $0$, tức là $d(i,i) = 0$.
-   Tính đối xứng: khoảng cách Manhattan từ $A$ đến $B$ bằng khoảng cách từ $B$ đến $A$, tức là $d(i,j) = d(j,i)$.
-   Bất đẳng thức tam giác: khoảng cách trực tiếp từ điểm $i$ đến $j$ không lớn hơn khoảng cách đi qua bất kỳ điểm nào khác $k$, tức là $d(i,j)\leq d(i,k)+d(k,j)$.

### Bài ví dụ

[P5098 "USACO04OPEN" Cave Cows 3](https://www.luogu.com.cn/problem/P5098)

Theo đề bài, với biểu thức $|x_1-x_2|+|y_1-y_2|$, ta có thể giả sử $x_1 - x_2 \geq 0$, rồi dựa vào dấu của $y_1 - y_2$ để chia thành hai trường hợp:

-   $(y_1 - y_2 \geq 0)\rightarrow |x_1-x_2|+|y_1-y_2|=x_1 + y_1 - (x_2 + y_2)$

-   $(y_1 - y_2 < 0)\rightarrow |x_1-x_2|+|y_1-y_2|=x_1 - y_1 - (x_2 - y_2)$

Chỉ cần lần lượt tìm giá trị lớn nhất và nhỏ nhất của $x+y, x-y$ là có thể suy ra đáp án.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        #include <algorithm>
        #include <cstdio>
        using namespace std;
        
        int main() {
          int n, x, y, minx = 0x7fffffff, maxx = 0, miny = 0x7fffffff, maxy = 0;
          scanf("%d", &n);
          for (int i = 1; i <= n; i++) {
            scanf("%d%d", &x, &y);
            minx = min(minx, x + y), maxx = max(maxx, x + y);
            miny = min(miny, x - y), maxy = max(maxy, x - y);
          }
          printf("%d\n", max(maxx - minx, maxy - miny));
          return 0;
        }
        ```
    
    === "Python"
        ```python
        minx = 0x7FFFFFFF
        maxx = 0
        miny = 0x7FFFFFFF
        maxy = 0
        n = int(input())
        for i in range(1, n + 1):
            x, y = map(lambda x: int(x), input().split())
            minx = min(minx, x + y)
            maxx = max(maxx, x + y)
            miny = min(miny, x - y)
            maxy = max(maxy, x - y)
        print(max(maxx - minx, maxy - miny))
        ```

Thật ra còn có cách làm thứ hai: chuyển khoảng cách Manhattan thành khoảng cách Chebyshev để giải. Phần cuối sẽ trình bày cách này.

## Khoảng cách Chebyshev

### Định nghĩa

Khoảng cách Chebyshev (Chebyshev distance) là một loại độ đo trong không gian vectơ; khoảng cách giữa hai điểm được định nghĩa là giá trị lớn nhất trong các hiệu trị tuyệt đối theo từng tọa độ của chúng.[^ref1]

Trong không gian hai chiều, khoảng cách Chebyshev giữa hai điểm là giá trị lớn nhất giữa trị tuyệt đối hiệu hoành độ và trị tuyệt đối hiệu tung độ. Giả sử hai điểm là $A(x_1,y_1),B(x_2,y_2)$, khoảng cách Chebyshev giữa $A$ và $B$ có thể được biểu diễn bằng công thức:

$$
d(A,B) = \max(|x_1 - x_2|, |y_1 - y_2|)
$$

Công thức khoảng cách Chebyshev trong không gian $n$ chiều có thể được biểu diễn là:

$$
\begin{aligned}
d(x,y) &= \max\begin{Bmatrix} |x_1 - y_1|,|x_2 - y_2|,\cdot \cdot \cdot,|x_n - y_n|\end{Bmatrix} \\
&= \max\begin{Bmatrix} |x_i - y_i|\end{Bmatrix}(i \in [1, n])\end{aligned}
$$

### Giải thích

Vẫn là ví dụ này, trong hình dưới đây tọa độ của $A,B$ lần lượt là $A(25,20),B(10,10)$.

![Khoảng cách Chebyshev](./images/distance-2.svg)

$$
d(A,B) = \max(|20 - 10|, |25 - 10|) = \max(10, 15) = 15
$$

## Chuyển đổi qua lại giữa khoảng cách Manhattan và khoảng cách Chebyshev

### Quá trình

Trước hết, ta xét việc vẽ tất cả các điểm trên hệ tọa độ Descartes phẳng có khoảng cách Manhattan đến gốc tọa độ bằng $1$.

Từ công thức, ta dễ dàng thu được phương trình $|x| + |y| = 1$.

Khai triển trị tuyệt đối, ta thu được $4$ hàm bậc nhất, lần lượt là:

$$
\begin{aligned}
&y = -x + 1 &(x \geq 0, y \geq 0) \\
&y = x + 1 &(x \leq 0, y \geq 0) \\
&y = x - 1  &(x \geq 0, y \leq 0)  \\
&y = -x - 1  &(x \leq 0, y \leq 0) \\
\end{aligned}
$$

Vẽ $4$ hàm này lên hệ tọa độ Descartes phẳng, ta được một hình vuông có cạnh dài $\sqrt{2}$ như hình dưới đây:

![Hình vuông khoảng cách Manhattan đơn vị](./images/distance-3.svg)

Mọi điểm trên biên của hình vuông đều có khoảng cách Manhattan đến gốc tọa độ bằng $1$.

Tương tự, ta xét việc vẽ tất cả các điểm trên hệ tọa độ Descartes phẳng có khoảng cách Chebyshev đến gốc tọa độ bằng $1$.

Từ công thức, ta biết $\max(|x|,|y|)=1$.

Khai triển biểu thức này, ta cũng thu được $4$ đoạn thẳng, lần lượt là:

$$
\begin{aligned}
&y = 1&(-1\leq x \leq 1) \\
&y = -1&(-1\leq x \leq 1) \\
&x = 1,&(-1\leq y \leq 1) \\
&x = -1,&(-1\leq y \leq 1) \\
\end{aligned}
$$

Vẽ chúng lên hệ tọa độ Descartes phẳng, ta được một hình vuông có cạnh dài $2$ như hình dưới đây:

![Hình vuông khoảng cách Chebyshev đơn vị](./images/distance-4.svg)

Mọi điểm trên biên của hình vuông đều có khoảng cách Chebyshev đến gốc tọa độ bằng $1$.

So sánh hai hình, ta sẽ thấy một điều thú vị:

Hai hình vuông này là các hình đồng dạng.

### Chứng minh

Vậy giữa khoảng cách Manhattan và khoảng cách Chebyshev có tồn tại mối liên hệ nào không?

Tiếp theo ta chứng minh ngắn gọn:

Giả sử $A(x_1,y_1),B(x_2,y_2)$.

Ta tách trị tuyệt đối trong khoảng cách Manhattan ra, sẽ thu được bốn giá trị. Giá trị lớn nhất trong bốn giá trị này là tổng của hai số không âm, tức là khoảng cách Manhattan. Khi đó khoảng cách Manhattan giữa hai điểm $A,B$ là:

$$
\begin{aligned}
d(A,B)&=|x_1 - x_2| + |y_1 - y_2|\\
&=\max\begin{Bmatrix} x_1 - x_2 + y_1 - y_2, x_1 - x_2 + y_2 - y_1,x_2 - x_1 + y_1 - y_2, x_2 - x_1 + y_2 - y_1\end{Bmatrix}\\
&= \max(|(x_1 + y_1) - (x_2 + y_2)|, |(x_1 - y_1) - (x_2 - y_2)|)
\end{aligned}
$$

Ta dễ thấy đây chính là khoảng cách Chebyshev giữa hai điểm $(x_1 + y_1,x_1 - y_1), (x_2 + y_2,x_2 - y_2)$.

Vì vậy, nếu biến đổi mỗi điểm $(x,y)$ thành $(x + y, x - y)$, thì khoảng cách Chebyshev trong hệ tọa độ mới bằng khoảng cách Manhattan trong hệ tọa độ ban đầu.

Tương tự, khoảng cách Chebyshev giữa hai điểm $A,B$ là:

$$
\begin{aligned}
d(A,B)&=\max\begin{Bmatrix} |x_1 - x_2|,|y_1 - y_2|\end{Bmatrix}\\
&=\max\begin{Bmatrix} \left|\dfrac{x_1 + y_1}{2}-\dfrac{x_2 + y_2}{2}\right|+\left|\dfrac{x_1 - y_1}{2}-\dfrac{x_2 - y_2}{2}\right|\end{Bmatrix}
\end{aligned}
$$

Đây chính là khoảng cách Manhattan giữa hai điểm $(\dfrac{x_1 + y_1}{2},\dfrac{x_1 - y_1}{2}), (\dfrac{x_2 + y_2}{2},\dfrac{x_2 - y_2}{2})$.

Vì vậy, nếu biến đổi mỗi điểm $(x,y)$ thành $(\dfrac{x + y}{2},\dfrac{x - y}{2})$, thì khoảng cách Manhattan trong hệ tọa độ mới bằng khoảng cách Chebyshev trong hệ tọa độ ban đầu.

### Kết luận

-   Hệ tọa độ Manhattan thu được bằng cách xoay hệ tọa độ Chebyshev $45^\circ$, rồi thu nhỏ còn một nửa.
-   Sau khi biến đổi tọa độ của một điểm $(x,y)$ thành $(x + y, x - y)$, khoảng cách Manhattan trong hệ tọa độ ban đầu bằng khoảng cách Chebyshev trong hệ tọa độ mới.
-   Sau khi biến đổi tọa độ của một điểm $(x,y)$ thành $(\dfrac{x + y}{2},\dfrac{x - y}{2})$, khoảng cách Chebyshev trong hệ tọa độ ban đầu bằng khoảng cách Manhattan trong hệ tọa độ mới.

Khi gặp bài toán yêu cầu tính khoảng cách Chebyshev hoặc khoảng cách Manhattan, ta thường có thể chuyển đổi qua lại giữa hai loại khoảng cách để giải. Hai loại khoảng cách có ưu và nhược điểm khác nhau trong từng bài toán, nên cần vận dụng linh hoạt.

### Bài ví dụ

[P4648 "IOI2007" pairs Animal Pairs](https://www.luogu.com.cn/problem/P4648) (chuyển khoảng cách Manhattan thành khoảng cách Chebyshev)

[P3964 "TJOI2013" Squirrel Party](https://www.luogu.com.cn/problem/P3964) (chuyển khoảng cách Chebyshev thành khoảng cách Manhattan)

Cuối cùng, dưới đây là cách giải thứ hai cho [P5098 "USACO04OPEN" Cave Cows 3](https://www.luogu.com.cn/problem/P5098):

Ta xét việc chuyển khoảng cách Manhattan mà bài toán yêu cầu thành khoảng cách Chebyshev, tức là biến đổi tọa độ mỗi điểm $(x,y)$ thành $(x + y, x - y)$.

Đáp án cần tìm trở thành $\max\limits_{i,j\in n}\begin{Bmatrix} \max\begin{Bmatrix} |x_i - x_j|,|y_i - y_j|\end{Bmatrix}\end{Bmatrix}$.

Để hiệu hoành độ hoặc hiệu tung độ đạt lớn nhất, chỉ cần tiền xử lý giá trị lớn nhất và nhỏ nhất của $x,y$.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        #include <algorithm>
        #include <cstdio>
        using namespace std;
        
        int main() {
          int n, x, y, a, b, minx = 0x7fffffff, maxx = 0, miny = 0x7fffffff, maxy = 0;
          scanf("%d", &n);
          for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a, &b);
            x = a + b, y = a - b;
            minx = min(minx, x), maxx = max(maxx, x);
            miny = min(miny, y), maxy = max(maxy, y);
          }
          printf("%d\n", max(maxx - minx, maxy - miny));
          return 0;
        }
        ```
    
    === "Python"
        ```python
        minx = 0x7FFFFFFF
        maxx = 0
        miny = 0x7FFFFFFF
        maxy = 0
        n = int(input())
        for i in range(1, n + 1):
            a, b = map(lambda x: int(x), input().split())
            x = a + b
            y = a - b
            minx = min(minx, x)
            maxx = max(maxx, x)
            miny = min(miny, y)
            maxy = max(maxy, y)
        print(max(maxx - minx, maxy - miny))
        ```

So sánh hai đoạn mã, ta lại thấy rằng hai ý tưởng khác nhau nhưng mã viết ra hoàn toàn tương đương. Tất nhiên, những vấn đề sâu hơn cần được tiếp tục tự nghiên cứu.

## Khoảng cách Minkowski

Ta định nghĩa khoảng cách Minkowski giữa hai điểm $X(x_1, x_2, \dots, x_n)$, $Y(y_1, y_2, \dots, y_n)$ trong không gian $n$ chiều là:

$$
D(X, Y) = \left(\sum_{i=1}^n \left\vert x_i - y_i \right\vert ^p\right)^{\frac{1}{p}}.
$$

Đặc biệt:

1.  Khi $p=1$, $D(X, Y) = \sum_{i=1}^n \left\vert x_i - y_i \right\vert$ chính là khoảng cách Manhattan.
2.  Khi $p=2$, $D(X, Y) = \left(\sum_{i=1}^n (x_i - y_i)^2\right)^{1/2}$ chính là khoảng cách Euclid.
3.  Khi $p \to \infty$, $D(X, Y) = \lim_{p \to \infty}\left(\sum_{i=1}^n \left\vert x_i - y_i \right\vert ^p\right) ^{1/p} = \max\limits_{i=1}^n \left\vert x_i - y_i \right\vert$ chính là khoảng cách Chebyshev.

Lưu ý: khi $p \ge 1$, khoảng cách Minkowski mới là một độ đo. Chứng minh chi tiết có thể xem tại [Minkowski distance - Wikipedia](https://en.wikipedia.org/wiki/Minkowski_distance).

## Tài liệu tham khảo và liên kết

1.  [A brief discussion of three common distance algorithms](https://www.luogu.com.cn/blog/xuxing/Distance-Algorithm), cảm ơn tác giả xuxing đã cho phép sử dụng.

[^ref1]: [Chebyshev distance - Wikipedia](https://en.wikipedia.org/wiki/Chebyshev_distance)
