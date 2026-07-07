author: CoelacanthusHex, qinyihao, StudyingFather, ksyx, NachtgeistW, CoderOJ, Enter-tainer, mcendu, Tiphereth-A, ayalhw, CCXXXI, Early0v0, HeRaNO, ouuan, swiftqwq, Xeonacid, xiaofu-15191

Trước khi đọc mục này, cần cài đặt GCC và GDB; cách cài đặt cụ thể xem trong bài [trình biên dịch](compiler.md).

## Dùng g++ trên dòng lệnh để biên dịch tệp cpp

### Biên dịch thủ công

Nhập `g++ a.cpp` trong dòng lệnh để biên dịch tệp `a.cpp` (trên Windows cần thêm thư mục chứa trình biên dịch vào `PATH` trước).

Có thể thêm một số tùy chọn biên dịch trong quá trình biên dịch:

-   `-o <tên tệp>`: chỉ định tên tệp thực thi mà trình biên dịch xuất ra.
-   `-g`: thêm thông tin gỡ lỗi khi biên dịch (cần khi dùng GDB để gỡ lỗi).
-   `-Wall`: hiển thị toàn bộ thông tin cảnh báo khi biên dịch.
-   `-O1`, `-O2`, `-O3`, `-Ofast`: tối ưu hóa chương trình được biên dịch; mức càng cao thì áp dụng càng nhiều biện pháp tối ưu hơn (bật tối ưu hóa sẽ ảnh hưởng đến việc gỡ lỗi bằng GDB).
-   `-DDEBUG`: định nghĩa ký hiệu `DEBUG` khi biên dịch (ký hiệu có thể thay tùy ý; ví dụ `-DONLINE_JUDGE` định nghĩa ký hiệu `ONLINE_JUDGE`).
-   `-UDEBUG`: hủy định nghĩa ký hiệu `DEBUG` khi biên dịch.
-   `-lm`, `-lgmp`: liên kết một thư viện cụ thể (trong ví dụ này là math và gmp; tên cần dùng nên tra theo tài liệu của thư viện, nhưng thường giống tên thư viện).

???+ note "Ghi chú"
    Trên Unix, nếu dùng thư viện math trong thư viện C chuẩn (`math.h`), cần thêm tham số `-lm` khi biên dịch.[^have-to-link-libm-in-gcc]

???+ note "Làm thế nào để tăng kích thước ngăn xếp?"
    Trên Windows, có thể dùng tùy chọn biên dịch `-Wl,--stack=536870912` để tăng ngăn xếp lên 512 MB; số sau dấu bằng là **số byte**.

    Trên Unix, dùng `ulimit -s [num]` để đặt ngăn xếp của **trình bao hiện tại** thành `[num]` **KiB**.

### Dùng quy tắc tích hợp của GNU Make[^gnu-make-built-in-rules]

Với mã nguồn C/C++ tên `qwq.c/cpp`, có thể dùng `make qwq` để tự động biên dịch thành chương trình tương ứng tên `qwq`.

Nếu cần thêm tùy chọn biên dịch, có thể dùng `export CFLAGS="xxx"` (chương trình C) hoặc `export CXXFLAGS="xxx"` (chương trình C++) để chỉ định. Nếu cần thêm tùy chọn tiền xử lý, có thể dùng `export CPPFLAGS="xxx"` để chỉ định. Các thiết lập trên cũng có thể viết dưới dạng `CFLAGS="xxx" CPPFLAGS="xxx" make qwq` để chỉ định biến môi trường cho một lần chạy lệnh.

### Công cụ kiểm lỗi Sanitizer

#### Giới thiệu

Sanitizer là nhóm công cụ kiểm lỗi được tích hợp trong trình biên dịch để gỡ lỗi mã C/C++. Các công cụ này chèn mã kiểm tra trong quá trình biên dịch để phát hiện các lỗi khi chạy như truy cập bộ nhớ vượt biên, hành vi không xác định, v.v.

Các công cụ Sanitizer thường được chia thành các loại sau:

-   AddressSanitizer[^address-sanitizer]: phát hiện truy cập vượt biên trên heap, ngăn xếp và biến toàn cục, giải phóng bộ nhớ không hợp lệ, rò rỉ bộ nhớ (thử nghiệm).
-   ThreadSanitizer[^thread-sanitizer]: phát hiện tranh chấp dữ liệu trong đa luồng.
-   MemorySanitizer[^memory-sanitizer]: phát hiện việc đọc bộ nhớ chưa được khởi tạo.
-   UndefinedBehaviorSanitizer[^ub-san]: phát hiện hành vi không xác định.

#### Cách sử dụng

Các phiên bản mới của clang++, g++ và MSVC (hỗ trợ một phần) đều đã tích hợp Sanitizer, nhưng chức năng và cách dùng có khác nhau. Phần này lấy clang++ làm ví dụ; cách dùng như sau:

```console
$ clang++ -fsanitize=<name> test.cc
```

Trong đó `<name>` là chức năng cần bật (có thể hiểu mỗi Sanitizer là một tập hợp chức năng), ví dụ:

```console
$ clang++ -fsanitize=memory test.cc # Bật MemorySanitizer
$ clang++ -fsanitize=signed-integer-overflow test.cc # Bật kiểm tra tràn số nguyên có dấu
```

Sau đó chạy tệp thực thi như bình thường. Nếu Sanitizer phát hiện lỗi, nó sẽ xuất thông tin ra luồng `stderr`, ví dụ:

```console
$ ./a.out
test.cc:3:5: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'
```

???+ warning "Cảnh báo"
    g++ trên Windows không hỗ trợ Sanitizer; cần dùng [MinGW64 đã được chỉnh sửa](https://github.com/ssbssa/gcc/releases) hoặc dùng trình biên dịch khác.

    Từ MSVC 16.0 đến phiên bản 17.14, MSVC chỉ hỗ trợ AddressSanitizer.

#### Chi phí thời gian/bộ nhớ

Các công cụ gỡ lỗi này sẽ làm chương trình chạy chậm hơn đáng kể và tăng lượng bộ nhớ sử dụng. Bảng dưới đây là chi phí thời gian/bộ nhớ khi dùng chúng:

| Tên | Hệ số tăng bộ nhớ | Hệ số tăng thời gian |
| :-- | :---------------- | :------------------- |
| AddressSanitizer | N/A | 2 |
| ThreadSanitizer | 5\~15 | 5\~10 |
| MemorySanitizer | N/A | 3 |
| UndefinedBehaviorSanitizer | N/A | N/A |

## Dùng GDB trên dòng lệnh để gỡ lỗi

```console
$ g++ a.cpp -o a -g
$ gdb ./a
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04.2) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.
--Type <RET> for more, q to quit, c to continue without paging--
```

Nhấn `c` để tiếp tục. Sau đó sẽ hiện thông báo `Reading symbols from [filename]...`; khi xuất hiện `(gdb)`, có thể nhập lệnh để gỡ lỗi.

Dưới đây là các lệnh thường dùng được liệt kê theo phân loại:

### Lệnh GDB cơ bản

| Lệnh | Mô tả |
| ---- | ----- |
| `help` | Hiển thị thông tin trợ giúp |
| `quit` | Thoát GDB |
| `file [filename]` | Nạp chương trình `[filename]` cần gỡ lỗi |

### Lệnh điều khiển chạy

| Lệnh | Mô tả |
| ---- | ----- |
| `run` | Chạy chương trình cho đến khi gặp điểm dừng hoặc chương trình kết thúc |
| `continue` | Tiếp tục chạy cho đến khi gặp điểm dừng hoặc chương trình kết thúc |
| `next` | Thực thi từng bước; nếu gặp lời gọi hàm thì bước qua lời gọi đó |
| `step` | Thực thi từng bước; nếu gặp lời gọi hàm thì đi vào hàm |
| `finish` | Chạy đến khi hàm hiện tại trả về, rồi dừng lại chờ lệnh |
| `until [num]` | Chạy đến dòng số `[num]`, rồi dừng lại chờ lệnh |
| `break [num]` | Đặt điểm dừng tại dòng `[num]`; khi chương trình chạy đến dòng đó thì dừng lại chờ lệnh |
| `condition [id] [p]` | Đặt điều kiện cho điểm dừng số `[id]`; điểm dừng chỉ được kích hoạt khi biểu thức `[p]` thỏa mãn |
| `ignore [id] [num]` | Bỏ qua `[num]` lần đầu điểm dừng được kích hoạt |
| `delete [id]` | Xóa điểm dừng có số chỉ định |
| `disable [id]` | Tắt điểm dừng có số chỉ định |
| `enable [id]` | Bật điểm dừng có số chỉ định |
| `list` | Liệt kê mã nguồn, tiếp tục từ vị trí trước đó; mỗi lần liệt kê 10 dòng |
| `list [num]` | Liệt kê mã nguồn với dòng `[num]` ở giữa |
| `list [func-name]` | Liệt kê mã nguồn với hàm tương ứng ở giữa |
| `call [function]` | Gọi hàm và in giá trị trả về |

`break [num]` sẽ xuất ra số hiệu của điểm dừng; cũng có thể dùng `break [func-name]` để đặt điểm dừng tại hàm.

Cũng có thể dùng `break [num] [p]` khi đặt điểm dừng để có tác dụng gần giống `condition [id] [p]`.

### Lệnh khung ngăn xếp

| Lệnh | Mô tả |
| ---- | ----- |
| `info args` | Xem tham số của hàm |
| `backtrace` | Xem các cấp lời gọi hàm và tham số |
| `frame` | Chọn khung ngăn xếp |
| `up` | Di chuyển lên một cấp khung ngăn xếp |
| `down` | Di chuyển xuống một cấp khung ngăn xếp |

### Lệnh biến

| Lệnh | Mô tả |
| ---- | ----- |
| `print [p]` | In giá trị của biểu thức `[p]`; có thể sửa giá trị biến thông qua biểu thức |
| `display [p]` | In giá trị của biểu thức `[p]` mỗi khi chương trình tạm dừng |
| `watch [var]` | Theo dõi giá trị của biến `[var]`; khi biến bị ghi, GDB sẽ tự động in ra và tạm dừng |
| `rwatch [var]` | Theo dõi giá trị của biến `[var]`; khi biến bị đọc, GDB sẽ tự động in ra |
| `awatch [var]` | Khi biến `[var]` bị sửa hoặc bị ghi, GDB sẽ tự động in ra và tạm dừng |
| `set [assignment]` | Thực hiện câu lệnh gán |

Cả hai lệnh `display` và `print` đều hỗ trợ điều khiển định dạng xuất. Cách làm là thêm ngay sau lệnh ký tự `/` và ký tự định dạng; ví dụ `print/display [var]` (in giá trị biến `[var]` theo hệ thập phân). Các ký tự định dạng được hỗ trợ gồm:

| Ký tự định dạng | Định dạng tương ứng |
| --------------- | ------------------- |
| `d` | Hiển thị biến theo hệ thập phân |
| `x` | Hiển thị biến theo hệ thập lục phân |
| `a` | Hiển thị biến theo hệ thập lục phân |
| `t` | Hiển thị biến theo hệ nhị phân |
| `c` | Hiển thị biến theo dạng ký tự |
| `f` | Hiển thị biến theo dạng số thực |
| `u` | Hiển thị số nguyên không dấu theo hệ thập phân |
| `o` | Hiển thị biến theo hệ bát phân |

### Lệnh thông tin

| Lệnh | Mô tả |
| ---- | ----- |
| `info breakpoints` | Liệt kê tất cả điểm dừng |
| `info locals` | Liệt kê biến cục bộ của khung ngăn xếp hiện tại |
| `info args` | Liệt kê tham số hàm của khung ngăn xếp hiện tại |
| `info threads` | Liệt kê tất cả luồng |
| `info program` | Hiển thị trạng thái hiện tại của chương trình |
| `info registers` | Hiển thị giá trị thanh ghi hiện tại |
| `info frame` | Hiển thị thông tin của khung ngăn xếp hiện tại |

### Lệnh khác

| Lệnh | Mô tả |
| ---- | ----- |
| `enable pretty-printer` | Bật bộ in đẹp (pretty-printer), có thể in các bộ chứa STL theo dạng dễ đọc hơn |
| `checkpoint`[^checkpoint] | Tạo điểm kiểm tra, có thể quay lại điểm kiểm tra đó |
| `restart [num]`[^checkpoint] | Quay lại điểm kiểm tra thứ `[num]` |
| `save breakpoints [filename]` | Lưu điểm dừng vào tệp |
| `source [filename]` | Nạp tệp điểm dừng |

???+ tip "Mẹo"
    Phần lớn lệnh khi gỡ lỗi bằng GDB có thể được viết tắt thành một dạng rút gọn bằng số chữ cái vừa đủ để nhận diện duy nhất, ví dụ `breakpoint` viết tắt thành `b`, `step` viết tắt thành `s`, `info args` viết tắt thành `i ar`. Xem lệnh `help` để biết chi tiết.

## Tài liệu tham khảo và chú thích

[^have-to-link-libm-in-gcc]: [Vì sao cần liên kết thư viện toán học trong C?](https://stackoverflow.com/questions/1033898/why-do-you-have-to-link-the-math-library-in-c)

[^address-sanitizer]: <https://clang.llvm.org/docs/AddressSanitizer.html>

[^thread-sanitizer]: <https://clang.llvm.org/docs/ThreadSanitizer.html>

[^memory-sanitizer]: <https://clang.llvm.org/docs/MemorySanitizer.html>

[^ub-san]: <https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html>

[^gnu-make-built-in-rules]: [Danh mục các quy tắc dựng sẵn](https://www.gnu.org/software/make/manual/html_node/Catalogue-of-Rules.html)

[^checkpoint]: Các lệnh liên quan đến điểm kiểm tra (checkpoint) chỉ dùng được trên nền tảng GNU/Linux. Xem [sổ tay chính thức của GDB](https://sourceware.org/gdb/current/onlinedocs/gdb#Checkpoint_002fRestart) để biết chi tiết.
