author: Ir1d, Planet6174, abc1763613206, StudyingFather, cjsoft, Marcythm, luoguyuntianming, ChungZH, Xeonacid, YZircon, i-Yirannn, H-J-Granger, NachtgeistW, YuzhenQin, Andycode3759, HHH2309, shigengxin123456, Re-Ori, hcx1204

## Giới thiệu cuộc thi

**Olympic Tin học** (tiếng Anh: Olympiad in Informatics, viết tắt: OI) là một cuộc thi học thuật được tổ chức rộng rãi trong học sinh trung học, có tính chất tương tự các kỳ thi Olympic Vật lý, Toán học, v.v. Nội dung OI đánh giá năng lực của thí sinh trong việc vận dụng thuật toán, cấu trúc dữ liệu và kiến thức toán học để viết chương trình máy tính giải quyết các bài toán thực tế.

Các loại cuộc thi OI rất đa dạng; chỉ riêng Trung Quốc đã có:

-   National Olympiad in Informatics in Provinces (NOIP)
-   National Olympiad in Informatics (NOI)
-   Winter Camp (WC)
-   China Team Selection Competition (CTSC)

Các cuộc thi OI quốc tế bao gồm:

-   International Olympiad in Informatics (IOI)
-   USA Computing Olympiad (USACO)
-   Japanese Olympiad in Informatics (JOI)
-   Asia-Pacific Informatics Olympiad (APIO)

    ……

Với phần lớn thí sinh, mùa thi mới hằng năm bắt đầu từ vòng đầu tiên CSP-J/S vào tháng 9.

Ở Trung Quốc, ngôn ngữ được phép dùng trong các cuộc thi OI chỉ có C++ (trước đây từng mở cho C và Pascal, nhưng đều đã ngừng hỗ trợ). Trong đó, các cuộc thi khác nhau có quy định khác nhau về phiên bản C++. Đề thi thường liên quan đến thuật toán hoặc cấu trúc dữ liệu; hình thức bài gồm bài truyền thống (phổ biến nhất là bài quy định nhập và xuất qua tệp) và bài phi truyền thống (bài nộp đáp án, bài tương tác, bài điền hoàn chỉnh mã nguồn, v.v.).

## Giới thiệu thể thức

### Thể thức OI

Thí sinh chỉ có một cơ hội nộp bài. Trong lúc thi không thể xem kết quả chấm; điểm số sẽ được công bố sau cuộc thi. Mỗi bài có nhiều điểm kiểm thử (test point), và điểm tương ứng được tính theo số điểm kiểm thử mà lời giải vượt qua; mỗi điểm kiểm thử cũng có thể có điểm thành phần, nên ngay cả khi chỉ qua một phần dữ liệu vẫn có thể nhận điểm.

???+ note "Công cụ tự chấm selfEval"
    Hiện nay, trong một số cuộc thi thuộc hệ thống NOI, công cụ tự chấm selfEval được cung cấp. selfEval được tích hợp trong bản NOI Linux tùy chỉnh cho các kỳ thi toàn quốc. Sau khi được công bố chính thức và đưa vào sử dụng từ NOI2023, selfEval lần lượt được dùng trong các kỳ NOI toàn quốc, APIO (khu vực Trung Quốc), NOI Winter Camp, v.v. Thí sinh có thể dùng selfEval để kiểm thử chương trình của mình trên một bộ dữ liệu kiểm thử sơ bộ (pretest) và nhận phản hồi. Số lần tự kiểm thử của thí sinh trong mỗi buổi thi có giới hạn cụ thể (NOI2024 giới hạn 50 lần tự kiểm thử, NOI2025 giới hạn 30 lần tự kiểm thử), và dữ liệu kiểm thử sơ bộ cũng không hiển thị cho thí sinh. Vì dữ liệu kiểm thử sơ bộ khác với dữ liệu chấm chính thức, kết quả tự kiểm thử chỉ dùng cho việc gỡ lỗi, không thể xem là điểm chấm chính thức. Nếu thí sinh tự kiểm thử nhiều lần trên cùng một bài, bộ dữ liệu kiểm thử sơ bộ được sử dụng là như nhau.

CSP-J/S vòng hai, NOIP, vòng tuyển chọn cấp tỉnh và NOI đều dùng thể thức OI.

### Thể thức IOI

Thí sinh có nhiều cơ hội nộp bài trong lúc thi. Bài nộp được chấm theo thời gian thực và trả về kết quả; nếu kết quả nộp sai thì không có hình phạt nào. Mỗi bài có nhiều điểm kiểm thử, và điểm tương ứng được tính theo số điểm kiểm thử mà lời giải vượt qua.

APIO và IOI đều dùng thể thức IOI. Hiện nay các cuộc thi trong nước Trung Quốc cũng đang dần tiến gần hơn đến thể thức IOI.

### Thể thức Codeforces (CF)

[Codeforces](https://codeforces.com) là một hệ thống chấm trực tuyến, định kỳ tổ chức các cuộc thi.

Đặc điểm của cuộc thi trên Codeforces là trong lúc thi chỉ kiểm thử trên một phần dữ liệu, gọi là pretests (các bộ kiểm thử sơ bộ), còn sau khi cuộc thi kết thúc mới trả về kết quả kiểm thử trên toàn bộ điểm kiểm thử đầy đủ, gọi là System Tests (kiểm thử hệ thống). Trong lúc thi có thể nộp nhiều lần và được phép hack mã nguồn của người khác; trong ngữ cảnh này, hack nghĩa là nộp một bộ dữ liệu kiểm thử khiến mã nguồn của người khác không thể đưa ra đáp án đúng. Nếu muốn hack, thí sinh phải khóa mã nguồn của mình (nói cách khác, trong lúc thi không thể nộp lại bài đó nữa). Khi hack, không được sao chép chương trình của thí sinh khác về máy cục bộ để kiểm thử; mã nguồn sẽ được chuyển thành hình ảnh.

Codeforces đồng thời cung cấp một thể thức khác, gọi là Extended ICPC (Extended ICPC hoặc ICPC+). Trong thể thức này, toàn bộ dữ liệu được kiểm thử trong lúc thi, nhưng sau khi cuộc thi kết thúc sẽ có 12 giờ hack toàn mạng. Khi hack được phép sao chép chương trình của thí sinh khác về máy cục bộ để kiểm thử.

## Các cuộc thi chính

### CSP-J/S

**CSP-J/S** (tiếng Anh: Certified Software Professional Junior/Senior) là kỳ chứng nhận năng lực phần mềm cấp không chuyên do CCF mở ra sau khi NOIP bị hủy vào năm 2019; trước năm 2025 kỳ này dành cho mọi lứa tuổi, [sau đó đổi thành từ 12 tuổi trở lên](https://www.noi.cn/xw/2025-02-13/837984.shtml).

CSP-J/S được chia thành hai nhóm: cấp nhập môn (Junior, viết tắt là CSP-J) và cấp nâng cao (Senior, viết tắt là CSP-S). Lịch thi gồm hai vòng: vòng một (thường vào tháng 9 hằng năm) và vòng hai (thường vào tháng 10 hằng năm). Vòng một là thi viết, kiểm tra lý thuyết máy tính, kiến thức thao tác thông thường, cùng kiến thức cơ bản về thuật toán và toán học; vòng hai là thi trên máy, cả nhóm nhập môn và nhóm nâng cao đều có 4 bài, trong đó nhóm nhập môn thi 3,5 giờ, nhóm nâng cao thi 4 giờ (ngoại trừ CSP-S 2019, kỳ này dùng thể thức cũ của nhóm nâng cao NOIP, lịch thi chia thành hai ngày, mỗi ngày 3 bài trong 3,5 giờ). Vòng một cho phép toàn bộ học sinh trong xã hội từ 12 tuổi trở lên đăng ký; sau một bước sàng lọc theo thứ hạng, những người có thành tích tốt có cơ hội tham gia vòng hai.

Đăng ký tham gia vòng một/vòng hai, cũng như khi khiếu nại bài sau vòng hai, đều cần nộp phí cho CCF.

Cả hai vòng thi đều đánh giá chứng nhận kết quả của thí sinh theo thứ hạng trong từng tỉnh, chia thành giải nhất, giải nhì và giải ba.

### NOIP

**NOIP** (tiếng Anh: National Olympiad in Informatics in Provinces, tiếng Trung: Liên đoàn Olympic Tin học Thanh thiếu niên Toàn quốc) là cuộc thi tin học do Cộng hòa Nhân dân Trung Hoa tổ chức, dành cho học sinh trung học ở Trung Quốc (bao gồm Hồng Kông và Ma Cao).

Thể thức cũ từ năm 2018 trở về trước: NOIP chia theo đối tượng dự thi thành nhóm phổ cập và nhóm nâng cao; năm 2018 thí điểm nhóm nhập môn tại Thượng Hải; chia theo giai đoạn thành vòng sơ khảo và vòng phúc khảo. Vòng sơ khảo kiểm tra một số kiến thức cơ bản về máy tính và nền tảng thuật toán, còn vòng phúc khảo là thi trên máy. Về thời gian, thường diễn ra vào cuối tuần thứ hai của tháng 11: sáng thứ Bảy, nhóm nâng cao bài thi thứ nhất từ 8:30-12:00 (3,5 giờ, tổng cộng 3 bài); chiều từ 14:30-18:00 là nhóm phổ cập (3,5 giờ, tổng cộng 4 bài); sáng Chủ nhật, nhóm nâng cao bài thi thứ hai từ 8:30-12:00 (3,5 giờ, tổng cộng 3 bài). Cả nước dùng chung một bộ đề, nhưng quy tắc trao giải do CCF (China Computer Federation) quy định thống nhất theo tình hình từng tỉnh, và được công bố trên [trang web chính thức của NOI](http://www.noi.cn) sau cuộc thi. Điểm chuẩn giải nhất của các tỉnh có khác nhau đôi chút.

NOIP [bị CCF tạm dừng](http://www.noi.cn/xw/2019-08-16/715365.shtml) vào ngày 16 tháng 8 năm 2019, và [được tuyên bố khôi phục](http://www.noi.cn/xw/2020-01-21/715520.shtml) vào ngày 21 tháng 1 năm 2020. Từ năm 2020, thể thức NOIP khác trước đây ở các điểm sau:

-   Hủy vòng sơ khảo, thay bằng vòng một CSP-J/S;
-   Hủy nhóm phổ cập, thay bằng CSP-J; từ đó NOIP chỉ còn một nhóm, dành cho thí sinh ở trình độ nhóm nâng cao;
-   Lịch thi được rút từ 6 bài trong 2 ngày, mỗi ngày 3,5 giờ, xuống còn 4 bài trong 1 ngày, tổng cộng 4,5 giờ.
-   Thí sinh cần đạt thứ hạng nhất định trong vòng hai CSP-S mới có tư cách tham gia NOIP; chỉ tiêu cụ thể khác nhau theo từng tỉnh. Tư cách tham gia NOIP cấp tỉnh liên quan đến số lượng thí sinh và thành tích của tỉnh đó trong mùa thi năm trước.

Đăng ký tham gia NOIP và khiếu nại bài không cần nộp thêm phí.

NOIP xếp hạng và trao giải theo đơn vị tỉnh. Tính đến năm 2019, ở phần lớn trường đại học, thí sinh đạt giải nhất cấp tỉnh nhóm nâng cao có thể nhận tư cách tuyển sinh tự chủ.

> Tháng 1 năm 2020, Bộ Giáo dục Cộng hòa Nhân dân Trung Hoa ban hành [Ý kiến về việc triển khai thí điểm cải cách tuyển sinh các ngành khoa học cơ bản tại một số trường đại học](http://www.moe.gov.cn/srcsite/A15/moe_776/s3258/202001/t20200115_415589.html). Văn bản nêu rằng từ năm 2020 sẽ không còn tổ chức công tác tuyển sinh tự chủ ở các trường đại học, đồng thời triển khai thí điểm cải cách tuyển sinh các ngành khoa học cơ bản tại một số trường đại học xây dựng đại học hạng nhất (Kế hoạch Cường cơ).

### Vòng tuyển chọn đội tuyển cấp tỉnh

**Vòng tuyển chọn đội tuyển cấp tỉnh** (gọi tắt: vòng tuyển tỉnh) dùng để chọn đội đại diện của các tỉnh tham gia kỳ thi toàn quốc, thường được tổ chức từ tháng 1 đến tháng 4 hằng năm. Về lịch thi, thường chia thành hai ngày, mỗi ngày 3 bài trong 4,5 giờ.

Đề của vòng tuyển tỉnh do từng tỉnh tự quyết định; xu hướng hiện nay là nhiều tỉnh chọn ra đề chung.

Chỉ tiêu của các đội tuyển tỉnh có công thức tính phức tạp, thường liên quan đến thành tích trước đó và số lượng thí sinh. Thông thường, điểm NOIP cần chiếm một tỷ lệ nhất định trong chỉ số của vòng tuyển tỉnh. Theo quy định, thí sinh trung học cơ sở chỉ có thể được chọn làm thí sinh loại E, không thể tham gia tuyển chọn loại A, B. Thí sinh loại A có 5 người ([ít nhất 1 nữ](https://www.noi.cn/xw/2024-08-26/829152.shtml)); các thí sinh khác lần lượt vào đội B theo chỉ tiêu cho sẵn và điểm đạt được. Số suất tham gia NOI của một trường không vượt quá một phần ba tổng chỉ tiêu A, B của tỉnh đó (làm tròn), và thí sinh nữ có điểm cao nhất đồng thời được chọn vào đội A không tính vào tỷ lệ này (gọi tắt là giới hạn 1/3 hoặc loại trừ 1/3; xem chi tiết trong [giải thích chính thức của CCF](https://www.noi.cn/xw/2022-12-14/781364.shtml)).

Từ năm 2020, vòng tuyển đội tuyển tỉnh NOI do CCF thống nhất ra đề và chấm; tỉnh có năng lực ra đề có thể tự ra đề, nhưng phương thức tuyển chọn cần được CCF phê duyệt. Từ năm 2024, vòng tuyển đội tuyển tỉnh NOI khôi phục việc các tỉnh tự ra đề; tỉnh có nhu cầu có thể tổ chức thi liên tỉnh hoặc dùng đề của tỉnh khác, nhưng phương án cụ thể cần được CCF phê duyệt.

### NOI

**NOI** (tiếng Anh: National Olympiad in Informatics, tiếng Trung: Olympic Tin học Toàn quốc) là cuộc thi cấp cao nhất trong nước dành cho các đội đại diện cấp tỉnh, bao gồm cả Hồng Kông và Ma Cao.

NOI thường được tổ chức vào tháng 7, thí sinh được chia thành hai loại: thí sinh chính thức và thí sinh trại hè. Thí sinh chính thức lại chia thành ba loại, trong đó loại A, B là thí sinh chính thức của đội tuyển tỉnh, loại C là thí sinh được mời. Loại A, B tương ứng với thí sinh loại A, B của đội tuyển tỉnh (trong đó loại A được cộng 5 điểm khi tính thành tích); loại C trên danh nghĩa là suất thưởng sau khi trường có đóng góp nổi bật cho CCF. Thí sinh trại hè chia thành loại D, E, lần lượt tương ứng với thí sinh nhóm trung học phổ thông và trung học cơ sở tham gia với tư cách không chính thức. Nếu thí sinh trại hè có thành tích vượt điểm chuẩn, họ chỉ có giấy chứng nhận thành tích chứ không có huy chương (với cùng mức điểm thì giá trị thấp hơn đôi chút). 50 thí sinh chính thức đứng đầu tạo thành đội tuyển tập huấn quốc gia và nhận tư cách tuyển thẳng.

Trên các nền tảng quốc tế, để phân biệt với các cuộc thi khác cũng gọi là NOI, kỳ này đôi khi được gọi là CNOI.

### CTT

**CTT** (tiếng Anh: China Team Training, tiếng Trung: Tập huấn đội tuyển quốc gia Olympic Tin học Quốc tế) là hoạt động tập huấn và tuyển chọn tổ chức mỗi mùa đông cho thí sinh đội tuyển tập huấn quốc gia IOI, gồm 3-4 bài kiểm tra. Ngoài đội tuyển tập huấn quốc gia, một số thí sinh đạt thành tích xuất sắc trong NOI năm đó cũng có thể tham gia CTT dưới danh nghĩa "tập huấn tinh anh".

CTT cùng với bài tập thường kỳ và các quy trình khác tạo thành giai đoạn thứ nhất của tuyển chọn đội tuyển quốc gia. Từ năm 2021, 30 thí sinh đứng đầu ở giai đoạn thứ nhất sẽ trở thành đội dự tuyển quốc gia và bước vào giai đoạn tuyển chọn thứ hai (WC).

### WC

**WC** (tiếng Anh: Winter Camp, tiếng Trung: Trại đông Olympic Tin học Thanh thiếu niên Toàn quốc) là một hoạt động được tổ chức vào mỗi mùa đông tại địa điểm đăng cai NOI của năm đó. Dù hoạt động này chủ yếu dùng cho tập huấn đội tuyển và tuyển chọn đội tuyển quốc gia, các thí sinh đạt thành tích khá tốt ở NOIP và vòng hai CSP-S năm trước cũng có thể tham gia với tư cách trại viên không chính thức.

Nội dung WC gồm nhiều ngày tập huấn và kiểm tra; điểm kiểm tra sẽ được tổng hợp với thành tích của các giai đoạn trước để tính ra xếp hạng tổng hợp của thí sinh đội tuyển tập huấn. Trước năm 2020, chỉ có một bài kiểm tra, và đề kiểm tra của đội tuyển tập huấn giống đề của trại viên không chính thức; 15 thí sinh đứng đầu thành tích tổng hợp của đội tuyển tập huấn sẽ trở thành đội dự tuyển quốc gia, tham gia giai đoạn tuyển chọn cuối cùng (CTS, v.v.). Từ năm 2021, khi chức năng tuyển chọn đội tuyển quốc gia của CTS được gộp vào WC, bài kiểm tra của đội dự tuyển quốc gia chuyển thành hai buổi, còn trại viên không chính thức vẫn thi một buổi, và đề của trại viên không chính thức có một phần trùng với đề của đội dự tuyển. 6 thí sinh đứng đầu xếp hạng tổng hợp trong đội dự tuyển sẽ bước vào phỏng vấn cuối cùng, từ đó chọn ra 4 thí sinh chính thức và 2 thí sinh dự bị tham gia IOI năm đó.

### APIO

**APIO** (tiếng Anh: Asia-Pacific Informatics Olympiad, tiếng Trung: Olympic Tin học Châu Á - Thái Bình Dương) là một cuộc thi môn tin học dành cho học sinh trung học đang học tại khu vực châu Á - Thái Bình Dương. Hằng năm CCF tổ chức kỳ thi song song cho khu vực Trung Quốc vào đầu tháng 5. Xung quanh ngày thi sẽ có các hoạt động tập huấn.

Thí sinh APIO có thể chia thành loại A và loại B; sáu thí sinh đứng đầu loại A (bao gồm đồng hạng) có thể tham gia xét giải quốc tế của APIO, còn thí sinh loại B chỉ có thể tham gia xét giải của khu vực Trung Quốc.

### CTS

**CTS** (tên cũ: CTSC, tiếng Anh: China Team Selection Competition, tiếng Trung: Kỳ tuyển chọn đội tuyển Trung Quốc tham dự Olympic Tin học Quốc tế) dùng để chọn đội tuyển quốc gia (6 người) từ đội dự tuyển quốc gia (15 người), chuẩn bị tham gia IOI vào mùa hè năm đó; trong đó có 4 thí sinh chính thức và 2 thí sinh dự bị. Tương tự WC, thí sinh có thành tích khá tốt ở NOIP năm trước cũng có thể tham gia (không tham gia tuyển chọn).

APIO và CTS đều đăng ký theo đơn vị tỉnh, thường dựa trên thứ hạng thành tích NOIP để xác định người tham gia APIO và CTS (hai kỳ này thường diễn ra rất gần nhau về thời gian).

CTS năm 2020 bị dừng vì dịch bệnh; đội tuyển tập huấn quốc gia năm đó được chọn thông qua NOI. Từ năm 2021, quy trình tuyển chọn của CTS được WC thay thế.

### IOI

**IOI** (tiếng Anh: International Olympiad in Informatics, tiếng Trung: Olympic Tin học Quốc tế) là cuộc thi môn tin học hằng năm dành cho học sinh trung học trên toàn thế giới. Mỗi quốc gia có bốn người tham gia; cuộc thi thường có phát trực tiếp. Trong thể thức IOI, mỗi bài có các Subtask (bài con), mỗi Subtask tương ứng với một số điểm nhất định.

### Trại học thuật

#### Peking University (PKU)

-   Peking University Informatics Winter Camp (PKUWC): tổ chức vào khoảng thời gian trước hoặc sau Winter Camp.
-   Peking University Informatics Experience Camp (PKUSC): thường tổ chức trong khuôn viên trường vào tháng 6. Do thi trong phòng máy của trường, môi trường phòng máy là Windows, hệ thống thi là OpenJudge.
-   Peking University Summer School for High School Students (Informatics): tổ chức trong kỳ nghỉ hè, dành cho học sinh khối 11 ban khoa học tự nhiên.

#### Tsinghua University (THU)

-   Hoạt động hội thảo và giảng dạy mùa đông "chuyển tiếp trung học - đại học" của Khoa Khoa học Máy tính: tương đương Winter Camp tin học, đôi khi cũng dùng viết tắt tiếng Anh là THUWC. Thường kéo dài tổng cộng hai ngày; buổi sáng là thi đấu (ngày đầu là cuộc thi OI chuẩn, ngày thứ hai là cuộc thi "bài kỹ thuật" do Tsinghua tự sáng tạo), buổi chiều là đào tạo theo khóa học.

## Các cuộc thi OI ở quốc gia và khu vực khác

### Hoa Kỳ: USACO

Trang web chính thức: <http://www.usaco.org/>

USACO có lẽ là cuộc thi OI nước ngoài quen thuộc nhất với thí sinh trong nước Trung Quốc (có thể cũng là cuộc thi OI nước ngoài có nhiều lời giải tiếng Trung nhất).

Từ mùa đông đến đầu mùa xuân hằng năm, USACO tổ chức một cuộc thi trực tuyến mỗi tháng. Một cuộc thi kéo dài 3\~5 giờ.

Theo giới thiệu trên trang web chính thức, cuộc thi USACO được chia thành 4 mức độ khó sau (trước năm học 2015\~2016 là 3 mức):

-   Bronze Division, phù hợp với người mới học lập trình, nhất là học sinh mới chỉ học các thuật toán cơ bản nhất (như: sắp xếp, tìm kiếm nhị phân);
-   Silver Division, phù hợp với học sinh bắt đầu học các kỹ thuật thuật toán cơ bản (như: đệ quy, tìm kiếm, thuật toán tham lam) và cấu trúc dữ liệu nền tảng;
-   Gold Division, học sinh sẽ gặp các thuật toán phức tạp hơn (như: đường đi ngắn nhất, DP) và cấu trúc dữ liệu nâng cao hơn;
-   Platinum Division, phù hợp với thí sinh có năng lực thiết kế thuật toán vững chắc; Platinum Division có thể giúp họ thử thách bản thân bằng các bài toán phức tạp và mở hơn.

Ở Trung Quốc, hiện nền tảng OJ có đầy đủ bài USACO nhất là Luogu.

### Ba Lan: POI

Trang web chính thức: <https://oi.edu.pl/>

Địa chỉ nộp bài chính thức: <https://szkopul.edu.pl/p/default/problemset/>

POI là cuộc thi OI nước ngoài mà khá nhiều thí sinh vòng tuyển tỉnh luyện nhiều nhất.

Theo mô tả trên [trang web chính thức của POI](https://oi.edu.pl/l/42/), quy trình POI như sau:

-   Vòng một: sáu bài (từ kỳ thứ 31 trở về trước là năm bài), thi trực tuyến;
-   Vòng hai: gồm một cuộc thi luyện tập và hai cuộc thi chính thức, trong đó cuộc thi luyện tập có một bài, mỗi cuộc thi chính thức có hai bài;
-   Vòng ba: gồm một cuộc thi luyện tập và hai cuộc thi chính thức, trong đó cuộc thi luyện tập có một bài, mỗi cuộc thi chính thức có ba bài.

Trong một số năm, từng có cuộc thi tên là ONTAK; tên chính thức của nó là trại tập huấn POI, tương ứng với các kỳ tập huấn đội tuyển tập huấn quốc gia trong nước Trung Quốc (CTT).

Ngoài ra, Ba Lan còn tổ chức một cuộc thi mở tên là PA, đại ý là "Algorithmic Battles"; trang web chính thức là: <https://potyczki.mimuw.edu.pl/>.

Hiện nay trong các OJ ở Trung Quốc, nơi có bài POI đầy đủ nhất là BZOJ.

### Croatia: COCI

Trang web chính thức (tiếng Anh): <http://www.hsin.hr/coci/>

Trang web chính thức (tiếng Croatia): <http://www.hsin.hr/honi/>

Đây là cuộc thi có dải độ khó rất rộng, khoảng từ mức Phổ cập - đến mức tuyển chọn cấp tỉnh -.

Trước đây, toàn bộ bài của COCI đều cung cấp đề bài, dữ liệu, lời giải và mã chuẩn. Từ cuối năm 2017, lời giải và mã chuẩn của COCI ngừng được cập nhật. Đến mùa 2019-2020, lời giải và mã chuẩn bắt đầu được cập nhật trở lại.

Luogu, BZOJ và LibreOJ đều có một lượng nhỏ bài COCI.

### Nhật Bản: JOI

Trang web chính thức: <https://www.ioi-jp.org/>

JOI (tiếng Nhật: Japanese Olympiad in Informatics, tiếng Trung: Olympic Tin học Nhật Bản) cung cấp đề bài, dữ liệu, lời giải và mã chuẩn cho tất cả bài. Trong hai năm gần đây, JOI Final và JOI Spring Camp cung cấp đề tiếng Anh, nhưng không có lời giải tiếng Anh. JOI Open qua các năm đều cung cấp phiên bản đề bài và lời giải bằng tiếng Anh.

Quy trình JOI:

-   Vòng sơ tuyển (Yosen)
-   Chung kết (Honsen/JOI Final)
-   Trại tập huấn mùa xuân (JOI Spring Camp/JOISC)
-   Cuộc thi mở (JOI Open Contest)

Vòng sơ tuyển có độ khó thấp; từ mùa 2019/2020, vòng sơ tuyển được chia thành nhiều vòng. Độ khó của JOI Final khoảng từ Nâng cao - đến Nâng cao +. Độ khó các bài của JOISC và JOI Open dao động từ Nâng cao đến NOI -.

Đa số bài JOI có thể nộp trên [AtCoder](https://atcoder.jp/). Có thể tìm thêm bài JOI (đề tiếng Nhật) trên trang web chính thức của JOI hoặc trên AtCoder.

Hiện nay LibreOJ và BZOJ có các bài JOI Final, JOISC và JOI Open trong những năm gần đây.

### Nga: ROI

Trang web chính thức: <http://neerc.ifmo.ru/school/archive/index.html>

Địa chỉ nộp trực tuyến: <https://contest.yandex.ru/roiarchive/> và Codeforces (một phần).

ROI (tiếng Nga: олимпиадная информатика, tiếng Trung: Olympic Tin học Nga) là cuộc thi tin học của Nga.

Quy trình:

-   Vòng thành phố (Municipal Stage/Муниципальный этап)
-   Vòng khu vực (Regional Stage/Региональный этап)
-   Vòng chung kết (Final Stage/Заключительный этап)

Hiện LibreOJ có bản dịch các bài vòng chung kết ROI trong vài năm gần đây.

Ngoài ra, Nga còn có các cuộc thi quy mô khá lớn dành cho học sinh trung học:

-   Internet Olympiads in Informatics (tiếng Nga: Интернет-олимпиады по информатике)
    -   Trang web chính thức: <http://neerc.ifmo.ru/school/io/index.html>
    -   Cuộc thi này do các tác giả đề ROI tổ chức.
-   All-Russian Team Olympiad for Schoolchildren in Informatics (tiếng Nga: Всероссийской командной олимпиады школьников)
    -   Trang web chính thức: <http://neerc.ifmo.ru/school/russia-team/index.html>
    -   Vòng sơ tuyển Moscow Team Olympiad của cuộc thi này có thể nộp trên Codeforces.
-   Innopolis Open
    -   Trang web chính thức <https://olymp.innopolis.ru/en/ooui/information/>
-   Open Olympiad for Schoolchildren in Programming (Открытая олимпиада школьников по программированию)
    -   Trang web chính thức: <https://olympiads.ru/zaoch/>
    -   Trang web chính thức cho biết cuộc thi này tương ứng với ROI.

### Canada: CCC & CCO

CCC (tiếng Anh: Canadian Computing Competition), CCO (tiếng Anh: Canadian Computing Olympiad), có thể tra cứu thông tin và đề thi các năm trên [trang web chính thức](https://cemc.math.uwaterloo.ca/contests/past_contests.html#ccc).

Có thể nộp [CCC](https://dmoj.ca/problems/?category=4) và [CCO](https://dmoj.ca/problems/?category=24) trên DMOJ; OJ này cũng có lời giải CCC.

CCC Junior/Senior gần với độ khó nhóm phổ cập/nhóm nâng cao của NOIP. Muốn đạt huy chương vàng CCO có lẽ cần trình độ huy chương bạc NOI.

### Singapore: NOI SG

Trang web chính thức: <https://noisg.comp.nus.edu.sg/noi/>

Tên đầy đủ là Singapore National Olympiad in Informatics; trong ngữ cảnh nội bộ Singapore và khi không gây nhập nhằng, cũng gọi là NOI. Về thể thức, cuộc thi chia thành Online Qualification Contest (vòng loại trực tuyến) và Final Contest (chung kết toàn quốc). Vòng loại trực tuyến đăng ký tham gia theo đơn vị trường; thí sinh thi tại trường mình và nộp bài từ xa qua mạng. Thành tích vòng loại chỉ xếp hạng trong nội bộ trường; 5 thí sinh đứng đầu và có điểm khác 0 đủ tư cách đại diện trường tham gia chung kết toàn quốc.

Hiện nay các OJ trong nước Trung Quốc thu thập bài NOI SG còn khá ít; có thể tìm đề bài, dữ liệu kiểm thử và chương trình chuẩn chính thức qua các năm trên [tài khoản GitHub chính thức](https://github.com/noisg).

### Khu vực Đài Loan: Olympic Tin học

Khu vực Đài Loan dùng cách dịch "tin học" theo thuật ngữ tiếng Hoa phồn thể của Đài Loan, khác với cách dùng thông dụng ở Trung Quốc đại lục.

Thí sinh ở khu vực Đài Loan nếu muốn tham gia IOI cần trải qua các vòng thi sau:

-   Kỳ thi năng lực môn Tin học khu vực
-   Kỳ thi năng lực môn Tin học toàn quốc
-   Trại nghiên cứu Tin học (TOI)

### Các quốc gia khác

-   Úc: AIO: <https://orac.amt.edu.au/hub/aio/>

    -   Độ khó tương tự NOI.

-   Vương quốc Anh: British Informatics Olympiad: <https://www.olympiad.org.uk/>

    -   Độ khó quá thấp.

-   Czech: Matematická olympiáda–kategorie P: <http://mo.mff.cuni.cz/p/archiv.html>

-   Romania: Olimpiada Nationala de Informatica: <http://olimpiada.info/>
    -   Đề bài, dữ liệu kiểm thử và lời giải có thể tìm trong thẻ có chữ Subiecte.

## Các cuộc thi OI quốc tế khác

### BalticOI

**BalticOI** hướng đến các quốc gia quanh biển Baltic. Các nước tham gia BalticOI 2018 gồm Lithuania, Ba Lan, Estonia, Phần Lan, v.v., tổng cộng 9 nước. Đề có độ khó cao.

Ngoại trừ năm 2017, BalticOI công khai đề bài, dữ liệu kiểm thử và lời giải hằng năm. BalticOI không có một trang web chính thức cố định; ban tổ chức từng năm sẽ tạo một trang web mới. Địa chỉ trang web chính thức các năm xem trong [bài viết](https://loj.ac/article/416).

Hiện LibreOJ có bài BalticOI của gần mười năm gần đây.

### BalkanOI

**BalkanOI** hướng đến các quốc gia quanh khu vực Balkan. Các nước tham gia BalkanOI 2018 gồm Romania, Hy Lạp, Bulgaria, Serbia, v.v., tổng cộng 12 nước. Đề có độ khó cao.

BalkanOI chỉ công khai đề bài, dữ liệu kiểm thử và lời giải trong một số năm; địa chỉ trang web chính thức xem trong [bài viết](https://loj.ac/article/416).

### CEOI

Các nước tham gia CEOI 2018 có một phần trùng với hai cuộc thi phía trên, gồm Ba Lan, Romania, Georgia, Croatia, v.v. Đề có độ khó cao.

CEOI công khai đề bài, dữ liệu kiểm thử và lời giải hằng năm; địa chỉ trang web chính thức xem trong [bài viết](https://loj.ac/article/416).

### eJOI

**eJOI** có tên đầy đủ là European Junior Olympiad in Informatics. Các nước tham gia gồm Nga, Armenia, Bulgaria, Ba Lan, v.v. Đề có độ khó khá cao.

eJOI công khai đề bài, dữ liệu kiểm thử và lời giải hằng năm; địa chỉ trang web chính thức xem trong [bài viết](https://loj.ac/article/416).

### NOI

???+ warning "Cảnh báo"
    Phần này không giới thiệu "National Olympiad in Informatics" của Trung Quốc.

**NOI** có tên đầy đủ là Nordic Olympiads in Informatics.

Trang web chính thức: <http://nordic.progolymp.se>

Đây là cuộc thi mới bắt đầu tổ chức trong khoảng hai năm gần đây, hướng đến các nước Bắc Âu.

## Tài liệu tham khảo

-   [Cuộc thi và thể thức ICPC/CCPC](./icpc.md)
-   ["Nhóm dịch thuật" địa chỉ của một số cuộc thi OI cấp châu lục](https://loj.ac/article/416)
