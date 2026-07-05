Tương tự biến đổi Fourier rời rạc, biến đổi Chirp Z là một thuật toán nhận đa thức $f(x) = \sum_{i = 0}^{m - 1} f_i x^i \in \mathbb{C}\lbrack x\rbrack$ và $q \in \mathbb{C} \setminus \{0\}$, rồi tính $f(1), f(q), \dots, f(q^{n - 1})$; thuật toán không yêu cầu $q$ là căn đơn vị. Nó cũng có thể dùng cho biến đổi số học. Phần sau sẽ giới thiệu biến đổi Chirp Z và biến đổi ngược của nó.

<span id="biến-đổi-chirp-z"></span>

## Biến đổi Chirp Z

Theo định nghĩa, biến đổi Chirp Z có thể viết là

$$
\operatorname{\mathsf{CZT}}_n : \left(f(x), q\right) \mapsto
\begin{bmatrix}
f(1) & f(q) & \cdots & f\left(q^{n - 1}\right)
\end{bmatrix}
$$

trong đó $f(x) := \sum_{i = 0}^{m - 1} f_i x^i \in \mathbb{C}\lbrack x\rbrack$ và $q \in \mathbb{C} \setminus \{0\}$.

<span id="thuật-toán-bluestein"></span>

### Thuật toán Bluestein

Xét

$$
ij = \binom{i}{2} + \binom{-j}{2} - \binom{i - j}{2}
$$

với $i, j \in \mathbb{Z}$, ta có thể xây dựng

$$
\begin{aligned}
G(x) & := \sum_{i = -(m - 1)}^{n - 1} q^{-\binom{i}{2}}x^i, \\
F(x) & := \sum_{i = 0}^{m - 1} f_i q^{\binom{-i}{2}}x^i.
\end{aligned}
$$

trong đó $G(x) \in \mathbb{C}\left\lbrack x, x^{-1}\right\rbrack$, và với $i = 0, \dots, n - 1$ ta có

$$
\begin{aligned}
\left\lbrack x^i\right\rbrack\left(G(x)F(x)\right) &=
\sum_{j = 0}^{m - 1}\left(\left(\left\lbrack x^{i - j}\right\rbrack G(x)\right)\left(\left\lbrack x^j\right\rbrack F(x)\right)\right) \\
&= \sum_{j = 0}^{m - 1} f_j q^{\binom{-j}{2} - \binom{i - j}{2}} \\
&= q^{-\binom{i}{2}} f\left(q^i\right)
\end{aligned}
$$

Ngoài ra $q^{\binom{i + 1}{2}} = q^{\binom{i}{2}}\cdot q^i$ và $\binom{-i}{2} = \binom{i + 1}{2}$. Vì vậy phép tính có thể hoàn thành bằng một lần nhân đa thức; thuật toán này được gọi là thuật toán Bluestein.

??? note "Mẫu ([P6800 - Mẫu Chirp Z-Transform](https://www.luogu.com.cn/problem/P6800))"
    ```cpp
    --8<-- "docs/math/code/poly/czt/czt_1.cpp:core"
    ```

<span id="biến-đổi-chirp-z-ngược"></span>

## Biến đổi Chirp Z ngược

Biến đổi Chirp Z ngược có thể viết là

$$
\operatorname{\mathsf{ICZT}}_n :
\left(
    \begin{bmatrix} f(1) & f(q) & \cdots & f\left(q^{n - 1}\right)
    \end{bmatrix},q
\right)
\mapsto f(x)
$$

trong đó $f(x) \in \mathbb{C}\left\lbrack x\right\rbrack_{< n}$ và $q \in \mathbb{C} \setminus \{0\}$, đồng thời $q^i \neq q^j$ với mọi $i \neq j$; đây là điều kiện của nội suy đa thức.

<span id="thuật-toán-bostan-schost"></span>

### Thuật toán Bostan-Schost

Nhắc lại [công thức nội suy Lagrange](../numerical/interp.md#phương-pháp-nội-suy-lagrange):

$$
f(x) = \sum_{i = 0}^{n - 1}\left(f\left(x_i\right)\prod_{0 \leq j < n \atop j \neq i} \frac{x - x_j}{x_i - x_j}\right)
$$

với $x_i \neq x_j$ cho mọi $i \neq j$. Tương tự như trong [nội suy nhanh đa thức](./multipoint-eval-interpolation.md#nội-suy-nhanh-đa-thức), đặt $M(x) := \prod_{i = 0}^{n - 1}\left(x - x_i\right)$. Theo quy tắc L'Hopital, ta có

$$
M'(x_i) = \lim_{x \to x_i} \frac{M(x)}{x - x_i} = \prod_{0 \leq j < n \atop j \neq i}\left(x_i - x_j\right)
$$

**Công thức nội suy Lagrange hiệu chỉnh** là

$$
f(x) = M(x)\left(\sum_{i = 0}^{n - 1}\frac{f\left(x_i\right)/M'(x_i)}{x - x_i}\right)
$$

Khi đó hiện tại ta có

$$
f(x) = M(x)\left(\sum_{i = 0}^{n - 1}\frac{f\left(q^i\right)/M'\left(q^i\right)}{x - q^i}\right)
$$

trong đó $M(x)=\prod_{j = 0}^{n - 1}\left(x - q^j\right)$. Nếu giả sử $n$ là số chẵn, đặt $n = 2k$ và $H(x) := \prod_{j = 0}^{k - 1}\left(x - q^j\right)$, thì

$$
M(x) = H(x) \cdot q^{k^2} \cdot H\left(\frac{x}{q^k}\right)
$$

Điều này cho phép ta tính nhanh $M(x)$. Sau đó dùng thuật toán Bluestein để tính $M'(1), \dots, M'(q^{n - 1})$. Đặt $c_i := f\left(q^i\right)/M'\left(q^i\right)$, ta có

$$
f(x) = M(x)\left(\sum_{i = 0}^{n - 1}\frac{c_i}{x - q^i}\right)
$$

Vì $\deg f(x) < n$, ta chỉ cần tính $\sum_{i = 0}^{n - 1}\frac{c_i}{x - q^i}\bmod{x^n}$, trong đó $\frac{c_i}{x - q^i} \in \mathbb{C}\left\lbrack\left\lbrack x\right\rbrack\right\rbrack$, tức là

$$
\begin{aligned}
\sum_{i = 0}^{n - 1}\frac{c_i}{x - q^i} \bmod x^n &=
-\sum_{i = 0}^{n - 1}\left(\sum_{j = 0}^{n - 1} c_i q^{-i(j+1)}x^j\right) \\
&= -\sum_{j = 0}^{n - 1} C\left(q^{-j - 1}\right) x^j
\end{aligned}
$$

trong đó $C(x) = \sum_{i = 0}^{n - 1} c_i x^i$. Ta có thể dùng thuật toán Bluestein để tính $C\left(q^{-1}\right), \dots, C\left(q^{-n}\right)$.

Nói ngắn gọn, ta lần lượt thực hiện các phép tính sau:

1.  Dùng giảm trị (decrease and conquer) để tính $M(x)$;
2.  Dùng thuật toán Bluestein để tính $M'(1), \dots, M'(q^{n - 1})$;
3.  Dùng thuật toán Bluestein để tính $C\left(q^{-1}\right), \dots, C\left(q^{-n}\right)$;
4.  Dùng một lần nhân đa thức để tính $f(x)$.

Độ phức tạp thời gian của mỗi bước đều bằng độ phức tạp thời gian của phép nhân hai đa thức có bậc không vượt quá $n$.

??? note "Mẫu hiện thực"
    ```cpp
    --8<-- "docs/math/code/poly/czt/inv_czt_1.cpp:core"
    ```

<span id="tài-liệu-tham-khảo"></span>

## Tài liệu tham khảo

1.  [Bostan, A. (2010). Fast algorithms for polynomials and matrices. JNCF 2010. Algorithms Project, INRIA.](https://specfun.inria.fr/bostan/publications/exposeJNCF.pdf)
