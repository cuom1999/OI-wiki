author: Ir1d, sshwy, GavinZhengOI, Planet6174, ouuan, Marcythm, ylxmf2005, 0xis-cn

Đọc thêm: [thành phần song liên thông](./bcc.md)

Định nghĩa chặt chẽ hơn của đỉnh khớp và cầu có thể xem ở [khái niệm liên quan đến lý thuyết đồ thị](./concept.md).

## Đỉnh khớp

> Với một đồ thị vô hướng, nếu sau khi xóa một đỉnh mà số thành phần liên thông cực đại của đồ thị tăng lên, thì đỉnh đó là một đỉnh khớp, còn gọi là đỉnh cắt.

### Quy trình

Việc lần lượt xóa từng đỉnh rồi kiểm tra tính liên thông của đồ thị có độ phức tạp rất cao. Phần này giới thiệu một thuật toán thường dùng: Tarjan.

Trước hết, xét đồ thị sau:

![](./images/cut1.svg)

Đỉnh khớp trong đồ thị này là 2, đồng thời đó cũng là đỉnh khớp duy nhất.

Đầu tiên, gán nhãn thời gian theo thứ tự DFS, tức thứ tự các đỉnh được thăm.

![](./images/cut2.svg)

Các thông tin này được lưu trong mảng `dfn`.

Cần thêm một mảng khác là `low`, dùng để lưu nhãn thời gian nhỏ nhất có thể đi tới mà không đi qua cha của đỉnh hiện tại.

Ví dụ, `low[2]` bằng 1, còn `low[5]` và `low[6]` bằng 3.

Sau đó bắt đầu DFS.
Tiêu chí xác định một đỉnh có phải đỉnh khớp hay không là: với một đỉnh $u$, nếu tồn tại ít nhất một đỉnh $v$ là con của $u$ sao cho $low_v \geq dfn_u$, thì $u$ là đỉnh khớp.
Điều kiện này nghĩa là nhánh con đó không thể quay về tổ tiên của $u$.

Riêng đỉnh bắt đầu DFS không áp dụng trực tiếp tiêu chí trên và cần xét riêng.
Nếu đỉnh đó không phải đỉnh khớp, các đường đi khác vẫn có thể đi tới tất cả các đỉnh.
Khi đó từ đỉnh bắt đầu chỉ có một lần tìm kiếm "đi xuống", tức trong cây DFS nó chỉ có một con.
Nếu trong cây DFS nó có từ hai con trở lên, đỉnh đó là đỉnh khớp.
Trong hình trên, nếu bắt đầu tìm kiếm từ 2, cây DFS sẽ có hai con: một trong 3 hoặc 4, và một trong 5 hoặc 6.
Nếu nó chỉ có một con, việc xóa nó sẽ không gây ảnh hưởng.
Chẳng hạn trong đồ thị dưới đây, các đỉnh tạo thành một chu trình.

![](./images/cut3.svg)

Khi thăm các con của 1, giả sử DFS đi tới 2 trước và đánh dấu đã thăm, rồi tiếp tục đệ quy xuống 4, sau đó từ 4 đi tới 3. Khi đệ quy quay lui, sẽ phát hiện 3 đã được thăm, vì vậy 1 không phải là đỉnh khớp.

Mã giả cập nhật `low` như sau:

$$
\begin{array}{ll}
1 & \textbf{nếu } v \text{ là con của } u \\
2 & \qquad \text{low}_u = \min(\text{low}_u, \text{low}_v) \\
3 & \textbf{ngược lại} \\
4 & \qquad \text{low}_u = \min(\text{low}_u, \text{dfn}_v) \\
\end{array}
$$

### Ví dụ

[Luogu P3388 [Mẫu] Đỉnh khớp (đỉnh cắt)](https://www.luogu.com.cn/problem/P3388)

??? note "Mã nguồn ví dụ"
    ```cpp
    --8<-- "docs/graph/code/cut/cut_1.cpp"
    ```

## Cầu khi không có cạnh bội

Khái niệm này tương tự đỉnh khớp và thường được gọi là cầu.

> Với một đồ thị vô hướng, nếu sau khi xóa một cạnh mà số thành phần liên thông trong đồ thị tăng lên, thì cạnh đó được gọi là cầu hoặc cạnh cắt.
> Nói chặt chẽ hơn: giả sử có đồ thị liên thông $G=\{V,E\}$ và $e$ là một cạnh của nó, tức $e \in E$.
> Nếu $G-e$ không liên thông, thì cạnh $e$ là một cạnh cắt, hay một cầu, của đồ thị $G$.

Ví dụ, trong hình dưới đây:

![Hình minh họa cầu](./images/bridge1.svg)

Các cạnh màu đỏ chính là cầu.

### Quy trình

Cách làm gần giống đỉnh khớp, chỉ cần đổi một chỗ thành điều kiện $low_v>dfn_u$ là được, và không cần xét riêng đỉnh gốc.

Việc một cạnh có phải cầu hay không không phụ thuộc vào đỉnh gốc.
Khi tìm đỉnh khớp, cần xét việc đỉnh $v$ không thể quay về một tổ tiên, kể cả cha, nếu không đi qua cha $u$, nên đỉnh $u$ là đỉnh khớp.
Nếu $low_v=dfn_u$ thì vẫn có thể quay về cha.
Chỉ khi đỉnh $v$ không thể quay về tổ tiên và cũng không có đường nào khác quay về cha, cạnh $u-v$ mới là cầu.

### Cài đặt

Đoạn mã dưới đây tìm cầu trong đồ thị vô hướng **không có cạnh bội**. Trong đó, khi `isbridge[x]` là đúng, `(father[x],x)` là một cầu.

=== "C++"
    ```cpp
    int low[MAXN], dfn[MAXN], idx;
    bool isbridge[MAXN];
    vector<int> G[MAXN];
    int cnt_bridge;
    int father[MAXN];
    
    void tarjan(int u, int fa) {
      father[u] = fa;
      low[u] = dfn[u] = ++idx;
      for (const auto &v : G[u]) {
        if (!dfn[v]) {
          tarjan(v, u);
          low[u] = min(low[u], low[v]);
          if (low[v] > dfn[u]) {
            isbridge[v] = true;
            ++cnt_bridge;
          }
        } else if (v != fa) {
          low[u] = min(low[u], dfn[v]);
        }
      }
    }
    ```

=== "Python"
    ```python
    low = [0] * MAXN
    dfn = [0] * MAXN
    idx = 0
    isbridge = [False] * MAXN
    G = [[0 for i in range(MAXN)] for j in range(MAXN)]
    cnt_bridge = 0
    father = [0] * MAXN
    
    
    def tarjan(u, fa):
        father[u] = fa
        idx = idx + 1
        low[u] = dfn[u] = idx
        for i in range(0, len(G[u])):
            v = G[u][i]
            if dfn[v] == False:
                tarjan(v, u)
                low[u] = min(low[u], low[v])
                if low[v] > dfn[u]:
                    isbridge[v] = True
                    cnt_bridge = cnt_bridge + 1
            elif v != fa:
                low[u] = min(low[u], dfn[v])
    ```

## Cầu khi có cạnh bội

Tuy nhiên, cách làm ở trên cho trường hợp không có cạnh bội sẽ gặp vấn đề trên đồ thị vô hướng có cạnh bội.

Vì giữa hai đỉnh có thể có nhiều hơn một cạnh, nên trong trường hợp đó không cạnh nào giữa chúng là cầu.

### Quy trình

Một hướng xử lý là đổi tham số `fa` thành chỉ số của cạnh vừa đi qua (mỗi cạnh có một chỉ số thống nhất), tức đổi "không dùng đỉnh cha để cập nhật" thành "không dùng cạnh vừa đi tới để cập nhật".

Một cách đơn giản hơn là đặt một cờ để xác định liệu đã có một cạnh đi tới đỉnh cha hay chưa; sau khi đã đánh dấu, nếu lại gặp đỉnh cha thì cập nhật bình thường.

Đoạn mã dưới đây tìm cầu trong đồ thị vô hướng có thể **có cạnh bội**.

=== "C++"
    ```cpp
    int low[MAXN], dfn[MAXN], idx;
    bool isbridge[MAXN];
    vector<int> G[MAXN];
    int cnt_bridge;
    int father[MAXN];
    
    void tarjan(int u, int fa) {
      bool flag = false;
      father[u] = fa;
      low[u] = dfn[u] = ++idx;
      for (const auto &v : G[u]) {
        if (!dfn[v]) {
          tarjan(v, u);
          low[u] = min(low[u], low[v]);
          if (low[v] > dfn[u]) {
            isbridge[v] = true;
            ++cnt_bridge;
          }
        } else {
          if (v != fa || flag)
            low[u] = min(low[u], dfn[v]);
          else
            flag = true;
        }
      }
    }
    ```

## Bài tập

-   [P3388 [Mẫu] Đỉnh khớp (đỉnh cắt)](https://www.luogu.com.cn/problem/P3388)
-   [POJ2117 Điện lực](http://poj.org/problem?id=2117)
-   [HDU4738 Những cây cầu của Tào Tháo](https://acm.hdu.edu.cn/showproblem.php?pid=4738)
-   [HDU2460 Mạng](https://acm.hdu.edu.cn/showproblem.php?pid=2460)
-   [POJ1523 SPF](http://poj.org/problem?id=1523)

Thuật toán Tarjan còn có nhiều ứng dụng khác, thường gặp như tìm thành phần liên thông mạnh, co đỉnh, giải 2-SAT, v.v.
