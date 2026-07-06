#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <queue>
#include <random>
#include <vector>
using namespace std;

// graph
template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n) { g.resize(n); }

  virtual int add(int from, int to, T cost) = 0;
};

// undirectedgraph
template <typename T>
class undirectedgraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undirectedgraph(int _n) : graph<T>(_n) {}

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int)edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

// blossom / find_max_unweighted_matching
template <typename T>
vector<int> find_max_unweighted_matching(const undirectedgraph<T> &g) {
  std::mt19937 rng(114514);  // Seed ngẫu nhiên tại đây không quan trọng.
  // Cũng có thể dùng chrono::steady_clock::now().time_since_epoch().count()
  // để lấy thời gian hiện tại.
  vector<int> match(g.n, -1);   // Ghép cặp.
  vector<int> aux(g.n, -1);     // Dấu timestamp.
  vector<int> label(g.n);       // "o" or "i"
  vector<int> orig(g.n);        // Gốc blossom.
  vector<int> parent(g.n, -1);  // Đỉnh cha.
  queue<int> q;
  int aux_time = -1;

  auto lca = [&](int v, int u) {
    aux_time++;
    while (true) {
      if (v != -1) {
        if (aux[v] == aux_time) {  // Tìm được đỉnh đã thăm, tức LCA.
          return v;
        }
        aux[v] = aux_time;
        if (match[v] == -1) {
          v = -1;
        } else {
          v = orig[parent[match[v]]];  // Tiếp tục tìm từ cha của đỉnh được ghép.
        }
      }
      swap(v, u);
    }
  };  // lca

  auto blossom = [&](int v, int u, int a) {
    while (orig[v] != a) {
      parent[v] = u;
      u = match[v];
      if (label[u] == 1) {  // Đặt điểm ban đầu là "o" để tìm đường tăng.
        label[u] = 0;
        q.push(u);
      }
      orig[v] = orig[u] = a;  // Co blossom.
      v = parent[u];
    }
  };  // blossom

  auto augment = [&](int v) {
    while (v != -1) {
      int pv = parent[v];
      int next_v = match[pv];
      match[v] = pv;
      match[pv] = v;
      v = next_v;
    }
  };  // augment

  auto bfs = [&](int root) {
    fill(label.begin(), label.end(), -1);
    iota(orig.begin(), orig.end(), 0);
    while (!q.empty()) {
      q.pop();
    }
    q.push(root);
    // Đặt điểm ban đầu là "o"; tại đây dùng "0" thay "o", "1" thay "i".
    label[root] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : g.g[v]) {
        auto &e = g.edges[id];
        int u = e.from ^ e.to ^ v;
        if (label[u] == -1) {  // Tìm được đỉnh chưa thăm.
          label[u] = 1;        // Đánh dấu "i".
          parent[u] = v;
          if (match[u] == -1) {  // Tìm được đỉnh chưa ghép.
            augment(u);          // Tìm đường tăng.
            return true;
          }
          // Tìm được đỉnh đã ghép; đưa đỉnh ghép với nó vào queue để mở rộng cây xen kẽ.
          label[match[u]] = 0;
          q.push(match[u]);
          continue;
        } else if (label[u] == 0 && orig[v] != orig[u]) {
          // Tìm được đỉnh đã thăm và cùng nhãn "o", tức đã tìm được blossom.
          int a = lca(orig[v], orig[u]);
          // Tìm LCA rồi co blossom.
          blossom(u, v, a);
          blossom(v, u, a);
        }
      }
    }
    return false;
  };  // bfs

  auto greedy = [&]() {
    vector<int> order(g.n);
    // Xáo trộn ngẫu nhiên order.
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);

    // Ghép các đỉnh có thể ghép.
    for (int i : order) {
      if (match[i] == -1) {
        for (auto id : g.g[i]) {
          auto &e = g.edges[id];
          int to = e.from ^ e.to ^ i;
          if (match[to] == -1) {
            match[i] = to;
            match[to] = i;
            break;
          }
        }
      }
    }
  };  // greedy

  // Ban đầu ghép ngẫu nhiên trước.
  greedy();
  // Tìm đường tăng cho các đỉnh chưa ghép.
  for (int i = 0; i < g.n; i++) {
    if (match[i] == -1) {
      bfs(i);
    }
  }
  return match;
}

int main() {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  undirectedgraph<int> g(n);

  while (m--) {
    int u, v;
    cin >> u >> v;
    g.add(u - 1, v - 1);  // 0-based
  }

  auto match = find_max_unweighted_matching(g);

  cout << count_if(match.begin(), match.end(), [](int x) { return x != -1; }) /
              2
       << endl;
  for (int i = 0; i < n; i++) cout << match[i] + 1 << " \n"[i == n - 1];

  return 0;
}
