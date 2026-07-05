<span id="hoán-vị-sai-vị-trí"></span>
## Hoán vị sai vị trí

<span id="định-nghĩa"></span>
### Định nghĩa

Hoán vị sai vị trí (derangement) là một hoán vị mà không có phần tử nào nằm ở vị trí đúng của nó. Cụ thể, với một hoán vị $P$ của $1\sim n$, nếu $P_i\neq i$ với mọi $i$, thì $P$ được gọi là một hoán vị sai vị trí của $n$ phần tử.

Ví dụ, các hoán vị sai vị trí của 3 phần tử là $\{2,3,1\}$ và $\{3,1,2\}$. Các hoán vị sai vị trí của 4 phần tử là $\{2,1,4,3\}$, $\{2,3,4,1\}$, $\{2,4,1,3\}$, $\{3,1,4,2\}$, $\{3,4,1,2\}$, $\{3,4,2,1\}$, $\{4,1,2,3\}$, $\{4,3,1,2\}$ và $\{4,3,2,1\}$. Hoán vị sai vị trí là hoán vị không có điểm bất động, tức là không có chu trình độ dài 1.

<span id="tính-bằng-nguyên-lý-bao-hàm-loại-trừ"></span>
### Tính bằng nguyên lý bao hàm - loại trừ

Tập toàn cục $U$ là tập các hoán vị của $1\sim n$, nên $|U|=n!$; đặt $S_i$ là tập các hoán vị thỏa mãn $P_i\neq i$. Dùng bổ đề về phần bù và [nguyên lý bao hàm - loại trừ](./inclusion-exclusion-principle.md), bài toán trở thành tính:

$$
\begin{aligned}
\left|\bigcap_{i=1}^n S_i\right|
&=|U|-\left|\bigcup_{i=1}^n\overline{S_i}\right|\\
&=n!-\sum_{k=1}^n(-1)^{k-1}\sum_{a_i<a_{i+1}}\left|\bigcap_{i=1}^{k}\overline{S_{a_i}}\right|
\end{aligned}
$$

Trong đó tổng bên trong có nghĩa là chọn $a_1, a_2, \cdots, a_k$ từ $1, 2, \cdots, n$ sao cho $a_i<a_{i+1}$. Khi đó

$$
\left|\bigcap_{i=1}^{k}\overline{S_{a_i}}\right|
$$

biểu thị số hoán vị có $k$ số $a_1,a_2,\cdots,a_k$ thỏa mãn $P_{a_i}=a_i$, còn vị trí của $n-k$ số còn lại tùy ý. Vì vậy:

$$
\left|\bigcap_{i=1}^{k}\overline{S_{a_i}}\right|=(n-k)!
$$

Có $\dbinom{n}{k}$ cách chọn $k$ số này, nên sau khi lấy tổng ta có:

$$
\begin{aligned}
&\sum_{k=1}^n(-1)^{k-1}\sum_{a_i<a_{i+1}}\left|\bigcap_{i=1}^{k}\overline{S_{a_i}}\right|\\
=&\sum_{k=1}^n(-1)^{k-1}\dbinom{n}{k}(n-k)!\\
=&\sum_{k=1}^n(-1)^{k-1}\frac{n!}{k!}\\
=&n!\sum_{k=1}^n\frac{(-1)^{k-1} }{k!}
\end{aligned}
$$

Do đó số hoán vị sai vị trí của $n$ phần tử là:

$$
D_n=n!-n!\sum_{k=1}^n\frac{(-1)^{k-1} }{k!}=n!\sum_{k=0}^n\frac{(-1)^k}{k!}
$$

Một vài số hạng đầu của dãy số hoán vị sai vị trí là $0,1,2,9,44,265$ ([OEIS A000166](http://oeis.org/A000166)).

<span id="tính-bằng-truy-hồi"></span>
### Tính bằng truy hồi

Cụ thể hóa bài toán hoán vị sai vị trí, xét bài toán sau:

Có $n$ lá thư khác nhau, được đánh số $1,2,3,4,5$, cần đặt năm lá thư này vào các phong bì đánh số $1,2,3,4,5$, sao cho số trên phong bì khác với số trên lá thư. Hỏi có bao nhiêu cách đặt khác nhau?

Giả sử xét đến phong bì thứ $n$. Ban đầu tạm đặt lá thư thứ $n$ vào phong bì thứ $n$, rồi xét hai trường hợp truy hồi:

-   Toàn bộ $n-1$ phong bì phía trước đều đặt sai;
-   Trong $n-1$ phong bì phía trước có đúng một phong bì đặt đúng, còn lại đều đặt sai.

Với trường hợp thứ nhất, toàn bộ $n-1$ phong bì phía trước đều đặt sai. Vì $n-1$ phong bì đó đã sai hết, lá thư thứ $n$ chỉ cần đổi chỗ với bất kỳ vị trí nào phía trước, tổng cộng có $D_{n-1}\times (n-1)$ trường hợp.

Với trường hợp thứ hai, trong $n-1$ phong bì phía trước có một phong bì đặt đúng, còn lại đều đặt sai. Mục đích xét trường hợp này là: nếu trong $n-1$ phong bì có một phong bì chưa sai, đổi phong bì đó với phong bì thứ $n$ sẽ thu được một hoán vị sai vị trí hoàn toàn.

Các trường hợp khác không thể biến thành một hoán vị sai vị trí độ dài $n$ chỉ bằng một thao tác.

Vì vậy số hoán vị sai vị trí thỏa mãn hệ thức truy hồi:

$$
D_n=(n-1)(D_{n-1}+D_{n-2})
$$

Sau đây là một hệ thức truy hồi khác:

$$
D_n=nD_{n-1}+{(-1)}^n
$$

<span id="các-quan-hệ-khác"></span>
### Các quan hệ khác

Số hoán vị sai vị trí có một biểu thức làm tròn đơn giản; tốc độ tăng chỉ khác giai thừa bởi một hằng số:

$$
D_n=\left\lfloor\frac{n!}{\mathrm{e}} + \frac{1}{2}\right\rfloor
$$

Khi số phần tử tăng lên, xác suất $P$ để tạo thành một hoán vị sai vị trí tiến tới:

$$
P=\lim_{n\to\infty}\frac{D_n}{n!}=\frac{1}{\mathrm{e}}
$$
