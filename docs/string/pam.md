<span id="định-nghĩa"></span>
## Định nghĩa

Cây hồi văn (EER Tree, Palindromic Tree, còn được gọi là automaton hồi văn) là một cấu trúc dữ liệu hiệu quả có thể lưu trữ mọi xâu con đối xứng trong một xâu. Nó được Mikhail Rubinchik và Arseny M. Shur công bố lần đầu vào năm 2015. Cấu trúc này được gợi cảm hứng từ các cấu trúc dữ liệu hậu tố cho xâu như cây hậu tố; dùng cây hồi văn có thể giải quyết đơn giản và hiệu quả nhiều bài toán liên quan đến xâu đối xứng.

<span id="kết-cấu"></span>
## Kết cấu

Cây hồi văn đại khái có dạng như sau:

![](./images/pam1.png)

Tương tự các automaton khác, cây hồi văn cũng gồm các cạnh chuyển và liên kết hậu tố (con trỏ fail); mỗi nút có thể biểu diễn một xâu con đối xứng.

Vì độ dài xâu đối xứng có thể là lẻ hoặc chẵn, có thể làm giống Manacher: thêm một ký tự không thuộc bảng chữ cái (chẳng hạn `#`) làm dấu phân cách để biến mọi xâu đối xứng thành độ dài lẻ. Tuy nhiên cách này khá rườm rà. Có cách tốt hơn.

Cách tốt hơn là xây hai cây: các nút trên một cây tương ứng với những xâu con đối xứng có độ dài lẻ, còn các nút trên cây kia tương ứng với những xâu con đối xứng có độ dài chẵn.

Giống như các automaton khác, con trỏ fail của một nút trỏ tới nút tương ứng với hậu tố đối xứng dài nhất của xâu đối xứng mà nút đó biểu diễn. Tuy nhiên cạnh chuyển không biểu diễn việc thêm một ký tự vào sau xâu ở nút ban đầu, mà biểu diễn việc thêm cùng một ký tự vào cả đầu và cuối xâu đó (điều này tự nhiên vì cần bảo đảm xâu được lưu là đối xứng).

Còn cần duy trì trên mỗi nút độ dài `len` của xâu con đối xứng tương ứng. Thông tin này giúp việc xây dựng cây hồi văn thuận tiện hơn.

<span id="xây-dựng"></span>
## Xây dựng

Cây hồi văn có hai trạng thái khởi tạo, lần lượt biểu diễn các xâu đối xứng có độ dài $-1,0$. Có thể gọi chúng là gốc lẻ và gốc chẵn. Chúng không biểu diễn xâu thực tế nào, chỉ tồn tại như các trạng thái khởi tạo, tương tự vai trò của nút gốc trong những automaton khác.

Con trỏ fail của gốc chẵn trỏ tới gốc lẻ. Không cần quan tâm con trỏ fail của gốc lẻ, vì gốc lẻ không thể thất bại khi khớp (trạng thái tiếp theo chuyển ra từ gốc lẻ có độ dài $1$, tức là một ký tự đơn, luôn là xâu con đối xứng).

Tương tự automaton hậu tố, xây cây hồi văn theo kiểu tăng dần.

Xét sau khi đã xây xong cây hồi văn cho $p-1$ ký tự đầu, thêm vào automaton ký tự ở vị trí $p$ trong xâu gốc.

Bắt đầu từ nút tương ứng với xâu con đối xứng dài nhất kết thúc tại ký tự trước đó, rồi liên tục đi theo con trỏ fail cho tới khi tìm được một nút thỏa $s_{p}=s_{p-len-1}$, tức là ký tự đứng ngay trước xâu con đối xứng mà nút đó biểu diễn bằng với ký tự cần thêm.

Dưới đây là hình trong bài báo:

![](./images/pam2.png)

Nút tương ứng với `A` được tìm bằng cách nhảy theo con trỏ fail, rồi thêm `X` vào hai bên để thu được xâu đối xứng hiện tại (tức `XAX`). Nút này chính là nút trên cây tương ứng với xâu con đối xứng dài nhất kết thúc tại $p$. Lúc này lợi thế của nút độ dài $-1$ cũng thể hiện rõ: nếu không có `X` nào khác khớp điều kiện, phép so sánh sẽ trở thành $s_p=s_p$ tại cùng một vị trí, nhờ đó tự nhiên thu được nút biểu diễn ký tự `X`. Sau đó cần kiểm tra: nếu chưa có nút này thì phải tạo mới.

Tiếp theo cần tìm con trỏ fail cho nút mới tạo. Cách làm tương tự quá trình trên: bắt đầu từ `A`, liên tục nhảy theo con trỏ fail để tìm hậu tố đối xứng dài nhất `XBX` của `XAX`, rồi đặt nút tương ứng làm đích của con trỏ fail.

Nút này không cần tạo mới. $len_B$ ký tự đầu và $len_B$ ký tự cuối của `A` đều giống nhau và đều là `B`; theo quan hệ đối xứng, hai đầu của $len_B$ ký tự đầu đều là `X`, còn phía sau đã được xác định là `X`, nên nút `XBX` đã được chứa trong cây.

Nếu fail không khớp được, nối nó tới nút có độ dài $0$; điều này hợp lệ, vì đó là hậu tố của mọi nút.

<span id="chứng-minh-số-trạng-thái-tuyến-tính"></span>
## Chứng minh số trạng thái tuyến tính

<span id="định-lý"></span>
### Định lý

Với một xâu $s$, số xâu con đối xứng phân biệt bản chất của nó nhiều nhất chỉ là $|s|$.

<span id="chứng-minh"></span>
### Chứng minh

Xét chứng minh bằng quy nạp toán học.

-   Khi $|s| =1$, $s$ chỉ có một ký tự, đồng thời chỉ có một xâu con, và xâu con đó là đối xứng, nên kết luận đúng.

-   Khi $|s| >1$, đặt $t=sc$, trong đó $t$ là xâu thu được sau khi thêm một ký tự $c$ vào cuối $s$. Giả sử kết luận đúng với xâu $s$. Xét các xâu con đối xứng kết thúc tại ký tự cuối $c$, và giả sử các đầu trái của chúng theo thứ tự tăng dần là $l_1,l_2,\dots,l_k$. Vì $t[l_1..|t|]$ là xâu đối xứng, nên với mọi vị trí $l_1 \le p \le |t|$, có $t[p..|t|]=t[l_1..l_1+|t|-p]$. Do đó, với $1 < i \le k$, $t[l_i..|t|]$ đã xuất hiện trong $t[1..|t|-1]$. Vì vậy, mỗi lần thêm một ký tự, số xâu con đối xứng phân biệt bản chất tăng thêm nhiều nhất $1$.

Theo quy nạp toán học, định lý được chứng minh.

Vì thế số trạng thái của cây hồi văn là $O(|s|)$. Mỗi trạng thái chỉ biểu diễn một xâu con đối xứng phân biệt bản chất; trạng thái chuyển tới nút đó là duy nhất, nên tổng số cạnh chuyển cũng là $O(|s|)$.

<span id="chứng-minh-tính-đúng-đắn"></span>
## Chứng minh tính đúng đắn

Lấy hình trên làm ví dụ: khi thêm ký tự hiện tại `X`, theo chứng minh số trạng thái tuyến tính, chỉ cần tìm hậu tố đối xứng dài nhất chứa ký tự cuối `X`, tức là `XAX`. Sau đó tiếp tục tìm hậu tố đối xứng dài nhất `XBX` của `XAX` và tạo liên kết hậu tố. Trạng thái tương ứng với `XBX` đã xuất hiện trong cây hồi văn. Các hậu tố đối xứng chứa ký tự cuối chính là `XAX`, bản thân `XBX`, và mọi tổ tiên của trạng thái tương ứng trên cây fail.

Với việc xây cây hồi văn của $s$, đặt $n=|s|$. Mọi thao tác ngoài việc nhảy theo con trỏ fail đều là $O(n)$.

Khi thêm ký tự, dựa trên trạng thái ở bước trước, mỗi lần nhảy fail làm độ sâu của nút tương ứng trên cây fail giảm $1$; sau khi nối fail, độ sâu chỉ tăng thêm $1$ (nhưng khi fail là $0$, tức là phải tới $-1$ mới thỏa, độ sâu tương đương tăng thêm $2$ từ nền $-1$).

Vì chỉ thêm $n$ ký tự, độ sâu chỉ tăng $n$ lần, nên tổng số lần nhảy fail nhiều nhất cũng chỉ là $2n$.

Do đó, độ phức tạp thời gian để xây cây hồi văn của $s$ là $O(|s|)$.

<span id="ứng-dụng"></span>
## Ứng dụng

<span id="số-xâu-con-đối-xứng-phân-biệt-bản-chất"></span>
### Số xâu con đối xứng phân biệt bản chất

Từ chứng minh số trạng thái tuyến tính, suy ra số xâu con đối xứng phân biệt bản chất của một xâu bằng số trạng thái của cây hồi văn (loại trừ hai trạng thái gốc lẻ và gốc chẵn).

<span id="số-lần-xuất-hiện-của-xâu-con-đối-xứng"></span>
### Số lần xuất hiện của xâu con đối xứng

Sau khi xây cây hồi văn, dùng cách thống kê số lần xuất hiện tương tự automaton hậu tố.

Vì trong quá trình xây cây hồi văn, các nút được chèn theo thứ tự topo, nên chỉ cần duyệt ngược tất cả trạng thái và cộng số lần xuất hiện của trạng thái hiện tại vào số lần xuất hiện của trạng thái mà con trỏ fail của nó trỏ tới.

Bài ví dụ: [APIO2014 - Palindrome](https://www.luogu.com.cn/problem/P3649)

Định nghĩa giá trị tồn tại của một xâu con của $s$ là số lần xâu con đó xuất hiện trong $s$ nhân với độ dài của xâu con đó. Với xâu $s$ cho trước, tìm giá trị tồn tại lớn nhất trong mọi xâu con đối xứng.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/pam/pam_1.cpp"
    ```

<span id="phân-hoạch-đối-xứng-tối-thiểu"></span>
### Phân hoạch đối xứng tối thiểu

> Cho một xâu $s(1\le |s| \le 10^5)$, tìm $k$ nhỏ nhất sao cho tồn tại $s_1,s_2,\dots,s_k$, trong đó mọi $s_i(1\le i \le k)$ đều là xâu đối xứng, và khi nối $s_1,s_2, \dots ,s_k$ theo thứ tự thu được xâu đúng bằng $s$.

Xét quy hoạch động, gọi $dp[i]$ là số phần ít nhất trong một phân hoạch của tiền tố độ dài $i$ của $s$. Khi chuyển trạng thái, chỉ cần duyệt mọi xâu đối xứng kết thúc tại ký tự thứ $i$:

$$
dp[i]=1+\min_{ s[j+1..i] \text{ là xâu đối xứng} } dp[j]
$$

Vì một xâu có thể có tới $O(n^2)$ xâu con đối xứng, độ phức tạp thời gian của thuật toán trên là $O(n^2)$, không chấp nhận được. Để tối ưu quá trình chuyển trạng thái, dưới đây là một số bổ đề.

Ký hiệu tiền tố độ dài $i$ của xâu $s$ là $pre(s,i)$, và hậu tố độ dài $i$ là $suf(s,i)$.

Chu kỳ: nếu $0< p \le |s|$ và $\forall 1 \le i \le |s|-p,s[i]=s[i+p]$, thì gọi $p$ là một chu kỳ của $s$.

Border: nếu $0 \le r < |s|$ và $pre(s,r)=suf(s,r)$, thì gọi $pre(s,r)$ là một border của $s$.

Quan hệ giữa chu kỳ và border: $t$ là một border của $s$ khi và chỉ khi $|s|-|t|$ là một chu kỳ của $s$.

???+ note "Chứng minh"
    Nếu $t$ là một border của $s$, thì $pre(s,|t|)=suf(s,|t|)$, do đó $\forall 1\le i \le |t|, s[i]=s[|s|-|t|+i]$, nên $|s|-|t|$ là một chu kỳ của $s$.
    
    Nếu $|s|-|t|$ là một chu kỳ của $s$, thì $\forall 1 \le i \le |s|-(|s|-|t|)=|t|,s[i]=s[|s|-|t|+i]$, do đó $pre(s,|t|)=suf(s,|t|)$, nên $t$ là một border của $s$.

<span id="bổ-đề-1"></span>
#### Bổ đề 1

$t$ là hậu tố của xâu đối xứng $s$. Khi đó $t$ là border của $s$ khi và chỉ khi $t$ là xâu đối xứng.

???+ note "Chứng minh"
    Với $1 \le i \le |t|$, vì $s$ và $t$ đều là xâu đối xứng, có $s[i]=s[|s|-i+1]=s[|s|-|t|+i]$, nên $t$ là border của $s$.
    
    Với $1 \le i \le |t|$, vì $t$ là border của $s$, có $s[i]=s[|s|-|t|+i]$; vì $s$ là xâu đối xứng, có $s[i]=s[|s|-i+1]$. Do đó $s[|s|-i+1]=s[|s|-|t|+i]$, nên $t$ là xâu đối xứng.

Trong hình dưới, các vị trí cùng màu biểu thị các ký tự tương ứng bằng nhau.

![](./images/pam3.png)

<span id="bổ-đề-2"></span>
#### Bổ đề 2

$t$ là border của xâu $s$ ($|s|\le 2|t|$). Khi đó $s$ là xâu đối xứng khi và chỉ khi $t$ là xâu đối xứng.

???+ note "Chứng minh"
    Nếu $s$ là xâu đối xứng, theo Bổ đề $1$, $t$ cũng là xâu đối xứng.
    
    Nếu $t$ là xâu đối xứng, vì $t$ là border của $s$, nên $\forall 1 \le i \le |t|, s[i]=s[|s|-|t|+i]=s[|s|-i+1]$. Vì $|s| \le 2|t|$, nên $s$ cũng là xâu đối xứng.

<span id="bổ-đề-3"></span>
#### Bổ đề 3

$t$ là border của xâu đối xứng $s$, nên $|s|-|t|$ là một chu kỳ của $s$. $|s|-|t|$ là chu kỳ nhỏ nhất của $s$ khi và chỉ khi $t$ là hậu tố đối xứng thực sự dài nhất của $s$.

<span id="bổ-đề-4"></span>
#### Bổ đề 4

$x$ là một xâu đối xứng, $y$ là hậu tố đối xứng thực sự dài nhất của $x$, và $z$ là hậu tố đối xứng thực sự dài nhất của $y$. Gọi $u,v$ lần lượt là các xâu thỏa $x=uy,y=vz$, khi đó có ba tính chất sau:

1.  $|u| \ge |v|$;

2.  Nếu $|u| > |v|$, thì $|u| > |z|$;

3.  Nếu $|u| = |v|$, thì $u=v$.

![](./images/pam4.png)

???+ note "Chứng minh"
    1.  Theo hệ quả của Bổ đề $3$, $|u|=|x|-|y|$ là chu kỳ nhỏ nhất của $x$, còn $|v|=|y|-|z|$ là chu kỳ nhỏ nhất của $y$. Xét phản chứng, giả sử $|u| < |v|$. Vì $y$ là hậu tố của $x$, nên $u$ vừa là chu kỳ của $x$ vừa là chu kỳ của $y$, mâu thuẫn với việc $|v|$ là chu kỳ nhỏ nhất của $y$. Do đó $|u| \ge |v|$.
    2.  Vì $y$ là border của $x$, nên $v$ là tiền tố của $x$. Đặt xâu $w$ thỏa $x=vw$ (như hình dưới), trong đó $z$ là border của $w$. Xét phản chứng, giả sử $|u| \le |z|$, khi đó $|zu| \le 2|z|$, nên theo Bổ đề $2$, $w$ là xâu đối xứng. Theo Bổ đề $1$, $w$ là border của $x$; lại vì $|u| > |v|$, nên $|w| > |y|$, mâu thuẫn. Do đó $|u| > |z|$.
    3.  $u,v$ đều là tiền tố của $x$ và $|u|=|v|$, nên $u=v$.
    
    ![](./images/pam5.png)

<span id="hệ-quả"></span>
#### Hệ quả

Sau khi sắp xếp mọi hậu tố đối xứng của $s$ theo độ dài, có thể chia chúng thành $\log |s|$ đoạn cấp số cộng.

???+ note "Chứng minh"
    Giả sử độ dài mọi hậu tố đối xứng của $s$ theo thứ tự tăng dần là $l_1,l_2,\dots,l_k$. Với mọi $2 \le i \le k-1$, nếu $l_{i}-l_{i-1}=l_{i+1}-l_{i}$, thì $l_{i-1},l_{i},l_{i+1}$ tạo thành một cấp số cộng. Ngược lại, nếu $l_{i}-l_{i-1}\neq l_{i+1}-l_{i}$, theo Bổ đề $4$ có $l_{i+1}-l_{i}>l_{i}-l_{i-1}$ và $l_{i+1}-l_{i}>l_{i-1}$, suy ra $l_{i+1}>2l_{i-1}$. Vì vậy, nếu hiệu độ dài của hai cặp hậu tố đối xứng kề nhau thay đổi, thì độ dài lớn nhất đã tăng gấp đôi so với độ dài nhỏ nhất. Việc tăng gấp đôi độ dài chỉ xảy ra nhiều nhất $O(\log |s|)$ lần, tức là các độ dài hậu tố đối xứng của $s$ có thể được chia thành $\log |s|$ đoạn cấp số cộng.

Hệ quả này cũng có thể được chứng minh bằng bổ đề chu kỳ yếu: phân loại mọi border của hậu tố đối xứng dài nhất của $s$ theo độ dài $x$, với $x \in [2^0,2^1),[2^1,2^2),\dots,[2^k,n)$, rồi xét border dài nhất trong mỗi nhóm trong $\log |s|$ nhóm đó. Chứng minh chi tiết có thể tham khảo bài giảng "Chuyên đề thuật toán xâu" của Jin Ce và luận văn đội tuyển ứng viên IOI Trung Quốc năm 2019 của Chen Sunli, "Các thuật toán liên quan tới truy vấn chu kỳ xâu con và ứng dụng".

Sau khi có kết luận này, có thể xét cách tối ưu chuyển trạng thái của $dp$.

<span id="tối-ưu-hóa"></span>
#### Tối ưu hóa

Mỗi nút $u$ trên cây hồi văn cần duy trì thêm hai thông tin, $diff[u]$ và $slink[u]$. $diff[u]$ biểu thị hiệu độ dài giữa xâu đối xứng mà nút $u$ biểu diễn và xâu đối xứng mà $fail[u]$ biểu diễn, tức là $len[u]-len[fail[u]]$. $slink[u]$ biểu thị nút $v$ đầu tiên mà khi đi từ $u$ lên trên theo fail liên tục thì gặp được sao cho $diff[v] \neq diff[u]$; nói cách khác, đó là nút có độ dài nhỏ nhất trong cấp số cộng chứa $u$.

Theo kết luận đã chứng minh ở trên, nếu dùng con trỏ $slink$ để nhảy lên trên, thì mỗi khi thêm một ký tự vào cuối chỉ cần nhảy lên $O(\log |s|)$ lần. Vì vậy, có thể ghi tổng các giá trị $dp$ (trong bài toán gốc là $\min$) của mọi xâu đối xứng được biểu diễn bởi một cấp số cộng vào nút tương ứng với xâu đối xứng dài nhất trong cấp số cộng đó.

$g[v]$ biểu thị tổng các giá trị $dp$ của cấp số cộng chứa $v$, và $v$ là nút có độ dài lớn nhất trong cấp số cộng này. Khi đó $g[v]=\sum_{slink[x]=slink[v]} dp[i-len[x]]$, trong đó $i$ là chỉ số đang được duyệt hiện tại.

Tiếp theo xét cách cập nhật mảng $g$ và mảng $dp$. Lấy hình dưới làm ví dụ, giả sử hiện đang duyệt ký tự thứ $i$ và nút tương ứng trên cây hồi văn là $x$. $g[x]$ là tổng các giá trị $dp$ tại ba vị trí màu cam (xâu đối xứng ngắn nhất $slink[x]$ được tính vào cấp số cộng kế tiếp). Vị trí xuất hiện lần trước của $fail[x]$ là $i-diff[x]$ (kết thúc tại $i-diff[x]$), và các giá trị $dp$ mà $g[fail[x]]$ chứa là các vị trí màu xanh. Vì vậy, $g[x]$ bằng tổng của $g[fail[x]]$ và giá trị $dp$ tại một vị trí mới phát sinh; vị trí mới đó là $i-(len[slink[x]]+diff[x])$. Cuối cùng dùng $g[x]$ để cập nhật $dp[i]$, khi đó phần đóng góp của cấp số cộng này đã được tính xong. Tiếp tục nhảy theo $slink[x]$ và lặp lại quá trình này. Cách cài đặt cụ thể có thể tham khảo mã của bài ví dụ.

![](./images/pam6.png)

Cuối cùng, tính đúng đắn của cách làm trên dựa vào điều sau: nếu $x$ và $fail[x]$ thuộc cùng một cấp số cộng, thì vị trí xuất hiện lần trước của $fail[x]$ là $i-diff[x]$.

???+ note "Chứng minh"
    Theo Bổ đề $1$, $fail[x]$ là border của $x$, do đó nó xuất hiện tại vị trí $i-diff[x]$.
    
    Giả sử $fail[x]$ xuất hiện tại một vị trí $j$ trong $(i-diff[x],i)$. Vì $x$ và $fail[x]$ thuộc cùng một cấp số cộng, nên $2len[fail[x]] \ge len[x]$. Phần $fail[x]$ dư ra và $fail[x]$ tại vị trí $i-diff[x]$ có giao nhau; gọi phần giao là $w$, và đặt xâu $u$ thỏa $uw=fail[x]$. Bằng cách tương tự Bổ đề $1$, có thể chứng minh $w$ là xâu đối xứng, và tiền tố $s[i-len[x]+1..j]=uwu$ của $x$ cũng là xâu đối xứng. Điều này mâu thuẫn với việc $fail[x]$ là tiền tố (hậu tố) đối xứng dài nhất của $x$.

Bài ví dụ: [Codeforces 932G Palindrome Partition](https://codeforces.com/problemset/problem/932/G)

Cho một xâu $s$, yêu cầu chia $s$ thành $t_1, t_2, \dots, t_k$, trong đó $k$ là số chẵn và $t_i=t_{k-i+1}$, tính số cách phân hoạch như vậy.

??? note "Lời giải"
    Xây xâu $t= s[0]s[n - 1]s[1]s[n - 2]s[2]s[n - 3] \dots s[n / 2 - 1]s[n / 2]$. Bài toán tương đương với việc tính số cách phân hoạch $t$ thành các xâu đối xứng chẵn. Chỉ cần đổi công thức chuyển trạng thái ở trên sang dạng tổng và chỉ cập nhật mảng $dp$ tại các vị trí chẵn. Độ phức tạp thời gian $O(n \log n)$, độ phức tạp không gian $O(n)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/pam/pam_2.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

-   [Xâu song đối xứng dài nhất](https://www.luogu.com.cn/problem/P4555)

-   [Luyện tập cổ động viên](https://www.luogu.com.cn/problem/P1659)

-   [SHOI2011 - Hồi văn kép](https://www.luogu.com.cn/problem/P4287)

-   [HDU 5421 Victor và chuỗi](https://acm.hdu.edu.cn/showproblem.php?pid=5421)

-   [CodeChef Tính hồi văn](https://www.codechef.com/LTIME23/problems/PALPROB)

<span id="tài-liệu-liên-quan"></span>
## Tài liệu liên quan

-   [EERTREE: cấu trúc dữ liệu hiệu quả để xử lý hồi văn trong chuỗi](https://arxiv.org/pdf/1506.04862)

-   [Cây hồi văn](http://adilet.org/blog/palindromic-tree/)

-   Tuyển tập luận văn đội tuyển ứng viên IOI Trung Quốc 2017, "Cây hồi văn và ứng dụng", Weng Wentao

-   Tuyển tập luận văn đội tuyển ứng viên IOI Trung Quốc 2019, "Các thuật toán liên quan tới truy vấn chu kỳ xâu con và ứng dụng", Chen Sunli

-   "Chuyên đề thuật toán xâu", Jin Ce

-   [Thêm một chút về hồi văn](https://codeforces.com/blog/entry/19193)

-   [Thuật toán dưới bậc hai cho phân tích hồi văn nhỏ nhất](https://arxiv.org/pdf/1403.2431.pdf)
