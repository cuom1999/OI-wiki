#include <iostream>
constexpr int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
// Tích các số nguyên tố trong p vượt quá 1e18

int n;
long long ans = 2e18;

// u: chỉ số của số nguyên tố đang xét trong p
// num: giá trị hiện tại được tạo ra
// cnt: số ước của giá trị hiện tại
// pre: số mũ của thừa số trước, giới hạn số mũ được chọn lần này
void dfs(int u, long long num, long long cnt, int pre) {
  if (cnt > n || u >= 15) return;
  if (cnt == n) return ans = std::min(ans, num), void();
  for (int i = 1; i <= pre; ++i) {
    if (num * p[u] > ans) break;  // cắt nhánh
    dfs(u + 1, num *= p[u], cnt * (i + 1), i);
  }
}

int main() {
  std::cin >> n;
  dfs(0, 1, 1, 59);  // floor(log2(1e18))=19
  std::cout << ans << std::endl;
  return 0;
}
