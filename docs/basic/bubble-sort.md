Trang này giới thiệu ngắn gọn về sắp xếp nổi bọt.

## Định nghĩa

Sắp xếp nổi bọt (tiếng Anh: Bubble sort) là một thuật toán sắp xếp đơn giản. Trong quá trình chạy thuật toán, các phần tử nhỏ hơn dần "nổi" lên đầu dãy giống như bọt khí, vì vậy thuật toán này được gọi là sắp xếp nổi bọt.

## Quy trình

Nguyên lý hoạt động của thuật toán là mỗi lần kiểm tra hai phần tử kề nhau; nếu phần tử đứng trước và phần tử đứng sau thỏa điều kiện cần đổi theo thứ tự sắp xếp đã cho, thì hoán đổi hai phần tử kề nhau đó. Khi không còn cặp phần tử kề nhau nào cần hoán đổi, quá trình sắp xếp hoàn tất.

Sau $i$ lượt quét, $i$ phần tử ở cuối dãy chắc chắn là $i$ phần tử lớn nhất. Vì vậy, sắp xếp nổi bọt chỉ cần quét mảng nhiều nhất $n-1$ lần để hoàn tất.

## Tính chất

### Tính ổn định

Sắp xếp nổi bọt là một thuật toán sắp xếp ổn định.

### Độ phức tạp thời gian

Khi dãy đã hoàn toàn có thứ tự, sắp xếp nổi bọt chỉ cần duyệt mảng một lần và không thực hiện thao tác hoán đổi nào, nên độ phức tạp thời gian là $O(n)$.

Trong trường hợp xấu nhất, sắp xếp nổi bọt phải thực hiện $\frac{(n-1)n}{2}$ thao tác hoán đổi, với độ phức tạp thời gian là $O(n^2)$.

Độ phức tạp thời gian trung bình của sắp xếp nổi bọt là $O(n^2)$.

## Cài đặt

### Mã giả

$$
\begin{array}{ll}
1 & \textbf{Đầu vào. } \text{Mảng } A \text{ gồm }n\text{ phần tử.} \\
2 & \textbf{Đầu ra. } A\text{ được sắp xếp không giảm một cách ổn định.} \\
3 & \textbf{Phương pháp. }  \\
4 & flag\gets True\\
5 & \textbf{while }flag\\
6 & \qquad flag\gets False\\
7 & \qquad\textbf{for }i\gets1\textbf{ to }n-1\\
8 & \qquad\qquad\textbf{if }A[i]>A[i + 1]\\
9 & \qquad\qquad\qquad flag\gets True\\
10 & \qquad\qquad\qquad \text{Hoán đổi } A[i]\text{ và }A[i + 1]
\end{array}
$$

=== "C++"
    ```cpp
    --8<-- "docs/basic/code/bubble-sort/bubble-sort_1.cpp"
    ```

=== "Python"
    ```python
    --8<-- "docs/basic/code/bubble-sort/bubble-sort_1.py:core"
    ```

=== "Java"
    ```java
    // Giả sử kích thước mảng là n + 1, sắp xếp nổi bọt bắt đầu từ chỉ số 1
    static void bubble_sort(int[] a, int n) {
        boolean flag = true;
        while (flag) {
            flag = false;
            for (int i = 1; i < n; i++) {
                if (a[i] > a[i + 1]) {
                    flag = true;
                    int t = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = t;
                }
            }
        }
    }
    ```
