disqus:

## Cấu hình môi trường

Muốn viết chương trình thuận lợi, trước hết cần chuẩn bị công cụ phù hợp.

### Môi trường phát triển tích hợp

Thao tác với IDE tương đối đơn giản, nên người mới bắt đầu thường chọn IDE để
viết mã. Trong thi đấu, công cụ phổ biến là
[Dev-C++](../tools/editor/devcpp.md); nếu môi trường thi là Windows, thông
thường IDE này cũng sẽ được cung cấp.

### Trình biên dịch

#### Windows

Nên dùng trình biên dịch GNU. Có thể tải và cài MinGW từ
[MinGW Distro](https://nuwen.net/mingw.html). Ngoài ra, trên Windows cũng có thể
chọn [trình biên dịch Microsoft Visual C++](https://docs.microsoft.com/en-us/cpp/build/projects-and-build-systems-cpp);
công cụ này có thể tải và cài từ
[trang Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019).

#### macOS

Chạy lệnh sau trong dòng lệnh:

```bash
xcode-select --install
```

#### Linux

Dùng `g++ -v` để kiểm tra đã cài `g++` hay chưa.

Có thể cài bằng lệnh sau:

```bash
sudo apt update && sudo apt install g++
```

#### Biên dịch mã trong dòng lệnh

Khi đã quen hơn, nhiều người sẽ dùng dòng lệnh để biên dịch mã vì cách này linh
hoạt hơn. Khi đó, người viết không phụ thuộc vào IDE mà có thể dùng trình soạn thảo văn
bản quen thuộc để viết mã.

```bash
g++ test.cpp -o test -lm
```

`g++` là trình biên dịch của ngôn ngữ C++ (trình biên dịch của C là `gcc`).
`-o` dùng để chỉ định tên tệp thực thi, còn tùy chọn biên dịch `-lm` dùng để
liên kết thư viện toán học `libm`, giúp mã dùng `math.h` có thể biên dịch và
chạy bình thường.

Ghi chú: Chương trình C++ thường không cần `-lm` vẫn có thể biên dịch và chạy
bình thường. Các đề NOI/NOIP qua các năm đều có `-lm` trong tùy chọn biên dịch
C++, nên phần này cũng thêm tùy chọn này.

## Đoạn mã đầu tiên

Bắt đầu hành trình nhập môn C++ bằng chương trình ví dụ sau.

Ghi chú: Trước khi gõ mã, cần chuyển bộ gõ sang tiếng Anh.

Chương trình C++:

```cpp
#include <iostream>  // nạp tệp tiêu đề

int main() {                     // định nghĩa hàm main
  std::cout << "Hello, world!";  // dùng cout trong không gian tên chuẩn
  return 0;  // trả về 0, kết thúc hàm main; trong C++ có thể bỏ qua dòng này
}
```

Chương trình C:

```c
#include <stdio.h>  // nạp tệp tiêu đề

int main() {                // định nghĩa hàm main
  printf("Hello, world!");  // in Hello, world!
  return 0;                 // trả về 0, kết thúc hàm main
}
```

Lưu ý: Chương trình C trong phần này chỉ dùng để tham khảo. C++ về cơ bản tương thích với
C, đồng thời có nhiều tính năng mới giúp thí sinh làm việc hiệu quả hơn trong
phòng thi. Xem thêm
[khác biệt giữa C++ và các ngôn ngữ thường dùng khác](./cpp-other-langs.md).
