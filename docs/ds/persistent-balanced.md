## Treap không xoay bền vững

### Kiến thức cần có

**Cây cân bằng bền vững thường dùng trong OI** nhìn chung chính là **Treap không xoay bền vững**, nên trước tiên nên học
[**Treap không xoay**](./treap.md).

### Ý tưởng/cách làm

Với Treap không xoay, có thể bền vững hóa bằng cách sao chép các nút đi qua trên đường trong quá trình thực hiện **hợp
nhất** (Merge) và **tách** (Split). Thường sao chép trong thao tác **tách** để bảo đảm không ảnh hưởng đến phiên bản
trước.

Với Treap xoay, ngoài việc sao chép các nút đi qua trên đường, còn cần sao chép các nút bị ảnh hưởng bởi phép xoay. Nếu
nút đó đã được sao chép trong thao tác hiện tại thì không cần sao chép lại. Một phép xoay thường chỉ ảnh hưởng đến hai
nút, nên điều này không làm tăng độ phức tạp thời gian.

Phương pháp trên thường được gọi là sao chép đường đi (path copying).

"Mọi thao tác được hỗ trợ đều có thể hoàn thành thông qua **Merge Split Newnode Build**". Trong đó, **Build** (xây dựng)
chỉ dùng để xây dựng ban đầu nên không cần quan tâm nhiều, còn **Newnode** (tạo nút mới) chính là công cụ để bền vững hóa.

Quan sát **Merge** (hợp nhất) và **Split** (tách) sẽ thấy chúng đều là các thao tác từ trên xuống dưới.

Do đó, hoàn toàn có thể **tham khảo thao tác bền vững hóa cây phân đoạn** để bền vững hóa Treap.

### Thao tác bền vững hóa

**Bền vững hóa** là thao tác trên **cấu trúc dữ liệu**, tức giữ lại thông tin lịch sử để về sau có thể gọi lại các phiên
bản trước đó.

Với **cây phân đoạn bền vững**, mỗi lần tạo phiên bản lịch sử mới chính là sao chép **đường đi bị sửa đổi**.

Với Treap bền vững (phiên bản hiện thường dùng trong OI tại Trung Quốc), cách làm như sau:

Sau khi sao chép một nút $X_{a}$ (phiên bản thứ $a$ của nút $X$) thành phiên bản mới $X_{a+1}$ (phiên bản thứ $a+1$ của
nút $X$):

-   Nếu một nút con $Y$ không cần sửa thông tin, chỉ cần cho con trỏ của $X_{a+1}$ trỏ trực tiếp đến $Y_{a}$ (phiên bản thứ $a$ của nút $Y$).
-   Ngược lại, nếu cần sửa $Y$, thì khi **đệ quy xuống tầng dưới**, **tạo mới** nút $Y_{a+1}$ (phiên bản thứ $a+1$ của
    nút $Y$) để **lưu thông tin mới**, đồng thời cho con trỏ của $X_{a+1}$ trỏ đến $Y_{a+1}$.

### Cần những gì

Những thứ cần có:

-   Một mảng `struct` để lưu thông tin của **mỗi nút** (thường gọi là mảng `tree`); nếu viết cây cân bằng **bản con
    trỏ** thì có thể cân nhắc không dùng mảng này.

-   Một **mảng nút gốc**, lưu *gốc cây* của từng phiên bản; mỗi khi truy vấn thông tin phiên bản, bắt đầu từ **nút lưu trong mảng gốc**.

-   `split()` để tách, tức **tách một cây thành hai cây**.

-   `merge()` để hợp nhất, tức **hợp nhất hai cây theo khóa ngẫu nhiên**.

-   `newNode()` để tạo một nút mới.

-   `build()` để xây cây.

#### Tách (split)

Với **thao tác tách**, mỗi khi đi qua đường tách thì **tạo nút mới** trỏ đến đường được tách ra, và dùng `std::pair` để
lưu gốc của hai cây mới được tách.

`split(x,k)` trả về một `std::pair`.

Nó biểu thị việc đưa $k$ phần tử đầu tiên của cây gốc $_x$ vào **một cây**, các nút còn lại tạo thành cây kia, rồi trả
về gốc của hai cây đó (`first` là gốc cây thứ nhất, `second` là gốc cây thứ hai).

-   Nếu $key$ của **cây con trái** của $x$ thỏa $key \geq k$, thì **đệ quy trực tiếp vào cây con trái**, rồi hợp nhất cây
    thứ hai tách ra từ cây con trái với **cây con phải** hiện tại của $x$.
-   Ngược lại, đệ quy vào **cây con phải**.

```cpp
static std::pair<int, int> _split(int _x, int k) {
  if (_x == 0)
    return std::make_pair(0, 0);
  else {
    int _vs = ++_cnt;  // Tạo nút mới (cốt lõi của bền vững hóa)
    _trp[_vs] = _trp[_x];
    std::pair<int, int> _y;
    if (_trp[_vs].key <= k) {
      _y = _split(_trp[_vs].leaf[1], k);
      _trp[_vs].leaf[1] = _y.first;
      _y.first = _vs;
    } else {
      _y = _split(_trp[_vs].leaf[0], k);
      _trp[_vs].leaf[0] = _y.second;
      _y.second = _vs;
    }
    _trp[_vs]._update();
    return _y;
  }
}
```

#### Hợp nhất (merge)

`merge(x,y)` trả về gốc của cây sau khi hợp nhất.

Cũng cài đặt bằng đệ quy. Nếu **khóa ngẫu nhiên của x** > **khóa ngẫu nhiên của y** thì gọi `merge(x_{rc},y)`, ngược lại
gọi `merge(x,y_{lc})`.

```cpp
static int _merge(int _x, int _y) {
  if (_x == 0 || _y == 0)
    return _x ^ _y;
  else {
    if (_trp[_x].fix < _trp[_y].fix) {
      _trp[_x].leaf[1] = _merge(_trp[_x].leaf[1], _y);
      _trp[_x]._update();
      return _x;
    } else {
      _trp[_y].leaf[0] = _merge(_x, _trp[_y].leaf[0]);
      _trp[_y]._update();
      return _y;
    }
  }
}
```

## WBLT bền vững

### Kiến thức cần có

WBLT bền vững được sửa đổi từ WBLT, nên trước tiên nên học [WBLT](./wblt.md).

### Ý tưởng/cách làm

Dùng phương pháp **sao chép đường đi**, sao chép các nút **bị sửa đổi** trong một thao tác để không ảnh hưởng đến các
nút ở phiên bản trước.

### Xử lý nhãn lười

Để xử lý nhãn lười, xét như sau: trên một WBLT bền vững, một nút có thể có nhiều cha, nhưng số con của nó chỉ có thể là
$0$ hoặc $2$. Thao tác `pushdown` đẩy nhãn lười xuống chỉ ảnh hưởng đến các con của nút. Việc `pushdown` trên bản thân
một nút không gây vấn đề; vấn đề nằm ở các con của nó, vì con của nó có thể có nhiều hơn một cha. Nếu đẩy nhãn xuống
con, có thể khiến một phiên bản thuộc cha khác xuất hiện thêm nhãn lười không thuộc phiên bản đó, dẫn đến sai, trừ khi
con đó chỉ có một cha. Vì vậy khi `pushdown`, nên sao chép các con một lần rồi gắn nhãn lười lên các con mới.

### Cài đặt sao chép đường đi

Khi thực hiện sao chép đường đi, có thể định nghĩa một hàm `refresh` nhận tham chiếu đến một nút $p$, biểu thị việc sao
chép nút $p$ để tạo một nút mới rồi gán lại cho $p$. Nguyên tắc dùng `refresh` là: nếu nút sắp bị sửa, hoặc các con mà
nó sở hữu sắp thay đổi (không phải thông tin của con sắp bị sửa), thì `refresh` nó; nếu không thì không cần.

Với truy vấn tĩnh, ngoài `pushdown` ra thì không cần `refresh`. Nếu bảo đảm mọi thao tác đều sao chép đường đi, thứ tự
giữa `pushdown` và `refresh` không quan trọng.

### Tối ưu nhỏ cho WBLT bền vững

Có một tối ưu nhỏ. Khi `pushdown` cần sao chép hai nút, cũng có thể dùng cách vĩnh viễn hóa nhãn. Nhưng như đã nói, nếu
con của nó chỉ có một cha thì không cần sao chép. Dựa trên tính chất này, có thể tối ưu để giảm số nút bị sao chép dư.

Xét việc ghi lại mỗi nút có bao nhiêu cha (xem gốc của mỗi phiên bản cũng có một cha), ký hiệu là $use$. Mỗi lần
`refresh`, nếu $use\leq 1$ thì không cần sao chép lại nút; ngược lại tạo nút mới và giảm $use$ đi $1$, biểu thị cha đã
mang nút con này sang bản sao mới. Như vậy cha có thể tùy ý sửa nút mới mà không ảnh hưởng đến các phiên bản khác.
Ngoài ra, mỗi khi sao chép một nút, nếu nút đó có con thì $use$ của hai con tăng thêm $1$; khi hợp nhất hai cây con, nút
được trả về cũng tạo thêm một cha cho hai con; khi xóa nút, hai nút con đều mất đi một cha. Cách này có thể tối ưu một
phần thời gian và không gian.

### Cài đặt

??? note "Mã đầy đủ (cây cân bằng văn nghệ bền vững)"
    ```cpp
    --8<-- "docs/ds/code/persistent-balanced/persistent-wblt.cpp"
    ```

## Bài ví dụ

???+ note "[Luogu P3835 [Mẫu] Cây cân bằng bền vững](https://www.luogu.com.cn/problem/P3835)"
    Cần cài đặt một cấu trúc dữ liệu hỗ trợ các thao tác sau (ban đầu cấu trúc dữ liệu rỗng):
    
    1.  Chèn số $x$.
    2.  Xóa số $x$ (nếu có nhiều số giống nhau thì chỉ xóa một; nếu không có thì bỏ qua thao tác).
    3.  Truy vấn thứ hạng của số $x$ (thứ hạng được định nghĩa là số lượng số nhỏ hơn số hiện tại cộng $1$).
    4.  Truy vấn số có thứ hạng $x$.
    5.  Tìm tiền nhiệm của $x$ (tiền nhiệm là số nhỏ hơn $x$ và lớn nhất; nếu không tồn tại thì xuất $-2\,147\,483\,647$).
    6.  Tìm kế nhiệm của $x$ (kế nhiệm là số lớn hơn $x$ và nhỏ nhất; nếu không tồn tại thì xuất $2\,147\,483\,647$).
    
    Các thao tác trên đều dựa trên một phiên bản lịch sử nào đó, đồng thời sinh ra một phiên bản mới (với thao tác 3, 4,
    5, 6 thì phiên bản gốc được giữ nguyên). Mã số của mỗi phiên bản chính là số thứ tự thao tác. Đặc biệt, phiên bản
    ban đầu có mã số 0.

Đây chính là phiên bản bền vững của bài **cây cân bằng thông thường**, các thao tác tương tự bài đó.

Điểm khác là sử dụng các thao tác `merge` và `split` bền vững.

## Bài luyện tập đề xuất

1.  ["Luogu P3919" Mảng bền vững (bài mẫu)](https://www.luogu.com.cn/problem/P3919)

2.  ["Codeforces 702F" T-shirt](http://codeforces.com/problemset/problem/702/F)

3.  ["Luogu P5055" Cây cân bằng văn nghệ bền vững](https://www.luogu.com.cn/problem/P5055)

4.  ["Luogu P5350" Dãy](https://www.luogu.com.cn/problem/P5350)
