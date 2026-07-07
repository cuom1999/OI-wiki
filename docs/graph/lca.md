author:ouuan, Backl1ght, billchenchina, CCXXXI, ChickenHu, ChungZH, cjsoft, countercurrent-time, diauweb, Early0v0, Enter-tainer, EtaoinWu, H-J-Granger, H-Shen, Henry-ZHR, HeRaNO, hsfzLZH1, huaruoji, iamtwz, imp2002, Ir1d, kenlig, Konano, Lyccrius, Marcythm, Menci, NachtgeistW, PeterlitsZo, psz2007, shuzhouliu, SkqLiao, sshwy, SukkaW, therehello, TrisolarisHD, ttzztztz, vincent-163, WAAutoMaton, Hunter19019

## Định nghĩa

Tổ tiên chung gần nhất được viết tắt là LCA (Lowest Common Ancestor). Tổ tiên chung gần nhất của hai nút là tổ tiên chung xa gốc nhất trong các tổ tiên chung của hai nút đó.
Để thuận tiện, ký hiệu tổ tiên chung gần nhất của một tập đỉnh $S=\{v_1,v_2,\ldots,v_n\}$ là $\text{LCA}(v_1,v_2,\ldots,v_n)$ hoặc $\text{LCA}(S)$.

## Tính chất

> Phần **Tính chất** trong mục này được dịch và chỉnh sửa từ [wcipeg](http://wcipeg.com/wiki/Lowest_common_ancestor).

1.  $\text{LCA}(\{u\})=u$;
2.  $u$ là tổ tiên của $v$ khi và chỉ khi $\text{LCA}(u,v)=u$;
3.  Nếu $u$ không phải là tổ tiên của $v$ và $v$ không phải là tổ tiên của $u$, thì $u,v$ lần lượt nằm trong hai cây con khác nhau của $\text{LCA}(u,v)$;
4.  Trong duyệt tiền thứ tự, $\text{LCA}(S)$ xuất hiện trước mọi phần tử trong $S$; trong duyệt hậu thứ tự, $\text{LCA}(S)$ xuất hiện sau mọi phần tử trong $S$;
5.  Tổ tiên chung gần nhất của hợp hai tập đỉnh là tổ tiên chung gần nhất của hai LCA tương ứng, tức là $\text{LCA}(A\cup B)=\text{LCA}(\text{LCA}(A), \text{LCA}(B))$;
6.  Tổ tiên chung gần nhất của hai đỉnh nằm trên đường đi ngắn nhất giữa hai đỉnh đó trên cây;
7.  $d(u,v)=h(u)+h(v)-2h(\text{LCA}(u,v))$, trong đó $d$ là khoảng cách giữa hai đỉnh trên cây, còn $h$ biểu thị khoảng cách từ một đỉnh đến gốc của cây.

## Cách tìm

### Thuật toán đơn giản

#### Quy trình

Mỗi lần có thể chọn đỉnh có độ sâu lớn hơn rồi đưa đỉnh đó lên tổ tiên của nó. Trên cây, cuối cùng hai đỉnh này sẽ gặp nhau, và vị trí gặp nhau chính là LCA cần tìm.
Một cách khác là trước hết điều chỉnh đỉnh có độ sâu lớn hơn lên trên để hai đỉnh có cùng độ sâu, sau đó đưa đồng thời cả hai đỉnh lên tổ tiên của chúng; cuối cùng chúng cũng sẽ gặp nhau.

#### Tính chất

Khi tiền xử lý, thuật toán đơn giản cần DFS toàn bộ cây, nên độ phức tạp thời gian là $O(n)$; độ phức tạp thời gian cho một truy vấn là $\Theta(n)$. Nếu cây được sinh ngẫu nhiên theo một mô hình cho trước, độ phức tạp thời gian liên quan đến chiều cao kỳ vọng của loại cây ngẫu nhiên đó.

### Thuật toán nhân đôi

#### Quy trình

Thuật toán nhân đôi là cách tìm LCA kinh điển nhất, là cải tiến của thuật toán đơn giản. Bằng cách tiền xử lý mảng $\text{fa}_{x,i}$, có thể nhảy nhanh qua các tổ tiên, qua đó giảm đáng kể số lần nhảy. $\text{fa}_{x,i}$ biểu thị tổ tiên thứ $2^i$ của đỉnh $x$. Có thể tiền xử lý mảng $\text{fa}_{x,i}$ bằng DFS.

Xét cách tối ưu các bước nhảy này:
Ở giai đoạn đầu khi điều chỉnh con trỏ, cần đưa hai đỉnh $u,v$ về cùng một độ sâu. Có thể tính hiệu độ sâu của $u,v$, giả sử là $y$. Bằng cách phân tách $y$ theo nhị phân, có thể tối ưu $y$ lần nhảy con trỏ thành số lần nhảy bằng "số bit `1` trong biểu diễn nhị phân của $y$".
Ở giai đoạn thứ hai, bắt đầu thử lặp từ $i$ lớn nhất xuống đến $0$ (bao gồm $0$). Nếu $\text{fa}_{u,i}\not=\text{fa}_{v,i}$, thì đặt $u\gets\text{fa}_{u,i},v\gets\text{fa}_{v,i}$; khi đó LCA cuối cùng là $\text{fa}_{u,0}$.

#### Tính chất

Độ phức tạp thời gian tiền xử lý của thuật toán nhân đôi là $O(n \log n)$, và độ phức tạp thời gian cho một truy vấn là $O(\log n)$.
Ngoài ra, thuật toán nhân đôi có thể đổi thứ tự hai chiều của mảng `fa` để đặt chiều nhỏ hơn lên trước. Cách này có thể giảm số lần cache miss và nâng cao hiệu suất chương trình.

??? note "Ví dụ"
    [HDU 2586 How far away?](https://acm.hdu.edu.cn/showproblem.php?pid=2586) Truy vấn đường đi ngắn nhất trên cây.

Có thể tìm LCA trước rồi kết hợp với tính chất $7$ để trả lời. Hoặc có thể tính trực tiếp kết quả trong lúc tìm LCA.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/lca/lca_1.cpp"
    ```

### Thuật toán Tarjan

#### Quy trình

Thuật toán Tarjan là một **thuật toán ngoại tuyến**, cần dùng [DSU](../ds/dsu.md) để ghi nhận tổ tiên đại diện của mỗi tập. Cách làm như sau:

1.  Trước hết đọc các cạnh của cây (danh sách kề) và các cạnh truy vấn (lưu trong một danh sách kề khác). Cạnh truy vấn thực chất là cạnh ảo được thêm vào; để thuận tiện, mỗi khi nhập một cạnh truy vấn, thêm cả cạnh đó và cạnh ngược của nó vào mảng `queryEdge`.
2.  Sau đó thực hiện một lần duyệt DFS, đồng thời dùng mảng `visited` để ghi nhận một nút đã được thăm hay chưa, và dùng `parent` để ghi nhận nút cha của nút hiện tại.
3.  Bước này dùng **ý tưởng quay lui**. Mỗi khi duyệt đến một nút nào đó, đặt đại diện của tập chứa nút đó là chính nó. Sau khi DFS trên cây con của nút đó kết thúc, đặt lại đại diện của tập chứa nút đó thành nút cha trực tiếp của nó.
4.  Khi quay lui, nếu với nút hiện tại làm điểm xuất phát, nút còn lại của cạnh truy vấn trong `queryEdge` đã được thăm, thì cập nhật trực tiếp kết quả LCA của cạnh truy vấn đó.
5.  Cuối cùng xuất kết quả.

#### Tính chất

Thuật toán Tarjan cần khởi tạo DSU, vì vậy độ phức tạp thời gian tiền xử lý là $O(n)$.

Thuật toán Tarjan đơn giản xử lý toàn bộ $m$ truy vấn trong độ phức tạp thời gian $O(m \alpha(m+n, n) + n)$, nhưng hằng số của thuật toán Tarjan lớn hơn thuật toán nhân đôi. Tồn tại cách cài đặt $O(m + n)$.

???+ warning "Lưu ý"
    Không nên cho rằng "tính chất của DSU dùng trong thuật toán Tarjan LCA đơn giản tương đối đặc biệt, nên độ phức tạp thời gian của một lần gọi hàm `find()` là $O(1)$ trung bình".

    Cài đặt Tarjan đơn giản dưới đây có độ phức tạp $O(m \alpha(m+n, n) + n)$. Nếu cần đạt tuyến tính nghiêm ngặt, có thể tham khảo [bài báo năm 1983 của Gabow và Tarjan](https://dl.acm.org/doi/pdf/10.1145/800061.808753). Bài báo đưa ra một cách làm có độ phức tạp $O(m + n)$.

#### Cài đặt

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/lca/lca_tarjan.cpp"
    ```

### Dùng dãy Euler để chuyển thành bài toán RMQ

#### Định nghĩa

Thực hiện DFS trên một cây; mỗi khi lần đầu đi vào một nút hoặc quay lui về nút đó, đều ghi lại số hiệu của nút, từ đó thu được một dãy có độ dài $2n-1$. Dãy này được gọi là dãy Euler của cây.

Trong phần dưới, ký hiệu vị trí xuất hiện đầu tiên của nút $u$ trong dãy Euler là $pos(u)$ (cũng gọi là thứ tự Euler của nút $u$), và ký hiệu chính dãy Euler là $E[1..2n-1]$.

#### Quy trình

Khi đã có dãy Euler, bài toán LCA có thể được chuyển thành bài toán RMQ trong thời gian tuyến tính: trên đoạn $E[\min(pos(u), pos(v))..\max(pos(u), pos(v))]$, LCA của $u$ và $v$ là đỉnh có độ sâu nhỏ nhất.

Lập luận cho nhận xét trên như sau: trong quá trình đi từ $u$ đến $v$ sẽ đi qua $LCA(u,v)$, nhưng sẽ không đi qua tổ tiên của $LCA(u,v)$. Vì vậy, đỉnh có độ sâu nhỏ nhất xuất hiện trên đoạn Euler tương ứng với quá trình từ $u$ đến $v$ chính là $LCA(u, v)$.

Thời gian dùng DFS để tính dãy Euler là $O(n)$, và độ dài của dãy Euler cũng là $O(n)$, nên bài toán LCA có thể được chuyển thành bài toán RMQ cùng quy mô trong thời gian $O(n)$.

#### Cài đặt

???+ note "Mã tham khảo"
    ```cpp
    int dfn[N << 1], pos[N], tot, st[30][(N << 1) + 2],
        rev[30][(N << 1) + 2];  // rev biểu thị số hiệu đỉnh có độ sâu nhỏ nhất

    void dfs(int cur, int dep) {
      dfn[++tot] = cur;
      depth[tot] = dep;
      pos[cur] = tot;
      for (int i = head[cur]; i; i = side[i].next) {
        int v = side[i].to;
        if (!pos[v]) {
          dfs(v, dep + 1);
          dfn[++tot] = cur, depth[tot] = dep;
        }
      }
    }

    void init() {
      for (int i = 2; i <= tot + 1; ++i)
        lg[i] = lg[i >> 1] + 1;  // tiền xử lý lg thay cho log2 của thư viện để tối ưu hằng số
      for (int i = 1; i <= tot; i++) st[0][i] = depth[i], rev[0][i] = dfn[i];
      for (int i = 1; i <= lg[tot]; i++)
        for (int j = 1; j + (1 << i) - 1 <= tot; j++)
          if (st[i - 1][j] < st[i - 1][j + (1 << i - 1)])
            st[i][j] = st[i - 1][j], rev[i][j] = rev[i - 1][j];
          else
            st[i][j] = st[i - 1][j + (1 << i - 1)],
            rev[i][j] = rev[i - 1][j + (1 << i - 1)];
    }

    int query(int l, int r) {
      int k = lg[r - l + 1];
      return st[k][l] < st[k][r + 1 - (1 << k)] ? rev[k][l]
                                                : rev[k][r + 1 - (1 << k)];
    }
    ```

Khi cần truy vấn LCA của một cặp đỉnh $(u, v)$, chỉ cần truy vấn đỉnh tương ứng với độ sâu nhỏ nhất trên đoạn $[\min\{pos[u], pos[v]\}, \max\{pos[u], pos[v]\}]$.

Nếu dùng bảng ST để giải bài toán RMQ, thuật toán này không hỗ trợ sửa đổi trực tuyến; độ phức tạp thời gian tiền xử lý là $O(n\log n)$, và độ phức tạp thời gian của mỗi truy vấn LCA là $O(1)$.

### Phân rã cây theo chuỗi

LCA là đỉnh nông hơn trong hai đỉnh khi hai con trỏ đã nhảy lên cùng một chuỗi nặng.

Độ phức tạp thời gian tiền xử lý của phân rã cây theo chuỗi là $O(n)$, độ phức tạp thời gian cho một truy vấn là $O(\log n)$, và hằng số khá nhỏ.

<span id="link-cut-tree"></span>

### Cây Link-Cut

Trong [cây Link-Cut](../ds/lct.md), giả sử hai đỉnh được thực hiện thao tác [access](../ds/lct.md#access) liên tiếp lần lượt là `u` và `v`, thì đỉnh do thao tác [access](../ds/lct.md#access) thứ hai trả về chính là LCA của `u` và `v`.

Trong trường hợp không có các thao tác như link và cut, độ phức tạp thời gian cho một truy vấn khi dùng cây Link-Cut là $O(\log n)$.

### RMQ chuẩn

Phần trước đã nói đến việc dùng thứ tự Euler để chuyển bài toán LCA thành bài toán RMQ; phần cốt lõi còn lại là RMQ. Nếu có thể giải RMQ với $O(n) \sim O(1)$, thì cũng có thể giải LCA với $O(n) \sim O(1)$.

Dãy độ sâu theo thứ tự Euler thỏa mãn hiệu giữa hai số kề nhau là 1 hoặc -1, nên có thể dùng [RMQ cộng trừ 1](../topic/rmq.md#rmq-cộng-trừ-1) với $O(n) \sim O(1)$ để xử lý.

Độ phức tạp thời gian là $O(n) \sim O(1)$, độ phức tạp không gian là $O(n)$, hỗ trợ truy vấn trực tuyến, nhưng hằng số khá lớn.

#### Ví dụ [Luogu P3379 [Mẫu] Tổ tiên chung gần nhất (LCA)](https://www.luogu.com.cn/problem/P3379)

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/lca/lca_2.cpp"
    ```

## Bài tập

-   [Truy vấn tổ tiên và hậu duệ](https://loj.ac/problem/10135)
-   [Vận chuyển bằng xe tải](https://loj.ac/problem/2610)
-   [Khoảng cách giữa các điểm](https://loj.ac/problem/10130)
