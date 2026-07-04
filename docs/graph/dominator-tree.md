## Lời nói đầu

Năm 1959, khái niệm "thống trị" được Reese T. Prosser đưa ra trong [một bài báo về luồng mạng](http://portal.acm.org/ft_gateway.cfm?id=1460314&type=pdf&coll=GUIDE&dl=GUIDE&CFID=79528182&CFTOKEN=33765747), nhưng bài báo chưa đưa ra thuật toán cụ thể để giải quyết; đến năm 1969, Edward S. Lowry và C. W. Medlock mới lần đầu đề xuất [một thuật toán hiệu quả](http://portal.acm.org/ft_gateway.cfm?id=362838&type=pdf&coll=GUIDE&dl=GUIDE&CFID=79528182&CFTOKEN=33765747). Thuật toán Lengauer-Tarjan, hiện là thuật toán được sử dụng rộng rãi nhất, được Lengauer và Tarjan đề xuất vào năm 1979 trong [một bài báo](https://www.cs.princeton.edu/courses/archive/fall03/cs528/handouts/a%20fast%20algorithm%20for%20finding.pdf).

Trong giới OI, khái niệm cây thống trị được đưa vào sớm nhất qua bài [ZJOI2012 Thảm họa](https://www.luogu.com.cn/problem/P2597), khi đó còn được gọi là "cây tuyệt chủng"; Chen Sunli cũng giới thiệu thuật toán này trong luận văn đội tuyển quốc gia năm 2020.

Hiện nay cây thống trị không thật sự phổ biến trong lập trình thi đấu, và các bài tập liên quan cũng không nhiều; tuy vậy trong công nghiệp, đặc biệt là các lĩnh vực liên quan đến trình biên dịch, cây thống trị đã được ứng dụng rộng rãi.

Bài viết này sẽ giới thiệu khái niệm cây thống trị và một vài phương pháp xây dựng.

## Quan hệ thống trị

Trên một đồ thị có hướng bất kỳ, ta chọn cố định một đỉnh vào $s$. Với một đỉnh $u$, nếu mọi đường đi từ $s$ đến $u$ đều đi qua một đỉnh $v$ nào đó, ta nói $v$ **thống trị** $u$, hay $v$ là một **đỉnh thống trị** của $u$, ký hiệu $v\ dom\ u$.

Đối với các đỉnh không thể đạt tới từ $s$, việc xét quan hệ thống trị là không có ý nghĩa. Vì vậy, nếu không có ghi chú đặc biệt, bài viết này mặc định rằng từ $s$ có thể đi tới mọi đỉnh trong đồ thị.

![](images/dom-tree1.png)

Ví dụ trong đồ thị có hướng này, $2$ bị $1$ thống trị, $3$ bị $1, 2$ thống trị, $4$ bị $1, 2, 3$ thống trị, $5$ bị $1, 2$ thống trị, v.v.

### Bổ đề

Trong các bổ đề dưới đây, mặc định $u, v, w\ne s$.

**Bổ đề 1:** $s$ là đỉnh thống trị của tất cả các đỉnh; mọi đỉnh đều là đỉnh thống trị của chính nó.

**Chứng minh:** Hiển nhiên mọi đường đi từ $s$ đến $u$ đều phải đi qua hai đỉnh $s$ và $u$.

**Bổ đề 2:** Quan hệ thống trị thu được khi chỉ xét các đường đi đơn giống với quan hệ thu được khi xét tất cả các đường đi.

**Chứng minh:** Với một đường đi không đơn, giả sử $S$ là tập các đỉnh đi qua giữa hai lần xuất hiện của cùng một đỉnh. Nếu xóa các đỉnh trong $S$, ta có thể tương ứng mỗi đường đi không đơn với một đường đi đơn.

Trong $S$, các đỉnh nằm trên đường đi không đơn nhưng không nằm trên đường đi đơn chắc chắn không thể trở thành đỉnh thống trị, vì tồn tại ít nhất một đường đi đơn từ $s$ đến $u$ không chứa đỉnh đó; đồng thời, các đỉnh nằm trên cả đường đi đơn và đường đi không đơn chỉ cần được xét trên đường đi đơn.

Tóm lại, việc loại bỏ các đường đi không đơn không ảnh hưởng đến quan hệ thống trị.

**Bổ đề 3:** Nếu $u$  $dom$  $v$, $v$  $dom$  $w$, thì $u$  $dom$  $w$.

**Chứng minh:** Mọi đường đi qua $w$ chắc chắn đi qua $v$, và mọi đường đi qua $v$ chắc chắn đi qua $u$, do đó mọi đường đi qua $w$ chắc chắn đi qua $u$, tức là $u \ dom \ w$.

**Bổ đề 4:** Nếu $u \ dom \ v$, $v \ dom\ u$, thì $u=v$.

**Chứng minh:** Giả sử $u \ne v$. Khi đó mọi đường đi đến $v$ đều đã đi qua $u$, đồng thời mọi đường đi đến $u$ đều đã đi qua $v$, mâu thuẫn.

**Bổ đề 5:** Nếu $u \ne v \ne w$, $u \ dom \ w$ và $v \ dom \ w$, thì có $u \ dom \ v$ hoặc $v \ dom \ u$.

**Chứng minh:** Xét một đường đi $s \rightarrow \dots \rightarrow u \rightarrow \dots \rightarrow v \rightarrow \dots \rightarrow w$. Nếu $u$ và $v$ không có quan hệ thống trị, thì chắc chắn tồn tại một đường đi từ $s$ đến $v$ không đi qua $u$, tức là tồn tại một đường đi $s \rightarrow \dots \rightarrow v \rightarrow \dots \rightarrow w$, mâu thuẫn với $u\ dom\ w$.

### Tìm quan hệ thống trị

#### Phương pháp xóa đỉnh

Một kết luận tương đương với định nghĩa: nếu sau khi xóa một đỉnh nào đó trong đồ thị, một số đỉnh trở nên không thể đạt tới, thì đỉnh bị xóa này thống trị các đỉnh trở nên không thể đạt tới đó.

Vì vậy ta chỉ cần thử xóa từng đỉnh rồi chạy dfs, độ phức tạp của mã là $O(n^3)$. Dưới đây là phần mã cốt lõi.

```cpp
// Gia su do thi co n dinh, dinh bat dau s = 1
std::bitset<N> vis;
std::vector<int> edge[N];
std::vector<int> dom[N];

void dfs(int u, int del) {
  vis[u] = true;
  for (int v : edge[u]) {
    if (v == del or vis[v]) {
      continue;
    }
    dfs(v, del);
  }
}

void getdom() {
  for (int i = 2; i <= n; ++i) {
    vis.reset();
    dfs(1, i);
    for (int j = 1; j <= n; ++j) {
      if (!vis[j]) {
        dom[j].push_back(i);
      }
    }
  }
}
```

#### Phương pháp lặp luồng dữ liệu

Phương pháp lặp luồng dữ liệu cũng là một kiến thức không thường gặp trong OI, nên ở đây ta giới thiệu ngắn gọn trước.

Phân tích luồng dữ liệu là một khái niệm trong nguyên lý trình biên dịch, dùng để phân tích dữ liệu chảy như thế nào trên các đường thực thi của chương trình. Phương pháp lặp luồng dữ liệu là cách lập các phương trình trên các đỉnh của đồ thị luồng điều khiển của chương trình rồi liên tục lặp để giải, từ đó thu được giá trị luồng dữ liệu tại một số điểm của chương trình. Ở đây ta xem đồ thị có hướng như một đồ thị luồng điều khiển của chương trình.

Trong bài toán này, phương trình là:

$$
dom(u)=\{u\} \cup \left(\bigcap_{v\in pre(u)}{dom(v)}\right)
$$

Trong đó $pre(u)$ được định nghĩa là tập các đỉnh tiền nhiệm của $u$. Phương trình này có thể suy ra từ bổ đề 3.

Nói một cách dễ hiểu, tập các đỉnh thống trị của một đỉnh bằng giao của các tập đỉnh thống trị của tất cả các đỉnh tiền nhiệm của nó, rồi hợp thêm chính nó. Theo phương trình này, ta liên tục lặp tập đỉnh thống trị trên mỗi đỉnh cho đến khi đáp án không còn thay đổi.

Để nâng cao hiệu suất, ta mong rằng trong mỗi vòng lặp, mọi đỉnh tiền nhiệm của đỉnh đang được lặp đều đã hoàn thành vòng lặp hiện tại càng nhiều càng tốt. Vì vậy ta cần dùng thứ tự duyệt sâu để lấy thứ tự hậu tố ngược của đồ thị, rồi lặp theo thứ tự đó.

Dưới đây là một cài đặt tham khảo của phần mã cốt lõi. Ở đây cần tiền xử lý tập đỉnh tiền nhiệm của mỗi đỉnh và thứ tự hậu tố ngược của đồ thị, nhưng đó không phải nội dung chính của bài viết này nên không cung cấp cài đặt tham khảo.

```cpp
std::vector<int> pre[N];  // Cac dinh tien nhiem cua moi dinh
std::vector<int> ord;     // Thu tu hau to nguoc cua do thi
std::bitset<N> dom[N];
std::vector<int> Dom[N];

void getdom() {
  dom[1][1] = true;
  flag = true;
  while (flag) {
    flag = false;
    for (int u : ord) {
      std::bitset<N> tmp;
      tmp[u] = true;
      for (int v : pre[u]) {
        tmp &= dom[v];
      }
      if (tmp != dom[u]) {
        dom[u] = tmp;
        flag = true;
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dom[i][j]) {
        Dom[i].push_back(j);
      }
    }
  }
}
```

Dễ thấy độ phức tạp của thuật toán trên là $O(n^2)$.

## Cây thống trị

Ở phần trước ta thấy rằng, ngoài $s$ ra, một đỉnh có ít nhất hai đỉnh thống trị: $s$ và chính nó.

Trong các đỉnh thống trị của một đỉnh bất kỳ $u$, ta gọi đỉnh $v$ gần $u$ nhất sau khi loại trừ chính $u$ là đỉnh thống trị trực tiếp của $u$, ký hiệu $idom(u) = v$. Hiển nhiên, ngoài $s$ không có đỉnh thống trị trực tiếp, mỗi đỉnh đều có duy nhất một đỉnh thống trị trực tiếp.

Xét việc nối cạnh từ $idom(u)$ đến $u$ cho mỗi đỉnh $u$ khác $s$, ta thu được một đồ thị có hướng với $n$ đỉnh và $n - 1$ cạnh. Theo bổ đề 3 và bổ đề 4, ta biết quan hệ thống trị chắc chắn không tạo thành chu trình, tức là các cạnh này chắc chắn không tạo thành vòng. Vì vậy đồ thị thu được thực chất là một cây. Ta gọi cây này là **cây thống trị** của đồ thị ban đầu.

## Tìm cây thống trị

### Tìm từ dom

Xét tập đỉnh thống trị $\{s_1, s_2, \dots, s_k\}$ của một đỉnh nào đó. Khi đó chắc chắn tồn tại một đường đi $s \rightarrow \dots \rightarrow s_1 \rightarrow \dots \rightarrow s_2 \rightarrow \dots \rightarrow \dots \rightarrow s_k \rightarrow\dots \rightarrow u$. Hiển nhiên đỉnh thống trị trực tiếp của $u$ là $s_k$. Vì vậy định nghĩa của đỉnh thống trị trực tiếp tương đương với:

Với tập đỉnh thống trị $S$ của một đỉnh $u$, nếu $v \in S$ thỏa mãn $\forall w \in S\setminus\{u,v\}, w\ dom \ v$, thì $idom(u)=v$.

Vì vậy, sau khi dùng thuật toán đã nêu ở trên để thu được tập đỉnh thống trị của mỗi đỉnh, ta có thể dựa vào định nghĩa trên để dễ dàng tìm đỉnh thống trị trực tiếp của từng đỉnh, từ đó xây dựng cây thống trị. Dưới đây là mã tham khảo.

```cpp
std::bitset<N> dom[N];
std::vector<int> Dom[N];
int idom[N];

void getidom() {
  for (int u = 2; u <= n; ++u) {
    for (int v : Dom[u]) {
      std::bitset<N> tmp = (dom[v] & dom[u]) ^ dom[u];
      if (tmp.count() == 1 and tmp[u]) {
        idom[u] = v;
        break;
      }
    }
  }
  for (int u = 2; u <= n; ++u) {
    e[idom[u]].push_back(u);
  }
}
```

### Trường hợp đặc biệt trên cây

Hiển nhiên cây thống trị của một đồ thị dạng cây chính là bản thân nó.

### Trường hợp đặc biệt trên DAG

Ta nhận thấy DAG có một tính chất rất tốt: khi giải theo thứ tự topo, nghiệm đã tìm được trước đó sẽ không ảnh hưởng đến các nghiệm về sau. Ta có thể lợi dụng đặc điểm này để nhanh chóng tìm cây thống trị của DAG.

???+ warning "Nhắc nhở"
    Cần chú ý rằng DAG ở đây chỉ được có một điểm xuất phát. Nếu có nhiều điểm xuất phát, các đỉnh bị điểm xuất phát thống trị có thể xuất hiện nhiều cha trên cây thống trị, khiến quan hệ thống trị không thể được biểu diễn đơn giản bằng cây thống trị.

**Bổ đề 6:** Trên đồ thị có hướng, $v\ dom\ u$ khi và chỉ khi $\forall w \in pre(u), v\ dom \ w$.

**Chứng minh:** Trước hết chứng minh chiều đủ. Xét một đường đi bất kỳ từ $s$ đến $u$, đường đi đó chắc chắn đi qua một đỉnh $w \in pre(u)$, mà $v$ thống trị đỉnh này, nên mọi đường đi từ $s$ đến $u$ chắc chắn đi qua $v$. Do đó ta có $v \ dom \ u$.

Tiếp theo là chiều cần. Nếu $\exists w\in pre(u)$ mà $v$ không thống trị $w$, thì chắc chắn tồn tại một đường đi không qua $v$ là $s \rightarrow \cdots \rightarrow w \rightarrow \cdots \rightarrow u$, do đó $v$ không thống trị $u$.

Ta nhận thấy đỉnh thống trị của $u$ chắc chắn là tổ tiên chung của tất cả các đỉnh tiền nhiệm của nó trên cây thống trị, nên hiển nhiên đỉnh thống trị trực tiếp của $u$ là LCA của tất cả các đỉnh tiền nhiệm trên cây thống trị. Xét việc dùng nhân đôi để tìm LCA, ta có thể hỗ trợ mỗi lần thêm một đỉnh, nên thuật toán trên rõ ràng là khả thi.

Dưới đây là cài đặt tham khảo:

```cpp
std::stack<int> sta;
std::vector<int> e[N], g[N], tree[N];  // g la do thi dao cua do thi goc, tree la cay thong tri
int n, s, in[N], tpn[N], dep[N], idom[N];  // n la tong so dinh, s la dinh bat dau, in la bac vao
int fth[N][17];

void topo(int s) {
  sta.push(s);
  while (!sta.empty()) {
    int u = sta.top();
    sta.pop();
    tpn[++tot] = u;
    for (int v : e[u]) {
      --in[v];
      if (!in[v]) {
        sta.push(v);
      }
    }
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) {
    std::swap(u, v);
  }
  for (int i = 15; i >= 0; --i) {
    if (dep[fth[u][i]] >= dep[v]) {
      u = fth[u][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = 15; i >= 0; --i) {
    if (fth[u][i] != fth[v][i]) {
      u = fth[u][i];
      v = fth[v][i];
    }
  }
  return fth[u][0];
}

void build() {
  topo(s);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= 15; ++j) fth[i][j] = s;
  for (int i = 1; i <= n; ++i) {
    int u = tpn[i];
    if (g[u].size()) {
      int v = g[u][0];
      for (int j = 1, q = g[u].size(); j < q; ++j) {
        v = lca(v, g[u][j]);
      }
      tree[v].push_back(u);
      fth[u][0] = v;
      dep[u] = dep[v] + 1;
      for (int i = 1; i <= 15; ++i) {
        fth[u][i] = fth[fth[u][i - 1]][i - 1];
      }
    }
  }
}

```

### Thuật toán Lengauer-Tarjan

Thuật toán Lengauer-Tarjan là một trong những thuật toán nổi tiếng nhất để tìm cây thống trị, có thể tìm cây thống trị của một đồ thị có hướng trong độ phức tạp thời gian $O(n\alpha(n, m))$. Thuật toán này đưa vào khái niệm **bán thống trị**, rồi dùng bán thống trị để hỗ trợ tìm đỉnh thống trị trực tiếp.

#### Quy ước

Trước hết, ta xuất phát từ $s$ và chạy dfs trên đồ thị có hướng này. Các đỉnh và cạnh đi qua tạo thành một cây $T$. Ta gọi các cạnh đã đi qua là cạnh cây, các cạnh còn lại là cạnh không thuộc cây; đặt $dfn(u)$ là thứ tự đỉnh $u$ được duyệt tới; định nghĩa $u<v$ khi và chỉ khi $dfn(u) < dfn(v)$.

#### Bán thống trị

Bán thống trị của một đỉnh $u$ là đỉnh nhỏ nhất trong các đỉnh $v$ sao cho từ $v$ có một đường đi đến $u$ mà trên đường đi đó, ngoài $u, v$ ra, mọi đỉnh đều lớn hơn $u$. Nói một cách hình thức, bán thống trị $sdom(u)$ của $u$ được định nghĩa là:

$sdom(u) = \min(v|\exists v=v_0 \rightarrow v_1 \rightarrow\dots \rightarrow v_k = u, \forall 1\le i\le k - 1, v_i > u)$

Ta nhận thấy bán thống trị có một số tính chất hữu ích:

**Bổ đề 7:** Với mọi đỉnh $u$, $sdom(u) < u$.

**Chứng minh:** Theo định nghĩa, không khó để thấy cha $fa(u)$ của $u$ trên $T$ cũng thỏa mãn điều kiện trở thành bán thống trị, và $fa(u) < u$, vì vậy mọi đỉnh lớn hơn $u$ đều không thể trở thành bán thống trị của nó.

**Bổ đề 8:** Với mọi đỉnh $u$, $idom(u)$ là tổ tiên của $u$ trên $T$.

**Chứng minh:** Đường đi từ $s$ đến $u$ trên $T$ tương ứng với một đường đi trong đồ thị ban đầu, nên $idom(u)$ chắc chắn nằm trên đường đi này.

**Bổ đề 9:** Với mọi đỉnh $u$, $sdom(u)$ là tổ tiên của $u$ trên $T$.

**Chứng minh:** Giả sử $sdom(u)$ không phải là tổ tiên của $u$. Khi đó $sdom(u)$ không thể nối đến bất kỳ đỉnh nào có thứ tự $\mathrm{dfs}$ lớn hơn hoặc bằng $u$ (nếu không, đỉnh đó phải nằm trong cây con của $sdom(u)$ chứ không phải trong cây con khác), mâu thuẫn.

**Bổ đề 10:** Với mọi đỉnh $u$, $idom(u)$ là tổ tiên của $sdom(u)$.

**Chứng minh:** Xét việc đi từ $s$ đến $sdom(u)$, rồi đi theo đường đi trong định nghĩa đến $u$. Theo định nghĩa, các đỉnh trên đường đi từ $sdom(u)$ đến $u$ đều không thống trị $u$, nên $idom(u)$ chắc chắn là tổ tiên của $sdom(u)$.

**Bổ đề 11:** Với mọi cặp đỉnh $u \ne v$ sao cho $v$ là tổ tiên của $u$, hoặc $v$ là tổ tiên của $idom(u)$, hoặc $idom(u)$ là tổ tiên của $idom(v)$.

**Chứng minh:** Với mọi đỉnh $w$ nằm giữa $v$ và $idom(v)$, theo định nghĩa của đỉnh thống trị trực tiếp, chắc chắn tồn tại một đường đi từ $s$ đến $idom(v)$ rồi đến $v$ mà không đi qua $w$. Vì vậy các đỉnh $w$ này chắc chắn không phải là $idom(u)$, do đó $idom(u)$ hoặc là hậu duệ của $v$, hoặc là tổ tiên của $idom(v)$.

Từ các bổ đề trên, ta có thể thu được định lý sau:

**Định lý 1:** Bán thống trị của một đỉnh $u$ là đỉnh nhỏ nhất trong các đỉnh tiền nhiệm của nó và trong các bán thống trị của mọi tổ tiên lớn hơn $u$ trên $T$ của các đỉnh thống trị của nó. Nói một cách hình thức, $sdom(u)=\min(\{v|\exists v \rightarrow u, v < u \} \cup \{sdom(w) | w > u\ and\ \exists w \rightarrow \dots \rightarrow v \rightarrow u \})$.

**Chứng minh:** Đặt $x$ bằng vế phải của công thức trên.

Trước hết ta chứng minh $sdom(u) \le x$. Theo bổ đề 7, ta biết mệnh đề này tương đương với việc chứng minh cả hai loại lựa chọn nêu trên đều thỏa mãn điều kiện trở thành bán thống trị. Trường hợp $x$ là một đỉnh tiền nhiệm của $u$ là hiển nhiên. Với nửa sau, ta xét việc nối đường đi $x=v_0\rightarrow\dots\rightarrow v_j=w$ nêu trong định nghĩa bán thống trị với một đường đi trên $T$ thỏa mãn $\forall i\in[j, k-1], v_i\ge w > u$ là $w=v_j \rightarrow\dots\rightarrow v_k=v$, rồi nối thêm đường đi $v \rightarrow u$. Nhờ đó ta xây dựng được một đường đi thỏa mãn định nghĩa bán thống trị.

Tiếp theo ta chứng minh $sdom(u)\ge x$. Xét đường đi nêu trong định nghĩa bán thống trị từ $sdom(u)$ đến $u$: $sdom(u)=v_0\rightarrow v_1 \rightarrow\dots\rightarrow v_k=u$. Dễ thấy $k=1$ và $k > 1$ lần lượt tương ứng với hai cách lựa chọn trong định nghĩa. Nếu $k = 1$, thì tồn tại cạnh có hướng $sdom(u) \rightarrow u$, và theo bổ đề 7 ta chứng minh được điều cần chứng minh; nếu $k>1$, đặt $j$ là số nhỏ nhất thỏa mãn $j \ge 1$ và $v_j$ là tổ tiên của $v_{k-1}$ trên $T$. Do $k$ thỏa mãn điều kiện trên, một $j$ như vậy chắc chắn tồn tại.

Xét việc chứng minh $v_0 \rightarrow \dots \rightarrow v_j$ là một đường đi thỏa mãn điều kiện trở thành bán thống trị của $v_j$, tức là chứng minh $\forall i \in [1, j), v_i>v_j$. Nếu không, đặt $i$ là chỉ số sao cho $v_i < v_j$ và $v_i$ là nhỏ nhất. Theo bổ đề 11, ta biết $v_i$ là tổ tiên của $v_j$, mâu thuẫn với định nghĩa của $j$. Vì vậy $sdom(v_j)\le sdom(u)$. Tóm lại $sdom(u) \le x$, nên $x=sdom(u)$.

Theo định lý 1, ta có thể tìm bán thống trị của mỗi đỉnh. Không khó để thấy nút thắt độ phức tạp khi tính bán thống trị nằm ở trường hợp thứ hai, nên ta xét tối ưu bằng DSU có trọng số, cập nhật giá trị nhỏ nhất mỗi khi nén đường đi.

```cpp
void dfs(int u) {
  dfn[u] = ++dfc;
  pos[dfc] = u;
  for (int i = h[0][u]; i; i = e[i].x) {
    int v = e[i].v;
    if (!dfn[v]) {
      dfs(v);
      fth[v] = u;
    }
  }
}

int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  int tmp = fa[x];
  fa[x] = find(fa[x]);
  if (dfn[sdm[mn[tmp]]] < dfn[sdm[mn[x]]]) {
    mn[x] = mn[tmp];
  }
  return fa[x];
}

void getsdom() {
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    mn[i] = fa[i] = sdm[i] = i;
  }
  for (int i = dfc; i >= 2; --i) {
    int u = pos[i], res = INF;
    for (int j = h[1][u]; j; j = e[j].x) {
      int v = e[j].v;
      if (!dfn[v]) {
        continue;
      }
      find(v);
      if (dfn[v] < dfn[u]) {
        res = std::min(res, dfn[v]);
      } else {
        res = std::min(res, dfn[sdm[mn[v]]]);
      }
    }
    sdm[u] = pos[res];
    fa[u] = fth[u];
  }
}

```

#### Tìm đỉnh thống trị trực tiếp

##### Chuyển thành DAG

Nhưng ta vẫn chưa biết bán thống trị dùng để làm gì!

Xét việc thêm cạnh có hướng $sdom(u) \rightarrow u$ vào $T$ cho mỗi $u$. Theo bổ đề 9, đồ thị mới $G$ chắc chắn là đồ thị có hướng không chu trình; theo bổ đề 10, ta còn thấy việc thêm cạnh như vậy không làm thay đổi quan hệ thống trị. Vì vậy ta đã chuyển đồ thị ban đầu thành một DAG, rồi có thể dùng thuật toán ở trên để giải.

##### Tìm bằng bán thống trị

Xây cả đống đồ thị như vậy thì thật không tinh gọn!

**Định lý 2:** Với một đỉnh bất kỳ $u$, nếu mọi đỉnh $v$ trên đường đi từ $sdom(u)$ đến $u$ trên $T$ đều thỏa mãn $sdom(v)\ge sdom(u)$, thì $idom(u) =sdom(u)$.

**Chứng minh:** Theo bổ đề 10, ta biết $idom(u)$ là $sdom(u)$ hoặc tổ tiên của nó, nên chỉ cần chứng minh $sdom(u) \ dom \ u$.

Xét một đường đi bất kỳ $P$ từ $s$ đến $u$, ta cần chứng minh $sdom(u)$ chắc chắn nằm trong $P$. Đặt $v$ là đỉnh cuối cùng trong $P$ thỏa mãn $v<sdom(u)$. Nếu $v$ không tồn tại thì chắc chắn có $sdom(u)=idom(u) =s$, ngược lại đặt $w$ là điểm đầu tiên trong $P$ sau $v$ nằm trên đường đi từ $sdom(u)$ đến $u$ trong cây DFS.

Tiếp theo ta chứng minh $sdom(w)\le v <sdom(u)$. Xét đường đi từ $v$ đến $w$ trên $T$: $v = v_0 \rightarrow \dots v_k = w$. Nếu điều này không đúng, thì tồn tại $i\in[1, k- 1], v_i < w$. Khi đó chắc chắn tồn tại một $j\in [i, k - 1]$ sao cho $v_j$ là tổ tiên của $w$. Từ cách chọn $v$, ta có $sdom(u)\le v_j$, nên $v_j$ cũng nằm trên đường đi từ $sdom(u)$ đến $u$ trong cây DFS, mâu thuẫn với định nghĩa của $w$. Vì vậy $sdom(w)\le v < sdom(u)$; kết hợp với điều kiện của định lý, ta suy ra $w=sdom(u)$, tức là đường đi $P$ chứa $sdom(u)$.

**Định lý 3:** Với một đỉnh bất kỳ $u$, trong tất cả các đỉnh trên đường đi từ $sdom(u)$ đến $u$ trên $T$, đỉnh $v$ có bán thống trị nhỏ nhất chắc chắn thỏa mãn $sdom(v)\le sdom(u)$ và $idom(v) = idom(u)$.

**Chứng minh:** Vì bản thân $u$ cũng thỏa mãn điều kiện của $v$, nên $sdom(v)\le sdom(u)$.

Do $idom(u)$ là tổ tiên của $v$ trên $T$, theo bổ đề 11 ta biết $idom(u)$ cũng là tổ tiên của $idom(v)$, vì vậy chỉ cần chứng minh $idom(v)$ thống trị $u$.

Xét một đường đi bất kỳ $P$ từ $s$ đến $u$, ta cần chứng minh $sdom(u)$ chắc chắn nằm trong $P$. Đặt $x$ là đỉnh cuối cùng trong $P$ thỏa mãn $x<sdom(u)$. Nếu $x$ không tồn tại thì chắc chắn có $sdom(u)=idom(u) =s$, ngược lại đặt $y$ là điểm đầu tiên trong $P$ sau $x$ nằm trên đường đi từ $sdom(u)$ đến $u$ trong cây DFS.

Tương tự quá trình chứng minh định lý 2, ta có thể thu được $sdom(y) \le x$. Theo bổ đề 10, có $sdom(y)\le x<idom(v) \le sdom(v)$. Đến đây, từ định nghĩa của $v$, ta biết $y$ không thể là hậu duệ của $sdom(u)$; mặt khác, $y$ không thể vừa là hậu duệ của $idom(v)$ vừa là tổ tiên của $v$, nếu không thì đường đi men theo cây DFS từ $s$ đến $sdom(y)$, rồi men theo $P$ đến $y$, cuối cùng men theo cây DFS đến $v$ sẽ không đi qua $idom(v)$, mâu thuẫn với định nghĩa của đỉnh thống trị. Vì vậy $y=idom(v)$, tức là $P$ chứa $idom(v)$.

Từ hai định lý trên, ta có thể thu được quan hệ giữa $sdom(u)$ và $idom(u)$.

Đặt $v$ là một đỉnh có $sdom(v)$ nhỏ nhất trong tất cả các đỉnh nằm giữa $sdom(u)$ và $u$. Khi đó:

$$
idom(u) =
\left\{ 
\begin{aligned} 
& sdom(u), &\text{if}\ sdom(u) = sdom(v)
\\
&idom(v), &\text{otherwise}
\end{aligned}
\right.
$$

Chỉ cần sửa nhẹ mã tìm bán thống trị ở trên là được.

```cpp
struct E {
  int v, x;
} e[MAX * 4];

int h[3][MAX * 2];

int dfc, tot, n, m, u, v;
int fa[MAX], fth[MAX], pos[MAX], mn[MAX], idm[MAX], sdm[MAX], dfn[MAX],
    ans[MAX];

void add(int x, int u, int v) {
  e[++tot] = {v, h[x][u]};
  h[x][u] = tot;
}

void dfs(int u) {
  dfn[u] = ++dfc;
  pos[dfc] = u;
  for (int i = h[0][u]; i; i = e[i].x) {
    int v = e[i].v;
    if (!dfn[v]) {
      dfs(v);
      fth[v] = u;
    }
  }
}

int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  int tmp = fa[x];
  fa[x] = find(fa[x]);
  if (dfn[sdm[mn[tmp]]] < dfn[sdm[mn[x]]]) {
    mn[x] = mn[tmp];
  }
  return fa[x];
}

void tar(int st) {
  dfs(st);
  for (int i = 1; i <= n; ++i) {
    fa[i] = sdm[i] = mn[i] = i;
  }
  for (int i = dfc; i >= 2; --i) {
    int u = pos[i], res = INF;
    for (int j = h[1][u]; j; j = e[j].x) {
      int v = e[j].v;
      if (!dfn[v]) {
        continue;
      }
      find(v);
      if (dfn[v] < dfn[u]) {
        res = std::min(res, dfn[v]);
      } else {
        res = std::min(res, dfn[sdm[mn[v]]]);
      }
    }
    sdm[u] = pos[res];
    fa[u] = fth[u];
    add(2, sdm[u], u);
    u = fth[u];
    for (int j = h[2][u]; j; j = e[j].x) {
      int v = e[j].v;
      find(v);
      if (sdm[mn[v]] == u) {
        idm[v] = u;
      } else {
        idm[v] = mn[v];
      }
    }
    h[2][u] = 0;
  }
  for (int i = 2; i <= dfc; ++i) {
    int u = pos[i];
    if (idm[u] != sdm[u]) {
      idm[u] = idm[idm[u]];
    }
  }
}

```

## Bài tập ví dụ

### [Luogu P5180 [Mẫu] Cây thống trị](https://www.luogu.com.cn/problem/P5180)

Có thể chỉ cần tìm quan hệ thống trị và trong quá trình đó ghi lại mỗi đỉnh thống trị bao nhiêu đỉnh; cũng có thể xây cây thống trị rồi tìm kích thước cây con của từng đỉnh.

Ở đây đưa ra mã cho cách giải thứ hai.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/dom-tree/dom-tree_1.cpp"
    ```

### [ZJOI2012 Thảm họa](https://www.luogu.com.cn/problem/P2597)

Trên DAG, chỉ cần tìm cây thống trị rồi tính kích thước cây con của các đỉnh.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/dom-tree/dom-tree_2.cpp"
    ```
