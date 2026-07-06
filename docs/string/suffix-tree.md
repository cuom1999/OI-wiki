Cây hậu tố là một cấu trúc dữ liệu duy trì tất cả hậu tố của một chuỗi.

<span id="một-số-ký-hiệu"></span>
## Một số ký hiệu

Gọi chuỗi mẹ dùng để xây dựng cây hậu tố là $S$, có độ dài $n$, và bảng chữ cái là $\Sigma$.

Gọi $S[i]$ là ký tự thứ $i$ trong $S$, với $1 \le i \le n$.

Gọi $S[l, r]$ là chuỗi tạo bởi các ký tự từ vị trí $l$ đến vị trí $r$ trong $S$; chuỗi này được gọi là một chuỗi con của $S$.

Gọi $S[i, n]$ là hậu tố của $S$ bắt đầu tại $i$, và $S[1, i]$ là tiền tố của $S$ kết thúc tại $i$.

<span id="định-nghĩa"></span>
## Định nghĩa

Định nghĩa **trie hậu tố** của chuỗi $S$ là cây từ điển thu được bằng cách chèn tất cả hậu tố của $S$ vào trie. Trong trie hậu tố, chuỗi tương ứng với nút $x$ là chuỗi tạo bởi việc nối các ký tự trên đường đi từ gốc đến $x$. Gọi mọi nút tương ứng với một hậu tố nào đó của $S$ trong trie hậu tố là nút hậu tố.

Trie hậu tố có tính chất rất tốt: mọi nút khác gốc của nó nhận đúng tất cả chuỗi con không rỗng và phân biệt của $S$. Tuy nhiên, độ phức tạp thời gian và bộ nhớ để xây dựng trie hậu tố đều là $O(n^2)$, trong nhiều trường hợp không chấp nhận được, nên cần đưa vào khái niệm cây hậu tố.

Nếu lấy mọi nút trong trie hậu tố có nhiều hơn một con và mọi nút hậu tố làm điểm then chốt, rồi chỉ giữ lại các điểm then chốt và nén các chuỗi nút không then chốt thành một cạnh, cây trie nén thu được được gọi là **cây hậu tố (Suffix Tree)**. Nếu chỉ lấy mọi nút trong trie hậu tố có nhiều hơn một con và mọi nút lá làm điểm then chốt, rồi chỉ giữ lại các điểm then chốt để tạo thành cây trie nén, cấu trúc đó gọi là **cây hậu tố ẩn (Implicit Suffix Tree)**. Cây hậu tố ẩn là kết quả thu được sau khi tiếp tục nén cây hậu tố.

Trong cây hậu tố và cây hậu tố ẩn, mỗi cạnh tương ứng với một chuỗi; mỗi nút không phải gốc $x$ tương ứng với một tập chuỗi, gồm chuỗi đi từ gốc đến nút cha $fa_x$ của $x$, nối với một tiền tố không rỗng bất kỳ của chuỗi trên cạnh từ $fa_x$ đến $x$. Tập này được gọi là $str_x$. Đồng thời, trong cây hậu tố ẩn, một hậu tố không tương ứng với bất kỳ nút nào được gọi là **hậu tố ẩn**.

Hình dưới đây, từ trái sang phải, lần lượt là trie hậu tố, cây hậu tố và cây hậu tố ẩn được xây dựng từ chuỗi mẹ $\texttt{cabab}$.

![Trie hậu tố, cây hậu tố và cây hậu tố ẩn của chuỗi cabab](./images/suffix-tree1.png)

Xét việc chèn từng hậu tố của $S$ vào trie hậu tố. Từ lần chèn thứ hai trở đi, mỗi lần nhiều nhất chỉ thêm một nút có nhiều hơn một con và một nút hậu tố, nên số nút trong cây hậu tố nhiều nhất là $2n$, rất tốt.

<span id="xây-dựng-cây-hậu-tố"></span>
## Xây dựng cây hậu tố

<span id="thuật-toán-hỗ-trợ-thêm-ký-tự-động-ở-đầu"></span>
### Thuật toán hỗ trợ thêm ký tự động ở đầu

Cây parent của SAM được xây dựng trên chuỗi đảo chính là cây hậu tố của chuỗi đó, vì vậy chỉ cần lần lượt thêm các ký tự của chuỗi đảo vào SAM.

???+ note "Cài đặt tham khảo"
    ```cpp
    struct SuffixAutomaton {
      int tot, lst;
      int siz[N << 1];
      int buc[N], id[N << 1];
    
      struct Node {
        int len, link;
        int ch[26];
      } st[N << 1];
    
      SuffixAutomaton() : tot(1), lst(1) {}
    
      void extend(int ch) {
        int cur = ++tot, p = lst;
        lst = cur;
        siz[cur] = 1, st[cur].len = st[p].len + 1;
        for (; p && !st[p].ch[ch]; p = st[p].link) st[p].ch[ch] = cur;
        if (!p)
          st[cur].link = 1;
        else {
          int q = st[p].ch[ch];
          if (st[q].len == st[p].len + 1)
            st[cur].link = q;
          else {
            int pp = ++tot;
            st[pp] = st[q];
            st[pp].len = st[p].len + 1;
            st[cur].link = st[q].link = pp;
            for (; p && st[p].ch[ch] == q; p = st[p].link) st[p].ch[ch] = pp;
          }
        }
      }
    } SAM;
    ```

<span id="thuật-toán-hỗ-trợ-thêm-ký-tự-động-ở-cuối"></span>
### Thuật toán hỗ trợ thêm ký tự động ở cuối

Thuật toán Ukkonen là một thuật toán xây dựng tăng dần. Lần lượt chèn từng ký tự của chuỗi $S$ vào cây, và sau mỗi lần chèn duy trì đúng cây hậu tố hiện tại.

<span id="thuật-toán-ngây-thơ"></span>
#### Thuật toán ngây thơ

Trước hết giới thiệu một cách xây dựng khá trực tiếp. Dùng chuỗi $\texttt {abbbc}$ để minh họa quá trình xây dựng.

Ban đầu tạo một nút gốc, gọi là nút số $0$. Đồng thời, với mỗi cạnh duy trì một đoạn $[l,r]$ biểu thị chuỗi trên cạnh là $S[l,r]$. Ngoài ra, duy trì số ký tự đã chèn $m$, ban đầu bằng $0$.

Đầu tiên chèn ký tự $\texttt a$, trực tiếp tạo từ nút $0$ một cạnh được gắn nhãn $[1,\infty]$, trỏ đến một nút mới. Ký hiệu $\infty$ là một giá trị rất lớn, có thể hiểu là cuối chuỗi; nhờ vậy khi chèn ký tự mới, cạnh này tự động chứa thêm ký tự mới.

![Cây hậu tố sau khi chèn ký tự a](./images/suffix-tree2.webp)

Tiếp theo chèn ký tự $\texttt b$, cũng tạo từ nút $0$ một cạnh được gắn nhãn $[2,\infty]$. Lưu ý rằng ý nghĩa của cạnh $[1,\infty]$ đã tạo trước đó tự động thay đổi: khi cuối chuỗi thay đổi, chuỗi mà nó biểu diễn chuyển từ $\texttt a$ thành $\texttt {ab}$. Điều này đúng, vì mọi hậu tố trước đó đều đã xuất hiện trong cây dưới dạng nút lá; chỉ cần chèn ký tự hiện tại vào cuối mọi nút lá.

![Cây hậu tố sau khi chèn chuỗi ab](./images/suffix-tree3.webp)

Tiếp theo, lại chèn một ký tự $\texttt b$. Nhưng $\texttt b$ đã là một chuỗi con của chuỗi đã chèn trước đó, nên cây hiện có đã chứa $\texttt b$. Lúc này không làm gì, và ghi lại một $k$ sao cho $S[k,m]$ là hậu tố ẩn dài nhất hiện tại.

![Cây hậu tố sau khi chèn chuỗi abb](./images/suffix-tree4.webp)

Tiếp theo chèn thêm một $\texttt b$. Vì ký tự $\texttt b$ trước đó chưa chèn thành công, lúc này $k=3$, biểu thị hậu tố cần chèn là $\texttt {bb}$. Tìm $\texttt {bb}$ từ gốc xuống và thấy nó cũng đã nằm trong cây. Tương tự, vẫn không làm gì.

![Cây hậu tố sau khi chèn chuỗi abbb](./images/suffix-tree5.webp)

Lưu ý rằng không xét các hậu tố sau $k$. Vì nếu $S[k,m]$ là một hậu tố ẩn, thì với $l>k$, $S[l,m]$ đều là hậu tố ẩn. Do $S[k,m]$ là hậu tố ẩn, tồn tại ký tự $c$ sao cho $S[k, m] + c$ là chuỗi con của $S$, do đó $S[l, m] + c$ cũng là chuỗi con của $S$. Theo định nghĩa của cây hậu tố ẩn, $S[l, m]$ cũng không xuất hiện dưới dạng nút lá.

Tiếp theo chèn $\texttt c$. Lúc này $k=3$, vì vậy cần tìm $\texttt {bbc}$ từ gốc xuống và thấy nó không có trong cây. Cần tạo một cạnh đi ra nhãn $[5,\infty]$ tại nút biểu diễn $\texttt {bb}$. Nhưng nút này không tồn tại như một nút riêng mà nằm bên trong một cạnh; vì vậy cần tách cạnh này, tạo một nút mới, rồi tại nút vừa tạo kéo ra cạnh cần tạo. Lần này chèn thành công, đặt $k\to k+1$, vì $S[k,m]$ không còn là hậu tố ẩn.

![Tách cạnh khi chèn chuỗi abbbc](./images/suffix-tree6.webp)

Tiếp theo, vì $k$ đã thay đổi, lặp lại quá trình này cho đến khi lại xuất hiện hậu tố ẩn, hoặc $k>m$ (trong ví dụ này là trường hợp sau).

![Cây hậu tố sau khi hoàn tất chèn chuỗi abbbc](./images/suffix-tree7.webp)

Quá trình xây dựng kết thúc.

Thuật toán này mỗi lần đều tìm và chèn thẳng từ gốc xuống, độ phức tạp xấu nhất là $O(n)$, nên tổng độ phức tạp là $O(n^2)$.

<span id="liên-kết-hậu-tố"></span>
#### Liên kết hậu tố

Thuật toán ngây thơ chậm chủ yếu vì mỗi lần `extend` đều phải tìm từ gốc đến vị trí chèn của hậu tố ẩn dài nhất. Vì vậy có thể ghi lại vị trí này. Trước hết, dùng một cặp $(now,rem)$ để mô tả hậu tố dài nhất hiện đang được chứa ẩn, $S[k,m]$. Đi theo cạnh đi ra từ nút $now$ có ký tự đầu là $S[m-rem+1]$ với độ dài $rem$ sẽ đến một vị trí biểu diễn duy nhất một chuỗi. Mỗi lần chèn ký tự mới, chỉ cần tìm từ vị trí được mô tả bởi $now$ và $rem$.

Bây giờ chỉ cần cập nhật $(now,rem)$ khi $k\to k + 1$. Nếu $now=0$, chỉ cần cho $rem \to rem-1$, vì hậu tố tiếp theo cần chèn có độ dài giảm $1$ so với hậu tố vừa chèn. Ngược lại, giả sử chuỗi con tương ứng với $str_{now}$ là $S[l,r]$, cần tìm một nút $now'$ tương ứng với $S[l+1,r]$, rồi đặt $now\to now'$.

Trước hết có bổ đề: với mọi nút $x$ trong cây hậu tố ẩn không phải lá và không phải gốc, tồn tại một nút không phải lá khác $y$ trong cây sao cho $str_y$ là chuỗi thu được từ chuỗi tương ứng với $str_x$ sau khi bỏ ký tự đầu.

Chứng minh. Gọi $s$ là chuỗi thu được từ $str_x$ sau khi bỏ ký tự đầu. Theo định nghĩa cây hậu tố ẩn, tồn tại hai ký tự khác nhau $c_1,c_2$ sao cho $str_x + c_1$ và $str_x + c_2$ đều là chuỗi con của $S$. Vì vậy $s + c_1$ và $s + c_2$ cũng là chuỗi con của $S$, nên trong trie hậu tố, $s$ cũng tương ứng với một điểm then chốt có phân nhánh, tức là trong trie hậu tố ẩn tồn tại $y$ sao cho $str_y=s$. Chứng minh xong.

Từ bổ đề này, định nghĩa $\operatorname{Link}(x)=y$, gọi là **liên kết hậu tố (Suffix Link)** của $x$. Khi đó $now'=\operatorname{Link}(now)$ tồn tại theo bổ đề. Bây giờ chỉ cần tính được $\operatorname{Link}$ cho mọi nút không phải gốc và không phải lá trong cây hậu tố ẩn.

<span id="thuật-toán-ukkonen"></span>
#### Thuật toán Ukkonen

Quy trình tổng thể của thuật toán Ukkonen như sau:

Để xây dựng cây hậu tố ẩn, thêm các ký tự của $S$ từ trái sang phải. Giả sử nút gốc là $0$, hiện đã xây dựng cây hậu tố ẩn của $S[1, m]$ và đã duy trì xong các liên kết hậu tố. Hậu tố ẩn dài nhất của $S[1, m]$ là $S[k, m]$, có vị trí trong cây là $(now, rem)$. Đặt $S[m + 1] = x$, bây giờ cần thêm ký tự $x$. Lúc này mọi hậu tố của $S[1, m]$ đều cần thêm ký tự $x$ vào cuối. Vì mọi hậu tố hiển thị đều tương ứng với một nút lá trong cây, và đầu mút phải của cạnh cha của chúng là $\infty$, nên không cần bảo trì. Do đó, chỉ cần xét ảnh hưởng của việc thêm $x$ vào cuối các hậu tố ẩn đối với hình dạng cây. Trước hết xét $S[k, m]$, có hai trường hợp:

1.  Vị trí $(now, rem)$ đã có chuyển tiếp bằng $x$. Khi đó hình dạng cây hậu tố không thay đổi. Vì $S[k, m+1]$ đã xuất hiện trong cây hậu tố, nên với $l > k$, $S[l, m + 1]$ cũng sẽ xuất hiện trong cây hậu tố. Lúc này chỉ cần đặt $rem\to rem + 1$, không cần sửa gì thêm.
2.  Vị trí $(now, rem)$ không có chuyển tiếp bằng $x$. Nếu $(now, rem)$ đúng là một nút trong cây, thêm một cạnh đi ra bằng $x$ từ nút này; nếu không, cần tách cạnh, thêm một nút mới tại vị trí này, rồi thêm cạnh đi ra bằng $x$ tại nút mới. Lúc này với $l > k$, chưa biết $S[l, m]$ sẽ ảnh hưởng ra sao đến hình dạng cây hậu tố, nên cần tiếp tục xét $S[k + 1, m]$. Cách tìm vị trí của $S[k + 1, m]$ trong cây hậu tố: nếu $now$ khác $0$, dùng liên kết hậu tố và đặt $now = \operatorname{Link}(now)$; nếu không, đặt $rem\to rem - 1$. Cuối cùng đặt $k\to k + 1$ và lặp lại quá trình.

Mỗi bước chỉ tốn thời gian hằng số, và thuật toán dừng sau khi chèn toàn bộ ký tự, nên độ phức tạp thời gian là $O(n)$.

Vì thuật toán Ukkonen chỉ xây dựng được cây hậu tố ẩn của $S$, trong khi cây hậu tố ẩn có thể không đủ mạnh cho một số bài toán, khi cần có thể thêm vào cuối $S$ một ký tự chưa từng xuất hiện. Khi đó mọi hậu tố của $S$ có thể tương ứng một-một với mọi lá của cây.

???+ note "Cài đặt tham khảo"
    ```cpp
    struct SuffixTree {
      int ch[M + 5][RNG + 1], st[M + 5], len[M + 5], link[M + 5];
      int s[N + 5];
      int now{1}, rem{0}, n{0}, tot{1};
    
      SuffixTree() { len[0] = inf; }
    
      int new_node(int s, int le) {
        ++tot;
        st[tot] = s;
        len[tot] = le;
        return tot;
      }
    
      void extend(int x) {
        s[++n] = x;
        ++rem;
        for (int lst{1}; rem;) {
          while (rem > len[ch[now][s[n - rem + 1]]])
            rem -= len[now = ch[now][s[n - rem + 1]]];
          int &v{ch[now][s[n - rem + 1]]}, c{s[st[v] + rem - 1]};
          if (!v || x == c) {
            lst = link[lst] = now;
            if (!v)
              v = new_node(n, inf);
            else
              break;
          } else {
            int u{new_node(st[v], rem - 1)};
            ch[u][c] = v;
            ch[u][x] = new_node(n, inf);
            st[v] += rem - 1;
            len[v] -= rem - 1;
            lst = link[lst] = v = u;
          }
          if (now == 1)
            --rem;
          else
            now = link[now];
        }
      }
    } Tree;
    ```

<span id="vai-trò"></span>
## Vai trò

Mỗi đường đi từ một nút trên cây hậu tố đến gốc đều là một chuỗi con không rỗng của $S$, điều này rất hữu ích khi xử lý nhiều bài toán chuỗi.

Thứ tự DFS của cây hậu tố chính là mảng hậu tố. Một cây con của cây hậu tố cũng tương ứng với một đoạn trên mảng hậu tố. Tiền tố chung dài nhất của hai hậu tố trên cây hậu tố là LCA của hai nút lá tương ứng với chúng. Vì vậy, kết luận về `height` của mảng hậu tố có thể hiểu là: LCA của một số nút trên cây bằng LCA của nút nhỏ nhất và lớn nhất theo thứ tự DFS trong số đó.

<span id="bài-tập-ví-dụ"></span>
## Bài tập ví dụ

<span id="luogu-p3804-mẫu-máy-tự-động-hậu-tố-sam"></span>
### [Luogu P3804 [Mẫu] Máy tự động hậu tố (SAM)](https://www.luogu.com.cn/problem/P3804)

Tóm tắt đề bài:

Cho một chuỗi $S$ chỉ gồm chữ cái thường.

Tìm giá trị lớn nhất của số lần xuất hiện của một chuỗi con nhân với độ dài chuỗi con đó, xét trên mọi chuỗi con của $S$ có số lần xuất hiện khác $1$.

??? note "Lời giải"
    Xây dựng cây hậu tố ẩn sau khi chèn thêm một ký tự kết thúc. Mỗi đường đi xuất phát từ gốc trên cây đều tạo thành một chuỗi con. Số lần xuất hiện của một hậu tố hiển thị chính là số nút lá trong cây con của nút tương ứng; các hậu tố ẩn không cần xét, vì số lần xuất hiện của một hậu tố ẩn bằng số lần xuất hiện của hậu tố hiển thị đầu tiên gặp được khi đi xuống, và hậu tố ẩn không dài hơn hậu tố hiển thị đó. Vì vậy duyệt toàn bộ cây, tính số lá trong cây con của mỗi nút và độ dài đường đi từ mỗi nút đến gốc. Nếu số lá $>1$ thì cập nhật đáp án. Độ phức tạp $O(|S||\Sigma|)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/suffix-tree/suffix-tree_1.cpp"
    ```

<span id="cf235c-cyclical-quest"></span>
### [CF235C Cyclical Quest](https://codeforces.com/problemset/problem/235/C)

Tóm tắt đề bài: Cho một chuỗi mẹ $S$ chỉ gồm chữ cái thường và $n$ chuỗi truy vấn, tính tổng số lần xuất hiện trong chuỗi mẹ của tất cả chuỗi đồng cấu vòng của mỗi chuỗi truy vấn $x_i$.

??? note "Lời giải"
    Xây dựng cây hậu tố ẩn sau khi chèn ký tự kết thúc.
    
    Liệt kê chu kỳ hiện tại và ghi lại độ dài tiền tố có thể tìm được trên cây.
    
    Lặp lại quá trình tương tự thuật toán Ukkonen, ghi lại vị trí hiện có thể khớp tới là $(now,rem)$. Mỗi lần thử chèn ký tự tiếp theo; nếu thành công thì tiếp tục chèn, nếu không thì thoát khỏi vòng lặp.
    
    Nếu một lần nào đó khớp thành công chu kỳ hiện tại, và chu kỳ đó chưa từng xuất hiện trước đó, thì cập nhật đáp án.
    
    Sau đó khi chuyển sang chu kỳ tiếp theo, cần xóa ký tự đầu của chuỗi con đang khớp: điều này đúng bằng việc đặt $now \to \operatorname{Link}(now)$. Nếu $now=1$ thì chỉ cần đặt $rem\to rem-1$.
    
    Độ phức tạp $O(|S||\Sigma|+\sum|x_i|)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/suffix-tree/suffix-tree_2.cpp"
    ```

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

1.  Bài luận đội tuyển quốc gia năm 2021 "Xây dựng cây hậu tố", Dai Chenxin
2.  [Ảo thuật cây hậu tố thú vị, blog của EternalAlexander](https://www.luogu.com.cn/blog/EternalAlexander/xuan-ku-hou-zhui-shu-mo-shu)
