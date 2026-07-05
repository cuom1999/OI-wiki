Trang này giới thiệu một số công cụ OJ.

## cf-tool

cf-tool là một công cụ dòng lệnh đa nền tảng cho Codeforces (hỗ trợ Windows, Linux, macOS), hỗ trợ nhiều thao tác thường dùng.

Mã nguồn được lưu trữ tại [xalanq/cf-tool](https://github.com/xalanq/cf-tool).

![Ảnh chụp màn hình sử dụng cf-tool 1](./images/oj-tool-1.jpg)

![Ảnh chụp màn hình sử dụng cf-tool 2](./images/oj-tool-2.jpg)

### Tính năng

-   Hỗ trợ mọi ngôn ngữ lập trình trên Codeforces.
-   Hỗ trợ Contests và Gym.
-   Nộp mã.
-   Làm mới động trạng thái sau khi nộp.
-   Tải mẫu của bài.
-   Biên dịch cục bộ và kiểm thử mẫu.
-   Tải toàn bộ mã của một người.
-   Sinh mã từ mẫu chỉ định (bao gồm dấu thời gian, tác giả và các thông tin khác).
-   Liệt kê thông tin tổng quát của tất cả bài trong một cuộc thi.
-   Mở trang bài, bảng xếp hạng, trang nộp bài, v.v. bằng trình duyệt mặc định.
-   Giao diện dòng lệnh nhiều màu sắc.

### Tải xuống

Truy cập [cf-tool/releases](https://github.com/xalanq/cf-tool/releases) để tải phiên bản mới nhất.

Các bản cập nhật sau đó có thể được lấy trực tiếp bằng lệnh `upgrade`.

### Cách dùng

Sau khi đặt tệp thực thi đã tải `cf` (hoặc `cf.exe`) vào vị trí phù hợp (xem câu hỏi thường gặp thứ hai), mở dòng lệnh và dùng lệnh `cf config` để cấu hình tên người dùng, mật khẩu và mẫu mã.

### Ví dụ sử dụng

Dưới đây là một mô phỏng đơn giản về quy trình tham gia một cuộc thi.

`cf race 1136`

Bắt đầu tham gia contest 1136. Trong đó, 1136 có thể lấy từ liên kết của cuộc thi; ví dụ liên kết cuộc thi trong ví dụ này là <https://codeforces.com/contest/1136>.

Nếu cuộc thi chưa bắt đầu, lệnh này sẽ đếm ngược. Khi cuộc thi đã bắt đầu hoặc đếm ngược kết thúc, công cụ sẽ tự động mở trang của tất cả bài bằng trình duyệt mặc định và tải mẫu về cục bộ.

`cd 1136/a`

Đi vào thư mục của bài A; lúc này thư mục đó sẽ chứa mẫu của bài.

`cf gen`

Sinh một tệp mã bằng mẫu mặc định; ở đây giả sử đặt là `a.cpp`.

`vim a.cpp`

Viết mã bằng Vim (hoặc bằng trình soạn thảo/IDE khác).

`cf test`

Biên dịch và kiểm thử mẫu.

`cf submit`

Nộp mã.

`cf list`

Xem thông tin của từng bài trong cuộc thi hiện tại.

`cf stand`

Mở bảng xếp hạng bằng trình duyệt để xem thứ hạng.

### Câu hỏi thường gặp

1.  Tôi nhấp đúp vào chương trình này nhưng không thấy gì xảy ra

    cf-tool là công cụ giao diện dòng lệnh; bạn nên chạy công cụ này trong trình dòng lệnh.

2.  Tôi không thể dùng lệnh `cf`

    Bạn nên đặt chương trình `cf` vào một đường dẫn đã được thêm vào biến hệ thống PATH (ví dụ `/usr/bin/` trên Linux).

    Nếu chưa rõ, hãy tìm kiếm trực tiếp "thêm đường dẫn vào PATH".

3.  Cách thêm một dữ liệu test mới

    Tạo thêm hai tệp dữ liệu test `inK.txt` và `ansK.txt` (K là một chuỗi gồm các chữ số 0\~9).

4.  Cách bật hoàn thành bằng tab trong trình dòng lệnh

    Có thể dùng công cụ [Infinidat/infi.docopt\_completion](https://github.com/Infinidat/infi.docopt_completion).

    Lưu ý: nếu có phiên bản mới được phát hành (đặc biệt là khi thêm lệnh mới), bạn nên chạy lại `docopt-completion cf`.

## Codeforces Visualizer

Trang chủ: [Codeforces Visualizer](https://cfviz.netlify.app)

Mã nguồn được lưu trữ tại [sjsakib/cfviz](https://github.com/sjsakib/cfviz/).

Trang web này có ba chức năng:

-   Dùng biểu đồ đẹp mắt để trực quan hóa nhiều thông tin của một người dùng (chẳng hạn phân bố độ khó của bài đã giải).
-   So sánh hai người dùng.
-   Tính dự đoán Rating cho một cuộc thi.

## Competitive Companion

Công cụ này là một tiện ích trình duyệt dùng để phân tích dữ liệu mẫu trên trang web. Nó hỗ trợ phân tích gần như mọi nền tảng OJ phổ biến (chẳng hạn Codeforces, AtCoder). Sau khi dùng tiện ích này, bạn không cần sao chép thủ công bất kỳ dữ liệu mẫu nào nữa.

Mã nguồn được lưu trữ tại [jmerle/competitive-companion](https://github.com/jmerle/competitive-companion).

Cách dùng:

-   Cài tiện ích trên trình duyệt Chrome hoặc Firefox. Công cụ này sẽ gửi dữ liệu mẫu đã phân tích ở dạng JSON tới một cổng chỉ định.
-   Cài cục bộ bất kỳ công cụ nào có thể lắng nghe và đọc dữ liệu từ cổng đó; có thể tham khảo [ví dụ chính thức](https://github.com/jmerle/competitive-companion-example).

Minh họa bằng hình ảnh:

![Minh họa sử dụng Competitive Companion](images/oj-tool-3.apng)

Phần minh họa được thực hiện bằng [bytetools](https://github.com/zqxyz73/bytetools) của bạn [zqxyz73](https://github.com/zqxyz73).

## ac-predictor

ac-predictor là một tiện ích giúp biết trước thay đổi rating của cuộc thi trước khi rating AtCoder được cập nhật.

Công cụ này là một script Tampermonkey, vì vậy trước hết bạn cần cài [Tampermonkey](https://www.tampermonkey.net/).

Sau đó vào [Greasy Fork](https://greasyfork.org/en/scripts/369954-ac-predictor) và nhấn cài đặt.

Sau khi cài đặt xong, giao diện bảng xếp hạng của cuộc thi sẽ hiển thị dự đoán thay đổi rating của từng người dùng.

Nếu trang script có nhiều phiên bản, nên ưu tiên bản gốc hoặc bản đang được duy trì thường xuyên.
