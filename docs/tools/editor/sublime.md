## Giới thiệu

Sublime Text (sau đây gọi tắt là ST; khi cần phân biệt phiên bản sẽ thêm số ở sau, nếu không ghi thì áp dụng cho mọi phiên bản) là một trình soạn thảo văn bản nhẹ, hỗ trợ tô sáng cú pháp và hoàn thành mã cho nhiều ngôn ngữ. ST có khả năng mở rộng cao, có chế độ Vim, và cơ chế hot exit đặc biệt giúp giảm đáng kể khả năng mất tệp.

Trong bản NOI Linux mới, phiên bản được hỗ trợ là bản cuối của ST3, tức 3.2.2[^ref1], vì vậy trang này chủ yếu lấy ST3 làm ví dụ. Hiện nay bản chính thức của ST4 đã được phát hành[^ref2]; nếu vẫn dùng ST3, chương trình sẽ nhắc cập nhật.

Những khác biệt quan trọng giữa ST4 và ST3 sẽ được bổ sung riêng. Trong phần giới thiệu, nếu một mục đã có bản dịch trong ST3 thì dùng tên tiếng Việt tương ứng, nếu không thì giữ tên tiếng Anh trong ST4.

## Cài đặt

Cách cài ST4 xem tại [trang tải Sublime Text 4](https://www.sublimetext.com/download).

Cách cài ST3 xem tại [trang tải Sublime Text 3](https://www.sublimetext.com/3).

???+ note "Nhắc mua bản quyền"
    ST là phần mềm trả phí, nhưng có chế độ dùng thử không giới hạn thời gian. Bản dùng thử không thiếu chức năng, nhưng thỉnh thoảng sẽ hiện cửa sổ nhắc kích hoạt.

## Plugin và tùy biến

### Việt hóa hoặc bản địa hóa giao diện

ST không hỗ trợ tiếng Trung sẵn; nếu cần giao diện tiếng Trung thì phải cài plugin bản địa hóa. Với người dùng tiếng Việt, cách cài plugin dưới đây cũng là quy trình chung để cài các gói mở rộng khác.

#### Cài trình quản lý plugin

Sau khi mở ST, nhấn <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd> để gọi hộp lệnh, nhập `Install` rồi nhấn Enter (lệnh đầy đủ là `Install Package Control`, không phân biệt chữ hoa chữ thường). Lúc này ở góc dưới bên trái thường sẽ thấy một dấu `=` di chuyển qua lại liên tục. Khi Package Control cài xong (hoặc thất bại), sẽ có cửa sổ thông báo; thời gian tải cụ thể phụ thuộc vào mạng.

Nếu cửa sổ hoàn tất báo cài đặt thất bại (liên quan đến mạng), cần tải thủ công [Package Control](https://packagecontrol.io/Package%20Control.sublime-package) rồi đặt tệp đã tải vào thư mục `\Installed Packages` trong thư mục dữ liệu của ST. Chờ một lát, ST sẽ tự nhận diện plugin này (đôi khi cần khởi động lại ST).

???+ note "Đường dẫn thư mục dữ liệu của ST"
    Trên Windows, nếu trong **thư mục cài đặt** của ST có thư mục `\data`, ST sẽ tự động dùng (hoặc khởi tạo) thư mục đó làm thư mục dữ liệu.

    Đường dẫn của ST3 thường là `C:\Users\tên_người_dùng\AppData\Roaming\Sublime Text 3`, còn ST4 thường là `C:\Users\tên_người_dùng\AppData\Roaming\Sublime Text`. ST sẽ tìm đường dẫn ứng với phiên bản trước, nếu không tồn tại thì tìm đường dẫn của phiên bản thấp hơn, nếu vẫn không có thì tạo mới và khởi tạo.

    Trong Ubuntu 20.04.1 dùng bởi NOI Linux, thư mục dữ liệu của ST3 là `$HOME/.config/sublime-text-3`, còn của ST4 là `$HOME/.config/sublime-text`; quy tắc sử dụng cụ thể giống môi trường Windows.

    Có thể dùng `Preferences->Browse Packages...` để xem nhanh thư mục `\Packages` nằm dưới đường dẫn thư mục dữ liệu.

#### Cài plugin bản địa hóa tiếng Trung

Nhấn lại <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd>, nhập `Install` rồi nhấn Enter (lệnh đầy đủ là `Package Control: Install Package`), đợi tải xong. Tiếp theo sẽ thấy giao diện như sau:

![](./images/sublime3-1.png)

Nhập `Chinese`, chọn ChineseLocalizations rồi nhấn Enter, chờ cài đặt hoàn tất. Sau khi xong, giao diện sẽ tự chuyển sang tiếng Trung (nếu là ST4, vì plugin bản địa hóa chưa cập nhật nên một số mục menu mới sẽ thiếu bản dịch, nhưng thường không ảnh hưởng đến việc soạn thảo).

### Điều chỉnh phông chữ

Vào `Preferences->Settings`, trong phần thiết lập người dùng ở bên phải, thêm một dòng `"font_face": "tên phông",` vào trong cặp ngoặc nhọn. Thiết lập của ST được lưu bằng định dạng JSON. Sau khi sửa xong và lưu lại, nếu hệ thống đã cài phông tương ứng thì ST sẽ tự chuyển.

Nhìn chung, nếu chỉ xét khả năng hiển thị tiếng Trung, Microsoft Yahei Consolas và Microsoft YaHei Mono là các lựa chọn tương đối tốt.

???+ warning "Warning"
    Chú ý: dù có thể sửa, không nên sửa bất kỳ thiết lập nào (kể cả thiết lập plugin) trong phần thiết lập mặc định bên trái. Đây là cách không được khuyến nghị, vì khi phần mềm (hoặc plugin) cập nhật, thiết lập mặc định sẽ bị đặt lại.

### Cài plugin và theme

Cách cài plugin và theme giống cách cài plugin bản địa hóa.

Nhấn <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd>, nhập `Install` rồi nhấn Enter, sau đó tìm plugin/theme/bảng màu cần cài.

Plugin khuyến nghị:

-   BracketHighlighter: tăng cường khả năng tô sáng cặp ngoặc so với bản gốc, gần như bắt buộc nên có.
-   C++ Snippets: ST đã có hoàn thành mã C++ sẵn, với phong cách dấu ngoặc nhọn không xuống dòng. Nếu không quen phong cách có sẵn hoặc muốn thêm một số mẫu hoàn thành, có thể cài plugin này.
-   C++ 11: hỗ trợ tô sáng chuẩn C++ 11 (không cần trong ST4).
-   SublimeAstyleFormatter: Astyle, dùng để định dạng mã.
-   Diffy: nhấn <kbd>Ctrl</kbd>+<kbd>K</kbd>&<kbd>Ctrl</kbd>+<kbd>D</kbd> để nhanh chóng so sánh khác biệt giữa tệp đang mở ở khung nhìn thứ nhất và thứ hai; cách so sánh là theo từng dòng.
-   ConvertToUTF8: tự động nhận diện mã hóa tệp và hỗ trợ chuyển đổi mã hóa.
-   SideBarEnhancements: tăng cường thanh bên, khá đáng dùng.
-   Transparency: làm cửa sổ trong suốt.

Nếu có nhu cầu khác, có thể thử tìm kiếm thêm.

Một số theme:[^ref3]

1337 (chỉ bảng màu), 3024 (chỉ bảng màu), Grandson-of-Obsidian (chỉ bảng màu), Seti\_UI (chỉ theme, có thêm tô sáng cho git và một số định dạng khác, khá đáng dùng), Material Theme, Predawn, Agila, Materialize.

Nếu muốn chỉnh bảng màu riêng, có thể truy cập [tmTheme Editor](http://tmtheme-editor.herokuapp.com/).

Nếu dùng ST4, có thể chỉnh bảng màu trong `Preferences->Customize Color Scheme` hoặc chỉnh theme trong `Preferences->Customize Scheme`.

### Bật Vi Mode

Nhà phát triển ST cung cấp cho người dùng Vi một plugin tùy chọn tên là Vintage, có thể mô phỏng phần lớn chức năng của Vi.

#### Cách bật

Plugin Vintage mặc định bị tắt. Có thể vào `Preferences->Settings`, trong thiết lập người dùng, xóa Vintage khỏi mục `"ignored_packages"` rồi lưu lại (không xóa cả mục, chỉ xóa Vintage). Bên trái thanh trạng thái của ST sẽ xuất hiện `INSERT MODE`, tức là plugin Vintage đã được bật.

Hoặc nhấn <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd>, nhập `Enable`, chọn `Package Control: Enable Package` rồi nhấn Enter, sau đó chọn Vintage. Cách này cần Package Control.

#### Cấu hình liên quan

Nếu muốn vô hiệu hóa các phím mũi tên, có thể thêm vào `Preferences->Key Bindings`:

```JSON
{ "keys": ["left"], "command": ""},
{ "keys": ["right"], "command": ""},
{ "keys": ["up"], "command": ""},
{ "keys": ["down"], "command": ""},
```

Nếu muốn ST khởi động ở chế độ lệnh, có thể thêm vào `Preferences->Settings`:

```json
"vintage_start_in_command_mode": true,
```

Cũng có thể dùng thiết lập phím tắt để gán thao tác vào chế độ lệnh cho một phím bất kỳ (xem chi tiết ở [Thiết lập phím tắt](#thiết-lập-phím-tắt)).

#### Khác biệt so với Vi

Plugin Vintage của ST có một số điểm khác với Vi, một phần được liệt kê dưới đây:

-   Trong chế độ chèn, thao tác chọn bằng chuột sẽ không vào chế độ visual; lúc này nội dung nhập vào không được nhận diện là lệnh mà sẽ trực tiếp thay thế văn bản. Chế độ visual chỉ có thể vào từ chế độ lệnh.
-   Không có các lệnh `r`, `R`, `zA`, `za`, `zi`, `z=`, `@` và các lệnh dùng phím <kbd>\[</kbd>, <kbd>]</kbd> hoặc <kbd>"</kbd>.
-   Các phím tắt dùng <kbd>Ctrl</kbd>, <kbd>Shift</kbd> và <kbd>Alt</kbd> vẫn giữ nguyên phím tắt do ST thiết lập; ví dụ <kbd>Ctrl</kbd>+<kbd>V</kbd> sẽ không vào chế độ visual mà vẫn dán bình thường.
-   Chế độ dòng lệnh chỉ giữ lại `:e`, `:0`, `:$`, `:s`.
-   Khi dùng lệnh `\` và `?`, ST sẽ tự gọi hộp tìm kiếm thay vì nhập trực tiếp từ cần tìm trong lệnh. Đồng thời, số đếm sẽ không có hiệu lực.
-   Lệnh ghi macro `q` sẽ khởi động chức năng ghi macro có sẵn của ST. Sau khi nhấn <kbd>Q</kbd>, cần nhấn thêm một phím để bắt đầu ghi, nhưng macro đã ghi sẽ không được gắn với phím đó; cần nhấn <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>Q</kbd> mới chạy. Nếu cần lưu, dùng `Tools->Save Macro`; phím tắt cần tự thiết lập.
-   Không thể dùng tổ hợp `số+.`.

### Thiết lập

#### Thiết lập ST

Thiết lập trong `Preferences->Settings`. Dưới đây liệt kê một số tùy chọn khá hữu ích:

```JSON
{
  // Co chu
  "font_size": 11,

  // Phong chu; co the khong dat, mac dinh la Consolas
  "font_face": "",

  // Tu dong chuyen Tab thanh dau cach
  "translate_tabs_to_spaces": true,

  // Do rong thut le
  "tab_size": 4,

  // To sang dong hien tai
  "highlight_line": true,

  // Tu dong them xuong dong o cuoi tep khi luu
  "trim_trailing_white_space_on_save": true,

  // Khi dang chon van ban, tim kiem chi tim trong pham vi da chon
  "auto_find_in_selection": true,

  // Tat cac plugin it khi dung trong OI; co the tu dieu chinh
  "ignored_packages": [
    "ActionScript", "AppleScript", "ASP", "Batch File", "C#",
    "Clojure", "CSS", "D", "Diff", "Erlang", "Git Formats",
    "Go", "Graphviz", "Groovy", "Haskell", "HTML", "Java",
    "LaTeX", "Lisp", "Lua", "Makefile", "Matlab",
    "Objective-C", "OCaml", "Perl", "PHP", "Python",
    "R","Rails", "RestructuredText", "Ruby", "Rust",
    "Scala", "ShellScript", "SQL", "TCL", "Textile", "XML",
  ],

  // So dong tuong doi, co the phoi hop voi Vintage de nhay nhanh
  "relative_line_numbers": false,
}
```

#### Thiết lập phím tắt

Thiết lập trong `Preferences->Key Bindings`: tìm chức năng cần sửa ở bên trái, sao chép sang bên phải rồi sửa phím.

Ví dụ, nếu muốn đổi phím biên dịch từ <kbd>Ctrl</kbd>+<kbd>B</kbd> sang <kbd>F9</kbd> (nếu không vô hiệu hóa phím tắt cũ thì thực tế là thêm một cách kích hoạt), có thể thêm vào `Preferences->Key Bindings`:

```JSON
// Doi lenh build thanh f9
{ "keys": ["f9"], "command": "build" },

// Doi phim sap xep dong dang gan voi f9 sang shift+f9.
// Phan lon truong hop khong can chuc nang nay, nen co the bo dong nay.
{ "keys": ["shift+f9"], "command": "sort_lines", "args": {"case_sensitive": false} },
```

#### Thiết lập plugin

Thiết lập của plugin có thể tìm trong `Preferences->Package Settings->tên plugin`; khi sửa, chú ý không sửa thiết lập mặc định.

Ví dụ, dưới đây là một số thiết lập của BracketHighlighter, chỉnh trong `Preferences->Package Settings->BracketHighlighter->Bracket Settings`:

```JSON
{
  // Hien mot vach o dau dong giua hai ngoac khop nhau,
  // giup nhanh chong tim pham vi cap ngoac
  "content_highlight_bar": true,

  // Hien cap ngoac khop nhau trong minimap
  "show_in_minimap": true,

  // Bo qua gioi han pham vi khop
  "ignore_threshold": true,

  // style la kieu to sang: bold la to sang khoi,
  // underline la gach chan dam, outline la vien ngoai
  // color la mau; thiet lap mac dinh da chua tat ca mau duoc ho tro
  // icon la dau hieu hien thi o thanh ben
  "bracket_styles": {
    "default": {"icon": "dot", "color": "region.yellowish", "style": "bold",},
    "unmatched": {"icon": "question", "color": "region.redish", "style": "outline",},
    "curly": {"icon": "curly_bracket", "color": "region.purplish",},
    "round": {"icon": "round_bracket", "color": "region.yellowish",},
    "square": {"icon": "square_bracket", "color": "region.bluish",},
    "angle": {"icon": "angle_bracket", "color": "region.orangish",},
    "tag": {"icon": "tag", "color": "region.orangish",},
    "c_define": {"icon": "hash", "color": "region.yellowish",},
    "single_quote": {"icon": "single_quote", "color": "region.greenish",},
    "double_quote": {"icon": "double_quote", "color": "region.greenish",},
    "regex": {"icon": "star", "color": "region.greenish"}
  }
}
```

### Sửa và thêm mới

Đôi khi một số chỗ trong plugin có thể chưa thật vừa ý, hoặc muốn bản địa hóa plugin; khi đó cần sửa plugin.

Plugin được đặt trong thư mục `\Installed Packages` dưới thư mục dữ liệu.

Các tệp bên trong có hậu tố `.sublime-package`; thực chất đây là định dạng `.zip`, có thể mở bằng phần mềm giải nén.

Ví dụ, nếu muốn sửa hoàn thành tự động, có thể mở các tệp `\Snippets\*.sublime-snippet` trong plugin `\Packages\C++` ở **thư mục cài đặt** của ST để sửa. Nếu muốn **thêm** hoàn thành tự động, có thể cài C++ Snippets rồi sửa hoặc thêm tệp trong đó (hoặc tạo một plugin mới, nhưng không được thêm trực tiếp vào plugin C++ có sẵn, nếu không ST sẽ không nhận diện). Khi lưu bất kỳ sửa đổi nào, **bắt buộc** phải đóng ST và nên sao lưu trước, nếu không có thể mất tệp.

Dĩ nhiên, mọi phần thêm mới đều có thể đặt dưới `\Packages\User\` trong thư mục dữ liệu; cách này luôn được hỗ trợ.

Ví dụ, một snippet mẫu tệp có thể viết như sau:

```XML
<snippet>
  <description>template_code</description> <!-- Noi dung nay la ban xem truoc cua phan hoan thanh -->
  <content><![CDATA[#include <cstdio>
using namespace std;

int main() {
  freopen("${1:file name}.in", "r", stdin);
  freopen("$1.out", "w", stdout);
  ${0:/* code */}
  fclose(stdin);
  fclose(stdout);
  return 0;
}]]></content>
  <tabTrigger>code</tabTrigger> <!-- Noi dung nay la van ban kich hoat hoan thanh -->
  <scope>source.c++</scope> <!-- Noi dung nay la ngon ngu ap dung cho hoan thanh -->
</snippet>
```

Dưới đây liệt kê một số hậu tố tệp và công dụng của chúng. Hướng dẫn phát triển plugin chi tiết xem [tài liệu cộng đồng](https://docs.sublimetext.io/guide/extensibility/plugins/) và [tài liệu chính thức](https://www.sublimetext.com/docs/3/):

| Hậu tố | Công dụng |
| ------ | --------- |
| .sublime-build | Tệp hệ thống biên dịch |
| .sublime-completions | Danh sách hoàn thành tên tệp (thường là tệp header) |
| .sublime-syntax | Tệp tô sáng cú pháp |
| .sublime-settings | Tệp thiết lập |
| .tmPreferences | Tệp danh sách trong Preferences |
| .sublime-keymap | Tệp thiết lập phím tắt |
| .sublime-snippet | Tệp hoàn thành mã |
| .sublime-commands | Tệp định nghĩa lệnh |
| .sublime-menu | Tệp UI của ST, gồm thanh bên và thanh menu phía trên (đối tượng chính khi bản địa hóa) |

Do cập nhật plugin sẽ trực tiếp ghi đè tệp gốc, nên nên sao lưu các tệp đã sửa.

## Soạn thảo

### Thiết lập cú pháp

Sau khi nhấn <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd>, nhập tên cú pháp cần dùng; hoặc nhấn `Plain Text` ở góc dưới bên phải rồi đổi sang ngôn ngữ cần thiết. Cũng có thể thiết lập trong `View->Syntax`.

![](images/sublime3-2.png)

### Phím tắt

ST có phím tắt phức hợp, ví dụ <kbd>Ctrl</kbd>+<kbd>K</kbd>&<kbd>Ctrl</kbd>+<kbd>Backspace</kbd> nghĩa là nhấn <kbd>Ctrl</kbd>+<kbd>K</kbd> trước, rồi nhấn <kbd>Ctrl</kbd>+<kbd>Backspace</kbd>.

Một số phím tắt:

| Phím | Lệnh |
| ---- | ---- |
| <kbd>Ctrl</kbd>+<kbd>X</kbd> | Cắt dòng hiện tại |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>K</kbd> | Xóa dòng |
| <kbd>Ctrl</kbd>+<kbd>Enter</kbd> | Chèn dòng bên dưới |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>Enter</kbd> | Chèn dòng bên trên |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>Up</kbd> | Di chuyển dòng lên |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>Down</kbd> | Di chuyển dòng xuống |
| <kbd>Ctrl</kbd>+<kbd>L</kbd> | Chọn dòng; lặp lại để chọn thêm nhiều dòng phía dưới |
| <kbd>Ctrl</kbd>+<kbd>D</kbd> | Chọn từ; lặp lại để chọn nhiều từ giống nhau và vào chế độ chọn nhiều điểm (dùng để sửa hàng loạt nhanh) |
| <kbd>Ctrl</kbd>+<kbd>M</kbd> | Nhảy đến ngoặc khớp |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>M</kbd> | Chọn nội dung trong cặp ngoặc (không gồm ngoặc); lặp lại để bao gồm cả ngoặc |
| <kbd>Ctrl</kbd>+<kbd>K</kbd>&<kbd>Ctrl</kbd>+<kbd>K</kbd> | Xóa đến cuối dòng (phím tắt phức hợp, nên dùng Vim mode thay thế) |
| <kbd>Ctrl</kbd>+<kbd>K</kbd>&<kbd>Ctrl</kbd>+<kbd>Backspace</kbd> | Xóa đến đầu dòng (phím tắt phức hợp, nên dùng Vim mode thay thế) |
| <kbd>Ctrl</kbd>+<kbd>]</kbd> | Thụt lề dòng hiện tại (hoặc các dòng đang chọn) |
| <kbd>Ctrl</kbd>+<kbd>\[</kbd> | Bỏ thụt lề dòng hiện tại (hoặc các dòng đang chọn) |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>D</kbd> | Sao chép dòng hiện tại và chèn vào dòng kế tiếp |
| <kbd>Ctrl</kbd>+<kbd>J</kbd> | Gộp dòng kế tiếp với dòng hiện tại |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>V</kbd> | Dán và tự thụt lề (dùng khi dán cả đoạn mã) |
| <kbd>Ctrl</kbd>+<kbd>K</kbd>&<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>V</kbd> | Dán từ lịch sử (phím tắt phức hợp, nên đổi thành <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>V</kbd>) |
| <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Down</kbd> | Di chuyển con trỏ xuống và giữ lại con trỏ ở dòng hiện tại (vào chế độ chọn nhiều điểm) |
| <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Up</kbd> | Di chuyển con trỏ lên và giữ lại con trỏ ở dòng hiện tại (vào chế độ chọn nhiều điểm) |
| <kbd>Ctrl</kbd>+<kbd>R</kbd> | Nhảy đến bất kỳ ký hiệu nào trong tệp (hàm hoặc định nghĩa kiểu) |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>R</kbd> | Nhảy đến bất kỳ ký hiệu nào trong dự án (hàm hoặc định nghĩa kiểu) |
| <kbd>Ctrl</kbd>+<kbd>P</kbd> | Nhảy đến bất kỳ tệp nào (đã từng mở, hoặc nằm trong dự án và tồn tại) |
| <kbd>\~</kbd> | Chuyển đổi chữ hoa/thường của vùng chọn |

### Hoàn thành tự động

ST có chức năng hoàn thành phong phú. Các mục hoàn thành có thể dùng sẽ hiển thị dưới con trỏ; nhấn <kbd>Tab</kbd> hoặc <kbd>Enter</kbd> để hoàn thành (trong ST4, nếu thực hiện một hoàn thành không phải kiểu Snippet, nhấn tiếp <kbd>Tab</kbd> có thể tiếp tục chọn mục hoàn thành chứa mục này làm chuỗi con).

Hoàn thành kiểu Snippet thường có một số khối có thể chỉnh sửa. Sau khi hoàn thành, ST sẽ tự chọn phần cần thay thế; nếu là hoàn thành phức tạp như `for` có nhiều khối chỉnh sửa, sau khi sửa xong một khối thì nhấn lại <kbd>Tab</kbd> để sang khối tiếp theo. Khi đang ở trong khối chỉnh sửa mà muốn kích hoạt hoàn thành, cần dùng <kbd>Enter</kbd> (trong ST4 vẫn có thể tiếp tục dùng <kbd>Tab</kbd>).

Nếu không có hoàn thành tự động, hãy sửa như sau:

1.  Kiểm tra xem đã chuyển ngôn ngữ chưa; tệp mới của ST mặc định là Plain Text.

2.  Vào `Preferences->Settings` rồi thêm hai dòng:

```JSON
"auto_complete": true,
"auto_match_enabled": true,
```

### Chọn nhiều điểm

Giữ <kbd>Ctrl</kbd> và nhấp chuột để thêm con trỏ trên màn hình. <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Up</kbd> hoặc <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Down</kbd> có thể trực tiếp thêm con trỏ ở các dòng kề nhau. Mọi thao tác chỉnh sửa sẽ được áp dụng đồng thời cho tất cả con trỏ.

### Tìm kiếm và thay thế

<kbd>Ctrl</kbd>+<kbd>F</kbd> là tìm kiếm, <kbd>F3</kbd> là tìm tiếp, <kbd>Shift</kbd>+<kbd>F3</kbd> là tìm trước đó, <kbd>Ctrl</kbd>+<kbd>H</kbd> là thay thế.

Năm tùy chọn tìm kiếm lần lượt là khớp biểu thức chính quy, phân biệt hoa thường, khớp cả từ, tìm vòng, và tìm trong vùng chọn.

Nên đặt `"auto_find_in_selection"` thành `true` trong Preferences. Khi đó, nếu chọn hơn một từ rồi tìm kiếm, ST sẽ tự chỉ tìm trong vùng đã chọn.

## Minh họa

### Hot exit

Thử nhập một số nội dung trong ST rồi đóng thẳng toàn bộ ST. ST sẽ đóng ngay mà không có thông báo nào; khi mở lại ST, miễn là máy tính không bị khôi phục dữ liệu, dữ liệu sẽ không mất.

### Chọn nhiều điểm

Nếu muốn đổi tất cả `bok` trong đoạn mã sau thành `book`, chỉ cần đặt con trỏ vào một `bok` bất kỳ rồi giữ <kbd>Ctrl</kbd>+<kbd>D</kbd> để nhanh chóng chọn tất cả.

```cpp
int check() {
  book[1] = 1, book[2] = 1, book[3] = 1, bok[1] = 1, bok[2] = 1, bok[3] = 1,
  bok[4] = 1, bok[5] = 1;
}
```

Nếu muốn đổi toàn bộ phần sau dấu bằng trong tệp dưới đây thành `"good"`, chỉ cần đặt con trỏ trước `aaa` ở dòng đầu, nhấn <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Down</kbd> năm lần, sau đó nhấn <kbd>Ctrl</kbd>+<kbd>D</kbd> rồi nhập `good`.

Hoặc chọn `"a`, giữ <kbd>Ctrl</kbd>+<kbd>D</kbd>, sau đó nhấn <kbd>Right</kbd>, <kbd>Ctrl</kbd>+<kbd>D</kbd>, rồi nhập nội dung cần thay.

```cpp
s[1] = "aaa";
s[2] = "aab";
s[3] = "aac";
s[4] = "good";
s[5] = "aae";
s[6] = "aaf";
```

Nếu muốn thêm ngoặc cho tất cả `a + b` dưới đây, chỉ cần chọn một `a + b`, giữ <kbd>Ctrl</kbd>+<kbd>D</kbd> rồi nhập <kbd>(</kbd> (nếu đã chọn một vùng nhất định, nhập bất kỳ ngoặc trái nào sẽ thêm cặp ngoặc khớp vào hai bên vùng đó).

```plain
a + b*a + b*a + b
```

### Tìm kiếm và thay thế

Nếu muốn đổi toàn bộ phần sau dấu bằng trong tệp dưới đây thành `"good"`, cũng có thể dùng <kbd>Ctrl</kbd>+<kbd>H</kbd> để thay thế, bật regex, nhập `".*"`, rồi thay bằng `"good"`.

```cpp
s[1] = "aaa";
s[2] = "aab";
s[3] = "aac";
s[4] = "good";
s[5] = "aae";
s[6] = "aaf";
```

Nếu muốn thêm dấu chấm phẩy cho đoạn mã sau, chỉ cần dùng thay thế trong vùng chọn, bật regex, nhập `\n`, rồi thay bằng `;\n`.

```plain
int main() {  int a, b  cin >> a >> b  cout << a + b  return 0}
```

### Ghi macro

Nếu muốn thêm dấu chấm phẩy cho đoạn mã sau, có thể nhấn <kbd>Ctrl</kbd>+<kbd>q</kbd> để bắt đầu ghi macro, sau đó lần lượt nhấn <kbd>End</kbd>, <kbd>;</kbd>, <kbd>Down</kbd>, rồi nhấn lại <kbd>Ctrl</kbd>+<kbd>q</kbd> để kết thúc ghi macro (trong quá trình này góc dưới bên trái không luôn hiển thị đang ghi, nhưng thực tế vẫn đang ghi). Sau đó lặp lại bằng <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>q</kbd>.

```plain
int main() {
  int a, b
  cin >> a >> b
  cout << a + b
  return 0
}
```

??? note "Nếu đã bật plugin Vintage"
    Sau khi chạy <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>q</kbd> một lần, có thể nhấn <kbd>Esc</kbd> để vào chế độ lệnh rồi nhập `..` (lệnh `.` có thể lặp lại lệnh ST3).

Về cách lưu macro và gán phím, xem [tài liệu cộng đồng](https://docs.sublimetext.io/guide/extensibility/macros.html).

## Biên dịch và chạy

Môi trường biên dịch của ST đã được cấu hình sẵn, có thể dùng trực tiếp.

Trên Windows, cần thêm thư mục chứa g++ vào biến môi trường rồi khởi động lại ST.

### Biên dịch

Nhấn trực tiếp <kbd>Ctrl</kbd>+<kbd>B</kbd> để biên dịch. Lần đầu sử dụng cần chọn hệ thống biên dịch: chọn `C++ Single File` (biên dịch) hoặc `C++ Single File - Run` (biên dịch và chạy).

#### Sửa tùy chọn biên dịch

Tùy chọn biên dịch mặc định của ST là `g++ "${file}" -o "${file_path}/${file_base_name}"`. Nếu muốn sửa tùy chọn biên dịch, có thể tạo một hệ thống biên dịch mới.

Vào `Tools->Build System->New Build System...`, rồi nhập vào giữa cặp ngoặc nhọn:

```JSON
// Tuy chon bien dich co the tu dieu chinh
// Bien dich va chay
"shell_cmd": "g++ -Wall \"${file}\" -o \"${file_path}/${file_base_name}.exe\" && \"${file_path}/${file_base_name}.exe\"",

// Dong nay giup ST3 hien loi bang giao dien do hoa.
// Neu quen xem thong tin g++ tra ve thi co the bo.
"file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
```

Sau khi lưu, nhấn <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd> để chuyển hệ thống biên dịch là có thể dùng. Cấu hình ở đây là biên dịch rồi chạy trong CMD bên ngoài.

Tệp đã lưu nằm tại `\Packages\User\tên_hệ_thống_biên_dịch.sublime-build` dưới thư mục dữ liệu và có thể sửa nhiều lần.

### Chạy

Nếu khi biên dịch chọn `C++ Single File - Run` (tức chạy sau khi biên dịch) hoặc đã cấu hình tự chạy, cửa sổ thông tin biên dịch bật lên ở phía dưới thường sẽ không hiển thị gì (trừ khi lỗi biên dịch), vì cửa sổ thông tin biên dịch của ST thực chất là một terminal, có thể nhập dữ liệu trực tiếp.

Sau khi chạy xong, ST sẽ hiển thị thời gian chạy của chương trình. Bộ đếm thời gian này tính từ lúc nhấn <kbd>Ctrl</kbd>+<kbd>B</kbd> đến khi toàn bộ lệnh CMD kết thúc, nghĩa là bao gồm cả thời gian biên dịch, thời gian nhập liệu, và nếu chạy trong CMD bên ngoài thì còn gồm cả thời gian mở/đóng CMD.

???+ warning "Warning"
    Cửa sổ này không thể nhập <kbd>F6</kbd> hoặc <kbd>Ctrl</kbd>+<kbd>Z</kbd>. Nếu chương trình cần đọc đến cuối tệp, hãy dùng input từ tệp hoặc cấu hình chạy trong CMD bên ngoài.

### Gỡ lỗi

Có thể cài plugin để ST hỗ trợ gỡ lỗi gdb bằng giao diện đồ họa, nhưng không nên phụ thuộc vào plugin để gỡ lỗi gdb.

Cách tốt hơn là thêm lệnh liên quan khi cấu hình hệ thống biên dịch để khởi động gdb, rồi gỡ lỗi bằng dòng lệnh ở bên ngoài.

## Linh tinh

-   Kéo thư mục vào ST rồi nhấn <kbd>Ctrl</kbd>+<kbd>K</kbd>&<kbd>Ctrl</kbd>+<kbd>B</kbd> để mở thanh bên, từ đó chuyển tệp nhanh.
-   Tận dụng chức năng nhảy, đặc biệt là <kbd>Ctrl</kbd>+<kbd>P</kbd> để nhảy giữa các tệp và <kbd>Ctrl</kbd>+<kbd>R</kbd> để nhảy đến hàm.
-   ST hỗ trợ git[^ref4].
-   Toàn bộ cấu hình của ST được lưu dưới thư mục dữ liệu và có thể đóng gói tùy ý, nhưng thông tin đăng ký không thể dùng trên nhiều máy.

## Liên kết ngoài

-   [Dùng dòng lệnh để gỡ lỗi](../cmd.md)
-   [Tài liệu chính thức Sublime Text 3](https://www.sublimetext.com/docs/3/)
-   [Tài liệu cộng đồng Sublime Text](https://docs.sublimetext.io/)

## Tài liệu tham khảo và chú thích

[^ref1]: [NOI Linux 2.0 phát hành](https://www.noi.cn/gynoi/jsgz/2021-07-16/732450.shtml)

[^ref2]: [Sublime Text 4 phát hành](https://www.sublimetext.com/blog/articles/sublime-text-4)

[^ref3]: [Trình soạn thảo văn bản Sublime gọn nhẹ và dễ dùng](https://www.luogu.com.cn/blog/acking/sublime)

[^ref4]: [Tích hợp Git trong Sublime Text](https://www.sublimetext.com/docs/git_integration.html)
