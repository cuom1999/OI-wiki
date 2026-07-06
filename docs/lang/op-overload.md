Nạp chồng toán tử là việc định nghĩa cách một toán tử hoạt động với các kiểu dữ
liệu cụ thể. Đây là một trường hợp đặc biệt của nạp chồng hàm.

Khi một toán tử xuất hiện trong biểu thức và ít nhất một toán hạng của nó có kiểu
lớp hoặc kiểu liệt kê, C++ sẽ dùng cơ chế phân giải nạp chồng (overload
resolution) để quyết định hàm `operator` nào cần được gọi.[^ref1]

Nói ngắn gọn, dùng "toán tử" cũng giống như gọi một hàm đặc biệt. Ví dụ, có thể
hình dung `1 + 2` như lời gọi `add(1, 2)`. Khi ít nhất một toán hạng có kiểu
`class`, `struct` hoặc `enum`, trình biên dịch sẽ dựa vào kiểu của các toán hạng
để quyết định hàm tùy biến nào cần được gọi.

Trong C++, có thể nạp chồng gần như mọi toán tử khả dụng.

???+ note "Một số toán tử có thể nạp chồng"
    Toán tử một ngôi: `+` (dấu dương); `-` (dấu âm); `~` (đảo bit); `++`; `--`;
    `!` (phủ định logic); `*` (giải tham chiếu con trỏ); `&` (lấy địa chỉ); `->`
    (truy cập thành viên thông qua con trỏ), v.v.

    Toán tử hai ngôi: `+`; `-`; `&` (AND theo bit); `[]` (truy cập chỉ số);
    `==`; `=` (gán), v.v.

    Khác: `()` (gọi hàm); `""` (literal do người dùng định nghĩa[^ref2], từ
    C++11); `new` (cấp phát bộ nhớ); `,` (toán tử dấu phẩy); `<=>` (so sánh ba
    chiều[^ref3], từ C++20), v.v.

## Giới hạn

Nạp chồng toán tử có các giới hạn sau:

-   Chỉ có thể nạp chồng các toán tử đã tồn tại, không thể tự định nghĩa toán tử
    mới.
-   Các toán tử sau không thể bị nạp chồng: `::` (phân giải phạm vi), `.` (truy
    cập thành viên), `.*` (truy cập thành viên thông qua con trỏ tới thành viên),
    `?:` (toán tử ba ngôi).
-   Sau khi nạp chồng, độ ưu tiên, số lượng toán hạng và tính kết hợp của toán tử
    không được thay đổi.
-   Nếu nạp chồng `&&` (AND logic) và `||` (OR logic), chúng sẽ mất tính chất đánh
    giá ngắn mạch.

## Cài đặt

Có hai cách nạp chồng toán tử: nạp chồng thành hàm thành viên hoặc thành hàm không
phải thành viên.

Khi nạp chồng thành hàm thành viên, đối tượng hiện tại được truyền ngầm qua con
trỏ `this` và đóng vai trò một toán hạng của phép toán; với toán tử hai ngôi, đó
là toán hạng bên trái. Vì vậy, số tham số viết ra trong hàm sẽ ít hơn số toán
hạng của phép toán một đơn vị.

Khi nạp chồng thành hàm không phải thành viên, số tham số của hàm bằng số toán
hạng của phép toán.

Khuôn dạng cơ bản như sau (giả sử toán tử cần nạp chồng là `@`):

```cpp
class Example {
  // Ví dụ về hàm thành viên
  ReturnType operator@(parameters_except_self) { /* ... */ }
};

// Ví dụ về hàm không phải thành viên
ReturnType operator@(all_operands) { /* ... */ }
```

Sau đây là một vài ví dụ về nạp chồng toán tử.

### Toán tử số học cơ bản

Ví dụ sau định nghĩa cấu trúc vector hai chiều `Vector2D`, rồi nạp chồng phép
cộng và tích vô hướng.

??? note "Ví dụ nạp chồng toán tử số học"
    ```cpp
    struct Vector2D {
      double x, y;
    
      Vector2D(double a = 0, double b = 0) : x(a), y(b) {}
    
      Vector2D operator+(const Vector2D& v) const { return Vector2D(x + v.x, y + v.y); }
    
      // Lưu ý kiểu trả về có thể không phải chính lớp này
      double operator*(const Vector2D& v) const { return x * v.x + y * v.y; }
    };
    ```

### Toán tử tăng giảm

Toán tử tăng giảm được chia thành hai loại: tiền tố (`++a`) và hậu tố (`a++`). Để
phân biệt dạng tiền tố và hậu tố, khi nạp chồng dạng hậu tố cần thêm một tham số
hình thức kiểu `int`; tham số này chỉ dùng để phân biệt chữ ký hàm.

Tăng tiền tố tương ứng với lời gọi `operator++(a)` hoặc `a.operator++()`, còn
tăng hậu tố tương ứng với lời gọi `operator++(a, 0)` hoặc `a.operator++(0)`.

??? note "Ví dụ nạp chồng riêng toán tử tăng tiền tố và hậu tố"
    ```cpp
    struct MyInt {
      int x;
    
      // Tiền tố, tương ứng với ++a
      MyInt &operator++() {
        x++;
        return *this;
      }
    
      // Hậu tố, tương ứng với a++
      MyInt operator++(int) {
        MyInt tmp;
        tmp.x = x;
        x++;
        return tmp;
      }
    };
    ```

Với các toán tử tăng giảm dựng sẵn, toán tử tiền tố trả về tham chiếu, còn toán
tử hậu tố trả về giá trị cũ trước khi tăng/giảm. Dù toán tử sau khi nạp chồng
không bắt buộc tuân theo quy ước này, về mặt ngữ nghĩa vẫn nên giữ kiểu trả về
nhất quán với toán tử dựng sẵn.

Với kiểu `T`, cách định nghĩa điển hình cho toán tử tăng là:

| Định nghĩa nạp chồng (lấy `++` làm ví dụ) | Hàm thành viên               | Hàm không phải thành viên      |
| ----------------------------------------- | ---------------------------- | ------------------------------ |
| Tiền tố                                   | `T& T::operator++();`        | `T& operator++(T& a);`         |
| Hậu tố                                    | `T T::operator++(int);`      | `T operator++(T& a, int);`     |

### Toán tử gọi hàm

Toán tử gọi hàm `()` chỉ có thể được nạp chồng thành hàm thành viên. Khi nạp
chồng toán tử `()` cho một lớp, đối tượng của lớp đó có thể được gọi như một
hàm.

Một ứng dụng phổ biến của nạp chồng toán tử `()` là truyền một cấu trúc đã nạp
chồng `()` làm hàm so sánh tùy biến vào các bộ chứa STL như hàng đợi ưu tiên.

Sau đây là một ví dụ: cho tên và điểm của $n$ học sinh, cần sắp xếp theo điểm
giảm dần. Nếu điểm bằng nhau, sắp xếp tên theo thứ tự từ điển tăng dần. Cuối cùng,
in tên và điểm của người có thứ hạng cao nhất.

Bên dưới định nghĩa một cấu trúc so sánh để cài đặt thứ tự ưu tiên tùy biến cho
hàng đợi ưu tiên.

??? note "Ví dụ nạp chồng toán tử gọi hàm"
    ```cpp
    struct student {
      string name;
      int score;
    };
    
    struct cmp {
      bool operator()(const student& a, const student& b) const {
        return a.score < b.score || (a.score == b.score && a.name > b.name);
      }
    };
    
    // Lưu ý tham số mẫu truyền vào là tên cấu trúc, không phải một đối tượng cụ thể
    priority_queue<student, vector<student>, cmp> pq;
    ```

### Toán tử so sánh

`std::sort` và một số bộ chứa STL cần dùng toán tử `<`. Với kiểu tự định nghĩa,
cần tự nạp chồng toán tử này nếu muốn các công cụ đó biết cách so sánh hai đối
tượng.

Ví dụ sau cài đặt cùng chức năng với phần trước.

??? note "Ví dụ nạp chồng toán tử so sánh"
    ```cpp
    struct student {
      string name;
      int score;
    
      // Nạp chồng toán tử <
      bool operator<(const student& a) const {
        return score < a.score || (score == a.score && name > a.name);
        // Ở trên đã lược bỏ con trỏ this; biểu thức đầy đủ như sau:
        // this->score < a.score || (this->score == a.score && this->name > a.name);
      }
    };
    
    priority_queue<student> pq;
    ```

Đoạn mã trên nạp chồng dấu nhỏ hơn thành hàm thành viên; cũng có thể nạp chồng
thành hàm không phải thành viên.

??? note "Nạp chồng thành hàm không phải thành viên"
    ```cpp
    struct student {
      string name;
      int score;
    };
    
    bool operator<(const student& a, const student& b) {
      return a.score < b.score || (a.score == b.score && a.name > b.name);
    }
    
    priority_queue<student> pq;
    ```

Khi đã có toán tử `<`, năm toán tử so sánh còn lại cũng có thể được cài đặt theo
các mẫu quen thuộc.

```cpp
/* clang-format off */

// Các cách cài đặt sau đều nạp chồng dấu nhỏ hơn thành hàm không phải thành viên

bool operator<(const T& lhs, const T& rhs) { /* Nạp chồng toán tử nhỏ hơn tại đây */ }
bool operator>(const T& lhs, const T& rhs) { return rhs < lhs; }
bool operator<=(const T& lhs, const T& rhs) { return !(lhs > rhs); }
bool operator>=(const T& lhs, const T& rhs) { return !(lhs < rhs); }
bool operator==(const T& lhs, const T& rhs) { return !(lhs < rhs) && !(lhs > rhs); }
bool operator!=(const T& lhs, const T& rhs) { return !(lhs == rhs); }
```

??? note "Về toán tử so sánh ba chiều trong C++20"
    Nếu sử dụng C++20 hoặc phiên bản cao hơn, có thể dùng toán tử so sánh ba
    chiều mặc định để đơn giản hóa mã.[^ref3]

    ```cpp
    auto operator<=>(const T &lhs, const T &rhs) = default;
    ```

    Thứ tự so sánh mặc định là so sánh từng biến thành viên theo thứ tự khai
    báo.[^ref4]

    Cũng có thể sử dụng so sánh ba chiều tùy biến. Lúc này cần chọn loại quan hệ
    thứ tự mà phép so sánh biểu diễn (`std::strong_ordering`,
    `std::weak_ordering` hoặc `std::partial_ordering`), hoặc trả về một đối tượng
    sao cho:

    -   Nếu `a < b`, thì `(a <=> b) < 0`;
    -   Nếu `a > b`, thì `(a <=> b) > 0`;
    -   Nếu `a` và `b` bằng nhau hoặc tương đương, thì `(a <=> b) == 0`.

    Xem chi tiết cài đặt tại
    [Toán tử so sánh # so sánh ba chiều - cppreference][cppref-three-way].

Tài liệu tham khảo và chú thích:

[^ref1]: [Nạp chồng toán tử - cppreference](https://en.cppreference.com/w/cpp/language/operators)

[^ref2]: [Literal do người dùng định nghĩa - cppreference](https://en.cppreference.com/w/cpp/language/user_literal)

[^ref3]:
    [Toán tử so sánh # so sánh ba chiều - cppreference][cppref-three-way]

[^ref4]: [So sánh mặc định - cppreference](https://en.cppreference.com/w/cpp/language/default_comparisons)

[cppref-three-way]: https://en.cppreference.com/w/cpp/language/operator_comparison#Three-way_comparison
