Trang này giới thiệu ngắn gọn về sắp xếp chọn.

## Định nghĩa

Sắp xếp chọn (selection sort) là một thuật toán sắp xếp đơn giản và trực quan.
Nguyên lý của nó là mỗi lần tìm phần tử nhỏ thứ $i$ (tức phần tử nhỏ nhất trong
$A_{i..n}$), rồi hoán đổi phần tử này với phần tử ở vị trí thứ $i$ của mảng.

![Minh họa động sắp xếp chọn](images/selection-sort-animate.svg)

## Tính chất

### Tính ổn định

Tính ổn định của sắp xếp chọn phụ thuộc vào cách cài đặt cụ thể.

Nếu cài đặt bằng danh sách liên kết, do thao tác chèn và xóa tại vị trí bất kỳ
trong danh sách liên kết đều là $O(1)$, không cần dùng thao tác hoán đổi hai
phần tử: mỗi lần chọn phần tử nhỏ nhất trong phần chưa sắp xếp (nếu có nhiều
phần tử như vậy thì chọn phần tử đầu tiên), rồi chèn nó vào trước phần tử đầu
tiên của phần chưa sắp xếp. Cách này bảo đảm được tính ổn định.

Nếu cài đặt bằng mảng (cách cài đặt thường gặp trong OI), do thao tác chèn và
xóa tại vị trí bất kỳ trong mảng đều là $O(n)$, thường chỉ có thể dùng hoán đổi
để đưa phần tử từ phần chưa sắp xếp sang phần đã sắp xếp. Thao tác hoán đổi làm
cho sắp xếp chọn cài đặt bằng mảng không ổn định.

Các ví dụ cài đặt sau đây đều dựa trên việc hoán đổi phần tử trong mảng, nên đều **không ổn định**.

### Độ phức tạp thời gian

Độ phức tạp thời gian tốt nhất, trung bình và xấu nhất của sắp xếp chọn đều là $O(n^2)$.

## Cài đặt

### Mã giả

$$
\begin{array}{ll}
1 & \textbf{Đầu vào. } \text{Mảng } A \text{ gồm }n\text{ phần tử.} \\
2 & \textbf{Đầu ra. } A\text{ được sắp xếp theo thứ tự không giảm.} \\
3 & \textbf{Phương pháp. }  \\
4 & \textbf{với } i\gets 1\textbf{ đến }n-1\\
5 & \qquad ith\gets i\\
6 & \qquad \textbf{với }j\gets i+1\textbf{ đến }n\\
7 & \qquad\qquad\textbf{nếu }A[j]<A[ith]\\
8 & \qquad\qquad\qquad ith\gets j\\
9 & \qquad \text{hoán đổi }A[i]\text{ và }A[ith]\\
\end{array}
$$

=== "C++"
    ```cpp
    --8<-- "docs/basic/code/selection-sort/selection-sort_1.cpp"
    ```

=== "Python"
    ```python
    --8<-- "docs/basic/code/selection-sort/selection-sort_1.py:core"
    ```

=== "Java"
    ```java
    // Chỉ số của arr trong mã bắt đầu từ 1
    static void selection_sort(int[] arr, int n) {
        for (int i = 1; i < n; i++) {
            int ith = i;
            for (int j = i + 1; j <= n; j++) {
                if (arr[j] < arr[ith]) {
                    ith = j;
                }
            }
            // swap
            int temp = arr[i];
            arr[i] = arr[ith];
            arr[ith] = temp;
        }
    }
    ```
