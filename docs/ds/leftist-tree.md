author: JiZiQian, llleixx, firefly-zjyjoe

<span id="cây-lệch-trái-là-gì"></span>

## Cây lệch trái là gì?

**Cây lệch trái** cũng như [**heap ghép cặp**](./pairing-heap.md), là một loại **heap có thể hợp nhất**: nó có tính chất heap và có thể hợp nhất nhanh.

<span id="định-nghĩa-và-tính-chất-của-cây-lệch-trái"></span>

## Định nghĩa và tính chất của cây lệch trái

Với một cây nhị phân, ta định nghĩa **nút ngoài** là nút có số con nhỏ hơn hai. $\mathrm{dist}$ của một nút là số cạnh trên đường đi từ nút đó tới nút ngoài gần nhất trong cây con của nó. $\mathrm{dist}$ của nút rỗng là $0$.

???+ note "Lưu ý"
    Trong một số tài liệu, $\mathrm{dist}$ được định nghĩa bằng $\mathrm{dist}$ trong bài này trừ $1$. Cách định nghĩa đó giúp khi viết code có thể bỏ qua một số bước kiểm tra rỗng, nhưng cần đặt trước $\mathrm{dist}$ của nút rỗng là $-1$. Tất cả code trong bài này đều dùng định nghĩa **$\mathrm{dist}$ của nút rỗng là $-1$**, hãy chú ý điểm khác biệt này so với định nghĩa $\mathrm{dist}$ trong phần diễn giải.

Cây lệch trái là một cây nhị phân. Nó không chỉ có tính chất heap mà còn "lệch trái": tại mỗi nút, $\mathrm{dist}$ của con trái luôn lớn hơn hoặc bằng $\mathrm{dist}$ của con phải.

Do đó, $\mathrm{dist}$ của mỗi nút trong cây lệch trái đều bằng $\mathrm{dist}$ của con phải cộng một.

Cần lưu ý rằng $\mathrm{dist}$ không phải là độ sâu. **Độ sâu của cây lệch trái không được bảo đảm**, một chuỗi chỉ đi về bên trái vẫn thỏa mãn định nghĩa cây lệch trái.

<span id="thao-tác-cốt-lõi-hợp-nhất-merge"></span>

## Thao tác cốt lõi: hợp nhất (merge)

Khi hợp nhất hai heap, để thỏa mãn tính chất heap, trước hết lấy gốc có giá trị nhỏ hơn (cho tiện, bài này xét heap nhỏ) làm gốc của heap sau khi hợp nhất. Sau đó giữ con trái của gốc này làm con trái của heap mới, rồi đệ quy hợp nhất con phải của nó với heap còn lại để làm con phải của heap mới. Để thỏa mãn tính chất lệch trái, sau khi hợp nhất, nếu $\mathrm{dist}$ của con trái nhỏ hơn $\mathrm{dist}$ của con phải thì đổi chỗ hai con.

Code tham khảo:

???+ note "Cài đặt"
    ```cpp
    int merge(int x, int y) {
      if (!x || !y) return x | y;  // Nếu một heap rỗng thì trả về heap còn lại
      if (t[x].val > t[y].val) swap(x, y);  // Lấy nút có giá trị nhỏ hơn làm gốc
      t[x].rs = merge(t[x].rs, y);          // Đệ quy hợp nhất con phải với heap còn lại
      if (t[t[x].rs].d > t[t[x].ls].d)
        swap(t[x].ls, t[x].rs);   // Nếu không thỏa tính chất lệch trái thì đổi hai con
      t[x].d = t[t[x].rs].d + 1;  // Cập nhật dist
      return x;
    }
    ```

Nhờ tính chất lệch trái, mỗi khi đệ quy xuống một tầng, $\mathrm{dist}$ của gốc một trong hai heap sẽ giảm $1$. Mặt khác, trong một cây nhị phân có $n$ nút, $\mathrm{dist}$ của gốc không vượt quá $\left\lceil\log (n+1)\right\rceil$, nên độ phức tạp khi hợp nhất hai heap có kích thước lần lượt là $n$ và $m$ là $O(\log n+\log m)$.

???+ note "Chứng minh tính chất của $\mathrm{dist}$"
    Một cây nhị phân có $\mathrm{dist}$ của gốc bằng $x$ thì ít nhất $x-1$ tầng của nó là cây nhị phân đầy đủ, do đó có ít nhất $2^x-1$ nút. Lưu ý tính chất này đúng với mọi cây nhị phân, không phải tính chất riêng của cây lệch trái.

Cây lệch trái còn có một cách viết không cần hoán đổi con trái và con phải: xem con có $\mathrm{dist}$ lớn hơn là con trái, con có $\mathrm{dist}$ nhỏ hơn là con phải:

???+ note "Cài đặt"
    ```cpp
    int& rs(int x) { return t[x].ch[t[t[x].ch[1]].d < t[t[x].ch[0]].d]; }
    
    int merge(int x, int y) {
      if (!x || !y) return x | y;
      if (t[x].val < t[y].val) swap(x, y);
      int& rs_ref = rs(x);
      rs_ref = merge(rs_ref, y);
      t[x].d = t[rs(x)].d + 1;
      return x;
    }
    ```

<span id="các-thao-tác-khác-của-cây-lệch-trái"></span>

## Các thao tác khác của cây lệch trái

<span id="chèn-nút"></span>

### Chèn nút

Một nút đơn lẻ cũng có thể xem là một heap, vì vậy chỉ cần hợp nhất.

<span id="xóa-gốc"></span>

### Xóa gốc

Chỉ cần hợp nhất hai con trái và phải của gốc.

<span id="xóa-nút-bất-kỳ"></span>

### Xóa nút bất kỳ

<span id="cách-làm"></span>

#### Cách làm

Trước hết hợp nhất hai con trái và phải, rồi cập nhật $\mathrm{dist}$ từ dưới lên. Khi không thỏa mãn tính chất lệch trái thì đổi chỗ hai con, và khi $\mathrm{dist}$ không cần cập nhật nữa thì kết thúc đệ quy:

???+ note "Cài đặt"
    ```cpp
    int& rs(int x) { return t[x].ch[t[t[x].ch[1]].d < t[t[x].ch[0]].d]; }
    
    // Có pushup thì chỉ cần merge hai con là xóa được nút và vẫn giữ tính chất lệch trái
    int merge(int x, int y) {
      if (!x || !y) return x | y;
      if (t[x].val < t[y].val) swap(x, y);
      int& rs_ref = rs(x);
      rs_ref = merge(rs_ref, y);
      t[rs_ref].fa = x;
      t[x].d = t[rs(x)].d + 1;
      return x;
    }
    
    void pushup(int x) {
      if (!x) return;
      if (t[x].d != t[rs(x)].d + 1) {
        t[x].d = t[rs(x)].d + 1;
        pushup(t[x].fa);
      }
    }
    
    void erase(int x) {
      int y = merge(t[x].ch[0], t[x].ch[1]);
      t[y].fa = t[x].fa;
      if (t[t[x].fa].ch[0] == x)
        t[t[x].fa].ch[0] = y;
      else if (t[t[x].fa].ch[1] == x)
        t[t[x].fa].ch[1] = y;
      pushup(t[y].fa);
    }
    ```

<span id="chứng-minh-độ-phức-tạp"></span>

#### Chứng minh độ phức tạp

Trước hết xét quá trình `merge`: mỗi lần đều làm cho $x$ hoặc $y$ đi xuống một tầng. Nói cách khác, trong tình huống cực đoan nhất, ta luôn chọn nút phải của cây lệch trái (nút có $\mathrm{dist}$ nhỏ nhất) để đi xuống một tầng; lúc này $\mathrm{dist}$ giảm $1$.

Tiếp theo xét quá trình `pushup`. Gọi nút hiện tại mà `pushup` đang xử lý là $x$, cha của nó là $y$, và gọi "$\mathrm{dist}$ ban đầu" của một nút là $\mathrm{dist}$ của nó trước khi `pushup`. Bắt đầu đệ quy từ cha của nút bị xóa, có hai trường hợp:

1.  $x$ là con phải của $y$. Khi đó $\mathrm{dist}$ ban đầu của $y$ bằng $\mathrm{dist}$ ban đầu của $x$ cộng một.
2.  $x$ là con trái của $y$. Vì $\mathrm{dist}$ của một nút giảm nhiều nhất một, nên chỉ khi $\mathrm{dist}$ ban đầu của hai con trái phải của $y$ bằng nhau (lúc này $\mathrm{dist}$ của con trái giảm một sẽ khiến hai con đổi chỗ) thì đệ quy mới tiếp tục. Do đó $\mathrm{dist}$ ban đầu của $y$ vẫn bằng $\mathrm{dist}$ ban đầu của $x$ cộng một.

Vì vậy, ta có: mỗi khi đệ quy lên một tầng, $\mathrm{dist}$ ban đầu của $x$ sẽ tăng một, nên số tầng đệ quy tối đa là $O(\log n)$.

<span id="cộngtrừ-một-giá-trị-cho-toàn-bộ-heap-nhân-với-một-số-dương"></span>

### Cộng/trừ một giá trị cho toàn bộ heap, nhân với một số dương

Thực ra, mọi thao tác có thể gắn tag mà không làm thay đổi thứ tự tương đối đều xử lý được.

Gắn tag ở gốc, rồi khi xóa gốc/hợp nhất heap (tức là khi truy cập con) thì đẩy tag xuống:

???+ note "Cài đặt"
    ```cpp
    int merge(int x, int y) {
      if (!x || !y) return x | y;
      if (t[x].val > t[y].val) swap(x, y);
      pushdown(x);
      t[x].rs = merge(t[x].rs, y);
      if (t[t[x].rs].d > t[t[x].ls].d) swap(t[x].ls, t[x].rs);
      t[x].d = t[t[x].rs].d + 1;
      return x;
    }
    
    int pop(int x) {
      pushdown(x);
      return merge(t[x].ls, t[x].rs);
    }
    ```

<span id="các-heap-có-thể-hợp-nhất-khác"></span>

## Các heap có thể hợp nhất khác

<span id="heap-ngẫu-nhiên"></span>

### Heap ngẫu nhiên

???+ note "Cài đặt"
    ```cpp
    int merge(int x, int y) {
      if (!x || !y) return x | y;
      if (t[y].val < t[x].val) swap(x, y);
      if (rand() & 1)  // Chọn ngẫu nhiên có hoán đổi hai con hay không
        swap(t[x].ls, t[x].rs);
      t[x].ls = merge(t[x].ls, y);
      return x;
    }
    ```

Có thể thấy điểm khác biệt duy nhất của cách cài đặt này là dùng số ngẫu nhiên để hợp nhất, nhờ đó có thể bỏ các tính toán liên quan đến $\mathrm{dist}$. Độ phức tạp thời gian trung bình cũng là $O(\log n)$; chứng minh chi tiết có thể xem tại [Randomized Heap](https://cp-algorithms.com/data_structures/randomized_heap.html).

<span id="heap-nghiêng"></span>

### Heap nghiêng

Heap nghiêng là dạng tự thích nghi của cây lệch trái. Khi hợp nhất hai heap, nó đổi chỗ vô điều kiện tất cả các nút trên đường hợp nhất để cố gắng duy trì cân bằng. Theo phân tích khấu hao, với heap nghiêng từ trên xuống (top-down skew heap), độ phức tạp của chèn, hợp nhất và xóa giá trị nhỏ nhất là $O(\log n)$[^ref1].

<span id="bài-tập-ví-dụ"></span>

## Bài tập ví dụ

<span id="bài-mẫu"></span>

### Bài mẫu

[Luogu P3377【Mẫu】Cây lệch trái (heap có thể hợp nhất)](https://www.luogu.com.cn/problem/P3377)

[Monkey King](https://www.luogu.com.cn/problem/P1456)

[Trò chơi La Mã](https://www.luogu.com.cn/problem/P2713)

Cần chú ý:

1.  Trước khi hợp nhất, cần kiểm tra xem hai nút đã ở trong cùng một heap hay chưa.

2.  Độ sâu của cây lệch trái có thể đạt $O(n)$, vì vậy muốn tìm đỉnh heap chứa một điểm thì phải dùng DSU để duy trì, không thể nhảy cha trực tiếp theo cách vét cạn. (Dù dữ liệu của nhiều bài khá yếu, nhảy cha vét cạn vẫn có thể qua...) (Khi dùng DSU để duy trì gốc, cần bảo đảm gốc cũ trỏ tới gốc mới, còn gốc mới trỏ tới chính nó.)

??? note "Mã tham khảo cho Trò chơi La Mã"
    ```cpp
    --8<-- "docs/ds/code/leftist-tree/leftist-tree_1.cpp"
    ```

<span id="bài-toán-trên-cây"></span>

### Bài toán trên cây

[APIO2012 Dispatching](https://www.luogu.com.cn/problem/P1552)

[JLOI2015 Chiếm thành trì](https://loj.ac/problem/2107)

Trong dạng bài này, thường mỗi nút duy trì một heap, hợp nhất với các con, rồi theo đề mà pop, sửa đổi và tính đáp án; nó hơi giống các bài hợp nhất cây phân đoạn.

??? note "Mã tham khảo cho Chiếm thành trì"
    ```cpp
    --8<-- "docs/ds/code/leftist-tree/leftist-tree_2.cpp"
    ```

<span id="scoi2011-thao-tác-hóc-búa"></span>

### [SCOI2011 Thao tác hóc búa](https://loj.ac/problem/2441)

Trước hết, để tìm đỉnh heap chứa một nút, cần dùng DSU, không thể nhảy lên trên bằng vét cạn.

Tiếp theo xét truy vấn một điểm. Nếu dùng cách thông thường để gắn tag, ta phải truy vấn tổng tag trên đường từ điểm đó tới gốc, trường hợp xấu nhất có thể đạt độ phức tạp $O(n)$. Nếu chỉ đỉnh heap có tag thì có thể truy vấn nhanh, nhưng làm thế nào để đạt được điều đó?

Có thể dùng cách tương tự hợp nhất heuristic: mỗi lần hợp nhất, đẩy tag của heap nhỏ hơn xuống từng nút bằng vét cạn, rồi dùng tag của heap lớn hơn làm tag của heap sau khi hợp nhất. Vì sau khi hợp nhất sẽ có tag của heap còn lại, khi đẩy tag của heap nhỏ hơn xuống ta cần đẩy giá trị bằng tag của nó trừ tag của heap kia. Do mỗi lần một nút được hợp nhất, kích thước heap chứa nó ít nhất nhân đôi, nên mỗi nút nhiều nhất bị đẩy tag xuống $O(\log n)$ lần; tổng độ phức tạp của việc đẩy tag vét cạn là $O(n\log n)$.

Tiếp theo xét cộng vào một điểm: xóa trước, cập nhật, rồi chèn lại.

Cuối cùng là giá trị lớn nhất toàn cục. Có thể dùng cây cân bằng/heap hỗ trợ xóa nút bất kỳ (như cây lệch trái)/multiset để duy trì đỉnh heap của mỗi heap.

Vì vậy, các thao tác lần lượt như sau:

1.  Đẩy tag của heap có ít nút hơn bằng vét cạn, hợp nhất hai heap, cập nhật size và tag, rồi trong multiset xóa đỉnh heap cũ không còn là đỉnh heap sau hợp nhất.
2.  Xóa nút, cập nhật giá trị, chèn lại, rồi cập nhật multiset. Cần xét riêng trường hợp nút bị xóa có phải là gốc hay không.
3.  Gắn tag lên đỉnh heap, cập nhật multiset.
4.  Gắn tag toàn cục.
5.  Truy vấn giá trị + tag của đỉnh heap + tag toàn cục.
6.  Truy vấn giá trị của gốc + tag của đỉnh heap + tag toàn cục.
7.  Truy vấn giá trị lớn nhất trong multiset + tag toàn cục.

??? note "Mã tham khảo cho Thao tác hóc búa"
    ```cpp
    --8<-- "docs/ds/code/leftist-tree/leftist-tree_3.cpp"
    ```

<span id="boi2004-sequence-dãy-số"></span>

### [BOI2004 Sequence Dãy số](https://www.luogu.com.cn/problem/P4331)

Đây là một bài được trình bày trong luận văn; xem chi tiết tại [Huang Yuanhe - Đặc điểm và ứng dụng của cây lệch trái](https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2005%E8%AE%BA%E6%96%87%E9%9B%86/%E9%BB%84%E6%BA%90%E6%B2%B3--%E5%B7%A6%E5%81%8F%E6%A0%91%E7%9A%84%E7%89%B9%E7%82%B9%E5%8F%8A%E5%85%B6%E5%BA%94%E7%94%A8/%E9%BB%84%E6%BA%90%E6%B2%B3.pdf).

<span id="tài-liệu-tham-khảo"></span>

## Tài liệu tham khảo

[^ref1]: [Self-Adjusting Heaps](https://epubs.siam.org/doi/10.1137/0215004)
