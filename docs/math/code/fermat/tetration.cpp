#include <iostream>

// Tính hàm phi Euler của n.
int phi(int n) {
  int res = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      res = res / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) res = res / n * (n - 1);
  return res;
}

// Tìm phần dư theo số mũ trong định lý Euler mở rộng.
int mod(long long v, int m) { return v >= m ? v % m + m : v; }

// Lũy thừa modulo.
int pow(int a, int b, int m) {
  long long res = 1, po = a;
  for (; b; b >>= 1) {
    if (b & 1) res = mod(res * po, m);
    po = mod(po * po, m);
  }
  return res;
}

// Tháp lũy thừa modulo.
int tetra(int a, int b, int m) {
  if (a == 0) return !(b & 1);
  if (b == 0 || m == 1) return 1;
  if (b == 1) return mod(a, m);
  return pow(a, tetra(a, b - 1, phi(m)), m);
}

int main() {
  int t;
  std::cin >> t;
  for (; t; --t) {
    int a, b, m;
    std::cin >> a >> b >> m;
    std::cout << (tetra(a, b, m) % m) << std::endl;
  }
}
