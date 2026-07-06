author: sbofgayschool

`std::pair` là một mẫu lớp (class template) trong thư viện chuẩn. Nó dùng để
ghép hai giá trị thành một "cặp"; hai giá trị này có thể thuộc hai kiểu khác
nhau.

??? note "Mẫu lớp"
    Bản thân mẫu lớp không phải là một lớp cụ thể, mà là một "khuôn mẫu" dùng
    để sinh ra **các lớp khác nhau** ứng với **các kiểu dữ liệu khác nhau**.

    Khi sử dụng, trình biên dịch sẽ sinh lớp tương ứng với các kiểu dữ liệu
    được truyền vào, rồi tạo đối tượng thuộc lớp đó.

    Cơ chế template là một tính năng nâng cao của C++; trong thi đấu tin học,
    thường chỉ cần biết cách dùng các template có sẵn trong thư viện chuẩn. Nếu
    quan tâm, có thể đọc thêm "C++ Primer" để học sâu hơn về C++.

Sử dụng `pair` linh hoạt giúp xử lý gọn các tình huống **cần ghép hai dữ liệu
liên quan để lưu trữ và xử lý**.

??? note "Cấu trúc (`struct`)"
    So với `struct` tự định nghĩa, `pair` không cần khai báo thêm cấu trúc và
    nạp chồng toán tử, nên dùng gọn hơn.

    Tuy nhiên, tên thành viên trong `struct` tự định nghĩa thường dễ hiểu hơn
    (`pair` chỉ có thể dùng `first` và `second` để truy cập hai thành viên bên
    trong). Đồng thời, nếu cần liên kết nhiều hơn hai biến, `struct` tự định
    nghĩa sẽ phù hợp hơn.

## Cách dùng

### Khởi tạo

Có thể khởi tạo `pair` ngay khi định nghĩa.

```cpp
pair<int, double> p0(1, 2.0);
```

Cũng có thể định nghĩa trước, sau đó gán giá trị cho từng thành viên.

```cpp
pair<int, double> p1;
p1.first = 1;
p1.second = 2.0;
```

Cũng có thể dùng hàm `std::make_pair`. Hàm này nhận hai giá trị và trả về
`pair` được tạo từ hai giá trị đó.

```cpp
pair<int, double> p2 = make_pair(1, 2.0);
```

Trong một số mã thi đấu cũ, người viết định nghĩa macro `#define mp make_pair`
để rút gọn tên hàm `make_pair` thành `mp`. Cách này không cần thiết; gọi
`make_pair` hoặc khởi tạo bằng dấu `{}` thường dễ đọc hơn.

Từ C++11 trở đi, có thể khởi tạo trực tiếp bằng danh sách, ví dụ
`pair<int, double> p{1, 2.0};`. `make_pair` cũng có thể dùng cùng `auto` để
tránh khai báo kiểu dữ liệu tường minh.

```cpp
auto p3 = make_pair(1, 2.0);
```

Về cách dùng `auto` trong thi đấu tin học, xem giải thích ở phần
[bộ lặp](./iterator.md).

### Truy cập

Thông qua hai thành viên `first` và `second`, có thể truy cập hai giá trị được
lưu trong `pair`.

```cpp
int i = p0.first;
double d = p0.second;
```

Cũng có thể sửa chúng.

```cpp
p1.first++;
```

### So sánh

`pair` đã định nghĩa sẵn tất cả toán tử so sánh, bao gồm `<`, `>`, `<=`, `>=`,
`==`, `!=`. Vì vậy, các kiểu dữ liệu tạo nên `pair` cũng cần hỗ trợ các phép so
sánh tương ứng, chẳng hạn `==` hoặc `<`.

Trong đó, bốn toán tử `<`, `>`, `<=`, `>=` sẽ so sánh thành viên thứ nhất của
hai `pair` trước; nếu thành viên thứ nhất bằng nhau thì tiếp tục so sánh thành
viên thứ hai. Đây chính là thứ tự từ điển.

```cpp
if (p2 >= p3) {
  cout << "do something here" << endl;
}
```

Vì `pair` định nghĩa `<` và `==` thường dùng trong STL, nó có thể phối hợp tốt
với các hàm hoặc cấu trúc dữ liệu STL khác. Ví dụ, `pair` có thể làm kiểu phần
tử của `priority_queue`.

```cpp
priority_queue<pair<int, double>> q;
```

### Gán và hoán đổi

Có thể gán giá trị của một `pair` cho một `pair` khác cùng kiểu.

```cpp
p0 = p1;
```

Cũng có thể dùng hàm `swap` để hoán đổi giá trị của `pair`.

```cpp
swap(p0, p1);
p2.swap(p3);
```

## Ví dụ ứng dụng

### Rời rạc hóa

`pair` có thể dùng để cài đặt rời rạc hóa một cách gọn gàng.

Có thể tạo một mảng `pair`, dùng thành viên thứ nhất của mỗi `pair` để lưu giá
trị dữ liệu gốc, và thành viên thứ hai để lưu vị trí ban đầu của dữ liệu đó. Sau
khi sắp xếp, gán thứ hạng của từng giá trị gốc (vị trí của giá trị đó sau khi
sắp xếp) về vị trí ban đầu tương ứng.

```cpp
// a là dữ liệu gốc
pair<int, int> a[MAXN];
// ai là dữ liệu sau rời rạc hóa
int ai[MAXN];
for (int i = 0; i < n; i++) {
  // first là giá trị dữ liệu gốc, second là vị trí dữ liệu gốc
  scanf("%d", &a[i].first);
  a[i].second = i;
}
// sắp xếp
sort(a, a + n);
for (int i = 0; i < n; i++) {
  // Gán thứ hạng của giá trị này về vị trí ban đầu của nó
  ai[a[i].second] = i;
}
```

### Dijkstra

Như đã nói, `pair` có thể làm kiểu dữ liệu của `priority_queue`.

Trong phiên bản Dijkstra tối ưu bằng heap, có thể dùng `pair` và
`priority_queue` để duy trì các đỉnh: thành viên thứ nhất lưu khoảng cách hiện
tại từ nguồn đến đỉnh, còn thành viên thứ hai lưu số hiệu đỉnh. Ví dụ dưới đây
dùng `greater<pair<int, int>>` để biến `priority_queue` mặc định thành min-heap
theo thứ tự từ điển của `pair`.

```cpp
priority_queue<pair<int, int>, std::vector<pair<int, int>>,
               std::greater<pair<int, int>>>
    q;
... while (!q.empty()) {
  // dis là khoảng cách từ nguồn đến đỉnh khi được đưa vào heap, i là số hiệu đỉnh
  int dis = q.top().first, i = q.top().second;
  q.pop();
  ...
}
```

### `pair` và `map`

`map` là cấu trúc dữ liệu lưu cặp khóa-giá trị trong C++. Về cơ bản, mỗi phần tử
của `map` là một cặp gồm khóa và giá trị (khóa được giữ const bên trong
`map`), nên khi chèn dữ liệu thường dùng `pair` hoặc `make_pair`.

```cpp
map<int, double> m;
m.insert(make_pair(1, 2.0));
```

Xem thêm nội dung về `map` trong các phần liên quan ở
[bộ chứa kết hợp](./associative-container.md) và
[bộ chứa kết hợp không thứ tự](./unordered-container.md).
