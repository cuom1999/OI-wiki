author: chu-yuehan

SAT là viết tắt của bài toán thỏa mãn (Satisfiability). Dạng tổng quát của nó là bài toán thỏa mãn k, gọi tắt là k-SAT. Khi $k>2$, bài toán này là NP-đầy đủ, nên phần này chỉ xét trường hợp $k=2$.

## Định nghĩa

Nói đơn giản, 2-SAT cho trước $n$ mệnh đề Boolean, mỗi mệnh đề liên quan đến hai biến, chẳng hạn $a \vee b$, nghĩa là trong hai biến $a, b$ có ít nhất một biến được thỏa mãn. Cần kiểm tra có tồn tại một phương án gán giá trị khả thi hay không. Có thể có nhiều phương án, và trong bài toán thông thường chỉ cần tìm một phương án bất kỳ. Ngoài ra, $\neg a$ biểu thị phủ định của $a$.

## Ý tưởng giải

???+ example "[Luogu P4782 [Mẫu] 2-SAT](https://www.luogu.com.cn/problem/P4782)"
    Có $n$ biến Boolean $x_1\sim x_n$, cùng $m$ điều kiện cần thỏa mãn. Mỗi điều kiện đều có dạng "$x_i$ là `true`/`false` hoặc $x_j$ là `true`/`false`". Ví dụ: "$x_1$ là đúng hoặc $x_3$ là sai", "$x_7$ là sai hoặc $x_2$ là sai".
    
    Mục tiêu của bài toán 2-SAT là gán giá trị cho mỗi biến sao cho mọi điều kiện đều được thỏa mãn.

Biểu diễn bài toán trên bằng các mệnh đề Boolean. Đặt $a$ biểu thị $x_a$ là đúng, còn $\neg a$ biểu thị $x_a$ là sai. Nếu một điều kiện yêu cầu $a$ hoặc $b$, tức $(a \vee b)$, nghĩa là trong hai biến $a, b$ có ít nhất một biến thỏa mãn. Khi dựng đồ thị có hướng cho các quan hệ giữa biến, dùng các đỉnh để biểu diễn việc $a$ đúng hoặc không đúng, rồi thêm các cạnh $\neg a\to b$ và $\neg b\to a$. Chúng biểu thị rằng nếu $a$ **không đúng** thì $b$ **nhất định đúng**; tương tự, nếu $b$ **không đúng** thì $a$ **nhất định đúng**. Sau khi dựng đồ thị, có thể dùng thuật toán co thành phần liên thông mạnh để giải bài toán 2-SAT.

|       Mệnh đề gốc       |                    Dựng đồ thị                    |
| :---------------------: | :-----------------------------------------------: |
|   $\neg a \vee b$       | $a \to b$ và $\neg b \to \neg a$                  |
|     $a \vee b$          | $\neg a \to b$ và $\neg b \to a$                  |
| $\neg a\vee\neg b$      | $a \to \neg b$ và $b \to \neg a$                  |

Nhiều bài toán 2-SAT đều cần tìm các quan hệ kiểu: nếu $a$ **không đúng** thì $b$ **đúng**.

## Cách giải

Xét ý nghĩa của việc hai đỉnh nằm trong cùng một thành phần liên thông mạnh. Theo ý nghĩa logic của các cạnh ở trên: nếu hai đỉnh nằm trong cùng một thành phần liên thông mạnh, thì hai điều kiện mà chúng biểu diễn **hoặc cùng được thỏa mãn, hoặc cùng không được thỏa mãn**.

Sau khi dựng đồ thị, dùng [thuật toán Tarjan tìm SCC](./scc.md), rồi với mỗi biến Boolean $a$, kiểm tra đỉnh biểu diễn $a$ đúng và đỉnh biểu diễn $a$ không đúng có nằm trong cùng một SCC hay không. Cùng một biến không thể vừa đúng vừa sai. Nếu tồn tại biến như vậy thì bài toán vô nghiệm, ngược lại bài toán có nghiệm.

Khi xuất một phương án, có thể dựa vào thứ tự topo của các biến trong đồ thị để xác định giá trị của biến. Nếu thứ tự topo của biến $x$ nằm sau $\neg x$, thì gán $x$ là đúng. Áp dụng vào đồ thị co SCC của thuật toán Tarjan, nếu số hiệu SCC chứa $x$ nằm trước số hiệu SCC chứa $\neg x$, gán $x$ là đúng. Lý do là Tarjan dùng ngăn xếp khi tìm thành phần liên thông mạnh: sau khi chạy Tarjan và co SCC, thành phần có thứ tự topo lớn hơn sẽ được Tarjan duyệt muộn hơn, nên được lấy khỏi ngăn xếp và co thành SCC sớm hơn, dẫn đến số hiệu thành phần nhỏ hơn. Vì vậy số hiệu SCC do Tarjan tìm được tương ứng với **thứ tự topo ngược**.

Thuật toán duyệt toàn bộ đồ thị một lần. Đồ thị có $O(n)$ đỉnh và $O(m)$ cạnh, nên độ phức tạp tổng thể là $O(n+m)$.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/graph/code/2-sat/2-sat_3.cpp"
    ```

## Ví dụ

### Ví dụ 1

???+ example "[HDU3062 Party](https://acm.hdu.edu.cn/showproblem.php?pid=3062)"
    Có $n$ cặp vợ chồng được mời tham dự một buổi tiệc. Do giới hạn địa điểm, mỗi cặp vợ chồng chỉ có một người được tham dự. Trong $2n$ người, một số người có mâu thuẫn lớn với nhau, còn vợ chồng thì không có mâu thuẫn. Hai người có mâu thuẫn sẽ không cùng xuất hiện ở buổi tiệc. Hỏi có thể có đúng $n$ người cùng tham dự hay không?

Theo phân tích ở trên, nếu người chồng trong $a_1$ không hợp với người vợ trong $a_2$, nối cạnh từ người chồng trong $a_1$ đến người chồng trong $a_2$, đồng thời nối cạnh từ người vợ trong $a_2$ đến người vợ trong $a_1$, rồi co SCC và tô màu để kiểm tra.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/2-sat/2-sat_1.cpp"
    ```

### Ví dụ 2

???+ example "[2018-2019 ACM-ICPC Asia Seoul Regional K TV Show Game](https://codeforces.com/gym/101987/problem/K)"
    Có $k$ bóng đèn, mỗi bóng có màu đỏ hoặc xanh lam, nhưng ban đầu chưa biết màu của từng bóng. Có $n$ người, mỗi người chọn ba bóng đèn và đoán màu của chúng. Một người nhận được giải thưởng nếu đoán đúng màu của ít nhất hai bóng đèn. Cần xác định có tồn tại một cách tô màu các bóng đèn sao cho mọi người đều nhận được giải thưởng hay không; nếu có, cần xuất một cách tô màu.

Theo [Wu Yu - Solving 2-SAT Problems Using Symmetry](https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2003%E8%AE%BA%E6%96%87%E9%9B%86/%E4%BC%8D%E6%98%B1--%E7%94%B1%E5%AF%B9%E7%A7%B0%E6%80%A7%E8%A7%A32-SAT%E9%97%AE%E9%A2%98/%E4%BC%8D%E6%98%B1.ppt), để xuất một nghiệm khả thi của bài toán 2-SAT, chỉ cần chọn và xóa từ dưới lên trên trên DAG thu được sau khi Tarjan co SCC.

Khi cài đặt cụ thể, có thể dựng đồ thị ngược của DAG rồi sắp xếp topo trên đồ thị ngược; cũng có thể dựa vào tính chất sau khi Tarjan co SCC: số hiệu thành phần liên thông chứa một đỉnh càng nhỏ thì đỉnh đó càng gần nút lá, nên ưu tiên chọn các đỉnh thuộc thành phần liên thông có số hiệu nhỏ hơn.

Dưới đây là mã của cách cài đặt thứ hai.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/2-sat/2-sat_2.cpp"
    ```

## Bài tập

-   [Luogu P5782 Peace Committee](https://www.luogu.com.cn/problem/P5782)
-   [POJ3683 Priest John's Busiest Day](http://poj.org/problem?id=3683)
