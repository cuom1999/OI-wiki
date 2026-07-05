author: Ir1d, HeRaNO, NachtgeistW, i-Yirannn, bear-good, ranwen, CoelacanthusHex, billchenchina, Tiger3018, Xeonacid, Cryflmind

## Arbiter

**Arbiter** là công cụ chấm do Đại học Hàng không và Du hành vũ trụ Bắc Kinh phát triển cho NOI Linux, hiện đã được dùng để chấm trong nhiều kỳ thi lập trình thuộc hệ NOI. Theo bài giảng "Hệ thống chấm thế hệ tiếp theo" của Lyu Kaifeng tại trại mùa đông năm 2016, Arbiter được nhóm GAIT của Đại học Hàng không và Du hành vũ trụ Bắc Kinh phát triển dưới sự dẫn dắt của thầy Yin Baolin.

Sau khi NOI Linux được cập nhật lên phiên bản 2.0, Arbiter cũng được biên dịch lại bằng Qt 5.12.8 và phát hành dưới tên Arbiter 2.0. Vì các môi trường chấm sau đó đều dùng NOI Linux 2.0, phần giới thiệu dưới đây dùng phiên bản Arbiter 2.0 đi kèm trong NOI Linux 2.0.

Phần mềm chấm này chỉ có trong NOI Linux. Tệp nhị phân nằm tại `/usr/local/arbiter/local/arbiter_local`.

### Cách dùng

#### Cấu hình chương trình

Cấu hình thư mục mã nguồn của thí sinh và danh sách thí sinh. Thư mục thí sinh được tạo theo định dạng NOIP như sau:

```text
players/
| -- day1
|    | -- <contestant_1's ID>
|    |     | -- <problem_1>
|    |     |   `-- <problem_1>.c/cpp/pas
|    |     | -- <problem_2>
|    |     |   `-- <problem_2>.c/cpp/pas
|    |     | ...
|    |     | -- <problem_x>
|    |        `-- <problem_x>.c/cpp/pas
|    | -- <contestant_2's ID>
|    |     | -- <problem_1>
|    |     ...
|    ...
| -- day2
|    | -- <contestant_1's ID>
|    |     | -- <problem_1>
|    |     |   `-- <problem_1>.c/cpp/pas
|    |     | -- <problem_2>
|    |     |   `-- <problem_2>.c/cpp/pas
|    |     | ...
|    |     | -- <problem_x>
|    |        `-- <problem_x>.c/cpp/pas
|    | -- <contestant_2's ID>
|    |     | -- <problem_1>
|    |     ...
|    ...
...
```

Trong `day<x>`, `<x>` là số hiệu buổi thi; `<contestant_x's ID>` là mã thí sinh, có dạng `<tỉnh>-<số hiệu>`, chẳng hạn HL-001, JL-125, v.v.; `<problem_x>` là tên bài. Khi tự kiểm thử, có thể dùng tổ hợp chữ cái, dấu gạch nối (`-`) và chữ số làm mã thí sinh.

Định dạng danh sách thí sinh như sau:

```text
<contestant_1's ID>,<contestant_1's name>
<contestant_2's ID>,<contestant_2's name>
...
```

Trong đó, `<contestant_x's name>` biểu thị tên thí sinh. Hãy lưu tệp này dưới dạng tệp văn bản thuần hoặc tệp CSV; có thể dùng mã hóa `UTF-8`.

Cũng có thể thêm danh sách thí sinh thủ công sau khi khởi động Arbiter.

Tiếp theo, cấu hình dữ liệu kiểm thử. Định dạng tên của mỗi bộ dữ liệu như sau:

```text
<problem_x><y>.in <problem_x><y>.ans
```

Trong đó, `<y>` là số hiệu dữ liệu, bắt đầu từ 1. Hậu tố mặc định của dữ liệu kiểm thử là `.ans`, còn hậu tố đầu ra của thí sinh là `.out`; không được nhầm lẫn hai loại này.

Nếu cần đổi định dạng `out` đã sinh trước đó thành định dạng `ans`, trong NOI Linux 2.0 có thể dùng lệnh `rename` để đổi hàng loạt, còn trong Windows có thể dùng lệnh `ren`. Phần sau sẽ giới thiệu cách dùng các lệnh này.

Không cần đặt dữ liệu kiểm thử của từng bài trong thư mục riêng của bài đó; chỉ cần đặt chung với nhau là được.

Sau đó bắt đầu cấu hình thư mục chấm.

Ở góc dưới bên trái, chọn "Hiển thị ứng dụng" - "Tất cả" - "Arbiter\_local" để khởi động Arbiter.

![Trang chủ Arbiter](./images/arbiter_home.png)

Nhấn OPEN ("Mở") để mở một kỳ thi đã tạo; sau đó cần chọn tệp `setup.cfg` trong thư mục kỳ thi tương ứng. Nhấn NEW ("Mới") để tạo một kỳ thi mới và đặt tên cùng thư mục kỳ thi. Lưu ý, cần tạo một thư mục trong **thư mục home** của người dùng rồi chọn thư mục đó làm thư mục kỳ thi; nếu tạo thư mục kỳ thi trên desktop thì sẽ không chấm được. Nên tránh dùng ký tự ngoài ASCII trong đường dẫn thư mục kỳ thi, bao gồm cả dấu tiếng Việt, để hạn chế lỗi tương thích.

![Thêm bài trong Arbiter](./images/arbiter_addproblem.png)

Trong phần tổng quan bài ở bên trái, "nhấp chuột phải" - "Thêm kỳ thi", rồi trên nhãn kỳ thi "nhấp chuột phải" - "Thêm bài", là có thể tạo bài mới.

Nhấn mũi tên xuống bên trái kỳ thi để hiển thị toàn bộ. Nhấn nhãn bài để sửa tên bài thành tên tiếng Anh của bài, đồng thời sửa giới hạn thời gian, giới hạn bộ nhớ và cách so sánh. Rất không khuyến nghị dùng cách so sánh "so sánh trực tiếp toàn văn", vì cách này không thân thiện với dữ liệu được tạo trên Windows. Có thể tự chọn trình kiểm tra đáp án theo bài, nhưng cần lưu ý bắt buộc phải chọn một trình kiểm tra đáp án, nếu không kết quả chấm sẽ là `No Score.` (`Không có điểm`).

![Danh sách bài trong Arbiter](./images/arbiter_problem.png)

Nhấn "Tệp" - "Lưu". Không được bỏ qua thao tác này, nếu không chương trình sẽ không sinh tệp cấu hình bài. Lưu ý mỗi lần sửa cấu hình bài đều phải lưu lại.

Lúc này, mở thư mục kỳ thi, ta sẽ thấy các nội dung sau.

```text
<name>/
| -- data
| -- evaldata
| -- filter
| -- final
| -- players
| -- result
| -- tmp
`-- day1.info
`-- player.info
`-- setup.cfg
`-- task1_1.info
`-- task1_2.info
`-- team.info
```

Thư mục `filter` chứa một số trình kiểm tra đáp án; thư mục `result` lưu kết quả chấm của thí sinh; thư mục `tmp` là thư mục bộ nhớ đệm khi chấm. Trong đó, `day<x>.info` là tệp cấu hình buổi thi, `<x>` là số hiệu buổi thi; tệp `task<x>_<y>.info` là tệp cấu hình bài, `<x>` là số hiệu buổi thi, `<y>` là số thứ tự bài.

Đặt thư mục chương trình thí sinh đã tạo vào thư mục `players/`. Lưu ý lớp ngoài cùng nên tạo thư mục `day<x>` tương ứng theo ngày thi. Đặt toàn bộ dữ liệu kiểm thử (không đặt trong thư mục con) vào `evaldata`. Nếu dùng trình kiểm tra đáp án tùy chỉnh, cần đặt trình kiểm tra đáp án tùy chỉnh vào `filter`.

#### Chấm chính thức

Mở thẻ "Chấm bài", sẽ thấy giao diện như sau:

![Giao diện chấm thử trong Arbiter](./images/arbiter_pretest.png)

Nếu đã tạo danh sách thí sinh, chọn trực tiếp "Nhập danh sách" ở bên phải để nhập. Nếu số lượng người ít, có thể chọn "Thêm thí sinh" ở bên phải để nhập.

Sau khi nhập, giao diện như hình sau.

![Giao diện chấm chính thức trong Arbiter](./images/arbiter_test.png)

Trong ví dụ, mã là `HL-001`; chương trình sẽ tự nhận ra cột "Thuộc". Nếu mã không theo chuẩn NOIP thì sẽ không nhận ra được.

Đổi buổi chấm thứ 0 thành buổi chấm thứ 1 (hoặc buổi khác). Sau đó chọn tất cả ở bên phải (hoặc chọn các thí sinh chỉ định), rồi chọn chấm các thí sinh đã chọn ở phía dưới, chọn bài cần chấm (hoặc toàn bộ bài), cuối cùng chờ quá trình chấm kết thúc.

Chi tiết từng bộ kiểm thử cần xem trong thư mục `result`. Trong thư mục này sẽ có thư mục kết quả của thí sinh; tệp kết quả có hậu tố `.result`, có thể mở bằng văn bản thuần. Nếu xuất hiện lỗi `No score file.`, có thể kiểm tra khi chấm có sinh tệp `/tmp/_eval.score` hay không.

### Viết trình kiểm tra đáp án tùy chỉnh

Khi dịch ngược các trình kiểm tra đáp án khác, có thể biết lệnh chạy trình kiểm tra đáp án tùy chỉnh là `<problem>_e <in> <out> <ans>`. Ba tham số sau lần lượt biểu thị đầu vào, đầu ra của thí sinh và tệp đáp án. Kết quả chấm cuối cùng cần được ghi vào tệp `/tmp/_eval.score`: dòng đầu tiên là thông tin chấm, dòng thứ hai là điểm, với 10 điểm là điểm tối đa.

Tên trình kiểm tra đáp án tùy chỉnh sau khi biên dịch bắt buộc phải là `<problem>_e`, trong đó `<problem>` là tên bài. Khi cấu hình bài, chọn trình kiểm tra đáp án tùy chỉnh rồi chọn trình kiểm tra đáp án cần dùng.

Trong phần cấu hình bài của quản lý bài, đổi phương thức nộp từ mã nguồn sang tệp đáp án, rồi chọn trình kiểm tra đáp án tùy chỉnh; cách này có thể kiểm thử bài nộp đáp án.

### Lưu ý

Các điểm đã xác nhận cần chú ý:

-   Cần chú ý lưu kỳ thi kịp thời, nếu không khi thao tác có thể bị thoát đột ngột. Để tránh bị thoát, có thể thử lưu kỳ thi nhiều lần, hoặc lưu ngay sau mỗi lần sửa.
-   Nếu chưa từng chấm, đừng nhấn thống kê điểm ở phía trên, nếu không Arbiter sẽ thoát ngay.
-   Do giới hạn ngăn xếp (stack) khi chạy trên Linux, nếu muốn mở ngăn xếp không giới hạn, nên nhập `ulimit -s unlimited` trong trình dòng lệnh trước rồi chạy `arbiter_local` để mở trình chấm; nếu không có thể gặp vấn đề `Exceeding memory limit` (`Vượt giới hạn bộ nhớ`).
-   Khi chấm chính thức, lúc chuẩn bị đề cần để mọi bài có cùng giới hạn bộ nhớ. Khi chấm, thay `unlimited` trong lệnh bằng số KiB tương ứng với giới hạn bộ nhớ của bài; ví dụ giới hạn bộ nhớ là 512 MiB thì lệnh là `ulimit -s $((512 * 1024))`. Nguyên nhân chính của vấn đề này là khi khởi động Arbiter trực tiếp, tiến trình cha là GNOME, và tiến trình con kế thừa giới hạn ngăn xếp của tiến trình cha.
-   Không khuyến nghị để thư mục làm việc của phần mềm chứa dấu cách. Nếu có dấu cách, rất có thể khi tạo kỳ thi, toàn bộ trình kiểm tra đáp án mặc định không được sao chép vào thư mục `filter` (tức thư mục `filter` rỗng). Khi đó nếu chấm sẽ xuất hiện tình trạng tất cả đều bị 0 điểm, đồng thời trong tệp kết quả sinh ra có thể thấy thông báo `Compile Failed.` (`Biên dịch thất bại.`).
-   Khi xem mã mà hiện thông báo "không tìm thấy tệp đáp án", điều đó nghĩa là không tìm thấy mã nguồn của thí sinh.

Các điểm còn nghi ngờ:

-   Rất dễ treo máy; chẳng hạn khi chấm số lượng lớn, di chuyển chuột có thể gây treo máy.
-   Thỉnh thoảng thoát đột ngột (một phần nguyên nhân là không lưu kỳ thi kịp thời).
-   Sau khi sửa cách so sánh, có xác suất sửa thất bại, tức cách so sánh sau khi sửa không được áp dụng.
-   Khi cấu hình cần chú ý vấn đề quyền, nhưng nếu bảo đảm dùng cùng một người dùng để tạo kỳ thi, sao chép dữ liệu và chấm thì sẽ không xuất hiện vấn đề quyền.

### Lỗ hổng

Do thiếu bảo trì lâu dài, hệ thống tồn tại một số lỗ hổng, chẳng hạn có thể dùng `#pragma G++ optimize("O2")`, `__attribute__((__optimize__("-O2")))`, v.v. Có thể dùng [gcc-plugins-for-oi](https://github.com/xdu-icpc/gcc-plugins-for-oi) để phát hiện các lệnh này trong giai đoạn biên dịch.

### Đánh giá

Sau khi hoàn tất phát triển, Arbiter 1.0.2 gần như không có cập nhật thực chất nào, khiến trải nghiệm chấm rất tệ và giao diện không còn phù hợp với thẩm mỹ hiện đại. Trong NOI Linux 1.4.1, nó cùng với GUIDE đi kèm NOI Linux trở thành đối tượng bị thí sinh và huấn luyện viên phàn nàn rất nhiều. Trong NOI Linux 2.0, ngoài việc trình kiểm tra đáp án bị loại bỏ mã nguồn và toàn bộ phần mềm được biên dịch lại bằng Qt 5, không có nhiều thay đổi lớn; một số vấn đề ổn định vẫn chưa được giải quyết.

??? note "Phụ lục: cách dùng lệnh ren và rename"
    Trong hệ điều hành Windows có sẵn một lệnh đổi tên tệp: `ren`.
    
    Cú pháp lệnh như sau:
    
    ```shell
    ren [<drive>:][<path>]<filename1> <filename2>
    ```
    
    Nếu cần đổi toàn bộ tệp trong thư mục làm việc hiện tại, chẳng hạn đổi tất cả tệp `out` thành tệp `ans`, có thể chạy lệnh sau:
    
    ```shell
    ren *.out *.ans
    ```
    
    Nếu thực hiện thao tác này trong môi trường NOI Linux 2.0, hiện có vẻ lệnh `rename` là lựa chọn tương đối dễ dùng, nhưng nó không được cài sẵn trong NOI Linux 2.0, nên cần cài đặt trước:
    
    ```shell
    sudo apt install rename
    ```
    
    Ghi chú: nếu sau khi chạy xuất hiện thông báo `E: Unable to locate package package_name`, bạn cần chạy lệnh này trước: `sudo apt-get update`.
    
    Sau khi cài đặt xong, có thể dùng `rename` bình thường. Cách dùng `rename` tương tự thay thế văn bản trực tiếp; cú pháp trong môi trường NOI Linux 2.0 như sau:
    
    ```shell
    rename 's/<text-before>/<text-after>/' <filename>
    ```
    
    Trong đó, `<filename>` có thể dùng ký tự đại diện `*`, hoặc chỉ định một loại tệp nhất định (ví dụ `*.out`).
    
    Lưu ý trong dấu nháy còn có một dấu `/` ở cuối. Nếu thiếu dấu `/`, lệnh `rename` sẽ báo lỗi: `Substitution replacement not terminated at (user-supplied code)`.
    
    Lúc này, nếu cần đổi toàn bộ tệp trong thư mục làm việc hiện tại, chẳng hạn đổi tất cả tệp `out` thành tệp `ans`, có thể viết như sau:
    
    ```shell
    rename 's/\.out/\.ans/' *
    ```
    
    Trong đó, `\.` biểu thị escape ký tự `.`.
    
    Gợi ý: nếu thiếu `\.`, giả sử trong tệp của bạn có một tệp tên `outtest.out`, sau khi chạy lệnh này, tệp đó sẽ bị đổi thành `anstest.out`.
    
    Tương tự, nếu bạn cần đổi đồng loạt tất cả tệp tên `atmost<x>.ans` (trong đó `<x>` biểu thị số hiệu bộ kiểm thử) thành `test<x>.ans`, có thể viết như sau:
    
    ```shell
    rename 's/atmost/test/' *.ans
    ```
