author: Ir1d, cjsoft, Lans1ot, JasonkayZK

Lớp (`class`) là phần mở rộng của cấu trúc: ngoài thành viên dữ liệu, nó còn có
hàm thành viên.

Trong lập trình hướng đối tượng (OOP), đối tượng là một thực thể của lớp, tức
một giá trị hoặc biến thuộc kiểu lớp đó.

Trong C++, kiểu được định nghĩa bằng từ khóa `struct` cũng là lớp. Định nghĩa
**cấu trúc** ở phần trước gần với cách dùng trong C. Vì lý do lịch sử, C++ giữ
lại và mở rộng `struct`.

## Định nghĩa lớp

Lớp được định nghĩa bằng từ khóa `class` hoặc `struct`; phần sau dùng `class`
làm ví dụ.

```cpp
class ClassName {
  ...
};

// Ví dụ:
class Object {
 public:
  int weight;
  int value;
} e[array_length];

const Object a;
Object b, B[array_length];
Object *c;
```

Cách dùng gần giống `struct`. Ví dụ này định nghĩa một lớp tên là `Object`. Lớp
này có hai thành viên dữ liệu là `weight` và `value`; sau dấu `}`, ví dụ còn
dùng kiểu này để khai báo mảng `e`.

Cách định nghĩa con trỏ tới lớp giống với [`struct`](./struct.md).

### Bộ chỉ định truy cập

Khác với ví dụ trong [`struct`](./struct.md), ví dụ này có `public`; đây là một
bộ chỉ định truy cập.

-   `public`: mọi thành viên sau bộ chỉ định truy cập này đều có thể được truy cập
    công khai, cả **bên trong lớp** lẫn **bên ngoài lớp**.
-   `protected`: mọi thành viên sau bộ chỉ định truy cập này có thể được thành
    viên **bên trong lớp**, thành viên của lớp dẫn xuất hoặc friend truy cập,
    nhưng **không thể truy cập từ bên ngoài lớp**.
-   `private`: mọi thành viên sau bộ chỉ định truy cập này **chỉ** có thể được
    thành viên **bên trong lớp** hoặc friend truy cập, **không thể** truy cập từ
    bên ngoài lớp hoặc từ lớp dẫn xuất.

Với `struct`, mọi thành viên mặc định đều là `public`. Với `class`, mọi thành
viên mặc định đều là `private`.

??? note "Khái niệm cơ bản về friend và lớp dẫn xuất"
    Friend (`friend`): dùng từ khóa `friend` để khai báo một hàm hoặc một lớp.
    Điều này cho phép **thực thể được khai báo là friend** truy cập thành viên
    riêng tư (`private`) hoặc được bảo vệ (`protected`) của lớp đó mà không cần
    trở thành hàm thành viên hoặc lớp thành viên. Khi một hàm hoặc lớp được khai
    báo là `friend` của lớp này, nó có thể truy cập các thành viên riêng tư hoặc
    được bảo vệ của lớp này.

    Lớp dẫn xuất (`derived class`): C++ cho phép dùng một lớp làm **lớp cơ sở**
    và từ lớp cơ sở **dẫn xuất** ra **lớp dẫn xuất**. Lớp dẫn xuất kế thừa biến
    thành viên và hàm thành viên của lớp cơ sở theo các quy tắc nhất định, nhờ
    đó tăng khả năng tái sử dụng mã.

    Lớp dẫn xuất biểu diễn quan hệ "là một". Ví dụ, xe tải (lớp dẫn xuất) "là
    một" phương tiện giao thông (lớp cơ sở).

    Từ khác biệt giữa `private` và `protected` ở trên, có thể thấy lớp dẫn xuất
    truy cập được thành viên `protected` của lớp cơ sở, nhưng không truy cập được
    thành viên `private`.

## Truy cập và sửa giá trị thành viên

Cách truy cập giống với [`struct`](./struct.md).

-   Với biến, dùng ký hiệu `.`.
-   Với con trỏ, dùng ký hiệu `->`.

## Hàm thành viên

Hàm thành viên, đúng như tên gọi, là hàm nằm trong lớp.

??? note "Ví dụ hàm thành viên thường gặp"
    ```cpp
    vector.push_back();
    set.insert();
    queue.empty();
    ```

```cpp
class Class_Name {
  ... type Function_Name(...) { ... }
};

// Ví dụ:
class Object {
 public:
  int weight;
  int value;

  void print() {
    cout << weight << endl;
    return;
  }

  void change_w(int);
};

void Object::change_w(int _weight) { weight = _weight; }

Object var;
```

Lớp này có một hàm thành viên để in dữ liệu của `Object` và một hàm để sửa thành
viên `weight`.

Tương tự hàm thường, hàm thành viên cũng có thể khai báo trước rồi định nghĩa
sau, như dòng khai báo trong lớp và phần định nghĩa bên ngoài lớp ở trên.

Nếu muốn gọi hàm thành viên `print` của `var`, có thể dùng `var.print()`.

### Nạp chồng toán tử

??? note "Nạp chồng là gì?"
    C++ cho phép người viết cung cấp nhiều định nghĩa cho hàm hoặc toán tử cùng
    tên. Điều này được gọi là **nạp chồng** (overload).

    Nếu các hàm cùng tên có khác biệt ở kiểu tham số hoặc số lượng tham số, chúng
    được xem là các hàm khác nhau.

    Lưu ý: nếu hai hàm cùng tên chỉ khác nhau ở kiểu giá trị trả về thì không
    thể nạp chồng; lúc này trình biên dịch sẽ từ chối biên dịch.

    Nếu lời gọi không nhập nhằng, tức có thể dựa vào kiểu và số lượng tham số đã
    truyền để xác định duy nhất hàm cần gọi, trình biên dịch sẽ chọn hàm tương
    ứng. Trường hợp nhập nhằng thường gặp ở các hàm có tham số mặc định.

    Quá trình trên được gọi là phân giải nạp chồng.

Trong một số trường hợp, nạp chồng toán tử có thể thay cho lời gọi hàm thông
thường và giúp mã ngắn gọn hơn.

Sau đây là ví dụ nạp chồng toán tử.

```cpp
class Vector {
 public:
  int x, y;

  Vector() : x(0), y(0) {}

  Vector(int _x, int _y) : x(_x), y(_y) {}

  int operator*(const Vector& other) const { return x * other.x + y * other.y; }

  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;
};

Vector Vector::operator+(const Vector& other) const {
  return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector& other) const {
  return Vector(x - other.x, y - other.y);
}

// Hai hàm tạo phía trên dùng danh sách khởi tạo thành viên để gán giá trị cho x, y.
```

Ví dụ này định nghĩa một lớp vector và nạp chồng các toán tử `*`, `+`, `-`, lần
lượt đại diện cho tích vô hướng vector, cộng vector và trừ vector.

Mẫu nạp chồng toán tử thường có các dạng sau:

```text
/* nạp chồng trong định nghĩa lớp */ kiểu_trả_về operator_ký_hiệu(tham_số){...}

/* khai báo trong định nghĩa lớp, định nghĩa bên ngoài */ kiểu_trả_về TênLớp::operator_ký_hiệu(tham_số){...}
```

Với lớp tự định nghĩa, nếu muốn dùng các container hoặc thuật toán STL tương ứng
như [`sort`](../basic/stl-sort.md), thông thường cần nạp chồng toán tử so sánh
`<`.

Để tìm hiểu thêm, xem mục thứ tư trong "Tài liệu tham khảo".

??? note "Các toán tử có thể được nạp chồng"
    ```text
    +       -       *       /       %       ^       &
    |       ~       !       =       <       >       +=
    -=      *=      /=      %=      ^=      &=      |=
    <<      >>      >>=     <<=     ==      !=      <=
    >=      &&      ||      ++      --      ,       ->*
    ->      ()      []      new     new []  delete  delete []
    ```

### Đặt giá trị ban đầu khi tạo biến

Để đặt giá trị ban đầu khi tạo đối tượng, có thể định nghĩa **hàm tạo**
(constructor).

```cpp
class ClassName {
  ... ClassName(...)... { ... }
};

// Ví dụ:
class Object {
 public:
  int weight;
  int value;

  Object() {
    weight = 0;
    value = 0;
  }
};
```

Ví dụ này định nghĩa hàm tạo mặc định của `Object`. Hàm này có thể khởi tạo mọi
thành viên dữ liệu thành `0` khi tạo biến kiểu `Object`.

Nếu người viết không tự định nghĩa hàm tạo, trình biên dịch xem lớp đó là có hàm
tạo mặc định ngầm định. Cụ thể, khi không có bất kỳ hàm tạo nào được định nghĩa,
trình biên dịch sẽ tự sinh một hàm tạo mặc định. Khi đó, các thành viên dữ liệu
kiểu dựng sẵn không nhất thiết được khởi tạo giá trị.

Trong trường hợp này, nếu các thành viên dữ liệu chưa được khởi tạo mà đã bị
truy cập, hành vi là không xác định, tức không thể biết chắc chương trình sẽ đọc
được giá trị gì.

Nếu cần tự định nghĩa giá trị khởi tạo, có thể định nghĩa thêm hoặc nạp chồng
hàm tạo.

??? note "Về định nghĩa hoặc nạp chồng hàm tạo"
    Thông thường, hàm tạo mặc định là hàm tạo có thể được gọi khi không truyền
    đối số. Đây là điểm khác với các hàm tạo còn lại. Cách định nghĩa hàm tạo và
    hàm tạo mặc định gần giống nhau, chỉ khác ở danh sách tham số.

    Hàm tạo có thể được nạp chồng; lần đầu viết một hàm tạo cũng là định nghĩa
    hàm tạo đó. Nếu đã định nghĩa hàm tạo, trình biên dịch sẽ không tự sinh hàm
    tạo mặc định không tham số nữa. Điều này có thể khiến thao tác tạo biến theo
    cách mặc định, tức không điền tham số khởi tạo, bị lỗi biên dịch.

Khi dùng C++11 trở lên, có thể dùng `{}` để khởi tạo biến.

??? note "Về `{}`"
    Quá trình khởi tạo bằng `{}` có thể sử dụng đối tượng proxy nhẹ
    `std::initializer_list`.

    Các bước khởi tạo thường diễn ra như sau:

    1.  Thử tìm hàm tạo nhận `std::initializer_list`; nếu có thì gọi hàm đó, và
        sau khi gọi xong thì không tiếp tục tìm các cách phía sau nữa. Các bước
        sau cũng tương tự.
    2.  Thử điền các phần tử trong `{}` vào tham số của các hàm tạo khác; nếu có
        thể điền đầy đủ tham số theo thứ tự, tính cả tham số mặc định, thì gọi
        hàm tạo tương ứng.
    3.  Nếu không có thành viên `private`, thử gán lần lượt **bên ngoài lớp** theo
        thứ tự định nghĩa thành viên hoặc thứ tự chỉ số.

    *Quá trình trên chỉ là phiên bản rút gọn của quá trình đầy đủ; chi tiết xem
    "Tài liệu tham khảo" mục 9.*

```cpp
class Object {
 public:
  int weight;
  int value;

  Object() {
    weight = 0;
    value = 0;
  }

  Object(int _weight, int _value) {
    weight = _weight;
    value = _value;
  }

  // Tương đương với
  // Object(int _weight, int _value) : weight(_weight), value(_value) {}
};

// Tương đương với
// Object::Object(int _weight, int _value) {
//   weight = _weight;
//   value = _value;
// }

Object A;        // hợp lệ
Object B(1, 2);  // hợp lệ
Object C{1, 2};  // hợp lệ (C++11)
```

??? note "Về chuyển đổi kiểu ngầm định"
    Đôi khi có thể viết đoạn mã sau:

    ```cpp
    class Node {
     public:
      int var;

      Node(int _var) : var(_var) {}
    };

    Node a = 1;
    ```

    Thoạt nhìn có vẻ lạ: một giá trị kiểu `int` không thể tự nhiên chuyển thành
    kiểu `Node`. Nhưng trình biên dịch sẽ không báo `error`.

    Nguyên nhân là trong quá trình khởi tạo sao chép, `1` được dùng làm tham số
    để gọi `Node::Node(int)`, từ đó tạo ra một đối tượng `Node`.

    Tuy nhiên trong đa số trường hợp, người viết muốn trình biên dịch báo lỗi.
    Khi đó có thể thêm từ khóa `explicit` trước hàm tạo. Từ khóa này cho trình
    biên dịch biết rằng hàm tạo phải được gọi tường minh.

    ```cpp
    class Node {
     public:
      int var;

      explicit Node(int _var) : var(_var) {}
    };
    ```

    Khi đó, `Node a = 1` sẽ báo lỗi, nhưng `Node a = Node(1)` thì không, vì đoạn
    sau gọi hàm tạo một cách tường minh. Cách viết sau không phổ biến, nhưng ví dụ
    này đủ để minh họa tác dụng của `explicit`.

    *Trong lập trình thi đấu, cách thường dùng để tránh tình huống này là viết
    mã chặt chẽ ngay từ đầu.*

### Hủy

Mỗi biến đều sẽ bị hủy khi ra khỏi phạm vi hiệu lực.

Nhưng với con trỏ trỏ tới vùng nhớ được cấp phát động, khi bản thân con trỏ bị
hủy, vùng nhớ mà nó trỏ tới sẽ không tự động được giải phóng; cần giải phóng bộ
nhớ động thủ công.

Nếu thành viên của lớp là con trỏ sở hữu vùng nhớ động, cũng sẽ gặp vấn đề này.
Khi đó cần dùng hàm hủy để giải phóng bộ nhớ động thủ công.

Hàm **hủy** (destructor) sẽ được gọi khi biến đó bị hủy. Cách định nghĩa tương
tự hàm tạo, nhưng cần thêm `~` phía trước tên hàm.

*Hàm hủy mặc định thường đã đủ dùng trong lập trình thi đấu; thường chỉ tự
định nghĩa hàm hủy khi thành viên có chứa con trỏ cần tự quản lý.*

```cpp
class Object {
 public:
  int weight;
  int value;
  int* ned;

  Object() {
    weight = 0;
    value = 0;
    ned = nullptr;
  }

  ~Object() { delete ned; }
};
```

### Gán giá trị cho biến lớp

Theo mặc định, khi gán giữa hai đối tượng cùng lớp, chương trình sẽ gán lần lượt
từng thành viên tương ứng. Cũng có thể dùng `TênLớp(...)` hoặc `TênLớp{...}` làm
đối tượng tạm để gán.

Khi dùng đối tượng tạm, trước hết chương trình tạo đối tượng tạm bằng hàm tạo
phù hợp, sau đó dùng toán tử gán để gán vào biến bên trái.

Ngoài ra, theo mặc định, việc gán giữa các thành viên tương ứng đều là **sao
chép nông**. Nếu thành viên có con trỏ, sau khi gán xong, con trỏ thành viên của
hai biến sẽ có cùng địa chỉ.

```cpp
// A, tmp1, tmp2, tmp3 có kiểu Object
tmp1 = A;
tmp2 = Object(...);
tmp3 = {...};
```

Nếu cần xử lý vấn đề con trỏ hoặc thao tác đặc biệt khác, cần tự định nghĩa toán
tử gán, hàm tạo sao chép hoặc các hàm thành viên đặc biệt liên quan.

*Nội dung khác về hàm tạo: xem mục thứ sáu trong "Tài liệu tham khảo".*

## Tài liệu tham khảo

1.  [cppreference class](https://en.cppreference.com/w/cpp/language/class)
2.  [cppreference access](https://en.cppreference.com/w/cpp/language/access)
3.  [cppreference default_constructor](https://en.cppreference.com/w/cpp/language/default_constructor)
4.  [cppreference operator](https://en.cppreference.com/w/cpp/language/operators)
5.  [cplusplus Data structures](http://www.cplusplus.com/doc/tutorial/structures/)
6.  [cplusplus Special members](http://www.cplusplus.com/doc/tutorial/classes2/)
7.  [C++11 FAQ](http://www.stroustrup.com/C++11FAQ.html)
8.  [cppreference Friendship and inheritance](http://www.cplusplus.com/doc/tutorial/inheritance/)
9.  [cppreference value initialization](https://en.cppreference.com/w/cpp/language/value_initialization)
