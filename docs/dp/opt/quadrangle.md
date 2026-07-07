author: Marcythm, zyf0726, hsfzLZH1, MingqiHuang, Ir1d, greyqz, billchenchina, Chrogeek, StudyingFather, NFLSCode, c-forrest

Tối ưu bằng bất đẳng thức tứ giác sử dụng tính đơn điệu của quyết định trong công thức chuyển trạng thái, nên cũng thường được gọi là **DP tối ưu bằng tính đơn điệu quyết định**.

## Kiến thức cơ bản

<span id="kiến-thức-cơ-bản"></span>

Xét trường hợp đơn giản nhất: cần giải một loạt bài toán tối ưu sau:

$$
f(i) = \min_{1 \leq j \leq i} w(j,i) \qquad \left(1 \leq i \leq n\right) \tag{1}
$$

Trong phần này giả sử hàm chi phí $w(j,i)$ có thể được tính trong thời gian $O(1)$.

???+ info "Quy ước"
    Công thức chuyển trạng thái của quy hoạch động thường có thể viết dưới dạng một loạt bài toán tối ưu. Lấy công thức (1) làm ví dụ, các bài toán này có tham số $i$; hàm mục tiêu và miền nghiệm khả thi đều có thể phụ thuộc vào $i$. Mỗi bài toán, khi tham số $i$ đã cho, sẽ chọn một nghiệm khả thi $j$ để cực tiểu hóa giá trị hàm mục tiêu. Để trình bày thuận tiện, dưới đây gọi ngắn gọn bài toán tối ưu có tham số $i$ là "bài toán $i$", nghiệm khả thi $j$ của bài toán này là "quyết định $j$", và giá trị hàm mục tiêu tại nghiệm tối ưu là "trạng thái $f(i)$". Đồng thời, ký hiệu điểm quyết định tối ưu nhỏ nhất ứng với bài toán $i$ là $\operatorname{opt}(i)$.

Trong trường hợp tổng quát, tổng độ phức tạp thời gian của các bài toán này là $O(n^2)$, vì với bài toán $i$, cần xét mọi quyết định $j$ có thể. Khi thỏa mãn tính đơn điệu quyết định, có thể thu hẹp hiệu quả không gian quyết định và tối ưu tổng độ phức tạp.

-   **Tính đơn điệu quyết định**: với mọi $i_1 < i_2$, luôn có $\operatorname{opt}(i_1) \leq \operatorname{opt}(i_2)$.

??? note "Ghi chú"
    Với bài toán $i$, tập quyết định tối ưu không nhất thiết là một khoảng. Tính đơn điệu quyết định cũng có thể được định nghĩa trên tập các quyết định tối ưu. Với hai tập $A$ và $B$, có thể định nghĩa $A \leq B$ khi và chỉ khi với mọi $a\in A$ và $b\in B$, có $\min\{a,b\}\in A$ và $\max\{a,b\}\in B$. Điều này kéo theo tính đơn điệu của điểm quyết định tối ưu nhỏ nhất (hoặc lớn nhất), tức định nghĩa được dùng trong phần này. Các kết luận trong bài viết về điểm quyết định tối ưu nhỏ nhất cũng áp dụng cho điểm quyết định tối ưu lớn nhất. Tuy nhiên, có những trường hợp điểm quyết định tối ưu nhỏ nhất của một bài toán lớn hơn lại nhỏ hơn nghiêm ngặt điểm quyết định tối ưu lớn nhất của một bài toán nhỏ hơn; tức là có thể tồn tại $i_1 < i_2$ sao cho $\mathop{\mathrm{optmax}}(i_1) > \mathop{\mathrm{optmin}}(i_2)$. Vì vậy khi viết code, cần bảo đảm luôn lấy điểm quyết định tối ưu nhỏ nhất hoặc lớn nhất một cách nhất quán.
    
    Mặt khác, các bài toán có cùng điểm quyết định tối ưu nhỏ nhất tạo thành một khoảng. Khoảng này, nếu xem như hàm của điểm quyết định tối ưu nhỏ nhất, phải tăng nghiêm ngặt. Nói cách khác, cho $j_1 = \operatorname{opt}(i_1)$ và $j_2 = \operatorname{opt}(i_2)$, nếu $j_1 < j_2$ thì tất yếu $i_1 < i_2$. Tương đương, nếu các khoảng bài toán mà quyết định $j_1 < j_2$ có thể trở thành quyết định tối ưu nhỏ nhất lần lượt là $[l_{j_1},r_{j_1}]$ và $[l_{j_2},r_{j_2}]$, thì tất yếu $r_{j_1} < l_{j_2}$.

Cách thường gặp nhất để phán đoán tính đơn điệu quyết định là thông qua bất đẳng thức tứ giác (quadrangle inequality). Trong các ngữ cảnh khác nhau, tính chất này cũng thường được gọi là tính chất Monge (khi mô tả ma trận $A_{j,i}$) hoặc tính dưới môđun (submodularity, khi mô tả một hàm có biến là khoảng $f([j,i])$).

-   **Bất đẳng thức tứ giác**: nếu với mọi $a\leq b\leq c\leq d$ đều có

    $$
    w(a,c)+w(b,d) \leq w(a,d)+w(b,c),
    $$

    thì hàm $w$ được gọi là thỏa mãn bất đẳng thức tứ giác (có thể nhớ ngắn gọn là "chéo nhỏ hơn chứa"). Nếu dấu bằng luôn xảy ra, hàm $w$ được gọi là thỏa mãn **đẳng thức tứ giác**.

Nếu không nói gì thêm, dưới đây luôn giả sử $a\leq b\leq c\leq d$. Bất đẳng thức tứ giác cho một điều kiện đủ nhưng không cần cho tính đơn điệu quyết định.

???+ note "Định lý 1"
    Nếu $w$ thỏa mãn bất đẳng thức tứ giác, thì bài toán (1) thỏa mãn tính đơn điệu quyết định.

??? note "Chứng minh"
    Chứng minh bằng phản chứng. Giả sử với một số $c < d$, có $a = \operatorname{opt}(d) < \operatorname{opt}(c) = b$. Khi đó $a < b \leq c < d$. Theo điều kiện tối ưu, $w(a,d) \leq w(b,d)$ và $w(b,c) < w(a,c)$, do đó $w(a,d) - w(b,d) \leq 0 < w(a,c) - w(b,c)$, mâu thuẫn với bất đẳng thức tứ giác.

Bất đẳng thức tứ giác có thể được hiểu là trong miền xác định hợp lý, sai phân hỗn hợp bậc hai $\Delta_i\Delta_jw(j,i)$ của $w$ không dương.

Nhờ tính đơn điệu quyết định, nhiều thuật toán thường gặp có thể tối ưu độ phức tạp xuống $O(n\log n)$. Phạm vi áp dụng, độ khó cài đặt và hiệu suất thực tế của các thuật toán này khác nhau, nên cần chọn thuật toán phù hợp theo bối cảnh. Điều này chủ yếu phụ thuộc vào tính chất của $w(j,i)$. Nếu không nói rõ, bài viết mặc định $w(i,j)$ có thể **truy cập ngẫu nhiên**, tức là $w(j,i)$ có thể được truy vấn hoặc tính trong $O(1)$. Tuy nhiên, không phải bài toán nào cũng có $w(j,i)$ dễ tính như vậy. Do đó, ngoài trường hợp cơ bản, bài viết còn thảo luận cách dùng tính đơn điệu quyết định để tối ưu DP khi $w(j,i)$ chỉ có các tính chất sau:

-   **Truy cập bằng di chuyển**: $w(j,i)$ có thể được chuyển từ $w(j\pm 1,i)$ hoặc $w(j,i\pm 1)$ trong thời gian $O(1)$. (Tương tự trường hợp trong [thuật toán Mo](../../misc/mo-algo.md))
-   **Tính động**: việc tính $w(j,i)$ phụ thuộc vào $\{f(j'):j' < j\}$. Điều này nghĩa là $f$ và $w$ chỉ có thể được tính tuần tự. Bài toán phân tách khoảng không giới hạn số khoảng được giới thiệu bên dưới thuộc trường hợp này.

Hai tính chất này không loại trừ nhau; có thể tồn tại trường hợp $w(j,i)$ vừa cần tính động, vừa chỉ hỗ trợ truy cập bằng di chuyển.

### Chia để trị

<span id="chia-để-trị"></span>

Để tính mọi trạng thái, chỉ cần tìm mọi điểm quyết định tối ưu. Để tìm $\operatorname{opt}(i)$ cho mọi $1 \leq i \leq n$, trước hết tính $\operatorname{opt}(n/2)$, rồi lần lượt tính $\operatorname{opt}(i)$ trên các đoạn $1 \leq i < n/2$ và $n/2 < i \leq n$. Lúc này, $\operatorname{opt}(i)$ của nửa trước luôn nằm giữa $1$ và $\operatorname{opt}(n/2)$ (kể cả hai đầu), còn $\operatorname{opt}(i)$ của nửa sau luôn nằm giữa $\operatorname{opt}(n/2)$ và $n$ (kể cả hai đầu). Với hai đoạn con, xử lý tương tự cho đến khi tính được quyết định tối ưu của mọi bài toán. Nếu trong quá trình chia để trị ghi lại cận dưới và cận trên của vùng tìm kiếm, có thể bảo đảm độ phức tạp thuật toán là $O(n\log n)$. Cây đệ quy có $O(\log n)$ tầng, và trên mỗi tầng, một điểm quyết định được tính nhiều nhất hai lần, nên tổng số lần tính là $O(n\log n)$.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/dp/code/opt/quadrangle/quadrangle-divide-conquer.cpp:core"
    ```

Ngoài trường hợp cơ bản có truy cập ngẫu nhiên, thuật toán chia để trị cũng có thể áp dụng khi $w(j,i)$ chỉ hỗ trợ truy cập bằng di chuyển. Chỉ cần duy trì con trỏ $(j,i)$ và giá trị hàm tương ứng $w(j,i)$ trong quá trình tính; khi cần truy vấn giá trị mới, di chuyển con trỏ một cách trực tiếp đến vị trí hiện tại và cập nhật giá trị hàm. Cách làm này vẫn có độ phức tạp thời gian $O(n\log n)$. Thảo luận chi tiết hơn về việc này có trong mục [thuật toán LARSCH giản lược](#thuật-toán-larsch-giản-lược) bên dưới. Tuy nhiên, thuật toán chia để trị không giải quyết được trường hợp $w(j,i)$ cần tính động, vì nó không thể tính điểm quyết định tối ưu nhỏ nhất $\operatorname{opt}(n/2)$ ở trung điểm khi các bài toán ở nửa trái vẫn chưa được giải.

### Hàng đợi nhị phân

<span id="hàng-đợi-nhị-phân"></span>

Với mỗi điểm quyết định $j$, các bài toán $i$ mà trong đó $j$ trở thành điểm quyết định tối ưu nhỏ nhất luôn tạo thành một khoảng. Có thể dùng hàng đợi đơn điệu để ghi lại, cho đến hiện tại, khoảng bài toán mà mỗi điểm quyết định có thể giải. Khi đó nghiệm tối ưu của bài toán có thể được tính trực tiếp từ các điểm quyết định ghi trong hàng đợi.

Cụ thể, thuật toán cần duyệt tuần tự các điểm quyết định. Khi duyệt đến điểm quyết định $k$, hàng đợi cần ghi lại **bộ ba** gồm mỗi điểm quyết định khả thi $j$ đã xét đến hiện tại, và hai đầu $l_j$, $r_j$ của khoảng bài toán mà nó có thể giải. Với các bài toán trong khoảng $[l_j,r_j]$, $j$ phải là quyết định tối ưu nhỏ nhất trong số các điểm quyết định đã xét (tức các điểm quyết định trong khoảng $[1,k]$). Ở mọi thời điểm, các quyết định lưu trong hàng đợi không nhất thiết liên tiếp, nhưng các bài toán chưa giải $[j,n]$ phải là hợp rời nhau của các khoảng bài toán lưu trong hàng đợi.

Để chứng minh trong quá trình cập nhật hàng đợi, các bài toán $i$ mà điểm quyết định $j$ là quyết định tối ưu nhỏ nhất luôn tạo thành một đoạn liên tiếp, cần tăng cường kết luận phía trên một chút:

???+ note "Hệ quả 1"
    Gọi $\operatorname{opt}_k(i)$ là quyết định tối ưu nhỏ nhất của bài toán $i$ khi chỉ xét các quyết định trong $[1,k]$. Nếu $w$ thỏa mãn bất đẳng thức tứ giác, thì với mọi $i_1 < i_2$, luôn có $\operatorname{opt}_k(i_1) \leq \operatorname{opt}_k(i_2)$.

??? note "Chứng minh"
    Gọi $M$ là một số thực dương đủ lớn. Hàm $w'(j,i) = w(j,i) + M[j > k]$ vẫn thỏa mãn bất đẳng thức tứ giác, trong đó $[\cdot]$ là ngoặc Iverson. Xét DP phụ có hàm chi phí là $w'$. Trong DP phụ, với mọi bài toán $i$, quyết định $j > k$ không thể là quyết định tối ưu nhỏ nhất, tức $\operatorname{opt}'(i) = \operatorname{opt}'_k(i) = \operatorname{opt}_k(i)$. Áp dụng Định lý 1 cho DP phụ sẽ thu được hệ quả này.

Quy trình của thuật toán như sau:[^cmp-min-opt]

-   Ban đầu, hàng đợi rỗng. Tương tự hàng đợi đơn điệu, mỗi lần xét quyết định kế tiếp $j$, cần thực hiện thao tác ra hàng đợi và vào hàng đợi.
-   **Ra hàng đợi**: trước hết loại bài toán trước đó $j-1$ khỏi hàng đợi. Nếu đầu phải của khoảng bài toán mà quyết định ở đầu hàng đợi có thể giải đúng bằng $j-1$, trực tiếp bật đầu hàng đợi; nếu không, cập nhật đầu trái của khoảng bài toán mà quyết định đầu hàng đợi có thể giải thành $j$.
-   **Vào hàng đợi**: khi đưa quyết định $j$ vào hàng đợi, trước hết so sánh nó với quyết định $j'$ ở cuối hàng đợi.
    -   Nếu với bài toán $l_{j'}$, quyết định sắp vào $j$ tốt hơn nghiêm ngặt quyết định hiện có $j'$, tức $w(j,l_{j'}) < w(j',l_{j'})$, thì bật quyết định $j'$ ở cuối hàng đợi. Thao tác này tiếp tục cho đến khi hàng đợi rỗng hoặc quyết định cuối hàng đợi $j'$ tốt hơn $j$ trên bài toán $l_{j'}$.
    -   Nếu hàng đợi đã rỗng, đưa $(j,j,n)$ vào hàng đợi, tức xem quyết định $j$ là nghiệm tối ưu của mọi bài toán chưa giải.
    -   Nếu quyết định cuối hàng đợi $j'$ trên bài toán $r_{j'}$ cũng không kém quyết định sắp vào $j$, thì khi $r_{j'} < n$, đưa $(j,r_{j'}+1,n)$ vào hàng đợi, biểu thị $j$ là quyết định tối ưu nhỏ nhất của các bài toán $[r_{j'}+1,n]$; nếu không, không cần đưa $j$ vào, vì nó không tốt hơn các quyết định đã có.
    -   Trường hợp cuối cùng là quyết định cuối hàng đợi $j'$ tốt hơn nghiêm ngặt quyết định sắp vào $j$ trên bài toán $l_{j'}$, nhưng kém hơn nghiêm ngặt trên bài toán $r_{j'}$. Điều này cho thấy tồn tại bài toán $i\in(l_{j'},r_{j'}]$ sao cho quyết định tối ưu nhỏ nhất của các bài toán $[l_{j'},i-1]$ là $j'$, còn của các bài toán $[i,r_{j'}]$ là $j$. Vì vậy, cần dùng **tìm kiếm nhị phân** để tìm $i\in[l_{j'},r_{j'}]$ nhỏ nhất sao cho $w(j,i) < w(j',i)$, rồi sửa đầu phải $r_{j'}$ của khoảng cuối hàng đợi thành $i-1$ và đưa $(j,i,n)$ vào hàng đợi.
-   Sau khi xử lý quyết định $j$, mọi quyết định đến $j$ đã được xử lý. Lúc này, quyết định ở đầu hàng đợi chính là quyết định tối ưu nhỏ nhất của bài toán $j$, và có thể ghi lại nghiệm tối ưu tương ứng.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/dp/code/opt/quadrangle/quadrangle-monotone-queue.cpp:core"
    ```

Tương tự hàng đợi đơn điệu, mỗi điểm quyết định được đưa vào hàng đợi nhiều nhất một lần và ra hàng đợi nhiều nhất một lần. Trong đó, thao tác ra hàng đợi là $O(1)$, còn vào hàng đợi là $O(\log n)$ (có thể cần tìm kiếm nhị phân), nên tổng độ phức tạp thời gian là $O(n\log n)$.

Vì thuật toán hàng đợi nhị phân xét tuần tự mọi bài toán và điểm quyết định, nó có thể áp dụng cho trường hợp $w(j,i)$ cần tính động. Đây là ưu thế của nó so với thuật toán chia để trị. Tuy nhiên, vì bước tìm kiếm nhị phân trong thuật toán phụ thuộc vào truy cập ngẫu nhiên tới $w(j,i)$, nó không thể áp dụng khi $w(j,i)$ chỉ hỗ trợ truy cập bằng di chuyển.

???+ example "Ví dụ 1: [「POI2011」Lightning Conductor](https://loj.ac/problem/2157)"
    Cho một dãy độ dài $n$ là $a_1,a_2,\cdots,a_n$. Với mỗi $1 \leq i \leq n$, cần tìm số nguyên không âm nhỏ nhất $f_i$ thỏa mãn
    
    $$
    \forall j\in\left[1,n\right]:a_j \leq a_i + f_i - \sqrt{|i-j|}.
    $$

??? note "Ý tưởng"
    Sau khi biến đổi bất đẳng thức, thu được số nguyên cần tìm $f_i = \max_{j}\{a_j+\sqrt{|i-j|}-a_i\}$. Trước hết xét trường hợp $j \leq i$ (trường hợp còn lại tương tự), khi đó có công thức chuyển trạng thái:
    
    $$
    f_i = -\min_{j\le i}\{-a_j-\sqrt{i-j}+a_i\}.
    $$
    
    Dựa vào tính lồi của $-\sqrt{x}$, có thể suy ra (phần sau sẽ mô tả chi tiết) hàm $w(l, r) = -a_l - \sqrt{r-l} + a_r$ thỏa mãn bất đẳng thức tứ giác, do đó áp dụng thuật toán trên là có thể giải bài này trong thời gian $O(n\log n)$.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/dp/code/opt/quadrangle/quadrangle_1.cpp"
    ```

### Thuật toán LARSCH giản lược

<span id="thuật-toán-larsch-giản-lược"></span>

Hai thuật toán đầu đều không xử lý được trường hợp $w(j,i)$ vừa cần tính động, vừa chỉ hỗ trợ truy cập bằng di chuyển. Mục này giới thiệu một thuật toán có thể đồng thời vượt qua hai khó khăn đó. Nó là phiên bản giản lược của thuật toán LARSCH[^larsch] do Larmore và Schieber đề xuất năm 1991, nên được gọi là **thuật toán LARSCH giản lược**. Phiên bản gốc của thuật toán có thể giải bài toán DP có tính đơn điệu quyết định trong thời gian $O(n)$, nhưng cài đặt phức tạp hơn nên bài viết không giới thiệu.

Vẫn xét cách giải chia để trị. Khi giải các bài toán trong khoảng $(l,r]$, giả sử các thông tin sau đã biết:

-   Quyết định tối ưu nhỏ nhất $\operatorname{opt}(i)$ và giá trị tối ưu của các bài toán $i$ trong khoảng $[1,l]$; và
-   Quyết định tối ưu nhỏ nhất $\operatorname{opt}_l(r)$ và giá trị tối ưu của bài toán $r$ khi chỉ xét các quyết định trong khoảng $[1,l]$.

Khi giải xong các bài toán trong khoảng $(l,r]$, cần thu được quyết định tối ưu nhỏ nhất và giá trị tối ưu của các bài toán trong khoảng $(l,r]$.

Gọi $\textit{mid}$ là trung điểm của khoảng $(l,r]$. Quy trình giải như sau:

1.  Duyệt các quyết định $i\in[\operatorname{opt}(l),\operatorname{opt}_l(r)]$, cập nhật quyết định tối ưu nhỏ nhất và giá trị tối ưu của bài toán $\textit{mid}$.
2.  Đệ quy giải các bài toán trong khoảng $(l,\textit{mid}]$.
3.  Duyệt các quyết định $i\in(l,\textit{mid}]$, cập nhật quyết định tối ưu nhỏ nhất và giá trị tối ưu của bài toán $r$.
4.  Đệ quy giải các bài toán trong khoảng $(\textit{mid},r]$.

Trước khi thực hiện đệ quy cho toàn bộ khoảng $[1,n]$, trước hết cần dùng quyết định $j=1$ để cập nhật các bài toán $i\in\{1,n\}$. Thuật toán dừng khi đệ quy đến $l=r$.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/dp/code/opt/quadrangle/quadrangle-simplified-larsch.cpp:core"
    ```

Trước hết, có thể chứng minh tính đúng đắn của thuật toán này. Để làm vậy, chỉ cần kiểm tra rằng trước mỗi bước giải đệ quy (tức bước 2 và 4), các tiền đề nêu trên đều được thỏa mãn. Từ Hệ quả 1 ở mục trước, có $\operatorname{opt}(l)=\operatorname{opt}_l(l)\le\operatorname{opt}_l(\textit{mid})\le\operatorname{opt}_l(r)$, nên sau bước 1, $\operatorname{opt}_l(\textit{mid})$ đã biết; vì vậy trước khi thực hiện bước 2, tiền đề để đệ quy giải các bài toán trong khoảng $(l,\textit{mid}]$ là đúng. Vì trước đó $\{\operatorname{opt}(i):i\in[1,l]\}$ đã biết, và bước 2 lại thu được giá trị của $\{\operatorname{opt}(i):i\in(l,\textit{mid}]\}$, nên sau bước này $\{\operatorname{opt}(i):i\in[1,\textit{mid}]\}$ đều đã biết; đồng thời, vì trước đó $\operatorname{opt}_l(r)$ đã biết, nên sau bước 3, $\operatorname{opt}_\textit{mid}(r)$ cũng đã biết. Do đó, trước khi thực hiện bước 4, tiền đề để đệ quy giải các bài toán trong khoảng $(\textit{mid},r]$ cũng đúng.

Tiếp theo, cần chứng minh độ phức tạp của thuật toán vẫn là $O(n\log n)$. Cây đệ quy có $O(\log n)$ tầng. Với mỗi nút ở cùng một tầng của cây đệ quy, lần lượt duyệt các quyết định trong các khoảng $[\operatorname{opt}(l),\operatorname{opt}_l(r)]$ và $(l,\textit{mid}]$. Vì $\operatorname{opt}(l)\le\operatorname{opt}_l(r)\le\operatorname{opt}(r)$, nên ở cùng một tầng, mỗi điểm quyết định chỉ được duyệt $O(1)$ lần. Vì vậy tổng số lần duyệt trên mỗi tầng của cây đệ quy là $O(n)$. Giả sử độ phức tạp của một lần truy cập hoặc tính $w(j,i)$ là $O(1)$, độ phức tạp thời gian của thuật toán là $O(n\log n)$.

Với một số trường hợp $w(j,i)$ chỉ hỗ trợ truy cập bằng di chuyển, độ phức tạp của thuật toán này vẫn là $O(n\log n)$. Khi đó, cần lần lượt duy trì con trỏ $(j,i)$ và giá trị hiện tại của $w(j,i)$ cho bước 1 và bước 3 trong quy trình thuật toán. Mỗi khi cần truy cập giá trị mới, cần di chuyển trực tiếp con trỏ $(j,i)$ từ vị trí của lần truy cập trước đến vị trí hiện tại, đồng thời chuyển giá trị hàm $w(j,i)$. Khi duyệt cây đệ quy, tổng số lần cập nhật trực tiếp này là $O(n\log n)$. Vì vậy, độ phức tạp thời gian của thuật toán vẫn là $O(n\log n)$.

??? note "Chứng minh độ phức tạp khi không truy cập ngẫu nhiên"
    Chỉ cần chứng minh tổng số lần di chuyển con trỏ là $O(n\log n)$. Gọi $A$ và $B$ lần lượt là các con trỏ tương ứng với bước 1 và bước 3. Có thể bảo đảm rằng: trước khi giải các bài toán trong khoảng $(l,r]$, con trỏ $A$ ở vị trí $(\operatorname{opt}(l),l)$, con trỏ $B$ ở vị trí $(l,l)$; còn sau khi giải xong, con trỏ $A$ ở vị trí $(\operatorname{opt}(r),r)$, con trỏ $B$ ở vị trí $(r,r)$.
    
    Xét cách dựng quy tắc di chuyển con trỏ như sau. Ở bước 1, có thể cho con trỏ $A$ đi theo đường
    
    $$
    (\operatorname{opt}(l),l)\to(\operatorname{opt}(l),\textit{mid})\to(\operatorname{opt}_l(r),\textit{mid})\to(\operatorname{opt}(l),\textit{mid})\to(\operatorname{opt}(l),l)
    $$
    
    để di chuyển. Lúc này, cả con trỏ $A$ và $B$ đều ở vị trí quy định trước khi giải các bài toán trong khoảng $(l,\textit{mid}]$. Ở bước 2, theo quy định, con trỏ $A$ sẽ di chuyển đến $(\operatorname{opt}(\textit{mid}),\textit{mid})$, con trỏ $B$ sẽ di chuyển đến $(\textit{mid},\textit{mid})$. Ở bước 3, có thể cho con trỏ $B$ đi theo đường
    
    $$
    (\textit{mid},\textit{mid}) \to (l,\textit{mid}) \to (l, r) \to (\textit{mid},r) \to (\textit{mid},\textit{mid})
    $$
    
    để di chuyển. Lúc này, cả con trỏ $A$ và $B$ đều ở vị trí quy định trước khi giải các bài toán trong khoảng $(\textit{mid},r]$. Ở bước 4, theo quy định, con trỏ $A$ sẽ di chuyển đến $(\operatorname{opt}(r),r)$, con trỏ $B$ sẽ di chuyển đến $(r,r)$. Khi kết thúc giải các bài toán trong khoảng $(l,r]$, cả hai con trỏ đều ở vị trí quy định. Do đó, quy tắc di chuyển này phù hợp với yêu cầu trên. Hơn nữa, quy tắc này đủ để hoàn thành mọi phép tính trong bước 1 và 3. Tính trực tiếp số lần di chuyển con trỏ trong quy tắc này, bước 1 cần
    
    $$
    2(\operatorname{opt}_l(r) - \operatorname{opt}(l)) + 2(\textit{mid} - l)
    $$
    
    lần di chuyển, bước 3 cần
    
    $$
    2(\textit{mid}-l)+2(r-\textit{mid}) = 2(r-l)
    $$
    
    lần di chuyển. Lấy tổng số lần di chuyển này trên mọi nút của cây đệ quy, và dùng tính chất rằng mọi $[l,r]$ và $[\operatorname{opt}(l),\operatorname{opt}_l(r)]$ trên cùng một tầng chỉ trùng nhau nhiều nhất ở đầu mút, có thể chứng minh tổng số lần di chuyển là $O(n\log n)$.
    
    Vì quy tắc di chuyển trên đặt thêm nhiều điểm trung gian hơn so với việc di chuyển con trỏ khi tính thực tế, số lần di chuyển thực tế của con trỏ không vượt quá ước lượng theo quy tắc này. Do đó, số lần di chuyển thực tế của con trỏ cũng là $O(n\log n)$.

Vì trước khi giải các bài toán trong khoảng $(l,r]$, thuật toán này đã tính được nghiệm tối ưu $f(i)$ của các bài toán trong khoảng $[1,l]$, nên nó cũng có thể áp dụng cho trường hợp $w(j,i)$ cần tính động.

## Bài toán phân tách khoảng

<span id="bài-toán-phân-tách-khoảng"></span>

Xét bài toán tách một khoảng thành nhiều khoảng con. Nói hình thức, tách khoảng cho trước $[1,n]$ thành $[a_1,b_1],\cdots,[a_k,b_k]$, trong đó $a_1=1$, $b_k=n$, và $b_{i}+1=a_{i+1}$ với mọi $i < k$. Với một cách tách cho trước, chi phí là $\sum_{i=1}^kw(a_i,b_i)$. Bài toán yêu cầu cực tiểu hóa chi phí này. Có thể viết công thức chuyển trạng thái 1D1D như sau.

$$
f(i) = \min_{1\leq j\leq i} f(j-1)+w(j,i) \qquad (1\leq i\leq n)
$$

Trong công thức này, $f(0)=0$. Chỉ cần $w(j,i)$ thỏa mãn bất đẳng thức tứ giác, $f(j-1)+w(j,i)$ cũng thỏa mãn bất đẳng thức tứ giác, vì hạng đầu không chứa hạng giao nhau giữa $j$ và $i$, nên sẽ bị khử trong sai phân hỗn hợp. Tuy nhiên, vì hàm chi phí phụ thuộc vào các bài toán con phía trước, chuyển trạng thái này chỉ có thể được tính tuần tự, nên không thể áp dụng thuật toán chia để trị thứ nhất đã mô tả ở trên; thường chỉ phù hợp với thuật toán hàng đợi nhị phân hoặc thuật toán LARSCH giản lược. Độ phức tạp thuật toán là $O(n\log n)$.

### Trường hợp giới hạn số khoảng

<span id="trường-hợp-giới-hạn-số-khoảng"></span>

Bài toán trên có thể được tăng cường thành trường hợp giới hạn số khoảng, tức đề bài chỉ định tách khoảng thành $m$ khoảng con. Khi đó cần dùng số khoảng sau khi tách làm một chiều của trạng thái chuyển. Tương ứng, có công thức chuyển trạng thái 2D1D như sau.

$$
f(k,i) = \min_{1\leq j\leq i} f(k-1,j-1)+w(j,i) \qquad (1\leq k\leq m,\ 1\leq i\leq n) \tag{2}
$$

Trong đó, $f(0,0)=0$, còn $f(0,i)=f(k,0)=\infty$ với mọi $1\leq k\leq m$ và $1\leq i\leq n$. Tương tự phần trên, $f(k-1,j-1)+w(j,i)$ trong trường hợp này vẫn thỏa mãn bất đẳng thức tứ giác. Lúc này việc tính tầng thứ $k$ không còn phụ thuộc vào kết quả của chính tầng đó, nên với mỗi tầng, có thể dùng bất kỳ thuật toán nào đã mô tả ở mục trước để tính. Khi đó độ phức tạp thuật toán là $O(mn\log n)$.

Với bài toán này, ngoài cách dùng tính đơn điệu quyết định, còn có các thuật toán tối ưu khác. Ý tưởng tối ưu thứ hai dựa vào kết quả sau. Thuật toán tối ưu này rất giống tối ưu Knuth được mô tả chi tiết phía dưới.

???+ note "Định lý 2"
    Nếu $w$ thỏa mãn bất đẳng thức tứ giác, thì với bài toán (2) có $\operatorname{opt}(k-1,i) \leq \operatorname{opt}(k,i) \leq \operatorname{opt}(k,i+1)$.

??? note "Chứng minh"
    Bất đẳng thức thứ hai chỉ là tính đơn điệu quyết định của tầng $k$. Điểm mấu chốt nằm ở bất đẳng thức thứ nhất.
    
    Chứng minh $\operatorname{opt}(k,i) \leq \operatorname{opt}(k+1,i)$. Giả sử có hai phân hoạch của khoảng $[1,i]$ như sau (đánh số ngược): $[a_{k},d_{k}],\cdots,[a_1,d_1]$ và $[b_{k+1},c_{k+1}],\cdots,[b_1,c_1]$. Trong đó, đầu trái của mỗi khoảng đều là quyết định tối ưu nhỏ nhất của bài toán tương ứng tại đầu phải của nó; tương tự, nếu xét mọi phân hoạch có thể từ phải sang trái, đầu phải cũng là quyết định tối ưu nhỏ nhất của bài toán tương ứng tại đầu trái. Ví dụ, $d_j$ và $c_j$ lần lượt là quyết định tối ưu nhỏ nhất của đầu phải khoảng đầu tiên từ trái sang khi chia $[a_j,i]$ và $[b_j,i]$ thành $j$ đoạn. Theo tính đơn điệu quyết định, nếu $a_{j-1} > b_{j-1}$, tức $d_j > c_j$, thì tất yếu $a_j > b_j$. Do đó, nếu mệnh đề cần chứng minh không đúng, có $a_1 > b_1$. Từ đây có thể quy nạp chứng minh $a_{k} > b_{k}$. Điều này mâu thuẫn với giả thiết, nên được chứng minh.
    
    Bất đẳng thức thứ nhất cũng có thể chứng minh theo cách khác như sau. Vẫn xét hai phân hoạch trong chứng minh trên. Nếu mệnh đề cần chứng minh không đúng, có $a_1 > b_1$, nhưng vì $a_{k} < b_{k}$, có thể tìm $j>1$ nhỏ nhất sao cho $a_j \leq b_j$. Khi đó $a_{j-1} > b_{j-1}$, nên $d_j>c_j$. Tìm được một nhóm khoảng thỏa mãn $a_j \leq b_j \leq c_j < d_j$. Xét kết quả ghép lại hai cách tách này. Xét cách tách $[b_{k+1},c_{k+1}],\cdots,[b_{j+1},c_{j+1}],[b_j,d_j],[a_{j-1},d_{j-1}],\cdots,[a_1,d_1]$, gồm $(k+1)$ đoạn; từ tính tối ưu giả thiết có
    
    $$
    \begin{aligned}
    &w(b_{k+1},c_{k+1})+\cdots+w(b_{j+1},c_{j+1})+w(b_j,c_j)+w(b_{j-1},c_{j-1})+\cdots+w(b_1,c_1) \\
    &\qquad \leq w(b_{k+1},c_{k+1})+\cdots+w(b_{j+1},c_{j+1})+w(b_j,d_j)+w(a_{j-1},d_{j-1})+\cdots+w(a_1,d_1).
    \end{aligned}
    $$
    
    Tương tự, xét cách tách $[a_{k},d_{k}],\cdots,[a_{j+1},d_{j+1}],[a_j,c_j],[b_{j-1},c_{j-1}],\cdots,[b_1,c_1]$, gồm $k$ đoạn, có
    
    $$
    \begin{aligned}
    &w(a_{k},d_{k})+\cdots+w(a_{j+1},d_{j+1})+w(a_j,d_j)+w(a_{j-1},d_{j-1})+\cdots+w(a_1,d_1) \\
    &\qquad < w(a_{k},d_{k})+\cdots+w(a_{j+1},d_{j+1})+w(a_j,c_j)+w(b_{j-1},c_{j-1})+\cdots+w(b_1,c_1).
    \end{aligned}
    $$
    
    Dấu bất đẳng thức trong dòng trên là nghiêm ngặt, vì $a_1 > b_1$, nhưng theo giả thiết, $a_1$ là đầu trái tối ưu nhỏ nhất của đoạn cuối trong mọi cách tách thành $k$ đoạn. Cộng hai bất đẳng thức lại, thu được $w(b_j,c_j) + w(a_j,d_j) < w(b_j,d_j) + w(a_j,c_j)$, mâu thuẫn với bất đẳng thức tứ giác. Vậy kết luận ban đầu được chứng minh.

Nhờ kết quả này, có thể giới hạn phạm vi tìm kiếm của quyết định $j$. Khi cài đặt thuật toán, duyệt $k$ theo chiều tăng và duyệt $i$ theo chiều giảm; trong phạm vi cận trên và cận dưới đã biết trước đó, tìm kiếm vét cạn $j$ là đủ để bảo đảm độ phức tạp thuật toán $O(n(n+m))$.

??? warning "Lưu ý"
    Độ phức tạp thuật toán trong phần này không phải $O(nm)$. Cách tính độ phức tạp đúng cần xét ma trận trạng thái $n\times m$. Vì với bài toán $(i,k)$, chỉ cần xét các quyết định trong $\operatorname{opt}(k-1,i) \leq j \leq \operatorname{opt}(k,i+1)$, nên trên mỗi đường chéo phụ (tức $i-k$ là hằng số), tổng số quyết định cần duyệt là $O(n)$. Có tổng cộng $(n+m)$ đường chéo như vậy, nên tổng độ phức tạp thời gian là $O(n(n+m))$.

Phương pháp tối ưu cuối cùng đến từ quan sát sau.

???+ note "Định lý 3"
    Nếu $w$ thỏa mãn bất đẳng thức tứ giác, thì nghiệm tối ưu $g(k):=f(n,k)$ của bài toán (2) là một hàm lồi theo $k$.

??? note "Chứng minh"
    Chứng minh $g(k-1) + g(k+1) \ge 2g(k)$. Để làm vậy, xét phân hoạch tối ưu có độ dài $(k-1)$ đoạn và $(k+1)$ đoạn, lần lượt là $[a_1,d_1],\cdots,[a_{k-1},d_{k-1}]$ và $[b_1,c_1],\cdots,[b_{k+1},c_{k+1}]$. Lấy $1 \leq j \leq k-1$ nhỏ nhất sao cho $c_{j+1} \leq d_j$; sự tồn tại của nó suy ra từ $c_{k} < n = d_{k-1}$. Theo tính nhỏ nhất này, có $b_{j+1} > a_j$. Vì vậy $a_j < b_{j+1} \leq c_{j+1} \leq d_j$. Tương tự phần trên, hoán đổi nửa sau của hai cách tách hiện có sẽ thu được hai cách tách khoảng sau:
    
    $$
    \begin{aligned}
    & [a_1,d_1],\cdots,[a_{j-1},d_{j-1}],[a_j,c_{j+1}],[b_{j+2},c_{j+2}],\cdots,[b_{k+1},c_{k+1}], \\
    & [b_1,c_1],\cdots,[b_j,c_j],[b_{j+1},d_j],[a_{j+1},d_{j+1}],\cdots,[a_{k-1},d_{k-1}].
    \end{aligned}
    $$
    
    Hai khoảng thu được đều gồm $k$ đoạn, nên từ điều kiện tối ưu có
    
    $$
    \begin{aligned}
    2g(k) &\le w(a_1,d_1) + \cdots + w(a_{j-1},d_{j-1}) + w(a_j,c_{j+1}) + w(b_{j+2},c_{j+2}) + \cdots + w(b_{k+1},c_{k+1}) \\
    &\quad + w(b_1,c_1) + \cdots + w(b_j,c_j) + w(b_{j+1},d_j) + w(a_{j+1},d_{j+1}) + \cdots + w(a_{k-1},d_{k-1}) \\
    &\le w(a_1,d_1) + \cdots + w(a_{j-1},d_{j-1}) + w(a_j,d_j) + w(a_{j+1},d_{j+1}) + \cdots + w(a_{k-1},d_{k-1}) \\
    &\quad + w(b_1,c_1) + \cdots + w(b_j,c_j) + w(b_{j+1},c_{j+1}) + w(b_{j+2},c_{j+2}) + \cdots + w(b_{k+1},c_{k+1}) \\
    &= g(k-1) + g(k+1).
    \end{aligned}
    $$
    
    Bất đẳng thức thứ hai trong biến đổi trên chính là bất đẳng thức tứ giác. Từ đó suy ra tính lồi cần chứng minh.

Kết luận này bảo đảm có thể dùng tìm kiếm nhị phân WQS (ở nước ngoài gọi là Aliens Trick) để giải bài toán này. Cụ thể, xét hàm chi phí có tham số $w_c(j,i):=w(j,i)+c$, giải bài toán không giới hạn số khoảng và thu được nghiệm tối ưu $f_c(n)$. Khi số thực $c$ tăng, số khoảng tối ưu tương ứng giảm đơn điệu, nên có thể dùng tìm kiếm nhị phân để tìm tham số $c$ làm cho số khoảng tối ưu đúng bằng $m$. Khi đó nghiệm tối ưu của bài gốc là $f(n,m) = f_c(n)-cm$. Số thực $c$ trong ngữ cảnh này có thể xem như nhân tử Lagrange của ràng buộc số khoảng. Cài đặt thuật toán này có nhiều chi tiết; có thể tham khảo trang [tìm kiếm nhị phân WQS](./wqs-binary-search.md). Độ phức tạp thời gian của thuật toán là $O(n\log n\log C)$, trong đó $C$ là một hằng số nào đó.

Với ba thuật toán cho bài toán phân tách khoảng có giới hạn số khoảng, hiệu quả của chúng khác nhau theo từng phạm vi dữ liệu; cần chọn thuật toán phù hợp theo bài cụ thể.

???+ example "Ví dụ 3: [P4767 \[IOI2000\] Bưu điện bản tăng cường](https://www.luogu.com.cn/problem/P4767)  [P6246 \[IOI2000\] Bưu điện bản tăng cường hơn](https://www.luogu.com.cn/problem/P6246)"
    Có một số ngôi làng bên cạnh đường cao tốc. Đường cao tốc được biểu diễn bằng trục số nguyên, và vị trí của mỗi làng được đánh dấu bằng một tọa độ nguyên đơn. Không có hai làng ở cùng một vị trí. Khoảng cách giữa hai vị trí là trị tuyệt đối hiệu hai tọa độ nguyên của chúng.
    
    Bưu cục sẽ được xây tại một số, nhưng không nhất thiết là tất cả, các làng. Để xây bưu cục, cần chọn vị trí xây sao cho tổng khoảng cách từ mỗi làng đến bưu cục gần nhất là nhỏ nhất.
    
    Viết chương trình: biết vị trí các làng và số lượng bưu cục, tính tổng khoảng cách nhỏ nhất có thể từ mọi làng đến bưu cục gần nhất.

??? note "Ý tưởng"
    Mỗi làng có bưu cục gần nhất của nó, vậy mỗi bưu cục cũng có các làng do nó phụ trách; đó là một khoảng.
    
    Xét việc chia $n$ làng này thành $m$ khoảng, rồi trong mỗi khoảng chọn ra một bưu cục.
    
    Theo kiến thức toán học, với khoảng $[i,j]$, bưu cục nên được xây tại làng thứ $\left\lfloor\dfrac{i+j}2\right\rfloor$. Dùng tổng tiền tố có thể tính $w(i,j)$ một cách trực tiếp.
    
    Bài toán được chuyển thành bài toán phân tách khoảng có giới hạn số khoảng. Có thể chứng minh hàm $w$ thỏa mãn bất đẳng thức tứ giác. Do đó, có thể áp dụng trực tiếp phương pháp tối ưu trên.

??? note "Cài đặt 1, phương pháp tối ưu thứ hai ở trên, độ phức tạp $O(n(n+m))$"
    ```cpp
    --8<-- "docs/dp/code/opt/quadrangle/quadrangle_2.cpp"
    ```

??? note "Cài đặt 2, tìm kiếm nhị phân WQS, độ phức tạp $O(n\log n\log C)$"
    ```cpp
    --8<-- "docs/dp/code/opt/quadrangle/quadrangle_3.cpp"
    ```

## Bài toán gộp khoảng

<span id="bài-toán-gộp-khoảng"></span>

Một loại bài toán quy hoạch động khác có thể tối ưu bằng bất đẳng thức tứ giác là bài toán gộp khoảng: cần gộp đôi một $n$ khoảng độ dài một $[i,i]$ cho đến khi thu được khoảng $[1,n]$. Mỗi lần gộp $[j,k]$ và $[k+1,i]$ cần trả chi phí $w(j,i)$. Bài toán yêu cầu tìm cách gộp có chi phí thấp nhất. Với loại bài toán này, có công thức chuyển trạng thái 2D1D sau:

$$
f(j,i) = \min_{j \leq k < i} f(j,k) + f(k+1,i) + w(j,i) \qquad (1\le j< i\le n) \tag{3}
$$

Trong đó chi phí ban đầu $f(i,i)=0$. Thuật toán vét cạn có tổng độ phức tạp $O(n^3)$; khi có tính đơn điệu quyết định, có thể tối ưu xuống $O(n^2)$. Thuật toán này được Knuth đề xuất đầu tiên khi giải bài toán cây tìm kiếm nhị phân tối ưu, rồi được Yao Chi-Feng nghiên cứu và tổng kết thêm; ở nước ngoài thường gọi là tối ưu Knuth hoặc tăng tốc Knuth-Yao.

Ngoài bất đẳng thức tứ giác, tính đơn điệu quyết định của bài toán gộp khoảng còn yêu cầu hàm chi phí thỏa mãn tính đơn điệu theo bao hàm khoảng.

-   **Tính đơn điệu theo bao hàm khoảng**: nếu với mọi $a \leq b \leq c \leq d$ đều có

    $$
    w(b,c) \leq w(a,d),
    $$

    thì hàm $w$ được gọi là có tính đơn điệu theo quan hệ bao hàm khoảng.

Về bản chất, đây là điều kiện bậc nhất của hàm chi phí, tức $w(j,i)$ giảm theo $j$ và tăng theo $i$.

???+ note "Bổ đề 1"
    Nếu $w$ thỏa mãn tính đơn điệu theo bao hàm khoảng và bất đẳng thức tứ giác, thì trạng thái $f(j,i)$ thỏa mãn bất đẳng thức tứ giác.

??? note "Chứng minh"
    Không mất tính tổng quát, giả sử $a \leq b \leq c \leq d$. Chứng minh $f(a,d) + f(b,c) \geq f(a,c) + f(b,d)$. Xét quy nạp theo $d-a$. Khi $a=b$ hoặc $c=d$, điều cần chứng minh là một đẳng thức. Với trường hợp tổng quát, phân loại theo vị trí của $d'=\operatorname{opt}(a,d)$.
    
    Trường hợp thứ nhất: $c \leq d'$ hoặc $d' < b$, tức $[b,c]$ nằm trong $[a,d']$ hoặc trong $[d'+1,d]$.
    
    Giả sử $c \leq d'$, trường hợp còn lại tương tự. Khi đó có
    
    $$
    \begin{aligned}
    f(a,d) + f(b,c)
    & = f(a,d') + f(d'+1,d) + w(a,d) + f(b,c) \\
    & \geq f(a,c) + f(b,d') + f(d'+1,d) + w(a,d) \\
    & \geq f(a,c) + f(b,d') + f(d'+1,d) + w(b,d) \\
    & \geq f(a,c) + f(b,d).
    \end{aligned}
    $$
    
    Trong biến đổi trên, bất đẳng thức thứ nhất đến từ giả thiết quy nạp $f(a,c) + f(b,d') \leq f(a,d') + f(b,c)$, bất đẳng thức thứ hai đến từ tính đơn điệu theo bao hàm khoảng $w(b,d) \leq w(a,d)$, và bất đẳng thức thứ ba đến từ điều kiện tối ưu $f(b,d) \leq f(b,d') + f(d'+1,d) + w(b,d)$.
    
    Trường hợp thứ hai: $b \leq d' < c$, tức $d'$ nằm trong $[b,c]$. Khi đó xét vị trí của $c'=\operatorname{opt}(b,c)$.
    
    Giả sử $c' \leq d'$, tức $[b,c']$ nằm trong $[a,d']$; trường hợp còn lại tương tự. Khi đó có
    
    $$
    \begin{aligned}
    f(a,d) + f(b,c)
    & = f(a,d') + f(d'+1,d) + w(a,d) + f(b,c') + f(c'+1,c) + w(b,c) \\
    & \geq f(a,c') + f(c'+1,c) + w(b,c) + f(b,d') + f(d'+1,d) + w(a,d) \\
    & \geq f(a,c') + f(c'+1,c) + w(a,c) + f(b,d') + f(d'+1,d) + w(b,d) \\
    & \geq f(a,c) + f(b,d).
    \end{aligned}
    $$
    
    Trong biến đổi trên, bất đẳng thức thứ nhất đến từ giả thiết quy nạp $f(a,c') + f(b,d') \leq f(a,d') + f(b,c')$, bất đẳng thức thứ hai đến từ bất đẳng thức tứ giác $w(a,c) + w(b,d) \leq w(a,d) + w(b,c)$, và bất đẳng thức thứ ba đến từ điều kiện tối ưu của $f(a,c)$ và $f(b,d)$.

???+ note "Định lý 4"
    Nếu $w$ thỏa mãn tính đơn điệu theo bao hàm khoảng và bất đẳng thức tứ giác, thì quyết định tối ưu nhỏ nhất $\operatorname{opt}(j,i)$ trong bài toán (3) thỏa mãn
    
    $$
    \operatorname{opt}(j,i-1) \leq \operatorname{opt}(j,i) \leq \operatorname{opt}(j+1,i). \qquad (j + 1 < i)
    $$

??? note "Chứng minh"
    Bổ đề 1 đã chứng minh $f(j,i)$ thỏa mãn bất đẳng thức tứ giác, nên hàm mục tiêu $f(j,k) + f(k+1,i) + w(j,i)$, với $j$ cố định và xem như hàm theo $(k,i)$, cũng thỏa mãn bất đẳng thức tứ giác. Vì vậy theo Định lý 1 có $\operatorname{opt}(j,i-1) \leq \operatorname{opt}(j,i)$. Lưu ý rằng các hạng không đồng thời chứa $(k,i)$ không ảnh hưởng đến việc bất đẳng thức tứ giác có đúng hay không. Tương tự, với $i$ cố định và xem như hàm theo $(k,j)$, nó cũng thỏa mãn bất đẳng thức tứ giác, nên $\operatorname{opt}(j,i) \leq \operatorname{opt}(j+1,i)$. Từ đó suy ra điều cần chứng minh.

Nhờ kết luận này, cũng có thể giới hạn phạm vi tìm kiếm của điểm quyết định $k$. Trong phần này, duyệt độ dài khoảng $i-j+1$ theo thứ tự tăng, rồi duyệt mọi khoảng $[j,i]$ có cùng độ dài; tìm kiếm vét cạn mọi $k$ giữa $\operatorname{opt}(j,i-1)$ và $\operatorname{opt}(j+1,i)$ để thu được nghiệm tối ưu $f(j,i)$, đồng thời ghi lại quyết định tối ưu nhỏ nhất $\operatorname{opt}(j,i)$. Với mọi khoảng cùng độ dài, tổng độ dài không gian quyết định trong thuật toán này là $O(n)$, và số độ dài khoảng có thể có cũng là $O(n)$, nên tổng độ phức tạp thuật toán là $O(n^2)$.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/dp/code/opt/quadrangle/quadrangle-knuth-optimization.cpp:core"
    ```

## Các lớp hàm thỏa mãn bất đẳng thức tứ giác

<span id="các-lớp-hàm-thỏa-mãn-bất-đẳng-thức-tứ-giác"></span>

Để chứng minh một hàm thỏa mãn bất đẳng thức tứ giác thuận tiện hơn, có các tính chất sau:

**Tính chất 1**: Nếu các hàm $w_1(j,i)$ và $w_2(j,i)$ đều thỏa mãn bất đẳng thức tứ giác (hoặc tính đơn điệu theo bao hàm khoảng), thì với mọi $c_1,c_2\geq 0$, hàm $c_1w_1+c_2w_2$ cũng thỏa mãn bất đẳng thức tứ giác (hoặc tính đơn điệu theo bao hàm khoảng).

**Tính chất 2**: Nếu tồn tại các hàm $f(x)$ và $g(x)$ sao cho $w(j,i) = f(j)-g(i)$, thì hàm $w$ thỏa mãn đẳng thức tứ giác. Khi các hàm $f$ và $g$ tăng đơn điệu, hàm $w$ còn thỏa mãn tính đơn điệu theo bao hàm khoảng.

**Tính chất 3**: Giả sử $h(x)$ là một hàm lồi tăng đơn điệu. Nếu hàm $w(j,i)$ thỏa mãn bất đẳng thức tứ giác và có tính đơn điệu theo bao hàm khoảng, thì hàm hợp $h(w(j,i))$ cũng thỏa mãn bất đẳng thức tứ giác và tính đơn điệu theo bao hàm khoảng.

**Tính chất 4**: Giả sử $h(x)$ là một hàm lồi. Nếu hàm $w(j,i)$ thỏa mãn đẳng thức tứ giác và có tính đơn điệu theo bao hàm khoảng, thì hàm hợp $h(w(j,i))$ cũng thỏa mãn bất đẳng thức tứ giác.

Trước hết cần làm rõ một điểm: định nghĩa hàm lồi (Convex Function) trong các giáo trình Trung Quốc có sự khác biệt. Trong bài này, hàm lồi chỉ hàm lồi xuống theo cách gọi tại đó, tức hàm có đạo hàm bậc nhất tăng đơn điệu (khi khả vi).

??? note "Chứng minh"
    Hai tính chất đầu suy ra trực tiếp từ định nghĩa. Dưới đây chứng minh tính chất thứ ba; quá trình chứng minh tính chất thứ tư tương tự. Vì $h(x)$ đơn điệu, $h(w(j,i))$ giữ được tính đơn điệu theo bao hàm khoảng. Điểm mấu chốt là chứng minh bất đẳng thức tứ giác.
    
    Để làm vậy, xét sai phân hỗn hợp bậc hai trên $a \leq j \leq b \leq c \leq i \leq d$.
    
    $$
    \begin{aligned}
    \Delta_i\Delta_j h\left(w(j,i)\right)
    &= h\left(w(b,d)\right) - h\left(w(a,c) + \Delta_jw(j,c) + \Delta_iw(a,i)\right) \\
    &\quad + h\left(w(a,c) + \Delta_jw(j,c) + \Delta_iw(a,i)\right) - h\left(w(a,c) + \Delta_jw(j,c)\right) \\
    &\quad - h\left(w(a,c) + \Delta_iw(a,i)\right) + h\left(w(a,c)\right).
    \end{aligned}
    $$
    
    Theo tính đơn điệu theo bao hàm khoảng, $\Delta_iw(a,i) := w(a,d) - w(a,c) \geq 0$ và $\Delta_jw(j,c) := w(b,c) - w(a,c) \leq 0$. Vì $h(x)$ có tính lồi, với $t_1,t_2\geq 0$ có $h(x + t_1 - t_2) - h(x + t_1) \leq h(x - t_2) - h(x)$, nên hai dòng sau đều không dương. Đồng thời, do bất đẳng thức tứ giác, $w(b,d) \leq w(a,c) + \Delta_jw(j,c) + \Delta_iw(a,i) = w(b,c) + w(a,d) - w(a,c)$; vì vậy hiệu ở dòng đầu tiên cũng không dương khi $h(x)$ tăng đơn điệu. Do đó, tổng sai phân hỗn hợp bậc hai không dương. Đây chính là bất đẳng thức tứ giác.

    Chứng minh này là phiên bản rời rạc của chứng minh bằng đạo hàm sau.
    
    $$
    \frac{\partial^2}{\partial x\partial y}h(w(x,y)) = h''(w(x,y))\frac{\partial }{\partial x}w(x,y)\frac{\partial}{\partial y}w(x,y) + h'(w(x,y))\frac{\partial^2}{\partial x\partial y}w(x,y) \leq 0.
    $$
    
    Điều này đúng trực tiếp dưới các điều kiện $h' \geq 0$, $h'' \geq 0$, $w_x \leq 0$, $w_y \geq 0$ và $w_{xy} \leq 0$. Trong đó, tính đơn điệu theo bao hàm khoảng cho điều kiện bậc nhất của $w$, còn bất đẳng thức tứ giác cho điều kiện bậc hai.

## Bài tập

<span id="bài-tập"></span>

-   [Codeforces - Ciel và những chiếc thuyền gondola](https://codeforces.com/contest/321/problem/E) (Cẩn thận với nhập/xuất!)
-   [SPOJ - LARMY](https://www.spoj.com/problems/LARMY/)
-   [CodeChef - CHEFAOR](https://www.codechef.com/problems/CHEFAOR)
-   [Hackerrank - Những người canh giữ kẻ điên](https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14)
-   [Vòng chung kết thế giới ACM-ICPC 2017 - Tiền](https://open.kattis.com/problems/money)

## Tài liệu tham khảo và chú thích

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>

-   [Câu trả lời Quora của Michael Levin](https://www.quora.com/What-is-divide-and-conquer-optimization-in-dynamic-programming)
-   [Video hướng dẫn của "Sothe" the Algorithm Wolf](https://www.youtube.com/watch?v=wLXEWuDWnzI)
-   [DP chia để trị](https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html)
-   [Tối ưu Knuth](https://cp-algorithms.com/dynamic_programming/knuth-optimization.html)
-   [Các tính chất của bất đẳng thức tứ giác](https://codeforces.com/blog/entry/86306)
-   [Wang Qinshi, Phân tích sơ lược một lớp phương pháp nhị phân](https://github.com/hzwer/shareOI/blob/master/%E5%9F%BA%E7%A1%80%E7%AE%97%E6%B3%95/%E6%B5%85%E6%9E%90%E4%B8%80%E7%B1%BB%E4%BA%8C%E5%88%86%E6%96%B9%E6%B3%95_%E7%8E%8B%E9%92%A6%E7%9F%B3.pdf)
-   [Thuật toán LARSCH giản lược của noshi91](https://noshi91.hatenablog.com/entry/2023/02/18/005856)
-   [Bất đẳng thức tứ giác và tính đơn điệu quyết định của b6e0\_ - Luogu Column](https://www.luogu.com.cn/article/h81hh5lk)
-   [Thuật toán LARSCH giản lược cho tính đơn điệu quyết định trực tuyến của Register\_int - Luogu Column](https://www.luogu.com.cn/article/vqf42hah)

[^cmp-min-opt]: Các cụm "kém hơn" và "tốt hơn" trong mô tả thuật toán đều nên được hiểu là đang mô tả thứ tự từ điển: trước hết so sánh giá trị hàm, rồi so sánh điểm quyết định. Trong thứ tự từ điển này, "tốt hơn" nghĩa là hoặc giá trị hàm nhỏ hơn, hoặc giá trị hàm bằng nhau nhưng điểm quyết định nhỏ hơn.

[^larsch]: Larmore, Lawrence L., and Baruch Schieber. "On-line dynamic programming with applications to the prediction of RNA secondary structure." Journal of Algorithms 12, no. 3 (1991): 490-515.
