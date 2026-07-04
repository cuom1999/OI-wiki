<span id="&#x5F15;&#x5165;"></span>
## Dẫn nhập

> Bài toán "không biết số vật": Có một số vật chưa rõ là bao nhiêu. Đếm theo nhóm $3$ thì dư $2$, theo nhóm $5$ thì dư $3$, theo nhóm $7$ thì dư $2$. Hỏi có bao nhiêu vật?

Tức là cần tìm số nguyên thỏa các điều kiện: chia cho $3$ dư $2$, chia cho $5$ dư $3$, chia cho $7$ dư $2$.

Bài toán này xuất hiện sớm nhất trong *Sunzi Suanjing*, kèm theo lời giải cụ thể. Năm 1247, nhà toán học Tần Cửu Thiều thời Tống đã đưa ra lời giải đầy đủ và có hệ thống cho bài toán này trong phần "Đại diễn" của quyển một và quyển hai sách *Shushu Jiuzhang*. Với bài toán cụ thể ở trên, bài quyết do nhà toán học Trình Đại Vị thời Minh nêu trong *Suanfa Tongzong* có thể diễn giải như sau:

> Ba người đi cùng: bảy mươi hiếm; năm cây mai: hai mươi mốt cành; bảy con sum họp: đúng nửa tháng; trừ đi một trăm linh năm là biết.

$2\times 70+3\times 21+2\times 15=233=2\times 105+23$, nên đáp án là $23$.

<span id="&#x5B9A;&#x4E49;"></span>
## Định nghĩa

Định lý số dư Trung Hoa (Chinese Remainder Theorem, CRT) có thể giải hệ phương trình đồng dư tuyến tính một ẩn có dạng sau, trong đó $n_1, n_2, \cdots, n_k$ đôi một nguyên tố cùng nhau:

$$
\begin{cases}
x &\equiv a_1 \pmod {n_1} \\
x &\equiv a_2 \pmod {n_2} \\
  &\vdots \\
x &\equiv a_k \pmod {n_k} \\
\end{cases}
$$

Bài toán "không biết số vật" ở trên là một ví dụ của hệ phương trình đồng dư tuyến tính một ẩn.

<span id="&#x8FC7;&#x7A0B;"></span>
## Quy trình

1.  Tính tích $n$ của tất cả các modulo.
2.  Với phương trình thứ $i$:
    1.  Tính $m_i=\frac{n}{n_i}$.
    2.  Tính [nghịch đảo](./inverse.md) $m_i^{-1}$ của $m_i$ theo modulo $n_i$.
    3.  Tính $c_i=m_im_i^{-1}$ (**không lấy modulo theo $n_i$**).
3.  Nghiệm duy nhất của hệ phương trình theo modulo $n$ là: $x=\sum_{i=1}^k a_ic_i \pmod n$.

<span id="&#x5B9E;&#x73B0;"></span>
## Cài đặt

=== "C++"
    ```cpp
    LL CRT(int k, LL* a, LL* r) {
      LL n = 1, ans = 0;
      for (int i = 1; i <= k; i++) n = n * r[i];
      for (int i = 1; i <= k; i++) {
        LL m = n / r[i], b, y;
        exgcd(m, r[i], b, y);  // b * m mod r[i] = 1
        ans = (ans + a[i] * m * b % n) % n;
      }
      return (ans % n + n) % n;
    }
    ```

=== "Python"
    ```python
    def CRT(k, a, r):
        n = 1
        ans = 0
        for i in range(1, k + 1):
            n = n * r[i]
        for i in range(1, k + 1):
            m = n // r[i]
            b = y = 0
            exgcd(m, r[i], b, y)  # b * m mod r[i] = 1
            ans = (ans + a[i] * m * b % n) % n
        return (ans % n + n) % n
    ```

<span id="&#x8BC1;&#x660E;"></span>
## Chứng minh

Cần chứng minh rằng $x$ do thuật toán trên tính được thỏa $x\equiv a_i \pmod {n_i}$ với mọi $i=1,2,\cdots,k$.

Khi $i\neq j$, ta có $m_j \equiv 0 \pmod {n_i}$, nên $c_j \equiv m_j \equiv 0 \pmod {n_i}$. Lại có $c_i \equiv m_i \cdot (m_i^{-1} \bmod {n_i}) \equiv 1 \pmod {n_i}$, vì vậy:

$$
\begin{aligned}
x&\equiv \sum_{j=1}^k a_jc_j                      &\pmod {n_i} \\
 &\equiv a_ic_i                                   &\pmod {n_i} \\
 &\equiv a_i \cdot m_i \cdot (m^{-1}_i \bmod n_i) &\pmod {n_i} \\
 &\equiv a_i                                      &\pmod {n_i}
\end{aligned}
$$

Tức là với mọi $i=1,2,\cdots,k$, giá trị $x$ thu được từ thuật toán luôn thỏa $x\equiv a_i \pmod{n_i}$; do đó tính đúng đắn của thuật toán giải hệ đồng dư đã được chứng minh.

Vì không đặt ràng buộc đặc biệt nào lên đầu vào $a_i$, mọi bộ đầu vào $\{a_i\}$ đều tương ứng với một nghiệm $x$. Ngoài ra, nếu $x\neq y$ thì luôn tồn tại $i$ sao cho $x$ và $y$ không đồng dư modulo $n_i$. Vì vậy danh sách hệ số $\{a_i\}$ và nghiệm $x$ tạo thành một ánh xạ một-một, nên hệ phương trình luôn có nghiệm duy nhất.

<span id="&#x89E3;&#x91CA;"></span>
## Giải thích

Dưới đây minh họa cách CRT giải bài toán "không biết số vật".

1.  $n=3\times 5\times 7=105$.
2.  "Ba người đi cùng: **bảy mươi** hiếm": $n_1=3, m_1=n/n_1=35, m_1^{-1}\equiv 2\pmod 3$, nên $c_1=35\times 2=70$.
3.  "Năm cây mai: **hai mươi mốt** cành": $n_2=5, m_2=n/n_2=21, m_2^{-1}\equiv 1\pmod 5$, nên $c_2=21\times 1=21$.
4.  "Bảy con sum họp: đúng **nửa tháng**": $n_3=7, m_3=n/n_3=15, m_3^{-1}\equiv 1\pmod 7$, nên $c_3=15\times 1=15$.
5.  Do đó nghiệm duy nhất của hệ là $x\equiv 2\times 70+3\times 21+2\times 15\equiv 233\equiv 23 \pmod {105}$. (Trừ đi **một trăm linh năm** là biết.)

<span id="garner-&#x7B97;&#x6CD5;"></span>
## Thuật toán Garner

Một ứng dụng khác của CRT là dùng một nhóm số nguyên tố tương đối nhỏ để biểu diễn một số nguyên lớn.

Ví dụ, nếu $a$ thỏa hệ phương trình tuyến tính sau và $a < \prod_{i=1}^k p_i$, trong đó $p_i$ là số nguyên tố:

$$
\begin{cases}
a &\equiv a_1 \pmod {p_1} \\
a &\equiv a_2 \pmod {p_2} \\
  &\vdots \\
a &\equiv a_k \pmod {p_k} \\
\end{cases}
$$

ta có thể biểu diễn $a$ dưới dạng sau, gọi là biểu diễn cơ số hỗn hợp của $a$:

$$
a = x_1 + x_2 p_1 + x_3 p_1 p_2 + \ldots + x_k p_1 \ldots p_{k-1}
$$

**Thuật toán Garner** dùng để tính các hệ số $x_1, \ldots, x_k$.

Gọi $r_{ij}$ là [nghịch đảo](./inverse.md) của $p_i$ theo modulo $p_j$:

$$
p_i \cdot r_{i,j} \equiv 1 \pmod{p_j}
$$

Thay $a$ vào phương trình thứ nhất, ta được:

$$
a_1 \equiv x_1 \pmod{p_1}
$$

Thay vào phương trình thứ hai, ta được:

$$
a_2 \equiv x_1 + x_2 p_1 \pmod{p_2}
$$

Trừ $x_1$ hai vế rồi chia cho $p_1$, ta có

$$
\begin{aligned}
    a_2 - x_1           &\equiv x_2 p_1             &\pmod{p_2} \\
    (a_2 - x_1) r_{1,2} &\equiv x_2                 &\pmod{p_2} \\
    x_2                 &\equiv (a_2 - x_1) r_{1,2} &\pmod{p_2}
\end{aligned}
$$

Tương tự, ta có:

$$
x_k=(\dots((a_k-x_1)r_{1,k}-x_2)r_{2,k})-\dots)r_{k-1,k} \bmod p_k
$$

??? note "Cài đặt"
    === "C++"
        ```cpp
        for (int i = 0; i < k; ++i) {
          x[i] = a[i];
          for (int j = 0; j < i; ++j) {
            x[i] = r[j][i] * (x[i] - x[j]);
            x[i] = x[i] % p[i];
            if (x[i] < 0) x[i] += p[i];
          }
        }
        ```
    
    === "Python"
        ```python
        for i in range(0, k):
            x[i] = a[i]
            for j in range(0, i):
                x[i] = r[j][i] * (x[i] - x[j])
                x[i] = x[i] % p[i]
                if x[i] < 0:
                    x[i] = x[i] + p[i]
        ```

Độ phức tạp thời gian của thuật toán này là $O(k^2)$. Thực ra thuật toán Garner không yêu cầu các modulo là số nguyên tố; chỉ cần chúng đôi một nguyên tố cùng nhau. Ta có mã giả sau:

$$
\begin{array}{ll}
&\textbf{Chinese Remainder Algorithm }\operatorname{cra}(\mathbf{v}, \mathbf{m})\text{:} \\
&\textbf{Input}\text{: }\mathbf{m}=(m_0,m_1,\dots ,m_{n-1})\text{, }m_i\in\mathbb{Z}^+\land\gcd(m_i,m_j)=1\text{ for all } i\neq j\text{,} \\
&\qquad \mathbf{v}=(v_0,\dots ,v_{n-1}) \text{ where }v_i=x\bmod m_i\text{.} \\
&\textbf{Output}\text{: }x\bmod{\prod_{i=0}^{n-1} m_i}\text{.} \\
1&\qquad \textbf{for }i\text{ from }1\text{ to }(n-1)\textbf{ do} \\
2&\qquad \qquad C_i\gets \left(\prod_{j=0}^{i-1}m_j\right)^{-1}\bmod{m_i} \\
3&\qquad x\gets v_0 \\
4&\qquad \textbf{for }i\text{ from }1\text{ to }(n-1)\textbf{ do} \\
5&\qquad \qquad u\gets (v_i-x)\cdot C_i\bmod{m_i} \\
6&\qquad \qquad x\gets x+u\prod_{j=0}^{i-1}m_j \\
7&\qquad \textbf{return }(x)
\end{array}
$$

Có thể thấy phép tính ở dòng 6 tương ứng với biểu diễn cơ số hỗn hợp ở trên.

<span id="&#x5E94;&#x7528;"></span>
## Ứng dụng

Trong một số bài toán đếm hoặc bài toán số học, để kéo dài mã nguồn, tăng độ khó, hoặc vì một lý do khác nào đó, modulo được cho **không phải số nguyên tố**.

Tuy nhiên, khi phân tích thừa số nguyên tố của nó, ta thấy nó không có thừa số chính phương; tức modulo đó là tích của một số nguyên tố khác nhau.

Khi đó, ta có thể tính riêng theo các modulo này, rồi dùng CRT để ghép đáp án cuối cùng.

Bài sau là một ví dụ tốt.

???+ note "[Luogu P2480, SDOI2010: văn bản lợn cổ đại](https://www.luogu.com.cn/problem/P2480)"
    Cho $G,n$ ($1 \leq G,n \leq 10^9$), hãy tính:
    
    $$
    G^{\sum_{k\mid n}\binom{n}{k}} \bmod 999~911~659
    $$

Trước hết, khi $G=999~911~659$, giá trị cần tìm hiển nhiên bằng $0$.

Ngược lại, theo [định lý Euler](./fermat.md), giá trị cần tìm là:

$$
G^{\sum_{k\mid n}\binom{n}{k} \bmod 999~911~658} \bmod 999~911~659
$$

Bây giờ xét cách tính:

$$
\sum_{k\mid n}\binom{n}{k} \bmod 999~911~658
$$

Vì $999~911~658$ không phải số nguyên tố, không thể bảo đảm mọi $x \in [1,999~911~657]$ đều có nghịch đảo, nên biểu thức trên không thể được tính trực tiếp theo cách thông thường.

Chú ý $999~911~658=2 \times 3 \times 4679 \times 35617$, trong đó bậc cao nhất của mỗi thừa số nguyên tố đều bằng một. Vì vậy có thể lần lượt tính $\sum_{k\mid n}\binom{n}{k}$ theo các modulo nguyên tố $2$, $3$, $4679$, $35617$, rồi dùng định lý số dư Trung Hoa để ghép đáp án.

Nói cách khác, thực chất ta cần tìm nghiệm của hệ phương trình tuyến tính sau:

$$
\begin{cases}
x \equiv a_1 \pmod 2\\
x \equiv a_2 \pmod 3\\
x \equiv a_3 \pmod {4679}\\
x \equiv a_4 \pmod {35617}
\end{cases}
$$

Để tính một tổ hợp modulo một số nguyên tố nhỏ hơn, có thể dùng [định lý Lucas](./lucas.md).

<span id="&#x6269;&#x5C55;&#xFF1A;&#x6A21;&#x6570;&#x4E0D;&#x4E92;&#x8D28;&#x7684;&#x60C5;&#x51B5;"></span>
## Mở rộng: trường hợp các modulo không nguyên tố cùng nhau

<span id="&#x4E24;&#x4E2A;&#x65B9;&#x7A0B;"></span>
### Hai phương trình

Giả sử hai phương trình là $x\equiv a_1 \pmod {m_1}$ và $x\equiv a_2 \pmod {m_2}$.

Chuyển chúng thành phương trình nghiệm nguyên: $x=m_1p+a_1=m_2q+a_2$, trong đó $p, q$ là các số nguyên. Khi đó $m_1p-m_2q=a_2-a_1$.

Theo [định lý Bezout](./bezouts.md), nếu $a_2-a_1$ không chia hết cho $\gcd(m_1,m_2)$ thì hệ vô nghiệm.

Trong các trường hợp còn lại, có thể dùng [thuật toán Euclid mở rộng](./gcd.md) để tìm một nghiệm khả thi $(p, q)$.

Khi đó nghiệm của hệ modulo gồm hai phương trình ban đầu là $x\equiv b\pmod M$, trong đó $b=m_1p+a_1$ và $M=\text{lcm}(m_1, m_2)$.

<span id="&#x591A;&#x4E2A;&#x65B9;&#x7A0B;"></span>
### Nhiều phương trình

Dùng phương pháp trên để ghép từng cặp phương trình.

<span id="&#x4E60;&#x9898;"></span>
## Bài tập

-   [Mẫu: định lý số dư Trung Hoa (CRT) / Cao Chong nuôi lợn](https://www.luogu.com.cn/problem/P1495)
-   [Mẫu: định lý số dư Trung Hoa mở rộng](https://www.luogu.com.cn/problem/P4777)
-   [NOI2018: Dũng sĩ diệt rồng](https://uoj.ac/problem/396)
-   [TJOI2009: đoán số](https://www.luogu.com.cn/problem/P3868)

    **Một phần nội dung trang này được dịch từ bài viết [Russian: Chinese Remainder Theorem](http://e-maxx.ru/algo/chinese_theorem) và bản dịch tiếng Anh [Chinese Remainder Theorem](https://cp-algorithms.com/algebra/chinese-remainder-theorem.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.**
