author: Ir1d, Anguei, hsfzLZH1

## Định nghĩa

**Hệ ràng buộc hiệu** là một hệ bất đẳng thức tuyến tính đặc biệt với $n$ ẩn. Nó gồm $n$ biến $x_1,x_2,\dots,x_n$ và $m$ điều kiện ràng buộc; mỗi ràng buộc được tạo từ hiệu của hai biến, có dạng $x_i-x_j\leq c_k$, trong đó $1 \leq i, j \leq n, i \neq j, 1 \leq k \leq m$, và $c_k$ là một hằng số (có thể không âm hoặc âm). Bài toán cần giải là: tìm một bộ nghiệm $x_1=a_1,x_2=a_2,\dots,x_n=a_n$ sao cho mọi ràng buộc đều được thỏa mãn; nếu không tồn tại thì kết luận vô nghiệm.

Mỗi ràng buộc $x_i-x_j\leq c_k$ trong hệ ràng buộc hiệu đều có thể biến đổi thành $x_i\leq x_j+c_k$, rất giống bất đẳng thức tam giác $dist[y]\leq dist[x]+z$ trong bài toán đường đi ngắn nhất một nguồn. Vì vậy, ta có thể xem mỗi biến $x_i$ là một đỉnh trong đồ thị; với mỗi ràng buộc $x_i-x_j\leq c_k$, nối một cạnh có hướng độ dài $c_k$ từ đỉnh $j$ đến đỉnh $i$.

Chú ý rằng nếu $\{a_1,a_2,\dots,a_n\}$ là một nghiệm của hệ ràng buộc hiệu này, thì với hằng số bất kỳ $d$, $\{a_1+d,a_2+d,\dots,a_n+d\}$ hiển nhiên cũng là một nghiệm, vì khi lấy hiệu thì $d$ vừa khéo bị triệt tiêu.

## Quy trình

Đặt $dist[0]=0$ và nối từ đỉnh này đến mỗi đỉnh khác một cạnh trọng số $0$, rồi chạy thuật toán đường đi ngắn nhất một nguồn. Nếu trong đồ thị tồn tại chu trình âm, hệ ràng buộc hiệu đã cho vô nghiệm; ngược lại, $x_i=dist[i]$ là một nghiệm của hệ.

## Tính chất

Thông thường dùng Bellman–Ford hoặc Bellman–Ford tối ưu bằng hàng đợi (thường gọi là SPFA, chạy rất nhanh trên một số đồ thị ngẫu nhiên) để kiểm tra đồ thị có chu trình âm hay không. Độ phức tạp thời gian xấu nhất là $O(nm)$.

## Các kỹ thuật biến đổi thường dùng

### Ví dụ [Luogu P1993 Trang trại của K nhỏ](https://www.luogu.com.cn/problem/P1993)

Tóm tắt đề bài: giải một hệ ràng buộc hiệu có $m$ ràng buộc, mỗi ràng buộc có dạng $x_a-x_b\geq c_k$, $x_a-x_b\leq c_k$ hoặc $x_a=x_b$. Hãy xác định hệ ràng buộc hiệu này có nghiệm hay không.

|       Ý nghĩa       |                  Biến đổi                   |            Nối cạnh             |
| :----------------: | :-----------------------------------------: | :---------------------------: |
| $x_a - x_b \geq c$ |             $x_b - x_a \leq -c$             |        `add(a, b, -c);`       |
| $x_a - x_b \leq c$ |              $x_a - x_b \leq c$             |        `add(b, a, c);`        |
|     $x_a = x_b$    | $x_a - x_b \leq 0, \space x_b - x_a \leq 0$ | `add(b, a, 0), add(a, b, 0);` |

Chạy kiểm tra chu trình âm. Nếu không tồn tại chu trình âm thì in `Yes`, ngược lại in `No`.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/diff-constraints/diff-constraints_1.cpp"
    ```

### Ví dụ [P4926\[1007\] Người đo double kill](https://www.luogu.com.cn/problem/P4926)

Không xét các phần khác như tìm kiếm nhị phân; ở đây chỉ trình bày cách giải hệ ràng buộc dạng $\frac{x_i}{x_j}\leq c_k$.

Lấy $\log$ cho từng $x_i,x_j$ và $c_k$ sẽ biến phép nhân thành phép cộng, tức là $\log x_i-\log x_j \leq \log c_k$; khi đó có thể dùng ràng buộc hiệu để giải.

## Cài đặt Bellman–Ford để kiểm tra chu trình âm

Dưới đây là cài đặt dùng thuật toán Bellman–Ford để kiểm tra đồ thị có chu trình âm hay không. Trước khi gọi, hãy bảo đảm đồ thị là liên thông.

???+ note "Cài đặt"
    === "C++"
        ```cpp
        bool Bellman_Ford() {
          for (int i = 0; i < n; i++) {
            bool jud = false;
            for (int j = 1; j <= n; j++)
              for (int k = h[j]; ~k; k = nxt[k])
                if (dist[j] > dist[p[k]] + w[k])
                  dist[j] = dist[p[k]] + w[k], jud = true;
            if (!jud) break;
          }
          for (int i = 1; i <= n; i++)
            for (int j = h[i]; ~j; j = nxt[j])
              if (dist[i] > dist[p[j]] + w[j]) return false;
          return true;
        }
        ```
    
    === "Python"
        ```python
        def Bellman_Ford():
            for i in range(0, n):
                jud = False
                for j in range(1, n + 1):
                    while ~k:
                        k = h[j]
                        if dist[j] > dist[p[k]] + w[k]:
                            dist[j] = dist[p[k]] + w[k]
                            jud = True
                        k = nxt[k]
                if jud == False:
                    break
            for i in range(1, n + 1):
                while ~j:
                    j = h[i]
                    if dist[i] > dist[p[j]] + w[j]:
                        return False
                    j = nxt[j]
            return True
        ```

## Bài tập

[USACO 2006 December Wormholes](https://loj.ac/problem/10085)

[SCOI2011 Candy](https://loj.ac/problem/2436)

[POJ 1364 King](http://poj.org/problem?id=1364)

[POJ 2983 Is the Information Reliable?](http://poj.org/problem?id=2983)
