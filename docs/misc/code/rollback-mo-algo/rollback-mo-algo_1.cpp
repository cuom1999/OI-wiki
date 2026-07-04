#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 5;
int n, q;
int x[N], t[N], m;

struct Query {
  int l, r, id;
} Q[N];

int pos[N], L[N], R[N], sz, tot;
int cnt[N], __cnt[N];
ll ans[N];

bool cmp(const Query& A, const Query& B) {
  if (pos[A.l] == pos[B.l]) return A.r < B.r;
  return pos[A.l] < pos[B.l];
}

void build() {
  sz = sqrt(n);
  tot = n / sz;
  for (int i = 1; i <= tot; i++) {
    L[i] = (i - 1) * sz + 1;
    R[i] = i * sz;
  }
  if (R[tot] < n) {
    ++tot;
    L[tot] = R[tot - 1] + 1;
    R[tot] = n;
  }
}

void Add(int v, ll& Ans) {
  ++cnt[v];
  Ans = max(Ans, 1LL * cnt[v] * t[v]);
}

void Del(int v) { --cnt[v]; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> x[i], t[++m] = x[i];
  for (int i = 1; i <= q; i++) cin >> Q[i].l >> Q[i].r, Q[i].id = i;

  build();

  // Sắp xếp các truy vấn
  for (int i = 1; i <= tot; i++)
    for (int j = L[i]; j <= R[i]; j++) pos[j] = i;
  sort(Q + 1, Q + 1 + q, cmp);

  // Rời rạc hóa
  sort(t + 1, t + 1 + m);
  m = unique(t + 1, t + 1 + m) - (t + 1);
  for (int i = 1; i <= n; i++) x[i] = lower_bound(t + 1, t + 1 + m, x[i]) - t;

  int l = 1, r = 0, last_block = 0, __l;
  ll Ans = 0, tmp;
  for (int i = 1; i <= q; i++) {
    // Nếu hai đầu mút của truy vấn nằm trong cùng một khối, quét trực tiếp
    if (pos[Q[i].l] == pos[Q[i].r]) {
      for (int j = Q[i].l; j <= Q[i].r; j++) ++__cnt[x[j]];
      for (int j = Q[i].l; j <= Q[i].r; j++)
        ans[Q[i].id] = max(ans[Q[i].id], 1LL * t[x[j]] * __cnt[x[j]]);
      for (int j = Q[i].l; j <= Q[i].r; j++) --__cnt[x[j]];
      continue;
    }

    // Khi sang khối mới, khởi tạo lại đoạn của Mo
    if (pos[Q[i].l] != last_block) {
      while (r > R[pos[Q[i].l]]) Del(x[r]), --r;
      while (l < R[pos[Q[i].l]] + 1) Del(x[l]), ++l;
      Ans = 0;
      last_block = pos[Q[i].l];
    }

    // Mở rộng đầu mút phải
    while (r < Q[i].r) ++r, Add(x[r], Ans);
    __l = l;
    tmp = Ans;

    // Mở rộng đầu mút trái
    while (__l > Q[i].l) --__l, Add(x[__l], tmp);
    ans[Q[i].id] = tmp;

    // Rollback
    while (__l < l) Del(x[__l]), ++__l;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
  return 0;
}
