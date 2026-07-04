#include <cstring>
constexpr int MAXN = 100000;  // Ở đây MAXN là cận của phần tử trong mảng.

int solve(int n, int a[]) {
  bool met[MAXN * 2 + 1];  // Tạo bucket chứa được đoạn [-MAXN, MAXN].
  memset(met, 0, sizeof(met));
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (met[MAXN - a[i]]) ++ans;  // Nếu bucket có phần tử cần tìm, tăng đáp án.
    met[MAXN + a[i]] = true;      // Luôn đưa phần tử hiện tại vào bucket.
  }
  return ans * 2;
}
