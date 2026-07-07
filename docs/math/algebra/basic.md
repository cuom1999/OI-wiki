author: jifbt, billchenchina, Enter-tainer, Great-designer, iamtwz, ImpleLee, isdanni, Menci, ouuan, Tiphereth-A, warzone-oier, Xeonacid, c-forrest

Chương này giới thiệu ngắn gọn các kiến thức liên quan đến đại số trừu tượng. Ở giai đoạn hiện nay, nội dung chính của lập trình thi đấu không trực tiếp kiểm tra kiến thức đại số trừu tượng, nhưng trong phần mô tả thuật toán hoặc lời giải bài toán, các khái niệm cơ bản về cấu trúc đại số thường xuyên xuất hiện. Vì vậy, độc giả nắm được các khái niệm cơ sở của đại số trừu tượng có thể hiểu một số thuật toán nhanh hơn. Do đó, phần nội dung này không phải kiến thức bắt buộc với mọi thí sinh, mà chỉ dùng làm tài liệu tham khảo cho những độc giả có quan tâm hoặc có thể hưởng lợi từ nó. Đồng thời, chương này sẽ tránh giới thiệu đại số trừu tượng quá đầy đủ hay quá sâu[^oi-wiki-not-wikipedia], mà tập trung vào các khái niệm cơ bản và những phần gắn bó chặt chẽ nhất với các kiến thức khác trong OI. Độc giả muốn học đại số trừu tượng một cách hệ thống nên tham khảo các giáo trình chuyên ngành về đại số trừu tượng.

Để giúp độc giả hiểu rõ hơn việc đọc phần này có thể đem lại lợi ích gì, dưới đây là một số ví dụ về những chỗ trong lập trình thi đấu có thể liên quan đến kiến thức đại số trừu tượng:

-   Nhiều định lý trong lý thuyết số và đa thức là trường hợp đặc biệt của các kết quả trong đại số trừu tượng;
-   Trong cấu trúc dữ liệu, những cấu trúc như [cây đoạn](../../ds/seg.md) có thể duy trì thông tin của một vị nhóm, còn hệ thức truy hồi của nhiều bài DP có thể được trừu tượng hóa thành cấu trúc vị nhóm như vậy;
-   Trong tổ hợp, cách phát biểu và chứng minh chặt chẽ của [nguyên lý đếm Pólya](../combinatorics/polya.md) cần dùng các khái niệm liên quan đến lý thuyết nhóm.

Trên cơ sở đó, chương này sẽ tập trung giới thiệu các kiến thức cơ sở không thể bỏ qua và các phần liên quan trực tiếp đến những ứng dụng này. Để bắt đầu, bài này giới thiệu các khái niệm cơ bản về nhóm, vành và trường.

<span id="nhóm"></span>
## Nhóm

Định nghĩa của nhóm như sau.

???+ abstract "Nhóm"
    Cho $G$ là một tập hợp khác rỗng, trên đó có phép toán hai ngôi $\cdot:G\times G\rightarrow G$. Nếu chúng thỏa mãn các tính chất sau, thì $(G,\cdot)$ được gọi là một **nhóm** (group):
    
    1.  Luật kết hợp (associative property): với mọi $a,b,c\in G$, có $a\cdot(b\cdot c)=(a\cdot b)\cdot c$;
    2.  Có phần tử đơn vị: tồn tại $e\in G$ sao cho với mọi $a\in G$, đều có $a\cdot e = e\cdot a = a$. Khi đó, $e$ được gọi là **phần tử đơn vị** (identity element) của $G$;
    3.  Tồn tại phần tử nghịch đảo: với mọi $a\in G$, tồn tại $b\in G$ tương ứng sao cho $a\cdot b=b\cdot a=e$. Khi đó, $b$ được gọi là **phần tử nghịch đảo** (inverse element) của $a$.

??? info "Về điều kiện đóng trong định nghĩa"
    Phép toán hai ngôi trong định nghĩa này đã ngầm chứa điều kiện đóng, tức là với mọi $a,b\in G$, đều có $a\cdot b\in G$. Một số tài liệu sẽ liệt kê riêng điều kiện này.

???+ note "Các tính chất cơ bản của nhóm"
    Với nhóm $(G,\cdot)$, các tính chất sau luôn đúng:
    
    1.  Với mọi dãy hữu hạn $\{g_i\}_{i=1}^k\subseteq G$, kết quả của tích $g_1\cdot g_2\cdot\cdots\cdot g_k$ không phụ thuộc vào cách đặt dấu ngoặc;
    2.  Phần tử đơn vị $e$ luôn duy nhất;
    3.  Với mọi phần tử $a\in G$, nghịch đảo $a^{-1}$ của nó cũng duy nhất;
    4.  Luật giản ước (cancellation law): với $a,b,c\in G$, nếu $a\cdot c=b\cdot c$ hoặc $c\cdot a=c\cdot b$, thì $a=b$.

Nhóm xuất hiện rất phổ biến. Hiểu nôm na, mọi phép biến đổi không làm mất cấu trúc đều tự động tạo thành một nhóm. Xét một vài kiểu nhóm thường gặp làm ví dụ.

???+ example "Ví dụ về nhóm"
    -   **Nhóm đối xứng** (symmetric group): tất cả các [hoán vị](../permutation.md) trên tập hợp $M$, tức các song ánh từ $M$ đến chính $M$, tạo thành nhóm $S_M$ dưới phép hợp thành ánh xạ. Phần tử đơn vị là phép biến đổi đồng nhất, phần tử nghịch đảo là ánh xạ nghịch đảo (song ánh tất yếu có ánh xạ nghịch đảo). Nếu tập hợp $M$ hữu hạn và có kích thước $n$, nhóm này cũng thường được ký hiệu là $S_n$ và gọi là nhóm đối xứng bậc $n$.
    -   Nhóm đối xứng không gian (symmetry group): với một hình hình học, toàn bộ các phép biến đổi làm nó trùng khớp với chính nó cũng tạo thành một nhóm dưới phép hợp thành ánh xạ. Nhóm này mô tả tính đối xứng không gian của hình hình học đó. Ví dụ cụ thể có thể xem tại [các nhóm đối xứng không gian thường gặp](../combinatorics/polya.md#các-nhóm-đối-xứng-không-gian-thường-gặp).
    -   Nhóm cộng của số nguyên: tập số nguyên $\mathbf Z$ tạo thành nhóm $(\mathbf Z,+)$ dưới phép cộng $+$. Phần tử đơn vị là $0$, phần tử nghịch đảo là số đối.
    -   Nhóm nhân các số nguyên modulo $n$ (multiplicative group of integers modulo $n$): với một modulo $n$, các [lớp đồng dư](../number-theory/basic.md#lớp-đồng-dư-và-hệ-thặng-dư) ứng với tất cả các số nguyên nguyên tố cùng nhau với $n$ tạo thành nhóm $((\mathbf Z/n\mathbf Z)^\times,\times)$ dưới phép nhân. Phần tử đơn vị là $\bar 1$, phần tử nghịch đảo chính là [nghịch đảo nhân](../number-theory/inverse.md) modulo $n$ (lớp đồng dư tương ứng), và sự tồn tại của nó được suy ra từ [định lý Bézout](../number-theory/bezouts.md). Phân tích cấu trúc cụ thể xem tại [nhóm nhân các số nguyên modulo $n$](./ring-theory.md#ứng-dụng-nhóm-nhân-của-các-lớp-đồng-dư-số-nguyên).
    -   Nhóm tuyến tính tổng quát (general linear group): tất cả các ma trận vuông khả nghịch cấp $n$ trên trường số $F$ tạo thành nhóm $GL_n(F)$ dưới phép nhân. Phần tử đơn vị là ma trận đơn vị, phần tử nghịch đảo là ma trận nghịch đảo.

Để hiểu định nghĩa nhóm tốt hơn, có thể đối chiếu với một vài ví dụ không phải nhóm.

???+ example "Ví dụ không phải nhóm"
    -   Tất cả các ánh xạ từ $M$ đến chính nó (không nhất thiết là song ánh) không tạo thành nhóm, vì những ánh xạ không phải song ánh không có phần tử nghịch đảo.
    -   Các số nguyên không tạo thành nhóm dưới phép nhân, vì $2$ không có nghịch đảo nhân trong phạm vi số nguyên.
    -   Các số nguyên dương cũng không tạo thành nhóm dưới phép cộng, vì chúng không có phần tử đơn vị cộng.
    -   Tất cả các lớp đồng dư khác không modulo $n$ thường không tạo thành nhóm theo nghĩa phép nhân. Chẳng hạn, trong $(\mathbf Z/6\mathbf Z)\setminus\{\overline 0\}$, xảy ra $\overline 2\times\overline 3=\overline 0$ không thuộc tập hợp này; điều đó có nghĩa phép nhân thậm chí không phải là một phép toán hai ngôi được định nghĩa tốt trên tập hợp này (hay nói cách khác, nó không thỏa mãn tính đóng).

Đôi khi cũng cần thảo luận tính chất của những cấu trúc kém hoàn chỉnh hơn này. Vì vậy, có thể định nghĩa các khái niệm sau, chúng rộng hơn nhóm.

???+ abstract "Nửa nhóm"
    Với tập hợp khác rỗng $G$ và một phép toán hai ngôi $\cdot$ trên nó, nếu phép toán này thỏa mãn luật kết hợp, thì $(G,\cdot)$ được gọi là một **nửa nhóm** (semigroup).

???+ abstract "Vị nhóm"
    Với nửa nhóm $(G,\cdot)$, nếu nó còn có phần tử đơn vị, thì $(G,\cdot)$ được gọi là một **vị nhóm** (monoid).

???+ example "Ví dụ về vị nhóm và nửa nhóm"
    Trong các ví dụ bên trên, $(\mathbf N_+,+)$ là nửa nhóm, còn $(\mathbf Z,\times)$ là vị nhóm.

Cuối cùng, nhiều phép toán trên các nhóm quen thuộc, ngoài việc thỏa mãn luật kết hợp, còn thỏa mãn luật giao hoán. Cấu trúc của loại nhóm này tương đối đơn giản; chúng được gọi là nhóm Abel, hay nhóm giao hoán.

???+ abstract "Nhóm Abel"
    Với nhóm $(G,\cdot)$, nếu phép toán $\cdot$ còn thỏa mãn luật giao hoán (tiếng Anh: commutative property), tức là với mọi $a,b\in G$, đều có $a\cdot b=b\cdot a$, thì $(G,\cdot)$ được gọi là một **nhóm Abel** (Abelian group) hay **nhóm giao hoán** (commutative group).

???+ example "Ví dụ về nhóm Abel và nhóm không Abel"
    -   Nhóm cộng các số nguyên $(\mathbf Z,+)$ là một nhóm Abel.
    -   Khi $n\ge3$, nhóm đối xứng $S_n$ không phải nhóm Abel.

Đó là các định nghĩa cơ bản liên quan đến lý thuyết nhóm. Nội dung khác về lý thuyết nhóm có thể tham khảo tại [lý thuyết nhóm](./group-theory.md) hoặc các sách liên quan.

<span id="vành"></span>
## Vành

Định nghĩa của vành như sau.

???+ abstract "Vành"
    Với tập hợp khác rỗng $R$ và hai phép toán hai ngôi $+:R\times R\rightarrow R$ và $\cdot:R\times R\rightarrow R$ trên nó, nếu chúng thỏa mãn các tính chất sau, thì $(R,+,\cdot)$ được gọi là một **vành** (ring):
    
    1.  $(R,+)$ tạo thành nhóm Abel, phần tử đơn vị của nó được ký hiệu là $0$, và nghịch đảo của phần tử $a\in R$ theo $+$ được ký hiệu là $-a$.
    2.  $(R,\cdot)$ tạo thành nửa nhóm, tức $\cdot$ thỏa mãn luật kết hợp.
    3.  Luật phân phối (distributive property): với mọi $a,b,c\in R$, có $a\cdot(b+c)=a\cdot b+a\cdot c$ và $(a+b)\cdot c=a\cdot c+b\cdot c$.

Để tiện trình bày, hai phép toán hai ngôi $+$ và $\cdot$ thường được gọi là phép cộng và phép nhân của vành. Tương ứng, phần tử đơn vị của phép cộng được gọi là **phần tử không** (zero), còn phần tử đơn vị của phép nhân (nếu tồn tại) được gọi là **phần tử đơn vị** (identity). Cần tránh nhầm lẫn chúng với phép cộng, phép nhân trong các tập số cụ thể, cũng như với số tự nhiên không và một.

??? info "Về việc định nghĩa có yêu cầu phần tử đơn vị nhân hay không"
    Trong một số định nghĩa, vành bắt buộc phải có phần tử đơn vị nhân; tương ứng, cấu trúc không có phần tử đơn vị nhân được gọi là **giả vành** (rng hoặc pseudo-ring). Khi gặp cần xác định theo ngữ cảnh. Wikipedia sử dụng cách định nghĩa này[^ring-wiki].

Cấu trúc cộng của vành khá đơn giản, nhưng cấu trúc nhân thì rất sơ khai. Vì vậy, nếu tương tự như nhóm và đặt thêm các yêu cầu trên phép nhân, sẽ thu được các định nghĩa liên quan sau.

???+ abstract "Vành có đơn vị"
    Với vành $(R,+,\cdot)$, nếu nó có phần tử đơn vị nhân, ký hiệu là $1$, thì $(R,+,\cdot)$ được gọi là một **vành có đơn vị** (ring with identity).

???+ abstract "Vành chia"
    Với vành có đơn vị khác không $(R,+,\cdot)$, nếu với mọi phần tử khác $0$ là $a\in R$, đều tồn tại nghịch đảo nhân (ký hiệu là $a^{-1}$), thì $(R,+,\cdot)$ được gọi là một **vành chia** (division ring).

???+ abstract "Vành giao hoán"
    Với vành $(R,+,\cdot)$, nếu phép nhân của nó thỏa mãn luật giao hoán, thì $(R,+,\cdot)$ được gọi là một **vành giao hoán** (commutative ring).

Một điểm thú vị trong định nghĩa vành chia là nó xem $0$ là phần tử đặc biệt trong cấu trúc nhân. Lý do là $0 = 0\cdot a = a\cdot 0$[^zero-multiplication]. Nghĩa là phần tử đơn vị cộng của vành nhân với bất kỳ phần tử nào cũng cho kết quả là chính $0$. Vì thế, tự nhiên nó không có nghịch đảo nhân, trừ khi bản thân nó cũng là phần tử đơn vị nhân. Vành như vậy chỉ có thể là vành không (xem ví dụ bên dưới).

Khi phân tích cấu trúc nhân của một vành tổng quát, cần loại bỏ ảnh hưởng của phần tử đơn vị cộng và xét $R\setminus\{0\}$. Dựa trên ý tưởng này, có định nghĩa sau.

???+ abstract "Ước của không"
    Với vành $(R,+,\cdot)$, nếu tồn tại $b\in R$ với $b\ne 0$ sao cho $a\cdot b=0$ hoặc $b\cdot a=0$, thì phần tử khác không $a$ được gọi là một **ước của không** (zero divisor).

???+ abstract "Phần tử khả nghịch"
    Với vành $(R,+,\cdot)$, nếu phần tử $a$ có nghịch đảo nhân, tức tồn tại $b\in R$ sao cho $a\cdot b=b\cdot a=1$, thì phần tử $a\in R$ được gọi là một **phần tử khả nghịch**, hay **đơn vị** (unit).

???+ warning "\"Đơn vị\" và \"phần tử đơn vị\""
    Đừng nhầm lẫn hai khái niệm này. Để tránh nhầm lẫn, phần đại số trừu tượng sẽ dùng tên gọi "phần tử khả nghịch" thay cho "đơn vị".

Ước của không không thể là phần tử khả nghịch, và phần tử khả nghịch không thể là ước của không. Tuy nhiên, một phần tử khác không có thể vừa không phải ước của không, vừa không phải phần tử khả nghịch.

Nếu một vành không có ước của không, điều đó cho thấy tập hợp tất cả các phần tử khác không đóng dưới phép nhân, tức $(R\setminus\{0\},\cdot)$ tạo thành nửa nhóm. Tiến thêm một bước, nếu yêu cầu nó trở thành vị nhóm giao hoán, sẽ thu được định nghĩa miền nguyên.

???+ abstract "Miền nguyên"
    Với vành khác không $(R,+,\cdot)$, nếu nó là vành giao hoán, có phần tử đơn vị nhân và không có ước của không, thì nó được gọi là **miền nguyên** (integral domain).

Mặc dù các phần tử trong miền nguyên không nhất thiết có nghịch đảo, tính chất không có ước của không đã đủ để thiết lập luật giản ước trên miền nguyên.

???+ note "Luật giản ước trong miền nguyên"
    Giả sử miền nguyên $R$ có các phần tử $a,b,c\in R$ và $a\neq 0$. Nếu $ab=ac$, thì tất yếu $b=c$.

Với một vành có đơn vị tổng quát, nếu chỉ xét toàn bộ các phần tử khả nghịch của nó, cũng thu được cấu trúc nhóm. Cấu trúc này được gọi là nhóm nhân của vành, hay nhóm đơn vị.

???+ abstract "Nhóm nhân (nhóm đơn vị)"
    Với vành có đơn vị $(R,+,\cdot)$, đặt $R^\times$ là tập hợp tất cả các phần tử khả nghịch trong $R$. Khi đó $(R^\times,\cdot)$ tạo thành nhóm, được gọi là **nhóm nhân** (multiplicative group), hay **nhóm đơn vị** (unit group), của vành có đơn vị $R$.

Một số ví dụ đơn giản nhất về vành như sau.

???+ example "Ví dụ về vành"
    -   Vành không (zero ring): tập hợp $\{0\}$ tạo thành vành dưới phép cộng $+$ và phép nhân $\times$ theo nghĩa thông thường, và được gọi là vành không. Nó là vành duy nhất chỉ có một phần tử, đồng thời là vành duy nhất mà phần tử đơn vị cộng bằng phần tử đơn vị nhân.
    -   Vành số nguyên: tập số nguyên $\mathbf Z$ cùng với phép cộng $+$ và phép nhân $\times$ được định nghĩa thông thường trên nó tạo thành vành $(\mathbf Z,+,\times)$. Đây là một miền nguyên, nhưng không phải vành chia.
    -   Vành đa thức: với một vành $R$, có thể định nghĩa [vành đa thức](./ring-theory.md#vành-đa-thức) $R[x]$ trên nó. Nếu $R$ là miền nguyên, thì vành đa thức này tất yếu là miền nguyên.
    -   Quaternion: tương tự số phức, có thể xét tập hợp $\mathbf H=\{a+b\mathrm{i}+c\mathrm{j}+d\mathrm{k}:a,b,c,d\in\mathbf R\}$, và định nghĩa phép cộng, phép nhân trên nó. Trong đó, phép nhân của $\mathrm{i},\mathrm{j},\mathrm{k}$ thỏa mãn
    
        $$
        \mathrm{i}^2=\mathrm{j}^2=\mathrm{k}^2=-1,\ \mathrm{i}\mathrm{j}=-\mathrm{j}\mathrm{i}=\mathrm{k},\ \mathrm{j}\mathrm{k}=-\mathrm{k}\mathrm{j}=\mathrm{i},\ \mathrm{k}\mathrm{i}=-\mathrm{i}\mathrm{k}=\mathrm{j}.
        $$
    
        Khi đó có thể kiểm tra $\mathbf H$ tạo thành một vành, hơn nữa nó là một vành chia không giao hoán.
    -   Tập con $2\mathbf Z$ của tập số nguyên tạo thành vành dưới phép cộng và phép nhân theo nghĩa thông thường. Nó là vành giao hoán, không có ước của không, nhưng không có phần tử đơn vị nhân.
    -   Các lớp đồng dư modulo $n$ của số nguyên, $\mathbf Z/n\mathbf Z$, tạo thành vành dưới phép cộng và phép nhân các lớp đồng dư. Nó là vành giao hoán, có đơn vị (tức $\bar 1$). Vành như vậy có ước của không khi và chỉ khi $n$ là hợp số. Vì thế, khi $n$ là số nguyên tố, vành $(\mathbf Z/n\mathbf Z, +,\times)$ là miền nguyên; hơn nữa, khi đó nó cũng là vành chia, nên thực chất nó tạo thành một trường. Nhóm nhân của nó $((\mathbf Z/n\mathbf Z)^\times,\times)$ chính là nhóm nhân các số nguyên modulo $n$.
    -   Vành ma trận: tất cả các ma trận vuông cấp $n$ trên vành $R$ tạo thành một vành $M_n(R)$ dưới phép cộng và phép nhân ma trận. Vành này thường có ước của không và không phải vành giao hoán.
    -   Với toàn bộ các tập con $\mathcal P(A)$ của một tập hợp $A$, nếu định nghĩa hiệu đối xứng $\triangle$ của tập hợp và phép giao $\cap$ lần lượt làm phép cộng và phép nhân, thì $(\mathcal P(A),\triangle,\cap)$ tạo thành một vành. Vành này có đơn vị, thường có ước của không và là vành giao hoán.

Việc thảo luận về cấu trúc của vành còn vượt xa những nội dung này. Để tìm hiểu thêm, có thể tham khảo [lý thuyết vành](./ring-theory.md) hoặc các sách liên quan.

<span id="trường"></span>
## Trường

Trường là một cấu trúc đại số có tính chất mạnh hơn vành. Cụ thể, trường là vành chia giao hoán. Cũng có thể viết định nghĩa đầy đủ của nó.

???+ abstract "Trường"
    Với tập hợp khác rỗng $F$ và hai phép toán hai ngôi $+:F\times F\rightarrow F$ và $\cdot:F\times F\rightarrow F$ trên nó, nếu chúng thỏa mãn các tính chất sau, thì $(F,+,\cdot)$ được gọi là một **trường** (field):
    
    1.  $(F,+)$ tạo thành nhóm Abel, phần tử đơn vị của nó được ký hiệu là $0$, và nghịch đảo của phần tử $a\in F$ theo $+$ được ký hiệu là $-a$.
    2.  $(F\setminus\{0\},\cdot)$ tạo thành nhóm Abel, phần tử đơn vị của nó được ký hiệu là $1$, và nghịch đảo của phần tử $a\in F\setminus\{0\}$ theo $\cdot$ được ký hiệu là $a^{-1}$.

Nói cách khác, trường là cấu trúc đại số đóng đối với cả bốn phép toán cộng, trừ, nhân, chia.

Ví dụ thường gặp về trường như sau.

???+ example "Ví dụ về trường"
    -   Trường số: tập số hữu tỷ $\mathbf Q$, tập số thực $\mathbf R$ và tập số phức $\mathbf C$ đều tạo thành trường dưới phép cộng và phép nhân theo nghĩa thông thường.
    -   Trường hữu hạn (finite field): tập hợp các lớp đồng dư của số nguyên modulo số nguyên tố $p$, $\mathbf Z/p\mathbf Z$, tạo thành trường dưới phép cộng và phép nhân các lớp đồng dư. Ngoài chúng ra còn có các trường hữu hạn khác; cấu trúc của chúng được xác định duy nhất bởi kích thước, và kích thước đó tất yếu có dạng lũy thừa của một số nguyên tố.
    -   **Trường phân thức** (fraction field): cho $(R,+,\cdot)$ là một miền nguyên, có thể xét tập hợp $Q$ gồm các phần tử có dạng $ab^{-1}$. Nói chặt chẽ hơn, định nghĩa quan hệ tương đương trên tập $R\times(R\setminus\{0\})$: $(a_1,b_1)\sim(a_2,b_2)$ khi và chỉ khi $a_1b_2=a_2b_1$. Khi đó, $Q$ là tập hợp các lớp tương đương theo quan hệ này, tức $R\times(R\setminus\{0\})/\sim$; trong đó lớp tương đương chứa $(a,b)$ được ký hiệu là $ab^{-1}$. Nếu định nghĩa các phép toán trên nó bởi
    
        $$
        \begin{aligned}
        a_1b_1^{-1}+a_2b_2^{-1} &= (a_1\cdot b_2+a_2\cdot b_1)(b_1\cdot b_2)^{-1},\\
        (a_1b_1^{-1})\cdot(a_2b_2^{-1}) &= (a_1\cdot a_2)(b_1\cdot b_2)^{-1}
        \end{aligned}
        $$
    
        thì $(Q,+,\cdot)$ tạo thành một trường, gọi là trường phân thức của $R$. Chẳng hạn, trường số hữu tỷ $(\mathbf Q,+,\times)$ chính là trường phân thức của vành số nguyên $(\mathbf Z,+,\times)$.
    -   Trường bậc hai (quadratic field): đây là trường thu được bằng cách thêm $\sqrt d$ vào trường số hữu tỷ $\mathbf Q$, trong đó $d\neq 0,1$ và $d$ không có thừa số chính phương. Nội dung liên quan có thể tham khảo tại [trường bậc hai](../number-theory/quadratic.md).

So với vành, trường có cấu trúc cộng và nhân rất đơn giản. Vì thế, cấu trúc của bản thân trường thường khá đơn giản. Điều này làm cho việc nghiên cứu trường và việc nghiên cứu vành rất khác nhau: thông thường trọng tâm được chuyển sang các mở rộng trường và lý thuyết Galois tương ứng. Trong thi đấu thuật toán, đôi khi cần tính toán trên các trường mở rộng của trường số hữu tỷ hoặc trường hữu hạn. Nội dung liên quan đến lý thuyết trường có thể tham khảo tại [lý thuyết trường](./field-theory.md) hoặc các sách liên quan.

<span id="ứng-dụng"></span>
## Ứng dụng

Cuối cùng, lấy bài toán dưới đây làm ví dụ để minh họa các đối tượng đại số trừu tượng hỗ trợ phân tích vấn đề cụ thể như thế nào.

???+ note "[Bài mẫu DP động và phân trị cây động (bản tăng cường)](https://www.luogu.com.cn/problem/P4751)"
    Cho một cây có $n$ đỉnh, mỗi đỉnh có trọng số, thực hiện $m$ lần sửa đổi trọng số đỉnh. Sau mỗi lần sửa đổi, cần xuất tổng trọng số của tập độc lập có trọng số lớn nhất trên cây. Bài toán bắt buộc xử lý trực tuyến.

???+ note "Phân tích ý tưởng"
    Bài này là mẫu cho DP động. Một cài đặt có độ phức tạp đúng cần dùng [cây nhị phân cân bằng toàn cục](../../ds/global-bst.md); mã mẫu cụ thể cũng nằm ở trang tương ứng. Phần này chỉ kết hợp với bối cảnh bài toán này để phân tích quá trình mô hình hóa.
    
    Để làm nổi bật trọng tâm, tạm thời không xét cách cây nhị phân cân bằng toàn cục xử lý cấu trúc cây, mà chuyển sang xét bài toán DP tập độc lập có trọng số lớn nhất trên một đường thẳng. Xét lần lượt từng điểm trên đường thẳng $[1,n]$; điểm $i$ có thể được chọn ($1$) hoặc không được chọn ($0$). Lần lượt đặt lời giải tối ưu của bài toán con trên $[1,i]$ trong hai trường hợp này là $f_{i,1}$ và $f_{i,0}$. Khi đó có thể viết phương trình DP là
    
    $$
    \begin{aligned}
    f_{i,1}&=w_{i}+f_{i-1,0},\\
    f_{i,0}&=\max\{f_{i-1,1},f_{i-1,0}\}.
    \end{aligned}
    $$
    
    Giá trị đầu là $(f_{0,1},f_{0,0})=(0,0)$, và đáp án cuối cùng là $\max\{f_{n,1},f_{n,0}\}$. Để biểu diễn ảnh hưởng của điểm $i$ lên kết quả cuối cùng, chỉ cần nhận xét rằng quan hệ đệ quy này có thể viết thành
    
    $$
    (f_{i,1},f_{i,0})=g(f_{i-1,1},f_{i-1,0};w_i).
    $$
    
    Đây là một chuỗi các ánh xạ từ $\mathbf R^2$ đến $\mathbf R^2$, ánh xạ $(f_{i-1,1},f_{i-1,0})$ thành $(f_{i,1},f_{i,0})$. Dùng ngôn ngữ của nhóm để mô tả, các phép biến đổi này tạo thành một vị nhóm dưới phép hợp thành ánh xạ. Đây chính là đối tượng mà cây đoạn có thể duy trì.
    
    Tuy nhiên, nếu phép biến đổi có tham số $g(\cdot;w_i)$ như vậy không có cấu trúc đặc biệt, một ánh xạ tổng quát từ $\mathbf R^2$ đến $\mathbf R^2$ không thể được mô tả bằng dữ liệu hữu hạn chiều. Cần một quan sát khác: nếu trên $\mathbf R\cup\{-\infty\}$, định nghĩa $\max$ làm phép cộng và $+$ làm phép nhân, thì $\mathbf R\cup\{-\infty\}$ tạo thành một cấu trúc tương tự vành; trong cấu trúc này, $-\infty$ là phần tử đơn vị cộng, và $0$ là phần tử đơn vị nhân. Nhưng nó không phải vành, vì các phần tử của nó không phải đều có nghịch đảo cộng. Cấu trúc như vậy được gọi là nửa vành[^semiring]; nửa vành $(\mathbf R\cup\{-\infty\},\max,+)$ đang xét được gọi là **nửa vành nhiệt đới** (tropical semiring).
    
    Dựa trên nửa vành nhiệt đới $(R,\oplus,\otimes)$, có thể định nghĩa phép nhân ma trận trên nó. Cụ thể, với ma trận $m\times n$ chiều $A=(a_{ij})$ và ma trận $n\times p$ chiều $B=(b_{jk})$, có thể định nghĩa tích $AB$ là $(c_{ik})$, trong đó mỗi phần tử bằng
    
    $$
    c_{ik} = \bigoplus_{j=1}^n(a_{ij}\otimes b_{jk}) = \max_{1\le j\le n}\;(a_{ij}+b_{jk}).
    $$
    
    Với các ký hiệu này, có thể xem quan hệ truy hồi ở trên là một phép biến đổi tuyến tính trên nửa vành nhiệt đới và viết bằng ngôn ngữ ma trận như sau:
    
    $$
    \left(\begin{matrix}f_{i,1}\\f_{i,0}\end{matrix}\right)
    =\left(\begin{matrix}-\infty&w_i\\0&0\end{matrix}\right)\left(\begin{matrix}f_{i-1,1}\\f_{i-1,0}\end{matrix}\right).
    $$
    
    Từ đó, chỉ cần dùng cây đoạn để duy trì tích các ma trận trên nửa vành nhiệt đới này là có thể trả lời bài toán DP động trên đường thẳng với nhiều lần sửa đổi.
    
    Bây giờ quay lại phiên bản trên cây của bài toán. Với nút $i$ trên cây, ký hiệu tập các nút con của nó là $S(i)$. Khi đó phương trình DP tại đây là
    
    $$
    \begin{aligned}
    f_{i,1}&=w_i+\sum_{j\in S(i)}f_{j,0},\\
    f_{i,0}&=\sum_{j\in S(i)}\max\{f_{j,1},f_{j,0}\}.
    \end{aligned}
    $$
    
    Trước hết, dùng phân rã cây theo chuỗi nặng để chuyển bài toán về phiên bản trên đường thẳng. Giả sử $h$ là nút con nặng của $i$, khi đó hệ thức truy hồi trên có thể viết thành
    
    $$
    \begin{aligned}
    f_{i,1}&=w_i+f_{h,0}+g_{i,1},\\
    f_{i,0}&=\max\{f_{h,0},f_{h,1}\}+g_{i,0},
    \end{aligned}
    $$
    
    trong đó
    
    $$
    \begin{aligned}
    g_{i,1}&=\sum_{j\in S(i),\ j\neq h}f_{j,0},\\
    g_{i,0}&=\sum_{j\in S(i),\ j\neq h}\max\{f_{j,1},f_{j,0}\}
    \end{aligned}
    $$
    
    tóm tắt đóng góp của các nút con nhẹ. Theo mô tả bên trên, các phép biến đổi này đều có thể viết dưới dạng ma trận trên nửa vành nhiệt đới, nên toàn bộ bài toán cũng có thể được duy trì trên cây đoạn sau khi phân rã cây. Tuy nhiên, nếu trực tiếp dùng phân rã cây kết hợp cây đoạn, một lần sửa đổi có độ phức tạp $O(\log^2n)$, nên cần dùng cây nhị phân cân bằng toàn cục đã nhắc bên trên để tối ưu xuống $O(\log n)$; ngoài ra cũng có thể dùng LCT để duy trì.
    
    Nửa vành nhiệt đới và các phép toán ma trận trên nó đã xuất hiện trong nhiều bài toán quen thuộc. Nếu thay $\max$ bên trên bằng $\min$, nửa vành nhiệt đới tương ứng thường được dùng trong các bài toán đường đi ngắn nhất. Nếu ma trận vuông cấp $n$ là $A$ cho biết trọng số cạnh (ngắn nhất) giữa từng cặp đỉnh của một đồ thị có $n$ đỉnh, thì phần tử tại vị trí $(i,j)$ của $A^k$ là khoảng cách ngắn nhất từ đỉnh $i$ đến đỉnh $j$ qua nhiều nhất $k$ cạnh; đặc biệt, $A^n$ chính là ma trận khoảng cách của đồ thị này. Trong cài đặt thực tế, không cần tính lũy thừa ma trận này bằng vét cạn, mà dùng thuật toán Floyd với độ phức tạp $O(n^3)$.

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   Dummitt, D.S. và Foote, R.M. (2004) Đại số trừu tượng. Ấn bản thứ 3, John Wiley & Sons, Inc.
-   [Nửa vành nhiệt đới - Wikipedia](https://en.wikipedia.org/wiki/Tropical_semiring)

[^oi-wiki-not-wikipedia]: Vì [OI Wiki không phải bách khoa toàn thư](../../intro/what-oi-wiki-is-not.md#oi-wiki-không-phải-bách-khoa-toàn-thư).

[^ring-wiki]: [Vành (toán học) - Wikipedia](https://en.wikipedia.org/wiki/Ring_%28mathematics%29)

[^zero-multiplication]: Cách suy ra công thức này là $0\cdot a+0 = 0\cdot a = (0+0)\cdot a = 0\cdot a + 0\cdot a$; trong đó đẳng thức thứ nhất và thứ hai đến từ định nghĩa phần tử đơn vị cộng, đẳng thức thứ ba đến từ luật phân phối, và hệ quả cuối cùng đến từ luật giản ước của phép cộng. Phép nhân ở phía còn lại cũng tương tự.

[^semiring]: Nửa vành (semiring) là cấu trúc thu được bằng cách nới lỏng yêu cầu phép cộng nhất định phải có nghịch đảo trong định nghĩa vành có đơn vị; tức cấu trúc cộng là vị nhóm giao hoán, còn cấu trúc nhân là vị nhóm. Xem thêm tại [Wikipedia](https://en.wikipedia.org/wiki/Semiring).
