Trước khi bắt đầu bài viết, toàn thể thành viên dự án **OI Wiki** luôn hoan nghênh mọi đóng góp cho dự án này. Chính nhờ hàng trăm người đóng góp mà **OI Wiki** có được ngày hôm nay!

Trang này liệt kê các quy chuẩn định dạng và phương châm biên tập được khuyên dùng khi viết **OI Wiki**. Trước khi soạn thảo hoặc sửa trang Wiki, vui lòng đọc kỹ các nội dung dưới đây để tạo ra nội dung chất lượng hơn.

Nếu muốn bắt đầu thật nhanh, nên đọc trước các mục [Tóm tắt nhanh](#tom-tat-nhanh) và [Hình minh họa](#hinh-minh-hoa).

??? abstract "Nhật ký thay đổi"
    **Lưu ý**: chỉ ghi các thay đổi liên quan đến viết bài, duyệt bài, v.v.; không ghi các thay đổi chỉ sửa định dạng.
    
    | Thời gian  | Nội dung chính                                                                | Liên kết Issue/Pull Request liên quan                                                                     |
    | ---------- | ----------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- |
    | 2026-02-22 | Hoàn thiện quy định về cách dùng dấu nháy                                     | [#6793](https://github.com/OI-wiki/OI-wiki/pull/6793)                                                     |
    | 2026-01-07 | Bản gốc bổ sung quy tắc dấu câu cho văn bản CJK                              | [#6746](https://github.com/OI-wiki/OI-wiki/pull/6746)                                                     |
    | 2025-08-10 | Thêm yêu cầu định dạng cho sổ tay định dạng;<br>Mã: bổ sung yêu cầu về mã đoạn | [#6412](https://github.com/OI-wiki/OI-wiki/pull/6412)                                                    |
    | 2025-08-10 | Thêm nhật ký thay đổi và tóm tắt nhanh                                        | [#6409](https://github.com/OI-wiki/OI-wiki/pull/6409)                                                     |
    | 2024-10-08 | Mã: hoàn thiện yêu cầu định dạng để phù hợp kiểm thử đa nền tảng              | [#5912](https://github.com/OI-wiki/OI-wiki/pull/5912), [#5924](https://github.com/OI-wiki/OI-wiki/pull/5924) |
    | 2024-03-26 | Khi dẫn liên kết bài trên OJ, dùng liên kết gốc thay vì liên kết bản sao      | [#5482](https://github.com/OI-wiki/OI-wiki/pull/5482)                                                     |
    | 2023-10-09 | Phần bổ trợ chủ đề: thêm yêu cầu định dạng cho tab[^note6]                    | [#5152](https://github.com/OI-wiki/OI-wiki/pull/5152)                                                     |
    | 2023-07-23 | Với nội dung về công cụ, yêu cầu dẫn tài liệu chính thức khi nói về tải và cài đặt | [#5023](https://github.com/OI-wiki/OI-wiki/pull/5023)                                                 |
    | 2023-04-15 | Bổ sung quy phạm dùng dấu nháy                                                | [#4792](https://github.com/OI-wiki/OI-wiki/pull/4792)                                                     |
    | 2023-03-28 | LaTeX: bảng ký hiệu toán học                                                  | [#4587](https://github.com/OI-wiki/OI-wiki/pull/4587)                                                     |
    | 2023-03-02 | Bổ sung quy phạm dùng dấu câu, khoảng trắng và dấu nối                       | [#4726](https://github.com/OI-wiki/OI-wiki/pull/4726)                                                     |
    | 2022-12-13 | Phần bổ trợ chủ đề: bỏ yêu cầu về bóng của hộp gấp lồng nhau                  | [#4500](https://github.com/OI-wiki/OI-wiki/pull/4500)                                                     |
    | 2022-08-09 | Khi dẫn một mục của liên kết nội bộ, dùng tiêu đề tương ứng trong bản tiếng Việt | [#4057](https://github.com/OI-wiki/OI-wiki/pull/4057)                                                  |
    | 2022-06-12 | Hoàn thiện yêu cầu liên quan đến thay đổi mục lục[^note4]                     | [#4043](https://github.com/OI-wiki/OI-wiki/pull/4043)                                                     |
    | 2021-09-09 | Phần bổ trợ chủ đề: bổ sung yêu cầu liên quan đến hộp gấp                     | [#3517](https://github.com/OI-wiki/OI-wiki/pull/3517)                                                     |
    | 2021-09-03 | LaTeX: `\Leftrightarrow` $\to$ `\iff`                                         | [#3499](https://github.com/OI-wiki/OI-wiki/pull/3499)                                                     |
    | 2021-08-18 | Mã: thêm yêu cầu định dạng cho mã bài mẫu                                     | [#3447](https://github.com/OI-wiki/OI-wiki/pull/3447)                                                     |
    | 2021-08-12 | Hình ảnh: ưu tiên dùng định dạng APNG cho ảnh động                            | [#3422](https://github.com/OI-wiki/OI-wiki/pull/3422)                                                     |
    | 2021-06-29 | Hình ảnh: khuyến nghị nộp kèm tệp nguồn                                       | [#3255](https://github.com/OI-wiki/OI-wiki/pull/3255)                                                     |
    | 2021-05-29 | Mã: bỏ yêu cầu dấu ngoặc nhọn không xuống dòng, bổ sung yêu cầu về khả năng đọc | [#3197](https://github.com/OI-wiki/OI-wiki/pull/3197)                                                  |
    | 2021-03-15 | Bảo trì trang: chuẩn hóa cách gộp Pull Request[^note5]                        | [#3061](https://github.com/OI-wiki/OI-wiki/pull/3061)                                                     |
    | 2021-02-01 | LaTeX: `\lt` $\to$ `<`, `\gt` $\to$ `>`                                       | [#2950](https://github.com/OI-wiki/OI-wiki/pull/2950)                                                     |
    | 2021-01-27 | Khuyến nghị lưu bản sao liên kết ngoài trên [Internet Archive](https://web.archive.org/) | [#2918](https://github.com/OI-wiki/OI-wiki/pull/2918)                                           |
    | 2020-09-19 | Bảo trì trang: yêu cầu viết thông điệp commit và tiêu đề Pull Request[^note4] | [#2744](https://github.com/OI-wiki/OI-wiki/pull/2744)                                                     |
    | 2020-10-18 | Hình ảnh: ưu tiên dùng định dạng SVG                                          | [#2215](https://github.com/OI-wiki/OI-wiki/pull/2215)                                                     |
    | 2020-08-05 | LaTeX: thêm yêu cầu định dạng cho biến gồm nhiều chữ cái                      | [#2502](https://github.com/OI-wiki/OI-wiki/pull/2502)                                                     |
    | 2020-07-28 | LaTeX: cấm môi trường `cases` có quá hai cột                                  | [#2466](https://github.com/OI-wiki/OI-wiki/pull/2466)                                                     |
    | 2020-07-24 | LaTeX: `{n \choose m}`$\to$ `\dbinom{n}{m}`                                   | [#2442](https://github.com/OI-wiki/OI-wiki/pull/2442)                                                     |
    | 2020-07-20 | Markdown: cấm cú pháp gạch xóa                                               | [#2422](https://github.com/OI-wiki/OI-wiki/pull/2422)                                                     |
    | 2020-07-19 | Phần bổ trợ chủ đề: yêu cầu giữ khoảng trắng thụt lề ở dòng trống trong hộp gấp[^note3];<br>LaTeX: thêm yêu cầu định dạng cho công thức toán | [#2412](https://github.com/OI-wiki/OI-wiki/pull/2412) |
    | 2020-07-11 | Phiên bản đầu tiên                                                            | [#2350](https://github.com/OI-wiki/OI-wiki/pull/2350)                                                     |

## <a id="tom-tat-nhanh"></a>Tóm tắt nhanh

Để người đọc lần đầu dễ nắm nội dung, mục này liệt kê một số điểm trọng yếu của sổ tay:

-   Lưu trữ tệp:

    -   Dùng tên tệp viết thường, thay khoảng trắng bằng `-`. Xem [SAVE-1](#SAVE-1).

    -   Không chèn ảnh bằng liên kết ngoài. Xem [SAVE-2](#SAVE-2).

    -   Hình ảnh nên dùng định dạng SVG nếu có thể, và chỉ nên dùng chuẩn SVG 1.1. Xem [SAVE-3](#SAVE-3).

    -   Ảnh động nên dùng định dạng SVG hoặc APNG. Xem [SAVE-4](#SAVE-4).

    -   Nếu hình ảnh có tệp nguồn, nên nộp kèm tệp nguồn. Xem [SAVE-5](#SAVE-5).

    -   Khi chèn liên kết ngoài, nên chèn kèm liên kết bản lưu trữ. Xem [SAVE-6](#SAVE-6).

    -   Không chèn liên kết nội bộ theo cách chèn liên kết ngoài. Xem [SAVE-7](#SAVE-7).

-   Dấu câu:

    -   Dùng dấu câu đúng quy chuẩn. Thêm **dấu chấm câu** ở cuối mỗi câu. Xem từ [PUNC-1](#PUNC-1) đến [PUNC-7](#PUNC-7).

    -   Lưu ý phân biệt các loại dấu nối (hyphen, en dash, em dash). Xem [PUNC-8](#PUNC-8).

-   Cú pháp Markdown và cú pháp mở rộng của chủ đề:

    -   Chỉ nên dùng tiêu đề cấp hai, cấp ba và cấp bốn. Không dùng tiêu đề để thay cho in đậm. Không viết công thức LaTeX trong tiêu đề. Xem [LINT-1](#LINT-1), [MDFM-1](#MDFM-1), [CONT-4](#CONT-4), [CONT-9](#CONT-9).

    -   Khi dùng cú pháp hộp gấp[^note3] và cú pháp tab[^note6], phải giữ thụt lề bên trong nhất quán, **kể cả dòng trống**. **Không được bỏ sót** khoảng trắng thụt lề của dòng trống. Xem [LINT-6](#LINT-6), [MDFM-6](#MDFM-6).

    -   Không dùng cú pháp gạch xóa `~~foo~~`. Xem [LINT-3](#LINT-3).

    -   Công thức hiển thị riêng dòng nên viết là

        ```text
        $$
        a^{2}=b^{2}+c^{2}
        $$
        ```

        thay vì `$$a^{2}=b^{2}+c^{2}$$`. Xem [LINT-5](#LINT-5).

    -   Dùng hộp gấp thay vì blockquote. Xem [MDFM-5](#MDFM-5).

    -   Khối mã chỉ nên dùng cú pháp ` ``` ` và phải ghi rõ ngôn ngữ. Xem [LINT-7](#LINT-7), [MDFM-3](#MDFM-3).

-   Công thức LaTeX:
    -   Không được mâu thuẫn với [bảng ký hiệu toán học](./symbol.md). Xem [MATH-1.1](#MATH-1.1).

    -   Lưu ý cách dùng font, xem [MATH-1.2](#MATH-1.2), [MATH-1.15](#MATH-1.15), [MATH-2.6](#MATH-2.6), [MATH-2.7](#MATH-2.7).

    -   Không lạm dụng công thức LaTeX. Xem [MATH-1.14](#MATH-1.14).

    -   Không dùng cách biểu diễn của ngôn ngữ lập trình trong công thức LaTeX. (Ví dụ: không dùng $a==b$, $a<<1$, $a\%b$.) Không dùng cách nối nhiều cặp ngoặc vuông ($a[i][j]$). Xem [MATH-1.9](#MATH-1.9), [MATH-1.10](#MATH-1.10).

-   Mã:

    -   Viết ngắn gọn, dễ hiểu, tránh các thói quen xấu như nén quá nhiều câu lệnh trên một dòng. Bảo đảm khả năng đọc và làm nổi bật tư tưởng thuật toán. Xem [CONT-10](#CONT-10).

    -   Không khuyến nghị chèn mã trực tiếp vào tài liệu Markdown. Xem [CODE-1.1](#CODE-1.1), [CODE-1.2](#CODE-1.2).

## Yêu cầu định dạng của tài liệu này

-   <a id="FREQ-1"></a>FREQ-1: khi sửa các mục của sổ tay định dạng, cần bổ sung nhật ký thay đổi đồng thời. Nếu chỉ sửa lỗi định dạng thì không cần bổ sung nhật ký thay đổi.
-   <a id="FREQ-2"></a>FREQ-2: ngoài mục [Tóm tắt nhanh](#tom-tat-nhanh), mọi mục trong sổ tay định dạng đều cần có mã số không trùng lặp. Mã số cần khớp biểu thức chính quy `(?<category>[A-Z]{4})-(?<id>[1-9][0-9]*(?:\.[1-9][0-9]*)*)`, trong đó `category` nên có ý nghĩa trực quan. Phần thuyết minh không cần có mã số.
-   <a id="FREQ-3"></a>FREQ-3: các mục trong [Tóm tắt nhanh](#tom-tat-nhanh) phải được lấy từ nội dung ở các chương khác của sổ tay định dạng, và cuối mục cần dẫn mã số mục tương ứng.
-   <a id="FREQ-4"></a>FREQ-4: sau khi mã số của mục đã xác định thì không nên thay đổi. Nếu thật sự cần thay đổi (ví dụ xóa hoặc gộp mục), cần ghi chú bằng nội dung tương tự "đã hủy bỏ" hoặc "chuyển sang XXXX-id".

## Yêu cầu khi đóng góp tài liệu

Khi dự định đóng góp nội dung cho một phần nào đó, người đóng góp nên nắm rõ ba phần sau:

-   Định dạng lưu trữ tài liệu.
-   Tính hợp lý của tài liệu.
-   Yêu cầu định dạng của remark-lint và công thức $\rm{\LaTeX}$.

### Định dạng dẫn chiếu và lưu trữ tài liệu

-   <a id="SAVE-1"></a>SAVE-1: **tên tệp bắt buộc viết thường và tách bằng `-`.** Ví dụ: `file-name.md`.

-   <a id="SAVE-2"></a>SAVE-2: cần bảo đảm tất cả hình ảnh **liên kết ngoài** được dẫn trong tài liệu đã được chuyển vào thư mục `images` tương ứng **bên trong kho này** (để tránh kích hoạt cơ chế chống hotlink của một số website). Nên đặt tên theo dạng `tên tài liệu MD + số thứ tự` (có thể tham khảo cách xử lý hình ảnh trong các tài liệu hiện có). Ví dụ: tên tệp của tài liệu này là format, thì hình ảnh đầu tiên được dẫn trong tài liệu có tên là `format1.png`.

-   <a id="SAVE-3"></a>SAVE-3: nên dùng hình ảnh định dạng SVG[^ref4] để có độ nét và hiệu quả phóng to, thu nhỏ tốt hơn. Do các thành phần của **OI Wiki** có khả năng tương thích khác nhau với chuẩn SVG, hình ảnh nên dựa trên chuẩn [SVG 1.1](http://www.w3.org/TR/SVG11/).

-   <a id="SAVE-4"></a>SAVE-4: với ảnh động, nếu không thể hoặc không biết cách tạo định dạng SVG, nên dùng tệp định dạng APNG[^apng]. Người dùng Windows có thể dùng [ScreenToGif](https://www.screentogif.com) để ghi hình, người dùng Linux có thể dùng [Peek](https://github.com/phw/peek) để ghi hình; lưu ý cần chỉnh trong cài đặt sang ghi APNG. Trường hợp khác, nên tạo trước thành tệp video như MP4 rồi chuyển sang APNG. Nếu dùng ffmpeg, có thể chuyển bằng `ffmpeg -i filename.mp4 -f apng filename.apng -plays 0`.[^intro-apng]

-   <a id="SAVE-5"></a>SAVE-5: với hình ảnh có đồng thời tệp nguồn và ảnh xuất ra (ví dụ tệp JPG và tệp PSD, hoặc ảnh SVG và mã nguồn TikZ TeX), nên lưu tệp nguồn cùng tên với hình ảnh trong cùng thư mục.

-   <a id="SAVE-6"></a>SAVE-6: cần bảo đảm tính ổn định của các liên kết tham chiếu trong tài liệu. **Không khuyến nghị** dẫn tài nguyên từ dịch vụ **tự xây dựng** (ví dụ bài tập trong OJ tự xây dựng). Khi thêm liên kết ngoài, nên đồng thời lưu liên kết đó vào Internet Archive[^webarchive] để phòng trường hợp liên kết không thể thay thế bị hỏng.

-   <a id="SAVE-7"></a>SAVE-7: với liên kết trong site, cần bỏ tên miền website và dùng đường dẫn tương đối để liên kết đến tệp `.md` tương ứng. Ví dụ, trong trang này (`intro/format`), khi liên kết đến giới thiệu về tạp mục (`misc`), nên dùng `[Giới thiệu tạp mục](../misc/index.md)`. Có thể thêm hash vào liên kết để trỏ đến một mục cụ thể, ví dụ [`[Quy chuẩn định dạng thông tin Pull Request](./htc.md#pull-request-format)`](./htc.md#pull-request-format). Giá trị hash có thể lấy từ nút ở bên phải mỗi tiêu đề hoặc từ liên kết trong mục lục bên phải trang web.

### Tính hợp lý của tài liệu

**Tính hợp lý** nghĩa là **nội dung** được viết phải có các đặc tính sau:

-   <a id="STRC-1"></a>STRC-1: đi từ dễ đến khó, độ khó của nội dung nên có tính tăng tiến.
-   <a id="STRC-2"></a>STRC-2: có tính logic.

    -   <a id="STRC-2.1"></a>STRC-2.1: khi viết nội dung về thuật toán hoặc khái niệm toán học, nên cố gắng bao gồm các nội dung sau:

        1.  Nguyên lý: giải thích nguyên lý tương ứng của nội dung đó;
        2.  Ví dụ: đưa ra 1 đến 2 ví dụ điển hình;
        3.  Bài tập: dưới tiêu đề này, **chỉ cần đưa ra tên bài và liên kết bài**. Với bài tập thuật toán, thứ tự ưu tiên của OJ trong liên kết bài là: OJ gốc (nếu có thể truy cập ổn định) > UOJ > LOJ > Luogu.

        Trang ví dụ: [IDA\*](../search/idastar.md).

    -   <a id="STRC-2.2"></a>STRC-2.2: khi viết nội dung về công cụ, nên cố gắng bao gồm các nội dung sau:

        1.  Giới thiệu: trình bày bối cảnh và công dụng của công cụ.
        2.  Cách cấu hình: nêu chi tiết quá trình cấu hình môi trường và sử dụng; phương pháp tải và cài đặt nên ưu tiên dẫn tài liệu chính thức.

        Trang ví dụ: [WSL (Windows 10)](../tools/wsl.md).

Trừ khi chất lượng nội dung hiện có thấp, nên đóng góp theo hướng **bổ sung** thay vì ghi đè trực tiếp. Nếu không chắc nên làm gì, có thể tham khảo mục [cách trao đổi về dự án này](./about.md#trao-đổi) và liên hệ với nhóm dự án **OI Wiki**.

### Yêu cầu định dạng cơ bản của tài liệu

#### Yêu cầu định dạng của Remark-lint

[remark-lint](https://github.com/remarkjs/remark-lint) có thể tự động thống nhất phong cách cho các tệp trong dự án. Tệp cấu hình hiện **OI Wiki** đang dùng được lưu tại [.remarkrc](https://github.com/OI-wiki/OI-wiki/blob/master/.remarkrc).

Trong quá trình cấu hình, nhóm dự án **OI Wiki** cũng gặp một số vấn đề remark-lint xử lý chưa tốt, vì vậy cần biên tập tài liệu nghiêm ngặt theo các yêu cầu sau:

-   <a id="LINT-1"></a>LINT-1: không dùng tiêu đề cấp một như `<h1>` hoặc `# Tiêu đề`.

-   <a id="LINT-2"></a>LINT-2: sau dấu tiêu đề phải có một khoảng trắng ASCII, ví dụ: `## Giới thiệu`.

-   <a id="LINT-3"></a>LINT-3: vì remark-lint không xử lý tốt gạch xóa, vui lòng không dùng cú pháp gạch xóa. Một lý do khác để không dùng gạch xóa là nội dung bị gạch xóa thường mang tính "đùa vui", ít giúp người đọc hiểu bài, và không phù hợp với [yêu cầu về diễn đạt nội dung](#CONT-5) trong phần "Yêu cầu định dạng của nội dung văn bản" bên dưới.

-   <a id="LINT-4"></a>LINT-4: danh sách:
    -   <a id="LINT-4.1"></a>LINT-4.1: trước danh sách cần có một dòng trống để bắt đầu một đoạn mới.
    -   <a id="LINT-4.2"></a>LINT-4.2: khi dùng danh sách có thứ tự (như `1. Ví dụ`), sau dấu chấm cần có khoảng trắng.

-   <a id="LINT-5"></a>LINT-5: trước và sau công thức riêng dòng đều cần có một dòng trống, nếu không nó sẽ bị xem là công thức trong dòng.

-   <a id="LINT-6"></a>LINT-6: khi dùng cú pháp hộp gấp bắt đầu bằng `???` hoặc `!!!`, mỗi dòng thuộc phần văn bản trong hộp gấp phải bắt đầu bằng ít nhất 4 khoảng trắng.

    **Ngay cả dòng trống cũng phải giữ thụt lề nhất quán với các dòng khác. Vui lòng không dùng tính năng tự động cắt khoảng trắng cuối dòng của trình soạn thảo.**

    ???+ success "Ví dụ"
        Trong đoạn mã dưới đây, `␣` biểu thị khoảng trắng ` `.
        
        ```text
        ???+ warning
        ␣␣␣␣Cần nhớ thêm 4 khoảng trắng trước văn bản. Các cú pháp khác vẫn giống cú pháp Markdown.
        ␣␣␣␣
        ␣␣␣␣Nếu không thêm 4 khoảng trắng, văn bản sẽ không xuất hiện trong hộp gấp.
        ␣␣␣␣
        ␣␣␣␣Câu hỏi `???` này là gì sẽ được giải thích ở [phần sau](#MDFM-5).
        ```
        
        ???+ warning "Cảnh báo"
            Cần nhớ thêm 4 khoảng trắng trước văn bản. Các cú pháp khác vẫn giống cú pháp Markdown.
            
            Nếu không thêm 4 khoảng trắng, văn bản sẽ không xuất hiện trong hộp gấp.
            
            Câu hỏi `???` này là gì sẽ được giải thích ở [phần sau](#MDFM-5).

-   <a id="LINT-7"></a>LINT-7: với khối văn bản thuần mang kiểu dáng mã, vui lòng dùng ` ```text`. Nếu dùng trực tiếp ` ``` ` mà không chỉ định ngôn ngữ cho khối văn bản thuần, nội dung có thể bị thụt lề sai.

#### Cách dùng dấu câu

-   <a id="PUNC-1"></a>PUNC-1: cần thêm **dấu chấm câu** ở cuối mỗi câu.

<!-- scripts.linter.postprocess.fix_full_stop off -->

-   <a id="PUNC-2"></a>PUNC-2: cần dùng dấu câu và khoảng trắng theo quy chuẩn tiếng Việt. Dấu câu thông dụng như `.`, `,`, `:`, `;`, `?`, `!`, dấu ngoặc và dấu nháy nên dùng dạng nửa chiều rộng; không dùng dấu câu toàn chiều rộng kiểu CJK trong văn bản tiếng Việt, trừ khi trích nguyên văn hoặc ghi chú về một ký hiệu cụ thể. Không đặt khoảng trắng trước dấu câu đóng như dấu phẩy, dấu chấm, dấu hai chấm, dấu chấm phẩy, dấu hỏi, dấu than; đặt một khoảng trắng sau các dấu đó nếu câu còn tiếp tục.

<!-- scripts.linter.postprocess.fix_full_stop on -->

<!-- scripts.linter.postprocess.fix_quotation off -->

-   <a id="PUNC-3"></a>PUNC-3: khi cần đặt một cụm từ trong dấu nháy, ưu tiên dùng dấu nháy kép `"..."` trong Markdown để giữ văn bản nhất quán và dễ tìm kiếm. Chỉ dùng dấu nháy đơn `'...'` khi cần phân biệt một lớp trích dẫn lồng bên trong, hoặc khi đó là ký hiệu bắt buộc trong mã nguồn, chuỗi ký tự hay cú pháp lệnh.

<!-- scripts.linter.postprocess.fix_quotation on -->

-   <a id="PUNC-4"></a>PUNC-4: lưu ý phân biệt cách dùng dấu liệt kê và dấu phẩy.
-   <a id="PUNC-5"></a>PUNC-5: lưu ý vị trí của dấu ngoặc. Vị trí của ngoặc trong câu và ngoặc ngoài câu là khác nhau.
-   <a id="PUNC-6"></a>PUNC-6: thông thường dùng **dấu chấm phẩy** để biểu thị quan hệ giữa các mệnh đề phức trong môi trường danh sách.
-   <a id="PUNC-7"></a>PUNC-7: với danh sách có thứ tự, nên thêm **dấu chấm phẩy** sau mỗi mục và thêm **dấu chấm câu** sau mục cuối cùng; với danh sách không thứ tự, nên thêm **dấu chấm câu** sau mỗi mục.
-   <a id="PUNC-8"></a>PUNC-8: lưu ý phân biệt các loại dấu nối khác nhau, như hyphen (thường dùng U+002D hyphen-minus (-), tức phím "dấu trừ" trên bàn phím, để thay thế), U+2013 en dash (–) và U+2014 em dash (—). (Trong tiếng Anh, khi nối nhiều tên người, phải dùng en dash, nhưng lỗi thường gặp là dùng nhầm thành hyphen. Các lỗi khác hiếm hơn; về cơ bản chỉ cần nhớ điểm này.) Xem [hyphen - Wikipedia](https://en.wikipedia.org/wiki/Hyphen).

    ???+ success "Ví dụ"
        -   Các kỳ thi môn học cấp trung học chủ yếu bao gồm Olympic Tin học, Olympic Tin học, Olympic Tin học, Olympic Tin học và Olympic Tin học (ai viết ví dụ này thì nên mời ra ngoài sửa lại).
        -   "Anh ăn cơm chưa?" Lý Tứ hỏi Trương Tam.
        -   Tôi muốn nói với anh: "Tôi thật sự rất thích câu này."
        -   "Nếu lợi cho đất nước thì sống chết cũng không quản ngại, đâu vì họa phúc mà tránh né!"
        -   Trương Hoa đỗ đại học; Lý Bình vào trường nghề; tôi trở thành công nhân: chúng tôi đều có tương lai tốt đẹp.[^note1]
        -   Quy trình cơ bản của thuật toán này như sau:
            1.  Khởi tạo khoảng cách đến mỗi đỉnh là vô cùng, đánh dấu tất cả đỉnh là chưa được thăm, và khởi tạo một hàng đợi;
            2.  Đưa đỉnh xuất phát vào hàng đợi, đánh dấu đỉnh xuất phát là đã được thăm, và cập nhật khoảng cách đến đỉnh xuất phát là $0$;
            3.  Lấy phần tử đầu hàng đợi ra và đánh dấu phần tử đó là chưa được thăm;
            4.  Duyệt tất cả cạnh nối với phần tử này; nếu tồn tại khoảng cách ngắn hơn đến đỉnh đó thì thực hiện thao tác relax;
            5.  Nếu đỉnh đó chưa được thăm, đưa đỉnh đó vào hàng đợi và đánh dấu đỉnh đó là đã được thăm;
            6.  Quay lại bước thứ ba cho đến khi hàng đợi rỗng.
        -   Thuật toán KMP (Knuth–Morris–Pratt algorithm, KMP algorithm) được Knuth, Pratt và Morris công bố chung vào năm 1977.[^note2]

#### Yêu cầu về định dạng Markdown và định dạng mở rộng của chủ đề

-   <a id="MDFM-1"></a>MDFM-1: khi biểu thị nhấn mạnh, vui lòng dùng `**SOMETHING**` hoặc dấu nháy kép `"..."` khi phù hợp, thay vì một cấp tiêu đề nào đó, vì dùng tiêu đề sẽ làm cấu trúc bài viết rối loạn và/hoặc làm mục lục gặp vấn đề.

-   <a id="MDFM-2"></a>MDFM-2: khi cần dẫn liên kết bài tập, nên ưu tiên dùng liên kết trong kho bài của OJ gốc thay vì liên kết bản sao.

-   <a id="MDFM-3"></a>MDFM-3: cần dùng đúng chức năng block của Markdown. Khi chèn mã trong dòng, dùng một cặp dấu backtick bao quanh khối mã; khi chèn mã riêng dòng, dùng một cặp ` ``` ` bao quanh khối mã. Dấu backtick là ký tự nằm dưới dấu ngã ở góc trên bên trái bàn phím. Với mã riêng dòng, cần thêm tên ngôn ngữ sau ` ``` ` đầu tiên (ví dụ: ` ```cpp`).

    ???+ success "Ví dụ"
        ````text
        ```cpp
        // #include<stdio.h>    // cách viết không tốt
        #include <cstdio>  // cách viết tốt
        ```
        ````
        
        ```cpp
        // #include<stdio.h>    // cách viết không tốt
        #include <cstdio>  // cách viết tốt
        ```

-   <a id="MDFM-4"></a>MDFM-4: mục "Tài liệu tham khảo và chú thích" được viết bằng chức năng footnote của Markdown. Định dạng là:

    ```markdown
    Nội dung văn bản.[^ten-footnote]
    [^ten-footnote]: Nội dung tài liệu tham khảo. Lưu ý: dấu hai chấm là dấu hai chấm tiếng Anh, sau dấu hai chấm có một khoảng trắng.
    ```

    Tên footnote có thể dùng số hoặc văn bản. Vị trí đặt tên footnote giống cách dùng dấu ngoặc. Để đẹp mắt, nên để tên footnote trong cùng một trang tuân theo cùng một quy luật đặt tên, ví dụ: ref1, ref2, note1, ...

    Nội dung footnote được đặt thống nhất dưới tiêu đề cấp hai `## Tài liệu tham khảo và chú thích`.

    ???+ success "Ví dụ"
        ```markdown
        Khi `#include <cxxxx>` có thể thay thế `#include <xxxx.h>`, nên dùng cách viết trước.[^ref1]
        
        Ngày 21 tháng 1 năm 2020, CCF thông báo khôi phục NOIP.[^ref2]
        
        ## Tài liệu tham khảo và chú thích
        
        [^ref1]: [cstdio stdio.h namespace](https://stackoverflow.com/questions/10460250/cstdio-stdio-h-namespace)
        
        [^ref2]: [Thông báo của CCF về việc khôi phục kỳ thi NOIP - China Computer Federation](https://www.ccf.org.cn/c/2020-01-21/694716.shtml)
        ```
        
        Khi `#include <cxxxx>` có thể thay thế `#include <xxxx.h>`, nên dùng cách viết trước.[^ref1]
        
        Ngày 21 tháng 1 năm 2020, CCF thông báo khôi phục NOIP.[^ref2]

-   <a id="MDFM-5"></a>MDFM-5: nên dùng định dạng `???+note` được chủ đề mở rộng (tức [khối có thể gấp](https://squidfunk.github.io/mkdocs-material/reference/admonitions/#collapsible-blocks)) để mô tả đề bài và mã tham khảo. Cũng có thể dùng định dạng này để hiển thị các nội dung khác cần giới thiệu bổ sung.

    Mã ví dụ (trong đoạn mã dưới đây, `␣` biểu thị khoảng trắng ` `):

    ```text
    ??? note "Tiêu đề"
    ␣␣␣␣Hộp văn bản này mặc định sẽ bị gấp lại.
    ␣␣␣␣
    ␣␣␣␣Nên đặt **mã lời giải** trong hộp văn bản gấp được.

    ???+note "[Bài toán A + B của HDOJ](https://acm.hdu.edu.cn/showproblem.php?pid=1000)"
    ␣␣␣␣Tiêu đề cũng có thể dùng siêu liên kết Markdown. Trong ví dụ này, siêu liên kết là "Bài toán A + B" của HDOJ.
    ␣␣␣␣
    ␣␣␣␣Ngoài ra, nên **ghi chú liên kết bài gốc** theo cách này.
    ␣␣␣␣
    ␣␣␣␣Lưu ý vị trí của dấu nháy kép.
    ```

    Hiệu quả:

    ??? note "Tiêu đề"
        Hộp văn bản này mặc định sẽ bị gấp lại.
        
        Nên đặt **mã lời giải** trong hộp văn bản gấp được.

    ???+ note "[Bài toán A + B của HDOJ](https://acm.hdu.edu.cn/showproblem.php?pid=1000)"
        Tiêu đề cũng có thể dùng siêu liên kết Markdown. Trong ví dụ này, siêu liên kết là "Bài toán A + B" của HDOJ.
        
        Ngoài ra, nên **ghi chú liên kết bài gốc** theo cách này.
        
        Lưu ý vị trí của dấu nháy kép.

    Khác nhau giữa hai định dạng là: định dạng có `+` mặc định giữ trạng thái mở, còn định dạng không có `+` mặc định giữ trạng thái gấp.

    Tiêu đề của hộp gấp, tức nội dung sau `note` trong `???+note`, nên được bao bằng `"`. Nội dung trong đó hỗ trợ cú pháp Markdown. Xem [admonition - đổi tiêu đề](https://squidfunk.github.io/mkdocs-material/reference/admonitions/#changing-the-title). (Loại không có chức năng gấp là admonition thông thường; tham khảo [admonition trong Material for MkDocs](https://squidfunk.github.io/mkdocs-material/reference/admonitions).)

-   <a id="MDFM-6"></a>MDFM-6: khi cần thêm mã bằng nhiều ngôn ngữ khác nhau, nên dùng tab nội dung để có thể chuyển đổi giữa mã của các ngôn ngữ. Tab nội dung còn có các cách dùng khác; xem [tab nội dung](https://squidfunk.github.io/mkdocs-material/reference/content-tabs/#usage). Cách dùng và hiệu quả như sau.

    ???+ success "Ví dụ"
        Lưu ý cần thêm 4 khoảng trắng trước văn bản (dưới đây dùng `␣` để biểu thị). Các cú pháp khác vẫn giống cú pháp Markdown.
        
        ````text
        === "C"
        ␣␣␣␣```c
        ␣␣␣␣#include <stdio.h>
        ␣␣␣␣
        ␣␣␣␣int main(void) {
        ␣␣␣␣  printf("Hello world!\n");
        ␣␣␣␣  return 0;
        ␣␣␣␣}
        ␣␣␣␣```
        
        === "C++"
        ␣␣␣␣```cpp
        ␣␣␣␣#include <iostream>
        ␣␣␣␣
        ␣␣␣␣int main(void) {
        ␣␣␣␣  std::cout << "Hello world!" << std::endl;
        ␣␣␣␣  return 0;
        ␣␣␣␣}
        ␣␣␣␣```
        ````
        
        === "C"
            ```c
            #include <stdio.h>
            
            int main(void) {
              printf("Hello world!\n");
              return 0;
            }
            ```
        
        === "C++"
            ```cpp
            #include <iostream>
            
            int main(void) {
              std::cout << "Hello world!" << std::endl;
              return 0;
            }
            ```

Nếu còn câu hỏi về mkdocs-material (chủ đề đang dùng), cũng có thể đọc [hướng dẫn sử dụng MkDocs](https://github.com/ctf-wiki/ctf-wiki/wiki/Mkdocs-%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E), trong đó giới thiệu cách dùng các plugin của chủ đề mkdocs-material.

#### Yêu cầu định dạng của nội dung văn bản

-   <a id="CONT-1"></a>CONT-1: tất cả chữ **OI Wiki** trong văn bản đều nên được đánh dấu in đậm.

-   <a id="CONT-2"></a>CONT-2: đầu trang nên có một đoạn văn ngắn (như "Trang này sẽ giới thiệu ...") để tóm tắt nội dung trang.

    ???+ success "Ví dụ"
        Trang này liệt kê các quy chuẩn định dạng và phương châm biên tập được khuyên dùng khi viết **OI Wiki**.

-   <a id="CONT-3"></a>CONT-3: với trang liên quan đến "kiến thức tiên quyết", cần thêm một dòng **Kiến thức tiên quyết: ...** ở đầu trang, đặt trước phần tóm tắt trang. Định dạng như sau:

    `Kiến thức tiên quyết: [trang nội bộ 1](url1), [trang nội bộ 2](url2) và [trang nội bộ 3](url3)`

    ???+ success "Ví dụ"
        Kiến thức tiên quyết: [Độ phức tạp thời gian](../basic/complexity.md)
        
        Trang này sẽ giới thiệu kiến thức cơ bản về lý thuyết tính toán.

-   <a id="CONT-4"></a>CONT-4: cần lưu ý cấu trúc tài liệu. Cấu trúc tài liệu cần thật có trật tự và phân cấp mạch lạc. Không nên để những việc như "tiêu đề cấp năm" xảy ra nữa; một bài viết bình thường không cần cấu trúc phân cấp phức tạp như vậy.

-   <a id="CONT-5"></a>CONT-5: cần lưu ý cách diễn đạt nội dung. Là một website bách khoa, ngôn ngữ **OI Wiki** sử dụng nên mang tính viết, khách quan. Những nội dung mang tính "đùa vui" và ít giúp người đọc hiểu bài không nên xuất hiện trong **OI Wiki**.

-   <a id="CONT-6"></a>CONT-6: nên cố gắng cung cấp tiêu đề đầy đủ hoặc gợi ý dễ nhận biết cho liên kết, tránh dùng URL trần hoặc các mô tả mơ hồ như "này", "đó". Mỗi siêu liên kết nên được mô tả cụ thể hết mức để người đọc biết nó sẽ trỏ đến đâu.

    Nên dùng tiêu đề của bài nguồn hoặc của tab.

    ???+ failure "Cách viết không khuyến nghị"
        ```markdown
        Vui lòng tham khảo [trang này](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork)
        
        Vui lòng tham khảo <https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork>
        ```
        
        Vui lòng tham khảo [trang này](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork)
        
        Vui lòng tham khảo <https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork>

    ???+ success "Cách viết khuyến nghị"
        ```markdown
        Vui lòng tham khảo trang trợ giúp chính thức của GitHub [Syncing a fork - GitHub Docs](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork)
        ```
        
        Vui lòng tham khảo trang trợ giúp chính thức của GitHub [Syncing a fork - GitHub Docs](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork)

-   <a id="CONT-7"></a>CONT-7: do giới hạn của định dạng Markdown, tiêu đề cấp hai `## Tài liệu tham khảo và chú thích` phải đặt ở cuối bài.

-   <a id="CONT-8"></a>CONT-8: khi số thứ tự xuất hiện trong câu văn tự nhiên, nên viết bằng chữ tiếng Việt nếu cách viết đó giúp câu dễ đọc hơn. Ví dụ:
    -   Hạng thứ nhất của dãy số.
    -   Dòng thứ nhất của tệp nhập.

-   <a id="CONT-9"></a>CONT-9: nên cố gắng tránh dùng công thức MathJax trong tiêu đề, bất kể là tiêu đề cấp mấy. Dùng công thức trong tiêu đề có thể làm mục lục hiển thị sai.[^ref3]

-   <a id="CONT-10"></a>CONT-10: cần lưu ý khả năng đọc của mã.

    -   <a id="CONT-10.1.1"></a>CONT-10.1.1: mã cần có logic mạch lạc, ngắn gọn và dễ hiểu hết mức có thể. Không nên nén dòng quá mức, không đưa vào quá nhiều mã không liên quan. Cố gắng tránh nội dung không liên quan đến tư tưởng thuật toán.
    -   <a id="CONT-10.1.2"></a>CONT-10.1.2: nên thêm chú thích phù hợp trong mã tham khảo để người đọc dễ hiểu.

    Đối với các ngôn ngữ kiểu C/C++:

    -   <a id="CONT-10.2.1"></a>CONT-10.2.1: cố gắng tránh các chỉ thị tiền xử lý và định nghĩa macro ảnh hưởng đến khả năng đọc.

    -   <a id="CONT-10.2.2"></a>CONT-10.2.2: không dùng `0` thay cho `false`/`NULL`/`nullptr`, không dùng `1` thay cho `true`, v.v.

    -   <a id="CONT-10.2.3"></a>CONT-10.2.3: khi khai báo [bí danh kiểu](https://en.cppreference.com/w/cpp/language/type_alias), không khuyến nghị dùng `typedef`, nên dùng `using`.

    -   <a id="CONT-10.2.4"></a>CONT-10.2.4: không khuyến nghị định nghĩa hằng bằng macro; nên trực tiếp dùng các từ khóa như `constexpr`/`const` để định nghĩa hằng.

    -   <a id="CONT-10.2.5"></a>CONT-10.2.5: không khuyến nghị dùng từ khóa `inline` cho hàm; xem [tối ưu biên dịch](../lang/optimizations.md#inline---nội-tuyến).

    -   <a id="CONT-10.2.6"></a>CONT-10.2.6: cố gắng tránh type traits, partial specialization và các kỹ thuật lập trình meta bằng template phức tạp khác. Nếu thật sự cần dùng, cần thêm chú thích để giải thích ý nghĩa.

        ???+ failure "Cách viết không khuyến nghị"
            ```cpp
            --8<-- "docs/intro/code/format/format_1.cpp:not-recommended"
            ```
            
            Đoạn mã này đưa ra một cách hiện thực phức tạp để tính [ước chung lớn nhất](../math/number-theory/gcd.md), trong đó:
            
            -   `gcd` thứ nhất nhận hai số nguyên không dấu `x`, `y`, trả về ước chung lớn nhất của `x`, `y`; miền giá trị của kiểu trả về bảo đảm có thể chứa đồng thời `x` và `y`.
            -   `gcd` thứ hai nhận hai số nguyên `x`, `y`, trong đó ít nhất một trong `x`, `y` là số nguyên có dấu, và trả về ước chung lớn nhất của `x`, `y`.
            -   `gcd` thứ ba nhận hơn hai số nguyên và trả về ước chung lớn nhất của các số đó.
            -   `gcd` thứ tư nhận một container và trả về ước chung lớn nhất của tất cả số trong container.
            
            Với **OI Wiki**, trọng tâm chỉ là tư tưởng của thuật toán ước chung lớn nhất; đoạn mã này bao gồm quá nhiều chi tiết kỹ thuật phức tạp và không liên quan, nên cần tránh.

        ???+ success "Cách viết khuyến nghị"
            ```cpp
            --8<-- "docs/intro/code/format/format_1.cpp:recommended"
            ```
            
            Những việc như "thêm kiểm tra kiểu", "xử lý đầu vào âm", "cho hàm hỗ trợ nhiều tham số" thiên về quan tâm kỹ thuật phần mềm hơn; trọng tâm của tài liệu luôn nên là tư tưởng thuật toán.

#### Yêu cầu định dạng của công thức LaTeX

LaTeX là lựa chọn ưu tiên để dàn công thức, và cần sử dụng nó đúng cách. Vì vậy, **OI Wiki** có yêu cầu nghiêm ngặt đối với việc dùng LaTeX. Nếu muốn bắt đầu nhanh, có thể đọc bảng ở cuối mục này.

-   <a id="MATH-1.1"></a>MATH-1.1: ký hiệu được sử dụng không được mâu thuẫn với ký hiệu được quy định trong [bảng ký hiệu toán học](./symbol.md).

-   <a id="MATH-1.2"></a>MATH-1.2: dùng Roman để biểu thị số, hằng, toán tử và hàm. Dùng Italic để biểu thị biến và chỉ số dưới. LaTeX đã định nghĩa sẵn một số hằng, hàm, toán tử thường gặp; có thể gọi trực tiếp, bao gồm nhưng không giới hạn:

    ```latex
    \log, \ln, \lg, \sin, \cos, \tan, \sec, \csc, \cot, \gcd, \min, \max, \exp, \inf, \mod, \bmod, \pmod
    ```

    Vì vậy, khi nhập hằng, tên hàm, toán tử, v.v., vui lòng kiểm tra trước xem có nên dùng Roman hoặc font khác hay không. Cách viết ký hiệu LaTeX có thể tham khảo trang [các hàm được hỗ trợ của KaTeX](https://katex.org/docs/supported.html) (không phải đầy đủ tất cả), hoặc có thể tìm kiếm lời giải.

    Do trong LaTeX việc viết chữ cái Hy Lạp thường dạng Roman tương đối khó, các hằng, toán tử và hàm là chữ cái Hy Lạp thường có thể dùng Italic, như $\pi$ và $\delta$ trong $\delta x$.

    Nếu gặp **tên hàm** cần dùng Roman nhưng chưa được định nghĩa sẵn, có thể dùng `$\operatorname{something}$` để tạo ra. Ví dụ có thể dùng `$\operatorname{lcm}$` để tạo ký hiệu bội chung nhỏ nhất (hàm) ở dạng roman. Tương tự, để tạo **hằng** dạng Roman, dùng `$\mathrm{}$`; để tạo ký hiệu Roman đậm, dùng `$\mathbf{}$`; để tạo ký hiệu Italic đậm, dùng `$\boldsymbol{}$` (như vector $\boldsymbol{a}$). Với biến gồm nhiều chữ cái, nên dùng `$\textit{}$`. Các nội dung phi toán học khác, bao gồm tiếng Anh, ký hiệu đặc biệt, v.v., đều dùng `$\text{}$`. Với tiếng Việt hoặc văn bản tự nhiên dài, nên cân nhắc đưa nội dung ra ngoài công thức LaTeX nếu có thể.

-   <a id="MATH-1.3"></a>MATH-1.3: nếu biểu thức cần xuống dòng (thường gặp trong công thức hiển thị riêng dòng dài), nên tuân theo các quy tắc xuống dòng sau:

    -   <a id="MATH-1.3.1"></a>MATH-1.3.1: đặt ký tự xuống dòng trước $=$, $+$, $-$, $\pm$, $\mp$; nếu cần, cũng có thể đặt trước $\times$, $\cdot$, $/$, ví dụ:

        $$
        \begin{aligned}
            \mathrm{e}^x &= \sum\limits_{n=0}^{\infty} \frac{x^n}{n!} \\
            &= \phantom{+} 1 + x + \frac{x^2}{2} \\
            & \phantom{=} + \frac{x^3}{6} + \frac{x^4}{24} + \dots \\
        \end{aligned}
        $$

    -   <a id="MATH-1.3.2"></a>MATH-1.3.2: cùng một toán tử không nên xuất hiện đồng thời trước và sau ký tự xuống dòng.

    -   <a id="MATH-1.3.3"></a>MATH-1.3.3: cố gắng không đặt ký tự xuống dòng bên trong biểu thức nằm trong dấu ngoặc.

-   <a id="MATH-1.4"></a>MATH-1.4: khi dùng phân số trong dòng, cần dùng `$\dfrac{}{}$`. Ví dụ `$\dfrac{1}{2}$` cho hiệu quả $\dfrac{1}{2}$, thay vì `$\frac{1}{2}$` cho hiệu quả $\frac{1}{2}$.

-   <a id="MATH-1.5"></a>MATH-1.5: với tổ hợp, cần dùng `\dbinom{n}{m}`, cho hiệu quả $\dbinom{n}{m}$, thay vì `{n \choose m}` (cách viết này trong LaTeX đã không được khuyến nghị); tương tự quy ước về phân số ở mục trước, vui lòng không dùng `\binom{n}{m}`, cho hiệu quả $\binom{n}{m}$.

-   <a id="MATH-1.6"></a>MATH-1.6: cố gắng tránh dùng toán tử lớn trong dòng (như $\sum$, $\prod$, $\int$, v.v.).

-   <a id="MATH-1.7"></a>MATH-1.7: khi không gây nhầm lẫn, dùng `$\times$` thay cho dấu sao; phép nhân chéo dùng `$\times$`, phép nhân vô hướng dùng `$\cdot$`. Ví dụ $a\times b$, $a\cdot b$, thay vì $a\ast b$.

-   <a id="MATH-1.8"></a>MATH-1.8: dùng `$\cdots$` (nằm giữa baseline và topline), `$\ldots$` (nằm tại baseline), `$\vdots$` (dấu ba chấm dọc) thay cho `$...$`. Ví dụ $a_1,a_2,\cdots a_n$, thay vì $a_1,a_2,... a_n$.

-   <a id="MATH-1.9"></a>MATH-1.9: lưu ý không dùng bất kỳ cách biểu diễn nào của ngôn ngữ lập trình ở khu vực không phải mã; thay vào đó cần dùng công thức LaTeX. Ví dụ, dùng `$=$` thay vì `$==$` (như $a=b$, thay vì $a==b$), dùng `` `a<<1` `` hoặc `$a\times 2$` thay vì `$a<<1$`, dùng `$a\bmod b$` thay cho `$a\%b$` (như $a\bmod b$, thay vì $a\%b$), v.v.

-   <a id="MATH-1.10"></a>MATH-1.10: trong công thức, không dùng nhiều cặp ngoặc vuông nối tiếp (tức cách biểu diễn mảng nhiều chiều của C++); nên dùng chỉ số dưới nhiều hơn. Tức là dùng $a_{i,j,k}$ thay vì $a[i][j][k]$. Khi chỉ số dưới trong công thức phức tạp, nên chuyển sang hàm nhiều biến ($f(i,j,k)$) hoặc định dạng mã trong dòng. Với hàm một biến đơn giản, có thể dùng `$f_i$`, `$f(i)$` hoặc `$f[i]$`.

-   <a id="MATH-1.11"></a>MATH-1.11: để thống nhất và tiện viết, khi phân tích độ phức tạp, dùng trực tiếp ký hiệu $O$ lớn `$O()$` thay vì `$\mathcal O()$`.

-   <a id="MATH-1.12"></a>MATH-1.12: khi biểu thị quan hệ tương đương, dùng `$\iff$`, hiệu quả $\iff$, thay vì `$\Leftrightarrow$`, hiệu quả $\Leftrightarrow$.

-   <a id="MATH-1.13"></a>MATH-1.13: môi trường hàm từng phần `cases` **chỉ được có hai cột** (tức một dấu phân tách `&`).

-   <a id="MATH-1.14"></a>MATH-1.14: vui lòng không lạm dụng công thức LaTeX. Điều này không chỉ làm trang tải chậm (vì MathJax nổi tiếng là hiệu suất thấp), mà còn làm bố cục trang rối loạn. Font công thức LaTeX thường chỉ dùng để biểu thị tên biến. Khuyến nghị của **OI Wiki** là nếu không cần thiết, nên cố gắng giảm **lượng lớn** việc trộn công thức với font văn bản thông thường; nếu không cần thiết, cố gắng không dùng công thức, ví dụ:

    ```LaTeX
    Sắp học luồng chi phí nhỏ nhất $SPFA$ trong $Network-flow$, cần dùng thuật toán $Edmonds–Karp$ để tăng luồng.
    ```

    Đây là một ví dụ điển hình về **lạm dụng font công thức**. (Nếu cần dùng chữ nghiêng trong trang, viết bằng `*văn bản*`.)

-   <a id="MATH-1.15"></a>MATH-1.15: cần dùng đúng ký hiệu LaTeX tương ứng, đặc biệt là các ký hiệu đặc biệt như chữ cái Hy Lạp trong công thức. Ví dụ hàm Euler nên dùng `$\varphi$`, đường kính hình tròn nên dùng `$\Phi$`, tỉ lệ vàng nên dùng `$\phi$`. Các ký hiệu này tuy đều biểu thị chữ cái Hy Lạp Phi, nhưng có ý nghĩa khác nhau trong các ngữ cảnh khác nhau. Cần nhớ **không dùng chức năng chèn ký hiệu đặc biệt của bộ gõ** để chèn các ký hiệu này.

    Ngoài ra, do nguyên nhân lịch sử của LaTeX, ký hiệu tập rỗng nên là `$\varnothing$` thay vì `$\emptyset$`; các ký hiệu khác nên viết theo [bảng ký hiệu toán học](./symbol.md).

Có thể dùng một bảng để tóm tắt các nội dung trên. Lưu ý bảng này không liệt kê cách dùng của tất cả ký hiệu, mà chỉ đưa ra các lỗi thường gặp. Các trường hợp tương tự có thể suy ra theo đó.

| Cách dùng không đúng quy định       | Hiệu quả render       | Cách dùng đúng quy định                         | Hiệu quả render                       |
| ----------------------------------- | --------------------- | ----------------------------------------------- | ------------------------------------- |
| `$log, ln, lg$`                     | $log, ln, lg$         | `$\log$, $\ln$, $\lg$`                          | $\log$, $\ln$, $\lg$                  |
| `$sin, cos, tan$`                   | $sin, cos, tan$       | `$\sin$, $\cos$, $\tan$`                        | $\sin$, $\cos$, $\tan$                |
| `$gcd, lcm$`                        | $gcd, lcm$            | `$\gcd$, $\operatorname{lcm}$`                  | $\gcd$, $\operatorname{lcm}$          |
| `$e$, $\text{e}$, e` (cơ số logarit tự nhiên) | $e$, $\text{e}$, e | `$\mathrm{e}$`                                  | $\mathrm{e}$                          |
| `$i$, $\text{i}$, i` (đơn vị ảo)    | $i$, $\text{i}$, i    | `$\mathrm{i}$`                                  | $\mathrm{i}$                          |
| `$ số nguyên tố nhỏ hơn a $`        | $số nguyên tố nhỏ hơn a$ | `số nguyên tố nhỏ hơn $a$`                   | số nguyên tố nhỏ hơn $a$              |
| `$...$`                             | $...$                 | `$\cdots$, $\ldots$, $\vdots$, $\ddots$`        | $\cdots$, $\ldots$, $\vdots$, $\ddots$ |
| `$a*b$` (hai số nhân nhau)          | $a*b$                 | `$a\times b$, $a\cdot b$`                       | $a\times b$, $a\cdot b$               |
| `$SPFA$` (tên tiếng Anh)            | $SPFA$                | `SPFA`                                          | SPFA                                  |
| `$a==b$`                            | $a==b$                | `$a=b$`                                         | $a=b$                                 |
| `$f[i][j][k]$`                      | $f[i][j][k]$          | `$f_{i,j,k}$, $f(i,j,k)$`                       | $f_{i,j,k}$, $f(i,j,k)$               |
| `$R,N^*$` (tập hợp)                 | $R,N^*$               | `$\mathbf{R}$, $\mathbf{N}^*$`                  | $\mathbf{R}$, $\mathbf{N}^*$          |
| `$\emptyset$`                       | $\emptyset$           | `$\varnothing$`                                 | $\varnothing$                         |
| `$size$`                            | $size$                | `$\textit{size}$`                               | $\textit{size}$                       |

#### Yêu cầu định dạng bổ sung đối với công thức toán

Vui lòng lưu ý, mặc dù cú pháp nhập công thức nói trên giống hệ thống dàn trang LaTeX thực sự, **MathJax và LaTeX là hai thứ hoàn toàn không liên quan**, MathJax chỉ sử dụng một phần cú pháp tương tự LaTeX. Giữa hai bên có nhiều khác biệt chi tiết, và các khác biệt này thường làm công thức viết ra không dùng chung được giữa hai bên.

Vì **OI Wiki** đã phát triển công cụ xuất PDF dựa trên bộ máy dàn trang LaTeX, cần nhấn mạnh tính tương thích của công thức giữa MathJax và LaTeX. **Khi viết công thức toán trong Wiki, vui lòng lưu ý các điểm sau.**

Các quy tắc này đã nhân nhượng MathJax hết mức có thể. Công cụ xuất đã tương thích với một phần cách viết vốn chỉ xuất đúng trong MathJax.

-   <a id="MATH-2.1"></a>MATH-2.1: dùng `\begin{aligned} ... \end{aligned}` để biểu thị công thức cần nhiều dòng căn chỉnh;

-   <a id="MATH-2.2"></a>MATH-2.2: nếu các công thức cần nhiều dòng căn chỉnh này cần **đánh số**, dùng môi trường `align` hoặc `equation`;

-   <a id="MATH-2.3"></a>MATH-2.3: không dùng môi trường `split`, `eqnarray`;

-   <a id="MATH-2.4"></a>MATH-2.4: không dùng `\lt`, `\gt` để biểu thị dấu lớn hơn và nhỏ hơn; dùng trực tiếp `<`, `>`;

-   <a id="MATH-2.5"></a>MATH-2.5: không trực tiếp dùng `\\` để xuống dòng (công thức cần xuống dòng phải đặt trong `aligned` hoặc môi trường nhiều dòng khác);

-   <a id="MATH-2.6"></a>MATH-2.6: nếu muốn xuất ký hiệu LaTeX $\rm{\LaTeX}$, dùng `$\rm{\LaTeX}$`, thay vì `mathrm`; (`\LaTeX` trong hệ thống dàn trang TeX là lệnh không thể dùng trong math mode, còn `\mathrm` lại không thể dùng trong normal mode; ngoài ra, tuy lệnh `\text` xuất đúng trên TeX, trong MathJax tham số của lệnh `\text` sẽ được xuất nguyên dạng, không được escape theo lệnh);

-   <a id="MATH-2.7"></a>MATH-2.7: chữ tiếng Việt hoặc văn bản tự nhiên trong công thức toán **bắt buộc đặt trong lệnh `\text{}`**, còn biến, số, toán tử và tên hàm bắt buộc đặt ngoài lệnh `\text{}`. **Vui lòng không lồng công thức toán trong lệnh `\text{}`**;

-   <a id="MATH-2.8"></a>MATH-2.8: khi dùng môi trường `array`, cần lưu ý **số cột thực tế phải khớp với số ký hiệu căn chỉnh**. Ví dụ trong công thức dưới đây, dữ liệu thực tế có 3 cột (`&` là ký hiệu tách cột), vì vậy cần 3 ký hiệu căn chỉnh (`l`/`r`/`c` lần lượt biểu thị căn trái, căn phải, căn giữa).

    ```latex
    $$
    \begin{array}{lll}
    F_1=\{\frac{0}{1},&&\frac{1}{1}\}\\
    F_2=\{\frac{0}{1},&\frac{1}{2},&\frac{1}{1}\}\\
    \end{array}
    $$
    ```

#### Định dạng giả mã

Định dạng cụ thể của giả mã không có yêu cầu nghiêm ngặt; vui lòng tham khảo Introduction to Algorithms hoặc các bài báo học thuật. Lưu ý không viết thành Python.

<a id="PCOD-1"></a>PCOD-1: trong Wiki, giả mã được viết bằng LaTeX, toàn bộ nằm trong môi trường `array`, thụt lề dùng `$\qquad$`, mô tả bằng văn bản dùng `$\text$`, từ khóa dùng `$\textbf$`, biến nhiều chữ cái dùng `$\textit$`, phép gán dùng `$\gets$`.

Ví dụ tham khảo:

$$
\begin{array}{l}
\textbf{Đầu vào. } \text{Tập cạnh của đồ thị } e , \text{ trong đó mỗi phần tử của } e \text{ là } (u, v, w) \\
\text{ biểu thị một cạnh giữa } u \text{ và } v \text{ có trọng số } w . \\
\textbf{Đầu ra. } \text{Các cạnh của MST của đồ thị đầu vào}. \\
\textbf{Phương pháp. } \\
\begin{array}{ll} 
1 &  \textit{result} \gets \varnothing \\
2 &  \text{sắp xếp } e \text{ theo thứ tự không giảm của trọng số } w \\
3 &  \textbf{với mỗi } (u, v, w) \text{ trong } e \text{ đã sắp xếp} \\
4 &  \qquad \textbf{nếu } u \text{ và } v \text{ chưa liên thông trong DSU } \\
5 &  \qquad\qquad \text{hợp nhất } u \text{ và } v \text{ trong DSU} \\
6 &  \qquad\qquad \textit{result} \gets \textit{result}\;\bigcup\ \{(u, v, w)\} \\
7 &  \textbf{trả về } \textit{result}
\end{array}
\end{array}
$$

```latex
$$
\begin{array}{l}
\textbf{Đầu vào. } \text{Tập cạnh của đồ thị } e , \text{ trong đó mỗi phần tử của } e \text{ là } (u, v, w) \\
\text{ biểu thị một cạnh giữa } u \text{ và } v \text{ có trọng số } w . \\
\textbf{Đầu ra. } \text{Các cạnh của MST của đồ thị đầu vào}. \\
\textbf{Phương pháp. } \\
\begin{array}{ll} 
1 &  \textit{result} \gets \varnothing \\
2 &  \text{sắp xếp } e \text{ theo thứ tự không giảm của trọng số } w \\
3 &  \textbf{với mỗi } (u, v, w) \text{ trong } e \text{ đã sắp xếp} \\
4 &  \qquad \textbf{nếu } u \text{ và } v \text{ chưa liên thông trong DSU } \\
5 &  \qquad\qquad \text{hợp nhất } u \text{ và } v \text{ trong DSU} \\
6 &  \qquad\qquad \textit{result} \gets \textit{result}\;\bigcup\ \{(u, v, w)\} \\
7 &  \textbf{trả về } \textit{result}
\end{array}
\end{array}
$$
```

#### Yêu cầu định dạng của khối mã

Khối mã hiện được chia thành hai loại: đoạn mã và bài mẫu.

Về đoạn mã:

-   <a id="CODE-1.1"></a>CODE-1.1: nếu đoạn mã đủ ngắn và không cần thiết phải kiểm thử, có thể sửa trực tiếp trong tài liệu Markdown.
-   <a id="CODE-1.2"></a>CODE-1.2: vì mã nhúng trong tài liệu Markdown khó tự động hóa kiểm thử, nên dùng định dạng mã bài mẫu để chèn đoạn mã. Có thể chọn [phương án biên dịch nhiều tệp](https://github.com/OI-wiki/OI-wiki/pull/5729) hoặc cú pháp [đoạn mã theo vùng](https://facelessuser.github.io/pymdown-extensions/extensions/snippets/#snippet-sections):

    Ví dụ về phương án biên dịch nhiều tệp: [sắp xếp nổi bọt](https://github.com/OI-wiki/OI-wiki/blob/c35defebff6cea072d6cfeb359642f6fd84e66c7/docs/basic/bubble-sort.md?plain=1#L48). Phần thân bài dẫn [bubble-sort\_1.cpp](https://github.com/OI-wiki/OI-wiki/blob/c35defebff6cea072d6cfeb359642f6fd84e66c7/docs/basic/code/bubble-sort/bubble-sort_1.cpp), mã kiểm thử đặt trong [bubble-sort\_1.aux1.cpp](https://github.com/OI-wiki/OI-wiki/blob/c35defebff6cea072d6cfeb359642f6fd84e66c7/docs/basic/code/bubble-sort/bubble-sort_1.aux1.cpp).

    Ví dụ về đoạn mã theo vùng: [tổng tiền tố](https://github.com/OI-wiki/OI-wiki/blob/c7cf6d6de13b44757f1d0528e952349beb921f8a/docs/basic/prefix-sum.md?plain=1#L37). Trong phần thân bài không cần dẫn phần kiểm thử trong [prefix-sum\_1.cpp](https://github.com/OI-wiki/OI-wiki/blob/c7cf6d6de13b44757f1d0528e952349beb921f8a/docs/basic/code/prefix-sum/prefix-sum_1.cpp), nên chọn chèn đoạn mã chính.

    **Lưu ý**: không dùng cú pháp [đoạn mã theo dòng](https://facelessuser.github.io/pymdown-extensions/extensions/snippets/#snippet-lines).

    Để tăng tỷ lệ tái sử dụng mã, cũng có thể tách mã thành tệp tiêu đề và khi kiểm thử thì dẫn vào các mã kiểm thử khác nhau. Nếu phần thân bài cần xuất hiện đầy đủ mã kiểm thử làm hiện thực tham khảo cho bài mẫu, trong phần thân bài nên dùng riêng cú pháp đoạn mã theo vùng để ghép thành mã một tệp, để người đọc dễ đọc. Ví dụ: [cây đỏ-đen](https://github.com/OI-wiki/OI-wiki/blob/3b721e22ea60d59a2687a9b10555263de7bdc2f0/docs/ds/rbtree.md?plain=1#L218-L231).

Về mã bài mẫu:

-   <a id="CODE-2.1"></a>CODE-2.1: hình thức biểu diễn của mã bài mẫu là `--8<-- "path"`, và mã đều được lưu trong `path`. Đường dẫn thường là `docs/chu-de/code/noi-dung/noi-dung_so-thu-tu.cpp`.

-   <a id="CODE-2.2"></a>CODE-2.2: khi sửa mã bài mẫu, cần bảo đảm mã đúng. Mã bài mẫu đều có một bộ dữ liệu kiểm thử, được lưu trong `/docs/chu-de/examples/noi-dung/noi-dung_so-thu-tu.in/ans`.

Nếu cần thêm bài mẫu:

-   Thêm mã bài mẫu vào `docs/chu-de/code/noi-dung` và đánh số. Thông thường, thư mục `noi-dung` này đã có một hoặc nhiều đoạn mã. Ví dụ: nếu cần sửa mã của `dag.md`, đường dẫn là `docs/dp/code/dag`, trong đó `dp` là chủ đề, còn `dag` là nội dung.

-   Nếu cần thêm một mã bài mẫu vào cuối tất cả bài mẫu, tăng tiếp số thứ tự hiện tại. Ví dụ đã tồn tại `code/prefix-sum/prefix-sum_3.cpp`; nếu cần thêm một bài mẫu sau bài mẫu cuối cùng, đặt tên mã mới là `prefix-sum_4.cpp` và thêm vào `docs/basic/code/prefix-sum`.

-   Nếu cần thêm một mã bài mẫu vào giữa bài viết, cần chèn và thay đổi số thứ tự cũ. Ví dụ đã tồn tại `prefix-sum_2.cpp` và `prefix-sum_3.cpp`; nếu cần chèn một bài mẫu giữa bài mẫu thứ hai và bài mẫu thứ ba, đặt tên mã mới là `prefix-sum_3.cpp`, đổi tên `prefix-sum_3.cpp` cũ thành `prefix-sum_4.cpp`, đồng thời **sửa đồng bộ số thứ tự trong tài liệu Markdown và thư mục lưu dữ liệu kiểm thử**.

-   **Đừng quên thêm một bộ dữ liệu kiểm thử cho mã để bảo đảm mã có thể chạy thành công.** Cần thêm một bộ dữ liệu kiểm thử vào thư mục `docs/chu-de/examples/noi-dung`, lưu dữ liệu vào thành `noi-dung_so-thu-tu.in` và lưu đáp án chuẩn thành `noi-dung_so-thu-tu.ans`.

-   Cuối cùng, có thể thêm mã vào tài liệu. Dùng trực tiếp định dạng thêm khối mã trong tài liệu, và viết trực tiếp bên trong khối mã theo định dạng `--8<-- "duong dan ma cua ban"`.

**OI Wiki** sẽ kiểm thử mã bài mẫu trên tất cả nền tảng. Để bảo đảm mã có thể vượt qua kiểm thử thuận lợi, vui lòng tuân thủ các quy tắc sau:

-   <a id="CODE-3.1"></a>CODE-3.1: mã cần hỗ trợ biên dịch và chạy đồng thời theo các chuẩn C++14, C++17, C++20.
-   <a id="CODE-3.2"></a>CODE-3.2: không dùng các tệp tiêu đề không chuẩn như `<bits/stdc++.h>`, `<bits/extc++.h>`.
-   <a id="CODE-3.3"></a>CODE-3.3: tệp đáp án chuẩn không được có khoảng trắng thừa.
-   <a id="CODE-3.4"></a>CODE-3.4: không dùng [alternative tokens](https://en.cppreference.com/w/cpp/language/operator_alternative#Alternative_tokens).
-   <a id="CODE-3.5"></a>CODE-3.5: khi dùng [aggregate initialization](https://en.cppreference.com/w/cpp/language/aggregate_initialization), không được viết `object{args}` thành `(object){args}`.
-   <a id="CODE-3.6"></a>CODE-3.6: khi dùng [nạp chồng toán tử](https://en.cppreference.com/w/cpp/language/operators),
    cần lưu ý định dạng; ví dụ khi nạp chồng toán tử so sánh, nếu dùng cách viết
    hàm thành viên thì không được bỏ từ định danh `const`.
-   <a id="CODE-3.7"></a>CODE-3.7: không dùng macro giống `#define int long long`.
-   <a id="CODE-3.8"></a>CODE-3.8: nếu cần dùng [nhập/xuất có định dạng](https://en.cppreference.com/w/cpp/io/c#Formatted_input.2Foutput)
    kiểu C, cần đặc biệt lưu ý cách viết đặc tả định dạng: ví dụ `size_t` tương
    ứng `%zu`, `ptrdiff_t` tương ứng `%td`. Ví dụ khi xuất kích thước của một bộ
    chứa STL, mã nên tương tự `printf("%zu", container.size());`.
-   <a id="CODE-3.9"></a>CODE-3.9: do thư viện `<chrono>` của libstdc++ trong môi trường kiểm thử hiện tại có [BUG](https://github.com/actions/runner-images/issues/8659), vui lòng tránh dùng thư viện `<chrono>`.
-   <a id="CODE-3.10"></a>CODE-3.10: do `long` và `unsigned long` là 32 bit trong một số môi trường kiểm thử, nhưng là 64 bit trong một số môi trường khác, để bảo đảm hành vi mã nhất quán trên mọi nền tảng, không khuyến nghị dùng hai kiểu này. Nên dùng [kiểu số nguyên có độ rộng cố định](../lang/var.md#kiểu-số-nguyên-có-độ-rộng-cố-định).
-   <a id="CODE-3.11"></a>CODE-3.11: không khuyến nghị dùng các nội dung không chuẩn như `__gcd`, `__int128`, các hàm dòng `__builtin_`. Nếu cần dùng, cần bảo đảm mã vượt qua kiểm thử trên tất cả nền tảng; ví dụ [đoạn mã này](https://github.com/OI-wiki/OI-wiki/blob/4af83d6db6017f4c36db6d4a7583bbc3f6257484/docs/ds/code/tree-decompose/tree-decompose_1.cpp#L24-L47) cung cấp hiện thực đa nền tảng cho hàm thành viên `_Find_first()` đặc thù của [std::bitset](../lang/csl/bitset.md) trong libstdc++.

Ngoài ra, để nâng cao khả năng đọc của mã, nên tuân thủ [CONT-10](#CONT-10).

## <a id="hinh-minh-hoa"></a>Hình minh họa

Có thể các yêu cầu trên hơi khó nắm bắt, nên phần tiếp theo đưa ra một số hình ảnh để phân tích cụ thể nên dùng định dạng nào và không nên dùng định dạng nào:

### Ví dụ 1

![](./images/format-1.png)

Dùng định dạng hiển thị riêng dòng cho công thức LaTeX phức tạp có thể làm trang sáng sủa và cân đối hơn. Với bản tiếng Việt, phần lớn thông tin có tính dàn ý (như tiêu đề) nên ưu tiên dùng tiếng Việt rõ nghĩa, trừ các thuật ngữ riêng hoặc tên chuẩn tiếng Anh thật sự cần giữ nguyên.

### Ví dụ 2

![](./images/format-2.png)

Với công thức LaTeX phức tạp hơn, cần lưu ý căn chỉnh dấu bằng; đồng thời có thể dẫn liên kết **Wiki** phù hợp để bổ sung nội dung.

### Ví dụ 3

![](./images/format-3.png)

Thông thường, nên liệt kê tài liệu được dẫn ở mục `## Tài liệu tham khảo và chú thích` cuối bài, và thêm footnote sau câu gốc thay vì đưa trực tiếp liên kết. Đồng thời nhất định phải tránh dùng công thức LaTeX để biểu diễn mã; hai cặp ngoặc vuông trong hình là cách viết không đúng quy chuẩn. Nên dùng `dp(i,j)` hoặc `dp_{i,j}`.

### Ví dụ 4

![](./images/format-4.png)

Lưu ý khi mô tả **phép nhân**, thường dùng `\times` hoặc `\cdot`; trong trường hợp đặc biệt (như convolution) sẽ dùng `*` (cũng có thể viết là `\ast`). Tiêu đề là cụm từ ngắn gọn, nhưng phần thân bài không nên được ghép lại từ các cụm từ rời rạc. Trong hình, cụm "hai yếu tố" nên đổi thành "nguyên lý của quy hoạch động có hai yếu tố sau" để giữ mạch văn bản liên tục. Điểm đáng học tập là: dùng **danh sách có thứ tự** một cách phù hợp có thể giúp trình bày nội dung mạch lạc hơn. Nhắc lại lần nữa, khi dùng danh sách, nếu mỗi mục là một câu thì cần thêm **dấu câu** ở cuối mục. Danh sách có thứ tự thường thêm dấu chấm phẩy, và thêm dấu chấm câu ở cuối mục cuối cùng; danh sách không thứ tự thống nhất thêm dấu chấm câu.

### Ví dụ 5

![](./images/format-5.png)

Dẫn **hình ảnh** phù hợp có thể tăng khả năng đọc của bài viết. Dùng **giả mã** để biểu diễn quá trình thuật toán có thể mô tả thuật toán tiện lợi và ngắn gọn, dễ hiểu hơn so với dẫn trực tiếp mã mẫu.

### Ví dụ 6

![](./images/format-6.png)

Vẫn là vấn đề cũ: tiêu đề dùng tiếng Anh, và sau khi dùng ngoặc lại không có dấu chấm câu. Ngoài ra, công thức hiển thị riêng dòng trong hình tuy không dùng ngoặc, nhưng do lồng chỉ số dưới quá nhiều tầng, font của chỉ số dưới tầng thấp nhất rất nhỏ và toàn bộ công thức cũng không đẹp. Nên thay `son_{now,i}` bằng `son(now,i)`, hoặc thay `f_{now}` bằng `f(now)`. Nên cố gắng không lồng chỉ số trên/dưới quá hai tầng (khi cần lồng chỉ số trên nhiều lần, nên dùng mũi tên Knuth, ví dụ dùng $2 \uparrow (2 \uparrow (2 \uparrow (2 \uparrow \cdots)))$ thay cho $2^{2^{2^{2^{\cdots}}}}$, bài "Bảy phút Chúa tạo đề").

### Ví dụ 7

![](./images/format-7.png)

Dùng cú pháp mở rộng MkDocs để tách đề bài mẫu khỏi mô tả thuật toán. Gấp mã lại có thể làm bài viết gọn hơn. (Suy cho cùng, phần lớn người đọc Wiki là để hiểu ý tưởng; ngoài mã mẫu cần đọc, mã của bài tập phần lớn có thể gấp lại.) Khi mô tả thao tác hàm, dùng mã trong dòng và công thức LaTeX đều là lựa chọn tốt.

### Ví dụ 8

![](./images/format-8.png)

Liệt kê tài liệu tham khảo ở cuối bài có thể làm nội dung trang nghiêm túc, xác thực và đáng tin hơn.

## Liên kết ngoài

-   [Wikipedia tiếng Việt: Cẩm nang biên soạn](https://vi.wikipedia.org/wiki/Wikipedia:C%E1%BA%A9m_nang_bi%C3%AAn_so%E1%BA%A1n)
-   [Wikipedia: cẩm nang văn phong/dấu câu](https://en.wikipedia.org/wiki/Wikipedia:Manual_of_Style#Punctuation)
-   [Quy chuẩn phong cách tài liệu dành cho nhà phát triển của Google](https://developers.google.com/style)
-   [Hướng dẫn Markdown: cú pháp cơ bản](https://www.markdownguide.org/basic-syntax/)
-   [Sổ tay tham khảo không chính thức LaTeX2e](https://latexref.xyz/)

## Tài liệu tham khảo và chú thích

[^note1]: Dấu hai chấm biểu thị việc tổng kết nội dung phía trước.

[^note2]: Giữa tên đầy đủ bằng tiếng Anh của thuật ngữ khoa học kỹ thuật và dạng viết tắt của nó nên dùng dấu phẩy tiếng Anh. Khi trong câu tiếng Việt có chèn câu hoặc cụm câu tiếng Anh để chú thích, bổ sung hoặc giải thích, đặt phần đó trong ngoặc tròn nửa chiều rộng.

[^note3]: Hộp gấp: xem [khối có thể gấp](https://squidfunk.github.io/mkdocs-material/reference/admonitions/#collapsible-blocks). Đôi khi "cú pháp `<details>`" cũng được dùng để chỉ cú pháp này, vì về chức năng nó giống với [phần tử `<details>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Reference/Elements/details) trong HTML.

[^note4]: Đã chuyển đến [Cách đóng góp](./htc.md).

[^note5]: Quy phạm này được viết vào [Những điều cần biết trước khi biên tập](../edit-landing.md) và đã công bố thông báo, nhưng không được viết vào tài liệu này.

[^note6]: Tab: xem [tab nội dung](https://squidfunk.github.io/mkdocs-material/reference/content-tabs).

[^ref1]: [cstdio stdio.h namespace](https://stackoverflow.com/questions/10460250/cstdio-stdio-h-namespace)

[^ref2]: [Thông báo của CCF về việc khôi phục kỳ thi NOIP - China Computer Federation](https://www.ccf.org.cn/c/2020-01-21/694716.shtml)

[^ref3]: [Vì sao công thức của tôi không hiển thị bình thường trong mục lục? Hình như bị nhân đôi](faq.md)

[^ref4]: [SVG | MDN](https://developer.mozilla.org/en-US/docs/Web/SVG)

[^webarchive]: [Lưu trang vào Internet Archive](https://web.archive.org/save/)

[^apng]: [APNG](https://en.wikipedia.org/wiki/APNG)

[^intro-apng]: [OI-wiki/OI-wiki#3422](https://github.com/OI-wiki/OI-wiki/issues/3422)
