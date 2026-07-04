#include <iostream>
#include <vector>

// --8<-- [start:core]
// Tính (n!)_p modulo pa.
int factmod(int n, int p, int pa) {
  // Tiền xử lý.
  std::vector<int> f(pa);
  f[0] = 1;
  for (int i = 1; i < pa; ++i) {
    f[i] = i % p ? (long long)f[i - 1] * i % pa : f[i - 1];
  }
  // Đệ quy bằng vòng lặp.
  bool neg = p != 2 || pa <= 4;
  int res = 1;
  while (n > 1) {
    if ((n / pa) & neg) res = pa - res;
    res = (long long)res * f[n % pa] % pa;
    n /= p;
  }
  return res;
}

// --8<-- [end:core]
int main() {
  int t;
  std::cin >> t;
  for (; t; --t) {
    int n, p, pa;
    std::cin >> n >> p >> pa;
    std::cout << factmod(n, p, pa) << '\n';
  }
  return 0;
}
