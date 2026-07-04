## Tổng quan

Cơ chế **namespace** của C++ có thể dùng để giải quyết vấn đề xung đột tên trong
các dự án phức tạp.

Lấy một ví dụ: toàn bộ nội dung của thư viện chuẩn C++ đều được định nghĩa trong
namespace `std`. Nếu bạn định nghĩa một biến tên là `cin`, bạn có thể truy cập
biến `cin` do mình định nghĩa bằng `cin`, đồng thời truy cập đối tượng `cin` của
thư viện chuẩn bằng `std::cin`, mà không cần lo xung đột.

## Khai báo

Đoạn mã sau khai báo một namespace tên là `A`:

```cpp
namespace A {
int cnt;

void f(int x) { cnt = x; }
}  // namespace A
```

Sau khi khai báo, ở bên ngoài namespace này, bạn có thể dùng `A::f(x)` để truy
cập hàm `f` bên trong namespace `A`, cũng có thể dùng `A::cnt` để truy cập biến
`cnt` bên trong namespace `A`.

Khai báo namespace có thể lồng nhau, vì vậy đoạn mã sau cũng được phép:

```cpp
namespace A {
namespace B {
void f() { ... }
}  // namespace B

void f() {
  B::f();  // thực ra truy cập A::B::f(); vì hiện đang ở trong namespace A,
           // nên có thể lược bỏ A:: phía trước
}
}  // namespace A

void f()  // ở đây định nghĩa hàm f trong namespace toàn cục, không xung đột
          // với A::f hay A::B::f
{
  A::f();
  A::B::f();
}
```

## Chỉ thị `using`

Sau khi khai báo namespace, nếu ở bên ngoài namespace mà muốn truy cập thành
viên bên trong namespace, cần thêm `namespace::` trước tên thành viên.

Có cách nào tiện hơn để ta trực tiếp truy cập thành viên trong namespace bằng
tên thành viên không? Câu trả lời là có. Ta có thể dùng chỉ thị `using`.

Chỉ thị `using` có hai dạng sau:

1.  `using namespace::tên_thành_viên;`: chỉ thị này cho phép ta lược bỏ namespace
    trước tên của một thành viên nào đó và truy cập trực tiếp bằng tên thành
    viên. Tương đương với việc đưa thành viên này vào phạm vi hiện tại.
2.  `using namespace tên_namespace;`: chỉ thị này cho phép trực tiếp truy cập
    **mọi** thành viên trong namespace bằng tên thành viên. Tương đương với việc
    đưa toàn bộ thành viên của namespace này vào phạm vi hiện tại.

Vì vậy, nếu thực thi `using namespace std;`, mọi tên trong `std` sẽ được đưa vào
namespace toàn cục trong phạm vi hiện tại. Khi đó ta có thể dùng `cin` thay cho
`std::cin`, dùng `cout` thay cho `std::cout`.

??? warning "Chỉ thị `using` có thể gây xung đột tên!"
    Vì `using namespace std;` sẽ đưa **toàn bộ tên** trong `std` vào phạm vi
    hiện tại, nếu khai báo biến hoặc hàm trùng tên với `std`, có thể xảy ra lỗi
    biên dịch do xung đột tên.

    Vì vậy trong phát triển phần mềm, không khuyến nghị dùng chỉ thị
    `using namespace tên_namespace;`.

Với chỉ thị `using`, đoạn mã trong [cú pháp C++ cơ bản](./basic.md#cin-và-cout)
có thể viết theo hai cách tương đương sau:

```cpp
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int x, y;
  cin >> x >> y;
  cout << y << endl << x;
  return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  cout << y << endl << x;
  return 0;
}
```

## Namespace vô danh

Khi trong một phạm vi ta chỉ định nghĩa một namespace để tránh xung đột tên, cách
định nghĩa và sử dụng nó có thể trở nên rất gọn. Ta có thể dùng namespace vô
danh.

Namespace được định nghĩa dưới dạng `namespace { /* something ... */ }`, tức bỏ
qua tên namespace, được gọi là namespace vô danh. Namespace vô danh trong một
file được xem như có một tên riêng duy nhất, khác với mọi namespace khác, nhưng
nhiều namespace vô danh trong cùng một phạm vi được xem là cùng một namespace.
Sau khi namespace vô danh được định nghĩa, các tên bên trong nó có thể được tìm
thấy khi dùng ở phạm vi bên ngoài, giống như sau định nghĩa namespace vô danh đã
thêm một chỉ thị `using namespace`.

## Ứng dụng

### Tránh xung đột tên giữa các subtask

Trong một số bài toán có nhiều subtask, ta có thể định nghĩa một namespace riêng
cho từng subtask, rồi định nghĩa các biến và hàm cần thiết để giải subtask đó
bên trong. Như vậy, ngay cả khi hai phần cài đặt subtask khai báo cùng một tên,
chúng cũng không xung đột, giúp các subtask không ảnh hưởng lẫn nhau. Điều này
thuận tiện hơn cho debug ở một mức độ nhất định và cũng cải thiện khả năng đọc
của chương trình.

### Tránh xung đột với thư viện chuẩn và tên do môi trường đưa vào

Đồng thời, dùng namespace cũng có thể tránh việc một số tên thường dùng trong
lập trình thi đấu xung đột với chuẩn, như ví dụ sau:

```cpp
#include <math.h>

#include <vector>

using namespace std;

namespace Sol {
int end;  // std::end được đưa vào bởi using namespace std;

int y1;  // y1 là hàm Bessel loại hai do POSIX định nghĩa

// Vì vậy trong tình huống thông thường, trên Linux sẽ có xung đột còn trên
// Windows thì không.

void solve() {
  // Trong Sol::solve(), việc dùng end và y1 mà ta đã khai báo theo cách không
  // định danh đầy đủ (không dùng ::) sẽ không gây xung đột tên. Nếu đoạn mã
  // trên nằm trong namespace toàn cục thì sẽ gây xung đột: end chỉ xung đột với
  // std::end khi tra cứu tên (tức khi biên dịch mã sử dụng nó), còn y1 xung đột
  // ngay lúc khai báo. Hơn nữa, xung đột của y1 phụ thuộc vào môi trường, nên
  // thậm chí có thể không bị phát hiện trên Windows nhưng lại gây lỗi biên dịch
  // trong môi trường chấm Linux.
}
}  // namespace Sol

int main() { Sol::solve(); }
```

## Tham khảo

-   [Namespaces - cppreference.com](https://en.cppreference.com/w/cpp/language/namespace)
