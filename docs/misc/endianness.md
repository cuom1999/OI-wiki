Trang này giới thiệu ngắn gọn khái niệm và phân loại thứ tự byte.

## Giới thiệu

Thứ tự byte là quy tắc lưu trữ đối với các đối tượng chương trình chiếm nhiều byte, thể hiện cách sắp xếp các byte của một đối tượng.

## Phân loại

Thứ tự byte có hai loại: little endian và big endian.

Để tiện trình bày, xét một biến kiểu `int` nằm tại địa chỉ `0x100`, có giá trị thập lục phân là `0x01234567`. Trong đó `0x01` là byte có trọng số cao nhất, còn `0x67` là byte có trọng số thấp nhất.

### Little endian

Little endian nghĩa là máy lưu đối tượng trong bộ nhớ theo thứ tự từ byte có trọng số **thấp nhất** đến byte có trọng số **cao nhất**.

Biến ở trên được biểu diễn như sau:

| .... | 0x100 | 0x101 | 0x102 | 0x103 | .... |
| ---- | ----- | ----- | ----- | ----- | ---- |
| .... | 67    | 45    | 23    | 01    | .... |

### Big endian

Big endian nghĩa là máy lưu đối tượng trong bộ nhớ theo thứ tự từ byte có trọng số **cao nhất** đến byte có trọng số **thấp nhất**.

Biến ở trên được biểu diễn như sau:

| .... | 0x100 | 0x101 | 0x102 | 0x103 | .... |
| ---- | ----- | ----- | ----- | ----- | ---- |
| .... | 01    | 23    | 45    | 67    | .... |

### Khác biệt giữa hai thứ tự

Thực ra, không có thứ tự byte nào tốt hơn thứ tự còn lại. Tên gọi "little endian" và "big endian" bắt nguồn từ tác phẩm *Gulliver's Travels*. Trong truyện, hai phe ở xứ Lilliput giao chiến không ngừng vì không thống nhất được nên đập trứng từ đầu nhỏ hay đầu to. Tương tự cuộc tranh luận về cách đập trứng, việc chọn thứ tự byte nào không phải là một vấn đề kỹ thuật.

Dĩ nhiên, nếu thứ tự byte không thống nhất, dữ liệu nhị phân có thể bị đảo thứ tự khi truyền giữa các loại máy khác nhau. Để tránh điều này, các ứng dụng mạng thiết lập một bộ chuẩn nhằm bảo đảm quá trình truyền dùng chuẩn mạng đã quy ước, thay vì biểu diễn nội bộ của từng máy.

## Quy ước thường gặp

-   Little endian: x86, ARM processors running Android, iOS, and Windows

-   Big endian: Sun, PPC Mac, Internet
