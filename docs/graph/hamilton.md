## Định nghĩa

Một đường đi của đồ thị đi qua tất cả các đỉnh đúng một lần được gọi là đường đi Hamilton.

Một chu trình của đồ thị đi qua tất cả các đỉnh đúng một lần được gọi là chu trình Hamilton.

Đồ thị có chu trình Hamilton được gọi là đồ thị Hamilton.

Đồ thị có đường đi Hamilton nhưng không có chu trình Hamilton được gọi là đồ thị nửa Hamilton.

## Tính chất

Giả sử $G=\langle V, E\rangle$ là đồ thị Hamilton. Khi đó, với mọi tập con thực sự không rỗng $V_1$ của $V$, ta đều có $p(G-V_1) \leq |V_1|$, trong đó $p(x)$ là số thành phần liên thông của $x$.

Hệ quả: giả sử $G=\langle V, E\rangle$ là đồ thị nửa Hamilton. Khi đó, với mọi tập con thực sự không rỗng $V_1$ của $V$, ta đều có $p(G-V_1) \leq |V_1|+1$, trong đó $p(x)$ là số thành phần liên thông của $x$.

Đồ thị đầy đủ $K_{2k+1} (k \geq 1)$ chứa $k$ chu trình Hamilton đôi một không chung cạnh, và $k$ chu trình Hamilton không chung cạnh này chứa tất cả các cạnh của $K_{2k+1}$.

Đồ thị đầy đủ $K_{2k} (k \geq 2)$ chứa $k-1$ chu trình Hamilton đôi một không chung cạnh; sau khi xóa $k-1$ chu trình Hamilton không chung cạnh này khỏi $K_{2k}$, đồ thị thu được chứa $k$ cạnh đôi một không kề nhau.

## Điều kiện đủ

Giả sử $G$ là đồ thị vô hướng đơn có $n(n \geq 2)$ đỉnh. Nếu với mọi cặp đỉnh không kề nhau $v_i, v_j$ trong $G$, ta đều có $d(v_i)+ d(v_j) \geq n - 1$, thì $G$ có đường đi Hamilton.

Hệ quả 1: giả sử $G$ là đồ thị vô hướng đơn có $n(n \geq 3)$ đỉnh. Nếu với mọi cặp đỉnh không kề nhau $v_i, v_j$ trong $G$, ta đều có $d(v_i)+ d(v_j) \geq n$, thì $G$ có chu trình Hamilton, do đó $G$ là đồ thị Hamilton.

Hệ quả 2: giả sử $G$ là đồ thị vô hướng đơn có $n(n \geq 3)$ đỉnh. Nếu với mọi đỉnh $v_i$ trong $G$, ta đều có $d(v_i) \geq \frac{n}{2}$, thì $G$ có chu trình Hamilton, do đó $G$ là đồ thị Hamilton.

Giả sử $D$ là một đồ thị đấu loại (tournament graph) có $n(n \geq 2)$ đỉnh. Khi đó $D$ có đường đi Hamilton.

Nếu $D$ chứa một đồ thị đấu loại có $n(n \geq 2)$ đỉnh làm đồ thị con, thì $D$ có đường đi Hamilton.

Đồ thị đấu loại liên thông mạnh là đồ thị Hamilton.

Nếu $D$ chứa một đồ thị đấu loại liên thông mạnh có $n(n \geq 2)$ đỉnh làm đồ thị con, thì $D$ có chu trình Hamilton.
