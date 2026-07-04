#include <cstring>
#include <iostream>
using namespace std;
constexpr int MAXN = 105;

struct MaxClique {
  bool g[MAXN][MAXN];
  int n, dp[MAXN], st[MAXN][MAXN], ans;

  // dp[i] biểu diễn kích thước clique lớn nhất có thể tạo từ sau đỉnh i.
  // st[i][j] biểu diễn tập đỉnh cần cho tầng DFS thứ i, lưu các đỉnh có thể thuộc một maximum clique.

  void init(int n) {
    this->n = n;
    memset(g, false, sizeof(g));
  }

  void addedge(int u, int v, int w) { g[u][v] = w; }

  bool dfs(int sz, int num) {
    if (sz == 0) {
      if (num > ans) {
        ans = num;
        return true;
      }
      return false;
    }
    for (int i = 0; i < sz; i++) {  // Liệt kê một đỉnh i trong tập ở tầng num.
      if (sz - i + num <= ans) return false;  // Cắt tỉa 1.
      int u = st[num][i];
      if (dp[u] + num <= ans) return false;  // Cắt tỉa 2.
      int cnt = 0;
      for (
          int j = i + 1; j < sz;
          j++) {  // Ở tầng num, duyệt các đỉnh sau i và kề với i, rồi đưa vào tập tầng num+1.
        if (g[u][st[num][j]]) st[num + 1][cnt++] = st[num][j];
      }
      if (dfs(cnt, num + 1)) return true;
    }
    return false;
  }

  int solver() {
    ans = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = n; i >= 1; i--) {
      int cnt = 0;
      for (int j = i + 1; j <= n; j++) {  // Khởi tạo tập tầng 1.
        if (g[i][j]) st[1][cnt++] = j;
      }
      dfs(cnt, 1);
      dp[i] = ans;
    }
    return ans;
  }

} maxclique;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  while (cin >> n, n) {
    maxclique.init(n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int x;
        cin >> x;
        maxclique.addedge(i, j, x);
      }
    }
    cout << maxclique.solver() << '\n';
  }
  return 0;
}
