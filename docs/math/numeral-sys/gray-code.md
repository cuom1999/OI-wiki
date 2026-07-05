author: CCXXXI, danni, Early0v0, Enter-tainer, frank-xjh, Henry-ZHR, infiWang, Ir1d, mingyEx, ouuan, sshwy, StudyingFather, Tiphereth-A, Yanjun-Zhao

Mã Gray là một hệ số nhị phân trong đó hai số kề nhau chỉ khác nhau đúng một bit. Ví dụ, dãy mã Gray của số nhị phân $3$ bit là

$$
000,001,011,010,110,111,101,100
$$

Chú ý rằng chỉ số của dãy bắt đầu từ $0$, tức $G(0)=000,G(4)=110$.

Mã Gray do Frank Gray ở Bell Labs đề xuất vào thập niên 1940 và được cấp bằng sáng chế năm 1953.

<span id="xây-dựng-mã-gray-biến-đổi"></span>
## Xây dựng mã Gray (biến đổi)

Có nhiều cách xây dựng mã Gray. Trước hết giới thiệu cách xây thủ công, sau đó đưa ra mã và chứng minh tính đúng đắn.

<span id="xây-thủ-công"></span>
### Xây thủ công

Mã Gray $k$ bit có thể được xây dựng như sau. Bắt đầu từ mã Gray toàn `0`, rồi luân phiên theo chiến lược:

1.  lật bit thấp nhất để nhận mã Gray tiếp theo, ví dụ $000\to 001$;
2.  lật bit ở bên trái bit `1` ngoài cùng bên phải để nhận mã Gray tiếp theo, ví dụ $001\to 011$.

Luân phiên thực hiện các chiến lược trên $2^{k-1}$ lần sẽ nhận được dãy mã Gray $k$ bit.

<span id="xây-bằng-phản-chiếu"></span>
### Xây bằng phản chiếu

Mã Gray $k$ bit có thể được suy ra nhanh từ mã Gray $k-1$ bit bằng cách phản chiếu trên dưới rồi thêm bit mới, như hình dưới:

$$
\begin{matrix}
k=1\\
0\\ 1\\\\\\\\\\\\\\
\end{matrix}
\to \begin{matrix}\\
\color{Red}0\\\color{Red}1\\\color{Blue}1\\\color{Blue}0\\\\\\\\\\
\end{matrix}
\to \begin{matrix}
k=2\\
{\color{Red}0}0\\{\color{Red}0}1\\{\color{Blue}1}1\\{\color{Blue}1}0\\\\\\\\\\
\end{matrix}
\to \begin{matrix}\\
\color{Red}00\\\color{Red}01\\\color{Red}11\\\color{Red}10\\\color{Blue}10\\\color{Blue}11\\\color{Blue}01\\\color{Blue}00
\end{matrix}
\to \begin{matrix}
k=3\\
{\color{Red}0}00\\{\color{Red}0}01\\{\color{Red}0}11\\{\color{Red}0}10\\{\color{Blue}1}10\\{\color{Blue}1}11\\{\color{Blue}1}01\\{\color{Blue}1}00
\end{matrix}
$$

<span id="cách-tính"></span>
### Cách tính

Quan sát biểu diễn nhị phân của $n$ và $G(n)$. Có thể thấy bit thứ $i$ trong biểu diễn nhị phân của $G(n)$ bằng $1$ khi và chỉ khi bit thứ $i$ của $n$ bằng $1$ còn bit thứ $i+1$ bằng $0$, hoặc bit thứ $i$ bằng $0$ còn bit thứ $i+1$ bằng $1$. Vì vậy có thể xem đây là phép xor:

$$
G(n)=n\oplus \left\lfloor\frac{n}{2}\right\rfloor
$$

```cpp
int g(int n) { return n ^ (n >> 1); }
```

<span id="chứng-minh-tính-đúng-đắn"></span>
### Chứng minh tính đúng đắn

Tiếp theo chứng minh dãy mã Gray sinh theo công thức trên có đúng một bit khác nhau giữa hai mã kề nhau.

Xét sự khác biệt giữa $n$ và $n+1$. Cộng $1$ vào $n$ tương đương với việc đảo toàn bộ đoạn `1` liên tiếp ở cuối biểu diễn nhị phân của $n$, rồi đổi bit `0` thấp nhất thành `1`. Ta biểu diễn các bit của $n$ và $n+1$ như sau:

$$
\begin{aligned}
(n)_2 &= \cdots0\underbrace{11\cdots11}_{k\text{ bit}}\\
(n+1)_2 &= \cdots1\underbrace{00\cdots00}_{k\text{ bit}}
\end{aligned}
$$

Khi tính $g(n)$ và $g(n+1)$, $k$ bit cuối đều trở thành dạng $\displaystyle\underbrace{100\cdots00}_{k\text{ bit}}$, còn bit thứ $k+1$ là khác nhau, vì ngoài $k+1$ bit cuối, $n$ và $n+1$ có các bit giống nhau. Do đó bit thứ $k+1$ hoặc cùng xor với `1`, hoặc cùng xor với `0`; trong cả hai trường hợp, bit thứ $k+1$ vẫn khác nhau. Các bit ngoài $k+1$ bit cuối cũng thực hiện cùng một phép xor, nên kết quả giống nhau.

Chứng minh hoàn tất.

<span id="khôi-phục-số-gốc-từ-mã-gray-biến-đổi-ngược"></span>
## Khôi phục số gốc từ mã Gray (biến đổi ngược)

Bây giờ xét biến đổi ngược của mã Gray: cho một mã Gray $g$, cần tìm số gốc $n$. Duyệt từ bit cao nhất xuống bit thấp nhất (bit thấp nhất có chỉ số $1$, tức hàng đơn vị; bit cao nhất có chỉ số $k$). Quan hệ giữa bit thứ $i$ của $n$ và bit thứ $i$ của $g$ là:

$$
\begin{aligned}
n_k &= g_k \\
n_{k-1} &= g_{k-1} \oplus n_k &&= g_k \oplus g_{k-1} \\
n_{k-2} &= g_{k-2} \oplus n_{k-1} &&= g_k \oplus g_{k-1} \oplus g_{k-2} \\
n_{k-3} &= g_{k-3} \oplus n_{k-2} &&= g_k \oplus g_{k-1} \oplus g_{k-2} \oplus g_{k-3} \\
&\vdots\\
n_{k-i} &=\displaystyle\bigoplus_{j=0}^ig_{k-j}
\end{aligned}
$$

```cpp
int rev_g(int g) {
  int n = 0;
  for (; g; g >>= 1) n ^= g;
  return n;
}
```

<span id="ứng-dụng-thực-tế"></span>
## Ứng dụng thực tế

Mã Gray có nhiều ứng dụng rất hữu ích, một số ứng dụng khá bất ngờ:

-   Dãy mã Gray của số nhị phân $k$ bit có thể xem như một chu trình Hamilton trên các đỉnh của siêu lập phương $k$ chiều (hình vuông trong hai chiều, vector đơn vị trong một chiều), trong đó mỗi bit của mã Gray biểu thị tọa độ ở một chiều.

-   Mã Gray được dùng để giảm lỗi trong truyền tín hiệu của bộ chuyển đổi số-tương tự (ví dụ cảm biến), vì mỗi lần nó chỉ thay đổi một bit.

-   Mã Gray có thể dùng để giải bài toán Tháp Hà Nội.

    Gọi số đĩa là $n$. Bắt đầu từ mã Gray toàn `0` dài $n$ bit $G(0)$, rồi lần lượt chuyển sang mã Gray kế tiếp ($G(i)$ sang $G(i+1)$). Bit thứ $i$ trong biểu diễn nhị phân của mã Gray hiện tại biểu thị đĩa thứ $i$ theo thứ tự từ nhỏ đến lớn.

    Vì mỗi lần chỉ có một bit nhị phân thay đổi, khi bit thứ $i$ thay đổi, ta di chuyển đĩa thứ $i$. Trong quá trình di chuyển, ngoài đĩa nhỏ nhất, mọi đĩa khác khi cần di chuyển chỉ có một lựa chọn đặt hợp lệ. Khi di chuyển đĩa thứ nhất, luôn có hai lựa chọn đặt. Vì vậy chiến lược là:

    Nếu $n$ là số lẻ, đường đi của đĩa là $f\to t\to r\to f\to t\to r\to\cdots$, trong đó $f$ là cọc ban đầu, $t$ là cọc đích, $r$ là cọc trung gian.

    Nếu $n$ là số chẵn: $f \to r \to t \to f \to r \to t \to \cdots$.

-   Mã Gray cũng được ứng dụng trong lý thuyết thuật toán di truyền.

<span id="bài-tập"></span>
## Bài tập

-   [CSP S2 2019 D1T1](https://www.luogu.com.cn/problem/P5657) Độ khó: dễ

-   [SGU #249 Matrix](http://codeforces.com/problemsets/acmsguru/problem/99999/249) Độ khó: trung bình

> Một phần nội dung trang này được dịch từ bài viết [Код Грея](http://e-maxx.ru/algo/gray_code) và bản dịch tiếng Anh [Gray code](https://cp-algorithms.com/algebra/gray-code.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.
