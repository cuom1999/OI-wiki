<span id="&#23450;&#20041;"></span>
## Định nghĩa

Kiến thức cần có: [bậc và căn nguyên thủy](./primitive-root.md).

Cách định nghĩa logarit rời rạc tương tự như logarit thông thường. Xét một số nguyên dương $m$ có căn nguyên thủy, và gọi $g$ là một căn nguyên thủy modulo $m$. Với số nguyên $a$ thỏa mãn $(a,m)=1$, ta biết rằng tồn tại duy nhất một số nguyên $0\leq k<\varphi(m)$ sao cho

$$
g^k\equiv a\pmod m
$$

Ta gọi $k$ là logarit rời rạc cơ số $g$ modulo $m$ của $a$, ký hiệu là $k=\operatorname{ind}_g a$; khi không gây nhầm lẫn, có thể viết là $\operatorname{ind} a$.

Hiển nhiên $\operatorname{ind}_g 1=0$ và $\operatorname{ind}_g g=1$.

<span id="&#24615;&#36136;"></span>
## Tính chất

Logarit rời rạc cũng có nhiều tính chất tương tự logarit thông thường.

???+ note "Tính chất"
    Giả sử $g$ là căn nguyên thủy modulo $m$, $(a,m)=(b,m)=1$, khi đó:
    
    1.  $\operatorname{ind}_g(ab)\equiv\operatorname{ind}_g a+\operatorname{ind}_g b\pmod{\varphi(m)}$
    
        Suy ra $(\forall n\in\mathbf{N}),~~\operatorname{ind}_g a^n\equiv n\operatorname{ind}_g a\pmod{\varphi(m)}$
    2.  Nếu $g_1$ cũng là căn nguyên thủy modulo $m$, thì $\operatorname{ind}_g a\equiv\operatorname{ind}_{g_1}a \cdot \operatorname{ind}_g g_1\pmod{\varphi(m)}$
    3.  $a\equiv b\pmod m\iff \operatorname{ind}_g a=\operatorname{ind}_g b$

???+ note "Chứng minh"
    1.  $g^{\operatorname{ind}_g(ab)}\equiv ab\equiv g^{\operatorname{ind}_g a}g^{\operatorname{ind}_g b}\equiv g^{\operatorname{ind}_g a+\operatorname{ind}_g b}\pmod m$
    2.  Đặt $x=\operatorname{ind}_{g_1}a$, khi đó $a\equiv g_1^x\pmod m$. Lại đặt $y=\operatorname{ind}_g g_1$, khi đó $g_1\equiv g^y\pmod m$.
    
        Do đó $a\equiv g^{xy}\pmod m$, tức là $\operatorname{ind}_g a\equiv xy\equiv\operatorname{ind}_{g_1}a \cdot \operatorname{ind}_g g_1\pmod{\varphi(m)}$
    3.  Nhận thấy rằng
    
        $$
        \begin{aligned}
            \operatorname{ind}_g a=\operatorname{ind}_g b&\iff \operatorname{ind}_g a\equiv\operatorname{ind}_g b\pmod{\varphi(m)}\\
            &\iff g^{\operatorname{ind}_g a}\equiv g^{\operatorname{ind}_g b}\pmod m\\
            &\iff a\equiv b\pmod m
        \end{aligned}
        $$

<span id="&#22823;&#27493;&#23567;&#27493;&#31639;&#27861;"></span>
## Thuật toán bước lớn bước nhỏ

Hiện nay bài toán logarit rời rạc vẫn chưa có thuật toán cổ điển chạy trong thời gian đa thức, trong đó kích thước đầu vào của bài toán được tính theo số bit của dữ liệu đầu vào. Trong mật mã học, dựa trên điều này người ta đã thiết kế nhiều thuật toán mã hóa bất đối xứng, chẳng hạn như [Ed25519](https://en.wikipedia.org/wiki/EdDSA#Ed25519).

Trong lập trình thi đấu, BSGS (baby-step giant-step, thuật toán bước nhỏ bước lớn) thường được dùng để giải bài toán logarit rời rạc. Nói một cách hình thức, với $a,b,m\in\mathbf{Z}^+$, thuật toán này có thể giải trong thời gian $O(\sqrt{m})$ phương trình

$$
a^x \equiv b \pmod m
$$

trong đó $a\perp m$. Nghiệm $x$ của phương trình thỏa mãn $0 \le x < m$. Lưu ý rằng $m$ không nhất thiết là số nguyên tố.

<span id="&#31639;&#27861;&#25551;&#36848;"></span>
### Mô tả thuật toán

Đặt $x = A \left \lceil \sqrt m \right \rceil - B$, trong đó $0\le A,B \le \left \lceil \sqrt m \right \rceil$. Khi đó $a^{A\left \lceil \sqrt m \right \rceil -B} \equiv b \pmod m$; biến đổi một chút, ta có $a^{A\left \lceil \sqrt m \right \rceil} \equiv ba^B \pmod m$.

Ta đã biết $a,b$, vì vậy có thể tính trước mọi giá trị của vế phải $ba^B$, duyệt $B$ và lưu bằng `hash`/`map`. Sau đó lần lượt tính $a^{A\left \lceil \sqrt m \right \rceil}$, duyệt $A$ và tìm xem có giá trị $ba^B$ nào bằng nó hay không. Từ đó ta thu được mọi $x$ với $x=A \left \lceil \sqrt m \right \rceil - B$.

Vì cả $A$ và $B$ đều nhỏ hơn $\left \lceil \sqrt m \right \rceil$, độ phức tạp thời gian là $\Theta\left  (\sqrt m\right )$; nếu dùng `map` thì có thêm một hệ số $\log$.

??? note "Vì sao cần $a$ và $m$ nguyên tố cùng nhau"
    Lưu ý rằng thứ ta tìm được là $A,B$. Ta cần bảo đảm rằng từ $a^{A\left \lceil \sqrt m \right \rceil} \equiv ba^B \pmod m$ có thể suy ngược lại $a^{A\left \lceil \sqrt m \right \rceil -B} \equiv b \pmod m$. Công thức sau thu được bằng cách chia hai vế của công thức trước cho $a^B$, nên bắt buộc phải có $a^B \perp m$, tức là $a\perp m$.

<span id="&#25193;&#23637;-bsgs-&#31639;&#27861;"></span>
## Thuật toán BSGS mở rộng

Với $a,b,m\in\mathbf{Z}^+$, cần giải

$$
a^x\equiv b\pmod m
$$

trong đó $a,m$ không nhất thiết nguyên tố cùng nhau.

Khi $(a, m)=1$, $a$ có nghịch đảo theo modulo $m$, nên có thể dùng thuật toán BSGS để giải. Vì vậy ta tìm cách biến chúng thành nguyên tố cùng nhau.

Cụ thể, đặt $d_1=(a, m)$. Nếu $d_1\nmid b$, phương trình ban đầu vô nghiệm. Ngược lại, ta chia đồng thời phương trình cho $d_1$ và được

$$
\frac{a}{d_1}\cdot a^{x-1}\equiv \frac{b}{d_1}\pmod{\frac{m}{d_1}}
$$

Nếu $a$ và $\frac{m}{d_1}$ vẫn chưa nguyên tố cùng nhau thì tiếp tục chia. Đặt $d_2=\left(a, \frac{m}{d_1}\right)$. Nếu $d_2\nmid \frac{b}{d_1}$, phương trình vô nghiệm; ngược lại, chia đồng thời cho $d_2$ và được

$$
\frac{a^2}{d_1d_2}\cdot a^{x-2}≡\frac{b}{d_1d_2} \pmod{\frac{m}{d_1d_2}}
$$

Tương tự, cứ tiếp tục kiểm tra như vậy cho đến khi $a\perp \dfrac{m}{d_1d_2\cdots d_k}$.

Ký hiệu $D=\prod_{i=1}^kd_i$, khi đó phương trình trở thành

$$
\frac{a^k}{D}\cdot a^{x-k}\equiv\frac{b}{D} \pmod{\frac{m}{D}}
$$

Vì $a\perp\dfrac{m}{D}$, suy ra $\dfrac{a^k}{D}\perp \dfrac{m}{D}$. Như vậy $\dfrac{a^k}{D}$ có nghịch đảo; chuyển nó sang vế phải, ta nhận được một bài toán BSGS thông thường. Sau khi giải được $x-k$, cộng thêm $k$ sẽ được nghiệm của phương trình ban đầu.

Lưu ý rằng vẫn có thể tồn tại nghiệm nhỏ hơn hoặc bằng $k$. Vì vậy trước khi khử các nhân tử, ta thực hiện một lượt duyệt $\Theta(k)$ và kiểm tra trực tiếp $a^i\equiv b \pmod m$ để tránh bỏ sót trường hợp này.

<span id="&#22522;&#20110;&#20540;&#22495;&#39044;&#22788;&#29702;&#30340;&#24555;&#36895;&#31163;&#25955;&#23545;&#25968;"></span>
## Logarit rời rạc nhanh dựa trên tiền xử lý miền giá trị

Thuật toán BSGS ở trên có độ phức tạp thời gian $O(\sqrt m)$ cho mỗi lần hỏi, nên kém hiệu quả khi số lượng truy vấn lớn. Nếu modulo cần giải ở mỗi lần là một số nguyên tố cố định $p$, ta có một thuật toán nhanh dựa trên tiền xử lý miền giá trị.

Ta đã biết $\operatorname{ind}_g(ab)\equiv\operatorname{ind}_g a+\operatorname{ind}_g b\pmod{p-1}$, nên chỉ cần dùng thuật toán BSGS để tính logarit rời rạc của mọi số nguyên tố; logarit rời rạc của hợp số có thể được chuyển thành tổng của một số giá trị logarit rời rạc của các số nguyên tố đã biết theo công thức này. Độ phức tạp khi đó vẫn chưa tối ưu, nên ta xét việc chỉ tiền xử lý một phần các logarit rời rạc. Cụ thể, ta tiền xử lý logarit rời rạc của các số từ $1$ đến $L = \lfloor\sqrt p\rfloor + 1$. Lưu ý rằng độ dài khối BSGS $B$ lúc này **không được lấy** là $O(\sqrt{L})$, vì phần tiền xử lý của BSGS, tức là thao tác chèn vào bảng băm, có độ phức tạp $O(B)$, còn tổng số lần truy vấn là $O(\pi(L))$. Do đó tổng độ phức tạp thời gian là $O\left(B+\dfrac{\pi(L)p}{B}\right)$, và khi đó chọn $B=O(\sqrt{\pi(L)p})$ mới là tối ưu. Theo [định lý số nguyên tố](./prime.md), $\pi(n)\sim\dfrac{n}{\log n}$, nên tổng thời gian tiền xử lý có thể được cân bằng thành $O\left(\dfrac{p^{3/4}}{\log^{1/2} p}\right)$.

Tiếp theo là cách tính đáp án. Giả sử hiện cần tính $\operatorname{ind}_g y$. Nếu $y\le L$ thì trả về trực tiếp; ngược lại, đặt $p=vy+r$, khi đó $v=\left\lfloor\dfrac{p}{y}\right\rfloor<L$, $r=p\bmod y$, $y=\dfrac{p-r}{v}$, từ đó

$$
\begin{aligned}
\operatorname{ind}_g y &\equiv \operatorname{ind}_g (p-r)-\operatorname{ind}_g v\\
&\equiv \operatorname{ind}_g (-r)-\operatorname{ind}_g v\\
&\equiv \operatorname{ind}_g (p-1)+\operatorname{ind}_g r-\operatorname{ind}_g v \pmod{p-1}.
\end{aligned}
$$

Nhận thấy $\operatorname{ind}_g (p-1)=(p-1)/2$, vì vậy chỉ cần đệ quy tính logarit rời rạc của $r$.

Ta cũng có thể xét một cách biểu diễn khác của $y$. Do $p=vy+r=(v+1)y+r-y$, nên $y=\dfrac{p-r+y}{v+1}$, từ đó

$$
\operatorname{ind}_g y\equiv \operatorname{ind}_g (y-r)-\operatorname{ind}_g (v+1) \pmod{p-1}.
$$

Ta có $v+1 \le L$, vì vậy chỉ cần đệ quy tính logarit rời rạc của $y-r$.

Kết hợp hai cách tính trên, ta có $\min\{r,y-r\}\le \dfrac{y}{2}$, nên chỉ cần đệ quy trên phía nhỏ hơn là đạt được độ phức tạp truy vấn $O(\log p)$.

Đến đây, ta thu được một thuật toán có độ phức tạp thời gian $O\left(\dfrac{p^{3/4}}{\log^{1/2} p}\right)-O(\log p)$.

??? example "[Luogu11175: Mẫu logarit rời rạc nhanh dựa trên tiền xử lý miền giá trị](https://www.luogu.com.cn/problem/P11175)"
    ```cpp
    --8<-- "docs/math/code/discrete-logarithm/discrete-logarithm-1.cpp"
    ```

<span id="&#20064;&#39064;"></span>
## Bài tập

-   [SPOJ MOD](https://www.spoj.com/problems/MOD/) mẫu
-   [SDOI2013 Trình sinh số ngẫu nhiên](https://www.luogu.com.cn/problem/P3306)
-   [SGU261 Discrete Roots](https://codeforces.com/problemsets/acmsguru/problem/99999/261) mẫu
-   [SDOI2011 Máy tính](https://loj.ac/problem/10214) mẫu
-   [Luogu4195: Mẫu exBSGS/Spoj3105 Mod](https://www.luogu.com.cn/problem/P4195) mẫu
-   [Codeforces - Lunar New Year and a Recursive Sequence](https://codeforces.com/contest/1106/problem/F)
-   [LOJ6542 Logarit rời rạc](https://loj.ac/problem/6542) phương pháp index calculus, không phải bài mẫu

**Một phần nội dung và mã nguồn của trang này được dịch từ bài viết [Дискретное извлечение корня](http://e-maxx.ru/algo/discrete_root) và bản dịch tiếng Anh [Discrete Root](https://cp-algorithms.com/algebra/discrete-root.html). Giấy phép của bản tiếng Nga là Public Domain + Leave a Link; giấy phép của bản tiếng Anh là CC-BY-SA 4.0.**

<span id="&#21442;&#32771;&#36164;&#26009;"></span>
## Tài liệu tham khảo

1.  [Discrete logarithm - Wikipedia](https://en.wikipedia.org/wiki/Discrete_logarithm)
2.  Pan Chengdong, Pan Chengbiao. Số học sơ cấp.
3.  Feng Keqin. Số học sơ cấp và ứng dụng.
