#include <cstdio>
using namespace std;
constexpr int N = 500010;

char s[N];
int n, m, ch[N][26], tag[N], tot = 1;

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    int u = 1;
    for (int j = 1; s[j]; ++j) {
      int c = s[j] - 'a';
      // Nếu các con của đỉnh này chưa có ký tự này, thêm nó và lưu chỉ số đỉnh là ++tot
      if (!ch[u][c]) ch[u][c] = ++tot;
      u = ch[u][c];  // Tìm xuống tầng sâu hơn
    }
    tag[u] = 1;  // Tên kết thúc tại đỉnh u chưa được truy cập, ghi nhận là 1
  }

  scanf("%d", &m);

  while (m--) {
    scanf("%s", s + 1);
    int u = 1;
    for (int j = 1; s[j]; ++j) {
      int c = s[j] - 'a';
      u = ch[u][c];
      if (!u) break;  // Không có cạnh ứng với ký tự này, tức là tên không tồn tại
    }
    if (tag[u] == 1) {
      tag[u] = 2;  // Tên kết thúc tại đỉnh u đã được truy cập
      puts("OK");
    } else if (tag[u] == 2)  // Đã truy cập, bị lặp lại
      puts("REPEAT");
    else
      puts("WRONG");
  }

  return 0;
}
