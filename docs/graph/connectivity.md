author: jifbt, Mayuri0v0

## Định nghĩa

Định nghĩa của các nội dung sau có thể xem tại [các khái niệm liên quan đến lý thuyết đồ thị](./concept.md):

-   độ liên thông cạnh, tập cắt cạnh;
-   độ liên thông đỉnh, tập cắt đỉnh;
-   clique.

## Tính chất

### Bất đẳng thức Whitney

**Bất đẳng thức Whitney** (1932) cho biết quan hệ giữa độ liên thông đỉnh $\kappa$, độ liên thông cạnh $\lambda$ và bậc nhỏ nhất $\delta$:

$$
\kappa \le \lambda \le \delta
$$

???+ note "Chứng minh"
    Trực giác là: nếu có một tập cắt cạnh kích thước $\lambda$, chọn tùy ý một đầu mút của mỗi cạnh trong đó thì có thể thu được một tập cắt đỉnh kích thước $\lambda$. Vì vậy bất đẳng thức thứ nhất đúng.

    Tất cả các cạnh kề với một đỉnh có bậc nhỏ nhất (nếu có nhiều đỉnh như vậy thì chọn tùy ý một đỉnh) tạo thành một tập cắt cạnh kích thước $\delta$, nên bất đẳng thức thứ hai cũng đúng.

Bất đẳng thức này không thể cải thiện thêm. Nói cách khác, với mọi bộ ba thỏa mãn nó, đều có thể tìm được một đồ thị có đúng bộ ba giá trị đó.

???+ note "Cấu dựng"
    Nối hai clique kích thước $\delta + 1$ bằng $\lambda$ cạnh, sao cho trong hai clique lần lượt có $\lambda$ và $\kappa$ đỉnh khác nhau được nối bởi các cạnh này.

### Định lý Menger

Từ [định lý luồng cực đại - cắt nhỏ nhất](./flow/min-cut.md) (còn gọi là định lý Ford-Fulkerson), có thể suy ra rằng số lượng đường đi không giao nhau (tức là đôi một không có cạnh chung) lớn nhất giữa hai đỉnh bằng kích thước nhỏ nhất của tập cắt. Hệ quả này còn được gọi là **định lý Menger**.

## Tính toán

Trong các đồ thị dưới đây, trọng số của mọi cạnh đều là $1$.

### Tính độ liên thông cạnh bằng luồng cực đại

Liệt kê mọi cặp đỉnh $(s, t)$, lấy $s$ làm nguồn và $t$ làm đích, rồi chạy luồng cực đại với trọng số cạnh bằng $1$. Cần chạy luồng cực đại $O(n^2)$ lần. Nếu dùng thuật toán Edmonds-Karp, độ phức tạp là $O(|V|^3 |E|^2)$. Dùng thuật toán Dinic sẽ tốt hơn, với độ phức tạp $O(|V|^2 |E| \min(|V|^{2/3}, |E|^{1/2}))$.

### Cắt nhỏ nhất toàn cục

Dùng [thuật toán Stoer-Wagner](./stoer-wagner.md), chỉ cần chạy một lần bài toán cắt nhỏ nhất không có nguồn và đích. Độ phức tạp là $O(|V||E| + |V|^{2}\log|V|)$, thường có thể xấp xỉ là $O(|V|^3)$.

### Độ liên thông đỉnh

Vẫn liệt kê các cặp đỉnh. Lần này, với mỗi đỉnh $x$ không phải nguồn hoặc đích, tách nó thành hai đỉnh $x_1$ và $x_2$, rồi nối cạnh $(x_1, x_2)$. Thay mọi cạnh $(u, v)$ trong đồ thị ban đầu bằng hai cạnh $(u_2, v_1)$ và $(v_2, u_1)$. Khi đó, giá trị luồng cực đại bằng kích thước của tập cắt đỉnh nhỏ nhất giữa $s$ và $t$ (còn gọi là độ liên thông đỉnh cục bộ). Độ phức tạp giống với cách dùng luồng cực đại để tính độ liên thông cạnh.

**Trang này được dịch từ các bài blog [Рёберная связность. Свойства и нахождение](http://e-maxx.ru/algo/rib_connectivity), [Вершинная связность. Свойства и нахождение](http://e-maxx.ru/algo/vertex_connectivity) và bản dịch tiếng Anh của chúng [Edge connectivity/Vertex connectivity](https://cp-algorithms.com/graph/edge_vertex_connectivity.html). Bản tiếng Nga được cấp phép theo Public Domain + Leave a Link; bản tiếng Anh được cấp phép theo CC-BY-SA 4.0.**

## Đọc thêm

-   Bài báo [*Connectivity Algorithms*](https://www.cse.msu.edu/~cse835/Papers/Graph_connectivity_revised.pdf) giới thiệu những tiến triển trong các thuật toán tính liên thông trong những năm gần đây, có thể tham khảo thêm khi cần.
