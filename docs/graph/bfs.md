author: Ir1d, greyqz, yjl9903, Anguei, Marcythm, ChungZH, Xeonacid, ylxmf2005

BFS là viết tắt của [Breadth First Search](https://en.wikipedia.org/wiki/Breadth-first_search), trong tiếng Việt thường gọi là tìm kiếm theo chiều rộng.

Đây là một trong những thuật toán tìm kiếm cơ bản và quan trọng nhất trên đồ thị.

"Theo chiều rộng" nghĩa là mỗi lần thuật toán sẽ cố gắng thăm các đỉnh ở cùng một tầng.
Sau khi đã thăm hết một tầng, thuật toán mới chuyển sang tầng kế tiếp.

Kết quả của cách làm này là đường đi mà BFS tìm được sẽ là đường đi hợp lệ **ngắn nhất** xuất phát từ đỉnh bắt đầu. Nói cách khác, đường đi đó có số cạnh nhỏ nhất.

Khi BFS kết thúc, mỗi đỉnh đều được thăm thông qua một đường đi ngắn nhất từ đỉnh bắt đầu đến đỉnh đó.

Quá trình của thuật toán có thể được xem như sự lan truyền của lửa trên đồ thị: ban đầu chỉ có đỉnh xuất phát bắt lửa, và tại mỗi thời điểm, mọi đỉnh đang có lửa sẽ truyền lửa sang tất cả các đỉnh kề với nó.

## Cài đặt

Các cài đặt C++ và Python bên dưới dựa trên cách lưu đồ thị bằng forward star dạng danh sách liên kết. Bạn có thể tham khảo cách cài đặt này ở trang [Lưu trữ đồ thị](./save.md).

=== "Mã giả"
    ```text
    bfs(s) {
      q = new queue()
      q.push(s), visited[s] = true
      while (!q.empty()) {
        u = q.pop()
        for each edge(u, v) {
          if (!visited[v]) {
            q.push(v)
            visited[v] = true
          }
        }
      }
    }
    ```

=== "C++"
    ```cpp
    void bfs(int u) {
      while (!Q.empty()) Q.pop();
      Q.push(u);
      vis[u] = 1;
      d[u] = 0;
      p[u] = -1;
      while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
          if (!vis[e[i].to]) {
            Q.push(e[i].to);
            vis[e[i].to] = 1;
            d[e[i].to] = d[u] + 1;
            p[e[i].to] = u;
          }
        }
      }
    }
    
    void restore(int x) {
      vector<int> res;
      for (int v = x; v != -1; v = p[v]) {
        res.push_back(v);
      }
      std::reverse(res.begin(), res.end());
      for (int i = 0; i < res.size(); ++i) printf("%d", res[i]);
      puts("");
    }
    ```

=== "Python"
    ```python
    from queue import Queue
    
    
    def bfs(u):
        Q = Queue()
        Q.put(u)
        vis[u] = True
        d[u] = 0
        p[u] = -1
        while Q.qsize() != 0:
            u = Q.get()
            i = head[u]
            while i:
                if vis[e[i].to] == False:
                    Q.put(e[i].to)
                    vis[e[i].to] = True
                    d[e[i].to] = d[u] + 1
                    p[e[i].to] = u
                i = e[i].nxt
    
    
    def restore(x):
        res = []
        v = x
        while v != -1:
            res.append(v)
            v = p[v]
        res.reverse()
        for i in range(0, len(res)):
            print(res[i])
    ```

Cụ thể, ta dùng một hàng đợi `Q` để ghi lại các đỉnh cần xử lý, rồi mở một mảng Boolean `vis[]` để đánh dấu một đỉnh đã được thăm hay chưa.

Ban đầu, ta đặt giá trị `vis` của mọi đỉnh là 0, biểu thị rằng chúng chưa được thăm. Sau đó, đưa đỉnh xuất phát `s` vào hàng đợi `Q` và đặt `vis[s]` bằng 1.

Tiếp theo, mỗi lần ta lấy đỉnh đầu hàng đợi `Q`, ký hiệu là `u`, rồi đánh dấu tất cả các đỉnh `v` kề với `u` là đã thăm và đưa chúng vào hàng đợi `Q`.

Lặp lại cho đến khi hàng đợi `Q` rỗng, khi đó BFS kết thúc.

Trong quá trình BFS, ta cũng có thể ghi lại một số thông tin bổ sung. Ví dụ trong đoạn mã trên, mảng `d` dùng để ghi khoảng cách ngắn nhất từ đỉnh xuất phát đến một đỉnh nào đó, tức số cạnh ít nhất cần đi qua, còn mảng `p` ghi lại đỉnh mà từ đó ta đi đến đỉnh hiện tại.

Với mảng `d`, ta có thể dễ dàng lấy khoảng cách từ đỉnh xuất phát đến một đỉnh.

Với mảng `p`, ta có thể dễ dàng khôi phục đường đi ngắn nhất từ đỉnh xuất phát đến một đỉnh. Hàm `restore` trong đoạn mã trên dùng mảng này để lần lượt in ra các đỉnh trên đường đi ngắn nhất từ đỉnh xuất phát đến đỉnh `x`.

Độ phức tạp thời gian: $O(n + m)$

Độ phức tạp không gian: $O(n)$, gồm mảng `vis` và hàng đợi.

## Bảng open-closed

Khi cài đặt BFS, về bản chất ta đưa các đỉnh chưa được thăm vào một vùng chứa gọi là open, và đưa các đỉnh đã được thăm vào một vùng chứa gọi là closed.

## BFS trên cây/đồ thị

### Thứ tự BFS

Tương tự thứ tự DFS, thứ tự BFS là dãy chỉ số các đỉnh được thăm trong quá trình BFS.

### BFS trên đồ thị tổng quát

Nếu đồ thị ban đầu không liên thông, ta chỉ có thể thăm được các đỉnh có thể đi tới từ đỉnh xuất phát.

Thứ tự BFS thường cũng không duy nhất.

Tương tự, ta cũng có thể định nghĩa cây BFS: trong quá trình BFS, bằng cách ghi lại mỗi đỉnh được thăm từ đỉnh nào, ta có thể xây dựng một cấu trúc cây, gọi là cây BFS.

## Ứng dụng

-   Tìm đường đi ngắn nhất từ đỉnh xuất phát đến tất cả các đỉnh khác trong một đồ thị không trọng số.
-   Tìm tất cả các thành phần liên thông trong thời gian $O(n+m)$. Ta chỉ cần bắt đầu BFS từ mỗi đỉnh chưa được thăm, và hiển nhiên mỗi lần BFS sẽ duyệt hết một thành phần liên thông.
-   Nếu xem mỗi hành động trong một trò chơi là một cạnh, tức một phép chuyển, trên đồ thị trạng thái, thì BFS có thể được dùng để tìm số bước ít nhất cần thiết để đi từ một trạng thái đến một trạng thái khác trong trò chơi.
-   Tìm chu trình nhỏ nhất trong một đồ thị có hướng không trọng số. Bắt đầu BFS từ từng đỉnh; khi sắp đi tới một đỉnh đã được thăm trước đó, ta biết rằng đã gặp một chu trình. Chu trình nhỏ nhất của đồ thị là chu trình nhỏ nhất thu được trong các lần BFS.
-   Tìm các cạnh chắc chắn nằm trên một đường đi ngắn nhất từ $a$ đến $b$. Thực hiện BFS lần lượt từ $a$ và $b$ để thu được hai mảng `d`. Sau đó với mỗi cạnh $(u, v)$, nếu $d_a[u]+1+d_b[v]=d_a[b]$, thì cạnh đó nằm trên một đường đi ngắn nhất.
-   Tìm các đỉnh chắc chắn nằm trên một đường đi ngắn nhất từ $a$ đến $b$. Thực hiện BFS lần lượt từ $a$ và $b$ để thu được hai mảng `d`. Sau đó với mỗi đỉnh `v`, nếu $d_a[v]+d_b[v]=d_a[b]$, thì đỉnh đó nằm trên một đường đi ngắn nhất nào đó.
-   Tìm một đường đi ngắn nhất có độ dài chẵn. Ta cần xây dựng một đồ thị mới bằng cách tách mỗi đỉnh thành hai đỉnh mới; cạnh $(u, v)$ của đồ thị ban đầu trở thành $((u, 0), (v, 1))$ và $((u, 1), (v, 0))$. Chạy BFS trên đồ thị mới, đường đi ngắn nhất giữa $(s, 0)$ và $(t, 0)$ chính là đáp án cần tìm.
-   Tìm đường đi ngắn nhất trên một đồ thị có trọng số cạnh là 0/1, xem phần BFS hai đầu hàng đợi bên dưới.

## BFS hai đầu hàng đợi

Nếu bạn chưa biết hàng đợi hai đầu `deque`, hãy tham khảo [phần liên quan đến deque](../lang/csl/sequence-container.md#deque).

BFS hai đầu hàng đợi còn được gọi là 0-1 BFS.

### Phạm vi áp dụng

Các bài toán đường đi ngắn nhất trong đó trọng số cạnh có thể tồn tại hoặc không tồn tại, hoặc có thể được chuyển đổi thành dạng trọng số như vậy. Vì BFS áp dụng cho đồ thị có trọng số bằng 1, nên thông thường các trọng số này là 0 hoặc 1.

Ví dụ trong bài toán đi mê cung, bạn có thể tốn 1 đồng xu để đi 5 bước, hoặc không tốn đồng xu để đi 1 bước. Bài toán này có thể được giải bằng 0-1 BFS.

### Cài đặt

Trong trường hợp thông thường, ta đưa đỉnh được mở rộng qua cạnh không có trọng số vào đầu hàng đợi, và đưa đỉnh được mở rộng qua cạnh có trọng số vào cuối hàng đợi. Như vậy có thể bảo đảm rằng, giống như BFS thông thường, trọng số trong toàn bộ hàng đợi sẽ không giảm từ đầu đến cuối.

Dưới đây là mã giả:

```cpp
while (!q.empty()) {
  int u = q.front();
  q.pop_front();
  for (int v : adj[u]) {
    update_data(u, v);
    if (is_zero_weight_edge(u, v))
      q.push_front(v);
    else
      q.push_back(v);
  }
}
```

### Bài tập ví dụ

### [Codeforces 173B](http://codeforces.com/problemset/problem/173/B)

Cho một lưới $n \times m$. Hiện có một tia laser bắn từ góc trên bên trái sang bên phải. Mỗi khi gặp ký tự '#', bạn có thể chọn cho tia sáng bắn ra theo bốn hướng hoặc không làm gì cả. Hỏi cần ít nhất bao nhiêu ký tự '#' bắn ra theo bốn hướng để tia sáng có thể bắn ra bên phải ở hàng thứ $n$.

Lời giải chuẩn của bài này không phải là 0-1 BFS, nhưng bài toán có thể áp dụng 0-1 BFS để giảm độ khó tư duy. Trong lúc thi, nhiều cao thủ cũng làm như vậy.

Cách làm rất đơn giản: bắn ra theo một hướng không cần chi phí, tức 0, còn bắn ra theo bốn hướng cần chi phí, tức 1, sau đó chạy trực tiếp là được.

#### Mã nguồn

```cpp
--8<-- "docs/graph/code/bfs/bfs_1.cpp"
```

## BFS hàng đợi ưu tiên

Hàng đợi ưu tiên tương đương với một heap nhị phân. STL cung cấp [`std::priority_queue`](../lang/csl/container-adapter.md), giúp ta sử dụng hàng đợi ưu tiên một cách thuận tiện.

Trong BFS dựa trên hàng đợi ưu tiên, mỗi lần ta lấy ra từ đầu hàng đợi đỉnh có chi phí nhỏ nhất để tiếp tục tìm kiếm. Có thể dễ dàng chứng minh tư tưởng tham lam này là đúng, vì phần tìm kiếm mở rộng từ đỉnh này chắc chắn sẽ không cập nhật những đỉnh vốn có chi phí cao hơn. Nói cách khác, với những đỉnh còn lại có chi phí cao hơn, ta không quay lại xét để cập nhật chúng.

Tất nhiên, mỗi đỉnh có thể được đưa vào hàng đợi nhiều lần, chỉ là chi phí của mỗi lần đưa vào khác nhau. Khi đỉnh đó lần đầu tiên được lấy ra khỏi hàng đợi ưu tiên, về sau không cần tiếp tục tìm kiếm từ đỉnh đó nữa, chỉ cần bỏ qua trực tiếp. Vì vậy, trong BFS dùng hàng đợi ưu tiên, mỗi đỉnh chỉ được xử lý một lần.

So với BFS dùng hàng đợi thông thường, độ phức tạp thời gian có thêm một thừa số $\log n$, bởi dù sao ta cũng phải duy trì hàng đợi ưu tiên này. Tuy nhiên, trong BFS thông thường, mỗi đỉnh cũng có thể vào hàng đợi và ra khỏi hàng đợi nhiều lần, khiến độ phức tạp thời gian đạt tới $O(n^2)$ chứ không phải $O(n)$. Vì vậy BFS hàng đợi ưu tiên thường vẫn nhanh hơn.

Nghe có vẻ rất giống thuật toán [Dijkstra](./shortest-path.md#dijkstra-%E7%AE%97%E6%B3%95) tối ưu bằng heap phải không? Thật ra, Dijkstra tối ưu bằng heap chính là BFS hàng đợi ưu tiên.

## Bài tập

-   [NOIP2017 Cheese](https://uoj.ac/problem/332)

BFS hai đầu hàng đợi:

-   [CF1063B. Labyrinth](https://codeforces.com/problemset/problem/1063/B)
-   [CF173B. Chamber of Secrets](https://codeforces.com/problemset/problem/173/B)
-   [BalticOI 2011 Day1. Switch the Lamp On](https://loj.ac/p/2632)

## Tham khảo

<https://cp-algorithms.com/graph/breadth-first-search.html>
