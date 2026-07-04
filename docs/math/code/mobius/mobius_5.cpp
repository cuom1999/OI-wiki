#include <algorithm>
#include <iostream>
#include <vector>

int pow(int a, int b, int m) {
  int res = 1;
  for (int po = a; b; b >>= 1) {
    if (b & 1) res = 1LL * res * po % m;
    po = 1LL * po * po % m;
  }
  return res;
}

int main() {
  constexpr int M = 104857601;
  int n;
  std::cin >> n;
  // Tính F(n), tức exp(Lambda(n)).
  std::vector<int> vis(n + 1), prime, pf(n + 1), rem(n + 1);
  prime.reserve(n);
  for (int x = 2; x <= n; ++x) {
    if (!vis[x]) {
      prime.emplace_back(x);
      pf[x] = x;
      rem[x] = 1;
    }
    for (int p : prime) {
      if (1LL * p * x > n) break;
      vis[x * p] = 1;
      pf[x * p] = p;
      rem[x * p] = x % p ? x : rem[x];
      if (x % p == 0) break;
    }
  }
  pf[1] = 1;
  for (int x = 2; x <= n; ++x) {
    pf[x] = rem[x] == 1 ? pf[x] : 1;
  }
  // Tích tiền tố và nghịch đảo của chúng.
  std::vector<int> pm(n + 1), ip(n + 1);
  pm[0] = 1;
  for (int x = 1; x <= n; ++x) {
    pm[x] = 1LL * pm[x - 1] * pf[x] % M;
  }
  int inv = pow(pm[n], M - 2, M);
  ip[0] = 1;
  for (int x = n; x >= 1; --x) {
    ip[x] = inv;
    inv = 1LL * inv * pf[x] % M;
  }
  // Tính g(n).
  int res = 1;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l);
    int a = 1LL * pm[r] * ip[l - 1] % M;
    int b = 1LL * (n / l) * (n / l) % (M - 1);
    res = 1LL * res * pow(a, b, M) % M;
  }
  // Lấy bình phương rồi lấy nghịch đảo.
  res = pow(res, M - 3, M);
  // Tính giai thừa.
  int fac = 1;
  for (int x = 1; x <= n; ++x) {
    fac = 1LL * fac * x % M;
  }
  // Đáp án cuối cùng.
  res = 1LL * res * pow(fac, 2 * n, M) % M;
  std::cout << res << std::endl;
  return 0;
}
