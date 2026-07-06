<span id="định-nghĩa"></span>
## Định nghĩa

Sàng số lũy thừa mạnh, sau đây viết tắt là PN, tương tự sàng Dujiao, hoặc có thể xem là một mở rộng của sàng Dujiao, dùng để tính tổng tiền tố của một số hàm nhân.

**Yêu cầu**:

-   Tồn tại một hàm $g$ thỏa mãn:
    -   $g$ là hàm nhân.
    -   $g$ dễ tính tổng tiền tố.
    -   Với số nguyên tố $p$, $g(p) = f(p)$.

Giả sử hiện cần tính tổng tiền tố của hàm nhân $f$: $F(n) = \sum_{i=1}^{n} f(i)$.

## Số lũy thừa mạnh

**Định nghĩa**: Với số nguyên dương $n$, giả sử phân tích thừa số nguyên tố của $n$ là $n = \prod_{i=1}^{m} p_{i}^{e_{i}}$. $n$ là PN khi và chỉ khi $\forall 1 \le i \le m, e_{i} > 1$.

**Tính chất 1**: Mọi PN đều có thể biểu diễn dưới dạng $a^{2}b^{3}$.

**Chứng minh**: Nếu $e_i$ là số chẵn, gộp $p_{i}^{e_{i}}$ vào $a^{2}$; nếu $e_i$ là số lẻ, trước hết gộp $p_{i}^{3}$ vào $b^{3}$, rồi gộp $p_{i}^{e_{i}-3}$ vào $a^{2}$.

**Tính chất 2**: Số PN không vượt quá $n$ nhiều nhất là $O(\sqrt{n})$.

**Chứng minh**: Xét việc liệt kê $a$, rồi xét số lượng $b$ thỏa mãn điều kiện. Số PN xấp xỉ bằng

$$
\int_{1}^{\sqrt{n}} \sqrt[3]{\frac{n}{x^2}} \mathrm{d}x = O(\sqrt{n})
$$

Vậy làm thế nào để tìm mọi PN không vượt quá $n$? Dùng sàng tuyến tính tìm mọi số nguyên tố không vượt quá $\sqrt{n}$, rồi DFS trên số mũ của từng số nguyên tố. Vì số PN không vượt quá $n$ nhiều nhất là $O(\sqrt{n})$, nên số lần tìm kiếm cũng nhiều nhất là $O(\sqrt{n})$.

<span id="sàng-pn"></span>
## Sàng PN

Trước hết, xây dựng một hàm nhân $g$ dễ tính tổng tiền tố và thỏa mãn $g(p) = f(p)$ với mọi số nguyên tố $p$. Kí hiệu $G(n) = \sum_{i=1}^{n} g(i)$.

Tiếp theo, xây dựng hàm $h = f / g$, trong đó $/$ biểu thị phép chia theo tích chập Dirichlet. Theo tính chất của tích chập Dirichlet, $h$ cũng là hàm nhân, nên $h(1) = 1$. Khi đó $f = g * h$, trong đó $*$ biểu thị tích chập Dirichlet.

Với số nguyên tố $p$, $f(p) = g(1)h(p) + g(p)h(1) = h(p) + g(p) \implies h(p) = 0$. Từ $h(p)=0$ và việc $h$ là hàm nhân, suy ra với mọi số $n$ không phải PN thì $h(n) = 0$, tức là $h$ chỉ có giá trị hữu hiệu tại các PN.

Từ $f = g * h$, suy ra

$$
\begin{aligned}
F(n) &= \sum_{i = 1}^{n} f(i)\\
     &= \sum_{i = 1}^{n} \sum_{d|i} h(d) g\left(\frac{i}{d}\right)\\
     &= \sum_{d=1}^{n} \sum_{i=1}^{\lfloor \frac{n}{d}\rfloor} h(d) g(i)\\
     &= \sum_{d=1}^{n} h(d) \sum_{i=1}^{\lfloor \frac{n}{d}\rfloor}  g(i) \\
     &= \sum_{d=1}^{n} h(d) G\left(\left\lfloor \frac{n}{d}\right\rfloor\right)\\
     &= \sum_{\substack{d=1 \\ d \text{ là PN}}}^{n}h(d) G\left(\left\lfloor \frac{n}{d}\right\rfloor\right)
\end{aligned}
$$

Dùng $O(\sqrt{n})$ để tìm mọi PN và tính mọi giá trị hữu hiệu của $h$. Để tính các giá trị hữu hiệu của $h$, chỉ cần tính mọi giá trị tại $h(p^c)$, rồi dựa vào việc $h$ là hàm nhân để suy ra mọi giá trị hữu hiệu của $h$. Sau đó, với mỗi giá trị hữu hiệu $d$, tính $h(d)G\left(\left\lfloor \dfrac{n}{d} \right\rfloor\right)$ và cộng dồn là thu được $F(n)$.

Tiếp theo xét cách tính $h(p^c)$. Có hai phương pháp: một là trực tiếp suy ra công thức tính $h(p^c)$ chỉ liên quan đến $p,c$, rồi tính theo công thức; hai là từ $f = g * h$ có $f(p^c) = \sum_{i=0}^c g(p^i)h(p^{c-i})$, chuyển vế được $h(p^c) = f(p^c) - \sum_{i=1}^{c}g(p^i)h(p^{c-i})$, sau đó liệt kê số nguyên tố $p$ và số mũ $c$ để tính mọi $h(p^c)$.

<span id="quy-trình"></span>
### Quy trình

1.  Xây dựng $g$.
2.  Xây dựng cách tính nhanh $G$.
3.  Tính $h(p^c)$.
4.  Tìm kiếm PN, đồng thời cộng dồn đáp án.
5.  Thu được kết quả.

Với bước 3, có thể tính trực tiếp theo công thức, có thể tiền xử lí bằng cách liệt kê để lập bảng, hoặc chỉ suy ra tạm thời khi tìm kiếm đến.

<span id="tính-chất"></span>
### Tính chất

Phân tích với ví dụ dùng phương pháp thứ hai để tính $h(p^c)$. Có thể tách thành hai phần: tính $h(p^c)$ và tìm kiếm.

Với phần thứ nhất, số lượng số nguyên tố trong $O(\sqrt{n})$ là $O\left(\dfrac{\sqrt{n}}{\log n}\right)$, số mũ $c$ của mỗi số nguyên tố $p$ nhiều nhất là $\log n$, và để tính $h(p^c)$ cần lặp $(c - 1)$ lần. Do đó độ phức tạp thời gian của phần thứ nhất là $O\left(\dfrac{\sqrt{n}}{\log n} \cdot \log n \cdot \log n\right) = O(\sqrt{n}\log{n})$, và đây là một cận trên lỏng. Tùy bài toán còn có thể thêm các tối ưu khác để giảm độ phức tạp của phần thứ nhất.

Với phần tìm kiếm, vì số PN không vượt quá $n$ nhiều nhất là $O(\sqrt{n})$, nên tìm kiếm nhiều nhất $O(\sqrt{n})$ lần. Với mỗi PN, độ phức tạp phụ thuộc vào cách tính $G$. Ví dụ, nếu độ phức tạp tính $G\left(\left\lfloor \dfrac{n}{d}\right\rfloor\right)$ là $O(1)$, thì độ phức tạp của phần thứ hai là $O(\sqrt{n})$.

Đặc biệt, nếu dùng sàng Dujiao để tính $G\left(\left\lfloor \dfrac{n}{d}\right\rfloor\right)$, thì độ phức tạp thời gian của phần thứ hai chính là độ phức tạp của sàng Dujiao, tức $O(n^{\frac{2}{3}})$. Bởi nếu tính trước một lần $G(n)$, đồng thời tối ưu bằng sàng tuyến tính trước và dùng cấu trúc dữ liệu hỗ trợ truy cập ngẫu nhiên nhanh (như `std::map` và `std::unordered_map` trong C++) để ghi lại các giá trị lớn, thì các $G\left(\left\lfloor \dfrac{n}{d}\right\rfloor\right)$ được dùng trong quá trình sàng Dujiao đều đã được ghi trong sàng tuyến tính hoặc trong `std::map`; điều này có thể kiểm chứng trực tiếp bằng chương trình.

Về độ phức tạp không gian, nút thắt nằm ở việc lưu $h(p^c)$. Nếu dùng mảng hai chiều $a$ để ghi, trong đó $a_{i,j}$ biểu thị giá trị $h(p_i^j)$, thì độ phức tạp không gian là $O\left(\dfrac{\sqrt{n}}{\log n} \cdot \log n\right) = O(\sqrt{n})$.

<span id="ví-dụ"></span>
## Ví dụ

### [Luogu P5325 mẫu sàng Min_25](https://www.luogu.com.cn/problem/P5325)

**Đề bài**: Cho hàm nhân $f(p^k) = p^k(p^k-1)$, tính $\sum_{i=1}^{n} f(i)$.

Nhận thấy $f(p) = p(p-1) = \operatorname{id}(p)\varphi(p)$, xây dựng $g(n) = \operatorname{id}(n)\varphi(n)$.

Xét dùng sàng Dujiao để tính $G(n)$. Từ $(\operatorname{id}\cdot \varphi) * \operatorname{id} = \operatorname{id}_2$ suy ra $G(n)= \sum_{i=1}^{n} i^2 - \sum_{d=2}^{n} d \cdot G\left(\left\lfloor \dfrac{n}{d} \right\rfloor\right)$.

Sau đó có thể liệt kê để tính giá trị của $h(p^k)$; phương pháp này không trình bày thêm.

Ngoài ra, với bài này cũng có thể trực tiếp suy ra công thức $h(p^k)$ chỉ liên quan đến $p,k$, như sau:

$$
\begin{aligned}
& f(p^k) = \sum_{i=0}^{k} g(p^{k-i})h(p^i)\\
\iff & p^k(p^k-1) = \sum_{i=0}^{k} p^{k-i}\varphi(p^{k-i}) h(p^i)\\
\iff & p^k(p^k-1) = \sum_{i=0}^{k} p^{2k-2i-1}(p - 1) h(p^i)\\
\iff & p^k(p^k-1) = h(p^k) + \sum_{i=0}^{k-1} p^{2k-2i-1}(p - 1) h(p^i)\\
\iff & h(p^k) = p^k(p^k-1) - \sum_{i=0}^{k-1} p^{2k-2i-1}(p - 1) h(p^i)\\
\iff & h(p^k) - p^2h(p^{k-1}) = p^{k}(p^k-1)-p^{k+1}(p^{k-1}-1) - p(p-1)h(p^{k-1})\\
\iff & h(p^k) - ph(p^{k-1}) = p^{k+1} - p^k\\
\iff & \frac{h(p^k)}{p^k} - \frac{h(p^{k-1})}{p^{k-1}} = p - 1\\
\end{aligned}
$$

Kết hợp với $h(p) = 0$, bằng cách cộng dồn có thể suy ra $h(p^k) = (k-1)(p-1)p^k$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/powerful-number/powerful-number_1.cpp"
    ```

### [LOJ #6053: Hàm đơn giản](https://loj.ac/problem/6053)

Cho $f(n)$:

$$
f(n) =
\begin{cases}
1 & n = 1 \\
p \oplus c & n=p^c \\
f(a)f(b) & n=ab \text{ và } a \perp b
\end{cases}
$$

Nhận thấy:

$$
f(p) =
\begin{cases}
p + 1 & p = 2 \\
p - 1 & \text{ngược lại} \\
\end{cases}
$$

Xây dựng $g$ là

$$
g(n) =
\begin{cases}
3 \varphi(n) & 2 \mid n \\
\varphi(n) & \text{ngược lại} \\
\end{cases}
$$

Dễ chứng minh $g(p) = f(p)$ và $g$ là hàm nhân.

Tiếp theo xét cách tính $G(n)$.

$$
\begin{aligned}
G(n)
&= \sum_{i=1}^{n}[i \bmod 2 = 1] \varphi(i) + 3 \sum_{i=1}^{n}[i \bmod 2 = 0] \varphi(i)\\
&= \sum_{i=1}^{n} \varphi(i) + 2\sum_{i=1}^{n} [i \bmod 2 = 0]\varphi(i) \\
&= \sum_{i=1}^{n} \varphi(i) + 2\sum_{i=1}^{\lfloor \frac{n}{2} \rfloor} \varphi(2i)
\end{aligned}
$$

Đặt $S_1(n) = \sum_{i=1}^{n} \varphi(i)$, $S_2(n) = \sum_{i=1}^{n} \varphi(2i)$, khi đó $G(n) = S_1(n) + 2S_2\left(\left\lfloor \dfrac{n}{2} \right\rfloor\right)$.

Khi $2 \mid n$, có

$$
\begin{aligned}
S_2(n)
&= \sum_{i=1}^{n} \varphi(2i) \\
&= \sum_{i=1}^{\frac{n}{2}} (\varphi(2(2i-1)) + \varphi(2(2i))) \\
&= \sum_{i=1}^{\frac{n}{2}} (\varphi(2i-1) + 2\varphi(2i)) \\
&= \sum_{i=1}^{\frac{n}{2}} (\varphi(2i-1) + \varphi(2i)) + \sum_{i=1}^{\frac{n}{2}} \varphi(2i) \\
&= \sum_{i=1}^{n} \varphi(i) + S_2\left(\frac{n}{2}\right)\\
&= S_1(n) + S_2\left(\left\lfloor \frac{n}{2} \right\rfloor\right)\\
\end{aligned}
$$

Khi $2 \nmid n$, có

$$
\begin{aligned}
S_2(n)
&= S_2(n-1) + \varphi(2n) \\
&= S_2(n-1) + \varphi(n) \\
&= \sum_{i=1}^{n-1} \varphi(i) + S_2\left(\frac{n-1}{2}\right) + \varphi(n)\\
&= S_1(n) + S_2\left(\left\lfloor \frac{n}{2} \right\rfloor\right)\\
\end{aligned}
$$

Tổng hợp lại, $S_2(n) = S_1(n) + S_2\left(\left\lfloor \dfrac{n}{2} \right\rfloor\right)$.

$S_1$ có thể tính bằng sàng Dujiao, còn $S_2$ được suy trực tiếp theo công thức, nhờ đó cũng tính được $G$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/powerful-number/powerful-number_2.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

-   [PE708 Twos are all you need](https://projecteuler.net/problem=708)
-   [PE639 Summing a multiplicative function](https://projecteuler.net/problem=639)
-   [PE484 Arithmetic Derivative](https://projecteuler.net/problem=484)

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

-   [wallbreaker5th - Giới thiệu ngắn về sàng số lũy thừa mạnh](https://www.cnblogs.com/wallbreaker5th/p/13901487.html)
-   [command_block - Sàng Dujiao (+ chuỗi Bell + powerful number)](https://www.luogu.com.cn/blog/command-block/du-jiao-shai)
