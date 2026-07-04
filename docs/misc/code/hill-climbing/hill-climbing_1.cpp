#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
double ans[10001], cans[100001], dis[10001], tot, f[1001][1001];
int n;

void check() {
  tot = 0;
  for (int i = 1; i <= n + 1; i++) {
    dis[i] = 0;
    cans[i] = 0;
    for (int j = 1; j <= n; j++)
      dis[i] += (f[i][j] - ans[j]) * (f[i][j] - ans[j]);
    dis[i] = sqrt(dis[i]);  // Khoảng cách Euclid
    tot += dis[i];
  }
  tot /= (n + 1);  // Trung bình
  for (int i = 1; i <= n + 1; i++)
    for (int j = 1; j <= n; j++)
      cans[j] += (dis[i] - tot) * (f[i][j] - ans[j]) /
                 tot;  // Cập nhật lượng điều chỉnh trên từng chiều: chênh lệch khoảng cách Euclid * đóng góp của độ lệch
}

int main() {
  cin >> n;
  for (int i = 1; i <= n + 1; i++)
    for (int j = 1; j <= n; j++) {
      cin >> f[i][j];
      ans[j] += f[i][j];
    }
  for (int i = 1; i <= n; i++) ans[i] /= (n + 1);      // Khởi tạo
  for (double t = 10001; t >= 0.0001; t *= 0.99995) {  // Liên tục giảm nhiệt
    check();
    for (int i = 1; i <= n; i++) ans[i] += cans[i] * t;  // Điều chỉnh
  }
  cout << fixed << setprecision(3);
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
