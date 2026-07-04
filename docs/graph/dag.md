## Định nghĩa

Các cạnh đều có hướng, và đồ thị không có chu trình.

Tên tiếng Anh là Directed Acyclic Graph, viết tắt là DAG.

## Tính chất

-   Một đồ thị có thể [sắp xếp tô pô](./topo.md) chắc chắn là đồ thị có hướng không chu trình;

    Nếu tồn tại chu trình, thì với các đỉnh trên chu trình, mọi thứ tự tuyến tính đều không thể thỏa mãn điều kiện.

-   Một đồ thị có hướng không chu trình chắc chắn có thể sắp xếp tô pô;

    (Chứng minh bằng quy nạp) Giả sử mọi đồ thị có hướng không chu trình với số đỉnh không vượt quá $k$ đều có thể sắp xếp tô pô. Với trường hợp có đúng $k$ đỉnh, chỉ cần xét tình huống sau khi thực hiện bước đầu tiên của sắp xếp tô pô.

## Kiểm tra

Làm thế nào để kiểm tra một đồ thị có phải là đồ thị có hướng không chu trình?

Chỉ cần kiểm tra xem nó có thể [sắp xếp tô pô](./topo.md) hay không.

Dĩ nhiên cũng có cách khác: chạy một lượt [DFS](../search/dfs.md) trên đồ thị, rồi trên cây DFS thu được kiểm tra xem có cạnh không thuộc cây nào đi tới tổ tiên (cạnh ngược) hay không. Nếu có, đồ thị chứa chu trình.

## Ứng dụng

### Dùng DP tìm đường đi dài nhất (ngắn nhất)

Trên đồ thị tổng quát, độ phức tạp thời gian tốt nhất để tìm đường đi dài nhất (ngắn nhất) đơn nguồn là $O(nm)$ ([thuật toán Bellman–Ford](./shortest-path.md#thuật-toán-bellman-ford), dùng được cho đồ thị có trọng số âm) hoặc $O(m \log m)$ ([thuật toán Dijkstra](./shortest-path.md#thuật-toán-dijkstra), dùng cho đồ thị không có trọng số âm).

Nhưng trên DAG, ta có thể dùng DP để tìm đường đi dài nhất (ngắn nhất), đưa độ phức tạp thời gian xuống $O(n+m)$. Phương trình chuyển trạng thái là $dis_v = min(dis_v, dis_u + w_{u,v})$ hoặc $dis_v = max(dis_v, dis_u + w_{u,v})$.

Sau khi sắp xếp tô pô, duyệt từng đỉnh theo thứ tự tô pô và dùng đỉnh hiện tại để cập nhật các đỉnh đứng sau nó.

```cpp
struct edge {
  int v, w;
};

int n, m;
vector<edge> e[MAXN];
vector<int> L;                               // Lưu kết quả sắp xếp tô pô
int max_dis[MAXN], min_dis[MAXN], in[MAXN];  // in lưu bậc vào của từng đỉnh

void toposort() {  // Sắp xếp tô pô
  queue<int> S;
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < e[i].size(); j++) {
      in[e[i][j].v]++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (in[i] == 0) S.push(i);
  while (!S.empty()) {
    int u = S.front();
    S.pop();
    L.push_back(u);
    for (int i = 0; i < e[u].size(); i++) {
      if (--in[e[u][i].v] == 0) {
        S.push(e[u][i].v);
      }
    }
  }
}

void dp(int s) {  // Tìm đường đi dài nhất (ngắn nhất) đơn nguồn từ s
  toposort();     // Trước hết sắp xếp tô pô
  memset(min_dis, 0x3f, sizeof(min_dis));
  memset(max_dis, 0, sizeof(max_dis));
  min_dis[s] = 0;
  for (int i = 0; i < L.size(); i++) {
    int u = L[i];
    for (int j = 0; j < e[u].size(); j++) {
      min_dis[e[u][j].v] = min(min_dis[e[u][j].v], min_dis[u] + e[u][j].w);
      max_dis[e[u][j].v] = max(max_dis[e[u][j].v], max_dis[u] + e[u][j].w);
    }
  }
}
```

Xem thêm: [DP trên DAG](../dp/dag.md).
