#include <iostream>

// --8<-- [start:core]
// Thuật toán Euclid mở rộng.
// Tìm các số nguyên x, y sao cho a*x + b*y = gcd(a, b),
// rồi trả về gcd(a, b).
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

// Giải phương trình đồng dư tuyến tính:
//     a * x ≡ b (mod n), trong đó n > 0.
// Trả về nghiệm không âm nhỏ nhất x,
// hoặc -1 nếu phương trình vô nghiệm.
int solve_linear_congruence_equation(int a, int b, int n) {
  int x, y;
  int d = ex_gcd(a, n, x, y);
  if (b % d) return -1;
  n /= d;
  return ((long long)x * (b / d) % n + n) % n;
}

// --8<-- [end:core]
int main() {
  int t;
  std::cin >> t;
  for (; t; --t) {
    int a, b, n;
    std::cin >> a >> b >> n;
    std::cout << solve_linear_congruence_equation(a, b, n) << '\n';
  }
  return 0;
}
