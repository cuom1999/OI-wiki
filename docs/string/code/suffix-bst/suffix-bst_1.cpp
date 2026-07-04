#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

constexpr int N = 1e6 + 5;
constexpr double INF = 1e18;

int n, m, sa[N];
string t;

// SuffixBST(SGT Ver)

// Add in order; reverse the query string when querying.
// The suffix starting at i corresponds to node i.
constexpr double alpha = 0.75;
int root;
int sz[N], L[N], R[N];
double tag[N];
int buffer_size, buffer[N];

bool cmp(int x, int y) {
  if (t[x] != t[y]) return t[x] < t[y];
  return tag[x + 1] < tag[y + 1];
}

void init() { root = 0; }

void new_node(int& rt, int p, double lv, double rv) {
  rt = p;
  sz[rt] = 1;
  tag[rt] = (lv + rv) / 2;
  L[rt] = R[rt] = 0;
}

void push_up(int x) {
  if (!x) return;
  sz[x] = sz[L[x]] + 1 + sz[R[x]];
}

bool balance(int rt) { return alpha * sz[rt] > max(sz[L[rt]], sz[R[rt]]); }

void flatten(int rt) {
  if (!rt) return;
  flatten(L[rt]);
  buffer[++buffer_size] = rt;
  flatten(R[rt]);
}

void build(int& rt, int l, int r, double lv, double rv) {
  if (l > r) {
    rt = 0;
    return;
  }
  int mid = (l + r) >> 1;
  double mv = (lv + rv) / 2;

  rt = buffer[mid];
  tag[rt] = mv;
  build(L[rt], l, mid - 1, lv, mv);
  build(R[rt], mid + 1, r, mv, rv);
  push_up(rt);
}

void rebuild(int& rt, double lv, double rv) {
  buffer_size = 0;
  flatten(rt);
  build(rt, 1, buffer_size, lv, rv);
}

void insert(int& rt, int p, double lv, double rv) {
  if (!rt) {
    new_node(rt, p, lv, rv);
    return;
  }

  if (cmp(p, rt))
    insert(L[rt], p, lv, tag[rt]);
  else
    insert(R[rt], p, tag[rt], rv);

  push_up(rt);
  if (!balance(rt)) rebuild(rt, lv, rv);
}

void inorder(int rt) {
  if (!rt) return;
  inorder(L[rt]);
  sa[++m] = rt;
  inorder(R[rt]);
}

void solve(int Case) {
  cin >> t;
  n = t.size();
  t = " " + t;

  init();
  for (int i = n; i >= 1; --i) {
    insert(root, i, 0, INF);
  }

  // The inorder traversal of the suffix balanced tree is the suffix array.
  m = 0;
  inorder(root);

  for (int i = 1; i <= n; ++i) cout << sa[i] << ' ';
  cout << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve(1);
  return 0;
}
