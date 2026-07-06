author: Anguei, sshwy, Xeonacid, Ir1d, MonkeyOliver, hsfzLZH1

Tách đỉnh là một tư tưởng mô hình hóa trong lý thuyết đồ thị, thường dùng trong [luồng mạng](./flow.md) để xử lý các bài toán có **trọng số đỉnh hoặc giới hạn lưu lượng qua đỉnh**, và cũng thường dùng trong **đồ thị phân tầng**.

## Luồng cực đại khi đỉnh có giới hạn lưu lượng

Nếu chuyển đỉnh thành cạnh, có thể áp dụng trực tiếp khuôn mẫu lời giải.

Xét cách chuyển một đỉnh có giới hạn lưu lượng thành cấu trúc sau: một phần gồm hai đỉnh $u,v$ và một cạnh $\left\langle u,v \right\rangle$. Trong đó, đỉnh $u$ nhận tất cả các cạnh đi từ những đỉnh khác trong đồ thị gốc đến đỉnh này, còn đỉnh $v$ phát ra tất cả các cạnh đi từ đỉnh này đến những đỉnh khác trong đồ thị gốc. Giới hạn lưu lượng của cạnh $\left\langle u,v \right\rangle$ chính là giới hạn lưu lượng của đỉnh tương ứng trong đồ thị gốc. Sau đó chỉ cần áp dụng khuôn mẫu là giải được bài toán. Đây là tư tưởng cơ bản của tách đỉnh.

Nếu đồ thị gốc như sau:

![](./images/node.svg)

Sau khi tách đỉnh, đồ thị có dạng:

![](./images/node-split.svg)

## Đường đi ngắn nhất trên đồ thị phân tầng

Đường đi ngắn nhất trên đồ thị phân tầng, chẳng hạn: được phép đi qua $k$ cạnh với chi phí bằng không, cần tìm tổng chi phí nhỏ nhất. Với dạng bài này, có thể dùng tư tưởng liên quan đến DP. Đặt $\text{dis}_{i, j}$ là đường đi ngắn nhất hiện tại khi đến đỉnh $i$ từ đỉnh xuất phát sau khi đã dùng $j$ lượt đi miễn phí. Mảng $\text{dis}$ có thể chuyển như sau:

$\text{dis}_{i, j} = \min\{\min\{\text{dis}_{from, j - 1}\}, \min\{\text{dis}_{from,j} + w\}\}$

Trong đó, $from$ biểu diễn đỉnh cha của $i$, còn $w$ biểu diễn trọng số của cạnh đang đi. Khi $j - 1 \geq k$, $\text{dis}_{from, j}$=$\infty$.

Thực ra, DP này tương đương với việc tách mỗi đỉnh thành $k+1$ đỉnh, mỗi đỉnh mới biểu diễn việc đến đỉnh tương ứng trong đồ thị gốc sau khi đã dùng một số lượt đi miễn phí khác nhau. Nói cách khác, mỗi đỉnh $u_i$ biểu diễn trạng thái đến đỉnh $u$ sau khi đã dùng $i$ lượt đi miễn phí.

??? note "[\[JLOI2011\] Đường bay](https://www.luogu.com.cn/problem/P4568)"
    Đề bài: cho một đồ thị vô hướng có $n$ đỉnh và $m$ cạnh, được phép chọn $k$ con đường để đi với chi phí bằng không. Cần tìm chi phí nhỏ nhất từ $s$ đến $t$.
    
    Mã lõi tham khảo:
    
    ```cpp
    struct State {    // Cấu trúc đỉnh trong hàng đợi ưu tiên
      int v, w, cnt;  // cnt biểu diễn số lượt đi miễn phí đã dùng
    
      State() {}
    
      State(int v, int w, int cnt) : v(v), w(w), cnt(cnt) {}
    
      bool operator<(const State &rhs) const { return w > rhs.w; }
    };
    
    void dijkstra() {
      memset(dis, 0x3f, sizeof dis);
      dis[s][0] = 0;
      pq.push(State(s, 0, 0));  // Đến điểm xuất phát không cần dùng lượt miễn phí, khoảng cách bằng không
      while (!pq.empty()) {
        const State top = pq.top();
        pq.pop();
        int u = top.v, nowCnt = top.cnt;
        if (done[u][nowCnt]) continue;
        done[u][nowCnt] = true;
        for (int i = head[u]; i; i = edge[i].next) {
          int v = edge[i].v, w = edge[i].w;
          if (nowCnt < k && dis[v][nowCnt + 1] > dis[u][nowCnt]) {  // Dùng lượt đi miễn phí
            dis[v][nowCnt + 1] = dis[u][nowCnt];
            pq.push(State(v, dis[v][nowCnt + 1], nowCnt + 1));
          }
          if (dis[v][nowCnt] > dis[u][nowCnt] + w) {  // Không dùng lượt đi miễn phí
            dis[v][nowCnt] = dis[u][nowCnt] + w;
            pq.push(State(v, dis[v][nowCnt], nowCnt));
          }
        }
      }
    }
    
    int main() {
      n = read(), m = read(), k = read();
      // Tác giả quen đánh số từ 1 đến n, còn bài này đánh số từ 0 đến n - 1, nên cần xử lý thêm
      s = read() + 1, t = read() + 1;
      while (m--) {
        int u = read() + 1, v = read() + 1, w = read();
        add(u, v, w), add(v, u, w);  // Bài này dùng cạnh hai chiều
      }
      dijkstra();
      int ans = std::numeric_limits<int>::max();  // Khởi tạo ans bằng giá trị int lớn nhất
      for (int i = 0; i <= k; ++i)
        ans = std::min(ans, dis[t][i]);  // Lấy giá trị tốt nhất trong mọi trường hợp đến đích
      println(ans);
    }
    ```
