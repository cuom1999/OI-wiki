#include <cmath>
#include <iostream>
#include <vector>

// Cài đặt BIT đơn giản.
class BIT {
  int n;
  std::vector<int> su;

 public:
  BIT(int n) : n(n), su(n + 1) {}

  // Điền giá trị một vào BIT.
  void fill() {
    for (int x = 1; x <= n; ++x) {
      su[x] += x & (-x);
    }
  }

  // Cộng v vào phần tử thứ x.
  void add(int x, int v) {
    for (; x <= n; x += x & (-x)) {
      su[x] += v;
    }
  }

  // Lấy phần tử nhỏ thứ k.
  int find_kth(int k) {
    int ps = 0, x = 0;
    for (int i = log2(n); i >= 0; --i) {
      x += 1 << i;
      if (x >= n || ps + su[x] >= k) {
        x -= 1 << i;
      } else {
        ps += su[x];
      }
    }
    return x + 1;
  }
};

// Tìm cách sắp xếp thứ k của 1~n.
std::vector<int> find_permutation(int n, long long k) {
  --k;
  // Khai triển thứ hạng thành mã Lehmer.
  std::vector<int> lehmer(n);
  for (int i = 1; i <= n; ++i) {
    lehmer[n - i] = k % i;
    k /= i;
  }
  BIT bit(n);
  // Đặt mọi giá trị trong BIT bằng một.
  bit.fill();
  std::vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    // Tìm phần tử chưa dùng nhỏ thứ lehmer[i].
    res[i] = bit.find_kth(lehmer[i] + 1);
    // Loại bỏ phần tử đó khỏi BIT.
    bit.add(res[i], -1);
  }
  return res;
}

int main() {
  int n;
  long long k;
  std::cin >> n >> k;
  auto res = find_permutation(n, k);
  for (int num : res) {
    std::cout << num << ' ';
  }
  return 0;
}
