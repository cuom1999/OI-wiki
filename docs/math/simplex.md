Kiến thức nền: [Cơ sở quy hoạch tuyến tính](./linear-programming.md)

<span id="mở-đầu"></span>
## Mở đầu

Trong thi thuật toán, phương pháp đơn hình thường được dùng để giải các bài toán quy hoạch tuyến tính. Tuy nhiên, phần lớn bài toán quy hoạch tuyến tính gặp trong thi đấu có cấu trúc đặc biệt hơn và thường có thể chuyển thành bài toán luồng mạng, nên phương pháp đơn hình không được dùng thường xuyên, và hiệu quả cũng không bằng các thuật toán chuyên biệt cho luồng mạng.

<span id="khái-niệm-cơ-bản"></span>
## Khái niệm cơ bản

Giả sử cần giải bài toán quy hoạch tuyến tính [dạng chuẩn](./linear-programming.md#dạng-chuẩn) sau, có $n$ biến quyết định và $m+n$ ràng buộc:

$$
\begin{aligned}
\min_{x}\; & z = c^Tx \\
\text{subject to }& Ax = b, \\
& x \ge 0.
\end{aligned}
$$

Không mất tính tổng quát, giả sử hệ phương trình tuyến tính do $m$ ràng buộc đẳng thức này xác định có nghiệm, và $A$ đầy hạng. Khi đó $\operatorname{rank}A = m \le n$.

<span id="một-ví-dụ"></span>
### Một ví dụ

Trước khi mô tả chặt chẽ các bước của phương pháp đơn hình, phần này xét một ví dụ cụ thể để dễ hiểu hơn.

???+ example "Ví dụ"
    Xét bài toán quy hoạch tuyến tính
    
    $$
    \begin{aligned}
    \max\; & 10 x_1 + 12 x_2 + 12 x_3 \\
    \text{subject to } & x_1 + 2 x_2 + 2x_3 \le 20, \\
    & 2x_1 + x_2 + 2x_3 \le 20, \\
    & 2x_1 + 2x_2 + x_3 \le 20,\\
    & x_1,x_2,x_3 \ge 0.
    \end{aligned}
    $$
    
    Thêm các biến dư sẽ thu được dạng chuẩn:
    
    $$
    \begin{aligned}
    \min\; & -10 x_1 - 12 x_2 - 12 x_3 \\
    \text{subject to } & x_1 + 2 x_2 + 2x_3 + x_4 = 20, \\
    & 2x_1 + x_2 + 2x_3 + x_5 = 20, \\
    & 2x_1 + 2x_2 + x_3 + x_6 = 20,\\
    & x_1,x_2,x_3,x_4,x_5,x_6 \ge 0.
    \end{aligned}
    $$
    
    Quan sát các ràng buộc đẳng thức của bài toán này, chúng thực ra biểu diễn các biến $x_4,x_5,x_6$ theo các biến $x_1,x_2,x_3$. Viết lại bài toán một chút, ta có
    
    $$
    \begin{array}{rrrrrr}
    \min_{x_i\ge 0}  &  z  = &  0 &  -10x_1 &  -12x_2 &  -12x_3\;\\
    \text{subject to}& x_4 = & 20 &    -x_1 &   -2x_2 &   -2x_3, \\
                & x_5 = & 20 &   -2x_1 &    -x_2 &   -2x_3, \\
                & x_6 = & 20 &   -2x_1 &   -2x_2 &    -x_3. \\
    \end{array}
    $$
    
    Từ dạng này có thể thấy rõ: nếu đặt $x_1=x_2=x_3=0$, ta thu được một nghiệm khả thi của bài toán gốc
    
    $$
    x = (0,0,0,20,20,20)^T.
    $$
    
    Giá trị tương ứng của nó là $z=0$. Để tiện trình bày, gọi các biến được đặt bằng không $x_1,x_2,x_3$ là biến không cơ sở, và các biến còn lại $x_4,x_5,x_6$ là biến cơ sở.
    
    Nghiệm khả thi này hiển nhiên chưa tối ưu. Nếu tăng thích hợp các giá trị $x_1,x_2,x_3$ mà vẫn giữ $x_4,x_5,x_6$ không âm, nghiệm vẫn khả thi. Hơn nữa, vì hệ số của $x_1,x_2,x_3$ trong hàm mục tiêu đều âm nghiêm ngặt, tăng chúng chắc chắn làm giảm giá trị hàm mục tiêu. Chẳng hạn, ta có thể chọn tăng $x_1$. Để giảm hàm mục tiêu nhiều nhất, cần tăng $x_1$ nhiều nhất có thể. Nhưng để nghiệm vẫn khả thi, cần bảo đảm $x_4,x_5,x_6\ge 0$. Vì vậy $x_1$ nhiều nhất có thể tăng tới
    
    $$
    \min\left\{\dfrac{20}{1},\dfrac{20}{2},\dfrac{20}{2}\right\} = 10.
    $$
    
    Khi đó nghiệm khả thi trở thành
    
    $$
    x = (10,0,0,10,0,0)^T.
    $$
    
    Vì $x_1$ đã trở thành biến cơ sở, để quay lại dạng ban đầu (ba biến cơ sở được biểu diễn theo ba biến không cơ sở), cần chọn một biến không cơ sở mới. Vì $x_5,x_6$ đều bằng không, có thể chọn bất kỳ biến nào trong hai biến đó làm biến không cơ sở và đặt bằng không. Giả sử chọn $x_5$. Thay
    
    $$
    x_1 = 10 - 0.5x_5 - 0.5x_2 - x_3
    $$
    
    vào bài toán ban đầu, ta viết lại được
    
    $$
    \begin{array}{rrrrrr}
    \min_{x_i\ge 0}  &   z = &-100&   +5x_5 &   -7x_2 &   -2x_3\;\\
    \text{subject to}& x_4 = & 10 & +0.5x_5 & -1.5x_2 &    -x_3, \\
                & x_1 = & 10 & -0.5x_5 & -0.5x_2 &    -x_3, \\
                & x_6 = &  0 &    +x_5 &    -x_2 &    +x_3. \\
    \end{array}
    $$
    
    Như vậy ta lại quay về tình huống ban đầu.
    
    Tiếp tục quan sát hàm mục tiêu hiện tại. Hệ số của biến không cơ sở $x_3$ vẫn âm, nên có thể tăng $x_3$. Để bảo đảm $x_4,x_1,x_6\ge 0$, biến $x_3$ chỉ có thể tăng nhiều nhất tới
    
    $$
    \min\left\{\dfrac{10}{1},\dfrac{10}{1}\right\} = 10.
    $$
    
    Chú ý rằng trong biểu thức của $x_6$, hệ số của $x_3$ là dương, nên tăng $x_3$ thế nào cũng không làm $x_6$ âm. Đó là lý do trong tập ngoặc nhọn lần này chỉ có hai phần tử. Khi $x_3$ tăng tới $10$, cả $x_1$ và $x_4$ đều trở thành không, nên có thể chọn một trong hai làm biến không cơ sở mới. Giả sử chọn $x_4$. Khi đó thay
    
    $$
    x_3 = 10 + 0.5x_5 - 1.5x_2 - x_4
    $$
    
    vào bài toán trên, ta được
    
    $$
    \begin{array}{rrrrrr}
    \min_{x_i\ge 0}  &   z = &-120&   +4x_5 &   -4x_2 &   +2x_4\;\\
    \text{subject to}& x_3 = & 10 & +0.5x_5 & -1.5x_2 &    -x_4, \\
                & x_1 = &  0 &    -x_5 &    +x_2 &    +x_4, \\
                & x_6 = & 10 & +1.5x_5 & -2.5x_2 &    -x_4. \\
    \end{array}
    $$
    
    Chỉ cần thay $x_5=x_2=x_4=0$, ta đọc được nghiệm khả thi hiện tại là
    
    $$
    x = (0,0,10,0,0,10)^T,
    $$
    
    và giá trị tương ứng là $z=-120$.
    
    Lặp lại thao tác trước. Vì hệ số của $x_2$ âm, có thể tăng nó; nhưng để giữ $x_3,x_6$ không âm, chỉ có thể tăng tới
    
    $$
    \min\left\{\dfrac{10}{1.5},\dfrac{10}{2.5}\right\} = 4.
    $$
    
    Vì giá trị nhỏ nhất trong ngoặc nhọn xuất hiện ở biểu thức của biến $x_6$, biến này sẽ trở thành không khi $x_2=4$. Thay biểu thức
    
    $$
    x_2 = 4 + 0.6x_5 - 0.4x_6 - 0.4x_4
    $$
    
    vào bài toán trên, ta viết lại được
    
    $$
    \begin{array}{rrrrrr}
    \min_{x_i\ge 0}  &   z = &-136& +1.6x_5 & +1.6x_6 & +3.6x_4\;\\
    \text{subject to}& x_3 = &  4 & -0.4x_5 & +0.6x_6 & -0.4x_4, \\
                & x_1 = &  4 & -0.4x_5 & -0.4x_6 & +0.6x_4, \\
                & x_2 = &  4 & +1.5x_5 & -2.5x_6 &    -x_4. \\
    \end{array}
    $$
    
    Vẫn đặt các biến không cơ sở $x_5,x_6,x_4$ bằng không, ta được nghiệm khả thi hiện tại
    
    $$
    x = (4,4,4,0,0,0)^T.
    $$
    
    Giá trị tương ứng là $z=-136$.
    
    Vì mọi hệ số của biến không cơ sở trong hàm mục tiêu đều dương, không thể tiếp tục cải thiện hàm mục tiêu theo quá trình trên. Do đó nghiệm khả thi hiện tại là nghiệm tối ưu, và thuật toán dừng.

Trong ví dụ này, thuật toán bắt đầu từ một nghiệm khả thi, liên tục cải thiện hàm mục tiêu cho tới khi không thể cải thiện nữa. Đây chính là ý tưởng cơ bản của phương pháp đơn hình.

<span id="nghiệm-cơ-bản-khả-thi"></span>
### Nghiệm cơ bản khả thi

Vì $A$ đầy hạng, luôn có thể chọn một tập con $B\subseteq\{1,2,\cdots,n\}$ kích thước $m$ sao cho $A_B$ là ma trận vuông khả nghịch. Từ đó, có thể biểu diễn $x_B$ theo các biến còn lại $x_N$:

$$
x_B = A_B^{-1}b - A_B^{-1}A_Nx_N.
$$

Trong đó, $N=\{1,2,\cdots,n\}\setminus B$; các ma trận $A_B,A_N$ lần lượt là các ma trận con gồm các cột có chỉ số $i\in B$ và $i\in N$ của ma trận $A$; các vector $x_B,x_N$ lần lượt là các vector con gồm các thành phần có chỉ số $i\in B$ và $i\in N$ của vector $x$. Nếu $i\in B$, gọi $x_i$ là **biến cơ sở** (basic variable); ngược lại gọi $x_i$ là **biến không cơ sở** (non-basic variable). Toàn bộ các biến cơ sở gọi là một **cơ sở** (basis); bài này dùng tập chỉ số tương ứng $B$ để biểu diễn một cơ sở.

???+ tip "\"Cơ sở\""
    Tên gọi "cơ sở" có thể hiểu từ góc nhìn đại số tuyến tính. Gọi $V$ là không gian tuyến tính sinh bởi toàn bộ các vector cột của $A$. Khi đó, các vector cột ứng với cơ sở $B$ chính là một cơ sở của không gian $V$.

Trong biểu thức của biến cơ sở $x_B$, đặt $x_N=0$, ta được một nghiệm của toàn bộ các ràng buộc đẳng thức[^notation]

$$
x = (x_B,x_N) = (A_B^{-1}b,0).
$$

Nghiệm thu được như vậy gọi là một **nghiệm cơ bản** (basic solution) của bài toán quy hoạch tuyến tính. Nếu nó còn thỏa mãn mọi ràng buộc không âm, tức $x\ge 0$, thì nó cũng là một nghiệm khả thi của bài toán gốc, và gọi là **nghiệm cơ bản khả thi** (basic feasible solution, BFS). Trong quá trình lặp của phương pháp đơn hình, cần luôn giữ nghiệm hiện tại là một nghiệm cơ bản khả thi.

<span id="xoay-trục"></span>
### Xoay trục

Mỗi lần lặp của phương pháp đơn hình gọi là một lần **xoay trục** (pivoting). Về kết quả, mỗi lần xoay trục luôn loại bỏ một biến cơ sở cũ, thêm vào một biến cơ sở mới, qua đó cải thiện giá trị hàm mục tiêu.

???+ tip "\"Xoay trục\""
    Tên gọi "xoay trục" cũng có thể hiểu từ góc nhìn đại số tuyến tính. Như đã nói, các vector cột ứng với cơ sở $B$ là một cơ sở của không gian $V$, và chúng tương ứng với một hệ trục tọa độ của $V$ trong biểu diễn theo cơ sở đó. Vì vậy, quá trình xoay trục chính là quá trình xoay một trục tọa độ sang vị trí mới.

Để xác định biến cơ sở cần thêm vào, ta biểu diễn hàm mục tiêu bằng các biến không cơ sở:

$$
\begin{aligned}
c^Tx &= c^T_Bx_B + c^T_Nx_N \\
&= c_B^TA_B^{-1}b + (c_N^T - c_B^TA_B^{-1}A_N)x_N.
\end{aligned}
$$

Đặt $x_N=0$ sẽ cho giá trị hàm mục tiêu tại nghiệm cơ bản khả thi hiện tại: $z=c_B^TA_B^{-1}b$. Các hệ số của hạng thứ hai trong biểu thức biểu thị lượng thay đổi của hàm mục tiêu khi $x_N$ thay đổi:

$$
\tilde c_N = \dfrac{\partial z}{\partial x_N} = c_N - A_N^T(A_B^{-1})^Tc_B.
$$

Chú ý $c_B - A_B^T(A_B^{-1})^Tc_B = 0$, nên có thể gọi vector

$$
\tilde c = (\tilde c_B^T,\tilde c_N^T)^T = c - A^T(A_B^{-1})^Tc_B
$$

là **chi phí rút gọn** (reduced cost) của bài toán quy hoạch tuyến tính tại nghiệm cơ bản khả thi $x$. Thành phần $\tilde c_i<0$ nói rằng tăng giá trị biến $x_i$ có thể cải thiện hàm mục tiêu của bài toán gốc. Biến như vậy chỉ có thể là biến không cơ sở; nó gọi là **biến vào cơ sở** (entering variable) của lần xoay trục này. Sau khi xoay trục, $x_i$ sẽ trở thành biến cơ sở, không còn luôn bị đặt bằng không nữa (nhưng vẫn có thể bằng không).

Sau khi chọn biến vào cơ sở, còn cần chọn biến cơ sở cũ sẽ bị loại bỏ. Để làm vậy, chỉ cần xác định trong quá trình tăng $x_i$, biến cơ sở hiện có nào trở thành không đầu tiên. Thay $x_N=(x_i,x_{N\setminus\{i\}})=(x_i,0)$ vào biểu thức của $x_B$, ta có

$$
x_B = A_B^{-1}b - A_B^{-1}A_ix_i.
$$

Vì vậy lượng tăng tối đa của $x_i$ bằng

$$
\theta = \min\left\{\dfrac{(A_B^{-1}b)_j}{(A_B^{-1}A_i)_j}:(A_B^{-1}A_i)_j>0\right\}.
$$

Biến trở thành không đầu tiên là biến cơ sở $x_{B_j}$ ứng với chỉ số $j$ làm biểu thức này đạt giá trị nhỏ nhất. Nó cũng là "nút thắt" trong quá trình tăng $x_i$: nếu tiếp tục tăng $x_i$, $x_{B_j}$ sẽ trở thành âm. Biến này gọi là **biến ra khỏi cơ sở** (leaving variable). Cách xác định biến ra khỏi cơ sở gọi là **kiểm tra tỉ số nhỏ nhất** (minimum ratio test).

Giả sử biến vào cơ sở là $x_i$, biến ra khỏi cơ sở là $x_{i'}$. Sau khi xoay trục, các biến cơ sở là $x_{B\setminus\{i\}\cup\{i'\}}$, còn các biến không cơ sở là $x_{N\setminus\{i'\}\cup\{i\}}$.

<span id="điều-kiện-dừng"></span>
### Điều kiện dừng

Phương pháp đơn hình là quá trình bắt đầu từ một nghiệm cơ bản khả thi rồi liên tục xoay trục. Phần trước mô tả xoay trục chưa đầy đủ, vì bỏ qua một số trường hợp đặc biệt. Một số trường hợp tương ứng với việc thuật toán dừng, một số khác cần xử lý thêm.

Trước hết, biến vào cơ sở có thể không tồn tại, tức $\tilde c\ge 0$. Khi đó không còn cách cải thiện giá trị tối ưu, điều này cho thấy nghiệm cơ bản khả thi hiện tại là nghiệm tối ưu và thuật toán dừng. Để chứng minh chặt chẽ điều này cần dùng [điều kiện bù trừ độ lỏng](./linear-programming.md#điều-kiện-bù-trừ-độ-lỏng). Đặt $y=(A_B^{-1})^Tc_B$. Chú ý rằng trong toàn bộ quá trình thuật toán, $x$ luôn được giữ là nghiệm khả thi, và điều kiện bù trừ độ lỏng luôn đúng:

$$
x^T(c-A^Ty) = \tilde c^Tx = \tilde c_B^Tx_B + \tilde c_N^Tx_N = 0.
$$

Do đó, chỉ cần $y$ là nghiệm khả thi của bài toán đối ngẫu, tức $A^Ty\le c$, thì có thể kết luận $x$ và $y$ lần lượt là nghiệm tối ưu của bài toán gốc và bài toán đối ngẫu. Điều kiện này chính là $\tilde c\ge 0$, tức không tồn tại biến vào cơ sở.

???+ tip "\"Giá bóng\""
    Vector $y=(A_B^{-1})^Tc_B$ thường gọi là **vector đối ngẫu** (dual vector). Khi nghiệm cơ bản khả thi ứng với $B$ là nghiệm tối ưu của bài toán gốc, vector $y$ là nghiệm tối ưu của bài toán đối ngẫu. Vì vậy, khi dùng phương pháp đơn hình để giải nghiệm tối ưu của bài toán gốc, ta cũng thu được nghiệm tối ưu của bài toán đối ngẫu. Vì vector $y$ là đạo hàm riêng của giá trị hiện tại theo hằng số ràng buộc, tức
    
    $$
    \dfrac{\partial(c^Tx)}{\partial b} = (A_B^{-1})^Tc_B = y,
    $$
    
    nên nó còn gọi là **giá bóng** (shadow price).

Thứ hai, biến ra khỏi cơ sở có thể không tồn tại, tức $A_B^{-1}A_i\le 0$. Khi đó quá trình xoay trục không có "nút thắt" nào; nói cách khác, có thể liên tục tăng $x_i$ để cải thiện hàm mục tiêu cho tới khi nó bằng $-\infty$. Điều này nói rằng bài toán quy hoạch tuyến tính đã cho là không bị chặn, và thuật toán dừng.

Cuối cùng, lựa chọn biến vào cơ sở và biến ra khỏi cơ sở có thể không duy nhất. Cách chọn không thích hợp có thể dẫn tới quá nhiều lần xoay trục, thậm chí làm thuật toán rơi vào vòng lặp và không dừng bình thường. Việc xử lý các trường hợp này hơi phức tạp hơn, cần dùng một số [quy tắc xoay trục](#quy-tắc-xoay-trục) để tránh vòng lặp và giảm số lần xoay trục.

<span id="bảng-đơn-hình"></span>
### Bảng đơn hình

Khi cài đặt quá trình xoay trục, chỉ cần duy trì ma trận hệ số của bài toán quy hoạch tuyến tính sau mỗi lần xoay trục:

$$
\tilde T_B = 
\begin{pmatrix}
-z_B & \tilde c^T_N \\
x & A_B^{-1}A_N
\end{pmatrix}
=
\begin{pmatrix}
-c_B^TA_B^{-1}b & c^T - c_B^TA_B^{-1}A_N \\
A_B^{-1}b & A_B^{-1}A_N 
\end{pmatrix}.
$$

Nó tương ứng với bài toán quy hoạch tuyến tính:

$$
\begin{array}{rrrr}
\min_{x\ge 0}    &       & c_B^TA_B^{-1}b & + \tilde c_N^Tx_N\; \\
\text{subject to}& x_B = & A_B^{-1}b      & - A_B^{-1}A_Nx_N.
\end{array}
$$

Ma trận $\tilde T_B$ gọi là **bảng đơn hình rút gọn** (condensed simplex tableau) của bài toán quy hoạch tuyến tính đối với cơ sở $B$. Góc trên trái $(\tilde T_B)_{00}$ của bảng là giá trị hiện tại lấy dấu đối; phần tử $(\tilde T_B)_{0i}$ ở hàng $0$, cột $i$ là chi phí rút gọn của biến không cơ sở thứ $i$, $x_{N_i}$; phần tử $(\tilde T_B)_{j0}$ ở hàng $j$, cột $0$ là giá trị của biến cơ sở thứ $j$, $x_{B_j}$; còn $A_B^{-1}A_N$ là các hệ số trong biểu thức biểu diễn biến cơ sở $x_B$ theo biến không cơ sở $x_N$.

Dễ thấy mọi thông tin cần cho xoay trục đều có thể lấy trực tiếp từ bảng đơn hình rút gọn. Cụ thể, dùng bảng này, một lần xoay trục gồm các thao tác:

1.  Chọn cột $i=1,\cdots,n-m$ sao cho $(\tilde T_B)_{0i}<0$. Nếu không tồn tại $i$ như vậy, nghiệm hiện tại là nghiệm tối ưu và $-(\tilde T_B)_{00}$ là giá trị tối ưu.
2.  Chọn hàng $j=1,\cdots,m$ sao cho $(\tilde T_B)_{ji}>0$ và $(\tilde T_B)_{j0}/(\tilde T_B)_{ji}$ nhỏ nhất. Nếu không tồn tại $j$ như vậy, bài toán gốc không bị chặn.
3.  Cho biến $x_{N_i}$ vào cơ sở, biến $x_{B_j}$ ra khỏi cơ sở, rồi cập nhật bảng đơn hình.

Bây giờ xét cụ thể cách cập nhật bảng đơn hình. Trước khi cập nhật, hàng $j$ biểu diễn đẳng thức

$$
x_{B_j} = (\tilde T_B)_{j0} - \sum_{i=1}^{n-m}(\tilde T_B)_{ji}x_{N_i}.
$$

Để cập nhật bảng, cần dùng $x_{N\setminus\{N_i\}\cup\{B_j\}}$ để biểu diễn $x_{N_i}$, tức

$$
x_{N_i} = \dfrac{(\tilde T_B)_{j0}}{(\tilde T_B)_{ji}} - \dfrac{1}{(\tilde T_B)_{ji}}x_{B_j} - \sum_{i'\neq i}\dfrac{(\tilde T_B)_{ji'}}{(\tilde T_B)_{ji}}x_{N_{i'}}.
$$

Thay nó vào các phương trình còn lại, ta được

$$
x_{B_{j'}} = \left((\tilde T_B)_{j'0} - (\tilde T_B)_{j'i}\dfrac{(\tilde T_B)_{j0}}{(\tilde T_B)_{ji}}\right) + \dfrac{(\tilde T_B)_{j'i}}{(\tilde T_B)_{ji}}x_{B_j} - \sum_{i'\neq i}\left((\tilde T_B)_{j'i'}-(\tilde T_B)_{j'i}\dfrac{(\tilde T_B)_{ji'}}{(\tilde T_B)_{ji}}\right)x_{N_i}.
$$

Hàng $0$ tương tự, chỉ khác vế trái của đẳng thức trở thành $-z$. Tuy công thức trông phức tạp, khi cài đặt chỉ cần hai bước:

1.  Cập nhật hàng $j$: đặt $\alpha=(\tilde T_B)_{ji}$, sau đó đặt số ở cột $i$ thành $1$, rồi chia toàn bộ hàng cho $\alpha$;
2.  Cập nhật mỗi hàng $j'\neq j$: đặt $\beta=(\tilde T_B)_{j'i}$, sau đó đặt số ở cột $j$ thành $0$, rồi trừ khỏi toàn bộ hàng $\beta$ lần hàng $j$.

???+ tip "\"Bảng đơn hình\""
    **Bảng đơn hình** (simplex tableau) là ma trận
    
    $$
    T_B = 
    \begin{pmatrix}
    -z & \tilde c^T \\
    x & A_B^{-1}A 
    \end{pmatrix}
    =
    \begin{pmatrix}
    -c_B^TA_B^{-1}b & c^T - c_B^TA_B^{-1}A \\
    A_B^{-1}b & A_B^{-1}A 
    \end{pmatrix}.
    $$
    
    So với bảng đơn hình rút gọn, nó có thêm $m$ cột, lần lượt ứng với $m$ biến cơ sở; hơn nữa, cột ứng với biến cơ sở thứ $j$ nhất định là $e_j$, tức vector này nhận giá trị $1$ tại hàng $j$ và $0$ ở các hàng còn lại. Vì các cột này không cung cấp thêm thông tin, khi cài đặt phương pháp đơn hình thường lược bỏ chúng, thu được bảng đơn hình rút gọn.
    
    Dùng bảng đơn hình, ta có thể hiểu các bước cập nhật bảng thuận tiện hơn. Vì mọi bảng đơn hình $T_B$ đều có thể thu được bằng cách nhân trái cùng một ma trận $T_0$ với một ma trận khả nghịch $L_B$ phụ thuộc vào cơ sở:
    
    $$
    T_B=
    \begin{pmatrix}
    -c_B^TA_B^{-1}b & c^T - c_B^TA_B^{-1}A \\
    A_B^{-1}b & A_B^{-1}A 
    \end{pmatrix}
    =
    \begin{pmatrix}
    1 & -c_B^TA_B^{-1} \\
    O & A_B^{-1}
    \end{pmatrix}
    \begin{pmatrix}
    0 & c^T \\
    b & A 
    \end{pmatrix}=L_BT_0,
    $$
    
    nên các bảng đơn hình này và $T_0$ có thể chuyển đổi qua lại bằng một số [phép biến đổi sơ cấp trên hàng](./linear-algebra/elementary-operations.md). Vì vậy khi cập nhật bảng đơn hình, chỉ cần thực hiện biến đổi sơ cấp trên hàng để cột ứng với biến vào cơ sở trở thành $e_j$. Chuyển các thao tác này sang bảng đơn hình rút gọn chính là các bước đã nêu ở trên.

Cài đặt tham khảo để cập nhật bảng đơn hình rút gọn:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/simplex/simplex_0.cpp:pivot"
    ```

Từ cài đặt này có thể thấy độ phức tạp thời gian của một lần cập nhật bảng đơn hình là $O(mn)$. Khi bàn về [quy tắc xoay trục](#quy-tắc-xoay-trục) ở phần sau, ta sẽ thấy độ phức tạp để xác định biến ra khỏi cơ sở và biến vào cơ sở cũng không vượt quá $O(mn)$; do đó độ phức tạp của một lần xoay trục là $O(mn)$.

Để dễ hiểu, dưới đây liệt kê các bước tính chi tiết của ví dụ ở trên bằng bảng đơn hình rút gọn.

???+ example "Ví dụ (tiếp)"
    Ban đầu, bảng đơn hình rút gọn là:
    
    $$
    \begin{array}{|l|c|ccc|}
    \hline
        &    & x_1 & x_2 & x_3 \\
    \hline
        & 0  & -10 & -12 & -12 \\
    \hline
    x_4= & 20 &   1 & 2   &   2 \\
    x_5= & 20 &   2 & 1   &   2 \\
    x_6= & 20 &   2 & 2   &   1 \\
    \hline
    \end{array}
    $$
    
    Theo chi phí rút gọn ở hàng $0$, có thể chọn $x_1,x_2,x_3$ vào cơ sở. Cho $x_1$ vào cơ sở. Theo kiểm tra tỉ số nhỏ nhất, có thể chọn $x_5,x_6$ ra khỏi cơ sở. Cho $x_5$ ra khỏi cơ sở. Bảng đơn hình rút gọn tương ứng được cập nhật thành:
    
    $$
    \begin{array}{|l|c|ccc|}
    \hline
        &    & x_5 & x_2 & x_3 \\
    \hline
        &100 & 5   & -7  & -2  \\
    \hline
    x_4= & 10 &-0.5 & 1.5 &   1 \\
    x_1= & 10 & 0.5 & 0.5 &   1 \\
    x_6= &  0 & -1  & 1   &  -1 \\
    \hline
    \end{array}
    $$
    
    Theo chi phí rút gọn ở hàng $0$, có thể chọn $x_2,x_3$ vào cơ sở. Cho $x_3$ vào cơ sở. Theo kiểm tra tỉ số nhỏ nhất, có thể chọn $x_4,x_1$ ra khỏi cơ sở. Cho $x_4$ ra khỏi cơ sở. Bảng đơn hình rút gọn tương ứng được cập nhật thành:
    
    $$
    \begin{array}{|l|c|ccc|}
    \hline
        &    & x_5 & x_2 & x_4 \\
    \hline
        &120 & 4   & -4  & 2   \\
    \hline
    x_3= & 10 &-0.5 & 1.5 &  1  \\
    x_1= &  0 &  1  & -1  & -1  \\
    x_6= & 10 & -1.5& 2.5 &  1  \\
    \hline
    \end{array}
    $$
    
    Theo chi phí rút gọn ở hàng $0$, chỉ có thể chọn $x_2$ vào cơ sở. Cho $x_2$ vào cơ sở. Theo kiểm tra tỉ số nhỏ nhất, chỉ có thể chọn $x_6$ ra khỏi cơ sở. Cho $x_6$ ra khỏi cơ sở. Dùng các phép biến đổi sơ cấp trên hàng nói trên để cập nhật bảng đơn hình:
    
    $$
    \begin{array}{|l|c|ccc|}
    \hline
        &    & x_5 & x_4  & x_6 \\
    \hline
        &136 & 1.6 & 3.6 & 1.6 \\
    \hline
    x_3= & 4  & 0.4 & 0.4 &-0.6 \\
    x_1= &  4 & 0.4 & -0.6& 0.4 \\
    x_2= &  4 & -0.6& 0.4 & 0.4 \\
    \hline
    \end{array}
    $$
    
    Theo chi phí rút gọn ở hàng $0$, không tồn tại biến vào cơ sở. Vì vậy nghiệm hiện tại
    
    $$
    x=(4,4,4,0,0,0)^T
    $$
    
    là nghiệm tối ưu, với giá trị tối ưu của bài toán tối thiểu hóa là $-136$.

Ngoài việc dùng bảng đơn hình để cài đặt phương pháp đơn hình, còn có thể dùng phương pháp đơn hình sửa đổi (revised simplex method). Nó cải thiện thêm độ phức tạp thời gian và bộ nhớ, giảm độ phức tạp mỗi lần cập nhật xuống $O(m^2)$, đặc biệt hiệu quả khi $m\ll n$ hoặc $A$ là ma trận thưa.

<span id="nền-tảng-hình-học"></span>
## Nền tảng hình học

Phần này giới thiệu nền tảng hình học của phương pháp đơn hình.

Phân tích [miền khả thi và nghiệm của bài toán](./linear-programming.md#miền-khả-thi-và-nghiệm-của-bài-toán) đối với miền khả thi của quy hoạch tuyến tính

$$
\mathcal D = \{x\in\mathbf R^n : Ax = b,~ x\ge 0\}
$$

cho thấy:

-   Nghiệm tối ưu của bài toán quy hoạch tuyến tính (nếu tồn tại) luôn có thể chọn là một đỉnh của miền khả thi $\mathcal D$. Việc giải quy hoạch tuyến tính vì thế chuyển thành tìm trong tất cả nghiệm đỉnh nghiệm có hàm giá trị tối ưu.
-   Tọa độ của mỗi đỉnh đều có thể tìm bằng cách giải hệ phương trình thu được từ $n$ ràng buộc chặt. Với các ràng buộc dạng chuẩn, mọi $m$ ràng buộc đẳng thức nhất định đều chặt; $n-m$ ràng buộc còn lại chỉ có thể chọn từ các ràng buộc không âm. Chọn các ràng buộc không âm này làm ràng buộc chặt tương đương với đặt các biến quyết định tương ứng $x_N$ bằng $0$; khi đó hệ phương trình $Ax = b$ suy biến thành hệ tuyến tính theo $m$ biến quyết định còn lại $x_B$: $A_Bx_B = b$. Nếu $A_B$ khả nghịch, giải được $x_B = A_B^{-1}b$. Như vậy thu được một nghiệm $(x_B,x_N)=(A_B^{-1}b,0)$; nếu $x_B\ge 0$, đây là tọa độ của một đỉnh của $\mathcal D$.

Dễ thấy khái niệm nghiệm đỉnh trùng với nghiệm cơ bản khả thi đã định nghĩa ở trên. Vì vậy, chỉ cần tìm nghiệm tối ưu trong tất cả nghiệm cơ bản khả thi là có thể thu được nghiệm tối ưu của bài toán gốc. Tuy điều này đơn giản hóa bài toán rất nhiều, số đỉnh của miền khả thi là cấp mũ, nên liệt kê toàn bộ là không thực tế.

Để giải quyết khó khăn này, có thể xét việc di chuyển dọc theo [cạnh](./linear-programming.md#miền-khả-thi-và-nghiệm-của-bài-toán) của miền khả thi, từ một đỉnh sang đỉnh kề với nó. Vì hai đỉnh kề nhau nhất định nằm trên cùng một cạnh, chúng thỏa mãn ít nhất $n-1$ ràng buộc chặt giống nhau. Nói cách khác, các ràng buộc chặt ứng với hai đỉnh kề nhau chỉ có thể khác đúng một ràng buộc. Vì vậy, với một nghiệm cơ bản khả thi $x$, chỉ cần thay một biến cơ sở của nó bằng một biến không cơ sở là có thể thu được một nghiệm cơ bản khả thi **kề** (adjacent) $x'$. Đây chính là thao tác xoay trục.

Vì vậy, quá trình phương pháp đơn hình bắt đầu từ một nghiệm cơ bản khả thi, liên tục xoay trục để cải thiện hàm mục tiêu, thực chất là quá trình trên miền khả thi tương ứng: bắt đầu từ một đỉnh, liên tục đi sang đỉnh kề để cải thiện hàm mục tiêu.

???+ example "Ví dụ (tiếp)"
    Trong ví dụ đang xét, miền khả thi là một đa diện ba chiều có năm đỉnh, như hình sau:
    
    ![](./images/simplex-geo.svg)
    
    Quá trình giải ở trên, xét theo trực giác hình học, tương ứng với đường đi sau giữa các đỉnh của đa diện:
    
    $$
    (0,0,0) \rightarrow (0,0,10) \rightarrow (10,0,0) \rightarrow (4,4,4).
    $$

<span id="chi-tiết-cài-đặt"></span>
## Chi tiết cài đặt

Dùng bảng đơn hình đã đủ để giải nhiều bài toán quy hoạch tuyến tính. Tuy nhiên, với trường hợp tổng quát nhất, phương pháp đơn hình vẫn có nhiều chi tiết đáng bàn sâu hơn.

<span id="dạng-dư"></span>
### Dạng dư

[Cách](./linear-programming.md#dạng-chuẩn) chuyển bài toán quy hoạch tuyến tính tổng quát về dạng chuẩn đã được bàn trước đó. Nhưng để tiện dùng phương pháp đơn hình, còn cần bảo đảm ma trận hệ số $A$ đầy hạng. Tuy cách chuyển về dạng chuẩn rồi khử các ràng buộc phụ thuộc tuyến tính là khả thi, để giải đơn giản hơn người ta thường dùng chiến lược sau:

1.  Chuyển bài toán quy hoạch tuyến tính về **dạng bất đẳng thức** (inequality form), tức dạng $\min\{c^Tx : Ax \le b,~ x \ge 0\}$;
2.  Thêm biến dư $s$ để chuyển bài toán về dạng chuẩn: $\min\{c^Tx : Ax + s = b,~ x\ge 0,~ s \ge 0\}$.

Lợi ích của cách làm này là ma trận hệ số $(A,I)$ của dạng chuẩn thu được luôn đầy hạng, và luôn tồn tại nghiệm cơ bản $(x,s)=(0,b)$ (chưa chắc khả thi). Dạng chuẩn đặc biệt này còn gọi là **dạng dư** (slack form).

<span id="nghiệm-cơ-bản-khả-thi-ban-đầu"></span>
### Nghiệm cơ bản khả thi ban đầu

Mô tả phương pháp đơn hình ở trên luôn giả định đã biết một nghiệm cơ bản khả thi. Đôi khi rất dễ tìm một nghiệm như vậy. Chẳng hạn, nếu trong dạng dư nói trên có $b\ge 0$, thì $(x,s)=(0,b)$ là một nghiệm cơ bản khả thi. Đây chính là tình huống trong ví dụ số ở trên.

Với trường hợp tổng quát, có thể dùng **phương pháp hai pha** (two-phase method). Trong phương pháp hai pha, cần chạy phương pháp đơn hình hai lần. Pha thứ nhất giải một bài toán quy hoạch tuyến tính khả thi để tìm một nghiệm cơ bản khả thi của bài toán gốc. Pha thứ hai bắt đầu từ nghiệm cơ bản khả thi này và áp dụng phương pháp đơn hình để giải bài toán gốc.

Giả sử có bài toán dạng chuẩn $\min\{c^Tx : Ax = b \ge 0,~ x\ge 0\}$. Trong pha thứ nhất, cần giải bài toán

$$
\min\{1^Tx_a : Ax + x_a = b,~ x\ge 0,~ s\ge 0\}.
$$

Về bản chất, đây là bài toán quy hoạch tuyến tính khả thi, trong đó biến mới thêm $x_a$ gọi là **biến nhân tạo** (artificial variable). Nó nhất định có nghiệm cơ bản khả thi $(x,x_a)=(0,b)$, nên có thể trực tiếp dùng phương pháp đơn hình để giải. Nếu giá trị tối ưu của bài toán này lớn hơn nghiêm ngặt $0$, thì không tồn tại $x\ge 0$ sao cho $Ax=b$, tức bài toán gốc không khả thi. Nếu giá trị tối ưu bằng $0$, mọi biến nhân tạo trong nghiệm tối ưu chỉ có thể bằng không. Nếu vẫn còn một số biến nhân tạo là biến cơ sở, có thể xoay trục vài lần để đưa chúng ra khỏi cơ sở. Cuối cùng, khi mọi biến nhân tạo đều là biến không cơ sở, nghiệm cơ bản thu được từ pha thứ nhất có thể dùng làm nghiệm cơ bản khả thi ban đầu cho pha thứ hai.

???+ note "Cài đặt pha thứ nhất không đưa biến nhân tạo vào tường minh"
    Khi cài đặt pha thứ nhất, không nhất thiết phải đưa biến nhân tạo vào tường minh. Với cơ sở ban đầu $B$ được chọn tùy ý, ta có
    
    $$
    x_B + A_B^{-1}A_Nx_N = A_B^{-1}b.
    $$
    
    Nếu $(A_B^{-1}b)_j\ge 0$, không cần đưa biến nhân tạo vào; ngược lại, cần đưa thêm biến nhân tạo $x^{-}_{B_j}$:
    
    $$
    x_{B_j} - x^-_{B_j} + (A_B^{-1}A_N)_{(j)}x_N = (A_B^{-1}b)_j.
    $$
    
    Gọi tập chỉ số $L:=\{j:(A_B^{-1}b)_j<0\}$. Khi đó mọi bảng đơn hình của pha một đều thu được từ bảng đơn hình sau bằng một số phép biến đổi sơ cấp trên hàng:
    
    $$
    \begin{array}{|r|c|cccc|}
    \hline
                    &                       & x_N                      & x_{B_{\sim L}} & x_{B_L}  &x_{B_{L}}^- \\  
    \hline
                    & 0                     & 0^T                      & 0^T            & 0^T      & 1^T        \\
    \hline
    x_{B_{\sim L}}=  & (A_B^{-1}b)_{\sim L}  & (A_B^{-1}A_N)_{(\sim L)} & I              &  O       &  O         \\
    x_{B_{L}}^-=     & (A_B^{-1}b)_L         & (A_B^{-1}A_N)_{(L)}      & O              &  I       & -I         \\
    \hline
    \end{array}
    $$
    
    Tương tự việc rút gọn bảng đơn hình thành bảng đơn hình rút gọn, có thể giản lược bảng này một cách thích hợp: nhân trái các hàng $x_{B_{L}}^-$ với $1^T$ rồi cộng vào hàng $0$, sau đó lược bỏ ba nhóm cột cuối:
    
    $$
    \begin{array}{|r|c|cccc|}
    \hline
                    &                      & x_N                      \\  
    \hline
                    & 1^Tb_L               & 1^T(A_B^{-1}A_N)_L       \\
    \hline
    x_{B_{\sim L}}= & (A_B^{-1}b)_{\sim L} & (A_B^{-1}A_N)_{(\sim L)} \\
    -x_{B_{L}}=     & (A_B^{-1}b)_L        & (A_B^{-1}A_N)_L          \\
    \hline
    \end{array}
    $$
    
    Bảng này gần giống bảng đơn hình rút gọn thông thường, chỉ khác là biến ở hàng cuối được đánh dấu dấu âm, biểu thị hàng đó vẫn chứa biến nhân tạo, tức biến dư ban đầu vẫn chưa khả thi. Dùng bảng này, quá trình xoay trục như sau:
    
    1.  Nếu $L=\varnothing$, thuật toán dừng.
    2.  Ngược lại, chọn biến vào cơ sở $x_{N_i}$ theo điều kiện chi phí rút gọn ở hàng $0$ âm. Nếu không tồn tại, bài toán gốc không khả thi và thuật toán dừng.
    3.  Tiếp đó chọn biến ra khỏi cơ sở $x_{B_j}$ theo cột $i$. Vẫn dùng kiểm tra tỉ số nhỏ nhất, nhưng phải đồng thời bảo đảm các biến khả thi hiện tại vẫn khả thi và các biến chưa khả thi hiện tại vẫn chưa khả thi, tức chọn
    
        $$
        \arg\min_{j}\left\{\dfrac{(\tilde T_B)_{j0}}{(\tilde T_B)_{ji}}:(j\notin L\land(\tilde T_B)_{ji}>0)\lor(j\in L\land(\tilde T_B)_{ji}<0)\right\}
        $$
    
        làm hàng chứa biến ra khỏi cơ sở. Nếu có nhiều biến ra khỏi cơ sở như vậy, ưu tiên chọn biến chưa khả thi.
    4.  Cho $x_{N_i}$ vào cơ sở, $x_{B_j}$ ra khỏi cơ sở, rồi cập nhật bảng đơn hình.
    5.  Nếu $j\in L$, đưa $j$ ra khỏi $L$ (tức bỏ dấu âm của hàng đó), đồng thời cộng $1$ vào $(\tilde T_B)_{0i}$.
    
    Có thể lược bỏ các cột chứa biến nhân tạo vì nếu chúng vẫn là biến cơ sở, cột tương ứng là $e_j$ và không cần ghi lại; còn nếu chúng không còn là biến cơ sở, chúng sẽ không vào cơ sở lần nữa và cũng không cần ghi lại. Khi biến nhân tạo ra khỏi cơ sở, cần thay bằng biến không nhân tạo tương ứng; đó chính là mục đích của bước cuối trong quá trình trên.
    
    Cài đặt tham khảo:
    
    ??? example "Cài đặt tham khảo"
        ```cpp
        --8<-- "docs/math/code/simplex/simplex_0.cpp:initialize"
        ```
    
    Trước khi bắt đầu pha một, thêm một hàng để ghi hàm mục tiêu của pha một. Khi xoay trục, xoay toàn bộ bảng, bao gồm cả hàm mục tiêu của pha hai. Như vậy khi pha một kết thúc, hàm mục tiêu của pha hai cũng đã được cập nhật tương ứng và có thể trực tiếp bắt đầu pha hai của phương pháp đơn hình.

Phương pháp hai pha cũng có thể được thực hiện bằng một lần chạy đơn hình. Chỉ cần lấy một số dương đủ lớn $M$, rồi trực tiếp giải bài toán

$$
\min\{c^Tx + M1^Tx_a : Ax + x_a = b,~ x\ge 0,~ s\ge 0\}
$$

để thu được nghiệm tối ưu của bài toán gốc. Khi cài đặt, không gán cho $M$ một giá trị cụ thể mà xem nó như một số dương chưa biết nhưng đủ lớn để tính toán. Phương pháp này gọi là **phương pháp $M$ lớn** (big $M$ method).

???+ warning "Hiệu quả thực tế của thuật toán thô là cấp mũ"
    Vì dạng dư luôn có nghiệm cơ bản ban đầu, chỉ là chưa chắc khả thi, một ý tưởng đơn giản để tìm nghiệm cơ bản khả thi ban đầu là bắt đầu từ một nghiệm cơ bản không khả thi, lặp lại thao tác xoay trục để đưa biến cơ sở không khả thi ra khỏi cơ sở, đồng thời chọn biến không cơ sở ứng với một số âm trên hàng tương ứng vào cơ sở, cho tới khi mọi biến cơ sở đều không âm. Cài đặt tham khảo:
    
    ??? example "Cài đặt tham khảo"
        ```cpp
        --8<-- "docs/math/code/simplex/simplex_2.cpp:initialize"
        ```
    
    Cách làm này tuy đơn giản, nhưng so với phương pháp hai pha, nó không có một hàm mục tiêu mô tả mức độ không khả thi của cơ sở hiện tại, nên thiếu hướng cải thiện rõ ràng. Thử nghiệm thực tế cho thấy so với phương pháp hai pha hoặc phương pháp $M$ lớn thường chỉ cần $O(m)$ lần xoay trục, thuật toán thô này thường cần $O(2^m)$ lần xoay trục, và dễ rơi vào vòng lặp khi $n,m$ lớn. Dù hằng số trong số lần xoay trục của thuật toán thô nhỏ, nó chỉ phù hợp với trường hợp $n,m<50$.

<span id="quy-tắc-xoay-trục"></span>
### Quy tắc xoay trục

Khi xoay trục, nếu có nhiều biến vào cơ sở hoặc biến ra khỏi cơ sở có thể chọn, cần dùng **quy tắc xoay trục** (pivot rule) để quyết định chọn biến nào. Dùng bảng đơn hình, mọi quy tắc bàn trong phần này đều có thể tìm biến vào cơ sở và ra khỏi cơ sở trong thời gian $O(mn)$, nên độ phức tạp của một lần xoay trục vẫn là $O(mn)$.

Việc chọn biến vào cơ sở thường quyết định số lần xoay trục trước khi thuật toán dừng. Các quy tắc thường gặp gồm:

-   Chọn biến vào cơ sở được tìm thấy đầu tiên;
-   Chọn biến vào cơ sở có nhãn nhỏ nhất; (một phần của quy tắc Bland)
-   Chọn biến vào cơ sở có trị tuyệt đối chi phí rút gọn lớn nhất, tức $|c_i|$; (quy tắc Dantzig)
-   Chọn biến vào cơ sở làm cải thiện hàm giá trị nhiều nhất trong một lần xoay trục, tức $|c_i|\theta_i$;
-   Chọn biến vào cơ sở ứng với cạnh dốc nhất, tức cải thiện hàm giá trị trên mỗi đơn vị độ dài di chuyển dọc cạnh lớn nhất, tức $|c_i|/\|A_B^{-1}A_i\|$;
-   Chọn ngẫu nhiên một biến vào cơ sở.

Trong thực tế, quy tắc cạnh dốc nhất có hiệu quả cao nhất[^steepest-edge]. Thông thường người ta cho rằng quy tắc xoay trục thích hợp có thể tìm nghiệm tối ưu của đa số bài toán trong khoảng $2m$ lần xoay trục. Tuy nhiên, với mọi quy tắc xoay trục đã biết hiện nay, đều tồn tại ví dụ được xây dựng đặc biệt[^klee-minty] có thể làm số lần xoay trục tăng tới cấp mũ. Đây chính là lý do phương pháp đơn hình chạy rất tốt trong thực tế nhưng độ phức tạp trường hợp xấu nhất về lý thuyết là cấp mũ.

Việc chọn biến ra khỏi cơ sở thường quyết định thuật toán có rơi vào vòng lặp hay không. Nếu tồn tại nhiều nghiệm cơ bản khả thi có cùng giá trị tối ưu, thuật toán có thể lặp mãi giữa các nghiệm cơ bản khả thi đó. Những tình huống này không thường gặp, nên nhiều cài đặt phương pháp đơn hình không chỉ định quy tắc chọn biến ra khỏi cơ sở. Hai quy tắc thường gặp để tránh vòng lặp là:

-   Quy tắc Bland: luôn chọn biến vào cơ sở và biến ra khỏi cơ sở có nhãn nhỏ nhất.
-   Quy tắc thứ tự từ điển: luôn chọn biến ra khỏi cơ sở $x_{B_j}$ ứng với hàng $j$ thỏa $(A_B^{-1}A_i)_j>0$ và làm bộ

    $$
    \left(\dfrac{(A_B^{-1}b)_j}{(A_B^{-1}A_i)_j},\dfrac{(A_B^{-1})_{j1}}{(A_B^{-1}A_i)_j},\cdots,\dfrac{(A_B^{-1})_{jm}}{(A_B^{-1}A_i)_j}\right)
    $$

    nhỏ nhất theo thứ tự từ điển. Cách chọn biến vào cơ sở không quan trọng.

    Chú ý rằng nếu bài toán quy hoạch tuyến tính ở dạng dư, các đại lượng này đều có thể lấy trực tiếp từ bảng đơn hình $T_B$ dạng đã nêu ở trên; ngược lại, sau khi tìm một nghiệm cơ bản ban đầu (chưa chắc khả thi), có thể dùng các hệ số của các cột ứng với biến cơ sở trong cơ sở ban đầu này (giữ nguyên thứ tự) làm hệ số của $A_B^{-1}$.

Quy tắc Bland có hiệu quả thấp, vì bản thân quy tắc chọn biến vào cơ sở và ra khỏi cơ sở theo cùng một cách, rất dễ làm cùng một biến liên tục vào rồi ra khỏi cơ sở. Tương đối mà nói, quy tắc thứ tự từ điển thực dụng hơn. Quy tắc thứ tự từ điển tương đương với việc nhiễu loạn các tham số trong bài toán quy hoạch tuyến tính[^lexico], làm cho không tồn tại các nghiệm cơ bản khả thi có cùng giá trị tối ưu, và vì vậy không có khả năng lặp.

<span id="cài-đặt-tham-khảo"></span>
## Cài đặt tham khảo

Phần này cung cấp một cài đặt tham khảo của phương pháp đơn hình hai pha dựa trên bảng đơn hình rút gọn.

??? example "[Luogu P13337: Mẫu quy hoạch tuyến tính](https://www.luogu.com.cn/problem/P13337)"
    ```cpp
    --8<-- "docs/math/code/simplex/simplex_0.cpp:full-text"
    ```

<span id="bài-tập-ví-dụ"></span>
## Bài tập ví dụ

???+ example "[NOI2008: Tuyển mộ tình nguyện viên](https://www.luogu.com.cn/problem/P3980)"
    Có tổng cộng $n$ ngày hoạt động cần tuyển tình nguyện viên, trong đó ngày thứ $i$ cần ít nhất $b_i$ tình nguyện viên. Có tất cả $m$ loại tình nguyện viên; loại thứ $j$ có thể phục vụ trong đoạn ngày liên tiếp $[l_j,r_j]$, và chi phí tuyển mỗi người là $c_i$. Hãy tìm phương án tuyển tối ưu sao cho tổng chi phí tuyển tình nguyện viên nhỏ nhất.

??? note "Lời giải"
    Gọi $x_j$ là số tình nguyện viên loại thứ $j$ được tuyển. Khi đó có thể lập bài toán quy hoạch tuyến tính:
    
    $$
    \begin{align*}
    \max_{x}\; & \sum_{j=1}^mc_jx_j \\
    \text{subject to }& \sum_{i=1}^n a_{ij}x_j \ge b_i,~i=1,\cdots,n,\\
    & x_j\ge 0,~j=1,\cdots,m.
    \end{align*}
    $$
    
    Trong đó hệ số
    
    $$
    a_{ij} = 
    \begin{cases}
    1,& l_j\le i\le r_j,\\
    0,& \text{otherwise.}
    \end{cases}
    $$
    
    Bài toán gốc không có nghiệm khả thi ban đầu hiển nhiên. Vì vậy có thể xét [bài toán đối ngẫu](./linear-programming.md#bài-toán-đối-ngẫu):
    
    $$
    \begin{align*}
    \min_{y}\; & \sum_{i=1}^n b_iy_i \\
    \text{subject to } & \sum_{j=1}^na_{ij}y_i \le c_j,~j=1,\cdots,m,\\
    & y_i\ge 0,~i=1,\cdots,n.
    \end{align*}
    $$
    
    Sau khi thêm biến dư, dễ thu được một nghiệm khả thi ban đầu, nên có thể bỏ qua pha thứ nhất và trực tiếp dùng phương pháp đơn hình để giải. Theo nguyên lý đối ngẫu, nghiệm thu được chính là nghiệm của bài toán gốc.
    
    ```cpp
    --8<-- "docs/math/code/simplex/simplex_1.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

-   [Luogu P13337: Mẫu quy hoạch tuyến tính](https://www.luogu.com.cn/problem/P13337)
-   [UOJ#179. Quy hoạch tuyến tính](https://uoj.ac/problem/179)
-   [Luogu P4232: Trốn tìm bên ngoài vô thức](https://www.luogu.com.cn/problem/P4232)
-   [Codeforces 1430 G. Yet Another DAG Problem](https://codeforces.com/problemset/problem/1430/G)
-   [AtCoder Beginner Contest 231 H - Minimum Coloring](https://atcoder.jp/contests/abc231/tasks/abc231_h)

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

-   [Phương pháp đơn hình cho quy hoạch tuyến tính: giải thích rất chi tiết và minh họa](https://www.cnblogs.com/ECJTUACM-873284962/p/7097864.html)
-   [Tuyển tập luận văn đội tuyển tập huấn quốc gia 2016](https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2016%E8%AE%BA%E6%96%87%E9%9B%86.pdf)
-   Introduction to Algorithms
-   Matoušek, Jiří, and Bernd Gärtner. Understanding and using linear programming. Vol. 1. Berlin: Springer, 2007.
-   Inayatullah, Syed, Nasir Touheed, and Muhammad Imtiaz. "A streamlined artificial variable free version of simplex method." PloS one 10, no. 3 (2015): e0116156.
-   Floudas, Christodoulos A., and Panos M. Pardalos, eds. Encyclopedia of optimization. Springer Science & Business Media, 2008.

[^notation]: Về nguyên tắc, vì mọi vector mặc định là vector cột, $(x_B,x_N)$ nên được viết là $(x_B^T,x_N^T)^T$. Nhưng để đơn giản ký hiệu, mọi trường hợp tương tự trong bài này đều viết trực tiếp là $(x_B,x_N)$ và lược bỏ ký hiệu chuyển vị.

[^steepest-edge]: Kết quả thử nghiệm xem trong Forrest, John J., and Donald Goldfarb. "Steepest-edge simplex algorithms for linear programming." Mathematical programming 57, no. 1 (1992): 341-374.

[^klee-minty]: Một phản ví dụ kinh điển có thể xem trong Klee, Victor, and George J. Minty. "How good is the simplex algorithm." Inequalities 3, no. 3 (1972): 159-175.

[^lexico]: Giải thích chi tiết có thể xem trong [bài giảng này](https://misha.fish/archive/docs/3272-fall-2022/lecture8.pdf).
