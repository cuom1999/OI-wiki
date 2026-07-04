<span id="&#x5F15;&#x5165;"></span>

## Giới thiệu

Hoán vị và tổ hợp là các kiến thức cơ bản của tổ hợp. Hoán vị là việc chọn một số phần tử nhất định từ một tập phần tử cho trước rồi sắp xếp chúng theo thứ tự; tổ hợp là việc chỉ chọn một số phần tử nhất định từ tập phần tử cho trước, không xét thứ tự. Vấn đề trung tâm của hoán vị và tổ hợp là nghiên cứu tổng số khả năng sắp xếp hoặc chọn thỏa các yêu cầu đã cho. Hoán vị, tổ hợp có quan hệ chặt chẽ với xác suất cổ điển.

Trong toán sơ cấp ở trung học, các bài hoán vị tổ hợp thường được giải bằng các cách như lập bảng, liệt kê trực tiếp.

<span id="&#x52A0;&#x6CD5;-&#x4E58;&#x6CD5;&#x539F;&#x7406;"></span>

## Nguyên lý cộng và nhân

<span id="&#x52A0;&#x6CD5;&#x539F;&#x7406;"></span>

### Nguyên lý cộng

Để hoàn thành một công việc có $n$ loại cách làm, trong đó $a_i(1 \le i \le n)$ là số cách của loại thứ $i$. Khi đó có tổng cộng $S=a_1+a_2+\cdots +a_n$ cách khác nhau để hoàn thành công việc.

<span id="&#x4E58;&#x6CD5;&#x539F;&#x7406;"></span>

### Nguyên lý nhân

Để hoàn thành một công việc cần thực hiện qua $n$ bước, trong đó $a_i(1 \le i \le n)$ là số cách khác nhau để thực hiện bước thứ $i$. Khi đó có tổng cộng $S = a_1 \times a_2 \times \cdots \times a_n$ cách khác nhau để hoàn thành công việc.

<span id="&#x6392;&#x5217;&#x4E0E;&#x7EC4;&#x5408;&#x57FA;&#x7840;"></span>

## Cơ bản về hoán vị và tổ hợp

<span id="&#x6392;&#x5217;&#x6570;"></span>

### Số hoán vị

Từ $n$ phần tử khác nhau, chọn tùy ý $m$ phần tử ($m\leq n$, $m$ và $n$ đều là số tự nhiên; các phần sau cũng hiểu như vậy) và sắp thành một dãy theo một thứ tự nhất định, ta gọi đó là một hoán vị chập $m$ của $n$ phần tử khác nhau. Số tất cả các hoán vị chập $m$ ($m\leq n$) của $n$ phần tử khác nhau được gọi là số hoán vị chập $m$ của $n$ phần tử, ký hiệu $\mathrm A_n^m$ (hoặc $\mathrm P_n^m$).

Công thức tính số hoán vị:

$$
\mathrm A_n^m = n(n-1)(n-2) \cdots (n-m+1) = \frac{n!}{(n - m)!}
$$

$n!$ là giai thừa của $n$, ví dụ $6! = 1 \times 2 \times 3 \times 4 \times 5 \times 6$.

Có thể hiểu công thức như sau: chọn $m$ người trong $n$ người để xếp hàng ($m \le n$). Vị trí thứ nhất có $n$ cách chọn, vị trí thứ hai có $n-1$ cách chọn, tiếp tục như vậy, vị trí thứ $m$ (vị trí cuối) có $n-m+1$ cách chọn. Do đó:

$$
\mathrm A_n^m = n(n-1)(n-2) \cdots (n-m+1) = \frac{n!}{(n - m)!}
$$

Hoán vị toàn phần: tất cả $n$ người đều xếp hàng, độ dài hàng là $n$. Vị trí thứ nhất có $n$ cách chọn, vị trí thứ hai có $n-1$ cách chọn, tiếp tục như vậy:

$$
\mathrm A_n^n = n(n-1)(n-2) \cdots 3 \times 2 \times 1 = n!
$$

Hoán vị toàn phần là một trường hợp đặc biệt của số hoán vị.

<span id="&#x7EC4;&#x5408;&#x6570;"></span>

### Số tổ hợp

Từ $n$ phần tử khác nhau, chọn tùy ý $m \leq n$ phần tử để tạo thành một tập, ta gọi đó là một tổ hợp chập $m$ của $n$ phần tử khác nhau. Số tất cả các tổ hợp chập $m \leq n$ của $n$ phần tử khác nhau được gọi là số tổ hợp chập $m$ của $n$ phần tử, ký hiệu $\dbinom{n}{m}$, đọc là "$n$ chọn $m$".

Công thức tính số tổ hợp:

$$
\dbinom{n}{m} = \frac{\mathrm A_n^m}{m!} = \frac{n!}{m!(n - m)!}
$$

Hiểu công thức trên như thế nào? Xét việc chọn $m$ người từ $n$ người ($m \le n$), không xếp hàng, không quan tâm thứ tự. Nếu quan tâm thứ tự thì số cách là $\mathrm A_n^m$; nếu không quan tâm thứ tự thì phải chia cho số lần trùng lặp. Trùng lặp bao nhiêu lần? Cùng một nhóm $m$ người được chọn có thể được sắp xếp toàn phần theo $m!$ cách, nên:

$$
\begin{aligned}
\dbinom{n}{m} \times m! &= \mathrm A_n^m\\
\dbinom{n}{m} &= \frac{\mathrm A_n^m}{m!} = \frac{n!}{m!(n-m)!}
\end{aligned}
$$

Số tổ hợp cũng thường được ký hiệu là $\mathrm C_n^m$, tức $\displaystyle \mathrm C_n^m=\binom{n}{m}$. Hiện nay trong toán học, ký hiệu $\dbinom{n}{m}$ phổ biến hơn $\mathrm C_n^m$.

Số tổ hợp còn được gọi là "hệ số nhị thức"; phần định lý nhị thức bên dưới sẽ trình bày mối liên hệ này.

Đặc biệt, quy ước khi $m>n$ thì $\mathrm A_n^m=\dbinom{n}{m}=0$.

<span id="&#x63D2;&#x677F;&#x6CD5;"></span>

## Phương pháp thanh ngăn

Phương pháp thanh ngăn (Stars and bars) là một kỹ thuật để đếm số phương án chia nhóm các phần tử giống nhau, và cũng có thể dùng để đếm số nghiệm của một lớp phương trình bất định tuyến tính.

<span id="&#x6B63;&#x6574;&#x6570;&#x548C;&#x7684;&#x6570;&#x76EE;"></span>

### Số cách có tổng là số nguyên dương

Bài toán 1: Có $n$ phần tử **hoàn toàn giống nhau**, cần chia chúng thành $k$ nhóm, mỗi nhóm có ít nhất một phần tử. Có bao nhiêu cách chia?

Xét chèn $k - 1$ thanh ngăn vào $n - 1$ khoảng trống được tạo bởi các cặp phần tử liên tiếp trong $n$ phần tử.

Vì các phần tử hoàn toàn giống nhau, đáp án là $\dbinom{n - 1}{k - 1}$.

Bản chất là đếm số nghiệm nguyên dương của $x_1+x_2+\cdots+x_k=n$.

<span id="&#x975E;&#x8D1F;&#x6574;&#x6570;&#x548C;&#x7684;&#x6570;&#x76EE;"></span>

### Số cách có tổng là số nguyên không âm

Bài toán 2: Nếu thay đổi để mỗi nhóm được phép rỗng thì sao?

Lúc này rõ ràng không thể trực tiếp chèn thanh ngăn, vì có thể xảy ra trường hợp nhiều thanh ngăn cùng nằm trong một khoảng, rất khó tính.

Ta tạo điều kiện để chuyển về bài toán 1 có ràng buộc: mượn trước $k$ phần tử, rồi chèn thanh ngăn vào $n + k - 1$ khoảng được tạo bởi $n + k$ phần tử. Đáp án là

$$
\binom{n + k - 1}{k - 1} = \binom{n + k - 1}{n}
$$

Dù không trực tiếp giải bài toán gốc, biểu thức này chính là đáp án của bài toán gốc. Có thể hiểu như sau:

Ban đầu ta mượn $k$ phần tử để đảm bảo mỗi nhóm có ít nhất một phần tử; sau khi chèn thanh ngăn xong, lấy lại $k$ phần tử đã mượn khỏi $k$ nhóm. Vì các phần tử giống nhau, các trường hợp sau khi biến đổi và trước khi biến đổi tương ứng một-một, nên đáp án bằng nhau.

Từ đó suy ra công thức của phương pháp thanh ngăn: $\dbinom{n + k - 1}{n}$.

Bản chất là đếm số nghiệm nguyên không âm của $x_1+x_2+\cdots+x_k=n$ (tức yêu cầu $x_i \ge 0$).

<span id="&#x4E0D;&#x540C;&#x4E0B;&#x754C;&#x6574;&#x6570;&#x548C;&#x7684;&#x6570;&#x76EE;"></span>

### Số cách có tổng với các cận dưới khác nhau

Bài toán 3: Mở rộng thêm một bước, nếu yêu cầu nhóm thứ $i$ phải nhận ít nhất $a_i$ phần tử, với $\sum a_i \le n$, thì sao?

Bản chất là đếm số nghiệm của $x_1+x_2+\cdots+x_k=n$, trong đó $x_i \ge a_i$.

Tương tự trường hợp không ràng buộc, ta mượn $\sum a_i$ phần tử để đảm bảo nhóm thứ $i$ có ít nhất $a_i$ phần tử. Đặt

$$
x_i^{\prime}=x_i-a_i
$$

Thu được phương trình mới:

$$
\begin{aligned}
(x_1^{\prime}+a_1)+(x_2^{\prime}+a_2)+\cdots+(x_k^{\prime}+a_k)&=n\\
x_1^{\prime}+x_2^{\prime}+\cdots+x_k^{\prime}&=n-a_1-a_2-\cdots-a_k\\
x_1^{\prime}+x_2^{\prime}+\cdots+x_k^{\prime}&=n-\sum a_i
\end{aligned}
$$

trong đó

$$
x_i^{\prime}\ge 0
$$

Khi đó bài toán 3 được chuyển về bài toán 2; dùng trực tiếp công thức thanh ngăn, đáp án là

$$
\binom{n - \sum a_i + k - 1}{n - \sum a_i}
$$

<span id="&#x4E0D;&#x76F8;&#x90BB;&#x7684;&#x6392;&#x5217;"></span>

### Các cách chọn không kề nhau

Chọn $k$ số trong $n$ số tự nhiên $1 \sim n$ sao cho không có hai số nào kề nhau, số tổ hợp là $\dbinom {n-k+1}{k}$.

<span id="&#x4E8C;&#x9879;&#x5F0F;&#x5B9A;&#x7406;"></span>

## Định lý nhị thức

Trước khi vào phần nâng cao về hoán vị và tổ hợp, ta giới thiệu một định lý có liên quan chặt chẽ với số tổ hợp: định lý nhị thức.

Định lý nhị thức mô tả các hệ số trong khai triển:

$$
(a+b)^n=\sum_{i=0}^n\binom{n}{i}a^{n-i}b^i
$$

Có thể chứng minh bằng quy nạp toán học, sử dụng $\dbinom{n}{k}+\dbinom{n}{k-1}=\dbinom{n+1}{k}$ trong bước quy nạp.

Định lý nhị thức cũng dễ dàng mở rộng sang dạng đa thức:

Cho $n$ là số nguyên dương, $x_i$ là số thực,

$$
(x_1 + x_2 + \cdots + x_t)^n = \sum_{\substack{n_1+\cdots+n_t=n\\n_i\ge 0}} \binom{n}{n_1,n_2,\cdots,n_t} x_1^{n_1}x_2^{n_2}\cdots x_t^{n_t}
$$

Trong đó $\dbinom{n}{n_1,n_2,\cdots,n_t}$ là hệ số đa thức, và nó có tính chất tương tự:

$$
\sum{\binom{n}{n_1,n_2,\cdots,n_t}} = t^n
$$

<span id="&#x6392;&#x5217;&#x4E0E;&#x7EC4;&#x5408;&#x8FDB;&#x9636;&#x7BC7;"></span>

## Hoán vị và tổ hợp nâng cao

Tiếp theo ta giới thiệu một số biến thể của hoán vị và tổ hợp.

<span id="&#x591A;&#x91CD;&#x96C6;&#x7684;&#x6392;&#x5217;&#x6570;-&#x591A;&#x91CD;&#x7EC4;&#x5408;&#x6570;"></span>

### Số hoán vị của đa tập | Hệ số đa thức

Cần phân biệt rõ **hệ số đa thức** với **số tổ hợp của đa tập**. Hai khái niệm này hoàn toàn khác nhau.

Đa tập là một tập tổng quát có thể chứa các phần tử lặp. Đặt $S=\{n_1\cdot a_1,n_2\cdot a_2,\cdots,n_k\cdot a_k\}$ là đa tập gồm $n_1$ phần tử $a_1$, $n_2$ phần tử $a_2$, ..., $n_k$ phần tử $a_k$. Số hoán vị toàn phần của $S$ là

$$
\frac{n!}{\prod_{i=1}^kn_i!}=\frac{n!}{n_1!n_2!\cdots n_k!}
$$

Tương đương với việc chia bỏ số hoán vị của các phần tử giống nhau. Cụ thể, có thể xem ta có $k$ loại bóng khác nhau, mỗi loại có lần lượt $n_1,n_2,\cdots,n_k$ quả, và $n=n_1+n_2+\ldots+n_k$. Số hoán vị toàn phần của $n$ quả bóng này chính là **số hoán vị của đa tập**. Số hoán vị của đa tập thường được gọi là **hệ số đa thức**. Ta có thể dùng ký hiệu hệ số đa thức để biểu diễn công thức trên:

$$
\binom{n}{n_1,n_2,\cdots,n_k}=\frac{n!}{\prod_{i=1}^kn_i!}
$$

Có thể thấy $\dbinom{n}{m}$ tương đương với $\dbinom{n}{m,n-m}$, nhưng cách viết sau dài dòng hơn nên thường không dùng.

<span id="&#x591A;&#x91CD;&#x96C6;&#x7684;&#x7EC4;&#x5408;&#x6570;-1"></span>

### Số tổ hợp của đa tập 1

Đặt $S=\{n_1\cdot a_1,n_2\cdot a_2,\cdots,n_k\cdot a_k\}$ là đa tập gồm $n_1$ phần tử $a_1$, $n_2$ phần tử $a_2$, ..., $n_k$ phần tử $a_k$. Với số nguyên $r(r<n_i,\forall i\in[1,k])$, số cách chọn $r$ phần tử từ $S$ để tạo thành một đa tập chính là **số tổ hợp của đa tập**. Bài toán này tương đương với số nghiệm nguyên không âm của $x_1+x_2+\cdots+x_k=r$, có thể giải bằng phương pháp thanh ngăn, đáp án là

$$
\binom{r+k-1}{k-1}
$$

<span id="&#x591A;&#x91CD;&#x96C6;&#x7684;&#x7EC4;&#x5408;&#x6570;-2"></span>

### Số tổ hợp của đa tập 2

Xét bài toán: đặt $S=\{n_1\cdot a_1,n_2\cdot a_2,\cdots,n_k\cdot a_k,\}$ là đa tập gồm $n_1$ phần tử $a_1$, $n_2$ phần tử $a_2$, ..., $n_k$ phần tử $a_k$. Với số nguyên dương $r$, cần đếm số cách chọn $r$ phần tử từ $S$ để tạo thành một đa tập.

Lúc này số lượng phần tử mỗi loại được chọn bị giới hạn. Tương tự, ta có thể chuyển bài toán này thành việc giải phương trình tuyến tính có ràng buộc:

$$
\forall i\in [1,k],\ x_i\le n_i,\ \sum_{i=1}^kx_i=r
$$

Khi đó nguyên lý bao hàm-loại trừ xuất hiện rất tự nhiên. Mô hình bao hàm-loại trừ như sau:

1.  Tập vũ trụ: các nghiệm nguyên không âm của $\displaystyle \sum_{i=1}^kx_i=r$.
2.  Thuộc tính: $x_i\le n_i$.

Đặt tập thỏa thuộc tính $i$ là $S_i$, $\overline{S_i}$ là tập không thỏa thuộc tính $i$, tức tập thỏa $x_i\ge n_i+1$ (chuyển về bài toán 3 của phương pháp thanh ngăn ở trên). Khi đó đáp án là

$$
\left|\bigcap_{i=1}^kS_i\right|=|U|-\left|\bigcup_{i=1}^k\overline{S_i}\right|
$$

Theo nguyên lý bao hàm-loại trừ:

$$
\begin{aligned}
\left|\bigcup_{i=1}^k\overline{S_i}\right|
=&\sum_i\left|\overline{S_i}\right|
-\sum_{i,j}\left|\overline{S_i}\cap\overline{S_j}\right|
+\sum_{i,j,k}\left|\overline{S_i}\cap\overline{S_j}\cap\overline{S_k}\right|
-\cdots\\
&+(-1)^{k-1}\left|\bigcap_{i=1}^k\overline{S_i}\right|\\
=&\sum_i\binom{k+r-n_i-2}{k-1}
-\sum_{i,j}\binom{k+r-n_i-n_j-3}{k-1}+\sum_{i,j,k}\binom{k+r-n_i-n_j-n_k-4}{k-1}
-\cdots\\
&+(-1)^{k-1}\binom{k+r-\sum_{i=1}^kn_i-k-1}{k-1}
\end{aligned}
$$

Lấy tập vũ trụ $\displaystyle |U|=\binom{k+r-1}{k-1}$ trừ biểu thức trên, ta thu được số tổ hợp của đa tập:

$$
Ans=\sum_{p=0}^k(-1)^p\sum_{A}\binom{k+r-1-\sum_{A} n_{A_i}-p}{k-1}
$$

Trong đó $A$ đóng vai trò tập con đang được liệt kê, thỏa $|A|=p,\ A_i<A_{i+1}$.

<span id="&#x5706;&#x6392;&#x5217;"></span>

### Hoán vị vòng tròn

Cho $n$ người đứng thành một vòng tròn, số cách sắp xếp được ký hiệu $\mathrm Q_n^n$. Xét một vòng tròn đã sắp xếp xong; nếu cắt vòng tròn tại các vị trí khác nhau, ta lại thu được các hàng dọc khác nhau.
Do đó

$$
\mathrm Q_n^n \times n = \mathrm A_n^n \Longrightarrow \mathrm Q_n = \frac{\mathrm A_n^n}{n} = (n-1)!
$$

Từ đó suy ra công thức cho hoán vị vòng tròn chập một phần:

$$
\mathrm Q_n^r = \frac{\mathrm A_n^r}{r} = \frac{n!}{r \times (n-r)!}
$$

<span id="&#x7EC4;&#x5408;&#x6570;&#x6027;&#x8D28;-&#x4E8C;&#x9879;&#x5F0F;&#x63A8;&#x8BBA;"></span><span id="tinh-chat-cua-so-to-hop-he-qua-nhi-thuc"></span>

## Tính chất của số tổ hợp | Hệ quả nhị thức

Vì số tổ hợp rất quan trọng trong OI, phần này giới thiệu một số tính chất của chúng.

$$
\binom{n}{m}=\binom{n}{n-m}\tag{1}
$$

Tương đương với việc lấy phần bù của tập được chọn trong tập vũ trụ, nên giá trị không đổi. (Tính đối xứng)

$$
\binom{n}{k} = \frac{n}{k} \binom{n-1}{k-1}\tag{2}
$$

Hệ thức truy hồi suy ra từ định nghĩa.

$$
\binom{n}{m}=\binom{n-1}{m}+\binom{n-1}{m-1}\tag{3}
$$

Hệ thức truy hồi của số tổ hợp (cách biểu diễn công thức của tam giác Pascal). Có thể dùng công thức này để suy ra các số tổ hợp với độ phức tạp $O(n^2)$.

$$
\binom{n}{0}+\binom{n}{1}+\cdots+\binom{n}{n}=\sum_{i=0}^n\binom{n}{i}=2^n\tag{4}
$$

Đây là trường hợp đặc biệt của định lý nhị thức. Lấy $a=b=1$ sẽ thu được hệ thức trên.

$$
\sum_{i=0}^n(-1)^i\binom{n}{i}=[n=0]\tag{5}
$$

Đây là một trường hợp đặc biệt khác của định lý nhị thức, lấy $a=1, b=-1$. Trường hợp riêng của công thức là khi $n=0$, đáp án bằng $1$.

$$
\sum_{i=0}^k \binom{n}{i}\binom{m}{k-i} = \binom{m+n}{k}\tag{6}
$$

Đây là công thức tách số tổ hợp, thường dùng khi xử lý một số bài về cấu trúc dữ liệu. Nó được gọi là [đồng nhất thức Vandermonde](https://en.wikipedia.org/wiki/Vandermonde%27s_identity).

$$
\sum_{i=0}^n\binom{n}{i}^2=\binom{2n}{n}\tag{7}
$$

Đây là trường hợp đặc biệt của $(6)$, chỉ cần lấy $n=k=m$.

$$
\sum_{i=0}^ni\binom{n}{i}=n2^{n-1}\tag{8}
$$

Một công thức tổng có trọng số; có thể chứng minh bằng cách lấy đạo hàm hàm đa thức tương ứng với $(4)$.

$$
\sum_{i=0}^ni^2\binom{n}{i}=n(n+1)2^{n-2}\tag{9}
$$

Tương tự công thức trên, có thể chứng minh bằng đạo hàm hàm đa thức.

$$
\sum_{l=0}^n\binom{l}{k} = \binom{n+1}{k+1}\tag{10}
$$

Có thể chứng minh bằng phân tích tổ hợp, xét từng tập con kích thước $k+1$ của $S=\{a_1, a_2, \cdots, a_{n+1}\}$. Công thức này khá thường dùng trong chứng minh đồng nhất thức, và được gọi là [đồng nhất thức hockey-stick](https://en.wikipedia.org/wiki/Hockey-stick_identity).

$$
\binom{n}{r}\binom{r}{k} = \binom{n}{k}\binom{n-k}{r-k}\tag{11}
$$

Có thể chứng minh bằng định nghĩa.

$$
\sum_{i=0}^n\binom{n-i}{i}=F_{n+1}\tag{12}
$$

Trong đó $F$ là dãy Fibonacci.

$$
\binom{n+k}{k}^2=\sum_{j=0}^k\binom{k}{j}^2\binom{n+2k-j}{2k}\tag{13}
$$

Có thể chứng minh bằng $(6)$. Công thức này được gọi là [đồng nhất thức Li Shanlan](https://en.wikipedia.org/wiki/Li_Shanlan_identity).

<span id="&#x4E8C;&#x9879;&#x5F0F;&#x53CD;&#x6F14;"></span>

## Nghịch đảo nhị thức

Ký hiệu $f_n$ là số phương án tạo một cấu trúc nhất định bằng đúng $n$ phần tử khác nhau, và $g_n$ là tổng số phương án tạo cấu trúc đó bằng cách chọn $i \geq 0$ phần tử từ $n$ phần tử khác nhau.

Nếu biết $f_n$ và cần tính $g_n$, rõ ràng có:

$$
g_n = \sum_{i = 0}^{n} \binom{n}{i} f_i
$$

Nếu biết $g_n$ và cần tính $f_n$, thì:

$$
f_n = \sum_{i = 0}^{n} \binom{n}{i} (-1)^{n-i} g_i
$$

Quá trình tính $f_n$ từ $g_n$ như trên được gọi là **nghịch đảo nhị thức**.

<span id="&#x8BC1;&#x660E;"></span>

### Chứng minh

Khai triển $g_i$ trong công thức nghịch đảo:

$$
\begin{aligned}
f_n &= \sum_{i = 0}^{n} \binom{n}{i} (-1)^{n-i} \left[\sum_{j = 0}^{i} \binom{i}{j} f_j\right] \\
&= \sum_{i = 0}^{n}\sum_{j = 0}^{i}\binom{n}{i}\binom{i}{j} (-1)^{n-i}f_j
\end{aligned}
$$

Liệt kê $j$ trước, rồi liệt kê $i$, ta được:

$$
\begin{aligned}
f_n &= \sum_{j = 0}^{n}\sum_{i = j}^{n}\binom{n}{i}\binom{i}{j} (-1)^{n-i}f_j \\
&= \sum_{j = 0}^{n}f_j\sum_{i = j}^{n}\binom{n}{i}\binom{i}{j} (-1)^{n-i}
\end{aligned}
$$

Dùng công thức (11) trong phần [Tính chất của số tổ hợp | Hệ quả nhị thức](#tinh-chat-cua-so-to-hop-he-qua-nhi-thuc), ta được:

$$
\begin{aligned}
f_n &= \sum_{j = 0}^{n}f_j\sum_{i = j}^{n}\binom{n}{j}\binom{n - j}{i - j} (-1)^{n-i} \\
&= \sum_{j = 0}^{n}\binom{n}{j}f_j\sum_{i = j}^{n}\binom{n - j}{i - j} (-1)^{n-i}
\end{aligned}
$$

Đặt $k = i - j$. Khi đó $i = k + j$, biểu thức trên trở thành:

$$
f_n = \sum_{j = 0}^{n}\binom{n}{j}f_j\sum_{k = 0}^{n - j}\binom{n - j}{k} (-1)^{n-j-k}1^{k}
$$

Dùng công thức (5) trong phần [Tính chất của số tổ hợp | Hệ quả nhị thức](#tinh-chat-cua-so-to-hop-he-qua-nhi-thuc), ta được:

$$
f_n = \sum_{j = 0}^{n}\binom{n}{j}f_j[n = j] = f_n
$$

Chứng minh hoàn tất.
