// Bài nộp: https://judge.yosupo.jp/submission/311622
#include <iostream>
#include <queue>
#include <vector>

constexpr long long inf = 0x3f3f3f3f3f3f3f3f;

struct Edge {
  int u, v, c;

  Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};

int n, m, s, t, k;
std::vector<std::vector<int>> gr, ig;  // Đồ thị và đồ thị ngược.
std::vector<Edge> edges;               // Các cạnh.
std::priority_queue<std::pair<long long, int>,
                    std::vector<std::pair<long long, int>>, std::greater<>>
    pq;

std::vector<long long> dist_t;

// Tính khoảng cách tới đỉnh đích t. (Dijkstra)
void calc_distances_to_t() {
  dist_t.assign(n, inf);
  dist_t[t] = 0;
  pq.emplace(dist_t[t], t);
  while (!pq.empty()) {
    long long di = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if (di > dist_t[cur]) continue;
    for (auto e : ig[cur]) {
      int nxt = edges[e].u;
      auto di_nxt = di + edges[e].c;
      if (di_nxt < dist_t[nxt]) {
        dist_t[nxt] = di_nxt;
        pq.emplace(di_nxt, nxt);
      }
    }
  }
}

std::vector<long long> ans;

// Tìm k hành trình ngắn nhất. (tìm kiếm A*)
// Độ phức tạp: O(k * n * log(k * n)).
void find_k_shortest_walks() {
  ans.assign(k, -1);
  std::vector<int> cnt(n);
  pq.emplace(dist_t[s], s);
  while (!pq.empty()) {
    long long cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    // Bỏ qua các đỉnh không thể tới.
    if (cost >= inf) continue;
    if (cur == t) ans[cnt[t]] = cost;
    ++cnt[cur];
    // Dừng khi đỉnh đích đã được thăm k lần.
    if (cnt[t] >= k) break;
    // Mở rộng cùng một đỉnh tối đa k lần.
    if (cnt[cur] > k) continue;
    for (auto e : gr[cur]) {
      int nxt = edges[e].v;
      auto cost_nxt = cost - dist_t[cur] + edges[e].c + dist_t[nxt];
      pq.emplace(cost_nxt, nxt);
    }
  }
}

int main() {
  // Nhập dữ liệu.
  std::cin >> n >> m >> s >> t >> k;
  gr.resize(n);
  ig.resize(n);
  edges.reserve(m);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    edges.emplace_back(u, v, c);
    gr[u].push_back(i);
    ig[v].push_back(i);
  }
  // Tính toán.
  calc_distances_to_t();
  find_k_shortest_walks();
  // Xuất kết quả.
  for (auto x : ans) std::cout << x << '\n';
  return 0;
}
