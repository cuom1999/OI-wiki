author: Ir1d, Tiphereth-A, sshwy, ksyx, Marcythm, orzAtalod, Xeonacid, Enter-tainer, GavinZhengOI, Henry-ZHR, iamtwz, 383494, abc1763613206, aofall, Chrogeek, CoelacanthusHex, Dafenghh, DanJoshua, Gesrua, kenlig, lyccrius, Menci, opsiff, ouuan, partychicken, Persdre, Ruakker, shuzhouliu, StudyingFather, szdytom, XuYueming520, ZXyaang, alphagocc, c-forrest, Early0v0, GoodCoder666, HeRaNO, liangbob2023, qq2964, r-value, rickyxrc, Rickyxrc, shawlleyw, Unnamed2964, zica87, ZnPdCo, sun2snow

<span id="tổng-quan"></span>
## Tổng quan

Ô-tô-mát AC (ô-tô-mát Aho-Corasick) là một ô-tô-mát **dựa trên cấu trúc Trie** và kết hợp **ý tưởng của KMP**, dùng để giải các bài toán như khớp nhiều mẫu.

Về bản chất, ô-tô-mát AC là một ô-tô-mát trên Trie.

Trước khi đọc bài này, nên đọc trước [KMP](./kmp.md) và [Trie](./trie.md).

<span id="giải-thích"></span>
## Giải thích

Nói đơn giản, việc xây dựng một ô-tô-mát AC gồm hai bước:

1.  Cấu trúc Trie cơ bản: đưa tất cả các xâu mẫu vào một cây Trie;
2.  Ý tưởng của KMP: xây dựng con trỏ thất bại cho mọi đỉnh trên cây Trie.

Sau khi xây dựng xong, có thể dùng nó để khớp nhiều mẫu.

<span id="xây-dựng-trie"></span>
## Xây dựng Trie

Ban đầu, ô-tô-mát AC chèn một số xâu mẫu vào một Trie, rồi xây dựng ô-tô-mát AC trên Trie đó. Trie này là Trie thông thường, chỉ cần xây dựng theo cách dựng cây Trie cơ bản.

Cần chú ý rằng mỗi đỉnh trong Trie biểu diễn một tiền tố của một xâu mẫu nào đó. Ở các phần sau, đỉnh này cũng được gọi là một trạng thái. Một đỉnh biểu diễn một trạng thái, còn các cạnh của Trie là các phép chuyển trạng thái.

Nói một cách hình thức, với các xâu mẫu $s_1,s_2,\cdots,s_n$, sau khi xây dựng Trie từ chúng, gọi tập tất cả các trạng thái là $Q$.

<span id="con-trỏ-thất-bại"></span>
## Con trỏ thất bại

Ô-tô-mát AC dùng một con trỏ `fail` để hỗ trợ khớp nhiều xâu mẫu.

Con trỏ `fail` của trạng thái $u$ trỏ tới một trạng thái khác $v$, trong đó $v\in Q$ và $v$ là hậu tố dài nhất của $u$ (tức là trong các trạng thái hậu tố, chọn trạng thái dài nhất làm con trỏ `fail`).

So sánh con trỏ `fail` với con trỏ `next` trong [KMP](./kmp.md):

1.  Điểm giống nhau: cả hai đều là con trỏ dùng để nhảy khi khớp thất bại.
2.  Điểm khác nhau: con trỏ `next` tìm Border dài nhất (tiền tố và hậu tố giống nhau dài nhất), còn con trỏ `fail` trỏ tới tiền tố của một xâu mẫu nào đó khớp với hậu tố dài nhất của trạng thái hiện tại.

Lý do là KMP chỉ khớp một xâu mẫu, còn ô-tô-mát AC phải khớp nhiều xâu mẫu. Có thể đỉnh mà con trỏ `fail` trỏ tới tương ứng với một xâu mẫu khác, nên tiền tố của hai xâu có thể khác nhau.

Tóm lại, con trỏ thất bại của ô-tô-mát AC trỏ tới trạng thái hậu tố dài nhất của trạng thái hiện tại.

Lưu ý: khi ô-tô-mát AC thực hiện khớp, tại cùng một vị trí có thể khớp nhiều xâu mẫu.

<span id="xây-dựng-con-trỏ"></span>
### Xây dựng con trỏ

Dưới đây là **ý tưởng cơ bản** để xây dựng con trỏ `fail`:

Khi xây dựng con trỏ `fail`, có thể tham khảo ý tưởng xây dựng con trỏ `next` trong KMP.

Xét đỉnh hiện tại $u$ trong Trie. Cha của $u$ là $p$, và $p$ trỏ tới $u$ bằng cạnh mang ký tự $c$, tức là $\operatorname{trie}(p, c)=u$. Giả sử con trỏ `fail` của mọi đỉnh có độ sâu nhỏ hơn $u$ đều đã được tính.

1.  Nếu $\operatorname{trie}(\operatorname{fail}(p), c)$ tồn tại: đặt con trỏ `fail` của $u$ trỏ tới $\operatorname{trie}(\operatorname{fail}(p), c)$. Điều này tương đương với việc thêm ký tự $c$ vào sau $p$ và $\operatorname{fail}(p)$, lần lượt tương ứng với $u$ và $\operatorname{fail}(u)$;
2.  Nếu $\operatorname{trie}(\operatorname{fail}(p), c)$ không tồn tại: tiếp tục tìm $\operatorname{trie}(\operatorname{fail}(\operatorname{fail}(p)), c)$. Lặp lại quá trình này, liên tục nhảy theo con trỏ `fail` cho tới gốc;
3.  Nếu vẫn không tồn tại, đặt con trỏ `fail` trỏ tới đỉnh gốc.

Như vậy đã xây dựng xong $\operatorname{fail}(u)$.

<span id="ví-dụ"></span>
### Ví dụ

Dưới đây dùng một số ảnh GIF để minh họa quá trình xây dựng con trỏ `fail` cho Trie tạo bởi các xâu $\mathtt{i}$, $\mathtt{he}$, $\mathtt{his}$, $\mathtt{she}$, $\mathtt{hers}$:

1.  Đỉnh màu vàng: đỉnh hiện tại $u$.
2.  Đỉnh màu xanh lá: đỉnh đã được BFS duyệt xong.
3.  Cạnh màu cam: con trỏ `fail`.
4.  Cạnh màu đỏ: con trỏ `fail` hiện đang được tính.

![Quá trình xây con trỏ fail trong ô-tô-mát AC](./images/ac-automaton1.gif)

Phân tích kỹ việc xây dựng con trỏ `fail` của đỉnh $6$:

![Ví dụ tính con trỏ fail của đỉnh 6](./images/ac-automaton1.png)

Tìm cha của $6$ là đỉnh $5$, $\operatorname{fail}(5)=10$. Tuy nhiên đỉnh $10$ không có cạnh đi ra bằng chữ $\mathtt{s}$; tiếp tục nhảy tới con trỏ `fail` của $10$, tức $\operatorname{fail}(10)=0$. Đỉnh $0$ có cạnh đi ra bằng chữ $\mathtt{s}$ tới đỉnh $7$; vì vậy $\operatorname{fail}(6)=7$.

Hình dưới đây thể hiện trạng thái sau khi xây dựng xong:

![Trạng thái sau khi xây xong con trỏ fail](./images/ac-automaton4.png)

<span id="trie-và-đồ-thị-từ-điển"></span>
## Trie và đồ thị từ điển

Xét hàm xây dựng `build`. Hàm này có hai mục tiêu: xây dựng con trỏ `fail` và xây dựng ô-tô-mát. Các biến liên quan được định nghĩa như sau:

1.  `tr[u].son[c]`: có hai cách hiểu. Có thể hiểu đơn giản là một cạnh trên Trie, tức $\operatorname{trie}(u, c)$; cũng có thể hiểu là trạng thái (đỉnh) đạt được khi thêm một ký tự $c$ vào sau trạng thái (đỉnh) $u$, tức một hàm chuyển trạng thái $\operatorname{trans}(u, c)$. Để thuận tiện, bên dưới dùng cách hiểu thứ hai.
2.  Hàng đợi `q`: dùng để BFS trên Trie.
3.  `tr[u].fail`: con trỏ `fail` của đỉnh $u$.

???+ note "Cài đặt"
    === "C++"
        ```cpp
        void build() {
          queue<int> q;
          for (int i = 0; i < 26; i++)
            if (tr[0].son[i]) q.push(tr[0].son[i]);
          while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
              if (tr[u].son[i]) {
                tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                q.push(tr[u].son[i]);
              } else
                tr[u].son[i] = tr[tr[u].fail].son[i];
            }
          }
        }
        ```
    
    === "Python"
        ```python
        def build():
            for i in range(0, 26):
                if tr[0][i] != 0:
                    q.append(tr[0][i])
            while q:
                u = q.pop(0)
                for i in range(0, 26):
                    if tr[u][i] != 0:
                        fail[tr[u][i]] = tr[fail[u]][i]
                        q.append(tr[u][i])
                    else:
                        tr[u][i] = tr[fail[u]][i]
        ```

<span id="giải-thích_1"></span>
### Giải thích

Hàm `build` đưa các đỉnh vào hàng đợi theo thứ tự BFS và lần lượt tính con trỏ `fail`. Gốc của Trie là đỉnh $0$, các đỉnh con của gốc được đưa vào hàng đợi. Nếu đưa chính đỉnh gốc vào hàng đợi, trong lần BFS đầu tiên, con trỏ `fail` của các con của gốc sẽ bị đánh dấu thành chính chúng. Vì vậy cần đưa từng con của gốc vào hàng đợi, thay vì đưa gốc vào.

Sau đó bắt đầu BFS: mỗi lần lấy đỉnh đầu hàng đợi $u$ ($\operatorname{fail}(u)$ đã được tính ở các bước BFS trước đó), rồi duyệt bảng chữ cái (trong đoạn này là $0 \sim 25$, tương ứng với $\mathtt{a} \sim \mathtt{z}$, tức các con của $u$):

1.  Nếu $\operatorname{trans}(u, c)$ tồn tại, gán con trỏ `fail` của $\operatorname{trans}(u, c)$ bằng $\operatorname{trans}(\operatorname{fail}(u), c)$. Theo mô tả trước đó, lẽ ra phải dùng vòng lặp `while`, liên tục nhảy theo con trỏ `fail`, kiểm tra có tồn tại đỉnh tương ứng với ký tự $c$ hay không rồi mới gán; nhưng trong phần này đã có xử lý đặc biệt để giản lược phần mã đó, sẽ được giải thích bên dưới;
2.  Ngược lại, đặt $\operatorname{trans}(u, c)$ trỏ tới trạng thái $\operatorname{trans}(\operatorname{fail}(u), c)$.

Cách xử lý này dùng phần mã trong nhánh `else` để sửa cấu trúc của Trie, nối các trạng thái không tồn tại trong Trie tới trạng thái tương ứng của con trỏ thất bại. Trong Trie gốc, mỗi đỉnh đại diện cho một xâu $S$, là tiền tố của một xâu mẫu nào đó. Sau khi sửa cấu trúc Trie, dù có thêm nhiều quan hệ chuyển trạng thái, xâu mà mỗi đỉnh (trạng thái) đại diện vẫn không đổi.

Còn $\operatorname{trans}(S, c)$ tương đương với việc thêm ký tự $c$ vào sau $S$ để trở thành một trạng thái khác $S'$. Nếu $S'$ tồn tại, nghĩa là có một tiền tố của xâu mẫu bằng $S'$; nếu không, cho $\operatorname{trans}(S, c)$ trỏ tới $\operatorname{trans}(\operatorname{fail}(S), c)$. Vì xâu tương ứng với $\operatorname{fail}(S)$ là một hậu tố của $S$, nên xâu tương ứng với $\operatorname{trans}(\operatorname{fail}(S), c)$ cũng là một hậu tố của $S'$.

Nói cách khác, khi chuyển trên Trie, chỉ đi từ $S$ tới $S'$, tương đương với việc khớp được một $S'$; còn khi chuyển trên ô-tô-mát AC, sẽ đi từ $S$ tới một hậu tố của $S'$. Tức là sau khi khớp một ký tự $c$, bỏ đi một phần tiền tố của $S$. Phần tiền tố bị bỏ chắc chắn vẫn cho phép tiếp tục khớp. Đồng thời, nếu xâu văn bản khớp được $S$, nó cũng khớp được hậu tố của $S$, nên con trỏ `fail` cũng đang bỏ đi tiền tố. Con trỏ `fail` thực ra chính là một tập các hậu tố của $S$.

Mảng con `son` của các đỉnh Trie còn có một cách hiểu đơn giản hơn: nếu tại vị trí $u$ bị khớp thất bại, sẽ nhảy tới vị trí $\operatorname{fail}(u)$. Chú ý rằng điều này có thể khiến quá trình phải nhảy theo mảng `fail` nhiều lần mới tới được vị trí tiếp theo có thể khớp. Vì vậy có thể dùng `son` để ghi trực tiếp vị trí tiếp theo có thể khớp, nhờ đó bảo đảm độ phức tạp thời gian của chương trình.

Việc sửa cấu trúc Trie trong phần này giúp các phép chuyển khi khớp trở nên đầy đủ hơn. Đồng thời nó nén đường đi nhảy theo con trỏ `fail`, biến việc phải nhảy nhiều lần thành chỉ nhảy một lần.

<span id="quá-trình"></span>
### Quá trình

Phần này vẫn dùng một số ảnh GIF để minh họa quá trình xây dựng:

![Quá trình xây đồ thị từ điển của ô-tô-mát AC](./images/ac-automaton2.gif)

1.  Đỉnh màu xanh dương: đỉnh $u$ đang được BFS duyệt tới.
2.  Cạnh màu xanh dương: cạnh mà ô-tô-mát AC thêm ra khi sửa cấu trúc Trie tại đỉnh hiện tại.
3.  Cạnh màu đen: cạnh mà ô-tô-mát AC thêm ra khi sửa cấu trúc Trie.
4.  Cạnh màu đỏ: con trỏ `fail` hiện đang được tính.
5.  Cạnh màu vàng: con trỏ `fail`.
6.  Cạnh màu xám: cạnh của Trie.

Rất nhiều cạnh đen đan xen đã biến Trie thành **đồ thị từ điển**. Trong hình đã lược bỏ các cạnh đen trỏ về gốc (nếu không hình sẽ rối hơn). Phân tích kỹ trường hợp khi duyệt đỉnh $5$. Cần tính con trỏ `fail` của $\operatorname{trans}(5, \mathtt{s})=6$:

![Ví dụ chuyển trạng thái khi duyệt đỉnh 5](./images/ac-automaton2.png)

Chiến lược ban đầu là tìm theo con trỏ `fail`: nhảy tới $\operatorname{fail}(5)=10$, thấy không có cạnh Trie đi ra bằng $\mathtt{s}$; rồi nhảy tới $\operatorname{fail}(10)=0$, thấy có $\operatorname{trie}(0, \mathtt{s})=7$, nên $\operatorname{fail}(6)=7$. Nhưng khi đã có các cạnh đen và cạnh xanh dương, sau khi nhảy tới $\operatorname{fail}(5)=10$, chỉ cần đi trực tiếp theo $\operatorname{trans}(10, \mathtt{s})=7$ là tới đỉnh $7$.

Đây chính là hai việc mà `build` hoàn thành: xây dựng con trỏ `fail` và xây dựng đồ thị từ điển. Đồ thị từ điển này cũng đóng vai trò then chốt khi truy vấn.

<span id="khớp-nhiều-mẫu"></span>
## Khớp nhiều mẫu

Tiếp theo phân tích hàm khớp `query`:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        int query(const char t[]) {
          int u = 0, res = 0;
          for (int i = 1; t[i]; i++) {
            u = tr[u].son[t[i] - 'a'];
            for (int j = u; j && tr[j].cnt != -1; j = tr[j].fail) {
              res += tr[j].cnt, tr[j].cnt = -1;
            }
          }
          return res;
        }
        ```
    
    === "Python"
        ```python
        def query(t: str) -> int:
            u, res = 0, 0
            for c in t:
                u = tr[u][c - ord("a")]
                j = u
                while j and e[j] != -1:
                    res += e[j]
                    e[j] = -1
                    j = fail[j]
            return res
        ```

<span id="giải-thích_2"></span>
### Giải thích

Trong đoạn mã trên, $u$ là đỉnh hiện đang khớp tới trên Trie, còn `res` là đáp án trả về. Vòng lặp duyệt xâu cần khớp, $u$ theo dõi ký tự hiện tại trên Trie. Dùng con trỏ `fail` để tìm mọi xâu mẫu đã khớp và cộng vào đáp án. Sau đó đặt số lần xuất hiện của xâu đã khớp thành không còn xét nữa, để tránh đếm lặp cùng một xâu. Như đã phân tích ở trên, cấu trúc Trie thực chất là một hàm `trans`; sau khi xây dựng hàm này, trong quá trình khớp xâu, sẽ bỏ bớt một phần tiền tố để đạt tới mức khớp tối thiểu. Con trỏ `fail` thì trỏ tới nhiều trạng thái khớp hơn. Cuối cùng xem lại một hình với ô-tô-mát vừa rồi:

![Ô-tô-mát AC sau khi xây dựng](./images/ac-automaton3.png)

Bắt đầu từ gốc và thử khớp $\mathtt{ushersheishis}$, khi đó sự thay đổi của $p$ là:

![Quá trình khớp xâu trên ô-tô-mát AC](./images/ac-automaton3.gif)

1.  Đỉnh màu đỏ: đỉnh $p$.
2.  Mũi tên màu hồng: bước chuyển của $p$ trên ô-tô-mát.
3.  Cạnh màu xanh dương: xâu mẫu được khớp thành công.
4.  Đỉnh màu xanh dương: đỉnh (trạng thái) khi nhảy theo con trỏ `fail`.

<span id="tối-ưu-hiệu-suất"></span>
## Tối ưu hiệu suất

Bài toán tham khảo: Luogu [P5357 - Mẫu ô-tô-mát AC](https://www.luogu.com.cn/problem/P5357).

Trong ô-tô-mát AC ở trên, mỗi lần khớp sẽ liên tục nhảy theo các cạnh `fail` để tìm tất cả các lần khớp. Cách này có hiệu suất khá thấp và sẽ quá thời gian ở một số bài.

Vậy cần tối ưu như thế nào? Trước hết cần biết một tính chất của con trỏ `fail`: trong một ô-tô-mát AC, nếu chỉ giữ lại các cạnh `fail`, đồ thị còn lại chắc chắn là một cây.

Điều này đúng vì `fail` không tạo chu trình và độ sâu luôn nhỏ hơn hiện tại.

Như vậy, việc khớp trên ô-tô-mát AC có thể chuyển thành bài toán tính tổng trên một đường đi trong cây `fail`; chỉ cần tối ưu phần này là đủ.

Dưới đây đưa ra hai hướng.

<span id="tối-ưu-bằng-sắp-xếp-topo"></span>
### Tối ưu bằng sắp xếp topo

Quan sát thấy thời gian chủ yếu bị lãng phí do mỗi lần đều phải nhảy theo `fail`. Nếu có thể ghi nhận trước rồi cuối cùng cộng dồn một lượt, hiệu suất sẽ được cải thiện.

Vì vậy thực hiện một lần sắp xếp topo trên cây hướng vào theo cây `fail`, từ đó có thể tính số lần xuất hiện của mọi xâu mẫu trong một lượt.

Hàm `build` được bổ sung phần thống kê bậc vào so với phiên bản ban đầu, để chuẩn bị cho sắp xếp topo.

???+ note "Xây dựng"
    ```cpp
    void build() {
      queue<int> q;
      for (int i = 0; i < 26; i++)
        if (tr[0].son[i]) q.push(tr[0].son[i]);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
          if (tr[u].son[i]) {
            tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
            tr[tr[tr[u].fail].son[i]].du++;  // Đếm bậc vào
            q.push(tr[u].son[i]);
          } else
            tr[u].son[i] = tr[tr[u].fail].son[i];
        }
      }
    }
    ```

Sau đó, khi truy vấn, chỉ cần đánh dấu `ans` cho các đỉnh tìm được, rồi cuối cùng dùng sắp xếp topo để tính đáp án.

???+ note "Truy vấn"
    ```cpp
    void query(const char t[]) {
      int u = 0;
      for (int i = 1; t[i]; i++) {
        u = tr[u].son[t[i] - 'a'];
        tr[u].ans++;
      }
    }
    
    void topu() {
      queue<int> q;
      for (int i = 0; i <= tot; i++)
        if (tr[i].du == 0) q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans[tr[u].idx] = tr[u].ans;
        int v = tr[u].fail;
        tr[v].ans += tr[u].ans;
        if (!--tr[v].du) q.push(v);
      }
    }
    ```

Cuối cùng là hàm `main`:

???+ note "Hàm main"
    ```cpp
    int main() {
      // do_something();
      AC::build();
      scanf("%s", s + 1);
      AC::query(s);
      AC::topu();
      for (int i = 1; i <= n; i++) printf("%d\n", AC::ans[idx[i]]);
      // do_another_thing();
    }
    ```

??? note "Mã tham khảo tối ưu bằng sắp xếp topo cho bài mẫu [Luogu P5357 - Mẫu ô-tô-mát AC](https://www.luogu.com.cn/problem/P5357)"
    ```cpp
    --8<-- "docs/string/code/ac-automaton/ac-automaton_topu.cpp"
    ```

<span id="tối-ưu-bằng-dfs"></span>
### Tối ưu bằng DFS

Ý tưởng gần giống với sắp xếp topo, nhưng dùng DFS thay cho sắp xếp topo. Thực ra bản chất hai cách này giống nhau: đều tính tổng các cây con trên cây `fail`.

Mã đầy đủ xem ở mẫu tổng kết 3.

<span id="dp-trên-ac-automaton"></span>
## DP trên ô-tô-mát AC

Phần này dùng bài [P2292 [HNOI2004] Ngôn ngữ L](https://www.luogu.com.cn/problem/P2292) làm ví dụ để giải thích.

Một hướng đơn giản là xây dựng ô-tô-mát AC, chuyển trạng thái theo mọi xâu con trên các con trỏ `fail` trong ô-tô-mát AC, rồi lấy giá trị lớn nhất làm đáp án.

Phần mã chính như sau. Nếu chưa quen với các định nghĩa kiểu trong mã, có thể xem mã đầy đủ ở cuối phần này:

???+ note "Mã chính của phần truy vấn"
    ```cpp
    int query(const char t[]) {
      int u = 0, len = strlen(t + 1);
      for (int i = 1; i <= len; i++) dp[i] = 0;
      for (int i = 1; i <= len; i++) {
        u = tr[u].son[t[i] - 'a'];
        for (int j = u; j; j = tr[j].fail) {
          if (tr[j].idx && (dp[i - tr[j].depth] || i - tr[j].depth == 0)) {
            dp[i] = dp[i - tr[j].depth] + tr[j].depth;
          }
        }
      }
      int ans = 0;
      for (int i = 1; i <= len; i++) ans = std::max(ans, dp[i]);
      return ans;
    }
    ```

Tuy nhiên hướng này không có độ phức tạp tuyến tính (vì phải nhảy theo `fail` của từng đỉnh), nên sẽ quá thời gian ở subtasks thứ hai; do đó cần tối ưu.

Nhìn lại tính chất đặc biệt của bài toán, mọi từ đều có độ dài chỉ $20$, vì vậy có thể nghĩ tới tối ưu bằng nén trạng thái.

Nút thắt thời gian hiện tại chủ yếu nằm ở bước nhảy theo `fail`. Nếu tối ưu bước này xuống $O(1)$, toàn bộ bài toán có thể được giải trong thời gian tuyến tính chặt.

Có thể lưu lại các độ dài xâu con có thể có trong $20$ ký tự gần nhất, nén chúng vào trạng thái và lưu trong từng đỉnh con.

Khi đó trong `build`, có thể viết như sau:

???+ note "Xây dựng con trỏ fail"
    ```cpp
    void build() {
      queue<int> q;
      for (int i = 0; i < 26; i++)
        if (tr[0].son[i]) {
          q.push(tr[0].son[i]);
          tr[tr[0].son[i]].depth = 1;
        }
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = tr[u].fail;
        // Cập nhật trạng thái tại đây
        tr[u].stat = tr[v].stat;
        if (tr[u].idx) tr[u].stat |= 1 << tr[u].depth;
        for (int i = 0; i < 26; i++) {
          if (tr[u].son[i]) {
            tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
            tr[tr[u].son[i]].depth = tr[u].depth + 1;  // Ghi lại độ sâu
            q.push(tr[u].son[i]);
          } else
            tr[u].son[i] = tr[tr[u].fail].son[i];
        }
      }
    }
    ```

Sau đó khi truy vấn, có thể bỏ vòng lặp nhảy theo `fail` và rút gọn mã như sau:

???+ note "Truy vấn"
    ```cpp
    int query(const char t[]) {
      int u = 0, mx = 0;
      unsigned st = 1;
      for (int i = 1; t[i]; i++) {
        u = tr[u].son[t[i] - 'a'];
        st <<= 1;  // Đi xuống một vị trí, nên mọi độ dài đều tăng thêm 1
        if (tr[u].stat & st) st |= 1, mx = i;
      }
      return mx;
    }
    ```

`tr[u].stat` duy trì tập độ dài trên toàn bộ chuỗi `fail` bắt đầu từ đỉnh $u$ (vì tập độ dài nhỏ hơn $32$ nên không ảnh hưởng), còn `st` duy trì tập độ dài trong $32$ vị trí gần nhất của xâu truy vấn tính tới hiện tại (do nén trạng thái sẽ tự tràn).

Nếu kết quả phép toán `&` khác $0$, nghĩa là giao của hai tập độ dài không rỗng; lúc này đã tìm được một lần khớp.

??? note "Mã đầy đủ cho [P2292 [HNOI2004] Ngôn ngữ L](https://www.luogu.com.cn/problem/P2292)"
    ```cpp
    --8<-- "docs/string/code/ac-automaton/ac_automaton_luoguP2292.cpp"
    ```

<span id="tổng-kết"></span>
## Tổng kết

Độ phức tạp thời gian: định nghĩa $|s_i|$ là độ dài xâu mẫu, $|S|$ là độ dài xâu văn bản, $|\Sigma|$ là kích thước bảng chữ cái (hằng số, thường là $26$). Nếu nối thành đồ thị Trie, độ phức tạp thời gian là $O(\sum|s_i|+n|\Sigma|+|S|)$, trong đó $n$ là số đỉnh của ô-tô-mát AC và tối đa có thể đạt $O(\sum|s_i|)$. Nếu không nối đồ thị Trie, đồng thời tránh duyệt các con rỗng khi xây dựng con trỏ `fail`, độ phức tạp thời gian là $O(\sum|s_i|+|S|)$.

??? note "Mã tham khảo cho bài mẫu [Luogu P3808 ô-tô-mát AC (bản đơn giản)](https://www.luogu.com.cn/problem/P3808)"
    ```cpp
    --8<-- "docs/string/code/ac-automaton/ac-automaton_1.cpp"
    ```

??? note "Mã tham khảo cho bài mẫu [Luogu P3796 ô-tô-mát AC (bản đơn giản II)](https://www.luogu.com.cn/problem/P3796)"
    ```cpp
    --8<-- "docs/string/code/ac-automaton/ac-automaton_2.cpp"
    ```

??? note "Mã tham khảo tối ưu bằng DFS cho bài mẫu [Luogu P5357 - Mẫu ô-tô-mát AC](https://www.luogu.com.cn/problem/P5357)"
    ```cpp
    --8<-- "docs/string/code/ac-automaton/ac-automaton_3.cpp"
    ```
