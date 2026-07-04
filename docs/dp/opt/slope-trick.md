<span id="&#x5F15;&#x5165;"></span>
## Dẫn nhập

Với một lớp bài toán DP hai chiều, nếu hàm giá trị $f(i,x)$ là hàm lồi theo
$x$ với mọi $i$ cố định, ta có thể xem toàn bộ hàm $f(i,\cdot)$ là trạng thái
tại $i$, và duy trì sai phân (hay độ dốc) của nó

$$
\Delta f(i,x) = f(i,x+1)-f(i,x)
$$

thay vì duy trì trực tiếp hàm. Cách nghĩ tối ưu hóa DP này thường giúp đơn giản
hóa phép chuyển trạng thái, và được gọi là Slope Trick.

???+ info "\"Độ dốc\""
    Trong phần lớn bài toán, các hàm chỉ được lấy giá trị tại các điểm nguyên,
    nên việc gọi nó là sai phân hay độ dốc về bản chất không khác nhau. Trong
    bài viết này, theo thuật ngữ Slope Trick, ta thống nhất gọi là độ dốc.

Trong từng bài cụ thể, cách duy trì độ dốc có thể khác nhau. Nếu miền giá trị
của độ dốc hẹp, việc duy trì các điểm mà độ dốc thay đổi (tức điểm gãy) sẽ tiện
lợi hơn; nếu miền xác định của hàm hẹp, việc duy trì trực tiếp dãy độ dốc có thể
tiện lợi hơn. Trong các tình huống phức tạp hơn, có thể cần duy trì đồng thời
giá trị độ dốc của mỗi đoạn và độ dài của đoạn đó. Bất kể cách duy trì cụ thể là
gì, bản chất của lớp bài toán này là lợi dụng việc dãy độ dốc chỉ thay đổi ít
trong chuyển trạng thái để đơn giản hóa phép chuyển. Vì vậy, tất cả chúng đều có
thể được gọi là Slope Trick.

<span id="&#x51F8;&#x51FD;&#x6570;"></span>
## Hàm lồi

Trước khi thảo luận các bài toán cụ thể, cần nắm một số tính chất cơ bản của
hàm lồi, cũng như cách độ dốc của nó thay đổi khi thực hiện các phép biến đổi
khác nhau trên hàm lồi.

<span id="&#x5B9E;&#x8F74;&#x4E0A;&#x7684;&#x51F8;&#x51FD;&#x6570;"></span>
### Hàm lồi trên trục thực

Định nghĩa tổng quát hơn của hàm lồi được phát biểu trên $\mathbf R$.

![](../images/slope-trick/epigraph-convex-def.svg)

???+ abstract "Hàm lồi trên $\mathbf R$"
    Nếu hàm $f:\mathbf R\rightarrow\mathbf R\cup\{\pm\infty\}$ thỏa mãn, với
    mọi $x,y\in\mathbf R$ và $\alpha\in(0,1)$,
    
    $$
    f(\alpha x+(1-\alpha)y) \le \alpha f(x)+(1-\alpha)f(y),
    $$
    
    thì $f$ được gọi là **hàm lồi** (convex function). Quy tắc tính toán với
    $\pm\infty$ được quy ước như sau: $\pm\infty$ nhân với bất kỳ số thực dương
    nào, hoặc cộng với bất kỳ số thực nào, đều bằng chính nó; và với mọi số thực
    $x\in\mathbf R$ luôn có $-\infty<x<+\infty$.

Tất nhiên, nếu đổi dấu bất đẳng thức thành $\ge$, ta tương ứng có hàm lõm[^convex-def].
Vì với mọi hàm lõm $f$, hàm $-f$ luôn là hàm lồi, nên mục này chỉ xét hàm lồi.

???+ info "Bài viết chỉ xét hàm lồi đúng"
    Để tránh phải thảo luận giá trị của $\infty-\infty$ và các phân tích phức
    tạp bổ sung, khi nói về các khái niệm liên quan đến hàm lồi, bài viết này
    luôn mặc định hàm không nhận giá trị $-\infty$ và không phải lúc nào cũng
    bằng $+\infty$. Những hàm lồi như vậy được gọi là **hàm lồi đúng** (proper
    convex function). Điều này đã đủ để hiểu các nội dung cần dùng trong lập
    trình thi đấu.

Tất nhiên, hàm $f$ thường không được định nghĩa trên mọi số thực. Nếu miền xác
định của $f$ chỉ là một tập con của $\mathbf R$, ta có thể mở rộng nó thành hàm
trên $\mathbf R$:

$$
\tilde f(x) = \begin{cases} f(x), & x\in\operatorname{dom}f,\\ +\infty,& x\notin\operatorname{dom}f.\end{cases}
$$

Khi đó, ta nói $f$ là hàm lồi khi và chỉ khi hàm mở rộng tương ứng $\tilde f$
thỏa mãn định nghĩa hàm lồi ở trên. Vì vậy, nếu không nói rõ thêm, miền xác định
của các hàm lồi được nhắc đến trong bài viết này đều là tập số thực $\mathbf R$.
Hiển nhiên, hàm lồi $f$ chỉ có thể nhận giá trị hữu hạn trên một khoảng (tức một
tập con lồi của $\mathbf R$).

???+ example "Ví dụ đơn giản"
    Các ví dụ thường gặp về hàm lồi gồm:
    
    1.  Hàm hằng: $f(x)=c$, với $c\in\mathbf R$;
    2.  Hàm bậc nhất: $f(x)=kx+b$, với $k,b\in\mathbf R$ và $k\neq 0$;
    3.  Hàm giá trị tuyệt đối: $f(x)=|x-a|$, với $a\in\mathbf R$;
    4.  Kết quả khi hạn chế bất kỳ hàm lồi nào trên một khoảng, chẳng hạn
        $0_{[a,b]}(x)$ (trong ngữ cảnh giải tích lồi, hàm này cũng được gọi là
        hàm chỉ thị của $[a,b]$).

Tất nhiên, có thể kết hợp các phép biến đổi bảo toàn tính lồi được nêu bên dưới
để tạo ra những hàm lồi phức tạp hơn.

<span id="&#x79BB;&#x6563;&#x70B9;&#x96C6;&#x4E0A;&#x7684;&#x51F8;&#x51FD;&#x6570;"></span>
### Hàm lồi trên tập điểm rời rạc

Trong lập trình thi đấu, nhiều hàm chỉ được định nghĩa tại một phần các giá trị
nguyên. Nói chung, chúng không phải là hàm lồi theo định nghĩa ở trên, vì miền
xác định không còn là tập lồi. Để xử lý tình huống này, cần định nghĩa riêng
tính lồi của hàm trên tập điểm rời rạc. Nói ngắn gọn, trước hết cần nội suy
tuyến tính hàm để mở rộng miền xác định thành một khoảng, rồi mới xét tính lồi
của nó.

![](../images/slope-trick/epigraph-convex-discrete.svg)

???+ abstract "Hàm lồi trên tập điểm rời rạc"
    Cho $S\subset\mathbf R$ là tập điểm rời rạc, nghĩa là với mọi khoảng đóng
    $[a,b]$, tập $S\cap[a,b]$ đều hữu hạn. Với hàm
    $f:S\rightarrow\mathbf R\cup\{\pm\infty\}$, ta có thể định nghĩa hàm
    $\tilde f:\mathbf R\rightarrow\mathbf R\cup\{\pm\infty\}$ sao cho:
    
    -   Khi $x\in S$, $\tilde f(x)=f(x)$,
    -   Khi $x\in(\inf S,\sup S)\setminus S$, đặt
        $s_-=\max\{s\in S:s\le x\}$, $s_+=\min\{s\in S:s\ge x\}$, khi đó
    
        $$
        \tilde f(x) = \dfrac{s_+-x}{s_+-s_-}f(s_-)+\dfrac{x-s_-}{s_+-s_-}f(s_+),
        $$
    -   Khi $x\notin[\inf S,\sup S]$, $\tilde f(x)=+\infty$.
    
    Nếu $\tilde f(x)$ là hàm lồi trên $\mathbf R$, thì $f(x)$ được gọi là **hàm
    lồi** trên $S$.

Vì hàm lồi trên $\mathbf R$ tiện xử lý hơn, trong bài viết này, nếu không nói rõ
thêm, hàm lồi luôn chỉ hàm lồi trên $\mathbf R$. Nếu một hàm trong bài viết chỉ
cho giá trị tại một số điểm nguyên, thì giá trị của nó tại các số thực khác
được xác định bởi $\tilde f$ trong định nghĩa, tương đương với việc trực tiếp
thảo luận hàm tuyến tính từng đoạn tương ứng $\tilde f$.

Hàm lồi trên tập số nguyên $\mathbf Z$ có một định nghĩa tương đương trực quan hơn:

???+ note "Định nghĩa tương đương của hàm lồi trên $\mathbf Z$"
    Hàm $f:\mathbf Z\rightarrow\mathbf R\cup\{\pm\infty\}$ là hàm lồi khi và
    chỉ khi
    
    $$
    f(x)-f(x-1)\le f(x+1)-f(x)
    $$
    
    đúng với mọi $x\in\mathbf Z$.

??? note "Chứng minh"
    Mệnh đề này là hệ quả đơn giản của cách đặc trưng hàm lồi bằng độ dốc.
    
    Nếu $f$ là hàm lồi trên $\mathbf Z$, theo tính chất độ dốc không giảm, ta có
    
    $$
    \Delta f(x-1,x)\le \Delta f(x-1,x+1) \le\Delta f(x,x+1).
    $$
    
    Đây chính là điều kiện ở trên.
    
    Ngược lại, nếu điều kiện ở trên đúng, thì với mọi $x_1<x_2$, ta có
    
    $$
    \Delta f(x_1,x_2) = \dfrac{1}{x_2-x_1}\sum_{i=x_1}^{x_2-1}\left(f(i+1)-f(i)\right).
    $$
    
    Giá trị này là trung bình cộng của các sai phân với $x_1\le i<x_2$. Nếu
    tăng $x_2$ thêm một, ta tương đương chèn thêm một sai phân lớn hơn; nếu tăng
    $x_1$ thêm một, ta tương đương bỏ đi sai phân nhỏ nhất. Cả hai thao tác đều
    làm trung bình tăng lên. Điều đó cho thấy độ dốc $\Delta f(x_1,x_2)$ không
    giảm, tức $f$ là hàm lồi trên $\mathbf Z$.

Nói cách khác, chỉ cần độ dốc (sai phân) đơn điệu không giảm, dãy đó có thể
được xem là một hàm lồi trên $\mathbf Z$.

<span id="&#x51F8;&#x51FD;&#x6570;&#x7684;&#x4E24;&#x79CD;&#x523B;&#x753B;"></span>
### Hai cách đặc trưng hàm lồi

Thực ra, cách đặc trưng hàm lồi bằng độ dốc cũng có thể mở rộng cho trường hợp
tổng quát.

???+ note "Đặc trưng hàm lồi bằng độ dốc"
    Cho $S$ la $\mathbf R$ hoac tap con roi rac cua no. Ham $f:S\rightarrow\mathbf R\cup\{\pm\infty\}$ la ham loi khi va chi khi do doc
    
    $$
    \Delta f(x_1,x_2) = \dfrac{f(x_2)-f(x_1)}{x_2-x_1}
    $$
    
    la ham khong giam theo ca $x_1$ va $x_2$, voi moi $x_1,x_2\in S$ va $x_1<x_2$.

??? note "Chung minh"
    Voi ham $f(x)$ tren $\mathbf R$ va $x_1<x_2$, voi $\alpha\in(0,1)$, dat $x_3=\alpha x_1+(1-\alpha)x_2$. Khi do
    
    $$
    \Delta f(x_1,x_3) \le \Delta f(x_1,x_2) \le \Delta f(x_3,x_2)
    $$
    
    tuong duong voi
    
    $$
    \dfrac{f(x_3)-f(x_1)}{1-\alpha} \le f(x_2)-f(x_1) \le \dfrac{f(x_2)-f(x_3)}{\alpha}.
    $$
    
    Hai bat dang thuc hai phia deu tuong duong voi $f(x_3)\le\alpha f(x_1)+(1-\alpha)f(x_2)$, tuc tinh loi cua ham $f(x)$.
    
    Voi ham $f(x)$ tren tap con roi rac $S$ cua $\mathbf R$, tinh can thiet cua dieu kien do doc khong giam co the suy ra tu tinh loi cua $\tilde f(x)$. Bay gio can chung minh tinh du. De lam viec nay, chi can chung minh $\Delta\tilde f(x_1,x_2)$ cung khong giam. Dat $S=\{s_i\}$ voi $s_i$ tang nghiem ngat theo $i$, va gia su $s_{i_1}\le x_1\le s_{i_1+1}$, $s_{i_2}\le x_2\le s_{i_2+1}$; hien nhien $i_1\le i_2$. Dat $\Delta_i=\Delta f(s_i,s_{i+1})$. Khi do, co the chung minh $\Delta_{i_1}\le\Delta\tilde f(x_1,x_2)\le\Delta_{i_2}$.
    
    Xet hai truong hop. Neu $i_1=i_2$, thi $\Delta_{i_1}=\Delta\tilde f(x_1,x_2)=\Delta_{i_2}$, bat dang thuc hien nhien dung. Nguoc lai, ta co
    
    $$
    \Delta\tilde f(x_1,x_2) = \dfrac{1}{x_2-x_1}\left((s_{i_1+1}-x_1)\Delta_{i_1}+(x_2-s_{i_2})\Delta_{i_2}+\sum_{j=i_1+1}^{i_2-1}(s_{j+1}-s_j)\Delta_j\right).
    $$
    
    Theo tinh chat do doc tang tren $S$, $\Delta_i$ tang theo $i$, nen $\Delta_{i_1}\le\Delta\tilde f(x_1,x_2)\le\Delta_{i_2}$.
    
    Dung ket luan nay, voi $x_1<x_2$ va $\alpha\in(0,1)$, dat $x_3=\alpha x_1+(1-\alpha)x_2$, va chon $i_3$ sao cho $s_{i_3}\le x_3\le s_{i_3+1}$. Khi do
    
    $$
    \Delta\tilde f(x_1,x_3) \le \Delta_{i_3} \le \Delta\tilde f(x_3,x_2).
    $$
    
    Thay bieu thuc cua $x_3$ vao se thu duoc tinh loi cua $\tilde f(x)$.

Do doc don dieu khong giam co the xem la mot dinh nghia tuong duong cua ham loi. Chinh vi do doc cua ham loi co tinh don dieu, khi duy tri do doc, ta thuong can chon cac cau truc du lieu nhu [heap (hang doi uu tien)](../../ds/heap.md) hoac [cay can bang](../../ds/bst.md).

Bai viet nay con dung mot dac trung tuong duong khac cua ham loi. Voi ham $f:\mathbf R\rightarrow\mathbf R\cup\{\pm\infty\}$, ta co the xet vung nam phia thuong do thi cua ham trong mat phang, tuc

$$
\operatorname{epi} f = \{(x,y)\in\mathbf R^2 : y\ge f(x)\}.
$$

Vung nay con duoc goi la **thuong do thi** cua ham $f$ (epigraph). Tinh loi cua ham tuong duong voi tinh loi cua thuong do thi:

???+ note "Dac trung ham loi bang thuong do thi"
    Ham $f:\mathbf R\rightarrow\mathbf R\cup\{\pm\infty\}$ la ham loi khi va chi khi $\operatorname{epi}f$ la tap loi trong $\mathbf R^2$.

??? note "Chung minh"
    Neu $f$ la ham loi, thi voi $(x_1,y_1),(x_2,y_2)\in\operatorname{epi}f$ va bat ky $\alpha\in(0,1)$, ta co
    
    $$
    \alpha y_1+(1-\alpha)y_2 \ge \alpha f(x_1)+(1-\alpha)f(x_2) \ge f(\alpha x_1+(1-\alpha) x_2).
    $$
    
    Do do, $\alpha(x_1,y_1)+(1-\alpha)(x_2,y_2)\in\operatorname{epi}f$.
    
    Nguoc lai, neu $\operatorname{epi}f$ la tap loi, thi voi moi $x_1<x_2$ va $\alpha\in(0,1)$, ta co
    
    $$
    \alpha(x_1,f(x_1))+(1-\alpha)(x_2,f(x_2)) \in \operatorname{epi}f.
    $$
    
    Dieu nay tuong duong voi $\alpha f(x_1)+(1-\alpha)f(x_2)\ge f\left(\alpha x_1+(1-\alpha)x_2\right)$, tuc tinh loi cua $f$.

Lat nua ta se thay, bang thuong do thi, co the lien he tich chap duoi dung cua ham loi voi tong Minkowski cua tap loi.

<span id="&#x51F8;&#x51FD;&#x6570;&#x7684;&#x53D8;&#x6362;"></span>
## Cac phep bien doi ham loi

Tiep theo, bai viet gioi thieu mot so phep bien doi bao toan tinh loi thuong gap trong Slope Trick.

<span id="&#x975E;&#x8D1F;&#x7EBF;&#x6027;&#x7EC4;&#x5408;"></span>
### To hop tuyen tinh khong am

Voi hai ham loi $f$ va $g$, cung cac so thuc khong am $\alpha,\beta\ge0$, ham $\alpha f+\beta g$ cung la ham loi. Hon nua,

$$
\Delta(\alpha f+\beta g) = \alpha\Delta f + \beta\Delta g.
$$

Vi vay, neu da duy tri do doc cua cac ham loi $f$ va $g$, de thu duoc do doc cua to hop tuyen tinh khong am $\alpha f+\beta g$, chi can tinh theo tung doan.

Trong cac bai toan duy tri do doc, thuong co mot ham co dang kha don gian; khi do co the giam do phuc tap sua doi bang lazy tag. Trong cac bai toan duy tri diem gay, de tinh cac diem gay cua do doc cua $f+g$, chi can tron cac diem gay do doc cua $f$ va $g$.

<span id="&#x5377;&#x79EF;&#x4E0B;&#x786E;&#x754C;minkowski-&#x548C;"></span>
### Tich chap duoi dung (tong Minkowski)

Mot phep toan thuong gap khac tren ham loi la tich chap duoi dung. Voi hai ham $f$ va $g$, ham

$$
h(x) = \inf_{y\in\mathbf R}f(y)+g(x-y)
$$

duoc goi la **tich chap duoi dung**[^inf-conv] (infimal convolution) cua $f$ va $g$. Neu $f$ va $g$ deu la ham loi, tich chap duoi dung cua chung cung la ham loi.

![](../images/slope-trick/epigraph-convex-minkowski.svg)

??? example "Giai thich hinh ve"
    Nhu trong hinh, de tim tich chap duoi dung $h$ cua $f$ va $g$, co the xem moi diem thuong do thi cua $f$ (duong dut net mau do trong hinh thu ba) la goc toa do, roi ve do thi cua $g$ (duong dut net mau xanh trong hinh thu ba) trong he toa do tuong ung. Khi goc toa do di chuyen doc theo do thi cua $f$, bien dang quy dao ma do thi (thuong do thi) cua $g$ quet ra, cu the la bao loi duoi, chinh la do thi cua $h$. Co the thay moi doan do doc cua $h$ hoac la doan do doc cua $f$, hoac la doan do doc cua $g$: chung chi duoc sap xep lai theo do lon do doc. Trong qua trinh nay, vai tro cua $f$ va $g$ co the hoan doi; neu cho do thi cua $f$ di chuyen doc theo do thi cua $g$, ket qua van nhu nhau.

Ve truc giac hinh hoc, $\operatorname{epi}h$ chinh la [tong Minkowski](../../geometry/convex-hull.md#tổng-minkowski) cua $\operatorname{epi}f$ va $\operatorname{epi}g$. Neu $f$ va $g$ deu la ham tuyen tinh tung doan, thi $h$ cung la ham tuyen tinh tung doan, va cac doan do doc cua no co the xem la ket qua tron (roi sap xep lai) cac doan do doc cua $f$ va $g$.

??? note "Chung minh"
    Gia su $f,g$ deu la ham loi, va $h$ la tich chap duoi dung cua chung. Lay $x_1<x_2$ va $\alpha\in(0,1)$. Theo dinh nghia tich chap duoi dung, voi moi $\varepsilon>0$, ton tai $y_i,z_i\in\mathbf R$ sao cho $y_i+z_i=x_i$ va
    
    $$
    h(x_i) + \varepsilon > f(y_i) + g(z_i).
    $$
    
    Do do, ket hop tinh loi cua $f,g$ va dinh nghia cua $h$, ta co
    
    $$
    \begin{aligned}
    \alpha h(x_1)+(1-\alpha)h(x_2) + \varepsilon 
    &> \alpha f(y_1) + (1-\alpha) f(y_2) + \alpha g(z_1) + (1-\alpha) g(z_2)\\
    &\ge f\left(\alpha y_1+(1-\alpha)y_2\right) + g\left(\alpha z_1+(1-\alpha)z_2\right)\\
    &\ge h(\alpha x_1+(1-\alpha)x_2).
    \end{aligned}
    $$
    
    Vi $\varepsilon>0$ duoc chon tuy y, suy ra
    
    $$
    \alpha h(x_1)+(1-\alpha)h(x_2) \ge h(\alpha x_1+(1-\alpha)x_2).
    $$
    
    Tu do thu duoc tinh loi cua $h$.
    
    Tiep theo, doi voi truc giac hinh hoc, noi mot cach chat che thi chi co the chung minh ket luan sau:
    
    $$
    \operatorname{epi} f + \operatorname{epi} g\subseteq \operatorname{epi}h \subseteq \operatorname{cl}(\operatorname{epi} f + \operatorname{epi} g).
    $$
    
    Trong do, $\operatorname{cl}$ bieu thi bao dong.
    
    Voi moi $(x,y)\in\operatorname{epi} f + \operatorname{epi} g$, ton tai $(x_1,y_1)\in\operatorname{epi} f$ va $(x_2,y_2)\in\operatorname{epi} g$ sao cho $x=x_1+x_2$ va
    
    $$
    y = y_1+y_2 \ge f(x_1)+g(x_2) \ge h(x_1+x_2)=h(x).
    $$
    
    Do do, $(x,y)\in\operatorname{epi}h$. Dieu nay cho thay $\operatorname{epi} f + \operatorname{epi} g\subseteq \operatorname{epi}h$.
    
    Nguoc lai, voi moi $(x,y)\in\operatorname{epi}h$, ta co $y\ge h(x)$. Theo dinh nghia cua $h$, voi moi $\varepsilon>0$, ton tai $x_1+x_2=x$ sao cho
    
    $$
    y + \varepsilon > f(x_1) + g(x_2).
    $$
    
    Dat $y_1=f(x_1)$ va $y_2=g(x_2)$, ta co $y+\varepsilon>y_1+y_2$. Dieu nay noi rang voi moi $\varepsilon>0$, diem $(x_1,y_1)+(x_2,y_2)\in\operatorname{epi} f + \operatorname{epi} g$ nam tren doan thang noi $(x,y)$ va $(x,y+\varepsilon)$. Cho $\varepsilon\rightarrow 0$, ta duoc $\operatorname{epi}h \subseteq \operatorname{cl}(\operatorname{epi} f + \operatorname{epi} g)$.
    
    Vi vay, $\operatorname{epi} f + \operatorname{epi} g = \operatorname{epi}h$ khi va chi khi no la tap loi dong. Mot dieu kien de dieu nay dung la $f$ va $g$ deu la ham loi dung va [nua lien tuc duoi](https://en.wikipedia.org/wiki/Semi-continuity). Voi cac ung dung trong lap trinh thi dau, dieu nay da du, chang han ham tuyen tinh tung doan luon thoa man cac dieu kien nay.

Trong bai toan thuc te, neu mot trong hai ham $f$ va $g$ co it doan do doc, co the chen truc tiep cac doan do doc it hon vao tap doan do doc nhieu hon; neu khong, co the can dung cac ky thuat nhu [gop theo heuristic](../../graph/dsu-on-tree.md) hoac [heap co the gop](../../ds/heap.md) de giam do phuc tap tong the cua phep gop, hoac tim cach xu ly rieng theo bai toan cu the.

<span id="&#x6700;&#x503C;&#x64CD;&#x4F5C;"></span>
### Phep toan cuc tri

Gia tri lon nhat cua hai ham loi van la ham loi, nhung gia tri nho nhat cua hai ham loi chua chac con la ham loi.

Nhieu phep lay nho nhat thuong gap co the chuyen thanh tich chap duoi dung:

???+ example "Vi du"
    -   $f(x)=\min_{y\in [x+a,x+b]}g(y)$ van la ham loi, vi no co the xem la tich chap duoi dung:
    
        $$
        f(x) = \min_{y\in\mathbf R}g(y) + 0_{[-b,-a]}(x-y).
        $$
    -   $f(x)=\min\{g(x-a_i)+b_i\}$ la ham loi tren $\mathbf Z$, mien la $g(x)$ la ham loi tren $\mathbf Z$, va ham $h:a_i\mapsto b_i$ duoc dinh nghia tren tap huu han $\{a_i\}\subset\mathbf Z$ cung la ham loi tren tap roi rac do. Ly do la sau khi mo rong, ham $\tilde f(x)$ co the xem la tich chap duoi dung:
    
        $$
        \tilde f(x) = \min_{y\in\mathbf R}\tilde h(y)+\tilde g(x-y).
        $$
    
        Do do, ham $f(x)$ truoc khi mo rong cung la ham loi.

Nhung khong phai moi phep lay nho nhat deu bao toan tinh loi.

???+ example "Phan vi du"
    Cho $g(x)$ la ham loi. Ham $f(x)=\min\{g(x-1)+kx,g(x)\}$ khong nhat thiet la ham loi.

Trong mot so bai toan dac biet, mac du phuong trinh chuyen trang thai cua quy hoach dong co the viet duoi dang gia tri nho nhat cua hai ham loi, va kho chuyen thanh dang tich chap duoi dung, ham gia tri van co the giu tinh loi. Khi xu ly thuc te, thuong can ket hop lap bang va du doan de tim cach chuyen do doc hop ly cho loai bai nay.

Sau khi hieu ham loi va cac phep bien doi thuong gap cua no, ta co the thong qua cac bai toan cu the de nam cach toi uu hoa DP bang Slope Trick. Cac vi du trong bai viet duoc chia dai khai thanh hai nhom: duy tri diem gay va duy tri do doc, nham giup hieu cac thao tac thuong gap va chi tiet cai dat cua hai cach duy tri nay. Tuy nhien, nhu da nhan manh o tren, cach duy tri khong phai la ban chat cua Slope Trick; can chon cach duy tri doan do doc phu hop theo yeu cau cua tung bai toan.

<span id="&#x7EF4;&#x62A4;&#x62D0;&#x70B9;"></span>
## Duy tri diem gay

Lop bai toan nay thuong xuat hien khi can toi thieu hoa tong cua nhieu gia tri tuyet doi. Vi trong cac bai toan do, gia tri tuyet doi cua do doc cua ham gia tri khong lon, nen duy tri cac diem gay noi do doc thay doi se tien loi hon.

Duy tri diem gay nghia la duy tri cac diem trong ham tuyen tinh tung doan tai do do doc thay doi. Tuong duong, voi moi doan do doc $[l_i,r_i]$ co do doc $k_i$, chi duy tri thong tin hai dau mut cua no, con ban than do doc khong can duy tri rieng; do do, trong lop bai toan nay, moi khi do doc thay doi, no phai chi thay doi mot luong co dinh. Chang han, neu duy tri tap diem gay $\xi_{-s}\le\cdots\le\xi_{-1}\le\xi_{1}\le\cdots\le\xi_{t}$, dieu do tuong duong voi: do doc bang $0$ tren khoang $[\xi_{-1},\xi_1]$; moi khi di sang trai qua mot diem gay, do doc giam mot; moi khi di sang phai qua mot diem gay, do doc tang mot. Vi vay, tren khoang $[\xi_2,\xi_3]$, do doc la $2$; tren khoang $[\xi_{-3},\xi_{-2}]$, do doc la $-2$; va tuong tu. Viet bang ngon ngu hinh thuc, ham co the duoc bieu dien bang cac diem gay cua do doc nhu sau:

$$
f(x) = f(\xi_1) + \sum_{i=-s}^{-1}\max\{\xi_i-x,0\} + \sum_{i=1}^{\ell}\max\{x-\xi_i,0\}.
$$

Gia tri nho nhat cua no la $f(\xi_{-1})=f(\xi_1)$, va co the dat duoc tai bat ky vi tri nao trong khoang $[\xi_{-1},\xi_1]$.

![](../images/slope-trick/epigraph-convex-kinks.svg)

<span id="&#x4F8B;&#x9898;&#x6700;&#x5C0F;&#x6210;&#x672C;&#x9012;&#x589E;&#x5E8F;&#x5217;"></span>
### Vi du: day tang voi chi phi nho nhat

???+ example "[\[BalticOI 2004\] Sequence](https://www.luogu.com.cn/problem/P4331)"
    Cho day $\{a_i\}$ do dai $n$. Hay tim mot day tang nghiem ngat $\{b_i\}$ sao cho $\sum_i|a_i-b_i|$ nho nhat, va in ra gia tri nho nhat cung mot phuong an toi uu bat ky $\{b_i\}$.

??? note "Loi giai"
    Truoc het, $\{b_i\}$ tang nghiem ngat tuong duong voi $\{b'_i\}=\{b_i-i\}$ khong giam. Vi vay, chi can tim day khong giam $\{b'_i\}=\{b_i-i\}$ co tong sai lech nho nhat so voi $\{a'_i\}=\{a_i-i\}$, roi khoi phuc lai $\{b_i\}$.
    
    Xet loi giai DP truc tiep. Dat $f_i(x)$ la sai lech nho nhat giua cac so da chon va $i$ so dau cua $\{a'_i\}$, khi da chon $i$ so dau cua day $\{b'_i\}$ va so thu $i$ khong vuot qua $x$:
    
    $$
    f_i(x) = \min\sum_{j=1}^i|a'_j-b'_j|\text{ s.t. }b'_1\le b'_2\le\cdots\le b'_i\le x.
    $$
    
    De thay phuong trinh chuyen trang thai la
    
    $$
    f_i(x) = \min_{y\le x}f_{i-1}(y)+|a'_i-y|.
    $$
    
    Trang thai ban dau la $f_0(x)\equiv 0$, va cuoi cung can tim $\min_xf_n(x)$. Dung cac phep bien doi ham loi da neu o tren, de chuyen tu $f_{i-1}(x)$ sang $f_i(x)$ can hai buoc:
    
    1.  Truoc het, cong them $|a'_i-x|$, tuong duong voi tang tat ca doan do doc trong khoang $(-\infty,a'_i]$ them $-1$, va tang tat ca doan do doc trong khoang $[a'_i,+\infty)$ them $1$;
    2.  Lay gia tri nho nhat cua ham thu duoc, bien $g(x)=f_{i-1}(x)+|a'_i-x|$ thanh $f_i(x)=\min_{y\le x}g(y)$. Theo phan tich o tren, viec nay tuong duong voi lay tich chap duoi dung cua $g(x)$ va $0_{[0,+\infty)}$. Vi ham sau chi co mot doan do doc duy nhat, do doc bang $0$ va keo dai vo han sang phai, chen no vao cac doan do doc cua $g(x)$ tuong duong voi xoa tat ca doan do doc duong.
    
    Sau khi lam ro cac thao tac nay, ta da co the truc tiep dung cay can bang de duy tri tat ca doan do doc, nhung code se phuc tap. Chu y rang trong bai nay do doc moi lan thay doi nhieu nhat $1$, nen gia tri tuyet doi cua moi doan do doc khong vuot qua $n$. Thay vi truc tiep duy tri cac doan do doc, duy tri truc tiep cac diem gay cua do doc se tien hon.
    
    Gia su tap diem gay cua $f_{-1}(x)$ la $\xi_{-k}\le\cdots\le\xi_{-1}\le\xi_{1}\le\cdots\le\xi_{\ell}$. Khi do hai buoc o tren lan luot tuong ung voi:
    
    1.  Them mot diem gay $a'_i$ cua doan do doc am va mot diem gay $a'_i$ cua doan do doc duong;
    2.  Pop tat ca diem gay $\xi_1,\cdots,\xi_{\ell}$ cua cac doan do doc duong.
    
    Khi duy tri thuc te, vi sau moi thao tac khong con diem gay cua doan do doc duong, tuc cac diem gay cua do doc co dang $\xi_{-k}\le\cdots\le\xi_{-1}$, va thao tac luon xay ra tai bien giua doan do doc am va duong, nen chi can dung mot max-heap de luu tat ca diem gay. Hai buoc lan luot tuong ung voi:
    
    1.  Chen $a'_i$ hai lan;
    2.  Pop dinh heap.
    
    Tat nhien, sau moi lan can duy tri gia tri nho nhat hien tai cua ham. Vi sau khi thao tac ket thuc khong con doan do doc duong, gia tri nho nhat cua ham la gia tri tai dinh max-heap. Gia su truoc moi thao tac, dinh heap la $\xi_{-1}$ va gia tri nho nhat la $f_{i-1}(\xi_{-1})$. Vi dinh heap bi pop la diem gay nho nhat cua doan do doc duong, gia tri nho nhat cua ham bang gia tri ham tai do, nen chi can tinh gia tri ham tai dinh heap truoc khi pop, tuc
    
    $$
    f_{i-1}(\max\{a'_i,\xi_{-1}\})+|\max\{a'_i,\xi_{-1}\}-a'_i|=f_{i-1}(\xi_{-1})+\max\{0,\xi_{-1}-a'_i\}.
    $$
    
    Trong do, dau bang dau tien dung vi $f_{i-1}(x)$ khong co doan do doc duong. Do do, moi lan chi can lien tuc cong $\max\{0,\xi_{-1}-a'_i\}$ vao gia tri nho nhat.
    
    Bai nay con yeu cau in mot phuong an toi uu. Vi khi thao tac cuoi ket thuc, nghiem toi uu chinh la dinh heap, nen co the xac dinh truc tiep gia tri cua $b'_n$. Neu da biet nghiem toi uu thu $i$ la $b'_i$, de tim nghiem toi uu cua $f_{i-1}(x)$ thoa man $x\le b'$, chi can chu y rang do $f_{i-1}(x)$ la ham loi, diem cang gan diem cuc tieu toan cuc cua no thi nghiem cang tot. Vi vay, chi can ghi lai diem cuc tieu toan cuc cua $f_{i-1}(x)$, roi lay min voi $b'_i$, ta se thu duoc $b'_{i-1}$ toi uu.
    
    Do phuc tap thoi gian la $O(n\log n)$.
    
    ```cpp
    --8<-- "docs/dp/code/opt/slope-trick/sequence.cpp"
    ```

Bai mau:

-   [Codeforces 713 C. Sonya and Problem Without a Legend](https://codeforces.com/problemset/problem/713/C)
-   [Luogu P2893 \[USACO08FEB\] Making the Grade G](https://www.luogu.com.cn/problem/P2893)
-   [Luogu P4331 \[BalticOI 2004\] Sequence](https://www.luogu.com.cn/problem/P4331)
-   [Luogu P4597 Sequence](https://www.luogu.com.cn/problem/P4597)
-   [AtCoder dwango Challenge 2 Preliminary E - Fireworks](https://atcoder.jp/contests/dwango2016-prelims/tasks/dwango2016qual_e)

<span id="&#x4F8B;&#x9898;&#x8F6C;&#x79FB;&#x5E26;&#x9650;&#x5236;&#x7684;&#x60C5;&#x5F62;"></span>
### Vi du: truong hop chuyen trang thai co rang buoc

???+ example "[\[NOISG 2018 Finals\] Safety](https://www.luogu.com.cn/problem/P11598)"
    Cho day $\{a_i\}$ do dai $n$. Hay tim day $\{b_i\}$ sao cho $|b_i-b_{i-1}|\le h$ voi moi $1<i\le n$, va lam $\sum_i|a_i-b_i|$ nho nhat. In ra gia tri nho nhat.

??? note "Loi giai"
    Noi dung gan giong bai truoc, chi khac rang rang buoc tren day $\{b_i\}$ da thay doi. Tuong tu, dat $f_i(x)$ la gia tri nho nhat cua tong sai lech tren $i$ so dau khi so thu $i$ nhan gia tri $x$:
    
    $$
    f_i(x) = \min\sum_{j=1}^i|a_j-b_j|\text{ s.t. }|b_{j-1}-b_j|\le h,\forall 1<j\le i,~b_i=x.
    $$
    
    Suy ra phuong trinh chuyen trang thai
    
    $$
    f_i(x) = |a_i-x| + \min_{|y-x|\le h} f_{i-1}(y). 
    $$
    
    Dieu kien ban dau la $f_0(x)\equiv 0$. Cuoi cung van can tinh $\min_xf_n(x)$.
    
    Tach chuyen trang thai thanh cac thao tac tren ham loi, gom hai buoc:
    
    1.  Truoc het lay cuc tri cua $f_{i-1}(x)$, bien thanh $\min_{|y-x|\le h} f_{i-1}(y)$, tuong duong voi tich chap duoi dung cua $f_{i-1}(x)$ va $0_{[-h,h]}(x)$;
    2.  Cong ham thu duoc voi $|a_i-x|$.
    
    Cung vi do doc moi lan chi thay doi mot, co the xet duy tri diem gay. Khi do, hai thao tac nay co the mo ta nhu sau:
    
    1.  Dich tat ca doan do doc am sang trai $h$, va dich tat ca doan do doc duong sang phai $h$;
    2.  Chen $a_i$ hai lan.
    
    Hien nhien, voi bai nay, duy tri rieng cac doan do doc am va duong se tien loi hon. Vi thao tac chu yeu tap trung quanh doan do doc bang khong, ta dung [hai heap doi dinh](../../ds/binary-heap.md#%E5%AF%B9%E9%A1%B6%E5%A0%86), tuc dung rieng max-heap va min-heap de duy tri cac diem gay cua doan do doc am va duong. Cac phep tinh tien toan bo diem gay duoc thuc hien bang lazy tag. Vi buoc thu hai can chen mot $a_i$ vao moi heap, sau khi chen, dinh max-heap khong nhat thiet van nho hon hoac bang dinh min-heap. Khi do, hoan doi hai dinh heap cho den khi quan he thu tu cua hai dinh heap duoc thoa man.
    
    Cuoi cung, xet cach cap nhat gia tri nho nhat trong qua trinh thao tac. Vi buoc tinh tien dau tien khong lam thay doi gia tri nho nhat, chi can xet thao tac hoan doi dinh heap. Gia su $\xi_{-1}>\xi_1$. Khi hoan doi hai dinh heap $\xi_{-1}$ va $\xi_1$, ham tu
    
    $$
    \max\{0,x-\xi_{-1}\}+\max\{0,x-\xi_1\}
    $$
    
    bien thanh
    
    $$
    \max\{0,x-\xi_{1}\}+\max\{0,x-\xi_{-1}\}.
    $$
    
    Trong qua trinh nay, hinh dang cua ham khong doi, chi bi tinh tien xuong duoi $|\xi_{-1}-\xi_1|$. Vi vay, de ham truoc va sau khi hoan doi dinh heap giu nguyen, chi can cong $|\xi_{-1}-\xi_1|$ vao gia tri nho nhat.
    
    Do phuc tap thoi gian cua thuat toan van la $O(n\log n)$, vi sau moi lan them phan tu, thao tac hoan doi dinh heap thuc hien nhieu nhat mot lan.
    
    ```cpp
    --8<-- "docs/dp/code/opt/slope-trick/safety.cpp"
    ```

Bai mau:

-   [Luogu P4272 \[CTSC2009\] Sequence Transformation](https://www.luogu.com.cn/problem/P4272)
-   [Luogu P11598 \[NOISG 2018 Finals\] Safety](https://www.luogu.com.cn/problem/P11598)
-   [AtCoder Beginner Contest 217 H - Snuketoon](https://atcoder.jp/contests/abc217/tasks/abc217_h)
-   [AtCoder Regular Contest 070 E - NarrowRectangles](https://atcoder.jp/contests/arc070/tasks/arc070_c)
-   [AtCoder Regular Contest 123 D - Inc, Dec - Decomposition](https://atcoder.jp/contests/arc123/tasks/arc123_d)

<span id="&#x7EF4;&#x62A4;&#x659C;&#x7387;"></span>
## Duy tri do doc

Con co mot so bai toan ma viec duy tri do doc tien loi hon. Lop bai toan nay thuong cung co the giai bang tu tuong [tham lam hoi tiec](../../basic/greedy.md#%E5%90%8E%E6%82%94%E8%A7%A3%E6%B3%95) hoac mo phong luong chi phi. Trong mo hinh luong chi phi, chi phi nho nhat thuong la ham loi theo luong, va day la co so de dung Slope Trick.

<span id="&#x4F8B;&#x9898;&#x80A1;&#x7968;&#x4EA4;&#x6613;&#x95EE;&#x9898;"></span>
### Vi du: bai toan giao dich co phieu

???+ example "[Codeforces 865 D. Buy Low Sell High](https://codeforces.com/problemset/problem/865/D)"
    Cho day gia co phieu $\{p_i\}$ trong $n$ ngay (deu duong). Ban dau nam giu $0$ co phieu. Moi ngay co the mua mot co phieu, ban mot co phieu hoac khong giao dich. Hay tinh loi nhuan lon nhat sau $n$ ngay.

??? note "Loi giai"
    Truoc het xet loi giai DP truc tiep. Dat $f_i(x)$ la loi nhuan lon nhat khi ket thuc ngay thu $i$ va dang nam giu $x\ge 0$ co phieu. Khi do
    
    $$
    f_i(x) = \max\{f_{i-1}(x-1)-p_i,f_{i-1}(x),f_{i-1}(x+1)+p_i\}.
    $$
    
    Trang thai ban dau la $f_0(0)=0$, va voi moi $x\neq 0$, $f_0(x)=-\infty$. Dap an cua bai toan la $f_n(0)$.
    
    De chuyen tu $f_{i-1}(x)$ sang $f_i(x)$ can hai buoc:
    
    1.  Lay tich chap tren dung cua $f_{i-1}(x)$ voi ham tuyen tinh tung doan $\tilde h(x)$ ung voi ham
    
        $$
        h_i(x) = \begin{cases}p_i,&x=-1,\\0,&x=0,\\-p_i,&x=1\end{cases}
        $$
    
        (ro rang la ham lom);
    2.  Vi viec nay lam ham co gia tri huu han tren khoang $[-1,0)$, trai voi yeu cau $x\ge 0$, nen can cat lay phan cua ham tren $[0,+\infty)$.
    
    Chuyen chung thanh thay doi tren cac doan do doc, ta co hai buoc sau:
    
    1.  Chen mot doan do doc co do dai $2$ va do doc $-p_i$;
    2.  Trong cac doan do doc huu han, xoa mot doan co do dai $1$ va do doc lon nhat.
    
    Vi do dai cua cac doan do doc luon la so tu nhien, ta co the duy tri nhieu doan do dai mot, nhu vay chi can ghi lai do doc cua moi doan. Vi chi can chen va truy cap gia tri lon nhat, chi can dung mot max-heap. Thao tac gom hai buoc:
    
    1.  Chen $-p_i$ hai lan;
    2.  Pop dinh heap.
    
    Con can duy tri gia tri $f_i(0)$. Vi sau buoc dau tien, gia tri cua ham tai $x=-1$ la $f_{i-1}(0)+p_i$, nen gia tri tai $x=0$ la gia tri nay cong voi dinh heap sap bi pop, chinh la do doc cua ham tren khoang $[-1,0]$. Vi phep cat khong doi gia tri ham tai $x=0$, Day chinh la $f_i(0)$.
    
    So sanh cach cai dat thuat toan nay voi code cua phan [day tang voi chi phi nho nhat](#%E4%BE%8B%E9%A2%98%E6%9C%80%E5%B0%8F%E6%88%90%E6%9C%AC%E9%80%92%E5%A2%9E%E5%BA%8F%E5%88%97) o tren co the thay, thuat toan nay tuong duong voi bai toan bien day gia co phieu thanh day khong tang voi chi phi nho nhat.
    
    Do phuc tap thoi gian la $O(n\log n)$.
    
    ```cpp
    --8<-- "docs/dp/code/opt/slope-trick/stock.cpp"
    ```

Bai mau:

-   [Codeforces 865 D. Buy Low Sell High](https://codeforces.com/problemset/problem/865/D)

<span id="&#x4F8B;&#x9898;&#x642C;&#x8FD0;&#x571F;&#x77F3;&#x95EE;&#x9898;"></span>
### Vi du: bai toan van chuyen dat da

???+ example "[\[USACO16OPEN\] Landscaping P](https://www.luogu.com.cn/problem/P2748)"
    Cho hai day do dai $n$, $\{a_i\}$ va $\{b_i\}$, lan luot bieu thi luong dat hien co va luong dat can co trong vuon thu $i$ (khong duoc thua cung khong duoc thieu). Mua mot don vi dat va dat vao mot vuon bat ky ton $X$; chuyen mot don vi dat ra khoi mot vuon bat ky ton $Y$; van chuyen mot don vi dat tu vuon $i$ sang vuon $j$ ton $Z|i-j|$. Hay tinh chi phi nho nhat de thoa man nhu cau cua moi vuon. ($a_i,b_i\le 10$)

??? note "Loi giai"
    Xet loi giai DP truc tiep. Dat $f_i(x)$ la chi phi nho nhat de thoa man nhu cau cua $i$ vuon dau, va con du thuan $x$ don vi dat duoc chuyen den cac vuon phia sau. Neu $x<0$, dieu do tuong duong voi thieu rong $|x|$ don vi dat va can duoc chuyen tu cac vuon phia sau ve. Khi do co the viet phuong trinh chuyen trang thai:
    
    $$
    f_i(x) = \min_{y\in\mathbf R} f_{i-1}(y) + |y|Z + h((x-y)+(b_i-a_i)).
    $$
    
    Trong do, ham $h(\delta)$ bieu thi chi phi khi luong dat mua rong cua vuon hien tai la $\delta$, tuc
    
    $$
    h(\delta) = \max\{0,\delta\}X + \max\{0,-\delta\}Y = \max\{\delta X,-\delta Y\}.
    $$
    
    Ham nay ro rang la ham loi. Y nghia cua phuong trinh chuyen trang thai la:
    
    -   Khi $i-1$ vuon truoc con du rong $y$ don vi dat, chi phi nho nhat la $f_{i-1}(y)$;
    -   Chi phi van chuyen luong dat du (hoac thieu) giua vuon $i-1$ va $i$ la $|y|Z$;
    -   Bang mua ban, dieu chinh luong dat cua vuon thu $i$ tu $a_i$ thanh $b_i$, dong thoi dieu chinh luong dat du rong tu $y$ thanh $x$, voi chi phi nho nhat la $h((x-y)+(b_i-a_i))$.
    
    Trang thai ban dau la $f_0(0)=0$, va voi moi $x\neq 0$, $f_0(x)=+\infty$. Dap an cua bai toan la $f_n(0)$.
    
    Co the chia phep bien doi tu $f_{i-1}(x)$ sang $f_i(x)$ thanh ba buoc:
    
    1.  Truoc het cong $|x|Z$, thu duoc $f_{i-1}(x)+|x|Z$;
    2.  Sau do lay tich chap duoi dung voi $h(x)$, thu duoc $\min_{y\in\mathbf R}f_{i-1}(y)+|y|Z+h(x-y)$;
    3.  Cuoi cung, tinh tien ham sang trai $(b_i-a_i)$ don vi.
    
    Chuyen thanh thao tac tren cac doan do doc, cung gom ba buoc:
    
    1.  Cong $-Z$ vao tat ca doan do doc ben trai goc, va cong $Z$ vao tat ca doan do doc ben phai goc;
    2.  Thay the tat ca doan do doc nho hon $-Y$ bang $-Y$, va thay the tat ca doan do doc lon hon $X$ bang $X$;
    3.  Tinh tien tat ca doan do doc sang trai $(b_i-a_i)$ don vi.
    
    Trong de goc, $a_i$ va $b_i$ rat nho, nen chi can duy tri nhieu doan do doc do dai $1$. Mac du so doan do doc la vo han, chung co can tren $X$ va can duoi $-Y$, va so doan do doc nam nghiem ngat giua hai can nay khong nhieu. Vi khong co thao tac chen, co the dung hai stack de duy tri cac doan do doc hai phia goc. Phep cong tren khoang va phep lay cuc tri tren khoang deu duoc xu ly bang lazy tag. Ba buoc tren lan luot tuong ung voi:
    
    1.  Gan lazy tag cho hai stack trai va phai: ben trai cong $-Z$, ben phai cong $Z$;
    2.  Moi khi pop phan tu trong stack, lay max voi $-Y$ va min voi $X$. Neu stack trai rong thi pop $-Y$. Neu stack phai rong thi pop $X$;
    3.  Pop $(b_i-a_i)$ phan tu tren dinh stack trai va chen vao stack phai; tat nhien, khi $b_i-a_i<0$ thi lam nguoc lai.
    
    Khi trao doi dinh stack, cap nhat dap an: di sang trai thi tru di do doc hien tai, di sang phai thi cong do doc hien tai.
    
    Do phuc tap cua thuat toan la $O(n\max\{a_i,b_i\})$.
    
    ```cpp
    --8<-- "docs/dp/code/opt/slope-trick/landscaping.cpp"
    ```

Bai mau:

-   [Luogu P2748 \[USACO16OPEN\] Landscaping P](https://www.luogu.com.cn/problem/P2748)
-   [Kyoto University PC 2016 H - WAAAAAAAAAAAAALL](https://atcoder.jp/contests/kupc2016/tasks/kupc2016_h)
-   [JAG Practice Contest 2017 J - Farm Village](https://atcoder.jp/contests/jag2017autumn/tasks/jag2017autumn_j)

<span id="&#x4E60;&#x9898;"></span>
## Bai tap

Cuoi bai viet, duoi day la mot so bai toan tung xuat hien trong cac ky thi lap trinh, co the giai bang Slope Trick, de ban luyen tap.

-   [Luogu P3642 \[APIO2016\] Fireworks](https://www.luogu.com.cn/problem/P3642)
-   [Luogu P9962 \[THUPC 2024 Preliminary\] A Tree](https://www.luogu.com.cn/problem/P9962)
-   [Luogu P11317 \[RMI 2021\] Paths](https://www.luogu.com.cn/problem/P11317)
-   [AtCoder Beginner Contest 383 G - Bar Cover](https://atcoder.jp/contests/abc383/tasks/abc383_g)
-   [Codeforces 280 D. k-Maximum Subsequence Sum](https://codeforces.com/problemset/problem/280/D)
-   [Codeforces 280 E. Sequence Transformation](https://codeforces.com/problemset/problem/280/E)
-   [Codeforces 802 O. April Fools' Problem (hard)](https://codeforces.com/contest/802/problem/O)
-   [Codeforces 1209 H. Moving Walkways](https://codeforces.com/contest/1209/problem/H)
-   [Codeforces 1229 F. Mateusz and Escape Room](https://codeforces.com/contest/1229/problem/F)
-   [Codeforces 1534 G. A New Beginning](https://codeforces.com/problemset/problem/1534/G)
-   [Codeforces 1787 H. Codeforces Scoreboard](https://codeforces.com/problemset/problem/1787/H)
-   [2019 Summer Petrozavodsk Camp H. Honorable Mention](https://codeforces.com/gym/102331/problem/H)
-   [2018 ACM-ICPC World Finals C. Conquer The World](https://codeforces.com/gym/102482/problem/C)
-   [300iq Contest 3 F. Farm of Monsters](https://codeforces.com/gym/102538/problem/F)

<span id="&#x53C2;&#x8003;&#x6587;&#x732E;&#x4E0E;&#x6CE8;&#x91CA;"></span>
## Tai lieu tham khao va ghi chu

-   [\[Tutorial\] Slope Trick - zscoder](https://codeforces.com/blog/entry/47821)
-   [Slope trick explained - Kuroni](https://codeforces.com/blog/entry/77298)
-   [Slope Trick - USACO Guide](https://usaco.guide/adv/slope-trick?lang=cpp)
-   [\[Tutorial\] Intuition on Slope Trick - maomao90](https://codeforces.com/blog/entry/103222)

[^convex-def]: Cac giao trinh khac nhau co the dung ten goi khac nhau cho ham loi.

[^inf-conv]: Cung thuong duoc goi la tich chap $\min$, tich chap $\inf$, hoac tich chap $(\min,+)$.
