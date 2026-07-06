author: tsagaanbar, Enter-tainer, Xeonacid

## Địa chỉ của biến và con trỏ

Trong chương trình, dữ liệu thường nằm ở một địa chỉ nào đó trong bộ nhớ. Mỗi lần
chương trình chạy, vị trí của biến trong không gian địa chỉ có thể khác nhau.
Tuy vậy, khi lập trình, vẫn có thể dùng các câu lệnh nhất định để lấy địa chỉ
của dữ liệu trong bộ nhớ.

Địa chỉ cũng là một loại dữ liệu. Biến dùng để lưu địa chỉ có tên gọi riêng là
"biến con trỏ", thường gọi ngắn gọn là "con trỏ".

???+ note "Kích thước của biến con trỏ"
    Kích thước của biến con trỏ phụ thuộc vào môi trường. Trên các môi trường
    32 bit phổ biến, kích thước của một con trỏ thường là 4 byte. Trên các môi
    trường 64 bit phổ biến, kích thước của một con trỏ thường là 8 byte. Khi cần
    giá trị chính xác trong chương trình, dùng `sizeof`.

Địa chỉ là một giá trị dùng để định vị vùng nhớ. Để xử lý dữ liệu thuộc nhiều
kiểu khác nhau, biến con trỏ cũng có nhiều kiểu tương ứng. Ví dụ, một biến con
trỏ tới `int` lưu địa chỉ bắt đầu của một đối tượng `int`; một biến con trỏ tới
`char` lưu địa chỉ bắt đầu của một đối tượng `char`.

Ngoài ra, cũng có thể khai báo một biến con trỏ trỏ tới một biến con trỏ khác.

Giả sử có một cấu trúc tự định nghĩa:

```cpp
struct ThreeInt {
  int a;
  int b;
  int c;
};
```

Khi đó, biến con trỏ tới `ThreeInt` trỏ tới một đối tượng `ThreeInt`. Kích thước
của đối tượng này do bố cục cấu trúc quyết định; trong môi trường thường gặp, ba
thành viên `int` chiếm ít nhất `3 * sizeof(int)` byte, và trình biên dịch có thể
chèn thêm phần đệm.

## Khai báo và sử dụng con trỏ

Trong C/C++, kiểu con trỏ được viết bằng tên kiểu cơ sở kèm dấu sao `*`. Ví dụ,
kiểu của con trỏ tới `int` là `int*`.

Có thể dùng ký hiệu `&` để lấy địa chỉ của một biến.

Muốn truy cập vùng nhớ tương ứng với địa chỉ mà biến con trỏ lưu, còn gọi là vùng
nhớ mà con trỏ **trỏ tới**, cần **giải tham chiếu** biến con trỏ bằng ký hiệu
`*`.

```cpp
int main() {
  int a = 123;  // a: 123
  int* pa = &a;
  *pa = 321;  // a: 321
}
```

Với biến cấu trúc cũng tương tự. Nếu muốn truy cập thành viên của cấu trúc mà
con trỏ trỏ tới, trước hết cần giải tham chiếu con trỏ, rồi dùng toán tử truy
cập thành viên `.`. Tuy nhiên, cách viết ngắn gọn hơn là toán tử "mũi tên" `->`.

```cpp
struct ThreeInt {
  int a;
  int b;
  int c;
};

int main() {
  ThreeInt x{1, 2, 3}, y{6, 7, 8};
  ThreeInt* px = &x;
  (*px) = y;    // x: {6,7,8}
  (*px).a = 4;  // x: {4,7,8}
  px->b = 5;    // x: {4,5,8}
}
```

## Dịch chuyển con trỏ

Biến con trỏ cũng có thể thực hiện phép cộng trừ **với số nguyên**. Với con trỏ
tới `int`, mỗi khi cộng 1, địa chỉ mà nó trỏ tới sẽ dịch đi `sizeof(int)` byte;
nếu cộng 2, địa chỉ đó sẽ dịch đi `2 * sizeof(int)` byte. Tương tự, với con trỏ
tới `char`, mỗi lần tăng, địa chỉ mà nó trỏ tới sẽ dịch đi `sizeof(char)` byte,
tức 1 byte.

Cần lưu ý rằng số học con trỏ chỉ an toàn khi con trỏ nằm trong cùng một mảng,
hoặc trỏ tới vị trí ngay sau phần tử cuối cùng của mảng để so sánh hay làm mốc
dừng. Giải tham chiếu một con trỏ không hợp lệ, ví dụ con trỏ null hoặc con trỏ
đã vượt ra ngoài vùng hợp lệ, sẽ dẫn đến hành vi không xác định.

### Dùng dịch chuyển con trỏ để truy cập mảng

Ở phần trước đã nói rằng mảng là một vùng lưu trữ liên tiếp. Trong nhiều biểu
thức C/C++, tên mảng sẽ được chuyển đổi ngầm định thành con trỏ trỏ tới phần tử
đầu tiên của mảng.

```cpp
int main() {
  int a[3] = {1, 2, 3};
  int* p = a;  // p trỏ tới a[0]
  *p = 4;      // a: [4, 2, 3]
  p = p + 1;   // p trỏ tới a[1]
  *p = 5;      // a: [4, 5, 3]
  p++;         // p trỏ tới a[2]
  *p = 6;      // a: [4, 5, 6]
}
```

Khi truy cập phần tử trong mảng thông qua con trỏ, thường dùng đến "dịch chuyển
con trỏ": lấy một địa chỉ cơ sở, tức địa chỉ bắt đầu của mảng, rồi cộng thêm độ
lệch.

Thường dùng toán tử `[]` để truy cập phần tử của mảng tại một độ lệch được chỉ
định, ví dụ `a[3]` hoặc `p[4]`. Cách viết này tương đương với việc tính toán trên
con trỏ rồi giải tham chiếu kết quả, tức `p[4]` và `*(p + 4)` là hai cách viết
tương đương.

## Con trỏ null

Trước C++11, C++ cũng như C dùng macro `NULL` để biểu diễn hằng con trỏ null.
Trong C++, `NULL` thường được cài đặt như sau:

```cpp
// Trước C++11
#define NULL 0
```

???+ note "Định nghĩa `NULL` trong ngôn ngữ C"
    Trước C23, ngôn ngữ C có vài cách định nghĩa `NULL`, chủ yếu khác ở kiểu:
    một là biểu thức hằng kiểu số nguyên, một là biểu thức hằng được
    chuyển đổi sang kiểu `void *`. Trình biên dịch có thể chọn một trong các
    cách cài đặt này.

Việc dùng lẫn con trỏ null và số nguyên `0` trong C++ sẽ gây ra nhiều vấn đề, ví
dụ:

```cpp
int f(int x);
int f(int* p);
```

Nếu `NULL` được định nghĩa là `0`, lời gọi `f(NULL)` sẽ khớp với hàm `int(int)`
chứ không phải `int(int *)`.

???+ note "Vấn đề do `NULL` gây ra trong ngôn ngữ C"
    So với C++, vì có nhiều cách định nghĩa, vấn đề do `NULL` gây ra trong ngôn
    ngữ C còn nghiêm trọng hơn: nếu một hàm nhận tham số biến thiên cần đọc một
    con trỏ, nhưng người gọi lại truyền vào một `NULL` được định nghĩa là kiểu
    số nguyên, thì có thể gây ra hành vi không xác định. Nguyên nhân là khi lấy
    tham số biến thiên bên trong hàm, chương trình đọc một giá trị được truyền
    với kiểu số nguyên như thể đó là kiểu con trỏ, khiến kiểu thực tế và kiểu
    được đọc ra không khớp.[^note1]

Để giải quyết các vấn đề này, C++11 đã đưa vào từ khóa `nullptr` làm hằng con
trỏ null.

C++ quy định rằng `nullptr` có thể được chuyển đổi ngầm định sang bất kỳ kiểu con
trỏ nào; kết quả của phép chuyển đổi này là giá trị con trỏ null của kiểu đó.

Kiểu của `nullptr` là `std::nullptr_t`, gọi là kiểu con trỏ null. Một cách cài
đặt có thể như sau:

```cpp
namespace std {
typedef decltype(nullptr) nullptr_t;
}
```

Ngoài ra, từ C++11, nên dùng `nullptr` thay cho `NULL`; một số thư viện có thể
cài đặt `NULL` theo hướng tương tự:

```cpp
// Ví dụ minh họa
#define NULL nullptr
```

???+ note "Cải tiến của ngôn ngữ C đối với hằng con trỏ null"
    Vì những lý do tương tự, C23 cũng đưa vào `nullptr` làm hằng con trỏ null,
    đồng thời đưa vào `nullptr_t` làm kiểu của nó.[^note1]

## Sử dụng con trỏ nâng cao

Việc dùng con trỏ cho phép người lập trình thao tác với dữ liệu ở nhiều nơi
trong lúc chương trình chạy, thay vì bị giới hạn trong phạm vi hiện tại.

### Sử dụng tham số kiểu con trỏ

Trong C/C++, khi gọi hàm, các tham số thông thường được truyền vào dưới dạng bản
sao, ngoại trừ tham chiếu sẽ được giới thiệu ở phần sau. Theo mặc định, hàm chỉ
có thể trả kết quả về nơi gọi thông qua giá trị trả về. Tuy nhiên, nếu một hàm
muốn sửa dữ liệu bên ngoài nó, hoặc nếu dữ liệu của một cấu trúc/lớp lớn và
không phù hợp để sao chép, có thể truyền địa chỉ của dữ liệu bên ngoài vào hàm,
nhờ đó truy cập, thậm chí sửa đổi dữ liệu đó ngay trong hàm.

Hàm `my_swap` sau đây nhận hai con trỏ kiểu `int` và dùng biến trung gian trong
hàm để hoán đổi giá trị của hai biến kiểu `int`.

```cpp
void my_swap(int *a, int *b) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

int main() {
  int a = 6, b = 10;
  my_swap(&a, &b);
  // Sau khi gọi, trong hàm main, giá trị của biến a trở thành 10,
  // còn giá trị của biến b trở thành 6
}
```

C++ đưa vào khái niệm tham chiếu; so với con trỏ trong nhiều tình huống thường
gặp, tham chiếu dễ dùng hơn và cũng khó bị dùng sai hơn. Xem thêm
[C++: Tham chiếu](./reference.md) và
[Khác biệt giữa C và C++: Con trỏ và tham chiếu](./cpp-other-langs.md#con-trỏ-và-tham-chiếu).

### Khởi tạo động

Khi viết chương trình, cũng thường gặp việc cấp phát bộ nhớ động, tức chương
trình yêu cầu hoặc trả lại vùng nhớ cần thiết để lưu dữ liệu trong lúc chạy. Bộ
cấp phát bộ nhớ trả về địa chỉ của vùng nhớ đã cấp phát. Để sử dụng vùng nhớ
này, cần lưu địa chỉ của nó trong biến con trỏ.

Trong C++, dùng toán tử `new` để cấp phát vùng nhớ, và dùng toán tử `delete`
để giải phóng vùng nhớ mà con trỏ trỏ tới.

```cpp
int* p = new int(1234);
/* ... */
delete p;
```

Câu lệnh trên dùng toán tử `new` để cấp phát vùng nhớ đủ chứa `int`, khởi tạo
giá trị trong đó là 1234, đồng thời khai báo một con trỏ kiểu `int` tên `p` trỏ
tới vùng nhớ này.

Tương tự, cũng có thể dùng `new` để tạo đối tượng mới:

```cpp
class A {
  int a;

 public:
  A(int a_) : a(a_) {}
};

int main() {
  A* p = new A(1234);
  /* ... */
  delete p;
}
```

Như trên, biểu thức `new` sẽ thử cấp phát vùng nhớ có kích thước tương ứng, xây
dựng đối tượng trên vùng nhớ này, rồi trả về địa chỉ của vùng nhớ.

```cpp
struct ThreeInt {
  int a;
  int b;
  int c;
};

int main() {
  ThreeInt* p = new ThreeInt{1, 2, 3};
  /* ... */
  delete p;
}
```

???+ note "Khởi tạo bằng danh sách"
    Toán tử `{}` có thể dùng để khởi tạo những cấu trúc không có hàm tạo tự định
    nghĩa. Ngoài ra, dùng toán tử `{}` có thể làm cho hình thức khởi tạo biến
    thống nhất hơn. Xem thêm
    "[list initialization (since C++11)](https://en.cppreference.com/w/cpp/language/list_initialization)".

Khi vùng nhớ được cấp phát bằng `new` không còn được sử dụng, cần dùng `delete`
để giải phóng vùng nhớ này. Không được giải phóng cùng một vùng nhớ hai lần trở
lên. Thao tác `delete` trên con trỏ null `nullptr` là hợp lệ.

### Tạo mảng động

Cũng có thể dùng toán tử `new[]` để tạo mảng. Khi đó toán tử `new[]` sẽ trả về
địa chỉ đầu của mảng, tức địa chỉ của phần tử đầu tiên trong mảng; có thể dùng
con trỏ có kiểu tương ứng để lưu địa chỉ này. Khi giải phóng, cần dùng toán tử
`delete[]`.

```cpp
size_t element_cnt = 5;
int *p = new int[element_cnt];
delete[] p;
```

Các phần tử trong mảng được lưu liên tiếp, tức `p + 1` trỏ tới phần tử kế tiếp
sau `p`.

### Mảng hai chiều

Khi lưu dữ liệu dạng ma trận, có thể cần dùng đến kiểu dữ liệu như "mảng hai
chiều". Về mặt ngữ nghĩa, mảng hai chiều là một mảng của các mảng. Trong khi đó,
bộ nhớ máy tính giống một mảng một chiều dài. Khi lưu một mảng hai
chiều trong bộ nhớ máy tính, cần phân biệt vùng nhớ có "liên tiếp" hay không.

"Liên tiếp" nghĩa là cuối của một hàng trong mảng hai chiều và đầu của hàng tiếp
theo nằm kề nhau trong không gian địa chỉ; nói cách khác, toàn bộ mảng hai chiều
có thể được xem như một mảng một chiều. Ngược lại, hai phần đó không nhất thiết
kề nhau trong bộ nhớ.

Với mảng hai chiều "liên tiếp", chỉ cần dùng một vòng lặp và một con trỏ tăng dần
là có thể duyệt toàn bộ dữ liệu trong mảng. Với mảng hai chiều không liên tiếp,
do từng hàng không liên tiếp với nhau, cần lấy địa chỉ đầu của một hàng nào đó
trước, rồi mới truy cập các phần tử trong hàng đó.

???+ note "Cách lưu trữ mảng hai chiều"
    Cách lưu dữ liệu theo "hàng" này được gọi là lưu trữ theo thứ tự hàng
    trước; tương ứng, cũng có thể lưu dữ liệu theo cột trước. Do đặc tính truy
    cập bộ nhớ của máy tính, nhìn chung, truy cập dữ liệu liên tiếp sẽ hiệu quả
    hơn. Vì vậy, cần chọn cách lưu trữ "hàng trước" hoặc "cột trước" theo cách
    dữ liệu sẽ được sử dụng.

### Tạo mảng hai chiều động

Trong C/C++, có thể dùng câu lệnh tương tự sau đây để khai báo một mảng hai
chiều gồm N hàng và M cột, có vùng nhớ liên tiếp.

???+ note "Mô tả số chiều của mảng"
    Cách tổng quát hơn là nói theo chiều thứ n. Với dạng lưu trữ "hàng trước",
    độ dài của chiều thứ nhất của mảng là N, và độ dài của chiều thứ hai là M.

```cpp
int a[N][M];
```

Cách khai báo này yêu cầu N và M là các biểu thức hằng có thể xác định tại thời
điểm biên dịch.

Trong C/C++, chỉ số của phần tử đầu tiên trong mảng là 0, nên biểu thức như
`a[r][c]` biểu thị phần tử thứ c + 1 của hàng thứ r + 1 trong mảng hai chiều
`a`; chỉ số của phần tử này cũng được gọi là `(r, c)`.

Tuy nhiên, trong sử dụng thực tế, kích thước của mảng hai chiều có thể không cố
định, nên cần cấp phát bộ nhớ động.

Cách thường gặp là khai báo một **mảng một chiều** có độ dài N × M, rồi truy cập
phần tử có chỉ số `(r, c)` trong mảng hai chiều bằng chỉ số `r * M + c`.

```cpp
int* a = new int[N * M];
```

Cách này có thể bảo đảm mảng hai chiều là **liên tiếp**.

???+ note "Lưu trữ tuyến tính của mảng"
    Dữ liệu trong bộ nhớ đều có thể được xem là được lưu theo tuyến tính. Vì
    vậy, dưới một quy tắc ánh xạ chỉ số nhất định, chỉ cần cấp phát động vùng
    nhớ của mảng một chiều là đã có thể lưu mảng n chiều trên đó.

Ngoài ra, cũng có thể cấp phát và sử dụng bộ nhớ theo khái niệm "mảng của các
mảng". Đối với một mảng lưu nhiều mảng, thực chất đó là một mảng lưu địa chỉ đầu
của nhiều mảng, tức một mảng lưu nhiều biến con trỏ.

Cần một biến để lưu địa chỉ đầu của "mảng của các mảng" này, tức địa chỉ của một
con trỏ. Biến này chính là một "con trỏ trỏ tới con trỏ", đôi khi cũng gọi là
"con trỏ cấp hai", ví dụ:

```cpp
int** a = new int*[5];
```

Tiếp theo, cần cấp phát vùng nhớ cho từng mảng:

```cpp
for (int i = 0; i < 5; i++) {
  a[i] = new int[5];
}
```

Đến đây, việc cấp phát bộ nhớ đã hoàn tất. Khi giải phóng vùng nhớ thu được theo
cách này, cần thực hiện thao tác ngược lại: trước hết giải phóng từng mảng, rồi
giải phóng mảng lưu địa chỉ đầu của các mảng đó, ví dụ:

```cpp
for (int i = 0; i < 5; i++) {
  delete[] a[i];
}
delete[] a;
```

Mảng hai chiều thu được theo cách này không bảo đảm vùng nhớ của nó là liên tiếp.

Một cách nữa là dùng "con trỏ trỏ tới mảng".

???+ note "Khác biệt giữa tên mảng và địa chỉ phần tử đầu của mảng"
    Trước đây đã nói rằng trong nhiều biểu thức C/C++, tên mảng được chuyển đổi
    thành con trỏ trỏ tới phần tử đầu tiên của mảng. Nhưng bản thân kiểu của định
    danh mảng vẫn là toàn bộ mảng, chứ không phải một phần tử đơn lẻ.

    ```cpp
    int main() { int a[5] = {1, 2, 3, 4, 5}; }
    ```

    Về mặt khái niệm, kiểu của định danh `a` trong đoạn mã là `int[5]`. Trong
    hầu hết biểu thức, `a` được chuyển đổi thành con trỏ tới phần tử đầu tiên,
    nên `a + 1` trỏ tới `a[1]`. Nếu lấy địa chỉ của toàn bộ mảng bằng `&a`, thì
    `&a + 1` mới dịch đi đúng độ dài của cả 5 biến kiểu `int`.

```cpp
int main() {
  int(*a)[5] = new int[5][5];
  int* p = a[2];
  a[2][1] = 1;
  delete[] a;
}
```

Cách này cũng thu được bộ nhớ liên tiếp, đồng thời có thể dùng dạng `a[n]` để
lấy địa chỉ đầu của hàng thứ n + 1 của mảng. Vì vậy, dùng dạng `a[r][c]` là có
thể truy cập phần tử có chỉ số `(r, c)`.

Vì con trỏ trỏ tới mảng cũng là một kiểu dữ liệu xác định, nên ngoại trừ chiều
thứ nhất của mảng, độ dài của các chiều còn lại đều phải là hằng có thể được
trình biên dịch xác định. Nếu không, trình biên dịch sẽ không thể dịch các biểu
thức như `a[n]`, trong đó `a` là con trỏ trỏ tới mảng.

## Con trỏ trỏ tới hàm

Phần giới thiệu về hàm nằm ở chương [Hàm trong C++](./func.md).

Nói đơn giản, để gọi một hàm, cần biết kiểu tham số, số lượng tham số và kiểu
giá trị trả về của hàm đó; các thông tin này thường được gọi chung là chữ ký
hàm.

Có thể gọi hàm thông qua con trỏ hàm. Đôi khi, một số hàm có cùng chữ ký; dùng
con trỏ hàm cho phép chọn hàm cần gọi **một cách động** theo quá trình chạy của
chương trình. Tức là không cần sửa đổi một hàm; chỉ cần thay đổi đối số
truyền vào nó, tức con trỏ hàm, là có thể làm thay đổi hành vi của hàm đó.

Giả sử có một số hàm phép toán hai ngôi dành cho kiểu `int`, thì tham số của hàm
là 2 giá trị `int`, và giá trị trả về cũng là `int`. Sau đây là một ví dụ sử
dụng con trỏ hàm:

```cpp
#include <iostream>

int (*binary_int_op)(int, int);

int foo1(int a, int b) { return a * b + b; }

int foo2(int a, int b) { return (a + b) * b; }

int main() {
  int choice;
  std::cin >> choice;
  if (choice == 1) {
    binary_int_op = foo1;
  } else {
    binary_int_op = foo2;
  }

  int m, n;
  std::cin >> m >> n;
  std::cout << binary_int_op(m, n);
}
```

???+ note "`&`, `*` và con trỏ hàm"
    Trong ngôn ngữ C, các cách viết như `void (*p)() = foo;`,
    `void (*p)() = &foo;`, `void (*p)() = *foo;`, `void (*p)() = ***foo` đều cho
    cùng một kết quả.

    Vì hàm, chẳng hạn `foo`, có thể được chuyển đổi ngầm định thành con trỏ trỏ
    tới hàm, nên cách viết `void (*p)() = foo;` là hợp lệ.

    Toán tử `&` lấy địa chỉ của đối tượng; điều này cũng đúng với hàm, nên cách
    viết `void (*p)() = &foo;` vẫn hợp lệ.

    Toán tử `*` trên con trỏ hàm lấy hàm mà con trỏ trỏ tới. Với cách viết như
    `**foo`, `*foo` thu được chính hàm `foo`, rồi ngay sau đó lại được chuyển
    đổi ngầm định thành con trỏ trỏ tới `foo`. Suy luận tương tự, kết quả cuối
    cùng của `**foo` vẫn là con trỏ hàm trỏ tới `foo`; có thể viết bao nhiêu dấu
    `*` tùy ý, kết quả vẫn như nhau.

    Tương tự, khi gọi hàm, các câu lệnh như `(*p)()` và `p()` là như nhau; có
    thể lược bỏ toán tử `*`.

    Tài liệu tham khảo: [Why do function pointer definitions work with any number of ampersands '&' or asterisks '\*'? - stackoverflow.com](https://stackoverflow.com/questions/6893285/why-do-function-pointer-definitions-work-with-any-number-of-ampersands-or-as)

Có thể dùng từ khóa `typedef` để khai báo kiểu của con trỏ hàm.

```cpp
typedef int (*p_bi_int_op)(int, int);
```

Từ đó, về sau có thể dùng kiểu `p_bi_int_op`, tức kiểu con trỏ trỏ tới hàm "có
2 tham số kiểu `int` và giá trị trả về cũng là `int`".

Ngoài con trỏ hàm, `std::function` cũng có thể dùng để tham chiếu hàm thuận tiện
hơn.

Con trỏ hàm cũng thường được dùng để triển khai "hàm callback".

## Tài liệu tham khảo và chú thích

[^note1]: Xem [Introduce the nullptr constant](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3042.htm)
