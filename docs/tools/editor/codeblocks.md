## Giới thiệu

Code::Blocks là một môi trường phát triển tích hợp (IDE) mã nguồn mở được phát triển bằng C++, dùng wxWidgets làm thư viện giao diện đồ họa. Dự án bắt đầu từ năm 2001, hiện do cộng đồng chính thức duy trì, và chủ yếu dùng cho phát triển bằng các ngôn ngữ như C, C++ và Fortran.[^ref1]

Ưu điểm:

-   **Nhẹ và hiệu quả**: Code::Blocks chiếm ít tài nguyên và khởi động nhanh, phù hợp với môi trường tài nguyên hạn chế, lập trình viên thích IDE nhẹ, cũng như người mới học.

-   **Tương thích đa nền tảng**: hỗ trợ nhiều hệ điều hành như Windows, Linux và macOS, cung cấp trải nghiệm người dùng nhất quán để lập trình viên có thể làm việc liền mạch trên nhiều nền tảng.

-   **Hỗ trợ nhiều trình biên dịch**: hỗ trợ nhiều trình biên dịch, bao gồm GCC, MSVC (Microsoft Visual C++), Digital Mars và Borland C++ 5.5, cho phép lập trình viên chọn công cụ biên dịch phù hợp nhất theo nhu cầu dự án.

Nhược điểm:

-   **Phạm vi chức năng hạn chế**: so với các IDE như CLion hoặc Eclipse, chức năng và công cụ tích hợp còn khá cơ bản, có thể chưa đủ cho nhu cầu của các dự án phức tạp.

-   **Hệ sinh thái plugin yếu**: dù hỗ trợ plugin để mở rộng chức năng, số lượng và chất lượng plugin bên thứ ba còn hạn chế, nên hệ sinh thái plugin tương đối yếu.

## Cài đặt

Xem [trang web chính thức của Code::Blocks](https://www.codeblocks.org/downloads/), chọn tải trình cài đặt nhị phân (Binary Release), hoặc tải mã nguồn để biên dịch cài đặt (Source Code). Sau đó chọn trình cài đặt phù hợp với nhu cầu và hệ điều hành, rồi hoàn thành cài đặt theo hướng dẫn.

???+ note "Tải gói cài đặt có kèm MinGW"
    Với người dùng Windows, nếu không muốn cấu hình trình biên dịch thủ công, nên tải trình cài đặt có kèm MinGW, chẳng hạn `codeblocks-xxxxmingw-setup.exe`. Phiên bản này đã bao gồm trình biên dịch GCC, nên có thể bắt đầu phát triển dự án C và C++ mà không cần cài đặt và cấu hình thêm.

![CodeBlocks DownLoad](./images/codeblocks-1.png)

## Cấu hình

Nếu khi cài đặt bạn chọn trình cài đặt không kèm MinGW, hoặc cần dùng trình biên dịch khác, thì cần cài đặt và cấu hình trình biên dịch thủ công, rồi thiết lập Code::Blocks để dùng trình biên dịch đó.

### Cài đặt toolchain

Tham khảo hướng dẫn cài đặt [trình biên dịch](../compiler.md) trên trang này để tải và cài đặt trình biên dịch bạn cần.

### Thiết lập toolchain

Khi khởi động Code::Blocks lần đầu, phần mềm sẽ tự động quét các trình biên dịch đã cài trong hệ thống. Nếu không tìm thấy trình biên dịch, có thể thêm thủ công theo các bước sau:

1.  Mở Code::Blocks, nhấp `Settings -> Compiler` trên thanh menu để mở hộp thoại thiết lập trình biên dịch (như hình dưới).![CodeBlocks Compiler Settings](./images/codeblocks-2.png)
2.  Trong danh sách thả xuống `Selected compiler`, chọn trình biên dịch cần cấu hình, ví dụ `GNU GCC Compiler`.
3.  Trong thẻ `Toolchain executables`, nhấp nút `Auto-detect`; Code::Blocks sẽ tự động quét các trình biên dịch đã cài trong hệ thống.
4.  Nếu tự động quét thất bại, bạn có thể đặt thủ công đường dẫn trình biên dịch. Trong `Compiler's installation directory`, nhập đường dẫn cài đặt của trình biên dịch, ví dụ `C:\MinGW\bin`.
5.  Sau khi thiết lập xong, nhấp `OK` để lưu; bây giờ bạn có thể dùng trình biên dịch đó để biên dịch và chạy project.

## Sử dụng

Code::Blocks có trình quản lý project tích hợp và hỗ trợ người dùng tự định nghĩa cách build project. Bạn có thể đặt tùy chọn biên dịch trong `Project -> Build options`, chọn trình biên dịch, tùy chọn biên dịch, tùy chọn liên kết, v.v.; cũng có thể đặt thuộc tính project trong `Project -> Properties`, chẳng hạn tên project, đường dẫn và danh sách tệp.

??? note "Cấu hình Makefile"
    Mặc định Code::Blocks không yêu cầu viết Makefile. Nếu cần dùng Makefile tùy chỉnh, có thể chọn tùy chọn `This is a custom Makefile` trong `Project -> Properties`, rồi đặt đường dẫn Makefile trong `Project -> Build options`.

### Tạo project

Các ngôn ngữ lập trình mà Code::Blocks hỗ trợ bao gồm C, C++ và Fortran. Sau khi khởi động Code::Blocks, có thể tạo project mới qua `File -> New -> Project`, chọn loại project và template, rồi làm theo hướng dẫn để đặt tên project, đường dẫn, trình biên dịch, v.v.; cuối cùng nhấp `Finish` để hoàn tất tạo project.

Code::Blocks cũng hỗ trợ biên dịch và chạy tệp đơn. Có thể tạo tệp mới qua `File -> New -> File`; sau khi viết mã và lưu, nhấp nút `Build and run` trên thanh công cụ, hoặc nhấn phím `F9`, để tự động biên dịch và chạy tệp hiện tại.

### Build và chạy

Lấy một project Console Application đơn giản làm ví dụ, dưới đây là cách build và chạy project:

1.  Sau khi tạo project xong, bạn sẽ thấy một tệp `main.cpp` mặc định. Bạn có thể viết mã trong tệp này rồi lưu lại.
2.  Sau khi viết mã xong, nhấp nút `Build and run` trên thanh công cụ, hoặc nhấn phím `F9`; Code::Blocks sẽ tự động biên dịch và chạy project.
3.  Sau khi biên dịch và chạy, cửa sổ output sẽ hiển thị kết quả xuất của chương trình. Bạn có thể xem output trong cửa sổ này và điều chỉnh mã khi cần.
4.  Nếu chỉ cần biên dịch project mà không chạy, có thể nhấp nút `Build` trên thanh công cụ, hoặc nhấn `Ctrl + F9`; Code::Blocks sẽ chỉ biên dịch project, không chạy chương trình.

### Gỡ lỗi

Code::Blocks tích hợp debugger. Bạn có thể thiết lập và khởi động debugger trong menu `Debug` để hỗ trợ định vị và giải quyết lỗi trong chương trình.

Tương tự, lấy một project Console Application đơn giản làm ví dụ, dưới đây là cách gỡ lỗi project:

1.  **Đặt breakpoint**: nhấp chuột trái ở bên trái dòng mã cần gỡ lỗi để đặt breakpoint; chương trình sẽ dừng thực thi tại breakpoint.
2.  **Khởi động debugger**: nhấp nút `Debug` trên thanh công cụ, hoặc nhấn phím `F8`; Code::Blocks sẽ tự động biên dịch và khởi động debugger.
3.  **Gỡ lỗi chương trình**: trong debugger, bạn có thể thực thi từng bước, xem giá trị biến, call stack, v.v. để hỗ trợ định vị và giải quyết lỗi trong chương trình.
4.  **Dừng gỡ lỗi**: sau khi gỡ lỗi xong, có thể nhấp nút `Stop` trên thanh công cụ, hoặc nhấn `Shift + F8`, để dừng debugger.

## Tùy chỉnh thiết lập

Code::Blocks cung cấp nhiều tùy chọn thiết lập để giúp điều chỉnh hành vi của trình soạn thảo. Dưới đây là một số thiết lập thường dùng:

### Thiết lập giao diện

1.  Trong `Settings -> Editor`, có thể đặt phông chữ, màu sắc, thụt lề, tự động hoàn thành, v.v. của trình soạn thảo.
2.  Trong `Settings -> Environment`, có thể đặt hành vi toàn cục của Code::Blocks, chẳng hạn tự động lưu, tự động sao lưu, tự động gợi ý, v.v.
3.  Trong menu `View`, có thể điều chỉnh bố cục của trình soạn thảo, chẳng hạn bật/tắt trình duyệt tệp, thanh công cụ, thanh trạng thái, cửa sổ output, v.v.

### Thiết lập plugin

Code::Blocks hỗ trợ plugin để mở rộng chức năng. Có thể xem và cài đặt plugin khả dụng qua `Settings -> Plugins`, chẳng hạn DoxyBlocks, wxSmith, v.v. Dưới đây là một số plugin thường dùng:

-   **DoxyBlocks**: plugin tích hợp công cụ sinh tài liệu nổi tiếng Doxygen, có thể sinh tài liệu project trực tiếp trong Code::Blocks.
-   **wxSmith**: plugin dùng để phát triển ứng dụng wxWidgets, cung cấp công cụ thiết kế giao diện trực quan, cho phép tạo và bố trí giao diện GUI nhanh chóng, đơn giản hóa quy trình phát triển.
-   **Thread Search**: plugin hỗ trợ tìm kiếm đa luồng, có thể nhanh chóng tìm kiếm và thay thế ký hiệu và văn bản trong project, phù hợp cho phát triển dự án lớn.

Cách cài đặt và sử dụng plugin xem trong [tài liệu plugin của Code::Blocks](https://wiki.codeblocks.org/index.php/Code::Blocks_Plugins). Hãy chọn plugin phù hợp để cài đặt và sử dụng theo nhu cầu và chức năng của plugin.

???+ warning "Chú ý"
    Plugin của Code::Blocks tương đối đơn giản và cơ bản; phần lớn plugin đã được tích hợp vào phần mềm, còn số lượng và chất lượng plugin bên thứ ba thì hạn chế. Nên chọn plugin phù hợp theo nhu cầu thực tế.

### Thiết lập phím tắt

Bạn có thể xem và sửa phím tắt qua thẻ `Settings -> Editor -> Keyboard shortcuts`, rồi điều chỉnh theo thói quen của mình.

Dưới đây là một số phím tắt thường dùng:

| Chức năng | Phím tắt |
| --------- | -------- |
| Tạo tệp mới | `Ctrl + Shift + N` |
| Mở tệp | `Ctrl + O` |
| Lưu tệp hiện tại | `Ctrl + S` |
| Lưu tất cả | `Ctrl + Shift + S` |
| Đóng tệp hiện tại | `Ctrl + W` |
| Đóng tất cả tệp | `Ctrl + Shift + W` |
| Build và chạy project hiện tại | `F9` |
| Chỉ build project hiện tại | `Ctrl + F9` |
| Chỉ biên dịch project hiện tại | `Ctrl + Shift + F9` |
| Chạy project hiện tại | `Ctrl + F10` |
| Gỡ lỗi: bắt đầu/tiếp tục | `F8` |
| Gỡ lỗi: dừng | `Shift + F8` |
| Gỡ lỗi: bước tiếp | `F7` |
| Gỡ lỗi: bước vào | `Shift + F7` |
| Gỡ lỗi: bước ra | `Ctrl + F7` |
| Gỡ lỗi: bật/tắt breakpoint | `F5` |
| Tìm kiếm | `Ctrl + F` |
| Tìm và thay thế | `Ctrl + R` |
| Đi tới dòng chỉ định | `Ctrl + G` |
| Đi tới ngoặc khớp | `Ctrl + B` |
| Bật/tắt toàn màn hình | `F11` |
| Bật/tắt toàn bộ vùng gấp | `Ctrl + Shift + -` |
| Mở toàn bộ vùng gấp | `Ctrl + Shift + +` |
| Chọn kết quả khớp tiếp theo | `Ctrl + E` |
| Chọn và nhảy tới kết quả khớp tiếp theo | `Ctrl + Shift + E` |

## Tài liệu tham khảo và chú thích

[^ref1]: [Code::Blocks - Wikipedia](https://zh.wikipedia.org/wiki/Code::Blocks)
