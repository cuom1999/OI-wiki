// Verified by https://codeforces.com/gym/101649/problem/G.
// Codes associating I/O streams to files are omitted.
#include <iostream>
#include <vector>
using namespace std;

// --8<-- [start:core]
const int MAXN = 50005;

int n;
// Đoạn code này mặc định đánh số đỉnh từ 1, tức i ∈ [1,n].
int siz[MAXN],  // "Kích thước" của đỉnh này: số đỉnh trong mọi cây con + chính nó.
    weight[MAXN];  // "Trọng lượng" của đỉnh: kích thước lớn nhất trong các cây con.
vector<int> centroids;  // Ghi lại trọng tâm của cây, lưu bằng số hiệu đỉnh.
vector<int> g[MAXN];

void dfs(int cur, int fa) {  // cur biểu diễn đỉnh hiện tại (current).
  siz[cur] = 1;
  weight[cur] = 0;
  for (int v : g[cur]) {
    if (v != fa) {  // v là đỉnh mà cạnh có hướng này trỏ tới.
      dfs(v, cur);
      siz[cur] += siz[v];
      weight[cur] = max(weight[cur], siz[v]);
    }
  }
  weight[cur] = max(weight[cur], n - siz[cur]);
  if (weight[cur] <= n / 2) {  // Thống kê theo định nghĩa trọng tâm của cây.
    centroids.push_back(cur);
  }
}

void get_centroids() { dfs(1, 0); }

// --8<-- [end:core]
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  get_centroids();
  if (centroids.size() == 1)
    cout << centroids.front() << '\n';
  else
    cout << min(centroids.front(), centroids.back()) << " "
         << max(centroids.front(), centroids.back()) << '\n';
  return 0;
}
