Kiến thức tiên quyết: [thuật toán Dijkstra](./shortest-path.md#thuật-toán-dijkstra), [thuật toán A\*](../search/astar.md), [heap gộp được khả trì](../ds/persistent-heap.md)

## Mô tả bài toán

Cho một đồ thị có hướng gồm $n$ đỉnh và $m$ cạnh. Cần tìm độ dài đường đi ngắn thứ $k$ trong tất cả các đường đi khác nhau từ $s$ đến $t$.

???+ info "\"Đường đi\""
    "Đường đi" trong bài viết này cho phép đi qua cùng một cạnh hoặc cùng một đỉnh nhiều lần, nên tên gọi chính xác hơn phải là "[walk](./concept.md#đường-đi)" thay vì "đường đi". Nói chặt chẽ, bài toán được thảo luận trong bài là bài toán **walk ngắn thứ $k$** ($k$ shortest walk). Tuy nhiên, theo thói quen, bài viết vẫn dùng tên gọi "đường đi", còn đường đi không tự giao sẽ được gọi là "đường đi đơn".

## Thuật toán A\*

Thuật toán A\* là một thuật toán tìm kiếm. Với mỗi trạng thái hiện tại $x$, nó đặt một hàm đánh giá $f(x)=g(x)+h(x)$, trong đó $g(x)$ là chi phí thực tế từ trạng thái ban đầu đến trạng thái hiện tại, còn $h(x)$ là chi phí ước lượng của đường tốt nhất từ trạng thái hiện tại đến trạng thái đích. Khi tìm kiếm, mỗi lần lấy ra trạng thái $x$ có $f(x)$ tốt nhất và mở rộng mọi trạng thái kế tiếp của nó. Có thể dùng **hàng đợi ưu tiên** để duy trì giá trị này.

Khi giải bài toán đường đi ngắn thứ $k$, đặt $h(x)$ là độ dài đường đi ngắn nhất từ đỉnh hiện tại đến đích $t$. Có thể tiền xử lý giá trị này cho mọi đỉnh bằng cách chạy đường đi ngắn nhất một nguồn từ đỉnh $t$ trên đồ thị đảo. Với mỗi trạng thái, cần ghi hai giá trị: đỉnh hiện tại đang đến $x$ và quãng đường đã đi $g(x)$; ký hiệu trạng thái này là $(x,g(x))$. Ban đầu, đưa trạng thái khởi đầu $(s,0)$ vào hàng đợi ưu tiên. Mỗi lần lấy ra trạng thái có hàm đánh giá $f(x)=g(x)+h(x)$ nhỏ nhất, liệt kê mọi cạnh đi ra từ đỉnh $x$ của trạng thái đó và đưa các trạng thái kế tiếp tương ứng vào hàng đợi ưu tiên. Khi một đỉnh được thăm lần thứ $k$, $g(x)$ của trạng thái tương ứng chính là độ dài đường đi ngắn thứ $k$ từ đỉnh xuất phát $s$ đến đỉnh đó.

Quá trình tìm kiếm này có thể tối ưu. Vì chỉ cần tìm đường đi ngắn thứ $k$ từ đỉnh đầu đến đỉnh đích, nên nếu các trạng thái đã lấy ra đến một đỉnh nhiều hơn $k$ lần, có thể bỏ qua việc mở rộng trạng thái kế tiếp của nó. Trạng thái này không ảnh hưởng đến đáp án cuối cùng. Lý do là trong $k$ lần lấy ra trước đó của đỉnh này, đã có $k$ đường đi hợp lệ đến đỉnh đó, đủ để xây dựng $k$ đường đi ngắn nhất đầu tiên đến đỉnh đích.

Nếu dùng Dijkstra tối ưu bằng hàng đợi ưu tiên, do tối đa đưa toàn bộ cạnh vào hàng đợi ưu tiên $k$ lần, độ phức tạp thời gian của thuật toán là $O(km\log km)$ và độ phức tạp bộ nhớ là $O(km)$. So với tìm kiếm trực tiếp, thuật toán A\* cắt tỉa theo đỉnh đích $t$, nhưng điều này chỉ cải thiện hằng số chứ không cải thiện độ phức tạp tiệm cận. Thuật toán trong mục này tuy không có độ phức tạp tốt, nhưng với cùng độ phức tạp đó có thể tìm $k$ đường đi ngắn nhất đầu tiên từ đỉnh xuất phát $s$ đến mỗi đỉnh (trong cây đường đi ngắn nhất gốc $t$).

### Cài đặt

??? example "Cài đặt tham khảo cho bài mẫu [Library Checker - K-Shortest Walk](https://judge.yosupo.jp/problem/k_shortest_walk)"
    ```cpp
    --8<-- "docs/graph/code/k-shortest-walk/k-shortest-walk-1.cpp"
    ```

## Cách làm bằng heap gộp được khả trì

Thuật toán ở trên thực chất tìm $k$ đường đi ngắn nhất đến mọi đỉnh. Nếu chỉ muốn tìm $k$ đường đi ngắn nhất đến một đỉnh đích $t$ cho trước, có thể làm nhanh hơn. Mục này trình bày một cách làm $O(m\log m+k\log k)$ dựa trên heap gộp được khả trì.

### Cây đường đi ngắn nhất và cạnh lệch

Hạn chế của thuật toán ở trên là đáp án chỉ được cập nhật khi đến đỉnh đích $t$. Tuy nhiên, các đường đi khác nhau có thể không chênh lệch nhiều. Ví dụ, đường đi ngắn thứ hai có thể khác đường đi ngắn nhất chỉ ở chỗ đi vòng thêm qua một đỉnh tại một cạnh, còn các phần khác của đường đi đều giống nhau; thuật toán ở trên có thể vẫn phải tìm kiếm lại qua các cạnh giống nhau đó để tìm đường đi ngắn thứ hai. Vì chỉ phần đi vòng mới là quan trọng, nên để lấy $k$ đường đi ngắn nhất đầu tiên, chỉ cần xét $k$ cách đi vòng có chi phí nhỏ nhất. Điều này dẫn đến khái niệm cây đường đi ngắn nhất.

Chạy đường đi ngắn nhất một nguồn từ đỉnh đích $t$ trên đồ thị đảo, ghi lại độ dài đường đi ngắn nhất $h(x)$ từ mỗi đỉnh $x$ đến $t$, đồng thời ghi cạnh đầu tiên $f_x$ trên một đường đi ngắn nhất bắt đầu từ $x$; nếu có nhiều lựa chọn tối ưu thì chọn tùy ý một cạnh. Tất cả các cạnh $f_x$ cùng các đầu mút của chúng tạo thành một cây, và đường đi đơn từ mỗi đỉnh $x$ trên cây đến gốc $t$ đều là một đường đi ngắn nhất từ $x$ đến $t$. Đây là **cây đường đi ngắn nhất** $T$.

Sau khi tìm được cây đường đi ngắn nhất $T$, có thể tính mỗi cạnh không nằm trên $T$ làm đi vòng thêm bao nhiêu. Với cạnh $e=(u,v)\notin T$ có trọng số $w$, định nghĩa một cạnh mới vẫn đi từ $u$ đến $v$, với chi phí $\Delta(e)=w + h(v) - h(u)$. Trong bài viết này, các cạnh có trọng số $\Delta(e)$ đó được gọi trực quan là **cạnh lệch** (sidetrack), còn trọng số $\Delta(e)$ được gọi là chi phí lệch. Nếu hai đầu mút của một cạnh không cùng nằm trong cây đường đi ngắn nhất $T$, cạnh đó không ảnh hưởng đến việc tính $k$ đường đi ngắn nhất đến đỉnh $t$ và có thể xóa trực tiếp.

Hình bên trái dưới đây là đồ thị có hướng $G$, còn bên phải là cây đường đi ngắn nhất $T$ tương ứng (cạnh dày) và các cạnh lệch tương ứng (cạnh mảnh):

![](./images/k-shortest-path-1.svg)

Giả sử tập cạnh mà một đường đi từ $s$ đến $t$ đi qua là $P$, bỏ khỏi $P$ phần giao với $T$ để thu được $P'$. Khi sắp các cạnh trong $P'$ theo thứ tự, hai cạnh kề nhau $e_1=(u_1,v_1)$ và $e_2=(u_2,v_2)$ nhất định thỏa mãn

-   Điều kiện $(*)$: điểm đầu $u_2$ của cạnh sau là một tổ tiên của điểm cuối $v_1$ của cạnh trước trên cây đường đi ngắn nhất $T$ (bao gồm chính nó).

Lý do là trong đường đi gốc $P$ tương ứng, giữa $v_1$ và $u_2$ có nối qua một số cạnh cây trong $T$. Ngược lại, với một tập cạnh $P'$ thỏa điều kiện $(*)$, luôn tồn tại duy nhất một đường đi $P$ trong đồ thị $G$ tương ứng với nó. Điều này đúng vì đường đi đơn giữa $v_1$ và $u_2$ trên cây đường đi ngắn nhất $T$ là duy nhất. Như vậy, mọi đường đi $P$ trong đồ thị gốc tương ứng một-một với một dãy cạnh lệch $P'$ thỏa điều kiện $(*)$. Hơn nữa, độ dài của đường đi $P$ bằng độ dài đường đi ngắn nhất $h(s)$ cộng với tổng các chi phí lệch này:

$$
h(s)+\sum_{e\in P'}\Delta(e).
$$

Các phân tích trên cho thấy nhiệm vụ tìm đường đi ngắn thứ $k$ được chuyển thành nhiệm vụ tìm dãy cạnh lệch $P'$ có chi phí nhỏ thứ $k$ và thỏa điều kiện $(*)$.

Để xử lý điều kiện $(*)$, thay vì mỗi lần truy vấn lại tìm tổ tiên trên cây đường đi ngắn nhất, có thể trực tiếp truyền tập cạnh lệch của mỗi đỉnh xuống các đỉnh con cháu của nó trên cây đường đi ngắn nhất. Điều này tương đương với xây dựng đồ thị $G'$ như sau:

![](./images/k-shortest-path-2.svg)

Trên đồ thị này, điều kiện $(*)$ chuyển thành yêu cầu các cạnh trong $P'$ nối đầu-cuối với nhau, tức là $P'$ là một đường đi trong đồ thị $G'$. Bài toán tiếp tục được chuyển thành tìm đường đi **đến một đỉnh bất kỳ** có độ dài nhỏ thứ $k$ xuất phát từ $s$ trong đồ thị này. So với bài toán đường đi ngắn thứ $k$ ban đầu, biến thể này không còn yêu cầu đường đi nhất định phải kết thúc tại đỉnh đích $t$.

Bài toán sau chuyển đổi có cách giải trực tiếp. Chỉ cần xuất phát từ đỉnh đầu $s$ và chạy đường đi ngắn nhất một nguồn. Mỗi lần lấy ra một đỉnh từ hàng đợi ưu tiên, tức là đã tìm được một đường đi trong đồ thị $G'$, cũng tương ứng với một đường đi đến đỉnh đích $t$ trong đồ thị $G$.

### Tối ưu bằng heap gộp được khả trì

Ý tưởng thuật toán đã rõ, nhưng cài đặt ngây thơ có độ phức tạp quá cao. Trong đồ thị $G'$, số cạnh tại một đỉnh đơn lẻ có thể là $\Theta(m)$, nên mỗi lần chạy đường đi ngắn nhất một nguồn có thể phải đẩy một tập cạnh kích thước $\Theta(m)$ vào hàng đợi ưu tiên. Thực ra không cần đưa mọi cạnh vào hàng đợi ưu tiên: trong nhiều trường hợp, trong số các cạnh được đưa vào hàng đợi, chỉ những cạnh ngắn nhất mới có khả năng được lấy ra trong các bước sau. Nói cách khác, có thể xem toàn bộ tập cạnh tại một đỉnh là một đơn vị lưu trữ và đưa đơn vị đó vào hàng đợi ưu tiên; mỗi lần chỉ cần truy cập nhanh cạnh ngắn nhất trong tập cạnh.

Điều này gợi ý dùng heap min để lưu tập cạnh tại một đỉnh. Trong hàng đợi ưu tiên của thuật toán đường đi ngắn nhất một nguồn, chỉ cần lưu các heap này; chi phí của chúng chính là chi phí đường đi ngắn nhất tương ứng với phần tử ở đỉnh heap. Mỗi lần lấy đầu hàng đợi, cũng cần đồng thời lấy cạnh ở đỉnh heap của heap đầu hàng đợi. Sau đó, vừa đưa heap sau khi bỏ đỉnh heap trở lại hàng đợi ưu tiên, vừa đưa đỉnh heap tương ứng với tập cạnh lệch tại điểm cuối của cạnh vừa lấy vào hàng đợi ưu tiên.

Dùng heap để lưu tập cạnh cũng giải quyết được việc truyền tập cạnh xuống theo cây đường đi ngắn nhất. Vì truyền tập cạnh xuống tương đương với gộp tập cạnh của đỉnh hiện tại vào đỉnh con của nó, heap cần hỗ trợ thao tác gộp; đồng thời khi gộp vào đỉnh con, không được phá hỏng tập cạnh tại đỉnh hiện tại, nên heap còn cần hỗ trợ khả trì. Đây chính là heap gộp được khả trì.

Từ đó thu được toàn bộ quy trình thuật toán:

1.  Từ đỉnh đích $t$, chạy đường đi ngắn nhất một nguồn để tìm cây đường đi ngắn nhất.
2.  Với mỗi đỉnh trên cây đường đi ngắn nhất, xây dựng tập cạnh lệch tương ứng và lưu vào heap gộp được khả trì.
3.  Dọc theo các cạnh của cây đường đi ngắn nhất, bắt đầu từ đỉnh đích $t$, gộp heap tại mỗi đỉnh vào heap của các đỉnh con.
4.  Từ đỉnh xuất phát $s$, đưa heap tại đó vào hàng đợi ưu tiên.
5.  Lấy heap ở đầu hàng đợi, ghi nhận đáp án, rồi đưa heap sau khi bỏ đỉnh heap trở lại hàng đợi ưu tiên, đồng thời đưa heap tại điểm cuối của cạnh ở đỉnh heap vào hàng đợi ưu tiên.

Thông thường dùng cây leftist hoặc heap ngẫu nhiên để cài đặt heap gộp được khả trì. Khi đó, bước cuối còn có thể tối ưu thêm. Cấu trúc bên trong của các heap này đều là cây nhị phân. Sau khi lấy đỉnh heap, ban đầu cần gộp hai đỉnh con trái và phải, rồi đưa đỉnh heap sau khi gộp vào hàng đợi ưu tiên; tuy nhiên trong thuật toán này, có thể không thực hiện thao tác gộp mà trực tiếp đưa hai heap tương ứng với hai đỉnh con vào hàng đợi ưu tiên riêng rẽ. Như vậy tiết kiệm được độ phức tạp $O(\log m)$ của một lần gộp. Vì sau mỗi lần lấy heap đầu hàng đợi, tối đa chỉ đưa thêm ba heap mới vào hàng đợi ưu tiên, kích thước hàng đợi ưu tiên là $O(k)$. Khi đó, độ phức tạp thời gian của một lần truy vấn giảm xuống $O(\log k)$, và tổng độ phức tạp truy vấn là $O(k\log k)$.

Vì độ phức tạp xây dựng cây đường đi ngắn nhất và xây dựng heap gộp được khả trì đều là $O(m\log m)$, tổng độ phức tạp thời gian của thuật toán là $O(m\log m+k\log k)$.

### Cài đặt

??? example "Cài đặt tham khảo cho bài mẫu [Library Checker - K-Shortest Walk](https://judge.yosupo.jp/problem/k_shortest_walk)"
    ```cpp
    --8<-- "docs/graph/code/k-shortest-walk/k-shortest-walk-2.cpp"
    ```

## Bài tập

-   [SDOI2010 Magic Pig Academy](https://www.luogu.com.cn/problem/P2483)

## Tài liệu tham khảo và ghi chú

-   [\[Tutorial\] k shortest paths and Eppstein's algorithm by meooow - Codeforces](https://codeforces.com/blog/entry/102085)
