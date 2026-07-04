#include <iostream>
#include <vector>

// Sắp xếp trộn và đếm số nghịch thế.
long long merge_sort(std::vector<int>& nums, int b, int e) {
  // Trả về 0 khi độ dài <= 1.
  if (e - b <= 1) return 0;
  long long res = 0;
  int m = (b + e) / 2;
  // Sắp xếp trộn hai nửa.
  res += merge_sort(nums, b, m);
  res += merge_sort(nums, m, e);
  // Vector tạm để lưu mảng đã sắp xếp.
  std::vector<int> tmp(e - b);
  int i = b, j = m, k = 0;
  while (i < m && j < e) {
    if (nums[j] < nums[i]) {
      tmp[k] = nums[j++];
      // Trong trường hợp này, mọi phần tử trong [i,m) đều lớn hơn phần tử j.
      res += m - i;
    } else {
      tmp[k] = nums[i++];
    }
    ++k;
  }
  // Xử lý các phần tử còn lại.
  for (; i < m; ++i, ++k) {
    tmp[k] = nums[i];
  }
  for (; j < e; ++j, ++k) {
    tmp[k] = nums[j];
  }
  // Sao chép ngược về vector ban đầu.
  for (i = b, k = 0; i < e; ++i, ++k) {
    nums[i] = tmp[k];
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
  std::cout << merge_sort(nums, 0, n);
  return 0;
}
