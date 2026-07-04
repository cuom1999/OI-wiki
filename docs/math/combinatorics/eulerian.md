???+ warning "Lưu ý"
    Số Euler trong phần dưới đây chỉ Eulerian number. Cần phân biệt với Euler number, cũng như Euler's number, tức các hằng số toán học liên quan đến Euler như $\gamma$ hoặc $\mathrm{e}$.

Trong tổ hợp tính toán, **số Eulerian** (Eulerian Number) là **số lượng** hoán vị của các số từ $1$ đến $n$ có đúng $m$ phần tử lớn hơn phần tử đứng ngay trước nó, tức có $m$ "bước tăng". Định nghĩa:

$$
A(n, m) = 
\left\langle 
\begin{matrix}
  n\\
  m - 1
\end{matrix}
\right\rangle
$$

Ví dụ, trong các hoán vị của các số từ $1$ đến $3$, có $4$ hoán vị có đúng một phần tử lớn hơn phần tử đứng ngay trước nó:

| Hoán vị | Cặp phần tử kề nhau thỏa mãn điều kiện | Số lượng |
| ------- | --------------------------------------- | -------- |
| 1 2 3   | 1, 2 & 2, 3                             | 2        |
| 1 3 2   | 1, 3                                    | 1        |
| 2 1 3   | 1, 3                                    | 1        |
| 2 3 1   | 2, 3                                    | 1        |
| 3 1 2   | 1, 2                                    | 1        |
| 3 2 1   |                                         | 0        |

Vì vậy, theo định nghĩa $A(n, m)$: nếu $n=3$ và $m=1$, giá trị số Eulerian là $4$, biểu thị rằng có tổng cộng $4$ hoán vị có đúng $1$ phần tử lớn hơn phần tử đứng trước nó.

Với các giá trị nhỏ của $n$ và $m$, ta có thể nhận được kết quả trực tiếp:

| $A(n, m)$ | Hoán vị thỏa mãn yêu cầu                         | Số lượng |
| --------- | ------------------------------------------------ | -------- |
| $A(1, 0)$ | $(1)$                                            | 1        |
| $A(2, 0)$ | $(2, 1)$                                         | 1        |
| $A(2, 1)$ | $(1, 2)$                                         | 1        |
| $A(3, 0)$ | $(3, 2, 1)$                                      | 1        |
| $A(3, 1)$ | $(1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2)$     | 4        |
| $A(3, 2)$ | $(1, 2, 3)$                                      | 1        |

<span id="&#20844;&#24335;"></span>
## Công thức

Có thể tính số Eulerian bằng phương pháp truy hồi hoặc đệ quy.

Trước hết, khi $m \ge n$ hoặc $n = 0$, không có hoán vị nào thỏa mãn điều kiện, nên số Eulerian bằng $0$.

Tiếp theo, khi $m = 0$, chỉ có hoán vị giảm dần thỏa mãn điều kiện, nên số Eulerian bằng $1$.

Cuối cùng, xét việc chèn $n$ vào một hoán vị của $n-1$ phần tử để thu được một hoán vị của $n$ phần tử. Vì việc chèn $n$ làm số bước tăng tăng nhiều nhất $1$, nên $A(n, m)$ chỉ có thể được chuyển từ $A(n-1, m-1)$ và $A(n-1, m)$.

Xét vị trí chèn $n$: khi $p_{i-1} < p_i$, nếu chèn $n$ vào trước $p_i$, tức chèn $n$ vào một "bước tăng", thì số bước tăng của hoán vị không đổi. Ngoài ra, nếu chèn $n$ vào trước toàn bộ hoán vị, số bước tăng cũng không đổi. Ngược lại, nếu chèn $n$ vào các vị trí còn lại, số bước tăng của hoán vị tăng thêm $1$.

Xét chuyển từ $A(n-1, m-1)$ sang $A(n, m)$: lúc này cần làm số bước tăng tăng thêm $1$, nên không được chèn $n$ vào một "bước tăng" hoặc vào đầu hoán vị. Có tổng cộng $n - (m-1) - 1 = n-m$ cách.

Xét chuyển từ $A(n-1, m)$ sang $A(n, m)$: lúc này cần giữ nguyên số bước tăng, nên chỉ được chèn $n$ vào một "bước tăng" hoặc vào đầu hoán vị. Có tổng cộng $m+1$ cách.

Tóm lại:

$$
A(n, m) = \begin{cases}
    0, & m > n \text{ or } n = 0, \\
    1, & m = 0, \\
    (n-m) \cdot A(n-1, m-1) + (m+1) \cdot A(n-1, m), & \text{otherwise}.
\end{cases}
$$

<span id="&#23454;&#29616;"></span>
## Cài đặt

=== "C++"
    ```cpp
    int eulerianNumber(int n, int m) {
      if (m >= n || n == 0) return 0;
      if (m == 0) return 1;
      return (((n - m) * eulerianNumber(n - 1, m - 1)) +
              ((m + 1) * eulerianNumber(n - 1, m)));
    }
    ```

=== "Python"
    ```python
    def eulerianNumber(n, m):
        if m >= n or n == 0:
            return 0
        if m == 0:
            return 1
        return ((n - m) * eulerianNumber(n - 1, m - 1)) + (
            (m + 1) * eulerianNumber(n - 1, m)
        )
    ```

<span id="&#20064;&#39064;"></span>
## Bài tập

-   [CF1349F1 Slime and Sequences (Easy Version)](https://codeforces.com/problemset/problem/1349/F1)
-   [CF1349F2 Slime and Sequences (Hard Version)](https://codeforces.com/problemset/problem/1349/F2)
-   [UOJ 593. New Year's Army](https://uoj.ac/problem/593)
-   [P7511 Three to Six](https://www.luogu.com.cn/problem/P7511)
