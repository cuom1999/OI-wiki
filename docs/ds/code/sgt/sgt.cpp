// --8<-- [start:full-text]
#include <cmath>
#include <iostream>

constexpr int N = 2e6;
constexpr double ALPHA = 0.7;
int id, rt, lc[N], rc[N], tot[N], tot_active;  // Thông tin cấu trúc cây.
int tmp[N], n_tmp;                             // Không gian để dựng lại cây.
int val[N], cnt[N], sz[N];                     // Thông tin nút.

// --8<-- [start:push-up]
// Cập nhật thông tin nút từ các con.
void push_up(int x) {
  tot[x] = 1 + tot[lc[x]] + tot[rc[x]];
  sz[x] = cnt[x] + sz[lc[x]] + sz[rc[x]];
}

// --8<-- [end:push-up]
// --8<-- [start:rebuild]
// Cây -> mảng.
void flatten(int x) {
  if (!x) return;
  flatten(lc[x]);
  if (cnt[x]) tmp[n_tmp++] = x;
  flatten(rc[x]);
}

// Mảng -> cây.
int build(int ll, int rr) {
  if (ll > rr) return 0;
  int mm = (ll + rr) / 2;
  int x = tmp[mm];
  lc[x] = build(ll, mm - 1);
  rc[x] = build(mm + 1, rr);
  push_up(x);
  return x;
}

// Dựng lại một cây con.
void rebuild(int& x) {
  n_tmp = 0;
  flatten(x);
  x = build(0, n_tmp - 1);
}

// --8<-- [end:rebuild]
// --8<-- [start:insert]
// Chèn v vào cây con của x.
bool insert(int& x, int v, int dep) {
  bool check = false;
  if (!x) {
    x = ++id;
    val[x] = v;
    check = dep > std::log(tot[rt] + 1) / std::log(1 / ALPHA);
  }
  if (val[x] == v) {
    if (!cnt[x]) ++tot_active;
    ++cnt[x];
  } else if (v < val[x]) {
    check = insert(lc[x], v, dep + 1);
  } else {
    check = insert(rc[x], v, dep + 1);
  }
  push_up(x);
  if (check && (tot[lc[x]] > ALPHA * tot[x] || tot[rc[x]] > ALPHA * tot[x])) {
    rebuild(x);
    return false;
  }
  return check;
}

// Chèn v vào cây.
void insert(int v) { insert(rt, v, 0); }

// --8<-- [end:insert]
// --8<-- [start:remove]
// Xóa v khỏi cây con của x.
bool remove(int x, int v) {
  if (!x) return false;
  bool succ = true;
  if (v < val[x]) {
    succ = remove(lc[x], v);
  } else if (v > val[x]) {
    succ = remove(rc[x], v);
  } else if (cnt[x]) {
    --cnt[x];
    if (!cnt[x]) --tot_active;
  } else {
    succ = false;
  }
  push_up(x);
  return succ;
}

// Xóa v khỏi cây.
bool remove(int v) {
  bool succ = remove(rt, v);
  if (!tot_active) {
    rt = 0;
  } else if (succ && tot_active < tot[rt] * ALPHA) {
    rebuild(rt);
  }
  return succ;
}

// --8<-- [end:remove]
// --8<-- [start:find-rank]
// Tìm rank của v, tức #{val < v} + 1.
int find_rank(int v) {
  int res = 0;
  int x = rt;
  while (x && val[x] != v) {
    if (v < val[x]) {
      x = lc[x];
    } else {
      res += sz[lc[x]] + cnt[x];
      x = rc[x];
    }
  }
  return res + sz[lc[x]] + 1;
}

// --8<-- [end:find-rank]
// --8<-- [start:find-kth]
// Tìm phần tử nhỏ thứ k.
int find_kth(int k) {
  if (k <= 0 || sz[rt] < k) return -1;
  int x = rt;
  for (;;) {
    if (k <= sz[lc[x]]) {
      x = lc[x];
    } else if (k <= sz[lc[x]] + cnt[x]) {
      return val[x];
    } else {
      k -= sz[lc[x]] + cnt[x];
      x = rc[x];
    }
  }
  return -1;
}

// --8<-- [end:find-kth]
// --8<-- [start:pred-succ]
// Tìm phần tử trước.
int find_prev(int x) { return find_kth(find_rank(x) - 1); }

// Tìm phần tử sau.
int find_next(int x) { return find_kth(find_rank(x + 1)); }

// --8<-- [end:pred-succ]
int main() {
  int n;
  std::cin >> n;
  for (; n; --n) {
    int op, x;
    std::cin >> op >> x;
    switch (op) {
      case 1:
        insert(x);
        break;
      case 2:
        remove(x);
        break;
      case 3:
        std::cout << find_rank(x) << '\n';
        break;
      case 4:
        std::cout << find_kth(x) << '\n';
        break;
      case 5:
        std::cout << find_prev(x) << '\n';
        break;
      case 6:
        std::cout << find_next(x) << '\n';
        break;
    }
  }
  return 0;
}

// --8<-- [end:full-text]
