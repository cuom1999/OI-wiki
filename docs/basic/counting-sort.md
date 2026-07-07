Kiến thức cần biết trước: [Tổng tiền tố](./prefix-sum.md)

???+ warning "Nhắc nhở"
    Trang này không giới thiệu [**sắp xếp cơ số**](./radix-sort.md).

Trang này giới thiệu ngắn gọn về sắp xếp đếm.

## Định nghĩa

Sắp xếp đếm (counting sort) là một thuật toán sắp xếp có thời gian tuyến tính.

## Quy trình

Nguyên lý hoạt động của sắp xếp đếm là dùng một mảng phụ $C$. Trong đó, phần tử
thứ $i$ lưu số phần tử có giá trị bằng $i$ trong mảng cần sắp xếp $A$. Sau đó,
dựa vào mảng $C$ để đưa các phần tử trong $A$ về đúng vị trí.[^ref1]

Quy trình của thuật toán gồm ba bước:

1.  Tính số lần xuất hiện của từng giá trị;
2.  Tính [tổng tiền tố](./prefix-sum.md) của số lần xuất hiện của từng giá trị;
3.  Dùng tổng tiền tố của số lần xuất hiện để tính thứ hạng của từng phần tử
    từ phải sang trái.

### Vì sao cần tính tổng tiền tố

Nếu chỉ lần lượt đưa các phần tử có số lần xuất hiện dương trong $C$ vào $A$,
thuật toán sẽ không xử lý tốt trường hợp có nhiều phần tử trùng khóa.

Bằng cách tính tổng tiền tố trên mảng phụ $C$, rồi kết hợp với số lần xuất hiện
của từng khóa, ta có thể xác định một thứ hạng duy nhất cho mỗi phần tử trùng
khóa:

Giá trị của mỗi ô trong mảng phụ $C$ chính là số phần tử có khóa tương ứng, còn
tổng tiền tố tại ô đó chính là thứ hạng của phần tử đứng cuối cùng trong nhóm
cùng khóa.

Nếu duyệt $A$ theo thứ tự ngược, các phần tử có cùng khóa vẫn giữ nguyên thứ tự
tương đối ban đầu trong mảng sau khi sắp xếp. Do đó, ta thu được một thuật toán
sắp xếp ổn định.

![Minh họa động sắp xếp đếm](images/counting-sort-animate.svg)

## Tính chất

### Tính ổn định

Sắp xếp đếm là một thuật toán sắp xếp ổn định.

### Độ phức tạp thời gian

Độ phức tạp thời gian của sắp xếp đếm là $O(n+w)$, trong đó $w$ là kích thước
miền giá trị của dữ liệu cần sắp xếp.

## Cài đặt

### Mã giả

$$
\begin{array}{ll}
1 & \textbf{Đầu vào. } \text{Mảng } A \text{ gồm } n \text{ số nguyên dương không vượt quá } w. \\
2 & \textbf{Đầu ra. } \text{Mảng } A \text{ sau khi được sắp xếp không giảm một cách ổn định.} \\
3 & \textbf{Phương pháp. }  \\
4 & \textbf{với }i\gets0\textbf{ đến }w\\
5 & \qquad \textit{cnt}[i]\gets0\\
6 & \textbf{với }i\gets1\textbf{ đến }n\\
7 & \qquad \textit{cnt}[A[i]]\gets\textit{cnt}[A[i]]+1\\
8 & \textbf{với }i\gets1\textbf{ đến }w\\
9 & \qquad \textit{cnt}[i]\gets \textit{cnt}[i]+\textit{cnt}[i-1]\\
10 & \textbf{với }i\gets n\textbf{ giảm đến }1\\
11 & \qquad B[\textit{cnt}[A[i]]]\gets A[i]\\
12 & \qquad \textit{cnt}[A[i]]\gets \textit{cnt}[A[i]]-1\\
13 & \textbf{trả về } B
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

[^ref1]: [Sắp xếp đếm - Wikipedia](https://en.wikipedia.org/wiki/Counting_sort)
