Trang này giới thiệu một số trạng thái, đối tượng và hàm dùng chung trong trình kiểm tra đáp án (checker), trình tương tác (interactor) và trình xác thực dữ liệu (validator) của Testlib, cùng với vài cách dùng và lưu ý quan trọng. Nên đọc hết trang này trước khi đọc các trang khác.

## Trạng thái chung

| Kết quả            | Bí danh Testlib | Ý nghĩa                                                                                                                          |
| ------------------ | ------------ | ------------------------------------------------------------------------------------------------------------------------------- |
| Ok                 | `_ok`        | Đáp án đúng.                                                                                                                     |
| Wrong Answer       | `_wa`        | Đáp án sai.                                                                                                                      |
| Presentation Error | `_pe`        | Định dạng đáp án sai. Lưu ý rằng nhiều OJ, bao gồm Codeforces, không phân biệt PE và WA.                                        |
| Partially Correct  | `_pc(score)` | Đáp án đúng một phần. Chỉ dùng cho các bộ kiểm thử có điểm thành phần; `score` là một số nguyên dương từ $0$ (không có điểm) đến $100$ (điểm tối đa có thể đạt). (`quitf+_pc` chỉ nhằm tương thích với pascal-testlib cũ; nếu muốn xuất điểm thành phần, nên dùng `quitp`[^1].) |
| Fail               | `_fail`      | Trong trình xác thực dữ liệu, trạng thái này nghĩa là đầu vào không hợp lệ và không qua kiểm tra.<br>Trong trình kiểm tra, trạng thái này biểu thị lỗi nội bộ của chương trình, đầu ra chuẩn sai, hoặc đầu ra của thí sinh tốt hơn đầu ra chuẩn, cần giám khảo/người ra đề xem xét. Nói cách khác, lỗi thuộc về đề. |

Thông thường kết quả được biểu thị bằng giá trị trả về của chương trình, nhưng cũng có một số cách khác: tạo tệp XML đầu ra, in thông tin ra `stdout` (đầu ra chuẩn) hoặc vị trí khác, v.v. Các cách này đều được thực hiện thông qua hàm `quitf` trong bảng hàm bên dưới.

## Đối tượng chung

| Đối tượng | Ý nghĩa |
| ----- | ----- |
| `inf` | Luồng tệp đầu vào |
| `ouf` | Luồng đầu ra của thí sinh |
| `ans` | Luồng đầu ra tham chiếu |

## Hàm chung

Hàm không phải hàm thành viên:

| Lời gọi                                                                                        | Ý nghĩa                                                                                                                                      |
| ----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
| `void registerTestlibCmd(int argc, char* argv[])`                                               | Đăng ký chương trình là trình kiểm tra đáp án (checker)                                                                                     |
| `void registerInteraction(int argc, char* argv[])`                                              | Đăng ký chương trình là trình tương tác (interactor)                                                                                        |
| `void registerValidation()`/`void registerValidation(int argc, char* argv[])`                   | Đăng ký chương trình là trình xác thực dữ liệu (validator)                                                                                  |
| `void registerGen(int argc, char* argv[], int randomGeneratorVersion)`                          | Đăng ký chương trình là trình sinh dữ liệu (generator)<br>Nên đặt `randomGeneratorVersion` là `1`                                            |
| `void quit(TResult verdict, string message)`/`void quitf(TResult verdict, string message, ...)` | Kết thúc chương trình, trả về kết quả chấm `verdict` và xuất thông báo `message`                                                            |
| `void quitif(bool condition, TResult verdict, string message, ...)`                             | Nếu `condition` đúng, gọi `quitf(verdict, message, ...)`                                                                                    |
| `void quitp(F points, string message, ...)`                                                     | Kết thúc chương trình và trả về điểm thành phần. Với phần lớn OJ (như Luogu, UOJ), `points` cần là một số thực trong $[0,1]$, biểu thị phần trăm điểm; với một số OJ khác (như Lyrio), `points` cần là một số thực trong $[0,100]$ (OJ sẽ tự bỏ phần thập phân), biểu thị điểm của bộ kiểm thử theo thang 100. |

Hàm thành viên của luồng:

| Lời gọi                                                                                                                                                             | Ý nghĩa |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| `char readChar()`                                                                                                                                                 | Đọc một ký tự |
| `char readChar(char c)`                                                                                                                                           | Đọc một ký tự, ký tự đó bắt buộc phải là `c` |
| `char readSpace()`                                                                                                                                                | Tương đương `readChar(' ')` |
| `string readToken()`/`string readWord()`                                                                                                                          | Đọc một chuỗi, dừng ở ký tự trắng (dấu cách, Tab, EOLN, v.v.) |
| `string readToken(string regex)`/`string readWord(string regex)`                                                                                                  | Đọc một chuỗi, chuỗi đó bắt buộc phải khớp với `regex` |
| `long long readLong()`                                                                                                                                            | Đọc một số nguyên 64 bit |
| `long long readLong(long long L, long long R)`                                                                                                                    | Đọc một số nguyên 64 bit, bắt buộc nằm trong $[L,R]$ |
| `vector<long long> readLongs(int n, long long L, long long R)`                                                                                                    | Đọc $N$ số nguyên 64 bit, tất cả bắt buộc nằm trong $[L,R]$ |
| `int readInt()`/`int readInteger()`                                                                                                                               | Đọc một số nguyên 32 bit |
| `int readInt(int L, int R)`/`int readInteger(L, R)`                                                                                                               | Đọc một số nguyên 32 bit, bắt buộc nằm trong $[L,R]$ |
| `vector<int> readInts(int n, int L, int R)`/`vector<int> readIntegers(int n, int L, int R)`                                                                       | Đọc $N$ số nguyên 32 bit, tất cả bắt buộc nằm trong $[L,R]$ |
| `double readReal()`/`double readDouble()`                                                                                                                         | Đọc một số thực dấu phẩy động độ chính xác kép |
| `double readReal(double L, double R)`/`double readDouble(double L, double R)`                                                                                     | Đọc một số thực dấu phẩy động độ chính xác kép, bắt buộc nằm trong $[L,R]$ |
| `double readStrictReal(double L, double R, int minPrecision, int maxPrecision)`/`double readStrictDouble(double L, double R, int minPrecision, int maxPrecision)` | Đọc một số thực dấu phẩy động độ chính xác kép, bắt buộc nằm trong $[L,R]$, số chữ số thập phân bắt buộc nằm trong $[minPrecision,maxPrecision]$, và không được dùng định dạng bất thường như ký pháp khoa học |
| `string readString()`/`string readLine()`                                                                                                                         | Đọc một dòng (bao gồm ký tự xuống dòng), đồng thời đưa con trỏ luồng tới đầu dòng tiếp theo |
| `string readString(string regex)`/`string readLine(string regex)`                                                                                                 | Đọc một dòng, dòng đó bắt buộc phải khớp với `regex` |
| `void readEoln()`                                                                                                                                                 | Đọc EOLN (`LF` trong môi trường Linux, `CR LF` trong môi trường Windows) |
| `void readEof()`                                                                                                                                                  | Đọc EOF |
| `void quit(TResult verdict, string message)`/`void quitf(TResult verdict, string message, ...)`                                                                   | Kết thúc chương trình; nếu luồng hiện tại là `ouf` thì trả về kết quả chấm `verdict`, nếu không thì trả về `_fail`; xuất thông báo `message` |
| `void quitif(bool condition, TResult verdict, string message, ...)`                                                                                               | Nếu `condition` đúng, gọi `quitf(verdict, message, ...)` |

Nội dung còn được bổ sung tiếp...

## Biểu thức chính quy tối giản

Một số hàm nhập ở trên cho phép sử dụng tính năng "biểu thức chính quy tối giản", như sau:

-   Tập ký tự. Ví dụ, `[a-z]` biểu thị mọi chữ cái tiếng Anh viết thường, còn `[^a-z]` biểu thị mọi ký tự không phải chữ cái tiếng Anh viết thường.
-   Phạm vi. Ví dụ, `[a-z]{1,5}` biểu thị một chuỗi có độ dài trong khoảng $[1,5]$ và chỉ chứa chữ cái tiếng Anh viết thường.
-   Ký hiệu "hoặc". Ví dụ, `mike|john` biểu thị một trong hai chuỗi `mike` hoặc `john`.
-   Ký hiệu "tùy chọn". Ví dụ, `-?[1-9][0-9]{0,3}` biểu thị số nguyên khác 0 trong khoảng $[-9999,9999]$ (lưu ý dấu trừ tùy chọn).
-   Ký hiệu "lặp". Ví dụ, `[0-9]*` biểu thị không hoặc nhiều chữ số, còn `[0-9]+` biểu thị một hoặc nhiều chữ số.
-   Lưu ý rằng biểu thức chính quy trong Testlib là "tham lam" ("lặp" sẽ khớp nhiều nhất có thể). Ví dụ, `[0-9]?1` sẽ không khớp với `1` (vì `[0-9]?` đã khớp với `1`, khiến ký tự `1` còn lại trong mẫu không thể khớp).

## Đặt testlib.h trước tiên

Cần bảo đảm `testlib.h` là tệp tiêu đề **đầu tiên** được nạp bằng `#include`. Testlib sẽ ghi đè/vô hiệu hóa (thông qua xung đột tên) một số hàm liên quan đến ngẫu nhiên, chẳng hạn `random()`, để bảo đảm kết quả ngẫu nhiên không phụ thuộc môi trường. Điều này rất quan trọng với trình sinh dữ liệu; [trang trình sinh dữ liệu](./generator.md) sẽ giải thích chi tiết hơn.

## Dùng bí danh cho hạng mục

Với các lời gọi có ràng buộc như `readInt/readInteger/readLong/readDouble/readWord/readToken/readString/readLine`, nên truyền thêm một tham số `string` ở cuối, tức bí danh của hạng mục đang đọc, để thông báo lỗi dễ hiểu hơn. Ví dụ, nếu dùng `inf.readInt(1, 100, "n")` thay vì `inf.readInt(1, 100)`, thông báo lỗi sẽ là `FAIL Integer parameter [name=n] equals to 0, violates the range [1, 100]`.

## Dùng `ensuref/ensure()`

Hai hàm này dùng để kiểm tra điều kiện có đúng hay không (tương tự `assert()`). Ví dụ, để kiểm tra $x_i \neq y_i$, có thể dùng:

```cpp
ensuref(x[i] != y[i], "Graph can't contain loops");
```

Cũng có thể dùng phần giữ chỗ (placeholder) kiểu C, chẳng hạn:

```cpp
ensuref(s.length() % 2 == 0,
        "String 's' should have even length, but s.length()=%d",
        int(s.length()));
```

Hàm này có phiên bản rút gọn `ensure()`: có thể dùng trực tiếp `ensure(x > y)` mà không thêm nội dung giải thích (hàm này cũng không hỗ trợ thêm nội dung giải thích). Nếu điều kiện không thỏa, lỗi sẽ là `FAIL Condition failed: "x > y"`. Trong nhiều trường hợp, thông báo lỗi không có giải thích bổ sung như vậy không thân thiện, nên ưu tiên dùng `ensuref()` kèm nội dung giải thích thay vì dùng `ensure()`.

???+ warning "Cảnh báo"
    Lưu ý sự khác nhau giữa `ensuref/ensure()` toàn cục và hàm thành viên.
    
    Hàm toàn cục `::ensuref/ensure()` thường dùng trong trình sinh dữ liệu và trình xác thực dữ liệu; nếu kiểm tra thất bại, chúng sẽ luôn trả về `_fail`.
    
    Hàm thành viên `InStream::ensuref/ensure()` thường dùng để xác định đầu ra của thí sinh và chương trình tham chiếu có hợp lệ hay không. Khi `InStream` là `ouf`, chúng trả về `_wa`; khi là `inf` (thông thường không kiểm tra dữ liệu đầu vào trong trình kiểm tra đáp án, việc này nên được thực hiện trong trình xác thực dữ liệu) hoặc `ans`, chúng trả về `_fail`. Xem thêm phần viết hàm `readAns` trong [trang trình kiểm tra đáp án](./checker.md).

**Bài viết này chủ yếu được dịch và tổng hợp từ loạt bài [Testlib - Codeforces](https://codeforces.com/testlib). Kho GitHub của `testlib.h` là [MikeMirzayanov/testlib](https://github.com/MikeMirzayanov/testlib).**

[^1]: [Liên kết issue](https://github.com/MikeMirzayanov/testlib/issues/115#issuecomment-863414940)
