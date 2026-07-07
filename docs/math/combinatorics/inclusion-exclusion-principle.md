<span id="giới-thiệu"></span>

## Giới thiệu

???+ note "Ví dụ nhập môn"
    Giả sử trong lớp có $10$ học sinh thích Toán, $15$ học sinh thích Ngữ văn, $21$ học sinh thích lập trình. Hỏi trong lớp có ít nhất bao nhiêu học sinh thích ít nhất một môn?

Có phải là $10+15+21=46$ học sinh không? Không, vì một số học sinh có thể đồng thời thích Toán và Ngữ văn, hoặc Ngữ văn và lập trình, thậm chí có thể thích cả ba môn.

Để trình bày thuận tiện, gọi các tập học sinh thích Ngữ văn, Toán, lập trình lần lượt là $A,B,C$. Tổng số học sinh cần đếm bằng $|A\cup B\cup C|$. Như đã nói, nếu cộng trực tiếp số phần tử của ba tập $|A|,|B|,|C|$, một số phần tử sẽ bị đếm lặp, nên cần trừ đi $|A\cap B|,|B\cap C|,|C\cap A|$. Nhưng khi làm vậy, một phần nhỏ lại bị trừ quá nhiều, nên phải cộng lại $|A\cap B\cap C|$. Tức là

$$
|A\cup B\cup C|=|A|+|B|+|C|-|A\cap B|-|B\cap C|-|C\cap A|+|A\cap B\cap C|
$$

![Nguyên lý bao hàm-loại trừ - ví dụ biểu đồ Venn](./images/incexcp.png)

Mở rộng bài toán trên ra trường hợp tổng quát sẽ thu được nguyên lý bao hàm-loại trừ quen thuộc.

<span id="định-nghĩa"></span>

## Định nghĩa

Giả sử các phần tử trong $U$ có $n$ thuộc tính khác nhau, thuộc tính thứ $i$ được gọi là $P_i$, và tập các phần tử có thuộc tính $P_i$ là $S_i$. Khi đó

$$
\begin{aligned}
\left|\bigcup_{i=1}^{n}S_i\right|=&\sum_{i}|S_i|-\sum_{i<j}|S_i\cap S_j|+\sum_{i<j<k}|S_i\cap S_j\cap S_k|-\cdots\\
&+(-1)^{m-1}\sum_{a_i<a_{i+1} }\left|\bigcap_{i=1}^{m}S_{a_i}\right|+\cdots+(-1)^{n-1}|S_1\cap\cdots\cap S_n|
\end{aligned}
$$

Hay

$$
\left|\bigcup_{i=1}^{n}S_i\right|=\sum_{m=1}^n(-1)^{m-1}\sum_{a_i<a_{i+1} }\left|\bigcap_{i=1}^mS_{a_i}\right|
$$

<span id="chứng-minh"></span>

### Chứng minh

Với mỗi phần tử, dùng định lý nhị thức để tính số lần nó xuất hiện. Với một phần tử $x$, giả sử nó nằm trong các tập $T_1,T_2,\cdots,T_m$, thì số lần xuất hiện của nó là

$$
\begin{aligned}
Cnt=&|\{T_i\}|-|\{T_i\cap T_j|i<j\}|+\cdots+(-1)^{k-1}\left|\left\{\bigcap_{i=1}^{k}T_{a_i}|a_i<a_{i+1}\right\}\right|\\
&+\cdots+(-1)^{m-1}|\{T_1\cap\cdots\cap T_m\}|\\
=&\dbinom{m}{1}-\dbinom{m}{2}+\cdots+(-1)^{m-1}\dbinom{m}{m}\\
=&\dbinom{m}{0}-\sum_{i=0}^m(-1)^i\dbinom{m}{i}\\
=&1-(1-1)^m=1
\end{aligned}
$$

Vậy mỗi phần tử xuất hiện đúng một lần; gộp lại chính là phép hợp. Chứng minh hoàn tất.

<span id="phần-bù"></span>

### Phần bù

Với **hợp các tập** trong tập vũ trụ $U$, có thể dùng nguyên lý bao hàm-loại trừ để tính; còn giao các tập có thể tính bằng tập vũ trụ trừ đi **hợp các phần bù**:

$$
\left|\bigcap_{i=1}^{n}S_i\right|=|U|-\left|\bigcup_{i=1}^n\overline{S_i}\right|
$$

Vế phải lại dùng bao hàm-loại trừ.

Độc giả đã từng tiếp xúc với bao hàm-loại trừ chắc đều nắm rõ phần trên, và quan tâm hơn đến ứng dụng của nó.

Tiếp theo là 3 ví dụ ở các mức độ khác nhau để minh họa ứng dụng của nguyên lý bao hàm-loại trừ.

<span id="đếm-nghiệm-nguyên-không-âm-của-phương-trình-bất-định"></span>

## Đếm nghiệm nguyên không âm của phương trình bất định

???+ note "Đếm nghiệm nguyên không âm của phương trình bất định"
    Cho phương trình bất định $\sum_{i=1}^nx_i=m$ và $n$ điều kiện ràng buộc $x_i\leq b_i$, trong đó $m,b_i \in \mathbb{N}$. Tính số nghiệm nguyên không âm của phương trình.

<span id="khi-không-có-ràng-buộc"></span>

### Khi không có ràng buộc

Nếu không có ràng buộc $x_i\leq b_i$, số nghiệm nguyên không âm của phương trình bất định $\sum_{i=1}^nx_i=m$ là $\dbinom{m+n-1}{n-1}$.

Chứng minh sơ lược: phương pháp thanh ngăn.

Tương đương với việc có $m$ quả bóng cần chia vào $n$ hộp, cho phép hộp rỗng. Bài toán này không thể giải trực tiếp bằng số tổ hợp.

Thêm $n-1$ quả bóng nữa; khi đó bài toán trở thành chọn $n-1$ quả bóng trong một dãy bóng độ dài $m+n-1$. $n-1$ quả bóng được chọn này chia dãy thành $n$ phần, tương ứng một-một với cách chia vào $n$ hộp. Vậy số cách chọn $n-1$ quả bóng trong $m+n-1$ quả là $\dbinom{m+n-1}{n-1}$.

<span id="mô-hình-bao-hàm-loại-trừ"></span>

### Mô hình bao hàm-loại trừ

Tiếp theo, thử trừu tượng hóa mô hình của nguyên lý bao hàm-loại trừ:

1.  Tập vũ trụ $U$: các nghiệm nguyên không âm của phương trình bất định $\sum_{i=1}^nx_i=m$.
2.  Phần tử: biến $x_i$.
3.  Thuộc tính: thuộc tính của $x_i$ là điều kiện mà $x_i$ thỏa, tức điều kiện $x_i\leq b_i$.

Mục tiêu: kích thước của tập khi mọi biến thỏa thuộc tính tương ứng, tức $|\bigcap_{i=1}^nS_i|$.

Có thể tính bằng $\left|\bigcap_{i=1}^{n}S_i\right|=|U|-\left|\bigcup_{i=1}^n\overline{S_i}\right|$. $|U|$ tính được bằng số tổ hợp, phần còn lại tự nhiên được khai triển bằng nguyên lý bao hàm-loại trừ.

Bài toán trở thành tính kích thước giao của một số $\overline{S_{a_i}}$. Ý nghĩa của $\overline{S_{a_i} }$ là số nghiệm thỏa $x_{a_i}\geq b_{a_i}+1$, và giao nghĩa là đồng thời thỏa các điều kiện này. Vì vậy phương trình bất định tương ứng với giao này có một số biến có **cận dưới**, còn các biến khác không bị ràng buộc.

Có thể khử các cận dưới này không? Vì cần nghiệm nguyên không âm, mà cận dưới của một số biến lại lớn hơn $0$, chỉ cần **trừ đi cận dưới đó** để biến cận dưới của chúng thành $0$, tức không còn cận dưới. Do đó với

$$
\left|\bigcap_{a_i<a_{i+1} }^{1\leq i\leq k}S_{a_i}\right|
$$

phương trình bất định có dạng

$$
\sum_{i=1}^nx_i=m-\sum_{i=1}^k(b_{a_i}+1)
$$

Nên phần này cũng tính được bằng số tổ hợp. Mảng $a$ độ dài $k$ này tương đương với việc liệt kê tập con.

<span id="haoi2008-coin-shopping"></span>

## HAOI2008 Mua xu

???+ note "HAOI2008 Mua xu"
    Có 4 loại đồng xu, mệnh giá của loại thứ $i$ là $C_i$. Có $n$ truy vấn; mỗi truy vấn cho số lượng $D_i$ của mỗi loại xu và một giá tiền $S$, hỏi số cách thanh toán.
    
    $n\leq 10^3,S\leq 10^5$.

Nếu dùng bài toán cái túi, độ phức tạp là $O(4nS)$, không chấp nhận được. Đặc điểm rõ nhất của bài này là chỉ có bốn loại xu. Trừu tượng hóa bài toán, thực chất là cần đếm số nghiệm nguyên không âm của $\sum_{i=1}^4C_ix_i=S,x_i\leq D_i$.

Dùng cùng cách bao hàm-loại trừ, thuộc tính của $x_i$ là $x_i\leq D_i$. Áp dụng công thức bao hàm-loại trừ, cuối cùng cần giải

$$
\sum_{i=1}^4C_ix_i=S-\sum_{i=1}^kC_{a_i}(D_{a_i}+1)
$$

Đây chính là bài toán cái túi vô hạn. Có thể tiền xử lý bài toán này; tính cả truy vấn, tổng độ phức tạp là $O(4S+2^4n)$.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/inclusion-exclusion-principle/inclusion-exclusion-principle_1.cpp"
    ```

<span id="bài-toán-tô-màu-đồ-thị-con-của-đồ-thị-đầy-đủ"></span>

## Bài toán tô màu đồ thị con của đồ thị đầy đủ

Ba bài trên đều là ứng dụng thuận chiều của nguyên lý bao hàm-loại trừ; bài này cần phân tích ngược bằng bao hàm-loại trừ.

???+ note "Bài toán tô màu đồ thị con của đồ thị đầy đủ"
    A và B thích tô màu đồ thị (không nhất thiết liên thông), với quy tắc: hai đỉnh kề nhau phải có cùng một màu. Hôm nay A và B chơi một trò chơi trên **đồ thị đầy đủ** bậc $n$ $G=(V,E)$. Họ định nghĩa hàm định giá $F(S)$, trong đó $S$ là tập cạnh, $S\subseteq E$. Giá trị $F(S)$ là tổng số cách tô màu đồ thị $G'=(V,S)$ bằng $m$ màu. Quy tắc khác của họ là: nếu $|S|$ lẻ, điểm của A tăng thêm $F(S)$; ngược lại điểm của B tăng thêm $F(S)$. Hỏi chênh lệch điểm của A và B.

<span id="dạng-toán-học"></span>

### Dạng toán học

Thoạt nhìn, hướng thuật toán của bài này chưa rõ; với bài khó, trước hết nên trừu tượng hóa thành dạng toán học. Chênh lệch điểm là hiệu đối xứng chẵn lẻ, có thể dùng lũy thừa của $-1$ làm hệ số. Cần tính

$$
Ans=\sum_{S\subseteq E}(-1)^{|S|-1}F(S)
$$

<span id="mô-hình-bao-hàm-loại-trừ_1"></span>

### Mô hình bao hàm-loại trừ

"Hai đỉnh kề nhau phải có cùng một màu" được xem là một thuộc tính. Trước hết tạm không tuân theo quy tắc tô màu, giả định dùng trực tiếp $m$ màu để tô đồ thị. Với đồ thị $G'=(V,S)$, xem nó là **phần tử**. **Thuộc tính** $x_i=x_j$ có nghĩa là đỉnh $i,j$ cùng màu (lưu ý không yêu cầu giữa $i,j$ có cạnh).

Tập **tương ứng** với thuộc tính $x_i=x_j$ được định nghĩa là $Q_{i,j}$; ý nghĩa của nó là tất cả các phương án tô màu của đồ thị $G'$ thỏa thuộc tính này. Kích thước tập là số phương án tô màu thỏa thuộc tính, và phần tử trong tập tương ứng với các đồ thị đã tô màu thỏa thuộc tính đó.

Quay lại đề bài, "hai đỉnh kề nhau phải có cùng một màu" có thể hiểu là giao của một số tập $Q$. Do đó có thể viết

$$
F(S)=\left|\bigcap_{(i,j)\in S}Q_{i,j}\right|
$$

Ý nghĩa của vế phải là: với mỗi cạnh $(i,j)$ trong $S$, phương án tô màu đều thỏa $x_i=x_j$, chính là $F(S)$.

Đã thấy dáng dấp của bao hàm-loại trừ. Vì nguyên lý bao hàm-loại trừ không có dạng cặp có thứ tự, ánh xạ **tất cả** cạnh $(i,j)$ vào $T=\frac{n(n+1)}{2}$ số nguyên. Giả sử $(i,j)$ được ánh xạ thành $k,1\leq k\leq T$, đồng thời $Q_{i,j}$ được ánh xạ thành $Q_k$. Khi đó thuộc tính $x_i=x_j$ được định nghĩa là $P_k$.

Đồng thời $S$ có thể biểu diễn thành một tập gồm các $k$, tức $S\iff K=\{k_1,k_2,\cdots,k_m\}$ (nghĩa là lập một quan hệ tương đương giữa tập cạnh và tập số).

Tập $E$ tương ứng với $M=\left\{1,2,\cdots,\frac{n(n+1)}{2}\right\}$. Khi đó

$$
F(S)\iff F(\{ {k_i}\})=\left|\bigcap_{k_i}Q_{k_i}\right|
$$

<span id="phân-tích-ngược"></span>

### Phân tích ngược

Khai triển biểu thức cần tính:

$$
\begin{aligned}
Ans &= \sum_{K\subseteq M}(-1)^{|K|-1}\left|\bigcap_{k_i\in K}Q_{k_i}\right|\\
    &= \sum_{i}|Q_i|-\sum_{i<j}|Q_i\cap Q_j|+\sum_{i<j<k}|Q_i\cap Q_j\cap Q_k|-\cdots+(-1)^{T-1}\left|\bigcap_{i=1}^TQ_i\right|
\end{aligned}
$$

Vậy đã xuất hiện dạng khai triển của nguyên lý bao hàm-loại trừ, nên suy ngược biểu thức này:

$$
Ans=\left|\bigcup_{i=1}^TQ_i\right|
$$

Xét ý nghĩa của vế phải: chỉ cần thỏa bất kỳ điều kiện nào trong $1\sim T$, tức tồn tại hai đỉnh cùng màu (không nhất thiết kề nhau). Tập vũ trụ các phương án tô màu là $U$, có $|U|=m^n$. Chuyển sang phần bù, cần đếm số phương án mà mọi cặp đỉnh có màu khác nhau, tức $A_m^n=\frac{m!}{(m-n)!}$. Do đó

$$
Ans=m^n-A_m^n
$$

Để giải bài này, trước hết trừu tượng hóa đề bài thành dạng toán học; sau đó bắt đầu từ điều kiện chứa nhiều thông tin nhất, định nghĩa của hàm $F(S)$, và chuyển nó thành các phép giao, hợp, bù của tập hợp. Cuối cùng biến đổi biểu thức về dạng nguyên lý bao hàm-loại trừ và **suy ngược** ra kết quả. Bài này thể hiện cách dùng ngược của nguyên lý bao hàm-loại trừ.

<span id="bao-hàm-loại-trừ-trong-số-học"></span>

## Bao hàm-loại trừ trong số học

Nguyên lý bao hàm-loại trừ có thể giải một số bài toán số học một cách khéo léo.

<span id="dùng-bao-hàm-loại-trừ-để-đếm-số-cặp-có-ước-chung-lớn-nhất-bằng-k"></span>

### Dùng bao hàm-loại trừ để đếm số cặp có ước chung lớn nhất bằng $k$

Xét bài toán sau:

???+ note "Đếm số cặp có ước chung lớn nhất bằng $k$"
    Cho $1 \le x, y \le N$, $f(k)$ là số cặp có thứ tự $(x, y)$ có ước chung lớn nhất bằng $k$. Tính các giá trị từ $f(1)$ đến $f(N)$.

Bài này có thể làm bằng hàm Euler hoặc nghịch đảo Möbius, nhưng không cách nào đơn giản bằng bao hàm-loại trừ.

Theo nguyên lý bao hàm-loại trừ, trước tiên tìm tất cả các cặp có $k$ là **ước chung**, rồi loại bỏ mọi cặp có một bội của $k$ là **ước chung**; các cặp còn lại chính là các cặp có $k$ là **ước chung lớn nhất**. Tức là $f(k)=$ số cặp có $k$ là **ước chung** $-$ số cặp có bội của $k$ là **ước chung**.

Tiếp tục nhận thấy số cặp có bội của $k$ là **ước chung** bằng tổng số cặp có mỗi bội của $k$ là **ước chung lớn nhất**. Do đó có thể viết:

$$
f(k)= \lfloor (N/k) \rfloor ^2 - \sum_{i=2}^{i*k \le N} f(i*k)
$$

Vì khi $k>N/2$, có thể tính trực tiếp $f(k)= \lfloor (N/k) \rfloor ^2$, nên chỉ cần tính ngược từ $f(N)$ về $f(1)$. Vậy bài toán đã được hoàn thành bằng nguyên lý bao hàm-loại trừ.

```cpp
for (long long k = N; k >= 1; k--) {
  f[k] = (N / k) * (N / k);
  for (long long i = k + k; i <= N; i += k) f[k] -= f[i];
}
```

Độ phức tạp thời gian của cách trên là $O( \sum_{i=1}^{N} N/i)=O(N \sum_{i=1}^{N} 1/i)=O(N \log N)$.

Thêm ba bài tập cùng dạng để luyện tập.

-   [Luogu P2398 Tổng GCD](https://www.luogu.com.cn/problem/P2398)
-   [Luogu P2158\[SDOI2008\] Đội danh dự](https://www.luogu.com.cn/problem/P2158)
-   [Luogu P1447\[NOI2010\] Thu thập năng lượng](https://www.luogu.com.cn/problem/P1447)

<span id="suy-ra-hàm-euler-bằng-nguyên-lý-bao-hàm-loại-trừ"></span>

### Suy ra hàm Euler bằng nguyên lý bao hàm-loại trừ

Xét bài toán sau:

???+ note "Công thức hàm Euler"
    Tính hàm Euler $\varphi(n)$, trong đó $\varphi(n)=|\{1\leq x\leq n|\gcd(x,n)=1\}|$.

Tính trực tiếp là $O(n\log n)$, dùng sàng tuyến tính là $O(n)$, dùng Du Jiao sieve là $O(n^{\frac{2}{3}})$ (với một bài số học nhập môn dùng bao hàm-loại trừ thì không cần nói đến Du Jiao sieve). Tiếp theo xét cách suy ra công thức hàm Euler bằng bao hàm-loại trừ.

Để kiểm tra hai số có nguyên tố cùng nhau hay không, trước hết phân tích thừa số nguyên tố:

$$
n=\prod_{i=1}^k{p_i}^{c_i}
$$

Khi đó cần yêu cầu với mọi $p_i$, $x$ không phải bội của $p_i$, tức $p_i\nmid x$. Xem đây là một thuộc tính, tập tương ứng là $S_i$, có

$$
\varphi(n)=\left|\bigcap_{i=1}^kS_i\right|=|U|-\left|\bigcup_{i=1}^k\overline{S_i}\right|
$$

Kích thước tập vũ trụ $|U|=n$, còn $\overline{S_i}$ là tập các $x$ thỏa $p_i\mid x$, nên $|\overline{S_i}|=\frac{n}{p_i}$, từ đó suy ra

$$
\left|\bigcap_{a_i<a_{i+1}}S_{a_i}\right|=\frac{n}{\prod p_{a_i}}
$$

Vậy

$$
\begin{aligned}
\varphi(n)&=n-\sum_{i}\frac{n}{p_i}+\sum_{i<j}\frac{n}{p_ip_j}-\cdots+(-1)^k\frac{n}{p_1p_2 \cdots p_k}\\
&=n\left(1-\frac{1}{p_1}\right)\left(1-\frac{1}{p_2}\right)\cdots\left(1-\frac{1}{p_k}\right)\\
&=n\prod_{i=1}^k\left(1-\frac{1}{p_i}\right)
\end{aligned}
$$

Đây chính là biểu thức toán học của hàm Euler.

<span id="tổng-quát-hóa-nguyên-lý-bao-hàm-loại-trừ"></span>

## Tổng quát hóa nguyên lý bao hàm-loại trừ

Nguyên lý bao hàm-loại trừ thường được dùng trong các bài toán đếm tập hợp. Với hai hàm trên tập hợp $f(S),g(S)$, nếu

$$
f(S)=\sum_{T\subseteq S}g(T)
$$

thì

$$
g(S)=\sum_{T\subseteq S}(-1)^{|S|-|T|}f(T)
$$

<span id="chứng-minh_1"></span>

### Chứng minh

Chứng minh ngắn gọn. Bắt đầu từ vế phải:

$$
\begin{aligned}
&\sum_{T\subseteq S}(-1)^{|S|-|T|}f(T)\\
=&\sum_{T\subseteq S}(-1)^{|S|-|T|}\sum_{Q\subseteq T}g(Q)\\
=&\sum_{Q}g(Q)\sum_{Q\subseteq T\subseteq S}(-1)^{|S|-|T|}\\
\end{aligned}
$$

Nhận thấy phần tổng sau không liên quan đến $Q$; do đó tách phần $Q$ ở sau ra:

$$
=\sum_{Q}g(Q)\sum_{T\subseteq (S\setminus Q)}(-1)^{|S\setminus Q|-|T|}
$$

Ký hiệu hàm trên tập $P$ là $F(P)=\sum_{T\subseteq P}(-1)^{|P|-|T|}$, và rút gọn hàm này:

$$
\begin{aligned}
F(P)&=\sum_{T\subseteq P}(-1)^{|P|-|T|}\\
&=\sum_{i=0}^{|P|}\dbinom{|P|}{i}(-1)^{|P|-i}=\sum_{i=0}^{|P|}\dbinom{|P|}{i}1^i(-1)^{|P|-i}\\
&=(1-1)^{|P|}=0^{|P|}
\end{aligned}
$$

Vậy giá trị của biểu thức ban đầu là

$$
\sum_{Q}g(Q)\sum_{T\subseteq (S\setminus Q)}(-1)^{|S\setminus Q|-|T|}=\sum_{Q}g(Q)F(S\setminus Q)=\sum_{Q}g(Q)\cdot 0^{|S\setminus Q|}
$$

Chỉ khi $|S\setminus Q|=0$ thì $0^0=1$, lúc này $Q=S$ và đóng góp vào đáp án là $g(S)$; các trường hợp khác có $0^{|S\setminus Q|}=0$, không đóng góp gì. Do đó

$$
\sum_{Q}g(Q)\cdot 0^{|S\setminus Q|}=g(S)
$$

Suy ra điều phải chứng minh.

<span id="hệ-quả"></span>

### Hệ quả

Dạng này còn có một hệ quả sau. Trong tập vũ trụ $U$, với các hàm $f(S),g(S)$, nếu

$$
f(S)=\sum_{S\subseteq T}g(T)
$$

thì

$$
g(S)=\sum_{S\subseteq T}(-1)^{|T|-|S|}f(T)
$$

Hệ quả này thực chất là dạng phần bù, cách chứng minh tương tự.

<span id="đếm-dag"></span>

## Đếm DAG

???+ note "Đếm DAG"
    Đếm số đồ thị có hướng không chu trình có nhãn trên $n$ đỉnh, lấy kết quả theo môđun $10^9+7$. $n\leq 5\times 10^3$.

<span id="dp-trực-tiếp"></span>

### DP trực tiếp

Xét DP, định nghĩa $f[i,j]$ là số DAG trên $i$ đỉnh, trong đó có $j$ đỉnh có bậc vào bằng $0$. Giả sử sau khi loại bỏ $j$ đỉnh này, có $k$ đỉnh có bậc vào bằng $0$; khi chưa loại bỏ, mỗi đỉnh trong $k$ đỉnh này phải có ít nhất một cạnh nối từ một trong $j$ đỉnh đã bỏ, nên có $2^j-1$ khả năng. Ngoài việc nối tới $k$ đỉnh này, $j$ đỉnh đó còn có thể nối tùy ý tới các đỉnh còn lại, có $2^{i-j-k}$ khả năng. Do đó phương trình là:

$$
f[i,j]=\binom{i}{j}\sum_{k=1}^{i-j}(2^j-1)^k2^{(i-j-k)j}f[i-j,k]
$$

Độ phức tạp tính công thức trên là $O(n^3)$.

<span id="nới-lỏng-ràng-buộc"></span>

### Nới lỏng ràng buộc

Định nghĩa DP trên là đúng $j$ đỉnh có bậc vào bằng $0$, quá chặt; có thể nới lỏng thành ít nhất $j$ đỉnh có bậc vào bằng $0$. Định nghĩa trực tiếp $f[i]$ là số DAG trên $i$ đỉnh, và dùng bao hàm-loại trừ. Xét $j$ đỉnh được chọn: chúng có thể có cạnh tùy ý tới $i-j$ đỉnh còn lại, số cách là $\left(2^{i-j}\right)^j=2^{(i-j)j}$:

$$
f[i]=\sum_{j=1}^i(-1)^{j-1}\binom{i}{j}2^{(i-j)j}f[i-j]
$$

Độ phức tạp tính công thức trên là $O(n^2)$.

<span id="bao-hàm-loại-trừ-min-max"></span>

## Bao hàm-loại trừ min-max

Với một dãy $\{x_i\}$ thỏa quan hệ [thứ tự toàn phần](../order-theory.md#tập-có-thứ-tự-bộ-phận) và các phần tử trong dãy có thể cộng trừ, đặt độ dài dãy là $n$, và $S=\{1,2,3,\cdots,n\}$, có:

$$
\max_{i\in S}{x_i}=\sum_{T\subseteq S}{(-1)^{|T|-1}\min_{j\in T}{x_j}}
$$

$$
\min_{i\in S}{x_i}=\sum_{T\subseteq S}{(-1)^{|T|-1}\max_{j\in T}{x_j}}
$$

**Chứng minh:** Xét một ánh xạ đến nguyên lý bao hàm-loại trừ tổng quát. Với $x\in S$, giả sử $x$ là phần tử nhỏ thứ $k$. Định nghĩa ánh xạ $f:x\mapsto \{1,2,\cdots,k\}$. Đây là một song ánh.

Với $x,y\in S$, có $f(\min(x,y))=f(x)\cap f(y)$ và $f(\max(x,y))=f(x)\cup f(y)$. Do đó:

$$
\begin{aligned}
\left|f\left(\max_{i\in S}{x_i}\right)\right|
&= \left| \bigcup_{i\in S} f(x_i) \right|\\
&= \sum_{T\subseteq S}(-1)^{|T|-1} \left|\bigcap_{j\in T}f(x_j)\right|\\
&= \sum_{T\subseteq S}(-1)^{|T|-1} \left|f\left(\min_{j\in T}{x_j}\right)\right|\\
\end{aligned}
$$

Sau đó ánh xạ $\left|f\left(\max_{i\in S}{x_i}\right)\right|$ ngược lại thành $\max_{i\in S}{x_i}$; trường hợp $\min$ tương tự.

Chứng minh hoàn tất.

Công thức này có vẻ khá thừa, vì giá trị lớn nhất có thể tính trực tiếp. Lý do bao hàm-loại trừ min-max quan trọng là nó vẫn đúng với kỳ vọng, cụ thể:

$$
E\left(\max_{i\in S}{x_i}\right)=\sum_{T\subseteq S}{(-1)^{|T|-1}E\left(\min_{j\in T}{x_j} \right)}
$$

$$
E\left(\min_{i\in S}{x_i}\right)=\sum_{T\subseteq S}{(-1)^{|T|-1}E\left(\max_{j\in T}{x_j} \right)}
$$

**Chứng minh:** Xét một cách tính kỳ vọng:

$$
E\left(\max_{i\in S}{x_i}\right)=\sum_{y}{P(y=x)\max_{j\in S}{y_j}}
$$

Trong đó $y$ là một dãy độ dài $n$.

Áp dụng công thức trước đó cho phần $\max$ ở sau:

$$
\begin{aligned}E\left(\max_{i\in S}{x_i}\right)&=\sum_{y}{P(y=x)\max_{j\in S}{y_j}}\\
&=\sum_{y}{P(y=x)\sum_{T\subseteq S}{(-1)^{|T|-1}\min_{j\in T}{y_j}}} \end{aligned}
$$

Đổi thứ tự lấy tổng:

$$
\begin{aligned}E\left(\max_{i\in S}{x_i}\right)
&=\sum_{y}{P(y=x)\sum_{T\subseteq S}{(-1)^{|T|-1}\min_{j\in T}{y_j}}}\\
&=\sum_{T\subseteq S}{(-1)^{|T|-1}\sum_y{P(y=x)\min_{j\in T}{y_j}}}\\
&=\sum_{T\subseteq S}{(-1)^{|T|-1}E\left(\min_{j\in T}{y_j}\right)} \end{aligned}
$$

Trường hợp $\min$ tương tự.

Chứng minh hoàn tất.

Còn có dạng mạnh hơn:

$$
\underset{i\in S}{\operatorname{kthmax}{x_i}}=\sum_{T\subseteq S}{(-1)^{|T|-k}\dbinom {|T|-1}{k-1}\min_{j\in T}{x_j}}
$$

$$
\underset{i\in S}{\operatorname{kthmin}{x_i}}=\sum_{T\subseteq S}{(-1)^{|T|-k}\dbinom {|T|-1}{k-1}\max_{j\in T}{x_j}}
$$

$$
E\left(\underset{i\in S}{\operatorname{kthmax}{x_i}}\right)=\sum_{T\subseteq S}{(-1)^{|T|-k}\dbinom {|T|-1}{k-1}E\left(\min_{j\in T}{x_j}\right)}
$$

$$
E\left(\underset{i\in S}{\operatorname{kthmin}{x_i}}\right)=\sum_{T\subseteq S}{(-1)^{|T|-k}\dbinom {|T|-1}{k-1}E\left(\max_{j\in T}{x_j}\right)}
$$

Quy ước nếu $n< m$ thì $\dbinom nm=0$.

**Chứng minh:** Không mất tính tổng quát, giả sử $\forall 1\le i<n,x_i\le x_{i+1}$. Khi đó:

$$
\begin{aligned}
\sum_{T\subseteq S}{(-1)^{|T|-k}\dbinom {|T|-1}{k-1}\min_{j\in T}{x_j}}
&=\sum_{i\in S}{x_i\sum_{T\subseteq S}{(-1)^{|T|-k}\dbinom {|T|-1}{k-1}\left[x_i=\min_{j\in T}{x_j} \right]}}\\
&=\sum_{i\in S}{x_i\sum_{j=k}^n{\dbinom {n-i}{j-1}\dbinom {j-1}{k-1}(-1)^{j-k}}}
\end{aligned}
$$

Lại có đồng nhất thức tổ hợp $\dbinom ab\dbinom bc=\dbinom ac\dbinom {a-c}{b-c}$, nên:

$$
\begin{aligned}
\sum_{T\subseteq S}{(-1)^{|T|-k}\dbinom {|T|-1}{k-1}\min_{j\in T}{x_j}}
&=\sum_{i\in S}{x_i\sum_{j=k}^n{\dbinom {n-i}{j-1}\dbinom {j-1}{k-1}(-1)^{j-k}}}\\
&=\sum_{i\in S}{x_i\sum_{j=k}^n{\dbinom {n-i}{k-1}\dbinom {n-i-k+1}{j-k}(-1)^{j-k}}}\\
&=\sum_{i\in S}{\dbinom {n-i}{k-1}x_i\sum_{j=k}^n{\dbinom {n-i-k+1}{j-k}(-1)^{j-k}}}\\
&=\sum_{i\in S}{\dbinom {n-i}{k-1}x_i\sum_{j=0}^{n-i-k+1}{\dbinom {n-i-k+1}j(-1)^{j}}}
\end{aligned}
$$

Khi $i=n-k+1$:

$$
\dbinom {n-i}{k-1}\sum_{j=0}^{n-i-k+1}{\dbinom {n-i-k+1}j(-1)^{j}}=1
$$

Ngược lại:

$$
\dbinom {n-i}{k-1}\sum_{j=0}^{n-i-k+1}{\dbinom {n-i-k+1}j(-1)^{j}}=0
$$

Vậy:

$$
\sum_{i\in S}{\dbinom {n-i}{k-1}x_i\sum_{j=0}^{n-i-k+1}{\dbinom {n-i-k+1}j(-1)^{j}}}=\underset{i\in S}{\operatorname{kthmax}}{x_i}
$$

Ba công thức còn lại tương tự.

Chứng minh hoàn tất.

Theo bao hàm-loại trừ min-max, còn có công thức:

$$
\underset{i\in S}{\operatorname{lcm}}{x_i}=\prod_{T\subseteq S}{\left(\gcd_{j\in T}{x_j} \right)^{(-1)^{|T|-1}}}
$$

Vì $\operatorname{lcm},\gcd,a^{1},a^{-1}$ lần lượt tương ứng với $\max,\min,+,-$, tức là thực hiện bao hàm-loại trừ min-max trên các số mũ, nên công thức trên đúng.

<span id="pkuwc2018-random-walk"></span>

## PKUWC2018 Bước đi ngẫu nhiên

???+ note "[PKUWC2018 Bước đi ngẫu nhiên](https://loj.ac/problem/2542)"
    Cho một cây có $n$ đỉnh. Xuất phát từ $x$; mỗi lần chọn ngẫu nhiên đồng xác suất một cạnh kề với đỉnh hiện tại và đi theo cạnh đó.
    
    Có $Q$ truy vấn. Mỗi truy vấn cho một tập $S$; hỏi nếu xuất phát từ $x$ và cứ tiếp tục đi ngẫu nhiên cho đến khi mọi đỉnh trong $S$ đều đã được đi qua ít nhất một lần, thì kỳ vọng cần đi bao nhiêu bước.
    
    Đặc biệt, đỉnh $x$ (đỉnh xuất phát) được xem là đã được đi qua ngay từ đầu.
    
    Lấy kết quả theo môđun $998244353$.
    
    $1\le n\le 18,1\le Q\le 5000,1\le |S|\le n$.

Kỳ vọng số bước đi chính là thời gian đi. Đặt biến ngẫu nhiên $x_i$ là thời điểm lần đầu đi tới đỉnh $i$. Cần tính

$$
E\left(\max_{i\in S}x_i\right)
$$

Dùng bao hàm-loại trừ min-max, có

$$
E\left(\max_{i\in S}x_i\right)
=E\left(\sum_{T\subseteq S}(-1)^{|T|-1}\min_{i\in T}x_i\right)
=\sum_{T\subseteq S}(-1)^{|T|-1}E\left(\min_{i\in T}x_i\right)
$$

Với một tập $T\in[n]$, xét cách tính $F(T)=E(\min_{i\in T}x_i)$.

Ý nghĩa của $E(\min_{i\in T}x_i)$ là kỳ vọng thời gian lần đầu đi đến một đỉnh nào đó trong $T$. Không mất tính tổng quát, đặt $f(i)$ là kỳ vọng thời gian xuất phát từ đỉnh $i$ để lần đầu đi đến một đỉnh trong $T$.

-   Với $i\in T$, có $f(i)=0$.
-   Với $i\notin T$, có $f(i)=1+\frac{1}{\text{deg}(i)}\sum_{(i,j)\in E}f(j)$.

Nếu khử Gauss trực tiếp, độ phức tạp là $O(n^3)$. Nếu tính $F(T)$ cho mỗi $T$, tổng độ phức tạp sẽ là $O(2^nn^3)$, không chấp nhận được. Dùng kỹ thuật khử trên cây.

Không mất tính tổng quát, lấy gốc là đỉnh $1$, cha của đỉnh $u$ là $p_u$. Với đỉnh lá $i$, $f(i)$ chỉ liên quan đến cha của $i$ (hoặc có thể $f(i)=0$, càng tốt). Do đó có thể viết $f(i)=A_i+B_if(p_i)$, trong đó $A_i,B_i$ tính nhanh được.

Với đỉnh không phải lá $i$, xét dãy con của nó $j_1,\cdots,j_k$. Vì $f(j_e)=A_{j_e}+B_{j_e}f(i)$, có

$$
f(i)=1+\frac{1}{\deg(i)}\sum_{e=1}^k\left(A_{j_e}+B_{j_e}f(i)\right)+\frac{f(p_i)}{\deg(i)}
$$

Biến đổi, thu được

$$
f(i)=\frac{\deg(i)+\sum_{e=1}^kA_{j_e}}{\deg(i)-\sum_{e=1}^kB_{j_e}}+
\frac{f(p_i)}{\deg(i)-\sum_{e=1}^kB_{j_e}}
$$

Vậy cũng viết được $f(i)$ ở dạng $A_i+B_if(p_i)$. Có thể lần ngược như vậy đến gốc; gốc không có cha. Tức là

$$
f(1)=\frac{\deg(1)+\sum_{e=1}^kA_{j_e}}{\deg(1)-\sum_{e=1}^kB_{j_e}}
$$

Giải phương trình này sẽ thu được $f(1)$, rồi đẩy xuống một lần nữa để tính mọi $f(i)$. Khi đó $F(T)=f(x)$. Độ phức tạp thời gian là $O(n)$.

Như vậy có thể tính $F(T)$ cho mỗi $T$ với độ phức tạp $O(2^nn)$.

Quay lại phần bao hàm-loại trừ, có $E(\max_{i\in S}x_i)=\sum_{T\subseteq S}(-1)^{|T|-1}F(T)$.

Đặt $F'(T)=(-1)^{|T|-1}F(T)$, có thêm $E(\max_{i\in S}x_i)=\sum_{T\subseteq S}F'(T)$. Do đó có thể dùng FMT (còn gọi là tổng tiền tố trên tập con, hoặc FWT / phép biến đổi) để tính $E(\max_{i\in S}x_i)$ cho mỗi $S$ trong $O(2^nn)$, rồi trả lời mỗi truy vấn trong $O(1)$.

<span id="bài-tập"></span>

### Bài tập

-   [ABC331- G - Thu thập tất cả](https://atcoder.jp/contests/abc331/tasks/abc331_g)
-   [Luogu P4707 Trở về thế giới hiện tại](https://www.luogu.com.cn/problem/P4707)

<span id="tài-liệu-tham-khảo"></span>

## Tài liệu tham khảo

[Nghiên cứu sơ lược về nguyên lý bao hàm-loại trừ - Wang Di](https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2013%E8%AE%BA%E6%96%87%E9%9B%86.pdf), tuyển tập luận văn ứng viên đội tuyển quốc gia Olympic Tin học Trung Quốc năm 2013

[Một loạt bài toán về đếm DAG có nhãn - Cyhlnj](https://www.cnblogs.com/cjoieryl/p/10078167.html)

[Thứ tự toàn phần - Wikipedia](https://en.wikipedia.org/wiki/Total_order)
