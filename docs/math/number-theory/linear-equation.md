Bài viết này thảo luận cách giải phương trình đồng dư tuyến tính.

<span id="&#22522;&#26412;&#27010;&#24565;"></span>
## Khái niệm cơ bản

Gọi $a,b,n$ là các số nguyên và $x$ là ẩn. Phương trình có dạng

$$
ax\equiv b\pmod n
$$

được gọi là **phương trình đồng dư tuyến tính** (linear congruence equation).

Giải phương trình đồng dư tuyến tính nghĩa là tìm toàn bộ nghiệm $x$ trong đoạn $[0,n-1]$. Tất nhiên, cộng hoặc trừ bội tùy ý của $n$ vào các nghiệm này vẫn cho nghiệm của phương trình. Theo modulo $n$, đó là toàn bộ nghiệm của phương trình.

Bài viết này giới thiệu hai cách giải phương trình đồng dư tuyến tính, lần lượt dùng nghịch đảo và phương trình bất định. Trong trường hợp tổng quát, cả việc tính nghịch đảo lẫn giải phương trình bất định đều cần dùng [thuật toán Euclid mở rộng](./gcd.md#%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95), nên hai cách này về bản chất là nhất quán.

<span id="&#29992;&#36870;&#20803;&#27714;&#35299;"></span>
## Giải bằng nghịch đảo

Trước hết xét trường hợp $a$ và $n$ nguyên tố cùng nhau, tức $\gcd(a,n)=1$. Khi đó có thể tính [nghịch đảo](./inverse.md) $a^{-1}$ của $a$, rồi nhân hai vế phương trình với $a^{-1}$, thu được nghiệm duy nhất:

$$
x \equiv ba^{-1} \pmod n.
$$

Tiếp theo xét trường hợp $a$ và $n$ không nguyên tố cùng nhau, tức $\gcd(a,n)=d>1$. Khi đó phương trình ban đầu chưa chắc có nghiệm. Ví dụ $2x\equiv 1\pmod 4$ không có nghiệm. Vì vậy cần xét hai trường hợp:

-   Nếu $d$ không chia hết $b$, phương trình vô nghiệm. Với mọi $x$, vế trái $ax$ luôn là bội của $d$, nhưng vế phải $b$ không phải bội của $d$. Do đó chúng không thể chênh nhau một bội của $n$, vì mọi bội của $n$ cũng là bội của $d$. Vì vậy phương trình vô nghiệm.

-   Nếu $d$ chia hết $b$, có thể chia đồng thời các tham số $a,b,n$ cho $d$, thu được phương trình mới:

    $$
    a'x \equiv b'\pmod{n'}.
    $$

    Trong đó $\gcd(a',n')=1$, tức $a'$ và $n'$ nguyên tố cùng nhau. Trường hợp này đã được giải ở trên, nên có thể dùng nghịch đảo để tìm một nghiệm $x'$.

    Hiển nhiên $x'$ cũng là một nghiệm của phương trình ban đầu. Nhưng đây không phải nghiệm duy nhất của phương trình ban đầu. Vì toàn bộ nghiệm của phương trình đã chuyển đổi là

    $$
    \{x' + kn' : k\in\mathbf Z\}.
    $$

    Những nghiệm rơi vào đoạn $[0,n-1]$ chính là toàn bộ nghiệm của phương trình ban đầu trong đoạn $[0,n-1]$:

    $$
    x \equiv (x' + kn')\pmod{n},\quad k = 0, 1, \cdots, d-1.
    $$

Tóm lại, **số nghiệm** của phương trình đồng dư tuyến tính bằng $d=\gcd(a,n)$ hoặc bằng $0$.

<span id="&#29992;&#19981;&#23450;&#26041;&#31243;&#27714;&#35299;"></span>
## Giải bằng phương trình bất định

Phương trình đồng dư tuyến tính tương đương với [phương trình bất định bậc nhất hai ẩn](./bezouts.md#%E4%B8%A4%E4%B8%AA%E5%8F%98%E9%87%8F%E7%9A%84%E6%83%85%E5%BD%A2) theo $x,y$:

$$
ax + ny = b.
$$

Theo thảo luận trong trang được dẫn, phương trình có nghiệm khi và chỉ khi $\gcd(a,n)\mid b$, và một dạng nghiệm tổng quát là

$$
\begin{aligned}
x &= x_0 + t\dfrac{n}{d},\\
y &= y_0 - t\dfrac{a}{d},
\end{aligned}
$$

trong đó $d=\gcd(a,n)$ là ước chung lớn nhất của chúng, và $t$ là số nguyên tùy ý.

Do đó nghiệm tổng quát của phương trình đồng dư tuyến tính là

$$
x \equiv \left(x_0+t\frac{n}{d}\right)\pmod{n},\quad t\in\mathbf Z.
$$

Lấy $x_0$ theo modulo $n/d$ sẽ nhận được nghiệm nguyên không âm nhỏ nhất của phương trình đồng dư, tức $x'$ ở phần trên.

<span id="&#21442;&#32771;&#23454;&#29616;"></span>
## Cài đặt tham khảo

Cài đặt tham khảo trong phần này trả về nghiệm nguyên không âm nhỏ nhất của phương trình đồng dư. Nếu nghiệm không tồn tại, trả về $-1$.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/linear-equation/linear-equation.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/linear-equation/linear-equation.py:core"
        ```

<span id="&#20064;&#39064;"></span>
## Bài tập

-   [[NOIP2012] Phương trình đồng dư](https://loj.ac/problem/2605)

**Trang này chủ yếu được dịch từ bài viết [Модульное линейное уравнение первого порядка](http://e-maxx.ru/algo/diofant_1_equation) và bản dịch tiếng Anh [Linear Congruence Equation](https://cp-algorithms.com/algebra/linear_congruence_equation.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0. Nội dung có chỉnh sửa.**
