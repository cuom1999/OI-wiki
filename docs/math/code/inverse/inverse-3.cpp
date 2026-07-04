// LOJ Submission: https://loj.ac/s/2401162
#include <iostream>
#include <vector>

// Thuật toán Euclid mở rộng.
void ex_gcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
  } else {
    ex_gcd(b, a % b, y, x);
    y -= a / b * x;
  }
}

// Trả về nghịch đảo modulo của a theo modulo m.
// Giả sử gcd(a, m) = 1, nên nghịch đảo tồn tại.
int inverse(int a, int m) {
  int x, y;
  ex_gcd(a, m, x, y);
  return (x % m + m) % m;
}

// --8<-- [start:core]
// Trả về nghịch đảo modulo của từng x trong a theo modulo m.
// Giả sử nghịch đảo của x theo modulo m tồn tại với mọi x trong a.
std::vector<int> batch_inverse(const std::vector<int>& a, int m) {
  int n = a.size();
  std::vector<int> prod(n);
  long long s = 1;
  for (int i = 0; i < n; ++i) {
    // prod[i] = tích của a[0...i-1]; prod[0] = 1.
    prod[i] = s;
    s = s * a[i] % m;
  }
  // s = tích của mọi phần tử trong a.
  s = inverse(s, m);
  std::vector<int> res(n);
  for (int i = n - 1; i >= 0; --i) {
    res[i] = s * prod[i] % m;
    s = s * a[i] % m;
  }
  return res;
}

// --8<-- [end:core]
int main() {
  int n, p = 1e9 + 7;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  auto inv = batch_inverse(a, p);
  int res = 0;
  for (auto x : inv) res = (998244353LL * res + x) % p;
  std::cout << res << std::endl;
}
