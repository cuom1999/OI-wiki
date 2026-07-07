Trang này giới thiệu ngắn gọn thuật toán Minimax và cắt tỉa Alpha-Beta.

<span id="thuật-toán-minimax"></span>

## Thuật toán Minimax

Thuật toán Minimax, hay thuật toán cực tiểu hóa cực đại, là thuật toán dùng để tối thiểu hóa tổn thất tiềm ẩn trong trường hợp xấu nhất (tức tổn thất lớn nhất).

### Quy trình

Trong các trò chơi hai người tổng bằng không với cục diện xác định, thường cần thực hiện tìm kiếm đối kháng và xây dựng một cây tìm kiếm, trong đó mỗi nút là một trạng thái xác định. Các tầng lẻ là lượt của MAX, các tầng chẵn là lượt của đối phương. Mỗi nút lá của cây tìm kiếm được gán một giá trị đánh giá; giá trị càng lớn thì khả năng thắng của MAX càng cao. MAX muốn chọn khả năng thắng lớn hơn, còn đối phương sẽ cố gắng hạ thấp khả năng thắng đó. Trên cây tìm kiếm, điều này có nghĩa là các nút ở tầng lẻ (nút của MAX) luôn chọn trạng thái con có khả năng thắng lớn nhất, còn các nút ở tầng chẵn (nút của đối phương) luôn chọn trạng thái con có khả năng thắng của MAX nhỏ nhất.

Trong thuật toán Minimax, cây tìm kiếm được duyệt từ trên xuống dưới, rồi khi quay lui thì dùng thông tin của các cây con để cập nhật đáp án. Cuối cùng thu được giá trị của nút gốc, tức điểm số lớn nhất mà MAX có thể đạt được khi cả hai bên đều chơi theo chiến lược tối ưu.

### Ví dụ

Xét một ví dụ đơn giản.

Gọi bên đang tối đa hóa điểm số là MAX, đối phương là MIN; hình minh họa như sau:

![](images/minimax-1.svg)

Ví dụ, với cục diện sau, giả sử tìm kiếm từ trái sang phải, giá trị của nút gốc biểu thị khả năng thắng của MAX:

![](images/minimax-2.svg)

Nên chọn nhánh ở giữa. Nếu chọn nhánh bên trái, khả năng thắng xấu nhất là $3$; nếu chọn nhánh ở giữa, khả năng thắng xấu nhất là $15$; nếu chọn nhánh bên phải, khả năng thắng xấu nhất là $1$. Mặc dù nhánh bên phải có thể đem lại khả năng thắng $22$, một đối phương đủ lý trí sẽ làm cho khả năng thắng của MAX chỉ còn $1$. Sau khi cân nhắc, nhánh ở giữa tốt hơn.

![](images/minimax-3.svg)

Cụ thể, khi xét nhánh bên phải, một khi đã phát hiện khả năng thắng có thể là $1$, không cần tiếp tục xét các nhánh có khả năng thắng $12$, $20$, $22$ nữa. So với khả năng thắng của hai nhánh bên trái, có thể xác định nhánh bên phải không phải lựa chọn tốt nhất.

Thuật toán Minimax đơn giản thường phải xây dựng một cây tìm kiếm rất lớn, khiến cả độ phức tạp thời gian lẫn không gian đều có thể vượt quá giới hạn chấp nhận được. Cắt tỉa Alpha-Beta là một phương pháp tối ưu hóa Minimax bằng cách dùng cận trên và cận dưới của điểm số hai bên tại mỗi nút trên cây tìm kiếm để cắt tỉa.

Cần lưu ý rằng với các bài toán khác nhau, giá trị trên mỗi nút của cây tìm kiếm có thể mang những ý nghĩa khác nhau: giá trị đánh giá, điểm số, xác suất thắng, v.v. Để tiện trình bày, phần dưới thống nhất gọi chung là điểm số.

<span id="cắt-tỉa-alpha-beta"></span>

## Cắt tỉa Alpha-Beta

Cắt tỉa Alpha-Beta là kỹ thuật cắt tỉa tìm kiếm dành cho thuật toán Minimax.

### Quy trình

Trong thuật toán Minimax, nếu đã biết điểm số của tất cả các nút con của một nút, có thể tính điểm số của nút đó: với nút MAX, lấy điểm lớn nhất; với nút MIN, lấy điểm nhỏ nhất.

Khi quá trình tìm kiếm đã đi tới một nút nhưng chưa hoàn tất nút đó, tuy chưa thể tính điểm của nút, vẫn có thể suy ra **phạm vi giá trị điểm số của hai bên dựa trên các nút đã được tìm kiếm**. Khi tìm kiếm, thuật toán duy trì hai biến $\alpha$ và $\beta$, lần lượt biểu thị, tại cục diện ứng với nút hiện tại và **xét tất cả các nút đã được tìm kiếm**, cận dưới của điểm số mà người chơi Alpha (bên tìm điểm lớn nhất) có thể bảo đảm đạt được và cận trên của điểm số mà người chơi Beta (bên tìm điểm nhỏ nhất) có thể bảo đảm đạt được.

Chiến lược cắt tỉa của Alpha-Beta phụ thuộc vào giá trị $\alpha$ và $\beta$ khi tìm kiếm nút hiện tại. Nếu nút hiện tại là nút MAX, Alpha có thể tiếp tục tìm các nút con để nâng cận dưới điểm số $\alpha$. Tuy nhiên, nếu sau một lần tìm kiếm đã có $\alpha\ge\beta$, nút này sẽ không thể xuất hiện trong một ván đấu: chỉ cần đi tới nút này, người chơi Alpha đã có thể bảo đảm điểm số ít nhất là $\alpha$; nhưng người chơi Beta đã biết tồn tại một chiến lược (lệch khỏi đường đi hiện tại) có thể bảo đảm điểm số không vượt quá $\beta\le\alpha$, nên Beta sẽ không để cục diện phát triển tới **nút hiện tại**. Tương tự, nếu nút hiện tại là nút MIN và sau khi tìm kiếm một nút con của nó đã có $\beta\le\alpha$, cũng không cần tiếp tục tìm các nút con khác, vì người chơi Alpha sẽ không để cục diện đi vào **nút hiện tại**. Tổng kết hai trường hợp, khi $\alpha \geq \beta$, các nhánh còn lại của nút đó không cần tìm tiếp nữa, tức có thể cắt tỉa. Lưu ý khi $\alpha = \beta$ cũng cần cắt tỉa, vì sẽ không có kết quả tốt hơn, nhưng có thể có kết quả xấu hơn.

Trong quá trình tìm kiếm, không cần duy trì điểm số của từng nút, chỉ cần duy trì $\alpha$ và $\beta$. Ban đầu đặt $\alpha=-\infty,~\beta=+\infty$. Khi tìm kiếm xuống dưới, cần truyền kèm thông tin $\alpha$ và $\beta$ để ghi lại các phương án dự phòng của hai người chơi.

Khi tìm xong một nút con, cần cập nhật thông tin tại nút hiện tại. Giả sử nút hiện tại $X$ là nút MAX và vừa tìm xong nút con $Y$ của nó. Khi đó, giá trị $\beta$ tại nút $X$ không đổi; chỉ giá trị $\alpha$ cần lấy max với điểm số của nút con $Y$. Nếu nút con $Y$ là nút lá, dùng trực tiếp điểm số của $Y$ để cập nhật $\alpha$ tại $X$; nếu không, chỉ cần dùng giá trị $\beta$ của nút con $Y$ để cập nhật $\alpha$ của nút $X$. Lúc này có ba khả năng:

1.  Giá trị $\beta$ của nút con $Y$ nằm nghiêm ngặt giữa giá trị $\alpha$ và $\beta$ của nút $X$. Vì nút con $Y$ kế thừa giá trị $\alpha$ của nút $X$ và không cập nhật nó, sau khi tìm xong nút con $Y$ mà vẫn có $\beta > \alpha$, điều đó cho thấy không xảy ra cắt tỉa khi tìm nút con $Y$. Giá trị $\beta$ cuối cùng của nút con $Y$ bằng giá trị nhỏ hơn giữa giá trị $\beta$ mà nó kế thừa từ nút $X$ và điểm số nhỏ nhất trong tất cả các nút con của chính $Y$. Vì giá trị nhỏ nhất này nhỏ hơn nghiêm ngặt giá trị $\beta$ của nút $X$, đây là giá trị nhỏ nhất trong điểm số của tất cả các nút con của $Y$. Do đó, với vai trò là nút MIN, điểm số của nút con $Y$ chính là giá trị $\beta$ này. Dùng nó để cập nhật $\alpha$ của nút $X$ là hợp lý.
2.  Giá trị $\beta$ của nút con $Y$ bằng giá trị $\beta$ của nút $X$. Như đã nói ở trên, điều này cho thấy điểm số của tất cả các nút con của $Y$ đều không nhỏ hơn giá trị $\beta$ của nút $X$. Điều đó tiếp tục cho thấy người chơi Beta sẽ không để cục diện đi vào nút $X$: vì chỉ cần người chơi Alpha chọn nút con $Y$, Beta không thể đạt điểm số thấp hơn $\beta$. Vì vậy lúc này, việc dùng giá trị $\beta$ của nút con $Y$ để cập nhật $\alpha$ của nút $X$ là nhằm làm cho tại nút $X$ có $\alpha=\beta$, từ đó kích hoạt điều kiện cắt tỉa. Hiệu quả của nó giống với việc dùng điểm số thực tế tại $Y$ - một số lớn hơn hoặc bằng giá trị $\beta$ tại nút $X$ - để cập nhật $\alpha$ của nút $X$.
3.  Giá trị $\beta$ của nút con $Y$ nhỏ hơn hoặc bằng giá trị $\alpha$ của nút $X$. Lúc này nút con $Y$ đã kích hoạt điều kiện cắt tỉa; điểm số thực tế của nó không vượt quá giá trị $\beta$ của nút con $Y$, và càng không vượt quá giá trị $\alpha$ của nút $X$. Dùng điểm số thực tế của nút con $Y$ để cập nhật $\alpha$ của nút $X$ sẽ không làm thay đổi $\alpha$. Hiệu quả của việc này giống với việc dùng giá trị $\beta$ của nút con $Y$ để cập nhật $\alpha$ của nút $X$.

Phân tích trên cho thấy sau khi tìm kiếm xong một nút con, chỉ khi điểm số của nó thuộc trường hợp thứ nhất thì $\alpha$ (hoặc $\beta$) mới ghi đúng điểm số thực tế của nút con đó với tư cách là một nút MAX (hoặc MIN). Trong các trường hợp khác, tuy giá trị được ghi lại không nhất thiết là điểm số chính xác, thông tin đó vẫn đủ để bảo đảm việc cắt tỉa diễn ra đúng đắn, nên không ảnh hưởng đến điểm số được ghi ở nút gốc.

### Ví dụ

Phần này phân tích một ví dụ để minh họa cách cập nhật giá trị $\alpha$ và $\beta$ tại từng nút trong quá trình tìm kiếm. Trong quá trình đó, điểm số tại các nút liên quan cũng được tính. Nhờ vậy có thể quan sát quan hệ giữa điểm số thực tế của mỗi nút và các giá trị $\alpha$, $\beta$ được ghi lại tại đó. Tuy nhiên cần lưu ý rằng khi cài đặt thuật toán này, không tính điểm số thực tế của các nút như vậy.

Với cục diện sau, giả sử tìm kiếm từ trái sang phải:

![](images/alpha-beta-1.svg)

Ban đầu đặt $\alpha = -\infty,~\beta = +\infty$, và truyền thông tin này xuống theo đường tìm kiếm.

![](images/alpha-beta-2.svg)

Khi tìm tới nút A, vì điểm số của nút con bên trái là $3$ và nút A là nút MIN, nó muốn chọn nước đi có điểm nhỏ, nên giá trị $\beta$ được cập nhật thành $3$, bởi $3$ nhỏ hơn giá trị $\beta$ hiện tại ($\beta = +\infty$). Sau đó, điểm số của nút con bên phải của A là $17$, nên lúc này không cập nhật $\beta$ của nút A, vì $17$ lớn hơn giá trị $\beta$ hiện tại ($\beta = 3$). Đến đây, tất cả các nút con của A đã được tìm xong, có thể tính điểm số của nút A là $3$, trùng với giá trị $\beta$ được ghi tại nút này (trường hợp 1 ở trên).

![](images/alpha-beta-3.svg)

Nút A là nút con của nút B. Sau khi tính được điểm số của nút A, có thể cập nhật giá trị $\alpha$ và $\beta$ của nút B. Vì nút B là nút MAX và muốn chọn nước đi có điểm lớn, giá trị $\alpha$ được cập nhật thành $3$, bởi giá trị $\beta$ tại nút con A ($\beta=3$) lớn hơn giá trị $\alpha$ hiện tại ($\alpha = -\infty$). Sau đó, tìm kiếm nút con bên phải C của nút B, đồng thời truyền giá trị $\alpha$ và $\beta$ của nút B cho nút C.

![](images/alpha-beta-4.svg)

Với nút C, vì điểm số của nút con bên trái là $2$ và nút C là nút MIN, giá trị $\beta$ được cập nhật thành $2$. Lúc này $\alpha \geq \beta$, nên không cần tìm các nút con còn lại của C nữa, vì có thể xác định người chơi Alpha sẽ không cho phép cục diện phát triển tới nút C. Lúc này nút C là nút MIN, điểm số của nó là $2$, không vượt quá giá trị $\beta$ được ghi lại (trường hợp 3 ở trên). Vì tất cả các nút con của B đã được tìm xong, có thể tính điểm số của nút B là $3$, bằng với giá trị $\alpha$ được ghi lại (trường hợp 1 ở trên).

![](images/alpha-beta-5.svg)

Sau khi tính điểm số của nút B, vì B là một nút con của nút D, có thể cập nhật giá trị $\alpha$ và $\beta$ của nút D. Vì nút D là nút MIN, giá trị $\beta$ được cập nhật thành $3$. Sau đó nút D truyền giá trị $\alpha$ và $\beta$ cho nút E, và nút E tiếp tục truyền cho nút F. Với nút F, nó chỉ có một nút con có điểm số $15$; vì $15$ lớn hơn giá trị $\beta$ hiện tại và nút F là nút MIN, không cập nhật $\beta$ của F. Sau đó có thể tính điểm số của nút F là $15$, lớn hơn giá trị $\beta$ được ghi lại (trường hợp 2 ở trên).

![](images/alpha-beta-6.svg)

Sau khi tính điểm số của nút F, vì F là một nút con của nút E, có thể cập nhật giá trị $\alpha$ và $\beta$ của nút E. Nút E là nút MAX, nên cập nhật giá trị $\alpha$; lúc này $\alpha \geq \beta$, do đó có thể cắt bỏ các nhánh còn lại của E (tức nút G). Sau đó, vì nút E là nút MAX, đặt điểm số của nút E là $15$, lớn hơn nghiêm ngặt giá trị $\alpha$ được ghi lại (trường hợp 3 ở trên). Dùng giá trị $\alpha$ của nút E để cập nhật $\beta$ của nút D thì kết quả vẫn là $3$. Lúc này tất cả các nút con của D đã được tìm xong, có thể tính điểm số của nút D là $3$, bằng giá trị $\beta$ được ghi lại (trường hợp 1 ở trên).

![](images/alpha-beta-7.svg)

Sau khi tính điểm số của nút D, vì D là một nút con của nút H, có thể cập nhật giá trị $\alpha$ và $\beta$ của nút H. Nút H là nút MAX, nên cập nhật $\alpha$. Sau đó, theo thứ tự tìm kiếm, lần lượt truyền giá trị $\alpha$ và $\beta$ của nút H cho các nút I, J, K. Với nút K, điểm số của nút con bên trái là $2$ và nút K là nút MIN, nên cập nhật $\beta$; lúc này $\alpha \geq \beta$, do đó có thể cắt bỏ các nhánh còn lại của K. Sau đó đặt điểm số của nút K là $2$, nhỏ hơn hoặc bằng giá trị $\beta$ được ghi lại (trường hợp 3 ở trên).

![](images/alpha-beta-8.svg)

Sau khi tính điểm số của nút K, vì K là một nút con của nút J, có thể cập nhật giá trị $\alpha$ và $\beta$ của nút J. Nút J là nút MAX, nên cập nhật $\alpha$; tuy nhiên, vì điểm số của nút K nhỏ hơn $\alpha$, giá trị $\alpha$ của J vẫn giữ nguyên là $3$. Sau đó, truyền giá trị $\alpha$ và $\beta$ của nút J cho nút L. Vì nút L là nút MIN, cập nhật $\beta = 3$; lúc này $\alpha \geq \beta$, nên có thể cắt bỏ các nhánh còn lại của L. Do nút L không còn nhánh nào khác, thực tế không có nhánh nào bị cắt tại bước này. Sau đó đặt điểm số của nút L là $3$, nhỏ hơn hoặc bằng giá trị $\beta$ được ghi lại (trường hợp 3 ở trên).

![](images/alpha-beta-9.svg)

Sau khi tính điểm số của nút L, vì L là một nút con của nút J, có thể cập nhật giá trị $\alpha$ và $\beta$ của nút J. Nút J là nút MAX, nên cập nhật $\alpha$; tuy nhiên, vì điểm số của nút L nhỏ hơn hoặc bằng $\alpha$, giá trị $\alpha$ của J vẫn giữ nguyên là $3$. Lúc này tất cả các nút con của J đã được tìm xong, có thể tính điểm số của nút J là $3$, bằng giá trị $\alpha$ được ghi lại (trường hợp 2 ở trên).

Sau khi tính điểm số của nút J, vì J là một nút con của nút I, có thể cập nhật giá trị $\alpha$ và $\beta$ của nút I. Nút I là nút MIN, nên cập nhật $\beta$; lúc này $\alpha \geq \beta$, do đó có thể cắt bỏ các nhánh còn lại của I. Đáng lưu ý là do tồn tại nút con bên phải, điểm số thực tế của nút I là $2$, nhỏ hơn giá trị $\beta$ được ghi lại (trường hợp 3 ở trên).

Sau khi tính điểm số của nút I, vì I là một nút con của nút H, có thể cập nhật giá trị $\alpha$ và $\beta$ của nút H. Nút H là nút MAX, nên cập nhật $\alpha$; tuy nhiên, vì điểm số của nút I nhỏ hơn hoặc bằng $\alpha$, giá trị $\alpha$ của H vẫn giữ nguyên là $3$. Lúc này tất cả các nút con của H đã được tìm xong, có thể tính điểm số của nút H là $3$, bằng giá trị $\alpha$ được ghi lại (trường hợp 1 ở trên).

![](images/alpha-beta-10.svg)

Đó là kết quả cuối cùng.

### Cài đặt

???+ example "Mã tham khảo"
    ```cpp
    int alpha_beta(int u, int alph, int beta, bool is_max) {
      if (!son_num[u]) return val[u];
      if (is_max) {
        for (int i = 0; i < son_num[u]; ++i) {
          int d = son[u][i];
          alph = max(alph, alpha_beta(d, alph, beta, !is_max));
          if (alph >= beta) break;
        }
        return alph;
      } else {
        for (int i = 0; i < son_num[u]; ++i) {
          int d = son[u][i];
          beta = min(beta, alpha_beta(d, alph, beta, !is_max));
          if (alph >= beta) break;
        }
        return beta;
      }
    }
    ```

## Tài liệu tham khảo và ghi chú

-   [Thuật toán minimax - Wikipedia](https://en.wikipedia.org/wiki/Minimax#Minimax_algorithm_with_alternate_moves)
-   [Cắt tỉa alpha-beta - Wikipedia](https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning)

**Một phần nội dung bài viết này được trích từ blog [Giải thích chi tiết thuật toán Minimax và cắt tỉa Alpha-Beta](https://blog.csdn.net/wenjianmuran/article/details/90633418), tuân theo giấy phép CC 4.0 BY-SA. Nội dung đã được chỉnh sửa.**
