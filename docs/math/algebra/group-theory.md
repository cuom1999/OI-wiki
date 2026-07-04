author: jifbt, billchenchina, Enter-tainer, Great-designer, iamtwz, ImpleLee, isdanni, Menci, ouuan, Tiphereth-A, warzone-oier, Xeonacid, c-forrest, cervoliu

Kiến thức tiên quyết: [Các khái niệm cơ bản của đại số trừu tượng](./basic.md), [Hoán vị và sắp xếp](../permutation.md)

## Giới thiệu

**Lý thuyết nhóm** (group theory) chủ yếu nghiên cứu nhóm, một loại [cấu trúc đại số](https://en.wikipedia.org/wiki/Algebraic_structure).

Để nghiên cứu cấu trúc của nhóm, cần nắm một số công cụ cơ bản, gồm nhóm con, đồng cấu nhóm và tác động nhóm. Trong lập trình thi đấu, các nhóm thường gặp chủ yếu là các nhóm liên quan đến lý thuyết số (chẳng hạn nhóm nhân modulo $n$ của các số nguyên, $(\mathbf Z/n\mathbf Z)^\times$) và các nhóm hoán vị; bài này sẽ tập trung giới thiệu các khái niệm liên quan. Những phần lý thuyết nhóm không được đề cập trong bài, như lý thuyết cấu trúc của nhóm hữu hạn và lý thuyết biểu diễn tuyến tính của nhóm, nên được tìm đọc trong các giáo trình chuyên sâu.

???+ info "Ký hiệu"
    Khi không gây nhầm lẫn, bài này có thể viết $g\cdot h$ thành $gh$, và cũng có thể viết nhóm $(G,\cdot)$ thành nhóm $G$.

Không thể hiểu đại số trừu tượng nếu tách rời các ví dụ. Để minh họa cho các khái niệm bên dưới, ta xét nhóm đối xứng $D_6$ của tam giác đều.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều"
    Như hình vẽ, với một tam giác đều cho trước, có tổng cộng sáu phép biến đổi khác nhau đưa nó trùng lại với chính nó.
    
    ![Nhóm đối xứng D\_6 của tam giác đều](../images/triangle_d6.svg)
    
    Ở đây, dùng $r$ để chỉ phép quay theo chiều kim đồng hồ, dùng $s$ để chỉ phép lật qua đường nối đỉnh $1$ với tâm của tam giác. Các phép biến đổi được hợp thành từ phải sang trái, tức $sr$ nghĩa là quay trước ($r$), rồi lật ($s$). Hai phép biến đổi khác nhau khi và chỉ khi có một đỉnh của tam giác nằm ở vị trí khác nhau sau hai phép biến đổi đó.
    
    |  Ký hiệu |                  Phép biến đổi                  | Cấp | Biểu diễn hoán vị |
    | :------: | :---------------------------------------------: | :-: | :---------------: |
    |   $e$    |       Biến đổi đồng nhất, tức không làm gì      |  1  |       $(1)$       |
    |   $r$    |       Quay theo chiều kim đồng hồ $120^\circ$   |  3  |      $(123)$      |
    |  $r^2$   |       Quay theo chiều kim đồng hồ $240^\circ$   |  3  |      $(132)$      |
    |   $s$    |       Lật qua đường nối $1$ với tâm             |  2  |       $(23)$      |
    |   $sr$   |       Quay $120^\circ$ trước, rồi lật           |  2  |       $(13)$      |
    |  $sr^2$  |       Quay $240^\circ$ trước, rồi lật           |  2  |       $(12)$      |
    
    Dễ kiểm tra rằng các phép biến đổi này thật sự tạo thành một nhóm. Chẳng hạn, phần tử đơn vị của nhóm là $e$, và nghịch đảo của $sr$ là chính nó. Hơn nữa, nhóm $D_6$ không giao hoán; ví dụ có thể kiểm tra trực tiếp $rs=sr^{-1}$.
    
    Các phép biến đổi ghi trong bảng không phải là cách mô tả đối xứng duy nhất ứng với ký hiệu đó. Chẳng hạn, "lật qua đường nối $2$ với tâm" cũng là một phép đối xứng của tam giác; nó không xuất hiện trong bảng, nhưng kết quả trùng với phép "quay $120^\circ$ trước, rồi lật". Các khái niệm như "cấp" và "biểu diễn hoán vị" trong bảng sẽ được giải thích bên dưới.

## Nhóm con

Để hiểu cấu trúc của một nhóm cho trước, trước hết có thể phân tích các cấu trúc con của nó. Cấu trúc con của một nhóm là những tập con của nhóm vẫn tạo thành nhóm dưới cùng phép toán. Từ đó có định nghĩa sau.

???+ abstract "Nhóm con"
    Cho nhóm $(G,\cdot)$ và một tập con $H\subseteq G$. Nếu $(H,\cdot)$ cũng là một nhóm, thì $H$ được gọi là một **nhóm con** (subgroup) của $G$, ký hiệu $H\le G$.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Trong $D_6$, dễ kiểm tra thấy các nhóm con của nó là $\{e\}$, $\{e,s\}$, $\{e,sr\}$, $\{e,sr^2\}$, $\{e,r,r^2\}$ và chính $D_6$, tổng cộng sáu nhóm. Ngoài $D_6$, cấu trúc của các nhóm con này đơn giản hơn và chứa một phần thông tin về nhóm ban đầu.

Để xác định một tập con $H\subseteq G$ có phải là nhóm con hay không, không cần kiểm tra từng tiên đề trong định nghĩa nhóm: tính kết hợp tự nhiên đúng; để tập con trở thành nhóm con, chỉ cần đảm bảo nó đóng đối với phép toán hai ngôi, có đơn vị và đóng đối với lấy nghịch đảo. Thực ra, các điều kiện này có thể gộp lại thành một điều kiện.

???+ note "Định lý (tiêu chuẩn nhận biết nhóm con)"
    Tập con $H$ của nhóm $G$ là nhóm con khi và chỉ khi với mọi $g,h \in H$ đều có $g^{-1}h\in H$.

### Nhóm con sinh bởi một tập con

Tổng quát, cho một tập con $S$ của nhóm $G$. Bắt đầu từ các phần tử trong $S$, lặp lại phép nhân và lấy nghịch đảo hữu hạn lần, tập tất cả kết quả có thể thu được sẽ tạo thành một nhóm con của $G$. Nhóm con này được gọi là nhóm con sinh bởi tập con $S$.

???+ abstract "Nhóm con sinh bởi một tập con"
    Cho nhóm $G$ và một tập con không rỗng $S\subseteq G$. Nếu $H$ là nhóm con nhỏ nhất (theo quan hệ bao hàm) trong các nhóm con của $G$ chứa $S$, thì $H$ được gọi là **nhóm con sinh bởi tập con $S$** (subgroup generated by a subset), ký hiệu $\langle S\rangle$. Đặc biệt, nếu $S=\{x\}$ là tập một phần tử, thì $\langle S\rangle$ cũng được ký hiệu là $\langle x\rangle$, và được gọi là nhóm con vòng của các lũy thừa của $x$ (cyclic subgroup of the powers of an element).

Có thể chứng minh với mọi tập con $S$ như vậy luôn tồn tại nhóm con này: $\langle S\rangle$ có thể được xây dựng bằng giao của tất cả các nhóm con của $G$ chứa $S$.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Trong nhóm $D_6$, chọn phép quay $r$ rồi lặp lại nó và phép nghịch đảo của nó, ta thu được nhóm con $\{e,r,r^2\}$. Nhóm con này có thể viết là $\langle r\rangle$. Mỗi nhóm con không tầm thường của $D_6$ đều có thể được sinh ra bằng cách chọn một phép biến đổi nào đó.

Một số tập con sinh ra cả nhóm. Các tập con như vậy đặc biệt quan trọng và được gọi là tập sinh của nhóm.

???+ abstract "Tập sinh của nhóm"
    Nếu tập con $S\subseteq G$ của nhóm $(G,\cdot)$ thỏa $\langle S\rangle=G$, thì $S$ được gọi là **tập sinh** (generating set of a group) của $G$. Các phần tử trong tập sinh $S$ được gọi là **phần tử sinh** (generator).

Bản thân nhóm là một tập sinh tầm thường của chính nó. Trường hợp thú vị hơn là tập sinh nhỏ hơn rất nhiều so với kích thước của nhóm.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Có thể kiểm tra $D_6=\langle s,r\rangle$; tức mọi phép đối xứng của tam giác đều có thể thu được bằng hợp thành của phép quay và phép lật.

### Nhóm vòng

Nhóm chỉ được sinh bởi một phần tử có cấu trúc rất đơn giản. Một nhóm như vậy được gọi là nhóm vòng.

???+ abstract "Nhóm vòng"
    Cho nhóm $G$. Nếu tồn tại $x\in G$ sao cho $G=\langle x\rangle$, thì $G$ được gọi là một **nhóm vòng** (cyclic group).

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Mỗi nhóm con không tầm thường của $D_6$ và cả $\{e\}$ đều là nhóm vòng.

Có thể chứng minh cấu trúc của nhóm vòng được xác định duy nhất bởi kích thước của nó. Nếu nhóm vòng vô hạn, nó có cùng cấu trúc nhóm với nhóm cộng các số nguyên $(\mathbf Z,+)$, ký hiệu $C_\infty$ hoặc $\mathbf Z$; nếu không, gọi số phần tử của nhóm là $n\in\mathbf N_+$, thì nó có cùng cấu trúc nhóm với nhóm cộng các lớp đồng dư modulo $n$, $(\mathbf Z/n\mathbf Z,+)$, ký hiệu $C_n$ hoặc $\mathbf Z_n$. Phát biểu nghiêm ngặt của kết quả này cần dùng khái niệm [đẳng cấu nhóm](#dang-cau-nhom) ở phần sau, dùng để mô tả chính xác việc hai nhóm có cùng cấu trúc.

???+ note "Định lý phân loại nhóm vòng"
    Nhóm vòng hữu hạn $G$ có kích thước $n$ đẳng cấu với $C_n$; nhóm vòng vô hạn $G$ đẳng cấu với $C_\infty$.

??? note "Chứng minh"
    Cho nhóm vòng $G=\langle x\rangle$. Nó luôn có thể viết là $G=\{x^n:n\in\mathbf Z\}$. Nếu $G$ hữu hạn, thì tồn tại các số tự nhiên $n<m$ sao cho $x^n=x^m$. Theo luật khử, suy ra $x^{m-n}=e$. Khi đó, lấy $n\in\mathbf N_+$ nhỏ nhất sao cho $x^n=e$; dãy $\{x^k\}$ sẽ có chu kỳ độ dài $n$, và các phần tử trong một chu kỳ đôi một khác nhau (nếu không sẽ mâu thuẫn với tính nhỏ nhất của $n$). Khi đó ánh xạ $x^k\mapsto\bar k$ cho một đẳng cấu $G\rightarrow\mathbf Z/n\mathbf Z$, tức $G\cong C_n$. Ngược lại, nếu $G$ vô hạn, các phần tử $x^k$ trong $G$ đôi một khác nhau, và ánh xạ $x^k\mapsto k$ cho đẳng cấu $G\rightarrow\mathbf Z$, tức $G\cong C_\infty$.

Mọi nhóm vòng đều là nhóm Abel. Ví dụ $D_6$ trong bài này cho thấy ngay cả khi mọi nhóm con không tầm thường của một nhóm đều là nhóm vòng, chính nhóm đó vẫn có thể không phải nhóm Abel.

### Cấp

Cấp của một nhóm là số phần tử của nhóm. Cấp của một phần tử cho trước trong nhóm là cấp của nhóm con vòng sinh bởi phần tử đó. Từ đó có các định nghĩa sau:

???+ abstract "Cấp của nhóm"
    **Cấp** (order) của nhóm $G$ là số phần tử của nó, ký hiệu $|G|$. Cấp của nhóm vô hạn cũng là vô hạn.

???+ abstract "Cấp của phần tử"
    **Cấp** (order) của phần tử $x\in G$ trong nhóm $G$ là số nguyên dương nhỏ nhất $n$ sao cho $x^n=e$, ký hiệu $|x|$; nếu không tồn tại $n$ như vậy, phần tử $x$ được nói là có cấp vô hạn, ký hiệu $|x|=\infty$.

Cấp của phần tử luôn không vượt quá cấp của nhóm; thực ra phần sau sẽ chứng minh cấp của phần tử luôn là ước của cấp của nhóm. Tuy nhiên, cấp của nhóm không phải lúc nào cũng là giá trị lớn nhất trong các cấp phần tử. Chẳng hạn, $D_6$ là nhóm cấp sáu, nhưng cấp lớn nhất của phần tử chỉ là $3$. Cấp của nhóm cũng không phải lúc nào cũng là bội chung nhỏ nhất của cấp các phần tử; ví dụ nhóm bốn Klein[^klein] $V_4$ có cấp $4$, nhưng chỉ có các phần tử cấp $1$ và cấp $2$.

???+ note "Định lý"
    Trong nhóm vòng hữu hạn $C_n=\langle x\rangle$, cấp của phần tử $x^k$ là
    
    $$
    \frac{n}{\gcd(k,n)}.
    $$
    
    Đặc biệt, số phần tử sinh của $C_n$ là $\varphi(n)$, trong đó $\varphi(\cdot)$ là [hàm phi Euler](../number-theory/euler-totient.md).

Ứng dụng thảo luận trên, cấp của nhóm nhân modulo $n$ của các số nguyên bằng $\varphi(n)$, và cấp của mọi phần tử $a$ trong nhóm đều là ước của nó, nên tất yếu $a^{\varphi(n)}=1$. Đây chính là [định lý Euler](../number-theory/fermat.md#%E6%AC%A7%E6%8B%89%E5%AE%9A%E7%90%86), vì các phần tử trong nhóm này chính là tất cả các phần tử nguyên tố cùng nhau với $n$.

### Lớp kề

Cấu trúc của các phần tử bên ngoài một nhóm con không hề hỗn loạn.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Xét nhóm con $\langle r\rangle$ trong $D_6$. Các phần tử còn lại $\{s,sr,sr^2\}$ có cấu trúc rất giống $\langle r\rangle$: mỗi phép biến đổi trong đó đều có thể thu được bằng hợp thành $s$ với một phép biến đổi trong $\langle r\rangle$. Tương tự, xét nhóm con $\langle s\rangle$, các phần tử còn lại trong nhóm có thể chia thành hai loại, $\{r,sr\}$ và $\{r^2,sr^2\}$; chúng có thể thu được bằng cách hợp thành các phần tử của $\langle s\rangle$ với $r$ và $r^2$. Hiện tượng này là tổng quát.

Với một nhóm con cho trước, ta có thể định nghĩa lớp kề của nó.

???+ abstract "Lớp kề"
    Cho $G$ là nhóm và $H\le G$ là nhóm con của nó. **Lớp kề trái** (left coset) và **lớp kề phải** (right coset) của $H$ chứa $g$ lần lượt được định nghĩa là các tập
    
    $$
    \begin{aligned}
    gH &= \{gh:h\in H\},\\
    Hg &= \{hg:h\in H\}.
    \end{aligned}
    $$
    
    Các phần tử trong lớp kề được gọi là đại diện (representative element) của lớp kề.

Bản thân nhóm con cũng là một lớp kề của nó. Với một nhóm con cho trước, toàn bộ các lớp kề tạo thành một phân hoạch của nhóm, tức nhóm là hợp rời nhau của tất cả các lớp kề. Một phân hoạch luôn có thể được xem là các lớp tương đương của một quan hệ tương đương. Đối với phân hoạch bằng lớp kề trái, quan hệ tương đương là $g_1\sim g_2$ khi và chỉ khi $g_1^{-1}g_2\in H$; đối với phân hoạch bằng lớp kề phải, quan hệ tương đương là $g_1\sim g_2$ khi và chỉ khi $g_1g_2^{-1}\in H$.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Theo ngôn ngữ lớp kề, trong ví dụ trên, $D_6$ có thể được chia thành $\langle r\rangle\cup s\langle r\rangle$ và $\langle s\rangle\cup \langle s\rangle r \cup \langle s\rangle r^2$. Cách đầu chia nhóm thành các lớp kề trái, cách sau chia nhóm thành các lớp kề phải. Cần chú ý rằng việc chọn đại diện không có gì đặc biệt; chẳng hạn có thể kiểm tra $s\langle r\rangle=sr\langle r\rangle$. Mọi phần tử trong một lớp kề đều có thể làm đại diện của lớp kề đó.

Các lớp kề khác nhau của cùng một nhóm con có cùng kích thước, bằng kích thước của nhóm con tương ứng. Vì toàn bộ các lớp kề của một nhóm con cho trước tạo thành một phân hoạch của nhóm, cấp của nhóm hữu hạn phải là bội nguyên của cấp nhóm con. Kết quả này gọi là định lý Lagrange.

???+ note "Định lý Lagrange"
    Với nhóm hữu hạn $G$ và nhóm con $H\le G$, có $|G|=[G:H]|H|$, trong đó $[G:H]$ là số lớp kề trái (hoặc phải) của $H$ trong $G$, gọi là **chỉ số** (index) của nhóm con $H$ trong nhóm $G$.

??? note "Chứng minh"
    Xét ánh xạ nhân trái với $g$, $h\mapsto gh$. Ánh xạ này và $h\mapsto g^{-1}h$ là nghịch đảo của nhau, nên đều là song ánh. Do đó, luôn có $|H|=|gH|$.

Vì cấp của một phần tử chính là cấp của nhóm con vòng sinh bởi phần tử đó, cấp của phần tử cũng phải là ước của cấp của nhóm.

### Nhóm con chuẩn tắc

Nói chung, lớp kề trái và lớp kề phải của một nhóm con cho trước không giống nhau.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Trong nhóm $D_6$, $\langle s\rangle r=\{r,sr\}$, nhưng $r\langle s\rangle=\{r,sr^2\}$. Tuy nhiên, nếu xét nhóm con $\langle r\rangle$, các lớp kề trái và phải lại luôn bằng nhau, vì khi đó nhóm chỉ có hai lớp kề và chính nhóm con đã là một lớp kề.

Việc lớp kề trái và phải có bằng nhau hay không phản ánh tính chất của nhóm con tương ứng.

???+ abstract "Nhóm con chuẩn tắc"
    Cho $N\le G$ là nhóm con của nhóm $G$. Nếu với mọi $h\in N$ và $g\in G$ đều có $ghg^{-1}\in N$, nói cách khác, với mọi $g\in G$ đều có $gNg^{-1}\subseteq N$, thì $N$ được gọi là một **nhóm con chuẩn tắc** (normal subgroup) của $G$, ký hiệu $N\trianglelefteq G$.

Điều kiện trong định nghĩa này tương đương với việc $gN=Ng$ luôn đúng. Nhóm $G$ luôn có các nhóm con chuẩn tắc tầm thường, là $\langle e\rangle$ và chính $G$.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Trong nhóm $D_6$, $\langle s\rangle$ không phải nhóm con chuẩn tắc, còn $\langle r\rangle$ là nhóm con chuẩn tắc.

### Nhóm thương

Nhóm con chuẩn tắc là một lớp nhóm con rất quan trọng, một lý do là ta có thể định nghĩa nhóm thương dựa trên nó.

Với nhóm $G$ và nhóm con chuẩn tắc $N\trianglelefteq G$, xét tập tất cả các lớp kề

$$
G/N = \{gN:g\in G\}.
$$

Lúc này lớp kề trái và phải trùng nhau, nên không cần phân biệt. Từ phép toán của nhóm $G$, có thể định nghĩa phép toán hai ngôi $\circ$ trên $G/N$ bằng

$$
g_1N\circ g_2N=(g_1g_2)N.
$$

Có thể chứng minh kết quả của phép toán không phụ thuộc vào cách chọn đại diện[^quotient]. Khi đó, $(G/N,\circ)$ thật sự có cấu trúc nhóm, gọi là **nhóm thương** (quotient group) của $G$ theo $N$. Nhóm thương $G/N$ không phải nhóm con của $G$; mỗi phần tử của nó là một tập con của nhóm $G$.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Trong nhóm $D_6$, ý nghĩa của nhóm thương $G/\langle r\rangle$ rất rõ ràng. Nó tương đương với việc trong tất cả các phép đối xứng này, bỏ qua góc quay của tam giác và chỉ quan tâm phép đó có lật tam giác hay không. Hợp thành hai phép cùng lật tam giác tương đương với không lật tam giác ban đầu; còn nếu một phép lật và phép kia không lật, thì hợp thành tất yếu vẫn lật tam giác. Thuộc tính có lật hay không cũng có cấu trúc nhóm. Về mặt đại số, việc bỏ qua chi tiết quay trong nhóm $D_6$ và chỉ xét có lật hay không chính là lấy nhóm thương $D_6/\langle r\rangle$. Các lập luận này không đúng cho nhóm con $\langle s\rangle$, vì nếu bỏ qua việc có lật hay không thì không thể xác định rõ góc quay; đây là lý do $G/\langle s\rangle$ không có cấu trúc nhóm thương.

Nhóm thương có thể đơn giản hóa một nhóm phức tạp, cho phép quan sát một phần cấu trúc của nhóm để hiểu nhóm ban đầu. Đây cũng là lý do nhóm thương còn được gọi là **nhóm nhân tử** (factor group). Nhóm không có nhóm con chuẩn tắc nào ngoài các nhóm con chuẩn tắc tầm thường được gọi là **nhóm đơn** (simple group); những nhóm này không thể rút gọn thành nhóm nhỏ hơn. Tương tự số nguyên tố, chúng là viên gạch tạo nên các cấu trúc nhóm phức tạp hơn.

## Đồng cấu nhóm

Cách thứ hai để hiểu cấu trúc của một nhóm cho trước là so sánh cấu trúc của hai nhóm với nhau.

Để so sánh hai nhóm, ta cần xây dựng một ánh xạ giữa chúng. Những ánh xạ này không thể tùy ý; nó phải bảo toàn cấu trúc nhóm, tức bảo toàn phép toán của nhóm trước và sau khi ánh xạ. Các ánh xạ như vậy được gọi là đồng cấu nhóm.

???+ abstract "Đồng cấu nhóm"
    Cho ánh xạ $\varphi:G\rightarrow H$ từ nhóm $(G,\cdot)$ đến nhóm $(H,\odot)$. Nếu $\varphi$ bảo toàn phép toán nhóm, tức với mọi $g_1,g_2\in G$ đều có $\varphi(g_1\cdot g_2)=\varphi(g_1)\odot\varphi(g_2)$, thì $\varphi$ được gọi là một **đồng cấu** (homomorphism) từ nhóm $G$ đến nhóm $H$.

Đồng cấu nhóm tất yếu đưa phần tử đơn vị đến phần tử đơn vị, và đưa phần tử nghịch đảo đến phần tử nghịch đảo.

???+ info "Ký hiệu"
    Trong phần sau, nếu không gây nhầm lẫn, ta không phân biệt ký hiệu phép toán trong các nhóm $G$ và $H$, và sẽ lược bỏ các ký hiệu phép toán để trình bày ngắn gọn.

### Đẳng cấu nhóm

Với một đồng cấu $\varphi:G\rightarrow H$ từ nhóm $G$ đến nhóm $H$, một câu hỏi tự nhiên là đồng cấu này phản ánh đến mức nào việc cấu trúc của $G$ và $H$ giống nhau. Để trả lời, xét ảnh $\varphi(G)$ của $G$ dưới đồng cấu $\varphi$; nó đưa cấu trúc của $G$ vào trong nhóm $H$. Một mặt, $\varphi(G)$ là một nhóm con của $H$; nhưng nếu $\varphi$ không toàn ánh, $\varphi(G)$ không bằng $H$. Mặt khác, $\varphi$ cũng không nhất thiết đơn ánh; nếu $\varphi$ không đơn ánh, $\varphi(G)$ chỉ phản ánh một phần cấu trúc của $G$. Chỉ khi $\varphi$ là song ánh, cấu trúc của $G$ và $H$ mới hoàn toàn trùng nhau. Đồng cấu nhóm đặc biệt này gọi là đẳng cấu nhóm.

???+ abstract "Đẳng cấu nhóm"
    Cho $\varphi:G\rightarrow H$ là đồng cấu từ nhóm $G$ đến nhóm $H$. Nếu $\varphi$ là song ánh, thì $\varphi$ được gọi là một **đẳng cấu** (isomorphism) giữa nhóm $G$ và nhóm $H$, ký hiệu $G\cong H$.

Hai nhóm đẳng cấu có cấu trúc hoàn toàn như nhau. Nếu chỉ quan tâm cấu trúc nhóm, hai nhóm đẳng cấu không cần phân biệt. Định lý phân loại nhóm vòng ở trên được phát biểu theo nghĩa đẳng cấu.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Quay lại ví dụ trên, mỗi phép đối xứng của tam giác đều tương ứng duy nhất với một phép hoán vị trên tập các đỉnh. Toàn bộ các hoán vị của tập đỉnh cũng tạo thành một nhóm, là $S_3$. Dễ kiểm tra, ánh xạ thu được $\varphi:D_6\rightarrow S_3$ là đồng cấu nhóm; hơn nữa, nó là đẳng cấu nhóm. Do đó $D_6\cong S_3$. Thực ra, nhóm cấp sáu hoặc đẳng cấu với $C_6$, hoặc đẳng cấu với $S_3$ (phần chứng minh nằm bên dưới).

Phân loại cấu trúc các nhóm hữu hạn có cấp cho trước là nội dung nghiên cứu quan trọng của lý thuyết nhóm, nhưng vượt quá phạm vi bài này.

### Hạt nhân của đồng cấu

Với đồng cấu tổng quát, ta có thể tiếp tục hỏi bao nhiêu thông tin cấu trúc nhóm bị mất qua đồng cấu. Tiếp tục dùng ký hiệu ở trên. Đã biết $\varphi(G)$ là nhóm con của $H$, vấn đề then chốt là quan hệ giữa $\varphi(G)$ và $G$.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Xét ánh xạ $\varphi: D_6 \rightarrow C_2 = \langle x\rangle$ được định nghĩa bởi
    
    $$
    \varphi(e)=\varphi(r)=\varphi(r^2)=e,\ \varphi(s)=\varphi(sr)=\varphi(sr^2)=x.
    $$
    
    Dễ kiểm tra, $\varphi$ là đồng cấu nhóm; nó là toàn ánh nhưng không đơn ánh. Ý nghĩa của nó rõ ràng: mỗi phép đối xứng của nhóm được ánh xạ đến việc phép đó có lật hay không. Thông tin của nhóm $D_6$ bị nén bởi đồng cấu này chính là thông tin về góc quay. Chẳng hạn, nếu không lật, mọi góc quay đều được ánh xạ đến phần tử đơn vị của nhóm $C_2$.

Ví dụ này gợi ý dùng nghịch ảnh của $\{e\}$ để đo phần cấu trúc bị mất trong đồng cấu. Từ đó có định nghĩa sau.

???+ abstract "Hạt nhân của đồng cấu"
    Cho $\varphi:G\rightarrow H$ là đồng cấu từ nhóm $G$ đến nhóm $H$. **Hạt nhân** (kernel) của đồng cấu $\varphi$ là $\ker\varphi=\{g\in G:\varphi(g)=e\}$, trong đó $e$ là phần tử đơn vị của $H$.

### Định lý cơ bản về đồng cấu

Hạt nhân $\ker\varphi$ của đồng cấu thực sự mô tả phần thông tin cấu trúc bị mất qua đồng cấu nhóm. Phát biểu chính xác của kết quả này là **định lý cơ bản về đồng cấu** (cũng gọi là **định lý đẳng cấu thứ nhất**) (fundamental theorem of group homomorphism, a.k.a., first isomorphism theorem).

???+ note "Định lý cơ bản về đồng cấu (định lý đẳng cấu thứ nhất)"
    Cho $\varphi:G\rightarrow H$ là đồng cấu từ nhóm $G$ đến nhóm $H$. Khi đó $\ker\varphi\trianglelefteq G$, và $G/\ker\varphi\cong\varphi(G)\le H$.

??? note "Chứng minh"
    Trước hết, $N=\ker\varphi$ là nhóm con chuẩn tắc, vì với mọi $h\in N$ ta có $\varphi(ghg^{-1})=\varphi(g)\varphi(h)\varphi(g)^{-1}=\varphi(g)\varphi(g)^{-1}=e$, tức $ghg^{-1}\in\ker\varphi$. Sau đó xét ánh xạ $\Phi:G/N\rightarrow\varphi(G)$ thỏa $\Phi(gN)=\varphi(g)$. Ánh xạ này xác định tốt, vì nếu $g_1N=g_2N$ thì $g_1^{-1}g_2\in N$, suy ra $\varphi(g_1^{-1}g_2)=e$, tức $\varphi(g_1)=\varphi(g_2)$. Ánh xạ $\Phi$ rõ ràng toàn ánh; nó cũng đơn ánh vì $\ker\Phi=\{gN:\varphi(g)=e\}=\{N\}$. Vì vậy $\Phi$ là đẳng cấu nhóm. Cuối cùng, $\varphi(g_1)\varphi(g_2)^{-1}=\varphi(g_1g_2^{-1})\in\varphi(G)$, nên theo tiêu chuẩn nhận biết nhóm con, $\varphi(G)$ là nhóm con.

???+ note "Hệ quả"
    Đồng cấu $\varphi:G\rightarrow H$ là đơn ánh khi và chỉ khi $\ker\varphi=\{e\}$. Khi đó, $G$ đẳng cấu với một nhóm con của $H$, tức $G\cong\varphi(G)\le H$.

Nói cách khác, hạt nhân của đồng cấu $\varphi$ là một nhóm con chuẩn tắc của $G$, và nhóm thương $G/\ker\varphi$ thu được khi chia cho $\ker\varphi$ đẳng cấu với ảnh $\varphi(G)$ của đồng cấu; ảnh này lại chính là một nhóm con của $H$.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Hạt nhân của đồng cấu $\varphi: D_6 \rightarrow C_2$ ở trên là $\langle r\rangle$. Phần thảo luận về nhóm con chuẩn tắc đã cho thấy $D_6/\langle r\rangle$ thật sự đẳng cấu với $C_2$.

### Đồng cấu tự nhiên

Kết quả này không bất ngờ. Lý do là khi xây dựng đồng cấu $\varphi: D_6 \rightarrow C_2$, ta đã dùng chính ý nghĩa hình học của nhóm thương $D_6/\langle r\rangle$. Hiện tượng này không hiếm. Thực ra, với mọi nhóm thương, ta đều có thể xây dựng một đồng cấu nhóm sao cho ảnh của đồng cấu đẳng cấu với nhóm thương đã cho.

???+ abstract "Đồng cấu tự nhiên"
    Cho nhóm $G$ và nhóm con chuẩn tắc $N\trianglelefteq G$. Ánh xạ $\pi: G\rightarrow G/N$ cho bởi $\pi(g)=gN$ là một toàn đồng cấu từ $G$ đến $G/N$, gọi là **đồng cấu tự nhiên** (natural homomorphism) hay **ánh xạ tự nhiên** từ nhóm $G$ đến nhóm thương $G/N$.

Kết quả này cũng cho thấy với mọi nhóm con chuẩn tắc của một nhóm cho trước, ta đều tìm được một đồng cấu nhóm tương ứng sao cho hạt nhân của đồng cấu đó chính là nhóm con chuẩn tắc đã cho. Định lý cơ bản về đồng cấu ở trên lại nói rằng hạt nhân của mọi đồng cấu đều là nhóm con chuẩn tắc. Do đó, nhóm con chuẩn tắc và hạt nhân của đồng cấu là hai mặt của cùng một vấn đề.

Dùng khái niệm ánh xạ tự nhiên, định lý cơ bản về đồng cấu nhóm nói rằng **biểu đồ giao hoán** (commutative diagram) sau đúng.

![Biểu đồ giao hoán của định lý cơ bản về đồng cấu](../images/homomorphism.svg)

Ở đây, mọi mũi tên đều là đồng cấu nhóm, $N=\ker\varphi$ là hạt nhân của đồng cấu $\varphi$, và $\varphi(G)$ là ảnh của đồng cấu $\varphi$. Các ánh xạ lần lượt là: $\pi:g\mapsto gN$ là ánh xạ tự nhiên (toàn đồng cấu) từ nhóm $G$ đến nhóm thương $G/N$; $\Phi:gN\mapsto\varphi(g)$ là đẳng cấu; $\iota$ là phép nhúng (đơn đồng cấu). Biểu đồ giao hoán có nghĩa là hợp thành các ánh xạ trên hai đường đi khác nhau từ $G$ đến $H$ cho cùng kết quả, tức $\varphi=\iota\circ\Phi\circ\pi$. Biểu đồ này cho thấy rõ thông tin mà đồng cấu $\varphi$ làm mất được phản ánh trong $\pi$ và $\iota$.

### Các định lý đẳng cấu của nhóm

Công cụ mạnh để hiểu cấu trúc nhóm là các định lý đẳng cấu của nhóm. Ở trên đã có định lý đẳng cấu thứ nhất. Để nội dung đầy đủ, ở đây nêu thêm các định lý đẳng cấu phổ biến khác.

Định lý đẳng cấu thứ hai liên quan đến khái niệm tích của các nhóm con.

???+ abstract "Tích của các tập con"
    Cho nhóm $G$ và các tập con $A,B\subseteq G$. **Tích** (product) của $A$ và $B$ là tập con $AB=\{ab:a\in A,b\in B\}$.

Tích của các nhóm con không phải lúc nào cũng là nhóm con. Chẳng hạn, trong nhóm $D_6$, tích của nhóm con $A=\langle s\rangle$ và nhóm con $B=\langle sr\rangle$ là $AB=\{e,s,r,sr\}$, không phải nhóm con của $G$, vì $(sr)s=r^2\notin AB$. Thực ra, những phản ví dụ có dạng $a\in A$, $b\in B$ nhưng $ba\notin AB$ chính là lý do căn bản làm tích không phải nhóm con. Ta có định lý sau.

???+ note "Định lý"
    Cho nhóm $G$ và các nhóm con $A,B\le G$. Tích $AB$ là nhóm con khi và chỉ khi $AB=BA$.

??? note "Chứng minh"
    Nếu tích $AB$ là nhóm con, thì với mọi $a\in A$ và $b\in B$ ta có $ba=(a^{-1}b^{-1})^{-1}\in AB$, do đó $BA\subseteq AB$. Ngược lại, nếu $AB=BA$, thì với mọi $a_1,a_2\in A$ và $b_1,b_2\in B$ có $(a_1b_1)(a_2b_2)^{-1}=a_1b_1b_2^{-1}a_2^{-1}\in a_1BA=a_1AB=AB$, nên theo tiêu chuẩn nhận biết nhóm con, $AB$ là nhóm con.

**Định lý đẳng cấu thứ hai** (second isomorphism theorem, a.k.a., diamond isomorphism theorem) đưa ra một điều kiện đủ đơn giản hơn để tích của các nhóm con vẫn là nhóm con, đồng thời xác định cấu trúc của nó.

???+ note "Định lý đẳng cấu thứ hai"
    Cho nhóm $G$ và các nhóm con $A,B\le G$ thỏa $A\le N_G(B)$. Khi đó $AB\le G$, $B\trianglelefteq AB$, $A\cap B\trianglelefteq A$, và $AB/B\cong A/(A\cap B)$. Ở đây, $N_G(B)$ là [bộ chuẩn hóa](#bo-chuan-hoa-va-bo-trung-tam-hoa) của $B$. Đặc biệt, một điều kiện đủ cho $A\le N_G(B)$ là $B\trianglelefteq G$.

??? note "Chứng minh"
    Vì $A\le N_G(B)$, với mọi $a\in A$ đều có $aBa^{-1}=B$, tức $aB=Ba$. Do đó $AB=BA$, và theo định lý trên $AB$ là nhóm con. Nhóm con $B$ là nhóm con của $AB$ có lớp kề trái và phải bằng nhau, nên $B\trianglelefteq AB$.
    
    Xét ánh xạ $\varphi:A\rightarrow AB/B$ thỏa $\varphi(a)=aB$. Nó là toàn ánh, và hạt nhân của nó là $\ker\varphi=\{a\in A:aB=B\}=A\cap B$. Áp dụng định lý cơ bản về đồng cấu sẽ được kết quả.

**Định lý đẳng cấu thứ ba** (third isomorphism theorem) đưa ra mối tương ứng giữa nhóm con chuẩn tắc và nhóm thương của nhóm thương với nhóm con chuẩn tắc và nhóm thương của nhóm ban đầu. Nó giải thích vì sao việc tiếp tục phân ra nhóm thương là hợp lý.

???+ note "Định lý đẳng cấu thứ ba"
    Cho nhóm $G$ có các nhóm con chuẩn tắc $H,K\trianglelefteq G$, và $H\le K$. Khi đó $K/H\trianglelefteq G/H$, và $(G/H)/(K/H)\cong G/K$.

??? note "Chứng minh"
    Xét ánh xạ $\varphi:G/H\rightarrow G/K$ thỏa $\varphi(gH)=gK$. Nó là một toàn đồng cấu nhóm, và $\ker\varphi=\{gH:g\in K\}=K/H$. Áp dụng định lý cơ bản về đồng cấu là đủ.

Kết quả này có thể mở rộng thành định lý đẳng cấu thứ tư, hay **định lý tương ứng** (correspondence theorem), tiếp tục cho mối tương ứng giữa dàn nhóm con của nhóm và dàn nhóm con của nhóm thương.

???+ note "Định lý tương ứng"
    Cho nhóm $G$ có nhóm con chuẩn tắc $N\trianglelefteq G$. Giữa tập tất cả các nhóm con của $G$ chứa $N$, $\mathcal H=\{H:N\subseteq H\subseteq G\}$, và tập tất cả các nhóm con của nhóm thương $G/N$, $\mathcal S=\{S:S\le G/N\}$, tồn tại một song ánh $\varphi:\mathcal H\rightarrow\mathcal S$ đưa $H\in\mathcal H$ đến $H/N\in\mathcal S$. Song ánh này bảo toàn quan hệ bao hàm giữa các nhóm con, và mỗi nhóm con chuẩn tắc của $G$ luôn được ánh xạ đến một nhóm con chuẩn tắc của $G/N$.

??? info "Về nội dung các định lý đẳng cấu"
    Trong các giáo trình khác nhau, nội dung và tên gọi của các định lý đẳng cấu nhóm có thể khác nhau. Ở đây chọn một phiên bản phổ biến. [Wikipedia](https://en.wikipedia.org/wiki/Isomorphism_theorems#Note_on_numbers_and_names) có tóm tắt sự khác nhau về nội dung và tên gọi trong các giáo trình thông dụng.

## Tác động nhóm

Cách thứ ba để hiểu cấu trúc của một nhóm cho trước là xét tác động của nhóm lên một tập hợp.

Chẳng hạn, nhóm đối xứng của tam giác đều trong bài này được định nghĩa thông qua tác động của các phần tử nhóm (tức các phép đối xứng) lên tam giác. Một ví dụ khác, nhóm đối xứng $S_M$ có thể được định nghĩa thông qua tác động của các phần tử của nó lên tập $M$. Tác động ở đây có nghĩa là mỗi phần tử của nhóm tương ứng với một hoán vị trên tập hợp.

???+ abstract "Tác động của nhóm lên tập hợp"
    Cho nhóm $G$, tập $X$ và ánh xạ $G\times X\rightarrow X$. Ký hiệu ảnh của $(g,x)$ dưới ánh xạ này là $g\cdot x$. Nếu ánh xạ thỏa $g_1\cdot(g_2\cdot x)=(g_1g_2)\cdot x$ và $e\cdot x=x$ với mọi $g_1,g_2\in G$ và $x\in X$, thì ánh xạ đó được gọi là **tác động nhóm** (group action) của $G$ lên $X$.

??? info "\"Tác động trái\" và \"tác động phải\""
    Định nghĩa tác động nhóm ở đây trong một số nơi[^group-action] được gọi là tác động trái (left action), vì trong ký hiệu $g\cdot x$, phần tử của nhóm được viết bên trái phần tử của tập. Tương ứng, khi phần tử hợp thành $g_1g_2$ tác động lên tập hợp, cần thực hiện tác động của $g_2$ trước, rồi đến tác động của $g_1$. Tất nhiên, cũng có thể định nghĩa tác động phải, ký hiệu $x\cdot g$. Khi đó thứ tự hợp thành các phần tử nhóm ngược với tác động trái, tức $x\cdot (g_1g_2)=(x\cdot g_1)\cdot g_2$. Hai cách này chỉ khác nhau về ký hiệu, không khác bản chất; vì vậy bài này mặc định dùng ký hiệu tác động trái.

Với tác động nhóm thỏa định nghĩa trên, tự nhiên có cấu trúc sau:

$$
\begin{aligned}
\varphi:{\color{Maroon}{G}}\rightarrow {\color{Orchid}{S_X}}&\\
{\color{Maroon}{g}}\mapsto {\color{Orchid}{\varphi_g}}&: {\color{RoyalBlue}{X}}\rightarrow{\color{YellowGreen}{X}}\\
&\quad {\color{RoyalBlue}{x}}\mapsto {\color{YellowGreen}{g\cdot x}}.
\end{aligned}
$$

Ánh xạ này đưa mỗi phần tử $g$ của nhóm $G$ đến một hoán vị $\varphi_g$ trên tập $X$, trong đó hoán vị $\varphi_g$ đưa phần tử $x$ đến $g\cdot x$.

Theo định nghĩa, song ánh $\varphi_e$ ứng với phần tử đơn vị $e$ của nhóm là ánh xạ đồng nhất trên $X$, còn ánh xạ $\varphi_g$ ứng với phần tử $g$ và ánh xạ $\varphi_{g^{-1}}$ ứng với nghịch đảo $g^{-1}$ là nghịch đảo của nhau (điều này cũng giải thích vì sao $\varphi_g$ luôn là song ánh). Có thể kiểm tra $\varphi_{g_1g_2}=\varphi_{g_1}\varphi_{g_2}$, tức $\varphi$ là đồng cấu nhóm từ $G$ đến $S_X$.

Đồng cấu nhóm này được gọi là **biểu diễn hoán vị** (permutation representation) của tác động nhóm; nó ánh xạ nhóm $G$ vào một nhóm hoán vị nào đó.

???+ abstract "Nhóm hoán vị"
    Nếu nhóm $G$ là nhóm con của một nhóm đối xứng nào đó, thì $G$ được gọi là một **nhóm hoán vị** (permutation group).

Hạt nhân của đồng cấu nhóm này cũng được gọi là hạt nhân của tác động nhóm. Nếu hạt nhân của đồng cấu là tầm thường, tức đồng cấu này đơn ánh, tác động nhóm được gọi là **trung thành** (faithful), nghĩa là biểu diễn hoán vị phản ánh trung thành thông tin về cấu trúc nhóm. Khi đó, nhóm $G$ đẳng cấu với nhóm hoán vị thu được từ biểu diễn hoán vị.

???+ info "Ký hiệu"
    Trong phần sau, để trình bày gọn hơn, ta sẽ bỏ ký hiệu $\cdot$ trong tác động nhóm.

### Quỹ đạo

Tác động nhóm là ánh xạ hai ngôi. Nếu cố định phần tử $g$ của nhóm, ta thu được một hoán vị trên tập hợp. Nếu cố định phần tử $x$ của tập hợp, ta thu được tất cả kết quả có thể của tác động của nhóm lên phần tử đó.

???+ abstract "Quỹ đạo"
    Cho tác động của nhóm $G$ lên tập $X$ và $x\in X$. **Quỹ đạo** (orbit) của $x$ dưới tác động của $G$ là tập con $Gx=\{gx:g\in G\}$.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Chẳng hạn, nếu xét tác động của nhóm $\langle s\rangle\le D_6$ lên tập các đỉnh của tam giác đều, quỹ đạo của đỉnh $1$ là $\{1\}$, còn quỹ đạo của đỉnh $2$ và $3$ là $\{2,3\}$. Tuy nhiên, tác động của nhóm $\langle r\rangle\le D_6$ lên tập đỉnh chỉ có một quỹ đạo, là toàn bộ tập đỉnh.

Dễ chứng minh, toàn bộ các quỹ đạo của tập $X$ dưới tác động của $G$ tạo thành một phân hoạch của tập đó, ký hiệu $X/G$. Khác với lớp kề, các quỹ đạo này không nhất thiết có cùng độ dài.

### Bộ ổn định

Dưới tác động nhóm, độ dài quỹ đạo của một phần tử trong tập phụ thuộc vào số phần tử nhóm có hoán vị tương ứng giữ cố định phần tử đó.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Chẳng hạn, lý do quỹ đạo của đỉnh $1$ có độ dài một dưới tác động của nhóm $\langle s\rangle\le D_6$ là mọi phần tử trong nhóm đều đưa đỉnh $1$ về chính nó; còn quỹ đạo của đỉnh $2$ có độ dài hai vì chỉ có phần tử đơn vị $e$ đưa đỉnh $2$ về chính nó.

Điều này dẫn đến định nghĩa sau.

???+ abstract "Bộ ổn định"
    Cho tác động của nhóm $G$ lên tập $X$ và $x\in X$. **Bộ ổn định** (stabilizer) của $x$ trong nhóm $G$ là nhóm con $G_x=\{g\in G:gx=x\}$.

Hạt nhân của tác động nhóm chính là giao của bộ ổn định của tất cả các phần tử trong tập.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Xét tác động của nhóm $D_6$ lên tập các đỉnh. Bộ ổn định của đỉnh $1$ là $\{e,s\}=\langle s\rangle$, một nhóm con của $D_6$. Vì $D_6$ có thể chia thành các lớp kề trái $\langle s\rangle$, $r\langle s\rangle$ và $r^2\langle s\rangle$, dễ thấy mỗi lớp kề trái cho cùng một kết quả khi tác động lên đỉnh $1$.

Ví dụ này cho thấy các phần tử trên quỹ đạo tương ứng một-một với các lớp kề trái của bộ ổn định. Do đó có kết quả sau.

???+ note "Định lý"
    Với tác động của nhóm $G$ lên tập $X$, bộ ổn định $G_x$ của phần tử $x\in X$ là nhóm con của $G$, và tồn tại song ánh giữa các lớp kề trái của $G_x$ với quỹ đạo $Gx$.

??? note "Chứng minh"
    Chỉ cần kiểm tra ánh xạ $gG_x\mapsto gx$ là song ánh xác định tốt.

Dùng định lý Lagrange, ta liên hệ độ dài quỹ đạo với số lớp kề của bộ ổn định. Đây là **định lý quỹ đạo-bộ ổn định** (orbit-stabilizer theorem).

???+ note "Định lý quỹ đạo-bộ ổn định"
    Với tác động của nhóm hữu hạn $G$ lên tập $X$ và $x\in X$, có $|Gx|=[G:G_x]=|G|/|G_x|$.

Có thể kiểm tra kết quả này trong ví dụ trên.

### Bổ đề Burnside

Bổ đề này đưa ra công thức tính số quỹ đạo của tác động nhóm.

???+ note "Bổ đề Burnside"
    Với tác động của nhóm $G$ lên tập $X$, số quỹ đạo bằng số điểm bất động trung bình của hoán vị ứng với mỗi phần tử trong nhóm, tức
    
    $$
    |X/G| = \frac{1}{|G|}\sum_{g\in G}|X^g|.
    $$
    
    Ở đây, $X^g=\{x\in X:gx=x\}$ là tập điểm bất động của hoán vị ứng với phần tử $g\in G$.

??? note "Chứng minh"
    Chứng minh của định lý này rất ngắn gọn. Chú ý rằng số quỹ đạo có thể viết là
    
    $$
    |X/G|=\sum_{o\in X/G}1=\sum_{x\in X}\frac{1}{|Gx|}=\frac1{|G|}\sum_{x\in X}|G_x|.
    $$
    
    Dấu bằng cuối cùng là hệ quả của định lý trên; vế phải chỉ khác công thức cần chứng minh bởi định lý Fubini, vì hai tổng đều đếm tập $\{(g,x)\in G\times X:gx=x\}$, chỉ khác ở chỗ vế phải cộng theo $g$ trước, còn công thức cần chứng minh cộng theo $x$ trước.

Định lý này có nhiều ứng dụng trong tổ hợp, có thể dùng để đếm số đối tượng "khác nhau về bản chất". Có thể xem thêm ví dụ và thảo luận trong [đếm Polya](../combinatorics/polya.md).

### Định lý Cayley

Dùng tác động nhóm để nghiên cứu cấu trúc nhóm đòi hỏi chọn một tập hợp phù hợp. Thực ra, chính nhóm là một tập hợp như vậy. Vì thế, tiếp theo xét hai tác động nhóm thường gặp của nhóm lên chính nó và dùng chúng để phân tích cấu trúc nhóm.

Tác động đầu tiên là **tác động nhân trái** (left multiplication) của nhóm lên chính nó. Biểu diễn hoán vị của nó như sau.

$$
\begin{aligned}
\varphi:G\rightarrow S_G&\\
g\mapsto \varphi_g&: G\rightarrow G\\
&\quad x\mapsto gx
\end{aligned}
$$

Tác động nhân trái của nhóm tất yếu là trung thành, vì nhóm thỏa luật khử. Do đó, theo định lý cơ bản về đồng cấu, $G$ có thể nhúng vào nhóm đối xứng $S_G$. Nghĩa là mọi nhóm đều đẳng cấu với một nhóm hoán vị nào đó[^cayley].

???+ note "Định lý Cayley"
    Nhóm $G$ đẳng cấu với một nhóm con của nhóm đối xứng $S_G$.

Tác động nhóm này chỉ có một quỹ đạo, và bộ ổn định của mỗi phần tử đều là $\{e\}$.

### Tác động liên hợp

Tác động thứ hai của nhóm lên chính nó được gọi là **tác động liên hợp** (conjugation). Biểu diễn hoán vị của nó như sau.

$$
\begin{aligned}
\varphi:G\rightarrow S_G&\\
g\mapsto \varphi_g&: G\rightarrow G\\
&\quad x\mapsto gxg^{-1}
\end{aligned}
$$

Dưới tác động liên hợp của nhóm, quỹ đạo và bộ ổn định có tên riêng.

???+ abstract "Lớp liên hợp"
    Cho nhóm $G$ và $g\in G$. **Lớp liên hợp** (conjugacy class) của phần tử $g$ trong $G$ là quỹ đạo của $g$ dưới tác động liên hợp. Nếu hai phần tử $g$ và $h$ nằm trong cùng một lớp liên hợp, ta nói $g$ và $h$ **liên hợp** (conjugate).

???+ abstract "Bộ trung tâm hóa"
    Cho nhóm $G$ và $a\in G$. **Bộ trung tâm hóa** (centralizer) của phần tử $a$ trong $G$ là $C_G(a)=\{g\in G:ga=ag\}$.

???+ abstract "Tâm"
    **Tâm** (center) của nhóm $G$ là $Z(G)=\cap_{a\in G}C_G(a)=\{g\in G:\forall a\in G(ga=ag)\}$.

Tâm của nhóm là tập các phần tử giao hoán với mọi phần tử trong nhóm; vì nó là hạt nhân của tác động nhóm, nó tất yếu là nhóm con chuẩn tắc. Kích thước của tâm cho biết nhóm cách nhóm giao hoán bao xa. Bộ trung tâm hóa của một phần tử là tập tất cả các phần tử giao hoán với phần tử đó; nó cũng là nhóm con lớn nhất trong các nhóm con có tâm chứa phần tử đó, do đó có tên như vậy. Đồng thời, vì nó là bộ ổn định của một phần tử dưới tác động liên hợp, nó là nhóm con. Lớp liên hợp nói chung không phải nhóm con.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Quay lại nhóm $D_6$, tâm của nó là $\{e\}\neq G$, cho thấy nó không phải nhóm giao hoán. Bộ trung tâm hóa $C_G(r)$ của phần tử $r$ là $\langle r\rangle$, còn bộ trung tâm hóa $C_G(s)$ của phần tử $s$ là $\langle s\rangle$. Tổng quát, với mọi $g\in G$, luôn có $\langle g\rangle\le C_G(g)$. Nhóm $D_6$ có ba lớp liên hợp: $\{e\},\{r,r^2\},\{s,sr,sr^2\}$. Dễ thấy các phần tử liên hợp có cùng cấp[^conjugate].

Nhóm dưới tác động liên hợp được chia thành nhiều lớp liên hợp. Vì thế, ta có thể viết **phương trình lớp** (class equation).

???+ note "Phương trình lớp"
    Cho nhóm $G$. Gọi $\{\mathcal K_i\}_{i=1}^r$ là toàn bộ các lớp liên hợp có độ dài lớn hơn một, và $g_i$ là đại diện của $\mathcal K_i$. Khi đó
    
    $$
    |G|=|Z(G)|+\sum_{i=1}^r[G:C_G(g_i)].
    $$

Nó có thể dùng để phân tích cấu trúc nhóm, chẳng hạn để chứng minh [định lý Sylow](#dinh-ly-sylow) bên dưới.

### Bộ chuẩn hóa và bộ trung tâm hóa

Thực ra, tập lũy thừa của nhóm cũng có thể làm đối tượng cho tác động nhóm. Ở đây ta tập trung xét tác động liên hợp của nhóm lên toàn bộ các tập con $X=\mathcal P(G)$ của nó. Biểu diễn hoán vị của tác động này như sau.

$$
\begin{aligned}
\varphi:G\rightarrow S_X&\\
g\mapsto \varphi_g&: X\rightarrow X\\
&\quad S\mapsto gSg^{-1} = \{gsg^{-1}:s\in S\}
\end{aligned}
$$

Dưới tác động liên hợp này, ta cũng có thể định nghĩa lớp liên hợp của một tập con của nhóm. Hạt nhân của nó vẫn là tâm của nhóm. Bộ ổn định của nó được gọi là bộ chuẩn hóa.

???+ abstract "Bộ chuẩn hóa"
    Cho nhóm $G$ và tập con $S\subseteq G$. **Bộ chuẩn hóa** (normalizer) của tập con $S$ trong $G$ là $N_G(S)=\{g\in G:gSg^{-1}=S\}$.

Bộ chuẩn hóa là bộ ổn định của $S$ dưới tác động liên hợp, nên tất yếu là nhóm con của $G$. Bộ chuẩn hóa của $S$ là nhóm con lớn nhất trong các nhóm con mà trong đó $S$ nằm trong một nhóm con chuẩn tắc; đây cũng là nguồn gốc của tên gọi bộ chuẩn hóa. Đặc biệt, với tập một phần tử $\{a\}$, $N_G(\{a\})=C_G(a)$.

Bộ trung tâm hóa cũng có thể mở rộng tương tự cho tập con.

???+ abstract "Bộ trung tâm hóa"
    Cho nhóm $G$ và tập con $S\subseteq G$. **Bộ trung tâm hóa** (centralizer) của tập con $S$ trong $G$ là $C_G(S)=\{g\in G:\forall s\in S(gsg^{-1}=s)\}$.

Bộ trung tâm hóa thực ra là hạt nhân của tác động liên hợp của nhóm $N_G(S)$ lên $S$. Do đó tất yếu $C_G(S)\trianglelefteq N_G(S)\le G$; theo tính chất bắc cầu của nhóm con, bộ trung tâm hóa cũng là nhóm con. Đặc biệt, tâm của nhóm $Z(G)=C_G(G)\trianglelefteq N_G(G)=G$ tất yếu là nhóm con chuẩn tắc.

### Định lý Sylow

Phân tích sâu hơn tác động liên hợp của nhóm hữu hạn, ta thu được định lý Sylow. Đây là công cụ mạnh để xử lý cấu trúc nhóm hữu hạn, và có thể nhanh chóng suy ra cấu trúc của nhiều nhóm cấp nhỏ.

???+ abstract "Nhóm $p$"
    Cho nhóm $G$. Nếu tồn tại số nguyên tố $p$ và số nguyên dương $\alpha$ sao cho $|G|=p^\alpha$, thì $G$ được gọi là **nhóm $p$** ($p$-group).

??? info "Về định nghĩa nhóm $p$"
    Nhóm $p$ còn có một định nghĩa khác: nhóm mà cấp của mọi phần tử đều là lũy thừa của một số nguyên tố. Hai định nghĩa này tương đương với nhóm hữu hạn; nhưng định nghĩa thứ hai cũng dùng được cho nhóm vô hạn. Ngoài ra, về định nghĩa nhóm $p$, các tài liệu khác nhau có thể khác nhau ở việc có tính $\{e\}$ là nhóm $p$ hay không; độc giả cần phân biệt khi đọc.

???+ abstract "Nhóm con $p$"
    Cho nhóm $G$ và nhóm con $P\le G$. Nếu bản thân $P$ là một nhóm $p$, thì $P$ được gọi là **nhóm con $p$** ($p$-subgroup).

???+ note "Định lý Cauchy"
    Nếu số nguyên tố $p$ chia hết cấp của nhóm $G$, thì tất yếu tồn tại phần tử cấp $p$.

Định lý Cauchy đảm bảo sự tồn tại của nhóm con $p$. Thực ra, thông qua phân tích tinh vi hơn, có thể thu được kết luận mạnh hơn: sự tồn tại của nhóm con Sylow $p$.

???+ abstract "Nhóm con Sylow $p$"
    Cho nhóm $G$ và nhóm con $P\le G$. Nếu $|G|=p^\alpha m$, $p\perp m$ và $|P|=p^\alpha$, thì $P$ được gọi là **nhóm con Sylow $p$** (Sylow $p$-subgroup).

Nói cách khác, nhóm con Sylow $p$ là nhóm con $p$ cực đại. Định lý Sylow khẳng định sự tồn tại của nhóm con Sylow $p$, cung cấp một dạng đảo ngược phần nào của định lý Lagrange.

???+ note "Định lý Sylow"
    Giả sử cấp $|G|$ của nhóm hữu hạn $G$ có thể viết dưới dạng $p^\alpha m$, trong đó $p$ là số nguyên tố và $p$ không chia $m$. Khi đó:
    
    1.  Tồn tại nhóm con Sylow $p$;
    2.  Với một nhóm con Sylow $p$ là $P$ và một nhóm con $p$ là $Q$ của $G$, tồn tại $g\in G$ sao cho $Q\le gPg^{-1}$; đặc biệt, mọi nhóm con Sylow $p$ đều liên hợp với nhau;
    3.  Số nhóm con Sylow $p$ trong $G$, ký hiệu $n_p$, thỏa $n_p\equiv 1\pmod p$, $n_p\mid m$ và $n_p=[G:N_G(P)]$, trong đó $P$ là một nhóm con Sylow $p$ bất kỳ.

??? note "Chứng minh"
    Để chứng minh phần thứ nhất, quy nạp theo $|G|$. Xét phương trình lớp
    
    $$
    |G|=|Z(G)|+\sum_{i=1}^r[G:C_G(g_i)].
    $$
    
    Nếu $p\mid|Z(G)|$, có thể chọn tùy ý một nhóm con $N\le Z(G)$ cấp $p$ của tâm; khi đó $N\trianglelefteq Z(G)\trianglelefteq G$, nên $G/N$ là nhóm nhỏ hơn. Theo giả thuyết quy nạp, nó có nhóm con Sylow $p$ là $P/N$; nghịch ảnh $P$ tương ứng qua đồng cấu tự nhiên chính là nhóm con Sylow $p$ của nhóm ban đầu $G$. Do đó chỉ cần xét trường hợp $p$ không chia $|Z(G)|$. Khi đó có thể chọn $g_i\in G$ sao cho $p$ không chia $[G:C_G(g_i)]$, nên toàn bộ lũy thừa của $p$ trong $|G|$ đều xuất hiện trong $|C_G(g_i)|$. Lại theo giả thuyết quy nạp, $|C_G(g_i)|$ có nhóm con Sylow $p$ là $P$, và nó chính là nhóm con Sylow $p$ của nhóm ban đầu $G$.
    
    Để chứng minh phần thứ hai và thứ ba, gọi lớp liên hợp của một nhóm con Sylow $p$ là $P$ của $G$ là $\mathcal S=\{gPg^{-1}:g\in G\}$, và xét kết quả khi hạn chế tác động liên hợp của $G$ trên $\mathcal S$ vào một nhóm con $p$ nào đó $Q$. Tập $\mathcal S$ được chia thành một số quỹ đạo dưới tác động này. Giả sử có tổng cộng $r$ quỹ đạo, với đại diện mỗi quỹ đạo là $P_i$, khi đó có đẳng thức
    
    $$
    |\mathcal S|=\sum_{i=1}^r[Q:Q\cap N_G(P_i)].
    $$
    
    Ở đây, $Q\cap N_G(P_i)$ là bộ ổn định của $P_i$ dưới tác động nhóm nói trên. Đặt $H=Q\cap N_G(P_i)$. Rõ ràng $H\le N_G(P_i)$, nên theo định lý đẳng cấu thứ hai của nhóm, $P_iH/P_i\cong H/(P_i\cap H)$. Do đó $|P_iH|=|P_i||H|/|P_i\cap H|$; vế phải là một lũy thừa của $p$, nên vế trái cũng phải là lũy thừa của $p$, và cần có $|P_i|\le |P_iH|$. Nhưng $P_i$ đã là nhóm con có lũy thừa của $p$ lớn nhất trong các nhóm con của $G$, nên $P_i=P_iH$. Thế vào quan hệ đẳng cấu trên, ta có $H=P_i\cap H=Q\cap P_i$. Ở đây dùng quan hệ hiển nhiên $P_i\le N_G(P_i)$. Như vậy bộ ổn định $Q\cap N_G(P_i)$ thực ra là $Q\cap P_i$. Vì thế công thức trên có thể viết thành
    
    $$
    |\mathcal S|=\sum_{i=1}^r[Q:Q\cap P_i].
    $$
    
    Đẳng thức này đúng với mọi nhóm con $p$ là $Q$.
    
    Đặc biệt, nhóm con Sylow $p$ là $P$ cũng là một nhóm con $p$. Thế $Q=P$ vào đẳng thức trên, vế phải có đúng một hạng bằng $1$, các hạng còn lại đều là bội của $p$. Vì vậy, kích thước $|\mathcal S|$ của lớp liên hợp của nhóm con Sylow $p$ là $P$ tất yếu dư $1$ modulo $p$. Đồng thời, vì công thức này đúng với mọi nhóm con $p$ là $Q$, tự nhiên tồn tại $g\in G$ sao cho $Q\le gPg^{-1}$; nếu không, với mọi $P_i$ trong đẳng thức trên đều có $|Q\cap P_i|<|Q|$, mâu thuẫn với $|\mathcal S|\equiv 1\pmod p$. Nếu lúc này cho $Q$ là một nhóm con Sylow $p$ khác $P$, tất yếu $Q=gPg^{-1}$ với một $g\in G$, tức mọi nhóm con Sylow $p$ đều liên hợp. Do đó, số nhóm con Sylow $p$, $n_p$, chính là $|\mathcal S|$, nên $n_p\equiv 1\pmod p$. Cuối cùng, vì $n_p=|\mathcal S|=[G:N_G(P)]$ và $P\le N_G(P)$, suy ra $n_p\mid m$. Như vậy chứng minh đầy đủ phần thứ hai và thứ ba.

??? example "Ứng dụng: theo nghĩa đẳng cấu, nhóm cấp sáu chỉ có $C_6$ và $S_3$"
    Giả sử $G$ có cấp $6$. Theo định lý Sylow, nó có nhóm con Sylow $2$, và số nhóm con đó thỏa $n_2\equiv 1\pmod 2$ và $n_2\mid 3$, nên chỉ có hai trường hợp: $n_2=1$ hoặc $n_2=3$. Tương tự, có thể chứng minh $G$ có đúng một nhóm con Sylow $3$, tức $n_3=1$.
    
    Với trường hợp $n_2=1$, trong nhóm $G$ có một nhóm con Sylow $2$, nên có một phần tử cấp $2$; lại có một nhóm con Sylow $3$, nên có hai phần tử cấp $3$. Nhóm $G$ còn có một phần tử đơn vị; các phần tử còn lại, theo định lý Lagrange, phải có cấp là ước của $6$. Chúng không thể là phần tử mới cấp $2$ hoặc cấp $3$, nếu không sẽ tạo ra nhóm con Sylow $p$ mới khác với trên. Vì vậy các phần tử còn lại chỉ có thể là phần tử cấp $6$. Tồn tại phần tử có cấp bằng cấp của nhóm, nên $G$ là nhóm vòng, do đó $G\cong C_6$.
    
    Với trường hợp $n_2=3$, nhóm $G$ có ba nhóm con Sylow $2$ liên hợp. Xét tác động liên hợp của $G$ lên ba nhóm con Sylow $2$ này. Với bất kỳ nhóm con Sylow $2$ nào $P$, theo định lý Sylow có $|N_G(P)|=2$; nhưng lại có $P\le N_G(P)$, nên $P=N_G(P)$. Do đó, giao của các bộ chuẩn hóa của ba nhóm con Sylow $2$ này, tức hạt nhân của tác động liên hợp này, là tầm thường. Vì vậy tác động này trung thành, nhúng $G$ vào nhóm hoán vị trên ba nhóm con Sylow $2$, tức $S_3$. Nhưng vì $|G|=|S_3|$, tất yếu $G\cong S_3$.

## Nhóm Abel hữu hạn sinh

Sau khi nắm các công cụ cơ bản để phân tích cấu trúc nhóm, ta tập trung vào cấu trúc của một lớp nhóm.

Như đã nói trong tổng quan, nhóm Abel có cấu trúc đơn giản hơn các nhóm khác vì các phần tử giao hoán. Đặc biệt đơn giản là các nhóm Abel có thể được sinh bởi hữu hạn phần tử.

???+ abstract "Hữu hạn sinh"
    Nếu nhóm $G$ có một tập sinh hữu hạn, thì $G$ được gọi là **hữu hạn sinh** (finitely generated).

Định lý phân loại trong mục này nói rằng nhóm Abel hữu hạn sinh có thể xem như một tổ hợp đơn giản của hữu hạn nhóm vòng. Các nhóm xuất hiện trong lập trình thi đấu phần lớn là nhóm hữu hạn. Nhóm Abel hữu hạn tất yếu hữu hạn sinh, nên kết quả này luôn áp dụng được.

### Tích trực tiếp

Phần trên chủ yếu phân tích cách phân ra một nhóm thành các nhóm nhỏ hơn; ngược lại, tự nhiên có thể hỏi cách ghép hai nhóm thành một nhóm lớn hơn. Trong mọi cách ghép có thể, tích trực tiếp của nhóm là cách đơn giản nhất.

Ý tưởng cơ bản của tích trực tiếp là: cho hai nhóm $G$ và $H$, xét tích Descartes $G\times H$; phép toán trên cặp $(g,h)$ được định nghĩa bằng cách thực hiện phép toán riêng trên từng thành phần, hai thành phần không ảnh hưởng lẫn nhau. Kết quả thu được rõ ràng là một nhóm lớn hơn, và hai nhóm ban đầu nhúng vào nhóm mới một cách tầm thường.

???+ abstract "Tích trực tiếp"
    **Tích trực tiếp** (direct product) của nhóm $(G,\cdot_G)$ và nhóm $(H,\cdot_H)$ là nhóm $(G\times H,\cdot)$, trong đó phép toán hai ngôi $\cdot:(G\times H)\times(G\times H)\rightarrow G\times H$ được định nghĩa bởi $(g_1,h_1)\cdot(g_2,h_2)=(g_1\cdot_G g_2,h_1\cdot_H h_2)$. Tích trực tiếp của $G$ và $H$ ký hiệu là $G\times H$.

Với tích trực tiếp $G\times H$, hiển nhiên có các phép nhúng $g\mapsto(g,e_H)$ và $h\mapsto(e_G,h)$. Ngược lại, ánh xạ $(g,h)\mapsto g$ và ánh xạ $(g,h)\mapsto h$ là các đồng cấu nhóm, có hạt nhân lần lượt là $\{e_G\}\times H$ và $G\times\{e_H\}$. Hai hạt nhân này chính là ảnh của hai phép nhúng nói trên, và giao của chúng là tầm thường, tức $\{(e_G,e_H)\}$. Vì vậy trong tích trực tiếp $G\times H$ có hai nhóm con, đều chuẩn tắc, giao nhau tầm thường, và tích của chúng là chính $G\times H$.

Phân tích này thực ra cho một điều kiện cần và đủ để một nhóm viết được thành tích trực tiếp của hai nhóm con của nó.

???+ note "Định lý"
    Cho nhóm $G$ và các nhóm con $H_1,H_2\le G$. Có $G\cong H_1\times H_2$ khi và chỉ khi $H_1,H_2\trianglelefteq G$, $H_1\cap H_2=\{e\}$ và $G=H_1H_2$.

??? note "Chứng minh"
    Tính cần thiết của các điều kiện đã được thảo luận trong phần chính; ở đây chứng minh tính đủ. Xét ánh xạ $\varphi:G\rightarrow H_1\times H_2$ thỏa $h_1h_2\mapsto(h_1,h_2)$. Ánh xạ $\varphi$ xác định tốt, vì với mọi $h_1,k_1\in H_1$ và $h_2,k_2\in H_2$, nếu $h_1h_2=k_1k_2$ thì $h_1=k_1$ và $h_2=k_2$; lý do là $k_1^{-1}h_1=k_2h_2^{-1}\in H_1\cap H_2=\{e\}$. Để chỉ ra $\varphi$ là đồng cấu nhóm, cần chỉ ra $(h_1h_2)(k_1k_2)=h_1k_1h_2k_2$, tương đương với $k_1$ và $h_2$ giao hoán, tức $k_1h_2k_1^{-1}h_2^{-1}=e$. Để chứng minh quan hệ này, chỉ cần chú ý $k_1h_2k_1^{-1}h_2^{-1}=(k_1h_2k_1^{-1})h_2^{-1}\in (k_1H_2k_1^{-1})H_2=H_2$; tương tự cũng có $k_1(h_2k_1^{-1}h_2^{-1})\in H_1$, nên $k_1h_2k_1^{-1}h_2^{-1}\in H_1\cap H_2=\{e\}$. Như vậy $\varphi$ là đồng cấu nhóm. Nó rõ ràng là song ánh, nên là đẳng cấu, tức $G\cong H_1\times H_2$.

Trong tích trực tiếp, các phần tử của hai nhân tử tích trực tiếp tất yếu giao hoán với nhau, vì $hg=(e_G,h)(g,e_H)=(g,h)=gh$. Do đó, nếu hai nhân tử trực tiếp đều là nhóm Abel, tích trực tiếp cũng là nhóm Abel.

Không phải mọi nhóm đều viết được thành tích trực tiếp của hai nhóm con không tầm thường.

???+ example "Ví dụ: nhóm đối xứng $D_6$ của tam giác đều (tiếp)"
    Chẳng hạn, nhóm $D_6=\langle r,s\rangle$ không đẳng cấu với $\langle r\rangle\times\langle s\rangle$, vì nhóm sau là tích trực tiếp của hai nhóm vòng, nên tất yếu là nhóm Abel.

Định lý phân loại bên dưới nói rằng mọi nhóm Abel hữu hạn sinh đều có thể viết thành tích trực tiếp của hữu hạn nhóm vòng.

### Định lý phân loại

Với nhóm Abel hữu hạn sinh, có định lý phân loại sau. Nó được gọi là **định lý cơ bản về nhóm Abel hữu hạn sinh** (fundamental theorem of finitely generated Abelian groups).

???+ note "Định lý cơ bản về nhóm Abel hữu hạn sinh"
    Với nhóm Abel hữu hạn sinh $G$, tồn tại các số nguyên $r\ge0$ và $n_1,\cdots,n_s\ge 2$ sao cho
    
    $$
    G\cong C_\infty^r\times C_{n_1}\times\cdots\times C_{n_s}.
    $$
    
    Đặc biệt, $r$ được xác định duy nhất và gọi là **hạng** (rank) của nhóm $G$; hơn nữa:
    
    -   Có thể chọn các số nguyên $n_1,\cdots,n_s$ sao cho $n_1\ge2,\ n_1|n_2,\ \cdots,\ n_{s-1}|n_s$. Khi đó các số nguyên $n_1,\cdots,n_s$ được xác định duy nhất, và các nhân tử $C_{n_i}$ được gọi là **nhân tử bất biến** (invariant factor) của nhóm $G$;
    -   Cũng có thể chọn các số nguyên $n_1,\cdots,n_s$ đều có dạng lũy thừa của số nguyên tố. Khi đó các lũy thừa nguyên tố này cũng được xác định duy nhất, và các nhân tử $C_{n_i}$ được gọi là **ước số sơ cấp** (elementary divisor) của nhóm $G$.

Trước hết, định lý khẳng định mọi nhóm Abel hữu hạn sinh đều là tích trực tiếp của hữu hạn nhóm vòng.

??? note "Chứng minh"
    Ở đây đưa ra một chứng minh có hình thức đơn giản[^proof-abelian]; chứng minh sâu sắc hơn nên tham khảo định lý cấu trúc của môđun hữu hạn sinh trên miền lý tưởng chính[^module-pid]. Trong chứng minh, để viết gọn, ta dùng ký hiệu cộng thay cho ký hiệu nhân trong nhóm tổng quát; khi đó $0$ biểu diễn phần tử đơn vị, và ký hiệu $mx$ biểu diễn lũy thừa bậc $m$ của $x$.
    
    Giả sử $G$ có thể được sinh bởi ít nhất $k$ phần tử. Chứng minh định lý bằng quy nạp theo $k$. Khi $k=1$ kết luận là hiển nhiên. Khi $k>1$, trong tất cả các bộ sinh $\langle x_1,x_2,\cdots,x_k\rangle$ của $G$, chọn bộ sao cho $x_1$ có cấp nhỏ nhất. Ta sẽ chứng minh $G=\langle x_1\rangle\times\langle x_2,\cdots,x_k\rangle$; theo giả thuyết quy nạp, nhóm sau đã phân tích được thành tích trực tiếp của $(k-1)$ nhóm vòng, nên bước quy nạp được chứng minh.
    
    Theo đặc trưng của tích trực tiếp của nhóm, nếu phân tích tích trực tiếp không đúng, tất yếu tồn tại quan hệ $m_1x_1+m_2x_2+\cdots+m_kx_k=0$ với $m_1x_1\neq 0$. Với các hệ số âm $m_i$, có thể thay $x_i$ bằng nghịch đảo $-x_i$, nên mọi hệ số $m_i$ có thể lấy là số nguyên không âm. Hơn nữa, có thể lấy $0< m_1 <|x_1|$. Nếu đặt $d=\gcd(m_1,m_2,\cdots,m_k)$ và $c_i=m_i/d$, thì $y_1=c_1x_1+c_2x_2+\cdots+c_kx_k$ thỏa $dy_1=0$, nên $|y_1|\le d\le m_1< |x_1|$; tức $y_1$ là phần tử có cấp nhỏ hơn $x_1$.
    
    Bây giờ chứng minh $y_1$ có thể mở rộng thành một bộ sinh của $G$. Nói cách khác, tồn tại các phần tử $y_2,\cdots,y_k\in G$ sao cho $G=\langle y_1,y_2,\cdots,y_k\rangle$. Điều kiện duy nhất đã biết là $y_1$ có thể viết thành $c_1x_1+c_2x_2+\cdots+c_kx_k$, trong đó các hệ số $c_i$ là số tự nhiên và ước chung lớn nhất của chúng là một. Không mất tính tổng quát, giả sử các hệ số sắp theo thứ tự không tăng. Khi đó $y_1$ cũng có thể viết là $(c_1-c_2)x_1+c_2(x_1+x_2)+\cdots+c_kx_k$. So với điều kiện trước, ta thấy các hệ số vẫn toàn là số tự nhiên, ước chung lớn nhất vẫn là một, và $G=\langle x_1,x_1+x_2,x_3,\cdots,x_k\rangle$, nhưng tổng tất cả các hệ số giảm đi $c_2$. Nếu $c_2=0$, tất yếu $c_1=1$ và kết luận hiển nhiên; nếu không, tổng hệ số giảm nghiêm ngặt. Vì thế, quy nạp theo tổng hệ số cho thấy mọi $y_1$ thỏa điều kiện trên đều có thể mở rộng thành một bộ sinh của $G$.
    
    Khi đó ta tìm được một phần tử sinh $y_1$ có cấp nhỏ hơn $x_1$, mâu thuẫn với cách chọn $x_1$. Do đó phân tích tích trực tiếp tất yếu đúng; theo nguyên lý quy nạp, kết quả cần chứng minh đúng.

Tất nhiên, nhóm vòng có thể có cấp vô hạn hoặc cấp hữu hạn; chúng lần lượt là phần $C_\infty$ và phần $C_{n_i}$ trong phân tích trên. Sau đó, định lý mô tả cấu trúc của nhóm vòng hữu hạn $C_n$. Phần phân tích thành ước số sơ cấp trong định lý thực ra dựa vào quan sát sau.

???+ note "Bổ đề"
    Nếu $m$ và $n$ nguyên tố cùng nhau, thì $C_{mn}\cong C_m\times C_n$.

??? note "Chứng minh"
    Gọi $x$ và $y$ lần lượt là các phần tử sinh của $C_m$ và $C_n$. Vì $(m,n)=1$, ta có $|(x,y)|=mn=|C_m\times C_n|$. Do đó $(x,y)$ là phần tử sinh của $C_m\times C_n$, tức $C_m\times C_n=\langle(x,y)\rangle$. Nhóm này là nhóm vòng cấp $mn$, nên tất yếu đẳng cấu với $C_{mn}$.

Cho nhóm vòng $C_{n}$. Nếu theo định lý cơ bản của số học có $n=p_1^{r_1}\cdots p_k^{r_k}$, thì lặp lại bổ đề trên sẽ chứng minh được $C_n=C_{p_1^{r_1}}\times\cdots\times C_{p_k^{r_k}}$. Sau hai bước phân tích này, thực chất ta đã thu được phân tích thành ước số sơ cấp trong định lý. Sau đó, lại dùng bổ đề để ghép lại các nhóm vòng có cấp là lũy thừa số nguyên tố sao cho cấp của chúng thỏa yêu cầu, sẽ thu được phân tích thành nhân tử bất biến trong định lý. Tính duy nhất trong định lý có thể chứng minh bằng quy nạp.

??? example "Ví dụ: phân loại các nhóm Abel cấp 24"
    Làm ví dụ, từ định lý có thể biết tất cả các nhóm Abel cấp 24 có tổng cộng ba loại, liệt kê như sau.
    
    |      Phân tích nhân tử bất biến     |             Phân tích ước số sơ cấp            |
    | :---------------------------------: | :---------------------------------------------: |
    |              $C_{24}$               |              $C_{3}\times C_{8}$               |
    |        $C_{2}\times C_{12}$         |          $C_2\times C_{3}\times C_4$           |
    | $C_2\times C_2\times C_6$           | $C_2\times C_2\times C_2\times C_3$            |

## Tài liệu tham khảo và ghi chú

-   Dummitt, D.S. and Foote, R.M. (2004) Abstract Algebra. 3rd Edition, John Wiley & Sons, Inc.
-   [Milne, J.S. (2021) Group Theory](https://www.jmilne.org/math/CourseNotes/GT.pdf).
-   [Group (mathematics) - Wikipedia](https://en.wikipedia.org/wiki/Group_%28mathematics%29)
-   [Group theory - Wikipedia](https://en.wikipedia.org/wiki/Group_theory)
-   [Group - Wolfram MathWorld](https://mathworld.wolfram.com/Group.html)
-   [Visual Group Theory](https://www.youtube.com/playlist?list=PLwV-9DG53NDxU337smpTwm6sef4x-SCLv)

[^klein]: Nhóm này có thể biểu diễn thành nhóm hoán vị $\{(1),(12)(34),(13)(24),(14)(23)\}$, hoặc viết thành $C_2\times C_2$.

[^quotient]: Với nhóm con tổng quát $H\le G$, cũng có thể thử định nghĩa phép toán tương tự trên toàn bộ các lớp kề trái (hoặc phải). Nhưng phép toán như vậy xác định tốt khi và chỉ khi $H$ là nhóm con chuẩn tắc của $G$.

[^group-action]: Chẳng hạn [Group action - Wikipedia](https://en.wikipedia.org/wiki/Group_action).

[^cayley]: Bản thân định lý Cayley không phản ánh nhiều thông tin về cấu trúc nội tại của nhóm, vì nhóm $S_G$ thường có kích thước rất lớn, và khó nói một nhóm con nào đó của nó có kích thước đúng bằng $|G|$ sẽ có tính chất xác định nào. Tuy nhiên, sự phát triển thời kỳ đầu của lý thuyết nhóm chủ yếu tập trung vào nhóm hoán vị. Vì vậy, định lý Cayley thực ra nói rằng mọi cấu trúc nhóm có thể đều nằm trong những đối tượng đã được nghiên cứu kỹ này, dù khi nghiên cứu thực tế ta cần công cụ tinh vi hơn.

[^conjugate]: Tổng quát hơn, các phần tử liên hợp trong nhóm hoán vị tất yếu có cùng [kiểu](../permutation.md#%E7%BD%AE%E6%8D%A2%E7%9A%84%E5%9E%8B).

[^proof-abelian]: Xem Milne, J.S. (2021) Group Theory, trang 25.

[^module-pid]: Xem [Structure theorem for finitely generated modules over a principal ideal domain - Wikipedia](https://en.wikipedia.org/wiki/Structure_theorem_for_finitely_generated_modules_over_a_principal_ideal_domain).
