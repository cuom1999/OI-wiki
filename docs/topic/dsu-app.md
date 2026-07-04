author: sshwy

DSU và cây tái cấu trúc Kruskal có cách tư duy rất giống nhau; cả hai đều có thể dùng để xử lý các bài toán liên quan đến tính liên thông. Bài viết này giới thiệu các ứng dụng của tư tưởng DSU thông qua một số ví dụ.

## A

???+ note "A"
    Có $n$ đỉnh, ban đầu tất cả đều là các đỉnh cô lập.
    
    Tiếp theo có $m$ thao tác thêm cạnh. Thao tác thứ $i$ thêm một cạnh vô hướng giữa $a_i$ và $b_i$. Gọi $L(i,j)$ là thao tác sớm nhất sao cho sau thao tác thứ $L(i,j)$, hai đỉnh $i$ và $j$ liên thông.
    
    Sau khi thực hiện xong $m$ thao tác, hãy tính giá trị $\sum_{i=1}^n\sum_{j=i+1}^nL(i,j)$.

Đây là một ứng dụng cơ bản của DSU: trong DSU ta lưu kích thước của từng cây con. Xét việc thống kê đóng góp của từng thao tác. Nếu ở thao tác thứ $i$, $a_i$ và $b_i$ thuộc hai cây con khác nhau, ta hợp nhất hai cây con đó, rồi cộng vào đáp án tích kích thước của hai cây con nhân với $i$. Độ phức tạp thời gian là $O(n\alpha(n))$.

## B

???+ note "B"
    Có $n$ đỉnh, ban đầu tất cả đều là các đỉnh cô lập.
    
    Tiếp theo có $m$ thao tác thêm cạnh. Thao tác thứ $i$ thêm một cạnh vô hướng giữa $a_i$ và $b_i$.
    
    Tiếp theo có $q$ truy vấn. Truy vấn thứ $i$ hỏi $u_i$ và $v_i$ sớm nhất liên thông sau thao tác thứ mấy.

Xét việc ghi lại "cây sinh bởi DSU" trong quá trình hợp nhất DSU. Nói cách khác, nếu ở thao tác thứ $i$, $a_i$ và $b_i$ thuộc hai cây con khác nhau, ta đưa cạnh $(a_i,b_i)$ vào cây khung, với trọng số cạnh là $i$. Khi đó, một truy vấn trở thành bài toán hỏi trọng số cạnh lớn nhất trên đường đi từ $u$ đến $v$; có thể duy trì bằng binary lifting trên cây hoặc phân rã heavy-light. Độ phức tạp thời gian là $O(n\log n)$.

Một cách khác là duy trì cây tái cấu trúc Kruskal. Về bản chất, nó giống với cây sinh bởi DSU và có cùng độ phức tạp.

## C

???+ note "C"
    Có $n$ đỉnh, ban đầu tất cả đều là các đỉnh cô lập.
    
    Tiếp theo có $m$ thao tác thêm cạnh. Thao tác thứ $i$ thêm một cạnh vô hướng giữa $a_i$ và $b_i$.
    
    Tiếp theo có $q$ truy vấn. Truy vấn thứ $i$ hỏi kích thước thành phần liên thông chứa đỉnh $x_i$ sau thao tác thứ $t_i$.

Thuật toán offline: sắp xếp các truy vấn theo $t_i$ tăng dần. Trong quá trình thêm cạnh, dùng DSU và xử lý luôn các truy vấn tương ứng. Độ phức tạp thời gian là $O(q\log q+(n+q)\alpha(n))$.

Thuật toán online: với bài này, thuật toán online chỉ có thể dùng cây tái cấu trúc Kruskal. Điểm khác biệt giữa cây tái cấu trúc Kruskal và DSU là: nếu ở thao tác thứ $i$, $a_i$ và $b_i$ thuộc hai cây con khác nhau, Kruskal tạo một đỉnh mới $u$, rồi nối gốc của cây con chứa $a_i$ và gốc của cây con chứa $b_i$ lần lượt tới $u$, làm hai con của $u$. Có thể xem trọng số đỉnh của $u$ là $i$. Với $n$ đỉnh ban đầu, trọng số đỉnh là $0$.

Đối với mỗi truy vấn, ta chỉ cần tìm thành phần liên thông lớn nhất chứa $x_i$ trong cây tái cấu trúc sao cho trọng số đỉnh lớn nhất trong thành phần đó không vượt quá $t_i$. Đáp án của truy vấn là số đỉnh có trọng số $0$ trong thành phần liên thông này, tức số đỉnh lá.

Do chỉ số thao tác tăng dần, trọng số của đỉnh cha trên cây tái cấu trúc luôn lớn hơn trọng số của đỉnh con. Điều này có nghĩa là ta có thể dùng binary lifting trên đường đi từ $x_i$ đến gốc trong cây tái cấu trúc để tìm đỉnh có trọng số lớn nhất nhưng không vượt quá $t_i$. Như vậy ta thu được đáp án. Độ phức tạp thời gian là $O(n\log n)$.

## D

???+ note "D"
    Cho một dãy nhị phân $a_1,\ldots,a_n$ độ dài $n$, ban đầu tất cả đều bằng $0$. Tiếp theo thực hiện $m$ thao tác:
    
    -   Gán $a_x=1$;
    -   Tìm vị trí đầu tiên tính từ trái sang phải có giá trị $0$ trong $a_x,a_{x+1},\ldots,a_n$.

Xây dựng một DSU, trong đó $f_i$ biểu thị vị trí đầu tiên có giá trị $0$ trong $a_i,a_{i+1},\ldots,a_n$. Ban đầu $f_i=i$.

Với một thao tác $a_x=1$, nếu $a_x$ vốn đã bằng $1$ thì bỏ qua. Ngược lại, ta đặt $f_x=f_{x+1}$.

Độ phức tạp thời gian là $O(n\log n)$. Nếu muốn dùng hợp nhất theo hạng thì cài đặt sẽ phức tạp hơn, nhưng vẫn khả thi. Khi đó độ phức tạp thời gian có thể là $O(n\alpha(n))$.

## E

???+ note "E"
    Cho ba dãy số nguyên dương $a$, $b$, $c$ có độ dài $n$. Duyệt mọi $1\le i\le j\le n$, hãy tìm giá trị lớn nhất của $a_i\cdot b_j\cdot \min_{i\le k\le j}c_k$.

Bài này cũng có nhiều cách giải; ở đây ta tập trung trình bày hướng DSU. Xét các $c_k$ theo thứ tự trọng số giảm dần. Điều này tương đương với việc thêm một đỉnh tại vị trí $k$, rồi hợp nhất nó với thành phần liên thông chứa các đỉnh ở vị trí $k-1$ và $k+1$ nếu các vị trí đó đã có đỉnh. Trên mỗi thành phần liên thông, lưu giá trị lớn nhất của $a$ và giá trị lớn nhất của $b$; khi hợp nhất là có thể cập nhật đáp án. Độ phức tạp thời gian là $O(n\log n)$.

## F

???+ note "F"
    Cho một cây có $n$ đỉnh. Tiếp theo có $m$ thao tác:
    
    -   Thêm một cạnh từ $a_i$ đến $b_i$.
    -   Hỏi giữa hai đỉnh $u_i$ và $v_i$ có tồn tại ít nhất hai đường đi không giao nhau về cạnh hay không.

Truy vấn có thể chuyển thành: hỏi $u_i$ và $v_i$ có nằm trên cùng một chu trình đơn hay không. Theo ý tưởng co các thành phần song liên thông cạnh, mỗi khi thêm một cạnh giữa $a_i$ và $b_i$, ta có thể co các đỉnh trên đường đi từ $a_i$ đến $b_i$ trong cây lại với nhau. Nếu hai cạnh $(a_i,b_i)$ và $(a_j,b_j)$ tương ứng với hai đường đi trên cây có giao nhau, thì hai cạnh đó sẽ bị co vào cùng một nhóm.

Nói cách khác, thao tác thêm cạnh có thể hiểu là phủ một lần các cạnh trên đường đi từ $a_i$ đến $b_i$ trong cây. Khi đó truy vấn được chuyển thành: kiểm tra trên đường đi từ $u_i$ đến $v_i$ có tồn tại cạnh chưa bị phủ hay không. Nếu không tồn tại, thì $u_i$ và $v_i$ thuộc cùng một thành phần song liên thông cạnh, tức cũng thuộc cùng một chu trình đơn.

Xét việc dùng DSU để duy trì. Chọn gốc cho cây, đặt $f_i$ biểu thị cạnh chưa bị phủ đầu tiên trên đường đi từ $i$ đến gốc. Khi đó với mỗi thao tác thêm cạnh, ta nhảy DSU trực tiếp. Sau khi phủ một cạnh, hợp nhất $f$ của đỉnh tương ứng với cạnh đó vào cha của nó. Như vậy, mỗi cạnh bị phủ nhiều nhất một lần, nên tổng độ phức tạp là $O(n\log n)$. Dùng DSU hợp nhất theo hạng cũng có thể đạt $O(n\alpha(n))$.

Cách duy trì của bài này tương tự phiên bản trên cây của bài D.

## G

???+ note "G"
    Đồ thị vô hướng $G$ có $n$ đỉnh, ban đầu tất cả đều là các đỉnh cô lập, tức chưa có cạnh.
    
    Tiếp theo có $m$ thao tác thêm cạnh. Thao tác thứ $i$ thêm một cạnh vô hướng giữa $a_i$ và $b_i$.
    
    Sau mỗi thao tác, hãy tính số lượng cầu trong đồ thị.
    
    Định nghĩa cầu: với một cạnh $(x,y)$ trong $G$, nếu xóa cạnh đó làm số thành phần liên thông tăng lên, thì $(x,y)$ được gọi là cầu.
    
    Bắt buộc xử lý online.

Bài này kiểm tra khả năng hiểu tính chất của DSU. Xét việc dùng DSU để duy trì tính liên thông. Với cây các thành phần song liên thông cạnh, ta duy trì một cây có gốc, đặt $p_i$ là cha của đỉnh $i$. Đây chính là DSU không dùng nén đường đi.

Nếu ở thao tác thứ $i$, $a_i$ và $b_i$ thuộc cùng một thành phần liên thông, ta cần co các đỉnh trên đường đi từ $a_i$ đến $b_i$ trong cây thành phần song liên thông cạnh. Việc này có thể duy trì bằng DSU. Mỗi lần co đỉnh, số thành phần song liên thông cạnh giảm $1$, và giảm nhiều nhất $n-1$ lần, nên độ phức tạp DSU của phần co đỉnh là $O(n\alpha(n))$.

Để co đỉnh, trước hết ta phải tìm LCA của $a_i$ và $b_i$ trên cây thành phần song liên thông cạnh. Có thể duy trì một mảng đánh dấu cho việc này. Sau đó, bắt đầu từ $a_i$ và $b_i$, luân phiên nhảy từng bước lên tổ tiên và đánh dấu các đỉnh đi qua. Một khi nhảy tới một đỉnh đã được đánh dấu trước đó, đỉnh này chính là LCA của $a_i$ và $b_i$. Độ phức tạp của thuật toán này tuyến tính theo độ dài đường đi từ $a_i$ đến $b_i$, nên có thể chấp nhận được.

Nếu $a_i$ và $b_i$ thuộc hai thành phần liên thông khác nhau, ta hợp nhất hai thành phần đó và tăng số cầu thêm $1$. Lúc này cần nối hai cây thành phần song liên thông cạnh chứa hai đỉnh đó, tức thêm một cạnh từ $a_i$ đến $b_i$. Vì vậy ta cần đặt lại gốc cho một trong hai cây, rồi nối nó vào cây còn lại. Ở đây dùng ý tưởng hợp nhất theo heuristic: đặt lại gốc cho cây có ít đỉnh hơn. Tổng độ phức tạp của phần này là $O(n\log n)$.

Tổng hợp lại, độ phức tạp toàn bộ thuật toán là $O(n\log n+m\log n)$.

## Tổng kết

DSU và cây tái cấu trúc Kruskal có nhiều điểm chung, còn tối ưu hóa của DSU, tức hợp nhất theo hạng, chính là một ứng dụng của tư tưởng hợp nhất theo heuristic. Vì vậy, vận dụng linh hoạt DSU có thể xử lý thuận tiện nhiều bài toán đồ thị liên quan đến tính liên thông.

**Một phần nội dung của trang này được dịch từ bài viết [Поиск мостов в режиме онлайн](http://e-maxx.ru/algo/bridge_searching_online) và bản dịch tiếng Anh của nó, [Finding Bridges Online](https://cp-algorithms.com/graph/bridge-searching-online.html). Phiên bản tiếng Nga có giấy phép Public Domain + Leave a Link; phiên bản tiếng Anh có giấy phép CC-BY-SA 4.0.**
