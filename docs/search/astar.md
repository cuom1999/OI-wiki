Bài viết này giới thiệu thuật toán tìm kiếm A\*.

Thuật toán tìm kiếm A\* (A\* search algorithm, A\* đọc là A-star), gọi tắt là
thuật toán A\*, là thuật toán tìm đường đi ngắn nhất giữa một điểm bắt đầu và
một điểm kết thúc cho trước trên đồ thị có hướng có trọng số. Nó thuộc nhóm
duyệt đồ thị (graph traversal) và tìm kiếm ưu tiên tốt nhất (best-first search),
đồng thời là một cải tiến của [BFS](./bfs.md).

## Quy trình

Mục tiêu của thuật toán A\* là tìm đường đi ngắn nhất từ điểm bắt đầu $s$ đến
điểm kết thúc $t$ trên đồ thị có hướng. Gọi $d(x,y)$ là khoảng cách giữa nút $x$
và nút $y$, tức độ dài đường đi ngắn nhất giữa chúng. Ký hiệu $g(x)=d(s,x)$ là
hàm khoảng cách từ điểm bắt đầu $s$ đến nút $x$, $h^*(x)$ là hàm khoảng cách từ
nút $x$ đến điểm kết thúc $t$, và $h(x)$ là một ước lượng của $h^*(x)$[^note1].
Cuối cùng, ký hiệu ước lượng độ dài đường đi ngắn nhất từ $s$ qua $x$ đến $t$ là

$$
f(x) = g(x) + h(x).
$$

Khi tìm kiếm, thuật toán A\* mỗi lần lấy ra từ hàng đợi ưu tiên một nút có $f$
nhỏ nhất. Sau đó, đưa toàn bộ nút kế tiếp $x$ của nó vào hàng đợi ưu tiên, đồng
thời dùng giá trị thực tế đã ghi nhận $g(x)$ và ước lượng $h(x)$ để cập nhật
$f(x)$.

## Tính chất

Vì giá trị thực của $h^*(x)$ chưa biết trong lúc tìm kiếm, cần dùng một hàm
$h(x)$ dễ tính để ước lượng nó. Độ phức tạp thực tế của tìm kiếm A\* phụ thuộc
vào tính chất của hàm ước lượng $h(x)$. Dễ hình dung rằng nếu $h\equiv h^*$, tức
ước lượng chính xác, quá trình tìm kiếm sẽ đi đúng theo đường ngắn nhất. Còn nếu
$h\equiv 0$, thuật toán A\* suy biến thành [thuật toán Dijkstra](./../graph/shortest-path.md#thuật-toán-dijkstra);
khi $h\equiv 0$ và mọi cạnh có trọng số $1$, nó chính là [BFS](./bfs.md).

Giả sử đồ thị không có cạnh trọng số âm. Nếu ước lượng $h(x)$ không bao giờ vượt
quá khoảng cách thực $h^*(x)$, tức $0\le h\le h^*$, thì thuật toán A\* tìm được
lời giải tối ưu. Hàm ước lượng $h(x)$ thỏa điều kiện này được gọi là
**chấp nhận được** (admissible). Theo thảo luận phía trên, $h$ càng gần $h^*$
thì thuật toán A\* tương ứng càng hiệu quả. Trong trường hợp xấu
nhất, thuật toán sẽ đi qua mọi nút thỏa mãn

$$
f(x) = g(x) + h(x) \le C^*
$$

trong đó $C^*$ là khoảng cách ngắn nhất giữa điểm bắt đầu $s$ và điểm kết thúc
$t$. Trực giác là $h$ càng gần $h^*$ thì khi mở rộng, số nút kế tiếp thỏa điều
kiện trên càng ít, nên số nhánh mà thuật toán phải tìm kiếm càng ít. Vì vậy,
thuật toán A\* có thể xem là một dạng tối ưu "cắt tỉa" cho thuật toán tìm kiếm.

Nếu $h$ không chỉ chấp nhận được mà còn **nhất quán** (consistent), tức

$$
h(x) \le h(y) + d(x, y),
$$

thì thuật toán A\* sẽ không đưa lại vào hàng đợi một nút đã được lấy ra. Điều
kiện nhất quán có thể hiểu là bất đẳng thức tam giác giữa các nút $x,y,t$.

## Ví dụ

Một ứng dụng kinh điển của thuật toán A\* là giải bài toán k đường đi ngắn nhất.
Mô tả bài toán, cách làm bằng A\*, và cách dùng heap khả gộp khả persistent có
độ phức tạp tốt hơn được trình bày ở trang [bài toán k đường đi ngắn nhất](./../graph/kth-path.md).

Phần này giới thiệu một bài toán kinh điển có thể giải bằng thuật toán A\*.

???+ example "[8-puzzle](https://www.luogu.com.cn/problem/P1379)"
    Trên bàn cờ $3\times 3$ có tám quân cờ, mỗi quân ghi một số từ $1$ đến $8$.
    Trên bàn cờ còn một ô trống, biểu diễn bằng $0$. Các quân cờ xung quanh ô
    trống có thể di chuyển vào ô trống, khi đó vị trí cũ sẽ trở thành ô trống.
    Cho một bố cục ban đầu và bố cục mục tiêu (để đơn giản, đặt trạng thái mục
    tiêu như sau), cần tìm cách di chuyển ít bước nhất từ bố cục ban đầu đến bố
    cục mục tiêu.
    
    $$
    \begin{aligned}
    123\\
    804\\
    765
    \end{aligned}
    $$

??? note "Ý tưởng giải"
    Có thể định nghĩa hàm $h$ là số quân cờ không nằm đúng vị trí. Khi đó $h$
    vừa chấp nhận được, vừa nhất quán. Bài này có thể dùng thuật toán A\* để
    giải.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/search/code/astar/astar_1.cpp"
    ```

## Tài liệu tham khảo và chú thích

-   [A\* search algorithm - Wikipedia](https://en.wikipedia.org/wiki/A*_search_algorithm)

[^note1]: $h$ trong ngữ cảnh này nghĩa là heuristic. Xem thêm [Heuristic - Wikipedia](https://en.wikipedia.org/wiki/Heuristic_(computer_science))
    và phần Bounded relaxation của [A\* search algorithm - Wikipedia](https://en.wikipedia.org/wiki/A*_search_algorithm#Bounded_relaxation).
