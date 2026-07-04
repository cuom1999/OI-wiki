author: Ir1d, greyqz, yjl9903, partychicken, ChungZH, qq1010903229, Marcythm, Acfboy, shenshuaijie, Craneplayz

## Giới thiệu

DFS là viết tắt của [Depth First Search](https://en.wikipedia.org/wiki/Depth-first_search), tức tìm kiếm theo chiều sâu. Đây là một thuật toán dùng để duyệt hoặc tìm kiếm trên cây hay đồ thị. "Theo chiều sâu" có nghĩa là mỗi lần thuật toán đều cố gắng đi tới một đỉnh sâu hơn.

Khi được giới thiệu, thuật toán này thường được đặt cạnh BFS. Tuy nhiên, ngoài việc cả hai đều có thể duyệt một thành phần liên thông của đồ thị, mục đích sử dụng của chúng rất khác nhau, và hiếm khi có trường hợp hai thuật toán có thể dùng thay thế lẫn nhau.

DFS thường được dùng để chỉ kiểu tìm kiếm cài đặt bằng hàm đệ quy, nhưng thực ra hai khái niệm này không hoàn toàn giống nhau. Về tư tưởng tìm kiếm dạng đó, hãy xem [DFS trong tìm kiếm](../search/dfs.md).

## Quy trình

Đặc trưng rõ nhất của DFS là **tự gọi đệ quy**. Đồng thời, tương tự BFS, DFS sẽ đánh dấu các đỉnh đã thăm và bỏ qua những đỉnh đã được đánh dấu khi duyệt đồ thị, nhằm bảo đảm **mỗi đỉnh chỉ được thăm một lần**. Một hàm thỏa hai quy tắc trên có thể được xem là DFS theo nghĩa rộng.

Nói cụ thể hơn, DFS có cấu trúc đại khái như sau:

    DFS(v) // v có thể là một đỉnh của đồ thị, hoặc một khái niệm trừu tượng như trạng thái dp.
      Đánh dấu v là đã thăm
      for u in các đỉnh kề của v
        if u chưa được đánh dấu là đã thăm then
          DFS(u)
        end
      end
    end

Đoạn giả mã trên chỉ chứa cấu trúc chính bắt buộc của DFS. Trong cài đặt thực tế, ta thường bổ sung thêm một số thao tác dựa trên các tính chất của DFS.

## Tính chất

Thuật toán này thường có độ phức tạp thời gian $O(n+m)$ và độ phức tạp bộ nhớ $O(n)$, trong đó $n$ là số đỉnh và $m$ là số cạnh. Lưu ý rằng độ phức tạp bộ nhớ bao gồm cả bộ nhớ ngăn xếp, mà phần này có độ phức tạp $O(n)$. Độ phức tạp thời gian trên chỉ đạt được khi việc duyệt một cạnh mất trung bình $O(1)$, chẳng hạn khi lưu đồ thị bằng forward star hoặc danh sách kề; nếu dùng ma trận kề thì chưa chắc đạt được độ phức tạp này.

> Ghi chú: Hiện nay, phần lớn các kỳ thi lập trình thuật toán, bao gồm NOIP, đa số kỳ chọn đội cấp tỉnh và các cuộc thi do CCF tổ chức, đều hỗ trợ **không giới hạn riêng bộ nhớ ngăn xếp**. Nghĩa là bộ nhớ ngăn xếp không bị giới hạn tách biệt, nhưng tổng bộ nhớ vẫn chịu giới hạn của đề bài. Tuy vậy, hầu hết hệ điều hành sẽ đặt thêm giới hạn cho bộ nhớ ngăn xếp, vì thế khi gỡ lỗi cục bộ cần dùng một số cách để gỡ giới hạn này.
>
> -   Trên Windows, cách thông dụng là thêm `-Wl,--stack=1000000000` vào **tùy chọn biên dịch**, nghĩa là đặt giới hạn bộ nhớ ngăn xếp thành 1000000000 byte.
> -   Trên Linux, cách thông dụng là chạy `ulimit -s unlimited` **trong terminal** trước khi chạy chương trình, nghĩa là đặt bộ nhớ ngăn xếp thành không giới hạn. Mỗi terminal chỉ cần thực hiện một lần, và lệnh sẽ có hiệu lực với mọi lần chạy chương trình sau đó trong terminal ấy.

## Cài đặt

### Cài đặt bằng ngăn xếp

DFS có thể được cài đặt bằng cách dùng [ngăn xếp (Stack)](../ds/stack.md) làm nơi tạm lưu các đỉnh trong quá trình duyệt; cách này tương ứng chặt chẽ với BFS cài đặt bằng [hàng đợi (Queue)](../ds/queue.md).

=== "C++"
    ```cpp
    vector<vector<int>> adj;  // Danh sách kề
    vector<bool> vis;         // Ghi nhận đỉnh đã được duyệt hay chưa
    
    void dfs(int s) {
      stack<int> st;
      st.push(s);
      vis[s] = true;
    
      while (!st.empty()) {
        int u = st.top();
        st.pop();
    
        for (int v : adj[u]) {
          if (!vis[v]) {
            vis[v] = true;  // Bảo đảm trong ngăn xếp không có phần tử trùng
            st.push(v);
          }
        }
      }
    }
    ```

=== "Python"
    ```python
    # adj : List[List[int]] Danh sách kề
    # vis : List[bool] Ghi nhận đỉnh đã được duyệt hay chưa
    
    
    def dfs(s: int) -> None:
        stack = [s]  # Dùng list mô phỏng ngăn xếp, đưa đỉnh bắt đầu vào ngăn xếp
        vis[s] = True  # Đỉnh bắt đầu đã được duyệt
    
        while stack:  # Tiếp tục khi ngăn xếp chưa rỗng
            u = (
                stack.pop()
            )  # Lấy và loại bỏ phần tử cuối cùng, tức phần tử ở đỉnh ngăn xếp
    
            for v in adj[u]:  # Với mỗi đỉnh v kề với u
                if not vis[v]:  # Nếu trước đó chưa đi qua v
                    vis[v] = True  # Bảo đảm trong ngăn xếp không có phần tử trùng
                    stack.append(v)  # Đưa v vào ngăn xếp
    ```

### Cài đặt bằng đệ quy

Khi một hàm được gọi đệ quy, thứ tự tính toán tương tự thứ tự thêm và xóa phần tử trên ngăn xếp. Vì vậy vùng địa chỉ ảo mà các lời gọi hàm chiếm giữ được gọi là ngăn xếp lời gọi hàm (Call Stack), và DFS có thể được cài đặt bằng đệ quy.

Với cách lưu đồ thị bằng [danh sách kề (Adjacency List)](./save.md#danh-sách-kề):

=== "C++"
    ```cpp
    vector<vector<int>> adj;  // Danh sách kề
    vector<bool> vis;         // Ghi nhận đỉnh đã được duyệt hay chưa
    
    void dfs(const int u) {
      vis[u] = true;
      for (int v : adj[u])
        if (!vis[v]) dfs(v);
    }
    ```

=== "Python"
    ```python
    # adj : List[List[int]] Danh sách kề
    # vis : List[bool] Ghi nhận đỉnh đã được duyệt hay chưa
    
    
    def dfs(u: int) -> None:
        vis[u] = True
        for v in adj[u]:
            if not vis[v]:
                dfs(v)
    ```

Lấy [forward star dạng liên kết](./save.md#forward-star-dạng-liên-kết) làm ví dụ:

=== "C++"
    ```cpp
    void dfs(int u) {
      vis[u] = 1;
      for (int i = head[u]; i; i = e[i].x) {
        if (!vis[e[i].t]) {
          dfs(e[i].t);
        }
      }
    }
    ```

=== "Java"
    ```Java
    public void dfs(int u) {
        vis[u] = true;
        for (int i = head[u]; i != 0; i = e[i].x) {
            if (!vis[e[i].t]) {
                dfs(e[i].t);
            }
        }
    }
    ```

=== "Python"
    ```python
    def dfs(u):
        vis[u] = True
        i = head[u]
        while i:
            if vis[e[i].t] == False:
                dfs(e[i].t)
            i = e[i].x
    ```

### Dãy DFS

Dãy DFS là dãy các số hiệu đỉnh được thăm trong quá trình gọi DFS.

Ta có thể thấy mỗi cây con tương ứng với một đoạn liên tiếp, tức một khoảng, trong dãy DFS.

### Dãy ngoặc

Khi DFS đi vào một đỉnh, ghi lại một ngoặc trái `(`; khi thoát khỏi đỉnh đó, ghi lại một ngoặc phải `)`.

Mỗi đỉnh sẽ xuất hiện hai lần. Độ sâu của hai đỉnh kề nhau trong dãy chênh lệch 1.

### DFS trên đồ thị tổng quát

Với đồ thị không liên thông, DFS chỉ có thể thăm được thành phần liên thông chứa đỉnh bắt đầu.

Với đồ thị liên thông, dãy DFS thường không duy nhất.

Chú ý: dãy DFS của cây cũng không duy nhất.

Trong quá trình DFS, bằng cách ghi lại mỗi đỉnh được thăm từ đỉnh nào, ta có thể xây dựng một cấu trúc cây gọi là cây DFS. Cây DFS là một cây khung của đồ thị ban đầu.

[Cây DFS](./scc.md#cây-sinh-dfs) có nhiều tính chất, chẳng hạn có thể dùng để tìm [thành phần liên thông mạnh](./scc.md).
