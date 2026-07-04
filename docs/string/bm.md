author: minghu6

Kiến thức chuẩn bị: [hàm tiền tố và thuật toán KMP](./kmp.md).

Thuật toán KMP khai thác thông tin khớp tiền tố đến mức tối đa.

Còn ý tưởng cơ bản phía sau thuật toán BM là dùng khớp hậu tố để thu được nhiều thông tin hơn so với khớp tiền tố, từ đó thực hiện các bước nhảy ký tự nhanh hơn.

<span id="&#24341;&#20837;"></span>
## Dẫn nhập

Hãy tưởng tượng xâu mẫu $pat$ được đặt ở đầu bên trái của xâu văn bản $string$, sao cho hai ký tự đầu tiên của chúng thẳng hàng.

$$
\begin{aligned}
\textit{pat}:\qquad\qquad &\texttt{EXAMPLE} \\
\textit{string}:\qquad\quad &\texttt{HERE IS A SIMPLE EXAMPLE} \dots \\
&\qquad\ \ \ \, \, \Uparrow
\end{aligned}
$$

Ta định nghĩa một số ký hiệu ở đây và sẽ không nhắc lại về sau:

Độ dài của $pat$ là $patlen$. Riêng với xâu đánh chỉ số từ 0, quy ước $patlastpos=patlen-1$ là vị trí ký tự cuối cùng của $pat$.

Độ dài của $string$ là $stringlen$, và $stringlastpos = stringlen-1$.

Giả sử ta biết ký tự thứ $patlen$ của $string$ là $char$ (ký tự đang thẳng hàng với ký tự cuối của $pat$), hãy xem ta có thể rút ra thông tin gì:

<span id="&#35266;&#23519;-1"></span>
### Quan sát 1

Nếu biết ký tự $char$ không xuất hiện trong $pat$, ta không cần xét các khả năng $pat$ xuất hiện bắt đầu từ ký tự thứ $1$, thứ $2$, ..., thứ $patlen$ của $string$, mà có thể trượt thẳng $pat$ sang phải $patlen$ ký tự.

<span id="&#35266;&#23519;-2"></span>
### Quan sát 2

Tổng quát hơn, **nếu vị trí xuất hiện ngoài cùng bên phải của ký tự $char$ trong $pat$ cách cuối xâu $delta_1$ ký tự**,

thì có thể bỏ qua việc so khớp và trượt thẳng $pat$ sang phải $delta_1$ ký tự: nếu trượt ít hơn $delta_1$, chỉ riêng ký tự $char$ đã không thể khớp, nên dĩ nhiên xâu mẫu $pat$ cũng không thể khớp.

Do đó, trừ khi ký tự $char$ có thể khớp với ký tự cuối của $pat$, con trỏ trên $string$ cần nhảy qua $delta_1$ ký tự (tương đương với việc $pat$ trượt sang phải $delta_1$ ký tự). Ta có thể thu được hàm $delta_1(char)$ như sau:

$$
\begin{array}{ll}
\textbf{int}\ delta1(\textbf{char}\ char) \\
\qquad \textbf{if}\ \text{char không nằm trong pat || char là ký tự cuối cùng trong pat} \\
\qquad\qquad\textbf{return}\ patlen \\
\qquad \textbf{else} \\
\qquad\qquad\textbf{return}\ patlastpos-i\quad\textbf{//}\ \text{i là vị trí xuất hiện ngoài cùng bên phải của char trong pat, tức pat[i]=char}
\end{array}
$$

Cần chú ý rằng bảng này hiển nhiên chỉ cần được tính đến vị trí $patlastpos-1$.

Bây giờ giả sử $char$ đã khớp với ký tự cuối của $pat$, ta tiếp tục kiểm tra ký tự đứng trước $char$ có khớp với ký tự áp chót của $pat$ hay không:

Nếu có, ta tiếp tục lùi lại cho đến khi toàn bộ xâu mẫu $pat$ được khớp (khi đó ta đã tìm được một lần xuất hiện của $pat$ trong $string$).

Hoặc cũng có thể sau khi đã khớp $m$ ký tự cuối của $pat$, ta gặp bất khớp ở ký tự thứ $m+1$ tính từ cuối. Khi đó ta muốn trượt $pat$ sang phải đến vị trí tiếp theo có thể khớp, và dĩ nhiên càng trượt xa càng tốt.

<span id="&#35266;&#23519;-3(a)"></span>
### Quan sát 3(a)

Trong **Quan sát 2**, khi đã khớp $m$ ký tự cuối của $pat$ rồi bất khớp ở ký tự thứ $m+1$ tính từ cuối, để ký tự bất khớp trong $string$ thẳng hàng với ký tự tương ứng trong $pat$,

cần trượt $pat$ sang phải $k$ ký tự. Nói cách khác, ta nên chú ý đến ký tự sau đó $k+m$ vị trí (tức ký tự ở cuối đoạn của $pat$ sau khi trượt $k$ bước và thẳng hàng với $string$).

Mà $k=delta_1-m$,

nên điểm chú ý của ta trên $string$ cần nhảy sang phải $delta_1-m+m = delta_1$ ký tự.

Tuy vậy, ta còn có cơ hội bỏ qua nhiều ký tự hơn; hãy tiếp tục xét.

<span id="&#35266;&#23519;-3(b)"></span>
### Quan sát 3(b)

Nếu ta biết $m$ ký tự tiếp theo của $string$ khớp với $m$ ký tự cuối của $pat$, gọi xâu con đó là $subpat$,

thì ta còn biết sau ký tự bất khớp $char$ trong $string$ là một xâu con khớp với $subpat$. Nếu phía trước ký tự tương ứng bị bất khớp trong $pat$ cũng có một $subpat$, ta có thể trượt $pat$ sang phải một đoạn,

sao cho $subpat$ xuất hiện phía trước ký tự tương ứng với ký tự bất khớp $char$ trong $pat$ (một lần tái xuất hiện hợp lệ, plausible reoccurrence, sau đây cũng viết tắt là pr) thẳng hàng với $subpat$ trong $string$. Nếu có nhiều $subpat$ trong $pat$, theo thứ tự khớp hậu tố từ phải sang trái, ta lấy lần đầu tiên (rightmost plausible reoccurrence, sau đây cũng viết tắt là rpr).

Giả sử lúc này $pat$ trượt sang phải $k$ ký tự (tức khoảng cách giữa $subpat$ ở cuối $pat$ và lần tái xuất hiện hợp lệ ngoài cùng bên phải của nó). Khi đó điểm chú ý của ta trên $string$ nên trượt sang phải $k+m$ ký tự; khoảng cách này được gọi là $delta_2(j)$:

Giả sử $rpr(j)$ là vị trí tái xuất hiện hợp lệ ngoài cùng bên phải của $subpat=pat[j+1\dots patlastpos]$ khi bất khớp tại $pat[j]$, với $rpr(j) < j$ (đây chỉ là định nghĩa đơn giản; phần thiết kế thuật toán bên dưới sẽ thảo luận chính xác hơn), khi đó rõ ràng $k=j-rpr(j),\ m=patlastpos-j$.

Vì vậy:

$$
\begin{array}{ll}
\textbf{int}\ delta2(\textbf{int}\ j) \quad\textbf{//}\ \text{j là vị trí ký tự trong pat tương ứng với ký tự bất khớp} \\
\qquad\qquad\textbf{return}\ patlastpos-rpr(j) \\
\end{array}
$$

Do đó khi xảy ra bất khớp, ta có thể cho điểm chú ý trên $string$ nhảy sang phải $\max(delta_1,delta_2)$ ký tự.

<span id="&#36807;&#31243;"></span>
## Quy trình

Mũi tên chỉ vào ký tự bất khớp $char$:

$$
\begin{aligned}
\textit{pat}:\qquad\qquad &\texttt{AT-THAT} \\
\textit{string}:\ \ \ \dots\ &\texttt{WHICH-FINALLY-HALTS.--AT-THAT-POINT} \dots \\
&\qquad\ \ \ \, \, \Uparrow
\end{aligned}
$$

$\texttt{F}$ không xuất hiện trong $pat$. Theo **Quan sát 1**, $pat$ được dịch thẳng sang phải $patlen$ ký tự, tức 7 ký tự:

$$
\begin{aligned}
\textit{pat}:\qquad\qquad &\qquad\quad\ \ \, \texttt{AT-THAT} \\
\textit{string}:\ \ \ \dots\ &\texttt{WHICH-FINALLY-HALTS.--AT-THAT-POINT} \dots \\
&\qquad\ \ \ \, \, \qquad\quad\ \ \ \Uparrow
\end{aligned}
$$

Theo **Quan sát 2**, ta cần dịch $pat$ sang phải 4 ký tự để ký tự gạch nối thẳng hàng:

$$
\begin{aligned}
\textit{pat}:\qquad\qquad &\qquad\qquad\quad\ \ \, \texttt{AT-THAT} \\
\textit{string}:\ \ \ \dots\ &\texttt{WHICH-FINALLY-HALTS.--AT-THAT-POINT} \dots \\
&\qquad\ \ \ \; \qquad\qquad\qquad \Uparrow
\end{aligned}
$$

Bây giờ *char*: $\texttt{T}$ đã khớp, ta dịch con trỏ trên $string$ sang trái một bước để tiếp tục so khớp:

$$
\begin{aligned}
\textit{pat}:\qquad\qquad &\qquad\qquad\quad\ \ \, \texttt{AT-THAT} \\
\textit{string}:\ \ \ \dots\ &\texttt{WHICH-FINALLY-HALTS.--AT-THAT-POINT} \dots \\
&\qquad\ \ \ \; \qquad\qquad\quad\ \, \Uparrow
\end{aligned}
$$

Theo **Quan sát 3(a)**, $\texttt{L}$ bất khớp. Vì $\texttt{L}$ không nằm trong $pat$, nên $pat$ dịch sang phải $k=delta_1-m=7-1=6$ ký tự, còn con trỏ trên $string$ dịch sang phải $delta_1=7$ ký tự:

$$
\begin{aligned}
\textit{pat}:\qquad\qquad &\qquad\qquad\qquad\qquad\ \ \,\, \texttt{AT-THAT} \\
\textit{string}:\ \ \ \dots\ &\texttt{WHICH-FINALLY-HALTS.--AT-THAT-POINT} \dots \\
&\qquad\ \ \ \; \qquad\qquad\qquad\qquad\ \ \ \, \, \Uparrow
\end{aligned}
$$

Lúc này $char$ lại khớp với ký tự cuối $\texttt{T}$ của $pat$. Con trỏ trên $string$ khớp sang trái đến $\texttt{A}$, tiếp tục khớp sang trái rồi phát hiện bất khớp tại ký tự $\texttt{-}$:

$$
\begin{aligned}
\textit{pat}:\qquad\qquad &\qquad\qquad\qquad\qquad\ \ \,\, \texttt{AT-THAT} \\
\textit{string}:\ \ \ \dots\ &\texttt{WHICH-FINALLY-HALTS.--AT-THAT-POINT} \dots \\
&\qquad\ \ \ \; \qquad\qquad\qquad\quad\ \ \ \,\, \Uparrow
\end{aligned}
$$

Về trực giác, lúc này theo **Quan sát 3(b)**, ta dịch $pat$ sang phải $k=5$ ký tự để hậu tố $\texttt{AT}$ thẳng hàng. Cách dịch này cho con trỏ $string$ dịch được xa nhất; khi đó $delta_2=k+patlastpos-j=5+6-4=7$, tức con trỏ trên $string$ dịch sang phải 7 ký tự.

Nhìn theo logic hình thức, lúc này $delta_1=7-1-2=4,\ delta_2=7, \max(delta_1,delta_2)= 7$,
điều này cũng ủng hộ bước nhảy theo **Quan sát 3(b)**:

$$
\begin{aligned}
\textit{pat}:\qquad\qquad &\qquad\qquad\qquad\qquad\qquad\quad \;\, \texttt{AT-THAT} \\
\textit{string}:\ \ \ \dots\ &\texttt{WHICH-FINALLY-HALTS.--AT-THAT-POINT} \dots \\
&\qquad\ \ \ \; \qquad\qquad\qquad\qquad\qquad\quad \ \ \; \Uparrow
\end{aligned}
$$

Bây giờ ta thấy mọi ký tự trên $pat$ đều bằng ký tự tương ứng trên $string$, tức đã tìm được một lần khớp của $pat$ trong $string$. Tổng cộng chỉ cần 14 lần truy cập $string$, trong đó 7 lần là các phép so sánh bắt buộc để hoàn thành một lần khớp thành công ($patlen=7$), 7 lần còn lại giúp ta bỏ qua 22 ký tự.

<span id="&#31639;&#27861;&#35774;&#35745;"></span>
## Thiết kế thuật toán

<span id="&#26368;&#21021;&#30340;&#21305;&#37197;&#31639;&#27861;"></span>
### Thuật toán khớp ban đầu

<span id="&#35299;&#37322;"></span>
#### Giải thích

Xét thuật toán khớp xâu sử dụng $delta_1$ và $delta_2$ sau:

$$
\begin{array}{ll}
i \gets patlastpos. \\
j \gets patlastpos. \\
\textbf{loop}\\
\qquad \textbf{if}\ j < 0 \\
\qquad \qquad \textbf{return}\ i+1 \\
\\
\qquad \textbf{if}\ string[i]=pat[j] \\
\qquad \qquad j \gets j-1 \\
\qquad \qquad i \gets i-1 \\
\qquad \qquad \textbf{continue} \\
\\
\qquad i \gets i+max(delta_1(string[i]), delta_2(j)) \\
\\
\qquad \textbf{if}\ i > stringlastpos \\
\qquad \qquad \textbf{return}\ false \\
\qquad j \gets patlastpos \\
\end{array}
$$

Nếu thuật toán trên $\textbf{return}\ false$, điều đó cho biết $pat$ không nằm trong $string$; nếu trả về một số, số đó là vị trí xuất hiện đầu tiên của $pat$ tính từ trái sang trong $string$.

Tiếp theo, ta mô tả kỹ hơn hàm $rpr(j)$ được dùng để tính $delta_2$.

Theo định nghĩa ở trên, $rpr(j)$ biểu thị vị trí tái xuất hiện hợp lệ ngoài cùng bên phải của xâu con $subpat=pat[j+1\dots patlastpos]$ khi bất khớp tại $pat(j)$.

Nói cách khác, cần tìm một $k$ tốt nhất sao cho $pat[k\dots k+patlastpos-j-1]=pat[j+1\dots patlastpos]$. Ngoài ra còn phải xét hai trường hợp đặc biệt:

1.  Khi $k<0$, điều này tương đương với việc thêm một đoạn tiền tố ảo phía trước $pat$, và thực ra vẫn phù hợp với nguyên lý nhảy của $delta_2$.
2.  Khi $k>0$, nếu $pat[k-1]=pat[j]$, thì $pat[k\dots k+patlastpos-j-1]$ này không thể được xem là một lần tái xuất hiện hợp lệ của $subpat$.
    Lý do là bản thân $pat[j]$ là ký tự bất khớp, nên sau khi trượt $pat$ sang phải $k$ ký tự, quá trình khớp hậu tố vẫn sẽ bất khớp tại $pat[k-1]$.

Cũng cần chú ý hai ràng buộc:

1.  $k < j$. Vì khi $k=j$ thì $pat[k]=pat[j]$, ký tự bất khớp tại $pat[j]$ cũng sẽ bất khớp tại $pat[k]$.
2.  Do $delta_2(patlastpos)= 0$, ta quy ước $rpr(patlastpos) = patlastpos$.

<span id="&#36807;&#31243;_1"></span>
#### Quy trình

Vì hiểu $rpr(j)$ là phần cốt lõi để cài đặt thuật toán Boyer-Moore, ta dùng hai ví dụ sau để giải thích chi tiết:

$$
\begin{aligned}
\textit{j}:\qquad\qquad\quad\ \ &\texttt{0 1 2 3 4 5 6 7 8} \\
\textit{pat}:\qquad\qquad\ \  &\texttt{A B C X X X A B C} \\
\textit{rpr(j)}:\qquad\quad\  \  &\texttt{5 4 3 2 1 0 2 1 8} \\
\textit{sgn}:\qquad\qquad\ \   &\texttt{- - - - - - - - +}
\end{aligned}
$$

Với $rpr(0)$, $subpat$ là $\texttt{BCXXXABC}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[0]$ chỉ có thể là $\texttt{[(BCXXX)ABC]XXXABC}$, tức vị trí tái xuất hiện hợp lệ ngoài cùng bên phải là -5, nên $rpr(j)=-5$.

Với $rpr(1)$, $subpat$ là $\texttt{CXXXABC}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[1]$ là $\texttt{[(CXXX)ABC]XXXABC}$, nên $rpr(j)=-4$.

Với $rpr(2)$, $subpat$ là $\texttt{XXXABC}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[2]$ là $\texttt{[(XXX)ABC]XXXABC}$, nên $rpr(j)=-3$.

Với $rpr(3)$, $subpat$ là $\texttt{XXABC}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[3]$ là $\texttt{[(XX)ABC]XXXABC}$, nên $rpr(j)=-2$.

Với $rpr(4)$, $subpat$ là $\texttt{XABC}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[4]$ là $\texttt{[(X)ABC]XXXABC}$, nên $rpr(j)=-1$.

Với $rpr(5)$, $subpat$ là $\texttt{ABC}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[5]$ là $\texttt{[ABC]XXXABC}$, nên $rpr(j)=0$.

Với $rpr(6)$, $subpat$ là $\texttt{BC}$. Do $string[0]=string[6]$, tức $string[0]$ bằng ký tự bất khớp $string[6]$, nên $string[0\dots 2]$ không phải là một lần tái xuất hiện hợp lệ của $subpat$. Vì vậy lần tái xuất hiện hợp lệ ngoài cùng bên phải là $\texttt{[(BC)]ABCXXXABC}$, nên $rpr(j)=-2$.

Với $rpr(7)$, $subpat$ là $\texttt{C}$. Tương tự, do $string[7]=string[1]$, nên $string[1\dots 2]$ không phải là một lần tái xuất hiện hợp lệ của $subpat$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải là $\texttt{[(C)]ABCXXXABC}$, nên $rpr(j)=-1$.

Với $rpr(8)$, theo định nghĩa của $delta_2$, $rpr(patlastpos)=patlastpos$, do đó $rpr(8)=8$.

Bây giờ xét thêm một ví dụ khác:

$$
\begin{aligned}
\textit{j}:\qquad\qquad\quad\ \ &\texttt{0 1 2 3 4 5 6 7 8} \\
\textit{pat}:\qquad\qquad\ \ &\texttt{A B Y X C D E Y X} \\
\textit{rpr(j)}:\qquad\quad\  \  &\texttt{8 7 6 5 4 3 2 1 8} \\
\textit{sgn}:\qquad\qquad\ \   &\texttt{- - - - - - + - +}
\end{aligned}
$$

Với $rpr(0)$, $subpat$ là $\texttt{BYXCDEYX}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[0]$ chỉ có thể là $\texttt{[(BYXCDEYX)]ABYXCDEYX}$, tức vị trí tái xuất hiện hợp lệ ngoài cùng bên phải là -8, nên $rpr(j)=-8$.

Với $rpr(1)$, $subpat$ là $\texttt{YXCDEYX}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[1]$ chỉ có thể là $\texttt{[(YXCDEYX)]ABYXCDEYX}$, nên $rpr(j)=-7$.

Với $rpr(2)$, $subpat$ là $\texttt{XCDEYX}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[2]$ chỉ có thể là $\texttt{[(XCDEYX)]ABYXCDEYX}$, nên $rpr(j)=-6$.

Với $rpr(3)$, $subpat$ là $\texttt{CDEYX}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[3]$ chỉ có thể là $\texttt{[(CDEYX)]ABYXCDEYX}$, nên $rpr(j)=-5$.

Với $rpr(4)$, $subpat$ là $\texttt{DEYX}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[4]$ chỉ có thể là $\texttt{[(DEYX)]ABYXCDEYX}$, nên $rpr(j)=-4$.

Với $rpr(5)$, $subpat$ là $\texttt{EYX}$. Lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[5]$ chỉ có thể là $\texttt{[(EYX)]ABYXCDEYX}$, nên $rpr(j)=-3$.

Với $rpr(6)$, $subpat$ là $\texttt{YX}$. Vì $string[2\dots 3]=string[7\dots 8]$ và $string[6]\neq string[1]$, nên lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[6]$ là $\texttt{AB[YX]CDEYX}$, nên $rpr(j)=2$.

Với $rpr(7)$, $subpat$ là $\texttt{X}$. Mặc dù $string[3]=string[8]$, nhưng vì $string[2] = string[7]$, nên lần tái xuất hiện hợp lệ ngoài cùng bên phải trước $pat[7]$ là $\texttt{[X]ABYXCDEYX}$, nên $rpr(j)=-1$.

Với $rpr(8)$, theo định nghĩa của $delta_2$, $rpr(patlastpos)=patlastpos$, do đó $rpr(8)=8$.

<span id="&#23545;&#21305;&#37197;&#31639;&#27861;&#30340;&#19968;&#20010;&#25913;&#36827;"></span>
### Một cải tiến cho thuật toán khớp

Cuối cùng, trong thực tế người ta nhận thấy khoảng 80% thời gian tìm kiếm được dành cho các bước nhảy của **Quan sát 1**, tức quá trình $string[i]$ không khớp với $pat[patlastpos]$, rồi nhảy cả đoạn $patlen$ để bắt đầu lần khớp tiếp theo.

Vì vậy có thể tối ưu riêng cho trường hợp này:

Ta định nghĩa một $delta0$:

$$
\begin{array}{ll}
\textbf{int}\ delta0(\textbf{char}\ char) \\
\qquad \textbf{if}\ char=pat[patlastpos] \\
\qquad\qquad \textbf{return}\ large\ \ \text{// large là một số nguyên, cần thỏa large>stringlastpos+patlen} \\
\qquad \textbf{return}\ delta1(char)
\end{array}
$$

Thay $delta_1$ bằng $delta0$, ta thu được thuật toán khớp cải tiến:

$$
\begin{array}{ll}
i \gets patlastpos \\
\textbf{loop} \\
\qquad\textbf{if} \ i > stringlastpos \\
\qquad\qquad\textbf{return}\ false\\
\\
\qquad\textbf{while}\ i < stringlen \\
\qquad\qquad i \gets i+delta0(string(i)) \ \ \text{// trừ khi string[i] khớp với ký tự cuối của pat, bước dịch tối đa là patlen}\\\
\qquad\textbf{if}\ i \leqslant\ large \qquad\qquad\qquad\qquad \text{// lúc này không có ký tự nào trên string khớp với ký tự cuối của pat}\ \\
\qquad\qquad\textbf{return}\ false\\
\\
\qquad i \gets i-large \\
\qquad j \gets patlastpos. \\
\qquad\textbf{while}\ j \geqslant\ 0 \ and \  string[i]=pat[j]\\
\qquad \qquad j \gets j-1 \\
\qquad \qquad i \gets i-1 \\
\\
\qquad \textbf{if}\ j < 0 \\
\qquad \qquad \textbf{return}\ i+1 \\
\qquad i \gets i+max(delta_1(string[i]), delta_2(j)) \\
\\
\end{array}
$$

Ở đây $large$ có nhiều vai trò: một mặt nó hỗ trợ bước nhảy ký tự xấu nhanh tương tự thuật toán Horspool sẽ giới thiệu sau, mặt khác nó giúp phát hiện việc tìm kiếm trong xâu đã kết thúc.

Sau cải tiến, so với thuật toán gốc, khi thực hiện bước nhảy của **Quan sát 1** ta không còn phải tính thừa $delta_2$ mỗi lần, nhờ đó hiệu năng tìm kiếm trên các bảng chữ cái thông thường được cải thiện rõ rệt.

<span id="delta2-&#26500;&#24314;&#32454;&#33410;"></span>
## Chi tiết xây dựng delta2

<span id="&#24341;&#20837;_1"></span>
### Dẫn nhập

Trong bài báo của Boyer và Moore[^bm] trên *Communications of the ACM* tháng 10 năm 1977, các tác giả chỉ mô tả bảng tĩnh $delta_2$.

Phần thảo luận về cách cài đặt cụ thể để xây dựng $delta_2$ xuất hiện trong bài báo về thuật toán KMP do Knuth, Morris và Pratt cùng công bố chính thức trên *SIAM Journal on Computing* tháng 6 năm 1977[^kmp].

<span id="&#26420;&#32032;&#31639;&#27861;"></span>
### Thuật toán đơn giản

Trước khi giới thiệu thuật toán xây dựng $delta_2$ của Knuth, theo định nghĩa ta có một thuật toán đơn giản phù hợp với bài toán quy mô nhỏ:

1.  Với mỗi vị trí `i` trong đoạn `[0, patlen)`, xác định khoảng vị trí tái xuất hiện theo độ dài của `subpat`, tức `[-subpatlen, i]`.
2.  So sánh từng ký tự của các vị trí tái xuất hiện khả dĩ theo thứ tự từ phải sang trái, để tìm vị trí tái xuất hiện ngoài cùng bên phải của $subpat$ thỏa yêu cầu của $delta_2$.
3.  Cuối cùng đừng quên đặt $delta_2(lastpos)= 0$.

???+ note "Cài đặt"
    ```Rust
    use std::cmp::PartialEq;
    
    pub fn build_delta_2_table_naive(p: &[impl PartialEq]) -> Vec<usize> {
        let patlen = p.len();
        let lastpos = patlen - 1;
        let mut delta_2 = vec![];
        
        for i in 0..patlen {
            let subpatlen = (lastpos - i) as isize;
            
            if subpatlen == 0 {
                delta_2.push(0);
                break;
            }
            
            for j in (-subpatlen..(i + 1) as isize).rev() {
                // subpat khop
                if (j..j + subpatlen)
                .zip(i + 1..patlen)
                .all(|(rpr_index, subpat_index)| {
                    if rpr_index < 0 {
                        return true;
                    }
                    
                    if p[rpr_index as usize] == p[subpat_index] {
                        return true;
                    }
                    
                    false
                })
                && (j <= 0 || p[(j - 1) as usize] != p[i])
                {
                    delta_2.push((lastpos as isize - j) as usize);
                    break;
                }
            }
        }
        
        delta_2
    }
    ```

Riêng về một số đặc điểm của Rust cần giải thích, các đoạn sau sẽ không nhắc lại:

-   `usize` và `isize` lần lượt là số nguyên không dấu và có dấu có cùng số byte với con trỏ bộ nhớ; trên máy 32 bit chúng tương đương `u32` và `i32`, còn trên máy 64 bit tương đương `u64` và `i64`.
-   Khi đánh chỉ số mảng, vector hoặc slice, ta dùng số kiểu `usize` (vì đây là truy cập ngẫu nhiên trong bộ nhớ và chỉ số không thể âm). Vì vậy nếu cần xử lý giá trị âm thì dùng `isize`, còn khi đánh chỉ số lại phải dùng `usize`; đây là lý do ta thấy từ khóa `as` được dùng để chuyển đổi tường minh giữa hai kiểu.
-   `impl PartialEq` chỉ được dùng như một generic, cho phép hỗ trợ cả `char` theo mã hóa `Unicode` lẫn dữ liệu nhị phân kiểu `u8`.

Rõ ràng thuật toán vét cạn này có độ phức tạp thời gian $O(n^3)$.

<span id="&#39640;&#25928;&#31639;&#27861;"></span>
### Thuật toán hiệu quả

Tiếp theo ta giới thiệu thuật toán hiệu quả có độ phức tạp thời gian $O(n)$, nhưng cần thêm $O(n)$ bộ nhớ.

Dù Knuth đã đưa ra phương pháp xây dựng này vào năm 1977, phiên bản xây dựng gốc của ông có một khiếm khuyết: với một số $pat$, nó thực ra không tạo được $delta_2$ đúng theo định nghĩa.

Rytter đã sửa điểm này trong bài báo đăng trên *SIAM Journal on Computing* năm 1980[^rytter]. Thuật toán xây dựng $delta_2$ như sau:

Trước hết, vì định nghĩa của $delta_2$ tương đối phức tạp, ta phân loại theo vị trí tái xuất hiện của $subpat$ và xử lý từng loại riêng; đây là ý tưởng then chốt để cài đặt hiệu quả.

Sắp xếp các loại theo vị trí tái xuất hiện từ xa đến gần, tức theo độ lệch từ lớn đến nhỏ:

1.  Toàn bộ vị trí tái xuất hiện của $subpat$ nằm hoàn toàn bên trái $pat$, ví dụ $\texttt{[(EYX)]ABYXCDEYX}$. Khi đó $delta_2(j) = patlastpos\times 2 - j$.

2.  Một phần tái xuất hiện của $subpat$ nằm bên trái $pat$, phần còn lại là phần đầu của $pat$, ví dụ $\texttt{[(XX)ABC]XXXABC}$. Khi đó $patlastpos < delta_2(j) < patlastpos\times 2 - j$.
    Ta cũng xếp trường hợp biên khi $subpat$ nằm hoàn toàn ở đầu $pat$ vào nhóm này (tùy cách cài đặt cũng có thể xếp xuống nhóm dưới), ví dụ $\texttt{[ABC]XXXABC}$. Khi đó $patlastpos = delta_2(j)$.

3.  Sự tái xuất hiện của $subpat$ nằm hoàn toàn trong $pat$, ví dụ $\texttt{AB[YX]CDEYX}$. Khi đó $delta_2(j) < patlastpos$.

Bây giờ ta thảo luận cách tính hiệu quả ba trường hợp này:

<span id="&#31532;&#19968;&#31181;&#24773;&#20917;"></span>
#### Trường hợp thứ nhất

Đây là trường hợp đơn giản nhất; chỉ cần duyệt một lần và có thể tiện thể khởi tạo $delta_2$.

<span id="&#31532;&#20108;&#31181;&#24773;&#20917;"></span>
#### Trường hợp thứ hai

Ta quan sát xem khi nào sự tái xuất hiện của $subpat$ có một phần nằm bên trái $pat$ và một phần là đầu $pat$. Điều này xảy ra khi một hậu tố nào đó của $subpat$ bằng một tiền tố nào đó của $pat$.

Ví dụ từ trước:

$$
\begin{aligned}
\textit{j}:\qquad\qquad\quad\ \ &\texttt{0 1 2 3 4 5 6 7 8} \\
\textit{pat}:\qquad\qquad\ \  &\texttt{A B C X X X A B C} \\
\end{aligned}
$$

Lần tái xuất hiện của $delta_2(3)$ là $\texttt{[(XX)ABC]XXXABC}$; trong hậu tố của $subpat$ $\texttt{XXABC}$ và tiền tố của $pat$, phần bằng nhau là $\texttt{ABC}$.

Thực ra, mấu chốt để tính cả trường hợp thứ hai và thứ ba đều là tính và áp dụng hàm tiền tố.

Chỉ cần giá trị $j$ khiến $subpat$ chứa hậu tố bằng nhau này, ta sẽ thu được một lần tái xuất hiện của $subpat$ thuộc trường hợp thứ hai. Với ví dụ trên, chỉ cần $j \leqslant 5$.

Khi $j = 5$, đó chính là trường hợp biên mà $subpat$ nằm hoàn toàn ở đầu $pat$.

Ta có thể tính $delta_2(j)$ lúc này:

Giả sử độ dài của cặp tiền tố - hậu tố bằng nhau này là $\textit{prefixlen}$. Ta có $subpatlen = patlastpos - j$, nên độ dài phần nằm bên trái $pat$ là $subpatlen-\textit{prefixlen}$.

Mà $rpr(j) = -(subpatlen-\textit{prefixlen})$, nên $delta_2(j) = patlastpos - rpr(j) = patlastpos \times 2 - j - \textit{prefixlen}$.

Phía sau nó có thể còn nhiều cặp tiền tố và hậu tố bằng nhau, chẳng hạn:

$$
\begin{aligned}
\textit{j}:\qquad\qquad\quad\ \ &\texttt{0 1 2 3 4 5 6 7 8 9} \\
\textit{pat}:\qquad\qquad\ \  &\texttt{A B A A B A A B A A} \\
\end{aligned}
$$

Tại $j\leq2$ có $\texttt{ABAABAA}$, tại $2< j \leq 5$ có $\texttt{ABAA}$, và tại $5<j\leq8$ có $\texttt{A}$.

Khuyết điểm của thuật toán Knuth là chỉ xét cặp dài nhất. Trên thực tế, ta phải xét mọi trường hợp hậu tố của $subpat$ bằng tiền tố của $pat$, tương đương với việc tính tất cả các hậu tố thực sự bằng tiền tố thực sự của $pat$, rồi tính các giá trị $delta_2(j)$ khác nhau theo các đoạn $j$, theo thứ tự độ dài từ lớn đến nhỏ.

Dùng hàm tiền tố và áp dụng ngược phương trình chuyển trạng thái khi tính hàm tiền tố: $j^{(n)} = \pi[j^{(n-1)}-1]$, ta thu được độ dài của mọi tiền tố thực sự bằng hậu tố thực sự của $pat$. Bắt đầu từ $\pi[patlastpos]$ là cặp dài nhất, sau đó chạy ngược phương trình chuyển trạng thái để lấy độ dài cặp tiền tố - hậu tố bằng nhau dài thứ hai, rồi tiếp tục tương tự.

Như vậy ta hoàn tất việc tính $delta_2$ cho trường hợp thứ hai.

<span id="&#31532;&#19977;&#31181;&#24773;&#20917;"></span>
#### Trường hợp thứ ba

Sự tái xuất hiện của $subpat$ nằm đúng trong $pat$ (không bao gồm phần đầu của $pat$), tức ta tìm $subpat$ trong $pat[0\dots patlastpos-1]$ theo thứ tự từ phải sang trái.

Nếu dùng chính thuật toán BM để giải, ta thu được một cài đặt đệ quy của BM cho trường hợp thứ ba, với điều kiện dừng là $patlen \leqslant  2$.

Hơn nữa, theo định nghĩa của $delta_2$, ký tự tiếp theo (tức ký tự bên trái) của lần tái xuất hiện $subpat$ tìm được không được giống ký tự tiếp theo của $subpat$ khi $subpat$ là hậu tố của $pat$.

Điều này gợi ý rằng ta có thể dùng một quá trình tương tự tính hàm tiền tố để xử lý trường hợp thứ ba, chỉ khác là dùng hàm tiền tố theo chiều ngược trái phải:

-   Hai con trỏ lần lượt chỉ vào đầu trái của xâu con và vị trí "tiền tố" của tiền tố - hậu tố chung dài nhất của xâu con, rồi di chuyển từ phải sang trái. Khi hai ký tự đang chỉ đến bằng nhau, ta tiếp tục di chuyển; lúc này tương đương với việc "tiền tố" dài ra.
-   Khi hai ký tự khác nhau, phần đã bằng nhau trước đó thỏa yêu cầu của $delta_2$ đối với một lần tái xuất hiện. Sau đó lùi con trỏ trỏ vào vị trí "tiền tố" cho đến khi tạo được cặp ký tự bằng nhau mới hoặc đi ra ngoài biên.

Giống hàm tiền tố, ta cần một mảng phụ để lùi trạng thái; có thể dùng lại không gian của mảng tiền tố đã sinh ra khi tính trường hợp thứ hai.

<span id="&#23454;&#29616;"></span>
### Cài đặt

??? note "Cài đặt ở trên"
    ```rust
    use std::cmp::PartialEq;
    use std::cmp::min;
    
    pub fn build_delta_2_table_improved_minghu6(p: &[impl PartialEq]) -> Vec<usize> {
        let patlen = p.len();
        let lastpos = patlen - 1;
        let mut delta_2 = Vec::with_capacity(patlen);
        
        // Truong hop thu nhat
        // delta_2[j] = lastpos * 2 - j
        for i in 0..patlen {
            delta_2.push(lastpos * 2 - i);
        }
        
        // Truong hop thu hai
        // lastpos <= delata2[j] = lastpos * 2 - j
        let pi = compute_pi(p);  // Tinh ham tien to
        let mut i = lastpos;
        let mut last_i = lastpos; // Chi de khoi tao
        while pi[i] > 0 {
            let start;
            let end;
            
            if i == lastpos {
                start = 0;
            } else {
                start = patlen - pi[last_i];
            }
            
            end = patlen - pi[i];
            
            for j in start..end {
                delta_2[j] = lastpos * 2 - j - pi[i];
            }
            
            last_i = i;
            i = pi[i] - 1;
        }
        
        // Truong hop thu ba
        // delata2[j] < lastpos
        let mut j = lastpos;
        let mut t = patlen;
        let mut f = pi;
        loop {
            f[j] = t;
            while t < patlen && p[j] != p[t] {
                // Dung ham min de viec lui trang thai ve sau khong ghi de du lieu phia truoc
                delta_2[t] = min(delta_2[t], lastpos - 1 - j);
                t = f[t];
            }
            
            t -= 1;
            if j == 0 {
                break;
            }
            j -= 1;
        }
        
        // Khong co y nghia thuc te, chi de dinh nghia day du
        delta_2[lastpos] = 0;
        
        delta_2
    }
    ```

<span id="Galil-&#35268;&#21017;&#23545;&#22810;&#27425;&#21305;&#37197;&#26102;&#26368;&#22351;&#24773;&#20917;&#30340;&#25913;&#21892;"></span>
## Quy tắc Galil cải thiện trường hợp xấu nhất khi khớp nhiều lần

<span id="&#20851;&#20110;&#21518;&#32512;&#21305;&#37197;&#31639;&#27861;&#30340;&#22810;&#27425;&#21305;&#37197;&#38382;&#39064;"></span>
### Vấn đề khớp nhiều lần của thuật toán khớp hậu tố

Các thuật toán tìm kiếm trước đó chỉ xét việc tìm lần khớp đầu tiên của $pat$ trong $string$. Còn với bài toán tìm mọi lần khớp của $pat$ trong $string$, có nhiều hướng thuật toán khác nhau. Trọng tâm của vấn đề là: làm sao tận dụng thông tin về các ký tự đã khớp trước đó để giảm độ phức tạp thời gian trong trường hợp xấu nhất xuống tuyến tính.

Sau một lần khớp thành công trong thuật toán gốc, nếu chỉ đơn giản dịch con trỏ của $string$ sang phải $patlen$ rồi bắt đầu lại việc khớp hậu tố, trường hợp xấu nhất sẽ quay về độ phức tạp $O(mn)$ (theo quy ước, $m$ là $patlen$, $n$ là $stringlen$, sau đây cũng vậy).

Ví dụ cực đoan: $pat$: $\texttt{AAA}$, $string$: $\texttt{AAAAA}\dots$.

Để xử lý điều này, Knuth từng đề xuất dùng một tập trạng thái "hữu hạn" để ghi lại các ký tự có độ dài $patlen$. Thuật toán này bảo đảm mỗi ký tự trên $string$ được so sánh nhiều nhất một lần, nhưng cái giá là tập trạng thái "hữu hạn" ấy có thể không nhỏ; với một $pat$ mà các ký tự đôi một khác nhau, cần $\dfrac{1}{2}m^{2}+m$ trạng thái.

Dưới đây là ý tưởng Galil[^galil-rule], đơn giản hơn và không cần thêm chi phí tiền xử lý.

<span id="Galil-&#35268;&#21017;"></span>
### Quy tắc Galil

Giả sử $pat$ là tiền tố của xâu được tạo bằng cách lặp một xâu con $U$ n lần, tức $UUUU\dots$. Khi đó ta gọi $U$ là một chu kỳ của $pat$.

Ví dụ, $pat: \texttt{ABCABCAB}$ là tiền tố của $\texttt{ABCABCABC}$, tức $\texttt{ABC}$ lặp lại; do đó độ dài $3$ của $\texttt{ABC}$ là độ dài chu kỳ của $pat$, hay $pat$ thỏa $pat[i] = pat[i+3]$.

$pat$ ít nhất có một chu kỳ với độ dài bằng chính nó. Ta quy ước chu kỳ ngắn nhất có độ dài $k$, với $k\leq patlen$.

Trong quá trình tìm kiếm, nếu $pat$ đã hoàn tất một lần khớp thành công, thì theo tính chất chu kỳ, thực ra chỉ cần dịch $string$ sang phải $k$ ký tự và so sánh xem $k$ ký tự đó có tương ứng bằng nhau hay không là có thể trực tiếp xác định có thêm một lần khớp của $pat$ hay không.

Để tính độ dài chu kỳ ngắn nhất này, giả sử ta biết một cặp tiền tố - hậu tố bằng nhau của $pat$, có độ dài $\textit{prefixlen}$. Khi đó $pat[i] = pat[i+(patlen-\textit{prefixlen})]$, nên thu được một chu kỳ có độ dài $patlen-\textit{prefixlen}$.

Khi biết cặp tiền tố - hậu tố bằng nhau dài nhất của $pat$, ta thu được chu kỳ ngắn nhất của $pat$.

Độ dài tiền tố - hậu tố bằng nhau dài nhất, $\pi[patlastpos]$, đã được tính trong quá trình xây dựng $delta_2$, nên thực tế không cần thêm thời gian hay bộ nhớ tiền xử lý để cải thiện độ phức tạp thời gian trong trường hợp xấu nhất của thuật toán khớp hậu tố thành tuyến tính.

??? note "Cài đặt cuối cùng của thuật toán tìm kiếm BM kết hợp các tối ưu ở trên"
    ```rust
    #[cfg(target_pointer_width = "64")]
    const LARGE: usize = 10_000_000_000_000_000_000;
    
    #[cfg(not(target_pointer_width = "64"))]
    const LARGE: usize = 2_000_000_000;
    
    pub struct BMPattern<'a> {
        pat_bytes: &'a [u8],
        delta_1: [usize; 256],
        delta_2: Vec<usize>,
        k: usize  // Do dai chu ky ngan nhat cua pat
    }
    
    impl<'a> BMPattern<'a> {
        // ...
        
        pub fn find_all(&self, string: &str) -> Vec<usize> {
            let mut result = vec![];
            let string_bytes = string.as_bytes();
            let stringlen = string_bytes.len();
            let patlen = self.pat_bytes.len();
            let pat_last_pos = patlen - 1;
            let mut string_index = pat_last_pos;
            let mut pat_index;
            let l0 =  patlen - self.k;
            let mut l = 0;
            
            while string_index < stringlen {
                let old_string_index = string_index;
                
                while string_index < stringlen {
                    string_index += self.delta0(string_bytes[string_index]);
                }
                if string_index < LARGE {
                    break;
                }
                
                string_index -= LARGE;
                
                // Neu string_index di chuyen, nghia la sau lan khop thanh cong truoc do
                // da co it nhat mot lan khop that bai.
                // Luc nay can dua do lech khop lan hai cua quy tac Galil ve 0.
                if old_string_index < string_index {
                    l = 0;
                }
                
                pat_index = pat_last_pos;
                
                while pat_index > l && string_bytes[string_index] == self.pat_bytes[pat_index] {
                    string_index -= 1;
                    pat_index -= 1;
                }
                
                if pat_index == l && string_bytes[string_index] == self.pat_bytes[pat_index] {
                    result.push(string_index - l);
                    
                    string_index += pat_last_pos - l + self.k;
                    l = l0;
                } else {
                    l = 0;
                    string_index += max(
                        self.delta_1[string_bytes[string_index] as usize],
                        self.delta_2[pat_index],
                    );
                }
            }
            
            result
        }
    }
    ```

<span id="&#26368;&#22351;&#24773;&#20917;&#22312;&#23454;&#36341;&#20013;&#24615;&#33021;&#24433;&#21709;"></span>
### Ảnh hưởng của trường hợp xấu nhất trong thực tế

Từ góc độ thực tế, trường hợp xấu nhất trên lý thuyết không dễ ảnh hưởng đến hiệu năng. Ngay cả khi kiểm thử trên văn bản ngẫu nhiên với bảng chữ cái rất nhỏ chỉ có 4 ký tự, ảnh hưởng của trường hợp xấu nhất này cũng nhỏ đến mức khó quan sát.

Vì vậy nếu không được thiết kế tốt, việc dùng quy tắc Galil có thể làm giảm nhẹ hiệu năng trung bình. Nhưng với một số $pat$ và $string$ cực kỳ đặc biệt, chẳng hạn ví dụ $pat$: $\texttt{AAA}$, $string$: $\texttt{AAAAA}\dots$, việc áp dụng quy tắc Galil thật sự có thể cải thiện hiệu năng lên nhiều lần.

<span id="&#25913;&#36827;&#31639;&#27861;"></span>
## Các thuật toán cải tiến

<span id="Simplified-Boyer–Moore-&#31639;&#27861;"></span>
### Thuật toán Boyer-Moore đơn giản hóa

Phần phức tạp nhất của thuật toán BM là xây dựng bảng $delta_2$ (tức bảng hậu tố tốt). Trong thực tế, người ta nhận thấy hiệu năng khớp trên các bảng chữ cái thông thường chủ yếu dựa vào bảng $delta_1$ (tức bảng ký tự xấu), nên xuất hiện phiên bản BM đơn giản hóa chỉ dùng bảng $delta_1$. Hiệu năng của phiên bản này thường không chênh lệch nhiều so với bản gốc.

<span id="Boyer–Moore–Horspol-&#31639;&#27861;"></span>
### Thuật toán Boyer-Moore-Horspool

Thuật toán Horspool cũng dựa trên quy tắc ký tự xấu, áp dụng $delta_1$ lên ký tự thẳng hàng với cuối $pat$. Hiệu quả của nó tương tự cải tiến cho thuật toán khớp gốc và thường tốt hơn phiên bản gốc.

???+ note "Cài đặt"
    ```rust
    pub struct HorspoolPattern<'a> {
        pat_bytes: &'a [u8],
        bm_bc: [usize; 256],
    }
    
    impl<'a> HorspoolPattern<'a> {
        // ...
        pub fn find_all(&self, string: &str) -> Vec<usize> {
            let mut result = vec![];
            let string_bytes = string.as_bytes();
            let stringlen = string_bytes.len();
            let pat_last_pos = self.pat_bytes.len() - 1;
            let mut string_index = pat_last_pos;
            
            while string_index < stringlen {
                if &string_bytes[string_index-pat_last_pos..string_index+1] == self.pat_bytes {
                    result.push(string_index-pat_last_pos);
                }
                
                string_index += self.bm_bc[string_bytes[string_index] as usize];
            }
            
            result
        }
    }
    ```

<span id="Boyer–Moore–Sunday-&#31639;&#27861;"></span>
### Thuật toán Boyer-Moore-Sunday

Thuật toán Sunday cũng sử dụng quy tắc ký tự xấu, nhưng tiến thêm một bước so với Horspool: nó trực tiếp xét ký tự nằm ngay sau ký tự đang thẳng hàng với cuối $pat$.

Để cài đặt, chỉ cần sửa nhẹ bảng $delta_1$, tương đương xây dựng trên $pat$ có độ dài $patlen+1$.

Thuật toán Sunday thường được dùng như một thuật toán thực dụng có cài đặt đơn giản nhất và hiệu năng trung bình thuộc nhóm tốt nhất trong trường hợp thông thường; hiệu năng thường nhỉnh hơn Horspool và BM một chút.

???+ note "Cài đặt"
    ```rust
    pub struct SundayPattern<'a> {
        pat_bytes: &'a [u8],
        sunday_bc: [usize; 256],
    }
    
    impl<'a> SundayPattern<'a> {
        // ...
        fn build_sunday_bc(p: &'a [u8]) -> [usize; 256] {
            let mut sunday_bc_table = [p.len() + 1; 256];
            
            for i in 0..p.len() {
                sunday_bc_table[p[i] as usize] = p.len() - i;
            }
            
            sunday_bc_table
        }
        
        pub fn find_all(&self, string: &str) -> Vec<usize> {
            let mut result = vec![];
            let string_bytes = string.as_bytes();
            let pat_last_pos = self.pat_bytes.len() - 1;
            let stringlen = string_bytes.len();
            let mut string_index = pat_last_pos;
            
            while string_index < stringlen {
                if &string_bytes[string_index - pat_last_pos..string_index+1] == self.pat_bytes {
                    result.push(string_index - pat_last_pos);
                }
                
                if string_index + 1 == stringlen {
                    break;
                }
                
                string_index += self.sunday_bc[string_bytes[string_index + 1] as usize];
            }
            
            result
        }
    }
    ```

<span id="BMHBNFS-&#31639;&#27861;"></span>
### Thuật toán BMHBNFS

Thuật toán này kết hợp Horspool và Sunday. Đây là thuật toán `find` được CPython dùng khi cài đặt module `stringlib`[^b5s], sau đây gọi tắt là B5S.

Ý tưởng cơ bản của B5S là:

1.  Theo cách khớp hậu tố, trước hết so sánh hai ký tự tương ứng ở vị trí $patlastpos$. Nếu bằng nhau, tiếp tục so sánh các vị trí tương ứng $0\dots patlastpos-1$. Nếu vẫn bằng nhau, ta tìm được một lần khớp.

2.  Nếu bất kỳ giai đoạn nào xảy ra bất khớp, chuyển sang giai đoạn nhảy.

3.  Trong giai đoạn nhảy, trước hết quan sát ký tự ngay sau vị trí $patlastpos$ có nằm trong $pat$ hay không. Nếu không, trượt thẳng sang phải $patlen+1$, đây là cách tận dụng tối đa thuật toán Sunday.

    Nếu ký tự này nằm trong $pat$, dùng $delta_1$ tại ký tự ở vị trí $patlastpos$ để thực hiện bước nhảy Horspool.

Tùy mục tiêu ưu tiên là tiết kiệm thời gian hay tiết kiệm bộ nhớ, thuật toán sẽ có các cách cài đặt rất khác nhau.

<span id="&#26102;&#38388;&#33410;&#30465;&#29256;&#26412;"></span>
#### Phiên bản tiết kiệm thời gian

???+ note "Cài đặt"
    ```rust
    pub struct B5STimePattern<'a> {
        pat_bytes: &'a [u8],
        alphabet: [bool;256],
        bm_bc: [usize;256],
        k: usize
    }
    
    impl<'a> B5STimePattern<'a> {
        pub fn new(pat: &'a str) -> Self {
            assert_ne!(pat.len(), 0);
            
            let pat_bytes = pat.as_bytes();
            let (alphabet, bm_bc, k) = B5STimePattern::build(pat_bytes);
            
            B5STimePattern { pat_bytes, alphabet, bm_bc, k }
        }
        
        fn build(p: &'a [u8]) -> ([bool;256], [usize;256], usize)  {
            let mut alphabet = [false;256];
            let mut bm_bc = [p.len(); 256];
            let lastpos = p.len() - 1;
            
            for i in 0..lastpos {
                alphabet[p[i] as usize] = true;
                bm_bc[p[i] as usize] = lastpos - i;
            }
            
            alphabet[p[lastpos] as usize] = true;
            
            (alphabet, bm_bc, compute_k(p))
        }
        
        pub fn find_all(&self, string: &str) -> Vec<usize> {
            let mut result = vec![];
            let string_bytes = string.as_bytes();
            let pat_last_pos = self.pat_bytes.len() - 1;
            let patlen = self.pat_bytes.len();
            let stringlen = string_bytes.len();
            let mut string_index = pat_last_pos;
            let mut offset = pat_last_pos;
            let offset0 = self.k - 1;
            
            while string_index < stringlen {
                if string_bytes[string_index] == self.pat_bytes[pat_last_pos] {
                    if &string_bytes[string_index-offset..string_index] == &self.pat_bytes[pat_last_pos-offset..pat_last_pos] {
                        result.push(string_index-pat_last_pos);
                        
                        offset = offset0;
                        
                        // Galil rule
                        string_index += self.k;
                        continue;
                    }
                }
                
                if string_index + 1 == stringlen {
                    break;
                }
                
                offset = pat_last_pos;
                
                if !self.alphabet[string_bytes[string_index+1] as usize] {
                    string_index += patlen + 1;  // sunday
                } else {
                    string_index += self.bm_bc[string_bytes[string_index] as usize];  // horspool
                }
            }
            
            result
        }
    }
    ```

Phiên bản B5S này có hiệu năng rất lý tưởng; trong loạt thuật toán khớp hậu tố đang được giới thiệu, nó thường là phiên bản nhanh nhất trong các trường hợp thông thường.

<span id="&#31354;&#38388;&#33410;&#30465;&#29256;&#26412;"></span>
#### Phiên bản tiết kiệm bộ nhớ

Phiên bản này cũng được cài đặt trong `stringlib` của CPython. Nó dùng hai số nguyên để xấp xỉ vai trò của bảng ký tự và $delta_1$, nhờ đó tiết kiệm bộ nhớ đáng kể:

1.  Dùng một Bloom filter đơn giản để thay thế bảng ký tự (alphabet).

    ???+ note "Cài đặt"
        ```rust
        pub struct BytesBloomFilter {
            mask: u64,
        }
        
        impl BytesBloomFilter {
            pub fn new() -> Self {
                SimpleBloomFilter {
                    mask: 0,
                }
            }
            
            fn insert(&mut self, byte: &u8) {
                (self.mask) |= 1u64 << (byte & 63);
            }
            
            fn contains(&self, char: &u8) -> bool {
                (self.mask & (1u64 << (byte & 63))) != 0
            }
        }
        ```

    Thiết kế Bloom filter đánh đổi độ chính xác (thực tế cả thời gian chạy) để tiết kiệm đáng kể không gian lưu trữ cho cấu trúc dữ liệu kiểu `Set`. Đặc điểm của nó là có thể phán đoán nhầm một phần tử không thuộc tập thành thuộc tập (False Positives, viết tắt FP), nhưng không phán đoán nhầm một phần tử thuộc tập thành không thuộc tập (False Negatives, viết tắt FN). Vì vậy khi dùng nó, FP có thể khiến ta không đạt được bước nhảy ký tự lớn nhất, nhưng FN sẽ không làm ta bỏ qua ký tự đáng lẽ phải khớp.

    Về mặt lý thuyết, với cài đặt "Bloom filter" ở trên, khi độ dài $pat$ là 50 byte, xác suất FP khoảng 0.5; khi độ dài $pat$ là 10 byte, xác suất FP khoảng 0.15.

    Tuy nhiên đây không phải một Bloom filter chuẩn. Trước hết, nó không dùng một hàm băm thật sự; thực chất nó chỉ là một phép ánh xạ ký tự, ánh xạ byte 0-255 thành số được tạo từ sáu bit thấp của byte đó.

    Nhưng xét đến việc ta đang tìm kiếm ký tự trong bộ nhớ, sự đơn giản hóa này rất quan trọng. Ngay cả khi dùng thuật toán băm phi mật mã nhanh nhất hiện biết là [xxHash](https://cyan4973.github.io/xxHash/), thời gian tính toán cần thiết vẫn cao hơn nó một bậc độ lớn.

    Ngoài ra, khi $pat$ ngắn hơn 30 byte, để đạt xác suất FP tốt nhất, cần nhiều hơn một hàm băm. Nhưng làm vậy không mấy ý nghĩa, vì chỉ cần một mảng chứa hai số `u128` là đã có thể xây dựng bảng ký tự cho toàn bộ bảng chữ cái.

2.  Dùng $delta_1(pat[patlastpos])$ thay cho toàn bộ $delta_1$.

    Quan sát $delta_1$, ta thấy vị trí được dùng thường xuyên nhất là trường hợp bất khớp phổ biến nhất: ký tự đầu tiên trong khớp hậu tố đã không khớp. Vì vậy đặt `skip = delta1(pat[patlastpos])`.

    Khi bất khớp ở giai đoạn đầu, dịch thẳng sang phải `skip` ký tự; nhưng khi bất khớp ở giai đoạn thứ hai, vì thiếu thông tin của toàn bộ $delta_1$, ta chỉ có thể dịch sang phải một ký tự.

    ???+ note "Cài đặt"
        ```rust
        pub struct B5SSpacePattern<'a> {
            pat_bytes: &'a [u8],
            alphabet: BytesBloomFilter,
            skip: usize,
        }
        
        impl<'a> B5SSpacePattern<'a> {
            pub fn new(pat: &'a str) -> Self {
                assert_ne!(pat.len(), 0);
                
                let pat_bytes = pat.as_bytes();
                let (alphabet, skip) = B5SSpacePattern::build(pat_bytes);
                
                B5SSpacePattern { pat_bytes, alphabet, skip}
            }
            
            fn build(p: &'a [u8]) -> (BytesBloomFilter, usize)  {
                let mut alphabet = BytesBloomFilter::new();
                let lastpos = p.len() - 1;
                let mut skip = p.len();
                
                for i in 0..p.len()-1 {
                    alphabet.insert(&p[i]);
                    
                    if p[i] == p[lastpos] {
                        skip = lastpos - i;
                    }
                }
                
                alphabet.insert(&p[lastpos]);
                
                (alphabet, skip)
            }
            
            pub fn find_all(&self, string: &'a str) -> Vec<usize> {
                let mut result = vec![];
                let string_bytes = string.as_bytes();
                let pat_last_pos = self.pat_bytes.len() - 1;
                let patlen = self.pat_bytes.len();
                let stringlen = string_bytes.len();
                let mut string_index = pat_last_pos;
                
                while string_index < stringlen {
                    if string_bytes[string_index] == self.pat_bytes[pat_last_pos] {
                        if &string_bytes[string_index-pat_last_pos..string_index] == &self.pat_bytes[..patlen-1] {
                            result.push(string_index-pat_last_pos);
                        }
                        
                        if string_index + 1 == stringlen {
                            break;
                        }
                        
                        if !self.alphabet.contains(&string_bytes[string_index+1]) {
                            string_index += patlen + 1;  // sunday
                        } else {
                            string_index += self.skip;  // horspool
                        }
                    } else {
                        if string_index + 1 == stringlen {
                            break;
                        }
                        
                        if !self.alphabet.contains(&string_bytes[string_index+1]) {
                            string_index += patlen + 1;  // sunday
                        } else {
                            string_index += 1;
                        }
                    }
                
                }
                
                result
            }
        }
        ```

    So với các thuật toán khớp hậu tố phía trước, phiên bản này không nhanh bằng nhưng chênh lệch không lớn. Nhờ độ phức tạp bộ nhớ rất tốt, tối đa chỉ hai số nguyên `u64`, hiệu năng của nó vẫn tốt hơn KMP.

<span id="&#29702;&#35770;&#20998;&#26512;"></span>
## Phân tích lý thuyết

Dưới đây là biểu hiện của các thuật toán trên bảng chữ cái thông thường. Trục tung tương tự chi phí thực thi (`cost` chỉ chi phí khi bất khớp sau khi đã khớp thành công m ký tự, `skip` chỉ xác suất dịch sang phải k ký tự khi xảy ra bất khớp); giá trị càng nhỏ thì hiệu năng càng tốt. Trục hoành là độ dài của xâu mẫu $pat$:

![Biểu đồ so sánh hiệu năng các thuật toán tìm kiếm xâu](./images/BM/plot256.svg)

Biểu hiện trên bảng chữ cái nhỏ hơn (chuỗi cặp base DNA {A, C, T, G}):

![Biểu đồ so sánh hiệu năng thuật toán tìm kiếm xâu trên bảng chữ cái nhỏ](./images/BM/plot4.svg)

Tóm lại, trên các bảng chữ cái lớn hơn, chẳng hạn trong quá trình tìm kiếm thường ngày, họ thuật toán Boyer-Moore có hiệu năng vượt trội chủ yếu nhờ bảng $delta_1$ để thực hiện bước nhảy ký tự.

Mặt khác, trên bảng chữ cái nhỏ hơn, vai trò của $delta_1$ giảm xuống, còn vai trò của $delta_2$ được thể hiện rõ hơn.

Nếu có đủ không gian dư, thuật toán Boyer-Moore đầy đủ với độ phức tạp bộ nhớ $O(m)$ tổng quát hơn và có biểu hiện tổng hợp tốt nhất.

<span id="&#21442;&#32771;&#36164;&#26009;&#19982;&#27880;&#37322;"></span>
## Tài liệu tham khảo và chú thích

[^bm]: [Bài báo năm 1977 về thuật toán Boyer-Moore](https://dl.acm.org/doi/10.1145/359842.359859)

[^kmp]: [Bài báo năm 1977 về thuật toán KMP](https://epubs.siam.org/doi/abs/10.1137/0206024)

[^rytter]: [Bài báo năm 1980 của Rytter sửa lỗi Knuth](https://epubs.siam.org/doi/10.1137/0209037)

[^galil-rule]: [Bài báo năm 1979 giới thiệu thuật toán Galil](https://doi.org/10.1145%2F359146.359148)

[^b5s]: [Giới thiệu thuật toán B5S](http://effbot.org/zone/stringlib.htm#BMHBNFS)
