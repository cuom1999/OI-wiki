#include <iomanip>
#include <iostream>
using namespace std;
int n;
bool vis[50];  // Mảng đánh dấu đã thăm
int a[50];     // Mảng hoán vị, lưu kết quả tìm kiếm hiện tại theo thứ tự

void dfs(int step) {
  if (step == n + 1) {  // Điều kiện dừng
    for (int i = 1; i <= n; i++) {
      cout << setw(5) << a[i];  // Dành độ rộng trường là 5
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {  // Kiểm tra số i có đang nằm trong hoán vị hiện tại không
      vis[i] = true;
      a[step] = i;
      dfs(step + 1);
      vis[i] = false;  // Không dùng số này ở bước hiện tại; đặt lại để bước sau có thể dùng
    }
  }
  return;
}

int main() {
  cin >> n;
  dfs(1);
  return 0;
}
