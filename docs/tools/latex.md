## Giới thiệu

### LaTeX là gì

LaTeX (đọc là /ˈlɑːtɛx/ hoặc /ˈleɪtɛx/) là một hệ thống dàn trang giúp tài liệu của bạn trông chuyên nghiệp hơn, chứ không phải là một trình xử lý văn bản. Nó đặc biệt phù hợp với những tài liệu dài, có cấu trúc chặt chẽ, và rất mạnh trong việc trình bày công thức. Đây là phần mềm miễn phí và dùng được trên hầu hết các hệ điều hành.

LaTeX được xây dựng trên TeX, hệ thống dàn trang do Donald Knuth thiết kế năm 1978 cho chế bản số. TeX là một ngôn ngữ cấp thấp mà máy tính có thể xử lý, nhưng phần lớn người dùng thấy nó khó dùng. LaTeX được thiết kế để làm cho TeX dễ sử dụng hơn. Phiên bản LaTeX hiện nay là LaTeX 2e.

Nếu bạn quen dùng Microsoft Office Word để soạn tài liệu, cách làm việc của LaTeX có thể sẽ khá lạ. Word là trình soạn thảo kiểu "thấy gì được nấy", cho phép bạn xem ngay kết quả dàn trang cuối cùng trong khi chỉnh sửa tài liệu. Khi dùng LaTeX, bạn không xem kết quả cuối cùng một cách trực tiếp như vậy, nhờ đó có thể tập trung vào nội dung thay vì liên tục chỉnh hình thức.

Một tài liệu LaTeX là một tệp văn bản có đuôi `.tex`, có thể chỉnh sửa bằng bất kỳ trình soạn thảo văn bản nào, chẳng hạn Notepad. Tuy nhiên, với đa số người dùng, một trình soạn thảo LaTeX phù hợp sẽ giúp quá trình viết dễ hơn nhiều. Trong lúc soạn thảo, bạn đánh dấu cấu trúc của tài liệu. Khi hoàn thành, bạn biên dịch tài liệu, tức là chuyển nó sang một định dạng khác. LaTeX hỗ trợ nhiều định dạng, nhưng thông dụng nhất là PDF.

### Trước khi bắt đầu

Dưới đây là các ký hiệu được dùng trong bài:

-   Thao tác mà bạn cần thực hiện sẽ được đánh dấu bằng mũi tên $\rightarrow$;
-   Ký tự bạn cần nhập sẽ được đặt trong khối mã;
-   Tên lệnh trong menu và tên nút sẽ được đánh dấu **in đậm**.

### Một số khái niệm

Để viết tài liệu LaTeX, bạn cần cài một "bản phân phối". Các bản phân phối thường dùng gồm [TeX Live](http://tug.org/texlive/), [MikTeX](https://miktex.org/) và MacTeX dành cho người dùng macOS (thực chất là phiên bản TeX Live cho macOS). TeX Live và MacTeX đi kèm gần như toàn bộ các gói LaTeX; MikTeX chỉ đi kèm một số gói bắt buộc, các gói khác sẽ được cài khi cần.

TeX Live và MikTeX đều đi kèm trình soạn thảo TeXworks. Bạn cũng có thể cài trình soạn thảo nhiều tính năng hơn như TeXstudio, hoặc tự cấu hình Visual Studio Code, Notepad++ và các trình soạn thảo khác. Trình soạn thảo dùng trong phần dưới là TeXworks chạy trên Windows 7.

Phần lớn các bản phân phối đều có nhiều bộ máy, chẳng hạn pdfTeX, XeTeX và LuaTeX. Với văn bản Unicode nhiều dấu như tiếng Việt, XeTeX hoặc LuaTeX thường thuận tiện hơn.

TeX có nhiều định dạng, chẳng hạn Plain TeX và LaTeX. Hiện nay thường dùng định dạng LaTeX. Vì vậy, bạn cần dùng bộ máy được đóng gói cùng định dạng mà bạn sử dụng. Ví dụ với pdfTeX, bạn cần dùng pdfLaTeX; với XeTeX thì dùng XeLaTeX.

Đọc thêm: [Giới thiệu về bộ máy, định dạng và bản phân phối TeX](https://liam.page/2018/11/26/introduction-to-TeX-engine-format-and-distribution/).

### Cấu hình môi trường

Với người dùng Windows, bạn cần tải [TeX Live](https://tug.org/texlive/acquire.html) hoặc [MikTeX](https://miktex.org/download). Nếu tốc độ tải từ máy chủ mặc định không ổn định, có thể chọn một mirror CTAN gần vị trí của bạn. Bộ cài TeX Live dạng ISO cần được mount rồi chạy `install-tl-advanced.bat` bằng quyền quản trị.

Với người dùng macOS, có thể cài [MacTeX](https://tug.org/mactex/) hoặc MikTeX cho macOS.

Với người dùng Linux, nếu dùng TeX Live thì cũng tải tệp ISO và chạy script `install-tl`; nếu dùng MikTeX thì cài theo [tài liệu chính thức](https://miktex.org/download#unx).

## Cấu trúc tài liệu

### Thành phần cơ bản

$\rightarrow$ Mở TeXworks.

Một tài liệu mới sẽ tự động được mở.

$\rightarrow$ Vào menu **Format**, chọn **Line Numbers**.

Số dòng không phải là thành phần bắt buộc, nhưng nó giúp bạn đối chiếu mã với thông báo trên màn hình và tìm lỗi.

$\rightarrow$ Vào menu **Format**, chọn **Syntax Coloring**, rồi chọn **LaTeX**.

Tô màu cú pháp sẽ làm nổi bật mã, giúp mã dễ đọc hơn.

$\rightarrow$ Nhập văn bản sau:

```tex
\documentclass[a4paper, 12pt]{article}

\begin{document}
  A sentence of text.
\end{document}
```

Lệnh `\documentclass` phải xuất hiện ở đầu mỗi tài liệu LaTeX. Phần văn bản trong ngoặc nhọn chỉ định kiểu tài liệu. Kiểu tài liệu **article** phù hợp với các bài viết ngắn, chẳng hạn bài báo tạp chí và báo cáo ngắn. Các kiểu tài liệu khác gồm **report** (dùng cho tài liệu dài có nhiều chương, chẳng hạn luận án tiến sĩ), **proc** (kỷ yếu hội nghị), **book** và **beamer**. Phần văn bản trong ngoặc vuông chỉ định các tùy chọn. Trong ví dụ, nó đặt khổ giấy là A4 và cỡ chữ chính là 12pt.

Hai lệnh `\begin{document}` và `\end{document}` bao lấy phần nội dung văn bản của bạn. Mọi nội dung trước `\begin{document}` được xem là lệnh tiền tố và ảnh hưởng đến toàn bộ tài liệu. Mọi nội dung sau `\end{document}` đều bị bỏ qua.

Dòng trống không bắt buộc, nhưng nó giúp tài liệu dài dễ đọc hơn.

$\rightarrow$ Nhấn nút **Save**; $\rightarrow$ tạo một thư mục tên **LaTeX course** trong **Libraries>Documents**; $\rightarrow$ đặt tên tài liệu là **Doc1** và lưu nó dưới dạng **TeX document** trong thư mục này.

Đặt các tài liệu LaTeX khác nhau trong các thư mục khác nhau là một ý hay, nhất là khi cần ghép nhiều tệp trong lúc biên dịch.

$\rightarrow$ Bảo đảm menu typeset đang đặt thành **xeLaTeX**. $\rightarrow$ Nhấp nút **Typeset**.

Lúc này tệp nguồn của bạn sẽ được chuyển thành tài liệu PDF, quá trình này sẽ mất một ít thời gian. Sau khi biên dịch xong, trình xem PDF của TeXworks sẽ mở và hiển thị tệp đã tạo. Tệp PDF sẽ tự động được lưu trong cùng thư mục với tài liệu TeX.

### Xử lý sự cố

Nếu tài liệu có lỗi và TeXworks không thể tạo tài liệu PDF, nút **Typeset** sẽ biến thành dấu gạch chéo màu đỏ, đồng thời phần xuất của trình dòng lệnh ở phía dưới vẫn mở. Khi đó:

$\rightarrow$ Nhấp nút **Abort typesetting**. $\rightarrow$ Đọc nội dung xuất ra trong trình dòng lệnh; dòng cuối có thể cho biết số dòng nơi lỗi xuất hiện. $\rightarrow$ Tìm dòng tương ứng trong tài liệu và sửa lỗi. $\rightarrow$ Nhấp lại nút **Typeset** để thử biên dịch tệp nguồn.

### Thêm tiêu đề tài liệu

Lệnh `\maketitle` có thể tạo tiêu đề cho tài liệu. Bạn cần chỉ định tiêu đề của tài liệu. Nếu không chỉ định ngày tháng, LaTeX sẽ dùng thời điểm hiện tại; tác giả là tùy chọn.

$\rightarrow$ Ngay sau lệnh `\begin{document}`, nhập văn bản sau:

```tex
\title{My First Document}
\author{My Name}
\date{\today}
\maketitle
```

Tài liệu của bạn bây giờ trông như sau:

```tex
\documentclass[a4paper, 12pt]{article}

\begin{document}
  \title{My First Document}
  \author{My Name}
  \date{\today}
  \maketitle

  A sentence of text.
\end{document}
```

$\rightarrow$ Nhấp nút **Typeset** và kiểm tra tài liệu PDF đã tạo.

Ghi chú chính:

-   `\today` là lệnh chèn ngày hiện tại. Bạn cũng có thể nhập một ngày khác, chẳng hạn `\date{November 2013}`.
-   Phần thân của tài liệu **article** sẽ được dàn ngay sau tiêu đề trên cùng một trang. **report** sẽ đặt tiêu đề ở một trang riêng.

### Chương mục

Nếu cần, bạn có thể chia tài liệu thành chương, mục và tiểu mục. Các lệnh chia mục sau dùng được cho tài liệu kiểu **article**:

-   `\section{...}`
-   `\subsection{...}`
-   `\subsubsection{...}`
-   `\paragraph{...}`
-   `\subparagraph{...}`

Phần văn bản trong ngoặc nhọn là tiêu đề của chương mục. Với tài liệu kiểu **report** và **book**, LaTeX còn hỗ trợ lệnh `\chapter{...}`.

$\rightarrow$ Thay "A sentence of text." bằng văn bản sau:

```tex
\section{Introduction}
This is the introduction.

\section{Methods}

\subsection{Stage 1}
The first part of the methods.

\subsection{Stage 2}
The second part of the methods.

\section{Results}
Here are my results.
```

Tài liệu của bạn sẽ trở thành:

```tex
\documentclass[a4paper, 12pt]{article}

\begin{document}
  \title{My First Document}
  \author{My Name}
  \date{\today}
  \maketitle

  \section{Introduction}
  This is the introduction.

  \section{Methods}

  \subsection{Stage 1}
  The first part of the methods.

  \subsection{Stage 2}
  The second part of the methods.

  \section{Results}
  Here are my results.
\end{document}
```

$\rightarrow$ Nhấp nút **Typeset** và kiểm tra tài liệu PDF. Kết quả sẽ trông như sau:

![Tài liệu LaTeX đầu tiên sau khi biên dịch](images/latex-for-beginners-1.png)

### Tạo nhãn

Bạn có thể tạo nhãn cho bất kỳ lệnh chương mục nào để tham chiếu đến chúng ở phần khác của tài liệu. Dùng `\label{labelname}` để tạo nhãn cho chương mục. Sau đó nhập `\ref{labelname}` hoặc `\pageref{labelname}` để tham chiếu đến chương mục tương ứng.

$\rightarrow$ Xuống một dòng ngay dưới `\subsection{Stage 1}` và nhập `\label{sec1}`. $\rightarrow$ Trong mục **Results**, nhập `Referring to section \ref{sec1} on page \pageref{sec1}`.

Tài liệu của bạn sẽ trở thành:

```tex
\documentclass[a4paper, 12pt]{article}

\begin{document}
  \title{My First Document}
  \author{My Name}
  \date{\today}
  \maketitle

  \section{Introduction}
  This is the introduction.

  \section{Methods}

  \subsection{Stage 1}
  \label{sec1} The first part of the methods.

  \subsection{Stage 2}
  The second part of the methods.

  \section{Results}
  Here are my results. Referring to section \ref{sec1} on page \pageref{sec1}
\end{document}
```

$\rightarrow$ Biên dịch và kiểm tra tài liệu PDF. Có thể bạn cần biên dịch liên tiếp hai lần:

![Kết quả tham chiếu nhãn và số trang trong LaTeX](images/latex-for-beginners-2.png)

### Tạo mục lục (TOC)

Nếu dùng các lệnh chia mục, bạn có thể dễ dàng tạo mục lục. Dùng `\tableofcontents` để tạo mục lục trong tài liệu. Thông thường, mục lục được đặt ngay sau tiêu đề.

Bạn cũng có thể muốn đổi số trang sang chữ số La Mã (i,ii,iii). Việc này bảo đảm phần nội dung chính của tài liệu bắt đầu từ trang 1. Có thể dùng `\pagenumbering{...}` để chuyển đổi giữa số Ả Rập và số La Mã.

$\rightarrow$ Sau `\maketitle`, nhập nội dung sau:

```tex
\pagenumbering{roman}
\tableofcontents
\newpage
\pagenumbering{arabic}
```

Lệnh `\newpage` sẽ bắt đầu một trang mới, nhờ đó ta có thể thấy ảnh hưởng của lệnh `\pagenumbering`. 14 dòng đầu của tài liệu sẽ trông như sau:

```tex
\documentclass[a4paper, 12pt]{article}

\begin{document}

\title{My First Document}
\author{My Name}
\date{\today}
\maketitle

\pagenumbering{roman}
\tableofcontents
\newpage
\pagenumbering{arabic}
```

$\rightarrow$ Biên dịch và kiểm tra tài liệu. Có thể cần biên dịch nhiều lần; phần dưới sẽ không nhắc lại nữa.

Trang đầu của tài liệu trông như sau:

![Trang đầu của tài liệu có mục lục](images/latex-for-beginners-3.png)

Trang thứ hai:

![Trang nội dung sau mục lục trong tài liệu LaTeX](images/latex-for-beginners-4.png)

## Xử lý văn bản

### Hỗ trợ tiếng Việt và Unicode

Với người đọc bài này để học LaTeX, một trong những điều đầu tiên cần nắm là cách soạn văn bản Unicode có dấu. Cách gọn và dễ kiểm soát là dùng XeLaTeX hoặc LuaLaTeX cùng gói `fontspec`, rồi chọn một phông chữ có hỗ trợ tiếng Việt:

```tex
\usepackage{fontspec}
\setmainfont{TeX Gyre Termes}
```

Khi biên dịch tài liệu, hãy dùng `xelatex` hoặc `lualatex`. Nếu đổi sang phông chữ khác, cần bảo đảm phông chữ đó có đủ các dấu tiếng Việt.

### Hiệu ứng phông chữ

LaTeX có nhiều hiệu ứng phông chữ khác nhau. Dưới đây là một số ví dụ:

```tex
\textit{words in italics} \textsl{words slanted} \textsc{words in smallcaps} \textbf{words
in bold} \texttt{words in teletype} \textsf{sans serif words} \textrm{roman
words} \underline{underlined words}
```

Kết quả như sau:

![Ví dụ các hiệu ứng phông chữ trong LaTeX](images/latex-for-beginners-5.png)

$\rightarrow$ Thêm nhiều văn bản hơn vào tài liệu của bạn và thử các hiệu ứng phông chữ khác nhau.

### Chữ màu

Để tài liệu hỗ trợ chữ màu, bạn cần dùng gói lệnh. Bạn có thể nạp nhiều gói lệnh để tăng cường khả năng dàn trang của LaTeX. Lệnh nạp gói được đặt trong phần lệnh tiền tố của tài liệu, tức là trước lệnh `\begin{document}`. Dùng `\usepackage[options]{package}` để nạp gói. Trong đó, **package** là tên gói, còn **options** là các tham số chỉ định đặc tính của gói.

Sau khi dùng `\usepackage{color}`, chúng ta có thể gọi các màu thường gặp:

![Các màu chữ thường gặp trong LaTeX](images/latex-for-beginners-6.png)

Mã dùng chữ màu là:

```tex
{\color{colorname}text}
```

Trong đó **colorname** là tên màu bạn muốn dùng, còn **text** là nội dung văn bản có màu. Lưu ý rằng trong hình ví dụ, chữ màu vàng và trắng có màu nền; điều này cũng có thể thực hiện bằng lệnh `\colorbox` trong gói Color. Cách dùng như sau:

```tex
\colorbox{colorname}{text}
```

$\rightarrow$ Trước `\begin{document}`, nhập `\usepackage{color}`. $\rightarrow$ Trong nội dung tài liệu, nhập `{\color{red}fire}`. $\rightarrow$ Biên dịch và kiểm tra nội dung tài liệu PDF.

Từ fire sẽ có màu đỏ.

Bạn cũng có thể thêm tham số để gọi thêm nhiều màu hơn, thậm chí tự định nghĩa màu cần dùng. Tuy nhiên phần này nằm ngoài phạm vi của sách. Nếu muốn tìm hiểu thêm về văn bản có màu, hãy đọc chương [Colors](http://en.wikibooks.org/wiki/LaTeX/Colors) của LaTeX Wikibook.

### Cỡ chữ

Tiếp theo là một số lệnh đặt cỡ chữ trong LaTeX:

```tex
normal size words {\tiny tiny words} {\scriptsize scriptsize words}
{\footnotesize footnotesize words} {\small small words} {\large large words}
{\Large Large words} {\LARGE LARGE words} {\huge huge words}
```

Kết quả như sau:

![Ví dụ các cỡ chữ trong LaTeX](images/latex-for-beginners-7.png)

$\rightarrow$ Thử điều chỉnh cỡ chữ cho văn bản của bạn.

### Thụt đầu dòng đoạn văn

Theo mặc định, trong LaTeX, dòng đầu của đoạn đầu tiên trong mỗi chương mục không thụt vào, còn các đoạn sau thì thụt dòng đầu. Nếu muốn một đoạn không thụt đầu dòng, hãy thêm lệnh `\noindent` trước đoạn đó. Nếu muốn tất cả các đoạn từ một vị trí trở đi đều không thụt đầu dòng, dùng lệnh `\setlength{\parindent}{0pt}` tại vị trí đó trong tài liệu.

### Danh sách

LaTeX hỗ trợ hai kiểu danh sách: danh sách có thứ tự (enumerate) và danh sách không thứ tự (itemize). Mỗi phần tử trong danh sách được định nghĩa bằng `\item`. Danh sách có thể chứa danh sách con.

$\rightarrow$ Nhập nội dung dưới đây để tạo một danh sách có thứ tự lồng danh sách không thứ tự:

```tex
\begin{enumerate}
  \item First thing

  \item Second thing
    \begin{itemize}
      \item A sub-thing

      \item Another sub-thing
    \end{itemize}

  \item Third thing
\end{enumerate}
```

$\rightarrow$ Biên dịch và kiểm tra tài liệu PDF.

Danh sách trông như sau:

![Danh sách có thứ tự lồng danh sách không thứ tự trong LaTeX](images/latex-for-beginners-8.png)

Có thể dùng tham số trong ngoặc vuông để thay đổi ký hiệu đầu dòng của danh sách không thứ tự. Ví dụ, `\item[-]` sẽ dùng dấu gạch làm ký hiệu; bạn thậm chí có thể dùng một từ, chẳng hạn `\item[One]`.

Đoạn mã sau:

```tex
\begin{itemize}
  \item[-] First thing

  \item[+] Second thing
    \begin{itemize}
      \item[Fish] A sub-thing

      \item[Plants] Another sub-thing
    \end{itemize}

  \item[Q] Third thing
\end{itemize}
```

tạo ra kết quả:

![Danh sách không thứ tự với ký hiệu đầu dòng tùy chỉnh](images/latex-for-beginners-9.png)

### Chú thích và khoảng trắng

Chúng ta dùng `%` để tạo chú thích một dòng. Mọi nội dung trên cùng dòng sau ký tự này sẽ bị bỏ qua cho đến khi bắt đầu dòng tiếp theo.

Đoạn mã sau:

```tex
It is a truth universally acknowledged% Note comic irony
in the very first sentence , that a single man in possession of a good fortune,
must be in want of a wife.
```

tạo ra kết quả:

![Kết quả xử lý chú thích và khoảng trắng trong LaTeX](images/latex-for-beginners-10.png)

Nhiều khoảng trắng liên tiếp trong LaTeX được xem như một khoảng trắng. Nhiều dòng trống liên tiếp được xem như một dòng trống. Chức năng chính của dòng trống là bắt đầu một đoạn mới. Nói chung, LaTeX bỏ qua dòng trống và các ký tự khoảng trắng khác; hai dấu gạch chéo ngược (`\\`) có thể được dùng để xuống dòng.

$\rightarrow$ Thử thêm chú thích và dòng trống vào tài liệu của bạn.

Nếu muốn thêm khoảng cách trong tài liệu, bạn có thể dùng lệnh `\vspace{...}`. Lệnh này thêm khoảng cách theo chiều dọc, với chiều cao có thể chỉ định. Ví dụ `\vspace{12pt}` sẽ tạo một khoảng trống có chiều cao bằng chiều cao của chữ cỡ 12pt.

### Ký tự đặc biệt

Các ký tự sau là ký tự đặc biệt trong LaTeX:

```text
# $ % ^ & _ { } ~ \
```

Để dùng các ký tự này, ta cần thêm dấu gạch chéo ngược phía trước chúng để escape:

```tex
\# \$ \% \^{} \& \_ \{ \} \~{}
```

Lưu ý rằng khi dùng ký tự `^` và `~`, bạn cần đặt ngay sau đó một cặp ngoặc nhọn đóng mở; nếu không, chúng sẽ được hiểu là dấu phía trên chữ cái, giống như `\^ e` sẽ trở thành $\mathrm {\hat{e}}$. Đoạn mã trên tạo ra kết quả sau:

![Kết quả escape các ký tự đặc biệt trong LaTeX](images/latex-for-beginners-11.png)

Lưu ý rằng dấu gạch chéo ngược không thể escape bằng chính dấu gạch chéo ngược, vì như vậy nó sẽ trở thành lệnh xuống dòng; hãy dùng lệnh `\textbackslash` thay thế.

$\rightarrow$ Nhập mã để tạo nội dung sau trong tài liệu của bạn:

![Bài thực hành nhập ký tự đặc biệt trong LaTeX](images/latex-for-beginners-12.png)

Hãy hỏi chuyên gia hoặc xem [mã nguồn](https://github.com/OI-wiki/OI-wiki/blob/master/docs/tools/latex.md?plain=1) của trang này để được trợ giúp.

## Bảng

Lệnh bảng (tabular) dùng để dàn trang bảng. Theo mặc định, bảng trong LaTeX không có đường phân cách ngang và dọc; nếu cần, bạn phải tự đặt. LaTeX sẽ tự động đặt chiều rộng bảng theo nội dung. Đoạn mã sau có thể tạo một bảng:

```tex
\begin{tabular}{...}
```

Dấu ba chấm sẽ được thay bằng mã định nghĩa các cột của bảng:

-   `l` biểu thị một cột căn trái;
-   `r` biểu thị một cột căn phải;
-   `c` biểu thị một cột căn giữa;
-   `|` biểu thị đường kẻ dọc của một cột;

Ví dụ, `{lll}` sẽ tạo một bảng ba cột, tất cả đều căn trái và không có đường kẻ dọc rõ ràng; `{|l|l|r|}` sẽ tạo một bảng ba cột, hai cột đầu căn trái, cột cuối căn phải, và có đường kẻ dọc rõ ràng giữa các cột liền kề.

Dữ liệu của bảng được nhập sau `\begin{tabular}`:

-   `&` dùng để tách cột;
-   `\\` dùng để xuống dòng;
-   `\hline` biểu thị việc chèn một đường phân cách ngang chạy qua tất cả các cột;
-   `\cline{1-2}` sẽ chèn một đường phân cách ngang ở cột thứ nhất và cột thứ hai.

Cuối cùng, dùng `\end{tabular}` để kết thúc bảng. Một vài ví dụ:

```tex
\begin{tabular}{|l|l|}
  Apples       & Green  \\
  Strawberries & Red    \\
  Orange       & Orange \\
\end{tabular}

\begin{tabular}{rc}
  Apples              & Green  \\
  \hline
  Strawberries        & Red    \\
  \cline{1-1} Oranges & Orange \\
\end{tabular}

\begin{tabular}{|r|l|}
  \hline
  8              & here's \\
  \cline{2-2} 86 & stuff  \\
  \hline
  \hline
  2008           & now    \\
  \hline
\end{tabular}
```

Kết quả như sau:

![Bảng được tạo bằng môi trường tabular](images/latex-for-beginners-13.png)

### Thực hành

Hãy thử vẽ bảng sau:

![Bài thực hành tạo bảng trong LaTeX](images/latex-for-beginners-14.png)

## Hình ảnh

Chương này giới thiệu cách chèn hình ảnh vào tài liệu LaTeX. Ở đây chúng ta cần nạp gói **graphicx**. Hình ảnh nên là tệp PDF, PNG, JPEG hoặc GIF. Đoạn mã sau sẽ chèn một hình tên myimage:

```tex
\begin{figure}[h]
  \centering
  \includegraphics[width=1\textwidth]{myimage}
  \caption{Here is my image}
  \label{image-myimage}
\end{figure}
```

`[h]` là tham số vị trí; **h** nghĩa là đặt hình ảnh xấp xỉ tại đây, nếu có đủ chỗ. Các tùy chọn khác gồm: **t** nghĩa là đặt ở đầu trang; **b** nghĩa là đặt ở cuối trang; **p** nghĩa là đặt hình ảnh ở một trang riêng. Bạn cũng có thể thêm tham số **!** để ép đặt ở vị trí do tham số chỉ định, mặc dù kết quả dàn trang có thể không đẹp.

`\centering` đặt hình ảnh ở giữa trang. Nếu không có lệnh này, hình sẽ mặc định căn trái. Dùng lệnh này thường cho kết quả tốt, vì tiêu đề hình ảnh cũng được căn giữa.

Lệnh `\includegraphics{...}` có thể tự động đặt hình vào tài liệu của bạn; tệp ảnh nên nằm cùng thư mục với tệp TeX.

`[width=1\textwidth]` là tham số tùy chọn chỉ định chiều rộng của hình, ở đây bằng chiều rộng phần văn bản. Chiều rộng cũng có thể được đặt theo đơn vị xentimét. Bạn cũng có thể dùng `[scale=0.5]` để thu nhỏ hình theo tỷ lệ; ví dụ này tương đương thu nhỏ một nửa.

`\caption{...}` định nghĩa tiêu đề của hình ảnh. Nếu dùng lệnh này, LaTeX sẽ thêm số thứ tự bắt đầu bằng "Figure" ("Hình") cho hình ảnh của bạn. Bạn có thể dùng `\listoffigures` để tạo danh mục hình ảnh.

`\label{...}` tạo một nhãn để bạn có thể tham chiếu.

### Thực hành

$\rightarrow$ Thêm `\usepackage{graphicx}` vào phần lệnh tiền tố của tài liệu. $\rightarrow$ Tìm một hình ảnh và đặt nó trong thư mục **LaTeX course** của bạn. $\rightarrow$ Tại nơi bạn muốn chèn hình, nhập nội dung sau:

```tex
\begin{figure}[h!]
  \centering
  \includegraphics[width=1\textwidth]{ImageFilename}
  \caption{My test image}
\end{figure}
```

Thay **ImageFilename** bằng tên tệp của bạn, không bao gồm phần mở rộng. Nếu tên tệp có khoảng trắng, hãy dùng dấu nháy kép bao quanh, chẳng hạn `"screen 20"`.

$\rightarrow$ Biên dịch và kiểm tra tệp.

## Công thức

Một trong những lý do chính để dùng LaTeX là nó có thể dàn công thức rất thuận tiện. Chúng ta dùng chế độ toán học để dàn công thức.

### Chèn công thức

Bạn có thể dùng một cặp `$` để bật chế độ toán học; cách này dùng để viết công thức toán trong dòng. Ví dụ `$1+2=3$` tạo ra kết quả $1+2=3$.

Nếu muốn công thức hiển thị riêng dòng, có thể dùng `$$...$$`; hiện nay chúng tôi khuyến nghị dùng `\[...\]`, vì cách trước có thể tạo khoảng cách không tốt. Ví dụ, `$$1+2=3$$` tạo ra kết quả:

$$
1+2=3
$$

Nếu muốn tạo công thức có đánh số, có thể dùng `\begin{equation}...\end{equation}`. Ví dụ:

```tex
\begin{equation}
  1+2=3
\end{equation}
```

tạo ra kết quả:

![Công thức có đánh số bằng môi trường equation](images/latex-equation.svg)

Số 6 là số thứ tự của chương, chỉ xuất hiện khi tài liệu của bạn có đặt chương, chẳng hạn tài liệu kiểu **report**.

Dùng `\begin{eqnarray}...\end{eqnarray}` để viết một nhóm công thức có đánh số. Ví dụ:

```tex
\begin{eqnarray}
  a & = & b + c \\
  & = & y - z
\end{eqnarray}
```

tạo ra kết quả:

![Nhóm công thức có đánh số bằng môi trường eqnarray](images/latex-eqnarray.svg)

Để viết công thức không đánh số, hãy thêm ký tự `*` ngay sau tên môi trường, chẳng hạn `{equation*}`, `{eqnarray*}`.

??? warning "Cảnh báo"
    Có thể thấy rằng khi dùng `eqnarray`, sẽ xuất hiện các vấn đề như khoảng trống quanh dấu bằng quá lớn.
    
    Có thể dùng môi trường `align` trong gói `amsmath`:
    
    ```tex
    \usepackage{amsmath}
    ...
    \begin{align}
      a & = b + c \\
        & = y - z
    \end{align}
    ```
    
    Hoặc dùng môi trường `aligned` trong công thức hiển thị riêng dòng. Khi thêm dấu sao vào sau tên các môi trường này, công thức sẽ không được đánh số.
    
    Xem mục "4.4 Công thức nhiều dòng" trong tài liệu đầu tiên ở phần [Đọc thêm](#đọc-thêm).

### Ký hiệu toán học

Dù một số ký hiệu cơ bản có thể được nhập trực tiếp, phần lớn ký hiệu đặc biệt cần dùng lệnh để hiển thị.

Tài liệu này chỉ là phần nhập môn về cách dùng ký hiệu toán học; chương ký hiệu toán học của LaTeX Wikibook là một hướng dẫn khác tốt hơn và đầy đủ hơn. Nếu muốn tìm hiểu thêm về ký hiệu toán học, hãy xem tài liệu đó. Nếu muốn tìm một ký hiệu cụ thể, bạn có thể dùng [Detexify](http://detexify.kirelabs.org), công cụ có thể nhận diện ký tự viết tay.

#### Số mũ và chỉ số dưới

Số mũ (Powers) dùng `^` để biểu thị, chẳng hạn `$n^2$` tạo ra kết quả $n^2$.

Chỉ số dưới (Indices) dùng `_` để biểu thị, chẳng hạn `$2_a$` tạo ra kết quả $2_a$.

Nếu nội dung số mũ hoặc chỉ số dưới gồm nhiều ký tự, hãy dùng ngoặc nhọn bao lại. Ví dụ `$b_{a-2}$` tạo ra kết quả $b_{a-2}$.

#### Phân số

Phân số được chèn bằng lệnh `\frac{numerator}{denominator}`. Ví dụ `$$\frac{a}{3}$$` tạo ra kết quả:

$$
\frac{a}{3}
$$

Phân số có thể lồng nhau. Ví dụ `$$\frac{y}{\frac{3}{x}+b}$$` tạo ra kết quả:

$$
\frac{y}{\frac{3}{x}+b}
$$

#### Căn thức

Chúng ta dùng lệnh `\sqrt{...}` để chèn căn thức. Nội dung trong dấu ba chấm được thay bằng biểu thức lấy căn. Nếu cần thêm bậc của căn, hãy đặt bậc đó trong ngoặc vuông.

Ví dụ `$$\sqrt{y^2}$$` tạo ra kết quả:

$$
\sqrt{y^2}
$$

còn `$$\sqrt[x]{y^2}$$` tạo ra kết quả:

$$
\sqrt[x]{y^2}
$$

#### Tổng và tích phân

Dùng `\sum` và `\int` để chèn tổng và tích phân. Với cả hai ký hiệu, cận trên dùng `^` để biểu thị, còn cận dưới dùng `_`.

`$$\sum_{x=1}^5 y^z$$` tạo ra kết quả:

$$
\sum_{x=1}^5y^z
$$

còn `$$\int_a^b f(x)$$` tạo ra kết quả:

$$
\int_a^b f(x)
$$

#### Chữ cái Hy Lạp

Ta có thể dùng dấu gạch chéo ngược kèm tên chữ cái Hy Lạp để biểu thị một chữ cái Hy Lạp. Việc viết hoa hay viết thường chữ cái đầu của tên quyết định dạng của chữ cái Hy Lạp. Ví dụ:

-   `$\alpha$`=$\alpha$
-   `$\beta$`=$\beta$
-   `$\delta, \Delta$`=$\delta, \Delta$
-   `$\pi, \Pi$`=$\pi, \Pi$
-   `$\sigma, \Sigma$`=$\sigma, \Sigma$
-   `$\phi, \Phi, \varphi$`=$\phi, \Phi, \varphi$
-   `$\psi, \Psi$`=$\psi, \Psi$
-   `$\omega, \Omega$`=$\omega, \Omega$

### Thực hành

$\rightarrow$ Viết mã để tạo các công thức sau:

![Bài thực hành viết công thức toán học trong LaTeX](images/latex-for-beginners-15.png)

Nếu cần trợ giúp, bạn có thể xem [mã nguồn](https://github.com/OI-wiki/OI-wiki/blob/master/docs/tools/latex.md?plain=1) của trang này.

## Tài liệu tham khảo

### Giới thiệu

LaTeX có thể chèn tài liệu tham khảo và mục lục một cách dễ dàng. Phần này sẽ giới thiệu cách dùng một tệp BibTeX khác để lưu tài liệu tham khảo.

### Kiểu tệp BibTeX

Tệp BibTeX chứa tất cả tài liệu mà bạn muốn trích dẫn trong tài liệu của mình. Phần mở rộng của nó là `.bib`. Tên của nó nên được đặt theo tên tài liệu TeX của bạn. Tệp `.bib` là tệp văn bản. Bạn cần nhập tài liệu tham khảo theo định dạng sau:

```text
@article{
    Birdetal2001,
    Author = {Bird, R. B. and Smith, E. A. and Bird, D. W.},
    Title = {The hunting handicap: costly signaling in human foraging strategies},
    Journal = {Behavioral Ecology and Sociobiology},
    Volume = {50},
    Pages = {9-19},
    Year = {2001} 
}
```

Mỗi tài liệu tham khảo trước hết khai báo kiểu tài liệu (reference type). Ví dụ dùng @article; các kiểu khác gồm @book, @incollection dùng để trích dẫn một chương trong sách, và @inproceedings dùng để trích dẫn bài báo hội nghị. Có thể xem thêm các kiểu được hỗ trợ [tại đây](http://en.wikibooks.org/wiki/LaTeX/Bibliography_Management).

Trong cặp ngoặc nhọn tiếp theo, trước hết cần liệt kê một khóa trích dẫn (citation key). Bạn phải bảo đảm khóa trích dẫn của các tài liệu được trích dẫn là khác nhau. Bạn có thể tự định nghĩa chuỗi khóa, nhưng dùng tên tác giả đầu tiên kèm năm thường là một lựa chọn rõ nghĩa.

Các dòng tiếp theo gồm một số thông tin của tài liệu, theo định dạng:

```text
Field name = {field contents},
```

Bạn có thể dùng lệnh LaTeX để tạo hiệu ứng văn bản đặc biệt. Ví dụ chữ nghiêng có thể dùng `\emph{Rattus norvegicus}`.

Với các chữ cái cần viết hoa, hãy dùng ngoặc nhọn bao lại. BibTeX sẽ tự động đổi tất cả chữ hoa trong tiêu đề, trừ chữ cái đầu tiên, thành chữ thường. Ví dụ `Dispersal in the contemporary United States` tạo ra kết quả $\text{Dispersal in the contemporary united states}$, còn `Dispersal in the contemporary {U}nited {S}tates` tạo ra kết quả $\text{Dispersal in the contemporary United States}$.

Bạn có thể viết tệp BibTeX thủ công, hoặc dùng phần mềm để tạo.

### Chèn danh sách tài liệu

Dùng các lệnh sau để chèn danh sách tài liệu tại vị trí hiện tại trong tài liệu:

```tex
\bibliographystyle{plain}
\bibliography{references}
```

Tài liệu tham khảo được viết trong `references.bib`.

### Chú thích trích dẫn

Dùng `\cite{citationkey}` để chèn một chú thích trích dẫn tại nơi bạn muốn trích dẫn tài liệu. Nếu bạn không muốn chèn chú thích trích dẫn trong phần thân văn bản nhưng vẫn muốn hiển thị mục trích dẫn này trong danh sách tài liệu, hãy dùng lệnh `\nocite{citationkey}`.

Muốn chèn thông tin số trang vào trích dẫn, dùng ngoặc vuông: `\cite[p. 215]{citationkay}`.

Để trích dẫn nhiều tài liệu, dùng dấu phẩy phân tách: `\cite{citation01,citation02,citation03}`.

### Kiểu trích dẫn

#### Trích dẫn đánh số

LaTeX có nhiều kiểu trích dẫn đánh số trong dòng:

**Plain** là dạng dùng số đặt trong ngoặc vuông, chẳng hạn $[1]$. Danh sách tài liệu được sắp xếp theo thứ tự chữ cái của tác giả đầu tiên. Tên mỗi tác giả được viết đầy đủ.

**Abbrv** giống **plain**, nhưng tên tác giả được viết tắt.

**Unsrt** giống **plain**, nhưng danh sách tài liệu được sắp xếp theo thứ tự xuất hiện của trích dẫn trong văn bản.

**Alpha** giống **plain**, nhưng nhãn trích dẫn là tổ hợp tên tác giả và năm, không phải số, chẳng hạn $[Kop10]$.

#### Trích dẫn tác giả-ngày

Nếu muốn dùng kiểu trích dẫn tác giả-ngày, hãy dùng gói **natbib**. Nó dùng lệnh `\citep{...}` để tạo chú thích trong ngoặc vuông, chẳng hạn $[Koppe,2010]$, và dùng `\citet{...}` để tạo chú thích chỉ đặt năm trong ngoặc vuông, chẳng hạn $Koppe [2010]$. Xem thêm cách dùng của nó [tại đây](http://mirror.ctan.org/macros/latex/contrib/natbib/natnotes.pdf).

Gói Natbib cũng có ba kiểu: **plainnat**, **abbrvnat** và **unsrtnat**; chúng có hiệu quả tương tự **plain**, **abbrv** và **unsrt**.

#### Kiểu trích dẫn khác

Nếu cần dùng một kiểu khác, bạn cần tạo một tệp kiểu (`.bst`) trong cùng thư mục. Khi dùng kiểu đó, gọi lệnh `\bibliographystyle{...}` với tên tệp của nó.

### Thực hành

$\rightarrow$ Tạo một tệp BibTeX cùng tên trong cùng thư mục và nhập thông tin tài liệu tham khảo theo đúng định dạng. $\rightarrow$ Chuyển sang tài liệu TeX và dùng các lệnh `\cite`, `\bibliographystyle` và `\bibliography` để trích dẫn tài liệu. $\rightarrow$ Biên dịch tệp TeX. $\rightarrow$ Chuyển sang tệp BibTeX và biên dịch bằng cách nhấp nút **Typeset**. $\rightarrow$ Chuyển lại sang tệp TeX, biên dịch nó **hai lần**, rồi kiểm tra tài liệu PDF.

## Đọc thêm

-   Một bản giới thiệu LATEX 2ε ngắn gọn (không hẳn là ngắn) <https://tobi.oetiker.ch/lshort/lshort.pdf>, còn có tên *The Not So Short Introduction to LaTeX2e*.

-   LaTeX Project <http://www.latex-project.org/> Trang chính thức - có liên kết tới tài liệu, thông tin cài đặt LaTeX trên máy cá nhân và nơi tìm trợ giúp.

-   LaTeX Wikibook <http://en.wikibooks.org/wiki/LaTeX/> Đầy đủ và được viết rõ ràng, dù vẫn đang được hoàn thiện. Cũng có bản PDF để tải xuống.

-   Comparison of TeX Editors on Wikipedia <http://en.wikipedia.org/wiki/Comparison_of_TeX_editors> Thông tin giúp bạn chọn trình soạn thảo LaTeX để cài trên máy cá nhân.

-   TeX Live <http://www.tug.org/texlive/> "Một cách dễ dàng để bắt đầu dùng hệ thống soạn thảo tài liệu TeX". Có cho Unix và Windows (có liên kết tới MacTeX cho người dùng MacOSX). Bao gồm trình soạn thảo TeXworks.

-   Workbook Source Files <http://edin.ac/17EQPM1> Tải tệp `.tex` và các tệp khác cần để biên dịch sách bài tập này.

**Bài này được dịch từ [http://www.docs.is.ed.ac.uk/skills/documents/3722/3722-2014.pdf](https://web.archive.org/web/20220309055041/http://www.docs.is.ed.ac.uk/skills/documents/3722/3722-2014.pdf)**, có chỉnh sửa nhẹ dựa trên các tài liệu khác.
