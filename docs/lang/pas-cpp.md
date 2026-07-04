author: kexplorning, Ir1d, lvneg1

## Cài đặt nhanh C++ và cấu hình môi trường

Các bước dưới đây đều được thực hiện trên hệ điều hành Windows.

### Sử dụng IDE

Bạn có thể tham khảo nội dung trong các trang sau:

-   [Dev-C++](../tools/editor/devcpp.md)
-   [Code::Blocks](../tools/editor/codeblocks.md)

### Sử dụng trình soạn thảo mã + trình biên dịch + trình gỡ lỗi

Bạn có thể tham khảo nội dung trong trang [VS Code](../tools/editor/vscode.md). Trang web chính thức của Visual Studio Code có tài liệu giải thích cách cấu hình C++. Nói chung, VS Code sẽ tiện hơn khi dùng kèm các tiện ích mở rộng; xem [trang web chính thức của VS Code](https://code.visualstudio.com/).

## Tóm tắt nhanh cú pháp C++

Chương trình C++ luôn bắt đầu chạy từ phần `main`.

Dấu ngoặc nhọn biểu thị điểm bắt đầu và kết thúc của một khối lệnh: `{` tương đương với `begin` trong Pascal, còn `}` tương đương với `end`.

Lưu ý rằng, giống Pascal, mỗi câu lệnh C++ phải kết thúc bằng dấu chấm phẩy `;`. Tuy nhiên, sau dấu ngoặc nhọn đóng không cần dấu chấm phẩy, và cuối chương trình cũng không cần dấu chấm `.`.

Về chú thích, `//` biểu thị chú thích trên một dòng, còn `/* */` biểu thị chú thích dạng khối.

Theo thông lệ, hãy xem Hello World trước.

### Hello World: chương trình C++ đầu tiên

```cpp
#include <iostream>  // nap thu vien iostream

int main()  // phan main
{
  std::cout << "Hello World!" << std::endl;

  return 0;
}
```

Sau đó hãy biên dịch và chạy thử để xem kết quả.

#### Giải thích ngắn gọn

Dòng đầu tiên, `#include <iostream>`, có nghĩa là nạp thư viện `iostream`.

??? note "Tệp thư viện trong Pascal"
    Pascal thật ra cũng có tệp thư viện, chỉ là nhiều bạn chưa từng dùng đến.

Bạn có thấy `main` ở dòng thứ ba không? Chương trình bắt đầu thực thi từ `main`.

Câu lệnh quan trọng nhất tiếp theo là

```cpp
std::cout << "Hello World!" << std::endl;
```

`std::cout` là lệnh xuất dữ liệu. Có thể bạn đã từng thấy một số chương trình C++ viết trực tiếp là `cout`.

??? note "Về tiền tố std::"
    Về vấn đề tiền tố `std::`, xem ghi chú "std là gì?" dưới [phần này](basic.md#cin-%E4%B8%8E-cout).

Toán tử `<<` ở giữa gợi hình ảnh luồng dữ liệu đang chảy; thực chất nó biểu thị dữ liệu được "đẩy" ra luồng xuất như thế nào. Câu lệnh này có nghĩa là `"Hello World!"` được đẩy vào luồng xuất trước, sau đó `std::endl` cũng được đẩy vào luồng xuất.

`std::endl` là lệnh **xuất** ký tự xuống dòng. Nó tương tự `writeln` trong Pascal, nhưng trong C++ không có `coutln`. Điểm khác nhau giữa Pascal và C++ là `write('Hello World!')` tương đương với `std::cout << "Hello World!"`, còn `writeln('Hello World!')` tương đương với `std::cout << "Hello World!" << std::endl`.

Ở đây `"Hello World!"` là chuỗi. Trong Pascal, chuỗi dùng dấu nháy đơn `'` chứ không dùng dấu nháy kép; còn trong C++, chuỗi phải dùng dấu nháy kép. Ký tự đặt trong dấu nháy đơn ở C++ có ý nghĩa khác, phần sau sẽ nhắc lại.

Đến đây, phần Hello World gần như đã được giải thích xong.

Có thể một số bạn sẽ hỏi `return 0` phía sau nghĩa là gì, hoặc `int main()` nghĩa là gì. **Tạm thời đừng bận tâm**; khi mới bắt đầu viết chương trình, cứ xem nó như một khuôn mẫu để viết theo (ở đây cũng dùng đúng khuôn mẫu đó). Vì khi nhập môn bạn sẽ chưa dùng đến tham số trong `main`, nên không cần viết thành `int main(int argc, char const *argv[])`.

#### Bài tập đơn giản

1.  Thử đổi chuỗi được in ra.
2.  Thử tìm hiểu ký tự thoát.

### A+B Problem: chương trình C++ thứ hai

Bài kinh điển A+B Problem.

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

Ghi chú: mã trên có khá nhiều dòng trống; nếu chưa quen bạn có thể bỏ bớt.

#### Giải thích ngắn gọn

`std::cin` dùng để đọc dữ liệu vào (`cin` tức là C-in), và cú pháp `>>` cũng tương tự cú pháp xuất dữ liệu.

Trong các câu lệnh mới ở đây, quan trọng nhất có hai câu. Câu đầu tiên là câu lệnh khai báo biến.

```cpp
int a, b, c;
```

Có thể bạn đã quen với cách khai báo biến trong Pascal:

```pas
var
a, b, c: integer;
```

Khai báo trong C++ bắt đầu trực tiếp bằng tên kiểu dữ liệu. Ở đây, `int` (kiểu số nguyên) đứng đầu để cho biết các biến tiếp theo sẽ được khai báo.

Câu lệnh quan trọng tiếp theo là câu lệnh gán.

```cpp
c = a + b;
```

Đây là một khác biệt lớn giữa cú pháp Pascal và C++: phép gán trong Pascal là `:=`, còn trong C++ là `=`; phép so sánh bằng trong C++ là `==`.

C++ cũng có thể khởi tạo giá trị cho biến ngay khi khai báo.

```cpp
int a = 0, b = 0, c = 0;
```

#### Bài tập đơn giản

1.  Viết lại đoạn mã, nộp lên OJ và đạt AC.
2.  Tham khảo thêm cú pháp nhập xuất trong [phần này](basic.md#scanf-%E4%B8%8E-printf), đồng thời thử tìm hiểu cách xuất dữ liệu có định dạng trong C++.

### Lời kết và bước tiếp theo

Đến đây, bạn đã nắm được một số nội dung cơ bản nhất. Phần còn lại là tìm các cú pháp tương ứng giữa Pascal và C++, cũng như các đặc điểm khác nhau của hai ngôn ngữ.

Tuy vậy, trước khi tiếp tục, rất nên đọc trước phần [Phạm vi biến: biến toàn cục và biến cục bộ](#%E5%8F%98%E9%87%8F%E4%BD%9C%E7%94%A8%E5%9F%9F%E5%85%A8%E5%B1%80%E5%8F%98%E9%87%8F%E4%B8%8E%E5%B1%80%E9%83%A8%E5%8F%98%E9%87%8F).

Hãy tận dụng <kbd>Alt</kbd>+<kbd>←</kbd> và <kbd>Alt</kbd>+<kbd>→</kbd> để quay lại hoặc đi tới sau khi nhảy giữa các trang.

## Cú pháp

### Biến

#### Kiểu dữ liệu cơ bản

C++ về cơ bản khá giống Pascal. Các kiểu thường gặp gồm:

-   `bool`: kiểu Boolean
-   `int`: kiểu số nguyên
-   `float`: kiểu số thực dấu phẩy động độ chính xác đơn
-   `double`: kiểu số thực dấu phẩy động độ chính xác kép
-   `char`: kiểu ký tự
-   `void`: kiểu rỗng

Trong C++, dấu nháy đơn được dùng riêng để biểu diễn một ký tự đơn (kiểu ký tự), chẳng hạn `'a'`; còn chuỗi (mảng ký tự) phải dùng dấu nháy kép.

C++ còn có nhiều kiểu dữ liệu bổ sung. Xem [Fundamental types - cppreference.com](https://zh.cppreference.com/w/cpp/language/types).

#### Khai báo hằng

```cpp
const double PI = 3.1415926;
```

Nếu chưa rõ vấn đề liên quan đến mở rộng macro, nên dùng hằng thay vì định nghĩa macro.

### Toán tử

Hãy tham khảo trực tiếp bài [Phép toán](./op.md). Phần phụ lục cũng cung cấp bảng đối chiếu cú pháp toán tử và hàm toán học.

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

1.  `and` trong Pascal và `&&` trong C++ có độ ưu tiên khác nhau; trong C++ không cần đặt thêm ngoặc quanh từng điều kiện.
2.  Trong Pascal, so sánh bằng là `=`, phép gán là `:=`; trong C++, so sánh bằng là `==`, phép gán là `=`.
3.  Nếu viết `a = b` thay vì `a == b` trong ngoặc của câu lệnh `if`, chương trình sẽ không báo lỗi. Nó sẽ gán `b` cho `a`, rồi toàn bộ biểu thức gán `a = b` sẽ có giá trị bằng giá trị của `a` sau khi gán xong.
4.  Trong C++, bạn không cần suy nghĩ có nên thêm dấu chấm phẩy sau `end` hay không.
5.  Trong phép toán Boolean của C++, giá trị không phải Boolean có thể tự động chuyển thành Boolean.

???+ warning "Nhắc lỗi dễ mắc"
    Đặc biệt chú ý: **đừng viết `==` thành `=`!**

    Vì cú pháp C/C++ linh hoạt hơn Pascal, nếu viết `if (a=b)` trong câu lệnh điều kiện, chương trình vẫn chạy tiếp bình thường, vì trong C++ biểu thức `a=b` có giá trị trả về.

#### `case` và `switch`

Không dùng quá nhiều, nên ở đây không triển khai chi tiết.

Cần chú ý: C++ không có `1..n`, và cũng không có bất đẳng thức liên tiếp (ví dụ `1 < x < 2`).

### Vòng lặp

Ba loại vòng lặp dưới đây, với sáu đoạn mã, đều thực hiện cùng một chức năng.

#### Vòng lặp `while`

`while` rất giống nhau. (Đoạn C++ ở đây không phải chương trình hoàn chỉnh; một số phần khung mẫu được lược bỏ. Các phần sau cũng tương tự.)

```pas
var i: integer;

begin
    i := 1;
    while i <= 10 do
        begin
            write(i,' ');
            inc(i); // hoac i := i + 1;
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

Câu lệnh `for` của C++ rất khác.

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

1.  Dòng `for (int i = 1; i <= 10; i++){` chứa khá nhiều nội dung; trong `for` có ba câu lệnh.
2.  Câu lệnh đầu tiên `int i = 1;` khai báo một biến cục bộ `i` và khởi tạo nó. (Thiết kế này hợp lý hơn Pascal khá nhiều.)
3.  Câu lệnh thứ hai `i <= 10;` là điều kiện để xác định vòng lặp có tiếp tục hay không.
4.  Câu lệnh thứ ba `i++` được thực hiện ở cuối mỗi vòng lặp, ý nghĩa gần giống `inc(i)` trong Pascal. Viết `++i` ở đây cũng như nhau. Sự khác nhau giữa `i++` và `++i` hãy tham khảo tài liệu khác.

#### Vòng lặp `repeat until` và `do while`

Chú ý, `repeat until` và `do while` không giống nhau. Hãy so sánh các đoạn mã dưới đây:

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

`continue` cũng tương tự: bỏ qua phần còn lại của vòng lặp hiện tại và chuyển sang lần lặp tiếp theo (quay về đầu vòng lặp).

### Mảng và chuỗi

#### Mảng độ dài thay đổi: kiểu thư viện chuẩn Vector

Hãy tham khảo nội dung trong trang [Container tuần tự](csl/sequence-container.md).

Thư viện chuẩn C++ cung cấp `vector`, tương đương với mảng có độ dài thay đổi. Trước khi dùng cần nạp tệp thư viện.

```cpp
#include <iostream>
#include <vector>  // nap thu vien vector

int main() {
  std::vector<int> a;  // khai bao vector a va dinh nghia a la doi tuong vector rong
  int n;

  std::cin >> n;
  // doc a
  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    a.push_back(t);  // dua so t vua doc vao cuoi vector a; thao tac nay co do phuc tap O(1)
    /* Khong the dung truy cap chi so de gan gia tri o day, vi khi khai bao,
    kich thuoc cua a van rong.
    Dung `a[i] = t;` tai day la cach lam sai.
    */
  }

  // in ra tat ca cac so da doc vao a
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ", ";  // !chu y, so dau tien trong a la a[0];
    // Neu chi so vuot bien, no se tra ve mot gia tri khong xac dinh (tran), chu khong bao loi
  }
  std::cout << std::endl;

  return 0;
}
```

Truy cập phần tử mảng trong C++ khá giống Pascal, nhưng có một khác biệt rất quan trọng: phần tử đầu tiên của mảng là `a[0]`, còn trong Pascal bạn có thể tự chỉ định chỉ số bắt đầu.

#### Chuỗi: kiểu thư viện chuẩn String

Hãy tham khảo nội dung trong trang [string](csl/string.md).

Thư viện chuẩn C++ cung cấp `string`. Một số thao tác trên `string` giống với `vector`; kiểu này cũng cần nạp tệp thư viện trước khi dùng.

```cpp
#include <iostream>
#include <string>

int main() {
  std::string s;  // khai bao string s

  std::cin >> s;  // doc s;
  // Khi doc, tat ca ky tu trang o dau (dau cach, xuong dong, tab) se bi bo qua;
  // chuoi duoc doc den truoc ky tu trang tiep theo thi dung.

  std::cout << s << std::endl;

  return 0;
}
```

#### Mảng kiểu C

Hãy tham khảo nội dung trong trang [Mảng](array.md).

Nếu cần dùng mảng có độ dài thay đổi, hãy dùng `vector`, không nên dùng mảng kiểu C.

Mảng kiểu C có quan hệ rất chặt chẽ với con trỏ, nên ở đây không trình bày thêm.

## Những điểm khác biệt quan trọng

<a id="&#21464;&#37327;&#20316;&#29992;&#22495;&#65306;&#20840;&#23616;&#21464;&#37327;&#19982;&#23616;&#37096;&#21464;&#37327;"></a>
<a id="&#21464;&#37327;&#20316;&#29992;&#22495;&#20840;&#23616;&#21464;&#37327;&#19982;&#23616;&#37096;&#21464;&#37327;"></a>
### Phạm vi biến: biến toàn cục và biến cục bộ

C++ gần như có thể khai báo biến ở **bất kỳ đâu**. Hãy tham khảo [Phạm vi biến](var.md#%E5%8F%98%E9%87%8F%E4%BD%9C%E7%94%A8%E5%9F%9F).

Khi viết thủ tục/hàm Pascal, bạn rất dễ quên khai báo biến cục bộ `i` hoặc `j`. Thông thường chương trình chính lại có vòng lặp, nên trong đa số trường hợp `i` và `j` đều là biến toàn cục. Khi đó, việc thao tác với `i` trong thủ tục/hàm rất dễ gây lỗi. Tệ hơn nữa, nếu quên khai báo các biến cục bộ kiểu này, trình biên dịch không báo lỗi và chương trình vẫn chạy. (Rất nhiều bug khó tìm xuất phát từ đây.)

Vì vậy, khi dùng C++, hãy khai báo biến, chẳng hạn `i` dùng trong vòng lặp, theo nguyên tắc: **đừng dùng biến toàn cục nếu có thể dùng biến cục bộ**. Nếu làm vậy, bạn không cần lo tên biến trong hàm (ví dụ `i`) bị xung đột.

??? note "Ghi chú bổ sung"
    Pascal có thể tránh vấn đề này ở một mức độ nhất định bằng cách mô phỏng cách làm của C++: trong chương trình chính chỉ gọi thủ tục/hàm, không khai báo các biến toàn cục dễ xung đột tên như `i`, `j`; nếu cần vòng lặp thì viết thêm một thủ tục riêng để gọi.

### C++ có thể tự động chuyển đổi kiểu

```cpp
int i = 2;
if (i) {  // i = 0 tra ve false, cac gia tri khac tra ve true
  std::cout << "true";
} else {
  std::cout << "false";
}
```

Không chỉ `int` có thể chuyển thành `bool`, `int` và `float` cũng có thể chuyển đổi qua lại. Trong Pascal, có thể gán số nguyên cho số thực, nhưng không thể làm ngược lại. C++ không gặp vấn đề này.

```cpp
int a;
a = 3.2;      // luc nay a = 3
float b = a;  // luc nay b = 3.0
```

Việc phân biệt `/` là phép chia nguyên hay phép chia số thực được quyết định dựa trên kiểu của số bị chia và số chia.

```cpp
float a = 32 / 10;    // ket qua cua 32/10 la 3 (chia nguyen); a = 3.0
float b = 32.0 / 10;  // ket qua cua 32.0/10 la 3.2; b = 3.2
```

`pow(a, b)` tính $a^b$. Hàm này trả về kiểu số thực; nếu dùng trực tiếp để tính lũy thừa số nguyên thì nhờ chuyển đổi tự động, bạn không cần lo nó báo lỗi.

```cpp
int a = pow(2, 3);  // tinh 2^3
```

Ngoài ra còn có chuyển đổi qua lại giữa `char` và `int`.

```cpp
char a = 48;              // ASCII 48 la '0'
int b = a + 1;            // b = 49
std::cout << (a == '0');  // true xuat ra 1
```

Thực ra trong C++, `char` và `bool` về bản chất đều là kiểu số nguyên.

Chi tiết xem bài [Implicit conversions - cppreference.com](https://zh.cppreference.com/w/cpp/language/implicit_conversion).

### Nhiều câu lệnh C++ có giá trị trả về: ví dụ cách đọc dữ liệu với số lượng không cố định

Đôi khi cần đọc cho đến khi hết dữ liệu, chẳng hạn tính tổng một dãy số có số lượng không cố định (dữ liệu có thể nằm trên nhiều dòng) cho đến cuối tệp. Cách làm là:

??? note "Cuối tệp EOF"
    EOF là ký hiệu cuối tệp. Trong dòng lệnh Windows, nhập bằng <kbd>Ctrl</kbd>+<kbd>Z</kbd> (sau đó cần nhấn <kbd>Enter</kbd>); trên hệ Unix-like, nhập bằng <kbd>Ctrl</kbd>+<kbd>D</kbd>.

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

Nguyên lý: trong `while (std::cin >> a)`, nếu `std::cin >> a` gặp lỗi khi nhập hoặc gặp cuối tệp, nó sẽ trả về `false`, làm vòng lặp dừng lại.

### Hàm

C++ chỉ có hàm, không có thủ tục, nhưng có `void`; không có biến giá trị hàm như Pascal, nhưng có `return`.

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

Trong C++, khai báo hàm `int abs` định nghĩa hàm `abs()` và cho biết giá trị trả về có kiểu `int` (số nguyên). Giá trị trả về của hàm là giá trị do câu lệnh `return` đưa ra.

Nếu không muốn có giá trị trả về (tức "thủ tục" trong Pascal), hãy dùng `void`. `void` nghĩa là "rỗng", không trả về gì cả.

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

`return` của C++ có một điểm rất khác so với việc gán giá trị cho biến hàm trong Pascal. Trong C++, `return` trả về một giá trị; sau khi thực thi câu lệnh này, hàm kết thúc ngay. Còn trong Pascal, gán giá trị cho biến hàm không làm thoát khỏi hàm, mà chương trình vẫn tiếp tục thực thi. Vì vậy, nếu Pascal cần dừng hàm/thủ tục ở một chỗ nào đó, cần thêm lệnh `exit`. C++ thì không cần; nếu cần dừng ở đâu, có thể dùng trực tiếp `return`. Ví dụ (vì thật sự khó nghĩ ra đoạn mã vừa ngắn vừa thực dụng, nên tạm dùng như sau):

```cpp
#include <iostream>

void printWarning(int x) {
  if (x >= 0) {
    return;  // cau lenh nay o day tuong duong voi `exit;` trong Pascal
  }
  std::cout << "Warning: input a negative number.";
}

int main() {
  int a;

  std::cin >> a;
  printWarning(a);

  return 0;
}
```

Theo một nghĩa nào đó, hàm `abs` ở trên nếu muốn tương đương nghiêm ngặt thì phải viết như sau:

```pas
function abs(x:integer):integer;
begin
    if x < 0 then
        begin
            abs := -x; exit; // !chu y cho nay
        end
    else
        begin
            abs := x;  exit; // !chu y cho nay
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
    Trong C++, `exit` là thoát khỏi chương trình; đừng tiện tay gõ `exit`, hãy dùng `return`!

C++ coi cả hàm lẫn thủ tục đều là hàm, kể cả `main` cũng không ngoại lệ. Ví dụ khi viết `int main`, C++ xem `main` là một hàm kiểu số nguyên; ở đây giá trị trả về là `0`. Đây là một quy ước thông dụng: trả về `0` nghĩa là chương trình kết thúc bình thường.

Có lẽ bạn đã đoán ra, các tham số trong `main(int argc, char const *argv[])` là `int argc` và `char const *argv[]`; nhưng ý nghĩa của chúng hãy tham khảo tài liệu khác.

### Truyền tham số trong hàm

C++ không có từ khóa `var` của Pascal để thay đổi tham số được truyền vào, nhưng C++ có thể dùng tham chiếu và con trỏ để đạt hiệu quả tương tự.

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
// Ma dung con tro
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

Chú ý, đoạn C++ ở đây **liên quan đến con trỏ**. Con trỏ là vấn đề khá rắc rối, nên bạn nên đọc thêm tài liệu liên quan.

```cpp
// Ma dung tham chieu
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

Chú ý, đoạn C++ ở đây liên quan đến **kiểu tham chiếu**. Khi dùng tham chiếu để gọi một số thư viện STL hoặc thư viện template, bạn có thể gặp một số vấn đề; lúc đó cần tự khai báo kiểu riêng. Tài liệu cụ thể có thể tự tra trong *C++ Primer* bản thứ năm hoặc tài liệu trên mạng.

C++ còn có các cách truyền tham số khác. Một trong số đó là **truyền tham số bằng cách dùng trực tiếp biến toàn cục**; nếu chưa biết dùng con trỏ, bạn có thể tạm dùng cách này. Nhưng khuyết điểm của cách này là không có stack để lưu dữ liệu, nên **không thể truyền tham số trong hàm đệ quy**. (Trừ khi tự viết stack; lưu ý, tự viết stack cũng là một cách vượt qua giới hạn stack hệ thống.)

## Thư viện chuẩn C++ và tài liệu tham khảo

Đừng tự tạo lại bánh xe (trừ khi để luyện tập). Trước khi muốn tự viết một chức năng, hãy xem trước đã có hàm hoặc cấu trúc dữ liệu tương ứng hay chưa.

### Thư viện chuẩn C++

Trong thư viện chuẩn C++, `<algorithm>` có rất nhiều hàm hữu ích như sắp xếp nhanh, tìm kiếm nhị phân, v.v.; có thể gọi trực tiếp. Hãy tham khảo trang [Thuật toán STL](csl/algorithm.md).

Ngoài ra còn có container STL, chẳng hạn mảng, vector (mảng có kích thước thay đổi), hàng đợi, ngăn xếp, v.v., kèm nhiều hàm hỗ trợ. Hãy tham khảo trang [Giới thiệu container STL](csl/container.md).

Nếu muốn tìm các hàm thao tác chuỗi, xem:

-   [std::basic\_string - cppreference.com](https://zh.cppreference.com/w/cpp/string/basic_string)
-   [`<string>` - C++ Reference](https://www.cplusplus.com/reference/string/)

Con trỏ trong C/C++ là một thứ rất linh hoạt; có thể tham khảo trang [Con trỏ](pointer.md). Nếu muốn hiểu thật kỹ con trỏ, nên tìm một cuốn sách hoặc sổ tay tham khảo để đọc cẩn thận.

### Gỡ lỗi và mẹo

-   [Lỗi thường gặp](../contest/common-mistakes.md)
-   [Mẹo thường gặp](../contest/common-tricks.md)

### Tài liệu về ngôn ngữ C++

-   [Tài nguyên học tập](../contest/resources.md)
-   [cppreference.com](https://zh.cppreference.com/): tài liệu tham khảo C/C++ quan trọng nhất
-   [C++ Tutorial - Runoob](https://www.runoob.com/cplusplus/cpp-tutorial.html)
-   [C++ Language - C++ Tutorials](https://www.cplusplus.com/doc/tutorial/)
-   [Reference - C++ Reference](https://www.cplusplus.com/reference/)
-   [C++ Standard Library - Wikipedia](https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library)
-   [The Ultimate Question of Programming, Refactoring, and Everything](https://www.gitbook.com/book/alexastva/the-ultimate-question-of-programming-refactoring-/details)
-   [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

## Lời bạt

Viết đến đây, nhiều bạn có thể thấy bài này chẳng giống một bài "cấp cứu" chút nào, vì còn rất nhiều thứ chưa được nhắc tới. Điều đó cũng khó tránh.

Dù mục tiêu là "cấp cứu", nhiều nội dung như cách chuyển chuỗi thành số, cách tìm ký tự trong chuỗi, v.v. không phù hợp với một bài viết ngắn gọn. Nếu viết hết những thứ đó ra thì đây sẽ trở thành giáo trình nhập môn C++, nên hãy tận dụng đầy đủ Wiki này, sổ tay tham khảo và công cụ tìm kiếm.

Cần chỉ ra một điểm: cú pháp C++ nói ở trên thực ra có rất nhiều phần đến từ ngôn ngữ C. Tiêu đề viết chính xác hơn có lẽ nên là "Bài cấp cứu chuyển từ Pascal sang C/C++".

Pascal là một ngôn ngữ rất phổ biến vào nửa sau thế kỷ trước. Nó ra đời sớm hơn C, nhưng cùng với sự phổ biến của hệ thống UNIX và việc Microsoft sử dụng C, Pascal nay đã trở thành lịch sử. Pascal về sau vẫn có phát triển, chẳng hạn dự án trình biên dịch mã nguồn mở Free Pascal đã bổ sung đặc tính hướng đối tượng (ngôn ngữ Delphi). Hiện nay, ngoài việc dùng trong thi lập trình, Pascal có một đặc điểm mà các ngôn ngữ khác không có: hỗ trợ biên dịch cho rất nhiều máy cũ, chẳng hạn Gameboy, máy chơi game Nintendo từ thế kỷ trước. Một công dụng khác là xuất hiện dưới dạng mã giả (mã giả phong cách Pascal) trong nhiều sách giáo khoa.

Cuối cùng, cộng đồng Pascal thật ra rất nhỏ, còn cộng đồng C/C++ rất lớn; tài liệu trợ giúp và giáo trình rất nhiều, rất đầy đủ. Nhất định phải học tốt tiếng Anh. Trên thế giới còn rất nhiều ngôn ngữ lập trình, và ngành khoa học máy tính cùng kỹ thuật máy tính không chỉ có thi lập trình và ngôn ngữ lập trình.

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

-   [Các hàm toán học thường dùng - cppreference.com](https://zh.cppreference.com/w/cpp/numeric/math)
