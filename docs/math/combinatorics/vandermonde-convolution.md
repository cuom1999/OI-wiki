<span id="giới-thiệu"></span>

## Giới thiệu

Tích chập Vandermonde là một công thức dùng để gộp các số tổ hợp, chủ yếu được áp dụng khi suy ra các công thức trong tổ hợp.

<span id="công-thức-tích-chập-vandermonde"></span>

## Công thức tích chập Vandermonde

$$
\sum_{i=0}^k\binom{n}{i}\binom{m}{k-i}=\binom{n+m}{k}
$$

<span id="chứng-minh"></span>

### Chứng minh

Xét chứng minh bằng định lý nhị thức:

$$
\begin{aligned}
\sum_{k=0}^{n+m}\binom{n+m}{k}x^k&=(x+1)^{n+m}\\
&=(x+1)^n(x+1)^m\\
&=\sum_{r=0}^n\binom{n}{r}x^r\sum_{s=0}^m\binom{m}{s}x^s\\
&=\sum_{k=0}^{n+m}\sum_{r=0}^k\binom{n}{r}\binom{m}{k-r}x^k\\
\end{aligned}
$$

Suy ra:

$$
\binom{n+m}{k}=\sum_{r=0}^k\binom{n}{r}\binom{m}{k-r}
$$

Nếu chứng minh theo ý nghĩa tổ hợp:

Chọn $k$ phần tử từ một tập có kích thước $n+m$ có thể xem là tách tập này thành hai tập có kích thước lần lượt là $n$ và $m$, rồi chọn $i$ phần tử từ tập kích thước $n$ và $k-i$ phần tử từ tập kích thước $m$. Do ta đã cộng trên mọi giá trị $i$, chỉ cần xét một cách tách tập, vì các cách tách khác là tương đương.

<span id="hệ-quả"></span>

## Hệ quả

<span id="hệ-quả-1-và-chứng-minh"></span>

### Hệ quả 1 và chứng minh

$$
\sum_{i=-r}^{s}\binom{n}{r+i}\binom{m}{s-i}=\binom{n+m}{r+s}
$$

Chứng minh tương tự chứng minh công thức gốc.

<span id="hệ-quả-2-và-chứng-minh"></span>

### Hệ quả 2 và chứng minh

$$
\sum_{i=1}^n\binom{n}{i}\binom{n}{i-1}=\binom{2n}{n-1}
$$

Suy ra từ các kiến thức tổ hợp cơ bản:

$$
\sum_{i=1}^n\binom{n}{i}\binom{n}{i-1}=\sum_{i=0}^{n-1}\binom{n}{i+1}\binom{n}{i}=\sum_{i=0}^{n-1}\binom{n}{n-1-i}\binom{n}{i}=\binom{2n}{n-1}
$$

<span id="hệ-quả-3-và-chứng-minh"></span>

### Hệ quả 3 và chứng minh

$$
\sum_{i=0}^n\binom{n}{i}^2=\binom{2n}{n}
$$

Suy ra từ các kiến thức tổ hợp cơ bản:

$$
\sum_{i=0}^n\binom{n}{i}^2=\sum_{i=0}^n\binom{n}{i}\binom{n}{n-i}=\binom{2n}{n}
$$

<span id="hệ-quả-4-và-chứng-minh"></span>

### Hệ quả 4 và chứng minh

$$
\sum_{i=0}^m\binom{n}{i}\binom{m}{i}=\binom{n+m}{m}
$$

Suy ra từ các kiến thức tổ hợp cơ bản:

$$
\sum_{i=0}^m\binom{n}{i}\binom{m}{i}=\sum_{i=0}^m\binom{n}{i}\binom{m}{m-i}=\binom{n+m}{m}
$$

Trong đó $\binom{n+m}{m}$ là số cách đếm đường đi trên lưới quen thuộc. Vì vậy ta có thể chứng minh bằng ý nghĩa tổ hợp.

Trên một đồ thị lưới, để đi từ $(0,0)$ đến $(n,m)$ cần đi tổng cộng $n+m$ bước. Quy ước $(0,0)$ nằm ở góc trên bên trái của lưới; trong đó có $n$ bước đi xuống và $m$ bước đi sang phải, nên số cách là $\binom{n+m}{m}$.

Nhìn theo cách khác, ta tách $n+m$ bước thành hai phần: đi $n$ bước trước, rồi đi $m$ bước sau. Nếu trong $n$ bước đầu có $i$ bước sang phải, thì trong $m$ bước sau sẽ có $m-i$ bước sang phải. Do đó công thức được chứng minh.

<span id="bài-tập"></span>

## Bài tập

-   [CF785D Anton and School - 2](https://codeforces.com/problemset/problem/785/D)

-   [Luogu P2791 Kindergarten Basketball Problem](https://www.luogu.com.cn/problem/P2791)

<span id="tài-liệu-tham-khảo-và-ghi-chú"></span>

## Tài liệu tham khảo và ghi chú

1.  [Vandermonde's Convolution Formula](https://www.cut-the-knot.org/arithmetic/algebra/VandermondeConvolution.shtml)
