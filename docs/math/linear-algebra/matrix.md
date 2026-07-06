Bài này giới thiệu một nội dung rất quan trọng trong đại số tuyến tính: ma trận (Matrix), chủ yếu trình bày các tính chất, phép toán của ma trận và một số ứng dụng của phép nhân ma trận.

<span id="vectơ-và-ma-trận"></span>
## Vectơ và ma trận

Trong đại số tuyến tính, vectơ được chia thành vectơ cột và vectơ hàng.

???+ warning "Cảnh báo"
    Ở một số vùng dùng tiếng Trung, cách dịch "column" và "row" có thể ngược nhau. Trong **OI Wiki**, theo thói quen ở đại lục, dùng "cột" cho column và "hàng" cho row.

Đối tượng nghiên cứu chính của đại số tuyến tính là vectơ cột; quy ước dùng chữ thường in đậm để biểu diễn vectơ cột. Khi làm việc với nhiều vectơ và ma trận trong đại số tuyến tính, nếu không gây nhầm lẫn, ký hiệu vectơ phía trên chữ cái có thể được lược bỏ khi viết tay.

Vectơ cũng là một ma trận đặc biệt. Nếu muốn biểu diễn vectơ hàng, cần viết ký hiệu chuyển vị ở góc trên bên phải của chữ thường in đậm. Trong đại số tuyến tính, vectơ hàng thường biểu diễn phương trình.

<span id="dẫn-nhập"></span>
## Dẫn nhập

Ma trận được đưa vào từ hệ phương trình tuyến tính. Tương tự vectơ, ma trận thể hiện tư tưởng "đóng gói xử lý" dữ liệu.

Ví dụ, với hệ phương trình tuyến tính:

$$
\begin{equation}
    \begin{cases}
        7x_1+8x_2+9x_3=13 \\
        4x_1+5x_2+6x_3=12 \\
        x_1+2x_2+3x_3=11
    \end{cases}
\end{equation}
$$

Thông thường dùng ngoặc tròn hoặc ngoặc vuông để biểu diễn ma trận. Tách các hệ số ở trên ra và viết thành dạng nhân ma trận:

$$
\begin{equation}
    \begin{pmatrix}
        7 & 8 & 9 \\
        4 & 5 & 6 \\
        1 & 2 & 3
    \end{pmatrix}\begin{pmatrix}
        x_1 \\ x_2 \\ x_3
    \end{pmatrix}=\begin{pmatrix}
      13 \\ 12 \\ 11
    \end{pmatrix}
\end{equation}
$$

Viết gọn là:

$$
Ax=b
$$

Tức là vectơ cột ẩn $x$ được nhân trái bởi một ma trận $A$, thu được vectơ cột $b$. Công thức này có thể xem là dạng cơ bản của đại số tuyến tính.

Mô hình phép toán chủ yếu mà đại số tuyến tính nghiên cứu là tích trong. Tích trong là quá trình nhân trước rồi cộng sau, tức vectơ hàng nhân trái vectơ cột để thu được một số.

Phép nhân ma trận là sự mở rộng của tích trong. Phép nhân ma trận tương đương với việc lấy một hàng của ma trận bên trái và một cột của ma trận bên phải để tính tích trong, thu được phần tử tương ứng của ma trận kết quả; khẩu quyết là "trái hàng, phải cột".

Khi đối tượng nghiên cứu là vectơ cột ở bên phải, phép nhân ma trận tương đương với việc nhân trái vectơ cột. Theo góc nhìn nhân trái, ma trận là phép biến đổi trên vectơ cột: mỗi vectơ cột của ma trận bên phải trong phép nhân ma trận được biến đổi, tương ứng tạo ra từng vectơ cột trong ma trận kết quả.

Ma trận có thể biến đổi một vectơ cột, cũng có thể "đóng gói" để biến đổi một nhóm vectơ cột, thậm chí có thể biến đổi cả không gian, tức toàn bộ các vectơ cột. Khi ma trận được xem là phép biến đổi trên cả không gian, nó cũng tách khỏi không gian và trở thành một phép biến đổi thuần túy.

<span id="định-nghĩa"></span>
## Định nghĩa

Với ma trận $A$, đường chéo chính là các phần tử $A_{i,i}$.

Thường dùng $I$ để biểu diễn ma trận đơn vị, tức ma trận có các phần tử trên đường chéo chính bằng 1, các vị trí còn lại bằng 0.

<span id="ma-trận-cùng-dạng"></span>
### Ma trận cùng dạng

Hai ma trận có số hàng và số cột tương ứng bằng nhau được gọi là ma trận cùng dạng.

<span id="ma-trận-vuông"></span>
### Ma trận vuông

Ma trận có số hàng bằng số cột được gọi là ma trận vuông. Ma trận vuông là một loại ma trận đặc biệt. Cách nói quen thuộc "ma trận bậc $n$" chỉ ma trận vuông bậc $n$. Các ma trận vuông cùng bậc là ma trận cùng dạng.

Khi nghiên cứu hệ phương trình, hệ vectơ, hạng của ma trận, dùng ma trận tổng quát. Khi nghiên cứu giá trị riêng, vectơ riêng và dạng toàn phương, dùng ma trận vuông.

<span id="đường-chéo-chính"></span>
#### Đường chéo chính

Trong ma trận vuông, các phần tử có chỉ số hàng bằng chỉ số cột tạo thành đường chéo chính.

<span id="ma-trận-đối-xứng"></span>
#### Ma trận đối xứng

Nếu các phần tử của ma trận vuông đối xứng qua đường chéo chính, tức với mọi $i$ và $j$, phần tử ở hàng $i$ cột $j$ bằng phần tử ở hàng $j$ cột $i$, thì ma trận vuông đó được gọi là ma trận đối xứng.

<span id="ma-trận-đường-chéo"></span>
#### Ma trận đường chéo

Ma trận vuông có mọi phần tử ngoài đường chéo chính đều bằng $0$ được gọi là ma trận đường chéo, thường ký hiệu là:

$$
\operatorname{diag}\{\lambda_1,\cdots,\lambda_n\}
$$

Trong đó $\lambda_1,\cdots,\lambda_n$ là các phần tử trên đường chéo chính.

Ma trận đường chéo là ma trận đối xứng.

Nếu mọi phần tử của ma trận đường chéo đều bằng $1$, nó được gọi là ma trận đơn vị, ký hiệu $I$. Miễn phép nhân thực hiện được, bất kể hình dạng, nhân một ma trận bất kỳ với ma trận đơn vị vẫn giữ nguyên ma trận đó.

<span id="ma-trận-tam-giác"></span>
#### Ma trận tam giác

Nếu các phần tử phía dưới bên trái đường chéo chính của ma trận vuông đều bằng $0$, ma trận đó được gọi là ma trận tam giác trên. Nếu các phần tử phía trên bên phải đường chéo chính của ma trận vuông đều bằng $0$, ma trận đó được gọi là ma trận tam giác dưới.

Tích của hai ma trận tam giác trên (dưới) vẫn là ma trận tam giác trên (dưới). Nếu các phần tử trên đường chéo đều khác $0$, thì ma trận tam giác trên (dưới) khả nghịch, và nghịch đảo của nó cũng là ma trận tam giác trên (dưới).

<span id="ma-trận-tam-giác-đơn-vị"></span>
#### Ma trận tam giác đơn vị

Nếu mọi phần tử trên đường chéo của ma trận tam giác trên $A$ đều bằng $1$, thì $A$ được gọi là ma trận tam giác trên đơn vị. Nếu mọi phần tử trên đường chéo của ma trận tam giác dưới $A$ đều bằng $1$, thì $A$ được gọi là ma trận tam giác dưới đơn vị.

Tích của hai ma trận tam giác trên (dưới) đơn vị vẫn là ma trận tam giác trên (dưới) đơn vị, và nghịch đảo của ma trận tam giác trên (dưới) đơn vị cũng là ma trận tam giác trên (dưới) đơn vị.

<span id="phép-toán"></span>
## Phép toán

<span id="phép-toán-tuyến-tính-của-ma-trận"></span>
### Phép toán tuyến tính của ma trận

Phép toán tuyến tính của ma trận gồm cộng, trừ và nhân với số; tất cả đều thực hiện theo từng phần tử. Chỉ các ma trận cùng dạng mới có thể cộng trừ tương ứng.

<span id="chuyển-vị-ma-trận"></span>
### Chuyển vị ma trận

Chuyển vị ma trận là viết ký hiệu chuyển vị "T" ở góc trên bên phải của ma trận, biểu thị việc hoán đổi hàng và cột của ma trận.

Ma trận đối xứng không đổi sau khi chuyển vị.

<span id="phép-nhân-ma-trận"></span>
### Phép nhân ma trận

Phép nhân ma trận là sự khái quát của tích trong vectơ.

Hai ma trận chỉ nhân được khi số cột của ma trận thứ nhất bằng số hàng của ma trận thứ hai.

Giả sử $A$ là ma trận $P \times M$, $B$ là ma trận $M \times Q$, và ma trận $C$ là tích của $A$ và $B$.

Khi đó phần tử ở hàng $i$ cột $j$ của ma trận $C$ có thể biểu diễn là:

$$
C_{i,j} = \sum_{k=1}^MA_{i,k}B_{k,j}
$$

Trong phép nhân ma trận, số ở hàng $i$ cột $j$ của ma trận kết quả $C$ được tạo bằng cách lấy $M$ số ở hàng thứ $i$ của ma trận $A$ và $M$ số ở cột thứ $j$ của ma trận $B$, rồi **nhân từng cặp và cộng lại**. Việc **nhân rồi cộng** này chính là tích trong của vectơ. Phần tử ở hàng $i$ cột $j$ của ma trận tích đúng bằng tích trong của vectơ hàng thứ $i$ của ma trận nhân $A$ và vectơ cột thứ $j$ của ma trận nhân $B$, khẩu quyết là **trái hàng, phải cột**.

Các vectơ được nghiên cứu trong đại số tuyến tính phần lớn là vectơ cột. Theo cách định nghĩa phép nhân ma trận như trên, thường nghiên cứu phép nhân trái một ma trận vào vectơ cột; đồng thời qua đó cũng thấy được tư tưởng "đóng gói xử lý", tức xử lý nhiều tích trong của vectơ cùng lúc.

Phép nhân ma trận thỏa tính kết hợp, nhưng trong trường hợp tổng quát không thỏa tính giao hoán.

Dùng tính kết hợp, phép nhân ma trận có thể được tối ưu bằng tư tưởng [lũy thừa nhanh](../binary-exponentiation.md).

Trong thi đấu, vì truy hồi tuyến tính có thể biểu diễn dưới dạng nhân ma trận, lũy thừa ma trận nhanh cũng thường được dùng để tính một số hạng của dãy truy hồi tuyến tính.

<span id="tối-ưu"></span>
#### Tối ưu

Trước hết, với ma trận khá nhỏ, có thể cân nhắc tự trải vòng lặp thủ công để giảm hằng số.

Có thể sắp xếp lại thứ tự vòng lặp để cải thiện tính cục bộ của bộ nhớ. Tối ưu này không thay đổi độ phức tạp thời gian của phép nhân ma trận, nhưng đem lại cải thiện ở mức hằng số.

```cpp
// Lấy mã tham khảo bên dưới làm ví dụ
mat operator*(const mat& T) const {
  mat res;
  for (int i = 0; i < sz; ++i)
    for (int j = 0; j < sz; ++j)
      for (int k = 0; k < sz; ++k) {
        res.a[i][j] += mul(a[i][k], T.a[k][j]);
        res.a[i][j] %= MOD;
      }
  return res;
}

// Không bằng
mat operator*(const mat& T) const {
  mat res;
  int r;
  for (int i = 0; i < sz; ++i)
    for (int k = 0; k < sz; ++k) {
      r = a[i][k];
      for (int j = 0; j < sz; ++j)
        res.a[i][j] += T.a[k][j] * r, res.a[i][j] %= MOD;
    }
  return res;
}
```

<span id="nghịch-đảo-của-ma-trận-vuông"></span>
### Nghịch đảo của ma trận vuông

Ma trận nghịch đảo $P$ của ma trận vuông $A$ là ma trận sao cho $A \times P = I$.

Ma trận nghịch đảo không nhất thiết tồn tại. Nếu tồn tại, có thể dùng [khử Gauss](../numerical/gauss.md) để tìm.

<span id="định-thức-của-ma-trận-vuông"></span>
### Định thức của ma trận vuông

Định thức là một phép toán trên ma trận vuông.

<span id="mã-tham-khảo"></span>
## Mã tham khảo

Thông thường, có thể dùng mảng hai chiều để mô phỏng ma trận.

```cpp
struct mat {
  LL a[sz][sz];

  mat() { memset(a, 0, sizeof a); }

  mat operator-(const mat& T) const {
    mat res;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) {
        res.a[i][j] = (a[i][j] - T.a[i][j]) % MOD;
      }
    return res;
  }

  mat operator+(const mat& T) const {
    mat res;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) {
        res.a[i][j] = (a[i][j] + T.a[i][j]) % MOD;
      }
    return res;
  }

  mat operator*(const mat& T) const {
    mat res;
    int r;
    for (int i = 0; i < sz; ++i)
      for (int k = 0; k < sz; ++k) {
        r = a[i][k];
        for (int j = 0; j < sz; ++j)
          res.a[i][j] += T.a[k][j] * r, res.a[i][j] %= MOD;
      }
    return res;
  }

  mat operator^(LL x) const {
    mat res, bas;
    for (int i = 0; i < sz; ++i) res.a[i][i] = 1;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) bas.a[i][j] = a[i][j] % MOD;
    while (x) {
      if (x & 1) res = res * bas;
      bas = bas * bas;
      x >>= 1;
    }
    return res;
  }
};
```

<span id="hai-góc-nhìn-về-hệ-phương-trình-tuyến-tính"></span>
## Hai góc nhìn về hệ phương trình tuyến tính

Có hai góc nhìn để xem ma trận $A$, hoặc biến đổi $A$.

Góc nhìn thứ nhất: nhìn theo hàng, quan sát từng hàng của $A$. Khi đó xem $A$ như một hệ phương trình, từ đó có quá trình khử để giải phương trình.

Góc nhìn thứ hai: nhìn theo cột, quan sát từng cột của $A$. Bản thân $A$ cũng được tạo bởi các vectơ cột. Khi đó tương đương với việc xem bản thân biến đổi $A$ như một hệ vectơ cột, còn $x$ là hệ số chưa biết; cần xét nhóm vectơ cột trong $A$ có thể ghép với các hệ số chưa biết để tạo ra vectơ cột $b$ hay không.

Ví dụ ở đầu bài trở thành:

$$
\begin{equation}
    \begin{pmatrix}
        7 \\ 4 \\ 1
    \end{pmatrix}x_1+\begin{pmatrix}
        8 \\ 5 \\ 2
    \end{pmatrix}x_2+\begin{pmatrix}
        9 \\ 6 \\ 3
    \end{pmatrix}x_3=\begin{pmatrix}
      13 \\ 12 \\ 11
    \end{pmatrix}
\end{equation}
$$

Giải phương trình trở thành việc nghiên cứu liệu có thể điều chỉnh ba hệ số $x$ để các vectơ cơ sở đã cho ghép lại thành vectơ kết quả hay không.

Nhìn theo cột mới mẻ hơn nhìn theo hàng. Theo góc nhìn theo cột, có thể nghiên cứu độc lập tuyến tính và phụ thuộc tuyến tính.

<span id="ứng-dụng-của-phép-nhân-ma-trận"></span>
## Ứng dụng của phép nhân ma trận

<span id="dùng-ma-trận-tăng-tốc-truy-hồi"></span>
### Dùng ma trận tăng tốc truy hồi

Lấy [dãy Fibonacci (Fibonacci Sequence)](../combinatorics/fibonacci.md) làm ví dụ. Trong dãy Fibonacci, $F_1 = F_2 = 1$, $F_i = F_{i - 1} + F_{i - 2}(i \geq 3)$.

Nếu một bài toán yêu cầu tính giá trị số hạng thứ $n$ của dãy Fibonacci, cách đơn giản nhất là truy hồi trực tiếp. Nhưng nếu phạm vi của $n$ đạt mức $10^{18}$, truy hồi trực tiếp không còn khả thi; lúc này có thể xét tăng tốc truy hồi bằng ma trận.

Theo [dạng ma trận của công thức truy hồi](../combinatorics/fibonacci.md#dạng-ma-trận) của dãy Fibonacci:

$$
\begin{bmatrix}
  F_{n-1} & F_{n-2}
\end{bmatrix} \begin{bmatrix}
  1 & 1 \\
  1 & 0
\end{bmatrix} = \begin{bmatrix}
  F_n & F_{n-1}
\end{bmatrix}
$$

Định nghĩa ma trận ban đầu $\text{ans} = \begin{bmatrix}F_2 & F_1\end{bmatrix} = \begin{bmatrix}1 & 1\end{bmatrix}, \text{base} = \begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}$. Khi đó $F_n$ bằng phần tử hàng thứ nhất cột thứ nhất của ma trận $\text{ans} \text{base}^{n-2}$, tức phần tử hàng thứ nhất cột thứ nhất của $\begin{bmatrix}1 & 1\end{bmatrix} \begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}^{n-2}$.

???+ warning "Lưu ý"
    Phép nhân ma trận không thỏa tính giao hoán, nên tuyệt đối không được viết thành phần tử hàng thứ nhất cột thứ nhất của $\begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}^{n-2} \begin{bmatrix}1 & 1\end{bmatrix}$. Ngoài ra, với trường hợp $n \leq 2$, chỉ cần xuất trực tiếp $1$, không cần thực hiện lũy thừa ma trận nhanh.

Tại sao phải nhân với lũy thừa $n-2$ của ma trận $\text{base}$ mà không phải lũy thừa $n$? Vì $F_1, F_2$ không cần phép nhân ma trận cũng có thể tính được. Nói cách khác, chỉ thực hiện một phép nhân đã tính được $F_3$. Nếu vẫn chưa hiểu vì sao số mũ là $n-2$, nên tự tính tay một lần.

Dưới đây là mã ví dụ phần lõi để tính số hạng thứ $n$ của dãy Fibonacci theo modulo $10^9+7$.

```cpp
constexpr int mod = 1000000007;

struct Matrix {
  int a[3][3];

  Matrix() { memset(a, 0, sizeof a); }

  Matrix operator*(const Matrix &b) const {
    Matrix res;
    for (int i = 1; i <= 2; ++i)
      for (int j = 1; j <= 2; ++j)
        for (int k = 1; k <= 2; ++k)
          res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
    return res;
  }
} ans, base;

void init() {
  base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
  ans.a[1][1] = ans.a[1][2] = 1;
}

void qpow(int b) {
  while (b) {
    if (b & 1) ans = ans * base;
    base = base * base;
    b >>= 1;
  }
}

int main() {
  int n = read();
  if (n <= 2) return puts("1"), 0;
  init();
  qpow(n - 2);
  println(ans.a[1][1] % mod);
}
```

Đây là một ví dụ phức tạp hơn một chút.

$$
\begin{gathered}
f_{1} = f_{2} = 0\\
f_{n} = 7f_{n-1}+6f_{n-2}+5n+4\times 3^n
\end{gathered}
$$

Vì $f_n$ liên quan đến $f_{n-1}, f_{n-2}, n$, xét xây dựng một ma trận để mô tả trạng thái.

Nhưng nếu ma trận chỉ có ba phần tử $\begin{bmatrix}f_n& f_{n-1}& n\end{bmatrix}$ thì khó xây dựng phương trình chuyển, vì phép lũy thừa và phép $+1$ không thể được mô tả bằng ma trận đó.

Vì vậy xét xây dựng một ma trận lớn hơn.

$$
\begin{bmatrix}f_n& f_{n-1}& n& 3^n & 1\end{bmatrix}
$$

Cần xây dựng một ma trận truy hồi để chuyển sang

$$
\begin{bmatrix}
f_{n+1}& f_{n}& n+1& 3^{n+1} & 1
\end{bmatrix}
$$

Ma trận chuyển là

$$
\begin{bmatrix}
7 & 1 & 0 & 0 & 0\\
6 & 0 & 0 & 0 & 0\\
5 & 0 & 1 & 0 & 0\\
12 & 0 & 0 & 3 & 0\\
5 & 0 & 1 & 0 & 1
\end{bmatrix}
$$

<span id="dùng-ma-trận-biểu-diễn-cập-nhật"></span>
### Dùng ma trận biểu diễn cập nhật

???+ note "[THUSCH 2017 Đại pháp sư](https://loj.ac/p/2980)"
    Tiểu L, một đại pháp sư, chế tạo $n$ quả cầu pha lê ma lực. Mỗi quả cầu pha lê có ba thuộc tính năng lượng: nước, lửa, đất. Tiểu L xếp $n$ quả cầu pha lê này thành một hàng trên mặt đất từ trước ra sau, rồi bắt đầu buổi biểu diễn ma pháp hôm nay.
    
    Dùng $A_i,\ B_i,\ C_i$ lần lượt biểu thị giá trị năng lượng nước, lửa, đất của quả cầu pha lê thứ $i$ từ trước ra sau (chỉ số bắt đầu từ $1$).
    
    Tiểu L dự định thi triển $m$ lần ma pháp. Mỗi lần, cậu chọn một đoạn $[l, r]$, rồi thi triển một trong $3$ nhóm lớn, tổng cộng $7$ loại ma pháp sau:
    
    1.  Kích phát ma lực: làm năng lượng của một **thuộc tính nhất định** trong mỗi quả cầu pha lê trong đoạn bùng phát, từ đó tăng cường năng lượng của một **thuộc tính nhất định** khác. Cụ thể có ba dạng:
    
        -   Nguyên tố lửa kích phát năng lượng nước: đặt $A_i = A_i + B_i$.
        -   Nguyên tố đất kích phát năng lượng lửa: đặt $B_i = B_i + C_i$.
        -   Nguyên tố nước kích phát năng lượng đất: đặt $C_i = C_i + A_i$.
    
            **Cần lưu ý rằng tăng cường năng lượng của một thuộc tính sẽ không làm thay đổi năng lượng của thuộc tính còn lại; ví dụ $A_i = A_i + B_i$ không làm $B_i$ tăng hoặc giảm.**
    2.  Tăng cường ma lực: Tiểu L vung pháp trượng, tiêu hao $v$ điểm pháp lực của bản thân để thay đổi năng lượng của một **thuộc tính nhất định** trong mỗi quả cầu pha lê trong đoạn. Cụ thể có ba dạng:
    
        -   Tăng cố định năng lượng nguyên tố lửa: đặt $A_i = A_i + v$.
        -   Tăng gấp bội năng lượng nguyên tố nước: đặt $B_i=B_i \cdot v$.
        -   Hấp thu dung hợp năng lượng nguyên tố đất: đặt $C_i = v$.
    3.  Giải phóng ma lực: Tiểu L gom năng lượng của tất cả quả cầu pha lê trong đoạn lại, dung hợp thành một quả cầu pha lê mới, rồi tặng cho khán giả ngoài sân. Giá trị năng lượng của mỗi thuộc tính trong quả cầu pha lê tạo ra bằng tổng đại số của các giá trị năng lượng thuộc tính tương ứng trong đoạn. **Cần lưu ý rằng quá trình giải phóng ma lực không thật sự thay đổi năng lượng của các quả cầu pha lê trong đoạn**.
    
    Đáng nói là nguyên liệu tạo và dung hợp cầu pha lê của Tiểu L đều là cầu pha lê phiên bản tùy chỉnh từ nhà máy OI, nên các quả cầu pha lê này có ngưỡng năng lượng $998244353$. Khi giá trị năng lượng của một thuộc tính trong quả cầu pha lê lớn hơn hoặc bằng ngưỡng này, giá trị năng lượng sẽ tự động lấy modulo theo ngưỡng để tránh quả cầu pha lê phát nổ.
    
    Tiểu W là khán giả duy nhất của Tiểu L, theo dõi toàn bộ buổi biểu diễn và nhận được từng quả cầu pha lê mà Tiểu L dung hợp trong buổi biểu diễn. Tiểu W muốn biết ba giá trị năng lượng thuộc tính chứa trong các quả cầu pha lê này lần lượt là bao nhiêu.

Vì phép nhân ma trận thỏa tính kết hợp và phân phối, cập nhật tại một điểm có thể tự nhiên mở rộng thành cập nhật trên đoạn; sau khi suy ra ma trận, chỉ cần dùng cây đoạn để duy trì tích ma trận trên đoạn.

Dưới đây nêu vài ví dụ.

Chuyển trạng thái của $A_i = A_i + v$:

$$
\begin{bmatrix}
A & B & C & 1
\end{bmatrix}
\begin{bmatrix}
1 & 0 & 0 & 0\\
0 & 1 & 0 & 0\\
0 & 0 & 1 & 0\\
v & 0 & 0 & 1\\
\end{bmatrix}=
\begin{bmatrix}
A+v & B & C & 1\\
\end{bmatrix}
$$

Chuyển trạng thái của $B_i=B_i \cdot v$:

$$
\begin{bmatrix}
A & B & C & 1
\end{bmatrix}
\begin{bmatrix}
1 & 0 & 0 & 0\\
0 & v & 0 & 0\\
0 & 0 & 1 & 0\\
0 & 0 & 0 & 1\\
\end{bmatrix}=
\begin{bmatrix}
A & B \cdot v & C & 1\\
\end{bmatrix}
$$

???+ note "[LibreOJ 6208 Truy vấn trên cây](https://loj.ac/p/6208)"
    Có một cây gồm $n$ nút, gốc là nút số $1$. Mỗi nút có hai giá trị $k_i, t_i$, ban đầu đều bằng $0$.
    
    Cho ba loại thao tác:
    
    1.  Thao tác $\operatorname{Add}( x , d )$: với mọi điểm trên đường đi từ $x$ đến gốc, gán $k_i\leftarrow k_i + d$.
    2.  Thao tác $\operatorname{Mul}( x , d )$: với mọi điểm trên đường đi từ $x$ đến gốc, gán $t_i\leftarrow t_i + d \times k_i$.
    3.  Thao tác $\operatorname{Query}( x )$: hỏi giá trị $t_x$ của điểm $x$.
    
        $n,~m \leq 100000, ~-10 \leq d \leq 10$

Nếu suy nghĩ trực tiếp, việc đẩy thao tác xuống và duy trì thông tin không dễ hình dung. Nhưng ma trận có thể biểu diễn điều đó rất nhẹ nhàng.

$$
\begin{aligned}
\begin{bmatrix}k & t & 1 \end{bmatrix}
\begin{bmatrix}
1 & 0 & 0 \\
0 & 1 & 0 \\
d & 0 & 1
\end{bmatrix}
&=
\begin{bmatrix}k+d & t & 1 \end{bmatrix}\\
\begin{bmatrix}k & t & 1 \end{bmatrix}
\begin{bmatrix}
1 & d & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{bmatrix}
&=
\begin{bmatrix}k & t+d \times k & 1 \end{bmatrix}
\end{aligned}
$$

<span id="đếm-đường-đi-độ-dài-cố-định"></span>
### Đếm đường đi độ dài cố định

???+ note "Mô tả bài toán"
    Cho một đồ thị có hướng bậc $n$, mỗi cạnh có trọng số bằng $1$, rồi cho một số nguyên $k$. Nhiệm vụ là với mọi cặp đỉnh $(u,v)$, tìm số đường đi từ $u$ đến $v$ có độ dài bằng $k$ (không nhất thiết là đường đi đơn, tức các đỉnh hoặc cạnh trên đường đi có thể được đi qua nhiều lần).

Biểu diễn đồ thị này bằng ma trận kề $G$: với cạnh $(u\to v)$ trong đồ thị, đặt $G[u,v]=1$, các vị trí khác bằng $0$; nếu có cạnh song song, thì đặt $G[u,v]$ bằng số cạnh song song. Thuật toán dưới đây cũng áp dụng được khi đồ thị có khuyên.

Ma trận kề này chính là đáp án khi $k=1$.

Giả sử đã biết ma trận gồm số đường đi có độ dài $k$, ký hiệu là ma trận $C_k$, và muốn tìm $C_{k+1}$. Có phương trình chuyển DP:

$$
C_{k+1}[i,j] = \sum_{p = 1}^{n} C_k[i,p] \cdot G[p,j]
$$

Có thể xem nó như một phép nhân ma trận, vì vậy chuyển trạng thái trên có thể mô tả là

$$
C_{k+1} = C_k \cdot G
$$

Khai triển truy hồi này được

$$
C_k = \underbrace{G \cdot G \cdots G}_{k \text{ lần}} = G^k
$$

Để tính lũy thừa ma trận này, có thể dùng tư tưởng lũy thừa nhanh (lũy thừa nhị phân), tính kết quả trong độ phức tạp $O(n^3 \log k)$.

<span id="đường-đi-ngắn-nhất-có-độ-dài-cố-định"></span>
### Đường đi ngắn nhất có độ dài cố định

???+ note "Mô tả bài toán"
    Cho một đồ thị có hướng có trọng số bậc $n$ và một số nguyên $k$. Với mỗi cặp đỉnh $(u,v)$, tìm độ dài đường đi ngắn nhất từ $u$ đến $v$ chứa đúng $k$ cạnh. (Không nhất thiết là đường đi đơn, tức các đỉnh hoặc cạnh trên đường đi có thể được đi qua nhiều lần.)

Vẫn xây dựng ma trận kề $G$ của đồ thị, trong đó $G[i,j]$ biểu thị trọng số cạnh từ $i$ đến $j$. Nếu giữa hai đỉnh $i,j$ không có cạnh, thì $G[i,j]=\infty$. (Nếu có cạnh song song thì lấy trọng số nhỏ nhất.)

Ma trận trên là đáp án của bài toán khi $k=1$. Giả sử đã biết đáp án với $k$, ký hiệu là ma trận $L_k$. Bây giờ muốn tìm đáp án với $k+1$. Có phương trình chuyển:

$$
L_{k+1}[i,j] = \min_{1\le p \le n} \left\{L_k[i,p] + G[p,j]\right\}
$$

Có thể xem tương tự phép nhân ma trận: chuyển trạng thái trên chỉ thay "nhân rồi cộng" trong phép nhân ma trận bằng "cộng rồi lấy nhỏ nhất". Vì vậy định nghĩa phép toán này là $\odot$, tức

$$
A \odot B = C~~\Longleftrightarrow~~C[i,j]=\min_{1\le p \le n}\left\{A[i,p] + B[p,j]\right\}
$$

Suy ra

$$
L_{k+1} = L_k \odot G
$$

Khai triển truy hồi được

$$
L_k = \underbrace{G \odot \ldots \odot G}_{k\text{ lần}} = G^{\odot k}
$$

Vẫn có thể dùng phương pháp lũy thừa ma trận nhanh để tính biểu thức trên, vì phép toán này có tính kết hợp. Độ phức tạp thời gian là $O(n^3 \log k)$.

<span id="đếm-đường-đi-đường-đi-ngắn-nhất-với-giới-hạn-độ-dài"></span>
### Đếm đường đi/đường đi ngắn nhất với giới hạn độ dài

Thuật toán trên chỉ áp dụng cho trường hợp số cạnh cố định. Tuy nhiên, có thể cải tiến thuật toán để giải trường hợp số cạnh nhỏ hơn hoặc bằng $k$. Cụ thể, xét bài toán sau:

???+ note "Mô tả bài toán"
    Cho một đồ thị có hướng bậc $n$, trọng số cạnh bằng $1$, rồi cho một số nguyên $k$. Nhiệm vụ là với mỗi cặp đỉnh $(u,v)$, tìm số đường đi từ $u$ đến $v$ có độ dài nhỏ hơn hoặc bằng $k$ (không nhất thiết là đường đi đơn, tức các đỉnh hoặc cạnh trên đường đi có thể được đi qua nhiều lần).

Với mỗi đỉnh $v$, tạo một đỉnh ảo $v'$ để ghi đáp án, đồng thời thêm hai cạnh $(v,v')$ và $(v',v')$ vào đồ thị. Khi đó với cặp đỉnh $(u,v)$, số đường đi từ $u$ đến $v$ có số cạnh nhỏ hơn hoặc bằng $k$ bằng số đường đi từ $u$ đến $v'$ có số cạnh đúng bằng $k+1$. Lý do là với mọi đường đi có số cạnh $m(m \le k)$ là $(p_0=u)\to p_1\to p_2 \to \dots \to p_{m-1} \to (p_m=v)$, đều tồn tại một đường đi có số cạnh $k+1$ là $(p_0=u)\to p_1 \to p_2 \to \dots \to p_{m-1} \to (p_m=v) \to v'  \to \dots \to v'$ tương ứng một-một với nó.

Với bài toán tìm đường đi ngắn nhất có số cạnh nhỏ hơn hoặc bằng $k$, chỉ cần thêm cho mỗi đỉnh một khuyên có trọng số $0$.

<span id="bài-tập"></span>
## Bài tập

-   [Luogu P1962 Dãy Fibonacci](https://www.luogu.com.cn/problem/P1962), chính là ví dụ ở trên, cùng bài với POJ3070
-   [Luogu P1349 Dãy Fibonacci tổng quát](https://www.luogu.com.cn/problem/P1349), ma trận $\text{base}$ cần thay đổi một chút
-   [Luogu P1939 Mẫu: tăng tốc ma trận cho dãy số](https://www.luogu.com.cn/problem/P1939), ma trận $\text{base}$ trở thành ma trận $3 \times 3$, quá trình suy luận gần giống ở trên.

**Một phần nội dung của trang này được dịch từ bài viết [Kratchaishie puti fiksirovannoi dliny, kolichestva putei fiksirovannoi dliny](http://e-maxx.ru/algo/fixed_length_paths) và bản dịch tiếng Anh [Number of paths of fixed length/Shortest paths of fixed length](https://cp-algorithms.com/graph/fixed_length_paths.html). Trong đó bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.**
