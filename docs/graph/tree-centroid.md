author: Ir1d, Marcythm, LucienShui, Anguei, H-J-Granger, CornWorld, ttzc

Bài viết này giới thiệu khái niệm và các tính chất cơ bản của trọng tâm cây.

## Định nghĩa

Nếu sau khi xóa một đỉnh $v$ khỏi cây $T$, mọi thành phần liên thông của đồ thị thu được $T\setminus\{v\}$ đều có kích thước không vượt quá một nửa số đỉnh của cây ban đầu, thì $v$ được gọi là **trọng tâm** (centroid) của cây. Kích thước của thành phần liên thông lớn nhất sau khi xóa một đỉnh còn được gọi là **trọng số** (weight) của đỉnh đó. Theo cách nói này, trọng tâm là đỉnh có trọng số không vượt quá một nửa số đỉnh của cây.

???+ info "Cây con"
    Bài viết này có thể đồng thời đề cập đến cây không gốc, cây có gốc, và cây thu được khi đổi gốc của một cây có gốc sang đỉnh khác. Để tránh nhầm lẫn, bài viết dùng $T$ cho cây không gốc và dùng $T^{(v)}$ cho cây có gốc tại đỉnh $v$. Trong bài viết này, "cây con" luôn chỉ cây gồm một đỉnh và toàn bộ hậu duệ của nó trong **cây có gốc**. Trong cây có gốc $T^{(v)}$, cây con ứng với đỉnh $u$ được ký hiệu là $T^{(v)}_u$. Cây con theo định nghĩa này có thể là toàn bộ cây ban đầu. Nếu cần nhấn mạnh rằng nó không phải toàn bộ cây, ta gọi đó là "cây con thực sự".
    
    Trong cây không gốc, "cây con" thường được dùng cho một đồ thị con liên thông. Khi thảo luận về trọng tâm, một số tác giả dùng "cây con" để chỉ đồ thị con liên thông cực đại không chứa một đỉnh nào đó, hoặc để chỉ một trong hai thành phần liên thông thu được sau khi xóa một cạnh. Hai cách hiểu này cho cùng một tập "cây con", và tập đó không chứa toàn bộ cây. Vì tập này khác với tập các cây con của cây có gốc, bài viết sẽ tránh dùng khái niệm "cây con" cho cây không gốc.
    
    Khi tìm trọng tâm hoặc giải một số bài toán, ta thường ngầm chọn một gốc cho cây. Khi đó, trong các thành phần liên thông thu được sau khi xóa một đỉnh không phải gốc $v$, ngoài các cây con ứng với các đỉnh con của $v$, còn có một thành phần "phía trên". Nếu cha của $v$ là $u$, thì thành phần "phía trên" này chính là $T_u^{(v)}$. Khi cần nhắc đến loại đồ thị con này, bài viết gọi nó là cây con "hướng lên". Nếu không có ghi chú đặc biệt, các cây con được nói đến trong bài viết đều không bao gồm cây con "hướng lên" này.

Lưu ý rằng các thành phần liên thông thu được cũng là cây không gốc. Khi xóa trọng tâm, cây được tách thành nhiều cây có kích thước tối đa bằng một nửa cây ban đầu. Tính chất này cho phép áp dụng chia để trị trên cây, tức [phân trị theo đỉnh](./tree-divide.md#phân-trị-theo-đỉnh), còn gọi là phân rã trọng tâm.

## Tính chất

Phần này thảo luận các tính chất của trọng tâm. Trước hết, trọng tâm của cây có các định nghĩa tương đương sau:

???+ note "Định nghĩa tương đương"
    Đỉnh $v$ trong cây $T$ là trọng tâm của cây khi và chỉ khi một trong các điều kiện tương đương sau đúng:
    
    === "Phiên bản cây không gốc"
        1.  Sau khi xóa đỉnh $v$ trong cây, mọi thành phần liên thông của đồ thị thu được $T\setminus\{v\}$ đều có kích thước không vượt quá một nửa số đỉnh của cây ban đầu.
        2.  Trong các giá trị "kích thước thành phần liên thông lớn nhất sau khi xóa một đỉnh", giá trị ứng với $v$ là nhỏ nhất.
        3.  Trong các tổng khoảng cách từ mọi đỉnh của cây đến một đỉnh được chọn, tổng khoảng cách đến $v$ là nhỏ nhất.
    
    === "Phiên bản cây có gốc"
        1.  Khi cây được lấy gốc tại đỉnh $v$, kích thước của mọi cây con thực sự đều không vượt quá một nửa số đỉnh của cây ban đầu.
        2.  Trong các giá trị "kích thước cây con thực sự lớn nhất khi chọn gốc", giá trị ứng với gốc $v$ là nhỏ nhất.
        3.  Trong các tổng độ sâu của mọi đỉnh khi chọn gốc, tổng độ sâu ứng với gốc $v$ là nhỏ nhất.

??? note "Chứng minh"
    Trước hết, đặt một số ký hiệu. Hai cách phát biểu theo cây có gốc và cây không gốc là tương đương. Định nghĩa $W(x)=\max_{u\sim x}|T_u^{(x)}|$, trong đó $u\sim x$ nghĩa là $u$ kề với $x$. Định nghĩa $S(x)=\sum_{u\in T}d(u,x)$, trong đó $d(u,x)$ là khoảng cách giữa $u$ và $x$. Khi đó, định nghĩa 1 tương đương với $W(v)\le |T|/2$, định nghĩa 2 tương đương với $v\in\arg\min_{x\in T}W(x)$, còn định nghĩa 3 tương đương với $v\in\arg\min_{x\in T}S(x)$. Ta cần chứng minh ba điều kiện này tương đương.
    
    Xem $S(x)$ là tổng độ sâu của các đỉnh khi lấy $x$ làm gốc, rồi xét sự thay đổi của nó khi đổi gốc từ đỉnh $v$ sang đỉnh kề $u$. Sau khi xóa cạnh $(v,u)$, hai thành phần liên thông thu được lần lượt là các cây con $T_v^{(u)}$ và $T_u^{(v)}$. Khi đổi gốc, độ sâu của mỗi đỉnh trong $T_v^{(u)}$ tăng $1$, còn độ sâu của mỗi đỉnh trong $T_u^{(v)}$ giảm $1$, nên thay đổi của tổng độ sâu là
    
    $$
    \Delta S_{v\to u} = S(u) - S(v) = |T_v^{(u)}| - |T_u^{(v)}| = |T| - 2|T_u^{(v)}|.
    $$
    
    Vì vậy, điều kiện trong định nghĩa 1 tương đương với yêu cầu $\Delta S_{v\to u}\ge 0$ với mọi đỉnh $u$ kề với $v$, tức $v$ là một điểm cực tiểu cục bộ của $S(x)$.
    
    Ngược lại, giả sử $v$ là một điểm đạt giá trị nhỏ nhất của $S(x)$, tức thỏa định nghĩa 3. Điểm đạt giá trị nhỏ nhất tồn tại và cũng là một điểm cực tiểu cục bộ. Xét cây có gốc $T^{(v)}$. Với một đỉnh không phải gốc $u\neq v$, trên đường đi có hướng từ $v$ đến $u$, gọi $y$ là đỉnh ngay sau $v$ (có thể chính là $u$) và $x$ là đỉnh ngay trước $u$ (có thể chính là $v$). Khi đó, vì $T_u^{(x)}\subseteq T_y^{(v)}$, ta có
    
    $$
    2|T_x^{(u)}| = 2|T| - 2|T_u^{(x)}| \ge 2|T| - 2|T_y^{(v)}| \ge |T|.
    $$
    
    Bước cuối dùng việc $v$ là điểm cực tiểu cục bộ của $S(x)$. Lúc này có hai trường hợp:
    
    -   Tồn tại đỉnh $u$ sao cho $2|T_x^{(u)}|=|T|$. Khi đó, theo bất đẳng thức trên, phải có $(x,u)=(v,y)$ và $|T_v^{(u)}|=|T_{u}^{(v)}| = |T|/2$. Nghĩa là đỉnh đạt dấu bằng như vậy nếu có thì là duy nhất, và đỉnh đó kề với $v$. Với mọi đỉnh khác $u'\neq u,v$, tồn tại $x'\sim u'$ sao cho $|T_{x'}^{(u')}| > |T|/2$.
        Tập các đỉnh thỏa điều kiện 1 là $\{v,u\}$.
    
        Khi xóa bất kỳ đỉnh nào, tổng kích thước các thành phần liên thông thu được luôn là $|T|-1$. Vì thế, nếu có một thành phần liên thông có kích thước không nhỏ hơn $|T|/2$, nó chính là thành phần liên thông lớn nhất. Do đó, trong trường hợp này, $W(v)=W(u)=|T|/2$, còn với mọi $u'\neq u,v$ đều có $W(u') > |T|/2$. Vì vậy, tập các đỉnh thỏa điều kiện 2 là $\arg\min W(x) = \{v,u\}$.
    
        Lại vì $\Delta S_{v\to u} = 0$, nên $S(v)=S(u)$. Vì $v$ là điểm đạt giá trị nhỏ nhất, $u$ cũng đạt giá trị nhỏ nhất. Với mọi $u'\neq u,v$, đều tồn tại $x'\sim u'$ sao cho $|T_{x'}^{(u')}| > |T|/2$; điều này vi phạm điều kiện cần của một điểm cực tiểu cục bộ, nên $u'$ không thể đạt giá trị nhỏ nhất. Do đó, tập các đỉnh thỏa điều kiện 3 là $\arg\min S(x) = \{v,u\}$.
    -   Không tồn tại đỉnh $u$ sao cho $2|T_x^{(u)}|=|T|$. Khi đó, với mọi đỉnh $u\neq v$, đều tồn tại đỉnh $x\sim u$ sao cho $|T_x^{(u)}| > |T|/2$. Lặp lại phân tích trên, với mọi $u\neq v$, có $W(u) > |T|/2$, và $u$ không phải điểm cực tiểu cục bộ của $S(x)$. Do đó, chỉ có $v$ thỏa điều kiện 1, và $\arg\min W(x)=\arg\min S(x) = \{v\}$.
    
    Trong cả hai trường hợp, tập các đỉnh thỏa ba điều kiện đều giống nhau. Vậy ba định nghĩa là tương đương.

Ngoài các định nghĩa tương đương này, trọng tâm của cây còn có các tính chất thường gặp sau:

???+ note "Tính chất"
    1.  Nếu trọng tâm của cây không duy nhất, thì có đúng hai trọng tâm. Hai trọng tâm này kề nhau. Hơn nữa, sau khi xóa cạnh nối chúng, cây sẽ biến thành hai thành phần liên thông có kích thước bằng nhau.
    2.  Nếu thêm một lá vào cây hoặc xóa một lá khỏi cây, trọng tâm của cây di chuyển nhiều nhất một cạnh.
    3.  Khi nối hai cây bằng một cạnh để thu được cây mới, trọng tâm của cây mới nằm trên đường đi nối các trọng tâm của hai cây ban đầu.
    4.  Trọng tâm của cây có gốc luôn nằm trên chuỗi nặng chứa gốc. Trọng tâm của toàn cây là tổ tiên của trọng tâm của cây con ứng với con nặng của gốc.

??? note "Chứng minh"
    Tính chất 1 có thể suy ra từ chứng minh các định nghĩa tương đương của trọng tâm.
    
    Với tính chất 2, xét riêng trường hợp thêm một đỉnh lá. Trường hợp này lại chia thành hai trường hợp:
    
    -   Cây $T$ chỉ có một trọng tâm $v$. Đặt $x$ là đỉnh lá mới được thêm vào, và trong đồ thị $T\cup\{x\}\setminus\{v\}$ thu được sau khi xóa đỉnh $v$ trong cây mới, thành phần liên thông chứa $x$ là $B\cup\{x\}$. Vì $v$ là trọng tâm duy nhất của cây $T$, nên $2|B| < |T|$, tức là $2|B|+1\le |T|$. Suy ra
    
        $$
        2|B\cup\{x\}| = 2(|B|+1) \le |T| + 1 = |T\cup\{x\}|.
        $$
    
        Do đó, $v$ vẫn là trọng tâm của cây mới $T\cup\{x\}$. Ngay cả khi cây mới có hai trọng tâm, trọng tâm còn lại cũng phải kề với $v$. Vì vậy, trọng tâm di chuyển nhiều nhất một cạnh.
    -   Cây $T$ có hai trọng tâm $u,v$. Khi đó, hai thành phần liên thông $T_u^{(v)}$ và $T_v^{(u)}$ thu được sau khi xóa $(u,v)$ có kích thước bằng nhau, đều bằng $|T|/2$. Không mất tính tổng quát, giả sử đỉnh lá mới thêm $x$ được nối vào thành phần liên thông $T_v^{(u)}$ chứa $v$. Khi đó, vì
    
        $$
        |T_v^{(u)}\cup\{x\}| = |T|/2 + 1 > (|T|+1)/2 = |T\cup\{x\}|/2,
        $$
    
        nên $u$ không còn là trọng tâm của cây mới. Ngược lại, sau khi xóa $v$, vẫn có thành phần liên thông $T_u^{(v)}$ có kích thước $|T|/2$, trong khi tổng kích thước các thành phần liên thông khác là
    
        $$
        |T\cup\{x\}| - 1 - |T_u^{(v)}| = |T|/2 \le |T_u^{(v)}|,
        $$
    
        nên $v$ vẫn là trọng tâm của cây mới. Vì cây mới có số đỉnh lẻ, trọng tâm là duy nhất. Do đó, trọng tâm cũng di chuyển nhiều nhất một cạnh.
    
    Từ hai trường hợp trên, trọng tâm của cây mới nằm trên đường đi từ trọng tâm của cây cũ đến đỉnh lá mới thêm.
    
    Tính chất 3 có thể được chứng minh bằng quy nạp. Giả sử khi nối $T$ và $T'$, cạnh mới thêm là $(x,y)$, với $x\in T,y\in T'$. Không mất tính tổng quát, giả sử một trọng tâm của cây mới nằm trong $T$. Xét quá trình bắt đầu từ cây $T$ rồi lần lượt thêm các đỉnh trong $T'$ như các lá. Ta chứng minh bằng quy nạp rằng luôn có một trọng tâm nằm trên đường đi nối trọng tâm của cây $T$ với đỉnh $x$. Trường hợp cơ sở là hiển nhiên. Giả sử mệnh đề đúng đến một thời điểm nào đó, và trọng tâm hiện tại là $v$. Theo phân tích của tính chất 2, trọng tâm của cây sau khi thêm lá nằm trên đường đi nối đỉnh mới thêm với trọng tâm hiện tại $v$. Hơn nữa, vì trọng tâm đang xét không đi ra ngoài cây $T$, ta chỉ cần xét phần giao của đường đi đó với $T$, tức đường đi nối $v$ và $x$. Theo giả thiết quy nạp, $v$ nằm trên đường đi nối trọng tâm của cây $T$ với $x$, nên trọng tâm mới cũng nằm trên đường đi này. Vậy tính chất được chứng minh.
    
    Với tính chất 4, chỉ cần kết hợp với [tính chất của phân rã chuỗi nặng](./hld.md#tính-chất-của-phân-rã-chuỗi-nặng). Giả sử $v$ là một trọng tâm của cây $T$. Nếu $v$ là gốc thì mệnh đề đúng ngay. Xét trường hợp $v$ không phải gốc, và $u$ là cha của $v$. Vì $|T_u^{(v)}| \le |T|/2$, kích thước cây con chứa $v$ ít nhất là $|T|/2$. Nếu đường đi từ $v$ đến gốc đi qua một cạnh nhẹ, kích thước cây con chứa $v$ sẽ nhỏ hơn hẳn $|T|/2$, mâu thuẫn. Vì vậy, $v$ nằm trên chuỗi nặng chứa gốc. Tiếp theo, theo định nghĩa chuỗi nặng, trong cây con ứng với con nặng của gốc, chuỗi nặng chứa gốc là một phần của chuỗi nặng chứa gốc trong cây ban đầu. Hơn nữa, theo tính chất 3, sau khi thêm con nặng và tất cả các cây con ứng với các con nhẹ vào cây con ứng với con nặng, vị trí trọng tâm chỉ di chuyển dọc theo đường đi giữa trọng tâm hiện tại và gốc, nên trọng tâm mới là tổ tiên của trọng tâm cũ.

## Cách tìm

Theo các định nghĩa tương đương ở trên, có hai cách tìm tất cả trọng tâm của cây trong thời gian $O(n)$, với $n$ là số đỉnh.

### DFS thống kê kích thước cây con

Có thể dùng DFS để tính kích thước của từng cây con. Với mỗi đỉnh, ghi lại kích thước các cây con ứng với mọi đỉnh con của nó, đồng thời lấy tổng số đỉnh trừ đi kích thước cây con hiện tại để thu được kích thước của cây con "hướng lên". Sau đó tìm trọng tâm theo định nghĩa.

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-centroid/tree-centroid-2.cpp:core"
    ```

### DP đổi gốc để thống kê tổng độ sâu

Một cách khác là dùng DP đổi gốc để tính tổng độ sâu của tất cả các đỉnh khi lần lượt lấy từng đỉnh làm gốc, tức tổng khoảng cách đến gốc hiện tại. Theo định nghĩa, chỉ cần tìm đỉnh làm cho tổng độ sâu này nhỏ nhất.

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-centroid/tree-centroid-3.cpp:core"
    ```

## Ví dụ

???+ example "[Codeforces Round 359 (Div. 1) B. Kay and Snowflake](https://codeforces.com/problemset/problem/685/B)"
    Cho một cây có gốc, cần tìm trọng tâm của mỗi cây con.

??? note "Ý tưởng lời giải"
    Theo tính chất 3, với một cây con có gốc tại đỉnh $u$, trọng tâm của nó nằm trên các đường đi từ trọng tâm của mỗi cây con có gốc tại một đỉnh con trực tiếp của $u$ đến $u$.
    
    Tương tự cách tìm trọng tâm bằng DFS ở trên, với mỗi cây con có gốc tại đỉnh $u$, trước tiên tìm trọng tâm của tất cả các cây con có gốc tại các đỉnh con trực tiếp của nó (trọng tâm của một đỉnh lá là chính nó), rồi lần ngược lên để kiểm tra các đỉnh trên đường đi có phải trọng tâm hay không.
    
    Có thể tìm trọng tâm của tất cả các cây con trong thời gian $O(n)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-centroid/tree-centroid-1.cpp"
    ```

## Bài tập

-   [Gym 101649G Godfather](https://codeforces.com/gym/101649/problem/G)
-   [POJ 1655 Balancing Art](http://poj.org/problem?id=1655)
-   [Luogu P1364 Hospital Setup](https://www.luogu.com.cn/problem/P1364)
-   [Codeforces 1406C Link Cut Centroids](https://codeforces.com/contest/1406/problem/C)
-   [Codeforces 708C Centroids](https://codeforces.com/problemset/problem/708/C)

## Tài liệu tham khảo

-   [Một số tính chất và cách duy trì động của "trọng tâm" cây - fanhq666](https://web.archive.org/web/20181122041458/http://fanhq666.blog.163.com/blog/static/81943426201172472943638) ([bản đăng lại trên CNBlogs](https://www.cnblogs.com/qlky/p/5781081.html))
-   [Đường kính của cây, trọng tâm của cây và phân trị theo đỉnh trên cây - cyendra](https://www.cnblogs.com/zinthos/p/3899075.html)
-   [Tính chất của trọng tâm cây và chứng minh - suxxsfe](https://www.cnblogs.com/suxxsfe/p/13543253.html)
-   Từ điển Olympic Tin học, chương 2.4.7.11, mục 1. Trọng tâm của cây
