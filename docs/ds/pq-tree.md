author: isdanni,xyf007

PQ tree là một cấu trúc dữ liệu dựa trên cây, biểu diễn một tập các hoán vị trên một tập phần tử. Cấu trúc này được
Kellogg S. Booth và George S. Lueker phát hiện và đặt tên vào năm 1976, dùng để giải bài toán sau:

> Cho $m$ tập hợp $S_i$, cần tìm một hoán vị của $1\sim n$ sao cho các phần tử trong mỗi tập hợp đều nằm kề nhau.

PQ tree có thể được xây dựng trong thời gian $O(n+\sum|S_i|)$. Phương pháp xây dựng được giới thiệu trong bài này có độ
phức tạp thời gian $O(nm)$.

## Định nghĩa

PQ tree có ba loại nút: **nút lá**, **nút P** và **nút Q**. Nút lá biểu diễn một phần tử trong hoán vị. Nút P cho biết
các nút con của nó có thể được sắp xếp theo thứ tự bất kỳ, còn nút Q cho biết thứ tự các con của nó có thể bị đảo
ngược. Mọi nút không phải nút lá đều là một nút P hoặc một nút Q. Một nút P có ít nhất 2 con, còn một nút Q có ít nhất
3 con.

Theo định nghĩa của các nút, bản thân PQ tree biểu diễn **tất cả** các phương án hợp lệ; phép duyệt tiền thứ tự của nó
là một trong các phương án đó.

Hình dưới đây là một PQ tree.

![](https://gregable.com/2008/11/i/pq-tree.webp)  

Duyệt tiền thứ tự của cây này là $1,2,3,4,5$, biểu diễn một phương án hợp lệ. Nếu sắp xếp lại các con của nút P thành
$4,2,3$, có thể nhận được một phương án hợp lệ khác là $1,4,2,3,5$. Nếu giữ nguyên thứ tự các con của nút P và đảo
ngược thứ tự các con của nút Q, có thể nhận được phương án hợp lệ $5,3,2,4,1$.

## Xây dựng

**PQ tree dùng cách biểu diễn con - anh em.**

PQ tree được xây dựng theo kiểu tăng dần.

Trước hết, tạo một cây có gốc là P và có tổng cộng $n$ con, lần lượt là $1,2,\ldots,n$; cây này biểu diễn PQ tree khi
chưa có ràng buộc nào. Khi các ràng buộc được thêm vào, cây này được sửa dần.

Khi thêm một tập ràng buộc mới $S$, đánh dấu mọi nút lá thuộc tập này là **đen**, còn các nút lá không thuộc tập này là
**trắng**. Với mọi nút không phải lá, nếu tất cả con của nó đều đen thì cũng đánh dấu nó là đen; nếu tất cả con của nó
đều trắng thì cũng đánh dấu nó là trắng; nếu không thì đánh dấu nó là **xám**. Trong các hình bên dưới, nút đen, nút
trắng và nút xám lần lượt được biểu diễn bằng màu đen, màu xám, và nửa đen nửa xám.

Các nút trong PQ tree cần được sắp xếp theo màu.

### Phương pháp từ dưới lên

Cây con nhỏ nhất chứa tất cả các nút đen được gọi là **cây con liên quan**, và gốc của cây con liên quan (không nhất
thiết là gốc của toàn bộ cây) được gọi là **gốc liên quan**.

Quá trình thêm một ràng buộc được gọi là một lần rút gọn. Một lần rút gọn gồm hai giai đoạn: giai đoạn nổi bọt và giai
đoạn rút gọn.

#### Giai đoạn nổi bọt

Giai đoạn nổi bọt chỉ xử lý cây con liên quan. Mọi nút trong cây con liên quan được đánh dấu là đen hoặc xám, đồng thời
tính số nút con liên quan của từng nút. Để thực hiện quá trình này hiệu quả, xử lý cây con liên quan từ lá lên gốc.
Việc này cần ghi lại nút cha của mỗi nút, nhưng trong giai đoạn rút gọn, nút cha của một nút thường phải bị sửa. Để
xây dựng trong thời gian tuyến tính, chỉ các con của nút P và **con cuối cùng của nút Q** luôn ghi đúng nút cha. Với các
con khác của nút Q, giai đoạn nổi bọt dùng nút cha của con cuối cùng để cập nhật nút cha của chúng.

Khi gặp một nút ở giữa, kiểm tra xem nút anh em của nó đã có nút cha hợp lệ hay chưa. Nếu chưa, đánh dấu nó là **bị
chặn**. Nếu về sau nút anh em của nó có nút cha hợp lệ, sửa nút cha của nút này và bỏ đánh dấu. Nếu khi giai đoạn nổi
bọt kết thúc mà vẫn còn một đoạn liên tiếp các nút bị chặn (như trường hợp Q3 bên dưới), một "nút giả" không có nút cha
sẽ trở thành nút cha của khối này, rồi bị loại bỏ trong giai đoạn rút gọn.

#### Giai đoạn rút gọn

Giai đoạn rút gọn dùng một hàng đợi để xử lý các nút. Trước hết, đưa mọi nút lá nằm trong ràng buộc vào hàng đợi. Mỗi
lần lấy nút đầu hàng đợi $u$ ra và xử lý. Nếu cha của $u$ cũng là một nút trong cây con liên quan, đưa $\mathit{fa}_u$
vào hàng đợi.

Với mỗi nút $u$, xét theo từng trường hợp. Nếu không thuộc bất kỳ trường hợp nào trong số đó thì vô nghiệm.

##### Nút lá

Đánh dấu $u$ là đen.

##### Nút P

Nếu tất cả con đều đen, đánh dấu $u$ là đen.
![](https://gregable.com/2008/11/i/p1-template.png)  
![](https://gregable.com/2008/11/i/p1-replacement.png)

Nếu $u$ có cả con đen và con trắng, đồng thời $u$ là gốc liên quan, tạo một nút P mới $v$ làm gốc của tất cả các con đen của nó.
![](https://gregable.com/2008/11/i/p2-template.png)  
![](https://gregable.com/2008/11/i/p2-replacement.png)

Nếu $u$ có cả con đen và con trắng, đồng thời $u$ không phải gốc liên quan, thực hiện các thao tác sau:

-   Tạo một nút P mới $f$ làm gốc của tất cả các con đen.
-   Tạo một nút P mới $e$ làm gốc của tất cả các con trắng.
-   Nếu $e$ (và/hoặc $f$) chỉ có một con, không tạo nút mới, mà gán trực tiếp $e$ (và/hoặc $f$) thành con đó.
-   Đổi $u$ thành nút Q, đặt các con của nó là $e$ và $f$, rồi đánh dấu nó là xám.

Lưu ý rằng theo định nghĩa ở trên, nút Q có ít nhất 3 con, nên trong trường hợp này $u$ được xem là một "nút giả" và sẽ
tiếp tục được xử lý về sau.
![](https://gregable.com/2008/11/i/p3-template.png)  
![](https://gregable.com/2008/11/i/p3-replacement.png)

Nếu $u$ có một con xám $p$, đồng thời $u$ là gốc liên quan, tạo một nút P mới $v$ làm gốc của tất cả các con đen của nó.
Sau đó, đặt anh em của $v$ là con đen cuối cùng của $p$, rồi đặt $v$ làm con cuối cùng của $p$.
![](https://gregable.com/2008/11/i/p4-template.png)  
![](https://gregable.com/2008/11/i/p4-replacement.png)

Nếu $u$ có một con xám $p$, đồng thời $u$ không phải gốc liên quan, thực hiện các thao tác sau:

-   Tạo một nút P mới $f$ làm gốc của tất cả các con đen.
-   Tạo một nút P mới $e$ làm gốc của tất cả các con trắng.
-   Nếu $e$ (và/hoặc $f$) chỉ có một con, không tạo nút mới, mà gán trực tiếp $e$ (và/hoặc $f$) thành con đó.
-   Đặt anh em của $e$ là con trắng cuối cùng của $p$, rồi đặt $e$ làm con cuối cùng của $p$.
-   Đặt anh em của $f$ là con đen cuối cùng của $p$, rồi đặt $f$ làm con cuối cùng của $p$.

![](https://gregable.com/2008/11/i/p5-template.png)  
![](https://gregable.com/2008/11/i/p5-replacement.png)

Nếu $u$ có đúng hai con xám $p_1,p_2$, thực hiện các thao tác sau:

-   Tạo một nút P mới $f$ làm gốc của tất cả các con đen.
-   Nếu $f$ chỉ có một con, không tạo nút mới, mà gán trực tiếp $f$ thành con đó.
-   Đặt anh em của con đen cuối cùng của $p_1$ là $f$.
-   Đặt anh em của $f$ là con đen cuối cùng của $p_2$.
-   Đặt con cuối cùng của $p_2$ thành con trắng cuối cùng của $p_2$.

Bằng cách này, $p_2$ đã được gộp vào $p_1$.
![](https://gregable.com/2008/11/i/p6-template.png)  
![](https://gregable.com/2008/11/i/p6-replacement.png)

##### Nút Q

Nếu $u$ chỉ có con đen, đánh dấu $u$ là đen. (Hình dạng trong hình bên dưới bị sai.)
![](https://gregable.com/2008/11/i/q1-template.png)  
![](https://gregable.com/2008/11/i/q1-replacement.png)

Nếu $u$ có một con xám $p$, và mọi con có cùng màu đều xuất hiện liên tiếp, thực hiện như sau:

-   Gọi $p_f$ là con đen cuối cùng của $p$, $p_e$ là con trắng cuối cùng của $p$, $f$ là anh em đen của $p$, và $e$ là
    anh em trắng của $p$.
-   Đặt anh em của $f$ là $p_f$, và anh em của $e$ là $p_e$.
-   Nếu $p$ không có anh em trắng hoặc anh em đen, đặt con cuối cùng của $u$ thành con cuối cùng của $p$.
-   Xóa $p$.

![](https://gregable.com/2008/11/i/q2-template.png)  
![](https://gregable.com/2008/11/i/q2-replacement.png)

Nếu $u$ có đúng hai con xám $p_1,p_2$, và mọi con có cùng màu đều xuất hiện liên tiếp, chỉ cần thực hiện thao tác ở
trường hợp trước cho cả $p_1,p_2$.
![](https://gregable.com/2008/11/i/q3-template.png)  
![](https://gregable.com/2008/11/i/q3-replacement.png)

Phương pháp xây dựng này đến từ bài báo gốc, nhưng khá bất tiện khi cài đặt.

### Phương pháp từ trên xuống

Hiện nay, phần lớn các cài đặt trong OI dùng phương pháp này. Ý tưởng vẫn tương tự; các trường hợp xuất hiện bên dưới về
cơ bản đều có thể tìm thấy ở trên.

Lưu ý rằng theo quá trình tô màu ở trên, mọi nút đen và trắng đều đã thỏa mãn điều kiện, vì vậy **chỉ cần xử lý các nút
xám**.

#### Nút P

-   Nếu $u$ có nhiều hơn hai con xám, vô nghiệm.
-   Nếu $u$ chỉ có một con xám và không có con đen, xử lý đệ quy con xám đó.
-   Nếu không, trước hết xóa rỗng danh sách con của $u$, rồi thêm tất cả các con trắng vào. Tạo một nút Q mới $q_1$ và
    cho nó trở thành con của $u$. Thêm tất cả các con xám vào $q_1$. Tạo một nút P mới $p$ làm gốc của tất cả các con
    đen, rồi chèn $p$ vào giữa $q_1$. Trường hợp này tương ứng với tất cả các trường hợp nút P trong phương pháp từ dưới
    lên.

Lưu ý rằng hai nút xám sẽ được yêu cầu có toàn bộ phần trắng ở bên trái và toàn bộ phần đen ở bên phải (hoặc ngược lại).
Vì vậy, cần cài đặt một hàm tách `split`, có thể tách các điểm trong cây con này thành phần đen và phần trắng, đồng thời
giữ lại **tất cả khả năng** của các nút trong các cây con thu được sau khi tách.

#### Nút Q

-   Tìm vị trí của nút không trắng ngoài cùng bên trái và ngoài cùng bên phải, lần lượt là $l,r$. Nếu trong $[l+1,r-1]$
    có nút không đen, vô nghiệm.
-   Nếu không có nút đen và chỉ có một nút xám, xử lý đệ quy nút xám đó; nếu không, chỉ cần tách các nút ở vị trí $l$ và $r$.

#### Hàm tách

Gọi nút cần tách là $u$. Mục tiêu là tách $u$ thành một rừng mà bên trái toàn trắng, bên phải toàn đen. Nếu $u$ không
phải nút xám, trả về trực tiếp cây con đó. Chỉ cần xét trường hợp nút xám.

Nếu $u$ là nút loại P:

-   Nếu $u$ có ít nhất hai con xám, vô nghiệm.
-   Nếu không, bên trái là tất cả các con trắng, ở giữa là kết quả xử lý đệ quy con xám, và bên phải là tất cả các con
    đen. Để giữ lại tất cả khả năng, cần tạo hai nút P mới lần lượt làm gốc của các con trắng và các con đen. Trường hợp
    này tương ứng với trường hợp P4 trong phương pháp từ dưới lên.
-   Xóa $u$.

Nếu $u$ là nút loại Q:

-   Nếu cả thứ tự xuôi và thứ tự ngược đều không thỏa dạng trắng - xám - đen, vô nghiệm.
-   Nếu có ít nhất hai con xám, cũng vô nghiệm.
-   Nếu không, chỉ cần tách đệ quy con xám.
-   Xóa $u$.

Cuối cùng, xóa tất cả các nút thừa (các nút chỉ có một con).

## Cài đặt

```cpp
class PQTree {
 public:
  PQTree() {}

  void Init(int n) {
    n_ = n, rt_ = tot_ = n + 1;
    for (int i = 1; i <= n; i++) g_[rt_].emplace_back(i);
  }

  void Insert(const std::string &s) {
    s_ = s;
    Dfs0(rt_);
    Work(rt_);
    while (g_[rt_].size() == 1) rt_ = g_[rt_][0];
    Remove(rt_);
  }

  std::vector<int> ans() {
    DfsAns(rt_);
    return ans_;
  }

  ~PQTree() {}

 private:
  int n_, rt_, tot_, pool_[100001], top_, typ_[100001] /* 0-P 1-Q */,
      col_[100001] /* 0-black 1-white 2-grey */;
  std::vector<int> g_[100001], ans_;
  std::string s_;

  void Fail() {
    std::cout << "NO\n";
    std::exit(0);
  }

  int NewNode(int ty) {
    int x = top_ ? pool_[top_--] : ++tot_;
    typ_[x] = ty;
    return x;
  }

  void Delete(int u) { g_[u].clear(), pool_[++top_] = u; }

  void Dfs0(int u) {  // Lấy màu của từng nút.
    if (u >= 1 && u <= n_) {
      col_[u] = s_[u] == '1';
      return;
    }
    bool c0 = false, c1 = false;
    for (auto &&v : g_[u]) {
      Dfs0(v);
      if (col_[v]) c1 = true;
      if (col_[v] != 1) c0 = true;
    }
    if (c0 && !c1)
      col_[u] = 0;
    else if (!c0 && c1)
      col_[u] = 1;
    else
      col_[u] = 2;
  }

  bool Check(const std::vector<int> &v) {
    int p2 = -1;
    for (int i = 0; i < static_cast<int>(v.size()); i++)
      if (col_[v[i]] == 2) {
        if (p2 != -1) return false;
        p2 = i;
      }
    if (p2 == -1)
      for (int i = 0; i < static_cast<int>(v.size()); i++)
        if (col_[v[i]]) {
          p2 = i;
          break;
        }
    for (int i = 0; i < p2; i++)
      if (col_[v[i]]) return false;
    for (int i = p2 + 1; i < static_cast<int>(v.size()); i++)
      if (col_[v[i]] != 1) return false;
    return true;
  }

  std::vector<int> Split(int u) {
    if (col_[u] != 2) return {u};
    std::vector<int> ng;
    if (typ_[u]) {  // Q
      if (!Check(g_[u])) {
        std::reverse(g_[u].begin(), g_[u].end());
        if (!Check(g_[u])) Fail();
      }
      for (auto &&v : g_[u])
        if (col_[v] != 2) {
          ng.emplace_back(v);
        } else {
          auto s = Split(v);
          ng.insert(ng.end(), s.begin(), s.end());
        }
    } else {  // P
      std::vector<int> son[3];
      for (auto &&x : g_[u]) son[col_[x]].emplace_back(x);
      if (son[2].size() > 1) Fail();
      if (!son[0].empty()) {
        int n0 = NewNode(0);
        g_[n0] = son[0];
        ng.emplace_back(n0);
      }
      if (!son[2].empty()) {
        auto s = Split(son[2][0]);
        ng.insert(ng.end(), s.begin(), s.end());
      }
      if (!son[1].empty()) {
        int n1 = NewNode(0);
        g_[n1] = son[1];
        ng.emplace_back(n1);
      }
    }
    Delete(u);
    return ng;
  }

  void Work(int u) {
    if (col_[u] != 2) return;
    if (typ_[u]) {  // Q
      int l = 1e9, r = -1e9;
      for (int i = 0; i < static_cast<int>(g_[u].size()); i++)
        if (col_[g_[u][i]]) checkmin(l, i), checkmax(r, i);
      for (int i = l + 1; i < r; i++)
        if (col_[g_[u][i]] != 1) Fail();
      if (l == r && col_[g_[u][l]] == 2) {
        Work(g_[u][l]);
        return;
      }
      std::vector<int> ng;
      for (int i = 0; i < l; i++) ng.emplace_back(g_[u][i]);
      auto s = Split(g_[u][l]);
      ng.insert(ng.end(), s.begin(), s.end());
      for (int i = l + 1; i < r; i++) ng.emplace_back(g_[u][i]);
      if (l != r) {
        s = Split(g_[u][r]);
        std::reverse(s.begin(), s.end());
        ng.insert(ng.end(), s.begin(), s.end());
      }
      for (int i = r + 1; i < static_cast<int>(g_[u].size()); i++)
        ng.emplace_back(g_[u][i]);
      g_[u] = ng;
    } else {  // P
      std::vector<int> son[3];
      for (auto &&x : g_[u]) son[col_[x]].emplace_back(x);
      if (son[1].empty() && son[2].size() == 1) {
        Work(son[2][0]);
        return;
      }
      g_[u].clear();
      if (son[2].size() > 2) Fail();
      g_[u] = son[0];
      int n1 = NewNode(1);
      g_[u].emplace_back(n1);
      if (son[2].size() >= 1) {
        auto s = Split(son[2][0]);
        g_[n1].insert(g_[n1].end(), s.begin(), s.end());
      }
      if (son[1].size()) {
        int n2 = NewNode(0);
        g_[n1].emplace_back(n2);
        g_[n2] = son[1];
      }
      if (son[2].size() >= 2) {
        auto s = Split(son[2][1]);
        std::reverse(s.begin(), s.end());
        g_[n1].insert(g_[n1].end(), s.begin(), s.end());
      }
    }
  }

  void Remove(int u) {  // Xóa các nút chỉ có một con.
    for (auto &&v : g_[u]) {
      int tv = v;
      while (g_[tv].size() == 1) {
        int t = tv;
        tv = g_[tv][0];
        Delete(t);
      }
      v = tv, Remove(v);
    }
  }

  void DfsAns(int u) {
    if (u >= 1 && u <= n_) {
      ans_.emplace_back(u);
      return;
    }
    for (auto &&v : g_[u]) DfsAns(v);
  }
} T;
```

## Bài tập

-   [CF243E Matrix](https://codeforces.com/problemset/problem/243/E)
-   [CF1552I Organizing a Music Festival](https://codeforces.com/contest/1552/problem/I)

## Tài liệu tham khảo

-   Booth, Kellogg S. & Lueker, George S. (1976). "Testing for the consecutive ones property, interval graphs, and graph
    planarity using PQ-tree algorithms". *[Journal of Computer and System
    Sciences](https://en.wikipedia.org/wiki/Journal_of_Computer_and_System_Sciences)*. **13**(3): 335-379.
    [doi:10.1016/S0022-0000(76)80045-1](https://doi.org/10.1016%2FS0022-0000%2876%2980045-1).
-   [PQ Tree Algorithm and Consecutive Ones Problem](https://gregable.com/2008/11/pq-tree-algorithm.html)
-   [CF243E Matrix PQTree - RainAir's Blog](https://blog.aor.sd.cn/archives/1657/)
