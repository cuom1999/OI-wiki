author: GoodCoder666, abc1763613206, ksyx

<span id="&#x4E00;&#x4E9B;&#x8BB0;&#x53F7;"></span>

## Một số ký hiệu

-   $\Sigma$: bảng chữ cái. Kích thước bảng chữ cái là $|\Sigma| = k$.
-   $s$: xâu. Độ dài xâu là $|s| = n$, chỉ số bắt đầu từ $0$.
-   $t_0$: trạng thái ban đầu.
-   $\operatorname{endpos}(t)$: tập các vị trí kết thúc của xâu con $t$ trong xâu $s$.
-   $\operatorname{link}(v)$: liên kết hậu tố của trạng thái $v$.
-   $\operatorname{len}(v)$: độ dài xâu con dài nhất ứng với trạng thái $v$.
-   $\operatorname{longest}(v)$: xâu con dài nhất ứng với trạng thái $v$.
-   $\operatorname{minlen}(v)$: độ dài xâu con ngắn nhất ứng với trạng thái $v$.
-   $\operatorname{shortest}(v)$: xâu con ngắn nhất ứng với trạng thái $v$.

<span id="&#x540E;&#x7F00;&#x81EA;&#x52A8;&#x673A;&#x6982;&#x8FF0;"></span>

## Tổng quan về suffix automaton

**Suffix automaton** (SAM) là một cấu trúc dữ liệu mạnh, có thể giải quyết nhiều bài toán liên quan đến xâu.

Ví dụ, các bài toán xâu sau đều có thể được giải bằng SAM trong thời gian tuyến tính:

-   Tìm mọi lần xuất hiện của một xâu trong một xâu khác;
-   Đếm số xâu con phân biệt trong một xâu cho trước.

Về trực giác, SAM của một xâu có thể được hiểu là dạng nén của **tất cả xâu con** của xâu đó. Điểm đáng chú ý là SAM lưu toàn bộ thông tin này dưới dạng nén rất cao. Với một xâu độ dài $n$, độ phức tạp bộ nhớ chỉ là $O(n)$. Hơn nữa, SAM cũng có thể được xây dựng trong $O(n)$. Chính xác hơn, một SAM có nhiều nhất $2n-1$ đỉnh và $3n-4$ cạnh chuyển.

<span id="&#x5B9A;&#x4E49;"></span>

## Định nghĩa

SAM của xâu $s$ là [DFA](../misc/fsm.md#automaton-trạng-thái-hữu-hạn-xác-định) nhỏ nhất chấp nhận tất cả các hậu tố của $s$.

Nói cách khác:

-   SAM là một đồ thị có hướng không chu trình. Các đỉnh được gọi là **trạng thái**, các cạnh được gọi là **chuyển trạng thái**.
-   Đồ thị có một đỉnh nguồn $t_0$, gọi là **trạng thái ban đầu**; mọi đỉnh khác đều có thể đi tới được từ $t_0$.
-   Mỗi **chuyển trạng thái** được gán nhãn bằng một ký tự. Mọi chuyển trạng thái xuất phát từ cùng một đỉnh có nhãn **khác nhau**.
-   Có một hoặc nhiều **trạng thái kết thúc**. Nếu ta bắt đầu từ trạng thái ban đầu $t_0$ và cuối cùng chuyển tới một trạng thái kết thúc, thì chuỗi nhãn của các chuyển trạng thái trên đường đi chắc chắn là một hậu tố của xâu $s$. Ngược lại, mỗi hậu tố của $s$ đều có thể được tạo bởi một đường đi từ $t_0$ tới một trạng thái kết thúc nào đó.
-   Trong tất cả các automaton thỏa các điều kiện trên, SAM có số đỉnh nhỏ nhất.

Điểm cốt lõi của SAM chính là tính nhỏ nhất này. Thực ra, nếu trực tiếp xây [AC automaton](./ac-automaton.md) cho tất cả hậu tố của xâu $s$, ta cũng thu được một DFA chấp nhận tất cả hậu tố của $s$. Nhưng trong trường hợp xấu nhất, automaton đó có $\Theta(n^2)$ đỉnh, nên độ phức tạp không chấp nhận được. Từ ví dụ bên dưới có thể thấy DFA nhận được khi xây AC automaton cho mọi hậu tố có nhiều đỉnh trùng lặp và có thể gộp lại. SAM đẩy việc gộp đỉnh đến mức tối đa, nhờ đó kích thước DFA thu được được khống chế ở $O(n)$. Theo nghĩa này, SAM là AC automaton "nén" của toàn bộ các hậu tố của xâu.

<span id="&#x5B50;&#x4E32;&#x548C;&#x8DEF;&#x5F84;"></span>

### Xâu con và đường đi

Tính chất đơn giản nhất và cũng quan trọng nhất của SAM là nó chứa thông tin về mọi xâu con của xâu $s$. Với bất kỳ đường đi nào bắt đầu từ trạng thái ban đầu $t_0$, nếu viết ra nhãn của tất cả chuyển trạng thái trên đường đi, ta luôn thu được một **xâu con** của $s$. Ngược lại, mỗi xâu con của $s$ đều ứng với một đường đi nào đó bắt đầu từ $t_0$.

Để diễn đạt ngắn gọn, ta nói xâu con **ứng với** đường đi này, tức đường đi bắt đầu từ $t_0$ và chuỗi nhãn trên nó tạo thành xâu con đó. Ngược lại, ta nói một đường đi bất kỳ **ứng với** xâu tạo bởi các nhãn của nó.

Có thể có nhiều hơn một đường đi đi tới cùng một trạng thái, vì vậy ta nói một trạng thái ứng với một tập các xâu; các xâu trong tập lần lượt ứng với các đường đi đó.

<span id="&#x7B80;&#x5355;&#x4F8B;&#x5B50;"></span>

### Ví dụ đơn giản

Ở đây ta trình bày suffix automaton của một vài xâu đơn giản.

Ta dùng màu xanh lam cho trạng thái ban đầu và màu xanh lục cho trạng thái kết thúc.

Với xâu $s=\varnothing$:

![](./images/SAM/SA.svg)

Với xâu $s=\texttt{a}$:

![](./images/SAM/SAa.svg)

Với xâu $s=\texttt{aa}$:

![](./images/SAM/SAaa.svg)

Với xâu $s=\texttt{ab}$:

![](./images/SAM/SAab.svg)

Với xâu $s=\texttt{abb}$:

![](./images/SAM/SAabb.svg)

Với xâu $s=\texttt{abbb}$:

![](./images/SAM/SAabbb.svg)

Trong ví dụ cuối cùng, nếu trực tiếp xây AC automaton cho tất cả hậu tố của nó, đường đi $\texttt{bbb}$ và đường đi $\texttt{abbb}$ đáng ra sẽ dẫn tới hai đỉnh khác nhau. Tuy nhiên hai đỉnh này đều là trạng thái kết thúc, và dù thêm bất kỳ ký tự nào nữa cũng không thể nhận được một xâu khớp dài hơn. Điều đó cho thấy hai đỉnh này có hành vi chuyển trạng thái giống nhau trong automaton, nên có thể gộp thành cùng một đỉnh. Khi đó ta thu được SAM như hình. Phần thảo luận bên dưới sẽ mở rộng ý tưởng gộp đỉnh này cho mọi trường hợp và chứng minh rằng, nếu gộp đỉnh hợp lý, SAM cuối cùng chỉ có $O(n)$ đỉnh và chuyển trạng thái.

<span id="&#x7EBF;&#x6027;&#x590D;&#x6742;&#x5EA6;&#x7684;&#x6784;&#x9020;&#x7B97;&#x6CD5;"></span>

## Thuật toán xây dựng tuyến tính

Trước khi mô tả thuật toán xây SAM trong thời gian tuyến tính, ta cần giới thiệu hai khái niệm rất quan trọng để hiểu quá trình xây dựng, đồng thời chứng minh ngắn gọn các tính chất của chúng. Trong đó, tập vị trí kết thúc $\operatorname{endpos}$ định nghĩa các đỉnh trong SAM, tức chỉ ra điều kiện cần và đủ để gộp các đỉnh; còn liên kết hậu tố $\operatorname{link}$ chỉ là đối ứng tự nhiên trong SAM của [con trỏ thất bại](./ac-automaton.md#con-trỏ-thất-bại) trong AC automaton.

<span id="&#x7ED3;&#x675F;&#x4F4D;&#x7F6E;-endpos"></span>

### Tập vị trí kết thúc `endpos`

Xét một xâu con không rỗng bất kỳ $t$ của xâu $s$. Ta ký hiệu $\operatorname{endpos}(t)$ là tập tất cả vị trí kết thúc của $t$ trong xâu $s$ (giả sử các ký tự trong xâu được đánh số từ không). Ví dụ, với xâu $\texttt{abcbc}$, ta có $\operatorname{endpos}(\texttt{bc})=\{2,4\}$.

Hai xâu con $t_1$ và $t_2$ có thể có tập vị trí kết thúc hoàn toàn giống nhau: $\operatorname{endpos}(t_1)=\operatorname{endpos}(t_2)$. Điều này định nghĩa một quan hệ tương đương trên các xâu con của $s$. Tất cả xâu con không rỗng của $s$ có thể được chia thành nhiều **lớp tương đương** theo tập vị trí kết thúc $\operatorname{endpos}$ của chúng.

Một sự thật là mỗi lớp tương đương như vậy ứng với một trạng thái của SAM[^state-endpos]. Tức là, nếu hai xâu con có cùng vị trí kết thúc, đường đi của chúng trong SAM sẽ ứng với cùng một trạng thái. Nói cách khác, mỗi trạng thái không phải trạng thái ban đầu trong SAM ứng với một hoặc nhiều xâu con không rỗng có cùng $\operatorname{endpos}$. Tóm lại, các trạng thái trong SAM chính là các lớp tương đương của mọi xâu con không rỗng, cộng thêm trạng thái ban đầu.

Tạm thời chấp nhận sự thật này, ta sẽ dựa vào nó để giới thiệu thuật toán xây SAM. Ta cũng sẽ chỉ ra rằng mọi tính chất mà SAM cần thỏa, ngoại trừ tính nhỏ nhất, đều đã được thỏa mãn; còn tính nhỏ nhất có thể suy ra từ [định lý Myhill-Nerode](../misc/fsm.md#định-lý-myhill-nerode).

Từ giá trị của $\operatorname{endpos}$, ta có thể rút ra một số kết luận quan trọng. Chúng giải thích quan hệ giữa các xâu con khác nhau ứng với cùng một trạng thái.

???+ note "Bổ đề 1"
    Hai xâu con không rỗng $u$ và $w$ của xâu $s$ (giả sử $\left|u\right|\le \left|w\right|$) có cùng $\operatorname{endpos}$ khi và chỉ khi mỗi lần $u$ xuất hiện trong $s$, nó đều xuất hiện dưới dạng một hậu tố của $w$.

??? note "Chứng minh"
    Bổ đề là hiển nhiên. Nếu $u$ và $w$ có cùng $\operatorname{endpos}$, thì $u$ là một hậu tố của $w$, và trong $s$ nó chỉ xuất hiện dưới dạng hậu tố của $w$. Ngược lại, theo định nghĩa, nếu $u$ là một hậu tố của $w$ và chỉ xuất hiện trong $s$ dưới dạng hậu tố của $w$, thì hai xâu con này có cùng $\operatorname{endpos}$.

???+ note "Bổ đề 2"
    Xét hai xâu con không rỗng $u$ và $w$ (giả sử $\left|u\right|\le \left|w\right|$). Khi đó, hoặc $\operatorname{endpos}(u)\cap \operatorname{endpos}(w)=\varnothing$, hoặc $\operatorname{endpos}(w)\subseteq \operatorname{endpos}(u)$, tùy theo $u$ có phải là một hậu tố của $w$ hay không:
    
    $$
    \begin{cases}
    \operatorname{endpos}(w) \subseteq \operatorname{endpos}(u), & \text{if } u \text{ is a suffix of } w, \\
    \operatorname{endpos}(w) \cap \operatorname{endpos}(u) = \varnothing, & \text{otherwise}.
    \end{cases}
    $$

??? note "Chứng minh"
    Nếu hai tập $\operatorname{endpos}(u)$ và $\operatorname{endpos}(w)$ có ít nhất một phần tử chung, thì do $u$ và $w$ kết thúc tại cùng một vị trí, $u$ là một hậu tố của $w$. Vì vậy, tại mỗi vị trí mà $w$ xuất hiện, xâu con $u$ cũng xuất hiện. Do đó $\operatorname{endpos}(w)\subseteq \operatorname{endpos}(u)$.

???+ note "Bổ đề 3"
    Xét một lớp tương đương gồm các xâu con có cùng $\operatorname{endpos}$, và sắp xếp mọi xâu con trong lớp theo thứ tự độ dài không tăng. Khi đó, mỗi xâu con không dài hơn xâu đứng trước nó, đồng thời cũng là hậu tố của xâu đứng trước. Nói cách khác, với hai xâu con bất kỳ trong cùng một lớp tương đương, xâu ngắn hơn là hậu tố của xâu dài hơn; độ dài các xâu con trong lớp là liên tiếp và lấy đủ mọi giá trị nguyên trong một đoạn nào đó.

??? note "Chứng minh"
    Nếu lớp tương đương chỉ chứa một xâu con, bổ đề là hiển nhiên. Bây giờ xét lớp tương đương có nhiều hơn $1$ xâu con.
    
    Theo Bổ đề 1, trong hai xâu khác nhau có cùng $\operatorname{endpos}$, chắc chắn một xâu dài hơn, một xâu ngắn hơn, và xâu ngắn hơn luôn là hậu tố thực sự của xâu dài hơn. Tức là trong cùng một lớp tương đương không có hai xâu cùng độ dài.
    
    Gọi $w$ là xâu dài nhất trong lớp tương đương, và $u$ là xâu ngắn nhất. Theo Bổ đề 1, xâu $u$ là hậu tố thực sự của xâu $w$. Bây giờ xét một hậu tố bất kỳ của $w$ có độ dài thuộc đoạn $[\left|u\right|,\left|w\right|]$. Dễ thấy hậu tố này cũng thuộc cùng lớp tương đương, vì nó chỉ có thể xuất hiện trong xâu $s$ dưới dạng một hậu tố của $w$ (do hậu tố ngắn hơn $u$ trong $s$ chỉ xuất hiện dưới dạng hậu tố của $w$). Vì vậy, theo Bổ đề 1, hậu tố này và xâu $w$ có cùng $\operatorname{endpos}$.

Tóm lại trong một câu: các xâu con ứng với cùng một trạng thái có độ dài đôi một khác nhau, tạo thành một số tự nhiên liên tiếp, và xâu ngắn hơn luôn là hậu tố của xâu dài hơn.

<span id="&#x540E;&#x7F00;&#x94FE;&#x63A5;-link"></span>

### Liên kết hậu tố `link`

Xét một trạng thái $v\neq t_0$ trong SAM. Ta đã biết trạng thái $v$ ứng với một lớp tương đương các xâu con có cùng $\operatorname{endpos}$. Nếu định nghĩa $w$ là xâu dài nhất trong các xâu này, thì mọi xâu còn lại đều là hậu tố của $w$.

Ta cũng biết vài hậu tố đầu tiên của $w$ (xét theo thứ tự độ dài giảm dần) đều thuộc lớp tương đương này, còn các hậu tố khác (ít nhất có hậu tố rỗng) thuộc các lớp tương đương khác. Gọi $t$ là hậu tố dài nhất trong các hậu tố khác đó, rồi nối liên kết hậu tố của $v$ tới trạng thái của $t$.

Nói cách khác, **liên kết hậu tố** $\operatorname{link}(v)$ của $v$ trỏ tới trạng thái ứng với hậu tố dài nhất của $w$ có tập $\operatorname{endpos}$ khác với $w$; đó cũng là hậu tố dài nhất của $w$ xuất hiện trong $s$ nhiều lần hơn $w$.

Để tiện thảo luận, ta quy ước lớp tương đương ứng với trạng thái ban đầu $t_0$ chỉ chứa xâu rỗng, và $\operatorname{endpos}(t_0)=\{-1,0,\ldots,\left|S\right|-1\}$.

???+ note "Bổ đề 4"
    Tất cả liên kết hậu tố tạo thành một cây có gốc là $t_0$.

??? note "Chứng minh"
    Xét trạng thái bất kỳ $v\neq t_0$. Trạng thái mà liên kết hậu tố $\operatorname{link}(v)$ trỏ tới ứng với một xâu ngắn hơn nghiêm ngặt (theo định nghĩa liên kết hậu tố và Bổ đề 3). Vì vậy, khi đi theo các liên kết hậu tố, ta luôn có thể tới trạng thái ban đầu $t_0$ ứng với xâu rỗng.

???+ note "Bổ đề 5"
    Cây được xây bằng cách lấy các tập $\operatorname{endpos}$ làm đỉnh và quan hệ bao hàm giữa các tập làm cạnh (tức tập $\operatorname{endpos}$ của mỗi nút con nằm trong tập $\operatorname{endpos}$ của nút cha) trùng với cây được xây bởi các liên kết hậu tố $\operatorname{link}$.

??? note "Chứng minh"
    Theo Bổ đề 2, các tập $\operatorname{endpos}$ của một SAM bất kỳ tạo thành một cây, vì hai tập hoặc hoàn toàn không giao nhau, hoặc một tập là con của tập kia.
    
    Bây giờ xét một trạng thái bất kỳ $v\neq t_0$ và liên kết hậu tố $\operatorname{link}(v)$. Từ liên kết hậu tố và Bổ đề 2, ta có
    
    $$
    \operatorname{endpos}(v)\subsetneq \operatorname{endpos}(\operatorname{link}(v)).
    $$
    
    Lưu ý ở đây phải là $\subsetneq$ chứ không phải $\subseteq$, vì nếu $\operatorname{endpos}(v)=\operatorname{endpos}(\operatorname{link}(v))$, thì $v$ và $\operatorname{link}(v)$ lẽ ra phải được gộp thành cùng một đỉnh.

Kết hợp các bổ đề trước, ta có: cây tạo bởi các liên kết hậu tố về bản chất là cây tạo bởi các tập $\operatorname{endpos}$.

Dưới đây là một **ví dụ** về cây liên kết hậu tố sinh ra khi xây SAM cho xâu $\texttt{abcbc}$; mỗi đỉnh được gắn nhãn bằng xâu con dài nhất trong lớp tương đương tương ứng.

![](./images/SAM/SA_suffix_links.svg)

Kết hợp với hình minh họa, nếu hình thành được một số trực giác về suffix automaton thì việc hiểu thuật toán xây dựng và các ứng dụng bên dưới sẽ dễ hơn.

???+ example "Giải thích hình minh họa"
    -   Trên SAM tồn tại một đường đi dài nhất có nhãn đúng bằng chính xâu $\texttt{abcbc}$. Đường đi này bắt đầu từ trạng thái ban đầu; mỗi trạng thái đi qua đều ứng với một tiền tố của xâu $\texttt{abcbc}$ ($\varnothing,\texttt{a},\texttt{ab},\texttt{abc},\texttt{abcb},\texttt{abcbc}$). Các trạng thái này rất quan trọng trong phần [ứng dụng](#%E5%90%8E%E7%BC%80%E9%93%BE%E6%8E%A5%E6%A0%91) phía sau.
    -   Có thể xem cây liên kết hậu tố là kết quả "nén" các đường đi từ những "trạng thái tiền tố" này về gốc (tức trạng thái ban đầu) theo liên kết hậu tố.
    
        -   Dọc theo mỗi đường đi, các tập xâu ứng với các đỉnh tạo thành một phân hoạch của toàn bộ hậu tố của tiền tố tương ứng. Ví dụ, đường đi theo liên kết hậu tố từ trạng thái gắn nhãn $\texttt{abcbc}$ về gốc là $\texttt{abcbc}\rightarrow\texttt{bc}\rightarrow\varnothing$. Trong đó, đỉnh $\texttt{abcbc}$ thực ra ứng với tập xâu $\{\texttt{abcbc},\texttt{bcbc},\texttt{cbc}\}$, đỉnh $\texttt{bc}$ ứng với tập xâu $\{\texttt{bc},\texttt{c}\}$, và đỉnh $\varnothing$ ứng với xâu rỗng.
        -   Các đường đi khác nhau có thể dùng chung một đỉnh; đó là lý do có sự "nén". Ví dụ, đường đi $\texttt{abc}\rightarrow\texttt{bc}\rightarrow\varnothing$ và đường đi $\texttt{abcbc}\rightarrow\texttt{bc}\rightarrow\varnothing$ cùng dùng chung đỉnh $\texttt{bc}$. Nguyên nhân là $\operatorname{endpos}(\texttt{bc})=\{2,4\}$; trước xâu $\texttt{bc}$ kết thúc ở vị trí $2$ là ký tự $\texttt{a}$, còn trước xâu $\texttt{bc}$ kết thúc ở vị trí $4$ là ký tự $\texttt{c}$. Vì vậy, khi thêm ký tự ở phía trước (tức đi ngược liên kết hậu tố), tập vị trí kết thúc, tức trạng thái, sẽ tách ra.
        -   Cây liên kết hậu tố chỉ cần "nén" hợp lý các đường đi hậu tố này lại với nhau, không cần xét các đỉnh khác. Lý do là mọi xâu con đều là hậu tố của một tiền tố nào đó, nên chắc chắn xuất hiện trên một đường đi như vậy. Thuật toán xây dựng bên dưới về bản chất là thêm từng ký tự, rồi với mỗi tiền tố mới, xây một đường đi hậu tố như vậy và "nén" nó hợp lý vào các đường đi đã có, tức không xây lặp trạng thái và chuyển trạng thái đã tồn tại.
        -   Các trạng thái kết thúc chính là tất cả đỉnh trên đường đi hậu tố chứa chính xâu $\texttt{abcbc}$.
    -   Các chuyển trạng thái đi tới cùng một trạng thái chắc chắn có cùng nhãn, và các điểm đầu của chúng chắc chắn nằm trên một đoạn đường đi liên tiếp nào đó trong cây liên kết hậu tố. Ví dụ, có hai trạng thái chuyển tới trạng thái $\texttt{abcb}$: $\texttt{abc}$ và $\texttt{bc}$. Chúng nằm trên đường đi $\texttt{abc}\rightarrow\texttt{bc}$ của cây hậu tố. Lưu ý rằng chúng lần lượt ứng với tập xâu $\{\texttt{abc}\}$ và $\{\texttt{bc},\texttt{c}\}$; khi thêm ký tự $\texttt{b}$ vào sau các xâu này, ta thu được tập xâu $\{\texttt{abcb},\texttt{bcb},\texttt{cb}\}$ ứng với trạng thái $\texttt{abcb}$.
    
        -   Sau khi thêm ký tự, các trạng thái khác nhau có thể chuyển tới cùng một trạng thái vì ký tự mới khiến việc mở rộng tập vị trí kết thúc trở nên khó hơn.
    -   Trên cây liên kết hậu tố, tập $\operatorname{endpos}$ của mỗi đỉnh là hợp của các tập $\operatorname{endpos}$ của các nút con, nhiều nhất thêm một vị trí nữa. Vị trí mới này tồn tại khi và chỉ khi đỉnh đó đúng là tiền tố của xâu gốc kết thúc tại vị trí ấy. Trong hình minh họa, các đỉnh không phải gốc và không phải lá của cây liên kết hậu tố đều không ứng với tiền tố của xâu $\texttt{abcbc}$, nên trường hợp đó không xảy ra.

Suffix automaton lưu thông tin về toàn bộ xâu con của xâu. Có thể hiểu điều này từ hai góc nhìn:

-   Bản thân SAM có thể được xem là phiên bản nén của AC automaton trên toàn bộ hậu tố của xâu. Vì vậy, nó lưu thông tin về mọi tiền tố của mọi hậu tố, tương đương với lưu thông tin về mọi xâu con của xâu.
-   Cây liên kết hậu tố của SAM có thể được xem là phiên bản nén của các đường đi hậu tố của toàn bộ tiền tố của xâu. Vì vậy, nó lưu thông tin về mọi hậu tố của mọi tiền tố, cũng tương đương với lưu thông tin về mọi xâu con của xâu.

Cả hai cách nhìn này đều hữu ích khi xử lý các bài toán khác nhau.

<span id="&#x5C0F;&#x7ED3;"></span>

### Tóm tắt

Trước khi tiếp tục bàn về chính thuật toán, ta tóm tắt nội dung đã có và giới thiệu vài ký hiệu phụ trợ.

-   Các xâu con của $s$ có thể được chia thành nhiều lớp tương đương theo tập vị trí kết thúc $\operatorname{endpos}$ của chúng;

-   SAM gồm trạng thái ban đầu $t_0$ và mỗi trạng thái ứng với một lớp tương đương $\operatorname{endpos}$ của các xâu con không rỗng;

-   Mỗi trạng thái $v$ khớp với một hoặc nhiều xâu con. Ta ký hiệu $\operatorname{longest}(v)$ là xâu dài nhất trong số đó, và $\operatorname{len}(v)$ là độ dài của nó. Tương tự, ký hiệu $\operatorname{shortest}(v)$ là xâu con ngắn nhất, với độ dài $\operatorname{minlen}(v)$. Khi đó mọi xâu ứng với trạng thái này đều là các hậu tố khác nhau của xâu $\operatorname{longest}(v)$, và độ dài của chúng lấy đúng mọi số nguyên trong đoạn $[\operatorname{minlen}(v),\operatorname{len}(v)]$.

-   Với trạng thái bất kỳ $v\neq t_0$, định nghĩa liên kết hậu tố là cạnh trỏ tới hậu tố của xâu $\operatorname{longest}(v)$ có độ dài $\operatorname{minlen}(v)-1$. Các liên kết hậu tố xuất phát từ gốc $t_0$ tạo thành một cây. Cây này cũng biểu diễn quan hệ bao hàm giữa các tập $\operatorname{endpos}$.

-   Với trạng thái bất kỳ $v\neq t_0$, có thể biểu diễn $\operatorname{minlen}(v)$ bằng liên kết hậu tố $\operatorname{link}(v)$:

    $$
    \operatorname{minlen}(v)=\operatorname{len}(\operatorname{link}(v))+1.
    $$

-   Nếu bắt đầu từ trạng thái bất kỳ $v_0$ và duyệt theo liên kết hậu tố, ta luôn đi tới trạng thái ban đầu $t_0$. Khi đó ta nhận được một dãy các đoạn đôi một không giao nhau $[\operatorname{minlen}(v_i),\operatorname{len}(v_i)]$, và hợp của chúng tạo thành đoạn liên tiếp $[0,\operatorname{len}(v_0)]$.

<span id="&#x7B97;&#x6CD5;"></span>

### Thuật toán

Bây giờ ta có thể thảo luận thuật toán xây SAM. Thuật toán này là thuật toán **trực tuyến**: ta có thể thêm từng ký tự của xâu và duy trì SAM tương ứng ở mỗi bước.

Trước khi bàn về cài đặt chi tiết, trước hết hãy dùng hình minh họa để cảm nhận sơ bộ những thay đổi có thể xảy ra trong SAM khi thêm ký tự mới $c$.

???+ note "Hiểu đơn giản quá trình xây dựng tăng dần"
    Từ SAM của xâu $s$, ta có thể xây SAM của xâu $s+c$. Theo phần giải thích hình minh họa ở trên, ta chỉ cần xây đường đi hậu tố của tiền tố mới được thêm vào, tức $s+c$, rồi nén nó vào các đường đi hiện có. Hơn nữa, theo mô tả trước đó, các đỉnh trên đường đi hậu tố mới chắc chắn đều có thể nhận được bằng cách đi từ các đỉnh trên đường đi hậu tố của xâu cũ $s$ qua chuyển trạng thái mang ký tự $c$.
    
    Trước hết xét, trước khi thêm ký tự mới $c$, đường đi hậu tố của xâu cũ $s$ có thể có dạng nào và sẽ chuyển qua ký tự $c$ ra sao. Trường hợp tổng quát nhất được minh họa như sau:
    
    ![](./images/SAM/sam-suffix-path-1.svg)
    
    Trong hình, đường đi hậu tố của xâu cũ $s$ là $p_0\rightarrow p_1\rightarrow\cdots\rightarrow p_6\rightarrow t_0$, các liên kết hậu tố được biểu diễn bằng mũi tên màu đỏ. Một số đỉnh trong đó (cụ thể là $p_2\sim p_6$) đã có chuyển trạng thái qua ký tự $c$; do thêm cùng một ký tự vào các hậu tố liên tiếp cũng tạo ra các hậu tố liên tiếp, các điểm đến của những chuyển trạng thái này tạo thành một đường đi hậu tố khác $q_1\rightarrow q_2\rightarrow q_3\rightarrow t_0$. Lúc này có hai quan sát:
    
    -   Trên đường đi hậu tố của xâu cũ $s$, các đỉnh không có chuyển trạng thái qua $c$ chắc chắn là vài đỉnh đầu tiên. Chỉ cần từ một đỉnh nào đó (trong hình là $p_2$) đã có chuyển trạng thái qua $c$, thì mọi đỉnh đi tiếp sau đó cũng chắc chắn có chuyển trạng thái qua $c$.
    
        **Giải thích**: đặt $s_2=\operatorname{longest}(p_2)$. Khi đó mọi đỉnh đi tiếp sau đó đều ứng với hậu tố của $s_2$. Nếu $s_2+c$ cũng xuất hiện trong $s$, thì hậu tố của $s_2$ cộng thêm $c$ cũng chắc chắn xuất hiện trong $s$, nên các đỉnh đó đều có chuyển trạng thái qua $c$.
    -   Dù các đỉnh có thể đi qua ký tự $c$ tới đỉnh $q_i$ chắc chắn tạo thành một đoạn liên tiếp trên cây liên kết hậu tố, đoạn liên tiếp này không nhất thiết nằm hoàn toàn trên đường đi hậu tố từ $p_0$ tới gốc. Đặc biệt, chỉ một số đỉnh đầu của đoạn liên tiếp ứng với đỉnh đầu tiên $q_1$ là **có thể** không nằm trên đường đi hậu tố này. Ví dụ trong hình, đỉnh $q_1$ ứng với các đỉnh $p_1'\rightarrow p_2\rightarrow p_3$, trong đó $p_1'$ không nằm trên đường đi hậu tố của $p_0$.
    
        **Giải thích**: đặt $s_2=\operatorname{longest}(p_2)$. Khi đó $s_2+c$ ứng với $q_1$, nhưng trong hình rõ ràng $s_2+c\neq\operatorname{longest}(q_1)$, vì vế sau là $\operatorname{longest}(p'_1)+c$. Điều này cho thấy một phần các xâu ứng với $q_1$ không thể thu được bằng cách chuyển từ $s_2$ và các hậu tố của nó. Ngược lại, các xâu trong $q_2$ chắc chắn là hậu tố của $s_2+c$, nên sau khi bỏ ký tự $c$ ở cuối, chúng chắc chắn là hậu tố của $s_2$. Tức là các đỉnh chuyển qua $c$ tới $q_2$ chắc chắn nằm trên đường đi hậu tố bắt đầu từ $p_2$. Đó cũng là lý do chỉ một phần các đỉnh trong đoạn liên tiếp ứng với $q_1$ ban đầu có thể không nằm trên đường đi hậu tố của $p_0$.
    
    Với hình minh họa này, nếu thêm một ký tự $c$ vào cuối xâu cũ $s$ và xây đường đi hậu tố tương ứng, điều gì sẽ xảy ra? Câu trả lời được thể hiện trong hình sau:
    
    ![](./images/SAM/sam-suffix-path-2.svg)
    
    Vì đỉnh $q_0$ được chuyển tới từ đỉnh $p_0$ ứng với xâu cũ $s$ qua ký tự $c$, nó ứng với xâu mới $s+c$. Do đó đường đi hậu tố $q_0\rightarrow q_1''\rightarrow q_2\rightarrow q_3\rightarrow t_0$ của nó chính là đường đi hậu tố mới được thêm vào. Nếu các đỉnh $p_i$ trên đường đi hậu tố cũ vốn đã có chuyển trạng thái qua $c$, thì đường đi hậu tố mới cũng chắc chắn đi qua các đỉnh là điểm đến của những chuyển trạng thái này, nên có thể trực tiếp tái sử dụng các đỉnh cũ. Trên đường đi hậu tố mới có đúng một đỉnh hoàn toàn mới $q_0$, dùng để nhận các chuyển trạng thái từ những đỉnh ban đầu trên đường đi hậu tố cũ chưa có chuyển trạng thái qua $c$.
    
    Ngoài những sự thật hiển nhiên đó, có thể thấy đỉnh cũ $q_1$ cũng đã được sao chép, hay nói cách khác là bị tách thành hai đỉnh $q'_1\rightarrow q_1''$. Lý do là đường đi hậu tố mới chỉ trùng một phần với đường đi hiện có: trong các xâu ứng với đỉnh cũ $q_1$, chỉ những xâu ngắn hơn (tức những xâu mà các đỉnh $p_2$ và $p_3$ có thể chuyển tới) mới xuất hiện trên đường đi hậu tố mới, còn những xâu dài hơn (tức những xâu mà đỉnh $p_1'$ có thể chuyển tới) thì không. Vì vậy đường đi hậu tố mới chỉ có thể đi qua một phần của đỉnh $q_1$, và đỉnh này phải tách thành hai đỉnh để biểu diễn tình huống đó. Tương tự, như đã giải thích trước đó, các đỉnh $q_2$ và $q_3$ sau $q_1$ đều không thể được chuyển tới từ những đỉnh nằm ngoài đường đi hậu tố của $p_0$, nên mọi xâu ứng với các đỉnh này đều xuất hiện trên đường đi hậu tố mới và không cần tách.
    
    Nhìn từ ý nghĩa của trạng thái trong SAM, mỗi trạng thái là một tập $\operatorname{endpos}$. Giả sử khi kéo dài xâu, vị trí kết thúc mới là $i$. Khi đó đỉnh mới $q_0$ chính là tập vị trí kết thúc $\{i\}$, còn hai đỉnh tách ra $q_1'$ và $q_1''$ lần lượt ứng với các tập $\operatorname{endpos}(q_1)$ và $\operatorname{endpos}(q_1)\cup\{i\}$. Các đỉnh $q_2$ và $q_3$ phía sau thực ra đều được thêm $i$ vào tập vị trí kết thúc cũ. Tức là dù $q_2$, $q_3$ và các chuyển trạng thái liên quan không thay đổi, tập $\operatorname{endpos}$ tương ứng của chúng thực sự đã mở rộng.
    
    Phần trên mô tả trường hợp phức tạp nhất và tổng quát nhất, tức **trường hợp ba** bên dưới. Trong thực tế, có thể không tồn tại đỉnh $p'_1$, nên cũng không cần tách, tức **trường hợp hai** bên dưới. Để nhận biết trường hợp này, chỉ cần kiểm tra $\operatorname{longest}(q_1)=\operatorname{longest}(p_2)+c$, tức $\operatorname{len}(q_1)=\operatorname{len}(p_2)+1$. Cũng có thể mọi đỉnh trên đường đi hậu tố của $p_0$ đều không có chuyển trạng thái qua $c$; khi đó chỉ cần tạo mới $q_0$, tức **trường hợp một** bên dưới.

Sau khi nắm được ý tưởng về đường đi hậu tố mới, bây giờ ta thảo luận các bước cụ thể của quá trình xây dựng tăng dần.

<span id="&#x8FC7;&#x7A0B;"></span>

#### Quy trình

Để bảo đảm độ phức tạp bộ nhớ tuyến tính, ta chỉ lưu các giá trị $\operatorname{len}$ và $\operatorname{link}$ cùng danh sách chuyển trạng thái của mỗi trạng thái; ta không đánh dấu trạng thái kết thúc (nhưng lát nữa sẽ chỉ ra cách gán các dấu này sau khi xây xong SAM).

Ban đầu SAM chỉ chứa một trạng thái $t_0$, có số hiệu $0$ (các trạng thái khác có số hiệu $1,2,\ldots$). Để tiện, với trạng thái $t_0$ ta đặt $\operatorname{len}(t_0)=0$, $\operatorname{link}(t_0)=-1$ ($-1$ biểu diễn trạng thái ảo).

Bây giờ chỉ cần cài đặt quy trình thêm một ký tự $c$ vào xâu hiện tại. Thuật toán như sau:

???+ note "Quy trình xây SAM tăng dần"
    -   Gọi $\textit{last}$ là trạng thái ứng với toàn bộ xâu trước khi thêm ký tự $c$ (ban đầu đặt $\textit{last}=0$, và bước cuối của thuật toán cập nhật $\textit{last}$).
    -   Tạo một trạng thái mới $\textit{cur}$, gán $\operatorname{len}(\textit{cur})=\operatorname{len}(\textit{last})+1$. Lúc này giá trị $\operatorname{link}(\textit{cur})$ vẫn chưa biết.
    -   Bây giờ thực hiện quá trình sau: bắt đầu từ trạng thái $\textit{last}$; nếu trạng thái hiện tại chưa có chuyển trạng thái nhãn $c$, ta thêm một chuyển trạng thái qua ký tự $c$ tới trạng thái $\textit{cur}$, rồi đi theo liên kết hậu tố từ trạng thái hiện tại. Nếu trong quá trình gặp một trạng thái đã có chuyển trạng thái bằng ký tự $c$, ta dừng lại và gọi trạng thái đó là $p$.
    -   **Trường hợp một**: nếu không tìm thấy trạng thái $p$ như vậy, ta đã đi tới trạng thái ảo $-1$; khi đó gán $\operatorname{link}(\textit{cur})=0$ rồi kết thúc.
    -   Giả sử bây giờ đã tìm được một trạng thái $p$ có thể chuyển qua ký tự $c$. Gọi trạng thái được chuyển tới là $q$. Khi đó hoặc $\operatorname{len}(p)+1=\operatorname{len}(q)$, hoặc $\operatorname{len}(p)+1<\operatorname{len}(q)$.
    -   **Trường hợp hai**: nếu $\operatorname{len}(p)+1=\operatorname{len}(q)$, chỉ cần gán $\operatorname{link}(\textit{cur})=q$ rồi kết thúc.
    -   **Trường hợp ba**: ngược lại, tình hình phức tạp hơn và cần **sao chép** trạng thái $q$: ta tạo một trạng thái mới $\textit{clone}$, sao chép toàn bộ thông tin của $q$ ngoại trừ giá trị $\operatorname{len}$ (liên kết hậu tố và các chuyển trạng thái). Gán $\operatorname{len}(\textit{clone})=\operatorname{len}(p)+1$.
    
        Sau khi sao chép, ta cho liên kết hậu tố từ $\textit{cur}$ trỏ tới $\textit{clone}$, và cũng cho liên kết hậu tố từ $q$ trỏ tới $\textit{clone}$.
    
        Cuối cùng, cần đi ngược theo liên kết hậu tố từ trạng thái $p$; miễn là trạng thái đi qua có chuyển trạng thái tới $q$, ta nối lại chuyển trạng thái đó sang $\textit{clone}$.
    -   Sau khi xử lý xong một trong ba trường hợp trên, ta đều cần cập nhật $\textit{last}$ thành trạng thái $\textit{cur}$.

Nếu muốn biết trạng thái nào là **trạng thái kết thúc**, ta có thể tìm tất cả trạng thái kết thúc sau khi đã xây xong SAM đầy đủ cho xâu $s$. Cụ thể, bắt đầu từ trạng thái ứng với toàn bộ xâu (được lưu trong biến $\textit{last}$), duyệt theo các liên kết hậu tố cho tới khi tới trạng thái ban đầu. Đánh dấu mọi trạng thái đi qua là trạng thái kết thúc. Dễ thấy cách này đánh dấu chính xác mọi hậu tố của xâu $s$, và các trạng thái đó đều là trạng thái kết thúc.

Vì với mỗi ký tự của $s$ ta chỉ tạo một hoặc hai trạng thái mới, SAM chỉ chứa **số lượng tuyến tính** trạng thái. Tuy nhiên, số chuyển trạng thái của SAM là tuyến tính và tổng thời gian chạy của thuật toán là tuyến tính vẫn chưa được giải thích rõ; phần sau sẽ chứng minh.

<span id="&#x89E3;&#x91CA;"></span>

#### Giải thích

Ta giải thích chi tiết từng bước của thuật toán và chứng minh **tính đúng đắn** của nó.

???+ note "Giải thích chi tiết thuật toán"
    -   Nếu một chuyển trạng thái $(p,q)$ thỏa $\operatorname{len}(p)+1=\operatorname{len}(q)$, ta gọi chuyển trạng thái này là **liên tục**. Ngược lại, khi $\operatorname{len}(p)+1<\operatorname{len}(q)$, chuyển trạng thái đó được gọi là **không liên tục**.
    
        Từ mô tả thuật toán có thể thấy các chuyển trạng thái liên tục và không liên tục được xử lý khác nhau. Chuyển trạng thái liên tục là cố định, ta sẽ không thay đổi nó nữa. Ngược lại, khi chèn một ký tự mới vào xâu, chuyển trạng thái không liên tục có thể thay đổi (đầu mút của cạnh chuyển có thể thay đổi).
    -   Để tránh nhập nhằng, ta ký hiệu xâu trước khi chèn ký tự hiện tại $c$ vào SAM là $s$.
    -   Thuật toán bắt đầu bằng việc tạo trạng thái mới $\textit{cur}$, ứng với toàn bộ xâu $s+c$. Lý do tạo một đỉnh mới là rõ ràng. Đồng thời, ta cũng tạo ra một ký tự mới và một lớp tương đương mới.
    -   Sau khi tạo trạng thái mới, ta đi từ trạng thái $\textit{last}$ ứng với toàn bộ xâu $s$ theo các liên kết hậu tố. Với mỗi trạng thái đi qua, ta thử thêm một chuyển trạng thái qua ký tự $c$ tới trạng thái mới $\textit{cur}$.
    
        Tuy nhiên, ta chỉ có thể thêm các chuyển trạng thái không xung đột với chuyển trạng thái đã có. Vì vậy, hễ tìm thấy một chuyển trạng thái $c$ đã tồn tại, ta phải dừng lại.
    -   Trường hợp đơn giản nhất là ta đi tới trạng thái ảo $-1$. Điều này có nghĩa là ta đã thêm chuyển trạng thái $c$ cho mọi hậu tố của $s$. Nó cũng có nghĩa là ký tự $c$ chưa từng xuất hiện trong xâu $s$. Vì vậy liên kết hậu tố của $\textit{cur}$ là trạng thái $0$.
    -   Trong trường hợp thứ hai, ta tìm được chuyển trạng thái có sẵn $(p,q)$. Điều này có nghĩa là ta đang thử thêm vào automaton một xâu **đã tồn tại** $x+c$, trong đó $x$ là một hậu tố của $s$ và xâu $x+c$ đã xuất hiện như một xâu con của $s$. Vì giả sử automaton của xâu $s$ đã được xây đúng, ta không nên thêm một chuyển trạng thái mới ở đây.
    
        Tuy nhiên, điểm khó là liên kết hậu tố từ trạng thái $\textit{cur}$ nên nối tới trạng thái nào? Ta cần nối liên kết hậu tố tới một trạng thái có xâu dài nhất đúng bằng $x+c$, tức $\operatorname{len}$ của trạng thái đó phải là $\operatorname{len}(p)+1$. Nhưng trạng thái như vậy có thể chưa tồn tại, tức $\operatorname{len}(q)>\operatorname{len}(p)+1$. Trong trường hợp này, ta phải tách trạng thái $q$ để tạo ra một trạng thái như vậy.
    -   Tất nhiên, nếu chuyển trạng thái $(p,\,q)$ là liên tục, thì $\operatorname{len}(q)=\operatorname{len}(p)+1$. Khi đó mọi thứ rất đơn giản: chỉ cần cho liên kết hậu tố của $\textit{cur}$ trỏ tới trạng thái $q$.
    -   Ngược lại, chuyển trạng thái là không liên tục, tức $\operatorname{len}(q)>\operatorname{len}(p)+1$. Điều này có nghĩa trạng thái $q$ không chỉ ứng với hậu tố độ dài $\operatorname{len}(p)+1$ của $s+c$, mà còn ứng với những xâu con dài hơn của $s$. Ngoài việc tách trạng thái $q$ thành hai trạng thái con, ta không còn cách nào khác, nên độ dài của trạng thái con thứ nhất sẽ là $\operatorname{len}(p)+1$.
    
        Tách một trạng thái như thế nào? Ta **sao chép** trạng thái $q$ để tạo trạng thái $\textit{clone}$, rồi gán $\operatorname{len}(\textit{clone})=\operatorname{len}(p)+1$. Vì không muốn thay đổi các đường đi đi qua $q$, ta sao chép mọi chuyển trạng thái của $q$ sang $\textit{clone}$. Ta cũng đặt liên kết hậu tố xuất phát từ $\textit{clone}$ tới mục tiêu liên kết hậu tố cũ của $q$, và đặt liên kết hậu tố của $q$ thành $\textit{clone}$.
    
        Sau khi tách trạng thái, ta đặt liên kết hậu tố xuất phát từ $\textit{cur}$ tới $\textit{clone}$.
    
        Bước cuối cùng là nối lại một số chuyển trạng thái vốn trỏ tới $q$ sang $\textit{clone}$. Cần sửa những chuyển trạng thái nào? Chỉ cần nối lại các chuyển trạng thái ứng với các hậu tố của mọi xâu $w+c$, trong đó $w$ là xâu dài nhất ứng với trạng thái $p$. Tức là ta tiếp tục đi theo liên kết hậu tố từ đỉnh $p$ tới trạng thái ảo $-1$, hoặc cho tới khi chuyển trạng thái qua $c$ của trạng thái hiện tại không còn trỏ tới $q$.

<span id="&#x7EBF;&#x6027;&#x65F6;&#x95F4;&#x590D;&#x6742;&#x5EA6;"></span>

### Độ phức tạp thời gian tuyến tính

Ta giả sử kích thước bảng chữ cái là **hằng số**, tức mỗi thao tác tìm chuyển trạng thái theo một ký tự, thêm chuyển trạng thái, và tìm chuyển trạng thái kế tiếp đều có độ phức tạp $O(1)$. Nếu lưu các chuyển trạng thái của mỗi đỉnh bằng một mảng độ dài $\left|\Sigma\right|$ (để truy vấn nhanh chuyển trạng thái có nhãn cho trước) và một danh sách động (để duyệt nhanh mọi chuyển trạng thái khả dụng), đổi bộ nhớ lấy thời gian, thì độ phức tạp thời gian[^time-complexity] của thuật toán là $O(n)$, còn độ phức tạp bộ nhớ là $O(n\left|\Sigma\right|)$.

??? note "Chứng minh"
    Nếu xét từng phần của thuật toán, có ba chỗ mà độ phức tạp thời gian không hiển nhiên là tuyến tính:
    
    -   Thứ nhất là duyệt mọi liên kết hậu tố từ trạng thái $\textit{last}$ để thêm chuyển trạng thái của ký tự $c$.
    -   Thứ hai là quá trình sao chép các chuyển trạng thái khi trạng thái $q$ được sao chép thành trạng thái mới $\textit{clone}$.
    -   Thứ ba là quá trình sửa các chuyển trạng thái trỏ tới $q$ để nối lại chúng sang $\textit{clone}$.
    
    Ta dùng sự thật rằng kích thước của SAM (số trạng thái và số chuyển trạng thái) là **tuyến tính**. Với số trạng thái, chứng minh tuyến tính chính là bản thân thuật toán; với số chuyển trạng thái, chứng minh tuyến tính sẽ được đưa ra sau khi cài đặt thuật toán.
    
    Vì vậy tổng độ phức tạp của **phần thứ nhất và phần thứ hai** rõ ràng là tuyến tính, vì theo trung bình mỗi thao tác chỉ thêm một chuyển trạng thái mới vào automaton.
    
    Còn cần ước lượng tổng độ phức tạp của **phần thứ ba**, nơi ta nối lại các chuyển trạng thái ban đầu trỏ tới $q$ sang $\textit{clone}$. Gọi $v=\operatorname{longest}(p)$; đây là một hậu tố của xâu $s$. Mỗi lần lặp, độ dài của $v$ giảm đi, nên vị trí bắt đầu của $v$ với vai trò hậu tố của $s$ chắc chắn dịch sang phải. Do đó, số lần $p$ di chuyển theo liên kết hậu tố trong vòng lặp không vượt quá quãng đường mà vị trí bắt đầu của $v$ với vai trò hậu tố của $s$ dịch sang phải. Vì $p$ phải di chuyển ít nhất một lần để kết thúc vòng lặp, và $p$ ít nhất là kết quả của một lần đi theo liên kết hậu tố từ $last$, nên khi vòng lặp kết thúc, vị trí bắt đầu của $v$ với vai trò hậu tố của $s$ không nằm trước vị trí bắt đầu của xâu $\operatorname{longest}(\operatorname{link}(\operatorname{link}(\textit{last}))$. Hơn nữa, khi vòng lặp kết thúc, vị trí bắt đầu của xâu $v$ với vai trò hậu tố của $s$ đúng bằng vị trí bắt đầu của $v+c$ với vai trò hậu tố của $s+c$; còn với vai trò hậu tố của $s+c$, xâu $v+c$ đúng là xâu $\operatorname{longest}(\operatorname{link}(\operatorname{link}(\textit{cur}))$. Vì $cur$ là giá trị mới của $last$, số lần di chuyển trong vòng lặp không vượt quá quãng đường vị trí bắt đầu của $\operatorname{longest}(\operatorname{link}(\operatorname{link}(\textit{last}))$ với vai trò hậu tố của xâu hiện tại dịch sang phải trước và sau cập nhật, cộng thêm một (số lần di chuyển bắt buộc để kết thúc vòng lặp).
    
    Vì vị trí của xâu $\operatorname{longest}(\operatorname{link}(\operatorname{link}(\textit{last}))$ với vai trò hậu tố của xâu hiện tại tăng đơn điệu trong toàn bộ quá trình xây SAM[^monotone-loc], tổng quãng đường dịch chuyển của nó chắc chắn không vượt quá $n$. Điều này chứng minh số lần lặp trong vòng lặp sửa các chuyển trạng thái trỏ tới $q$ không vượt quá $2n$. Đó chính là điều cần chứng minh.

Tất nhiên, nếu kích thước bảng chữ cái không phải hằng số, độ phức tạp thời gian của SAM sẽ không còn tuyến tính. Các chuyển trạng thái xuất phát từ một đỉnh cần được lưu trong một cây cân bằng hỗ trợ truy vấn và chèn nhanh. Vì vậy, nếu ký hiệu $\Sigma$ là bảng chữ cái và $\left|\Sigma\right|$ là kích thước bảng chữ cái, thì độ phức tạp thời gian tiệm cận của thuật toán là $O(n\log\left|\Sigma\right|)$, còn độ phức tạp bộ nhớ là $O(n)$.

<span id="&#x5B9E;&#x73B0;"></span>

### Cài đặt

Trước hết, ta cài đặt một cấu trúc dữ liệu lưu toàn bộ thông tin của một chuyển trạng thái. Nếu cần, bạn có thể thêm cờ kết thúc hoặc thông tin khác ở đây. Ta dùng một `map` để lưu danh sách chuyển trạng thái, cho phép xử lý toàn bộ xâu với tổng độ phức tạp bộ nhớ $O(n)$ và độ phức tạp thời gian $O(n\log\left|\Sigma\right|)$. Tất nhiên, khi kích thước bảng chữ cái là hằng số nhỏ $K$ (ví dụ 26), khai báo `next` là `int[K]` sẽ tiện hơn.

```cpp
struct state {
  int len, link;
  std::map<char, int> next;
};
```

Bản thân SAM sẽ được lưu trong một mảng các cấu trúc `state`. Ta ghi lại kích thước hiện tại của automaton trong `sz`, và biến `last`, tức trạng thái ứng với toàn bộ xâu hiện tại.

```cpp
constexpr int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;
```

Ta định nghĩa một hàm khởi tạo SAM, tức tạo một SAM chỉ có trạng thái ban đầu.

```cpp
void sam_init() {
  st[0].len = 0;
  st[0].link = -1;
  sz++;
  last = 0;
}
```

Cuối cùng là cài đặt hàm chính: thêm một ký tự vào cuối xâu hiện tại và xây automaton tương ứng dựa trên automaton trước đó.

???+ note "Cài đặt"
    ```cpp
    void sam_extend(char c) {
      int cur = sz++;
      st[cur].len = st[last].len + 1;
      int p = last;
      while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
      }
      if (p == -1) {
        st[cur].link = 0;
      } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
          st[cur].link = q;
        } else {
          int clone = sz++;
          st[clone].len = st[p].len + 1;
          st[clone].next = st[q].next;
          st[clone].link = st[q].link;
          while (p != -1 && st[p].next[c] == q) {
            st[p].next[c] = clone;
            p = st[p].link;
          }
          st[q].link = st[cur].link = clone;
        }
      }
      last = cur;
    }
    ```

Như đã nói ở trên, nếu dùng bộ nhớ đổi lấy thời gian (độ phức tạp bộ nhớ $O(n\left|\Sigma\right|)$, trong đó $\left|\Sigma\right|$ là kích thước bảng chữ cái), bạn có thể xây SAM trong thời gian $O(n)$[^time-complexity] với bảng chữ cái tùy ý. Nhưng khi đó cần lưu cho mỗi trạng thái một mảng kích thước $\left|\Sigma\right|$ (để nhanh chóng tìm chuyển trạng thái tương ứng theo ký tự) và một danh sách chứa mọi chuyển trạng thái khả dụng (để duyệt nhanh mọi chuyển trạng thái khả dụng).

<span id="&#x66F4;&#x591A;&#x6027;&#x8D28;"></span>

## Các tính chất khác

<span id="&#x72B6;&#x6001;&#x6570;"></span>

### Số trạng thái

Với một xâu $s$ độ dài $n$, số trạng thái trong SAM của nó **không vượt quá** $2n-1$ (giả sử $n\ge 2$).

??? note "Chứng minh"
    Bản thân thuật toán đã chứng minh kết luận này. Ban đầu automaton có một trạng thái; ở lần lặp thứ nhất và thứ hai chỉ tạo một đỉnh; trong $n-2$ bước còn lại, mỗi bước tạo nhiều nhất $2$ trạng thái.
    
    Tuy nhiên, ta cũng có thể **chứng minh** ước lượng này **mà không dựa vào thuật toán**. Nhắc lại rằng số trạng thái bằng số tập $\operatorname{endpos}$ khác nhau. Các tập $\operatorname{endpos}$ này tạo thành một cây (tập $\operatorname{endpos}$ của nút cha chứa tập $\operatorname{endpos}$ của nút con). Xét biến đổi nhẹ cây này: mỗi khi nó có một nút trong chỉ có một nút con (nghĩa là tập của nút con thiếu ít nhất một vị trí trong tập của nút cha), ta tạo một tập chứa các vị trí bị thiếu đó làm nút con của nó. Cuối cùng ta thu được một cây mà mọi nút trong đều có bậc lớn hơn một, và số lá không vượt quá $n$. Một cây như vậy có không quá $2n-1$ nút, do đó số tập $\operatorname{endpos}$ khác nhau ban đầu cũng không vượt quá $2n-1$.
    
    Xâu $\texttt{abbb} \cdots \texttt{bbb}$ đạt tới cận trên này: từ sau lần lặp thứ ba, mỗi lần lặp của thuật toán đều tách một trạng thái, cuối cùng tạo đúng $2n-1$ trạng thái.

<span id="&#x8F6C;&#x79FB;&#x6570;"></span>

### Số chuyển trạng thái

Với một xâu $s$ độ dài $n$, số chuyển trạng thái trong SAM của nó **không vượt quá** $3n-4$ (giả sử $n\ge 3$).

??? note "Chứng minh"
    Trước hết ước lượng số chuyển trạng thái liên tục. Xét cây khung của automaton gồm các đường đi dài nhất từ trạng thái $t_0$ tới mọi trạng thái. Cây khung chỉ chứa các cạnh liên tục, nên số cạnh nhỏ hơn số trạng thái, tức không vượt quá $2n-2$.
    
    Bây giờ ước lượng số chuyển trạng thái không liên tục. Gọi chuyển trạng thái không liên tục hiện tại là $(p,\,q)$, với ký tự $c$. Ta lấy xâu tương ứng của nó là $u+c+w$, trong đó xâu $u$ ứng với đường đi dài nhất từ trạng thái ban đầu tới $p$, còn $w$ ứng với đường đi dài nhất từ $q$ tới một trạng thái kết thúc bất kỳ. Một mặt, các xâu dạng $u+c+w$ ứng với mỗi chuyển trạng thái không đầy đủ là khác nhau (vì $u$ và $w$ chỉ gồm các chuyển trạng thái đầy đủ). Mặt khác, theo định nghĩa trạng thái kết thúc, mọi xâu dạng $u+c+w$ đều là hậu tố của toàn bộ xâu $s$. Vì $s$ chỉ có $n$ hậu tố không rỗng, và các xâu dạng $u+c+w$ không chứa $s$ (vì toàn bộ xâu chỉ chứa các chuyển trạng thái đầy đủ), tổng số chuyển trạng thái không đầy đủ không vượt quá $n-1$.
    
    Cộng hai ước lượng trên, ta được cận trên $3n-3$. Tuy nhiên, số trạng thái lớn nhất chỉ có thể xuất hiện trong những trường hợp giống $\texttt{abbb} \cdots \texttt{bbb}$, mà khi đó số chuyển trạng thái rõ ràng nhỏ hơn $3n-3$.
    
    Do đó ta thu được cận trên chặt hơn cho số chuyển trạng thái của SAM: $3n-4$. Xâu $\texttt{abbb} \cdots \texttt{bbbc}$ đạt tới cận trên này.

<span id="&#x540E;&#x7F00;&#x94FE;&#x63A5;&#x6811;"></span>

### Cây liên kết hậu tố

Dù mục đích xây SAM là để thu được thông tin về trạng thái và chuyển trạng thái của nó, nhưng liên kết hậu tố $\operatorname{link}$ và độ dài xâu con dài nhất $\operatorname{len}$ ứng với trạng thái, được ghi lại trong quá trình xây dựng, thường còn quan trọng hơn các chuyển trạng thái của SAM trong ứng dụng; thậm chí có thể bỏ qua các chuyển trạng thái và dùng riêng chúng.

Trong quá trình xây SAM, cần cập nhật giá trị của trạng thái $\textit{last}$. Nó ứng với xâu trước hoặc sau mỗi lần thêm ký tự, tức mọi tiền tố của toàn bộ xâu $s$. Gọi trạng thái ứng với tiền tố thứ $i$ là $v_i$, ta thu được $n$ trạng thái $v_0,v_1,\cdots,v_{n-1}$. Ngoài ra, quy ước trạng thái ban đầu $t_0$ là $v_{-1}$, ứng với tiền tố rỗng. Tạm gọi các trạng thái này là "nút tiền tố".

Như Bổ đề 4 đã nêu, mọi trạng thái và mọi liên kết hậu tố tạo thành một cây có gốc $t_0$, hướng từ gốc, gọi là **cây liên kết hậu tố** (trong OI còn thường gọi là **cây parent**). Nó ghi lại thông tin về mọi hậu tố của mọi tiền tố của xâu, tức thông tin về toàn bộ xâu con.

Cây liên kết hậu tố có các tính chất sau:

-   Xâu ứng với nút tổ tiên luôn là hậu tố của xâu ứng với nút con cháu.
-   Tập $\operatorname{endpos}$ tại mỗi nút chính là tập các chỉ số $i$ của mọi "nút tiền tố" $v_i$ nằm trong cây con của nó.
-   Tập $\operatorname{endpos}$ của nút tổ tiên trong cây liên kết hậu tố luôn chứa nghiêm ngặt tập $\operatorname{endpos}$ của nút con cháu.
-   Giá trị $\operatorname{len}$ tại mỗi nút chính là độ dài hậu tố chung dài nhất của các tiền tố ứng với mọi "nút tiền tố" $v_i$ trong cây con của nó.
-   Ngoài nút gốc $t_0$, số xâu con phân biệt ứng với mỗi nút bằng giá trị $\operatorname{len}$ của nó trừ đi giá trị $\operatorname{len}$ của nút cha, tức $\operatorname{len}(v)-\operatorname{len}(\operatorname{link}(v))$.

Các tính chất này có rất nhiều ứng dụng. Ví dụ, xâu là hậu tố chung dài nhất của tiền tố thứ $i$ và tiền tố thứ $j$ chính là xâu dài nhất ứng với LCA của $v_i$ và $v_j$.

Cuối cùng, cây liên kết hậu tố xây cho xâu $s$ có cùng cấu trúc với [cây hậu tố](./suffix-tree.md) xây cho xâu đảo $s_R$ của nó. Điều này thường được dùng để xây cây hậu tố ngoại tuyến.

<span id="&#x5E94;&#x7528;"></span>

## Ứng dụng

Bây giờ ta xem một số bài toán có thể giải bằng SAM. Để đơn giản, giả sử kích thước bảng chữ cái $k$ là hằng số. Khi đó có thể coi độ phức tạp của việc thêm một ký tự và duyệt là hằng số.

<span id="&#x68C0;&#x67E5;&#x5B57;&#x7B26;&#x4E32;&#x662F;&#x5426;&#x51FA;&#x73B0;"></span>

### Kiểm tra một xâu có xuất hiện hay không

???+ example "Bài toán"
    Cho một xâu văn bản $T$ và nhiều xâu mẫu $P$. Cần kiểm tra xâu $P$ có xuất hiện trong $T$ như một xâu con hay không.

??? note "Lời giải"
    Ta xây suffix automaton cho xâu văn bản $T$ trong thời gian $O(\left|T\right|)$. Để kiểm tra xâu mẫu $P$ có xuất hiện trong $T$ hay không, ta bắt đầu từ $t_0$ và đi theo các chuyển trạng thái (cạnh) tương ứng với các ký tự của $P$. Nếu tại một điểm nào đó không thể đi tiếp, xâu mẫu $P$ không phải là xâu con của $T$. Nếu xử lý được toàn bộ xâu $P$ theo cách này, thì xâu mẫu đã xuất hiện trong $T$.
    
    Với mỗi xâu $P$, độ phức tạp thời gian của thuật toán là $O(\left|P\right|)$. Ngoài ra, thuật toán này cũng tìm được độ dài tiền tố dài nhất của xâu mẫu $P$ xuất hiện trong xâu văn bản.

<span id="&#x4E0D;&#x540C;&#x5B50;&#x4E32;&#x4E2A;&#x6570;"></span>

### Số xâu con phân biệt

???+ example "Bài toán"
    Cho một xâu $S$, tính số xâu con phân biệt.

??? note "Lời giải 1"
    Xây suffix automaton cho xâu $S$.
    
    Mỗi xâu con của $S$ tương ứng với một số đường đi trong automaton. Vì vậy số xâu con phân biệt bằng số đường đi khác nhau trong automaton có điểm bắt đầu là $t_0$.
    
    Vì SAM là đồ thị có hướng không chu trình, số đường đi khác nhau có thể được tính bằng quy hoạch động. Cụ thể, gọi $d_{v}$ là số đường đi bắt đầu từ trạng thái $v$ (bao gồm cả đường đi độ dài không), ta có công thức truy hồi:
    
    $$
    d_{v}=1+\sum_{w:(v,w,c)\in DAWG}d_{w}
    $$
    
    Tức $d_{v}$ có thể được biểu diễn bằng tổng trên các điểm cuối của mọi chuyển trạng thái từ $v$; bộ ba $(v,w,c)$ trong $DAWG$ biểu diễn một chuyển trạng thái từ $v$ qua $c$ tới $w$ trong suffix automaton.
    
    Vì vậy số xâu con phân biệt là $d_{t_0}-1$ (do cần bỏ xâu rỗng).
    
    Tổng độ phức tạp thời gian là $O(\left|S\right|)$.

??? note "Lời giải 2"
    Một phương pháp khác là dùng thông tin của cây liên kết hậu tố sau khi xây xong suffix automaton. Số xâu con ứng với mỗi nút là $\operatorname{len}(v)-\operatorname{len}(\operatorname{link}(v))$; chỉ cần cộng trên mọi nút của automaton.
    
    Tổng độ phức tạp thời gian vẫn là $O(\left|S\right|)$.

Bài ví dụ: [Mẫu suffix automaton](https://www.luogu.com.cn/problem/P3804), [SDOI2016 Sinh bùa chú](https://loj.ac/problem/2033)

<span id="&#x6240;&#x6709;&#x4E0D;&#x540C;&#x5B50;&#x4E32;&#x7684;&#x603B;&#x957F;&#x5EA6;"></span>

### Tổng độ dài của mọi xâu con phân biệt

???+ example "Bài toán"
    Cho một xâu $S$, tính tổng độ dài của mọi xâu con phân biệt.

??? note "Lời giải 1"
    Cách làm của bài này tương tự bài trước, chỉ khác là bây giờ cần xét quy hoạch động gồm hai phần: số xâu con phân biệt $d_{v}$ và tổng độ dài của chúng $ans_{v}$.
    
    Ở bài trước ta đã giới thiệu cách tính $d_{v}$. Giá trị $ans_{v}$ có thể được tính bằng công thức truy hồi sau:
    
    $$
    ans_{v}=\sum_{w:(v,w,c)\in DAWG}d_{w}+ans_{w}
    $$
    
    Ta lấy đáp án của mỗi đỉnh kề $w$ và cộng thêm $d_{w}$ (vì các xâu con xuất phát từ trạng thái $v$ đều được thêm một ký tự).
    
    Độ phức tạp thời gian của thuật toán vẫn là $O(\left|S\right|)$.

??? note "Lời giải 2"
    Cũng có thể dùng thông tin của cây liên kết hậu tố. Tổng độ dài mọi hậu tố của xâu con dài nhất ứng với mỗi nút là
    
    $$
    \dfrac{\operatorname{len}(v)\times (\operatorname{len}(v)+1)}{2},
    $$
    
    trừ đi giá trị tương ứng của nút $\operatorname{link}$ chính là đóng góp ròng của nút đó; chỉ cần cộng trên mọi nút của automaton.
    
    Tổng độ phức tạp thời gian vẫn là $O(\left|S\right|)$.

<span id="&#x5B57;&#x5178;&#x5E8F;&#x7B2C;-k-&#x5927;&#x5B50;&#x4E32;"></span>

### Xâu con lớn thứ k theo thứ tự từ điển

???+ example "Bài toán"
    Cho một xâu $S$. Có nhiều truy vấn, mỗi truy vấn cho một số $K_i$, yêu cầu tìm xâu con lớn thứ $K_i$ theo thứ tự từ điển trong tất cả xâu con của $S$.

??? note "Lời giải"
    Ý tưởng giải bài này có thể phát triển từ cách giải hai bài trước. Xâu con lớn thứ $k$ theo thứ tự từ điển tương ứng với đường đi lớn thứ $k$ theo thứ tự từ điển trong SAM. Vì vậy, sau khi tính số đường đi của mỗi trạng thái, ta có thể dễ dàng bắt đầu từ gốc của SAM để tìm đường đi lớn thứ $k$.
    
    Độ phức tạp tiền xử lý là $O(\left|S\right|)$, độ phức tạp mỗi truy vấn là $O(\left|ans\right|\cdot\left|\Sigma\right|)$, trong đó $ans$ là đáp án của truy vấn và $\left|\Sigma\right|$ là kích thước bảng chữ cái.

??? info "Ghi chú thêm"
    Dù đây là một bài kinh điển về suffix automaton, thực ra vì bài toán liên quan đến thứ tự từ điển nên dùng mảng hậu tố là thuận tiện nhất.

Bài ví dụ: [SPOJ - SUBLEX](https://www.spoj.com/problems/SUBLEX/), [TJOI2015 String Theory](https://loj.ac/problem/2102)

<span id="&#x6700;&#x5C0F;&#x5FAA;&#x73AF;&#x79FB;&#x4F4D;"></span>

### Phép dịch vòng nhỏ nhất

???+ example "Bài toán"
    Cho một xâu $S$. Tìm phép dịch vòng nhỏ nhất theo thứ tự từ điển.

??? note "Lời giải"
    Dễ thấy xâu $S+S$ chứa mọi phép dịch vòng của xâu $S$ dưới dạng xâu con.
    
    Vì vậy bài toán được rút gọn thành tìm đường đi độ dài $\left|S\right|$ nhỏ nhất trên suffix automaton ứng với $S+S$. Điều này có thể làm bằng cách hiển nhiên: bắt đầu từ trạng thái ban đầu, tham lam đi theo ký tự nhỏ nhất.
    
    Tổng độ phức tạp thời gian là $O(\left|S\right|)$.

<span id="&#x51FA;&#x73B0;&#x6B21;&#x6570;"></span>

### Số lần xuất hiện

???+ example "Bài toán"
    Với một xâu văn bản $T$ cho trước, có nhiều truy vấn; mỗi truy vấn cho một xâu mẫu $P$, cần trả lời xâu mẫu $P$ xuất hiện bao nhiêu lần trong xâu $T$ như một xâu con.

??? note "Lời giải 1"
    Dùng thông tin của cây liên kết hậu tố, thực hiện DFS để tiền xử lý kích thước tập $\operatorname{endpos}$ của mỗi nút.
    
    Kích thước tập ban đầu của mọi "nút tiền tố" là $1$, còn của các nút không phải "nút tiền tố" là $0$. Sau đó, khi truy hồi từ dưới lên theo liên kết hậu tố, kích thước tập của mỗi nút cha được cộng với kích thước tập của tất cả nút con của nó (đừng bỏ sót giá trị ban đầu của chính nút cha). Giá trị thu được tại mỗi nút chính là kích thước tập $\operatorname{endpos}$ của nút đó. Lý do có thể cộng trực tiếp kích thước tập của các nút con khác nhau là cùng một $v_i$ chỉ xuất hiện trong một cây con, nên cộng sẽ không bị trùng.
    
    Khi truy vấn, tìm nút ứng với xâu mẫu $P$ trên automaton. Nếu tồn tại, đáp án là kích thước tập $\operatorname{endpos}$ của nút đó; nếu không tồn tại, đáp án là $0$.
    
    Độ phức tạp tiền xử lý là $O(|T|)$. Độ phức tạp mỗi truy vấn là $O(|P|)$.

??? note "Lời giải 2"
    Xây suffix automaton cho xâu văn bản $T$.
    
    Tiếp theo tiền xử lý: với mỗi trạng thái $v$ trong automaton, tiền xử lý $cnt_{v}$ sao cho nó bằng kích thước tập $\operatorname{endpos}(v)$. Thực ra, mọi xâu con ứng với cùng một trạng thái $v$ xuất hiện trong xâu văn bản $T$ cùng số lần; số lần đó chính là số vị trí trong tập $\operatorname{endpos}$.
    
    Tuy nhiên ta không thể xây tường minh tập $\operatorname{endpos}$, nên chỉ xét kích thước $cnt$ của chúng.
    
    Để tính các giá trị này, ta làm như sau. Với mỗi trạng thái, nếu nó không được tạo bằng cách sao chép (và không phải trạng thái ban đầu $t_0$), ta khởi tạo $cnt$ của nó bằng 1. Sau đó duyệt mọi trạng thái theo thứ tự giảm dần của độ dài $\operatorname{len}$, và cộng giá trị $cnt_{v}$ hiện tại vào trạng thái mà liên kết hậu tố trỏ tới, tức:
    
    $$
    cnt_{\operatorname{link}(v)}+=cnt_{v}
    $$
    
    Làm như vậy, đáp án của mỗi trạng thái đều đúng.
    
    Vì sao đúng? Các trạng thái không được tạo bằng sao chép có đúng $\left|T\right|$ trạng thái, và trạng thái thứ $i$ trong số chúng được tạo khi ta chèn $i$ ký tự đầu. Vì vậy, với mỗi trạng thái như vậy, khi nó được xử lý, ta đang tính số lượng vị trí mà nó ứng với. Do đó ta khởi tạo $cnt$ của các trạng thái này bằng $1$, và khởi tạo $cnt$ của các trạng thái khác bằng $0$.
    
    Tiếp theo, với mỗi $v$, ta thực hiện thao tác: $cnt_{\operatorname{link}(v)}+=cnt_{v}$. Ý nghĩa đằng sau là nếu một xâu $v$ xuất hiện $cnt_{v}$ lần, thì mọi hậu tố của nó cũng kết thúc tại đúng các vị trí đó, tức cũng xuất hiện $cnt_{v}$ lần.
    
    Vì sao quá trình này không đếm lặp (tức đếm một số vị trí hai lần)? Vì ta chỉ thêm các vị trí của một trạng thái vào **một** trạng thái khác, nên một trạng thái không thể trỏ lặp các vị trí của nó tới trạng thái khác theo hai cách khác nhau.
    
    Do đó, ta có thể tính giá trị $cnt$ của mọi trạng thái trong thời gian $O(\left|T\right|)$.
    
    Cuối cùng, để trả lời truy vấn chỉ cần tìm giá trị $cnt_{t}$, trong đó $t$ là trạng thái ứng với xâu mẫu; nếu xâu mẫu không tồn tại thì đáp án là $0$. Độ phức tạp mỗi truy vấn là $O(\left|P\right|)$.

<span id="&#x7B2C;&#x4E00;&#x6B21;&#x51FA;&#x73B0;&#x7684;&#x4F4D;&#x7F6E;"></span>

### Vị trí xuất hiện đầu tiên

???+ example "Bài toán"
    Cho một xâu văn bản $T$ và nhiều truy vấn. Mỗi truy vấn hỏi vị trí xuất hiện đầu tiên của xâu $P$ trong xâu $T$ (vị trí bắt đầu của $P$).

??? note "Lời giải 1"
    Dùng thông tin của cây liên kết hậu tố, thực hiện DFS để tiền xử lý giá trị nhỏ nhất trong tập $\operatorname{endpos}$ của mỗi nút.
    
    Giá trị ban đầu của mọi "nút tiền tố" $v_i$ là $i$, còn của các nút không phải "nút tiền tố" là $\infty$. Sau đó, khi truy hồi từ dưới lên theo liên kết hậu tố, giá trị của mỗi nút cha được so sánh với giá trị của tất cả nút con của nó và lấy nhỏ nhất (đừng bỏ sót giá trị ban đầu của chính nút cha). Giá trị thu được tại mỗi nút chính là giá trị nhỏ nhất trong tập $\operatorname{endpos}$ của nút đó.
    
    Khi truy vấn, tìm nút ứng với xâu mẫu $P$ trên automaton. Nếu tồn tại, đáp án là giá trị của nút đó trừ $|P|-1$; nếu không tồn tại, đáp án không tồn tại.
    
    Độ phức tạp tiền xử lý là $O(|T|)$. Độ phức tạp mỗi truy vấn là $O(|P|)$.

??? note "Lời giải 2"
    Ta xây một suffix automaton. Ta tiền xử lý vị trí $\operatorname{firstpos}$ cho mọi trạng thái trong SAM. Tức là, với mỗi trạng thái $v$, ta muốn tìm vị trí kết thúc của lần xuất hiện đầu tiên của trạng thái này, $\operatorname{firstpos}[v]$. Nói cách khác, trước hết ta muốn tìm phần tử nhỏ nhất trong mỗi tập $\operatorname{endpos}$ (rõ ràng không thể duy trì tường minh mọi tập $\operatorname{endpos}$).
    
    Để duy trì các vị trí $\operatorname{firstpos}$ này, ta mở rộng hàm `sam_extend()`. Khi tạo trạng thái mới $\textit{cur}$, ta đặt:
    
    $$
    \operatorname{firstpos}(\textit{cur})=\operatorname{len}(\textit{cur})-1.
    $$
    
    Khi sao chép đỉnh $q$ sang $\textit{clone}$, ta đặt:
    
    $$
    \operatorname{firstpos}(\textit{clone})=\operatorname{firstpos}(q).
    $$
    
    (Vì lựa chọn duy nhất khác là $\operatorname{firstpos}(\textit{cur})$, rõ ràng quá lớn.)
    
    Khi đó đáp án truy vấn là $\operatorname{firstpos}(t)-\left|P\right|+1$, trong đó $t$ là trạng thái ứng với xâu $P$. Mỗi truy vấn chỉ cần thời gian $O(\left|P\right|)$.

<span id="&#x6240;&#x6709;&#x51FA;&#x73B0;&#x7684;&#x4F4D;&#x7F6E;"></span>

### Mọi vị trí xuất hiện

???+ example "Bài toán"
    Bài toán giống trên, nhưng lần này cần truy vấn mọi vị trí xuất hiện của xâu mẫu $P$ trong xâu văn bản $T$.

??? note "Lời giải 1"
    Sau khi tìm được nút ứng với xâu mẫu $P$, dùng thông tin của cây liên kết hậu tố để duyệt cây con; hễ gặp một nút kết thúc thì xuất ra.
    
    Độ phức tạp mỗi truy vấn là $O(|P|)+O(\textit{answer}(P))$, trong đó $\textit{answer}(P)$ là đáp án của truy vấn này. Tương tự [chứng minh số trạng thái là tuyến tính](#%E7%8A%B6%E6%80%81%E6%95%B0), có thể chỉ ra kích thước cây con của cây liên kết hậu tố không vượt quá hai lần kích thước tập $\operatorname{endpos}$ của nút đó, nên độ phức tạp duyệt cây con là $O(\textit{answer}(P))$.

??? note "Lời giải 2"
    Ta vẫn xây suffix automaton cho xâu văn bản $T$. Tương tự bài trước, ta tính vị trí $\operatorname{firstpos}$ cho mọi trạng thái.
    
    Nếu $t$ là trạng thái ứng với xâu mẫu $P$, rõ ràng $\operatorname{firstpos}(t)$ là một trong các đáp án. Ta đã tìm được trạng thái trong automaton ứng với $P$. Còn cần tìm những vị trí nào khác? Chính là các trạng thái ứng với những xâu có $P$ làm hậu tố. Nói cách khác, ta cần tìm tất cả trạng thái có thể đi tới trạng thái $t$ thông qua các liên kết hậu tố.
    
    Vì vậy để giải bài toán này, ta cần lưu cho mỗi trạng thái danh sách các liên kết hậu tố trỏ vào nó. Đáp án truy vấn sẽ chứa giá trị $\operatorname{firstpos}$ của mọi trạng thái mà ta có thể tìm được từ trạng thái $t$ bằng cách chỉ dùng liên kết hậu tố ngược trong DFS hoặc BFS.
    
    Độ phức tạp tiền xử lý là $O(|T|)$, độ phức tạp mỗi truy vấn là $O(|P|+\textit{answer}(P))$.
    
    Ta sẽ không thăm lặp một trạng thái, vì mỗi trạng thái chỉ có một liên kết hậu tố trỏ tới một trạng thái khác, nên không tồn tại hai đường đi khác nhau trỏ tới cùng một trạng thái.
    
    Ta chỉ cần xét trường hợp hai trạng thái khác nhau có cùng giá trị $\operatorname{firstpos}$. Tình huống này chỉ xảy ra khi một trạng thái được sao chép từ trạng thái kia. Tuy nhiên, điều này không ảnh hưởng tới phân tích độ phức tạp. Tương tự [chứng minh số trạng thái là tuyến tính](#%E7%8A%B6%E6%80%81%E6%95%B0), số trạng thái có hậu tố là $P$ như vậy không vượt quá $2\textit{answer}(P)$.
    
    Ngoài ra, ta có thể loại bỏ vị trí lặp bằng cách không xét giá trị $\operatorname{firstpos}$ của các nút được sao chép. Thực tế, với một trạng thái, nếu có thể đi tới nó qua trạng thái được sao chép thì cũng có thể đi tới nó qua trạng thái gốc. Do đó, nếu ghi cho mỗi trạng thái một cờ `is_clone` biểu diễn trạng thái này có phải được sao chép ra hay không, ta có thể đơn giản bỏ qua các trạng thái được sao chép, chỉ xuất giá trị $firstpos$ của mọi trạng thái còn lại.
    
    Dưới đây là cài đặt phác thảo:
    
    ```cpp
    struct state {
      bool is_clone;
      int first_pos;
      std::vector<int> inv_link;
      // cac bien khac
    };
    
    // sau khi xay SAM
    for (int v = 1; v < sz; v++) st[st[v].link].inv_link.push_back(v);
    
    // xuat moi vi tri xuat hien
    void output_all_occurrences(int v, int P_length) {
      if (!st[v].is_clone) cout << st[v].first_pos - P_length + 1 << endl;
      for (int u : st[v].inv_link) output_all_occurrences(u, P_length);
    }
    ```

<span id="&#x6700;&#x77ED;&#x7684;&#x6CA1;&#x6709;&#x51FA;&#x73B0;&#x7684;&#x5B57;&#x7B26;&#x4E32;"></span>

### Xâu ngắn nhất không xuất hiện

???+ example "Bài toán"
    Cho một xâu $S$ và một bảng chữ cái cụ thể, cần tìm một xâu ngắn nhất không xuất hiện trong $S$.

??? note "Lời giải"
    Ta quy hoạch động trên suffix automaton của xâu $S$.
    
    Giả sử đã xử lý xong một phần của xâu con, hiện đang ở trạng thái $v$. Ta muốn tìm số ký tự tối thiểu cần thêm để gặp một chuyển trạng thái không tồn tại; gọi số này tại nút $v$ là $d_v$.
    
    Tính $d_{v}$ rất đơn giản. Nếu không tồn tại chuyển trạng thái dùng ít nhất một ký tự trong bảng chữ cái, thì $d_{v}=1$. Ngược lại, thêm một ký tự là chưa đủ, ta cần lấy giá trị nhỏ nhất trong mọi chuyển trạng thái:
    
    $$
    d_{v}=1+\min_{w:(v,w,c)\in SAM}d_{w}
    $$
    
    Đáp án của bài toán là $d_{t_0}$; xâu cụ thể có thể được truy vết ngược từ mảng $d$ đã tính.

<span id="&#x4E24;&#x4E2A;&#x5B57;&#x7B26;&#x4E32;&#x7684;&#x6700;&#x957F;&#x516C;&#x5171;&#x5B50;&#x4E32;"></span>

### Xâu con chung dài nhất của hai xâu

???+ example "Bài toán"
    Cho hai xâu $S$ và $T$, tìm xâu con chung dài nhất, tức một xâu $X$ xuất hiện trong cả $S$ và $T$ dưới dạng xâu con.

??? note "Lời giải"
    Ta xây suffix automaton cho xâu $S$.
    
    Bây giờ xử lý xâu $T$. Với mỗi tiền tố, ta tìm hậu tố dài nhất của tiền tố này nằm trong $S$. Nói cách khác, với mỗi vị trí trong xâu $T$, ta muốn tìm độ dài xâu con chung dài nhất của $S$ và $T$ kết thúc tại vị trí này.
    
    Để đạt mục tiêu đó, ta dùng hai biến: **trạng thái hiện tại** $v$ và **độ dài hiện tại** $l$. Hai biến này mô tả phần đang khớp: độ dài của nó và trạng thái tương ứng.
    
    Ban đầu $v=t_0$ và $l=0$, tức phần khớp là xâu rỗng.
    
    Bây giờ mô tả cách thêm một ký tự $T_{i}$ và tính lại đáp án cho nó:
    
    -   Nếu tồn tại chuyển trạng thái từ $v$ qua ký tự $T_{i}$, ta chỉ cần đi theo chuyển trạng thái đó và tăng $l$ thêm một.
    -   Nếu không tồn tại chuyển trạng thái như vậy, ta cần rút ngắn phần khớp hiện tại, nghĩa là đi theo liên kết hậu tố:
    
        $$
        v=\operatorname{link}(v)
        $$
    
        Đồng thời cần rút ngắn độ dài hiện tại. Rõ ràng ta cần gán $l=\operatorname{len}(v)$, vì sau khi đi qua liên kết hậu tố này, trạng thái ta tới ứng với một xâu dài nhất là một xâu con.
    -   Nếu vẫn không có chuyển trạng thái dùng ký tự này, ta tiếp tục lặp việc đi theo liên kết hậu tố và giảm $l$, cho tới khi tìm được một chuyển trạng thái hoặc tới trạng thái ảo $-1$ (nghĩa là ký tự $T_{i}$ hoàn toàn không xuất hiện trong $S$, nên đặt $v=l=0$).
    
    Rõ ràng đáp án của bài toán là giá trị lớn nhất của mọi $l$.
    
    Độ phức tạp thời gian của phần này là $O(\left|T\right|)$, vì mỗi lần di chuyển hoặc làm $l$ tăng thêm một, hoặc đi qua vài liên kết hậu tố và mỗi lần đều làm giá trị $l$ giảm.
    
    Cài đặt:
    
    ```cpp
    string lcs(const string &S, const string &T) {
      sam_init();
      for (int i = 0; i < S.size(); i++) sam_extend(S[i]);
    
      int v = 0, l = 0, best = 0, bestpos = 0;
      for (int i = 0; i < T.size(); i++) {
        while (v && !st[v].next.count(T[i])) {
          v = st[v].link;
          l = st[v].length;
        }
        if (st[v].next.count(T[i])) {
          v = st[v].next[T[i]];
          l++;
        }
        if (l > best) {
          best = l;
          bestpos = i;
        }
      }
      return T.substr(bestpos - best + 1, best);
    }
    ```

Bài ví dụ: [SPOJ Longest Common Substring](https://www.spoj.com/problems/LCS/en/)

<span id="&#x591A;&#x4E2A;&#x5B57;&#x7B26;&#x4E32;&#x95F4;&#x7684;&#x6700;&#x957F;&#x516C;&#x5171;&#x5B50;&#x4E32;"></span>

### Xâu con chung dài nhất giữa nhiều xâu

???+ example "Bài toán"
    Cho $k$ xâu $S_i$. Cần tìm xâu con chung dài nhất của chúng, tức một xâu $X$ xuất hiện trong mọi xâu dưới dạng xâu con.

??? note "Lời giải 1"
    Ta nối tất cả xâu con thành một xâu dài hơn $T$, dùng các ký tự đặc biệt $D_i$ để tách từng xâu (mỗi ký tự ứng với một xâu):
    
    $$
    T=S_1+D_1+S_2+D_2+\cdots+S_k+D_k.
    $$
    
    Sau đó xây suffix automaton cho xâu $T$.
    
    Bây giờ cần tìm trong automaton một xâu tồn tại trong mọi xâu $S_i$; để làm điều này có thể tận dụng các ký tự đặc biệt đã thêm. Nếu $S_j$ chứa một xâu con $X$, thì từ nút $t$ ứng với xâu con $X$, chắc chắn tồn tại một đường đi tới $D_j$ mà không đi qua bất kỳ ký tự đặc biệt nào khác $D_1,\cdots,D_{j-1},D_{j+1},\cdots,D_k$. Với một xâu con chung $X$, điều này phải đúng với mọi ký tự đặc biệt $D_j$.
    
    Vì vậy cần tính khả năng đi tới: với mỗi trạng thái trong automaton và mỗi ký tự $D_i$, có tồn tại một đường đi như vậy hay không. Điều này có thể tính dễ dàng bằng DFS hoặc BFS và quy hoạch động. Sau đó, đáp án của bài toán là xâu con dài nhất $\operatorname{longest}(v)$ trong các trạng thái $v$ có thể đi tới mọi ký tự đặc biệt.

??? note "Lời giải 2"
    Giả sử xâu **ngắn nhất** là $S_1$, xây SAM cho nó. Dùng thuật toán tìm xâu con chung dài nhất của hai xâu để tính độ dài xâu con chung dài nhất giữa từng xâu còn lại và $S_1$. Trong quá trình khớp, mỗi khi thêm một ký tự của xâu $S_j$ cần khớp, ta di chuyển tương ứng trên SAM, nên có thể trực tiếp ghi lại độ dài xâu con dài nhất của $S_j$ mà mỗi trạng thái SAM có thể khớp được **trong quá trình khớp**.
    
    Vì trong quá trình khớp, mỗi lần khớp tới một trạng thái của SAM, ta cũng đồng thời khớp tới mọi nút tổ tiên của nó trên cây liên kết hậu tố, nhưng thông tin độ dài khớp của các nút tổ tiên chưa được cập nhật. Vì vậy, sau khi hoàn tất việc khớp xâu $S_j$, cần cập nhật từ dưới lên theo liên kết hậu tố, đưa thông tin xâu con dài nhất khớp được của nút con lên nút cha. Lúc này cần chú ý độ dài khớp dài nhất ghi ở nút cha không được vượt quá giá trị $\operatorname{len}$ của chính nó. Như vậy ta thu được, với mỗi trạng thái trên SAM của $S_1$, độ dài xâu con dài nhất của $S_j$ mà nó **thực sự có thể khớp được**.
    
    Cuối cùng, chỉ cần khớp lần lượt mọi $S_2,\cdots,S_k$, rồi lấy giá trị nhỏ nhất trên độ dài thực sự khớp được đã ghi ở mỗi trạng thái SAM, ta thu được độ dài xâu con chung dài nhất của $S_2,\cdots,S_k$ mà mỗi trạng thái SAM thực sự có thể khớp được. Sau đó duyệt mọi trạng thái SAM và lấy giá trị lớn nhất, đó chính là độ dài xâu con chung dài nhất của $k$ xâu này.
    
    Độ phức tạp thời gian của thuật toán là $O(\sum_i |S_i|)$. Dù SAM của xâu $S_1$ được duyệt $k$ lần, vì $|S_1|$ là nhỏ nhất nên $k|S_1|\le \sum_i |S_i|$; thành phần chính của độ phức tạp vẫn là quá trình khớp duyệt qua mọi xâu con.

Bài ví dụ: [SPOJ Longest Common Substring II](https://www.spoj.com/problems/LCS2/)

<span id="&#x4E60;&#x9898;"></span>

## Bài tập

-   [Mẫu suffix automaton](https://www.luogu.com.cn/problem/P3804)
-   [SDOI2016 Sinh bùa chú](https://loj.ac/problem/2033)
-   [SPOJ - SUBLEX](https://www.spoj.com/problems/SUBLEX/)
-   [TJOI2015 String Theory](https://loj.ac/problem/2102)
-   [SPOJ Longest Common Substring](https://www.spoj.com/problems/LCS/en/)
-   [SPOJ Longest Common Substring II](https://www.spoj.com/problems/LCS2/)
-   [Codeforces 1037H Security](https://codeforces.com/problemset/problem/1037/H)
-   [Codeforces 666E Forensic Examination](https://codeforces.com/problemset/problem/666/E)
-   [HDU4416 Good Article Good sentence](https://acm.hdu.edu.cn/showproblem.php?pid=4416)
-   [HDU4436 str2int](https://acm.hdu.edu.cn/showproblem.php?pid=4436)
-   [HDU6583 Typewriter](https://acm.hdu.edu.cn/showproblem.php?pid=6583)
-   [Codeforces 235C Cyclical Quest](https://codeforces.com/problemset/problem/235/C)
-   [CTSC2012 Familiar Article](https://www.luogu.com.cn/problem/P4022)
-   [NOI2018 Your Name](https://uoj.ac/problem/395)

<span id="&#x76F8;&#x5173;&#x8D44;&#x6599;"></span>

## Tài liệu liên quan

Trước hết là một số tài liệu ban đầu liên quan đến SAM:

-   A. Blumer, J. Blumer, A. Ehrenfeucht, D. Haussler, R. McConnell. Linear Size Finite Automata for the Set of All Subwords of a Word. An Outline of Results. \[1983]
-   A. Blumer, J. Blumer, A. Ehrenfeucht, D. Haussler. The Smallest Automaton Recognizing the Subwords of a Text. \[1984]
-   Maxime Crochemore. Optimal Factor Transducers. \[1985]
-   Maxime Crochemore. Transducers and Repetitions. \[1986]
-   A. Nerode. Linear automaton transformations. \[1958]

Ngoài ra, trong một số tài nguyên mới hơn và nhiều sách về thuật toán xâu, cũng có thể tìm thấy chủ đề này:

-   Maxime Crochemore, Rytter Wowjcieh. Jewels of Stringology. \[2002]
-   Bill Smyth. Computing Patterns in Strings. \[2003]
-   Bill Smith. Methods and algorithms of calculations on lines. \[2006]

Ngoài ra còn có một số tài liệu khác:

-   "Suffix automaton", Chen Lijie.
-   "Mở rộng suffix automaton trên trie", Liu Yanyi.
-   "Suffix automaton và ứng dụng", Zhang Tianyang.
-   <https://www.cnblogs.com/zinthos/p/3899679.html>
-   <https://codeforces.com/blog/entry/20861>
-   <https://zhuanlan.zhihu.com/p/25948077>

**Trang này chủ yếu được dịch từ bài viết [Суффиксный автомат](http://e-maxx.ru/algo/suffix_automata) và bản dịch tiếng Anh của nó [Suffix Automaton](https://cp-algorithms.com/string/suffix-automaton.html). Trong đó, bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.**

[^state-endpos]: Lý do cần lấy mỗi trạng thái làm một lớp tương đương $\operatorname{endpos}$ thực ra chính là định lý Myhill-Nerode được nhắc tới trong đoạn này. Nói ngắn gọn, nếu hai xâu $t$ và $u$ có tập $\operatorname{endpos}$ khác nhau, thì chúng không thể ứng với cùng một trạng thái của SAM: các đường đi từ cùng một trạng thái tới trạng thái kết thúc luôn giống nhau, nghĩa là cách thêm ký tự vào cuối $t$ và $u$ để đi tới cuối xâu $s$ cũng giống nhau, và điều này lại cho thấy vị trí kết thúc của $t$ và $u$ trong xâu $s$ là giống nhau. Ngược lại, nếu hai xâu $t$ và $u$ có cùng tập $\operatorname{endpos}$, ta có thể cho chúng ứng với cùng một trạng thái của SAM. Việc này khả thi chính là nội dung chứng minh của định lý Nerode, nên không thảo luận thêm ở đây. Nhưng ít nhất từ thảo luận này có thể tin rằng, đặt các xâu có cùng tập $\operatorname{endpos}$ vào cùng một trạng thái sẽ tạo ra SAM nhỏ nhất, vì không thể gộp đỉnh thêm nữa.

[^time-complexity]: Nếu không dùng thêm danh sách để ghi lại các chuyển trạng thái khả dụng của trạng thái hiện tại, mà chỉ dùng mảng để lưu mọi chuyển trạng thái có thể có (dù có tồn tại hay không) và sao chép trực tiếp khi sao chép nút, thì độ phức tạp thời gian cũng là $O(n\left|\Sigma\right|)$.

[^monotone-loc]: Điều phần chính văn chưa giải thích là, trong trường hợp một và hai, vị trí của $\operatorname{longest}(\operatorname{link}(\operatorname{link}(\textit{last})))$ có tăng đơn điệu (không giảm) hay không. Trường hợp một dễ kiểm chứng, vì sau khi cập nhật, $\operatorname{longest}(\operatorname{link}(\operatorname{link}(\textit{last})))$ là xâu rỗng, có vị trí bắt đầu và kết thúc ở cuối xâu $s$. Với trường hợp hai, chuyển trạng thái là liên tục, nghĩa là $\operatorname{longest}(q) = \operatorname{longest}(p)+c$. Tuy nhiên, thêm ký tự mới vào cuối một xâu con chỉ khiến xâu con đó khó xuất hiện hơn; nói cách khác, khi tập vị trí kết thúc của hậu tố độ dài $\operatorname{len}(\operatorname{link}(p))$ của xâu $\operatorname{longest}(p)$ chứa nghiêm ngặt $\operatorname{endpos}(p)$, thì tập vị trí kết thúc của hậu tố độ dài $\operatorname{len}(\operatorname{link}(p))+1$ của xâu $\operatorname{longest}(q)$ vẫn có thể giống $\operatorname{endpos}(q)$. Do đó $\operatorname{len}(\operatorname{link}(q))<\operatorname{len}(\operatorname{link}(p))+1$, tức vị trí bắt đầu của $\operatorname{longest}(\operatorname{link}(p))$ với vai trò hậu tố của $s$ chắc chắn không lớn hơn vị trí bắt đầu của $\operatorname{longest}(\operatorname{link}(q))$ với vai trò hậu tố của $s+c$. Mặt khác, khi tìm được trạng thái $p$ sao cho tồn tại chuyển trạng thái qua $c$, chắc chắn đã di chuyển ít nhất một lần. Điều này cho thấy vị trí bắt đầu của $\operatorname{longest}(\operatorname{link}(p))$ với vai trò hậu tố của $s$ không nhỏ hơn vị trí bắt đầu của $\operatorname{longest}(\operatorname{link}(\operatorname{link}(\textit{last})))$ với vai trò hậu tố của $s$. Cuối cùng, $\operatorname{longest}(\operatorname{link}(q))=\operatorname{longest}(\operatorname{link}(\operatorname{link}(\textit{cur})))$. Điều này chứng minh trong trường hợp hai, vị trí của $\operatorname{longest}(\operatorname{link}(\operatorname{link}(\textit{last})))$ cũng tăng đơn điệu.
