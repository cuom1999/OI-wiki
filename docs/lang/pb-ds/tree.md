## `__gnu_pbds::tree`

Kèm theo: [tài liệu chính thức](https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/tree_based_containers.html)

```cpp
#include <ext/pb_ds/assoc_container.hpp>  // tree được định nghĩa ở đây
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
__gnu_pbds::tree<Key, Mapped, Cmp_Fn = std::less<Key>, Tag = rb_tree_tag,
                 Node_Update = null_tree_node_update,
                 Allocator = std::allocator<char>>
```

## Tham số template

-   `Key`: kiểu phần tử được lưu trữ. Nếu muốn lưu nhiều phần tử có cùng `Key`,
    cần dùng cách tương tự `std::pair` hoặc `struct`, rồi kết hợp các hàm thành
    viên `lower_bound` và `upper_bound` để tìm kiếm.
-   `Mapped`: kiểu chính sách ánh xạ (Mapped-Policy). Nếu muốn biểu diễn
    container kết hợp là **tập hợp**, tương tự lưu phần tử trong `std::set`, hãy
    điền `null_type` tại đây; với phiên bản `g++` cũ, vị trí này là
    `null_mapped_type`. Nếu muốn biểu diễn container kết hợp là **tập hợp có
    giá trị**, tương tự lưu phần tử trong `std::map`, hãy điền kiểu `Value`
    giống như trong `std::map<Key, Value>`.
-   `Cmp_Fn`: functor so sánh khóa, ví dụ `std::less<Key>`.
-   `Tag`: chọn loại cấu trúc dữ liệu nền; mặc định là `rb_tree_tag`.
    `__gnu_pbds` cung cấp ba loại cây cân bằng khác nhau:
    -   `rb_tree_tag`: cây đỏ-đen; thường dùng loại này, hai loại sau thường có
        hiệu năng kém cây đỏ-đen.
    -   `splay_tree_tag`: cây splay.
    -   `ov_tree_tag`: cây vector có thứ tự, chỉ là một cấu trúc có thứ tự hiện
        thực bằng `vector`, tương tự dùng `vector` đã sắp xếp để hiện thực cây
        cân bằng; hiệu năng phụ thuộc dữ liệu có cố tình gây khó hay không.
-   `Node_Update`: chính sách dùng để cập nhật nút; mặc định là
    `null_node_update`. Nếu muốn dùng `order_of_key` và `find_by_order`, cần dùng
    `tree_order_statistics_node_update`.
-   `Allocator`: kiểu bộ cấp phát bộ nhớ.

## Cách khởi tạo

```cpp
__gnu_pbds::tree<std::pair<int, int>, __gnu_pbds::null_type,
                 std::less<std::pair<int, int>>, __gnu_pbds::rb_tree_tag,
                 __gnu_pbds::tree_order_statistics_node_update>
    trr;
```

## Hàm thành viên

-   `insert(x)`: chèn một phần tử `x` vào cây, trả về
    `std::pair<point_iterator, bool>`, trong đó phần tử thứ nhất là iterator tại
    vị trí chèn, phần tử thứ hai cho biết chèn có thành công hay không.
-   `erase(x)`: xóa một phần tử/iterator `x` khỏi cây. Nếu `x` là iterator, hàm
    trả về iterator trỏ đến phần tử sau `x` (nếu `x` là `end()` thì trả về
    `end()`); nếu `x` là `Key`, hàm trả về xóa có thành công hay không (nếu
    không tồn tại thì xóa thất bại).
-   `order_of_key(x)`: trả về số phần tử nhỏ hơn nghiêm ngặt `x` (theo logic so
    sánh của `Cmp_Fn`), tức thứ hạng bắt đầu từ $0$.
-   `find_by_order(x)`: trả về iterator của phần tử ứng với thứ hạng theo so
    sánh của `Cmp_Fn`.
-   `lower_bound(x)`: trả về iterator của phần tử đầu tiên không nhỏ hơn `x`
    (theo logic so sánh của `Cmp_Fn`).
-   `upper_bound(x)`: trả về iterator của phần tử đầu tiên lớn hơn nghiêm ngặt
    `x` (theo logic so sánh của `Cmp_Fn`).
-   `join(x)`: gộp cây `x` vào cây hiện tại, rồi làm rỗng cây `x` (phải bảo đảm
    **hàm so sánh** và **kiểu phần tử** của hai cây giống nhau).
-   `split(x,b)`: theo so sánh của `Cmp_Fn`, các phần tử nhỏ hơn hoặc bằng `x`
    thuộc cây hiện tại, các phần tử còn lại thuộc cây `b`.
-   `empty()`: trả về cây có rỗng hay không.
-   `size()`: trả về kích thước.

???+ warning "Chú ý"
    Hàm `join(x)` yêu cầu miền giá trị khóa của cây được gộp và cây nhận gộp
    **không giao nhau** (tức mọi giá trị trong cây được gộp phải đều lớn hơn
    hoặc đều nhỏ hơn mọi giá trị trong cây hiện tại), nếu không sẽ ném ngoại lệ
    `join_error`.
    
    Nếu cần gộp hai cây có miền giá trị giao nhau, cần chèn từng phần tử của một
    cây vào cây còn lại.

## Ví dụ

```cpp
// Common Header Simple over C++11
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
__gnu_pbds::tree<pair<int, int>, __gnu_pbds::null_type, less<pair<int, int>>,
                 __gnu_pbds::rb_tree_tag,
                 __gnu_pbds::tree_order_statistics_node_update>
    trr;

int main() {
  int cnt = 0;
  trr.insert(make_pair(1, cnt++));
  trr.insert(make_pair(5, cnt++));
  trr.insert(make_pair(4, cnt++));
  trr.insert(make_pair(3, cnt++));
  trr.insert(make_pair(2, cnt++));
  // Phần tử trên cây: {(1,0), (2,4), (3,3), (4,2), (5,1)}

  auto it = trr.lower_bound(make_pair(2, 0));
  trr.erase(it);
  // Phần tử trên cây: {(1,0), (3,3), (4,2), (5,1)}

  // In first của phần tử có thứ hạng 1 trong các thứ hạng 0 1 2 3
  auto it2 = trr.find_by_order(1);
  cout << (*it2).first << endl;  // In ra: 3

  // In thứ hạng của nó
  int pos = trr.order_of_key(*it2);
  cout << pos << endl;  // In ra: 1

  // Tách trr theo it2
  decltype(trr) newtr;
  trr.split(*it2, newtr);
  for (auto i = newtr.begin(); i != newtr.end(); ++i) {
    cout << (*i).first << ' ';  // In ra: 4 5
  }
  cout << endl;

  // Gộp cây newtr vào cây trr, cây newtr bị làm rỗng.
  trr.join(newtr);
  for (auto i = trr.begin(); i != trr.end(); ++i) {
    cout << (*i).first << ' ';  // In ra: 1 3 4 5
  }
  cout << endl;
  cout << newtr.size() << endl;  // In ra: 0

  return 0;
}
```

## Tài liệu tham khảo

-   [Tree-Based Containers](https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/tree_based_containers.html)
-   [Hiện thực hàm `join` trong GCC 14.1.0](https://gcc.gnu.org/onlinedocs/gcc-14.1.0/libstdc++/api/a18391_source.html#l00043)
-   [Hiện thực hàm `erase` trong GCC 14.1.0](https://gcc.gnu.org/onlinedocs/gcc-14.1.0/libstdc++/api/a18211_source.html#l00043)
