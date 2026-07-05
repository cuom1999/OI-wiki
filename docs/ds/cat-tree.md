author: ChungZH, billchenchina, Chrogeek, Early0v0, ethan-enhe, HeRaNO, hsfzLZH1, iamtwz, Ir1d, konnyakuxzy, luoguojie, Marcythm, orzAtalod, StudyingFather, wy-luke, Xeonacid, CCXXXI, chenryang, chenzheAya, CJSoft, cjsoft, countercurrent-time, DawnMagnet, Enter-tainer, GavinZhengOI, Haohu Shen, Henry-ZHR, hjsjhn, hly1204, jaxvanyang, Jebearssica, kenlig, ksyx, megakite, Menci, moon-dim, NachtgeistW, onelittlechildawa, ouuan, shadowice1984, shawlleyw, shuzhouliu, SukkaW, Tiphereth-A, x2e6, Ycrpro, yifan0305, zeningc, hcx2012Git

## Dẫn nhập

Cây phân đoạn hỗ trợ truy vấn nhanh thông tin hợp nhất của một đoạn, chẳng hạn tổng đoạn con lớn nhất, tổng đoạn, tích
liên tiếp của các ma trận trên đoạn, v.v.

Tuy nhiên, với một số bài toán có yêu cầu thời gian rất chặt, truy vấn đoạn của cây phân đoạn thông thường đôi khi vẫn còn chậm.

Nói ngắn gọn, quá trình xây cây phân đoạn cần thực hiện $O(n)$ phép hợp nhất,
còn mỗi truy vấn đoạn cần $O(\log{n})$ phép hợp nhất.
Với những thông tin như tổng đoạn thì chi phí này vẫn chấp nhận được.
Nhưng nếu cần truy vấn cơ sở tuyến tính trên đoạn, nơi độ phức tạp hợp nhất có thể lên tới $O(\log^2{w})$,
thì ngay cả $O(\log{n})$ lần hợp nhất đôi khi cũng không đạt yêu cầu thời gian.

"Cây mèo" là một dạng cây phân đoạn tĩnh: không hỗ trợ sửa đổi, chỉ hỗ trợ truy vấn đoạn nhanh.

Để xây một cây phân đoạn tĩnh như vậy cần $O(n\log{n})$ phép hợp nhất,
nhưng khi đó độ phức tạp truy vấn giảm xuống còn $O(1)$ phép hợp nhất.

Khi xử lý những thông tin đặc biệt như cơ sở tuyến tính, thậm chí có thể giảm độ phức tạp xuống $O(n\log^2{w})$.

## Nguyên lý

Khi truy vấn thông tin hợp nhất của đoạn $[l,r]$,
lấy LCA trên cây phân đoạn của nút biểu diễn $[l,l]$ và nút biểu diễn $[r,r]$.
Giả sử nút này là $p$ và đoạn mà nó biểu diễn là $[L,R]$.
Khi đó có hai tính chất quan trọng:

1.  Đoạn $[L,R]$ chắc chắn chứa $[l,r]$,
    vì nó vừa là tổ tiên của $l$ vừa là tổ tiên của $r$.

2.  Đoạn $[l,r]$ chắc chắn cắt qua trung điểm của $[L,R]$.
    Vì $p$ là LCA của $l$ và $r$, con trái của $p$ là tổ tiên của $l$ nhưng không phải tổ tiên của $r$,
    còn con phải của $p$ là tổ tiên của $r$ nhưng không phải tổ tiên của $l$.
    Do đó $l$ chắc chắn nằm trong đoạn $[L,\mathit{mid}]$,
    còn $r$ chắc chắn nằm trong đoạn $(\mathit{mid},R]$.

Nhờ hai tính chất này, có thể giảm độ phức tạp truy vấn xuống $O(1)$.

## Cài đặt

Cụ thể, khi xây cây, xét một nút trên cây phân đoạn biểu diễn đoạn $(l,r]$.

Khác với cây phân đoạn truyền thống chỉ lưu thông tin hợp nhất của $[l,r]$ trong nút này,
cây mèo lưu thêm mảng thông tin hậu tố của $(l,\mathit{mid}]$ và mảng thông tin tiền tố của $(\mathit{mid},r]$.

Như vậy độ phức tạp xây cây là $T(n)=2T(n/2)+O(n)=O(n\log{n})$;
tương tự, độ phức tạp bộ nhớ cũng tăng từ $O(n)$ ban đầu lên $O(n\log{n})$.

Phần then chốt nhất là truy vấn.

Nếu đoạn cần hỏi là $[l,r]$,
lấy LCA của nút biểu diễn $[l,l]$ và nút biểu diễn $[r,r]$, ký hiệu là $p$.

Theo hai tính chất trên, $l,r$ nằm trong đoạn mà $p$ bao phủ và đoạn truy vấn chắc chắn cắt qua trung điểm của $p$.

Điều này dẫn đến một sự thật rất quan trọng:
có thể dùng mảng tiền tố và mảng hậu tố trong $p$ để tách $[l,r]$ thành $[l,\mathit{mid}]+(\mathit{mid},r]$,
từ đó ghép lại đoạn $[l,r]$.

Quá trình này chỉ cần $O(1)$ phép hợp nhất!

Vẫn còn một điểm cần xử lý.

Độ phức tạp tìm LCA chưa phải $O(1)$:
tìm trực tiếp là $O(\log{n})$, dùng nhảy nhị phân là $O(\log{\log{n}})$,
còn chuyển sang bảng ST thì chi phí lại quá lớn.

## Dựng cây kiểu heap

Cụ thể, đệm dãy thành độ dài là một lũy thừa nguyên của $2$, rồi xây cây phân đoạn.

Khi đó, số hiệu LCA của hai nút trên cây phân đoạn chính là tiền tố chung dài nhất (LCP)
của biểu diễn nhị phân của hai số hiệu đó.

Từ biểu diễn nhị phân của $x$ và $y$ có công thức `lcp(x,y)=x>>digits[x^y]`.
Trong đó `digits[x]` biểu thị số bit của $x$ trong hệ nhị phân, tức $\lfloor \log_2 x \rfloor+1$.

Vì vậy, chỉ cần tiền xử lý mảng `digits` là có thể tìm LCA.

Như vậy đã xây dựng được một cây mèo.

Do quá trình xây cây cần tính tiền tố và hậu tố,
nên với những thông tin như cơ sở tuyến tính, dù phép hợp nhất là $O(\log^2{w})$ nhưng mỗi lần cập nhật tiền tố/hậu tố chỉ
cần $O(\log{w})$.
Cây mèo có thể tối ưu cơ sở tuyến tính tĩnh trên đoạn
từ độ phức tạp $O(n\log^2{w}+m\log^2{w}\log{n})$ xuống $O(n\log{n}\log{w}+m\log^2{w})$.

### Tham khảo

-   [blog của immortalCO](https://immortalco.blog.uoj.ac/blog/2102)
-   [\[Kle77\]](http://ieeexplore.ieee.org/document/1675628/) V. Klee, "Can the Measure of be Computed in Less than
    O (n log n) Steps?," Am. Math. Mon., vol. 84, no. 4, pp. 284–285, Apr. 1977.
-   [\[BeW80\]](https://www.tandfonline.com/doi/full/10.1080/00029890.1977.11994336) Bentley and Wood, "An Optimal Worst
    Case Algorithm for Reporting Intersections of Rectangles," IEEE Trans. Comput., vol. C–29, no. 7, pp. 571–577,
    Jul. 1980.
