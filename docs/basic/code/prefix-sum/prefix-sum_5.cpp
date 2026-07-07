#include <iostream>
#include <vector>

// --8<-- [start:core]
int n;
std::vector<int> a, ps;  // độ dài = 1 << n.

void sum_of_subsets() {
  ps = a;
  // Duyệt qua các chiều.
  for (int i = 0; i < n; ++i) {
    // Duyệt theo chiều thứ i.
    for (int st = 0; st < (1 << n); ++st) {
      // Điều kiện này cho biết chiều thứ i bằng 1.
      if ((st >> i) & 1) {
        // ps[... 1 ...] += ps[... 0 ...]. (chiều thứ i)
        ps[st] += ps[st ^ (1 << i)];
      }
    }
  }
}

// --8<-- [end:core]
int main() {
  std::cin >> n;
  a.resize(1 << n);
  for (int& x : a) std::cin >> x;

  sum_of_subsets();

  for (int x : ps) std::cout << x << ' ';
  std::cout << std::endl;
  return 0;
}
