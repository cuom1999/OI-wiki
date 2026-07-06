Kiến thức cần biết: [phân khối](../ds/decompose.md).

Lập bảng đơn giản là kỹ thuật tính trước đáp án ứng với mọi dữ liệu vào có thể
xuất hiện trong cuộc thi, lưu lại, rồi khai báo một mảng chứa đáp án trong mã
nguồn và in trực tiếp.

Lưu ý kỹ thuật này chỉ phù hợp với những bài có miền giá trị đầu vào nhỏ, chẳng
hạn đầu vào chỉ có một số và phạm vi rất nhỏ. Nếu không, mã nguồn có thể quá
dài, bị MLE, hoặc thời gian tạo bảng quá lớn.

???+ note "Ví dụ"
    Gọi $f(x)$ là số bit $1$ trong biểu diễn nhị phân của số nguyên $x$. Cho
    một số nguyên dương $n$ ($n\leq 10^9$), in
    $\sum_{i=1}^n f^2(i)$.

Nếu với mỗi $n$ đều in trực tiếp $f(n)$, ngoài khả năng bị MLE, mã nguồn còn
có thể vượt giới hạn độ dài và không biên dịch được.

Xét cách tối ưu bảng đáp án. Dựa trên tư tưởng
[phân khối](../ds/decompose.md), đặt một bước nhảy hợp lý $m$ (thường phụ
thuộc vào giới hạn độ dài mã nguồn). Với khối thứ $i$, tính trước giá trị:

$$
\sum_{k=\frac{n}{m}(i-1)+1}^{\frac{ni}{m}} f^2(k)
$$

Sau đó khi in đáp án, cũng xử lý theo tư tưởng phân khối: phần thuộc khối
đầy đủ dùng giá trị đã tiền xử lý, còn phần không trọn khối thì tính vét cạn.

Nói chung, dạng bài phù hợp là những bài mà việc tính một giá trị hàm đơn lẻ
$f(x)$ rất nhanh, nhưng cần tổng hợp rất nhiều giá trị hàm, chẳng hạn lấy tổng,
tích hoặc một phép toán có thể gộp nhanh. Khi liệt kê trực tiếp sẽ quá thời
gian và chưa tìm được lời giải chuẩn, lập bảng theo đoạn là một lựa chọn đáng
cân nhắc.

???+ note "Lưu ý"
    Nếu trong bài trên, số mũ không cố định nhưng có phạm vi nhỏ, cũng có thể
    cân nhắc lập bảng.

### Bài ví dụ

[BZOJ 3798: Số nguyên tố đặc biệt](https://hydro.ac/p/bzoj-P3798): Tính có bao nhiêu số
nguyên tố trong đoạn $[l,r]$ có thể phân tích thành tổng bình phương của hai số
nguyên dương.

[Luogu P1822: Dấu vân tay ma thuật](https://www.luogu.com.cn/problem/P1822)
