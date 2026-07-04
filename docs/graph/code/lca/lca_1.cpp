#include <cstring>
#include <iostream>
#include <vector>

constexpr int MXN = 40005;
using namespace std;
vector<int> v[MXN];
vector<int> w[MXN];

int fa[MXN][31], cost[MXN][31], dep[MXN];
int n, m;
int a, b, c;

// DFS để chuẩn bị cho thuật toán LCA. Nhận hai tham số: đỉnh bắt đầu DFS và cha của nó.
void dfs(int root, int fno) {
  // Khởi tạo: tổ tiên thứ 2^0 = 1 chính là cha, dep cũng lớn hơn cha 1.
  fa[root][0] = fno;
  dep[root] = dep[fa[root][0]] + 1;
  // Khởi tạo các tổ tiên khác: tổ tiên thứ 2^i là tổ tiên thứ 2^(i-1) của
  // tổ tiên thứ 2^(i-1).
  for (int i = 1; i < 31; ++i) {
    fa[root][i] = fa[fa[root][i - 1]][i - 1];
    cost[root][i] = cost[fa[root][i - 1]][i - 1] + cost[root][i - 1];
  }
  // Duyệt các đỉnh con để DFS.
  int sz = v[root].size();
  for (int i = 0; i < sz; ++i) {
    if (v[root][i] == fno) continue;
    cost[v[root][i]][0] = w[root][i];
    dfs(v[root][i], root);
  }
}

// LCA: dùng thuật toán nhân đôi để tính LCA của x và y.
int lca(int x, int y) {
  // Đảm bảo y sâu hơn x.
  if (dep[x] > dep[y]) swap(x, y);
  // Đưa y và x về cùng độ sâu.
  int tmp = dep[y] - dep[x], ans = 0;
  for (int j = 0; tmp; ++j, tmp >>= 1)
    if (tmp & 1) ans += cost[y][j], y = fa[y][j];
  // Nếu lúc này y = x, thì x và y đều là tổ tiên của chính chúng.
  if (y == x) return ans;
  // Nếu không, tìm hai điểm đầu tiên chưa phải là tổ tiên của chúng.
  for (int j = 30; j >= 0 && y != x; --j) {
    if (fa[x][j] != fa[y][j]) {
      ans += cost[x][j] + cost[y][j];
      x = fa[x][j];
      y = fa[y][j];
    }
  }
  // Trả về kết quả.
  ans += cost[x][0] + cost[y][0];
  return ans;
}

void Solve() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // Khởi tạo mảng tổ tiên fa, chi phí cost và độ sâu dep.
  memset(fa, 0, sizeof(fa));
  memset(cost, 0, sizeof(cost));
  memset(dep, 0, sizeof(dep));
  // Đọc cây: có n đỉnh và m truy vấn, mỗi truy vấn tìm LCA của hai đỉnh.
  cin >> n >> m;
  // Khởi tạo cạnh cây và trọng số cạnh.
  for (int i = 1; i <= n; ++i) {
    v[i].clear();
    w[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    cin >> a >> b >> c;
    v[a].push_back(b);
    v[b].push_back(a);
    w[a].push_back(c);
    w[b].push_back(c);
  }
  // Dùng DFS để tính LCA.
  dfs(1, 0);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    cout << lca(a, b) << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) Solve();
  return 0;
}
