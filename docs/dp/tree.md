author: aaron20100919

DP trên cây là quy hoạch động thực hiện trên cấu trúc cây. Do cây có tính chất đệ quy tự nhiên, DP trên cây thường cũng được thực hiện bằng đệ quy.

## Cơ sở

Xét bài toán sau để giới thiệu quy trình chung của DP trên cây.

???+ note "Bài ví dụ [Luogu P1352 Không có cấp trên trong buổi tiệc](https://www.luogu.com.cn/problem/P1352)"
    Một trường đại học có $n$ nhân viên, đánh số từ $1 \sim N$. Giữa họ có quan hệ cấp trên - cấp dưới, giống như một cây có hiệu trưởng làm gốc; cha của một nút là cấp trên trực tiếp của nút con. Hiện có một buổi tiệc kỷ niệm: mỗi nhân viên được mời sẽ làm tăng chỉ số vui vẻ thêm $a_i$. Tuy nhiên, nếu cấp trên trực tiếp của một nhân viên tham gia buổi tiệc, nhân viên đó không được tham gia. Cần xác định những nhân viên nên được mời để chỉ số vui vẻ là lớn nhất, đồng thời tìm giá trị lớn nhất đó.

Đặt $f(i,0/1)$ là lời giải tối ưu của cây con gốc $i$; chiều thứ hai bằng $0$ nghĩa là $i$ không tham gia buổi tiệc, bằng $1$ nghĩa là $i$ tham gia.

Mỗi trạng thái có hai kiểu quyết định (trong đó các $x$ bên dưới đều là con của $i$):

-   Khi cấp trên không tham gia, cấp dưới có thể tham gia hoặc không tham gia, nên $f(i,0)=\sum\max\{f(x,1),f(x,0)\}$;
-   Khi cấp trên tham gia, mọi cấp dưới trực tiếp đều không tham gia, nên $f(i,1)=\sum f(x,0)+a_i$.

Có thể dùng DFS và cập nhật lời giải tối ưu của nút hiện tại khi quay lui về nút cha.

```cpp
--8<-- "docs/dp/code/tree/tree_1.cpp"
```

Thông thường, trạng thái của DP trên cây là lời giải tối ưu tại nút hiện tại. Trước hết dùng DFS duyệt lời giải tối ưu của mọi cây con, sau đó truyền kết quả lên nút cha để chuyển trạng thái. Cuối cùng, giá trị tại gốc chính là lời giải tối ưu cần tìm.

### Bài tập

-   [HDU 2196 Máy tính](https://acm.hdu.edu.cn/showproblem.php?pid=2196)

-   [POJ 1463 Trò chơi chiến lược](http://poj.org/problem?id=1463)

-   [\[POI2014\] FAR-FarmCraft](https://www.luogu.com.cn/problem/P3574)

## Ba lô trên cây

Ba lô trên cây, nói đơn giản, là sự kết hợp giữa bài toán ba lô và DP trên cây.

???+ note "Bài ví dụ [Luogu P2014 CTSC1997 Chọn môn](https://www.luogu.com.cn/problem/P2014)"
    Có $n$ môn học, môn thứ $i$ có số tín chỉ là $a_i$. Mỗi môn có không hoặc một môn tiên quyết; nếu một môn có tiên quyết, cần học xong môn tiên quyết trước rồi mới có thể học môn đó.
    
    Một học sinh muốn học $m$ môn. Cần tìm số tín chỉ lớn nhất có thể đạt được.
    
    $n,m \leq 300$

Tính chất mỗi môn có nhiều nhất một môn tiên quyết tương tự với tính chất mỗi nút trong cây có gốc có nhiều nhất một nút cha.

Vì vậy có thể dựng cây dựa trên tính chất này, và toàn bộ các môn học tạo thành một rừng. Để thuận tiện, thêm một môn học có $0$ tín chỉ (đánh số là $0$) làm môn tiên quyết của mọi môn không có tiên quyết; khi đó rừng được biến thành một cây có gốc là môn $0$.

Đặt $f(u,i,j)$ là số tín chỉ lớn nhất trong cây con gốc $u$ khi đã duyệt $i$ cây con đầu tiên của nút $u$ và chọn $j$ môn.

Quá trình chuyển trạng thái kết hợp đặc điểm của DP trên cây và [DP ba lô](./knapsack.md). Cần duyệt từng con $v$ của $u$, đồng thời duyệt số môn được chọn trong cây con gốc $v$, rồi gộp kết quả của cây con vào $u$.

Gọi số con của nút $x$ là $s_x$, kích thước cây con gốc $x$ là $\textit{siz}_x$, phương trình chuyển trạng thái là:

$$
f(u,i,j)=\max_{v,k \leq j,k \leq \textit{siz}_v} f(u,i-1,j-k)+f(v,s_v,k)
$$

Cần lưu ý các điều kiện ràng buộc trong phương trình trên để tránh truy cập các trạng thái vô nghĩa.

Chiều thứ hai của $f$ có thể được lược bỏ bằng mảng cuộn. Khi đó cần duyệt $j$ theo thứ tự giảm.

Có thể chứng minh cách làm này có độ phức tạp thời gian $O(nm)$[^note1].

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/tree/tree_2.cpp"
    ```

### Bài tập

-   [「CTSC1997」Chọn môn](https://www.luogu.com.cn/problem/P2014)

-   [「JSOI2018」Hành động thâm nhập](https://loj.ac/problem/2546)

-   [「SDOI2017」Cây táo](https://loj.ac/problem/2268)

-   [「Codeforces Round 875 Div. 1」Problem D. Mex Tree](https://codeforces.com/contest/1830/problem/D)

## DP đổi gốc

Trong DP trên cây, bài toán DP đổi gốc còn được gọi là quét hai lần. Thường bài toán không chỉ định sẵn gốc, và việc thay đổi gốc sẽ ảnh hưởng tới một số giá trị, chẳng hạn tổng độ sâu của các nút con hoặc tổng trọng số đỉnh.

Thông thường cần hai lần DFS: lần DFS thứ nhất tiền xử lý các thông tin như độ sâu, tổng trọng số đỉnh; lần DFS thứ hai thực hiện quy hoạch động đổi gốc.

Tiếp theo là một số ví dụ minh họa cho nội dung này.

???+ note "Bài ví dụ [\[POI2008\] STA-Station](https://www.luogu.com.cn/problem/P3478)"
    Cho một cây có $n$ nút. Cần tìm một nút sao cho khi lấy nút đó làm gốc, tổng độ sâu của mọi nút là lớn nhất.

Gọi $u$ là nút hiện tại, $v$ là một nút con của nó. Trước hết dùng $s_i$ để biểu diễn số nút trong cây con gốc $i$, khi đó $s_u=1+\sum s_v$. Cần một lần DFS để tính mọi $s_i$; lần DFS này chính là tiền xử lý, giúp xác định tổng số nút trong cây con khi lấy một nút nào đó làm gốc.

Xét chuyển trạng thái; đây chính là chỗ thể hiện ý tưởng "đổi gốc". Đặt $f_u$ là tổng độ sâu của mọi nút khi lấy $u$ làm gốc.

$f_v\leftarrow f_u$ biểu diễn việc đổi gốc, tức chuyển từ cây gốc $u$ sang cây gốc $v$. Trong quá trình đổi gốc, việc lấy $v$ hoặc $u$ làm gốc sẽ làm thay đổi độ sâu của các nút trong cây con. Cụ thể:

-   Mọi nút trong cây con của $v$ đều giảm độ sâu đi một, nên tổng độ sâu giảm $s_v$;

-   Mọi nút không nằm trong cây con của $v$ đều tăng độ sâu thêm một, nên tổng độ sâu tăng $n-s_v$.

Từ hai điều kiện này suy ra phương trình chuyển trạng thái $f_v=f_u-s_v+n-s_v=f_u+n-2\times s_v$.

Vì vậy, trong lần DFS thứ hai, duyệt toàn bộ cây và chuyển trạng thái theo $f_v=f_u+n-2\times s_v$ sẽ tính được tổng độ sâu khi lấy từng nút làm gốc. Cuối cùng chỉ cần duyệt một lần các tổng độ sâu này để lấy đáp án.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/tree/tree_3.cpp"
    ```

### Bài tập

-   [Atcoder Educational DP Contest, Bài V, Cây con](https://atcoder.jp/contests/dp/tasks/dp_v)

-   [Educational Codeforces Round 67, Bài E, Tô màu cây](https://codeforces.com/contest/1187/problem/E)

-   [POJ 3585 Bậc tích lũy](http://poj.org/problem?id=3585)

-   [\[USACO10MAR\] Cuộc tụ họp bò lớn G](https://www.luogu.com.cn/problem/P2986)

-   [CodeForce 708C Trọng tâm](http://codeforces.com/problemset/problem/708/C)

## Tài liệu tham khảo và chú thích

[^note1]: [Chứng minh độ phức tạp của kiểu DP ba lô gộp cây con - blog CSDN của LYD729](https://blog.csdn.net/lyd_7_29/article/details/79854245)
