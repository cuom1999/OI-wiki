author: Frankaiyou, henrytbtrue, zymooll

## Thư viện chuẩn C

Thư viện chuẩn C thao tác trên mảng ký tự `char[]`/`const char*`.

Tham khảo: [fprintf](https://en.cppreference.com/w/c/io/fprintf), [fscanf](https://en.cppreference.com/w/c/io/fscanf), [xâu byte kết thúc bằng null](https://en.cppreference.com/w/c/string/byte)

-   `printf("%s", s)`: dùng `%s` để xuất một xâu (mảng ký tự).
-   `scanf("%s", &s)`: dùng `%s` để đọc một xâu (mảng ký tự).
-   `sscanf(const char *__source, const char *__format, ...)`: đọc biến từ xâu `__source`, ví dụ `sscanf(str,"%d",&a)`.
-   `sprintf(char *__stream, const char *__format, ...)`: xuất nội dung theo xâu định dạng `__format` vào `__stream`, ví dụ `sprintf(str,"%d",i)`.
-   `strlen(const char *str)`: trả về số ký tự từ `str[0]` tới trước `'\0'`. Lưu ý, khi chưa bật tối ưu O2, nếu viết thao tác này trong điều kiện vòng lặp thì độ phức tạp là $\Theta(N)$.
-   `strcmp(const char *str1, const char *str2)`: so sánh `str1` và `str2` theo thứ tự từ điển. Nếu `str1` nhỏ hơn thì trả về số âm, nếu bằng nhau trả về `0`, nếu `str1` lớn hơn thì trả về số dương. Lưu ý, không nên đơn giản cho rằng giá trị trả về chỉ có `0`, `1`, `-1`; trên các nền tảng khác nhau, giá trị trả về tuân theo dấu âm/dương nhưng không nhất thiết đúng là `0`, `1`, `-1`.
-   `strcpy(char *str, const char *src)`: sao chép ký tự từ `src` sang `str`; `str` và `src` đều là con trỏ đầu mảng ký tự, giá trị trả về là `str`, bao gồm ký tự kết thúc null `'\0'`.
-   `strncpy(char *str, const char *src, int cnt)`: sao chép nhiều nhất `cnt` ký tự vào `str`; nếu `src` kết thúc trước khi đủ `cnt`, ghi ký tự rỗng vào `str` cho tới khi tổng cộng đã ghi `cnt` ký tự.
-   `strcat(char *str1, const char *str2)`: nối `str2` vào cuối `str1`, thay `'\0'` ở cuối `str1` bằng `*str2`, rồi trả về `str1`.
-   `strstr(char *str1, const char *str2)`: nếu `str2` là xâu con của `str1`, trả về địa chỉ lần xuất hiện đầu tiên của `str2` trong `str1`; nếu không, trả về `NULL`.
-   `strchr(const char *str, int c)`: tìm vị trí xuất hiện đầu tiên của ký tự `c` trong xâu `str` và trả về địa chỉ vị trí đó. Nếu không tìm thấy thì trả về `NULL`.
-   `strrchr(const char *str, int c)`: tìm vị trí xuất hiện cuối cùng của ký tự `c` trong xâu `str` và trả về địa chỉ vị trí đó. Nếu không tìm thấy thì trả về `NULL`.

## Thư viện chuẩn C++

Thư viện chuẩn C++ thao tác trên đối tượng xâu [`std::string`](../lang/csl/string.md), đồng thời cũng cung cấp khả năng tương thích với mảng ký tự.

Tham khảo: [std::basic\_string](https://en.cppreference.com/w/cpp/string/basic_string), [std::basic\_string\_view](https://en.cppreference.com/w/cpp/string/basic_string_view)

-   Toán tử `+` được nạp chồng; khi hai vế của `+` có kiểu `string/char/char[]/const char*`, có thể nối hai biến này và trả về xâu đã nối (`string`).
-   Vế phải của toán tử gán `=` có thể là `const string/string/const char*/char*`.
-   Toán tử truy cập `[cur]` trả về tham chiếu tới vị trí `cur`.
-   Hàm truy cập `data()/c_str()` trả về con trỏ `const char*` có nội dung giống `string` đó.
-   Hàm dung lượng `size()` trả về số ký tự của xâu.
-   `find(ch, start = 0)` tìm và trả về vị trí của ký tự `ch` bắt đầu từ `start`; `rfind(ch)` tìm từ cuối về đầu và trả về vị trí của ký tự `ch` đầu tiên tìm được (đều đánh số từ `0`; nếu không tìm thấy, trả về `-1`).
-   `substr(start, len)` cắt từ vị trí `start` (đánh số từ `0`) một xâu có độ dài `len`; nếu bỏ qua `len`, đoạn cắt kéo dài tới cuối xâu.
-   `append(s)` thêm `s` vào cuối xâu.
-   `append(s, pos, n)` nối `n` ký tự của xâu `s` bắt đầu từ `pos` vào cuối xâu hiện tại.
-   `replace(pos, n, s)` xóa `n` ký tự bắt đầu từ `pos`, rồi chèn xâu `s` tại `pos`.
-   `erase(pos, n)` xóa `n` ký tự bắt đầu từ `pos`.
-   `insert(pos, s)` chèn xâu `s` tại vị trí `pos`.
-   `std::string` nạp chồng các toán tử so sánh logic, với độ phức tạp $\Theta(N)$.
