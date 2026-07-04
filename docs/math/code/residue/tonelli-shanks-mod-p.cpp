#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <tuple>
#include <unordered_map>
#include <vector>

std::mt19937 rng(std::random_device{}());

// Lũy thừa nhị phân.
int pow(int a, int b, int m = 0) {
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = m ? (long long)res * a % m : res * a;
    a = m ? (long long)a * a % m : a * a;
  }
  return res;
}

// Tìm một bất thặng dư bậc P modulo M.
int non_residue(int p, int m, int phi) {
  std::uniform_int_distribution<int> dis(1, m - 1);
  while (true) {
    int c = dis(rng);
    if (pow(c, phi / p, m) != 1) return c;
  }
  return -1;
}

// Thuật toán Euclid.
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

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

// Trả về nghịch đảo của A modulo M.
// Giả sử gcd(A, M) = 1, nên nghịch đảo tồn tại.
int inv(int a, int m) {
  int x, y;
  ex_gcd(a, m, x, y);
  return (x % m + m) % m;
}

// Thủ tục con: tìm một căn bậc P^E của A modulo M.
int peth_root_mod_m(int p, int e, int a, int m, int phi) {
  int s = 0, r = phi, pe = pow(p, e);
  for (; r % p == 0; r /= p, ++s);
  int q = pe - inv(r, pe);
  int ans = pow(a, ((long long)q * r + 1) / pe % phi, m);
  int eta = non_residue(p, m, phi);
  std::unordered_map<int, int> mp;
  int zeta = pow(eta, r, m);
  int xi = pow(eta, phi / p, m);
  // Tiền xử lý các lũy thừa cho BSGS.
  int B = std::sqrt((s - e) * p + 0.25l) + 1;
  int pB = p / B + 1;
  int po0 = pow(xi, pB, m);
  for (int j = 1, po1 = 1; j <= B; ++j) {
    po1 = (long long)po1 * po0 % m;
    mp[po1] = j;
  }
  // Tính các chữ số p-adic của h.
  for (int j = 0; j < s - e; ++j) {
    int err = (long long)pow(ans, pe, m) * inv(a, m) % m;
    int xi_hj = pow(err, pow(p, s - e - j - 1), m);
    long long hj = 0;
    // Truy vấn BSGS.
    for (int i = 1; i <= pB; ++i) {
      xi_hj = (long long)xi_hj * xi % m;
      if (mp.count(xi_hj)) {
        hj = mp[xi_hj] * pB - i;
        break;
      }
    }
    ans = (long long)ans * pow(zeta, phi - hj * pow(p, j) % phi, m) % m;
  }
  return ans;
}

// Tìm một căn bậc K của A modulo số nguyên tố P.
int kth_root_mod_p(int k, int a, int p) {
  a %= p;
  if (k == 0) return a == 1 ? 0 : -1;
  if (a == 0) return 0;
  int d = gcd(k, p - 1);
  if (pow(a, (p - 1) / d, p) != 1) return -1;
  a = pow(a, inv(k / d, (p - 1) / d), p);
  for (int dp = 2; dp * dp <= d && dp * dp * dp * dp < p; ++dp) {
    if (d % dp == 0) {
      int de = 0;
      for (; d % dp == 0; d /= dp, ++de);
      a = peth_root_mod_m(dp, de, a, p, p - 1);
    }
  }
  if (d != 1) {
    int dp = gcd(d, (p - 1) / d), de = 0;
    if (dp != 1) {
      for (; d % dp == 0; d /= dp, ++de);
      a = peth_root_mod_m(dp, de, a, p, p - 1);
    }
    if (d != 1) a = peth_root_mod_m(d, 1, a, p, p - 1);
  }
  return a;
}

void solve() {
  int k, y, p;
  std::cin >> k >> y >> p;
  std::cout << kth_root_mod_p(k, y, p) << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for (; t; --t) {
    solve();
  }
}
