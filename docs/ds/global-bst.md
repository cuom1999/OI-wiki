## Giới thiệu

Kiến thức nền: [Phân rã nặng-nhẹ](../graph/hld.md)

Độ phức tạp thời gian của phân rã nặng-nhẹ là $O(n\log^2 n)$.
LCT quen thuộc tuy có độ phức tạp thời gian $O(n\log n)$,
nhưng hằng số khá lớn, có thể còn chậm hơn phân rã nặng-nhẹ.
Một lựa chọn vừa đạt $O(n\log n)$ vừa có hằng số tương đối nhỏ
là cây nhị phân cân bằng toàn cục.

Cây nhị phân cân bằng toàn cục thực chất là một rừng cây nhị phân,
trong đó mỗi cây nhị phân duy trì một chuỗi nặng.
Các cây nhị phân trong rừng này vẫn có liên hệ với nhau:
gốc của mỗi cây nhị phân nối tới cha của đỉnh đầu chuỗi nặng tương ứng,
giống như trong LCT.
Tuy nhiên, cây nhị phân cân bằng toàn cục là cây tĩnh;
khác với LCT, sau khi xây xong thì hình dạng cây không thay đổi.

Cây nhị phân cân bằng toàn cục là một cấu trúc dữ liệu có thể xử lý cập nhật/truy vấn trên đường đi trong cây, đạt được:

-   $O(\log n)$ cho cập nhật toàn bộ một đường.
-   $O(\log n)$ cho truy vấn toàn bộ một đường.
-   $O(\log n)$ cho tìm tổ tiên chung gần nhất, cập nhật cây con, truy vấn cây con, v.v.; các độ phức tạp này giống với phân rã chuỗi nặng.

## Tính chất chính

1.  Cây nhị phân cân bằng toàn cục được tạo thành từ nhiều cây nhị phân
    nối với nhau bằng cạnh nhẹ.
    Mỗi cây nhị phân duy trì một chuỗi nặng của cây gốc,
    trong đó thứ tự duyệt trung thứ tự chính là thứ tự độ sâu tăng đơn điệu trên chuỗi nặng này.
    Mỗi đỉnh chỉ xuất hiện trong đúng một cây nhị phân.
2.  Các cạnh được chia thành cạnh nặng và cạnh nhẹ.
    Cạnh nặng là cạnh nằm trong cây nhị phân;
    khi duy trì thì giống như duy trì cây nhị phân thông thường,
    ghi lại con trái, con phải và đỉnh cha.
    Cạnh nhẹ đi từ gốc của một cây nhị phân
    tới đỉnh cha của đỉnh đầu chuỗi nặng mà nó tương ứng.
    Khi duy trì cạnh nhẹ, cấu trúc "nhận cha chứ không nhận con",
    tức là chỉ có thể đi từ đỉnh con lên đỉnh cha, không thể đi ngược lại.
    Lưu ý rằng các cạnh trong cây nhị phân cân bằng toàn cục
    không có quan hệ tương ứng với các cạnh trong cây gốc.
3.  Tính cả cạnh nặng và cạnh nhẹ,
    chiều cao của cây nhị phân cân bằng toàn cục ở cấp độ $O(\log n)$.
    Đây là tính chất bảo đảm độ phức tạp thời gian của cây nhị phân cân bằng toàn cục.

Dưới đây là một ví dụ xây cây nhị phân cân bằng toàn cục.
Hình thứ nhất là cây gốc, lấy đỉnh 1 làm gốc.
Các đường liền là cạnh nặng.

![Cây gốc với các cạnh nặng](images/global-bst-1.svg)

Hình thứ hai là cây nhị phân cân bằng toàn cục được xây ra.
Trong đó đường nét đứt là cạnh nhẹ, đường liền là cạnh nặng,
mỗi cây nhị phân được biểu diễn bằng một vòng tròn đỏ.

![Cây nhị phân cân bằng toàn cục sau khi xây](images/global-bst-2.svg)

## Xây cây

Trước hết, giống như phân rã chuỗi nặng thông thường,
dùng một lần DFS để tìm con nặng của mỗi đỉnh.
Sau đó bắt đầu từ gốc, tìm chuỗi nặng chứa đỉnh gốc.
Với các con nhẹ của những đỉnh này, đệ quy xây cây và nối cạnh nhẹ.
Tiếp theo cần xây một cây nhị phân cho các đỉnh trên chuỗi nặng.
Trước tiên lưu các đỉnh trên chuỗi nặng vào một mảng,
tính tổng kích thước cây con của các con nhẹ của mỗi đỉnh cộng thêm một
(tức là size do chính đỉnh đó đóng góp).
Sau đó dựa vào giá trị này để tìm trung điểm có trọng số của chuỗi nặng,
lấy nó làm gốc của cây nhị phân, rồi đệ quy xây hai phía và nối cạnh nặng.

Mã như sau:

???+ note "Cài đặt"
    ```cpp
    std::vector<int> G[N];
    int n, fa[N], son[N], sz[N];
    
    void dfsS(int u) {
      sz[u] = 1;
      for (int v : G[u]) {
        dfsS(v);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
      }
    }
    
    int b[N], bs[N], l[N], r[N], f[N], ss[N];
    
    // Xây cây nhị phân cho các đỉnh trong [bl,br) của b, trả về gốc của cây nhị phân
    int cbuild(int bl, int br) {
      int x = bl, y = br;
      while (y - x > 1) {
        int mid = (x + y) >> 1;
        if (2 * (bs[mid] - bs[bl]) <= bs[br] - bs[bl])
          x = mid;
        else
          y = mid;
      }
      // Tìm trung điểm theo trọng số bs bằng tìm kiếm nhị phân
      y = b[x];
      ss[y] = br - bl;  // ss: kích thước cây con nặng trong cây nhị phân
      if (bl < x) {
        l[y] = cbuild(bl, x);
        f[l[y]] = y;
      }
      if (x + 1 < br) {
        r[y] = cbuild(x + 1, br);
        f[r[y]] = y;
      }
      return y;
    }
    
    int build(int x) {
      int y = x;
      do
        for (int v : G[y])
          if (v != son[y])
            f[build(v)] =
                y;  // Đệ quy xây cây và nối cạnh nhẹ; cần nối từ gốc cây nhị phân, không phải từ con
      while (y = son[y]);
      y = 0;
      do {
        b[y++] = x;                              // Lưu các đỉnh trên chuỗi nặng
        bs[y] = bs[y - 1] + sz[x] - sz[son[x]];  // bs: size con nhẹ + 1, lấy tổng tiền tố
      } while (x = son[x]);
      return cbuild(0, y);
    }
    ```

Từ mã trên, độ phức tạp thời gian để xây cây là $O(n\log n)$.
Tiếp theo có thể chứng minh chiều cao cây là $O(\log n)$:
xét việc nhảy theo đỉnh cha từ một đỉnh bất kỳ lên gốc.
Nhảy qua cạnh nhẹ tương đương với việc nhảy sang một chuỗi nặng khác trong cây gốc.
Theo tính chất của phân rã chuỗi nặng,
số cạnh nhẹ phải nhảy tối đa là $O(\log n)$.
Vì khi xây cây nhị phân, đỉnh gốc được chọn là trung điểm có trọng số tính theo các con nhẹ,
nên mỗi lần nhảy qua cạnh nặng thì size tính cả các con nhẹ ít nhất tăng gấp đôi.
Do đó số cạnh nặng phải nhảy cũng tối đa là $O(\log n)$.
Vì vậy chiều cao tổng thể của cây là $O(\log n)$.

## Truy vấn

Trên đây là phần về cây nhị phân cân bằng toàn cục.
Các thao tác cập nhật đường và truy vấn đường còn lại tương đối đơn giản:
chỉ cần xuất phát từ đỉnh cần thao tác rồi liên tục nhảy lên gốc.
Muốn thao tác trên tất cả các đỉnh có độ sâu nhỏ hơn nó
trên chuỗi nặng chứa một đỉnh nào đó,
về bản chất tương đương với thao tác trên tất cả các đỉnh
nằm bên trái đỉnh mục tiêu trong cây nhị phân của chuỗi nặng này.
Các thao tác đó có thể được phân rã thành một loạt thao tác trên cây con,
tương tự cách duy trì cây nhị phân thông thường,
trong đó cần duy trì tổng cây con và gắn nhãn cây con.
Trong quá trình này, dùng kỹ thuật lưu nhãn vĩnh viễn.
Cũng có thể dùng pushdown để gắn nhãn và dùng pushup để duy trì tổng cây con,
nhưng cách này có thể phức tạp hơn:
thông thường xử lý cây nhị phân là thao tác từ trên xuống dưới,
còn trong cấu trúc này cần xác định đường nhảy trước rồi mới pushdown từ trên xuống dưới,
có thể làm hằng số lớn hơn.

Mã như sau:

???+ note "Cài đặt"
    ```cpp
    // a: nhãn cộng trên cây con
    // s: tổng cây con (không tính nhãn cộng)
    int a[N], s[N];
    
    void add(int x) {
      bool t = true;
      int z = 0;
      while (x) {
        s[x] += z;
        if (t) {
          a[x]++;
          if (r[x]) a[r[x]]--;
          z += 1 + ss[l[x]];
          s[x] -= ss[r[x]];
        }
        t = (x != l[f[x]]);
        if (t && x != r[f[x]]) z = 0;  // Khi nhảy qua cạnh nhẹ, cần xóa về 0
        x = f[x];
      }
    }
    
    int query(int x) {
      int ret = 0;
      bool t = true;
      int z = 0;
      while (x) {
        if (t) {
          ret += s[x] - s[r[x]];
          ret -= 1ll * ss[r[x]] * a[r[x]];
          z += 1 + ss[l[x]];
        }
        ret += 1ll * z * a[x];
        t = (x != l[f[x]]);
        if (t && x != r[f[x]]) z = 0;  // Khi nhảy qua cạnh nhẹ, cần xóa về 0
        x = f[x];
      }
      return ret;
    }
    ```

Ngoài ra, với thao tác trên cây con, cần xét cả con nhẹ.
Cần duy trì thêm tổng cây con và nhãn cây con bao gồm cả con nhẹ,
từ đó có thể làm bài
"[P3384 [Mẫu] Phân rã nặng-nhẹ](https://www.luogu.com.cn/problem/P3384)".

## Bài tập ví dụ

??? note "[P4751 [Mẫu] \"DP động\" và phân trị cây động (bản tăng cường)](https://www.luogu.com.cn/problem/P4751)"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    constexpr int MAXN = 1000000;
    constexpr int MAXM = 3000000;
    constexpr int INF = 0x3FFFFFFF;
    using namespace std;
    
    struct edge {
      int to;
      edge *nxt;
    } edges[MAXN * 2 + 5];
    
    edge *ncnt = &edges[0], *Adj[MAXN + 5];
    int n, m;
    
    struct Matrix {
      int M[2][2];
    
      Matrix operator*(const Matrix &B) const {
        static Matrix ret;
        for (int i = 0; i < 2; i++)
          for (int j = 0; j < 2; j++) {
            ret.M[i][j] = -INF;
            for (int k = 0; k < 2; k++)
              ret.M[i][j] = max(ret.M[i][j], M[i][k] + B.M[k][j]);
          }
        return ret;
      }
    } matr1[MAXN + 5], matr2[MAXN + 5];  // Mỗi đỉnh duy trì hai ma trận
    
    int root;
    int w[MAXN + 5], dep[MAXN + 5], son[MAXN + 5], siz[MAXN + 5], lsiz[MAXN + 5];
    int g[MAXN + 5][2], f[MAXN + 5][2], trfa[MAXN + 5], bstch[MAXN + 5][2];
    int stk[MAXN + 5], tp;
    bool vis[MAXN + 5];
    
    void AddEdge(int u, int v) {
      edge *p = ++ncnt;
      p->to = v;
      p->nxt = Adj[u];
      Adj[u] = p;
    
      edge *q = ++ncnt;
      q->to = u;
      q->nxt = Adj[v];
      Adj[v] = q;
    }
    
    void DFS(int u, int fa) {
      siz[u] = 1;
      for (edge *p = Adj[u]; p != NULL; p = p->nxt) {
        int v = p->to;
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        DFS(v, u);
        siz[u] += siz[v];
        if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
      }
      lsiz[u] = siz[u] - siz[son[u]];  // Tổng siz của con nhẹ + 1
    }
    
    void DFS2(int u, int fa) {
      f[u][1] = w[u], f[u][0] = 0;
      g[u][1] = w[u], g[u][0] = 0;
      if (son[u]) {
        DFS2(son[u], u);
        f[u][0] += max(f[son[u]][0], f[son[u]][1]);
        f[u][1] += f[son[u]][0];
      }
      for (edge *p = Adj[u]; p != NULL; p = p->nxt) {
        int v = p->to;
        if (v == fa || v == son[u]) continue;
        DFS2(v, u);
        f[u][0] += max(f[v][0], f[v][1]);  // f[][] là mảng DP thông thường
        f[u][1] += f[v][0];
        g[u][0] += max(f[v][0], f[v][1]);  // Mảng g[][] chỉ thống kê thông tin của chính nó và con nhẹ
        g[u][1] += f[v][0];
      }
    }
    
    void PushUp(int u) {
      matr2[u] = matr1[u];  // matr1 là thông tin của một đỉnh cộng với con nhẹ, matr2 là thông tin đoạn
      if (bstch[u][0]) matr2[u] = matr2[bstch[u][0]] * matr2[u];
      // Lưu ý hướng chuyển tiếp; nếu định nghĩa phép nhân ma trận khác thì hướng có thể khác
      if (bstch[u][1]) matr2[u] = matr2[u] * matr2[bstch[u][1]];
    }
    
    int getmx2(int u) { return max(matr2[u].M[0][0], matr2[u].M[0][1]); }
    
    int getmx1(int u) { return max(getmx2(u), matr2[u].M[1][0]); }
    
    int SBuild(int l, int r) {
      if (l > r) return 0;
      int tot = 0;
      for (int i = l; i <= r; i++) tot += lsiz[stk[i]];
      for (int i = l, sumn = lsiz[stk[l]]; i <= r; i++, sumn += lsiz[stk[i]])
        if (sumn * 2 >= tot)  // Đã là trọng tâm
        {
          int lch = SBuild(l, i - 1), rch = SBuild(i + 1, r);
          bstch[stk[i]][0] = lch;
          bstch[stk[i]][1] = rch;
          trfa[lch] = trfa[rch] = stk[i];
          PushUp(stk[i]);  // Tổng hợp thông tin của đoạn lên
          return stk[i];
        }
      return 0;
    }
    
    int Build(int u) {
      for (int pos = u; pos; pos = son[pos]) vis[pos] = true;
      for (int pos = u; pos; pos = son[pos])
        for (edge *p = Adj[pos]; p != NULL; p = p->nxt)
          if (!vis[p->to])  // Là con nhẹ
          {
            int v = p->to, ret = Build(v);
            trfa[ret] = pos;  // Nối treefa[] của con nhẹ vào
          }
      tp = 0;
      for (int pos = u; pos; pos = son[pos]) stk[++tp] = pos;  // Lấy chuỗi nặng ra
      int ret = SBuild(1, tp);  // SBuild riêng cho chuỗi nặng (tôi đoán là Special Build?)
      return ret;               // Trả về gốc cây nhị phân của chuỗi nặng hiện tại
    }
    
    void Modify(int u, int val) {
      matr1[u].M[1][0] += val - w[u];
      w[u] = val;
      for (int pos = u; pos; pos = trfa[pos])
        if (trfa[pos] && bstch[trfa[pos]][0] != pos && bstch[trfa[pos]][1] != pos) {
          matr1[trfa[pos]].M[0][0] -= getmx1(pos);
          matr1[trfa[pos]].M[0][1] = matr1[trfa[pos]].M[0][0];
          matr1[trfa[pos]].M[1][0] -= getmx2(pos);
          PushUp(pos);
          matr1[trfa[pos]].M[0][0] += getmx1(pos);
          matr1[trfa[pos]].M[0][1] = matr1[trfa[pos]].M[0][0];
          matr1[trfa[pos]].M[1][0] += getmx2(pos);
        } else
          PushUp(pos);
    }
    
    int read() {
      int ret = 0, f = 1;
      char c = 0;
      while (c < '0' || c > '9') {
        c = getchar();
        if (c == '-') f = -f;
      }
      ret = 10 * ret + c - '0';
      while (true) {
        c = getchar();
        if (c < '0' || c > '9') break;
        ret = 10 * ret + c - '0';
      }
      return ret * f;
    }
    
    void print(int x) {
      if (x == 0) return;
      print(x / 10);
      putchar(x % 10 + '0');
    }
    
    int main() {
      scanf("%d %d", &n, &m);
      for (int i = 1; i <= n; i++) w[i] = read();
      int u, v;
      for (int i = 1; i < n; i++) {
        u = read(), v = read();
        AddEdge(u, v);
      }
      DFS(1, -1);
      // Tìm con nặng
      DFS2(1, -1);
      // Tìm giá trị DP ban đầu; cũng có thể làm trong Build(), nhưng viết vậy sẽ thống nhất với cách viết phân rã cây
      for (int i = 1; i <= n; i++) {
        matr1[i].M[0][0] = matr1[i].M[0][1] = g[i][0];
        matr1[i].M[1][0] = g[i][1], matr1[i].M[1][1] = -INF;  // Khởi tạo ma trận
      }
      root = Build(1);  // root chính là trọng tâm của chuỗi nặng chứa đỉnh gốc
      int lastans = 0;
      for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        u ^= lastans;  // Bắt buộc xử lý trực tuyến
        Modify(u, v);
        lastans = getmx1(root);  // Lấy giá trị trực tiếp
        if (lastans == 0)
          putchar('0');
        else
          print(lastans);
        putchar('\n');
      }
      return 0;
    }
    ```

## Tham khảo

[P4211 [LNOI2014] LCA | Cây nhị phân cân bằng toàn cục](https://www.luogu.com.cn/blog/nederland/globalbst)
