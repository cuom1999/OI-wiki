Kiến thức chuẩn bị: [các khái niệm cơ bản của đại số trừu tượng](./basic.md), [lý thuyết nhóm](./group-theory.md)

<span id="&#24341;&#20837;"></span>
## Dẫn nhập

**Lý thuyết vành** (ring theory) nghiên cứu các loại vành và cấu trúc của chúng.

Nội dung lý thuyết vành trong bài này gắn chặt với lý thuyết chia hết trong số học. Trước hết, tương tự nhóm con chuẩn tắc trong lý thuyết nhóm, bài này giới thiệu hạt nhân của đồng cấu vành; đó chính là iđêan của vành. Có thể xem iđêan là sự khái quát của khái niệm bội số trong số học lên một vành tổng quát. Sau đó, khi khái quát các khái niệm như số nguyên tố, thuật toán Euclid và phân tích thừa số nguyên tố từ vành số nguyên sang các vành tổng quát, ta thu được nhiều loại miền nguyên khác nhau.

Nhiều kết luận trong số học vẫn đúng trên các vành thường gặp khác. Có thể nói, một phần nhiệm vụ của lý thuyết vành là xác định liệu các kết luận số học ấy còn đúng trên vành tổng quát hay không; nếu không, cần bổ sung điều kiện nào lên vành để chúng đúng.

???+ info "Ký hiệu"
    Khi không gây nhầm lẫn, bài này có thể lược bỏ ký hiệu nhân của vành và viết vành $(R,+,\cdot)$ đơn giản là vành $R$. Trong vành $R$, đơn vị cộng cũng được gọi là phần tử không, ký hiệu là $0$; đơn vị nhân cũng được gọi là phần tử đơn vị, ký hiệu là $1$.

??? warning "Định nghĩa vành trong bài này không yêu cầu có đơn vị"
    Lưu ý rằng định nghĩa vành trong bài này không yêu cầu vành phải có đơn vị. Một số tài liệu yêu cầu vành phải có đơn vị; khi đó, phát biểu của một số kết luận trong bài này cần điều chỉnh đôi chút. Chẳng hạn, trong bài này iđêan có thể được định nghĩa dựa trên vành con, còn trong các tài liệu khác có thể phải định nghĩa dựa trên nhóm con cộng.

<span id="&#29702;&#24819;"></span>
## Iđêan

Tương tự trường hợp của nhóm, ta có thể xây dựng các khái niệm vành con và đồng cấu vành.

???+ abstract "Vành con"
    Với vành $(R,+,\cdot)$ và một tập con $S$ của nó, nếu $(S,+,\cdot)$ cũng là một vành, thì $S$ được gọi là **vành con** (subring) của $R$.

???+ example "Ví dụ: vành số nguyên $\mathbf Z$"
    Với mọi số nguyên $n$, ta có $n\mathbf Z=\{nk:k\in\mathbf Z\}$ là một vành con của $\mathbf Z$.

???+ abstract "Đồng cấu vành"
    Với hai vành $(R,+,\cdot)$ và $(S,\oplus,\odot)$, nếu ánh xạ $\pi$ bảo toàn phép cộng và phép nhân của vành, tức là với mọi $r_1,r_2\in R$ đều có $\pi(r_1+r_2)=\pi(r_1)\oplus\pi(r_2)$ và $\pi(r_1\cdot r_2)=\pi(r_1)\odot\pi(r_2)$, thì $\pi:R\rightarrow S$ được gọi là một **đồng cấu** (homomorphism) từ vành $R$ đến vành $S$.

??? info "Trường hợp định nghĩa vành yêu cầu có đơn vị"
    Nếu định nghĩa vành yêu cầu có phần tử đơn vị, thì định nghĩa đồng cấu vành cũng thường yêu cầu ánh xạ phần tử đơn vị đến phần tử đơn vị. Đối với đồng cấu giữa các vành có đơn vị khác không, điều kiện bổ sung này nhằm tránh trường hợp đồng cấu ánh xạ toàn bộ vành có đơn vị về phần tử không.

???+ example "Ví dụ: vành số nguyên $\mathbf Z$ (tiếp)"
    Với mọi số nguyên khác không $n$, ánh xạ lấy phần dư modulo $n$, tức $\pi:\mathbf Z\rightarrow\mathbf Z/n\mathbf Z$ với $\pi(a)=\bar a$, đều là đồng cấu vành.

Phần [thảo luận](./group-theory.md#%E7%BE%A4%E5%90%8C%E6%80%81) về hạt nhân và ảnh của đồng cấu nhóm gần như có thể chuyển nguyên vẹn sang đây. Ảnh của đồng cấu quyết định đồng cấu có toàn ánh hay không, còn việc hạt nhân có tầm thường hay không quyết định đồng cấu có đơn ánh hay không. Hạt nhân của đồng cấu vành được định nghĩa như sau:

???+ abstract "Hạt nhân của đồng cấu"
    **Hạt nhân** (kernel) của đồng cấu $\pi:R\rightarrow S$ từ vành $R$ đến vành $S$ là $\{r\in R:\pi(r)=0\}$, ký hiệu là $\ker\pi$, trong đó $0$ là đơn vị cộng của $S$.

Rõ ràng, hạt nhân và ảnh của đồng cấu vành đều là vành con. Ngược lại, không phải mọi vành con đều có thể trở thành hạt nhân của một đồng cấu vành nào đó. Những vành con có thể xuất hiện dưới dạng hạt nhân của đồng cấu vành được gọi là iđêan của vành.

???+ abstract "Iđêan"
    Với vành $R$ và vành con $I$ của nó, ta gọi $I$ là
    
    -   **iđêan trái** (left ideal), nếu với mọi $r\in R$ đều có $rI\subseteq I$, trong đó $rI=\{ra:a\in I\}$;
    -   **iđêan phải** (right ideal), nếu với mọi $r\in R$ đều có $Ir\subseteq I$, trong đó $Ir=\{ar:a\in I\}$;
    -   **iđêan** (ideal), nếu $I$ vừa là iđêan trái vừa là iđêan phải của $R$.

Ở đây ta yêu cầu iđêan $I$ đóng dưới phép nhân trái và phép nhân phải bởi các phần tử của vành $R$. Điều kiện này rất tự nhiên. Các phần tử trong iđêan sẽ được ánh xạ về phần tử không dưới một đồng cấu vành, mà phần tử không nhân trái hay nhân phải với bất kỳ phần tử nào cũng vẫn là phần tử không; đó chính là tính đóng cần có. Ngoài ra, cấu trúc cộng của vành là nhóm Abel nên mọi nhóm con đều là nhóm con chuẩn tắc; còn cấu trúc nhân của vành khá yếu, không tự áp đặt thêm ràng buộc nào lên cấu trúc con. Điều này cho thấy điều kiện đóng dưới nhân trái và nhân phải cũng là đủ.

???+ example "Ví dụ: vành số nguyên $\mathbf Z$ (tiếp)"
    Chẳng hạn, vành con $n\mathbf Z$ đã nhắc ở trên thực ra là một iđêan của $\mathbf Z$. Nó là tập hợp tất cả bội của $n$. Một bội của $n$ khi nhân với bất kỳ số nguyên nào vẫn là một bội của $n$. Trên thực tế, mọi iđêan của $\mathbf Z$ đều có dạng này; những vành như vậy được gọi là [miền iđêan chính](#mien-ide-an-chinh). Đối với vành tổng quát, một số iđêan không phải là tập các bội của một phần tử nào đó; sự tồn tại của các vành như vậy cũng là động cơ ban đầu để nghiên cứu iđêan, thay vì chỉ nghiên cứu bội số[^ideal-history].

<span id="&#21830;&#29615;"></span>
### Vành thương

Tương tự trường hợp nhóm, dựa trên iđêan của vành, ta có thể định nghĩa **vành thương** (quotient ring) trên tập tất cả các lớp kề theo nghĩa nhóm cộng. Xét tập

$$
R/I=\{a+I:a\in R\},
$$

trong đó lớp kề $a+I=\{a+b:b\in I\}$. Có thể chứng minh rằng khi và chỉ khi $I$ là iđêan thì các phép toán

$$
\begin{aligned}
(a+I)+(b+I)&=(a+b)+I,\\
(a+I)(b+I)&=(ab)+I
\end{aligned}
$$

là xác định tốt, tức là kết quả của các phép toán không phụ thuộc vào cách chọn đại diện trong lớp kề. Dưới các phép toán này, $R/I$ tạo thành một vành. Cũng như với nhóm, ta có thể xây dựng **định lý đẳng cấu thứ nhất** (first isomorphism theorem) cho vành, và tồn tại đồng cấu tự nhiên từ vành đến vành thương của nó. Những điều này cho thấy iđêan của vành và nhóm con chuẩn tắc của nhóm giữ cùng một vai trò trong đồng cấu của các cấu trúc tương ứng.

???+ note "Định lý đẳng cấu thứ nhất"
    Cho $\pi:R\rightarrow S$ là đồng cấu từ vành $R$ đến vành $S$. Khi đó $\ker\pi$ là một iđêan của $R$, và $R/\ker\pi\cong\pi(R)$ là một vành con của $S$.

???+ abstract "Đồng cấu tự nhiên"
    Với vành $R$ và iđêan $I$ của nó, ánh xạ $\pi:R\rightarrow R/I$ cho bởi $\pi(r)=r+I$ là một đồng cấu toàn ánh từ $R$ đến $R/I$, gọi là **đồng cấu tự nhiên** (natural homomorphism) từ vành $R$ đến vành thương $R/I$.

???+ example "Ví dụ: vành số nguyên $\mathbf Z$ (tiếp)"
    Chẳng hạn, vành $\mathbf Z/n\mathbf Z$ gồm các lớp đồng dư modulo $n$ của số nguyên là vành thương thu được khi lấy $\mathbf Z$ modulo iđêan $n\mathbf Z$ của nó. Điều này cũng giải thích ý nghĩa của ký hiệu $\mathbf Z/n\mathbf Z$. Ánh xạ modulo $n$ đã nhắc ở trên, $\pi:\mathbf Z\rightarrow\mathbf Z/n\mathbf Z$, chính là ánh xạ tự nhiên ở đây, và hạt nhân tương ứng chính là iđêan $n\mathbf Z$.

Trong trường hợp vành, các định lý đẳng cấu khác cũng đúng.

???+ note "Định lý đẳng cấu thứ hai"
    Giả sử vành $R$ có vành con $A$ và iđêan $B$. Khi đó $A+B=\{a+b:a\in A,b\in B\}$ cũng là vành con của $R$, còn $A\cap B$ là iđêan của $A$, $B$ là iđêan của $A+B$, và $(A+B)/B\cong A/(A\cap B)$.

???+ note "Định lý đẳng cấu thứ ba"
    Giả sử vành $R$ có các iđêan $I,J$ và $I\subseteq J$. Khi đó $J/I$ cũng là iđêan của $R/I$, và $(R/I)/(J/I)\cong R/J$.

???+ note "Định lý tương ứng"
    Giả sử vành $R$ có iđêan $I$. Khi đó tồn tại song ánh $\varphi:\mathcal S\rightarrow\mathcal T$ giữa tập tất cả vành con của $R$ chứa $I$, $\mathcal S=\{S:I\subseteq S\subseteq R\}$, và tập tất cả nhóm con của nhóm thương $R/I$, $\mathcal T=\{T:T\le R/I\}$; song ánh này gửi $S\in\mathcal S$ đến $S/I\in\mathcal T$. Song ánh này bảo toàn quan hệ bao hàm giữa các vành con, và iđêan của vành $R$ luôn được ánh xạ thành iđêan của $R/I$.

Các định lý này sẽ đóng vai trò nền tảng khi ta thảo luận về cấu trúc của vành và iđêan ở các phần sau.

<span id="&#29702;&#24819;&#30340;&#36816;&#31639;"></span>
### Các phép toán trên iđêan

Có thể định nghĩa nhiều phép toán khác nhau trên các iđêan của một vành. Điều này tương tự việc định nghĩa các khái niệm như ước chung lớn nhất, bội chung nhỏ nhất trong cấu trúc chia hết của số nguyên.

???+ abstract "Các phép toán trên iđêan"
    Giả sử vành $R$ có các iđêan $I,J$. Ta có thể định nghĩa các phép toán sau:
    
    -   **tổng** (sum) của iđêan: $I+J=\{a+b:a\in I,b\in J\}$;
    -   **tích** (product) của iđêan: $IJ=\{\sum_{i=1}^na_ib_i:a_i\in I,b_i\in J\}$, tức là tập các tổng hữu hạn của những tích có dạng $ab$;
    -   **giao** (intersection) của iđêan: $I\cap J$.

Dễ kiểm tra rằng kết quả của các phép toán này vẫn là iđêan của vành.

???+ example "Ví dụ: vành số nguyên $\mathbf Z$ (tiếp)"
    Xét trường hợp vành số nguyên $\mathbf Z$. Với các iđêan $n\mathbf Z$ và $m\mathbf Z$, ta có
    
    $$
    \begin{aligned}
    n\mathbf Z+m\mathbf Z&=\gcd(m,n)\mathbf Z,\\
    (n\mathbf Z)(m\mathbf Z)&=(mn)\mathbf Z,\\
    (n\mathbf Z)\cap(m\mathbf Z)&=\mathrm{lcm}(m,n)\mathbf Z.
    \end{aligned}
    $$

Nói chung, với vành $R$ và các iđêan $I,J$ của nó, luôn có

$$
IJ\subseteq I\cap J\subseteq I,J\subseteq I+J.
$$

Dùng các định nghĩa này, ta có thể khái quát định lý số dư Trung Hoa từ số nguyên sang vành tổng quát. Trước đó, cần tiếp tục khái quát các khái niệm như nguyên tố và nguyên tố cùng nhau lên vành tổng quát.

<span id="&#26497;&#22823;&#29702;&#24819;"></span>
### Iđêan cực đại

Thông qua cấu trúc iđêan của vành, ta có thể hiểu các tính chất của vành.

Vành khác không $R$ luôn có hai iđêan tầm thường, là $\{0\}$ và $R$. Nếu $R$ còn là vành giao hoán, thì $R$ chỉ có hai iđêan này khi và chỉ khi nó là trường[^simple-ring].

???+ note "Định lý"
    Cho $R$ là vành giao hoán có đơn vị, khác không. Khi đó $R$ là trường khi và chỉ khi $R$ chỉ có các iđêan tầm thường $\{0\}$ và $R$.

??? note "Chứng minh"
    Nếu $R$ là trường, thì với mọi iđêan khác không $I$, lấy một phần tử khác không $a\in I$. Khi đó với mọi phần tử $r\in R$, ta có $r=(ra^{-1})a\in (ra^{-1})I\subseteq I$, suy ra $I=R$. Ngược lại, với mọi $a\in R$ và $a\neq 0$, có thể kiểm tra $aR=\{ar:r\in R\}$ là một iđêan, nên nó phải bằng $R$. Vì vậy tồn tại $b\in R$ sao cho $ab=1$, tức là $a$ có nghịch đảo. Do đó $R$ là trường.

Điều kiện giao hoán ở đây là cần thiết; nếu không, phải đồng thời yêu cầu mọi iđêan trái và iđêan phải đều tầm thường mới bảo đảm vành là vành chia.

Kết luận trên có thể khái quát cho trường hợp bản thân vành không phải là trường. Tuy nhiên, lúc này cần chuyển sang xét vành thương, tức là thảo luận điều kiện để vành thương của một vành giao hoán có đơn vị, khác không là trường. Vành thương $R/I$ là trường nghĩa là $R/I$ chỉ có các iđêan tầm thường; theo định lý tương ứng, điều này có nghĩa là trong vành ban đầu $R$ không có iđêan nào nằm nghiêm ngặt giữa iđêan bị lấy modulo $I$ và toàn bộ vành $R$. Những iđêan $I$ như vậy được gọi là iđêan cực đại.

???+ abstract "Iđêan cực đại"
    Với vành $R$ và iđêan $M$ của nó, nếu $M\neq R$ và các iđêan của $R$ chứa $M$ chỉ có hai iđêan $M$ và $R$, thì iđêan $M$ được gọi là một **iđêan cực đại** (maximal ideal).

???+ note "Định lý"
    Giả sử vành giao hoán có đơn vị, khác không $R$ có iđêan $M$. Khi đó vành thương $R/M$ là trường khi và chỉ khi $M$ là iđêan cực đại.

???+ example "Ví dụ: vành số nguyên $\mathbf Z$ (tiếp)"
    Chẳng hạn, iđêan $n\mathbf Z$ trong vành số nguyên $\mathbf Z$ là iđêan cực đại khi và chỉ khi $n$ là số nguyên tố. Với số nguyên tố $p$, vành thương $\mathbf Z/p\mathbf Z$ là trường, cũng được ký hiệu là $\mathbf F_p$.

Không phải mọi vành đều có iđêan cực đại, nhưng trong vành có đơn vị khác không thì iđêan cực đại luôn tồn tại.

???+ note "Định lý (Krull)"
    Với iđêan $I\neq R$ của vành có đơn vị khác không $R$, luôn tồn tại iđêan cực đại $M$ của $R$ sao cho $I\subseteq M$.

??? note "Chứng minh"
    Ý tưởng là dùng bổ đề Zorn. Xét tập $\mathcal S$ gồm tất cả iđêan thực sự của $R$ chứa $I$ (tức là các iđêan khác $R$). Vì $I\in\mathcal S$, tập này khác rỗng, và nó tạo thành một tập sắp thứ tự bộ phận theo quan hệ bao hàm. Với bất kỳ dây chuyền nào trong đó, $J_0\subseteq J_1\subseteq\cdots\subseteq J_n\subseteq\cdots$, gọi hợp của chúng là $J$; dễ kiểm tra $J$ cũng là iđêan. Hơn nữa, $J\neq R$, nếu không $1\in J$, tức là tồn tại $n$ sao cho $1\in J_n$, mâu thuẫn với việc $J_n$ là iđêan thực sự. Do đó, theo bổ đề Zorn, tồn tại iđêan cực đại $M\supseteq I$.

Nếu đối chiếu với lý thuyết chia hết, iđêan cực đại tương tự phần tử bất khả quy. Lý do là quan hệ bao hàm giữa các iđêan chính là quan hệ chia hết của số nguyên; việc không còn iđêan nào chứa nó một cách thực sự tương ứng với việc không còn nhân tử không tầm thường. Tuy nhiên, khái niệm iđêan cực đại rộng hơn phần tử bất khả quy, vì không phải mọi iđêan đều là iđêan chính.

<span id="&#32032;&#29702;&#24819;"></span>
### Iđêan nguyên tố

Điều kiện để là trường mạnh hơn điều kiện để là miền nguyên. Iđêan bảo đảm vành thương là miền nguyên được gọi là iđêan nguyên tố; nó tương tự khái niệm số nguyên tố trong lý thuyết chia hết.

???+ abstract "Iđêan nguyên tố"
    Với vành giao hoán $R$ và iđêan $P$ của nó, nếu $P\neq R$ và với mọi phần tử $a,b\in R$, hễ $ab\in P$ thì luôn có $a\in P$ hoặc $b\in P$, thì iđêan $P$ được gọi là một **iđêan nguyên tố** (prime ideal).

Định nghĩa này thoạt nhìn có vẻ đột ngột, nhưng nếu so sánh với [định nghĩa số nguyên tố](../number-theory/basic.md#%E7%AE%97%E6%9C%AF%E5%9F%BA%E6%9C%AC%E5%AE%9A%E7%90%86), ta thấy nó rất tự nhiên.

???+ note "Định lý"
    Giả sử vành giao hoán có đơn vị, khác không $R$ có iđêan $P$. Khi đó vành thương $R/P$ là miền nguyên khi và chỉ khi $P$ là iđêan nguyên tố.

??? note "Chứng minh"
    Với vành giao hoán có đơn vị, khác không $R$, vành thương $R/P$ là miền nguyên khi và chỉ khi $R/P$ không có ước của không. Ký hiệu lớp kề $a+P$ là $\bar a$. Việc $R/P$ không có ước của không tương đương với $\bar a\bar b=\bar 0$ luôn kéo theo $\bar a=\bar 0$ hoặc $\bar b=\bar 0$. Theo định lý tương ứng, điều này tương đương với việc $ab\in P$ luôn kéo theo $a\in P$ hoặc $b\in P$.

Trong vành số nguyên $\mathbf Z$, $n\mathbf Z$ là iđêan cực đại và iđêan nguyên tố khi và chỉ khi $n$ là số nguyên tố. Trong vành giao hoán tổng quát, iđêan cực đại luôn là iđêan nguyên tố, nhưng chiều ngược lại không nhất thiết đúng; điều này có thể thấy từ tính chất của các vành thương tương ứng.

???+ note "Định lý"
    Với vành giao hoán có đơn vị, khác không $R$, mọi iđêan cực đại của nó đều là iđêan nguyên tố.

Ta sẽ thấy ngay sau đây rằng mệnh đề đảo chỉ đúng trong những vành có tính chất tốt, đủ giống vành số nguyên.

<span id="&#20027;&#29702;&#24819;"></span>
### Iđêan chính

Tương tự khái niệm nhóm con sinh bởi một tập, trong thảo luận về vành ta cũng thường cần xét iđêan sinh bởi một tập con nào đó.

???+ abstract "Iđêan sinh bởi một tập con"
    Với vành có đơn vị khác không $R$ và tập con khác rỗng $A\subseteq R$ của nó, nếu $I$ là iđêan nhỏ nhất theo quan hệ bao hàm trong số các iđêan của $R$ chứa $A$, thì $I$ được gọi là **iđêan sinh bởi tập con $A$** (ideal generated by a subset), ký hiệu là $(A)$. Khi đó, $A$ được gọi là **tập sinh** (generating set) của $(A)$.

???+ abstract "Iđêan chính"
    Iđêan sinh bởi một phần tử $a\in R$ được gọi là **iđêan chính** (principal ideal), ký hiệu là $(a)$. Khi đó, $a$ được gọi là **phần tử sinh** (generator) của $(a)$.

Với tập $A$, ta có thể mô tả cách xây dựng iđêan do nó sinh ra. Trước hết, định nghĩa

$$
\begin{aligned}
RA&=\{r_1a_1+\cdots+r_na_n:r_i\in R,a_i\in A,n\in\mathbf Z\},\\
AR&=\{a_1r_1+\cdots+a_nr_n:r_i\in R,a_i\in A,n\in\mathbf Z\}.
\end{aligned}
$$

Thực ra chúng lần lượt là iđêan trái và iđêan phải sinh bởi $A$. Khi đó, iđêan sinh bởi tập con $A$ là $RAR$. Với vành giao hoán, các cấu trúc được định nghĩa như vậy đều trùng nhau.

Tất cả iđêan $n\mathbf Z$ trong vành số nguyên đều là iđêan chính; dưới đây thường ký hiệu chúng là $(n)$.

<span id="&#25972;&#29615;"></span>
## Miền nguyên

Miền nguyên là vành khác không, giao hoán, có đơn vị và không có ước của không. Khái niệm này chính là sự khái quát của vành số nguyên. Tuy nhiên, các vành thu được như vậy chưa chắc có đủ tính chất tốt để chuyển nguyên vẹn mọi kết luận trong lý thuyết chia hết của số nguyên sang. Để khái quát các kết luận trong số học, ta có thể đặt thêm điều kiện lên miền nguyên. Ba loại miền nguyên thường gặp nhất là miền Euclid, miền iđêan chính và miền phân tích duy nhất; các khái niệm đứng trước được chứa nghiêm ngặt trong các khái niệm đứng sau.

<span id="&#25972;&#38500;&#20851;&#31995;"></span>
### Quan hệ chia hết

Trước hết, ta khái quát các khái niệm liên quan trong lý thuyết chia hết của số nguyên lên vành giao hoán tổng quát.

???+ abstract "Chia hết"
    Giả sử vành giao hoán $R$ có các phần tử $a,b\in R$. Nếu tồn tại $x\in R$ sao cho $a=bx$, thì ta nói $a$ **chia hết cho** $b$, hay $b$ **chia** (divide) $a$, ký hiệu $b\mid a$. Khi đó $b$ được gọi là **ước** (divisor) của $a$.

???+ abstract "Liên hợp"
    Giả sử vành giao hoán $R$ có các phần tử $a,b\in R$. Nếu chúng chỉ khác nhau bởi một phần tử khả nghịch, tức là tồn tại phần tử khả nghịch $u\in R$ sao cho $a=bu$, thì $a$ và $b$ được gọi là **liên hợp** (associate).

Quan hệ chia hết là một quan hệ [thứ tự bộ phận](../order-theory.md#%E4%BA%8C%E5%85%83%E5%85%B3%E7%B3%BB) trên vành, còn quan hệ liên hợp là một quan hệ tương đương trên vành. Từ góc nhìn iđêan, $a\mid b$ tương đương với $(b)\subseteq (a)$, còn $a$ và $b$ liên hợp tương đương với $(a)=(b)$. Vì vậy, khi thảo luận các phần tử trong vành, ta thường không phân biệt các phần tử liên hợp. Tương tự trường hợp số nguyên, ước chung lớn nhất của $a$ và $b$ trong vành giao hoán được định nghĩa là cận dưới lớn nhất của $\{a,b\}$ theo quan hệ chia hết.

???+ abstract "Ước chung lớn nhất"
    Với vành giao hoán $R$ và các phần tử $a,b\in R$ của nó, nếu tồn tại phần tử khác không $d\in R$ thỏa mãn $d\mid a$ và $d\mid b$, đồng thời với mọi $d'$ thỏa mãn $d'\mid a$ và $d'\mid b$ đều có $d'\mid d$, thì $d$ được gọi là **ước chung lớn nhất** (greatest common divisor) của $a$ và $b$, ký hiệu là $\gcd(a,b)$.

Trong miền nguyên, ước chung lớn nhất được xác định duy nhất theo nghĩa liên hợp. Phần thảo luận dưới đây sẽ được giới hạn trong miền nguyên.

Trong miền nguyên còn có thể xây dựng khái niệm tương tự số nguyên tố. Trong lý thuyết số nguyên, số nguyên tố có hai định nghĩa tương đương, nhưng trong miền nguyên tổng quát, hai định nghĩa này tương ứng với hai khái niệm khác nhau:

???+ abstract "Phần tử nguyên tố"
    Giả sử miền nguyên $R$ có phần tử khác không $p\in R$. Nếu $(p)$ là iđêan nguyên tố, tức là $p$ không khả nghịch và $p\mid ab$ luôn kéo theo $p\mid a$ hoặc $p\mid b$, thì $p$ được gọi là **phần tử nguyên tố** (prime).

???+ abstract "Phần tử bất khả quy"
    Giả sử miền nguyên $R$ có phần tử khác không $r\in R$. Nếu $r$ không khả nghịch, và với mọi $a,b\in R$ thỏa mãn $r=ab$ thì $a$ hoặc $b$ là phần tử khả nghịch, thì $r$ được gọi là **phần tử bất khả quy** (irreducible), hoặc nói $r$ bất khả quy. Ngược lại, nếu $r=ab$ và $a,b\in R$ đều không khả nghịch, thì $r$ được gọi là khả quy.

Có thể chỉ ra rằng iđêan chính $(r)$ ứng với phần tử bất khả quy $r$ luôn cực đại trong tập các iđêan chính của vành. Tuy nhiên, trong miền nguyên tổng quát, không phải mọi iđêan đều là iđêan chính, nên khái niệm phần tử bất khả quy và iđêan cực đại không tương đương.

Tương tự cách chứng minh trong miền iđêan chính rằng iđêan nguyên tố nhất định là iđêan cực đại, nói chung có thể chứng minh kết luận sau:

???+ note "Định lý"
    Giả sử $R$ là miền nguyên. Nếu $a\in R$ là phần tử nguyên tố, thì $a$ cũng là phần tử bất khả quy.

??? note "Chứng minh"
    Giả sử $r\in R$ là phần tử nguyên tố, và $a,b\in R$ thỏa mãn $r=ab$. Vì $r$ là phần tử nguyên tố, không mất tính tổng quát giả sử $r\mid a$. Khi đó $a=cr=cba$. Vì luật khử đúng trên miền nguyên, ta có $1=bc$, nên $b$ có nghịch đảo $c$. Điều này cho thấy $r$ là phần tử bất khả quy.

Chiều ngược lại không đúng.

??? example "Phản ví dụ"
    Trong vành số nguyên bậc hai $\mathbf Z[\sqrt{-5}]$, $3$ là phần tử bất khả quy, nhưng $9=3\cdot 3=(2+\sqrt{-5})(2-\sqrt{-5})$, nên nó không phải là phần tử nguyên tố.
    
    Sau đây là chứng minh cho phản ví dụ này; độc giả chưa quen với vành số nguyên bậc hai nên đọc trước phần [vành số nguyên bậc hai](#vi-du-vanh-so-nguyen-bac-hai). Gọi $N(\cdot)$ là chuẩn trên vành số nguyên bậc hai. Với mọi phân tích $3=ab$, ta có $N(a)N(b)=N(3)=9$. Nếu $a,b$ đều không khả nghịch, thì $N(a)$ và $N(b)$ đều lớn hơn $1$, do đó nhất định có $N(a)=N(b)=3$. Nhưng trên $\mathbf Z[\sqrt{-5}]$ không có phần tử như vậy, tức là $x^2+5y^2=3$ không có nghiệm nguyên. Điều này cho thấy $3$ là phần tử bất khả quy. Còn để thấy $3$ không phải là phần tử nguyên tố, chỉ cần chứng minh $3$ không chia $2\pm\sqrt{-5}$; điều này là hiển nhiên.

<span id="&#27431;&#20960;&#37324;&#24471;&#25972;&#29615;"></span>
### Miền Euclid

Đọc thêm: [thuật toán Euclid (mở rộng)](../number-theory/gcd.md), [định lý Bézout](../number-theory/bezouts.md)

Miền Euclid là miền nguyên cho phép thực hiện phép chia có dư, từ đó thực hiện được thuật toán Euclid.

???+ abstract "Miền Euclid"
    Với miền nguyên $R$, nếu tồn tại ánh xạ $N:R\setminus\{0\}\rightarrow\mathbf N$ sao cho với mọi $a,b\in R$ và $b\neq 0$, luôn tồn tại $q,r\in R$ thỏa mãn $a=qb+r$ và $r=0$ hoặc $N(r)<N(b)$, thì $R$ được gọi là **miền Euclid** (Euclidean domain, ED). Ánh xạ $N$ được gọi là chuẩn (norm) của phần tử trong miền Euclid.

??? info "Các định nghĩa tương đương khác"
    Định nghĩa dùng trong bài này chỉ định nghĩa chuẩn trên các phần tử khác không. Các tài liệu khác nhau có thể trình bày định nghĩa miền Euclid theo những cách khác nhau. Chẳng hạn, có tài liệu bổ sung định nghĩa $N(0)=0$; nhưng trong phép chia có dư, giá trị của $N(0)$ không được dùng đến, nên điều này không quan trọng. Một số tài liệu, như định nghĩa trên [Wikipedia](https://en.wikipedia.org/wiki/Euclidean_domain), còn yêu cầu chuẩn $N$ thỏa mãn tính chất: với mọi $a,b\in R$ khác không đều có $N(a)\le N(ab)$. Tuy nhiên, dễ kiểm tra rằng nếu miền Euclid $R$ có chuẩn $N(\cdot)$ thỏa mãn tính chất trong định nghĩa của bài này, thì có thể định nghĩa chuẩn $N'(a)=\min_{b\in R\setminus\{0\}} N(ab)$ để nó thỏa mãn thêm tính chất $N'(a)\le N'(ab)$. Do đó các định nghĩa khác nhau này đều tương đương.

Định nghĩa này là sự khái quát của phép chia có dư trong số nguyên. Sự tồn tại của chuẩn cho phép đo kích thước tương đối giữa số dư và số chia. Khi thực hiện thuật toán Euclid, chuẩn của các số dư liên tiếp sẽ giảm dần; vì chuẩn nhận giá trị trong các số tự nhiên, quá trình này nhất định kết thúc khi $r=0$. Từ đó ta thu được thuật toán Euclid trên miền Euclid.

Việc thực hiện được thuật toán Euclid có nghĩa là trên miền Euclid có thể tính ước chung lớn nhất một cách hiệu quả. Hoàn toàn tương tự lý thuyết chia hết của số nguyên, có thể chứng minh kết quả của thuật toán Euclid là ước chung lớn nhất, và định lý Bézout vẫn đúng; các hệ số trong định lý có thể được xác định bằng thuật toán Euclid mở rộng.

???+ note "Định lý"
    Với miền Euclid $R$ và các phần tử $a,b\in R$ của nó, kết quả $d$ thu được khi áp dụng thuật toán Euclid cho $a$ và $b$ là ước chung lớn nhất của $a$ và $b$, và tồn tại $x,y\in R$ sao cho $d=ax+by$; ngược lại, mọi phần tử có dạng $ax+by$ đều là bội của $d$.

Lưu ý rằng trong ngôn ngữ lý thuyết vành, mọi phần tử có dạng $ax+by$ chính là các phần tử của iđêan $(a,b)$, và định lý này cho thấy $(a,b)$ nhất định là iđêan chính $(d)$.

Thực ra, mọi iđêan trong miền Euclid đều là iđêan chính.

???+ note "Định lý"
    Mọi iđêan trong miền Euclid đều là iđêan chính.

??? note "Chứng minh"
    Giả sử $R$ là miền Euclid, và $I$ là một iđêan của nó. Nếu $I=\{0\}$, nó hiển nhiên là iđêan chính. Giả sử $I$ là iđêan khác không. Theo định nghĩa, trên vành $R$ có chuẩn $N(\cdot)$, nên có thể chọn phần tử khác không $d$ trong $I$ có chuẩn nhỏ nhất. Khi đó với mọi $a\in I$, ta có $a=qd+r$ với $r=0$ hoặc $N(r)< N(d)$. Lại vì $r=a-qd\in I$, theo cách chọn $d$ suy ra $r=0$, tức là $a=qd\in (d)$. Điều này cho thấy $I$ là iđêan chính.

<span id="&#20027;&#29702;&#24819;&#25972;&#29615;"></span><span id="mien-ide-an-chinh"></span>
### Miền iđêan chính

Miền nguyên mà mọi iđêan đều là iđêan chính được gọi là miền iđêan chính. Đây là một lớp miền nguyên có tính chất tốt và cũng rất thường gặp. Trong các miền nguyên này, khái niệm iđêan của vành gần như đồng nhất với khái niệm bội số trong số nguyên.

???+ abstract "Miền iđêan chính"
    Với miền nguyên $R$, nếu mọi iđêan của nó đều là iđêan chính, thì $R$ được gọi là **miền iđêan chính** (principal ideal domain, PID).

Do đó, định lý cuối của mục trước có thể được phát biểu lại như sau:

???+ note "Định lý"
    Mọi miền Euclid đều là miền iđêan chính.

Trong miền iđêan chính, iđêan cực đại tương đương với iđêan sinh bởi một phần tử bất khả quy. Tương tự việc số nguyên tố và phần tử bất khả quy là tương đương trong số nguyên, trong miền iđêan chính hai khái niệm này cũng tương đương; do đó iđêan cực đại và iđêan nguyên tố cũng hoàn toàn tương đương.

???+ note "Định lý"
    Giả sử miền iđêan chính $R$ có iđêan khác không $I$. Khi đó $I$ là iđêan nguyên tố khi và chỉ khi $I$ là iđêan cực đại.

??? note "Chứng minh"
    Chỉ cần chứng minh mọi iđêan nguyên tố đều là iđêan cực đại. Giả sử trong miền iđêan chính $R$ có iđêan nguyên tố khác không $(p)$, và đồng thời có iđêan $(a)$ thỏa mãn $(p)\subseteq(a)\subseteq R$. Điều này cho thấy $a\mid p$, nên tồn tại $b\in R$ sao cho $p=ab$. Nhưng vì $(p)$ là iđêan nguyên tố, $ab\in(p)$ kéo theo $a\in(p)$ hoặc $b\in(p)$. Nếu $a\in(p)$, thì $(a)\subseteq (p)$, suy ra $(a)=(p)$; nếu $b\in(p)$, thì $b=cp$, nên $p=acp$, và vì $p\neq 0$, ta có $1=ac$, tức là $a$ có nghịch đảo $c$, do đó $(a)=R$. Điều này cho thấy $(p)$ là iđêan cực đại.

???+ note "Hệ quả"
    Giả sử miền iđêan chính $R$ có phần tử khác không $r$. Khi đó $r$ là phần tử nguyên tố khi và chỉ khi $r$ là phần tử bất khả quy.

Phân tích về định lý Bézout ở mục trước có thể chuyển sang miền iđêan chính.

???+ note "Định lý"
    Giả sử $R$ là miền iđêan chính, và $a,b\in R$ là các phần tử khác không. Gọi $d\in R$ là phần tử sinh của iđêan $(a,b)$. Khi đó ước chung lớn nhất của $a$ và $b$ là $d$, và là duy nhất theo nghĩa liên hợp; hơn nữa, tồn tại $x,y\in R$ sao cho $ax+by=d$.

Nói cách khác, [định lý Bézout](../number-theory/bezouts.md) vẫn đúng trong miền iđêan chính. Dù cả hai đều có ước chung lớn nhất, khác biệt lớn nhất giữa miền Euclid và miền iđêan chính là trong miền Euclid, ước chung lớn nhất có thể được tính hiệu quả bằng thuật toán Euclid, còn trong miền iđêan chính nói chung không có thuật toán hiệu quả như vậy.

<span id="&#21807;&#19968;&#20998;&#35299;&#25972;&#29615;"></span>
### Miền phân tích duy nhất

Khái niệm tổng quát hơn miền iđêan chính là miền phân tích duy nhất. Định lý phân tích duy nhất của số nguyên được gọi là [định lý cơ bản của số học](../number-theory/basic.md#%E7%AE%97%E6%9C%AF%E5%9F%BA%E6%9C%AC%E5%AE%9A%E7%90%86). Một định lý phân tích duy nhất tương tự vẫn đúng trong một số miền nguyên không phải miền iđêan chính. Những miền nguyên như vậy được gọi là miền phân tích duy nhất.

???+ abstract "Miền phân tích duy nhất"
    Với miền nguyên $R$, nếu mọi phần tử khác không và không khả nghịch $r$ đều có thể viết dưới dạng $r=p_1\cdots p_n$, trong đó $p_1,\cdots,p_n$ là các phần tử bất khả quy có thể lặp lại, và phân tích như vậy là duy nhất theo nghĩa liên hợp và hoán vị lại thứ tự, thì miền nguyên $R$ được gọi là **miền phân tích duy nhất** (unique factorization domain, UFD).

Định lý cơ bản của số học cho thấy vành số nguyên $\mathbf Z$ là miền phân tích duy nhất.

Ở trên đã đưa ra phản ví dụ trong đó phần tử bất khả quy không phải là phần tử nguyên tố; miền nguyên $\mathbf Z[\sqrt{-5}]$ xuất hiện trong đó không còn thỏa mãn định lý phân tích duy nhất. Tuy nhiên, trên mọi miền phân tích duy nhất, phần tử bất khả quy và phần tử nguyên tố là tương đương.

???+ note "Định lý"
    Với miền phân tích duy nhất $R$ và phần tử khác không $a\in R$ của nó, $a$ là phần tử nguyên tố khi và chỉ khi $a$ là phần tử bất khả quy.

??? note "Chứng minh"
    Chỉ cần chứng minh mọi phần tử bất khả quy đều là phần tử nguyên tố. Với phần tử bất khả quy $r$, nếu $r\mid ab$, thì tồn tại $c\in R$ sao cho $ab=rc$. Vì $R$ là miền phân tích duy nhất, ta có thể phân tích $a,b,c\in R$ thành tích các phần tử bất khả quy. So sánh hai vế và dùng tính duy nhất của phân tích, suy ra $r$ liên hợp với một nhân tử bất khả quy nào đó của $a$ hoặc của $b$, do đó $r$ chia một trong hai phần tử $a$ hoặc $b$. Điều này cho thấy $r$ cũng là phần tử nguyên tố.

Mọi miền iđêan chính đều là miền phân tích duy nhất.

???+ note "Định lý"
    Mọi miền iđêan chính đều là miền phân tích duy nhất.

??? note "Chứng minh"
    Giả sử $R$ là miền iđêan chính, và $r\in R$ không phải phần tử không, cũng không khả nghịch. Để chứng minh $r$ có thể phân tích duy nhất thành tích của một dãy phần tử bất khả quy, có thể chia làm hai bước: trước hết chứng minh sự tồn tại của phân tích, rồi chứng minh tính duy nhất của phân tích.
    
    Sự tồn tại của phân tích khá tự nhiên. Nếu $r$ đã là phần tử bất khả quy thì không cần tiếp tục phân tích; nếu không, tồn tại $r_1,r_2$ sao cho $r=r_1r_2$ và $r_1,r_2$ đều không khả nghịch. Tiếp theo, nếu $r_1$ và $r_2$ đều là phần tử bất khả quy thì cũng không cần tiếp tục phân tích; nếu không, phần tử nào trong $r_1$ và $r_2$ không bất khả quy có thể được phân tích tiếp, và $r$ có thể được viết thành tích của nhiều phần tử hơn. Vì vậy, chừng nào các thừa số trong tích chưa toàn là phần tử bất khả quy, quá trình phân tích còn có thể tiếp tục. Quá trình phân tích nhất định dừng sau hữu hạn bước. Nếu không, tiên đề chọn bảo đảm có thể chọn từ $R$ một dây chuyền vô hạn các phần tử $\{r_{(i)}\}_{i=0}^\infty$ thỏa mãn $r_{(0)}=r$ và $r_{(i+1)}\mid r_{(i)}$ với mọi $i\in\mathbf N$, đồng thời các quan hệ chia hết này đều nghiêm ngặt, tức là trong dây chuyền không có các phần tử liên hợp. Nói bằng ngôn ngữ iđêan, điều này tương ứng với dãy iđêan tăng nghiêm ngặt vô hạn: $I_{0}\subset I_{1}\subset \cdots\subset I_{i}\subset\cdots\subset R$, trong đó $I_i=(r_{(i)})$. Dễ kiểm tra hợp $I=\bigcup_{i=0}^\infty I_i$ của các iđêan này vẫn là iđêan, nên nhất định là iđêan chính. Gọi $a$ là phần tử sinh của iđêan chính $I$; khi đó tồn tại $n\in\mathbf N$ sao cho $a\in I_n$. Vì vậy $I=(a)\subseteq I_n$. Điều này cho thấy dãy iđêan tăng nghiêm ngặt vô hạn nói trên không tồn tại, nên quá trình phân tích ở trên nhất định dừng trong hữu hạn bước.
    
    Sau đó chứng minh tính duy nhất của phân tích. Ta có thể quy nạp theo số nhân tử trong phân tích. Bước then chốt của quy nạp là kiểm tra rằng nếu $r=p_1p_2\cdots p_n=q_1q_2\cdots q_m$ và $n\le m$, thì nhất định có $p_1$ liên hợp với một $q_j$ nào đó. Ở đây cần dùng kết luận trước đó: trong miền iđêan chính, mọi phần tử bất khả quy đều là phần tử nguyên tố. Đã biết $p_1$ là phần tử bất khả quy trong $R$, nên nó cũng là phần tử nguyên tố; vì vậy với tích ở vế phải, có thể dùng quy nạp để chỉ ra rằng tồn tại $q_j$ sao cho $p_1\mid q_j$. Do đó tồn tại $c\in R$ sao cho $q_j=p_1c$, mà $q_j$ là phần tử bất khả quy và $p_1$ cũng là phần tử bất khả quy, nên theo định nghĩa $c$ chỉ có thể khả nghịch; do đó $p_1$ liên hợp với $q_j$. Khi ấy có thể dùng luật khử để khử $p_1$ và $q_j$ ở hai vế, rồi nhân phần tử khả nghịch biểu thị sự liên hợp giữa chúng vào một nhân tử còn lại bất kỳ. Theo giả thiết quy nạp, số phần tử bất khả quy trong $p_2\cdots p_n$ và $q_1\cdots q_{j-1}q_{j+1}\cdots q_m$ nhất định bằng nhau, và chúng giống nhau theo nghĩa liên hợp. Định lý được chứng minh.

Cuối cùng, tính tồn tại của ước chung lớn nhất vẫn đúng trên miền phân tích duy nhất.

???+ note "Định lý"
    Giả sử miền phân tích duy nhất $R$ có các phần tử khác không $a,b\in R$, và chúng có thể được phân tích dưới dạng $a=up_1^{r_1}\cdots p_n^{r_n}$ và $b=vp_1^{s_1}\cdots p_n^{s_n}$, trong đó $u,v$ là các phần tử khả nghịch, $p_1,\cdots,p_n$ là các phần tử bất khả quy đôi một khác nhau, còn $r_i,s_i$ đều là số tự nhiên. Khi đó một ước chung lớn nhất của chúng là $d=p_1^{\min\{r_1,s_1\}}\cdots p_n^{\min\{r_n,s_n\}}$.

Điều này cũng cho thấy tính chất tồn tại ước chung lớn nhất còn yếu hơn cả tính đúng của định lý phân tích duy nhất[^gcd-domain].

<span id="&#20363;&#23376;&#20108;&#27425;&#25972;&#25968;&#29615;"></span><span id="vi-du-vanh-so-nguyen-bac-hai"></span>
### Ví dụ: vành số nguyên bậc hai

Đọc thêm: [trường bậc hai](../number-theory/quadratic.md)

Việc hiểu đại số trừu tượng không thể tách khỏi các ví dụ. Chính vì quá trình nghiên cứu định lý lớn Fermat đòi hỏi khảo sát tính chất của một lớp số nguyên đại số, lý thuyết vành ngày nay mới dần phát triển[^ring-theory-history]. Ở đây ta thảo luận loại số nguyên đại số đơn giản nhất, tức số nguyên bậc hai. Chứng minh của nhiều kết luận trong phần này cần dùng kiến thức phức tạp của lý thuyết số đại số, nên sẽ được lược bỏ.

**Số nguyên bậc hai** (quadratic integer) là nghiệm phức của một phương trình bậc hai hệ số nguyên có hệ số bậc hai bằng một, $\alpha^2+b\alpha+c=0$. Mọi số nguyên bậc hai có và chỉ có dạng

$$
\alpha=a+b\omega,~(a,b\in\mathbf Z)
$$

trong đó

$$
\omega=\begin{cases}
\dfrac{1+\sqrt{D}}{2},& D\equiv 1\pmod 4,\\
\sqrt D,& D\equiv 2,3\pmod 4,
\end{cases}
$$

và $D$ không có nhân tử chính phương.

??? note "Phân tích"
    Theo công thức nghiệm của phương trình bậc hai, nghiệm của phương trình này nhất định có thể viết thành
    
    $$
    \alpha=\frac{-b\pm\sqrt{b^2-4c}}{2}.
    $$
    
    Khi $b=2k+1$ là số lẻ, nghiệm này có thể viết là
    
    $$
    \alpha=-k-\frac{1\pm\sqrt{4(k^2+k-c)+1}}{2}.
    $$
    
    Ngược lại, khi $b=2k$ là số chẵn, nghiệm này có thể viết là
    
    $$
    \alpha=-k\pm\sqrt{k^2-c}.
    $$
    
    Từ đó có thể suy ra rằng số nguyên bậc hai nhất định có dạng nêu trên.

Dễ kiểm tra rằng với $\omega$ như vậy, tập $\mathbf Z[\omega]=\{a+b\omega:a,b\in\mathbf Z\}$ tạo thành một vành. Nó được gọi là **vành số nguyên bậc hai** (quadratic integer ring), và trường phân thức của nó chính là trường bậc hai $\mathbf Q(\sqrt D)$. Khi $D>0$, mọi số nguyên bậc hai đều là số thực, nên vành này cũng được gọi là **vành số nguyên bậc hai thực**; khi $D<0$, các số nguyên bậc hai ngoài số nguyên đều là số phức, nên nó cũng được gọi là **vành số nguyên bậc hai ảo**.

Mọi vành số nguyên bậc hai $\mathbf Z[\omega]$ đều là miền nguyên. Trong đó, khi $D=-1$, $\mathbf Z[\sqrt{-1}]$ (hoặc ký hiệu $\mathbf Z[\mathrm{i}]$) còn được gọi là vành số nguyên Gauss; khi $D=-3$, $\mathbf Z\left[\dfrac{1+\sqrt{-3}}{2}\right]$ được gọi là vành số nguyên Eisenstein.

Với số nguyên bậc hai $a+b\omega$, có thể định nghĩa **liên hợp** (conjugate) của nó là $a+b\bar\omega$, trong đó

$$
\bar\omega=\begin{cases}
\dfrac{1-\sqrt{D}}{2},& D\equiv 1\pmod 4,\\
-\sqrt D,& D\equiv 2,3\pmod 4,
\end{cases}
$$

Lưu ý rằng khi $D>0$, số nguyên bậc hai là số thực, nên khái niệm liên hợp ở đây không hoàn toàn trùng với khái niệm liên hợp của số phức. Tuy vậy, cả hai đều là trường hợp đặc biệt của khái niệm liên hợp của phần tử đại số trong lý thuyết trường. Hai số nguyên bậc hai liên hợp là hai nghiệm của cùng một phương trình bậc hai hệ số nguyên.

Trên vành số nguyên bậc hai có thể định nghĩa **chuẩn**

$$
\begin{aligned}
N(a+b\omega)&=(a+b\omega)(a+b\bar\omega)\\
&=\begin{cases}
a^2+ab+\dfrac{1-D}{4}b^2,& D\equiv 1\pmod 4,\\
a^2-Db^2,& D\equiv 2,3\pmod 4.
\end{cases}
\end{aligned}
$$

Chuẩn của số nguyên bậc hai luôn là số nguyên. Đặc biệt, khi $D<0$, chuẩn luôn là số tự nhiên. Chuẩn bảo toàn phép nhân, tức là $N(ab)=N(a)N(b)$.

Các phần tử khả nghịch (đơn vị) trong vành số nguyên bậc hai chính là những phần tử có chuẩn bằng $\pm1$. Với trường hợp $D>0$, điều này tương đương với việc xét nghiệm của [phương trình Pell](../number-theory/pell-equation.md) $x^2-Dy^2=\pm1$ hoặc $x^2-Dy^2=\pm4$. Với trường hợp $D<0$, dễ kiểm tra rằng ngoài hai trường hợp đặc biệt là các phần tử khả nghịch trong vành số nguyên Gauss $\mathbf Z[\rm{i}]$ bằng $\{\pm1,\pm\rm{i}\}$ và các phần tử khả nghịch trong vành số nguyên Eisenstein $\mathbf Z[\omega]$ bằng $\{\pm1,\pm\omega,\pm\omega^2\}$, các phần tử khả nghịch còn lại chỉ là $\{\pm1\}$.

Chuẩn $N(\alpha)$ định nghĩa trên vành số nguyên bậc hai có thể được dùng để chứng minh nó là miền Euclid. Với trường hợp $D>0$, cần dùng giá trị tuyệt đối $|N(\alpha)|$ làm chuẩn trong định nghĩa miền Euclid. Dùng chuẩn thu được như vậy, có thể chứng minh khi $D<0$,

$$
D=-1,-2,-3,-7,-11
$$

hoặc khi $D>0$,

$$
D=2, 3, 5, 6, 7, 11, 13, 17, 19, 21, 29, 33, 37, 41, 57, 73
$$

các vành số nguyên bậc hai ứng với những số nguyên này là miền Euclid theo chuẩn $|N(\cdot)|$. Tuy nhiên, chuẩn trong định nghĩa miền Euclid không nhất thiết phải là chuẩn được định nghĩa ở trên. Chẳng hạn, khi $D=14,69$, các vành số nguyên bậc hai tương ứng cũng là miền Euclid, nhưng cần dùng chuẩn khác. Với trường hợp $D<0$, có thể chứng minh rằng các trường hợp nêu trên chính là tất cả miền Euclid trong các vành số nguyên bậc hai.

Dùng các phương pháp phức tạp hơn, còn có thể xác định một vành số nguyên bậc hai có phải là miền iđêan chính hay không. Có thể chứng minh rằng khi $D<0$, chỉ có

$$
D=-1,-2,-3,-7,-11,-19,-43,-67,-163
$$

các vành số nguyên bậc hai tương ứng là miền iđêan chính. So sánh với kết quả ở trên, ta biết các trường hợp như $D=-19$ cung cấp ví dụ về miền iđêan chính không phải miền Euclid. Khi $D>0$, hiện vẫn chưa có kết quả hoàn chỉnh.

Tuy nhiên, có thể chứng minh rằng trong vành số nguyên bậc hai, miền phân tích duy nhất và miền iđêan chính là tương đương. Kết quả ở trên cho thấy, chẳng hạn $\mathbf Z[\sqrt{-5}]$ không phải là miền iđêan chính, nên cũng không phải miền phân tích duy nhất. Trước đó ta đã trực tiếp chứng minh bằng ví dụ rằng nó không thể phân tích duy nhất, cụ thể là

$$
9=3\times3=(2+\sqrt{-5})\times(2-\sqrt{-5}).
$$

Dùng cùng ví dụ, có thể chỉ ra iđêan $(3,2+\sqrt{-5})$ cũng không phải là iđêan chính. Ta sẽ thấy sau rằng một ví dụ đơn giản về miền phân tích duy nhất nhưng không phải miền iđêan chính là vành đa thức $\mathbf Z[x]$.

Dù nhiều vành số nguyên bậc hai không phải miền phân tích duy nhất, chúng đều là [miền Dedekind](https://en.wikipedia.org/wiki/Dedekind_domain). Điều này nghĩa là mọi iđêan không tầm thường trong các vành số nguyên bậc hai đều có thể phân tích duy nhất thành tích của một dãy iđêan nguyên tố. Nhưng nếu bản thân vành số nguyên bậc hai không phải miền iđêan chính, các nhân tử iđêan nguyên tố này không nhất thiết tương ứng với phần tử nguyên tố, nên định lý phân tích duy nhất (tức là phân tích một số thành tích các số nguyên tố) không còn đúng. Đây cũng là động cơ ban đầu để nghiên cứu iđêan thay vì chỉ nghiên cứu các số.

<span id="&#22810;&#39033;&#24335;&#29615;"></span>
## Vành đa thức

Đọc thêm: [giới thiệu kỹ thuật đa thức](../poly/intro.md)

Trong lập trình thi đấu, ta thường gặp nhiều phép toán khác nhau trên đa thức. Phép nhân, lấy nghịch đảo, lấy dư của đa thức có thể được xem là sự khái quát các phép toán trên số sang vành đa thức. Dùng ngôn ngữ đại số trừu tượng, ta có thể hiểu rõ hơn tính chất của các phép toán liên quan trên vành đa thức.

???+ abstract "Đa thức"
    Với vành giao hoán có đơn vị, khác không $R$, một **đa thức** (polynomial) trên $R$ là một tổng hình thức
    
    $$
    \sum_{k=0}^{n}a_kx^k = a_0+a_1x+\cdots+a_{n-1}x^{n-1}+a_nx^n,
    $$
    
    trong đó $n\in\mathbf N$, và với mỗi $k$ đều có $a_k\in R$. Các $a_k$ này được gọi là **hệ số** (coefficient) của đa thức, còn $a_kx^k$ tương ứng được gọi là **hạng tử** (term) của đa thức. Trong hạng tử $a_kx^k$, số $k$ được gọi là **bậc** (degree) của hạng tử đó.
    
    Đa thức có mọi hệ số bằng không (tức bằng phần tử không) được gọi là **đa thức không** (zero polynomial), ký hiệu là $0$. Với các đa thức khác, không mất tính tổng quát giả sử $a_n\neq 0$, tức là $a_nx^n$ là hạng tử có bậc cao nhất trong các hạng tử có hệ số khác không. Khi đó số tự nhiên $n$ được gọi là **bậc** (degree) của đa thức, hạng tử $a_nx^n$ được gọi là **hạng tử đầu** (leading term), và $a_n$ cũng được gọi là **hệ số đầu** (leading coefficient). Đa thức có hệ số đầu bằng một (tức phần tử đơn vị) được gọi là đa thức **monic**. Bậc của đa thức không không được chỉ định, hoặc được quy ước là $-\infty$.

Ký hiệu $x$ xuất hiện trong ký hiệu đa thức được gọi là **biến không xác định** (indeterminate) của đa thức. Bản thân nó không có ý nghĩa giá trị, cũng không có miền giá trị. Nó chỉ dùng để đánh dấu vị trí của hệ số thông qua số mũ. Vì vậy, đa thức cũng có thể được viết như một dãy trên $R$

$$
(a_0,a_1,...,a_{n-1},a_n,0,0,\cdots).
$$

Tuy nhiên, một dãy như vậy chỉ được phép có hữu hạn nhiều hạng tử khác không. Nếu hai đa thức ứng với cùng một dãy hệ số, ta nói hai đa thức đó bằng nhau. Điều này tương đương với việc sau khi bổ sung các hạng tử có hệ số bằng không, các tổng hình thức của chúng hoàn toàn giống nhau. Trong phần dưới, ta không phân biệt ký hiệu tổng hình thức của các đa thức bằng nhau: nếu cần, độc giả có thể tự bổ sung các hệ số không còn thiếu.

Đôi khi cần thay một phần tử của vành vào biến không xác định trong đa thức. Chẳng hạn, giả sử $f(x)$ là đa thức trên $R$ và $a\in R$, thì kết quả thay $a$ vào đa thức $f(x)$ là $f(a)$. Ý nghĩa của nó là: trong tổng hình thức của đa thức, thay $x$ bằng $a$, ta thu được một biểu thức số học trong $R$, và $f(a)$ chính là kết quả tính biểu thức này trong $R$.

??? info "\"Đa thức\" và \"hàm đa thức\""
    Độc giả không nên nhầm lẫn hai khái niệm này. Đa thức chỉ là một dãy hệ số hữu hạn; nó không tự động trở thành một hàm. Dù thao tác thay phần tử của vành vào biến không xác định ở đây thật sự ánh xạ đa thức thành hàm đa thức, ánh xạ như vậy không nhất thiết là đơn ánh. Chẳng hạn, $f(x)=x^p-x$ với tư cách là đa thức trên trường $\mathbf F_p$ hiển nhiên không bằng đa thức không; nhưng $f(x)$ với tư cách là hàm đa thức $\mathbf F_p\rightarrow \mathbf F_p$ thì đồng nhất bằng không (tức là định lý nhỏ Fermat). Dù hai khái niệm khác nhau, nhiều khái niệm của hàm đa thức đều có thể khái quát sang trường hợp đa thức; chẳng hạn có thể phỏng theo các định nghĩa vi phân, tích phân bất định và hợp thành của hàm đa thức để định nghĩa [đạo hàm](../poly/intro.md#%E5%AF%BC%E6%95%B0), [tích phân bất định](../poly/intro.md#%E5%AF%BC%E6%95%B0), [hợp thành](../poly/intro.md#%E5%A4%8D%E5%90%88) hình thức của đa thức. Các phép toán hình thức này không phụ thuộc vào bất kỳ cấu trúc tôpô nào, nhưng nhiều quy tắc tính toán vẫn đúng.

Với các đa thức

$$
\begin{aligned}
f(x)&=a_0+a_1x+\cdots+a_{n-1}x^{n-1}+a_nx^n,\\
g(x)&=b_0+b_1x+\cdots+b_{n-1}x^{n-1}+b_nx^n,
\end{aligned}
$$

phép cộng đa thức được định nghĩa là

$$
f(x)+g(x) = (a_0+b_0)+(a_1+b_1)x+\cdots+(a_{n-1}+b_{n-1})x^{n-1}+(a_n+b_n)x^n,
$$

còn phép nhân đa thức được định nghĩa là

$$
f(x)g(x) = a_0b_0+(a_1b_0+a_0b_1)x+(a_2b_0+a_1b_1+a_0b_2)x^2+\cdots,
$$

trong đó hệ số của hạng tử $x^k$ là $\sum_{i=0}^ka_{k-i}b_i$. Dưới phép cộng và phép nhân được định nghĩa như vậy, có thể chứng minh tập tất cả đa thức trên $R$ tạo thành một vành, ký hiệu là $R[x]$.

Bậc của đa thức $f(x)$ được ký hiệu là $\deg f(x)$. Những đa thức có bậc bằng không là đa thức hằng; chúng cùng với đa thức không tương ứng với phép nhúng $R$ vào $R[x]$. Rõ ràng, $R$ có ước của không khi và chỉ khi $R[x]$ có ước của không.

???+ note "Định lý"
    Vành đa thức $R[x]$ là miền nguyên khi và chỉ khi $R$ là miền nguyên.

Trong vành đa thức $R[x]$ trên miền nguyên $R$, kết quả của phép cộng và phép nhân thỏa mãn

$$
\begin{aligned}
\deg(f(x)+g(x)) &\le \max\{\deg f(x),\deg g(x)\},\\
\deg(f(x)g(x)) &= \deg f(x) + \deg g(x).
\end{aligned}
$$

Ở đây đặt $\deg 0 = -\infty$. Vì vậy, các phần tử khả nghịch trong vành đa thức chỉ có thể là những phần tử khả nghịch nằm trong các đa thức hằng. Mọi đa thức bậc một trở lên đều không khả nghịch.

Phần thảo luận dưới đây chỉ giới hạn trong đa thức trên miền nguyên.

???+ info "Quy ước"
    Dưới đây, ta sẽ không phân biệt hai cách nói "đa thức trên vành $R$" và "đa thức trong vành đa thức $R[x]$". Chẳng hạn, nói đa thức bất khả quy trên vành $R$ nghĩa là đa thức bất khả quy trong vành $R[x]$. Hơn nữa, nếu $R$ là vành con của $S$, thì đa thức trên $R$ tự động trở thành đa thức trên $S$; điều này cũng sẽ không được nhắc lại.

<span id="&#22495;&#19978;&#30340;&#22810;&#39033;&#24335;&#29615;"></span>
### Vành đa thức trên trường

Trong các vành đa thức trên miền nguyên, vành có tính chất đơn giản nhất đương nhiên là vành đa thức trên trường. Vành đa thức $F[x]$ trên trường $F$ có hệ số cho phép chia, nên có thể định nghĩa phép chia có dư. Giả sử chuẩn của đa thức khác không $f(x)$ là $N(f(x))=\deg f(x)$. Khi đó với đa thức $f(x)$ và đa thức khác không $g(x)$ trong $F[x]$, ta có thể thực hiện phép chia có dư

$$
f(x)=g(x)q(x)+r(x),
$$

trong đó $q(x),r(x)\in F[x]$, và $r(x)=0$ hoặc $\deg r(x)<\deg g(x)$. Điều này cho thấy mọi vành đa thức trên trường đều là miền Euclid.

???+ note "Định lý"
    Vành đa thức $F[x]$ trên trường $F$ là miền Euclid, cũng là miền iđêan chính, và cũng là miền phân tích duy nhất.

Trong lập trình thi đấu, do vấn đề độ chính xác tính toán, người ta thường xét vành đa thức $\mathbf F_p[x]=(\mathbf Z/p\mathbf Z)[x]$; khi đó môđun $p$ cần là số nguyên tố. Vành như vậy cho phép thực hiện các phép toán như thuật toán Euclid. Tuy nhiên, vành đa thức $(\mathbf Z/n\mathbf Z)[x]$ ứng với môđun tùy ý $n$ thậm chí còn không phải miền nguyên.

Việc phép chia có dư đúng kéo theo nghiệm của đa thức luôn tương ứng với một nhân tử bậc nhất của nó.

???+ abstract "Nghiệm"
    **Nghiệm** (root) của đa thức $f(x)$ là phần tử $\xi\in F$ làm cho $f(\xi)=0$.

???+ note "Định lý"
    Với đa thức $f(x)$ trên trường $F$ và phần tử $\xi\in F$ trong trường, $\xi$ là nghiệm của $f(x)$ khi và chỉ khi $f(x)$ có nhân tử bậc nhất $(x-\xi)$.

??? note "Chứng minh"
    Phép chia có dư cho thấy tồn tại $q(x),r(x)$ sao cho $f(x)=q(x)(x-\xi)+r(x)$ và $\deg r(x)<\deg(x-\xi)=1$. Do đó $r(x)$ là đa thức hằng hoặc đa thức không; đặt $r(x)=c$, ta có $f(x)=q(x)(x-\xi)+c$. Thay $x=\xi$ vào, suy ra $0=f(\xi)=c$, tức là $f(x)=q(x)(x-\xi)$.

Khái niệm nghiệm có thể được khái quát cho trường hợp nghiệm bội.

???+ abstract "Nghiệm bội"
    Nếu đa thức $f(x)$ có nhân tử $(x-\xi)^k$, và $(x-\xi)^{k+1}$ không chia hết $f(x)$, thì $\xi$ được gọi là **nghiệm bội $k$** (root of multiplicity $k$) của $f(x)$. Nếu $k>1$, nghiệm $\xi$ được gọi là **nghiệm bội** (multiple root) của $f(x)$; nếu $k=1$, nghiệm $\xi$ được gọi là **nghiệm đơn** (simple root) của $f(x)$.

???+ note "Định lý"
    Nếu đa thức $f(x)$ trên trường $F$ có các nghiệm (có thể lặp) $\xi_1,\cdots,\xi_k$, thì nó nhất định có nhân tử $(x-\xi_1)\cdots(x-\xi_k)$. Hơn nữa, nếu đa thức $f(x)$ trên trường $F$ có bậc $n$, thì nó có nhiều nhất $n$ nghiệm tính cả bội số.

??? note "Chứng minh"
    Chỉ cần lưu ý rằng $F[x]$ là miền phân tích duy nhất.

Dù định lý phân tích duy nhất đúng với đa thức trên trường, nói chung không có cách tổng quát để phán đoán một đa thức cho trước có khả quy hay không. Trường hợp bậc tương đối nhỏ thì dễ hơn. Chẳng hạn, mọi đa thức bậc nhất đều là đa thức bất khả quy. Trên những trường đặc biệt, mọi đa thức bất khả quy đều là đa thức bậc nhất. Những trường như vậy được gọi là [trường đóng đại số](./field-theory.md#%E4%BB%A3%E6%95%B0%E9%97%AD%E5%9F%9F). Trên những trường như vậy, mọi đa thức không đồng nhất bằng hằng số khác không đều có nghiệm, nên mọi đa thức bậc lớn hơn một đều có thể tiếp tục phân tích. Một ví dụ là trường số phức $\mathbf C$. Còn trên trường số thực $\mathbf R$, tồn tại đa thức bậc hai bất khả quy; trên trường số hữu tỉ $\mathbf Q$, cấu trúc đa thức bất khả quy còn phức tạp hơn. Trang [lý thuyết trường](./field-theory.md) có thảo luận thêm về đa thức trên trường số hữu tỉ và trường hữu hạn.

Các kết luận trên đều nói về đa thức trên trường. Đa thức trên miền nguyên tổng quát hơn thường có thể được chuyển về trường hợp như vậy.

Tiếp theo xét vành đa thức $R[x]$ trên miền phân tích duy nhất $R$. Nếu tính trực tiếp trong $R[x]$, vì hệ số thường không chia được, nhiều phép toán bị hạn chế. Ta mở rộng $R$ thành trường phân thức $F$ của nó, rồi xét phân tích đa thức $f(x)$ trong $R[x]$ bên trong $F[x]$. Đã biết $F[x]$ là miền phân tích duy nhất, nên có thể từ phân tích của $f(x)$ trong $F[x]$ suy ngược ra phân tích trong $R[x]$. May mắn là ý tưởng này luôn khả thi.

???+ note "Bổ đề Gauss"
    Với miền phân tích duy nhất $R$ và trường phân thức $F$ của nó, nếu $f(x)\in R[x]$ và trong $F[x]$ có $f(x)=A(x)B(x)$, thì tồn tại $s,t\in F$ sao cho $a(x)=sA(x)\in R[x]$, $b(x)=tB(x)\in R[x]$, và $f(x)=a(x)b(x)$. Do đó, nếu $f(x)$ bất khả quy trong $R[x]$, thì nó bất khả quy trong $F[x]$.

??? note "Chứng minh"
    Giả sử $f(x)\in R[x]$ khả quy trong $F[x]$, và $f(x)=A(x)B(x)$. Gọi $r_a$ và $r_b$ lần lượt là bội chung nhỏ nhất của các mẫu số của mọi hệ số trong $A(x)$ và $B(x)$; khi đó $\tilde a(x)=r_aA(x)$ và $\tilde b(x)=r_bB(x)$ đều là đa thức trên $R$. Đặt $r=r_ar_b$, ta có $rf(x)=\tilde a(x)\tilde b(x)$. Nếu $r$ là phần tử khả nghịch trong $R$, thì có thể lấy phân tích $f(x)=(r^{-1}\tilde a(x))\tilde b(x)$, hiển nhiên thỏa mãn yêu cầu của bổ đề.
    
    Ngược lại, nếu trong $r$ tồn tại nhân tử bất khả quy $p$, cần chứng minh có thể khử nhân tử này ở hai vế của đẳng thức, đồng thời bảo đảm mọi hệ số vẫn nằm trong miền nguyên $R$. Lưu ý rằng $p$ cũng là phần tử nguyên tố, do đó $(p)$ là iđêan nguyên tố. Lấy modulo $p$ ở cả hai vế đẳng thức, ta được đẳng thức đa thức trên $(R/(p))[x]$ là $0=\bar a(x)\bar b(x)$, trong đó $\bar a$ và $\bar b$ là các đa thức sau khi lấy modulo. Vì $R/(p)$ là miền nguyên, $(R/(p))[x]$ cũng là miền nguyên, nên có thể giả sử $\bar a(x)=0$. Điều này cho thấy tất cả hệ số của $\tilde a(x)$ đều chia hết cho $p$. Do đó có thể trực tiếp khử nhân tử $p$ ở hai vế của đẳng thức.
    
    Theo định nghĩa miền phân tích duy nhất, $r$ có nhiều nhất hữu hạn nhân tử bất khả quy như vậy, nên sau khi khử chúng hữu hạn lần, ta chuyển về trường hợp $r$ là phần tử khả nghịch trong $R$. Bổ đề được chứng minh.

???+ note "Hệ quả"
    Với miền phân tích duy nhất $R$ và trường phân thức $F$ của nó, nếu $f(x)\in R[x]$ và mọi hệ số khác không của $f(x)$ nguyên tố cùng nhau (tức là ước chung lớn nhất là phần tử đơn vị trong $R$), thì $f(x)$ bất khả quy trong $R[x]$ khi và chỉ khi $f(x)$ bất khả quy trong $F[x]$.

Nói cách khác, các phần tử bất khả quy trong vành đa thức hệ số nguyên $\mathbf Z[x]$ đều là phần tử bất khả quy trong $\mathbf Q[x]$. Một phương pháp hiệu quả để phán đoán đa thức hệ số nguyên có bất khả quy hay không là tiêu chuẩn Eisenstein. Theo bổ đề Gauss, tiêu chuẩn này cũng cung cấp phương pháp phán đoán đa thức hệ số hữu tỉ có bất khả quy hay không.

???+ note "Tiêu chuẩn Eisenstein"
    Cho đa thức hệ số nguyên bậc $n$, $f(x)=a_0+a_1x+\cdots+a_{n-1}x^{n-1}+a_nx^n$. Nếu tồn tại số nguyên tố $p$ thỏa mãn $p\mid a_i$ với mọi $i=0,1,\cdots,n-1$, đồng thời $p$ không chia hết $a_n$ và $p^2$ không chia hết $a_0$, thì đa thức $f(x)$ bất khả quy trên trường số hữu tỉ $\mathbf Q$. Nếu $\gcd(a_0,a_1,\cdots,a_n)=1$, thì đa thức $f(x)$ cũng bất khả quy trên vành số nguyên $\mathbf Z$.

??? note "Chứng minh"
    Dùng bổ đề Gauss, nếu đa thức $f(x)$ khả quy trên trường số hữu tỉ $\mathbf Q$, thì nó cũng khả quy trên vành số nguyên $\mathbf Z$. Giả sử $f(x)=b(x)c(x)$ là phân tích của nó trong $\mathbf Z[x]$. Lấy modulo số nguyên tố $p$ ở hai vế của đẳng thức, ta được phân tích trong $\mathbf F_p[x]$: $\overline{f}(x)=\overline{b}(x)\overline{c}(x)$. Nhưng điều kiện của định lý cho thấy $\overline{f}(x)=x^n$, nên tồn tại số nguyên $m$ sao cho $\overline b(x)=x^m$ và $\overline c(x)=x^{n-m}$, trong đó $0<m<n$. Vì vậy các hệ số hằng $b_0$ và $c_0$ của hai nhân tử $b(x)$ và $c(x)$ đều là bội của $p$. Do đó hệ số hằng $a_0=b_0c_0$ của $f(x)$ là bội của $p^2$. Điều này mâu thuẫn với điều kiện đã cho.

??? example "Ví dụ"
    1.  Đa thức $x^3-2$ bất khả quy trong $\mathbf Q[x]$. Chỉ cần áp dụng tiêu chuẩn Eisenstein với $p=2$.
    2.  Đa thức $x^4+1$ bất khả quy trong $\mathbf Q[x]$. Nếu không, $(x+1)^4+1=x^4+4x^3+6x^2+4x+2$ cũng khả quy. Nhưng áp dụng tiêu chuẩn Eisenstein với $p=2$ cho thấy đa thức sau bất khả quy.

Với miền phân tích duy nhất $R$, vì vành đa thức trên trường phân thức tương ứng $F$ là miền phân tích duy nhất, còn bổ đề Gauss cho thấy phân tích của đa thức trên trường phân thức $F$ và phân tích của đa thức trên miền nguyên ban đầu $R$ tương ứng với nhau, nên $R[x]$ cũng là miền phân tích duy nhất. Do đó ta có định lý sau:

???+ note "Định lý"
    Vành đa thức $R[x]$ là miền phân tích duy nhất khi và chỉ khi $R$ là miền phân tích duy nhất.

Ở đây $\mathbf Z[x]$ cung cấp ví dụ về miền phân tích duy nhất không phải miền iđêan chính. Chẳng hạn, trong $\mathbf Z[x]$, $(2,x)$ không phải là iđêan chính.

Có nhiều cách mở rộng vành đa thức thành các tập lớn hơn. Chẳng hạn, với vành đa thức $R[x]$ trên miền nguyên, có thể mở rộng nó thành trường phân thức, ký hiệu là $R(x)$. Trường phân thức này thường được gọi là **trường phân thức hữu tỉ** (field of rational fractions), trong đó phần tử có dạng cơ bản $\dfrac{f(x)}{g(x)}$, với $f(x)$ và $g(x)$ đều là đa thức.

<span id="&#22810;&#20803;&#22810;&#39033;&#24335;&#29615;"></span>
### Vành đa thức nhiều biến

Vành đa thức có thể được khái quát sang trường hợp có nhiều biến không xác định. Với vành giao hoán có đơn vị $R$, có thể định nghĩa vành đa thức trên $R$, tức vành đa thức một biến $R[x]$. Tiếp theo, có thể định nghĩa vành đa thức $R[x][y]$ trên $R[x]$, và có thể xem nó là vành đa thức hai biến $R[x,y]$ trên $R$. Từ đó, có thể quy nạp để định nghĩa vành đa thức $k$ biến $R[x_1,\cdots,x_k]$ trên $R$. Khi $R$ là miền nguyên, mọi vành đa thức nhiều biến trên nó đều là miền nguyên; tương tự, tính chất miền phân tích duy nhất cũng truyền sang mọi vành đa thức nhiều biến.

<span id="&#24418;&#24335;&#24130;&#32423;&#25968;&#29615;"></span>
### Vành chuỗi lũy thừa hình thức

Ta cũng có thể xét trường hợp tổng hình thức được phép có vô hạn nhiều hệ số khác không. **Chuỗi lũy thừa hình thức** (formal power series) trên vành giao hoán có đơn vị $R$ được định nghĩa là

$$
\sum_{k=0}^\infty a_kx^k=a_0+a_1x+a_2x^2+\cdots.
$$

Dùng cách nhất quán với vành đa thức $R[x]$, có thể định nghĩa phép cộng và phép nhân giữa các chuỗi lũy thừa. Khi đó các chuỗi lũy thừa hình thức cũng tạo thành một vành, ký hiệu là $R[[x]]$. Ở đây chuỗi lũy thừa hình thức không cần xét tính hội tụ hay phân kỳ, vì trên thực tế mỗi chuỗi lũy thừa hình thức chỉ là dãy hệ số của nó và không được gán thêm cấu trúc tôpô nào.

Cấu trúc của vành chuỗi lũy thừa hình thức rất thú vị. Trong vành đa thức trên miền nguyên, phần tử khả nghịch chỉ có thể là hằng số. Nhưng trong vành chuỗi lũy thừa hình thức, ta lại có

$$
(1-x)^{-1}=\sum_{k=0}^\infty x^k=1+x+x^2+\cdots.
$$

Hiện tượng này là phổ biến. Chỉ cần hệ số hằng $a_0$ của một chuỗi lũy thừa hình thức là phần tử khả nghịch trong $R$, thì $\sum_{k=0}^\infty a_kx^k$ cũng khả nghịch. Lý do là nếu đặt

$$
\left(\sum_{k=0}^\infty a_kx^k\right)\left(\sum_{k=0}^\infty b_kx^k\right)=1,
$$

thì khi viết ra hệ phương trình mà các hệ số cần thỏa mãn, ta có thể truy hồi để tìm biểu thức của $b_k$, trong đó chỉ cần dùng đến nghịch đảo của $a_0$.

Trên vành chuỗi lũy thừa hình thức có thể định nghĩa nhiều phép toán như lấy nghịch đảo, phép chia, nghịch đảo hợp thành, đạo hàm hình thức, hàm sơ cấp, v.v.; xem chi tiết tại [giới thiệu kỹ thuật đa thức](../poly/intro.md).

<span id="&#24418;&#24335;&#27931;&#26391;&#32423;&#25968;&#29615;"></span>
### Vành chuỗi Laurent hình thức

Vành chuỗi lũy thừa hình thức còn có thể được mở rộng thêm để cho phép các hạng tử bậc âm. **Chuỗi Laurent hình thức** (formal Laurent series) trên vành giao hoán có đơn vị $R$ được định nghĩa là

$$
\sum_{k=N}^\infty a_kx^k,
$$

trong đó $N\in\mathbf Z$. Vì vậy, chuỗi Laurent hình thức có thể có hữu hạn nhiều hạng tử bậc âm. Mở rộng phép cộng và phép nhân trước đó sang chuỗi Laurent hình thức, ta thu được vành chuỗi Laurent hình thức, ký hiệu là $R((x))$. Nếu $F$ là trường, thì $F((x))$ cũng là trường.

Vành chuỗi Laurent hình thức có ứng dụng trong [nghịch đảo Lagrange](../poly/lagrange-inversion.md).

<span id="&#20013;&#22269;&#21097;&#20313;&#23450;&#29702;"></span>
## Định lý số dư Trung Hoa

Đọc thêm: [định lý số dư Trung Hoa](../number-theory/crt.md)

Trong lý thuyết số, định lý số dư Trung Hoa thường được dùng để giải hệ phương trình đồng dư. Với vành giao hoán có đơn vị tổng quát, cũng có thể xây dựng định lý số dư Trung Hoa. Mỗi phương trình đồng dư tương đương với việc chỉ định ảnh của ẩn trong một vành thương nào đó; khi ấy định lý số dư Trung Hoa trong vành giao hoán có đơn vị tương đương với việc xác định phần tử của vành thông qua các ảnh trong những vành thương này.

Thảo luận này có thể chuyển thành ngôn ngữ hình thức. Với vành giao hoán có đơn vị, khác không $R$ và các iđêan $I_1,\cdots,I_n$ của nó, xét đồng cấu vành $\varphi:R\rightarrow R/I_1\times \cdots \times R/I_n$ ánh xạ $r$ đến $(r+I_1,\cdots,r+I_n)$. Trong đó, $r+I_i$ là lớp kề, còn $\times$ biểu thị tích trực tiếp của các vành:

???+ abstract "Tích trực tiếp"
    Với hai vành $R_1$ và $R_2$, trên tích trực tiếp $R_1\times R_2$ của các nhóm cộng của chúng, có thể định nghĩa phép nhân bằng cách nhân theo từng thành phần. Khi đó $R_1\times R_2$ trở thành một vành, gọi là **tích trực tiếp** (direct product) của hai vành $R_1$ và $R_2$, vẫn ký hiệu là $R_1\times R_2$.

Hạt nhân của đồng cấu $\varphi$ là $\ker\varphi=I_1\cap\cdots\cap I_n$. Câu hỏi mà định lý số dư Trung Hoa cần trả lời là ánh xạ như vậy toàn ánh dưới điều kiện nào.

Trong trường hợp số học, định lý đúng khi các môđun nguyên tố cùng nhau. Điều kiện này có thể được khái quát sang ngôn ngữ lý thuyết vành.

???+ abstract "Cùng nhau cực đại"
    Giả sử vành $R$ có các iđêan $I$ và $J$. Nếu $I+J=R$, thì $I$ và $J$ được gọi là **cùng nhau cực đại** (comaximal).

Trong trường hợp vành có đơn vị, nếu xét các iđêan chính $(a)$ và $(b)$, điều kiện này tương đương với việc tồn tại $x,y\in R$ sao cho $ax+by=1$, tương tự định lý Bézout khi hai số nguyên nguyên tố cùng nhau. Dùng định nghĩa này, có thể xây dựng **định lý số dư Trung Hoa** (Chinese remainder theorem) trên vành giao hoán có đơn vị hoàn toàn tương tự trường hợp vành số nguyên.

???+ note "Định lý số dư Trung Hoa"
    Giả sử vành giao hoán có đơn vị, khác không $R$ có các iđêan $I_1,\cdots,I_n$. Nếu chúng đôi một cùng nhau cực đại, thì đồng cấu vành $\varphi$ được định nghĩa ở trên là toàn ánh, hạt nhân của nó bằng tích của các iđêan này, $\ker\varphi=I_1\cap\cdots\cap I_n=I_1\cdots I_n$, do đó
    
    $$
    R/(I_1\cdots I_n)=R/(I_1\cap\cdots\cap I_n)\cong R/I_1\times\cdots\times R/I_n.
    $$

??? note "Chứng minh"
    Nội dung định lý khá phong phú, nhưng những kết luận còn cần chứng minh chỉ có hai: $\varphi$ là toàn ánh và $I_1\cap\cdots\cap I_n=I_1\cdots I_n$. Điểm then chốt là tận dụng điều kiện cùng nhau cực đại.
    
    Trước hết chứng minh trường hợp $n=2$. Vì các iđêan $I_1$ và $I_2$ cùng nhau cực đại, tức là $I_1+I_2=R$, nên phần tử đơn vị $1$ trong $R$ có thể viết dưới dạng $a_1+a_2$, trong đó $a_i\in I_i$. Vì $a_1\in I_1$ và $a_1=1-a_2\in 1+I_2$, nên $\varphi(a_1)=(I_1,1+I_2)$; tương tự, $\varphi(a_2)=(1+I_1,I_2)$. Do đó $(\varphi(a_2),\varphi(a_1))$ đóng vai trò tương tự một "cơ sở" trong không gian vectơ. Vì vậy, với ảnh tùy ý $(r_1+I_1,r_2+I_2)$, ta đều có thể tìm được nguyên ảnh dưới đồng cấu $\varphi$, là $r_1a_2+r_2a_1$. Điều này cho thấy $\varphi$ là toàn ánh.
    
    Còn cần chứng minh $I_1\cap I_2=I_1I_2$. Với vành tổng quát luôn có $I_1I_2\subseteq I_1\cap I_2$, điểm then chốt là chiều ngược lại. Với mọi $r\in I_1\cap I_2$, ta có $r=r(a_1+a_2)=ra_1+ra_2\in I_1I_2$. Do đó cũng có $I_1\cap I_2\subseteq I_1I_2$. Suy ra điều phải chứng minh.
    
    Với trường hợp $n>2$, cần dùng quy nạp toán học. Bước quy nạp then chốt là chứng minh rằng với các iđêan đôi một cùng nhau cực đại $I_1,\cdots,I_n$, luôn có $I_1$ và $I_2\cdots I_n$ cùng nhau cực đại. Vì $I_1$ cùng nhau cực đại với từng $I_2,\cdots,I_n$, nên với mỗi $i=2,\cdots,n$ đều tồn tại $a_i\in I_1$ và $b_i\in I_i$ sao cho $1=a_i+b_i$. Do đó $1=(a_2+b_2)\cdots(a_n+b_n)$. Vì vậy $1\in (b_2\cdots b_n)+I_1\subseteq I_1+(I_2\cdots I_n)$. Điều này cho thấy các iđêan $I_1$ và $I_2\cdots I_n$ cùng nhau cực đại.

<span id="&#24212;&#29992;lagrange-&#25554;&#20540;&#20844;&#24335;"></span>
### Ứng dụng: công thức nội suy Lagrange

Đọc thêm: [nội suy Lagrange](../numerical/interp.md#lagrange-%E6%8F%92%E5%80%BC%E6%B3%95), [nội suy nhanh đa thức](../poly/multipoint-eval-interpolation.md#%E5%A4%9A%E9%A1%B9%E5%BC%8F%E7%9A%84%E5%BF%AB%E9%80%9F%E6%8F%92%E5%80%BC)

Bài toán nội suy (interpolation) là: cho một dãy giá trị tại các điểm $\{(x_i,y_i)\}_{i=1}^n$, tìm đa thức $f(x)$ trên trường $F$ sao cho $f(x_i)=y_i$ với mọi $i=1,\cdots,n$. Tất nhiên, ta giả sử các $x_i$ đôi một khác nhau. Công thức nội suy Lagrange cho nghiệm tổng quát của loại bài toán này.

Với đa thức $f(x)$ trên trường $F$, điều kiện $f(x_i)=y_i$ tương đương với việc $x_i$ là một nghiệm của đa thức $f(x)-y_i$, do đó tương đương với $(x-x_i)\mid(f(x)-y_i)$, tức là $f(x)\equiv y_i\pmod{x-x_i}$. Vì vậy, bài toán nội suy tương đương với việc giải hệ phương trình đồng dư

$$
\begin{cases}
f(x)\equiv y_1&\pmod{x-x_1},\\
f(x)\equiv y_2&\pmod{x-x_2},\\
\cdots\\
f(x)\equiv y_n&\pmod{x-x_n}.
\end{cases}
$$

Các đa thức bậc nhất $\{x-x_i\}_{i=1}^n$ đôi một nguyên tố cùng nhau. Theo định lý số dư Trung Hoa, nghiệm của bài toán phải có dạng

$$
f(x)=\sum_{i=1}^ny_iM_i(x),
$$

trong đó $M_i(x)=m_i(x)\prod_{j\neq i}(x-x_j)$ và $M_i(x)\equiv 1\pmod{x-x_i}$. Theo tính tương đương đã suy ra ở trên, điều này tương đương với $M_i(x_i)=1$, tức là

$$
m_i(x_i)\prod_{j\neq i}(x_i-x_j) = 1.
$$

Ta có thể lấy $m_i(x)$ là đa thức hằng, tức là

$$
m_i(x) = \frac{1}{\prod_{j\neq i}(x_i-x_j)}.
$$

Từ đó thu được công thức nội suy Lagrange

$$
f(x)=\sum_{i=1}^ny_i\frac{\prod_{j\neq i}(x-x_j)}{\prod_{j\neq i}(x_i-x_j)}.
$$

Nói chung, khi khái quát phương pháp này, còn có thể suy ra [công thức nội suy Hermite](https://en.wikipedia.org/wiki/Hermite_interpolation), cho phép ràng buộc thêm một số giá trị đạo hàm của đa thức tại từng điểm.

<span id="&#24212;&#29992;&#25972;&#25968;&#21516;&#20313;&#31867;&#30340;&#20056;&#27861;&#32676;"></span>
### Ứng dụng: nhóm nhân của các lớp đồng dư số nguyên

Đọc thêm: [căn nguyên thủy](../number-theory/primitive-root.md), [định lý cơ bản về nhóm Abel hữu hạn sinh](./group-theory.md#%E5%88%86%E7%B1%BB%E5%AE%9A%E7%90%86)

Là một ứng dụng của định lý số dư Trung Hoa và các nội dung liên quan đến lý thuyết nhóm, ở đây ta thảo luận cấu trúc của nhóm nhân modulo $n$ của số nguyên. Mục này lược bỏ ký hiệu gạch ngang của lớp đồng dư.

**Nhóm nhân modulo $n$ của số nguyên** (multiplicative group of integers modulo $n$) là $(\mathbf Z/n\mathbf Z)^\times$, tức là nhóm nhân của các phần tử khả nghịch trong vành thương $\mathbf Z/n\mathbf Z$ (cũng gọi là nhóm đơn vị). Cấp của nhóm $(\mathbf Z/n\mathbf Z)^\times$ là $\varphi(n)$, vì điều kiện cần và đủ để một lớp đồng dư có nghịch đảo chính là nguyên tố cùng nhau với $n$. Ở đây $\varphi(n)$ là [hàm Euler](../number-theory/euler-totient.md). Hơn nữa, nhóm $(\mathbf Z/n\mathbf Z)^\times$ luôn là nhóm Abel.

Theo định lý cơ bản của số học, môđun $n$ có thể phân tích thành tích các lũy thừa của các số nguyên tố khác nhau:

$$
n=p_1^{\alpha_1}\cdots p_s^{\alpha_s}.
$$

Dễ kiểm tra rằng với các iđêan của vành số nguyên, điều kiện các iđêan cùng nhau cực đại tương đương với việc các phần tử sinh của chúng nguyên tố cùng nhau. Vì vậy, áp dụng định lý số dư Trung Hoa, ta thu được

$$
\mathbf Z/n\mathbf Z\cong\mathbf Z/p_1^{\alpha_1}\mathbf Z\times\cdots\times\mathbf Z/p_s^{\alpha_s}\mathbf Z.
$$

Đẳng cấu vành kéo theo cấu trúc nhân tương ứng cũng đẳng cấu, nên

$$
(\mathbf Z/n\mathbf Z)^\times\cong(\mathbf Z/p_1^{\alpha_1}\mathbf Z)^\times\times\cdots\times(\mathbf Z/p_s^{\alpha_s}\mathbf Z)^\times.
$$

Điều này cho thấy $\varphi(n)=\varphi(p_1^{\alpha_1})\cdots\varphi(p_s^{\alpha_s})$, tức là hàm Euler là hàm nhân tính.

Do đó, để nghiên cứu trường hợp môđun tổng quát, chỉ cần xét trường hợp môđun là lũy thừa số nguyên tố $p^k$. Với trường hợp lũy thừa số nguyên tố, cần xét riêng hai trường hợp $p=2$ và $p$ là số nguyên tố lẻ:

-   Với trường hợp $p=2$, kiểm tra trực tiếp cho thấy $(\mathbf Z/2\mathbf Z)^\times\cong C_1$ và $(\mathbf Z/4\mathbf Z)^\times\cong C_2$. Với trường hợp $k\ge3$, có $(\mathbf Z/2^k\mathbf Z)^\times\cong C_2\times C_{2^{k-2}}$.

    ??? note "Chứng minh"
        Dùng định lý nhị thức để tính trực tiếp, ta biết
        
        $$
        \begin{aligned}
        5^{2^{k-2}}=(1+2^2)^{2^{k-2}}&\equiv 1\pmod {2^k},\\
        5^{2^{k-3}}=(1+2^2)^{2^{k-3}}&\equiv 1+2^{k-1}\pmod {2^k}.
        \end{aligned}
        $$
        
        Vì vậy, $5$ là phần tử cấp $2^{k-2}$ trong $(\mathbf Z/2^k\mathbf Z)^\times$. Đồng thời, $-1$ và $5^{2^{k-3}}$ là hai phần tử cấp hai khác nhau, nên $-1\notin\langle 5\rangle$. Do đó $\langle-1\rangle$ và $\langle 5\rangle$ có giao tầm thường, và theo định lý đẳng cấu thứ hai ta có
        
        $$
        (\mathbf Z/2^k\mathbf Z)^\times\cong\langle-1\rangle\times\langle 5\rangle\cong C_2\times C_{2^{k-2}}.
        $$
-   Với trường hợp $p$ là số nguyên tố lẻ, có thể chứng minh $(\mathbf Z/p^k\mathbf Z)^\times$ đẳng cấu với nhóm cyclic $C_{\varphi(p^k)}$.

    ??? note "Chứng minh"
        Để chứng minh $(\mathbf Z/p^k\mathbf Z)^\times$ là nhóm cyclic, theo định lý cơ bản về nhóm Abel hữu hạn, chỉ cần chứng minh mỗi nhóm con Sylow $q$ của nó đều là nhóm cyclic. Trước hết, với nhóm con Sylow $p$, tính trực tiếp cho thấy
        
        $$
        \begin{aligned}
        (1+p)^{p^{k-1}} &\equiv 1\pmod{p^k},\\
        (1+p)^{p^{k-2}} &\equiv 1+p^{k-1}\pmod{p^k}.
        \end{aligned}
        $$
        
        Do đó $(1+p)$ là phần tử cấp $p^{k-1}$. Nói cách khác, nhóm con Sylow $p$ duy nhất của $(\mathbf Z/p^k\mathbf Z)^\times$ là nhóm cyclic $\langle 1+p\rangle$.
        
        Với các nhóm con Sylow $q$ khác ($q\neq p$), có thể dùng đồng cấu nhóm để chuyển về trường hợp $k=1$. Xét đồng cấu nhóm $\varphi:(\mathbf Z/p^k\mathbf Z)^\times\rightarrow(\mathbf Z/p\mathbf Z)^\times$, ánh xạ lớp kề $r+p^k\mathbf Z$ đến lớp kề $r+p\mathbf Z$. Kích thước hạt nhân của ánh xạ này là $p^{k-1}$, nên khi hạn chế ánh xạ $\varphi$ trên nhóm con Sylow $q$ của $(\mathbf Z/p^k\mathbf Z)^\times$ ($q\neq p$), hạt nhân của ánh xạ hạn chế đều tầm thường. Vì vậy, nhóm con Sylow $q$ này đẳng cấu với ảnh của ánh xạ, tức là một nhóm con Sylow $q$ của $(\mathbf Z/p\mathbf Z)^\times$. Do đó chỉ cần chứng minh mọi nhóm con Sylow $q$ của $(\mathbf Z/p\mathbf Z)^\times$ đều là nhóm cyclic.
        
        Cuối cùng, chứng minh mọi nhóm con Sylow $q$ của $(\mathbf Z/p\mathbf Z)^\times$ đều là nhóm cyclic. Vì $(\mathbf Z/p\mathbf Z)^\times$ là nhóm Abel hữu hạn, có thể phân tích nó theo các nhân tử bất biến thành
        
        $$
        C_{n_1}\times\cdots\times C_{n_r}.
        $$
        
        Ở đây $n_1\mid n_2\mid \cdots \mid n_r$. Vì vậy, trong mỗi nhân tử tích trực tiếp đều có $n_1$ phần tử có cấp chia $n_1$. Nếu $r>1$, thì sẽ có nhiều hơn hẳn $n_1$ phần tử thỏa mãn phương trình $x^{n_1}=1$. Nhưng $\mathbf Z/p\mathbf Z$ là trường, và đa thức bậc $n_1$ trên trường có nhiều nhất $n_1$ nghiệm, nên $r=1$. Nói cách khác, $(\mathbf Z/p\mathbf Z)^\times\cong C_{p-1}$.
        
        Như vậy đã chứng minh $(\mathbf Z/p^k\mathbf Z)^\times\cong C_{p^{k-1}}\times C_{p-1}=C_{\varphi(p^{k})}$.

Cấu trúc của nhóm nhân trong trường hợp môđun tổng quát cũng được xác định từ đó. Từ kết quả hiện có, có thể biết nhóm nhân modulo $n$ của số nguyên là nhóm cyclic khi và chỉ khi môđun $n$ nhận một trong các dạng

$$
1,2,4,p^k,2p^k
$$

trong đó $p$ là số nguyên tố lẻ; nếu không, nhóm nhân modulo $n$ của số nguyên có nhóm con $C_2\times C_2$, nên không thể là nhóm cyclic. Khi nhóm nhân là nhóm cyclic, phần tử sinh của nhóm nhân được gọi là **căn nguyên thủy** (primitive root) modulo đó. Vì vậy, định lý ở đây chính là điều kiện cần và đủ để căn nguyên thủy tồn tại.

Tất nhiên, phân tích cấu trúc nhóm nhân chứa nhiều thông tin hơn điều kiện tồn tại căn nguyên thủy. Nó phản ánh rõ ràng cấp của các phần tử khác nhau trong nhóm nhân. Trong nhóm $(\mathbf Z/n\mathbf Z)^\times$, phần tử $x$ thỏa mãn $x^k=1$, tức là nghiệm của phương trình đồng dư $x^k\equiv 1\pmod n$, được gọi là **căn bậc $k$ của đơn vị modulo $n$** ($k$-th root of unity modulo $n$); phần tử có cấp đúng bằng $k$ được gọi là **căn nguyên thủy bậc $k$ của đơn vị modulo $n$** (primitive $k$-th root of unity modulo $n$). Dựa vào cấu trúc của nhóm nhân, ta có thể tính chính xác sự tồn tại và số lượng của các căn đơn vị này. Cuối cùng, bội chung nhỏ nhất của cấp của mọi phần tử trong nhóm $(\mathbf Z/n\mathbf Z)^\times$, tức là số nguyên dương nhỏ nhất $k$ sao cho mọi $x\in (\mathbf Z/n\mathbf Z)^\times$ đều thỏa mãn $x^k=1$, khi xem như hàm của $n$, chính là [hàm Carmichael](../number-theory/primitive-root.md#carmichael-%E5%87%BD%E6%95%B0). Một loạt tính chất của nó đều có thể thu được từ cấu trúc của nhóm nhân.

<span id="&#21442;&#32771;&#36164;&#26009;&#21644;&#27880;&#37322;"></span>
## Tài liệu tham khảo và chú thích

-   Dummitt, D.S. and Foote, R.M. (2004) Abstract Algebra. 3rd Edition, John Wiley & Sons, Inc.
-   [Quadratic integer - Wikipedia](https://en.wikipedia.org/wiki/Quadratic_integer)
-   [Formal power series - Wikipedia](https://en.wikipedia.org/wiki/Formal_power_series)
-   [Multiplicative group of integers modulo $n$ - Wikipedia](https://en.wikipedia.org/wiki/Multiplicative_group_of_integers_modulo_n)

[^ideal-history]: <https://en.wikipedia.org/wiki/Ideal_(ring_theory)#History>

[^simple-ring]: Tương tự trường hợp nhóm, những vành như vậy được gọi là **vành đơn** (simple ring). Vành đơn giao hoán chỉ có thể là trường, còn trường hợp vành đơn không giao hoán thì phức tạp hơn nhiều.

[^gcd-domain]: Miền nguyên trong đó ước chung lớn nhất tồn tại được gọi là [miền ước chung lớn nhất](https://en.wikipedia.org/wiki/GCD_domain).

[^ring-theory-history]: Có thể xem lịch sử tóm tắt của lý thuyết vành tại [đây](https://mathshistory.st-andrews.ac.uk/HistTopics/Ring_theory/).
