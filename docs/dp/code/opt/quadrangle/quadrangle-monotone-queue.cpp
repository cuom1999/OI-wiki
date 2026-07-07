// Bài nộp: https://loj.ac/s/2464486
#include <algorithm>
#include <cmath>
#include <deque>
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
int lt[N], rt[N];       // Khoảng bài toán [l_j,r_j] mà quyết định j có thể giải

// Giải các bài toán trên toàn khoảng [1,n]
void solve(int n) {
  std::deque<int> dq;  // Hàng đợi đơn điệu lưu mọi quyết định khả thi

  // Xét tuần tự mọi bài toán và quyết định, chỉ số bắt đầu từ 1
  for (int j = 1; j <= n; ++j) {
    // Ra hàng đợi
    if (!dq.empty() && rt[dq.front()] < j) dq.pop_front();
    if (!dq.empty()) lt[dq.front()] = j;
    // Vào hàng đợi
    while (!dq.empty() && w(j, lt[dq.back()]) < w(dq.back(), lt[dq.back()])) {
      dq.pop_back();
    }
    if (dq.empty()) {
      lt[j] = j;
      rt[j] = n;
      dq.emplace_back(j);
    } else if (w(j, rt[dq.back()]) >= w(dq.back(), rt[dq.back()])) {
      if (rt[dq.back()] < n) {
        lt[j] = rt[dq.back()] + 1;
        rt[j] = n;
        dq.emplace_back(j);
      }
    } else {
      int ll = lt[dq.back()], rr = rt[dq.back()], i = rr;
      // Tìm kiếm nhị phân
      while (ll <= rr) {
        int mm = (ll + rr) / 2;
        if (w(j, mm) < w(dq.back(), mm)) {
          i = mm;
          rr = mm - 1;
        } else {
          ll = mm + 1;
        }
      }
      rt[dq.back()] = i - 1;
      lt[j] = i;
      rt[j] = n;
      dq.emplace_back(j);
    }
    // Tính kết quả
    f[j] = w(dq.front(), j);
    opt[j] = dq.front();
  }
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
