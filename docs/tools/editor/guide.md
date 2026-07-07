GUIDE (GAIT Universal IDE) là một môi trường phát triển tích hợp nhỏ do nhóm nghiên cứu GAIT của Đại học Hàng không Vũ trụ Bắc Kinh phát triển, được thiết kế riêng cho thí sinh NOI và hỗ trợ ba ngôn ngữ lập trình C/C++/Pascal.

???+ note "Ghi chú"
    NOI Linux 2.0, được đưa vào sử dụng từ ngày 1 tháng 9 năm 2021, không còn bao gồm GUIDE nữa.[^ref1]

## Cài đặt

### Windows

Xem <https://www.noi.cn/xw/2009-03-23/714714.shtml>.

### Linux

Xem <https://www.noi.cn/xw/2009-03-23/714714.shtml>, hoặc cài đặt theo các bước sau.

#### Các tệp thư viện động cần thiết và tên gói

| Thư viện động | Tên gói Arch | Tên gói Debian | Tên gói Fedora | Tên gói openSUSE x86 | Tên gói openSUSE x86\_64 |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------------------ |
| libpng12.so.0 | lib32-libpng12 | libpng12 | libpng12 | libpng12-0 | libpng12-0-32bit |
| libSM.so.6 | lib32-libsm | libsm6 | libSM | libSM6 | libSM6-32bit |
| libICE.so.6 | lib32-libice | libice6 | libICE | libICE6 | libICE6-32bit |
| libXi.so.6 | lib32-libxi | libxi6 | libXi | libXi6 | libXi6-32bit |
| libXrender.so.1 | lib32-libxrender | libxrender1 | libXrender | libXrender1 | libXrender1-32bit |
| libXrandr.so.2 | lib32-libxrandr | libxrandr | libXrandr | libXrandr2 | libXrandr2-32bit |
| libfreetype.so.6 | lib32-freetype2 | libfreetype6 | freetype | libfreetype6 | libfreetype6-32bit |
| libfontconfig.so.1 | lib32-fontconfig | libfontconfig1 | fontconfig | libfontconfig1 | libfontconfig1-32bit |
| libXext.so.6 | lib32-libxext | libxext6 | libXext | libXext6 | libXext6-32bit |
| libX11.so.6 | lib32-libx11 | libx11-6 | libX11 | libX11-6 | libX11-6-32bit |
| libz.so.1 | lib32-zlib | zlib1g | zlib | libz1 | libz1-32bit |
| libgthread-2.0.so.0 | lib32-glib2 | libglib2.0-0 | glib2 | libgthread-2\_0-0 | libgthread-2\_0-0-32bit |
| libglib-2.0.so.0 | lib32-glib2 | libglib2.0-0 | glib2 | libglib2\_0-0 | libglib2\_0-0-32bit |
| libstdc++.so.6 | lib32-gcc-libs | libstdc++6 | libstdc++ | libstdc++6 | libstdc++6-32bit |
| libgcc\_s.so.1 | lib32-gcc-libs | lib32gcc1 | libgcc | libgcc\_s1 | libgcc\_s1 |
| librt.so.1 | lib32-glibc | libc6 | glibc | glibc | glibc-32bit |
| libpthread.so.0 | lib32-glibc | libc6 | glibc | glibc | glibc-32bit |
| libdl.so.2 | lib32-glibc | libc6 | glibc | glibc | glibc-32bit |
| libm.so.6 | lib32-glibc | libc6 | glibc | glibc | glibc-32bit |
| libc.so.6 | lib32-glibc | libc6 | glibc | glibc | glibc-32bit |

#### Cài đặt trên Debian hoặc Ubuntu

```bash
sudo apt install -y libpng12 libsm6 libice6 libxi6 libxrender1 libxrandr libfreetype6 libfontconfig1 libxext6 libx11-6 zlib1g libglib2.0-0 libglib2.0-0 libstdc++6 lib32gcc1 libc6
wget -c http://download.noi.cn/T/noi/GUIDE-1.0.2-ubuntu.tar
tar -xvf GUIDE-1.0.2-ubuntu.tar
cd GUIDE-1.0.2-ubuntu
echo "install:\n\tinstall -Dm755 -t /usr/bin GUIDE\n\tinstall -Dm644 -t /usr/share/ lang_en.qm\n\tmkdir -p /usr/share/apis/ && cp -r apis/* /usr/share/apis/\n\tmkdir -p /usr/share/doc/GUIDE/ && mkdir -p /usr/share/doc/GUIDE/html/ && cp -r doc/*  /usr/share/doc/GUIDE/html/" > Makefile
sudo apt install -y checkinstall
sudo checkinstall --pkgname "GUIDE" --pkgversion "1.0.2" -y
```

#### Cài đặt trên openSUSE

Cài đặt `opi` theo cách được nêu trong [openSUSE/opi](https://github.com/openSUSE/opi#install).

Sau đó: (người dùng 32 bit tự xóa `-32bit`)

```bash
sudo opi checkinstall
sudo zypper install -n {libpng12-0,libSM6,libICE6,libXi6,libXrender1,libXrandr2,libfreetype6,libfontconfig1,libXext6,libX11-6,libz1,libgthread-2_0-0,libglib2_0-0,libstdc++6,libgcc_s1,glibc}-32bit
wget -c http://download.noi.cn/T/noi/GUIDE-1.0.2-ubuntu.tar
tar -xvf GUIDE-1.0.2-ubuntu.tar
cd GUIDE-1.0.2-ubuntu
echo "install:\n\tinstall -Dm755 -t /usr/bin GUIDE\n\tinstall -Dm644 -t /usr/share/ lang_en.qm\n\tmkdir -p /usr/share/apis/ && cp -r apis/* /usr/share/apis/\n\tmkdir -p /usr/share/doc/GUIDE/ && mkdir -p /usr/share/doc/GUIDE/html/ && cp -r doc/*  /usr/share/doc/GUIDE/html/" > Makefile
sudo checkinstall --pkgname "GUIDE" --pkgversion "1.0.2" -y -rpmi
```

## Chỉnh sửa tệp

Nhấp nút "New File" ("Tệp mới") trên thanh công cụ phía trên trang (hoặc dùng phím tắt <kbd>Ctrl</kbd>+<kbd>N</kbd>) để tạo tệp mới.

Theo mặc định, phông chữ mã nguồn của GUIDE không phải phông chữ monospace nên
khó đọc; vì vậy cần đổi phông chữ trong phần thiết lập.

Trong Edit -> Options -> Syntax Highlighting Settings ("Chỉnh sửa -> Tùy chọn -> Thiết lập tô sáng cú pháp"), nhấp nút "All Fonts" ("Tất cả phông chữ") để đổi phông chữ của trình soạn thảo.

Với tệp mới chưa lưu, phông chữ vẫn là phông chữ mặc định. Vì vậy, nên lưu tệp trước khi bắt đầu chỉnh sửa (nhấp nút "Save" ("Lưu") trên thanh công cụ, hoặc nhấn phím tắt <kbd>Ctrl</kbd>+<kbd>S</kbd>), rồi mới chỉnh sửa.

## Biên dịch và chạy

Sau khi chỉnh sửa xong mã nguồn, nhấp nút "Compile" ("Biên dịch") trên thanh công cụ (hoặc phím tắt <kbd>F7</kbd>) để biên dịch.

???+ note "Thay đổi tùy chọn biên dịch"
    GUIDE không có chức năng đặt tùy chọn biên dịch mặc định; người dùng chỉ có thể thay đổi tùy chọn biên dịch cho từng tệp.

    Nhấp chuột phải vào tab của tệp muốn đổi tùy chọn biên dịch, rồi chọn **Set Compile Command** (**Đặt lệnh biên dịch**) để thay đổi tùy chọn biên dịch của tệp đó.

Nếu mã nguồn biên dịch bình thường, nhấp nút "Run" ("Chạy") trên thanh công cụ (hoặc phím tắt <kbd>Ctrl</kbd>+<kbd>F5</kbd>) để chạy chương trình.

## Gỡ lỗi

Chức năng gỡ lỗi tích hợp của GUIDE có nhiều lỗi (ví dụ chương trình bị crash giữa chừng), nên không khuyến nghị dùng chức năng gỡ lỗi của GUIDE.

Khuyến nghị dùng gdb trực tiếp trong [trình dòng lệnh](../cmd.md) để gỡ lỗi.

[^ref1]: [NOI Linux 2.0 ra mắt, chính thức được đưa vào sử dụng từ ngày 1 tháng 9!](https://www.noi.cn/gynoi/jsgz/2021-07-16/732450.shtml)
