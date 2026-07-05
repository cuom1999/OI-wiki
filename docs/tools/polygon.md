author: ouuan, NachtgeistW

Trang này giới thiệu ngắn gọn nền tảng ra đề cộng tác nhiều người Polygon.

## Giới thiệu

### Polygon là gì

Trang web: [Index Page - Polygon](https://polygon.codeforces.com)

Polygon là một nền tảng ra đề hỗ trợ nhiều người cộng tác, với hệ thống chức năng rất hoàn chỉnh. Mô tả trên trang chính thức là: "Sứ mệnh của Polygon là cung cấp một nền tảng để tạo bài toán cho các cuộc thi lập trình."

Khi ra đề trên Codeforces (CF), bắt buộc phải dùng Polygon. Khi ra đề ở nơi khác, đặc biệt là khi nhiều người cùng cộng tác, Polygon cũng là một lựa chọn tốt.

### Ưu điểm

-   Có hệ thống quản lý phiên bản; khi nhiều người cùng làm sẽ không rối, và cũng không cần truyền tệp qua lại.

-   Hệ thống ra đề hoàn chỉnh; trình kiểm tra dữ liệu, trình sinh dữ liệu, trình kiểm tra đáp án và lời giải liên kết chặt chẽ với nhau, đầu ra được tự động sinh.

-   Có thể đặt nhãn cho lời giải; nếu lời giải sai AC hoặc lời giải đúng không AC thì hệ thống đều cảnh báo, thuận tiện để lần lượt chặn các lời giải sai.

-   Có thể kiểm thử stress rất thuận tiện; dữ liệu tìm được khi kiểm thử stress có thể thêm trực tiếp vào dữ liệu của bài.

-   Khi phát hiện vấn đề có thể tạo issue, tránh việc bị tin nhắn trôi mất mà vẫn không có fix.

-   Chuẩn bị cho việc ra đề CF trong tương lai.

-   ...

## Danh sách bài

Danh sách bài sẽ hiển thị thông tin cơ bản của một bài, chẳng hạn tình trạng viết đề bài, hướng dẫn, tình trạng sinh dữ liệu, cũng như thiết lập của lời giải chuẩn, trình kiểm tra dữ liệu và trình kiểm tra đáp án.

Có thể nhấp đúp vào cột "Name" ("Tên") trong danh sách bài để ghi chú, ví dụ những việc cần tự nhắc (cần thêm test/cần viết hướng dẫn), hoặc phân bố điểm dự kiến của bài. Có thể điền tùy nhu cầu, và dĩ nhiên cũng có thể để trống.

Trong "Rev." ("Phiên bản"), "x/y" nghĩa là x là phiên bản hiện tại của bài, còn y là phiên bản gói. Nếu hai số khác nhau, y sẽ hiển thị màu đỏ.

Trong "Edit session" ("Phiên chỉnh sửa"), "Start" ("Bắt đầu") nghĩa là tài khoản của bạn chưa từng xem bài này; "Continue (x) Discard" ("Tiếp tục (x) / Hủy bỏ") nghĩa là tài khoản của bạn đang ở phiên bản thứ x của bài này. Nhấp "Start" hoặc "Continue (x)" sẽ đi vào giao diện quản lý bài; nhấp "Discard" ("Hủy bỏ") sẽ hủy **không thể khôi phục** toàn bộ thay đổi của bạn và trở về trạng thái như chưa từng xem bài.

Nếu tài khoản của bạn có thay đổi chưa commit trong một bài, cả hàng tương ứng trong danh sách bài sẽ chuyển sang màu đỏ.

## Quản lý bài

Phần lớn chức năng của Polygon không cần học riêng; đọc hiểu tiếng Anh là về cơ bản dùng được.

???+ warning "Cảnh báo"
    Đề bài không thể dùng Markdown, chỉ có thể dùng TeX.

-   Invocation dùng để kiểm thử lời giải.

-   Stress dùng để kiểm thử stress.

-   Dữ liệu được tạo bằng trình sinh dữ liệu trong Tests; trình sinh dữ liệu được tải lên trong Files.

### Thông tin chung

Trong trang này, có thể thiết lập giới hạn thời gian, giới hạn bộ nhớ, loại bài, thẻ của bài và cuộc thi chứa bài.

Ở cuối trang, "statement sketch" ("bản nháp đề bài") và "tutorial sketch" ("bản nháp hướng dẫn") cho phép chỉnh sửa **bản nháp** của đề bài và hướng dẫn. Chú ý rằng hai mục này sẽ không xuất hiện trong đề bài và hướng dẫn chính thức.

### Đề bài và hướng dẫn

Trang này dùng để viết đề bài và hướng dẫn. Cũng có thể dùng nút "Review" để xem đề bài, trình kiểm tra dữ liệu và trình kiểm tra đáp án, thường dùng cho việc rà soát.

Đề bài và hướng dẫn đều cần dùng cú pháp TeX, không thể dùng Markdown. Ví dụ, cần dùng `\textbf{text}` thay vì `**text**`. Tuy vậy, phần TeX mà Polygon hỗ trợ thực ra chỉ là một tập con rất nhỏ; có thể tự thử cụ thể.

Có thể dùng liên kết "In HTML" ("Dạng HTML") ở phía trên cùng để xem đề bài sau khi dựng HTML, và dùng "Tutorial in HTML" ("Hướng dẫn dạng HTML") để xem hướng dẫn sau khi dựng HTML.

Nếu cần thêm ảnh vào đề bài, trước hết cần tải ảnh lên trong "Statement Resource Files" ("Tệp tài nguyên của đề bài") bên dưới, rồi thêm `\includegraphics{filename.png}` vào đề bài.

### Tệp

"Source Files" ("Tệp nguồn") dùng để lưu các mã nguồn **ngoại trừ lời giải**, chẳng hạn trình kiểm tra dữ liệu, trình kiểm tra đáp án, trình sinh dữ liệu, và nếu là bài tương tác kiểu IO thì còn có trình tương tác.

Nếu các mã nguồn này cần include tệp khác, ví dụ [Tree-Generator](https://github.com/ouuan/Tree-Generator), thì cần đặt chúng trong "Resource Files" ("Tệp tài nguyên").

Tương tác kiểu grader xem [hướng dẫn chính thức](https://codeforces.com/blog/entry/66916).

### Trình kiểm tra đáp án (Checker)

testlib.h cung cấp một số trình kiểm tra đáp án tích hợp sẵn; trong hộp chọn có giới thiệu ngắn gọn, và sau khi chọn cũng có thể nhấp "View source" (xem mã nguồn).

Nếu cần tự viết trình kiểm tra đáp án, hãy tham khảo [hướng dẫn viết trình kiểm tra đáp án](./testlib/checker.md).

"Checker tests" ("Test cho checker") bên dưới dùng "Add test" ("Thêm test") để thêm nhiều nhóm đầu ra cùng kết quả chấm mong muốn tương ứng; sau đó nhấp "Run tests" ("Chạy test") để kiểm tra trình kiểm tra đáp án có trả về đúng kết quả chấm hay không.

### Trình tương tác (Interactor)

Chỉ bài tương tác kiểu IO mới cần mục này; hãy tham khảo [hướng dẫn viết trình tương tác](./testlib/interactor.md).

### Trình kiểm tra dữ liệu (Validator)

Trình kiểm tra dữ liệu dùng để kiểm tra tính hợp lệ của dữ liệu. Cách viết xem [hướng dẫn viết trình kiểm tra dữ liệu](./testlib/validator.md).

"Validator tests" bên dưới tương tự "Checker tests"; cần cung cấp đầu vào và kỳ vọng hợp lệ hay không, dùng để kiểm thử trình kiểm tra dữ liệu.

### Dữ liệu kiểm thử

Trang này dùng để quản lý dữ liệu.

Trên Polygon, cách làm được khuyến nghị là dùng một số ít [trình sinh dữ liệu](./testlib/generator.md) **có tham số dòng lệnh** để sinh dữ liệu, thay vì viết nhiều trình sinh dữ liệu hoặc mỗi lần sinh một bộ dữ liệu lại sửa trình sinh dữ liệu. Ngoài ra, chỉ cần sinh đầu vào; đầu ra sẽ được sinh tự động.

"Testset" là một tập kiểm thử. Nếu ra đề cho CF, cần tự thêm Testset tên "pretests", và "pretests" cần là tập con của "tests".

"Add Test" ("Thêm test") dùng để thêm thủ công một bộ dữ liệu, thường dùng để nhập tay mẫu hoặc dữ liệu nhỏ. Dù có thể tải tệp dữ liệu lên, cách này **không được khuyến nghị**; dữ liệu nên hoặc được nhập thủ công, hoặc được sinh bằng trình sinh dữ liệu với một bộ tham số nào đó.

Nếu chọn "Use in statements" (dùng trong đề bài), bộ dữ liệu này sẽ trở thành mẫu và được tự động thêm vào đề bài. Nếu cần nội dung hiển thị trong đề bài không phải đầu vào/đầu ra của mẫu (thường dùng cho bài tương tác), có thể nhấp "If you want to specify custom content of input or output data for statements click here" (nếu muốn chỉ định nội dung đầu vào hoặc đầu ra tùy chỉnh cho đề bài, hãy nhấp vào đây), rồi nhập đầu vào/đầu ra muốn hiển thị trong đề bài.

Phần dưới của trang Tests dùng để nhập kịch bản sinh dữ liệu, ví dụ `generator-name [params] > test-index`. Có thể dùng `generator-name [params] > $` để không phải chỉ định thủ công số thứ tự test.

Có thể tham khảo [hướng dẫn do Polygon cung cấp](https://polygon.codeforces.com/docs/freemarker-manual) để dùng Freemarker sinh script hàng loạt.

"Preview Tests" ("Xem trước test") có thể xem trước dữ liệu được sinh.

### Kiểm thử stress

Trang này dùng để kiểm thử stress.

Nhấp "Add Stress" ("Thêm stress") để thêm một bộ kiểm thử stress. "Script pattern" ("Mẫu script") là script sinh dữ liệu, trong đó có thể dùng dạng như "\[10..100]" để biểu thị chọn ngẫu nhiên trong một khoảng.

Sau đó chạy kiểm thử stress; nếu tìm được lỗi, hệ thống sẽ hiển thị "Crashed" ("Bị lỗi"), và có thể thêm bộ dữ liệu đó vào Tests bằng một lần nhấp.

### Tệp lời giải

Trang này dùng để đặt mã nguồn lời giải của bài, có thể là lời giải đúng hoặc lời giải sai. Tải lời giải sai lên giúp chặn chúng thuận tiện hơn, và cũng có thể nhắc chính mình rằng cần chặn các lời giải đó.

### Lượt chạy kiểm thử

Trang này dùng để chạy lời giải.

Chọn mã nguồn và test rồi chạy; sau đó có thể nhấp vào mục trong danh sách ("View") để xem thông tin chi tiết.

Trạng thái chấm "FL" nghĩa là chấm bị lỗi, thường là dữ liệu không qua xác thực hoặc trình kiểm tra dữ liệu/trình kiểm tra đáp án/trình tương tác bị RE. "RJ" có hai trường hợp: một là đã xuất hiện "FL", hai là mã nguồn này không qua ngay test đầu tiên.

Nếu thời gian chạy nằm trong khoảng từ một nửa đến hai lần giới hạn thời gian, nó sẽ được đánh dấu màu vàng.

Nếu trong dữ liệu có biến chưa đạt giá trị nhỏ nhất hoặc lớn nhất, phía dưới cùng sẽ nhắc.

### Vấn đề

Nơi dùng để tạo Issue.

### Gói xuất bản

Gói chứa toàn bộ thông tin của một bài. Khi ra đề CF, gói là căn cứ để CF chấm (ví dụ, nếu cần sửa lỗi trong lúc thi, chỉ khi cập nhật gói thì mới ảnh hưởng đến CF); những lúc khác có thể dùng để xuất ra.

"Verify" (xác minh) dùng để kiểm tra tất cả lời giải có phù hợp với thẻ (AC, WA, TLE) hay không, đồng thời trình kiểm tra đáp án và trình kiểm tra dữ liệu có qua bộ kiểm thử tương ứng hay không.

### Quản lý quyền truy cập

Quản lý quyền truy cập của bài.

### Thanh bên

Cột đầu tiên sẽ hiển thị một số thông tin cơ bản. Nếu có chỗ nào không đúng quy chuẩn (ví dụ tests không chứa pretests, hoặc có test bị trùng), nó sẽ hiển thị màu vàng; đưa chuột lên đó sẽ thấy thông tin cụ thể.

"View changes" dùng để xem lịch sử thay đổi. Cần chú ý rằng "switch" không dùng để quay lại một phiên bản nào đó; nó chỉ có thể thực hiện sửa đổi không sinh xung đột trên cơ sở một phiên bản nào đó, điều này thực ra không có ý nghĩa, nên switch tương đương chỉ đọc.

"Update Working Copy" (cập nhật bản làm việc) dùng để lấy cập nhật của người khác.

"Commit Changes" dùng để commit cập nhật của bạn.

Khi commit, nếu có chỗ không đúng quy chuẩn hoặc cần cảnh báo, chúng sẽ được liệt kê ra.

## Quản lý cuộc thi

Nếu muốn ra một cuộc thi, có thể tạo bằng "New Contest", từ đó quản lý bài thuận tiện hơn.

"Add problems?" (thêm bài?) ở góc trên bên phải của danh sách bài trong trang quản lý cuộc thi dùng để thêm một bài đã có vào cuộc thi.

"New problem" (bài mới) ở thanh bên dùng để tạo một bài mới rồi thêm vào cuộc thi.

"Manage problem access" (quản lý quyền truy cập bài) ở phía trên dùng để xem quyền của từng bài; "Manage developers list" (quản lý danh sách người phát triển) ở phía dưới dùng để quản lý những người có quyền trong cuộc thi này. Khi tạo bài bằng "New problem" và khi thêm người phát triển mới, quyền sẽ được tự động thêm; nhưng bài thêm vào bằng "Add problems?" sẽ không cấp quyền cho người phát triển đã có.

Thanh bên còn có thể xem trước toàn bộ đề bài, toàn bộ hướng dẫn, toàn bộ trình kiểm tra dữ liệu và trình kiểm tra đáp án, tải gói của cả cuộc thi và đánh số lại các bài.

## Giải quyết xung đột

Khi nhiều người cùng dùng Polygon để ra đề, nếu phiên bản bài đang sửa khác với phiên bản bài ở remote, và khi lấy phiên bản mới nhất từ remote hoặc commit cập nhật mà tệp đã sửa không thể tự động merge, xung đột (Conflicted) sẽ xảy ra.

Sau khi xảy ra xung đột, Polygon sẽ cung cấp tùy chọn "Resolve conflicts" trong các tùy chọn của bài bị xung đột; người dùng có thể vào đó để giải quyết xung đột trên các tệp bị xung đột.
