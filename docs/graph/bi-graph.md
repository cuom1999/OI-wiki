## Giới thiệu

Đồ thị hai phía, còn gọi là đồ thị lưỡng phân,
là một lớp đồ thị có cấu trúc đặc biệt.
Tập đỉnh của nó có thể được chia thành hai tập con rời nhau,
sao cho mỗi cạnh trong đồ thị đều nối một cặp đỉnh thuộc hai tập này,
và không nối hai đỉnh nằm trong cùng một tập.

Nhờ cấu trúc đơn giản này,
đồ thị hai phía không chỉ có nhiều tính chất đẹp
mà còn được dùng rộng rãi trong các mô hình thực tế,
chẳng hạn phân công nhiệm vụ, hệ gợi ý, thị trường ghép cặp, v.v.
Nhiều bài toán tối ưu khó trên đồ thị tổng quát
lại có thể được giải hiệu quả và chính xác trên đồ thị hai phía.

## Định nghĩa

Nếu tập đỉnh $V$ của đồ thị $G=(V,E)$
có thể được chia thành hai tập con rời nhau $X$ và $Y$,
sao cho hai đầu mút của mỗi cạnh $e\in E$ lần lượt thuộc $X$ và $Y$,
thì đồ thị $G$ được gọi là **đồ thị hai phía** (bipartite graph).
Hai tập $X$ và $Y$ thường được gọi là hai **phần** (part) của nó,
hoặc lần lượt gọi là phần trái và phần phải của đồ thị hai phía.
Khi hai phần $X$ và $Y$ đã biết,
cũng có thể biểu diễn đồ thị hai phía $G$ bằng bộ ba $(X, Y, E)$.

Một đồ thị hai phía điển hình được minh họa dưới đây.

![](./images/bi-graph-1.svg)

Cây, chu trình chẵn, đồ thị lưới, v.v. đều là những ví dụ thường gặp về đồ thị hai phía.

## Đặc trưng

Đồ thị hai phía cũng có thể được định nghĩa tương đương bằng các tính chất sau:

-   Đồ thị $G$ tô được bằng 2 màu.
    Nói cách khác, có thể tô màu tất cả các đỉnh của đồ thị bằng không quá hai màu,
    đồng thời bảo đảm hai đỉnh kề nhau có màu khác nhau.
-   Đồ thị $G$ không chứa chu trình có độ dài lẻ.

Tính chất thứ nhất tương đương với định nghĩa của đồ thị hai phía: chỉ cần tô mỗi phần của đồ thị hai phía bằng một màu.

Tính chất thứ hai phức tạp hơn một chút.
Có thể thử tô màu đồ thị $G$ bằng hai màu.
Vì việc tô màu giữa các thành phần liên thông khác nhau không ảnh hưởng lẫn nhau,
chỉ cần xét từng thành phần liên thông.
Chọn một đỉnh bất kỳ $s$ trong thành phần liên thông,
chạy DFS, và ghi lại khoảng cách từ mỗi đỉnh $v$ trong thành phần đó đến $s$.
Bằng quy nạp trên cây DFS bắt đầu từ $s$,
nếu tồn tại một cách tô màu hợp lệ,
thì cách tô đó buộc phải tô hai màu theo tính chẵn lẻ
của khoảng cách từ mỗi đỉnh $v$ đến đỉnh xuất phát $s$.

![](./images/bi-graph-2.svg)

Tiếp theo, xét những cạnh không nằm trong cây sinh.
Nếu hai đầu mút của mọi cạnh ngoài cây này đều có màu khác nhau,
thì cách tô màu hiện tại là hợp lệ;
ngược lại, không tồn tại cách tô màu hợp lệ.
Hơn nữa, hai đỉnh có màu khác nhau khi và chỉ khi
khoảng cách từ chúng đến gốc cây $s$ có một giá trị lẻ và một giá trị chẵn.
Điều này lại tương đương với việc thêm cạnh ngoài cây đó
tạo ra một chu trình chẵn chứ không phải chu trình lẻ.
Vì vậy, miễn là không có chu trình lẻ,
các cạnh ngoài cây này sẽ nối hai đỉnh có màu khác nhau,
do đó toàn bộ đồ thị có thể được tô bằng hai màu,
và đồ thị là đồ thị hai phía.

## Kiểm tra

Để kiểm tra một đồ thị có phải là đồ thị hai phía hay không,
chỉ cần dùng đặc trưng tương đương ở trên và thử tô màu đồ thị.
Có thể dùng [DFS](./dfs.md) hoặc [BFS](./bfs.md) để duyệt đồ thị.
Nếu phát hiện chu trình lẻ,
tức xuất hiện tình huống không thể tô màu,
thì đồ thị không phải là đồ thị hai phía;
ngược lại, nó là đồ thị hai phía.

Quy trình cụ thể như sau:

-   Duyệt qua các đỉnh; nếu gặp một đỉnh chưa được tô màu, nghĩa là đã tìm thấy một thành phần liên thông mới.
-   Tô đỉnh đó bằng một màu bất kỳ,
    rồi lấy nó làm đỉnh xuất phát để chạy [DFS](./dfs.md) hoặc [BFS](./bfs.md),
    thử tô màu thành phần liên thông này.
-   Khi duyệt các đỉnh kề, nếu gặp một đỉnh đã được tô màu,
    kiểm tra màu của nó có trùng với màu của đỉnh hiện tại hay không.
    Nếu trùng, đồ thị không phải là đồ thị hai phía và có thể trả về ngay;
    nếu không, tiếp tục duyệt.
-   Nếu gặp một đỉnh chưa được tô màu, tô đỉnh đó bằng màu ngược với màu của đỉnh hiện tại.

Mã tham khảo như sau:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/bi-graph/check-bipartite.cpp:core"
    ```

Độ phức tạp thời gian là $O(|V|+|E|)$.

## Ứng dụng

Nhờ cấu trúc đơn giản,
nhiều bài toán tối ưu trong lý thuyết đồ thị có thể được giải hiệu quả trên đồ thị hai phía.
Xem chi tiết trong các mục chính liên quan.

-   Clique cực đại
-   Tô màu đỉnh tối thiểu
-   [Tô màu cạnh tối thiểu](./color.md#chứng-minh-mang-tính-xây-dựng-của-định-lý-vizing-cho-đồ-thị-hai-phía)
-   [Ghép cặp lớn nhất](./graph-matching/bigraph-match.md)
-   [Phủ cạnh nhỏ nhất](./graph-matching/graph-match.md#phủ-cạnh-nhỏ-nhất-có-trọng-số)
-   [Phủ đỉnh nhỏ nhất](./graph-matching/bigraph-match.md#phủ-đỉnh-nhỏ-nhất-trên-đồ-thị-hai-phía)
-   [Tập độc lập lớn nhất](./graph-matching/bigraph-match.md#tập-độc-lập-lớn-nhất-trên-đồ-thị-hai-phía)
-   [Ghép cặp trọng số lớn nhất](./graph-matching/bigraph-weight-match.md)
-   [Trò chơi trên đồ thị hai phía](../math/game-theory/impartial-game.md#trò-chơi-trên-đồ-thị-hai-phía)
