// --8<-- [start:full-text]
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

// --8<-- [start:core]
int m, n;  // Số ràng buộc và số biến.
std::vector<std::vector<long double>>
    tab;                             // Tableau nén (chuyển vị), kèm theo
                                     // hàm mục tiêu của giai đoạn một.
std::vector<int> B, N;               // Biến cơ sở và biến phi cơ sở.
constexpr long double eps = 1e-12l;  // Độ chính xác.

// --8<-- [start:pivot]
// Xoay trục trên (N[x], B[y]).
void pivot(int x, int y) {
  std::swap(N[x], B[y]);
  long double v = -1 / tab[x][y];
  for (int j = 0; j <= m + 1; ++j) {
    tab[x][j] = j == y ? -v : v * tab[x][j];
  }
  for (int i = 0; i <= n; ++i) {
    if (i == x) continue;
    v = tab[i][y];
    tab[i][y] = 0;
    for (int j = 0; j <= m + 1; ++j) {
      tab[i][j] += v * tab[x][j];
    }
  }
}

// --8<-- [end:pivot]
// --8<-- [start:initialize]
// Giai đoạn một: tìm một BFS ban đầu.
// Trả về false nếu không có nghiệm khả thi.
bool initialize() {
  int neg_count = 0;
  for (int j = 0; j < m; ++j) {
    if (tab[n][j] < -eps) {
      for (int i = 0; i <= n; ++i) {
        tab[i][m + 1] += tab[i][j];
      }
      B[j] = ~B[j];
      ++neg_count;
    }
  }
  while (neg_count) {
    int x = -1;
    long double mi = -eps;
    for (int i = 0; i < n; ++i) {
      if (tab[i][m + 1] < mi) {
        x = i;
        mi = tab[i][m + 1];
      }
    }
    if (x == -1) return false;
    int y = -1;
    mi = INFINITY;
    for (int j = 0; j < m; ++j) {
      if ((B[j] < 0 && tab[x][j] < -eps) || (B[j] >= 0 && tab[x][j] > eps)) {
        auto tmp = tab[n][j] / tab[x][j] + (B[j] < 0 ? -eps : eps);
        if (tmp < mi) {
          y = j;
          mi = tmp;
        }
      }
    }
    if (B[y] < 0) {
      --neg_count;
      B[y] = ~B[y];
      pivot(x, y);
      tab[x][m + 1] += 1;
    } else {
      pivot(x, y);
    }
  }
  return true;
}

// --8<-- [end:initialize]
// --8<-- [start:simplex]
// Giai đoạn hai: tìm một BFS tối ưu.
// Trả về false nếu bài toán không bị chặn.
bool simplex() {
  while (true) {
    int x = -1;
    long double mi = -eps;
    for (int i = 0; i < n; ++i) {
      if (tab[i][m] < mi) {
        x = i;
        mi = tab[i][m];
      }
    }
    // Không còn cột nào có chi phí rút gọn âm => tối ưu.
    if (x == -1) break;
    int y = -1;
    mi = INFINITY;
    for (int j = 0; j < m; ++j) {
      if (tab[x][j] <= eps) continue;
      if (tab[n][j] / tab[x][j] < mi) {
        y = j;
        mi = tab[n][j] / tab[x][j];
      }
    }
    // Không còn hàng nào có tỉ số dương => không bị chặn.
    if (y == -1) return false;
    pivot(x, y);
  }
  return true;
}

// --8<-- [end:simplex]
int solve() {
  B.resize(m);
  N.resize(n);
  std::iota(B.begin(), B.end(), n);
  std::iota(N.begin(), N.end(), 0);
  return initialize() ? (simplex() ? 0 : 1) : -1;
}

// --8<-- [end:core]
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(8);
  std::cin >> n >> m;
  tab.assign(n + 1, std::vector<long double>(m + 2));
  for (int i = 0; i < n; ++i) {
    std::cin >> tab[i][m];
    tab[i][m] = -tab[i][m];
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i <= n; ++i) {
      std::cin >> tab[i][j];
    }
  }
  switch (solve()) {
    case -1:
      std::cout << "Infeasible" << std::endl;
      break;
    case 1:
      std::cout << "Unbounded" << std::endl;
      break;
    case 0: {
      std::cout << tab[n][m] << std::endl;
      std::vector<long double> x(n);
      for (int j = 0; j < m; ++j) {
        if (B[j] < n) x[B[j]] = tab[n][j];
      }
      for (int i = 0; i < n; ++i) {
        std::cout << x[i] << ' ';
      }
      std::cout << std::endl;
      break;
    }
  }
  return 0;
}

// --8<-- [end:full-text]
