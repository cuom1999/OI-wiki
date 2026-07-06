**Ghi chú**: Xét đến nhu cầu thực tế của lập trình thi đấu, bài viết này không
trình bày toàn diện mọi cú pháp hiện đại của C++, mà chỉ giới thiệu những phần
thường dùng trong lập trình thi đấu.

Cú pháp trong bài viết này tham chiếu theo chuẩn **C++11**. Với những chỗ có ngữ
nghĩa khác nhau, **C++11** sẽ được lấy làm chuẩn; cú pháp của C++14, C++17, v.v.
sẽ được nhắc đến tùy trường hợp và được đánh dấu riêng.

## Bộ chỉ định kiểu `auto`

Bộ chỉ định kiểu `auto` dùng để yêu cầu trình biên dịch tự suy luận kiểu của biến
và một số ngữ cảnh khác. Ví dụ:

```cpp
auto a = 1;        // a có kiểu int
auto b = a + 0.1;  // b có kiểu double
```

Khi khai báo biến bằng `auto` đơn thuần, kiểu được suy luận sẽ bỏ phần tham
chiếu. Nếu không muốn tạo bản sao, cần chỉ định tham chiếu một cách tường minh:

```cpp
int a = 1;
int& b = a;
auto c = b;   // c có kiểu int, là một bản sao của a
auto& e = a;  // e có kiểu int&, là tham chiếu tới a
```

## Bộ chỉ định `decltype`

`decltype` có thể suy luận kiểu dựa trên **thực thể** hoặc **biểu thức**. Hai
cách này tuân theo các quy tắc suy luận khác nhau; dùng sai có thể tạo ra tham
chiếu treo. Nội dung này không thường dùng trong thi đấu, nên phần này chỉ giới
thiệu sơ lược.

```cpp
#include <iostream>
#include <vector>

int main() {
  int a = 1926;
  decltype(a) b;                 // Suy luận theo thực thể, b có kiểu int
  decltype(1 + 1) c;             // Suy luận theo biểu thức, c có kiểu int
  decltype((a)) d = a;           // Suy luận theo biểu thức, d có kiểu int&!
  std::vector<decltype(b)> vec;  // Suy luận theo thực thể, vec có kiểu std::vector<int>
  return 0;
}
```

## constexpr

> Xem thêm [biểu thức hằng constexpr (C++11)](const.md#biểu-thức-hằng-constexpr-c11)

<a id="vòng-lặp-for-dựa-trên-phạm-vi"></a>

## Vòng lặp `for` dựa trên phạm vi

Dùng vòng lặp `for` dựa trên phạm vi để duyệt đối tượng có thể lặp, với hiệu
suất tương đương cách duyệt bằng bộ lặp. Hai cách này thường phù hợp hơn duyệt
bằng chỉ số khi chỉ cần đi qua từng phần tử, vì không cần tự quản lý chỉ số.

Sau đây là cú pháp cơ bản của vòng lặp `for` dựa trên phạm vi:

```cpp
for (item_declaration : range_initializer) statement
```

Ví dụ:

```cpp
std::array<int, 4> arr = {1, 2, 3, 4};
for (int x : arr) {
  std::cout << x << std::endl;
}
```

Cú pháp trên có thể được hiểu gần tương đương với đoạn mã sau:

```cpp
std::array<int, 4> arr = {1, 2, 3, 4};
for (auto px = arr.begin(), ed = arr.end(); px != ed; ++px) {
  std::cout << *px << std::endl;
}
```

### Khai báo mục `item-declaration`

Khai báo một biến để nhận từng phần tử trong phạm vi bên phải; kiểu biến phải
tương thích với kiểu phần tử của phạm vi. Có thể dùng `auto` để tự động suy luận
kiểu; với kiểu phức tạp, thường dùng `auto&` hoặc `const auto&` để tránh sao chép
không cần thiết.

### Bộ khởi tạo phạm vi `range-initializer`

Bộ khởi tạo phạm vi có thể là bất kỳ đối tượng có thể lặp nào, chẳng hạn mảng
hoặc đối tượng lớp định nghĩa các hàm thành viên `begin` và `end`. Nếu đưa vào
một biểu thức, biểu thức đó chỉ được tính một lần.

Ví dụ:

```cpp
int a[] = {1, 1, 4, 5, 1, 4};
std::vector<int> b{1, 1, 4, 5, 1, 4};
std::map<std::string, int> c{{"114", 114}, {"514", 514}};
for (int i : a) std::cout << i;
for (auto i : b) std::cout << i;
// Kiểu của i ở dòng sau là std::pair<const std::string, int>&
for (auto& i : c) std::cout << i.first << i.second;
for (auto i : {1, 1, 4, 5, 1, 4}) std::cout << i;
```

### Hỗ trợ vòng lặp `for` dựa trên phạm vi cho kiểu tự định nghĩa

Chỉ cần cung cấp các hàm thành viên `begin` và `end`; kiểu trả về cần hỗ trợ so
sánh, tăng và giải tham chiếu (toán tử `*`).

Sau đây là một ví dụ:

```cpp
#include <iostream>

struct C {
  int a[4];

  int* begin() { return a; }

  int* end() { return a + 4; }
};

int main() {
  C c = {1, 9, 2, 6};
  for (auto i : c) std::cout << i << " ";
  std::cout << std::endl;
  // output: 1 9 2 6
  return 0;
}
```

### Câu lệnh khởi tạo (C++20)

Trong C++20, vòng lặp `for` dựa trên phạm vi còn có thể có câu lệnh khởi tạo, ví
dụ dùng để tạo bộ đếm vòng lặp:

```cpp
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {0, 1, 2, 3, 4, 5};

  for (int counter = 0; auto i : v)  // câu lệnh khởi tạo (C++20)
    std::cout << counter++ << ' ' << i << std::endl;
}
```

## Ràng buộc có cấu trúc (C++17)

Ràng buộc có cấu trúc là cú pháp tiện ích do C++17 cung cấp, giúp trích xuất phần
tử con hoặc tham chiếu tới phần tử con gọn hơn, như sau:

```cpp
struct C {
  int x{1}, y{2};
};

int arr[]{4, 5, 6};

auto [c1, c2] = C{};       // c1=1,c2=2; kiểu int
auto& [a1, a2, a3] = arr;  // a1=arr[0],a2=arr[1],a3=arr[2]; kiểu int&
```

Cần lưu ý các điểm sau:

-   Số biến khai báo ở bên trái phải bằng số phần tử con của đối tượng bên phải.
-   Khai báo kiểu cần dùng `auto`.
-   Có thể dùng `&` để lấy tham chiếu.

Khi duyệt bộ chứa `map`, có thể viết như sau:

```cpp
std::map<std::string, int> m = {{"k1", 1}, {"k2", 2}};

// Dùng "auto&" để tránh sao chép phần tử
for (auto& [k, v] : m) {
  // k có kiểu const std::string&, vì khóa vốn được gắn const
  // v có kiểu int&
  std::cout << k << ' ' << v << std::endl;
}
```

## Bộ `std::tuple`

[`std::tuple`](https://en.cppreference.com/w/cpp/utility/tuple) được định nghĩa
trong tệp tiêu đề `<tuple>`, là sự khái quát hóa của `std::pair` và có thể lưu
nhiều giá trị thuộc các kiểu khác nhau. Xét ví dụ sau:

```cpp
#include <iostream>
#include <tuple>
#include <vector>

constexpr auto expr = 4 - 1;  // expr = 3

int main() {
  std::vector<int> vec = {1, 9, 2, 6, 0};
  std::tuple<int, int, std::string, std::vector<int>> tup =
      std::make_tuple(817, 114, "514", vec);

  // Dùng get<> để lấy phần tử con; phần trong <> phải là biểu thức hằng số nguyên
  for (auto i : std::get<expr>(tup)) std::cout << i << " ";
  // Phần tử đầu tiên có chỉ số 0, nên std::get<3> lấy được một std::vector<int>
  return 0;
}
```

Từ C++17 trở đi, có thể dùng ràng buộc có cấu trúc để trích xuất giá trị, như sau:

```cpp
std::vector<int> vec = {1, 9, 2, 6, 0};
std::tuple<int, int, std::string, std::vector<int>> tup =
    std::make_tuple(817, 114, "514", vec);

auto& [a, b, c, d] = tup;  // C++17: ràng buộc có cấu trúc
std::cout << a << ' ' << b << c << std::endl;
std::cout << d.size() << ' ' << d[2] << std::endl;
```

### Hàm thành viên

| Hàm         | Tác dụng                                      |
| ----------- | -------------------------------------------- |
| `operator=` | Gán nội dung của một `tuple` cho một `tuple` khác |
| `swap`      | Hoán đổi nội dung của hai `tuple`            |

Ví dụ:

```cpp
constexpr std::tuple<int, int> tup = {1, 2};
std::tuple<int, int> tupA = {2, 3}, tupB;
tupB = tup;
tupB.swap(tupA);
```

### Hàm không phải thành viên

| Hàm             | Tác dụng                                                     |
| --------------- | ----------------------------------------------------------- |
| `make_tuple`    | Tạo một đối tượng `tuple`, kiểu của nó được xác định theo kiểu của từng đối số |
| `std::get`      | Truy cập phần tử được chỉ định trong `tuple`                |
| `std::tie`      | Gán các giá trị trong tuple vào những biến đã có            |
| `operator==` và các toán tử tương tự | So sánh các giá trị trong `tuple` theo thứ tự từ điển |
| `std::swap`     | Thuật toán `std::swap` đã được chuyên biệt hóa              |

Ví dụ:

```cpp
std::tuple<int, int> tupA = {2, 3}, tupB;
tupB = std::make_tuple(1, 2);
std::swap(tupA, tupB);
std::cout << std::get<1>(tupA) << std::endl;
int x;
std::tie(x, std::ignore) = tupB;
std::cout << x << std::endl;
```

`std::tie` gán các phần tử của tuple cho những biến đã có; có thể dùng
`std::ignore` để bỏ qua phần tử không cần. Ràng buộc có cấu trúc khai báo biến
mới ngay tại chỗ (hỗ trợ ràng buộc theo giá trị hoặc theo tham chiếu), và phải
nhận tất cả phần tử.

<a id="đối-tượng-hàm"></a>

## Đối tượng hàm

Đối tượng có thể được gọi bằng toán tử gọi hàm `operator()` là đối tượng hàm.

Đây không phải một tính năng cú pháp riêng của ngôn ngữ, mà là một
[khái niệm/yêu cầu](https://en.cppreference.com/w/cpp/named_req/FunctionObject)
được dùng rộng rãi trong thư viện chuẩn.

Đối tượng hàm thường được chia thành hai loại:

1.  Con trỏ hàm
2.  Đối tượng lớp đã nạp chồng toán tử `operator()`

[Lambda](./lambda.md) là một đối tượng hàm điển hình thuộc loại thứ hai: nó lưu
nội dung đã bắt giữ (capture) trong các biến thành viên và nạp chồng toán tử gọi
hàm.

## Biểu thức lambda

> Xem thêm trang [Biểu thức lambda](lambda.md).

## std::function

???+ warning "Cân nhắc chi phí hiệu năng"
    `std::function` có thể gây thêm chi phí hiệu năng. Theo thử nghiệm
    [benchmark](./lambda.md#đệ-quy-trong-lambda), nó thường làm hiệu năng giảm từ
    2 đến hơn 3 lần.
    
    Nguyên nhân là nó sử dụng kỹ thuật xóa kiểu (type erasure), thường được cài
    đặt bằng cơ chế hàm ảo; lời gọi hàm ảo sẽ gây thêm
    [chi phí](https://stackoverflow.com/questions/5057382/what-is-the-performance-overhead-of-stdfunction).
    
    Nên cân nhắc dùng [**Biểu thức lambda**](./lambda.md) hoặc
    [**đối tượng hàm**](#đối-tượng-hàm) thay thế.

`std::function` là một bộ bao bọc hàm đa hình tổng quát, được định nghĩa trong
tệp tiêu đề `<functional>`.

Một thể hiện của `std::function` có thể lưu trữ, sao chép và gọi bất kỳ
[**đối tượng có thể gọi**](https://en.cppreference.com/w/cpp/named_req/Callable)
nào, bao gồm [**biểu thức lambda**](./lambda.md), con trỏ hàm thành viên hoặc
[**đối tượng hàm**](#đối-tượng-hàm) khác.

Nếu `std::function` không chứa đối tượng có thể gọi nào (ví dụ được khởi tạo mặc
định), khi gọi nó sẽ ném ngoại lệ
[`std::bad_function_call`](https://en.cppreference.com/w/cpp/utility/functional/bad_function_call).

```cpp
#include <functional>
#include <iostream>

struct Foo {
  Foo(int num) : num_(num) {}

  void print_add(int i) const { std::cout << num_ + i << '\n'; }

  int num_;
};

void print_num(int i) { std::cout << i << '\n'; }

struct PrintNum {
  void operator()(int i) const { std::cout << i << '\n'; }
};

int main() {
  // Lưu hàm tự do
  std::function<void(int)> f_display = print_num;
  f_display(-9);

  // Lưu Lambda
  std::function<void()> f_display_42 = []() { print_num(42); };
  f_display_42();

  // Lưu lời gọi đến hàm thành viên
  std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
  const Foo foo(314159);
  f_add_display(foo, 1);
  f_add_display(314159, 1);

  // Lưu lời gọi đến hàm truy cập của thành viên dữ liệu
  std::function<int(Foo const&)> f_num = &Foo::num_;
  std::cout << "num_: " << f_num(foo) << '\n';

  // Lưu lời gọi đến đối tượng hàm
  std::function<void(int)> f_display_obj = PrintNum();
  f_display_obj(18);
}
```

## Mẫu hàm tham số biến thiên

Trước C++11, cả mẫu lớp và mẫu hàm đều chỉ có thể nhận số lượng tham số mẫu cố
định. C++11 cho phép tham số mẫu có **số lượng bất kỳ, kiểu bất kỳ**.

Phần này chỉ giới thiệu ngắn gọn về mẫu **hàm** tham số biến thiên.

Mẫu hàm `fun` được khai báo trong đoạn mã sau có thể nhận số lượng tùy ý các
tham số mẫu với kiểu bất kỳ.

```cpp
template <typename... Clazz>
void fun(Clazz... paras) {}
```

`paras` là một gói tham số hàm (function parameter pack), nhận 0 hoặc nhiều đối
số hàm. `Clazz` là một gói tham số mẫu (template parameter pack), nhận 0 hoặc
nhiều đối số mẫu (đối số không phải kiểu, kiểu hoặc mẫu); khi được đánh dấu bằng
`typename` thì chỉ nhận kiểu.

Có thể tóm tắt như sau:

-   Gói tham số mẫu thường là một dãy tên kiểu, nhưng cũng có thể chứa hằng số
    thời gian biên dịch hoặc tên mẫu.
-   Gói tham số hàm thường là một dãy tên biến.

Khi đó, có thể gọi hàm `fun` như sau:

```cpp
fun();
fun(1);
fun(1, 2, 3);
fun(1, 0.0, "abc");
```

### Mở rộng gói tham số

#### Cú pháp mở rộng gói tham số

Để mở rộng gói tham số, chỉ cần dùng `...`; các phần tử sẽ tự động
được phân tách bằng dấu phẩy. Ví dụ:

```cpp
template <class A, class... C>
void func(A arg1, C... arg2) {
  // C là gói tham số mẫu
  tuple<A, C...>();  // Mở rộng thành tuple<int, int, double, bool>();

  // arg2 là gói tham số hàm
  func(arg2...);  // Mở rộng thành func( 2, 1.1, true );
}

func(1, 2, 1.1, true);
```

Khi mở rộng gói tham số, cũng có thể kèm theo phép toán cần thiết, ví dụ:

```cpp
template <class A, class... C>
void func(A arg1, C... arg2) {
  func((arg2 + 1)...);
  // Mở rộng thành func( (2+1) , (1.1+1), (2.1f+1) );
}

func(1, 2, 1.1, 2.1f);
```

#### Hàm kết thúc

Hàm ở trên không thể chạy riêng lẻ, vì số lượng tham số liên tục giảm; cuối cùng
lời gọi sẽ không còn tham số và gây lỗi biên dịch.

Cần chỉ định điều kiện kết thúc; có thể cung cấp một hàm thông thường như sau:

```cpp
void func() {}

template <class A, class... C>
void func(A arg1, C... arg2) {
  std::cout << arg1 << std::endl;
  func((arg2 + 1)...);
}

func(1, 2, 1.1, 2.1f);
```

Vì vậy, khi số lượng tham số khác 0 thì mẫu hàm sẽ được gọi; khi không còn tham
số thì hàm thông thường sẽ được gọi, nên chương trình có thể chạy bình thường.

### Biểu thức gấp (fold expression, C++17)

C++17 cung cấp một cú pháp tiện lợi để xử lý **gói tham số hàm**. Cú pháp như sau
(phải bọc bằng dấu ngoặc đơn):

1.  `( pack op ... )`, sẽ trở thành `(E1 op (... op (EN-1 op EN)))`
2.  `( ... op pack )`, sẽ trở thành `(((E1 op E2) op ...) op EN)`
3.  `( pack op ... op init )`, sẽ trở thành `(E1 op (... op (EN−1 op (EN op I))))`
4.  `( init op ... op pack )`, sẽ trở thành `((((I op E1) op E2) op ...) op EN)`

Một ví dụ ngắn:

```cpp
template <class... C>
void func(C... args) {
  (std::cout << ... << args) << std::endl;
  // Cú pháp 4, tương đương với ↓
  // ( ( ( std::cout << 1 ) << 2.1 ) << true ) << std::endl;
  // Kết quả: 12.11  true được in thành 1 do không chỉ định boolalpha

  std::cout << (args && ...) << std::endl;
  // Cú pháp 1, tương đương với ↓
  // std::cout << ( 1 && ( 2.1 && true ) ) ) << std::endl;
  // Kết quả: 1
}

func(1, 2.1, true);
```

### Mẫu hàm rút gọn (C++20)

Từ C++20, có thể dùng `auto ...` làm kiểu tham số để viết mẫu hàm ở dạng rút gọn:

```cpp
void func(auto... args) { (std::cout << ... << args) << std::endl; }
```

Về bản chất, cú pháp này vẫn tạo ra mẫu hàm, tương đương với cách viết sau:

```cpp
template <class... T>
void func(T... args) {
  (std::cout << ... << args) << std::endl;
}
```

## Thư viện ranges (C++20)

> Thư viện ranges là phần mở rộng của bộ lặp và thư viện thuật toán tổng quát,
> giúp kết hợp bộ lặp với thuật toán linh hoạt hơn, đồng thời giảm khả năng mắc
> lỗi.

Phạm vi (`range`) là một dãy có thể duyệt, bao gồm mảng, bộ chứa, khung nhìn
(`view`), v.v.

Khi cần thực hiện các thao tác phức tạp trên bộ chứa hoặc các phạm vi khác,
[thư viện ranges](https://en.cppreference.com/w/cpp/ranges) giúp mã thuật toán
ngắn gọn và mạch lạc hơn.

### Khung nhìn (view)

Khung nhìn (`view`) là một đối tượng nhẹ, cài đặt một số thao tác thông qua cơ
chế đặc thù (như bộ lặp tự định nghĩa), nhờ đó cung cấp nhiều cách duyệt khác
nhau cho phạm vi.

Thư viện ranges cài đặt sẵn một số khung nhìn thường dùng, có thể chia
thành hai loại:

1.  **Bộ sinh phạm vi** (range factory), dùng để xây dựng một số phạm vi đặc
    biệt. Loại bộ sinh này cho phép bỏ qua bước tự xây dựng bộ chứa, giảm chi phí
    và sinh ra một phạm vi ngay tại chỗ.
2.  **Bộ chuyển đổi phạm vi** (range adaptor), cung cấp nhiều cách duyệt đa dạng;
    có thể gọi như hàm hoặc nối bằng toán tử ống dẫn `|` để gọi theo chuỗi.

Với vai trò là
[**đối tượng bao đóng bộ chuyển đổi phạm vi**](https://en.cppreference.com/w/cpp/named_req/RangeAdaptorClosureObject)
(range adaptor closure object), **bộ chuyển đổi phạm vi** cũng là
[**đối tượng hàm**](#đối-tượng-hàm). Chúng nạp chồng `operator|`, nhờ đó có thể
ghép với nhau như toán tử ống dẫn (pipe).

??? note "Toán tử ống dẫn"
    Trong ngữ cảnh này, `|` là toán tử ống dẫn (pipe), không phải toán tử OR theo
    bit. Cách dùng này bắt nguồn từ
    [pipe](https://en.wikipedia.org/wiki/Pipeline_(Unix)) trong Linux.

Trong các thao tác phức tạp, cách viết này vẫn giữ được tính dễ đọc và tuân theo
quy tắc sau:

Nếu A, B, C là các đối tượng bao đóng bộ chuyển đổi phạm vi, R là một phạm vi nào
đó, còn các chữ cái khác là tham số hợp lệ, thì biểu thức

    R | A(a) | B(b) | C(c, d)

tương đương với

    C(B(A(R, a), b), c, d)

Sau đây lấy `ranges::take_view` và `ranges::iota_view` làm ví dụ:

```cpp
#include <iostream>
#include <ranges>

int main() {
  const auto even = [](int i) { return 0 == i % 2; };

  for (int i : std::views::iota(0, 6) | std::views::filter(even))
    std::cout << i << ' ';
}
```

1.  Bộ sinh phạm vi `std::views::iota(0, 6)` sinh ra một phạm vi gồm dãy số
    nguyên từ 0 đến 5.
2.  Bộ chuyển đổi phạm vi `std::views::filter(even)` lọc phạm vi trước đó, sinh
    ra một phạm vi chỉ còn các số chẵn.
3.  Hai thao tác được liên kết bằng toán tử ống dẫn (pipe).

Đoạn mã trên không cần cấp phát thêm vùng nhớ heap để lưu phạm vi sinh ra ở mỗi
bước. Việc sinh và lọc thực tế xảy ra trong quá trình duyệt (cụ thể hơn là khi
xây dựng, tăng và giải tham chiếu bộ lặp nội bộ), nên không tạo thêm chi phí phụ
trội đáng kể (zero overhead).

Đồng thời, khung nhìn thường chỉ tham chiếu đến phạm vi đầu vào bên ngoài. Nếu
phạm vi bên ngoài (chẳng hạn bộ chứa hoặc bộ sinh phạm vi) đã bị hủy, thì việc
duyệt khung nhìn sau đó tương đương với giải tham chiếu con trỏ treo, thuộc về
hành vi không xác định.

Để tránh tình huống trên, cần bảo đảm vòng đời của khung nhìn không vượt quá vòng
đời của mọi phạm vi mà nó sử dụng.

???+ note "Khi phạm vi bị hủy, các phần tử trong khung nhìn đều bị treo"
    ```cpp
    #include <iostream>
    #include <ranges>
    #include <vector>
    
    using namespace std;
    
    int main() {
      auto view = [] {
        vector<int> vec{1, 2, 3, 4, 5};
        return vec | std::views::filter([](int i) { return 0 == i % 2; });
      }();
    
      for (int i : view) cout << i << ' ';  // hành vi không xác định lúc chạy
    
      return 0;
    }
    ```

### Thuật toán có ràng buộc

> Trong C++20, không gian tên `std::ranges` cung cấp phiên bản có ràng buộc của
> hầu hết thuật toán. Có thể dùng cặp bộ lặp-lính canh (iterator-sentinel) hoặc
> một phạm vi đơn làm đối số để chỉ định phạm vi, đồng thời hỗ trợ phép chiếu
> (projection) và đối tượng có thể gọi (callable object) là con trỏ đến thành
> viên. Ngoài ra, kiểu trả về của hầu hết thuật toán cũng được thay đổi để trả về
> các thông tin hữu ích được tính trong quá trình thực thi thuật toán.

Các thuật toán này có thể được hiểu là phiên bản cải tiến của thuật toán thư viện
chuẩn cũ. Chúng đều là đối tượng hàm, cung cấp cách nạp chồng thân thiện hơn và
kiểm tra kiểu tham số đầu vào tốt hơn (dựa trên
[`concept`](https://en.cppreference.com/w/cpp/language/constraints)). Trước tiên,
lấy so sánh giữa `std::sort` và `ranges::sort` làm ví dụ:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec{4, 2, 5, 3, 1};

  sort(vec.begin(), vec.end());  // {1, 2, 3, 4, 5}

  for (const int i : vec) cout << i << ", ";
  cout << '\n';

  ranges::sort(vec, ranges::greater{});  // {5, 4, 3, 2, 1}

  for (const int i : vec) cout << i << ", ";

  return 0;
}
```

`ranges::sort` và `sort` có cùng cách cài đặt thuật toán, nhưng cung cấp cách
nạp chồng dựa trên phạm vi, giúp truyền tham số ngắn gọn hơn. Đa số thuật toán
khác trong không gian tên `std` cũng có phiên bản nạp chồng tương ứng cho phạm
vi nằm trong không gian tên `ranges`.

Dùng các tham số đầu vào dạng phạm vi này, kết hợp với khung nhìn ở phần trước,
giúp mã vẫn dễ đọc khi thực hiện những thao tác phức tạp. Ví dụ:

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>

using namespace std;

int main() {
  const auto& inputs = views::iota(0u, 9u);  // Sinh dãy số nguyên từ 0 đến 8
  const auto& chunks = inputs | views::chunk(3);  // Chia dãy thành các khối, mỗi khối 3 phần tử
  const auto& cartesian_product =
      views::cartesian_product(chunks, chunks);  // Tính tích Descartes của các khối với chính chúng

  for (const auto [l_chunk, r_chunk] : cartesian_product)
    // Tính tổng các số nguyên trong hai khối của tích Descartes
    cout << ranges::fold_left(l_chunk, 0u, plus{}) +
                ranges::fold_left(r_chunk, 0u, plus{})
         << ' ';
}
```

???+ note "Đầu ra:"
    6 15 24 15 24 33 24 33 42

## Tham khảo

1.  [C++ Reference](https://en.cppreference.com/)
