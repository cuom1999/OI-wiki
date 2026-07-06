Kiến thức tiên quyết: [Độ phức tạp thời gian](./complexity.md)

Trang này giới thiệu các kiến thức cơ bản về độ phức tạp khấu hao.

## Dẫn nhập

Phân tích khấu hao là một kỹ thuật dùng để phân tích hiệu năng của thuật toán và
cấu trúc dữ liệu động. Nó không chỉ quan tâm đến chi phí của một thao tác đơn lẻ
mà còn đánh giá chi phí trung bình trên một chuỗi thao tác, từ đó đưa ra nhận
định chính xác hơn về hiệu năng tổng thể. Phân tích khấu hao không liên quan đến
xác suất; nó bảo đảm chi phí trung bình cho mỗi thao tác trên mọi chuỗi thao tác,
kể cả trong trường hợp bất lợi nhất. Ý tưởng chính là phân bổ chi phí của các
thao tác đắt đỏ sang các thao tác rẻ hơn, nhờ đó chi phí trung bình của toàn bộ
chuỗi thao tác vẫn nằm trong phạm vi hợp lý.

Phân tích khấu hao thường dùng ba phương pháp chính: phân tích gộp, phân tích kế
toán và phân tích thế năng. Mỗi phương pháp có trọng tâm riêng và phù hợp với
các tình huống khác nhau, nhưng mục tiêu chung là cân bằng chi phí thao tác, qua
đó kiểm soát hiệu năng tổng thể của cấu trúc dữ liệu trong trường hợp bất lợi
nhất.

## Nội dung

Xét một mảng có thể mở rộng, chẳng hạn `vector` trong C++, với dung lượng ban đầu $m = 1$. Mỗi khi chèn một phần tử mới, nếu mảng đã đầy, cần nhân đôi kích thước mảng, sao chép các phần tử từ mảng cũ sang mảng mới, rồi cuối cùng chèn phần tử mới.

Tiếp theo, dùng thao tác chèn vào mảng động làm ví dụ và phân tích chi phí khấu hao của nó bằng ba phương pháp: phân tích gộp, phân tích kế toán và phân tích thế năng.

### Phân tích gộp

Phân tích gộp tính tổng chi phí của một chuỗi thao tác rồi chia đều cho từng
thao tác, từ đó thu được độ phức tạp thời gian khấu hao của mỗi thao tác.

Với ví dụ mảng động, trước hết có hai loại chi phí chính của thao tác chèn:

-   Nếu mảng chưa đầy, chi phí chèn là $O(1)$.
-   Nếu mảng đã đầy, thao tác chèn cần mở rộng dung lượng; chi phí sao chép phần tử sau khi mở rộng là $O(m)$, trong đó $m$ là kích thước hiện tại của mảng.

Vì vậy, để tính tổng chi phí của $n$ thao tác chèn, có thể tách thành hai phần:

1.  **Chi phí thao tác chèn**: chi phí của mỗi lần chèn phần tử mới là thời gian
    hằng số $O(1)$; với $n$ thao tác, tổng chi phí là $O(n)$.
2.  **Chi phí mở rộng mảng**: mỗi lần mở rộng cần sao chép các phần tử của mảng cũ sang mảng mới. Các thao tác này xảy ra khi kích thước mảng là $1, 2, 4, \ldots , 2^k$, trong đó $2^k$ là lũy thừa lớn nhất không vượt quá $n$. Chi phí của các lần mở rộng lần lượt là $1, 2, 4, \ldots , 2^{k-1}$, tổng là $1 + 2 + 4 + \ldots  + 2^{k-1} = 2^k - 1$. Đây là tổng của một cấp số nhân, nên kết quả là $O(n)$.

Do đó, tổng chi phí chèn của mảng là $O(n)$, và chi phí khấu hao trên mỗi thao
tác là $O(1)$. Ngay cả trong trường hợp bất lợi nhất, chi phí trung bình cho mỗi
lần chèn vẫn là thời gian hằng số.

### Phân tích kế toán

Phương pháp kế toán gán trước một chi phí khấu hao cố định cho mỗi thao tác để
bảo đảm tổng chi phí thực tế của mọi thao tác không vượt quá tổng chi phí đã
phân bổ trước. Phương pháp kế toán giống một cơ chế **trả trước chi phí**: các
thao tác có chi phí thấp sẽ lưu lại một phần "tín dụng" để trả cho các thao tác
có chi phí cao trong tương lai.

Với ví dụ mảng động, có thể phân bổ một chi phí khấu hao cố định cho mỗi thao tác chèn để bảo đảm khi cần mở rộng dung lượng, chi phí đã được dự trữ đủ.

1.  **Phân bổ chi phí**:
    -   Giả sử chi phí thực tế của mỗi thao tác chèn là $1$, và đặt chi phí khấu hao là $3$.
    -   Trong đó $1$ dùng cho thao tác chèn hiện tại, $2$ dùng cho các thao tác mở rộng có thể xảy ra trong tương lai.

2.  **Sử dụng chi phí**:
    -   Khi mảng đã đầy, cần thực hiện thao tác mở rộng, với chi phí thực tế là $O(m)$, trong đó $m$ là kích thước hiện tại của mảng.
    -   Giả sử trước khi mở rộng, số phần tử trong mảng là $n$. Vì $n/2$ phần tử ở nửa sau của mảng cũ đã dự trữ tổng cộng $n$ đơn vị chi phí khấu hao khi được chèn, khoản này vừa đủ trả chi phí mở rộng.

Sau đây là một ví dụ cụ thể:

```text
Trạng thái ban đầu:
arr    = [1, 2, 3, 4]  // mảng ban đầu
amount = [2, 2, 2, 2]  // chi phí dự trữ của từng phần tử

// Lần mở rộng thứ nhất: mảng đã đầy, cần mở rộng
arr    = [1, 2, 3, 4, null, null, null, null]  // mảng sau khi mở rộng
amount = [2, 2, 0, 0, 0, 0, 0, 0]  // chi phí của 3, 4 dùng để trả cho mở rộng

// Tiếp tục chèn phần tử mới cho đến khi lại đầy
arr    = [1, 2, 3, 4, 5, 6, 7, 8]  // tiếp tục lấp đầy mảng
amount = [2, 2, 0, 0, 2, 2, 2, 2]  // các phần tử mới chèn cũng dự trữ chi phí

// Lần mở rộng thứ hai: mảng lại đầy, cần không gian lớn hơn
arr    = [1, 2, 3, 4, 5, 6, 7, 8, null, null, null, null, null, null, null, null]  // mảng sau khi mở rộng
amount = [2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]  // chi phí của 5, 6, 7, 8 dùng để trả cho mở rộng
```

Quá trình trên cho thấy chi phí khấu hao được lưu lại từ mỗi thao tác chèn đủ để trả cho các thao tác mở rộng trong tương lai, nhờ đó bảo đảm chi phí khấu hao của mỗi thao tác duy trì ở $O(1)$.

### Phân tích thế năng

Phân tích thế năng định nghĩa một hàm thế năng (thường ký hiệu là $\Phi$) để đo
**năng lượng tiềm ẩn** của cấu trúc dữ liệu, tức các tài nguyên dự trữ trong
trạng thái hệ thống có thể dùng để trả cho các thao tác đắt đỏ trong tương lai.
Sự thay đổi thế năng được dùng để cân bằng tổng chi phí của chuỗi thao tác, từ
đó bảo đảm chi phí khấu hao của toàn bộ thuật toán nằm trong phạm vi hợp lý.

#### Nguyên lý

Trước hết, định nghĩa **trạng thái** $S$ là trạng thái của cấu trúc dữ liệu tại một thời điểm; trạng thái này có thể chứa số lượng phần tử, dung lượng, con trỏ, v.v. Trạng thái ban đầu được ký hiệu là $S_0$, tức trạng thái khi chưa thực hiện thao tác nào.

Tiếp theo, định nghĩa hàm thế năng $\Phi(S)$ để đo thế năng của trạng thái cấu trúc dữ liệu $S$. Hàm này thỏa hai tính chất sau:

1.  **Thế năng ban đầu**: ở trạng thái ban đầu $S_0$ của cấu trúc dữ liệu, thế năng $\Phi(S_0) = 0$.
2.  **Không âm**: ở mọi trạng thái $S$, thế năng $\Phi(S) \geq 0$.

Với mỗi thao tác, chi phí khấu hao $\hat{c}$ được định nghĩa là:

$$
\hat{c} = c + \Phi(S') - \Phi(S)
$$

Trong đó $c$ là chi phí thực tế của thao tác, còn $S$ và $S'$ lần lượt là trạng thái cấu trúc dữ liệu trước và sau thao tác. Công thức này cho thấy chi phí khấu hao bằng chi phí thực tế cộng với độ thay đổi của thế năng. Nếu thao tác làm tăng thế năng (tức $\Phi(S') > \Phi(S)$), chi phí khấu hao tăng; nếu thao tác tiêu hao thế năng (tức $\Phi(S') < \Phi(S)$), chi phí khấu hao giảm.

Có thể dùng hàm thế năng để phân tích tổng chi phí của một chuỗi thao tác. Gọi $S_1, S_2, \dots, S_m$ là chuỗi trạng thái sinh ra sau $m$ thao tác bắt đầu từ trạng thái ban đầu $S_0$, và $c_i$ là chi phí thực tế của thao tác thứ $i$. Khi đó chi phí khấu hao $p_i$ của thao tác thứ $i$ là:

$$
p_i = c_i + \Phi(S_i) - \Phi(S_{i-1})
$$

Do đó, tổng chi phí thời gian của $m$ thao tác là:

$$
\sum_{i=1}^m c_i = \sum_{i=1}^m p_i + \Phi(S_0) - \Phi(S_m)
$$

Vì $\Phi(S_m) \geq \Phi(S_0)$, cận trên của tổng chi phí thời gian là:

$$
\sum_{i=1}^m p_i \geq \sum_{i=1}^m c_i
$$

Vì vậy, nếu $p_i = O(T(n))$, thì $O(T(n))$ là một cận trên của độ phức tạp khấu hao.

#### Ví dụ: phân tích mở rộng mảng động

Với thao tác chèn của mảng động `vector`, định nghĩa hàm thế năng $\Phi(h)$ như
sau:

$$
\Phi(h) = 2n - m + 1
$$

Trong đó $n$ là số phần tử trong mảng, còn $m$ là dung lượng hiện tại của mảng.
Hàm thế năng này phản ánh mức độ mảng đã được lấp đầy so với dung lượng hiện
tại; hằng số $+1$ giúp thế năng ở trạng thái ban đầu bằng $0$ khi $n=0, m=1$.

1.  **Thao tác chèn (không cần mở rộng)**:
    -   **Chi phí thao tác**: $O(1)$, vì thao tác chỉ chèn một phần tử.
    -   **Độ thay đổi thế năng**: sau khi chèn, số phần tử tăng thêm 1, thế năng tăng $2$.
        -   $\Phi(h') - \Phi(h) = (2(n + 1) - m + 1) - (2n - m + 1) = 2$
    -   **Chi phí khấu hao**: $1 + 2 = 3$

2.  **Thao tác chèn (kích hoạt mở rộng)**:
    -   Giả sử dung lượng hiện tại $m = n$; khi chèn một phần tử mới, thao tác mở rộng được kích hoạt và dung lượng mới trở thành $2n$.
    -   **Chi phí thao tác**: $O(n)$, vì cần sao chép tất cả phần tử sang mảng mới và chèn phần tử mới.
    -   **Độ thay đổi thế năng**: sau khi mở rộng, dung lượng tăng, thế năng giảm, độ thay đổi là $2 - n$.
        -   $\Phi(h') - \Phi(h) = (2(n + 1) - 2n + 1) - (2n - n + 1) = 2 - n$
    -   **Chi phí khấu hao**: $n + 1 + (2 - n) = 3$

Từ phân tích trên, dù chi phí thực tế của thao tác mở rộng cao, nhờ cách thiết
kế hàm thế năng, chi phí khấu hao tổng thể vẫn giữ ở mức hằng số $O(1)$.

## Ví dụ mở rộng: thao tác ngăn xếp

Thao tác trên ngăn xếp là một trong những ứng dụng kinh điển của phân tích khấu hao. Giả sử ngăn xếp `S` hỗ trợ ba thao tác sau:

| Thao tác         | Mô tả                       | Chi phí thực tế $c_i$          |
| ---------------- | --------------------------- | ------------------------------ |
| `S.push(x)`      | Đưa phần tử x vào ngăn xếp   | $1$                            |
| `S.pop()`        | Lấy phần tử ở đỉnh           | $1$                            |
| `S.multi-pop(k)` | Lấy k phần tử ở đỉnh         | $O(\min{\lvert S\rvert, k})$   |

Phần này phân tích chi phí khấu hao của các thao tác ngăn xếp này bằng ba phương pháp: phân tích gộp, phân tích kế toán và phân tích thế năng.

### Phương pháp phân tích gộp

Phân tích gộp tính tổng chi phí của tất cả thao tác rồi chia đều cho từng thao tác, từ đó thu được chi phí khấu hao.

1.  Với $n_{push}$ thao tác `push(x)`, mỗi thao tác có chi phí $O(1)$, nên tổng chi phí là $O(n_{push})$.
2.  Với $n_{pop}$ thao tác `pop()`, mỗi thao tác có chi phí $O(1)$, nên tổng chi phí là $O(n_{pop})$.
3.  Với $n_{multi-pop}$ thao tác `multi-pop(k)`, dù chi phí thực tế của mỗi thao
    tác là $O(\min(\lvert S \rvert, k))$, tổng số phần tử bị lấy ra bởi các thao
    tác này không vượt quá số phần tử đã được `push(x)` trước đó, nên phần chi
    phí do lấy phần tử ra bị chặn bởi $n_{push}$.

Mỗi thao tác vẫn có chi phí điều khiển hằng số. Vì vậy, nếu tổng số thao tác là
$n = n_{push} + n_{pop} + n_{multi-pop}$, tổng chi phí là $O(n+n_{push})=O(n)$,
và chi phí khấu hao của mỗi thao tác là $O(1)$.

### Phương pháp phân tích kế toán

Phân tích kế toán dự trữ một phần chi phí cho mỗi thao tác `push(x)` để trả cho các thao tác `pop()` hoặc `multi-pop(k)` có thể xảy ra trong tương lai.

1.  **`S.push(x)`**: giả sử chi phí khấu hao của mỗi thao tác `push(x)` là $2$, trong đó $1$ đơn vị dùng cho thao tác hiện tại, và $1$ đơn vị còn lại được lưu làm chi phí để trả cho thao tác `pop()` hoặc `multi-pop(k)` trong tương lai.
2.  **`S.pop()`**: chi phí thực tế là $1$, nhưng vì thao tác `push(x)` trước đó đã dự trữ $1$ đơn vị chi phí cho phần tử này, nên chi phí khấu hao là $0$.
3.  **`S.multi-pop(k)`**: chi phí thực tế của mỗi phần tử bị lấy ra là $1$, có thể được trả bằng chi phí đã dự trữ từ thao tác `push(x)` của chính phần tử đó, nên chi phí khấu hao là $0$.

Qua phân tích trên, chi phí dự trữ khi đưa phần tử vào ngăn xếp đủ để trả cho thao tác lấy phần tử đó ra trong tương lai, nên chi phí khấu hao của mỗi thao tác là $O(1)$.

### Phương pháp phân tích thế năng

Phân tích thế năng định nghĩa một hàm thế năng để đo trạng thái của ngăn xếp và dùng sự thay đổi thế năng để cân bằng chi phí thao tác.

1.  **Hàm thế năng**: đặt $\Phi(h)$ là số phần tử trong ngăn xếp, tức $\Phi(h) = \lvert S \rvert$. Mỗi phần tử đóng góp $1$ đơn vị thế năng.
2.  **`S.push(x)`**: mỗi thao tác `push(x)` làm tăng số phần tử trong ngăn xếp, thế năng tăng $1$, nên chi phí khấu hao là $1 + 1 = 2$.
3.  **`S.pop()`**: mỗi thao tác `pop()` làm giảm số phần tử trong ngăn xếp, thế năng giảm $1$, nên chi phí khấu hao là $1 - 1 = 0$.
4.  **`S.multi-pop(k)`**: thao tác `multi-pop(k)` lấy ra $k$ phần tử, thế năng giảm $k$, nên chi phí khấu hao là $k - k = 0$.

Với cách thiết kế hàm thế năng trên, chi phí khấu hao của thao tác `push(x)` là $2$, còn chi phí khấu hao của `pop()` và `multi-pop(k)` là $0$. Vì vậy, chi phí khấu hao của mọi thao tác ngăn xếp đều là $O(1)$.

## Tài liệu tham khảo

-   [Amortized Analysis - Wikipedia](https://en.wikipedia.org/wiki/Amortized_analysis)
-   [Cornell CS 3110 - Lecture 20: Amortized Analysis](https://www.cs.cornell.edu/courses/cs3110/2011sp/Lectures/lec20-amortized/amortized.htm)
