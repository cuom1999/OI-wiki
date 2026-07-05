author: aofall, greyqz, Ir1d, Link-cute, Marcythm, ouuan, Shen-Linwood, sshwy, StudyingFather

## Toán tử số học

| Toán tử       | Chức năng |
| ------------- | --------- |
| `+` (một ngôi) | dương     |
| `-` (một ngôi) | âm        |
| `*` (hai ngôi) | nhân      |
| `/`           | chia      |
| `%`           | lấy modulo |
| `+` (hai ngôi) | cộng      |
| `-` (hai ngôi) | trừ       |

??? note "Toán tử một ngôi và hai ngôi"
    Toán tử một ngôi (unary operator) là toán tử chỉ có một toán hạng, còn toán
    tử hai ngôi (binary operator) là toán tử có hai toán hạng. Ví dụ, dấu cộng
    trong `1 + 2` là toán tử hai ngôi, có hai toán hạng là `1` và `2`. Ngoài ra
    trong C++ còn có một toán tử ba ngôi duy nhất là `?:`.

Trong các toán tử số học có hai toán tử một ngôi (dương, âm) và năm toán tử hai
ngôi (nhân, chia, lấy modulo, cộng, trừ), trong đó toán tử một ngôi có độ ưu
tiên cao nhất.

Toán tử modulo `%` có nghĩa là tính phần dư khi chia hai số nguyên.

Khi `-` là toán tử hai ngôi, nó là toán tử trừ, ví dụ `2-1`; khi là toán tử một
ngôi, nó là toán tử lấy giá trị âm, ví dụ `-1`.

Cách dùng như sau:

`op=x-y*z`

Giá trị tính được của `op` tuân theo quy tắc ưu tiên cộng, trừ, nhân, chia trong
toán học: trước hết thực hiện phép có độ ưu tiên cao; nếu cùng độ ưu tiên thì
tính theo tính kết hợp của toán tử; dấu ngoặc làm tăng độ ưu tiên.

### Chuyển đổi kiểu trong phép toán số học

Với toán tử số học hai ngôi, nếu hai biến tham gia phép toán có cùng kiểu, sẽ
không xảy ra [chuyển đổi kiểu](./var.md#chuyển-đổi-kiểu), và kết quả phép toán được chứa
bằng kiểu của các biến tham gia. Nếu không cùng kiểu, chuyển đổi kiểu sẽ xảy ra
để làm cho hai biến có kiểu thống nhất. Quy tắc chuyển đổi xem tại
[chuyển đổi kiểu](./var.md#chuyển-đổi-kiểu).

Ví dụ, với một biến số nguyên (`int`) $x$ và một biến số thực dấu phẩy động độ
chính xác kép (`double`) $y$:

-   Kết quả của `x/3` là kiểu số nguyên;
-   Kết quả của `x/3.0` là kiểu `double`;
-   Kết quả của `x/y` là kiểu `double`;
-   Kết quả của `x*1/3` là kiểu số nguyên;
-   Kết quả của `x*1.0/3` là kiểu `double`;

<a id="toán-tử-bit"></a>

## Toán tử bit

Xem thêm: [phép toán bit](../math/bit.md#phép-toán-bit).

| Toán tử       | Chức năng |
| ------------- | --------- |
| `~`           | NOT theo bit |
| `&` (hai ngôi) | AND theo bit |
| `|`           | OR theo bit |
| `^`           | XOR theo bit |
| `<<`          | dịch trái theo bit |
| `>>`          | dịch phải theo bit |

Ý nghĩa của phép toán bit xem tại trang [phép toán bit](../math/bit.md). Cần
chú ý rằng độ ưu tiên của phép toán bit thấp hơn toán tử số học (trừ phép đảo
bit), còn AND theo bit, OR theo bit và XOR thấp hơn toán tử so sánh (xem
[bảng tổng hợp độ ưu tiên toán tử C++](#bảng-tổng-hợp-độ-ưu-tiên-toán-tử-c)), vì vậy khi dùng cần
cẩn thận và thêm ngoặc khi cần thiết.

Trong phép dịch bit, nếu xuất hiện các trường hợp sau thì hành vi là không xác
định:

1.  Toán hạng bên phải (tức số bit dịch) là giá trị âm;
2.  Toán hạng bên phải lớn hơn hoặc bằng số bit của toán hạng bên trái;

Ví dụ, với biến `a` kiểu `int32_t`, `a<<-1` và `a<<32` đều là không xác định.

Với phép dịch trái trên số có dấu không âm, cần bảo đảm kết quả sau khi dịch có
thể được chứa bởi kiểu của số ban đầu; nếu không, hành vi cũng là không xác
định.[^note1] Dịch trái một số âm cũng là không xác định.[^note2]

Với phép dịch phải, các bit dư ở bên phải sẽ bị loại bỏ, còn bên trái phức tạp
hơn: với số không dấu, bên trái được điền $0$[^note3]; với số có dấu, bên trái
được điền bằng bit cao nhất (thực ra là bit dấu: số không âm là $0$, số âm là
$1$)[^note4].

## Toán tử tự tăng/tự giảm

Đôi khi ta cần tăng một biến thêm 1 (tự tăng) hoặc giảm đi 1 (tự giảm). Khi đó
toán tử tự tăng `++` và tự giảm `--` sẽ được dùng.

Toán tử tự tăng/tự giảm có thể đặt trước hoặc sau biến. Đặt trước biến gọi là
tiền tố, đặt sau biến gọi là hậu tố. Khi dùng riêng lẻ, tiền tố và hậu tố không
cần phân biệt đặc biệt; nếu cần dùng giá trị của biểu thức thì phải chú ý, xem
ví dụ bên dưới. Chi tiết có thể tham khảo phần ví dụ trong [tham chiếu](./reference.md).

```cpp
i = 100;

op1 = i++;  // op1 = 100, trước hết op1 = i, sau đó i = i + 1

i = 100;

op2 = ++i;  // op2 = 101, trước hết i = i + 1, sau đó gán cho op2

i = 100;

op3 = i--;  // op3 = 100, trước hết gán cho op3, sau đó i = i - 1

i = 100;

op4 = --i;  // op4 = 99, trước hết i = i - 1, sau đó gán cho op4
```

## Toán tử gán phức hợp

Toán tử gán phức hợp thực chất là dạng viết tắt của biểu thức. Có thể chia thành
toán tử số học phức hợp `+=`, `-=`, `*=`, `/=`, `%=` và toán tử bit phức hợp
`&=`, `|=`, `^=`, `<<=`, `>>=`.

Ví dụ, `op = op + 2` có thể viết thành `op += 2`, `op = op - 2` có thể viết
thành `op -= 2`, `op= op * 2` có thể viết thành `op *= 2`.

## Toán tử điều kiện

Toán tử điều kiện có thể xem là dạng viết tắt của câu lệnh `if`. Trong
`a ? b : c`, nếu biểu thức `a` đúng thì kết quả của biểu thức điều kiện này là
`b`, ngược lại kết quả là `c`.

## Toán tử so sánh

| Toán tử | Chức năng |
| ------- | --------- |
| `>`     | lớn hơn |
| `>=`    | lớn hơn hoặc bằng |
| `<`     | nhỏ hơn |
| `<=`    | nhỏ hơn hoặc bằng |
| `==`    | bằng |
| `!=`    | khác |

Trong đó cần đặc biệt chú ý phân biệt toán tử bằng `==` với toán tử gán `=`,
điều này đặc biệt quan trọng trong câu lệnh kiểm tra điều kiện.

`if (op=1)` và `if (op==1)` trông có vẻ giống nhau, nhưng chức năng thực tế khác
rất xa. Câu thứ nhất gán giá trị cho `op`; nếu giá trị được gán khác 0 thì là
giá trị đúng, nên điều kiện của biểu thức luôn được thỏa mãn và không đạt được
tác dụng kiểm tra. Câu thứ hai mới là kiểm tra giá trị của `op`.

## Toán tử logic

| Toán tử | Chức năng |
| ------- | --------- |
| `&&`    | Phép VÀ logic |
| `||`    | Phép HOẶC logic |
| `!`     | Phép PHỦ ĐỊNH logic |

```cpp
Result = op1 && op2;  // nếu op1 và op2 đều đúng thì Result đúng

Result = op1 || op2;  // nếu op1 hoặc op2 có một cái đúng thì Result đúng

Result = !op1;  // nếu op1 sai thì Result đúng
```

Toán tử **dựng sẵn** `&&` và `||` thực hiện đánh giá ngắn mạch: nếu sau khi đánh
giá toán hạng thứ nhất đã biết kết quả thì không đánh giá toán hạng thứ hai.
Toán tử được nạp chồng không có đặc tính này và luôn đánh giá cả hai toán hạng.

## Toán tử dấu phẩy

Toán tử dấu phẩy có thể phân tách nhiều biểu thức. Các biểu thức được phân tách
sẽ được tính lần lượt từ trái sang phải, và giá trị của toàn bộ biểu thức là giá
trị của biểu thức cuối cùng. Biểu thức dấu phẩy có độ ưu tiên **thấp nhất**
trong tất cả toán tử.

```cpp
exp1, exp2, exp3;  // giá trị cuối cùng là kết quả tính của exp3.

Result = 1 + 2, 3 + 4, 5 + 6;
// giá trị nhận được của Result là 3 chứ không phải 11, vì độ ưu tiên của
// toán tử gán "=" cao hơn toán tử dấu phẩy, nên phép gán được thực hiện trước
// rồi mới đến phép toán dấu phẩy.

Result = (1 + 2, 3 + 4, 5 + 6);

// Nếu muốn Result nhận kết quả của phép toán dấu phẩy, cần dùng ngoặc để
// nâng độ ưu tiên của cả biểu thức; lúc này giá trị của Result mới là 11.
```

## Toán tử truy cập thành viên

| Toán tử       | Chức năng |
| ------------- | --------- |
| `[]`          | chỉ số mảng |
| `.`           | thành viên đối tượng |
| `&` (một ngôi) | lấy địa chỉ/lấy tham chiếu |
| `*` (một ngôi) | truy cập gián tiếp/giải tham chiếu |
| `->`          | thành viên qua con trỏ |

Các toán tử này dùng để truy cập thành viên của đối tượng hoặc truy cập bộ nhớ.
Trừ toán tử cuối cùng, các toán tử nêu trên đều có thể được nạp chồng. Với nội
dung liên quan đến `&`, `*` và `->`, hãy đọc hướng dẫn về [con trỏ](./pointer.md)
và [tham chiếu](./reference.md). Ở đây cũng lược bỏ hai toán tử rất ít dùng là
`.*` và `->*`; cách dùng cụ thể có thể xem tại
[sổ tay ngôn ngữ C++](https://en.cppreference.com/w/cpp/language/operator_member_access).

```cpp
auto result1 = v[1];    // lấy đối tượng có chỉ số 1 trong v
auto result2 = p.q;     // lấy thành viên q của đối tượng p
auto result3 = p -> q;  // lấy thành viên q của đối tượng mà con trỏ p trỏ tới,
                        // tương đương (*p).q
auto result4 = &v;      // lấy con trỏ trỏ tới v
auto result5 = *v;      // lấy đối tượng mà con trỏ v trỏ tới
```

<a id="bảng-tổng-hợp-độ-ưu-tiên-toán-tử-c"></a>

## Bảng tổng hợp độ ưu tiên toán tử C++

Dựa trên [C++ operator precedence - cppreference](https://en.cppreference.com/w/cpp/language/operator_precedence), có chỉnh sửa.

| Toán tử | Mô tả | Ví dụ | Có thể nạp chồng |
| :-----: | :---: | :---: | :--------------: |
| **Cấp 1** | | | |
| `::` | toán tử phân giải phạm vi | `Class::age = 2;` | không thể |
| **Cấp 2** | | | |
| `++` | toán tử hậu tự tăng | `for (int i = 0; i < 10; i++) cout << i;` | có thể |
| `--` | toán tử hậu tự giảm | `for (int i = 10; i > 0; i--) cout << i;` | có thể |
| `type()  type{}` | ép kiểu | `unsigned int a = unsigned(3.14);` | có thể |
| `()` | gọi hàm | `isdigit('1')` | có thể |
| `[]` | truy cập dữ liệu mảng | `array[4] = 2;` | có thể |
| `.` | gọi thành viên đối tượng | `obj.age = 34;` | không thể |
| `->` | gọi thành viên qua con trỏ | `ptr->age = 34;` | có thể |
| **Cấp 3** (kết hợp từ phải sang trái) | | | |
| `++` | toán tử tiền tự tăng | `for (i = 0; i < 10; ++i) cout << i;` | có thể |
| `--` | toán tử tiền tự giảm | `for (i = 10; i > 0; --i) cout << i;` | có thể |
| `+` | dấu dương | `int i = +1;` | có thể |
| `-` | dấu âm | `int i = -1;` | có thể |
| `!` | phủ định logic | `if (!done) …` | có thể |
| `~` | phủ định theo bit | `flags = ~flags;` | có thể |
| `(type)` | ép kiểu kiểu C | `int i = (int) floatNum;` | có thể |
| `*` | lấy giá trị qua con trỏ | `int data = *intPtr;` | có thể |
| `&` | lấy con trỏ tới giá trị | `int *intPtr = &data;` | có thể |
| `sizeof` | trả về kích thước bộ nhớ của kiểu | `int size = sizeof floatNum; int size = sizeof(float);` | không thể |
| `new` | cấp phát bộ nhớ động cho phần tử | `long *pVar = new long; MyClass *ptr = new MyClass(args);` | có thể |
| `new []` | cấp phát bộ nhớ động cho mảng | `long *array = new long[n];` | có thể |
| `delete` | hủy phần tử động | `delete pVar;` | có thể |
| `delete []` | hủy mảng động | `delete [] array;` | có thể |
| **Cấp 4** | | | |
| `.*` | tham chiếu thành viên qua đối tượng lớp | `obj.*var = 24;` | không thể |
| `->*` | tham chiếu thành viên qua con trỏ lớp | `ptr->*var = 24;` | có thể |
| **Cấp 5** | | | |
| `*` | nhân | `int i = 2 * 4;` | có thể |
| `/` | chia | `float f = 10.0 / 3.0;` | có thể |
| `%` | lấy phần dư (modulo) | `int rem = 4 % 3;` | có thể |
| **Cấp 6** | | | |
| `+` | cộng | `int i = 2 + 3;` | có thể |
| `-` | trừ | `int i = 5 - 1;` | có thể |
| **Cấp 7** | | | |
| `<<` | dịch trái bit | `int flags = 33 << 1;` | có thể |
| `>>` | dịch phải bit | `int flags = 33 >> 1;` | có thể |
| **Cấp 8** | | | |
| `<=>` | toán tử so sánh ba chiều | `if ((i <=> 42) < 0) ...` | có thể |
| **Cấp 9** | | | |
| `<` | nhỏ hơn | `if (i < 42) ...` | có thể |
| `<=` | nhỏ hơn hoặc bằng | `if (i <= 42) ...` | có thể |
| `>` | lớn hơn | `if (i > 42) ...` | có thể |
| `>=` | lớn hơn hoặc bằng | `if (i >= 42) ...` | có thể |
| **Cấp 10** | | | |
| `==` | bằng | `if (i == 42) ...` | có thể |
| `!=` | khác | `if (i != 42) ...` | có thể |
| **Cấp 11** | | | |
| `&` | AND bit | `flags = flags & 42;` | có thể |
| **Cấp 12** | | | |
| `^` | XOR bit | `flags = flags ^ 42;` | có thể |
| **Cấp 13** | | | |
| `|` | OR bit | `flags = flags | 42;` | có thể |
| **Cấp 14** | | | |
| `&&` | Phép VÀ logic | `if (conditionA && conditionB) ...` | có thể |
| **Cấp 15** | | | |
| `||` | Phép HOẶC logic | `if (conditionA || conditionB) ...` | có thể |
| **Cấp 16** (kết hợp từ phải sang trái) | | | |
| `? :` | toán tử điều kiện | `int i = a > b ? a : b;` | không thể |
| `throw` | ném ngoại lệ | `throw EClass("Message");` | không thể |
| `=` | gán | `int a = b;` | có thể |
| `+=` | cộng rồi gán | `a += 3;` | có thể |
| `-=` | trừ rồi gán | `b -= 4;` | có thể |
| `*=` | nhân rồi gán | `a *= 5;` | có thể |
| `/=` | chia rồi gán | `a /= 2;` | có thể |
| `%=` | modulo rồi gán | `a %= 3;` | có thể |
| `<<=` | dịch trái bit rồi gán | `flags <<= 2;` | có thể |
| `>>=` | dịch phải bit rồi gán | `flags >>= 2;` | có thể |
| `&=` | AND bit rồi gán | `flags &= new_flags;` | có thể |
| `^=` | XOR bit rồi gán | `flags ^= new_flags;` | có thể |
| `|=` | OR bit rồi gán | `flags |= new_flags;` | có thể |
| **Cấp 17** | | | |
| `,` | dấu phân tách bằng dấu phẩy | `for (i = 0, j = 0; i < 10; i++, j++) ...` | có thể |

Cần chú ý rằng bảng trên không liệt kê các toán tử như `const_cast`,
`static_cast`, `dynamic_cast`, `reinterpret_cast`, `typeid`, `sizeof...`,
`noexcept` và `alignof`, vì hình thức sử dụng của chúng giống lời gọi hàm và
không gây nhập nhằng.

## Tài liệu tham khảo và chú thích

[^note1]: Trước C++20, nếu giá trị ban đầu thuộc kiểu có dấu và kết quả sau khi
    dịch có thể được chứa bởi phiên bản không dấu của kiểu ban đầu, kết quả đó
    được [chuyển đổi](../lang/var.md#chuyển-đổi-kiểu) thành giá trị có dấu tương ứng;
    nếu không thì hành vi không xác định. Với số không dấu, dịch trái sẽ loại bỏ
    các bit bị dịch ra khỏi kiểu kết quả. Từ C++20, `a << b` được quy định là
    giá trị của $a\cdot 2^b$ theo modulo $2^N$ ($N$ là độ rộng bit của kiểu kết
    quả), tức dù là số có dấu hay không dấu, dịch trái đều trực tiếp loại bỏ các
    bit bị dịch ra khỏi kiểu kết quả (tức [dịch trái số học/dịch trái logic](../math/bit.md#dịch-bit)).

[^note2]: Trước C++20. Hành vi từ C++20 trở đi xem [^note1].

[^note3]: Tức [dịch phải logic](../math/bit.md#dịch-bit).

[^note4]: Tức [dịch phải số học](../math/bit.md#dịch-bit). Trước C++20, dịch phải
    số có dấu là hành vi do triển khai quyết định; trong phần lớn triển khai,
    dịch phải số học được dùng. Từ C++20, `a >> b` được quy định là
    $\lfloor a/2^b\rfloor$, nên phép dịch phải trên số có dấu là dịch phải số
    học.
