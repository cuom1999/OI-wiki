author: hsfzLZH1, cesonic, AtomAlpaca, caijianhong, Persdre, aofall, CoelacanthusHex, Marcythm, shuzhouliu, Tiphereth-A

## Dẫn nhập

**Cây lá cân bằng theo trọng số** (Weight Balanced Leafy Tree), dưới đây viết tắt là **WBLT**, là một loại cây cân bằng. So với nhiều cây cân bằng khác, WBLT có ưu điểm chính là cài đặt đơn giản và hằng số nhỏ. Cấu trúc này hỗ trợ thao tác trên đoạn, đồng thời có thể làm bền vững.

Đúng như tên gọi, cây lá cân bằng theo trọng số là sự kết hợp giữa cây cân bằng theo trọng số (Weight Balanced Tree) và cây lá (Leafy Tree).

Trong cây cân bằng theo trọng số, mỗi nút lưu kích thước cây con của nó. Chiều cao cây được khống chế bằng cách giữ tỷ lệ kích thước giữa cây con trái và cây con phải trong một phạm vi nhất định.

Cây lá chỉ lưu thông tin gốc cần duy trì trên **nút lá**. Các nút không phải lá chỉ dùng để tổng hợp thông tin từ nút con và giữ hình thái của cấu trúc dữ liệu. Cây đoạn quen thuộc cũng là một loại cây lá.

![](images/leafy-tree-1.svg)

Trong bài này, “cây” luôn chỉ cây lá nhị phân, tức mỗi nút chỉ có thể có $0$ hoặc $2$ nút con. Ký hiệu $n$ là số nút lá của cây. Với một cây có $n$ nút lá, tổng số nút là $2n-1$, vì vậy WBLT chiếm $\Theta(n)$ không gian.

## Cấu trúc cơ bản và duy trì cân bằng

Phần này giới thiệu cấu trúc cơ bản của WBLT, định nghĩa khái niệm cây $\alpha$-cân bằng, đồng thời giải thích cách duy trì cân bằng của cây bằng phép xoay hoặc bằng phép hợp nhất.

### Thông tin nút

Để cài đặt một WBLT cơ bản, chỉ cần ghi lại các thông tin sau cho mỗi nút:

-   `lc[x]`, `rc[x]`: nút con trái và phải;
-   `sz[x]`: số nút lá trong cây con gốc $x$.

Khi dùng WBLT để cài đặt cây cân bằng, cần ghi thêm thông tin liên quan tới khóa tại mỗi nút:

-   `val[x]`: khóa tại nút $x$.

Vì chỉ các nút lá mới thực sự lưu khóa, thông tin ở các nút khác được hợp nhất từ nút con để phục vụ các truy vấn sau này.

Ví dụ, một cách hợp nhất thường dùng là lưu tại nút hiện tại giá trị lớn hơn trong hai khóa của hai nút con. Khi đó, mỗi nút lưu giá trị lớn nhất trong tất cả nút lá thuộc cây con của nó. Với cách này, hàm cập nhật thông tin nút có dạng:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:push-up"
    ```

Dĩ nhiên, nếu cần, cũng có thể cài đặt hàm `push_down(x)` tương ứng.

### Hàm phụ trợ

Ngoài việc duy trì thông tin nút cơ bản, WBLT thường còn cần cài đặt các hàm phụ trợ sau để quản lý bộ nhớ:

-   `new_node()`: tạo nút mới;
-   `del_node(x)`: xóa nút $x$;
-   `new_leaf(v)`: tạo nút lá mới có khóa là $v$;
-   `join(x, y)`: nối cây con, tức tạo nút mới $z$ với $x$, $y$ lần lượt là nút con trái và phải;
-   `cut(x)`: cắt cây con, tức lấy hai nút con của nút $x$ rồi xóa nút $x$.

Nếu cài đặt WBLT phụ thuộc nhiều vào việc tách và nối cây con, cấu trúc sẽ tạo khá nhiều nút mới và giải phóng số lượng nút cũ tương ứng. Nếu không thu hồi kịp thời các nút cũ không còn dùng tới, mức sử dụng không gian sẽ không còn tuyến tính. Dưới đây là cài đặt bằng mảng của các hàm phụ trợ này:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:helper"
    ```

Sau khi đóng gói các hàm phụ trợ này, cài đặt bằng mảng và cài đặt bằng con trỏ sẽ không còn khác biệt trong các hàm phía sau.

### Khái niệm cân bằng

Với một cây, có thể định nghĩa **độ cân bằng** của nó tại một nút không phải lá $x$ là

$$
\rho(x) = \dfrac{\min\{w(T_{\operatorname{left}(x)}),w(T_{\operatorname{right}(x)})\}}{w(T_x)}.
$$

Trong đó, $T_x$ biểu thị cây con gốc $x$, $w(\cdot)$ biểu thị trọng số của cây con (số nút lá của nó), còn $\operatorname{left}(x)$ và $\operatorname{right}(x)$ lần lượt là nút con trái và phải của $x$. Với nút lá, quy ước $\rho(x)=1/2$.

Với $\alpha\in(0,1/2]$, nếu độ cân bằng tại nút $x$ thỏa $\rho(x)\ge\alpha$, nút đó được gọi là **$\alpha$-cân bằng**. Nếu mọi nút của cây đều $\alpha$-cân bằng, cây được gọi là **$\alpha$-cân bằng**. Tập hợp các cây như vậy được ký hiệu là $BB[\alpha]$. Một cây là **$\alpha$-cân bằng** khi và chỉ khi bản thân nó $\alpha$-cân bằng, các cây con trái phải của nó đều $\alpha$-cân bằng, hoặc nó là nút lá.

Cây $\alpha$-cân bằng có một lợi ích trực tiếp: chiều cao của nó là $O(\log n)$. Mỗi khi đi từ nút lá lên gần gốc thêm một bước, số nút lá trong cây con ít nhất tăng $1/(1-\alpha)$ lần so với trước đó, nên chỉ có thể đi $O(\log_{\frac{1}{1-\alpha}}n) = O(\log n)$ bước. Do đó, trong cây $\alpha$-cân bằng, độ phức tạp của một truy vấn đơn lẻ luôn nghiêm ngặt là $O(\log n)$, và hằng số của thuật toán tỷ lệ thuận với $\log(1/(1-\alpha))$ (cơ số $2$). Khi $\alpha$ nằm trong phạm vi hợp lý được nêu bên dưới, hằng số này xấp xỉ $2\sim 3.5$.

Việc duy trì cân bằng của WBLT thường có thể thực hiện bằng phép xoay hoặc phép hợp nhất. Với WBLT được cài đặt theo một trong hai cách này, mỗi thao tác đơn lẻ như chèn hoặc xóa đều có độ phức tạp nghiêm ngặt $O(\log n)$. Tuy nhiên, khác với [Treap](./treap.md) có độ ưu tiên cố định, cấu trúc của WBLT không có tính duy nhất. Vì vậy, hai cách duy trì này có thể tạo ra các hình thái cây khác nhau, nhưng điều đó không ảnh hưởng đến việc sử dụng. Cũng có thể duy trì cân bằng bằng chiến lược tương tự [cây scapegoat](./sgt.md), tức tái xây dựng để đạt độ phức tạp khấu hao $O(\log n)$; cách này làm mất các ưu điểm như khả năng bền vững và thao tác trên đoạn của WBLT, nên không được khuyến nghị.

Phần dưới lần lượt giới thiệu phương pháp duy trì cân bằng bằng phép xoay và bằng phép hợp nhất, đồng thời cài đặt các hàm duy trì cân bằng và hợp nhất tương ứng. Sau khi đóng gói các hàm này, hai cách duy trì cân bằng không còn khác biệt trong các cài đặt cây cân bằng cụ thể phía sau. Dù dùng cách nào, độ phức tạp thời gian của một thao tác duy trì cân bằng đơn lẻ đều là $O(1)$, và độ phức tạp của việc hợp nhất một cây $T_1$ với một cây $T_2$ đều là $O\left(\left|\log\dfrac{w(T_1)}{w(T_2)}\right|\right)$.

???+ info "Ký hiệu lược bỏ trọng số"
    Để duy trì cân bằng của cây, chỉ cần giữ thông tin trọng số của cây con. Vì vậy, để diễn đạt gọn hơn, hai phần thảo luận về duy trì cân bằng dưới đây dùng chung ký hiệu cho cây và trọng số của nó. Ví dụ, trọng số của cây con $x$ cũng được ký hiệu là $x$, thay vì $w(x)$. Tương tự, cây thu được bằng cách hợp nhất cây con $x$ và $y$ cũng được viết trực tiếp theo trọng số là cây $x+y$.

### Duy trì bằng phép xoay

Phép xoay của WBLT giống [phép xoay của Treap](./treap.md#phép-xoay), nên có thể dùng cùng chiến lược xoay. Bản thân phép xoay cũng có thể xem là quá trình phân phối lại trọng số cây con, nên có thể hoàn thành bằng cách tách và nối cây con. Kết quả của hai cách cài đặt hoàn toàn giống nhau, nhưng cách thứ hai thuận tiện hơn cho WBLT bền vững.

???+ example "Mã tham khảo"
    === "Không phụ thuộc vào nối"
        ```cpp
        --8<-- "docs/ds/code/wblt/wblt-1.cpp:rotate-not-by-joining"
        ```
    
    === "Phụ thuộc vào nối"
        ```cpp
        --8<-- "docs/ds/code/wblt/wblt-1.cpp:rotate-by-joining"
        ```

Giả sử sau một thao tác sửa đổi trên một cây, quá trình khôi phục cân bằng đang đi từ dưới lên trên. Lúc này, hai cây con trái phải $x$ và $y$ không còn cân bằng với nhau, nhưng bản thân chúng đều cân bằng. Không mất tính tổng quát, giả sử cây con phải $y$ quá nhẹ, tức $y<\alpha(x+y)$. Khi đó, hình thái của cây giống cây bên trái trong hình.

![](images/wblt-balance.svg)

Một chiến lược duy trì cân bằng đơn giản là xoay $x$ lên vị trí nút gốc. Khi đó, nút con phải ban đầu của nó là $w$ cùng với $y$ trở thành nút con phải của cây mới, còn nút con trái ban đầu là $z$ trở thành nút con trái của cây mới. Điều này tương đương với việc chuyển trọng số của $w$ từ phía trái của cây ban đầu sang phía phải. Nếu trọng số của $w$ phù hợp, thao tác này có thể khôi phục cân bằng của cây. Cây thu được giống cây bên phải trong hình.

Tuy nhiên, nếu bản thân $w$ quá nặng, thao tác này có thể chuyển quá nhiều trọng số sang cây con phải, khiến cây con trái trong cây mới quá nhẹ, tức $z<\alpha(x+y)$. Khi đó, vì trọng số của cả cây con $z$ lẫn cây con $y$ đều quá nhỏ, cần cân nhắc tách $w$ thành hai cây con, rồi nối chúng lần lượt với $z$ và $y$ để tạo hai cây con của cây mới. Điều này tương đương với việc trước tiên xoay nút $w$ lên vị trí nút $x$, rồi xoay nó lên vị trí gốc. Có thể kỳ vọng cây thu được theo cách này đạt cân bằng, với hình thái như cây phía trên trong hình.

Hai chiến lược xoay này lần lượt được gọi là xoay đơn và xoay kép. Việc chọn xoay đơn hay xoay kép chủ yếu phụ thuộc vào tỷ trọng của cây con $w$ so với cây con $x$, tức tồn tại một ngưỡng $\beta$ sao cho

-   khi $w\le\beta x$, nên chọn chiến lược xoay đơn;
-   khi $w>\beta x$, nên chọn chiến lược xoay kép.

Điểm khó nằm ở việc chọn ngưỡng $\beta$, điều này cần một số tính toán cụ thể. Blum và Mehlhorn đã chứng minh rằng, với tham số[^wrong-range]

$$
\alpha\in\left(\dfrac{2}{11},1-\dfrac{\sqrt{2}}{2}\right]\approx(0.182,0.292],~\beta=\frac{1}{2-\alpha},
$$

có thể dùng chiến lược kết hợp xoay đơn và xoay kép nói trên để duy trì cân bằng của WBLT bị mất cân bằng do một lần chèn hoặc xóa.

??? note "Chứng minh"
    Cần chứng minh rằng nếu cây mất cân bằng sau một lần chèn hoặc xóa, chiến lược trên có thể khôi phục cân bằng. Kết hợp với hình minh họa phía trên, đặt
    
    $$
    \rho_1 = \dfrac{y}{x+y}, ~\rho_2 = \dfrac{w}{x}, ~\rho_3 = \dfrac{v}{w}.
    $$
    
    Khi đó, có $\rho_1<\alpha\le\rho_2,\rho_3\le 1-\alpha$. Trong đó còn một điều kiện ngầm về phạm vi giá trị của $\rho_1$:
    
    -   Nếu mất cân bằng do chèn một phần tử đơn lẻ, thì phải có
    
        $$
        \dfrac{y}{x-1+y} \ge \alpha \implies \rho_1 \ge \dfrac{\alpha y}{y+\alpha} \ge \dfrac{\alpha}{1+\alpha}.
        $$
    -   Nếu mất cân bằng do xóa một phần tử đơn lẻ, thì phải có
    
        $$
        \dfrac{y+1}{x+y+1} \ge \alpha \implies \rho_1 \ge \dfrac{\alpha y}{y+1-\alpha} \ge \dfrac{\alpha}{2-\alpha}.
        $$
    
    Vì với $0<\alpha<1/2$ luôn có $\alpha/(2-\alpha)<\alpha/(1+\alpha)$, thao tác xóa phần tử có thể gây mất cân bằng nghiêm trọng hơn thao tác thêm phần tử, đặc biệt với cây kích thước rất nhỏ.
    
    Tiếp theo, thao tác khôi phục cân bằng được chia thành hai trường hợp:
    
    ??? note "Trường hợp 1: $w$ không quá nặng, tức $\rho_2\le\beta$, dùng xoay đơn"
        Trước hết, $z$ và $w+y$ cân bằng. Điều này là do
        
        $$
        \left(1-\dfrac{\alpha}{2-\alpha}\right)\alpha+\dfrac{\alpha}{2-\alpha} \le \dfrac{w+y}{x+y} = (1-\rho_1)\rho_2+\rho_1 < (1-\alpha)\dfrac{1}{2-\alpha}+\alpha.
        $$
        
        Biểu thức bên trái luôn lớn hơn $\alpha$ khi $\alpha\in(0,1)$, còn biểu thức bên phải luôn không vượt quá $(1-\alpha)$ khi $\alpha\in(0,1-\sqrt{2}/2]$.
        
        Thứ hai, $w$ và $y$ cân bằng. Tương tự, xét
        
        $$
        \dfrac{y}{w+y} = \dfrac{\rho_1}{(1-\rho_1)\rho_2+\rho_1}.
        $$
        
        Một mặt, với mọi $\alpha\in(0,(3-\sqrt{5})/2)$, có
        
        $$
        \dfrac{y}{w+y} < \dfrac{\alpha}{(1-\alpha)\alpha+\alpha} < 1-\alpha.
        $$
        
        Mặt khác, với mọi $\alpha\in(0,1/3)$, trừ trường hợp xóa phần tử và $y=1$, đều có
        
        $$
        \rho_1 \ge \min\left\{\dfrac{\alpha}{1+\alpha},\dfrac{2\alpha}{3-\alpha}\right\} = \dfrac{2\alpha}{3-\alpha},
        $$
        
        nên có
        
        $$
        \dfrac{y}{w+y} \ge \dfrac{\dfrac{2\alpha}{3-\alpha}}{\left(1-\dfrac{2\alpha}{3-\alpha}\right)\dfrac{1}{2-\alpha}+\dfrac{2\alpha}{3-\alpha}} > \alpha.
        $$
        
        Cuối cùng, xét trường hợp còn lại, tức xóa phần tử và $y=1$. Trường hợp dễ mất cân bằng nhất xảy ra khi $x=\lfloor 2/\alpha\rfloor-2$ và $w=\lfloor\beta x\rfloor$. Cây có thể khôi phục cân bằng khi và chỉ khi
        
        $$
        \dfrac{1}{1+\lfloor\beta x\rfloor}\ge\alpha \iff \lfloor\beta x\rfloor\le\dfrac{1}{\alpha}-1 \iff \beta x < \dfrac{1}{\alpha} \iff x < \dfrac{2}{\alpha}-1.
        $$
        
        Điều này luôn đúng. Như vậy hoàn tất chứng minh cho trường hợp này. Lưu ý, chứng minh của trường hợp cuối cùng đã dùng tính chất trọng số luôn là số nguyên, nên không thể gộp vào phần thảo luận trước đó.
    
    ??? note "Trường hợp 2: $w$ quá nặng, tức $\rho_2>\beta$, dùng xoay kép"
        Trước hết, $z+u$ và $v+y$ cân bằng. Điều này là do
        
        $$
        \dfrac{\alpha}{2-\alpha}+\left(1-\dfrac{\alpha}{2-\alpha}\right)\dfrac{1}{2-\alpha}\alpha < \dfrac{z+u}{x+y} = \rho_1+(1-\rho_1)\rho_2\rho_3 <\alpha+(1-\alpha)^3
        $$
        
        Biểu thức bên trái luôn lớn hơn $\alpha$ khi $\alpha\in(0,1)$, còn biểu thức bên phải luôn nhỏ hơn $(1-\alpha)$ khi $\alpha\in(0,(3-\sqrt{5})/2)$.
        
        Tiếp theo, $z$ và $u$ cân bằng. Điều này là do với $\alpha\in(0,1)$, luôn có
        
        $$
        \alpha=\dfrac{\dfrac{1}{2-\alpha}\alpha}{1-\dfrac{1}{2-\alpha}(1-\alpha)}<\dfrac{u}{z} = \dfrac{\rho_2(1-\rho_3)}{1-\rho_2\rho_3} <\dfrac{(1-\alpha)^2}{1-(1-\alpha)\alpha} < 1-\alpha.
        $$
        
        Cuối cùng, $v$ và $y$ cân bằng. Tương tự các trường hợp khác, xét
        
        $$
        \dfrac{y}{v+y} = \dfrac{\rho_1}{\rho_1+(1-\rho_1)\rho_2\rho_3}.
        $$
        
        Một mặt, với mọi $\alpha\in(0,1-\sqrt{2}/2]$, đều có
        
        $$
        \dfrac{y}{v+y} < \dfrac{\alpha}{\alpha+(1-\alpha)\dfrac{1}{2-\alpha}\alpha} \le 1-\alpha.
        $$
        
        Mặt khác,
        
        $$
        \dfrac{y}{v+y} \ge \dfrac{\rho_1}{\rho_1+(1-\rho_1)(1-\alpha)^2}.
        $$
        
        Biểu thức bên phải không nhỏ hơn $\alpha$ khi và chỉ khi
        
        $$
        \rho_1 \ge \dfrac{\alpha(1-\alpha)}{1+\alpha(1-\alpha)}.
        $$
        
        Nếu mất cân bằng do chèn, thì $\rho_1\ge \alpha/(1+\alpha)$, nên điều kiện được thỏa mãn. Nếu không, tình huống phức tạp hơn:
        
        -   Khi $y\ge 3$, $\rho_1\ge 3\alpha/(4-\alpha)$, và $3\alpha/(4-\alpha)\ge\alpha(1-\alpha)/(1+\alpha(1-\alpha))$ đúng với mọi $\alpha\in[1-\sqrt{3}/2,1)$;
        -   Khi $y=2$, trường hợp dễ mất cân bằng nhất xảy ra tại $x=\lfloor 3/\alpha\rfloor-3$, $w=\lfloor(1-\alpha)x\rfloor$ và $v=\lfloor(1-\alpha)w\rfloor$; lúc này $v/(v+y)\ge\alpha$ đúng với mọi $\alpha\in(3/22,1)$;
        -   Khi $y=1$, trường hợp dễ mất cân bằng nhất xảy ra tại $x=\lfloor 2/\alpha\rfloor-2$, $w=\lfloor(1-\alpha)x\rfloor$ và $v=\lfloor(1-\alpha)w\rfloor$; lúc này $v/(v+y)\ge\alpha$ đúng với mọi $\alpha\in(2/11,1)$.
        
        Phần thảo luận của hai trường hợp cuối cũng dùng tính chất trọng số của tất cả nút đều là số nguyên.
    
    Tổng hợp hai trường hợp, khi $\alpha\in(2/11,1-\sqrt{2}/2]$, chiến lược kết hợp xoay đơn và xoay kép ở trên có thể bảo đảm cân bằng của cây.
    
    Từ quá trình phân tích này có thể thấy, tình huống khó giữ cân bằng nhất xảy ra khi xóa nút khỏi cây có kích thước nhỏ. Ngoài $\beta=1/(2-\alpha)$, với các lựa chọn tham số khác, cũng có thể lặp lại quá trình trên để chứng minh tính đúng đắn, chỉ là một số bất đẳng thức được sử dụng cần được điều chỉnh tương ứng.

Sau đó, Hirai và Yamamoto đã dùng chứng minh bằng máy để xác định đầy đủ phạm vi của tất cả $(\alpha,\beta)$ khả thi; kết quả là một hình hai chiều khá phức tạp:

![](images/wblt-param-range.svg)

Trong bài viết của mình, họ khuyến nghị dùng chiến lược sau để duy trì cân bằng:

-   Khi $x>3y$, phán định là mất cân bằng;
-   Khi $w\le 2z$, chọn chiến lược xoay đơn, ngược lại chọn chiến lược xoay kép.

Lý do là đây là chiến lược duy nhất trong phạm vi tham số khả thi có thể biểu diễn bằng số nguyên đơn giản, qua đó tránh tổn thất hiệu năng do phép toán dấu phẩy động. Chiến lược họ khuyến nghị tương đương với việc lấy $(\alpha,\beta)=(1/4,2/3)$. Trong thực hành, có thể chọn tham số phù hợp tùy tình huống cụ thể.

Cài đặt tham khảo như sau:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:too-heavy"
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:balance"
    ```

Sau khi cài đặt chiến lược duy trì cân bằng, thuật toán hợp nhất hai cây trở nên rất đơn giản. Vẫn giả sử $x>y$, chiến lược hợp nhất như sau:

-   Nếu cây con phải $y$ rỗng, trả về trực tiếp cây con trái $x$;
-   Nếu hai cây con trái phải $x$ và $y$ đã cân bằng, tức $y\ge\alpha(x+y)$, nối trực tiếp hai cây con;
-   Nếu không, hợp nhất cây con phải $w$ của $x$ với $y$, nối cây con trái $z$ với kết quả hợp nhất của chúng, rồi điều chỉnh cân bằng của cây mới.

Cài đặt tham khảo như sau:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:merge-by-balancing"
    ```

Có thể chứng minh rằng cách này duy trì được cân bằng của cây sau khi hợp nhất, và độ phức tạp của thao tác là $O(|\log(x/y)|)$.

??? note "Chứng minh cân bằng và độ phức tạp"
    Chỉ cần xét trường hợp $y$ quá nhẹ, tức $y<\alpha(x+y)$. Khi đó, trước tiên hợp nhất $w$ và $y$, rồi nối $z$ với $w+y$. Cần chứng minh rằng chỉ cần điều chỉnh cân bằng tại gốc cây là đủ để bảo đảm cây cân bằng. Giả sử cây con trái và phải của cây $w+y$ lần lượt là $c$ và $d$, còn cây con trái và phải của $c$ lần lượt là $a$ và $b$. Việc điều chỉnh cân bằng tại gốc cây có thể chia thành ba trường hợp:
    
    ??? note "Trường hợp 1: $z$ và $w+y$ đã cân bằng, không cần điều chỉnh thêm, tức $z\ge\alpha(x+y)$"
        Theo định nghĩa cân bằng, cây con $z$ và $w+y$ đều cân bằng, đồng thời chúng cân bằng với nhau, nên toàn bộ cây cũng cân bằng.
    
    ??? note "Trường hợp 2: $z$ quá nhẹ và $c$ không quá nặng, có thể khôi phục cân bằng bằng xoay đơn, tức $z<\alpha(x+y)$ và $c\le\beta(w+y)$"
        Lúc này, vì $z$ và $w$ cân bằng, nhưng $y$ quá nhẹ so với $x = z+w$, nên trọng số của cây con $z$ thỏa
        
        $$
        \alpha(1-\alpha)(x+y) <  \alpha(z+w) \le z \le \alpha(x+y) .
        $$
        
        Còn trọng số của $c$ thỏa
        
        $$
        \alpha(w+y) \le c \le \beta(w+y).
        $$
        
        Do đó, $z$ và $c$ cân bằng với nhau, miễn là
        
        $$
        \dfrac{\alpha}{1-\alpha}<\dfrac{1-\alpha}{\alpha}\alpha<\dfrac{c}{z}=\dfrac{w+y}{z}\dfrac{c}{w+y} < \dfrac{1-\alpha(1-\alpha)}{\alpha(1-\alpha)}\beta\le\dfrac{1-\alpha}{\alpha},
        $$
        
        điều này yêu cầu
        
        $$
        \beta\le \dfrac{(1-\alpha)^2}{1-\alpha(1-\alpha)}.
        $$
        
        Đồng thời, $z+c$ và $d$ cân bằng với nhau, miễn là
        
        $$
        \alpha\le (1-\beta)(1-\alpha)\le \dfrac{d}{w+y}\dfrac{w+y}{x+y}  = \dfrac{d}{x+y} < \dfrac{d}{c+d} \le 1-\alpha,
        $$
        
        điều này yêu cầu
        
        $$
        \beta \le \dfrac{1-2\alpha}{1-\alpha}.
        $$
    
    ??? note "Trường hợp 3: $z$ quá nhẹ và $c$ quá nặng, có thể khôi phục cân bằng bằng xoay kép, tức $z<\alpha(x+y)$ và $c>\beta(w+y)$"
        Tương tự trường hợp 2, có
        
        $$
        \begin{aligned}
        \alpha(1-\alpha)(x+y) < z &\le \alpha(x+y),\\
        \beta(w+y)<c &\le (1-\alpha)(w+y),\\
        \alpha c\le a,b &\le (1-\alpha)c.
        \end{aligned}
        $$
        
        Do đó, $z$ và $a$ cân bằng với nhau, miễn là
        
        $$
        \dfrac{\alpha}{1-\alpha}\le\dfrac{1-\alpha}{\alpha}\beta\alpha\le\dfrac{a}{z} = \dfrac{w+y}{z}\dfrac{a}{c+d} < \dfrac{1-\alpha(1-\alpha)}{\alpha(1-\alpha)}(1-\alpha)^2,
        $$
        
        điều này yêu cầu
        
        $$
        \beta\ge\dfrac{\alpha}{(1-\alpha)^2}.
        $$
        
        Thứ hai, $b$ và $d$ cân bằng với nhau, miễn là
        
        $$
        \dfrac{\alpha}{1-\alpha}\le\dfrac{\beta}{1-\beta}\alpha \le \dfrac{b}{d} = \dfrac{c}{d}\dfrac{b}{c} \le \dfrac{1-\alpha}{\alpha}(1-\alpha) < \dfrac{1-\alpha}{\alpha},
        $$
        
        điều này yêu cầu
        
        $$
        \beta\ge\dfrac{1}{2-\alpha}.
        $$
        
        Cuối cùng, $z+a$ và $b+d$ cân bằng với nhau, miễn là
        
        $$
        \alpha<(1-\alpha)(1-(1-\alpha)^2)\le\frac{b+d}{x+y} = \dfrac{w+y}{x+y}\dfrac{b+d}{w+y} < (1-\alpha(1-\alpha))(1-\beta\alpha) \le 1-\alpha,
        $$
        
        điều này yêu cầu
        
        $$
        \beta\ge\dfrac{\alpha}{1-\alpha+\alpha^2}.
        $$
    
    Tổng hợp ba trường hợp, miễn là
    
    $$
    0<\alpha\le 1-\dfrac{\sqrt{2}}{2},~\dfrac{1}{2-\alpha}\le\beta\le\dfrac{1-2\alpha}{1-\alpha},
    $$
    
    có thể bảo đảm cây sau khi hợp nhất điều chỉnh được về trạng thái cân bằng bằng chiến lược kết hợp xoay đơn và xoay kép. Phạm vi này bao gồm phạm vi tham số đã nêu trong phần chính.
    
    Cuối cùng, xét vì sao độ phức tạp của thuật toán này là $O(|\log(x/y)|)$. Trong quá trình hợp nhất, nếu $y$ quá nhẹ so với $x$, thuật toán thử hợp nhất nó với cây con phải của $x$. Quá trình này tiếp tục cho tới khi gặp cây con gốc tại một hậu duệ nào đó của $x$ cân bằng với $y$. Vì mỗi khi đi sâu xuống một tầng, trọng số cây con ít nhất trở thành $(1-\alpha)$ lần so với trước đó, nên cần nhiều nhất $\log_{\frac{1}{1-\alpha}}(x/y)$ lần lặp để tìm được cây con cân bằng với $y$. Vì vậy, thuật toán hợp nhất này gọi thuật toán cân bằng $O(\log n)$ lần[^merge-complexity-cmp], và độ phức tạp cũng là $O(\log n)$.
    
    Quá trình lập luận này phụ thuộc vào một kết luận không hoàn toàn trực tiếp: khi liên tục lấy cây con phải, $y$ sẽ không chuyển từ quá nhẹ so với cây con bên trái sang quá nặng so với nó chỉ sau một lần lặp. Lý do là phạm vi trọng số của cây con có thể cân bằng với $y$ nằm giữa $\alpha y/(1-\alpha)$ và $(1-\alpha)y/\alpha$. Do đó, nếu trong một lần lặp mà $y$ chuyển từ quá nhẹ sang quá nặng, trọng số của cây con của $x$ trong lần lặp đó ít nhất đã co lại thành $\alpha^2/(1-\alpha)^2$ lần so với ban đầu. Nhưng trong một lần lặp, trọng số cây con nhiều nhất chỉ có thể co lại thành $\alpha$ lần so với ban đầu; trong phạm vi $\alpha$ nói trên, lại có $\alpha>\alpha^2/(1-\alpha)^2$. Điều này cho thấy tình huống giả định trước đó là không thể, và sau một lần lặp nào đó nhất định sẽ xuất hiện trường hợp $y$ cân bằng với một cây con nào đó của $x$.

### Duy trì bằng phép hợp nhất

Hợp nhất hai cây con có nghĩa là xây dựng một cây mới trong điều kiện khóa của cây con trái luôn không lớn hơn khóa của cây con phải. Thông tin của tất cả nút lá trong cây mới phải đúng bằng hợp thông tin nút lá của hai cây con ban đầu, đồng thời cây mới vẫn cân bằng.

Để làm điều đó, có chiến lược sau[^more-join]: (vẫn giả sử $x>y$)

-   Nếu cây con phải $y$ rỗng, trả về trực tiếp cây con trái $x$;
-   Nếu hai cây con trái phải $x$ và $y$ đã cân bằng, tức $y\ge\alpha(x+y)$, nối trực tiếp hai cây con;
-   Nếu không, cây con phải $y$ quá nhẹ, nhưng nếu cây con trái $z$ của $x$ và $w+y$ có thể cân bằng, tức $z\ge\alpha(x+y)$, thì hợp nhất $w$ với $y$ trước, rồi hợp nhất $z$ với $w+y$;
-   Nếu không, cả $z$ và $y$ đều quá nhẹ; lúc này cần trước hết hợp nhất $z$ với cây con trái $u$ của $w$, rồi hợp nhất cây con phải $v$ của $w$ với $y$, sau đó **hợp nhất** kết quả của hai lần hợp nhất thành cây mới.

So với chiến lược cân bằng ở phần trước, trong hai trường hợp sau, cách tổ hợp các nút lần lượt tương tự kết quả của xoay đơn và xoay kép. Khác biệt nằm ở việc thay thao tác nối cây con bằng thao tác hợp nhất.

Có thể chứng minh rằng, khi

$$
0<\alpha \le 1-\dfrac{\sqrt{2}}{2}\approx 0.292
$$

cây thu được theo cách này luôn cân bằng, và độ phức tạp của thao tác là $O(|\log(x/y)|)$. Nói cách khác, chi phí hợp nhất hai cây không phụ thuộc vào kích thước tuyệt đối của hai cây, mà chỉ phụ thuộc vào kích thước tương đối của chúng.

??? note "Chứng minh cân bằng và độ phức tạp"
    Khi hợp nhất hai cây con có trọng số lần lượt là $x$ và $y$, đặt số lần cần nối trực tiếp hai cây con là $\tau(x,y)$. Nói nghiêm ngặt, cần chứng minh rằng khi $0<\alpha\le 1-\sqrt{2}/2$, tồn tại hằng số $C>0$ sao cho với mọi $x>y>0$ đều có
    
    $$
    \tau(x,y) \le 1+C\log^+\dfrac{\alpha x}{(1-\alpha)^2y},
    $$
    
    trong đó $\log^+ x = \max\{0,\log x\}$; hơn nữa, với mọi $x/y\le(1-\alpha)/\alpha$, đều có $\tau(x,y)=1$. Trên thực tế, hằng số trong công thức có thể lấy là
    
    $$
    C = -\dfrac{2}{\log(1-\alpha)}.
    $$
    
    Điều này cho thấy độ phức tạp của thuật toán hợp nhất là $O(|\log(x/y)|)$.
    
    Để chứng minh cây thu được từ thuật toán hợp nhất luôn cân bằng và biểu thức độ phức tạp ở trên đúng, cần dùng quy nạp. Với mọi điểm lưới trong góc phần tư thứ nhất $(x,y)\in\mathbf N^2_+$, gán thứ tự từ điển của $(x+y,|x-y|)$. Đây là một thứ tự tốt trên tập này, nên có thể quy nạp theo thứ tự đó. Cơ sở quy nạp là $(x,y)=(1,1)$; khi đó hai cây con đều chỉ có một nút lá, cây con thu được bằng cách nối trực tiếp tất nhiên cân bằng, và $\tau(x,y)=1$, phù hợp với công thức trên. Dưới đây giả sử quy nạp đã tiến tới $(x,y)$, và kết luận đúng với mọi điểm đứng trước $(x,y)$. Có ba trường hợp:
    
    ??? note "Trường hợp 1: cây $x$ và $y$ cân bằng, tức $y\ge\alpha(x+y)$"
        Lúc này, cây thu được bằng nối trực tiếp cũng cân bằng, và chỉ gọi thuật toán nối cây một lần, nên có $\tau(x,y)=1$.
    
    ??? note "Trường hợp 2: cây $y$ quá nhẹ, nhưng $z$ không quá nhẹ, tức $y<\alpha(x+y)\le z$"
        Lúc này, trước hết hợp nhất $w$ và $y$, sau đó hợp nhất $z$ với $w+y$, nên
        
        $$
        \tau(x,y) = \tau(w,y) + \tau(z,w+y).
        $$
        
        Theo giả thiết quy nạp, cây con $w+y$ đã cân bằng. Với bước hợp nhất thứ hai, thật ra có thể chứng minh trực tiếp rằng $z$ và $w+y$ cân bằng:
        
        $$
        \alpha \le \dfrac{z}{z+(w+y)} = \dfrac{z}{x+y} < \dfrac{z}{z+w} \le 1-\alpha.
        $$
        
        Vì vậy, việc hợp nhất $z$ và $w+y$ thực chất là nối trực tiếp hai cây con, có $\tau(z,w+y) = 1$. Do đó, cây cuối cùng thu được cũng cân bằng.
        
        Bây giờ ước lượng kích thước của $\tau(w,y)$. Vì $y>(\alpha/(1-\alpha))x$ và $\alpha x\le w\le(1-\alpha)x$, nới lỏng bất đẳng thức cho kết quả
        
        $$
        \dfrac{\alpha}{1-\alpha}<1-\alpha=\dfrac{\alpha x}{(\alpha/(1-\alpha))x}< \dfrac{w}{y} \le \dfrac{(1-\alpha)x}{y}.
        $$
        
        Điều này cho thấy $w$ và $y$ chỉ không cân bằng khi $w>y$, nên có
        
        $$
        \begin{aligned}
        \tau(w,y) &\le 1+C\log^+\dfrac{\alpha w}{(1-\alpha)^2y} \le 1+C\log^+\dfrac{\alpha x}{(1-\alpha)y} \\
        &= 1 + C\log(1-\alpha) + C\log^+\dfrac{\alpha x}{(1-\alpha)^2y}.
        \end{aligned}
        $$
        
        Đẳng thức ở bước cuối đúng vì $x/y>(1-\alpha)/\alpha$.
        
        Vì vậy, có
        
        $$
        \tau(x,y) \le 2 + C\log(1-\alpha) + C\log^+\dfrac{\alpha x}{(1-\alpha)^2y}.
        $$
    
    ??? note "Trường hợp 3: cả cây $y$ và $z$ đều quá nhẹ, tức $y,z<\alpha(x+y)$"
        Lúc này, trước hết hợp nhất $z$ và $u$, rồi hợp nhất $v$ và $y$, cuối cùng hợp nhất $z+u$ với $v+y$. Vì vậy,
        
        $$
        \tau(x,y) = \tau(z,u) + \tau(v,y) + \tau(z+u,v+y).
        $$
        
        Tương tự các trường hợp phía trước, có thể ước lượng tỷ lệ trọng số của hai cây con tại mỗi bước hợp nhất.
        
        Vì $z,y<\alpha(x+y)$, nên $w>(1-2\alpha)(x+y)$. Đồng thời, dùng điều kiện cân bằng, có $\alpha\le z/x,w/x,u/w,v/w\le 1-\alpha$. Điều này cho thấy
        
        $$
        \begin{aligned}
        \dfrac{\alpha}{1-\alpha}<\dfrac{\alpha}{1-\alpha}\frac{1}{1-\alpha}\le \dfrac{z}{u} &= \dfrac{z}{w}\dfrac{w}{u} < \dfrac{\alpha}{1-2\alpha}\dfrac{1}{\alpha} \le \dfrac{1-\alpha}{\alpha},\\
        \dfrac{\alpha}{1-\alpha}\le\alpha\dfrac{1-2\alpha}{\alpha}< \dfrac{v}{y} &= \dfrac{v}{w}\dfrac{w}{y} \le (1-\alpha)\dfrac{(1-\alpha)x}{y} = (1-\alpha)^2\dfrac{x}{y}.
        \end{aligned}
        $$
        
        Với hạng cuối cùng, có
        
        $$
        \dfrac{z+u}{v+y} = \dfrac{x+y}{v+y}-1 = \dfrac{x+y}{y}\dfrac{y}{v+y} - 1 < (1-\alpha)\left(\dfrac{x}{y}+1\right)-1 < (1-\alpha)\dfrac{x}{y}.
        $$
        
        Ngược lại, có
        
        $$
        \dfrac{z+u}{v+y} = \dfrac{x+y}{v+y}-1 \ge \dfrac{x+y}{(1-\alpha)^2x+y}-1 > \dfrac{1}{(1-\alpha)^3+\alpha}-1 > \dfrac{\alpha}{1-\alpha}.
        $$
        
        Từ các bất đẳng thức này, có thể chỉ ra rằng cây cuối cùng thu được nhất định cân bằng. Theo giả thiết quy nạp, hợp nhất $z$ với $u$ và hợp nhất $v$ với $y$ đều cho cây cân bằng. Hơn nữa, bước đầu tiên hợp nhất $z$ và $u$ thực chất là nối trực tiếp hai cây. Với việc hợp nhất cây $z+u$ và cây $v+y$, lại có hai trường hợp con:
        
        -   Nếu $z+u\le v+y$, thì tỷ lệ trọng số của chúng lớn hơn nghiêm ngặt $\alpha/(1-\alpha)$, nên có thể nối trực tiếp, và kết quả cân bằng;
        -   Nếu không, tỷ lệ trọng số của chúng tất nhiên nhỏ hơn nghiêm ngặt $x/y$, nhưng $(z+u)+(v+y)=x+y$, nên $|(z+u)-(v+y)|<|x-y|$; theo thứ tự từ điển đã nêu phía trước, trường hợp này cũng có thể áp dụng giả thiết quy nạp, và kết quả cũng cân bằng.
        
        Tiếp tục áp dụng giả thiết quy nạp, suy ra:
        
        $$
        \begin{aligned}
        \tau(z,u) &= 1,\\
        \tau(v,y) &\le 1+C\log^+\dfrac{\alpha x}{y},\\
        \tau(z+u,v+y) &\le 1 + C\log^+\dfrac{\alpha x}{(1-\alpha)y}.
        \end{aligned}
        $$
        
        Nếu cộng trực tiếp ba bất đẳng thức, hệ số trước hạng logarit sẽ trở thành $2C$, nên không thể hoàn tất quy nạp. Vì vậy, cần một ước lượng tinh tế hơn.
        
        Khi $\max\{v/y,(z+u)/(v+y)\}\le(1-\alpha)/\alpha$, trong $\tau(v,y)$ và $\tau(z+u,v+y)$ nhất định có một hạng bằng $1$, nên có
        
        $$
        \begin{aligned}
        \tau(v,y) + \tau(z+u,v+y) &\le 2 + C\log^+\dfrac{\alpha x}{(1-\alpha)y}\\
        &= 2 + C\log(1-\alpha) + C\log^+\dfrac{\alpha x}{(1-\alpha)^2y}.
        \end{aligned}
        $$
        
        Nếu không, phải có
        
        $$
        \begin{aligned}
        \tau(v,y) + \tau(z+u,v+y) 
        &\le 2 + C\log^+\dfrac{\alpha v}{(1-\alpha)^2y} + C\log^+\dfrac{\alpha(z+u)}{(1-\alpha)^2(v+y)}\\
        &= 2 + C\log\dfrac{\alpha}{(1-\alpha)^2} + C\log^+\dfrac{\alpha v(z+u)}{(1-\alpha)^2y(v+y)}.
        \end{aligned}
        $$
        
        Với $0<\alpha\le 1-\sqrt{2}/2$, có
        
        $$
        \dfrac{\alpha}{(1-\alpha)^2} < 1-\alpha.
        $$
        
        Hơn nữa, có
        
        $$
        \begin{aligned}
        \dfrac{v(z+u)}{y(v+y)} &= \left(\dfrac{v+y}{y}-1\right)\left(\dfrac{x+y}{y}\dfrac{y}{v+y} - 1\right) \\
        &= \dfrac{x+y}{y} + 1 -\dfrac{x+y}{y}\dfrac{y}{v+y}-\dfrac{v+y}{y} < \dfrac{x}{y}.
        \end{aligned}
        $$
        
        Điều này cho thấy trong trường hợp sau cũng có
        
        $$
        \tau(v,y) + \tau(z+u,v+y) < 2 + C\log(1-\alpha) + C\log^+\dfrac{\alpha x}{(1-\alpha)^2y}.
        $$
        
        Độ phức tạp hợp nhất tổng thể là
        
        $$
        \tau(x,y) \le 3 + C\log(1-\alpha) + C\log^+\dfrac{\alpha x}{(1-\alpha)^2y}.
        $$
    
    Tổng hợp mọi trường hợp, có
    
    $$
    \tau(x,y) \le 3 + C\log(1-\alpha) + C\log^+\dfrac{\alpha x}{(1-\alpha)^2y}.
    $$
    
    Vì vậy, chỉ cần lấy $2+C\log(1-\alpha)\le 0$ là có thể hoàn tất quy nạp về độ phức tạp. Một lựa chọn tự nhiên là
    
    $$
    C = -\dfrac{2}{\log(1-\alpha)}.
    $$
    
    Hằng số này cho thấy khi hợp nhất hai cây, số lần nối trực tiếp cây con xấp xỉ sẽ không vượt quá hai lần chênh lệch chiều cao cây.

Cài đặt tham khảo như sau:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:merge"
    ```

Dùng chiến lược hợp nhất này, việc duy trì cân bằng của cây cũng rất đơn giản: khi mất cân bằng, hợp nhất trực tiếp hai cây con trái phải.

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:balance-by-merging"
    ```

Vì hai cây cần tái cân bằng luôn có kích thước gần cân bằng, độ phức tạp của việc duy trì cân bằng là $O(1)$.

## Thao tác cơ bản trên cây cân bằng

Với các hàm đã cài đặt ở phần trước, WBLT có thể hỗ trợ mọi thao tác cơ bản của cây cân bằng. Phần này lấy đa tập làm ví dụ để thảo luận cách dùng WBLT cài đặt cây cân bằng.

### Xây cây

Thao tác xây cây rất giống cây đoạn: đệ quy chia đôi đoạn, tới khi độ dài đoạn là $1$ thì đặt thông tin cần duy trì lên nút lá, rồi hợp nhất thông tin đoạn khi quay lui.

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-2.cpp:build"
    ```

Độ phức tạp thời gian là $O(n)$.

### Chèn và xóa

Với thao tác chèn, cần đệ quy từ nút gốc đi xuống cho tới khi tìm được nút lá nhỏ nhất có khóa lớn hơn hoặc bằng khóa của phần tử cần chèn. Sau đó tạo mới hai nút: một nút lưu giá trị mới chèn, nút còn lại làm cha mới của hai lá để thay thế vị trí nút lá vừa tìm được, rồi nối hai lá này vào nút cha đó. Khi quay lui, cần duy trì cân bằng của cây.

![](./images/wblt-insert-delete.svg)

Trong hình minh họa, cần chèn phần tử có giá trị $4$ vào cây bên trái. Trước hết tìm nút lá có giá trị $5$, sau đó tạo mới nút lá $4$ và nút không phải lá $\text{d}$, rồi nối $4$ và $5$ vào $\text{d}$. Kết quả là cây bên phải.

Với thao tác xóa, xét quá trình ngược lại: tìm một nút lá có khóa bằng giá trị cần xóa, xóa nó và nút cha của nó, rồi dùng nút con còn lại của cha để thay thế vị trí của cha. Khi quay lui, cũng cần duy trì cân bằng của cây.

Cài đặt tham khảo như sau:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:insert-remove"
    ```

Chú ý xử lý cây rỗng. Nếu không muốn xử lý cây rỗng, có thể chèn trước phần tử $\infty$ vào cây.

Độ phức tạp thời gian của cả hai thao tác đều là $O(\log n)$.

### Truy vấn hạng

Vì hình thái của WBLT rất giống cây đoạn, truy vấn hạng có thể dùng cách tương tự tìm kiếm nhị phân trên cây đoạn. Nếu giá trị lớn nhất của cây con trái lớn hơn hoặc bằng giá trị cần tìm thì đi sang nút con trái; nếu không, đi sang nút con phải, đồng thời cộng trọng số của cây con trái vào đáp án.

Cài đặt tham khảo như sau:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:rank"
    ```

Độ phức tạp thời gian là $O(\log n)$.

### Truy vấn theo hạng

Vẫn dùng ý tưởng tìm kiếm nhị phân trên cây đoạn, chỉ khác ở chỗ giá trị so sánh là trọng số của nút.

Cài đặt tham khảo như sau:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:kth-element"
    ```

Độ phức tạp thời gian là $O(\log n)$.

### Tìm tiền nhiệm và kế nhiệm

Chỉ cần kết hợp hai chức năng trên.

Cài đặt tham khảo như sau:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:prev-next"
    ```

Nếu muốn cài đặt trực tiếp, cần chú ý rằng các nút có cùng khóa có thể được lưu ở nhiều nút lá.

### Thao tác tách

Phép tách của WBLT tương tự [Treap không xoay](./treap.md#tách-split): dựa vào kích thước cây con hoặc khóa để quyết định đệ quy tách cây con trái hay cây con phải. Điểm khác là WBLT cần **hợp nhất** các cây con được tách ra để duy trì cân bằng của cây cuối cùng sau khi tách.

Cài đặt tham khảo cho cách tách theo kích thước cây con như sau:

???+ example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-2.cpp:split"
    ```

Độ phức tạp thời gian là $O(\log n)$.

??? note "Chứng minh độ phức tạp"
    Số tầng đệ quy đi xuống không vượt quá chiều cao cây, tức là $O(\log n)$. Cần chứng minh rằng độ phức tạp của việc lần lượt hợp nhất các cây con được tách ra ở hai phía trái phải là $O(\log n)$. Không mất tính tổng quát, chỉ xét các cây con phía trái, vì phía phải đối xứng. Giả sử các cây con được tách ra ở phía trái theo thứ tự từ dưới lên trên là $T_1,T_2,\cdots,T_\ell$, số lượng các cây con này là $\ell\in O(\log n)$. Quá trình hợp nhất có thể mô tả như sau: bắt đầu từ $T'_1=T_1$, hợp nhất $T'_{i-1}$ với $T_i$ để thu được $T'_i$, rồi tiếp tục đệ quy cho tới khi hợp nhất xong tất cả cây con. Tổng độ phức tạp của việc hợp nhất có thể biểu diễn là
    
    $$
    \sum_{i=2}^\ell \tau(T_i,T'_{i-1}),
    $$
    
    trong đó $\tau(T_i,T'_{i-1})$ là độ phức tạp của việc hợp nhất $T_i$ và $T'_{i-1}$.
    
    Nếu luôn có $w(T_i)\ge w(T'_{i-1})$, thì theo biểu thức độ phức tạp của việc hợp nhất hai cây con, có
    
    $$
    \tau(T_i,T'_{i-1}) \in O\left(\log\dfrac{w(T_i)}{w(T'_{i-1})}\right) \subseteq O\left(\log\dfrac{w(T'_i)}{w(T'_{i-1})}\right).
    $$
    
    Vì các hằng số trong các ký hiệu $O$ lớn này đều thống nhất, có thể cộng trực tiếp và triệt tiêu dạng telescoping.
    
    Tuy nhiên, cần chú ý rằng $w(T_i)\ge w(T'_{i-1})$ không phải lúc nào cũng đúng, vì $T'_{i-1}$ được tách ra từ cây con phải tương ứng của $T_i$ trong cây ban đầu, và cây con phải này có thể lớn hơn cây con trái $T_i$. Dù vậy, ngay cả khi $T'_{i-1}$ lớn hơn $T_i$, với tư cách là một phần của cây con phải, trọng số $w(T'_{i-1})$ cũng không vượt quá $(1-\alpha)/\alpha$ lần $w(T_i)$. Điều này nghĩa là lúc đó $T'_{i-1}$ và $T_i$ nhất định cân bằng, nên độ phức tạp hợp nhất là $O(1)$.
    
    Tổng hợp hai trường hợp này, độ phức tạp của một lần hợp nhất có thể viết là
    
    $$
    \tau(T_i,T'_{i-1}) \in O\left(\log\dfrac{w(T'_i)}{w(T'_{i-1})}\right) + O(1).
    $$
    
    Do đó, tổng độ phức tạp của việc hợp nhất là
    
    $$
    O\left(\sum_{i=2}^\ell\left( 1+\log\dfrac{w(T'_i)}{w(T'_{i-1})}\right) \right) \subseteq O(\ell+\log w(T'_\ell)) \subseteq O(\log n).
    $$
    
    Điều này cũng cho thấy tổng độ phức tạp của thuật toán tách là $O(\log n)$.

## Cài đặt tham khảo

Bài này đã giới thiệu cách dùng WBLT để hoàn thành các thao tác cơ bản của cây cân bằng. Dưới đây là [mẫu cây cân bằng thông thường](https://loj.ac/p/104) cài đặt bằng WBLT.

??? example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-1.cpp:full-text"
    ```

Dùng hợp nhất và tách, cũng có thể cài đặt cây cân bằng văn nghệ. Dưới đây là [mẫu cây cân bằng văn nghệ](https://loj.ac/p/105) cài đặt bằng WBLT; cần đẩy nhãn lười xuống khi đi xuống cây.

??? example "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/wblt/wblt-2.cpp:full-text"
    ```

Chú ý rằng WBLT cần gấp đôi không gian. Khi có liên quan tới tách và hợp nhất, cần thu gom rác và kịp thời thu hồi các nút không còn dùng tới; nếu không, mức sử dụng không gian sẽ không còn tuyến tính.

## Tài liệu tham khảo và chú thích

-   [Weight-balanced tree - Wikipedia](https://en.wikipedia.org/wiki/Weight-balanced_tree)
-   Nievergelt, J.; Reingold, E. M. (1973). "Binary Search Trees of Bounded Balance". SIAM Journal on Computing. 2: 33-43.
-   Blum, Norbert; Mehlhorn, Kurt (1980). "On the average number of rebalancing operations in weight-balanced trees". Theoretical Computer Science. 11 (3): 303-320.
-   Hirai, Y.; Yamamoto, K. (2011). "Balancing weight-balanced trees". Journal of Functional Programming. 21 (3): 287.
-   Blelloch, Guy E.; Ferizovic, Daniel; Sun, Yihan (2016), "Just Join for Parallel Ordered Sets", Symposium on Parallel Algorithms and Architectures, Proc. of 28th ACM Symp. Parallel Algorithms and Architectures (SPAA 2016), ACM, pp. 253-264.
-   Straka, Milan. (2011). "Adams'Trees Revisited: Correctness Proof and Efficient Implementation." International Symposium on Trends in Functional Programming. Berlin, Heidelberg: Springer Berlin Heidelberg.

[^wrong-range]: Phạm vi tham số $\alpha < 1-\dfrac{\sqrt{2}}{2},~\beta=\dfrac{1-2\alpha}{1-\alpha}$ được đưa ra trong bài báo gốc của Nievergelt và Reingold là sai. Bài viết của Hirai và Yamamoto đưa ra phản ví dụ tương ứng; vấn đề chủ yếu xuất hiện trên một số cây rất nhỏ, khiến toàn bộ chứng minh quy nạp mất hiệu lực. Trong thi lập trình thuật toán thực tế, rất khó tạo dữ liệu có thể đánh bại các tham số sai này, nên tác động thực tế thường không đáng kể.

[^merge-complexity-cmp]: Vì một thao tác cân bằng đơn lẻ nhiều nhất tương đương với nối cây con hai lần, hơn nữa khi hai cây con cuối cùng đã cân bằng vẫn cần gọi thuật toán nối cây con một lần, nên nếu tính theo số lần gọi thuật toán nối cây con, hằng số của thao tác hợp nhất cài đặt dựa trên cân bằng và thuật toán cân bằng bằng hợp nhất trực tiếp ở phần sau là như nhau.

[^more-join]: Từ chứng minh phía sau có thể thấy: trong trường hợp thứ ba, $z$ và $w+y$ luôn cân bằng; trong trường hợp thứ tư, $z$ và $u$ luôn cân bằng. Chúng đều có thể được nối trực tiếp, không cần hợp nhất.
