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
    $s_{i_2}\le x_2\le s_{i_2+1}$; hiển nhiên $i_1\le i_2$. Đặt
    $\Delta_i=\Delta f(s_i,s_{i+1})$. Khi đó, có thể chứng minh
    $\Delta_{i_1}\le\Delta\tilde f(x_1,x_2)\le\Delta_{i_2}$.
    
    Xét hai trường hợp. Nếu $i_1=i_2$, thì
    $\Delta_{i_1}=\Delta\tilde f(x_1,x_2)=\Delta_{i_2}$, bất đẳng thức hiển
    nhiên đúng. Ngược lại, ta có
    
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
Chính vì độ dốc của hàm lồi có tính đơn điệu, khi duy trì độ dốc, ta thường cần
chọn các cấu trúc dữ liệu như [heap (hàng đợi ưu tiên)](../../ds/heap.md) hoặc
[cây cân bằng](../../ds/bst.md).

Bài viết này còn dùng một đặc trưng tương đương khác của hàm lồi. Với hàm
$f:\mathbf R\rightarrow\mathbf R\cup\{\pm\infty\}$, ta có thể xét vùng nằm phía
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
    $(x_1,y_1),(x_2,y_2)\in\operatorname{epi}f$ và bất kỳ $\alpha\in(0,1)$, ta
    có
    
    $$
    \alpha y_1+(1-\alpha)y_2 \ge \alpha f(x_1)+(1-\alpha)f(x_2) \ge f(\alpha x_1+(1-\alpha) x_2).
    $$
    
    Do đó, $\alpha(x_1,y_1)+(1-\alpha)(x_2,y_2)\in\operatorname{epi}f$.
    
    Ngược lại, nếu $\operatorname{epi}f$ là tập lồi, thì với mọi $x_1<x_2$ và
    $\alpha\in(0,1)$, ta có
    
    $$
    \alpha(x_1,f(x_1))+(1-\alpha)(x_2,f(x_2)) \in \operatorname{epi}f.
    $$
    
    Điều này tương đương với
    $\alpha f(x_1)+(1-\alpha)f(x_2)\ge f\left(\alpha x_1+(1-\alpha)x_2\right)$,
    tức tính lồi của $f$.

Lát nữa ta sẽ thấy, bằng thượng đồ thị, có thể liên hệ tích chập dưới đúng của
hàm lồi với tổng Minkowski của tập lồi.

<span id="&#x51F8;&#x51FD;&#x6570;&#x7684;&#x53D8;&#x6362;"></span>
## Các phép biến đổi hàm lồi

Tiếp theo, bài viết giới thiệu một số phép biến đổi bảo toàn tính lồi thường gặp
trong Slope Trick.

<span id="&#x975E;&#x8D1F;&#x7EBF;&#x6027;&#x7EC4;&#x5408;"></span>
### Tổ hợp tuyến tính không âm

Với hai hàm lồi $f$ và $g$, cùng các số thực không âm $\alpha,\beta\ge0$, hàm
$\alpha f+\beta g$ cũng là hàm lồi. Hơn nữa,

$$
\Delta(\alpha f+\beta g) = \alpha\Delta f + \beta\Delta g.
$$

Vì vậy, nếu đã duy trì độ dốc của các hàm lồi $f$ và $g$, để thu được độ dốc
của tổ hợp tuyến tính không âm $\alpha f+\beta g$, chỉ cần tính theo từng đoạn.

Trong các bài toán duy trì độ dốc, thường có một hàm có dạng khá đơn giản; khi
đó có thể giảm độ phức tạp sửa đổi bằng lazy tag. Trong các bài toán duy trì
điểm gãy, để tính các điểm gãy của độ dốc của $f+g$, chỉ cần trộn các điểm gãy
độ dốc của $f$ và $g$.

<span id="&#x5377;&#x79EF;&#x4E0B;&#x786E;&#x754C;minkowski-&#x548C;"></span>
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
    
    Do đó, kết hợp tính lồi của $f,g$ và định nghĩa của $h$, ta có
    
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
    
    Ngược lại, với mọi $(x,y)\in\operatorname{epi}h$, ta có $y\ge h(x)$. Theo
    định nghĩa của $h$, với mọi $\varepsilon>0$, tồn tại $x_1+x_2=x$ sao cho
    
    $$
    y + \varepsilon > f(x_1) + g(x_2).
    $$
    
    Đặt $y_1=f(x_1)$ và $y_2=g(x_2)$, ta có $y+\varepsilon>y_1+y_2$. Điều này
    nói rằng với mọi $\varepsilon>0$, điểm
    $(x_1,y_1)+(x_2,y_2)\in\operatorname{epi} f + \operatorname{epi} g$ nằm trên
    đoạn thẳng nối $(x,y)$ và $(x,y+\varepsilon)$. Cho
    $\varepsilon\rightarrow 0$, ta được
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

<span id="&#x6700;&#x503C;&#x64CD;&#x4F5C;"></span>
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

Sau khi hiểu hàm lồi và các phép biến đổi thường gặp của nó, ta có thể thông qua
các bài toán cụ thể để nắm cách tối ưu hóa DP bằng Slope Trick. Các ví dụ trong
bài viết được chia đại khái thành hai nhóm: duy trì điểm gãy và duy trì độ dốc,
nhằm giúp hiểu các thao tác thường gặp và chi tiết cài đặt của hai cách duy trì
này. Tuy nhiên, như đã nhấn mạnh ở trên, cách duy trì không phải là bản chất của
Slope Trick; cần chọn cách duy trì đoạn độ dốc phù hợp theo yêu cầu của từng bài
toán.

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
