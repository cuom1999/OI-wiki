author: Xeonacid, sshwy

Nếu bạn đang dùng C++ để chuẩn bị một bài thi lập trình, Testlib là công cụ hỗ trợ rất tốt để viết các chương trình liên quan như trình sinh dữ liệu (generator), trình xác thực dữ liệu (validator), trình kiểm tra đáp án (checker) và trình tương tác (interactor). Đây là công cụ gần như bắt buộc với nhiều người ra đề ở Nga và một số quốc gia khác; nhiều kỳ thi cũng sử dụng Testlib, chẳng hạn ROI, các vòng ICPC khu vực và toàn bộ các vòng Codeforces.

Thư viện Testlib chỉ gồm một tệp `testlib.h`. Khi sử dụng, bạn chỉ cần thêm `#include "testlib.h"` ở đầu chương trình đang viết.

Các mục đích sử dụng cụ thể của Testlib:

-   Viết [trình sinh dữ liệu (generator)](./generator.md).
-   Viết [trình xác thực dữ liệu (validator)](./validator.md), dùng để xác định dữ liệu sinh ra có thỏa yêu cầu của đề hay không, chẳng hạn miền giá trị và định dạng.
-   Viết [trình tương tác (interactor)](./interactor.md) cho bài tương tác.
-   Viết [trình kiểm tra đáp án (checker)](./checker.md), tức [trình chấm đặc biệt (Special Judge)](../special-judge.md).

Testlib hoàn toàn tương thích với nền tảng ra đề [Polygon](https://polygon.codeforces.com/) do Codeforces phát triển.

`testlib.h` được chuyển từ `testlib.pas` vào năm 2005 và vẫn được cập nhật liên tục. Testlib tương thích với phần lớn trình biên dịch, chẳng hạn VC++ và GCC g++, đồng thời tương thích với C++11.

**Bài viết này chủ yếu được dịch từ [Testlib - Codeforces](https://codeforces.com/testlib). Kho GitHub của `testlib.h` là [MikeMirzayanov/testlib](https://github.com/MikeMirzayanov/testlib).**
