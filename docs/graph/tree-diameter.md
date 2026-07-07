Đường đi đơn dài nhất giữa hai đỉnh bất kỳ trên cây được gọi là "đường kính" của cây.

Kiến thức cần biết trước: [Cơ bản về cây](./tree-basic.md).

## Dẫn nhập

Một cây có thể có nhiều đường kính, và độ dài của chúng bằng nhau.

Có thể tìm đường kính của cây trong thời gian $O(n)$ bằng hai lần DFS hoặc bằng DP trên cây.

## Hai lần DFS

Trước hết, bắt đầu lần DFS thứ nhất từ một đỉnh bất kỳ $y$, tìm đỉnh xa nhất tính từ $y$ và ký hiệu đỉnh đó là $z$. Sau đó bắt đầu lần DFS thứ hai từ $z$, tìm đỉnh xa nhất tính từ $z$ và ký hiệu đỉnh đó là $z'$. Khi đó $\delta(z,z')$ chính là đường kính của cây.

Nếu đỉnh $z$ mà lần DFS thứ nhất tìm được là một đầu mút của đường kính, thì đỉnh $z'$ mà lần DFS thứ hai tìm được cũng là một đầu mút của đường kính. Chỉ cần chứng minh rằng trong mọi trường hợp, $z$ luôn là một đầu mút của đường kính.

Định lý: Trên một cây, nếu bắt đầu DFS từ một đỉnh bất kỳ $y$, thì đỉnh $z$ xa $y$ nhất tìm được luôn là một đầu mút của đường kính.

???+ note "Chứng minh"
    Chứng minh bằng phản chứng. Gọi đỉnh xuất phát là $y$. Giả sử đường kính thật sự là $\delta(s,t)$, còn đỉnh $z$ xa $y$ nhất do lần DFS thứ nhất từ $y$ tìm được không phải là $t$ hay $s$. Xét ba trường hợp:
    
    -   Nếu $y$ nằm trên $\delta(s,t)$:
    
    ![Trường hợp y nằm trên đường s-t](./images/tree-diameter1.svg)
    
    Có $\delta(y,z) > \delta(y,t) \Longrightarrow \delta(x,z) > \delta(x,t) \Longrightarrow \delta(s,z) > \delta(s,t)$, mâu thuẫn với việc $\delta(s,t)$ là đường đi đơn dài nhất giữa hai đỉnh bất kỳ trên cây.
    
    -   Nếu $y$ không nằm trên $\delta(s,t)$ và $\delta(y,z)$ có đoạn đường trùng với $\delta(s,t)$:
    
    ![Trường hợp y không nằm trên s-t và y-z có đoạn trùng với s-t](./images/tree-diameter2.svg)
    
    Có $\delta(y,z) > \delta(y,t) \Longrightarrow \delta(x,z) > \delta(x,t) \Longrightarrow \delta(s,z) > \delta(s,t)$, mâu thuẫn với việc $\delta(s,t)$ là đường đi đơn dài nhất giữa hai đỉnh bất kỳ trên cây.
    
    -   Nếu $y$ không nằm trên $\delta(s,t)$ và $\delta(y,z)$ không có đoạn đường nào trùng với $\delta(s,t)$:
    
    ![Trường hợp y không nằm trên s-t và y-z không có đoạn trùng với s-t](./images/tree-diameter3.svg)
    
    Có $\delta(y,z) > \delta(y,t) \Longrightarrow \delta(x',z) > \delta(x',t) \Longrightarrow \delta(x,z) > \delta(x,t) \Longrightarrow \delta(s,z) > \delta(s,t)$, mâu thuẫn với việc $\delta(s,t)$ là đường đi đơn dài nhất giữa hai đỉnh bất kỳ trên cây.
    
    Tóm lại, trong cả ba trường hợp giả thiết đều dẫn tới mâu thuẫn, nên định lý được chứng minh.

???+ warning "Cạnh trọng số âm"
    Chứng minh ở trên dựa trên tiền đề rằng mọi cạnh đều có trọng số không âm. Nếu trên cây có cạnh trọng số âm thì chứng minh trên không còn đúng. Vì vậy, khi tồn tại cạnh trọng số âm, không thể áp dụng phương pháp hai lần DFS để tìm đường kính.

Nếu cần tìm tất cả các đỉnh trên một đường kính, trong quá trình DFS lần thứ hai có thể lưu đỉnh liền trước của mỗi đỉnh. Khi đó chỉ cần bắt đầu từ một đầu mút của đường kính và truy vết theo các đỉnh liền trước là có thể duyệt tất cả các đỉnh trên đường kính.

## DP trên cây

### Phương pháp 1

Khi lấy $1$ làm gốc của cây, với mỗi đỉnh được xem là gốc của một cây con, ghi lại độ dài đường đi dài nhất có thể kéo dài xuống dưới từ đỉnh đó là $d_1$ và độ dài đường đi dài thứ hai là $d_2$ (không có cạnh chung với đường đi dài nhất). Khi đó đường kính là giá trị lớn nhất trong các giá trị $d_1 + d_2$ tại mỗi đỉnh.

DP trên cây có thể tìm đường kính của cây cả khi tồn tại cạnh trọng số âm.

Nếu cần tìm tất cả các đỉnh trên một đường kính, trong quá trình DP có thể lưu đỉnh con tương ứng với đường đi dài nhất và đường đi dài thứ hai có thể kéo dài xuống dưới từ mỗi đỉnh (định nghĩa như trên). Khi cập nhật đáp án $d$, đồng thời lưu đỉnh $u$ đạt giá trị $d = d_1[u] + d_2[u]$. Sau đó truy vết theo hai nhánh con tương ứng với đường đi dài nhất và đường đi dài thứ hai bắt đầu từ $u$; với cây đã chọn gốc theo DP này, chỉ cần truy vết xuống theo các con đã lưu để duyệt tất cả các đỉnh trên đường kính.

### Phương pháp 2

Phần này trình bày một cách DP trên cây chỉ dùng một mảng.

Định nghĩa $dp[u]$ là đường đi dài nhất bắt đầu từ $u$ trong cây con gốc $u$. Khi đó dễ suy ra công thức chuyển: $dp[u] = \max(dp[u], dp[v] + w(u, v))$, trong đó $v$ là đỉnh con của $u$, còn $w(u, v)$ biểu thị trọng số của cạnh $(u,v)$.

Có thể cập nhật đường kính bằng cách xét giá trị lớn nhất của tổng hai nhánh con khác nhau cùng xuất phát từ một đỉnh. Vì vậy, trong quá trình DP, trước khi cập nhật $dp[u]$, chỉ cần tính $d = \max(d, dp[u] + dp[v] + w(u, v))$ là có thể tính được đường kính $d$.

## Ví dụ

???+ example "[Luogu B4016 Đường kính của cây](https://www.luogu.com.cn/problem/B4016)"
    Cho một cây có $n$ đỉnh, yêu cầu tìm độ dài đường kính của cây. $1\leq n\leq 10^5$.

??? note "Cài đặt tham khảo dùng hai lần DFS"
    ```cpp
    --8<-- "docs/graph/code/tree-diameter/tree-diameter_1.cpp"
    ```

??? note "Cài đặt tham khảo DP trên cây dùng hai mảng"
    ```cpp
    --8<-- "docs/graph/code/tree-diameter/tree-diameter_2.cpp"
    ```

??? note "Cài đặt tham khảo DP trên cây dùng một mảng"
    ```cpp
    --8<-- "docs/graph/code/tree-diameter/tree-diameter_3.cpp"
    ```

## Tính chất

Đường kính của cây có tính chất sau: nếu tất cả các cạnh của cây đều có trọng số dương, thì trung điểm của mọi đường kính của cây trùng nhau.

???+ note "Chứng minh"
    Chứng minh: Dùng phản chứng. Giả sử có hai đường kính có trung điểm không trùng nhau, lần lượt là $\delta(s,t)$ và $\delta(s',t')$, với trung điểm tương ứng là $x$ và $x'$. Khi đó $\delta(s,x) = \delta(x,t) = \delta(s',x') = \delta(x',t')$.
    
    ![Trung điểm của mọi đường kính trong cây không có cạnh âm trùng nhau](./images/tree-diameter4.svg)
    
    Có $\delta(s,t') = \delta(s,x) + \delta(x,x') + \delta(x',t') > \delta(s,x) + \delta(x,t) = \delta(s,t)$, mâu thuẫn với việc $\delta(s,t)$ là đường đi đơn dài nhất giữa hai đỉnh bất kỳ trên cây. Do đó tính chất được chứng minh.

## Bài tập

-   [CodeChef, Đường kính của cây](https://www.codechef.com/problems/DTREE)
-   [Educational Codeforces Round 35, Problem F, Phá hủy cây](https://codeforces.com/contest/911/problem/F)
-   [ZOJ 3820 Xây trạm cứu hỏa](https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?problemSetProblemId=91827369872&page=28)
-   [CEOI2019/CodeForces 1192B. Đường kính động](https://codeforces.com/contest/1192/problem/B)
-   [ICPC 2019 Shanghai Regional Online Contest, Định tuyến tia chớp I](https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-A2290)
-   [NOIP2007 Nhóm nâng cao, Lõi của mạng cây](https://www.luogu.com.cn/problem/P1099)
-   [SDOI2011 Chữa cháy](https://www.luogu.com.cn/problem/P2491)
-   [APIO2010 Tuần tra](https://www.luogu.com.cn/problem/P3629)
