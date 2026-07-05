author: CoelacanthusHex

## Giới thiệu phần mềm

Kate là một trình soạn thảo văn bản đa nền tảng với nhiều chức năng. Kate còn đi kèm nhiều phần bổ trợ, bao gồm trình dòng lệnh nhúng để bạn khởi động lệnh trực tiếp từ Kate, phần bổ trợ tìm kiếm và thay thế mạnh, cùng phần bổ trợ xem trước có thể hiển thị tệp MD, HTML, thậm chí SVG. Kate hỗ trợ khôi phục dữ liệu khi hệ thống gặp sự cố thông qua tệp hoán đổi, tự động hoàn thành kèm gợi ý tham số, đồng thời hỗ trợ [LSP (Language Server Protocol)](https://microsoft.github.io/language-server-protocol/) để có khả năng hoàn thành mã mạnh hơn.

## Tải xuống và cài đặt

Có thể mở [trang chủ Kate](https://kate-editor.org/), rồi vào [trang tải xuống](https://kate-editor.org/get-it/). Sau đó, cài đặt theo hệ thống bạn dùng và cách cài đặt bạn thích.

## Cách dùng và chức năng

### Tệp hoán đổi để tránh mất dữ liệu

Tương tự Vim, Kate sẽ ghi các thay đổi chưa lưu vào một tệp hoán đổi (thường là thêm dấu chấm trước tên tệp gốc và thêm `.kate-swp` phía sau). Nếu gặp sự cố như mất điện hoặc chương trình gặp lỗi, lần khởi động tiếp theo sẽ không làm mất các thay đổi chưa lưu.

### Tô sáng mã

Kate hỗ trợ tô sáng cú pháp cho hơn ba trăm ngôn ngữ. Nói chung, Kate có thể tự động chọn ngôn ngữ tương ứng để tô sáng cú pháp, nhưng đôi khi cũng có thể nhận sai; khi đó có thể nhấp nút ở góc dưới cùng bên phải và chọn đúng ngôn ngữ.

#### Tự viết tệp tô sáng cú pháp

Dù Kate hỗ trợ tô sáng cú pháp cho hơn ba trăm ngôn ngữ, vẫn khó tránh khỏi có ngôn ngữ chưa được bao phủ. Khi đó, bạn có thể tự viết tệp tô sáng cú pháp.
Các tệp đi kèm Kate nằm tại [Syntax Highlighting Powered By KSyntaxHighlighting Framework](https://kate-editor.org/syntax/); cú pháp có thể tham khảo [Working with Syntax Highlighting](https://docs.kde.org/trunk5/en/kate/katepart/highlight.html); tệp viết xong đặt theo hướng dẫn trong [Syntax definition files](https://github.com/KDE/syntax-highlighting#syntax-definition-files). [CoelacanthusHex/dotfiles@80a913c/pam\_env.xml](https://github.com/CoelacanthusHex/dotfiles/blob/80a913cc5b90d7878eb0ed77b8df2d9b97926272/kate/.local/share/katepart5/syntax/pam_env.xml) là một tệp cấu hình do tác giả viết, có thể dùng để tham khảo.

### Chuyển ngôn ngữ

Nhấp `Settings`/`Setting` trên thanh công cụ phía trên, rồi nhấp `Configure Language`, sau đó chọn ngôn ngữ. Chú ý rằng có thể chọn ngôn ngữ dự phòng.

### Mã hóa và ký tự cuối dòng

Kate có thể tự động nhận diện tệp hiện tại dùng mã hóa nào. Nếu nhận diện sai, có thể nhấp nút thứ hai từ phải sang ở góc dưới bên phải và chọn mã hóa đúng.

Đồng thời, Kate cũng có thể tự động nhận diện kiểu ký tự cuối dòng hiện tại. Nếu nhận diện sai, có thể nhấp `Tools` -> `End of line` để chọn đúng kiểu cuối dòng.

### Tìm kiếm và thay thế

Lần lượt nhấp `Edit` -> `Find` (phím tắt <kbd>Ctrl</kbd>+<kbd>F</kbd>) để mở trang "Find". Lần lượt nhấp `Edit` -> `Replace` (phím tắt <kbd>Ctrl</kbd>+<kbd>R</kbd>) để mở trang "Find and Replace". Đồng thời, nhấp `Search and Replace` ở góc dưới bên trái cũng có thể mở trang "Find and Replace".

Thao tác cụ thể không khác nhiều so với các trình soạn thảo khác, nhưng Kate hỗ trợ thêm một số đặc tính, ví dụ:

1.  Có phân biệt hoa thường hay không.
2.  Hỗ trợ biểu thức chính quy (bao gồm nhóm bắt).
3.  Phạm vi từ tệp hiện tại, nhiều tệp, cho tới dự án hiện tại.
4.  Thay thế có chọn lọc trong kết quả tìm kiếm.

### Giao thức máy chủ ngôn ngữ

Kate hỗ trợ LSP Client từ phiên bản 19.12. Ban đầu chỉ hỗ trợ C/C++, D, Fortran, Go, Latex/BibTeX, OCaml, Python, Rust; hiện nay hỗ trợ các ngôn ngữ trong bảng sau:

| Ngôn ngữ | Máy chủ LSP |
| :------: | :---------: |
| Bash | [bash-language-server](https://github.com/bash-lsp/bash-language-server) |
| LaTeX | [texlab](https://texlab.netlify.com/) |
| BibTeX | [texlab](https://texlab.netlify.com/) |
| C | [clangd](https://clang.llvm.org/extra/clangd/) |
| C++ | [clangd](https://clang.llvm.org/extra/clangd/) |
| D | [serve-d](https://github.com/Pure-D/serve-d) |
| Fortran | [fortls](https://github.com/hansec/fortran-language-server) |
| Go | [gopls](https://golang.org/x/tools/gopls) |
| Haskell | [haskell-language-server-wrapper](https://github.com/haskell/haskell-language-server) |
| JavaScript | [typescript-language-server](https://github.com/theia-ide/typescript-language-server) |
| OCaml | [ocamllsp](https://github.com/ocaml/ocaml-lsp) |
| Perl | [Perl-LanguageServer](https://github.com/richterger/Perl-LanguageServer) |
| Python | [pyls](https://github.com/palantir/python-language-server) |
| Rust | [rls](https://github.com/rust-lang/rls) |
| TypeScript | [typescript-language-server](https://github.com/theia-ide/typescript-language-server) |
| R | [RLanguageServer](https://github.com/REditorSupport/languageserver) |
| zig | [zls](https://github.com/zigtools/zls) |

Để bật các tính năng liên quan đến LSP, cần vào thanh menu `Settings` -> `Configure Kate`, rồi trong `Plugins`, chọn `LSP Client` để bật các tính năng liên quan. Khi mở tệp của ngôn ngữ tương ứng, Kate sẽ tự động khởi động máy chủ LSP tương ứng.

#### Thêm cấu hình

Ngoài ra, người dùng cũng có thể tự viết cấu hình thủ công. Định dạng cụ thể như sau:

```json
{
    "servers": {
        "bibtex": {
            "use": "latex",
            "highlightingModeRegex": "^BibTeX$"
        },
        "c": {
            "command": ["clangd", "-log=error", "--background-index"],
            "commandDebug": ["clangd", "-log=verbose", "--background-index"],
            "url": "https://clang.llvm.org/extra/clangd/",
            "highlightingModeRegex": "^(C|ANSI C89|Objective-C)$"
        },
        "cpp": {
            "use": "c",
            "highlightingModeRegex": "^(C\\+\\+|ISO C\\+\\+|Objective-C\\+\\+)$"
        },
        "haskell": {
            "command": ["haskell-language-server-wrapper", "--lsp"],
            "rootIndicationFileNames": ["*.cabal", "stack.yaml", "cabal.project", "package.yaml"],
            "url": "https://github.com/haskell/haskell-language-server",
            "highlightingModeRegex": "^Haskell$"
        },
        "latex": {
            "command": ["texlab"],
            "url": "https://texlab.netlify.com/",
            "highlightingModeRegex": "^LaTeX$"
        },
        "rust": {
            "command": ["rls"],
            "rootIndicationFileNames": ["Cargo.lock", "Cargo.toml"],
            "url": "https://github.com/rust-lang/rls",
            "highlightingModeRegex": "^Rust$"
        }
    }
}
```

Trong đó, mỗi mục trong `servers` đại diện cho một ngôn ngữ. Trong cấu hình của ngôn ngữ đó, `command` là lệnh dùng để khởi động máy chủ LSP; `command` là một mảng, chính là kết quả tách lệnh cần chạy theo dấu cách; `url` là trang web của LSP; `rootIndicationFileNames` là các tệp dùng để xác định thư mục gốc dự án; `highlightingModeRegex` khớp tên của một kiểu tô sáng cú pháp để xác định dùng LSP nào; nếu có mục `use`, nghĩa là dùng cấu hình của ngôn ngữ tương ứng với mục `use`.

Mục cấu hình này nằm tại `Settings` -> `Configure Kate` -> `LSP Client` -> `User Server Settings`; phần `LSP Client` chỉ hiện sau khi đã bật phần bổ trợ `LSP Client` trong `Plugins`.

### Trình dòng lệnh tích hợp

???+ note "Chú ý"
    Trình dòng lệnh tích hợp phụ thuộc vào Konsole[^ref1] của KDE, còn Konsole là gói chỉ có trên \*nix. Nói cách khác, tính năng này không dùng được trên Windows.

Nhấn <kbd>F4</kbd> để mở hoặc đóng trình dòng lệnh tích hợp; cũng có thể nhấp nút `Terminal` ở góc dưới bên trái để mở. Thư mục hiện tại của trình dòng lệnh tích hợp sẽ tự động đồng bộ với tệp hiện tại và thay đổi theo tệp bạn chọn. Các phần còn lại không khác nhiều so với trình dòng lệnh thông thường.

### Công cụ ngoài

Nhấp `Tools` -> `External Tools` để thực thi.

Nhấp `Tools` -> `External Tools` -> `Configure` để cấu hình công cụ ngoài.

#### Thêm công cụ ngoài

##### Thêm từ cấu hình có sẵn

Sau khi vào trang cấu hình, nhấp `Add` -> `Add from Defaults` ở góc dưới bên trái, rồi nhấp công cụ tương ứng.

##### Thêm bằng cấu hình tự viết

Sau khi vào trang cấu hình, nhấp `Add` -> `Add Tool` ở góc dưới bên trái, rồi điền theo hướng dẫn. Có thể tham khảo [tài liệu này (tiếng Anh)](https://docs.kde.org/trunk5/en/kate/kate/kate-application-plugin-external-tools.html) để viết cấu hình công cụ ngoài của riêng mình. Chú ý có thể nhấp biểu tượng dưới đây để xem các biến có thể dùng.

![](images/kate-3-var.png)

#### Công cụ ngoài thường dùng

##### Biên dịch và chạy một tệp C++ đơn

Trên hệ thống \*nix, mở bất kỳ tệp nguồn C++ nào, tìm `Compile Execute cpp` trong công cụ ngoài, rồi nhấp vào đó.

???+ note "Dành cho người dùng Windows"
    Theo mặc định, vì tệp thực thi của công cụ này là `sh`, công cụ này không dùng được trên Windows. Tuy nhiên, người dùng có thể chỉnh sửa công cụ này để dùng được trên Windows.

    Để chỉnh sửa, trước hết hãy đảm bảo hệ thống của bạn có một trình biên dịch C++ dùng được. Sau đó thêm `Compile Run cpp` từ công cụ mặc định, đổi `Executable` từ `sh` thành `powershell`, và đổi tham số thành `-ExecutionPolicy Bypass -Command "g++ %{Document:FilePath} -o %{Document:FileBaseName}.exe;./%{Document:FileBaseName}.exe"` [^note1][^note2].

##### Git Blame

Mở bất kỳ tệp nào, tìm `git blame` trong công cụ ngoài; sau khi nhấp, một cửa sổ sẽ mở ra và hiển thị kết quả git blame.

##### Định dạng

Chức năng định dạng yêu cầu gói hoặc ứng dụng tương ứng khả dụng; ví dụ, định dạng C/C++ yêu cầu `clang-format` khả dụng. Với các ngôn ngữ khác, người dùng có thể vào cấu hình công cụ ngoài để xem tệp thực thi mặc định làm tham khảo.

Mở bất kỳ tệp nguồn nào, tìm `Format with xxx` trong công cụ ngoài, rồi nhấp vào đó. Ngoài ra, với tệp nguồn C/C++, `clang-format` có thể định dạng phần văn bản được chọn.

### Truy vết dòng bằng Git blame

Để bật tính năng này, cần vào thanh menu `Settings` -> `Configure Kate`, rồi trong `Plugins`, chọn `Git Blame`.

Sau khi bật tính năng này, Kate sẽ hiển thị bằng chữ nhạt ở cuối mỗi dòng rằng dòng đó được ai sửa lần cuối trong Git và vào thời điểm nào. Di chuột lên đoạn chữ đó sẽ hiện một cửa sổ nổi hiển thị thông tin cụ thể của commit.

## Liên kết ngoài liên quan

-   [The Kate Handbook](https://docs.kde.org/stable5/en/kate/kate/kate.pdf)
-   [Về cách tự viết cấu hình LSP Client (tiếng Anh)](https://docs.kde.org/trunk5/en/kate/kate/kate-application-plugin-lspclient.html#Configuration)
-   [Về cách tự viết cấu hình công cụ ngoài (tiếng Anh)](https://docs.kde.org/trunk5/en/kate/kate/kate-application-plugin-external-tools.html)

## Tài liệu tham khảo và chú thích

[^ref1]: Trong [mô tả gói này trên Arch Linux](https://archlinux.org/packages/extra/x86_64/kate/), gói có phụ thuộc tùy chọn là `konsole`, được mô tả là `open a terminal in Kate` (mở trình dòng lệnh trong Kate).

[^note1]: Nếu `g++` không nằm trong biến môi trường `PATH`, hãy đổi nó thành đường dẫn tuyệt đối của trình biên dịch.

[^note2]: Hoặc nếu dùng Clang, hãy đổi `g++` thành `clang++`.
