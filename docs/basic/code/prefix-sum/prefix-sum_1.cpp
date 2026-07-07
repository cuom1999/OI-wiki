#include <iostream>
#include <vector>

// --8<-- [start:core]
int n;                // Kích thước mảng.
std::vector<int> a;   // Mảng, đánh số từ 1.
std::vector<int> ps;  // Mảng tổng tiền tố.

// Tính tổng tiền tố.
void prefix_sum() {
  ps = a;
  // Hoặc đơn giản là:
  // std::partial_sum(a.begin(), a.end(), ps.begin());
  for (int i = 1; i <= n; ++i) {
    ps[i] += ps[i - 1];
  }
}

// Truy vấn tổng các phần tử trong [l, r].
int query(int l, int r) { return ps[r] - ps[l - 1]; }

// --8<-- [end:core]
int main() {
  std::cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  prefix_sum();
  int t;
  std::cin >> t;
  for (; t; --t) {
    int l, r;
    std::cin >> l >> r;
    std::cout << query(l, r) << '\n';
  }
  return 0;
}
