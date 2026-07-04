#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

constexpr int N = 2e5 + 6;
constexpr int LEN = 2e6 + 6;
constexpr int SIZE = 2e5 + 6;

int n;

namespace AC {
struct Node {
  int son[26];  // Các đỉnh con
  int ans;      // Số lần khớp
  int fail;     // Con trỏ fail
  int du;       // Bậc vào
  int idx;

  void init() {  // Khởi tạo đỉnh
    memset(son, 0, sizeof(son));
    ans = fail = idx = 0;
  }
} tr[SIZE];

int tot;  // Tổng số đỉnh
int ans[N], pidx;

void init() {
  tot = pidx = 0;
  tr[0].init();
}

void insert(char s[], int &idx) {
  int u = 0;
  for (int i = 1; s[i]; i++) {
    int &son = tr[u].son[s[i] - 'a'];  // Tham chiếu đến đỉnh con tiếp theo
    if (!son) son = ++tot, tr[son].init();  // Nếu chưa có thì thêm đỉnh mới
    u = son;                                // Tiếp tục từ đỉnh kế tiếp
  }
  // Các xâu mẫu trùng nhau cần được ánh xạ về cùng một chỉ số
  if (!tr[u].idx) tr[u].idx = ++pidx;  // Lần đầu xuất hiện, thêm chỉ số mới
  idx = tr[u].idx;  // Chỉ số của xâu mẫu này ứng với chỉ số của đỉnh
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
        tr[tr[tr[u].fail].son[i]].du++;                 // Đếm bậc vào
        q.push(tr[u].son[i]);                           // Đưa vào hàng đợi
      } else
        tr[u].son[i] =
            tr[tr[u].fail]
                .son[i];  // Nối trạng thái không tồn tại tới trạng thái theo fail
    }
  }
}

void query(char t[]) {
  int u = 0;
  for (int i = 1; t[i]; i++) {
    u = tr[u].son[t[i] - 'a'];  // Chuyển trạng thái
    tr[u].ans++;
  }
}

void topu() {
  queue<int> q;
  for (int i = 0; i <= tot; i++)
    if (tr[i].du == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans[tr[u].idx] = tr[u].ans;
    int v = tr[u].fail;
    tr[v].ans += tr[u].ans;
    if (!--tr[v].du) q.push(v);
  }
}
}  // namespace AC

char s[LEN];
int idx[N];

int main() {
  AC::init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    AC::insert(s, idx[i]);
    AC::ans[i] = 0;
  }
  AC::build();
  scanf("%s", s + 1);
  AC::query(s);
  AC::topu();
  for (int i = 1; i <= n; i++) {
    printf("%d\n", AC::ans[idx[i]]);
  }
  return 0;
}
