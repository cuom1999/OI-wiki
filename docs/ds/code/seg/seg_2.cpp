#include <iostream>
using ll = long long;

int n, m;
ll mod;
ll a[100005], sum[400005], mul[400005], laz[400005];

void up(int i) { sum[i] = (sum[(i << 1)] + sum[(i << 1) | 1]) % mod; }

void pd(int i, int s, int t) {
  int l = (i << 1), r = (i << 1) | 1, mid = (s + t) >> 1;
  if (mul[i] != 1) {  // Truyền nhãn lười, có hai nhãn lười.
    mul[l] *= mul[i];
    mul[l] %= mod;
    mul[r] *= mul[i];
    mul[r] %= mod;
    laz[l] *= mul[i];
    laz[l] %= mod;
    laz[r] *= mul[i];
    laz[r] %= mod;
    sum[l] *= mul[i];
    sum[l] %= mod;
    sum[r] *= mul[i];
    sum[r] %= mod;
    mul[i] = 1;
  }
  if (laz[i]) {  // Truyền nhãn lười.
    sum[l] += laz[i] * (mid - s + 1);
    sum[l] %= mod;
    sum[r] += laz[i] * (t - mid);
    sum[r] %= mod;
    laz[l] += laz[i];
    laz[l] %= mod;
    laz[r] += laz[i];
    laz[r] %= mod;
    laz[i] = 0;
  }
  return;
}

void build(int s, int t, int i) {
  mul[i] = 1;
  if (s == t) {
    sum[i] = a[s];
    return;
  }
  int mid = s + ((t - s) >> 1);
  build(s, mid, i << 1);  // Xây cây.
  build(mid + 1, t, (i << 1) | 1);
  up(i);
}

void chen(int l, int r, int s, int t, int i, ll z) {
  int mid = s + ((t - s) >> 1);
  if (l <= s && t <= r) {
    mul[i] *= z;
    mul[i] %= mod;  // Lấy modulo.
    laz[i] *= z;
    laz[i] %= mod;  // Lấy modulo.
    sum[i] *= z;
    sum[i] %= mod;  // Lấy modulo.
    return;
  }
  pd(i, s, t);
  if (mid >= l) chen(l, r, s, mid, (i << 1), z);
  if (mid + 1 <= r) chen(l, r, mid + 1, t, (i << 1) | 1, z);
  up(i);
}

void add(int l, int r, int s, int t, int i, ll z) {
  int mid = s + ((t - s) >> 1);
  if (l <= s && t <= r) {
    sum[i] += z * (t - s + 1);
    sum[i] %= mod;  // Lấy modulo.
    laz[i] += z;
    laz[i] %= mod;  // Lấy modulo.
    return;
  }
  pd(i, s, t);
  if (mid >= l) add(l, r, s, mid, (i << 1), z);
  if (mid + 1 <= r) add(l, r, mid + 1, t, (i << 1) | 1, z);
  up(i);
}

ll getans(int l, int r, int s, int t,
          int i) {  // Lấy đáp án; có thể xem phần nhãn lười phía trên để dễ hiểu hơn.
  int mid = s + ((t - s) >> 1);
  ll tot = 0;
  if (l <= s && t <= r) return sum[i];
  pd(i, s, t);
  if (mid >= l) tot += getans(l, r, s, mid, (i << 1));
  tot %= mod;
  if (mid + 1 <= r) tot += getans(l, r, mid + 1, t, (i << 1) | 1);
  return tot % mod;
}

using std::cin;
using std::cout;

int main() {  // Đọc dữ liệu.
  cin.tie(nullptr)->sync_with_stdio(false);
  int i, j, x, y, bh;
  ll z;
  cin >> n >> m >> mod;
  for (i = 1; i <= n; i++) cin >> a[i];
  build(1, n, 1);  // Xây cây.
  for (i = 1; i <= m; i++) {
    cin >> bh;
    if (bh == 1) {
      cin >> x >> y >> z;
      chen(x, y, 1, n, 1, z);
    } else if (bh == 2) {
      cin >> x >> y >> z;
      add(x, y, 1, n, 1, z);
    } else if (bh == 3) {
      cin >> x >> y;
      cout << getans(x, y, 1, n, 1) << '\n';
    }
  }
  return 0;
}
