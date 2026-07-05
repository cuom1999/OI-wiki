Trang này giới thiệu ngắn gọn về sắp xếp chèn.

## Định nghĩa

Sắp xếp chèn (tiếng Anh: Insertion sort) là một thuật toán sắp xếp đơn giản và trực quan. Nguyên lý của nó là chia các phần tử cần sắp xếp thành hai phần "đã sắp xếp" và "chưa sắp xếp"; mỗi lần chọn một phần tử từ phần "chưa sắp xếp" rồi chèn vào đúng vị trí trong phần "đã sắp xếp".

Một thao tác tương tự sắp xếp chèn là khi chơi bài: lấy một lá bài từ bàn, chèn nó vào tay bài theo thứ tự giá trị, rồi mới lấy lá tiếp theo.

![Minh họa động sắp xếp chèn](images/insertion-sort-animate.svg)

## Tính chất

### Tính ổn định

Sắp xếp chèn là một thuật toán sắp xếp ổn định.

### Độ phức tạp thời gian

Độ phức tạp thời gian tốt nhất của sắp xếp chèn là $O(n)$; thuật toán rất hiệu quả khi dãy gần như đã có thứ tự.

Độ phức tạp thời gian xấu nhất và trung bình của sắp xếp chèn đều là $O(n^2)$.

## Cài đặt

### Mã giả

$$
\begin{array}{ll}
1 & \textbf{Đầu vào. } \text{Mảng } A \text{ gồm }n\text{ phần tử.} \\
2 & \textbf{Đầu ra. } A\text{ được sắp xếp không giảm một cách ổn định.} \\
3 & \textbf{Phương pháp. }  \\
4 & \textbf{for } i\gets 2\textbf{ to }n\\
5 & \qquad key\gets A[i]\\
6 & \qquad j\gets i-1\\
7 & \qquad\textbf{while }j>0\textbf{ and }A[j]>key\\
8 & \qquad\qquad A[j + 1]\gets A[j]\\
9 & \qquad\qquad j\gets j - 1\\
10 & \qquad A[j + 1]\gets key
\end{array}
$$

=== "C++"
    ```cpp
    --8<-- "docs/basic/code/insertion-sort/insertion-sort_1.cpp"
    ```

=== "Python"
    ```python
    --8<-- "docs/basic/code/insertion-sort/insertion-sort_1.py:core"
    ```

=== "Java"
    ```java
    --8<-- "docs/basic/code/insertion-sort/insertion-sort_1.java"
    ```

## Sắp xếp chèn nhị phân

Sắp xếp chèn còn có thể dùng tìm kiếm nhị phân để tối ưu hiệu năng; khi số phần tử cần sắp xếp lớn, hiệu quả tối ưu sẽ rõ rệt hơn.

### Độ phức tạp thời gian

Tư tưởng cơ bản của sắp xếp chèn nhị phân giống với sắp xếp chèn trực tiếp. Sắp xếp chèn nhị phân chỉ tối ưu hằng số trong độ phức tạp thời gian của sắp xếp chèn, nên độ phức tạp sau tối ưu vẫn không đổi.

### Cài đặt

=== "C++"
    ```cpp
    void insertion_sort(int arr[], int len) {
      if (len < 2) return;
      for (int i = 1; i != len; ++i) {
        int key = arr[i];
        auto index = upper_bound(arr, arr + i, key) - arr;
        // Dùng memmove để di chuyển phần tử nhanh hơn vòng lặp for, độ phức tạp vẫn là O(n)
        memmove(arr + index + 1, arr + index, (i - index) * sizeof(int));
        arr[index] = key;
      }
    }
    ```
