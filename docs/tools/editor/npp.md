author: ouuan, CBW2007, partychicken, StudyingFather, Xeonacid, Henry-ZHR

## Giới thiệu phần mềm

Notepad++ là trình soạn thảo văn bản trên hệ điều hành Windows, hỗ trợ nhiều ngôn ngữ, nhiều kiểu mã hóa, cũng như tô sáng và tự động hoàn thành cho nhiều ngôn ngữ lập trình. Logo của nó cũng khá đáng yêu: một con tắc kè hoa (![Biểu trưng Notepad++](./images/npp-logo.webp)).

Chức năng của nó mạnh hơn nhiều trình soạn thảo khác; khi mở tệp lớn thì ổn định hơn, và undo liên tục cũng không gặp vấn đề. Khi đóng phần mềm cũng không cần lưu ngay, vì nó sẽ tự lưu vào vùng đệm cho bạn (có thể cần cấu hình). Hơn nữa, nó rất nhỏ gọn, chỉ hơn 10 MB, thậm chí có thể đặt trong USB để mang theo.

## Tải xuống và cài đặt

Xem [Hướng dẫn bắt đầu | Notepad++ User Manual](https://npp-user-manual.org/docs/getting-started/) trong tài liệu chính thức.

## Đổi ngôn ngữ giao diện

![Đổi ngôn ngữ giao diện Notepad++](./images/npp-lang.gif)

Sau khi đổi ngôn ngữ xong, bạn có thể tùy ý chỉnh sửa trình soạn thảo theo ý mình.

## Cách dùng cơ bản

Phần này chủ yếu nói về một số chức năng cơ bản và đặc trưng.

### Tìm kiếm và thay thế

Lần lượt nhấp "(thanh menu) Search" -> "Find" (phím tắt `CTRL`+`F`) để mở trang "Find" (như hình dưới).

![Tìm kiếm trong Notepad++](./images/npp-search.png)

Lần lượt nhấp "(thanh menu) Search" -> "Replace" (phím tắt `CTRL`+`H`) để mở trang "Replace" (như hình dưới).

![Thay thế trong Notepad++](./images/npp-replace.png)

Thực ra tìm kiếm và thay thế nằm trong cùng một cửa sổ; chỉ cần nhấp các thẻ phía trên là có thể chuyển đổi.

Chức năng của nó gần giống trình soạn thảo thông thường, nhưng hỗ trợ nhiều hơn, ví dụ:

1.  Khớp nghiêm ngặt hoặc khớp phân biệt hoa thường.
2.  Khớp giữa nhiều tài liệu.
3.  Ký tự escape, như `\r`, `\n`.
4.  Biểu thức chính quy.
5.  Đếm số lần xuất hiện.

### Sao lưu định kỳ

![Thiết lập sao lưu định kỳ trong Notepad++](./images/npp-settings-1.png)

Có chức năng này thì bạn không cần quá lo mã bị mất do sự cố bất ngờ.

Tuy nhiên, chức năng này chỉ chụp một bản chụp nhanh cho tệp của bạn, chứ chưa thật sự lưu tệp, nên vẫn nên giữ thói quen lưu tệp tốt. Hoặc bạn có thể vào kho phần bổ trợ tích hợp để cài phần bổ trợ "Auto Save" (xem [Cách dùng nâng cao -> Phần bổ trợ](#plugin), các mục dưới tương tự).

### Chức năng đánh dấu

Tại dòng cần đánh dấu, nhấn `Ctrl`+`F2` để đặt/hủy dấu đánh dấu. Dòng đã đặt dấu đánh dấu sẽ có một chấm tròn màu xanh ở phía trước.

Nhấn `F2` để nhảy tới dấu đánh dấu tiếp theo.

Nếu thấy chưa tiện, có thể vào kho phần bổ trợ tích hợp để cài phần bổ trợ "Bookmarks" ("Dấu đánh dấu").

### Tô sáng mã

Nhấp chuột phải vào "XXX file" ("Tệp XXX") ở góc dưới bên trái, bạn có thể chọn tô sáng cho rất nhiều ngôn ngữ như C, C++, PASCAL, Markdown. Thậm chí bạn có thể tự định nghĩa tô sáng.

Nếu thấy mỗi lần mở tệp lại phải đổi tô sáng là phiền, có thể sửa tô sáng mặc định trong "Settings -> Preferences -> New Document -> Default Language" ("Thiết lập -> Tùy chọn -> Tài liệu mới -> Ngôn ngữ mặc định").

Nếu cần hiển thị Markdown, có thể vào kho phần bổ trợ cài "Markdown Viewer" ("Trình xem Markdown"); còn nhiều phần bổ trợ tương tự khác đang chờ bạn.

### Hiển thị toàn bộ ký tự

![Hiển thị toàn bộ ký tự trong Notepad++](./images/npp-settings-2.png)

Nhấp nút được khoanh đỏ để hiển thị rất rõ các ký tự vốn không nhìn thấy như "space" ("dấu cách"), "TAB" ("tab") và "newline" ("xuống dòng").

### Tự động nhận diện mã hóa tệp và ký tự xuống dòng

Notepad++ có thể tự động nhận diện tệp hiện tại dùng mã hóa `UTF-8`, `GB2312` hoặc các kiểu mã hóa khác. Bạn không còn phải lo bị lỗi mojibake khi đọc nhầm mã hóa.

Nếu muốn xem văn bản bằng mã hóa khác, lần lượt nhấp "(thanh menu) Encoding" -> "Use XXX encoding" ("(thanh menu) Mã hóa -> Dùng mã hóa XXX"). Nếu muốn đổi mã hóa ký tự cho tệp, lần lượt nhấp "(thanh menu) Encoding" -> "Convert to XXX encoding" ("(thanh menu) Mã hóa -> Chuyển sang mã hóa XXX").

Nó cũng có thể tự động nhận diện ký tự xuống dòng là `CR`, `LF` hay `CRLF`, nên không cần lo dữ liệu tải xuống bị mất dòng.

Ở thanh thông tin phía dưới, bạn có thể thấy các dòng như "Windows(CR LF)"; đó chính là kiểu xuống dòng hiện tại của tệp. Nhấp chuột phải vào đó để đổi kiểu xuống dòng của tệp hiện tại. Thao tác này trực quan hơn khi dùng cùng chức năng "hiển thị toàn bộ ký tự".

## Cách dùng nâng cao

Phần này phù hợp với người dùng có nhu cầu cao hơn.

### Macro tự động hóa

Macro có thể giúp bạn hoàn thành nhiều việc lặp lại. Ví dụ, đổi "abcde" ở các dòng lẻ thành "afce" cần hai bước.

#### Ghi macro

![Ghi macro trong Notepad++](./images/npp-macro-rec.gif)

#### Dùng macro

![Dùng macro trong Notepad++](./images/npp-macro-use.gif)

#### Xử lý hàng loạt và dùng lặp lại

Nếu có nhiều dòng hơn thì sao? Thao tác cần thay đổi một chút.

Trước hết là ghi macro: nhất định phải nhấn phím `HOME` hoặc `END` trên bàn phím để đưa con trỏ về đầu dòng hoặc cuối dòng, rồi dùng phím mũi tên điều chỉnh vị trí ngang trước khi sửa. Cuối cùng, nhất định phải dùng phím mũi tên để chuyển con trỏ tới dòng tiếp theo cần xử lý.

Ví dụ với trường hợp vừa rồi, có thể nhấn `END`, rồi lần lượt nhấn `←`, `Backspace`, `←`, `Backspace`, `F`, cuối cùng nhấn `↓` hai lần, rồi dừng ghi.

Sau đó là phát lại: trước hết đặt con trỏ ở dòng đầu tiên cần xử lý (dòng 3), rồi nhấp "Macro" -> "Run a Macro Multiple Times" ("Macro -> Chạy macro nhiều lần"). Trong cửa sổ bật lên, chọn macro cần chạy (macro vừa ghi thường là cái đầu tiên), đặt số lần chạy (hoặc chạy thẳng đến cuối tệp), rồi nhấp OK.

#### Lưu macro

Nhấp "Macro" -> "Save Current Recorded Macro" ("Macro -> Lưu macro vừa ghi"), đặt tên và phím tắt, là có thể lưu lại để tiện dùng về sau.

<span id="plugin"></span>

<span id="plugin-mở-rộng"></span>

### Phần bổ trợ mở rộng

#### Quản lý phần bổ trợ

Mở nút "Plugins" ("Phần bổ trợ") trên thanh chức năng; danh sách sẽ hiển thị toàn bộ phần bổ trợ bạn đã cài.

Sau đó chọn "Plugins Admin" ("Quản lý phần bổ trợ") để quản lý phần bổ trợ.

#### Cài phần bổ trợ (kho phần bổ trợ)

1.  Mở thẻ "Available" (Khả dụng), đánh dấu phần bổ trợ bạn cần trong danh sách.
2.  Nhấp nút "Install" (Cài đặt) ở góc trên bên phải, rồi khởi động lại phần mềm theo hướng dẫn.

#### Cài phần bổ trợ (thủ công)

1.  Tải phần bổ trợ (địa chỉ chính thức do bên thứ ba lưu trữ: <https://sourceforge.net/projects/npp-plugins/>). Chú ý nhất định phải chọn phần bổ trợ **cùng kiến trúc bộ xử lý với lúc cài Notepad++**.
2.  Tìm tệp tên "XXX.dll" (thường được đặt theo tên phần bổ trợ).
3.  Trong Notepad++, nhấp Plugins trên thanh chức năng, rồi nhấp "Open Plugins Folder" ("Mở thư mục phần bổ trợ") trong danh sách.
4.  Đặt tệp DLL vừa tìm được vào thư mục đó, rồi khởi động lại Notepad++.
5.  [Tùy chọn] Xóa tệp vừa sao chép, **nhưng đừng xóa thư mục đã được sinh ra!**

Mẹo: Nếu thử nhiều lần vẫn không thành công, có thể tạo một thư mục trùng tên phần bổ trợ rồi đặt tệp ".dll" vào thư mục vừa tạo.

#### Cập nhật phần bổ trợ

Trong trình quản lý phần bổ trợ, chọn thẻ "Updates" (Bản cập nhật), đánh dấu phần bổ trợ cần cập nhật, rồi nhấp nút "Update" (Cập nhật) ở góc trên bên phải.

#### Gỡ phần bổ trợ

Cũng trong trình quản lý phần bổ trợ, chọn thẻ "Installed" (Đã cài đặt), đánh dấu phần bổ trợ cần gỡ, rồi nhấp nút "Remove" (Gỡ bỏ) ở góc trên bên phải.

### Dựng môi trường phát triển

Không chỉ là trình soạn thảo, "Notepad++" có thể coi là một công cụ rất mạnh: nó có thể biên dịch mã theo cách đơn giản, thậm chí thay thế IDE. Ở đây lấy C++ làm ví dụ.

1.  Cài trình biên dịch và thêm các thư mục tệp cần thiết của nó vào biến môi trường PATH. (Với C++ cần thêm `%APPPATH%\bin`.) Khi nhập `g++` trong cmd mà không còn báo `'g++' is not recognized as an internal or external command...` là được (có thể cần khởi động lại máy). Khuyến nghị [tải ConsolePauser](https://sourceforge.net/projects/orwelldevcpp/files/Tools/ConsolePauser.exe/download), đặt ở đâu cũng được rồi thêm thư mục của nó vào biến môi trường (đây là phần bổ trợ của Dev-C++; trong thư mục gốc của phần mềm Dev-C++ cũng có).

2.  Trên thanh menu, chọn "Run" -> "Run..." ("Chạy -> Chạy..."), mở cửa sổ "Run" ("Chạy").

3.  Nhập lần lượt các lệnh sau:

    ```shell
    # Lệnh biên dịch:
    cmd /c g++.exe -o $(CURRENT_DIRECTORY)\$(NAME_PART).exe $(FULL_CURRENT_PATH)
    # Lệnh chạy:
    cmd /c $(CURRENT_DIRECTORY)\$(NAME_PART).exe $(FULL_CURRENT_PATH) & pause
    # Lệnh gỡ lỗi:
    cmd /c gdb $(CURRENT_DIRECTORY)\$(NAME_PART).exe

    # Nếu đã tải ConsolePauser, có thể dùng các lệnh sau để có trải nghiệm chạy chương trình tốt hơn! (Chú ý thêm biến môi trường!)

    # Lệnh biên dịch:
    cmd /c (start ConsolePauser "g++.exe -o $(CURRENT_DIRECTORY)\$(NAME_PART).exe $(FULL_CURRENT_PATH)")
    # Lệnh chạy:
    cmd /c (start ConsolePauser "$(CURRENT_DIRECTORY)\$(NAME_PART).exe")
    # Lệnh gỡ lỗi:
    cmd /c (start ConsolePauser "gdb $(CURRENT_DIRECTORY)\$(NAME_PART).exe")
    ```

4.  Nhấp "Save" ("Lưu"); tên có thể tự đặt, chẳng hạn "Compile" ("Biên dịch"), "Run" ("Chạy"), rồi đặt phím tắt bạn muốn (chọn phím dễ nhớ, ví dụ Dev-C++ lần lượt là `F9` và `F10`).

5.  Thế là xong!

## Trứng phục sinh

1.  Khi chạy trình cài đặt, bạn sẽ thấy câu sau ở phía dưới:

    > "The best things in life are free. Notepad++ is free. So Notepad++ is the best(.)"
    >
    > (Những điều tốt nhất trong cuộc sống đều miễn phí. Notepad++ miễn phí. Vì vậy Notepad++ là tốt nhất.)

    Câu này tự tin thật, nhưng phải nói là cũng có cơ sở.

2.  Trong một trang mới mở, nhập "random" rồi chọn nó, sau đó nhấn `F1`, bạn sẽ nhận được một câu khá thú vị.
