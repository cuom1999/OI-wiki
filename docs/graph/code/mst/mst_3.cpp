#include <algorithm>
#include <iostream>
using namespace std;

int fa[1010];  // Định nghĩa mảng cha.
int n, m, k;

struct edge {
  int u, v, w;
};

int l;
edge g[10010];

void add(int u, int v, int w) {
  l++;
  g[l].u = u;
  g[l].v = v;
  g[l].w = w;
}

// DSU chuẩn.
int findroot(int x) { return fa[x] == x ? x : fa[x] = findroot(fa[x]); }

void Merge(int x, int y) {
  x = findroot(x);
  y = findroot(y);
  fa[x] = y;
}

bool cmp(edge A, edge B) { return A.w < B.w; }

// Thuật toán Kruskal.
void kruskal() {
  int tot = 0;  // Lưu số cạnh đã chọn.
  int ans = 0;  // Lưu tổng chi phí.
  for (int i = 1; i <= m; i++) {
    int xr = findroot(g[i].u), yr = findroot(g[i].v);
    if (xr != yr) {        // Nếu hai gốc khác nhau.
      Merge(xr, yr);       // Hợp nhất.
      tot++;               // Tăng số cạnh.
      ans += g[i].w;       // Tăng chi phí.
      if (tot == n - k) {  // Kiểm tra số cạnh đã chọn có thỏa k kẹo bông không.
        cout << ans << '\n';
        return;
      }
    }
  }
  cout << "No Answer\n";  // Không thể nối thành công.
}

int main() {
  cin >> n >> m >> k;
  if (n == k) {  // Xử lý riêng trường hợp biên.
    cout << "0\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {  // Khởi tạo.
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);  // Thêm cạnh.
  }
  sort(g + 1, g + m + 1, cmp);  // Trước hết sắp xếp theo trọng số cạnh.
  kruskal();
  return 0;
}
