author: accelsao, Enter-tainer, guodong2005, StudyingFather, Backl1ght, Chrogeek, H-J-Granger, Henry-ZHR

Ghép cặp hai phía có trọng số lớn nhất là một ghép cặp trong đồ thị hai phía sao cho tổng trọng số các cạnh được chọn là lớn nhất.

<span id="hungarian-algorithm-kuhnmunkres-algorithm"></span>
## Thuật toán Hungarian (Kuhn-Munkres)

Thuật toán Hungarian, còn gọi là thuật toán **KM**, có thể tìm **ghép cặp hoàn hảo có trọng số lớn nhất** trong đồ thị hai phía trong thời gian $O(n^3)$.

Vì số đỉnh ở hai tập của đồ thị hai phía không phải lúc nào cũng bằng nhau, để áp dụng thuật toán KM cho bài toán ghép cặp hai phía có trọng số lớn nhất, trước hết cần xử lý như sau: thêm các đỉnh giả vào tập có ít đỉnh hơn để hai phía có cùng số đỉnh, rồi đặt trọng số của những cạnh không tồn tại thành $0$. Khi đó, bài toán được chuyển thành bài toán tìm **ghép cặp hoàn hảo có trọng số lớn nhất**, nên có thể giải bằng thuật toán KM.

???+ note "Nhãn đỉnh khả thi"
    Gán cho mỗi đỉnh $i$ một giá trị $l(i)$, sao cho với mọi cạnh $(u,v)$ đều có $w(u,v) \leq l(u) + l(v)$.

???+ note "Đồ thị con đẳng thức"
    Với một bộ nhãn đỉnh khả thi, đây là đồ thị con sinh của đồ thị gốc, chứa toàn bộ các đỉnh nhưng chỉ chứa những cạnh $(u,v)$ thỏa mãn $w(u,v) = l(u) + l(v)$.

???+ note "Định lý 1: Với một bộ nhãn đỉnh khả thi, nếu đồ thị con đẳng thức của nó có ghép cặp hoàn hảo, thì ghép cặp đó là ghép cặp hoàn hảo có trọng số lớn nhất của đồ thị hai phía ban đầu."
    Chứng minh 1.
    
    Xét một ghép cặp hoàn hảo bất kỳ $M$ của đồ thị hai phía ban đầu, tổng trọng số của nó là
    
    $val(M) = \sum_{(u,v)\in M} {w(u,v)} \leq \sum_{(u,v)\in M} {l(u) + l(v)} \leq \sum_{i=1}^{n} l(i)$
    
    Với một ghép cặp hoàn hảo $M'$ bất kỳ trong đồ thị con đẳng thức ứng với một bộ nhãn đỉnh khả thi, tổng trọng số là
    
    $val(M') = \sum_{(u,v)\in M} {l(u) + l(v)} = \sum_{i=1}^{n} l(i)$
    
    Do đó tổng trọng số của mọi ghép cặp hoàn hảo đều không lớn hơn $val(M')$, nên $M'$ chính là ghép cặp có trọng số lớn nhất.

Từ định lý 1, mục tiêu của ta là liên tục điều chỉnh bộ nhãn đỉnh khả thi để đồ thị con đẳng thức có ghép cặp hoàn hảo.

Vì hai phía có số đỉnh bằng nhau, giả sử số đỉnh là $n$. Gọi $lx(i)$ là nhãn đỉnh của đỉnh thứ $i$ ở phía trái, $ly(i)$ là nhãn đỉnh của đỉnh thứ $i$ ở phía phải, và $w(u,v)$ là trọng số giữa đỉnh thứ $u$ ở phía trái và đỉnh thứ $v$ ở phía phải.

Trước hết khởi tạo một bộ nhãn đỉnh khả thi, ví dụ

$lx(i) = \max_{1\leq j\leq n} \{ w(i, j)\},\, ly(i) = 0$

Sau đó chọn một đỉnh chưa ghép cặp và tìm đường tăng giống như trong bài toán ghép cặp lớn nhất. Nếu tìm được đường tăng thì mở rộng ghép cặp; nếu không, ta thu được một cây luân phiên.

Gọi $S$, $T$ lần lượt là các đỉnh phía trái và phía phải nằm trong cây luân phiên, còn $S'$, $T'$ là các đỉnh không nằm trong cây luân phiên.

![bigraph-weight-match-1](./images/bigraph-weight-match-1.png)

Trong đồ thị con đẳng thức:

-   Không tồn tại cạnh $S-T'$, nếu không cây luân phiên đã có thể mở rộng.
-   Mọi cạnh $S'-T$ chắc chắn là cạnh không thuộc ghép cặp, nếu không đỉnh tương ứng đã thuộc $S$.

Giả sử giảm nhãn của các đỉnh trong $S$ đi $a$ và tăng nhãn của các đỉnh trong $T$ thêm $a$, ta thấy rằng:

-   Các cạnh $S-T$ vẫn nằm trong đồ thị con đẳng thức.
-   Các cạnh $S'-T'$ không thay đổi.
-   Với các cạnh $S-T'$, giá trị $lx + ly$ giảm xuống, nên chúng có thể được thêm vào đồ thị con đẳng thức.
-   Với các cạnh $S'-T$, giá trị $lx + ly$ tăng lên, nên chúng không thể được thêm vào đồ thị con đẳng thức.

Vì vậy giá trị $a$ rõ ràng nên được chọn là độ chênh nhỏ nhất trên các cạnh $S-T'$:

$a = \min \{ lx(u) + ly(v) - w(u,v) | u\in{S} , v\in{T'} \}$.

Khi một cạnh mới $(u,v)$ được thêm vào đồ thị con đẳng thức, có hai trường hợp:

-   $v$ là đỉnh chưa ghép cặp, khi đó tìm được đường tăng.
-   $v$ đã được ghép cặp với một đỉnh trong $S'$.

Như vậy, sau nhiều nhất $n$ lần sửa nhãn đỉnh, ta có thể tìm được một đường tăng.

Mỗi lần sửa nhãn đỉnh, các cạnh trong cây luân phiên sẽ không rời khỏi đồ thị con đẳng thức, vì vậy ta có thể trực tiếp duy trì cây này.

Với mỗi đỉnh $v$ trong $T$, ta duy trì

$slack(v) = \min \{ lx(u) + ly(v) - w(u,v) | u\in{S} \}$.

Vì vậy có thể tính giá trị sửa nhãn $a$ trong $O(n)$:

$a = \min \{ slack(v) | v\in{T'} \}$

Khi cây luân phiên thêm một đỉnh mới vào $S$, cần $O(n)$ để cập nhật $slack(v)$. Khi sửa nhãn, cần $O(n)$ để trừ $a$ khỏi mỗi $slack(v)$. Chỉ cần cây luân phiên tìm thấy một đỉnh chưa ghép cặp là ta tìm được đường tăng.

Ban đầu ta duyệt $n$ đỉnh để tìm đường tăng. Để tìm một đường tăng, cây luân phiên cần mở rộng nhiều nhất $n$ lần, mỗi lần mở rộng cần $n$ thao tác duy trì, nên tổng độ phức tạp là $O(n^3)$.

??? note "Mã tham khảo"
    ```cpp
    template <typename T>
    struct hungarian {  // km
      int n;
      vector<int> matchx;  // đỉnh được ghép ở tập trái
      vector<int> matchy;  // đỉnh được ghép ở tập phải
      vector<int> pre;     // đỉnh trái nối với tập phải
      vector<bool> visx;   // mảng đánh dấu đã thăm cho tập trái
      vector<bool> visy;   // mảng đánh dấu đã thăm cho tập phải
      vector<T> lx;
      vector<T> ly;
      vector<vector<T>> g;
      vector<T> slack;
      T inf;
      T res;
      queue<int> q;
      int org_n;
      int org_m;
    
      hungarian(int _n, int _m) {
        org_n = _n;
        org_m = _m;
        n = max(_n, _m);
        inf = numeric_limits<T>::max();
        res = 0;
        g = vector<vector<T>>(n, vector<T>(n));
        matchx = vector<int>(n, -1);
        matchy = vector<int>(n, -1);
        pre = vector<int>(n);
        visx = vector<bool>(n);
        visy = vector<bool>(n);
        lx = vector<T>(n, -inf);
        ly = vector<T>(n);
        slack = vector<T>(n);
      }
    
      void addEdge(int u, int v, int w) {
        g[u][v] = max(w, 0);  // trọng số âm còn kém hơn không ghép, nên đặt thành 0 không ảnh hưởng
      }
    
      bool check(int v) {
        visy[v] = true;
        if (matchy[v] != -1) {
          q.push(matchy[v]);
            visx[matchy[v]] = true;  // thuộc S
          return false;
        }
          // Tìm được một đỉnh chưa ghép. Cập nhật ghép cặp; pre ghi lại đỉnh nối bằng cạnh không thuộc ghép cặp.
        while (v != -1) {
          matchy[v] = pre[v];
          swap(v, matchx[pre[v]]);
        }
        return true;
      }
    
      void bfs(int i) {
        while (!q.empty()) {
          q.pop();
        }
        q.push(i);
        visx[i] = true;
        while (true) {
          while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++) {
              if (!visy[v]) {
                T delta = lx[u] + ly[v] - g[u][v];
                if (slack[v] >= delta) {
                  pre[v] = u;
                  if (delta) {
                    slack[v] = delta;
                  } else if (check(v)) {  // delta = 0 nghĩa là cạnh có thể vào đồ thị con đẳng thức và tạo đường tăng
                                          // sau khi tìm được thì trả về và xây lại cây luân phiên
                    return;
                  }
                }
              }
            }
          }
          // Không có đường tăng; điều chỉnh nhãn.
          T a = inf;
          for (int j = 0; j < n; j++) {
            if (!visy[j]) {
              a = min(a, slack[j]);
            }
          }
          for (int j = 0; j < n; j++) {
            if (visx[j]) {  // S
              lx[j] -= a;
            }
            if (visy[j]) {  // T
              ly[j] += a;
            } else {  // T'
              slack[j] -= a;
            }
          }
          for (int j = 0; j < n; j++) {
            if (!visy[j] && slack[j] == 0 && check(j)) {
              return;
            }
          }
        }
      }
    
      void solve() {
        // Nhãn ban đầu
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            lx[i] = max(lx[i], g[i][j]);
          }
        }
    
        for (int i = 0; i < n; i++) {
          fill(slack.begin(), slack.end(), inf);
          fill(visx.begin(), visx.end(), false);
          fill(visy.begin(), visy.end(), false);
          bfs(i);
        }
    
        // custom
        for (int i = 0; i < n; i++) {
          if (g[i][matchx[i]] > 0) {
            res += g[i][matchx[i]];
          } else {
            matchx[i] = -1;
          }
        }
        cout << res << "\n";
        for (int i = 0; i < org_n; i++) {
          cout << matchx[i] + 1 << " ";
        }
        cout << "\n";
      }
    };
    ```

<span id="dynamic-hungarian-algorithm"></span>
## Thuật toán Hungarian động

Bài báo gốc: [The Dynamic Hungarian Algorithm for the Assignment Problem with Changing Costs](https://www.ri.cmu.edu/publications/the-dynamic-hungarian-algorithm-for-the-assignment-problem-with-changing-costs/)

Bài báo có mã giả rõ ràng hơn: [A Fast Dynamic Assignment Algorithm for Solving Resource Allocation Problems](https://www.researchgate.net/publication/352490780_A_Fast_Dynamic_Assignment_Algorithm_for_Solving_Resource_Allocation_Problems)

Bài OJ liên quan: [DAP](https://www.spoj.com/problems/DAP/)

???+ note "Ý tưởng thuật toán"
    1.  Sửa trọng số giữa một đỉnh $u_i$ và tất cả các đỉnh $v_j$, tức là một hàng trong ma trận trọng số.
        -   Sửa nhãn đỉnh $lx(u_i) = max(w_{ij} - v_{j}), \forall j$
        -   Xóa ghép cặp liên quan đến $u_i$
    2.  Sửa trọng số giữa tất cả các đỉnh $u_i$ và một đỉnh $v_j$, tức là một cột trong ma trận trọng số.
        -   Sửa nhãn đỉnh $ly(v_j) = max(w_{ij} - u_{i}), \forall i$
        -   Xóa ghép cặp liên quan đến $v_j$
    3.  Sửa trọng số giữa một đỉnh $u_i$ và một đỉnh $v_j$, tức là một phần tử trong ma trận trọng số.
        -   Chỉ cần thực hiện một trong hai thao tác 1 hoặc 2
    4.  Thêm một đỉnh $u_i$ hoặc một đỉnh $v_j$, tức là thêm hoặc xóa một hàng hoặc một cột trong ma trận trọng số.
        -   Thực hiện thao tác 1 hoặc 2 tương ứng. Lưu ý rằng thao tác thêm đỉnh ở đây chỉ thêm đỉnh, không gán thêm giá trị trọng số; trọng số giữa đỉnh mới và các đỉnh khác là 0.

???+ note "Chứng minh thuật toán"
    -   Gọi đồ thị ban đầu là G, nhãn đỉnh ở hai phía trái và phải lần lượt là $\alpha^{i}$ và $\beta^{j}$, và bộ nhãn khả thi là l. Khi đó $G_l$ là một đồ thị con của G, chứa các đỉnh và cạnh trong G thỏa mãn $w_{ij} = alpha_{i}+beta_{j}$.
    -   Trong phần thuật toán Hungarian ở trên, định lý 1 đã chứng minh rằng: với một bộ nhãn đỉnh khả thi, nếu đồ thị con đẳng thức của nó có ghép cặp hoàn hảo, thì ghép cặp đó là ghép cặp hoàn hảo có trọng số lớn nhất của đồ thị hai phía ban đầu.
    -   Giả sử ghép cặp tối ưu ban đầu là $M^*$. Khi có một thay đổi, ta cập nhật nhãn đỉnh khả thi theo các quy tắc trên; nhãn sau khi cập nhật được ký hiệu là $\alpha^{i^*}$ hoặc $\beta^{j^*}$. Các trường hợp xảy ra như sau:
        1.  Cả một hàng của ma trận trọng số bị sửa, giả sử đó là hàng $i^*$, tức là tất cả các cạnh của $u_{i^*}$ bị sửa. Vì vậy nhãn ban đầu của $u_{i^*}$ có thể không còn thỏa điều kiện, do ta cần $w_{i^{*}j} \leq alpha_{i^*}+beta_{j}$. Nhưng với các đỉnh $u_j$ khác, ngoài các cạnh liên quan đến $i^*$, trọng số các cạnh không thay đổi, nên nhãn của chúng vẫn hợp lệ. Do đó thuật toán sửa nhãn liên quan đến $u_{i^*}$ để bộ nhãn này trở thành một bộ nhãn khả thi.
        2.  Cả một cột của ma trận trọng số bị sửa. Lập luận tương tự cho thấy thuật toán sửa nhãn để bộ nhãn này trở thành một bộ nhãn khả thi.
        3.  Khi sửa một phần tử của ma trận trọng số, chỉ cần sửa một trong hai nhãn là có thể thỏa điều kiện nhãn.
    -   Mỗi lần ma trận trọng số bị sửa đều liên quan đến một đỉnh cụ thể; đỉnh này có thể ở phía trái hoặc phía phải, nên ta ký hiệu chung là $x$. Trong ghép cặp tối ưu ban đầu, đỉnh này được ghép với một đỉnh nào đó $y$. Mỗi thao tác sửa nhiều nhất chỉ hủy ghép cặp giữa hai đỉnh này, vì vậy chỉ cần chạy một vòng tìm kiếm của thuật toán Hungarian là ta thu được một ghép cặp mới; theo định lý 1, ghép cặp mới tìm được là tối ưu.

Đoạn mã sau được cho là mã do tác giả bài báo 2 nộp. Đoạn mã dưới đây là phiên bản tối đa hóa trọng số, còn bài báo gốc dùng tối thiểu hóa chi phí.

??? note "Mã tham khảo cho thuật toán Hungarian động"
    ```cpp
    --8<-- "docs/graph/code/graph-matching/bigraph-weight-match/bigraph-weight-match_1.cpp"
    ```

## Chuyển thành mô hình luồng chi phí

Tương tự [ghép cặp lớn nhất trong đồ thị hai phía](./bigraph-match.md), bài toán ghép cặp hai phía có trọng số lớn nhất cũng có thể chuyển thành một bài toán luồng mạng để giải.

Trước hết, thêm vào đồ thị một đỉnh nguồn và một đỉnh đích.

Nối từ nguồn đến mỗi đỉnh phía trái của đồ thị hai phía một cạnh có lưu lượng $1$ và chi phí $0$; nối từ mỗi đỉnh phía phải đến đích một cạnh có lưu lượng $1$ và chi phí $0$.

Tiếp theo, với mỗi cạnh trong đồ thị hai phía nối đỉnh phía trái $u$ và đỉnh phía phải $v$, có trọng số $w$, ta nối một cạnh từ $u$ đến $v$ với lưu lượng $1$ và chi phí $w$.

Ngoài ra, do trong ghép cặp có trọng số lớn nhất, số cạnh được ghép không nhất thiết bằng số cạnh trong ghép cặp lớn nhất, nên với mỗi đỉnh phía trái, còn cần nối thêm một cạnh đến đích với lưu lượng $1$ và chi phí $0$.

Tìm luồng cực đại có chi phí lớn nhất trên mạng này là thu được đáp án. Tương đương, có thể đổi dấu chi phí rồi dùng [luồng chi phí nhỏ nhất](../flow/min-cost.md). Khi đó lưu lượng cực đại của mạng chắc chắn bằng số đỉnh phía trái, và chi phí lớn nhất trong số các luồng cực đại tương ứng với một phương án ghép cặp có trọng số lớn nhất.

## Bài tập

??? note "[UOJ #80. Ghép cặp hai phía có trọng số lớn nhất](https://uoj.ac/problem/80)"
    Bài mẫu.
    
    ```cpp
    --8<-- "docs/graph/code/graph-matching/bigraph-weight-match/bigraph-weight-match_2.cpp"
    ```
