## Tổng quan

Cơ chế **không gian tên** (`namespace`) của C++ dùng để giải quyết vấn đề xung
đột tên trong các dự án phức tạp.

Ví dụ, toàn bộ nội dung của thư viện chuẩn C++ đều được định nghĩa trong không
gian tên `std`. Nếu tự định nghĩa một biến tên là `cin`, có thể truy cập biến
`cin` đó bằng `cin`, đồng thời truy cập đối tượng `cin` của thư viện chuẩn bằng
`std::cin`, nhờ đó tránh xung đột tên.

## Định nghĩa

Đoạn mã sau định nghĩa một không gian tên có tên `A`:

```cpp
namespace A {
int cnt;

void f(int x) { cnt = x; }
}  // namespace A
```

Sau khi định nghĩa, ở bên ngoài không gian tên này, có thể dùng `A::f(x)` để
truy cập hàm `f` bên trong không gian tên `A`, đồng thời dùng `A::cnt` để truy
cập biến `cnt` bên trong không gian tên `A`.

Không gian tên có thể lồng nhau, vì vậy đoạn mã sau cũng được phép:

```cpp
namespace A {
namespace B {
void f() {
  // ...
}
}  // namespace B

void f() {
  B::f();  // truy cập A::B::f(); vì hiện đang ở trong không gian tên A,
           // nên có thể lược bỏ A:: phía trước
}
}  // namespace A

void f()  // định nghĩa hàm f trong không gian tên toàn cục, không xung đột
          // với A::f hay A::B::f
{
  A::f();
  A::B::f();
}
```

## Khai báo và chỉ thị `using`

Sau khi định nghĩa không gian tên, nếu muốn truy cập thành viên từ bên ngoài
không gian tên, cần thêm `tên_không_gian_tên::` trước tên thành viên.

Để truy cập thành viên trong không gian tên chỉ bằng tên thành viên, có thể dùng
`using`.

`using` có hai dạng thường gặp sau:

1.  `using tên_không_gian_tên::tên_thành_viên;`: khai báo này cho phép lược bỏ
    tên không gian tên trước một thành viên cụ thể và truy cập bằng chính tên
    thành viên đó. Nó đưa riêng thành viên đó vào phạm vi hiện tại.
2.  `using namespace tên_không_gian_tên;`: chỉ thị này cho phép truy cập **mọi**
    thành viên trong không gian tên bằng tên thành viên. Nó đưa toàn bộ thành
    viên của không gian tên này vào phạm vi hiện tại.

Vì vậy, nếu viết `using namespace std;`, mọi tên trong `std` sẽ được đưa vào
phạm vi hiện tại. Khi đó có thể dùng `cin` thay cho `std::cin`, dùng `cout` thay
cho `std::cout`.

??? warning "Chỉ thị `using namespace` có thể gây xung đột tên!"
    Vì `using namespace std;` sẽ đưa **toàn bộ tên** trong `std` vào phạm vi
    hiện tại, nếu khai báo biến hoặc hàm trùng với tên trong `std`, có thể xảy
    ra lỗi biên dịch do xung đột tên.

    Vì vậy, trong phát triển phần mềm, không nên dùng chỉ thị
    `using namespace tên_không_gian_tên;`.

Với `using`, đoạn mã trong [cú pháp C++ cơ bản](./basic.md#cin-và-cout)
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

## Không gian tên vô danh

Khi trong một phạm vi chỉ cần định nghĩa một không gian tên (`namespace`) để
tránh xung đột tên nội bộ, có thể viết gọn phần định nghĩa và sử dụng bằng không
gian tên vô danh.

Không gian tên được định nghĩa dưới dạng `namespace { /* something ... */ }`,
tức bỏ qua tên sau từ khóa `namespace`, được gọi là không gian tên vô danh. Một
không gian tên vô danh trong một tệp được xem như có một tên riêng duy nhất, khác
với mọi không gian tên khác; nhưng nhiều khối không gian tên vô danh trong cùng
một phạm vi được xem là cùng một không gian tên. Sau khi không gian tên vô danh
được định nghĩa, các tên bên trong nó có thể được tìm thấy khi dùng ở phạm vi bên
ngoài, giống như sau phần định nghĩa đã có thêm một chỉ thị `using namespace`.

## Ứng dụng

### Tránh xung đột tên giữa các bài con

Trong một số bài toán có nhiều bài con, có thể định nghĩa một không gian tên
riêng cho từng bài con, rồi đặt các biến và hàm cần thiết để giải bài con đó bên
trong. Khi đó, ngay cả khi hai phần cài đặt bài con khai báo cùng một tên, chúng
cũng không xung đột, giúp các bài con không ảnh hưởng lẫn nhau. Cách làm này
giúp gỡ lỗi thuận tiện hơn và cũng cải thiện khả năng đọc của chương trình.

### Tránh xung đột với thư viện chuẩn và tên do môi trường đưa vào

Dùng không gian tên cũng có thể tránh việc một số tên thường dùng trong lập trình
thi đấu xung đột với thư viện chuẩn hoặc môi trường biên dịch, như ví dụ sau:

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
  // Trong Sol::solve(), việc dùng end và y1 đã khai báo ở trên theo cách không
  // định danh đầy đủ (không dùng Sol::) sẽ không gây xung đột tên. Nếu các khai
  // báo trên nằm trong không gian tên toàn cục thì sẽ gây xung đột: end chỉ xung
  // đột với std::end khi tra cứu tên (tức khi biên dịch mã sử dụng nó), còn y1
  // xung đột ngay lúc khai báo. Hơn nữa, xung đột của y1 phụ thuộc vào môi
  // trường, nên thậm chí có thể không bị phát hiện trên Windows nhưng lại gây
  // lỗi biên dịch trong môi trường chấm Linux.
}
}  // namespace Sol

int main() { Sol::solve(); }
```

## Tham khảo

-   [Namespaces - cppreference.com](https://en.cppreference.com/w/cpp/language/namespace)
