## Giới thiệu

Trước khi đọc nội dung dưới đây, cần nắm phần cơ bản trong [các khái niệm đồ thị](./concept.md).

Liên thông mạnh được định nghĩa như sau: đồ thị có hướng $G$ được gọi là liên thông mạnh nếu hai đỉnh bất kỳ trong $G$ đều đến được nhau.

Thành phần liên thông mạnh (Strongly Connected Components, SCC) là đồ thị con liên thông mạnh cực đại.

Trang này giới thiệu cách tìm các thành phần liên thông mạnh.

## Thuật toán Tarjan

### Dẫn nhập

Robert E. Tarjan (1948\~), sinh tại Pomona, California, Hoa Kỳ, là nhà khoa học máy tính.

Tarjan đã phát minh nhiều thuật toán và cấu trúc dữ liệu.
Không ít thuật toán do ông phát minh được đặt theo tên ông, nên đôi khi dễ nhầm lẫn giữa các thuật toán khác nhau.
Ví dụ: thuật toán Tarjan để tìm các loại thành phần liên thông, thuật toán Tarjan để tìm LCA (Lowest Common Ancestor, tổ tiên chung gần nhất).
Disjoint Set Union, Splay và Toptree cũng do Tarjan phát minh.

Phần này giới thiệu thuật toán Tarjan để tìm thành phần liên thông mạnh trong đồ thị có hướng.

### Cây sinh DFS

Trước khi giới thiệu thuật toán, xét **cây sinh DFS**. Lấy đồ thị có hướng dưới đây làm ví dụ:

![Cây sinh DFS](./images/dfs-tree.svg)

Khi chạy thuật toán DFS trên đồ thị có hướng $G$, do các cạnh có hướng, xuất phát từ một đỉnh đơn lẻ có thể không thăm được toàn bộ các đỉnh trong đồ thị.
Vì vậy, cần duyệt toàn bộ tập đỉnh: với mỗi đỉnh chưa được thăm, khởi động lại một lần DFS.
Trong mỗi lần DFS bắt đầu từ một đỉnh xuất phát, các cạnh cây mà quá trình tìm kiếm đi qua sẽ tạo thành một cây, gọi là **cây sinh DFS**.
Sau khi mọi đỉnh đã được thăm, toàn bộ các cây sinh DFS thu được tạo thành **rừng sinh DFS** của đồ thị có hướng đó.

Cấu trúc cụ thể của cây sinh (và rừng sinh), cũng như cách phân loại cạnh dưới đây, đều phụ thuộc vào cách chọn đỉnh bắt đầu DFS và thứ tự thăm các đỉnh kề.

Các cạnh của đồ thị có hướng $G$ có thể được chia thành bốn loại:

1.  Cạnh cây (tree edge): được biểu diễn bằng cạnh màu đen trong hình minh họa. Mỗi khi quá trình tìm kiếm gặp một đỉnh chưa từng được thăm, một cạnh cây được tạo ra. Các cạnh cây kề nhau tạo thành cây sinh DFS.
2.  Cạnh ngược lên tổ tiên (back edge): còn gọi là cạnh ngược, được biểu diễn bằng cạnh màu đỏ trong hình minh họa (tức $7 \rightarrow 1$).
    Đây là cạnh không thuộc cây, đi từ một đỉnh tới một tổ tiên của nó trong quá trình tìm kiếm.
3.  Cạnh xuôi (forward edge): được biểu diễn bằng cạnh màu xanh lá trong hình minh họa (tức $3 \rightarrow 6$). Đây là cạnh không thuộc cây, đi từ một đỉnh tới một hậu duệ trong cây con của nó trong quá trình tìm kiếm.
4.  Cạnh chéo (cross edge): được biểu diễn bằng cạnh màu xanh dương trong hình minh họa (tức $9 \rightarrow 7$).
    Đây là cạnh đi từ một đỉnh tới một đỉnh đã thăm không phải tổ tiên cũng không phải hậu duệ, tức không thuộc ba loại trên.

Xét quan hệ giữa cây sinh DFS và thành phần liên thông mạnh.

Nếu đỉnh $u$ là đỉnh đầu tiên của một thành phần liên thông mạnh được gặp trong cây tìm kiếm, thì các đỉnh còn lại của thành phần liên thông mạnh đó đều nằm trong cây con gốc $u$ của cây tìm kiếm.
Đỉnh $u$ được gọi là gốc của thành phần liên thông mạnh này.

Chứng minh phản chứng: giả sử có một đỉnh $v$ thuộc thành phần liên thông mạnh đó nhưng không nằm trong cây con gốc $u$.
Khi đó, đường đi từ $u$ tới $v$ phải có một cạnh rời khỏi cây con.
Cạnh như vậy chỉ có thể là cạnh chéo hoặc cạnh ngược lên tổ tiên; cả hai loại cạnh này đều yêu cầu đỉnh được trỏ tới đã được thăm.
Điều này mâu thuẫn với việc $v$ không nằm trong cây con gốc $u$.
Suy ra điều phải chứng minh.

### Dùng thuật toán Tarjan tìm thành phần liên thông mạnh

Thuật toán Tarjan dựa trên [tìm kiếm theo chiều sâu](./dfs.md) trên đồ thị.
Mỗi thành phần liên thông có thể được xem như một cây con trong cây tìm kiếm.
Trong quá trình tìm kiếm, thuật toán duy trì một ngăn xếp và đưa các đỉnh chưa xử lý trong cây tìm kiếm vào ngăn xếp.

Trong thuật toán Tarjan, với mỗi đỉnh $u$ cần duy trì các biến sau:

1.  $\textit{dfn}_u$: thứ tự mà đỉnh $u$ được thăm trong quá trình DFS.
2.  $\textit{low}_u$: giá trị $\textit{dfn}$ nhỏ nhất của một đỉnh đã nằm trong ngăn xếp mà cây con của $u$ có thể lần ngược tới.
    Gọi cây con gốc $u$ là $\textit{Subtree}_u$.
    $\textit{low}_u$ được định nghĩa là giá trị $\textit{dfn}$ nhỏ nhất trong hai nhóm đỉnh.
    Nhóm thứ nhất là các đỉnh thuộc $\textit{Subtree}_u$; nhóm thứ hai là các đỉnh có thể đến được từ $\textit{Subtree}_u$ thông qua một cạnh không nằm trong cây tìm kiếm.

Giá trị dfn của các đỉnh trong cây con của một đỉnh đều lớn hơn dfn của chính đỉnh đó.

Trên một đường đi bắt đầu từ gốc, dfn tăng nghiêm ngặt, còn low không giảm.

Duyệt tất cả các đỉnh trong đồ thị theo thứ tự của thuật toán DFS, duy trì hai biến `dfn` và `low` cho từng đỉnh, đồng thời đưa các đỉnh được thăm vào ngăn xếp.
Mỗi khi tìm được một thành phần liên thông mạnh, lấy khỏi ngăn xếp số đỉnh tương ứng với thành phần đó.
Trong quá trình tìm kiếm, với đỉnh $u$ và một đỉnh kề $v$ của nó, xét ba trường hợp:

1.  $v$ chưa được thăm: tiếp tục DFS từ $v$.
    Trong quá trình quay lui, dùng $\textit{low}_v$ để cập nhật $\textit{low}_u$.
    Vì tồn tại đường đi trực tiếp từ $u$ tới $v$, những đỉnh đã nằm trong ngăn xếp mà $v$ có thể lần ngược tới thì $u$ cũng có thể lần ngược tới.
2.  $v$ đã được thăm và vẫn nằm trong ngăn xếp: theo định nghĩa của giá trị low, dùng $\textit{dfn}_v$ để cập nhật $\textit{low}_u$.
3.  $v$ đã được thăm nhưng không còn nằm trong ngăn xếp: điều này cho biết quá trình tìm kiếm ở $v$ đã kết thúc và thành phần liên thông chứa $v$ đã được xử lý, nên không cần thao tác gì thêm.

Viết thuật toán trên thành giả mã:

???+ note "Cài đặt"
    ```text
    TARJAN_SEARCH(int u)
        vis[u]=true
        low[u]=dfn[u]=++dfncnt
        đưa u vào ngăn xếp
        với mỗi (u,v) thì
            nếu v chưa được tìm kiếm thì
                TARJAN_SEARCH(v) // Tìm kiếm
                low[u]=min(low[u],low[v]) // Quay lui
            ngược lại nếu v đang nằm trong ngăn xếp thì
                low[u]=min(low[u],dfn[v])
    ```

Với một thành phần liên thông mạnh, có đúng một đỉnh $u$ sao cho $\textit{dfn}_u=\textit{low}_u$.
Đỉnh này là đỉnh đầu tiên của thành phần liên thông mạnh đó được thăm trong quá trình DFS, vì dfn và low của nó là nhỏ nhất, không bị các đỉnh khác trong cùng thành phần liên thông mạnh làm giảm thêm.

Do đó, trong quá trình quay lui, cần kiểm tra điều kiện $\textit{dfn}_u=\textit{low}_u$. Nếu điều kiện này đúng, thì $u$ cùng các đỉnh nằm phía trên $u$ trong ngăn xếp tạo thành một SCC.

### Cài đặt

=== "C++"
    ```cpp
    int dfn[N], low[N], dfncnt, s[N], in_stack[N], tp;
    int scc[N], sc;  // Số hiệu SCC chứa đỉnh i
    int sz[N];       // Kích thước của thành phần liên thông mạnh i
    
    void tarjan(int u) {
      low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
      for (int i = h[u]; i; i = e[i].nex) {
        const int &v = e[i].t;
        if (!dfn[v]) {
          tarjan(v);
          low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
          low[u] = min(low[u], dfn[v]);
        }
      }
      if (dfn[u] == low[u]) {
        ++sc;
        do {
          scc[s[tp]] = sc;
          sz[sc]++;
          in_stack[s[tp]] = 0;
        } while (s[tp--] != u);
      }
    }
    ```

=== "Python"
    ```python
    dfn = [0] * N
    low = [0] * N
    dfncnt = 0
    s = [0] * N
    in_stack = [0] * N
    tp = 0
    scc = [0] * N
    sc = 0  # Số hiệu SCC chứa đỉnh i
    sz = [0] * N  # Kích thước của thành phần liên thông mạnh i
    
    
    def tarjan(u):
        low[u] = dfn[u] = dfncnt
        s[tp] = u
        in_stack[u] = 1
        dfncnt = dfncnt + 1
        tp = tp + 1
        i = h[u]
        while i:
            v = e[i].t
            if dfn[v] == False:
                tarjan(v)
                low[u] = min(low[u], low[v])
            elif in_stack[v]:
                low[u] = min(low[u], dfn[v])
            i = e[i].nex
        if dfn[u] == low[u]:
            sc = sc + 1
            while s[tp] != u:
                scc[s[tp]] = sc
                sz[sc] = sz[sc] + 1
                in_stack[s[tp]] = 0
                tp = tp - 1
            scc[s[tp]] = sc
            sz[sc] = sz[sc] + 1
            in_stack[s[tp]] = 0
            tp = tp - 1
    ```

Độ phức tạp thời gian là $O(n + m)$.

### Quan hệ giữa số hiệu thành phần và thứ tự tô pô

Trong quá trình xử lý, thuật toán Tarjan phát hiện các thành phần liên thông mạnh theo một dạng **thứ tự tô pô ngược**.
Lý do là khi DFS, thuật toán sẽ xử lý xong trước các đỉnh không có cạnh đi ra, trái với quá trình sắp xếp tô pô.

Nếu co mỗi thành phần liên thông mạnh trong đồ thị thành một đỉnh đơn, thì trên DAG tạo bởi các đỉnh sau khi co, thứ tự sắp xếp tô pô sẽ ngược với thứ tự đánh số thành phần liên thông mạnh mà thuật toán Tarjan tạo ra.

Vì vậy, trong DAG sau khi co, **thứ tự số hiệu của các thành phần liên thông mạnh (sau khi co) là thứ tự ngược của thứ tự tô pô**.
Tuy nhiên, phát biểu này chỉ đúng khi xét quan hệ phụ thuộc giữa các thành phần liên thông mạnh, tức các cạnh có hướng đi từ một thành phần liên thông mạnh tới thành phần liên thông mạnh khác.
Các đỉnh bên trong một thành phần liên thông mạnh có chu trình, nên nội bộ thành phần không thỏa định nghĩa thứ tự tô pô.

## Thuật toán Kosaraju

### Dẫn nhập

Thuật toán Kosaraju được S. Rao Kosaraju đề xuất sớm nhất vào năm 1978 trong một bài báo chưa xuất bản, còn Micha Sharir là người công bố đầu tiên.

### Quy trình

Thuật toán này dựa vào hai lần DFS đơn giản:

Lần DFS thứ nhất chọn một đỉnh bất kỳ làm điểm bắt đầu, duyệt mọi đỉnh chưa được thăm, và đánh số đỉnh trước khi quay lui, tức duyệt hậu tự.

Lần DFS thứ hai chạy trên đồ thị đảo chiều, chọn đỉnh có số hiệu lớn nhất làm điểm bắt đầu DFS.
Tập đỉnh được duyệt tới theo cách này chính là một thành phần liên thông mạnh.
Với mọi đỉnh chưa được thăm, tiếp tục chọn đỉnh có số hiệu lớn nhất và lặp lại quy trình trên.

Sau hai lần DFS, tìm được các thành phần liên thông mạnh. Độ phức tạp thời gian của thuật toán Kosaraju là $O(n+m)$.

### Cài đặt

=== "C++"
    ```cpp
    // g là đồ thị gốc, g2 là đồ thị đảo
    
    void dfs1(int u) {
      vis[u] = true;
      for (int v : g[u])
        if (!vis[v]) dfs1(v);
      s.push_back(u);
    }
    
    void dfs2(int u) {
      color[u] = sccCnt;
      for (int v : g2[u])
        if (!color[v]) dfs2(v);
    }
    
    void kosaraju() {
      sccCnt = 0;
      for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs1(i);
      for (int i = n; i >= 1; --i)
        if (!color[s[i]]) {
          ++sccCnt;
          dfs2(s[i]);
        }
    }
    ```

=== "Python"
    ```python
    def dfs1(u):
        vis[u] = True
        for v in g[u]:
            if vis[v] == False:
                dfs1(v)
        s.append(u)
    
    
    def dfs2(u):
        color[u] = sccCnt
        for v in g2[u]:
            if color[v] == False:
                dfs2(v)
    
    
    def kosaraju(u):
        sccCnt = 0
        for i in range(1, n + 1):
            if vis[i] == False:
                dfs1(i)
        for i in range(n, 0, -1):
            if color[s[i]] == False:
                sccCnt = sccCnt + 1
                dfs2(s[i])
    ```

## Thuật toán Garbow

### Quy trình

Thuật toán Garbow là một cách cài đặt khác của thuật toán Tarjan.
Tarjan dùng dfn và low để tính gốc của thành phần liên thông mạnh.
Garbow duy trì một ngăn xếp đỉnh, đồng thời dùng một ngăn xếp thứ hai để xác định khi nào cần lấy khỏi ngăn xếp thứ nhất các đỉnh thuộc cùng một thành phần liên thông mạnh.
Trong quá trình DFS bắt đầu từ đỉnh $w$, khi một đường đi cho thấy nhóm đỉnh này đều thuộc cùng một thành phần liên thông mạnh, chỉ cần lấy khỏi ngăn xếp thứ hai một số phần tử.
Các phần tử bị lấy ra là những phần tử trên đỉnh ngăn xếp có thời điểm thăm lớn hơn thời điểm thăm của gốc $w$.
Cuối cùng chỉ còn lại gốc $w$.
Trong quá trình này, mọi đỉnh bị lấy ra đều thuộc cùng một thành phần liên thông mạnh.

Khi quay lui tới một đỉnh $w$, nếu đỉnh này nằm ở đỉnh của ngăn xếp thứ hai, điều đó cho biết đỉnh này là đỉnh bắt đầu của một thành phần liên thông mạnh.
Các đỉnh được thăm sau đỉnh này đều thuộc cùng một thành phần liên thông mạnh, vì vậy cần lấy các đỉnh đó khỏi ngăn xếp thứ nhất để tạo thành thành phần liên thông mạnh.

### Cài đặt

=== "C++"
    ```cpp
    int garbow(int u) {
      stack1[++p1] = u;
      stack2[++p2] = u;
      low[u] = ++dfs_clock;
      for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (!low[v])
          garbow(v);
        else if (!sccno[v])
          while (low[stack2[p2]] > low[v]) p2--;
      }
      if (stack2[p2] == u) {
        p2--;
        scc_cnt++;
        do {
          sccno[stack1[p1]] = scc_cnt;
          // all_scc[scc_cnt] ++;
        } while (stack1[p1--] != u);
      }
      return 0;
    }
    
    void find_scc(int n) {
      dfs_clock = scc_cnt = 0;
      p1 = p2 = 0;
      memset(sccno, 0, sizeof(sccno));
      memset(low, 0, sizeof(low));
      for (int i = 1; i <= n; i++)
        if (!low[i]) garbow(i);
    }
    ```

=== "Python"
    ```python
    def garbow(u):
        stack1[p1] = u
        stack2[p2] = u
        p1 = p1 + 1
        p2 = p2 + 1
        low[u] = dfs_clock
        dfs_clock = dfs_clock + 1
        i = head[u]
        while i:
            v = e[i].to
            if low[v] == False:
                garbow(v)
            elif sccno[v] == False:
                while low[stack2[p2]] > low[v]:
                    p2 = p2 - 1
        if stack2[p2] == u:
            p2 = p2 - 1
            scc_cnt = scc_cnt + 1
            while stack1[p1] != u:
                p1 = p1 - 1
                sccno[stack1[p1]] = scc_cnt
    
    
    def find_scc(n):
        dfs_clock = scc_cnt = 0
        p1 = p2 = 0
        sccno = []
        low = []
        for i in range(1, n + 1):
            if low[i] == False:
                garbow(i)
    ```

## Ứng dụng

Có thể co mỗi thành phần liên thông mạnh của một đồ thị thành một đỉnh.

Khi đó đồ thị sẽ trở thành một DAG, nên có thể sắp xếp tô pô và thực hiện nhiều thao tác khác.

Một ví dụ đơn giản: tìm một đường đi có thể đi qua các đỉnh lặp lại, sao cho số lượng đỉnh phân biệt đã đi qua là lớn nhất.

## Bài tập

[USACO Fall/HAOI 2006 Những con bò được yêu thích](https://loj.ac/problem/10091)

[POJ1236 Network of Schools](http://poj.org/problem?id=1236)
