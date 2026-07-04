#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

constexpr int N = 1e6 + 6;
constexpr int LEN = 1e6 + 6;
constexpr int SIZE = 1e6 + 6;

int n;

namespace AC {
struct Node {
  int son[26];  // Các đỉnh con
  int cnt;      // Số xâu kết thúc tại đỉnh này
  int fail;     // Con trỏ fail

  void init() {  // Khởi tạo đỉnh
    memset(son, 0, sizeof(son));
    cnt = fail = 0;
  }
} tr[SIZE];

int tot;  // Tổng số đỉnh

void init() {
  tot = 0;
  tr[0].init();
}

void insert(char s[]) {
  int u = 0;
  for (int i = 1; s[i]; i++) {
    int &son = tr[u].son[s[i] - 'a'];  // Tham chiếu đến đỉnh con tiếp theo
    if (!son) son = ++tot, tr[son].init();  // Nếu chưa có thì thêm đỉnh mới
    u = son;                                // Tiếp tục từ đỉnh kế tiếp
  }
  tr[u].cnt++;
}

void build() {
  queue<int> q;
  for (int i = 0; i < 26; i++)
    if (tr[0].son[i]) q.push(tr[0].son[i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (tr[u].son[i]) {                               // Có đỉnh con tương ứng
        tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];  // Chỉ cần nhảy fail một lần
        q.push(tr[u].son[i]);                           // Đưa vào hàng đợi
      } else
        tr[u].son[i] =
            tr[tr[u].fail]
                .son[i];  // Nối trạng thái không tồn tại tới trạng thái theo fail
    }
  }
}

int query(char t[]) {
  int u = 0, res = 0;
  for (int i = 1; t[i]; i++) {
    u = tr[u].son[t[i] - 'a'];  // Chuyển trạng thái
    for (int j = u; j && tr[j].cnt != -1; j = tr[j].fail) {
      res += tr[j].cnt, tr[j].cnt = -1;
    }
  }
  return res;
}
}  // namespace AC

char s[LEN];

int main() {
  AC::init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    AC::insert(s);
  }
  AC::build();
  scanf("%s", s + 1);
  printf("%d", AC::query(s));
  return 0;
}
