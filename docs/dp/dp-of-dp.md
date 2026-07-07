author: Hope666666

<span id="dẫn-nhập"></span>
## Dẫn nhập

Bài viết này giới thiệu ý tưởng DP lồng DP, đồng thời dùng hai ví dụ để minh họa cách áp dụng kỹ thuật này vào các bài toán cụ thể.

<span id="tư-tưởng"></span>
## Ý tưởng

"DP lồng DP" là phương pháp trong quá trình quy hoạch động, trừu tượng hóa quá trình giải một bài toán con (thường cũng là một DP) thành một ô-tô-mát (automaton, DFA), rồi thiết kế thêm một lớp DP mới trên ô-tô-mát đó.

Kỹ thuật này chủ yếu được dùng cho một lớp bài toán **đếm dãy**, **xác suất** hoặc **kỳ vọng**. Một bài toán điển hình có cấu trúc như sau:

-   Cho bảng chữ cái $\Sigma$ và một tập $A\subseteq\Sigma^n$ gồm các "dãy hợp lệ" độ dài $n$ trên bảng chữ cái đó. Tùy bảng chữ cái, dãy có thể là xâu nhị phân, xâu chữ số, dãy trạng thái, v.v.
-   Với mỗi dãy cụ thể $s\in\Sigma^n$, có thể dùng quy hoạch động để kiểm tra nó có hợp lệ hay không (tức $s\in A$), tính trọng số của nó hoặc tính một giá trị liên quan.
-   Cuối cùng, cần thống kê số lượng, tổng trọng số, giá trị kỳ vọng, v.v. của tất cả các dãy trong tập $A$.

Lúc này, liệt kê mọi dãy là không khả thi. Vì vậy, xét việc trừu tượng hóa quá trình "kiểm tra một dãy có hợp lệ hay không" (tức DP bên trong) thành một [ô-tô-mát hữu hạn xác định](../misc/fsm.md#automaton-trạng-thái-hữu-hạn-xác-định) (DFA). Với một dãy cố định $s\in\Sigma^n$, hàm trạng thái của DP bên trong có thể được biểu diễn là $g(i,x;s)$, tức là giá trị của một đại lượng nào đó sau khi đã xử lý xong tiền tố độ dài $i$ của dãy $s$, đồng thời thành phần trạng thái khác là $x$. Tương ứng, phương trình chuyển trạng thái của DP bên trong là

$$
g(i,\cdot;s) = G(g(i-1,\cdot;s),s_i).
$$

Nói cách khác, hàm $g(i,\cdot;s)$ được xác định duy nhất bởi hàm trước đó $g(i-1,\cdot;s)$ và ký tự hiện tại $s_i$. Nếu xem hàm $g(i,\cdot;s)$ là một trạng thái của ô-tô-mát, thì phương trình chuyển trạng thái của DP bên trong đã cho một phép chuyển của ô-tô-mát. Vì vậy, ô-tô-mát $(Q,\Sigma,\delta,q_0,F)$ tương ứng với DP bên trong có cấu trúc như sau:

-   Tập trạng thái $Q$ là tập mọi hàm $g(i,\cdot;s)$ có thể có, ứng với mọi $s\in\Sigma^n$ và $i=0,1,\cdots,n$;
-   Hàm chuyển $\delta:Q\times\Sigma\to Q$ chính là $G$ trong phương trình chuyển trạng thái của DP bên trong;
-   Trạng thái bắt đầu $q_0$ thường là trạng thái ban đầu của DP bên trong;
-   Tập trạng thái chấp nhận $F$ tương ứng với tất cả các dãy hợp lệ $s\in A$.

Bản thân hàm $g(i,\cdot;s)$ có thể khá phức tạp. Vì vậy, khi xử lý bài toán cụ thể, thường cần dùng [nén trạng thái](./state.md) hoặc kết hợp kỹ thuật tối thiểu hóa DFA để nén không gian trạng thái. Đây cũng là nguyên nhân chính khiến DP lồng DP có thể giảm đáng kể độ phức tạp thời gian và bộ nhớ so với DP vét cạn.

Sau khi trừu tượng hóa DP bên trong thành DFA, có thể thiết kế một DP mới trên DFA này để giải bài toán gốc, tức DP bên ngoài. Để tiện trình bày, xét một bài toán đếm đơn giản làm ví dụ. Định nghĩa hàm trạng thái của DP bên ngoài là $f(i,q)$, tức số lượng tiền tố tới được trạng thái $q\in Q$ trong DFA sau khi xử lý tới tiền tố độ dài $i$. Phương trình chuyển trạng thái của nó là

$$
f(i,q) = \sum_{c\in\Sigma}\sum_{q'\in Q:\delta(q',c)=q} f(i-1,q').
$$

Trạng thái bắt đầu là $f(0,q_0)$, còn đáp án cuối cùng thường có thể được tính đơn giản từ $\{f(n,q):q\in F\}$. DP bên ngoài thực chất là một trường hợp đặc biệt của [DP trên DAG](./dag.md).

<span id="ví-dụ"></span>
## Ví dụ

Hai ví dụ tiếp theo sẽ giải thích chi tiết cách làm chung của DP lồng DP.

<span id="ví-dụ-1"></span>
### Ví dụ 1

???+ example "[Hero meet devil](https://www.luogu.com.cn/problem/P10614)"
    Cho một xâu $S$ trên bảng chữ cái `ACGT`, với $|S|\le 15$. Với mỗi $0\leq i \leq |S|$, tính có bao nhiêu xâu $T$ độ dài $m$ trên bảng chữ cái `ACGT` sao cho độ dài dãy con chung dài nhất của nó với $S$ bằng $i$.

??? note "Lời giải"
    Trước hết thường nghĩ tới một DP: đặt $f_{i,j}$ là số phương án sao cho trong $T$ độ dài $i$, độ dài dãy con chung dài nhất với $S$ là $j$. Nhưng trạng thái này không thể chuyển được. Vấn đề chính là không biết dãy con chung dài nhất đó tương ứng với những ký tự nào.
    
    Xét cách tìm dãy con chung dài nhất đơn giản nhất. Đặt $g_{i,j}$ là độ dài dãy con chung dài nhất của $i$ ký tự đầu của $T$ và $j$ ký tự đầu của $S$. Khi đó có
    
    $$
    g_{i,j} = \max\{g_{i-1,j},g_{i,j-1},g_{i-1,j-1}+[T_i=S_j]\}.
    $$
    
    Với một $i$, chỉ cần ghi lại giá trị ở từng vị trí của mảng một chiều $g_i$ là có thể duy trì chính xác trạng thái dãy con chung dài nhất giữa $S$ và $i$ ký tự đầu của $T$. Vì độ dài $S$ chỉ là $15$, ý tưởng này khả thi.
    
    Vì vậy, định nghĩa lại trạng thái $f_{i,x}$ là số phương án sao cho với $T$ độ dài $i$, trạng thái của mảng DP với $S$ (chính là $g_i$) là $x$. DP này nhìn qua có rất nhiều trạng thái; tuy nhiên $g_{i,j}-g_{i,j-1}\in\{0,1\}$, nên có thể duy trì mảng sai phân của $g_i$, và số trạng thái là $2^{|S|}$.
    
    Bây giờ xét cách chuyển trạng thái. Nếu đã biết mảng $g_i$ và cũng biết $T_{i+1}$, có thể dùng chuyển LCS đơn giản (tức phương trình DP phía trên) để tính ra $g_{i+1}$. Vì vậy, LCS đơn giản trở thành DP bên trong giúp chuyển trạng thái cho $f$.
    
    Do đó, liệt kê $T_{i+1}$, tính trạng thái $x'$ sau khi chuyển từ $x$, rồi cộng $f_{i,x}$ vào $f_{i+1,x'}$ là hoàn thành chuyển trạng thái của DP bên ngoài. Cuối cùng, ghi $\textit{ans}_i$ là đáp án ứng với độ dài LCS bằng $i$; liệt kê từng trạng thái $S$, cộng $f_{m,S}$ vào $\textit{ans}_{\operatorname{popcount}(S)}$ là được.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/dp-of-dp/dp-of-dp_1.cpp"
    ```

<span id="ví-dụ-2"></span>
### Ví dụ 2

???+ example "[\[ZJOI2019\] Mạt chược](https://loj.ac/p/3042)"
    Giả sử bài mạt chược có $n$ loại quân theo kích thước, mỗi loại kích thước có $4$ quân. Định nghĩa một bộ là ba quân mạt chược có kích thước liên tiếp $i,i+1,i+2$ (sảnh) hoặc ba quân cùng kích thước $i,i,i$ (bộ ba); một đôi là hai quân cùng kích thước $i,i$. Một dãy quân mạt chược được định nghĩa là ù khi và chỉ khi nó (xem như một đa tập) có thể được tách thành bốn bộ và một đôi, hoặc bảy đôi khác nhau. Cho $13$ quân mạt chược, hỏi kỳ vọng cần rút thêm bao nhiêu quân để thỏa mãn điều kiện tồn tại một dãy con có thể ù.

??? note "Lời giải"
    Trước hết, với một bộ bài, chỉ cần xét số lượng của mỗi loại quân, không cần quan tâm thứ tự của chúng. Vì vậy, với một tiền tố bất kỳ của một bộ bài bất kỳ, đều có thể chuyển nó thành một dãy độ dài $n$, trong đó mỗi vị trí có giá trị $0\sim 4$. Ban đầu, số lượng quân thứ $i$ là $a_i$, tương đương với việc giới hạn giá trị của số thứ $i$ trong dãy, tức $x_i$, là một số nguyên trong $[a_i,4]$. Cần lưu ý rằng dãy sau khi chuyển đổi không xét thứ tự rút quân, nhưng dãy quân mạt chược trong đề bài thì có xét thứ tự.
    
    Gọi $X$ là số lần rút quân nhỏ nhất để có thể ù. Tính trực tiếp kỳ vọng $\mathbf E[X]$ là khá khó, nên có thể xét biến đổi sau. Gọi $h_i$ là số dãy **chưa ù** sau khi đã rút $i$ quân. Vì trong dãy quân mạt chược tương ứng, $i$ quân này đứng trước $(4n-13-i)$ quân còn lại, nhưng thứ tự của $i$ quân này và thứ tự của $(4n-13-i)$ quân còn lại đều tùy ý, nên số lượng dãy quân mạt chược không thể ù nếu chỉ rút $i$ quân đầu là
    
    $$
    h_i\cdot i!(4n-13-i)!.
    $$
    
    Vì tổng số dãy quân mạt chược là $(4n-13)!$, xác suất không thể ù nếu chỉ rút $i$ quân đầu là
    
    $$
    \mathbf P[X>i] = \dfrac{h_i\cdot i!(4n-13-i)!}{(4n-13)!}.
    $$
    
    Dùng công thức tổng đuôi, thu được kỳ vọng cần tìm:
    
    $$
    \mathbf E[X] = \sum_{i=0}^\infty\mathbf P[X>i] = 1 + \sum_{i=1}^{4n-13}\dfrac{h_i\cdot i!(4n-13-i)!}{(4n-13)!}.
    $$
    
    Tới đây, bài toán chuyển thành cách tính $h_i$. Dùng phương pháp DP lồng DP để giải quyết vấn đề này.
    
    Trước hết, xét DP bên trong, tức là dùng quy hoạch động để kiểm tra xem một dãy (sau khi chuyển đổi) có tương ứng với một bộ bài có thể ù hay không. Trường hợp bảy đôi dễ hơn, nên tập trung thảo luận dạng ù thứ nhất. Đặt $g_{0/1,i,j,k}$ là số bộ nhiều nhất sau khi đã xử lý xong $i$ loại quân đầu, còn lại $j$ nhóm $(i-1,i)$ và $k$ quân $i$, đồng thời có/không có đôi (tức $0/1$). Nếu khi chạy DP cho một dãy, trong $g_{1,n}$ cuối cùng có một số lớn hơn hoặc bằng $4$, thì dãy này có thể ù.
    
    Chuyển trạng thái của DP này khá phức tạp. Thảo luận theo hai bước. Bước thứ nhất, xét chuyển của $g_{0/1,i}$. Điều này tương đương với việc: nếu muốn thêm $x_i$ quân kích thước $i$ vào dạng bài hiện tại nhưng không tạo đôi mới, thì số bộ chuyển như thế nào. Nếu sau khi thêm $x_i$ quân kích thước $i$ muốn thu được $\ell$ sảnh, $j$ nhóm $(i-1,i)$ và $k$ quân $i$ đơn lẻ, thì nên chuyển từ $(g_{0/1,i-1})_{\ell,j}$ (lựa chọn này tránh lãng phí ở mức tối đa), đồng thời dùng các quân còn lại $(x_i-\ell-j-k)$ để tạo càng nhiều bộ ba càng tốt. Liệt kê mọi khả năng, thu được phương trình chuyển sau:
    
    $$
    \tilde G(g_{0/1,i-1}, x_i)_{j,k} = \max\left\{(g_{0/1,i-1})_{\ell,j} + \ell + \left\lfloor\dfrac{x_i-\ell-j-k}{3}\right\rfloor:\ell+j+k\le x_i\right\}.
    $$
    
    Bước thứ hai, xét tiếp trường hợp cần tạo đôi. Khi thêm $x_i$ quân kích thước $i$, có ba kiểu chuyển sau:
    
    -   Thêm $x_i$ quân vào $g_{0,i-1}$ để chuyển tới $g_{0,i}$;
    -   Thêm $x_i$ quân vào $g_{1,i-1}$ để chuyển tới $g_{1,i}$;
    -   Nếu $x_i\ge 2$, thêm $x_i-2$ quân vào $g_{0,i-1}$ để chuyển tới $g_{1,i}$.
    
    Từ đó, thu được toàn bộ phép chuyển từ $g_{i-1}$ tới $g_i$ sau khi thêm $x_i$ quân.
    
    Sau khi giải quyết chuyển trạng thái của DP bên trong, có thể xây dựng **ô-tô-mát ù bài**. Phép chuyển của ô-tô-mát chính là phép chuyển của DP bên trong nói trên; ngoài ra còn cần xét cách biểu diễn mỗi trạng thái của ô-tô-mát. Mỗi trạng thái đều tương ứng với một giá trị có thể có của $g_i$. Nó có ba chiều $(0/1,j,k)$. Vì các nhóm $(i-1,i)$ và quân $i$ được giữ lại trong các chiều tương ứng với $j$ và $k$ đều nhằm tạo sảnh trong tương lai, mà ba sảnh giống nhau luôn có thể được tổ chức lại thành ba bộ ba, nên chỉ cần xét nhu cầu tạo không quá $2$ sảnh giống nhau; mỗi dạng bài cũng chỉ cần giữ không quá $2$ nhóm, tức $j,k\in\{0,1,2\}$. Vì vậy, $g_i$ có thể được biểu diễn bằng một mảng $2\times 3\times 3$. Ngoài ra, để duy trì dạng ù bảy đôi, còn cần thêm một bộ đếm cho mỗi trạng thái, dùng để biểu thị số đôi nhiều nhất hiện tại có thể tạo được.
    
    Giá trị của mỗi phần tử trong mảng $g_i$ có thể thuộc $\{-\infty\}\cup\mathbf N$. Tuy nhiên, vì số bộ lớn hơn hoặc bằng $4$ đều là ù, nên có thể giới hạn giá trị của mỗi phần tử không vượt quá $4$. Do một dãy đã ù thì thêm bất kỳ quân nào vẫn là dãy ù, có thể dùng ý tưởng tối thiểu hóa DFA để nén toàn bộ trạng thái ù thành một trạng thái. Vì vậy, với các trạng thái chưa ù, thực tế giá trị ở mỗi vị trí chỉ cần xét $\{-\infty\}\cup\{0,1,2,3\}$. Khi cài đặt, dùng $-1$ để biểu diễn $-\infty$.
    
    Dù vậy, số trạng thái có thể có vẫn rất nhiều, tổng cộng $1+7\times 5^{18}$ trạng thái. Liệt kê chúng là không thực tế. Phần lớn các khả năng này sẽ không thật sự xuất hiện trong một ô-tô-mát ù bài. Để tránh xét các trạng thái không tồn tại trong thực tế, có thể dùng cách làm kiểu BFS, bắt đầu từ trạng thái ban đầu và mở rộng trạng thái từng bước cho tới khi dừng ở trạng thái ù. Ô-tô-mát thu được theo cách này có $N = 2092$ trạng thái.
    
    Cuối cùng, xét cách DP trên ô-tô-mát ù bài (tức DP bên ngoài). Đặt $f_{i,j,k}$ là số dãy khi đã xử lý tới quân thứ $i$, đã rút tổng cộng $j$ quân, và đi tới trạng thái số $k$ trên ô-tô-mát ù bài. Khi chuyển, liệt kê số quân rút $0\leq t\leq 4-a_i$, trong đó $a_i$ là số quân loại $i$ đã dùng trong $13$ quân ban đầu; nhân số dãy trước đó với số cách chọn $t$ quân trong $4−a_i$ quân, tức $\dbinom{4-a_i}{t}$, rồi cộng dồn. Viết hình thức là:
    
    $$
    f_{i+1,j+t,k'} = \sum_{t=0}^{4-a_i}\dbinom{4-a_i}{t}f_{i,j,k}.
    $$
    
    Trong đó, $k'=\delta(k,a_i+t)$, biểu thị trạng thái sau khi thêm $a_i+t$ quân vào trạng thái $k$ của ô-tô-mát. Sau khi DP bên ngoài kết thúc, có thể tính số dãy vẫn chưa ù sau khi rút $i$ quân, tức là
    
    $$
    h_i=\sum_{j=1}^{N} f_{n,i,j}.
    $$
    
    Thay vào biểu thức đã nêu ở trên là thu được kỳ vọng cần tìm.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/dp-of-dp/dp-of-dp_2.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

-   [CF979E Kuro và tính chẵn lẻ tô pô](https://codeforces.com/problemset/problem/979/E)
-   [\[TJOI2018\] Hội dạo chơi](https://loj.ac/p/2575)
-   [\[NOI2022\] Loại bỏ đá](https://loj.ac/p/3848)
