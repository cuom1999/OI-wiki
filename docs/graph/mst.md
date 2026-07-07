author: Chrogeek, Enter-tainer, HeRaNO, Ir1d, Marcythm, ShadowsEpic, StudyingFather, Xeonacid, bear-good, billchenchina, diauweb, diauweb, greyqz, kawa-yoiko, ouuan, partychicken, sshwy, stevebraveman, zhouyuyang2002, renbaoshuo, Hszzzx, y-kx-b, toprise

## Định nghĩa

Trước khi đọc các nội dung dưới đây, nên đọc phần [các khái niệm liên quan đến đồ thị](./concept.md)
và [kiến thức cơ bản về cây](./tree-basic.md), đồng thời nắm các định nghĩa sau:

1.  Đồ thị con bao trùm
2.  Cây khung

**Cây khung nhỏ nhất** (Minimum Spanning Tree, MST) của một đồ thị vô hướng liên thông
là cây khung có tổng trọng số cạnh nhỏ nhất.

Lưu ý: chỉ đồ thị liên thông mới có cây khung; với đồ thị không liên thông, chỉ tồn tại rừng khung.

## Thuật toán Kruskal

Thuật toán Kruskal là một thuật toán tìm cây khung nhỏ nhất phổ biến và dễ cài đặt, do Kruskal đề xuất.
Ý tưởng cơ bản của thuật toán là thêm các cạnh theo thứ tự trọng số tăng dần;
đây là một thuật toán tham lam.

### Kiến thức cần có

[Tập hợp rời nhau](../ds/dsu.md), [tham lam](../basic/greedy.md), [lưu trữ đồ thị](./save.md).

### Cài đặt

Minh họa:

![](./images/mst-2.apng)

Mã giả:

<!--
```pseudo
\begin{algorithm}
\caption{Kruskal}
\begin{algorithmic}
\INPUT{ Các cạnh của đồ thị $e$, mỗi phần tử trong $e$ có dạng $(u, v, w)$, biểu thị có một cạnh giữa $u$ và $v$ với trọng số $w$. }
\OUTPUT Các cạnh của MST của đồ thị đầu vào
\STATE $result \gets \varnothing$
\STATE sắp xếp $e$ theo thứ tự không giảm của trọng số $w$
\FOR{mỗi $(u, v, w)$ trong $e$ đã sắp xếp}
    \IF{$u$ \AND $v$ chưa liên thông trong DSU}
        \STATE nối $u$ \AND $v$ trong DSU
        \STATE $result \gets result \bigcup (u, v, w)$
    \ENDIF
\ENDFOR
\RETURN $result$
\end{algorithmic}
\end{algorithm}
```
-->

$$
\begin{array}{ll}
1 &  \textbf{Đầu vào. } \text{Các cạnh của đồ thị } e , \text{ trong đó mỗi phần tử của } e \text{ là } (u, v, w) \\
  &  \text{ biểu thị có một cạnh giữa } u \text{ và } v \text{ với trọng số } w . \\
2 &  \textbf{Đầu ra. } \text{Các cạnh của MST của đồ thị đầu vào}.\\
3 &  \textbf{Phương pháp. } \\
4 &  result \gets \varnothing \\
5 &  \text{sắp xếp } e \text{ theo thứ tự không giảm của trọng số } w \\
6 &  \textbf{với mỗi } (u, v, w) \text{ trong } e \text{ đã sắp xếp} \\
7 &  \qquad \textbf{nếu } u \text{ và } v \text{ chưa liên thông trong DSU } \\
8 &  \qquad\qquad \text{nối } u \text{ và } v \text{ trong DSU} \\
9 &  \qquad\qquad  result \gets result\;\bigcup\ \{(u, v, w)\} \\
10 &  \textbf{trả về }  result
\end{array}
$$

Thuật toán tuy đơn giản, nhưng cần cấu trúc dữ liệu phù hợp để hỗ trợ.
Cụ thể, cần duy trì một khu rừng, truy vấn hai đỉnh có nằm trong cùng một cây hay không,
và nối hai cây lại với nhau.

Nói một cách trừu tượng hơn, cần duy trì nhiều **tập hợp**,
truy vấn hai phần tử có thuộc cùng một tập hợp hay không, và hợp nhất hai tập hợp.

DSU hỗ trợ đúng hai thao tác này: kiểm tra hai đỉnh có liên thông hay không và hợp nhất hai thành phần.

Nếu dùng thuật toán sắp xếp $O(m\log m)$ và DSU có độ phức tạp
$O(m\alpha(m, n))$ hoặc $O(m\log n)$,
thuật toán Kruskal có độ phức tạp thời gian $O(m\log m)$.

### Chứng minh

Ý tưởng rất đơn giản: bắt đầu từ cạnh có trọng số nhỏ nhất,
rồi xét lần lượt các cạnh theo thứ tự trọng số tăng dần.
Nếu thêm một cạnh sẽ tạo ra chu trình thì bỏ qua cạnh đó.
Khi đã thêm $n-1$ cạnh, ta thu được một cây khung.

Chứng minh: dùng quy nạp để chứng minh rằng ở mọi thời điểm, tập cạnh mà thuật toán Kruskal chọn đều được chứa trong một MST nào đó.

Cơ sở: khi thuật toán vừa bắt đầu, mệnh đề đúng vì cây khung nhỏ nhất tồn tại.

Bước quy nạp: giả sử ở một thời điểm nào đó mệnh đề đúng, tập cạnh hiện tại là $F$,
và gọi $T$ là một MST chứa $F$.
Xét cạnh tiếp theo được thuật toán thêm vào, ký hiệu là $e$.

Nếu $e$ thuộc $T$, mệnh đề đúng.

Ngược lại, $T+e$ tạo ra một chu trình.
Xét một cạnh khác $f$ trên chu trình này mà không thuộc $F$; cạnh này luôn tồn tại.

Trước hết, trọng số của $f$ không thể nhỏ hơn trọng số của $e$, vì nếu không $f$ đã được chọn trước $e$.

Tiếp theo, trọng số của $f$ không thể lớn hơn trọng số của $e$, vì nếu không $T+e-f$ sẽ là một cây khung tốt hơn $T$.

Do đó, $T+e-f$ chứa $F$ và cũng là một cây khung nhỏ nhất, nên bước quy nạp được chứng minh.

### Bài tập mẫu

???+ note "[Luogu P1195 Bầu trời của Pocket](https://www.luogu.com.cn/problem/P1195)"
    Có $n$ đám mây. Cần nối chúng thành $k$ cụm kẹo bông.
    Nối đám mây $X_i$ với đám mây $Y_i$ tốn chi phí $L_i$.
    Hãy tìm chi phí nhỏ nhất.

??? note "Mã cho bài tập mẫu"
    === "C++"
        ```cpp
        --8<-- "docs/graph/code/mst/mst_3.cpp"
        ```

    === "Python"
        ```python
        --8<-- "docs/graph/code/mst/mst_3.py"
        ```

    === "Java"
        ```java
        --8<-- "docs/graph/code/mst/mst_3.java"
        ```

## Thuật toán Prim

Thuật toán Prim là một thuật toán cây khung nhỏ nhất phổ biến khác và cũng dễ cài đặt.
Khác với Kruskal, thuật toán bắt đầu từ một đỉnh rồi liên tục thêm đỉnh mới vào cây hiện tại.

### Cài đặt

Minh họa:

![](./images/mst-3.apng)

Cụ thể, mỗi lần chọn một đỉnh chưa được thêm có khoảng cách nhỏ nhất đến cây hiện tại,
rồi dùng các cạnh kề với đỉnh này để cập nhật khoảng cách của các đỉnh khác.

Quá trình này giống thuật toán Dijkstra:
mỗi lần cần tìm đỉnh có khoảng cách nhỏ nhất, có thể tìm bằng vét cạn hoặc duy trì bằng đống.

Cách tối ưu bằng đống tương tự tối ưu bằng đống của Dijkstra.
Tuy nhiên, nếu dùng đống nhị phân hoặc các loại đống không hỗ trợ thao tác decrease-key trong $O(1)$,
độ phức tạp sẽ không tốt hơn Kruskal và hằng số cũng lớn hơn.
Vì vậy, trong trường hợp thông thường thường chọn Kruskal.
Trên đồ thị dày, đặc biệt là đồ thị đầy đủ, độ phức tạp của Prim vét cạn tốt hơn Kruskal,
nhưng khi chạy thực tế chưa chắc nhanh hơn.

Vét cạn: $O(n^2+m)$.

Đống nhị phân: $O((n+m) \log n)$.

Đống Fibonacci: $O(n \log n + m)$.

Mã giả:

$$
\begin{array}{ll}
1 &  \textbf{Đầu vào. } \text{Tập đỉnh của đồ thị }V\text{; hàm }g(u, v)\text{ biểu thị}\\
  &  \text{trọng số của cạnh }(u, v)\text{; hàm }adj(v)\text{ biểu thị}\\
  &  \text{các đỉnh kề với }v.\\
2 &  \textbf{Đầu ra. } \text{Tổng trọng số của MST của đồ thị đầu vào.} \\
3 &  \textbf{Phương pháp.} \\
4 &  result \gets 0 \\
5 & \text{chọn một đỉnh bất kỳ trong }V\text{ làm }root \\
6 &  dis(root)\gets 0 \\
7 &  \textbf{với mỗi } \text{đỉnh }v\in(V-\{root\}) \\
8 &  \qquad  dis(v)\gets\infty \\
9 &  rest\gets V \\
10 &  \textbf{trong khi }  rest\ne\varnothing \\
11 &  \qquad cur\gets \text{đỉnh có }dis\text{ nhỏ nhất trong }rest \\
12 &  \qquad  result\gets result+dis(cur) \\
13 &  \qquad  rest\gets rest-\{cur\} \\
14 &  \qquad  \textbf{với mỗi }\text{đỉnh }v\in adj(cur) \\
15 &  \qquad\qquad  dis(v)\gets\min(dis(v), g(cur, v)) \\
16 &  \textbf{trả về }  result
\end{array}
$$

Lưu ý: đoạn mã trên chỉ tính tổng trọng số của cây khung nhỏ nhất. Nếu cần in phương án, phải ghi lại mỗi giá trị $dis$ của từng đỉnh đại diện cho cạnh nào.

??? note "Cài đặt mã"
    ```cpp
    // Thuật toán Prim tối ưu bằng đống nhị phân.
    #include <cstring>
    #include <iostream>
    #include <queue>
    using namespace std;
    constexpr int N = 5050, M = 2e5 + 10;

    struct E {
      int v, w, x;
    } e[M * 2];

    int n, m, h[N], cnte;

    void adde(int u, int v, int w) { e[++cnte] = E{v, w, h[u]}, h[u] = cnte; }

    struct S {
      int u, d;
    };

    bool operator<(const S &x, const S &y) { return x.d > y.d; }

    priority_queue<S> q;
    int dis[N];
    bool vis[N];

    int res = 0, cnt = 0;

    void Prim() {
      memset(dis, 0x3f, sizeof(dis));
      dis[1] = 0;
      q.push({1, 0});
      while (!q.empty()) {
        if (cnt >= n) break;
        int u = q.top().u, d = q.top().d;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        ++cnt;
        res += d;
        for (int i = h[u]; i; i = e[i].x) {
          int v = e[i].v, w = e[i].w;
          if (w < dis[v]) {
            dis[v] = w, q.push({v, w});
          }
        }
      }
    }

    int main() {
      cin >> n >> m;
      for (int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w, adde(u, v, w), adde(v, u, w);
      }
      Prim();
      if (cnt == n)
        cout << res;
      else
        cout << "No MST.";
      return 0;
    }
    ```

### Chứng minh

Bắt đầu từ một đỉnh bất kỳ, chia các đỉnh thành hai loại: đã được thêm và chưa được thêm.

Mỗi lần, trong các đỉnh chưa được thêm, tìm đỉnh có giá trị nhỏ nhất của cạnh nhẹ nhất nối nó với một đỉnh đã được thêm.

Sau đó thêm đỉnh này vào, đồng thời nối cạnh có trọng số nhỏ nhất đó.

Lặp lại $n-1$ lần là đủ.

Chứng minh: vẫn chứng minh rằng ở mỗi bước, tồn tại một cây khung nhỏ nhất chứa tập cạnh đã chọn.

Cơ sở: khi chỉ có một đỉnh, mệnh đề đúng.

Bước quy nạp: nếu một bước nào đó mệnh đề đúng, tập cạnh hiện tại là $F$ và thuộc về MST $T$; tiếp theo thêm cạnh $e$.

Nếu $e$ thuộc $T$, mệnh đề đúng.

Ngược lại, xét trong $T+e$ một cạnh khác $f$ trên chu trình mà có thể thêm vào tập cạnh hiện tại.

Trước hết, trọng số của $f$ không nhỏ hơn trọng số của $e$, nếu không $f$ đã được chọn thay vì $e$.

Tiếp theo, trọng số của $f$ không lớn hơn trọng số của $e$, nếu không $T+e-f$ sẽ là một cây khung nhỏ hơn.

Vì vậy, $e$ và $f$ có trọng số bằng nhau, $T+e-f$ cũng là một cây khung nhỏ nhất và chứa $F$.

## Thuật toán Boruvka

Tiếp theo là một thuật toán khác để tìm cây khung nhỏ nhất: thuật toán Boruvka.
Ý tưởng của thuật toán này có thể xem là sự kết hợp của Kruskal và Prim.
Nó có thể dùng để tìm rừng khung nhỏ nhất của đồ thị vô hướng.
Với đồ thị vô hướng liên thông, rừng đó chính là cây khung nhỏ nhất.

Trong các bài toán mà cạnh có nhiều tính chất đặc biệt, thuật toán Boruvka có lợi thế.
Một ví dụ là bài toán trên đồ thị đầy đủ [CF888G](https://codeforces.com/problemset/problem/888/G).

Để mô tả thuật toán này, cần đưa vào một số định nghĩa:

1.  Gọi $E'$ là tập cạnh của rừng khung nhỏ nhất đang được xây dựng.
    Trong quá trình thuật toán chạy, các cạnh sẽ dần được thêm vào $E'$.
    Một **thành phần liên thông** là một tập đỉnh $V'\subseteq V$ sao cho với hai đỉnh bất kỳ $u$, $v$ trong tập này,
    chúng liên thông với nhau trên đồ thị con được tạo bởi các cạnh trong $E'$.
2.  **Cạnh nhỏ nhất** của một thành phần liên thông là cạnh có trọng số nhỏ nhất trong số các cạnh nối thành phần đó
    với các thành phần liên thông khác.

Ban đầu, $E'=\varnothing$, mỗi đỉnh là một thành phần liên thông riêng:

1.  Tính thành phần liên thông của mỗi đỉnh.
    Đặt trạng thái cạnh nhỏ nhất của mỗi thành phần là "không có".
2.  Duyệt mỗi cạnh $(u, v)$.
    Nếu $u$ và $v$ không nằm trong cùng một thành phần liên thông,
    dùng trọng số cạnh này để cập nhật cạnh nhỏ nhất của thành phần chứa $u$ và thành phần chứa $v$.
3.  Nếu tất cả thành phần liên thông đều không có cạnh nhỏ nhất, thuật toán kết thúc;
    khi đó $E'$ là tập cạnh của rừng khung nhỏ nhất của đồ thị ban đầu.
    Ngược lại, thêm cạnh nhỏ nhất của mỗi thành phần có cạnh nhỏ nhất vào $E'$, rồi quay về bước một.

Dưới đây là một ví dụ bằng ảnh động; nguồn ảnh từ [Wikipedia](https://en.wikipedia.org/wiki/Bor%C5%AFvka%27s_algorithm):

![Ảnh động minh họa thuật toán Boruvka](./images/mst-1.apng)

Khi đồ thị ban đầu liên thông, sau mỗi vòng lặp số thành phần liên thông giảm ít nhất một nửa,
nên thuật toán chỉ lặp không quá $O(\log V)$ lần.
Khi đồ thị ban đầu không liên thông, bài toán tương đương với nhiều bài toán con.
Vì vậy độ phức tạp của thuật toán là $O(E\log V)$.
Mã giả dưới đây được sửa từ [Wikipedia](https://en.wikipedia.org/wiki/Bor%C5%AFvka%27s_algorithm):

$$
\begin{array}{ll}
1 &  \textbf{Đầu vào. } \text{Một đồ thị }G\text{ có các cạnh mang trọng số phân biệt. } \\
2 &  \textbf{Đầu ra. } \text{Rừng khung nhỏ nhất của }G .  \\
3 &  \textbf{Phương pháp. }  \\
4 & \text{Khởi tạo một rừng }F\text{ gồm các cây một đỉnh} \\
5 &  \textbf{lặp vô hạn} \\
6 &  \qquad \text{Tìm các thành phần của }F\text{ và gán nhãn thành phần cho mỗi đỉnh của }G \\
7 &  \qquad \text{Khởi tạo cạnh rẻ nhất của mỗi thành phần là "không có"} \\
8 &  \qquad  \textbf{với mỗi } \text{cạnh }(u, v)\text{ của }G  \\
9 &  \qquad\qquad  \textbf{nếu }  u\text{ và }v\text{ có nhãn thành phần khác nhau} \\
10 &  \qquad\qquad\qquad  \textbf{nếu }  (u, v)\text{ rẻ hơn cạnh rẻ nhất của thành phần chứa }u  \\
11 &  \qquad\qquad\qquad\qquad\text{ Đặt }(u, v)\text{ làm cạnh rẻ nhất của thành phần chứa }u \\
12 &  \qquad\qquad\qquad  \textbf{nếu }  (u, v)\text{ rẻ hơn cạnh rẻ nhất của thành phần chứa }v  \\
13 &  \qquad\qquad\qquad\qquad\text{ Đặt }(u, v)\text{ làm cạnh rẻ nhất của thành phần chứa }v  \\
14 &  \qquad  \textbf{nếu }\text{ cạnh rẻ nhất của mọi thành phần đều là "không có"} \\
15 &  \qquad\qquad  \textbf{trả về }  F \\
16 &  \qquad  \textbf{với mỗi }\text{ thành phần có cạnh rẻ nhất khác "không có"} \\
17 &  \qquad\qquad\text{ Thêm cạnh rẻ nhất của nó vào }F \\
\end{array}
$$

Cần lưu ý rằng phép so sánh giữa các cạnh thường cần khóa phụ thứ hai, chẳng hạn sắp xếp theo chỉ số, để phân định thứ tự khi các cạnh có cùng trọng số.

## Bài tập

-   [HAOI2006 Khỉ thông minh](https://www.luogu.com.cn/problem/P2504)
-   [SCOI2005 Thành phố bận rộn](https://loj.ac/problem/2149)

## Tính duy nhất của cây khung nhỏ nhất

Xét tính duy nhất của cây khung nhỏ nhất.
Nếu một cạnh **không nằm trong cây khung nhỏ nhất** có thể thay thế một cạnh khác
**có cùng trọng số và nằm trong cây khung nhỏ nhất**,
thì cây khung nhỏ nhất này không duy nhất.

Với thuật toán Kruskal, chỉ cần tính số cạnh có trọng số hiện tại có thể được thêm
và số cạnh thực sự được thêm.
Nếu hai giá trị này khác nhau, các cạnh cùng trọng số hiện tại cùng với các cạnh trước đó đã tạo ra một chu trình.
Chu trình này có ít nhất hai cạnh mang trọng số hiện tại; nếu không, theo DSU cạnh đó không thể được thêm.
Khi đó cây khung nhỏ nhất không duy nhất.

Để tìm các cạnh có trọng số bằng cạnh hiện tại, chỉ cần ghi lại hai con trỏ đầu và cuối của đoạn cạnh cùng trọng số.
Có thể dùng hàng đợi đơn điệu để xử lý phần này trong độ phức tạp $O(\alpha(m))$ với $m$ là số cạnh,
gần như bằng thời gian của thuật toán gốc.

??? note "Bài tập mẫu: [POJ 1679](http://poj.org/problem?id=1679)"
    ```cpp
    --8<-- "docs/graph/code/mst/mst_1.cpp"
    ```

## Cây khung nhỏ thứ hai

### Cây khung nhỏ thứ hai không nghiêm ngặt

#### Định nghĩa

Trong đồ thị vô hướng, đây là cây khung khác với cây khung nhỏ nhất đang xét
và có tổng trọng số nhỏ nhất trong số các cây khung có tổng trọng số
**lớn hơn hoặc bằng** tổng trọng số của cây khung nhỏ nhất.

#### Cách giải

-   Tìm cây khung nhỏ nhất $T$ của đồ thị vô hướng, gọi tổng trọng số của nó là $M$
-   Duyệt mỗi cạnh chưa được chọn $e=(u,v,w)$.
    Tìm cạnh có trọng số lớn nhất $e'=(s,t,w')$ trên đường đi từ $u$ đến $v$ trong $T$.
    Khi thay $e'$ bằng $e$ trong $T$, thu được một cây khung $T'$ có tổng trọng số $M'=M+w-w'$.
-   Lấy giá trị nhỏ nhất trong tất cả đáp án $M'$ thu được từ các phép thay thế

Làm thế nào để tìm trọng số cạnh lớn nhất trên đường đi giữa $u$ và $v$?

Có thể dùng kỹ thuật nhảy nhị phân để duy trì thông tin này:
tiền xử lý tổ tiên cấp $2^i$ của mỗi nút và trọng số cạnh lớn nhất trên đường đi
từ nút đó đến tổ tiên cấp $2^i$ của nó.
Khi tìm LCA bằng nhảy nhị phân, có thể lấy trực tiếp giá trị này.

### Cây khung nhỏ thứ hai nghiêm ngặt

#### Định nghĩa

Trong đồ thị vô hướng, đây là cây khung có tổng trọng số nhỏ nhất trong số các cây khung có tổng trọng số **nghiêm ngặt lớn hơn** tổng trọng số của cây khung nhỏ nhất.

#### Cách giải

Xét lại quá trình tìm cây khung nhỏ thứ hai không nghiêm ngặt ở trên:
tại sao đáp án thu được có thể không nghiêm ngặt?

Vì cây khung nhỏ nhất bảo đảm rằng trong cây khung,
trọng số lớn nhất trên đường đi từ $u$ đến $v$ **không lớn hơn**
trọng số lớn nhất trên bất kỳ đường đi nào khác từ $u$ đến $v$.
Nói cách khác, nếu cạnh dùng để thay thế có trọng số bằng cạnh bị thay thế trong cây khung ban đầu,
cây khung nhỏ thứ hai thu được có tổng trọng số bằng cây khung nhỏ nhất.

Cách xử lý là: khi duy trì trọng số cạnh lớn nhất trên đường đi đến tổ tiên cấp $2^i$,
đồng thời duy trì **trọng số cạnh lớn thứ hai nghiêm ngặt**.
Khi trọng số của cạnh dùng để thay thế bằng trọng số lớn nhất trên đường đi trong cây khung ban đầu,
hãy thay bằng giá trị lớn thứ hai nghiêm ngặt.

Quá trình này có thể giải bằng nhảy nhị phân, với độ phức tạp $O(m \log m)$.

??? note "Cài đặt mã"
    ```cpp
    #include <algorithm>
    #include <iostream>

    constexpr int INF = 0x3fffffff;
    constexpr long long INF64 = 0x3fffffffffffffffLL;

    struct Edge {
      int u, v, val;

      bool operator<(const Edge &other) const { return val < other.val; }
    };

    Edge e[300010];
    bool used[300010];

    int n, m;
    long long sum;

    class Tr {
     private:
      struct Edge {
        int to, nxt, val;
      } e[600010];

      int cnt, head[100010];

      int pnt[100010][22];
      int dpth[100010];
      // Cạnh có trọng số lớn nhất trên đường đi đến tổ tiên
      int maxx[100010][22];
      // Cạnh có trọng số lớn thứ hai trên đường đi đến tổ tiên; nếu không tồn tại thì là -INF
      int minn[100010][22];

     public:
      void addedge(int u, int v, int val) {
        e[++cnt] = Edge{v, head[u], val};
        head[u] = cnt;
      }

      void insedge(int u, int v, int val) {
        addedge(u, v, val);
        addedge(v, u, val);
      }

      void dfs(int now, int fa) {
        dpth[now] = dpth[fa] + 1;
        pnt[now][0] = fa;
        minn[now][0] = -INF;
        for (int i = 1; (1 << i) <= dpth[now]; i++) {
          pnt[now][i] = pnt[pnt[now][i - 1]][i - 1];
          int kk[4] = {maxx[now][i - 1], maxx[pnt[now][i - 1]][i - 1],
                       minn[now][i - 1], minn[pnt[now][i - 1]][i - 1]};
          // Lấy giá trị lớn nhất trong bốn giá trị
          std::sort(kk, kk + 4);
          maxx[now][i] = kk[3];
          // Lấy giá trị lớn thứ hai nghiêm ngặt
          int ptr = 2;
          while (ptr >= 0 && kk[ptr] == kk[3]) ptr--;
          minn[now][i] = (ptr == -1 ? -INF : kk[ptr]);
        }

        for (int i = head[now]; i; i = e[i].nxt) {
          if (e[i].to != fa) {
            maxx[e[i].to][0] = e[i].val;
            dfs(e[i].to, now);
          }
        }
      }

      int lca(int a, int b) {
        if (dpth[a] < dpth[b]) std::swap(a, b);

        for (int i = 21; i >= 0; i--)
          if (dpth[pnt[a][i]] >= dpth[b]) a = pnt[a][i];

        if (a == b) return a;

        for (int i = 21; i >= 0; i--) {
          if (pnt[a][i] != pnt[b][i]) {
            a = pnt[a][i];
            b = pnt[b][i];
          }
        }
        return pnt[a][0];
      }

      int query(int a, int b, int val) {
        int res = -INF;
        for (int i = 21; i >= 0; i--) {
          if (dpth[pnt[a][i]] >= dpth[b]) {
            if (val != maxx[a][i])
              res = std::max(res, maxx[a][i]);
            else
              res = std::max(res, minn[a][i]);
            a = pnt[a][i];
          }
        }
        return res;
      }
    } tr;

    int fa[100010];

    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

    void Kruskal() {
      int tot = 0;
      std::sort(e + 1, e + m + 1);
      for (int i = 1; i <= n; i++) fa[i] = i;

      for (int i = 1; i <= m; i++) {
        int a = find(e[i].u);
        int b = find(e[i].v);
        if (a != b) {
          fa[a] = b;
          tot++;
          tr.insedge(e[i].u, e[i].v, e[i].val);
          sum += e[i].val;
          used[i] = true;
        }
        if (tot == n - 1) break;
      }
    }

    int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);

      std::cin >> n >> m;
      for (int i = 1; i <= m; i++) {
        int u, v, val;
        std::cin >> u >> v >> val;
        e[i] = Edge{u, v, val};
      }

      Kruskal();
      long long ans = INF64;
      tr.dfs(1, 0);

      for (int i = 1; i <= m; i++) {
        if (!used[i]) {
          int _lca = tr.lca(e[i].u, e[i].v);
          // Tìm cạnh có trọng số lớn nhất trên đường đi và khác e[i].val
          long long tmpa = tr.query(e[i].u, _lca, e[i].val);
          long long tmpb = tr.query(e[i].v, _lca, e[i].val);
          // Cạnh như vậy có thể không tồn tại; chỉ cập nhật đáp án khi nó tồn tại
          if (std::max(tmpa, tmpb) > -INF)
            ans = std::min(ans, sum - std::max(tmpa, tmpb) + e[i].val);
        }
      }
      // In -1 khi không tồn tại cây khung nhỏ thứ hai
      std::cout << (ans == INF64 ? -1 : ans) << '\n';
      return 0;
    }
    ```

## Cây khung nút cổ chai

### Định nghĩa

Cây khung nút cổ chai của đồ thị vô hướng $G$ là một cây khung
sao cho cạnh có trọng số lớn nhất trong cây là nhỏ nhất trong tất cả các cây khung của $G$.

### Tính chất

**Cây khung nhỏ nhất là điều kiện đủ nhưng không cần của cây khung nút cổ chai.**
Nghĩa là cây khung nhỏ nhất luôn là cây khung nút cổ chai,
nhưng cây khung nút cổ chai không bắt buộc là cây khung nhỏ nhất.

Chứng minh mệnh đề "cây khung nhỏ nhất luôn là cây khung nút cổ chai" bằng phản chứng.
Giả sử trọng số cạnh lớn nhất trong cây khung nhỏ nhất là $w$.
Nếu cây khung nhỏ nhất không phải cây khung nút cổ chai,
thì mọi cạnh trong một cây khung nút cổ chai đều có trọng số nhỏ hơn $w$.
Xóa cạnh dài nhất trong cây khung nhỏ nhất ban đầu, rồi dùng một cạnh trong cây khung nút cổ chai
để nối hai cây tạo thành sau khi xóa cạnh đó.
Cây khung mới thu được sẽ có tổng trọng số nhỏ hơn cây khung nhỏ nhất ban đầu, tạo ra mâu thuẫn.

### Bài tập mẫu

???+ note "POJ 2395 Out of Hay"
    Cho $n$ nông trại và $m$ cạnh, các nông trại được đánh số từ $1$ đến $n$.
    Có một người cần đi từ nông trại số $1$ đến các nông trại khác.
    Tìm khối lượng nước tối đa người đó cần mang theo trên hành trình.
    Lưu ý rằng mỗi khi đến một nông trại, người đó có thể bổ sung nước,
    và tổng độ dài đường đi phải nhỏ nhất.
    Bài toán yêu cầu cạnh lớn nhất của cây nút cổ chai, có thể giải bằng cách tìm cây khung nhỏ nhất.

## Đường đi nút cổ chai nhỏ nhất

### Định nghĩa

Trong đồ thị vô hướng $G$, đường đi nút cổ chai nhỏ nhất từ $x$ đến $y$
là một lớp các đường đi đơn sao cho cạnh có trọng số lớn nhất trên đường đi đó
là nhỏ nhất trong tất cả các đường đi đơn từ $x$ đến $y$.

### Tính chất

Theo định nghĩa cây khung nhỏ nhất, trọng số lớn nhất trên đường đi nút cổ chai nhỏ nhất từ $x$ đến $y$
bằng trọng số lớn nhất trên đường đi từ $x$ đến $y$ trong cây khung nhỏ nhất.
Cây khung nhỏ nhất có thể không duy nhất, nhưng với mọi cây khung nhỏ nhất,
trọng số lớn nhất trên đường đi từ $x$ đến $y$ đều bằng nhau và đều là giá trị nhỏ nhất.
Nói cách khác, đường đi từ $x$ đến $y$ trên mọi cây khung nhỏ nhất đều là đường đi nút cổ chai nhỏ nhất.

Tuy nhiên, không phải mọi đường đi nút cổ chai nhỏ nhất đều có một cây khung nhỏ nhất sao cho nó là đường đi đơn từ $x$ đến $y$ trên cây.

Ví dụ trong hình sau:

![](./images/mst5.png)

Từ $1$ đến $4$ có hai đường đi nút cổ chai nhỏ nhất sau: $1-2-3-4$ và $1-3-4$.

Tuy nhiên, cạnh $1-2$ sẽ không xuất hiện trong bất kỳ cây khung nhỏ nhất nào.

### Ứng dụng

Vì đường đi nút cổ chai nhỏ nhất không duy nhất, thông thường truy vấn sẽ hỏi trọng số lớn nhất trên đường đi nút cổ chai nhỏ nhất.

Nói cách khác, cần tìm giá trị lớn nhất trên đường đi trong cây khung nhỏ nhất.

Binary lifting và phân tách nặng-nhẹ đều có thể xử lý việc này; phần này không trình bày thêm.

## Cây tái cấu trúc Kruskal

### Định nghĩa

Trong quá trình chạy Kruskal, các cạnh được thêm theo thứ tự trọng số tăng dần.
Phần này vẫn dùng đúng thứ tự đó.

Trước hết tạo $n$ tập hợp, mỗi tập hợp có đúng một nút, và trọng số đỉnh bằng $0$.

Mỗi lần thêm cạnh sẽ hợp nhất hai tập hợp.
Ta tạo một nút mới, đặt trọng số đỉnh của nó bằng trọng số cạnh vừa thêm,
đồng thời đặt gốc của hai tập hợp lần lượt làm con trái và con phải của nút mới.
Sau đó hợp nhất hai tập hợp và nút mới thành một tập hợp, rồi đặt nút mới làm gốc.

Sau $n-1$ vòng, thu được một cây nhị phân có đúng $n$ lá,
và mỗi nút không phải lá đều có đúng hai con.
Cây này được gọi là cây tái cấu trúc Kruskal.

Ví dụ:

![](./images/mst5.png)

Cây tái cấu trúc Kruskal của hình này như sau:

![](./images/mst6.png)

### Tính chất

Trong đồ thị ban đầu, giá trị nhỏ nhất có thể của trọng số cạnh lớn nhất trên một đường đi đơn giữa hai đỉnh
bằng trọng số cạnh lớn nhất trên đường đi giữa hai đỉnh đó trong cây khung nhỏ nhất,
và cũng bằng trọng số của LCA của hai đỉnh trong cây tái cấu trúc Kruskal.

Nói cách khác, mọi đỉnh $y$ sao cho giá trị nhỏ nhất của trọng số cạnh lớn nhất
trên đường đi đơn từ $x$ đến $y$ không vượt quá $val$
đều nằm trong một cây con nào đó của cây tái cấu trúc Kruskal.
Tập đỉnh này đúng bằng toàn bộ các lá của cây con đó.

Tìm trên cây tái cấu trúc Kruskal nút nông nhất trên đường từ $x$ đến gốc có trọng số $\leq val$.
Đây chính là gốc của cây con chứa tất cả các nút thỏa điều kiện.

Nếu cần tìm giá trị lớn nhất của trọng số cạnh nhỏ nhất trên mọi đường đi đơn giữa hai đỉnh trong đồ thị ban đầu,
thì khi chạy Kruskal, hãy thêm cạnh theo thứ tự trọng số giảm dần.

??? note "[LOJ 137 Đường đi cổ chai nhỏ nhất, phiên bản nâng cao](https://loj.ac/problem/137)"
    ```cpp
    --8<-- "docs/graph/code/mst/mst_2.cpp"
    ```

??? note "[NOI 2018 Hành trình trở về](https://uoj.ac/problem/393)"
    Trước hết tiền xử lý đường đi ngắn nhất từ mỗi đỉnh đến nút gốc.

    Xây dựng cây khung lớn nhất theo độ cao.
    Với mỗi truy vấn, các nút có thể đi đến là các nút mà trên đường đi giữa chúng
    và đỉnh truy vấn trong cây khung lớn nhất, cạnh có trọng số nhỏ nhất lớn hơn $p$.

    Theo tính chất của cây tái cấu trúc Kruskal,
    các nút này nằm trong cùng một cây con và đồng thời là toàn bộ các lá của cây con đó.

    Nói cách khác, chỉ cần tính giá trị min của các lá trong mỗi cây con của cây tái cấu trúc Kruskal để hỗ trợ truy vấn cây con.

    Nút gốc của truy vấn có thể được tìm bằng nhảy nhị phân trên cây tái cấu trúc Kruskal.

    Độ phức tạp thời gian là $O((n+m+Q) \log n)$.
