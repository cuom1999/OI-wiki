> Khai báo một thực thể có kiểu tham chiếu, tức là bí danh của một đối tượng hoặc
> hàm đã tồn tại.

Tham chiếu là bí danh được ràng buộc với một đối tượng hoặc hàm hợp lệ. Khi truyền
tham chiếu vào hàm, hàm thao tác trên chính thực thể được tham chiếu mà không cần
sao chép đối tượng.

Tham chiếu không phải là đối tượng, nên không thể tạo mảng chứa tham chiếu, không
thể lấy con trỏ tới tham chiếu, và cũng không thể khai báo tham chiếu tới tham
chiếu theo cách thông thường.

??? note "Kiểu tham chiếu không thuộc kiểu đối tượng"
    Nếu muốn một đối tượng có hành vi giống tham chiếu nhưng vẫn thực hiện được
    các thao tác thông thường như sao chép, gán, hoặc làm phần tử của bộ chứa,
    cần dùng
    [`reference_wrapper`](https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper).
    Kiểu này thường được cài đặt bằng cách duy trì một con trỏ không rỗng.

Tham chiếu chủ yếu được chia thành hai loại: tham chiếu trái trị và tham chiếu
phải trị.

??? note "Trái trị và phải trị"
    Phần giải thích về trái trị và phải trị nằm ở trang
    [loại giá trị](./value-category.md).

## Tham chiếu trái trị T&

Loại tham chiếu thường gặp nhất là tham chiếu trái trị, tức tham chiếu được ràng
buộc với trái trị. Ngoài ra, tham chiếu trái trị tới `const` có thể ràng buộc với
phải trị. Dưới đây là một đoạn mã ví dụ từ
[tài liệu tham khảo](https://en.cppreference.com/w/cpp/language/reference).

```cpp
#include <iostream>
#include <string>

int main() {
  std::string s = "Ex";
  std::string& r1 = s;
  const std::string& r2 = s;

  r1 += "ample";  // Sửa r1, tức là sửa s
  // r2 += "!"; // Lỗi: không thể sửa thông qua tham chiếu tới đối tượng const
  std::cout << r2 << '\n';  // In r2, truy cập s, xuất ra "Example"
}
```

Tham chiếu trái trị thường được dùng làm tham số hàm để tránh các phép sao chép
không cần thiết.

```cpp
#include <iostream>
#include <string>

// s trong tham số là tham chiếu, nên khi gọi hàm sẽ không xảy ra sao chép
char& char_number(std::string& s, std::size_t n) {
  s += s;  // 's' và 'str' trong main()
           // là cùng một đối tượng; trái trị cũng có thể đặt ở vế phải dấu bằng
  return s.at(n);  // string::at() trả về tham chiếu tới char
}

int main() {
  std::string str = "Test";
  char_number(str, 1) = 'a';  // Giá trị hàm trả về là trái trị, nên có thể được gán
  std::cout << str << '\n';   // xuất ra "TastTest"
}
```

## Tham chiếu phải trị T&& (C++11)

Tham chiếu phải trị là tham chiếu được ràng buộc với phải trị, thường dùng khi di
chuyển đối tượng, và cũng có thể dùng để **kéo dài thời gian sống của đối tượng
tạm**.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1 = "Test";
  // string&& r1 = s1; // Lỗi: không thể gắn với trái trị, cần std::move hoặc static_cast

  const string& r2 = s1 + s1;  // Hợp lệ: tham chiếu trái trị tới const kéo dài thời gian sống
  // r2 += "Test"; // Lỗi: không thể sửa thông qua tham chiếu tới const
  cout << r2 << '\n';

  string&& r3 = s1 + s1;  // Hợp lệ: tham chiếu phải trị kéo dài thời gian sống
  r3 += "Test";
  cout << r3 << '\n';

  const string& r4 = r3;  // Bản thân biểu thức r3 là trái trị, nên có thể gắn với const string&
  cout << r4 << '\n';

  string& r5 = r3;  // Bản thân biểu thức r3 là trái trị, nên có thể gắn với string&
  cout << r5 << '\n';
}
```

## Tham chiếu treo

Khi đối tượng được tham chiếu đã bị hủy, tham chiếu đó trở thành tham chiếu treo.
Truy cập tham chiếu treo là hành vi không xác định và có thể khiến chương trình
gặp lỗi khi chạy.

Sau đây là các ví dụ thường gặp về tham chiếu treo:

-   Tham chiếu tới biến cục bộ

    ```cpp
    #include <iostream>

    int& foo() {
      int a = 1;
      return a;
    }

    int main() {
      int& b = foo();
      std::cout << b << std::endl;  // Hành vi không xác định
    }
    ```

-   Tham chiếu treo do giải phóng bộ nhớ

    ```cpp
    #include <iostream>

    int main() {
      int* ptr = new int(10);
      int& ref = *ptr;
      delete ptr;

      std::cout << ref << std::endl;  // Hành vi không xác định
    }
    ```

-   Tham chiếu treo do cấp phát lại bộ nhớ

    ```cpp
    #include <iostream>

    int main() {
      std::string str = "hello";

      const char& ref = str.front();

      str.append("world");
      // Có thể cấp phát lại bộ nhớ, khiến ký tự mà ref tham chiếu bị giải phóng

      std::cout << ref << std::endl;  // Hành vi không xác định
    }
    ```

    Tương tự, thao tác chèn vào các bộ chứa như `std::vector` hoặc
    `std::unordered_map` cũng có thể dẫn tới cấp phát lại bộ nhớ.

Khi sử dụng tham chiếu, cần luôn lưu ý tới thời gian sống của đối tượng được tham
chiếu để tránh tạo ra tham chiếu treo.

Thông thường, công cụ phân tích tĩnh và thói quen viết mã cẩn thận có thể giúp
hạn chế vấn đề tham chiếu treo.

## Kỹ thuật cải thiện hiệu năng liên quan đến tham chiếu

### Loại bỏ chi phí sao chép khi truyền đối tượng tốn kém vào hàm

Các **đối tượng tốn kém khi sao chép** thường gặp gồm:

-   Bộ chứa như `std::vector`, `std::array`, `std::map`.
-   `std::string`
-   Các kiểu tự định nghĩa hoặc kế thừa những hàm đặc biệt như hàm tạo sao chép,
    hàm tạo di chuyển

Trong khi đó, dùng tham chiếu cho **đối tượng nhẹ** không nhất thiết mang lại lợi
ích rõ ràng; kích thước chiếm dụng của tham chiếu khi làm tham số thậm chí có thể
lớn hơn chính kiểu đó.

Điều này có thể tạo thêm một ít chi phí hiệu năng, đồng thời cản trở trình biên
dịch tối ưu.

Những kiểu sau thuộc nhóm **đối tượng nhẹ**:

-   Kiểu cơ bản như `int`, `float`.
-   [Kiểu kết tập (aggregate)](https://en.cppreference.com/w/cpp/language/aggregate_initialization) nhỏ
-   Bộ lặp của bộ chứa trong thư viện chuẩn

### Chuyển biểu thức thành xvalue

Dùng `std::move` để [chuyển](./value-category.md#stdmove) một biểu thức thành
xvalue, từ đó cho phép kích hoạt ngữ nghĩa di chuyển nếu kiểu dữ liệu hỗ trợ. Cách
này thường xuất hiện giữa các biến cục bộ, hoặc giữa tham số và biến cục bộ:

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string world(string str) {
  str += " world!";
  return str;  // tham số hàm có thể được di chuyển khi trả về
}

int main() {
  // 1
  cout << world("hello") << '\n';

  vector<string> vec0;

  // 2
  {
    string&& size = to_string(vec0.size());

    size += ", " + to_string(size.size());

    vec0.emplace_back(std::move(size));
  }

  cout << vec0.front();
}
```

Tuy nhiên, không phải lúc nào cũng cần dùng `std::move`, chẳng hạn khi có
[tối ưu giá trị trả về của hàm](./value-category.md#các-hiểu-lầm-thường-gặp).
Trong ví dụ `world` ở trên, không cần viết `return std::move(str);`.

### Tham chiếu kéo dài thời gian sống của đối tượng tạm

Về mặt ngữ nghĩa, đối tượng tạm có thể kéo theo các phép sao chép hoặc di chuyển.
Dù trong đa số trường hợp trình biên dịch có thể tối ưu bằng
[loại bỏ sao chép](./value-category.md#loại-bỏ-sao-chép), việc ràng buộc đối tượng
tạm với tham chiếu phù hợp có thể kéo dài thời gian sống của nó, tránh dùng một
đối tượng đã bị hủy.

## Nội dung tham khảo

1.  [Tài liệu ngôn ngữ C++ - khai báo tham chiếu](https://en.cppreference.com/w/cpp/language/reference)
2.  [Tài liệu ngôn ngữ C++ - loại giá trị](https://en.cppreference.com/w/cpp/language/value_category)
3.  [Does const ref lvalue to non-const func return value specifically reduce copies?][so-38909228]

[so-38909228]: https://stackoverflow.com/questions/38909228/does-const-ref-lvalue-to-non-const-func-return-value-specifically-reduce-copies
