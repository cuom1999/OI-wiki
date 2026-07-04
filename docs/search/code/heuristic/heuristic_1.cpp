#include <algorithm>
#include <iostream>
using namespace std;
constexpr int N = 105;
int n, m, ans;

struct Node {
  int a, b;  // a biểu thị thời gian, b biểu thị giá trị
  double f;
} node[N];

bool operator<(Node p, Node q) { return p.f > q.f; }

int f(int t, int v) {  // Tính giá trị lớn nhất của các vật còn lại với thời gian hiện tại
  int tot = 0;
  for (int i = 1; t + i <= n; i++)
    if (v >= node[t + i].a) {
      v -= node[t + i].a;
      tot += node[t + i].b;
    } else
      return (int)(tot + v * node[t + i].f);
  return tot;
}

void work(int t, int p, int v) {
  ans = max(ans, v);
  if (t > n) return;                         // Điều kiện biên: chỉ có n loại vật
  if (f(t, p) + v > ans) work(t + 1, p, v);  // Cắt tỉa tối ưu
  if (node[t].a <= p) work(t + 1, p - node[t].a, v + node[t].b);  // Cắt tỉa khả thi
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> node[i].a >> node[i].b;
    node[i].f = 1.0 * node[i].b / node[i].a;  // f là tỉ lệ giá trị/thời gian
  }
  sort(node + 1, node + n + 1);  // Sắp xếp theo tỉ lệ giá trị/thời gian
  work(1, m, 0);
  cout << ans << '\n';
  return 0;
}
