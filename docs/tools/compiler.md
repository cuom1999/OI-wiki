Trang này chủ yếu giới thiệu các bước cài đặt một số trình biên dịch/trình thông dịch trên từng hệ điều hành.

## GCC

### Windows

#### Tải xuống và cài đặt bằng tay

Truy cập trang tải xuống của [MinGW-w64](https://www.mingw-w64.org/downloads), nơi có nhiều bản dựng. Hướng dẫn này dùng bản dựng do WinLibs cung cấp.

Trước hết, vào [WinLibs](https://winlibs.com) để tải gói cài đặt mới nhất và chọn phiên bản phù hợp. Bài viết này dùng GCC 12.3.0 + LLVM/Clang/LLD/LLDB 16.0.4 + MinGW-w64 11.0.0 (UCRT) làm ví dụ:

Mặc định gói này sẽ cài kèm LLVM/Clang. Nếu không muốn cài, cũng có thể chọn bản không kèm LLVM/Clang/LLD/LLDB ở bên phải.

![](./images/compiler1.png)

Sau khi tải xong, giải nén vào một vị trí nào đó trên máy tính. Trong hướng dẫn
này, gói được giải nén vào thư mục gốc của ổ C. Tên thư mục nên tránh ký tự ngoài
tiếng Anh hoặc dấu cách, nếu không về sau có thể phát sinh một số vấn đề.

![](./images/compiler2.png)

Tiếp theo, cần thêm thư mục chứa tệp thực thi của trình biên dịch vào biến môi
trường hệ thống. Sau khi cấu hình xong, khi biên dịch sẽ không cần chỉ định
đường dẫn trình biên dịch, nên thao tác sử dụng sẽ gọn hơn. Ở trên, MinGW được
giải nén vào thư mục `C:\mingw64`, nên thư mục chứa tệp thực thi là
`C:\mingw64\bin`.

Nhấn tổ hợp phím logo Windows + R, nhập
`rundll32.exe sysdm.cpl,EditEnvironmentVariables`, mở cửa sổ thiết lập biến môi
trường hệ thống, chọn biến tên `Path` trong mục "Biến hệ thống", rồi nhấn nút
"Chỉnh sửa":

![](./images/compiler3.png)

Trong cửa sổ chỉnh sửa, nhấn nút "Mới" ở bên phải, tạo một mục mới cho biến
`Path`, rồi điền thư mục chứa tệp thực thi đã ghi lại ở trên (trong hướng dẫn này
là `C:\mingw64\bin`).

![](./images/compiler4.png)

??? note "Lưu ý cho một số hệ thống phiên bản cũ"
    Một số hệ thống phiên bản cũ chỉ có thể sửa giá trị văn bản của biến bằng
    tay. Khi đó cần chèn một **dấu chấm phẩy ASCII** vào cuối giá trị của biến,
    rồi dán thư mục chứa tệp thực thi vào sau dấu chấm phẩy đó, như hình minh họa:
    
    ![](./images/compiler5.png)

Sau khi hoàn tất, nhấn "OK" ("Đồng ý") liên tiếp để thoát.

Tiếp theo, mở trình dòng lệnh, nhập `g++ --version` rồi nhấn Enter. Nếu xuất hiện thông báo như hình minh họa thì nghĩa là cài đặt thành công.

![](./images/compiler6.png)

#### Cài bằng Scoop

Mở PowerShell và chạy tập lệnh sau:

```powershell
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
irm get.scoop.sh | iex
scoop install mingw-winlibs
```

### Linux

#### Debian/Ubuntu

Trước hết, cập nhật danh sách gói:

```bash
sudo apt update
```

Sau đó dùng lệnh để cài đặt trực tiếp:

```bash
sudo apt install g++
```

#### Arch Linux

Dùng lệnh để cài đặt trực tiếp:

```bash
sudo pacman -Syu gcc
```

#### openSUSE

Dùng lệnh để cài đặt trực tiếp:

```bash
sudo zypper in gcc-c++
```

### macOS

Trước hết, cập nhật trình quản lý gói:

```bash
brew upgrade
brew update
```

Sau đó dùng lệnh để cài đặt trực tiếp:

```bash
brew install gcc
```

## JDK

JDK có nhiều bản phân phối. Sau đây là hai bản thường gặp:

-   [Eclipse Temurin](https://adoptium.net/) trong OpenJDK[^temurin]: xem [cài đặt Eclipse Temurin™ | Adoptium](https://adoptium.net/installation/).
-   Oracle JDK: có thể tham khảo [hướng dẫn cài đặt JDK (JDK 17)](https://docs.oracle.com/en/java/javase/17/install/overview-jdk-installation.html).

## Python 3

Python cũng có nhiều bản triển khai[^pythonimpl]. Lấy CPython 3 làm ví dụ, xem [tải Python | Python.org](https://www.python.org/downloads/).

## LLVM

### Windows

??? note "Một điểm cần lưu ý về LLVM trên Windows"
    Do LLVM trên Windows thiếu thư viện chuẩn, vẫn cần cài MSVC hoặc GCC.

#### Cài đặt trực tiếp

Truy cập trang tải xuống của [LLVM](https://github.com/llvm/llvm-project/releases/latest), chọn `LLVM-*-win64.exe` để tải.

Nếu chất lượng mạng không tốt, có thể chọn một máy chủ bản sao GitHub Releases đáng tin cậy hoặc tải lại từ mạng ổn định hơn.

Mở tệp `.exe`; khi cài đặt, chọn "Add LLVM to system PATH for current user"
("Thêm LLVM vào PATH hệ thống cho người dùng hiện tại"), sau đó nhấn "Next"
("Tiếp theo") cho đến khi cài đặt hoàn tất.

Mở trình dòng lệnh, nhập `clang++ --version` rồi nhấn Enter. Nếu xuất hiện nội dung tương tự:

```text
clang version 15.0.1
Target: x86_64-pc-windows-msvc
Thread model: posix
InstalledDir: <omitted>
```

thì nghĩa là cài đặt thành công.

#### Cài bằng Scoop

Mở PowerShell và chạy tập lệnh sau:

```powershell
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
irm get.scoop.sh | iex
scoop install llvm
```

### Linux

#### openSUSE

Dùng lệnh để cài đặt trực tiếp:

```bash
sudo zypper in llvm clang
```

## MSVC (Visual Studio)

Truy cập trang [Tải xuống Visual Studio](https://visualstudio.microsoft.com/downloads/), tìm phần "Community" trong mục "Tải xuống", rồi nhấn "Tải miễn phí". Sau khi tải xong, mở trình cài đặt và chọn "Cài đặt Community 2022". Trong cửa sổ hiện ra sau đó, chỉ chọn "Desktop development with C++" ("Phát triển ứng dụng máy tính để bàn bằng C++"), rồi nhấn cài đặt.

Nếu không muốn cài Visual Studio đầy đủ, có thể cuộn xuống mục "Tất cả tải xuống", tìm "Build Tools for Visual Studio" trong phần "Tools for Visual Studio", rồi nhấn nút "Download" ("Tải xuống") phía sau. Sau khi tải xong, mở trình cài đặt, làm theo hướng dẫn để chọn "Desktop development with C++" ("Phát triển ứng dụng máy tính để bàn bằng C++") rồi cài đặt. Cũng có thể dùng công cụ [PortableBuildTools](https://github.com/Data-Oriented-House/PortableBuildTools) để chỉ cài trình biên dịch MSVC.

[^temurin]: [Eclipse Temurin](https://adoptium.net/) chính là [AdoptOpenJDK](https://adoptopenjdk.net/) trước đây; dự án sau đã được chuyển giao cho [Eclipse Foundation](https://www.eclipse.org/org/foundation/) vào tháng 7 năm 2021. Xem chi tiết trong [thông báo này](https://blog.adoptopenjdk.net/2021/03/transition-to-eclipse-an-update/).

[^pythonimpl]: [Các bản triển khai Python thay thế | Python.org](https://www.python.org/download/alternatives/)
