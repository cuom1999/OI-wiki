author: Dev-XYS, ttzytt, Sora233, qwqAutomaton

Kiến thức cần có: [Cây tìm kiếm nhị phân mộc mạc](./bst.md), [Cơ sở về heap](./heap.md).

## Giới thiệu

Treap là một **cây tìm kiếm nhị phân** **cân bằng yếu**.

Ngoài **giá trị** cần được duy trì ($\textit{val}$), mỗi nút của Treap còn có thêm một **độ ưu tiên** ngẫu nhiên ($\textit{priority}$). Trong đó, giá trị thỏa mãn tính chất của cây tìm kiếm nhị phân, còn độ ưu tiên thỏa mãn tính chất heap (min-heap hoặc max-heap).

Tính chất của cây tìm kiếm nhị phân là:

-   Giá trị ($\textit{val}$) của mỗi nút trong cây con trái nhỏ hơn nút cha.
-   Giá trị ($\textit{val}$) của mỗi nút trong cây con phải lớn hơn nút cha.

Tính chất của heap là:

-   Độ ưu tiên ($\textit{priority}$) của nút con lớn hơn hoặc nhỏ hơn nút cha, tùy theo đó là min-heap hay max-heap.

Có thể thấy rằng nếu dùng cùng một giá trị cho cả hai cấu trúc, khi kết hợp lại cấu trúc sẽ biến thành một chuỗi. Vì vậy, trên nền tảng cây tìm kiếm, Treap đưa thêm một giá trị $\textit{priority}$ cho heap. Với giá trị $\textit{val}$, duy trì tính chất cây tìm kiếm; với giá trị $\textit{priority}$, duy trì tính chất heap. Giá trị $\textit{priority}$ này được gán ngẫu nhiên.

Hình dưới đây là một ví dụ về Treap (dùng min-heap, tức nút gốc có độ ưu tiên nhỏ nhất).

![Một ví dụ về Treap](./images/treap-treap-example.svg)

Vì sao cấu trúc dữ liệu này cần đồng thời thỏa mãn tính chất của cây và heap, đồng thời gán ngẫu nhiên giá trị heap?

Để hiểu điều này, trước hết cần xét vấn đề của cây tìm kiếm nhị phân mộc mạc. Khi chèn một nút mới vào cây tìm kiếm mộc mạc, quá trình đệ quy bắt đầu từ nút gốc của cây. Nếu nút mới nhỏ hơn nút hiện tại thì đệ quy sang trái, ngược lại thì đệ quy sang phải.

Cuối cùng, khi gặp một nút hiện tại không có nút con phù hợp, dựa vào quan hệ lớn nhỏ của giá trị nút mới mà đặt nó làm nút con trái hoặc nút con phải của nút hiện tại.

Nếu giá trị của các nút được chèn là ngẫu nhiên (nói cách khác, chèn theo thứ tự ngẫu nhiên), chiều cao của cây tìm kiếm mộc mạc này sẽ nhỏ (gần $\log n$, trong đó $n$ là số nút), và số nút trên mỗi tầng khá lớn, tức hình dạng của cây khá "bè ngang". Treap trong hình trên là một ví dụ. Khi đó độ phức tạp của mỗi thao tác sẽ vào khoảng $O(\log n)$.

Tuy nhiên, đó chỉ là độ phức tạp trong trường hợp ngẫu nhiên. Nếu chèn nút vào một cây tìm kiếm mộc mạc theo thứ tự rất có quy luật như sau:

```plain
1 2 3 4 5
```

Thì cây này sẽ suy biến thành một chuỗi, tức trở nên rất "thon dài" (mỗi nút được chèn đều lớn hơn các nút trước đó, nên đều bị đặt vào nút con phải):

![Ví dụ suy biến thành chuỗi](./images/treap-search-tree-chain.svg)

Khi đó độ phức tạp truy vấn cũng từ $O(\log n)$ biến thành $O(n)$.

Để giải quyết vấn đề này và đạt trạng thái tương đối "cân bằng", Treap duy trì các độ ưu tiên ngẫu nhiên thỏa mãn tính chất heap, qua đó "xáo trộn" thứ tự chèn nút, giúp cây tìm kiếm nhị phân đạt độ phức tạp mong muốn và tránh suy biến thành chuỗi.

## Chứng minh độ phức tạp của Treap

Vì độ phức tạp của các thao tác trên Treap đều liên quan đến độ sâu của nút được thao tác, trước hết chứng minh độ sâu kỳ vọng của mỗi nút đều là $O(\log n)$.

### Quy ước ký hiệu

Để tiện trình bày, quy ước:

-   $n$ là số nút.
-   Trong nút Treap, giá trị thỏa mãn tính chất cây tìm kiếm nhị phân được gọi là **giá trị**, còn giá trị thỏa mãn tính chất heap (tức ngẫu nhiên) được gọi là **độ ưu tiên**. Không mất tính tổng quát, giả sử độ ưu tiên thỏa mãn tính chất min-heap.
-   $x_k$ biểu thị nút có giá trị nhỏ thứ $k$.
-   $X_{i,j}$ biểu thị tập $\{x_i,x_{i+1},\cdots,x_{j-1},x_j\}$, tức tập các nút từ thứ $i$ đến thứ $j$ sau khi sắp xếp tăng dần theo giá trị.
-   $\operatorname{dep}(x)$ biểu thị độ sâu của nút $x$. Quy định độ sâu của nút gốc là $0$.
-   $Y_{i,j}$ là một biến ngẫu nhiên chỉ thị; khi $x_i$ là tổ tiên của $x_j$ thì có giá trị $1$, ngược lại là $0$. Đặc biệt, $Y_{i,i}=0$.
-   $\Pr(A)$ biểu thị xác suất xảy ra sự kiện $A$.

### Chứng minh độ sâu kỳ vọng của nút

Vì độ sâu của nút $x_i$ bằng số tổ tiên của nó, có

$$
\operatorname{dep}(x_i)=\sum_{k=1}^nY_{k,i}.
$$

Theo tính tuyến tính của kỳ vọng, có

$$
E(\operatorname{dep}(x_i))=E\left(\sum_{k=1}^nY_{k,i}\right)=\sum_{k=1}^nE(Y_{k,i}).
$$

Vì $Y_{k,i}$ là biến ngẫu nhiên chỉ thị, kỳ vọng của nó bằng xác suất nó có giá trị $1$, nên

$$
E(\operatorname{dep}(x_i))=\sum_{k=1}^n\Pr(Y_{k,i}=1).
$$

Trước hết chứng minh bổ đề: $Y_{i,j}=1$ khi và chỉ khi độ ưu tiên của $x_i$ là nhỏ nhất trong $X_{i,j}$.

??? note "Chứng minh bổ đề"
    Xét các trường hợp của $x_i$ và $x_j$.

    1.  Nếu $x_i$ là nút gốc: do độ ưu tiên thỏa mãn tính chất min-heap, độ ưu tiên của $x_i$ là nhỏ nhất, và với mọi $x_j$, $x_i$ đều là tổ tiên của $x_j$.
    2.  Nếu $x_j$ là nút gốc: tương tự, do độ ưu tiên của $x_j$ là nhỏ nhất, nên $x_i$ không phải nút có độ ưu tiên nhỏ nhất trong $X_{i,j}$; đồng thời $x_i$ cũng không phải tổ tiên của $x_j$.
    3.  Nếu $x_i$ và $x_j$ nằm trong hai cây con của nút gốc (một trái, một phải), thì nút gốc $r\in X_{i,j}$. Do đó độ ưu tiên của $x_i$ không thể là nhỏ nhất trong $X_{i,j}$ (vì độ ưu tiên của nút gốc nhỏ hơn nó). Đồng thời, vì $x_i$ và $x_j$ thuộc hai cây con khác nhau, $x_i$ cũng không phải tổ tiên của $x_j$.
    4.  Nếu $x_i$ và $x_j$ nằm trong cùng một cây con của nút gốc, có thể tách riêng cây con này thành một Treap mới và chứng minh đệ quy như trên.

Theo bổ đề, kỳ vọng của độ sâu có thể chuyển thành

$$
E(\operatorname{dep}(x_i))=\sum_{k=1}^n\Pr(x_k=\min X_{i,k}\land k\neq i).
$$

Vì độ ưu tiên của các nút là ngẫu nhiên, giả định mỗi nút trong tập $X_{i,j}$ có xác suất như nhau để có độ ưu tiên nhỏ nhất. Khi đó

$$
\begin{aligned}
E(\operatorname{dep}(x_i))&=\sum_{k=1}^n\Pr(x_k=\min X_{i,k}\land k\neq i)\\
&=\sum_{k=1}^{n}\Pr(x_k=\min X_{i,k})-1\\
&=\sum_{k=1}^n\dfrac{1}{|i-k|+1}-1\\
&=\sum_{k=1}^{i-1}\dfrac{1}{i-k+1}+\sum_{k=i+1}^n\dfrac{1}{k-i+1}\\
&=\sum_{j=2}^i\dfrac 1j+\sum_{j=2}^{n-i+1}\dfrac 1j\\
&\le 2\sum_{j=2}^n\dfrac 1j < 2\sum_{j=2}^n\int_{j-1}^j\dfrac 1x\mathrm dx\\
&=2\int_1^n\dfrac 1x\mathrm dx=2\ln n=O(\log n).
\end{aligned}
$$

Do đó độ sâu kỳ vọng của mỗi nút đều là $O(\log n)$.

Độ phức tạp của các thao tác trên cây tìm kiếm nhị phân mộc mạc đều là $O(h)$, và độ phức tạp để Treap duy trì tính chất heap cũng là $O(h)$, nên độ phức tạp kỳ vọng của các thao tác trên Treap đều là $O(\log n)$.

???+ note "Cách hiểu trực quan về độ phức tạp kỳ vọng"
    Trước hết, cần nhận ra thuộc tính $\textit{priority}$ của một nút có liên hệ trực tiếp với tầng chứa nút đó. Nhắc lại tính chất heap:

    -   Giá trị nút con ($\textit{priority}$) lớn hơn hoặc nhỏ hơn nút cha, tùy theo đó là min-heap hay max-heap.

    Các nút ở tầng thấp, chẳng hạn nút gốc của toàn bộ cây, sẽ có thuộc tính $\textit{priority}$ nhỏ hơn (trong min-heap). Đồng thời, trong cây tìm kiếm mộc mạc, nút được chèn trước cũng có khả năng nằm ở tầng nông hơn. Có thể liên hệ thuộc tính $\textit{priority}$ này với thứ tự chèn để hiểu vì sao Treap có thể dùng $\textit{priority}$ để xáo trộn thứ tự chèn nút.

Khi chèn nút mới vào Treap, cần đồng thời duy trì tính chất của cây và của heap. Trong đó, tính chất cây tìm kiếm có thể được duy trì khi chèn, còn tính chất heap có hai cách xử lý: phép xoay và tách/hợp nhất. Treap dùng hai cách này lần lượt được gọi là **Treap xoay** và **Treap không xoay**.

## Treap xoay

**Treap xoay** duy trì cân bằng bằng phép xoay, tương tự thao tác xoay của cây AVL, gồm **xoay trái** và **xoay phải**. Tức là, với điều kiện vẫn thỏa mãn cây tìm kiếm nhị phân, Treap được cân bằng dựa theo độ ưu tiên của heap.

Khi làm các bài cây cân bằng thông thường, Treap xoay có hằng số nhỏ trong số các cây cân bằng.

Phần giải thích dưới đây dùng con trỏ để cài đặt Treap xoay; cuối bài có kèm cài đặt đầy đủ bằng mảng.

???+ info "Thông tin"
    Trong code, `rank` đại diện cho độ ưu tiên đã nói ở trên (thuộc tính $\textit{priority}$); thuộc tính này thỏa mãn tính chất min-heap.

### Cấu trúc nút

```cpp
struct Node {
  Node *ch[2];  // Địa chỉ của hai nút con
  int val, rank;
  int rep_cnt;  // Số lần giá trị hiện tại (val) xuất hiện lặp lại
  int siz;      // Kích thước cây con có gốc là nút hiện tại

  Node(int val) : val(val), rep_cnt(1), siz(1) {
    ch[0] = ch[1] = nullptr;
    rank = rand();
    // Lưu ý: khi khởi tạo, rank được gán ngẫu nhiên
  }

  void upd_siz() {
    // Dùng để tính lại giá trị siz sau khi xoay và xóa
    siz = rep_cnt;
    if (ch[0] != nullptr) siz += ch[0]->siz;
    if (ch[1] != nullptr) siz += ch[1]->siz;
  }
};
```

### Phép xoay

Phép xoay là một thao tác rất quan trọng của Treap, chủ yếu dùng để điều chỉnh tầng của các nút khác nhau trong khi vẫn giữ tính chất của Treap, qua đó duy trì tính chất heap.

Xoay trái và xoay phải có thể không quá dễ phân biệt. Dưới đây là hai đặc điểm khá rõ:

Ý nghĩa của thao tác xoay:

-   Không làm ảnh hưởng đến tính chất cây tìm kiếm; cây con ở hướng ngược với hướng xoay sẽ trở thành nút gốc (ví dụ xoay trái là biến cây con phải thành nút gốc).
-   Không ảnh hưởng đến tính chất heap; sau khi xoay, nút con cùng hướng với hướng xoay sẽ trở thành nút gốc ban đầu (ví dụ sau khi xoay trái, nút con trái là nút gốc trước khi xoay).

Thao tác xoay trái và xoay phải là hai thao tác đối xứng với nhau, như hình dưới đây.

![Thao tác xoay](./images/treap-rotate.svg)

```cpp
enum rot_type { LF = 1, RT = 0 };

void _rotate(Node *&cur,
             rot_type dir) {  // Tham số dir biểu thị hướng xoay: 0 là xoay phải, 1 là xoay trái
  // Lưu ý cur truyền vào là tham chiếu tới con trỏ, nên khi sửa cur này
  // thì biến bên ngoài cũng thay đổi theo. Nếu cur này là nút con của một cây khác,
  // lần theo ch cũng sẽ đến đúng vị trí này.

  // Các giải thích dưới đây đều là trường hợp xoay trái
  Node *tmp = cur->ch[dir];  // Cho C thành nút gốc,
                             // tmp là một con trỏ nút tạm, trỏ đến nút sẽ thành gốc mới

  /* Xoay trái: tức cho nút con phải thành nút gốc
   *         A                 C
   *        / \               / \
   *       B  C    ---->     A   E
   *         / \            / \
   *        D   E          B   D
   */
  cur->ch[dir] = tmp->ch[!dir];    // Cho nút con phải của A thành D
  tmp->ch[!dir] = cur;             // Cho nút con trái của C thành A
  cur->upd_siz(), tmp->upd_siz();  // Cập nhật thông tin kích thước
  cur = tmp;  // Cuối cùng gán biến tạm lưu cây C cho nút gốc hiện tại (lưu ý cur là tham chiếu)
}
```

### Chèn

Tương tự chèn trong cây tìm kiếm nhị phân thông thường, nhưng cần dùng phép xoay trong quá trình chèn để duy trì tính chất heap của độ ưu tiên.

```cpp
void _insert(Node *&cur, int val) {
  if (cur == nullptr) {
    // Không có nút này thì tạo mới trực tiếp
    cur = new Node(val);
    return;
  } else if (val == cur->val) {
    // Nếu đã có nút cùng giá trị, tăng số lần lặp lên một
    cur->rep_cnt++;
    cur->siz++;
  } else if (val < cur->val) {
    // Duy trì tính chất cây tìm kiếm: val nhỏ hơn nút hiện tại thì chèn bên trái, ngược lại bên phải
    _insert(cur->ch[0], val);
    if (cur->ch[0]->rank < cur->rank) {
      // Trong min-heap, độ ưu tiên của nút phía trên chắc chắn nhỏ hơn
      // Vì nút con trái mới chèn nhỏ hơn nút cha, bây giờ cần cho nút con trái thành nút cha
      _rotate(cur, RT);  // Lưu ý tính chất xoay ở trên: muốn đưa nút con trái lên thì cần xoay phải
    }
    cur->upd_siz();  // Sau khi chèn, kích thước thay đổi nên cần cập nhật
  } else {
    _insert(cur->ch[1], val);
    if (cur->ch[1]->rank < cur->rank) {
      _rotate(cur, LF);
    }
    cur->upd_siz();
  }
}
```

### Xóa

Chủ yếu là phân loại từng trường hợp; mỗi trường hợp có cách xử lý khác nhau. Sau khi xóa, kích thước cây thay đổi, cần chú ý cập nhật. Nếu nút cần xóa có cả cây con trái và cây con phải, cần xét sau khi xóa thì nút nào làm cha (duy trì nút có `rank` nhỏ hơn ở phía trên).

```cpp
void _del(Node *&cur, int val) {
  if (val > cur->val) {
    _del(cur->ch[1], val);
    // Giá trị lớn hơn thì nằm trong cây con phải, ngược lại nằm bên trái
    cur->upd_siz();
  } else if (val < cur->val) {
    _del(cur->ch[0], val);
    cur->upd_siz();
  } else {
    if (cur->rep_cnt > 1) {
      // Nếu nút cần xóa có giá trị lặp, chỉ cần giảm số lần lặp
      cur->rep_cnt--, cur->siz--;
      return;
    }
    uint8_t state = 0;
    state |= (cur->ch[0] != nullptr);
    state |= ((cur->ch[1] != nullptr) << 1);
    // 00: không có con; 01: có trái không phải; 10: không trái có phải; 11: có cả hai
    Node *tmp = cur;
    switch (state) {
      case 0:
        delete cur;
        cur = nullptr;
        // Không có nút con nào, xóa trực tiếp nút này
        break;
      case 1:  // Có trái không phải
        cur = tmp->ch[0];
        // Biến gốc thành con trái, rồi xóa nút gốc cũ. Lưu ý tmp được sao chép từ cur,
        // còn cur là tham chiếu
        delete tmp;
        break;
      case 2:  // Có phải không trái
        cur = tmp->ch[1];
        delete tmp;
        break;
      case 3:
        rot_type dir = cur->ch[0]->rank < cur->ch[1]->rank
                           ? RT
                           : LF;  // dir là hướng xoay để đưa con có rank nhỏ hơn lên
        _rotate(cur, dir);  // Phép xoay này có thể đưa con có độ ưu tiên nhỏ hơn lên; RT là 0,
                            // LF là 1, vừa hay ngược với chỉ số cây con thực tế
        _del(
            cur->ch[!dir],
            val);  // Sau khi xoay, nút gốc ban đầu nằm ở phía hướng xoay,
                   // nên cần tiếp tục xóa nút gốc ban đầu này.
                   // Nếu nút cần xóa nằm ở "tầng trên" của toàn cây, liên tục dùng
                   // các phép xoay này để đưa nó đến khi không còn cây con (hoặc chỉ có một cây con), rồi xóa nó.
        cur->upd_siz();
        // Xóa sẽ làm kích thước thay đổi
        break;
    }
  }
}
```

### Truy vấn hạng theo giá trị

Ý nghĩa thao tác: truy vấn hạng của giá trị `val` trong cây con có gốc là `cur` (số nút trong cây con nhỏ hơn `val` + 1).

```cpp
int _query_rank(Node *cur, int val) {
  int less_siz = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
  // Số nút trong cây này nhỏ hơn val
  if (val == cur->val)
    // Nếu nút này chính là nút cần tìm
    return less_siz + 1;
  else if (val < cur->val) {
    if (cur->ch[0] != nullptr)
      return _query_rank(cur->ch[0], val);
    else
      return 1;  // Nếu cây con trái rỗng, nghĩa là nhỏ hơn cả nút nhỏ nhất; số này là nhỏ nhất
  } else {
    if (cur->ch[1] != nullptr)
      // Nếu giá trị cần tìm lớn hơn nút này, thì cây con trái của nút này và bản thân nút này đều nhỏ hơn giá trị cần tìm
      // Vì vậy cần cộng hai giá trị này, rồi cộng kết quả tìm sang bên phải
      // (hạng của giá trị val trong cây con có gốc là cây con phải)
      return less_siz + cur->rep_cnt + _query_rank(cur->ch[1], val);
    else
      return cur->siz + 1;
    // Nếu không có cây con phải thì toàn bộ cây + 1, tương đương less_siz + cur->rep_cnt + 1
  }
}
```

### Truy vấn giá trị theo hạng

Để truy vấn giá trị theo hạng, trước hết cần biết cách xác định nút cần tìm nằm ở phần nào của cây:

Bảng dưới đây là một cách phân định:

| Cây con trái | Nút gốc/nút hiện tại | Cây con phải |
| ----------- | ---------------------------------- | ---------------------- |
| Hạng <= kích thước cây con trái | Hạng > kích thước cây con trái, và <= kích thước cây con trái + số lần lặp của nút gốc | Hạng > kích thước cây con trái + số lần lặp của nút gốc |

Lưu ý nếu nằm trong cây con phải, khi đệ quy cần xử lý `rank` ban đầu. Khi đệ quy, thao tác tương đương với việc tìm giá trị có hạng này trong cây con phải; để chuyển hạng sang cơ sở của cây con phải, cần lấy `rank` ban đầu trừ đi kích thước cây con trái và số lần lặp của nút gốc.

Có thể hình dung tất cả nút thành một mảng đã sắp xếp, hoặc một trục số (như dưới đây),

    1 -> |các nút của cây con trái|nút gốc|các nút của cây con phải| -> n
                               ^
                               hạng cần tìm
                         v chuyển thành hạng theo cây con phải
    1 -> |các nút của cây con phải| -> n
           ^
           hạng cần tìm

Cách chuyển đổi là trực tiếp trừ hạng đi kích thước cây con trái và số lần lặp của nút gốc.

```cpp
int _query_val(Node *cur, int rank) {
  // Truy vấn giá trị của nút có hạng rank trong cây
  int less_siz = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
  // less_siz là kích thước cây con trái
  if (rank <= less_siz)
    return _query_val(cur->ch[0], rank);
  else if (rank <= less_siz + cur->rep_cnt)
    return cur->val;
  else
    return _query_val(cur->ch[1], rank - less_siz - cur->rep_cnt);  // Xem phần trên
}
```

### Truy vấn nút đầu tiên nhỏ hơn val

Lưu ý phần này sử dụng một biến toàn cục trong lớp, `q_prev_tmp`.

Giá trị này chỉ được thay đổi khi `val` lớn hơn giá trị nút hiện tại, nên trả về biến này tức là trả về lần cuối cùng `val` lớn hơn giá trị nút hiện tại; sau đó các nút sẽ nhỏ hơn.

```cpp
int _query_prev(Node *cur, int val) {
  if (val <= cur->val) {
    // Vẫn lớn hơn hoặc bằng val, nên tìm sang cây con trái
    if (cur->ch[0] != nullptr) return _query_prev(cur->ch[0], val);
  } else {
    // Chỉ khi vào được nhánh else này mới cập nhật q_prev_tmp
    q_prev_tmp = cur->val;
    // Nút hiện tại đã nhỏ hơn val, nhưng chưa chắc là lớn nhất, nên tiếp tục tìm trong cây con phải
    if (cur->ch[1] != nullptr) _query_prev(cur->ch[1], val);
    // Các lần đệ quy tiếp theo có thể không thay đổi q_prev_tmp,
    // khi đó trả về trực tiếp giá trị này; nói tóm lại, giá trị trả về là cur->val
    // của lần cuối cùng vào nhánh else này
    return q_prev_tmp;
  }
  return NIL;
}
```

### Truy vấn nút đầu tiên lớn hơn val

Rất giống thao tác trước, chỉ đổi dấu lớn hơn và nhỏ hơn.

```cpp
int _query_nex(Node *cur, int val) {
  if (val >= cur->val) {
    if (cur->ch[1] != nullptr) return _query_nex(cur->ch[1], val);
  } else {
    q_nex_tmp = cur->val;
    if (cur->ch[0] != nullptr) _query_nex(cur->ch[0], val);
    return q_nex_tmp;
  }
  return NIL;
}
```

## Treap không xoay

Cách thao tác của Treap không xoay giúp nó tự nhiên hỗ trợ duy trì dãy, khả năng lưu phiên bản (persistent), và các đặc tính khác.

**Treap không xoay** còn được gọi là Treap tách-hợp nhất. Nó chỉ có hai thao tác lõi, đó là **tách** và **hợp nhất**. Trong nhiều trường hợp, nhờ hai thao tác này, việc cài đặt các thao tác khác sẽ tiện hơn so với Treap xoay. Dưới đây lần lượt giới thiệu hai thao tác này.

???+ note "Ghi chú"
    Khi giải thích Treap không xoay, nên nhắc đến **FHQ-Treap** (của Fan Haoqiang). Đây là Treap không xoay có thể lưu phiên bản (persistent) và hỗ trợ thao tác trên đoạn. Xem thêm trong ppt "Fan Haoqiang bàn về cấu trúc dữ liệu".

### Tách (split)

#### Tách theo giá trị

Quá trình tách nhận hai tham số: con trỏ gốc $\textit{cur}$ và khóa $\textit{key}$. Kết quả là tách Treap mà con trỏ gốc trỏ tới thành hai Treap: mỗi nút trong Treap thứ nhất có giá trị ($\textit{val}$) nhỏ hơn hoặc bằng $\textit{key}$, mỗi nút trong Treap thứ hai có giá trị lớn hơn $\textit{key}$.

Quá trình này trước hết kiểm tra $\textit{key}$ có nhỏ hơn giá trị của $\textit{cur}$ hay không. Nếu nhỏ hơn, điều đó cho thấy $\textit{cur}$ và toàn bộ cây con phải của nó đều lớn hơn $\textit{key}$, thuộc Treap thứ hai. Tất nhiên, một phần cây con trái cũng có thể có giá trị lớn hơn $\textit{key}$, nên cần tiếp tục đệ quy tách cây con trái. Với phần cây con trái lớn hơn $\textit{key}$, gán nó làm cây con trái của $\textit{cur}$; như vậy mọi nút trong toàn bộ $\textit{cur}$ đều lớn hơn $\textit{key}$.

Tương ứng, nếu $\textit{key}$ lớn hơn hoặc bằng giá trị của $\textit{cur}$, điều đó cho thấy toàn bộ cây con trái của $\textit{cur}$ và chính nó đều nhỏ hơn hoặc bằng $\textit{key}$, thuộc Treap thứ nhất sau khi tách. Đồng thời, một phần cây con phải của $\textit{cur}$ cũng có thể nhỏ hơn hoặc bằng $\textit{key}$, nên cần tiếp tục đệ quy tách cây con phải. Lấy phần nhỏ hơn hoặc bằng $\textit{key}$ làm cây con phải của $\textit{cur}$; như vậy mọi nút trong toàn bộ $\textit{cur}$ đều nhỏ hơn hoặc bằng $\textit{key}$.

Hình dưới đây minh họa trường hợp tách theo giá trị khi giá trị của $\textit{cur}$ nhỏ hơn hoặc bằng $\textit{key}$.[^ref1]

![Tách theo giá trị](./images/treap-none-rot-split-by-val.svg)

```cpp
pair<Node *, Node *> split(Node *cur, int key) {
  if (cur == nullptr) return {nullptr, nullptr};
  if (cur->val <= key) {
    // cur và cây con trái của nó chắc chắn thuộc cây thứ nhất sau khi tách
    auto temp = split(cur->ch[1], key);
    // Nhưng nó có thể có một phần cây con phải cũng nhỏ hơn key
    cur->ch[1] = temp.first;
    // Lấy phần nhỏ hơn key làm cây con phải của cur, như vậy toàn bộ cur đều nhỏ hơn
    // key; phần cây con phải còn lại trở thành Treap thứ hai sau khi tách
    cur->upd_siz();
    // Sau khi tách, kích thước cây thay đổi, cần cập nhật
    return {cur, temp.second};
  } else {
    // Tương tự như trên
    auto temp = split(cur->ch[0], key);
    cur->ch[0] = temp.second;
    cur->upd_siz();
    return {temp.first, cur};
  }
}
```

#### Tách theo hạng

So với tách theo giá trị, thao tác này giống truy vấn giá trị theo hạng trong Treap xoay hơn (hạng của một nút là số nút có giá trị nhỏ hơn nút đó trong cây $+ 1$):

Hàm này nhận hai tham số, con trỏ nút $\textit{cur}$ và hạng $\textit{rk}$, rồi trả về ba Treap sau khi tách.

Trong đó, mỗi nút trong Treap thứ nhất có hạng nhỏ hơn $\textit{rk}$, Treap thứ hai có hạng bằng $\textit{rk}$, và Treap thứ hai chỉ có một nút (không thể có nhiều nút bằng nhau; nếu có thì sẽ tăng `cnt` trong cấu trúc `Node`), còn Treap thứ ba là các nút lớn hơn.

Trọng tâm của thao tác này là xác định nút có hạng bằng $\textit{rk}$ nằm ở phần nào của cây. Đây cũng là phần quan trọng trong thao tác truy vấn giá trị theo hạng của Treap xoay, đã được giải thích chi tiết ở trên, nên không lặp lại nhiều.

Đồng thời, phần đệ quy của thao tác này cũng rất giống tách theo giá trị, nên không trình bày lại.

```cpp
tuple<Node *, Node *, Node *> split_by_rk(Node *cur, int rk) {
  if (cur == nullptr) return {nullptr, nullptr, nullptr};
  int ls_siz = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
  if (rk <= ls_siz) {
    // Nút có hạng bằng rk nằm trong cây con trái
    Node *l, *mid, *r;
    tie(l, mid, r) = split_by_rk(cur->ch[0], rk);
    cur->ch[0] = r;  // Các hạng trong Treap thứ ba trả về đều lớn hơn rk
    // Sau khi cây con trái của cur được gán thành r, mọi nút trong cur đều có hạng lớn hơn rk
    cur->upd_siz();
    return {l, mid, cur};
  } else if (rk <= ls_siz + cur->cnt) {
    // Nút bằng cur chính là nút hiện tại
    Node *lt = cur->ch[0];
    Node *rt = cur->ch[1];
    cur->ch[0] = cur->ch[1] = nullptr;
    // Treap thứ hai sau khi tách chỉ có một nút, nên cần đặt các cây con của nó thành rỗng
    return {lt, cur, rt};
  } else {
    // Nút có hạng bằng rk nằm trong cây con phải
    // Quá trình đệ quy tương tự như trên
    Node *l, *mid, *r;
    tie(l, mid, r) = split_by_rk(cur->ch[1], rk - ls_siz - cur->cnt);
    cur->ch[1] = l;
    cur->upd_siz();
    return {cur, mid, r};
  }
}
```

### Hợp nhất (merge)

Quá trình hợp nhất nhận hai tham số: con trỏ gốc của Treap trái $\textit{u}$ và con trỏ gốc của Treap phải $\textit{v}$. Cần thỏa mãn mọi nút trong $\textit{u}$ có giá trị nhỏ hơn hoặc bằng mọi nút trong $\textit{v}$. Thông thường, hai Treap được hợp nhất đều tách ra từ một Treap ban đầu, nên điều kiện mọi nút trong $\textit{u}$ có giá trị nhỏ hơn $\textit{v}$ được thỏa mãn tự nhiên.

Trong Treap xoay, thao tác xoay được dùng để duy trì $\textit{priority}$ thỏa mãn tính chất heap, đồng thời khi xoay không được làm thay đổi tính chất cây. Trong Treap không xoay, thao tác hợp nhất đạt hiệu ứng tương tự.

Vì hai Treap đã có thứ tự, khi hợp nhất chỉ cần xét cây nào được "đặt lên trên" và cây nào "đặt xuống dưới", tức cần xác định cây nào làm cây con. Theo tính chất heap, cần đặt $\textit{priority}$ nhỏ hơn lên trên (phần này dùng min-heap).

Đồng thời, vẫn cần thỏa mãn tính chất cây tìm kiếm. Vì vậy, nếu $\textit{priority}$ của nút gốc $\textit{u}$ nhỏ hơn của $\textit{v}$, thì $\textit{u}$ sẽ là nút gốc mới; do $\textit{v}$ có giá trị lớn hơn $\textit{u}$, nó cần được hợp nhất với cây con phải của $\textit{u}$. Ngược lại, $\textit{v}$ làm nút gốc mới; do giá trị của $u$ nhỏ hơn $\textit{v}$, hợp nhất với cây con trái của $v$.

```cpp
Node *merge(Node *u, Node *v) {
  // Hai cây truyền vào đã thỏa mãn tính chất cây tìm kiếm ở bên trong
  // Và mọi nút trong u có giá trị < mọi nút trong v
  // Nên khi hợp nhất cần duy trì tính chất heap
  // Đoạn này dùng min-heap
  if (u == nullptr && v == nullptr) return nullptr;
  if (u != nullptr && v == nullptr) return u;
  if (v != nullptr && u == nullptr) return v;

  if (u->prio < v->prio) {
    // prio của u nhỏ hơn, u nên làm nút cha
    u->ch[1] = merge(u->ch[1], v);
    // Vì v lớn hơn u, đặt v làm cây con phải của u
    u->upd_siz();
    return u;
  } else {
    // v nhỏ hơn, v nên làm nút cha
    v->ch[0] = merge(u, v->ch[0]);
    // u nhỏ hơn v, nên tham số khi đệ quy là như vậy
    v->upd_siz();
    return v;
  }
}
```

### Chèn

Trong Treap không xoay, các thao tác cơ bản như chèn, xóa, truy vấn hạng theo giá trị có thể cài đặt theo cách của cây tìm kiếm nhị phân thông thường, hoặc bằng tách và hợp nhất. Thông thường, dùng tách và hợp nhất để cài đặt sẽ ngắn gọn hơn, nhưng tốc độ chậm hơn một chút[^ref2]. Để giúp hiểu Treap không xoay tốt hơn, các thao tác dưới đây đều được cài đặt bằng tách và hợp nhất.

Khi cài đặt thao tác chèn, có thể tận dụng một số tính chất của thao tác tách. Cụ thể, các nút có giá trị nhỏ hơn hoặc bằng $\textit{val}$ sẽ được tách vào Treap thứ nhất.

Vì vậy, giả sử tách Treap hiện tại theo $\textit{val}$. Sẽ có hai cây sau, thỏa mãn các điều kiện:

$$
\begin{aligned}
T_1 &\le val\\
T_2 &> val
\end{aligned}
$$

Trong đó $T_1$ biểu thị tập tất cả nút được tách vào Treap thứ nhất, $T_2$ là tập thứ hai.

Nếu tiếp tục tách $T_1$ theo $\textit{val} - 1$, sẽ có hai cây sau và thỏa mãn các điều kiện:

$$
\begin{gathered}
T_{1\ \text{trái}} \le val - 1\\
T_{1\ \text{phải}} > val - 1 \ \text{và}\ T_{1\ \text{phải}} \le val
\end{gathered}
$$

Trong đó $T_{1\ \text{trái}}$ biểu thị tập tất cả nút được tách vào Treap thứ nhất sau khi tách $T_1$, còn $T_{1\ \text{phải}}$ là tập thứ hai. Trong công thức trên, phần sau $\text{và}\ T_{1\ \text{phải}} \le val$ đến từ điều kiện $T_1 \le val$ mà $T_1$ thỏa mãn.

Chỉ cần $\textit{val}$ và giá trị của nút là số nguyên (hầu hết trường hợp sử dụng đều dùng số nguyên), các nút thỏa mãn điều kiện $T_{1\ \text{phải}}$ chỉ có một loại, đó là nút có giá trị bằng $\textit{val}$.

Khi chèn, nếu nút thỏa mãn $T_{1\ \text{phải}}$ tồn tại, có thể trực tiếp tăng số lần lặp; ngược lại thì tạo một nút mới.

Lưu ý sau khi tách cây xong, vẫn cần dùng hợp nhất để "dán" nó lại, để lần sau có thể tiếp tục sử dụng. Đồng thời cần chú ý thứ tự tham số của thao tác hợp nhất có yêu cầu: mọi nút của cây thứ nhất phải nhỏ hơn các nút của cây thứ hai.

```cpp
void insert(int val) {
  auto temp = split(root, val);
  // Tách toàn bộ cây thành hai phần theo giá trị val
  // Lưu ý cài đặt split: cây con bằng val nằm ở cây con trái
  auto l_tr = split(temp.first, val - 1);
  // Cây con trái của l_tr <= val - 1; nếu có nút = val thì nó chắc chắn nằm ở cây con phải
  Node *new_node;
  if (l_tr.second == nullptr) {
    // Không có nút này thì tạo mới, ngược lại tăng trực tiếp số lần lặp.
    new_node = new Node(val);
  } else {
    l_tr.second->cnt++;
    l_tr.second->upd_siz();
  }
  Node *l_tr_combined =
      merge(l_tr.first, l_tr.second == nullptr ? new_node : l_tr.second);
  // Hợp nhất T_1 left và T_1 right
  root = merge(l_tr_combined, temp.second);
  // Hợp nhất T_1 và T_2
}
```

### Xóa

Thao tác xóa cũng dùng cách tương tự thao tác chèn: tìm nút có giá trị bằng $\textit{val}$ và xóa nó.

```cpp
void del(int val) {
  auto temp = split(root, val);
  auto l_tr = split(temp.first, val - 1);
  if (l_tr.second->cnt > 1) {
    // Nếu số lần lặp của nút này lớn hơn 1, chỉ cần giảm đi
    l_tr.second->cnt--;
    l_tr.second->upd_siz();
    l_tr.first = merge(l_tr.first, l_tr.second);
  } else {
    if (temp.first == l_tr.second) {
      // Có thể toàn bộ T_1 chỉ có nút này, nên cũng cần đặt điểm này thành null để đánh dấu đã xóa
      temp.first = nullptr;
    }
    delete l_tr.second;
    l_tr.second = nullptr;
  }
  root = merge(l_tr.first, temp.second);
}
```

### Truy vấn hạng theo giá trị

Hạng là số nút nhỏ hơn giá trị này $+ 1$, nên tách cây hiện tại theo $\textit{val} - 1$. Khi đó Treap thứ nhất sau khi tách thỏa mãn:

$$
T_1 \le val - 1
$$

Nếu giá trị trong cây và $\textit{val}$ là số nguyên, thì $T_1$ sẽ chứa tất cả nút có giá trị nhỏ hơn $\textit{val}$.

```cpp
int qrank_by_val(Node* cur, int val) {
  auto temp = split(cur, val - 1);
  int ret = (temp.first == nullptr ? 0 : temp.first->siz) + 1;  // + 1 theo định nghĩa
  root = merge(temp.first, temp.second);  // Tách xong thì dán lại
  return ret;
}
```

### Truy vấn giá trị theo hạng

Sau khi gọi hàm `split_by_rk()`, hàm sẽ trả về ba Treap đã tách xong. Trong đó Treap thứ hai chỉ chứa một nút, và hạng của nó bằng $\textit{rk}$, nên có thể trực tiếp trả về $\textit{val}$ của nút này.

```cpp
int qval_by_rank(Node *cur, int rk) {
  Node *l, *mid, *r;
  tie(l, mid, r) = split_by_rk(cur, rk);
  int ret = mid->val;
  root = merge(merge(l, mid), r);
  return ret;
}
```

### Truy vấn nút đầu tiên nhỏ hơn val

Có thể chuyển bài toán này thành: trong tất cả nút nhỏ hơn $\textit{val}$, tìm nút có hạng lớn nhất. Tách Treap này theo $\textit{val}$; mọi nút trong Treap thứ nhất trả về đều có giá trị nhỏ hơn $\textit{val}$, sau đó gọi `qval_by_rank()` để tìm nút có giá trị lớn nhất trong cây này.

```cpp
int qprev(int val) {
  auto temp = split(root, val - 1);
  // temp.first là cây con gồm các giá trị nhỏ hơn val
  int ret = qval_by_rank(temp.first, temp.first->siz);
  // Truy vấn giá trị lớn nhất trong tất cả nút nhỏ hơn val
  root = merge(temp.first, temp.second);
  return ret;
}
```

### Truy vấn nút đầu tiên lớn hơn val

Tương tự thao tác trên, có thể chuyển bài toán thành: trong tất cả nút lớn hơn $\textit{val}$, tìm nút có hạng nhỏ nhất. Khi tách theo $\textit{val}$, mọi nút trong Treap thứ hai được trả về đều có giá trị lớn hơn $\textit{val}$.

Sau đó truy vấn nút có hạng $1$ trong cây này (tức nút có giá trị nhỏ nhất), là tìm được nút đầu tiên lớn hơn $\textit{val}$.

```cpp
int qnex(int val) {
  auto temp = split(root, val);
  int ret = qval_by_rank(temp.second, 1);
  // Truy vấn giá trị nhỏ nhất trong cây con gồm tất cả nút lớn hơn val
  root = merge(temp.first, temp.second);
  return ret;
}
```

### Xây cây (build)

Chuyển một dãy có $n$ nút $\{a_n\}$ thành một Treap.

Có thể chèn lần lượt từng nút trong $n$ nút này một cách trực tiếp. Mỗi lần chèn một nút có giá trị $v$, tách toàn bộ Treap theo giá trị thành hai phần: giá trị nhỏ hơn hoặc bằng $v$ và giá trị lớn hơn $v$; sau đó tạo một nút mới có giá trị $v$, rồi hợp nhất hai phần và nút mới theo thứ tự tăng dần. Độ phức tạp mỗi lần chèn là $O(\log n)$, tổng độ phức tạp là $O(n\log n)$.

Trong một số bài, có thể có nhiều thao tác chèn một đoạn dãy đã sắp xếp; lúc này cần hoàn thành thao tác xây cây trong độ phức tạp $O(n)$.

Cách 1: Trong quá trình đệ quy xây cây, mỗi lần chọn điểm giữa của đoạn hiện tại làm gốc của cây trong đoạn, và gán cho mỗi nút một độ ưu tiên phù hợp để cây mới thỏa mãn tính chất heap. Cách này bảo đảm chiều cao cây là $O(\log n)$.

Cách 2: Trong quá trình đệ quy xây cây, mỗi lần chọn điểm giữa của đoạn hiện tại làm gốc của cây trong đoạn, sau đó gán cho mỗi nút một độ ưu tiên ngẫu nhiên. Cách này bảo đảm chiều cao cây là $O(\log n)$, nhưng không bảo đảm nó thỏa mãn tính chất heap. Cách này vẫn dùng được, vì độ ưu tiên của Treap không xoay dùng để làm thao tác `merge` ngẫu nhiên hơn, chứ không phải để bảo đảm chiều cao cây.

Cách 3: Nhận thấy Treap là cây Descartes, nên chỉ cần dùng phương pháp xây cây $O(n)$ của cây Descartes, dùng ngăn xếp đơn điệu để duy trì chuỗi phải.

### Thao tác đoạn của Treap không xoay

#### Xây cây

Một lợi thế lớn của Treap không xoay so với Treap xoay là có thể cài đặt nhiều loại thao tác trên đoạn. Phần dưới lấy [bài mẫu](https://loj.ac/problem/105) về cây cân bằng nghệ thuật làm ví dụ để giới thiệu thao tác đoạn của Treap.

> Cần viết một cấu trúc dữ liệu (có thể tham khảo tiêu đề bài) để duy trì một dãy có thứ tự.
>
> Cần cung cấp thao tác sau: đảo ngược một đoạn. Ví dụ dãy có thứ tự ban đầu là $5\ 4\ 3\ 2\ 1$, nếu đoạn đảo ngược là $[2,4]$, kết quả là $5\ 2\ 3\ 4\ 1$.
> Với $100\%$ dữ liệu, $1 \le n, m \le 10^5$, trong đó $n$ là độ dài dãy ban đầu và $m$ là số lần đảo ngược.

Trong bài này, cần cài đặt thao tác đảo ngược đoạn. Trước hết cần xét cách xây cây, cây được xây ra cần biểu diễn đoạn ban đầu.

Chỉ cần chèn lần lượt các chỉ số của đoạn vào Treap. Khi duyệt trung thứ tự (duyệt cây con trái trước, sau đó đến nút hiện tại, cuối cùng là cây con phải), kết quả thu được chính là đoạn này[^ref3].

Trong cây tìm kiếm nhị phân mộc mạc, nếu chèn nút theo thứ tự tăng dần, cây được tạo ra là một chuỗi dài; khi duyệt trung thứ tự, kết quả chính là đoạn này.

<div align=center>
  <img style="width: 50%; " src="../images/treap-search-tree-chain.svg" >
</div>

Như hình trên, nếu chèn các nút vào cây tìm kiếm mộc mạc theo thứ tự $1\ 2\ 3\ 4\ 5$, khi duyệt trung thứ tự cũng thu được $1\ 2\ 3\ 4\ 5$.

Nhưng trong Treap, sau khi chèn các nút theo thứ tự tăng dần, thao tác hợp nhất còn điều chỉnh cấu trúc cây dựa theo $\textit{priority}$. Trong trường hợp này, làm sao bảo đảm duyệt trung thứ tự nhất định xuất đúng?

Có thể tham khảo [phương pháp xây cây bằng ngăn xếp đơn điệu của cây Descartes](./cartesian-tree.md) để hiểu vấn đề này.

Giả sử nút mới chèn là $\textit{u}$.

Trước hết, vì chèn nút theo thứ tự tăng dần, mỗi nút mới chèn chắc chắn sẽ được nối vào chuỗi phải của Treap (tức chuỗi gồm các nút đi từ nút gốc liên tục sang cây con phải).

Bắt đầu từ nút gốc, độ ưu tiên $\textit{priority}$ của các nút trên chuỗi phải tăng dần (min-heap). Có thể tìm nút đầu tiên trên chuỗi phải có $\textit{priority}$ lớn hơn $\textit{u}$, gọi nút này là $\textit{v}$, và thay nút này bằng $\textit{u}$.

Vì $\textit{u}$ chắc chắn lớn hơn tất cả nút khác trong cây, cần đặt $\textit{v}$ và cây con của nó làm cây con trái của $\textit{u}$. Đồng thời lúc này $\textit{u}$ không có cây con phải.

Có thể thấy khi duyệt trung thứ tự, $\textit{u}$ chắc chắn là nút cuối cùng được duyệt (vì $\textit{u}$ là nút cuối trên chuỗi phải, mà trong duyệt trung thứ tự, cây con phải được duyệt cuối cùng).

Hình dưới đây cho thấy sự thay đổi khi chèn nút số $5$ trong quá trình chèn các nút $1 \sim 5$ vào Treap theo thứ tự tăng dần. Có thể dùng hình này để hiểu tốt hơn quá trình chèn tăng dần.

![Chèn nút](./images/treap-none-rot-seg-build.svg)

#### Đảo ngược đoạn

Khi đảo ngược đoạn $[l, r]$, ý tưởng cơ bản là tách cây thành ba đoạn $[1, l - 1],\ [l, r],\ [r + 1, n]$, rồi đảo ngược đoạn giữa $[l, r]$[^ref3].

Thao tác đảo ngược cụ thể là hoán đổi vị trí mọi cặp nút con trái và con phải trong cây con của đoạn. Hình dưới đây minh họa Treap sau khi đảo ngược các đoạn $[3, 4]$ và $[3, 5]$ của Treap ở hình trên.

![Đảo ngược đoạn](./images/treap-none-rot-seg-flip-ex.svg)

Lưu ý nếu đảo ngược theo cách này, mỗi lần đảo ngược đoạn $[l, r]$ sẽ có $r - l$ nút bị hoán đổi vị trí. Thao tác thường xuyên như vậy không đáp ứng được giới hạn dữ liệu $10^5$; độ phức tạp một lần đảo ngược $O(n \times \log_2 n)$ kém hiệu quả hơn cả làm trực tiếp (vì ngoài thời gian tuyến tính để hoán đổi nút, còn cần tốn $O(\log_2 n)$ để tìm các nút cần hoán đổi trong cây).

Quan sát lại yêu cầu bài toán, có thể thấy vì chỉ cần xuất đoạn cuối cùng sau tất cả thao tác, không cần mỗi lần đều hoán đổi thật. Do đó có thể dùng đánh dấu lười thường gặp trong cây phân đoạn để tối ưu độ phức tạp. Khi hoán đổi, chỉ cần gán đánh dấu trên nút cha, biểu thị mọi cặp nút con trái/phải dưới cây con này đều cần hoán đổi.

Trong cây phân đoạn, đánh dấu lười thường được đẩy xuống khi cập nhật và truy vấn. Lý do là khi cập nhật/truy vấn, phạm vi cần cập nhật/truy vấn không nhất thiết trùng với phạm vi mà đánh dấu lười đại diện, nên phải đẩy đánh dấu xuống trước để bảo đảm giá trị tìm được và giá trị sau cập nhật là đúng.

Trong Treap không xoay cũng vậy. Khi thao tác cụ thể, tách Treap thành ba cây như đã nói ở trên, sau đó gán đánh dấu lười cho cây ở giữa rồi hợp nhất ba cây này. Vì đoạn cần đảo ngược không nhất thiết trùng với đoạn mà đánh dấu lười đại diện, cần đẩy đánh dấu xuống khi tách. Đồng thời, thao tác tách và hợp nhất làm thay đổi mỗi nút và tập nút mà đánh dấu lười của nó đại diện, nên trước khi hợp nhất cũng cần đẩy đánh dấu lười xuống.

Nói cách khác, khi cấu trúc cây thay đổi, trước thời điểm một thao tác tách hoặc hợp nhất cần thay đổi thông tin con trái/con phải của một nút, nên đẩy đánh dấu xuống, không phải sau đó. Vì đánh dấu lười cần được đẩy cho các nút con; nếu đã thay đổi thông tin con trái/con phải mà đánh dấu lười chưa được đẩy xuống, đánh dấu lười sẽ mất đối tượng để đẩy xuống.[^ref4]

Dưới đây là phần giải thích mã, mã tham khảo từ [^ref3].

Vì phần lớn thao tác trong thao tác đoạn giống Treap không xoay thông thường, phần này chỉ giải thích những điểm khác với Treap không xoay thông thường.

#### Đẩy đánh dấu xuống

Cần lưu ý đánh dấu lười trong phần này biểu thị cần hoán đổi vị trí mọi cặp nút con trong cây này. Vì vậy nếu nút con của nút hiện tại cũng có đánh dấu lười, hai lần đảo ngược sẽ triệt tiêu nhau. Nếu nút con không cần đảo ngược, đánh dấu lười này cần tiếp tục được đẩy xuống nút con.

```cpp
// pushdown là hàm thành viên của lớp Node, trong đó to_rev là đánh dấu lười
void pushdown() {
  swap(ch[0], ch[1]);
  if (ch[0] != nullptr) ch[0]->to_rev ^= 1;
  if (ch[1] != nullptr) ch[1]->to_rev ^= 1;
  to_rev = false;
}

void check_tag() {
  if (to_rev) pushdown();
}
```

#### Tách

Lưu ý trong bài này, do thao tác đảo ngược, $\textit{val}$ trong Treap sẽ không thỏa mãn tính chất cây tìm kiếm nhị phân (xem hình ở phần đảo ngược đoạn), nên không thể dựa vào $\textit{val}$ để xác định nên đệ quy sang cây con trái hay phải.

Vì vậy, thao tác tách trong phần này giống tách theo hạng trong Treap không xoay thông thường hơn: dựa vào kích thước cây hiện tại để quyết định đệ quy sang trái hay phải. Nói cách khác, vị trí ban đầu của nút trong cây là căn cứ để xác định nhánh đệ quy.

Mỗi nút trong Treap thứ nhất trả về có hạng nhỏ hơn hoặc bằng $\textit{sz}$, còn mỗi nút trong Treap thứ hai có hạng lớn hơn $\textit{sz}$.

```cpp
#define siz(_) (_ == nullptr ? 0 : _->siz)

pair<Node*, Node*> split(Node* cur, int sz) {
  // Xác định theo kích thước cây
  if (cur == nullptr) return {nullptr, nullptr};
  cur->check_tag();
  // Đẩy đánh dấu xuống trước khi tách
  if (sz <= siz(cur->ch[0])) {
    auto temp = split(cur->ch[0], sz);
    cur->ch[0] = temp.second;
    cur->upd_siz();
    return {temp.first, cur};
  } else {
    auto temp =
        split(cur->ch[1],
              sz - siz(cur->ch[0]) -
                  1);  // Phép chuyển đổi này đã được giải thích ở phần "truy vấn giá trị theo hạng" của Treap xoay
    cur->ch[1] = temp.first;
    cur->upd_siz();
    return {cur, temp.second};
  }
}
```

#### Hợp nhất

Điểm duy nhất cần chú ý là đẩy đánh dấu lười xuống trước khi hợp nhất.

```cpp
Node *merge(Node *sm, Node *bg) {
  // small, big
  if (sm == nullptr && bg == nullptr) return nullptr;
  if (sm != nullptr && bg == nullptr) return sm;
  if (sm == nullptr && bg != nullptr) return bg;
  sm->check_tag(), bg->check_tag();
  if (sm->prio < bg->prio) {
    sm->ch[1] = merge(sm->ch[1], bg);
    sm->upd_siz();
    return sm;
  } else {
    bg->ch[0] = merge(sm, bg->ch[0]);
    bg->upd_siz();
    return bg;
  }
}
```

#### Đảo ngược đoạn

Giống như đã giới thiệu ở trên, tách ra ba đoạn $[1, l - 1],\ [l, r],\ [r + 1, n]$, sau đó gán tag cho đoạn giữa rồi hợp nhất lại.

```cpp
void seg_rev(int l, int r) {
  // less và more là tương đối theo l
  auto less = split(root, l - 1);
  // Tất cả phần nhỏ hơn hoặc bằng l - 1 sẽ nằm bên trái của less
  auto more = split(less.second, r - l + 1);
  // Đoạn gồm r - l + 1 phần tử bắt đầu từ l
  more.first->to_rev = true;
  root = merge(less.first, merge(more.first, more.second));
}
```

#### In bằng duyệt trung thứ tự

Cần chú ý đẩy đánh dấu xuống khi in.

```cpp
void print(Node* cur) {
  if (cur == nullptr) return;
  cur->check_tag();
  // Duyệt trung thứ tự -> trái trước, rồi đến bản thân, cuối cùng là phải
  print(cur->ch[0]);
  cout << cur->val << " ";
  print(cur->ch[1]);
}
```

## Mã đầy đủ

### Treap xoay

#### Cài đặt bằng con trỏ

??? note "Mã đầy đủ"
    Dưới đây là phiên bản đầy đủ của mã đã giải thích ở trên, là mã mẫu cho bài cây cân bằng thông thường.

    ```cpp
    // author: (ttzytt)[ttzytt.com]
    #include <cstdint>
    #include <cstdio>
    #include <cstdlib>
    using namespace std;

    struct Node {
      Node *ch[2];
      int val, rank;
      int rep_cnt;
      int siz;

      Node(int val) : val(val), rep_cnt(1), siz(1) {
        ch[0] = ch[1] = nullptr;
        rank = rand();
      }

      void upd_siz() {
        siz = rep_cnt;
        if (ch[0] != nullptr) siz += ch[0]->siz;
        if (ch[1] != nullptr) siz += ch[1]->siz;
      }
    };

    class Treap {
     private:
      Node *root;

      constexpr static int NIL = -1;  // Dùng để biểu thị giá trị truy vấn không tồn tại

      enum rot_type { LF = 1, RT = 0 };

      int q_prev_tmp = 0, q_nex_tmp = 0;

      void _rotate(Node *&cur, rot_type dir) {  // 0 là xoay phải, 1 là xoay trái
        Node *tmp = cur->ch[dir];
        cur->ch[dir] = tmp->ch[!dir];
        tmp->ch[!dir] = cur;
        cur->upd_siz(), tmp->upd_siz();
        cur = tmp;
      }

      void _insert(Node *&cur, int val) {
        if (cur == nullptr) {
          cur = new Node(val);
          return;
        } else if (val == cur->val) {
          cur->rep_cnt++;
          cur->siz++;
        } else if (val < cur->val) {
          _insert(cur->ch[0], val);
          if (cur->ch[0]->rank < cur->rank) {
            _rotate(cur, RT);
          }
          cur->upd_siz();
        } else {
          _insert(cur->ch[1], val);
          if (cur->ch[1]->rank < cur->rank) {
            _rotate(cur, LF);
          }
          cur->upd_siz();
        }
      }

      void _del(Node *&cur, int val) {
        if (val > cur->val) {
          _del(cur->ch[1], val);
          cur->upd_siz();
        } else if (val < cur->val) {
          _del(cur->ch[0], val);
          cur->upd_siz();
        } else {
          if (cur->rep_cnt > 1) {
            cur->rep_cnt--, cur->siz--;
            return;
          }
          uint8_t state = 0;
          state |= (cur->ch[0] != nullptr);
          state |= ((cur->ch[1] != nullptr) << 1);
          // 00: không có con; 01: có trái không phải; 10: không trái có phải; 11: có cả hai
          Node *tmp = cur;
          switch (state) {
            case 0:
              delete cur;
              cur = nullptr;
              break;
            case 1:  // Có trái không phải
              cur = tmp->ch[0];
              delete tmp;
              break;
            case 2:  // Có phải không trái
              cur = tmp->ch[1];
              delete tmp;
              break;
            case 3:
              rot_type dir = cur->ch[0]->rank < cur->ch[1]->rank ? RT : LF;
              _rotate(cur, dir);
              _del(cur->ch[!dir], val);
              cur->upd_siz();
              break;
          }
        }
      }

      int _query_rank(Node *cur, int val) {
        int less_siz = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
        if (val == cur->val)
          return less_siz + 1;
        else if (val < cur->val) {
          if (cur->ch[0] != nullptr)
            return _query_rank(cur->ch[0], val);
          else
            return 1;
        } else {
          if (cur->ch[1] != nullptr)
            return less_siz + cur->rep_cnt + _query_rank(cur->ch[1], val);
          else
            return cur->siz + 1;
        }
      }

      int _query_val(Node *cur, int rank) {
        int less_siz = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
        if (rank <= less_siz)
          return _query_val(cur->ch[0], rank);
        else if (rank <= less_siz + cur->rep_cnt)
          return cur->val;
        else
          return _query_val(cur->ch[1], rank - less_siz - cur->rep_cnt);
      }

      int _query_prev(Node *cur, int val) {
        if (val <= cur->val) {
          if (cur->ch[0] != nullptr) return _query_prev(cur->ch[0], val);
        } else {
          q_prev_tmp = cur->val;
          if (cur->ch[1] != nullptr) _query_prev(cur->ch[1], val);
          return q_prev_tmp;
        }
        return NIL;
      }

      int _query_nex(Node *cur, int val) {
        if (val >= cur->val) {
          if (cur->ch[1] != nullptr) return _query_nex(cur->ch[1], val);
        } else {
          q_nex_tmp = cur->val;
          if (cur->ch[0] != nullptr) _query_nex(cur->ch[0], val);
          return q_nex_tmp;
        }
        return NIL;
      }

     public:
      void insert(int val) { _insert(root, val); }

      void del(int val) { _del(root, val); }

      int query_rank(int val) { return _query_rank(root, val); }

      int query_val(int rank) { return _query_val(root, rank); }

      int query_prev(int val) { return _query_prev(root, val); }

      int query_nex(int val) { return _query_nex(root, val); }
    };

    Treap tr;

    int main() {
      srand(0);
      int t;
      scanf("%d", &t);
      while (t--) {
        int mode;
        int num;
        scanf("%d%d", &mode, &num);
        switch (mode) {
          case 1:
            tr.insert(num);
            break;
          case 2:
            tr.del(num);
            break;
          case 3:
            printf("%d\n", tr.query_rank(num));
            break;
          case 4:
            printf("%d\n", tr.query_val(num));
            break;
          case 5:
            printf("%d\n", tr.query_prev(num));
            break;
          case 6:
            printf("%d\n", tr.query_nex(num));
            break;
        }
      }
    }
    ```

#### Cài đặt bằng mảng

Dưới đây là mã mẫu bzoj cho bài cây cân bằng thông thường, cài đặt bằng mảng.

??? note "Mã đầy đủ"
    ```cpp
    --8<-- "docs/ds/code/treap/treap_1.cpp"
    ```

### Treap không xoay

#### Cài đặt bằng con trỏ

??? note "Mã đầy đủ"
    Dưới đây là phiên bản đầy đủ của mã đã giải thích ở trên, là mã mẫu cho bài cây cân bằng thông thường.

    ```cpp

    // author: (ttzytt)[ttzytt.com]
    #include <cstdio>
    #include <cstdlib>
    #include <ctime>
    #include <tuple>
    using namespace std;

    struct Node {
      Node *ch[2];
      int val, prio;
      int cnt;
      int siz;

      Node(int _val) : val(_val), cnt(1), siz(1) {
        ch[0] = ch[1] = nullptr;
        prio = rand();
      }

      Node(Node *_node) {
        val = _node->val, prio = _node->prio, cnt = _node->cnt, siz = _node->siz;
      }

      void upd_siz() {
        siz = cnt;
        if (ch[0] != nullptr) siz += ch[0]->siz;
        if (ch[1] != nullptr) siz += ch[1]->siz;
      }
    };

    struct none_rot_treap {
    #define _3 second.second
    #define _2 second.first
      Node *root;

      pair<Node *, Node *> split(Node *cur, int key) {
        if (cur == nullptr) return {nullptr, nullptr};
        if (cur->val <= key) {
          auto temp = split(cur->ch[1], key);
          cur->ch[1] = temp.first;
          cur->upd_siz();
          return {cur, temp.second};
        } else {
          auto temp = split(cur->ch[0], key);
          cur->ch[0] = temp.second;
          cur->upd_siz();
          return {temp.first, cur};
        }
      }

      tuple<Node *, Node *, Node *> split_by_rk(Node *cur, int rk) {
        if (cur == nullptr) return {nullptr, nullptr, nullptr};
        int ls_siz = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
        if (rk <= ls_siz) {
          Node *l, *mid, *r;
          tie(l, mid, r) = split_by_rk(cur->ch[0], rk);
          cur->ch[0] = r;
          cur->upd_siz();
          return {l, mid, cur};
        } else if (rk <= ls_siz + cur->cnt) {
          Node *lt = cur->ch[0];
          Node *rt = cur->ch[1];
          cur->ch[0] = cur->ch[1] = nullptr;
          return {lt, cur, rt};
        } else {
          Node *l, *mid, *r;
          tie(l, mid, r) = split_by_rk(cur->ch[1], rk - ls_siz - cur->cnt);
          cur->ch[1] = l;
          cur->upd_siz();
          return {cur, mid, r};
        }
      }

      Node *merge(Node *u, Node *v) {
        if (u == nullptr && v == nullptr) return nullptr;
        if (u != nullptr && v == nullptr) return u;
        if (v != nullptr && u == nullptr) return v;
        if (u->prio < v->prio) {
          u->ch[1] = merge(u->ch[1], v);
          u->upd_siz();
          return u;
        } else {
          v->ch[0] = merge(u, v->ch[0]);
          v->upd_siz();
          return v;
        }
      }

      void insert(int val) {
        auto temp = split(root, val);
        auto l_tr = split(temp.first, val - 1);
        Node *new_node;
        if (l_tr.second == nullptr) {
          new_node = new Node(val);
        } else {
          l_tr.second->cnt++;
          l_tr.second->upd_siz();
        }
        Node *l_tr_combined =
            merge(l_tr.first, l_tr.second == nullptr ? new_node : l_tr.second);
        root = merge(l_tr_combined, temp.second);
      }

      void del(int val) {
        auto temp = split(root, val);
        auto l_tr = split(temp.first, val - 1);
        if (l_tr.second->cnt > 1) {
          l_tr.second->cnt--;
          l_tr.second->upd_siz();
          l_tr.first = merge(l_tr.first, l_tr.second);
        } else {
          if (temp.first == l_tr.second) {
            temp.first = nullptr;
          }
          delete l_tr.second;
          l_tr.second = nullptr;
        }
        root = merge(l_tr.first, temp.second);
      }

      int qrank_by_val(Node *cur, int val) {
        auto temp = split(cur, val - 1);
        int ret = (temp.first == nullptr ? 0 : temp.first->siz) + 1;
        root = merge(temp.first, temp.second);
        return ret;
      }

      int qval_by_rank(Node *cur, int rk) {
        Node *l, *mid, *r;
        tie(l, mid, r) = split_by_rk(cur, rk);
        int ret = mid->val;
        root = merge(merge(l, mid), r);
        return ret;
      }

      int qprev(int val) {
        auto temp = split(root, val - 1);
        int ret = qval_by_rank(temp.first, temp.first->siz);
        root = merge(temp.first, temp.second);
        return ret;
      }

      int qnex(int val) {
        auto temp = split(root, val);
        int ret = qval_by_rank(temp.second, 1);
        root = merge(temp.first, temp.second);
        return ret;
      }
    };

    none_rot_treap tr;

    int main() {
      srand(time(nullptr));
      int t;
      scanf("%d", &t);
      while (t--) {
        int mode;
        int num;
        scanf("%d%d", &mode, &num);
        switch (mode) {
          case 1:
            tr.insert(num);
            break;
          case 2:
            tr.del(num);
            break;
          case 3:
            printf("%d\n", tr.qrank_by_val(tr.root, num));
            break;
          case 4:
            printf("%d\n", tr.qval_by_rank(tr.root, num));
            break;
          case 5:
            printf("%d\n", tr.qprev(num));
            break;
          case 6:
            printf("%d\n", tr.qnex(num));
            break;
        }
      }
    }
    ```

### Thao tác đoạn của Treap không xoay

#### Cài đặt bằng con trỏ

??? note "Mã đầy đủ"
    Dưới đây là phiên bản đầy đủ của mã đã giải thích ở trên, là mã mẫu cho bài cây cân bằng nghệ thuật.

    ```cpp

    // author: (ttzytt)[ttzytt.com]
    #include <cstdlib>
    #include <ctime>
    #include <iostream>
    using namespace std;

    // Tham khảo: https://www.cnblogs.com/Equinox-Flower/p/10785292.html
    struct Node {
      Node* ch[2];
      int val, prio;
      int cnt;
      int siz;
      bool to_rev = false;  // Cần đảo ngược mọi nút trong cây con này

      Node(int _val) : val(_val), cnt(1), siz(1) {
        ch[0] = ch[1] = nullptr;
        prio = rand();
      }

      int upd_siz() {
        siz = cnt;
        if (ch[0] != nullptr) siz += ch[0]->siz;
        if (ch[1] != nullptr) siz += ch[1]->siz;
        return siz;
      }

      void pushdown() {
        swap(ch[0], ch[1]);
        if (ch[0] != nullptr) ch[0]->to_rev ^= 1;
        // Nếu nút con ban đầu cũng cần đảo ngược, hai lần đảo ngược sẽ triệt tiêu nhau; nếu không,
        // tag này cần tiếp tục được push xuống nút con
        if (ch[1] != nullptr) ch[1]->to_rev ^= 1;
        to_rev = false;
      }

      void check_tag() {
        if (to_rev) pushdown();
      }
    };

    struct Seg_treap {
      Node* root;
    #define siz(_) (_ == nullptr ? 0 : _->siz)

      pair<Node*, Node*> split(Node* cur, int sz) {
        // Chia theo kích thước cây
        if (cur == nullptr) return {nullptr, nullptr};
        cur->check_tag();
        if (sz <= siz(cur->ch[0])) {
          // Chỉ cây con bên trái đã đủ
          auto temp = split(cur->ch[0], sz);
          // Không nhất thiết cần toàn bộ cây con bên trái; temp.second là phần không cần
          cur->ch[0] = temp.second;
          cur->upd_siz();
          return {temp.first, cur};
        } else {
          // Cây bên trái cộng với một phần bên phải (tất nhiên gồm cả nút này)
          auto temp = split(cur->ch[1], sz - siz(cur->ch[0]) - 1);
          cur->ch[1] = temp.first;
          cur->upd_siz();
          return {cur, temp.second};
        }
      }

      Node* merge(Node* sm, Node* bg) {
        // small, big
        if (sm == nullptr && bg == nullptr) return nullptr;
        if (sm != nullptr && bg == nullptr) return sm;
        if (sm == nullptr && bg != nullptr) return bg;
        sm->check_tag(), bg->check_tag();
        if (sm->prio < bg->prio) {
          sm->ch[1] = merge(sm->ch[1], bg);
          sm->upd_siz();
          return sm;
        } else {
          bg->ch[0] = merge(sm, bg->ch[0]);
          bg->upd_siz();
          return bg;
        }
      }

      void insert(int val) {
        auto temp = split(root, val);
        auto l_tr = split(temp.first, val - 1);
        Node* new_node;
        if (l_tr.second == nullptr) new_node = new Node(val);
        Node* l_tr_combined =
            merge(l_tr.first, l_tr.second == nullptr ? new_node : l_tr.second);
        root = merge(l_tr_combined, temp.second);
      }

      void seg_rev(int l, int r) {
        // less và more là tương đối theo l
        auto less = split(root, l - 1);
        // Tất cả phần nhỏ hơn hoặc bằng l - 1 sẽ nằm bên trái của less
        auto more = split(less.second, r - l + 1);
        // Lấy r - l + 1 phần tử bắt đầu từ l
        more.first->to_rev = true;
        root = merge(less.first, merge(more.first, more.second));
      }

      void print(Node* cur) {
        if (cur == nullptr) return;
        cur->check_tag();
        print(cur->ch[0]);
        cout << cur->val << " ";
        print(cur->ch[1]);
      }
    };

    Seg_treap tr;

    int main() {
      srand(time(nullptr));
      int n, m;
      cin >> n >> m;
      for (int i = 1; i <= n; i++) tr.insert(i);
      while (m--) {
        int l, r;
        cin >> l >> r;
        tr.seg_rev(l, r);
      }
      tr.print(tr.root);
    }
    ```

## Bài tập ví dụ

[Cây cân bằng thông thường](https://loj.ac/problem/104)

[Cây cân bằng nghệ thuật (Splay)](https://loj.ac/problem/105)

[ZJOI2006 - Giá sách](https://www.luogu.com.cn/problem/P2596)

[NOI2005 - Duy trì dãy số](https://www.luogu.com.cn/problem/P2042)

[CF 702F T-Shirts](http://codeforces.com/problemset/problem/702/F)

## Tài liệu tham khảo và ghi chú

[^ref1]: Thiết kế của hình này tham khảo từ [hình minh họa trong mục Treap trên Wikipedia](https://en.wikipedia.org/wiki/Treap)

[^ref2]: <https://charleswu.site/archives/1051>

[^ref3]: <https://www.cnblogs.com/Equinox-Flower/p/10785292.html>

[^ref4]: <https://www.luogu.com.cn/blog/85514/fhq-treap-xue-xi-bi-ji>
