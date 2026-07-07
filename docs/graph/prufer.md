???+ note "Ghi chú"
    Bài viết này được dịch từ [e-maxx Prüfer Code](https://github.com/e-maxx-eng/e-maxx-eng/blob/master/src/graph/pruefer_code.md).
    Trong bản gốc, các đỉnh được đánh số từ $0$;
    bài viết này đổi phần trình bày sang đánh số từ $1$ theo thói quen của đa số người đọc.

Bài viết này giới thiệu dãy Prüfer (Prüfer code), một phương pháp biểu diễn một cây có nhãn bằng một dãy số nguyên duy nhất.

Có thể dùng dãy Prüfer để chứng minh [công thức Cayley](#công-thức-cayley-cayleys-formula) (Cayley's formula).
Bài viết cũng trình bày cách tính số phương án thêm cạnh vào một đồ thị để làm cho đồ thị liên thông.

**Quy ước**: Không xét cây chỉ có $1$ đỉnh.

## Dãy Prüfer

### Giới thiệu

Dãy Prüfer có thể biểu diễn một cây có nhãn gồm $n$ đỉnh bằng $n-2$ số nguyên thuộc $[1,n]$.
Cũng có thể hiểu nó là một song ánh giữa các cây khung của đồ thị đầy đủ và các dãy số.
Dãy này thường được dùng trong các bài toán đếm tổ hợp.

Heinz Prüfer phát minh ra dãy này vào năm 1918 để chứng minh [công thức Cayley](#công-thức-cayley-cayleys-formula).

### Xây dựng dãy Prüfer cho cây

Dãy Prüfer được xây dựng như sau:
mỗi lần chọn lá có số hiệu nhỏ nhất rồi xóa nó, sau đó ghi vào dãy đỉnh kề với lá đó.
Sau khi lặp lại $n-2$ lần, cây chỉ còn hai đỉnh và thuật toán kết thúc.

Nếu dùng đống thì độ phức tạp là $O(n\log n)$.

???+ note "Cài đặt"
    === "C++"
        ```cpp
        // Mã nguồn lấy từ bản gốc, các đỉnh được đánh số từ 0
        vector<vector<int>> adj;
        
        vector<int> pruefer_code() {
          int n = adj.size();
          set<int> leafs;
          vector<int> degree(n);
          vector<bool> killed(n);
          for (int i = 0; i < n; i++) {
            degree[i] = adj[i].size();
            if (degree[i] == 1) leafs.insert(i);
          }
        
          vector<int> code(n - 2);
          for (int i = 0; i < n - 2; i++) {
            int leaf = *leafs.begin();
            leafs.erase(leafs.begin());
            killed[leaf] = true;
            int v;
            for (int u : adj[leaf])
              if (!killed[u]) v = u;
            code[i] = v;
            if (--degree[v] == 1) leafs.insert(v);
          }
          return code;
        }
        ```
    
    === "Python"
        ```python
        # Các đỉnh được đánh số từ 0
        adj = [[]]
        
        
        def pruefer_code():
            n = len(adj)
            leafs = set()
            degree = [0] * n
            killed = [False] * n
            for i in range(1, n):
                degree[i] = len(adj[i])
                if degree[i] == 1:
                    leafs.intersection(i)
            code = [0] * (n - 2)
            for i in range(1, n - 2):
                leaf = leafs[0]
                leafs.pop()
                killed[leaf] = True
                for u in adj[leaf]:
                    if killed[u] == False:
                        v = u
                code[i] = v
                if degree[v] == 1:
                    degree[v] = degree[v] - 1
                    leafs.intersection(v)
            return code
        ```

Ví dụ, đây là quá trình xây dựng dãy Prüfer cho một cây có $7$ đỉnh:

![Prüfer](./images/prufer1.png)

Dãy cuối cùng là $2,2,3,3,2$.

Ngoài ra, còn có một thuật toán xây dựng tuyến tính.

### Thuật toán xây dựng dãy Prüfer tuyến tính

Bản chất của cách xây dựng tuyến tính là duy trì một con trỏ trỏ tới đỉnh sắp bị xóa.
Trước hết nhận thấy rằng số lá không tăng:
khi xóa một lá, tổng số lá hoặc giữ nguyên hoặc giảm đi $1$.

Vì vậy, xét quy trình sau: duy trì một con trỏ $p$.
Ban đầu $p$ trỏ tới lá có số hiệu nhỏ nhất.
Đồng thời, duy trì bậc của từng đỉnh để biết khi xóa một đỉnh có sinh ra lá mới hay không.
Các thao tác như sau:

1.  Xóa đỉnh mà $p$ đang trỏ tới và kiểm tra xem có sinh ra lá mới hay không.
2.  Nếu sinh ra lá mới, giả sử số hiệu của nó là $x$, so sánh $p$ và $x$.
    Nếu $x>p$, không cần thao tác gì thêm.
    Nếu không, lập tức xóa $x$, rồi kiểm tra sau khi xóa $x$ có sinh ra lá mới hay không.
    Lặp lại bước $2$ cho đến khi không sinh ra đỉnh mới hoặc số hiệu của đỉnh mới $>p$.
3.  Tăng con trỏ $p$ cho đến khi gặp một lá chưa bị xóa.

#### Tính đúng đắn

Lặp các thao tác trên $n-2$ lần là hoàn thành việc xây dựng dãy. Tiếp theo xét tính đúng đắn của thuật toán.

$p$ là lá có số hiệu nhỏ nhất hiện tại. Nếu sau khi xóa $p$ không sinh ra lá mới, chỉ có thể đi tìm lá tiếp theo; nếu sinh ra lá $x$:

-   Nếu $x>p$, khi $p$ quét tiếp về sau cũng sẽ gặp nó, nên không cần thao tác gì.
-   Nếu $x<p$, vì $p$ vốn là lá có số hiệu nhỏ nhất, mà $x$ còn nhỏ hơn $p$,
    nên $x$ chính là lá có số hiệu nhỏ nhất hiện tại và cần được xóa trước.
    Sau khi xóa $x$, tiếp tục lập luận như vậy cho đến khi không còn lá nào nhỏ hơn.

Về độ phức tạp, mỗi cạnh được thăm nhiều nhất một lần khi giảm bậc, còn con trỏ đi qua mỗi đỉnh nhiều nhất một lần. Do đó độ phức tạp là $O(n)$.

#### Cài đặt

=== "C++"
    ```cpp
    // Mã nguồn lấy từ bản gốc, cũng đánh số từ 0
    vector<vector<int>> adj;
    vector<int> parent;
    
    void dfs(int v) {
      for (int u : adj[v]) {
        if (u != parent[v]) parent[u] = v, dfs(u);
      }
    }
    
    vector<int> pruefer_code() {
      int n = adj.size();
      parent.resize(n), parent[n - 1] = -1;
      dfs(n - 1);
    
      int ptr = -1;
      vector<int> degree(n);
      for (int i = 0; i < n; i++) {
        degree[i] = adj[i].size();
        if (degree[i] == 1 && ptr == -1) ptr = i;
      }
    
      vector<int> code(n - 2);
      int leaf = ptr;
      for (int i = 0; i < n - 2; i++) {
        int next = parent[leaf];
        code[i] = next;
        if (--degree[next] == 1 && next < ptr) {
          leaf = next;
        } else {
          ptr++;
          while (degree[ptr] != 1) ptr++;
          leaf = ptr;
        }
      }
      return code;
    }
    ```

=== "Python"
    ```python
    # Cũng đánh số từ 0
    adj = [[]]
    parent = [0] * n
    
    
    def dfs(v):
        for u in adj[v]:
            if u != parent[v]:
                parent[u] = v
                dfs(u)
    
    
    def pruefer_code():
        n = len(adj)
        parent[n - 1] = -1
        dfs(n - 1)
    
        ptr = -1
        degree = [0] * n
        for i in range(0, n):
            degree[i] = len(adj[i])
            if degree[i] == 1 and ptr == -1:
                ptr = i
    
        code = [0] * (n - 2)
        leaf = ptr
        for i in range(0, n - 2):
            next = parent[leaf]
            code[i] = next
            if degree[next] == 1 and next < ptr:
                degree[next] = degree[next] - 1
                leaf = next
            else:
                ptr = ptr + 1
                while degree[ptr] != 1:
                    ptr = ptr + 1
                leaf = ptr
        return code
    ```

### Tính chất của dãy Prüfer

1.  Sau khi xây dựng xong dãy Prüfer, cây ban đầu sẽ còn lại hai đỉnh, trong đó một đỉnh là đỉnh có số hiệu lớn nhất $n$.
2.  Số lần mỗi đỉnh xuất hiện trong dãy bằng bậc của nó trừ $1$. Các đỉnh không xuất hiện chính là các lá.

### Dựng lại cây từ dãy Prüfer

Phương pháp dựng lại cây cũng tương tự.
Dựa vào tính chất của dãy Prüfer, có thể suy ra bậc của mỗi đỉnh trong cây ban đầu.
Từ đó cũng tìm được lá có số hiệu nhỏ nhất;
lá này nối với đỉnh tương ứng với số đầu tiên trong dãy Prüfer.
Sau đó, đồng thời giảm bậc của hai đỉnh này đi một.

Từ đó có quy trình dựng lại cây:
mỗi lần chọn đỉnh có bậc $1$ và số hiệu nhỏ nhất, nối nó với đỉnh đang xét trong dãy Prüfer,
rồi đồng thời giảm bậc của hai đỉnh.
Cuối cùng còn lại hai đỉnh có bậc $1$, trong đó một đỉnh là đỉnh $n$; nối hai đỉnh này lại.
Nếu dùng đống để duy trì quá trình này, mỗi khi bậc của một đỉnh giảm xuống $1$ thì thêm đỉnh đó vào đống.
Độ phức tạp là $O(n\log n)$.

???+ note "Cài đặt"
    ```cpp
    // Mã nguồn lấy từ bản gốc
    vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
      int n = code.size() + 2;
      vector<int> degree(n, 1);
      for (int i : code) degree[i]++;
    
      set<int> leaves;
      for (int i = 0; i < n; i++)
        if (degree[i] == 1) leaves.insert(i);
    
      vector<pair<int, int>> edges;
      for (int v : code) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
    
        edges.emplace_back(leaf, v);
        if (--degree[v] == 1) leaves.insert(v);
      }
      edges.emplace_back(*leaves.begin(), n - 1);
      return edges;
    }
    ```

### Dựng lại cây trong thời gian tuyến tính

Tương tự phương pháp xây dựng dãy Prüfer tuyến tính.
Khi giảm bậc có thể sinh ra lá mới, vì vậy cần so sánh lá này với con trỏ $p$;
nếu nó nhỏ hơn thì ưu tiên xử lý nó.

#### Cài đặt

```cpp
// Mã nguồn lấy từ bản gốc
vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
  int n = code.size() + 2;
  vector<int> degree(n, 1);
  for (int i : code) degree[i]++;

  int ptr = 0;
  while (degree[ptr] != 1) ptr++;
  int leaf = ptr;

  vector<pair<int, int>> edges;
  for (int v : code) {
    edges.emplace_back(leaf, v);
    if (--degree[v] == 1 && v < ptr) {
      leaf = v;
    } else {
      ptr++;
      while (degree[ptr] != 1) ptr++;
      leaf = ptr;
    }
  }
  edges.emplace_back(leaf, n - 1);
  return edges;
}
```

Qua các quy trình trên, có thể hiểu rằng dãy Prüfer thiết lập một song ánh với các cây vô hướng có nhãn và không gốc.

## Công thức Cayley (Cayley's formula)

Đồ thị đầy đủ $K_n$ có $n^{n-2}$ cây khung.

Có nhiều cách chứng minh công thức này, nhưng chứng minh bằng dãy Prüfer rất trực tiếp.
Mọi dãy số nguyên có độ dài $n-2$ và miền giá trị $[1,n]$
đều tương ứng song ánh, thông qua dãy Prüfer, với một cây khung.
Vì vậy số phương án là $n^{n-2}$.

## Số phương án làm đồ thị liên thông

Dãy Prüfer còn có thể tạo ra một công thức tổng quát hơn [công thức Cayley](#công-thức-cayley-cayleys-formula). Chẳng hạn xét bài toán sau:

> Một đồ thị vô hướng có nhãn gồm $n$ đỉnh, $m$ cạnh và $k$ thành phần liên thông. Cần thêm $k-1$ cạnh để toàn bộ đồ thị liên thông. Tính số phương án.

### Chứng minh

Gọi $s_i$ là số đỉnh trong thành phần liên thông thứ $i$.
Xét việc xây dựng dãy Prüfer trên $k$ thành phần liên thông.
Vì có nhiều cách nối giữa hai thành phần liên thông, đây không phải là dãy Prüfer thông thường.
Giả sử $d_i$ là bậc của thành phần liên thông thứ $i$.
Do tổng bậc bằng hai lần số cạnh, có $\sum_{i=1}^kd_i=2k-2$.
Khi đó, với một dãy $d$ cố định, số cách xây dựng dãy Prüfer là

$$
\binom{k-2}{d_1-1,d_2-1,\cdots,d_k-1}=\frac{(k-2)!}{(d_1-1)!(d_2-1)!\cdots(d_k-1)!}
$$

Đối với thành phần liên thông thứ $i$, có ${s_i}^{d_i}$ cách chọn các đỉnh đầu mút để kết nối.
Vì vậy, với dãy $d$ cố định, số phương án làm đồ thị liên thông là

$$
\binom{k-2}{d_1-1,d_2-1,\cdots,d_k-1}\cdot \prod_{i=1}^k{s_i}^{d_i}
$$

Bây giờ cần liệt kê các dãy $d$, nên biểu thức trở thành

$$
\sum_{d_i\ge 1,\sum_{i=1}^kd_i=2k-2}\binom{k-2}{d_1-1,d_2-1,\cdots,d_k-1}\cdot \prod_{i=1}^k{s_i}^{d_i}
$$

Biểu thức này có thể xử lý bằng định lý nhị thức đa thức:

$$
(x_1 + \dots + x_m)^p = \sum_{\substack{c_i \ge 0 ,\  \sum_{i=1}^m c_i = p}} \binom{p}{c_1, c_2, \cdots ,c_m}\cdot \prod_{i=1}^m{x_i}^{c_i}
$$

Đổi biến trong biểu thức ban đầu: đặt $e_i=d_i-1$. Khi đó $\sum_{i=1}^ke_i=k-2$, nên biểu thức ban đầu trở thành

$$
\sum_{e_i\ge 0,\sum_{i=1}^ke_i=k-2}\binom{k-2}{e_1,e_2,\cdots,e_k}\cdot \prod_{i=1}^k{s_i}^{e_i+1}
$$

Rút gọn thu được

$$
(s_1+s_2+\cdots+s_k)^{k-2}\cdot \prod_{i=1}^ks_i
$$

tức là

$$
n^{k-2}\cdot\prod_{i=1}^ks_i
$$

đây chính là đáp án.

## Bài tập

-   [Luogu P6086 [Mẫu] Dãy Prüfer](https://www.luogu.com.cn/problem/P6086) (bài mẫu)
-   [Luogu P11039 [MX-X3-T6] "RiOI-4" TECHNOPOLIS 2085](https://www.luogu.com.cn/problem/P11039)
-   [UVa #10843 - Trò chơi của Anne](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=20&page=show_problem&problem=1784)
-   [Timus #1069 - Mã Prüfer](http://acm.timus.ru/problem.aspx?space=1&num=1069)
-   [Codeforces - Manh mối](http://codeforces.com/contest/156/problem/D)
-   [Topcoder - Các thành phố và con đường, bảng Hai](https://archive.topcoder.com/ProblemStatement/pm/10774)
