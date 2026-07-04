#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

// Cài đặt BIT đơn giản.
class BIT {
  int n;
  std::vector<int> su;

 public:
  BIT(int n) : n(n), su(n + 1) {}

  // Cộng v vào phần tử thứ x.
  void add(int x, int v) {
    for (; x <= n; x += x & (-x)) {
      su[x] += v;
    }
  }

  // Lấy tổng tiền tố đến phần tử thứ x.
  int query(int x) {
    int res = 0;
    for (; x; x &= x - 1) {
      res += su[x];
    }
    return res;
  }
};

// Đếm số nghịch thế.
long long solve(const std::vector<int>& nums) {
  // Rời rạc hóa.
  std::vector<int> sorted(nums);
  std::sort(sorted.begin(), sorted.end());
  sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
  std::unordered_map<int, int> ids;
  int m = sorted.size();
  for (int i = 0; i < m; ++i) {
    // Đảo ngược thứ tự.
    // Bây giờ id nhỏ hơn tương ứng với phần tử lớn hơn.
    ids[sorted[i]] = m - i;
  }
  // Phần chính.
  BIT bit(m);
  long long res = 0;
  for (int num : nums) {
    int id = ids[num];
    // Đếm cặp nghịch thế (i,j) với j là phần tử hiện tại.
    // Tức là đếm số phần tử lớn hơn phần tử hiện tại
    //     nhưng nằm trước nó.
    res += bit.query(id - 1);
    // Chèn phần tử hiện tại vào BIT.
    bit.add(id, 1);
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int& num : nums) {
    std::cin >> num;
  }
  std::cout << solve(nums);
  return 0;
}
