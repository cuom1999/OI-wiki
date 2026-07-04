author: Marcythm, Xeonacid, CSPNOIP

<span id="&#x5B9A;&#x4E49;"></span>
## Định nghĩa

Xét theo ý tưởng của phương pháp sàng này, nó còn được gọi là "Extended Eratosthenes Sieve".

Vì phương pháp này do [Min_25](https://web.archive.org/web/20211104125457/http://min-25.hatenablog.com/) phát minh và sử dụng sớm nhất, nên được gọi là "sàng Min_25".

<span id="&#x6027;&#x8D28;"></span>
## Tính chất

Sàng này có thể giải một lớp bài toán tính tổng tiền tố của **hàm nhân** với độ phức tạp thời gian $O\left(\frac{n^{\frac{3}{4}}}{\log{n}}\right)$ hoặc $\Theta\left(n^{1 - \epsilon}\right)$.

Yêu cầu: $f(p)$ là tổng của các hàm hoàn toàn nhân theo $p$ có thể tính nhanh (ví dụ đa thức); $f(p^{c})$ có thể tính nhanh.

<span id="&#x8BB0;&#x53F7;"></span>
## Kí hiệu

-   **Nếu không có giải thích đặc biệt, mọi biến được kí hiệu là $p$ trong mục này đều lấy giá trị trên tập tất cả số nguyên tố.**
-   $x / y := \left\lfloor\frac{x}{y}\right\rfloor$
-   $\operatorname{isprime}(n) := [ |\{d : d \mid n\}| = 2 ]$, tức là giá trị bằng $1$ khi $n$ là số nguyên tố, ngược lại bằng $0$.
-   $p_{k}$: số nguyên tố nhỏ thứ $k$ trong tập tất cả số nguyên tố (ví dụ: $p_{1} = 2, p_{2} = 3$). Đặc biệt, đặt $p_{0} = 1$.
-   $\operatorname{lpf}(n) := [1 < n] \min\{p : p \mid n\} + [1 = n]$, tức là thừa số nguyên tố nhỏ nhất của $n$. Đặc biệt, khi $n=1$, giá trị này bằng $1$.
-   $F_{\mathrm{prime}}(n) := \sum_{2 \le p \le n} f(p)$
-   $F_{k}(n) := \sum_{i = 2}^{n} [p_{k} \le \operatorname{lpf}(i)] f(i)$

<span id="&#x89E3;&#x91CA;"></span>
## Giải thích

Quan sát định nghĩa của $F_{k}(n)$, có thể thấy đáp án chính là $F_{1}(n) + f(1) = F_{1}(n) + 1$.

Xét cách tính $F_{k}(n)$. Bằng cách liệt kê thừa số nguyên tố nhỏ nhất của mỗi $i$ và số lần xuất hiện của nó, ta thu được công thức truy hồi:

$$
\begin{aligned}
    F_{k}(n)
    &= \sum_{i = 2}^{n} [p_{k} \le \operatorname{lpf}(i)] f(i) \\
    &= \sum_{\substack{k \le i \\ p_{i}^{2} \le n}} \sum_{\substack{c \ge 1 \\ p_{i}^{c} \le n}} f\left(p_{i}^{c}\right) ([c > 1] + F_{i + 1}\left(n / p_{i}^{c}\right)) + \sum_{\substack{k \le i \\ p_{i} \le n}} f(p_{i}) \\
    &= \sum_{\substack{k \le i \\ p_{i}^{2} \le n}} \sum_{\substack{c \ge 1 \\ p_{i}^{c} \le n}} f\left(p_{i}^{c}\right) ([c > 1] + F_{i + 1}\left(n / p_{i}^{c}\right)) + F_{\mathrm{prime}}(n) - F_{\mathrm{prime}}(p_{k - 1}) \\
    &= \sum_{\substack{k \le i \\ p_{i}^{2} \le n}} \sum_{\substack{c \ge 1 \\ p_{i}^{c + 1} \le n}} \left(f\left(p_{i}^{c}\right) F_{i + 1}\left(n / p_{i}^{c}\right) + f\left(p_{i}^{c + 1}\right)\right) + F_{\mathrm{prime}}(n) - F_{\mathrm{prime}}(p_{k - 1})
\end{aligned}
$$

Bước suy diễn cuối cùng dựa trên sự thật sau: với $c$ thỏa mãn $p_{i}^{c} \le n < p_{i}^{c + 1}$, ta có $p_{i}^{c + 1} > n \iff n / p_{i}^{c} < p_{i} < p_{i + 1}$, nên $F_{i + 1}\left(n / p_{i}^{c}\right) = 0$.
Giá trị biên là $F_{k}(n) = 0 (p_{k} > n)$.

Giả sử hiện đã tính được mọi $F_{\mathrm{prime}}(n)$, có hai cách để tính mọi $F_{k}(n)$:

1.  Tính trực tiếp theo công thức truy hồi.
2.  Liệt kê $p$ từ lớn xuống nhỏ để chuyển trạng thái; chỉ khi $p^{2} < n$ thì phần tăng thêm của chuyển trạng thái mới khác không, nên có thể tối ưu bằng tổng hậu tố theo công thức truy hồi.

Bây giờ xét cách tính $F_{\mathrm{prime}}{(n)}$.
Quan sát quá trình tính $F_{k}(n)$, dễ thấy $F_{\mathrm{prime}}$ chỉ cần các giá trị tại $1, 2, \dots, \left\lfloor\sqrt{n}\right\rfloor, n / \sqrt{n}, \dots, n / 2, n$, tổng cộng $O(\sqrt{n})$ điểm hữu dụng.
Thông thường, $f(p)$ là một đa thức bậc thấp theo $p$, có thể viết thành $f(p) = \sum a_{i} p^{c_{i}}$.
Khi đó, với mỗi $p^{c_{i}}$, phần đóng góp của nó vào $F_{\mathrm{prime}}(n)$ là $a_{i} \sum_{2 \le p \le n} p^{c_{i}}$.
Xét riêng phần đóng góp của từng $p^{c_{i}}$, bài toán chuyển thành: cho $n, s, g(p) = p^{s}$, với mọi $m = n / i$, hãy tính $\sum_{p \le m} g(p)$.

???+ tip "Lưu ý"
    $g(p) = p^{s}$ là hàm hoàn toàn nhân!

Do đó đặt $G_{k}(n) := \sum_{i = 2}^{n} \left[p_{k} < \operatorname{lpf}(i) \lor \operatorname{isprime}(i)\right] g(i)$, tức là tổng các giá trị $g$ của những số còn lại sau vòng sàng Eratosthenes thứ $k$.
Với một hợp số $x \le n$, chắc chắn có $\operatorname{lpf}(x) \le \sqrt{x} \le \sqrt{n}$. Gọi $p_{\ell(n)}$ là số nguyên tố lớn nhất không vượt quá $\sqrt{n}$, khi đó $\sum_{2\le p\le n}g(p) = G_{\ell(n)}(n)$, tức là sau khi sàng Eratosthenes chạy $\ell$ vòng, các số còn lại đều là số nguyên tố.
Xét giá trị biên của $G$, hiển nhiên $G_{0}(n) = \sum_{i = 2}^{n} g(i)$. (Còn nhớ không? Ta đã quy ước riêng $p_{0} = 1$.)
Với chuyển trạng thái, xét quá trình của sàng Eratosthenes và tách riêng đóng góp của từng phần:

1.  Với phần $n < p_{k}^{2}$, giá trị $G$ không đổi, tức $G_{k}(n) = G_{k - 1}(n)$.
2.  Với phần $p_{k}^{2} \le n$, các số bị sàng đi chắc chắn có thừa số nguyên tố $p_{k}$, tức là $-g(p_{k}) G_{k - 1}(n / p_{k})$.
3.  Với phần thứ hai, do $p_{k}^{2} \le n \iff p_{k} \le n / p_{k}$, các $i$ thỏa mãn $\operatorname{lpf}(i) < p_{k}$ sẽ bị trừ thừa. Phần này cần được cộng lại, tức là $g(p_{k}) G_{k - 1}(p_{k - 1})$.

Vậy có:

$$
G_{k}(n) = G_{k - 1}(n) - \left[p_{k}^{2} \le n\right] g(p_{k}) (G_{k - 1}(n / p_{k}) - G_{k - 1}(p_{k - 1}))
$$

<span id="&#x590D;&#x6742;&#x5EA6;&#x5206;&#x6790;"></span>
## Phân tích độ phức tạp

Với việc tính $F_{k}(n)$, độ phức tạp thời gian của phương pháp thứ nhất được chứng minh là $O\left(n^{1 - \epsilon}\right)$ (xem mục 2.3 trong luận văn đội tuyển tập huấn của Zhu Zhenting, ["Một số bài toán tính tổng hàm số học đặc biệt"](https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2018%E8%AE%BA%E6%96%87%E9%9B%86.pdf));
Với phương pháp thứ hai, bản chất của nó chính là phần thứ hai của sàng Zhouge, cũng được nhắc đến trong luận văn của Ren Zhizhou ["Một số phương pháp tính tổng hàm nhân"](https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2016%E8%AE%BA%E6%96%87%E9%9B%86.pdf) (6.5.4); độ phức tạp thời gian được chứng minh là $O\left(\frac{n^{\frac{3}{4}}}{\log{n}}\right)$.

Với việc tính $F_{\mathrm{prime}}(n)$, trên thực tế cách cài đặt giống phần thứ nhất của sàng Zhouge.
Xét từng $m = n / i$, chỉ khi liệt kê $p_{k}$ thỏa mãn $p_{k}^{2} \le m$ để chuyển trạng thái thì mới phát sinh đóng góp vào độ phức tạp thời gian, do đó có thể ước lượng:

$$
\begin{aligned}
    T(n)
    &= \sum_{i^{2} \le n} O\left(\pi\left(\sqrt{i}\right)\right) + \sum_{i^{2} \le n} O\left(\pi\left(\sqrt{\frac{n}{i}}\right)\right) \\
    &= \sum_{i^{2} \le n} O\left(\frac{\sqrt{i}}{\ln{\sqrt{i}}}\right) + \sum_{i^{2} \le n} O\left(\frac{\sqrt{\frac{n}{i}}}{\ln{\sqrt{\frac{n}{i}}}}\right) \\
    &= O\left(\int_{1}^{\sqrt{n}} \frac{\sqrt{\frac{n}{x}}}{\log{\sqrt{\frac{n}{x}}}} \mathrm{d} x\right) \\
    &= O\left(\frac{n^{\frac{3}{4}}}{\log{n}}\right)
\end{aligned}
$$

Về độ phức tạp không gian, có thể thấy dù là $F_{k}$ hay $F_{\mathrm{prime}}$, giá trị hữu hiệu của chúng chỉ xuất hiện tại các điểm $n / i$, tổng cộng $O(\sqrt{n})$ điểm. Chỉ ghi lại các giá trị hữu hiệu là có thể tối ưu độ phức tạp không gian xuống $O(\sqrt{n})$.

Trước hết, dùng một lần chia đoạn số học để lấy mọi giá trị hữu hiệu, lưu bằng một mảng $\text{lis}$ kích thước $O(\sqrt{n})$. Với giá trị hữu hiệu $v$, kí hiệu $\text{id}(v)$ là chỉ số của $v$ trong $\text{lis}$. Dễ thấy với mọi giá trị hữu hiệu $v$, $\text{id}(v) \le \sqrt{n}$.

Sau đó xét riêng các giá trị hữu hiệu không lớn hơn $\sqrt{n}$ và lớn hơn $\sqrt{n}$: với giá trị hữu hiệu $v$ không lớn hơn $\sqrt{n}$, dùng mảng $\text{le}$ ghi $\text{id}(v)$, tức $\text{le}_v = \text{id}(v)$; với giá trị hữu hiệu $v$ lớn hơn $\sqrt{n}$, dùng mảng $\text{ge}$ ghi $\text{id}(v)$. Vì $v$ quá lớn, ta mượn $v' = n / v < \sqrt{n}$ để ghi $\text{id}(v)$, tức $\text{ge}_{v'} = \text{id}(v)$.

Như vậy, có thể dùng hai mảng kích thước $O(\sqrt{n})$ để ghi $\text{id}$ của mọi giá trị hữu hiệu và truy vấn trong $O(1)$. Khi tính $F_{k}$ hoặc $F_{\mathrm{prime}}$, dùng $\text{id}$ của giá trị hữu hiệu thay cho chính giá trị hữu hiệu làm chỉ số, từ đó tối ưu độ phức tạp không gian xuống $O(\sqrt{n})$.

<span id="&#x8FC7;&#x7A0B;"></span>
## Quy trình

Khi tính $F_{k}(n)$, trong cài đặt ta thường chọn phương pháp thứ nhất vì dễ hiện thực hơn; với dữ liệu quy mô nhỏ, nó thường chạy tốt hơn phương pháp thứ hai.

Với việc tính $F_{\mathrm{prime}}(n)$, chỉ cần cài đặt trực tiếp theo công thức truy hồi.

Với $p_{k}^{2} \le n$, có thể dùng sàng tuyến tính tiền xử lí $s_{k} := F_{\mathrm{prime}}(p_{k})$ để thay thế $F_{\mathrm{prime}}(p_{k - 1})$ trong công thức truy hồi của $F_{k}$.
Tương tự, $G_{k - 1}(p_{k - 1}) = \sum_{i = 1}^{k - 1} g(p_{i})$ trong công thức truy hồi của $G$ cũng có thể được tiền xử lí theo cách này.

Khi dùng Extended Eratosthenes Sieve để tính tổng tiền tố của **hàm nhân** $f$, cần xác định rõ các điểm sau:

-   Cách sàng nhanh (thường là độ phức tạp tuyến tính) ra các giá trị $f$ đầu tiên trên đoạn đến $\sqrt{n}$;
-   Biểu diễn đa thức của $f(p)$;
-   Cách tính nhanh $f(p^{c})$.

Sau khi xác định rõ các điểm trên, chỉ cần lần lượt cài đặt các phần sau:

1.  Sàng các số nguyên tố và các giá trị $f$ đầu tiên trên đoạn $[1, \sqrt{n}]$;
2.  Với từng hạng tử trong biểu diễn đa thức của $f(p)$, sàng ra $G$ tương ứng, rồi gộp để thu được mọi giá trị hữu dụng $O(\sqrt{n})$ của $F_{\mathrm{prime}}$;
3.  Cài đặt đệ quy theo công thức truy hồi của $F_{k}$ để tính $F_{1}(n)$.

<span id="&#x4F8B;&#x9898;"></span>
## Ví dụ

???+ example "[Luogu P4213 mẫu sàng Dujiao](https://www.luogu.com.cn/problem/P4213)"
    Tính $\displaystyle \sum_{i = 1}^{n} \varphi(i)$ và $\displaystyle \sum_{i = 1}^{n} \mu(i)$.

??? note "Lời giải"
    Để tính tổng tiền tố của $\varphi(i)$, trước hết dễ biết $f(p) = p - 1$. Với hạng tử bậc nhất $(p)$ của $f(p)$, có $g(p) = p, G_{0}(n) = \sum_{i = 2}^{n} g(i) = \frac{(n + 2) (n - 1)}{2}$; với hạng tử hằng $(-1)$, có $g(p) = -1, G_{0}(n) = \sum_{i = 2}^{n} g(i) = -n + 1$. Sàng hai lần rồi cộng lại là thu được mọi giá trị cần thiết $O(\sqrt{n})$ của $F_{\mathrm{prime}}$.

    Để tính tổng tiền tố của $\mu(i)$, dễ biết $f(p) = -1$. Khi đó $g(p) = -1, G_{0}(n) = \sum_{i = 2}^{n} g(i) = -n + 1$. Sàng trực tiếp là thu được mọi giá trị cần thiết $O(\sqrt{n})$ của $F_{\mathrm{prime}}$.

???+ example "[LOJ 6053: Hàm đơn giản](https://loj.ac/p/6053)"
    Cho $f(n)$:

    $$
    f(n) = \begin{cases}
        1 & n = 1 \\
        p \operatorname{xor} c & n = p^{c} \\
        f(a)f(b) & n = ab \land a \perp b
    \end{cases}
    $$

    Tính $\displaystyle \sum_{i = 1}^{n} f(i)$.

??? note "Lời giải"
    Dễ biết $f(p) = p - 1 + 2[p = 2]$. Vậy có thể sàng theo cách sàng $\varphi$, chỉ cần thảo luận riêng trường hợp $2$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/min-25/min-25_1.cpp"
    ```
