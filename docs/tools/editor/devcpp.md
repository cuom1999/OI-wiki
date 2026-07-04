author: topdevst, ksyx, ouuan, Doveqise, hsfzLZH1, wangqingshiyu, sshwy, NanoApe, DawnMagnet, CamberLoid, royqh1979

## Giới thiệu

Dev-C++ là một môi trường phát triển tích hợp (IDE) tự do dùng để phát triển chương trình C/C++, được phân phối theo giấy phép GPL, dùng MinGW và GDB làm hệ thống biên dịch và gỡ lỗi. Dev-C++ chạy trên Microsoft Windows.

Ưu điểm của Dev-C++ là giao diện đơn giản, thân thiện, cài đặt thuận tiện và hỗ trợ biên dịch tệp đơn, nên nó trở thành lựa chọn đầu tiên của nhiều thí sinh OI mới bắt đầu và người mới học C++. Trong NOIP, các tỉnh dùng Windows làm hệ thống thi đấu thường cài sẵn Dev-C++.

Dev-C++ bắt nguồn từ Bloodshed Dev-C++ do Colin Laplace viết. Phiên bản này ngừng cập nhật từ ngày 22 tháng 2 năm 2005. Năm 2006, nhà phát triển chính Colin Laplace từng giải thích về việc này: "Do bận rộn với công việc ngoài đời, tôi không có thời gian tiếp tục phát triển Dev-C++."

Orwell Dev-C++ là một phiên bản phái sinh của Dev-C++, do lập trình viên độc lập Orwell (Johan Mes) phát triển và duy trì. Phiên bản này sửa lỗi cho Dev-C++ gốc và cập nhật phiên bản trình biên dịch. Nói chung, Dev-C++ 5.x đều là Orwell Dev-C++. Lần cập nhật cuối cùng của nó là vào năm 2015, với phiên bản 5.11.

Embarcadero Dev-C++[^ref1] là phiên bản kế nhiệm Bloodshed Dev-C++ và Orwell Dev-C++. Năm 2020, Embarcadero tài trợ và tiếp quản dự án Dev-C++ cũ để tiếp tục phát triển. Embarcadero Dev-C++ bổ sung hỗ trợ DPI cao, cập nhật trình biên dịch để hỗ trợ các chuẩn C++ mới hơn, đồng thời thêm dark mode.

Các bản phân phối Dev-C++ nêu trên đều được coi là "chính thức". Ngoài ra, sau khi Orwell Dev-C++ ngừng cập nhật vào năm 2015, vì nhu cầu giảng dạy, một nhà phát triển cá nhân từ Trung Quốc là [royqh1979](https://github.com/royqh1979) quyết định tiếp tục phát triển nhánh Dev-C++ cá nhân của mình, đặt tên là Red Panda Dev-C++[^ref2]. Nhánh này tích hợp gợi ý thông minh và MinGW64 phiên bản cao, rất thuận tiện cho việc tự học và sử dụng cá nhân trong nước.

Sau khi phát hành Red Panda Dev-C++ 6.7.5, tác giả dùng qt5 phát triển Red Panda C++[^ref3] hoàn toàn mới, có thể chạy native trên Windows, Linux, macOS và các hệ thống khác. Giao diện của Red Panda C++ tương tự Dev-C++; ngoài các chức năng giống Dev-C++ nhưng hoàn thiện hơn như biên dịch tệp đơn, gỡ lỗi, tô sáng cú pháp, tìm kiếm/thay thế, nó còn cung cấp các chức năng cơ bản thường thấy ở IDE hiện đại như **giao diện tối**, **gợi ý mã thông minh**, **đổi tên biến/hàm**, **chuyển/tự nhận diện mã hóa tệp**. Ngoài ra, Red Panda C++ còn có chức năng bộ đề tương tự CP Editor: có thể tự viết hoặc **tải sample bài từ các website OJ/contest thường gặp**, rồi **tự động chạy và kiểm thử chương trình**.

## Hướng dẫn sử dụng

### Phím tắt thường dùng

#### Nhóm tệp

-   `Ctrl + N`: tạo mã nguồn
-   `Ctrl + O`: mở tệp
-   `Ctrl + W`: đóng tệp
-   `Ctrl + Shift + W`: đóng tất cả tệp
-   `Ctrl + P`: in tệp

#### Nhóm định dạng

-   `Ctrl + /`: chú thích và bỏ chú thích
-   `Tab`: thụt lề
-   `Shift + Tab`: bỏ thụt lề

#### Thao tác dòng

-   `Ctrl + E`: sao chép dòng
-   `Ctrl + D`: xóa dòng
-   `Ctrl + Shift + Up`: di chuyển lên
-   `Ctrl + Shift + Down`: di chuyển xuống

#### Nhóm nhảy vị trí

-   `Ctrl + F`: tìm kiếm
-   `Ctrl + R`: thay thế
-   `F3`: tìm tiếp
-   `Shift + F3`: tìm trước
-   `Ctrl + G`: tới số dòng chỉ định
-   `Shift + Ctrl + G`: tới hàm chỉ định
-   `Ctrl + [1 ~ 9]`: đặt bookmark
-   `Alt + [1 ~ 9]`: nhảy tới bookmark

#### Nhóm hiển thị

-   `Ctrl + cuộn chuột`: phóng to hoặc thu nhỏ cỡ chữ
-   `Ctrl + F11`: toàn màn hình hoặc khôi phục

#### Nhóm chạy

-   `F9`: chỉ biên dịch
-   `F10`: chỉ chạy
-   `F11`: biên dịch và chạy
-   `F12`: biên dịch lại toàn bộ

#### Nhóm gỡ lỗi

-   `F2`: tới breakpoint
-   `F4`: đặt hoặc hủy breakpoint
-   `F5`: chạy gỡ lỗi
-   `F6`: dừng
-   `F7`: gỡ lỗi từng bước

### Quy trình gỡ lỗi

1.  Đặt cấu hình trình biên dịch thành `TDM-GCC 4.9.2 64-bit Debug`.
2.  Nhấn `F4` để đặt hoặc hủy breakpoint gỡ lỗi.
3.  Đặt con trỏ lên biến, nhấn `Alt + A` để thêm biến cần theo dõi vào cửa sổ gỡ lỗi.
4.  Nhấn `F5` để bắt đầu gỡ lỗi.
5.  Nhấn `F7` hoặc `Alt + N` để gỡ lỗi từng bước.
6.  Nhấn `Alt + S` để nhảy tới breakpoint gỡ lỗi tiếp theo.
7.  Nhấn `F6` để dừng gỡ lỗi.

## Mở rộng

### Thêm tùy chọn biên dịch

Nhấp Tools -> Compiler Options, rồi chọn thẻ "Code Generation/Optimization". Dưới đây giới thiệu một vài tùy chọn biên dịch thường dùng.

#### Bật tối ưu hóa

Tối ưu hóa thời gian chạy hoặc dung lượng chương trình.

Chọn nhãn tùy chọn "Optimization level (-Ox)" trong thẻ con "Code Generation".

![](./images/Dev-C++-11.png)

#### Đổi chuẩn ngôn ngữ

Dùng tính năng ngôn ngữ mới, hoặc thử biên dịch mã dưới chuẩn cũ.

Chọn nhãn tùy chọn "Language standard (-std)" trong thẻ con "Code Generation".

![](./images/Dev-C++-12.png)

#### Hiển thị nhiều cảnh báo nhất

Trợ thủ nhỏ khi tìm lỗi.

Chọn nhãn tùy chọn "Show most warnings (-Wall)" trong thẻ con "Code Warnings".

![](./images/Dev-C++-13.png)

#### Sinh thông tin gỡ lỗi

Khi xuất hiện thông báo "Project does not have debugging information, do you want to enable debugging and rebuild?" rồi bị thoát sau khi nhấp, hoặc khi muốn dùng chức năng gỡ lỗi, cần bật chức năng này.

Chọn nhãn tùy chọn "Generate debugging information" trong thẻ con "Linker".

![](./images/Dev-C++-14.png)

### Một số mẹo biên dịch

Nhấp Tools -> Compiler Options, rồi chọn thẻ "Compiler". Dưới đây giới thiệu một vài mẹo thường dùng.

#### Tăng stack

Tránh các tình huống như DFS làm tràn stack hệ thống.

Thêm lệnh `-Wl,--stack=128000000` vào "Add the following commands when calling the linker".

Lệnh này đặt stack khoảng 128 MB; nếu cần, có thể tự tăng thêm.

![](./images/Dev-C++-15.png)

#### Định nghĩa macro

Thuận tiện để chấm cục bộ bằng file input/output hoặc dùng cho mục đích khác.

Thêm lệnh `-D[String]` vào "Add the following commands when calling the linker".

Trong đó `[String]` đổi thành tên macro bạn cần.

Như hình, sau khi bật tùy chọn biên dịch, đoạn mã sau có thể đọc dữ liệu từ tệp `test.in` và xuất ra tệp `test.out`.

![](./images/Dev-C++-16.png)

```cpp
#ifdef LOCAL
freopen("test.in", "r", stdin);
freopen("test.out", "w", stdout);
#endif
```

#### Định dạng mã

Nhấp Astyle -> Format Current File, hoặc nhấn Ctrl+Shift+A để định dạng mã.

![](./images/Dev-C++-17.png)

### Làm đẹp giao diện

#### Phông chữ

Nhấp Tools -> Editor Options, rồi chọn thẻ "Display".

![](./images/Dev-C++-9.png)

#### Theme

Nhấp Tools -> Editor Options, rồi chọn thẻ "Syntax". Có thể dùng theme có sẵn hoặc tự điều chỉnh.

![](./images/Dev-C++-10.png)

## Tài liệu tham khảo

[^ref1]: Mã nguồn dự án được lưu tại [GitHub](https://github.com/Embarcadero/Dev-Cpp) và [SourceForge](https://sourceforge.net/projects/embarcadero-devcpp/).

[^ref2]: Mã nguồn được lưu tại [Github](https://github.com/royqh1979/Dev-Cpp)

[^ref3]: Trang chủ dự án nằm tại [Red Panda C++](https://royqh1979.gitee.io/redpandacpp), mã nguồn được lưu tại [Github](https://github.com/royqh1979/RedPanda-CPP/)
