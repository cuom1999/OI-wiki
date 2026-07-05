author: zarttic, xk2013

## Giới thiệu

[CP Editor](https://github.com/cpeditor/cpeditor) được thiết kế riêng cho thi đấu thuật toán, không giống các IDE khác chủ yếu được thiết kế cho phát triển phần mềm. Nó có thể giúp bạn tự động hóa việc biên dịch, chạy và kiểm thử, để bạn tập trung vào thiết kế thuật toán. Nó thậm chí có thể lấy sample từ nhiều website thi đấu thuật toán và nộp mã lên [Codeforces](https://codeforces.com/)!

## Tải xuống và cài đặt

Xem [Installation | CP Editor](https://cpeditor.org/docs/installation/).

## Cấu hình cơ bản

> CP Editor không tích hợp sẵn trình biên dịch bên trong; bạn cần tự cài đặt và cấu hình trình biên dịch. Nếu cần, hãy tham khảo bài liên quan đến cài đặt trình biên dịch trên trang này[^compiler]. Dĩ nhiên, nếu khi tải xuống bạn chọn gói cài đặt có hậu tố `with-gcc-<số phiên bản GCC>-llvm-<số phiên bản LLVM>`, bạn có thể dùng trình biên dịch đi kèm CP Editor, nằm tại `{thư mục cài đặt}/mingw64/bin/`.

-   Đặt ngôn ngữ mặc định

    Ngôn ngữ mặc định của trình soạn thảo là `C++`.

    ![cp-setting-lang-1](images/cp-setting-lang-1.png)

    ![cp-setting-lang-2](images/cp-setting-lang-2.png)

-   Đặt lệnh `C++`

    Cần đặt một số lệnh biên dịch cần thiết; phần này phải cấu hình theo trình biên dịch đang dùng.

    ![cp-setting-lang-3](images/cp-setting-lang-3.png)

-   Đặt mẫu

    Mẫu sẽ tự động khởi tạo khi tạo tệp mới. Cần chú ý rằng CP Editor cần một tệp `xxx.cpp` làm mẫu tệp.

    ![cp-setting-lang-4](images/cp-setting-lang-4.png)

> Sau khi hoàn thành các thao tác cơ bản trên, bạn đã có thể dùng các chức năng cơ bản nhất.

## Chức năng cơ bản

-   Phím tắt

    |                       Lệnh                       |          Thao tác          |
    | :----------------------------------------------: | :------------------------: |
    | <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>C</kbd>    |         Biên dịch          |
    | <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>R</kbd>    |     Biên dịch và chạy      |
    |          <kbd>Ctrl</kbd>+<kbd>R</kbd>            |            Chạy            |
    |  <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>D</kbd>     | Chạy trong trình dòng lệnh |
    |          <kbd>Ctrl</kbd>+<kbd>K</kbd>            | Dừng toàn bộ tiến trình    |
    | <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>I</kbd>    |       Định dạng mã         |

    Chi tiết có thể xem trong [tài liệu chính thức](https://cpeditor.org/docs/preferences/key-bindings/).

-   Kiểm thử sample

    Có thể sao chép sample trong statement để CP Editor tự động chấm, và còn có thể đặt giới hạn thời gian!

    ![cp-setting-limits](images/cp-setting-limits.png)

    ![cp-judge-1](images/cp-judge-1.png)

    ![cp-judge-2](images/cp-judge-2.png)

    ![cp-judge-3](images/cp-judge-3.png)

    ![cp-judge-4](images/cp-judge-4.png)

## Tài liệu tham khảo

[^compiler]: [Trình biên dịch - OI Wiki](../compiler.md)
