author: cutekibry, woruo27, tinjyu, 2008verser, Backl1ght, billchenchina, Enter-tainer, FFjet, Ir1d, Molmin, orzAtalod, ouuan, SaMiiKaaaa, SamZhangQingChuan, Tiphereth-A, chu-yuehan

Kiến thức cần có: [giới thiệu lý thuyết trò chơi](./intro.md)

Bài viết này thảo luận về [trò chơi tổ hợp công bằng](./intro.md#trò-chơi-tổ-hợp-công-bằng).

Trong các trò chơi tổ hợp công bằng, trò chơi cơ bản nhất và quan trọng nhất là Nim theo luật bình thường. Định lý Sprague-Grundy chỉ ra rằng mọi trò chơi tổ hợp công bằng theo luật bình thường đều tương đương với một trò chơi Nim chỉ có một đống. Từ đó có thể phát triển các khái niệm hàm Sprague-Grundy và số Nim; chúng mô tả đầy đủ một trò chơi tổ hợp công bằng theo luật bình thường. Vì vậy, bài viết trước hết xây dựng các kết luận cho Nim bình thường và lý thuyết Sprague-Grundy. Sau đó, bài viết thảo luận một số trò chơi tổ hợp công bằng thường gặp trong lập trình thi đấu.

Cuối cùng, bài viết giới thiệu ngắn gọn Nim luật ngược. Trò chơi luật ngược phức tạp hơn nhiều so với luật bình thường và cũng hiếm gặp trong lập trình thi đấu. Nếu không nói rõ thêm, mọi trò chơi được nhắc tới trong bài đều mặc định là trò chơi tổ hợp công bằng theo luật bình thường.

???+ info "\"Trạng thái\", \"cục diện\" và \"trò chơi\""
    Bài viết sẽ dùng xen kẽ ba thuật ngữ này. Trong lý thuyết trò chơi, trạng thái (state) của trò chơi thường bao gồm mọi thông tin có thể liên quan tới trò chơi tính đến một thời điểm nào đó. Trong trường hợp tổng quát, trạng thái trò chơi thường bao gồm các hành động đã qua của hai người chơi, các giá trị ngẫu nhiên đã được hiện thực hóa, nội dung thông tin mà hai bên biết, v.v. Cục diện (position) không hẳn là thuật ngữ chuẩn trong lý thuyết trò chơi; nó thường chỉ tình thế mà hai người chơi đang đối mặt tại một thời điểm, chẳng hạn vị trí các quân trong trò chơi cờ. Riêng với trò chơi tổ hợp công bằng, hoặc rộng hơn là trò chơi tổng bằng không, xác định và có thông tin hoàn hảo, trò chơi không có tính ngẫu nhiên, đồng thời tập hành động tương lai và hàm lợi ích của người chơi đều không phụ thuộc vào đường đi lịch sử dẫn tới cục diện hiện tại, tức các hành vi trước đó của hai bên. Do đó trạng thái (state) và cục diện (position) không khác nhau, và cả hai đều có thể xem là một đỉnh (node) trên đồ thị trò chơi. Vì một trò chơi (game) luôn có thể được mô tả bằng cục diện ban đầu của nó, đôi khi bài viết cũng dùng trực tiếp từ "cục diện" để chỉ bản thân trò chơi.

<span id="trò-chơi-nim"></span>
## Trò chơi Nim

Luật của trò chơi Nim rất đơn giản:

???+ abstract "Trò chơi Nim"
    Có $n$ đống đá, đống thứ $i$ có $a_i$ viên đá. Hai người chơi lần lượt lấy đi một số viên đá tùy ý từ một đống tùy ý, nhưng không được không lấy. Người lấy viên đá cuối cùng thắng.

Dễ kiểm tra rằng Nim là một trò chơi tổ hợp công bằng theo luật bình thường.

???+ example "Ví dụ"
    Chẳng hạn, hiện có $3$ đống đá với số lượng lần lượt là $2,5,4$. Khi đó có thể lấy đi $2$ vật từ đống thứ $1$, cục diện trở thành $0, 5, 4$; cũng có thể lấy đi $4$ vật từ đống thứ $2$, cục diện trở thành $2, 1, 4$. Nếu tại một thời điểm nào đó cục diện trở thành $0, 0, 5$, người chơi A lấy đi $5$ vật ở đống thứ $3$, tức lấy đi vật cuối cùng, thì người chơi A thắng.

<span id="đồ-thị-trò-chơi-và-trạng-thái"></span>
### Đồ thị trò chơi và trạng thái

Trong trò chơi Nim, các biến đổi có thể xảy ra của cục diện có thể được mô tả bằng đồ thị trò chơi.

Xem mỗi trạng thái có thể có là một đỉnh của đồ thị, rồi nối cạnh từ một trạng thái tới các trạng thái kế tiếp của nó, tức các trạng thái có thể đạt được sau một thao tác. Khi đó thu được một đồ thị có hướng không chu trình, gọi là đồ thị trò chơi. Đồ thị không có chu trình vì trong Nim, sau mỗi thao tác, tổng số đá đều giảm nghiêm ngặt.

???+ example "Ví dụ"
    Ví dụ, với trò chơi Nim có cục diện ban đầu gồm $3$ đống đá, mỗi đống lần lượt có $1,1,2$ viên, có thể vẽ đồ thị trò chơi như sau:
    
    ![Ví dụ về đồ thị trò chơi](./images/nim.svg)
    
    Các đỉnh màu đỏ trong hình biểu thị trạng thái tất thắng, còn các đỉnh màu đen biểu thị trạng thái tất bại.

Vì Nim là trò chơi tổ hợp công bằng, việc mỗi người chơi có chiến lược thắng hay không chỉ phụ thuộc vào trạng thái hiện tại của trò chơi, không phụ thuộc vào danh tính người chơi. Do đó, mọi trạng thái có thể được chia thành **trạng thái tất thắng** của người đi trước và **trạng thái tất bại** của người đi trước, lần lượt ký hiệu là trạng thái $\mathcal N$ và trạng thái $\mathcal P$[^n-vs-p]. Định nghĩa này áp dụng cho mọi trò chơi tổ hợp công bằng.

Nhờ bổ đề sau, có thể đánh dấu quy nạp mọi trạng thái là tất thắng hoặc tất bại:<a id="np-lem"></a>

???+ note "Bổ đề"
    Trong trò chơi tổ hợp công bằng theo luật bình thường,
    
    1.  trạng thái không có trạng thái kế tiếp là trạng thái tất bại $\mathcal P$,
    2.  một trạng thái là trạng thái tất thắng $\mathcal N$ khi và chỉ khi tồn tại ít nhất một trạng thái kế tiếp của nó là trạng thái tất bại $\mathcal P$,
    3.  một trạng thái là trạng thái tất bại $\mathcal P$ khi và chỉ khi mọi trạng thái kế tiếp của nó đều là trạng thái tất thắng $\mathcal N$.

??? note "Chứng minh"
    Với mệnh đề thứ nhất, nếu người chơi hiện không còn hành động nào có thể chọn, người chơi đó đã thua.
    
    Với mệnh đề thứ hai, nếu trạng thái này có ít nhất một trạng thái kế tiếp là trạng thái tất bại, người chơi có thể đi tới trạng thái tất bại đó; lúc này đối thủ đối mặt với một trạng thái người đi trước tất bại, nên người chơi hiện tại giành thắng lợi.
    
    Với mệnh đề thứ ba, nếu không tồn tại trạng thái kế tiếp nào là tất bại, dù đi thế nào người chơi cũng chỉ có thể đi tới trạng thái tất thắng; khi đó đối thủ đối mặt với trạng thái người đi trước tất thắng, nên người chơi hiện tại sẽ thua.

Trong mọi trò chơi tổ hợp công bằng, đồ thị trò chơi đều là đồ thị có hướng không chu trình. Vì vậy, sau khi dựng đồ thị trò chơi, dựa vào ba tính chất trên có thể tính trong thời gian $O(|V|+|E|)$ xem mỗi trạng thái là tất thắng hay tất bại. Tại đây $|V|$ là số trạng thái của đồ thị trò chơi, còn $|E|$ là số cạnh, tức tổng số hành động có thể thực hiện trên mọi trạng thái.

Bổ đề này có thể mở rộng cho trò chơi luật ngược và trường hợp đồ thị có hướng có thể có chu trình. Thảo luận liên quan xem trong phần [trò chơi trên đồ thị có hướng](#tro-choi-tren-do-thi-co-huong).

<span id="tổng-nim"></span>
### Tổng Nim

Tiếp tục xét trò chơi Nim.

Bằng cách dựng đồ thị trò chơi, có thể xác định một cục diện có phải là tất thắng cho người đi trước hay không trong thời gian $\Omega(\prod_{i=1}^na_i)$. Nhưng độ phức tạp như vậy quá cao để áp dụng thực tế. Với Nim, việc trạng thái có tất thắng cho người đi trước hay không chỉ phụ thuộc vào tổng Nim của số đá trong cục diện hiện tại.

???+ abstract "Tổng Nim"
    **Tổng Nim** (Nim sum) của các số tự nhiên $a_1,a_2,\cdots,a_n$ được định nghĩa là $a_1\oplus a_2\oplus\cdots\oplus a_n$.

Cái gọi là tổng Nim chính là [phép toán XOR](../bit.md#phép-toán-bit).

???+ note "Định lý"
    Trong trò chơi Nim, trạng thái $(a_1,a_2,\cdots,a_n)$ là trạng thái tất bại $\mathcal P$ khi và chỉ khi tổng Nim
    
    $$
    a_1\oplus a_2\oplus\cdots\oplus a_n = 0.
    $$

??? note "Chứng minh"
    Áp dụng quy nạp cho mọi trạng thái có thể có:
    
    1.  Nếu $a_i=0$ với mọi $i=1,\cdots,n$, trạng thái này không có trạng thái kế tiếp và tổng Nim bằng $0$, nên mệnh đề đúng.
    2.  Nếu $k = a_1\oplus a_2\oplus\cdots\oplus a_n\neq 0$, cần chứng minh trạng thái này là tất thắng. Nói cách khác, cần dựng một nước đi hợp lệ sao cho trạng thái kế tiếp là tất bại; theo giả thiết quy nạp, chỉ cần chứng minh trạng thái kế tiếp thỏa $a'_1\oplus a'_2\oplus\cdots\oplus a'_n=0$. Dựa vào tính chất của tổng Nim, tức XOR, điều này tương đương với việc tồn tại một đống đá sao cho lấy đi một số viên từ $a_i$ sẽ nhận được $a_i\oplus k$, tức $a_i>a_i\oplus k$.
    
        Thật vậy, giả sử trong biểu diễn nhị phân của $k$, bit $1$ cao nhất nằm ở vị trí $d$. Khi đó tồn tại một $a_i$ có bit thứ $d$ trong biểu diễn nhị phân bằng $1$. Với đống đá tương ứng, có $a_i>a_i\oplus k$, vì trong $a_i\oplus k$ bit thứ $d$ bằng $0$, còn các bit cao hơn giống với $a_i$.
    3.  Nếu $a_1\oplus a_2\oplus\cdots\oplus a_n= 0$, cần chứng minh trạng thái này là tất bại. Theo giả thiết quy nạp, chỉ cần chứng minh tổng Nim của mọi trạng thái kế tiếp đều khác $0$. Mọi nước đi hợp lệ biến $a_i$ thành $a'_i\neq a_i$, nên tổng Nim tất yếu trở thành $a'_i\oplus a_i\neq 0$.

Từ đó có thể xác định trong thời gian $O(n)$ xem một trạng thái của Nim có tất thắng cho người đi trước hay không.

<span id="lý-thuyết-sprague-grundy"></span>
## Lý thuyết Sprague-Grundy

Lý thuyết Sprague-Grundy chỉ ra rằng mọi trò chơi tổ hợp công bằng đều tương đương với trò chơi Nim một đống. Kết luận này chủ yếu được áp dụng trong tình huống trò chơi gồm nhiều trò chơi con độc lập với nhau. Khi đó, việc phán định trạng thái có thể được thực hiện bằng cách tính tổng Nim của các giá trị hàm SG của những trò chơi con. Nếu bản thân trò chơi không có cấu trúc như vậy, thì để phán định trạng thái tất thắng và tất bại chỉ cần áp dụng [bổ đề](#np-lem) trong phần đồ thị trò chơi ở trên.

<span id="ký-hiệu-trò-chơi"></span>
### Ký hiệu trò chơi

Như đã nói ở trên, mọi trò chơi tổ hợp công bằng đều có thể được mô tả bằng đồ thị trò chơi. Vì trong đồ thị trò chơi, tính chất của mỗi trạng thái chỉ do các trạng thái kế tiếp của nó quyết định, nên có thể biểu diễn một trạng thái $S$ trong đồ thị trò chơi bằng tập các trạng thái kế tiếp của nó.

???+ example "Ví dụ (tiếp)"
    Với đồ thị trò chơi ở trên, nhận được cách biểu diễn trạng thái như sau:
    
    $$
    \begin{aligned}
    S_{0,0,0} &= \{\},\\
    S_{0,1,0} &= \{S_{0,0,0}\} = \{\{\}\},\\
    S_{0,0,1} &= \{S_{0,0,0}\} = \{\{\}\},\\
    S_{0,0,2} &= \{S_{0,0,0},S_{0,0,1}\} = \{\{\},\{\{\}\}\},\\
    S_{0,1,1} &= \{S_{0,0,0},S_{0,1,0},S_{0,0,1}\} = \{\{\},\{\{\}\}\},\\
    S_{0,1,2} &= \{S_{0,0,2},S_{0,1,0},S_{0,1,1}\} = \{\{\{\}\},\{\{\},\{\{\}\}\}\}.
    \end{aligned}
    $$
    
    Trong đó $S_{0,1,0}=S_{0,0,1}$ và $S_{0,0,2}=S_{0,1,1}$.

Một trò chơi có thể được biểu diễn bằng trạng thái ban đầu của nó.

Dù biểu diễn của trò chơi công bằng có thể khá phức tạp, trò chơi Nim một đống lại đơn giản hơn nhiều. Khi chỉ có một đống đá với số đá là $n$, nó có thể được biểu diễn là

$$
*0 = \{\},~*n = \{*m : m<n,~m\in\mathbf N\} = \{*0,*1,\cdots,*(n-1)\}.
$$

Trong đó, ký hiệu $*n$ biểu thị trò chơi Nim một đống, hay trạng thái ban đầu của nó, khi số đá bằng $n$.

???+ example "Ví dụ (tiếp)"
    Dùng ký hiệu này, các trạng thái trong ví dụ trên có thể được biểu diễn gọn thành
    
    $$
    S_{0,0,0} = *0,~
    S_{0,1,0} = S_{0,0,1} = *1,~
    S_{0,0,2} = S_{0,1,1} = *2,~
    S_{0,1,2} = \{*1, *2\}.
    $$

Trong các phần sau, ký hiệu $T\in S$ nên được hiểu là trạng thái $T$ là trạng thái kế tiếp của trạng thái $S$.

<span id="tổng-và-tương-đương-của-trò-chơi"></span>
### Tổng và tương đương của trò chơi

Quan hệ tương đương giữa các trò chơi phụ thuộc vào khái niệm tổng[^more-sums] của trò chơi.

???+ note "Tổng của trò chơi"
    **Tổng** (sum) của hai trò chơi $G$ và $H$, hay còn gọi là **trò chơi kết hợp** (combined game), ký hiệu $G+H$, là trò chơi
    
    $$
    G + H = \{g + H : g \in G\} \cup \{G + h : h \in H\}.
    $$

Tổng của trò chơi có thể hiểu là trò chơi gồm hai trò chơi con diễn ra đồng thời và không can thiệp lẫn nhau; ở mỗi bước, người chơi có thể và chỉ có thể chọn một trong hai trò chơi con để đi một bước, và trò chơi kết thúc khi cả hai trò chơi con đều không thể đi tiếp. Khái niệm tổng của trò chơi có thể mở rộng cho tùy ý nhiều trò chơi, đồng thời thỏa tính kết hợp và tính giao hoán. Nói cách khác, kết quả của việc kết hợp nhiều trò chơi không phụ thuộc vào thứ tự kết hợp hay thứ tự các trò chơi. Trò chơi Nim chính là tổng của nhiều trò chơi Nim một đống.

Một quan sát là: mặc dù trong Nim một đống, ngoại trừ trường hợp không có đá, mọi trạng thái đều tất thắng cho người đi trước, các trò chơi Nim một đống khác nhau này khi kết hợp với những trò chơi Nim một đống khác lại không cho cùng một trò chơi. Ví dụ, trò chơi $*n$ chỉ tạo thành một trò chơi tất bại khi kết hợp với một $*n$ khác; khi kết hợp với mọi trò chơi $*n'\neq *n$ khác, kết quả đều là trò chơi tất thắng.

Quan sát này gợi ý rằng có thể nghiên cứu tính chất của một trò chơi bằng cách xét tổng của nó với các trò chơi khác. Điều này dẫn tới khái niệm tương đương giữa các trò chơi.

???+ abstract "Quan hệ tương đương của trò chơi"
    Nếu với mọi trò chơi $H$, hai trò chơi $G_1+H$ và $G_2+H$ luôn cùng là trạng thái tất bại hoặc cùng là trạng thái tất thắng, thì gọi $G_1$ và $G_2$ là **tương đương** (equivalent), ký hiệu $G_1\approx G_2$.

Dễ kiểm tra rằng $\approx$ được định nghĩa như trên thực sự là một [quan hệ tương đương](../order-theory.md#quan-hệ-hai-ngôi) trên tập tất cả trò chơi công bằng.

<span id="hàm-sprague-grundy"></span>
### Hàm Sprague-Grundy

Phân tích trò chơi Nim cho thấy các trò chơi Nim một đống khác nhau không tương đương với nhau. Tuy nhiên, mọi trò chơi công bằng đều tương đương với một trò chơi Nim một đống nào đó. Từ đó, có thể gán cho mỗi trò chơi công bằng một con số; đây chính là hàm Sprague-Grundy.

Để chứng minh các kết luận này, trước hết cần thiết lập hai bổ đề về quan hệ tương đương giữa trò chơi. Thứ nhất, kết hợp một trò chơi tất bại với bất kỳ trò chơi nào cũng tương đương với trò chơi ban đầu.

???+ note "Bổ đề 1"
    Với trò chơi $G$ và bất kỳ trò chơi tất bại $A\in\mathcal P$, có $G\approx G + A$.

??? note "Chứng minh"
    Theo định nghĩa, chỉ cần chứng minh với mọi trò chơi $H$ đều có $G+H\approx G+A+H$.
    
    Nếu trò chơi $G+H$ có chiến lược thắng, thì trò chơi $G+A+H$ cũng có chiến lược thắng. Nếu đối thủ đi trong trò chơi con $A$, đi để đưa nó trở lại trạng thái tất bại; nếu không, đi theo chiến lược thắng trong trò chơi $G+H$. Như vậy bảo đảm thắng cuối cùng.
    
    Nếu trò chơi $G+H$ là trò chơi tất bại, thì trò chơi $G+A+H$ cũng là trò chơi tất bại. Bởi dù lượt này đi trong trò chơi con $G+H$ hay trong trò chơi con $A$, đối thủ đều có thể ở lượt tiếp theo đưa trò chơi con tương ứng trở lại trạng thái tất bại. Cuối cùng, người đi trước nhất định không thể thắng.

Thứ hai, hai trò chơi tương đương khi và chỉ khi tổng của chúng là trò chơi tất bại. Bổ đề này cung cấp một cách chứng minh hai trò chơi tương đương.

<a id="sg-lem-2"></a>

???+ note "Bổ đề 2"
    Hai trò chơi $G$ và $G'$ tương đương khi và chỉ khi $G+G'\in\mathcal P$ là trò chơi tất bại.

??? note "Chứng minh"
    Nếu $G$ và $G'$ tương đương, thì $G+G'$ và $G+G$ cùng tất thắng hoặc cùng tất bại, trong khi $G+G$ là trò chơi tất bại. Lý do là với bất kỳ nước đi nào của người đi trước, người đi sau đều có thể thực hiện hành động giống hệt trong trò chơi con còn lại, và cuối cùng người đi trước nhất định không thể đi tiếp.
    
    Ngược lại, nếu $G+G'$ là trò chơi tất bại, theo bổ đề 1 có $G\approx G+(G+G') = (G+G)+G' \approx G'$.

Dùng các bổ đề này, thu được định lý sau:

???+ note "Định lý (Sprague-Grundy)"
    Với bất kỳ trò chơi công bằng hữu hạn $G$, tồn tại $n\in\mathbf N$ sao cho $G\approx *n$.

??? note "Chứng minh"
    Có thể chứng minh kết luận bằng quy nạp toán học. Giả sử trò chơi $G = \{G_1,G_2,\cdots,G_k\}$. Theo giả thiết quy nạp, tồn tại $n_1,n_2,\cdots,n_k$ sao cho $G_i\approx *n_i$. Khi đó xét trò chơi
    
    $$
    G' = \{*n_1,*n_2,\cdots,*n_k\}.
    $$
    
    Cần chứng minh $G'\approx *m$, trong đó $m=\operatorname{mex}\{n_1,n_2,\cdots,n_k\}$ là số tự nhiên nhỏ nhất không xuất hiện trong tập.
    
    Bước thứ nhất, cần chứng minh $G\approx G'$. Theo [bổ đề 2](#sg-lem-2), chỉ cần chứng minh trò chơi $G+G'$ là tất bại. Giả sử không mất tính tổng quát rằng $G\neq *0$. Nếu người đi trước chọn $G_i$, thì người đi sau có thể chọn $*n_i$; ngược lại, nếu người đi trước chọn $*n_i$, người đi sau có thể chọn $G_i$. Sau hai nước đi này, trò chơi trở thành $G_i+*n_i$; theo bổ đề 2 và $G_i\approx *n_i$, đây là trò chơi tất bại. Điều này chứng minh $G\approx G'$.
    
    Bước thứ hai, cần chứng minh $G'\approx*m$. Theo [bổ đề 2](#sg-lem-2), chỉ cần chứng minh $G'+*m$ là trò chơi tất bại. Giả sử không mất tính tổng quát rằng $G'\neq *0$. Nếu người đi trước chọn $*n_i\in *m$, thì theo định nghĩa của $m$, người đi sau có thể chọn $*n_i\in G'$, đưa cục diện trò chơi thành $*n_i + *n_i\in\mathcal P$, nên người đi trước tất bại. Nếu người đi trước chọn $*n_i\in G'$ và $n_i<m$, người đi sau có thể chọn $*n_i\in *m$, cục diện trò chơi cũng trở thành $*n_i+*n_i\in\mathcal P$, nên người đi trước tất bại. Cuối cùng, nếu người đi trước chọn $*n_i\in G'$ và $n_i>m$, người đi sau có thể chọn $*m\in *n_i$, cục diện trò chơi trở thành $*m+*m\in\mathcal P$, nên người đi trước tất bại. Điều này chứng minh $G'\approx *m$.
    
    Theo tính bắc cầu của quan hệ tương đương, $G\approx *m$. Như vậy quy nạp hoàn tất, chứng minh mọi trò chơi $G$ đều tương đương với một trò chơi Nim một đống.

Kết luận này cho thấy có thể gán cho mỗi trò chơi công bằng $G$ một số tự nhiên $n$ sao cho $G\approx *n$.

???+ abstract "Số Nim"
    **Số Nim** (nimber) ứng với một trò chơi công bằng $G$ là số tự nhiên duy nhất $n$ sao cho $G\approx *n$.

Hàm ánh xạ trò chơi công bằng tới số Nim này được gọi là **hàm Sprague-Grundy** (Sprague-Grundy function), viết tắt là **hàm SG**, ký hiệu $\operatorname{SG}(\cdot)$. Vì mỗi trạng thái của một trò chơi công bằng cũng là một trò chơi công bằng khác, nên với mỗi trạng thái của trò chơi công bằng đều có thể tính số Nim tương ứng, còn gọi là giá trị hàm SG tương ứng.

Từ quá trình chứng minh định lý trong phần này, có thể tính đệ quy hàm Sprague-Grundy như sau:

???+ note "Hệ quả"
    Trong trò chơi công bằng $G$, giá trị hàm Sprague-Grundy $\operatorname{SG}(x)$ ứng với một trạng thái $x$ thỏa
    
    $$
    \operatorname{SG}(x) = \operatorname{mex}\{\operatorname{SG}(x'): x'\in x\}.
    $$
    
    Trong đó, $\operatorname{mex}(A):=\min\{n\in\mathbf N:n\notin A\}$ là số tự nhiên nhỏ nhất không xuất hiện trong tập $A$.

Nói cách khác, giá trị hàm SG của một trạng thái bằng giá trị $\operatorname{mex}$ của các giá trị hàm SG của mọi trạng thái kế tiếp của nó.

Dựa vào giá trị hàm SG, tức số Nim, có thể xác định một trạng thái có tất thắng cho người đi trước hay không.

???+ note "Hệ quả"
    Một trạng thái $x$ trong trò chơi công bằng $G$ là trạng thái tất thắng cho người đi trước khi và chỉ khi $\operatorname{SG}(x)\neq 0$.

Cuối cùng, giá trị hàm SG của tổng các trò chơi chính là tổng Nim, tức XOR, của các giá trị hàm SG của những trò chơi con.

???+ note "Định lý (Sprague-Grundy)"
    Với các trò chơi công bằng $G_1,G_2,\cdots,G_n$, có
    
    $$
    \operatorname{SG}(G_1+ G_2+\cdots + G_n) = \operatorname{SG}(G_1)\oplus \operatorname{SG}(G_2)\oplus\cdots\oplus\operatorname{SG}(G_n).
    $$

??? note "Chứng minh"
    Vì $*a_1+ *a_2 + \cdots + *a_n$ chính là trò chơi Nim có số đá là $(a_1,a_2,\cdots,a_n)$, nên theo kết luận của trò chơi Nim, trò chơi
    
    $$
    *a_1+ *a_2 + \cdots + *a_n + *(a_1\oplus a_2\oplus\cdots\oplus a_n)
    $$
    
    là tất bại cho người đi trước. Theo [bổ đề 2](#sg-lem-2), có
    
    $$
    *a_1+ *a_2 + \cdots + *a_n \approx *(a_1\oplus a_2\oplus\cdots\oplus a_n).
    $$
    
    Do đó
    
    $$
    \operatorname{SG}(*a_1 + *a_2 + \cdots + *a_n) = a_1\oplus a_2\oplus\cdots\oplus a_n.
    $$
    
    Đặt $a_i=\operatorname{SG}(G_i)$, khi đó $G_i\approx *a_i$. Dùng các tính chất đại số của $\approx$, có
    
    $$
    (G_1+ G_2+\cdots + G_n) + (*a_1 + *a_2 + \cdots + *a_n) = \sum_{i=1}^n(G_i+*a_i) \in\mathcal P.
    $$
    
    Vì vậy
    
    $$
    \begin{aligned}
    \operatorname{SG}(G_1+ G_2+\cdots + G_n) &= \operatorname{SG}(*a_1 + *a_2 + \cdots + *a_n) \\
    &= a_1\oplus a_2\oplus \cdots \oplus a_n \\
    &= \operatorname{SG}(G_1)\oplus \operatorname{SG}(G_2)\oplus\cdots\oplus\operatorname{SG}(G_n).
    \end{aligned}
    $$

Dùng định lý này, việc tính giá trị hàm SG của tổng các trò chơi có thể được đơn giản hóa đáng kể.

Từ đó, có thể tóm tắt phương pháp tính giá trị hàm SG như sau:

-   Với nhiều trò chơi độc lập, có thể tính riêng giá trị hàm SG của từng trò chơi rồi lấy tổng Nim;
-   Với một trò chơi đơn lẻ, giá trị hàm SG của mỗi trạng thái là giá trị $\operatorname{mex}$ của các giá trị hàm SG của mọi trạng thái kế tiếp;
-   Đặc biệt, trạng thái kết thúc, tức trạng thái không có trạng thái kế tiếp, có giá trị hàm SG bằng $\operatorname{mex}\varnothing = 0$.

<span id="số-nim"></span>
### Số Nim

Mọi trò chơi công bằng đều tương ứng duy nhất với một số Nim. Tập các số Nim hữu hạn chính là tập số tự nhiên $\mathbf N$. Tuy nhiên, tính chất đại số của nó khác với tập số tự nhiên. Cụ thể, trên các số Nim có thể định nghĩa hai phép toán: tổng Nim $\oplus$ và tích Nim $\otimes$.

???+ abstract "Phép toán trên số Nim"
    Với các số Nim $a,b$, có thể định nghĩa:
    
    -   tổng Nim $a\oplus b=\operatorname{mex}(\{a'\oplus b:a'<a,~a'\in\mathbf N\}\cup\{a\oplus b':b'<b,~b'\in\mathbf N\})$,
    -   tích Nim $a\otimes b=\operatorname{mex}(\{(a'\otimes b)\oplus(a\otimes b')\oplus(a'\otimes b'):a'<a,~b'<b,~a',b'\in\mathbf N\})$.

Tập tất cả số Nim với hai phép toán $\oplus$ và $\otimes$ tạo thành một [trường](../algebra/basic.md#trường) có đặc số $2$. Hơn nữa, các phép toán này và các phép toán nghịch đảo của chúng đóng trên $2^{2^n}$ số Nim đầu tiên; từ đó nhận được một dãy các [trường hữu hạn](../algebra/field-theory.md#trường-hữu-hạn) $\mathbf F_{2^{2^n}}$ có kích thước $2^{2^n}$.

<span id="các-trò-chơi-công-bằng-thường-gặp"></span>
## Các trò chơi công bằng thường gặp

Dù lý thuyết Sprague-Grundy giải quyết hoàn toàn bài toán của trò chơi công bằng, khi xử lý các trò chơi công bằng thực tế, việc trực tiếp áp dụng định lý Sprague-Grundy thường vẫn không hiệu quả. Ví dụ, trong trò chơi Nim, độ phức tạp của cách tính vét cạn giá trị Sprague-Grundy là cấp số mũ. Vì vậy, thường cần lập bảng để phỏng đoán kết luận cụ thể cho từng trò chơi công bằng.

Phần này liệt kê một số trò chơi công bằng thường gặp và kết luận tương ứng. Khi trình bày kết luận, phần này chỉ nêu quy tắc phán định trạng thái tất thắng và tất bại. Còn chiến lược thắng là thực hiện thao tác thích hợp sao cho cục diện để lại cho đối thủ đúng là trạng thái tất bại. Vì các biến thể của những trò chơi này thường xuất hiện trong lập trình thi đấu, việc nắm được quá trình chứng minh kết luận của từng trò chơi cũng rất quan trọng.

???+ info "Phương pháp chứng minh các kết luận trong phần này"
    Các chứng minh kết luận trong phần này đều mang tính kiểm chứng. Với một trò chơi, kết luận sẽ mô tả các trạng thái người đi trước tất bại và tất thắng. Trong chứng minh, chỉ cần kiểm tra rằng từ một trạng thái người đi trước tất bại chỉ có thể đi tới trạng thái người đi trước tất thắng; còn từ một trạng thái người đi trước tất thắng luôn có thể đi tới ít nhất một trạng thái người đi trước tất bại. Để viết các chứng minh này thành chứng minh chặt chẽ, cần xây dựng đồ thị trò chơi rồi áp dụng quy nạp toán học trên đồ thị đó; các bước kiểm chứng nói trên chính là phần quy nạp.

<span id="trò-chơi-bachet"></span>
### Trò chơi Bachet

So với Nim một đống, trò chơi Bachet giới hạn số đá có thể lấy trong mỗi lượt.

???+ abstract "Trò chơi Bachet"
    Có một đống đá gồm $n$ viên. Hai người chơi lần lượt lấy đi ít nhất $1$ viên và nhiều nhất $k$ viên đá. Người lấy viên đá cuối cùng thắng.

Với trò chơi này, có kết luận sau:

???+ note "Định lý"
    Người đi trước tất bại khi và chỉ khi $n\equiv 0\pmod {k+1}$.

??? note "Chứng minh 1"
    Khi $n\not\equiv 0\pmod {k+1}$, chỉ cần lấy đi $n\bmod{(k+1)}\in[1,k]$ viên đá là có thể bảo đảm đối thủ ở trạng thái tất bại. Do đó lúc này là trạng thái tất thắng cho người đi trước.
    
    Ngược lại, khi $n\equiv 0\pmod {k+1}$, hoặc đã không còn lựa chọn nào, hoặc sau khi người đi trước lấy đi $k'$ viên đá, đối thủ có thể lập tức lấy đi $k+1-k'$ viên đá để đưa cục diện trở lại trạng thái tất bại.

??? note "Chứng minh 2"
    Như một ứng dụng của định lý Sprague-Grundy, gọi $f(n)$ là giá trị hàm SG của cục diện khi còn lại $n$ viên đá.
    
    Với $n\le k$, có thể chứng minh quy nạp rằng $f(n)=n$. Điều này giống Nim một đống, vì giới hạn số đá được lấy chưa phát huy tác dụng. Với $n>k$, có thể chứng minh $f(n)=n\bmod{(k+1)}$, nên
    
    $$
    f(n) = \operatorname{mex}\{f(n-k),f(n-k+1),\cdots,f(n-1)\}.
    $$
    
    Tập này duyệt qua mọi số dư modulo $k+1$, ngoại trừ $n\bmod{(k+1)}$. Vì vậy $f(n) = n\bmod{(k+1)}$.

<span id="trò-chơi-nim-k-của-moore"></span>
### Trò chơi Nim-$k$ của Moore

So với Nim, trò chơi Nim-$k$ của Moore cho phép lấy đá từ $k$ đống cùng lúc.

???+ abstract "Trò chơi Nim-$k$ của Moore"
    Có $n$ đống đá, đống thứ $i$ có $a_i$ viên đá. Hai người chơi lần lượt lấy đi một số viên đá tùy ý từ ít nhất $1$ đống và nhiều nhất $k$ đống, nhưng không được không lấy. Người lấy viên đá cuối cùng thắng.

Với trò chơi này, có kết luận sau:

???+ note "Định lý"
    Biểu diễn số đá của mỗi đống dưới dạng nhị phân. Với mỗi vị trí bit $d$, đếm có bao nhiêu đống mà bit thứ $d$ của số đá bằng $1$, rồi lấy số đếm này modulo $(k+1)$. Nếu với mọi vị trí bit, số dư này đều bằng $0$, thì người đi trước tất bại; nếu không, người đi trước tất thắng.

??? note "Chứng minh"
    Có thể chứng minh kết luận này bằng cách mô phỏng chứng minh cho Nim. Gọi $d$ là vị trí bit nhị phân cao nhất có số dư khác $0$, và số dư tương ứng là $k'\le k$. Khi đó chiến lược thắng là chọn $k'$ đống trong số các đống có bit thứ $d$ của số đá bằng $1$, rồi chọn số đá cần lấy sao cho trong cục diện của đối thủ, số dư ở mỗi vị trí bit đều bằng $0$. Điều duy nhất cần giải thích là việc chọn số đá cuối cùng luôn khả thi.
    
    Thật vậy, chỉ cần chọn $k'$ đống đá và ở mỗi đống lấy đi $2^d$ viên là có thể làm số dư ở bit thứ $d$ trong kết quả trở thành $0$. Với số dư ở các bit thấp hơn, có thể phân bổ tùy ý các số dư này cho một đống nào đó.

<span id="trò-chơi-nim-bậc-thang"></span>
### Trò chơi Nim bậc thang

Trò chơi Nim bậc thang phức tạp hơn một chút: nó cho phép di chuyển đá giữa các đống kề nhau.

???+ abstract "Trò chơi Nim bậc thang"
    Có $n$ đống đá, đống thứ $i$ có $a_i$ viên đá. Hai người chơi lần lượt thao tác. Trong mỗi thao tác, hoặc lấy đi tùy ý nhiều viên đá từ đống thứ $1$, hoặc chuyển tùy ý nhiều viên đá từ đống thứ $i>1$ sang đống thứ $i-1$, nhưng không được không làm gì. Người lấy viên đá cuối cùng thắng.

Với trò chơi này, có kết luận sau:

???+ note "Định lý"
    Người đi trước tất bại khi và chỉ khi tổng Nim của số đá ở các đống lẻ $a_1\oplus a_3\oplus\cdots\oplus a_{n-1+(n\bmod 2)}=0$.

??? note "Chứng minh"
    Khi một người chơi chuyển đá từ đống chẵn sang đống lẻ, đối thủ có thể tiếp tục chuyển số đá đó sang đống chẵn tiếp theo, hoặc lấy đi, nên nước đi như vậy không ảnh hưởng tới cục diện của các đống lẻ. Lúc này, mỗi việc chuyển một đống lẻ xuống đống chẵn kề dưới, hoặc lấy đi, có thể xem như một trò chơi Nim một đống độc lập. Theo kết luận của định lý Sprague-Grundy về tổng trò chơi, giá trị hàm SG của Nim bậc thang là tổng Nim của các giá trị hàm SG của những trò chơi con này. Từ đó nhận được kết luận trên.

<span id="trò-chơi-fibonacci-nim"></span>
### Trò chơi Fibonacci Nim

Fibonacci Nim giống trò chơi Bachet ở chỗ chỉ có một đống đá và giới hạn số lượng được lấy mỗi lượt. Khác với Bachet, trong Fibonacci Nim, giới hạn số lượng được lấy là động.

???+ abstract "Trò chơi Fibonacci Nim"
    Có một đống đá gồm $n$ viên. Hai người chơi lần lượt lấy đá. Người hành động đầu tiên không bị giới hạn số đá được lấy, nhưng không được lấy hết đá; sau đó, mỗi lượt không được lấy quá hai lần số đá đã được lấy ở lượt trước, tức lượt của đối thủ. Số đá lấy mỗi lượt không được bằng $0$. Người lấy viên đá cuối cùng thắng.

Với trò chơi này, có kết luận sau:

???+ note "Định lý"
    Khi trò chơi bắt đầu, người đi trước tất bại khi và chỉ khi số đá $n$ là một [số Fibonacci](../combinatorics/fibonacci.md).

??? note "Chứng minh"
    Gọi $q$ là hạn mức (quota) số đá có thể lấy ở cục diện hiện tại. Trong lượt đầu tiên, $q=n-1$; còn ở các lượt sau, $q$ bằng hai lần số đá mà đối thủ lấy ở lượt trước. Xét [mã hóa Fibonacci](../combinatorics/fibonacci.md#mã-hóa-fibonacci) của số đá còn lại $n$, tức phân rã duy nhất $n$ thành tổng của một dãy các số Fibonacci dương không kề nhau. Cần chứng minh rằng trạng thái hiện tại là tất thắng khi và chỉ khi $q$ lớn hơn hoặc bằng số Fibonacci nhỏ nhất trong phân rã của $n$.
    
    Chiến lược thắng là: nếu có thể thì lấy hết số đá còn lại; nếu không thì lấy đi số Fibonacci nhỏ nhất trong phân rã. Vì trong phân rã, số Fibonacci nhỏ thứ hai luôn lớn nghiêm ngặt hơn hai lần số Fibonacci nhỏ nhất, nên nếu lượt hiện tại ở trạng thái tất thắng không thể lấy hết đá, thì ở lượt sau đối thủ cũng không thể lấy số Fibonacci nhỏ thứ hai, tức số Fibonacci nhỏ nhất của lượt sau; đối thủ nhất định ở trạng thái tất bại.
    
    Ngược lại, nếu hiện tại là trạng thái tất bại, giả sử số đá được lấy hiện tại là $k$, thì nó nhỏ nghiêm ngặt hơn số Fibonacci nhỏ nhất $F$ trong phân rã hiện tại. Giả sử số Fibonacci nhỏ nhất ở lượt sau là $F'$, nó cũng là số Fibonacci nhỏ nhất trong phân rã ứng với $F - k$. Đặt $F'=F''+F'''$ và $F''>F'''$, tức $F''',F'',F'$ là ba số Fibonacci kề nhau. Nếu $k<F''$, thì khi dùng mã hóa Fibonacci để tính $k + (F-k)$, không cần nhớ, nên không thể thu được $F$. Vì vậy có $k\ge F''$. Điều này cho thấy hạn mức lượt sau $2k>F''+F'''=F'$, nên đó là trạng thái tất thắng.

<span id="trò-chơi-wythoff"></span>
### Trò chơi Wythoff

Trò chơi Wythoff cho phép loại bỏ đá đồng thời từ nhiều đống, nhưng yêu cầu mỗi đống bị loại bỏ cùng một số lượng đá.

???+ abstract "Trò chơi Wythoff"
    Có hai đống đá, lần lượt có $a_1$ và $a_2$ viên đá. Hai người chơi lần lượt lấy đá từ một đống hoặc hai đống; không được không lấy, và nếu lấy từ cả hai đống thì số đá lấy từ hai đống phải bằng nhau. Người lấy viên đá cuối cùng thắng.

Với trò chơi này, có kết luận sau:

???+ note "Định lý"
    Không mất tính tổng quát, giả sử $a_1\le a_2$. Khi đó người đi trước tất bại khi và chỉ khi $a_1 = \lfloor(a_2-a_1)\phi\rfloor$, trong đó $\phi=(\sqrt{5}+1)/2$ là tỉ lệ vàng.

Để chứng minh kết luận này, cần dùng bổ đề sau:

???+ abstract "Dãy Beatty"
    Cho $r > 1$ là số vô tỉ. Dãy Beatty do nó sinh ra là $\mathcal B_r = \{\lfloor kr\rfloor : k \in\mathbf N_+\}$.

???+ note "Định lý Rayleigh"
    Cho $r,s > 1$ là hai số vô tỉ và $\dfrac{1}{r}+\dfrac{1}{s}=1$. Khi đó hai dãy $\mathcal B_r$ và $\mathcal B_s$ tạo thành một phân hoạch của tập số nguyên dương $\mathbf N_+$. Lúc này chúng còn được gọi là hai dãy Beatty bổ sung.

??? note "Chứng minh"
    Đặt $\mathcal A_r=\{kr:k\in\mathbf N_+\}$. Xét việc sắp xếp các phần tử trong tập $\mathcal A=\mathcal A_r\cup\mathcal A_s$ để nhận được dãy $\{a_i\}_{i\in\mathbf N_+}$. Cần chứng minh $i=\lfloor a_i\rfloor$ với mọi $i\in\mathbf N_+$; khi đó sẽ suy ra $\mathcal B_r\cup\mathcal B_s$ là một phân hoạch của tập số nguyên dương $\mathbf N_+$.
    
    Trước hết, chứng minh dãy không có phần tử trùng nhau. Giả sử ngược lại, tồn tại $k,\ell\in\mathbf N_+$ sao cho $kr=\ell s$. Khi đó
    
    $$
    \dfrac{\ell}{k} = \dfrac{r}{s} = r - 1.
    $$
    
    Nhưng vế trái là số hữu tỉ, còn vế phải là số vô tỉ, mâu thuẫn. Vì vậy các số trong dãy đôi một khác nhau.
    
    Tiếp theo, chứng minh trong tập $\mathcal A$ có đúng $\lfloor a_i\rfloor$ số nhỏ hơn hoặc bằng $a_i$. Không mất tính tổng quát, giả sử $a_i\in\mathcal A_r$, tức $a_i=kr$. Đếm riêng các phần tử trong $\mathcal A_r$ và $\mathcal A_s$, thu được số phần tử nhỏ hơn hoặc bằng $a_i$ là
    
    $$
    k + \left\lfloor\dfrac{kr}{s}\right\rfloor = k + \lfloor k(r-1)\rfloor = \lfloor kr\rfloor = \lfloor a_i\rfloor.
    $$
    
    Mặt khác, vì dãy $\{a_i\}$ tăng nghiêm ngặt, số phần tử nhỏ hơn hoặc bằng $a_i$ đúng bằng $i$. Do đó $i=\lfloor a_i\rfloor$.

Từ đây có thể chứng minh kết luận đã nêu.

??? note "Chứng minh kết luận của trò chơi Wythoff"
    Với mọi trạng thái $(a_1,a_2)$ thỏa $a_1 < a_2$ và người đi trước tất bại, đặt $k = a_2 - a_1 \in\mathbf N_+$. Khi đó $a_1=\lfloor k\phi\rfloor$ và $a_2=\lfloor k(\phi+1)\rfloor$. Vì $\phi$ là tỉ lệ vàng, có $\dfrac{1}{\phi}+\dfrac{1}{\phi+1}=1$. Theo định lý Rayleigh, các dãy $\{\lfloor k\phi\rfloor\}$ và $\lfloor k(\phi+1)\rfloor$ tạo thành một phân hoạch của tập số nguyên dương $\mathbf N_+$. Điều này nghĩa là trong mọi trạng thái $(a_1,a_2)$ thỏa $a_1 < a_2$ và người đi trước tất bại, hai thành phần $a_1$ và $a_2$ lấy đúng một lần mọi số nguyên dương, và hiệu của chúng $a_2-a_1$ cũng lấy đúng một lần mọi số nguyên dương.
    
    Trong trò chơi Wythoff, một thao tác hợp lệ hoặc giữ nguyên một trong hai thành phần, hoặc giữ nguyên hiệu của hai thành phần. Vì vậy, từ một trạng thái người đi trước tất bại, không thể nhận được một trạng thái người đi trước tất bại khác chỉ bằng một thao tác hợp lệ. Ngược lại, với bất kỳ trạng thái người đi trước tất thắng $(a_1,a_2)$, giả sử không mất tính tổng quát rằng $a_1\le a_2$ và đặt $k=a_2-a_1$. Nếu $a_1>\lfloor k\phi\rfloor$, người đi trước có thể lấy từ mỗi đống $(a_1 - \lfloor k\phi\rfloor)$ viên đá để biến cục diện thành trạng thái tất bại. Ngược lại, theo kết luận ở đoạn trước, với $a_1$ này tồn tại duy nhất một trạng thái tất bại $(a_1,a_2')$. Tiếp đó, nếu $a_1 > a_2'$ thì $a_2' < a_2$; còn nếu $a_1 < a_2'$, lấy $k'=a_2'-a_1$ sao cho $a_1=\lfloor k'\phi\rfloor$. Lại có $a_1 < \lfloor k\phi\rfloor$, nên $k' < k$, do đó $a_2'=a_1 + k' < a_1+k = a_2$. Vì vậy, miễn là $a_1 < \lfloor k\phi\rfloor$, nhất định có $a_2' < a_2$; người đi trước chỉ cần lấy đi $(a_2-a'_2)$ viên đá từ đống thứ hai là có thể biến cục diện thành trạng thái tất bại.

<span id="trò-chơi-lật-đồng-xu"></span>
### Trò chơi lật đồng xu

Trò chơi lật đồng xu cũng là một lớp trò chơi tổ hợp công bằng thường gặp.

???+ abstract "Trò chơi lật đồng xu"
    Cho $(S,\preceq)$ là một [tập có thứ tự bộ phận nền tảng](../order-theory.md), ánh xạ $f:S\rightarrow\mathcal P\mathcal PS$ thỏa với mọi $s\in S$, tập $f(s)$ không rỗng; với mọi $T\in f(s)$ đều có $s\in T$; hơn nữa với mọi $t\in T$ đều có $t\preceq s$. Tại mỗi phần tử của tập $S$ đặt một đồng xu, có thể ngửa hoặc sấp. Hai người chơi lần lượt hành động: chọn một đồng xu ngửa $s$ và một tập $T\in f(s)$, rồi lật tất cả đồng xu trong tập $T$. Người lật tất cả đồng xu thành mặt sấp thắng.

Trò chơi lật đồng xu là một lớp lớn các trò chơi. Tùy theo lựa chọn cụ thể của tập thứ tự bộ phận $S$ và ánh xạ $f$, hình thức cụ thể của trò chơi lật đồng xu cũng khác nhau. Trong mô tả trò chơi, các điều kiện mà ánh xạ $f$ cần thỏa đang nói rằng trong tập đồng xu $T$ được người chơi chọn để lật mỗi lượt, phải tồn tại một đồng xu ngửa $s$ sao cho mọi phần tử trong $T$ đều đứng trước $s$. Điều này bảo đảm trò chơi có thể kết thúc sau hữu hạn bước.

???+ example "Ví dụ"
    1.  Cho $S=\{1,2,\cdots,n\}$ và $f(s)=\{\{t,s\}:t \le s\}$. Điều này tương đương với việc có một hàng $n$ đồng xu; mỗi lần lật một đồng xu đang ngửa và có thể chọn thêm một đồng xu ở bên trái nó để lật.
    2.  Cho $S=\{1,2,\cdots,n\}$ và $f(s)=\{[t,s]:t \le s\}$. Điều này tương đương với việc có một hàng $n$ đồng xu; mỗi lần lật một đoạn đồng xu liên tiếp, nhưng phải bảo đảm đồng xu ngoài cùng bên phải trong đoạn đó đang ngửa trước khi lật.
    3.  Cho $S=\{1,2,\cdots,n\}^2$ và $f(s)=\{\{s\}\}$. Điều này tương đương với việc có $n$ hàng và $n$ cột đồng xu; mỗi lần chỉ được lật một đồng xu đang ngửa.
    4.  Cho $S$ là tập đỉnh của một cây có gốc, và $f(s)$ là tập gồm mọi tập con chứa chính $s$ trong các tập con của tập đỉnh trên đường đi từ đỉnh $s$ tới gốc. Điều này tương đương với việc có một cây có gốc, tại mỗi đỉnh đặt một đồng xu; mỗi lần lật một đồng xu đang ngửa và có thể chọn thêm một số đồng xu ở các tổ tiên của nó để lật.

Dù có rất nhiều loại trò chơi lật đồng xu, hướng giải của chúng là thống nhất. Với trò chơi lật đồng xu $(S,f)$, gọi $G_s$ là cục diện chỉ có đồng xu tại phần tử $s$ ngửa. Các cục diện này được gọi là cục diện cơ sở. Khi đó, một cục diện bất kỳ $G$ đều có thể xem là tổng của các trò chơi tương ứng với những cục diện cơ sở này. Nói cách khác, kết luận sau đúng:

???+ note "Định lý"
    Với trò chơi lật đồng xu $(S,f)$ và cục diện $G$, gọi tập vị trí của các đồng xu ngửa trong đó là $H(G)\subseteq S$. Khi đó giá trị hàm SG của cục diện $G$ là
    
    $$
    \operatorname{SG}(G) = \bigoplus_{s\in H(G)}\operatorname{SG}(G_s).
    $$

??? note "Chứng minh"
    Xét một trò chơi liên quan: trong một cục diện $G'$, tại mỗi phần tử của tập $S$ đặt một số viên đá; mỗi lượt, người chơi có thể lấy đi một viên đá tại $s$, chọn một tập $T\in f(s)$, rồi đặt thêm một viên đá tại mỗi phần tử trong $T\setminus\{s\}$. Với loại trò chơi này, vẫn có thể định nghĩa cục diện cơ sở $G'_s$, tức cục diện chỉ đặt một viên đá tại vị trí $s$. Trong loại trò chơi này, mỗi cục diện đều là tổng của các cục diện cơ sở ứng với mọi viên đá của nó. Lý do là khi đặt đá mới, viên đá mới được gắn với viên đá vừa bị lấy đi; như vậy mỗi viên đá xuất hiện trong quá trình chơi đều có thể được gắn với một viên đá ở cục diện ban đầu. Tiếp đó, tiến trình trò chơi con ứng với các viên đá khác nhau ở cục diện ban đầu không can thiệp lẫn nhau, nên toàn bộ trò chơi có thể xem là tổng của các trò chơi con này. Vì các viên đá ở cùng vị trí ứng với cùng một giá trị SG của cục diện cơ sở, dựa vào tính chất của XOR, giá trị SG của cục diện $G'$ chỉ phụ thuộc vào tính chẵn lẻ của số đá ở từng đống, không phụ thuộc vào số lượng cụ thể. Vì vậy, với cục diện $G'$, nếu ký hiệu tập các vị trí có số đá lẻ là $H(G')$, thì phân tích trong đoạn này có thể tóm tắt bằng công thức:
    
    $$
    \operatorname{SG}(G') = \bigoplus_{s\in H(G')} \operatorname{SG}(G'_s).
    $$
    
    Từ đó, phần còn lại chỉ cần thiết lập tính tương đương giữa trò chơi $G'$ và trò chơi $G$ là chứng minh được công thức trong định lý.
    
    Cần chứng minh rằng với cục diện $G'$ của trò chơi mới và cục diện $G$ của trò chơi lật đồng xu, nếu các vị trí có số đá lẻ trong $G'$ đúng bằng các vị trí có đồng xu ngửa trong $G$, thì $G'$ và $G$ tương đương. Theo [bổ đề 2 của định lý Sprague-Grundy](#sg-lem-2), điều này tương đương với việc chứng minh cục diện $G+G'$ là trạng thái tất bại. Chiến lược thắng của người đi sau rất đơn giản: nếu người đi trước chọn lấy đi một viên đá tại $s$ và ở đó có hơn một viên đá, người đi sau trực tiếp bắt chước hành vi của người đi trước; nếu không, người đi sau chọn cùng $s$ và cùng $T\in f(s)$ với người đi trước, nhưng chọn trò chơi con khác với người đi trước, tức người đi trước lấy đá thì người đi sau lật xu, còn người đi trước lật xu thì người đi sau lấy đá. Với bất kỳ thao tác nào của người đi trước, người đi sau đều có thể tiếp tục thao tác và bảo đảm trong cục diện còn lại, các vị trí có số đá lẻ trùng với các vị trí có đồng xu ngửa. Như vậy trò chơi tất yếu kết thúc khi người đi trước không có thao tác hợp lệ, nên người đi trước tất bại. Định lý được chứng minh.

Dùng kết luận này, để phán định một cục diện có tất thắng hay không, chỉ cần tính giá trị hàm SG của các cục diện cơ sở ứng với mọi đồng xu đang ngửa, rồi lấy tổng Nim. Các giá trị hàm SG của cục diện cơ sở có thể tính trực tiếp, vì các cục diện kế tiếp của chúng đã được ánh xạ $f$ cho trước, và giá trị SG của cục diện kế tiếp có thể được tính quy nạp:

$$
\operatorname{SG}(G_s) = \operatorname{mex}\limits_{T\in f(s)}\bigoplus_{t\in T\setminus\{s\}}\operatorname{SG}(G_t).
$$

Điều này tương đương với việc cung cấp một công thức truy hồi cho giá trị hàm SG của cục diện cơ sở.

<span id="trò-chơi-trên-đồ-thị-hai-phía"></span>
### Trò chơi trên đồ thị hai phía

Kiến thức cần có: [ghép cặp lớn nhất trên đồ thị hai phía](../../graph/graph-matching/bigraph-match.md)

Phần cuối của mục này thảo luận trò chơi trên đồ thị hai phía. Mặc dù trò chơi này thường được gọi là trò chơi trên đồ thị hai phía, mô tả và chứng minh kết luận của nó đều không phụ thuộc vào cấu trúc hai phía của đồ thị, nên kết luận cũng đúng với đồ thị vô hướng tổng quát. Tuy nhiên, ghép cặp lớn nhất trên đồ thị tổng quát phức tạp hơn, vì vậy kết luận này thường xuất hiện trong các bài về đồ thị hai phía.

???+ abstract "Trò chơi trên đồ thị hai phía"
    Hai người chơi lần lượt hành động. Cục diện mà mỗi người chơi đối mặt gồm một đồ thị vô hướng $G=(V,E)$ và một đỉnh $v\in V$ của nó. Trong lượt của một người chơi, nếu cục diện hiện tại là $(G,v)$, người chơi đó phải chọn một đỉnh $u$ kề với $v$. Sau đó, xóa đỉnh $v$ và mọi cạnh liên thuộc với nó khỏi đồ thị $G$, thu được đồ thị còn lại $G'$. Cục diện mới là $(G',u)$ và được giao cho người chơi tiếp theo. Nếu một người chơi bắt đầu lượt của mình mà đỉnh hiện tại $v$ không có đỉnh kề trong đồ thị, tức không tồn tại lựa chọn hợp lệ, thì người chơi đó không thể hành động và thua.

Với trò chơi này, có kết luận sau:

???+ note "Định lý"
    Người đi trước tất thắng khi và chỉ khi đỉnh $v$ là điểm then chốt của ghép cặp lớn nhất trong đồ thị $G$, nghĩa là trong mọi ghép cặp lớn nhất của đồ thị $G$, đỉnh $v$ đều là đỉnh được ghép.

??? note "Chứng minh"
    Trước hết, giả sử đỉnh $v$ là điểm then chốt của ghép cặp lớn nhất trong đồ thị $G$. Gọi $M$ là một ghép cặp lớn nhất của $G$. Khi đó, người đi trước có thể chuyển cục diện tới đỉnh $u$ được ghép với $v$ trong $M$. Vì đỉnh $v$ xuất hiện trong mọi ghép cặp lớn nhất của đồ thị $G$, kích thước ghép cặp lớn nhất của đồ thị còn lại $G'$ nhiều nhất là $|M|-1$; hơn nữa, bỏ cạnh $(v,u)$ khỏi $M$ sẽ thu được một ghép cặp $M'$ của đồ thị $G'$ có kích thước $|M|-1$. Kết hợp hai điểm này, $M'$ là một ghép cặp lớn nhất của đồ thị $G'$. Tuy nhiên, trong cục diện của người đi sau, đỉnh $u$ không phải là đỉnh được ghép trong ghép cặp $M'$. Vì vậy, người đi sau tất yếu ở trạng thái tất bại.
    
    Ngược lại, giả sử tồn tại một ghép cặp lớn nhất $M$ sao cho $v$ là đỉnh chưa ghép. Vì $M$ là ghép cặp lớn nhất, mọi đỉnh kề với $v$ nhất định là đỉnh được ghép; nếu không, có thể thêm cạnh giữa chúng vào $M$ để nhận được một ghép cặp lớn hơn. Do đó, bất kể người đi trước chọn thế nào, người đi sau đều ở trạng thái tất thắng.

Thuật toán tìm các điểm then chốt của ghép cặp lớn nhất trên đồ thị hai phía xem tại [trang ghép cặp lớn nhất trên đồ thị hai phía](../../graph/graph-matching/bigraph-match.md#đỉnh-then-chốt-của-ghép-cặp-lớn-nhất).

Ngoài ra, trò chơi trên đồ thị hai phía còn có một biến thể:

???+ abstract "Biến thể của trò chơi trên đồ thị hai phía"
    Cho $G=(V,E)$ là một đồ thị vô hướng, và trên mỗi đỉnh của đồ thị đặt một viên đá. Hai người chơi lần lượt hành động để lấy đá. Khi trò chơi bắt đầu, người đi trước có thể lấy đi bất kỳ viên đá nào; ở các lượt sau, mỗi người chơi phải lấy viên đá tại một đỉnh kề với đỉnh mà đối phương đã lấy đá ở lượt trước. Người đầu tiên không thể lấy đá thua.

Biến thể này tương đương với việc trong trò chơi trên đồ thị hai phía ở trên, cho người đi trước chọn cục diện ban đầu, rồi để người đi sau bắt đầu trò chơi trên đồ thị hai phía. Vì vậy, trong biến thể này, người đi trước tất bại khi và chỉ khi mọi đỉnh đều là điểm then chốt của ghép cặp lớn nhất, tức đồ thị $G$ tồn tại [ghép cặp hoàn hảo](../../graph/graph-matching/graph-match.md#sự-tồn-tại-của-ghép-cặp-hoàn-hảo).

<span id="trò-chơi-nim-luật-ngược"></span>
## Trò chơi Nim luật ngược

Phần này thảo luận cách giải Nim luật ngược.

???+ abstract "Trò chơi Nim"
    Có $n$ đống đá, đống thứ $i$ có $a_i$ viên đá. Hai người chơi lần lượt lấy đi một số viên đá tùy ý từ một đống tùy ý, nhưng không được không lấy. Người lấy viên đá cuối cùng thua.

Với trò chơi này, có kết luận sau:

???+ note "Định lý"
    Trong Nim luật ngược, trạng thái $(a_1,a_2,\cdots,a_n)$ là trạng thái tất bại $\mathcal P$ khi và chỉ khi
    
    1.  tồn tại $i$ sao cho $a_i>1$, và tổng Nim $a_1\oplus a_2\oplus\cdots\oplus a_n=0$; hoặc
    2.  với mọi $i$ đều có $a_i\le 1$, và số đống đá còn lại không rỗng là số lẻ.

??? note "Chứng minh"
    Vì không thể thao tác là trạng thái tất thắng cho người đi trước $\mathcal N$, có thể chứng minh quy nạp rằng nếu mỗi đống đá đều chỉ có một viên, thì số đống đá lẻ tương ứng với trạng thái tất bại cho người đi trước $\mathcal P$, còn số đống đá chẵn tương ứng với trạng thái tất thắng cho người đi trước $\mathcal N$.
    
    Tiếp theo, xét trường hợp có một số đống đá có số lượng lớn hơn nghiêm ngặt $1$.
    
    Trường hợp A: nếu chỉ có một đống đá có số lượng lớn hơn nghiêm ngặt $1$, thì lúc này tổng Nim khác $0$. Hơn nữa, vì người đi trước có thể chọn chuyển sang cục diện mà số đá ở mọi đống đều không vượt quá $1$, đồng thời có thể kiểm soát tính chẵn lẻ của số đống đá không rỗng còn lại, nên đây là trạng thái tất thắng cho người đi trước $\mathcal N$.
    
    Trường hợp B: hiện có hơn một đống đá có số lượng lớn hơn nghiêm ngặt $1$. Khi đó dù thao tác thế nào, trong cục diện tiếp theo vẫn có ít nhất một đống đá có số lượng lớn hơn nghiêm ngặt $1$. Theo giả thiết quy nạp, trong cục diện tiếp theo, người đi trước tất bại tương ứng với tổng Nim bằng không, còn người đi trước tất thắng tương ứng với tổng Nim khác không. Điều này hoàn toàn giống giả thiết quy nạp của Nim bình thường. Vì vậy, lặp lại lập luận của trò chơi Nim, cục diện hiện tại cũng thỏa kết luận rằng tổng Nim bằng không tương ứng với trạng thái người đi trước tất bại.

<span id="trò-chơi-trên-đồ-thị-có-hướng"></span>
## Trò chơi trên đồ thị có hướng

Các trò chơi tổ hợp công bằng được thảo luận trong bài này yêu cầu cùng một cục diện không thể xuất hiện hai lần, và không có khả năng hòa. Do đó, đồ thị trò chơi tương ứng luôn là đồ thị có hướng không chu trình. Phần này nới lỏng hạn chế đó và thảo luận cách phán định từng trạng thái trên một đồ thị có hướng tổng quát là người đi trước tất thắng, người đi trước tất bại hay hòa.

Luật của trò chơi trên đồ thị có hướng về cơ bản giống các trò chơi tổ hợp công bằng khác: bắt đầu từ trạng thái khởi đầu, hai người chơi lần lượt di chuyển một bước dọc theo cạnh có hướng cho tới khi không còn đường đi. Tùy theo trò chơi là luật bình thường hay luật ngược, người chơi cuối cùng không thể di chuyển lần lượt là người thua hoặc người thắng. Trong trò chơi như vậy, tình trạng thắng thua của mỗi trạng thái có ba khả năng: người đi trước tất thắng, người đi trước tất bại, hoặc hòa. Khi hòa, trò chơi sẽ không bao giờ kết thúc. Dù phức tạp hơn một chút, [bổ đề](#np-lem) về trạng thái tất bại và tất thắng vẫn đúng, còn các trạng thái còn lại là trạng thái hòa:

-   Một trạng thái có trạng thái kế tiếp mà người đi trước tất thắng khi và chỉ khi một trong các trạng thái kế tiếp là tất bại;
-   Nếu một trạng thái có trạng thái kế tiếp, thì người đi trước tất bại khi và chỉ khi mọi trạng thái kế tiếp đều là tất thắng;
-   Nếu một trạng thái không thể được phân loại là tất thắng hay tất bại, thì nó là trạng thái hòa.

Để phân loại mọi trạng thái thành ba loại này, chỉ cần dùng ý tưởng tương tự [sắp xếp tô pô](../../graph/topo.md):

1.  Khi khởi tạo, ghi lại bậc ra của mọi trạng thái, đẩy mọi trạng thái có bậc ra bằng không vào hàng đợi, và tùy theo trò chơi là luật bình thường hay luật ngược mà lần lượt đặt chúng là trạng thái tất bại hoặc tất thắng.
2.  Lấy trạng thái đầu hàng đợi ra. Nếu đó là trạng thái tất bại, đặt trạng thái tiền nhiệm là tất thắng; nếu không, trạng thái hiện tại là tất thắng, giảm bậc ra của mọi trạng thái tiền nhiệm của nó đi một, và đặt trạng thái tiền nhiệm có bậc ra bằng không là tất bại. Đẩy các trạng thái tiền nhiệm đã có thể xác định là tất thắng hoặc tất bại vào hàng đợi.
3.  Thuật toán kết thúc khi hàng đợi rỗng. Mọi trạng thái chưa được xác định là tất thắng hoặc tất bại đều là trạng thái hòa.

Thuật toán này có thể phân loại mọi trạng thái trong thời gian $O(|V|+|E|)$.

<span id="bài-tập-ví-dụ"></span>
## Bài tập ví dụ

Phần này thảo luận một số bài tập điển hình.

???+ example "[Luogu P2148 \[SDOI2009\] E&D](https://www.luogu.com.cn/problem/P2148)"
    Có $2n$ đống đá. Với $k=1,2,\cdots,n$, hai đống đá $2k-1$ và $2k$ tạo thành một nhóm. Hai người chơi lần lượt thao tác: mỗi lần chọn một nhóm đống đá, bỏ đi một trong hai đống, rồi chia đống còn lại thành hai đống không rỗng và đặt vào hai vị trí của nhóm đó. Nếu mọi đống đá đều chỉ có một viên, người chơi hiện tại không có thao tác hợp lệ và thua. Cho số đá của mỗi đống $\{a_i\}_{i=1}^{2n}$, hỏi cục diện có tất thắng cho người đi trước hay không.

??? note "Lời giải"
    Trò chơi ở các nhóm đống đá khác nhau độc lập với nhau. Vì vậy, chỉ cần tính giá trị hàm SG của mỗi nhóm là có thể tính giá trị SG của toàn bộ trò chơi, từ đó phán định có phải trạng thái tất thắng hay không. Điểm mấu chốt là tính giá trị hàm SG của mỗi nhóm đống đá như thế nào. Điều này không dễ. Một hướng thường gặp khi giải các bài lý thuyết trò chơi loại này là lập bảng. Gọi giá trị SG là $f(i,j)$ khi trong một nhóm, số đá ở hai đống lần lượt là $(i,j)$. Viết một chương trình vét cạn lập bảng sẽ nhận được kết quả sau:
    
    ```text
    0 1 0 2 0 1 0 3 0 1 0 2 0 1 0 4 
    1 1 2 2 1 1 3 3 1 1 2 2 1 1 4 4
    0 2 0 2 0 3 0 3 0 2 0 2 0 4 0 4
    2 2 2 2 3 3 3 3 2 2 2 2 4 4 4 4
    0 1 0 3 0 1 0 3 0 1 0 4 0 1 0 4
    1 1 3 3 1 1 3 3 1 1 4 4 1 1 4 4
    0 3 0 3 0 3 0 3 0 4 0 4 0 4 0 4
    3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4
    0 1 0 2 0 1 0 4 0 1 0 2 0 1 0 4
    1 1 2 2 1 1 4 4 1 1 2 2 1 1 4 4
    0 2 0 2 0 4 0 4 0 2 0 2 0 4 0 4
    2 2 2 2 4 4 4 4 2 2 2 2 4 4 4 4
    0 1 0 4 0 1 0 4 0 1 0 4 0 1 0 4
    1 1 4 4 1 1 4 4 1 1 4 4 1 1 4 4
    0 4 0 4 0 4 0 4 0 4 0 4 0 4 0 4
    4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
    ```
    
    Bảng này có quy luật rất rõ. Một quan sát đơn giản là bảng được chia thành nhiều ma trận $2\times 2$, trong đó góc trái trên luôn là $0$, còn ba giá trị còn lại luôn giống nhau. Vì vậy, có thể nén bảng này bằng cách nén mỗi ma trận $2\times 2$ thành giá trị chung ngoài góc trái trên:
    
    ```text
    1 2 1 3 1 2 1 4 
    2 2 3 3 2 2 4 4 
    1 3 1 3 1 4 1 4 
    3 3 3 3 4 4 4 4 
    1 2 1 4 1 2 1 4 
    2 2 4 4 2 2 4 4 
    1 4 1 4 1 4 1 4 
    4 4 4 4 4 4 4 4 
    ```
    
    Bảng nén này bằng giá trị ở cùng vị trí trong bảng đầy đủ phía trước cộng thêm một. Đến đây bài toán đã được giải quyết. Giả sử chỉ số bắt đầu từ $0$, giá trị $g(i,j)$ tại vị trí $(i,j)$ của bảng có thể được cho bởi công thức truy hồi:
    
    $$
    g(i,j) =
    \begin{cases}
    0, & \text{nếu }2\mid i\text{ và }2\mid j,\\
    g(\lfloor i/2\rfloor,\lfloor j/2\rfloor)+1,& \text{ngược lại}.
    \end{cases}
    $$
    
    Hàm SG cần tìm là $f(i,j)=g(i-1,j-1)$. Dùng công thức truy hồi này, thuật toán có thể tính giá trị $f(i,j)$ trong thời gian $O(\log\min\{i,j\})$.
    
    Bằng quy nạp đơn giản, $g(i,j)$ là số lần ít nhất cần đồng thời chia $i$ và $j$ cho $2$ cho tới khi nhận được hai số chẵn. Nói cách khác, nó chính là số bit $1$ liên tiếp ở cuối trong phép OR bit của $i$ và $j$. Từ đó cũng có thể trực tiếp dùng `__builtin_ctz(~(i | j))` để tính giá trị này.
    
    Trong loại bài này, sau khi quan sát từ bảng và nhận được biểu thức hàm SG, biểu thức đó thường dễ chứng minh bằng quy nạp; vì vậy điểm mấu chốt khi giải bài là thu được các kết luận này bằng một hình thức nào đó, chứ không phải suy diễn từ đầu. Ví dụ, sau khi biết kết luận, quan hệ truy hồi trong bài này có thể được chứng minh quy nạp như sau. Gọi $S_k$ là tập các giá trị SG của các cục diện có thể nhận được khi chia $k$ viên đá thành hai đống không rỗng. Khi đó $f(i,j) = \operatorname{mex}(S_i \cup S_j)$. Vì vậy $S_k$ có quan hệ truy hồi:
    
    $$
    S_k = \{\operatorname{mex}(S_i \cup S_j) : i + j = k,~i,j\in\mathbf N_+\}.
    $$
    
    Cần chứng minh rằng $d\in S_k$ khi và chỉ khi trong biểu diễn nhị phân của $(k-1)$, bit thứ $d$ với bit thấp nhất là bit thứ $0$ bằng $1$.
    
    Dùng quy nạp toán học. Cơ sở quy nạp $S_1=\varnothing$ đúng. Giả sử mệnh đề đúng với mọi số nguyên dương nhỏ hơn $k$. Khi đó $d\in S_k$ khi và chỉ khi tồn tại $i,j\in\mathbf N_+$ sao cho $i+j=k$, đồng thời trong hai số $(i-1)$ và $(j-1)$, ở mỗi bit $d' < d$ có ít nhất một số có bit bằng $1$, còn bit thứ $d$ của cả hai đều bằng $0$. Tồn tại một cách chia như vậy khi và chỉ khi nếu chỉ xét phần gồm các bit $0\sim d$, tức xét modulo $2^{d+1}$, giá trị của $(k-1)=(i-1)+(j-1)+1$ nằm trong khoảng $[2^d,2^{d+1}-1)$. Điều kiện này tương đương với bit thứ $d$ của $(k-1)$ bằng $1$. Từ đó bước quy nạp đúng, và mệnh đề ban đầu được chứng minh.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/impartial-game/impartial-game-1.cpp"
    ```

???+ example "[Luogu P5675 \[GZOI2017\] Trò chơi lấy đá](https://www.luogu.com.cn/problem/P5675)"
    Có $n$ đống đá, đống thứ $i$ có $a_i$ viên. Hai người chơi chơi trò Nim. Giờ có thể tùy ý chỉ định một số đống đá làm cục diện ban đầu, đồng thời chỉ định một trong các đống đó là đống mà người đi trước bắt buộc phải lấy đá ở lượt đầu, nhưng không được chỉ định số đá cần lấy. Hỏi có bao nhiêu cách chỉ định sao cho người đi trước không thể giành thắng lợi. Dữ liệu thỏa $n,a_i\le 200$.

??? note "Lời giải"
    Với loại bài này, cần dùng kết luận của các trò chơi thường gặp và kết hợp kiến thức ở phần khác để giải. Giả sử chỉ định người đi trước phải lấy đá từ đống thứ $i$, và tổng Nim của mọi đống đá được chỉ định là $v$. Khi đó người đi trước không thể giành thắng lợi khi và chỉ khi $a_i \le a_i\oplus v$, tức số đá $a_i$ của đống thứ $i$ không vượt quá tổng Nim $a_i\oplus v$ của số đá ở các đống còn lại ngoài đống thứ $i$. Vì phạm vi dữ liệu rất nhỏ, có thể trực tiếp liệt kê đống được chỉ định để lấy đá ở lượt đầu; khi xét tới đống thứ $i$, với mỗi đống còn lại chọn hoặc không chọn, số phương án tạo ra từng tổng Nim khác nhau có thể được tính bằng DP, rồi cộng phần số phương án cuối cùng có giá trị lớn hơn hoặc bằng $a_i$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/impartial-game/impartial-game-2.cpp"
    ```

???+ example "[Luogu P2599 \[ZJOI2009\] Trò chơi lấy đá](https://www.luogu.com.cn/problem/P2599)"
    Có $n$ đống đá, đống thứ $i$ có $a_i$ viên. Hai người chơi lần lượt lấy đá; mỗi lần chỉ được chọn một đống ở ngoài cùng bên trái hoặc ngoài cùng bên phải để lấy đi tùy ý nhiều viên đá, nhưng không được không lấy. Người lấy viên đá cuối cùng thắng. Hỏi người đi trước có tất thắng hay không.

??? note "Lời giải"
    Vì bài này không tồn tại các trò chơi con độc lập với nhau, về nguyên tắc chỉ dùng [bổ đề phán định trạng thái tất bại và tất thắng](#np-lem). Bắt đầu phân tích từ trường hợp đơn giản nhất. Khi $n\le 2$, đây là trò chơi Nim. Khi $n \ge 3$, bài toán trở nên phức tạp. Tuy nhiên, vì các đống đá có thể thao tác chỉ là hai đống ở hai đầu, giả sử số đá của chúng lần lượt là $x$ và $y$. Tiếp đó, gọi $f(x,y)$ là hàm chỉ thị trạng thái người đi trước tất thắng, tức $f(x,y)=1$ nếu người đi trước tất thắng, ngược lại $f(x,y)=0$. Giá trị của $f(x,y)$ thỏa quan hệ truy hồi: $f(x,y)=0$ khi và chỉ khi với mọi $s < x$ và $t < y$ đều có $f(x,t)=f(s,y)=1$. Cơ sở truy hồi nằm ở $x=0$ hoặc $y=0$; khi đó số đống đá đã nhỏ hơn $n$, nên cần xét thêm số đá ở các đống giữa. Vì vậy, tạm giả sử $f(x,0)$ và $f(0,y)$ đã biết, rồi xét cách suy ra toàn bộ giá trị $f(x,y)$ từ chúng. Xét ma trận vô hạn có tập chỉ số là $\mathbf N\times\mathbf N$; việc tính $f(x,y)$ tương đương với điền $0$ và $1$ vào ma trận, cần thỏa điều kiện rằng mỗi hàng và mỗi cột có nhiều nhất một số $0$, và nếu các vị trí trước đó trong cùng hàng hoặc cùng cột đều chưa xuất hiện số $0$, thì vị trí này phải là $0$. Vị trí của số $0$ trong mỗi hàng định nghĩa một hàm từ số hàng $x$ tới số cột $y$. Sau khi thử một vài ví dụ đơn giản, tức lập bảng, nếu $x_0$ là $x$ duy nhất sao cho $f(x,0)=0$, và $y_0$ là $y$ duy nhất sao cho $f(0,y)=0$, thì với mọi $x$, giá trị $y$ làm $f(x,y)=0$ là
    
    $$
    y = \begin{cases}
    0, & x = x_0,\\
    x - 1, & x_0 < x < y_0,\\
    x + 1, & y_0 < x < x_0,\\
    x, & \text{ngược lại}.
    \end{cases}
    $$
    
    Nói cách khác, chỉ cần biết $x_0$ và $y_0$ là có thể tính giá trị của mọi $f(x,y)$ trong thời gian $O(1)$, từ đó phán định trạng thái hiện tại có tất thắng cho người đi trước hay không. Còn $x_0$ và $y_0$ có thể được tính đệ quy. Ví dụ, $x_0$ là nghiệm duy nhất làm $f(x,0)=0$, nhưng đồng thời giá trị của $f(x,0)$ có thể được tính bằng cách bỏ đống đá ngoài cùng bên phải rồi chỉ xét $n-1$ đống còn lại; nói cách khác, chỉ xét $n-1$ đống đá đầu cũng có thể tính một hàm $f_{1,n-1}(x,y)$, khi đó có $f(x,0)=f_{1,n-1}(x,a_{n-1})$. Tương tự, sau khi bỏ đống đá ngoài cùng bên trái và tính được $f_{2,n}(x,y)$, nhận được $f(0,y)=f_{2,n}(a_1,y)$. Việc tính các hàm bên trong $f_{1,n-1}(x,y)$ và $f_{2,n}(x,y)$ lại phụ thuộc vào các hàm ở lớp sâu hơn. Đây là [DP đoạn](../../dp/interval.md) điển hình. Ở mỗi lớp, chỉ cần duy trì $x_0$ và $y_0$ của hàm tương ứng.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/impartial-game/impartial-game-3.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

Trước hết là một số bài mẫu. Chúng là các ứng dụng đơn giản của những kết luận trong trang này:

-   [Luogu P2197 [Mẫu] Trò chơi Nim](https://www.luogu.com.cn/problem/P2197)
-   [Luogu P2252 \[SHOI2002\] Trò chơi lấy đá](https://www.luogu.com.cn/problem/P2252)
-   [Luogu P2594 \[ZJOI2009\] Trò chơi tô màu](https://www.luogu.com.cn/problem/P2594)
-   [Luogu P3185 \[HNOI2007\] Trò chơi tách](https://www.luogu.com.cn/problem/P3185)
-   [Luogu P3480 \[POI 2009\] KAM-Pebbles](https://www.luogu.com.cn/problem/P3480)
-   [Luogu P4101 \[HEOI2014\] Ai cũng khen Giang Nam đẹp](https://www.luogu.com.cn/problem/P4101)
-   [Luogu P4279 \[SHOI2008\] Trò chơi của Little John](https://www.luogu.com.cn/problem/P4279)
-   [Luogu P6487 \[COCI 2010/2011 #4\] HRPA](https://www.luogu.com.cn/problem/P6487)
-   [Luogu P6560 \[SBCOI2020\] Thời gian trôi qua](https://www.luogu.com.cn/problem/P6560)
-   [Luogu P7589 Cờ đen trắng (2021 CoE-II B)](https://www.luogu.com.cn/problem/P7589)
-   [AtCoder Regular Contest 168 B - Nim tùy ý](https://atcoder.jp/contests/arc168/tasks/arc168_b)

Sau đó là một số bài đòi hỏi tư duy hơn hoặc tổng hợp hơn:

-   [Luogu P2490 \[SDOI2011\] Cờ đen trắng](https://www.luogu.com.cn/problem/P2490)
-   [Luogu P3179 \[HAOI2015\] Trò chơi mảng](https://www.luogu.com.cn/problem/P3179)
-   [Luogu P5363 \[SDOI2019\] Di chuyển đồng vàng](https://www.luogu.com.cn/problem/P5363)
-   [Luogu P5970 \[POI 2016\] Nim z utrudnieniem](https://www.luogu.com.cn/problem/P5970)
-   [Luogu P6791 \[SNOI2020\] Lấy đá](https://www.luogu.com.cn/problem/P6791)
-   [Luogu P7864 "EVOI-RD1" Hái lá](https://www.luogu.com.cn/problem/P7864)
-   [Luogu P8347 "Wdoi-6" Mặt trăng phía bên kia](https://www.luogu.com.cn/problem/P8347)
-   [AtCoder Grand Contest 002 E - Các đống kẹo](https://atcoder.jp/contests/agc002/tasks/agc002_e)
-   [AtCoder Grand Contest 010 F - Trò chơi trên cây](https://atcoder.jp/contests/agc010/tasks/agc010_f)
-   [AtCoder Grand Contest 017 D - Trò chơi trên cây](https://atcoder.jp/contests/agc017/tasks/agc017_d)
-   [AtCoder Beginner Contest 278 G - Trò chơi trừ tổng quát](https://atcoder.jp/contests/abc278/tasks/abc278_g)
-   [SPOJ COT3 - Chiến đấu trên cây](https://www.spoj.com/problems/COT3/)
-   [Codeforces 494 E. Sharti](https://codeforces.com/problemset/problem/494/E)
-   [Codeforces 1149 E. Lời hứa tranh cử](https://www.luogu.com.cn/problem/CF1149E)
-   [Codeforces 1451 F. Triệt tiêu ma trận](https://codeforces.com/problemset/problem/1451/F)
-   [Codeforces 1704 F. Trò chơi tô màu](https://codeforces.com/problemset/problem/1704/F)

Cuối cùng là một số bài về trò chơi trên đồ thị hai phía. Vì cần dùng một số thuật toán ghép trên đồ thị hai phía, nên chúng được liệt kê riêng:

-   [Luogu P4136 Ai sẽ thắng?](https://www.luogu.com.cn/problem/P4136)
-   [Luogu P4617 \[COCI 2017/2018 #5\] Planinarenje](https://www.luogu.com.cn/problem/P4617)
-   [Luogu P4055 \[JSOI2009\] Trò chơi](https://www.luogu.com.cn/problem/P4055)
-   [Luogu P1971 \[NOI2011\] Trò chơi của Thỏ Thỏ và Đản Đản](https://www.luogu.com.cn/problem/P1971)
-   [Codeforces 1147 F. Trò chơi zích zắc](https://codeforces.com/problemset/problem/1147/F)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [(Đăng lại) Lý thuyết trò chơi Nim (bản sưu tầm đầy đủ) bởi exponent - Blog Garden](http://www.cnblogs.com/exponent/articles/2141477.html)
-   [[Trò chơi tổ hợp và lý thuyết trò chơi] Ghi chú học tập bởi Candy? - Blog Garden](https://www.cnblogs.com/candy99/p/6548836.html)
-   [Nim - Wikipedia](https://en.wikipedia.org/wiki/Nim)
-   [Định lý Sprague-Grundy - Wikipedia](https://en.wikipedia.org/wiki/Sprague%E2%80%93Grundy_theorem)
-   [Số Nim - Wikipedia](https://en.wikipedia.org/wiki/Nimber)
-   [Dãy Beatty - Wikipedia](https://en.wikipedia.org/wiki/Beatty_sequence)
-   [Trò chơi trên đồ thị tùy ý - CP Algorithms](https://cp-algorithms.com/game_theory/games_on_graphs.html)
-   [Ghi chú học thuật toán (74): Trò chơi trên đồ thị hai phía bởi Pecco - Zhihu](https://zhuanlan.zhihu.com/p/359334008)
-   Conway, John H. Về số và trò chơi. AK Peters/CRC Press, 2000.
-   Berlekamp, Elwyn R., John H. Conway, and Richard K. Guy. Winning ways for your mathematical plays, volume 1-4. AK Peters/CRC Press, 2001-2004.

[^n-vs-p]: Hai tên gọi "trạng thái $\mathcal N$" và "trạng thái $\mathcal P$" lần lượt biểu thị "người chơi tiếp theo thắng" (Next player wins) và "người chơi trước đó thắng" (Previous player wins).

[^more-sums]: Các "tổng" được thảo luận trong bài này đều là **tổng rời rạc** (disjunctive sum) theo **luật dài** (long rule). Đây cũng là cách kết hợp trò chơi thường gặp nhất. Ngoài ra còn có những cách kết hợp trò chơi khác. Để đọc thảo luận chi tiết về chúng, có thể tham khảo chương 14 của sách Conway, John H. Về số và trò chơi. AK Peters/CRC Press, 2000.
