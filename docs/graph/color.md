## Tô màu đỉnh

(Phần này xét đồ thị vô hướng không có khuyên.)

Tô màu các đỉnh của đồ thị vô hướng sao cho hai đỉnh kề nhau không được cùng màu. Nếu $G$ là $k$-tô màu được nhưng không phải là $(k-1)$-tô màu được, thì $k$ được gọi là số sắc của $G$, ký hiệu là $\chi(G)$.

Với mọi đồ thị $G$, có $\chi(G) \leq \Delta(G) + 1$, trong đó $\Delta(G)$ là bậc cực đại.

### Định lý Brooks

Giả sử đồ thị liên thông không phải là đồ thị đầy đủ và cũng không phải là chu trình lẻ. Khi đó $\chi(G) \leq \Delta(G)$.

#### Chứng minh

???+ note "Chứng minh"
    Đặt $|V(G)|=n$ và dùng quy nạp toán học.
    
    Trước hết, khi $n\leq 3$, mệnh đề đúng.
    
    Tiếp theo, giả sử mệnh đề đã đúng với $n-1$. Cần từng bước tăng cường mệnh đề cần chứng minh.
    
    Không mất tính tổng quát, chỉ cần xét đồ thị $\Delta(G)$-chính quy, vì đồ thị không chính quy có thể xem là thu được bằng cách xóa một số cạnh khỏi một đồ thị chính quy, và quá trình này không ảnh hưởng đến kết luận.
    
    Với một đồ thị chính quy $G$ bất kỳ không phải đồ thị đầy đủ cũng không phải chu trình lẻ, chọn tùy ý một đỉnh $v$ và xét đồ thị con $H:=G-v$. Theo giả thiết quy nạp, $\chi(H)\leq\Delta(H)=\Delta(G)$. Do đó chỉ cần chứng minh rằng chèn lại $v$ vào $H$ không làm thay đổi kết luận.
    
    Đặt $\Delta:=\Delta(G)$. Giả sử $\Delta$ màu được dùng để tô $H$ lần lượt là $c_1,c_2,\dots,c_{\Delta}$, và $\Delta$ đỉnh kề của $v$ là $v_1,v_2,\dots,v_{\Delta}$. Không mất tính tổng quát, giả sử các đỉnh kề này của $v$ có màu đôi một khác nhau; nếu không thì mệnh đề đã được chứng minh.
    
    Tiếp theo, xét đồ thị con $H_{i,j}$ tạo bởi tất cả các đỉnh trong $H$ được tô màu $c_i$ hoặc $c_j$ cùng với tất cả các cạnh giữa chúng. Không mất tính tổng quát, giả sử với hai đỉnh khác nhau bất kỳ $v_i$, $v_j$, chúng luôn nằm trong cùng một thành phần liên thông của $H_{i,j}$. Nếu chúng nằm ở hai thành phần liên thông khác nhau, có thể hoán đổi màu của tất cả các đỉnh trong một thành phần liên thông, khiến $v_i$ và $v_j$ có cùng màu.
    
    > Trong ngữ cảnh này, hoán đổi màu nghĩa là: nếu trong đồ thị chỉ có hai màu $a$ và $b$, thì đổi tất cả các đỉnh đang có màu $a$ thành màu $b$, đồng thời đổi tất cả các đỉnh đang có màu $b$ thành màu $a$.
    
    Gọi thành phần liên thông nói trên là $C_{i,j}$. Khi đó $C_{i,j}$ chỉ có thể là một đường đi từ $v_i$ đến $v_j$. Vì bậc của $v_i$ trong $H$ là $\Delta-1$, các đỉnh kề của $v_i$ trong $H$ phải có màu đôi một khác nhau; nếu không có thể tô lại $v_i$ bằng một màu khác, làm màu của nó trùng với một đỉnh kề khác của $v$. Do đó số đỉnh kề của $v_i$ trong $C_{i,j}$ là 1, và với $v_j$ cũng tương tự. Tiếp theo, lấy một đường đi từ $v_i$ đến $v_j$ trong $C_{i,j}$ và gọi nó là $P$. Nếu $C_{i,j}\ne P$, tô lại màu các đỉnh trên đường đi $P$ theo thứ tự. Gọi $u$ là đỉnh đầu tiên gặp được có bậc lớn hơn 2. Các đỉnh kề của $u$ dùng nhiều nhất $\Delta-2$ màu, nên có thể tô lại $u$, từ đó làm cho $v_i$ và $v_j$ không còn liên thông với nhau.
    
    Khi đó suy ra với ba đỉnh khác nhau bất kỳ $v_i$, $v_j$, $v_k$, có $V(C_{i,j})\cap V(C_{j,k})=\{v_j\}$.
    
    Đến đây việc tăng cường mệnh đề đã hoàn tất.
    
    Phần còn lại rất đơn giản. Trước hết, nếu các đỉnh kề của v đôi một kề nhau, mệnh đề được chứng minh. Ngược lại, giả sử $v_1$ và $v_2$ không kề nhau. Lấy đỉnh kề w của $v_1$ trong $C_{1,2}$, rồi hoán đổi màu trong $C_{1,3}$. Trong đồ thị mới thu được, $w\in V(C_{1,2})\cap V(C_{2,3})$, mâu thuẫn.
    
    Vậy mệnh đề đã được chứng minh.

### Thuật toán Welsh-Powell

Thuật toán Welsh-Powell là một thuật toán tham lam để tìm phương án tô màu khi **không giới hạn trước số màu tối đa**.

Với đồ thị vô hướng không có khuyên G, giả sử $V(G):=\{v_1,v_2,\dots,v_n\}$ thỏa mãn

$\deg(v_i)\geq\deg(v_{i+1}),~\forall 1\leq i\leq n-1$

Số màu thu được sau khi tô theo thuật toán Welsh-Powell không vượt quá $\max_{i=1}^n\min\{\deg(v_i)+1,i\}$, và độ phức tạp thời gian của thuật toán là $O\left(n\max_{i=1}^n\min\{\deg(v_i)+1,i\}\right)=O(n^2)$.

#### Quy trình

1.  Sắp xếp các đỉnh chưa tô màu hiện tại theo bậc giảm dần.
2.  Tô đỉnh đầu tiên bằng một màu chưa từng được dùng.
3.  Lần lượt duyệt các đỉnh tiếp theo. Nếu đỉnh hiện tại **không kề** với mọi đỉnh có màu **giống** đỉnh đầu tiên, thì tô nó bằng cùng màu với đỉnh đầu tiên.
4.  Nếu vẫn còn đỉnh chưa tô màu, quay lại bước 1; nếu không thì kết thúc.

Ví dụ như sau:

![Ban đầu](images/color1.png)

(Sinh bằng [Graph Editor](https://csacademy.com/app/graph_editor/).)

Trước hết, sắp xếp các đỉnh theo bậc giảm dần, thu được:

| Thứ tự                    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9  | 10 | 11 | 12 | 13 |
| ------------------------- | - | - | - | - | - | - | - | - | -- | -- | -- | -- | -- |
| Số hiệu đỉnh              | 4 | 5 | 0 | 2 | 9 | 1 | 3 | 6 | 10 | 12 | 7  | 8  | 11 |
| Bậc                       | 5 | 5 | 4 | 4 | 4 | 3 | 3 | 3 | 3  | 3  | 2  | 2  | 1  |
| $\min\{\deg(v_i)+1,i\}$   | 1 | 2 | 3 | 4 | 5 | 4 | 4 | 4 | 4  | 4  | 3  | 3  | 2  |

Vì vậy, số màu tối đa sau khi tô bằng thuật toán Welsh-Powell là 5.

Ngoài ra, vì đồ thị này có đồ thị con $C_3$, nên số sắc không nhỏ hơn 3.

-   Lần tô màu thứ nhất:

    ![Tô màu 1](images/color2.png)

    Tô các đỉnh số `4 9 3 11`.
-   Lần tô màu thứ hai:

    ![Tô màu 2](images/color3.png)

    Tô các đỉnh số `5 2 6 7 8`.
-   Lần tô màu thứ ba:

    ![Tô màu 3](images/color4.png)

    Tô các đỉnh số `0 1 10 12`.

#### Chứng minh

???+ note "Chứng minh"
    Với đồ thị vô hướng không có khuyên G, giả sử $V(G):=\{v_1,v_2,\dots,v_n\}$ thỏa mãn
    
    $\deg(v_i)\geq\deg(v_{i+1}),~\forall 1\leq i\leq n-1$
    
    Đặt $V_0=\varnothing$. Lấy tập con $V_m$ của $V(G)\setminus\bigcup_{i=0}^{m-1} V_i$, trong đó các phần tử thỏa mãn:
    
    1.  $v_{k_m}\in V_m$, trong đó $k_m=\min\{k:v_k\notin\bigcup_{i=0}^{m-1} V_i\}$.
    2.  Nếu
    
        $\{v_{i_{m,1}},v_{i_{m,2}},\dots,v_{i_{m,l_m}}\}\subset V_m,~i_{m,1}<i_{m,2}<\dots<i_{m,l_m}$
    
        thì $v_j\in V_m$ khi và chỉ khi
    
        1.  $j>i_{m,l_m}$.
        2.  $v_j$ không kề với mọi đỉnh $v_{i_{m,1}},v_{i_{m,2}},\dots,v_{i_{m,l_m}}$.
    
    Nếu tô các đỉnh trong $V_i$ bằng màu thứ $i$, phương án tô màu này chính là phương án do thuật toán Welsh-Powell đưa ra. Đồng thời có:
    
    -   $V_1\neq\varnothing$
    -   $V_i\cap V_j=\varnothing\iff i\neq j$
    -   $\exists \alpha(G)\in\Bbb{N}^*,\forall i>\alpha(G),~\text{sao cho}~ V_i=\varnothing$
    
    Chỉ cần chứng minh:
    
    $\bigcup_{i=1}^{\alpha(G)} V_i=V(G)$
    
    trong đó
    
    $\chi(G)\leq\alpha(G)\leq\max_{i=1}^n\min\{\deg(v_i)+1,i\}$
    
    Bất đẳng thức bên trái đúng. Xét bất đẳng thức bên phải.
    
    Trước hết, suy ra rằng:
    
    Nếu $v\notin\bigcup_{i=1}^mV_i$, thì $v$ kề với ít nhất một đỉnh trong mỗi tập $V_1,V_2,\dots,V_m$, do đó $\deg(v)\geq m$.
    
    Suy ra
    
    $v_j\in\bigcup_{i=1}^{\deg(v_j)+1}V_i$
    
    Mặt khác, dựa trên cách xây dựng dãy $\{V_i\}$, có
    
    $v_j\in\bigcup_{i=1}^j V_i$
    
    Kết hợp hai công thức trên, thu được điều phải chứng minh.

## Tô màu cạnh

Tô màu các cạnh của đồ thị vô hướng sao cho hai cạnh kề nhau có màu khác nhau. Nếu $G$ là $k$-tô màu cạnh được nhưng không phải là $(k-1)$-tô màu cạnh được, thì $k$ được gọi là số sắc cạnh của $G$, ký hiệu là $\chi'(G)$.

### Định lý Vizing

Nếu $G$ là đồ thị đơn, thì $\Delta(G) \leq \chi'(G) \leq \Delta(G) + 1$.

Nếu $G$ là đồ thị hai phía, thì $\chi'(G)=\Delta(G)$.

Khi $n$ là số lẻ ($n \neq 1$), $\chi'(K_n)=n$; khi $n$ là số chẵn, $\chi'(K_n)=n-1$.

### Chứng minh mang tính xây dựng của định lý Vizing cho đồ thị hai phía

???+ note "Chứng minh"
    Thêm các cạnh vào đồ thị hai phía theo thứ tự.
    
    Khi thử thêm cạnh $(x,y)$, tìm màu chưa được dùng có số hiệu nhỏ nhất tại $x$ và tại $y$, giả sử lần lượt là $l_x$ và $l_y$.
    
    Nếu $l_x=l_y$, có thể trực tiếp đặt màu của cạnh này là $l_x$.
    
    Ngược lại, giả sử $l_x<l_y$, có thể thử đổi màu cạnh đi ra từ đỉnh $y$ đang có màu $l_x$ thành $l_y$.
    
    Quá trình đổi màu có thể xem xấp xỉ như một đường tăng hữu hạn và duy nhất bắt đầu từ $y$, lần lượt đi qua các cạnh có màu $l_x,l_y,\cdots$.
    
    Vì đường tăng là hữu hạn, có thể đảo màu tất cả các cạnh trên đường tăng: cạnh vốn có màu $l_x$ được đổi thành $l_y$, còn cạnh vốn có màu $l_y$ được đổi thành $l_x$.
    
    Theo tính chất của đồ thị hai phía, đỉnh $x$ không thể nằm trên đường tăng; nếu không sẽ mâu thuẫn với việc màu chưa dùng nhỏ nhất tại $x$ là $l_x$.
    
    Vì vậy, sau khi tăng, có thể trực tiếp đặt màu của cạnh nối $x$ và $y$ là $l_x$.
    
    Tổng độ phức tạp thời gian của phép xây dựng là $O(nm)$.

???+ note "Mã ví dụ [UVa10615 Rooks](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=18&page=show_problem&problem=1556)"
    ```cpp
    --8<-- "docs/graph/code/color/color_1.cpp"
    ```

??? note "Một bài ví dụ khá khó [uoj 444 Đồ thị hai phía](https://uoj.ac/problem/444)"
    Đây là bài tập do tác giả ra cho đợt bài tập vòng 1 của đội tuyển tập huấn năm 2018.
    
    Trước hết, cận dưới của đáp án là số đỉnh có bậc không phải bội của $k$.
    
    Cách xây dựng đạt cận dưới là tách đỉnh trên đồ thị hai phía.
    
    Nếu $degree \bmod k \neq 0$, tách nó thành $degree/k$ đỉnh có bậc $k$ và một đỉnh có bậc $degree \bmod k$.
    
    Nếu $degree \bmod k = 0$, tách nó thành $degree/k$ đỉnh có bậc $k$.
    
    Các đỉnh được tách ra có cùng ý nghĩa trong đồ thị gốc. Nói cách khác, miễn là thỏa mãn giới hạn về bậc, một đầu mút của cạnh có thể nối tới bất kỳ đỉnh nào được tách ra.
    
    Theo định lý Vizing, có thể xây dựng một phương án $k$-tô màu cho đồ thị này.
    
    Phần xóa cạnh không liên quan nhiều đến định lý Vizing, nên không trình bày thêm trong mục này.
    
    Có thể tham khảo lời giải mà tác giả đã viết khi đó.

## Đa thức sắc

$P(G,k)$ biểu thị tổng số cách $k$-tô màu khác nhau của $G$.

$P(K_n, k) = k(k-1)\cdots(k-n+1)$

$P(N_n, k) = k^n$

Trong đồ thị vô hướng không có khuyên $G$,

1.  Nếu $e=(v_i, v_j) \notin E(G)$, thì $P(G, k) = P(G \cup e, k)+P(G\setminus e, k)$.
2.  Nếu $e=(v_i, v_j) \in E(G)$, thì $P(G,k)=P(G-e,k)-P(G\setminus e,k)$.

Định lý: Giả sử $V_1$ là tập cắt đỉnh của $G$, $G[V_1]$ là đồ thị con đầy đủ cấp $|V_1|$ của $G$, và $G-V_1$ có $p(p \geq 2)$ thành phần liên thông. Khi đó:

$P(G,k)=\frac{\Pi_{i=1}^{p}{(P(H_i, k))}}{P(G[V_1], k)^{p-1}}$

trong đó $H_i=G[V_1 \cup V(G_i)]$

## Tài liệu tham khảo

1.  [Graph coloring - Wikipedia](https://en.wikipedia.org/wiki/Graph_coloring)
2.  Welsh, D. J. A.; Powell, M. B. (1967), "[An upper bound for the chromatic number of a graph and its application to timetabling problems](https://doi.org/10.1093%2Fcomjnl%2F10.1.85)", The Computer Journal, 10 (1): 85-86
