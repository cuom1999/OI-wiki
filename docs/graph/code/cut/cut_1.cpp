/*
Luogu P3388 Mẫu: điểm khớp (đỉnh cắt)
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m;  // n: số đỉnh, m: số cạnh.
int dfn[100001], low[100001], idx, res;
// dfn: ghi timestamp của mỗi đỉnh.
// low: số hiệu nhỏ nhất có thể đến mà không đi qua cha; idx: timestamp; res: số đáp án.
bool vis[100001], flag[100001];  // flag: đáp án, vis: đánh dấu để tránh lặp.
vector<int> edge[100001];        // Dùng để lưu đồ thị.

void Tarjan(int u, int fa) {  // u là số hiệu đỉnh hiện tại, fa là cha của nó.
  vis[u] = true;              // Đánh dấu.
  low[u] = dfn[u] = ++idx;    // Gán timestamp.
  int child = 0;              // Số con của mỗi đỉnh.
  for (const auto &v : edge[u]) {  // Duyệt mọi láng giềng của đỉnh này (C++11).
    if (!vis[v]) {
      child++;                       // Thêm một con.
      Tarjan(v, u);                  // Tiếp tục.
      low[u] = min(low[u], low[v]);  // Cập nhật số hiệu nhỏ nhất có thể đến.
      if (fa != u && low[v] >= dfn[u] && !flag[u]) {  // Phần chính.
        // Nếu không phải gốc, điểm nhỏ nhất quay về mà không qua cha thỏa điều kiện
        // điểm khớp, và đỉnh này chưa bị đánh dấu.
        // Điều kiện là: xóa cha thì không nối được nữa, tức xa nhất chỉ nối về cha.
        flag[u] = true;
        res++;  // Ghi đáp án.
      }
    } else if (v != fa) {
      // Nếu đỉnh này không phải cha, cập nhật số hiệu nhỏ nhất có thể đến.
      low[u] = min(low[u], dfn[v]);
    }
  }
  // Phần chính: nếu là gốc thì cần ít nhất 2 con.
  if (fa == u && child >= 2 && !flag[u]) {
    flag[u] = true;
    res++;  // Ghi đáp án.
  }
}

int main() {
  cin >> n >> m;                  // Đọc dữ liệu.
  for (int i = 1; i <= m; i++) {  // Chú ý các đỉnh bắt đầu từ 1.
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }  // Dùng vector để lưu đồ thị.
  for (int i = 1; i <= n; i++)  // Vì đồ thị trong Tarjan không nhất thiết liên thông.
    if (!vis[i]) {
      idx = 0;       // Timestamp khởi tạo bằng 0.
      Tarjan(i, i);  // Bắt đầu từ đỉnh i, cha là chính nó.
    }
  cout << res << endl;
  for (int i = 1; i <= n; i++)
    if (flag[i]) cout << i << " ";  // In kết quả.
  return 0;
}
