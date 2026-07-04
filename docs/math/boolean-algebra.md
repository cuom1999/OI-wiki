Trong logic toán học, đại số Boolean (boolean algebra) là một nhánh của đại số. Trong đại số sơ cấp, giá trị của biến là các số, và các phép toán chủ yếu được nghiên cứu gồm cộng, nhân, lũy thừa cùng các phép toán ngược của ba phép đó. Trong đại số Boolean, giá trị của biến chỉ có hai khả năng **đúng** và **sai** (thường ký hiệu là $1$ và $0$), và các phép toán chủ yếu được nghiên cứu gồm hội (AND, $\land$), tuyển (OR, $\lor$), phủ định (NOT, $\lnot$). Giống như đại số sơ cấp là một hình thức mô tả phép toán trên số, đại số Boolean là một hình thức mô tả phép toán logic.

<span id="&#x5E03;&#x5C14;&#x51FD;&#x6570;"></span>
## Hàm Boolean

???+ abstract "Định nghĩa"
    **Hàm Boolean** (boolean function) là hàm có dạng $f:\mathbf{B}^k\to \mathbf{B}$, trong đó $\mathbf{B}=\{0,1\}$ là **miền Boolean** (boolean domain), và số nguyên không âm $k$ là **số ngôi** (arity) của hàm Boolean này. Hàm Boolean với $k=1$ là hàm một ngôi, và tương tự cho các trường hợp khác. Khi $k=0$, ta xem hàm suy biến thành một hằng trong $\mathbf{B}$.

Thông thường ta chỉ nghiên cứu các hàm Boolean một ngôi và hai ngôi. Nếu không nói rõ thêm, các hàm Boolean dưới đây chỉ xét trong hai trường hợp một ngôi và hai ngôi.

Ngoài cách biểu diễn hàm thông thường, ta còn có thể dùng **bảng chân trị** (truth table), **cổng logic** (logic gate), hoặc [biểu đồ Venn](https://en.wikipedia.org/wiki/Venn_diagram) để biểu diễn hàm Boolean.

???+ abstract "Bảng chân trị"
    Với một hàm Boolean, ta liệt kê tất cả các trường hợp đầu vào của nó, rồi lập thành một bảng gồm đầu vào và đầu ra tương ứng. Bảng đó được gọi là bảng chân trị.

Hàm Boolean $n$ ngôi cũng có thể được biểu diễn bằng **công thức mệnh đề** (propositional formula) gồm $n$ biến. Hai công thức mệnh đề $p$ và $q$ **tương đương logic** (logically equivalent) khi và chỉ khi chúng mô tả cùng một hàm Boolean, ký hiệu là $p\iff q$.

Sau đây là một số hàm Boolean thường gặp; ta cũng gọi chung các hàm Boolean này là **liên từ logic** (logical connective) hoặc **toán tử logic** (logical operator):

| Tên (logic toán học)                                      | Tên khác                               | Ký hiệu                          |
| --------------------------------------------------------- | -------------------------------------- | -------------------------------- |
| Đúng hằng (truth, tautology)                              |                                        | $\top$                           |
| Sai hằng (falsity, contradiction)                         |                                        | $\bot$                           |
| Mệnh đề                                                   | Chính nó                               | $A$                              |
| Phủ định (negation)                                       | NOT                                    | $\lnot A$                        |
| Hội (conjunction)                                         | AND                                    | $A \land B$                      |
| Tuyển (disjunction)                                       | OR                                     | $A \lor B$                       |
| Không hội (non-conjunction)                               | NAND, vạch dọc Sheffer                 | $A \bar{\land} B$, $A\uparrow B$  |
| Không tuyển (non-disjunction)                             | NOR                                    | $A \bar{\lor} B$, $A\downarrow B$ |
|                                                           | XOR (Exclusive-OR)                     | $A \oplus B$                     |
|                                                           | XNOR (Exclusive-NOR)                   | $A \odot B$                      |
| Kéo theo vật chất (material implication)[^note1]          |                                        | $A \to B$                        |
| Không kéo theo vật chất (material nonimplication)[^note1] |                                        | $A \nrightarrow B$               |
| Kéo theo đảo (converse implication)[^note1]               |                                        | $A \gets B$                      |
| Không kéo theo đảo (converse nonimplication)[^note1]      |                                        | $A \nleftarrow B$                |
| Song điều kiện (biconditional), tương đương (equivalence)[^note1][^note2] |                    | $A \leftrightarrow B$            |
| Không tương đương (non-equivalence)[^note1][^note3]       |                                        | $A \nleftrightarrow B$           |

Bảng chân trị tương ứng (From [Wikipedia](https://commons.wikimedia.org/wiki/File:Logical_connectives_table.svg)):

![](./images/logical-connectives-table.svg)

Biểu đồ Venn và [biểu đồ Hasse](./order-theory.md#%E5%81%8F%E5%BA%8F%E9%9B%86%E7%9A%84%E5%8F%AF%E8%A7%86%E5%8C%96%E8%A1%A8%E7%A4%BAhasse-%E5%9B%BE) tương ứng (lấy quan hệ bao hàm tập hợp $\subseteq$ làm thứ tự riêng phần, From [Wikipedia](https://en.wikipedia.org/wiki/File:Logical_connectives_Hasse_diagram.svg)):

![](./images/logical-connectives-hasse-diagram.svg)

Vì đầu vào của hàm Boolean $n$ ngôi có $2^n$ trường hợp, nên có $2\uparrow (2\uparrow n)$ hàm Boolean $n$ ngôi, trong đó $\uparrow$ là mũi tên Knuth.

Ta gọi tổ hợp các toán tử logic là **biểu thức logic** (logical expression).

Nếu xem $\mathbf{B}$ như một [lớp thặng dư](./number-theory/basic.md#%E5%90%8C%E4%BD%99%E7%B1%BB%E4%B8%8E%E5%89%A9%E4%BD%99%E7%B3%BB) modulo $2$, thì XOR tương đương với phép cộng modulo $2$, còn AND tương đương với phép nhân modulo $2$. Vì vậy đôi khi ta cũng dùng $\mathbf{Z}_2$ để biểu thị miền Boolean.

<span id="&#x4F18;&#x5148;&#x7EA7;"></span>
### Thứ tự ưu tiên

Toán tử logic một ngôi có thứ tự ưu tiên cao hơn toán tử logic hai ngôi; tức là $\lnot$ có thứ tự ưu tiên cao hơn $\land$, $\lor$, $\oplus$, v.v.

Có nhiều quy ước khác nhau về thứ tự ưu tiên giữa các toán tử logic hai ngôi. Một số tài liệu xem $\land$, $\lor$, $\oplus$ có thứ tự ưu tiên cao hơn $\to$, $\gets$, $\leftrightarrow$, trong khi một số tài liệu khác lại quy ước ngược lại. Do đó khi sử dụng, nên thêm ngoặc để làm rõ thứ tự thực hiện.

Quy ước trong C++ xem tại [bảng tổng hợp thứ tự ưu tiên toán tử C++](../lang/op.md#c-%E8%BF%90%E7%AE%97%E7%AC%A6%E4%BC%98%E5%85%88%E7%BA%A7%E6%80%BB%E8%A1%A8).

<span id="&#x81EA;&#x8DB3;&#x7B97;&#x5B50;&#x4E0E;&#x5B8C;&#x5907;&#x7B97;&#x5B50;&#x96C6;"></span>
### Toán tử tự túc và tập toán tử đầy đủ

Thực ra, chỉ cần NAND hoặc NOR là có thể biểu diễn các toán tử logic còn lại; CPU cũng được xây dựng dựa trên điểm này. Tuy nhiên, do bốn toán tử logic **AND, OR, NOT, XOR** có tính chất tốt hơn, nên khi nghiên cứu đại số Boolean ta thường chỉ dùng bốn hàm này.

??? example "Cách dùng riêng NAND và NOR để biểu diễn các toán tử logic còn lại"
    Ta có
    
    -   $\lnot p=p\bar{\land} p=p\bar{\lor} p$,
    -   $p\land q=(p\bar{\land}q)\bar{\land}(p\bar{\land}q)=(p\bar{\lor}p)\bar{\lor}(q\bar{\lor}q)$,
    -   $p\lor q=(p\bar{\land}p)\bar{\land}(q\bar{\land}q)=(p\bar{\lor}q)\bar{\lor}(p\bar{\lor}q)$,
    -   $p\to q=p\bar{\land} (q\bar{\land} q)=((p\bar{\lor}p)\bar{\lor}q)\bar{\lor}((p\bar{\lor}p)\bar{\lor}q)$.
    
    Ngoài ra,
    
    -   $p=\lnot\lnot p$,
    -   $p\nleftrightarrow q=p\oplus q=(p\lor q)\land\lnot (p\land q)$,
    -   $p\leftrightarrow q=p\odot q=\lnot(p\oplus q)$,
    -   $p\nrightarrow q=\lnot(p\to q)$,
    -   $p\gets q=q\to p$,
    -   $p\nleftarrow q=\lnot(p\gets q)$.

Liệu ta có thể dùng một số toán tử logic được chỉ định để mô tả tất cả các toán tử logic hay không? Câu hỏi này dẫn đến định nghĩa tập toán tử đầy đủ.

???+ abstract "Định nghĩa"
    Với một tập toán tử logic cho trước, nếu chỉ dùng các hàm trong tập đó mà có thể mô tả tất cả các toán tử logic, thì tập đó được gọi là **tập toán tử đầy đủ** (functionally complete operator set). Đặc biệt, nếu chỉ cần một toán tử logic để mô tả tất cả các toán tử logic, thì toán tử đó được gọi là **toán tử tự túc** (sole sufficient operator) hoặc **hàm Sheffer** (Sheffer function).
    
    Nếu xóa bất kỳ một phần tử nào khỏi một tập toán tử đầy đủ thì tập con thu được không còn mô tả được tất cả các toán tử logic, ta gọi tập ban đầu là **tập toán tử đầy đủ cực tiểu** (minimal functionally complete operator set).

Có thể chứng minh rằng trong các toán tử logic, chỉ có $\bar{\land}$ và $\bar{\lor}$ là toán tử tự túc.

Sau đây là các tập toán tử đầy đủ cực tiểu thường gặp[^vaughan1942complete]:

-   $\{\bar{\land}\}$, $\{\bar{\lor}\}$,
-   $\{\land,\lnot\}$, $\{\lor,\lnot\}$, $\{\gets,\lnot\}$, $\{\to,\lnot\}$, $\{\nleftarrow,\lnot\}$, $\{\nrightarrow,\lnot\}$,
-   $\{\gets,\bot\}$, $\{\to,\bot\}$, $\{\nleftarrow,\top\}$, $\{\nrightarrow,\top\}$,
-   $\{\gets,\nleftarrow\}$, $\{\to,\nleftarrow\}$, $\{\gets,\nrightarrow\}$, $\{\to,\nrightarrow\}$,
-   $\{\gets,\nleftrightarrow\}$, $\{\to,\nleftrightarrow\}$, $\{\nleftarrow,\leftrightarrow\}$, $\{\nrightarrow,\leftrightarrow\}$,
-   $\{\lor,\leftrightarrow,\bot\}$, $\{\lor,\leftrightarrow,\nleftrightarrow\}$, $\{\lor,\nleftrightarrow,\top\}$,
-   $\{\land,\leftrightarrow,\bot\}$, $\{\land,\leftrightarrow,\nleftrightarrow\}$, $\{\land,\nleftrightarrow,\top\}$.

<span id="&#x6027;&#x8D28;"></span>
### Tính chất

Trước hết là các tính chất liên quan đến cấu trúc đại số:

-   AND và OR đều lập thành [vị nhóm giao hoán](./algebra/basic.md#%E7%BE%A4) trên $\mathbf{B}$. Tức là phép AND và phép OR đều có tính giao hoán, tính kết hợp và phần tử đơn vị ($x\land 1=x\lor 0=x$).
-   XOR và XNOR đều lập thành [nhóm](./algebra/basic.md#%E7%BE%A4) trên $\mathbf{B}$. Tức là phép XOR và phép XNOR đều có tính giao hoán, tính kết hợp, phần tử đơn vị ($x\oplus 0=x\odot 1=x$) và phần tử nghịch đảo ($x\oplus x=0$, $x\odot x=1$).
-   NAND và NOR đều không có tính kết hợp, nên không lập thành nửa nhóm.

Với $\land$ và $\lor$, ta có:

-   Luật phân phối:
    -   $a\land(b\diamond c)=(a\land b)\diamond (a\land c)$, trong đó $\diamond$ có thể là $\land$, $\lor$, $\oplus$,
    -   $a\lor(b\diamond c)=(a\lor b)\diamond (a\lor c)$, trong đó $\diamond$ có thể là $\land$, $\lor$, $\odot$.
-   Luật **lũy đẳng** (idempotence): $x\land x=x$, $x\lor x=x$.
-   Tính đơn điệu: $a\to b\iff(a\land c)\to(b\land c)$, $a\to b\iff(a\lor c)\to(b\lor c)$.
-   Luật **hấp thụ** (absorption): $x\land(x\lor y)=x\lor(x\land y)=x$.
-   Quan hệ với "$\to$":
    -   $a \lor b \iff (\lnot a \to b) \land (\lnot b \to a)$,
    -   $a \land b \iff \lnot((a \to \lnot b) \lor (b \to \lnot a))$.

???+ abstract "Tính đơn điệu của hàm Boolean"
    Với một hàm Boolean $f(x_1,\dots,x_n)$ và hai phần tử $(a_1,\dots,a_n),(b_1,\dots,b_n)$ trong $\mathbf{B}^n$, nếu cứ $a_i\leq b_i,~~\forall i=1,\dots,n$ thì luôn có $f(a_1,\dots,a_n)\leq f(b_1,\dots,b_n)$, ta gọi hàm Boolean đó là đơn điệu.

Ta còn có các tính chất sau:

-   **Luật loại trừ trung gian** (law of excluded middle): $p\lor\lnot p$ luôn đúng.
-   $\lnot p\iff p\to\bot$.
-   Phủ định kép / luật **đối hợp** (involution) của $\lnot$: $\lnot\lnot x=x$.
-   Luật đối hợp của $\oplus$ và $\odot$: $x\oplus y\oplus y=x$, $x\odot y\odot y=x$.
-   Luật De Morgan: $\lnot(p\land q)=\lnot p\lor \lnot q$, $\lnot(p\lor q)=\lnot p\land \lnot q$.

<span id="&#x903B;&#x8F91;&#x8868;&#x8FBE;&#x5F0F;&#x7684;&#x6807;&#x51C6;&#x5316;"></span>
## Chuẩn hóa biểu thức logic

Theo các tính chất trên, ta có thể thực hiện một số phép biến đổi tương đương trên biểu thức logic để đưa nó về những dạng chuẩn nhất định; điều này có thể được dùng trong chứng minh định lý tự động. Các dạng chuẩn hóa thường gặp gồm **dạng chuẩn hội** (conjunctive normal form, CNF), **dạng chuẩn tuyển** (disjunctive normal form, DNF) và **dạng chuẩn đại số** (algebraic normal form, ANF).

???+ abstract "Dạng chuẩn hội và dạng chuẩn tuyển"
    Ta định nghĩa đệ quy như sau:
    
    1.  **Literal** (literal): với biến $x$, $x$ và $\lnot x$ là literal.
    2.  Mệnh đề con:
        -   Literal là mệnh đề con,
        -   Nếu $A$ là literal và $B$ là mệnh đề con, thì $A\lor B$ là mệnh đề con.
    3.  Dạng chuẩn hội:
        -   Nếu $A$ là mệnh đề con, thì $(A)$ là dạng chuẩn hội,
        -   Nếu $A$ là mệnh đề con và $B$ là dạng chuẩn hội, thì $(A)\land B$ là dạng chuẩn hội.
    
    Tương tự, hoán đổi $\land$ và $\lor$ trong định nghĩa trên thì thu được định nghĩa của dạng chuẩn tuyển.

Ví dụ, các biểu thức logic sau đều là dạng chuẩn tuyển:

-   $(A\land\lnot B)\lor(C\land D\land\lnot E)$,
-   $(A\land B)\lor (C)$,
-   $(A\land B)$,
-   $(A)$.

Các biểu thức logic sau đều là dạng chuẩn hội:

-   $(\lnot A\lor\lnot B\lor C)\land(\lor D\lor\lnot E)$,
-   $(A\lor B)\land (C)$,
-   $(A\lor B)$,
-   $(A)$.

Các biểu thức logic sau không phải dạng chuẩn hội cũng không phải dạng chuẩn tuyển:

-   $\lnot(A\land B)$,
-   $A\land (B\lor (C\land D))$.

Ta có thể đưa một biểu thức logic bất kỳ chỉ chứa các phép toán $\lnot$, $\land$, $\lor$ về DNF bằng các bước sau:

$$
\begin{array}{rcccl}
    \lnot\lnot x &&\mapsto&& x,\\
    \lnot(x\lor y) &&\mapsto&& \lnot x\land \lnot y,\\
    \lnot(x\land y) &&\mapsto&& \lnot x\lor \lnot y,\\
    x\land(y\lor z) &&\mapsto&& (x\land y)\lor (x\land z),\\
    (x\lor y)\land z &&\mapsto&& (x\land z)\lor (y\land z).
\end{array}
$$

Để thu được CNF của biểu thức $X$, chỉ cần tìm DNF của $\lnot X$, sau đó phủ định lại và áp dụng luật De Morgan.

???+ abstract "Dạng chuẩn đại số"
    Trước hết, ta dùng định nghĩa đệ quy sau để định nghĩa mệnh đề con:
    
    -   Biến $x$ là mệnh đề con,
    -   Nếu $A$ là mệnh đề con và $x$ là biến, thì $x\land A$ là mệnh đề con.
    
    Khi đó, biểu thức logic thỏa mãn một trong ba dạng sau là dạng chuẩn đại số:
    
    1.  $1$, $0$,
    2.  XOR của một số mệnh đề con không tương đương nhau, chẳng hạn $a\oplus b\oplus(a\land b)\oplus(a\land b\land c)$,
    3.  XOR của một số mệnh đề con không tương đương nhau và duy nhất một $1$, chẳng hạn $1\oplus a\oplus b\oplus(a\land b)\oplus(a\land b\land c)$.

Chú ý rằng dạng chuẩn đại số tương ứng một-một với đa thức trên $\mathbf{Z}_2$, nên dạng chuẩn đại số cũng được gọi là **đa thức Zhegalkin** (Zhegalkin polynomial).

Ta có thể đưa một biểu thức logic bất kỳ chỉ chứa các phép toán $\lnot$, $\land$, $\lor$, $\oplus$ về ANF bằng các bước sau:

1.  $\oplus$: khai triển trực tiếp, chẳng hạn $(1\oplus x)\oplus(1\oplus x\oplus y)=1\oplus x\oplus 1\oplus x\oplus y=y$,
2.  $\land$: khai triển bằng luật phân phối, chẳng hạn $x\land(1\oplus x\oplus y)=(x\land 1)\oplus (x\land x)\oplus (x\land y)=x\oplus (x\land y)$,
3.  $\lnot$: thay $\lnot x$ bằng $1\oplus x$, chẳng hạn $\lnot(1\oplus x\oplus y)=1\oplus 1\oplus x\oplus y=x\oplus y$,
4.  $\lor$: thay $x\lor y$ bằng $1\oplus((1\oplus x)\land(1\oplus y))$ hoặc $x\oplus y\oplus (x\land y)$, chẳng hạn $(1\oplus x)\lor(1\oplus x\oplus y)=1\oplus((1\oplus 1\oplus x)\land(1\oplus 1\oplus x\oplus y))=1\oplus x\oplus(x\land y)$.

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x6CE8;&#x91CA;"></span>
## Tài liệu tham khảo và ghi chú

1.  [Boolean algebra - Wikipedia](https://en.wikipedia.org/wiki/Boolean_algebra)
2.  [Boolean function - Wikipedia](https://en.wikipedia.org/wiki/Boolean_function)
3.  [Logical connective - Wikipedia](https://en.wikipedia.org/wiki/Logical_connective)
4.  [Disjunctive normal form - Wikipedia](https://en.wikipedia.org/wiki/Disjunctive_normal_form)
5.  [Zhegalkin polynomial - Wikipedia](https://en.wikipedia.org/wiki/Zhegalkin_polynomial)

[^note1]: Khi dùng cho suy diễn mệnh đề, nên dùng mũi tên hai vạch dài, như $A\implies B$, $A\impliedby B$, $A\iff B$, v.v.

[^note2]: Tương đương với XNOR.

[^note3]: Tương đương với XOR.

[^vaughan1942complete]: Vaughan, H. E. (1942). Complete sets of logical functions.*Transactions of the American Mathematical Society 51*: 117–32.
