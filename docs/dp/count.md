**DP đếm** là một phương pháp tìm kiếm có nhớ tương tự DP, dùng để giải các bài toán đếm (và tính tổng). Nó khác với DP theo nghĩa hẹp, tức các bài toán tối ưu hóa, ở một số điểm.

## Cơ sở

### Ý tưởng cơ bản

Bài toán đếm thường là bài toán tính kích thước của một tập $S$. Trong OI, kích thước của $S$ đôi khi có thể đạt mức $\Theta(n^n)$, thậm chí $\Theta(2^{n!})$ (thường đáp án sẽ lấy theo một môđun cố định), trong đó $n$ là quy mô bài toán. Vì vậy không thể liệt kê từng phần tử của $S$.

Nếu có thể chia $S$ thành một số tập con rời nhau, thì số phần tử của $S$ bằng tổng số phần tử của các phần đó. Nếu việc đếm trên các tập con này lại có dạng tương tự bài toán ban đầu, có thể giải bằng phương pháp giống quy hoạch động.

### Ví dụ

???+ note "Bài ví dụ"
    Cho số nguyên dương $n$, hỏi có bao nhiêu cách phân tích $n$ thành tổng của $k$ số nguyên dương, trong đó đổi vị trí được xem là một cách phân tích khác.

Đặt $S_{n,k}$ là tập các bộ số nguyên dương có dạng $(a_1,\dots,a_k)$, trong đó $a_1+\dots+a_k=n$. Nếu cố định $a_k$, suy luận như sau: vì $a_1+a_2+\dots+a_{k-1}+a_k=n$, nên $a_1+a_2+\dots+a_{k-1}=n-a_k$. Theo định nghĩa của $S_{n,k}$, có $(a_1,a_2,\dots,a_{k-1})\in S_{n-a_k,k-1}$.

Vì $a_1,a_2,\dots,a_k$ đều là số nguyên dương, miền giá trị của $a_k$ là $[1,n-k+1]\cap\mathbb Z$. Do đó có thể chia $S_{n,k}$ theo giá trị của $a_k$ thành $n-k+1$ tập con. Khi $a_k=i$, tập con tương ứng là:

$$
\{(L, i) \mid L \in S_{n-i,k-1}\}.
$$

Số phần tử của tập con này bằng $|S_{n-i,k-1}|$. Vì các giá trị $i$ khác nhau, các tập con này đôi một rời nhau. Do đó:

$$
|S_{n,k}| = \sum_{i=1}^{n-k+1} |S_{n-i,k-1}|.
$$

Như vậy có thể xử lý bằng phương pháp tương tự DP. Đặt $f_{n,k}=|S_{n,k}|$, thu được phương trình chuyển trạng thái:

$$
f_{n,k} = \sum_{i=1}^{n-k+1} f_{n-i,k-1}.
$$

Từ đó có thể dùng DP để giải.

### Điểm giống và khác với DP tối ưu hóa

DP đếm và DP tối ưu hóa đều tính một giá trị trong một phạm vi $\Omega$ (kích thước hoặc giá trị tối ưu). Giá trị này thu được bằng cách xử lý mọi phần tử trong $\Omega$, rồi gộp các giá trị xử lý lại.

Ví dụ, với bài toán ba lô 0-1, các phần tử của $\Omega$ là mọi tập vật phẩm có thể đưa vào ba lô. Với một phương án $S$ trong $\Omega$, xử lý $S$ để nhận được $w(S)$ là tổng giá trị các vật trong $S$. Sau đó lấy giá trị lớn nhất trong tất cả các giá trị xử lý để được đáp án.

Với bài toán đếm, các phần tử của $\Omega$ chính là những phần tử trong tập $S$ cần đếm. Việc xử lý là biến mỗi phần tử của $S$ thành $1$, rồi cộng các giá trị $1$ đó lại. Vì mỗi phần tử của $S$ tương ứng với đúng một $1$, giá trị thu được chính là số phần tử của $S$.

Khi phép gộp là lấy lớn nhất/nhỏ nhất, có thể chia $\Omega$ thành tùy ý nhiều phần, chỉ cần hợp của các phần đó bằng $\Omega$ là đủ, không cần điều kiện rời nhau. Nhưng với bài toán đếm thì điều này không đúng; cần chia $\Omega$ thành các phần đôi một rời nhau. Đây là khác biệt so với DP tối ưu hóa.

## Ví dụ

???+ note "Bài ví dụ"
    Cho số nguyên dương $n$, hỏi có bao nhiêu cách phân tích $n$ thành tổng của tùy ý nhiều số nguyên dương, trong đó đổi vị trí được xem là **cùng một** cách phân tích.

### Cách giải 1

Tập cần đếm gồm các đa tập số nguyên dương có tổng bằng $n$. Tuy nhiên cách định nghĩa này không dễ suy ra chuyển trạng thái.

Nếu một đa tập $T$ chỉ chứa các số nguyên dương $\le M$ và tổng các phần tử của $T$ là $n$, gọi $T\in S_{n,M}$. Xét số lần $M$ xuất hiện, có thể là $k\in\left[0,\left\lfloor\dfrac nM\right\rfloor\right]\cap\mathbb Z$. Khi đó có thể chuyển về $S_{n-kM,M-1}$ rồi lấy tổng. Độ phức tạp là $\Theta(n^2\log n)$, trong đó $\log$ đến từ chuỗi điều hòa do miền giá trị của $k$ gây ra.

Nhưng như vậy vẫn chưa đủ tốt. Xét ví dụ sau:

$$
\begin{aligned}
f_{8, 3} &= {\color{red}f_{8, 2} + f_{5, 2} + f_{2, 2}} \\
f_{9, 3} &= {\color{blue}f_{9, 2} + f_{6, 2} + f_{3, 2} + f_{0, 2}} \\
f_{10, 3} &= {\color{green}f_{10, 2} + f_{7, 2} + f_{4, 2} + f_{1, 2}}\\
f_{11, 3} &= f_{11, 2} + {\color{red}f_{8, 2} + f_{5, 2} + f_{2, 2}}\\
f_{12, 3} &= f_{12, 2} + {\color{blue}f_{9, 2} + f_{6, 2} + f_{3, 2} + f_{0, 2}}\\
f_{13, 3} &= f_{13, 2} + {\color{green}f_{10, 2} + f_{7, 2} + f_{4, 2} + f_{1, 2}}\\
\end{aligned}
$$

Thay thế các biểu thức tương đương, có $f_{11,3}=f_{11,2}+f_{8,3}$, $f_{12,3}=f_{12,2}+f_{9,3}$, $f_{13,3}=f_{13,2}+f_{10,3}$. Tương tự, thu được phương trình chuyển trạng thái tổng quát:

$$
f_{n, M} = f_{n, M - 1} + \begin{cases} f_{n - M, M} & n \ge M, \\ 0 & \text{ngược lại}. \end{cases}
$$

Lúc này, độ phức tạp thời gian là $\Theta(n^2)$.

### Cách giải 2

Xét rằng một đa tập $T$ gồm các số nguyên dương luôn có thể thu được bằng hai thao tác: "tăng mỗi phần tử trong $T$ lên $1$" và "thêm vào $T$ một phần tử có giá trị $1$"; hơn nữa các dãy thao tác khác nhau cho kết quả khác nhau.

Như vậy chuyển trạng thái trên $T$ có thể biến thành chuyển trạng thái trên dãy thao tác. Xét thao tác cuối cùng trong dãy thao tác phân tích $n$ thành $m$ số (gọi toàn bộ các dãy này là $B_{n,m}$). Nếu thao tác cuối là thao tác thứ nhất, số lượng phần tử không tăng nhưng $\sum T$ tăng thêm $m$. Để cuối cùng có $\sum T=n$, tổng của $T$ ban đầu (gọi là $T'$) phải là $n-m$. Do đó $B_{n,m}\to B_{n-m,m}$. Nếu là thao tác thứ hai, số lượng phần tử tăng thêm một và $\sum T$ tăng thêm $1$, nên $B_{n,m}\to B_{n-1,m-1}$.

Cách này vẫn có độ phức tạp thời gian $\Theta(n^2)$.

### Cách giải 3

Xét chia $T$ thành phần $T_1$ gồm các phần tử lớn hơn $\sqrt n$ và phần $T_2$ gồm các phần tử không vượt quá $\sqrt n$. Có thể dùng cách 1 để tính $T_2$, còn số lượng của $T_1$ có thể tính bằng cách sửa nhẹ cách 2: đổi hai thao tác thành "tăng mỗi phần tử trong $T_1$ lên $1$" và "thêm vào $T_1$ một phần tử có giá trị $\lfloor\sqrt n\rfloor+1$". Khi đó dễ viết phương trình chuyển trạng thái.

Chia $n$ thành hai phần $A$ và $B$. Chỉ cần duyệt một phần là phần còn lại được xác định. Tính số lượng $T_1$ thỏa $\sum T_1=A$ và số lượng $T_2$ thỏa $\sum T_2=B$, nhân hai số này với nhau, rồi cộng theo mọi $A$ để được kết quả cuối cùng.

Trong quá trình tính số lượng $T_1$, có $M\le\sqrt n$, nên dùng cách 1 để tính $T_1$ có độ phức tạp $\Theta(n^{3/2})$. Tương tự, khi tính số lượng $T_2$, do $|T_2|\le\dfrac{\sum T_2}{\sqrt n}\le\dfrac n{\sqrt n}=\sqrt n$, dùng cách 2 để tính $T_2$ cũng có độ phức tạp $\Theta(n^{3/2})$. Vì vậy tổng độ phức tạp là $\Theta(n^{3/2})$.
