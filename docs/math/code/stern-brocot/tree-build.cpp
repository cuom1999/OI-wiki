#include <iostream>

// --8<-- [start:core]
// Duyet trung tu cay Stern-Brocot den tang N.
void build(int n, int a = 0, int b = 1, int c = 1, int d = 0, int level = 1) {
  if (level > n) return;  // Chi lay n tang dau.
  int x = a + c, y = b + d;
  build(n, a, b, x, y, level + 1);
  std::cout << x << '/' << y << ' ';  // In phan so hien tai.
  build(n, x, y, c, d, level + 1);
}

// --8<-- [end:core]
int main() {
  int n;
  std::cin >> n;
  build(n);
  std::cout << '\n';
  return 0;
}
