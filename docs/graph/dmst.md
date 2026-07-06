## Định nghĩa

Cây khung nhỏ nhất trên đồ thị có hướng được gọi là arborescence nhỏ nhất.

Thuật toán thường dùng là thuật toán Chu-Liu (còn gọi là thuật toán Edmonds), giải bài toán arborescence nhỏ nhất trong thời gian $O(nm)$.

## Quy trình

1.  Với mỗi đỉnh, chọn cạnh đi vào nó có trọng số nhỏ nhất.
2.  Nếu không có chu trình, thuật toán kết thúc; nếu có, co chu trình lại và cập nhật khoảng cách từ các đỉnh khác tới chu trình.

## Cài đặt

```cpp
bool solve() {
  ans = 0;
  int u, v, root = 0;
  for (;;) {
    f(i, 0, n) in[i] = 1e100;
    f(i, 0, m) {
      u = e[i].s;
      v = e[i].t;
      if (u != v && e[i].w < in[v]) {
        in[v] = e[i].w;
        pre[v] = u;
      }
    }
    f(i, 0, m) if (i != root && in[i] > 1e50) return 0;
    int tn = 0;
    memset(id, -1, sizeof id);
    memset(vis, -1, sizeof vis);
    in[root] = 0;
    f(i, 0, n) {
      ans += in[i];
      v = i;
      while (vis[v] != i && id[v] == -1 && v != root) {
        vis[v] = i;
        v = pre[v];
      }
      if (v != root && id[v] == -1) {
        for (int u = pre[v]; u != v; u = pre[u]) id[u] = tn;
        id[v] = tn++;
      }
    }
    if (tn == 0) break;
    f(i, 0, n) if (id[i] == -1) id[i] = tn++;
    f(i, 0, m) {
      u = e[i].s;
      v = e[i].t;
      e[i].s = id[u];
      e[i].t = id[v];
      if (e[i].s != e[i].t) e[i].w -= in[v];
    }
    n = tn;
    root = id[root];
  }
  return ans;
}
```

## Thuật toán DMST của Tarjan

Tarjan đề xuất một thuật toán giải bài toán arborescence nhỏ nhất trong thời gian $O(m+n\log n)$.

Phần mô tả thuật toán và mã tham khảo trong mục này dựa trên bài giảng của Giáo sư Uri Zwick; có thể xem tài liệu gốc để biết thêm chi tiết.

### Quy trình

Thuật toán của Tarjan gồm hai giai đoạn: **co** và **mở rộng**. Trước hết xét giai đoạn **co**.

Cần giả sử đồ thị đầu vào là liên thông mạnh. Nếu không, thêm $O(n)$ cạnh có trọng số vô cùng lớn để đồ thị thỏa điều kiện này.

Cần một heap để lưu các thông tin như chỉ số cạnh vào của đỉnh, trọng số cạnh vào và tổng chi phí của đỉnh. Vì các bước sau cần thao tác gộp heap, phần này dùng [cây lệch trái](../ds/leftist-tree.md) và [DSU](../ds/dsu.md) để cài đặt. Ở mỗi bước của thuật toán, chọn một đỉnh tùy ý $v$ sao cho $v$ không phải là đỉnh gốc và cạnh vào của nó chưa nằm trong heap. Sau đó đưa cạnh vào nhỏ nhất của $v$ vào heap. Nếu cạnh mới thêm khiến các cạnh trong heap tạo thành một chu trình, co các đỉnh thuộc chu trình đó lại; các đỉnh đã được co như vậy được gọi là **siêu đỉnh**. Tiếp tục quá trình này, và khi toàn bộ các đỉnh đã được co thành một siêu đỉnh, giai đoạn co kết thúc. Sau toàn bộ giai đoạn co, thu được một cây co, rồi sẽ thực hiện thao tác mở rộng trên cây đó.

Các cạnh trong heap luôn tạo thành một đường đi $v_0\leftarrow v_1\leftarrow \dots\leftarrow v_k$. Vì đồ thị liên thông mạnh, đường đi này chắc chắn tồn tại; mỗi $v_i$ có thể là một đỉnh đơn ban đầu hoặc một siêu đỉnh sau khi co.

Ban đầu có $v_o=a$, trong đó $a$ là một đỉnh bất kỳ trong đồ thị. Mỗi lần chọn một cạnh vào nhỏ nhất $v_k\leftarrow u$. Nếu $u$ không phải một trong các đỉnh $v_0,v_1,\dots,v_k$, mở rộng đường đi tới $v_{k+1}=u$. Nếu $u$ là một đỉnh $v_i$ trong số đó, đã tìm được chu trình $v_i\leftarrow\dots\leftarrow v_k\leftarrow v_i$, rồi co các đỉnh này thành một siêu đỉnh $c$.

Đưa tất cả các đỉnh hoặc siêu đỉnh vào hàng đợi $P$, đồng thời ban đầu chọn một đỉnh tùy ý $a$. Chừng nào hàng đợi còn chưa rỗng, thực hiện các bước sau:

1.  Chọn cạnh vào nhỏ nhất của $a$, bảo đảm không có khuyên, rồi tìm đỉnh $b$ ở đầu còn lại. Nếu đỉnh $b$ chưa từng được ghi nhận, nghĩa là chưa hình thành chu trình; đặt $a\leftarrow b$ và tiếp tục thao tác hiện tại để tìm chu trình.

2.  Nếu $b$ đã được ghi nhận, nghĩa là đã xuất hiện chu trình. Tăng tổng số đỉnh lên một, đánh số lại mọi đỉnh trên chu trình, gộp các heap, đồng thời cập nhật tổng trọng số của các đỉnh hoặc siêu đỉnh. Thao tác cập nhật trọng số là gom tất cả cạnh vào của các đỉnh trên chu trình và trừ đi trọng số của cạnh vào tương ứng trên chu trình.

![Co chu trình trong đồ thị thành cây co](./images/dmst1.png)

Trong hình minh họa, đồ thị liên thông mạnh bên trái sau khi co sẽ tạo thành cây co ở bên phải. Trong đó, $a$ là siêu đỉnh thu được sau khi co đỉnh 1 và đỉnh 2; $b$ là siêu đỉnh thu được sau khi co đỉnh 3, đỉnh 4 và đỉnh 5; còn $A$ được tạo thành sau khi co hai siêu đỉnh $a$ và $b$.

Giai đoạn mở rộng tương đối đơn giản. Bắt đầu từ đỉnh gốc $r$ được yêu cầu ban đầu, mở rộng từng chu trình trên đường từ $r$ tới gốc của cây co. Sau đó bắt đầu từ đỉnh tổ tiên $f_r$ của $r$, mở rộng các chu trình từ đó tới gốc, cho tới khi duyệt xong mọi đỉnh.

### Cài đặt

```cpp
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;
constexpr int MAXN = 102;
constexpr int INF = 0x3f3f3f3f;

struct UnionFind {
  int fa[MAXN << 1];

  UnionFind() { memset(fa, 0, sizeof(fa)); }

  void clear(int n) { memset(fa + 1, 0, sizeof(int) * n); }

  int find(int x) { return fa[x] ? fa[x] = find(fa[x]) : x; }

  int operator[](int x) { return find(x); }
};

struct Edge {
  int u, v, w, w0;
};

struct Heap {
  Edge *e;
  int rk, constant;
  Heap *lch, *rch;

  Heap(Edge *_e) : e(_e), rk(1), constant(0), lch(NULL), rch(NULL) {}

  void push() {
    if (lch) lch->constant += constant;
    if (rch) rch->constant += constant;
    e->w += constant;
    constant = 0;
  }
};

Heap *merge(Heap *x, Heap *y) {
  if (!x) return y;
  if (!y) return x;
  if (x->e->w + x->constant > y->e->w + y->constant) swap(x, y);
  x->push();
  x->rch = merge(x->rch, y);
  if (!x->lch || x->lch->rk < x->rch->rk) swap(x->lch, x->rch);
  if (x->rch)
    x->rk = x->rch->rk + 1;
  else
    x->rk = 1;
  return x;
}

Edge *extract(Heap *&x) {
  Edge *r = x->e;
  x->push();
  x = merge(x->lch, x->rch);
  return r;
}

vector<Edge> in[MAXN];
int n, m, fa[MAXN << 1], nxt[MAXN << 1];
Edge *ed[MAXN << 1];
Heap *Q[MAXN << 1];
UnionFind id;

void contract() {
  bool mark[MAXN << 1];
  // Ghi nhận các cạnh nối với từng đỉnh trong đồ thị.
  for (int i = 1; i <= n; i++) {
    queue<Heap *> q;
    for (int j = 0; j < in[i].size(); j++) q.push(new Heap(&in[i][j]));
    while (q.size() > 1) {
      Heap *u = q.front();
      q.pop();
      Heap *v = q.front();
      q.pop();
      q.push(merge(u, v));
    }
    Q[i] = q.front();
  }
  mark[1] = true;
  for (int a = 1, b = 1, p; Q[a]; b = a, mark[b] = true) {
    // Tìm cạnh vào nhỏ nhất và đầu mút của nó, đồng thời tránh tạo khuyên.
    do {
      ed[a] = extract(Q[a]);
      a = id[ed[a]->u];
    } while (a == b && Q[a]);
    if (a == b) break;
    if (!mark[a]) continue;
    // Co chu trình vừa tìm được, đánh số lại các đỉnh trong chu trình và cập nhật tổng trọng số.
    for (a = b, n++; a != n; a = p) {
      id.fa[a] = fa[a] = n;
      if (Q[a]) Q[a]->constant -= ed[a]->w;
      Q[n] = merge(Q[n], Q[a]);
      p = id[ed[a]->u];
      nxt[p == n ? b : p] = a;
    }
  }
}

ll expand(int x, int r);

ll expand_iter(int x) {
  ll r = 0;
  for (int u = nxt[x]; u != x; u = nxt[u]) {
    if (ed[u]->w0 >= INF)
      return INF;
    else
      r += expand(ed[u]->v, u) + ed[u]->w0;
  }
  return r;
}

ll expand(int x, int t) {
  ll r = 0;
  for (; x != t; x = fa[x]) {
    r += expand_iter(x);
    if (r >= INF) return INF;
  }
  return r;
}

void link(int u, int v, int w) { in[v].push_back({u, v, w, w}); }

int main() {
  int rt;
  scanf("%d %d %d", &n, &m, &rt);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    link(u, v, w);
  }
  // Bảo đảm đồ thị liên thông mạnh.
  for (int i = 1; i <= n; i++) link(i > 1 ? i - 1 : n, i, INF);
  contract();
  ll ans = expand(rt, n);
  if (ans >= INF)
    puts("-1");
  else
    printf("%lld\n", ans);
  return 0;
}
```

## Tài liệu tham khảo

Uri Zwick. (2013),[Directed Minimum Spanning Trees](http://www.cs.tau.ac.il/~zwick/grad-algo-13/directed-mst.pdf), Lecture notes on "Analysis of Algorithms"

<https://riteme.site/blog/2018-6-18/mdst.html#_3>
