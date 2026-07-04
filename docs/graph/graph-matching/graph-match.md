author: 310552025atNYCU, accelsao, Chrogeek, Enter-tainer, iamtwz, mcendu, Shen-Linwood, shuzhouliu, StudyingFather, t4rf9, Tiphereth-A, TrickEye, wlbksy, Xeonacid, yuhuoji, c-forrest, aaron20100919

## Mở đầu

**Ghép cặp** hay **tập cạnh độc lập** là một tập các cạnh trong đồ thị không có chung đầu mút. Thuật toán ghép cặp trong đồ thị là nhóm thuật toán thường gặp trong lập trình thi đấu, có thể chia đại khái thành hai loại: ghép cặp lớn nhất và ghép cặp trọng số lớn nhất. Vì ghép cặp trong [đồ thị hai phía](../bi-graph.md) tương đương với bài toán luồng mạng, có nhiều tính chất tốt và tương đối dễ xử lý, phần này sẽ bắt đầu bằng hai loại thuật toán trên đồ thị hai phía rồi mới thảo luận thuật toán cho đồ thị tổng quát.

## Ghép cặp trong đồ thị

Gọi $G=(V,E)$ là một đồ thị vô hướng, trong đó $V$ là tập đỉnh và $E$ là tập cạnh. Nếu một tập cạnh $M\subseteq E$ không chứa khuyên và mọi cặp cạnh trong đó không có đỉnh chung, thì tập cạnh $M$ được gọi là một **ghép cặp** (matching) hay **tập cạnh độc lập** (independent edge set) của đồ thị $G$. Một cạnh $e\in E$ nếu xuất hiện trong ghép cặp $M$ thì được gọi là **cạnh ghép cặp**, ngược lại được gọi là **cạnh không ghép cặp**. Tương ứng, một đỉnh $v\in V$ nếu là đầu mút của một cạnh ghép cặp thì được gọi là **đỉnh đã ghép cặp**, ngược lại được gọi là **đỉnh chưa ghép cặp**.

Kích thước của ghép cặp $M$ là số cạnh mà nó chứa. Với ghép cặp trong đồ thị vô hướng (có trọng số), ta thường xét các khái niệm sau:

-   **Ghép cặp cực đại** (maximal matching): ghép cặp không thể thêm cạnh ghép cặp nào nữa. Ghép cặp cực đại không nhất thiết là ghép cặp lớn nhất.

    ![ghép cặp cực đại](images/graph-match-1.svg)

-   **Ghép cặp lớn nhất** (maximum matching or maximum cardinality matching): ghép cặp có số cạnh ghép cặp nhiều nhất. Có thể có nhiều ghép cặp lớn nhất, nhưng số cạnh của ghép cặp lớn nhất là xác định và không thể vượt quá một nửa số đỉnh của đồ thị.

    ![ghép cặp lớn nhất theo số cạnh](images/graph-match-2.svg)

-   **Ghép cặp trọng số lớn nhất** (maximum weight matching): trong đồ thị có trọng số, đây là ghép cặp có tổng trọng số cạnh lớn nhất.

    ![ghép cặp trọng số lớn nhất](images/graph-match-3.svg)

-   **Ghép cặp lớn nhất có trọng số lớn nhất** (maximum weight maximum cardinality matching): trong số các ghép cặp có số cạnh lớn nhất, chọn ghép cặp có tổng trọng số cạnh lớn nhất. Nói cách khác, đó là ghép cặp có tổng trọng số lớn nhất trong tất cả các ghép cặp lớn nhất.

    ![ghép cặp lớn nhất có trọng số lớn nhất](images/graph-match-4.svg)

-   **Ghép cặp hoàn hảo** (perfect matching): ghép cặp mà mọi đỉnh đều là đỉnh đã ghép cặp. Ghép cặp hoàn hảo chắc chắn là ghép cặp lớn nhất. Đồ thị đầy đủ có số đỉnh chẵn luôn tồn tại ghép cặp hoàn hảo.

-   **Ghép cặp gần hoàn hảo** (near-perfect matching): ghép cặp có đúng một đỉnh chưa ghép cặp. Điều này chỉ có thể xảy ra khi số đỉnh của đồ thị là lẻ. Ghép cặp gần hoàn hảo cũng chắc chắn là ghép cặp lớn nhất. Đồ thị đầy đủ có số đỉnh lẻ luôn tồn tại ghép cặp gần hoàn hảo.

Trong lập trình thi đấu, các bài toán ghép cặp trong đồ thị chủ yếu nói đến ghép cặp lớn nhất hoặc ghép cặp trọng số lớn nhất.

## Đường tăng

Trong các thuật toán ghép cặp trong đồ thị, đường tăng là cấu trúc cốt lõi dùng để cải thiện ghép cặp.

### Định nghĩa

Với đồ thị $G=(V,E)$ và một ghép cặp $M$ của nó, ta có thể định nghĩa hai loại đường đi (đơn) sau:

-   **Đường xen kẽ** (alternating path) là đường đi gồm các cạnh ghép cặp và cạnh không ghép cặp xuất hiện luân phiên;
-   **Đường tăng** (augmenting path) là đường xen kẽ bắt đầu ở một đỉnh chưa ghép cặp và kết thúc ở một đỉnh chưa ghép cặp.

Vì trên đường tăng, số cạnh không ghép cặp nhiều hơn số cạnh ghép cặp đúng $1$, nên số cạnh của đường tăng luôn là số lẻ. Nếu đảo trạng thái các cạnh ghép cặp và không ghép cặp trên đường tăng, ta vẫn thu được một đường xen kẽ, đồng thời số cạnh trong ghép cặp tăng thêm $1$. Quá trình tìm một đường tăng rồi đảo nó để tăng kích thước ghép cặp được gọi là **tăng** (augmentation). Theo ngôn ngữ toán học, phép tăng tương đương với lấy hiệu đối xứng giữa ghép cặp $M$ và đường tăng $P$, thu được ghép cặp mới $M\oplus P$.

Hình dưới minh họa quá trình sau một phép tăng, số cạnh ghép cặp tăng từ $2$ lên $3$.

![tăng-1](./images/augment-1.png)

### Bổ đề Berge

Bổ đề Berge cho biết phương pháp cải thiện ghép cặp bằng đường tăng là đủ. Nói cách khác, khi không tìm được đường tăng nữa thì ta đã thu được ghép cặp lớn nhất.

???+ note "Bổ đề Berge"
    Với đồ thị $G=(V,E)$ và một ghép cặp $M$ của nó, $M$ là ghép cặp lớn nhất khi và chỉ khi không tồn tại đường tăng đối với ghép cặp $M$.

??? note "Chứng minh"
    Như đã nói ở trên, nếu tồn tại đường tăng $P$, thì $M\oplus P$ là một ghép cặp lớn hơn $M$, vì vậy $M$ chắc chắn không phải là ghép cặp lớn nhất.
    
    Ngược lại, cần chứng minh rằng nếu tồn tại một ghép cặp $M'$ lớn hơn ghép cặp $M$, thì chắc chắn tồn tại một đường tăng $P$ đối với $M$. Xét hiệu đối xứng $M\oplus M'$. Trong đồ thị $(V,M\oplus M')$, bậc của mỗi đỉnh chỉ có thể là $0$, $1$ hoặc $2$; các thành phần liên thông của đồ thị như vậy tất yếu là đường đi, chu trình hoặc đỉnh cô lập. Hơn nữa, hai cạnh kề với một đỉnh bậc $2$ chắc chắn đến từ hai ghép cặp khác nhau, nên trong mỗi chu trình này, số cạnh đến từ $M$ và $M'$ là như nhau. Vì $M'$ lớn hơn $M$, nên tồn tại ít nhất một đường đi mà số cạnh đến từ $M'$ nhiều hơn số cạnh đến từ $M$; gọi đường đi đó là $P$. Khi đó, hai đầu mút của $P$ đều là đỉnh chưa ghép cặp theo $M$, và $P$ là đường xen kẽ đối với $M$, nên $P$ chắc chắn là đường tăng đối với $M$. Chứng minh hoàn tất.

Từ định lý này, ý tưởng cốt lõi để tìm ghép cặp lớn nhất là:

-   Duyệt tất cả các đỉnh chưa ghép cặp, tìm đường tăng cho đến khi không còn tìm được đường tăng nào nữa.

Thực ra, sau mỗi phép tăng, không cần duyệt lại tất cả các đỉnh chưa ghép cặp. Trong toàn bộ quá trình tìm ghép cặp lớn nhất, mỗi đỉnh chỉ cần được duyệt một lần.

??? note "Chứng minh"
    Chỉ cần chứng minh rằng nếu khi đang xét đỉnh $v$ không tồn tại đường tăng bắt đầu từ $v$, thì sau một số lượt tăng, vẫn không tồn tại đường tăng bắt đầu từ $v$. Điều này cho thấy dù phép tăng làm thay đổi ghép cặp, ta cũng không cần kiểm tra lại các đỉnh chưa ghép cặp đã được duyệt trước đó.
    
    Giả sử ngược lại. Tức là, giả sử $v$ là một đỉnh chưa ghép cặp đã được duyệt, và sau một lượt tăng dọc theo đường tăng $P$ từ $u$ đến $w$, xuất hiện một đường tăng mới $P'$ bắt đầu từ $v$ mà trước đó không tồn tại. Khi đó, đường $P'$ chắc chắn phải có cạnh chung với $P$; nếu không, việc tăng dọc theo $P$ sẽ không làm thay đổi trạng thái ghép cặp của các cạnh trong $P'$, và $P'$ sẽ không phải là đường tăng mới xuất hiện do lượt tăng này.
    
    ![tăng-2](./images/augment-2.svg)
    
    (Trong hình, màu đen biểu thị cạnh không ghép cặp, màu đỏ và màu xanh biểu thị các trạng thái ghép cặp khác nhau.)
    
    Gọi $x$ là đỉnh đầu tiên thuộc $P$ mà ta gặp khi xuất phát từ $v$ và đi dọc theo đường $P'$. Vì trước lượt tăng này đã tồn tại một đường xen kẽ từ $v$ đến $x$, nên $x$ chắc chắn là đỉnh đã ghép cặp, do đó không thể là một trong hai đỉnh $u$ hoặc $w$. Vì vậy, trên đường tăng $P$, có hai cạnh kề với $x$ và trạng thái ghép cặp của chúng trái ngược nhau. Điều này có nghĩa là bất kể khi đến đỉnh $x$ dọc theo đường xen kẽ bắt đầu từ $v$, trạng thái ghép cặp của cạnh cuối là gì, ta đều có thể kéo dài đường xen kẽ dọc theo $P$ đến một trong hai đỉnh $u$ hoặc $w$. Như vậy trước khi tăng đã tồn tại một đường tăng bắt đầu từ $v$, mâu thuẫn với giả thiết.

### Cây xen kẽ

Một khái niệm khác liên quan chặt chẽ đến đường tăng là cây xen kẽ. Đây là cây sinh ra trong quá trình dùng DFS hoặc BFS từ một đỉnh chưa ghép cặp $r$ để tìm đường tăng.

Với đồ thị $G=(V,E)$ và một ghép cặp $M$ của nó, nếu đồ thị con $H\subseteq G$ là một cây có gốc là đỉnh chưa ghép cặp $r$, và đường đi nối $r$ với bất kỳ $v\in H$ nào đều là đường xen kẽ, thì $H$ được gọi là một **cây xen kẽ** (alternating tree). Trong cây, các đỉnh có độ sâu chẵn được gọi là đỉnh chẵn, còn các đỉnh có độ sâu lẻ được gọi là đỉnh lẻ.

Hình dưới minh họa một cây xen kẽ có thể thu được khi bắt đầu BFS từ đỉnh chưa ghép cặp $1$. (Trong hình, cạnh đỏ là cạnh ghép cặp, cạnh đen là cạnh không ghép cặp; đỉnh màu đậm là đỉnh đã ghép cặp, đỉnh màu nhạt là đỉnh chưa ghép cặp.)

![](images/alternating-tree.svg)

## Sự tồn tại của ghép cặp hoàn hảo

Trong lý thuyết ghép cặp đồ thị, có hai định lý tồn tại quan trọng, dùng để xác định liệu ghép cặp hoàn hảo có tồn tại trong đồ thị hai phía hoặc đồ thị tổng quát hay không.

### Định lý Hall

Giả sử $G=(X,Y,E)$ là đồ thị hai phía và $|X|\le |Y|$. Với một ghép cặp $M$ của đồ thị $G$, nếu mọi đỉnh trong $X$ đều là đỉnh đã ghép cặp, thì $M$ được gọi là một **ghép cặp $X$-hoàn hảo**, đôi khi cũng gọi tắt là ghép cặp hoàn hảo (của đồ thị hai phía $G$). Đây là ghép cặp lớn nhất có thể đạt được trong đồ thị hai phía. Định lý Hall đưa ra điều kiện cần và đủ để xác định kiểu ghép cặp này có tồn tại hay không.

Định lý Hall nói rằng chỉ cần bảo đảm rằng với mọi tập con của $X$, trong $Y$ có đủ nhiều đỉnh để ghép với nó, thì chắc chắn tồn tại ghép cặp $X$-hoàn hảo.

???+ note "Định lý Hall"
    Giả sử $G=(X,Y,E)$ là đồ thị hai phía và $|X|\le |Y|$. Với mọi $W\subseteq X$, ký hiệu $N_G(W)$ là tập tất cả các đỉnh trong đồ thị $G$ kề với các đỉnh thuộc $W$. Khi đó, ghép cặp $X$-hoàn hảo tồn tại khi và chỉ khi $|W|\le |N_G(W)|$ đúng với mọi $W\subseteq X$.

??? note "Chứng minh"
    Tính cần thiết là hiển nhiên. Giả sử tồn tại ghép cặp $X$-hoàn hảo $M$, thì mỗi đỉnh trong $X$ được ghép với một đỉnh khác nhau trong $Y$. Tập $N_G(W)$ ít nhất chứa các đỉnh được ghép với các đỉnh trong $W$, nên kích thước của nó ít nhất là $|W|$.
    
    Điều kiện cũng là đủ. Giả sử không tồn tại ghép cặp $X$-hoàn hảo, khi đó tồn tại một ghép cặp lớn nhất $M$ sao cho một đỉnh $v\in X$ vẫn chưa được ghép cặp. Gọi $Z$ là tập các đỉnh có thể đi tới bằng đường xen kẽ xuất phát từ $v$, và đặt $S=Z\cap X$, $T=Z\cap Y$. Tập $S\setminus\{v\}$ chắc chắn toàn là đỉnh đã ghép cặp, nếu không sẽ xuất hiện chu trình lẻ, mâu thuẫn với việc $G$ là đồ thị hai phía; tập $T$ cũng chắc chắn toàn là đỉnh đã ghép cặp, nếu không sẽ tồn tại đường tăng, mâu thuẫn với việc $M$ là ghép cặp lớn nhất theo bổ đề Berge. Vì tất cả đều là đỉnh đã ghép cặp, và ghép cặp chỉ có thể xảy ra giữa $X$ và $Y$, nên các đỉnh trong $S\setminus\{v\}$ và $T$ tương ứng một-một, tức là $|T|=|S|-1$. Đồng thời, vì các đỉnh trong $T$ đã được ghép với các đỉnh trong $S$, ít nhất ta có $T\subseteq N_G(S)$; nhưng trong $N_G(S)$ không tồn tại đỉnh chưa ghép cặp $u$, bởi nếu giả sử nó kề với một đỉnh $v'$ trong $S$, thì ta có thể kéo dài đường xen kẽ đi tới $v'$ để thu được một đường xen kẽ đi tới $u$. Điều này cho thấy $T=N_G(S)$. Các lập luận trên suy ra $|N_G(S)|<|S|$, mâu thuẫn với điều kiện của định lý Hall. Do đó ghép cặp $X$-hoàn hảo tồn tại.

???+ note "Hệ quả"
    Mọi đồ thị hai phía chính quy đều có ghép cặp hoàn hảo.

??? note "Chứng minh"
    Trong đồ thị hai phía chính quy, mọi đỉnh đều có cùng bậc, gọi là $k$. Trước hết kiểm tra điều kiện Hall, tức là với mọi $W\subseteq X$, ta có $|N_G(W)|\ge |W|$. Số cạnh kề với các đỉnh trong $W$ là $k|W|$, còn mỗi đỉnh trong tập $N_G(W)$ kề với nhiều nhất $k$ cạnh trong số đó, nên chắc chắn $k|W|\le k|N_G(W)|$, tức là $|W|\le |N_G(W)|$. Đặc biệt, $|X|\le |Y|$; vì $X$ và $Y$ đối xứng, ta cũng có $|X|=|Y|$. Điều này cho thấy trong đồ thị hai phía chính quy, ghép cặp $X$-hoàn hảo cũng chắc chắn là ghép cặp hoàn hảo. Vì định lý Hall bảo đảm tồn tại ghép cặp $X$-hoàn hảo, nên ghép cặp hoàn hảo cũng chắc chắn tồn tại.

### Định lý Tutte

Định lý Tutte đưa ra điều kiện cần và đủ để xác định trong đồ thị tổng quát có tồn tại ghép cặp hoàn hảo hay không. Điều kiện này bắt nguồn từ một quan sát trực tiếp: đồ thị có số đỉnh lẻ chắc chắn không tồn tại ghép cặp hoàn hảo.

???+ note "Định lý Tutte"
    Đồ thị $G=(V,E)$ tồn tại ghép cặp hoàn hảo khi và chỉ khi với mọi $U\subseteq V$, ta có $\operatorname{odd}(G-U)\le |U|$, trong đó $G-U$ là đồ thị con thu được bằng cách xóa khỏi $G$ các đỉnh thuộc $U$ cùng các cạnh kề với chúng, còn $\operatorname{odd}(G-U)$ là số thành phần liên thông có số đỉnh lẻ trong đồ thị con $G-U$.

??? note "Chứng minh"
    Chỉ cần xét đồ thị đơn, vì cạnh song song và khuyên không ảnh hưởng đến điều kiện Tutte cũng như sự tồn tại của ghép cặp hoàn hảo.
    
    Tính cần thiết của điều kiện tương đối dễ thấy. Giả sử tồn tại ghép cặp hoàn hảo $M$. Với mọi $U\subseteq V$, sau khi xóa các đỉnh thuộc $U$ khỏi đồ thị $G$, mỗi thành phần liên thông có số đỉnh lẻ đều có ít nhất một đỉnh không thể được ghép với đỉnh trong cùng thành phần liên thông đó; các đỉnh này chỉ có thể tìm cách ghép với các đỉnh thuộc $U$. Để phép ghép như vậy tồn tại, ít nhất cần có $\operatorname{odd}(G-U)\le |U|$. Đây chính là điều kiện Tutte.
    
    Tính đủ của điều kiện phức tạp hơn. Giả sử $G$ thỏa điều kiện Tutte nhưng không có ghép cặp hoàn hảo. Vì thêm bất kỳ cạnh nào vào $G$ vẫn giữ điều kiện Tutte đúng, nên không mất tính tổng quát, giả sử $G$ là một đồ thị cực đại như vậy: $G$ không có ghép cặp hoàn hảo, nhưng thêm bất kỳ cạnh $e$ nào chưa tồn tại vào $G$ thì $G+e$ đều có ghép cặp hoàn hảo. Gọi $U\subseteq V$ là tập tất cả các đỉnh có bậc bằng $|V|-1$. Có thể chứng minh rằng mỗi thành phần liên thông của $G-U$ đều là một đồ thị đầy đủ. Từ đó có thể xây dựng một ghép cặp hoàn hảo của $G$: trước hết lấy ghép cặp lớn nhất trong mỗi thành phần liên thông của $G-U$, khi đó chỉ những thành phần có số đỉnh lẻ mới để lại một đỉnh chưa ghép cặp; ghép các đỉnh chưa ghép cặp này với các đỉnh trong $U$; vì số đỉnh của $G$ là chẵn (lấy $U=\varnothing$ trong điều kiện Tutte), nên số đỉnh còn lại chưa được ghép trong $U$ cũng là chẵn, ta ghép chúng từng cặp. Mâu thuẫn này cho thấy không tồn tại đồ thị $G$ thỏa điều kiện Tutte nhưng không có ghép cặp hoàn hảo.
    
    Điểm mấu chốt là phải chứng minh mỗi thành phần liên thông của $G-U$ đều là đồ thị đầy đủ. Giả sử ngược lại. Không mất tính tổng quát, giả sử các đỉnh $x,y,z$ thuộc một thành phần liên thông như vậy, với $(x,y)\in E$, $(y,z)\in E$, $(x,z)\notin E$. Hơn nữa, vì $y\notin U$, chắc chắn tồn tại $w\in V\setminus U$ nhưng $(y,w)\notin E$. Do tính cực đại của $G$, các đồ thị $G+(x,z)$ và $G+(y,w)$ lần lượt có các ghép cặp hoàn hảo $M_1$ và $M_2$. Xét hiệu đối xứng $M_1\oplus M_2$. Vì trong đồ thị $(V,M_1\oplus M_2)$, bậc của mọi đỉnh hoặc là $0$ hoặc là $2$, nên $M_1\oplus M_2$ thực ra là hợp rời của một số chu trình chẵn, và mỗi chu trình chẵn được tạo bởi các cạnh ghép cặp của $M_1$ và $M_2$ xen kẽ nhau.
    
    ![](images/tutte-proof.svg)
    
    Như hình minh họa, có thể chia làm hai trường hợp:
    
    -   $(x,z)$ và $(y,w)$ nằm trên hai chu trình khác nhau (như hình bên trái): gọi chu trình chứa $(y,w)$ là $C$, khi đó tập cạnh $M_2\oplus C$ là một ghép cặp hoàn hảo của đồ thị $G$;
    -   $(x,z)$ và $(y,w)$ nằm trên cùng một chu trình (như hình bên phải): do tính đối xứng, không mất tính tổng quát, giả sử chu trình lần lượt đi qua $x,y,w,z$. Khi đó lấy đường đi $P$ trên chu trình từ $y$ qua $w$ đến $z$, và gọi $\{(y,z)\}\cup P$ là chu trình $C$; tập cạnh $M_2\oplus C$ cũng là một ghép cặp hoàn hảo của đồ thị $G$.
    
    Dù ở trường hợp nào, ta cũng mâu thuẫn với cách chọn $G$. Mâu thuẫn này chứng minh rằng mỗi thành phần liên thông của $G-U$ đều là đồ thị đầy đủ.

???+ note "Hệ quả"
    Mọi đồ thị 3-chính quy không có cầu đều có ghép cặp hoàn hảo.

??? note "Chứng minh"
    Để kiểm tra điều kiện Tutte, lấy tùy ý $U\subseteq V$ và cần chứng minh $\operatorname{odd}(G-U)\le |U|$. Gọi $G_1,\cdots,G_n$ là tất cả các thành phần liên thông có số đỉnh lẻ của $G-U$. Gọi $m_i$ là số cạnh nối đỉnh trong $G_i$ với đỉnh trong $U$. Một phép đếm đơn giản cho thấy
    
    $$
    3|V(G_i)| = \sum_{v\in V(G_i)} d(v) = 2|E(G_i)| + m_i.
    $$
    
    Do đó, $m_i$ chắc chắn là số lẻ. Vì $G$ không có cầu (tức là cạnh cắt), nên $m_i\ge 3$. Điều này cho thấy
    
    $$
    \operatorname{odd}(G-U) = n \le \dfrac{1}{3}\sum_{i=1}^n m_i \le \dfrac{1}{3}\sum_{v\in U} d(v) = |U|.
    $$
    
    Vì vậy, điều kiện Tutte đúng và đồ thị $G$ chắc chắn có ghép cặp hoàn hảo.

## Các thuật toán thường gặp

Một bài toán cơ bản trong tối ưu tổ hợp là tìm ghép cặp lớn nhất và ghép cặp trọng số lớn nhất trong đồ thị.

### Ghép cặp lớn nhất trong đồ thị hai phía

Xem chi tiết tại trang [ghép cặp lớn nhất trong đồ thị hai phía](./bigraph-match.md).

Trong đồ thị hai phía không trọng số, có thể dùng thuật toán Kuhn để giải trong thời gian $O(|V||E|)$, hoặc dùng thuật toán Hopcroft–Karp để giải trong thời gian $O(|V|^{1/2}|E|)$.

### Ghép cặp trọng số lớn nhất trong đồ thị hai phía

Xem chi tiết tại trang [ghép cặp trọng số lớn nhất trong đồ thị hai phía](./bigraph-weight-match.md).

Trong đồ thị hai phía có trọng số, có thể dùng thuật toán Hungarian. Nếu dùng thuật toán Bellman–Ford khi tìm đường đi ngắn nhất, độ phức tạp thời gian là $O(|V|^2|E|)$; nếu dùng thuật toán Dijkstra hoặc Fibonacci heap, có thể giải trong thời gian $O(|V|^{2}\log {|V|}+|V||E|)$.

### Ghép cặp lớn nhất trong đồ thị tổng quát

Xem chi tiết tại trang [ghép cặp lớn nhất trong đồ thị tổng quát](./general-match.md).

Trong đồ thị tổng quát không trọng số, có thể dùng thuật toán Edmonds' blossom để giải trong thời gian $O(|V|^2|E|)$.

### Ghép cặp trọng số lớn nhất trong đồ thị tổng quát

Xem chi tiết tại trang [ghép cặp trọng số lớn nhất trong đồ thị tổng quát](./general-weight-match.md).

Trong đồ thị tổng quát có trọng số, có thể dùng thuật toán Edmonds' blossom để giải trong thời gian $O(|V|^2|E|)$.

## Các vấn đề liên quan

Ghép cặp lớn nhất (có trọng số) có liên hệ chặt chẽ với nhiều bài toán lý thuyết đồ thị khác. Phần này chỉ thảo luận đồ thị tổng quát; các kết luận cho đồ thị hai phía có thể xem tại trang [ghép cặp lớn nhất trong đồ thị hai phía](./bigraph-match.md#các-bài-toán-liên-quan).

### Ghép cặp lớn nhất có trọng số lớn nhất

Bài toán ghép cặp lớn nhất có trọng số lớn nhất và bài toán ghép cặp trọng số lớn nhất có thể quy về nhau. Một khác biệt rất đáng chú ý giữa chúng là trong ghép cặp lớn nhất có trọng số lớn nhất có thể tồn tại cạnh trọng số âm, nhưng trong ghép cặp trọng số lớn nhất sẽ không tồn tại cạnh trọng số âm.

Trước hết, bài toán ghép cặp trọng số lớn nhất có thể quy về bài toán ghép cặp lớn nhất có trọng số lớn nhất. Đầu tiên, đặt trọng số của mọi cạnh âm trong đồ thị $G$ thành $0$; sau đó mở rộng đồ thị thành đồ thị đầy đủ $G'$ bằng cách nối thêm một số cạnh có trọng số $0$. Chú ý rằng trong đồ thị đầy đủ có trọng số cạnh không âm, ghép cặp lớn nhất có trọng số lớn nhất và ghép cặp trọng số lớn nhất là như nhau. Vì vậy, chỉ cần tính ghép cặp lớn nhất có trọng số lớn nhất $M'$ của $G'$, rồi xóa tất cả các cạnh trọng số không trong $M'$, tập cạnh $M$ thu được chính là ghép cặp trọng số lớn nhất của đồ thị $G$.[^other-approach]

![ghép cặp đồ thị](images/graph-match-5.svg)

Ngược lại, bài toán ghép cặp lớn nhất có trọng số lớn nhất cũng có thể quy về bài toán ghép cặp trọng số lớn nhất. Chỉ cần cộng một số dương đủ lớn $K$ vào trọng số của mọi cạnh trong đồ thị $G$, ta có thể bảo đảm rằng ghép cặp trọng số lớn nhất của đồ thị $G'$ thu được cũng chắc chắn là ghép cặp lớn nhất, và do đó tất yếu là ghép cặp lớn nhất có trọng số lớn nhất. Lý do là việc tính ghép cặp trọng số lớn nhất của $G'$ tương đương với tối đa hóa biểu thức sau trên tất cả các ghép cặp của đồ thị $G$:

$$
K|M| + \sum_{e\in M}w(e).
$$

Khi $K$ đủ lớn, lợi ích $K$ từ việc ghép thêm một cạnh sẽ vượt quá mức thay đổi của tổng trọng số ở hạng sau. Vì vậy, thuật toán trước tiên sẽ ghép nhiều cạnh nhất có thể, rồi mới tối đa hóa tổng trọng số của các cạnh ghép cặp. Chỉ cần chọn hằng số $K$ sao cho nó lớn hơn chặt chẽ mọi chênh lệch có thể giữa hai ghép cặp. Một lựa chọn hiển nhiên là

$$
K = \sum_{e\in E}|w(e)| + 1.
$$

![ghép cặp đồ thị](images/graph-match-6.svg)

### Phủ cạnh nhỏ nhất (có trọng số)

Một bài toán khác liên quan chặt chẽ đến ghép cặp lớn nhất (có trọng số) là phủ cạnh nhỏ nhất (có trọng số). Quan hệ giữa phủ cạnh và ghép cặp (còn gọi là tập cạnh độc lập) tương tự quan hệ giữa phủ đỉnh và tập độc lập.

Trong đồ thị $G=(V,E)$, một tập cạnh $C\subseteq E$ được gọi là một **phủ cạnh** (edge cover) của đồ thị $G$ nếu mọi đỉnh $v\in V$ đều là đầu mút của một cạnh nào đó trong $C$. Khi thảo luận phủ cạnh, ta luôn giả sử đồ thị $G$ không có đỉnh cô lập.

Với đồ thị không trọng số, bài toán phủ cạnh nhỏ nhất gần như chính là bài toán ghép cặp lớn nhất. Với bất kỳ ghép cặp lớn nhất $M$ nào của đồ thị $G$, chỉ cần thêm cho mỗi đỉnh chưa ghép cặp một cạnh kề với nó, ta thu được một phủ cạnh nhỏ nhất $C$. Kích thước của chúng thỏa mãn hệ thức đếm đơn giản: $|M|+|C|=|V|$. Hình dưới là một số ví dụ về phủ cạnh nhỏ nhất:

![ghép cặp đồ thị](images/graph-match-7.svg)

Với đồ thị có trọng số, bài toán phủ cạnh trọng số nhỏ nhất có thể quy về một bài toán **ghép cặp hoàn hảo trọng số nhỏ nhất**. Trước hết, sao chép đồ thị $G=(V,E)$ thành $\tilde G=(\tilde V,\tilde E)$ với trọng số cạnh giữ nguyên như đồ thị ban đầu; sau đó nối mỗi đỉnh $v\in V$ với bản sao $\tilde v\in\tilde V$ của nó, với trọng số bằng giá trị nhỏ nhất trong các trọng số của những cạnh kề với $v$ trong đồ thị $G$. Ký hiệu đồ thị thu được là $G'=(V',E')$. Nếu đồ thị $G$ là đồ thị hai phía hoặc đồ thị thưa, thì $G'$ tương ứng cũng là đồ thị hai phía hoặc đồ thị thưa. Hơn nữa, bài toán phủ cạnh trọng số nhỏ nhất của đồ thị $G$ được quy về bài toán ghép cặp hoàn hảo trọng số nhỏ nhất của đồ thị $G'$[^edge-cover]: với ghép cặp hoàn hảo trọng số nhỏ nhất $M'$ của đồ thị $G'$, chỉ cần giữ lại các cạnh thuộc $E$, rồi thay mọi cạnh đã ghép dạng $(v,v')$ bằng cạnh có trọng số nhỏ nhất kề với $v$ trong đồ thị $G$, ta thu được phủ cạnh trọng số nhỏ nhất của đồ thị $G$.

## Tài liệu tham khảo

1.  [Wikiwand - Matching (graph theory)](https://www.wikiwand.com/en/Matching_%28graph_theory%29)
2.  [Wikiwand - Blossom algorithm](https://www.wikiwand.com/en/Blossom_algorithm)
3.  Bài viết năm 2015 "Bàn về thuật toán ghép cặp trong đồ thị và ứng dụng" - Chen Yinbo
4.  [Ghi chú thuật toán - Matching](http://web.ntnu.edu.tw/~algo/Matching.html)
5.  [the-tourist/algo](https://github.com/the-tourist/algo)
6.  [Bill Yang's Blog - Ghi chú học thuật toán blossom](https://blog.bill.moe/blossom-algorithm-notes/)
7.  [Ghép cặp lớn nhất, ghép cặp hoàn hảo và thuật toán Hungarian trong đồ thị hai phía](https://www.renfei.org/blog/bipartite-matching.html)
8.  [Wikiwand - Hopcroft–Karp algorithm](https://www.wikiwand.com/en/Hopcroft%E2%80%93Karp_algorithm)
9.  Bondy, John Adrian, and Uppaluri Siva Ramachandra Murty. Graph theory with applications. Vol. 290. London: Macmillan, 1976.

[^other-approach]: Tất nhiên, đây không phải cách quy về duy nhất. Với đồ thị $G=(V,E)$, ta cũng có thể lấy một bản sao $\tilde G=(\tilde V,\tilde E)$ của nó, nối từng đỉnh của bản sao vào đồ thị ban đầu, và đặt trọng số của mọi cạnh mới so với đồ thị gốc $G$ (bao gồm cả các cạnh trong bản sao) bằng $0$, thu được đồ thị $G'=(V',E')$. Nói cách khác, tập đỉnh của đồ thị mới $G'$ là $V\cup \tilde V$, còn tập cạnh của nó ngoài các cạnh trong đồ thị $G$ còn có cạnh trọng số không nối mỗi đỉnh $v\in V$ với bản sao $\tilde v\in \tilde V$ của nó, và với mọi cạnh $(u,v)\in E$, có cạnh trọng số không nối $\tilde u$ với $\tilde v$. Mọi ghép cặp $M$ trong đồ thị $G$ đều tương ứng với một ghép cặp hoàn hảo trong đồ thị $G'$ có cùng tổng trọng số: chỉ cần ghép mọi đỉnh chưa ghép cặp $v$ của $G$ với bản sao $\tilde v$ của nó, và với mỗi cạnh ghép cặp $(u,v)$, ghép $\tilde u$ với $\tilde v$. Do đó, ghép cặp lớn nhất có trọng số lớn nhất trong đồ thị $G'$, tức là ghép cặp hoàn hảo trọng số lớn nhất, khi giới hạn lại trên $E$ sẽ cho ghép cặp trọng số lớn nhất của đồ thị $G$. Ưu điểm của cách quy về này là nếu đồ thị $G$ là đồ thị hai phía hoặc đồ thị thưa, thì đồ thị mở rộng $G'$ thu được cũng tương ứng là đồ thị hai phía hoặc đồ thị thưa.

[^edge-cover]: Với mỗi ghép cặp hoàn hảo $M'$ của đồ thị $G'$, đều có thể theo cách mô tả ở đây để thu được một phủ cạnh $C$ của đồ thị $G$, và tổng trọng số của $C$ bằng một nửa tổng trọng số của $M'$; đảo ngược quá trình xây dựng này, với mỗi phủ cạnh $C$ của đồ thị $G$, đều có thể xây dựng một ghép cặp hoàn hảo $M'$ của đồ thị $G'$, và tổng trọng số của $M'$ không vượt quá hai lần tổng trọng số của $C$. Điều đó chứng minh phép quy về là đúng.
