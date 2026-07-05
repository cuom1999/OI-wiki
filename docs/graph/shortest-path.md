author: du33169, lingkerio, Taoran-01

## Định nghĩa

(Trước khi đọc nội dung dưới đây, cần nắm chắc phần cơ bản trong [các khái niệm đồ thị](./concept.md).)

-   Đường đi
-   Đường đi ngắn nhất
-   Đường đi ngắn nhất trong đồ thị có hướng, đường đi ngắn nhất trong đồ thị vô hướng
-   Đường đi ngắn nhất từ một nguồn, đường đi ngắn nhất giữa mọi cặp đỉnh

## Ký hiệu

Để tiện trình bày, trước hết nêu ý nghĩa của một số ký hiệu sẽ dùng ở dưới.

-   $n$ là số đỉnh của đồ thị, $m$ là số cạnh của đồ thị;
-   $s$ là đỉnh nguồn của bài toán đường đi ngắn nhất;
-   $D(u)$ là độ dài đường đi ngắn nhất **thực sự** từ $s$ đến $u$;
-   $dis(u)$ là độ dài đường đi ngắn nhất **ước lượng** từ $s$ đến $u$. Ở mọi thời điểm đều có $dis(u) \geq D(u)$. Đặc biệt, khi thuật toán đường đi ngắn nhất kết thúc, cần có $dis(u)=D(u)$.
-   $w(u,v)$ là trọng số của cạnh $(u,v)$.

## Tính chất

Trong đồ thị có trọng số cạnh dương, đường đi ngắn nhất giữa hai đỉnh bất kỳ sẽ không đi qua một đỉnh lặp lại.

Trong đồ thị có trọng số cạnh dương, đường đi ngắn nhất giữa hai đỉnh bất kỳ sẽ không đi qua một cạnh lặp lại.

Trong đồ thị có trọng số cạnh dương, mọi đường đi ngắn nhất giữa hai đỉnh bất kỳ có số đỉnh không vượt quá $n$ và số cạnh không vượt quá $n-1$.

## Thuật toán Floyd

Thuật toán Floyd dùng để tìm đường đi ngắn nhất giữa mọi cặp đỉnh.

Độ phức tạp khá cao, nhưng hằng số nhỏ và dễ cài đặt (chỉ có ba vòng `for`).

Thuật toán áp dụng được cho mọi đồ thị, dù có hướng hay vô hướng, trọng số âm hay dương, miễn là đường đi ngắn nhất tồn tại (không có chu trình âm).

### Cài đặt

Định nghĩa mảng `f[k][x][y]`, biểu diễn độ dài đường đi ngắn nhất từ đỉnh $x$ đến đỉnh $y$ khi chỉ được phép đi qua các đỉnh từ $1$ đến $k$ (tức là đường đi trong đồ thị con $V'={1, 2, \ldots, k}$; chú ý rằng $x$ và $y$ không nhất thiết nằm trong đồ thị con này).

`f[n][x][y]` chính là độ dài đường đi ngắn nhất từ đỉnh $x$ đến đỉnh $y$ (vì $V'={1, 2, \ldots, n}$ chính là toàn bộ $V$, nên đường đi biểu diễn trong đó là đường đi cần tìm).

Tiếp theo xét cách tính giá trị của mảng `f`.

`f[0][x][y]`: trọng số cạnh giữa $x$ và $y$, hoặc $0$, hoặc $+\infty$ (`f[0][x][y]` khi nào nên là $+\infty$? Nếu $x$ và $y$ có cạnh nối trực tiếp thì lấy trọng số cạnh đó; nếu $x = y$ thì bằng không vì khoảng cách đến chính nó là không; nếu $x$ và $y$ không có cạnh nối trực tiếp thì là $+\infty$).

`f[k][x][y] = min(f[k-1][x][y], f[k-1][x][k]+f[k-1][k][y])` (`f[k-1][x][y]` là đường đi ngắn nhất không đi qua đỉnh $k$, còn `f[k-1][x][k]+f[k-1][k][y]` là đường đi ngắn nhất có đi qua đỉnh $k$).

Hai dòng trên đều đúng. Cách làm này dùng không gian $O(N^3)$. Lần lượt tăng quy mô bài toán ($k$ từ $1$ đến $n$), rồi xét đường đi ngắn nhất giữa mọi cặp đỉnh trong quy mô hiện tại.

=== "C++"
    ```cpp
    for (k = 1; k <= n; k++) {
      for (x = 1; x <= n; x++) {
        for (y = 1; y <= n; y++) {
          f[k][x][y] = min(f[k - 1][x][y], f[k - 1][x][k] + f[k - 1][k][y]);
        }
      }
    }
    ```

=== "Python"
    ```python
    for k in range(1, n + 1):
        for x in range(1, n + 1):
            for y in range(1, n + 1):
                f[k][x][y] = min(f[k - 1][x][y], f[k - 1][x][k] + f[k - 1][k][y])
    ```

Vì chiều thứ nhất không ảnh hưởng đến kết quả, có thể bỏ chiều đầu của mảng và viết trực tiếp thành `f[x][y] = min(f[x][y], f[x][k]+f[k][y])`.

???+ note "Chứng minh chiều thứ nhất không ảnh hưởng đến kết quả"
    Với một `k` cố định, khi cập nhật `f[k][x][y]`, các phần tử được dùng luôn đến từ hàng `k` và cột `k` của mảng `f[k-1]`. Khi cập nhật `f[k][k][y]` hoặc `f[k][x][k]`, giá trị sẽ không thay đổi, vì theo công thức `f[k][k][y] = min(f[k-1][k][y], f[k-1][k][k]+f[k-1][k][y])`, `f[k-1][k][k]` bằng 0, nên giá trị này luôn là `f[k-1][k][y]`; chứng minh cho `f[k][x][k]` tương tự.
    
    Do đó, nếu bỏ chiều thứ nhất, với `k` cố định, mọi phần tử được dùng trong mỗi lần cập nhật đều chưa bị thay đổi trong lần lặp này, nên việc bỏ chiều thứ nhất không ảnh hưởng đến kết quả.

=== "C++"
    ```cpp
    for (k = 1; k <= n; k++) {
      for (x = 1; x <= n; x++) {
        for (y = 1; y <= n; y++) {
          f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
        }
      }
    }
    ```

=== "Python"
    ```python
    for k in range(1, n + 1):
        for x in range(1, n + 1):
            for y in range(1, n + 1):
                f[x][y] = min(f[x][y], f[x][k] + f[k][y])
    ```

Tóm lại, độ phức tạp thời gian là $O(N^3)$, độ phức tạp không gian là $O(N^2)$.

### Ứng dụng

???+ question "Cho một đồ thị vô hướng trọng số dương, tìm một chu trình có tổng trọng số nhỏ nhất."
    Trước hết, chu trình đó chắc chắn là chu trình đơn.
    
    Xét cách chu trình này được tạo thành.
    
    Xét đỉnh $u$ có số thứ tự lớn nhất trên chu trình.
    
    `f[u-1][x][y]` cùng với $(u,x)$, $(u,y)$ tạo thành chu trình.
    
    Trong quá trình Floyd, liệt kê $u$ và tính giá trị nhỏ nhất của tổng này.
    
    Độ phức tạp thời gian là $O(n^3)$.
    
    Xem thêm nội dung trong phần [chu trình nhỏ nhất](./min-cycle.md).

???+ question "Biết với mọi cặp đỉnh trong một đồ thị có hướng rằng giữa chúng có cạnh hay không, xác định mọi cặp đỉnh có liên thông với nhau hay không."
    Bài toán này chính là tìm **bao đóng bắc cầu của đồ thị**.
    
    Chỉ cần làm theo quá trình Floyd, lần lượt thêm từng đỉnh vào để kiểm tra.
    
    Chỉ khác là lúc này trọng số cạnh trở thành $1/0$, còn phép lấy $\min$ trở thành phép **hoặc**.
    
    Nếu tiếp tục tối ưu bằng bitset, độ phức tạp có thể đạt $O(\frac{n^3}{w})$.
    
    ```cpp
    // std::bitset<SIZE> f[SIZE];
    for (k = 1; k <= n; k++)
      for (i = 1; i <= n; i++)
        if (f[i][k]) f[i] = f[i] | f[k];
    ```

## Thuật toán Bellman-Ford

Thuật toán Bellman-Ford là thuật toán đường đi ngắn nhất dựa trên thao tác nới lỏng (relax). Nó có thể tìm đường đi ngắn nhất trong đồ thị có trọng số âm, đồng thời có thể xác định trường hợp đường đi ngắn nhất không tồn tại.

Trong giới OI Trung Quốc, thuật toán "SPFA" thường được nhắc đến chính là một cách cài đặt Bellman-Ford.

### Quy trình

Trước hết giới thiệu thao tác nới lỏng mà Bellman-Ford dùng (Dijkstra cũng dùng thao tác này).

Với cạnh $(u,v)$, thao tác nới lỏng tương ứng với công thức: $dis(v) = \min(dis(v), dis(u) + w(u, v))$.

Ý nghĩa của thao tác này là dùng đường đi $S \to u \to v$ (trong đó đường đi $S \to u$ lấy theo đường đi ngắn nhất) để cập nhật độ dài đường đi ngắn nhất đến đỉnh $v$; nếu đường đi này tốt hơn thì cập nhật.

Việc Bellman-Ford làm là liên tục thử nới lỏng từng cạnh trên đồ thị. Mỗi vòng lặp, thuật toán thử thực hiện một lần nới lỏng trên tất cả cạnh của đồ thị; khi trong một vòng lặp không có thao tác nới lỏng thành công nào, thuật toán dừng.

Mỗi vòng lặp tốn $O(m)$, vậy nhiều nhất sẽ lặp bao nhiêu lần?

Trong trường hợp đường đi ngắn nhất tồn tại, vì một thao tác nới lỏng sẽ làm số cạnh trên đường đi ngắn nhất tăng thêm ít nhất $1$, còn số cạnh trên đường đi ngắn nhất nhiều nhất là $n-1$, nên toàn bộ thuật toán thực hiện nhiều nhất $n-1$ vòng nới lỏng. Do đó độ phức tạp thời gian là $O(nm)$.

Nhưng còn một trường hợp khác: nếu từ đỉnh $S$ có thể đi đến một chu trình âm, thao tác nới lỏng sẽ tiếp tục mãi. Từ lập luận ở trên, với đồ thị mà đường đi ngắn nhất tồn tại, thao tác nới lỏng nhiều nhất chỉ thực hiện $n-1$ vòng; vì vậy nếu đến vòng thứ $n$ vẫn còn cạnh có thể nới lỏng, điều đó cho thấy từ đỉnh $S$ có thể đi đến một chu trình âm.

???+ warning "Hiểu lầm thường gặp khi phát hiện chu trình âm"
    Cần chú ý rằng khi chạy Bellman-Ford với đỉnh nguồn $S$, nếu thuật toán không báo tồn tại chu trình âm thì điều đó chỉ nói rằng từ $S$ không thể đi đến một chu trình âm, chứ không chứng minh rằng toàn đồ thị không có chu trình âm.
    
    Vì vậy nếu cần xác định toàn đồ thị có chu trình âm hay không, cách chặt chẽ nhất là tạo một siêu nguồn, nối từ siêu nguồn đến mỗi đỉnh trong đồ thị một cạnh trọng số 0, rồi chạy Bellman-Ford từ siêu nguồn.

### Cài đặt

??? note "Cài đặt tham khảo"
    === "C++"
        ```cpp
        struct Edge {
          int u, v, w;
        };
        
        vector<Edge> edge;
        
        int dis[MAXN], u, v, w;
        constexpr int INF = 0x3f3f3f3f;
        
        bool bellmanford(int n, int s) {
          memset(dis, 0x3f, (n + 1) * sizeof(int));
          dis[s] = 0;
          bool flag = false;  // Kiểm tra trong một vòng lặp có xảy ra nới lỏng hay không
          for (int i = 1; i <= n; i++) {
            flag = false;
            for (int j = 0; j < edge.size(); j++) {
              u = edge[j].u, v = edge[j].v, w = edge[j].w;
              if (dis[u] == INF) continue;
              // Vô cực cộng trừ với hằng số vẫn là vô cực
              // Vì vậy cạnh đi ra từ đỉnh có độ dài đường đi ngắn nhất là INF không thể được nới lỏng
              if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                flag = true;
              }
            }
            // Khi không còn cạnh có thể nới lỏng thì dừng thuật toán
            if (!flag) {
              break;
            }
          }
          // Nếu ở vòng lặp thứ n vẫn có thể nới lỏng, đỉnh s có thể đi đến một chu trình âm
          return flag;
        }
        ```
    
    === "Python"
        ```python
        class Edge:
            def __init__(self, u=0, v=0, w=0):
                self.u = u
                self.v = v
                self.w = w
        
        
        INF = 0x3F3F3F3F
        edge = []
        
        
        def bellmanford(n, s):
            dis = [INF] * (n + 1)
            dis[s] = 0
            for i in range(1, n + 1):
                flag = False
                for e in edge:
                    u, v, w = e.u, e.v, e.w
                    if dis[u] == INF:
                        continue
                    # Vô cực cộng trừ với hằng số vẫn là vô cực
                    # Vì vậy cạnh đi ra từ đỉnh có độ dài đường đi ngắn nhất là INF không thể được nới lỏng
                    if dis[v] > dis[u] + w:
                        dis[v] = dis[u] + w
                        flag = True
                # Khi không còn cạnh có thể nới lỏng thì dừng thuật toán
                if not flag:
                    break
            # Nếu ở vòng lặp thứ n vẫn có thể nới lỏng, đỉnh s có thể đi đến một chu trình âm
            return flag
        ```

### Tối ưu bằng hàng đợi: SPFA

SPFA là viết tắt của tên tiếng Anh Shortest Path Faster Algorithm, nghĩa là "thuật toán đường đi ngắn nhất nhanh hơn".

Trong nhiều trường hợp, không cần thực hiện quá nhiều thao tác nới lỏng vô ích.

Chỉ các cạnh nối với những đỉnh vừa được nới lỏng ở lần trước mới có khả năng gây ra thao tác nới lỏng tiếp theo.

Vì vậy dùng hàng đợi để duy trì "những đỉnh có thể gây ra thao tác nới lỏng", nhờ đó chỉ cần thăm các cạnh cần thiết.

SPFA cũng có thể dùng để xác định đỉnh $s$ có đi đến được một chu trình âm hay không. Chỉ cần ghi lại số cạnh mà đường đi ngắn nhất đi qua; khi số cạnh đã đi qua ít nhất là $n$, điều đó cho thấy từ $s$ có thể đi đến một chu trình âm.

??? note "Cài đặt"
    === "C++"
        ```cpp
        struct edge {
          int v, w;
        };
        
        vector<edge> e[MAXN];
        int dis[MAXN], cnt[MAXN], vis[MAXN];
        queue<int> q;
        
        bool spfa(int n, int s) {
          memset(dis, 0x3f, (n + 1) * sizeof(int));
          dis[s] = 0, vis[s] = 1;
          q.push(s);
          while (!q.empty()) {
            int u = q.front();
            q.pop(), vis[u] = 0;
            for (auto ed : e[u]) {
              int v = ed.v, w = ed.w;
              if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;  // Ghi lại số cạnh mà đường đi ngắn nhất đi qua
                if (cnt[v] >= n) return false;
                // Nếu không đi qua chu trình âm, đường đi ngắn nhất có nhiều nhất n - 1 cạnh
                // Vì vậy nếu đi qua nhiều hơn n cạnh thì chắc chắn đã đi qua chu trình âm
                if (!vis[v]) q.push(v), vis[v] = 1;
              }
            }
          }
          return true;
        }
        ```
    
    === "Python"
        ```python
        from collections import deque
        
        
        class Edge:
            def __init__(self, v=0, w=0):
                self.v = v
                self.w = w
        
        
        e = [[Edge() for i in range(MAXN)] for j in range(MAXN)]
        INF = 0x3F3F3F3F
        
        
        def spfa(n, s):
            dis = [INF] * (n + 1)
            cnt = [0] * (n + 1)
            vis = [False] * (n + 1)
            q = deque()
        
            dis[s] = 0
            vis[s] = True
            q.append(s)
            while q:
                u = q.popleft()
                vis[u] = False
                for ed in e[u]:
                    v, w = ed.v, ed.w
                    if dis[v] > dis[u] + w:
                        dis[v] = dis[u] + w
                        cnt[v] = cnt[u] + 1  # Ghi lại số cạnh mà đường đi ngắn nhất đi qua
                        if cnt[v] >= n:
                            return False
                        # Nếu không đi qua chu trình âm, đường đi ngắn nhất có nhiều nhất n - 1 cạnh
                        # Vì vậy nếu đi qua nhiều hơn n cạnh thì chắc chắn đã đi qua chu trình âm
                        if not vis[v]:
                            q.append(v)
                            vis[v] = True
        ```

Dù trong đa số trường hợp SPFA chạy rất nhanh, độ phức tạp thời gian trong trường hợp xấu nhất của nó là $O(nm)$; có thể tạo dữ liệu để đẩy nó đến độ phức tạp này. Vì vậy khi thi cần thận trọng khi dùng SPFA (nếu không có cạnh âm thì tốt nhất dùng Dijkstra; nếu có cạnh âm và đồ thị trong đề không có tính chất đặc biệt, nếu SPFA là một phần của lời giải chuẩn thì đề không nên cho giới hạn dữ liệu khiến Bellman-Ford không thể qua).

???+ note "Các tối ưu khác của Bellman-Ford"
    Ngoài tối ưu bằng hàng đợi (SPFA), Bellman-Ford còn có các dạng tối ưu khác. Những tối ưu này hiệu quả rõ rệt trên một số đồ thị, nhưng trên vài đồ thị đặc biệt, độ phức tạp xấu nhất có thể đạt mức hàm mũ.
    
    -   Tối ưu bằng heap: thay hàng đợi bằng heap; khác với Dijkstra ở chỗ cho phép một đỉnh vào hàng đợi nhiều lần. Trên đồ thị có cạnh âm, cách này có thể bị đẩy đến độ phức tạp hàm mũ.
    -   Tối ưu bằng stack: thay hàng đợi bằng stack (tức biến quá trình BFS ban đầu thành DFS). Cách này có thể hiệu quả hơn khi tìm chu trình âm, nhưng độ phức tạp thời gian xấu nhất vẫn là hàm mũ.
    -   Tối ưu LLL: thay hàng đợi thường bằng deque; mỗi lần đưa một đỉnh vào hàng đợi, so sánh khoảng cách của nó với trung bình khoảng cách trong hàng đợi, nếu lớn hơn thì chèn vào cuối, ngược lại chèn vào đầu.
    -   Tối ưu SLF: thay hàng đợi thường bằng deque; mỗi lần đưa một đỉnh vào hàng đợi, so sánh khoảng cách của nó với đỉnh đầu hàng đợi, nếu lớn hơn thì chèn vào cuối, ngược lại chèn vào đầu.
    -   Thuật toán D'Esopo-Pape: thay hàng đợi thường bằng deque; nếu một đỉnh trước đó chưa vào hàng đợi thì chèn vào cuối, ngược lại chèn vào đầu.
    
    Xem thêm các tối ưu và cách hack những tối ưu đó trong [câu trả lời của fstqwq trên Zhihu](https://www.zhihu.com/question/292283275/answer/484871888).

## Thuật toán Dijkstra

Thuật toán Dijkstra (/ˈdikstrɑ/ hoặc /ˈdɛikstrɑ/) do nhà khoa học máy tính người Hà Lan E. W. Dijkstra phát hiện năm 1956 và công bố năm 1959. Đây là thuật toán tìm đường đi ngắn nhất từ một nguồn trên **đồ thị có trọng số không âm**.

### Quy trình

Chia các đỉnh thành hai tập: tập các đỉnh đã xác định được độ dài đường đi ngắn nhất (ký hiệu là tập $S$) và tập các đỉnh chưa xác định được độ dài đường đi ngắn nhất (ký hiệu là tập $T$). Ban đầu mọi đỉnh đều thuộc tập $T$.

Khởi tạo $dis(s)=0$, còn $dis$ của các đỉnh khác đều là $+\infty$.

Sau đó lặp lại các thao tác sau:

1.  Chọn trong tập $T$ một đỉnh có độ dài đường đi ngắn nhất nhỏ nhất, rồi chuyển nó sang tập $S$.
2.  Thực hiện nới lỏng trên tất cả cạnh đi ra từ đỉnh vừa được thêm vào tập $S$.

Khi tập $T$ rỗng, thuật toán kết thúc.

### Độ phức tạp thời gian

Cài đặt đơn giản là sau mỗi lần thực hiện thao tác 2, trực tiếp tìm tuyến tính trong tập $T$ đỉnh có độ dài đường đi ngắn nhất nhỏ nhất. Tổng thời gian của thao tác 2 là $O(m)$, tổng thời gian của thao tác 1 là $O(n^2)$, nên toàn bộ quá trình có độ phức tạp thời gian $O(n^2 + m) = O(n^2)$.

Có thể dùng heap để tối ưu quá trình này: mỗi khi nới lỏng thành công một cạnh $(u,v)$, chèn $v$ vào heap (nếu $v$ đã ở trong heap thì trực tiếp thực hiện Decrease-key); thao tác 1 chỉ cần lấy đỉnh ở đỉnh heap. Tổng cộng có $O(m)$ lần Decrease-key, $O(n)$ lần pop; chọn heap khác nhau sẽ cho độ phức tạp khác nhau, xem trang [heap](../ds/heap.md). Độ phức tạp tối ưu mà Dijkstra tối ưu bằng heap có thể đạt được là $O(n\log n+m)$, ví dụ với heap Fibonacci.

Đặc biệt, có thể dùng hàng đợi ưu tiên để duy trì. Khi đó không thể thực hiện Decrease-key, nhưng có thể chèn lại đỉnh mỗi khi nới lỏng, rồi khi lấy ra thì kiểm tra đỉnh đó đã được nới lỏng hay chưa; nếu rồi thì bỏ qua. Độ phức tạp là $O(m\log n)$, ưu điểm là cài đặt đơn giản hơn.

Heap trong phần này cũng có thể được cài bằng cây phân đoạn, độ phức tạp là $O(m\log n)$. Với một số cài đặt cây phân đoạn không đệ quy đặc biệt, hằng số của cách này nhỏ hơn heap. Ngoài ra cây phân đoạn hỗ trợ nhiều thao tác hơn, và trong một số bài đồ thị đặc biệt bắt buộc phải dùng cây phân đoạn để duy trì.

Trong đồ thị thưa, $m = O(n)$, Dijkstra tối ưu bằng heap có lợi thế lớn về hiệu suất; còn trong đồ thị dày, $m = O(n^2)$, cài đặt đơn giản lại tốt hơn.

### Chứng minh tính đúng đắn

Dưới đây dùng quy nạp toán học để chứng minh tính đúng đắn của thuật toán Dijkstra trong điều kiện **mọi trọng số cạnh đều không âm**[^1].

Nói ngắn gọn, cần chứng minh rằng ở thao tác 1, đỉnh $u$ được lấy ra đều đã được xác định đường đi ngắn nhất, tức thỏa mãn $D(u) = dis(u)$.

Ban đầu $S = \varnothing$, giả thiết đúng.

Tiếp theo dùng phản chứng.

Giả sử $u$ là đỉnh đầu tiên trong thuật toán mà khi được thêm vào tập $S$ không thỏa mãn $D(u) = dis(u)$. Vì đỉnh $s$ chắc chắn thỏa mãn $D(u)=dis(u)=0$, và nó chắc chắn là đỉnh đầu tiên được thêm vào tập $S$, nên trước khi thêm $u$ vào tập $S$ có $S \neq \varnothing$; nếu không tồn tại đường đi từ $s$ đến $u$, thì $D(u) = dis(u) = +\infty$, mâu thuẫn với giả thiết.

Vì vậy chắc chắn tồn tại một đường đi $s \to x \to y \to u$, trong đó $y$ là đỉnh đầu tiên trên đường đi từ $s$ đến $u$ thuộc tập $T$, còn $x$ là đỉnh đứng trước $y$ (khi đó $x \in S$). Cần chú ý rằng có thể xảy ra $s = x$ hoặc $y = u$, tức $s \to x$ hoặc $y \to u$ có thể là đường đi rỗng.

Vì mọi đỉnh được thêm vào trước $u$ đều thỏa mãn $D(u) = dis(u)$, nên khi đỉnh $x$ được thêm vào tập $S$, có $D(x) = dis(x)$; lúc đó cạnh $(x,y)$ sẽ được nới lỏng. Từ đó có thể chứng minh rằng khi thêm $u$ vào tập $S$, chắc chắn có $D(y)=dis(y)$.

Tiếp theo chứng minh $D(u) = dis(u)$. Trên đường đi $s \to x \to y \to u$, vì mọi trọng số cạnh của đồ thị không âm, nên $D(y) \leq D(u)$. Do đó $dis(y) = D(y) \leq D(u)\leq dis(u)$. Nhưng khi đỉnh $u$ được lấy khỏi tập $T$ ở thao tác 1, đỉnh $y$ vẫn chưa bị lấy khỏi tập $T$, vì vậy lúc này có $dis(u)\leq dis(y)$. Suy ra $dis(y) = D(y) = D(u) = dis(u)$, mâu thuẫn với giả thiết $D(u)\neq dis(u)$. Do đó giả thiết sai.

Vậy đã chứng minh được rằng mỗi đỉnh được lấy ra ở thao tác 1 đều đã được xác định đường đi ngắn nhất. Mệnh đề được chứng minh.

Chú ý rằng bất đẳng thức then chốt $D(y) \leq D(u)$ trong chứng minh được suy ra nhờ mọi trọng số cạnh trên đồ thị không âm. Khi đồ thị có cạnh âm, bất đẳng thức này không còn đúng, tính đúng đắn của Dijkstra không được bảo đảm, và thuật toán có thể cho kết quả sai.

### Cài đặt

Dưới đây đồng thời đưa ra cài đặt đơn giản $O(n^2)$ và cài đặt bằng hàng đợi ưu tiên $O(m \log m)$.

???+ note "Cài đặt đơn giản"
    === "C++"
        ```cpp
        struct edge {
          int v, w;
        };
        
        vector<edge> e[MAXN];
        int dis[MAXN], vis[MAXN];
        
        void dijkstra(int n, int s) {
          memset(dis, 0x3f, (n + 1) * sizeof(int));
          dis[s] = 0;
          for (int i = 1; i <= n; i++) {
            int u = 0, mind = 0x3f3f3f3f;
            for (int j = 1; j <= n; j++)
              if (!vis[j] && dis[j] < mind) u = j, mind = dis[j];
            vis[u] = true;
            for (auto ed : e[u]) {
              int v = ed.v, w = ed.w;
              if (dis[v] > dis[u] + w) dis[v] = dis[u] + w;
            }
          }
        }
        ```
    
    === "Python"
        ```python
        class Edge:
            def __init(self, v=0, w=0):
                self.v = v
                self.w = w
        
        
        e = [[Edge() for i in range(MAXN)] for j in range(MAXN)]
        INF = 0x3F3F3F3F
        
        
        def dijkstra(n, s):
            dis = [INF] * (n + 1)
            vis = [0] * (n + 1)
        
            dis[s] = 0
            for i in range(1, n + 1):
                u = 0
                mind = INF
                for j in range(1, n + 1):
                    if not vis[j] and dis[j] < mind:
                        u = j
                        mind = dis[j]
                vis[u] = True
                for ed in e[u]:
                    v, w = ed.v, ed.w
                    if dis[v] > dis[u] + w:
                        dis[v] = dis[u] + w
        ```

???+ note "Cài đặt bằng hàng đợi ưu tiên"
    === "C++"
        ```cpp
        struct edge {
          int v, w;
        };
        
        struct node {
          int dis, u;
        
          bool operator>(const node& a) const { return dis > a.dis; }
        };
        
        vector<edge> e[MAXN];
        int dis[MAXN], vis[MAXN];
        priority_queue<node, vector<node>, greater<node>> q;
        
        void dijkstra(int n, int s) {
          memset(dis, 0x3f, (n + 1) * sizeof(int));
          memset(vis, 0, (n + 1) * sizeof(int));
          dis[s] = 0;
          q.push({0, s});
          while (!q.empty()) {
            int u = q.top().u;
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto ed : e[u]) {
              int v = ed.v, w = ed.w;
              if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
              }
            }
          }
        }
        ```
    
    === "Python"
        ```python
        def dijkstra(e, s):
            """
            Đầu vào:
            e: danh sách kề
            s: đỉnh xuất phát
            Trả về:
            dis: độ dài đường đi ngắn nhất từ s đến từng đỉnh
            """
            dis = defaultdict(lambda: float("inf"))
            dis[s] = 0
            q = [(0, s)]
            vis = set()
            while q:
                _, u = heapq.heappop(q)
                if u in vis:
                    continue
                vis.add(u)
                for v, w in e[u]:
                    if dis[v] > dis[u] + w:
                        dis[v] = dis[u] + w
                        heapq.heappush(q, (dis[v], v))
            return dis
        ```

## Thuật toán Johnson tìm đường đi ngắn nhất mọi cặp

Giống Floyd, Johnson là thuật toán có thể tìm đường đi ngắn nhất giữa mọi cặp đỉnh trên đồ thị không có chu trình âm. Thuật toán này được Donald B. Johnson đề xuất năm 1977.

Đường đi ngắn nhất giữa mọi cặp đỉnh có thể được giải bằng cách liệt kê đỉnh xuất phát và chạy Bellman-Ford $n$ lần, độ phức tạp thời gian là $O(n^2m)$; cũng có thể dùng trực tiếp Floyd, độ phức tạp thời gian là $O(n^3)$.

Nhận thấy Dijkstra tối ưu bằng heap có độ phức tạp tìm đường đi ngắn nhất từ một nguồn tốt hơn Bellman-Ford. Nếu liệt kê đỉnh xuất phát và chạy Dijkstra $n$ lần, có thể giải bài toán trong độ phức tạp $O(nm\log m)$ (phụ thuộc vào cách cài đặt Dijkstra), tốt hơn độ phức tạp chạy Bellman-Ford $n$ lần ở trên, và trên đồ thị thưa cũng tốt hơn Floyd.

Nhưng Dijkstra không thể tìm đúng đường đi ngắn nhất khi có cạnh âm, vì vậy cần tiền xử lý trọng số cạnh của đồ thị ban đầu để mọi trọng số cạnh đều không âm.

Một cách dễ nghĩ tới là cộng đồng thời một số dương $x$ vào trọng số của mọi cạnh, để mọi cạnh đều có trọng số không âm. Nếu đường đi ngắn nhất từ điểm đầu đến điểm cuối trong đồ thị mới đi qua $k$ cạnh, thì trừ $kx$ khỏi đường đi ngắn nhất đó sẽ nhận được đường đi ngắn nhất thực sự.

Nhưng cách này là sai. Xét hình sau:

![](./images/shortest-path1.svg)

Đường đi ngắn nhất từ $1 \to 2$ là $1 \to 5 \to 3 \to 2$, độ dài là $−2$.

Nhưng nếu cộng thêm $5$ vào trọng số của mỗi cạnh thì sao?

![](./images/shortest-path2.svg)

Trong đồ thị mới, đường đi ngắn nhất từ $1 \to 2$ là $1 \to 4 \to 2$, không còn là đường đi ngắn nhất thực sự.

Thuật toán Johnson dùng một cách khác để gán lại trọng số cho từng cạnh.

Tạo một đỉnh ảo mới (giả sử đánh số là $0$). Từ đỉnh này nối một cạnh trọng số $0$ đến mọi đỉnh khác.

Tiếp theo dùng Bellman-Ford để tìm đường đi ngắn nhất từ đỉnh $0$ đến mọi đỉnh khác, ký hiệu là $h_i$.

Giả sử tồn tại một cạnh từ đỉnh $u$ đến đỉnh $v$ với trọng số $w$, đặt lại trọng số của cạnh này thành $w+h_u-h_v$.

Sau đó lấy từng đỉnh làm điểm xuất phát và chạy Dijkstra $n$ lần, sẽ tìm được đường đi ngắn nhất giữa mọi cặp đỉnh.

Bellman-Ford ban đầu không phải nút thắt thời gian; nếu dùng `priority_queue` để cài Dijkstra, độ phức tạp thời gian của thuật toán là $O(nm\log m)$.

### Chứng minh tính đúng đắn

Vì sao cách gán lại trọng số này là đúng?

Trước khi bàn về vấn đề đó, xét một khái niệm vật lý: thế năng.

Các dạng thế năng như thế năng trọng trường, thế năng điện có một đặc điểm: độ biến thiên thế năng chỉ phụ thuộc vào vị trí tương đối của điểm đầu và điểm cuối, không phụ thuộc vào đường đi từ điểm đầu đến điểm cuối.

Thế năng còn có một đặc điểm khác: giá trị tuyệt đối của thế năng thường phụ thuộc vào cách chọn mốc thế năng bằng không, nhưng dù đặt mốc ở đâu thì hiệu thế năng giữa hai điểm vẫn không đổi.

Bây giờ quay lại bài toán.

Trong đồ thị sau khi gán lại trọng số, độ dài của một đường đi từ $s$ đến $t$: $s \to p_1 \to p_2 \to \dots \to p_k \to t$ có biểu thức:

$(w(s,p_1)+h_s-h_{p_1})+(w(p_1,p_2)+h_{p_1}-h_{p_2})+ \dots +(w(p_k,t)+h_{p_k}-h_t)$

Rút gọn được:

$w(s,p_1)+w(p_1,p_2)+ \dots +w(p_k,t)+h_s-h_t$

Bất kể đi từ $s$ đến $t$ theo đường nào, giá trị $h_s-h_t$ đều không đổi, điều này khớp với tính chất của thế năng.

Để tiện gọi, $h_i$ là thế năng của đỉnh $i$.

Trong đồ thị mới ở trên, biểu thức độ dài đường đi ngắn nhất từ $s \to t$ gồm hai phần: tổng trọng số cạnh phía trước là đường đi ngắn nhất từ $s \to t$ trong đồ thị ban đầu, còn phần phía sau là hiệu thế năng giữa hai đỉnh. Vì hiệu thế năng giữa hai đỉnh là hằng số, đường đi ngắn nhất từ $s \to t$ trên đồ thị ban đầu tương ứng với đường đi ngắn nhất từ $s \to t$ trên đồ thị mới.

Đến đây đã giải quyết được một nửa chứng minh tính đúng đắn: đã chứng minh rằng sau khi gán lại trọng số, đường đi ngắn nhất trên đồ thị vẫn là đường đi ngắn nhất ban đầu. Tiếp theo cần chứng minh mọi cạnh trong đồ thị mới đều có trọng số không âm, vì trên đồ thị trọng số không âm, Dijkstra bảo đảm cho kết quả đúng.

Theo bất đẳng thức tam giác, với mọi cạnh $(u,v)$ trên đồ thị, hai đầu cạnh thỏa mãn $h_v \leq h_u + w(u,v)$. Trọng số cạnh sau khi gán lại là $w'(u,v)=w(u,v)+h_u-h_v \geq 0$. Như vậy đã chứng minh mọi trọng số cạnh trong đồ thị mới đều không âm.

Vậy đã chứng minh tính đúng đắn của thuật toán Johnson.

## So sánh các phương pháp

| Thuật toán đường đi ngắn nhất | Floyd | Bellman-Ford | Dijkstra | Johnson |
| ------- | ---------- | ------------ | ------------ | ------------- |
| Kiểu đường đi ngắn nhất | Mọi cặp đỉnh | Từ một nguồn | Từ một nguồn | Mọi cặp đỉnh |
| Áp dụng cho | Đồ thị bất kỳ | Đồ thị bất kỳ | Đồ thị trọng số không âm | Đồ thị bất kỳ |
| Phát hiện được chu trình âm? | Có | Có | Không | Có |
| Độ phức tạp thời gian | $O(N^3)$ | $O(NM)$ | $O(M\log M)$ | $O(NM\log M)$ |

Ghi chú: thuật toán Dijkstra trong bảng đều được tính độ phức tạp khi cài bằng `priority_queue`.

## Xuất phương án

Tạo một mảng `pre`, khi cập nhật khoảng cách thì ghi lại đỉnh phía sau được chuyển từ đâu đến, sau đó trước khi thuật toán kết thúc thì đệ quy xuất đường đi.

Ví dụ Floyd cần ghi `pre[i][j] = k;`, còn Bellman-Ford và Dijkstra thường ghi `pre[v] = u`.

## Một số trường hợp đặc biệt

-   Đường đi ngắn nhất trên đồ thị có trọng số cạnh chỉ gồm $0$ và $1$: [0-1 BFS](./bfs.md#bfs-hai-đầu-hàng-đợi);
-   Bài toán đường đi ngắn nhất cho phép thay đổi chi phí đường đi tối đa $k$ lần: [đường đi ngắn nhất trên đồ thị phân tầng](./node.md#đường-đi-ngắn-nhất-trên-đồ-thị-phân-tầng).

## Tài liệu tham khảo và chú thích

[^1]: *Introduction to Algorithms* (bản dịch Trung Quốc, ấn bản thứ 3), China Machine Press, 2013, trang 384-385.
