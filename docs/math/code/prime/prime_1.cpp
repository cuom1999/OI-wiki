#include <iostream>
constexpr int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
// Tich cac so nguyen to trong p vuot qua 1e18

int n;
long long ans = 2e18;

// u: chi so cua so nguyen to dang xet trong p
// num: gia tri hien tai duoc tao ra
// cnt: so uoc cua gia tri hien tai
// pre: so mu cua thua so truoc, gioi han so mu duoc chon lan nay
void dfs(int u, long long num, long long cnt, int pre) {
  if (cnt > n || u >= 15) return;
  if (cnt == n) return ans = std::min(ans, num), void();
  for (int i = 1; i <= pre; ++i) {
    if (num * p[u] > ans) break;  // cat nhanh
    dfs(u + 1, num *= p[u], cnt * (i + 1), i);
  }
}

int main() {
  std::cin >> n;
  dfs(0, 1, 1, 59);  // floor(log2(1e18))=19
  std::cout << ans << std::endl;
  return 0;
}
