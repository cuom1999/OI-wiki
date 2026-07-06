Bài viết này giới thiệu đồ thị phẳng, đồ thị phẳng đã nhúng và các khái niệm liên quan.

## Đồ thị phẳng

Nếu đồ thị $G$ có thể được vẽ trên mặt phẳng $S$, tức là không có hai cạnh nào cắt nhau ngoài các đỉnh chung, thì $G$ nhúng được vào mặt phẳng $S$, và $G$ là **đồ thị phẳng** (planar graph). Hình vẽ không có cạnh cắt nhau như vậy được gọi là biểu diễn phẳng của $G$, hay **phép nhúng phẳng** (planar embedding). Phép nhúng phẳng cụ thể của một đồ thị phẳng còn được gọi là **đồ thị phẳng đã nhúng** (plane graph).

???+ info "Thuật ngữ đồ thị phẳng"
    Trong các tài liệu khác nhau, thuật ngữ "đồ thị phẳng" có thể được hiểu theo những cách khác nhau. Theo định nghĩa trong bài này, đồ thị phẳng là một đối tượng của lý thuyết đồ thị, và nó có thể được nhúng vào mặt phẳng theo nhiều cách khác nhau; còn đồ thị phẳng đã nhúng là một đối tượng hình học, ngoài cấu trúc đồ thị còn cần chỉ rõ cách vẽ đồ thị. Cùng một đồ thị phẳng thường tương ứng với nhiều đồ thị phẳng đã nhúng. Vì vậy, nếu một kết luận trong bài chỉ phụ thuộc vào cấu trúc đồ thị, bài viết dùng cụm từ "đồ thị phẳng"; nếu kết luận còn phụ thuộc vào cách nhúng trên mặt phẳng, bài viết dùng cụm từ "đồ thị phẳng đã nhúng".

Dưới đây là các ví dụ đơn giản về đồ thị phẳng đã nhúng:

![](images/planar-1.svg)

(trái: đồ thị bướm; phải: đồ thị đầy đủ cấp $4$, $K_4$)

Dưới đây là các ví dụ đơn giản về đồ thị không phẳng:

![](images/planar-2.svg)

(trái: đồ thị đầy đủ cấp $5$, $K_5$; phải: đồ thị hai phía đầy đủ $K_{3,3}$ với mỗi phía có $3$ đỉnh)

## Tính chất

Phần này giới thiệu các tính chất của đồ thị phẳng đã nhúng.

### Mặt và bậc của mặt

Giả sử $G$ là một đồ thị phẳng đã nhúng. Các cạnh của $G$ chia mặt phẳng chứa $G$ thành một số miền; mỗi miền được gọi là một **mặt** (face) của $G$. Trong đó, mặt không bị chặn được gọi là **mặt vô hạn** (unbounded face) hoặc **mặt ngoài** (external face), còn các mặt bị chặn được gọi là mặt hữu hạn hoặc mặt trong. Mỗi đồ thị phẳng đã nhúng có đúng một mặt ngoài.

Chu trình tạo bởi tất cả các cạnh bao quanh một mặt được gọi là **biên** (boundary) của mặt đó, và các cạnh trên biên **liên thuộc** (incident) với mặt đó. Độ dài của biên được gọi là **bậc** (degree) của mặt. Khi tính bậc của mặt, mỗi cạnh cầu được tính hai lần. Tổng bậc của tất cả các mặt trong một đồ thị phẳng đã nhúng bằng $2$ lần số cạnh $|E|$.

Trong một đồ thị phẳng đã nhúng, biên của mặt bậc $1$ tương ứng với một khuyên; biên của mặt bậc $2$ thường tương ứng với một cặp cạnh song song[^face-2]. Trong một đồ thị phẳng đơn liên thông có số đỉnh $|V|\ge 3$, mọi mặt đều có bậc ít nhất là $3$.

### Công thức Euler

Một tính chất quan trọng của đồ thị phẳng đã nhúng là **công thức Euler** (Euler's formula). Công thức này cho quan hệ giữa số đỉnh $|V|$, số cạnh $|E|$ và số mặt $|F|$ của đồ thị.

???+ note "Công thức Euler"
    Với đồ thị phẳng đã nhúng liên thông $G$, có
    
    $$
    |V| - |E| + |F| = 2.
    $$

??? note "Chứng minh"
    Chứng minh bằng quy nạp theo số mặt $|F|$. Cơ sở quy nạp là $|F|=1$. Khi đó, đồ thị phẳng đã nhúng chỉ có đúng một mặt ngoài, và mọi cạnh đều là cạnh cầu. Vì thế, $G$ là một cây, nên tất yếu $|E|=|V|-1$; thay vào công thức Euler thu được đẳng thức đúng. Giả sử công thức Euler đúng với mọi đồ thị phẳng đã nhúng có $|F| = k$ mặt. Xét một đồ thị phẳng đã nhúng $G$ có $|F|=k + 1$ mặt. Khi đó tồn tại một cạnh không phải cạnh cầu $e$, là cạnh chung của hai mặt khác nhau. Xóa cạnh $e$ khỏi đồ thị, thu được đồ thị $G-e$ có $|V|$ đỉnh, $|E|-1$ cạnh và $|F|-1$ mặt. Theo giả thiết quy nạp, công thức Euler đúng với $G-e$, tức là $|V|-(|E|-1)+(|F|-1)=2$. Biến đổi lại thu được công thức Euler cho $G$. Do đó, theo nguyên lý quy nạp toán học, công thức Euler đúng với mọi đồ thị phẳng đã nhúng liên thông.

???+ note "Hệ quả"
    Với đồ thị phẳng đã nhúng $G$ có $k$ thành phần liên thông, có
    
    $$
    |V| - |E| + |F| = k + 1.
    $$

??? note "Chứng minh"
    Mỗi thành phần liên thông của $G$ đều là một đồ thị phẳng đã nhúng, nhưng các thành phần liên thông này dùng chung cùng một mặt ngoài. Vì vậy, nếu áp dụng trực tiếp công thức Euler cho từng thành phần rồi cộng lại, tổng số đỉnh và tổng số cạnh là đúng, nhưng tổng số mặt bị thừa $(k-1)$, vì mặt ngoài duy nhất đã bị đếm tổng cộng $k$ lần. Tính đến phần hiệu chỉnh này, thu được $|V|-|E|+|F| = 2k - (k-1) = k+1$.

Từ đó, có thể suy ra quan hệ giữa số cạnh và số đỉnh của đồ thị phẳng đã nhúng.

???+ note "Định lý"
    Với đồ thị phẳng đã nhúng $G$ có $k$ thành phần liên thông, nếu mỗi mặt của $G$ đều có bậc ít nhất là $l \ge 3$, thì
    
    $$
    |E| \le \dfrac{l}{l-2}(|V|-k-1).
    $$

??? note "Chứng minh"
    Vì bậc của mỗi mặt trong $G$ đều ít nhất là $l$, nên tổng bậc của tất cả các mặt ít nhất là $l|F|$, tức là $2|E| \ge l|F|$. Thay hệ quả của công thức Euler $|V| - |E| + |F| = k + 1$ vào, thu được
    
    $$
    2|E| \ge l(k + 1 - |V| + |E|).
    $$
    
    Dùng $l \ge 2$ để giải theo $|E|$, thu được
    
    $$
    |E| \le \dfrac{l}{l-2}(|V|-k-1).
    $$

???+ note "Hệ quả"
    Giả sử $G$ là đồ thị phẳng đơn và $|V|\ge 3$. Khi đó
    
    $$
    |E| \le 3|V|-6.
    $$

??? note "Chứng minh"
    Khi $G$ liên thông, mọi mặt đều có bậc ít nhất là $3$. Trong định lý trên, lấy $k=1$ và $l=3$, thu được $|E|\le 3|V|-6$.
    
    Khi $G$ không liên thông, chia thành hai trường hợp:
    
    -   Nếu tồn tại thành phần liên thông có số đỉnh ít nhất là $3$, thì với từng thành phần liên thông có ít nhất $3$ đỉnh, có bất đẳng thức $|E_i|\le 3|V_i|-6$. Còn các thành phần liên thông có ít hơn $3$ đỉnh đều thỏa $|E_i|\le |V_i| \le 3|V_i|$. Cộng các bất đẳng thức ứng với mọi thành phần liên thông lại, thu được $|E|\le 3|V|-6$.
    -   Nếu mọi thành phần liên thông đều có ít hơn $3$ đỉnh, thì toàn bộ đồ thị thỏa $|E|\le |V|$. Lại vì khi $|V|\ge 3$ thì $|V|\le 3|V|-6$, nên vẫn có $|E|\le 3|V|-6$.
    
    Tóm lại, mệnh đề được chứng minh.

Hệ quả này cho thấy đồ thị phẳng đơn là đồ thị thưa.

### Đồ thị đối ngẫu

Mọi đồ thị phẳng đã nhúng đều có đồ thị đối ngẫu hình học tương ứng.

![](images/planar-dual-1.svg)

Giả sử $G$ là một đồ thị phẳng đã nhúng. Có thể vẽ đồ thị $G^*$ như sau:

1.  Trong mỗi mặt $f_i$ của $G$, vẽ một điểm $v_i^*$.
2.  Với mỗi cạnh $e$ của $G$, nếu $e$ nằm trên biên chung của hai mặt $f_i$ và $f_j$, vẽ một cạnh $e^*$ nối $v_i^*$ với $v_j^*$ sao cho cạnh này cắt $e$ đúng một lần và không cắt các cạnh khác của $G$ hoặc $G^*$. Đặc biệt, khi $e$ chỉ xuất hiện trên biên của một mặt $f_i$, cần vẽ một khuyên liên thuộc với $v_i^*$ sao cho khuyên này cắt $e$.

Đồ thị $G^*$ thu được theo cách đó được gọi là **đồ thị đối ngẫu** (dual graph) của đồ thị $G$.

???+ note "Định lý"
    Giả sử $G^*$ là đồ thị đối ngẫu của đồ thị phẳng đã nhúng $G$. Khi đó, $G^*$ là một đồ thị phẳng đã nhúng liên thông. Hơn nữa, $G^{**}$ đẳng cấu với $G$ khi và chỉ khi $G$ liên thông.

??? note "Chứng minh"
    Việc $G^*$ là đồ thị phẳng đã nhúng được bảo đảm bởi chính quá trình dựng nó. Còn cần chứng minh $G^*$ liên thông. Với hai đỉnh bất kỳ $v^*_i,v^*_j$ trong $G^*$, giả sử đoạn thẳng trong mặt phẳng nối $v^*_i$ và $v^*_j$ lần lượt đi qua các mặt và cạnh của $G$ là $f_i,e_{s_1},f_{s_1},\cdots,f_{s_{r-1}},e_{s_r},f_j$. Chúng lần lượt tương ứng với các đỉnh và cạnh $v_i^*,e_{s_1}^*,v^*_{s_1},\cdots,v^*_{s_{r-1}},e^*_{s_r},v^*_j$ trong đồ thị đối ngẫu. Từ cách dựng $G^*$, các đỉnh và cạnh kề nhau trong dãy này là liên thuộc với nhau, nên dãy đó mô tả một đường đi trong $G^*$. Vì vậy, $G^*$ liên thông.
    
    Đồ thị $G^{**}$ là đồ thị đối ngẫu của $G^*$, nên liên thông. Do đó, điều kiện cần để $G$ đẳng cấu với $G^{**}$ là $G$ liên thông. Tiếp theo, chứng minh điều kiện này cũng đủ. Để làm vậy, chỉ cần chứng minh rằng khi $G$ liên thông, đồ thị $G$ thỏa các yêu cầu trong phép dựng đồ thị đối ngẫu của $G^*$. Vì các cạnh của $G^*$ và các cạnh của $G$ tương ứng tự nhiên với nhau, chỉ cần chứng minh mỗi mặt của $G^*$ chứa đúng một đỉnh của $G$. Với một mặt bất kỳ $f^*$ của $G^*$, lấy một cạnh $e^*$ trên biên của nó; khi đó, một trong hai đầu mút của cạnh tương ứng $e$ trong $G$ nằm bên trong mặt $f^*$. Vì vậy, trong $f^*$ có ít nhất một đỉnh của $G$. Do cả $G^*$ và $G$ đều liên thông, công thức Euler áp dụng được; mà $G$ và $G^*$ có cùng số cạnh, số mặt của $G$ bằng số đỉnh của $G^*$, nên số đỉnh của $G$ bằng số mặt của $G^*$. Vì thế, mỗi mặt của $G^*$ chứa đúng một đỉnh của $G$. Mệnh đề được chứng minh.

Giữa cấu trúc của một đồ thị phẳng đã nhúng và đồ thị đối ngẫu của nó có nhiều quan hệ tương ứng:

-   Mặt trong $G$ tương ứng với đỉnh trong $G^*$; cạnh trong $G$ tương ứng với cạnh trong $G^*$; đỉnh trong $G$ tương ứng với mặt trong $G^*$.
-   Khuyên trong $G$ tương ứng với cạnh cầu trong $G^*$; khuyên trong $G^*$ tương ứng với cạnh cầu trong $G$.
-   Tập cắt cạnh trong $G$ tương ứng với chu trình trong $G^*$; chu trình trong $G^*$ tương ứng với tập cắt cạnh trong $G$.

Cần lưu ý rằng khái niệm đồ thị đối ngẫu chỉ có nghĩa đối với một đồ thị phẳng đã nhúng cụ thể, chứ không thể định nghĩa trên một đồ thị phẳng tùy ý nếu chưa chỉ rõ phép nhúng. Thật vậy, hai đồ thị phẳng đã nhúng đẳng cấu không nhất thiết có đồ thị đối ngẫu đẳng cấu. Nói cách khác, các phép nhúng phẳng khác nhau của cùng một đồ thị có thể cho các đồ thị đối ngẫu khác nhau.

???+ example "Ví dụ"
    Hình dưới đây vẽ hai đồ thị phẳng đã nhúng đẳng cấu, nhưng đồ thị đối ngẫu của chúng không đẳng cấu.
    
    ![](images/planar-dual-2.svg)
    
    Lý do đồ thị đối ngẫu không đẳng cấu là hình bên phải có một mặt bậc một, nên đồ thị đối ngẫu của nó có một đỉnh bậc một, còn hình bên trái thì không.

Chuyển một bài toán trên đồ thị phẳng sang đồ thị đối ngẫu đôi khi giúp bài toán dễ giải hơn. Một ví dụ điển hình là bài toán [lát cắt nhỏ nhất](./flow/min-cut.md) trên đồ thị phẳng có thể chuyển thành bài toán [đường đi ngắn nhất](./shortest-path.md) trên đồ thị đối ngẫu. Giả sử $G$ là đồ thị phẳng có trọng số trên cạnh, $s,t$ là hai đỉnh của nó, và cần tìm lát cắt $s$-$t$ nhỏ nhất.

![](images/planar-dual-3.svg)

Như hình minh họa, chọn một phép nhúng phẳng phù hợp sao cho $s,t$ nằm trên biên mặt ngoài của $G$. Ngoài ra, thêm các tia kéo dài từ $s$ và $t$ ra ngoài để chia mặt ngoài thành hai phần $f_{+}$ và $f_{-}$. Dựa trên hình này, dựng đồ thị đối ngẫu và gán trọng số cho các cạnh tương ứng trong đồ thị đối ngẫu. Khi đó, các đường đi giữa hai đỉnh tương ứng với hai mặt $f_{+}$ và $f_{-}$ trong đồ thị đối ngẫu $G^*$ (nét đỏ đậm) tương ứng một-một với các tập cắt cạnh $s$-$t$ của đồ thị $G$ (nét đen đậm), và hai bên có cùng trọng số. Vì vậy, tìm đường đi ngắn nhất trong đồ thị đối ngẫu sẽ cho lát cắt $s$-$t$ nhỏ nhất trong $G$.

Một hiểu lầm thường gặp là từ phép chuyển đổi trên mà kết luận rằng lát cắt nhỏ nhất trong đồ thị phẳng luôn bằng đường đi ngắn nhất trong đồ thị đối ngẫu. Tuy nhiên, điều này chỉ áp dụng khi tồn tại một phép nhúng phẳng của $G$ sao cho $s,t$ cùng nằm trên một mặt; trong các bài lập trình thi đấu kiểm tra kiến thức này, đồ thị được cho thường có, và kèm theo, một phép nhúng như vậy. Dưới đây là một định lý có thể dùng để kiểm tra sự tồn tại của nó.

???+ note "Định lý"
    Với hai đỉnh $s,t$ của đồ thị phẳng $G=(V,E)$, tồn tại một phép nhúng phẳng của $G$ sao cho $s,t$ nằm trên cùng một mặt khi và chỉ khi $(V,E \cup \{(s,t)\})$ là đồ thị phẳng.

??? note "Chứng minh"
    Nếu tồn tại một phép nhúng phẳng của $G$ sao cho $s,t$ nằm trên cùng một mặt, thì có thể thêm cạnh $(s,t)$ bên trong mặt đó mà vẫn giữ được tính phẳng.
    
    Nếu $(V, E \cup \{(s,t)\})$ là đồ thị phẳng, thì lấy tùy ý một phép nhúng phẳng của nó, $s,t$ cùng nằm trên mặt chứa cạnh $(s,t)$. Sau khi xóa $(s,t)$, $s,t$ vẫn cùng nằm trên một mặt. Mệnh đề được chứng minh.

Chẳng hạn, trong hình dưới đây, sau khi thêm cạnh $(s,t)$ sẽ thu được đồ thị không phẳng $K_5$, nên không tồn tại phép nhúng phẳng như vậy, và phép chuyển đổi trên không áp dụng được.

![](images/planar-st.svg)

### Một số kết quả khác

Ngoài ra, đồ thị phẳng còn có nhiều kết quả nổi tiếng khác. Phần này chỉ liệt kê ngắn gọn mà không thảo luận thêm.

???+ note "Định lý bốn màu"
    Mọi đồ thị phẳng không có khuyên đều tô được bằng $4$ màu.

???+ note "Định lý Fáry"
    Mọi đồ thị phẳng đơn luôn có một phép nhúng phẳng sao cho tất cả các cạnh của đồ thị đều là đoạn thẳng.

???+ note "Định lý Wood"
    Đồ thị phẳng có nhiều nhất $8|V|-16$ clique cực đại.

???+ note "Định lý Tutte"
    Mọi đồ thị phẳng $4$-liên thông theo đỉnh đều là đồ thị Hamilton.

## Nhận biết

Phần này thảo luận các phương pháp xác định một đồ thị cho trước có phải là đồ thị phẳng hay không.

### Đồ thị cấm

Đặc trưng kinh điển nhất của đồ thị phẳng được phát biểu bằng **đồ thị cấm** (forbidden graph).

Trước hết, $K_5$ và $K_{3,3}$ không phải là đồ thị phẳng.

???+ note "Định lý"
    $K_5$ và $K_{3,3}$ không phải là đồ thị phẳng.

??? note "Chứng minh"
    Ở trên đã thấy rằng đồ thị phẳng đơn liên thông với $|V|\ge 3$ phải thỏa
    
    $$
    |E| \le \dfrac{l}{l-2}(|V|-2).
    $$
    
    Trong đó, $l$ là bậc nhỏ nhất của các mặt. Với $K_5$, có $l=3,~|V|=5,~|E|=10$, nên $K_5$ không thể vẽ thành đồ thị phẳng đã nhúng. Với $K_{3,3}$, có $l=4,~|V|=6,~|E|=9$, nên $K_{3,3}$ cũng không thể vẽ thành đồ thị phẳng đã nhúng.

Hai đồ thị này chính là các cấu trúc nhỏ nhất làm cho một đồ thị không phẳng. Nói cách khác, miễn là đồ thị không chứa hai đồ thị này làm cấu trúc con theo một nghĩa nào đó, thì đồ thị đó là đồ thị phẳng.

Định lý kiểm tra tính phẳng đầu tiên là định lý Kuratowski. Định lý này dùng khái niệm đồng phôi đồ thị: nếu hai đồ thị $G_1$ và $G_2$ đẳng cấu, hoặc trở nên đẳng cấu sau khi lặp lại thao tác chèn hoặc xóa đỉnh bậc $2$, thì chúng được gọi là **đồng phôi** (homeomorphic). Từ đó, có thể phát biểu kết quả sau:

???+ note "Định lý Kuratowski"
    Đồ thị $G$ là đồ thị phẳng khi và chỉ khi $G$ không chứa đồ thị con đồng phôi với $K_5$ hoặc $K_{3,3}$.

Một định lý liên quan khác là định lý Wagner. Định lý này dùng thao tác co cạnh để đặc trưng đồ thị phẳng. Thao tác co cạnh là việc lặp nhiều lần thao tác co một cạnh của đồ thị thành một điểm. Từ đó, có thể phát biểu kết quả sau:

???+ note "Định lý Wagner"
    Đồ thị $G$ là đồ thị phẳng khi và chỉ khi $G$ không có đồ thị con nào có thể co về $K_5$ hoặc $K_{3,3}$.

Việc đồ thị phẳng không chứa các loại đồ thị con này khá dễ thấy, nên phần then chốt của cả hai định lý nằm ở tính đủ của điều kiện đồ thị cấm tương ứng. Vì một đồ thị con đồng phôi với $K_5$ hoặc $K_{3,3}$ đều có thể co về chúng, nhưng chiều ngược lại không nhất thiết đúng, nên định lý Kuratowski cung cấp một điều kiện kiểm tra tính phẳng yếu hơn nhưng cũng dễ kiểm tra hơn.

### Thuật toán kiểm tra tính phẳng

Dù trông có vẻ không đơn giản, hiện đã có nhiều thuật toán tuyến tính cho bài toán kiểm tra tính phẳng. Tuy nhiên, do các thuật toán này thường khá phức tạp khi cài đặt, chúng gần như không xuất hiện trong lập trình thi đấu.

Thuật toán tuyến tính sớm nhất là thuật toán Hopcroft-Tarjan[^ht74], nhưng cách cài đặt của nó khá phức tạp. Thuật toán de Fraysseix-Ossona de Mendez-Rosenstiehl, còn gọi là thuật toán kiểm tra tính phẳng LR[^dor06][^df08][^bra09], cải tiến thêm quy trình của thuật toán Hopcroft-Tarjan và là một trong các thuật toán kiểm tra tính phẳng tốt nhất hiện nay. Thư viện NetworkX của Python có [cài đặt](https://github.com/networkx/networkx/blob/main/networkx/algorithms/planarity.py) thuật toán này.

Một thuật toán rất tốt khác là thuật toán Boyer-Myrvold[^bm99][^bm04]. Nó có thể xác định trong thời gian tuyến tính một đồ thị cho trước có phẳng hay không. Hơn nữa, nếu đồ thị phẳng, thuật toán sẽ xuất ra một phép nhúng phẳng; nếu không, thuật toán sẽ xuất ra một đồ thị con Kuratowski, tức là một đồ thị con đồng phôi với $K_5$ hoặc $K_{3,3}$. Thư viện Boost của C++ có [cài đặt](https://www.boost.org/doc/libs/1_67_0/boost/graph/planar_detail/boyer_myrvold_impl.hpp) thuật toán này.

Có thể tham khảo thêm các thuật toán liên quan trong phần tài liệu ở cuối bài.

## Các đồ thị phẳng đặc biệt

Phần này giới thiệu một vài lớp đồ thị phẳng đặc biệt.

### Đồ thị phẳng cực đại

Với đồ thị phẳng đơn $G$, nếu thêm cạnh giữa hai đỉnh không kề nhau bất kỳ của nó đều làm cho đồ thị thu được không còn phẳng, thì $G$ được gọi là **đồ thị phẳng cực đại** (maximal planar graph). Một phép nhúng phẳng của đồ thị phẳng cực đại được gọi là **đồ thị phẳng đã nhúng cực đại**.

???+ note "Định lý"
    Đồ thị phẳng cực đại $G$ liên thông. Hơn nữa, khi số đỉnh $|V|\ge 3$, đồ thị $G$ không có cạnh cầu.

??? note "Chứng minh"
    Nếu đồ thị phẳng $G$ không liên thông, thì với bất kỳ phép nhúng phẳng nào của nó, đều có thể chọn hai đỉnh thuộc hai thành phần liên thông khác nhau và nối chúng trong mặt ngoài; đồ thị thu được vẫn phẳng. Điều này cho thấy $G$ không phải là đồ thị phẳng cực đại. Vì vậy, nếu $G$ là đồ thị phẳng cực đại thì $G$ liên thông.
    
    Nếu đồ thị phẳng $G$ có số đỉnh $|V|\ge 3$ và có cạnh cầu $e=(u,v)$, thì đồ thị $G - e$ sau khi xóa cạnh $e$ có đúng hai thành phần liên thông, và $u,v$ thuộc hai thành phần khác nhau. Giả sử thành phần liên thông chứa $v$ có ít nhất hai đỉnh. Khi đó, có thể vẽ thành phần liên thông $G_1$ chứa $u$ trên mặt phẳng, chọn một mặt bất kỳ $f$ của $G_1$ có biên chứa $u$, rồi vẽ thành phần liên thông còn lại $G_2$ bên trong mặt $f$. Vì $G_2$ là đồ thị đơn, biên mặt ngoài của nó không thể là một khuyên, nên còn tồn tại ít nhất một đỉnh khác $w\neq u,v$. Nối lần lượt $v,w$ với $u$, thu được một đồ thị phẳng chứa $G$ làm đồ thị con. Vì vậy, $G$ không phải là đồ thị phẳng cực đại. Do đó, đồ thị phẳng cực đại có $|V|\ge 3$ không có cạnh cầu.

Cấu trúc của đồ thị phẳng đã nhúng cực đại có thể được mô tả chính xác hơn.

???+ note "Định lý"
    Với đồ thị phẳng đã nhúng $G$ có số đỉnh $|V|\ge 3$, $G$ là đồ thị phẳng đã nhúng cực đại khi và chỉ khi $G$ là đồ thị đơn và mọi mặt của $G$ đều có bậc $3$.

??? note "Chứng minh"
    Tính đủ là trực tiếp. Chỉ cần chứng minh tính cần, tức là: trong một đồ thị phẳng đã nhúng cực đại $G$ có $|V|\ge 3$, mọi mặt đều có bậc $3$. Vì $G$ là đồ thị phẳng đơn liên thông và $|V|\ge 3$, bậc của mọi mặt đều ít nhất là $3$. Do đó, giả sử mệnh đề sai, thì tồn tại một mặt $f$ có độ dài biên ít nhất là $4$. Lại vì $G$ không có cạnh cầu, biên này chỉ có thể là một chu trình. Giả sử chu trình đó là $v_1v_2v_3v_4\cdots v_1$. Nếu $v_1$ và $v_3$ không kề nhau, thì nối $v_1$ với $v_3$ bên trong mặt $f$ sẽ không phá vỡ tính phẳng, mâu thuẫn với tính cực đại của $G$; vậy $v_1$ và $v_3$ kề nhau. Tương tự, $v_2$ và $v_4$ kề nhau. Tuy nhiên, cả hai cạnh $(v_1,v_3)$ và $(v_2,v_4)$ đều không nằm trong mặt $f$. Điều này có nghĩa là hai cạnh đó phải nằm bên ngoài mặt $f$. Nhưng đó là điều không thể: dù vẽ thế nào, hai cạnh này cũng tất yếu cắt nhau. Vì vậy, trong $G$ không tồn tại mặt có bậc lớn hơn $3$. Mệnh đề ban đầu được chứng minh.

???+ note "Hệ quả"
    Với đồ thị $G$ có số đỉnh $|V|\ge 3$, luôn có số cạnh $|E|=3|V|-6$ và số mặt $|F|=2|V|-4$.

Do trong đồ thị phẳng đã nhúng cực đại, mỗi mặt đều được bao bởi ba cạnh, đồ thị phẳng đã nhúng cực đại còn được gọi là **tam giác phân phẳng** (plane triangulation).

### Đồ thị ngoài phẳng

Giả sử $G$ là một đồ thị phẳng. Nếu $G$ có một phép nhúng phẳng $\tilde{G}$ sao cho mọi đỉnh của $G$ đều nằm trên biên của cùng một mặt trong $\tilde{G}$, thì $G$ được gọi là **đồ thị ngoài phẳng** (outerplanar graph). Phép nhúng này còn được gọi là phép nhúng ngoài phẳng, hay **đồ thị ngoài phẳng đã nhúng**. Thông thường, mặt có biên đi qua tất cả các đỉnh được vẽ thành mặt ngoài.

![](images/planar-outer.svg)

Mọi đồ thị ngoài phẳng đều là đồ thị phẳng, nhưng chiều ngược lại không đúng. Đồ thị ngoài phẳng cũng có thể được đặc trưng bằng đồ thị cấm.

???+ note "Định lý"
    Một đồ thị $G$ là đồ thị ngoài phẳng khi và chỉ khi $G$ không chứa đồ thị con đồng phôi với $K_4$ hoặc $K_{2,3}$.

Với đồ thị ngoài phẳng, cũng có thể xét khái niệm đồ thị ngoài phẳng cực đại. Với đồ thị ngoài phẳng đơn $G$, nếu thêm cạnh giữa hai đỉnh không kề nhau bất kỳ đều làm cho đồ thị thu được không còn ngoài phẳng, thì $G$ được gọi là **đồ thị ngoài phẳng cực đại** (maximal outerplanar graph). Một phép nhúng ngoài phẳng của đồ thị ngoài phẳng cực đại được gọi là **đồ thị ngoài phẳng đã nhúng cực đại**. Đồ thị ngoài phẳng đã nhúng cực đại chính là một phép tam giác phân của đa giác trên mặt phẳng.

???+ note "Định lý"
    Với đồ thị ngoài phẳng đã nhúng cực đại $G$ có số đỉnh $|V|\ge 3$, nếu mọi đỉnh đều nằm trên biên mặt ngoài, thì $G$ có đúng $|V|-2$ mặt trong.

??? note "Chứng minh"
    Chứng minh bằng quy nạp theo $|V|$. Cơ sở quy nạp là $|V|=3$. Khi đó, $G$ là chu trình tam giác và chỉ có $1$ mặt trong, nên mệnh đề đúng. Giả sử mệnh đề đúng với $|V| = k$. Cần chứng minh rằng khi $|V| = k+1$, mệnh đề vẫn đúng.
    
    Trước hết, đồ thị $G$ có đỉnh bậc $2$. Nếu không, ngoài các đỉnh kề nhau trên biên mặt ngoài, mọi đỉnh đều cần nối với một đỉnh thứ ba. Không mất tính tổng quát, đánh số các đỉnh trên biên mặt ngoài theo thứ tự, và với mỗi $i = 1,2,\cdots,k+1$, định nghĩa $f(i)$ là chỉ số nhỏ nhất của một đỉnh nối với đỉnh $i$ và có chỉ số không kề với $i$. Xét các giá trị có thể của $f(i)$. Trước hết, $1 < f(1)$. Vì đỉnh $1$ đã nối với $f(1)$, đoạn nối giữa đỉnh $2$ và $f(2)$ không thể vượt qua cạnh $(1,f(1))$, nên tất yếu $1 < 2 < f(2) < f(1)$. Tương tự, $2 < 3 < f(3) < f(2)$. Vì số đỉnh là hữu hạn, quá trình thu hẹp dần này phải dừng sau hữu hạn bước. Gọi $i^*$ là giá trị lớn nhất của chỉ số $i$ thỏa $1 < \cdots < i-1 < i < f(i) < f(i-1) < \cdots < f(1)$. Khi đó, do đỉnh $i^*$ và đỉnh $f(i^*)$ không kề nhau, có $i^* < i^* + 1 < f(i^*)$. Lặp lại lập luận trước đó, vẫn phải có $i^* < i^*+1 < f(i^*+1) < f(i^*)$, mâu thuẫn với tính lớn nhất của $i^*$. Mâu thuẫn này cho thấy $G$ có đỉnh bậc $2$.
    
    Gọi $v$ là một đỉnh bậc $2$. Xóa đỉnh này khỏi $G$, thu được một đồ thị ngoài phẳng $G-v$ có $k$ đỉnh. Nó là đồ thị ngoài phẳng cực đại, vì nếu có cách thêm cạnh hợp lệ vào nó, thì cách đó cũng áp dụng được cho $G$. Theo giả thiết quy nạp, $G-v$ có đúng $k-2$ mặt trong; khi xóa đỉnh $v$, mất đúng một mặt trong của $G$. Vì vậy, số mặt trong của $G$ là $k-1$. Mệnh đề được chứng minh.

???+ note "Định lý"
    Với đồ thị ngoài phẳng đã nhúng $G$ có số đỉnh $|V|\ge 3$ và mọi đỉnh đều nằm trên biên mặt ngoài, $G$ là đồ thị ngoài phẳng đã nhúng cực đại khi và chỉ khi biên mặt ngoài của $G$ là một chu trình độ dài $|V|$, và biên của mọi mặt trong đều là chu trình độ dài $3$.

??? note "Chứng minh"
    Tính đủ là trực tiếp. Cụ thể, xét việc nối hai đỉnh không kề nhau trên biên mặt ngoài. Nếu nối trong mặt ngoài, thì không thể để mọi đỉnh cùng nằm trên biên của một mặt; nếu không nối trong mặt ngoài, đoạn nối đó tất yếu cắt biên của một mặt trong.
    
    Tiếp theo, chứng minh tính cần. Giả sử biên mặt ngoài của $G$ là $v_1v_2v_3\cdots v_nv_1~(n = |V|)$ nhưng không phải là một chu trình. Khi đó, biên này đi qua một đỉnh nhiều lần, tức là tồn tại $i\neq j$ và $i-j\neq\pm 1\pmod{n}$ sao cho $v_i=v_j$. Không mất tính tổng quát, giả sử $1 < i < j < n$. Khi đó, các cạnh liên thuộc với $v_{i-1}$ chỉ có thể nằm trong miền bị chặn bởi mạch $v_jv_{j+1}\cdots v_nv_1\cdots v_{i-1}v_i$, còn các cạnh liên thuộc với $v_{i+1}$ chỉ có thể nằm trong miền bị chặn bởi mạch $v_iv_{i+1}\cdots v_{j-1}v_{j}$. Vì vậy, $v_{i-1}$ và $v_{i+1}$ không thể kề nhau. Có thể thêm một cạnh $e$ nối $v_{i-1}$ với $v_{i+1}$ bên trong mặt ngoài, thu được đồ thị $G+e$. Đây vẫn là một đồ thị phẳng đã nhúng, và biên mặt ngoài của nó vẫn chứa mọi đỉnh. Điều này mâu thuẫn với tính cực đại ngoài phẳng của $G$. Do đó, mặt ngoài của $G$ là một chu trình độ dài $|V|$. Lý do biên của mọi mặt trong của $G$ đều là chu trình độ dài $3$ giống với trường hợp đồ thị phẳng cực đại, nên không nhắc lại.

???+ note "Hệ quả"
    Với đồ thị ngoài phẳng đã nhúng cực đại $G$ có số đỉnh $|V|\ge 3$, có:
    
    1.  $|E|=2|V|-3$.
    2.  Trong $G$ có ít nhất $3$ đỉnh có bậc không quá $3$, và ít nhất $2$ đỉnh có bậc đúng bằng $2$.
    3.  Độ liên thông đỉnh của $G$ bằng $2$.

## Bài tập

-   [Luogu P3209 \[HNOI2010\] Kiểm tra tính phẳng của đồ thị](https://www.luogu.com.cn/problem/P3209)
-   [Luogu P3249 \[HNOI2016\] Khu mỏ](https://www.luogu.com.cn/problem/P3249)
-   [Luogu P4001 \[ICPC-Beijing 2006\] Sói bắt thỏ](https://www.luogu.com.cn/problem/P4001)
-   [Luogu P4073 \[WC2013\] Đồ thị phẳng](https://www.luogu.com.cn/problem/P4073)
-   [Luogu P7295 \[USACO21JAN\] Paint by Letters P](https://www.luogu.com.cn/problem/P7295)

## Tài liệu tham khảo và chú thích

-   [Planar graph - Wikipedia](https://en.wikipedia.org/wiki/Planar_graph)
-   [Planarity testing - Wikipedia](https://en.wikipedia.org/wiki/Planarity_testing)
-   Bondy, John Adrian, and Uppaluri Siva Ramachandra Murty. Graph theory with applications. Vol. 290. London: Macmillan, 1976.
-   Diestel, Reinhard. Graph theory. Vol. 173. Springer Nature, 2025.
-   Patrignani, Maurizio. "Planarity Testing and Embedding." (2013): 1-42.

[^face-2]: Nhưng đây không phải là khả năng duy nhất. Hai khuyên lồng nhau cũng tạo thành một mặt bậc hai. Ngoài ra, có mặt bậc hai không nhất thiết nghĩa là đồ thị không đơn; chẳng hạn, trong một đồ thị chỉ có một cạnh, mặt duy nhất, tức mặt ngoài, cũng có bậc hai.

[^ht74]: Hopcroft, John, and Robert Tarjan. "Efficient planarity testing." Journal of the ACM (JACM) 21, no. 4 (1974): 549-568.

[^dor06]: De Fraysseix, Hubert, Patrice Ossona De Mendez, and Pierre Rosenstiehl. "Trémaux trees and planarity." International Journal of Foundations of Computer Science 17, no. 05 (2006): 1017-1029.

[^df08]: De Fraysseix, Hubert. "Trémaux trees and planarity." Electronic Notes in Discrete Mathematics 31 (2008): 169-180.

[^bra09]: Brandes, Ulrik. "The left-right planarity test." Manuscript submitted for publication 3 (2009).

[^bm99]: Boyer, John M., and Wendy J. Myrvold. "Stop Minding Your p's and q's: A Simplified O (n) Planar Embedding Algorithm." In SODA, vol. 99, pp. 140-146. 1999.

[^bm04]: Boyer, John M., and Wendy J. Myrvold. "Simplified o (n) planarity by edge addition." Graph Algorithms and Applications 5 (2006): 241.
