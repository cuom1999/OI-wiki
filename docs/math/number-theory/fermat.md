author: PeterlitsZo, Tiphereth-A

Bài viết này thảo luận định lý nhỏ Fermat, định lý Euler và dạng mở rộng của chúng. Các định lý này giải quyết bài toán tính lũy thừa với số mũ rất lớn dưới modulo bất kỳ.

<span id="&#x8D39;&#x9A6C;&#x5C0F;&#x5B9A;&#x7406;"></span>
## Định lý nhỏ Fermat

**Định lý nhỏ Fermat** (Fermat's little theorem) là một trong những định lý cơ bản nhất của số học. Nó cũng là cơ sở lý thuyết của [kiểm tra nguyên tố Fermat](./prime.md#fermat-%E7%B4%A0%E6%80%A7%E6%B5%8B%E8%AF%95).

???+ note "Định lý nhỏ Fermat"
    Cho $p$ là số nguyên tố. Với mọi số nguyên $a$ thỏa $p\nmid a$, ta có $a^{p-1}\equiv 1\pmod p$.

???+ note "Định lý"
    Cho $p$ là số nguyên tố. Với mọi số nguyên $a$, ta có $a^{p}\equiv a\pmod p$.

Khi $p\nmid a$, hai quan hệ đồng dư này là tương đương; còn khi $p\mid a$, ta có hiển nhiên $a^p\equiv 0\equiv a\pmod p$. Vì vậy hai mệnh đề là tương đương, và cả hai thường được gọi là định lý nhỏ Fermat.

??? note "Chứng minh 1"
    Cho $p$ là số nguyên tố và $p\nmid a$. Trước hết chứng minh: với $i=1,2,\cdots,p-1$, các số dư $ia \bmod p$ đôi một khác nhau. Chứng minh phản chứng. Nếu tồn tại $1\le i < j < p$ sao cho
    
    $$
    ia \bmod p = ja \bmod p. \iff (j-i)a\equiv 0.\pmod p
    $$
    
    Nhưng cả $(j-i)$ lẫn $a$ đều không chia hết cho $p$, mâu thuẫn.
    
    Nói cách khác, các số dư này là một hoán vị của $\{1,2,\cdots,p-1\}$. Do đó
    
    $$
    \prod_{i=1}^{p-1}i = \prod_{i=1}^{p-1}(ia\bmod p) \equiv \prod_{i=1}^{p-1}ia = a^{p-1}\prod_{i=1}^{p-1}i.\pmod p
    $$
    
    Suy ra
    
    $$
    (a^{p-1}-1)\prod_{i=1}^{p-1}i \equiv 0. \pmod{p}
    $$
    
    Nghĩa là vế trái chia hết cho $p$. Tuy nhiên các số $i=1,2,\cdots, p-1$ đều không chia hết cho $p$, nên chỉ có thể là $p\mid (a^{p-1}-1)$; tức định lý nhỏ Fermat được chứng minh.

??? note "Chứng minh 2"
    Nhận thấy phát biểu thứ hai của định lý nhỏ Fermat đúng với mọi $a\in\mathbf N$, ta có thể dùng quy nạp toán học. Trường hợp số nguyên âm dễ dàng quy về trường hợp không âm.
    
    Cơ sở quy nạp là $0^p\equiv 0\pmod p$, hiển nhiên đúng. Giả sử mệnh đề đúng với $a\in\mathbf N$, cần chứng minh nó cũng đúng với $a+1$. Theo định lý nhị thức,
    
    $$
    (a+1)^p=a^p+\binom{p}{1}a^{p-1}+\binom{p}{2}a^{p-2}+\cdots +\binom{p}{p-1}a+1.
    $$
    
    Ngoại trừ hai hạng tử đầu và cuối, trong biểu thức tổ hợp $\dbinom{p}{k} = \dfrac{p!}{k!(p-k)!}$, tử số chia hết cho $p$ còn mẫu số thì không; vì vậy các hệ số này đều là bội của $p$ với $k\neq 0,p$. Do đó
    
    $$
    (a+1)^p \equiv a^p + 1\equiv a + 1. \pmod{p}
    $$
    
    Bước thứ hai dùng giả thiết quy nạp. Vậy theo quy nạp toán học, định lý nhỏ Fermat đúng.

Mệnh đề đảo của định lý nhỏ Fermat không đúng. Ngay cả khi với mọi $a$ nguyên tố cùng nhau với $n$ đều có $a^{n-1}\equiv 1\pmod n$, $n$ vẫn chưa chắc là số nguyên tố. Thảo luận liên quan xem thêm mục [kiểm tra nguyên tố Fermat](./prime.md#fermat-%E7%B4%A0%E6%80%A7%E6%B5%8B%E8%AF%95).

<span id="&#x6B27;&#x62C9;&#x5B9A;&#x7406;"></span>
## Định lý Euler

**Định lý Euler** (Euler's theorem) mở rộng định lý nhỏ Fermat cho modulo bất kỳ, nhưng vẫn yêu cầu cơ số và modulo nguyên tố cùng nhau.

???+ note "Định lý Euler"
    Với số nguyên $m>0$ và số nguyên $a$ thỏa $\gcd(a,m)=1$, ta có $a^{\varphi(m)}\equiv 1\pmod{m}$, trong đó $\varphi(\cdot)$ là [hàm phi Euler](./euler-totient.md).

??? note "Chứng minh"
    Tương tự chứng minh 1 của định lý nhỏ Fermat, ta lấy một dãy số nguyên tố cùng nhau với $m$ rồi thao tác trên dãy đó. Xét tập
    
    $$
    R = \{r\in\mathbf N : 0 < r < m,~\gcd(r,m)=1\}.
    $$
    
    Đây là [hệ thặng dư thu gọn](./basic.md#%E5%90%8C%E4%BD%99%E7%B1%BB%E4%B8%8E%E5%89%A9%E4%BD%99%E7%B3%BB) modulo $m$. Theo định nghĩa của hàm Euler, $|R|=\varphi(m)$. Tương tự phần trên, nhân các phần tử của tập này với $a$ chỉ tạo ra một hoán vị của chính tập đó:
    
    $$
    R = \{ar\bmod m: r\in R\}.
    $$
    
    Điều này đúng vì dễ kiểm tra $\gcd(ar,m)=1$, và hai phần tử khác nhau $r_1,r_2\in R$ sẽ cho hai số dư $ar_1\bmod m$ và $ar_2\bmod m$ khác nhau. Do đó
    
    $$
    \prod_{r\in R}r \equiv \prod_{r\in R}ar = a^{\varphi(m)}\prod_{r\in R}r. \pmod{m}
    $$
    
    Lặp lại lập luận khử $\prod_{r\in R}r$ như trước, ta được $a^{\varphi(m)}\equiv 1\pmod m$.

Với số nguyên tố $p$, ta có $\varphi(p)=p-1$, nên định lý nhỏ Fermat là một trường hợp đặc biệt của định lý Euler. Ngoài ra, số mũ $\varphi(m)$ trong định lý Euler nói chung không phải số mũ nhỏ nhất làm cho công thức đúng. Có thể cải thiện nó thành $\lambda(m)$, trong đó $\lambda(\cdot)$ là [hàm Carmichael](./primitive-root.md#carmichael-%E5%87%BD%E6%95%B0). Về nền tảng đại số của kết quả liên quan, có thể tham khảo mục [nhóm nhân của các lớp đồng dư nguyên](../algebra/ring-theory.md#%E5%BA%94%E7%94%A8%E6%95%B4%E6%95%B0%E5%90%8C%E4%BD%99%E7%B1%BB%E7%9A%84%E4%B9%98%E6%B3%95%E7%BE%A4).

<span id="&#x6269;&#x5C55;&#x6B27;&#x62C9;&#x5B9A;&#x7406;"></span>
## Định lý Euler mở rộng

Định lý Euler mở rộng[^ex-euler] tiếp tục mở rộng kết quả cho trường hợp cơ số và modulo không nguyên tố cùng nhau. Nhờ đó, nó giải quyết hoàn toàn bài toán tính lũy thừa với cơ số bất kỳ dưới modulo bất kỳ: đưa số mũ về nhỏ hơn $2\varphi(m)$, rồi dùng [lũy thừa nhị phân](../binary-exponentiation.md) để tính trong thời gian $O(\log\varphi(m))$.

???+ note "Định lý Euler mở rộng"
    Với mọi số nguyên dương $m$, số nguyên $a$ và số nguyên không âm $k$, ta có
    
    $$
    a^k \equiv \begin{cases}
    a^{k \bmod \varphi(m)},                &\gcd(a,m) =  1,                   \\
    a^k,                                   &\gcd(a,m)\ne 1, k <   \varphi(m), \\
    a^{(k \bmod \varphi(m)) + \varphi(m)}, &\gcd(a,m)\ne 1, k \ge \varphi(m).
    \end{cases} \pmod m
    $$

Trường hợp thứ hai nói rằng nếu $k < \varphi(m)$ thì không cần tiếp tục giảm số mũ, chỉ cần dùng lũy thừa nhị phân trực tiếp. Khác biệt lớn nhất giữa trường hợp thứ ba và trường hợp thứ nhất là: sau khi lấy dư để giảm số mũ, có cần cộng thêm một lượng $\varphi(m)$ hay không. Tất nhiên, gộp trường hợp thứ nhất vào hai trường hợp thứ hai và thứ ba cũng vẫn đúng.

<span id="&#x76F4;&#x89C2;&#x7406;&#x89E3;"></span>
### Hiểu trực quan

Trước khi chứng minh chặt chẽ, ta có thể hiểu trực quan ý nghĩa của định lý.

![fermat1](./images/fermat.svg)

Xét sự thay đổi của số dư $a^k\bmod m$ khi $k$ tăng. Vì giá trị số dư luôn nằm trong đoạn $[0,m)$, còn $k$ có vô hạn giá trị, nếu xem ánh xạ $a^k\bmod m \mapsto a^{k+1}\bmod m$ là các cạnh có hướng giữa các nút số dư, thì chắc chắn sẽ tạo thành một chu trình như hình vẽ.

Định lý Euler mở rộng cho biết các chu trình này có thể là chu trình thuần túy (trường hợp thứ nhất) hoặc chu trình có đoạn dẫn vào (trường hợp thứ hai và thứ ba). Trong chu trình thuần túy, không có nút nào có hai tiền nhiệm; còn trong trường hợp có đoạn dẫn vào thì hiện tượng đó xuất hiện. Vì vậy, với trường hợp tổng quát, chỉ cần tìm được độ dài chu kỳ và độ dài đoạn trước khi vào chu kỳ là có thể dùng tính chất này để giảm số mũ.

<span id="&#x4E25;&#x683C;&#x8BC1;&#x660E;"></span>
### Chứng minh chặt chẽ

Mục này đưa ra chứng minh chặt chẽ của định lý Euler mở rộng.

??? note "Chứng minh"
    Trước hết chứng minh tồn tại $k_0\in\mathbf N$ sao cho số nguyên $a$ nguyên tố cùng nhau với $m':=\dfrac{m}{\gcd(a^{k_0},m)}$. Đặt $\nu_p(n)$ là số mũ của số nguyên tố $p$ trong phân tích thừa số nguyên tố của số nguyên $n$. Ta có thể lấy
    
    $$
    k_0 = \max\left\{\left\lceil\dfrac{\nu_p(m)}{\nu_p(a)}\right\rceil : \nu_p(a)>0\right\}.
    $$
    
    Vì mọi lũy thừa của các thừa số nguyên tố chung giữa $m$ và $a$ đều đã được chứa trong $a^{k_0}$, nên $a$ nguyên tố cùng nhau với phần còn lại $m'=\dfrac{m}{\gcd(a^{k_0},m)}$ của $m$.
    
    Tiếp theo, với $k\ge k_0$, xét quan hệ đồng dư
    
    $$
    b\equiv a^k. \pmod m
    $$
    
    Vì $\gcd(a^{k_0},m)=\gcd(a^k,m)\mid b$, chia đồng thời hai vế và cả modulo cho $\gcd(a^{k_0},m)$, ta có
    
    $$
    \dfrac{b}{\gcd(a^{k_0},m)} = \dfrac{a^{k_0}}{\gcd(a^{k_0},m)}\cdot a^{k-k_0}. \pmod{m'}
    $$
    
    Lúc này, vì $a$ nguyên tố cùng nhau với modulo $m'$, có thể áp dụng trực tiếp định lý Euler:
    
    $$
    \dfrac{b}{\gcd(a^{k_0},m)} \equiv \dfrac{a^{k_0}}{\gcd(a^{k_0},m)}\cdot a^{(k-k_0)\bmod\varphi(m')}. \pmod{m'}
    $$
    
    Nhân lại thừa số $\gcd(a^{k_0},m)$, ta được
    
    $$
    b \equiv a^{k_0}\cdot a^{(k-k_0)\bmod\varphi(m')} = a^{k_0 + (k-k_0)\bmod\varphi(m')}. \pmod{m}
    $$
    
    Đây chính là dạng của định lý Euler mở rộng. Công thức cho thấy độ dài chu kỳ là $\varphi(m')$, còn độ dài đoạn trước khi vào chu kỳ là $k_0$.
    
    Các tham số vừa thu được chặt hơn so với phát biểu định lý Euler mở rộng, nhưng việc tính chúng tương đối không dễ. Có thể chứng minh rằng các tham số này được nới lỏng thành dạng trong định lý. Trước hết, từ [công thức của hàm Euler](./euler-totient.md), vì $m'\mid m$, ta có $\varphi(m')\mid\varphi(m)$. Nói cách khác, $\varphi(m)$ cũng là một chu kỳ. Thứ hai, $k_0$ cũng có thể được nới lỏng thành $\varphi(m)$. Lý do là với mọi $m\in\mathbf N_+$ và mọi $p\mid m$, ta có
    
    $$
    \begin{aligned}
    \varphi(m) &\ge \varphi(p^{\nu_p(m)}) = (p-1)p^{\nu_p(m)-1} \ge p^{\nu_p(m)-1} \\
    &= (1+(p-1))^{\nu_p(m)-1} \ge 1 + (p-1)(\nu_p(m)-1) \\
    &\ge 1 + (\nu_p(m)-1) = \nu_p(m).
    \end{aligned}
    $$
    
    Trong đó, bất đẳng thức ở dòng thứ hai dùng khai triển nhị thức và chỉ giữ lại hạng tử hằng cùng hạng tử bậc nhất. Do đó
    
    $$
    k_0 \le \max\{\nu_p(m):p\in\mathbf P\}\le \varphi(m).
    $$
    
    Vậy kết quả đã nêu được chứng minh hoàn toàn.

<span id="&#x4F8B;&#x9898;"></span>
## Ví dụ

Mục này dùng một bài toán để minh họa một ứng dụng kinh điển của định lý Euler mở rộng: tính tháp lũy thừa dưới modulo bất kỳ. **Tháp lũy thừa** (power tower) là biểu thức dạng $A\uparrow(B\uparrow(C\uparrow(D\uparrow\cdots)))$, trong đó $\uparrow$ là ký hiệu mũi tên Knuth, còn $A,B,C,D,\cdots$ là một dãy số nguyên không âm.

???+ example "[Library Checker - Tetration Mod](https://judge.yosupo.jp/problem/tetration_mod)"
    Có $T$ bộ kiểm thử. Trong mỗi bộ, cho $A,B,M$, hãy tính $(A\uparrow\uparrow B)\bmod M$. Ở đây $A\uparrow\uparrow B$ biểu thị tháp lũy thừa gồm $B$ số $A$. Nói chính xác hơn,
    
    $$
    A \uparrow\uparrow B =
    \begin{cases}
    1 , & B = 0,\\
    A\uparrow(A\uparrow\uparrow(B-1)), & B > 0.
    \end{cases}
    $$
    
    Quy ước $0^0=1$.

??? note "Lời giải"
    Dựa theo định nghĩa của $A\uparrow\uparrow B$, chỉ cần tính đệ quy. Để tính $(A\uparrow\uparrow B)\bmod M$, áp dụng định lý Euler mở rộng và tính $(A\uparrow\uparrow(B-1))\bmod\varphi(M)$. Vì $\varphi(\varphi(n)) \le n/2$ với mọi $n\ge 2$, quá trình đệ quy chắc chắn kết thúc trong $O(\log M)$ bước. Do cần áp dụng định lý Euler mở rộng, phải phân biệt kết quả hiện tại có nhỏ hơn hẳn modulo hiện tại hay không. Vì vậy, chỉ cần kiểm tra thêm một bước khi lấy dư. Ngoài ra, cần chú ý xử lý các trường hợp biên.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/fermat/tetration.cpp"
    ```

<span id="&#x4E60;&#x9898;"></span>
## Bài tập

-   [Luogu P5091, mẫu: định lý Euler mở rộng](https://www.luogu.com.cn/problem/P5091)
-   [Codeforces 906 D. Power Tower](https://codeforces.com/problemset/problem/906/D)
-   [Luogu P3747, kỳ thi liên tỉnh sáu tỉnh 2017: Gặp nhau là lời chào](https://www.luogu.com.cn/problem/P3747)
-   [Luogu P4139, cách dùng đúng của Chúa và tập hợp](https://www.luogu.com.cn/problem/P4139)
-   [Luogu P3934, Ynoi Easy Round 2016: Khủng long cổ dài nổ tung I](https://www.luogu.com.cn/problem/P3934)
-   [Luogu P6736, Wdsr-2: giáo dục Bạch Trạch](https://www.luogu.com.cn/problem/P6736)

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x6CE8;&#x91CA;"></span>
## Tài liệu tham khảo và chú thích

-   [Fermat's little theorem - Wikipedia](https://en.wikipedia.org/wiki/Fermat%27s_little_theorem)
-   [Euler's theorem - Wikipedia](https://en.wikipedia.org/wiki/Euler%27s_theorem)
-   Hardy, Godfrey Harold, and Edward Maitland Wright. An introduction to the theory of numbers. Oxford university press, 1979.

[^ex-euler]: Tên gọi này chủ yếu xuất hiện trong cộng đồng lập trình thi đấu, không phải tên gọi phổ biến của kết quả này.
