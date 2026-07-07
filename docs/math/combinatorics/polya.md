author: Wajov, Early0v0, Enter-tainer, Great-designer, iamtwz, Ir1d, MegaOwIer, mgt, StudyingFather, Tiphereth-A, warzone-oier, Xeonacid, c-forrest

Kiến thức cần có: [hoán vị và sắp xếp](../permutation.md)

<span id="mở-đầu"></span>
## Mở đầu

Nguyên lý đếm Pólya thường được dùng để giải các bài toán đếm liên quan đến những đối tượng "khác nhau về bản chất".

???+ info "Bài viết này có thể liên quan đến nội dung lý thuyết nhóm"
    Bài viết này có thể dùng một số nội dung của lý thuyết nhóm. Các khái niệm nhóm xuất hiện trong bài sẽ được giải thích ngắn gọn để người đọc chưa quen vẫn có thể hiểu và áp dụng nguyên lý đếm Pólya. Với phát biểu và thảo luận chặt chẽ hơn về lý thuyết nhóm, xem thêm các chương [khái niệm cơ bản của đại số trừu tượng](../algebra/basic.md), [lý thuyết nhóm](../algebra/group-theory.md), v.v.

??? info "\"Nhóm đối xứng không gian\", \"nhóm đối xứng\" và \"nhóm hoán vị\""
    Trong bài này sẽ không tránh khỏi việc dùng đồng thời ba tên gọi nhóm trên. Dù dễ gây nhầm lẫn, chúng thật sự chỉ các khái niệm khác nhau. Với một cấu trúc hình học cho trước, phép đối xứng trên nó là một phép biến đổi hình học có thể đưa nó trùng lại với chính nó; nhóm đối xứng không gian (symmetry group) là tập hợp các phép đối xứng đó. Nhóm đối xứng (symmetric group) là tập hợp tất cả các hoán vị trên một tập cho trước. Nhóm hoán vị (permutation group) là một nhóm con của nhóm đối xứng, tức một nhóm gồm một số hoán vị, không nhất thiết là toàn bộ. Phần sau sẽ giải thích cách biểu diễn nhóm đối xứng không gian của một cấu trúc hình học cho trước dưới dạng nhóm hoán vị và dùng nó cho bài toán đếm.

<span id="bổ-đề-burnside"></span>
## Bổ đề Burnside

Đọc thêm: [bổ đề Burnside](../algebra/group-theory.md#bổ-đề-burnside)

Nguyên lý đếm Pólya là một ứng dụng và mở rộng của bổ đề Burnside. Trước khi giới thiệu nguyên lý đếm Pólya, cần nhắc lại ngắn gọn nội dung của bổ đề Burnside.

Để rút ra quy luật tổng quát, trước hết xét một ví dụ đơn giản.

???+ example "Tô màu vòng cổ"
    Có một vòng cổ gồm bốn hạt, mỗi hạt có thể tô màu đỏ hoặc xanh. Hỏi có bao nhiêu vòng cổ khác nhau về bản chất? (Nếu hai cách tô có thể trùng nhau sau khi quay vòng cổ, chúng được xem là giống nhau.)

??? example "Lời giải và phân tích"
    Bài toán đủ đơn giản để giải bằng liệt kê. Có tổng cộng $4$ hạt, mỗi hạt có $2$ màu, nên tổng số cách tô màu có thể là $2^4=16$. Gom các cách tô có thể thu được từ nhau bằng phép quay vào cùng một nhóm, sẽ có tổng cộng $6$ nhóm như hình dưới. Trong đó, mã của một cách tô biểu diễn màu các hạt theo chiều kim đồng hồ bắt đầu từ hạt ở góc trái dưới; $B$ là xanh, $R$ là đỏ; các mã thuộc cùng nhóm có cùng màu nền.
    
    ![Tô màu vòng cổ](../images/necklaces.svg)
    
    Từ ví dụ này, để tính số loại tô màu khác nhau về bản chất, điều then chốt là biết mỗi kiểu tô màu cùng bản chất tương ứng với bao nhiêu cách tô khác nhau. Nói cách khác, cần hiểu kích thước của từng nhóm trong hình trên.
    
    Các cách tô nằm trong cùng một nhóm là các cách có thể biến đổi qua lại bằng phép quay. Có tổng cộng $4$ phép quay:
    
    $$
    G=\{r_0,r_1,r_2,r_3\},
    $$
    
    lần lượt biểu diễn quay $0,1,2,3$ lần. Quay $0$ lần chính là giữ nguyên.
    
    Trước hết xét nhóm chứa cách tô $RRBB$. Áp dụng bốn phép toán đó lên nó, lần lượt được
    
    $$
    RRBB, RBBR, BBRR, BRRB.
    $$
    
    Bốn cách tô này đôi một khác nhau, nên nhóm này có $4$ phần tử.
    
    Tiếp theo xét nhóm chứa cách tô $BRBR$. Áp dụng bốn phép toán tương tự, lần lượt được
    
    $$
    BRBR, RBRB, BRBR, RBRB.
    $$
    
    Lúc này kết quả quay hai lần trùng với không quay, và quay ba lần trùng với quay một lần. Vì vậy nhóm này chỉ có $2$ phần tử.
    
    Nếu xét các nhóm chứa $BBBB$ và $RRRR$, áp dụng bất kì phép quay nào cũng cho lại chính chúng. Do đó mỗi nhóm chỉ có $1$ phần tử.
    
    Gọi $x$ là một cách tô, $Gx$ là tập các mã màu thu được sau khi tác động các phép toán lên $x$. Từ ví dụ trên có thể rút ra rằng tác động của $G$ lên $x$ có một dạng "chu kỳ" nào đó.
    
    Gọi $|G|$ là tổng số phép toán. Tính "chu kỳ" này nghĩa là nếu có $m$ phép toán khác nhau trong $G$ biến cách tô $x$ thành chính nó, thì kết quả của $x$ dưới các phép toán đó sẽ lặp lại $m$ lần. Vì vậy $x$ có tổng cộng $|G|/m$ kết quả khác nhau dưới các phép toán, và đó chính là kích thước nhóm chứa $x$.
    
    Trong ví dụ này, vì chỉ có quay không lần $r_0$ biến $RRBB$ thành chính nó, nên kích thước nhóm của nó là $4/1=4$; còn quay không lần $r_0$ và quay hai lần $r_2$ đều biến $BRBR$ thành chính nó, nên kích thước nhóm là $4/2=2$; với $BBBB$, mọi phép quay đều biến nó thành chính nó, nên kích thước nhóm là $4/4=1$.
    
    Trong phần dưới, ký hiệu $G_x$ là tập các phép toán biến $x$ thành chính nó, nên $|G_x|$ chính là $m$ ở trên. Khi đó kích thước quỹ đạo chứa $x$ là $|G|/|G_x|$. Để tính số nhóm các cách tô, chỉ cần duyệt mọi cách tô có thể $x\in X$, rồi gán trọng số $1/|Gx|$ cho cách tô $x$ nằm trong nhóm có kích thước $|Gx|$. Khi đó số nhóm là
    
    $$
    |X/G|=\sum_{x\in X}\frac{1}{|Gx|}=\sum_{x\in X}\frac{|G_x|}{|G|}.
    $$
    
    Dạng công thức hiện tại chưa tiện áp dụng. Ký hiệu $gx$ là kết quả khi áp dụng phép toán $g\in G$ lên cách tô $x\in X$. Khi đó tập $G_x$ nêu trên là $\{g\in G:gx=x\}$, nên đổi thứ tự lấy tổng được
    
    $$
    \begin{aligned}
    \sum_{x\in X}|G_x| 
    &=\sum_{x\in X}|\{g\in G:gx=x\}|\\
    &=\sum_{x\in X}\sum_{g\in G}[gx=x]\\
    &=\sum_{g\in G}\sum_{x\in X}[gx=x]\\
    &=\sum_{g\in G}|\{x\in X:gx=x\}|\\
    &=\sum_{g\in G}|X^g|.
    \end{aligned}
    $$
    
    Trong đó $[\cdot]$ là ngoặc Iverson. Sau khi đổi thứ tự tổng, $X^g=\{x\in X:gx=x\}$ là tập các cách tô $x$ bất biến dưới phép toán $g$. Nói ngắn gọn, đó là tập điểm bất động của $g$.
    
    Sau các thảo luận trên, số nhóm có thể viết thành
    
    $$
    |X/G|=\frac{1}{|G|}\sum_{g\in G}|X^g|.
    $$
    
    Nghĩa là số nhóm bằng số điểm bất động trung bình của các phép quay.
    
    Áp dụng kết quả này để tính lại số cách tô vòng cổ. Các điểm bất động của từng phép quay được liệt kê như sau.
    
    | Phép toán |        Điểm bất động         |
    | :------: | :--------------------------: |
    |  $r_0$   |             $X$              |
    |  $r_1$   |       $\{BBBB,RRRR\}$        |
    |  $r_2$   | $\{BBBB,BRBR,RBRB,RRRR\}$    |
    |  $r_3$   |       $\{BBBB,RRRR\}$        |
    
    Do đó số nhóm bằng
    
    $$
    \frac{16+2+4+2}{4} = 6.
    $$
    
    Kết quả này trùng với phần trước.

Từ ví dụ trên có thể rút ra kết quả tổng quát để giải lớp bài toán đếm này. Để tiện thảo luận, bài viết xét ngữ cảnh là bài toán tô màu; kết quả này cũng áp dụng được cho các ngữ cảnh khác, và cuối bài sẽ có ví dụ tương ứng.

Bài toán tô màu là: cho một cấu trúc, tô màu các đỉnh của nó sẽ tạo ra các cách tô khác nhau. Cấu trúc này có một loại đối xứng nào đó, khiến các cách tô nhìn có vẻ khác nhau lại có thể biến đổi qua lại bằng một dãy phép đối xứng. Những cách tô có thể biến đổi qua lại như vậy được gọi là giống nhau về bản chất. Bài toán yêu cầu số cách tô khác nhau về bản chất.

Theo phân tích trong ví dụ, để giải bài toán như vậy, trước hết cần xét cấu trúc cho trước có những phép đối xứng nào. Tập các phép đối xứng đó, ký hiệu $G$, gọi là nhóm đối xứng không gian của cấu trúc. Trong ứng dụng thực tế, đa số trường hợp không cần hiểu định nghĩa nhóm, chỉ cần liệt kê đầy đủ và không trùng lặp mọi phép đối xứng không gian. Phần sau sẽ phân tích cấu trúc của một số nhóm đối xứng không gian thường gặp và giải thích định nghĩa nhóm ở đó.

Ký hiệu tập tất cả các cách tô là $X$, một cách tô riêng lẻ là $x$. Kết quả tác động của phép toán $g\in G$ lên cách tô $x\in X$ là $gx$. Khi đó tập tất cả kết quả thu được bằng cách tác động một phép toán nào đó lên $x$ là $Gx=\{gx:g\in G\}$, gọi là quỹ đạo của $x$ dưới tác động của nhóm $G$. Các cách tô khác nhau trong cùng một quỹ đạo chính là những cách "giống nhau về bản chất" trong loại bài toán này. Vì thế số cách tô khác nhau về bản chất tương đương với số quỹ đạo khác nhau.

Phân tích trong ví dụ có thể mở rộng sang trường hợp tổng quát.

???+ note "Bổ đề Burnside"
    Cho nhóm $G$ tác động lên tập $X$, số quỹ đạo khác nhau là
    
    $$
    |X/G|=\frac{1}{|G|}\sum_{g\in G}|X^g|.
    $$
    
    Tại đây, $X^g=\{x\in X:gx=x\}$ là tập điểm bất động dưới tác động của $g\in G$.

Chứng minh gần như chỉ là chép lại phân tích trong ví dụ trên. Tuy nhiên, ví dụ dùng một quan sát: kết quả tác động của nhóm $G$ lên một phần tử riêng lẻ $x$ có một dạng "chu kỳ", nên số lần lặp của chu kỳ bằng số phép toán biến $x$ thành chính nó. Quan sát này đúng trong trường hợp tổng quát, nhưng vì cấu trúc của nhóm $G$ có thể phức tạp, "chu kỳ" của nó không nhất thiết trực quan như trong ví dụ. Phát biểu chặt chẽ quan sát này cần dùng [định lý quỹ đạo - ổn định tử (orbit-stabilizer theorem)](../algebra/group-theory.md#bộ-ổn-định) trong lý thuyết nhóm.

Khi áp dụng, chỉ cần liệt kê mọi phép đối xứng và cho biết số điểm bất động ứng với từng phép đối xứng là giải được bài toán đếm tương ứng. Dưới đây là một ứng dụng hơi phức tạp hơn.

???+ example "Tô màu lập phương"
    Dùng ba màu để tô một khối lập phương, hỏi có bao nhiêu phương án khác nhau về bản chất (hai phương án trùng nhau sau một phép quay trong không gian được xem là cùng một phương án).

??? example "Lời giải"
    Khối lập phương có $6$ mặt, mỗi mặt có $3$ cách tô, nên tổng cộng có $3^6$ cách tô, tức $|X|=3^6$. Ký hiệu nhóm đối xứng không gian của khối lập phương là $G$.
    
    ![](../images/cube.svg)
    
    Tiếp theo cần phân tích mọi phép toán trong $G$. Có thể chia chúng thành các loại sau (để tiện, gọi sáu mặt của khối lập phương là trước, sau, trên, dưới, trái, phải):
    
    -   Bất động: tức phép đồng nhất. Mọi cách tô trực tiếp đều bất biến dưới phép đồng nhất, nên $|X^g|=3^6$;
    -   Quay $90^\circ$ quanh trục nối tâm của hai mặt đối diện: có $3$ cách chọn cặp mặt đối diện và $2$ hướng quay, nên loại này có $6$ phép hoán vị. Giả sử chọn trục nối tâm mặt trước và mặt sau, để bất biến sau khi quay thì bốn mặt trên, dưới, trái, phải phải có cùng màu. Khi đó có $3$ vùng tô độc lập, nên $|X^g|=3^3$;
    -   Quay $180^\circ$ quanh trục nối tâm của hai mặt đối diện: có $3$ cách chọn cặp mặt đối diện, hướng quay không ảnh hưởng, nên loại này có $3$ phép hoán vị. Giả sử chọn trục nối tâm mặt trước và mặt sau, để bất biến thì mặt trên và dưới phải cùng màu, mặt trái và phải phải cùng màu. Khi đó có $4$ vùng tô độc lập, nên $|X^g|=3^4$;
    -   Quay $180^\circ$ quanh trục nối trung điểm của hai cạnh đối diện: có $6$ cách chọn cặp cạnh đối diện, hướng quay vẫn không ảnh hưởng, nên loại này có $6$ phép hoán vị. Giả sử chọn cặp cạnh đối diện là biên giữa mặt trước - trên và biên giữa mặt dưới - sau, thì để bất biến, mặt trước và trên phải cùng màu, mặt dưới và sau phải cùng màu, mặt trái và phải phải cùng màu. Khi đó có $3$ vùng tô độc lập, nên $|X^g|=3^3$;
    -   Quay $120^\circ$ quanh trục nối hai đỉnh đối diện: có $4$ cách chọn cặp đỉnh đối diện và $2$ hướng quay, nên loại này có $8$ phép hoán vị. Giả sử chọn đỉnh góc phải trên của mặt trước và đỉnh góc trái dưới của mặt sau làm cặp đỉnh đối diện, thì mặt trước, trên, phải phải cùng màu, và mặt sau, dưới, trái phải cùng màu. Khi đó có $2$ vùng tô độc lập, nên $|X^g|=3^2$.
    
    Vì vậy số cách tô khác nhau về bản chất là
    
    $$
    \frac{1\times3^6+6\times3^3+3\times3^4+6\times3^3+8\times3^2}{1+6+3+6+8}=57.
    $$

<span id="nguyên-lí-đếm-pólya"></span>
## Nguyên lý đếm Pólya

Trong phát biểu của bổ đề Burnside, không dùng tính chất rằng tập $X$ là toàn bộ các cách tô trên một cấu trúc nào đó. Phạm vi áp dụng của bổ đề Burnside không chỉ giới hạn ở bài toán đếm tô màu. Với bài toán tô màu, nguyên lý đếm Pólya cung cấp một cách tính chính xác hơn; có thể xem nó là ứng dụng của bổ đề Burnside tổng quát vào bài toán tô màu.

So với bổ đề Burnside, điểm cải tiến của nguyên lý đếm Pólya là cung cấp cách tính cụ thể kích thước tập điểm bất động $|X^g|$ trong bài toán đếm tô màu.

Ví dụ tô màu lập phương ở trên cho thấy điều này một cách trực quan. Với các phép đối xứng của khối lập phương, kích thước tập điểm bất động đều có dạng $m^{c(g)}$, trong đó $m$ là số màu, còn $c(g)$ là số vùng có thể tô độc lập dưới phép toán $g$. Quan sát này cũng đúng trong trường hợp tổng quát, nhưng cần làm rõ cách tính $c(g)$ với một $g$ cho trước.

Chọn một cách tô cho một cấu trúc, viết bằng ngôn ngữ toán học, là chọn một ánh xạ $f:X\rightarrow C$ từ tập các đối tượng có thể tô của cấu trúc (ví dụ hạt trong vòng cổ, mặt của lập phương) đến tập màu $C$. Vì vậy tập các cách tô là $C^X$. Nhóm đối xứng không gian $G$ của cấu trúc tác động lên cấu trúc, và tự nhiên cũng tác động lên tập $X$. Mỗi phép đối xứng như vậy luôn tương ứng với một song ánh trên tập $X$, tức một **hoán vị** (permutation).[^perm-group]

Bây giờ phân tích cấu trúc của tập điểm bất động $(C^X)^g$. Với $g$ cho trước, xem nó là một hoán vị trên $X$. Tương tự phân tích trong ví dụ, nếu vị trí $x$ trong $X$ có thể chuyển đến vị trí $y$ sau khi lặp hữu hạn lần phép toán $g$, thì với một điểm bất động $f\in (C^X)^g$, bắt buộc $f(x)=f(y)$. Theo ngôn ngữ quỹ đạo ở phần trước, vì vị trí $x$ và $y$ nằm trong cùng một quỹ đạo dưới tác động[^g-act] của $g$, chúng phải được tô cùng màu. Theo ngôn ngữ hoán vị, trong [phân tích thành chu trình](../permutation.md#biểu-diễn-bằng-chu-trình) của hoán vị $g$, vị trí $x$ và $y$ nằm trong cùng một chu trình nên phải tô cùng màu. Các chu trình khác nhau trong phân tích chu trình không nhất thiết phải cùng màu và có thể tô độc lập. Vì vậy số vùng có thể tô độc lập chính là $c(g)$, tức số chu trình trong phân tích chu trình của $g$.

Từ đó, số điểm bất động của phép toán $g$ là $|C|^{c(g)}$. Thay kết luận này vào bổ đề Burnside, thu được phiên bản không trọng số của **nguyên lý đếm Pólya** (Pólya enumeration theorem).

???+ note "Nguyên lý đếm Pólya (phiên bản không trọng số)"
    Cho nhóm $G$ tác động lên tập $X$, và cho tập màu $C$ có $m$ phần tử. Số cách tô khác nhau là
    
    $$
    |C^X/G|=\frac{1}{|G|}\sum_{g\in G}m^{c(g)},
    $$
    
    trong đó $m$ là số màu, còn $c(g)$ là số chu trình trong phân tích chu trình của biểu diễn hoán vị của phần tử $g\in G$.

??? info "Về ý nghĩa của nhóm $G$"
    Tại đây có lạm dụng ký hiệu một chút. Nếu nhóm $G$ tác động lên $X$, thì tác động nhóm trên tập cách tô $C^X$ cần được định nghĩa lại; bài viết không phân biệt riêng hai tác động này.

Như một ứng dụng đơn giản của nguyên lý đếm Pólya, xét lại các ví dụ phía trước.

??? example "Một cách giải khác cho bài toán tô màu vòng cổ"
    Đánh số bốn hạt là $1\sim 4$. Khi đó các phần tử trong nhóm $G$ của ví dụ có biểu diễn hoán vị như sau (đều viết dưới dạng phân tích chu trình):
    
    -   Quay không lần $r_0=()=(1)(2)(3)(4)$, tổng cộng $4$ chu trình (các chu trình độ dài $1$ thường bị lược bỏ);
    -   Quay một lần $r_1=(1234)$, tổng cộng $1$ chu trình;
    -   Quay hai lần $r_2=(13)(24)$, tổng cộng $2$ chu trình;
    -   Quay ba lần $r_3=(1432)$, tổng cộng $1$ chu trình.
    
    Vì vậy số cách tô khác nhau về bản chất là
    
    $$
    \frac{2^4+2^1+2^2+2^1}{4}=6.
    $$

??? example "Một cách giải khác cho bài toán tô màu lập phương"
    Phân tích phía trước thực chất đã cho biểu diễn chu trình của từng loại hoán vị, chỉ chưa viết tường minh bằng ký hiệu số. Phần này không lặp lại phân tích đó, chỉ minh họa trường hợp quay $180^\circ$ quanh trục nối trung điểm của hai cạnh đối diện. Đánh số sáu mặt trước, sau, trên, dưới, trái, phải lần lượt là $1\sim6$, hoán vị tương ứng là $(13)(24)(56)$, do đó $c(g)=3$. Các loại hoán vị khác cũng phân tích tương tự, và biểu thức đếm cuối cùng giống hệt phần trên.

<span id="mở-rộng-có-trọng-số"></span>
## Mở rộng có trọng số

Phiên bản không trọng số của nguyên lý đếm Pólya chỉ cho số lượng tất cả các cách tô khác nhau về bản chất; khi xử lý bài toán tinh hơn thì không đủ. Chẳng hạn, nếu trong bài toán tô màu ở trên, số lần được dùng của từng màu đã được cho trước, thì không thể áp dụng trực tiếp công thức Pólya trên. Khi giải loại bài toán này trong thực tế, cần dùng lại bổ đề Burnside để suy luận; tổng kết các kết quả đó dưới dạng hàm sinh chính là phiên bản có trọng số của nguyên lý đếm Pólya.

???+ example "Tô màu vòng cổ (có ràng buộc)"
    Có một vòng cổ gồm bốn hạt, mỗi hạt có thể tô màu đỏ hoặc xanh, và phải dùng đúng hai hạt đỏ, hai hạt xanh. Hỏi có bao nhiêu vòng cổ khác nhau về bản chất? (Nếu hai cách tô có thể trùng nhau sau khi quay vòng cổ, chúng được xem là giống nhau.)

??? example "Lời giải và phân tích"
    Xét bằng bổ đề Burnside. Có đúng hai hạt đỏ và hai hạt xanh, tổng cộng có $\dbinom{4}{2}=6$ cách tô. Nhóm đối xứng không gian $G=\{r_0,r_1,r_2,r_3\}$ lần lượt ứng với quay $0\sim3$ lần. Tập điểm bất động của chúng được phân tích như sau:
    
    -   Quay không lần $r_0=()=(1)(2)(3)(4)$, cả $6$ cách tô đều là điểm bất động;
    -   Quay một lần $r_1=(1234)$, điểm bất động yêu cầu mọi hạt có cùng màu, nên không có điểm bất động;
    -   Quay hai lần $r_2=(13)(24)$, có hai vùng tô độc lập, mỗi vùng có kích thước $2$; chúng cần lần lượt tô thành đỏ và xanh, nên kích thước tập điểm bất động là $2$;
    -   Quay ba lần $r_3=(1432)$ giống trường hợp quay một lần, không có điểm bất động.
    
    Theo bổ đề Burnside, số cách tô khác nhau về bản chất là
    
    $$
    \frac{6+0+2+0}{4}=2.
    $$

Từ ví dụ này có thể rút ra cách tính sau. Với bài toán ràng buộc số lượng của từng màu, vẫn phải tô các chu trình của từng hoán vị trong nhóm đối xứng không gian, nhưng số lượng màu được dùng phải đúng bằng các giá trị cho trước. Bài toán tổ hợp này thường không có nghiệm tường minh; ngoài vài trường hợp đặc biệt có thể tính bằng [phương pháp hoán vị - tổ hợp](../combinatorics/combination.md), thường cần xem như [bài toán ba lô](../../dp/knapsack.md) để giải.

Hàm sinh có thể mô tả đáp án của loại bài toán đếm này. Với một hoán vị $g$ cho trước, nếu [kiểu](../permutation.md#kiểu-chu-trình-của-hoán-vị) của nó là $1^{\alpha_1}2^{\alpha_2}\cdots n^{\alpha_n}$, tức nó có $\alpha_k$ chu trình độ dài $k$, và mỗi chu trình có thể tô bằng một trong $m$ màu, thì trong hàm sinh

$$
\prod_{k=1}^n\left(\sum_{i=1}^mx_i^k\right)^{\alpha_k}
$$

hệ số của đơn thức $x_1^{\beta_1}x_2^{\beta_2}\cdots x_m^{\beta_m}$ chính là số cách dùng màu thứ $i$ đúng $\beta_i$ lần. Ý nghĩa tổ hợp của biểu thức $\sum_{i=1}^mx_i^k$ trong ngoặc là: với một chu trình độ dài $k$, số cách tô dùng màu $i$ đúng $k$ lần là $1$, còn các trường hợp khác có số cách là $0$; điều này mô tả đúng yêu cầu các vị trí trong cùng một chu trình phải có cùng màu.

Cho hàm sinh đếm tô màu dưới hoán vị $g$, áp dụng bổ đề Burnside lên từng đơn thức sẽ thu được số cách khác nhau về bản chất ứng với mỗi tổ hợp màu. Vì hàm sinh tuyến tính theo từng đơn thức, hàm sinh đếm các cách tô khác nhau về bản chất là

$$
\frac1{|G|}\sum_{g\in G}\prod_{k=1}^n\left(\sum_{i=1}^mx_i^k\right)^{\alpha_k}.
$$

Khai triển biểu thức này, hệ số của mỗi đơn thức sẽ cho số cách tô khác nhau về bản chất với tổ hợp màu tương ứng.

Trong quá trình trên, hàm sinh $\sum_{i=1}^mx_i^k$ cho việc tô mỗi chu trình không có gì đặc biệt, có thể thay bằng các hàm sinh khác. Vì vậy có phiên bản tổng quát sau của nguyên lý đếm Pólya.

???+ note "Chỉ số chu trình của nhóm hoán vị"
    Cho nhóm hoán vị $G$, **chỉ số chu trình** (cycle index) của nhóm $G$ được định nghĩa là
    
    $$
    Z_G(t_1,t_2,\cdots,t_n)=\frac{1}{|G|}\sum_{g\in G}t_1^{c_1(g)}t_2^{c_2(g)}\cdots t_n^{c_n(g)},
    $$
    
    trong đó $c_k(g)$ là số chu trình độ dài $k$ trong phân tích chu trình của hoán vị $g$, tức $1^{c_1(g)}2^{c_2(g)}\cdots n^{c_n(g)}$ là kiểu của hoán vị $g$.

???+ note "Nguyên lý đếm Pólya (phiên bản có trọng số)"
    Cho nhóm $G$ tác động lên tập $X$. Nếu cách tô mỗi điểm được cho bởi hàm sinh đếm các phương án tô $f(x_1,x_2,\cdots,x_m)$, thì hàm sinh đếm các cách tô khác nhau về bản chất của tập $X$ là
    
    $$
    Z_G(f(x_1^1,x_2^1,\cdots,x_m^1),f(x_1^2,x_2^2,\cdots,x_m^2),\cdots,f(x_1^n,x_2^n,\cdots,x_m^n)),
    $$
    
    trong đó $Z_G(t_1,t_2,\cdots,t_n)$ là chỉ số chu trình của nhóm $G$.

Tại đây, nếu hàm sinh của cách tô một vị trí là $f(x_1,x_2,\cdots,x_m)$, thì hàm sinh của cách tô một chu trình độ dài $k$ là $f(x_1^k,x_2^k,\cdots,x_m^k)$. Điều này phản ánh rằng nếu một cách tô là điểm bất động của hoán vị cho trước, thì mọi vị trí trong cùng một chu trình phải có cùng màu. Nếu lấy giá trị hàm sinh tại $x_i=1$, sẽ thu được phiên bản không trọng số của nguyên lý đếm Pólya ở trên.

Phát biểu định lý dùng khái niệm chỉ số chu trình của nhóm hoán vị. Khái niệm này độc lập với bài toán tô màu cụ thể; nó mô tả cấu trúc của nhóm hoán vị.

??? example "Một cách giải khác cho bài toán tô vòng cổ có ràng buộc"
    Chỉ số chu trình của nhóm đối xứng quay là $\dfrac14\left(t_1^4+t_2^2+2t_4\right)$, hàm sinh tô một điểm là $r+b$, nên hàm sinh của toàn bộ cách tô là
    
    $$
    \begin{aligned}
    F(r,b)&=\frac14\left((r+b)^4+(r^2+b^2)^2+2(r^4+b^4)\right)\\
    &=r^4+r^3b+2r^2b^2+rb^3+b^4.
    \end{aligned}
    $$
    
    Số cần tìm là hệ số của $r^2b^2$, tức có tổng cộng $2$ cách tô khác nhau về bản chất. Đồng thời, công thức này cũng cho số cách đếm dưới các ràng buộc khác.

<span id="ứng-dụng"></span>
### Ứng dụng

Phiên bản có trọng số của nguyên lý đếm Pólya đóng vai trò quan trọng trong các bài toán đếm tổ hợp. Phần này chỉ thảo luận ngắn gọn ứng dụng của nó; phần tổng quát hơn có thể xem ở [phương pháp hình thức cho bài toán tổ hợp](../poly/symbolic-method.md#cấu-trúc-có-ràng-buộc).

???+ example "Vòng cổ kim cương"
    Có một vòng cổ gồm bốn hạt giống nhau, mỗi hạt có thể gắn một số viên kim cương. Nếu có tổng cộng bốn viên kim cương, hỏi có bao nhiêu cách gắn khác nhau về bản chất? (Nếu hai cách gắn có thể trùng nhau sau khi quay vòng cổ, chúng được xem là giống nhau.)

??? example "Lời giải và phân tích"
    Nhóm đối xứng không gian của vòng cổ vẫn giống như đã nêu ở trên. Nếu chưa xét ràng buộc tổng số kim cương, hàm sinh phương án gắn kim cương tại một vị trí là
    
    $$
    f(x)=1+x+x^2+\cdots=\sum_{i=0}^\infty x^i=\frac{1}{1-x}.
    $$
    
    Áp dụng phiên bản có trọng số của nguyên lý đếm Pólya, hàm sinh của mọi phương án gắn kim cương là
    
    $$
    \begin{aligned}
    F(x)&=\frac14\left(f(x)^4+f(x^2)^2+2f(x^4)\right)\\
    &=1+x+3x^2+5x^3+10x^4+\cdots.
    \end{aligned}
    $$
    
    Vì vậy số phương án cần tìm là hệ số của $x^4$, tức tổng cộng $10$ phương án. Có thể kiểm chứng bằng liệt kê; chúng lần lượt là
    
    $$
    4000,3100,3010,3001,2200,2020,2110,2101,2011,1111.
    $$
    
    Tại đây, mỗi nhóm bốn chữ số biểu diễn số kim cương trên từng hạt.

Ví dụ này cho thấy phiên bản có trọng số của nguyên lý đếm Pólya giải được phạm vi bài toán rộng hơn nhiều so với bài toán tô màu. Nó cung cấp cách mở rộng phép đếm tại một điểm đơn lẻ thành phép đếm khác nhau về bản chất trên toàn cấu trúc. Bài toán tô màu chỉ là một trường hợp đặc biệt của lớp bài toán này.

<span id="các-nhóm-đối-xứng-không-gian-thường-gặp"></span>
## Các nhóm đối xứng không gian thường gặp

Một khó khăn của các bài toán đếm Pólya là phân tích cấu trúc của nhóm hoán vị. Phần này thảo luận ngắn gọn cấu trúc của các nhóm đối xứng không gian thường gặp và mô tả chúng bằng chỉ số chu trình. Cần lưu ý rằng với cùng một nhóm đối xứng không gian của một cấu trúc, nếu tập đối tượng mà nó tác động lên khác nhau thì [tác động nhóm](../algebra/group-theory.md#tác-động-nhóm) tương ứng cũng khác nhau, do đó biểu diễn hoán vị cũng khác nhau. Ví dụ, nhóm đối xứng không gian của khối lập phương khi tác động lên đỉnh, cạnh, mặt lần lượt cho nhóm hoán vị đỉnh, nhóm hoán vị cạnh và nhóm hoán vị mặt của khối lập phương; số lượng đỉnh, cạnh, mặt đôi một khác nhau, nên các nhóm hoán vị đó và chỉ số chu trình tương ứng cũng khác nhau. Vì vậy trong bài toán cụ thể, không được bỏ qua việc chỉ rõ đối tượng mà nhóm tác động lên.

??? info "Quan hệ giữa nhóm đối xứng không gian và nhóm hoán vị"
    Dù hai khái niệm rất giống nhau về trực giác, chúng tuyệt đối không phải cùng một đối tượng. Nói bằng ngôn ngữ lý thuyết nhóm, cho nhóm đối xứng không gian $G$ và tác động nhóm của nó lên tập $X$, biểu diễn hoán vị của tác động nhóm cho một đồng cấu từ nhóm $G$ đến nhóm đối xứng $S_X$, ký hiệu $\varphi$. Trong ngữ cảnh đếm tổ hợp, biểu diễn hoán vị này thường là trung thành, tức $\ker\varphi=\{e\}$, nên đồng cấu $\varphi$ thực chất là một phép nhúng từ nhóm $G$ vào nhóm $S_X$. Nhóm hoán vị trong bài chính là ảnh của phép nhúng này, tức $\varphi(G)$, và nó đẳng cấu với nhóm đối xứng không gian $G$. Vì vậy, với cùng một nhóm đối xứng không gian $G$ trên cùng một cấu trúc, nếu cách chọn tác động nhóm khác nhau thì nó sẽ đẳng cấu với các nhóm hoán vị $\varphi(G)$ khác nhau, từ đó có chỉ số chu trình khác nhau (các nhóm hoán vị đẳng cấu không nhất thiết có cùng chỉ số chu trình).

Cho một cấu trúc, nhóm đối xứng không gian của nó là tập mọi phép toán có thể biến đổi nó thành chính nó. Nó nhất thiết thỏa mãn các điều kiện sau:

-   Áp dụng liên tiếp hai phép đối xứng lên cấu trúc cho trước có thể xem là áp dụng một phép đối xứng khác, tức tập các phép đối xứng đóng dưới phép hợp thành;
-   Phép hợp thành các phép đối xứng thỏa mãn luật kết hợp;
-   Tồn tại phép đối xứng đồng nhất, tức việc giữ nguyên cấu trúc cũng được xem là một phép toán;
-   Mọi phép toán đều có phép nghịch đảo, có thể triệt tiêu hiệu quả của phép toán đã cho.

[Nhóm](../algebra/basic.md#nhóm) là sự trừu tượng hóa của mọi khái niệm thỏa mãn các điều kiện trên. Việc nghiên cứu cấu trúc nhóm là nội dung chính của [lý thuyết nhóm](../algebra/group-theory.md). Phân tích bên dưới chủ yếu tập trung vào nhóm đối xứng không gian và dùng quan điểm hình học để thảo luận cấu trúc của chúng. Các ví dụ thường gặp dưới đây nhằm giúp người đọc nắm được cách phân tích loại bài toán này.

<span id="nhóm-cyclic"></span>
### Nhóm cyclic

Cho đa giác đều $n$ cạnh, nhóm đối xứng không gian gồm tất cả các phép quay của nó được gọi là nhóm cyclic, ký hiệu $C_n$. Ký hiệu phép quay ngược chiều kim đồng hồ $(360/n)^\circ$ là $r$, khi đó các phần tử của nhóm $C_n$ có thể viết là

$$
C_n=\{e,r,r^2,\cdots,r^{n-1}\}.
$$

Tại đây, $r^k$ là kết quả lặp phép toán $r$ đúng $k$ lần, tức quay ngược chiều kim đồng hồ $(360k/n)^\circ$, còn $e=r^0$ là phép đồng nhất.

Dù xét tác động của nhóm cyclic lên tập tất cả đỉnh hay tập tất cả cạnh của đa giác đều $n$ cạnh, biểu diễn hoán vị đều giống nhau. Lấy tập tất cả đỉnh làm ví dụ để phân tích biểu diễn hoán vị của tác động nhóm. Chỉ số chu trình của nó là

$$
Z(C_n)=\frac1n\sum_{d\mid n}\varphi(d)t_{d}^{n/d}.
$$

Tại đây, $\varphi(\cdot)$ là [hàm Euler](../number-theory/euler-totient.md) trong số học.

Nếu chỉ tính phép quay, nhóm đối xứng không gian của vòng cổ độ dài $n$ chính là $C_n$.

??? note "Phân tích"
    Đánh số tập đỉnh theo thứ tự ngược chiều kim đồng hồ là $\{0,1,\cdots,n-1\}$, khi đó $r^k(i)=i+k\bmod n$. Tập đỉnh trong chu trình chứa đỉnh $i$ là
    
    $$
    \{i+\ell k\bmod n:\ell\in\mathbf Z\}.
    $$
    
    Có $i\equiv i+\ell k\pmod n$ khi và chỉ khi
    
    $$
    \frac{n}{\gcd(k,n)}\mid\ell.
    $$
    
    Điều này có nghĩa là độ dài chu trình chứa bất kì đỉnh $i$ nào đều là $\dfrac{n}{\gcd(k,n)}$. Vì vậy hoán vị $r^k$ có $\gcd(k,n)$ chu trình cùng độ dài. Xét việc gộp các hạng đồng dạng trong biểu thức chỉ số chu trình: với $d\mid n$ cho trước, các $k$ thỏa $\gcd(k,n)=n/d$ có tổng cộng $\varphi(d)$ giá trị, và chúng ứng với cùng một đơn thức dạng $t_d^{n/d}$. Từ đó suy ra biểu thức chỉ số chu trình ở trên.

<span id="nhóm-nhị-diện"></span>
### Nhóm nhị diện

Cho đa giác đều $n$ cạnh, tất cả các phép quay và phép lật qua trục đối xứng cũng tạo thành một nhóm đối xứng không gian, gọi là nhóm nhị diện (dihedral group), ký hiệu $D_{2n}$. Ký hiệu phép quay ngược chiều kim đồng hồ $(360/n)^\circ$ là $r$, và ký hiệu phép lật qua một trục đối xứng cố định (ví dụ đường nối tâm với một đỉnh) là $s$, khi đó các phép toán của nhóm $D_{2n}$ có thể viết là

$$
D_{2n}=\{e,r,\cdots,r^{n-1},s,sr,\cdots,sr^{n-1}\}.
$$

Tại đây, $r^k$ vẫn là phép quay; còn $sr^k$, dù có thể hiểu là quay $k$ lần rồi lật qua trục cố định, cũng tương đương với lật qua một trục đối xứng khác. Do đó nhóm $D_{2n}$ có tổng cộng $1$ phép đồng nhất, $(n-1)$ phép quay và $n$ phép lật. Tác động của nó lên tập đỉnh và tập cạnh có cùng chỉ số chu trình. Chỉ số chu trình là

$$
Z(D_{2n})=\frac12Z(C_n)+
\begin{cases}
\dfrac12t_1t_2^k,&n=2k+1,\\
\dfrac14\left(t_1^2t_2^{k-1}+t_2^k\right),&n=2k.
\end{cases}
$$

??? note "Phân tích"
    Phân tích tập các phép quay $r^k$ trong nhóm $D_{2n}$ (bao gồm phép đồng nhất) giống hệt nhóm cyclic $C_n$; điểm mấu chốt là phân tích các phép lật còn lại. Khi đó cần chia theo tính chẵn lẻ của số đỉnh $n$.
    
    Khi $n=2k+1$, mọi trục lật đều nối một đỉnh với trung điểm cạnh đối diện nó, có tổng cộng $n$ trục như vậy. Sau mỗi phép lật, đỉnh nằm trên trục đối xứng giữ nguyên, còn các đỉnh khác đổi chỗ theo từng cặp, nên có $1$ điểm bất động (chu trình độ dài $1$) và $k$ chu trình độ dài $2$.
    
    Khi $n=2k$, có hai loại trục đối xứng. Một nửa số trục nối hai đỉnh đối diện; lật qua trục như vậy giữ nguyên hai đỉnh trên trục và đổi chỗ các đỉnh còn lại theo từng cặp, nên có $2$ điểm bất động (chu trình độ dài $1$) và $(k-1)$ chu trình độ dài $2$. Nửa còn lại nối trung điểm hai cạnh đối diện; lật qua trục như vậy đổi chỗ mọi đỉnh theo từng cặp, nên có $k$ chu trình độ dài $2$.
    
    Từ phân tích này có thể viết được biểu thức chỉ số chu trình ở trên.

<span id="nhóm-đối-xứng"></span>
### Nhóm đối xứng

Cho $n$ phần tử, tập tất cả các hoán vị trên chúng tạo thành một nhóm, gọi là nhóm đối xứng bậc $n$ (symmetric group), ký hiệu $S_n$. Nó mô tả mọi đối xứng mà $n$ đỉnh này có thể có. Nó cũng chính là biểu diễn hoán vị của các phép đối xứng đó khi tác động lên tập đỉnh.

Theo phân tích trong bài [hoán vị và sắp xếp](../permutation.md#kiểu-chu-trình-của-hoán-vị), chỉ số chu trình của nó là

$$
Z(S_n)=\sum_{\alpha_1+2\alpha_2+\cdots+n\alpha_n=n}\frac{t_1^{\alpha_1}t_2^{\alpha_2}\cdots t_n^{\alpha_n}}{1^{\alpha_1}2^{\alpha_2}\cdots n^{\alpha_n}\alpha_1!\alpha_2!\cdots\alpha_n!}.
$$

Tại đây dùng công thức đếm số hoán vị có kiểu $1^{\alpha_1}2^{\alpha_2}\cdots n^{\alpha_n}$:

$$
\frac{n!}{1^{\alpha_1}2^{\alpha_2}\cdots n^{\alpha_n}\alpha_1!\alpha_2!\cdots\alpha_n!}.
$$

Nó thỏa mãn truy hồi

$$
Z(S_n)=\frac1n\sum_{k=1}^nt_kZ(S_{n-k}),
$$

với điều kiện đầu $Z(S_0)=1$. Ý nghĩa tổ hợp của truy hồi này là: để xây dựng một hoán vị độ dài $n$, trước hết chọn độ dài $k$ của chu trình chứa điểm $n$, rồi xây dựng trên tập $(n-k)$ đỉnh còn lại.

Với đồ thị đầy đủ trên $n$ đỉnh, nhóm tự đẳng cấu của nó chính là nhóm hoán vị đỉnh $S_n$. Chỉ số chu trình của tác động lên tập tất cả đỉnh được cho bởi $Z(S_n)$ ở trên. Nhưng biểu diễn hoán vị của nó trên tập tất cả cạnh thì khác. Chẳng hạn, kích thước tập đã khác: số cạnh là $n(n-1)/2$. Với trường hợp cạnh, cần phân tích thêm. Dưới đây là ví dụ đơn giản; trường hợp tổng quát có thể xem ở phần bài tập.

???+ example "Đếm đồ thị đơn vô hướng"
    Tính số đồ thị đơn vô hướng có $4$ đỉnh, xét đến đẳng cấu.

??? example "Lời giải"
    Bài toán tương đương với tô hai màu trên đồ thị đầy đủ có $4$ đỉnh, yêu cầu số cách tô khác nhau về bản chất. Nhóm tự đẳng cấu là nhóm hoán vị đỉnh $S_4$; cần phân tích chỉ số chu trình của nhóm hoán vị cạnh $S_4^{(2)}$.
    
    -   Phép đồng nhất ($1$ phép): các cạnh cũng giữ nguyên, nên đơn thức tương ứng là $t_1^6$;
    -   Đổi chỗ hai đỉnh ($6$ phép): giả sử đổi chỗ $a$ và $b$, cạnh $1$ và cạnh $3$ giữ nguyên; cạnh $2$ đổi chỗ với cạnh $5$, cạnh $4$ đổi chỗ với cạnh $6$, nên đơn thức tương ứng là $6t_1^2t_2^2$;
    -   Chu trình ba đỉnh ($8$ phép): giả sử chu trình là $(abc)$, các cạnh nối giữa chúng $1,2,5$ cũng tạo chu trình tương ứng, và các cạnh nối chúng với đỉnh thứ tư $d$, tức $4,6,3$, cũng tạo chu trình tương ứng, nên đơn thức là $8t_3^2$;
    -   Đổi chỗ hai cặp đỉnh ($3$ phép): giả sử đỉnh $a$ đổi với $b$, đỉnh $c$ đổi với $d$, thì cạnh $1$ và cạnh $3$ giữ nguyên, cạnh $2$ đổi với cạnh $4$, cạnh $5$ đổi với cạnh $6$, nên đơn thức là $3t_1^2t_2^2$;
    -   Chu trình bốn đỉnh ($6$ phép): giả sử chu trình là $(abcd)$, các cạnh nối các đỉnh kề nhau $1,2,3,4$ cũng tạo chu trình tương ứng, còn hai cạnh nối đỉnh đối diện $5,6$ đổi chỗ với nhau, nên đơn thức tương ứng là $6t_2t_4$.
    
    Vì vậy chỉ số chu trình của nhóm hoán vị cạnh là
    
    $$
    Z(S_4^{(2)})=\dfrac{1}{24}(t_1^6+9t_1^2t_2^2+8t_3^2+6t_2t_4).
    $$
    
    Theo nguyên lý đếm Pólya, số đồ thị đơn vô hướng có $4$ đỉnh xét đến đẳng cấu là
    
    $$
    \frac{2^6+9\times 2^4+8\times 2^2+6\times 2^2}{24} = 11.
    $$

<span id="nhóm-đa-diện"></span>
### Nhóm đa diện

Nhóm đa diện (polyhedral group) là nhóm đối xứng không gian của khối đa diện đều. Chỉ có năm khối đa diện đều: tứ diện đều, lập phương, bát diện đều, thập nhị diện đều và nhị thập diện đều. Nếu giữ quan hệ kề nhau giữa đỉnh, cạnh, mặt và hoán đổi vai trò đỉnh với mặt, sẽ thu được khối đa diện đều đối ngẫu. Trong đó, tứ diện đều đối ngẫu với chính nó, lập phương đối ngẫu với bát diện đều, thập nhị diện đều đối ngẫu với nhị thập diện đều. Có thể dùng quan hệ đối ngẫu để đơn giản hóa thảo luận nhóm đối xứng không gian của chúng.

Nếu chỉ tính các phép quay trong không gian ba chiều, nhóm đối xứng không gian của chúng chỉ có ba loại.

-   Nhóm tứ diện (tetrahedral group), tức nhóm đối xứng không gian của tứ diện đều:

    -   Phép đồng nhất;
    -   Quay $120^\circ$ và $240^\circ$ quanh đường nối một đỉnh với tâm mặt đối diện;
    -   Quay $180^\circ$ quanh đường nối trung điểm hai cạnh đối diện.

    Tổng cộng có $1+2\times4+1\times3=12$ phép đối xứng.

    Chỉ số chu trình của các nhóm hoán vị tương ứng là:

    -   Nhóm hoán vị đỉnh và nhóm hoán vị mặt: $\dfrac1{12}\left(t_1^4+8t_1t_3+3t_2^2\right)$;
    -   Nhóm hoán vị cạnh: $\dfrac1{12}\left(t_1^6+8t_3^2+3t_1^2t_2^2\right)$.

-   Nhóm bát diện (octahedral group), tức nhóm đối xứng không gian của lập phương (và bát diện đều):

    -   Phép đồng nhất;
    -   Quay $120^\circ$ và $240^\circ$ quanh đường nối hai đỉnh đối diện;
    -   Quay $180^\circ$ quanh đường nối trung điểm hai cạnh đối diện;
    -   Quay $90^\circ$, $180^\circ$ và $270^\circ$ quanh đường nối tâm hai mặt đối diện.

    Tổng cộng có $1+2\times 4+1\times 6+3\times 3=24$ phép đối xứng.

    Chỉ số chu trình của các nhóm hoán vị tương ứng của lập phương là:

    -   Nhóm hoán vị đỉnh: $\dfrac{1}{24}\left(t_1^8+8t_1^2t_3^2+9t_2^4+6t_4^2\right)$;
    -   Nhóm hoán vị cạnh: $\dfrac{1}{24}\left(t_1^{12}+8t_3^4+6t_1^2t_2^5+6t_4^3+3t_2^6\right)$;
    -   Nhóm hoán vị mặt: $\dfrac{1}{24}\left(t_1^6+8t_3^2+6t_2^3+6t_1^2t_4+3t_1^2t_2^2\right)$.

    Nhóm hoán vị của bát diện đều tương tự, chỉ cần đổi vai trò đỉnh và mặt.

-   Nhóm nhị thập diện (icosahedral group), tức nhóm đối xứng không gian của thập nhị diện đều (và nhị thập diện đều):

    -   Phép đồng nhất;
    -   Quay $120^\circ$ và $240^\circ$ quanh đường nối hai đỉnh đối diện;
    -   Quay $180^\circ$ quanh đường nối trung điểm hai cạnh đối diện;
    -   Quay $72^\circ$, $144^\circ$, $216^\circ$ và $288^\circ$ quanh đường nối tâm hai mặt đối diện.

    Tổng cộng có $1+2\times 10+1\times 15+6\times 4=60$ phép đối xứng.

    Chỉ số chu trình của các nhóm hoán vị tương ứng của thập nhị diện đều là:

    -   Nhóm hoán vị đỉnh: $\dfrac{1}{60}\left(t_1^{20}+20t_1^2t_3^6+15t_2^{10}+24t_5^4\right)$;
    -   Nhóm hoán vị cạnh: $\dfrac{1}{60}\left(t_1^{30}+20t_3^{10}+15t_1^2t_2^{14}+24t_5^6\right)$;
    -   Nhóm hoán vị mặt: $\dfrac{1}{60}\left(t_1^{12}+20t_3^4+15t_2^6+24t_1^2t_5^2\right)$.

    Nhóm hoán vị của nhị thập diện đều tương tự, chỉ cần đổi vai trò đỉnh và mặt.

Các chỉ số chu trình tại đây đều dành cho nhóm hoán vị tác động riêng lên các đối tượng như đỉnh, cạnh, mặt. Nếu cần tô màu đồng thời nhiều loại đối tượng, phải viết chỉ số chu trình liên hợp.

<span id="bài-tập"></span>
## Bài tập

<span id="bài-toán-tô-màu"></span>
### Bài toán tô màu

Các bài này chỉ cần phân tích cấu trúc của nhóm hoán vị và áp dụng nguyên lý đếm Pólya.

-   [Luogu P4980 Mẫu: Định lý Polya](https://www.luogu.com.cn/problem/P4980)
-   [Luogu P2561 [AHOI2002] Gạch trắng đen](https://www.luogu.com.cn/problem/P2561)
-   [TRANSP - Transposing is Fun](https://www.spoj.com/problems/TRANSP/)
-   [TRANSP2 - Transposing is Even More Fun](https://www.spoj.com/problems/TRANSP2/)
-   [Luogu P3307 [SDOI2013] Vòng cổ](https://www.luogu.com.cn/problem/P3307)

Khi tổ hợp màu được phép dùng bị ràng buộc, cần dùng DP ba lô hoặc phương pháp tổ hợp để tính số cách tô các chu trình.

-   [Luogu P1446 [HNOI2008] Cards](https://www.luogu.com.cn/problem/P1446)
-   [UVA10601 Cubes](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1542)
-   [Luogu P4916 [MtOI2018] Vòng ma lực](https://www.luogu.com.cn/problem/P4916)

<span id="đếm-đồ-thị"></span>
### Đếm đồ thị

Nguyên lý đếm Pólya có thể dùng cho bài toán [đếm đồ thị](../combinatorics/graph-enumeration.md); khó khăn của loại bài này nằm ở việc liệt kê nhóm hoán vị cạnh của đồ thị.

-   [SGU 282. Isomorphism](https://codeforces.com/problemsets/acmsguru/problem/99999/282)
-   [Luogu P4727 [HNOI2009] Đếm đẳng cấu đồ thị](https://www.luogu.com.cn/problem/P4727)
-   [Luogu P4128 [SHOI2006] Đồ thị có màu](https://www.luogu.com.cn/problem/P4128)

Một loại bài toán đếm đồ thị khác có thể áp dụng nguyên lý đếm Pólya cần thao tác trực tiếp trên hàm sinh.

-   [LOJ 6538 Đếm alkyl, bản tăng cường, bản tăng cường](https://loj.ac/p/6538)
-   [LOJ 6512 "Trại huấn luyện Yale 2018" Đếm alkane](https://loj.ac/p/6512)
-   [Luogu P6597 Đếm alkene](https://www.luogu.com.cn/problem/P6597)
-   [Luogu P5818 [JSOI2011] Đếm đồng phân](https://www.luogu.com.cn/problem/P5818)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [Định lý đếm Pólya - Wikipedia](https://en.wikipedia.org/wiki/P%C3%B3lya_enumeration_theorem)
-   [Ghi chú về định lý đếm Pólya](https://www.diva-portal.org/smash/get/diva2:324594/FULLTEXT01.pdf)
-   [Chỉ số chu trình - Wikipedia](https://en.wikipedia.org/wiki/Cycle_index)

[^perm-group]: Vì vậy nhóm đối xứng không gian $G$ có thể biểu diễn thành một nhóm hoán vị trên tập $X$, tức một nhóm con của nhóm đối xứng $S_X$.

[^g-act]: Nói chặt chẽ hơn, đây là tác động của nhóm con $\langle g\rangle\le G$.
