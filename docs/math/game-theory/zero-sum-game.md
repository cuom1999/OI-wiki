Kiến thức cần có: [Giới thiệu về lý thuyết trò chơi](./intro.md)

Bài viết này thảo luận về [trò chơi tổng bằng không](./intro.md#trò-chơi-tổng-bằng-không-không-tổng-bằng-không) hai người.

Trong trò chơi tổng bằng không, tổng lợi ích của hai người chơi luôn bằng không; lợi ích của một bên tất yếu tương ứng với tổn thất của bên còn lại. Trò chơi tổng bằng không có thể xem là một trường hợp đặc biệt của trò chơi tổng hằng. Tuy nhiên, bất kỳ trò chơi tổng hằng nào cũng có thể được chuyển đổi tương đương thành trò chơi tổng bằng không bằng cách cộng hoặc trừ cùng một hằng số vào toàn bộ lợi ích của một bên, vì vậy chỉ cần xét trò chơi tổng bằng không.

Trong thi thuật toán, các trò chơi tổng bằng không thường gặp có thể chia đại khái thành hai loại: trò chơi tuần tự tổng bằng không và trò chơi đồng thời tổng bằng không.

<span id="trò-chơi-tuần-tự-tổng-bằng-không"></span>
## Trò chơi tuần tự tổng bằng không

Trong trò chơi tuần tự tổng bằng không, hai người chơi luân phiên hành động cho đến khi trò chơi kết thúc.

Trong trò chơi tuần tự tổng bằng không, hàm lợi ích của người chơi có cấu trúc đệ quy. Các trạng thái trò chơi $S$ có thể chia thành ba loại: trạng thái kết thúc $S_0$, trạng thái đến lượt người chơi $1$ hành động $S_1$, và trạng thái đến lượt người chơi $2$ hành động $S_2$. Giả sử tại trạng thái kết thúc $s\in S_0$, lợi ích của người chơi $1$ là $v(s)$, tương ứng lợi ích của người chơi $2$ là $-v(s)$. Do đó, khi đến lượt người chơi $2$ hành động, tối đa hóa lợi ích của họ tương đương với tối thiểu hóa lợi ích của người chơi $1$. Từ đó, nếu giả sử cả hai bên đều dùng chiến lược tối ưu, lợi ích lớn nhất $V(s)$ mà người chơi $1$ có thể đạt được tại trạng thái $s\in S$ thỏa mãn truy hồi sau:

$$
V(s) = \begin{cases}
v(s), & s \in S_0,\\
\max_{t\in s} V(t), & s\in S_1,\\
\min_{t\in s} V(t), & s\in S_2.
\end{cases}
$$

Trong đó, $t\in s$ nghĩa là $t$ là một trạng thái kế tiếp của $s$. Đây chính là [tư tưởng minimax](../../search/alpha-beta.md#thuật-toán-minimax).

Khi áp dụng thuật toán này vào bài toán thực tế, thường có các cách cụ thể sau:

-   Nếu số lượng trạng thái xuất hiện trong trò chơi tương đối ít, có thể cài đặt trực tiếp thuật toán này bằng vét cạn.

-   Nếu số lượng trạng thái xuất hiện trong trò chơi rất lớn và không có cấu trúc đặc biệt, có thể cân nhắc dùng [cắt tỉa Alpha-Beta](../../search/alpha-beta.md#cắt-tỉa-alpha-beta) kết hợp với các thuật toán cắt tỉa tìm kiếm khác.

-   Nếu một trạng thái trong trò chơi thường là trạng thái kế tiếp của nhiều trạng thái khác, để tránh tìm kiếm lặp lại, có thể dùng tìm kiếm có nhớ hoặc các thuật toán quy hoạch động khác.

-   Nếu lợi ích cuối cùng của người chơi trong trò chơi là tổng lợi ích của mọi hành động trước khi kết thúc, có thể tối ưu cách mô hình hóa một cách phù hợp. Cụ thể, giả sử khi đến trạng thái kết thúc $s\in S_0$, dãy hành động của người chơi $i=1,2$ lần lượt là $\{a^{(i)}_j\}_{j=1}^{k_i}$, lợi ích tương ứng với hành động $a$ là $w(a)$, và hàm lợi ích của người chơi $1$ là

    $$
    v(s) = \sum_{j=1}^{k_1}w(a_j^{(1)}) - \sum_{j=1}^{k_2}w(a_j^{(2)}).
    $$

    Khi đó, có thể đặt $\tilde V(s)$ là điểm số lớn nhất mà người chơi hiện tại có thể đạt được trong phần trò chơi sau trạng thái $s\in S$. Với trạng thái ban đầu $s_0$, có $V(s_0)=\tilde V(s_0)$, nên chỉ cần tính được $\tilde V(\cdot)$ là đủ để giải bài toán gốc. Với $\tilde V(\cdot)$, truy hồi là:

    $$
    \tilde V(s) = \begin{cases}
    0, & s \in S_0, \\
    \max_{t\in s} w(a_{s\to t}) - \tilde V(t), & s\in S_1\cup S_2.
    \end{cases}
    $$

    Trong đó, $a_{s\to t}$ biểu thị một hành động có thể chuyển trạng thái từ $s$ sang $t$; nếu có nhiều hành động như vậy, lấy hành động có lợi ích $w(a)$ lớn nhất.

-   Mọi trò chơi tổ hợp công bằng đều là trò chơi tuần tự tổng bằng không; chỉ cần đặt lợi ích của bên thắng và bên thua trong trò chơi lần lượt là $+1$ và $-1$. Khi đó, truy hồi của hàm lợi ích $V(\cdot)$ thực chất chính là [bổ đề](./impartial-game.md#đồ-thị-trò-chơi-và-trạng-thái) dùng để xác định trạng thái thắng chắc và trạng thái thua chắc.

    Dạng bài này còn có một biến thể thường gặp: tìm số lượt ít nhất mà bên thắng cần dùng, và số lượt nhiều nhất mà bên thua có thể cầm cự. Để làm điều đó, lưu ý rằng khi bắt đầu BFS từ trạng thái kết thúc và dùng bổ đề để xác định trạng thái thắng chắc, thua chắc, số vòng BFS tại thời điểm trạng thái được xác định chính là số lượt cần tìm. Lý do là một trạng thái được xác định là thắng chắc chỉ cần có một trạng thái kế tiếp là thua chắc, nên nó luôn được chuyển từ trạng thái thua chắc có số vòng nhỏ nhất trong các trạng thái kế tiếp; còn một trạng thái được xác định là thua chắc cần mọi trạng thái kế tiếp đều là thắng chắc, nên nó luôn được chuyển từ trạng thái thắng chắc có số vòng lớn nhất trong các trạng thái kế tiếp.

    Phương pháp này cũng có thể mở rộng cho [trò chơi trên đồ thị có hướng](./impartial-game.md#trò-chơi-trên-đồ-thị-có-hướng) nói chung.

<span id="ví-dụ"></span>
### Ví dụ

???+ example "[Codeforces 794 E. Choosing Carrot](https://codeforces.com/problemset/problem/794/E)"
    Cho một dãy số ${a_i}$ có độ dài $n$. Hai người chơi $1$ và $2$ luân phiên lấy đi một số ở một trong hai đầu dãy, cho đến khi trong dãy chỉ còn lại đúng một số cuối cùng. Mục tiêu của người chơi $1$ là tối đa hóa số cuối cùng còn lại này, còn mục tiêu của người chơi $2$ là tối thiểu hóa nó. Trước khi trò chơi chính thức bắt đầu, người chơi $1$ còn có thể thực hiện trước $k$ hành động. Giả sử cả hai người chơi đều dùng chiến lược tối ưu trong suốt quá trình. Với mỗi $k = 0,1,2,\cdots,n-1$, tìm số cuối cùng còn lại khi trò chơi kết thúc. Trong đó, $1 \le n \le 3\times 10^5$.

??? note "Lời giải"
    Vì dù hai bên lấy số như thế nào, phần còn lại của dãy luôn là một đoạn liên tiếp. Do đó, trạng thái trong trò chơi có thể chỉ được mô tả bằng đoạn $[l,r]$ và người chơi hiện đang hành động $i=1,2$, và có thể dùng quy hoạch động để giải. Đặt $f(l,r,i)$ là số cuối cùng còn lại khi trạng thái được mô tả bởi $(l,r,i)$. Theo phân tích ở trên, khi $l < r$, hàm này thỏa mãn phương trình chuyển trạng thái:
    
    $$
    \begin{aligned}
    f(l,r,1) &= \max\{f(l+1,r,2),f(l,r-1,2)\},\\
    f(l,r,2) &= \min\{f(l+1,r,1),f(l,r-1,1)\}.
    \end{aligned}
    $$
    
    Điều kiện biên là $f(l,l,1)=f(l,l,2) = a_l$. Từ đó, có thể tính giá trị hàm của mọi trạng thái có thể trong thời gian $\Theta(n^2)$. Với mỗi $k$, đáp án là
    
    $$
    g(k) = \max f(l,r,1) \text{ với ràng buộc } r - l + 1 = k.
    $$
    
    Thuật toán này không thể vượt qua phạm vi dữ liệu của đề gốc, nên cần tối ưu phép chuyển. Có nhiều cách xử lý; bài viết này chỉ trình bày một cách.
    
    Xem phương trình chuyển trạng thái như một thao tác trên toàn bộ dãy số. Hai phương trình chuyển lần lượt biểu thị việc lấy giá trị lớn nhất và giá trị nhỏ nhất của các số kề nhau để tạo thành dãy mới; gọi chúng lần lượt là "thao tác cực đại hóa" và "thao tác cực tiểu hóa". Mỗi thao tác làm độ dài dãy giảm đi một. Tổng cộng có $(n-d+1)$ kết quả ứng với các đoạn có độ dài $d$, tương đương với dãy thu được sau khi thực hiện $(d-1)$ thao tác trên dãy ban đầu. Ngoài ra, để thu được kết quả $f(l,r,1)$, cần bảo đảm thao tác cuối cùng là thao tác cực đại hóa. Vì vậy, các dãy thao tác này luôn kết thúc bằng thao tác cực đại hóa.
    
    Xét thay đổi do hai thao tác liên tiếp gây ra cho dãy. Không mất tính tổng quát, xét trường hợp trước hết thực hiện thao tác cực tiểu hóa, rồi thực hiện thao tác cực đại hóa. Khi đó, dãy $a_1,a_2,a_3$ sẽ trở thành
    
    $$
    \max\{\min\{a_1,a_2\},\min\{a_2,a_3\}\}.
    $$
    
    Liệt kê mọi quan hệ thứ tự có thể giữa ba số $a_1,a_2,a_3$ cho thấy, ngoại trừ trường hợp $a_1 < a_2$ và $a_2 > a_3$ (tức $a_2$ là một cực đại nghiêm ngặt), biểu thức này luôn bằng $a_2$. Nói cách khác, nếu một dãy không có bất kỳ điểm cực đại nghiêm ngặt nào, thì ảnh hưởng duy nhất của hai thao tác liên tiếp lên nó là xóa đi một số ở đầu và một số ở cuối dãy. Điều này đơn giản hóa phép chuyển rất nhiều. Vấn đề duy nhất còn lại là: làm thế nào để bảo đảm dãy không có bất kỳ điểm cực đại nghiêm ngặt nào? Chỉ cần thực hiện một thao tác cực đại hóa trên dãy là có thể bảo đảm không tồn tại điểm cực đại nghiêm ngặt. Vì vậy, mọi kết quả sau số thao tác chẵn có thể được thu bằng cách thực hiện hai thao tác trên dãy ban đầu, rồi lần lượt xóa từng cặp số ở hai đầu; mọi kết quả sau số thao tác lẻ có thể được thu bằng cách thực hiện một thao tác trên dãy ban đầu, rồi lần lượt xóa từng cặp số ở hai đầu.
    
    Vì toàn bộ thao tác đầy đủ trên dãy chỉ cần thực hiện nhiều nhất $3$ lần, còn phần thống kê đáp án sau đó chỉ cần $2$ lần duyệt, độ phức tạp thời gian tổng cộng của thuật toán là $\Theta(n)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/zero-sum-game/zero-sum-game-1.cpp"
    ```

<span id="bài-tập"></span>
### Bài tập

-   [Luogu P2734 \[USACO3.3\] Trò chơi A Game](https://www.luogu.com.cn/problem/P2734)
-   [Luogu P4576 \[CQOI2013\] Trò chơi bàn cờ](https://www.luogu.com.cn/problem/P4576)
-   [Luogu P7097 \[yLOI2020\] Múa rối dây](https://www.luogu.com.cn/problem/P7097)
-   [Codeforces 388 C. Fox and Card Game](https://codeforces.com/problemset/problem/388/C)
-   [Codeforces 794 E. Choosing Carrot](https://codeforces.com/problemset/problem/794/E)
-   [Codeforces 1628 D2. Game on Sum (Hard Version)](https://codeforces.com/problemset/problem/1628/D2)
-   [Luogu P3210 \[HNOI2010\] Trò chơi lấy đá](https://www.luogu.com.cn/problem/P3210)

<span id="trò-chơi-đồng-thời-tổng-bằng-không"></span>
## Trò chơi đồng thời tổng bằng không

Trong trò chơi đồng thời tổng bằng không, hai người chơi hành động cùng lúc.

Trò chơi đồng thời tổng bằng không thường được biểu diễn bằng ma trận lợi ích. Giả sử tập hành động của người chơi $i=1,2$ là $A_i$, và khi người chơi $i=1,2$ lần lượt chọn hành động $a_i\in A_i$, lợi ích của hai người lần lượt là $v(a_1,a_2)$ và $-v(a_1,a_2)$.

???+ example "Ví dụ"
    Xét trò chơi kéo búa bao. Giả sử thắng được $1$ điểm, thua được $-1$ điểm, hòa được $0$ điểm. Khi đó, lợi ích của hai người trong trò chơi có thể biểu diễn bằng
    
    $$
    \begin{pmatrix}
    0,0 & 1,-1 & -1,1 \\
    -1,1 & 0,0 & 1,-1 \\
    1,-1 & -1,1 & 0,0
    \end{pmatrix}.
    $$
    
    Trò chơi đồng thời hai người nói chung cũng có thể được biểu diễn dưới dạng tương tự, nên còn được gọi là [trò chơi song ma trận](https://en.wikipedia.org/wiki/Bimatrix_game) (bimatrix game). Với trò chơi tổng bằng không, do ma trận lợi ích của người chơi $1$ và ma trận lợi ích của người chơi $2$ là hai ma trận đối nhau, chỉ cần xét ma trận lợi ích của người chơi $1$:
    
    $$
    V = (v(a_1,a_2))_{(a_1,a_2)\in A_1\times A_2} = \begin{pmatrix}
    0 & 1 & -1 \\
    -1 & 0 & 1 \\
    1 & -1 & 0
    \end{pmatrix}.
    $$

Vấn đề cần giải quyết là: cho ma trận lợi ích $V = (v(a_1,a_2))_{(a_1,a_2)\in A_1\times A_2}$, làm thế nào để tìm chiến lược tối ưu và lợi ích lớn nhất của hai người chơi?

<span id="chiến-lược-hỗn-hợp"></span>
### Chiến lược hỗn hợp

So với trò chơi tuần tự tổng bằng không, vai trò của hai người chơi trong trò chơi đồng thời là đối xứng. Tuy nhiên, vì trò chơi tuần tự tổng bằng không đã được giải quyết, có thể xét phiên bản tuần tự của trò chơi đồng thời. Chẳng hạn, nếu giả định người chơi $1$ hành động trước, rồi người chơi $2$ hành động sau, thì theo phần thảo luận ở trên, lợi ích của người chơi $1$ khi trò chơi kết thúc sẽ được cho bởi

$$
w_-=\max_{a_1\in A_1}\min_{a_2\in A_2} v(a_1,a_2)
$$

Vì người chơi $2$ quan sát được hành động của người chơi $1$, đây nên là kết quả xấu nhất mà người chơi $1$ có thể đạt được. Đối xứng lại, nếu giả định người chơi $2$ hành động trước, thì lợi ích của người chơi $1$ sẽ được cho bởi

$$
w_+ = \min_{a_2\in A_2}\max_{a_1\in A_1} v(a_1,a_2)
$$

Vì người chơi $1$ quan sát được hành động của người chơi $2$, đây nên là kết quả tốt nhất mà người chơi $1$ có thể đạt được. Người chơi $1$ nên kỳ vọng rằng trong trò chơi thực tế, lợi ích đạt được là $w\in[w_-,w_+]$. Mặc dù bất đẳng thức $w_-\le w_+$ luôn đúng (chứng minh xem tại [định lý đối ngẫu yếu](../linear-programming.md#nguyên-lý-đối-ngẫu)), nhưng vì dấu bằng không nhất thiết xảy ra, chỉ dùng phương pháp phân tích của trò chơi tuần tự thì nói chung không thể xác định duy nhất kết quả trò chơi.

???+ example "Ví dụ (tiếp)"
    Trong trò chơi kéo búa bao, nếu có thứ tự ra tay trước sau, người đi trước sẽ thua, người đi sau sẽ thắng. Chuyển sang ngôn ngữ toán học, đó chính là bất đẳng thức sau:
    
    $$
    w_- = -1 \le +1 = w_+.
    $$
    
    Khi đó, $w_-=w_+$ không đúng.

Phân tích trên đã bỏ sót một yếu tố then chốt của trò chơi đồng thời: người chơi không thể dự đoán chính xác hành động của đối thủ. Về hình thức, điều này có nghĩa là hai bên có thể dùng một loại chiến lược ngẫu nhiên nào đó. Ý tưởng này không đúng trong ngữ cảnh trò chơi tuần tự, vì dù người chơi đi trước chọn hành động ngẫu nhiên như thế nào, người chơi đi sau luôn có thể quan sát chính xác hành động đó và đáp trả có mục tiêu. Nhưng với trò chơi đồng thời, sự mơ hồ chiến lược do chiến lược ngẫu nhiên đưa vào sẽ khiến đối thủ không thể đối phó hiệu quả với hành động của bên còn lại.

???+ example "Ví dụ (tiếp)"
    Trong trò chơi kéo búa bao, nếu người chơi $1$ chọn ngẫu nhiên đều một trong ba hành động kéo, búa, bao, thì tùy theo hành động của người chơi $2$, lợi ích có thể nhận được của người chơi $1$ là
    
    $$
    \dfrac{1}{3}(0,1,-1)^T + \dfrac{1}{3}(-1,0,1)^T + \dfrac{1}{3}(1,-1,0)^T = (0,0,0)^T.
    $$
    
    Khi đó, bất kể người chơi $2$ chọn hành động nào, kỳ vọng lợi ích của người chơi $1$ luôn là $0$. Điều này tốt hơn việc chọn cố định một hành động đơn lẻ.

Từ đó, đưa vào khái niệm chiến lược hỗn hợp.

???+ abstract "Chiến lược hỗn hợp"
    Trong trò chơi đồng thời, **chiến lược hỗn hợp** (mixed strategy), gọi tắt là **chiến lược**, của người chơi $i$ là một hàm $s_i:A_i\to[0,1]$ thỏa mãn $\sum_{a_i\in A_i}s_i(a_i)=1$. Nói cách khác, chiến lược $s_i$ chính là một phân phối xác suất trên tập hành động $A_i$ của người chơi $i$. Tập mọi chiến lược hỗn hợp của người chơi $i$ được ký hiệu là $S_i=\Delta(A_i)$, trong đó $\Delta(A_i)$ biểu thị tập mọi phân phối xác suất trên $A_i$. Nếu $s_i$ là một phân phối xác suất suy biến, tức tồn tại $a\in A_i$ sao cho $s_i(a)=1$, thì chiến lược $s_i$ còn được gọi là **chiến lược thuần** (pure strategy).

Lợi ích của chiến lược hỗn hợp chính là kỳ vọng của lợi ích từ từng hành động đơn lẻ:

$$
v(s_1,s_2) = \sum_{a_1\in A_1}\sum_{a_2\in A_2}s_1(a_1)s_2(a_2)v(a_1,a_2).
$$

Nếu xem mỗi hành động đơn lẻ như chiến lược thuần tương ứng, có thể nhúng tập hành động $A_i$ vào tập chiến lược hỗn hợp $S_i$, và $v(s_1,s_2)$ được định nghĩa ở trên có thể được xem là phần mở rộng của $v(a_1,a_2)$ từ $A_1\times A_2$ lên $S_1\times S_2$.

<span id="định-lý-von-neumann"></span>
### Định lý von Neumann

Sau khi đưa vào chiến lược hỗn hợp, kết quả thu được từ tư tưởng cực đại hóa cực tiểu và cực tiểu hóa cực đại là nhất quán; do đó, kết quả của trò chơi đồng thời tổng bằng không cũng được xác định duy nhất.

???+ note "Định lý (von Neumann)"
    Trong trò chơi đồng thời tổng bằng không cho phép chiến lược hỗn hợp, nếu cả hai bên đều dùng chiến lược tối ưu, thì lợi ích lớn nhất của người chơi $1$ là
    
    $$
    w = \max_{s_1\in S_1}\min_{s_2\in S_2} v(s_1,s_2) = \min_{s_2\in S_2}\max_{s_1\in S_1} v(s_1,s_2),
    $$
    
    lợi ích lớn nhất của người chơi $2$ là $-w$.

??? note "Chứng minh"
    Đặt $w = \max_{s_1\in S_1}\min_{s_2\in S_2} v(s_1,s_2)$. Xét bài toán tối thiểu hóa ở lớp trong. Vì $v(s_1,s_2)=\sum_{a_2\in A_2}s_2(a_2)v(s_1,a_2)$, nên $\min_{s_2\in S_2}v(s_1,s_2)=\min_{a_2\in A_2}v(s_1,a_2)$; nghiệm tối ưu của vế trước chính là chiến lược thuần tương ứng với nghiệm tối ưu của vế sau. Do đó, $w = \max_{s_1\in S_1}\min_{a_2\in A_2} v(s_1,a_2)$. Tiếp theo, đưa vào biến phụ $u$, bài toán có thể viết lại thành
    
    $$
    w = \max_{s_1\in S_1} u \text{ với ràng buộc }u \le \min_{a_2\in A_2} v(s_1,a_2).
    $$
    
    Ràng buộc này tương đương với $u\le v(s_1,a_2)$ đúng với mọi $a_2\in A_2$. Cuối cùng, đưa vào định nghĩa của chiến lược hỗn hợp $s_1$ và biểu thức của hàm lợi ích $v(s_1,a_2)$, bài toán gốc tương đương với [bài toán quy hoạch tuyến tính](../linear-programming.md)
    
    $$
    (P) \qquad
    \begin{aligned}
    w = \max_{u,s_1}\; & u\\
    \text{với ràng buộc }& \sum_{a_1\in A_1}s_1(a_1)v(a_1,a_2) \ge u,~\forall a_2\in A_2,\\
    & \sum_{a_1\in A_1}s_1(a_1) = 1,\\
    & s_1(a_1) \ge 0,~\forall a_1\in A_1.
    \end{aligned}
    $$
    
    Bài toán này khả thi và có nghiệm tối ưu. Theo [nguyên lý đối ngẫu](../linear-programming.md#nguyên-lý-đối-ngẫu), nghiệm tối ưu của nó bằng nghiệm tối ưu của bài toán đối ngẫu:
    
    $$
    (D) \qquad
    \begin{aligned}
    w = \min_{t,s_2}\; & t\\
    \text{với ràng buộc }&\sum_{a_2\in A_2}s_2(a_2)v(a_1,a_2) \le t,~\forall a_1\in A_1,\\
    &\sum_{a_2\in A_2}s_2(a_2) = 1,\\
    &s_2(a_2)\ge 0,~\forall a_2\in A_2.
    \end{aligned}
    $$
    
    Lặp lại các bước ở trên, bài toán này tương đương với $\min_{s_2\in S_2}\max_{s_1\in S_1}v(s_1,s_2)$. Định lý được chứng minh.

Kết quả này chính là [cân bằng Nash](https://en.wikipedia.org/wiki/Nash_equilibrium) của trò chơi này. Nói cách khác, giả sử hai bên đều chọn chiến lược tối ưu trong cân bằng, thì không người chơi nào có thể thu lợi nghiêm ngặt bằng cách lệch khỏi chiến lược cân bằng.

<span id="chuyển-thành-bài-toán-quy-hoạch-tuyến-tính"></span>
### Chuyển thành bài toán quy hoạch tuyến tính

Chứng minh của định lý von Neumann đồng thời cũng chỉ ra cách giải trò chơi đồng thời tổng bằng không. Gọi $n$ và $m$ lần lượt là số hành động mà người chơi $1$ và $2$ có thể chọn. Cho ma trận lợi ích $V\in\mathbf R^{n\times m}$ của người chơi $1$, có thể giải bài toán quy hoạch tuyến tính sau:

$$
\begin{aligned}
w = \max_{(u,s)\in\mathbf R\times\mathbf R^n}\; & u\\
\text{với ràng buộc }& V^Ts \ge u\mathbf 1,\\
& \mathbf 1^Ts = 1,\\
& s \ge 0.
\end{aligned}
$$

Đây là một bài toán quy hoạch tuyến tính có kích thước $\Theta(n+m)$, có thể giải hiệu quả bằng [phương pháp đơn hình](../simplex.md). Nghiệm tối ưu $s$ mà thuật toán thu được chính là chiến lược hỗn hợp tối ưu của người chơi $1$. Để tìm chiến lược tối ưu của người chơi $2$, chỉ cần lấy biến đối ngẫu (tức giá bóng) của nghiệm tối ưu bài toán này từ bảng đơn hình.

<span id="bài-tập_1"></span>
### Bài tập

-   [Luogu P4232 Trốn tìm ngoài vô thức](https://www.luogu.com.cn/problem/P4232)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [Zero-sum game - Wikipedia](https://en.wikipedia.org/wiki/Zero-sum_game)
-   [Minimax theorem - Wikipedia](https://en.wikipedia.org/wiki/Minimax_theorem)
