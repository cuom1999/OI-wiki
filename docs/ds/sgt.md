author: Ir1d, 0xis-cn

## Dẫn nhập

**Cây scapegoat** là một loại cây cân bằng theo trọng số,
duy trì cân bằng bằng các thao tác xây lại.
Sau mỗi thao tác chèn hoặc xóa,
cây scapegoat kiểm tra xem cây có bị mất cân bằng hay không;
nếu có, nó sẽ xây lại phần thích hợp để khôi phục cân bằng.

Nhìn chung, cây scapegoat không hỗ trợ thao tác trên đoạn
và cũng không thể bền vững hóa hoàn toàn.
Bù lại, nó có ưu điểm là cài đặt đơn giản và hằng số nhỏ.

## Cấu trúc và thao tác cơ bản

Các thao tác cốt lõi của cây scapegoat là xây lại, chèn và xóa.

### Thông tin nút

Cây scapegoat cần lưu các thông tin sau để phục vụ thao tác tự cân bằng của cây:

-   Thông tin cấu trúc của cây:
    -   `id`: số lượng nút đã dùng;
    -   `rt`: nút gốc;
    -   `lc[x]`, `rc[x]`: nút con trái và nút con phải;
    -   `tot[x]`: kích thước cây con gốc $x$ (mỗi nút được tính là $1$)[^tot-cnt];
    -   `tot_active`: số nút chưa bị xóa (tức là `cnt[x] != 0`) trong toàn bộ cây.

Khi dùng cây scapegoat để cài đặt cây cân bằng,
còn cần lưu các thông tin sau:

-   Thông tin nút của cây cân bằng:
    -   `val[x]`: giá trị được lưu trong nút;
    -   `cnt[x]`: số lần xuất hiện của giá trị được lưu trong nút (có thể bằng $0$);
    -   `sz[x]`: tổng số giá trị được lưu trong cây con gốc $x$.

Để duy trì thông tin nút, có thể cài đặt thao tác `push_up`:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/sgt/sgt.cpp:push-up"
    ```

Cần phân biệt cách cập nhật `tot[x]` và `sz[x]`.

### Thao tác xây lại

Khi cây bị mất cân bằng, cần xây lại một cây con nào đó sao cho nó cân bằng nhất có thể. Việc xây lại gồm hai bước:

-   Duyệt inorder cây con cần xây lại, đưa tất cả nút chưa bị xóa vào một dãy;
-   Xây cây bằng cách chia đôi, tức là lấy phần tử giữa làm gốc, đệ quy xây cây con ở hai phía trái và phải, rồi cập nhật thông tin nút.

Cài đặt tham khảo như sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/sgt/sgt.cpp:rebuild"
    ```

Khi xây cây, cần duy trì đầy đủ thông tin nút, bao gồm cả thông tin của nút lá.

Độ phức tạp của một lần xây lại là $\Theta(|T_x|)$.
Vì vậy, nếu lần nào chèn hoặc xóa cũng xây lại,
độ phức tạp sẽ khó chấp nhận.
Ý tưởng cốt lõi của cây scapegoat nằm ở việc chọn thời điểm xây lại,
nhờ đó đạt được độ phức tạp khấu hao $O(\log n)$.

### Thao tác chèn

Thao tác chèn có thể làm cây mất cân bằng.
Để xác định mất cân bằng, cần đưa vào tham số $\alpha\in(0.5,1)$,
thường chọn trong khoảng $0.7\sim 0.8$.
Tham số này còn được gọi là hệ số cân bằng alpha.

Nếu độ sâu của nút mới chèn vượt quá $\lfloor\log_{1/\alpha}|T|\rfloor$,
trong đó $|T|$ là kích thước cây sau khi cập nhật,
thì khi quay lui cần tìm nút xảy ra mất cân bằng và xây lại.
Khi đó, dùng điều kiện sau để xác định cây con gốc $x$ bị mất cân bằng:

$$
\max\{|T_{\mathrm{left}(x)}|,|T_{\mathrm{right}(x)}|\} > \alpha\cdot |T_x|,
$$

trong đó $\mathrm{left}(x)$ và $\mathrm{right}(x)$ lần lượt là nút con trái
và nút con phải của $x$, còn $|T_x|$ là kích thước cây con gốc $x$.

Các bước cụ thể của thao tác chèn như sau:

-   Trước hết dùng tính chất của cây tìm kiếm nhị phân để đi xuống tìm vị trí của giá trị cần chèn,
    đồng thời ghi lại độ sâu trong quá trình đi xuống;
-   Nếu đã có nút tương ứng, chỉ cần sửa thông tin nút; nếu chưa thì tạo nút mới;
-   Nếu nút mới quá sâu, cần quay lui từ dưới lên tới gốc,
    cập nhật thông tin nút và ghi lại nút đầu tiên
    hoặc một nút bất kỳ có cây con mất cân bằng;
-   Nếu tồn tại nút mất cân bằng, xây lại cây con của nút đó.

Cài đặt tham khảo như sau:

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/sgt/sgt.cpp:insert"
    ```

Lưu ý rằng một lần chèn nhiều nhất chỉ gây ra một lần xây lại.
Nếu không thêm nút mới, hoặc nút mới không quá sâu,
hoặc trong quá trình quay lui lần này đã thực hiện xây lại rồi,
thì không cần tiếp tục kiểm tra mất cân bằng.
Các lần xây lại dư thừa có thể làm giảm hiệu suất[^insert-complexity].
Nút mất cân bằng đầu tiên trong quá trình quay lui chính là "scapegoat".

### Thao tác xóa

Cách xử lý thao tác xóa rất đơn giản.
Chiến lược xóa của cây scapegoat là "xóa lười":
khi một nút trở thành rỗng, không loại bỏ nút đó ngay mà để xử lý sau.

Nếu trong cây có quá nhiều nút rỗng,
hiệu suất truy cập sẽ giảm mạnh.
Vì vậy, cây scapegoat duy trì hai bộ đếm:
số nút chưa bị xóa trong toàn bộ cây
và số nút thực tế đã dùng trong toàn bộ cây.
Với một ngưỡng đã chọn[^threshold] $\alpha\in(0,1)$,
khi tỉ lệ giữa bộ đếm thứ nhất và bộ đếm thứ hai giảm xuống dưới $\alpha$,
xây lại toàn bộ cây một lần.
Trong quá trình xây lại, tất cả nút rỗng sẽ bị loại bỏ.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/sgt/sgt.cpp:remove"
    ```

### Độ phức tạp thời gian

Với cây scapegoat có kích thước $n$,
độ phức tạp thời gian của một lần truy cập nút là $O(\log n)$.
Độ phức tạp thời gian khấu hao của mỗi thao tác
trong $\Theta(n)$ lần chèn và xóa cũng là $O(\log n)$.

Phần này chỉ trình bày lập luận ngắn gọn về độ phức tạp thời gian của cây scapegoat.
Chứng minh chi tiết có thể xem trong bài báo gốc.

??? note "Lập luận về độ phức tạp thời gian của cây scapegoat"
    Do dùng chiến lược xóa lười,
    một cây scapegoat có $n$ nút chưa bị xóa có thể chiếm tới $\alpha^{-1}n$ nút.
    Vì chỉ khác nhau một hằng số,
    phần trình bày này không phân biệt số nút chưa bị xóa
    và số nút bị chiếm dụng của cây scapegoat,
    mà gọi chung là "kích thước cây".

    1.  **Thao tác truy cập**: Độ phức tạp của thao tác truy cập được bảo đảm
        vì chiều cao của cây scapegoat kích thước $n$ luôn là $O(\log n)$.

        Trước hết, phân biệt hai khái niệm:

        -   Cân bằng trọng số $\alpha$: tại mọi nút,
            kích thước cây con của nút con trái và nút con phải
            đều không vượt quá $\alpha$ lần kích thước cây con tại nút đó;
        -   Cân bằng chiều cao $\alpha$: chiều cao của cây không vượt quá
            $\lfloor\log_{1/\alpha}|T|\rfloor$, trong đó $|T|$ là kích thước cây.

        Cân bằng trọng số $\alpha$ suy ra cân bằng chiều cao $\alpha$,
        vì mỗi khi độ sâu của nút con tăng thêm một,
        kích thước sẽ giảm xuống còn $\alpha$ lần ban đầu.
        Chiều ngược lại thì không nhất thiết đúng.
        Nói chặt chẽ hơn, sau mỗi thao tác,
        cây scapegoat luôn cân bằng chiều cao $\alpha$[^hei-bal],
        nhờ đó bảo đảm độ phức tạp của thao tác truy cập.

        Chỉ thao tác chèn mới thay đổi cấu trúc cây,
        nên chỉ cần chứng minh sau mỗi thao tác chèn,
        cây scapegoat vẫn cân bằng chiều cao $\alpha$.
        Nếu nút mới chèn quá sâu,
        làm cho toàn bộ cây không còn cân bằng chiều cao $\alpha$,
        thì khi quay lui từ nút đó về gốc,
        sẽ gặp ít nhất một nút, tức "scapegoat",
        có cây con không còn cân bằng trọng số $\alpha$.
        Sau khi xây lại cây con đó,
        chiều cao của cây con sẽ giảm ít nhất một,
        do đó nút mới chèn sẽ không còn quá sâu nữa.
    2.  **Thao tác chèn**: Độ phức tạp của thao tác chèn là $O(\log n)$ theo nghĩa khấu hao.

        Giả sử sau một thao tác chèn nào đó,
        tại nút $x$ xảy ra một lần xây lại cây con,
        với chi phí thời gian $\Theta(|T_x|)$.
        Khi nút $x$ vừa được chèn,
        hoặc ngay sau lần xây lại trước đó của chính nó hay của một nút tổ tiên,
        hai cây con trái và phải của nó chênh lệch nhiều nhất một nút.
        Còn trước lần xây lại hiện tại,
        tại nút $x$ đã thỏa mãn

        $$
        \max\{|T_{\mathrm{left}(x)}|,|T_{\mathrm{right}(x)}|\} > \alpha\cdot |T_x|.
        $$

        Điều kiện này bảo đảm độ chênh lệch kích thước giữa hai cây con trái và phải
        ít nhất là $(2\alpha-1)|T_x|$.
        Vì vậy, giữa hai lần xây lại này,
        đã có $\Omega(|T_x|)$ nút được chèn vào cây con $T_x$.

        Theo phân tích khấu hao[^alternative-analysis],
        nếu mỗi lần chèn một nút đều cộng $\Theta(1)$ thế năng cho mỗi nút
        trên đường đi từ gốc tới nút đó (trước lần xây lại nếu có),
        thì trước khi cây con tại nút $x$ được xây lại,
        nút $x$ đã tích lũy $\Omega(|T_x|)$ thế năng,
        đủ để trả chi phí $\Theta(|T_x|)$ cho lần xây lại cây con tại $x$.
        Vì độ sâu của cây luôn là $O(\log n)$,
        thế năng tăng thêm trong một lần chèn là $O(\log n)$.
        Điều này cho thấy tổng thế năng tăng thêm trong $\Theta(n)$ thao tác chèn là $O(n\log n)$.
        Do đó, tổng chi phí xây lại cây con cũng là $O(n\log n)$,
        và độ phức tạp thời gian khấu hao của một thao tác chèn
        (bao gồm xây lại) là $O(\log n)$.

        Lưu ý rằng phân tích trên không giả định rằng giữa hai lần xây lại tại nút $x$,
        bên trong cây con $T_x$ không xảy ra lần xây lại nào khác.
        Vì vậy, chỉ cần xây lại cây con tại các nút thỏa điều kiện mất cân bằng
        là đã bảo đảm độ phức tạp đúng.
    3.  **Thao tác xóa**: Độ phức tạp của thao tác xóa cũng là $O(\log n)$ theo nghĩa khấu hao.

        Việc xây lại do thao tác xóa gây ra sẽ làm cho toàn bộ cây không còn nút rỗng.
        Trước một lần xây lại do xóa nào đó,
        trong toàn bộ cây đã có $\Theta(n)$ nút rỗng,
        nghĩa là trước đó đã có ít nhất $\Theta(n)$ thao tác xóa.
        Vì độ phức tạp tìm vị trí của mỗi thao tác xóa là $O(\log n)$,
        và độ phức tạp của một lần xây lại là $\Theta(n)$,
        chi phí thời gian thực tế của $\Theta(n)$ thao tác xóa này là

        $$
        \Theta(n)O(\log n)+\Theta(n)
        $$

        Do đó, độ phức tạp khấu hao của một lần xóa là $O(\log n)$.

## Thao tác cây cân bằng

Phần này giới thiệu cách dùng cây scapegoat để duy trì một multiset.

Ngoài các thao tác đã giới thiệu ở phần trước,
các thao tác còn lại đều là thao tác thường gặp của cây cân bằng.
Tuy nhiên, vì trong cây scapegoat có thể tồn tại nút rỗng,
các thao tác này cũng cần được điều chỉnh tương ứng.

### Truy vấn hạng

Dùng tính chất của cây tìm kiếm nhị phân để đi xuống tìm vị trí nút, đồng thời ghi lại số lượng giá trị được lưu ở bên trái đường đi là đủ.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/sgt/sgt.cpp:find-rank"
    ```

### Truy vấn giá trị theo hạng

Dùng thông tin số lượng giá trị được lưu trong cây con mà các nút ghi lại
để đi xuống tìm kiếm là đủ.
Cần xét trường hợp tồn tại nút có số lần xuất hiện bằng không.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/sgt/sgt.cpp:find-kth"
    ```

### Truy vấn tiền nhiệm và kế nhiệm

Có thể kết hợp hai chức năng trên.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/sgt/sgt.cpp:pred-succ"
    ```

Nếu muốn cài đặt trực tiếp, cần xử lý các nút có số lần xuất hiện bằng không.

### Cài đặt tham khảo

Cuối phần này là cài đặt tham khảo cho bài mẫu [Cây cân bằng thông thường](https://loj.ac/p/104).

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/sgt/sgt.cpp:full-text"
    ```

## Tài liệu tham khảo

-   Galperin, Igal, and Ronald L. Rivest. "Scapegoat trees." Proceedings of the fourth annual ACM-SIAM Symposium on Discrete algorithms. 1993.
-   [Scapegoat Tree - Wikipedia](https://en.wikipedia.org/wiki/Scapegoat_tree)
-   [Bài viết của riteme về cây scapegoat](https://riteme.site/blog/2016-4-6/scapegoat.html)

[^tot-cnt]: Cũng có thể chỉ thống kê số nút chưa bị xóa.
    Khi đó không cần thống kê `tot_active` nữa,
    mà cần thống kê tổng số nút đã cấp phát `tot_max`,
    và mã nguồn cần được điều chỉnh tương ứng.

[^insert-complexity]: Theo phân tích độ phức tạp ở phần sau,
    phần hiệu suất bị mất này chỉ làm hằng số lớn hơn,
    còn độ phức tạp vẫn đúng.
    Vì việc kiểm tra độ sâu của cây có thể liên quan tới khá nhiều phép tính logarit số thực,
    trên một số dữ liệu,
    mã chỉ kiểm tra mất cân bằng mà không kiểm tra độ sâu của cây có thể nhanh hơn.

[^threshold]: Không nhất thiết phải giống tham số được chọn cho thao tác chèn ở trên.
    Dù bài báo gốc giả định như vậy,
    việc chọn các tham số khác nhau chỉ làm thay đổi hằng số trong độ phức tạp của một thao tác,
    còn độ phức tạp tổng thể vẫn đúng.

[^hei-bal]: Theo định nghĩa trong bài báo gốc,
    $n$ chỉ số nút chưa bị xóa,
    vì vậy chỉ có thể bảo đảm chiều cao cây không vượt quá $\lfloor\log_{1/\alpha}n\rfloor+1$.
    Đây được gọi là cân bằng chiều cao $\alpha$ yếu.
    Trang này không đi sâu vào khác biệt ở hằng số này.

[^alternative-analysis]: Một số bài viết sẽ phân tích đơn giản rằng
    $\Omega(|T_x|)$ lần chèn tương ứng với một lần xây lại,
    nên độ phức tạp khấu hao là
    $\dfrac{\Omega(|T_x|)O(\log n)+\Theta(|T_x|)}{\Omega(|T_x|)} = O(\log n)$.
    Cách lập luận này có thể giúp hiểu vì sao độ phức tạp khấu hao là đúng,
    nhưng chưa chặt chẽ.
    Lý do là một lần chèn có thể tương ứng với việc xây lại ở nhiều nút tổ tiên,
    nên khi nút $x$ xảy ra xây lại,
    số nút trong cây con chưa gây ra xây lại không nhất thiết là $\Omega(|T_x|)$.
