Trang này quy định cách viết khuyến nghị cho các ký hiệu toán học trong **OI Wiki**, đồng thời đưa ra một số ví dụ áp dụng.

Trang này được hiệu chỉnh dựa trên [GB/T 3102.11-1993](https://openstd.samr.gov.cn/bzgk/gb/newGbInfo?hcno=3DE79450D562E62D41CB6E79FF411054), [ISO 80000-2:2019](https://www.iso.org/standard/64973.html) và bảng ký hiệu trong *Concrete Mathematics*, nên về cơ bản tương thích với hệ ký hiệu trong các giáo trình thông dụng và các ký hiệu thường dùng trong bối cảnh OI.

Về cách viết LaTeX của các ký hiệu, tham khảo [mã nguồn của bài viết này](https://github.com/cuom1999/OI-wiki/blob/vietnamese-translation/docs/intro/symbol.md?plain=1).

## Logic toán học

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n1.1"></a>n1.1 | $p \land q$ | Hội của $p$ và $q$ | $p$ và $q$. |
| <a id="n1.2"></a>n1.2 | $p \lor q$ | Tuyển của $p$ và $q$ | $p$ hoặc $q$;<br>"hoặc" trong ngữ cảnh này là hoặc bao hàm, tức nếu một trong $p$, $q$ là mệnh đề đúng thì $p \lor q$ đúng. |
| <a id="n1.3"></a>n1.3 | $\lnot p$ | Phủ định của $p$ | Không phải $p$. |
| <a id="n1.4"></a>n1.4 | $p \implies q$ | $p$ kéo theo $q$;<br>nếu $p$ đúng thì $q$ đúng | $q \impliedby p$ và $p \implies q$ đồng nghĩa. |
| <a id="n1.5"></a>n1.5 | $p \iff q$ | $p$ tương đương với $q$ | $(p \implies q) \land (q \implies p)$ và $p \iff q$ đồng nghĩa. |
| <a id="n1.6"></a>n1.6 | $(\forall~x \in A)~~p(x)$ | Với mọi $x$ trong $A$, mệnh đề $p(x)$ đều đúng | Nếu từ ngữ cảnh có thể biết tập đang xét là $A$, có thể dùng ký hiệu $(\forall~x)~~p(x)$.<br>$\forall$ được gọi là lượng từ phổ quát.<br>Ý nghĩa của $x \in A$ xem tại [n2.1](#n2.1). |
| <a id="n1.7"></a>n1.7 | $(\exists~x \in A)~~p(x)$ | Tồn tại một $x$ thuộc $A$ sao cho $p(x)$ đúng | Nếu từ ngữ cảnh có thể biết tập đang xét là $A$, có thể dùng ký hiệu $(\exists~x)~~p(x)$.<br>$\exists$ được gọi là lượng từ tồn tại.<br>Ý nghĩa của $x \in A$ xem tại [n2.1](#n2.1).<br>$(\exists!~x)~~p(x)$ (lượng từ duy nhất) dùng để biểu thị có đúng một $x$ sao cho $p(x)$ đúng.<br>$\exists!$ cũng có thể viết là $\exists^1$. |

## Lý thuyết tập hợp

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n2.1"></a>n2.1 | $x \in A$ | $x$ thuộc $A$, $x$ là phần tử của tập hợp $A$ | $A \ni x$ và $x \in A$ đồng nghĩa. |
| <a id="n2.2"></a>n2.2 | $y \notin A$ | $y$ không thuộc $A$, $y$ không phải là phần tử của tập hợp $A$ | |
| <a id="n2.3"></a>n2.3 | $\{x_1, x_2, \dots, x_n\}$ | Tập hợp chứa các phần tử $x_1, x_2, \dots, x_n$ | Cũng có thể viết là $\{x_i ~\vert~ i \in I\}$, trong đó $I$ là tập chỉ số. |
| <a id="n2.4"></a>n2.4 | $\{x \in A ~\vert~ p(x)\}$ | Tập hợp gồm mọi phần tử trong $A$ làm cho mệnh đề $p(x)$ đúng | Ví dụ $\{x \in \textbf{R} ~\vert~ x \geq 5\}$;<br>nếu từ ngữ cảnh có thể biết tập đang xét là $A$, có thể dùng ký hiệu $\{x ~\vert~ p(x)\}$ (chẳng hạn khi chỉ xét tập số thực, có thể dùng $\{x ~\vert~ x \geq 5\}$).<br>$\vert$ cũng có thể thay bằng dấu hai chấm, như $\{x \in A : p(x)\}$. |
| <a id="n2.5"></a>n2.5 | $\operatorname{card} A$;<br>$\vert A\vert$;<br>$\# A$ | Số phần tử trong $A$, lực lượng của $A$ | |
| <a id="n2.6"></a>n2.6 | $\varnothing$ | Tập rỗng | Không nên dùng $\emptyset$. |
| <a id="n2.7"></a>n2.7 | $B \subseteq A$ | $B$ được chứa trong $A$, $B$ là tập con của $A$ | Mọi phần tử của $B$ đều thuộc $A$.<br>$\subset$ cũng có thể được dùng với nghĩa này, nhưng xem phần giải thích tại [n2.8](#n2.8).<br>$A \supseteq B$ và $B \subseteq A$ đồng nghĩa. |
| <a id="n2.8"></a>n2.8 | $B \subset A$ | $B$ được chứa thật sự trong $A$, $B$ là tập con thực sự của $A$ | Mọi phần tử của $B$ đều thuộc $A$, và trong $A$ có ít nhất một phần tử không thuộc $B$.<br>Nếu $\subset$ được hiểu theo nghĩa ở [n2.7](#n2.7), thì ký hiệu tương ứng với [n2.8](#n2.8) nên dùng $\subsetneq$.<br>$A \supset B$ và $B \subset A$ đồng nghĩa. |
| <a id="n2.9"></a>n2.9 | $A \cup B$ | Hợp của $A$ và $B$ | $A \cup B := \{x ~\vert~ x \in A \lor x \in B\}$;<br>định nghĩa của $:=$ xem tại [n4.3](#n4.3). |
| <a id="n2.10"></a>n2.10 | $A \cap B$ | Giao của $A$ và $B$ | $A \cap B := \{x ~\vert~ x \in A \land x \in B\}$;<br>định nghĩa của $:=$ xem tại [n4.3](#n4.3). |
| <a id="n2.11"></a>n2.11 | $\displaystyle \bigcup\limits_{i=1}^n A_i$ | Hợp của các tập hợp $A_1, A_2, \dots, A_n$ | $\displaystyle \bigcup\limits_{i=1}^n A_i=A_1\cup A_2\cup \dots \cup A_n$;<br>cũng có thể dùng $\displaystyle \bigcup\nolimits_{i=1}^n$, $\displaystyle \bigcup\limits_{i\in I}$, $\displaystyle \bigcup\nolimits_{i\in I}$, trong đó $I$ là tập chỉ số;<br>hơn nữa, đặt $P(i)$ là một mệnh đề liên quan đến $i$, có thể dùng $\displaystyle \bigcup_{P(i)} A_i$ để biểu thị hợp của các $A_i$ ứng với mọi $i$ làm cho $P(i)$ đúng. |
| <a id="n2.12"></a>n2.12 | $\displaystyle \bigcap\limits_{i=1}^n A_i$ | Giao của các tập hợp $A_1, A_2, \dots, A_n$ | $\displaystyle \bigcap\limits_{i=1}^n A_i=A_1\cap A_2\cap \dots \cap A_n$;<br>cũng có thể dùng $\displaystyle \bigcap\nolimits_{i=1}^n$, $\displaystyle \bigcap\limits_{i\in I}$, $\displaystyle \bigcap\nolimits_{i\in I}$, trong đó $I$ là tập chỉ số;<br>hơn nữa, đặt $P(i)$ là một mệnh đề liên quan đến $i$, có thể dùng $\displaystyle \bigcap_{P(i)} A_i$ để biểu thị giao của các $A_i$ ứng với mọi $i$ làm cho $P(i)$ đúng. |
| <a id="n2.13"></a>n2.13 | $A \setminus B$ | Hiệu của $A$ và $B$ | $A \setminus B = \{x ~\vert~ x \in A \land x \notin B\}$;<br>không nên dùng $A - B$;<br>khi $B$ là tập con của $A$, cũng có thể dùng $\complement_A B$; nếu từ ngữ cảnh có thể biết tập đang xét là $A$ thì có thể lược bỏ $A$.<br>Khi không gây nhầm lẫn, cũng có thể dùng $\overline{B}$ để biểu thị phần bù của tập hợp $B$. |
| <a id="n2.14"></a>n2.14 | $(a, b)$ | Cặp có thứ tự $a$, $b$ | $(a, b) = (c, d)$ khi và chỉ khi $a = c$ và $b = d$. |
| <a id="n2.15"></a>n2.15 | $(a_1, a_2, \dots, a_n)$ | Bộ $n$ phần tử có thứ tự | Xem [n2.14](#n2.14). |
| <a id="n2.16"></a>n2.16 | $A \times B$ | Tích Descartes của các tập hợp $A$ và $B$ | $A \times B = \{(x, y) ~\vert~ x \in A \land y \in B\}$. |
| <a id="n2.17"></a>n2.17 | $\displaystyle \prod\limits_{i=1}^{n} A_i$ | Tích Descartes của các tập hợp $A_1, A_2, \dots, A_n$ | $\displaystyle \prod\limits_{i=1}^{n} A_i=\{(x_1, x_2, \dots, x_n) ~\vert~ x_1 \in A_1, x_2 \in A_2, \dots, x_n \in A_n\}$;<br>$A \times A \times \dots \times A$ được ký hiệu là $A^n$, trong đó $n$ là số thừa số trong tích;<br>một cách dùng khác của ký hiệu này xem tại [n6.8](#n6.8). |
| <a id="n2.18"></a>n2.18 | $\mathrm{id}_A$ | Tập đường chéo của $A\times A$ | $\mathrm{id}_A=\{(x, x)~\vert~x\in A\}$;<br>nếu từ ngữ cảnh có thể biết tập đang xét là $A$ thì có thể lược bỏ $A$. |
| <a id="n2.19"></a>n2.19 | $\mathbf{1}_A$ | Hàm chỉ thị | $\mathbf{1}_A(a)=[a\in A]$, định nghĩa của $[\cdot]$ xem tại [n6.24](#n6.24). |
| <a id="n2.20"></a>n2.20 | $\mathcal{P}(A)$;<br>$2^A$ | Tập lũy thừa | $\mathcal{P}(A)=\{S:S\subseteq A\}$ |

## Tập số chuẩn và khoảng

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n3.1"></a>n3.1 | $\mathbf{N}$ | Tập số tự nhiên | $\mathbf{N} = \{0, 1, 2, 3, \dots\}$;<br>$\mathbf{N}^* = \mathbf{N}_+ = \{1, 2, 3, \dots\}$;<br>có thể thêm các ràng buộc khác theo cách sau: $\mathbf{N}_{> 5} = \{n \in \mathbf{N} ~\vert~ n > 5\}$;<br>cũng có thể dùng $\mathbb{N}$. |
| <a id="n3.2"></a>n3.2 | $\mathbf{Z}$ | Tập số nguyên | $\mathbf{Z}^* = \mathbf{Z}_+ = \{n \in \mathbf{Z} ~\vert~ n \ne 0\}$;<br>có thể thêm các ràng buộc khác theo cách sau: $\mathbf{Z}_{> -3} = \{n \in \mathbf{Z} ~\vert~ n > -3\}$;<br>cũng có thể dùng $\mathbb{Z}$. |
| <a id="n3.3"></a>n3.3 | $\mathbf{Q}$ | Tập số hữu tỉ | $\mathbf{Q}^* = \mathbf{Q}_+ = \{r \in \mathbf{Q} ~\vert~ r \ne 0\}$;<br>có thể thêm các ràng buộc khác theo cách sau: $\mathbf{Q}_{< 0} = \{r \in \mathbf{Q} ~\vert~ r < 0\}$;<br>cũng có thể dùng $\mathbb{Q}$. |
| <a id="n3.4"></a>n3.4 | $\mathbf{R}$ | Tập số thực | $\mathbf{R}^* = \mathbf{R}_+ = \{x \in \mathbf{R} ~\vert~ x \ne 0\}$;<br>có thể thêm các ràng buộc khác theo cách sau: $\mathbf{R}_{> 0} = \{x \in \mathbf{R} ~\vert~ x > 0\}$;<br>cũng có thể dùng $\mathbb{R}$. |
| <a id="n3.5"></a>n3.5 | $\mathbf{C}$ | Tập số phức | $\mathbf{C}^* = \mathbf{C}_+ = \{z \in \mathbf{C} ~\vert~ z \ne 0\}$;<br>cũng có thể dùng $\mathbb{C}$. |
| <a id="n3.6"></a>n3.6 | $\mathbf{P}$ | Tập số nguyên tố (dương) | $\mathbf{P} = \{2, 3, 5, 7, 11, 13, 17, \dots\}$;<br>cũng có thể dùng $\mathbb{P}$. |
| <a id="n3.7"></a>n3.7 | $[a, b]$ | Khoảng đóng từ $a$ đến $b$ | $[a, b] = \{x \in \mathbf{R} ~\vert~ a \leq x \leq b\}$. |
| <a id="n3.8"></a>n3.8 | $(a, b]$ | Khoảng mở trái đóng phải từ $a$ đến $b$ | $(a, b] = \{x \in \mathbf{R} ~\vert~ a < x \leq b\}$;<br>$(-\infty, b] = \{x \in \mathbf{R} ~\vert~ x \leq b\}$. |
| <a id="n3.9"></a>n3.9 | $[a, b)$ | Khoảng đóng trái mở phải từ $a$ đến $b$ | $[a, b) = \{x \in \mathbf{R} ~\vert~ a \leq x < b\}$;<br>$[a, +\infty) = \{x \in \mathbf{R} ~\vert~ a \leq x\}$. |
| <a id="n3.10"></a>n3.10 | $(a, b)$ | Khoảng mở từ $a$ đến $b$ | $(a, b) = \{x \in \mathbf{R} ~\vert~ a < x < b\}$;<br>$(-\infty, b) = \{x \in \mathbf{R} ~\vert~ x < b\}$;<br>$(a, +\infty) = \{x \in \mathbf{R} ~\vert~ a < x\}$. |

## Quan hệ

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n4.1"></a>n4.1 | $a = b$ | $a$ bằng $b$ | $\equiv$ dùng để nhấn mạnh một đẳng thức là đồng nhất thức.<br>Một nghĩa khác của ký hiệu này xem tại [n4.18](#n4.18). |
| <a id="n4.2"></a>n4.2 | $a \ne b$ | $a$ không bằng $b$ | |
| <a id="n4.3"></a>n4.3 | $a := b$ | $a$ được định nghĩa là $b$ | Xem [n2.9](#n2.9), [n2.10](#n2.10). |
| <a id="n4.4"></a>n4.4 | $a \approx b$ | $a$ xấp xỉ bằng $b$ | Không loại trừ trường hợp bằng nhau. |
| <a id="n4.5"></a>n4.5 | $a \simeq b$ | $a$ tiệm cận bằng $b$ | Ví dụ:<br>khi $x\to a$, $\dfrac{1}{\sin(x-a)} \simeq \dfrac{1}{x-a}$;<br>ý nghĩa của $x \to a$ xem tại n4.15. |
| <a id="n4.6"></a>n4.6 | $a \propto b$ | $a$ tỉ lệ thuận với $b$ | Cũng có thể dùng $a \sim b$.<br>$\sim$ cũng được dùng để biểu thị quan hệ tương đương. |
| <a id="n4.7"></a>n4.7 | $M \cong N$ | $M$ toàn đẳng với $N$ | Khi $M$ và $N$ là tập điểm (hình hình học).<br>Ký hiệu này cũng được dùng để biểu thị đẳng cấu của cấu trúc đại số. |
| <a id="n4.8"></a>n4.8 | $a < b$ | $a$ nhỏ hơn $b$ | |
| <a id="n4.9"></a>n4.9 | $b > a$ | $b$ lớn hơn $a$ | |
| <a id="n4.10"></a>n4.10 | $a \leq b$ | $a$ nhỏ hơn hoặc bằng $b$ | |
| <a id="n4.11"></a>n4.11 | $b \geq a$ | $b$ lớn hơn hoặc bằng $a$ | |
| <a id="n4.12"></a>n4.12 | $a \ll b$ | $a$ rất nhỏ so với $b$ | |
| <a id="n4.13"></a>n4.13 | $b \gg a$ | $b$ rất lớn so với $a$ | |
| <a id="n4.14"></a>n4.14 | $\infty$ | Vô cực | Ký hiệu này **không** phải là một số.<br>Cũng có thể dùng $+\infty$, $-\infty$. |
| <a id="n4.15"></a>n4.15 | $x \to a$ | $x$ tiến tới $a$ | Thường xuất hiện trong biểu thức giới hạn.<br>$a$ cũng có thể là $\infty$, $+\infty$, $-\infty$. |
| <a id="n4.16"></a>n4.16 | $m \mid n$ | $m$ chia hết $n$ | Với các số nguyên $m$, $n$:<br>$(\exists~k \in \mathbf{Z})~~m\cdot k = n$. |
| <a id="n4.17"></a>n4.17 | $m \perp n$ | $m$ và $n$ nguyên tố cùng nhau | Với các số nguyên $m$, $n$:<br>$(\nexists~k \in \mathbf{Z}_{>1})~~(k \mid m) \land (k \mid n)$;<br>một cách dùng khác của ký hiệu này xem tại [n5.2](#n5.2). |
| <a id="n4.18"></a>n4.18 | $n \equiv k \pmod m$ | $n$ đồng dư với $k$ modulo $m$ | Với các số nguyên $n$, $k$, $m$:<br>$m \mid (n - k)$;<br>đừng nhầm với nghĩa được nhắc tới trong [n4.1](#n4.1). |

## Hình học sơ cấp

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n5.1"></a>n5.1 | $\parallel$ | Song song | |
| <a id="n5.2"></a>n5.2 | $\perp$ | Vuông góc | Một cách dùng khác của ký hiệu này xem tại [n4.17](#n4.17). |
| <a id="n5.3"></a>n5.3 | $\angle$ | Góc (phẳng) | |
| <a id="n5.4"></a>n5.4 | $\overline{\mathrm{AB}}$ | Đoạn thẳng $\mathrm{AB}$ | |
| <a id="n5.5"></a>n5.5 | $\overrightarrow{\mathrm{AB}}$ | Đoạn thẳng có hướng $\mathrm{AB}$ | |
| <a id="n5.6"></a>n5.6 | $d(\mathrm{A}, \mathrm{B})$ | Khoảng cách giữa hai điểm $\mathrm{A}$ và $\mathrm{B}$ | Tức độ dài của $\overline{\mathrm{AB}}$. |

## Toán tử

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n6.1"></a>n6.1 | $a + b$ | $a$ cộng $b$ | |
| <a id="n6.2"></a>n6.2 | $a - b$ | $a$ trừ $b$ | |
| <a id="n6.3"></a>n6.3 | $a \pm b$ | $a$ cộng hoặc trừ $b$ | |
| <a id="n6.4"></a>n6.4 | $a \mp b$ | $a$ trừ hoặc cộng $b$ | $-(a \pm b) = -a \mp b$. |
| <a id="n6.5"></a>n6.5 | $a \cdot b$;<br>$a \times b$;<br>$ab$ | $a$ nhân $b$ | Nếu xuất hiện dấu thập phân, chỉ nên dùng $\times$;<br>một số cách dùng xem tại [n2.16](#n2.16), [n2.17](#n2.17), [n14.11](#n14.11), [n14.12](#n14.12). |
| <a id="n6.6"></a>n6.6 | $\dfrac{a}{b}$;<br>$a/b$;<br>$a:b$ | $a$ chia cho $b$ | $\dfrac{a}{b}=a\cdot b^{-1}$;<br>có thể dùng $:$ để biểu thị tỉ lệ giữa các giá trị cùng thứ nguyên.<br>Không nên dùng $÷$. |
| <a id="n6.7"></a>n6.7 | $\displaystyle \sum\limits_{i=1}^n a_i$ | $a_1 + a_2 + \dots + a_n$ | Cũng có thể dùng $\displaystyle \sum\nolimits_{i=1}^n a_i$, $\displaystyle \sum\limits_i a_i$, $\displaystyle \sum\nolimits_i a_i$, $\displaystyle \sum a_i$;<br>đặt $P(i)$ là một mệnh đề liên quan đến $i$, có thể dùng $\displaystyle \sum_{P(i)} a_i$ để biểu thị tổng các $a_i$ ứng với mọi $i$ làm cho $P(i)$ đúng. |
| <a id="n6.8"></a>n6.8 | $\displaystyle \prod\limits_{i=1}^n a_i$ | $a_1 \cdot a_2 \cdot \dots \cdot a_n$ | Cũng có thể dùng $\displaystyle \prod\nolimits_{i=1}^n a_i$, $\displaystyle \prod\limits_i a_i$, $\displaystyle \prod\nolimits_i a_i$, $\displaystyle \prod a_i$;<br>đặt $P(i)$ là một mệnh đề liên quan đến $i$, có thể dùng $\displaystyle \prod_{P(i)} a_i$ để biểu thị tích các $a_i$ ứng với mọi $i$ làm cho $P(i)$ đúng;<br>một cách dùng khác của ký hiệu này xem tại [n2.17](#n2.17). |
| <a id="n6.9"></a>n6.9 | $a^p$ | Lũy thừa bậc $p$ của $a$ | |
| <a id="n6.10"></a>n6.10 | $a^{1/2}$;<br>$\sqrt{a}$ | Lũy thừa bậc $1/2$ của $a$, căn bậc hai của $a$ | Nên tránh dùng $\sqrt{}a$. |
| <a id="n6.11"></a>n6.11 | $a^{1/n}$;<br>$\sqrt[n]{a}$ | Lũy thừa bậc $1/n$ của $a$, căn bậc $n$ của $a$ | Nên tránh dùng $\sqrt[n]{}a$. |
| <a id="n6.12"></a>n6.12 | $\bar{x}$;<br>$\bar{x}_a$ | Trung bình cộng của $x$ | Các loại trung bình khác gồm:<br>trung bình điều hòa $\bar{x}_h$;<br>trung bình nhân $\bar{x}_g$;<br>trung bình bình phương/căn trung bình bình phương $\bar{x}_q$ hoặc $\bar{x}_{rms}$.<br>$\bar{x}$ cũng được dùng để biểu thị số phức liên hợp của $x$, xem [n11.6](#n11.6). |
| <a id="n6.13"></a>n6.13 | $\operatorname{sgn} a$ | Hàm dấu của $a$ | Với số thực $a$:<br>$\operatorname{sgn} a=1\quad (a>0)$;<br>$\operatorname{sgn} a=-1\quad (a<0)$;<br>$\operatorname{sgn} 0=0$;<br>xem [n11.7](#n11.7). |
| <a id="n6.14"></a>n6.14 | $\inf M$ | Cận dưới đúng của $M$ | Cận dưới lớn nhất trong các số nhỏ hơn hoặc bằng mọi phần tử của tập không rỗng $M$. |
| <a id="n6.15"></a>n6.15 | $\sup M$ | Cận trên đúng của $M$ | Cận trên nhỏ nhất trong các số lớn hơn hoặc bằng mọi phần tử của tập không rỗng $M$. |
| <a id="n6.16"></a>n6.16 | $\lvert a\rvert$ | Giá trị tuyệt đối của $a$ | Cũng có thể dùng $\operatorname{abs} a$. |
| <a id="n6.17"></a>n6.17 | $\lfloor a\rfloor$ | Làm tròn xuống<br>số nguyên lớn nhất nhỏ hơn hoặc bằng số thực $a$ | Ví dụ:<br>$\lfloor 2.4\rfloor = 2$;<br>$\lfloor -2.4\rfloor = -3$. |
| <a id="n6.18"></a>n6.18 | $\lceil a\rceil$ | Làm tròn lên<br>số nguyên nhỏ nhất lớn hơn hoặc bằng số thực $a$ | Ví dụ:<br>$\lceil 2.4\rceil = 3$;<br>$\lceil -2.4\rceil = -2$. |
| <a id="n6.19"></a>n6.19 | $\min(a, b)$;<br>$\min\{a, b\}$ | Giá trị nhỏ nhất của $a$ và $b$ | Có thể mở rộng cho tập hữu hạn.<br>Để biểu thị giá trị nhỏ nhất trong tập vô hạn, nên dùng $\inf$, xem [n6.14](#n6.14). |
| <a id="n6.20"></a>n6.20 | $\max(a, b)$;<br>$\max\{a, b\}$ | Giá trị lớn nhất của $a$ và $b$ | Có thể mở rộng cho tập hữu hạn.<br>Để biểu thị giá trị lớn nhất trong tập vô hạn, nên dùng $\sup$, xem [n6.15](#n6.15). |
| <a id="n6.21"></a>n6.21 | $n \bmod m$ | Số dư của $n$ modulo $m$ | Với các số nguyên dương $n$, $m$:<br>$(\exists~q\in\mathbf{N}, r\in[0, m))~~n=qm+r$;<br>trong đó $r=n \bmod m$. |
| <a id="n6.22"></a>n6.22 | $\gcd(a, b)$;<br>$\gcd\{a, b\}$ | Ước chung lớn nhất của các số nguyên $a$ và $b$ | Có thể mở rộng cho tập hữu hạn. Khi không gây nhầm lẫn, có thể viết là $(a, b)$. |
| <a id="n6.23"></a>n6.23 | $\operatorname{lcm}(a, b)$;<br>$\operatorname{lcm}\{a, b\}$ | Bội chung nhỏ nhất của các số nguyên $a$ và $b$ | Có thể mở rộng cho tập hữu hạn. Khi không gây nhầm lẫn, có thể viết là $[a, b]$;<br>$(a, b)[a, b]=\lvert ab\rvert$. |
| <a id="n6.24"></a>n6.24 | $[P]$ | Ngoặc Iverson | Nếu mệnh đề $P$ đúng thì $[P]=1$, ngược lại $[P]=0$. |
| <a id="n6.25"></a>n6.25 | $a\uparrow b$;<br>$a\uparrow^{n} b$ | Mũi tên Knuth | Với các số nguyên không âm $a,b,n$:<br>$a\uparrow^{n} b=a~\underbrace{\uparrow\dots\uparrow}_{n \text{ times}}~b$;<br>$a\uparrow^{0} b=ab$;<br>$a\uparrow^{1} b=a\uparrow b=a^b$;<br>$a\uparrow^{n} 0=1\quad(n>0)$;<br>$a\uparrow^{n}b=a\uparrow^{n-1}(a\uparrow^{n}(b-1))$. |
| <a id="n6.26"></a>n6.26 | $[x^n]f(x)$ | Hệ số của hạng tử $x^n$ trong đa thức/chuỗi lũy thừa hình thức/chuỗi Laurent hình thức $f(x)$ | Nếu $\displaystyle f(x)=\sum_{i} a_ix^i$ thì $[x^n]f(x)=a_n$;<br>có thể mở rộng cho trường hợp nhiều biến, chẳng hạn nếu $\displaystyle f(x,y)=\sum_{i,j}a_{i,j}x^iy^j$ thì $[x^ny^m]f(x,y)=a_{n,m}$. |

## Tổ hợp

Trong mục này, $n$ và $k$ là số tự nhiên, $a$ là số phức, và $k\leq n$.

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n7.1"></a>n7.1 | $n!$ | Giai thừa | $n!=\prod_{k=1}^n k=1\cdot 2\cdot 3\cdot \dots \cdot n\quad (n>0)$;<br>$0!=1$. |
| <a id="n7.2"></a>n7.2 | $a^{\underline{k}}$;<br>$(a)_{-k}$ | Giai thừa giảm | $a^{\underline{k}}=a\cdot(a-1)\cdot \dots \cdot(a-k+1)\quad (k>0)$;<br>$a^{\underline{0}}=1$;<br>$n^{\underline{k}}=\dfrac{n!}{(n-k)!}$. |
| <a id="n7.3"></a>n7.3 | $a^{\overline{k}}$;<br>$(a)_{+k}$ | Giai thừa tăng | $a^{\overline{k}}=a\cdot(a+1)\cdot \dots \cdot(a+k-1)\quad (k>0)$;<br>$a^{\overline{0}}=1$;<br>$n^{\overline{k}}=\dfrac{(n+k-1)!}{(n-1)!}$. |
| <a id="n7.4"></a>n7.4 | $\dbinom{n}{k}$ | Số tổ hợp | $\dbinom{n}{k}=\dfrac{n!}{k!(n-k)!}$. |
| <a id="n7.5"></a>n7.5 | $\displaystyle{n\brack k}$ | Số Stirling loại một | $\displaystyle{n+1\brack k}=n{n\brack k}+{n\brack k-1}$;<br>$\displaystyle x^{\overline{n}}=\sum_{k=0}^n{n\brack k}x^k$. |
| <a id="n7.6"></a>n7.6 | $\displaystyle{n\brace k}$ | Số Stirling loại hai | $\displaystyle{n\brace k}=\frac{1}{k!}\sum_{i=0}^k(-1)^i\binom{k}{i}(k-i)^n$;<br>$\displaystyle\sum_{k=0}^n{n\brace k}x^{\underline{k}}=x^n$. |

## Hàm

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n8.1"></a>n8.1 | $f$ | Hàm | |
| <a id="n8.2"></a>n8.2 | $f(x)$, $f(x_1, \dots, x_n)$ | Giá trị của hàm $f$ tại $x$<br>giá trị của hàm $f$ tại $(x_1, \dots, x_n)$ | |
| <a id="n8.3"></a>n8.3 | $\operatorname{dom} f$ | Tập xác định của $f$ | Cũng có thể dùng $\mathrm{D}(f)$. |
| <a id="n8.4"></a>n8.4 | $\operatorname{ran} f$ | Tập giá trị của $f$ | Cũng có thể dùng $\mathrm{R}(f)$. |
| <a id="n8.5"></a>n8.5 | $f:A\to B$ | $f$ là ánh xạ từ $A$ tới $B$ | $\operatorname{dom} f=A$ và $(\forall~x \in\operatorname{dom} f)~~ f(x) \in B$. |
| <a id="n8.6"></a>n8.6 | $x\mapsto T(x), x\in A$ | Hàm ánh xạ mọi $x\in A$ tới $T(x)$ | $T(x)$ chỉ được dùng trong định nghĩa, để biểu thị một giá trị hàm nào đó có tham số là $x\in A$. Nếu hàm này là $f$, thì với mọi $x\in A$ đều có $f(x)=T(x)$. Do đó $T(x)$ thường được dùng để định nghĩa hàm $f$.<br>Ví dụ:<br>$x\mapsto 3x^2y, x\in[0, 2]$;<br>đây là một hàm bậc hai theo $x$ được định nghĩa bởi $3x^2y$. Nếu chưa đưa vào ký hiệu hàm, dùng $3x^2y$ để biểu thị hàm đó. |
| <a id="n8.7"></a>n8.7 | $f^{-1}$ | Hàm ngược của $f$ | Hàm ngược $f^{-1}$ của hàm $f$ được định nghĩa khi và chỉ khi $f$ là đơn ánh.<br>Nếu $f$ là đơn ánh, thì $\operatorname{dom}\left(f^{-1}\right) = \operatorname{ran} f$, $\operatorname{ran}\left(f^{-1}\right) = \operatorname{dom} f$, và $(\forall~x\in\operatorname{dom} f)~~f^{-1}(f(x)) = x$.<br>Đừng nhầm với nghịch đảo của giá trị hàm $f(x)^{-1}$. |
| <a id="n8.8"></a>n8.8 | $g\circ f$ | Hàm hợp của $f$ và $g$ | $(g\circ f)(x)=g(f(x))$. |
| <a id="n8.9"></a>n8.9 | $f:x\mapsto y$ | $f(x)=y$, $f$ ánh xạ $x$ tới $y$ | |
| <a id="n8.10"></a>n8.10 | $f\vert_a^b$;<br>$f(\dots, u, \dots)\vert_{u=a}^{u=b}$ | $f(b)-f(a)$;<br>$f(\dots, b, \dots)-f(\dots, a, \dots)$ | Chủ yếu dùng trong tính tích phân xác định. |
| <a id="n8.11"></a>n8.11 | $\displaystyle \lim\limits_{x\to a}f(x)$;<br>$\lim\nolimits_{x\to a}f(x)$ | Giới hạn của $f(x)$ khi $x$ tiến tới $a$ | $\lim\nolimits_{x\to a}f(x)=b$ có thể viết thành $f(x)\to b\quad (x \to a)$.<br>Ký hiệu của giới hạn phải và giới hạn trái lần lượt là $\lim\nolimits_{x\to a+}f(x)$ và<br>$\lim\nolimits_{x\to a-}f(x)$. |
| <a id="n8.12"></a>n8.12 | $f(x) = O(g(x))$ | $\lvert f(x)/g(x)\rvert$ bị chặn trên trong giới hạn ngầm định bởi ngữ cảnh; bậc của $f(x)$ không cao hơn $g(x)$ | Khi cả $f/g$ và $g/f$ đều bị chặn, gọi $f$ và $g$ là cùng bậc.<br>Việc dùng ký hiệu "$=$" là do lý do lịch sử; trong ngữ cảnh này nó không biểu thị quan hệ tương đương, vì không thỏa tính bắc cầu.<br>Ví dụ:<br>$\sin x=O(x)\quad (x\to 0)$. |
| <a id="n8.13"></a>n8.13 | $f(x) = o(g(x))$ | Trong giới hạn ngầm định bởi ngữ cảnh có $f(x)/g(x)\to 0$; bậc của $f(x)$ cao hơn $g(x)$ | Việc dùng ký hiệu "$=$" là do lý do lịch sử; trong ngữ cảnh này nó không biểu thị quan hệ tương đương, vì không thỏa tính bắc cầu.<br>Ví dụ:<br>$\cos x=1+o(x)\quad (x\to 0)$. |
| <a id="n8.14"></a>n8.14 | $\Delta f$ | Lượng tăng hữu hạn của $f$ | Hiệu của hai giá trị hàm được ngầm định bởi ngữ cảnh. Ví dụ:<br>$\Delta x=x_2-x_1$;<br>$\Delta f(x)=f(x_2)-f(x_1)$. |
| <a id="n8.15"></a>n8.15 | $\dfrac{\mathrm{d}f}{\mathrm{d}x}$;<br>$f'$ | Đạo hàm của $f$ theo $x$ | Chỉ dùng cho hàm một biến.<br>Có thể chỉ rõ biến độc lập, như $\dfrac{\mathrm{d}f(x)}{\mathrm{d}x}$, $f'(x)$. |
| <a id="n8.16"></a>n8.16 | $\left(\dfrac{\mathrm{d}f}{\mathrm{d}x}\right)_{x=a}$;<br>$f'(a)$ | Giá trị đạo hàm của $f$ tại $a$ | Xem [n8.15](#n8.15). |
| <a id="n8.17"></a>n8.17 | $\dfrac{\mathrm{d}^n f}{\mathrm{d}x^n}$;<br>$f^{(n)}$ | Đạo hàm bậc $n$ của $f$ theo $x$ | Chỉ dùng cho hàm một biến.<br>Có thể chỉ rõ biến độc lập, như $\dfrac{\mathrm{d}^n f(x)}{\mathrm{d}x^n}$, $f^{(n)}(x)$.<br>Có thể dùng $f''$ và $f'''$ để lần lượt biểu thị $f^{(2)}$ và $f^{(3)}$. |
| <a id="n8.18"></a>n8.18 | $\dfrac{\partial f}{\partial x}$;<br>$f_x$ | Đạo hàm riêng của $f$ theo $x$ | Chỉ dùng cho hàm nhiều biến.<br>Có thể chỉ rõ biến độc lập, như $\dfrac{\partial f(x, y, \dots)}{\partial x}$, $f_x(x, y, \dots)$.<br>Có thể mở rộng tới bậc cao, như $f_{xx}=\dfrac{\partial^2 f}{\partial x^2}=\dfrac{\partial}{\partial x}\left(\dfrac{\partial f}{\partial x}\right)$;<br>$f_{xy}=\dfrac{\partial^2 f}{\partial y\partial x}=\dfrac{\partial}{\partial y}\left(\dfrac{\partial f}{\partial x}\right)$. |
| <a id="n8.19"></a>n8.19 | $\dfrac{\partial(f_1, \dots, f_m)}{\partial(x_1, \dots, x_n)}$ | Ma trận Jacobi | *Xem*[^n8.19-ref1] |
| <a id="n8.20"></a>n8.20 | $\mathrm{d}f$ | Vi phân toàn phần của $f$ | $\mathrm{d}f(x, y, \dots)=\dfrac{\partial f}{\partial x}\mathrm{d}x+\dfrac{\partial f}{\partial y}\mathrm{d}y+\dots$. |
| <a id="n8.21"></a>n8.21 | $\delta f$ | Biến phân (vô cùng nhỏ) của $f$ | |
| <a id="n8.22"></a>n8.22 | $\displaystyle \int f(x)\mathrm{d}x$ | Tích phân bất định của $f$ | |
| <a id="n8.23"></a>n8.23 | $\displaystyle \int\limits_a^b f(x)\mathrm{d}x$ | Tích phân xác định của $f$ từ $a$ đến $b$ | Cũng có thể dùng $\displaystyle \int\nolimits_a^b f(x)\mathrm{d}x$;<br>tích phân xác định còn có thể được định nghĩa trên miền tổng quát hơn. Ví dụ $\displaystyle\int\limits_C$, $\displaystyle\int\limits_S$, $\displaystyle\int\limits_V$, $\displaystyle\oint$ lần lượt biểu thị tích phân xác định trên đường cong $C$, mặt $S$, miền ba chiều $V$, và đường cong hoặc mặt kín.<br>Tích phân bội có thể viết là $\displaystyle\iint$, $\displaystyle\iiint$, v.v. |
| <a id="n8.24"></a>n8.24 | $f*g$ | Tích chập của các hàm $f$ và $g$ | $\displaystyle (f*g)(x)=\int\limits_{-\infty}^{\infty}f(y)g(x-y)\mathrm{d}y$. |

[^n8.19-ref1]: $\dfrac{\partial(f_1, \dots, f_m)}{\partial(x_1, \dots, x_n)}=\begin{pmatrix}\dfrac{\partial f_1}{\partial x_1}&\cdots&\dfrac{\partial f_1}{\partial x_n}\\\vdots&\ddots&\vdots\\\dfrac{\partial f_m}{\partial x_1}&\cdots&\dfrac{\partial f_m}{\partial x_n}\end{pmatrix}$; định nghĩa của ma trận xem tại [n12.1](#n12.1).

## Hàm mũ và hàm logarit

$x$ có thể là số phức.

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n9.1"></a>n9.1 | $\mathrm{e}$ | Cơ số của logarit tự nhiên | $\displaystyle \mathrm{e}=\lim\limits_{n\to\infty}\left(1+\frac{1}{n}\right)^n=2.718~281~8\dots$;<br>đừng viết thành $e$. |
| <a id="n9.2"></a>n9.2 | $a^x$ | Hàm mũ của $x$ (cơ số $a$) | Xem [n6.9](#n6.9). |
| <a id="n9.3"></a>n9.3 | $\mathrm{e}^x$;<br>$\exp x$ | Hàm mũ của $x$ (cơ số $\mathrm{e}$) | |
| <a id="n9.4"></a>n9.4 | $\log_a x$ | Logarit cơ số $a$ của $x$ | Khi không cần chỉ định cơ số, có thể dùng $\log x$.<br>Không nên dùng $\log x$ để thay thế bất kỳ ký hiệu nào trong $\ln x$, $\lg x$, $\operatorname{lb} x$. |
| <a id="n9.5"></a>n9.5 | $\ln x$ | Logarit tự nhiên của $x$ | $\ln x = \log_{\mathrm{e}} x$;<br>xem [n9.4](#n9.4). |
| <a id="n9.6"></a>n9.6 | $\lg x$ | Logarit thập phân của $x$ | $\lg x = \log_{10} x$;<br>xem [n9.4](#n9.4). |
| <a id="n9.7"></a>n9.7 | $\operatorname{lb} x$ | Logarit cơ số $2$ của $x$ | $\operatorname{lb} x = \log_2 x$;<br>xem [n9.4](#n9.4). |

## Hàm lượng giác và hàm hyperbol

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n10.1"></a>n10.1 | $\pi$ | Số pi | $\pi = 3.141~592~6\dots$. |
| <a id="n10.2"></a>n10.2 | $\sin x$ | Sin của $x$ | $\sin x=\dfrac{\mathrm{e}^{\mathrm{i}x}-\mathrm{e}^{-\mathrm{i}x}}{2\mathrm{i}}$;<br>$(\sin x)^n$, $(\cos x)^n$ ($n\geq 2$) thường được viết là $\sin^n x$, $\cos^n x$, v.v. |
| <a id="n10.3"></a>n10.3 | $\cos x$ | Cos của $x$ | $\cos x = \sin(x + \pi/2)$. |
| <a id="n10.4"></a>n10.4 | $\tan x$ | Tang của $x$ | $\tan x = \sin x/\cos x$;<br>không được dùng $\operatorname{tg} x$. |
| <a id="n10.5"></a>n10.5 | $\cot x$ | Cotang của $x$ | $\cot x = 1/\tan x$;<br>không được dùng $\operatorname{ctg} x$. |
| <a id="n10.6"></a>n10.6 | $\sec x$ | Sec của $x$ | $\sec x = 1/\cos x$. |
| <a id="n10.7"></a>n10.7 | $\csc x$ | Cosec của $x$ | $\csc x = 1/\sin x$;<br>không được dùng $\operatorname{cosec} x$. |
| <a id="n10.8"></a>n10.8 | $\arcsin x$ | Arcsin của $x$ | $y = \arcsin x \iff x = \sin y\quad (-\pi/2 \leq y \leq \pi/2)$. |
| <a id="n10.9"></a>n10.9 | $\arccos x$ | Arccos của $x$ | $y = \arccos x \iff x = \cos y\quad (0 \leq y \leq \pi)$. |
| <a id="n10.10"></a>n10.10 | $\arctan x$ | Arctang của $x$ | $y = \arctan x \iff x = \tan y\quad (-\pi/2 \leq y \leq \pi/2)$;<br>không được dùng $\operatorname{arctg} x$. |
| <a id="n10.11"></a>n10.11 | $\operatorname{arccot} x$ | Arccotang của $x$ | $y = \operatorname{arccot} x \iff x = \cot y\quad (0 \leq y \leq \pi)$;<br>không được dùng $\operatorname{arcctg} x$. |
| <a id="n10.12"></a>n10.12 | $\operatorname{arcsec} x$ | Arcsec của $x$ | $y = \operatorname{arcsec} x \iff x = \sec y\quad (0\leq y \leq \pi, y\ne \pi/2)$. |
| <a id="n10.13"></a>n10.13 | $\operatorname{arccsc} x$ | Arccosec của $x$ | $y = \operatorname{arccsc} x \iff x = \csc y\quad (-\pi/2 \leq y \leq \pi/2, y\ne 0)$;<br>không được dùng $\operatorname{arccosec} x$. |
| <a id="n10.14"></a>n10.14 | $\sinh x$ | Sinh hyperbol của $x$ | $\sinh x=\dfrac{\mathrm{e}^x-\mathrm{e}^{-x}}{2}$;<br>không được dùng $\operatorname{sh} x$. |
| <a id="n10.15"></a>n10.15 | $\cosh x$ | Cosh hyperbol của $x$ | $\cosh^2 x = \sinh^2 x + 1$;<br>không được dùng $\operatorname{ch} x$. |
| <a id="n10.16"></a>n10.16 | $\tanh x$ | Tanh hyperbol của $x$ | $\tanh x = \sinh x/\cosh x$;<br>không được dùng $\operatorname{th} x$. |
| <a id="n10.17"></a>n10.17 | $\coth x$ | Coth hyperbol của $x$ | $\coth x = 1/\tanh x$. |
| <a id="n10.18"></a>n10.18 | $\operatorname{sech} x$ | Sech hyperbol của $x$ | $\operatorname{sech} x = 1/\cosh x$. |
| <a id="n10.19"></a>n10.19 | $\operatorname{csch} x$ | Csch hyperbol của $x$ | $\operatorname{csch} x = 1/\sinh x$;<br>không được dùng $\operatorname{cosech} x$. |
| <a id="n10.20"></a>n10.20 | $\operatorname{arsinh} x$ | Arsinh của $x$ | $y = \operatorname{arsinh} x \iff x = \sinh y$;<br>không được dùng $\operatorname{arsh} x$. |
| <a id="n10.21"></a>n10.21 | $\operatorname{arcosh} x$ | Arcosh của $x$ | $y = \operatorname{arcosh} x \iff x = \cosh y\quad (y \geq 0)$;<br>không được dùng $\operatorname{arch} x$. |
| <a id="n10.22"></a>n10.22 | $\operatorname{artanh} x$ | Artanh của $x$ | $y = \operatorname{artanh} x \iff x = \tanh y$;<br>không được dùng $\operatorname{arth} x$. |
| <a id="n10.23"></a>n10.23 | $\operatorname{arcoth} x$ | Arcoth của $x$ | $y = \operatorname{arcoth} x \iff x = \coth y\quad (y \ne 0)$. |
| <a id="n10.24"></a>n10.24 | $\operatorname{arsech} x$ | Arsech của $x$ | $y = \operatorname{arsech} x \iff x = \operatorname{sech} y\quad (y \geq 0)$. |
| <a id="n10.25"></a>n10.25 | $\operatorname{arcsch} x$ | Arcsch của $x$ | $y = \operatorname{arcsch} x \iff x = \operatorname{csch} y\quad (y \geq 0)$;<br>không được dùng $\operatorname{arcosech} x$. |

## Số phức

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n11.1"></a>n11.1 | $\mathrm{i}$ | Đơn vị ảo | $\mathrm{i}^2 = -1$;<br>không được dùng $i$ hoặc `i`. |
| <a id="n11.2"></a>n11.2 | $\operatorname{Re} z$ | Phần thực của $z$ | Xem [n11.3](#n11.3). |
| <a id="n11.3"></a>n11.3 | $\operatorname{Im} z$ | Phần ảo của $z$ | Nếu $z = x + \mathrm{i} y\quad (x, y\in\mathbf{R})$, thì $x = \operatorname{Re} z$, $y = \operatorname{Im} z$. |
| <a id="n11.4"></a>n11.4 | $\lvert z\rvert$ | Môđun của $z$ | $\lvert z\rvert=\sqrt{(\operatorname{Re} z)^2+(\operatorname{Im} z)^2}$. |
| <a id="n11.5"></a>n11.5 | $\arg z$ | Argument của $z$ | Nếu $z = r \mathrm{e}^{\mathrm{i}\varphi}$, trong đó $r = \lvert z\rvert$ và $-\pi < \varphi \leq \pi$, thì $\varphi = \arg z$.<br>$\operatorname{Re} z = r \cos \varphi$, $\operatorname{Im} z = r \sin \varphi$. |
| <a id="n11.6"></a>n11.6 | $\bar{z}$;<br>$z^*$ | Số phức liên hợp của $z$ | $\bar{z}=\operatorname{Re}z-\mathrm{i}\operatorname{Im}z$. |
| <a id="n11.7"></a>n11.7 | $\operatorname{sgn} z$ | Hàm môđun đơn vị của $z$ | $\operatorname{sgn} z =z / \lvert z\rvert = \exp(\mathrm{i} \arg z)\quad (z \ne 0)$;<br>$\operatorname{sgn} 0 = 0$;<br>xem [n6.13](#n6.13). |

## Ma trận

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n12.1"></a>n12.1 | $A$;<br>*Xem*[^n12.1-ref1] | Ma trận $A$ cỡ $m\times n$ | $a_{ij} = (A)_{ij}$;<br>cũng có thể dùng $A = (a_{ij})$. Trong đó $m$ là số hàng, $n$ là số cột.<br>Khi $m=n$, gọi là ma trận vuông.<br>Có thể dùng ngoặc vuông thay cho ngoặc tròn. |
| <a id="n12.2"></a>n12.2 | $A + B$ | Tổng của các ma trận $A$ và $B$ | $(A + B)_{ij} = (A)_{ij} + (B)_{ij}$;<br>số hàng và số cột của các ma trận $A$ và $B$ phải lần lượt bằng nhau. |
| <a id="n12.3"></a>n12.3 | $x A$ | Tích của vô hướng $x$ và ma trận $A$ | $(x A)_{ij} = x (A)_{ij}$. |
| <a id="n12.4"></a>n12.4 | $AB$ | Tích của các ma trận $A$ và $B$ | $\displaystyle(AB)_{ik} = \sum\limits_{j}(A)_{ij}(B)_{jk}$;<br>số cột của ma trận $A$ phải bằng số hàng của ma trận $B$. |
| <a id="n12.5"></a>n12.5 | $I$;<br>$E$ | Ma trận đơn vị | $(I)_{ik} = \delta_{ik}$;<br>định nghĩa của $\delta_{ik}$ xem tại [n14.9](#n14.9). |
| <a id="n12.6"></a>n12.6 | $A^{-1}$ | Nghịch đảo của ma trận vuông $A$ | $AA^{-1} = A^{-1}A = I\quad (\det A \ne 0)$.<br>Định nghĩa của $\det A$ xem tại [n12.10](#n12.10). |
| <a id="n12.7"></a>n12.7 | $A^{\mathrm{T}}$;<br>$A'$ | Ma trận chuyển vị của $A$ | $(A^{\mathrm{T}})_{ik} = (A)_{ki}$. |
| <a id="n12.8"></a>n12.8 | $\overline{A}$;<br>$A^*$ | Ma trận liên hợp phức của $A$ | $\left(\overline{A}\right)_{ik}=\overline{(A)_{ik}}$. |
| <a id="n12.9"></a>n12.9 | $A^{\mathrm{H}}$;<br>$A^{\dagger}$ | Ma trận liên hợp Hermite của $A$ | $A^{\mathrm{H}} = \left(\overline{A}\right)^{\mathrm{T}}$. |
| <a id="n12.10"></a>n12.10 | $\det A$;<br>*Xem*[^n12.10-ref1] | Định thức của ma trận vuông $A$ | Cũng có thể dùng $\lvert A\rvert$. |
| <a id="n12.11"></a>n12.11 | $\operatorname{rank}A$ | Hạng của ma trận $A$ | |
| <a id="n12.12"></a>n12.12 | $\operatorname{tr}A$ | Vết của ma trận vuông $A$ | $\displaystyle\operatorname{tr}A=\sum\limits_{i}(A)_{ii}$. |
| <a id="n12.13"></a>n12.13 | $\lVert A\rVert$ | Chuẩn của ma trận $A$ | Thỏa bất đẳng thức tam giác: nếu $A + B = C$, thì $\lVert A\rVert+\lVert B\rVert \geq \lVert C\rVert$. |

[^n12.1-ref1]: $\begin{pmatrix}a_{11}&\cdots&a_{1n}\\\vdots&\ddots&\vdots\\a_{m1}&\cdots&a_{mn}\end{pmatrix}$

[^n12.10-ref1]: $\begin{vmatrix}a_{11}&\cdots&a_{1n}\\\vdots& &\vdots\\a_{n1}&\cdots&a_{nn}\end{vmatrix}$

## Hệ tọa độ

Mục này xét một số hệ tọa độ trong không gian ba chiều. Điểm $\mathrm{O}$ là **gốc tọa độ** của hệ tọa độ. Mọi điểm $\mathrm{P}$ đều được xác định bởi **vector vị trí** từ gốc tọa độ $\mathrm{O}$ đến điểm $\mathrm{P}$.

| Số hiệu | Tọa độ | Vector vị trí và vi phân | Tên hệ tọa độ | Ghi chú |
| ------- | ----- | ------------------------ | ------------- | ------- |
| <a id="n13.1"></a>n13.1 | $x$, $y$, $z$ | $\boldsymbol{r} = x \boldsymbol{e}_x + y \boldsymbol{e}_y + z \boldsymbol{e}_z$;<br>$\mathrm{d}\boldsymbol{r} = \mathrm{d}x~\boldsymbol{e}_x + \mathrm{d}y~\boldsymbol{e}_y + \mathrm{d}z~\boldsymbol{e}_z$ | Tọa độ Descartes | Các vector cơ sở $\boldsymbol{e}_x$, $\boldsymbol{e}_y$, $\boldsymbol{e}_z$ tạo thành một hệ trực chuẩn tay phải, xem [Hình 1](#hinh-1) và [Hình 4](#hinh-4).<br>Vector cơ sở cũng có thể dùng $\boldsymbol{e}_1$, $\boldsymbol{e}_2$, $\boldsymbol{e}_3$ hoặc $\boldsymbol{i}$, $\boldsymbol{j}$, $\boldsymbol{k}$; tọa độ cũng có thể dùng $x_1$, $x_2$, $x_3$ hoặc $i$, $j$, $k$. |
| <a id="n13.2"></a>n13.2 | $\rho$, $\varphi$, $z$ | $\boldsymbol{r} = \rho~\boldsymbol{e}_{\rho} + z~\boldsymbol{e}_z$;<br>$\mathrm{d}\boldsymbol{r} = \mathrm{d}\rho~\boldsymbol{e}_{\rho} +\rho~\mathrm{d}\varphi~\boldsymbol{e}_{\varphi} + \mathrm{d}z~\boldsymbol{e}_z$ | Tọa độ trụ | $\boldsymbol{e}_{\rho}(\varphi)$, $\boldsymbol{e}_{\varphi}(\varphi)$, $\boldsymbol{e}_z$ tạo thành một hệ trực chuẩn tay phải, xem [Hình 2](#hinh-2).<br>Nếu $z = 0$, thì $\rho$ và $\varphi$ là tọa độ cực trên mặt phẳng. |
| <a id="n13.3"></a>n13.3 | $r$, $\vartheta$, $\varphi$ | $\boldsymbol{r} = r \boldsymbol{e}_r$;<br>$\mathrm{d}\boldsymbol{r} = \mathrm{d}r~\boldsymbol{e}_r + r~\mathrm{d}\vartheta~\boldsymbol{e}_{\vartheta} + r~\sin\vartheta~\mathrm{\mathrm{d}}\varphi~\boldsymbol{e}_{\varphi}$ | Tọa độ cầu | $\boldsymbol{e}_r(\vartheta, \varphi)$, $\boldsymbol{e}_{\vartheta}(\vartheta, \varphi)$, $\boldsymbol{e}_{\varphi}(\varphi)$ tạo thành một hệ trực chuẩn tay phải, xem [Hình 3](#hinh-3). |

Nếu không dùng [hệ tọa độ tay phải](#hinh-4) mà dùng [hệ tọa độ tay trái](#hinh-5), cần nhấn mạnh rõ trước đó để tránh dùng sai ký hiệu.

![](./images/symbol-1.svg)

<a id="hinh-1"></a>**Hình 1** Hệ tọa độ Descartes tay phải

![](./images/symbol-2.svg)

<a id="hinh-2"></a>**Hình 2** Hệ tọa độ trụ tay phải

![](./images/symbol-3.svg)

<a id="hinh-3"></a>**Hình 3** Hệ tọa độ cầu tay phải

![](./images/symbol-4.svg)

<a id="hinh-4"></a>**Hình 4** Hệ tọa độ tay phải

![](./images/symbol-5.svg)

<a id="hinh-5"></a>**Hình 5** Hệ tọa độ tay trái

## Vô hướng và vector

Trong mục này, vector cơ sở được ký hiệu bằng $\boldsymbol{e}_1$, $\boldsymbol{e}_2$, $\boldsymbol{e}_3$. Nhiều khái niệm trong mục này có thể được mở rộng sang không gian $n$ chiều.

Bản thân vô hướng và vector không phụ thuộc vào việc chọn hệ tọa độ, còn từng thành phần vô hướng của vector thì phụ thuộc vào việc chọn hệ tọa độ.

Với các vector cơ sở $\boldsymbol{e}_1$, $\boldsymbol{e}_2$, $\boldsymbol{e}_3$, mọi vector $\boldsymbol{a}$ đều có thể biểu diễn thành $\boldsymbol{a}=a_1\boldsymbol{e}_1+a_2\boldsymbol{e}_2+a_3\boldsymbol{e}_3$, trong đó $a_1$, $a_2$ và $a_3$ là các giá trị vô hướng được xác định duy nhất; chúng được gọi là "tọa độ" của vector theo nhóm vector cơ sở đó, còn $a_1\boldsymbol{e}_1$, $a_2\boldsymbol{e}_2$ và $a_3\boldsymbol{e}_3$ được gọi là các vector thành phần của vector theo nhóm vector cơ sở đó.

Trong mục này, chỉ xét tọa độ Descartes (trực giao) của không gian thông thường. Tọa độ Descartes được ký hiệu bằng $x$, $y$, $z$ hoặc $a_1$, $a_2$, $a_3$ hoặc $x_1$, $x_2$, $x_3$.

Trong mục này, mọi chỉ số dưới $i$, $j$, $k$ đều chạy từ $1$ đến $3$.

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n14.1"></a>n14.1 | $\boldsymbol{a}$;<br>$\vec{a}$ | Vector $\boldsymbol{a}$ | |
| <a id="n14.2"></a>n14.2 | $\boldsymbol{a} + \boldsymbol{b}$ | Tổng của các vector $\boldsymbol{a}$ và $\boldsymbol{b}$ | $(\boldsymbol{a} + \boldsymbol{b})_i = a_i + b_i$. |
| <a id="n14.3"></a>n14.3 | $x\boldsymbol{a}$ | Tích của vô hướng $x$ và vector $\boldsymbol{a}$ | $(x\boldsymbol{a})_i = xa_i$. |
| <a id="n14.4"></a>n14.4 | $\lvert \boldsymbol{a}\rvert$ | Độ lớn của vector $\boldsymbol{a}$, chuẩn của vector $\boldsymbol{a}$ | $\lvert \boldsymbol{a}\rvert=\sqrt{a_x^2+a_y^2+a_z^2}$;<br>cũng có thể dùng $\lVert a\rVert$. |
| <a id="n14.5"></a>n14.5 | $\boldsymbol{0}$;<br>$\vec{0}$ | Vector không | Độ lớn của vector không là $0$. |
| <a id="n14.6"></a>n14.6 | $\boldsymbol{e_a}$ | Vector đơn vị theo hướng $\boldsymbol{a}$ | $\boldsymbol{e_a} = \boldsymbol{a}/\lvert\boldsymbol{a}\rvert\quad (\boldsymbol{a}\ne \boldsymbol{0})$. |
| <a id="n14.7"></a>n14.7 | $\boldsymbol{e}_x$, $\boldsymbol{e}_y$, $\boldsymbol{e}_z$;<br>$\boldsymbol{e}_1$, $\boldsymbol{e}_2$, $\boldsymbol{e}_3$ | Vector đơn vị theo hướng các trục tọa độ Descartes | Cũng có thể dùng $\boldsymbol{i}$, $\boldsymbol{j}$, $\boldsymbol{k}$. |
| <a id="n14.8"></a>n14.8 | $a_x$, $a_y$, $a_z$;<br>$a_i$ | Thành phần Descartes của vector $\boldsymbol{a}$ | $\boldsymbol{a} = a_x \boldsymbol{e}_x + a_y \boldsymbol{e}_y + a_z \boldsymbol{e}_z$;<br>nếu ngữ cảnh đã xác định vector cơ sở, vector có thể viết là $\boldsymbol{a} = (a_x, a_y, a_z)$.<br>$a_x = \boldsymbol{a}\cdot \boldsymbol{e}_x$, $a_y = \boldsymbol{a}\cdot \boldsymbol{e}_y$, $a_z = \boldsymbol{a}\cdot \boldsymbol{e}_z$;<br>$\boldsymbol{r} = x\boldsymbol{e}_x + y\boldsymbol{e}_y + z\boldsymbol{e}_z$ là vector vị trí có tọa độ $x$, $y$, $z$. |
| <a id="n14.9"></a>n14.9 | $\delta_{ik}$ | Ký hiệu delta Kronecker | $\delta_{ik}=[i=k]$, trong đó định nghĩa của $[\cdot]$ xem tại [n6.24](#n6.24), tức là:<br>$\delta_{ik}=1\quad (i=k)$;<br>$\delta_{ik}=0\quad (i\ne k)$. |
| <a id="n14.10"></a>n14.10 | $\varepsilon_{ijk}$ | Ký hiệu Levi-Civita | $\varepsilon_{123} = \varepsilon_{231} = \varepsilon_{312} = 1$;<br>$\varepsilon_{132} = \varepsilon_{321} = \varepsilon_{213} = -1$;<br>các $\varepsilon_{ijk}$ còn lại đều bằng $0$. |
| <a id="n14.11"></a>n14.11 | $\boldsymbol{a}\cdot\boldsymbol{b}$ | Tích vô hướng/tích trong của các vector $\boldsymbol{a}$ và $\boldsymbol{b}$ | $\displaystyle\boldsymbol{a}\cdot\boldsymbol{b}=\sum\limits_i a_ib_i$. |
| <a id="n14.12"></a>n14.12 | $\boldsymbol{a}\times\boldsymbol{b}$ | Tích có hướng/tích vector của các vector $\boldsymbol{a}$ và $\boldsymbol{b}$ | Trong hệ tọa độ Descartes tay phải, $\displaystyle (\boldsymbol{a}\times\boldsymbol{b})_i = \sum\limits_j\sum\limits_k\varepsilon_{ijk}a_jb_k$;<br>định nghĩa của $\varepsilon_{ijk}$ xem tại [n14.10](#n14.10). |
| <a id="n14.13"></a>n14.13 | $\mathbf{\nabla}$ | Toán tử nabla | $\displaystyle \mathbf{\nabla} = \boldsymbol{e}_x\frac{\partial}{\partial x}+\boldsymbol{e}_y\frac{\partial}{\partial y}+\boldsymbol{e}_z\frac{\partial}{\partial z}=\sum\limits_i\boldsymbol{e}_i\frac{\partial}{\partial x_i}$. |
| <a id="n14.14"></a>n14.14 | $\mathbf{\nabla}\varphi$;<br>$\operatorname{\mathbf{grad}}\varphi$ | Gradient của $\varphi$ | $\displaystyle \mathbf{\nabla}\varphi=\sum\limits_i\boldsymbol{e}_i\frac{\partial\varphi}{\partial x_i}$;<br>$\operatorname{\mathbf{grad}}$ nên dùng `\operatorname{\mathbf{grad}}`. |
| <a id="n14.15"></a>n14.15 | $\mathbf{\nabla}\cdot\boldsymbol{a}$;<br>$\operatorname{\mathbf{div}}\boldsymbol{a}$ | Divergence của $\boldsymbol{a}$ | $\displaystyle \mathbf{\nabla}\cdot\boldsymbol{a}=\sum\limits_i\frac{\partial a_i}{\partial x_i}$;<br>$\operatorname{\mathbf{div}}$ nên dùng `\operatorname{\mathbf{div}}`. |
| <a id="n14.16"></a>n14.16 | $\mathbf{\nabla}\times\boldsymbol{a}$;<br>$\operatorname{\mathbf{rot}}\boldsymbol{a}$ | Curl của $\boldsymbol{a}$ | $\displaystyle (\mathbf{\nabla}\times\boldsymbol{a})_i=\sum\limits_j\sum\limits_k\varepsilon_{ijk}\frac{\partial a_k}{\partial x_j}$;<br>$\operatorname{\mathbf{rot}}$ nên dùng `\operatorname{\mathbf{rot}}`.<br>Không nên dùng $\operatorname{\mathbf{curl}}$.<br>Định nghĩa của $\varepsilon_{ijk}$ xem tại [n14.10](#n14.10). |
| <a id="n14.17"></a>n14.17 | $\mathbf{\nabla}^2$;<br>$\Delta$ | Toán tử Laplace | $\mathbf{\nabla}^2=\dfrac{\partial^2}{\partial x^2}+\dfrac{\partial^2}{\partial y^2}+\dfrac{\partial^2}{\partial z^2}$. |

## Hàm đặc biệt

Trong mục này, $z$, $w$ là số phức, $k$, $n$ là số tự nhiên, và $k\leq n$.

| Số hiệu | Ký hiệu, biểu thức | Ý nghĩa, cách diễn đạt tương đương | Ghi chú và ví dụ |
| ------- | ----------------- | ---------------------------------- | ---------------- |
| <a id="n15.1"></a>n15.1 | $\gamma$ | Hằng số Euler-Mascheroni | $\displaystyle \gamma=\lim\limits_{n\to\infty}\left(\sum\limits_{k=1}^n\frac{1}{k}-\ln n\right)= 0.577~215~6 \dots$. |
| <a id="n15.2"></a>n15.2 | $\Gamma(z)$ | Hàm gamma | $\displaystyle\Gamma(z)=\int\limits_0^{\infty}t^{z-1}\mathrm{e}^{-t}\mathrm{d}t\quad (\operatorname{Re}z>0)$;<br>$\Gamma(n+1)=n!$. |
| <a id="n15.3"></a>n15.3 | $\zeta(z)$ | Hàm zeta Riemann | $\displaystyle\zeta(z)=\sum\limits_{n=1}^{\infty}\frac{1}{n^z}\quad (\operatorname{Re}z>1)$. |
| <a id="n15.4"></a>n15.4 | $\operatorname{B}(z, w)$ | Hàm beta | $\displaystyle\operatorname{B}(z, w)=\int\limits_0^1 t^{z-1}(1-t)^{w-1}\mathrm{d}t\quad (\operatorname{Re} z>0$, $\operatorname{Re} w>0)$;<br>$\operatorname{B}(z, w)=\dfrac{\Gamma(z)\Gamma(w)}{\Gamma(z+w)}$;<br>$\dfrac{1}{(n+1)\operatorname{B}(k+1, n-k+1)}=\dbinom{n}{k}$. |
