Loại giá trị là một khái niệm quan trọng trong C++. Trong lập trình thi đấu, ta
không phải lúc nào cũng cần gọi tên khái niệm này, nhưng hiểu nó sẽ giúp phát
hiện và tránh những phép sao chép không cần thiết, từ đó cải thiện hiệu năng của
mã.

Khái niệm loại giá trị đã nhiều lần thay đổi từ ngôn ngữ C, qua C++98, C++11 rồi
đến C++17, nên ngày nay nó là một chủ đề tương đối phức tạp.

## Sao chép không cần thiết

Xét quá trình thêm chuỗi vào một vector:

```cpp
int main() {
  std::vector<std::string> vec;
  vec.reserve(3);
  for (int i = 0; i < 3; ++i) {
    std::string str;
    std::cin >> str;
    vec.push_back(str);
  }
  return 0;
}
```

Trong quá trình thêm chuỗi vào `vec`, cả `str` và phần tử mới trong `vec` đều giữ
một bản dữ liệu riêng, làm lượng bộ nhớ sử dụng tăng lên.

Nếu muốn tiết kiệm phần bộ nhớ này, có thể tự mô phỏng một thao tác di chuyển:
định nghĩa cấu trúc `MyString`, bên trong có một con trỏ trỏ tới vùng dữ liệu
chuỗi. Khi đó, ta chỉ chuyển con trỏ sang nơi mới, đồng thời đặt lại con trỏ của
đối tượng gốc để tránh hủy nhầm cùng một vùng nhớ.

```cpp
struct MyString {
  char *beg, *end;
  // ...
};

void move_to(MyString& src, MyString& dst) {
  dst.beg = src.beg;
  dst.end = src.end;
  src.beg = src.end = nullptr;
}
```

Nhu cầu chuyển tài nguyên của đối tượng theo kiểu này rất thường gặp, nhưng lại
khó phối hợp thủ công với các thao tác như khởi tạo và hủy của C++. Vì thế C++11
đã đưa ngữ nghĩa di chuyển vào phần lõi của ngôn ngữ.

## Loại giá trị trong ngôn ngữ C

Trong chuẩn ngôn ngữ C, đối tượng là một khái niệm tổng quát hơn biến; nó chỉ một
vùng dữ liệu trong môi trường thực thi. Các tính chất chính của đối tượng gồm
kích thước, kiểu hiệu dụng và giá trị. Giá trị là ý nghĩa của vùng dữ liệu đó khi
được diễn giải theo kiểu của nó. Ví dụ, tuy kiểu `int` và `float` thường đều
chiếm 4 byte, cùng một vùng nhớ sẽ mang ý nghĩa khác nhau tùy kiểu dùng để diễn
giải.

Trong ngôn ngữ C, mỗi biểu thức đều có kiểu và loại giá trị. Loại giá trị chủ
yếu được chia thành ba loại:

-   Trái trị (lvalue): biểu thức xác định một đối tượng; thường có thể lấy địa
    chỉ của biểu thức đó.
-   Phải trị (rvalue): biểu thức không xác định một đối tượng có thể lấy địa chỉ;
    nó chỉ biểu diễn một giá trị dùng tạm thời.
-   Biểu thức chỉ định hàm: biểu thức có kiểu hàm.

Vì vậy, chỉ các trái trị có thể sửa đổi (trái trị không được định tính `const`
và không phải mảng) mới có thể xuất hiện ở vế trái của biểu thức gán.

Với một toán tử yêu cầu toán hạng của nó là phải trị, mỗi khi một trái trị được
dùng làm toán hạng, biểu thức đó sẽ trải qua phép chuyển đổi chuẩn từ trái trị
sang phải trị, từ mảng sang con trỏ, hoặc từ hàm sang con trỏ để trở thành phải
trị.

Các hiểu lầm thường gặp:

-   Tiếp tục tính toán từ một biểu thức phải trị vẫn có thể cho ra trái trị. Ví
    dụ với `int *a`, biểu thức `a + 1` là phải trị, nhưng `*(a + 1)` lại là trái
    trị.
-   Chỉ biểu thức mới có loại giá trị, biến thì không. Ví dụ với `int *a`, không
    nên nói biến `a` là trái trị; cách nói chính xác hơn là biểu thức `a` là một
    trái trị.

## Loại giá trị trong C++98

C++98 gần với ngôn ngữ C về loại giá trị, nhưng bổ sung một số quy tắc:

-   Biểu thức chỉ định hàm là trái trị, vì có thể lấy địa chỉ.
-   Biểu thức là tên của biến tham chiếu trái trị (`T&`) là trái trị, vì có thể
    lấy địa chỉ của thực thể được tham chiếu.
-   Chỉ `const T&` mới có thể gắn với phải trị.

<span id="loại-bỏ-sao-chép"></span>

### Loại bỏ sao chép

C++ cho phép trình biên dịch thực hiện **loại bỏ sao chép** (copy elision), nhờ
đó giảm việc tạo và hủy đối tượng tạm.

Ví dụ, đoạn mã sau kích hoạt tối ưu hóa giá trị trả về (return value optimization,
RVO) trong cơ chế loại bỏ sao chép. Chương trình chỉ in ra một lần khởi tạo và
một lần khởi tạo sao chép, kể cả khi thao tác khởi tạo và hủy có tác dụng phụ.

```cpp
struct X {
  X() { std::puts("X::X()"); }

  X(const X&) { std::puts("X::X(const X&)"); }

  ~X() { std::puts("X::~X()"); }
};

X get() {
  X x;
  return x;
}

int main() {
  X x = get();
  X y = X(X(X(X(x))));
  return 0;
}
```

## Loại giá trị trong C++11

C++11 đưa vào ngữ nghĩa di chuyển và tham chiếu phải trị (`T&&`), bao gồm hàm
tạo di chuyển và toán tử gán di chuyển. Nhờ đó chương trình có thể tận dụng các
đối tượng tạm.

Hàm `move_to` ở trên có thể được viết lại như sau:

```cpp
struct MyString {
  // ...
  MyString(MyString&& other) {
    beg = other.beg;
    end = other.end;
    other.beg = other.end = nullptr;
  }
};
```

Lúc này cần xét thêm các tính chất của biểu thức:

-   Có danh tính hay không: có xác định một thực thể cụ thể hay không, tức có thể
    phân biệt bằng địa chỉ hay không.
-   Có thể di chuyển từ biểu thức đó hay không: biểu thức có thể dùng làm nguồn
    để di chuyển tài nguyên hay không.

Từ đó có các trường hợp sau:

-   Có danh tính, không thể di chuyển: trái trị (lvalue).
-   Có danh tính, có thể di chuyển: giá trị sắp hết hạn (xvalue).
-   Không có danh tính, có thể di chuyển: giá trị thuần phải (prvalue).
-   Không có danh tính, không thể di chuyển: trường hợp này không xuất hiện như
    một loại giá trị hữu dụng.

Ngoài ra, C++11 còn đưa vào hai loại tổng hợp:

-   Có danh tính: giá trị trái tổng quát (glvalue), tức trái trị và giá trị sắp
    hết hạn.
-   Có thể di chuyển: phải trị (rvalue), tức giá trị thuần phải và giá trị sắp
    hết hạn.

### std::move

Để phối hợp với ngữ nghĩa di chuyển, C++11 còn đưa vào hàm tiện ích `std::move`.
Hàm này ép biểu thức thành xvalue, nhờ đó có thể kích hoạt ngữ nghĩa di chuyển
nếu kiểu dữ liệu hỗ trợ.

```cpp
int main() {
  std::vector<int> a = {1, 2, 3};
  std::cout << "a: " << a.data() << std::endl;
  std::vector<int> b = a;
  std::cout << "b: " << b.data() << std::endl;
  std::vector<int> c = std::move(b);
  std::cout << "c: " << c.data() << std::endl;
}
```

Vì vậy, đổi `push_back(str)` thành `push_back(std::move(str))` sẽ cho phép
`vector` dùng hàm tạo di chuyển thay cho hàm tạo sao chép.

```cpp
int main() {
  std::vector<std::string> vec;
  vec.reserve(3);
  for (int i = 0; i < 3; ++i) {
    std::string str;
    std::cin >> str;
    vec.push_back(std::move(str));
    // Một cách viết gọn khác, cần C++17
    // std::cin >> vec.emplace_back();
  }
  return 0;
}
```

> Do `std::string` có tối ưu hóa chuỗi nhỏ (small string optimization, SSO), các
> chuỗi ngắn được lưu ngay bên trong đối tượng. Cần nhập chuỗi dài hơn mới dễ
> quan sát việc vùng dữ liệu được chuyển giao khi di chuyển.

## Loại giá trị trong C++17

C++17 tiếp tục tinh giản loại giá trị:

-   Trái trị (lvalue): có danh tính, không thể di chuyển.
-   Giá trị sắp hết hạn (xvalue): có danh tính, có thể di chuyển.
-   Giá trị thuần phải (prvalue): phép khởi tạo đối tượng.

C++11 đã mở rộng loại bỏ sao chép sang cả di chuyển; trước C++17, đoạn mã dưới
đây có thể không tạo thao tác di chuyển nếu trình biên dịch áp dụng RVO.

C++17 yêu cầu giá trị thuần phải không nhất thiết phải được vật chất hóa thành
một đối tượng tạm riêng, mà có thể được khởi tạo thẳng vào vùng lưu trữ của đích
cuối cùng. Trước khi khởi tạo, đối tượng tạm riêng đó còn chưa tồn tại. Vì vậy
trong C++17, không còn bước tạo rồi trả về một đối tượng tạm riêng, và trường hợp
này cũng không cần phụ thuộc vào RVO. Cụ thể, URVO (RVO không tên, unnamed RVO)
là bắt buộc, còn NRVO (RVO có tên, named RVO) thì vẫn không bắt buộc.

```cpp
std::string urvo() { return std::string("123"); }

std::string nrvo() {
  std::string s;
  s = "123";
  std::cout << s;
  return s;
}

int main() {
  std::string s1 = urvo();  // Khởi tạo ngay tại đích
  // Không nhất thiết khởi tạo ngay tại đích, phụ thuộc vào tối ưu hóa
  std::string s2 = nrvo();
}
```

Đồng thời, C++17 đưa vào cơ chế vật chất hóa đối tượng tạm: khi cần truy cập thành
viên dữ liệu, gọi hàm thành viên, hoặc gặp tình huống khác cần một giá trị trái
tổng quát (glvalue), giá trị thuần phải có thể được chuyển ngầm định thành giá
trị sắp hết hạn đã được vật chất hóa.

<span id="các-hiểu-lầm-thường-gặp"></span>

### Các hiểu lầm thường gặp

Trong ví dụ sau đây:

-   Trả về `std::move(s)` trong `f1` là thừa; nó không cải thiện hiệu năng, ngược
    lại còn cản trở trình biên dịch thực hiện tối ưu NRVO.
-   Trả về `std::move(s)` trong `f2` là nguy hiểm; hàm trả về một tham chiếu phải
    trị gắn với biến cục bộ `s` đã bị hủy, gây ra vấn đề tham chiếu treo.

```cpp
std::string f1() {
  std::string s = "123";
  // Tương đương với return std::string(std::move(s))
  return std::move(s);
}

std::string&& f2() {
  std::string s = "123";
  return std::move(s);
}
```

## Tài liệu tham khảo và đọc thêm

1.  [Value categories](https://en.cppreference.com/w/cpp/language/value_category)
2.  [Wording for guaranteed copy elision through simplified value categories](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0135r1.html)
3.  [Loại giá trị trong C++](https://paul.pub/cpp-value-category/)
4.  [Tham chiếu phải trị, di chuyển và hệ thống loại giá trị của C++](https://zclll.com/index.php/cpp/value_category.html)
5.  [Copy elision](https://en.cppreference.com/w/cpp/language/copy_elision)
