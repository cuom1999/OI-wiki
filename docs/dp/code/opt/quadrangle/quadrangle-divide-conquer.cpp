// Submission: https://loj.ac/s/2464464
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

constexpr int N = 500010;
using val_t = long double;
constexpr val_t inf = 1e18;

// --8<-- [start:core]
val_t w(int j, int i);  // Hàm chi phí
val_t f[N];             // Giá trị tối ưu
int opt[N];             // Quyết định tối ưu nhỏ nhất

// Đệ quy giải các bài toán trong [l,r]
// Biết rằng điểm quyết định tối ưu nhỏ nhất của chúng chắc chắn nằm trong [opt_l, opt_r]
void calc(int l, int r, int opt_l, int opt_r) {
  int mid = (l + r) / 2;
  // Tìm điểm quyết định tối ưu của bài toán mid
  for (int j = opt_l; j <= std::min(opt_r, mid); ++j) {
    if (w(j, mid) < f[mid]) {
      f[mid] = w(j, mid);
      opt[mid] = j;
    }
  }
  // Dựa vào tính đơn điệu quyết định để lấy khoảng quyết định cho hai nửa rồi xử lý đệ quy
  if (l < mid) calc(l, mid - 1, opt_l, opt[mid]);
  if (r > mid) calc(mid + 1, r, opt[mid], opt_r);
}

// Giải các bài toán trên toàn khoảng [1,n]
void solve(int n) {
  // Trước mỗi lần gọi hàm đệ quy, cần xóa mảng f
  std::fill(f + 1, f + n + 1, inf);
  // Ban đầu chỉ biết mọi điểm quyết định của các bài toán [1,n] đều nằm trong [1,n]
  calc(1, n, 1, n);
}

// --8<-- [end:core]
std::function<val_t(int, int)> impl;

val_t w(int j, int i) { return impl(j, i); }

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), ans(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  impl = [&](int j, int i) -> long double {
    return a[i] - a[j] - std::sqrt((long double)(i - j));
  };
  solve(n);
  for (int i = 1; i <= n; ++i) ans[i] = std::ceil(-f[i]);
  std::reverse(a.begin() + 1, a.end());
  solve(n);
  for (int i = 1; i <= n; ++i)
    std::cout << std::max(ans[i], (int)std::ceil(-f[n + 1 - i])) << '\n';
  return 0;
}
