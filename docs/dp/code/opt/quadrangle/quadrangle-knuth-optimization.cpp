// Đã được kiểm chứng tại https://www.spoj.com/problems/BRKSTRNG/
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>

using val_t = int;
constexpr val_t inf = 0x3f3f3f3f;
constexpr int N = 1024;

// --8<-- [start:core]
val_t w(int j, int i);  // Hàm chi phí
val_t f[N][N];          // Giá trị tối ưu
int opt[N][N];          // Quyết định tối ưu nhỏ nhất

// Giải bài toán ứng với toàn khoảng [1,n]
void solve(int n) {
  // Khởi tạo
  for (int i = 1; i <= n; ++i) {
    f[i][i] = 0;
    opt[i][i] = i;
  }
  // Liệt kê độ dài khoảng
  for (int len = 2; len <= n; ++len) {
    // Liệt kê mọi khoảng có độ dài len
    for (int j = 1, i = len; i <= n; ++j, ++i) {
      f[j][i] = inf;
      for (int k = opt[j][i - 1]; k <= opt[j + 1][i]; ++k)
        if (f[j][i] > f[j][k] + f[k + 1][i] + w(j, i)) {
          f[j][i] = f[j][k] + f[k + 1][i] + w(j, i);  // Cập nhật giá trị trạng thái
          opt[j][i] = k;  // Cập nhật điểm quyết định tối ưu (nhỏ nhất)
        }
    }
  }
}

// --8<-- [end:core]
std::function<val_t(int, int)> impl;

int w(int j, int i) { return impl(j, i); }

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  int n, m;
  while (std::cin >> n >> m) {
    std::vector<int> ps(m + 2);
    for (int i = 1; i <= m; ++i) std::cin >> ps[i];
    ps[m + 1] = n;
    impl = [&](int j, int i) -> int { return ps[i] - ps[j - 1]; };
    solve(m + 1);
    std::cout << f[1][m + 1] << '\n';
  }
}
