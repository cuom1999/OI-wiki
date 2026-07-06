author: JiZiQian, llleixx, firefly-zjyjoe

<span id="cây-lệch-trái-là-gì"></span>

## Cây lệch trái là gì?

**Cây lệch trái**, giống như [**heap ghép cặp**](./pairing-heap.md), là một loại **heap có thể hợp nhất**:
nó vừa thỏa tính chất heap, vừa hỗ trợ hợp nhất nhanh.

<span id="định-nghĩa-và-tính-chất-của-cây-lệch-trái"></span>

## Định nghĩa và tính chất của cây lệch trái

Với một cây nhị phân, **nút ngoài** là nút có số con nhỏ hơn hai.
$\mathrm{dist}$ của một nút là số cạnh trên đường đi từ nút đó tới nút ngoài gần nhất trong cây con của nó.
$\mathrm{dist}$ của nút rỗng là $0$.

???+ note "Lưu ý"
    Trong một số tài liệu, $\mathrm{dist}$ được định nghĩa bằng $\mathrm{dist}$ trong bài này trừ $1$.
    Cách định nghĩa đó giúp mã nguồn bỏ qua một số bước kiểm tra rỗng, nhưng phải quy ước $\mathrm{dist}$ của nút rỗng
    là $-1$. Mã trong bài này dùng quy ước **$\mathrm{dist}$ của nút rỗng là $-1$**, cần phân biệt với định nghĩa dùng
    trong phần diễn giải.

Cây lệch trái là một cây nhị phân. Ngoài tính chất heap, nó còn "lệch trái":
tại mỗi nút, $\mathrm{dist}$ của con trái luôn lớn hơn hoặc bằng $\mathrm{dist}$ của con phải.

Do đó, $\mathrm{dist}$ của mỗi nút trong cây lệch trái đều bằng $\mathrm{dist}$ của con phải cộng một.

Cần lưu ý rằng $\mathrm{dist}$ không phải là độ sâu.
**Độ sâu của cây lệch trái không có cận bảo đảm**; một chuỗi chỉ đi về bên trái vẫn thỏa mãn định nghĩa cây lệch trái.

<span id="thao-tác-cốt-lõi-hợp-nhất-merge"></span>

## Thao tác cốt lõi: hợp nhất (merge)

Khi hợp nhất hai heap, trước hết lấy gốc có giá trị nhỏ hơn làm gốc của heap sau hợp nhất để giữ tính chất heap (bài này
xét min-heap). Sau đó giữ nguyên con trái của gốc này, rồi đệ quy hợp nhất con phải của nó với heap còn lại để tạo con
phải mới. Để giữ tính chất lệch trái, sau khi hợp nhất, nếu $\mathrm{dist}$ của con trái nhỏ hơn $\mathrm{dist}$ của con
phải thì đổi chỗ hai con.

Mã tham khảo:

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

Nhờ tính chất lệch trái, mỗi khi đệ quy xuống một tầng, $\mathrm{dist}$ của gốc một trong hai heap sẽ giảm $1$.
Mặt khác, trong một cây nhị phân có $n$ nút, $\mathrm{dist}$ của gốc không vượt quá $\left\lceil\log (n+1)\right\rceil$.
Vì vậy, độ phức tạp khi hợp nhất hai heap có kích thước lần lượt là $n$ và $m$ là $O(\log n+\log m)$.

???+ note "Chứng minh tính chất của $\mathrm{dist}$"
    Nếu một cây nhị phân có $\mathrm{dist}$ của gốc bằng $x$, thì ít nhất $x-1$ tầng của nó là cây nhị phân đầy đủ, nên
    cây có ít nhất $2^x-1$ nút.
    Tính chất này đúng với mọi cây nhị phân, không phải tính chất riêng của cây lệch trái.

Cây lệch trái còn có một cách viết không cần hoán đổi tường minh con trái và con phải: xem con có $\mathrm{dist}$ lớn hơn
là con trái, con có $\mathrm{dist}$ nhỏ hơn là con phải.

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

Trước hết hợp nhất hai con trái và phải, rồi cập nhật $\mathrm{dist}$ từ dưới lên.
Nếu không thỏa tính chất lệch trái thì đổi chỗ hai con; khi $\mathrm{dist}$ không cần cập nhật nữa thì kết thúc đệ quy.

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

Trước hết xét quá trình `merge`: mỗi lần gọi đều làm cho $x$ hoặc $y$ đi xuống một tầng. Trong trường hợp cực đoan nhất,
quá trình luôn đi theo nút phải của cây lệch trái, tức nút có $\mathrm{dist}$ nhỏ nhất; khi đó $\mathrm{dist}$ giảm $1$.

Tiếp theo xét quá trình `pushup`. Gọi nút hiện tại mà `pushup` đang xử lý là $x$, cha của nó là $y$.
Gọi "$\mathrm{dist}$ ban đầu" của một nút là $\mathrm{dist}$ của nó trước khi `pushup`.
Khi đệ quy bắt đầu từ cha của nút bị xóa, có hai trường hợp:

1.  $x$ là con phải của $y$. Khi đó $\mathrm{dist}$ ban đầu của $y$ bằng $\mathrm{dist}$ ban đầu của $x$ cộng một.
2.  $x$ là con trái của $y$. Vì $\mathrm{dist}$ của một nút giảm nhiều nhất một,
    đệ quy chỉ tiếp tục khi $\mathrm{dist}$ ban đầu của hai con trái/phải của $y$ bằng nhau.
    Lúc này, $\mathrm{dist}$ của con trái giảm một sẽ khiến hai con đổi chỗ.
    Do đó $\mathrm{dist}$ ban đầu của $y$ vẫn bằng $\mathrm{dist}$ ban đầu của $x$ cộng một.

Vì vậy, mỗi khi đệ quy lên một tầng, $\mathrm{dist}$ ban đầu của $x$ sẽ tăng một, nên số tầng đệ quy tối đa là
$O(\log n)$.

<span id="cộngtrừ-một-giá-trị-cho-toàn-bộ-heap-nhân-với-một-số-dương"></span>

### Cộng/trừ một giá trị cho toàn bộ heap, nhân với một số dương

Nhìn chung, mọi thao tác có thể gắn đánh dấu lười mà không làm thay đổi thứ tự tương đối đều xử lý được.

Gắn đánh dấu ở gốc; khi xóa gốc hoặc hợp nhất heap, tức khi cần truy cập con, thì đẩy đánh dấu xuống:

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

Điểm khác biệt duy nhất của cách cài đặt này là dùng số ngẫu nhiên trong quá trình hợp nhất,
nhờ đó có thể bỏ các tính toán liên quan đến $\mathrm{dist}$.
Độ phức tạp thời gian trung bình cũng là $O(\log n)$;
chứng minh chi tiết có thể xem tại [Randomized Heap](https://cp-algorithms.com/data_structures/randomized_heap.html).

<span id="heap-nghiêng"></span>

### Heap nghiêng

Heap nghiêng là dạng tự thích nghi của cây lệch trái.
Khi hợp nhất hai heap, nó đổi chỗ vô điều kiện tất cả các nút trên đường hợp nhất để cố gắng duy trì cân bằng.
Theo phân tích khấu hao, với heap nghiêng từ trên xuống (top-down skew heap),
độ phức tạp của chèn, hợp nhất và xóa giá trị nhỏ nhất là $O(\log n)$[^ref1].

<span id="bài-tập-ví-dụ"></span>

## Bài tập ví dụ

<span id="bài-mẫu"></span>

### Bài mẫu

[Luogu P3377【Mẫu】Cây lệch trái (heap có thể hợp nhất)](https://www.luogu.com.cn/problem/P3377)

[Monkey King](https://www.luogu.com.cn/problem/P1456)

[Trò chơi La Mã](https://www.luogu.com.cn/problem/P2713)

Cần chú ý:

1.  Trước khi hợp nhất, cần kiểm tra xem hai nút đã ở trong cùng một heap hay chưa.

2.  Độ sâu của cây lệch trái có thể đạt $O(n)$, vì vậy muốn tìm đỉnh heap chứa một điểm thì phải dùng DSU để duy trì,
    không thể nhảy cha trực tiếp bằng vét cạn.
    Dù dữ liệu của nhiều bài khá yếu và nhảy cha vét cạn vẫn có thể qua,
    khi dùng DSU để duy trì gốc cần giữ cho gốc cũ trỏ tới gốc mới, còn gốc mới trỏ tới chính nó.

??? note "Mã tham khảo cho Trò chơi La Mã"
    ```cpp
    --8<-- "docs/ds/code/leftist-tree/leftist-tree_1.cpp"
    ```

<span id="bài-toán-trên-cây"></span>

### Bài toán trên cây

[APIO2012 Dispatching](https://www.luogu.com.cn/problem/P1552)

[JLOI2015 Chiếm thành trì](https://loj.ac/problem/2107)

Trong dạng bài này, thường mỗi nút duy trì một heap, hợp nhất với các con, rồi tùy đề mà pop, sửa đổi và tính đáp án.
Cách xử lý này gần giống các bài hợp nhất cây phân đoạn.

??? note "Mã tham khảo cho Chiếm thành trì"
    ```cpp
    --8<-- "docs/ds/code/leftist-tree/leftist-tree_2.cpp"
    ```

<span id="scoi2011-thao-tác-hóc-búa"></span>

### [SCOI2011 Thao tác hóc búa](https://loj.ac/problem/2441)

Trước hết, để tìm đỉnh heap chứa một nút, cần dùng DSU, không thể nhảy lên trên bằng vét cạn.

Tiếp theo xét truy vấn một điểm. Nếu dùng cách thông thường để gắn đánh dấu,
cần truy vấn tổng các đánh dấu trên đường từ điểm đó tới gốc; trường hợp xấu nhất có thể đạt $O(n)$.
Nếu chỉ đỉnh heap có đánh dấu thì có thể truy vấn nhanh, nhưng làm thế nào để đạt được điều đó?

Có thể dùng cách tương tự hợp nhất theo kinh nghiệm: mỗi lần hợp nhất, đẩy đánh dấu của heap nhỏ hơn xuống từng nút bằng
vét cạn, rồi dùng đánh dấu của heap lớn hơn làm đánh dấu của heap sau hợp nhất. Vì sau khi hợp nhất sẽ dùng đánh dấu của
heap còn lại, khi đẩy đánh dấu của heap nhỏ hơn xuống cần đẩy lượng bằng đánh dấu của nó trừ đánh dấu của heap kia. Mỗi
lần một nút được hợp nhất, kích thước heap chứa nó ít nhất nhân đôi, nên mỗi nút bị đẩy đánh dấu xuống nhiều nhất
$O(\log n)$ lần.
Tổng độ phức tạp của việc đẩy đánh dấu vét cạn là $O(n\log n)$.

Tiếp theo xét cộng vào một điểm: xóa trước, cập nhật, rồi chèn lại.

Cuối cùng là giá trị lớn nhất toàn cục.
Có thể dùng cây cân bằng, heap hỗ trợ xóa nút bất kỳ (như cây lệch trái), hoặc `multiset` để duy trì đỉnh heap của mỗi
heap.

Vì vậy, các thao tác lần lượt như sau:

1.  Đẩy đánh dấu của heap có ít nút hơn bằng vét cạn, hợp nhất hai heap, cập nhật kích thước và đánh dấu,
    rồi xóa khỏi `multiset` đỉnh heap cũ không còn là đỉnh heap sau hợp nhất.
2.  Xóa nút, cập nhật giá trị, chèn lại, rồi cập nhật multiset. Cần xét riêng trường hợp nút bị xóa có phải là gốc hay
    không.
3.  Gắn đánh dấu lên đỉnh heap, cập nhật multiset.
4.  Gắn đánh dấu toàn cục.
5.  Truy vấn giá trị + đánh dấu của đỉnh heap + đánh dấu toàn cục.
6.  Truy vấn giá trị của gốc + đánh dấu của đỉnh heap + đánh dấu toàn cục.
7.  Truy vấn giá trị lớn nhất trong multiset + đánh dấu toàn cục.

??? note "Mã tham khảo cho Thao tác hóc búa"
    ```cpp
    --8<-- "docs/ds/code/leftist-tree/leftist-tree_3.cpp"
    ```

<span id="boi2004-sequence-dãy-số"></span>

### [BOI2004 Sequence Dãy số](https://www.luogu.com.cn/problem/P4331)

Đây là một bài được trình bày trong luận văn; xem chi tiết tại
[Huang Yuanhe - Đặc điểm và ứng dụng của cây lệch trái][huang-leftist-tree].

<span id="tài-liệu-tham-khảo"></span>

## Tài liệu tham khảo

[^ref1]: [Self-Adjusting Heaps](https://epubs.siam.org/doi/10.1137/0215004)

[huang-leftist-tree]: https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2005%E8%AE%BA%E6%96%87%E9%9B%86/%E9%BB%84%E6%BA%90%E6%B2%B3--%E5%B7%A6%E5%81%8F%E6%A0%91%E7%9A%84%E7%89%B9%E7%82%B9%E5%8F%8A%E5%85%B6%E5%BA%94%E7%94%A8/%E9%BB%84%E6%BA%90%E6%B2%B3.pdf
