author: Ir1d, Marcythm, LucienShui, Anguei, H-J-Granger, CornWorld, ttzc

Bài viết này giới thiệu khái niệm và các tính chất cơ bản của trọng tâm cây.

## Định nghĩa

Nếu sau khi xóa một đỉnh $v$ trong cây $T$, mọi thành phần liên thông của đồ thị thu được $T\setminus\{v\}$ đều có kích thước không vượt quá một nửa số đỉnh của cây ban đầu, thì đỉnh $v$ được gọi là **trọng tâm** (centroid) của cả cây. Kích thước của thành phần liên thông lớn nhất sau khi xóa một đỉnh cũng được gọi là **trọng số** (weight) của đỉnh đó. Dựa trên khái niệm này, có thể phát biểu định nghĩa trọng tâm là đỉnh có trọng số không vượt quá một nửa số đỉnh của cây.

???+ info "Cây con"
    Bài viết này có thể đồng thời đề cập đến cây không gốc, cây có gốc, và cây thu được khi đổi gốc của cây có gốc sang một đỉnh không phải gốc. Để tránh nhầm lẫn, bài viết dùng $T$ để biểu diễn cây không gốc, và dùng $T^{(v)}$ để biểu diễn cây có gốc tại đỉnh $v$. Trong bài viết này, "cây con" đều chỉ cây gồm một đỉnh và tất cả các đỉnh hậu duệ của nó trong **cây có gốc**. Trong cây có gốc $T^{(v)}$, cây con tương ứng với đỉnh $u$ được ký hiệu là $T^{(v)}_u$. Cây con được định nghĩa như vậy hiển nhiên bao gồm cả bản thân cây ban đầu. Nếu cần nói rõ là không bao gồm cả cây, ta gọi nó là "cây con thực sự".
    
    Trong cây không gốc, "cây con" thường chỉ một đồ thị con liên thông của nó. Khi thảo luận về trọng tâm, một số tác giả dùng từ "cây con" riêng để chỉ đồ thị con liên thông cực đại không chứa một đỉnh nào đó, hoặc riêng để chỉ một trong hai thành phần liên thông thu được sau khi xóa một cạnh nào đó. Dễ thấy rằng hai cách định nghĩa này cho ra cùng một tập "cây con", và tập này không bao gồm chính cả cây. Vì tập đó không trùng với tập các cây con của cây có gốc, bài viết này sẽ tránh dùng khái niệm "cây con" cho cây không gốc.
    
    Khi thực tế tìm trọng tâm hoặc xử lý một số bài toán, thường có một gốc cây ngầm định. Khi đó, trong các thành phần liên thông thu được sau khi xóa một đỉnh không phải gốc $v$, ngoài các cây con tương ứng với các đỉnh con của đỉnh đó, còn có một cây con "hướng lên". Nếu cha của đỉnh $v$ là $u$, thì cây con "hướng lên" này chính là $T_u^{(v)}$. Khi đề cập đến loại đồ thị con này, bài viết sẽ gọi rõ ràng là cây con "hướng lên". Nếu không có ghi chú đặc biệt, các cây con được đề cập trong bài viết đều không bao gồm loại cây con "hướng lên" này.

Lưu ý rằng các thành phần liên thông thu được cũng là cây không gốc. Bằng cách xóa trọng tâm của cây, một cây sẽ biến thành nhiều cây có kích thước nhiều nhất bằng một nửa cây ban đầu. Tính chất này của trọng tâm giúp có thể áp dụng tư tưởng chia để trị trên cây. Đây là [phân trị theo điểm](./tree-divide.md#%E7%82%B9%E5%88%86%E6%B2%BB), còn được gọi là phân rã trọng tâm của cây.

## Tính chất

Phần này thảo luận các tính chất của trọng tâm. Trước hết, trọng tâm của cây có các định nghĩa tương đương sau:

???+ note "Định nghĩa tương đương"
    Đỉnh $v$ trong cây $T$ là trọng tâm của cây khi và chỉ khi bất kỳ điều kiện nào sau đây đúng:
    
    === "Phiên bản cây không gốc"
        1.  Sau khi xóa đỉnh $v$ trong cây, mọi thành phần liên thông của đồ thị thu được $T\setminus\{v\}$ đều có kích thước không vượt quá một nửa số đỉnh của cây ban đầu.
        2.  Xét kích thước thành phần liên thông lớn nhất thu được sau khi xóa từng đỉnh, giá trị thu được khi xóa đỉnh $v$ là nhỏ nhất.
        3.  Trong tổng khoảng cách từ tất cả các đỉnh của cây đến một đỉnh nào đó, tổng khoảng cách đến đỉnh $v$ là nhỏ nhất.
    
    === "Phiên bản cây có gốc"
        1.  Khi cây được lấy gốc tại đỉnh $v$, kích thước của mọi cây con thực sự đều không vượt quá một nửa số đỉnh của cây ban đầu.
        2.  Xét kích thước cây con thực sự lớn nhất khi lấy từng đỉnh làm gốc, giá trị thu được khi lấy đỉnh $v$ làm gốc là nhỏ nhất.
        3.  Xét tổng độ sâu của tất cả các đỉnh khi lấy từng đỉnh làm gốc, tổng độ sâu khi lấy đỉnh $v$ làm gốc là nhỏ nhất.

??? note "Chứng minh"
    Trước hết, đưa vào một số ký hiệu. Hai cách phát biểu cho cây có gốc và cây không gốc rõ ràng là tương đương. Định nghĩa $W(x)=\max_{u\sim x}|T_u^{(x)}|$, trong đó $u\sim x$ biểu thị $u$ kề với $x$. Định nghĩa $S(x)=\sum_{u\in T}d(u,x)$, trong đó $d(u,x)$ biểu thị khoảng cách giữa đỉnh $u$ và $x$. Khi đó, định nghĩa 1 tương đương với yêu cầu $W(v)\le |T|/2$, định nghĩa 2 tương đương với yêu cầu $v\in\arg\min_{x\in T}W(x)$, và định nghĩa 3 tương đương với yêu cầu $v\in\arg\min_{x\in T}S(x)$. Cần chứng minh ba điều kiện này là tương đương.
    
    Hiểu $S(x)$ là tổng độ sâu của các đỉnh khi lấy $x$ làm gốc, và xét thay đổi của nó khi đổi gốc từ đỉnh $v$ sang đỉnh kề $u$. Lưu ý rằng sau khi xóa cạnh $(v,u)$ trong cây, hai thành phần liên thông thu được lần lượt là các cây con $T_v^{(u)}$ và $T_u^{(v)}$. Trước và sau khi đổi gốc, độ sâu của mỗi đỉnh trong cây con $T_v^{(u)}$ tăng $1$, còn độ sâu của mỗi đỉnh trong cây con $T_u^{(v)}$ giảm $1$, nên thay đổi của tổng độ sâu là
    
    $$
    \Delta S_{v\to u} = S(u) - S(v) = |T_v^{(u)}| - |T_u^{(v)}| = |T| - 2|T_u^{(v)}|.
    $$
    
    Vì vậy, điều kiện của định nghĩa 1 tương đương với yêu cầu $\Delta S_{v\to u}\ge 0$ với mọi đỉnh $u$ kề với $v$, nói cách khác, $v$ là một điểm cực tiểu của $S(x)$.
    
    Ngược lại, giả sử $v$ là một điểm đạt giá trị nhỏ nhất của $S(x)$ (tức định nghĩa 3). Điểm này chắc chắn tồn tại và nhất định là điểm cực tiểu. Xét cây có gốc $T^{(v)}$ lấy $v$ làm gốc. Đặt $u\neq v$ là một đỉnh không phải gốc; trên đường đi có hướng từ $v$ đến $u$, đỉnh ngay sau $v$ là $y$ (có thể chính là $u$), và đỉnh ngay trước $u$ là $x$ (có thể chính là $v$). Khi đó, vì $T_u^{(x)}\subseteq T_y^{(v)}$, ta có
    
    $$
    2|T_x^{(u)}| = 2|T| - 2|T_u^{(x)}| \ge 2|T| - 2|T_y^{(v)}| \ge |T|.
    $$
    
    Ở bước cuối, ta dùng sự thật rằng $v$ là điểm cực tiểu của $S(x)$. Lúc này có hai trường hợp:
    
    -   Tồn tại đỉnh $u$ sao cho $2|T_x^{(u)}|=|T|$. Khi đó, theo bất đẳng thức trên, nhất định có $(x,u)=(v,y)$ và $|T_v^{(u)}|=|T_{u}^{(v)}| = |T|/2$. Nói cách khác, đỉnh $u$ làm cho dấu bằng xảy ra chỉ có thể là duy nhất, và nó nhất định kề với $v$. Khi đó, với mọi đỉnh khác $u'\neq u,v$, nhất định tồn tại $x'\sim u'$ sao cho $|T_{x'}^{(u')}| > |T|/2$.
        Tập các đỉnh thỏa điều kiện 1 là $\{v,u\}$.
    
        Lưu ý rằng khi xóa bất kỳ đỉnh nào, tổng kích thước các thành phần liên thông thu được luôn là $|T|-1$, nên chỉ cần có một thành phần liên thông có kích thước không nhỏ hơn $|T|/2$, nó nhất định là thành phần liên thông lớn nhất. Do đó, trong trường hợp này, $W(v)=W(u)=|T|/2$, và với mọi $u'\neq u,v$ đều có $W(u') > |T|/2$. Vì vậy, tập các đỉnh thỏa điều kiện 2 là $\arg\min W(x) = \{v,u\}$.
    
        Lại vì $\Delta S_{v\to u} = 0$, nên $S(v)=S(u)$. Vì $v$ là điểm đạt giá trị nhỏ nhất, $u$ cũng nhất định là điểm đạt giá trị nhỏ nhất. Còn với mọi $u'\neq u,v$, đều tồn tại $x'\sim u'$ sao cho $|T_{x'}^{(u')}| > |T|/2$, điều này vi phạm điều kiện mà một điểm cực tiểu cần thỏa mãn, nên $u'$ cũng nhất định không phải điểm đạt giá trị nhỏ nhất. Do đó, tập các đỉnh thỏa điều kiện 3 là $\arg\min S(x) = \{v,u\}$.
    -   Không tồn tại đỉnh $u$ sao cho $2|T_x^{(u)}|=|T|$. Khi đó, với mọi đỉnh $u\neq v$, đều tồn tại đỉnh $x\sim u$ sao cho $|T_x^{(u)}| > |T|/2$. Lặp lại phân tích ở trên, với mọi đỉnh $u\neq v$, ta có $W(u) > |T|/2$, và $u$ không phải điểm cực tiểu của $S(x)$. Do đó, chỉ có $v$ thỏa điều kiện 1, và $\arg\min W(x)=\arg\min S(x) = \{v\}$.
    
    Trong cả hai trường hợp, tập các đỉnh thỏa ba điều kiện đều giống nhau. Vậy ba định nghĩa là tương đương.

Ngoài các định nghĩa tương đương này, trọng tâm của cây còn có các tính chất thường gặp sau:

???+ note "Tính chất"
    1.  Nếu trọng tâm của cây không duy nhất, thì có đúng hai trọng tâm. Hai trọng tâm này kề nhau. Hơn nữa, sau khi xóa cạnh nối chúng, cây sẽ biến thành hai thành phần liên thông có kích thước bằng nhau.
    2.  Nếu thêm hoặc xóa một lá trên một cây, thì trọng tâm của cây di chuyển nhiều nhất một cạnh.
    3.  Nối hai cây bằng một cạnh để thu được một cây mới. Khi đó, trọng tâm của cây mới nằm trên đường đi nối các trọng tâm của hai cây ban đầu.
    4.  Trọng tâm của một cây có gốc nhất định nằm trên chuỗi nặng chứa đỉnh gốc. Trọng tâm của một cây nhất định là tổ tiên của trọng tâm của cây con tương ứng với con nặng của gốc cây đó.

??? note "Chứng minh"
    Tính chất 1 có thể suy ra từ chứng minh các định nghĩa tương đương của trọng tâm.
    
    Với tính chất 2, chỉ cần xét trường hợp thêm một đỉnh lá. Trường hợp này lại chia thành hai trường hợp:
    
    -   Cây $T$ chỉ có một trọng tâm $v$. Đặt $x$ là đỉnh lá mới được thêm vào, và trong đồ thị $T\cup\{x\}\setminus\{v\}$ thu được sau khi xóa đỉnh $v$ trong cây mới, thành phần liên thông chứa $x$ là $B\cup\{x\}$. Vì $v$ là trọng tâm duy nhất của cây $T$, nên $2|B| < |T|$, tức là $2|B|+1\le |T|$. Suy ra
    
        $$
        2|B\cup\{x\}| = 2(|B|+1) \le |T| + 1 = |T\cup\{x\}|.
        $$
    
        Do đó, $v$ vẫn là trọng tâm của cây mới $T\cup\{x\}$. Ngay cả khi trọng tâm của cây mới không duy nhất, trọng tâm còn lại cũng nhất định là đỉnh kề với $v$. Vì vậy, trọng tâm di chuyển nhiều nhất một cạnh.
    -   Cây $T$ có hai trọng tâm $u,v$. Khi đó, hai thành phần liên thông $T_u^{(v)}$ và $T_v^{(u)}$ thu được sau khi xóa $(u,v)$ có kích thước bằng nhau, đều bằng $|T|/2$. Không mất tính tổng quát, giả sử đỉnh lá mới thêm $x$ được nối vào thành phần liên thông $T_v^{(u)}$ chứa $v$. Khi đó, vì
    
        $$
        |T_v^{(u)}\cup\{x\}| = |T|/2 + 1 > (|T|+1)/2 = |T\cup\{x\}|/2,
        $$
    
        nên $u$ không còn là trọng tâm của cây mới. Ngược lại, sau khi xóa $v$, vẫn có thành phần liên thông $T_u^{(v)}$ có kích thước $|T|/2$, trong khi tổng kích thước các thành phần liên thông khác là
    
        $$
        |T\cup\{x\}| - 1 - |T_u^{(v)}| = |T|/2 \le |T_u^{(v)}|,
        $$
    
        nên $v$ vẫn là trọng tâm của cây mới. Vì cây mới có số đỉnh lẻ, trọng tâm nhất định duy nhất. Do đó, trọng tâm cũng di chuyển nhiều nhất một cạnh.
    
    Tổng kết phân tích của hai trường hợp, có thể thấy trọng tâm của cây mới nhất định nằm trên đường đi từ trọng tâm của cây cũ đến đỉnh lá mới thêm.
    
    Tính chất 3 có thể được chứng minh bằng quy nạp. Giả sử khi nối $T$ và $T'$, cạnh mới thêm là $(x,y)$, với $x\in T,y\in T'$. Không mất tính tổng quát, giả sử một trọng tâm của cây mới nằm trong $T$. Xét quá trình bắt đầu từ cây $T$ và lần lượt thêm các đỉnh trong cây $T'$ vào làm các đỉnh lá. Có thể chứng minh bằng quy nạp rằng một trọng tâm của cây luôn nằm trên đường đi nối trọng tâm của cây $T$ với đỉnh $x$. Cơ sở quy nạp là rõ ràng. Giả sử mệnh đề vẫn đúng cho đến một thời điểm nào đó, và khi đó trọng tâm là $v$. Theo phân tích của tính chất 2, trọng tâm của cây mới nhất định nằm trên đường đi nối đỉnh mới thêm và trọng tâm hiện tại $v$. Hơn nữa, vì nó sẽ không di chuyển ra ngoài cây $T$, ta chỉ cần xét phần giao của đường đi đó với cây $T$, tức đường đi nối trọng tâm hiện tại $v$ và đỉnh $x$. Theo giả thiết quy nạp, $v$ nằm trên đường đi nối trọng tâm của cây $T$ và đỉnh $x$, nên trọng tâm của cây mới cũng nhất định nằm trên đường đi nối trọng tâm hiện tại $v$ và đỉnh $x$. Theo quy nạp, mệnh đề được chứng minh.
    
    Với tính chất 4, chỉ cần kết hợp với [tính chất của phân rã nặng-nhẹ](./hld.md#%E9%87%8D%E9%93%BE%E5%89%96%E5%88%86%E7%9A%84%E6%80%A7%E8%B4%A8). Giả sử một trọng tâm của cây $T$ là $v$. Khi đỉnh $v$ là đỉnh gốc, mệnh đề rõ ràng đúng. Sau đây giả sử $v$ không phải đỉnh gốc, và $u$ là cha của nó. Vì $|T_u^{(v)}| \le |T|/2$, kích thước cây con chứa $v$ ít nhất là $|T|/2$. Nhưng chỉ cần đường đi từ nó đến đỉnh gốc đi qua một cạnh nhẹ, kích thước cây con chứa nó sẽ nhỏ hơn hẳn $|T|/2$, mâu thuẫn. Vì vậy, nó nhất định nằm trên chuỗi nặng chứa đỉnh gốc. Tiếp theo, theo định nghĩa của chuỗi nặng, trong cây con tương ứng với con nặng của đỉnh gốc, chuỗi nặng chứa đỉnh gốc là một phần của chuỗi nặng chứa đỉnh gốc trong cây ban đầu. Hơn nữa, theo tính chất 3, sau khi thêm con nặng và tất cả các cây con tương ứng với các con nhẹ của nó vào cây con tương ứng với con nặng, vị trí trọng tâm sẽ di chuyển dọc theo đường đi giữa trọng tâm hiện tại và đỉnh gốc, nên trọng tâm mới nhất định là tổ tiên của trọng tâm cũ.

## Cách tìm

Theo các định nghĩa tương đương của trọng tâm, có hai cách tìm tất cả các trọng tâm của cây trong thời gian $O(n)$, trong đó $n$ là kích thước của cây.

### DFS thống kê kích thước cây con

Dùng DFS để tính kích thước của mỗi cây con. Với mỗi đỉnh, ghi lại kích thước các cây con tương ứng với tất cả các đỉnh con của nó, đồng thời lấy tổng số đỉnh trừ đi kích thước cây con hiện tại để thu được kích thước của cây con "hướng lên". Sau đó có thể tìm trọng tâm theo định nghĩa.

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-centroid/tree-centroid-2.cpp:core"
    ```

### DP đổi gốc để thống kê tổng độ sâu

Ta cũng có thể dùng DP đổi gốc để tính tổng độ sâu của tất cả các đỉnh khi lấy từng đỉnh khác nhau làm gốc (tức tổng khoảng cách đến gốc hiện tại). Theo định nghĩa, chỉ cần tìm đỉnh làm cho tổng độ sâu này nhỏ nhất.

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-centroid/tree-centroid-3.cpp:core"
    ```

## Ví dụ

???+ example "[Codeforces Round 359 (Div. 1) B. Kay and Snowflake](https://codeforces.com/problemset/problem/685/B)"
    Cho một cây có gốc, hãy tìm trọng tâm của mỗi cây con.

??? note "Ý tưởng lời giải"
    Theo tính chất 3, với một cây con có gốc tại đỉnh $u$, trọng tâm của nó nhất định nằm trên các đường đi từ trọng tâm của mỗi cây con có gốc tại một đỉnh con trực tiếp của $u$ đến đỉnh $u$.
    
    Tương tự cách tìm trọng tâm bằng DFS đã nêu ở trên, với mỗi cây con có gốc tại đỉnh $u$, trước tiên tìm trọng tâm của tất cả các cây con có gốc tại các đỉnh con trực tiếp của nó (trọng tâm của một đỉnh lá là chính nó), rồi đi lên trên để kiểm tra các đỉnh trên đường đi có phải trọng tâm hay không.
    
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
-   [Đường kính của cây, trọng tâm của cây và phân trị theo điểm trên cây - cyendra](https://www.cnblogs.com/zinthos/p/3899075.html)
-   [Tính chất của trọng tâm cây và chứng minh - suxxsfe](https://www.cnblogs.com/suxxsfe/p/13543253.html)
-   Từ điển Olympic Tin học, chương 2.4.7.11, mục 1. Trọng tâm của cây
