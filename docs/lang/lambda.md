**Lưu ý**: Xét đến nhu cầu thực tế của lập trình thi đấu, bài viết này không
trình bày đầy đủ toàn bộ cú pháp lambda, mà chỉ trình bày những phần thường dùng
trong lập trình thi đấu.

Cú pháp trong bài viết này tham chiếu chuẩn **C++11**. Cú pháp của các chuẩn mới
hơn sẽ được nhắc đến tùy trường hợp và được đánh dấu riêng.

<a id="biểu-thức-lambda"></a>

## Biểu thức lambda

Biểu thức lambda được đặt tên theo phép tính $\lambda$ trong toán học, tương ứng
với phép trừu tượng lambda trong đó. Khi biên dịch, dựa trên cú pháp, trình biên
dịch sẽ sinh ra một [**đối tượng hàm**](./new.md#đối-tượng-hàm) ẩn danh: các
biến được bắt giữ trở thành thành viên, còn danh sách tham số và thân hàm được
dùng để cài đặt toán tử gọi hàm `operator()`.

??? note "Đối tượng hàm"
    Đối tượng hàm là một đối tượng lớp, thường được cài đặt bằng cách nạp chồng
    `operator()`, nên có thể được gọi như một hàm. So với hàm thông thường, đối
    tượng hàm có nhiều ưu điểm, chẳng hạn có thể lưu trạng thái và có thể truyền
    làm tham số cho các hàm khác.

Một dạng cú pháp của lambda là:

```text
[capture] (parameters) mutable -> return-type {statement}
```

Kiểu của biểu thức lambda là một kiểu lớp ẩn danh; nếu khai triển gần đúng thì có
dạng như sau:

<!-- scripts.linter.preprocess.fix_details off -->

```text
class Lambda_1 {
 private:
  Lambda_1() : capture-list(init-value) { }

 public:
  return-type operator()(parameters) const { statement }

 private:
  mutable capture-list
};
```

<!-- scripts.linter.preprocess.fix_details on -->

Biểu thức lambda có danh sách bắt giữ rỗng có thể được chuyển đổi ngầm định thành
con trỏ hàm, ví dụ:

```cpp
void (*f)(int, int) = [](int, int) -> void {};
```

Sau đây là từng phần trong cú pháp.

<a id="thân-hàm"></a>

### Thân hàm

Thân hàm của biểu thức lambda tương tự thân hàm thông thường. Ngoài tham số, biến
toàn cục và các tên nhìn thấy được trong phạm vi, nó còn có thể truy cập các biến
được [bắt giữ](#capture-mệnh-đề-bắt-giữ).

<a id="capture-mệnh-đề-bắt-giữ"></a>

### Mệnh đề bắt giữ

Biểu thức lambda bắt đầu bằng mệnh đề bắt giữ, dùng để chỉ định những biến nào từ
phạm vi bên ngoài được đưa vào lambda. Danh sách bắt giữ có thể rỗng, hoặc chỉ
định cách bắt giữ: biến có tiền tố `&` được truy cập thông qua
[tham chiếu](./reference.md), còn biến không có tiền tố này được truy cập theo
giá trị.

Có thể dùng chế độ bắt giữ mặc định để bắt giữ tất cả các biến được nhắc đến
trong lambda: `&` nghĩa là mọi biến được bắt giữ sẽ được truy cập thông qua tham
chiếu, còn `=` nghĩa là mọi biến được bắt giữ sẽ được truy cập theo giá trị.

Sau chế độ bắt giữ mặc định, vẫn có thể chỉ định **tường minh** chế độ bắt giữ
cho một biến cụ thể.

Nếu cần truy cập biến ngoài `a` bằng tham chiếu và truy cập biến ngoài `b` theo
giá trị, các mệnh đề bắt giữ sau đây đều làm được:

-   `[&a, b]`
-   `[b, &a]`
-   `[&, b]`
-   `[b, &]`
-   `[=, &a]`

Đồng thời, danh sách bắt giữ cũng có thể được dùng để khai báo biến mới; kiểu của
biến được suy luận từ bộ khởi tạo, tương tự khai báo biến bằng `auto`.

Sau đây là một số ví dụ thường gặp:

```cpp
int a = 0;
auto f0 = []() { return a * 9; };   // Lỗi, không thể truy cập 'a'
auto f1 = [a]() { return a * 9; };  // Hợp lệ, 'a' được bắt giữ theo giá trị
auto f2 = [&a]() { return a++; };   // Hợp lệ, 'a' được bắt giữ bằng tham chiếu
auto f3 = [v = a + 1]() {
  return v + 1;
};  // Hợp lệ, dùng bộ khởi tạo để khai báo biến v, có cùng kiểu với a

// Lưu ý: khi bắt giữ bằng tham chiếu, cần bảo đảm a chưa bị hủy lúc gọi
auto b = f2();  // f2 lấy giá trị của a từ danh sách bắt giữ, không cần truyền a qua tham số
```

<a id="generalized-capture-bắt-giữ-có-khởi-tạo-c14"></a>

#### Bắt giữ tổng quát, bắt giữ có khởi tạo (C++14)

Từ C++14 trở đi, mệnh đề bắt giữ không chỉ có thể bắt giữ biến bên ngoài, mà còn
có thể khai báo biến mới và khởi tạo biến đó, ví dụ:

```cpp
auto f1 = [val = 520]() {
  return val;
};  // Hợp lệ, định nghĩa val có kiểu int, giá trị ban đầu là 520, kiểu trả về là int

auto f2 = [val = 520LL]() {
  return val;
};  // Hợp lệ, định nghĩa val có kiểu long long, giá trị ban đầu là 520, kiểu trả về là long long

auto f3 = [val = "520"]() {
  return val;
};  // Hợp lệ, định nghĩa val có kiểu const char*, giá trị ban đầu là "520", kiểu trả về là const char*

auto f4 = [val = "520"s]() {
  return val;
};  // Hợp lệ, từ C++14 trở đi, cần using namespace std; hoặc using namespace std::literals;
    // định nghĩa val có kiểu std::string, giá trị ban đầu là std::string("520"),
    // kiểu trả về là std::string

auto f5 = [val = std::string("520")]() {
  return val;
};  // Hợp lệ, định nghĩa val có kiểu std::string, giá trị ban đầu là std::string("520"),
    // kiểu trả về là std::string

auto f6 = [val = std::vector<int>(3, 6)]() {
  return val;
};  // Hợp lệ, định nghĩa val có kiểu std::vector<int>, kích thước là 3,
    // các phần tử được gán giá trị 6, kiểu trả về là std::vector<int>

auto f7 = [val = 520]() -> int {
  return val;
};  // Hợp lệ, định nghĩa val có kiểu int, giá trị ban đầu là 520, kiểu trả về là int

auto f8 = [val = 520]() -> long long {
  return val;
};  // Hợp lệ, định nghĩa val có kiểu int, giá trị ban đầu là 520, kiểu trả về là long long
```

Khi định nghĩa biến mới, không được bỏ qua giá trị khởi tạo. Kiểu của biến do
giá trị khởi tạo quyết định, tương đương với:

```text
auto val = init-value;
```

Sau đây là cách viết sai:

```cpp
auto f = [val]() { return val; };  // Lỗi: 'val' chưa được khai báo trong phạm vi này,
                                   // định danh "val" chưa được định nghĩa
```

Giá trị khởi tạo cũng có thể là biến bên ngoài, ví dụ:

```cpp
int value = 520;
auto f = [val = value]() { return val; };
std::cout << f();  // Kết quả: 520
```

`val` cũng có thể là một tham chiếu đến biến bên ngoài. Bằng cách này, có thể đặt
bí danh cho biến ngoài được bắt giữ bằng tham chiếu, ví dụ:

```cpp
int value = 520;

auto f = [&val = value]() {
  return val;
};  // Hợp lệ, định nghĩa val có kiểu int&, kiểu trả về là int, tương đương int& val = value;

std::cout << f() << '\n';  // Kết quả: 520

value = 1314;

std::cout << f() << '\n';  // Kết quả: 1314
```

Có thể vừa bắt giữ biến bên ngoài vừa định nghĩa biến mới.

Nếu muốn sửa đổi biến mới được định nghĩa trong mệnh đề bắt giữ ở bên trong biểu
thức lambda, cần dùng từ khóa `mutable`; nếu biến đó là tham chiếu thì không cần,
ví dụ:

```cpp
int value = 520;

{
  auto f = [val = value]() mutable -> int {
    return val = 1314;
  };  // cần mutable
  auto val_f = f();
  std::cout << value << ' ' << val_f << std::endl;  // Kết quả: 520 1314
}

{
  auto f = [&val = value]() -> int { return val = 1314; };  // không cần mutable
  auto val_f = f();
  std::cout << value << ' ' << val_f << std::endl;  // Kết quả: 1314 1314
}
```

Xem thêm [đặc tả mutable](#mutable-đặc-tả-có-thể-thay-đổi).

Vòng đời của biến được định nghĩa trong mệnh đề bắt giữ đi theo đối tượng lambda;
trong các ví dụ trên là biến $f$. Lý do là lambda được biểu diễn bằng một kiểu
lớp, và mọi nội dung trong mệnh đề bắt giữ đều là biến thành viên `private` của
lớp này, ví dụ:

```cpp
int main() {
  auto f = [val = 0]() mutable -> int { return ++val; };  // val được khởi tạo và cấu tạo

  std::cout << f() << '\n';  // Kết quả: 1
  std::cout << f() << '\n';  // Kết quả: 2
  std::cout << f() << '\n';  // Kết quả: 3
}  // val bị hủy theo f
```

<a id="danh-sách-tham-số"></a>

### Danh sách tham số

Trong phần lớn trường hợp, danh sách tham số của lambda tương tự danh sách tham
số của hàm, ví dụ:

```cpp
int x[] = {5, 1, 7, 6, 1, 4, 2};
std::sort(x, x + 7, [](int a, int b) { return (a > b); });
for (auto i : x) std::cout << i << " ";
```

Đoạn này sẽ in ra kết quả sau khi mảng `x` được sắp xếp theo thứ tự giảm dần.

Vì **danh sách tham số** là tùy chọn, nếu không truyền tham số cho lambda, khai
báo của nó không chứa [mutable](#mutable-đặc-tả-có-thể-thay-đổi), và không có
kiểu trả về hậu tố, thì có thể bỏ qua cặp ngoặc rỗng.

??? note "Tham số được khai báo bằng `auto`"
    Từ **C++14** trở đi, nếu tham số dùng `auto` để khai báo kiểu, một
    [biểu thức lambda tổng quát](#lambda-tổng-quát-c14) sẽ được tạo.

<a id="tham-số-đối-tượng-tường-minh-c23"></a>

#### Tham số đối tượng tường minh (C++23)

Từ **C++23** trở đi, [tham số đối tượng tường minh](https://en.cppreference.com/w/cpp/language/lambda)
có thể được dùng trong danh sách tham số của lambda.

```cpp
auto nth_fibonacci = [](this auto self, unsigned n) -> unsigned {
  return n < 2 ? n : self(n - 1) + self(n - 2);
};

cout << nth_fibonacci(10u);
```

<a id="mutable-đặc-tả-có-thể-thay-đổi"></a>

### Đặc tả `mutable`

Đặc tả `mutable` cho phép thân hàm sửa đổi các biến được bắt giữ theo giá trị.

```cpp
int a = 0;
auto by_value = [a]() mutable { ++a; };
auto by_ref = [&a] { ++a; };

by_value();
by_ref();
```

Sau khi thực thi `by_value()`, thành viên bắt giữ `a` của `by_value` có giá trị
1, nhưng biến `a` bên ngoài vẫn là 0.
Còn sau khi thực thi `by_ref()`, giá trị của `a` bên ngoài trở thành 1.

<a id="kiểu-trả-về"></a>

### Kiểu trả về

Dùng để chỉ định kiểu trả về của biểu thức lambda. Nếu bỏ qua, kiểu trả về sẽ
được suy luận tự động, tương tự hàm có kiểu trả về được khai báo bằng `auto`.

Nếu có nhiều câu lệnh `return` và các kiểu suy luận không nhất quán, sẽ phát sinh
lỗi biên dịch.

```cpp
auto lam = [](int a, int b) -> int { return 0; };

auto x1 = [](int i) { return i; };

auto x2 = [](bool condition) {
  if (condition) return 1;
  return 1.0;
};  // Lỗi, các kiểu suy luận không nhất quán
```

<a id="lambda-tổng-quát-c14"></a>

### Lambda tổng quát (C++14)

Dùng `auto` làm kiểu tham số có thể tạo lambda tổng quát.

```cpp
auto add = [](auto a, auto b) { return a + b; };
```

Trong [cpp insights](https://cppinsights.io), có thể quan sát định nghĩa lớp
lambda do trình biên dịch sinh ra:

```cpp
class add_lambda {
 public:
  template <class T, class U>
  auto operator()(T a, U b) const {
    return a + b;
  }
};

add_lambda add{};
```

Cả hai tham số của `add` đều được khai báo bằng `auto`, tương ứng với hai tham số
mẫu `T` và `U` của mẫu hàm `operator()` trong lớp `add_lambda`.

<a id="đệ-quy-trong-lambda"></a>

### Đệ quy trong lambda

Trước hết, xét một ví dụ biên dịch thất bại:

```cpp
int n = 10;

auto dfs = [&](int i) -> void {
  if (i == n)
    return;
  else
    dfs(i + 1);  // Lỗi: biến được khai báo với bộ chỉ định kiểu auto
                 // không thể xuất hiện trong chính bộ khởi tạo của nó
};
```

Đoạn mã này thử bắt giữ $dfs$ trong danh sách bắt giữ, nhưng có một vấn đề: kiểu
của $dfs$ là `auto`, nên phải chờ suy luận xong kiểu của vế phải dấu bằng mới xác
định được kiểu của $dfs$. Trong khi đó, để lambda bắt giữ $dfs$, trình biên dịch
lại cần biết kiểu của $dfs$ trước để tạo biến tham chiếu tương ứng. Kết quả là
hai bước này phụ thuộc lẫn nhau.

Có một số cách giải quyết vấn đề này:

1.  Chỉ định tường minh kiểu của $dfs$, có thể dùng `std::function` để thay thế.

    ???+ example "Sửa đoạn mã trên thành:"
        ```cpp
        int n = 10;
        
        std::function<void(int)> dfs = [&](int i) -> void {
          if (i == n)
            return;
          else
            dfs(i + 1);  // Hợp lệ
        };
        
        dfs(1);
        ```

    ??? warning "Không khuyến nghị dùng [`std::function`](./new.md#stdfunction) để cài đặt đệ quy"
        Kỹ thuật xóa kiểu của `std::function` thường cần cấp phát thêm bộ nhớ.
        Đồng thời, lời gọi gián tiếp làm tăng chi phí định địa chỉ, khiến hiệu
        năng tiếp tục giảm.
        
        Trong bài [đo kiểm](https://quick-bench.com/q/U5qf_dHHKsSyVU83jmt0p_U541c),
        với trình biên dịch Clang 17 và libc++ làm thư viện chuẩn, cách cài đặt
        bằng `std::function` chậm hơn đệ quy bằng lambda khoảng 2.5 lần.
        
        ??? note "Mã kiểm thử"
            ```cpp
            #include <algorithm>
            #include <functional>
            #include <numeric>
            #include <random>
            
            using namespace std;
            
            const auto& nums = [] {
              random_device rd;
              mt19937 gen{rd()};
              array<unsigned, 32> arr{};
            
              std::iota(arr.begin(), arr.end(), 0u);
              ranges::shuffle(arr, gen);
            
              return arr;
            }();
            
            static void std_function_fib(benchmark::State& state) {
              std::function<int(int)> fib;
            
              fib = [&](int n) { return n <= 2 ? 1 : fib(n - 1) + fib(n - 2); };
            
              unsigned i = 0;
            
              for (auto _ : state) {
                auto res = fib(nums[i]);
                benchmark::DoNotOptimize(res);
            
                ++i;
            
                if (i == nums.size()) i = 0;
              }
            }
            
            BENCHMARK(std_function_fib);
            
            static void template_lambda_fib(benchmark::State& state) {
              auto n_fibonacci = [](const auto& self, int n) -> int {
                return n <= 2 ? 1 : self(self, n - 1) + self(self, n - 2);
              };
            
              unsigned i = 0;
            
              for (auto _ : state) {
                auto res = n_fibonacci(n_fibonacci, nums[i]);
                benchmark::DoNotOptimize(res);
            
                ++i;
            
                if (i == nums.size()) i = 0;
              }
            }
            
            BENCHMARK(template_lambda_fib);
            ```
2.  Không lấy $dfs$ bằng cách bắt giữ, mà truyền nó qua tham số hàm.

    ???+ example "Sửa đoạn mã trên thành:"
        ```cpp
        int n = 10;
        
        // Nếu danh sách tham số có tham số kiểu auto, thì operator()
        // trong lớp lambda này sẽ được định nghĩa là mẫu hàm;
        // mẫu hàm có thể được hiện thực hóa sau, khi được gọi
        auto dfs = [&](auto& self,
                       int i) -> void  // [&] chỉ bắt giữ các biến được dùng, nên sẽ không bắt giữ auto dfs
        {
          if (i == n)
            return;
          else
            self(self, i + 1);  // Hợp lệ
        };
        
        dfs(dfs, 1);
        ```

    ???+ note "Khác biệt giữa `auto self`, `auto& self` và `auto&& self`:"
        Về lý thuyết, `auto& self` và `auto&& self` đều chỉ truyền một tham chiếu,
        thường có kích thước bằng con trỏ, nên không tạo thêm bản sao của đối
        tượng lambda. Chi tiết vẫn phụ thuộc vào cách trình biên dịch cài đặt
        lambda và các tối ưu tương ứng.

        Với `auto self`, lời gọi sẽ tạo bản sao của đối tượng lambda. Kích thước
        bản sao phụ thuộc vào các phần tử trong danh sách bắt giữ, vì chúng đều là
        biến thành viên riêng của lớp lambda này.
3.  Có thể khai triển thủ công lớp lambda, hoặc dùng cách viết tương tự; nhờ đó
    có thể khai báo kiểu của $dfs$.

    ???+ example "Sửa đoạn mã trên thành:"
        ```cpp
        int n = 10;
        
        class Lambda_1 {
         public:
          auto operator()(int i) const -> void {
            if (i == n)
              return;
            else
              (*this)(i + 1);  // Hợp lệ
          }
        
          explicit Lambda_1(int& __n) : n(__n) {}
        
         private:
          int& n;
        } dfs(n);
        
        dfs(1);
        ```
4.  Nếu lambda không bắt giữ bất kỳ biến nào, cũng có thể tận dụng con trỏ hàm.

    Nếu lambda không bắt giữ bất kỳ biến nào, nó có thể được chuyển đổi ngầm định
    thành con trỏ hàm. Khi đó, có thể khai báo lambda là `static`, đồng thời khai
    báo kiểu con trỏ hàm là `static`. Nhờ vậy, lambda truy cập được con trỏ hàm mà
    không cần bắt giữ biến nào, từ đó thực hiện được đệ quy.

    ???+ example "Ví dụ"
        ```cpp
        static unsigned (*fptr)(unsigned);
        
        static const auto lambda = [](const unsigned a) {
          return a < 2 ? a : (*fptr)(a - 2) + (*fptr)(a - 1);
        };
        
        static auto init = [] {
          fptr = +lambda;
          // Or
          // fptr = static_cast<unsigned (*)(unsigned)>(lambda);
          return 0;
        }();
        
        cout << lambda(10);
        ```

<a id="ứng-dụng-của-biểu-thức-lambda"></a>

### Ứng dụng của biểu thức lambda

<a id="làm-vị-từ-cho-thuật-toán-thư-viện-chuẩn"></a>

#### Làm vị từ cho thuật toán thư viện chuẩn

Sắp xếp theo thứ tự giảm dần:

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
```

Dùng [std::find\_if](https://en.cppreference.com/w/cpp/algorithm/find) để tìm
phần tử đầu tiên lớn hơn 3:

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
auto it = std::find_if(v.begin(), v.end(), [](int a) { return a > 3; });
```

<a id="kiểm-soát-vòng-đời-của-biến-trung-gian"></a>

#### Kiểm soát vòng đời của biến trung gian

Trong lập trình thi đấu, sẽ gặp những tình huống như sau: việc khởi tạo một biến
cần dùng các biến đã khai báo trước đó, và quá trình khởi tạo lại sinh ra các
biến trung gian chiếm nhiều bộ nhớ.

Cần hủy các biến trung gian này càng sớm càng tốt để giảm mức tiêu thụ bộ nhớ.
Lúc này, có thể dùng lambda để kiểm soát vòng đời của các biến trung gian.

```cpp
void solution(const vector<int>& input) {
  int b = [&] {
    vector<int> large_objects(input.size());
    int c = 0;

    for (int i = 0; i < large_objects.size(); ++i)
      large_objects[i] = i + input[i];

    for (int i = 0; i < input.size(); ++i) c += large_objects[input[i]];

    return c;
  }();

  // ...
}
```

So với phạm vi khối lệnh, lambda có giá trị trả về nên mã ngắn gọn hơn. So với
hàm riêng, lambda không cần thêm tên hàm và không phải khai báo lại các tham số đã
được bắt giữ, nên mã tập trung hơn vào logic đang viết.

<a id="tài-liệu-tham-khảo"></a>

## Tài liệu tham khảo

-   [cppreference-lambda](https://en.cppreference.com/w/cpp/language/lambda)
-   [Stackoverflow: Overhead with std::function](https://stackoverflow.com/a/33881130/11120338)
