#include <iostream>

int main() {
  int n = 0, u = 0, d = 0;
  std::cin >> u >> d >> n;
  int time = 0, dist = 0;
  while (true) {  // Dùng vòng lặp vô hạn để liệt kê.
    dist += u;
    time++;
    if (dist >= n) break;  // Thoát vòng lặp vô hạn khi thỏa điều kiện.
    dist -= d;
  }
  std::cout << time << '\n';  // In kết quả thu được.
  return 0;
}
