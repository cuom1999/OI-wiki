## Giới thiệu

Cây Chtholly Tree, còn gọi là Old Driver Tree ODT (Old Driver Tree). Nó bắt nguồn từ [CF896C](https://codeforces.com/problemset/problem/896/C).

Tên gọi này chỉ một kỹ thuật "dùng cây cân bằng (`std::set`, `std::map`, v.v.) hoặc danh sách liên kết (`std::list`, danh sách liên kết tự cài đặt, v.v.) để duy trì các đoạn màu theo phân tích khấu hao", chứ không phải một cấu trúc dữ liệu cụ thể. Ý tưởng cốt lõi là gộp một đoạn liên tiếp có cùng giá trị thành một nút để xử lý. So với các cấu trúc dữ liệu truyền thống như cây phân đoạn, với những bài toán có thao tác phủ giá trị trên đoạn, Chtholly Tree có thể duy trì giá trị của từng đoạn bị phủ thuận tiện hơn.

## Cài đặt (`std::set`)

### Kiểu nút

```cpp
struct Node_t {
  int l, r;
  mutable int v;

  Node_t(const int &il, const int &ir, const int &iv) : l(il), r(ir), v(iv) {}

  bool operator<(const Node_t &o) const { return l < o.l; }
};
```

Trong đó, `int v` là dữ liệu bổ sung do bài toán tự quy định.

???+ note "Từ khóa `mutable` có ý nghĩa gì?"
    `mutable` có nghĩa là "có thể thay đổi", cho phép sửa giá trị của `v` trong các thao tác về sau. Trong C++, mutable được thiết kế để vượt qua ràng buộc của const. Biến được đánh dấu mutable (mutable chỉ dùng để đánh dấu thành viên dữ liệu phi tĩnh trong lớp) sẽ luôn ở trạng thái có thể thay đổi, kể cả trong một hàm const.

    Điều này có nghĩa là có thể sửa trực tiếp giá trị `v` của phần tử đã chèn vào `set`, mà không cần lấy phần tử đó ra rồi chèn lại vào `set`.

### Lưu trữ nút

Cần duy trì tất cả các nút sao cho đầu trái của các khoảng mà chúng đại diện tăng đơn điệu và đôi một không giao nhau. Tốt hơn nữa là hợp của tất cả các khoảng tạo thành một miền liên tục cực đại. Ví dụ với `std::set`, dùng một `set<Node_t> odt;` để duy trì tất cả các nút.

Khi khởi tạo, chèn vào Chtholly Tree một khoảng rất dài (ví dụ nếu đề bài yêu cầu duy trì thông tin tại các vị trí từ $1$ đến $n$, chèn khoảng $[1,n+1]$).

### Thao tác `split`

Thao tác `split` là cốt lõi của Chtholly Tree. Nó nhận một vị trí $x$, tách khoảng ban đầu chứa điểm $x$ (giả sử là $[l, r]$) thành hai khoảng $[l, x)$ và $[x, r]$, đồng thời trả về iterator trỏ đến khoảng sau.

Mã tham khảo như sau:

```cpp
auto split(int x) {
  auto it = odt.lower_bound(Node_t(x, 0, 0));
  if (it != odt.end() && it->l == x) return it;
  --it;
  int l = it->l, r = it->r, v = it->v;
  odt.erase(it);
  odt.insert(Node_t(l, x - 1, v));
  return odt.insert(Node_t(x, r, v)).first;
}
```

Trên các trình biên dịch không hỗ trợ suy diễn kiểu trả về bằng `auto`, có thể đổi kiểu trả về của hàm thành `set<Node_t>::iterator`.

### Thao tác `assign`

Một thao tác quan trọng khác là `assign`. Nó dùng để gán giá trị cho một đoạn. Giả sử cần gán khoảng $[l,r]$ thành $v$.

Trước hết, cắt riêng khoảng $[l, r]$ ra. Gọi lần lượt `split(r + 1), split(l)`, và ký hiệu các iterator mà hai lời gọi này trả về là $itr, itl$. Khi đó phạm vi iterator $[itl, itr)$ sẽ trỏ đến tất cả các khoảng trong Chtholly Tree nằm trong $[l,r]$.

Sau đó, xóa thông tin cũ. `std::set` có hàm thành viên `erase`, với chữ kí như `iterator erase( const_iterator first, const_iterator last );`, có thể loại bỏ các phần tử trong phạm vi `[first; last)`. Vì vậy gọi `odt.erase(itl, itr);` để xóa thông tin cũ.

Cuối cùng, chèn giá trị mới của khoảng $[l,r]$. Chỉ cần gọi `odt.insert(Node_t(l, r, v))`.

Mã tham khảo như sau:

```cpp
void assign(int l, int r, int v) {
  auto itr = split(r + 1), itl = split(l);
  odt.erase(itl, itr);
  odt.insert(Node_t(l, r, v));
}
```

???+ note "Vì sao cần gọi `split(r + 1)` trước rồi mới gọi `split(l)`?"
    1.  Phương thức `std::set::erase` sẽ làm mất hiệu lực các tham chiếu và iterator trỏ đến phần tử bị xóa. Các tham chiếu và iterator khác không bị ảnh hưởng.
    2.  Phương thức `std::set::insert` không làm mất hiệu lực bất kì iterator hay tham chiếu nào.
    3.  Thao tác `split` sẽ tách khoảng. Sau khi gọi `split(r + 1)`, $r + 1$ sẽ trở thành đầu trái của khoảng bên phải trong hai khoảng mới. Lúc này khi `split` khoảng bên trái, quá trình sẽ không truy cập đến khoảng có đầu trái là $r + 1$, nên cũng không tách và xóa khoảng có đầu trái là $r + 1$ khiến iterator mất hiệu lực. Ngược lại, nếu gọi `split(l)` trước rồi mới gọi `split(r + 1)`, có thể xóa khoảng có đầu trái là $l$, làm iterator mất hiệu lực.

### Thao tác `perform`

Trích một đoạn trên Chtholly Tree ra rồi thực hiện thao tác. Nó tương tự thao tác `assign`, chỉ khác là thay việc xóa khoảng bằng việc duyệt khoảng.

Mã tham khảo như sau:

```cpp
void perform(int l, int r) {
  auto itr = split(r + 1), itl = split(l);
  for (; itl != itr; ++itl) {
    // Thực hiện thao tác tại đây
  }
}
```

Lưu ý không nên lạm dụng cách trích khoảng như vậy, vì có thể làm sai độ phức tạp thời gian. Xem mục "Phân tích độ phức tạp" bên dưới.

## Cài đặt (`std::map`)

So với cách cài đặt bằng `std::set`, thao tác `split` trong cách cài đặt bằng `std::map` viết đơn giản hơn. Ngoài điểm đó, các thao tác còn lại không khác gì nhiều so với `std::set`.

### Lưu trữ nút

Vì các khoảng được Chtholly Tree lưu trữ là liên tục, không nhất thiết phải ghi lại đầu phải. Có thể dùng một `map<int, int> mp;` để lưu tất cả các khoảng: key duy trì đầu trái, value duy trì giá trị từ đầu trái tương ứng đến trước đầu trái kế tiếp.

Khi khởi tạo, nếu đề bài yêu cầu duy trì thông tin tại các vị trí từ $1$ đến $n$, gọi `mp[1] = -1, mp[n + 1] = -1` để biểu thị rằng $[1,n+1)$, tức $[1, n]$, đều được gán thành giá trị đặc biệt $-1$. Khoảng $[n+1, +\infty)$ được dùng làm lính canh, và cũng có thể khởi tạo nó.

### Thao tác `split`

Mã tham khảo (bản thứ nhất):

```cpp
void split(int x) {
  auto it = prev(mp.upper_bound(x));  // Tìm khoảng có đầu trái nhỏ hơn hoặc bằng x.
  mp[x] = it->second;  // Tạo khoảng mới và sao chép giá trị lưu trong khoảng trước cho khoảng này.
}
```

Mã tham khảo (bản thứ hai):

```cpp
auto split(int pos) {
  auto it = prev(mp.upper_bound(pos));  // Tìm khoảng có đầu trái nhỏ hơn hoặc bằng x.
  return mp.insert(it, make_pair(pos, it->second));
  // Tạo khoảng mới và sao chép giá trị lưu trong khoảng trước cho khoảng này.
}
```

Đoạn này dùng overload `iterator insert( const_iterator pos, const value_type& value );` của `std::map::insert`. Nó chèn `value` vào vị trí gần nhất có thể ngay trước `pos`. Nếu việc chèn thực sự xảy ra ngay trước `pos`, độ phức tạp là hằng số theo phân tích khấu hao; nếu không, độ phức tạp là logarit theo kích thước container.

### Thao tác `assign`

Với thao tác assign, cần xóa tất cả đầu trái của các khoảng nằm trong $[l,r-1]$, rồi tạo khoảng mới.

```cpp
void assign(int l, int r, int v) {  // Lưu ý: r là đầu phải của khoảng + 1
  split(l);
  split(r);
  auto it = mp.find(l);
  while (it->first != r) {
    it = mp.erase(it);
  }
  mp[l] = v;
}
```

### Thao tác `perform`

```cpp
void perform(int l, int r) {  // Lưu ý: r là đầu phải của khoảng + 1
  split(l);
  split(r);
  auto it = mp.find(l);
  while (it->first != r) {
    // Thực hiện thao tác tại đây
    it = next(it);
  }
}
```

## Cài đặt (danh sách liên kết)

Hiện nay cách cài đặt chủ lưu dựa trên `set` để duy trì các nút, nhưng vì số khoảng trung bình cần duy trì rất nhỏ, ưu thế của `set` không rõ rệt. So với nó, danh sách liên kết (hoặc mảng) có thể duy trì các thao tác tách và gộp gọn hơn.

### Lưu trữ nút

```cpp
using i64 = int64_t;

struct Block {
  Block *next;  // Nút tiếp theo trong danh sách liên kết
  int l, r;     // Phạm vi khoảng
  i64 val;      // Giá trị trên khoảng

  Block(Block *next, int l, int r, i64 val)
      : next(next), l(l), r(r), val(val) {}

  bool operator<(const Block &b) const { return val < b.val; }
} *root;
```

### Thao tác `split`

```cpp
// Trả về khoảng có đầu trái là mid+1
Block *split(int mid) {
  for (Block *b = root; b; b = b->next) {  // Duyệt danh sách liên kết
    if (b->l == mid + 1) {                 // Đầu trái là mid+1
      return b;
    }
    // Tìm khoảng [l, r] có thể chứa cả mid và mid+1, rồi tách nó thành
    // [l, mid] và [mid+1, r]
    if (b->l <= mid && mid + 1 <= b->r) {
      b->next = new Block(b->next, mid + 1, b->r, b->val);
      b->r = mid;
      return b->next;
    }
  }
  return nullptr;  // Không tìm thấy thì trả về rỗng
}
```

Khi thao tác trên một khoảng, vì không thể chỉ duy trì một phần của khoảng, nên trước khi thực hiện các thao tác bên dưới đều cần tách trước khoảng, rồi mới hoàn thành thao tác tương ứng.

```cpp
Block *lb, *rb;

// Tách trước để bảo đảm các thao tác sau nằm bên trong [l, r]
void prepare(int l, int r) {
  lb = split(l - 1);
  rb = split(r);
}
```

### Thao tác `assign`

```cpp
void assign(int l, int r, i64 val) {
  prepare(l, r);
  lb->r = r;  // Sửa khoảng [lb.l, lb.r] thành [lb.l, r]
  lb->val = val;
  lb->next = rb;  // Nối [lb.l, r] với khoảng kề bên phải của nó
}

// Ghi chú: đoạn này không giải phóng bộ nhớ của các nút bị xóa; có thể tự thêm nếu cần
```

### Thao tác `perform`

```cpp
void perform(int l, int r) {
  prepare(l, r);
  for (Block *b = lb; b != rb; b = b->next) {
    // Thực hiện thao tác tại đây
  }
}
```

## Phân tích độ phức tạp

### Gọi assign ngay sau khi perform trên cùng một khoảng

Quan sát trong trường hợp này, hai thao tác `split` tăng nhiều nhất hai khoảng; một thao tác `assign` sẽ xóa tất cả các khoảng trong phạm vi và thêm một khoảng, đồng thời duyệt qua các khoảng bị xóa. Vì vậy số khoảng được duyệt tỉ lệ tuyến tính với số khoảng bị xóa, còn mỗi thao tác chỉ tăng thêm $O(1)$ khoảng. Do đó số khoảng được thao tác là tuyến tính theo số thao tác (kể cả khởi tạo), và độ phức tạp thời gian là $O(m\log n)$ theo phân tích khấu hao, trong đó $m$ là số thao tác, $n$ là số khoảng lớn nhất trong Chtholly Tree (có thể xem $n\leq m$).

### Không gọi assign sau perform

Nếu cho phép tạo dữ liệu đặc biệt, cách này có thể bị hack: chỉ cần làm cho Chtholly Tree có đủ nhiều khoảng khác nhau và lặp lại việc duyệt, độ phức tạp của Chtholly Tree có thể đạt tới, thậm chí vượt qua, bậc hai.

Nếu muốn có độ phức tạp đúng, dữ liệu phải ngẫu nhiên. Xem thêm [chứng minh về độ phức tạp của Chtholly Tree trên Codeforces](http://codeforces.com/blog/entry/56135?#comment-398940). Chứng minh nghiêm ngặt hơn có trong [phân tích độ phức tạp của Chtholly Tree](https://zhuanlan.zhihu.com/p/102786071). Kết luận của chứng minh là: độ phức tạp của Chtholly Tree cài đặt bằng `std::set` là $O(n \log \log n)$, còn cài đặt bằng danh sách liên kết là $O(n \log n)$.

## Bài tập

-   ["Luogu 1840" Tô màu trục](https://www.luogu.com.cn/problem/P1840)
-   ~~["SCOI2010" Thao tác dãy](https://www.luogu.com.cn/problem/P2572)~~ (nguồn của bài này đã được thêm dữ liệu Hack)
-   ["SHOI2015" Máy trị liệu não động](https://loj.ac/problem/2037)
-   ["Luogu 4979" Mỏ: sập đổ](https://www.luogu.com.cn/problem/P4979)
-   ["Luogu 8146" risrqnis](https://www.luogu.com.cn/problem/P8146)

## Đọc thêm

[Mở rộng tư tưởng ánh xạ của ODT - chuyên mục Luogu (luogu.com.cn)](https://www.luogu.com.cn/article/0mys9qkh)

## Tài liệu tham khảo và chú thích

-   [Bài toán - 896C - Codeforces](https://codeforces.com/problemset/problem/896/C) (nguồn gốc của Chtholly Tree)
-   [Lời giải CF896C Willem, Chtholly và Seniorious - chuyên mục Luogu (luogu.com.cn)](https://www.luogu.com.cn/article/gyxbe23s) (tham khảo cách cài đặt bằng `std::set`)
-   [Cài đặt Chtholly Tree bằng map - Zhihu (zhihu.com)](https://zhuanlan.zhihu.com/p/469794466) (tham khảo cách cài đặt bằng `std::map`)
-   [Lời giải CF896C Willem, Chtholly và Seniorious - chuyên mục Luogu (luogu.com.cn)](https://www.luogu.com.cn/article/umiw1fwp) (tham khảo cách cài đặt bằng danh sách liên kết)
-   [Lời giải chính thức Codeforces Round #449 - Codeforces](https://codeforces.com/blog/entry/56135?#comment-398940) (chứng minh về độ phức tạp của Chtholly Tree)
-   [Phân tích độ phức tạp của Chtholly Tree - Zhihu (zhihu.com)](https://zhuanlan.zhihu.com/p/102786071) (phân tích độ phức tạp của Chtholly Tree)
