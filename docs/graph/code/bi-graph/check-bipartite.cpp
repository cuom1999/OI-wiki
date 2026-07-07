#include <iostream>
#include <vector>

// --8<-- [start:core]
int n;
std::vector<std::vector<int>> gr;
std::vector<int> colors, vis;

// Tìm kiếm theo chiều sâu để tô màu các đỉnh.
bool dfs(int cr) {
  vis[cr] = true;
  for (int nt : gr[cr]) {
    if (vis[nt]) {
      if (colors[cr] == colors[nt]) return false;
    } else {
      colors[nt] = colors[cr] ^ 1;
      if (!dfs(nt)) return false;
    }
  }
  return true;
}

// Kiểm tra đồ thị GR có phải đồ thị hai phía hay không.
// Nếu có, vector COLORS sẽ lưu một cách tô màu hợp lệ.
bool check_bipartite() {
  for (int i = 1; i <= n; ++i) {
    // Kiểm tra từng thành phần liên thông.
    if (!vis[i]) {
      colors[i] = 0;
      if (!dfs(i)) return false;
    }
  }
  return true;
}

// --8<-- [end:core]
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int m;
    std::cin >> n >> m;
    gr.assign(n + 1, {});
    colors.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; ++i) {
      int u, v;
      std::cin >> u >> v;
      gr[u].push_back(v);
      gr[v].push_back(u);
    }
    std::cout << (check_bipartite() ? "Yes" : "No") << std::endl;
  }
  return 0;
}
