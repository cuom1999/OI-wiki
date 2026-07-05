## Khung chương trình

Nếu chưa muốn tìm hiểu sâu nguyên lý phía sau, khi mới học bạn có thể ghi nhớ
trực tiếp "khung" sau:

```cpp
#include <cstdio>
#include <iostream>

int main() {
  // làm gì đó...
  return 0;
}
```

??? note "`#include` là gì?"
    `#include` thực chất là một lệnh tiền xử lý, nghĩa là "đặt" một tệp vào vị
    trí của câu lệnh này; tệp được đặt vào đó gọi là tệp tiêu đề. Nói cách khác,
    khi biên dịch, trình biên dịch sẽ "sao chép" nội dung trong tệp tiêu đề
    `iostream` rồi "dán" vào vị trí câu lệnh `#include <iostream>`. Nhờ vậy,
    bạn có thể dùng các đối tượng mà `iostream` cung cấp như `std::cin`,
    `std::cout`, `std::endl`, v.v.

    Nếu đã học ngôn ngữ C, bạn sẽ thấy trong C++ hiện nay các tệp tiêu đề thường
    gặp không có hậu tố `.h`, còn các tệp tiêu đề `xx.h` của C thường có dạng
    `cxx`, chẳng hạn `stdio.h` trở thành `cstdio`. Để tương thích với C, C++
    trực tiếp sử dụng các tệp tiêu đề của C; để phân biệt tệp tiêu đề C++ với
    tệp tiêu đề C, người ta dùng tiền tố `c`.

    Thông thường, bạn nên quyết định cần `#include` những tệp tiêu đề nào dựa
    trên nhu cầu của chương trình C++ mình viết. Nếu `#include` thừa tệp tiêu
    đề, thời gian biên dịch có thể tăng, nhưng thời gian chạy gần như không bị
    ảnh hưởng. Hiện tại chúng ta mới tiếp xúc với hai tệp tiêu đề `iostream` và
    `cstdio`; nếu bạn chỉ cần `scanf` và `printf`, thì không cần
    `#include <iostream>`.

    Có thể `#include` tệp tiêu đề tự viết không? Câu trả lời là có.

    Bạn có thể tự viết một tệp tiêu đề, ví dụ `myheader.h`. Sau đó đặt nó vào
    cùng thư mục với mã nguồn, rồi dùng `#include "myheader.h"` là được. Cần chú
    ý rằng tệp tiêu đề tự định nghĩa phải dùng dấu ngoặc kép thay vì dấu ngoặc
    nhọn. Tất nhiên, bạn cũng có thể dùng tùy chọn biên dịch
    `-I <header_file_path>` để cho trình biên dịch biết cần tìm tệp tiêu đề ở
    đâu; khi đó không cần đặt tệp tiêu đề cùng thư mục với mã nguồn nữa.

??? note "`main()` là gì?"
    Có thể hiểu rằng khi chương trình chạy, các đoạn mã trong `main()` sẽ được
    thực thi.

    Trên thực tế, hàm `main` được hệ thống hoặc chương trình bên ngoài gọi. Ví
    dụ, khi bạn gọi chương trình của mình trong dòng lệnh, tức là bạn đã gọi hàm
    `main` trong chương trình đó (trước đó việc khởi tạo các [biến](./var.md)
    toàn cục đã hoàn tất).

    Câu lệnh `return 0;` cuối cùng biểu thị chương trình chạy thành công. Theo
    mặc định, khi chương trình kết thúc, trả về 0 nghĩa là mọi thứ bình thường;
    ngược lại, giá trị trả về biểu thị mã lỗi (trên Windows, dạng thập lục phân
    của mã lỗi này có thể tra cứu trên trang [Windows Error Codes](https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/)).
    Giá trị này được trả về cho ai? Thực ra là cho hệ thống hoặc chương trình
    bên ngoài đã gọi chương trình bạn viết; khi chương trình của bạn kết thúc,
    nó sẽ nhận được giá trị trả về này. Nếu không viết câu lệnh `return`, khi
    chương trình kết thúc bình thường, giá trị trả về mặc định cũng là 0.

    Trong C hoặc C++, nếu giá trị trả về của chương trình khác 0, trình chấm
    thường sẽ xem đó là lỗi khi chạy (RE).

## Chú thích

Trong mã C++, chú thích có hai cách viết:

1.  Chú thích trên dòng

    Bắt đầu bằng `//`; mọi nội dung đứng sau nó trên cùng dòng đều là chú thích.

2.  Khối chú thích

    Bắt đầu bằng `/*` và kết thúc bằng `*/`; mọi nội dung ở giữa đều là chú
    thích, có thể trải qua nhiều dòng.

Chú thích không ảnh hưởng đến việc chạy chương trình. Chúng có thể dùng để giải
thích ý nghĩa của chương trình, hoặc để khiến một đoạn mã không được thực thi
nhưng vẫn được giữ lại trong tệp nguồn.

Trong phát triển phần mềm, chú thích giúp việc bảo trì về sau và việc đọc mã của
người khác thuận tiện hơn.

Trong OI, rất ít người viết nhiều chú thích, nhưng chú thích có thể giúp bạn làm
rõ suy nghĩ khi viết mã, hoặc tiện cho việc ôn lại sau này. Hơn nữa, nếu cần
viết lời giải hoặc giáo trình, lượng chú thích vừa phải sẽ giúp người đọc dễ
hiểu ý đồ của mã hơn. Hy vọng các bạn sẽ hình thành thói quen viết chú thích
tốt.

## Nhập và xuất

### `cin` và `cout`

```cpp
#include <iostream>

int main() {
  int x, y;                          // khai báo biến
  std::cin >> x >> y;                // đọc vào x và y
  std::cout << y << std::endl << x;  // xuất y, xuống dòng, rồi xuất x
  return 0;                          // kết thúc hàm main
}
```

???+ note "Biến là gì?"
    Bạn có thể tham khảo trang [Biến](./var.md).

???+ note "`std` là gì?"
    `std` là **không gian tên** mà thư viện chuẩn C++ sử dụng. Không gian tên
    được dùng để tránh trùng tên.

    Để biết chi tiết về không gian tên, có thể tham khảo trang
    [Không gian tên](./namespace.md).

### `scanf` và `printf`

`scanf` và `printf` thực ra là các hàm do ngôn ngữ C cung cấp. Trong đa số
trường hợp, chúng nhanh hơn `cin` và `cout`, đồng thời có thể điều khiển định
dạng nhập xuất một cách thuận tiện.

???+ note "Tối ưu nhập xuất"
    Về khác biệt cụ thể giữa `cin`/`cout` và `scanf`/`printf`, cũng như tối ưu
    nhập xuất, hãy tham khảo trang [Tối ưu đọc vào, xuất ra](../contest/io.md).

```cpp
#include <cstdio>

int main() {
  int x, y;
  scanf("%d%d", &x, &y);   // đọc vào x và y
  printf("%d\n%d", y, x);  // xuất y, xuống dòng, rồi xuất x
  return 0;
}
```

Trong đó, `%d` biểu thị biến được đọc vào hoặc xuất ra là một biến kiểu số
nguyên có dấu (`int`).

Tương tự:

1.  `%s` biểu thị chuỗi.
2.  `%c` biểu thị ký tự.
3.  `%lf` biểu thị số thực dấu phẩy động độ chính xác kép (`double`).
4.  `%lld` biểu thị số nguyên dài (`long long`). Tùy hệ thống, cũng có thể là
    `%I64d`.
5.  `%u` biểu thị số nguyên không dấu (`unsigned int`).
6.  `%llu` biểu thị số nguyên dài không dấu (`unsigned long long`), cũng có thể
    là `%I64u`.

Ngoài ký hiệu kiểu dữ liệu, còn có một số cách điều khiển định dạng. Nhiều cách
không thường dùng; dưới đây liệt kê hai cách phổ biến:

1.  `%1d` biểu thị số nguyên có độ dài 1. Khi đọc vào, ngay cả khi không có
    khoảng trắng cũng có thể đọc từng chữ số. Khi xuất ra, nếu độ dài được chỉ
    định lớn hơn số chữ số của số đó, phía trước số sẽ được đệm bằng khoảng
    trắng. Nếu độ dài được chỉ định nhỏ hơn số chữ số của số đó, thì không có
    tác dụng.
2.  `%.6lf`, dùng khi xuất ra, giữ lại sáu chữ số sau dấu thập phân.

Ở các vị trí tương ứng trong hai dạng định dạng này đều có thể điền các số khác,
ví dụ `%.3lf` biểu thị giữ lại ba chữ số sau dấu thập phân.

??? note "Số thực dấu phẩy động độ chính xác kép, số nguyên dài là gì?"
    Chúng biểu thị kiểu của biến. Cũng như trên, nội dung này sẽ được giải thích
    thống nhất trong [Biến](./var.md).

??? note "Vì sao trong `scanf` có toán tử `&`?"
    Ở đây, `&` thực chất là toán tử lấy địa chỉ, trả về địa chỉ của biến trong bộ
    nhớ. Tham số mà `scanf` nhận chính là địa chỉ của biến. Cụ thể hơn có lẽ
    phải đến [Con trỏ](./pointer.md) mới có thể giải thích thật rõ ràng; hiện
    tại chỉ cần ghi nhớ như vậy là được.

??? note "`\n` là gì?"
    `\n` là một **ký tự thoát**, biểu thị xuống dòng.

    Ký tự thoát dùng để biểu thị một số ký tự không thể nhập trực tiếp, chẳng hạn
    ký tự xuống dòng vì chuỗi ký tự không thể xuống dòng, dấu ngoặc kép vì có ý
    nghĩa đặc biệt, hoặc dấu gạch chéo ngược vì nó dùng để biểu thị ký tự thoát.

    Các ký tự thoát thường dùng gồm:

    1.  `\t` biểu thị ký tự tab.

    2.  `\\` biểu thị `\`.

    3.  `\"` biểu thị `"`.

    4.  `\0` biểu thị ký tự rỗng, dùng để biểu thị phần kết thúc của chuỗi kiểu C.

    5.  `\r` biểu thị ký tự về đầu dòng. Trong Linux, ký tự xuống dòng là `\n`;
        trong Windows, ký tự xuống dòng là `\r\n`. Trong OI, nếu đầu ra cần
        xuống dòng, dùng `\n` là đủ. Nhưng khi đọc vào, nếu dùng cách đọc từng
        ký tự, ký tự xuống dòng có thể gây ra một số vấn đề, cần chú ý. Ví dụ,
        `gets` xem `\n` là kết thúc chuỗi; lúc này nếu ký tự xuống dòng là
        `\r\n`, thì `\r` sẽ còn lại ở cuối chuỗi.

    6.  Đặc biệt, `%%` biểu thị `%`, chỉ dùng trong `printf` hoặc `scanf`; trong
        các chuỗi ký tự khác, chỉ cần dùng `%` trực tiếp là được.

    ??? note "Giá trị trực tiếp (literal) là gì?"
        Literal là một giá trị xuất hiện trực tiếp trong mã, ví dụ `3` là một
        literal kiểu `int`, `'c'` là một literal kiểu `char`. `"hello world"`
        trong chương trình chúng ta viết ở trên cũng là một literal chuỗi.

        Những literal không có giải thích và xuất hiện không rõ lý do còn được
        gọi là "số ma thuật" (magic number). Nếu mã cần được người khác đọc, đây
        là một cách viết rất không được khuyến nghị.

## Một số nội dung mở rộng

### Ký tự trắng trong C++

Trong C++, tất cả ký tự trắng (dấu cách, tab, xuống dòng), dù nhiều hay một, đều
được xem như nhau. Tất nhiên, điều này không áp dụng cho các ký tự nằm trong dấu
ngoặc kép và được xem là một phần của chuỗi.

Vì vậy, bạn có thể tự do sử dụng nhiều phong cách viết mã khác nhau. Ngoại lệ là
chú thích trên dòng, literal chuỗi và lệnh tiền xử lý phải nằm trong một dòng.
Ví dụ:

```cpp
--8<-- "docs/lang/code/basic/basic_1.cpp:main"
```

Tất nhiên, cách viết như vậy không được khuyến nghị.

Một phong cách viết mã khác cũng được sử dụng rộng rãi, nhưng khác với phong cách
mà **OI Wiki** yêu cầu:

```cpp
--8<-- "docs/lang/code/basic/basic_2.cpp:main"
```

### Lệnh `#define`

`#define` là một lệnh tiền xử lý dùng để định nghĩa macro; về bản chất, nó là
phép thay thế văn bản. Ví dụ:

```cpp
#include <iostream>
#define n 233

// n không phải là biến; bộ tiền xử lý sẽ thay mọi token n trong mã thành 233,
// nhưng n nằm trong một phần của định danh thì sẽ không bị thay thế, chẳng hạn
// fn sẽ không bị thay thành f233; tương tự, n trong chuỗi cũng không bị thay thế

int main() {
  std::cout << n;  // xuất 233
  return 0;
}
```

??? note "Định danh là gì?"
    Định danh là một nhóm ký tự có thể dùng làm tên biến. Ví dụ, `abcd` và
    `abc1` đều là định danh hợp lệ, còn `1a` và `c+b` thì không phải định danh
    hợp lệ.

    Định danh bắt đầu bằng chữ cái tiếng Anh hoặc dấu gạch dưới; các ký tự phía
    sau chỉ được là chữ cái tiếng Anh, dấu gạch dưới hoặc chữ số. Cần chú ý rằng
    từ khóa (như `int`, `for`, `if`) không thể dùng làm định danh.

??? note "Lệnh tiền xử lý là gì?"
    Lệnh tiền xử lý là lệnh mà bộ tiền xử lý chấp nhận, dùng để thực hiện các
    biến đổi văn bản sơ bộ trên mã, chẳng hạn thao tác bao gồm tệp `#include` và
    xử lý macro `#define`, v.v. Với GCC, theo mặc định tệp đầu ra `.i` của giai
    đoạn tiền xử lý sẽ không được giữ lại. Có thể dùng tùy chọn `-E` để giữ lại
    tệp đầu ra.

Macro có thể mang tham số; macro có tham số có thể được dùng với cú pháp giống
hàm:

```cpp
#include <iostream>
#define sum(x, y) ((x) + (y))
#define square(x) ((x) * (x))

int main() {
  std::cout << sum(1, 2) << ' ' << 2 * sum(3, 5) << std::endl;  // xuất 3 16
}
```

Nhưng macro có tham số khác với hàm. Vì macro là thay thế văn bản, nên nó có thể
gây ra nhiều vấn đề. Ví dụ:

```cpp
#include <iostream>
#define sum(x, y) x + y
// Ở đây nên là #define sum(x, y) ((x) + (y))
#define square(x) ((x) * (x))

int main() {
  std::cout << sum(1, 2) << ' ' << 2 * sum(3, 5) << std::endl;
  // đầu ra là 3 11, vì #define là thay thế văn bản,
  // biểu thức phía sau bị thay thành 2 * 3 + 5
  int i = 1;
  std::cout << square(++i) << ' ' << i;
  // đầu ra không xác định, vì ++i được thực hiện hai lần
  // mà trong cùng một câu lệnh, sửa đổi cùng một biến nhiều lần
  // là hành vi không xác định (có ngoại lệ)
}
```

Sử dụng `#define` có rủi ro: vì phạm vi tác dụng của `#define` là toàn bộ chương
trình sau điểm định nghĩa, nó có thể khiến văn bản bị thay thế ngoài ý muốn; khi
cần, phải dùng `#undef` để hủy định nghĩa kịp thời. Do đó, nên dùng `#define`
thận trọng. Cách làm được khuyến nghị hơn là dùng bộ định tính `const` để khai
báo hằng, và dùng hàm thay cho macro.

Tuy vậy, trong OI, `#define` vẫn có những chỗ hữu dụng. Hai cách dùng sau không
được khuyến nghị, vì sẽ làm giảm tính chuẩn mực của mã:

1.  `#define int long long`+`signed main()`. Cách này thường được dùng để tránh
    lỗi do quên dùng `long long`, hoặc để loại trừ khả năng đó khi gỡ lỗi. Nó
    cũng có thể làm hằng số tăng đến mức TLE, hoặc gây MLE vì vượt bộ nhớ.
2.  `#define For(i, l, r) for (int i = (l); i <= (r); ++i)`,
    `#define pb push_back`, `#define mid ((l + r) / 2)`, dùng để rút ngắn độ dài
    mã.

Tuy nhiên, `#define` cũng có ưu điểm, chẳng hạn khi kết hợp với các chỉ thị tiền
xử lý như `#ifdef` thì rất hiệu quả. Ví dụ:

```cpp
#ifdef LINUX
// mã cho Linux
#else
// mã cho hệ điều hành khác
#endif
```

Có thể dùng `-DLINUX` khi biên dịch để điều khiển phần mã được biên dịch, mà
không cần sửa tệp nguồn. Điều này còn có một ưu điểm: trong tệp thực thi được
biên dịch bằng `-DLINUX` không có mã của các hệ điều hành khác; những đoạn mã đó
đã bị xóa ngay ở giai đoạn tiền xử lý.

`#define` còn có thể sử dụng các toán tử `#`, `##`, giúp việc gỡ lỗi thuận tiện
hơn rất nhiều.
