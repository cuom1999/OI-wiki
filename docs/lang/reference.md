> Khai báo một biến có tên là tham chiếu, tức là bí danh của một đối tượng hoặc hàm đã tồn tại.

Có thể xem tham chiếu như một con trỏ không rỗng được C++ đóng gói; nó có thể dùng để truyền đối tượng mà nó trỏ tới, và khi khai báo bắt buộc phải gắn với một đối tượng.

Tham chiếu không phải là đối tượng, nên không tồn tại mảng các tham chiếu, không thể lấy con trỏ tới tham chiếu, và cũng không tồn tại tham chiếu tới tham chiếu.

??? note "Kiểu tham chiếu không thuộc kiểu đối tượng"
    Nếu muốn tham chiếu có thể thực hiện các thao tác thông thường như sao chép, gán, chẳng hạn làm phần tử của container, cần dùng [`reference_wrapper`](https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper). Kiểu này thường được hiện thực bằng cách duy trì một con trỏ không rỗng.

Tham chiếu chủ yếu được chia thành hai loại: tham chiếu trái trị và tham chiếu phải trị.

??? note "Trái trị và phải trị"
    Phần giải thích về trái trị và phải trị nằm ở trang [loại giá trị](./value-category.md).

## Tham chiếu trái trị T&

Loại tham chiếu thường gặp là tham chiếu trái trị, tức là tham chiếu gắn với trái trị. Đồng thời, tham chiếu trái trị có định tính `const` có thể gắn với phải trị. Dưới đây là một đoạn mã ví dụ từ [tài liệu tham khảo](https://en.cppreference.com/w/cpp/language/reference).

```cpp
#include <iostream>
#include <string>

int main() {
  std::string s = "Ex";
  std::string& r1 = s;
  const std::string& r2 = s;

  r1 += "ample";  // Sửa r1, tức là sửa s
  // r2 += "!"; // Lỗi: không thể sửa thông qua tham chiếu tới const
  std::cout << r2 << '\n';  // In r2, truy cập s, xuất ra "Example"
}
```

Nơi tham chiếu trái trị được dùng phổ biến nhất là tham số hàm, nhằm tránh những phép sao chép không cần thiết.

```cpp
#include <iostream>
#include <string>

// s trong tham số là tham chiếu, nên khi gọi hàm sẽ không xảy ra sao chép
char& char_number(std::string& s, std::size_t n) {
  s += s;  // 's' và 'str' trong main()
           // là cùng một đối tượng; điều này cũng cho thấy trái trị có thể đặt ở vế phải dấu bằng
  return s.at(n);  // string::at() trả về tham chiếu tới char
}

int main() {
  std::string str = "Test";
  char_number(str, 1) = 'a';  // Giá trị hàm trả về là trái trị, nên có thể được gán
  std::cout << str << '\n';   // Ở đây xuất ra "TastTest"
}
```

## Tham chiếu phải trị T&& (C++ 11)

Tham chiếu phải trị là tham chiếu gắn với phải trị, dùng để di chuyển đối tượng, và cũng có thể dùng để **kéo dài thời gian sống của đối tượng tạm**.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1 = "Test";
  // string&& r1 = s1; // Lỗi: không thể gắn với trái trị, cần std::move hoặc static_cast

  const string& r2 = s1 + s1;  // Hợp lệ: tham chiếu trái trị tới hằng kéo dài thời gian sống
  // r2 += "Test"; // Lỗi: không thể sửa thông qua tham chiếu tới hằng
  cout << r2 << '\n';

  string&& r3 = s1 + s1;  // Hợp lệ: tham chiếu phải trị kéo dài thời gian sống
  r3 += "Test";
  cout << r3 << '\n';

  const string& r4 = r3;  // Tham chiếu phải trị có thể chuyển thành trái trị có định tính const
  cout << r4 << '\n';

  string& r5 = r3;  // Tham chiếu phải trị có thể chuyển thành trái trị
  cout << r5 << '\n';
}
```

## Tham chiếu treo

Khi đối tượng mà tham chiếu chỉ tới đã bị hủy, tham chiếu sẽ trở thành tham chiếu treo. Truy cập tham chiếu treo là hành vi không xác định và có thể khiến chương trình bị sập.

Dưới đây là các ví dụ thường gặp về tham chiếu treo:

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

      str.append("world");  // Có thể cấp phát lại bộ nhớ, khiến vùng nhớ ref trỏ tới bị giải phóng

      std::cout << ref << std::endl;  // Hành vi không xác định
    }
    ```

    Tương tự, thao tác chèn vào các container như `std::vector`, `std::unordered_map` cũng đều có thể dẫn tới cấp phát lại bộ nhớ.

Khi sử dụng tham chiếu, cần luôn chú ý tới thời gian sống của đối tượng mà tham chiếu trỏ tới để tránh tạo ra tham chiếu treo.

Thông thường, công cụ kiểm tra tĩnh và thói quen viết mã tốt có thể giúp ta tránh vấn đề tham chiếu treo.

## Kĩ thuật tối ưu liên quan đến tham chiếu

### Loại bỏ chi phí sao chép khi truyền đối tượng không nhẹ vào hàm

Các **đối tượng không nhẹ** thường gặp gồm:

-   Container như `vector`, `array`, `map`, v.v.
-   `string`
-   Các kiểu khác đã hiện thực hoặc kế thừa những hàm đặc biệt như hàm khởi tạo sao chép, hàm khởi tạo di chuyển tự định nghĩa

Trong khi đó, dùng tham chiếu cho **đối tượng nhẹ** không mang lại lợi ích nào; kích thước chiếm dụng của kiểu tham chiếu khi làm tham số thậm chí có thể lớn hơn chính kiểu đó.

Điều này có thể tạo thêm một ít gánh nặng hiệu năng, đồng thời có thể cản trở trình biên dịch tối ưu.

Những kiểu sau thuộc nhóm **đối tượng nhẹ**:

-   Kiểu cơ bản như `int`, `float`, v.v.
-   [Kiểu aggregate](https://en.cppreference.com/w/cpp/language/aggregate_initialization) nhỏ
-   Iterator của container trong thư viện chuẩn

### Chuyển trái trị thành phải trị

Dùng `std::move` để [chuyển giao](./value-category.md#stdmove) quyền sở hữu của đối tượng. Cách này thường xuất hiện giữa các biến cục bộ, hoặc giữa tham số và biến cục bộ:

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string world(string str) { return std::move(str) += " world!"; }

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

Tuy nhiên, không phải lúc nào cũng cần làm như vậy, ví dụ như khi có [tối ưu giá trị trả về của hàm](./value-category.md#các-hiểu-lầm-thường-gặp).

### Phải trị kéo dài thời gian sống của đối tượng tạm

Về mặt ngữ nghĩa, đối tượng tạm có thể gây ra thêm các phép sao chép hoặc di chuyển. Dù trong đa số trường hợp trình biên dịch có thể tối ưu bằng [loại bỏ sao chép](./value-category.md#loại-bỏ-sao-chép), tham chiếu có thể buộc trình biên dịch không thực hiện những thao tác thừa này, tránh sự bất định.

## Nội dung tham khảo

1.  [Tài liệu ngôn ngữ C++ - khai báo tham chiếu](https://en.cppreference.com/w/cpp/language/reference)
2.  [Tài liệu ngôn ngữ C++ - loại giá trị](https://en.cppreference.com/w/cpp/language/value_category)
3.  [Does const ref lvalue to non-const func return value specifically reduce copies?](https://stackoverflow.com/questions/38909228/does-const-ref-lvalue-to-non-const-func-return-value-specifically-reduce-copies)
