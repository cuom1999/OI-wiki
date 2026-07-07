author: StudyingFather, Backl1ght, countercurrent-time, Ir1d, greyqz, MicDZ, ouuan, Linky

## Thuật toán Mo trên cây theo thứ tự ngoặc

Thuật toán Mo thông thường chỉ xử lý được bài toán tuyến tính, vì vậy cần ép cây thành một dãy.

Có thể duyệt thứ tự ngoặc của cây, chia khối trên thứ tự ngoặc rồi chạy thuật toán Mo trên dãy đó.

Cụ thể làm như sau.

### Quy trình

DFS cây. Khi DFS tới đỉnh x thì `push_back(x)`, khi DFS x xong thì `push_back(-x)`. Khi di chuyển con trỏ:

-   Giá trị mới được thêm là x --->`add(x)`
-   Giá trị mới được thêm là -x --->`del(x)`
-   Giá trị mới bị xóa là x --->`del(x)`
-   Giá trị mới bị xóa là -x --->`add(x)`

Như vậy, cây đã được biến thành một dãy.

### Ví dụ

???+ note "Ví dụ [WC2013 Candy Park](https://uoj.ac/problem/58)"
    Đề bài: cho một cây, đỉnh thứ $i$ trên cây có màu $c_i$. Mỗi truy vấn cho một đường đi $u_i$,$v_i$, cần tính trên đường đi đó:
    
    $\sum_{c}val_c\sum_{i=1}^{cnt_c}w_i$
    
    Trong đó: $val$ biểu thị giá trị của màu, $cnt$ biểu thị số lần màu xuất hiện, còn $w$ biểu thị giá trị sau khi màu đó xuất hiện $i$ lần.

#### Quy trình

Trước hết biến cây thành một dãy. Sau đó, mỗi lần thêm/xóa một đỉnh, đóng góp của đỉnh này vào đáp án có thể tính trong $O(1)$: khi thêm màu $c$ thì tăng $val_c\times w_{cnt_c+1}$, còn khi xóa màu $c$ thì giảm $val_c\times w_{cnt_c}$.

Quá trình này cũng quét qua cây con của điểm bắt đầu, tạo ra đóng góp thừa. Cần xử lý phần thừa này.

Trong quá trình quét, các đỉnh trong cây con của điểm bắt đầu sẽ bị quét hai lần, nên đóng góp của chúng là 0.

Vì vậy có thể dùng một mảng $vis$; mỗi lần quét tới đỉnh x, XOR $vis_x$ với 1.

Nếu $vis_x=0$, đóng góp của đỉnh này có thể bỏ qua.

Do đó có thể dùng thuật toán Mo trên cây để giải.

Với thao tác sửa đổi, chỉ cần thêm một chiều thời gian để thu được thuật toán Mo trên cây có sửa đổi.

Ngoài ra, đoạn đang xét có thể không chứa LCA. Với trường hợp này, cần loại bỏ phần đóng góp thừa là xong.

#### Cài đặt

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cmath>
    #include <cstdio>
    using namespace std;
    
    constexpr int MAXN = 200010;
    
    int f[MAXN], g[MAXN], id[MAXN], head[MAXN], cnt, last[MAXN], dep[MAXN],
        fa[MAXN][22], v[MAXN], w[MAXN];
    int block, index, n, m, q;
    int pos[MAXN], col[MAXN], app[MAXN];
    bool vis[MAXN];
    long long ans[MAXN], cur;
    
    struct edge {
      int to, nxt;
    } e[MAXN];
    
    int cnt1 = 0, cnt2 = 0;  // Mốc thời gian
    
    struct query {
      int l, r, t, id;
    
      bool operator<(const query &b) const {
        return (pos[l] < pos[b.l]) || (pos[l] == pos[b.l] && pos[r] < pos[b.r]) ||
               (pos[l] == pos[b.l] && pos[r] == pos[b.r] && t < b.t);
      }
    } a[MAXN], b[MAXN];
    
    void addedge(int x, int y) {
      e[++cnt] = edge{y, head[x]};
      head[x] = cnt;
    }
    
    void dfs(int x) {
      id[f[x] = ++index] = x;
      for (int i = head[x]; i; i = e[i].nxt) {
        if (e[i].to != fa[x][0]) {
          fa[e[i].to][0] = x;
          dep[e[i].to] = dep[x] + 1;
          dfs(e[i].to);
        }
      }
      id[g[x] = ++index] = x;  // Thứ tự ngoặc
    }
    
    int lca(int x, int y) {
      if (dep[x] < dep[y]) swap(x, y);
      if (dep[x] != dep[y]) {  // Đưa lên cùng độ sâu
        int dis = dep[x] - dep[y];
        for (int i = 20; i >= 0; i--)
          if (dis >= (1 << i)) dis -= 1 << i, x = fa[x][i];
      }
      if (x == y) return x;
      for (int i = 20; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
      }
      return fa[x][0];
    }
    
    void add(int x) {
      if (vis[x])
        cur -= (long long)v[col[x]] * w[app[col[x]]--];
      else
        cur += (long long)v[col[x]] * w[++app[col[x]]];
      vis[x] ^= 1;
    }
    
    // Di chuyển trên chiều thời gian
    void modify(int x, int t) {
      if (vis[x]) {
        add(x);
        col[x] = t;
        add(x);
      } else
        col[x] = t;
    }
    
    int main() {
      scanf("%d%d%d", &n, &m, &q);
      for (int i = 1; i <= m; i++) scanf("%d", &v[i]);
      for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
      for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
      }
      for (int i = 1; i <= n; i++) {
        scanf("%d", &last[i]);
        col[i] = last[i];
      }
      dfs(1);
      for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
          fa[i][j] = fa[fa[i][j - 1]][j - 1];  // Tiền xử lý tổ tiên
      int block = pow(index, 2.0 / 3);
      for (int i = 1; i <= index; i++) {
        pos[i] = (i - 1) / block;
      }
      while (q--) {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 0) {
          b[++cnt2].l = x;
          b[cnt2].r = last[x];
          last[x] = b[cnt2].t = y;
        } else {
          if (f[x] > f[y]) swap(x, y);
          a[++cnt1] = query{lca(x, y) == x ? f[x] : g[x], f[y], cnt2, cnt1};
        }
      }
      sort(a + 1, a + cnt1 + 1);
      int L, R, T;  // Tọa độ con trỏ
      L = R = 0;
      T = 1;
      for (int i = 1; i <= cnt1; i++) {
        while (T <= a[i].t) {
          modify(b[T].l, b[T].t);
          T++;
        }
        while (T > a[i].t) {
          modify(b[T].l, b[T].r);
          T--;
        }
        while (L > a[i].l) {
          L--;
          add(id[L]);
        }
        while (L < a[i].l) {
          add(id[L]);
          L++;
        }
        while (R > a[i].r) {
          add(id[R]);
          R--;
        }
        while (R < a[i].r) {
          R++;
          add(id[R]);
        }
        int x = id[L], y = id[R];
        int llca = lca(x, y);
        if (x != llca && y != llca) {
          add(llca);
          ans[a[i].id] = cur;
          add(llca);
        } else
          ans[a[i].id] = cur;
      }
      for (int i = 1; i <= cnt1; i++) {
        printf("%lld\n", ans[i]);
      }
      return 0;
    }
    ```

## Thuật toán Mo thật sự trên cây

Thuật toán Mo trên cây ở trên chỉ biến cây thành một chuỗi. Phần dưới đây mới là thuật toán Mo đúng nghĩa trên cây.

Vì các bài liên quan tới thuật toán Mo thường là bài mẫu, phần cài đặt sẽ không giải thích quá nhiều.

### Sắp xếp truy vấn

Thuật toán Mo dựa trên chia khối, nên cần tìm một cách chia khối trên cây để bảo đảm độ phức tạp thời gian.

Các điều kiện:

-   Khoảng cách giữa các đỉnh thuộc cùng một khối không vượt quá kích thước khối cho trước.
-   Số đỉnh trong mỗi khối không được quá nhiều cũng không được quá ít.
-   Mỗi đỉnh đều phải thuộc một khối.
-   Khoảng cách giữa các khối có chỉ số kề nhau không được quá lớn.

Sau khi nắm các điều kiện này, xét bài [SCOI2005 Royal Federation](https://loj.ac/problem/2152).

Dựa trên bài này, chỉ cần bảo đảm thêm điều kiện cuối cùng là có thể giải quyết vấn đề chia khối.

??? note "Ý tưởng"
    Gọi lim là kích thước khối mong muốn. Trước hết DFS toàn bộ cây; khi kích thước một cây con lớn hơn lim, đưa các đỉnh đó vào cùng một khối. Với gốc có thể còn dư một số đỉnh, khi đó đưa các đỉnh này vào khối cuối cùng.

Cách làm: dùng một ngăn xếp để duy trì các đỉnh con được thăm khi đỉnh hiện tại đóng vai trò cha. Khi khoảng cách từ đỉnh trên cùng của ngăn xếp tới đỉnh cha lớn hơn kích thước khối mong muốn, lấy phần tử của đoạn này ra để tạo thành một khối. Phần còn lại cuối cùng tạo thành một khối riêng.

Cách sắp xếp cuối cùng: nếu mốc thời gian ở chiều thứ nhất lớn hơn chiều thứ hai thì hoán đổi chúng; sau đó sắp theo khối chứa chiều thứ nhất làm khóa chính, và mốc thời gian của chiều thứ hai làm khóa phụ.

### Di chuyển con trỏ

#### Quy trình

Dễ nghĩ tới cách đánh dấu các đỉnh đang được tính vào đáp án, cho con trỏ di chuyển thẳng tới mục tiêu, đồng thời đảo trạng thái các đỉnh trên đường đi.

Tuy nhiên cách này có một vấn đề. Nếu ban đầu cả hai con trỏ đều ở x, x được đánh dấu. Khi hai con trỏ cùng di chuyển tới một đỉnh con giống nhau, hoặc trong nhiều trường hợp tương tự, x lẽ ra không được đánh dấu, nhưng thực tế x vẫn bị đánh dấu, vì hai con trỏ mỗi bên đã đánh dấu một lần và triệt tiêu lẫn nhau.

Giải quyết thế nào?

Có một tính chất quan trọng: các đỉnh này thuộc nhóm LCA, vì chỉ tại LCA mới có khả năng bị hủy lặp lại khiến việc hủy thất bại.

Vì vậy mỗi lần không đánh dấu LCA ngay; chỉ khi cần trả lời truy vấn mới đánh dấu LCA, rồi hủy đánh dấu lại.

#### Cài đặt

```cpp
// Đảo trạng thái tất cả đỉnh trên đường đi, trừ LCA
void move(int x, int y) {
  if (dp[x] < dp[y]) swap(x, y);
  while (dp[x] > dp[y]) update(x), x = fa[x];
  while (x != y) update(x), update(y), x = fa[x], y = fa[y];
  // x!=y bảo đảm LCA không bị đảo trạng thái
}
```

Để tìm LCA, có thể dùng phân rã nặng nhẹ. Khi đó có thể đặt bước chia khối vào lần DFS đầu tiên của phân rã nặng nhẹ, còn mốc thời gian có thể trực tiếp dùng thứ tự DFS của lần DFS thứ hai.

```cpp
int bl[100002], bls = 0;  // Khối chứa đỉnh, số lượng khối
unsigned step;            // Kích thước khối
int fa[100002], dp[100002], hs[100002] = {0}, sz[100002] = {0};
// Cha, độ sâu, con nặng, kích thước
stack<int> sta;

void dfs1(int x) {
  sz[x] = 1;
  unsigned ss = sta.size();
  for (int i = head[x]; i; i = nxt[i])
    if (ver[i] != fa[x]) {
      fa[ver[i]] = x;
      dp[ver[i]] = dp[x] + 1;
      dfs1(ver[i]);
      sz[x] += sz[ver[i]];
      if (sz[ver[i]] > sz[hs[x]]) hs[x] = ver[i];
      if (sta.size() - ss >= step) {
        bls++;
        while (sta.size() != ss) bl[sta.top()] = bls, sta.pop();
      }
    }
  sta.push(x);
}

// main
if (!sta.empty()) {
  bls++;  // Dòng này có thể có hoặc không
  while (!sta.empty()) bl[sta.top()] = bls, sta.pop();
}
```

### Độ phức tạp thời gian

Tới phần quan trọng: cách chọn kích thước khối.

Giả sử kích thước khối là $unit$:

-   Với con trỏ x, do khoảng cách giữa các đỉnh trong mỗi khối vào khoảng $unit$, trong mỗi khối con trỏ x di chuyển $unit^2$ lần ($unit\times dis_{\max}$), tổng cộng $n\times unit$ lần ($unit^2 \times (\frac{n}{unit})$).
-   Với con trỏ y, trong mỗi khối nó di chuyển nhiều nhất $O(n)$ lần, tổng cộng $\frac{n^2}{unit}$ lần ($n \times (\frac{n}{unit})$).

Cộng hai phần lại, giá trị nhỏ nhất xấp xỉ đạt được tại căn bậc hai. Do kích thước khối trong thuật toán Mo trên cây không cố định, không nhất thiết phải theo đúng tuyệt đối.

### Ví dụ WC2013 Candy Park

Vì có thêm chiều thời gian, lấy kích thước khối khoảng $n^{0.6}$ là tương đối ổn.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cmath>
    #include <cstdio>
    #include <stack>
    using namespace std;
    
    int gi() {
      int x, c, op = 1;
      while (c = getchar(), c < '0' || c > '9')
        if (c == '-') op = -op;
      x = c ^ 48;
      while (c = getchar(), c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48);
      return x * op;
    }
    
    int head[100002], nxt[200004], ver[200004], tot = 0;
    
    void add(int x, int y) {
      ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
      ver[++tot] = x, nxt[tot] = head[y], head[y] = tot;
    }
    
    int bl[100002], bls = 0;
    unsigned step;
    int fa[100002], dp[100002], hs[100002] = {0}, sz[100002] = {0}, top[100002],
                                id[100002];
    stack<int> sta;
    
    void dfs1(int x) {
      sz[x] = 1;
      unsigned ss = sta.size();
      for (int i = head[x]; i; i = nxt[i])
        if (ver[i] != fa[x]) {
          fa[ver[i]] = x, dp[ver[i]] = dp[x] + 1;
          dfs1(ver[i]);
          sz[x] += sz[ver[i]];
          if (sz[ver[i]] > sz[hs[x]]) hs[x] = ver[i];
          if (sta.size() - ss >= step) {
            bls++;
            while (sta.size() != ss) bl[sta.top()] = bls, sta.pop();
          }
        }
      sta.push(x);
    }
    
    int cnt = 0;
    
    void dfs2(int x, int hf) {
      top[x] = hf, id[x] = ++cnt;
      if (!hs[x]) return;
      dfs2(hs[x], hf);
      for (int i = head[x]; i; i = nxt[i])
        if (ver[i] != fa[x] && ver[i] != hs[x]) dfs2(ver[i], ver[i]);
    }
    
    int lca(int x, int y) {
      while (top[x] != top[y]) {
        if (dp[top[x]] < dp[top[y]]) swap(x, y);
        x = fa[top[x]];
      }
      return dp[x] < dp[y] ? x : y;
    }
    
    struct qu {
      int x, y, t, id;
    
      bool operator<(const qu a) const {
        return bl[x] == bl[a.x] ? (bl[y] == bl[a.y] ? t < a.t : bl[y] < bl[a.y])
                                : bl[x] < bl[a.x];
      }
    } q[100001];
    
    int qs = 0;
    
    struct ch {
      int x, y, b;
    } upd[100001];
    
    int ups = 0;
    long long ans[100001];
    int b[100001] = {0};
    int a[100001];
    long long w[100001];
    long long v[100001];
    long long now = 0;
    bool vis[100001] = {false};
    
    void back(int t) {
      if (vis[upd[t].x]) {
        now -= w[b[upd[t].y]--] * v[upd[t].y];
        now += w[++b[upd[t].b]] * v[upd[t].b];
      }
      a[upd[t].x] = upd[t].b;
    }
    
    void change(int t) {
      if (vis[upd[t].x]) {
        now -= w[b[upd[t].b]--] * v[upd[t].b];
        now += w[++b[upd[t].y]] * v[upd[t].y];
      }
      a[upd[t].x] = upd[t].y;
    }
    
    void update(int x) {
      if (vis[x])
        now -= w[b[a[x]]--] * v[a[x]];
      else
        now += w[++b[a[x]]] * v[a[x]];
      vis[x] ^= 1;
    }
    
    void move(int x, int y) {
      if (dp[x] < dp[y]) swap(x, y);
      while (dp[x] > dp[y]) update(x), x = fa[x];
      while (x != y) update(x), update(y), x = fa[x], y = fa[y];
    }
    
    int main() {
      int n = gi(), m = gi(), k = gi();
      step = (int)pow(n, 0.6);
      for (int i = 1; i <= m; i++) v[i] = gi();
      for (int i = 1; i <= n; i++) w[i] = gi();
      for (int i = 1; i < n; i++) add(gi(), gi());
      for (int i = 1; i <= n; i++) a[i] = gi();
      for (int i = 1; i <= k; i++)
        if (gi())
          q[++qs].x = gi(), q[qs].y = gi(), q[qs].t = ups, q[qs].id = qs;
        else
          upd[++ups].x = gi(), upd[ups].y = gi();
      for (int i = 1; i <= ups; i++) upd[i].b = a[upd[i].x], a[upd[i].x] = upd[i].y;
      for (int i = ups; i; i--) back(i);
      fa[1] = 1;
      dfs1(1), dfs2(1, 1);
      if (!sta.empty()) {
        bls++;
        while (!sta.empty()) bl[sta.top()] = bls, sta.pop();
      }
      for (int i = 1; i <= n; i++)
        if (id[q[i].x] > id[q[i].y]) swap(q[i].x, q[i].y);
      sort(q + 1, q + qs + 1);
      int x = 1, y = 1, t = 0;
      for (int i = 1; i <= qs; i++) {
        if (x != q[i].x) move(x, q[i].x), x = q[i].x;
        if (y != q[i].y) move(y, q[i].y), y = q[i].y;
        int f = lca(x, y);
        update(f);
        while (t < q[i].t) change(++t);
        while (t > q[i].t) back(t--);
        ans[q[i].id] = now;
        update(f);
      }
      for (int i = 1; i <= qs; i++) printf("%lld\n", ans[i]);
      return 0;
    }
    ```
