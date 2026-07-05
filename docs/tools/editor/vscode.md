author: NachtgeistW, Ir1d, ouuan, Enter-tainer, Xeonacid, ChungZH, keepthethink, abc1763613206, partychicken, Chrogeek, xkww3n, HeliumOI, Pinghigh, xiaofu-15191, Sekakou, fuxianhu

## Giới thiệu

Visual Studio Code (dưới đây gọi tắt là VS Code) là một trình soạn thảo mã nguồn mở do Microsoft phát triển, hỗ trợ các hệ điều hành như Windows, Linux và macOS. Nó được viết bằng TypeScript và dùng kiến trúc Electron. VS Code có sẵn hỗ trợ cho JavaScript, TypeScript và Node.js, đồng thời cung cấp hệ sinh thái extension phong phú cho các ngôn ngữ khác như C, C++, Java, Python, PHP, Go.

Trang chủ: [Visual Studio Code - The open source AI code editor](https://code.visualstudio.com/)

Trước khi đọc các nội dung bên dưới, bạn nên tìm hiểu sơ qua cách dùng cơ bản của VS Code: [Get started](https://code.visualstudio.com/docs/getstarted/getting-started).

## Chạy mã bằng extension C/C++ Compile Run

C/C++ Compile Run là một plugin tập trung vào biên dịch và chạy tệp đơn C/C++. Nó tránh được các bước cấu hình rườm rà của plugin C/C++ truyền thống, rất phù hợp với nhu cầu lập trình thi đấu, dễ bắt đầu và thao tác đơn giản.

Mở VS Code, nhấp biểu tượng "Extensions" ở thanh bên trái (hoặc nhấn <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>X</kbd>), nhập `C++` vào ô tìm kiếm, tìm C/C++ Compile Run, rồi nhấp "Install".

![](./images/vscode-14.png)

Sau khi cài đặt xong, không cần cấu hình thêm; plugin sẽ tự động thích nghi với trình biên dịch MinGW đã cấu hình sẵn theo biến môi trường.

Mở tệp cần chạy, nhấp biểu tượng tam giác ở góc trên bên phải để chạy mã.

Phím tắt:

-   <kbd>F6</kbd> - biên dịch và chạy trong terminal tích hợp của VS Code.
-   <kbd>F7</kbd> - biên dịch với tham số tùy chỉnh và chạy với tham số tùy chỉnh trong terminal tích hợp của VS Code.
-   <kbd>F8</kbd> - biên dịch và chạy trong terminal ngoài.

## Chạy mã bằng extension Code Runner

Sau khi cài đặt và cấu hình extension, VS Code có thể hỗ trợ C/C++, nhưng quá trình cấu hình tương đối phức tạp. Một phương án đơn giản để biên dịch và chạy chương trình C++ là cài extension Code Runner.

Code Runner là một extension có thể chạy mã bằng một lần nhấp. Trong công việc phát triển, nó thường được dùng để kiểm tra đoạn mã, và hỗ trợ hơn 40 ngôn ngữ như Node.js, Python, C, C++, Java, PHP, Perl, Ruby, Go.

Cách cài đặt là tìm Code Runner trong extension store rồi nhấp Install; hoặc vào [Marketplace](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) và nhấp Install, trình duyệt sẽ tự mở VS Code để cài đặt.

![](./images/vscode-1.jpg)

Sau khi cài đặt xong, mở tệp cần chạy, nhấp biểu tượng tam giác nhỏ ở góc trên bên phải để chạy mã; nhấn phím tắt <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>N</kbd> (trên macOS là <kbd>Control</kbd>+<kbd>Option</kbd>+<kbd>N</kbd>) cũng có hiệu quả tương tự.

???+ warning "Cảnh báo"
    Nếu sau khi cài VS Code và Code Runner mà mã vẫn không chạy được, rất có thể hệ thống chưa cài môi trường chạy C/C++; hãy tham khảo [trang Hello, World!](../../lang/helloworld.md) để cài đặt.

    Nhớ chọn tùy chọn Run In Terminal trong phần cài đặt, như hình: ![](./images/vscode-7.png)

## Dùng extension C/C++ để biên dịch, gỡ lỗi và hoàn thành thông minh

### Cài extension

Trong VS Code, mở extension store, nhập `C++` hoặc `@category:"programming languages"` vào thanh tìm kiếm, tìm C/C++, rồi nhấp Install để cài extension.

![](./images/vscode-2.png)

???+ warning "Cảnh báo"
    Trước khi cấu hình, hãy đảm bảo hệ thống đã cài G++ hoặc Clang và đã thêm vào biến môi trường `PATH`. Hãy dùng CMD hoặc PowerShell làm terminal tích hợp, không dùng Git Bash.

### Cấu hình debugger GDB/LLDB

#### GDB

Trong VS Code, tạo một tệp mã C++ mới, viết một số nội dung theo cú pháp C++ (ví dụ `int main(){}`), lưu lại rồi nhấn <kbd>F5</kbd> để vào chế độ gỡ lỗi.
Nếu xuất hiện lời nhắc "Select debugger", chọn `C++ (GDB/LLDB)`. Trong "Select configuration", người dùng G++ chọn `g++.exe - Build and debug active file`; người dùng Clang chọn `clang++ - Build and debug active file`.

???+ warning "Cảnh báo"
    Tên cấu hình không cố định mà có thể tùy chỉnh. Các hệ điều hành khác nhau có thể có tên cấu hình khác nhau.

Sau khi hoàn tất, VS Code sẽ tự động hoàn thành thao tác khởi tạo và khởi động gỡ lỗi trong terminal tích hợp phía dưới. Đến đây, toàn bộ quy trình cấu hình GDB đã xong.

#### LLDB

Nếu cần dùng LLDB, cần cài một extension khác[^ref1]: [CodeLLDB](https://github.com/vadimcn/vscode-lldb/). Sau khi tải tệp `.vsix` từ trang Release của dự án này[^ref2], hãy cài đặt từ trang extension của VS Code.

![](images/vscode-9.png)

Trước hết làm theo quy trình cấu hình GDB ở trên một lần, rồi xóa `.vscode/launch.json`, nhấn <kbd>F5</kbd>, chọn `LLDB`, sau đó đổi `${workspaceFolder}/<executable file>` trong `launch.json` thành `${fileDirname}/${fileBasenameNoExtension}` là được.

Đến đây, cấu hình LLDB đã hoàn tất. Nhấn <kbd>F5</kbd> lần nữa là có thể thấy thông tin gỡ lỗi ở phía dưới phần mềm.

Nếu sau này muốn dùng VS Code để biên dịch và gỡ lỗi mã, toàn bộ mã nguồn cần được lưu trong thư mục này. Nếu muốn biên dịch và gỡ lỗi mã nằm trong thư mục khác, cần thực hiện lại các bước trên (hoặc sao chép thư mục con `.vscode` trong thư mục cũ sang thư mục mới).

### Bắt đầu gỡ lỗi mã

Dùng VS Code mở một tệp mã, di chuột tới vùng trống bên trái số dòng, rồi nhấp chấm đỏ xuất hiện để đặt breakpoint cho dòng mã đó. Nhấp lại để hủy breakpoint.

![](images/vscode-5.apng)

Nhấn <kbd>F5</kbd> để vào chế độ gỡ lỗi. Phía trên trình soạn thảo sẽ xuất hiện một thanh công cụ gỡ lỗi; bốn nút màu xanh từ trái sang phải lần lượt tương ứng với `continue`, `next`, `step` và `until` trong GDB:

![](images/vscode-6.png)

Nếu trình soạn thảo không tự động chuyển tới, hãy nhấp biểu tượng "Debug" trên thanh công cụ bên trái để vào cửa sổ gỡ lỗi; khi đó có thể thấy giá trị biến ở bên trái.

Trong "Watch", bạn có thể nhập biểu thức; mỗi lần thực hiện thao tác như `next` hoặc `step`, biểu thức sẽ được tính lại và hiển thị.

Trong "Call Stack", bạn có thể thấy stack frame của hàm hiện tại.

???+ note "Mẹo"
    Bạn có thể tham khảo [tài liệu chính thức của GDB](https://sourceware.org/gdb/current/onlinedocs/gdb.html/Arrays.html) để xem nội dung của một đoạn trong mảng.

Trong chế độ gỡ lỗi, trình soạn thảo sẽ dùng nền màu vàng để hiển thị dòng mã sẽ được thực thi tiếp theo.

### Cấu hình IntelliSense

Dùng để điều chỉnh hoàn thành thông minh của VS Code.

Nếu bạn dùng trình biên dịch Clang, trong "IntelliSense Mode" hãy chọn `clang-x64` thay vì `msvc-x64` mặc định; nếu dùng trình biên dịch G++, chọn `gcc-x64` để dùng tự động hoàn thành và các chức năng tương tự. Nếu không, bạn sẽ gặp lỗi "IntelliSense mode msvc-x64 is incompatible with compiler path."

![](images/vscode-4.png)

## Cấu hình clangd

???+ warning "Cảnh báo"
    Do xung đột chức năng, sau khi cài extension clangd, chức năng IntelliSense của extension C/C++ sẽ bị tắt (các chức năng như gỡ lỗi vẫn dùng extension C/C++). Nếu chức năng của extension clangd có vấn đề, có thể kiểm tra xem IntelliSense của extension C/C++ đã bị tắt hay chưa.

### Giới thiệu clangd

Trang chủ LLVM giới thiệu clangd như sau:

> Clangd is an implementation of the Language Server Protocol leveraging Clang. Clangd’s goal is to provide language "smartness" features like code completion, find references, etc. for clients such as C/C++ Editors.

Nói đơn giản, clangd là phần triển khai Language Server Protocol của Clang. Nó cung cấp một số tính năng thông minh như lập chỉ mục toàn project, nhảy tới mã, đổi tên biến, hoàn thành mã nhanh hơn, gợi ý thông tin, định dạng mã, v.v.; đồng thời có thể phối hợp với các trình soạn thảo như Vim, Emacs, VSCode thông qua LSP. Dù định nghĩa chính thức nói clangd là phần triển khai LSP, chức năng của clangd gần với language server hơn là chỉ bản thân giao thức.

Extension C/C++ của VS Code cũng có các chức năng như tự động hoàn thành, nhưng về độ dễ đọc và độ chính xác của thông tin gợi ý thì kém hơn clangd một chút. Vì vậy đôi khi ta dùng clangd thay cho extension C/C++ để triển khai các chức năng như tự động hoàn thành mã.

### Cài đặt

Xem [Getting started](https://clangd.llvm.org/installation).

### Tiện ích mở rộng VS Code

Mở extension store của VS Code, nhập `clangd` vào thanh tìm kiếm, tìm extension clangd rồi cài đặt.

![](images/vscode-8.png)

Nếu phía dưới hiện hộp thoại clangd yêu cầu tắt Intellisense, hãy nhấp "Disable Intellisense", tải lại workspace, rồi bạn có thể dùng các chức năng như tự động hoàn thành của clangd.

## Chỉnh sửa

### Thiết lập cú pháp

Trong trình soạn thảo mới mở, nhấp "Select Language" để bật tô sáng cú pháp tương ứng, như hình:

![](images/vscode-11.apng)

### Phím tắt

PDF phím tắt chính thức như dưới đây; cũng có thể nhấn <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd> trong VS Code để mở command palette, rồi nhập lệnh `> Help: Keyboard Shortcuts Reference` để mở.[^ref3]

-   [Phím tắt hệ Windows](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf)
-   [Phím tắt hệ Linux](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-linux.pdf)
-   [Phím tắt hệ Mac OS](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-macos.pdf)

Một số phím tắt:

| Phím | Thao tác |
| ---- | -------- |
| <kbd>Ctrl</kbd>+<kbd>C</kbd>/<kbd>X</kbd> | Sao chép/cắt dòng hiện tại (khi không chọn nội dung nào) |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>K</kbd> | Xóa dòng hiện tại |
| <kbd>Alt</kbd>+<kbd>Up</kbd>/<kbd>Down</kbd> | Di chuyển dòng lên/xuống |
| <kbd>Alt</kbd>+<kbd>Shift</kbd>+<kbd>Up</kbd>/<kbd>Down</kbd> | Sao chép dòng lên/xuống |
| <kbd>Ctrl</kbd>+<kbd>/</kbd> | Bật/tắt chú thích dòng |
| <kbd>Ctrl</kbd>+<kbd>\[</kbd>/<kbd>]</kbd> | Thụt dòng sang trái/phải |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>\[</kbd>/<kbd>]</kbd> | Gấp/mở dòng |
| <kbd>Ctrl</kbd>+<kbd>P</kbd> | Mở tệp đã mở gần đây |
| <kbd>Alt</kbd>+<kbd>Z</kbd> | Bật/tắt tự xuống dòng |
| <kbd>Alt</kbd>+<kbd>F12</kbd> | Xem nhanh định nghĩa (ví dụ định nghĩa của hàm) |
| <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>\\</kbd> | Nhảy tới ngoặc khớp |
| <kbd>Ctrl</kbd>+<kbd>T</kbd> | Tìm symbol trong workspace (ví dụ tìm hàm có tên chỉ định trong thư mục) |

### Nhiều con trỏ

Giữ <kbd>Alt</kbd> rồi nhấp để thêm con trỏ trong trình soạn thảo; đa số thao tác chỉnh sửa đều có thể thực hiện đồng thời. Giữ nút chuột giữa và kéo trong trình soạn thảo cũng có thể thêm con trỏ nhiều dòng, như hình:

![](images/vscode-12.gif)

Nhấn <kbd>Ctrl</kbd>+<kbd>F2</kbd> để đồng thời sửa tất cả kết quả khớp trong trình soạn thảo; cũng có thể tìm Change All Occurrences trong menu chuột phải, như hình:

![](images/vscode-13.gif)

Chú ý lúc này ở góc trên bên phải sẽ có một thanh công cụ, có thể bật/tắt phân biệt hoa thường, khớp cả từ, v.v. khi tìm kết quả khớp.

## Tài liệu tham khảo và chú thích

[^ref1]: Nếu extension C/C++ của VS Code chọn lldb làm debugger, mặc định nó sẽ dùng chương trình lldb-mi; chương trình này đã được nhóm phát triển LLVM tách khỏi dự án và cần tự biên dịch. Bản thân nó cũng có một số bug, nên trải nghiệm và mức độ tiện lợi đều không bằng extension CodeLLDB.

[^ref2]: Sau khi cài CodeLLDB từ extension store, nó sẽ tải phần lõi từ GitHub, tốc độ tải rất chậm và đôi khi lỗi tải, nên tốt nhất là tải trực tiếp phần lõi rồi cài đặt. Khi cập nhật cũng có thể tải và cài theo các bước trên.

[^ref3]: [Tài liệu chính thức của VS Code](https://code.visualstudio.com/docs/).
