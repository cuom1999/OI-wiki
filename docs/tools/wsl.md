author: GoodCoder666, Ir1d, H-J-Granger, NachtgeistW, StudyingFather, Enter-tainer, abc1763613206, Anti-Li, shenyouran, Chrogeek, SukkaW, Henry-ZHR, Early0v0, andylizf, tootal, Marcythm, CoelacanthusHex, indevn, qinyihao, peasoft

![Ảnh đầu trang](./images/wsl-header.png)

Chương này chủ yếu giới thiệu cách dùng Windows Subsystem for Linux để chạy môi trường Linux trên hệ thống Windows.

## Dẫn nhập[^ref1]

Hiện nay, môi trường luyện tập thi đấu ở phần lớn trường học được xây dựng trên hệ điều hành họ Windows, nhưng trong các kỳ thi thuộc hệ thống NOI, môi trường đã chuyển sang NOI Linux, một bản Ubuntu được tùy biến.

Yêu cầu môi trường của kỳ thi NOI (từ ngày 1 tháng 9 năm 2021) như sau.[^ref2]

| Loại | Phần mềm hoặc mô-đun | Phiên bản | Ghi chú |
| :--- | :------------------- | :-------- | :------ |
| Hệ thống | Linux kernel | `5.4.0-42-generic` | x86 64-bit (AMD64) |
| Môi trường ngôn ngữ | GCC (`gcc` và `g++`) | `9.3.0` | Trình biên dịch C và C++ |
| | FPC | `3.0.4` | Trình biên dịch Pascal (chú ý: từ năm 2022, các kỳ thi NOI không còn hỗ trợ Pascal) |
| | Python 2 | `2.7` | Ngôn ngữ không dùng để thi |
| | Python 3 | `3.8` | Ngôn ngữ không dùng để thi |
| Công cụ gỡ lỗi | GDB | `9.1` | |
| | DDD | `3.3.12` | Frontend GUI của GDB |
| Môi trường phát triển tích hợp (IDE) | Code::Blocks | `20.03` | C/C++ IDE |
| | Lazarus | `2.0.6` | Pascal IDE |
| | Geany | `1.36` | C/C++/Pascal IDE nhẹ |
| Công cụ soạn thảo văn bản | Visual Studio Code | `1.54.3` | |
| | GNU Emacs | `26.3` | |
| | gedit | `3.36.2` | |
| | Vim | `8.1` | |
| | Joe | `4.6` | |
| | nano | `4.8` | |
| | Sublime Text | `3.2.2` | |
| Phần mềm khác | Firefox | `79.0` | Trình duyệt |
| | Midnight Commander (`mc`) | `4.8.24` | Trình quản lý tệp |
| | xterm (uxterm) | `3.5.3` | Terminal |
| | Arbiter-local | `1.02` | Bản độc lập của công cụ chấm bài |

Môi trường trong phòng thi có một loạt điểm khác với môi trường thông thường:

-   Thao tác trên dòng lệnh và thao tác trên giao diện đồ họa có khác biệt.
-   Linux và Windows có khác biệt, chẳng hạn khác biệt về phân biệt chữ hoa chữ thường.
-   Hành vi của các trình biên dịch khác nhau (MSVC và GCC), cũng như các phiên bản trình biên dịch khác nhau (GCC trên Windows và Linux, Linux GCC 32-bit và 64-bit, GCC 7 và GCC 8, v.v.) có thể khác nhau; ví dụ cách xử lý khởi tạo biến và truy cập mảng vượt biên.
-   Các hệ thống chấm bài khác nhau (Luogu và Arbiter) có thể khác nhau về kiểm tra quá thời gian và kiểm tra giới hạn bộ nhớ.

Điều này có thể dẫn đến một số tình huống khó xử:

-   Muốn dùng <kbd>Ctrl</kbd>+<kbd>C</kbd> để sao chép, nhưng lại thoát chương trình.
-   Template chương trình thường ngày AC, khi đưa lên Linux lại WA.

Để tránh những tình huống như vậy trong phòng thi, ta phải làm quen trước với cách thao tác trên hệ thống Linux.

Mặc dù trang chính thức của NOI đã cung cấp ảnh ISO của NOI Linux, việc cấu hình máy ảo tương đối phiền phức. Hơn nữa, do NOI Linux mặc định có sẵn giao diện đồ họa, khó bảo đảm chạy mượt trên các máy cấu hình thấp.

Windows 10 ra mắt Linux subsystem (WSL) trong bản Anniversary Update, rồi nâng cấp lên WSL 2 trong bản cập nhật tháng 5 năm 2020. Tính đến ngày 1 tháng 6 năm 2020, WSL đã hỗ trợ cài các bản phân phối Linux phổ biến như Ubuntu, openSUSE Leap, Kali, Debian. Tuy nhiên, WSL không hỗ trợ Arbiter dùng để chấm trong NOI.

???+ note "[Windows Subsystem for Linux (WSL) là gì?](https://en.wikipedia.org/wiki/Windows_Subsystem_for_Linux)"
    Windows Subsystem for Linux (viết tắt là WSL) là một lớp tương thích cho phép chạy trực tiếp các tệp thực thi nhị phân Linux (định dạng ELF) trên Windows 10, Windows 11 và Windows Server 2019.

    WSL cho phép nhà phát triển chạy nguyên trạng môi trường GNU/Linux, bao gồm hầu hết công cụ dòng lệnh, tiện ích và ứng dụng, mà không phát sinh chi phí của máy ảo.

    WSL chỉ khả dụng trên Windows 10 64-bit phiên bản 1607 trở lên, Windows 11 và Windows Server 2019/2022.

## Bật WSL[^ref3]

### Cài đặt tự động

???+ warning "Warning"
    Phần này áp dụng cho Windows 10 phiên bản 2004 trở lên (build 19041 trở lên) hoặc Windows 11.

    Nếu bạn đang dùng phiên bản trước 2004 hoặc máy tính không hỗ trợ ảo hóa, hãy đọc phần cài đặt thủ công bên dưới.

    Nếu bạn đang dùng Windows 10 trước phiên bản 1607, hệ thống của bạn không hỗ trợ WSL.

1.  Mở Windows PowerShell với quyền quản trị viên (nhấp chuột phải vào nút Start, chọn Windows PowerShell (Administrator) hoặc Windows Terminal (Administrator)).

2.  Nhập `wsl --install`, rồi chờ tất cả thành phần tự động cài đặt xong. Trong quá trình này, bạn có thể cần khởi động lại máy tính để bật các tính năng Windows cần thiết.

3.  Sau khi cài xong, bạn có thể tìm bản phân phối đã cài trong menu Start hoặc trong tab của Windows Terminal.

4.  Tiếp theo, hãy chuyển đến phần "Cấu hình bản phân phối" bên dưới để hoàn tất các thiết lập khác.

### Cài đặt thủ công[^ref4]

???+ warning "Warning"
    Dưới đây là các bước cài đặt WSL thủ công. Nếu bạn đã hoàn tất cài đặt tự động, hãy bỏ qua phần này.

#### Bật Windows Subsystem for Linux

Trước khi cài bất kỳ bản phân phối Linux nào cho WSL, phải chọn một trong hai cách dưới đây để bảo đảm tính năng tùy chọn "Windows Subsystem for Linux" đã được bật:

Dùng dòng lệnh:

1.  Mở PowerShell với quyền quản trị viên rồi chạy:

    ```powershell
    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
    # Nếu chỉ muốn dùng WSL 1, hãy bỏ qua bước này
    Enable-WindowsOptionalFeature -Online -FeatureName VirtualMachinePlatform
    ```

2.  Khi có lời nhắc, khởi động lại máy tính.

Dùng giao diện đồ họa:

![Windows Features](./images/wsl-windows-features.png)

1.  Mở Control Panel.

2.  Vào menu con "Turn Windows features on or off" trong "Programs and Features".

3.  Chọn "Windows Subsystem for Linux" và "Virtual Machine Platform".

4.  Nhấp OK.

5.  Khởi động lại.

#### Cài gói cập nhật kernel

Nếu bạn muốn dùng WSL 1, hãy bỏ qua bước này.

Tải và cài [gói cập nhật WSL2 Linux kernel dành cho máy x64](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi).

#### Thiết lập phiên bản WSL mặc định

Trong phần lớn trường hợp, nên dùng WSL 2.
Sự khác biệt giữa WSL 1 và WSL 2 xem tại [So sánh WSL 2 và WSL 1](https://docs.microsoft.com/zh-cn/windows/wsl/compare-versions).

??? note "Về systemd"
    WSL 1 hoàn toàn không hỗ trợ systemd (nghĩa là một số chức năng cần systemd sẽ không thể dùng hoặc cần phương án thay thế). WSL 2 đã tích hợp sẵn hỗ trợ systemd. Nếu cần dùng systemd mà bản phân phối hiện tại chưa được cấu hình để bật systemd, có thể tham khảo [cấu hình nâng cao trong WSL](https://learn.microsoft.com/zh-cn/windows/wsl/wsl-config#systemd-support).

```powershell
# Đặt phiên bản WSL mặc định thành WSL 2
wsl --set-default-version 2
```

#### Cài bản phân phối WSL

![Trang tìm kiếm](./images/wsl-search-page.png)

Vào Microsoft Store, tìm "Ubuntu", sau đó chọn "Ubuntu" và nhấp "Install" để cài đặt. Cũng có thể mở [trang Store của Ubuntu](https://www.microsoft.com/zh-cn/p/ubuntu/9nblggh4msv6).

???+ warning "Warning"
    Ubuntu trong Microsoft Store sẽ cập nhật theo Ubuntu, vì vậy nội dung có thể thay đổi. Nếu muốn có bản Ubuntu hỗ trợ dài hạn ổn định, có thể cài phiên bản LTS của Ubuntu trong Microsoft Store.

## Cấu hình bản phân phối[^ref5]

Chương này lấy Ubuntu được Windows tự động cài đặt làm ví dụ.

### Chạy Ubuntu

Mở menu Start, tìm Ubuntu rồi khởi động; hoặc dùng lệnh `wsl` để khởi động từ dòng lệnh Windows.

Có thể tạo ô ứng dụng cho Ubuntu hoặc ghim vào taskbar để lần sau mở thuận tiện hơn.

### Khởi tạo

Lần đầu chạy Ubuntu, cần hoàn tất khởi tạo.

```console
    Installing, this may take a few minutes...
```

Chờ một hai phút, hệ thống sẽ yêu cầu tạo tài khoản người dùng mới.

```console
    Please create a default UNIX user account. The username does not need to match your Windows username.
    For more information visit: https://aka.ms/wslusers
    Enter new UNIX username: chtholly
```

Sau khi nhập tên người dùng, hệ thống sẽ yêu cầu nhập mật khẩu. Trong Linux, khi nhập mật khẩu mà màn hình không hiển thị ký tự nào là hiện tượng bình thường.

```console
    Enter new UNIX password:
```

Sau khi đặt xong tên tài khoản và mật khẩu, WSL đã được cài đặt xong.

```console
    Installation successful!
    To run a command as administrator (user "root"), use "sudo <command>".
    See "man sudo_root" for details.

    chtholly@SENIORIOUS:~$
```

## Cấu hình cơ bản

Hệ thống vừa cài lần đầu không kèm bất kỳ trình biên dịch C/C++ nào, cần cấu hình môi trường thủ công.

```console
$ gcc
The program 'gcc' is currently not installed. You can install it by typing:
sudo apt install gcc
$ g++
The program 'g++' is currently not installed. You can install it by typing:
sudo apt install g++
```

### Đổi sang nguồn phần mềm trong nước

Nguồn phần mềm mặc định của Ubuntu nằm ở nước ngoài. Có thể đổi sang nguồn trong nước để tăng tốc, ví dụ [nguồn phần mềm của Tsinghua TUNA](https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/).

???+ warning "Dùng nguồn phần mềm khớp với phiên bản hệ thống của bạn"
    Hãy tìm nguồn tương ứng với phiên bản hệ thống của mình trên trang đó (có thể dùng `sudo lsb_release -a` để xem phiên bản Ubuntu).

    Trừ khi bạn biết rõ mình đang làm gì, đừng dùng nguồn không khớp với phiên bản hệ thống của mình!

Dùng các lệnh sau để cập nhật phần mềm và nguồn phần mềm:

```console
$ sudo su # Sau khi chạy lệnh này, prompt terminal sẽ đổi từ $ thành #; trước khi chạy các lệnh bên dưới hãy chú ý prompt
[sudo] mat khau cua xxx:
# cp /etc/apt/sources.list /etc/apt/sources.list.bak
# vim /etc/apt/sources.list
... (sau khi nhan i, nhap chuot phai de dan source o tren vao; sua xong nhan Esc, roi nhap :wq va Enter)
# apt update
# apt upgrade -y
# exit
exit
$
```

### Cài môi trường tiếng Trung

```console
# apt install language-pack-zh-hans -y
# apt install fontconfig -y
# apt install fonts-noto-cjk fonts-wqy-microhei fonts-wqy-zenhei -y # Phông chữ tiếng Trung
# dpkg-reconfigure locales
```

Lúc này sẽ vào một menu thiết lập; không cần chỉnh gì, cứ nhấn Enter.

Trong menu tiếp theo, chọn `zh_CN.UTF-8` rồi nhấn Enter.

<!-- scripts.linter.preprocess.fix_details off -->

```text
    Default locale for the system environment:

                 None
                 C.UTF-8
                 en_US.UTF-8
                [zh_CN.UTF-8]

            <Ok>            <Cancel>
```

<!-- scripts.linter.preprocess.fix_details on -->

Sau đó đóng WSL rồi khởi động lại, hệ thống sẽ chuyển sang tiếng Trung.

Tiếp tục nhập lần lượt các lệnh sau để thay trang trợ giúp `man` bằng tiếng Trung.[^ref6]

```console
# apt install manpages-zh
# sed -i 's|/usr/share/man|/usr/share/man/zh_CN|g' /etc/manpath.config
```

Có thể dùng `man help` để kiểm tra.

### Cài môi trường biên dịch[^ref7]

```console
# apt install -y build-essential vim ddd gdb fpc emacs gedit anjuta lazarus
```

Việc cài GUIDE xem tại [Cài GUIDE trên Debian hoặc Ubuntu](./editor/guide.md#cài-đặt-trên-debian-hoặc-ubuntu).

Ở đây cài đặt môi trường cơ bản và môi trường chính thức mà NOI yêu cầu. Nếu cần, có thể dùng `sudo apt install <tên_chương_trình>` để cài các gói phần mềm khác.
Nếu muốn cài phiên bản khác, có thể tham khảo [sổ tay quản lý gói](https://www.debian.org/doc/manuals/debian-reference/ch02.zh-cn.html) chính thức của Debian.

Dưới đây là một chương trình ví dụ:

```console
$ vim cpuid.cpp
...
$ g++ -Wall cpuid.cpp -o cpuid
$ ./cpuid
AMD Ryzen 5 1400 Quad-Core Processor
```

???+ note "Note"
    Trong môi trường Linux, tệp thực thi có thể không có phần mở rộng; cách chạy xem lệnh phía trên.

## Thao tác nâng cao

### Dùng WSLg để chạy chương trình GUI

Nếu bạn dùng Windows 10 phiên bản 19044 trở lên hoặc Windows 11, có thể dùng trải nghiệm desktop tích hợp do WSL 2 cung cấp. Chức năng này cho phép cài và khởi động trực tiếp chương trình desktop Linux mà không cần cấu hình khác.

Xem [Chạy ứng dụng Linux GUI trên Windows Subsystem for Linux](https://docs.microsoft.com/zh-cn/windows/wsl/tutorials/gui-apps).

### Cài môi trường đồ họa và kết nối bằng Remote Desktop

Nếu phiên bản bạn dùng chưa hỗ trợ WSLg, có thể thử bật chức năng giao diện đồ họa theo hướng dẫn dưới đây.

Dưới đây lấy Xfce làm ví dụ.

Nếu chỉ muốn cài Xfce, có thể chạy lệnh sau:

```console
$ sudo apt install xfce4 tightvncserver -y
```

Nếu muốn cài thêm nhiều phần mềm ngoài Xfce, có thể chạy lệnh sau:

```console
$ sudo apt install xubuntu-desktop -y
```

Tệp môi trường đồ họa khá lớn, việc tải và giải nén cần một khoảng thời gian.

Cấu hình xrdp:

```console
$ sudo apt install xrdp -y
$ echo "xfce4-session" >~/.xsession
$ sudo service xrdp restart
```

Để tránh xung đột với Remote Desktop vốn có của máy tính, cần đổi cổng mặc định.

![Kết quả khi không đổi cổng](./images/wsl-result-of-not-changing-ports.png)

Chạy lệnh `sudo sed -i 's/port=[0-9]\{1,5\}/port=otherport/' /etc/xrdp/xrdp.ini`, trong đó `otherport` là cổng khác (ví dụ `3390`).

    [globals]
    ...
    port=3390

Chạy `sudo service xrdp restart`, rồi vào menu Start và dùng `localhost:otherport` để truy cập.

![](./images/wsl-login-using-non-root.png)

![](./images/wsl-first-login.png)

### Kết nối bằng Xming

Vào môi trường Ubuntu và cài xterm:

```console
# apt install xterm -y
```

Thoát Ubuntu.

Tải Xming Server mới nhất từ [địa chỉ tải Xming X Server](https://sourceforge.net/projects/xming/), rồi cài đặt:

![](./images/wsl-xming-setup-wizard.png)

Nếu sau khi cài xong quên chọn Launch Xming, cần mở Xming trong menu Start:

![Đừng quên!](./images/wsl-xming.png)

Sau đó quay lại Ubuntu và nhập lệnh sau:

```console
$ DISPLAY=:0 xterm
```

![](./images/wsl-open-xterm.png)

Nếu đã dùng xfce4, có thể kích hoạt xfce4 trong cửa sổ bật lên bằng lệnh sau:

```console
$ xfce4-session
```

![](./images/wsl-open-xfce4-session.png)

Kết quả chạy như hình. (Trong Xming, dùng <kbd>Ctrl</kbd>+<kbd>C</kbd> là có thể thoát giao diện này.)

![](./images/wsl-xfce.png)

### Truy cập qua lại giữa tệp WSL và Windows

Ổ đĩa trong Windows được tự động mount vào thư mục `/mnt` trong môi trường Linux.
Ví dụ đường dẫn ổ C trong WSL là `/mnt/c`.

```console
PS C:\Users\chtholly> bash
/mnt/c/Users/chtholly$ echo "Hello world!" > hello
/mnt/c/Users/chtholly$ exit
PS C:\Users\chtholly> cat hello
Hello world!
PS C:\Users\chtholly> echo "Welcome!" > welcome
PS C:\Users\chtholly> bash
/mnt/c/Users/chtholly$ cat welcome
Welcome!
```

Ngoài ra, cũng có thể truy cập thư mục WSL từ trình quản lý tệp. Sau khi cài WSL, trong thanh bên của File Explorer sẽ thấy mục Linux; trong đó có thể truy cập tệp của tất cả bản phân phối đã cài.

Tương tự, cũng có thể nhập trực tiếp `\\wsl$` trong đường dẫn của File Explorer hoặc Run (Win+R) để chuyển đến thư mục WSL.

Cũng có thể dùng trực tiếp các đường dẫn như `\\wsl$\Ubuntu\home\` để truy cập thư mục con.

### Phối hợp với Visual Studio Code để soạn thảo

Nếu quen dùng [Visual Studio Code](./editor/vscode.md) trong môi trường Windows để soạn thảo mã, có thể cài plugin `Remote - WSL` trong VS Code để chỉnh sửa tệp trong hệ thống WSL thuận tiện hơn.

Thông qua `Remote - WSL`, có thể thao tác trực tiếp với subsystem WSL trong giao diện VS Code trên Windows, chỉnh sửa tệp dưới thư mục của subsystem thuận tiện hơn và dùng terminal để gỡ lỗi tiện hơn.

Bằng cách nhập trực tiếp `code .` trong WSL, có thể gọi Visual Studio Code ngay tại thư mục đó để chỉnh sửa các tệp trong thư mục.

Đồng thời, cũng có thể dùng lệnh tương tự `code filename` để chỉnh sửa tệp chỉ định.

Trang Getting Started của plugin `Remote - WSL` có giới thiệu chi tiết về thao tác soạn thảo.

Đồng thời, cũng có thể tham khảo nội dung về WSL trong tài liệu chính thức của Visual Studio Code ([Remote development in WSL](https://code.visualstudio.com/docs/remote/wsl-tutorial)); bài viết này giới thiệu toàn bộ quy trình từ cài WSL đến sử dụng cùng plugin một cách chi tiết hơn.

## Nâng cấp WSL1 lên WSL2

???+ warning "Warning"
    Hãy xác nhận bạn đã hoàn thành các bước cài WSL1 ở phía trước.

Chạy lệnh `wsl -l -v` để thấy phiên bản WSL hiện là 1; cần nâng cấp thì mới lên được 2.

1.  Bật tính năng "Virtual Machine Platform"

    Chạy PowerShell với quyền quản trị viên:

    ```shell
    dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
    ```

    Sau đó **khởi động lại máy tính**.

2.  Tải gói cập nhật Linux kernel

    -   Gói cập nhật kernel cho [x64](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi).
    -   Gói cập nhật kernel cho [ARM64/AArch64](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_arm64.msi).

3.  Thiết lập phiên bản bản phân phối

    Chạy lệnh: `wsl --set-version <tên_bản_phân_phối> <số_phiên_bản>`

    Ví dụ: lệnh đặt Ubuntu 18.04 thành WSL 2 là `wsl --set-version Ubuntu-18.04 2`.

    Bước này khá tốn thời gian. Sau khi chạy xong, dùng lệnh `wsl -l -v` để kiểm tra nâng cấp đã thành công chưa.

## FAQ

Xem: [Câu hỏi thường gặp](https://docs.microsoft.com/zh-cn/windows/wsl/faq), [Câu hỏi thường gặp về WSL 2](https://docs.microsoft.com/zh-cn/windows/wsl/wsl2-faq).

-   Làm thế nào để thực hiện xxx trong subsystem?

    Có thể dùng dòng lệnh có sẵn hoặc dùng giao diện đồ họa.
    Ví dụ với vim, nhập `man vim` trong dòng lệnh sẽ có một hướng dẫn sử dụng rất chi tiết.
    Cũng có thể dùng `vim --help`.

    Về dòng lệnh, có thể đọc [Dòng lệnh](./cmd.md).

-   Mức chiếm dụng tài nguyên hệ thống?

    Hệ thống này dùng chung host với Windows 10, nên về lý thuyết tiêu thụ tài nguyên ít hơn máy ảo.

## Liên kết ngoài

-   [Về Windows Subsystem for Linux](https://docs.microsoft.com/zh-cn/windows/wsl/about)
-   [Hướng dẫn dùng mirror Ubuntu, Tsinghua TUNA](https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/)
-   [Dev on Windows with WSL](https://dowww.spencerwoo.com)
-   [Awesome-WSL trên GitHub](https://github.com/sirredbeard/Awesome-WSL)
-   [Khắc phục sự cố Windows Subsystem for Linux](https://docs.microsoft.com/zh-cn/windows/wsl/troubleshooting)
-   [Nâng cấp WSL1 lên WSL2](https://www.cnblogs.com/stulzq/p/13926936.html)

## Tài liệu tham khảo và chú thích

[^ref1]: [Luogu Daily #6](https://www.luogu.com.cn/blog/asfr/Run-Ubuntu-On-Windows10)

[^ref2]: [NOI Linux 2.0 phát hành, chính thức sử dụng từ ngày 1 tháng 9](https://noi.cn/gynoi/jsgz/2021-07-16/732450.shtml)

[^ref3]: [Cài đặt WSL, Microsoft Docs](https://docs.microsoft.com/zh-cn/windows/wsl/install)

[^ref4]: [Các bước cài đặt thủ công WSL phiên bản cũ](https://docs.microsoft.com/zh-cn/windows/wsl/install-manual)

[^ref5]: [WSL-Ubuntu Wiki, Ubuntu Wiki](https://wiki.ubuntu.com/WSL)

[^ref6]: [Cách thiết lập bản tiếng Trung cho trợ giúp lệnh man của Ubuntu, Frank xem Lư Sơn, 2017-06-09](https://blog.csdn.net/qq_14989227/article/details/72954523)

[^ref7]: [Run Bash on Ubuntu on Windows, Mike Harsh, 2016-05-30, Windows Blog](https://blogs.windows.com/buildingapps/2016/03/30/run-bash-on-ubuntu-on-windows/#cie8WdR3uSjgR5Ru.97)
