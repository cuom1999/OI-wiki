author: Enter-tainer, ouuan, Xeonacid, Ir1d, partychicken, ChungZH, LuoshuiTianyi, Kewth, s0cks5, Doveqise, StudyingFather, SukkaW, SodaCris, SkyeYoung, 383494, danielqfmai

Vim - trình soạn thảo văn bản có mặt ở khắp nơi.

## Giới thiệu

Vim là một trình soạn thảo văn bản phát triển từ vi. Vim cung cấp nhiều chức năng phục vụ lập trình như hoàn thành mã, biên dịch, nhảy tới lỗi, v.v., nên được dùng rộng rãi trong cộng đồng lập trình viên.

## Cài đặt

Hệ thống Linux thường có sẵn Vim; mở trình dòng lệnh và nhập `vim` là có thể dùng.

Nếu cần cài thủ công, [trang web chính thức](https://www.vim.org/) của Vim có [tài liệu hướng dẫn tải xuống](https://www.vim.org/download.php); biên dịch và cài đặt theo nhu cầu.

## Chế độ và phím thường dùng của Vim

Các thao tác cơ bản của Vim sẽ được giới thiệu trong hướng dẫn nhập môn đi kèm Vim. Mở trình dòng lệnh và nhập `vimtutor` để vào hướng dẫn này.

Thông thường cần khoảng hai đến ba mươi phút để làm quen sơ bộ với các thao tác này.

### Chế độ lệnh

Đây là chế độ mặc định sau khi vào Vim.

Ở trạng thái này, thao tác gõ phím sẽ được Vim nhận diện là lệnh chứ không phải nhập ký tự. Ví dụ, lúc này nếu nhấn <kbd>i</kbd>, Vim sẽ không nhập một ký tự; <kbd>i</kbd> được xem là một lệnh.

Phím di chuyển của Vim là <kbd>↑</kbd>, <kbd>↓</kbd>, <kbd>←</kbd>, <kbd>→</kbd>, hoặc <kbd>h</kbd>, <kbd>j</kbd>, <kbd>k</kbd>, <kbd>l</kbd>.

```text
        ↑(k)
        ^
(h)← <     > →(l)
        v
        ↓(j)
```

Dưới đây là các lệnh thường dùng trong chế độ lệnh:

-   `i` chuyển sang chế độ nhập, bắt đầu nhập văn bản tại vị trí con trỏ hiện tại. Nhấn <kbd>Esc</kbd> để quay lại chế độ thường.
-   `x` dùng để xóa một ký tự phía sau con trỏ.
-   `:` chuyển sang chế độ lệnh dòng cuối để nhập lệnh ở dòng dưới cùng.
-   `a` chuyển sang chế độ nhập, bắt đầu nhập văn bản phía sau con trỏ.
-   `o` chuyển sang chế độ nhập và chèn một dòng mới bên dưới con trỏ; `O` chuyển sang chế độ nhập và chèn một dòng mới bên trên con trỏ.
-   `p` dán nội dung clipboard xuống bên dưới con trỏ; `P` dán nội dung clipboard lên bên trên con trỏ.
-   `dd` xóa cả dòng nơi con trỏ đang đứng.
-   Lệnh `d` cũng dùng để xóa, thường kết hợp với phím khác.
-   `u` hoàn tác lần sửa văn bản trước đó.
-   Lệnh `y` có thể sao chép vùng đã chọn. Cần nhấn `v` để vào chế độ trực quan rồi thao tác.
-   `yy` sao chép dòng hiện tại.
-   `Ctrl + r` làm lại thao tác vừa hoàn tác.
-   `:w` lưu tệp, thường kết hợp với `q` để lưu rồi thoát.
-   `:q` thoát Vim.
-   `:q!` buộc thoát Vim, không lưu sửa đổi.

Một số lệnh khác:

-   Lệnh `c` dùng để sửa, tương đương `di`.
-   Lệnh `=` có thể áp dụng tự động thụt lề theo định dạng mặc định cho các dòng đã chọn.
-   `==` tự động thụt lề dòng hiện tại.
-   Lệnh `.` có thể lặp lại lệnh vừa thực hiện.
-   Lệnh `gg` nhảy tới đầu mã; lệnh `G` nhảy tới đầu dòng cuối cùng của mã; thêm số trước lệnh `G` để nhảy tới dòng chỉ định.
-   `w` nhảy tới đầu từ tiếp theo; `e` nhảy tới cuối từ hiện tại hoặc từ tiếp theo; `b` nhảy tới đầu từ hiện tại hoặc từ trước đó; `0` nhảy tới đầu dòng; `$` nhảy tới cuối dòng. `w`, `e`, `0`, `$` cũng có thể kết hợp với lệnh khác, chẳng hạn `de`, `dw`, `d0` và `d$` lần lượt tương ứng với xóa đến cuối từ, xóa đến đầu từ tiếp theo, xóa đến đầu dòng và xóa đến cuối dòng.

Trong chế độ lệnh, nhấn <kbd>/</kbd>, phía dưới sẽ xuất hiện ô tìm kiếm. Nhập ký tự cần tìm rồi nhấn Enter để xem kết quả tìm kiếm. Nếu có nhiều kết quả, nhấn <kbd>n</kbd> để nhảy tới kết quả tiếp theo; nhấn <kbd>N</kbd> để nhảy tới kết quả trước đó.

Trong chế độ lệnh, nhấn <kbd>\*</kbd> để tìm từ dưới con trỏ hiện tại.

Nếu nhập một số `n` trước một lệnh, lệnh đó sẽ được lặp lại `n` lần.

### Chế độ nhập

Trong chế độ lệnh, nhấn <kbd>i</kbd> để vào chế độ nhập; nhấn <kbd>Esc</kbd> để quay lại chế độ lệnh.

Trong chế độ nhập, có thể dùng các phím sau:

-   Phím ký tự và tổ hợp với <kbd>Shift</kbd> để nhập ký tự.
-   <kbd>ENTER</kbd>, phím Enter, xuống dòng.
-   <kbd>BACK SPACE</kbd>, phím Backspace, xóa ký tự trước con trỏ.
-   <kbd>DEL</kbd>, phím Delete, xóa ký tự sau con trỏ.
-   Phím mũi tên, di chuyển con trỏ trong văn bản.
-   <kbd>HOME/END</kbd>, di chuyển con trỏ tới đầu/cuối dòng.
-   <kbd>Page Up/Page Down</kbd>, lật trang lên/xuống.
-   <kbd>Insert</kbd>, chuyển con trỏ giữa chế độ nhập/thay thế; con trỏ sẽ đổi thành vạch dọc/gạch dưới.
-   <kbd>ESC</kbd>, thoát chế độ nhập và chuyển sang chế độ lệnh.

Trong chế độ nhập, nhấn <kbd>Ctrl</kbd>+<kbd>o</kbd> để vào "chế độ nhập - lệnh"; sau khi thực hiện xong một thao tác, Vim sẽ tự quay lại chế độ nhập.

### Chế độ dòng lệnh cuối

Trong chế độ lệnh, nhấn <kbd>:</kbd> để vào chế độ dòng lệnh cuối.

Chế độ dòng lệnh cuối cho phép nhập các lệnh gồm một hoặc nhiều ký tự; chế độ này hỗ trợ nhiều lệnh khác nhau.

Trong chế độ dòng lệnh cuối, các lệnh cơ bản gồm:

-   `:help`/`:h` xem tài liệu trợ giúp trực tuyến tiếng Anh của Vim.
-   `:w` lưu tệp.
-   `:q` thoát Vim.
-   `:wq` lưu tệp rồi thoát Vim.
-   `:q!`/`:!q` buộc thoát Vim, không lưu sửa đổi.
-   `:e filename` mở tệp chỉ định trong thư mục hiện tại.
-   Lệnh `:s` là thay thế.

```vim
" Thay thế kết quả khớp str1 đầu tiên trong dòng hiện tại bằng str2
:s/str1/str2/
" Thay thế tất cả str1 trong dòng hiện tại bằng str2
:s/str1/str2/g
" Thay thế tất cả str1 trong dòng hiện tại bằng str2, hỏi trước khi thay
:s/str1/str2/gc
" Trong các dòng từ x1 đến x2, thay thế kết quả khớp str1 đầu tiên mỗi dòng bằng str2
:x1,x2 s/str1/str2/
" Trong các dòng từ x1 đến x2, thay thế tất cả str1 bằng str2
:x1,x2 s/str1/str2/g
" Trong các dòng từ x1 đến x2, thay thế tất cả str1 bằng str2, hỏi trước khi thay
:x1,x2 s/str1/str2/gc
" Thay thế kết quả khớp str1 đầu tiên trên mỗi dòng bằng str2
:%s/str1/str2/
" Thay thế tất cả str1 trong toàn bộ tệp bằng str2
:%s/str1/str2/g
" Thay thế tất cả str1 trong toàn bộ tệp bằng str2, hỏi trước khi thay
:%s/str1/str2/gc
```

Nếu dạng lệnh là `:! command`, lệnh đó sẽ được thực thi trong bash của trình dòng lệnh.

Nhấn <kbd>Esc</kbd> để thoát chế độ dòng lệnh cuối.

### Chế độ trực quan

Nhấn `v` để vào chế độ trực quan, thường dùng để chọn vùng. Nhấn `V` (`Shift+v`) để vào chế độ trực quan theo dòng, dùng để chọn dòng.

Nhấn <kbd>Ctrl</kbd>+<kbd>v</kbd> hoặc <kbd>Ctrl</kbd>+<kbd>q</kbd> để vào chế độ trực quan theo khối (visual block).

Sau khi vào chế độ trực quan theo khối, nhấn <kbd>I</kbd> hoặc <kbd>A</kbd> để vào chế độ chèn (tương đương `i` và `a`); sau khi thoát chế độ chèn, thay đổi đã thực hiện trên dòng hiện tại sẽ được áp dụng vào cùng vị trí trên mọi dòng được chọn. Cách này thường dùng để thêm chú thích hàng loạt.

Sau khi chọn, nhập `y` hoặc `d` cũng có thể thực hiện lệnh tương ứng.

Ba chế độ trực quan có thể chuyển đổi qua lại bằng phím.

## Phím tắt của Vim

Có thể tham khảo [sơ đồ phím tắt Vim đầy đủ từ nhập môn đến nâng cao](https://cenalulu.github.io/linux/all-vim-cheatsheat/).

## Kiến thức nâng cao

### Lệnh `.`

Người dùng Vim khó tránh khỏi cảm giác ngại khi phải lặp lại các sửa đổi văn bản, vì so với trình soạn thảo khác, Vim thường phải thêm hai lần nhấn phím: <kbd>Esc</kbd> và <kbd>i</kbd>. Tuy nhiên, Vim cung cấp lệnh lặp `.`; lệnh này phù hợp để lặp các thao tác thêm, sửa, xóa văn bản.

Lệnh `.` có thể lặp lại lệnh vừa thực hiện. Nhưng "lệnh" này không chỉ giới hạn ở một lệnh đơn lẻ; nó cũng có thể là tổ hợp `số + lệnh`; `vào chế độ nhập + nhập văn bản + Esc` cũng là một dạng lệnh. Vì vậy, dùng `.` hợp lý mới đạt hiệu suất cao nhất.

Ví dụ, mỗi dòng trong đoạn mã sau đều thiếu dấu chấm phẩy ở cuối:

```text
int a, b
cin >> a >> b
cout << a + b
return 0
```

Kết hợp `.` với lệnh `A` để di chuyển tới cuối dòng rồi chèn, có thể thêm dấu chấm phẩy ở cuối nhiều dòng nhanh hơn.

```vim
A;<Esc>
" Lặp lại lệnh bên dưới
j.
```

Ví dụ khác, trong đoạn mã sau, tên mảng ở năm phép gán phía sau đều bị viết sai:

```cpp
int check() {
  book[1] = 1, book[2] = 1, book[3] = 1, bok[1] = 1, bok[2] = 1, bok[3] = 1,
  bok[4] = 1, bok[5] = 1;
  return 0;
}
```

Sửa từng chỗ một sẽ tốn thời gian, còn lệnh `s` trong chế độ dòng lệnh lại sẽ sửa tất cả.

Cách sửa thứ nhất là dùng kết hợp với lệnh `s` trong chế độ thường (xóa ký tự tại con trỏ rồi vào chế độ nhập). Tới chữ cái đầu của tên mảng sai đầu tiên, nhấn `3s`/`cw`, nhập tên mảng đúng rồi thoát. Sau đó lần lượt di chuyển con trỏ tới từng chỗ và dùng lệnh `.`.

Cách sửa thứ hai tiết kiệm thời gian hơn là dùng chế độ tìm kiếm để sửa. Gõ `/bok`, nhấn Enter, dùng phím `n` tới chữ cái đầu của tên mảng sai đầu tiên, gõ `3s tên_mảng_mới <Esc>`, cuối cùng lặp lại `n.`.

Cách sửa thứ ba là lệnh tìm kiếm đơn giản `f`. Trong chế độ thường trên một dòng, `f + một ký tự` sẽ tìm ký tự đó trong dòng này và đưa con trỏ tới vị trí ký tự; nhấn `;` để tìm tiếp, `,` để tìm trước đó. Vì vậy với đoạn mã trên, chỉ cần gõ `fb;;;`, sau đó vào chế độ nhập để sửa, rồi dùng `;.` là được. Cách này phù hợp khi chỉ cần di chuyển trong cùng một dòng.

### Macro tự động hóa

Chức năng macro của Vim có thể lặp lại một chuỗi lệnh dài tùy ý.

Trước khi dùng macro cần "ghi" nó, tức là ghi lại một chuỗi thao tác phím rồi phát lại để lặp thao tác. Để bắt đầu ghi, trong chế độ thường hãy gõ `q`. Bước tiếp theo là chỉ định một phím lệnh cho macro được ghi; có thể nhấn bất kỳ chữ cái nào trong 26 chữ cái. Lúc này góc dưới bên trái sẽ hiển thị `recording @chữ_cái_vừa_chọn`. Sau đó có thể bắt đầu ghi lệnh. Tương tự, trong chế độ thường nhấn `q` để dừng ghi.

Cách dùng là nhấn `:` để vào chế độ dòng lệnh, gõ `@chữ_cái_đã_chọn`, rồi lệnh đã ghi trước đó sẽ được gọi.

Kết hợp `.` và macro, tức là ghi macro -> gọi macro -> dùng `.` lặp lệnh -> dùng `số + .`, có thể xử lý nhiều thao tác lặp với ít phím hơn.

### Lệnh normal

Lệnh này liên quan đến chế độ thường; tác dụng của nó là lặp lệnh trên các dòng chỉ định.

Nhấn `:` để vào chế độ dòng lệnh, rồi nhập lệnh sau:

```vim
:a,b normal command
```

hoặc:

```vim
:a,b norm command
```

Ý nghĩa của các lệnh trên là thực thi lệnh `command` trong chế độ thường trên các dòng từ `a` đến `b`.

Vì lệnh `normal` có thể được lệnh `.` gọi lặp lại, lại dễ hiểu, tần suất sử dụng của nó thậm chí còn cao hơn macro.

### Số + `.` + macro + normal

Ba loại lệnh trên có thể kết hợp với nhau. Ví dụ:

> Tôi tải một cuốn sách, cần biến mỗi chương của nó thành "tiêu đề" để tiện chuyển thành định dạng như mobi, hoặc tiện sinh mục lục để nhảy tới. Làm thế nào?

Dưới đây là quá trình xử lý bằng Vim:

1.  Nhấn <kbd>/</kbd> để mở ô tìm kiếm, nhập biểu thức chính quy để tìm.
2.  Dùng lệnh `q` bắt đầu ghi macro.
3.  Gõ lệnh `I#`, rồi nhấn <kbd>ESC</kbd>.
4.  Dùng lệnh `q` kết thúc ghi macro.
5.  Gõ `normal n@chữ_cái` để chuyển tới vị trí tiếp theo và lặp lại bước trước đó.
6.  Gõ `số + .` để lặp lại nhiều lần.

## Liên kết ngoài

-   [Trang chủ Vim](https://www.vim.org/)
-   [Cấu hình do tác giả gốc cung cấp](https://github.com/LuoshuiTianyi/Vim-for-OIWiki)
-   [Gỡ lỗi Vim: nhập môn termdebug](https://fzheng.me/2018/05/28/termdebug/)
-   [Vim scripting cheatsheet](https://devhints.io/vimscript)
-   [Learn Vimscript the Hard Way](https://learnvimscriptthehardway.stevelosh.com)
-   [Linux vi/vim | Runoob Tutorial](https://www.runoob.com/linux/linux-vim.html)
