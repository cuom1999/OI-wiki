author: StudyingFather, NachtgeistW, countercurrent-time, Ir1d, H-J-Granger, Chrogeek, sshwy, Suyun514, hsfzLZH1, CBW2007, Xeonacid, kawa-yoiko, Konano

Trong lập trình thi đấu, có rất nhiều kiểu bài toán khác nhau.

## Bài truyền thống

**Bài truyền thống** là dạng bài hiện khá phổ biến trong lập trình thi đấu.

Thí sinh cần nộp mã nguồn. Hệ thống chấm sẽ dùng một số dữ liệu vào và dữ liệu ra tương ứng đã được chuẩn bị trước làm các test[^note1], biên dịch mã nguồn thí sinh nộp[^note2], cho chương trình của thí sinh đọc dữ liệu vào, rồi so sánh dữ liệu thí sinh xuất ra với dữ liệu ra đã chuẩn bị trước để phán định chương trình có đúng hay không. Cách chấm này được gọi là **chấm hộp đen**[^note3].

Với một test, thường sẽ có thêm giới hạn thời gian và giới hạn bộ nhớ.

Giới hạn thời gian là giới hạn về thời gian chạy của chương trình[^note4]. Thời gian chạy của chương trình thí sinh trên một test không được vượt quá giới hạn đã cho.

Giới hạn bộ nhớ là giới hạn về lượng bộ nhớ mà chương trình sử dụng. Lượng bộ nhớ lớn nhất chương trình thí sinh chiếm dụng khi chạy không được vượt quá giới hạn đã cho.

Sau khi chương trình kết thúc bình thường, dữ liệu xuất ra của thí sinh sẽ được so sánh với dữ liệu ra của test. Việc so sánh này thường bỏ qua dòng mới ở cuối tệp và khoảng trắng cuối dòng, rồi so sánh toàn văn. Với một số bài đặc biệt, hệ thống sẽ dùng [trình chấm đặc biệt (Special Judge)](../tools/special-judge.md) để so sánh.

Khi quá trình này kết thúc, hệ thống chấm sẽ căn cứ vào trạng thái chạy của chương trình để đưa ra các **kết quả chấm** khác nhau[^note5]:

-   Được chấp nhận (Accepted, AC): chương trình của thí sinh được chấp nhận.
-   Lỗi biên dịch (Compile Error, CE): chương trình của thí sinh không thể biên dịch bình thường.
-   Đáp án sai (Wrong Answer, WA): chương trình của thí sinh kết thúc bình thường, nhưng dữ liệu xuất ra không khớp với dữ liệu ra của test.
-   Lỗi trình bày (Presentation Error, PE): chương trình của thí sinh kết thúc bình thường, nhưng định dạng không đúng yêu cầu[^note6].
-   Lỗi khi chạy (Runtime Error, RE): chương trình của thí sinh kết thúc bất thường (giá trị trả về khi chương trình kết thúc không bằng không).
-   Quá giới hạn thời gian (Time Limit Exceeded, TLE): thời gian chạy của chương trình thí sinh vượt quá giới hạn thời gian đã cho.
-   Quá giới hạn bộ nhớ (Memory Limit Exceeded, MLE): lượng bộ nhớ lớn nhất chương trình thí sinh chiếm dụng vượt quá giới hạn bộ nhớ đã cho.
-   Quá giới hạn đầu ra (Output Limit Exceeded, OLE): lượng nội dung chương trình thí sinh xuất ra vượt quá giới hạn tối đa.

Trong các kỳ thi ICPC, chương trình của bạn cần đạt trạng thái AC trên tất cả test của một bài thì mới được xem là giải được bài đó. Trong các kỳ thi OI, đạt trạng thái AC trên một test là có thể nhận điểm của test đó[^note7].

## Bài nộp đáp án

**Bài nộp đáp án** là dạng bài nộp trực tiếp đáp án. Dạng bài này thường cung cấp các tệp dữ liệu vào và yêu cầu nộp một tệp nén, thư mục hoặc các tệp thuần chứa `XXX1.out`, `XXX2.out`, `XXX3.out`…`XXXn.out`.

Sau khi nộp đáp án, hệ thống chấm sẽ so sánh các tệp đáp án với đáp án chuẩn, rồi cho một số điểm nhất định dựa trên chất lượng đáp án của thí sinh và mức độ hoàn thành nhiệm vụ.

Vì bài nộp đáp án không cần chạy chương trình nguồn, dạng bài này không có giới hạn thời gian và bộ nhớ.

Thông thường có hai cách làm dạng bài này:

-   Làm thủ công. Cách này đơn giản và trực diện, nhưng gặp dữ liệu lớn thì gần như không xử lý được.
-   Viết một chương trình để sinh các tệp đáp án.

## Bài tương tác

**Bài tương tác** là dạng bài yêu cầu chương trình của thí sinh tương tác với chương trình chấm để hoàn thành nhiệm vụ. Một tình huống phổ biến là chương trình của thí sinh gửi truy vấn đến chương trình chấm và nhận phản hồi. Chương trình chấm có thể đặt giới hạn lên các truy vấn của thí sinh, hoặc điều chỉnh chiến lược trả lời để cố gắng làm tăng số lượt truy vấn, từ đó tạo thêm nhiều biến thể cho bài toán.

Có thể xem phần giải thích chi tiết hơn ở [bài tương tác](./interaction.md).

Các phương thức tương tác chủ yếu gồm hai loại sau. Dù khác nhau khá nhiều về mặt kỹ thuật, về bản chất kiểm tra thuật toán thì chúng không có khác biệt thực sự.

### Tương tác STDIO

Tương tác STDIO (tương tác I/O chuẩn) là phương thức tương tác trên các nền tảng trực tuyến như Codeforces, AtCoder, đồng thời cũng là chuẩn trong các kỳ thi thuộc hệ ICPC. Codeforces có một [hướng dẫn ngắn gọn hơn (tiếng Anh)](https://codeforces.com/blog/entry/45307).

???+ note "Ví dụ [LOJ #559. LibreOJ Round #9: Mê cung của ZQC](https://loj.ac/problem/559)"
    Hãy chú ý phần được thêm ở cuối.

    Đây là một bài tương tác.

    Bạn đang ở trong một mê cung tối gồm $n \times m$ ô vuông và cần đi tới đích của mê cung để hoàn thành thử thách.

    Ban đầu, bạn ở điểm xuất phát của mê cung, tức ô $(1,1)$, và quay mặt sang phải; điểm đích nằm ở ô $(n,m)$. Giữa hai ô bất kỳ trong mê cung đều liên thông, và chỉ có đúng một đường đi duy nhất; độ dài giữa hai ô kề nhau (tức kề theo bốn hướng trên, dưới, trái, phải) là một đơn vị. Giữa hai ô kề nhau có thể có tường; độ dày của tường rất nhỏ so với ô vuông nên có thể bỏ qua trong mô hình xấp xỉ. Biên của mê cung đều có tường, và mỗi bức tường đều nối với biên. Mê cung hoàn toàn tối, nghĩa là ngoài $(n,m)$ ra, bạn không thể nhận được bất kỳ thông tin nào.

    Để cố gắng không bị lạc trong bóng tối, mỗi lần đi tiếp bạn chỉ có thể xuất phát từ ô hiện tại, men theo bức tường bên trái hoặc bên phải, dùng tay trái hoặc tay phải chạm vào tường để đi, và làm cho khoảng cách tay chạm tường di chuyển đúng bằng một đơn vị. Cần chú ý rằng nếu phía bên trái hoặc bên phải không có tường, thì không thể đi theo hướng phía đó.

    Ở trong bóng tối quá lâu sẽ khiến bạn sợ hãi, vì vậy bạn cần ra khỏi mê cung càng sớm càng tốt. Nếu bạn không ra khỏi mê cung trong số bước giới hạn, thử thách sẽ thất bại.

Với dạng bài này, thí sinh chỉ cần ghi truy vấn ra đầu ra chuẩn như bình thường, **xả bộ đệm đầu ra** rồi đọc kết quả từ đầu vào chuẩn. Sau khi chương trình của thí sinh xả bộ đệm đầu ra, chương trình chấm được nối với nó qua ống dẫn (pipe, gọi là trình tương tác) mới có thể nhận ngay các dữ liệu này. Trong C/C++, có thể dùng `fflush(stdout)` và `std::cout << std::flush` để thực hiện thao tác này (khi xuống dòng bằng `std::cout << std::endl` thì bộ đệm cũng được tự động xả, nhưng `std::cout << '\n'` thì không); trong Pascal là `flush(output)`.

### Tương tác với trình chấm

Phương thức tương tác với trình chấm thường gặp trong các kỳ thi OI quốc tế như IOI, APIO (đặc biệt là các kỳ thi trên nền tảng CMS).

???+ note "Ví dụ [UOJ #206. APIO2016 Gap](https://uoj.ac/problem/206)"
    Có $N$ số nguyên không âm tăng nghiêm ngặt $a_1,a_2,\cdots,a_N (0\leq a_1<a2<\cdots<a_N\leq 10^{18})$. Bạn cần tìm giá trị lớn nhất trong các hiệu $a_{i+1}−a_i (0\leq i\leq N−1)$.

    Chương trình của bạn không thể trực tiếp đọc dãy số nguyên này, nhưng bạn có thể truy vấn thông tin của dãy thông qua các hàm đã cho. Về chi tiết của hàm truy vấn, hãy tham khảo phần chi tiết cài đặt bên dưới theo ngôn ngữ bạn sử dụng.

    Bạn cần cài đặt một hàm trả về giá trị lớn nhất trong $a_{i+1}−a_i (0\leq i\leq N−1)$.

Với dạng bài này, thí sinh chỉ cần viết một hàm cụ thể để hoàn thành một nhiệm vụ; hàm này tương tác bằng cách gọi một số hàm phụ trợ được cho sẵn. Để thí sinh tiện kiểm thử cục bộ, đề bài sẽ phát một tệp tiêu đề và một chương trình chấm tham khảo `grader.cpp` (với Pascal là một thư viện `graderlib`); thí sinh cần biên dịch chương trình của mình cùng với `grader.cpp` để thu được tệp thực thi.

```sh
g++ grader.cpp my_solution.cpp -o my_solution -Wall -O2
./my_solution   # Thực thi chương trình
```

Chương trình sau khi biên dịch có hành vi giống chương trình của bài truyền thống. Nó sẽ mở các tệp cố định, đọc dữ liệu theo định dạng cố định, gọi hàm do thí sinh viết, rồi hiển thị kết quả và một số thông tin (ví dụ số lần truy vấn, tính đúng sai của đáp án) ra đầu ra chuẩn.

Khi chấm thật, chương trình của thí sinh sẽ được biên dịch với một `grader.cpp` khác. `grader.cpp` này sẽ gọi hàm do thí sinh viết theo cách tương tự và ghi nhận điểm số. Nói chung, mọi ký hiệu toàn cục trong phiên bản `grader.cpp` này đều được đặt là `static`, tức không thể phá bằng cách đặt tên xung đột; tuy nhiên mọi hành vi cố gắng vượt qua giới hạn của trình chấm đều sẽ bị truất quyền (disqualification).

### Khác biệt

Một ưu điểm rõ ràng của tương tác STDIO là nó hỗ trợ được mọi ngôn ngữ lập trình, nhưng chi phí thời gian của nhập xuất dễ trở thành nút thắt khi thiết kế bài, khiến đôi khi khó phân biệt chênh lệch hiệu quả thời gian giữa các chương trình. Tương tác với trình chấm thì ngược lại: vì chi phí gọi hàm không lớn, nó thường cho phép số lượt truy vấn ở cỡ $10^6$, nhưng điểm yếu là bị hạn chế về ngôn ngữ.

Nếu tự thiết kế bài hoặc tổ chức kỳ thi, cần cân nhắc và so sánh hai phương thức này một cách nghiêm túc.

## Bài truyền tin

**Bài truyền tin** là dạng bài yêu cầu hai chương trình của thí sinh giao tiếp với nhau và phối hợp hoàn thành một nhiệm vụ. Chương trình thứ nhất nhận dữ liệu vào của bài toán và sinh một số dữ liệu ra; dữ liệu vào của chương trình thứ hai sẽ liên quan đến dữ liệu ra của chương trình thứ nhất (đôi khi được giữ nguyên làm một tham số, đôi khi được phía chấm xử lý rồi tạo ra), và chương trình thứ hai cần sinh lời giải của bài toán.

Ví dụ về bài truyền tin có: [UOJ #178. Điện mừng năm mới](https://uoj.ac/problem/178), [#454. UER #8: Ném tuyết](https://uoj.ac/problem/454), v.v.

Phương pháp kiểm thử cục bộ rất đa dạng tùy theo thiết lập của bài, các hình thức thường dùng gồm:

-   Nhập thủ công
-   Viết một chương trình phụ trợ để chuyển đổi đầu ra của chương trình thứ nhất thành đầu vào của chương trình thứ hai
-   Dùng ống dẫn (pipe) hai chiều để nối đầu vào/đầu ra chuẩn của hai chương trình với nhau

Do các nền tảng chấm còn hỗ trợ hạn chế cho bài truyền tin, đến nay dạng bài này chỉ thường gặp trong các kỳ thi hệ IOI và các cuộc thi do một số ít nền tảng trực tuyến như UOJ tổ chức. Đây vẫn là một lĩnh vực còn cần được khám phá.

## Bài hoàn thiện hàm

**Bài hoàn thiện hàm** là dạng bài yêu cầu thí sinh hoàn thiện chương trình. Có thể hiểu là trong một bài tương tác, đề bài đã cho sẵn mã của thí sinh và yêu cầu viết các hàm phụ trợ.

Thông thường có một số hình thức sau:

-   Cho sẵn một chương trình và cho biết khối mã cần hoàn thiện sẽ được nhúng vào đâu.
-   Không cho chương trình, mà truyền thông tin đầu vào dưới dạng tham số của hàm cần nộp.

Dạng bài này khá thường gặp trên [LeetCode](https://leetcode.com/) và [PTA - Pintia](https://pintia.cn/problem-sets).

## Các dạng khác

???+ note "Ví dụ [Quine](https://loj.ac/problem/4)"
    Viết một chương trình có thể in ra chính mã nguồn của nó.

    Mã nguồn phải chứa ít nhất mười ký tự hiển thị được.

Bài toán này rất kinh điển, nhưng trên phần lớn OJ thì rất khó triển khai.

??? note "Mã tham khảo"
    **Chú ý**: mã nguồn không chứa dòng đầu tiên bên dưới (tức `// clang-format off`).

    ```cpp
    // clang-format off
    #include<cstdio>

    char *s={"#include<cstdio>%cchar *s={%c%s%c};%cint main(){printf(s,10,34,s,34,10);return 0;}"};

    int main(){printf(s,10,34,s,34,10);return 0;}
    ```

## Tài liệu tham khảo và chú thích

[^note1]: Do hạn chế về kỹ thuật và tài nguyên, trong đa số trường hợp, các test của một bài không thể bao phủ toàn bộ dữ liệu thỏa mãn phạm vi dữ liệu.

[^note2]: Với các ngôn ngữ thông dịch như Python, chương trình sẽ được trình thông dịch trực tiếp thông dịch và chạy.

[^note3]: Trên thực tế, cài đặt của hệ thống chấm phức tạp hơn điều này rất nhiều; ở đây chỉ giới thiệu sơ lược quá trình chấm của hệ thống.

[^note4]: Nói chính xác hơn, thường là thời gian ở chế độ người dùng của chương trình.

[^note5]: Phần lớn kết quả chấm ở đây cũng áp dụng cho các dạng bài khác.

[^note6]: Hầu hết hệ thống chấm sẽ quy trạng thái PE vào trạng thái WA.

[^note7]: Một số test có thể có điểm thành phần; khi thí sinh hoàn thành một phần nhiệm vụ của một test, hoặc dữ liệu xuất ra của thí sinh đúng nhưng chưa đủ tối ưu, thí sinh có thể nhận một tỷ lệ điểm nhất định.
