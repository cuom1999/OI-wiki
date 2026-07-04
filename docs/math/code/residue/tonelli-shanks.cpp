#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <tuple>
#include <unordered_map>
#include <vector>

std::mt19937 rng(std::random_device{}());

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

// Tìm căn nguyên thủy modulo lũy thừa của số nguyên tố lẻ.
int primitive_root(PrimePower pp) {
  std::vector<int> exp;
  int phi = pp.pe / pp.p * (pp.p - 1);
  for (auto factor : factorize(pp.p - 1)) {
    exp.push_back(phi / factor.p);
  }
  if (pp.e != 1) exp.push_back(phi / pp.p);
  int ans = 0;
  bool succ = false;
  while (!succ) {
    ++ans;
    succ = true;
    for (int b : exp) {
      if (pow(ans, b, pp.pe) == 1) {
        succ = false;
        break;
      }
    }
  }
  return ans;
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

// Tìm một bất thặng dư bậc P modulo M.
int non_residue(int p, int m, int phi) {
  std::uniform_int_distribution<int> dis(1, m - 1);
  while (true) {
    int c = dis(rng);
    if (gcd(c, m) == 1 && pow(c, phi / p, m) != 1) return c;
  }
  return -1;
}

// Thủ tục con: tìm một căn bậc P^E của A modulo M.
int peth_root_mod_m(int p, int e, int a, int m, int phi) {
  if (m == 2) return 1;
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
  int pB = pe / B + 1;
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

// Tìm một căn bậc K của A modulo lũy thừa nguyên tố P^E.
int kth_root_mod_pe(int k, int a, int pe, int phi) {
  a %= pe;
  if (k == 0) return a == 1 ? 0 : -1;
  if (a == 0) return 0;
  int d = gcd(k, phi);
  if (pow(a, phi / d, pe) != 1) return -1;
  a = pow(a, inv(k / d, phi / d), pe);
  for (int dp = 2; dp * dp <= d && dp * dp * dp * dp < pe; ++dp) {
    if (d % dp == 0) {
      int de = 0;
      for (; d % dp == 0; d /= dp, ++de);
      a = peth_root_mod_m(dp, de, a, pe, phi);
    }
  }
  if (d != 1) {
    int dp = gcd(d, phi / d), de = 0;
    if (dp != 1) {
      for (; d % dp == 0; d /= dp, ++de);
      a = peth_root_mod_m(dp, de, a, pe, phi);
    }
    if (d != 1) a = peth_root_mod_m(d, 1, a, pe, phi);
  }
  return a;
}

// Thủ tục con: tìm mọi căn bậc K khi đã biết căn nguyên thủy G.
std::vector<int> calc(int g, int k, int a, int p, int pe) {
  int mm = p == 2 ? pe / 4 : pe / p * (p - 1);
  int ans = kth_root_mod_pe(k, a, pe, mm);
  if (ans == -1) return {};
  int d = mm / gcd(k, mm);
  int po = pow(g, d, pe);
  std::vector<int> res(mm / d);
  for (auto& x : res) {
    x = ans;
    ans = (long long)ans * po % pe;
  }
  return res;
}

// Tìm mọi căn bậc K của A modulo lũy thừa nguyên tố P^E.
std::vector<int> kth_roots_mod_pe(int k, int a, PrimePower pp) {
  int p = pp.p, e = pp.e, pe = pp.pe;
  a %= pe;
  if (a == 0) {
    int d = pow(p, (e - 1) / k + 1);
    std::vector<int> res(pe / d);
    for (int i = 0; i < pe / d; ++i) {
      res[i] = i * d;
    }
    return res;
  }
  int s = 0;
  for (; a % p == 0; a /= p, ++s);
  if (s % k) return {};
  int psk = pow(p, s / k), pss = pow(p, s - s / k), pes = pow(p, e - s);
  std::vector<int> res;
  if (p != 2) {
    int g = primitive_root(PrimePower(p, e - s, pes));
    res = calc(g, k, a, p, pes);
  } else if (pes == 2) {
    res.push_back(a);
  } else if (k & 1) {
    int z = a % 4 == 3;
    a = z ? pes - a : a;
    res = calc(5, k, a, p, pes);
    if (z) {
      for (auto& x : res) x = pes - x;
    }
  } else {
    if (a % 4 == 3) return {};
    res = calc(5, k, a, p, pes);
    int m = res.size();
    res.reserve(m * 2);
    for (int i = 0; i < m; ++i) {
      res.push_back(pes - res[i]);
    }
  }
  int m = res.size();
  res.reserve(m * pss);
  for (int j = 1; j < pss; ++j) {
    for (int i = 0; i < m; ++i) {
      res.push_back(res.end()[-m] + pes);
    }
  }
  for (auto& x : res) x *= psk;
  return res;
}

// Tìm mọi căn bậc K của A modulo số nguyên dương M.
std::vector<int> kth_roots_mod_m(int k, int a, int m) {
  auto factors = factorize(m);
  int m0 = 0;
  std::vector<std::vector<int>> sols;
  for (const auto& pp : factors) {
    sols.push_back(kth_roots_mod_pe(k, a, pp));
    if (sols.back().empty()) return {};
  }
  std::vector<int> ans;
  for (int i = 0; i < (int)factors.size(); ++i) {
    auto pp = factors[i];
    if (!i) {
      m0 = pp.pe;
      ans = sols[i];
    } else {
      long long m1 = pp.pe * inv(pp.pe, m0);
      long long m2 = m0 * inv(m0, pp.pe);
      m0 *= pp.pe;
      std::vector<int> _ans;
      _ans.reserve(ans.size() * sols[i].size());
      for (auto x : ans) {
        for (auto y : sols[i]) {
          _ans.push_back((m1 * x + m2 * y) % m0);
        }
      }
      ans.swap(_ans);
    }
  }
  return ans;
}

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  auto ans = kth_roots_mod_m(n, k, m);
  if (ans.empty()) {
    std::cout << 0 << '\n';
    return;
  }
  std::cout << ans.size() << '\n';
  std::sort(ans.begin(), ans.end());
  for (auto x : ans) std::cout << x << ' ';
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for (; t; --t) {
    solve();
  }
}
