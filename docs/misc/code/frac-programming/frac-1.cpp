#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;

constexpr int N = 100000 + 10;
constexpr double eps = 1e-6;

int n, k;
int a[N], b[N];
double c[N];

bool check(double mid) {
  double s = 0;
  for (int i = 1; i <= n; i++) c[i] = a[i] - b[i] * mid;
  // Sắp xếp trọng số theo thứ tự giảm dần
  sort(c + 1, c + n + 1, greater<double>());
  for (int i = 1; i <= k; ++i)  // Chọn k vật phẩm đầu tiên
    s += c[i];
  return s >= 0;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  double L = 0, R = 1;
  while (R - L > eps) {
    double mid = (L + R) / 2;
    if (check(mid))  // mid khả thi, đáp án lớn hơn mid
      L = mid;
    else  // mid không khả thi, đáp án nhỏ hơn mid
      R = mid;
  }
  printf("%.6lf\n", L);
  return 0;
}
