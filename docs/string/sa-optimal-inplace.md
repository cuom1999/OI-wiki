Chương này giới thiệu thuật toán sắp xếp hậu tố tại chỗ với độ phức tạp tuyến tính[^in-place-sa-sort] (Optimal In-Place Suffix Sorting).

???+ warning "Cảnh báo"
    Người đọc chỉ nên đọc chương này khi đã **rất, rất quen thuộc** với SA-IS[^nzc09a][^sa-is-gioi-thieu].

<span id="thiết-lập-chung"></span>
## Thiết lập chung

Xâu mục tiêu là $\texttt{Pat}$, mảng hậu tố là $\texttt{SA}$. Chỉ số xâu bắt đầu từ 0; ký tự cuối là ký tự canh, giả sử bằng 0.

<span id="sắp-xếp-hậu-tố-trên-bảng-chữ-cái-số-nguyên"></span>
## Sắp xếp hậu tố trên bảng chữ cái số nguyên

Phần này có thể xem là phiên bản tại chỗ của thuật toán SA-IS.

Đây là thuật toán được bài gốc mô tả khá đầy đủ, cài đặt cũng khá đơn giản, đồng thời là nền tảng để hiểu các thuật toán phía sau, nên là trọng tâm của bài này.

Nguyên lý tại chỗ là dùng $\texttt{Pat}$ đã được đổi tên để thay thế các bucket S và L, rồi dùng thêm $O(n)$ thao tác để thay cho bucket kiểu.

<span id="đổi-tên-xâu-mục-tiêu-pat"></span>
### Đổi tên xâu mục tiêu Pat

Nói ngắn gọn, đổi tên $\texttt{Pat}$ mà không làm thay đổi thứ tự tương đối giữa các hậu tố. Sau đó dùng $\texttt{Pat}$ đã đổi tên để thay thế các bucket S và L ban đầu, qua đó chỉ ra đầu bucket hoặc cuối bucket.

Cách đổi tên là thay ký tự kiểu S trong $\texttt{Pat}$ bằng chỉ số cuối bucket của nó, và thay ký tự kiểu L bằng chỉ số đầu bucket của nó.

Như hình dưới đây:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{Pat}:\qquad&\texttt{ 2   1   1   3   3   1   1   3   3   1   2   1   0} \\
\texttt{Type}:\qquad&\texttt{ L   S   S   L   L   S   S   L   L   S   L   L   S} \\
\texttt{Bucket}:\qquad&\texttt{(0)}\texttt{ }\texttt{(1}\texttt{ }\texttt{ }\texttt{ 1 }\texttt{ }\texttt{ 1 }\texttt{ }\texttt{ 1 }\texttt{ }\texttt{ 1 }\texttt{ }
\texttt{ 1) }\texttt{(2 }\texttt{ }\texttt{ 2) }\texttt{(3}\texttt{ }\texttt{ }\texttt{ 3 }\texttt{ }\texttt{ 3 }\texttt{ }\texttt{ 3)}
\end{aligned}
$$

$\texttt{Pat'}$ sau khi đổi tên (từ đây về sau gọi trực tiếp $\texttt{Pat'}$ đã đổi tên là $\texttt{Pat}$):

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{Pat'}:\qquad&\texttt{ 7   6   6   9   9   6   6   9   9   6   7   1   0}
\end{aligned}
$$

Trong cùng một bucket, hậu tố của ký tự kiểu L nhỏ hơn nên nằm ở đầu bucket, còn hậu tố của ký tự kiểu S lớn hơn nên nằm ở cuối bucket; do đó thứ tự tương đối giữa các hậu tố được giữ nguyên.

Các bước đổi tên cụ thể:

1.  Giống SA-IS, đếm từng ký tự trong $\texttt{Pat}$ và tính tổng tiền tố của chúng (sắp xếp đếm) để xây dựng bucket S/L; khác biệt là biến thể này dùng $\texttt{SA}$ để chứa các tổng tiền tố này.
2.  Quét từng ký tự của $\texttt{Pat}$ từ cuối lên đầu. Khi đó chỉ cần ghi nhớ kiểu của ký tự trước đó là có thể xác định động kiểu của từng ký tự, rồi đổi tên theo tổng tiền tố.

<span id="sắp-xếp-ký-tự-lms"></span>
### Sắp xếp ký tự LMS

Kỹ thuật trọng tâm là dùng bộ đếm nội bộ.

<span id="khởi-tạo"></span>
#### Khởi tạo

Ban đầu đặt mọi phần tử của $\texttt{SA}$ thành E (EMPTY).

Quét $\texttt{Pat}$ từ cuối lên đầu. Nếu phát hiện ký tự LMS $\texttt{Pat[i]}$, đặt dấu cho $\texttt{SA[Pat[i]]}$:

Nếu $\texttt{SA[Pat[i]]}$ là E, đặt nó thành U (UNIQUE).

Nếu $\texttt{SA[Pat[i]]}$ là U, đặt nó thành M (MULTIPLE).

Các trường hợp khác không cần xử lý.

Kết quả như hình dưới đây:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{Pat}:\qquad&\texttt{ 7   6   6   9   9   6   6   9   9   6   7   1   0} \\
\texttt{LMS}:\qquad&\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ ∗ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ * }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ * }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ }\texttt{ * } \\
\texttt{SA}:\qquad&\texttt{(}\underline{\color{red}{\texttt{U}}}\texttt{) }\texttt{(E)}\texttt{ }\texttt{(E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ }\underline{\color{red}{\texttt{M}}}\texttt{) }\texttt{(E }\texttt{ }\texttt{ E) }\texttt{(E}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E)}
\end{aligned}
$$

<span id="đưa-chỉ-số-ký-tự-lms-vào-sa"></span>
#### Đưa chỉ số ký tự LMS vào SA

Quét $\texttt{Pat}$ từ cuối lên đầu. Với ký tự LMS $\texttt{Pat[i]}$, xét theo ký hiệu của $\texttt{SA[Pat[i]]}$:

U: đặt trực tiếp $\texttt{SA[Pat[i]] = i}$.

M: nghĩa là trong bucket có ít nhất hai ký tự LMS.

1.  Nếu bucket có ít nhất ba ký tự LMS:
    dùng vị trí áp chót của bucket làm bộ đếm tạm, ghi số ký tự LMS đã được điền vào bucket (vị trí cuối bucket là dấu M).
    Chèn ký tự LMS mới bắt đầu từ vị trí thứ ba tính từ cuối, rồi tăng bộ đếm tạm thêm 1.
    Nếu phát hiện bucket đã đầy, dịch toàn bộ phần tử từ đầu bucket đến vị trí thứ ba tính từ cuối sang phải 2 vị trí, rồi chèn phần tử mới vào vị trí thứ hai của bucket (vị trí đầu bucket điền E).

2.  Nếu bucket có đúng 2 ký tự LMS thì không cần bộ đếm; chỉ cần chèn theo thứ tự từ phải sang trái.

Giá trị bình thường:

    Theo thảo luận ở trên, lúc này dù bucket có hai hay nhiều hơn hai ký tự LMS, điều đó đều có nghĩa $\texttt{i}$ là vị trí của ký tự LMS cuối cùng cần chèn trong bucket.

    Chỉ cần quét trong bucket từ phải sang trái, tìm vị trí đầu tiên được đánh dấu E và đặt nó thành $\texttt{i}$.

Cuối cùng cần quét $\texttt{SA}$ một lượt từ cuối lên đầu để xóa các ký hiệu đặc biệt M có thể còn sót lại (bucket chưa được điền đầy, nên M và bộ đếm chưa bị ghi đè).

Cách làm là dịch các ký tự LMS trong bucket sang phải 2 vị trí như bước trên, rồi điền E vào các vị trí trống bên trái.

Như hình dưới đây:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ }\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{Pat}:\qquad&\texttt{ }\texttt{ 7   6   6   9   9   6   6   9   9   6   7   1   0} \\
\texttt{SA}:\qquad&\texttt{(}\underline{\color{red}{\texttt{12}}}\texttt{)}\texttt{ (E)}\texttt{ (E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ M}\texttt{) }\texttt{(E }\texttt{ }
\texttt{ E) }\texttt{(E}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E)}\\
\texttt{SA}:\qquad&\texttt{(12) }\texttt{(E)}\texttt{ (E }\texttt{ }\texttt{ E }\texttt{ }
\texttt{ }\underline{\color{red}{\texttt{9}}}\texttt{ }\texttt{ }{\color{red}{\texttt{ 1 }}}\texttt{ }\texttt{ }
{\color{red}{\texttt{M}}}\texttt{) }\texttt{(E }\texttt{ }\texttt{ E) }\texttt{(E}\texttt{ }\texttt{ }\texttt{ E }
\texttt{ }\texttt{ E }\texttt{ }\texttt{ E)} \\
\texttt{SA}:\qquad&\texttt{(12) }\texttt{(E)}\texttt{ (E }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{5}}}}
\texttt{ }\texttt{ }\texttt{ }{\texttt{9}}\texttt{ }\texttt{ }{\color{red}{\texttt{ 2 }}}\texttt{ }\texttt{ }
{\color{red}{\texttt{M}}}\texttt{) }\texttt{(E }\texttt{ }\texttt{ E) }\texttt{(E}\texttt{ }\texttt{ }\texttt{ E }
\texttt{ }\texttt{ E }\texttt{ }\texttt{ E)}\\
\texttt{SA}:\qquad&\texttt{(12) }\texttt{(E)}\texttt{ (}\underline{\color{red}{\texttt{1}}}\texttt{ }\texttt{ }{\texttt{ 5}}\texttt{ }\texttt{ }\texttt{ }{\texttt{9}}\texttt{ }\texttt{ }{\color{red}{\texttt{ 3 }}}\texttt{ }\texttt{ }{\color{red}{\texttt{M}}}\texttt{) }\texttt{(E }\texttt{ }\texttt{ E) }\texttt{(E}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E)}\\
\texttt{SA}:\qquad&\texttt{(12) }\texttt{(E)}\texttt{ (}\texttt{E }\texttt{ }\texttt{ E }\texttt{ }{\color{red}{\texttt{ 1 }}\texttt{ }{\texttt{ 5 }}\texttt{ }\texttt{ }{\texttt{9}}}\texttt{) }\texttt{(E }\texttt{ }\texttt{ E) }\texttt{(E}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E)}
\end{aligned}
$$

Ở giai đoạn này, mỗi bucket chỉ cần được dịch chuyển và quét một lần, nên độ phức tạp thời gian là $O(n)$.

<span id="sắp-xếp-cảm-ứng-xâu-con-lms"></span>
### Sắp xếp cảm ứng xâu con LMS

<span id="sắp-xếp-cảm-ứng-tiền-tố-lms"></span>
#### Sắp xếp cảm ứng tiền tố LMS

Thực hiện sắp xếp cảm ứng các tiền tố LMS. Giống SA-IS, phần này hoàn toàn giống bước sắp xếp cảm ứng hậu tố ở phía sau (dùng cùng một hàm), nên phần chi tiết được lược bỏ.

Dưới đây là kết quả sắp xếp:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ }\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&\texttt{(}\texttt{12}\texttt{)}\texttt{(11)}\texttt{ (1 }\texttt{ }\texttt{ 5 }\texttt{ }\texttt{ 9 }\texttt{ }\texttt{ 2 }\texttt{ }\texttt{ 6}\texttt{) }\texttt{(10 }\texttt{ }\texttt{ 0) }\texttt{(4}\texttt{ }\texttt{ }\texttt{ 8 }\texttt{ }\texttt{ 3 }\texttt{ }\texttt{ 7)}
\end{aligned}
$$

<span id="đưa-các-xâu-con-lms-đã-sắp-xếp-vào-cuối-sa"></span>
#### Đưa các xâu con LMS đã sắp xếp vào cuối SA

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&\texttt{ }\texttt{E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }{\underline{\color{red}{\texttt{12}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{1}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{5}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{9}}}}
\end{aligned}
$$

<span id="xây-dựng-xâu-mục-tiêu-con-pat1-có-kích-thước-thu-gọn"></span>
### Xây dựng xâu mục tiêu con Pat1 có kích thước thu gọn

Quét các xâu con LMS ở cuối $\texttt{SA}$ từ trái sang phải, xác định quan hệ thứ tự của chúng và "đổi tên"; lưu giá trị đổi tên của $\texttt{SA[i]}$ vào $\texttt{SA}\left[\left\lfloor\frac{\texttt{SA}[i]}{2} \right\rfloor\right]$.

Vì các ký tự LMS không kề nhau nên sẽ không có xung đột. Cách này đặt các giá trị đã đổi tên theo đúng thứ tự ban đầu của các xâu con mà chúng đại diện trong $\texttt{Pat}$:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&\texttt{ }\underline{\color{red}{\texttt{1}}}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ }\underline{\color{red}{\texttt{1}}}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ }\underline{\color{red}{\texttt{2}}}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ }\underline{\color{red}{\texttt{0}}}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ 12 }\texttt{ }\texttt{ 1 }\texttt{ }\texttt{ 5 }\texttt{ }\texttt{ 9 }
\end{aligned}
$$

Sau đó quét $\texttt{SA}$ và gom các giá trị đã đổi tên này về đầu $\texttt{SA}$:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&\texttt{ }\underline{\color{red}{\texttt{1}}}\texttt{ }\texttt{ }\texttt{ }\underline{\color{red}{\texttt{1}}}\texttt{ }\texttt{ }\texttt{ }\underline{\color{red}{\texttt{2}}}\texttt{ }\texttt{ }\texttt{ }\underline{\color{red}{\texttt{0}}}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ 12 }\texttt{ }\texttt{ 1 }\texttt{ }\texttt{ 5 }\texttt{ }\texttt{ 9 }
\end{aligned}
$$

<span id="giải-đệ-quy-pat1-để-hoàn-tất-sắp-xếp-hậu-tố-lms"></span>
### Giải đệ quy Pat1 để hoàn tất sắp xếp hậu tố LMS

Giống SA-IS, giải đệ quy bài toán sắp xếp hậu tố của $\texttt{Pat1}$ đã thu gọn ở đầu $\texttt{SA}$, rồi lưu kết quả vào cuối $\texttt{SA}$:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&\texttt{ }\texttt{1 }\texttt{ }\texttt{ 1 }\texttt{ }\texttt{ 2 }\texttt{ }\texttt{ 0 }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{3}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{0}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{1}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{2}}}}
\end{aligned}
$$

Di chuyển $\texttt{SA1}$ ở cuối $\texttt{SA}$ lên đầu $\texttt{SA}$, rồi quét lại $\texttt{Pat}$ từ cuối lên đầu, đặt các ký tự LMS vào cuối $\texttt{SA}$ theo thứ tự của chúng trong $\texttt{Pat}$:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&\texttt{ }{\underline{\color{red}{\texttt{3}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{0}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{1}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{2}}}}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{1}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{5}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{9}}}}\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{12}}}}
\end{aligned}
$$

Dựa trên "bảng đối chiếu" ở cuối $\texttt{SA}$, khôi phục phần đầu của $\texttt{SA1}$ thành vị trí chỉ số của hậu tố LMS tương ứng trong $\texttt{Pat}$:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&{\underline{\color{red}{\texttt{12}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{1}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{5}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{9}}}}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ 1 }\texttt{ }\texttt{ 5 }\texttt{ }\texttt{ 9 }\texttt{ 12 }
\end{aligned}
$$

Đưa các hậu tố LMS đã sắp xếp ở đầu $\texttt{SA}$ vào bucket tương ứng theo thứ tự (đặt từ cuối bucket):

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ }\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&\texttt{(}{\underline{\color{red}{\texttt{12}}}}\texttt{)}\texttt{ }\texttt{(E)}\texttt{ (}\texttt{E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{1}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{5}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{9}}}}\texttt{)}\texttt{ }\texttt{(E }\texttt{ }\texttt{ E) }\texttt{(E}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E)}
\end{aligned}
$$

<span id="sắp-xếp-cảm-ứng-tất-cả-hậu-tố-trong-pat1"></span>
### Sắp xếp cảm ứng tất cả hậu tố trong Pat1

Phần này dùng lại kỹ thuật bộ đếm nội bộ ở trên để thực hiện sắp xếp cảm ứng phiên bản tại chỗ.

Giả sử đã có các hậu tố LMS được sắp xếp (ở cuối bucket), dùng chúng để cảm ứng các hậu tố kiểu L[^thu-tu-cam-ung]:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ }\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{Pat}:\qquad&\texttt{ }\texttt{ 7   6   6   9   9   6   6   9   9   6   7   1   0} \\
\texttt{SA}:\qquad&\texttt{(12) }\texttt{(E)}\texttt{ (}\texttt{E }\texttt{ }\texttt{ E }\texttt{ }{\texttt{ 1 }\texttt{ }{\texttt{ 5 }}\texttt{ }\texttt{ }{\texttt{9}}}\texttt{) }\texttt{(E }\texttt{ }\texttt{ E) }\texttt{(E}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E)}
\end{aligned}
$$

Tương tự khi sắp xếp ký tự LMS, trước hết dùng ký hiệu đặc biệt để đếm các ký tự kiểu L:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ }\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{Pat}:\qquad&\texttt{ }\texttt{ 7   6   6   9   9   6   6   9   9   6   7   1   0} \\
\texttt{SA}:\qquad&\texttt{(}{{\texttt{12}}}\texttt{)}\texttt{ }\texttt{(}{\underline{\color{red}{\texttt{U}}}}\texttt{)}\texttt{ }\texttt{(E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ 1 }\texttt{ }\texttt{ 5 }\texttt{ }{\texttt{ 9}}\texttt{) }\texttt{(}{\underline{\color{red}{\texttt{M}}}}\texttt{ }\texttt{ }\texttt{ E) }\texttt{(}{\underline{\color{red}{\texttt{M}}}}\texttt{ }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E }\texttt{ }\texttt{ E)}
\end{aligned}
$$

Quét SA từ trái sang phải. Giống khi sắp xếp ký tự LMS, điểm phức tạp hơn là cần xác định kiểu của $\texttt{suf[SA[i] - 1]}$, phải chia trường hợp để xét (chi tiết xem mã):

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ }\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&\texttt{(}{\overrightarrow{\color{red}{\texttt{12}}}\texttt{)}\texttt{(}{\underline{\color{red}{\texttt{11}}}}}\texttt{)}\texttt{  (E   E   1   5   9) (M   E) (M   E   E   E)}\\
\texttt{SA}:\qquad&\texttt{(}\texttt{12}\texttt{)}\texttt{(}{\overrightarrow{\color{red}{\texttt{11}}}}\texttt{)}\texttt{  (E   E   1   5   9)}\texttt{(}{\underline{\color{red}{\texttt{10}}}}\texttt{ }\texttt{ }\texttt{ E)}\texttt{ (M   E   E   E)}\\
\texttt{SA}:\qquad&\texttt{(12)(11)}\texttt{  (E   E  }\texttt{ }\texttt{ } {\overrightarrow{\color{red}{\texttt{1}}}}\texttt{ }\texttt{  5   9)}\texttt{(10 }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{0}}}}\texttt{)}\texttt{ (M   E   E   E)}\\
\texttt{SA}:\qquad&\texttt{(12)(11)}\texttt{  (E   E   1 }\texttt{ }\texttt{ } {\overrightarrow{\color{red}{\texttt{5}}}}\texttt{ }\texttt{  9)}\texttt{(10   0)}\texttt{ (}{\color{red}{\texttt{M   1}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{4}}}}\texttt{ }\texttt{ }\texttt{ E)}\\
\texttt{SA}:\qquad&\texttt{(12)(11)}\texttt{  (E   E   1   5}\texttt{ }\texttt{ } {\overrightarrow{\color{red}{\texttt{9}}}}\texttt{)}\texttt{(10   0)}\texttt{ (}{\color{red}{\texttt{M   2}}}\texttt{ }\texttt{ }\texttt{ 4 }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{8}}}}\texttt{)}\\
\texttt{SA}:\qquad&\texttt{(12)(11)}\texttt{  (E   E   1   5   9)(10   0)}\texttt{ (}{\overrightarrow{\color{red}{\texttt{4}}}}\texttt{ }\texttt{ 8 }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{3}}}}\texttt{ }\texttt{ }\texttt{ E}\texttt{)}\\
\texttt{SA}:\qquad&\texttt{(12)(11)}\texttt{  (E   E   1   5   9)(10   0)}\texttt{ (4 }\texttt{ }\texttt{ }{\overrightarrow{\color{red}{\texttt{8}}}}\texttt{ }\texttt{ 3 }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{7}}}}\texttt{)}
\end{aligned}
$$

Khác với SA-IS, sau khi sắp xếp cảm ứng một kiểu ký tự, cần dọn các ký tự LMS để tránh ảnh hưởng tới bước sắp xếp cảm ứng tại chỗ tiếp theo:

$$
\begin{aligned}
\texttt{Index}:\qquad&\texttt{ }\texttt{ 0   1   2   3   4   5   6   7   8   9  10  11  12} \\
\texttt{SA}:\qquad&\texttt{(12)(11)}\texttt{  (E   E  }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{E}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{E}}}}\texttt{ }\texttt{ }\texttt{ }{\underline{\color{red}{\texttt{E}}}}\texttt{)}\texttt{(10   0)}\texttt{ (4   8   3   7)}
\end{aligned}
$$

Còn việc cảm ứng hậu tố S từ hậu tố L hoàn toàn đối xứng với việc cảm ứng hậu tố L từ hậu tố LMS, nên không trình bày thêm.

Đến đây, bước sắp xếp cảm ứng đã hoàn tất.

<span id="cài-đặt"></span>
#### Cài đặt

Về thời gian, thuật toán không khác SA-IS đáng kể; còn không gian sử dụng giảm xuống dưới $\dfrac{1}{3}$ so với ban đầu (đổi lại lượng mã tăng khoảng gấp đôi). Như vậy tương xứng với tiêu đề Optimal In-Place Suffix Sorting[^in-place-sa-sort] của bài gốc.

??? note "Mã tham khảo"
    ```rust
    use std::cmp::max;
    use std::cmp::Ordering;
    use std::slice::from_raw_parts_mut;
    
    
    const LTYPE: bool = false;
    const STYPE: bool = true;
    const MAX_SA_VALUE: usize = usize::MAX / 2;
    const EMPTY: usize = MAX_SA_VALUE + 1;
    const UNIQUE: usize = MAX_SA_VALUE + 2;
    const MULTI: usize = MAX_SA_VALUE + 3;  // >= 258
    
    
    fn lms_str_cmp<E: Ord>(l1: &[E], l2: &[E]) -> Ordering {
        for (x, y) in l1.iter().zip(l2.iter()) {
            let cmp_res = x.cmp(&y);
            
            if cmp_res != Ordering::Equal { return cmp_res; }
        }
        
        Ordering::Equal
    }
    
    #[inline]
    fn pat_char_type(cur: usize, prev: usize, last_scanned_type: bool) -> bool {
        if cur < prev || cur == prev && last_scanned_type == STYPE { STYPE }
        else { LTYPE }
    }
    
    
    fn rename_pat(pat: &mut [usize], sa: &mut [usize]) {
        let patlastpos = pat.len() - 1;
        // Đặt tất cả về đầu bucket
        //sa.fill(0);
        for i in 0..sa.len() { sa[i] = 0 }
        
        for i in 0..pat.len() { sa[pat[i]] += 1 }
        for i in 1..sa.len() { sa[i] += sa[i - 1] }
        
        for i in 0..pat.len() - 1 {
            pat[i] = sa[pat[i]] - 1;
        };
        // Đặt các L-suffix về đầu bucket
        //sa.fill(0);
        for i in 0..sa.len() { sa[i] = 0 }
        
        for i in 0..pat.len() { sa[pat[i]] += 1 }
        let mut last_scanned_type = STYPE;
        pat[patlastpos] = 0;
        for i in (0..pat.len() - 1).rev() {
            if pat_char_type(pat[i], pat[i + 1], last_scanned_type) == STYPE {
                last_scanned_type = STYPE;
            } else {
                pat[i] -= sa[pat[i]] - 1;
                last_scanned_type = LTYPE;
            }
        }
    
    }
    
    
    fn sort_lms_char(pat: &mut [usize], sa: &mut [usize]) -> usize {
        //sa.fill(EMPTY);
        for i in 0..sa.len() { sa[i] = EMPTY }
        
        let mut last_scanned_type = STYPE;
        for i in (0..pat.len() - 1).rev() {
            if pat_char_type(pat[i], pat[i + 1], last_scanned_type) == STYPE {
                last_scanned_type = STYPE;
            } else {
                if last_scanned_type == STYPE {  // pat[i + 1] có kiểu LMS
                    sa[pat[i + 1]] += 1;
                }
                
                last_scanned_type = LTYPE;
            }
        }
        
        let mut lms_cnt = 0;
        last_scanned_type = STYPE;
        for i in (0..pat.len() - 1).rev() {
            if pat_char_type(pat[i], pat[i + 1], last_scanned_type) == STYPE {
                last_scanned_type = STYPE;
            } else {
                let e_i = i + 1;
                let e = pat[e_i];
                
                if last_scanned_type == STYPE {  // pat[i + 1] có kiểu LMS
                    lms_cnt += 1;
                    if sa[e] == UNIQUE {
                        sa[e] = e_i;
                    } else if sa[e] >= MULTI && sa[e - 1] == EMPTY {
                        if sa[e - 2] == EMPTY {
                            sa[e - 2] = e_i;
                            sa[e - 1] = 1;  // Đặt bộ đếm
                        } else {  // MUL = 2
                            sa[e] = e_i;
                            sa[e - 1] = EMPTY;
                        }
                    } else if sa[e] >= MULTI && sa[e - 1] != EMPTY {
                        let c = sa[e - 1];  // Lấy bộ đếm
                        
                        if sa[e - 2 - c] == EMPTY {
                            sa[e - 2 - c] = e_i;
                            sa[e - 1] += 1;  // Cập nhật bộ đếm
                        } else {
                            for j in (1..c + 1).rev() {
                                sa[e - c + j] = sa[e - 2 - c + j]
                            }
                            sa[e - c] = e_i;
                            sa[e - c - 1] = EMPTY;
                        }
                    } else if sa[e] < EMPTY {
                        for j in (0..e).rev() {
                            if sa[j] == EMPTY {
                                sa[j] = e_i;
                                break;
                            }
                        }
                    }
                }
                
                last_scanned_type = LTYPE;
            }
        }
        
        for i in (0..pat.len()).rev() {
            if sa[i] >= MULTI {
                let c = sa[i - 1];
                for j in (1..c + 1).rev() {  // Duyệt ngược để tránh giá trị phía trước ghi đè giá trị phía sau
                    sa[i - c + j] = sa[i - 2 - c + j];
                }
                sa[i - c - 1] = EMPTY;
                sa[i - c] = EMPTY;
            }
        }
        
        lms_cnt
    }
    
    
    fn sort_lms_substr(pat: &mut [usize], sa: &mut [usize]) {
        // step 1
        induced_sort(pat, sa);
        
        // step 2
        let pat_last_pos = pat.len() - 1;
        let mut lms_cnt = 0;
        let mut i = pat_last_pos;
        let mut bucket_tail_ptr = pat_last_pos + 1;  // Dành cho phiên bản bucket đã đổi tên
        let mut bucket = EMPTY;  // Có thể bỏ, nhưng giữ lại để code dễ viết hơn
        let mut num = 0;  // Số ký tự kiểu S trong bucket
        while i > 0 {
            if pat[sa[i]] != bucket {  // Gặp bucket mới
                num = 0;
                
                let mut l = 0;
                while pat[sa[i - l]] == pat[sa[i]] {  // Quét bucket để đếm ký tự kiểu S; theo định nghĩa, vòng lặp sẽ dừng khi l = i
                    let pat_i = sa[i - l];             // l < i, tức i - l > 0, 0 <= pat_i < patlen - 1
                    if pat[pat_i] < pat[pat_i + 1] {
                        let mut k = pat_i;
                        while k > 0 && pat[k - 1] == pat[pat_i] { k -= 1 }
                        num += pat_i - k + 1;
                    } else {
                        break;   // Bucket không có ký tự kiểu S; dừng quét
                    }
                    
                    l += 1;
                }
                
                bucket_tail_ptr = i;
                bucket = pat[sa[bucket_tail_ptr]];
            }
            
            if num > 0
            && i > bucket_tail_ptr - num
            && sa[i] > 0
            && pat[sa[i]] < pat[sa[i] - 1]  {
                sa[pat_last_pos - lms_cnt] = sa[i];
                lms_cnt += 1;
            }
            
            i -= 1;
        }
        
        sa[pat_last_pos - lms_cnt ] = sa[i];  // i = 0
        lms_cnt += 1;
        //sa[0..pat_last_pos - lms_cnt + 1].fill(EMPTY);
        for i in 0..pat_last_pos - lms_cnt + 1 { sa[i] = EMPTY }
    }
    
    
    fn construct_pat1(pat: &mut [usize], sa: &mut [usize], lms_cnt: usize) -> bool {
        let patlen = pat.len();
        
        let mut prev_lms_str_len = 1;
        let mut rank = 0;
        sa[(patlen - 1) / 2] = rank;
        let mut has_duplicated_char = false;
        for i in patlen - lms_cnt + 1..patlen {  // Bắt đầu từ ký tự ngay sau ký tự canh
            let mut j = sa[i];
            while pat[j] <= pat[j + 1] { j += 1 } // Tìm ký tự L đầu tiên bên phải suf(sa[i]); hậu tố LMS chứa ký tự canh đã bị loại, nên không thể vượt biên
            let mut k = j;
            while k + 1 < patlen && pat[k] >= pat[k + 1] { k += 1 }  // Tìm ký tự LMS đầu tiên bên phải suf(sa[i])
            let cur_lms_str_len = k + 1 - sa[i];
            let cmp_res = lms_str_cmp(&pat[sa[i]..sa[i] + cur_lms_str_len], &pat[sa[i - 1]..sa[i - 1] + prev_lms_str_len]);
            
            if  cmp_res != Ordering::Equal {
                rank += 1
            }
            
            if rank == sa[sa[i - 1] / 2] {
                has_duplicated_char = true;
            }
            let rank_index = sa[i] / 2;
            sa[rank_index] = rank;  // Chia nguyên
            
            prev_lms_str_len = cur_lms_str_len;
        }
        
        // Chuyển lên đầu sa
        let mut j = 0;
        for i in 0..patlen - lms_cnt {
            if sa[i] != EMPTY {
                sa[j] = sa[i];
                if i > j {
                    sa[i] = EMPTY;
                }
                j += 1;
            }
        }
        //sa[lms_cnt..patlen].fill(EMPTY);
        for i in lms_cnt..patlen { sa[i] = EMPTY }
        
        has_duplicated_char
    }
    
    fn sort_lms_suf(pat: &mut [usize], sa: &mut [usize], lms_cnt: usize, has_duplicated_char: bool) {
        // solve T1 recursively
        let patlen = pat.len();
        let salen = sa.len();
        unsafe {
            let sa_ptr = sa.as_mut_ptr();
            let mut pat1 = from_raw_parts_mut(sa_ptr, lms_cnt);
            let mut sa1 = from_raw_parts_mut(sa_ptr.offset((patlen - lms_cnt) as isize), salen - (patlen - lms_cnt));
            
            if has_duplicated_char {
                _compute_suffix_array_16_1(&mut pat1, &mut sa1);
            } else {
                for i in 0..lms_cnt { sa1[pat1[i]] = i }
            }
        }
        
        // Chuyển SA1 sang SA[0...n1-1]
        for i in 0..lms_cnt {
            sa[i] = sa[patlen- lms_cnt + i];
        }
        
        // Đưa tất cả hậu tố LMS vào cuối SA
        let mut last_scanned_type = STYPE;
        let mut j = 0;
        for i in (0..pat.len() - 1).rev() {
            if pat[i] < pat[i + 1] || pat[i] == pat[i + 1] && last_scanned_type == STYPE {
                last_scanned_type = STYPE;
            } else {
                if last_scanned_type == STYPE {
                    sa[patlen - 1 - j] = i + 1;
                    j += 1;
                }
                
                last_scanned_type = LTYPE;
            }
        }
        
        // Ánh xạ ngược hạng của các hậu tố LMS
        for i in 0..lms_cnt {
            let relative_rank = sa[i];
            sa[i] = sa[patlen - lms_cnt + relative_rank];
            sa[patlen - lms_cnt + relative_rank] = EMPTY;
        }
        
        let mut tail = EMPTY;
        let mut rfp = EMPTY;
        for i in (1..lms_cnt).rev() { // Giữ nguyên vị trí của sa[0]
            if pat[sa[i]] != tail {
                tail = pat[sa[i]];
                rfp = tail;
            }
            
            sa[rfp] = sa[i];
            if rfp != i { sa[i] = EMPTY }
            rfp -= 1;
        }
    }
    
    // PASS!
    fn induced_sort(pat: &mut [usize], sa: &mut [usize]) {
        let patlen = pat.len();
        
        // place L-suff in SA
        // init
        let mut last_scanned_type = STYPE;
        for i in (0..patlen - 1).rev() {
            if pat_char_type(pat[i], pat[i + 1], last_scanned_type) == LTYPE {
                sa[pat[i]] += 1;  // >= EMPTY
                last_scanned_type = LTYPE;
            } else {
                last_scanned_type = STYPE;
            }
        }
        //place
        let mut i = 0;
        while i < patlen {
            if sa[i] < EMPTY && sa[i] > 0 {
                let j = sa[i] - 1;
                let mut is_ltype = false;
                if pat[j] > pat[j + 1] {
                    is_ltype = true;
                } else if pat[j] == pat[j + 1] {  // Kiểm tra sa[i] có phải chỉ số của một L-suffix hay không
                    let next_i = sa[pat[sa[i]]];
                    if next_i >= MULTI {
                        is_ltype = true;
                    } else if next_i < EMPTY && pat[sa[i]] + 1 < patlen {
                        if sa[pat[sa[i]] + 1] == EMPTY {
                            is_ltype = true;
                        } else if sa[pat[sa[i]] + 1] < EMPTY {
                            if pat[sa[pat[sa[i]] + 1]] == pat[sa[i]] {
                                is_ltype = true;
                            }
                        }
                    }
                }
                
                if is_ltype {
                    if sa[pat[j]] == UNIQUE {
                        sa[pat[j]] = j;
                    } else if sa[pat[j]] >= MULTI && sa[pat[j] + 1] == EMPTY {
                        if sa[pat[j]] - EMPTY > 2 {
                            sa[pat[j] + 2] = j;
                            sa[pat[j] + 1] = 1;  // Đặt bộ đếm
                        } else {
                            sa[pat[j]] = j;
                        }
                    } else if sa[pat[j]] >= MULTI && sa[pat[j] + 1] != EMPTY {
                        let e = pat[j];
                        let c = sa[e + 1];
                        let lfp = e + c + 2;
                        if  c + 2 < sa[pat[j]] - EMPTY {  // Chưa đến cuối bucket
                            sa[lfp] = j;
                            sa[e + 1] += 1;  // Cập nhật bộ đếm
                        } else {
                            for k in 1..c + 1 {
                                sa[e + k - 1] = sa[e + k + 1];
                            }
                            sa[e + c] = j;
                            sa[e + c + 1] = EMPTY;
                            if i >= e + 2 && i <= e + c + 1 {
                                i -= 2;
                            }
                        }
                    } else if sa[pat[j]] < EMPTY {
                        for k in pat[j]..patlen {
                            if sa[k] == EMPTY {
                                sa[k] = j;
                                break;
                            }
                        }
                    }
                }
            } else if sa[i] >= MULTI {
                i += 1;
            }
            
            i += 1;
        }
        
        // Xóa các LMS-suffix khỏi SA; một bucket có thể chứa nhiều LMS-suffix
        last_scanned_type = STYPE;
        for i in (0..pat.len() - 1).rev() {
            if pat_char_type(pat[i], pat[i + 1], last_scanned_type) == STYPE {
                last_scanned_type = STYPE;
            } else {
                if last_scanned_type == STYPE {  // pat[i + 1] có kiểu LMS
                    if sa[pat[i + 1]] <= EMPTY {
                        sa[pat[i + 1]] = UNIQUE;
                    } else {
                        sa[pat[i + 1]] += 1;
                    }
                }
                
                last_scanned_type = LTYPE;
            }
        }
        i = patlen - 1;
        while i > 0 {
            if sa[i] > EMPTY {
                let c = sa[i] - EMPTY;
                for k in 0..c {
                    sa[i - k] = EMPTY;
                }
                i -= c - 1;
            }
            
            i -= 1;
        }
        sa[0] = pat.len() - 1;
        
        // place S-suff in SA
        // init
        let mut last_scanned_type = STYPE;
        for i in (0..patlen - 1).rev() {
            if pat_char_type(pat[i], pat[i + 1], last_scanned_type) == STYPE {
                if sa[pat[i]] >= EMPTY {
                    sa[pat[i]] += 1;
                } else {
                    sa[pat[i]] = UNIQUE;
                }
                last_scanned_type = STYPE;
            } else {
                last_scanned_type = LTYPE;
            }
        }
        i = patlen - 1;
        while i > 0 {
            if sa[i] < EMPTY && sa[i] > 0 {
                let j = sa[i] - 1;
                let mut is_stype = false;
                if pat[j] < pat[j + 1] {
                    is_stype = true;
                } else if pat[j] == pat[j + 1] {  // Kiểm tra sa[i] có phải chỉ số của một S-suffix hay không
                    let next_i = sa[pat[sa[i]]];
                    if next_i >= MULTI {
                        is_stype = true;
                    } else if next_i < EMPTY && pat[sa[i]] - 1 > 0 {
                        if sa[pat[sa[i]] - 1] == EMPTY {
                            is_stype = true;
                        } else if sa[pat[sa[i]] - 1] < EMPTY {
                            if pat[sa[pat[sa[i]] - 1]] == pat[sa[i]] {
                                is_stype = true;
                            }
                        }
                    }
                }
                
                if is_stype {
                    if sa[pat[j]] == UNIQUE {
                        sa[pat[j]] = j;
                    } else if sa[pat[j]] >= MULTI && sa[pat[j] - 1] == EMPTY {
                        if sa[pat[j]] - EMPTY > 2 {
                            sa[pat[j] - 2] = j;
                            sa[pat[j] - 1] = 1;  // Đặt bộ đếm
                        } else {
                            sa[pat[j]] = j;
                        }
                    } else if sa[pat[j]] >= MULTI && sa[pat[j] - 1] != EMPTY {
                        let e = pat[j];
                        let c = sa[e - 1];
                        let num = sa[pat[j]] - EMPTY;
                        if c + 2 < num {  // Chưa đến đầu bucket
                            let rfp = e - c - 2;
                            sa[rfp] = j;
                            sa[e - 1] += 1;
                        } else {
                            for k in 1..c + 1 {
                                sa[e - k + 1] = sa[e - k - 1];
                            }
                            sa[e - c] = j;
                            sa[e - c - 1] = EMPTY;
                            if i >= e - num + 1 && i <= e - 2 {
                                i += 2;
                            }
                        }
                    } else if sa[pat[j]] < EMPTY {
                        for k in (0..pat[j]).rev() {
                            if sa[k] == EMPTY {
                                sa[k] = j;
                                break;
                            }
                        }
                    }
                }
            } else if sa[i] >= MULTI {
                i -= 1;
            }
            i -= 1;
        }
    }
    
    fn _compute_suffix_array_16_1(pat: &mut [usize], sa: &mut [usize]) {
        rename_pat(pat, sa);
        let lms_cnt = sort_lms_char(pat, sa);
        sort_lms_substr(pat, sa);
        let has_duplicated_char = construct_pat1(pat, sa, lms_cnt);
        sort_lms_suf(pat, sa, lms_cnt, has_duplicated_char);
        induced_sort(pat, sa);
    }
    
    pub fn suffix_array_16(pat: &[u8]) -> Vec<usize> {
        let mut pat = pat.into_iter().map(|x| *x as usize).collect::<Vec<usize>>();
        pat.push(0);
        let mut sa = vec![0; max(pat.len(), 256) * 1];
        _compute_suffix_array_16_1(&mut pat[..], &mut sa[..]);
        
        sa
    }
    
    fn input() -> String {
        use std::io;
        
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        String::from(input.trim())
    }
    
    
    fn main() {
        let pat = input();
        
        let sa_16 = suffix_array_16(pat.as_bytes());
        
        for i in 1..pat.len() + 1 { print!("{} ", sa_16[i] + 1) }
    }
    ```

<span id="sắp-xếp-hậu-tố-trên-bảng-chữ-cái-số-nguyên-chỉ-đọc"></span>
## Sắp xếp hậu tố trên bảng chữ cái số nguyên chỉ đọc

Dùng phương pháp phức tạp để giải quyết vấn đề phức tạp: dùng chia để trị để xử lý hạn chế về không gian.

Khó khăn khi cài đặt thuật toán nằm ở việc xây dựng BitMaps[^np12] trên $\texttt{SA}$ để thay thế các vị trí đầu/cuối bucket vốn được chỉ ra bởi T sau khi đổi tên.

Trong ngữ cảnh này, BitMaps là từ điển có thứ tự (multiset) được biểu diễn bằng vector bit (bit vector), một dạng cấu trúc dữ liệu gọn (compact data structure).

Nếu muốn tìm hiểu sâu hơn, hiện tại nên đọc bài gốc và các bài báo liên quan đến BitMaps được trích dẫn trong bài này.

<span id="sắp-xếp-hậu-tố-trên-bảng-chữ-cái-tổng-quát-chỉ-đọc"></span>
## Sắp xếp hậu tố trên bảng chữ cái tổng quát chỉ đọc

Kiến thức chuẩn bị là sắp xếp trộn và sắp xếp vun đống.

Vì tác giả còn băn khoăn về độ phức tạp thời gian của phương pháp xác định kiểu ký tự trong phần này, nên không trình bày thêm; nên đọc bài gốc để tìm hiểu kỹ hơn.

<span id="ghi-chú"></span>
## Ghi chú

[^in-place-sa-sort]: Li, Zhize; Li, Jian; Huo, Hongwei (2016).*Optimal In-Place Suffix Sorting*. Proceedings of the 25th International Symposium on String Processing and Information Retrieval (SPIRE). Lecture Notes in Computer Science. 11147. Springer. pp. 268–284. arXiv:1610.08305. doi:10.1007/978-3-030-00479-8\_22. ISBN:978-3-030-00478-1.

[^nzc09a]: Ge Nong, Sen Zhang, and Wai Hong Chan. Linear suffix array construction by almost pure induced-sorting. In Data Compression Conference (DCC), pages 193–202. IEEE, 2009.

[^sa-is-gioi-thieu]: Nên đọc [bài viết](https://riteme.site/blog/2016-6-19/sais.html) và [danh sách issue](https://github.com/riteme/riteme.github.io/issues/28) của bài viết đó.

[^thu-tu-cam-ung]: Nếu là hậu tố LML, nên cảm ứng hậu tố kiểu S trước. Khác biệt duy nhất là khi tính hậu tố LML cần tính cả ký tự canh.

[^np12]: Gonzalo Navarro and Eliana Providel. Fast, small, simple rank/select on bitmaps. In Proc. 11th International Symposium on Experimental Algorithms (SEA), pages 295–306, 2012.
