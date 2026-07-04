#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#define SNI set<nod>::iterator
#define SDI set<data>::iterator
using namespace std;
constexpr int N = 1e5 + 10;
int n;
int m;
int pre[N];
int npre[N];
int a[N];
int tp[N];
int lf[N];
int rt[N];
int co[N];

struct modi {
  int t;
  int pos;
  int pre;
  int va;

  friend bool operator<(modi a, modi b) { return a.pre < b.pre; }
} md[10 * N];

int tp1;

struct qry {
  int t;
  int l;
  int r;
  int ans;

  friend bool operator<(qry a, qry b) { return a.l < b.l; }
} qr[N];

int tp2;
int cnt;

bool cmp(const qry& a, const qry& b) { return a.t < b.t; }

void modify(int pos, int co)  // Hàm sửa đổi
{
  if (npre[pos] == co) return;
  md[++tp1] = modi{++cnt, pos, npre[pos], -1};
  md[++tp1] = modi{++cnt, pos, npre[pos] = co, 1};
}

namespace prew {
int lst[2 * N];
map<int, int> mp;  // Rời rạc hóa trước

void prew() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]] = 1;
  for (int i = 1; i <= m; i++) {
    cin >> tp[i] >> lf[i] >> rt[i];
    if (tp[i] == 1) cin >> co[i], mp[co[i]] = 1;
  }
  map<int, int>::iterator it, it1;
  for (it = mp.begin(), it1 = it, ++it1; it1 != mp.end(); ++it, ++it1)
    it1->second += it->second;
  for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
  for (int i = 1; i <= n; i++)
    if (tp[i] == 1) co[i] = mp[co[i]];
  for (int i = 1; i <= n; i++) pre[i] = lst[a[i]], lst[a[i]] = i;
  for (int i = 1; i <= n; i++) npre[i] = pre[i];
}
}  // namespace prew

namespace colist {
struct data {
  int l;
  int r;
  int x;

  friend bool operator<(data a, data b) { return a.r < b.r; }
};

set<data> s;

struct nod {
  int l;
  int r;

  friend bool operator<(nod a, nod b) { return a.r < b.r; }
};

set<nod> c[2 * N];
set<int> bd;

void split(int mid) {  // Tách một nút thành hai nút
  SDI it = s.lower_bound(data{0, mid, 0});
  data p = *it;
  if (mid == p.r) return;
  s.erase(p);
  s.insert(data{p.l, mid, p.x});
  s.insert(data{mid + 1, p.r, p.x});
  c[p.x].erase(nod{p.l, p.r});
  c[p.x].insert(nod{p.l, mid});
  c[p.x].insert(nod{mid + 1, p.r});
}

void del(set<data>::iterator it) {  // Xóa một iterator
  bd.insert(it->l);
  SNI it1, it2;
  it1 = it2 = c[it->x].find(nod{it->l, it->r});
  ++it2;
  if (it2 != c[it->x].end()) bd.insert(it2->l);
  c[it->x].erase(it1);
  s.erase(it);
}

void ins(data p) {  // Chèn một nút
  s.insert(p);
  SNI it = c[p.x].insert(nod{p.l, p.r}).first;
  ++it;
  if (it != c[p.x].end()) {
    bd.insert(it->l);
  }
}

void stv(int l, int r, int x) {  // Gán giá trị cho đoạn
  if (l != 1) split(l - 1);
  split(r);
  int p = l;  // Sau hai lần split, xóa toàn bộ các đoạn
  while (p != r + 1) {
    SDI it = s.lower_bound(data{0, p, 0});
    p = it->r + 1;
    del(it);
  }
  ins(data{l, r, x});  // Quét set một lượt để xử lý mọi giá trị pre thay đổi
  for (set<int>::iterator it = bd.begin(); it != bd.end(); ++it) {
    SDI it1 = s.lower_bound(data{0, *it, 0});
    if (*it != it1->l)
      modify(*it, *it - 1);
    else {
      SNI it2 = c[it1->x].lower_bound(nod{0, *it});
      if (it2 != c[it1->x].begin())
        --it2, modify(*it, it2->r);
      else
        modify(*it, 0);
    }
  }
  bd.clear();
}

void ih() {
  int nc = a[1];
  int ccnt = 1;  // Chèn một đoạn liên tiếp vào set
  for (int i = 2; i <= n; i++)
    if (nc != a[i]) {
      s.insert(data{i - ccnt, i - 1, nc}), c[nc].insert(nod{i - ccnt, i - 1});
      nc = a[i];
      ccnt = 1;
    } else {
      ccnt++;
    }
  s.insert(data{n - ccnt + 1, n, a[n]}), c[a[n]].insert(nod{n - ccnt + 1, n});
}
}  // namespace colist

namespace CDQ {
struct treearray  // Cây Fenwick
{
  int ta[N];

  void c(int x, int t) {
    for (; x <= n; x += x & (-x)) ta[x] += t;
  }

  void d(int x) {
    for (; x <= n; x += x & (-x)) ta[x] = 0;
  }

  int q(int x) {
    int r = 0;
    for (; x; x -= x & (-x)) r += ta[x];
    return r;
  }

  void clear() {
    for (int i = 1; i <= n; i++) ta[i] = 0;
  }
} ta;

int srt[N];

bool cmp1(const int& a, const int& b) { return pre[a] < pre[b]; }

void solve(int l1, int r1, int l2, int r2, int L, int R) {  // CDQ
  if (l1 == r1 || l2 == r2) return;
  int mid = (L + R) / 2;
  int mid1 = l1;
  while (mid1 != r1 && md[mid1 + 1].t <= mid) mid1++;
  int mid2 = l2;
  while (mid2 != r2 && qr[mid2 + 1].t <= mid) mid2++;
  solve(l1, mid1, l2, mid2, L, mid);
  solve(mid1, r1, mid2, r2, mid, R);
  if (l1 != mid1 && mid2 != r2) {
    sort(md + l1 + 1, md + mid1 + 1);
    sort(qr + mid2 + 1, qr + r2 + 1);
    for (int i = mid2 + 1, j = l1 + 1; i <= r2; i++) {  // Xét đóng góp của nửa trái cho nửa phải
      while (j <= mid1 && md[j].pre < qr[i].l) ta.c(md[j].pos, md[j].va), j++;
      qr[i].ans += ta.q(qr[i].r) - ta.q(qr[i].l - 1);
    }
    for (int i = l1 + 1; i <= mid1; i++) ta.d(md[i].pos);
  }
}

void mainsolve() {
  colist::ih();
  for (int i = 1; i <= m; i++)
    if (tp[i] == 1)
      colist::stv(lf[i], rt[i], co[i]);
    else
      qr[++tp2] = qry{++cnt, lf[i], rt[i], 0};
  sort(qr + 1, qr + tp2 + 1);
  for (int i = 1; i <= n; i++) srt[i] = i;
  sort(srt + 1, srt + n + 1, cmp1);
  for (int i = 1, j = 1; i <= tp2; i++) {  // Khởi tạo giá trị cho từng truy vấn
    while (j <= n && pre[srt[j]] < qr[i].l) ta.c(srt[j], 1), j++;
    qr[i].ans += ta.q(qr[i].r) - ta.q(qr[i].l - 1);
  }
  ta.clear();
  sort(qr + 1, qr + tp2 + 1, cmp);
  solve(0, tp1, 0, tp2, 0, cnt);
  sort(qr + 1, qr + tp2 + 1, cmp);
  for (int i = 1; i <= tp2; i++) cout << qr[i].ans << '\n';
}
}  // namespace CDQ

int main() {
  prew::prew();
  CDQ::mainsolve();
  return 0;
}
