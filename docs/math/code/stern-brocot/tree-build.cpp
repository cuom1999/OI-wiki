#include <iostream>

// --8<-- [start:core]
// Duyệt trung tự cây Stern-Brocot đến tầng N.
void build(int n, int a = 0, int b = 1, int c = 1, int d = 0, int level = 1) {
  if (level > n) return;  // Chỉ lấy n tầng đầu.
  int x = a + c, y = b + d;
  build(n, a, b, x, y, level + 1);
  std::cout << x << '/' << y << ' ';  // In phân số hiện tại.
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
