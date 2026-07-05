author: Backl1ght, Tiphereth-A, Enter-tainer, Ir1d, ksyx, leoleoasd, Xeonacid, aaron20100919

## Giới thiệu

Phân khối lồng cây Fenwick có thể dùng để làm một số việc mà cây lồng cây làm được trong những điều kiện nhất định. Tuy nhiên, so với cây lồng cây, mã của phân khối lồng cây Fenwick ngắn hơn và dễ cài đặt hơn.

## Ví dụ đơn giản

Một ví dụ đơn giản là truy vấn số điểm trong một vùng ma trận trên mặt phẳng hai chiều.

???+ note "Truy vấn vùng chữ nhật"
    Cho $n$ điểm $(x_i, y_i)$ trên mặt phẳng hai chiều, trong đó $1 \le i \le n, 1 \le x_i, y_i \le n, 1 \le n \le 10^5$. Cần thực hiện các thao tác sau:
    
    1.  Cho $a, b, c, d$, hỏi số điểm trong vùng chữ nhật có góc trên trái là $(a, b)$ và góc dưới phải là $(c, d)$.
    2.  Cho $x, y$, đổi tung độ của điểm có hoành độ $x$ thành $y$.
    
    Bài toán **bắt buộc xử lý trực tuyến**, và bảo đảm $x_i \ne x_j(1 \le i, j \le n, i \ne j)$.

Với thao tác 1, ta có thể dùng bao hàm - loại trừ trên hình chữ nhật để chuyển nó thành 4 truy vấn thứ tự bộ phận hai chiều. Vì bài toán bắt buộc xử lý trực tuyến, các thuật toán ngoại tuyến như chia để trị CDQ không áp dụng được, nên ta nghĩ đến cây lồng cây, chẳng hạn cây Fenwick lồng Treap. Cách này thật sự giải được bài toán, nhưng mã khá dài và không quá dễ cài đặt.

Chú ý rằng bài toán còn bảo đảm thêm $x_i \ne x_j(1 \le i, j \le n, i \ne j)$, khi đó có thể dùng phân khối lồng cây Fenwick để giải.

### Khởi tạo

Trước hết, mỗi $x$ chỉ tương ứng với một $y$, nên có thể dùng một mảng để ghi lại ánh xạ này. Chẳng hạn, đặt $Y_i$ là tung độ của điểm có hoành độ $i$.

Sau đó, phân khối các hoành độ với kích thước khối là $\sqrt n$. Với mỗi khối, xây một cây Fenwick trên miền giá trị. Kí hiệu $T_i$ là cây Fenwick tương ứng với khối thứ $i$, và $T_{i, j}$ là số điểm trong khối $i$ có tung độ thuộc $(j - lowbit(j), j]$.

### Truy vấn

Với thao tác 1, chuyển nó thành 4 truy vấn thứ tự bộ phận hai chiều. Bây giờ chỉ cần giải bài toán: cho $a, b$, hỏi có bao nhiêu điểm thỏa mãn $1 \le x_i \le a, 1\le y_i \le b$.

Ta cần truy vấn phạm vi hoành độ $[1, a]$. Vì ở mép phải của phạm vi truy vấn có thể có một đoạn không phải là khối hoàn chỉnh, ta duyệt trực tiếp đoạn này, kiểm tra điều kiện $Y_i \le b$, rồi đếm số điểm thỏa mãn trong đoạn đó.

Bây giờ chỉ còn cần xử lý các khối hoàn chỉnh. Duyệt trực tiếp các khối phía trước, truy vấn trong cây Fenwick tương ứng với mỗi khối số giá trị nhỏ hơn $b$, rồi cộng dồn vào đáp án.

Như vậy là xong chưa? Chưa. Chú ý rằng khi xử lý các khối hoàn chỉnh, thực chất ta đang truy vấn tổng tiền tố của $T$. Nếu khi cập nhật cũng dùng kĩ thuật cây Fenwick để xử lý $T$, độ phức tạp truy vấn sẽ thấp hơn.

### Cập nhật

Cách thông thường là trước hết tìm khối chứa điểm $x$, sau đó thực hiện hai cập nhật điểm trên cây Fenwick theo miền giá trị, một lần trừ và một lần cộng, rồi đặt $Y_x$ thành $y$.

Nếu dùng tối ưu nói trên, ta cũng thực hiện quy trình cập nhật kiểu cây Fenwick trên $T$. Mỗi lần cập nhật vẫn là hai cập nhật điểm trên cây Fenwick theo miền giá trị, một lần trừ và một lần cộng.

Thay đổi nhẹ các bước trên sẽ cho các thao tác khác. Ví dụ, đổi từ một lần trừ và một lần cộng thành chỉ trừ thì đó là xóa điểm; đổi thành chỉ cộng thì đó là thêm điểm. Tuy nhiên, cần chú ý rằng mỗi $x$ chỉ được tương ứng với một $y$.

### Độ phức tạp không gian

Phân khối tạo ra $\sqrt n$ khối, mỗi khối có một cây Fenwick dùng $O(n)$ không gian, nên độ phức tạp không gian là $O(n \sqrt n)$.

### Độ phức tạp thời gian

Khi truy vấn, việc duyệt đoạn thuộc khối không hoàn chỉnh tốn $O(\sqrt n)$. Sau đó, thực hiện truy vấn cây Fenwick trên $T$; với mỗi $T_i$ đi qua, lại thực hiện một truy vấn cây Fenwick, bước này có độ phức tạp $O(\log (\sqrt n) \log n)$. Vì vậy độ phức tạp thời gian của truy vấn là $O (\sqrt n + \log (\sqrt n) \log n)$.

Cập nhật có độ phức tạp giống truy vấn, là $O (\sqrt n + \log (\sqrt n) \log n)$.

## Ví dụ 1

???+ note "[Intersection of Permutations](https://codeforces.com/problemset/problem/1093/E)"
    Cho hai hoán vị $a$ và $b$, cần thực hiện hai loại thao tác sau:
    
    1.  Cho $l_a, r_a, l_b, r_b$, cần truy vấn số phần tử vừa xuất hiện trong $a[l_a ... r_a]$ vừa xuất hiện trong $b[l_b ... r_b]$.
    2.  Cho $x, y$, thực hiện $swap(b_x, b_y)$.
    
    Độ dài dãy $n$ thỏa mãn $2 \le n \le 2 \cdot 10^5$, số thao tác $q$ thỏa mãn $1 \le q \le 2 \cdot 10^5$.

Với mỗi giá trị $i$, kí hiệu $x_i$ là chỉ số của nó trong hoán vị $b$, và $y_i$ là chỉ số của nó trong hoán vị $a$. Khi đó, thao tác 1 trở thành một truy vấn số điểm trong vùng chữ nhật, còn thao tác 2 có thể xem là hai thao tác cập nhật. Hơn nữa, vì đây là hoán vị nên điều kiện mỗi $x$ tương ứng với một $y$ được thỏa mãn, do đó bài này có thể viết bằng phân khối lồng cây Fenwick.

??? note "Mã tham khảo (phân khối lồng cây Fenwick - 1s)"
    ```cpp
    #include <cmath>
    #include <cstdio>
    using namespace std;
    constexpr int N = 2e5 + 5;
    constexpr int M = 447 + 5;  // sqrt(N) + 5
    
    int n, m, pa[N], pb[N];
    
    int nn, block_size, block_cnt, block_id[N], L[N], R[N], T[M][N];
    
    void build(int n) {
      nn = n;
      block_size = sqrt(nn);
      block_cnt = nn / block_size;
      for (int i = 1; i <= block_cnt; ++i) {
        L[i] = R[i - 1] + 1;
        R[i] = i * block_size;
      }
      if (R[block_cnt] < nn) {
        ++block_cnt;
        L[block_cnt] = R[block_cnt - 1] + 1;
        R[block_cnt] = nn;
      }
      for (int j = 1; j <= block_cnt; ++j)
        for (int i = L[j]; i <= R[j]; ++i) block_id[i] = j;
    }
    
    int lb(int x) { return x & -x; }
    
    void add(int p, int v, int d) {
      for (int i = block_id[p]; i <= block_cnt; i += lb(i))
        for (int j = v; j <= nn; j += lb(j)) T[i][j] += d;
    }
    
    int getsum(int p, int v) {
      if (!p) return 0;
      int res = 0;
      int id = block_id[p];
      for (int i = L[id]; i <= p; ++i)
        if (pb[i] <= v) ++res;
      for (int i = id - 1; i; i -= lb(i))
        for (int j = v; j; j -= lb(j)) res += T[i][j];
      return res;
    }
    
    void update(int x, int y) {
      add(x, pb[x], -1);
      add(y, pb[y], -1);
      swap(pb[x], pb[y]);
      add(x, pb[x], 1);
      add(y, pb[y], 1);
    }
    
    int query(int la, int ra, int lb, int rb) {
      int res = getsum(rb, ra) - getsum(rb, la - 1) - getsum(lb - 1, ra) +
                getsum(lb - 1, la - 1);
      return res;
    }
    
    int main() {
      scanf("%d %d", &n, &m);
      int v;
      for (int i = 1; i <= n; ++i) scanf("%d", &v), pa[v] = i;
      for (int i = 1; i <= n; ++i) scanf("%d", &v), pb[i] = pa[v];
    
      build(n);
      for (int i = 1; i <= n; ++i) add(i, pb[i], 1);
    
      int op, la, lb, ra, rb, x, y;
      for (int i = 1; i <= m; ++i) {
        scanf("%d", &op);
        if (op == 1) {
          scanf("%d %d %d %d", &la, &ra, &lb, &rb);
          printf("%d\n", query(la, ra, lb, rb));
        } else if (op == 2) {
          scanf("%d %d", &x, &y);
          update(x, y);
        }
      }
      return 0;
    }
    ```

??? note "Mã tham khảo (cây Fenwick lồng Treap - TLE)"
    ```cpp
    #include <cstdio>
    #include <random>
    using namespace std;
    constexpr int N = 2e5 + 5;
    mt19937 rng(random_device{}());
    
    int n, m, pa[N], pb[N];
    
    // Treap
    struct Treap {
      struct node {
        node *l, *r;
        int sz, rnd, v;
    
        node(int _v) : l(NULL), r(NULL), sz(1), rnd(rng()), v(_v) {}
      };
    
      int get_size(node*& p) { return p ? p->sz : 0; }
    
      void push_up(node*& p) {
        if (!p) return;
        p->sz = get_size(p->l) + get_size(p->r) + 1;
      }
    
      node* root;
    
      node* merge(node* a, node* b) {
        if (!a) return b;
        if (!b) return a;
        if (a->rnd < b->rnd) {
          a->r = merge(a->r, b);
          push_up(a);
          return a;
        } else {
          b->l = merge(a, b->l);
          push_up(b);
          return b;
        }
      }
    
      void split_val(node* p, const int& k, node*& a, node*& b) {
        if (!p)
          a = b = NULL;
        else {
          if (p->v <= k) {
            a = p;
            split_val(p->r, k, a->r, b);
            push_up(a);
          } else {
            b = p;
            split_val(p->l, k, a, b->l);
            push_up(b);
          }
        }
      }
    
      void split_size(node* p, int k, node*& a, node*& b) {
        if (!p)
          a = b = NULL;
        else {
          if (get_size(p->l) <= k) {
            a = p;
            split_size(p->r, k - get_size(p->l), a->r, b);
            push_up(a);
          } else {
            b = p;
            split_size(p->l, k, a, b->l);
            push_up(b);
          }
        }
      }
    
      void ins(int val) {
        node *a, *b;
        split_val(root, val, a, b);
        a = merge(a, new node(val));
        root = merge(a, b);
      }
    
      void del(int val) {
        node *a, *b, *c, *d;
        split_val(root, val, a, b);
        split_val(a, val - 1, c, d);
        delete d;
        root = merge(c, b);
      }
    
      int qry(int val) {
        node *a, *b;
        split_val(root, val, a, b);
        int res = get_size(a);
        root = merge(a, b);
        return res;
      }
    
      int qry(int l, int r) { return qry(r) - qry(l - 1); }
    };
    
    // Fenwick Tree
    Treap T[N];
    
    int lb(int x) { return x & -x; }
    
    void ins(int x, int v) {
      for (; x <= n; x += lb(x)) T[x].ins(v);
    }
    
    void del(int x, int v) {
      for (; x <= n; x += lb(x)) T[x].del(v);
    }
    
    int qry(int x, int mi, int ma) {
      int res = 0;
      for (; x; x -= lb(x)) res += T[x].qry(mi, ma);
      return res;
    }
    
    int main() {
      scanf("%d %d", &n, &m);
      int v;
      for (int i = 1; i <= n; ++i) scanf("%d", &v), pa[v] = i;
      for (int i = 1; i <= n; ++i) scanf("%d", &v), pb[i] = pa[v];
      for (int i = 1; i <= n; ++i) ins(i, pb[i]);
    
      int op, la, lb, ra, rb, x, y;
      for (int i = 1; i <= m; ++i) {
        scanf("%d", &op);
        if (op == 1) {
          scanf("%d %d %d %d", &la, &ra, &lb, &rb);
          printf("%d\n", qry(rb, la, ra) - qry(lb - 1, la, ra));
        } else if (op == 2) {
          scanf("%d %d", &x, &y);
          del(x, pb[x]);
          del(y, pb[y]);
          swap(pb[x], pb[y]);
          ins(x, pb[x]);
          ins(y, pb[y]);
        }
      }
      return 0;
    }
    ```

## Ví dụ 2

???+ note "[Complicated Computations](https://codeforces.com/contest/1436/problem/E)"
    Cho một dãy $a$. Lấy tất cả MEX của mọi dãy con liên tiếp của $a$ để tạo thành mảng $b$, hỏi MEX của $b$. MEX của một dãy là **số nguyên dương** nhỏ nhất chưa xuất hiện trong dãy đó.
    
    Độ dài dãy $n$ thỏa mãn $1 \le n \le 10^5$.

**Nhận xét**: MEX của một dãy là $mex$ khi và chỉ khi dãy đó chứa các số từ $1$ đến $mex-1$, nhưng không chứa $mex$.

Lần lượt kiểm tra có tồn tại dãy con liên tiếp có MEX bằng từng giá trị từ $1$ đến $n+1$ hay không. Nếu không có dãy con liên tiếp nào có MEX bằng $i$, thì đáp án là $i$. Nếu tất cả đều tồn tại, đáp án là $n + 2$.

Khi kiểm tra $i$, xem dãy như nhiều đoạn được ngăn cách bởi không hoặc nhiều phần tử có giá trị $i$. Nếu tồn tại một đoạn chứa các giá trị từ $1$ đến $i - 1$ nhưng không chứa $i$, thì tồn tại một dãy con liên tiếp có MEX bằng $i$.

Dùng một mảng $Y_j$ để ghi lại vị trí của phần tử gần nhất trước đó có giá trị bằng $a_j$. Lấy $j$ làm $x$, $Y_j$ làm $y$, và $a_j$ làm $z$. Khi đó, tính xem trong đoạn có chứa các giá trị từ $1$ đến $i - 1$ hay không trở thành một bài toán thứ tự bộ phận ba chiều. Nói chính thức, để kiểm tra MEX của đoạn $[l, r]$ có bằng $i$ hay không, ta xem số điểm thỏa mãn $l \le j \le r, Y_j \le l - 1, a_j \le i - 1$ có bằng $i-1$ hay không.

Nếu sau khi kiểm tra xong các phần tử có giá trị $i$ mới chèn các điểm tương ứng, thì lúc này trong $[l, r]$ chỉ tồn tại các phần tử có $a_j \le i - 1$. Vì vậy bài toán thứ tự bộ phận ba chiều ở trên có thể chuyển thành bài toán thứ tự bộ phận hai chiều.

??? note "Mã tham khảo (phân khối lồng cây Fenwick - 78ms)"
    ```cpp
    #include <cmath>
    #include <cstdio>
    #include <vector>
    using namespace std;
    constexpr int N = 1e5 + 5;
    constexpr int M = 316 + 5;  // sqrt(N) + 5
    
    // Phân khối
    int nn, b[N], block_size, block_cnt, block_id[N], L[N], R[N], T[M][N];
    
    void build(int n) {
      nn = n;
      block_size = sqrt(nn);
      block_cnt = nn / block_size;
      for (int i = 1; i <= block_cnt; ++i) {
        L[i] = R[i - 1] + 1;
        R[i] = i * block_size;
      }
      if (R[block_cnt] < nn) {
        ++block_cnt;
        L[block_cnt] = R[block_cnt - 1] + 1;
        R[block_cnt] = nn;
      }
      for (int j = 1; j <= block_cnt; ++j)
        for (int i = L[j]; i <= R[j]; ++i) block_id[i] = j;
    }
    
    int lb(int x) { return x & -x; }
    
    // d = 1: thêm điểm (p, v)
    // d = -1: xóa điểm (p, v)
    void add(int p, int v, int d) {
      for (int i = block_id[p]; i <= block_cnt; i += lb(i))
        for (int j = v; j <= nn; j += lb(j)) T[i][j] += d;
    }
    
    // Hỏi trong [1, r] có bao nhiêu điểm có tung độ không vượt quá val
    int getsum(int p, int v) {
      if (!p) return 0;
      int res = 0;
      int id = block_id[p];
      for (int i = L[id]; i <= p; ++i)
        if (b[i] && b[i] <= v) ++res;
      for (int i = id - 1; i; i -= lb(i))
        for (int j = v; j; j -= lb(j)) res += T[i][j];
      return res;
    }
    
    // Hỏi trong [l, r] có bao nhiêu điểm có tung độ không vượt quá val
    int query(int l, int r, int val) {
      if (l > r) return -1;
      int res = getsum(r, val) - getsum(l - 1, val);
      return res;
    }
    
    // Thêm điểm (p, v)
    void update(int p, int v) {
      b[p] = v;
      add(p, v, 1);
    }
    
    int n, a[N];
    vector<int> g[N];
    
    int main() {
      scanf("%d", &n);
    
      // Để giảm các trường hợp cần xét, thêm các nút lính canh
      // Vì khi thêm vào cây Fenwick, giá trị 0 có thể gây vòng lặp vô hạn, nên dịch toàn bộ sang phải một vị trí
      // a_1 và a_{n+2} là các nút lính canh
      for (int i = 2; i <= n + 1; ++i) scanf("%d", &a[i]);
      for (int i = 2; i <= n + 1; ++i) g[a[i]].push_back(i);
    
      // Phân khối
      build(n + 2);
    
      int ans = n + 2, lst, ok;
      for (int i = 1; i <= n + 1; ++i) {
        g[i].push_back(n + 2);
    
        lst = 1;
        ok = 0;
        for (int pos : g[i]) {
          if (query(lst + 1, pos - 1, lst) == i - 1) {
            ok = 1;
            break;
          }
          lst = pos;
        }
    
        if (!ok) {
          ans = i;
          break;
        }
    
        lst = 1;
        g[i].pop_back();
        for (int pos : g[i]) {
          update(pos, lst);
          lst = pos;
        }
      }
      printf("%d\n", ans);
      return 0;
    }
    ```

??? note "Mã tham khảo (cây đoạn lồng Treap - 468ms)"
    ```cpp
    #include <cstdio>
    #include <random>
    #include <vector>
    using namespace std;
    constexpr int N = 1e5 + 5;
    
    vector<int> g[N];
    int n, a[N];
    
    mt19937 rng(random_device{}());
    
    struct Treap {
      struct node {
        node *l, *r;
        unsigned rnd;
        int sz, v;
    
        node(int _v) : l(NULL), r(NULL), rnd(rng()), sz(1), v(_v) {}
      };
    
      int get_size(node*& p) { return p ? p->sz : 0; }
    
      void push_up(node*& p) {
        if (!p) return;
        p->sz = get_size(p->l) + get_size(p->r) + 1;
      }
    
      node* root;
    
      node* merge(node* a, node* b) {
        if (!a) return b;
        if (!b) return a;
        if (a->rnd < b->rnd) {
          a->r = merge(a->r, b);
          push_up(a);
          return a;
        } else {
          b->l = merge(a, b->l);
          push_up(b);
          return b;
        }
      }
    
      void split_val(node* p, const int& k, node*& a, node*& b) {
        if (!p)
          a = b = NULL;
        else {
          if (p->v <= k) {
            a = p;
            split_val(p->r, k, a->r, b);
            push_up(a);
          } else {
            b = p;
            split_val(p->l, k, a, b->l);
            push_up(b);
          }
        }
      }
    
      void split_size(node* p, int k, node*& a, node*& b) {
        if (!p)
          a = b = NULL;
        else {
          if (get_size(p->l) <= k) {
            a = p;
            split_size(p->r, k - get_size(p->l), a->r, b);
            push_up(a);
          } else {
            b = p;
            split_size(p->l, k, a, b->l);
            push_up(b);
          }
        }
      }
    
      void insert(int val) {
        node *a, *b;
        split_val(root, val, a, b);
        a = merge(a, new node(val));
        root = merge(a, b);
      }
    
      int query(int val) {
        node *a, *b;
        split_val(root, val, a, b);
        int res = get_size(a);
        root = merge(a, b);
        return res;
      }
    
      int qry(int l, int r) { return query(r) - query(l - 1); }
    };
    
    // Segment Tree
    Treap T[N << 2];
    
    void insert(int x, int l, int r, int p, int val) {
      T[x].insert(val);
      if (l == r) return;
      int mid = (l + r) >> 1;
      if (p <= mid)
        insert(x << 1, l, mid, p, val);
      else
        insert(x << 1 | 1, mid + 1, r, p, val);
    }
    
    int query(int x, int l, int r, int L, int R, int val) {
      if (l == L && r == R) return T[x].query(val);
      int mid = (l + r) >> 1;
      if (R <= mid) return query(x << 1, l, mid, L, R, val);
      if (L > mid) return query(x << 1 | 1, mid + 1, r, L, R, val);
      return query(x << 1, l, mid, L, mid, val) +
             query(x << 1 | 1, mid + 1, r, mid + 1, R, val);
    }
    
    int query(int l, int r, int val) {
      if (l > r) return -1;
      return query(1, 1, n, l, r, val);
    }
    
    int main() {
      scanf("%d", &n);
      for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
      for (int i = 1; i <= n; ++i) g[a[i]].push_back(i);
    
      // a_0 và a_{n+1} là các nút lính canh
      int ans = n + 2, lst, ok;
      for (int i = 1; i <= n + 1; ++i) {
        g[i].push_back(n + 1);
    
        lst = 0;
        ok = 0;
        for (int pos : g[i]) {
          if (query(lst + 1, pos - 1, lst) == i - 1) {
            ok = 1;
            break;
          }
          lst = pos;
        }
    
        if (!ok) {
          ans = i;
          break;
        }
    
        lst = 0;
        g[i].pop_back();
        for (int pos : g[i]) {
          insert(1, 1, n, pos, lst);
          lst = pos;
        }
      }
      printf("%d\n", ans);
      return 0;
    }
    ```
