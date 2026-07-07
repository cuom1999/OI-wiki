// Bài nộp: https://judge.yosupo.jp/submission/311623
#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

std::mt19937_64 rng(static_cast<std::mt19937_64::result_type>(time(nullptr)));

constexpr long long inf = 0x3f3f3f3f3f3f3f3f;

// Heap ngẫu nhiên hóa bền vững.
struct PersistentRandomizedHeap {
  static constexpr int N = 1e7;
  int id;
  std::vector<int> rt, lc, rc, to;
  std::vector<long long> va;

  int new_node(long long cost, int _to) {
    ++id;
    va[id] = cost;
    to[id] = _to;
    return id;
  }

  int copy_node(int x) {
    ++id;
    lc[id] = lc[x];
    rc[id] = rc[x];
    va[id] = va[x];
    to[id] = to[x];
    return id;
  }

  int meld(int x, int y, std::mt19937_64::result_type rand) {
    if (!x || !y) return x | y;
    if (va[x] > va[y]) std::swap(x, y);
    x = copy_node(x);
    if (rand & 1) std::swap(lc[x], rc[x]);
    rc[x] = meld(rc[x], y, rand >> 1);
    return x;
  }

  PersistentRandomizedHeap() : id(0), rt(N), lc(N), rc(N), to(N), va(N) {}

  void insert(int i, long long cost, int _to) {
    rt[i] = meld(rt[i], new_node(cost, _to), rng());
  }

  void merge(int i, int j) { rt[i] = meld(rt[i], rt[j], rng()); }

} heaps;

struct Edge {
  int u, v, c;

  Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};

int n, m, s, t, k;
std::vector<std::vector<int>> gr, ig;
std::vector<Edge> edges;
std::priority_queue<std::pair<long long, int>,
                    std::vector<std::pair<long long, int>>, std::greater<>>
    pq;

std::vector<long long> dist_t;
std::vector<int> out;

// Tính khoảng cách tới đỉnh đích t. (Dijkstra)
// Ghi lại các cạnh đi ra tối ưu tạo thành cây đường đi ngắn nhất T.
void calc_distances_to_t() {
  dist_t.assign(n, inf);
  dist_t[t] = 0;
  out.assign(n, -1);
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
        out[nxt] = e;
        pq.emplace(di_nxt, nxt);
      }
    }
  }
}

// Dựng các cạnh rẽ nhánh và lan truyền chúng trên cây T.
void build_sidetracks() {
  // Đưa mọi cạnh rẽ nhánh hợp lệ vào các heap.
  for (int i = 0; i < m; ++i) {
    auto edge = edges[i];
    if (out[edge.u] != i && dist_t[edge.u] < inf && dist_t[edge.v] < inf) {
      heaps.insert(edge.u, edge.c + dist_t[edge.v] - dist_t[edge.u], edge.v);
    }
  }
  // Lan truyền các cạnh rẽ nhánh xuống cây đường đi ngắn nhất.
  std::queue<int> q;
  q.push(t);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto e : ig[cur]) {
      auto nxt = edges[e].u;
      if (out[nxt] == e) {
        heaps.merge(nxt, cur);
        q.push(nxt);
      }
    }
  }
}

std::vector<long long> ans;

// Đưa heap không rỗng vào hàng đợi ưu tiên.
// Tổng chi phí bằng giá trị ở đỉnh heap sau khi cộng chi phí tích lũy.
void insert(int x, long long cost) {
  if (x) pq.emplace(cost + heaps.va[x], x);
}

// Tìm k đường đi ngắn nhất trong đồ thị cạnh rẽ nhánh. (Dijkstra)
// Chúng tương ứng với k walk ngắn nhất trong đồ thị ban đầu.
void find_k_shortest_walks() {
  int cnt = 0;
  ans.assign(k, -1);
  if (dist_t[s] >= inf) return;
  ans[cnt++] = dist_t[s];
  insert(heaps.rt[s], dist_t[s]);
  while (!pq.empty() && cnt < k) {
    auto cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    ans[cnt++] = cost;
    insert(heaps.lc[cur], cost - heaps.va[cur]);
    insert(heaps.rc[cur], cost - heaps.va[cur]);
    insert(heaps.rt[heaps.to[cur]], cost);
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
  build_sidetracks();
  find_k_shortest_walks();
  // Xuất dữ liệu.
  for (auto x : ans) std::cout << x << '\n';
  return 0;
}
