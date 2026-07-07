#include <iostream>
#include <vector>

// --8<-- [start:core]
int N1, N2, N3;
std::vector<std::vector<std::vector<int>>> a,
    ps;  // (N1 + 1) x (N2 + 1) x (N3 + 1).

// Tính tổng tiền tố của mảng 3 chiều.
void prefix_sum() {
  ps = a;

  // Tổng tiền tố theo chiều thứ 3.
  for (int i = 1; i <= N1; ++i)
    for (int j = 1; j <= N2; ++j)
      for (int k = 1; k <= N3; ++k) ps[i][j][k] += ps[i][j][k - 1];

  // Tổng tiền tố theo chiều thứ 2.
  for (int i = 1; i <= N1; ++i)
    for (int j = 1; j <= N2; ++j)
      for (int k = 1; k <= N3; ++k) ps[i][j][k] += ps[i][j - 1][k];

  // Tổng tiền tố theo chiều thứ 1.
  for (int i = 1; i <= N1; ++i)
    for (int j = 1; j <= N2; ++j)
      for (int k = 1; k <= N3; ++k) ps[i][j][k] += ps[i - 1][j][k];
}

// --8<-- [end:core]
int main() {
  // Nhập dữ liệu.
  std::cin >> N1 >> N2 >> N3;
  a.assign(N1 + 1,
           std::vector<std::vector<int>>(N2 + 1, std::vector<int>(N3 + 1)));

  for (int i = 1; i <= N1; ++i)
    for (int j = 1; j <= N2; ++j)
      for (int k = 1; k <= N3; ++k) std::cin >> a[i][j][k];

  // Tính toán.
  prefix_sum();

  // Xuất dữ liệu.
  for (int i = 1; i <= N1; ++i) {
    for (int j = 1; j <= N2; ++j) {
      for (int k = 1; k <= N3; ++k) {
        std::cout << ps[i][j][k] << ' ';
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }

  return 0;
}
