author: Peanut-Tang, Early0v0, Vxlimo, GHLinZhengyu, 1196131597

Thuật toán Meissel–Lehmer là một thuật toán có thể tính số lượng số nguyên tố trong đoạn $1\sim n$ với độ phức tạp thời gian dưới tuyến tính.

<span id="quy-ước-ký-hiệu"></span>
## Quy ước ký hiệu

$\left[x\right]$ biểu thị kết quả làm tròn xuống của $x$.\
$p_k$ biểu thị số nguyên tố thứ $k$, với $p_1=2$.\
$\pi\left(x\right)$ biểu thị số lượng số nguyên tố trong phạm vi $1\sim x$.\
$\mu\left(x\right)$ biểu thị hàm Möbius.\
Với tập hợp $S$, $\# S$ biểu thị kích thước của tập hợp $S$.\
$\delta\left(x\right)$ biểu thị thừa số nguyên tố nhỏ nhất của $x$.\
$P^+\left(x\right)$ biểu thị thừa số nguyên tố lớn nhất của $x$.

<span id="dùng-thuật-toán-meissellehmer-để-tính-πx"></span>
## Dùng thuật toán Meissel–Lehmer để tính π(x)

Định nghĩa $\phi\left(x,a\right)$ là số lượng số nguyên dương không vượt quá $x$ mà mọi thừa số nguyên tố của chúng đều lớn hơn $p_a$, tức là:

$$
\phi\left(x,a\right)=\#\big\{n\le x\mid n\bmod p=0 \implies p>p_a\big\}\tag{1}
$$

Tiếp theo, định nghĩa $P_k\left(x,a\right)$ là số lượng số nguyên dương không vượt quá $x$ có đúng $k$ thừa số nguyên tố tính cả bội số, và mọi thừa số nguyên tố đều lớn hơn $p_a$, tức là:

$$
P_k\left(x,a\right)=\#\big\{n\le x\mid n=q_1q_2\cdots q_k \implies \forall i,q_i>p_a\big\}\tag{2}
$$

Đặc biệt, định nghĩa $P_0\left(x,a\right)=1$, khi đó có:

$$
\phi\left(x,a\right)=P_0\left(x,a\right)+P_1\left(x,a\right)+\cdots+P_k\left(x,a\right)+\cdots
$$

Tổng vô hạn này có thể biểu diễn thành tổng hữu hạn, vì khi $p_a^k>x$ thì $P_k\left(x,a\right)=0$.

Đặt $y$ là một số nguyên thỏa mãn $x^{1/3}\le y\le x^{1/2}$, và ký hiệu $a=\pi\left(y\right)$.

Khi $k\ge 3$, có $P_1\left(x,a\right)=\pi\left(x\right)-a$ và $P_k\left(x,a\right)=0$, từ đó suy ra:

$$
\pi\left(x\right)=\phi\left(x,a\right)+a-1-P_2\left(x,a\right)\tag{3}
$$

Như vậy, việc tính $\pi\left(x\right)$ có thể chuyển thành việc tính $\phi\left(x,a\right)$ và $P_2\left(x,a\right)$.

<span id="tính-p₂xa"></span>
## Tính P₂(x,a)

Từ đẳng thức $\left(2\right)$, suy ra $P_2\left(x,a\right)$ bằng số lượng cặp số nguyên tố $\left(p,q\right)$ thỏa mãn $y<p\le q$ và $pq\le x$.

Trước hết, lưu ý rằng $p\in \left[y+1,\sqrt{x}\right]$. Ngoài ra, với mỗi $p$, có $q\in\left[p,x/p\right]$. Do đó:

$$
P_2\left(x,a\right)=\sum_{y<p\le \sqrt{x}}{\left(\pi\left(\dfrac{x}{p}\right)-\pi\left(p\right)+1\right)}\tag{4}
$$

Khi $p\in \left[y+1,\sqrt{x}\right]$, có $\dfrac{x}{p}\in \left[1,\dfrac{x}{y}\right]$. Vì vậy, có thể sàng khoảng $\left[1,\dfrac{x}{y}\right]$, rồi tính $\pi\left(\dfrac{x}{p}\right)-\pi\left(p\right)+1$ cho tất cả số nguyên tố $p\in \left[y+1,\sqrt{x}\right]$. Để giảm độ phức tạp không gian của thuật toán trên, có thể xét chia khối với độ dài khối là $L$. Nếu độ dài khối $L=y$, thì có thể tính $P_2\left(x,a\right)$ trong độ phức tạp thời gian $O\left(\dfrac{x}{y}\log{\log{x}}\right)$ và độ phức tạp không gian $O\left(y\right)$.

<span id="tính-ϕxa"></span>
## Tính ϕ(x,a)

Với $b\le a$, xét tất cả số nguyên dương không vượt quá $x$ mà mọi thừa số nguyên tố của nó đều lớn hơn $p_{b-1}$. Các số này có thể chia thành hai loại:

1.  Chia hết cho $p_b$;
2.  Không chia hết cho $p_b$.

Có $\phi\left(\dfrac{x}{p_b},b-1\right)$ số thuộc loại $1$, và có $\phi\left(x,b\right)$ số thuộc loại thứ hai.

Do đó rút ra kết luận:

> **Định lý $5.1$:** Hàm $\phi$ thỏa mãn các tính chất sau
>
> $$
> \phi\left(u,0\right)=\left[u\right]\tag{5}
> $$
>
> $$
> \phi\left(x,b\right)=\phi\left(x,b-1\right)-\phi\left(\dfrac{x}{p_b},b-1\right)\tag{6}
> $$

Một cách đơn giản để tính $\phi\left(x,a\right)$ có thể suy ra từ định lý này: lặp lại việc dùng đẳng thức $\left(6\right)$ cho đến khi cuối cùng thu được $\phi\left(u,0\right)$. Quá trình này có thể xem như tạo một cây nhị phân có gốc bắt đầu từ nút $\phi\left(x,a\right)$; hình $1$ minh họa quá trình đó. Từ đó thu được công thức sau:

$$
\phi\left(x,a\right)=\sum_{\substack{1\le n\le x\\ P^+\left(n\right)\le y}}{\mu\left(n\right)\left[x/n\right]}
$$

$$
\begin{gathered}
\begin{matrix}&&\phi\left(x,a\right)&&\\
&\swarrow&&\searrow&\\
&\phi\left(x,a-1\right)&&-\phi\left(\frac{x}{p_a},a-1\right)&\\
\swarrow&\downarrow&&\downarrow&\searrow\\
\phi\left(x,a-2\right)&\phi\left(\frac{x}{p_{a-1}},a-2\right)&&-\phi\left(\frac{x}{p_a},a-2\right)&\phi\left(\frac{x}{p_ap_{a-1}},a-2\right)\end{matrix}\\
\vdots\\
\end{gathered}
$$

Hình trên biểu diễn cây nhị phân trong quá trình tính $\phi\left(x,a\right)$: tổng trọng số của các nút lá chính là $\phi\left(x,a\right)$.

Tuy nhiên, cách này cần tính quá nhiều thứ. Vì $y\geq x^{1/3}$, riêng việc tính các số là tích của $3$ số nguyên tố không vượt quá $y$ theo cách này đã tạo ra ít nhất $\dfrac{x}{\log^3 x}$ hạng, nên không thể đáp ứng yêu cầu về độ phức tạp.

Để hạn chế cây nhị phân này "phát triển", thay đổi điều kiện dừng ban đầu. Điều kiện dừng ban đầu là:

> **Điều kiện dừng $1$:** Nếu $b=0$, thì không tiếp tục gọi đẳng thức $\left(6\right)$ trên nút $\mu\left(n\right)\phi\left(\dfrac xn,b\right)$.

Thay điều kiện này bằng điều kiện dừng mạnh hơn:

> **Điều kiện dừng $2$:** Nếu thỏa mãn một trong $2$ điều kiện dưới đây, thì không tiếp tục gọi đẳng thức $\left(6\right)$ trên nút $\mu\left(n\right)\phi\left(\dfrac xn,b\right)$:
>
> 1.  $b=0$ và $n\le y$;
> 2.  $n>y$.

Theo **điều kiện dừng $2$**, chia các lá trên cây nhị phân ban đầu thành hai loại:

1.  Nếu nút lá $\mu\left(n\right)\phi\left(\dfrac xn,b\right)$ thỏa mãn $n\le y$, thì gọi loại nút lá này là **lá thông thường**;
2.  Nếu nút lá $\mu\left(n\right)\phi\left(\dfrac xn,b\right)$ thỏa mãn $n>y$ và $n=mp_b\left(m\le y\right)$, thì gọi loại nút này là **lá đặc biệt**.

Từ đó có:

> **Định lý $5.2$:** Có:
>
> $$
> \phi\left(x,a\right)=S_0+S\tag{7}
> $$
>
> Trong đó $S_0$ biểu thị đóng góp của **lá thông thường**:
>
> $$
> S_0=\sum_{n\le y}{\mu\left(n\right)\left[\dfrac xn\right]}\tag{8}
> $$
>
> $S$ biểu thị đóng góp của **lá đặc biệt**:
>
> $$
> S=\sum_{n/\delta\left(n\right)\le y\le n}{\mu\left(n\right)\phi\left(\dfrac{x}{n},\pi\left(\delta\left(n\right)\right)-1 \right)}\tag{9}
> $$

Việc tính $S_0$ có thể giải quyết trong độ phức tạp thời gian $O\left(y\log{\log x}\right)$; tiếp theo xét cách tính $S$.

<span id="tính-s"></span>
## Tính S

Có:

$$
S=-\sum_{p\le y}{\ \sum_{\substack{\delta\left(m\right)>p\\ m\le y<mp}}{\mu\left(m\right)\phi\left(\dfrac{x}{mp},\pi\left(p\right)-1\right)}}\tag{10}
$$

Viết lại đẳng thức này thành:

$$
S=S_1+S_2+S_3
$$

Trong đó:

$$
S_1=-\sum_{x^{1/3}<p\le y}{\ \sum_{\substack{\delta\left(m\right)>p\\ m\le y<mp}}{\mu\left(m\right)\phi\left(\dfrac{x}{mp},\pi\left(p\right)-1\right)}}
$$

$$
S_2=-\sum_{x^{1/4}<p\le x^{1/3}}{\ \sum_{\substack{\delta\left(m\right)>p\\ m\le y<mp}}{\mu\left(m\right)\phi\left(\dfrac{x}{mp},\pi\left(p\right)-1\right)}}
$$

$$
S_3=-\sum_{p\le x^{1/4}}{\ \sum_{\substack{\delta\left(m\right)>p\\ m\le y<mp}}{\mu\left(m\right)\phi\left(\dfrac{x}{mp},\pi\left(p\right)-1\right)}}
$$

Lưu ý rằng trong các tổng dùng để tính $S_1,S_2$, các $m$ xuất hiện đều là số nguyên tố. Chứng minh như sau:

> Nếu không phải vậy, vì $\delta\left(m\right)>p>x^{1/4}$ nên $m>p^2>\sqrt{x}$, mâu thuẫn với $m\le y$. Do đó mệnh đề ban đầu đúng.

Hơn nữa, khi $mp>x^{1/2}\ge y$ thì $y\le mp$. Vì vậy có:

$$
S_1=\sum_{x^{1/3}<p\le y}{\ \sum_{p<q\le y}{\phi\left(\dfrac{x}{pq},\pi\left(p\right)-1\right)}}
$$

$$
S_2=\sum_{x^{1/4}<p\le x^{1/3}}{\ \sum_{p<q\le y}{\phi\left(\dfrac{x}{pq},\pi\left(p\right)-1\right)}}
$$

<span id="tính-s₁"></span>
### Tính S₁

Vì:

$$
\dfrac{x}{pq}<x^{1/3}<p
$$

nên:

$$
\phi\left(\dfrac{x}{pq},\pi\left(p\right)-1\right)=1
$$

Do đó mọi hạng trong tổng tính $S_1$ đều bằng $1$. Nghĩa là thực chất cần tính số lượng cặp số nguyên tố $\left(p,q\right)$ thỏa mãn $x^{1/3}<p<q\le y$.

Vì vậy:

$$
S_1=\dfrac{\left(\pi\left(y\right)-\pi\left(x^{1/3}\right)\right)\left(\pi\left(y\right)-\pi\left(x^{1/3}\right)-1\right)}{2}
$$

Với đẳng thức này, có thể tính $S_1$ trong thời gian $O\left(1\right)$.

<span id="tính-s₂"></span>
### Tính S₂

Có:

$$
S_2=\sum_{x^{1/4}<p\le x^{1/3}}{\ \sum_{p<q\le y}{\phi\left(\dfrac{x}{pq},\pi\left(p\right)-1\right)}}
$$

Chia $S_2$ thành hai phần $q>\dfrac x{p^2}$ và $q\le \dfrac x{p^2}$:

$$
S_2=U+V
$$

Trong đó:

$$
U=\sum_{x^{1/4}<p\le x^{1/3}}{\ \sum_{\substack{p<q<y\\q>x/p^2}}{\phi\left(\dfrac{x}{pq},\pi\left(p\right)-1 \right)}}
$$

$$
V=\sum_{x^{1/4}<p\le x^{1/3}}{\ \sum_{\substack{p<q<y\\q\le x/p^2}}{\phi\left(\dfrac{x}{pq},\pi\left(p\right)-1 \right)}}
$$

<span id="tính-u"></span>
### Tính U

Từ $q>\dfrac x{p^2}$ suy ra $p^2>\dfrac xq\le \dfrac xy$, nên $p>\sqrt{\dfrac xy}$. Do đó:

$$
U=\sum_{\sqrt{x/y}<p\le x^{1/3}}{\ \sum_{\substack{p<q\le y\\q>x/p^2}}{\phi\left(\dfrac{x}{pq},\pi\left(p\right)-1 \right)}}
$$

Suy ra:

$$
U=\sum_{\sqrt{x/y}<p\le x^{1/3}}{\#\left\{q\mid \dfrac x{p^2}<q\le y \right\}}
$$

Do đó:

$$
U=\sum_{\sqrt{x/y}<p\le x^{1/3}}{\left(\pi\left(y\right)-\pi\left(\dfrac{x}{p^2} \right) \right)}
$$

Vì $\dfrac x{p^2}<y$, có thể tiền xử lý tất cả giá trị $\pi\left(t\right)\left(t\le y\right)$, nhờ đó tính được $U$ trong độ phức tạp thời gian $O\left(y\right)$.

<span id="tính-v"></span>
### Tính V

Với mỗi hạng trong tổng tính $V$, đều có $p\le \dfrac{x}{pq}<x^{1/2}<p^2$. Do đó:

$$
\phi\left(\dfrac{x}{pq},\pi\left(p\right)-1 \right)=1+\pi\left(\dfrac{x}{pq} \right)-\left(\pi\left(p\right)-1\right)=2-\pi\left(p\right)+\pi\left(\dfrac{x}{pq} \right)
$$

Vì vậy $V$ có thể được biểu diễn thành:

$$
V=V_1+V_2
$$

Trong đó:

$$
V_1=\sum_{x^{1/4}<p\le x^{1/3}}{\ \sum_{p<q\le \min\left(x/p^2,y\right)}{\left(2-\pi\left(p\right)\right)}}
$$

$$
V_2=\sum_{x^{1/4}<p\le x^{1/3}}{\ \sum_{p<q\le \min\left(x/p^2,y\right)}{\pi\left(\dfrac{x}{pq} \right)}}
$$

Sau khi tiền xử lý $\pi\left(t\right)\left(t\le y\right)$, có thể tính $V_1$ trong độ phức tạp thời gian $O\left(x^{1/3}\right)$.

Xét cách tăng tốc quá trình tính $V_2$. Có thể tách đóng góp của $q$ thành các khoảng mà trên mỗi khoảng, $\pi\left(\dfrac{x}{pq} \right)$ là hằng số; như vậy chỉ cần tính độ dài của từng khoảng và lượng thay đổi của $\pi\left(\dfrac{x}{pq} \right)$ khi chuyển từ khoảng này sang khoảng kế tiếp.

Chính xác hơn, trước hết chia $V_2$ thành hai phần để đơn giản hóa điều kiện phức tạp $q\le \min\left(\dfrac x{p^2},y\right)$:

$$
V_2=\sum_{x^{1/4}<p\le \sqrt{x/y}}{\ \sum_{p<q\le y}{\pi\left(\dfrac{x}{pq} \right)}}+\sum_{\sqrt{x/y}<p\le x^{1/3}}{\ \sum_{p<q\le x/p^2}{\pi\left(\dfrac{x}{pq} \right)}}
$$

Sau đó viết lại biểu thức này thành:

$$
V_2=W_1+W_2+W_3+W_4+W_5
$$

Trong đó:

$$
W_1=\sum_{x^{1/4}<p\le x/y^2}{\ \sum_{p<q\le y}{\pi\left(\dfrac{x}{pq} \right)}}
$$

$$
W_2=\sum_{x/y^2<p\le \sqrt{x/y}}{\ \sum_{p<q\le \sqrt{x/p}}{\pi\left(\dfrac{x}{pq} \right)}}
$$

$$
W_3=\sum_{x/y^2<p\le \sqrt{x/y}}{\ \sum_{\sqrt{x/p}<q\le y}{\pi\left(\dfrac{x}{pq} \right)}}
$$

$$
W_4=\sum_{\sqrt{x/y}<p\le x^{1/3}}{\ \sum_{p<q\le \sqrt{x/p}}{\pi\left(\dfrac{x}{pq} \right)}}
$$

$$
W_5=\sum_{\sqrt{x/y}<p\le x^{1/3}}{\ \sum_{\sqrt{x/p}<q\le x/p^2}{\pi\left(\dfrac{x}{pq} \right)}}
$$

<span id="tính-w₁-và-w₂"></span>
#### Tính W₁ và W₂

Để tính hai giá trị này, cần tính các giá trị $\pi\left(\dfrac{x}{pq} \right)$ thỏa mãn $y<\dfrac{x}{pq}<x^{1/2}$. Có thể sàng phân khối trên khoảng $[1,\sqrt x]$. Trong mỗi khối, cộng dồn $\pi\left(\dfrac x{pq}\right)$ cho tất cả $(p,q)$ thỏa mãn điều kiện.

<span id="tính-w₃"></span>
#### Tính W₃

Với mỗi $p$, chia $q$ thành nhiều khoảng sao cho trong mỗi khoảng, $\pi\left(\dfrac x{pq}\right)$ là hằng số; đóng góp của mỗi khoảng đều có thể tính trong $O(1)$. Khi thu được một $q$ mới, dùng bảng giá trị $\pi(t)$ với $t\leq y$ để tính $\pi\left(\dfrac x{pq}\right)$. Bằng danh sách số nguyên tố không vượt quá $y$, có thể tìm $t$ sao cho $\pi(t)<\pi(t+1)=\pi\left(\dfrac x{pq}\right)$. Từ đó tiếp tục tìm giá trị $q$ kế tiếp làm $\pi\left(\dfrac x{pq}\right)$ thay đổi.

<span id="tính-w₄"></span>
#### Tính W₄

So với $W_3$, trong $W_4$ giá trị $q$ nhỏ hơn, nên $\pi\left(\dfrac x{pq}\right)$ thay đổi nhanh hơn. Lúc này nếu vẫn dùng cách tính $W_3$ cho $W_4$ thì không còn lợi thế nào đáng kể. Vì vậy trực tiếp duyệt tất cả cặp $(p,q)$ để tính $W_4$.

<span id="tính-w₅"></span>
#### Tính W₅

Tính $W_5$ tương tự như cách tính $W_3$.

<span id="tính-s₃"></span>
## Tính S₃

Dùng tất cả số nguyên tố nhỏ hơn $x^{1/4}$ để sàng một lần khoảng $\left[1,\dfrac xy\right]$. Khi phép sàng đi tới $p_k$, đã tính được các giá trị $-\mu(m)\phi\left(\dfrac{x}{mp_k},k-1 \right)$ cho mọi $m$ thỏa mãn không chứa thừa số chính phương và $\delta(m)>p_k$. Phép sàng này được thực hiện theo phân khối; trong khoảng đang sàng, duy trì một cây nhị phân để cập nhật theo thời gian thực các kết quả trung gian sau khi sàng đến một số nguyên tố cho trước. Như vậy, chỉ cần độ phức tạp thời gian $O(\log x)$ để tìm số lượng các số chưa bị sàng khi phép sàng đi tới một giá trị nào đó.

<span id="độ-phức-tạp-thời-gian-và-không-gian-của-thuật-toán"></span>
## Độ phức tạp thời gian và không gian của thuật toán

Độ phức tạp thời gian và không gian bị ảnh hưởng bởi $3$ quá trình sau:

1.  Tính $P_2\left(x,a\right)$;
2.  Tính $W_1,W_2,W_3,W_4,W_5$;
3.  Tính $S_3$.

<span id="độ-phức-tạp-khi-tính-p₂xy"></span>
### Độ phức tạp khi tính P₂(x,y)

Như đã biết, quá trình này có độ phức tạp thời gian $O\left(\dfrac{x}{y}\log{\log x}\right)$ và độ phức tạp không gian $O\left(y\right)$.

<span id="độ-phức-tạp-khi-tính-w₁w₂w₃w₄w₅"></span>
### Độ phức tạp khi tính W₁,W₂,W₃,W₄,W₅

Phép sàng theo khối độ dài $y$ dùng để tính $W_1,W_2$ có độ phức tạp thời gian $O\left(\sqrt{x}\log{\log x}\right)$ và độ phức tạp không gian $O\left(y\right)$.

Độ phức tạp thời gian cần để tính $W_1$ là:

$$
\pi\left(\dfrac{x}{y^2} \right)\pi\left(y\right)=O\left(\dfrac{x}{y\log^2 x} \right)
$$

Độ phức tạp thời gian khi tính $W_2$ là:

$$
O\left(\sum_{x/y^2<p\le \sqrt{x/y}}{\pi\left(\sqrt{\dfrac xp}\right)} \right)=O\left(\dfrac{x^{3/4}}{y^{1/4}\log^2 x} \right)
$$

Do đó, độ phức tạp thời gian khi tính $W_3$ là:

$$
O\left(\sum_{x/y^2<p\le \sqrt{x/y}}{\pi\left(\sqrt{\dfrac xp}\right)} \right)=O\left(\dfrac{x^{3/4}}{y^{1/4}\log^2 x} \right)
$$

Độ phức tạp thời gian khi tính $W_4$ là:

$$
O\left(\sum_{\sqrt{x/y}<p\le x^{1/3}}{\pi\left(\sqrt{\dfrac xp}\right)} \right)=O\left(\dfrac{x^{2/3}}{\log^2 x} \right)
$$

Độ phức tạp thời gian khi tính $W_5$ là:

$$
O\left(\sum_{\sqrt{x/y}<p\le x^{1/3}}{\pi\left(\sqrt{\dfrac xp}\right)} \right)=O\left(\dfrac{x^{2/3}}{\log^2 x} \right)
$$

<span id="độ-phức-tạp-khi-tính-s₃"></span>
### Độ phức tạp khi tính S₃

Với bước tiền xử lý: do cần truy vấn nhanh giá trị $\phi(u,b)$, không thể dùng phép sàng thông thường để lấy trong $O(1)$, mà phải duy trì một cấu trúc dữ liệu sao cho mỗi truy vấn có độ phức tạp thời gian $O(\log x)$. Vì vậy độ phức tạp thời gian là $O\left(\dfrac{x}{y}\log x\log\log x\right)$.

Với bước tính tổng: với mỗi hạng trong tổng tính $S_3$, truy vấn cấu trúc dữ liệu trên, tổng cộng $O\left(\log x\right)$ lần truy vấn. Còn cần tính số lượng hạng của tổng, tức số lá trong cây nhị phân. Mọi lá đều có dạng $\pm\phi\left(\dfrac{x}{mp_b},b-1\right)$, trong đó $m\le y,b<\pi(x^{1/4})$. Vì vậy số lá có cấp $O\left(y\pi\left(x^{1/4}\right)\right)$. Do đó tổng độ phức tạp thời gian để tính $S_3$ là:

$$
O\left(\dfrac{x}{y}\log x\log\log x+yx^{1/4}\right)
$$

<span id="tổng-độ-phức-tạp"></span>
### Tổng độ phức tạp

Độ phức tạp không gian của thuật toán này là $O\left(y\right)$, và độ phức tạp thời gian là:

$$
O\left(\dfrac{x}{y}\log{\log x}+\dfrac{x}{y}\log x\log{\log x}+x^{1/4}y+\dfrac{x^{2/3}}{\log^2{x}} \right)
$$

Chọn $y=x^{1/3}\log^3{x}\log{\log x}$, thu được độ phức tạp thời gian tối ưu $O\left(\dfrac{x^{2/3}}{\log^2 x}\right)$ và độ phức tạp không gian $O\left(x^{1/3}\log^3{x}\log{\log x}\right)$.

<span id="một-số-cải-tiến"></span>
## Một số cải tiến

Phần này trình bày các cách cải tiến để giảm hằng số của thuật toán và nâng cao hiệu năng thực tế.

-   Trong **điều kiện dừng $2$**, có thể dùng một $z$ thay cho $y$, với $z$ thỏa mãn $z>y$. Có thể chứng minh rằng khi đó độ phức tạp thời gian để tính $S_3$ có thể tối ưu thành:

    $$
    O\left(\dfrac{x}{z}\log x\log{\log x}+\dfrac{yx^{1/4}}{\log x}+z^{3/2} \right)
    $$

    Điều này cũng cung cấp một cách tốt để kiểm tra phép tính thông qua việc thay đổi giá trị $z$.

-   Để trình bày mạch lạc, khi mô tả thuật toán chọn tách tổng $S$ tại $x^{1/4}$. Tuy nhiên, chỉ cần có $p\le \dfrac{x}{pq}<p^2$ là đã có thể tính. Có thể tận dụng điểm này mà không làm đổi độ phức tạp tiệm cận.

-   Tiền xử lý phép tính bằng vài số nguyên tố đầu tiên $2,3,5$ có thể tiết kiệm thêm thời gian.

<span id="tài-liệu-tham-khảo-và-đọc-thêm"></span>
## Tài liệu tham khảo và đọc thêm

Bài viết này được dịch từ: [Computing $\pi(x)$: the Meissel, Lehmer, Lagarias, Miller, Odlyzko method](https://dl.acm.org/doi/abs/10.1090/s0025-5718-96-00674-6)
