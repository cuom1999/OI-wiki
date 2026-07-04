author: ouuan, akakw1, Ir1d, partychicken, Xeonacid

Trang này là hướng dẫn nhập môn Emacs.

> Nhập môn Emacs trong 15 phút.

## Giới thiệu

Emacs là một trình soạn thảo rất dễ bắt đầu; chỉ cần vài dòng cấu hình ngắn là có thể dùng. Tuy nhiên, để dùng Emacs thật thành thạo cho nhiều công việc khác nhau thì vẫn cần một khoảng thời gian nhất định.

Là một hướng dẫn nhập môn, trang này chỉ giới thiệu các chức năng cơ bản của Emacs, cũng như cách dùng Emacs để viết và gỡ lỗi mã tương đối thuận tiện.

## Nhập môn

### Lệnh

Lệnh có vai trò rất lớn trong Emacs.

Dùng phím Application[^note1] (trên Windows, Emacs chưa gán phím này, cần tự thiết lập) hoặc phím tắt M-x (<kbd>Alt</kbd>+<kbd>x</kbd>) để mở ô nhập lệnh; sau khi nhập xong, nhấn Enter để thực thi lệnh.

Thường dùng lệnh `es` hoặc `eshell` để mở Eshell (tương tự một terminal).

Việc nhập lệnh thường có thể được thay bằng phím tắt.

### Buffer

Buffer là các tệp và tiến trình đang mở. Khi chưa lưu, sửa đổi trong buffer sẽ không sửa trực tiếp vào tệp.

Có thể nhấp tên buffer ở đáy vùng buffer hoặc dùng phím tắt để chuyển buffer.

### Biên dịch, gỡ lỗi và chạy

Lối vào chức năng biên dịch và gỡ lỗi nằm trong menu thả xuống Tools trên thanh menu phía trên. Người dùng cũng có thể dùng lệnh hoặc phím tắt tự định nghĩa để dùng chức năng biên dịch và gỡ lỗi.

Có thể dùng terminal hoặc Eshell để chạy chương trình.

Sau khi nhấn debug (gud-gdb) trong Tools, nhập tên chương trình (thường sẽ được tự động điền sẵn, nhưng nếu giữa chừng lưu chương trình thành tên khác hoặc mở hai chương trình cần gỡ lỗi, **tên tệp tự động điền có thể sai**) là có thể bắt đầu gỡ lỗi.

### Chia cửa sổ

Chức năng này cho phép người dùng đồng thời xem nội dung của nhiều buffer mà không cần chuyển qua lại giữa các buffer, thuận tiện cho kiểm thử và gỡ lỗi mã.

Chức năng chia cửa sổ có thể hiển thị nhiều cửa sổ cùng lúc; kéo mép cửa sổ bằng chuột để thay đổi kích thước cửa sổ.

Một vài phím tắt:

-   Xóa cửa sổ chia "C-x 0": xóa cửa sổ chia này.
-   Chia ngang "C-x 3": chia cửa sổ này thành hai nửa theo chiều ngang.
-   Chia dọc "C-x 2": chia cửa sổ này thành hai nửa theo chiều dọc.

Bố cục cửa sổ được khuyến nghị là chia cửa sổ thành bốn phần: trước hết chia ngang, điều chỉnh một phần rộng khoảng 3/4 màn hình để làm cửa sổ chỉnh sửa. Chia ngang phần còn lại; một phần dùng để hiển thị thông tin gỡ lỗi và biên dịch, phần còn lại lại chia dọc, một phần mở tệp input, một phần mở tệp output.

![](./images/emacs.png)

### Phím tắt

Emacs có hệ thống phím tắt cực kỳ phong phú, có thể nâng cao đáng kể hiệu suất làm việc. Người dùng có thể tự định nghĩa phím tắt hoặc thiết lập ánh xạ phím tắt trong cấu hình.

Do số lượng phím tắt quá nhiều, cách dùng phím tắt của Emacs khác với hệ điều hành.

Để tiện mô tả, ta dùng quy ước sau:

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
-   `C-x left`, `C-x right`: chuyển tới buffer trước/sau.
-   `C-x d`: mở một thư mục.
-   `C-x C-f`: mở một tệp (nếu tệp không tồn tại thì tạo tệp mới).

## Cá nhân hóa

Emacs mới cài có giao diện xấu và không dễ dùng, vì vậy cần cá nhân hóa nó.

Vì cấu hình không dễ nhớ, nên với một số mục có thể thiết lập trực tiếp, khuyến nghị không cần nhớ cấu hình.

### Thiết lập trực tiếp

-   Options: `Highlight Matching Parentheses` tô sáng cặp ngoặc khớp.
-   Options: `Blink Cursor` thiết lập con trỏ nhấp nháy.
-   Options Show/Hide: `Tool Bar` hiển thị/ẩn thanh công cụ (mặc định hiển thị, khuyến nghị ẩn).
-   Options: `Use CUA Keys` sau khi chọn có thể dùng các phím tắt như Ctrl + C, Ctrl + V để sao chép/dán.
-   Options Customize-Emacs: `Custom Theme` chọn bảng màu; sau khi chọn xong cần nhấp lưu.
-   Options: `Save Options` **lưu cấu hình**.

### Cấu hình

Hiển thị tệp ẩn trong thư mục home (trên Windows là thư mục `AppData\Roaming` trong **thư mục người dùng**); `.emacs` chính là tệp cấu hình (nếu không có thì nghĩa là trước đó chưa từng lưu). Mở tệp này để sửa. Nếu Emacs đang mở, cần khởi động lại Emacs để cấu hình có hiệu lực.

Cấu hình khuyến nghị cho phòng thi như sau.

```text
;; Dat bien dich mot phim; co the tu them tham so; kho nho nen khong khuyen nghi dung o phong thi; khong nen phu thuoc vao bien dich mot phim
(defun compile-file ()(interactive)(compile (format "g++ -o %s %s -g -lm -Wall" (file-name-sans-extension (buffer-name))(buffer-name))))
(global-set-key [f9] 'compile-file)
;;;; Dat phim tat bien dich (neu da dat bien dich mot phim thi khong duoc xung dot)
;;(global-set-key [f9] 'compile)

(global-set-key (kbd "C-a") 'mark-whole-buffer) ;; Phim tat chon tat ca
(global-set-key (kbd "C-z") 'undo) ;; Phim tat hoan tac
(global-set-key [f10] 'gud-gdb) ;; Phim tat go loi GDB
(global-set-key (kbd "RET") 'newline-and-indent) ;; Xuong dong tu dong thut le
(global-set-key (kbd "C-s") 'save-buffer) ;; Dat phim tat luu
(setq-default kill-ring-max 65535) ;; Mo rong lich su co the hoan tac

;; Kieu ma C++; thuong dung de dieu khien quy tac thut le
;;;"bsd" tat ca dau ngoac nhon xuong dong
;;;"java" tat ca dau ngoac nhon khong xuong dong. else nam sau dau ngoac nhon phai
;;;"awk" chi dau ngoac nhon canh namespace, dinh nghia lop, dinh nghia ham moi xuong dong. else nam sau dau ngoac nhon phai
;;;"linux" chi dau ngoac nhon canh namespace, dinh nghia lop, dinh nghia ham moi xuong dong. else nam sau dau ngoac nhon phai. Noi chung kieu nay nen co thut le 8 dau cach
(setq-default c-default-style "awk")
```

??? note "Cấu hình đầy đủ"
    ```text
    ;; Dat bien dich mot phim
    (defun compile-file ()(interactive)(compile (format "g++ -o %s %s -g -lm -Wall" (file-name-sans-extension (buffer-name))(buffer-name))))
    (global-set-key [f9] 'compile-file)
    ;;;; Dat phim tat bien dich (neu da dat bien dich mot phim thi khong duoc xung dot)
    ;;(global-set-key [f9] 'compile)

    ;; Can thiet trong phong thi
    (global-set-key (kbd "C-a") 'mark-whole-buffer) ;; Phim tat chon tat ca
    (global-set-key (kbd "C-z") 'undo) ;; Phim tat hoan tac
    (global-set-key [f10] 'gud-gdb) ;; Phim tat go loi GDB
    (global-set-key (kbd "RET") 'newline-and-indent) ;; Xuong dong tu dong thut le
    (global-set-key (kbd "C-s") 'save-buffer) ;; Dat phim tat luu
    (setq-default kill-ring-max 65535) ;; Mo rong lich su co the hoan tac
    ;;(define-key key-translation-map [apps] (kbd "M-x")) ;; Dat phim tat lenh tren Windows

    ;; Dat thut le
    ;;; Do dai thut le ma C++.
    (setq-default c-basic-offset 4)
    ;;; Dung tab de thut le
    (setq-default indent-tabs-mode t)
    ;;; Do dai tab. Nhat dinh phai trung voi do dai thut le
    (setq-default default-tab-width 4)
    (setq-default tab-width 4)

    ;; Dat moi truong ma hoa mac dinh
    (set-language-environment "UTF-8")
    (set-default-coding-systems 'utf-8)

    ;; Khong hien trang chao mung
    (setq-default inhibit-startup-screen t)

    ;; Dat tieu de
    (setq-default frame-title-format "")

    ;; Hien so dong
    (global-display-line-numbers-mode t)

    ;; To sang
    (global-hl-line-mode 1);; To sang dong hien tai
    (show-paren-mode t);; To sang cap ngoac khop
    (global-font-lock-mode t);; To sang cu phap

    ;; Cho phep dan giua emacs va cac chuong trinh ben ngoai; hinh nhu mac dinh da cho phep
    (setq-default x-select-enable-clipboard t)

    ;; Dat font la Ubuntu Mono co 16 point; neu font khong ton tai se bao loi
    (set-face-attribute 'default nil :font "Ubuntu Mono-16")
    ;(set-face-attribute 'default nil :font "Consolas-16") ;; He Windows hay dung dong nay

    ;; Ho tro con lan chuot
    (mouse-wheel-mode t)

    ;; Dat hinh dang con tro thanh vach dung (mac dinh la khoi vuong)
    (setq-default cursor-type 'bar)

    ;; Doi cau tra loi yes/no thanh y/n
    (fset 'yes-or-no-p 'y-or-n-p)

    ;; Do trong suot
    (set-frame-parameter (selected-frame) 'alpha (list 85 60))
    (add-to-list 'default-frame-alist (cons 'alpha (list 85 60)))

    ;; Giam so dong cuon trang, tranh cuon ca trang
    (setq-default scroll-margin 3 scroll-conservatively 10000)

    ;; Toi uu cau truc cay tep
    (ido-mode t)

    ;; Bang mau
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
    ;; Bat Ctrl-x Ctrl-c Ctrl-v = cat sao-chep dan
     '(cua-mode t nil (cua-base))
     '(show-paren-mode t)
    ;; An thanh cong cu
     '(tool-bar-mode nil))
    ;; Tat con tro nhap nhay
     '(blink-cursor-mode nil)
    (custom-set-faces)
    ```

### Đọc thêm

Để khởi động Emacs ở chế độ terminal, thêm tham số `-nw` khi khởi động. Emacs có nhiều biến thể, chẳng hạn [GCC Emacs](http://akrl.sdf.org/gccemacs.html) dùng native-comp để giảm độ trễ và biến thể GTK thuần của nó, hoặc Emacs Macport được tối ưu cho macOS.

Emacs có kho phần mềm tập trung; sau khi cấu hình, có thể dùng `M-x package-install` để cài plugin. Dùng [mirror](https://mirrors.bfsu.edu.cn/help/elpa/) có thể tăng tốc tải xuống.

Emacs có thể dùng language server (Language Server Protocol) để cải thiện trải nghiệm chỉnh sửa. Backend C++ hiện được khuyến nghị là [Clangd](https://clangd.llvm.org/). Frontend có thể dùng [Eglot](https://github.com/joaotavora/eglot) hoặc [Emacs LSP](https://emacs-lsp.github.io/lsp-mode/); tham khảo [mục này](https://github.com/joaotavora/eglot#historical-differences-to-lsp-modeel) có thể hữu ích khi chọn frontend.

Tài liệu Org Mode có phần mở rộng `.org` có thể được chuyển thành tài liệu Markdown bằng [Pandoc](https://pandoc.org/).

## Tài liệu tham khảo và chú thích

[^note1]: Phím này dùng để mở menu chuột phải, thường là phím đầu tiên bên trái phím <kbd>Ctrl</kbd> phải.
