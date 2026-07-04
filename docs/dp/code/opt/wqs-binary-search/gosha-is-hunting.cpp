#include <algorithm>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <vector>

// Tìm kiếm theo tỉ lệ vàng trên miền số thực (hàm đơn đỉnh)
template <typename T, typename F>
typename std::enable_if<
    std::is_floating_point<T>::value,
    std::pair<T, decltype(std::declval<F>()(std::declval<T>()))>>::type
golden_section_search(T ll, T rr, F func, T eps) {
  constexpr long double phi = 0.618033988749894848204586834L;
  T ml = ll + (rr - ll) * (1 - phi);
  T mr = ll + (rr - ll) * phi;
  auto fl = func(ml), fr = func(mr);
  while ((rr - ll) > eps) {
    if (fl > fr) {
      rr = mr;
      mr = ml;
      fr = fl;
      ml = ll + (rr - ll) * (1 - phi);
      fl = func(ml);
    } else {
      ll = ml;
      ml = mr;
      fl = fr;
      mr = ll + (rr - ll) * phi;
      fr = func(mr);
    }
  }
  T mid = (ll + rr) / 2;
  return {mid, func(mid)};
}

int main() {
  int n, m1, m2;
  std::cin >> n >> m1 >> m2;
  std::vector<long double> p(n + 1), q(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> p[i];
  for (int i = 1; i <= n; ++i) std::cin >> q[i];
  // Tính h(k1,k2).
  auto solve = [&](long double k1, long double k2) -> long double {
    long double res = 0;
    for (int i = 1; i <= n; ++i) {
      res += std::max(
          {0.0l, p[i] + k1, q[i] + k2, p[i] + q[i] - p[i] * q[i] + k1 + k2});
    }
    return res;
  };
  // Giải bài toán đối ngẫu để tìm v(m1,m2).
  // Cài đặt dưới dạng bài toán cực tiểu bằng cách thêm dấu âm.
  auto res = -golden_section_search(
                  -1.0l, 0.0l,
                  [&](long double k1) -> long double {
                    return golden_section_search(
                               -1.0l, 0.0l,
                               [&](long double k2) -> long double {
                                 return -solve(k1, k2) + k2 * m2;
                               },
                               1e-8l)
                               .second +
                           k1 * m1;
                  },
                  1e-8l)
                  .second;
  std::cout << std::fixed << std::setprecision(10) << res << std::endl;
  return 0;
}
