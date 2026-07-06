## Định nghĩa

Quy hoạch động trên đoạn là một mở rộng của quy hoạch động tuyến tính. Khi chia bài toán theo từng giai đoạn, nó phụ thuộc nhiều vào thứ tự xuất hiện của các phần tử trong giai đoạn và vào việc chúng được hợp nhất từ những phần tử nào ở giai đoạn trước.

Gọi trạng thái $f(i,j)$ là giá trị lớn nhất có thể thu được khi hợp nhất tất cả phần tử từ vị trí $i$ đến $j$. Khi đó $f(i,j)=\max\{f(i,k)+f(k+1,j)+cost\}$, trong đó $cost$ là giá trị khi hợp nhất hai nhóm phần tử này.

## Tính chất

DP trên đoạn có các đặc điểm sau:

**Hợp nhất**: gộp hai hoặc nhiều phần lại với nhau; cũng có thể xét theo chiều ngược lại.

**Đặc trưng**: bài toán có thể được phân rã thành dạng các phần có thể hợp nhất từng đôi một.

**Cách giải**: đặt giá trị tối ưu cho toàn bài toán, duyệt điểm hợp nhất, chia bài toán thành hai phần trái và phải, rồi hợp nhất giá trị tối ưu của hai phần để thu được giá trị tối ưu của bài toán ban đầu.

## Giải thích

### Ví dụ

???+ note "[「NOI1995」Gộp đá](https://loj.ac/problem/10147)"
    Tóm tắt đề bài: Trên một vòng tròn có $n$ số $a_1,a_2,\dots,a_n$. Thực hiện $n-1$ lần hợp nhất, mỗi lần gộp hai đống kề nhau thành một đống và nhận điểm bằng tổng số viên đá trong đống mới. Cần tối đa hóa tổng điểm.

Trước hết xét trường hợp không ở trên vòng tròn mà ở trên một chuỗi.

Đặt $f(i,j)$ là điểm lớn nhất khi hợp nhất tất cả đống đá trong đoạn $[i,j]$ thành một đống.

**Phương trình chuyển trạng thái** là: $f(i,j)=\max\{f(i,k)+f(k+1,j)+\sum_{t=i}^{j} a_t \}~(i\le k<j)$.

Gọi $sum_i$ là tổng tiền tố của mảng $a$, phương trình chuyển có thể viết thành $f(i,j)=\max\{f(i,k)+f(k+1,j)+sum_j-sum_{i-1} \}$.

### Cách chuyển trạng thái

Vì khi tính $f(i,j)$ cần biết mọi giá trị $f(i,k)$ và $f(k+1,j)$, mà số phần tử trong hai đoạn này đều nhỏ hơn đoạn của $f(i,j)$, lấy $len=j-i+1$ làm giai đoạn DP. Trước hết duyệt $len$ tăng dần, sau đó duyệt $i$, tính $j$ từ $len$ và $i$, rồi duyệt $k$. Độ phức tạp thời gian là $O(n^3)$.

### Cách xử lý vòng tròn

Trong đề bài, các đống đá nằm trên một vòng tròn chứ không phải một chuỗi. Cần xử lý thế nào?

**Cách 1**: Vì các đống đá tạo thành vòng tròn, có thể duyệt vị trí cắt để biến vòng tròn thành một chuỗi. Do phải duyệt $n$ lần, độ phức tạp cuối cùng là $O(n^4)$.

**Cách 2**: Nhân đôi chuỗi, thu được $2\times n$ đống, trong đó đống thứ $i$ giống đống thứ $n+i$. Sau khi dùng DP để giải, lấy giá trị tốt nhất trong $f(1,n),f(2,n+1),\dots,f(n,2n-1)$ làm đáp án. Độ phức tạp là $O(n^3)$.

## Cài đặt

=== "C++"
    ```cpp
    for (len = 2; len <= n; len++)
      for (i = 1; i <= 2 * n - len; i++) {
        int j = len + i - 1;
        for (k = i; k < j; k++)
          f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
      }
    ```

=== "Python"
    ```python
    for len in range(2, n + 1):
        for i in range(1, 2 * n - len + 1):
            j = len + i - 1
            for k in range(i, j):
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1])
    ```

## Một số bài luyện tập

[NOIP 2006 Vòng cổ năng lượng](https://www.luogu.com.cn/problem/P1063)

[NOIP 2007 Trò chơi lấy số trong ma trận](https://www.luogu.com.cn/problem/P1005)

[「IOI2000」Bưu điện](https://www.luogu.com.cn/problem/P4767)
