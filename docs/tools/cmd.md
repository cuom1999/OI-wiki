author: StudyingFather, ayalhw, qinyihao, CoderOJ, mcendu, Libaray

Tuy giao diện đồ họa ngày càng làm được nhiều việc hơn, vẫn có rất nhiều thao tác nâng cao cần xử lý bằng dòng lệnh.

Trang này giới thiệu ngắn gọn một số cách sử dụng dòng lệnh.

## Cơ bản

Windows có sẵn hai giao diện dòng lệnh. `Command Prompt` (`Dấu nhắc lệnh`, `cmd`) là giao diện cũ hơn, chức năng cũng khá đơn giản. PowerShell là giao diện dòng lệnh mới hơn, có nhiều tính năng tích hợp nhưng khá nặng. Cả hai đều có thể tìm thấy trong menu Start.

Các hệ thống kiểu Unix (bao gồm macOS và Linux, dưới đây gọi chung là Unix) có hai trường hợp: có giao diện đồ họa và không có giao diện đồ họa. Nếu hệ thống có giao diện đồ họa (ví dụ dùng macOS, hoặc Linux có cài GNOME, KDE, v.v.), thường có thể mở dòng lệnh bằng chương trình tên là `Terminal` (`Thiết bị đầu cuối`) hoặc `Console` (`Bảng điều khiển`). Hệ thống không có giao diện đồ họa sẽ tự động đi vào dòng lệnh sau khi khởi động xong.

Dòng lệnh trên Windows trông như sau:

```doscon
C:\Users\chtholly>
```

Lệnh nhập trên dòng lệnh sẽ xuất hiện sau dấu `>`.

```doscon
C:\Users\chtholly>echo "Hello World!"
```

Dòng lệnh trên Unix trông như sau (lấy Debian/Ubuntu làm ví dụ; các hệ thống khác nhìn chung tương tự):

```console
chtholly@seniorious:~$
```

Lệnh nhập trên dòng lệnh sẽ xuất hiện sau dấu `$`.

```console
chtholly@seniorious:~$ echo "Hello World!"
```

Nếu đăng nhập dòng lệnh trên Unix bằng `root`, dấu `$` sẽ được thay bằng `#`:

```console
root@seniorious:~# apt-get install gcc
```

Trước dấu `>`, `$` hoặc `#` trên dòng lệnh sẽ hiển thị một đường dẫn. Đường dẫn đó là thư mục làm việc, hay thư mục hiện tại. Trên Unix, thư mục hiện tại đôi khi được hiển thị dưới dạng như `~/folder`; ký tự `~` ở đầu chính là thư mục nhà của người dùng hiện đang đăng nhập. Vị trí thư mục nhà của người dùng `chtholly` khác nhau tùy hệ thống; trên Linux, nó nằm ở `/home/chtholly`, còn trên macOS, nó nằm ở `/Users/chtholly`.

## Cú pháp và các lệnh thường dùng[^1]

### Liên quan đến hệ thống tệp

Trước hết cần phân biệt hai cách mô tả vị trí trong hệ thống tệp: đường dẫn tương đối và đường dẫn tuyệt đối.

-   Đường dẫn tương đối: mô tả vị trí bằng quan hệ so với đường dẫn hiện tại. Ví dụ, nếu đường dẫn hiện tại là `~/folder`, thì `./a.cpp` chỉ tệp `~/folder/a.cpp`. **Khi đường dẫn hiện tại thay đổi, vị trí mà đường dẫn tương đối mô tả cũng có thể thay đổi**.

-   Đường dẫn tuyệt đối: mô tả vị trí bằng đường dẫn đầy đủ. Ví dụ, `~/folder/a.cpp` là một đường dẫn tuyệt đối. **Vị trí mà đường dẫn tuyệt đối mô tả không thay đổi theo đường dẫn hiện tại**.

    Trên Windows/Unix, `.` biểu thị thư mục hiện tại, còn `..` biểu thị thư mục cha của thư mục hiện tại. Riêng trên Unix, `~` biểu thị thư mục nhà của người dùng (lưu ý rằng `~` được shell mở rộng, nên có thể không dùng được ở những ngữ cảnh khác).

Trên Unix, lệnh `pwd` có thể in ra thư mục hiện tại (trong Windows PowerShell cũng có lệnh này, nhưng trong Windows Command Prompt thì không; xem ghi chú bên dưới để biết thêm chi tiết). Trong Windows/Unix, lệnh `cd <thư mục>` đều có thể chuyển thư mục hiện tại. Ví dụ, `cd folder` sẽ chuyển tới thư mục con `folder` của thư mục hiện tại; `cd ..` sẽ chuyển tới thư mục cha của thư mục hiện tại.

???+ note "Ghi chú riêng cho Windows Command Prompt"
    Trong Windows Command Prompt không có lệnh `pwd`, nhưng có thể dùng lệnh `cd` không kèm tham số để thay thế gần đúng.

    Đồng thời, cần lưu ý rằng khi dùng lệnh `cd` trong Windows Command Prompt để chuyển thư mục, nếu **ký tự ổ đĩa của thư mục cần chuyển tới khác với ký tự ổ đĩa của thư mục hiện tại**, thì thư mục hiện tại sẽ không đổi. Có thể gõ thêm một lần ký tự ổ đĩa của đường dẫn cần chuyển tới, hoặc dùng lệnh `cd /d <thư mục>` để chuyển ổ đĩa cùng lúc. Hai cách tương ứng có giao diện dòng lệnh như sau:

    ```doscon
    C:\Users\Libaray>cd D:\Codes
    C:\Users\Libaray>D:
    D:\Codes>
    ```

    ```doscon
    C:\Users\Libaray>cd /d D:\Codes
    D:\Codes>
    ```

Trên Windows, dùng lệnh `dir` để liệt kê danh sách tệp trong thư mục hiện tại. Trên Unix, lệnh liệt kê danh sách tệp là `ls`. Riêng trong PowerShell, cũng có thể dùng lệnh `ls` giống Unix.

Trên Windows, dùng lệnh `md <thư mục>` hoặc `mkdir <thư mục>` để tạo một thư mục mới, dùng lệnh `rd <thư mục>` hoặc `rmdir <thư mục>` để xóa một thư mục. Trên Unix, hai lệnh tương ứng là `mkdir` và `rmdir`. Cần lưu ý rằng **trước khi dùng `rd` hoặc `rmdir` để xóa một thư mục, thư mục đó phải rỗng**. Nếu muốn xóa thư mục không rỗng (cùng toàn bộ tệp bên trong), trên Unix có thể chạy lệnh `rm -r <thư mục>`, còn trên Windows có thể chạy lệnh `rd /s <thư mục>`.

### Cơ chế chuyển hướng

> Tôi đã biên dịch một chương trình đọc từ chuẩn nhập và ghi ra chuẩn xuất. Nhưng tệp nhập và tệp xuất đều rất lớn; khi đó có cách nào chuyển hướng nhập sang tệp nhập chỉ định, và chuyển hướng xuất sang tệp xuất chỉ định không?

Có thể làm bằng lệnh sau.

```console
$ command < input > output
```

Ví dụ, lệnh `./prog < 1.in > 1.out` sẽ làm cho chương trình `prog` đọc dữ liệu từ `1.in` trong thư mục hiện tại, đồng thời ghi đè kết quả xuất của chương trình vào `1.out`.

???+ warning "Cảnh báo"
    Nội dung ban đầu của `1.out` sẽ bị ghi đè. Nếu muốn ghi nối vào cuối tệp xuất ban đầu, dùng `>>`, tức là chuyển hướng xuất theo dạng `./prog >> 1.out`.

Lưu ý rằng PowerShell chỉ hỗ trợ chuyển hướng xuất, không hỗ trợ chuyển hướng nhập.

Đa số OJ đều dùng cơ chế chuyển hướng theo cách này. Chương trình thí sinh nộp sử dụng đầu vào/đầu ra chuẩn; thông qua cơ chế chuyển hướng, hệ thống có thể cho chương trình của thí sinh đọc dữ liệu từ tệp nhập cho trước, xuất ra tệp xuất chỉ định, rồi chấm bằng cách so sánh tệp.

### Thực thi chương trình

Với một chương trình thực thi hoặc một tập lệnh batch, chỉ cần nhập trực tiếp tên tệp của nó trong dòng lệnh là có thể chạy.

Khi thực thi một tệp, dòng lệnh sẽ không tìm qua tất cả thư mục. Biến môi trường `PATH` mô tả phạm vi đường dẫn tìm kiếm của dòng lệnh; dòng lệnh sẽ tìm tệp mục tiêu trong các đường dẫn thuộc `PATH`.

Đối với hệ thống Windows, **thư mục hiện tại cũng nằm trong phạm vi tìm kiếm mặc định của dòng lệnh**. Ví dụ, trong Windows, nhập lệnh `hello` có thể chạy `hello.exe` trong thư mục hiện tại. Tuy nhiên trong PowerShell, mặc định PowerShell không tìm chương trình thực thi trong thư mục hiện tại (điều này nhất quán với hành vi trên Unix), nên trong PowerShell cần dùng đường dẫn tương đối hoặc đường dẫn tuyệt đối để gọi chương trình thực thi trong thư mục hiện tại, chẳng hạn `.\hello.exe`; nếu không sẽ xuất hiện lỗi sau:

```ps1con
PS> hello
hello: The term 'hello' is not recognized as a name of a cmdlet,
function, script file, or executable program.
Check the spelling of the name, or if a path was included, verify that
the path is correct and try again.

Suggestion [3,General]: The command hello was not found, but does exist
in the current location. PowerShell does not load commands from the
current location by default. If you trust this command, instead type:
".\hello". See "get-help about_Command_Precedence" for more details.
```

Trong hệ thống Unix, **thư mục hiện tại không nằm trong phạm vi tìm kiếm mặc định của dòng lệnh**, nên lệnh chạy chương trình `hello` trong thư mục hiện tại trở thành `./hello`:

```console
$ hello
hello: command not found
$ ./hello
Hello World!
```

### Tổng kết

Các cách dùng nêu trên chỉ là một phần nhỏ của các lệnh dòng lệnh; vẫn còn rất nhiều lệnh chưa được đề cập. Nhập lệnh trợ giúp `help` trong dòng lệnh để tra cứu toàn bộ lệnh cơ bản và công dụng của chúng.

Bảng dưới đây đối chiếu lệnh trên Windows và Unix để tham khảo.

| Phân loại | Hệ thống Windows | Hệ thống Unix |
| --------- | ---------------- | ------------- |
| Danh sách tệp | `dir` | `ls` |
| Chuyển thư mục | `cd` | `cd` |
| Tạo thư mục | `md` | `mkdir` |
| Xóa thư mục | `rd` | `rmdir` |
| So sánh tệp | `fc` | `diff` |
| Sao chép tệp | `copy` | `cp` |
| Di chuyển tệp | `move` | `mv` |
| Đổi tên tệp | `ren` | `mv` |
| Xóa tệp | `del` | `rm` |

## Biên dịch/gỡ lỗi bằng dòng lệnh

Xem: [Biên dịch và gỡ lỗi bằng dòng lệnh](compile-debug.md).

## Mẹo sử dụng dòng lệnh

### Tự động hoàn thành

Tự động hoàn thành là một trong những chức năng cơ bản do shell cung cấp, chủ yếu dùng để giảm lượng nhập liệu và giảm khả năng gõ sai khi dùng dòng lệnh.

Thông thường, phím tắt dùng để tự động hoàn thành là <kbd>Tab</kbd>; sau khi nhấn, shell sẽ dựa vào các ký tự đã nhập để hoàn thành thông tin.

Các shell khác nhau cung cấp khả năng tự động hoàn thành không hoàn toàn giống nhau.

Dưới đây là khả năng tự động hoàn thành của một số shell thường gặp[^autocomplete]:

| Shell | Khả năng tự động hoàn thành (phạm vi hoàn thành) |
| ----- | ---------------------------------------- |
| cmd (console truyền thống của Windows) | Đường dẫn tệp |
| PowerShell | Đường dẫn tệp, tên lệnh trong PATH, tên lệnh tích hợp, tên hàm, tham số lệnh; hỗ trợ khớp mờ, tự động sửa lỗi |
| Bash | Đường dẫn tệp, tên lệnh trong PATH, tên lệnh tích hợp, tên hàm, tham số lệnh |
| Zsh | Đường dẫn tệp, tên lệnh trong PATH, tên lệnh tích hợp, tên hàm, tham số lệnh; hỗ trợ khớp mờ, tự động sửa lỗi và gợi ý |
| Fish | Đường dẫn tệp, tên lệnh trong PATH, tên lệnh tích hợp, tên hàm, tham số lệnh; hỗ trợ khớp mờ, có thể hiển thị chức năng của tham số khi tự động hoàn thành, tự động sửa lỗi và gợi ý |

???+ note "Ghi chú"
    Một số chức năng của PowerShell cần nạp PSReadline Module hoặc cần nằm trong PowerShell ISE.

    Chức năng tự động hoàn thành của Bash thường cần một gói tên là `bash-completions` để có đầy đủ tính năng; tệp hoàn thành của một số phần mềm được cung cấp kèm theo gói phần mềm đó.

    Chức năng tự động hoàn thành đầy đủ của Zsh cần phối hợp với các tệp định nghĩa trước của người dùng (thường được cài cùng gói Zsh hoặc gói phần mềm tương ứng).

    Fish cung cấp chức năng tự động hoàn thành tốt và đầy đủ trong cấu hình mặc định, nhưng tệp hoàn thành của một số phần mềm chưa được dự án chính thức bao phủ vẫn do chính phần mềm đó cung cấp.

### Tài liệu trợ giúp

Các chương trình chạy dưới dòng lệnh thường kèm theo "trợ giúp". Trên Windows, thường dùng `command /?` hoặc `command -?` để lấy trợ giúp; trên hệ thống Unix-like (ví dụ Linux), thường dùng `command --help` hoặc `command -h` (nhưng "trợ giúp" trên BSD thường quá ngắn gọn nên khó dùng).

Ngoài ra, trên hệ thống kiểu Unix còn có sổ tay (`manual`) có thể xem bằng `man command`, thường chi tiết hơn trợ giúp ngắn của chương trình.

### time tích hợp và GNU time

Khi kiểm tra thời gian chạy của chương trình, thường có thể dùng lệnh `time`.

Tuy nhiên, lệnh này có hai dạng tương ứng trong hệ thống: một dạng là lệnh tích hợp sẵn của một số shell (chẳng hạn Bash), dạng còn lại là GNU time (một phần mềm riêng). Hai dạng này có một số khác biệt.

Thông thường, khi dùng trực tiếp `time` trong Bash thì phiên bản được gọi là phiên bản tích hợp của Bash. Có thể dùng biến môi trường `TIMEFORMAT` để điều khiển định dạng xuất; ví dụ đặt nó thành `%3lR` để xuất thời gian chạy thực tế với độ chính xác ba chữ số, hoặc `%3lU` để xuất thời gian chạy trong không gian người dùng với độ chính xác ba chữ số.[^bash-time-format]

Nếu muốn gọi phiên bản GNU của time, cần dùng `\time` hoặc `/usr/bin/time`; tuy nhiên định dạng xuất của nó không dễ đọc, nên có thể thêm tham số `-p` (tức `\time -p`) để nhận đầu ra dễ đọc.

## Ống dẫn

Giả sử có hai chương trình A và B đều dùng đầu vào/đầu ra chuẩn. Làm thế nào để chuyển hướng đầu ra của A vào đầu vào của B?

Có thể dùng cách chuyển hướng đã nói ở trên: trước hết chuyển hướng đầu ra của A vào một tệp tạm, rồi chuyển hướng đầu vào của B vào tệp tạm đó.

Nhưng cách này rất kém hiệu quả: không chỉ phải tạo tệp mới, thao tác IO đĩa cũng có thể trở thành nút thắt, và hai chương trình không thể chạy đồng thời; phải chờ A chạy xong mới bắt đầu chạy B. Có cách nào tốt hơn không?

Có, đó chính là **ống dẫn**. Cách dùng rất đơn giản:

```console
$ A | B
```

Lệnh này tạo một ống dẫn trong bộ nhớ, rồi khởi động hai chương trình cùng lúc. Mỗi lần chương trình A muốn xuất dữ liệu, dữ liệu đó được chuyển hướng vào ống dẫn; bản thân ống dẫn không lưu dữ liệu (chỉ có một bộ đệm rất nhỏ). Trước khi B đọc, thao tác xuất của A sẽ bị chặn; sau khi B đọc dữ liệu vào, thao tác xuất của A mới tiếp tục. Nhờ vậy, các vấn đề trên được giải quyết gọn gàng: không có thao tác IO đĩa, hai đoạn mã chạy đồng thời, và cũng không tốn thêm nhiều bộ nhớ để lưu kết quả trung gian.

### Ống dẫn có tên

Đôi khi yêu cầu không chỉ là chuyển hướng đầu ra của một chương trình vào đầu vào của chương trình khác. Ví dụ, khi làm bài tương tác IO, thường cần chuyển hướng đầu ra của A vào đầu vào của B, và chuyển hướng đầu ra của B vào đầu vào của A; khi đó ống dẫn thông thường nói ở trên không làm được. Còn chuyển hướng vào tệp lại không thể cho hai chương trình chạy đồng thời. Lúc này cần một ống dẫn trông giống như tệp: ống dẫn có tên.

Trong hệ thống Unix, có thể dùng lệnh sau để tạo ống dẫn có tên (ví dụ đặt tên là `my_pipe`):

```console
$ mkfifo my_pipe
```

Lúc này dùng lệnh `ls` để liệt kê tệp trong thư mục hiện tại sẽ thấy xuất hiện thêm một tệp `my_pipe|`. Tệp này chính là ống dẫn có tên vừa tạo; dấu `|` sau tên tệp cho biết đây là tệp ống dẫn. Sau đó, có thể đọc ghi vào ống dẫn này giống như chuyển hướng tệp.

Với ống dẫn có tên, có thể cho hai chương trình tương tác theo cách sau:

```console
$ mkfifo input output
$ ./checker > input < output # Cần viết > input trước; nếu không shell sẽ mở ống dẫn output trước, khi ống dẫn này chưa có dữ liệu nên checker sẽ bị chặn.
$ ./my_code < input > output
```

Sau khi dùng xong, có thể dùng lệnh `rm` để xóa ống dẫn có tên như tệp thông thường.

## Tài liệu tham khảo và chú thích

[^1]: Phụ lục A "Môi trường và phương pháp phát triển" trong sách "Nhập môn kinh điển về thi đấu thuật toán (bản thứ 2)" của Lưu Nhữ Giai

[^autocomplete]: [Comparison\_of\_command\_shells#Interactive\_features](https://en.wikipedia.org/wiki/Comparison_of_command_shells#Interactive_features)

[^bash-time-format]: <https://unix.stackexchange.com/a/70655>
