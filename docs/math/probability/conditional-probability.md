<span id="tổng-quan"></span>
## Tổng quan

Khi một biến cố đã xảy ra, xác suất của một số biến cố ngẫu nhiên khác có thể thay đổi do ta có thêm thông tin. Chẳng hạn trong trò chơi gacha trên điện thoại, ban đầu ta có thể nghĩ rằng xác suất rút được và không rút được nhân vật sáu sao trong một lượt là ngang nhau; nhưng nếu đã rút liên tiếp $50$ lượt mà vẫn không có sáu sao, việc tiếp tục khăng khăng rằng "rút được sáu sao và không rút được sáu sao là đồng xác suất" sẽ không còn hợp lý nữa.

Vì vậy, việc nghiên cứu xác suất của biến cố dưới một số điều kiện đã biết là cần thiết.

<span id="xác-suất-có-điều-kiện"></span>
## Xác suất có điều kiện

<span id="định-nghĩa"></span>
### Định nghĩa

Nếu đã biết biến cố $A$ xảy ra, xác suất để biến cố $B$ xảy ra dưới điều kiện đó được gọi là **xác suất có điều kiện**, ký hiệu là $P(B|A)$.

Trong không gian xác suất $(\Omega, \mathcal{F}, P)$, nếu biến cố $A \in \mathcal{F}$ thỏa $P(A) > 0$, thì xác suất có điều kiện $P(\cdot|A)$ được định nghĩa bởi

$$
P(B|A) = \frac{P(AB)}{P(A)} \quad \forall B \in \mathcal{F}
$$

Có thể kiểm tra rằng $P(\cdot|A)$ định nghĩa theo công thức trên là một hàm xác suất trên $(\Omega, \mathcal{F})$.

Từ định nghĩa xác suất có điều kiện, ta suy ra trực tiếp hai công thức sau:

-   **Công thức nhân xác suất**: trong không gian xác suất $(\Omega, \mathcal{F}, P)$, nếu $P(A) > 0$, thì với mọi biến cố $B$ ta có

$$
P(AB) = P(A)P(B|A)
$$

-   **Công thức xác suất toàn phần**: trong không gian xác suất $(\Omega, \mathcal{F}, P)$, nếu các biến cố $A_1, \cdots, A_n$ đôi một rời nhau và có hợp bằng $\Omega$, thì với mọi biến cố $B$ ta có

$$
P(B) = \sum_{i=1}^{n} P(A_i)P(B|A_i)
$$

<span id="công-thức-bayes"></span>
### Công thức Bayes

Nói chung, giả sử các nguyên nhân có thể dẫn đến biến cố $B$ là $A_1, A_2, \cdots, A_n$. Khi đã biết $P(A_i)$ và $P(B|A_i)$, ta có thể dùng công thức xác suất toàn phần để tính xác suất xảy ra của biến cố $B$. Tuy nhiên, trong nhiều trường hợp, ta cần suy ngược từ kết quả "biến cố $B$ đã xảy ra" để tính xác suất xảy ra của từng biến cố nguyên nhân. Khi đó ta có

$$
P(A_i|B) = \frac{P(A_iB)}{P(B)} = \frac{P(A_i)P(B|A_i)}{\sum_{j=1}^{n} P(A_j)P(B|A_j)}
$$

Công thức trên chính là công thức Bayes.

<span id="tính-độc-lập-của-biến-cố"></span>
## Tính độc lập của biến cố

Khi nghiên cứu xác suất có điều kiện, có thể xuất hiện trường hợp $P(B|A) = P(B)$. Trực quan mà nói, việc biến cố $B$ có xảy ra hay không không cung cấp cho ta thông tin nào về biến cố $A$, tức biến cố $B$ và biến cố $A$ "không liên quan" với nhau. Vì vậy, ta có định nghĩa sau.

<span id="định-nghĩa_1"></span>
### Định nghĩa

Nếu hai biến cố $A$, $B$ trong cùng một không gian xác suất thỏa

$$
P(AB) = P(A)P(B)
$$

thì ta nói $A$, $B$ **độc lập**. Với nhiều biến cố $A_1, A_2, \cdots, A_n$, ta nói chúng độc lập khi và chỉ khi với mọi nhóm biến cố $\{ A_{i_k} : 1 \leq i_1 < i_2 < \cdots < i_k \leq n \}$ đều có

$$
P( A_{i_1}A_{i_2} \cdots A_{i_r} ) = \prod_{k=1}^{r} P(A_{i_k})
$$

<span id="tính-độc-lập-của-nhiều-biến-cố"></span>
### Tính độc lập của nhiều biến cố

Với nhiều biến cố, nói chung không thể suy ra độc lập đồng thời chỉ từ độc lập từng đôi. Xét phản ví dụ sau:

Có một con xúc xắc tứ diện đều, trong đó ba mặt lần lượt được tô màu đỏ, xanh lá và xanh dương, còn mặt còn lại có đủ cả ba màu. Ta gieo con xúc xắc một lần, và gọi các biến cố $A$, $B$, $C$ lần lượt là mặt tiếp xúc với bàn có chứa màu đỏ, màu xanh lá, màu xanh dương.

Dễ tính được $P(A) = P(B) = P(C) = \frac{1}{2}$, còn $P(AB) = P(BC) = P(CA) = P(ABC) = \frac{1}{4}$.

Rõ ràng $A, B, C$ độc lập từng đôi, nhưng vì $P(ABC) \neq P(A)P(B)P(C)$ nên $A, B, C$ không độc lập đồng thời.
