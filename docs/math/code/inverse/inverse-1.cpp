#include <iostream>

// --8<-- [start:core]
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

// --8<-- [end:core]
int main() {
  int t;
  std::cin >> t;
  for (; t; --t) {
    int a, m;
    std::cin >> a >> m;
    std::cout << inverse(a, m) << std::endl;
  }
}
