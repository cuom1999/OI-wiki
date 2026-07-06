## Giới thiệu

???+ question "Bài toán"
    Cho một đồ thị. Hỏi chu trình có tổng trọng số cạnh nhỏ nhất, gồm $n$ đỉnh $(n\ge 3)$, có độ dài bằng bao nhiêu.

Chu trình nhỏ nhất của đồ thị cũng được gọi là girth.

## Quy trình

### Cách làm vét cạn

Giả sử giữa $u$ và $v$ có một cạnh độ dài $w$, và $dis(u,v)$ biểu thị đường đi ngắn nhất từ $u$ đến $v$ sau khi xóa cạnh nối $u$ và $v$.

Khi đó chu trình nhỏ nhất trong đồ thị vô hướng là $dis(u,v)+w$.

Lưu ý, nếu cần tìm chu trình nhỏ nhất trong đồ thị có hướng thì công thức tương ứng cần đổi thành $dis(v,u)+w$.

Tổng độ phức tạp thời gian là $O(n^2m)$.

### Dijkstra

Liên kết liên quan: [Đường đi ngắn nhất/Dijkstra](./shortest-path.md#thuật-toán-dijkstra)

#### Quy trình

Liệt kê mọi cạnh. Mỗi lần xóa một cạnh, rồi chạy Dijkstra từ đỉnh đầu của cạnh đó. Ý tưởng giống như trên.

#### Tính chất

Độ phức tạp thời gian là $O(m(n+m)\log n)$.

### Floyd

Liên kết liên quan: [Đường đi ngắn nhất/Floyd](./shortest-path.md#thuật-toán-floyd)

#### Quy trình

Ký hiệu trọng số cạnh giữa $u,v$ trong đồ thị ban đầu là $val\left(u,v\right)$.

Cần chú ý đến một tính chất của thuật toán Floyd: khi vòng lặp ngoài cùng đến đỉnh $k$ (trước khi bắt đầu lần lặp thứ $k$), trong mảng đường đi ngắn nhất $dis$, $dis_{u,v}$ biểu thị đường đi ngắn nhất từ $u$ đến $v$ chỉ đi qua các đỉnh có chỉ số nằm trong đoạn $\left[1, k\right)$.

Theo định nghĩa của chu trình nhỏ nhất, nó có ít nhất ba đỉnh. Giả sử đỉnh có chỉ số lớn nhất trên chu trình là $w$, hai đỉnh kề với $w$ ở hai phía của chu trình là $u,v$. Khi vòng lặp ngoài cùng liệt kê đến $k=w$, độ dài chu trình này chính là $dis_{u,v}+val\left(v,w\right)+val\left(w,u\right)$.

Vì vậy, trong khi lặp, với mỗi $k$ liệt kê các cặp $(i,j)$ thỏa mãn $i<k,j<k$ và cập nhật đáp án.

#### Ghi lại đường đi

Lúc này đã biết dạng của chu trình là $u\to k\to v$, sau đó đi từ $v$ về $u$ (các đỉnh đi qua đều có chỉ số $<k$).

Bài toán chuyển thành tìm đường đi $v\leadsto u$. Theo bất đẳng thức tam giác $dis_{u,v}\le dis_{u,i}+dis_{i,v}$, xét việc ghi lại $pos_{u,v}=j$, biểu thị đỉnh làm cho $dis_{u,v}=dis_{u,j}+dis_{j,v}$. Khi đó $j$ nằm trên đường đi $v\leadsto u$.

Do đó có thể tách đường đi thành hai đoạn $v\leadsto j$ và $j\leadsto u$, rồi đệ quy xử lý từng đoạn.

???+ note "Chứng minh đệ quy không rơi vào vòng lặp vô hạn"
    Dùng phản chứng.
    
    Giả sử chu trình lặp lại một đỉnh $u$. Khi đó trên chu trình chắc chắn có một đoạn xuất phát từ $u$, đi qua một số cạnh rồi quay lại $u$. Đoạn này tạo thành một chu trình mới.
    
    Vì trong đồ thị không có chu trình âm (nếu có chu trình âm thì sẽ không tồn tại chu trình nhỏ nhất), tổng trọng số của chu trình mới chắc chắn không lớn hơn chu trình ban đầu.
    
    Vì thế chỉ cần lấy riêng chu trình này thì sẽ không lặp lại đỉnh $u$. Giả thiết không đúng, nên chu trình không lặp lại một đỉnh.
    
    Do đó khi đệ quy đến hai đỉnh $u,v$, $pos_{u,v}$ chắc chắn không bằng chỉ số của hai đỉnh này, tức là sẽ thêm một đỉnh mới.
    
    Đặc biệt, khi $u$ và $v$ kề nhau thì trả về trực tiếp.
    
    Vì tổng số đỉnh là $n$, số lần thêm đỉnh mới (cũng là số lần đệ quy) không vượt quá $n$, nên đệ quy sẽ không rơi vào vòng lặp vô hạn.

#### Tính chất

Độ phức tạp thời gian: $O(n^3)$.

#### Cài đặt

Dưới đây là các cài đặt tham khảo bằng C++ và Python (có ghi lại đường đi):

=== "C++"
    ```cpp
    // Số đỉnh của đồ thị là n
    int val[MAXN + 1][MAXN + 1];  // Ma trận kề của đồ thị ban đầu
    int cnt, path[MAXN + 5];      // Ghi lại đường đi của chu trình nhỏ nhất và độ dài
    
    void get_path(int u, int v) {  // Lấy đường đi giữa u và v
      if (pos[u][v] == 0) return;
    
      int k = pos[u][v];
      get_path(u, k);
      path[++cnt] = k;
      get_path(k, v);
    }
    
    void Floyd(const int &n) {
      static int dis[MAXN + 1][MAXN + 1];  // Ma trận đường đi ngắn nhất
      static int pos[MAXN + 1][MAXN + 1];
      memcpy(dis, val, sizeof(val));
      memset(pos, 0, sizeof(pos));
      for (int k = 1; k <= n; ++k) {
        for (int i = 1; i < k; ++i)
          for (int j = 1; j < i; ++j)
            if (ans >
                (long long)val[i][k] + val[k][j] + dis[i][j]) {  // Tìm thấy chu trình ngắn hơn
              // Điều kiện j<i<k khiến ba đỉnh khác nhau và không có chu trình rỗng.
              ans = val[i][k] + val[k][j] + dis[i][j], cnt = 0;
              path[++cnt] = i, path[++cnt] = k,
              path[++cnt] = j;  // Lần lượt thêm ba đỉnh i,k,j
              get_path(j, i);   // Thêm đường đi từ j đến i
            }
    
        for (int i = 1; i <= n; ++i)  // Cập nhật đường đi ngắn nhất bằng Floyd như thông thường
          for (int j = 1; j <= n; ++j) {
            if (dis[i][j] > dis[i][k] + dis[k][j]) {
              dis[i][j] = dis[i][k] + dis[k][j];
              pos[i][j] = k;  // Đường đi hiện tại có thể được cập nhật thông qua k
            }
          }
      }
    }
    ```

=== "Python"
    ```python
    # Định nghĩa một giá trị đủ lớn để biểu thị vô cực
    INF = sys.maxsize
    
    
    def get_path(i, j, pos, path, cnt):
        """
        Đệ quy lấy các đỉnh trung gian trên đường đi ngắn nhất từ đỉnh i đến đỉnh j.
    
        Args:
            i (int): Đỉnh bắt đầu (0-based index).
            j (int): Đỉnh kết thúc (0-based index).
            pos (list[list[int]]): Ma trận ghi lại đỉnh trung gian của đường đi ngắn nhất. pos[i][j] = k nghĩa là đường đi ngắn nhất từ i đến j đi qua k.
            path (list[int]): Danh sách lưu các đỉnh trên đường đi (dùng 0-based index).
            cnt (int): Số đỉnh hiện có trên đường đi.
    
        Returns:
            int: Số đỉnh trên đường đi sau khi cập nhật.
        """
        # Nếu pos[i][j] bằng -1, i đến j không có đỉnh trung gian
        if pos[i][j] == -1:
            return cnt
    
        # Lấy đỉnh trung gian k
        k = pos[i][j]
        # Đệ quy lấy đường đi từ i đến k
        cnt = get_path(i, k, pos, path, cnt)
        # Thêm đỉnh trung gian k vào đường đi
        path[cnt] = k
        cnt += 1
        # Đệ quy lấy đường đi từ k đến j
        cnt = get_path(k, j, pos, path, cnt)
        return cnt
    
    
    def find_minimum_cycle_undirected(n, edges):
        """
        Dùng thuật toán Floyd-Warshall để tìm chu trình nhỏ nhất trong đồ thị vô hướng.
    
        Args:
            n (int): Số đỉnh của đồ thị (1 đến n).
            edges (list[tuple]): Danh sách cạnh, mỗi phần tử là (u, v, w), biểu thị có một cạnh trọng số w giữa đỉnh u và đỉnh v.
                                 Chỉ số đỉnh từ 1 đến n.
    
        Returns:
            tuple: Gồm độ dài chu trình nhỏ nhất và đường đi.
                   Nếu không tồn tại chu trình, trả về (INF, []).
                   Đường đi là danh sách chỉ số đỉnh (1-based index).
        """
        # Bên trong dùng 0-based indexing
        N = n
        # Khởi tạo ma trận kề g, biểu thị trọng số các cạnh ban đầu
        g = [[INF for _ in range(N)] for _ in range(N)]
        # Khởi tạo ma trận đường đi ngắn nhất dis, ban đầu giống g
        dis = [[INF for _ in range(N)] for _ in range(N)]
        # Khởi tạo ma trận pos, ghi lại đỉnh trung gian của đường đi ngắn nhất
        pos = [[-1 for _ in range(N)] for _ in range(N)]
    
        # Khởi tạo đường chéo bằng 0 (khoảng cách từ đỉnh đến chính nó)
        for i in range(N):
            g[i][i] = 0
            dis[i][i] = 0
    
        # Dựng ma trận kề từ danh sách cạnh đầu vào (đồ thị vô hướng)
        for u, v, w in edges:
            # Chuyển chỉ số 1-based thành 0-based
            u -= 1
            v -= 1
            # Trong đồ thị vô hướng, cạnh có hai chiều
            g[u][v] = min(g[u][v], w)
            g[v][u] = min(g[v][u], w)
            dis[u][v] = min(dis[u][v], w)
            dis[v][u] = min(dis[v][u], w)
    
        # Khởi tạo độ dài chu trình nhỏ nhất là vô cực
        min_cycle_len = INF
        # Khởi tạo đường đi của chu trình nhỏ nhất
        min_cycle_path = []
    
        # Phần lõi của thuật toán Floyd-Warshall
        # k là đỉnh trung gian (0-based index)
        for k in range(N):
            # Trước khi cập nhật dis[i][j], kiểm tra xem đi qua đỉnh k có tạo được chu trình nhỏ hơn hay không
            # Chu trình có dạng i -> k -> j -> ... -> i
            # dis[i][j] là đường đi ngắn nhất khi chỉ xét các đỉnh 0 đến k-1 làm đỉnh trung gian
            # Mã C++ dùng thứ tự lặp i < k và j < i; phần này cũng theo logic đó (0-based)
            for i in range(k):  # 0 <= i < k
                for j in range(i):  # 0 <= j < i
                    # Kiểm tra i, k, j có tạo thành chu trình và được nối bằng dis[i][j] hay không
                    # Yêu cầu các cạnh ban đầu g[i][k] và g[k][j] tồn tại (khác INF)
                    # Đồng thời đường đi ngắn nhất từ i đến j là dis[i][j] tồn tại (khác INF)
                    if g[i][k] != INF and g[k][j] != INF and dis[i][j] != INF:
                        current_cycle_len = g[i][k] + g[k][j] + dis[i][j]
                        if current_cycle_len < min_cycle_len:
                            min_cycle_len = current_cycle_len
                            # Khôi phục đường đi
                            path = [0] * (N + 5)  # Mảng tạm lưu đường đi, đủ dài
                            cnt = 0
                            # Thêm các đỉnh theo thứ tự i, k, j
                            path[cnt] = i
                            cnt += 1
                            path[cnt] = k
                            cnt += 1
                            path[cnt] = j
                            cnt += 1
                            # Lấy các đỉnh trung gian trên đường đi ngắn nhất từ j đến i (dùng dis và pos đã tính trước đó)
                            cnt = get_path(j, i, pos, path, cnt)
                            # Lấy các đỉnh thực sự trên đường đi (bỏ phần chưa dùng)
                            # Chuyển chỉ số 0-based thành 1-based
                            min_cycle_path = [node + 1 for node in path[:cnt]]
    
            # Cập nhật đường đi ngắn nhất bằng Floyd-Warshall chuẩn
            for i in range(N):
                for j in range(N):
                    if (
                        dis[i][k] != INF
                        and dis[k][j] != INF
                        and dis[i][j] > dis[i][k] + dis[k][j]
                    ):
                        dis[i][j] = dis[i][k] + dis[k][j]
                        # Ghi lại đường đi ngắn nhất từ i đến j đi qua k
                        pos[i][j] = k
    
        return min_cycle_len, min_cycle_path
    ```

## Bài mẫu

??? note "[AcWing 344 Chuyến du lịch tham quan](https://www.acwing.com/problem/content/346)"
    Cho một đồ thị vô hướng có $n$ đỉnh. Tìm một chu trình gồm ít nhất $3$ đỉnh trong đồ thị, các đỉnh trên chu trình không lặp lại, và tổng độ dài các cạnh trên chu trình là nhỏ nhất.
    
    Bài toán này được gọi là bài toán chu trình nhỏ nhất trong đồ thị vô hướng.
    
    Cần in ra một phương án chu trình nhỏ nhất. Nếu chu trình nhỏ nhất không duy nhất, có thể in ra bất kỳ một chu trình nào.
    
    $n \le 100$

Cách làm $O(n^3)$ được chấp nhận cho giới hạn thời gian, chỉ cần áp dụng cách dùng Floyd để tìm chu trình nhỏ nhất.

=== "C++"
    ```cpp
    #include <bits/stdc++.h>
    using lint = long long;
    // Định nghĩa hằng số đủ lớn cho số đỉnh tối đa của đồ thị
    const int MAXN = 110;
    
    // Định nghĩa một giá trị đủ lớn để biểu thị vô cực và khởi tạo độ dài chu trình nhỏ nhất
    lint ans = 1e9;  // lint là bí danh của long long
    
    // n là số đỉnh của đồ thị, m là số cạnh
    // cnt ghi lại số đỉnh trên đường đi của chu trình nhỏ nhất
    // path lưu các đỉnh trên đường đi của chu trình nhỏ nhất
    int n, m, cnt, path[MAXN];
    
    // g lưu ma trận kề của đồ thị ban đầu
    // dis lưu ma trận đường đi ngắn nhất (được cập nhật trong quá trình Floyd-Warshall)
    // pos ghi lại đỉnh trung gian của đường đi ngắn nhất, pos[i][j] = k nghĩa là đường đi ngắn nhất từ i đến j đi qua k
    int g[MAXN][MAXN], dis[MAXN][MAXN], pos[MAXN][MAXN];
    
    // Hàm đệ quy: lấy các đỉnh trung gian trên đường đi ngắn nhất từ đỉnh u đến đỉnh v
    // Khôi phục đường đi theo ma trận pos
    void get_path(int u, int v) {
      // Nếu pos[u][v] bằng 0, u đến v không có đỉnh trung gian, trả về trực tiếp
      if (pos[u][v] == 0) return;
    
      // Lấy đỉnh trung gian k
      int k = pos[u][v];
      // Đệ quy lấy đường đi từ u đến k
      get_path(u, k);
      // Thêm đỉnh trung gian k vào đường đi
      path[++cnt] = k;
      // Đệ quy lấy đường đi từ k đến v
      get_path(k, v);
    }
    
    // Hàm Floyd-Warshall: tìm chu trình nhỏ nhất trong đồ thị
    void Floyd() {
      // Vòng lặp ngoài: k là đỉnh trung gian (1 đến n)
      for (int k = 1; k <= n; ++k) {
        // Vòng lặp trong: i và j, dùng để kiểm tra xem đi qua đỉnh k có tạo được chu trình nhỏ hơn hay không
        // Thứ tự lặp là i từ 1 đến k-1, j từ 1 đến i-1
        // Như vậy có thể kiểm tra chu trình i -> k -> j -> ... -> i
        for (int i = 1; i < k; ++i)
          for (int j = 1; j < i; ++j)
            // Kiểm tra nối i và j thông qua đỉnh k có tạo thành chu trình nhỏ hơn hay không
            // Độ dài chu trình bằng trọng số cạnh ban đầu i đến k g[i][k] + trọng số cạnh ban đầu k đến j g[k][j]
            // + đường đi ngắn nhất hiện tại từ i đến j dis[i][j]
            if (ans > (long long)g[i][k] + g[k][j] + dis[i][j]) {
              // Tìm thấy chu trình nhỏ hơn
              ans = g[i][k] + g[k][j] + dis[i][j];  // Cập nhật độ dài chu trình nhỏ nhất
              cnt = 0;                              // Đặt lại bộ đếm đường đi
              // Lần lượt thêm i, k, j vào đường đi
              path[++cnt] = i, path[++cnt] = k, path[++cnt] = j;
              // Lấy các đỉnh trung gian trên đường đi ngắn nhất từ j đến i và thêm vào đường đi
              get_path(j, i);
            }
    
        // Cập nhật đường đi ngắn nhất bằng Floyd-Warshall chuẩn
        // i từ 1 đến n, j từ 1 đến n
        for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= n; ++j) {
            // Nếu có thể có đường đi từ i đến j ngắn hơn thông qua đỉnh trung gian k
            if (dis[i][j] > dis[i][k] + dis[k][j]) {
              // Cập nhật đường đi ngắn nhất
              dis[i][j] = dis[i][k] + dis[k][j];
              // Ghi lại đường đi ngắn nhất từ i đến j đi qua k
              pos[i][j] = k;
            }
          }
      }
    }
    
    // Hàm main
    int main() {
      // Đọc số đỉnh n và số cạnh m
      std::cin >> n >> m;
      // Khởi tạo ma trận kề ban đầu g, mọi trọng số cạnh được gán vô cực (0x3f thường biểu thị một giá trị rất lớn)
      memset(g, 0x3f, sizeof(g));
      // Đặt khoảng cách từ đỉnh đến chính nó bằng 0
      for (int i = 1; i <= n; ++i) g[i][i] = 0;
      // Đọc m cạnh và xây dựng ma trận kề ban đầu g
      // Với đồ thị vô hướng, cạnh có hai chiều và lấy trọng số nhỏ hơn
      for (int i = 0, u, v, w; i < m; ++i) {
        std::cin >> u >> v >> w;
        g[u][v] = g[v][u] = std::min(g[u][v], w);
      }
      // Sao chép ma trận kề ban đầu g sang ma trận đường đi ngắn nhất dis
      memcpy(dis, g, sizeof(g));
      // Gọi thuật toán Floyd để tìm chu trình nhỏ nhất
      Floyd();
      // Dựa vào độ dài chu trình nhỏ nhất để xác định có tồn tại chu trình hay không
      if (ans == 1e9) {  // Nếu độ dài chu trình nhỏ nhất vẫn là vô cực, không tồn tại chu trình
        puts("No solution.");
      } else {
        // Nếu tồn tại chu trình, in các đỉnh trên đường đi
        // std::cout << "ans = " << ans << std::endl; // In độ dài chu trình nhỏ nhất (đang được comment)
        // In các đỉnh trên đường đi, phân tách bằng dấu cách
        for (int i = 1; i <= cnt; ++i)
          std::cout << path[i]
                    << (i == cnt ? "" : " ");  // Không in dấu cách sau đỉnh cuối cùng
        std::cout << std::endl;                // Xuống dòng sau khi in xong đường đi
      }
      return 0;
    }
    ```

=== "Python"
    ```python
    import copy
    import sys
    
    # Định nghĩa một giá trị đủ lớn để biểu thị vô cực
    INF = sys.maxsize
    
    
    def get_path(i, j, pos, path, cnt):
        """
        Đệ quy lấy các đỉnh trung gian trên đường đi ngắn nhất từ đỉnh i đến đỉnh j.
    
        Args:
            i (int): Đỉnh bắt đầu (0-based index).
            j (int): Đỉnh kết thúc (0-based index).
            pos (list[list[int]]): Ma trận ghi lại đỉnh trung gian của đường đi ngắn nhất. pos[i][j] = k nghĩa là đường đi ngắn nhất từ i đến j đi qua k.
            path (list[int]): Danh sách lưu các đỉnh trên đường đi (dùng 0-based index).
            cnt (int): Số đỉnh hiện có trên đường đi.
    
        Returns:
            int: Số đỉnh trên đường đi sau khi cập nhật.
        """
        # Nếu pos[i][j] bằng -1, i đến j không có đỉnh trung gian
        if pos[i][j] == -1:
            return cnt
    
        # Lấy đỉnh trung gian k
        k = pos[i][j]
        # Đệ quy lấy đường đi từ i đến k
        cnt = get_path(i, k, pos, path, cnt)
        # Thêm đỉnh trung gian k vào đường đi
        path[cnt] = k
        cnt += 1
        # Đệ quy lấy đường đi từ k đến j
        cnt = get_path(k, j, pos, path, cnt)
        return cnt
    
    
    def find_minimum_cycle_undirected(n, edges):
        """
        Dùng thuật toán Floyd-Warshall để tìm chu trình nhỏ nhất trong đồ thị vô hướng.
    
        Args:
            n (int): Số đỉnh của đồ thị (1 đến n).
            edges (list[tuple]): Danh sách cạnh, mỗi phần tử là (u, v, w), biểu thị có một cạnh trọng số w giữa đỉnh u và đỉnh v.
                                 Chỉ số đỉnh từ 1 đến n.
    
        Returns:
            tuple: Gồm độ dài chu trình nhỏ nhất và đường đi.
                   Nếu không tồn tại chu trình, trả về (INF, []).
                   Đường đi là danh sách chỉ số đỉnh (1-based index).
        """
        # Bên trong dùng 0-based indexing
        N = n
        # Khởi tạo ma trận kề g, biểu thị trọng số các cạnh ban đầu
        g = [[INF for _ in range(N)] for _ in range(N)]
        # Khởi tạo ma trận đường đi ngắn nhất dis, ban đầu giống g
        dis = [[INF for _ in range(N)] for _ in range(N)]
        # Khởi tạo ma trận pos, ghi lại đỉnh trung gian của đường đi ngắn nhất
        pos = [[-1 for _ in range(N)] for _ in range(N)]
    
        # Khởi tạo đường chéo bằng 0 (khoảng cách từ đỉnh đến chính nó)
        for i in range(N):
            g[i][i] = 0
            dis[i][i] = 0
    
        # Dựng ma trận kề từ danh sách cạnh đầu vào (đồ thị vô hướng)
        for u, v, w in edges:
            # Chuyển chỉ số 1-based thành 0-based
            u -= 1
            v -= 1
            # Trong đồ thị vô hướng, cạnh có hai chiều
            g[u][v] = min(g[u][v], w)
            g[v][u] = min(g[v][u], w)
            dis[u][v] = min(dis[u][v], w)
            dis[v][u] = min(dis[v][u], w)
    
        # Khởi tạo độ dài chu trình nhỏ nhất là vô cực
        min_cycle_len = INF
        # Khởi tạo đường đi của chu trình nhỏ nhất
        min_cycle_path = []
    
        # Phần lõi của thuật toán Floyd-Warshall
        # k là đỉnh trung gian (0-based index)
        for k in range(N):
            # Trước khi cập nhật dis[i][j], kiểm tra xem đi qua đỉnh k có tạo được chu trình nhỏ hơn hay không
            # Chu trình có dạng i -> k -> j -> ... -> i
            # dis[i][j] là đường đi ngắn nhất khi chỉ xét các đỉnh 0 đến k-1 làm đỉnh trung gian
            # Mã C++ dùng thứ tự lặp i < k và j < i; phần này cũng theo logic đó (0-based)
            for i in range(k):  # 0 <= i < k
                for j in range(i):  # 0 <= j < i
                    # Kiểm tra i, k, j có tạo thành chu trình và được nối bằng dis[i][j] hay không
                    # Đảm bảo các cạnh ban đầu g[i][k] và g[k][j] tồn tại (khác INF)
                    # Đồng thời đường đi ngắn nhất từ i đến j là dis[i][j] tồn tại (khác INF)
                    if g[i][k] != INF and g[k][j] != INF and dis[i][j] != INF:
                        current_cycle_len = g[i][k] + g[k][j] + dis[i][j]
                        if current_cycle_len < min_cycle_len:
                            min_cycle_len = current_cycle_len
                            # Khôi phục đường đi
                            path = [0] * (N + 5)  # Mảng tạm lưu đường đi, đủ dài
                            cnt = 0
                            # Thêm các đỉnh theo thứ tự i, k, j
                            path[cnt] = i
                            cnt += 1
                            path[cnt] = k
                            cnt += 1
                            path[cnt] = j
                            cnt += 1
                            # Lấy các đỉnh trung gian trên đường đi ngắn nhất từ j đến i (dùng dis và pos đã tính trước đó)
                            cnt = get_path(j, i, pos, path, cnt)
                            # Lấy các đỉnh thực sự trên đường đi (bỏ phần chưa dùng)
                            # Chuyển chỉ số 0-based thành 1-based
                            min_cycle_path = [node + 1 for node in path[:cnt]]
    
            # Cập nhật đường đi ngắn nhất bằng Floyd-Warshall chuẩn
            for i in range(N):
                for j in range(N):
                    if (
                        dis[i][k] != INF
                        and dis[k][j] != INF
                        and dis[i][j] > dis[i][k] + dis[k][j]
                    ):
                        dis[i][j] = dis[i][k] + dis[k][j]
                        # Ghi lại đường đi ngắn nhất từ i đến j đi qua k
                        pos[i][j] = k
    
        return min_cycle_len, min_cycle_path
    
    
    # --- Điểm vào chương trình chính ---
    if __name__ == "__main__":
        # Đọc số đỉnh n và số cạnh m
        n, m = map(int, sys.stdin.readline().split())
    
        # Đọc thông tin cạnh
        edges = []
        for _ in range(m):
            u, v, w = map(int, sys.stdin.readline().split())
            edges.append((u, v, w))
    
        # Tìm chu trình nhỏ nhất
        min_len, path = find_minimum_cycle_undirected(n, edges)
    
        # In kết quả
        if min_len == INF:
            print("No solution.")
        else:
            # In các đỉnh trên đường đi (1-based index), phân tách bằng dấu cách
            print(" ".join(map(str, path)))
    ```

## Ví dụ 2

GDOI2018 Day2 Patrol

Cho một đồ thị vô hướng có $n$ đỉnh và cạnh không có trọng số âm. Cần thực hiện $q$ thao tác, gồm ba loại:

1.  Xóa một đỉnh trong đồ thị và các cạnh liên quan đến nó.
2.  Khôi phục một đỉnh đã bị xóa và các cạnh liên quan đến nó.
3.  Hỏi kích thước chu trình nhỏ nhất chứa đỉnh $x$.

Với $50\%$ dữ liệu, $n,q \le 100$.

Với mọi chu trình đơn chứa đỉnh $x$, luôn tồn tại hai cạnh kề với $x$. Nếu xóa một trong hai cạnh đó, chu trình đơn sẽ trở thành một đường đi đơn.

Vì vậy, có thể liệt kê mọi cạnh kề với $x$, mỗi lần xóa một cạnh trong số đó rồi chạy Dijkstra.

Hoặc trực tiếp chạy Floyd một lần cho mỗi truy vấn để tìm chu trình nhỏ nhất, độ phức tạp $O(qn^3)$.

Với $100\%$ dữ liệu, $n,q \le 400$.

Vẫn tận dụng thuật toán Floyd tìm chu trình nhỏ nhất.

Nếu không có thao tác xóa, xóa đỉnh được hỏi sẽ tách chu trình đơn thành một đường đi đơn.

Tuy nhiên, bước thứ hai đổi sang dùng Floyd để tính.

Khi đó đáp án là khoảng cách giữa hai đỉnh bất kỳ trong trường hợp không đi qua đỉnh truy vấn $x$.

Làm thế nào để xử lý trực tuyến?

Ép về ngoại tuyến, dùng phương pháp ngoại tuyến để tránh thao tác xóa.

Sắp xếp các truy vấn theo thứ tự thời gian và dựng một cây phân đoạn trên các truy vấn này.

Thời gian xuất hiện của mỗi đỉnh bao phủ tất cả các thời điểm truy vấn, trừ các thời điểm truy vấn chính đỉnh đó. Giả sử một đỉnh được truy vấn $x$ lần, thời gian xuất hiện của nó có thể xem là $x + 1$ đoạn, rồi chèn các đoạn này vào cây phân đoạn.

Sau khi hoàn tất, duyệt toàn bộ cây phân đoạn một lần. Khi đi qua một nút, lưu một bản sao của mảng Floyd, sau đó thêm tất cả các đỉnh được chèn vào khoảng ứng với nút này. Khi rời nút, dùng bản sao để quay lại trạng thái trước đó.

Độ phức tạp thời gian của cách làm này là $O(qn^2\log q)$.

Còn có một cách trực tuyến có độ phức tạp thời gian tốt hơn.

Với một truy vấn trên đỉnh $x$, chạy đường đi ngắn nhất một nguồn từ $x$, sau đó dựng cây đường đi ngắn nhất và đồng thời xử lý xem mỗi đỉnh nằm trong cây con nào của $x$.

Khi đó chắc chắn có thể tìm một cạnh không thuộc cây sao cho hai đầu mút của cạnh này nằm trong hai cây con khác nhau của gốc. Cạnh không thuộc cây đó cộng với hai đường đi từ hai đầu mút về gốc sẽ tạo thành chu trình nhỏ nhất.

Chứng minh:

Chu trình nhỏ nhất chứa ít nhất một cạnh không thuộc cây mà hai đầu mút của cạnh đó nằm trong hai cây con khác nhau của gốc.

Giả sử cạnh đó là $(u,v)$. Khi đó đường đi từ $x$ đến $u$ trên cây đường đi ngắn nhất là đường ngắn nhất trong tất cả các đường đi từ $x$ đến $u$, và đường đi từ $x$ đến $v$ cũng là đường ngắn nhất. Vì vậy chu trình $x\to u\to v\to x$ chắc chắn không dài hơn chu trình nhỏ nhất.

Từ đó có thể liệt kê mọi cạnh không thuộc cây để cập nhật đáp án.

Độ phức tạp của mỗi truy vấn bằng độ phức tạp chạy đường đi ngắn nhất một nguồn, là $O(n^2)$.

Tổng độ phức tạp thời gian là $O(qn^2)$.
