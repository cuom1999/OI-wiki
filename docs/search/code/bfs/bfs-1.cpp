#include <iostream>
#include <queue>
using namespace std;

char a[110][110];    // Lưu bản đồ mê cung
bool vis[110][110];  // Ghi nhận trạng thái đã thăm
int n, m;            // Kích thước mê cung

struct node {
  int x, y;
};  // Định nghĩa cấu trúc tọa độ

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};  // Mảng hướng (phải, trái, xuống, lên)

// Kiểm tra tọa độ có hợp lệ không
bool chk(int x, int y) {
  return (x >= 1 && x <= n && y >= 1 && y <= m  // Kiểm tra biên
          && !vis[x][y]                         // Chưa từng thăm
          && a[x][y] != '#');                   // Không phải vật cản
}

bool bfs() {
  queue<node> q;
  q.push({1, 1});  // Đưa điểm xuất phát vào hàng đợi
  vis[1][1] = 1;   // Đánh dấu điểm xuất phát đã thăm
  while (!q.empty()) {
    node p = q.front();  // Lấy tọa độ ở đầu hàng đợi
    q.pop();
    int px = p.x, py = p.y;
    if (px == n && py == m) return true;  // Tới đích thì trả về ngay
    // Mở rộng theo bốn hướng
    for (int i = 0; i < 4; ++i) {
      int nx = px + dx[i], ny = py + dy[i];
      if (chk(nx, ny)) {   // Kiểm tra hợp lệ
        q.push({nx, ny});  // Đưa tọa độ mới vào hàng đợi
        vis[nx][ny] = 1;   // Đánh dấu đã thăm
      }
    }
  }
  return false;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  cout << (bfs() ? "Yes" : "No") << endl;
  return 0;
}
