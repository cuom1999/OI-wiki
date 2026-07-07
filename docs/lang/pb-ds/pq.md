author: Xeonacid, ouuan, Ir1d, WAAutoMaton, Chrogeek, abc1763613206, Planet6174, i-Yirannn, opsiff, GoodCoder666

## `__gnu_pbds::priority_queue`

Kèm theo:
[tài liệu chính thức về độ phức tạp và kiểm thử hệ số hằng](https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/pq_performance_tests.html#std_mod1)

```cpp
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
__gnu_pbds::priority_queue<T, Compare, Tag, Allocator>
```

## Tham số mẫu

-   `T`: kiểu phần tử được lưu trữ.
-   `Compare`: kiểu so sánh cung cấp thứ tự yếu nghiêm ngặt.
-   `Tag`: chọn một trong năm loại đống do `__gnu_pbds` cung cấp; giá trị mặc
    định là `pairing_heap_tag`. Năm loại này gồm:
    -   `pairing_heap_tag`: đống ghép cặp (pairing heap)
        Tài liệu chính thức cho rằng đống ghép cặp có hiệu năng tốt nhất với
        phần tử không nguyên thủy, chẳng hạn `struct` tự định nghĩa,
        `std::string`, `pair`.
    -   `binary_heap_tag`: đống nhị phân
        Tài liệu chính thức cho rằng đống nhị phân có hiệu năng tốt nhất với
        phần tử nguyên thủy, nhưng kết quả thử nghiệm của tác giả không tốt đến
        vậy.
    -   `binomial_heap_tag`: đống nhị thức
        Đống nhị thức có hiệu năng hợp nhất tốt hơn đống nhị phân, nhưng thao
        tác loại bỏ phần tử đầu đống có độ phức tạp cao hơn đống nhị phân.
    -   `rc_binomial_heap_tag`: đống nhị thức đếm dư thừa
    -   `thin_heap_tag`: một thẻ có hầu hết độ phức tạp giống đống Fibonacci, trừ
        thao tác hợp nhất.
-   `Allocator`: bộ cấp phát bộ nhớ; vì hiếm gặp trong OI nên không giải thích ở
    đây.

Vì bài này hướng đến người học lập trình thi đấu, bốn thẻ còn lại chỉ được giới
thiệu sơ lược qua độ phức tạp; thẻ đầu tiên sẽ được trình bày kỹ hơn về hàm
thành viên và cách dùng.

Qua thử nghiệm các thao tác đống cơ bản trên máy của tác giả (Core i5 @3.1 GHz
trên macOS), kết hợp với kiểm thử độ phức tạp chính thức của GNU và kiểm thử
Dijkstra, có thể rút ra nhận xét: ít nhất với người học OI, bốn thẻ ngoài đống
ghép cặp thường không đáng dùng trong thực tế, vì hoặc không đem lại lợi ích rõ
ràng, hoặc có hệ số hằng lớn đến mức thua `std`, thậm chí có thể gây MLE. Vì
vậy, thường chỉ nên dùng đống ghép cặp mặc định. Tương tự, đống ghép cặp cũng
tốt hơn `make_heap()` trong tệp tiêu đề `<algorithm>` trong các thử nghiệm này.

## Cách khởi tạo

Cần ghi rõ không gian tên vì tên lớp trùng với `std`.

```cpp
// __gnu_pbds::priority_queue<int>;
// __gnu_pbds::priority_queue<int, greater<int>>;
// __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag>;
__gnu_pbds::priority_queue<int>::point_iterator id;  // bộ lặp kiểu điểm
// modify và push đều trả về point_iterator; phần sau sẽ giải thích cách dùng.
id = q.push(1);
```

## Hàm thành viên

-   `push()`: đưa một phần tử vào đống, trả về bộ lặp kiểu điểm trỏ tới phần tử
    đó.
-   `pop()`: loại bỏ phần tử ở đỉnh đống.
-   `top()`: trả về phần tử ở đỉnh đống.
-   `size()`: trả về số phần tử.
-   `empty()`: trả về `true` nếu đống rỗng, ngược lại trả về `false`.
-   `modify(point_iterator, const key)`: sửa phần tử tại vị trí bộ lặp thành
    giá trị `key` truyền vào, rồi điều chỉnh lại cấu trúc đống bên trong.
-   `erase(point_iterator)`: xóa phần tử tại vị trí bộ lặp khỏi đống.
-   `join(__gnu_pbds::priority_queue &other)`: hợp nhất `other` vào `*this` rồi
    làm rỗng `other`.

Thẻ được dùng quyết định độ phức tạp thời gian của từng thao tác:

|                        | `push`                              | `pop`                               | `modify`                            | `erase`                             | `join`            |
| ---------------------- | ----------------------------------- | :---------------------------------- | ----------------------------------- | ----------------------------------- | ----------------- |
| `pairing_heap_tag`     | $O(1)$                              | xấu nhất $\Theta(n)$, khấu hao $\Theta(\log(n))$ | xấu nhất $\Theta(n)$, khấu hao $\Theta(\log(n))$ | xấu nhất $\Theta(n)$, khấu hao $\Theta(\log(n))$ | $O(1)$            |
| `binary_heap_tag`      | xấu nhất $\Theta(n)$, khấu hao $\Theta(\log(n))$ | xấu nhất $\Theta(n)$, khấu hao $\Theta(\log(n))$ | $\Theta(n)$                         | $\Theta(n)$                         | $\Theta(n)$       |
| `binomial_heap_tag`    | xấu nhất $\Theta(\log(n))$, khấu hao $O(1)$      | $\Theta(\log(n))$                   | $\Theta(\log(n))$                   | $\Theta(\log(n))$                   | $\Theta(\log(n))$ |
| `rc_binomial_heap_tag` | $O(1)$                              | $\Theta(\log(n))$                   | $\Theta(\log(n))$                   | $\Theta(\log(n))$                   | $\Theta(\log(n))$ |
| `thin_heap_tag`        | $O(1)$                              | xấu nhất $\Theta(n)$, khấu hao $\Theta(\log(n))$ | xấu nhất $\Theta(\log(n))$, khấu hao $O(1)$      | xấu nhất $\Theta(n)$, khấu hao $\Theta(\log(n))$ | $\Theta(n)$       |

## Ví dụ

```cpp
#include <algorithm>
#include <cstdio>
#include <ext/pb_ds/priority_queue.hpp>
#include <iostream>
using namespace __gnu_pbds;
// Vì hướng đến người học OI, bài này dùng loại đống thường gặp pairing_heap_tag làm ví dụ
// Để dễ đọc hơn, định nghĩa bí danh như sau:
using pair_heap = __gnu_pbds::priority_queue<int>;
pair_heap q1;  // đống lớn (max-heap), đống ghép cặp
pair_heap q2;
pair_heap::point_iterator id;  // một bộ lặp

int main() {
  id = q1.push(1);
  // Phần tử trong đống: [1];
  for (int i = 2; i <= 5; i++) q1.push(i);
  // Phần tử trong đống: [1, 2, 3, 4, 5];
  std::cout << q1.top() << std::endl;
  // Kết quả in ra: 5;
  q1.pop();
  // Phần tử trong đống: [1, 2, 3, 4];
  id = q1.push(10);
  // Phần tử trong đống: [1, 2, 3, 4, 10];
  q1.modify(id, 1);
  // Phần tử trong đống: [1, 1, 2, 3, 4];
  std::cout << q1.top() << std::endl;
  // Kết quả in ra: 4;
  q1.pop();
  // Phần tử trong đống: [1, 1, 2, 3];
  id = q1.push(7);
  // Phần tử trong đống: [1, 1, 2, 3, 7];
  q1.erase(id);
  // Phần tử trong đống: [1, 1, 2, 3];
  q2.push(1), q2.push(3), q2.push(5);
  // Phần tử trong q1: [1, 1, 2, 3], phần tử trong q2: [1, 3, 5];
  q2.join(q1);
  // q1 không còn phần tử, phần tử trong q2: [1, 1, 1, 2, 3, 3, 5];
}
```

## Bảo đảm vô hiệu hóa bộ lặp của `__gnu_pbds` (`invalidation_guarantee`)

Trong ví dụ trên và trong một số tình huống thực tế (như dùng đống `pb_ds` của
chương này để viết thuật toán đường đi ngắn nhất từ một nguồn), ta thường cần
lưu và dùng bộ lặp của đống, chẳng hạn
`__gnu_pbds::priority_queue<int>::point_iterator`).

Tuy nhiên, với các tham số `Tag` khác nhau của `__gnu_pbds::priority_queue`,
cách cài đặt nội bộ không giống nhau, nên điều kiện vô hiệu hóa bộ lặp cũng
khác nhau. Theo thiết kế của thư viện `__gnu_pbds`, có ba mức bảo đảm theo thứ
tự từ yếu đến mạnh:

1.  Bảo đảm vô hiệu hóa cơ bản (`basic_invalidation_guarantee`): khi không sửa
    bộ chứa, bộ lặp kiểu điểm (`point_iterator`), con trỏ và tham chiếu
    (khóa/giá trị) **vẫn** hợp lệ.

2.  Bảo đảm vô hiệu hóa điểm (`point_invalidation_guarantee`): sau khi **sửa**
    bộ chứa, bộ lặp kiểu điểm (`point_iterator`), con trỏ và tham chiếu
    (khóa/giá trị) **vẫn** hợp lệ miễn là phần tử tương ứng chưa bị xóa khỏi
    bộ chứa.

3.  Bảo đảm vô hiệu hóa phạm vi (`range_invalidation_guarantee`): sau khi
    **sửa** bộ chứa, ngoài tính chất ở (2), mọi bộ lặp kiểu phạm vi (bao gồm
    giá trị trả về của `begin()` và `end()`) đều hợp lệ. Các thẻ có bảo đảm vô
    hiệu hóa phạm vi gồm `rb_tree_tag`, `splay_tree_tag` dùng cho
    `__gnu_pbds::tree`, và `pat_trie_tag` dùng cho `__gnu_pbds::trie`.

Từ kết quả chạy đoạn mã sau, ngoại trừ `binary_heap_tag` là
`basic_invalidation_guarantee` và bộ lặp sẽ bị vô hiệu sau khi sửa, các thẻ còn
lại đều là `point_invalidation_guarantee`, đáp ứng nhu cầu giữ bộ lặp kiểu điểm
(`point_iterator`) không bị vô hiệu sau khi sửa.

```cpp
#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
#include <cxxabi.h>

template <typename T>
void print_invalidation_guarantee() {
  using gute = __gnu_pbds::container_traits<T>::invalidation_guarantee;
  cout << abi::__cxa_demangle(typeid(gute).name(), 0, 0, 0) << endl;
}

int main() {
  using pairing =
      __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag>;
  using binary = __gnu_pbds::priority_queue<int, greater<int>, binary_heap_tag>;
  using binomial =
      __gnu_pbds::priority_queue<int, greater<int>, binomial_heap_tag>;
  using rc_binomial =
      __gnu_pbds::priority_queue<int, greater<int>, rc_binomial_heap_tag>;
  using thin = __gnu_pbds::priority_queue<int, greater<int>, thin_heap_tag>;
  print_invalidation_guarantee<pairing>();
  print_invalidation_guarantee<binary>();
  print_invalidation_guarantee<binomial>();
  print_invalidation_guarantee<rc_binomial>();
  print_invalidation_guarantee<thin>();
  return 0;
}
```
