#include <iostream>
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

// Tính thứ hạng của một cách sắp xếp của 1~n.
long long find_rank(const std::vector<int>& nums) {
  int n = nums.size();
  BIT bit(n);
  long long fac = 1;
  long long res = 0;
  // Duyệt ngược.
  for (int i = n - 1; i >= 0; --i) {
    // Đếm số phần tử nhỏ hơn phần tử hiện tại.
    res += bit.query(nums[i] - 1) * fac;
    // Chèn phần tử hiện tại vào BIT.
    bit.add(nums[i], 1);
    // Cập nhật giai thừa.
    fac *= n - i;
  }
  return res + 1;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int& num : nums) {
    std::cin >> num;
  }
  std::cout << find_rank(nums);
  return 0;
}
