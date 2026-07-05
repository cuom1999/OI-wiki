author: xingjiapeng, MingqiHuang

Geany là một trình soạn thảo nhẹ và tiện lợi, khá thân thiện với người mới trong môi trường Linux.

Giống Dev-C++, nó có thể biên dịch và chạy một tệp đơn lẻ.

Tuy nhiên, nó có thể chạy trên Linux/Windows/macOS.

Trang chủ: <https://geany.org/>

## Ưu và nhược điểm

### Ưu điểm

1.  Nhẹ.
2.  Có thể biên dịch và chạy một tệp đơn lẻ.
3.  Không cần quá nhiều cấu hình.
4.  Đa nền tảng.

### Nhược điểm

1.  Không có quá nhiều người dùng.
2.  Có một số vấn đề quyền hạn trên macOS Catalina[^1].
3.  Khi tạo tệp mới, mặc định không có tô sáng cú pháp; cần tự chuyển loại tệp.

## Cài đặt

Xem [Download | Geany](https://geany.org/download/)

## Mẹo sử dụng

### Chuyển loại tệp

Chuyển trong *Document -> Set Filetype* (*Tài liệu -> Đặt loại tệp*).

Ví dụ với ngôn ngữ C++, nhấp *Document -> Set Filetype -> Programming Languages -> C++ Source File* (*Tài liệu -> Đặt loại tệp -> Ngôn ngữ lập trình -> Tệp nguồn C++*), bạn sẽ thấy tệp đã được chuyển sang tô sáng cú pháp của ngôn ngữ C++.

<span id="đặt-template-tệp"></span>

### Đặt mẫu tệp

Tạo thư mục `templates/files` trong thư mục cấu hình; các tệp đặt trong đó sẽ trở thành mẫu tệp. Sau khi mở lại Geany, bạn có thể tìm thấy chúng trong *File -> New (with Template)*.

Thư mục cấu hình có thể được tìm thấy qua dòng thứ hai và thứ ba trong *Help -> Debug Messages*.

Dưới đây là thư mục cấu hình mẫu mặc định trên macOS và Linux:

-   Thư mục hệ thống: `/usr/share/geany/templates/files/`
-   Thư mục người dùng: `~/.config/geany/templates/files/`[^2]

## Câu hỏi thường gặp

### Tương thích với Deepin Terminal

Trong *Preferences -> Tools -> Virtual Terminal*, sửa lệnh trình dòng lệnh thành:

```bash
deepin-terminal -x "/bin/sh" %c
```

Nhấp nút "Apply" là được.[^3]

## Tài liệu tham khảo và chú thích

[^1]: Xem chi tiết: <https://github.com/geany/geany/issues/2344>

[^2]: Nguồn: <https://wiki.geany.org/config/templates>

[^3]: Nguồn: Deepin Wiki <https://wiki.deepin.org/>
