#include <iostream>

long long H(int n) {
  long long res = 0;  // Lưu kết quả
  int l = 1, r;       // Biên trái và biên phải của khối
  while (l <= n) {
    r = n / (n / l);  // Tính biên phải của khối hiện tại
    // Cộng đóng góp của khối này vào kết quả. Nhân 1LL để tránh tràn số
    res += 1LL * (r - l + 1) * (n / l);
    l = r + 1;  // Chuyển biên trái sang khối tiếp theo
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t, n;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::cout << H(n) << '\n';
  }
  return 0;
}
