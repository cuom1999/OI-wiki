author: Ir1d, sshwy, Xeonacid, partychicken, Anguei, HeRaNO

Trong OI, muốn thao tác trên đồ thị thì trước hết cần học các cách lưu trữ đồ thị.

## Quy ước

Bài viết này mặc định rằng người đọc đã đọc và hiểu các nội dung cơ bản trong [các khái niệm liên quan đến lý thuyết đồ thị](./concept.md). Nếu gặp khó khăn khi đọc, cũng có thể tra cứu lại trong [các khái niệm liên quan đến lý thuyết đồ thị](./concept.md).

Trong bài viết này, dùng $n$ để chỉ số đỉnh của đồ thị, $m$ để chỉ số cạnh của đồ thị, và $d^+(u)$ để chỉ bậc ra của đỉnh $u$, tức số cạnh lấy $u$ làm đỉnh xuất phát.

## Lưu cạnh trực tiếp

### Phương pháp

Dùng một mảng để lưu các cạnh, trong đó mỗi phần tử của mảng đều chứa đỉnh đầu và đỉnh cuối của một cạnh. Với đồ thị có trọng số cạnh, phần tử còn chứa cả trọng số cạnh. Cũng có thể dùng nhiều mảng để lần lượt lưu đỉnh đầu, đỉnh cuối và trọng số cạnh.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        #include <iostream>
        #include <vector>
        
        using namespace std;
        
        struct Edge {
          int u, v;
        };
        
        int n, m;
        vector<Edge> e;
        vector<bool> vis;
        
        bool find_edge(int u, int v) {
          for (int i = 1; i <= m; ++i) {
            if (e[i].u == u && e[i].v == v) {
              return true;
            }
          }
          return false;
        }
        
        void dfs(int u) {
          if (vis[u]) return;
          vis[u] = true;
          for (int i = 1; i <= m; ++i) {
            if (e[i].u == u) {
              dfs(e[i].v);
            }
          }
        }
        
        int main() {
          cin >> n >> m;
        
          vis.resize(n + 1, false);
          e.resize(m + 1);
        
          for (int i = 1; i <= m; ++i) cin >> e[i].u >> e[i].v;
        
          return 0;
        }
        ```
    
    === "Python"
        ```python
        class Edge:
            def __init__(self, u=0, v=0):
                self.u = u
                self.v = v
        
        
        n, m = map(int, input().split())
        
        e = [Edge() for _ in range(m)]
        vis = [False] * n
        
        for i in range(m):
            e[i].u, e[i].v = map(int, input().split())
        
        
        def find_edge(u, v):
            for i in range(m):
                if e[i].u == u and e[i].v == v:
                    return True
            return False
        
        
        def dfs(u):
            if vis[u]:
                return
            vis[u] = True
            for i in range(m):
                if e[i].u == u:
                    dfs(e[i].v)
        ```

### Độ phức tạp

Truy vấn xem một cạnh nào đó có tồn tại hay không: $O(m)$.

Duyệt tất cả các cạnh đi ra từ một đỉnh: $O(m)$.

Duyệt toàn bộ đồ thị: $O(nm)$.

Độ phức tạp không gian: $O(m)$.

### Ứng dụng

Do hiệu suất duyệt của cách lưu cạnh trực tiếp thấp, thông thường không dùng nó để duyệt đồ thị.

Trong [thuật toán Kruskal](./mst.md#thuật-toán-kruskal), do cần sắp xếp các cạnh theo trọng số, cần lưu cạnh trực tiếp.

Trong một số bài toán, cần xây dựng đồ thị nhiều lần, chẳng hạn xây một lần đồ thị gốc và một lần đồ thị đảo. Khi đó có thể dùng nhiều cấu trúc dữ liệu khác để lưu đồng thời nhiều đồ thị, hoặc cũng có thể lưu trực tiếp các cạnh rồi dùng các cạnh đã lưu để xây lại đồ thị khi cần.

## Ma trận kề

### Phương pháp

Dùng một mảng hai chiều `adj` để lưu cạnh, trong đó `adj[u][v]` bằng 1 biểu thị tồn tại cạnh từ $u$ đến $v$, bằng 0 biểu thị không tồn tại. Nếu là đồ thị có trọng số cạnh, có thể lưu trọng số của cạnh từ $u$ đến $v$ trong `adj[u][v]`.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        #include <iostream>
        #include <vector>
        
        using namespace std;
        
        int n, m;
        vector<bool> vis;
        vector<vector<bool>> adj;
        
        bool find_edge(int u, int v) { return adj[u][v]; }
        
        void dfs(int u) {
          if (vis[u]) return;
          vis[u] = true;
          for (int v = 1; v <= n; ++v) {
            if (adj[u][v]) {
              dfs(v);
            }
          }
        }
        
        int main() {
          cin >> n >> m;
        
          vis.resize(n + 1);
          adj.resize(n + 1, vector<bool>(n + 1));
        
          for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = true;
          }
        
          return 0;
        }
        ```
    
    === "Python"
        ```python
        vis = [False] * (n + 1)
        adj = [[False] * (n + 1) for _ in range(n + 1)]
        
        for i in range(1, m + 1):
            u, v = map(lambda x: int(x), input().split())
            adj[u][v] = True
        
        
        def find_edge(u, v):
            return adj[u][v]
        
        
        def dfs(u):
            if vis[u]:
                return
            vis[u] = True
            for v in range(1, n + 1):
                if adj[u][v]:
                    dfs(v)
        ```

### Độ phức tạp

Truy vấn xem một cạnh nào đó có tồn tại hay không: $O(1)$.

Duyệt tất cả các cạnh đi ra từ một đỉnh: $O(n)$.

Duyệt toàn bộ đồ thị: $O(n^2)$.

Độ phức tạp không gian: $O(n^2)$.

### Ứng dụng

Ma trận kề chỉ phù hợp với trường hợp không có cạnh song song, hoặc cạnh song song có thể bỏ qua.

Ưu điểm nổi bật nhất của nó là có thể truy vấn sự tồn tại của một cạnh trong $O(1)$.

Do ma trận kề rất kém hiệu quả trên đồ thị thưa, đặc biệt với đồ thị có nhiều đỉnh thì không gian không thể chịu nổi, nên thông thường chỉ dùng ma trận kề trên đồ thị dày.

## Danh sách kề

### Phương pháp

Dùng một mảng gồm các cấu trúc dữ liệu hỗ trợ thêm phần tử động, chẳng hạn `vector<int> adj[n + 1]`, để lưu cạnh. Trong đó `adj[u]` lưu các thông tin liên quan đến tất cả các cạnh đi ra từ đỉnh $u$, như đỉnh cuối, trọng số cạnh, v.v.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        #include <iostream>
        #include <vector>
        
        using namespace std;
        
        int n, m;
        vector<bool> vis;
        vector<vector<int>> adj;
        
        bool find_edge(int u, int v) {
          for (int i = 0; i < adj[u].size(); ++i) {
            if (adj[u][i] == v) {
              return true;
            }
          }
          return false;
        }
        
        void dfs(int u) {
          if (vis[u]) return;
          vis[u] = true;
          for (int i = 0; i < adj[u].size(); ++i) dfs(adj[u][i]);
        }
        
        int main() {
          cin >> n >> m;
        
          vis.resize(n + 1);
          adj.resize(n + 1);
        
          for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
          }
        
          return 0;
        }
        ```
    
    === "Python"
        ```python
        vis = [False] * (n + 1)
        adj = [[] for _ in range(n + 1)]
        
        for i in range(1, m + 1):
            u, v = map(lambda x: int(x), input().split())
            adj[u].append(v)
        
        
        def find_edge(u, v):
            for i in range(0, len(adj[u])):
                if adj[u][i] == v:
                    return True
            return False
        
        
        def dfs(u):
            if vis[u]:
                return
            vis[u] = True
            for i in range(0, len(adj[u])):
                dfs(adj[u][i])
        ```

### Độ phức tạp

Truy vấn xem có cạnh từ $u$ đến $v$ hay không: $O(d^+(u))$. Nếu đã sắp xếp từ trước thì có thể dùng [tìm kiếm nhị phân](../basic/binary.md) để đạt $O(\log(d^+(u)))$.

Duyệt tất cả các cạnh đi ra từ đỉnh $u$: $O(d^+(u))$.

Duyệt toàn bộ đồ thị: $O(n+m)$.

Độ phức tạp không gian: $O(m)$.

### Ứng dụng

Rất phù hợp để lưu nhiều loại đồ thị, trừ khi có nhu cầu đặc biệt, chẳng hạn cần truy vấn nhanh sự tồn tại của một cạnh và số đỉnh nhỏ, khi đó có thể dùng ma trận kề.

Đặc biệt phù hợp với các trường hợp cần sắp xếp tất cả các cạnh đi ra từ một đỉnh.

## Forward star dạng liên kết

### Phương pháp

Về bản chất, đây là danh sách kề được cài đặt bằng danh sách liên kết. Mã cốt lõi như sau:

=== "C++"
    ```cpp
    // Giá trị ban đầu của head[u] và cnt đều là -1
    void add(int u, int v) {
      nxt[++cnt] = head[u];  // Cạnh kế tiếp của cạnh hiện tại
      head[u] = cnt;         // Cạnh đầu tiên xuất phát từ u
      to[cnt] = v;           // Đỉnh cuối của cạnh hiện tại
    }
    
    // Duyệt các cạnh đi ra từ u
    for (int i = head[u]; ~i; i = nxt[i]) {  // ~i biểu thị i != -1
      int v = to[i];
    }
    ```

=== "Python"
    ```python
    # Giá trị ban đầu của head[u] và cnt đều là -1
    def add(u, v):
        cnt = cnt + 1
        nex[cnt] = head[u]  # Cạnh kế tiếp của cạnh hiện tại
        head[u] = cnt  # Cạnh đầu tiên xuất phát từ u
        to[cnt] = v  # Đỉnh cuối của cạnh hiện tại
    
    # Duyệt các cạnh đi ra từ u
    i = head[u]
    while ~i:  # ~i biểu thị i != -1
        v = to[i]
        i = nxt[i]
    ```

??? note "Mã tham khảo"
    ```cpp
    #include <iostream>
    #include <vector>
    
    using namespace std;
    
    int n, m;
    vector<bool> vis;
    vector<int> head, nxt, to;
    
    void add(int u, int v) {
      nxt.push_back(head[u]);
      head[u] = to.size();
      to.push_back(v);
    }
    
    bool find_edge(int u, int v) {
      for (int i = head[u]; ~i; i = nxt[i]) {  // ~i biểu thị i != -1
        if (to[i] == v) {
          return true;
        }
      }
      return false;
    }
    
    void dfs(int u) {
      if (vis[u]) return;
      vis[u] = true;
      for (int i = head[u]; ~i; i = nxt[i]) dfs(to[i]);
    }
    
    int main() {
      cin >> n >> m;
    
      vis.resize(n + 1, false);
      head.resize(n + 1, -1);
    
      for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v);
      }
    
      return 0;
    }
    ```

### Độ phức tạp

Truy vấn xem có cạnh từ $u$ đến $v$ hay không: $O(d^+(u))$.

Duyệt tất cả các cạnh đi ra từ đỉnh $u$: $O(d^+(u))$.

Duyệt toàn bộ đồ thị: $O(n+m)$.

Độ phức tạp không gian: $O(m)$.

### Ứng dụng

Rất phù hợp để lưu nhiều loại đồ thị, nhưng không thể truy vấn nhanh sự tồn tại của một cạnh, cũng không tiện sắp xếp các cạnh đi ra từ một đỉnh.

Ưu điểm là các cạnh có đánh số, đôi khi rất hữu ích. Ngoài ra, nếu giá trị ban đầu của `cnt` là số lẻ, khi lưu cạnh hai chiều thì `i ^ 1` chính là cạnh ngược của `i`, điều này thường dùng trong [luồng mạng](./flow.md).
