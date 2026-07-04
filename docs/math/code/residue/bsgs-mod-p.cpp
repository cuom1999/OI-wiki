// Bài nộp (TLE): https://judge.yosupo.jp/submission/320582
#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

struct PrimePower {
  int p, e, pe;

  PrimePower(int p, int e, int pe) : p(p), e(e), pe(pe) {}
};

// Phân tích thừa số.
auto factorize(int n) {
  std::vector<PrimePower> ans;
  for (int x = 2; x * x <= n; ++x) {
    int e = 0, pe = 1;
    for (; n % x == 0; n /= x, ++e, pe *= x);
    if (e) ans.emplace_back(x, e, pe);
  }
  if (n > 1) ans.emplace_back(n, 1, n);
  return ans;
}

// Lũy thừa nhị phân.
int pow(int a, int b, int m = 0) {
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = m ? (long long)res * a % m : res * a;
    a = m ? (long long)a * a % m : a * a;
  }
  return res;
}

// Tìm căn nguyên thủy modulo số nguyên tố.
int primitive_root(int p) {
  std::vector<int> exp;
  for (auto factor : factorize(p - 1)) {
    exp.push_back((p - 1) / factor.p);
  }
  int ans = 0;
  bool succ = false;
  while (!succ) {
    ++ans;
    succ = true;
    for (int b : exp) {
      if (pow(ans, b, p) == 1) {
        succ = false;
        break;
      }
    }
  }
  return ans;
}

// Logarit rời rạc. (Thuật toán BSGS)
int log(int g, int a, int m) {
  int b = std::sqrt(m + 0.25l) + 1;
  std::unordered_map<int, int> mp;
  int po0 = a % m, po1 = 1;
  for (int i = 0; i < b; ++i) {
    mp[po0] = i;
    po0 = (long long)po0 * g % m;
  }
  po0 = pow(g, b, m);
  for (int j = 1; j <= b; ++j) {
    po1 = (long long)po1 * po0 % m;
    if (mp.count(po1)) return j * b - mp[po1];
  }
  return -1;
}

// Thuật toán Euclid mở rộng.
int ex_gcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  } else {
    int d = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
  }
}

// Giải phương trình đồng dư tuyến tính: Ax = B mod N.
// Trả về nghiệm không âm nhỏ nhất và công sai.
std::pair<int, int> solve_linear(int a, int b, int n) {
  int x, y;
  int d = ex_gcd(a, n, x, y);
  if (b % d) return {-1, -1};
  n /= d;
  x = ((long long)x * (b / d) % n + n) % n;
  return {x, n};
}

// Thủ tục con: tìm một căn bậc K khi đã biết căn nguyên thủy G.
int calc(int g, int k, int a, int p) {
  int ind = log(g, a, p);
  if (ind == -1) return -1;
  int y0, d;
  std::tie(y0, d) = solve_linear(k, ind, p - 1);
  if (y0 == -1) return -1;
  return pow(g, y0, p);
}

// Tìm một căn bậc K của A modulo số nguyên tố P.
int kth_roots_mod_p(int k, int a, int p) {
  a %= p;
  if (k == 0) return a == 1 ? 0 : -1;
  if (a == 0) return 0;
  return calc(primitive_root(p), k, a, p);
}

void solve() {
  int k, y, p;
  std::cin >> k >> y >> p;
  std::cout << kth_roots_mod_p(k, y, p) << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for (; t; --t) {
    solve();
  }
}
