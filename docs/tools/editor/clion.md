## Giới thiệu

CLion là một môi trường phát triển tích hợp (IDE) C/C++ đa nền tảng, giàu tính năng và mạnh mẽ, do JetBrains phát triển.

![Clion](./images/clion.png)

## Hướng dẫn chính thức

Trang web chính thức cung cấp hướng dẫn [Learn CLion](https://www.jetbrains.com/clion/learn/).

## Cài đặt

Xem [Download CLion](https://www.jetbrains.com/clion/download/).

## Cấu hình

### Cài đặt toolchain

Mặc định CLion không đi kèm trình biên dịch, công cụ build và công cụ gỡ lỗi; cần cài đặt thủ công.

#### Windows

Xem [Tutorial: Configure CLion on Windows | CLion Documentation](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html).

Đáng chú ý là phiên bản CLion cho Windows có sẵn MinGW, nên có thể không cần cài đặt thêm toolchain MinGW.

#### Linux

##### Debian/Ubuntu và các bản phân phối phái sinh

```bash
sudo apt install make cmake # build tools
sudo apt install gcc g++ gdb # compiler and debugger
sudo apt install clang clang++ llvm lldb # you can also choose to use clang toolchain
```

##### Arch Linux và các bản phân phối phái sinh

```bash
sudo pacman -S make cmake # build tools
sudo pacman -S gcc g++ gdb # compiler and debugger
sudo pacman -S clang clang++ llvm lldb # you can also choose to use clang toolchain
```

##### Fedora/RHEL/CentOS/Rocky Linux

```bash
sudo dnf install make cmake # build tools
sudo dnf install gcc g++ gdb # compiler and debugger
sudo dnf install clang clang++ llvm lldb # you can also choose to use clang toolchain
```

#### macOS

Xem [Tutorial: Configure CLion on macOS | CLion Documentation](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-macos.html).

### Thiết lập toolchain

#### Thiết lập toolchain thủ công

CLion mới cài sẽ tự động phát hiện toolchain phát triển C/C++ trong hệ thống. Nếu toolchain đã cài không được phát hiện tự động, có thể vào `Settings`, tìm `Build, Execution, Deployment`>`Toolchains` để cấu hình thủ công.

![Config Toolchains](./images/clion-toolchain.png)

### Biên dịch, chạy và gỡ lỗi

Khi mới ra đời, CLion được thiết kế cho các dự án C/C++ phức tạp gồm nhiều tệp, và các phiên bản CLion trước đây mặc định dùng [CMake](https://cmake.org/) làm công cụ build. Tuy nhiên, từ CLion 2022.3, CLion đã hỗ trợ [chạy tệp đơn C, C++](https://www.jetbrains.com/help/clion/run-single-file.html).

Có nhiều cách để chạy một chương trình C++; một quy trình đơn giản như sau:

1.  Tạo một project C/C++: `New -> Project -> C++ Executable`, chọn vị trí và phiên bản chuẩn ngôn ngữ phù hợp, rồi nhấp `Create`.
2.  Mở project. Lúc này, trong thư mục project nên có một thư mục `cmake-build-debug`, một tệp `CMakeLists.txt` và một tệp `main.cpp`. Vì ta không cần dùng CMake để quản lý project, có thể xóa tệp `CMakeLists.txt`, thư mục `cmake-build-debug` và toàn bộ tệp bên trong nó.
3.  Nhấp mở tệp `main.cpp`, rồi nhấp chuột phải trong vùng soạn thảo; bạn sẽ thấy tùy chọn `Run 'main.cpp'`. Chọn tùy chọn này, CLion có thể tự động tạo cấu hình chạy và chạy chương trình.

![C++ Single File Execution](./images/clion-single-file-execution.png)

Nếu cần gỡ lỗi chương trình, có thể đặt breakpoint trong vùng soạn thảo, nhấp chuột phải trong vùng soạn thảo, rồi chọn `Debug 'main.cpp'`.

### Biên dịch, chạy và gỡ lỗi bằng CMake

#### Thiết lập

CLion cũng có thể dùng [CMake](https://cmake.org/) làm công cụ build. Thiết lập liên quan đến CMake có thể được chỉnh trong `Build, Execution, Deployment -> Toolchains -> CMake`.

![CMake Settings](./images/clion-cmake.png)

#### Tùy chọn biên dịch

Mặc định CMake dùng `CMakeLists.txt` trong thư mục gốc project làm tệp cấu hình build project. Có thể dùng lệnh `add_compile_options` để thêm tùy chọn biên dịch, ví dụ:

```cmake
add_compile_options(-std=c++17 -DDEBUG)
```

Các chức năng khác của CMake xem trong [tài liệu chính thức của CMake](https://cmake.org/documentation/).

## Nhận giấy phép CLion IDE miễn phí

CLion là sản phẩm trả phí, nhưng có thể xin giấy phép đặc biệt bằng email giáo dục hoặc dự án mã nguồn mở. Sau khi được cấp, bạn không chỉ có thể dùng CLion IDE bản quyền miễn phí, mà còn có thể dùng miễn phí các sản phẩm trả phí khác do JetBrains phát triển.

???+ note "Ghi chú"
    [Từ tháng 5 năm 2025, CLion miễn phí cho mục đích phi thương mại.](https://blog.jetbrains.com/clion/2025/05/clion-is-now-free-for-non-commercial-use)

    Theo định nghĩa trong thỏa thuận đăng ký Toolbox cho mục đích phi thương mại, sản phẩm thương mại là sản phẩm được phân phối hoặc cung cấp có thu phí, hoặc được dùng như một phần hoạt động thương mại của bạn. Tuy nhiên, một số nhóm trường hợp được loại trừ rõ ràng khỏi định nghĩa này. Các trường hợp phi thương mại thường gặp bao gồm học tập và tự học, mọi hình thức sáng tạo nội dung, mã nguồn mở và phát triển theo sở thích.

### Dùng email giáo dục để nhận

Vào trang [Free Educational Licenses](https://www.jetbrains.com/community/education/#students) trên trang chính thức, nhấp nút `Apply`, rồi điền thông tin liên quan để đăng ký.

![Educational Licenses](./images/clion-edu.png)

Chú ý: khi đăng ký, ở mục email hãy điền email giáo dục do trường cấp; giấy phép đặc biệt chỉ nhận được sau khi xác minh email.

Nếu không có email giáo dục, hãy xem các phương thức xác minh khác được JetBrains hỗ trợ trên trang đăng ký.

### Dùng dự án mã nguồn mở để nhận

Nếu bạn là một trong những nhà phát triển hoặc maintainer cốt lõi của một dự án mã nguồn mở, bạn có thể thử đăng ký Open Source Development License. Quy trình đăng ký tương tự giấy phép giáo dục, nhưng cần điền địa chỉ kho mã nguồn của dự án mã nguồn mở.

![Open Source Development License](./images/clion-oss.png)
