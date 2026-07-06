<span id="dẫn-nhập"></span>
## Dẫn nhập

Với một lớp bài toán DP hai chiều, nếu hàm giá trị $f(i,x)$ là hàm lồi theo
$x$ với mọi $i$ cố định, có thể xem toàn bộ hàm $f(i,\cdot)$ là trạng thái
tại $i$, và duy trì sai phân (hay độ dốc) của nó

$$
\Delta f(i,x) = f(i,x+1)-f(i,x)
$$

thay vì duy trì trực tiếp hàm. Cách nghĩ tối ưu hóa DP này thường giúp đơn giản
hóa phép chuyển trạng thái, và được gọi là Slope Trick.

???+ info "\"Độ dốc\""
    Trong phần lớn bài toán, các hàm chỉ được lấy giá trị tại các điểm nguyên,
    nên việc gọi nó là sai phân hay độ dốc về bản chất không khác nhau. Trong
    bài viết này, theo thuật ngữ Slope Trick, thống nhất gọi là độ dốc.

Trong từng bài cụ thể, cách duy trì độ dốc có thể khác nhau. Nếu miền giá trị
của độ dốc hẹp, việc duy trì các điểm mà độ dốc thay đổi (tức điểm gãy) sẽ tiện
lợi hơn; nếu miền xác định của hàm hẹp, việc duy trì trực tiếp dãy độ dốc có thể
tiện lợi hơn. Trong các tình huống phức tạp hơn, có thể cần duy trì đồng thời
giá trị độ dốc của mỗi đoạn và độ dài của đoạn đó. Bất kể cách duy trì cụ thể là
gì, bản chất của lớp bài toán này là lợi dụng việc dãy độ dốc chỉ thay đổi ít
trong chuyển trạng thái để đơn giản hóa phép chuyển. Vì vậy, tất cả chúng đều có
thể được gọi là Slope Trick.

<span id="hàm-lồi"></span>
## Hàm lồi

Trước khi thảo luận các bài toán cụ thể, cần nắm một số tính chất cơ bản của
hàm lồi, cũng như cách độ dốc của nó thay đổi khi thực hiện các phép biến đổi
khác nhau trên hàm lồi.

<span id="hàm-lồi-trên-trục-thực"></span>
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

Nếu đổi dấu bất đẳng thức thành $\ge$, tương ứng thu được hàm lõm[^convex-def].
Vì với mọi hàm lõm $f$, hàm $-f$ luôn là hàm lồi, nên mục này chỉ xét hàm lồi.

???+ info "Bài viết chỉ xét hàm lồi đúng"
    Để tránh phải thảo luận giá trị của $\infty-\infty$ và các phân tích phức
    tạp bổ sung, khi nói về các khái niệm liên quan đến hàm lồi, bài viết này
    luôn mặc định hàm không nhận giá trị $-\infty$ và không phải lúc nào cũng
    bằng $+\infty$. Những hàm lồi như vậy được gọi là **hàm lồi đúng** (proper
    convex function). Điều này đã đủ để hiểu các nội dung cần dùng trong lập
    trình thi đấu.

Tất nhiên, hàm $f$ thường không được định nghĩa trên mọi số thực. Nếu miền xác
định của $f$ chỉ là một tập con của $\mathbf R$, có thể mở rộng nó thành hàm
trên $\mathbf R$:

$$
\tilde f(x) = \begin{cases} f(x), & x\in\operatorname{dom}f,\\ +\infty,& x\notin\operatorname{dom}f.\end{cases}
$$

Khi đó, nói $f$ là hàm lồi khi và chỉ khi hàm mở rộng tương ứng $\tilde f$
thỏa mãn định nghĩa hàm lồi ở trên. Vì vậy, nếu không nói rõ thêm, miền xác định
của các hàm lồi được nhắc đến trong bài viết này đều là tập số thực $\mathbf R$.
Hàm lồi $f$ chỉ có thể nhận giá trị hữu hạn trên một khoảng (tức một
tập con lồi của $\mathbf R$).

???+ example "Ví dụ đơn giản"
    Các ví dụ thường gặp về hàm lồi gồm:

    1.  Hàm hằng: $f(x)=c$, với $c\in\mathbf R$;
    2.  Hàm bậc nhất: $f(x)=kx+b$, với $k,b\in\mathbf R$ và $k\neq 0$;
    3.  Hàm giá trị tuyệt đối: $f(x)=|x-a|$, với $a\in\mathbf R$;
    4.  Kết quả khi hạn chế bất kỳ hàm lồi nào trên một khoảng, chẳng hạn
        $0_{[a,b]}(x)$ (trong ngữ cảnh giải tích lồi, hàm này cũng được gọi là
        hàm chỉ thị của $[a,b]$).

Có thể kết hợp các phép biến đổi bảo toàn tính lồi được nêu bên dưới
để tạo ra những hàm lồi phức tạp hơn.

<span id="hàm-lồi-trên-tập-điểm-rời-rạc"></span>
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
    $f:S\rightarrow\mathbf R\cup\{\pm\infty\}$, có thể định nghĩa hàm
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

    Nếu $f$ là hàm lồi trên $\mathbf Z$, theo tính chất độ dốc không giảm, có

    $$
    \Delta f(x-1,x)\le \Delta f(x-1,x+1) \le\Delta f(x,x+1).
    $$

    Đây chính là điều kiện ở trên.

    Ngược lại, nếu điều kiện ở trên đúng, thì với mọi $x_1<x_2$, có

    $$
    \Delta f(x_1,x_2) = \dfrac{1}{x_2-x_1}\sum_{i=x_1}^{x_2-1}\left(f(i+1)-f(i)\right).
    $$

    Giá trị này là trung bình cộng của các sai phân với $x_1\le i<x_2$. Nếu
    tăng $x_2$ thêm một, tương đương chèn thêm một sai phân lớn hơn; nếu tăng
    $x_1$ thêm một, tương đương bỏ đi sai phân nhỏ nhất. Cả hai thao tác đều
    làm trung bình tăng lên. Điều đó cho thấy độ dốc $\Delta f(x_1,x_2)$ không
    giảm, tức $f$ là hàm lồi trên $\mathbf Z$.

Nói cách khác, chỉ cần độ dốc (sai phân) đơn điệu không giảm, dãy đó có thể
được xem là một hàm lồi trên $\mathbf Z$.

<span id="hai-cách-đặc-trưng-hàm-lồi"></span>
### Hai cách đặc trưng hàm lồi

Thực ra, cách đặc trưng hàm lồi bằng độ dốc cũng có thể mở rộng cho trường hợp
tổng quát.

???+ note "Đặc trưng hàm lồi bằng độ dốc"
    Cho $S$ là $\mathbf R$ hoặc tập con rời rạc của nó. Hàm
    $f:S\rightarrow\mathbf R\cup\{\pm\infty\}$ là hàm lồi khi và chỉ khi độ dốc

    $$
    \Delta f(x_1,x_2) = \dfrac{f(x_2)-f(x_1)}{x_2-x_1}
    $$

    là hàm không giảm theo cả $x_1$ và $x_2$, với mọi $x_1,x_2\in S$ và
    $x_1<x_2$.

??? note "Chứng minh"
    Với hàm $f(x)$ trên $\mathbf R$ và $x_1<x_2$, với $\alpha\in(0,1)$, đặt
    $x_3=\alpha x_1+(1-\alpha)x_2$. Khi đó

    $$
    \Delta f(x_1,x_3) \le \Delta f(x_1,x_2) \le \Delta f(x_3,x_2)
    $$

    tương đương với

    $$
    \dfrac{f(x_3)-f(x_1)}{1-\alpha} \le f(x_2)-f(x_1) \le \dfrac{f(x_2)-f(x_3)}{\alpha}.
    $$

    Hai bất đẳng thức hai phía đều tương đương với
    $f(x_3)\le\alpha f(x_1)+(1-\alpha)f(x_2)$, tức tính lồi của hàm $f(x)$.

    Với hàm $f(x)$ trên tập con rời rạc $S$ của $\mathbf R$, tính cần thiết của
    điều kiện độ dốc không giảm có thể suy ra từ tính lồi của $\tilde f(x)$. Bây
    giờ cần chứng minh tính đủ. Để làm việc này, chỉ cần chứng minh
    $\Delta\tilde f(x_1,x_2)$ cũng không giảm. Đặt $S=\{s_i\}$ với $s_i$ tăng
    nghiêm ngặt theo $i$, và giả sử $s_{i_1}\le x_1\le s_{i_1+1}$,
    $s_{i_2}\le x_2\le s_{i_2+1}$; khi đó $i_1\le i_2$. Đặt
    $\Delta_i=\Delta f(s_i,s_{i+1})$. Khi đó, có thể chứng minh
    $\Delta_{i_1}\le\Delta\tilde f(x_1,x_2)\le\Delta_{i_2}$.

    Xét hai trường hợp. Nếu $i_1=i_2$, thì
    $\Delta_{i_1}=\Delta\tilde f(x_1,x_2)=\Delta_{i_2}$, bất đẳng thức hiển
    đúng trực tiếp. Ngược lại, có

    $$
    \Delta\tilde f(x_1,x_2) = \dfrac{1}{x_2-x_1}\left((s_{i_1+1}-x_1)\Delta_{i_1}+(x_2-s_{i_2})\Delta_{i_2}+\sum_{j=i_1+1}^{i_2-1}(s_{j+1}-s_j)\Delta_j\right).
    $$

    Theo tính chất độ dốc tăng trên $S$, $\Delta_i$ tăng theo $i$, nên
    $\Delta_{i_1}\le\Delta\tilde f(x_1,x_2)\le\Delta_{i_2}$.

    Dùng kết luận này, với $x_1<x_2$ và $\alpha\in(0,1)$, đặt
    $x_3=\alpha x_1+(1-\alpha)x_2$, và chọn $i_3$ sao cho
    $s_{i_3}\le x_3\le s_{i_3+1}$. Khi đó

    $$
    \Delta\tilde f(x_1,x_3) \le \Delta_{i_3} \le \Delta\tilde f(x_3,x_2).
    $$

    Thay biểu thức của $x_3$ vào sẽ thu được tính lồi của $\tilde f(x)$.

Độ dốc đơn điệu không giảm có thể xem là một định nghĩa tương đương của hàm lồi.
Chính vì độ dốc của hàm lồi có tính đơn điệu, khi duy trì độ dốc, thường cần
chọn các cấu trúc dữ liệu như [heap (hàng đợi ưu tiên)](../../ds/heap.md) hoặc
[cây cân bằng](../../ds/bst.md).

Bài viết này còn dùng một đặc trưng tương đương khác của hàm lồi. Với hàm
$f:\mathbf R\rightarrow\mathbf R\cup\{\pm\infty\}$, có thể xét vùng nằm phía
trên đồ thị của hàm trong mặt phẳng, tức

$$
\operatorname{epi} f = \{(x,y)\in\mathbf R^2 : y\ge f(x)\}.
$$

Vùng này còn được gọi là **thượng đồ thị** của hàm $f$ (epigraph). Tính lồi của
hàm tương đương với tính lồi của thượng đồ thị:

???+ note "Đặc trưng hàm lồi bằng thượng đồ thị"
    Hàm $f:\mathbf R\rightarrow\mathbf R\cup\{\pm\infty\}$ là hàm lồi khi và
    chỉ khi $\operatorname{epi}f$ là tập lồi trong $\mathbf R^2$.

??? note "Chứng minh"
    Nếu $f$ là hàm lồi, thì với
    $(x_1,y_1),(x_2,y_2)\in\operatorname{epi}f$ và bất kỳ $\alpha\in(0,1)$, có

    $$
    \alpha y_1+(1-\alpha)y_2 \ge \alpha f(x_1)+(1-\alpha)f(x_2) \ge f(\alpha x_1+(1-\alpha) x_2).
    $$

    Do đó, $\alpha(x_1,y_1)+(1-\alpha)(x_2,y_2)\in\operatorname{epi}f$.

    Ngược lại, nếu $\operatorname{epi}f$ là tập lồi, thì với mọi $x_1<x_2$ và
    $\alpha\in(0,1)$, có

    $$
    \alpha(x_1,f(x_1))+(1-\alpha)(x_2,f(x_2)) \in \operatorname{epi}f.
    $$

    Điều này tương đương với
    $\alpha f(x_1)+(1-\alpha)f(x_2)\ge f\left(\alpha x_1+(1-\alpha)x_2\right)$,
    tức tính lồi của $f$.

Phần sau sẽ cho thấy, bằng thượng đồ thị, có thể liên hệ tích chập dưới đúng của
hàm lồi với tổng Minkowski của tập lồi.

<span id="các-phép-biến-đổi-hàm-lồi"></span>
## Các phép biến đổi hàm lồi

Tiếp theo, bài viết giới thiệu một số phép biến đổi bảo toàn tính lồi thường gặp
trong Slope Trick.

<span id="tổ-hợp-tuyến-tính-không-âm"></span>
### Tổ hợp tuyến tính không âm

Với hai hàm lồi $f$ và $g$, cùng các số thực không âm $\alpha,\beta\ge0$, hàm
$\alpha f+\beta g$ cũng là hàm lồi. Hơn nữa,

$$
\Delta(\alpha f+\beta g) = \alpha\Delta f + \beta\Delta g.
$$

Vì vậy, nếu đã duy trì độ dốc của các hàm lồi $f$ và $g$, để thu được độ dốc
của tổ hợp tuyến tính không âm $\alpha f+\beta g$, chỉ cần tính theo từng đoạn.

Trong các bài toán duy trì độ dốc, thường có một hàm có dạng khá đơn giản; khi
đó có thể giảm độ phức tạp sửa đổi bằng đánh dấu lười. Trong các bài toán duy trì
điểm gãy, để tính các điểm gãy của độ dốc của $f+g$, chỉ cần trộn các điểm gãy
độ dốc của $f$ và $g$.

<span id="tích-chập-dưới-đúng-tổng-minkowski"></span>
### Tích chập dưới đúng (tổng Minkowski)

Một phép toán thường gặp khác trên hàm lồi là tích chập dưới đúng. Với hai hàm
$f$ và $g$, hàm

$$
h(x) = \inf_{y\in\mathbf R}f(y)+g(x-y)
$$

được gọi là **tích chập dưới đúng**[^inf-conv] (infimal convolution) của $f$ và
$g$. Nếu $f$ và $g$ đều là hàm lồi, tích chập dưới đúng của chúng cũng là hàm
lồi.

![](../images/slope-trick/epigraph-convex-minkowski.svg)

??? example "Giải thích hình vẽ"
    Như trong hình, để tìm tích chập dưới đúng $h$ của $f$ và $g$, có thể xem
    mỗi điểm thượng đồ thị của $f$ (đường đứt nét màu đỏ trong hình thứ ba) là
    gốc tọa độ, rồi vẽ đồ thị của $g$ (đường đứt nét màu xanh trong hình thứ ba)
    trong hệ tọa độ tương ứng. Khi gốc tọa độ di chuyển dọc theo đồ thị của
    $f$, biến dạng quỹ đạo mà đồ thị (thượng đồ thị) của $g$ quét ra, cụ thể là
    bao lồi dưới, chính là đồ thị của $h$. Có thể thấy mỗi đoạn độ dốc của $h$
    hoặc là đoạn độ dốc của $f$, hoặc là đoạn độ dốc của $g$: chúng chỉ được sắp
    xếp lại theo độ lớn độ dốc. Trong quá trình này, vai trò của $f$ và $g$ có
    thể hoán đổi; nếu cho đồ thị của $f$ di chuyển dọc theo đồ thị của $g$, kết
    quả vẫn như nhau.

Về trực giác hình học, $\operatorname{epi}h$ chính là
[tổng Minkowski](../../geometry/convex-hull.md#tổng-minkowski) của
$\operatorname{epi}f$ và $\operatorname{epi}g$. Nếu $f$ và $g$ đều là hàm tuyến
tính từng đoạn, thì $h$ cũng là hàm tuyến tính từng đoạn, và các đoạn độ dốc của
nó có thể xem là kết quả trộn (rồi sắp xếp lại) các đoạn độ dốc của $f$ và $g$.

??? note "Chứng minh"
    Giả sử $f,g$ đều là hàm lồi, và $h$ là tích chập dưới đúng của chúng. Lấy
    $x_1<x_2$ và $\alpha\in(0,1)$. Theo định nghĩa tích chập dưới đúng, với mọi
    $\varepsilon>0$, tồn tại $y_i,z_i\in\mathbf R$ sao cho $y_i+z_i=x_i$ và

    $$
    h(x_i) + \varepsilon > f(y_i) + g(z_i).
    $$

    Do đó, kết hợp tính lồi của $f,g$ và định nghĩa của $h$, có

    $$
    \begin{aligned}
    \alpha h(x_1)+(1-\alpha)h(x_2) + \varepsilon
    &> \alpha f(y_1) + (1-\alpha) f(y_2) + \alpha g(z_1) + (1-\alpha) g(z_2)\\
    &\ge f\left(\alpha y_1+(1-\alpha)y_2\right) + g\left(\alpha z_1+(1-\alpha)z_2\right)\\
    &\ge h(\alpha x_1+(1-\alpha)x_2).
    \end{aligned}
    $$

    Vì $\varepsilon>0$ được chọn tùy ý, suy ra

    $$
    \alpha h(x_1)+(1-\alpha)h(x_2) \ge h(\alpha x_1+(1-\alpha)x_2).
    $$

    Từ đó thu được tính lồi của $h$.

    Tiếp theo, đối với trực giác hình học, nói một cách chặt chẽ thì chỉ có thể
    chứng minh kết luận sau:

    $$
    \operatorname{epi} f + \operatorname{epi} g\subseteq \operatorname{epi}h \subseteq \operatorname{cl}(\operatorname{epi} f + \operatorname{epi} g).
    $$

    Trong đó, $\operatorname{cl}$ biểu thị bao đóng.

    Với mọi $(x,y)\in\operatorname{epi} f + \operatorname{epi} g$, tồn tại
    $(x_1,y_1)\in\operatorname{epi} f$ và $(x_2,y_2)\in\operatorname{epi} g$ sao
    cho $x=x_1+x_2$ và

    $$
    y = y_1+y_2 \ge f(x_1)+g(x_2) \ge h(x_1+x_2)=h(x).
    $$

    Do đó, $(x,y)\in\operatorname{epi}h$. Điều này cho thấy
    $\operatorname{epi} f + \operatorname{epi} g\subseteq \operatorname{epi}h$.

    Ngược lại, với mọi $(x,y)\in\operatorname{epi}h$, có $y\ge h(x)$. Theo
    định nghĩa của $h$, với mọi $\varepsilon>0$, tồn tại $x_1+x_2=x$ sao cho

    $$
    y + \varepsilon > f(x_1) + g(x_2).
    $$

    Đặt $y_1=f(x_1)$ và $y_2=g(x_2)$, có $y+\varepsilon>y_1+y_2$. Điều này
    nói rằng với mọi $\varepsilon>0$, điểm
    $(x_1,y_1)+(x_2,y_2)\in\operatorname{epi} f + \operatorname{epi} g$ nằm trên
    đoạn thẳng nối $(x,y)$ và $(x,y+\varepsilon)$. Cho
    $\varepsilon\rightarrow 0$, thu được
    $\operatorname{epi}h \subseteq \operatorname{cl}(\operatorname{epi} f + \operatorname{epi} g)$.

    Vì vậy, $\operatorname{epi} f + \operatorname{epi} g = \operatorname{epi}h$
    khi và chỉ khi nó là tập lồi đóng. Một điều kiện để điều này đúng là $f$ và
    $g$ đều là hàm lồi đúng và
    [nửa liên tục dưới](https://en.wikipedia.org/wiki/Semi-continuity). Với các
    ứng dụng trong lập trình thi đấu, điều này đã đủ, chẳng hạn hàm tuyến tính
    từng đoạn luôn thỏa mãn các điều kiện này.

Trong bài toán thực tế, nếu một trong hai hàm $f$ và $g$ có ít đoạn độ dốc, có
thể chèn trực tiếp các đoạn độ dốc ít hơn vào tập đoạn độ dốc nhiều hơn; nếu
không, có thể cần dùng các kỹ thuật như
[gộp theo heuristic](../../graph/dsu-on-tree.md) hoặc
[heap có thể gộp](../../ds/heap.md) để giảm độ phức tạp tổng thể của phép gộp,
hoặc tìm cách xử lý riêng theo bài toán cụ thể.

<span id="phép-toán-cực-trị"></span>
### Phép toán cực trị

Giá trị lớn nhất của hai hàm lồi vẫn là hàm lồi, nhưng giá trị nhỏ nhất của hai
hàm lồi chưa chắc còn là hàm lồi.

Nhiều phép lấy nhỏ nhất thường gặp có thể chuyển thành tích chập dưới đúng:

???+ example "Ví dụ"
    -   $f(x)=\min_{y\in [x+a,x+b]}g(y)$ vẫn là hàm lồi, vì nó có thể xem là
        tích chập dưới đúng:

        $$
        f(x) = \min_{y\in\mathbf R}g(y) + 0_{[-b,-a]}(x-y).
        $$
    -   $f(x)=\min\{g(x-a_i)+b_i\}$ là hàm lồi trên $\mathbf Z$, miễn là
        $g(x)$ là hàm lồi trên $\mathbf Z$, và hàm $h:a_i\mapsto b_i$ được định
        nghĩa trên tập hữu hạn $\{a_i\}\subset\mathbf Z$ cũng là hàm lồi trên
        tập rời rạc đó. Lý do là sau khi mở rộng, hàm $\tilde f(x)$ có thể xem
        là tích chập dưới đúng:

        $$
        \tilde f(x) = \min_{y\in\mathbf R}\tilde h(y)+\tilde g(x-y).
        $$

        Do đó, hàm $f(x)$ trước khi mở rộng cũng là hàm lồi.

Nhưng không phải mọi phép lấy nhỏ nhất đều bảo toàn tính lồi.

???+ example "Phản ví dụ"
    Cho $g(x)$ là hàm lồi. Hàm $f(x)=\min\{g(x-1)+kx,g(x)\}$ không nhất thiết là
    hàm lồi.

Trong một số bài toán đặc biệt, mặc dù phương trình chuyển trạng thái của quy
hoạch động có thể viết dưới dạng giá trị nhỏ nhất của hai hàm lồi, và khó chuyển
thành dạng tích chập dưới đúng, hàm giá trị vẫn có thể giữ tính lồi. Khi xử lý
thực tế, thường cần kết hợp lập bảng và dự đoán để tìm cách chuyển độ dốc hợp
lý cho loại bài này.

Sau khi hiểu hàm lồi và các phép biến đổi thường gặp của nó, có thể thông qua
các bài toán cụ thể để nắm cách tối ưu hóa DP bằng Slope Trick. Các ví dụ trong
bài viết được chia đại khái thành hai nhóm: duy trì điểm gãy và duy trì độ dốc,
nhằm giúp hiểu các thao tác thường gặp và chi tiết cài đặt của hai cách duy trì
này. Tuy nhiên, như đã nhấn mạnh ở trên, cách duy trì không phải là bản chất của
Slope Trick; cần chọn cách duy trì đoạn độ dốc phù hợp theo yêu cầu của từng bài
toán.

<span id="duy-trì-điểm-gãy"></span>
## Duy trì điểm gãy

Lớp bài toán này thường xuất hiện khi cần tối thiểu hóa tổng của nhiều giá trị
tuyệt đối. Vì trong các bài toán đó, giá trị tuyệt đối của độ dốc của hàm giá
trị không lớn, nên duy trì các điểm gãy nơi độ dốc thay đổi sẽ tiện lợi hơn.

Duy trì điểm gãy nghĩa là duy trì các điểm trong hàm tuyến tính từng đoạn tại đó
độ dốc thay đổi. Tương đương, với mỗi đoạn độ dốc $[l_i,r_i]$ có độ dốc $k_i$,
chỉ duy trì thông tin hai đầu mút của nó, còn bản thân độ dốc không cần duy trì
riêng; do đó, trong lớp bài toán này, mỗi khi độ dốc thay đổi, nó phải chỉ thay
đổi một lượng cố định. Chẳng hạn, nếu duy trì tập điểm gãy
$\xi_{-s}\le\cdots\le\xi_{-1}\le\xi_{1}\le\cdots\le\xi_{t}$, điều đó tương
đương với: độ dốc bằng $0$ trên khoảng $[\xi_{-1},\xi_1]$; mỗi khi đi sang trái
qua một điểm gãy, độ dốc giảm một; mỗi khi đi sang phải qua một điểm gãy, độ dốc
tăng một. Vì vậy, trên khoảng $[\xi_2,\xi_3]$, độ dốc là $2$; trên khoảng
$[\xi_{-3},\xi_{-2}]$, độ dốc là $-2$; và tương tự. Viết bằng ngôn ngữ hình
thức, hàm có thể được biểu diễn bằng các điểm gãy của độ dốc như sau:

$$
f(x) = f(\xi_1) + \sum_{i=-s}^{-1}\max\{\xi_i-x,0\} + \sum_{i=1}^{\ell}\max\{x-\xi_i,0\}.
$$

Giá trị nhỏ nhất của nó là $f(\xi_{-1})=f(\xi_1)$, và có thể đạt được tại bất kỳ
vị trí nào trong khoảng $[\xi_{-1},\xi_1]$.

![](../images/slope-trick/epigraph-convex-kinks.svg)

<span id="ví-dụ-dãy-tăng-với-chi-phí-nhỏ-nhất"></span>
### Ví dụ: dãy tăng với chi phí nhỏ nhất

???+ example "[\[BalticOI 2004\] Sequence](https://www.luogu.com.cn/problem/P4331)"
    Cho dãy $\{a_i\}$ độ dài $n$. Tìm một dãy tăng nghiêm ngặt $\{b_i\}$ sao
    cho $\sum_i|a_i-b_i|$ nhỏ nhất, và in ra giá trị nhỏ nhất cùng một phương án
    tối ưu bất kỳ $\{b_i\}$.

??? note "Lời giải"
    Trước hết, $\{b_i\}$ tăng nghiêm ngặt tương đương với
    $\{b'_i\}=\{b_i-i\}$ không giảm. Vì vậy, chỉ cần tìm dãy không giảm
    $\{b'_i\}=\{b_i-i\}$ có tổng sai lệch nhỏ nhất so với
    $\{a'_i\}=\{a_i-i\}$, rồi khôi phục lại $\{b_i\}$.

    Xét lời giải DP trực tiếp. Đặt $f_i(x)$ là sai lệch nhỏ nhất giữa các số đã
    chọn và $i$ số đầu của $\{a'_i\}$, khi đã chọn $i$ số đầu của dãy
    $\{b'_i\}$ và số thứ $i$ không vượt quá $x$:

    $$
    f_i(x) = \min\sum_{j=1}^i|a'_j-b'_j|\text{ với điều kiện }b'_1\le b'_2\le\cdots\le b'_i\le x.
    $$

    Phương trình chuyển trạng thái là

    $$
    f_i(x) = \min_{y\le x}f_{i-1}(y)+|a'_i-y|.
    $$

    Trạng thái ban đầu là $f_0(x)\equiv 0$, và cuối cùng cần tìm
    $\min_xf_n(x)$. Dùng các phép biến đổi hàm lồi đã nêu ở trên, để chuyển từ
    $f_{i-1}(x)$ sang $f_i(x)$ cần hai bước:

    1.  Trước hết, cộng thêm $|a'_i-x|$, tương đương với tăng tất cả đoạn độ dốc
        trong khoảng $(-\infty,a'_i]$ thêm $-1$, và tăng tất cả đoạn độ dốc trong
        khoảng $[a'_i,+\infty)$ thêm $1$;
    2.  Lấy giá trị nhỏ nhất của hàm thu được, biến
        $g(x)=f_{i-1}(x)+|a'_i-x|$ thành $f_i(x)=\min_{y\le x}g(y)$. Theo phân
        tích ở trên, việc này tương đương với lấy tích chập dưới đúng của
        $g(x)$ và $0_{[0,+\infty)}$. Vì hàm sau chỉ có một đoạn độ dốc duy nhất,
        độ dốc bằng $0$ và kéo dài vô hạn sang phải, chèn nó vào các đoạn độ dốc
        của $g(x)$ tương đương với xóa tất cả đoạn độ dốc dương.

    Sau khi làm rõ các thao tác này, đã có thể trực tiếp dùng cây cân bằng để
    duy trì tất cả đoạn độ dốc, nhưng code sẽ phức tạp. Chú ý rằng trong bài này
    độ dốc mỗi lần thay đổi nhiều nhất $1$, nên giá trị tuyệt đối của mỗi đoạn
    độ dốc không vượt quá $n$. Thay vì trực tiếp duy trì các đoạn độ dốc, duy
    trì trực tiếp các điểm gãy của độ dốc sẽ tiện hơn.

    Giả sử tập điểm gãy của $f_{i-1}(x)$ là
    $\xi_{-k}\le\cdots\le\xi_{-1}\le\xi_{1}\le\cdots\le\xi_{\ell}$. Khi đó hai
    bước ở trên lần lượt tương ứng với:

    1.  Thêm một điểm gãy $a'_i$ của đoạn độ dốc âm và một điểm gãy $a'_i$ của
        đoạn độ dốc dương;
    2.  Pop tất cả điểm gãy $\xi_1,\cdots,\xi_{\ell}$ của các đoạn độ dốc dương.

    Khi duy trì thực tế, vì sau mỗi thao tác không còn điểm gãy của đoạn độ dốc
    dương, tức các điểm gãy của độ dốc có dạng
    $\xi_{-k}\le\cdots\le\xi_{-1}$, và thao tác luôn xảy ra tại biên giữa đoạn
    độ dốc âm và dương, nên chỉ cần dùng một max-heap để lưu tất cả điểm gãy.
    Hai bước lần lượt tương ứng với:

    1.  Chèn $a'_i$ hai lần;
    2.  Pop đỉnh heap.

    Tất nhiên, sau mỗi lần cần duy trì giá trị nhỏ nhất hiện tại của hàm. Vì sau
    khi thao tác kết thúc không còn đoạn độ dốc dương, giá trị nhỏ nhất của hàm
    là giá trị tại đỉnh max-heap. Giả sử trước mỗi thao tác, đỉnh heap là
    $\xi_{-1}$ và giá trị nhỏ nhất là $f_{i-1}(\xi_{-1})$. Vì đỉnh heap bị pop
    là điểm gãy nhỏ nhất của đoạn độ dốc dương, giá trị nhỏ nhất của hàm bằng
    giá trị hàm tại đó, nên chỉ cần tính giá trị hàm tại đỉnh heap trước khi
    pop, tức

    $$
    f_{i-1}(\max\{a'_i,\xi_{-1}\})+|\max\{a'_i,\xi_{-1}\}-a'_i|=f_{i-1}(\xi_{-1})+\max\{0,\xi_{-1}-a'_i\}.
    $$

    Trong đó, dấu bằng đầu tiên đúng vì $f_{i-1}(x)$ không có đoạn độ dốc dương.
    Do đó, mỗi lần chỉ cần liên tục cộng $\max\{0,\xi_{-1}-a'_i\}$ vào giá trị
    nhỏ nhất.

    Bài này còn yêu cầu in một phương án tối ưu. Vì khi thao tác cuối kết thúc,
    nghiệm tối ưu chính là đỉnh heap, nên có thể xác định trực tiếp giá trị của
    $b'_n$. Nếu đã biết nghiệm tối ưu thứ $i$ là $b'_i$, để tìm nghiệm tối ưu
    của $f_{i-1}(x)$ thỏa mãn $x\le b'_i$, chỉ cần chú ý rằng do
    $f_{i-1}(x)$ là hàm lồi, điểm càng gần điểm cực tiểu toàn cục của nó thì
    nghiệm càng tốt. Vì vậy, chỉ cần ghi lại điểm cực tiểu toàn cục của
    $f_{i-1}(x)$, rồi lấy min với $b'_i$, sẽ thu được $b'_{i-1}$ tối ưu.

    Độ phức tạp thời gian là $O(n\log n)$.

    ```cpp
    --8<-- "docs/dp/code/opt/slope-trick/sequence.cpp"
    ```

Bài mẫu:

-   [Codeforces 713 C. Sonya and Problem Without a Legend](https://codeforces.com/problemset/problem/713/C)
-   [Luogu P2893 \[USACO08FEB\] Making the Grade G](https://www.luogu.com.cn/problem/P2893)
-   [Luogu P4331 \[BalticOI 2004\] Sequence](https://www.luogu.com.cn/problem/P4331)
-   [Luogu P4597 Sequence](https://www.luogu.com.cn/problem/P4597)
-   [AtCoder dwango Challenge 2 Preliminary E - Fireworks](https://atcoder.jp/contests/dwango2016-prelims/tasks/dwango2016qual_e)

<span id="ví-dụ-trường-hợp-chuyển-trạng-thái-có-ràng-buộc"></span>
### Ví dụ: trường hợp chuyển trạng thái có ràng buộc

???+ example "[\[NOISG 2018 Finals\] Safety](https://www.luogu.com.cn/problem/P11598)"
    Cho dãy $\{a_i\}$ độ dài $n$. Tìm dãy $\{b_i\}$ sao cho
    $|b_i-b_{i-1}|\le h$ với mọi $1<i\le n$, và làm $\sum_i|a_i-b_i|$ nhỏ nhất.
    In ra giá trị nhỏ nhất.

??? note "Lời giải"
    Nội dung gần giống bài trước, chỉ khác rằng ràng buộc trên dãy $\{b_i\}$ đã
    thay đổi. Tương tự, đặt $f_i(x)$ là giá trị nhỏ nhất của tổng sai lệch trên
    $i$ số đầu khi số thứ $i$ nhận giá trị $x$:

    $$
    f_i(x) = \min\sum_{j=1}^i|a_j-b_j|\text{ với điều kiện }|b_{j-1}-b_j|\le h,\forall 1<j\le i,~b_i=x.
    $$

    Suy ra phương trình chuyển trạng thái

    $$
    f_i(x) = |a_i-x| + \min_{|y-x|\le h} f_{i-1}(y).
    $$

    Điều kiện ban đầu là $f_0(x)\equiv 0$. Cuối cùng vẫn cần tính $\min_xf_n(x)$.

    Tách chuyển trạng thái thành các thao tác trên hàm lồi, gồm hai bước:

    1.  Trước hết lấy cực trị của $f_{i-1}(x)$, biến thành
        $\min_{|y-x|\le h} f_{i-1}(y)$, tương đương với tích chập dưới đúng của
        $f_{i-1}(x)$ và $0_{[-h,h]}(x)$;
    2.  Cộng hàm thu được với $|a_i-x|$.

    Cũng vì độ dốc mỗi lần chỉ thay đổi một, có thể xét duy trì điểm gãy. Khi
    đó, hai thao tác này có thể mô tả như sau:

    1.  Dịch tất cả đoạn độ dốc âm sang trái $h$, và dịch tất cả đoạn độ dốc
        dương sang phải $h$;
    2.  Chèn $a_i$ hai lần.

    Với bài này, duy trì riêng các đoạn độ dốc âm và dương sẽ tiện
    lợi hơn. Vì thao tác chủ yếu tập trung quanh đoạn độ dốc bằng không, dùng
    [hai heap đối đỉnh](../../ds/binary-heap.md#heap-đối-đỉnh),
    tức dùng riêng max-heap và min-heap để duy trì các điểm gãy của đoạn độ dốc
    âm và dương. Các phép tịnh tiến toàn bộ điểm gãy được thực hiện bằng lazy
    tag. Vì bước thứ hai cần chèn một $a_i$ vào mỗi heap, sau khi chèn, đỉnh
    max-heap không nhất thiết vẫn nhỏ hơn hoặc bằng đỉnh min-heap. Khi đó, hoán
    đổi hai đỉnh heap cho đến khi quan hệ thứ tự của hai đỉnh heap được thỏa
    mãn.

    Cuối cùng, xét cách cập nhật giá trị nhỏ nhất trong quá trình thao tác. Vì
    bước tịnh tiến đầu tiên không làm thay đổi giá trị nhỏ nhất, chỉ cần xét thao
    tác hoán đổi đỉnh heap. Giả sử $\xi_{-1}>\xi_1$. Khi hoán đổi hai đỉnh heap
    $\xi_{-1}$ và $\xi_1$, hàm từ

    $$
    \max\{0,\xi_{-1}-x\}+\max\{0,x-\xi_1\}
    $$

    biến thành

    $$
    \max\{0,\xi_1-x\}+\max\{0,x-\xi_{-1}\}.
    $$

    Trong quá trình này, hình dạng của hàm không đổi, chỉ bị tịnh tiến xuống
    dưới $|\xi_{-1}-\xi_1|$. Vì vậy, để hàm trước và sau khi hoán đổi đỉnh heap
    giữ nguyên, chỉ cần cộng $|\xi_{-1}-\xi_1|$ vào giá trị nhỏ nhất.

    Độ phức tạp thời gian của thuật toán vẫn là $O(n\log n)$, vì sau mỗi lần
    thêm phần tử, thao tác hoán đổi đỉnh heap thực hiện nhiều nhất một lần.

    ```cpp
    --8<-- "docs/dp/code/opt/slope-trick/safety.cpp"
    ```

Bài mẫu:

-   [Luogu P4272 \[CTSC2009\] Sequence Transformation](https://www.luogu.com.cn/problem/P4272)
-   [Luogu P11598 \[NOISG 2018 Finals\] Safety](https://www.luogu.com.cn/problem/P11598)
-   [AtCoder Beginner Contest 217 H - Snuketoon](https://atcoder.jp/contests/abc217/tasks/abc217_h)
-   [AtCoder Regular Contest 070 E - NarrowRectangles](https://atcoder.jp/contests/arc070/tasks/arc070_c)
-   [AtCoder Regular Contest 123 D - Inc, Dec - Decomposition](https://atcoder.jp/contests/arc123/tasks/arc123_d)

<span id="duy-trì-độ-dốc"></span>
## Duy trì độ dốc

Còn có một số bài toán mà việc duy trì độ dốc tiện lợi hơn. Lớp bài toán này
thường cũng có thể giải bằng tư tưởng
[tham lam hối tiếc](../../basic/greedy.md#lời-giải-hối-tiếc)
hoặc mô phỏng luồng chi phí. Trong mô hình luồng chi phí, chi phí nhỏ nhất
thường là hàm lồi theo lượng, và đây là cơ sở để dùng Slope Trick.

<span id="ví-dụ-bài-toán-giao-dịch-cổ-phiếu"></span>
### Ví dụ: bài toán giao dịch cổ phiếu

???+ example "[Codeforces 865 D. Buy Low Sell High](https://codeforces.com/problemset/problem/865/D)"
    Cho dãy giá cổ phiếu $\{p_i\}$ trong $n$ ngày (đều dương). Ban đầu nắm giữ
    $0$ cổ phiếu. Mỗi ngày có thể mua một cổ phiếu, bán một cổ phiếu hoặc không
    giao dịch. Tính lợi nhuận lớn nhất sau $n$ ngày.

??? note "Lời giải"
    Trước hết xét lời giải DP trực tiếp. Đặt $f_i(x)$ là lợi nhuận lớn nhất khi
    kết thúc ngày thứ $i$ và đang nắm giữ $x\ge 0$ cổ phiếu. Khi đó

    $$
    f_i(x) = \max\{f_{i-1}(x-1)-p_i,f_{i-1}(x),f_{i-1}(x+1)+p_i\}.
    $$

    Trạng thái ban đầu là $f_0(0)=0$, và với mọi $x\neq 0$, $f_0(x)=-\infty$.
    Đáp án của bài toán là $f_n(0)$.

    Để chuyển từ $f_{i-1}(x)$ sang $f_i(x)$ cần hai bước:

    1.  Lấy tích chập trên đúng của $f_{i-1}(x)$ với hàm tuyến tính từng đoạn
        $\tilde h(x)$ ứng với hàm

        $$
        h_i(x) = \begin{cases}p_i,&x=-1,\\0,&x=0,\\-p_i,&x=1\end{cases}
        $$

        (đây là hàm lõm);
    2.  Vì việc này làm hàm có giá trị hữu hạn trên khoảng $[-1,0)$, trái với
        yêu cầu $x\ge 0$, nên cần cắt lấy phần của hàm trên $[0,+\infty)$.

    Chuyển chúng thành thay đổi trên các đoạn độ dốc, có hai bước sau:

    1.  Chèn một đoạn độ dốc có độ dài $2$ và độ dốc $-p_i$;
    2.  Trong các đoạn độ dốc hữu hạn, xóa một đoạn có độ dài $1$ và độ dốc lớn
        nhất.

    Vì độ dài của các đoạn độ dốc luôn là số tự nhiên, có thể duy trì nhiều
    đoạn độ dài một, như vậy chỉ cần ghi lại độ dốc của mỗi đoạn. Vì chỉ cần
    chèn và truy cập giá trị lớn nhất, chỉ cần dùng một max-heap. Thao tác gồm
    hai bước:

    1.  Chèn $-p_i$ hai lần;
    2.  Pop đỉnh heap.

    Còn cần duy trì giá trị $f_i(0)$. Vì sau bước đầu tiên, giá trị của hàm tại
    $x=-1$ là $f_{i-1}(0)+p_i$, nên giá trị tại $x=0$ là giá trị này cộng với
    đỉnh heap sắp bị pop, chính là độ dốc của hàm trên khoảng $[-1,0]$. Vì phép
    cắt không đổi giá trị hàm tại $x=0$, đây chính là $f_i(0)$.

    So sánh cách cài đặt thuật toán này với code của phần
    [dãy tăng với chi phí nhỏ nhất](#ví-dụ-dãy-tăng-với-chi-phí-nhỏ-nhất)
    ở trên có thể thấy, thuật toán này tương đương với bài toán biến dãy giá cổ
    phiếu thành dãy không tăng với chi phí nhỏ nhất.

    Độ phức tạp thời gian là $O(n\log n)$.

    ```cpp
    --8<-- "docs/dp/code/opt/slope-trick/stock.cpp"
    ```

Bài mẫu:

-   [Codeforces 865 D. Buy Low Sell High](https://codeforces.com/problemset/problem/865/D)

<span id="ví-dụ-bài-toán-vận-chuyển-đất-đá"></span>
### Ví dụ: bài toán vận chuyển đất đá

???+ example "[\[USACO16OPEN\] Landscaping P](https://www.luogu.com.cn/problem/P2748)"
    Cho hai dãy độ dài $n$, $\{a_i\}$ và $\{b_i\}$, lần lượt biểu thị lượng đất
    hiện có và lượng đất cần có trong vườn thứ $i$ (không được thừa cũng không
    được thiếu). Mua một đơn vị đất và đặt vào một vườn bất kỳ tốn $X$; chuyển
    một đơn vị đất ra khỏi một vườn bất kỳ tốn $Y$; vận chuyển một đơn vị đất từ
    vườn $i$ sang vườn $j$ tốn $Z|i-j|$. Tính chi phí nhỏ nhất để thỏa mãn
    nhu cầu của mọi vườn. ($a_i,b_i\le 10$)

??? note "Lời giải"
    Xét lời giải DP trực tiếp. Đặt $f_i(x)$ là chi phí nhỏ nhất để thỏa mãn nhu
    cầu của $i$ vườn đầu, và còn dư ròng $x$ đơn vị đất được chuyển đến các vườn
    phía sau. Nếu $x<0$, điều đó tương đương với thiếu ròng $|x|$ đơn vị đất và
    cần được chuyển từ các vườn phía sau về. Khi đó có thể viết phương trình
    chuyển trạng thái:

    $$
    f_i(x) = \min_{y\in\mathbf R} f_{i-1}(y) + |y|Z + h((x-y)+(b_i-a_i)).
    $$

    Trong đó, hàm $h(\delta)$ biểu thị chi phí khi lượng đất mua ròng của vườn
    hiện tại là $\delta$, tức

    $$
    h(\delta) = \max\{0,\delta\}X + \max\{0,-\delta\}Y = \max\{\delta X,-\delta Y\}.
    $$

    Hàm này là hàm lồi. Ý nghĩa của phương trình chuyển trạng thái là:

    -   Khi $i-1$ vườn trước còn dư ròng $y$ đơn vị đất, chi phí nhỏ nhất là
        $f_{i-1}(y)$;
    -   Chi phí vận chuyển lượng đất dư (hoặc thiếu) giữa vườn $i-1$ và $i$ là
        $|y|Z$;
    -   Bằng mua bán, điều chỉnh lượng đất của vườn thứ $i$ từ $a_i$ thành
        $b_i$, đồng thời điều chỉnh lượng đất dư ròng từ $y$ thành $x$, với chi
        phí nhỏ nhất là $h((x-y)+(b_i-a_i))$.

    Trạng thái ban đầu là $f_0(0)=0$, và với mọi $x\neq 0$, $f_0(x)=+\infty$.
    Đáp án của bài toán là $f_n(0)$.

    Có thể chia phép biến đổi từ $f_{i-1}(x)$ sang $f_i(x)$ thành ba bước:

    1.  Trước hết cộng $|x|Z$, thu được $f_{i-1}(x)+|x|Z$;
    2.  Sau đó lấy tích chập dưới đúng với $h(x)$, thu được
        $\min_{y\in\mathbf R}f_{i-1}(y)+|y|Z+h(x-y)$;
    3.  Cuối cùng, tịnh tiến hàm sang trái $(b_i-a_i)$ đơn vị.

    Chuyển thành thao tác trên các đoạn độ dốc, cũng gồm ba bước:

    1.  Cộng $-Z$ vào tất cả đoạn độ dốc bên trái gốc, và cộng $Z$ vào tất cả
        đoạn độ dốc bên phải gốc;
    2.  Thay thế tất cả đoạn độ dốc nhỏ hơn $-Y$ bằng $-Y$, và thay thế tất cả
        đoạn độ dốc lớn hơn $X$ bằng $X$;
    3.  Tịnh tiến tất cả đoạn độ dốc sang trái $(b_i-a_i)$ đơn vị.

    Trong đề gốc, $a_i$ và $b_i$ rất nhỏ, nên chỉ cần duy trì nhiều đoạn độ dốc
    độ dài $1$. Mặc dù số đoạn độ dốc là vô hạn, chúng có cận trên $X$ và cận
    dưới $-Y$, và số đoạn độ dốc nằm nghiêm ngặt giữa hai cận này không nhiều.
    Vì không có thao tác chèn, có thể dùng hai stack để duy trì các đoạn độ dốc
    hai phía gốc. Phép cộng trên khoảng và phép lấy cực trị trên khoảng đều được
    xử lý bằng đánh dấu lười. Ba bước trên lần lượt tương ứng với:

    1.  Gắn đánh dấu lười cho hai stack trái và phải: bên trái cộng $-Z$, bên phải
        cộng $Z$;
    2.  Mỗi khi pop phần tử trong stack, lấy max với $-Y$ và min với $X$. Nếu
        stack trái rỗng thì pop $-Y$. Nếu stack phải rỗng thì pop $X$;
    3.  Pop $(b_i-a_i)$ phần tử trên đỉnh stack trái và chèn vào stack phải; tất
        nhiên, khi $b_i-a_i<0$ thì làm ngược lại.

    Khi trao đổi đỉnh stack, cập nhật đáp án: đi sang trái thì trừ đi độ dốc
    hiện tại, đi sang phải thì cộng độ dốc hiện tại.

    Độ phức tạp của thuật toán là $O(n\max\{a_i,b_i\})$.

    ```cpp
    --8<-- "docs/dp/code/opt/slope-trick/landscaping.cpp"
    ```

Bài mẫu:

-   [Luogu P2748 \[USACO16OPEN\] Landscaping P](https://www.luogu.com.cn/problem/P2748)
-   [Kyoto University PC 2016 H - WAAAAAAAAAAAAALL](https://atcoder.jp/contests/kupc2016/tasks/kupc2016_h)
-   [JAG Practice Contest 2017 J - Farm Village](https://atcoder.jp/contests/jag2017autumn/tasks/jag2017autumn_j)

<span id="bài-tập"></span>
## Bài tập

Cuối bài viết, dưới đây là một số bài toán từng xuất hiện trong các kỳ thi lập
trình, có thể giải bằng Slope Trick để luyện tập.

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

<span id="tài-liệu-tham-khảo-và-ghi-chú"></span>
## Tài liệu tham khảo và ghi chú

-   [\[Tutorial\] Slope Trick - zscoder](https://codeforces.com/blog/entry/47821)
-   [Slope trick explained - Kuroni](https://codeforces.com/blog/entry/77298)
-   [Slope Trick - USACO Guide](https://usaco.guide/adv/slope-trick?lang=cpp)
-   [\[Tutorial\] Intuition on Slope Trick - maomao90](https://codeforces.com/blog/entry/103222)

[^convex-def]: Các giáo trình khác nhau có thể dùng tên gọi khác nhau cho hàm lồi.

[^inf-conv]: Cũng thường được gọi là tích chập $\min$, tích chập $\inf$, hoặc tích chập $(\min,+)$.
