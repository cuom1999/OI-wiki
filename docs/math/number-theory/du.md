author: hsfzLZH1, sshwy, StudyingFather, Marcythm

Sàng Dujiao được dùng để xử lí một lớp bài toán tính tổng tiền tố của hàm số học. Với hàm số học $f$, sàng Dujiao có thể tính $S(n)=\sum_{i=1}^{n}f(i)$ với độ phức tạp thấp hơn tuyến tính.

<span id="&#x7B97;&#x6CD5;&#x601D;&#x60F3;"></span>
## Ý tưởng thuật toán

Ta tìm cách xây dựng một công thức truy hồi của $S(n)$ theo $S\left(\left\lfloor\frac{n}{i}\right\rfloor\right)$.

Với một hàm số học bất kì $g$, luôn có:

$$
\begin{aligned}
    \sum_{i=1}^{n}(f * g)(i) & =\sum_{i=1}^{n}\sum_{d \mid i}g(d)f\left(\frac{i}{d}\right)           \\
                             & =\sum_{i=1}^{n}g(i)S\left(\left\lfloor\frac{n}{i}\right\rfloor\right)
\end{aligned}
$$

Trong đó $f*g$ là [tích chập Dirichlet](./dirichlet.md#dirichlet-%E5%8D%B7%E7%A7%AF) của hai hàm số học $f$ và $g$.

???+ note "Chứng minh sơ lược"
    $g(d)f\left(\frac{i}{d}\right)$ chính là phần đóng góp của mọi $i\leq n$. Vì vậy ta đổi thứ tự liệt kê, lần lượt liệt kê $d$ và $\frac{i}{d}$ (tương ứng với $i,j$ mới):

    $$
    \begin{aligned}
        \sum_{i=1}^n\sum_{d \mid i}g(d)f\left(\frac{i}{d}\right) & =\sum_{i=1}^n\sum_{j=1}^{\left\lfloor n/i \right\rfloor}g(i)f(j) \\
                                                                 & =\sum_{i=1}^ng(i)\sum_{j=1}^{\left\lfloor n/i \right\rfloor}f(j) \\
                                                                 & =\sum_{i=1}^ng(i)S\left(\left\lfloor\frac{n}{i}\right\rfloor\right)
    \end{aligned}
    $$

Từ đó có công thức truy hồi:

$$
\begin{aligned}
    g(1)S(n) & = \sum_{i=1}^n g(i)S\left(\left\lfloor\frac{n}{i}\right\rfloor\right) - \sum_{i=2}^n g(i)S\left(\left\lfloor\frac{n}{i}\right\rfloor\right) \\
             & = \sum_{i=1}^n (f * g)(i) - \sum_{i=2}^n g(i)S\left(\left\lfloor\frac{n}{i}\right\rfloor\right)
\end{aligned}
$$

Nếu ta xây dựng được một hàm số học $g$ thích hợp sao cho:

1.  Có thể tính nhanh $\sum_{i=1}^n(f * g)(i)$;
2.  Có thể tính nhanh tổng tiền tố của $g$, để dùng chia đoạn số học tính $\sum_{i=2}^ng(i)S\left(\left\lfloor\dfrac{n}{i}\right\rfloor\right)$.

Khi đó ta có thể tính $g(1)S(n)$ trong thời gian ngắn.

???+ warning "Lưu ý"
    Bất kể hàm số học $f$ có là hàm nhân hay không, miễn là xây dựng được hàm số học $g$ thích hợp thì đều có thể cân nhắc dùng sàng Dujiao để tính tổng tiền tố của $f$.

    Chẳng hạn xét $f(n)=\mathrm{i}\varphi(n)$. Rõ ràng $f$ không phải hàm nhân, nhưng có thể lấy $g(n)=1$, do đó:

    $$
    \sum_{k=1}^n (f*g)(k)=\mathrm{i}\frac{n(n+1)}{2}
    $$

    Độ phức tạp để tính $\sum_{k\leq m} (f*g)(k)$ và $\sum_{k \leq m} g(k)$ đều là $O(1)$, nên có thể cân nhắc dùng sàng Dujiao.

<span id="&#x65F6;&#x95F4;&#x590D;&#x6742;&#x5EA6;"></span>
## Độ phức tạp thời gian

Đặt $R(n)=\left\{\left\lfloor \dfrac{n}{k} \right\rfloor: k=2,3,\dots,n\right\}$. Từ [tính chất](./sqrt-decomposition.md#%E6%80%A7%E8%B4%A8) của chia đoạn số học, với mọi $m\in R(n)$ đều có $R(m)\subseteq R(n)$. Nói cách khác, sau khi dùng ghi nhớ, chỉ cần tính $S(k)$ một lần với mọi $k\in R(n)$ là có thể thu được giá trị trên $R(n)$. Số lượng điểm này là $|R(n)|=O(\sqrt{n})$.

Giả sử độ phức tạp để tính $\sum_{i=1}^n(f * g)(i)$ và $\sum_{i=1}^n g(i)$ đều là $O(1)$. Gọi độ phức tạp tính $S(n)$ là $T(n)$, khi đó:

$$
\begin{aligned}
    T(n) & = \sum_{k\in R(n)} T(k)\\
         & = \Theta(\sqrt n)+\sum_{k=1}^{\lfloor\sqrt n\rfloor} O(\sqrt k)+\sum_{k=2}^{\lfloor\sqrt n\rfloor} O\left(\sqrt{\dfrac{n}{k}}\right)\\
         & = O\left(\int_{0}^{\sqrt n} \left(\sqrt{x} + \sqrt{\dfrac{n}{x}}\right) \mathrm{d}x\right)\\
         & = O\left(n^{3/4}\right).
\end{aligned}
$$

Nếu ta có thể tiền xử lí một phần $S(k)$, với $k=1,2,\dots,m$ và $m\geq \lfloor\sqrt n\rfloor$. Giả sử độ phức tạp tiền xử lí là $T_0(m)$, thì lúc này $T(n)$ là:

$$
\begin{aligned}
    T(n) & = T_0(m)+\sum_{k\in R(n);k>m} T(k)\\
         & = T_0(m)+\sum_{k=1}^{\lfloor n/m \rfloor} O\left(\sqrt{\dfrac{n}{k}}\right)\\
         & = O\left(T_0(m)+\int_{0}^{n/m} \sqrt{\dfrac{n}{x}} \mathrm{d}x\right)\\
         & = O\left(T_0(m)+\dfrac{n}{\sqrt m}\right).
\end{aligned}
$$

Nếu $T_0(m)=O(m)$ (ví dụ sàng tuyến tính), theo bất đẳng thức trung bình ta có: khi $m=\Theta\left(n^{2/3}\right)$, $T(n)$ đạt giá trị nhỏ nhất $O\left(n^{2/3}\right)$.

??? failure "Một chứng minh sai"
    Giả sử độ phức tạp tính $S(n)$ là $T(n)$, ta có:

    $$
    T(n)=\Theta\left(\sqrt{n}\right)+O\left(\sum_{i=2}^{\lfloor\sqrt{n}\rfloor} T\left(\left\lfloor\frac{n}{i}\right\rfloor\right)\right)
    $$

    $$
    \begin{aligned}
        T\left(\left\lfloor\frac{n}{i}\right\rfloor\right) & = \Theta\left(\sqrt{\frac{n}{i}}\right)+O\left(\sum_{j=2}^{\lfloor\sqrt{n/i}\rfloor} T\left(\left\lfloor\frac{n}{ij}\right\rfloor\right)\right) \\
                                                           & = O\left(\sqrt{\frac{n}{i}}\right)
    \end{aligned}
    $$

    Ở đây, $O\left(\sum_{j=2}^{\lfloor\sqrt{n/i}\rfloor} T\left(\left\lfloor\dfrac{n}{ij}\right\rfloor\right)\right)$ bị xem như vô cùng bé bậc cao rồi bỏ đi. Vì vậy:

    $$
    \begin{aligned}
        T(n) & = \Theta\left(\sqrt{n}\right)+O\left(\sum_{i=2}^{\lfloor\sqrt{n}\rfloor} \sqrt{\frac{n}{i}}\right) \\
             & = O\left(\sum_{i=1}^{\lfloor\sqrt{n}\rfloor} \sqrt{\frac{n}{i}}\right) \\
             & = O\left(\int_{0}^{\sqrt{n}}\sqrt{\frac{n}{x}}\mathrm{d}x\right) \\
             & = O\left(n^{3/4}\right)
    \end{aligned}
    $$

    ??? bug "Lỗi"
        Vấn đề nằm ở chỗ "xem như vô cùng bé bậc cao rồi bỏ đi". Thay $T\left(\left\lfloor\dfrac{n}{i}\right\rfloor\right)$ vào công thức của $T(n)$, ta có:

        $$
        \begin{aligned}
            T(n) & = \Theta\left(\sqrt{n}\right)+O\left(\sum_{i=2}^{\lfloor\sqrt{n}\rfloor} \sqrt{\frac{n}{i}}\right)+O\left(\sum_{i=2}^{\lfloor\sqrt{n}\rfloor}\sum_{j=2}^{\lfloor\sqrt{n/i}\rfloor} T\left(\left\lfloor\frac{n}{ij}\right\rfloor\right)\right)\\
                 & = O\left(\sqrt{n}+\int_{0}^{\sqrt{n}}\sqrt{\frac{n}{x}}\mathrm{d}x\right)+O\left(\sum_{i=2}^{\lfloor\sqrt{n}\rfloor}\sum_{j=2}^{\lfloor\sqrt{n/i}\rfloor} T\left(\left\lfloor\frac{n}{ij}\right\rfloor\right)\right)\\
                 & = O\left(n^{3/4}\right)+O\left(\sum_{i=2}^{\lfloor\sqrt{n}\rfloor}\sum_{j=2}^{\lfloor\sqrt{n/i}\rfloor} T\left(\left\lfloor\frac{n}{ij}\right\rfloor\right)\right)\\
        \end{aligned}
        $$

        Xét phần $\displaystyle\sum_{i=2}^{\lfloor\sqrt{n}\rfloor}\sum_{j=2}^{\lfloor\sqrt{n/i}\rfloor} T\left(\left\lfloor\frac{n}{ij}\right\rfloor\right)$, không khó thấy rằng:

        $$
        \begin{aligned}
            \sum_{i=2}^{\lfloor\sqrt{n}\rfloor}\sum_{j=2}^{\lfloor\sqrt{n/i}\rfloor} T\left(\left\lfloor\frac{n}{ij}\right\rfloor\right) & = \Omega\left(\sum_{i=2}^{\lfloor\sqrt{n}\rfloor} T\left(\left\lfloor\frac{n}{i}\cdot\left\lfloor\sqrt\frac{n}{i}\right\rfloor^{-1}\right\rfloor\right)\right) \\
                                                                                                                                         & = \Omega\left(\sum_{i=2}^{\lfloor\sqrt{n}\rfloor} T\left(\left\lfloor\sqrt\frac{n}{i}\right\rfloor\right)\right)
        \end{aligned}
        $$

        Do chưa đưa ghi nhớ vào, $T\left(\left\lfloor\sqrt{\dfrac{n}{i}}\right\rfloor\right)$ trong công thức trên vẫn là $\Omega\left(\left(\dfrac{n}{i}\right)^{1/4}\right)$, nên phần được gọi là "vô cùng bé bậc cao" không thể bị bỏ đi.

        Trên thực tế, độ phức tạp dưới tuyến tính của sàng Dujiao được bảo đảm bởi ghi nhớ. Chỉ sau khi dùng ghi nhớ mới bảo đảm không xuất hiện hạng tổng nhiều tầng đó.

<span id="&#x4F8B;&#x9898;"></span>
## Ví dụ

<span id="&#x95EE;&#x9898;&#x4E00;"></span>
### Bài toán 1

???+ note "[P4213 mẫu sàng Dujiao (Sum)](https://www.luogu.com.cn/problem/P4213)"
    Tính giá trị của $S_1(n)= \sum_{i=1}^{n} \mu(i)$ và $S_2(n)= \sum_{i=1}^{n} \varphi(i)$, với $1\leq n<2^{31}$.

=== "Tổng tiền tố của hàm Mobius"
    Ta biết:

    $$
    \epsilon = [n=1] = \mu * 1 = \sum_{d \mid n} \mu(d)
    $$

    $$
    \begin{aligned}
        S_1(n) & =\sum_{i=1}^n \epsilon (i)-\sum_{i=2}^n S_1 \left(\left\lfloor \frac n i \right\rfloor\right) \\
               & = 1-\sum_{i=2}^n S_1\left(\left\lfloor \frac n i \right\rfloor\right)
    \end{aligned}
    $$

    Phần suy ra độ phức tạp thời gian xem tại mục [Độ phức tạp thời gian](#%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6).

    Với các giá trị lớn, cần dùng `map`/`unordered_map` để lưu giá trị tương ứng, thuận tiện cho việc dùng lại kết quả đã tính trước đó.

=== "Tổng tiền tố của hàm Euler"
    Dĩ nhiên cũng có thể dùng sàng Dujiao để tính tổng tiền tố của $\varphi (x)$, nhưng cách tốt hơn là áp dụng đảo Mobius.

    === "Đảo Mobius"
        $$
        \begin{aligned}
            \sum_{i=1}^n \sum_{j=1}^n [\gcd(i,j)=1] & =\sum_{i=1}^n \sum_{j=1}^n \sum_{d \mid i,d \mid j} \mu(d)    \\
                                                    & =\sum_{d=1}^n \mu(d) {\left\lfloor \frac n d \right\rfloor}^2
        \end{aligned}
        $$

        Vì đề bài yêu cầu $\sum_{i=1}^n \sum_{j=1}^i [\gcd(i,j)=1]$, ta chỉ cần loại trường hợp $i=1,j=1$ rồi chia kết quả cho $2$.

        Có thể thấy chỉ cần tính tổng tiền tố của hàm Mobius là có thể nhanh chóng tính được tổng tiền tố của hàm Euler. Độ phức tạp thời gian là $O\left(n^{\frac 2 3}\right)$.

    === "Sàng Dujiao"
        Tính $S(n)=\sum_{i=1}^n\varphi(i)$.

        Tương tự, $\varphi * 1=\operatorname{id}$, do đó:

        $$
            \begin{aligned}
                S(n) & =\sum_{i=1}^n i - \sum_{i=2}^n S\left(\left\lfloor\frac{n}{i}\right\rfloor\right)    \\
                     & =\frac{1}{2}n(n+1) - \sum_{i=2}^n S\left(\left\lfloor\frac{n}{i}\right\rfloor\right)
            \end{aligned}
        $$

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/du/du_1.cpp"
    ```

<span id="&#x95EE;&#x9898;&#x4E8C;"></span>
### Bài toán 2

???+ note "[Luogu P3768: Bài toán toán học đơn giản](https://www.luogu.com.cn/problem/P3768)"
    Tóm tắt: tính

    $$
    \sum_{i=1}^n\sum_{j=1}^ni\cdot j\cdot\gcd(i,j)\pmod p
    $$

    Trong đó $n\leq 10^{10},5\times 10^8\leq p\leq 1.1\times 10^9$, và $p$ là số nguyên tố.

Dùng $\varphi * 1=\operatorname{id}$ để biến đổi bằng đảo Mobius:

$$
\sum_{d=1}^nF^2\left(\left\lfloor\frac{n}{d}\right\rfloor\right)\cdot d^2\varphi(d)
$$

Trong đó $F(n)=\dfrac{1}{2}n(n+1)$.

Chia đoạn số học trên $\sum_{d=1}^nF\left(\left\lfloor\dfrac{n}{d}\right\rfloor\right)^2$, còn tổng tiền tố của $d^2\varphi(d)$ được xử lí bằng sàng Dujiao:

$$
f(n)=n^2\varphi(n)=(\operatorname{id}^2\varphi)(n)
$$

$$
S(n)=\sum_{i=1}^nf(i)=\sum_{i=1}^n(\operatorname{id}^2\varphi)(i)
$$

Cần xây dựng một hàm nhân $g$ sao cho $f\times g$ và $g$ đều có thể tính tổng nhanh.

Tổng tiền tố của riêng $\varphi$ có thể xử lí bằng sàng Dujiao cho $\varphi * 1$, nhưng ở đây $f$ có thêm một thừa số $\operatorname{id}^2$. Vì vậy ta chập thêm một $\operatorname{id}^2$ để biến nó thành hằng số:

$$
S(n)=\sum_{i=1}^n\left(\left(\operatorname{id}^2\varphi\right) * \operatorname{id}^2\right)(i)-\sum_{i=2}^n\operatorname{id}^2(i)S\left(\left\lfloor\frac{n}{i}\right\rfloor\right)
$$

Biến đổi tích chập:

$$
\begin{aligned}
    ((\operatorname{id}^2\varphi)* \operatorname{id}^2)(i) & =\sum_{d \mid i}\left(\operatorname{id}^2\varphi\right)(d)\operatorname{id}^2\left(\frac{i}{d}\right) \\
                                                           & =\sum_{d \mid i}d^2\varphi(d)\left(\frac{i}{d}\right)^2                                               \\
                                                           & =\sum_{d \mid i}i^2\varphi(d)=i^2\sum_{d \mid i}\varphi(d)                                            \\
                                                           & =i^2(\varphi*1)(i)=i^3
\end{aligned}
$$

Tiếp tục biến đổi $S(n)$:

$$
\begin{aligned}
    S(n) & =\sum_{i=1}^n\left((\operatorname{id}^2\varphi)* \operatorname{id}^2\right)(i)-\sum_{i=2}^n\operatorname{id}^2(i)S\left(\left\lfloor\frac{n}{i}\right\rfloor\right) \\
         & =\sum_{i=1}^ni^3-\sum_{i=2}^ni^2S\left(\left\lfloor\frac{n}{i}\right\rfloor\right)                                                                                  \\
         & =\left(\frac{1}{2}n(n+1)\right)^2-\sum_{i=2}^ni^2S\left(\left\lfloor\frac{n}{i}\right\rfloor\right)                                                                 \\
\end{aligned}
$$

Sau đó chỉ cần chia đoạn để tính.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/du/du_2.cpp"
    ```

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;"></span>
### Tài liệu tham khảo

1.  Ren Zhizhou, 2016, "Một số phương pháp tính tổng hàm nhân", luận văn đội tuyển dự bị Olympic Tin học Quốc gia Trung Quốc năm 2016
2.  [Phân tích độ phức tạp thời gian và không gian của sàng Dujiao - riteme.site](https://riteme.site/blog/2018-9-11/time-space-complexity-dyh-algo.html)
