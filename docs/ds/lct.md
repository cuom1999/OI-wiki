## Giới thiệu

Link/Cut Tree là một cấu trúc dữ liệu dùng để giải **bài toán cây động**.

Link/Cut Tree còn được gọi là Link-Cut Tree, viết tắt là LCT. Tuy vậy bản thân nó không được gọi là "cây động"; cây động là tên của một lớp bài toán.

Splay Tree là nền tảng của LCT, nhưng Splay Tree dùng trong LCT khác Splay thông thường ở một vài chi tiết (có thêm một số mở rộng).

## Dẫn nhập bài toán

Duy trì một cây, hỗ trợ các thao tác sau:

-   Sửa trọng số trên đường đi giữa hai điểm.
-   Truy vấn tổng trọng số trên đường đi giữa hai điểm.
-   Sửa trọng số trong cây con của một điểm.
-   Truy vấn tổng trọng số trong cây con của một điểm.

Đây là một bài mẫu về phân rã cây theo chuỗi.

Nhưng nếu thêm một thao tác:

-   Cắt và nối một số cạnh, đồng thời bảo đảm cấu trúc vẫn là một cây.

Yêu cầu trả lời trực tuyến các truy vấn ở trên.

Khi đó bài toán trở thành bài toán cây động, có thể dùng LCT để giải.

## Bài toán cây động

Duy trì một **rừng**, hỗ trợ xóa một cạnh, thêm một cạnh, và bảo đảm sau khi thêm hoặc xóa cạnh thì cấu trúc vẫn là rừng. Ta cần duy trì một số thông tin trên rừng này.

Các thao tác thường gặp gồm kiểm tra liên thông giữa hai điểm, tổng trọng số trên đường đi giữa hai điểm, nối hai điểm, cắt một cạnh, sửa thông tin, v.v.

### Nhìn lại phân rã cây theo chuỗi từ góc nhìn LCT

-   Phân rã toàn bộ cây theo kích thước cây con và đánh số lại.
-   Sau khi đánh số lại, trên cây xuất hiện một số đoạn liên tiếp theo đơn vị chuỗi, và ta có thể dùng cây đoạn để thao tác trên các đoạn này.

### Chuyển sang bài toán cây động

Ta thấy phân rã cây vừa nêu dùng kích thước cây con làm điều kiện chia. Vậy có thể định nghĩa lại một kiểu phân rã để phù hợp hơn với bài toán cây động không?

Hãy xét xem bài toán cây động cần loại chuỗi nào.

Vì ta đang duy trì động một rừng, rõ ràng ta muốn chuỗi này là chuỗi do chính ta chỉ định để tiện dùng trong lời giải.

## Phân rã chuỗi thực

Với các cạnh nối một điểm tới tất cả con của nó, ta tự chọn một cạnh để đưa vào phân rã. Cạnh được chọn gọi là cạnh thực, các cạnh còn lại gọi là cạnh ảo. Với một cạnh thực, đứa con mà nó nối tới gọi là con thực. Một chuỗi gồm các cạnh thực cũng được gọi là chuỗi thực. Hãy nhớ lý do quan trọng nhất khiến ta chọn phân rã chuỗi thực: nó do ta chọn, linh hoạt và có thể thay đổi. Chính tính linh hoạt đó khiến ta dùng Splay Tree để duy trì các chuỗi thực này.

## LCT

Có thể hiểu đơn giản LCT là dùng một số Splay để duy trì phân rã cây theo chuỗi một cách động, nhằm thực hiện các thao tác đoạn trên cây động. Với mỗi chuỗi thực, ta xây một Splay để duy trì thông tin của toàn bộ đoạn chuỗi đó.

## Cây phụ trợ

Trước hết hãy xem một số tính chất của cây phụ trợ, rồi dùng hình vẽ để hiểu cấu trúc cụ thể của nó.

Trong bài này, có thể xem một số Splay hợp thành một cây phụ trợ; mỗi cây phụ trợ duy trì một cây, và nhiều cây phụ trợ hợp thành LCT, duy trì toàn bộ rừng.

1.  Cây phụ trợ gồm nhiều Splay. Mỗi Splay duy trì một đường đi trong cây gốc, và dãy đỉnh thu được khi duyệt trung thứ tự Splay này tương ứng từ trước ra sau với một đường đi "từ trên xuống dưới" trong cây gốc.
2.  Mỗi nút trong cây gốc tương ứng một-một với một nút Splay trong cây phụ trợ.
3.  Các Splay trong cây phụ trợ không độc lập với nhau. Cha của gốc mỗi Splay lẽ ra phải rỗng, nhưng trong LCT, cha của gốc mỗi Splay trỏ tới nút cha của **chuỗi này** trong cây gốc (tức cha của điểm trên cùng của chuỗi). Loại liên kết cha này khác liên kết cha trong Splay thông thường ở chỗ con nhận cha, nhưng cha không nhận con; nó tương ứng với một **cạnh ảo** trong cây gốc. Vì vậy, mỗi thành phần liên thông có đúng một điểm có cha rỗng.
4.  Nhờ các tính chất trên của cây phụ trợ, khi duy trì mọi thao tác ta không cần duy trì cây gốc. Cây phụ trợ luôn xác định được duy nhất một cây gốc, nên ta chỉ cần duy trì cây phụ trợ.

Giả sử ta có một cây gốc như hình dưới. (Cạnh tô đậm là cạnh thực, cạnh nét đứt là cạnh ảo.)

![tree](images/lct-atree-1.svg)

Theo định nghĩa vừa nêu, cấu trúc cây phụ trợ như hình sau.

![auxtree](images/lct-atree-2.svg)

### Quan hệ cấu trúc giữa cây gốc và cây phụ trợ

-   Chuỗi thực trong cây gốc: các nút nằm trong cùng một Splay của cây phụ trợ.
-   Chuỗi ảo trong cây gốc: trong cây phụ trợ, `Father` của Splay chứa nút con trỏ tới nút cha, nhưng hai con của nút cha đều không trỏ tới nút con.
-   Chú ý: gốc của cây gốc không nhất thiết là gốc của cây phụ trợ.
-   Con trỏ `Father` trong cây gốc không giống con trỏ `Father` trong cây phụ trợ.
-   Cây phụ trợ có thể đổi gốc tùy ý miễn vẫn thỏa các tính chất của cây phụ trợ và Splay.
-   Chuyển đổi giữa chuỗi ảo và chuỗi thực có thể thực hiện dễ dàng trên cây phụ trợ; đây chính là cách duy trì động phân rã cây theo chuỗi.

### Khai báo biến sẽ dùng sau đây

-   `ch[N][2]` con trái và con phải
-   `f[N]` con trỏ cha
-   `sum[N]` tổng trọng số trên đường đi
-   `val[N]` trọng số của điểm
-   `tag[N]` đánh dấu đảo
-   `laz[N]` đánh dấu trọng số
-   `siz[N]` kích thước cây con trên cây phụ trợ
-   Other\_Vars

### Khai báo hàm

#### Các hàm cấu trúc dữ liệu thông thường

1.  `PushUp(x)`
2.  `PushDown(x)`

#### Các hàm của Splay Tree

Sau đây là các hàm dùng trong Splay Tree; xem chi tiết tại [Splay Tree](./splay.md).

1.  `Get(x)` lấy xem $x$ là con nào của cha nó.
2.  `Splay(x)` phối hợp với thao tác `Rotate` để xoay $x$ lên **gốc của Splay hiện tại**.
3.  `Rotate(x)` xoay $x$ lên trên một tầng.

#### Thao tác mới

1.  `Access(x)` đưa tất cả điểm từ gốc tới $x$ vào cùng một chuỗi thực, khiến đường từ gốc tới $x$ trở thành một đường thực và nằm trong cùng một Splay. **Chỉ thao tác này là bắt buộc phải cài đặt; các thao tác khác tùy bài mà cài đặt.**
2.  `IsRoot(x)` kiểm tra $x$ có phải gốc của cây chứa nó hay không.
3.  `Update(x)` sau thao tác `Access`, đệ quy từ trên xuống dưới để `PushDown` và cập nhật thông tin.
4.  `MakeRoot(x)` biến điểm $x$ thành gốc của cây chứa nó.
5.  `Link(x, y)` nối một cạnh giữa hai điểm $x, y$.
6.  `Cut(x, y)` xóa cạnh giữa hai điểm $x, y$.
7.  `Find(x)` tìm chỉ số nút gốc của cây chứa $x$.
8.  `Fix(x, v)` sửa trọng số điểm của $x$ thành $v$.
9.  `Split(x, y)` trích xuất đường đi giữa $x, y$ để tiện thao tác đoạn.

### Định nghĩa macro

-   `#define ls ch[p][0]`
-   `#define rs ch[p][1]`

## Giải thích hàm

### `PushUp()`

```cpp
void PushUp(int p) {
  // maintain other variables
  siz[p] = siz[ls] + siz[rs] + 1;
}
```

### `PushDown()`

```cpp
void PushDown(int p) {
  if (tag[p] != std_tag) {
    // pushdown the tag
    tag[p] = std_tag;
  }
}
```

### `Splay() && Rotate()`

Ở đây `Splay()` và `Rotate()` có vài điểm khác với cách cài đặt Splay Tree thông thường.

```cpp
#define Get(x) (ch[f[x]][1] == x)

void Rotate(int x) {
  int y = f[x], z = f[y], k = Get(x);
  if (!isRoot(y)) ch[z][ch[z][1] == y] = x;
  // Câu trên phải đặt ở phía trước; Splay thông thường không cần vậy
  // vì isRoot (sẽ nói ở phần sau)
  ch[y][k] = ch[x][!k], f[ch[x][!k]] = y;
  ch[x][!k] = y, f[y] = x, f[x] = z;
  PushUp(y), PushUp(x);
}

void Splay(int x) {
  Update(
      x);  // Trước khi Splay, phải PushDown mọi điểm trên đường mà phép xoay sẽ đi qua
  for (int fa; fa = f[x], !isRoot(x); Rotate(x)) {
    if (!isRoot(fa)) Rotate(Get(fa) == Get(x) ? fa : x);
  }
}
```

Các hàm trên có thể xem thêm tại [Splay Tree](./splay.md).

Sau đây là các hàm riêng của LCT.

### `isRoot()`

```cpp
// Như đã nói ở trên, LCT có tính chất: nếu một con không phải con thực
// thì cha của nó không tìm thấy nó.
// Vì vậy, nếu một điểm không phải con trái cũng không phải con phải của cha nó,
// nó chính là gốc của Splay hiện tại.
#define isRoot(x) (ch[f[x]][0] != x && ch[f[x]][1] != x)
```

### `Access()`

```cpp
// Access là thao tác cốt lõi của LCT. Hãy tưởng tượng ta muốn giải một đường đi,
// và đường đi đó đúng bằng một Splay hiện tại, khi đó chỉ cần gọi trực tiếp
// thông tin của nó. Trước hết xem mã, rồi kết hợp với hình để hiểu quá trình.
int Access(int x) {
  int p;
  for (p = 0; x; p = x, x = f[x]) {
    Splay(x), ch[x][1] = p, PushUp(x);
  }
  return p;
}
```

-   Ta có một cây như sau, cạnh liền là cạnh thực, cạnh nét đứt là cạnh ảo.

    ![initial tree](images/lct-access-1.svg)

-   Cây phụ trợ của nó có thể có dạng sau (cách vẽ khác nhau có thể dẫn tới cấu trúc LCT khác nhau).

    ![initial auxtree](images/lct-access-2.svg)

-   Bây giờ ta cần `Access(N)`, biến mọi cạnh trên đường từ $A$ tới $N$ thành cạnh thực và kéo chúng thành một Splay.

    ![access tree](images/lct-access-3.svg)

-   Cách thực hiện là cập nhật Splay từng bước từ dưới lên trên.

-   Trước hết ta xoay $N$ lên gốc của Splay hiện tại.

-   Để bảo đảm tính chất của AuxTree (cây phụ trợ), cạnh thực ban đầu từ $N$ tới $O$ phải đổi thành cạnh ảo.

-   Do tính chất con nhận cha nhưng cha không nhận con, ta có thể đơn phương đổi con của $N$ thành `NULL`.

-   Vì vậy AuxTree ban đầu chuyển từ hình dưới sang hình kế tiếp.

    ![step 1 auxtree](images/lct-access-4.svg)

-   Bước tiếp theo, ta cũng xoay `Father` $I$ mà $N$ trỏ tới lên gốc của Splay chứa $I$.

-   Cạnh thực ban đầu $I$--$K$ cần bị bỏ. Lúc này ta cho con phải của $I$ trỏ tới $N$, và thu được một Splay từ $I$ tới $L$.

    ![step 2 auxtree](images/lct-access-5.svg)

-   Tiếp theo, theo các bước vừa rồi, vì `Father` của $I$ trỏ tới $H$, ta xoay $H$ lên gốc của Splay Tree chứa nó, rồi đặt `rs` của $H$ thành $I$.

-   Cây sau đó có dạng như sau.

    ![step 3 auxtree](images/lct-access-6.svg)

-   Tương tự, ta `Splay(A)` và cho con phải của $A$ trỏ tới $H$.

-   Khi đó ta thu được AuxTree sau, và thấy rằng toàn bộ đường đi $A$--$N$ đã nằm trong cùng một Splay.

    ![step final auxtree](images/lct-access-7.svg)

```cpp
// Nhìn lại mã
int Access(int x) {
  int p;
  for (p = 0; x; p = x, x = f[x]) {
    Splay(x), ch[x][1] = p, PushUp(x);
  }
  return p;
}
```

Ta thấy `Access()` thực ra rất đơn giản, chỉ gồm bốn bước:

1.  Xoay nút hiện tại lên gốc.
2.  Đổi con thành nút trước đó.
3.  Cập nhật thông tin của điểm hiện tại.
4.  Đổi điểm hiện tại thành cha của nó và tiếp tục thao tác.

Phiên bản `Access` ở đây còn có giá trị trả về. Giá trị này tương đương chỉ số nút cha của cạnh ảo trong lần chuyển đổi chuỗi ảo/thực cuối cùng. Nó có hai ý nghĩa:

-   Khi thực hiện hai thao tác `Access` liên tiếp, giá trị trả về của thao tác `Access` thứ hai bằng LCA của hai nút đó.
-   Biểu thị gốc của Splay chứa chuỗi từ $x$ tới gốc. Nút này chắc chắn đã được xoay lên gốc và cha của nó chắc chắn rỗng.

### `Update()`

```cpp
// Chỉ cần pushDown từng tầng từ trên xuống dưới
void Update(int p) {
  if (!isRoot(p)) Update(f[p]);
  pushDown(p);
}
```

### `makeRoot()`

-   Tầm quan trọng của `Make_Root()` không hề kém `Access()`. Khi cần duy trì thông tin đường đi, chắc chắn sẽ có trường hợp độ sâu trên đường đi không tăng nghiêm ngặt; theo tính chất của AuxTree, kiểu đường đi này không thể xuất hiện trong một Splay.
-   Lúc này ta cần dùng `Make_Root()`.
-   Tác dụng của `Make_Root()` là biến điểm được chỉ định thành gốc của cây gốc. Hãy xét cách cài đặt thao tác này.
-   Giả sử giá trị trả về của `Access(x)` là $y$, khi đó đường đi từ $x$ tới gốc hiện tại vừa đúng tạo thành một Splay, và gốc của Splay này là $y$.
-   Hãy biểu diễn cây bằng đồ thị có hướng, gán cho mỗi cạnh một hướng từ con tới cha. Dễ thấy đổi gốc tương đương đảo hướng mọi cạnh trên đường đi từ $x$ tới gốc (hãy suy nghĩ kỹ).
-   Vì vậy chỉ cần đảo đường đi từ $x$ tới gốc hiện tại.
-   Do $y$ là gốc của Splay biểu diễn đường đi từ $x$ tới gốc hiện tại, ta chỉ cần đảo đoạn trên Splay có gốc $y$.

```cpp
void makeRoot(int p) {
  p = Access(p);
  swap(ch[p][0], ch[p][1]);
  tag[p] ^= 1;
}
```

### `Link()`

-   `Link` hai điểm thật ra rất đơn giản: trước hết `Make_Root(x)`, sau đó cho cha của $x$ trỏ tới $y$. Rõ ràng thao tác này không được xảy ra trong cùng một cây, nên hãy nhớ kiểm tra trước.

```cpp
void Link(int x, int p) {
  makeRoot(x);
  splay(x);
  f[x] = p;
}
```

### `Split()`

-   Ý nghĩa của thao tác `Split` rất đơn giản: lấy ra một Splay duy trì đường đi từ $x$ tới $y$.
-   Trước hết `MakeRoot(x)`, sau đó `Access(y)`. Nếu muốn $y$ làm gốc, tiếp tục `Splay(y)`.
-   Ngoài ra, ba thao tác trong `Split` có thể trực tiếp lấy đường đi cần thiết ra thành cây con của $y$, từ đó thực hiện các thao tác khác.

### `Cut()`

-   `Cut` có hai trường hợp: bảo đảm hợp lệ và không nhất thiết bảo đảm hợp lệ.
-   Nếu bảo đảm hợp lệ, trực tiếp `Split(x, y)`. Lúc này $y$ là gốc, $x$ chắc chắn là con của nó, chỉ cần ngắt liên kết hai chiều. Ví dụ:

```cpp
void Cut(int x, int p) { makeRoot(x), Access(p), Splay(p), ls = f[x] = 0; }
```

Nếu không bảo đảm hợp lệ, ta cần kiểm tra cạnh đó có tồn tại hay không. Có thể dùng `map` để lưu, nhưng cũng có một cách tận dụng tính chất:

Muốn xóa cạnh, phải thỏa ba điều kiện sau:

1.  $x,y$ liên thông.
2.  Trên đường đi giữa $x,y$ không có chuỗi nào khác.
3.  $x$ không có con phải.

Tóm lại, ba câu trên chỉ có một ý: giữa $x,y$ có cạnh.

Phần cài đặt cụ thể xin để lại như một bài tập suy nghĩ. Kiểm tra liên thông cần dùng `Find` ở phía sau; hai điểm còn lại chỉ cần phân tích cấu trúc một chút là biết cách kiểm tra.

### `Find()`

-   `Find()` tìm gốc của **cây gốc** chứa $x$; đừng nhầm gốc cây gốc với gốc cây phụ trợ. Sau `Access(p)`, tiếp tục `Splay(p)`. Khi đó gốc là nút có độ sâu nhỏ nhất trong cây, chỉ cần đi liên tục sang con trái và `PushDown` trên đường đi.
-   Đi cho tới khi không còn `ls`, rất đơn giản.
-   Chú ý, sau mỗi lần truy vấn cần `Splay` nút kết quả tìm được lên trên để bảo đảm độ phức tạp.

```cpp
int Find(int p) {
  Access(p);
  Splay(p);
  pushDown(p);
  while (ls) p = ls, pushDown(p);
  Splay(p);
  return p;
}
```

### Lưu ý

-   Trước khi thao tác, nhất định phải nghĩ xem có cần `PushUp` hoặc `PushDown` hay không. Vì LCT rất linh hoạt, thiếu một lần `Pushdown` hoặc `Pushup` cũng có thể khiến sửa đổi rơi vào điểm không nên sửa.
-   `Rotate` của LCT hơi khác Splay, `if (z)` nhất định phải đặt phía trước.
-   Thao tác `Splay` của LCT chỉ xoay lên gốc; không có thao tác xoay tới làm con của một nút nào đó, vì không cần.

## Độ phức tạp thời gian

Phần lớn thao tác trong LCT đều dựa trên `Access`, còn các thao tác khác có độ phức tạp hằng số, vì vậy ta chỉ cần phân tích độ phức tạp của thao tác `Access`.

Trong đó, độ phức tạp của `Access` chủ yếu đến từ nhiều thao tác splay và việc truy cập các cạnh ảo trên đường đi. Sau đây phân tích riêng hai phần này.

1.  splay

    -   Định nghĩa $w(x) = \log size(x)$, trong đó $size(x)$ biểu thị tổng số cạnh ảo và cạnh thực trong cây có gốc $x$.

    -   Định nghĩa hàm thế năng $\Phi = \sum_{x \in T} w(x)$, trong đó $T$ là tập tất cả các nút.

    Từ phân tích [độ phức tạp thời gian của Splay](./splay.md#%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6), dễ biết độ phức tạp khấu hao của thao tác splay là $O(\log n)$.

2.  Truy cập cạnh ảo

    Tham khảo [phân rã chuỗi nặng](../graph/hld.md#%E9%87%8D%E9%93%BE%E5%89%96%E5%88%86), định nghĩa hai loại cạnh ảo:

    -   **Cạnh ảo nặng**: cạnh ảo từ nút $v$ tới cha của nó, với $size(v) > \frac{1}{2} size(parent(v))$.

    -   **Cạnh ảo nhẹ**: cạnh ảo từ nút $v$ tới cha của nó, với $size(v) \leq \frac{1}{2} size(parent(v))$.

    Với việc xử lý cạnh ảo, có thể dùng phân tích thế năng. Định nghĩa hàm thế năng $\Phi$ là số lượng tất cả cạnh ảo nặng, và định nghĩa chi phí khấu hao $c_i = t_i + \Delta \Phi_i$, trong đó $t_i$ là chi phí thao tác thực tế, $\Delta \Phi_i$ là biến thiên thế năng.

    -   Sau khi đi qua cạnh ảo nặng, cạnh ảo nặng sẽ được chuyển thành cạnh thực. Thao tác này làm giảm thế năng đi $1$ vì nó tối ưu cấu trúc cây bằng cách tăng cường một liên kết quan trọng. Do chi phí thao tác thực tế là $O(1)$, nó bù trừ phần tăng thế năng, nên không làm tăng chi phí khấu hao; toàn bộ chi phí khấu hao tập trung vào việc xử lý cạnh ảo nhẹ.

    -   Mỗi thao tác `Access` duyệt nhiều nhất $O(\log n)$ cạnh ảo nhẹ, nên tốn tối đa $O(\log n)$ chi phí thao tác thực tế, đồng thời chuyển đổi ra $O(\log n)$ cạnh ảo nặng, tức thế năng tăng với chi phí $O(\log n)$.

    Do đó, độ phức tạp khấu hao cuối cùng của việc truy cập cạnh ảo là tổng của chi phí thao tác thực tế và biến thiên thế năng, tức $O(\log n)$.

Tóm lại, độ phức tạp của thao tác `Access` trong LCT là tổng độ phức tạp của splay và truy cập cạnh ảo, nên độ phức tạp khấu hao cuối cùng là $O(\log n)$. Nghĩa là với một LCT có n nút, thực hiện m thao tác `Access` có độ phức tạp thời gian $O(n \log n + m \log n)$; do đó các thao tác dựa trên `Access` như `Cut`, `Link`, `Findroot` cũng có độ phức tạp khấu hao $O(\log n)$.

## Bài tập

-   [BZOJ 3282 - Tree](https://hydro.ac/p/bzoj-P3282)
-   [HNOI2010 - Cừu bông bật nảy](https://www.luogu.com.cn/problem/P3203)

## Duy trì thông tin trên chuỗi cây

Thông qua thao tác `Split(x,y)`, LCT có thể trích xuất đường đi từ điểm $x$ tới điểm $y$ trên cây vào Splay có gốc $y$. Việc sửa và thống kê thông tin chuỗi cây được chuyển thành thao tác trên cây cân bằng, giúp LCT có ưu thế khi duy trì thông tin chuỗi cây. Ngoài ra, nhị phân trên chuỗi cây bằng LCT ít hơn một hệ số $O(\log n)$ so với phân rã cây theo chuỗi.

???+ note "Ví dụ [Đội tuyển quốc gia - Tree II](https://www.luogu.com.cn/problem/P1501)"
    Cho một cây có $n$ nút, trọng số ban đầu của mỗi điểm là $1$. Có $q$ thao tác, mỗi thao tác thuộc một trong bốn loại sau:
    
    1.  `- u1 v1 u2 v2`: xóa cạnh giữa hai điểm $u_1,v_1$ trên cây, rồi nối hai điểm $u_2,v_2$; bảo đảm thao tác hợp lệ và sau khi nối cạnh vẫn là một cây.
    2.  `+ u v c`: tăng trọng số của mọi điểm trên đường đi giữa hai điểm $u,v$ trên cây thêm $c$.
    3.  `* u v c`: nhân trọng số của mọi điểm trên đường đi giữa hai điểm $u,v$ trên cây với $c$.
    4.  `/ u v`: xuất tổng trọng số các điểm trên đường đi giữa hai điểm $u,v$ trên cây sau khi lấy modulo $51061$.
    
        $1\le n,q\le 10^5,0\le c\le 10^4$
    
        Thao tác `-` có thể trực tiếp `Cut(u1,v1),Link(u2,v2)`.

Khi sửa đường đi giữa hai điểm $u,v$ trên cây, trước hết `Split(u,v)`.

Bài này yêu cầu thực hiện cộng cây con, nhân cây con và tính tổng cây con trên cây phụ trợ, nên ngoài đánh dấu đảo cây con mà LCT thông thường cần duy trì, ta còn phải duy trì đánh dấu cộng và đánh dấu nhân của cây con. Cách xử lý đánh dấu giống như trên Splay.

Khi gắn và đẩy xuống đánh dấu cộng, lượng thay đổi của tổng trọng số cây con liên quan tới số nút trong cây con, nên ta còn phải duy trì kích thước cây con `siz`.

Khi đẩy đánh dấu xuống, cần chú ý thứ tự: đẩy đánh dấu nhân trước, rồi đến đánh dấu cộng. Hai loại đánh dấu đảo cây con và cộng/nhân cây con không xung đột.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    using namespace std;
    constexpr long long MAXN = 100010;
    constexpr long long mod = 51061;
    long long n, q, u, v, c;
    char op;
    
    struct Splay {
      long long ch[MAXN][2], fa[MAXN], siz[MAXN], val[MAXN], sum[MAXN], rev[MAXN],
          add[MAXN], mul[MAXN];
    
      void clear(long long x) {
        ch[x][0] = ch[x][1] = fa[x] = siz[x] = val[x] = sum[x] = rev[x] = add[x] =
            0;
        mul[x] = 1;
      }
    
      long long getch(long long x) { return (ch[fa[x]][1] == x); }
    
      long long isroot(long long x) {
        clear(0);
        return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
      }
    
      void maintain(long long x) {
        clear(0);
        siz[x] = (siz[ch[x][0]] + 1 + siz[ch[x][1]]) % mod;
        sum[x] = (sum[ch[x][0]] + val[x] + sum[ch[x][1]]) % mod;
      }
    
      void pushdown(long long x) {
        clear(0);
        if (mul[x] != 1) {
          if (ch[x][0])
            mul[ch[x][0]] = (mul[x] * mul[ch[x][0]]) % mod,
            val[ch[x][0]] = (val[ch[x][0]] * mul[x]) % mod,
            sum[ch[x][0]] = (sum[ch[x][0]] * mul[x]) % mod,
            add[ch[x][0]] = (add[ch[x][0]] * mul[x]) % mod;
          if (ch[x][1])
            mul[ch[x][1]] = (mul[x] * mul[ch[x][1]]) % mod,
            val[ch[x][1]] = (val[ch[x][1]] * mul[x]) % mod,
            sum[ch[x][1]] = (sum[ch[x][1]] * mul[x]) % mod,
            add[ch[x][1]] = (add[ch[x][1]] * mul[x]) % mod;
          mul[x] = 1;
        }
        if (add[x]) {
          if (ch[x][0])
            add[ch[x][0]] = (add[ch[x][0]] + add[x]) % mod,
            val[ch[x][0]] = (val[ch[x][0]] + add[x]) % mod,
            sum[ch[x][0]] = (sum[ch[x][0]] + add[x] * siz[ch[x][0]] % mod) % mod;
          if (ch[x][1])
            add[ch[x][1]] = (add[ch[x][1]] + add[x]) % mod,
            val[ch[x][1]] = (val[ch[x][1]] + add[x]) % mod,
            sum[ch[x][1]] = (sum[ch[x][1]] + add[x] * siz[ch[x][1]] % mod) % mod;
          add[x] = 0;
        }
        if (rev[x]) {
          if (ch[x][0]) rev[ch[x][0]] ^= 1, swap(ch[ch[x][0]][0], ch[ch[x][0]][1]);
          if (ch[x][1]) rev[ch[x][1]] ^= 1, swap(ch[ch[x][1]][0], ch[ch[x][1]][1]);
          rev[x] = 0;
        }
      }
    
      void update(long long x) {
        if (!isroot(x)) update(fa[x]);
        pushdown(x);
      }
    
      void print(long long x) {
        if (!x) return;
        pushdown(x);
        print(ch[x][0]);
        printf("%lld ", x);
        print(ch[x][1]);
      }
    
      void rotate(long long x) {
        long long y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
        fa[x] = z;
        if (!isroot(y)) ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
        maintain(y);
        maintain(x);
        maintain(z);
      }
    
      void splay(long long x) {
        update(x);
        for (long long f = fa[x]; f = fa[x], !isroot(x); rotate(x))
          if (!isroot(f)) rotate(getch(x) == getch(f) ? f : x);
      }
    
      void access(long long x) {
        for (long long f = 0; x; f = x, x = fa[x])
          splay(x), ch[x][1] = f, maintain(x);
      }
    
      void makeroot(long long x) {
        access(x);
        splay(x);
        swap(ch[x][0], ch[x][1]);
        rev[x] ^= 1;
      }
    
      long long find(long long x) {
        access(x);
        splay(x);
        while (ch[x][0]) x = ch[x][0];
        splay(x);
        return x;
      }
    } st;
    
    main() {
      scanf("%lld%lld", &n, &q);
      for (long long i = 1; i <= n; i++) st.val[i] = 1, st.maintain(i);
      for (long long i = 1; i < n; i++) {
        scanf("%lld%lld", &u, &v);
        if (st.find(u) != st.find(v)) st.makeroot(u), st.fa[u] = v;
      }
      while (q--) {
        scanf(" %c%lld%lld", &op, &u, &v);
        if (op == '+') {
          scanf("%lld", &c);
          st.makeroot(u), st.access(v), st.splay(v);
          st.val[v] = (st.val[v] + c) % mod;
          st.sum[v] = (st.sum[v] + st.siz[v] * c % mod) % mod;
          st.add[v] = (st.add[v] + c) % mod;
        }
        if (op == '-') {
          st.makeroot(u);
          st.access(v);
          st.splay(v);
          if (st.ch[v][0] == u && !st.ch[u][1]) st.ch[v][0] = st.fa[u] = 0;
          scanf("%lld%lld", &u, &v);
          if (st.find(u) != st.find(v)) st.makeroot(u), st.fa[u] = v;
        }
        if (op == '*') {
          scanf("%lld", &c);
          st.makeroot(u), st.access(v), st.splay(v);
          st.val[v] = st.val[v] * c % mod;
          st.sum[v] = st.sum[v] * c % mod;
          st.mul[v] = st.mul[v] * c % mod;
        }
        if (op == '/')
          st.makeroot(u), st.access(v), st.splay(v), printf("%lld\n", st.sum[v]);
      }
      return 0;
    }
    ```

### Bài tập

-   [luogu P3690 - Mẫu Link Cut Tree (cây động)](https://www.luogu.com.cn/problem/P3690)
-   [SDOI2011 - Tô màu](https://www.luogu.com.cn/problem/P2486)
-   [SHOI2014 - Cây thần kinh tam thoa](https://loj.ac/problem/2187)

## Duy trì tính liên thông

### Kiểm tra liên thông

Nhờ hàm `Find()` của LCT, ta có thể kiểm tra hai điểm trong rừng động có liên thông hay không. Nếu `Find(x)==Find(y)`, điều đó cho biết hai điểm $x,y$ nằm trong cùng một cây và liên thông với nhau.

???+ note "Ví dụ [SDOI2008 - Khảo sát hang động](https://www.luogu.com.cn/problem/P2147)"
    Ban đầu có $n$ điểm độc lập và $m$ thao tác. Mỗi thao tác thuộc một trong các loại sau:
    
    1.  `Connect u v`: nối một cạnh giữa hai điểm $u,v$.
    2.  `Destroy u v`: xóa cạnh giữa hai điểm $u,v$, bảo đảm trước đó tồn tại cạnh này.
    3.  `Query u v`: hỏi hai điểm $u,v$ có liên thông hay không.
    
    Bảo đảm ở mọi thời điểm, hình dạng của đồ thị đều là một rừng.
    
    $n\le 10^4, m\le 2\times 10^5$

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    using namespace std;
    constexpr int MAXN = 10010;
    
    struct Splay {
      int ch[MAXN][2], fa[MAXN], tag[MAXN];
    
      void clear(int x) { ch[x][0] = ch[x][1] = fa[x] = tag[x] = 0; }
    
      int getch(int x) { return ch[fa[x]][1] == x; }
    
      int isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    
      void pushdown(int x) {
        if (tag[x]) {
          if (ch[x][0]) swap(ch[ch[x][0]][0], ch[ch[x][0]][1]), tag[ch[x][0]] ^= 1;
          if (ch[x][1]) swap(ch[ch[x][1]][0], ch[ch[x][1]][1]), tag[ch[x][1]] ^= 1;
          tag[x] = 0;
        }
      }
    
      void update(int x) {
        if (!isroot(x)) update(fa[x]);
        pushdown(x);
      }
    
      void rotate(int x) {
        int y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
        fa[x] = z;
        if (!isroot(y)) ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
      }
    
      void splay(int x) {
        update(x);
        for (int f = fa[x]; f = fa[x], !isroot(x); rotate(x))
          if (!isroot(f)) rotate(getch(x) == getch(f) ? f : x);
      }
    
      void access(int x) {
        for (int f = 0; x; f = x, x = fa[x]) splay(x), ch[x][1] = f;
      }
    
      void makeroot(int x) {
        access(x);
        splay(x);
        swap(ch[x][0], ch[x][1]);
        tag[x] ^= 1;
      }
    
      int find(int x) {
        access(x);
        splay(x);
        while (ch[x][0]) x = ch[x][0];
        splay(x);
        return x;
      }
    } st;
    
    int n, q, x, y;
    char op[MAXN];
    
    int main() {
      scanf("%d%d", &n, &q);
      while (q--) {
        scanf("%s%d%d", op, &x, &y);
        if (op[0] == 'Q') {
          if (st.find(x) == st.find(y))
            printf("Yes\n");
          else
            printf("No\n");
        }
        if (op[0] == 'C')
          if (st.find(x) != st.find(y)) st.makeroot(x), st.fa[x] = y;
        if (op[0] == 'D') {
          st.makeroot(x);
          st.access(y);
          st.splay(y);
          if (st.ch[y][0] == x && !st.ch[x][1]) st.ch[y][0] = st.fa[x] = 0;
        }
      }
      return 0;
    }
    ```

### Duy trì thành phần song liên thông cạnh

Nếu cần co mỗi thành phần song liên thông cạnh thành một điểm, thì mỗi khi thêm một cạnh, nếu hai điểm trên cây được nối bởi cạnh đó vốn đã liên thông, mọi điểm trên đường đi này sẽ được co thành một điểm.

???+ note "Ví dụ [AHOI2005 - Quy hoạch tuyến bay](https://www.luogu.com.cn/problem/P2542)"
    Cho $n$ điểm, ban đầu có $m$ cạnh vô hướng, và $q$ thao tác. Mỗi thao tác thuộc một trong các loại sau:
    
    1.  `0 u v`: xóa cạnh nối giữa $u,v$, bảo đảm lúc này tồn tại cạnh đó.
    2.  `1 u v`: truy vấn số cạnh mà mọi đường đi khả dĩ giữa hai điểm $u,v$ lúc này đều phải đi qua.
    
    Bảo đảm đồ thị liên thông ở mọi thời điểm.
    
    $1<n<3\times 10^4,1<m<10^5,0\le q\le 4\times 10^4$

Có thể thấy, số cạnh mà mọi đường đi khả dĩ giữa hai điểm $u,v$ đều phải đi qua bằng số nút trên đường đi giữa điểm chứa $u$ và điểm chứa $v$ sau khi co mọi thành phần song liên thông cạnh thành điểm, trừ $1$.

Vì thao tác xóa cạnh trong bài không dễ xử lý, ta xét xử lý offline theo chiều ngược, biến xóa cạnh thành thêm cạnh.

Khi thêm một cạnh, nếu hai điểm ban đầu không liên thông, ta nối hai điểm trên LCT; ngược lại, trích xuất đường đi giữa hai điểm này trên LCT trước khi thêm cạnh, duyệt cây con tương ứng trên cây phụ trợ, tương đương duyệt đường đi đó, rồi hợp nhất các điểm này và dùng DSU để duy trì thông tin hợp nhất.

Dùng phần tử đại diện của DSU sau khi hợp nhất để thay thế đường đi ban đầu trên cây. Chú ý rằng trong mọi thao tác sau đó, cần tìm phần tử đại diện trong DSU của điểm thao tác rồi mới thao tác.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <map>
    using namespace std;
    constexpr int MAXN = 200010;
    int f[MAXN];
    
    int findp(int x) { return f[x] ? f[x] = findp(f[x]) : x; }
    
    void merge(int x, int y) {
      x = findp(x);
      y = findp(y);
      if (x != y) f[x] = y;
    }
    
    struct Splay {
      int ch[MAXN][2], fa[MAXN], tag[MAXN], siz[MAXN];
    
      void clear(int x) { ch[x][0] = ch[x][1] = fa[x] = tag[x] = siz[x] = 0; }
    
      int getch(int x) { return ch[findp(fa[x])][1] == x; }
    
      int isroot(int x) {
        return ch[findp(fa[x])][0] != x && ch[findp(fa[x])][1] != x;
      }
    
      void maintain(int x) {
        clear(0);
        if (x) siz[x] = siz[ch[x][0]] + 1 + siz[ch[x][1]];
      }
    
      void pushdown(int x) {
        if (tag[x]) {
          if (ch[x][0]) tag[ch[x][0]] ^= 1, swap(ch[ch[x][0]][0], ch[ch[x][0]][1]);
          if (ch[x][1]) tag[ch[x][1]] ^= 1, swap(ch[ch[x][1]][0], ch[ch[x][1]][1]);
          tag[x] = 0;
        }
      }
    
      void print(int x) {
        if (!x) return;
        pushdown(x);
        print(ch[x][0]);
        printf("%d ", x);
        print(ch[x][1]);
      }
    
      void update(int x) {
        if (!isroot(x)) update(findp(fa[x]));
        pushdown(x);
      }
    
      void rotate(int x) {
        x = findp(x);
        int y = findp(fa[x]), z = findp(fa[y]), chx = getch(x), chy = getch(y);
        fa[x] = z;
        if (!isroot(y)) ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
        maintain(y);
        maintain(x);
        if (z) maintain(z);
      }
    
      void splay(int x) {
        x = findp(x);
        update(x);
        for (int f = findp(fa[x]); f = findp(fa[x]), !isroot(x); rotate(x))
          if (!isroot(f)) rotate(getch(x) == getch(f) ? f : x);
      }
    
      void access(int x) {
        for (int f = 0; x; f = x, x = findp(fa[x]))
          splay(x), ch[x][1] = f, maintain(x);
      }
    
      void makeroot(int x) {
        x = findp(x);
        access(x);
        splay(x);
        tag[x] ^= 1;
        swap(ch[x][0], ch[x][1]);
      }
    
      int find(int x) {
        x = findp(x);
        access(x);
        splay(x);
        while (ch[x][0]) x = ch[x][0];
        splay(x);
        return x;
      }
    
      void dfs(int x) {
        pushdown(x);
        if (ch[x][0]) dfs(ch[x][0]), merge(ch[x][0], x);
        if (ch[x][1]) dfs(ch[x][1]), merge(ch[x][1], x);
      }
    } st;
    
    int n, m, q, x, y, cur, ans[MAXN];
    
    struct oper {
      int op, a, b;
    } s[MAXN];
    
    map<pair<int, int>, int> mp;
    
    int main() {
      scanf("%d%d", &n, &m);
      for (int i = 1; i <= n; i++) st.maintain(i);
      for (int i = 1; i <= m; i++)
        scanf("%d%d", &x, &y), mp[{x, y}] = mp[{y, x}] = 1;
      while (scanf("%d", &s[++q].op)) {
        if (s[q].op == -1) {
          q--;
          break;
        }
        scanf("%d%d", &s[q].a, &s[q].b);
        if (!s[q].op) mp[{s[q].a, s[q].b}] = mp[{s[q].b, s[q].a}] = 0;
      }
      reverse(s + 1, s + q + 1);
      for (map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end(); it++)
        if (it->second) {
          mp[{it->first.second, it->first.first}] = 0;
          x = findp(it->first.first);
          y = findp(it->first.second);
          if (st.find(x) != st.find(y))
            st.makeroot(x), st.fa[x] = y;
          else {
            if (x == y) continue;
            st.makeroot(x);
            st.access(y);
            st.splay(y);
            st.dfs(y);
            int t = findp(y);
            st.fa[t] = findp(st.fa[y]);
            st.ch[t][0] = st.ch[t][1] = 0;
            st.maintain(t);
          }
        }
      for (int i = 1; i <= q; i++) {
        if (s[i].op == 0) {
          x = findp(s[i].a);
          y = findp(s[i].b);
          st.makeroot(x);
          st.access(y);
          st.splay(y);
          st.dfs(y);
          int t = findp(y);
          st.fa[t] = st.fa[y];
          st.ch[t][0] = st.ch[t][1] = 0;
          st.maintain(t);
        }
        if (s[i].op == 1) {
          x = findp(s[i].a);
          y = findp(s[i].b);
          st.makeroot(x);
          st.access(y);
          st.splay(y);
          ans[++cur] = st.siz[y] - 1;
        }
      }
      for (int i = cur; i >= 1; i--) printf("%d\n", ans[i]);
      return 0;
    }
    ```

### Bài tập

-   [Luogu P3950 - Xung đột bộ lạc](https://www.luogu.com.cn/problem/P3950)
-   [BZOJ 4998 - Liên minh hành tinh](https://hydro.ac/p/bzoj-P4998)
-   [BZOJ 2959 - Chạy đường dài](https://hydro.ac/p/bzoj-P2959)

## Duy trì trọng số cạnh

LCT không thể trực tiếp xử lý trọng số cạnh. Khi đó cần tạo một điểm tương ứng cho mỗi cạnh để tiện truy vấn thông tin cạnh trên chuỗi. Dùng kỹ thuật này có thể duy trì cây khung một cách động.

???+ note "Ví dụ [luogu P4234 - Cây khung có hiệu nhỏ nhất](https://www.luogu.com.cn/problem/P4234)"
    Cho một đồ thị vô hướng có trọng số gồm $n$ điểm và $m$ cạnh. Hãy tìm cây khung sao cho hiệu giữa trọng số cạnh lớn nhất và trọng số cạnh nhỏ nhất là nhỏ nhất, rồi xuất hiệu đó.
    
    Dữ liệu bảo đảm tồn tại ít nhất một cây khung.
    
    $1\le n\le 5\times 10^4,1\le m\le 2\times 10^5,1\le w_i\le 10^4$

Sắp xếp các cạnh theo trọng số tăng dần, rồi liệt kê cạnh được chọn ở phía phải nhất. Để đạt lời giải tối ưu, cần làm cho trọng số của cạnh nhỏ nhất lớn nhất có thể.

Mỗi lần thêm cạnh theo thứ tự, nếu hai điểm sắp nối đã liên thông, thì xóa cạnh có trọng số nhỏ nhất trên đường đi giữa hai điểm đó. Nếu toàn bộ đồ thị đã liên thông thành một cây, dùng trọng số hiện tại trừ trọng số nhỏ nhất để cập nhật đáp án. Trọng số nhỏ nhất có thể cập nhật bằng phương pháp hai con trỏ.

Trên LCT không có quan hệ cha-con cố định, nên không thể ghi trọng số cạnh vào trọng số điểm.

Để ghi thông tin cạnh trên chuỗi cây, có thể dùng kỹ thuật **tách cạnh**. Với mỗi cạnh, tạo một điểm tương ứng, rồi nối một cạnh từ điểm cạnh này tới mỗi đầu mút của nó; khi đó thao tác nối cạnh và xóa cạnh ban đầu đều trở thành hai thao tác.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <set>
    using namespace std;
    constexpr int MAXN = 5000010;
    
    struct Splay {
      int ch[MAXN][2], fa[MAXN], tag[MAXN], val[MAXN], minn[MAXN];
    
      void clear(int x) {
        ch[x][0] = ch[x][1] = fa[x] = tag[x] = val[x] = minn[x] = 0;
      }
    
      int getch(int x) { return ch[fa[x]][1] == x; }
    
      int isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    
      void maintain(int x) {
        if (!x) return;
        minn[x] = x;
        if (ch[x][0]) {
          if (val[minn[ch[x][0]]] < val[minn[x]]) minn[x] = minn[ch[x][0]];
        }
        if (ch[x][1]) {
          if (val[minn[ch[x][1]]] < val[minn[x]]) minn[x] = minn[ch[x][1]];
        }
      }
    
      void pushdown(int x) {
        if (tag[x]) {
          if (ch[x][0]) tag[ch[x][0]] ^= 1, swap(ch[ch[x][0]][0], ch[ch[x][0]][1]);
          if (ch[x][1]) tag[ch[x][1]] ^= 1, swap(ch[ch[x][1]][0], ch[ch[x][1]][1]);
          tag[x] = 0;
        }
      }
    
      void update(int x) {
        if (!isroot(x)) update(fa[x]);
        pushdown(x);
      }
    
      void print(int x) {
        if (!x) return;
        pushdown(x);
        print(ch[x][0]);
        printf("%d ", x);
        print(ch[x][1]);
      }
    
      void rotate(int x) {
        int y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
        fa[x] = z;
        if (!isroot(y)) ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
        maintain(y);
        maintain(x);
        if (z) maintain(z);
      }
    
      void splay(int x) {
        update(x);
        for (int f = fa[x]; f = fa[x], !isroot(x); rotate(x))
          if (!isroot(f)) rotate(getch(x) == getch(f) ? f : x);
      }
    
      void access(int x) {
        for (int f = 0; x; f = x, x = fa[x]) splay(x), ch[x][1] = f, maintain(x);
      }
    
      void makeroot(int x) {
        access(x);
        splay(x);
        tag[x] ^= 1;
        swap(ch[x][0], ch[x][1]);
      }
    
      int find(int x) {
        access(x);
        splay(x);
        while (ch[x][0]) x = ch[x][0];
        splay(x);
        return x;
      }
    
      void link(int x, int y) {
        makeroot(x);
        fa[x] = y;
      }
    
      void cut(int x, int y) {
        makeroot(x);
        access(y);
        splay(y);
        ch[y][0] = fa[x] = 0;
        maintain(y);
      }
    } st;
    
    constexpr int inf = 2e9 + 1;
    int n, m, ans, nww, x, y;
    
    struct Edge {
      int u, v, w;
    
      bool operator<(Edge x) const { return w < x.w; };
    } s[MAXN];
    
    multiset<int> mp;
    
    int main() {
      scanf("%d%d", &n, &m);
      for (int i = 1; i <= n; i++) st.val[i] = inf, st.maintain(i);
      for (int i = 1; i <= m; i++) scanf("%d%d%d", &s[i].u, &s[i].v, &s[i].w);
      sort(s + 1, s + m + 1);
      for (int i = 1; i <= m; i++) st.val[n + i] = s[i].w, st.maintain(n + i);
      for (int i = 1; i <= m; i++) {
        x = s[i].u;
        y = s[i].v;
        if (x == y) continue;
        if (st.find(x) != st.find(y)) {
          nww++;
          st.link(x, n + i);
          st.link(n + i, y);
          mp.insert(s[i].w);
          if (nww == n - 1) ans = s[i].w - (*(mp.begin()++));
        } else {
          st.makeroot(x);
          st.access(y);
          st.splay(y);
          int t = st.minn[y] - n;
          st.cut(s[t].u, t + n);
          st.cut(t + n, s[t].v);
          mp.erase(mp.find(s[t].w));
          st.link(x, n + i);
          st.link(n + i, y);
          mp.insert(s[i].w);
          if (nww == n - 1) ans = min(ans, s[i].w - (*(mp.begin()++)));
        }
      }
      printf("%d\n", ans);
      return 0;
    }
    ```

### Bài tập

-   [WC2006 - Cục trưởng cục đường ống nước](https://www.luogu.com.cn/problem/P4172)
-   [BJWC2010 - Cây khung nhỏ thứ hai nghiêm ngặt](https://www.luogu.com.cn/problem/P4180)
-   [NOI2014 - Rừng ma thuật](https://uoj.ac/problem/3)

## Duy trì thông tin cây con

LCT không giỏi duy trì thông tin cây con. Nếu thống kê thông tin của mọi cây con ảo của một nút, ta có thể thu được thông tin của toàn bộ cây.

???+ note "Ví dụ [BJOI2014 - Đại dung hợp](https://loj.ac/problem/2230)"
    Cho $n$ nút và $q$ thao tác, mỗi thao tác có dạng sau:
    
    1.  `A x y` nối một cạnh giữa nút $x$ và nút $y$.
    2.  `Q x y` cho một cạnh đã tồn tại $(x,y)$, hãy tính có bao nhiêu đường đi đơn chứa cạnh $(x,y)$.
    
    Bảo đảm ở mọi thời điểm, hình dạng của đồ thị đều là một rừng.
    
    $1\le n,q,x,y\le 10^5$

Với truy vấn `Q`, xét một cách diễn đạt khác: đáp án bằng tích của số nút ở phía $x$ và số nút ở phía $y$ của cạnh $(x,y)$, tức số nút của hai cây lần lượt chứa $x$ và $y$ sau khi cắt cạnh $(x,y)$. Để loại bỏ ảnh hưởng của việc cắt cạnh, sau khi truy vấn ta nối lại cạnh $(x,y)$.

Các thao tác trong bài vừa có nối cạnh vừa có xóa cạnh, lại bảo đảm ở mọi thời điểm đều là một rừng, nên tự nhiên nghĩ tới dùng LCT để duy trì. Nhưng trong bài này LCT duy trì kích thước cây con, không giống việc duy trì thông tin một chuỗi như ta thường hình dung; hơn nữa cấu tạo của LCT là **con nhận cha nhưng cha không nhận con**, nên không tiện thống kê trực tiếp cây con. Làm thế nào?

Cách làm là thống kê đóng góp của các cây con do mọi con ảo của một nút $x$ biểu diễn (tức các nút có cha là $x$, nhưng không nằm trong con trái hoặc con phải của $x$ trong Splay).

Định nghĩa $siz2[x]$ là số nút trong các cây con do mọi con ảo của nút $x$ biểu diễn, và $siz[x]$ là số nút trong cây con của nút $x$.

Khác với cách trước đây khi duy trì số nút cây con trong Splay, khi tính số nút trong cây con của nút $x$, ta còn phải cộng thêm $siz2[x]$, tức:

```cpp
void maintain(int x) {
  clear(0);
  if (x) siz[x] = siz[ch[x][0]] + 1 + siz[ch[x][1]] + siz2[x];
}
```

Ngoài ra, khi ta **thay đổi hình dạng của Splay** (tức thay đổi con trỏ con trái/phải của một nút trên Splay), cần kịp thời sửa giá trị $siz2[x]$.

Trong các thao tác `Rotate(),Splay()`, ta chỉ thay đổi vị trí tương đối của các nút trong Splay, không thay đổi trạng thái ảo/thực của bất kỳ cạnh nào, nên không sửa $siz2[x]$.

Trong thao tác `access`, sau mỗi lần splay xong, con phải của nút vừa được splay sẽ thay đổi. Nói cách khác, trạng thái ảo/thực của cạnh nối nút đó với con phải cũ và cạnh nối nút đó với con phải mới đã thay đổi. Ta cần cộng đóng góp của cây con vừa được nối bằng cạnh ảo mới, và trừ đóng góp của cây con vừa được nối bằng cạnh thực mới. Mã như sau:

```cpp
void access(int x) {
  for (int f = 0; x; f = x, x = fa[x])
    splay(x), siz2[x] += siz[ch[x][1]] - siz[f], ch[x][1] = f, maintain(x);
}
```

Trong các thao tác `MakeRoot(),Find()`, ta chỉ gọi các hàm trước đó hoặc đi trên Splay, nên không cần sửa gì thêm.

Khi nối hai điểm, ta sửa cha của một nút. Ta cần cộng đóng góp kích thước cây con của nút con mới vào giá trị $siz2$ của nút cha.

```cpp
st.makeroot(x);
st.makeroot(y);
st.fa[x] = y;
st.siz2[y] += st.siz[x];
```

Khi cắt một cạnh, ta chỉ xóa một cạnh thực trên Splay; thao tác `Maintain` sẽ duy trì các thông tin này, nên không cần sửa gì thêm.

Trên đây là các chi tiết sửa mã. Cuối cùng, tóm tắt yêu cầu và phương pháp để LCT duy trì thông tin cây con:

1.  Thông tin được duy trì phải có **tính trừ được**, như số nút cây con hoặc tổng trọng số cây con; không thể trực tiếp duy trì giá trị lớn nhất/nhỏ nhất của cây con, vì khi một cạnh ảo biến thành cạnh thực cần loại bỏ đóng góp của cạnh ảo ban đầu.
2.  Tạo một giá trị phụ để lưu đóng góp của cây con ảo; khi thống kê thì cộng nó vào đáp án của nút hiện tại, và duy trì kịp thời khi trạng thái ảo/thực của cạnh thay đổi.
3.  Các phần còn lại giống LCT thông thường; khi thống kê thông tin cây con, nhất định phải đặt nút đó làm gốc.
4.  Nếu thông tin được duy trì không có tính trừ được, chẳng hạn duy trì cực trị đoạn, có thể mở một cây cân bằng cho mỗi nút để duy trì cực trị trong các cây con ảo của nút đó.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    using namespace std;
    constexpr int MAXN = 100010;
    using ll = long long;
    
    struct Splay {
      int ch[MAXN][2], fa[MAXN], siz[MAXN], siz2[MAXN], tag[MAXN];
    
      void clear(int x) {
        ch[x][0] = ch[x][1] = fa[x] = siz[x] = siz2[x] = tag[x] = 0;
      }
    
      int getch(int x) { return ch[fa[x]][1] == x; }
    
      int isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    
      void maintain(int x) {
        clear(0);
        if (x) siz[x] = siz[ch[x][0]] + 1 + siz[ch[x][1]] + siz2[x];
      }
    
      void pushdown(int x) {
        if (tag[x]) {
          if (ch[x][0]) swap(ch[ch[x][0]][0], ch[ch[x][0]][1]), tag[ch[x][0]] ^= 1;
          if (ch[x][1]) swap(ch[ch[x][1]][0], ch[ch[x][1]][1]), tag[ch[x][1]] ^= 1;
          tag[x] = 0;
        }
      }
    
      void update(int x) {
        if (!isroot(x)) update(fa[x]);
        pushdown(x);
      }
    
      void rotate(int x) {
        int y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
        fa[x] = z;
        if (!isroot(y)) ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
        maintain(y);
        maintain(x);
        maintain(z);
      }
    
      void splay(int x) {
        update(x);
        for (int f = fa[x]; f = fa[x], !isroot(x); rotate(x))
          if (!isroot(f)) rotate(getch(x) == getch(f) ? f : x);
      }
    
      void access(int x) {
        for (int f = 0; x; f = x, x = fa[x])
          splay(x), siz2[x] += siz[ch[x][1]] - siz[f], ch[x][1] = f, maintain(x);
      }
    
      void makeroot(int x) {
        access(x);
        splay(x);
        swap(ch[x][0], ch[x][1]);
        tag[x] ^= 1;
      }
    
      int find(int x) {
        access(x);
        splay(x);
        while (ch[x][0]) x = ch[x][0];
        splay(x);
        return x;
      }
    } st;
    
    int n, q, x, y;
    char op;
    
    int main() {
      scanf("%d%d", &n, &q);
      while (q--) {
        scanf(" %c%d%d", &op, &x, &y);
        if (op == 'A') {
          st.makeroot(x);
          st.makeroot(y);
          st.fa[x] = y;
          st.siz2[y] += st.siz[x];
        }
        if (op == 'Q') {
          st.makeroot(x);
          st.access(y);
          st.splay(y);
          st.ch[y][0] = st.fa[x] = 0;
          st.maintain(x);
          st.makeroot(x);
          st.makeroot(y);
          printf("%lld\n", (ll)(st.siz[x] * st.siz[y]));
          st.makeroot(x);
          st.makeroot(y);
          st.fa[x] = y;
          st.siz2[y] += st.siz[x];
        }
      }
      return 0;
    }
    ```

### Bài tập

-   [luogu P4299 - Thủ đô](https://www.luogu.com.cn/problem/P4299)
-   [SPOJ QTREE5 - Query on a tree V](https://www.spoj.com/problems/QTREE5)
