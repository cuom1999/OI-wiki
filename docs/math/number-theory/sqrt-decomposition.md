Phân khối số học có thể tính nhanh một số tổng có dạng

$$
\sum_{i=1}^nf(i)g\left(\left\lfloor\dfrac ni\right\rfloor\right)
$$

Nếu có thể tính $\sum_{i=l}^{r}f(i)$ trong $O(1)$, hoặc đã tiền xử lý tổng tiền tố của $f$, thì phân khối số học có thể tính giá trị của tổng trên trong $O(\sqrt{n})$.

Phân khối số học thường được dùng cùng các kỹ thuật như [đảo Möbius](./mobius.md).

<span id="ý-tưởng"></span>
## Ý tưởng

Trước hết, ta dùng một ví dụ đơn giản để minh họa ý tưởng của phân khối số học. Giả sử cần đếm số điểm nguyên nằm dưới hyperbol trong hình sau:

![Điểm nguyên dưới hyperbol](./images/sqrt-decomposition.svg)

Điều này tương đương với việc tính tổng

$$
\sum_{i=1}^{11}\left\lfloor\dfrac{11}{i}\right\rfloor.
$$

Đây là trường hợp đặc biệt của tổng ở trên khi $f(k)=1,~g(k)=k$.

Cách trực tiếp nhất là tính từng cột rồi cộng lại, tức là lần lượt tính số điểm nguyên trong các cột $i=1,2,\cdots,11$. Quan sát hình vẽ, các cột điểm nguyên này có thể chia thành $5$ khối; trong mỗi khối, chiều cao của các cột là như nhau và tạo thành một lưới điểm hình chữ nhật. Vì vậy, chỉ cần biết độ rộng của từng khối, ta có thể đếm nhanh bằng cách tính kích thước của các khối chữ nhật đó.

Đó là ý tưởng cơ bản của phân khối theo phép chia lấy phần nguyên.

<span id="tính-chất"></span>
## Tính chất

Mục này xét một số kết luận về cách chia khối các điểm nguyên dưới hyperbol $y = \dfrac{n}{x}$. Cụ thể, ta cần chia các số nguyên từ $1$ đến $n$ thành các khối theo giá trị của $\left\lfloor\dfrac{n}{i}\right\rfloor$. Đặt

$$
D(n) = \left\{\left\lfloor\dfrac{n}{i}\right\rfloor : 1 \le i \le n,~i\in\mathbf N_+\right\}.
$$

Đây là tập hợp tất cả các giá trị có thể có của $\left\lfloor\dfrac{n}{i}\right\rfloor$.

Trước hết, số giá trị khác nhau như vậy chỉ là $O(\sqrt{n})$. Do đó, số khối thu được từ phân khối số học cũng chỉ là $O(\sqrt{n})$.

???+ note "Tính chất 1"
    $|D(n)|\le 2\sqrt{n}$.

??? note "Chứng minh"
    Xét hai trường hợp:
    
    -   Khi $i\le\sqrt{n}$, số giá trị có thể của $i$ nhiều nhất là $\sqrt{n}$, nên số giá trị có thể của $\left\lfloor\dfrac{n}{i}\right\rfloor$ cũng nhiều nhất là $\sqrt{n}$.
    -   Khi $i>\sqrt{n}$, ta có $\left\lfloor\dfrac{n}{i}\right\rfloor \le\dfrac{n}{i} < \sqrt{n}$, nên cũng có nhiều nhất $\sqrt{n}$ giá trị.
    
    Vì vậy, tổng số giá trị có thể là $|D(n)|\le 2\sqrt{n}$.

Với phân tích chi tiết hơn, ta thực ra có thể mô tả chính xác tập $D(n)$ và kích thước của nó.

???+ note "Tính chất 2"
    Đặt $s = \lfloor\sqrt{n}\rfloor$. Các phần tử của $D(n)$ theo thứ tự tăng dần là
    
    $$
    1 < 2 < \cdots < s-1 < s \le \left\lfloor\dfrac{n}{s}\right\rfloor < \left\lfloor\dfrac{n}{s-1}\right\rfloor < \cdots < \left\lfloor\dfrac{n}{2}\right\rfloor < \left\lfloor\dfrac{n}{1}\right\rfloor = n.
    $$
    
    Suy ra $|D(n)| = \lfloor \sqrt{4n+1}\rfloor - 1$.

??? note "Chứng minh"
    Trước hết, với $1 \le i \le s$, có thể chứng minh $\left\lfloor\dfrac{n}{\lfloor n/i\rfloor}\right\rfloor = i$. Đặt $d = \left\lfloor\dfrac{n}{i}\right\rfloor$, ta cần chứng minh $\left\lfloor\dfrac{n}{d}\right\rfloor = i$. Viết dưới dạng bất đẳng thức, điều này tương đương với việc từ $d \le \dfrac{n}{i} < d + 1$ suy ra $i \le \dfrac{n}{d} < i + 1$. Điều kiện đã biết có thể viết thành $i\le\dfrac{n}{d} < i + \dfrac{i}{d}$, vì vậy chỉ cần chứng minh $\dfrac{i}{d} \le 1$, tức là $i \le d = \left\lfloor\dfrac{n}{i}\right\rfloor$. Điều này tương đương với $i \le \dfrac{n}{i}$, đúng với mọi $1 \le i \le s \le \sqrt{n}$.
    
    Kết quả này cho thấy ánh xạ $i \mapsto \left\lfloor\dfrac{n}{i}\right\rfloor$ tạo thành một song ánh giữa tập $\{i:1\le i \le s\}$ và tập $\left\{\left\lfloor\dfrac{n}{i}\right\rfloor: 1\le i\le s\right\}$. Vì các giá trị $i$ đôi một khác nhau, các giá trị $\left\lfloor\dfrac{n}{i}\right\rfloor$ tương ứng cũng đôi một khác nhau. Hai tập chỉ có thể trùng ở một phần tử, đó là $s$ và $\left\lfloor\dfrac{n}{s}\right\rfloor$. Do đó, $|D(n)|=2s - \left[s = \lfloor n/s\rfloor\right]$.
    
    Để thu được biểu thức cuối cùng của $|D(n)|$, ta xét khi nào $s = \left\lfloor\dfrac{n}{s}\right\rfloor$.
    
    -   Nếu $s = \left\lfloor\dfrac{n}{s}\right\rfloor$, luôn có $s \le \dfrac{n}{s} < s + 1$, tức là $s^2 \le n < s^2+s$. Khi đó $4s^2 + 1 \le 4n + 1 < 4s^2+4s+1 = (2s+1)^2$. Vì $4n+1$ luôn là số lẻ, vế trái có thể nới tương đương thành $4s^2$, nên điều kiện này tương đương với $2s \le \sqrt{4n+1} < 2s+1$, tức là $\lfloor \sqrt{4n+1}\rfloor = 2s$.
    -   Nếu $s < \left\lfloor\dfrac{n}{s}\right\rfloor$, luôn có $s + 1 \le \dfrac{n}{s}$, tức là $s^2 + s\le n$. Lại vì $n < (s+1)^2$, ta có $s^2 + s\le n < (s+1)^2$. Điều này tương đương với $(2s+1)^2\le 4n+1 < 4(s+1)^2+1$. Một lần nữa dùng việc $4n+1$ là số lẻ, vế phải có thể siết tương đương thành $4(s+1)^2$, nên điều kiện này tương đương với $2s+1\le\sqrt{4n+1} < 2s+2$, tức là $\lfloor \sqrt{4n+1}\rfloor = 2s+1$.
    
    Tổng hợp hai trường hợp, ta thu được $|D(n)| = \lfloor \sqrt{4n+1}\rfloor - 1$.

Tiếp theo, hai đầu mút của mỗi khối cũng rất dễ xác định.

???+ note "Tính chất 3"
    Với $d\in D(n)$, mọi số nguyên $i$ thỏa mãn $\left\lfloor\dfrac{n}{i}\right\rfloor=d$ nằm trong khoảng
    
    $$
    \left\lfloor\dfrac{n}{d+1}\right\rfloor + 1\le i \le \left\lfloor\dfrac{n}{d}\right\rfloor.
    $$

??? note "Chứng minh"
    Vì $\left\lfloor\dfrac{n}{i}\right\rfloor=d$ tương đương với bất đẳng thức
    
    $$
    d\le \dfrac{n}{i} < d+1.
    $$
    
    Điều này lại tương đương với
    
    $$
    \dfrac{n}{d+1} < i\le \dfrac{n}{d}.
    $$
    
    Do $i\in\mathbf N_+$, ta có thể lấy phần nguyên của bất đẳng thức trên và thu được dạng tương đương
    
    $$
    \left\lfloor\dfrac{n}{d+1}\right\rfloor + 1 \le i\le \left\lfloor\dfrac{n}{d}\right\rfloor.
    $$

Tính chất này cũng thể hiện tính đối xứng của hình vẽ: tập các đầu mút phải của các khối (các điểm màu xanh trong hình phía trên) chính là $D(n)$. Điều này dễ hiểu vì toàn bộ hình đối xứng qua đường thẳng $y=x$.

Ngoài các tính chất trên, tập $D(n)$ còn có tính chất đệ quy thuận tiện:

???+ note "Tính chất 4"
    Với $m\in D(n)$, ta có $D(m)\subseteq D(n)$.

??? note "Chứng minh"
    Giả sử $m = \left\lfloor\dfrac{n}{k}\right\rfloor$. Khi đó, với mọi $i\in\mathbf N_+$, ta có
    
    $$
    \left\lfloor\dfrac{m}{i}\right\rfloor = \left\lfloor\dfrac{\lfloor n/k\rfloor}{i}\right\rfloor = \left\lfloor\dfrac{n}{ki}\right\rfloor \in D(n),
    $$
    
    nên $D(m)\subseteq D(n)$. Đẳng thức thứ hai dùng tính chất của [hàm lấy phần nguyên](./basic.md#hàm-lấy-phần-nguyên) đối với phân thức lồng nhau.

Như đã nói ở trên, $D(n)$ vừa là tập giá trị của $\left\lfloor\dfrac{n}{i}\right\rfloor$ trong các khối, vừa là tập các đầu mút phải của khối. Điều này có nghĩa là nếu áp dụng phân khối số học theo kiểu đệ quy (tức là giá trị của một hàm tại $n$ phụ thuộc vào giá trị của nó tại $m\in D(n)\setminus\{n\}$), thì trong toàn bộ quá trình tính toán, tập các đối số và tập các đầu mút phải thực ra đều là $D(n)$. Một ví dụ điển hình là [sàng Dujiao](./du.md).

<span id="quy-trình"></span>
## Quy trình

Từ các kết luận ở mục trước, ta có quy trình cụ thể của phân khối số học.

Để tính tổng

$$
\sum_{i=1}^nf(i)g\left(\left\lfloor\dfrac ni\right\rfloor\right)
$$

ta có thể chia các chỉ số $i=1,2,\cdots,n$ thành các khối theo giá trị của $\left\lfloor\dfrac ni\right\rfloor$. Vì các chỉ số có cùng giá trị $\left\lfloor\dfrac ni\right\rfloor$ tạo thành một đoạn liên tiếp $[l,r]$, đóng góp của khối đó vào tổng là

$$
\left(\sum_{i=l}^rf(i)\right)\cdot g\left(\left\lfloor\dfrac nl\right\rfloor\right).
$$

Để tính nhanh tổng này, thông thường ta cần tính nhanh tổng liên quan đến $f$ ở vế trái. Trong một số trường hợp, biểu thức của tổng này đã biết và có thể tính từng lần trong $O(1)$; trong các trường hợp khác, có thể tiền xử lý tổng tiền tố để mỗi truy vấn vẫn được trả lời trong $O(1)$.

Khi lần lượt tính hai đầu mút của từng khối, đầu mút trái $l$ của khối hiện tại bằng đầu mút phải của khối trước cộng $1$, còn đầu mút phải của khối hiện tại bằng $\left\lfloor\dfrac n{\lfloor n/l\rfloor}\right\rfloor$. Từ đó có giả mã sau:

$$
\begin{array}{l}
\textbf{Algorithm }\text{Sum}(f,g,n):\\
\textbf{Input. }n,~s(k)=\sum_{i=1}^kf(k),~g(k).\\
\textbf{Output. }S(n) = \sum_{i=1}^nf(i)g(\lfloor n/i\rfloor).\\
\textbf{Method.}\\
\begin{array}{ll}
1 & l \gets 1\\
2 & \textit{result} \gets 0 \\
3 & \textbf{while } l \leq n \textbf{ do}\\
4 & \qquad r \gets \left\lfloor \dfrac{n}{\lfloor n/l \rfloor} \right\rfloor\\
5 & \qquad \textit{result} \gets \textit{result} + (s(r)-s(l-1))\cdot g\left(\left\lfloor \dfrac{n}{l} \right\rfloor\right)\\
6 & \qquad l \gets r+1\\
7 & \textbf{end while}\\
8 & \textbf{return }\textit{result}
\end{array}
\end{array}
$$

Nếu mỗi lần tính $s(\cdot)$ mất $O(1)$, toàn bộ quy trình có độ phức tạp thời gian $O(\sqrt{n})$.

<span id="mở-rộng"></span>
## Mở rộng

Phần trên đã xét dạng phổ biến và cơ bản nhất của phân khối số học. Mục này tiếp tục xét các dạng mở rộng.

<span id="phân-khối-số-học-với-làm-tròn-lên"></span>
### Phân khối số học với làm tròn lên

Phân khối số học có thể dùng để tính các tổng chứa phép làm tròn lên:

$$
\sum_{i=1}^nf(i)g\left(\left\lceil\dfrac ni\right\rceil\right).
$$

Vì $\left\lceil\dfrac ni\right\rceil = \left\lfloor\dfrac {n-1}i\right\rfloor + 1$, tổng này có thể chuyển về trường hợp làm tròn xuống:

$$
f(n)g(1) + \sum_{i=1}^{n-1}f(i)g\left(\left\lfloor\dfrac {n-1}i\right\rfloor + 1\right).
$$

Cần chú ý rằng cận trên của tổng đã thay đổi, và hạng tử ứng với $i=n$ được tách riêng.

<span id="phân-khối-số-học-nhiều-chiều"></span>
### Phân khối số học nhiều chiều

Phân khối số học cũng có thể xử lý các tổng chứa nhiều hơn một biểu thức lấy phần nguyên:

$$
\sum_{i=1}^{n}f(i)g\left(\left\lfloor\dfrac {n_1}i\right\rfloor,\left\lfloor\dfrac {n_2}i\right\rfloor,\cdots,\left\lfloor\dfrac {n_m}i\right\rfloor\right).
$$

Để áp dụng ý tưởng phân khối số học, cần bảo đảm rằng trong mỗi khối, tất cả các biểu thức lấy phần nguyên $\left\lfloor\dfrac {n_1}i\right\rfloor,\left\lfloor\dfrac {n_2}i\right\rfloor,\cdots,\left\lfloor\dfrac {n_m}i\right\rfloor$ đều không đổi. Nói cách khác, khối nhiều chiều phải là giao của tất cả các khối một chiều. Vì vậy, với đầu mút trái $l$ đã biết, đầu mút phải tương ứng là

$$
\min\left\{\left\lfloor\dfrac {n_1}{\lfloor n_1/l\rfloor}\right\rfloor,\left\lfloor\dfrac {n_2}{\lfloor n_2/l\rfloor}\right\rfloor,\cdots,\left\lfloor\dfrac {n_m}{\lfloor n_m/l\rfloor}\right\rfloor\right\}.
$$

Nghĩa là lấy giá trị nhỏ nhất trong các đầu mút phải của mọi phân khối một chiều làm đầu mút phải của khối nhiều chiều. Có thể hình dung qua hình sau:

![Minh họa phân khối nhiều chiều](./images/n-dimension-sqrt-decomposition.svg)

Dạng hai chiều là trường hợp khá thường gặp. Khi đó, có thể thay dòng $r \gets \left\lfloor \dfrac{n}{\lfloor n/l \rfloor}\right\rfloor$ trong giả mã phía trên bằng

$$
r \gets \min\left\{\left\lfloor \dfrac{n_1}{\lfloor n_1/l \rfloor}\right\rfloor,\left\lfloor \dfrac{n_2}{\lfloor n_2/l \rfloor}\right\rfloor\right\}.
$$

<span id="phân-khối-số-học-với-số-mũ-tùy-ý"></span>
### Phân khối số học với số mũ tùy ý

Phân khối số học có thể dùng để tính các tổng có biểu thức lấy phần nguyên với số mũ tùy ý:

$$
\sum_{i=1}^{\lfloor n^{\alpha/\beta}\rfloor}f(i)g\left(\left\lfloor\dfrac {n^\alpha}{i^\beta}\right\rfloor\right).
$$

Trong đó $\alpha,\beta$ là các số thực dương. Ở dạng cơ bản đã xét trong bài, $\alpha=\beta=1$.

???+ note "Tính chất"
    Với số nguyên dương $n$ và các số thực dương $\alpha, \beta$, đặt
    
    $$
    D(n,\alpha,\beta) = \left\{\left\lfloor\dfrac{n^\alpha}{i^\beta}\right\rfloor: i=1,2,\cdots,\lfloor n^{\alpha/\beta}\rfloor\right\}.
    $$
    
    Khi đó:
    
    1.  $|D(n,\alpha,\beta)|\le 2n^{\alpha/(1+\beta)}$.
    2.  Với $d\in D(n,\alpha,\beta)$, các giá trị $i$ thỏa mãn $\left\lfloor\dfrac{n^\alpha}{i^\beta}\right\rfloor=d$ nằm trong khoảng
    
        $$
        \left\lfloor\dfrac{n^{\alpha/\beta}}{(d+1)^{1/\beta}}\right\rfloor + 1\le i \le \left\lfloor\dfrac{n^{\alpha/\beta}}{d^{1/\beta}}\right\rfloor.
        $$

??? note "Chứng minh"
    Với mệnh đề thứ nhất, xét hai trường hợp:
    
    -   Khi $i\le \dfrac{n^\alpha}{i^\beta}$, ta có $i\le n^{\alpha/(1+\beta)}$, nên $\left\lfloor\dfrac{n^\alpha}{i^\beta}\right\rfloor$ có nhiều nhất $n^{\alpha/(1+\beta)}$ giá trị.
    -   Khi $i > \dfrac{n^\alpha}{i^\beta}$, ta có $i> n^{\alpha/(1+\beta)}$, suy ra $\dfrac{n^\alpha}{i^\beta} < n^{\alpha/(1+\beta)}$, nên $\left\lfloor\dfrac{n^\alpha}{i^\beta}\right\rfloor$ cũng có nhiều nhất $n^{\alpha/(1+\beta)}$ giá trị.
    
    Tổng hợp hai trường hợp, ta có $|D(n,\alpha,\beta)|\le 2n^{\alpha/(1+\beta)}$.
    
    Với mệnh đề thứ hai, $\left\lfloor\dfrac{n^\alpha}{i^\beta}\right\rfloor=d$ tương đương với
    
    $$
    d \le \dfrac{n^\alpha}{i^\beta} < d+1 \iff \dfrac{n^{\alpha/\beta}}{(d+1)^{1/\beta}} < i \le \dfrac{n^{\alpha/\beta}}{d^{1/\beta}}.
    $$
    
    Lấy phần nguyên của bất đẳng thức trên sẽ thu được mệnh đề thứ hai.

Dựa vào các tính chất này, ta có thể thực hiện phân khối số học với số mũ tùy ý trong $O(n^{\alpha/(1+\beta)})$.

???+ example "Ví dụ"
    Chẳng hạn, với $\alpha=\beta=1/2$, tổng sau
    
    $$
    \sum_{i=1}^nf(i)g\left(\left\lfloor\sqrt{\dfrac {n}{i}}\right\rfloor\right)
    $$
    
    có thể được giải bằng phân khối số học trong $O(n^{1/3})$. Khi biết đầu mút trái của khối là $l$, ta có thể tính đầu mút phải là $r=\left\lfloor\dfrac{n}{\lfloor\sqrt{n/l}\rfloor^2}\right\rfloor$.

<span id="bài-tập-ví-dụ"></span>
## Bài tập ví dụ

???+ example "[UVa11526 H(n)](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2521)"
    Có $T$ bộ dữ liệu, mỗi bộ gồm một số nguyên $n$. Với mỗi bộ dữ liệu, hãy in ra $\sum_{i=1}^n\left\lfloor\dfrac ni\right\rfloor$.

??? note "Lời giải"
    Theo phân tích ở trên, có thể tính gộp các chỉ số thuộc cùng một khối có giá trị $\left\lfloor\dfrac ni\right\rfloor$ giống nhau. Độ phức tạp thời gian là $O(T\sqrt n)$.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/sqrt-decomposition/sqrt-decomposition_1.cpp"
    ```

???+ example "[Codeforces 1954E Chain Reaction](https://codeforces.com/contest/1954/problem/E)"
    Có một hàng gồm $n$ quái vật, quái vật thứ $i$ có lượng máu ban đầu là $a_i$. Một lần tấn công làm giảm $k$ máu của một đoạn liên tiếp các quái vật còn sống; quái vật có máu không dương được xem là đã chết. Với mọi $k$, hãy tính số lần tấn công cần để tiêu diệt toàn bộ quái vật. Trong đó $n,a_i\leq 10^5$.

??? note "Lời giải"
    Đặt $a_0=0$. Giả sử cần $T(k,i-1)$ lần tấn công để tiêu diệt tất cả $(i-1)$ quái vật đầu tiên, và quái vật thứ $i$ có lượng máu là $a_i$. Khi tiêu diệt quái vật thứ $(i-1)$, cần tấn công nó $\lceil a_{i-1}/k\rceil$ lần; các đòn tấn công này đều có thể kéo dài sang quái vật thứ $i$. Vì vậy, để tiêu diệt quái vật thứ $i$, ta chỉ cần tấn công thêm $\max\{0,\lceil a_i/k\rceil-\lceil a_{i-1}/k\rceil\}$ lần. Do đó, tổng số lần tấn công là
    
    $$
    T(k,n)=\sum_{i=1}^n\max\left(0,\left\lceil\dfrac{a_i}{k}\right\rceil-\left\lceil\dfrac{a_{i-1}}{k}\right\rceil\right).
    $$
    
    Vì các giá trị $n,k$ trong bài đều lớn, không thể tính riêng tổng này cho từng $k$. Ta có thể xét từng $i=1,2,\cdots,n$ và duy trì dãy $\{T(k,i)\}_k$. Ban đầu đặt $T(k,0)\equiv 0$. Giả sử đã biết dãy $\{T(k,i-1)\}_k$, ta xét cách sửa nó để thu được dãy $\{T(k,i)\}_k$. Theo phân tích trên, chỉ cần cộng thêm $\max\left(0,\left\lceil\dfrac{a_i}{k}\right\rceil-\left\lceil\dfrac{a_{i-1}}{k}\right\rceil\right)$ vào phần tử thứ $k$ của dãy. Dùng phân khối số học hai chiều, thao tác sửa đổi này có thể tách thành $O(\sqrt{a_{i-1}}+\sqrt{a_i})$ phép cộng trên đoạn, và giá trị được cộng trên mỗi đoạn là cố định. Dãy $\{T(k,n)\}_k$ cuối cùng chính là đáp án.
    
    Bài toán gồm một loạt thao tác cộng trên đoạn, còn truy vấn chỉ diễn ra sau khi mọi sửa đổi đã hoàn tất. Vì vậy, ta có thể duy trì mảng hiệu để thực hiện cộng trên đoạn, rồi lấy tổng tiền tố ở cuối để thu được dãy cần tìm. Tổng độ phức tạp thời gian là $O(\sum\sqrt{a_i})$. Bài này cũng có các cách giải khác.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/sqrt-decomposition/sqrt-decomposition_2.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

-   [UVa11526 H(n)](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2521)
-   [Luogu P2261 CQOI2007 Tổng phần dư](https://www.luogu.com.cn/problem/P2261)
-   [Luogu P3455 POI2007 ZAP-Queries](https://www.luogu.com.cn/problem/P3455)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [Phân tích độ phức tạp thời gian và bộ nhớ của sàng Dujiao, bởi riteme](https://riteme.site/blog/2018-9-11/time-space-complexity-dyh-algo.html)
