#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

class LinearBasis {
  static constexpr int K = 20;
  std::array<int, K> a, t;

 public:
  LinearBasis() : a{}, t{} {}

  // Chèn vectơ x tại thời điểm i.
  void insert(int x, int i) {
    for (int k = K - 1; ~k && x; --k) {
      if (((x >> k) & 1)) {
        if (i > t[k]) {
          std::swap(a[k], x);
          std::swap(t[k], i);
        }
        x ^= a[k];
      }
    }
  }

  // Tìm xor lớn nhất của các tập con gồm các phần tử từ thời điểm i đến hiện tại.
  int query(int i) const {
    int res = 0;
    for (int k = K - 1; ~k; --k) {
      if (t[k] >= i && (res ^ a[k]) > res) {
        res ^= a[k];
      }
    }
    return res;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<int> c(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> c[i];
  int q;
  std::cin >> q;
  std::vector<std::array<int, 2>> qu(q);
  for (auto& v : qu) std::cin >> v[0] >> v[1];
  std::vector<int> ids(q);
  std::iota(ids.begin(), ids.end(), 0);
  std::sort(ids.begin(), ids.end(),
            [&](int l, int r) -> bool { return qu[l][1] < qu[r][1]; });
  LinearBasis lb;
  std::vector<int> res(q);
  for (int i = 1, j = 0; i <= n; ++i) {
    lb.insert(c[i], i);
    for (; j < q && qu[ids[j]][1] == i; ++j) {
      res[ids[j]] = lb.query(qu[ids[j]][0]);
    }
  }
  for (int x : res) std::cout << x << '\n';
  return 0;
}
