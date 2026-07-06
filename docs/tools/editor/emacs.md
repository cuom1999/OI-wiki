author: ouuan, akakw1, Ir1d, partychicken, Xeonacid

Trang này là hướng dẫn nhập môn Emacs.

> Nhập môn Emacs trong 15 phút.

## Giới thiệu

Emacs là một trình soạn thảo dễ bắt đầu; chỉ cần vài dòng cấu hình ngắn là có
thể dùng. Tuy nhiên, để dùng Emacs thành thạo cho nhiều công việc khác nhau thì
vẫn cần một khoảng thời gian nhất định.

Là một hướng dẫn nhập môn, trang này chỉ giới thiệu các chức năng cơ bản của
Emacs, cũng như cách dùng Emacs để viết và gỡ lỗi mã hiệu quả hơn.

## Nhập môn

### Lệnh

Lệnh có vai trò quan trọng trong Emacs.

Dùng phím Application[^note1] (trên Windows, Emacs chưa gán phím này, cần tự
thiết lập) hoặc phím tắt M-x (<kbd>Alt</kbd>+<kbd>x</kbd>) để mở ô nhập lệnh;
sau khi nhập xong, nhấn Enter để thực thi lệnh.

Thường dùng lệnh `es` hoặc `eshell` để mở Eshell (tương tự một trình dòng lệnh).

Việc nhập lệnh thường có thể được thay bằng phím tắt.

### Bộ đệm

Bộ đệm (buffer) là các tệp và tiến trình đang mở. Khi chưa lưu, sửa đổi trong bộ đệm sẽ không sửa trực tiếp vào tệp.

Có thể nhấp tên bộ đệm ở đáy vùng bộ đệm hoặc dùng phím tắt để chuyển bộ đệm.

### Biên dịch, gỡ lỗi và chạy

Lối vào chức năng biên dịch và gỡ lỗi nằm trong menu thả xuống Tools (`Công cụ`) trên thanh menu phía trên. Cũng có thể dùng lệnh hoặc phím tắt tự định nghĩa để gọi chức năng biên dịch và gỡ lỗi.

Có thể dùng trình dòng lệnh hoặc Eshell để chạy chương trình.

Sau khi nhấn gỡ lỗi (gud-gdb) trong Tools (`Công cụ`), nhập tên chương trình
(thường sẽ được tự động điền sẵn, nhưng nếu giữa chừng lưu chương trình thành
tên khác hoặc mở hai chương trình cần gỡ lỗi, **tên tệp tự động điền có thể
sai**) để bắt đầu gỡ lỗi.

### Chia cửa sổ

Chức năng này cho phép xem đồng thời nội dung của nhiều bộ đệm mà không cần
chuyển qua lại giữa các bộ đệm, hỗ trợ kiểm thử và gỡ lỗi mã.

Chức năng chia cửa sổ có thể hiển thị nhiều cửa sổ cùng lúc; kéo mép cửa sổ bằng chuột để thay đổi kích thước cửa sổ.

Một vài phím tắt:

-   Xóa cửa sổ chia "C-x 0": xóa cửa sổ chia này.
-   Chia ngang "C-x 3": chia cửa sổ này thành hai nửa theo chiều ngang.
-   Chia dọc "C-x 2": chia cửa sổ này thành hai nửa theo chiều dọc.

Bố cục cửa sổ được khuyến nghị là chia cửa sổ thành bốn phần: trước hết chia ngang, điều chỉnh một phần rộng khoảng 3/4 màn hình để làm cửa sổ chỉnh sửa. Chia ngang phần còn lại; một phần dùng để hiển thị thông tin gỡ lỗi và biên dịch, phần còn lại lại chia dọc, một phần mở tệp đầu vào, một phần mở tệp đầu ra.

![](./images/emacs.png)

### Phím tắt

Emacs có hệ thống phím tắt phong phú, có thể nâng cao đáng kể hiệu suất làm việc.
Người dùng có thể tự định nghĩa phím tắt hoặc thiết lập ánh xạ phím tắt trong
cấu hình.

Do số lượng phím tắt quá nhiều, cách dùng phím tắt của Emacs khác với hệ điều hành.

Để tiện mô tả, dùng quy ước sau:

| Ký tự | Phím |
| ----- | ---- |
| C | <kbd>Ctrl</kbd> |
| M | <kbd>Alt</kbd> |
| ? | Phím bất kỳ |

Thông thường có ba dạng sau:

-   `F?`, `ESC`: nhấn trực tiếp phím chức năng tương ứng.
-   `M-?`, `C-?`, `C-M-?`: giữ <kbd>Alt</kbd> hoặc <kbd>Ctrl</kbd> đồng thời nhấn `?`.
-   `? ?`: trước hết nhấn phím tương ứng với `?` đầu tiên, thả ra rồi nhấn phím tương ứng với `?` thứ hai.

Dưới đây là một số phím tắt thường dùng:

-   `C-x h`: chọn tất cả.
-   `C-x left`, `C-x right`: chuyển tới bộ đệm trước/sau.
-   `C-x d`: mở một thư mục.
-   `C-x C-f`: mở một tệp (nếu tệp không tồn tại thì tạo tệp mới).

## Cá nhân hóa

Thiết lập mặc định của Emacs có thể chưa phù hợp với thói quen sử dụng, vì vậy nên cá nhân hóa nó.

Vì các mục cấu hình khó nhớ, với một số mục có giao diện thiết lập trực tiếp thì không cần ghi nhớ cấu hình thủ công.

### Thiết lập trực tiếp

-   Options (`Tùy chọn`): `Highlight Matching Parentheses` (`Tô sáng cặp ngoặc khớp`) tô sáng cặp ngoặc khớp.
-   Options (`Tùy chọn`): `Blink Cursor` (`Con trỏ nhấp nháy`) thiết lập con trỏ nhấp nháy.
-   Options Show/Hide (`Tùy chọn Hiển thị/Ẩn`): `Tool Bar` (`Thanh công cụ`) hiển thị/ẩn thanh công cụ (mặc định hiển thị, khuyến nghị ẩn).
-   Options (`Tùy chọn`): `Use CUA Keys` (`Dùng phím CUA`) sau khi bật sẽ dùng được các phím tắt như Ctrl + C, Ctrl + V để sao chép/dán.
-   Options Customize-Emacs (`Tùy chọn Tùy chỉnh Emacs`): `Custom Theme` (`Chủ đề tùy chỉnh`) chọn bảng màu; sau khi chọn xong cần nhấp lưu.
-   Options (`Tùy chọn`): `Save Options` (`Lưu tùy chọn`) **lưu cấu hình**.

### Cấu hình

Hiển thị tệp ẩn trong thư mục home (trên Windows là thư mục `AppData\Roaming` trong **thư mục người dùng**); `.emacs` chính là tệp cấu hình (nếu không có thì nghĩa là trước đó chưa từng lưu). Mở tệp này để sửa. Nếu Emacs đang mở, cần khởi động lại Emacs để cấu hình có hiệu lực.

Cấu hình khuyến nghị cho phòng thi như sau.

```text
;; Đặt biên dịch một phím; có thể tự thêm tham số; khó nhớ nên không khuyến nghị dùng ở phòng thi; không nên phụ thuộc vào biên dịch một phím
(defun compile-file ()(interactive)(compile (format "g++ -o %s %s -g -lm -Wall" (file-name-sans-extension (buffer-name))(buffer-name))))
(global-set-key [f9] 'compile-file)
;;;; Đặt phím tắt biên dịch (nếu đã đặt biên dịch một phím thì không được xung đột)
;;(global-set-key [f9] 'compile)

(global-set-key (kbd "C-a") 'mark-whole-buffer) ;; Phím tắt chọn tất cả
(global-set-key (kbd "C-z") 'undo) ;; Phím tắt hoàn tác
(global-set-key [f10] 'gud-gdb) ;; Phím tắt gỡ lỗi GDB
(global-set-key (kbd "RET") 'newline-and-indent) ;; Xuống dòng tự động thụt lề
(global-set-key (kbd "C-s") 'save-buffer) ;; Đặt phím tắt lưu
(setq-default kill-ring-max 65535) ;; Mở rộng lịch sử có thể hoàn tác

;; Kiểu mã C++; thường dùng để điều khiển quy tắc thụt lề
;;;"bsd" tất cả dấu ngoặc nhọn xuống dòng
;;;"java" tất cả dấu ngoặc nhọn không xuống dòng. else nằm sau dấu ngoặc nhọn phải
;;;"awk" chỉ dấu ngoặc nhọn cạnh namespace, định nghĩa lớp, định nghĩa hàm mới xuống dòng. else nằm sau dấu ngoặc nhọn phải
;;;"linux" chỉ dấu ngoặc nhọn cạnh namespace, định nghĩa lớp, định nghĩa hàm mới xuống dòng. else nằm sau dấu ngoặc nhọn phải. Kiểu này thường có thụt lề 8 dấu cách
(setq-default c-default-style "awk")
```

??? note "Cấu hình đầy đủ"
    ```text
    ;; Đặt biên dịch một phím
    (defun compile-file ()(interactive)(compile (format "g++ -o %s %s -g -lm -Wall" (file-name-sans-extension (buffer-name))(buffer-name))))
    (global-set-key [f9] 'compile-file)
    ;;;; Đặt phím tắt biên dịch (nếu đã đặt biên dịch một phím thì không được xung đột)
    ;;(global-set-key [f9] 'compile)

    ;; Cần thiết trong phòng thi
    (global-set-key (kbd "C-a") 'mark-whole-buffer) ;; Phím tắt chọn tất cả
    (global-set-key (kbd "C-z") 'undo) ;; Phím tắt hoàn tác
    (global-set-key [f10] 'gud-gdb) ;; Phím tắt gỡ lỗi GDB
    (global-set-key (kbd "RET") 'newline-and-indent) ;; Xuống dòng tự động thụt lề
    (global-set-key (kbd "C-s") 'save-buffer) ;; Đặt phím tắt lưu
    (setq-default kill-ring-max 65535) ;; Mở rộng lịch sử có thể hoàn tác
    ;;(define-key key-translation-map [apps] (kbd "M-x")) ;; Đặt phím tắt lệnh trên Windows

    ;; Đặt thụt lề
    ;;; Độ dài thụt lề mã C++.
    (setq-default c-basic-offset 4)
    ;;; Dùng tab để thụt lề
    (setq-default indent-tabs-mode t)
    ;;; Độ dài tab. Nhất định phải trùng với độ dài thụt lề
    (setq-default default-tab-width 4)
    (setq-default tab-width 4)

    ;; Đặt môi trường mã hóa mặc định
    (set-language-environment "UTF-8")
    (set-default-coding-systems 'utf-8)

    ;; Không hiện trang chào mừng
    (setq-default inhibit-startup-screen t)

    ;; Đặt tiêu đề
    (setq-default frame-title-format "")

    ;; Hiện số dòng
    (global-display-line-numbers-mode t)

    ;; Tô sáng
    (global-hl-line-mode 1);; Tô sáng dòng hiện tại
    (show-paren-mode t);; Tô sáng cặp ngoặc khớp
    (global-font-lock-mode t);; Tô sáng cú pháp

    ;; Cho phép dán giữa Emacs và các chương trình bên ngoài; hình như mặc định đã cho phép
    (setq-default x-select-enable-clipboard t)

    ;; Đặt phông là Ubuntu Mono cỡ 16 point; nếu phông không tồn tại sẽ báo lỗi
    (set-face-attribute 'default nil :font "Ubuntu Mono-16")
    ;(set-face-attribute 'default nil :font "Consolas-16") ;; Hệ Windows hay dùng dòng này

    ;; Hỗ trợ con lăn chuột
    (mouse-wheel-mode t)

    ;; Đặt hình dạng con trỏ thành vạch đứng (mặc định là khối vuông)
    (setq-default cursor-type 'bar)

    ;; Đổi câu trả lời yes/no thành y/n
    (fset 'yes-or-no-p 'y-or-n-p)

    ;; Độ trong suốt
    (set-frame-parameter (selected-frame) 'alpha (list 85 60))
    (add-to-list 'default-frame-alist (cons 'alpha (list 85 60)))

    ;; Giảm số dòng cuộn trang, tránh cuộn cả trang
    (setq-default scroll-margin 3 scroll-conservatively 10000)

    ;; Tối ưu cấu trúc cây tệp
    (ido-mode t)

    ;; Bảng màu
    (setq default-frame-alist
             '((vertical-scroll-bars)
               (top . 25)
               (left . 45)
               (width . 120)
               (height . 40)
               (background-color . "grey15")
               (foreground-color . "grey")
               (cursor-color . "gold1")
               (mouse-color . "gold1")
               (tool-bar-lines . 0)
               (menu-bar-lines . 1)
               (scroll-bar-lines . 0)
               (right-fringe)
               (left-fringe)))

    (set-face-background 'highlight "gray5")
    (set-face-foreground 'region "cyan")
    (set-face-background 'region "blue")
    (set-face-foreground 'secondary-selection "skyblue")
    (set-face-background 'secondary-selection "darkblue")
    (set-cursor-color "wheat")
    (set-mouse-color "wheat")

    (custom-set-variables
     '(ansi-color-faces-vector
       [default default default italic underline success warning error])
    ;; Bật Ctrl-x Ctrl-c Ctrl-v = cắt sao chép dán
     '(cua-mode t nil (cua-base))
     '(show-paren-mode t)
    ;; Ẩn thanh công cụ
     '(tool-bar-mode nil))
    ;; Tắt con trỏ nhấp nháy
     '(blink-cursor-mode nil)
    (custom-set-faces)
    ```

### Đọc thêm

Để khởi động Emacs ở chế độ trình dòng lệnh, thêm tham số `-nw` khi khởi động. Emacs có nhiều biến thể, chẳng hạn [GCC Emacs](http://akrl.sdf.org/gccemacs.html) dùng biên dịch mã gốc (native-comp) để giảm độ trễ và biến thể GTK thuần của nó, hoặc Emacs Macport được tối ưu cho macOS.

Emacs có kho phần mềm tập trung; sau khi cấu hình, có thể dùng `M-x package-install` để cài phần bổ trợ. [Máy chủ nhân bản (mirror)](https://mirrors.bfsu.edu.cn/help/elpa/) giúp tăng tốc tải xuống.

Emacs có thể dùng máy chủ ngôn ngữ (Language Server Protocol) để cải thiện trải nghiệm chỉnh sửa. Phần xử lý phía sau (backend) cho C++ hiện được khuyến nghị là [Clangd](https://clangd.llvm.org/). Phần giao diện trong Emacs (frontend) có thể dùng [Eglot](https://github.com/joaotavora/eglot) hoặc [Emacs LSP](https://emacs-lsp.github.io/lsp-mode/); có thể tham khảo [mục này](https://github.com/joaotavora/eglot#historical-differences-to-lsp-modeel) khi lựa chọn phần giao diện trong Emacs.

Tài liệu Org Mode có phần mở rộng `.org` có thể được chuyển thành tài liệu Markdown bằng [Pandoc](https://pandoc.org/).

## Tài liệu tham khảo và chú thích

[^note1]: Phím này dùng để mở menu chuột phải, thường là phím đầu tiên bên trái phím <kbd>Ctrl</kbd> phải.
