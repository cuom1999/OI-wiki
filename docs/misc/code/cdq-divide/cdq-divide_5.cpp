#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using ll = long long;
int n;
int m;
int ask;

struct bcj {
  int fa[20010];
  int size[20010];

  struct opt {
    int u;
    int v;
  };

  stack<opt> st;

  void ih() {
    for (int i = 1; i <= n; i++) fa[i] = i, size[i] = 1;
  }

  int f(int x) { return (fa[x] == x) ? x : f(fa[x]); }

  void u(int x, int y) {  // Có hỗ trợ rollback
    int u = f(x);
    int v = f(y);
    if (u == v) return;
    if (size[u] < size[v]) swap(u, v);
    size[u] += size[v];
    fa[v] = u;
    opt o;
    o.u = u;
    o.v = v;
    st.push(o);
  }

  void undo() {
    opt o = st.top();
    st.pop();
    fa[o.v] = o.v;
    size[o.u] -= size[o.v];
  }

  void clear(int tim) {
    while (st.size() > tim) {
      undo();
    }
  }
} s, s1;

struct edge  // Cạnh tĩnh
{
  int u;
  int v;
  ll val;
  int mrk;

  friend bool operator<(edge a, edge b) { return a.val < b.val; }
} e[50010];

struct moved {
  int u;
  int v;
};  // Cạnh động

struct query {
  int num;
  ll val;
  ll ans;
} q[50010];

bool book[50010];  // Truy vấn
vector<edge> ve[30];
vector<moved> vq;
vector<edge> tr;
ll res[30];
int tim[30];

void pushdown(int dep)  // Co cạnh
{
  tr.clear();  // Cần sao chép một bản ở đây để vẫn có thể rollback
  for (int i = 0; i < ve[dep].size(); i++) {
    tr.push_back(ve[dep][i]);
  }
  sort(tr.begin(), tr.end());
  for (int i = 0; i < tr.size(); i++) {  // Cạnh vô dụng
    if (s1.f(tr[i].u) == s1.f(tr[i].v)) {
      tr[i].mrk = -1;
      continue;
    }
    s1.u(tr[i].u, tr[i].v);
  }
  s1.clear(0);
  res[dep + 1] = res[dep];
  for (int i = 0; i < vq.size(); i++) {
    s1.u(vq[i].u, vq[i].v);
  }
  vq.clear();
  for (int i = 0; i < tr.size(); i++) {  // Cạnh bắt buộc
    if (tr[i].mrk == -1 || s1.f(tr[i].u) == s1.f(tr[i].v)) continue;
    tr[i].mrk = 1;
    s1.u(tr[i].u, tr[i].v);
    s.u(tr[i].u, tr[i].v);
    res[dep + 1] += tr[i].val;
  }
  s1.clear(0);
  ve[dep + 1].clear();
  for (int i = 0; i < tr.size(); i++) {  // Co cạnh
    if (tr[i].mrk != 0) continue;
    edge p;
    p.u = s.f(tr[i].u);
    p.v = s.f(tr[i].v);
    if (p.u == p.v) continue;
    p.val = tr[i].val;
    p.mrk = 0;
    ve[dep + 1].push_back(p);
  }
  return;
}

void solve(int l, int r, int dep) {
  tim[dep] = s.st.size();
  int mid = (l + r) / 2;
  if (r - l == 1) {  // Điều kiện dừng
    edge p;
    p.u = s.f(e[q[r].num].u);
    p.v = s.f(e[q[r].num].v);
    p.val = q[r].val;
    e[q[r].num].val = q[r].val;
    p.mrk = 0;
    ve[dep].push_back(p);
    pushdown(dep);
    q[r].ans = res[dep + 1];
    s.clear(tim[dep - 1]);
    return;
  }
  for (int i = l + 1; i <= mid; i++) {
    book[q[i].num] = true;
  }
  for (int i = mid + 1; i <= r; i++) {  // Chuyển động sang tĩnh
    if (book[q[i].num]) continue;
    edge p;
    p.u = s.f(e[q[i].num].u);
    p.v = s.f(e[q[i].num].v);
    p.val = e[q[i].num].val;
    p.mrk = 0;
    ve[dep].push_back(p);
  }
  for (int i = l + 1; i <= mid; i++) {  // Chuyển truy vấn sang cạnh động
    moved p;
    p.u = s.f(e[q[i].num].u);
    p.v = s.f(e[q[i].num].v);
    vq.push_back(p);
  }
  pushdown(dep);  // Bên dưới là rollback
  for (int i = mid + 1; i <= r; i++) {
    if (book[q[i].num]) continue;
    ve[dep].pop_back();
  }
  for (int i = l + 1; i <= mid; i++) {
    book[q[i].num] = false;
  }
  solve(l, mid, dep + 1);
  for (int i = 0; i < ve[dep].size(); i++) {
    ve[dep][i].mrk = 0;
  }
  for (int i = mid + 1; i <= r; i++) {
    book[q[i].num] = true;
  }
  for (int i = l + 1; i <= mid; i++) {  // Chuyển động sang tĩnh
    if (book[q[i].num]) continue;
    edge p;
    p.u = s.f(e[q[i].num].u);
    p.v = s.f(e[q[i].num].v);
    p.val = e[q[i].num].val;
    p.mrk = 0;
    ve[dep].push_back(p);
  }
  for (int i = mid + 1; i <= r; i++) {  // Chuyển truy vấn sang động
    book[q[i].num] = false;
    moved p;
    p.u = s.f(e[q[i].num].u);
    p.v = s.f(e[q[i].num].v);
    vq.push_back(p);
  }
  pushdown(dep);
  solve(mid, r, dep + 1);
  s.clear(tim[dep - 1]);
  return;  // Quay thời gian về tầng trước
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> ask;
  s.ih();
  s1.ih();
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].val;
  }
  for (int i = 1; i <= ask; i++) {
    cin >> q[i].num >> q[i].val;
  }
  for (int i = 1; i <= ask; i++) {  // Các cạnh động ban đầu
    book[q[i].num] = true;
    moved p;
    p.u = e[q[i].num].u;
    p.v = e[q[i].num].v;
    vq.push_back(p);
  }
  for (int i = 1; i <= m; i++) {  // Các cạnh tĩnh ban đầu
    if (book[i]) continue;
    ve[1].push_back(e[i]);
  }
  for (int i = 1; i <= ask; i++) {
    book[q[i].num] = false;
  }
  solve(0, ask, 1);
  for (int i = 1; i <= ask; i++) {
    cout << q[i].ans << '\n';
  }
  return 0;
}
