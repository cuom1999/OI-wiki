author: Ir1d, cjsoft, Lans1ot, JasonkayZK

Lớp (`class`) là phần mở rộng của cấu trúc: nó không chỉ có phần tử thành viên,
mà còn có hàm thành viên.

Trong lập trình hướng đối tượng (OOP), đối tượng là một thực thể của lớp, tức
một biến.

Trong C++, thứ được định nghĩa bằng từ khóa `struct` cũng là lớp. Định nghĩa
**cấu trúc** ở phần trước xuất phát từ C. Vì một số nguyên nhân lịch sử, C++ giữ
lại và mở rộng `struct`.

## Định nghĩa lớp

Lớp được định nghĩa bằng từ khóa `class` hoặc `struct`; phần dưới đây lấy
`class` làm ví dụ.

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
này có hai phần tử thành viên là `weight,value`; sau dấu `}`, ví dụ còn dùng
kiểu này để định nghĩa một mảng `e`.

Cách định nghĩa con trỏ tới lớp giống với [`struct`](./struct.md).

### Bộ chỉ định truy cập

Khác với ví dụ trong [`struct`](./struct.md), ví dụ này có `public`, đây là một
bộ chỉ định truy cập.

-   `public`: mọi thành viên sau bộ chỉ định truy cập này đều có thể được truy
    cập công khai; nói đơn giản là có thể truy cập cả **bên trong lớp** lẫn
    **bên ngoài lớp**.
-   `protected`: mọi thành viên sau bộ chỉ định truy cập này có thể được thành
    viên **bên trong lớp**, lớp dẫn xuất hoặc friend truy cập, nhưng **không thể
    truy cập từ bên ngoài lớp**.
-   `private`: mọi thành viên sau bộ chỉ định truy cập này **chỉ** có thể được
    thành viên **bên trong lớp** hoặc friend truy cập, **không thể** truy cập từ
    bên ngoài lớp hoặc từ lớp dẫn xuất.

Với `struct`, mọi thành viên mặc định đều là `public`. Với `class`, mọi thành
viên mặc định đều là `private`.

??? note "Khái niệm cơ bản về friend và lớp dẫn xuất"
    Friend (`friend`): dùng từ khóa `friend` để bổ nghĩa một hàm hoặc một lớp.
    Điều này cho phép **đối tượng được bổ nghĩa** truy cập thành viên riêng tư
    (`private`) hoặc được bảo vệ (`protected`) của lớp đó mà không cần trở thành
    hàm thành viên hoặc lớp thành viên. Nói đơn giản, chỉ cần có dấu `friend` của
    lớp này thì có thể truy cập các phần tử thành viên riêng tư hoặc được bảo vệ.

    Lớp dẫn xuất (`derived class`): C++ cho phép dùng một lớp làm **lớp cơ sở**
    và từ lớp cơ sở **dẫn xuất** ra **lớp dẫn xuất**. Lớp dẫn xuất kế thừa biến
    thành viên và hàm thành viên của lớp cơ sở theo các quy tắc nhất định, nhờ
    đó tăng khả năng tái sử dụng mã.

    Lớp dẫn xuất giống quan hệ "là một". Ví dụ, mèo (lớp dẫn xuất) "là một" động
    vật có vú (lớp cơ sở).

    Với khác biệt giữa `private` và `protected` ở trên, có thể hiểu rằng lớp dẫn
    xuất có thể truy cập phần tử `protected` của lớp cơ sở (tương tự `public`),
    nhưng không thể truy cập phần tử `private`.

## Truy cập và sửa giá trị phần tử thành viên

Cách làm giống [`struct`](./struct.md).

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

Lớp này có một hàm in phần tử thành viên của `Object`, và một hàm sửa phần tử
thành viên `weight`.

Tương tự hàm thường, hàm thành viên cũng có thể khai báo trước rồi định nghĩa
sau, như dòng khai báo trong lớp và phần định nghĩa bên ngoài lớp ở trên.

Nếu muốn gọi hàm thành viên `print` của `var`, có thể dùng `var.print()`.

### Nạp chồng toán tử

??? note "Nạp chồng là gì?"
    C++ cho phép người viết chỉ định các định nghĩa khác nhau cho hàm hoặc toán
    tử cùng tên. Điều này được gọi là **nạp chồng** (overload).

    Nếu các hàm cùng tên khác nhau từng đôi một ở một hoặc nhiều yếu tố trong
    loại tham số hoặc số lượng tham số, chúng được xem là các hàm khác nhau.

    Cần chú ý: nếu hai hàm cùng tên chỉ khác nhau ở kiểu giá trị trả về thì
    không thể nạp chồng; lúc này trình biên dịch sẽ từ chối biên dịch.

    Nếu khi gọi không xảy ra nhập nhằng, tức khi gọi một hàm cùng tên nào đó có
    thể dựa vào loại và số lượng tham số đã truyền để xác định duy nhất hàm cần
    gọi, trình biên dịch sẽ dựa vào tham số khi gọi để quyết định nên gọi hàm
    nào. Trường hợp nhập nhằng thường gặp ở các hàm có tham số mặc định.

    Quá trình trên được gọi là phân giải nạp chồng.

Nạp chồng toán tử có thể thay thế hàm ở một mức độ nhất định và làm mã ngắn gọn
hơn.

Dưới đây là ví dụ nạp chồng toán tử.

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

// Các dòng 4,5 biểu thị việc gán giá trị cho x,y; xem phần sau để biết cài đặt cụ thể.
```

Ví dụ này định nghĩa một lớp vector và nạp chồng các toán tử `* + -`, lần lượt
đại diện cho tích vô hướng vector, cộng vector và trừ vector.

Mẫu nạp chồng toán tử đại khái có thể chia thành các phần sau:

```text
/* nạp chồng trong định nghĩa lớp */ kiểu_trả_về operator_ký_hiệu(tham_số){...}

/* khai báo trong định nghĩa lớp, định nghĩa bên ngoài */ kiểu_trả_về TênLớp::operator_ký_hiệu(tham_số){...}
```

Với lớp tự định nghĩa, nếu đã nạp chồng một số toán tử, thường chỉ cần nạp chồng
toán tử so sánh `<`, thì có thể dùng các container hoặc thuật toán STL tương
ứng, chẳng hạn [`sort`](../basic/stl-sort.md).

Để tìm hiểu thêm, có thể xem mục thứ tư trong "Tài liệu tham khảo".

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

Để thực hiện thao tác này, cần định nghĩa **hàm tạo mặc định** (default
constructor).

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
phần tử thành viên thành `0` khi ta tạo biến kiểu `Object`.

Nếu không có hàm tạo tường minh, trình biên dịch xem lớp đó là có hàm tạo mặc
định ngầm định. Nói cách khác, nếu không định nghĩa bất kỳ hàm tạo nào, trình
biên dịch sẽ tự động sinh một hàm tạo mặc định và khởi tạo theo kiểu của phần tử
thành viên, giống như khi định nghĩa biến kiểu dựng sẵn.

Trong trường hợp này, các phần tử thành viên đều chưa được khởi tạo; truy cập
biến chưa khởi tạo có kết quả là hành vi không xác định, tức không biết sẽ trả
về giá trị gì.

Nếu cần tự định nghĩa giá trị khởi tạo, có thể định nghĩa thêm, hoặc nạp chồng,
hàm tạo.

??? note "Về định nghĩa hoặc nạp chồng hàm tạo"
    Nói chung, hàm tạo mặc định không có tham số, đây là điểm khác với hàm tạo
    nói chung. Cách định nghĩa hàm tạo và hàm tạo mặc định gần giống nhau, chỉ
    khác ở số lượng tham số.

    Hàm tạo có thể được nạp chồng; lần đầu viết tất nhiên cũng có thể gọi là
    định nghĩa. Cần chú ý rằng nếu đã định nghĩa hàm tạo, trình biên dịch sẽ
    không tự sinh hàm tạo mặc định không tham số nữa. Điều này có thể khiến hành
    vi thử tạo biến theo cách mặc định, tức không điền tham số khởi tạo, bị lỗi
    biên dịch.

Khi dùng C++11 trở lên, có thể dùng `{}` để khởi tạo biến.

??? note "Về `{}`"
    Dùng `{}` để khởi tạo sẽ dùng đối tượng proxy nhẹ `std::initializer_list` để
    khởi tạo.

    Các bước khởi tạo đại khái như sau:

    1.  Thử tìm hàm tạo mặc định có tham số `std::initializer_list`; nếu có thì
        gọi hàm đó, và sau khi gọi xong không tiếp tục tìm các cách bên dưới
        nữa. Các bước sau cũng tương tự.
    2.  Thử điền các phần tử trong `{}` vào các tham số tạo khác; nếu có thể
        điền đầy đủ tham số theo thứ tự, tính cả tham số mặc định, thì gọi hàm
        tạo mặc định đó.
    3.  Nếu không có phần tử thành viên `private`, thử gán lần lượt **bên ngoài
        lớp** theo thứ tự định nghĩa phần tử hoặc thứ tự chỉ số.

    *Quá trình trên chỉ là phiên bản đơn giản hóa của quá trình đầy đủ; chi tiết
    xem "Tài liệu tham khảo" mục 9.*

```cpp
class Object {
 public:
  int weight;
  int value;

  Object() {
    weight = 0;
    value = 0;
  }

  Object(int _weight = 0, int _value = 0) {
    weight = _weight;
    value = _value;
  }

  // the same as
  // Object(int _weight,int _value):weight(_weight),value(_value) {}
};

// the same as
// Object::Object(int _weight,int _value){
//   weight = _weight;
//   value = _value;
// }
//}

Object A;        // ok
Object B(1, 2);  // ok
Object C{1, 2};  // ok,(C++11)
```

??? note "Về chuyển đổi kiểu ngầm định"
    Đôi khi ta sẽ viết đoạn mã sau:

    ```cpp
    class Node {
     public:
      int var;

      Node(int _var) : var(_var) {}
    };

    Node a = 1;
    ```

    Trông có vẻ rất vô lý: một kiểu `int` không thể chuyển thành kiểu `node`.
    Nhưng trình biên dịch sẽ không báo `error`.

    Nguyên nhân là khi gán, trước hết `1` được dùng làm tham số để gọi
    `node::node(int)`, rồi gọi hàm sao chép mặc định để gán.

    Tuy nhiên trong đa số trường hợp, người viết muốn trình biên dịch báo lỗi.
    Khi đó có thể thêm từ khóa `explicit` trước hàm tạo. Từ khóa này cho trình
    biên dịch biết rằng bắt buộc phải gọi tường minh.

    ```cpp
    class Node {
     public:
      int var;

      explicit Node(int _var) : var(_var) {}
    };
    ```

    Nghĩa là `node a=1` sẽ báo lỗi, nhưng `node a=node(1)` thì không, vì đoạn
    sau gọi hàm tạo một cách tường minh. Dĩ nhiên đa số người sẽ không viết đoạn
    sau, nhưng ví dụ này đủ để minh họa tác dụng của `explicit`.

    *Tuy vậy trong lập trình thi đấu, cách thường dùng để tránh tình huống này là
    "nâng cao mức độ chuẩn mực của mã" ngay từ đầu.*

### Hủy

Đây là vấn đề không thể tránh. Mỗi biến đều sẽ bị hủy khi ra khỏi phạm vi tác
dụng.

Nhưng với con trỏ đã trỏ tới vùng nhớ được cấp phát động, khi con trỏ bị hủy nó
sẽ không tự động giải phóng vùng nhớ mà nó trỏ tới; cần giải phóng bộ nhớ động
thủ công.

Nếu phần tử thành viên của cấu trúc có chứa con trỏ, cũng sẽ gặp vấn đề này. Khi
đó cần dùng hàm hủy để giải phóng bộ nhớ động thủ công.

Hàm **hủy** (destructor) sẽ được gọi khi biến đó bị hủy. Cách nạp chồng tương tự
hàm tạo, nhưng cần thêm `~` phía trước.

*Hàm hủy được định nghĩa mặc định thường đã đủ dùng trong lập trình thi đấu; ta
thường chỉ nạp chồng hàm hủy khi phần tử thành viên có chứa con trỏ.*

```cpp
class Object {
 public:
  int weight;
  int value;
  int* ned;

  Object() {
    weight = 0;
    value = 0;
  }

  ~Object() { delete ned; }
};
```

### Gán giá trị cho biến lớp

Theo mặc định, khi gán, chương trình sẽ gán theo quy tắc gán của từng phần tử
thành viên tương ứng. Cũng có thể dùng `TênLớp()` hoặc `TênLớp{}` làm biến tạm
để gán.

Cách trước chỉ gọi hàm tạo sao chép (copy constructor), còn cách sau gọi hàm tạo
mặc định trước khi gọi hàm tạo sao chép.

Ngoài ra, theo mặc định, việc gán giữa các phần tử tương ứng đều là **sao chép
nông**. Nếu phần tử thành viên có con trỏ, sau khi gán xong, con trỏ thành viên
của hai biến sẽ có cùng địa chỉ.

```cpp
// A,tmp1,tmp2,tmp3 có kiểu Object
tmp1 = A;
tmp2 = Object(...);
tmp3 = {...};
```

Nếu cần giải quyết vấn đề con trỏ hoặc cần thao tác khác, cần nạp chồng hàm tạo
tương ứng.

*Nội dung khác về hàm tạo (constructor), xem mục thứ sáu trong "Tài liệu tham
khảo".*

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
