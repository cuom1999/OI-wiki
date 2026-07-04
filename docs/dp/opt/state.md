author: Marcythm, partychicken, Xeonacid, hhc0001

## Tổng quan

Khi tối ưu DP, không chỉ có thể bắt đầu từ quá trình chuyển trạng thái để tăng tốc chuyển. Đôi khi cũng có thể bắt đầu từ định nghĩa trạng thái, thay đổi cách thiết kế trạng thái để giảm độ phức tạp.

Điểm khó là phần lớn kiểu tối ưu này không có tính phổ quát cao, tức không thể áp dụng theo khuôn mẫu cho nhiều bài khác nhau. Vì vậy, phần dưới sẽ đi từ các ví dụ cụ thể, cố gắng gợi mở cách nghĩ để người đọc tham khảo.

## Ví dụ 1

???+ note "Đề bài"
    Cho hai chuỗi $A,B$ có độ dài lần lượt là $n,m$ và chỉ gồm chữ cái thường. Hãy tìm dãy con chung dài nhất của $A,B$. $(n\le 10^6,m\le 10^3)$

### Cách giải đơn giản

Thoạt nhìn đây là một bài mẫu rất quen thuộc.

Định nghĩa trạng thái $f_{i,j}$ là độ dài dãy con chung dài nhất của $i$ ký tự đầu của $A$ và $j$ ký tự đầu của $B$. Khi đó:

$$
f_{i,j}=
\begin{cases}
\max(f_{i-1,j},f_{i,j-1}) & ,A_i \neq B_j \\
f_{i-1,j-1}+1 & ,A_i = B_j 
\end{cases}
$$

Cách làm trên có độ phức tạp thời gian $O(nm)$, không thể vượt qua bài này.

### Cách giải tốt hơn

Suy nghĩ kỹ hơn, ta thấy một tính chất: đáp án cuối cùng không vượt quá $m$.

Tiếp tục xét kỹ, LCS có một tính chất tham lam nhất định.

Đổi định nghĩa trạng thái: $f_{i,j}$ là độ dài tiền tố ngắn nhất của $A$ sao cho LCS với $i$ ký tự đầu của $B$ có độ dài $j$ (tức là hoán đổi đáp án trong cách đơn giản với chiều trạng thái thứ nhất).

Có thể tiền xử lý, với mỗi vị trí của $A$, vị trí xuất hiện tiếp theo của từng ký tự $a,b,\cdots,z$, rồi chuyển xuôi trong $O(1)$.

Độ phức tạp là $O(m^2+26n)$, đủ để vượt qua bài này.

## Ví dụ 2

???+ note "Đề bài"
    Cho một đồ thị có hướng không trọng số gồm $n$ đỉnh. Hãy xác định đồ thị có tồn tại chu trình Hamilton hay không. $(2\le n\le 20)$

### Cách giải đơn giản

Nhìn vào giới hạn dữ liệu, ta nghĩ tới nén trạng thái.

Đặt $f_{s,i}$ biểu thị liệu có thể xuất phát từ đỉnh $1$, chỉ đi qua các đỉnh trong tập $s$, và tới được đỉnh $i$ hay không. Gọi $g$ là ma trận kề của đồ thị ban đầu. Khi đó:

$$
f_{s, i} = \bigvee_{j\in s, j\neq i}f_{s \setminus \{i\}, j}\wedge g_{j, i} \left(i\in s\right)
$$

Độ phức tạp thời gian là $O(n^2\times 2^n)$; nếu cài đặt tốt có thể qua, nhưng chưa đẹp.

### Cách giải tốt hơn

Trong thiết kế trạng thái trên, mỗi giá trị `dp` chỉ biểu diễn một giá trị `bool`, khá lãng phí.

Có thể với mỗi trạng thái $s$, nén $f_{s,1},f_{s,2},\dots,f_{s,n}$ vào một `int`. Khi đó ma trận kề cũng có thể được nén tương tự, và chuyển trạng thái trong $O(1)$.

Độ phức tạp thời gian là $O(n^2/w\times 2^n)$, đủ để qua bài này, trong đó $w$ là số bit của `int`.

## Ví dụ 3

???+ note "Đề bài"
    Một bài ba lô thông thường. $n$ là số vật phẩm, $m$ là dung lượng ba lô, $v_i,w_i$ lần lượt là thể tích và giá trị của vật phẩm thứ $i$, với $1 \le n \le 10^3$, $1 \le m, v_i \le \color{red}{10^{18}}$, $1 \le \sum w_i \le 10^3$.

### Cách giải đơn giản

Đây là một bài ba lô mẫu.

Định nghĩa trạng thái $f_{i,j}$ là tổng giá trị lớn nhất khi xét $i$ vật phẩm đầu tiên và hiện đã dùng dung lượng $j$ trong ba lô.

Dễ có $f_{i,j}=\max(f_{i-1,j}, f_{i-1,j-v_i}+w_i)$.

Do $v_i\le 10^{18}$, cách này không thể vượt qua bài.

### Cách giải tốt hơn

Hoán đổi đáp án với chiều thứ hai của trạng thái. Đặt $f_{i,j}$ là tổng thể tích nhỏ nhất khi xét $i$ vật phẩm đầu tiên và các vật phẩm trong ba lô có **giá trị bằng $j$**.

Tương tự, dễ có $f_{i,j}=\min(f_{i-1,j}, f_{i-1,j-w_i}+v_i)$.

Chú ý rằng sau khi đổi chiều thứ hai của trạng thái, công thức chuyển cũng phải đổi theo.

Độ phức tạp thời gian là $O(n\sum w_i)$, đủ để vượt qua bài.
