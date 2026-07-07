## Phân trị theo đỉnh

Phân trị theo đỉnh thích hợp để xử lý các bài toán thông tin đường đi trên cây có quy mô lớn.

??? note "Ví dụ 1 [Luogu P3806 [Mẫu] Phân trị theo đỉnh 1](https://www.luogu.com.cn/problem/P3806)"
    Cho một cây có $n$ đỉnh và trọng số trên cạnh, cùng $m$ truy vấn. Mỗi truy vấn cho một giá trị $k$ và hỏi liệu có tồn tại một cặp đỉnh trên cây có khoảng cách bằng $k$ hay không.
    
    $n\le 10000,m\le 100,k\le 10000000$

Trước hết, chọn tùy ý một đỉnh làm gốc $\mathit{rt}$. Mọi đường đi nằm hoàn toàn trong cây con của nó có thể chia thành hai loại: đường đi đi qua gốc hiện tại và đường đi không đi qua gốc hiện tại. Với các đường đi đi qua gốc hiện tại, lại có thể chia thành hai loại: đường đi có gốc là một đầu mút và đường đi mà cả hai đầu mút đều không phải gốc. Loại thứ hai có thể được ghép từ hai chuỗi thuộc loại thứ nhất. Vì vậy, với gốc đang xét $\mathit{rt}$, trước tiên tính đóng góp vào đáp án của các đường đi nằm trong cây con của nó và đi qua đỉnh này, sau đó đệ quy xuống các cây con để giải các đường đi không đi qua đỉnh này.

Trong bài này, với các đường đi đi qua gốc $\mathit{rt}$, lần lượt duyệt mọi con $\mathit{ch}$ của nó, rồi lấy $\mathit{ch}$ làm gốc để tính khoảng cách từ mọi đỉnh trong cây con của $\mathit{ch}$ đến $\mathit{rt}$. Gọi khoảng cách từ đỉnh $i$ đến gốc hiện tại $\mathit{rt}$ là $\mathit{dist}_i$, và $\mathit{tf}_{d}$ biểu thị trong các cây con đã xử lý trước đó có tồn tại một đỉnh $v$ sao cho $\mathit{dist}_v=d$ hay không. Nếu một truy vấn $k$ thỏa mãn $\mathit{tf}_{k-\mathit{dist}_i}=\text{true}$, thì tồn tại một đường đi có độ dài $k$. Sau khi tính xong liệu các cạnh nối trong cây con của $\mathit{ch}$ có thể tạo thành đáp án hay không, thêm các khoảng cách mới này vào mảng $\mathit{tf}$.

Lưu ý rằng khi xóa mảng $\mathit{tf}$, không được dùng trực tiếp `memset`. Thay vào đó, đưa các vị trí $\mathit{tf}$ đã từng được sử dụng vào một hàng đợi rồi xóa chúng, như vậy mới bảo đảm độ phức tạp thời gian.

Trong quá trình phân trị theo đỉnh, ở mỗi tầng, tổng các lời gọi đệ quy xử lý mỗi đỉnh đúng một lần. Giả sử có tổng cộng $h$ tầng đệ quy, độ phức tạp thời gian là $O(hn)$.

Nếu mỗi lần chọn [trọng tâm](./tree-centroid.md) của cây con làm gốc, số tầng đệ quy được bảo đảm là nhỏ nhất, và độ phức tạp thời gian là $O(n\log n)$. Do đó, trong cộng đồng thi lập trình quốc tế, phân trị theo đỉnh cũng thường được gọi là **phân rã trọng tâm** của cây, tức centroid decomposition.

Sau khi chọn lại gốc, bắt buộc phải tính lại kích thước cây con. Nếu không, chỉ một thay đổi tưởng như rất nhỏ cũng có thể làm sai độ phức tạp thời gian hoặc khiến tính đúng đắn khó được bảo đảm.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-divide/tree-divide_1.cpp"
    ```

??? note "Ví dụ 2 [Luogu P4178 Tree](https://www.luogu.com.cn/problem/P4178)"
    Cho một cây có $n$ đỉnh và trọng số trên cạnh, cho giá trị $k$, hỏi số cặp đỉnh trên cây có khoảng cách không vượt quá $k$.
    
    $n\le 40000,k\le 20000,w_i\le 1000$

Vì cần truy vấn số cặp đỉnh có khoảng cách trên cây thuộc đoạn $[0,k]$, dùng cây đoạn để hỗ trợ duy trì và truy vấn.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-divide/tree-divide_2.cpp"
    ```

??? note "Ví dụ 3 [Luogu P2664 Trò chơi trên cây](https://www.luogu.com.cn/problem/P2664)"
    Cho một cây mà mỗi đỉnh đều có một màu. Định nghĩa $s(i,j)$ là số màu trên đường đi từ $i$ đến $j$, và $\mathit{sum}_i=\sum_{j=1}^n s(i,j)$. Tính $\mathit{sum}_i$ với mọi $1\leq i\leq n$. Với $1 \le n, c_i \le 10^5$.

Bài này kiểm tra khá sâu khả năng hiểu và áp dụng tư tưởng phân trị theo đỉnh, phù hợp làm ví dụ và bài luyện tập khó hơn về phân trị theo đỉnh.

Trước hết, cần hiểu rõ một phép chuyển đổi. Đề bài định nghĩa $\mathit{sum}_i$ là tổng số màu trên các đường đi từ $i$ đến mọi đỉnh. Tuy nhiên, nếu dùng trực tiếp cách nhìn này trong phân trị theo đỉnh thì rất khó thống kê đáp án, vì khó hợp nhất thông tin của hai cây con cùng xuất phát từ gốc hiện tại. Do đó, chuyển đổi ý nghĩa của $\mathit{sum}_i$. Với mỗi màu $j$, gọi số đường đi có một đầu mút là $i$ và chứa màu $j$ là $\mathit{cnt}_j$. Khi đó $\mathit{sum}_i$ chính là $\sum \mathit{cnt}_j$. Bước chuyển đổi này chỉ là đổi đối tượng quan sát: xét đóng góp của từng màu vào $\mathit{sum}_i$. Giá trị $\mathit{cnt}_j$ có thể xử lý trực tiếp: mỗi khi gặp một màu mới, chỉ cần cộng $\mathit{cnt}_{\mathit{col}_u}+=\mathit{size}_u$, trong đó $\mathit{size}_u$ là kích thước cây con của $u$. Điều này có nghĩa là mọi đỉnh trong cây con đó đều tạo một đóng góp theo màu này cho đáp án của $u$.

Trong quá trình phân trị theo đỉnh, chỉ cần lần lượt thống kê:

1.  Đóng góp cho gốc của các đường đi trong cây con có gốc hiện tại làm một đầu mút.
2.  Đóng góp cho mỗi đỉnh trong cây con của các đường đi có lca là gốc hiện tại.

Phần 1 dễ xử lý. Vì trong phân trị theo đỉnh, số tầng đệ quy không vượt quá $\log{n}$, ở mỗi tầng đều có thể duyệt toàn bộ cây con, nên có thể dùng trực tiếp công thức định nghĩa của $\mathit{sum}_i$ để thống kê trong quá trình duyệt cây con.

Với phần 2, giả sử một đỉnh con của gốc hiện tại $u$ là $d$, và chọn tùy ý một đỉnh $v$ trong cây con của $d$. Khi đó đáp án của $v$ có thể chia thành hai phần:

1.  Các màu đã xuất hiện trên đường đi $(u, v)$, giả sử số lượng là $\mathit{num}$. Gọi tổng kích thước của tất cả các cây con khác của $u$ ngoài $d$ là $\mathit{siz1}$. Khi đó đóng góp của các màu đã xuất hiện này vào đáp án của $v$ là $\mathit{num}\times \mathit{siz1}$.
2.  Với các màu $j$ chưa xuất hiện trên đường đi $(u, v)$, đóng góp của chúng đến từ $\mathit{cnt_j}$ của tất cả các cây con khác của $u$ ngoài $d$. Phần đáp án này là $\sum_{j \notin (u, v)} \mathit{cnt_j}$.

Trên đây là toàn bộ ý tưởng thống kê. Chi tiết cài đặt xem mã tham khảo.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-divide/tree-divide_3.cpp"
    ```

## Phân trị theo cạnh

Tương tự phân trị theo đỉnh ở trên, chọn một cạnh và chia cây thành hai phần cân bằng nhất có thể, tức làm cho $\mathit{size}$ của hai cây con được nối bởi cạnh đó càng gần nhau càng tốt. Sau đó đệ quy xử lý cây con bên trái và bên phải, đồng thời thống kê thông tin.

Tuy nhiên, cách này không ổn. Xét một đồ thị hình sao:

![Đồ thị hình sao](./images/tree-divide1.svg)

Khi dưới một đỉnh có nhiều con với $\mathit{size}$ gần nhau, độ phức tạp thời gian khi áp dụng phân trị theo cạnh là không thể chấp nhận.

Nếu đồ thị này là cây nhị phân thì có thể tránh được nhược điểm của phân trị theo cạnh trong đồ thị hình sao ở trên. Vì vậy, xét cách chuyển một cây nhiều nhánh thành cây nhị phân.

Chỉ cần dựng cây giống như cây đoạn, như hình sau:

![Dựng cây](./images/tree-divide2.svg)

Các đỉnh mới tạo ra được gán thông tin phù hợp theo yêu cầu của bài toán. Ví dụ, khi thống kê độ dài đường đi, đặt trọng số của cạnh gốc là $1$ và trọng số của cạnh mới tạo là $0$ là đủ.

Phân tích độ phức tạp cho thấy số đỉnh tăng thêm nhiều nhất là $O(n)$, nên tổng độ phức tạp là $O(n\log n)$.

Gần như mọi bài có thể làm bằng phân trị theo đỉnh đều có thể làm bằng phân trị theo cạnh, tuy hằng số khác nhau nhưng thường vẫn chấp nhận được. Vì vậy, mục này không đưa thêm ví dụ.

## Cây phân rã trọng tâm

Cây phân rã trọng tâm là một dạng cây tái cấu trúc, thu được bằng cách thay đổi hình thái của cây ban đầu để số tầng của cây ổn định ở mức $\log n$.

Nó thường được dùng để giải các bài toán có cập nhật mà không phụ thuộc vào hình thái ban đầu của cây.

### Phân tích thuật toán

Tái cấu trúc cây ban đầu bằng cách mỗi lần tìm trọng tâm theo phương pháp phân trị theo đỉnh.

Mỗi trọng tâm tìm được được nối quan hệ cha con với trọng tâm ở tầng trước, từ đó hình thành một cây có $\log n$ tầng.

Vì cây này có $\log n$ tầng, nhiều cách vét cạn vốn có độ phức tạp không hợp lý trên cây ban đầu lại có độ phức tạp đúng trên cây phân rã trọng tâm.

### Cài đặt

Có một mẹo nhỏ: mỗi lần lấy tổng kích thước $\mathit{tot}$ của tầng đệ quy trước trừ đi kích thước con nặng của đỉnh ở tầng trước, sẽ nhận được tổng kích thước của tầng hiện tại. Như vậy, việc tìm trọng tâm chỉ cần một lần DFS.

???+ note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <iostream>
    #include <vector>
    using namespace std;
    
    using IT = vector<int>::iterator;
    
    struct Edge {
      int to, nxt, val;
    
      Edge() {}
    
      Edge(int to, int nxt, int val) : to(to), nxt(nxt), val(val) {}
    } e[300010];
    
    int head[150010], cnt;
    
    void addedge(int u, int v, int val) {
      e[++cnt] = Edge(v, head[u], val);
      head[u] = cnt;
    }
    
    int siz[150010], son[150010];
    bool vis[150010];
    
    int tot, lasttot;
    int maxp, root;
    
    void getG(int now, int fa) {
      siz[now] = 1;
      son[now] = 0;
      for (int i = head[now]; i; i = e[i].nxt) {
        int vs = e[i].to;
        if (vs == fa || vis[vs]) continue;
        getG(vs, now);
        siz[now] += siz[vs];
        son[now] = max(son[now], siz[vs]);
      }
      son[now] = max(son[now], tot - siz[now]);
      if (son[now] < maxp) {
        maxp = son[now];
        root = now;
      }
    }
    
    struct Node {
      int fa;
      vector<int> anc;
      vector<int> child;
    } nd[150010];
    
    int build(int now, int ntot) {
      tot = ntot;
      maxp = 0x7f7f7f7f;
      getG(now, 0);
      int g = root;
      vis[g] = true;
      for (int i = head[g]; i; i = e[i].nxt) {
        int vs = e[i].to;
        if (vis[vs]) continue;
        int tmp = build(vs, ntot - son[vs]);
        nd[tmp].fa = now;
        nd[now].child.push_back(tmp);
      }
      return g;
    }
    
    int virtroot;
    
    int main() {
      int n;
      cin >> n;
      for (int i = 1; i < n; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        addedge(u, v, val);
        addedge(v, u, val);
      }
      virtroot = build(1, n);
    }
    ```
