author: Enter-tainer, iamtwz, Ir1d, isdanni, ksyx, StudyingFather, Tiphereth-A, Xeonacid, c-forrest

Kiến thức tiên quyết: [Các khái niệm cơ bản của đại số trừu tượng](./basic.md), [Lý thuyết nhóm](./group-theory.md), [Hoán vị và sắp xếp](../permutation.md)

<span id="giới-thiệu"></span>
## Giới thiệu

**Thuật toán Schreier-Sims** là một thuật toán trong lý thuyết nhóm tính toán (computational group theory), được đặt theo tên hai nhà toán học Otto Schreier và Charles Sims. Thuật toán này có thể giải nhiều bài toán trong thời gian đa thức, như tìm cấp của một nhóm hoán vị hữu hạn, hoặc kiểm tra một hoán vị cho trước có nằm trong nhóm đã cho hay không. Schreier-Sims được Sims đưa ra lần đầu vào năm 1970 dựa trên bổ đề Schreier. Năm 1981[^knuth-year], Donald Knuth cải tiến thêm thời gian chạy của thuật toán. Về sau, thuật toán còn có một phiên bản ngẫu nhiên hóa nhanh hơn. Các hệ đại số máy tính (chẳng hạn GAP và Magma) thường dùng phiên bản Monte Carlo đã được tối ưu hóa cao của thuật toán này[^monte-carlo].

???+ info "Ký hiệu"
    Theo thông lệ trong các tài liệu lý thuyết nhóm tính toán, bài này viết tác động nhóm dưới dạng tác động phải; điều này có nghĩa là phép hợp thành hoán vị được thực hiện từ trái sang phải. Mọi tác động nhóm xuất hiện trong bài đều có thể xem là tác động hoán vị, dù một số thuật toán vẫn dùng được cho các tác động nhóm tổng quát hơn. Tương ứng, tập mà nhóm tác động lên mặc định là $X=\{1,2,\cdots,n\}$, và các phần tử của nó được gọi là điểm. Kết quả khi hoán vị $g$ tác động lên điểm $x$ được ký hiệu là $x^g$; đôi khi cũng nói hoán vị $g$ đưa điểm $x$ đến điểm $x^g$. Cuối cùng, với nhóm hoán vị $G$, quỹ đạo của điểm $x$ dưới tác động của $G$ được ký hiệu là $x^G=\{x^g:g\in G\}$, còn bộ ổn định của nó là $G_x=\{g\in G:x^g=x\}$. Khái niệm bộ ổn định cũng có thể mở rộng cho tập $B\subseteq X$, khi đó bộ ổn định của $B$ được định nghĩa là $G_B=\bigcap_{x\in B}G_x$.

<span id="tổng-quan"></span>
## Tổng quan

Schreier-Sims chủ yếu cố gắng giải quyết bài toán sau:

-   Cho một tập $S$ gồm một số hoán vị trên tập $X$ có kích thước $n$, làm thế nào để lưu trữ hiệu quả trong máy tính nhóm hoán vị $G=\langle S\rangle$ sinh bởi $S$, đồng thời thực hiện các truy vấn liên quan đến nhóm này?

Kích thước của nhóm $G$ như vậy có thể rất lớn, lớn hơn nhiều so với kích thước của tập $X$ và tập sinh $S$. Chẳng hạn, nhóm đối xứng bậc $n$, $S_n=\langle(123\cdots n),(12)\rangle$, có kích thước $n!$ nhưng chỉ cần hai hoán vị để sinh ra. Lưu từng phần tử của nhóm là điều không thực tế.

Tương tự như cách dùng [khử Gauss](../numerical/gauss.md) để xây dựng một [cơ sở tuyến tính](../linear-algebra/basis.md) của không gian vectơ, ý tưởng của Schreier-Sims là tìm một "cơ sở" cho nhóm hoán vị hữu hạn $G$:

1.  Đầu vào của thuật toán là một tập sinh $S$ của $G$, gồm một số hoán vị;
2.  Nếu nhóm $G$ không tầm thường, luôn tìm được một điểm $\beta$ bị thay đổi vị trí dưới tác động của $G$, tức là $|\beta^G|>1$;
3.  Tìm quỹ đạo $\Delta=\beta^{G}$ của điểm $\beta$, và với mỗi điểm $\delta\in\Delta$ trong quỹ đạo, tìm một hoán vị $t_{\delta}$ trong nhóm $G$ đưa điểm $\beta$ đến $\delta$;
4.  Tìm một tập sinh $S'$ của bộ ổn định $G_{\beta}$ của điểm $\beta$;
5.  Đệ quy gọi thuật toán trên $G'=\langle S'\rangle$ cho đến khi thu được nhóm tầm thường $\{e\}$.

Ý tưởng này hợp lý vì bộ ổn định $G_{\beta}$ của điểm $\beta$ là một nhóm con của $G$; toàn bộ các lớp kề (phải) của nó tạo thành một phân hoạch của $G$, và các lớp kề này tương ứng một-một với quỹ đạo $\beta^G$ của điểm $\beta$. Các hoán vị $t_{\delta}$ tìm được ở bước 3 chính là các đại diện của những lớp kề đó. Tập các đại diện lớp kề này $T$ được gọi là **hệ đại diện lớp kề** (transversal) của bộ ổn định $G_{\beta}$. Nói cách khác, mỗi phần tử $g$ của nhóm $G$ tương ứng duy nhất với một cặp phần tử $(h,t)\in G_\beta\times T$ sao cho $g=ht$. Vì vậy, nếu có cách lưu nhóm con $G_{\beta}$ và hệ đại diện lớp kề tương ứng $T$, có thể lưu cả nhóm $G$. Tuy nhiên, bài toán lưu nhóm con $G_{\beta}$ cũng đã được giải: chỉ cần gọi đệ quy thuật toán.

Việc cài đặt thuật toán còn nhiều chi tiết cần sắp xếp; đó là nội dung chính của bài này. Trước đó, cần xem kết quả sau khi gọi thuật toán có dạng cấu trúc nào, và cấu trúc ấy giải được những truy vấn nào. Vì thế, cần làm rõ một số khái niệm.

<span id="chuỗi-bộ-ổn-định"></span>
### Chuỗi bộ ổn định

Giả sử gọi thuật toán trên nhóm $G=\langle S\rangle$ tổng cộng $k$ lần; trong lần gọi thứ $i$, đầu vào là tập hoán vị $S^{(i-1)}$, điểm tìm được là $\beta_i$, hệ đại diện lớp kề thu được là $T_i$, và tập sinh của bộ ổn định thu được là $S^{(i)}$. Nếu đặt $G^{(i)}=\langle S^{(i)}\rangle$, thì thuật toán thực chất thu được chuỗi nhóm con

$$
G=G^{(0)}> G^{(1)}>\cdots> G^{(k-1)}> G^{(k)}=\{e\}.
$$

Hơn nữa, mỗi nhóm con trong chuỗi đều là một bộ ổn định

$$
G^{(i)}=G_{\beta_1,\cdots,\beta_i}.
$$

Vì vậy, có thể xem Schreier-Sims là thuật toán tính một **chuỗi bộ ổn định** (stabilizer chain) như vậy.

<span id="cơ-sở-và-tập-sinh-mạnh"></span>
### Cơ sở và tập sinh mạnh

Nếu một tập con $B$ của $X$ thỏa $G_B=\{e\}$, thì $B$ được gọi là một **cơ sở** (base) của nhóm hoán vị $G$. Thuật toán trên thu được một cơ sở $B=\{\beta_1,\cdots,\beta_k\}$. Điều này có nghĩa là kết quả tác động của một hoán vị $g\in G$ lên các điểm này xác định duy nhất hoán vị đó trong nhóm $G$. Hơn nữa, cơ sở mà thuật toán xuất ra còn thỏa điều kiện

$$
G^{(i-1)}=G_{\beta_1,\cdots,\beta_{i-1}}>G_{\beta_1,\cdots,\beta_{i-1},\beta_i}=G^{(i)}.
$$

Nói cách khác, mỗi điểm trong cơ sở đều chứa thông tin hữu ích về các phần tử trong nhóm. Một cơ sở như vậy được gọi là **không dư thừa** (nonredundant). Thuật toán luôn xuất ra cơ sở không dư thừa. Chuỗi bộ ổn định ứng với cơ sở như vậy giảm nghiêm ngặt.

Đồng thời, hợp của các tập sinh mà thuật toán thu được

$$
\bar S=\bigcup_{i=0}^kS_i
$$

cũng là một tập sinh của $G$, và thỏa $\langle\bar S\cap G^{(i)}\rangle = G^{(i)}$. Một tập sinh thỏa điều kiện này được gọi là **tập sinh mạnh** (strong generating set) của nhóm $G$ đối với cơ sở $B$. Vì vậy, cũng có thể xem Schreier-Sims là thuật toán tính **cơ sở và tập sinh mạnh** (base and strong generating set, BSGS) của $G$. Cách nói này tương đương với cách nói chuỗi bộ ổn định; bài này không phân biệt hai cách gọi.

Thuật toán còn thu được một dãy quỹ đạo $\Delta_i=\beta_{i}^{G^{(i-1)}}$ và các hệ đại diện lớp kề tương ứng $T_i$. Các quỹ đạo này được gọi là **quỹ đạo cơ bản** (fundamental orbits) của nhóm $G$. Khi bài này nhắc đến chuỗi bộ ổn định hoặc cơ sở và tập sinh mạnh của $G$, mặc định các quỹ đạo cơ bản và hệ đại diện lớp kề tương ứng đã được tính kèm theo.

<span id="cấu-trúc-dữ-liệu"></span>
### Cấu trúc dữ liệu

Bài này sẽ đưa ra một loạt mã giả. Trong mã giả, chuỗi bộ ổn định của nhóm (hay cơ sở và tập sinh mạnh) được lưu trong cấu trúc dữ liệu $C$:

$$
C=(S,\Delta,T,C').
$$

Các thành viên dữ liệu trong cấu trúc này lần lượt là tập sinh $S$ của nhóm hiện tại, quỹ đạo cơ bản $\Delta$, hệ đại diện lớp kề tương ứng $T$, và bộ ổn định $C'$ được lưu như một cấu trúc con lồng nhau. Bộ ổn định $C'$ cũng là một cấu trúc như vậy. Toàn bộ nhóm thực tế được lưu trong một cấu trúc phân tầng, mỗi tầng mô tả một nhóm trong chuỗi bộ ổn định. Tầng trong cùng là cấu trúc rỗng, biểu diễn $G^{(k)}=\{e\}$.

Trong mã giả, các thành viên của cấu trúc dữ liệu này có thể được truy cập lần lượt bằng $C.generators$, $C.orbit$, $C.transversal$ và $C.next$. Phần tử đầu tiên của quỹ đạo $C.orbit[0]$ mặc định là điểm cơ sở $\beta$, còn đại diện lớp kề tương ứng $C.transversal[\beta]$ mặc định là biến đổi đồng nhất $e$. Tuy tại đây dùng chỉ số mảng để truy cập phần tử trong quỹ đạo và hệ đại diện lớp kề, chúng không nhất thiết phải được lưu bằng mảng; đúng hơn, nên hiểu rằng chúng cung cấp cách truy cập phần tử đầu của quỹ đạo và cách tra cứu đại diện lớp kề tương ứng theo điểm trong quỹ đạo. Các chi tiết cài đặt cụ thể sẽ được bàn ở phần sau.

<span id="ứng-dụng"></span>
### Ứng dụng

Sau khi thu được cơ sở và tập sinh mạnh của nhóm, có thể giải một loạt bài toán truy vấn về nhóm. Cơ bản nhất, và thường gặp nhất trong thi lập trình, là truy vấn cấp của nhóm và kiểm tra một hoán vị có thuộc nhóm đã cho hay không.

<span id="cấp-của-nhóm"></span>
#### Cấp của nhóm

Nếu đã biết cơ sở và tập sinh mạnh của nhóm $G$, từ định lý Lagrange và định lý quỹ đạo-bộ ổn định, cấp của $G$ có thể được tính bằng

$$
|G|=\prod_{i=1}^k[G^{(i-1)}:G^{(i)}]=\prod_{i=1}^k[G^{(i-1)}:G^{(i-1)}_{\beta_i}]=\prod_{i=1}^k|T_i|.
$$

Do đó, chỉ cần nhân kích thước của tất cả các hệ đại diện lớp kề $T_i$ (tương đương với độ dài của các quỹ đạo cơ bản $\Delta_i$) là thu được cấp của nhóm $G$.

<span id="kiểm-tra-thành-viên"></span>
#### Kiểm tra thành viên

Nếu đã biết cơ sở và tập sinh mạnh của nhóm $G$, cũng có thể xác định một hoán vị $h$ có thuộc $G$ hay không. Bài toán này được gọi là **kiểm tra thành viên** (membership testing).

Bài toán này có thể giải đệ quy. Để xác định $h\in G^{(i-1)}$, trước hết cần tìm đại diện $t\in T_i$ của lớp kề của $G^{(i)}$ chứa $h$. Nếu tìm được, đặt $h'=ht^{-1}$, khi đó $h=h't$ và $h\in G^{(i-1)}$ tương đương với $h'\in G^{(i)}$; bài toán chuyển thành xác định $h'\in G^{(i)}$. Nếu không tìm được $t$ như vậy, hoặc đã đệ quy đến $G^{(k)}=\{e\}$ nhưng $h\neq e$, kết luận $h\notin G$. Quá trình này không chỉ xác định $h\in G$, mà trong trường hợp $h\in G$ còn biểu diễn được $h$ thành tích của một dãy đại diện lớp kề $t_k\cdots t_2t_1$, với $t_i\in T_i$. Đối với các phần tử của $G$, biểu diễn như vậy tồn tại và duy nhất. Điều này một lần nữa chứng minh công thức tính cấp của nhóm bên trên là đúng.

Viết quá trình trên thành mã giả:

$$
\begin{array}{l}
\textbf{Thuật toán }\textrm{MembershipTest}(C,h):\\
\textbf{Đầu vào. }\textrm{Chuỗi bộ ổn định }C\textrm{ của nhóm }G\textrm{ và một hoán vị }h.\\
\textbf{Đầu ra. }\textrm{Liệu }h\in G\textrm{ hay không.}\\
\textbf{Phương pháp.}\\
\begin{array}{ll}
1  & \textbf{trong khi }C\textrm{ không rỗng }\\
2  & \qquad \beta \leftarrow C.orbit[0]\\
3  & \qquad \delta \leftarrow \beta^h\\
4  & \qquad \textbf{nếu }\delta\in C.orbit\textbf{ thì}\\
5  & \qquad \qquad t \leftarrow C.transversal[\delta]\\
6  & \qquad \qquad h \leftarrow ht^{-1}\\
7  & \qquad \textbf{ngược lại }\\
8  & \qquad \qquad \textbf{trả về }\textrm{false}\\
9  & \qquad \textbf{kết thúc nếu}\\
10 & \qquad C \leftarrow C.next\\
11 & \textbf{kết thúc vòng lặp}\\
12 & \textbf{trả về }h=e
\end{array}
\end{array}
$$

Phần sau sẽ thấy bài toán kiểm tra thành viên cũng là một thành phần quan trọng trong cách cài đặt Schreier-Sims được thảo luận ở bài này.

<span id="tính-quỹ-đạo-hệ-đại-diện-lớp-kề-và-bộ-ổn-định"></span>
## Tính quỹ đạo, hệ đại diện lớp kề và bộ ổn định

Để cài đặt Schreier-Sims, trước hết cần giải bài toán con sau:[^orbit-algo]

-   Cho tập sinh $S$ của nhóm $G$ và một điểm $\beta$, làm thế nào để tìm quỹ đạo $\beta^G$, hệ đại diện lớp kề tương ứng $T$, và một tập sinh của bộ ổn định $G_\beta$?

Đây là bài toán sẽ được giải quyết trong mục này.

<span id="lưu-quỹ-đạo-và-hệ-đại-diện-lớp-kề"></span>
### Lưu quỹ đạo và hệ đại diện lớp kề

Để tìm quỹ đạo và hệ đại diện lớp kề, chỉ cần tìm kiếm trực tiếp. Mã giả như sau:

$$
\begin{array}{l}
\textbf{Thuật toán }\textrm{OrbitTransversal}(S,\beta):\\
\textbf{Đầu vào. }\textrm{Tập sinh }S\textrm{ của nhóm }G\textrm{ và một điểm }\beta.\\
\textbf{Đầu ra. }\textrm{Quỹ đạo }\Delta=\beta^G\textrm{ và hệ đại diện lớp kề }T.\\
\textbf{Phương pháp.}\\
\begin{array}{ll}
1  & \Delta \leftarrow [\beta]\\
2  & T[\beta] \leftarrow e\\
3  & \textbf{với mỗi }\delta\in\Delta\\
4  & \qquad \textbf{với mỗi }s\in S\\
5  & \qquad \qquad \gamma \leftarrow \delta^s\\
6  & \qquad \qquad \textbf{nếu }\gamma\notin\Delta\textbf{ thì}\\
7  & \qquad \qquad \qquad\textrm{thêm }\gamma\textrm{ vào }\Delta\\
8  & \qquad \qquad \qquad T[\gamma] \leftarrow T[\delta]\cdot s\\
9  & \qquad \qquad \textbf{kết thúc nếu}\\
10 & \qquad \textbf{kết thúc vòng lặp}\\
11 & \textbf{kết thúc vòng lặp}\\
12 & \textbf{trả về }\Delta, T
\end{array}
\end{array}
$$

Khi cài đặt cụ thể, dùng tìm kiếm theo chiều rộng hay chiều sâu đều được. Số trạng thái mà tìm kiếm duyệt qua là $|S||T|$; miễn là quỹ đạo và hệ đại diện lớp kề được lưu hợp lý, độ phức tạp thời gian hoàn toàn chấp nhận được.

Trong ngữ cảnh nhóm hoán vị, quỹ đạo chỉ là một tập có tối đa $n$ điểm. Để tìm kiếm và thêm phần tử hiệu quả, có thể dùng mảng boolean hoặc tập băm. Khi đó cả hai thao tác đều có độ phức tạp $O(1)$, và tổng bộ nhớ là $O(n)$. Tùy vào cách cài đặt hệ đại diện lớp kề, có thể còn cần đánh dấu thêm vị trí của phần tử đầu tiên.

Vấn đề là nên dùng cấu trúc dữ liệu nào để lưu hệ đại diện lớp kề tương ứng $T$.

<span id="lưu-trực-tiếp"></span>
#### Lưu trực tiếp

Cách đơn giản nhất là lưu trực tiếp mỗi phần tử $t$ của hệ đại diện lớp kề $T$. Một hoán vị đơn lẻ khi lưu bằng [ký hiệu một dòng](../permutation.md#ký-hiệu-một-dòng) cần dùng đúng $n$ ô nhớ, nên độ phức tạp không gian để lưu hệ đại diện lớp kề như vậy là $O(|T|n)$. Lợi ích là truy cập một đại diện lớp kề đơn lẻ trong $O(1)$ thời gian; cái giá phải trả là lần đầu tính các đại diện lớp kề này tốn $O(|T|n)$ thời gian.

<span id="cây-schreier"></span>
#### Cây Schreier

Một cách phổ biến khác là cài đặt một cấu trúc cây để lưu hệ đại diện lớp kề. Cấu trúc này được gọi là **cây Schreier** (Schreier tree) hoặc **vectơ Schreier** (Schreier vector)[^schreier-vector]. Nó lấy $\beta$ làm gốc và lấy các phần tử $\delta$ trong quỹ đạo $\Delta$ làm đỉnh. Mỗi khi trong quá trình tìm kiếm thu được đỉnh mới $\gamma=\delta^s$, nối một cạnh từ đỉnh cũ $\delta$ đến đỉnh mới $\gamma$, và trên cạnh ghi lại chỉ số (hoặc con trỏ) của hoán vị $s$ trong tập sinh $S$. Vì tập sinh đã được lưu sẵn, bộ nhớ phụ cần để lưu hệ đại diện lớp kề là $O(|T|)$. Khi $n$ rất lớn, cách này tiết kiệm bộ nhớ hiệu quả, và độ phức tạp lần tính đầu là $O(|T|)$. Tuy nhiên, tác dụng phụ là mỗi khi cần lấy đại diện lớp kề, phải duyệt các cạnh trên đường đi từ đỉnh về gốc và tính lại đại diện lớp kề, nên thời gian phụ thuộc mạnh vào độ sâu của cây Schreier. Trong trường hợp tổng quát, độ sâu của cây có thể đạt cấp $O(n)$.

Khi cài đặt cụ thể, cần cân đối độ phức tạp thời gian và không gian theo bài toán. Trong những tình huống có thể gặp trong thi lập trình, $n$ thường không lớn, bộ nhớ đủ, còn thời gian lại hay là nút thắt. Phần phân tích độ phức tạp bên dưới cho thấy bước tốn thời gian nhất của Schreier-Sims cần truy cập đại diện lớp kề nhiều lần, nên cách lưu trực tiếp thường tốt hơn. Tuy nhiên, trong một số ứng dụng, $n$ có thể rất lớn và bộ nhớ chặt chẽ hơn; khi đó có thể cần dùng cây Schreier để lưu hệ đại diện lớp kề. Với trường hợp này, để tránh cây Schreier quá sâu, các nhà nghiên cứu đã đưa ra nhiều phương pháp dùng để xây lại cây Schreier nông hơn khi độ sâu của cây quá lớn. Có thể tham khảo thêm các tài liệu ở cuối bài.

Trong mã giả, bài này không phân biệt cách cài đặt cụ thể của hệ đại diện lớp kề; chỉ giả định cấu trúc dữ liệu lưu $T$ có thao tác truy cập và sửa đại diện lớp kề tương ứng $T[\delta]$ theo phần tử quỹ đạo $\delta\in\Delta$.

<span id="bổ-đề-schreier"></span>
### Bổ đề Schreier

Sau khi có quỹ đạo $\beta^G$ và hệ đại diện lớp kề $T$, bổ đề Schreier cho phép thu được tập sinh của bộ ổn định $G_\beta$.

???+ note "Bổ đề Schreier"
    Cho nhóm $G=\langle S\rangle$ có nhóm con $H\le G$. Gọi $T$ là một hệ đại diện lớp kề (phải) của nhóm con $H$, với $e\in T$[^schreier-lemma-unity], và ký hiệu đại diện $t\in T$ của lớp kề chứa $g\in G$ là $\overline g$. Khi đó, tập
    
    $$
    U=\{ts(\overline{ts})^{-1}:t\in T,s\in S\}
    $$
    
    là một tập sinh của nhóm con $H$. Các phần tử của nó được gọi là **phần tử sinh Schreier** (Schreier generator) của nhóm con $H$.

??? note "Chứng minh"
    Trước hết, theo định nghĩa của đại diện lớp kề, $ts(\overline{ts})^{-1}\in H$ đúng với mọi $t\in T,s\in S$, do đó $\langle U\rangle\subseteq H$.
    
    Ngược lại, với bất kỳ $h\in H$, vì $S$ là tập sinh của $G\ge H$, tồn tại một dãy $s_i\in S\cup S^{-1}$ sao cho
    
    $$
    h=s_1s_2\cdots s_r
    $$
    
    đúng. Đặt $t_1=e$, và định nghĩa đệ quy $t_{i+1}=\overline{t_is_i}\in T$. Khi đó
    
    $$
    \begin{aligned}
    h&=\left(t_1s_1t_2^{-1}\right)\left(t_2s_2t_3^{-1}\right)\cdots\left(t_rs_rt_{r+1}^{-1}\right)t_{r+1}.
    \end{aligned}
    $$
    
    Với mỗi $i=1,2,\cdots,r$ có $t_is_it_{i+1}^{-1}=t_is_i(\overline{t_is_i})^{-1}\in U\cup U^{-1}\subseteq H$, nên $t_{r+1}\in H$. Nhưng $H\cap T=\{e\}$, vì vậy $t_{r+1}=e$. Điều này cho thấy mỗi $h\in H$ đều viết được thành tích của một dãy $u_i=t_is_it_{i+1}^{-1}\in U\cup U^{-1}$, tức là $U$ sinh ra $H$.

Vì nhóm con tương ứng với hệ đại diện lớp kề $T$ chính là bộ ổn định $G_\beta$, sau khi tìm được $T$ và kết hợp với tập sinh $S$ của nhóm $G$, sẽ thu được một tập sinh của bộ ổn định $G_\beta$.

<span id="thuật-toán"></span>
### Thuật toán

Chỉ cần sửa nhẹ mã giả ở trên, có thể vừa tính quỹ đạo và hệ đại diện lớp kề, vừa thu được tập sinh của bộ ổn định tương ứng:

$$
\begin{array}{l}
\textbf{Thuật toán }\textrm{OrbitTransversalStabilizer}(S,\beta):\\
\textbf{Đầu vào. }\textrm{Tập sinh }S\textrm{ của nhóm }G\textrm{ và một điểm }\beta.\\
\textbf{Đầu ra. }\textrm{Quỹ đạo }\Delta=\beta^G\textrm{, hệ đại diện lớp kề }T\textrm{, và một}\\
\qquad\textrm{ tập sinh }S'\textrm{ của bộ ổn định }G_\beta.\\
\textbf{Phương pháp.}\\
\begin{array}{ll}
1  & \Delta \leftarrow [\beta]\\
2  & T[\beta] \leftarrow e\\
3  & S' \leftarrow [e]\\
4  & \textbf{với mỗi }\delta\in\Delta\\
5  & \qquad \textbf{với mỗi }s\in S\\
6  & \qquad \qquad \gamma \leftarrow \delta^s\\
7  & \qquad \qquad \textbf{nếu }\gamma\notin\Delta\textbf{ thì}\\
8  & \qquad \qquad \qquad\textrm{thêm }\gamma\textrm{ vào }\Delta\\
9  & \qquad \qquad \qquad T[\gamma] \leftarrow T[\delta]\cdot s\\
10 & \qquad \qquad \textbf{ngược lại} \\
11 & \qquad \qquad \qquad \textrm{thêm }T[\delta]\cdot s\cdot T[\gamma]^{-1}\textrm{ vào }S'\\
12 & \qquad \qquad \textbf{kết thúc nếu}\\
13 & \qquad \textbf{kết thúc vòng lặp}\\
14 & \textbf{kết thúc vòng lặp}\\
15 & \textbf{trả về }\Delta, T, S'
\end{array}
\end{array}
$$

Trong mã giả, với mỗi cặp $(\delta,s)$, chỉ khi không sinh ra phần tử mới trong quỹ đạo thì $t_\delta st_{\delta^s}^{-1}$ mới là một phần tử sinh Schreier mới; nếu không, nó chỉ là biến đổi đồng nhất $e$. Do đó, số phần tử sinh Schreier mà thuật toán thực sự sinh ra (kể cả biến đổi đồng nhất ban đầu) tối đa là

$$
|S||T|-(|T|-1) = |S|(|T|-1)+1
$$

phần tử. Trong trường hợp tổng quát, cận trên này đạt được.[^upper-bound] Tuy nhiên, với các nhóm hữu hạn cần xử lý trong thực tế, cận này khá lỏng: phần lớn các phần tử sinh Schreier mới thu được đều trùng với phần tử sinh đã có, hoặc có thể hợp thành từ các phần tử sinh trước đó.

Vì quy trình cơ bản của Schreier-Sims có thể cài đặt bằng cách đệ quy gọi thuật toán tính quỹ đạo và bộ ổn định bên trên, đến bước này đã có một cách cài đặt thô sơ của Schreier-Sims. Nhưng nếu không lọc bớt, số lượng phần tử sinh Schreier tăng theo cấp số mũ: lặp lại $O(|S_{i}|)=O(|S_{i-1}||T_i|)$ cho thấy kích thước tập sinh của bộ ổn định trong cùng sẽ đạt $O(|S||G|)$. Điều này phi lý về mặt hiệu quả, vì bộ ổn định trong cùng là $\{e\}$.

Công trình của Sims đưa ra cách khống chế tốc độ tăng của số phần tử sinh Schreier; nó bảo đảm tập sinh mạnh cuối cùng $\bar S$ có kích thước $O(n^2)$. Nhờ vậy có thể tính cơ sở và tập sinh mạnh trong thời gian đa thức.

<span id="thuật-toán-schreier-sims"></span>
## Thuật toán Schreier-Sims

Để giải quyết vấn đề trên, mục này thảo luận một cách cài đặt tăng dần của Schreier-Sims, trong đó tập sinh mạnh thu được có kích thước $O(n^2)$.

<span id="sàng-lọc"></span>
### Sàng lọc

Tối ưu cốt lõi của Schreier-Sims so với thuật toán thô sơ ở trên rất đơn giản: trước khi thêm bất kỳ phần tử sinh Schreier nào vào tập sinh của bộ ổn định, phần tử đó phải được **sàng lọc** (sifting). Sàng lọc nghĩa là trước hết xác định phần tử sinh Schreier mới đã nằm trong nhóm con sinh bởi các phần tử sinh hiện có hay chưa, rồi chỉ thêm những phần tử sinh chưa tồn tại. Để làm điều này, chỉ cần dùng thuật toán kiểm tra thành viên $\textrm{MembershipTest}(C,h)$ đã nêu ở trên.

Nhưng điều kiện tiền đề để làm như vậy là, dựa trên các phần tử sinh Schreier đã sinh ra của nhóm hiện tại, chuỗi bộ ổn định (hay cơ sở và tập sinh mạnh) của nhóm mà chúng sinh ra đã được xây dựng sẵn. Điều này có nghĩa là mỗi khi thêm một phần tử sinh Schreier mới vào tập sinh của bộ ổn định, cần duy trì đồng bộ chuỗi bộ ổn định bên trong để dùng cho các lần sàng lọc sau. Tuy nhiên, mỗi lần tầng hiện tại chèn thêm một phần tử sinh, có thể sinh ra nhiều phần tử sinh Schreier, nên có thể phải cập nhật cấu trúc bên trong nhiều lần; mỗi cập nhật ở cấu trúc bên trong lại có thể kéo theo nhiều cập nhật ở các cấu trúc sâu hơn.

Có vẻ như vấn đề bùng nổ theo cấp số mũ nêu trên vẫn tồn tại. Tuy nhiên, do đã sàng lọc trước, một tầng chỉ được cập nhật khi phần tử sinh sắp thêm thật sự làm nhóm được lưu ở tầng đó lớn hơn. Do đó, số lần cập nhật của một tầng thực chất bằng số lần nhóm mà tầng đó lưu tăng nghiêm ngặt. Nhưng một nhóm có kích thước $|G|$ có chuỗi nhóm con dài nhất không quá $\log|G|$, vì định lý Lagrange bảo đảm mỗi khi chuỗi nhóm con dài thêm một mức, kích thước nhóm ít nhất tăng gấp đôi. Vì vậy, mỗi tầng chỉ cập nhật tối đa $\log|G|$ lần, và kích thước tập sinh mạnh cuối cùng $\bar S$ là $|B|\log|G|$.

Ước lượng này còn có thể cải tiến. Vì nhóm $G$ đang xét đã biết là nhóm con của nhóm đối xứng bậc $n$, $S_n$, nên độ dài chuỗi nhóm con của $G$ không vượt quá độ dài chuỗi nhóm con của $S_n$. Có thể chứng minh[^subgroup-chain] rằng độ dài của một chuỗi nhóm con tăng nghiêm ngặt trong $S_n$ không vượt quá $3n/2$. Điều này cho thấy số lần cập nhật của một tầng là $O(n)$. Kích thước cơ sở cũng không vượt quá $n$. Vì thế, kích thước tập sinh mạnh cuối cùng $\bar S$ là $O(n^2)$.

Phương pháp sàng lọc vừa nêu do Sims đưa ra, còn gọi là sàng Sims (Sims filter). Còn một phương pháp sàng lọc phức tạp hơn do Jerrum đưa ra, gọi là [sàng Jerrum](https://groupprops.subwiki.org/w/index.php?title=Jerrum%27s_filter) (Jerrum filter), bảo đảm tập sinh mạnh thu được có kích thước $O(n)$. Có thể tham khảo thêm các tài liệu ở cuối bài.

Có một tối ưu nhỏ cho quá trình sàng lọc: trong cài đặt $\textrm{MembershipTest}(C,h)$, không cần xuất giá trị boolean, mà xuất "phần còn lại sau sàng"[^siftee] $h$ cuối cùng (tức dùng $\textbf{trả về }h$ thay cho các lệnh trả về kết quả boolean trong mã giả). Nếu "phần còn lại sau sàng" $h\neq e$, nghĩa là kiểm tra thành viên thất bại; khi đó có thể thêm trực tiếp "phần còn lại sau sàng" $h$ thay vì $h$ ban đầu vào tầng hiện tại. Phần tử $h$ này đã bị loại bỏ một số thừa số là đại diện lớp kề, nên di chuyển ít điểm hơn và giảm khối lượng tính toán cục bộ. Tối ưu này không ảnh hưởng đến độ phức tạp tổng thể.

<span id="quy-trình"></span>
### Quy trình

Bây giờ có thể mô tả quy trình cụ thể của Schreier-Sims: trước hết, khởi tạo một cấu trúc rỗng $C$ để lưu chuỗi bộ ổn định của nhóm. Sau đó lần lượt thêm các phần tử sinh trong tập sinh $S$ vào cấu trúc $C$; cấu trúc $C$ cuối cùng chính là chuỗi bộ ổn định của nhóm $\langle S\rangle$. Mã giả như sau:

$$
\begin{array}{l}
\textbf{Thuật toán }\textrm{SchreierSims}(S):\\
\textbf{Đầu vào. }\textrm{Tập sinh }S\textrm{ của nhóm }G.\\
\textbf{Đầu ra. }\textrm{Chuỗi bộ ổn định }C\textrm{ của nhóm }G.\\
\textbf{Phương pháp.}\\
\begin{array}{ll}
1  & C \leftarrow []\\
2  & \textbf{với mỗi }s\in S\\
3  & \qquad C \leftarrow \textrm{Extend}(C,s)\\
4  & \textbf{kết thúc vòng lặp}\\
5  & \textbf{trả về }C
\end{array}
\end{array}
$$

Cốt lõi của thuật toán nằm ở bước thêm phần tử sinh mới $s$ vào $C$ hiện tại, tức thủ tục con $\textrm{Extend}(C,s)$. Như đã nêu, trước và sau khi thêm hoán vị $s$, cần giữ $C$ là một chuỗi bộ ổn định. Vì vậy, trước khi thêm hoán vị $s$, có thể sàng lọc trước. Nếu phát hiện $s$ không nằm trong nhóm hiện có, thuật toán **tăng dần** tính quỹ đạo, đại diện lớp kề và phần tử sinh Schreier. Tại đây "tăng dần" có nghĩa là những gì đã tính rồi thì không tính lại. Như vậy mới đạt được độ phức tạp đúng.

Xét cách biến đổi $\textrm{OrbitTransversalStabilizer}(S,\beta)$ thành phiên bản tăng dần. Không gian trạng thái mà thuật toán tìm kiếm là $\Delta\times S$. Sau khi thêm phần tử sinh mới $s$, không gian trạng thái trở thành $\Delta'\times\left(S\cup\{s\}\right)$. Hiệu của hai không gian là

$$
\left(\Delta\times\{s\}\right)\cup\left((\Delta'\setminus\Delta)\times \left(S\cup\{s\}\right)\right).
$$

Điều này có nghĩa là khi thêm phần tử sinh mới $s$, trước hết cần tính các tổ hợp của phần tử sinh mới $s$ với quỹ đạo cũ và các đại diện lớp kề tương ứng; nếu trong quá trình này lại thu được phần tử quỹ đạo mới, thì tiếp tục xét các phần tử mới đó với tất cả phần tử sinh (cũ lẫn mới); lặp lại đến khi quỹ đạo không kéo dài nữa.

Mã giả để thêm hoán vị $g$ vào cấu trúc $C$ như sau:

$$
\begin{array}{l}
\textbf{Thuật toán }\textrm{Extend}(C,g):\\
\textbf{Đầu vào. }\textrm{Chuỗi bộ ổn định }C\textrm{ của nhóm sinh bởi }S\textrm{ và một}\\
\qquad \textrm{hoán vị }g.\\
\textbf{Đầu ra. }\textrm{Chuỗi bộ ổn định }C\textrm{ của nhóm sinh bởi }S\cup\{g\}.\\
\textbf{Phương pháp.}\\
\begin{array}{ll}
1  & \textbf{nếu }\textrm{MembershipTest}(C,g)\textrm{ thành công}\textbf{ thì}\\
2  & \qquad \textbf{trả về }C\\
3  & \textbf{kết thúc nếu}\\
4  & \textbf{nếu }C\textrm{ rỗng}\textbf{ thì}\\
5  & \qquad \beta \leftarrow \textrm{một phần tử bị }g\textrm{ di chuyển}\\
6  & \qquad C.orbit[0] \leftarrow \beta \\
7  & \qquad C.transversal[\beta] \leftarrow e\\
8  & \textbf{kết thúc nếu}\\
9  & \textrm{thêm }g\textrm{ vào }C.generators\\
10  & \Delta \leftarrow \textrm{bản sao của }C.orbit \\
11 & \textbf{với mỗi }\delta\in\Delta \\
12 & \qquad \gamma \leftarrow \delta^g \\
13 & \qquad \textbf{nếu }\gamma\notin C.orbit\textbf{ thì}\\
14 & \qquad \qquad \textrm{thêm }\gamma\textrm{ vào }C.orbit\\
15 & \qquad \qquad C.transversal[\gamma] \leftarrow C.transversal[\delta]\cdot g\\
16 & \qquad \textbf{ngược lại}\\
17 & \qquad \qquad s'\leftarrow C.transversal[\delta]\cdot g\cdot C.transversal[\gamma]^{-1}\\
18 & \qquad \qquad C.next \leftarrow \textrm{Extend}(C.next, s')\\
19 & \qquad \textbf{kết thúc nếu}\\
20 & \textbf{kết thúc vòng lặp} \\
21 & \textbf{với mỗi }\delta\in C.orbit\setminus\Delta \\
22 & \qquad \textbf{với mỗi }s\in C.generators \\
23 & \qquad \qquad \gamma \leftarrow \delta^s \\
24 & \qquad \qquad \textbf{nếu }\gamma\notin C.orbit\textbf{ thì}\\
25 & \qquad \qquad \qquad \textrm{thêm }\gamma\textrm{ vào }C.orbit\\
26 & \qquad \qquad \qquad C.transversal[\gamma] \leftarrow C.transversal[\delta]\cdot s\\
27 & \qquad \qquad \textbf{ngược lại}\\
28 & \qquad \qquad \qquad s'\leftarrow C.transversal[\delta]\cdot s\cdot C.transversal[\gamma]^{-1}\\
29 & \qquad \qquad \qquad C.next \leftarrow \textrm{Extend}(C.next, s')\\
30 & \qquad \qquad \textbf{kết thúc nếu}\\
31 & \qquad \textbf{kết thúc vòng lặp}\\
32 & \textbf{kết thúc vòng lặp} \\
33 & \textbf{trả về }C
\end{array}
\end{array}
$$

Như vậy thu được thuật toán Schreier-Sims hoàn chỉnh.

<span id="một-cách-cài-đặt-khác"></span>
### Một cách cài đặt khác

Cách cài đặt trên đã đúng, nhưng các dòng $12\sim 19$ và $23\sim 30$ hơi lặp lại. Dựa trên quan sát này, Knuth đề xuất trong bài báo của mình một cách cài đặt đệ quy ngắn gọn hơn. Cách làm của ông là xem phần lặp lại này như việc cập nhật hệ đại diện lớp kề (và quỹ đạo). Mỗi lần cập nhật hệ đại diện lớp kề đều phải kết hợp với tất cả phần tử sinh; tùy theo việc có sinh ra đại diện lớp kề mới hay không mà quyết định gọi đệ quy chính thủ tục này hay gọi thủ tục thêm phần tử sinh. Mã giả như sau:

$$
\begin{array}{l}
\textbf{Thuật toán }\textrm{Extend}(C,g):\\
\textbf{Đầu vào. }\textrm{Chuỗi bộ ổn định }C\textrm{ của nhóm sinh bởi }S\textrm{ và một}\\
\qquad \textrm{hoán vị }g.\\
\textbf{Đầu ra. }\textrm{Chuỗi bộ ổn định }C\textrm{ của nhóm sinh bởi }S\cup\{g\}.\\
\textbf{Phương pháp.}\\
\begin{array}{ll}
1  & \textbf{nếu }\textrm{MembershipTest}(C,g)\textrm{ thành công}\textbf{ thì}\\
2  & \qquad \textbf{trả về }C\\
3  & \textbf{kết thúc nếu}\\
4  & \textbf{nếu }C\textrm{ rỗng}\textbf{ thì}\\
5  & \qquad \beta \leftarrow \textrm{một phần tử bị }g\textrm{ di chuyển}\\
6  & \qquad C.orbit[0] \leftarrow \beta \\
7  & \qquad C.transversal[\beta] \leftarrow e\\
8  & \textbf{kết thúc nếu}\\
9  & \textrm{thêm }g\textrm{ vào }C.generators\\
10 & \textbf{với mỗi }t\in \operatorname{im}(C.transversal)\\
11 & \qquad \textrm{ExtendTransversal}(C,t\cdot g)\\
12 & \textbf{kết thúc vòng lặp}\\
13 & \textbf{trả về }C
\end{array}\\
\\
\textbf{Thuật toán con }\textrm{ExtendTransversal}(C,t):\\
\textbf{Phương pháp.}\\
\begin{array}{ll}
1  & \beta \leftarrow C.orbit[0]\\
2  & \gamma \leftarrow \beta^t\\
3  & \textbf{nếu }\gamma\notin C.orbit\textbf{ thì}\\
4  & \qquad \textrm{thêm }\gamma\textrm{ vào }C.orbit\\
5  & \qquad C.transversal[\gamma] \leftarrow t\\
6  & \qquad \textbf{với mỗi }s\in C.generators\\
7  & \qquad \qquad \textrm{ExtendTransversal}(C,t\cdot s)\\
8  & \qquad \textbf{kết thúc vòng lặp}\\
9  & \textbf{ngược lại}\\
10 & \qquad s' \leftarrow t\cdot C.transversal[\gamma]^{-1}\\
11 & \qquad C.next \leftarrow \textrm{Extend}(C.next,s')\\
12 & \textbf{kết thúc nếu}
\end{array}
\end{array}
$$

So sánh mã giả này với mục trước cho thấy nó là đúng. Hơn nữa, độ phức tạp của hai cách không khác nhau.

<span id="độ-phức-tạp"></span>
### Độ phức tạp

Để phân tích độ phức tạp của Schreier-Sims, cần một số ký hiệu. Gọi độ dài của hoán vị là $n$, kích thước tập sinh $|S|$ là $m$. Độ dài của cơ sở (không dư thừa) thu được ký hiệu là $|B|$. Ngoài ra, ở tầng thứ $i$ tính từ ngoài vào trong cuối cùng, số phần tử sinh được ký hiệu là $|S_{i-1}|$, còn kích thước hệ đại diện lớp kề (hay độ dài quỹ đạo) được ký hiệu là $|T_i|$. Sau đây phân tích độ phức tạp thời gian cần thiết cho cách cài đặt tăng dần của Schreier-Sims ở trên. Thuật toán chủ yếu gồm hai phần: sàng lọc, và tính quỹ đạo, hệ đại diện lớp kề cùng các phần tử sinh Schreier.

Các phần tử sinh đầu vào ban đầu và các phần tử sinh Schreier thu được trong thuật toán đều cần được sàng lọc, nên tổng số lần thực hiện quá trình sàng lọc là $O(\sum_{i=1}^{|B|}|S_{i-1}||T_i|+|S|)$. Một lần sàng lọc cần tính tích hoán vị với $O(|B|)$ đại diện lớp kề. Gọi thời gian tính tích với một đại diện lớp kề đơn lẻ là $\tau$. Nếu lưu trực tiếp đại diện lớp kề thì $\tau\in O(n)$; nếu dùng cây Schreier để lưu đại diện lớp kề thì $\tau\in O(n^2)$. Tổng thời gian thực hiện sàng lọc là $O(\tau|B|\sum_{i=1}^{|B|}|S_{i-1}||T_i|+\tau|B||S|)$.

Đối với việc tính quỹ đạo và các thông tin liên quan, vì đây là cách cài đặt tăng dần, mỗi cặp $(\delta,s)\in\Delta_i\times S_{i-1}$ trong không gian trạng thái chỉ được tính tối đa một lần. Khi tính quỹ đạo và hệ đại diện lớp kề, tùy cách lưu trữ mà thời gian tính một đại diện lớp kề đơn lẻ có thể là $O(n)$ hoặc $O(1)$. Tuy nhiên, dù thế nào thì nó cũng không vượt quá độ phức tạp tính phần tử sinh Schreier. Nếu lưu trực tiếp, độ phức tạp này là $O(n)$; nếu dùng cây Schreier, là $O(n^2)$. So với tổng độ phức tạp thời gian của quá trình sàng lọc, thời gian tính các thông tin này không vượt quá thời gian cần cho sàng lọc. Vì vậy, độ phức tạp thời gian của Schreier-Sims chính là kết quả ở đoạn trước: $O(\tau|B|\sum_{i=1}^{|B|}|S_{i-1}||T_i|+\tau|B||S|)$.

Về độ phức tạp không gian, cấu trúc dữ liệu cuối cùng của thuật toán lưu $O(\sum_{i=1}^{|B|}|S_{i-1}|)$ phần tử sinh và $O(\sum_{i=1}^{|B|}|T_i|)$ đại diện lớp kề. Nếu lưu trực tiếp, cả phần tử sinh lẫn đại diện lớp kề đều cần $O(n)$ bộ nhớ; nếu dùng cây Schreier, phần tử sinh cần $O(n)$ bộ nhớ, còn đại diện lớp kề chỉ cần $O(1)$ bộ nhớ.

Phần trước đã nói độ dài của chuỗi nhóm con tăng nghiêm ngặt trong nhóm đối xứng bậc $n$ là $O(n)$. Kết hợp với lập luận sàng lọc ở trên, suy ra $|B|=O(n)$ và $|S_i|=O(n)$. Do đó, nếu cài đặt Schreier-Sims bằng cách lưu trực tiếp hệ đại diện lớp kề, độ phức tạp thời gian là $O(n^5+mn^2)$ và độ phức tạp không gian là $O(n^3)$. Với trường hợp $\log|G|\in O(n)$, ước lượng tốt hơn là độ phức tạp thời gian[^knuth-complexity] $O(n^2\log^3|G|+mn\log|G|)$ và độ phức tạp không gian $O(n^2\log|G|)$. Với tập sinh ngẫu nhiên, thử nghiệm thực tế cho thấy độ phức tạp của thuật toán thấp hơn đáng kể so với $\Theta(n^5)$, xấp xỉ $\Theta(n^4)$.

Tuy so với lưu trực tiếp, cây Schreier đưa thêm một thừa số $n$ vào độ phức tạp thời gian, nhưng khi $n$ rất lớn mà bản thân nhóm nhỏ hơn nhiều so với nhóm đối xứng bậc $n$, độ phức tạp không gian của nó là $O(n\log^2|G|)$, nhỏ hơn nhiều so với $O(n^2\log|G|)$ của cách lưu trực tiếp. Tuy nhiên trong thi lập trình, rất khó gặp trường hợp dùng cây Schreier để lưu lại tốt hơn.

<span id="cài-đặt-tham-khảo"></span>
### Cài đặt tham khảo

Phần này cung cấp một cài đặt tham khảo cho Schreier-Sims. Vì $n$ tương đối nhỏ, trong cài đặt này cơ sở $B=\{n,n-1,\cdots,1\}$ được chỉ định trực tiếp thay vì để thuật toán chọn. Lợi ích là trong nhóm ở tầng thứ $k$ tính từ trong ra ngoài (không tính cấu trúc rỗng), các hoán vị chỉ thay đổi $k$ phần tử đầu, thuận tiện cho các tính toán tiếp theo. Một tối ưu khác trong mã là lưu nghịch đảo của đại diện lớp kề; cách này làm đơn giản các phép toán hoán vị.

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/schreier-sims/schreier-sims.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

-   [LOJ 177. Cấp của nhóm con sinh ra](https://loj.ac/p/177)
-   [\[WC2017\] Bàn cờ](https://uoj.ac/problem/287)
-   [Permutations](https://codeforces.com/gym/421334/problem/A)
-   [\[Grand Prix of Yekaterinburg 2015\] Problem H. Heimdall](https://disk.yandex.com/i/OfEXXcu-anMHuw)

<span id="tài-liệu-tham-khảo-và-ghi-chú"></span>
## Tài liệu tham khảo và ghi chú

-   [Thuật toán Schreier-Sims - Wikipedia](https://en.wikipedia.org/wiki/Schreier%E2%80%93Sims_algorithm)
-   [Sims, Charles C, Các phương pháp tính toán trong nghiên cứu nhóm hoán vị, Computational Problems in Abstract Algebra, pp. 169-183, Pergamon, Oxford, 1970.](https://www.sciencedirect.com/science/article/pii/B9780080129754500205)
-   [Knuth, Donald E. Biểu diễn hiệu quả nhóm hoán vị, Combinatorica 11 (1991), no. 1, 33-43.](https://arxiv.org/abs/math/9201304)
-   [Ákos Seress, Thuật toán nhóm hoán vị, Cambridge University Press](https://www.cambridge.org/core/books/permutation-group-algorithms/199629665EC545A10BCB99FFE6AAFD25)
-   [Ghi chú của Alexander Hulpke về lý thuyết nhóm tính toán](https://www.math.colostate.edu/%7Ehulpke/CGT/cgtnotes.pdf)
-   [Slide của Derek Holt về thuật toán Schreier-Sims cho nhóm hoán vị hữu hạn](https://blogs.cs.st-andrews.ac.uk/codima/files/2015/11/CoDiMa2015_Holt.pdf)
-   [Martin Jaggi, Triển khai 3 kiểu thuật toán Schreier-Sims, MAS334 - Mathematics Computing Project, 2005](https://www.m8j.net/data/List/Files-118/Documentation.pdf)
-   [Henrik Bäärnhielm. Thuật toán Schreier-Sims cho nhóm ma trận](https://henrik.baarnhielm.net/schreiersims.pdf)

[^knuth-year]: Bài báo của Knuth được xuất bản năm 1991, nhưng cải tiến của ông đã được phổ biến rộng rãi qua hội nghị từ năm 1981. Bài báo được viết dựa trên bài giảng hội nghị của ông.

[^monte-carlo]: Đừng nhầm với phương pháp Monte Carlo. Tại đây, thuật toán Monte Carlo chỉ thuật toán ngẫu nhiên có xác suất sai hằng số và có thể làm nhỏ tùy ý.

[^orbit-algo]: Bài toán này và các thuật toán trong mục này không cần giả định tác động nhóm đang xét là tác động hoán vị, nên có thể áp dụng trong các ngữ cảnh rộng hơn. Chẳng hạn, nếu áp dụng các thuật toán này cho tác động liên hợp, cũng có thể tìm quỹ đạo (lớp liên hợp), hệ đại diện lớp kề và bộ ổn định (bộ trung tâm hóa).

[^schreier-vector]: Vì cấu trúc cây này có thể cài đặt bằng một dãy con trỏ trỏ đến cha, nó cũng được gọi là vectơ Schreier.

[^schreier-lemma-unity]: Điều kiện $e\in T$ không cần thiết để bổ đề Schreier đúng.

[^upper-bound]: [Định lý Nielsen-Schreier](https://en.wikipedia.org/wiki/Nielsen%E2%80%93Schreier_theorem) nói rằng đối với [nhóm tự do](https://en.wikipedia.org/wiki/Free_group) sinh bởi $n$ phần tử sinh, một nhóm con có chỉ số $k$ của nó là nhóm tự do sinh bởi $k(n-1)+1$ phần tử sinh.

[^subgroup-chain]: Xem [Cameron, P. J., Solomon, R., & Turull, A. (1989). Chains of subgroups in symmetric groups. Journal of algebra, 127(2), 340-352.](https://www.sciencedirect.com/science/article/pii/0021869389902561)

[^siftee]: Đây không phải một thuật ngữ thật chặt chẽ; trong các tài liệu tiếng Anh khác nhau nó có thể được gọi là siftee hoặc sifted element.

[^knuth-complexity]: Cận trên trong bài báo của Knuth còn ít hơn một thừa số logarit; điều này cần ước lượng kỹ hơn độ dài các quỹ đạo cơ bản trong chuỗi bộ ổn định của nhóm.
