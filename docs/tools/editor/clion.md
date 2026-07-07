## Giới thiệu

CLion là một môi trường phát triển tích hợp (IDE) C/C++ đa nền tảng, giàu tính năng và mạnh mẽ, do JetBrains phát triển.

![Giao diện CLion](./images/clion.png)

## Hướng dẫn chính thức

Trang web chính thức cung cấp hướng dẫn [học CLion](https://www.jetbrains.com/clion/learn/).

## Cài đặt

Xem [tải CLion](https://www.jetbrains.com/clion/download/).

## Cấu hình

<span id="cài-đặt-toolchain"></span>

### Cài đặt chuỗi công cụ

Mặc định CLion không đi kèm trình biên dịch, công cụ xây dựng và công cụ gỡ lỗi; cần cài đặt thủ công.

#### Windows

Xem [hướng dẫn cấu hình CLion trên Windows | tài liệu CLion](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html).

Cần lưu ý rằng phiên bản CLion cho Windows có sẵn MinGW, nên có thể không cần cài đặt thêm chuỗi công cụ MinGW.

#### Linux

##### Debian/Ubuntu và các bản phân phối phái sinh

```bash
sudo apt install make cmake # công cụ xây dựng
sudo apt install gcc g++ gdb # trình biên dịch và trình gỡ lỗi
sudo apt install clang clang++ llvm lldb # cũng có thể chọn dùng chuỗi công cụ clang
```

##### Arch Linux và các bản phân phối phái sinh

```bash
sudo pacman -S make cmake # công cụ xây dựng
sudo pacman -S gcc g++ gdb # trình biên dịch và trình gỡ lỗi
sudo pacman -S clang clang++ llvm lldb # cũng có thể chọn dùng chuỗi công cụ clang
```

##### Fedora/RHEL/CentOS/Rocky Linux

```bash
sudo dnf install make cmake # công cụ xây dựng
sudo dnf install gcc g++ gdb # trình biên dịch và trình gỡ lỗi
sudo dnf install clang clang++ llvm lldb # cũng có thể chọn dùng chuỗi công cụ clang
```

#### macOS

Xem [hướng dẫn cấu hình CLion trên macOS | tài liệu CLion](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-macos.html).

<span id="thiết-lập-toolchain"></span>

### Thiết lập chuỗi công cụ

<span id="thiết-lập-toolchain-thủ-công"></span>

#### Thiết lập chuỗi công cụ thủ công

CLion mới cài sẽ tự động phát hiện chuỗi công cụ phát triển C/C++ trong hệ thống. Nếu chuỗi công cụ đã cài không được phát hiện tự động, có thể vào `Settings` (`Thiết lập`), tìm `Build, Execution, Deployment`>`Toolchains` (`Biên dịch, Thực thi, Triển khai`>`Chuỗi công cụ`) để cấu hình thủ công.

![Cấu hình chuỗi công cụ](./images/clion-toolchain.png)

### Biên dịch, chạy và gỡ lỗi

Khi mới ra đời, CLion được thiết kế cho các dự án C/C++ phức tạp gồm nhiều tệp, và các phiên bản CLion trước đây mặc định dùng [CMake](https://cmake.org/) làm công cụ xây dựng. Tuy nhiên, từ CLion 2022.3, CLion đã hỗ trợ [chạy tệp đơn C, C++](https://www.jetbrains.com/help/clion/run-single-file.html).

Có nhiều cách để chạy một chương trình C++; một quy trình đơn giản như sau:

1.  Tạo một dự án C/C++: `New -> Project -> C++ Executable` (`Mới -> Dự án -> Tệp thực thi C++`), chọn vị trí và phiên bản chuẩn ngôn ngữ phù hợp, rồi nhấp `Create` (`Tạo`).
2.  Mở dự án. Lúc này, trong thư mục dự án nên có một thư mục `cmake-build-debug`, một tệp `CMakeLists.txt` và một tệp `main.cpp`. Vì không cần dùng CMake để quản lý dự án, có thể xóa tệp `CMakeLists.txt`, thư mục `cmake-build-debug` và toàn bộ tệp bên trong nó.
3.  Nhấp mở tệp `main.cpp`, rồi nhấp chuột phải trong vùng soạn thảo; tùy chọn `Run 'main.cpp'` (`Chạy 'main.cpp'`) sẽ xuất hiện. Chọn tùy chọn này, CLion có thể tự động tạo cấu hình chạy và chạy chương trình.

![Chạy tệp C++ đơn](./images/clion-single-file-execution.png)

Nếu cần gỡ lỗi chương trình, có thể đặt điểm dừng trong vùng soạn thảo, nhấp chuột phải trong vùng soạn thảo, rồi chọn `Debug 'main.cpp'` (`Gỡ lỗi 'main.cpp'`).

### Biên dịch, chạy và gỡ lỗi bằng CMake

#### Thiết lập

CLion cũng có thể dùng [CMake](https://cmake.org/) làm công cụ xây dựng. Thiết lập liên quan đến CMake có thể được chỉnh trong `Build, Execution, Deployment -> Toolchains -> CMake` (`Biên dịch, Thực thi, Triển khai -> Chuỗi công cụ -> CMake`).

![Thiết lập CMake](./images/clion-cmake.png)

#### Tùy chọn biên dịch

Mặc định CMake dùng `CMakeLists.txt` trong thư mục gốc dự án làm tệp cấu hình xây dựng dự án. Có thể dùng lệnh `add_compile_options` để thêm tùy chọn biên dịch, ví dụ:

```cmake
add_compile_options(-std=c++17 -DDEBUG)
```

Các chức năng khác của CMake xem trong [tài liệu chính thức của CMake](https://cmake.org/documentation/).

## Nhận giấy phép CLion IDE miễn phí

CLion là sản phẩm trả phí, nhưng có thể xin giấy phép đặc biệt bằng email giáo dục hoặc dự án mã nguồn mở. Sau khi được cấp, người dùng không chỉ có thể dùng CLion IDE bản quyền miễn phí, mà còn có thể dùng miễn phí các sản phẩm trả phí khác do JetBrains phát triển.

???+ note "Ghi chú"
    [Từ tháng 5 năm 2025, CLion miễn phí cho mục đích phi thương mại.](https://blog.jetbrains.com/clion/2025/05/clion-is-now-free-for-non-commercial-use)

    Theo định nghĩa trong thỏa thuận đăng ký Toolbox cho mục đích phi thương mại, sản phẩm thương mại là sản phẩm được phân phối hoặc cung cấp có thu phí, hoặc được dùng như một phần hoạt động thương mại của người dùng. Tuy nhiên, định nghĩa này loại trừ một số nhóm trường hợp cụ thể. Các trường hợp phi thương mại thường gặp bao gồm học tập và tự học, mọi hình thức sáng tạo nội dung, mã nguồn mở và phát triển theo sở thích.

### Dùng email giáo dục để nhận

Vào trang [giấy phép giáo dục miễn phí](https://www.jetbrains.com/community/education/#students) trên trang chính thức, nhấp nút `Apply` (`Áp dụng`), rồi điền thông tin liên quan để đăng ký.

![Giấy phép giáo dục](./images/clion-edu.png)

Lưu ý: khi đăng ký, ở mục email cần điền email giáo dục do trường cấp; giấy phép đặc biệt chỉ nhận được sau khi xác minh email.

Nếu không có email giáo dục, xem các phương thức xác minh khác được JetBrains hỗ trợ trên trang đăng ký.

### Dùng dự án mã nguồn mở để nhận

Nếu là một trong những nhà phát triển hoặc người duy trì cốt lõi của một dự án mã nguồn mở, có thể thử đăng ký Open Source Development License. Quy trình đăng ký tương tự giấy phép giáo dục, nhưng cần điền địa chỉ kho mã nguồn của dự án mã nguồn mở.

![Giấy phép phát triển mã nguồn mở](./images/clion-oss.png)
