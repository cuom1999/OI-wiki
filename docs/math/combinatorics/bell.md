Số Bell $B_n$ được đặt theo tên Eric Temple Bell, là một dãy số nguyên trong tổ hợp học. Các số đầu tiên là ([OEIS A000110](https://oeis.org/A000110)):

$$
B_0 = 1,B_1 = 1,B_2=2,B_3=5,B_4=15,B_5=52,B_6=203,\dots
$$

$B_n$ là số cách phân hoạch một tập hợp có lực lượng $n$. Một phân hoạch của tập hợp $S$ được định nghĩa là một họ các tập con khác rỗng, đôi một rời nhau của $S$, và hợp của chúng bằng $S$. Ví dụ $B_3 = 5$ vì tập hợp gồm 3 phần tử ${a, b, c}$ có 5 cách phân hoạch khác nhau:

$$
\begin{aligned}
&\{ \{a\},\{b\},\{c\}\} \\
&\{ \{a\},\{b,c\}\} \\
&\{ \{b\},\{a,c\}\} \\
&\{ \{c\},\{a,b\}\} \\
&\{ \{a,b,c\}\} \\
\end{aligned}
$$

$B_0$ bằng 1 vì tập rỗng có đúng 1 cách phân hoạch.

<span id="&#x9012;&#x63A8;&#x516C;&#x5F0F;"></span>
## Công thức truy hồi

Số Bell thỏa mãn công thức truy hồi:

$$
B_{n+1}=\sum_{k=0}^n\binom{n}{k}B_{k}
$$

Chứng minh:

$B_{n+1}$ là số phân hoạch của tập hợp có $n+1$ phần tử. Đặt tập hợp ứng với $B_n$ là $\{b_1,b_2,b_3,\dots,b_n\}$, tập hợp ứng với $B_{n+1}$ là $\{b_1,b_2,b_3,\dots,b_n,b_{n+1}\}$. Có thể xem $B_{n+1}$ được tạo ra từ $B_n$ bằng cách thêm phần tử $b_{n+1}$; xét phần tử $b_{n+1}$.

-   Nếu nó được tách thành một lớp riêng, còn lại $n$ phần tử, số phân hoạch trong trường hợp này là $\dbinom{n}{n}B_{n}$;

-   Nếu nó nằm cùng lớp với đúng 1 phần tử nào đó, còn lại $n-1$ phần tử, số phân hoạch trong trường hợp này là $\dbinom{n}{n-1}B_{n-1}$;

-   Nếu nó nằm cùng lớp với đúng 2 phần tử nào đó, còn lại $n-2$ phần tử, số phân hoạch trong trường hợp này là $\dbinom{n}{n-2}B_{n-2}$;

-   ...

Suy luận tương tự sẽ thu được công thức trên.

Mỗi số Bell là tổng của các [số Stirling loại hai](./stirling.md#%E7%AC%AC%E4%BA%8C%E7%B1%BB%E6%96%AF%E7%89%B9%E6%9E%97%E6%95%B0stirling-number) tương ứng.
Vì số Stirling loại hai đếm số cách chia một tập hợp có lực lượng $n$ thành đúng $k$ tập khác rỗng.

$$
B_{n} = \sum_{k=0}^n{n\brace k}
$$

<span id="&#x8D1D;&#x5C14;&#x4E09;&#x89D2;&#x5F62;"></span>
## Tam giác Bell

Dùng cách sau để xây dựng một ma trận tam giác (hình dạng tương tự tam giác Pascal):

-   $a_{0,0} = 1$;
-   Với $n \ge 1$, phần tử đầu tiên của hàng thứ $n$ bằng phần tử cuối của hàng trước đó, tức là $a_{n,0}=a_{n-1,n-1}$;
-   Với $m,n \ge 1$, phần tử thứ $m$ của hàng thứ $n$ bằng tổng của số bên trái nó và số ở góc trái trên, tức là $a_{n,m}=a_{n,m-1}+a_{n-1,m-1}$.

Một số hàng đầu:

$$
\begin{aligned}
& 1   \\
& 1\quad\qquad 2  \\
& 2\quad\qquad 3\quad\qquad 5  \\
& 5\quad\qquad 7\quad\qquad 10\,\,\,\qquad 15 \\
& 15\,\,\,\qquad 20\,\,\,\qquad  27\,\,\,\qquad 37\,\,\,\qquad 52  \\
& 52\,\,\,\qquad  67\,\,\,\qquad 87\,\,\,\qquad 114\qquad 151\qquad 203\\
& 203\qquad  255\qquad 322\qquad  409\qquad 523\qquad  674\qquad 877 \\  
\end{aligned}
$$

Phần tử đầu mỗi hàng là một số Bell. Có thể dùng tam giác này để tính truy hồi các số Bell.

??? note "Cài đặt tham khảo"
    === "C++"
        ```cpp
        constexpr int MAXN = 2000 + 5;
        int bell[MAXN][MAXN];
        
        void f(int n) {
          bell[0][0] = 1;
          for (int i = 1; i <= n; i++) {
            bell[i][0] = bell[i - 1][i - 1];
            for (int j = 1; j <= i; j++)
              bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
          }
        }
        ```
    
    === "Python"
        ```python
        MAXN = 2000 + 5
        bell = [[0 for i in range(MAXN + 1)] for j in range(MAXN + 1)]
        
        
        def f(n):
            bell[0][0] = 1
            for i in range(1, n + 1):
                bell[i][0] = bell[i - 1][i - 1]
                for j in range(1, i + 1):
                    bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1]
        ```

<span id="&#x6307;&#x6570;&#x751F;&#x6210;&#x51FD;&#x6570;"></span>
## Hàm sinh mũ

Xét hàm sinh mũ của số Bell và đạo hàm của nó:

$$
\begin{aligned}
\hat B(x) &= \sum_{n = 0}^{+\infty}\frac{B_n}{n!}x^n \\
&= 1 + \sum_{n = 0}^{+\infty}\frac{B_{n+1}}{(n + 1)!}x^{n + 1} \\
\hat B'(x) &= \sum_{n = 0}^{+\infty}\frac{B_{n+1}}{n!}x^{n}
\end{aligned}
$$

Từ công thức truy hồi của số Bell suy ra:

$$
\frac{B_{n+1}}{n!} = \sum_{k = 0}^{n}\frac{1}{(n-k)!}\frac{B_{k}}{k!}
$$

Đây là một công thức tích chập, nên có:

$$
\hat B'(x) = \mathrm{e}^x \hat B(x)
$$

Đây là một phương trình vi phân; giải ra:

$$
\hat B(x) = \exp\left(\mathrm{e}^x + C\right)
$$

Cuối cùng, khi $x = 0$ thì $\hat B(x) = 1$, thay vào được $C = -1$, suy ra dạng đóng của hàm sinh mũ của số Bell:

$$
\hat B(x) = \exp\left(\mathrm{e}^x - 1\right)
$$

Sau khi tiền xử lý $n$ hạng đầu của $\mathrm{e}^x - 1$, chỉ cần thực hiện một lần [exp đa thức](../poly/elementary-func.md#%E5%A4%9A%E9%A1%B9%E5%BC%8F%E5%AF%B9%E6%95%B0%E5%87%BD%E6%95%B0--%E6%8C%87%E6%95%B0%E5%87%BD%E6%95%B0) là có thể thu được $n$ số Bell đầu tiên. Nút thắt thời gian nằm ở exp đa thức, có thể đạt độ phức tạp thời gian $O(n \log n)$.

<span id="&#x53C2;&#x8003;&#x6587;&#x732E;"></span>
## Tài liệu tham khảo

<https://en.wikipedia.org/wiki/Bell_number>
