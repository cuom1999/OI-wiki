## Giới thiệu

Trước khi đọc nội dung dưới đây, nên nắm vững phần [khái niệm liên quan đến lý thuyết đồ thị](./concept.md).

Đọc thêm: [đỉnh khớp và cầu](./cut.md)

## Định nghĩa

Định nghĩa chặt chẽ hơn của đỉnh khớp và cầu có thể xem ở phần [khái niệm liên quan đến lý thuyết đồ thị](./concept.md).

Trong một đồ thị vô hướng liên thông, với hai đỉnh $u$ và $v$, nếu xóa bất kỳ cạnh nào (chỉ xóa một cạnh) cũng không thể làm chúng mất liên thông, thì $u$ và $v$ được gọi là **song liên thông cạnh**.

Trong một đồ thị vô hướng liên thông, với hai đỉnh $u$ và $v$, nếu xóa bất kỳ đỉnh nào (chỉ xóa một đỉnh, và không được xóa chính $u$ hoặc $v$) cũng không thể làm chúng mất liên thông, thì $u$ và $v$ được gọi là **song liên thông đỉnh**.

Quan hệ song liên thông cạnh có tính bắc cầu: nếu $x,y$ song liên thông cạnh và $y,z$ song liên thông cạnh, thì $x,z$ cũng song liên thông cạnh.

Quan hệ song liên thông đỉnh **không** có tính bắc cầu. Phản ví dụ như hình dưới: $A,B$ song liên thông đỉnh, $B,C$ song liên thông đỉnh, nhưng $A,C$ **không** song liên thông đỉnh.

![Phản ví dụ cho tính bắc cầu của song liên thông đỉnh](./images/bcc-0.svg)

Với một đồ thị vô hướng, một đồ thị con song liên thông cạnh **cực đại** được gọi là một **thành phần song liên thông cạnh**.

Với một đồ thị vô hướng, một đồ thị con song liên thông đỉnh **cực đại** được gọi là một **thành phần song liên thông đỉnh**.

## Cây sinh DFS

Với một đồ thị vô hướng liên thông, có thể bắt đầu DFS từ một đỉnh bất kỳ để thu được một cây sinh DFS của đồ thị ban đầu (lấy đỉnh bắt đầu DFS làm gốc). Các cạnh trên cây sinh này được gọi là **cạnh cây**, còn các cạnh không nằm trên cây sinh được gọi là **cạnh ngoài cây**.

Do tính chất của DFS, với mọi cạnh ngoài cây, hai đầu mút của nó trên cây sinh luôn có quan hệ tổ tiên - hậu duệ.

Mã DFS như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        void DFS(int p) {
          visited[p] = true;
          for (int to : edge[p])
            if (!visited[to]) DFS(to);
        }
        ```
    
    === "Python"
        ```python
        def DFS(p):
            visited[p] = True
            for to in edge[p]:
                if visited[to] == False:
                    DFS(to)
        ```

## Thành phần song liên thông cạnh

???+ note "[Bài mẫu: Luogu P8436 [Mẫu] Thành phần song liên thông cạnh](https://www.luogu.com.cn/problem/P8436)"
    Cho một đồ thị vô hướng có $n$ đỉnh và $m$ cạnh. In ra số lượng thành phần song liên thông cạnh, đồng thời in ra từng thành phần song liên thông cạnh.

### Thuật toán Tarjan 1

Quá trình dùng Tarjan để tìm thành phần song liên thông tương tự như khi tìm thành phần liên thông mạnh. Có thể đọc trước thuật toán Tarjan ở trang [thành phần liên thông mạnh](./scc.md).

Cách đầu tiên là tìm tất cả các cầu, sau đó dùng DFS để tìm các thành phần song liên thông cạnh.

Cách tìm cầu có thể xem ở phần cầu trong trang [đỉnh khớp và cầu](./cut.md).

Độ phức tạp thời gian là $O(n+m)$.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/graph/code/bcc/bcc_1.cpp"
    ```

### Thuật toán Tarjan 2

Trước hết, cần dùng một tính chất quan trọng: trong đồ thị vô hướng, các cạnh xét theo cây sinh DFS chỉ có thể là cạnh cây hoặc cạnh ngoài cây.

Liên hệ với cách tìm thành phần liên thông mạnh: trong đồ thị vô hướng, chỉ cần một thành phần không có cầu, thì trên cây sinh DFS, tất cả các đỉnh của nó đều nằm trong cùng một thành phần liên thông mạnh theo ý nghĩa tương ứng của quá trình DFS.

Ngược lại, một thành phần liên thông mạnh trên cây sinh DFS tương ứng với một thành phần song liên thông cạnh trong đồ thị vô hướng ban đầu.

Do đó, quá trình tìm thành phần song liên thông cạnh thực chất giống với quá trình tìm thành phần liên thông mạnh.

Độ phức tạp thời gian là $O(n+m)$.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/graph/code/bcc/bcc_2.cpp"
    ```

### Thuật toán sai phân

Tương tự thuật toán Tarjan 1, trước tiên tìm tất cả các cầu, rồi dùng sai phân để tìm các thành phần song liên thông cạnh.

Trước hết, chạy DFS trên đồ thị ban đầu.

![Cạnh cây và cạnh ngoài cây trong thuật toán sai phân tìm thành phần song liên thông cạnh](./images/bcc-1.svg)

Như hình trên, các cạnh màu đen và màu xanh lá là cạnh cây, còn các cạnh màu đỏ là cạnh ngoài cây. Hai đầu mút của mỗi cạnh ngoài cây tương ứng duy nhất với một đường đi đơn trên cây gồm các cạnh cây; cạnh ngoài cây này được gọi là **phủ** tất cả các cạnh trên đường đi đơn đó.

Trong hình, các cạnh cây màu xanh lá được **ít nhất** một cạnh ngoài cây phủ, còn các cạnh cây màu đen không được **bất kỳ** cạnh ngoài cây nào phủ.

Vì vậy, **cạnh ngoài cây** và **cạnh cây màu xanh lá** không phải là cầu, còn **cạnh cây màu đen** là cầu.

Trước hết xét một cách làm vét cạn: với mỗi cạnh ngoài cây, lần lượt đánh dấu màu xanh lá cho từng cạnh cây mà nó phủ. Độ phức tạp thời gian là $O(nm)$.

Xét tối ưu bằng sai phân. Với mỗi cạnh ngoài cây, đánh dấu `-1` tại đầu mút có độ sâu nhỏ hơn trên cây, đánh dấu `+1` tại đầu mút có độ sâu lớn hơn trên cây, rồi trong $O(n)$ tính tổng các dấu trong cây con của mỗi đỉnh.

Với một đỉnh $u$, tổng dấu trong cây con của nó bằng số cạnh ngoài cây phủ cạnh cây giữa $u$ và $fa_u$. Nếu giá trị này bằng $0$, thì cạnh cây giữa $u$ và $fa_u$ là **cầu**.

Sau đó dùng DFS để tìm các thành phần song liên thông cạnh.

Độ phức tạp thời gian là $O(n+m)$.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/graph/code/bcc/bcc_4.cpp"
    ```

???+ note "[#2788. CEOI2015 Day1 - Đường ống](https://loj.ac/p/2788)"
    Cho một đồ thị vô hướng có $N$ đỉnh và $M$ cạnh, không bảo đảm liên thông. Xem mỗi thành phần liên thông là một đồ thị con, tìm các cầu trong từng đồ thị con. **Giới hạn bộ nhớ chỉ có 16 MB.**

??? note "Lời giải"
    Đặc điểm quan trọng nhất của bài này là không thể lưu toàn bộ các cạnh.
    
    Có thể tối ưu việc lưu cạnh như sau: nếu một cạnh ngoài cây bị một cạnh ngoài cây khác phủ hoàn toàn, thì cạnh đó là vô dụng.
    
    Chỉ cần dùng DSU để duy trì.

## Thành phần song liên thông đỉnh

???+ note "[Bài mẫu: Luogu P8435 [Mẫu] Thành phần song liên thông đỉnh](https://www.luogu.com.cn/problem/P8435)"
    Cho một đồ thị vô hướng có $n$ đỉnh và $m$ cạnh. In ra số lượng thành phần song liên thông đỉnh, đồng thời in ra từng thành phần song liên thông đỉnh.

### Thuật toán Tarjan

Cần nắm phần đỉnh khớp trước; có thể xem phần đỉnh khớp trong trang [đỉnh khớp và cầu](./cut.md).

Trước hết nêu hai tính chất:

1.  Hai thành phần song liên thông đỉnh có nhiều nhất một đỉnh chung, và đỉnh chung đó là đỉnh khớp.
2.  Với một thành phần song liên thông đỉnh, đỉnh có giá trị dfn nhỏ nhất trong cây tìm kiếm DFS là đỉnh khớp hoặc là gốc cây.

Dựa trên tính chất thứ hai, xét theo từng trường hợp:

1.  Khi đỉnh này là đỉnh khớp, nó là gốc của thành phần song liên thông đỉnh, vì nếu bao gồm cả đỉnh cha của nó thì nó vẫn là đỉnh khớp.
2.  Khi đỉnh này là gốc cây:
    1.  Nếu có từ hai cây con trở lên, nó là một đỉnh khớp.
    2.  Nếu chỉ có một cây con, nó là gốc của một thành phần song liên thông đỉnh.
    3.  Nếu không có cây con nào, nó được xem là một thành phần song liên thông đỉnh.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/graph/code/bcc/bcc_3.cpp"
    ```

### Thuật toán sai phân

![Đồ thị phụ trợ trong thuật toán sai phân tìm thành phần song liên thông đỉnh](./images/bcc-2.svg)

Như hình trên, các cạnh màu đen là cạnh cây, còn các cạnh màu đỏ là cạnh ngoài cây. Hai đầu mút của mỗi cạnh ngoài cây tương ứng duy nhất với một đường đi đơn trên cây gồm các cạnh cây.

Xét một đồ thị mới, trong đó mỗi đỉnh tương ứng với một cạnh cây của đồ thị ban đầu (được biểu diễn bằng đỉnh màu xanh dương trong hình). Với mỗi cạnh ngoài cây của đồ thị ban đầu, nối các đỉnh màu xanh dương tương ứng với tất cả các cạnh trên đường đi đơn của cạnh ngoài cây đó thành một thành phần liên thông trong đồ thị mới (được thể hiện bằng các cạnh màu xanh dương trong hình).

Khi đó, một đỉnh **không phải** là đỉnh khớp khi và chỉ khi tất cả các cạnh kề với nó trong đồ thị ban đầu có các đỉnh màu xanh dương tương ứng trong đồ thị mới **thuộc** cùng một thành phần liên thông.

Hai đỉnh **song liên thông đỉnh** khi và chỉ khi tất cả các cạnh trên đường đi giữa chúng trong cây của đồ thị ban đầu có các đỉnh màu xanh dương tương ứng trong đồ thị mới **thuộc** cùng một thành phần liên thông. Nói cách khác, mỗi thành phần liên thông tạo bởi các đỉnh màu xanh dương trong hình chính là một thành phần song liên thông đỉnh.

Quan hệ liên thông giữa các đỉnh màu xanh dương có thể được duy trì bằng phương pháp sai phân tương tự như khi tìm thành phần song liên thông cạnh. Độ phức tạp thời gian là $O(n+m)$.
