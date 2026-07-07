author: Ir1d, sshwy, Enter-tainer, H-J-Granger, ouuan, GavinZhengOI, hsfzLZH1, xyf007

[Giá trị nhỏ thứ $k$ trên đoạn tĩnh (POJ 2104 Số thứ k)](http://poj.org/problem?id=2104) có thể được giải bằng
[cây phân đoạn theo giá trị](./persistent-seg.md) với độ phức tạp thời gian $O(n\log n)$.

Nếu đoạn trở thành động thì sao? Nói cách khác, nếu còn phải hỗ trợ thao tác sửa giá trị tại một vị trí đơn lẻ thì cần làm thế nào?

??? note "Bài ví dụ [LOJ 106 Cây cân bằng (cây lồng cây)](https://loj.ac/problem/106)"
    Duy trì một dãy số có thứ tự, trong đó cần hỗ trợ các thao tác sau:

    -   Truy vấn thứ hạng của $x$ trong đoạn;
    -   Truy vấn giá trị có thứ hạng $k$ trong đoạn;
    -   Sửa giá trị tại một vị trí nào đó;
    -   Truy vấn tiền nhiệm của $x$ trong đoạn (tiền nhiệm được định nghĩa là số lớn nhất nhỏ hơn $x$);
    -   Truy vấn kế nhiệm của $x$ trong đoạn (kế nhiệm được định nghĩa là số nhỏ nhất lớn hơn $x$).

??? note "Bài ví dụ [Luogu P2617 Xếp hạng động](https://www.luogu.com.cn/problem/P2617)"
    Cho một dãy $a_1,a_2 \dots a_n$ gồm $n$ số, cần hỗ trợ hai thao tác:

    -   `Q l r k` biểu thị truy vấn số nhỏ thứ $k$ trong các phần tử có chỉ số thuộc đoạn $[l,r]$
    -   `C x y` biểu thị đổi $a_x$ thành $y$

Nếu dùng cách [cây phân đoạn lồng cây cân bằng](./balanced-in-seg.md) đã thảo luận, tức là với mỗi nút của cây phân đoạn
duy trì một cây cân bằng cho đoạn mà nút đó biểu diễn, rồi dùng tìm kiếm nhị phân để tìm giá trị nhỏ thứ $k$. Mỗi thao
tác truy vấn phải phủ nhiều đoạn, tức là liên quan đến nhiều nút, nhưng cây cân bằng không thể tìm đồng thời nhiều giá
trị, nên độ phức tạp thời gian là $O(\log^3 n)$, chưa phải tối ưu.

Ý tưởng tối ưu là kết hợp thao tác tìm kiếm nhị phân trên đáp án với thao tác truy vấn số lượng phần tử nhỏ hơn một giá
trị, sử dụng **cây phân đoạn lồng cây phân đoạn theo giá trị mở nút động**. Vì cấu trúc của tất cả các cây phân đoạn là
giống nhau, có thể thực hiện tìm kiếm nhị phân trên cây phân đoạn đồng thời trên nhiều cây.

Khi thực hiện thao tác sửa, trước hết đi từ trên xuống dưới trên cây phân đoạn đến điểm cần sửa, xóa giá trị cũ trong
cây phân đoạn theo giá trị mở nút động mà mỗi nút đi qua trỏ tới, rồi chèn giá trị mới. Quá trình này đi qua
$O(\log n)$ nút trên cây phân đoạn; một lần sửa trên cây phân đoạn theo giá trị mở nút động mất $O(\log n)$, nên độ
phức tạp thời gian của thao tác sửa là $O(\log^2 n)$.

Khi truy vấn đáp án, trước hết lấy ra tất cả các nút trên cây phân đoạn được đoạn truy vấn phủ, sau đó dùng phương pháp
tương tự bài giá trị nhỏ thứ $k$ trên đoạn tĩnh để cho các nút này cùng đi sang con trái hoặc con phải. Nếu tổng các
giá trị được lưu ở con trái của tất cả các nút này lớn hơn hoặc bằng $k$, thì đi sang trái, ngược lại đi sang phải. Vì
nhiều nhất chỉ phủ $O(\log n)$ nút, nên mỗi lần cũng chỉ có bấy nhiêu nút đi xuống; độ phức tạp thời gian là
$O(\log^2 n)$.

Do hằng số của cây phân đoạn khá lớn, trong cài đặt thường dùng **cây Fenwick**, có hằng số nhỏ hơn và xử lý tổng tiền
tố thuận tiện hơn. Ngoài ra, độ phức tạp bộ nhớ là $O(n\log^2 n)$, vì vậy khi sử dụng cần **lưu ý giới hạn bộ nhớ**.

Dưới đây là một cách cài đặt:

??? note "Cài đặt"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <map>
    #include <set>
    #define LC o << 1
    #define RC o << 1 | 1
    using namespace std;
    constexpr int MAXN = 1000010;
    int n, m, a[MAXN], u[MAXN], x[MAXN], l[MAXN], r[MAXN], k[MAXN], cur, cur1, cur2,
        q1[MAXN], q2[MAXN], v[MAXN];
    char op[MAXN];
    set<int> ST;
    map<int, int> mp;
    
    struct segment_tree  // Cây phân đoạn theo giá trị mở nút động được đóng gói
    {
      int cur, rt[MAXN * 4], sum[MAXN * 60], lc[MAXN * 60], rc[MAXN * 60];
    
      void build(int& o) { o = ++cur; }
    
      void print(int o, int l, int r) {
        if (!o) return;
        if (l == r && sum[o]) printf("%d ", l);
        int mid = (l + r) >> 1;
        print(lc[o], l, mid);
        print(rc[o], mid + 1, r);
      }
    
      void update(int& o, int l, int r, int x, int v) {
        if (!o) o = ++cur;
        sum[o] += v;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (x <= mid)
          update(lc[o], l, mid, x, v);
        else
          update(rc[o], mid + 1, r, x, v);
      }
    } st;
    
    // Cài đặt cây Fenwick
    namespace fenwick_impl {
      int lowbit(int o) { return (o & (-o)); }
    
      void upd(int o, int x, int v) {
        for (; o <= n; o += lowbit(o)) st.update(st.rt[o], 1, n, x, v);
      }
    
      void gtv(int o, int* A, int& p) {
        p = 0;
        for (; o; o -= lowbit(o)) A[++p] = st.rt[o];
      }
    
      int qry(int l, int r, int k) {
        if (l == r) return l;
        int mid = (l + r) >> 1, siz = 0;
        for (int i = 1; i <= cur1; i++) siz += st.sum[st.lc[q1[i]]];
        for (int i = 1; i <= cur2; i++) siz -= st.sum[st.lc[q2[i]]];
        // printf("j %d %d %d %d\n",cur1,cur2,siz,k);
        if (siz >= k) {
          for (int i = 1; i <= cur1; i++) q1[i] = st.lc[q1[i]];
          for (int i = 1; i <= cur2; i++) q2[i] = st.lc[q2[i]];
          return qry(l, mid, k);
        } else {
          for (int i = 1; i <= cur1; i++) q1[i] = st.rc[q1[i]];
          for (int i = 1; i <= cur2; i++) q2[i] = st.rc[q2[i]];
          return qry(mid + 1, r, k - siz);
        }
      }
    }
    using namespace fenwick_impl;
    
    // Cài đặt cây phân đoạn
    namespace segtree_impl {
    void build(int o, int l, int r) {
      st.build(st.rt[o]);
      if (l == r) return;
      int mid = (l + r) >> 1;
      build(LC, l, mid);
      build(RC, mid + 1, r);
    }
    
    void print(int o, int l, int r) {
      printf("%d %d:", l, r);
      st.print(st.rt[o], 1, n);
      printf("\n");
      if (l == r) return;
      int mid = (l + r) >> 1;
      print(LC, l, mid);
      print(RC, mid + 1, r);
    }
    
    void update(int o, int l, int r, int q, int x, int v) {
      st.update(st.rt[o], 1, n, x, v);
      if (l == r) return;
      int mid = (l + r) >> 1;
      if (q <= mid)
        update(LC, l, mid, q, x, v);
      else
        update(RC, mid + 1, r, q, x, v);
    }
    
    void getval(int o, int l, int r, int ql, int qr) {
      if (l > qr || r < ql) return;
      if (ql <= l && r <= qr) {
        q[++cur] = st.rt[o];
        return;
      }
      int mid = (l + r) >> 1;
      getval(LC, l, mid, ql, qr);
      getval(RC, mid + 1, r, ql, qr);
    }
    
    int query(int l, int r, int k) {
      if (l == r) return l;
      int mid = (l + r) >> 1, siz = 0;
      for (int i = 1; i <= cur; i++) siz += st.sum[st.lc[q[i]]];
      if (siz >= k) {
        for (int i = 1; i <= cur; i++) q[i] = st.lc[q[i]];
        return query(l, mid, k);
      } else {
        for (int i = 1; i <= cur; i++) q[i] = st.rc[q[i]];
        return query(mid + 1, r, k - siz);
      }
    }
    }  // namespace segtree_impl
    
    int main() {
      scanf("%d%d", &n, &m);
      for (int i = 1; i <= n; i++) scanf("%d", a + i), ST.insert(a[i]);
      for (int i = 1; i <= m; i++) {
        scanf(" %c", op + i);
        if (op[i] == 'C')
          scanf("%d%d", u + i, x + i), ST.insert(x[i]);
        else
          scanf("%d%d%d", l + i, r + i, k + i);
      }
      for (set<int>::iterator it = ST.begin(); it != ST.end(); it++)
        mp[*it] = ++cur, v[cur] = *it;
      for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
      for (int i = 1; i <= m; i++)
        if (op[i] == 'C') x[i] = mp[x[i]];
      n += m;
      // build(1,1,n);
      for (int i = 1; i <= n; i++) upd(i, a[i], 1);
      // print(1,1,n);
      for (int i = 1; i <= m; i++) {
        if (op[i] == 'C') {
          upd(u[i], a[u[i]], -1);
          upd(u[i], x[i], 1);
          a[u[i]] = x[i];
        } else {
          gtv(r[i], q1, cur1);
          gtv(l[i] - 1, q2, cur2);
          printf("%d\n", v[qry(1, n, k[i])]);
        }
      }
      return 0;
    }
    ```
