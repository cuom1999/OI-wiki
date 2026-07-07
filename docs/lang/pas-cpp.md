author: kexplorning, Ir1d, lvneg1

## Cài đặt nhanh C++ và cấu hình môi trường

Các bước sau đều được thực hiện trên hệ điều hành Windows.

### Sử dụng IDE

Có thể tham khảo nội dung trong các trang sau:

-   [Dev-C++](../tools/editor/devcpp.md)
-   [Code::Blocks](../tools/editor/codeblocks.md)

### Sử dụng trình soạn thảo mã + trình biên dịch + trình gỡ lỗi

Có thể tham khảo nội dung trong trang [VS Code](../tools/editor/vscode.md).
Trang web chính thức của Visual Studio Code có tài liệu giải thích cách cấu hình
C++. Thông thường, VS Code sẽ tiện hơn khi dùng kèm các tiện ích mở rộng; xem
[trang web chính thức của VS Code](https://code.visualstudio.com/).

## Tóm tắt nhanh cú pháp C++

Chương trình C++ luôn bắt đầu chạy từ hàm `main`.

Dấu ngoặc nhọn biểu thị điểm bắt đầu và kết thúc của một khối lệnh: `{` tương
đương với `begin` trong Pascal, còn `}` tương đương với `end`.

Tương tự Pascal, mỗi câu lệnh C++ phải kết thúc bằng dấu chấm phẩy `;`. Tuy
nhiên, sau dấu ngoặc nhọn đóng không cần dấu chấm phẩy, và cuối chương trình
cũng không cần dấu chấm `.`.

Về chú thích, `//` biểu thị chú thích trên một dòng, còn `/* */` biểu thị chú
thích dạng khối.

Theo thông lệ, hãy bắt đầu bằng chương trình Hello World.

### Hello World: chương trình C++ đầu tiên

```cpp
#include <iostream>  // nạp thư viện iostream

int main()  // phần main
{
  std::cout << "Hello World!" << std::endl;

  return 0;
}
```

Sau đó biên dịch và chạy thử để xem kết quả.

#### Giải thích ngắn gọn

Dòng đầu tiên, `#include <iostream>`, có nghĩa là nạp thư viện `iostream`.

??? note "Tệp thư viện trong Pascal"
    Pascal cũng có tệp thư viện, nhưng người mới học thường ít dùng đến.

`main` xuất hiện ở dòng thứ ba. Chương trình bắt đầu thực thi từ `main`.

Câu lệnh quan trọng nhất tiếp theo là

```cpp
std::cout << "Hello World!" << std::endl;
```

`std::cout` dùng để xuất dữ liệu. Một số chương trình C++ cũng viết trực tiếp là
`cout`.

??? note "Về tiền tố std::"
    Về vấn đề tiền tố `std::`, xem ghi chú "std là gì?" dưới
    [phần này](basic.md#cin-và-cout).

Toán tử `<<` ở giữa gợi hình ảnh luồng dữ liệu đang chảy; về bản chất, nó biểu
thị dữ liệu được "đẩy" ra luồng xuất như thế nào. Câu lệnh này có nghĩa là
`"Hello World!"` được đẩy vào luồng xuất trước, sau đó `std::endl` cũng được đẩy
vào luồng xuất.

`std::endl` dùng để **xuất** ký tự xuống dòng. Nó tương tự `writeln` trong
Pascal, nhưng trong C++ không có `coutln`. Điểm khác nhau giữa Pascal và C++ là
`write('Hello World!')` tương đương với `std::cout << "Hello World!"`, còn
`writeln('Hello World!')` tương đương với
`std::cout << "Hello World!" << std::endl`.

Trong câu này, `"Hello World!"` là chuỗi. Trong Pascal, chuỗi dùng dấu nháy đơn
`'` chứ không dùng dấu nháy kép; còn trong C++, chuỗi phải dùng dấu nháy kép. Ký
tự đặt trong dấu nháy đơn ở C++ có ý nghĩa khác, phần sau sẽ nhắc lại.

Đến đây, phần Hello World gần như đã được giải thích xong.

Có thể sẽ có thắc mắc `return 0` ở cuối chương trình nghĩa là gì, hoặc
`int main()` nghĩa là gì. **Tạm thời chưa cần bận tâm**; khi mới bắt đầu viết
chương trình, có thể xem nó như một khuôn mẫu để làm theo. Vì ở giai đoạn nhập
môn chưa dùng đến tham số trong `main`, không cần viết thành
`int main(int argc, char const *argv[])`.

#### Bài tập đơn giản

1.  Thử đổi chuỗi được in ra.
2.  Thử tìm hiểu ký tự thoát.

### Bài toán A+B: chương trình C++ thứ hai

Bài toán kinh điển A+B.

```cpp
#include <iostream>

int main() {
  int a, b, c;

  std::cin >> a >> b;

  c = a + b;

  std::cout << c << std::endl;

  return 0;
}
```

Ghi chú: mã trên có nhiều dòng trống; nếu chưa quen có thể bỏ bớt.

#### Giải thích ngắn gọn

`std::cin` dùng để đọc dữ liệu vào (`cin` tức là C-in), và cú pháp `>>` cũng
tương tự cú pháp xuất dữ liệu.

Trong các câu lệnh mới của ví dụ này, quan trọng nhất có hai câu. Câu đầu tiên
là câu lệnh khai báo biến.

```cpp
int a, b, c;
```

Có thể đã quen với cách khai báo biến trong Pascal:

```pas
var
a, b, c: integer;
```

Khai báo trong C++ bắt đầu bằng tên kiểu dữ liệu. Trong ví dụ này, `int` (kiểu
số nguyên) đứng đầu để cho biết các biến tiếp theo sẽ được khai báo.

Câu lệnh quan trọng tiếp theo là câu lệnh gán.

```cpp
c = a + b;
```

Đây là một khác biệt lớn giữa cú pháp Pascal và C++: phép gán trong Pascal là
`:=`, còn trong C++ là `=`; phép so sánh bằng trong C++ là `==`.

C++ cũng có thể khởi tạo giá trị cho biến ngay khi khai báo.

```cpp
int a = 0, b = 0, c = 0;
```

#### Bài tập đơn giản

1.  Viết lại đoạn mã, nộp lên OJ và đạt AC.
2.  Tham khảo thêm cú pháp nhập xuất trong [phần này](basic.md#scanf-và-printf),
    đồng thời thử tìm hiểu cách xuất dữ liệu có định dạng trong C++.

### Lời kết và bước tiếp theo

Đến đây, các nội dung cơ bản nhất đã được giới thiệu. Phần còn lại là tìm các cú
pháp tương ứng giữa Pascal và C++, cũng như các đặc điểm khác nhau của hai ngôn
ngữ.

Tuy vậy, trước khi tiếp tục, nên đọc trước phần
[Phạm vi biến: biến toàn cục và biến cục bộ](#phạm-vi-biến-biến-toàn-cục-và-biến-cục-bộ).

Có thể tận dụng <kbd>Alt</kbd>+<kbd>←</kbd> và <kbd>Alt</kbd>+<kbd>→</kbd> để quay
lại hoặc đi tới sau khi nhảy giữa các trang.

## Cú pháp

### Biến

#### Kiểu dữ liệu cơ bản

C++ nhìn chung giống Pascal ở phần này. Các kiểu thường gặp gồm:

-   `bool`: kiểu Boolean
-   `int`: kiểu số nguyên
-   `float`: kiểu số thực dấu phẩy động độ chính xác đơn
-   `double`: kiểu số thực dấu phẩy động độ chính xác kép
-   `char`: kiểu ký tự
-   `void`: kiểu rỗng

Trong C++, dấu nháy đơn được dùng riêng để biểu diễn một ký tự đơn (kiểu ký tự),
chẳng hạn `'a'`; còn chuỗi (mảng ký tự) phải dùng dấu nháy kép.

C++ còn có nhiều kiểu dữ liệu bổ sung. Xem
[Fundamental types - cppreference.com](https://en.cppreference.com/w/cpp/language/types).

#### Khai báo hằng

```cpp
const double PI = 3.1415926;
```

Nếu chưa rõ vấn đề liên quan đến mở rộng macro, nên dùng hằng thay vì định nghĩa
macro.

### Toán tử

Xem thêm bài [Phép toán](./op.md). Phần phụ lục cũng cung cấp bảng đối
chiếu cú pháp toán tử và hàm toán học.

### Điều kiện

#### Câu lệnh `if`

```pas
if (a = b) and (a > 0) and (b > 0) then
    begin
        b := a;
    end
else
    begin
        a := b;
    end;
```

```cpp
if (a == b && a > 0 && b > 0) {
  b = a;
} else {
  a = b;
}
```

Phép toán Boolean và phép so sánh:

-   `and -> &&`
-   `or -> ||`
-   `not -> !`
-   `= -> ==`
-   `<> -> !=`

Ghi chú:

1.  `and` trong Pascal và `&&` trong C++ có độ ưu tiên khác nhau; trong C++ không
    cần đặt thêm ngoặc quanh từng điều kiện.
2.  Trong Pascal, so sánh bằng là `=`, phép gán là `:=`; trong C++, so sánh bằng
    là `==`, phép gán là `=`.
3.  Nếu viết `a = b` thay vì `a == b` trong ngoặc của câu lệnh `if`, chương trình
    sẽ không báo lỗi. Nó sẽ gán `b` cho `a`, rồi toàn bộ biểu thức gán `a = b` sẽ
    có giá trị bằng giá trị của `a` sau khi gán xong.
4.  Trong C++, không cần cân nhắc có nên thêm dấu chấm phẩy sau `end` hay không.
5.  Trong phép toán Boolean của C++, giá trị không phải Boolean có thể tự động
    chuyển thành Boolean.

???+ warning "Nhắc lỗi dễ mắc"
    Đặc biệt lưu ý: **đừng viết `==` thành `=`!**

    Vì cú pháp C/C++ linh hoạt hơn Pascal, nếu viết `if (a=b)` trong câu lệnh
    điều kiện, chương trình vẫn chạy tiếp bình thường, vì trong C++ biểu thức
    `a=b` có giá trị trả về.

#### `case` và `switch`

Không dùng quá nhiều, nên phần này không triển khai chi tiết.

Cần lưu ý: C++ không có `1..n`, và cũng không có bất đẳng thức liên tiếp (ví dụ
`1 < x < 2`).

### Vòng lặp

Ba loại vòng lặp sau, với sáu đoạn mã, đều thực hiện cùng một chức năng.

#### Vòng lặp `while`

`while` trong hai ngôn ngữ tương đồng. Đoạn C++ trong mục này không phải chương
trình hoàn chỉnh; một số phần khung mẫu được lược bỏ. Các phần sau cũng tương
tự.

```pas
var i: integer;

begin
    i := 1;
    while i <= 10 do
        begin
            write(i,' ');
            inc(i); // hoặc i := i + 1;
        end;
end.
```

```cpp
int i = 1;
while (i <= 10) {
  std::cout << i << " ";
  i++;
}
```

#### Vòng lặp `for`

Câu lệnh `for` của C++ khác đáng kể.

```pas
var i: integer;

begin
    for i:= 1 to 10 do
        begin
            write(i, ' ');
        end;
end.
```

```cpp
for (int i = 1; i <= 10; i++) {
  std::cout << i << " ";
}
```

Ghi chú:

1.  Dòng `for (int i = 1; i <= 10; i++){` chứa nhiều nội dung; trong `for` có ba
    câu lệnh.
2.  Câu lệnh đầu tiên `int i = 1;` khai báo một biến cục bộ `i` và khởi tạo nó.
    Thiết kế này linh hoạt hơn Pascal.
3.  Câu lệnh thứ hai `i <= 10;` là điều kiện để xác định vòng lặp có tiếp tục hay
    không.
4.  Câu lệnh thứ ba `i++` được thực hiện ở cuối mỗi vòng lặp, ý nghĩa gần giống
    `inc(i)` trong Pascal. Viết `++i` trong vòng lặp này cũng cho kết quả như
    nhau. Sự khác nhau giữa `i++` và `++i` có thể tham khảo trong tài liệu khác.

#### Vòng lặp `repeat until` và `do while`

`repeat until` và `do while` không giống nhau. So sánh các đoạn mã sau:

```pas
var i: integer;

begin
    i := 1;
    repeat
        write(i, ' ');
        inc(i);
    until i = 11;
end.
```

```cpp
int i = 1;
do {
  std::cout << i << " ";
  i++;
} while (i <= 10);
```

#### Điều khiển vòng lặp

Trong C++, `break` có tác dụng giống Pascal: thoát khỏi vòng lặp.

`continue` cũng tương tự: bỏ qua phần còn lại của vòng lặp hiện tại và chuyển
sang lần lặp tiếp theo (quay về đầu vòng lặp).

### Mảng và chuỗi

#### Mảng độ dài thay đổi: kiểu thư viện chuẩn `vector`

Tham khảo nội dung trong trang [Container tuần tự](csl/sequence-container.md).

Thư viện chuẩn C++ cung cấp `vector`, tương đương với mảng có độ dài thay đổi.
Trước khi dùng cần nạp tệp thư viện.

```cpp
#include <iostream>
#include <vector>  // nạp thư viện vector

int main() {
  std::vector<int> a;  // khai báo vector a, ban đầu là vector rỗng
  int n;

  std::cin >> n;
  // đọc a
  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    a.push_back(t);  // đưa số t vừa đọc vào cuối vector a; độ phức tạp O(1)
    /* Không thể dùng truy cập chỉ số để gán giá trị trong trường hợp này, vì khi khai báo,
    kích thước của a vẫn rỗng.
    Dùng `a[i] = t;` tại đây là cách làm sai.
    */
  }

  // in ra tất cả các số đã đọc vào a
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ", ";  // !lưu ý, số đầu tiên trong a là a[0];
    // Nếu chỉ số vượt biên, kết quả là không xác định, chứ không báo lỗi
  }
  std::cout << std::endl;

  return 0;
}
```

Truy cập phần tử mảng trong C++ gần giống Pascal, nhưng có một khác biệt quan
trọng: phần tử đầu tiên của mảng là `a[0]`, còn trong Pascal có thể tự chỉ định
chỉ số bắt đầu.

#### Chuỗi: kiểu thư viện chuẩn `string`

Tham khảo nội dung trong trang [string](csl/string.md).

Thư viện chuẩn C++ cung cấp `string`. Một số thao tác trên `string` giống với
`vector`; kiểu này cũng cần nạp tệp thư viện trước khi dùng.

```cpp
#include <iostream>
#include <string>

int main() {
  std::string s;  // khai báo string s

  std::cin >> s;  // đọc s;
  // Khi đọc, tất cả ký tự trắng ở đầu (dấu cách, xuống dòng, tab) sẽ bị bỏ qua;
  // chuỗi được đọc đến trước ký tự trắng tiếp theo thì dừng.

  std::cout << s << std::endl;

  return 0;
}
```

#### Mảng kiểu C

Tham khảo nội dung trong trang [Mảng](array.md).

Nếu cần dùng mảng có độ dài thay đổi, nên dùng `vector`, không nên dùng mảng kiểu
C.

Mảng kiểu C có quan hệ chặt chẽ với con trỏ, nên bài này không trình bày thêm.

## Những điểm khác biệt quan trọng

### Phạm vi biến: biến toàn cục và biến cục bộ

C++ gần như cho phép khai báo biến ở **bất kỳ đâu**. Tham khảo thêm [Phạm vi
biến](var.md#phạm-vi-của-biến).

Khi viết thủ tục/hàm Pascal, người viết dễ quên khai báo biến cục bộ `i` hoặc `j`.
Thông thường chương trình chính lại có vòng lặp, nên trong đa số trường hợp `i`
và `j` đều là biến toàn cục. Khi đó, việc thao tác với `i` trong thủ tục/hàm rất
dễ gây lỗi. Tệ hơn nữa, nếu quên khai báo các biến cục bộ kiểu này, trình biên
dịch không báo lỗi và chương trình vẫn chạy. (Rất nhiều lỗi khó tìm xuất phát từ
đây.)

Vì vậy, khi dùng C++, nên khai báo biến, chẳng hạn `i` dùng trong vòng lặp, theo
nguyên tắc: **đừng dùng biến toàn cục nếu có thể dùng biến cục bộ**. Cách này
giúp tránh việc tên biến trong hàm (ví dụ `i`) bị xung đột.

??? note "Ghi chú bổ sung"
    Pascal có thể tránh vấn đề này ở một mức độ nhất định bằng cách mô phỏng cách
    làm của C++: trong chương trình chính chỉ gọi thủ tục/hàm, không khai báo các
    biến toàn cục dễ xung đột tên như `i`, `j`; nếu cần vòng lặp thì viết thêm
    một thủ tục riêng để gọi.

### C++ có thể tự động chuyển đổi kiểu

```cpp
int i = 2;
if (i) {  // i = 0 trả về false, các giá trị khác trả về true
  std::cout << "true";
} else {
  std::cout << "false";
}
```

Không chỉ `int` có thể chuyển thành `bool`, `int` và `float` cũng có thể chuyển
đổi qua lại. Trong Pascal, có thể gán số nguyên cho số thực, nhưng không thể làm
ngược lại. C++ không gặp vấn đề này.

```cpp
int a;
a = 3.2;      // lúc này a = 3
float b = a;  // lúc này b = 3.0
```

Việc phân biệt `/` là phép chia nguyên hay phép chia số thực được quyết định dựa
trên kiểu của số bị chia và số chia.

```cpp
float a = 32 / 10;    // kết quả của 32/10 là 3 (chia nguyên); a = 3.0
float b = 32.0 / 10;  // kết quả của 32.0/10 là 3.2; b = 3.2
```

`pow(a, b)` tính $a^b$. Hàm này trả về kiểu số thực; nếu dùng trực tiếp để tính
lũy thừa số nguyên thì nhờ chuyển đổi tự động, không cần lo nó báo lỗi.

```cpp
int a = pow(2, 3);  // tính 2^3
```

Ngoài ra còn có chuyển đổi qua lại giữa `char` và `int`.

```cpp
char a = 48;              // ASCII 48 là '0'
int b = a + 1;            // b = 49
std::cout << (a == '0');  // true xuất ra 1
```

Trong C++, `char` và `bool` về bản chất đều là kiểu số nguyên.

Chi tiết xem bài
[Implicit conversions - cppreference.com](https://en.cppreference.com/w/cpp/language/implicit_conversion).

### Nhiều câu lệnh C++ có giá trị trả về

Ví dụ thường gặp là đọc dữ liệu với số lượng không cố định. Đôi khi cần đọc cho
đến khi hết dữ liệu, chẳng hạn tính tổng một dãy số có thể nằm trên nhiều dòng
cho đến cuối tệp. Cách làm là:

??? note "Cuối tệp EOF"
    EOF là ký hiệu cuối tệp. Trong dòng lệnh Windows, nhập bằng
    <kbd>Ctrl</kbd>+<kbd>Z</kbd> (sau đó cần nhấn <kbd>Enter</kbd>); trên hệ
    Unix-like, nhập bằng <kbd>Ctrl</kbd>+<kbd>D</kbd>.

```cpp
#include <iostream>

int main() {
  int sum = 0, a = 0;

  while (std::cin >> a) {
    sum += a;
  }
  std::cout << sum << std::endl;

  return 0;
}
```

Nguyên lý: trong `while (std::cin >> a)`, nếu `std::cin >> a` gặp lỗi khi nhập
hoặc gặp cuối tệp, nó sẽ trả về `false`, làm vòng lặp dừng lại.

### Hàm

C++ chỉ có hàm, không có thủ tục, nhưng có `void`; không có biến giá trị hàm như
Pascal, nhưng có `return`.

Ví dụ đối chiếu hàm Pascal và hàm C++:

```pas
function abs(x:integer):integer;
begin
    if x < 0 then
        begin
            abs := -x;
        end
    else
        begin
            abs := x;
        end;
end;
```

```cpp
int abs(int x) {
  if (x < 0) {
    return -x;
  } else {
    return x;
  }
}
```

Trong C++, khai báo hàm `int abs` định nghĩa hàm `abs()` và cho biết giá trị trả
về có kiểu `int` (số nguyên). Giá trị trả về của hàm là giá trị do câu lệnh
`return` đưa ra.

Nếu không muốn có giá trị trả về (tức "thủ tục" trong Pascal), dùng `void`.
`void` nghĩa là "rỗng", không trả về gì cả.

```pas
var ans: integer;

procedure printAns(ans:integer);
begin
    writeln(ans);
end;

begin
    ans := 10;
    printAns(ans);
end.
```

```cpp
#include <iostream>

void printAns(int ans) {
  std::cout << ans << std::endl;

  return;
}

int main() {
  int ans = 10;
  printAns(ans);

  return 0;
}
```

`return` của C++ khác rõ rệt so với việc gán giá trị cho biến hàm trong Pascal.
Trong C++, `return` trả về một giá trị; sau khi thực thi câu lệnh này, hàm kết
thúc ngay. Còn trong Pascal, gán giá trị cho biến hàm không làm thoát khỏi hàm,
mà chương trình vẫn tiếp tục thực thi. Vì vậy, nếu Pascal cần dừng hàm/thủ tục ở
một chỗ nào đó, cần thêm lệnh `exit`. C++ thì không cần; nếu cần dừng ở đâu, có
thể dùng `return`. Ví dụ:

```cpp
#include <iostream>

void printWarning(int x) {
  if (x >= 0) {
    return;  // câu lệnh này tương đương với `exit;` trong Pascal
  }
  std::cout << "Cảnh báo: đầu vào là số âm.";
}

int main() {
  int a;

  std::cin >> a;
  printWarning(a);

  return 0;
}
```

Theo một nghĩa nào đó, nếu muốn hàm `abs` ở trên tương đương nghiêm ngặt với
phiên bản C++, cần viết như sau:

```pas
function abs(x:integer):integer;
begin
    if x < 0 then
        begin
            abs := -x; exit; // !lưu ý chỗ này
        end
    else
        begin
            abs := x;  exit; // !lưu ý chỗ này
        end;
end;
```

```cpp
int abs(int x) {
  if (x < 0) {
    return -x;
  } else {
    return x;
  }
}
```

???+ note "Nhắc nhở đặc biệt"
    Trong C++, `exit` là thoát khỏi chương trình; đừng tiện tay gõ `exit`; nên
    dùng `return`.

C++ coi cả hàm lẫn thủ tục đều là hàm, kể cả `main` cũng không ngoại lệ. Ví dụ
khi viết `int main`, C++ xem `main` là một hàm kiểu số nguyên; giá trị trả về là
`0`. Đây là một quy ước thông dụng: trả về `0` nghĩa là chương trình kết thúc
bình thường.

Các tham số trong `main(int argc, char const *argv[])` là `int argc` và
`char const *argv[]`; ý nghĩa của chúng có thể tham khảo trong tài liệu khác.

### Truyền tham số trong hàm

C++ không có từ khóa `var` của Pascal để thay đổi tham số được truyền vào, nhưng
C++ có thể dùng tham chiếu và con trỏ để đạt hiệu quả tương tự.

```pas
var a, b: integer;

procedure swap(var x,y:integer);
var temp:integer;
begin
    temp := x;
    x := y;
    y := temp;
end;

begin
    a := 10; b:= 20;
    swap(a, b);
    writeln(a, ' ', b);
end.
```

```cpp
// Mã dùng con trỏ
#include <iostream>

void swap(int* x, int* y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int a = 10, b = 20;
  swap(&a, &b);
  std::cout << a << " " << b;

  return 0;
}
```

Đoạn C++ này **liên quan đến con trỏ**. Con trỏ là nội dung tương đối phức tạp,
nên đọc thêm tài liệu liên quan trước khi dùng rộng rãi.

```cpp
// Mã dùng tham chiếu
#include <iostream>

void swap(int& x, int& y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

int main(int argc, char const* argv[]) {
  int a = 10, b = 20;
  swap(a, b);
  std::cout << a << " " << b;

  return 0;
}
```

Đoạn C++ này liên quan đến **kiểu tham chiếu**. Khi dùng tham chiếu để
gọi một số thư viện STL hoặc thư viện viết bằng template, có thể gặp một số vấn
đề; lúc đó cần tự khai báo kiểu riêng. Tài liệu cụ thể có thể tra trong *C++
Primer* bản thứ năm hoặc tài liệu trên mạng.

C++ còn có các cách truyền tham số khác. Một trong số đó là **truyền tham số bằng
cách dùng biến toàn cục**; nếu chưa biết dùng con trỏ, có thể tạm dùng cách này.
Khuyết điểm của cách này là không có khung ngăn xếp riêng để lưu dữ liệu, nên
**không thể truyền tham số trong hàm đệ quy**. Trừ khi tự viết ngăn xếp; lưu ý,
tự viết ngăn xếp cũng là một cách vượt qua giới hạn ngăn xếp hệ thống.

## Thư viện chuẩn C++ và tài liệu tham khảo

Đừng tự tạo lại bánh xe (trừ khi để luyện tập). Trước khi tự viết một chức năng,
nên xem trước đã có hàm hoặc cấu trúc dữ liệu tương ứng hay chưa.

### Thư viện chuẩn C++

Trong thư viện chuẩn C++, `<algorithm>` có nhiều hàm hữu ích như sắp xếp nhanh,
tìm kiếm nhị phân, v.v.; có thể gọi ngay. Tham khảo trang
[Thuật toán STL](csl/algorithm.md).

Ngoài ra còn có container STL, chẳng hạn mảng, vector (mảng có kích thước thay
đổi), hàng đợi, ngăn xếp, v.v., kèm nhiều hàm hỗ trợ. Tham khảo trang [Giới thiệu
container STL](csl/container.md).

Nếu muốn tìm các hàm thao tác chuỗi, xem:

-   [std::basic\_string - cppreference.com](https://en.cppreference.com/w/cpp/string/basic_string)
-   [`<string>` - C++ Reference](https://www.cplusplus.com/reference/string/)

Con trỏ trong C/C++ là một cơ chế linh hoạt; có thể tham khảo trang
[Con trỏ](pointer.md). Nếu muốn hiểu kỹ con trỏ, nên tìm một cuốn sách hoặc sổ
tay tham khảo để đọc cẩn thận.

### Gỡ lỗi và mẹo

-   [Lỗi thường gặp](../contest/common-mistakes.md)
-   [Mẹo thường gặp](../contest/common-tricks.md)

### Tài liệu về ngôn ngữ C++

-   [Tài nguyên học tập](../contest/resources.md)
-   [cppreference.com](https://en.cppreference.com/): tài liệu tham khảo C/C++
    quan trọng nhất
-   [C++ Tutorial - Runoob](https://www.runoob.com/cplusplus/cpp-tutorial.html)
-   [C++ Language - C++ Tutorials](https://www.cplusplus.com/doc/tutorial/)
-   [Reference - C++ Reference](https://www.cplusplus.com/reference/)
-   [C++ Standard Library - Wikipedia](https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library)
-   [The Ultimate Question of Programming, Refactoring, and Everything](https://www.gitbook.com/book/alexastva/the-ultimate-question-of-programming-refactoring-/details)
-   [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

## Lời bạt

Đến đây, bài viết có thể không còn giống một bài "cấp cứu" ngắn gọn, vì vẫn còn
rất nhiều thứ chưa được nhắc tới. Điều đó cũng khó tránh.

Dù mục tiêu là "cấp cứu", nhiều nội dung như cách chuyển chuỗi thành số, cách tìm
ký tự trong chuỗi, v.v. không phù hợp với một bài viết ngắn gọn. Nếu viết hết
những thứ đó ra thì đây sẽ trở thành giáo trình nhập môn C++, nên cần tận dụng
đầy đủ Wiki này, sổ tay tham khảo và công cụ tìm kiếm.

Cần chỉ ra một điểm: nhiều cú pháp C++ nói ở trên đến từ ngôn ngữ C. Tiêu đề nếu
viết chính xác hơn có lẽ nên là "Bài cấp cứu chuyển từ Pascal sang C/C++".

Pascal là một ngôn ngữ phổ biến vào nửa sau thế kỷ trước. Nó ra đời sớm hơn C,
nhưng cùng với sự phổ biến của hệ thống UNIX và việc Microsoft sử dụng C, Pascal
nay đã trở thành lịch sử. Pascal về sau vẫn có phát triển, chẳng hạn dự án trình
biên dịch mã nguồn mở Free Pascal đã bổ sung đặc điểm hướng đối tượng (ngôn ngữ
Delphi). Hiện nay, ngoài việc dùng trong thi lập trình, Pascal có một đặc điểm mà
các ngôn ngữ khác không có: hỗ trợ biên dịch cho nhiều máy cũ, chẳng hạn Gameboy
và máy chơi game Nintendo từ thế kỷ trước. Một công dụng khác là xuất hiện dưới
dạng mã giả (mã giả phong cách Pascal) trong nhiều sách giáo khoa.

Cuối cùng, cộng đồng Pascal hiện nhỏ hơn cộng đồng C/C++; tài liệu trợ giúp và
giáo trình cho C/C++ cũng phong phú hơn. Tiếng Anh là kỹ năng quan trọng khi đọc
tài liệu kỹ thuật. Trên thế giới còn nhiều ngôn ngữ lập trình, và ngành khoa học
máy tính cùng kỹ thuật máy tính không chỉ có thi lập trình và ngôn ngữ lập trình.

### Tài liệu tham khảo về ngôn ngữ Pascal trong bài này

-   [Lazarus wiki](https://wiki.freepascal.org/)
-   [Free Pascal Reference guide](https://freepascal.org/docs-html/current/ref/ref.html)

## Phụ lục: bảng đối chiếu cú pháp toán tử và hàm toán học giữa Pascal và C++

Chỉ bao gồm các toán tử và hàm thường dùng nhất.

### Số học cơ bản

|                | Pascal    | C++     |
| -------------- | --------- | ------- |
| Cộng           | `a + b`   | `a + b` |
| Trừ            | `a - b`   | `a - b` |
| Nhân           | `a * b`   | `a * b` |
| Chia nguyên    | `a div b` | `a / b` |
| Chia số thực   | `a / b`   | `a / b` |
| Lấy phần dư    | `a mod b` | `a % b` |

### Logic

|          | Pascal    | C++                   |
| -------- | --------- | --------------------- |
| Phủ định | `not(a)`  | `!a`                  |
| Và       | `a and b` | `a && b`              |
| Hoặc     | `a or b`  | <code>a \|\| b</code> |

### So sánh

|                   | Pascal   | C++      |
| ----------------- | -------- | -------- |
| Bằng              | `a = b`  | `a == b` |
| Khác              | `a <> b` | `a != b` |
| Lớn hơn           | `a > b`  | `a > b`  |
| Nhỏ hơn           | `a < b`  | `a < b`  |
| Lớn hơn hoặc bằng | `a >= b` | `a >= b` |
| Nhỏ hơn hoặc bằng | `a <= b` | `a <= b` |

### Gán

| Pascal                          | C++      |
| -------------------------------- | -------- |
| `a := b`                        | `a = b`  |
| `a := a + b`                    | `a += b` |
| `a := a - b`                    | `a -= b` |
| `a := a * b`                    | `a *= b` |
| `a := a div b` hoặc `a := a / b` | `a /= b` |
| `a := a mod b`                  | `a %= b` |

### Tăng/giảm một đơn vị

|       | Pascal   | C++   |
| ----- | -------- | ----- |
| Tăng  | `inc(a)` | `a++` |
| Tăng  | `inc(a)` | `++a` |
| Giảm  | `dec(a)` | `a--` |
| Giảm  | `dec(a)` | `--a` |

### Hàm toán học

Cần nạp thư viện `<cmath>` trước khi dùng.

|                   | Pascal     | C++                  |
| ----------------- | ---------- | -------------------- |
| Giá trị tuyệt đối | `abs(a)`   | `abs(a)` (số nguyên) |
| Giá trị tuyệt đối | `abs(a)`   | `fabs(a)` (số thực)  |
| $a^b$             | N/A[^ref1] | `pow(a, b)`          |
| Cắt bỏ phần lẻ    | `trunc(a)` | `trunc(a)`           |
| Làm tròn          | `round(a)` | `round(a)`           |

[^ref1]: Extended Pascal có `a**b`, nhưng cần nạp thư viện `Math`.

Các hàm khác, xem:

-   [Các hàm toán học thường dùng - cppreference.com](https://en.cppreference.com/w/cpp/numeric/math)
