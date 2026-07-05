author: sbofgayschool

`std::pair` là một mẫu lớp được định nghĩa trong thư viện chuẩn. Nó dùng
để liên kết hai biến lại với nhau thành một "cặp", và kiểu dữ liệu của hai biến
có thể khác nhau.

??? note "Mẫu lớp"
    Bản thân mẫu lớp không phải là một lớp, mà là một "khuôn mẫu" có thể
    sinh ra **các lớp khác nhau** theo **các kiểu dữ liệu khác nhau**.

    Khi sử dụng, trình biên dịch sẽ sinh lớp tương ứng theo kiểu dữ liệu được
    truyền vào, rồi tạo thực thể tương ứng.

    Khuôn mẫu là một đặc tính tương đối nâng cao của C++; trong thi đấu tin học
    gần như không cần tự viết `template`. Nếu quan tâm, bạn có thể đọc thêm
    "C++ Primer" để học sâu hơn về C++.

Sử dụng `pair` linh hoạt giúp xử lý dễ dàng các tình huống **cần buộc dữ liệu
liên quan lại để lưu trữ và xử lý**.

??? note "Cấu trúc"
    So với `struct` tự định nghĩa, `pair` không cần định nghĩa thêm cấu trúc và
    nạp chồng toán tử, nên dùng đơn giản hơn.

    Tuy nhiên, tên biến trong `struct` tự định nghĩa thường rõ ràng hơn (`pair`
    chỉ có thể dùng `first` và `second` để truy cập hai biến bên trong). Đồng
    thời, nếu cần liên kết nhiều hơn hai biến, `struct` tự định nghĩa sẽ phù hợp
    hơn.

## Cách dùng

### Khởi tạo

Có thể khởi tạo `pair` trực tiếp khi định nghĩa.

```cpp
pair<int, double> p0(1, 2.0);
```

Cũng có thể định nghĩa trước rồi gán sau để hoàn thành khởi tạo `pair`.

```cpp
pair<int, double> p1;
p1.first = 1;
p1.second = 2.0;
```

Cũng có thể dùng hàm `std::make_pair`. Hàm này nhận hai biến và trả về `pair`
được tạo từ hai biến đó.

```cpp
pair<int, double> p2 = make_pair(1, 2.0);
```

Một cách dùng phổ biến là định nghĩa macro `#define mp make_pair`, rút gọn
`make_pair` hơi dài thành `mp`.

Trong C++11 và các phiên bản mới hơn, `make_pair` có thể dùng cùng `auto` để
tránh khai báo kiểu dữ liệu tường minh.

```cpp
auto p3 = make_pair(1, 2.0);
```

Về cách dùng `auto` trong thi đấu tin học, xem giải thích ở phần
[bộ lặp](./iterator.md).

### Truy cập

Thông qua hai thành viên `first` và `second`, có thể truy cập hai biến chứa
trong `pair`.

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
`==`, `!=`. Tất nhiên, điều này yêu cầu kiểu dữ liệu của hai biến tạo thành
`pair` đã định nghĩa toán tử `==` và/hoặc `<`.

Trong đó, bốn toán tử `<`, `>`, `<=`, `>=` sẽ so sánh biến thứ nhất của hai
`pair` trước; nếu biến thứ nhất bằng nhau thì tiếp tục so sánh biến thứ hai.

```cpp
if (p2 >= p3) {
  cout << "do something here" << endl;
}
```

Vì `pair` định nghĩa `<` và `==` thường dùng trong STL, nó có thể phối hợp tốt
với các hàm hoặc cấu trúc dữ liệu STL khác. Ví dụ, `pair` có thể làm kiểu dữ
liệu của `priority_queue`.

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

`pair` có thể hiện thực rời rạc hóa rất dễ dàng.

Ta có thể tạo một mảng `pair`, dùng biến thứ nhất của mỗi `pair` để lưu giá trị
dữ liệu gốc, và biến thứ hai để lưu vị trí ban đầu của dữ liệu gốc. Sau khi sắp
xếp, gán thứ hạng của giá trị dữ liệu gốc (vị trí của giá trị đó sau khi sắp
xếp) về vị trí ban đầu của giá trị đó là được.

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

Trong tối ưu heap của thuật toán Dijkstra, có thể dùng `pair` và
`priority_queue` để duy trì đỉnh: lưu khoảng cách hiện tại từ đỉnh đến điểm
nguồn làm biến thứ nhất, và số hiệu đỉnh làm biến thứ hai.

```cpp
priority_queue<pair<int, int>, std::vector<pair<int, int>>,
               std::greater<pair<int, int>>>
    q;
... while (!q.empty()) {
  // dis là khoảng cách từ đỉnh đến nguồn khi được đưa vào heap, i là số hiệu đỉnh
  int dis = q.top().first, i = q.top().second;
  q.pop();
  ...
}
```

### pair và map

`map` là cấu trúc dữ liệu lưu cặp khóa-giá trị trong C++. Trong nhiều trường
hợp, các cặp khóa-giá trị được lưu trong `map` được phơi ra bên ngoài thông qua
`pair`.

```cpp
map<int, double> m;
m.insert(make_pair(1, 2.0));
```

Xem thêm nội dung về `map` trong các phần liên quan ở [bộ chứa kết hợp](./associative-container.md)
và [bộ chứa kết hợp không thứ tự](./unordered-container.md).
