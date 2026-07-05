Kiến thức cần biết trước: [Tổng tiền tố](./prefix-sum.md)

???+ warning "Nhắc nhở"
    Trang này không giới thiệu [**sắp xếp cơ số**](./radix-sort.md).

Trang này giới thiệu ngắn gọn về sắp xếp đếm.

## Định nghĩa

Sắp xếp đếm (tiếng Anh: Counting sort) là một thuật toán sắp xếp thời gian tuyến tính.

## Quy trình

Nguyên lý hoạt động của sắp xếp đếm là dùng một mảng phụ $C$, trong đó phần tử thứ $i$ là số phần tử có giá trị bằng $i$ trong mảng cần sắp xếp $A$, rồi dựa vào mảng $C$ để đưa các phần tử trong $A$ về đúng vị trí.[^ref1]

Quy trình của thuật toán gồm ba bước:

1.  Tính số lần xuất hiện của từng số;
2.  Tính [tổng tiền tố](./prefix-sum.md) của số lần xuất hiện của từng số;
3.  Dùng tổng tiền tố của số lần xuất hiện để tính thứ hạng của từng số từ phải sang trái.

### Vì sao cần tính tổng tiền tố

Việc trực tiếp đưa lần lượt các phần tử ứng với giá trị dương trong $C$ vào $A$ không xử lý được trường hợp có phần tử trùng nhau.

Bằng cách tính tổng tiền tố cho từng mục trong mảng phụ $C$, rồi kết hợp với giá trị của từng mục, ta có thể xác định một thứ hạng duy nhất cho các phần tử trùng nhau:

Giá trị của mỗi mục trong mảng phụ $C$ chính là số phần tử trùng nhau ứng với khóa đó, còn tổng tiền tố của mục này chính là thứ hạng của phần tử trùng nhau đứng cuối cùng.

Nếu xếp theo thứ tự ngược của $A$, thì rõ ràng mảng sau khi sắp xếp sẽ giữ nguyên thứ tự ban đầu của $A$ trong trường hợp các phần tử có cùng khóa; do đó ta thu được một thuật toán sắp xếp ổn định.

![Minh họa động sắp xếp đếm](images/counting-sort-animate.svg)

## Tính chất

### Tính ổn định

Sắp xếp đếm là một thuật toán sắp xếp ổn định.

### Độ phức tạp thời gian

Độ phức tạp thời gian của sắp xếp đếm là $O(n+w)$, trong đó $w$ là kích thước miền giá trị của dữ liệu cần sắp xếp.

## Cài đặt

### Mã giả

$$
\begin{array}{ll}
1 & \textbf{Đầu vào. } \text{Mảng } A \text{ gồm }n\text{ số nguyên dương không vượt quá } w. \\
2 & \textbf{Đầu ra. } \text{Mảng }A\text{ sau khi được sắp xếp không giảm một cách ổn định.} \\
3 & \textbf{Phương pháp. }  \\
4 & \textbf{for }i\gets0\textbf{ to }w\\
5 & \qquad \textit{cnt}[i]\gets0\\
6 & \textbf{for }i\gets1\textbf{ to }n\\
7 & \qquad \textit{cnt}[A[i]]\gets\textit{cnt}[A[i]]+1\\
8 & \textbf{for }i\gets1\textbf{ to }w\\
9 & \qquad \textit{cnt}[i]\gets \textit{cnt}[i]+\textit{cnt}[i-1]\\
10 & \textbf{for }i\gets n\textbf{ downto }1\\
11 & \qquad B[\textit{cnt}[A[i]]]\gets A[i]\\
12 & \qquad \textit{cnt}[A[i]]\gets \textit{cnt}[A[i]]-1\\
13 & \textbf{return } B
\end{array}
$$

=== "C++"
    ```cpp
    --8<-- "docs/basic/code/counting-sort/counting-sort_1.cpp"
    ```

=== "Python"
    ```python
    --8<-- "docs/basic/code/counting-sort/counting-sort_1.py:core"
    ```

## Tài liệu tham khảo và chú thích

[^ref1]: [Counting sort - Wikipedia](https://en.wikipedia.org/wiki/Counting_sort)
