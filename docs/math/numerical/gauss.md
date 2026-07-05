author: StudyingFather, CCXXXI, Chrogeek, ChungZH, countercurrent-time, Early0v0, Enter-tainer, GavinZhengOI, Great-designer, H-J-Granger, henrytbtrue, HeRaNO, huayucaiji, iamtwz, Ir1d, ksyx, MegaOwIer, NachtgeistW, P-Y-Y, qwqAutomaton, shuzhouliu, shuzhouliu-bot, Siger Young, sshwy, SukkaW, Tiphereth-A, tsentau, WhenMelancholy, Xeonacid, Yukimaikoriya, Zhoier, zyj-111, qute-firefly-26710-zjyjoe-lg-592080

<span id="mở-đầu"></span>
## Mở đầu

Phương pháp khử Gauss (Gauss-Jordan elimination) là thuật toán kinh điển để giải hệ phương trình tuyến tính. Nó có vị trí và giá trị quan trọng trong toán học hiện đại, đồng thời là một phần trọng tâm trong việc giảng dạy đại số tuyến tính.

Ngoài việc giải hệ phương trình tuyến tính, phương pháp khử Gauss còn có thể dùng để tính định thức, tìm ma trận nghịch đảo, cũng như trong nhiều bài toán máy tính và kỹ thuật khác.

<span id="phương-pháp-khử-và-tư-tưởng-khử-gauss"></span>
## Phương pháp khử và tư tưởng khử Gauss

<span id="định-nghĩa"></span>
### Định nghĩa

Phương pháp khử là cách biểu diễn một ẩn trong một phương trình của hệ bằng biểu thức đại số chứa một ẩn khác, rồi thay biểu thức đó vào phương trình còn lại; nhờ vậy ta khử được một ẩn và thu được nghiệm. Ta cũng có thể nhân một phương trình với một hằng số rồi cộng vào phương trình khác để khử một ẩn. Phương pháp khử chủ yếu được dùng để giải hệ hai phương trình bậc nhất hai ẩn.

<span id="diễn-giải"></span>
### Diễn giải

Ví dụ 1: dùng phương pháp khử để giải hệ phương trình tuyến tính hai ẩn:

$$
\begin{cases}
4x+y&=100 \\
x-y&=100
\end{cases}
$$

Lời giải: cộng hai phương trình trong hệ để khử $y$, ta được:

$$
5x = 200
$$

Suy ra:

$$
x = 40
$$

Thay $x = 40$ vào phương trình thứ hai của hệ, ta được:

$$
y = -60
$$

<span id="cốt-lõi-của-lý-thuyết-khử"></span>
### Cốt lõi của lý thuyết khử

Cốt lõi của lý thuyết khử chủ yếu gồm các tính chất sau:

-   Đổi chỗ hai phương trình thì nghiệm không đổi;

-   Nhân một phương trình với số khác không $k$ thì nghiệm không đổi;

-   Nhân một phương trình với số $k$ rồi cộng với phương trình khác thì nghiệm không đổi.

<span id="khái-niệm-tư-tưởng-của-phương-pháp-khử-gauss"></span>
### Khái niệm tư tưởng của phương pháp khử Gauss

Nhà toán học người Đức Gauss đã phân tích phương pháp khử và rút ra các kết luận sau:

-   Trong phương pháp khử, những đại lượng tham gia tính toán và bị thay đổi là các hệ số của từng biến trong phương trình;

-   Bản thân các biến không tham gia tính toán và không bị thay đổi;

-   Có thể dùng vị trí của hệ số để biểu diễn biến, từ đó lược bỏ biến;

-   Khi lược bỏ biến trong quá trình tính toán, nghiệm của phương trình không đổi.

Dựa trên các kết luận này, Gauss đề xuất phương pháp khử Gauss: trước hết dùng các phép biến đổi sơ cấp trên hàng để đưa ma trận mở rộng của hệ về dạng rút gọn theo hàng; sau đó gán giá trị cho các ẩn tự do theo tiêu chí độc lập tuyến tính; cuối cùng viết nghiệm tổng quát của hệ phương trình.

<span id="phương-pháp-khử-gauss-năm-bước"></span>
## Phương pháp khử Gauss năm bước

<span id="diễn-giải_1"></span>
### Diễn giải

Sau khi phương pháp khử Gauss đưa ma trận mở rộng về dạng rút gọn, việc gán giá trị cho các ẩn tự do đòi hỏi kiến thức về phụ thuộc tuyến tính; đồng thời cách gán cũng có yếu tố kinh nghiệm, khiến quá trình học có phần khó khăn. Vì vậy có thể chia phương pháp khử Gauss thành năm bước như sau:

1.  Dùng các phép biến đổi sơ cấp trên hàng để đưa ma trận mở rộng về dạng rút gọn theo hàng;

2.  Khôi phục hệ phương trình tuyến tính;

3.  Giải biến đầu tiên;

4.  Bổ sung các ẩn tự do;

5.  Viết nghiệm tổng quát của hệ phương trình dưới dạng cột.

Dưới đây dùng một ví dụ để minh họa thêm cách thuật toán vận hành.

<span id="quá-trình"></span>
### Quá trình

Ví dụ 2: dùng phương pháp khử Gauss năm bước để giải hệ phương trình tuyến tính:

$$
\begin{cases}
2x_1+5x_3+6x_4&=9 \\
x_3+x_4&=-4 \\
2x_3+2x_4&=-8
\end{cases}
$$

<span id="biến-đổi-hàng-sơ-cấp-ma-trận-mở-rộng-thành-dạng-rút-gọn-theo-hàng"></span>
### Biến đổi hàng sơ cấp ma trận mở rộng thành dạng rút gọn theo hàng

Ma trận mở rộng là ma trận mới được tạo bằng cách ghép ma trận hệ số $A$ của hệ phương trình với cột hằng số $b$, tức $(A | b)$. Việc dùng các phép biến đổi sơ cấp trên hàng để đưa ma trận mở rộng về dạng rút gọn theo hàng chính là vận dụng tư tưởng của phương pháp khử Gauss: lược bỏ biến và dùng vị trí hệ số để biểu diễn biến. Trong ma trận mở rộng, đường thẳng đứng tách ma trận hệ số và cột hằng số, đại diện cho dấu bằng.

$$
\left(\begin{matrix}
2 & 0 & 5 & 6 \\
0 & 0 & 1 & 1 \\
0 & 0 & 2 & 2
\end{matrix} \middle|
\begin{matrix}
9 \\
-4 \\
-8
\end{matrix} \right)
$$

$$
\xrightarrow{r_3-2r_2}
\left(\begin{matrix}
2 & 0 & 5 & 6 \\
0 & 0 & 1 & 1 \\
0 & 0 & 0 & 0
\end{matrix} \middle|
\begin{matrix}
9 \\
-4 \\
0
\end{matrix} \right)
$$

Đưa về dạng bậc thang theo hàng

$$
\xrightarrow{\frac{r_1}{2}}
\left(\begin{matrix}
1 & 0 & 2.5 & 3 \\
0 & 0 & 1 & 1 \\
0 & 0 & 0 & 0
\end{matrix} \middle|
\begin{matrix}
4.5 \\
-4 \\
0
\end{matrix} \right)
$$

$$
\xrightarrow{r_1-r_2 \times 2.5}
\left(\begin{matrix}
1 & 0 & 0 & 0.5 \\
0 & 0 & 1 & 1 \\
0 & 0 & 0 & 0
\end{matrix} \middle|
\begin{matrix}
14.5 \\
-4 \\
0
\end{matrix} \right)
$$

Đưa về dạng rút gọn

<span id="khôi-phục-hệ-phương-trình-tuyến-tính"></span>
### Khôi phục hệ phương trình tuyến tính

$$
\begin{cases}
x_1+0.5x_4 &= 14.5\\
x_3+x_4 &= -4 \\
\end{cases}
$$

???+ note "Diễn giải"
    Khôi phục hệ phương trình tuyến tính nghĩa là dựa trên dạng rút gọn theo hàng để viết lại nó thành hệ phương trình tuyến tính: gán lại biến cho các hệ số ở từng vị trí trong dạng rút gọn, đồng thời khôi phục đường thẳng đứng ở giữa thành dấu bằng.

<span id="giải-biến-đầu-tiên"></span>
### Giải biến đầu tiên

$$
\begin{cases}
x_1 = -0.5x_4+14.5\notag \\
x_3 = -x_4-4\notag
\end{cases}
$$

???+ note "Diễn giải"
    Với hệ phương trình tuyến tính đã khôi phục, bước này biểu diễn biến đầu tiên của mỗi phương trình bằng các đại lượng còn lại. Chẳng hạn, trong hai phương trình trên, các biến đầu tiên lần lượt là $x_1$ và $x_3$.

<span id="bổ-sung-các-ẩn-tự-do"></span>
### Bổ sung các ẩn tự do

$$
\begin{cases}
x_1 = -0.5x_4+14.5 \\
x_2 = x_2 \\
x_3 = -x_4-4 \\
x_4 = x_4
\end{cases}
$$

???+ note "Diễn giải"
    Ở bước 3, ta đã giải được các biến $x_1$ và $x_3$. Điều này cho thấy các biến còn lại $x_2$ và $x_4$ không bị hệ phương trình ràng buộc, tức là các ẩn tự do và có thể nhận giá trị tùy ý. Vì vậy, trên cơ sở nghiệm thu được ở bước 3, cần bổ sung nghiệm bằng cách viết $x_2 = x_2, x_4 = x_4$. Cách bổ sung này phù hợp với định nghĩa ẩn tự do và dễ hiểu: vì là ẩn tự do, không chịu ràng buộc, nên chúng chỉ có thể bằng chính chúng.

<span id="viết-nghiệm-tổng-quát-của-hệ-phương-trình-dưới-dạng-cột"></span>
### Viết nghiệm tổng quát của hệ phương trình dưới dạng cột

$$
\begin{aligned}
\begin{pmatrix} x_1 \\ x_2 \\ x_3 \\ x_4 \end{pmatrix} &=
\begin{pmatrix} 0 \\ 1 \\ 0 \\ 0 \end{pmatrix} x_2+
\begin{pmatrix} -0.5 \\ 0 \\ -1 \\ 1 \end{pmatrix} x_4 +
\begin{pmatrix} 14.5 \\ 0 \\ -4 \\ 0 \end{pmatrix} \\
&= \begin{pmatrix} 0 \\ 1 \\ 0 \\ 0 \end{pmatrix} C_1+
\begin{pmatrix} -0.5 \\ 0 \\ -1 \\ 1 \end{pmatrix} C_2 +
\begin{pmatrix} 14.5 \\ 0 \\ -4 \\ 0 \end{pmatrix}
\end{aligned}
$$

Trong đó $C_1$ và $C_2$ là các hằng số tùy ý.

???+ note "Diễn giải"
    Dựa trên bước 4, ta biểu diễn nghiệm dưới dạng tổ hợp các vector cột. Đồng thời, vì $x_2$ và $x_4$ là ẩn tự do, có thể nhận giá trị tùy ý, nên ở vế phải của nghiệm ta lần lượt đặt chúng bằng các hằng số tùy ý $C_1$ và $C_2$. Như vậy, hệ phương trình đã được giải xong.

<span id="tính-định-thức"></span>
## Tính định thức

<span id="diễn-giải_2"></span>
### Diễn giải

Định thức (determinant) của ma trận vuông $N \times N$ có thể được hiểu là thể tích có hướng của khối hình học được căng bởi tất cả các vector cột.

Ví dụ:

$$
\begin{vmatrix}
1 & 0 \\
0 & 1 \end{vmatrix} = 1
$$

$$
\begin{vmatrix}
1 & 2 \\
2 & 1 \end{vmatrix} = -3
$$

Định thức có công thức

$$
\operatorname{det}(A)=\sum_{\sigma \in S_{n}} \operatorname{sgn}(\sigma) \prod_{i=1}^{n} a_{i, \sigma(i)}
$$

Trong đó $S_n$ là tập hợp các hoán vị độ dài $n$, còn $\sigma$ là một hoán vị. Nếu số cặp nghịch thế của $\sigma$ là chẵn thì $\operatorname{sgn}(\sigma)=1$, ngược lại $\operatorname{sgn}(\sigma)=-1$.

Hiểu tính bất biến của định thức thông qua khái niệm thể tích là một cách rất đơn giản:

-   Chuyển vị ma trận thì định thức không đổi;

-   Đổi chỗ hai hàng (hoặc hai cột) của ma trận thì định thức đổi dấu;

-   Cộng hoặc trừ các hàng (hoặc cột) của ma trận với nhau thì định thức không đổi;

-   Nhân đồng thời mọi phần tử của một hàng (hoặc cột) của ma trận với số $k$ thì định thức thay đổi theo cùng tỉ lệ.

Từ đó, sau khi áp dụng khử Gauss lên ma trận, ta có thể thu được một ma trận đường chéo; định thức của ma trận này được quyết định bởi tích các phần tử trên đường chéo. Dấu của nó có thể xác định theo số lần đổi hàng (nếu số lần là lẻ thì dấu của định thức phải đảo ngược). Vì vậy, ta có thể dùng thuật toán Gauss để tính định thức của ma trận với độ phức tạp $O(n^3)$.

Lưu ý rằng nếu tại một thời điểm nào đó ta không tìm được phần tử khác không trong cột hiện tại, thuật toán nên dừng và trả về 0.

<span id="cài-đặt"></span>
### Cài đặt

```cpp
constexpr double EPS = 1E-9;
int n;
vector<vector<double>> a(n, vector<double>(n));

double det = 1;
for (int i = 0; i < n; ++i) {
  int k = i;
  for (int j = i + 1; j < n; ++j)
    if (abs(a[j][i]) > abs(a[k][i])) k = j;
  if (abs(a[k][i]) < EPS) {
    det = 0;
    break;
  }
  swap(a[i], a[k]);
  if (i != k) det = -det;
  det *= a[i][i];
  for (int j = i + 1; j < n; ++j) a[i][j] /= a[i][i];
  for (int j = 0; j < n; ++j)
    if (j != i && abs(a[j][i]) > EPS)
      for (int k = i + 1; k < n; ++k) a[j][k] -= a[i][k] * a[j][i];
}

cout << det;
```

<span id="tìm-ma-trận-nghịch-đảo"></span>
## Tìm ma trận nghịch đảo

Với ma trận vuông $A$, nếu tồn tại ma trận vuông $A^{-1}$ sao cho $A \times A^{-1} = A^{-1} \times A = I$, thì ma trận $A$ được gọi là khả nghịch, còn $A^{-1}$ được gọi là ma trận nghịch đảo của nó.

Cho ma trận vuông cấp $n$ là $A$, cách tìm ma trận nghịch đảo của nó như sau:

1.  Xây dựng ma trận kích thước $n \times 2n$ là $(A, I_n)$;
2.  Dùng phương pháp khử Gauss để rút gọn nó thành dạng $(I_n, A^{-1})$, khi đó ta thu được ma trận nghịch đảo $A^{-1}$ của $A$. Nếu phần bên trái của dạng rút gọn cuối cùng không phải ma trận đơn vị $I_n$, thì ma trận $A$ không khả nghịch.

Chứng minh tính đúng đắn của phương pháp này cần khá nhiều kiến thức đại số tuyến tính, nên do giới hạn dung lượng, phần này không trình bày ở đây. Bạn đọc quan tâm có thể tự tra cứu các tài liệu liên quan.

<span id="giải-hệ-phương-trình-xor-bằng-khử-gauss"></span>
## Giải hệ phương trình XOR bằng khử Gauss

Hệ phương trình XOR là hệ có dạng

$$
\begin{cases}
a_{1,1}x_1 \oplus a_{1,2}x_2 \oplus \cdots \oplus a_{1,n}x_n &= b_1\\
a_{2,1}x_1 \oplus a_{2,2}x_2 \oplus \cdots \oplus a_{2,n}x_n &= b_2\\
\cdots &\cdots \\ a_{m,1}x_1 \oplus a_{m,2}x_2 \oplus \cdots \oplus a_{m,n}x_n &= b_m
\end{cases}
$$

Trong đó $\oplus$ biểu thị "XOR theo bit" (tức `xor` hoặc `^` trong C++), và mọi hệ số/hằng số trong biểu thức (tức $a_{i,j}$ và $b_i$) đều là $0$ hoặc $1$.

Vì phép XOR thỏa mãn tính giao hoán và tính kết hợp, ta có thể khử dần để giải theo phương pháp khử Gauss. Cần chú ý rằng khi khử, ta nên dùng "khử bằng XOR" thay vì "khử bằng cộng trừ", và không cần nhân chia để thay đổi hệ số (vì mọi hệ số đều là $0$ hoặc $1$).

Do ma trận mở rộng của hệ phương trình XOR là ma trận $01$ (trong ma trận chỉ chứa $0$ và $1$), ta có thể dùng `std::bitset` trong C++ để tối ưu, giảm độ phức tạp thời gian xuống $O(\dfrac{n^2m}{\omega})$, trong đó $n$ là số ẩn, $m$ là số phương trình, còn $\omega$ thường là $32$ (phụ thuộc vào máy).

Cài đặt tham khảo:

```cpp
std::bitset<1010> matrix[2010];  // matrix[1~n]: ma trận mở rộng, vị trí 0 là hằng số

std::vector<bool> GaussElimination(
    int n, int m)  // n là số ẩn, m là số phương trình, trả về nghiệm của hệ
                   // (nhiều nghiệm / vô nghiệm thì trả về một vector rỗng)
{
  for (int i = 1; i <= n; i++) {
    int cur = i;
    while (cur <= m && !matrix[cur].test(i)) cur++;
    if (cur > m) return std::vector<bool>(0);
    if (cur != i) swap(matrix[cur], matrix[i]);
    for (int j = 1; j <= m; j++)
      if (i != j && matrix[j].test(i)) matrix[j] ^= matrix[i];
  }
  std::vector<bool> ans(n + 1);
  for (int i = 1; i <= n; i++) ans[i] = matrix[i].test(0);
  return ans;
}
```

<span id="bài-tập"></span>
## Bài tập

-   [Codeforces - Phù thủy và tiền cược](http://codeforces.com/contest/167/problem/E)
-   [Luogu - SDOI2010 Rết ngoài hành tinh](https://www.luogu.com.cn/problem/P2447)
