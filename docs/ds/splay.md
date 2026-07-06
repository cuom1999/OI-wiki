Trang này giới thiệu ngắn gọn cách dùng Splay để duy trì cây tìm kiếm nhị phân.

## Định nghĩa

**Cây Splay**, hay **Splay Tree**, là một cây tìm kiếm nhị phân cân bằng.
Nó liên tục đưa một nút nào đó lên nút gốc bằng **thao tác splay**,
sao cho toàn bộ cây vẫn thỏa tính chất của cây tìm kiếm nhị phân.
Nhờ đó, các thao tác chèn, tìm kiếm và xóa có thời gian khấu hao $O(\log N)$,
đồng thời cây được giữ cân bằng để không suy biến thành một dây xích.

Cây Splay do Daniel Sleator và Robert Tarjan phát minh vào năm 1985.

## Cấu trúc và thao tác cơ bản

Phần này thảo luận cấu trúc cơ bản của cây Splay và các thao tác cốt lõi của nó, trong đó quan trọng nhất là thao tác splay.

Cây Splay là một cây tìm kiếm nhị phân. Khi tìm một giá trị, nó thỏa tính chất:
giá trị của mọi nút trong cây con trái $<$ giá trị của nút gốc $<$ giá trị của mọi nút trong cây con phải.

### Thông tin cần duy trì

Bài viết này dùng mảng để mô phỏng con trỏ khi cài đặt cây Splay, cần duy trì các thông tin sau:

|   rt  |    id   | fa\[i] | ch\[i]\[0/1] | val\[i] | cnt\[i] | sz\[i] |
| :---: | :-----: | :----: | :----------: | :-----: | :-----: | :----: |
| Chỉ số nút gốc | Số nút đã dùng | Nút cha | Chỉ số con trái/phải | Giá trị nút | Số lần giá trị xuất hiện | Kích thước cây con |

Khi khởi tạo, chỉ cần đặt toàn bộ thông tin bằng không.

### Thao tác phụ trợ

Trước hết là một vài thao tác phụ trợ đơn giản:

-   `dir(x)`: xác định nút $x$ là con trái hay con phải của nút cha;
-   `push_up(x)`: sau khi thay đổi vị trí nút, cập nhật thông tin của nút $x$ dựa trên thông tin các nút con.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:aux"
    ```

### Thao tác xoay

Để Splay giữ được cân bằng, cần thực hiện thao tác xoay. Tác dụng của phép xoay là đưa một nút lên trên một mức.

Phép xoay cần bảo đảm:

-   Thứ tự duyệt trung tự của toàn bộ Splay không đổi, tức không phá vỡ tính chất của cây tìm kiếm nhị phân;
-   Thông tin được duy trì trên các nút bị ảnh hưởng vẫn đúng và hợp lệ;
-   `rt` phải trỏ tới nút gốc sau khi xoay.

Trong Splay có hai loại phép xoay: xoay trái và xoay phải.

![](./images/splay-rotate.svg)

Từ hình minh họa, nếu muốn dùng phép xoay để đưa nút $x$
(nút $1$ trong xoay trái và nút $2$ trong xoay phải) lên trên,
thì hướng xoay được xác định duy nhất bởi việc nút đó là con trái hay con phải của nút cha.
Vì vậy, khi cài đặt thao tác xoay, chỉ cần truyền vào nút $x$ cần được đưa lên.

Phân tích cụ thể các bước xoay: (giả sử nút cần đưa lên là $x$, lấy xoay phải làm ví dụ)

1.  Trước hết, ghi lại nút cha $y$ của nút $x$, nút cha $z$ của $y$ (có thể rỗng), và ghi lại $x$ là con trái hay con phải của $y$;
2.  Theo thứ tự từ dưới lên trong cây sau khi xoay, lần lượt cập nhật con trái của $y$ thành con phải của $x$,
    con phải của $x$ thành $y$, và nếu $z$ không rỗng thì cập nhật con của $z$ thành $x$;
3.  Theo cùng thứ tự đó, lần lượt cập nhật nút cha của con trái hiện tại của $y$ (nếu tồn tại) thành $y$,
    nút cha của $y$ thành $x$, và nút cha của $x$ thành $z$;
4.  Duy trì thông tin nút theo thứ tự từ dưới lên.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:rotate"
    ```

Khi cài đặt mọi hàm, không sửa thông tin của nút $0$.

### Thao tác splay

Cây Splay yêu cầu sau mỗi lần truy cập một nút $x$, bắt buộc phải xoay nút đó lên nút gốc. Thao tác này cũng được gọi là thao tác splay.

Giả sử nút vừa được truy cập là $x$.
Để thực hiện thao tác splay, thực hiện một chuỗi **bước splay** trên $x$.
Mỗi lần thực hiện một bước splay trên $x$, khoảng cách từ $x$ đến nút gốc sẽ ngắn hơn.
Gọi $p$ là nút cha của $x$. Có ba loại bước splay:

1.  **zig**: thực hiện khi $p$ là nút gốc.
    Cây Splay sẽ xoay theo cạnh giữa $x$ và $p$.
    **zig** tồn tại để xử lý vấn đề chẵn lẻ,
    và chỉ được thực hiện như bước cuối cùng của thao tác splay khi $x$ có độ sâu lẻ tại thời điểm bắt đầu thao tác splay.

    ![Bước zig trong cây Splay](./images/splay-zig.svg)

    Tức là trực tiếp xoay phải hoặc xoay trái $x$ (hình 1, 2).

    ![Zig xoay phải](./images/splay-rotate1.svg)![Zig xoay trái](./images/splay-rotate2.svg)

2.  **zig-zig**: thực hiện khi $p$ không phải nút gốc và $x$ cùng $p$ đều là con phải hoặc đều là con trái.
    Hình ví dụ bên dưới thể hiện trường hợp $x$ và $p$ đều là con trái.
    Cây Splay trước tiên xoay theo cạnh nối $p$ với nút cha $g$ của nó,
    sau đó xoay theo cạnh nối $x$ và $p$.

    ![Bước zig-zig trong cây Splay](./images/splay-zig-zig.svg)

    Tức là trước tiên xoay phải hoặc xoay trái $p$, sau đó xoay phải hoặc xoay trái $x$ (hình 3, 4).

    ![Zig-zig xoay phải](./images/splay-rotate3.svg)![Zig-zig xoay trái](./images/splay-rotate4.svg)

3.  **zig-zag**: thực hiện khi $p$ không phải nút gốc và trong hai nút $x$, $p$,
    một nút là con phải còn nút kia là con trái.
    Cây Splay trước tiên xoay theo cạnh giữa $p$ và $x$,
    sau đó xoay theo cạnh kết quả mới sinh ra giữa $x$ và $g$.

    ![Bước zig-zag trong cây Splay](./images/splay-zig-zag.svg)

    Tức là xoay $x$ trái rồi phải, hoặc phải rồi trái (hình 5, 6).

    ![Zig-zag xoay trái rồi phải](./images/splay-rotate5.svg)![Zig-zag xoay phải rồi trái](./images/splay-rotate6.svg)

???+ tip "Mẹo"
    Có thể tự mô phỏng $6$ trường hợp xoay để hiểu tư tưởng cơ bản của thao tác splay.

Khi so sánh ba loại bước splay, để phân biệt nên dùng thao tác nào,
điểm mấu chốt là cần xác định $x$ có phải là con của nút gốc hay không,
và $x$ cùng nút cha của nó có nằm cùng phía so với nút cha tương ứng của chúng hay không.

Cài đặt dưới đây cho phép chỉ định một nút gốc bất kỳ $z$,
rồi đưa một nút $x$ bất kỳ trong cây con của nó lên vị trí $z$:

1.  Trước hết ghi lại nút cha $w$ của nút gốc $z$, từ đó có thể dùng `fa[x] == w` để xác định $x$ đã nằm tại vị trí nút gốc hay chưa;
2.  Ghi lại nút cha hiện tại $y$ của $x$. Nếu $y$ giống $w$, tức là $x$ đã tới nút gốc;
3.  Ngược lại, dùng `fa[y] == w` để xác định $y$ có phải nút gốc hay không.
    Nếu đúng, trực tiếp thực hiện thao tác zig để xoay $x$;
    nếu không, dùng `dir(x) == dir(y)` để xác định dùng zig-zig hay zig-zag:
    trường hợp trước xoay $y$ rồi xoay $x$, trường hợp sau xoay $x$ hai lần liên tiếp.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:splay"
    ```

Thao tác splay là thao tác cốt lõi của cây Splay,
đồng thời là bước then chốt giúp độ phức tạp thời gian của nó được bảo đảm.
Sau mỗi lần truy cập nút theo hướng đi xuống, cần thực hiện một lần thao tác splay.

Ngoài ra, thao tác splay sẽ cập nhật lại thông tin của tất cả các nút trên đường đi từ nút hiện tại $x$
đến nút gốc $z$ theo thứ tự từ dưới lên.
Nhờ điểm này, có thể sửa một nút không phải gốc,
rồi thông qua thao tác splay đưa nó lên gốc để hoàn tất việc cập nhật thông tin của cả cây.

### Độ phức tạp thời gian

Với một cây Splay kích thước $n$, thực hiện $m$ thao tác splay có độ phức tạp $O((n+m)\log n)$,
và độ phức tạp khấu hao của một thao tác là $O(\log n)$.

??? note "Chứng minh độ phức tạp dựa trên phân tích thế năng"
    Để làm điều này, chỉ cần phân tích độ phức tạp của ba thao tác **zig**, **zig-zig** và **zig-zag**.
    Dùng **phương pháp phân tích thế năng**,
    có thể suy ra độ phức tạp khấu hao của thao tác bằng cách nghiên cứu sự thay đổi của thế năng.
    Giả sử thực hiện $m$ thao tác splay trên một cây Splay chứa $n$ nút, có thể phân tích như sau:
    
    **Định nghĩa**:
    
    1.  **Thế năng của một nút**: $w(x) = \log(\text{size}(x))$, trong đó $\text{size}(x)$ biểu thị kích thước cây con có gốc là nút $x$.
    2.  **Thế năng của toàn bộ cây**: $\varphi = \sum w(x)$, tức tổng thế năng của tất cả các nút trong cây;
        thế năng ban đầu thỏa $\varphi_0 \leq n \log n$.
    3.  **Chi phí khấu hao của thao tác thứ $i$**: $c_i = t_i + \varphi_i - \varphi_{i-1}$,
        trong đó $t_i$ là chi phí thực tế của thao tác,
        còn $\varphi_i$ và $\varphi_{i-1}$ lần lượt là thế năng sau và trước thao tác.
    
    **Tính chất**:
    
    1.  Nếu $p$ là nút cha của $x$, thì $w(p) \geq w(x)$, tức thế năng của nút cha không nhỏ hơn thế năng của nút con.
    
    2.  Vì kích thước cây con của nút gốc không đổi trước và sau thao tác, nên thế năng của nút gốc không đổi trong quá trình thao tác.
    
    3.  Nếu $\text{size}(p)\ge\text{size}(x)+\text{size}(y)$, thì có $2w(p) - w(x) - w(y) \geq 2$.
    
    ??? note "Chứng minh tính chất 3"
        Theo bất đẳng thức trung bình:
        
        $$
        \begin{aligned}
        2w(p) - w(x) - w(y) 
        &= \log\dfrac{\text{size}(p)^2}{\text{size}(x)\cdot\text{size}(y)} \\
        &> \log\dfrac{\left(\text{size}(x)+\text{size}(y)\right)^2}{\text{size}(x)\cdot\text{size}(y)} \\
        &\ge \log 4 \\
        &= 2.
        \end{aligned}
        $$
    
    Tiếp theo, lần lượt thực hiện phân tích thế năng cho các thao tác **zig**, **zig-zig** và **zig-zag**.
    Gọi thế năng của nút $x$ trước và sau thao tác lần lượt là $w(x)$ và $w'(x)$.
    Ký hiệu của các nút nhất quán với [phần trên](#thao-tac-splay).
    
    **zig**: theo tính chất 1 và 2, có $w(p) = w'(x)$, đồng thời $w'(x) \geq w'(p)$. Do đó, chi phí khấu hao là
    
    $$
    \begin{aligned}
    c_i &= 1 + w'(x) + w'(p) - w(x) - w(p)\\
    &= 1 + w'(p) - w(x)\\
    &\leq 1 + w'(x) - w(x).
    \end{aligned}
    $$
    
    **zig-zig**: theo tính chất 1 và 2, có $w(g) = w'(x)$, đồng thời $w'(x) \geq w'(p)$, $w(x) \leq w(p)$. Vì
    
    $$
    \begin{aligned}
    \text{size}'(x) 
    &= 3 + \text{size}(A) + \text{size}(B) + \text{size}(C) + \text{size}(D) \\
    &> (1 + \text{size}(A) + \text{size}(B)) + (1 + \text{size}(C) + \text{size}(D)) \\
    &= \text{size}(x) + \text{size}'(g),
    \end{aligned}
    $$
    
    Theo tính chất 3, suy ra
    
    $$
    2 w'(x) - w(x) - w'(g) \geq 2.
    $$
    
    Do đó, chi phí khấu hao là
    
    $$
    \begin{aligned}
    c_i &= 2 + w'(x) + w'(p) + w'(g) - w(x) - w(p) - w(g) \\
    &= 2 + w'(p) + w'(g) - w(x) - w(p) \\
    &\le (2 w'(x) - w(x) - w'(g)) + w'(p) + w'(g) - w(x) - w(p) \\
    &= 2(w'(x)-w(x)) + w'(p) - w(p) \\
    &\le 3(w'(x)-w(x)).
    \end{aligned}
    $$
    
    **zig-zag**: theo tính chất 1 và 2, có $w(g) = w'(x)$, đồng thời $w(p) \geq w(x)$.
    Vì $\text{size}'(x)>\text{size}'(p)+\text{size}'(g)$, theo tính chất 3, suy ra
    
    $$
    2 \cdot w'(x) - w'(g) - w'(p) \geq 2.
    $$
    
    Do đó, chi phí khấu hao là
    
    $$
    \begin{aligned}
    c_i &= 2 + w'(x) + w'(p) + w'(g) - w(x) - w(p) - w(g) \\
    &= 2 + w'(p) + w'(g) - w(x) - w(p) \\
    &\le (2w'(x) - w'(g) - w'(p)) + w'(p) + w'(g) - w(x) - w(p) \\
    &= 2w'(x) - w(x) - w(p) \\
    &\le 2(w'(x) - w(x)).
    \end{aligned}
    $$
    
    **Một thao tác splay đơn lẻ**:
    
    Đặt $w^{(n)}(x)=(w^{(n-1)})'(x)$ và $w^{(0)}(x)=w(x)$.
    Giả sử một thao tác splay lần lượt truy cập các nút $x_{1}, x_{2}, \cdots, x_{n}$,
    và cuối cùng $x_{1}$ trở thành nút gốc.
    Quá trình này đi qua một số thao tác **zig-zig** và **zig-zag**,
    cùng nhiều nhất một thao tác **zig**.
    Chi phí khấu hao của hai loại thao tác đầu đều không vượt quá $3(w'(x)-w(x))$,
    còn chi phí khấu hao của thao tác cuối không vượt quá $3(w'(x) - w(x))+1$,
    nên tổng chi phí khấu hao không vượt quá
    
    $$
    3(w^{(n)}(x_1) - w^{(0)}(x_1)) + 1 \le 3\log n + 1.
    $$
    
    Vì vậy, độ phức tạp khấu hao của một thao tác splay là $O(\log n)$.
    Từ đó, độ phức tạp thời gian của các thao tác dựa trên splay như chèn, truy vấn, xóa
    cũng là $O(\log n)$ theo nghĩa khấu hao.
    
    **Kết luận**:
    
    Sau khi thực hiện $m$ thao tác splay, chi phí thực tế là
    
    $$
    \begin{aligned}
    \sum_{i=1}^m t_i &= \sum_{i=1}^m \left(c_i + \varphi_{i-1} - \varphi_i \right) \\
    &= \sum_{i=1}^m c_i + \varphi_0 - \varphi_m \\
    &\le m(3\log n+1) + n\log n.
    \end{aligned}
    $$
    
    Vì vậy, độ phức tạp thời gian thực tế của $m$ thao tác splay là $O((m+n)\log n)$.

??? info "Vì sao thao tác tái cân bằng của cây Splay có thể đạt độ phức tạp khấu hao $O(\log n)$?"
    Cách tái cân bằng đơn giản là liên tục xoay một nút để nó đi lên cho đến khi trở thành nút gốc.
    Vấn đề của cách đơn giản này là với một cây dạng dây xích mà mọi nút con đều là con trái (hoặc con phải),
    nó tương đương với việc lặp lại thao tác **zig** liên tục.
    Vì vậy, hạng tử hằng $1$ trong độ phức tạp khấu hao của thao tác **zig** sẽ tích lũy không ngừng,
    khiến độ phức tạp khấu hao cuối cùng đạt mức $O(\log n+n)$.
    Thiết kế của thao tác tái cân bằng trong cây Splay tránh được việc tích lũy hằng số trong trường hợp **zig** liên tiếp,
    bảo đảm trong một thao tác splay hoàn chỉnh chỉ thực hiện nhiều nhất một thao tác **zig** đơn lẻ,
    từ đó tối ưu độ phức tạp thời gian.

## Thao tác trên cây cân bằng

Phần này thảo luận cách cài đặt các thao tác thường gặp của cây cân bằng dựa trên cây Splay.
Trong đó, tương đối quan trọng là tìm phần tử theo giá trị hoặc theo thứ hạng:
chúng có thể tìm ra một phần tử cụ thể và đưa nó lên nút gốc để tiện xử lý tiếp.

Làm ví dụ, phần này sẽ thảo luận cách cài đặt bài mẫu [Cây cân bằng thông thường](https://loj.ac/problem/104).

### Tìm theo giá trị

Với vai trò là cây tìm kiếm nhị phân, có thể tìm nút tương ứng theo giá trị $v$:
chỉ cần so sánh giá trị cần tìm $v$ với giá trị của nút hiện tại,
sau khi tìm thấy thì đưa phần tử đó lên gốc.

Thường có trường hợp trong cây không tồn tại nút tương ứng.
Với trường hợp này, cần ghi lại nút được truy cập cuối cùng (tức $y$ trong cài đặt) và đưa $y$ lên gốc.
Lúc này, giá trị được lưu trong nút $y$ hoặc là phần tử lớn nhất trong tất cả các phần tử nhỏ hơn $v$
(tức tiền nhiệm của $v$),
hoặc là phần tử nhỏ nhất trong tất cả các phần tử lớn hơn $v$ (tức hậu nhiệm của $v$).
Điều này là vì quá trình tìm kiếm bảo đảm cây con trái luôn lưu các giá trị nhỏ hơn $v$,
còn cây con phải luôn lưu các giá trị lớn hơn $v$.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:find"
    ```

Cài đặt này cho phép chỉ định bất kỳ nút $z$ nào làm nút gốc, rồi tìm theo giá trị trong cây con của nó.

### Truy cập theo thứ hạng

Vì đã ghi lại thông tin kích thước cây con, cây Splay còn có thể truy cập phần tử theo thứ hạng, tức tìm phần tử nhỏ thứ $k$ trong cây.

Gọi $k$ là thứ hạng còn lại, các bước cụ thể như sau:

-   Nếu cây con trái không rỗng và thứ hạng còn lại $k$ không lớn hơn kích thước cây con trái, thì tìm trong cây con trái;
-   Ngược lại, nếu $k$ không lớn hơn tổng kích thước cây con trái và kích thước của gốc, thì nút gốc chính là nút cần tìm;
-   Ngược lại, trừ khỏi $k$ tổng kích thước cây con trái và kích thước của gốc, rồi tiếp tục tìm trong cây con phải;
-   Đưa phần tử cuối cùng tìm được lên gốc.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:loc"
    ```

Cài đặt này cần bảo đảm thứ hạng $k$ không vượt quá kích thước cây tại nút gốc $z$.

Trong bài mẫu, thao tác $4$ yêu cầu trả về giá trị theo thứ hạng; chỉ cần gọi trực tiếp phương thức này rồi trả về giá trị.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:find-kth"
    ```

### Thao tác hợp nhất

Đôi khi cần hợp nhất hai cây Splay.

Giả sử nút gốc của hai cây lần lượt là $x$ và $y$.
Để bảo đảm kết quả vẫn là cây tìm kiếm nhị phân,
cần yêu cầu giá trị lớn nhất trong cây $x$ nhỏ hơn giá trị nhỏ nhất trong cây $y$.
Điều kiện này thường có thể thỏa mãn, vì hai cây thường được tách ra từ một cây con lớn hơn.

Thao tác hợp nhất như sau:

-   Nếu một trong $x$ và $y$, hoặc cả hai, là cây rỗng, trực tiếp trả về nút gốc của cây không rỗng hoặc cây rỗng;
-   Ngược lại, dùng `loc(y, 1)` để đưa giá trị nhỏ nhất trong cây $y$ lên vị trí gốc $y$,
    sau đó đặt nút con trái của nó (lúc này luôn rỗng) thành $x$,
    cập nhật thông tin nút và trả về nút $y$.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:merge"
    ```

Thao tác tách cũng tương tự. Vì vậy, cây Splay có thể mô phỏng tư tưởng của
[treap không xoay](./treap.md#treap-không-xoay) để thực hiện nhiều thao tác, bao gồm thao tác đoạn.
[Phần sau](#thao-tac-tren-day) sẽ giới thiệu phương pháp xử lý thao tác đoạn mang phong cách cây Splay hơn.

### Thao tác chèn

Thao tác chèn là một quá trình tương đối phức tạp. Các bước cụ thể như sau: (giả sử giá trị được chèn là $v$)

-   Tương tự quá trình tìm theo giá trị, dựa vào $v$ để đi xuống tìm nút lưu $v$ hoặc nút rỗng, đồng thời ghi lại nút cha $y$ trong quá trình đó;
-   Nếu tồn tại nút $x$ lưu $v$, trực tiếp cập nhật thông tin; ngược lại, tạo nút mới $x$;
-   Thực hiện thao tác splay, đưa nút cuối cùng $x$ lên gốc.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:insert"
    ```

Cài đặt này cho phép chèn giá trị trực tiếp vào cây rỗng. Nếu không muốn xử lý cây rỗng, có thể chèn trước các nút giả vào cây.

### Thao tác xóa

Thao tác xóa cũng là một thao tác tương đối phức tạp. Các bước cụ thể như sau: (giả sử giá trị cần xóa là $v$)

-   Trước hết tìm nút lưu giá trị $v$ theo giá trị và đưa nó lên gốc;
-   Nếu không tồn tại nút lưu giá trị đó, trực tiếp trả về; (bước trước đã thực hiện thao tác splay)
-   Ngược lại, cập nhật thông tin nút;
-   Nếu nút gốc thu được là nút rỗng, thì hợp nhất cây con trái và cây con phải làm nút gốc mới;
    trước khi hợp nhất cần cập nhật nút cha của gốc hai cây con thành rỗng.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:remove"
    ```

### Truy vấn thứ hạng

Trực tiếp truy cập nút theo giá trị $v$ (và đưa nó lên gốc), sau đó trả về giá trị tương ứng.

Khi $v$ không tồn tại, quan hệ lớn nhỏ giữa nút gốc mà phương thức `find(rt, v)` trả về và $v$ không xác định, cần thảo luận riêng.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:find-rank"
    ```

### Truy vấn tiền nhiệm

Tiền nhiệm được định nghĩa là số lớn nhất nhỏ hơn $v$. Các bước cụ thể như sau:

-   Truy cập nút theo giá trị $v$ (và đưa nó lên gốc);
-   Nếu giá trị ở gốc nhỏ hơn $v$, thì nó là giá trị lớn nhất như vậy, trực tiếp trả về;
-   Ngược lại, tìm giá trị lớn nhất trong cây con trái và đưa nó lên gốc.

Bước cuối cùng tương đương với việc gọi trực tiếp `loc(ch[rt][0], sz[ch[rt][0]])`, chỉ là lược bỏ các phán đoán không cần thiết.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:find-prev"
    ```

Cài đặt này cho phép tiền nhiệm không tồn tại; khi đó trả về $-1$.

### Truy vấn hậu nhiệm

Hậu nhiệm được định nghĩa là số nhỏ nhất lớn hơn $x$.
Cách truy vấn tương tự tiền nhiệm, chỉ thay giá trị lớn nhất trong cây con trái bằng giá trị nhỏ nhất trong cây con phải,
tức gọi `loc(ch[rt][1], 1)`.

???+ example "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:find-next"
    ```

### Cài đặt tham khảo

Cuối phần này, đưa ra cài đặt tham khảo cho bài mẫu [Cây cân bằng thông thường](https://loj.ac/problem/104).

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-1.cpp:full-text"
    ```

## Thao tác trên dãy

Cây Splay cũng có thể được dùng trên dãy để duy trì thông tin đoạn.
So với cây đoạn, hằng số của cây Splay lớn hơn,
nhưng nó hỗ trợ các thao tác trên dãy phức tạp hơn, chẳng hạn đảo ngược đoạn.
Như đã đề cập ở trên, cây Splay cũng hỗ trợ thao tác tách và hợp nhất,
vì vậy có thể mô phỏng [treap không xoay](./treap.md#treap-không-xoay) để thực hiện thao tác đoạn;
phần này không thảo luận thêm hướng đó.
Thay vào đó, phần này chủ yếu thảo luận phương pháp cài đặt thao tác đoạn dựa trên thao tác splay.

Cây Splay được xây từ dãy có các tính chất sau:

-   Thứ tự duyệt trung tự của cây Splay tương đương với việc duyệt dãy ban đầu từ trái sang phải;
-   Một nút trên cây Splay đại diện cho một phần tử của dãy ban đầu;
-   Một cây con trên cây Splay đại diện cho một đoạn của dãy ban đầu.

Nhờ có thao tác splay, có thể nhanh chóng trích ra cây con Splay đại diện cho một đoạn nào đó.

Làm ví dụ, phần này sẽ thảo luận cách cài đặt bài mẫu [Cây cân bằng văn nghệ](https://loj.ac/problem/105).

### Xây cây theo dãy

Trước khi thao tác, cần xây cây Splay theo dãy đã cho.
Dựa trên đặc tính của cây Splay, có thể trực tiếp xây một dây xích chỉ có con trái.
Độ phức tạp thời gian là $O(n)$.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-2.cpp:build"
    ```

Thao tác splay cuối cùng đã cập nhật thông tin nút từ dưới lên.
Để tiện cho thao tác đoạn ở phần sau, hai nút lính canh được thêm vào hai phía trái và phải của dãy.

### Đảo ngược đoạn

Lấy đảo ngược đoạn làm ví dụ để hiểu phương pháp thao tác đoạn: (giả sử đoạn là $[L,R]$)

-   Trước hết đưa nút $L-1$ lên nút gốc, rồi trong cây con phải của nó, đưa nút $R+1$ lên nút gốc của cây con phải;
-   Lúc này, gọi $x$ là nút con trái của nút con phải của nút gốc, thì cây con có gốc là $x$ sẽ tương ứng với đoạn $[L,R]$;
-   Thực hiện thao tác trên đoạn $[L,R]$ tại $x$ và gắn đánh dấu lười;
-   Tại $x$, đẩy đánh dấu xuống một lần, rồi dùng thao tác splay đưa $x$ lên gốc.

Thao tác cần ở bước đầu tiên chính là "truy cập theo thứ hạng" trong phần thao tác cây cân bằng phía trước,
vì chỉ số của phần tử chính là thứ hạng của nó.
Do liên quan tới quản lý đánh dấu lười, cài đặt của nó hơi khác phần trên.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-2.cpp:reverse"
    ```

Thao tác splay ở bước cuối không nhằm bảo đảm độ phức tạp đúng, mà để cập nhật thông tin nút.
Vì thao tác splay liên quan đến nút con trái và phải của nút $x$,
nên trước đó cần đẩy đánh dấu tại nút $x$ xuống một lần.
Nếu chỉ xét thao tác đảo ngược đoạn, việc đảo ngược đoạn con sẽ không ảnh hưởng tới các nút tổ tiên,
nên bỏ qua bước này cũng đúng.
Cài đặt này giữ lại hai dòng đó để minh họa phương pháp thao tác trong trường hợp tổng quát.

### Quản lý đánh dấu lười

Trước hết, cần các hàm phụ trợ `lazy_reverse(x)` và `push_down(x)`.
Hàm trước hoán đổi nút trái và nút phải, đồng thời cập nhật đánh dấu lười; hàm sau đẩy đánh dấu xuống.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-2.cpp:push-down"
    ```

Sau đó, chỉ cần đẩy đánh dấu xuống khi đi qua nút theo hướng xuống.
Thao tác mà bài mẫu yêu cầu khá đơn giản,
chỉ có thao tác tìm theo thứ hạng (tức `loc`) là liên quan đến việc truy cập nút theo hướng xuống.
Cần đẩy đánh dấu xuống **trước** mỗi lần hàm truy cập một nút mới.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-2.cpp:push-down-lazy"
    ```

Vì khi truy cập nút theo hướng xuống, tất cả đánh dấu lười trên đường đi đã được gỡ bỏ,
nên khi dùng thao tác splay để đưa nút lên trên không cần xử lý đánh dấu lười nữa.
Tuy nhiên, cần xử lý cẩn thận nút tương ứng với thao tác đoạn:
vì nó cũng nằm trên đường đi của thao tác splay,
nhưng vừa được thao tác xong nên có thể còn đánh dấu chưa được đẩy xuống.
Cần đẩy xuống trước rồi mới thực hiện thao tác splay, đúng như cách đã làm ở trên.

### Cài đặt tham khảo

Cuối phần này, đưa ra cài đặt tham khảo cho bài mẫu [Cây cân bằng văn nghệ](https://loj.ac/problem/105).

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/splay/splay-2.cpp:full-text"
    ```

## Bài tập

Các bài này đều là bài Splay Tree trực tiếp để duy trì cây tìm kiếm nhị phân:

-   [Mẫu: cây cân bằng thông thường](https://loj.ac/problem/104)
-   [Mẫu: cây cân bằng văn nghệ](https://loj.ac/problem/105)
-   [HNOI2002: thống kê doanh thu](https://loj.ac/problem/10143)
-   [HNOI2004: trại nhận nuôi thú cưng](https://loj.ac/problem/10144)

Cây Splay còn xuất hiện trong các bối cảnh ứng dụng phức tạp hơn:

-   [Cerc2007: robotic sort](https://www.luogu.com.cn/problem/P4402)
-   [HNOI2011: sửa ngoặc / JSOI2011: dãy ngoặc](https://www.luogu.com.cn/problem/P3215)
-   [Cây cân bằng ngầu: cây lồng cây](https://loj.ac/problem/106)
-   [BZOJ 2827: ngàn núi chim bay hết](https://hydro.ac/p/bzoj-P2827)
-   [Lydsy1706 thi tháng: truy vấn giá trị nhỏ thứ K](https://hydro.ac/p/bzoj-P4923)
-   [POJ3580 SuperMemo](http://poj.org/problem?id=3580)

## Tài liệu tham khảo và chú thích

Một phần nội dung của bài viết này được trích từ blog thuật toán algocode, xin đặc biệt cảm ơn!
