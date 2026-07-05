<span id="mở-đầu"></span>
## Mở đầu

Lý thuyết thứ tự là một nhánh toán học dùng quan hệ hai ngôi để hình thức hóa khái niệm "thứ tự". Phần dưới đây giới thiệu các định nghĩa cơ bản của nhánh này.

<span id="định-nghĩa"></span>
## Định nghĩa

<span id="quan-hệ-hai-ngôi"></span>
### Quan hệ hai ngôi

???+ note "Định nghĩa"
    Một **quan hệ hai ngôi** (binary relation) $R$ trên tập $X$ và tập $Y$ được định nghĩa là bộ $(X,Y,G(R))$, trong đó $X$ được gọi là miền xác định (domain), $Y$ được gọi là đối miền (codomain), và $G(R)\subseteq X\times Y=\{(x,y):x\in X,y\in Y\}$ được gọi là đồ thị (graph) của quan hệ hai ngôi $R$. Mệnh đề $xRy$ đúng khi và chỉ khi $(x,y)\in G(R)$.
    
    Nếu $X=Y$, quan hệ hai ngôi này được gọi là quan hệ hai ngôi thuần nhất (homogeneous relation) hoặc quan hệ nội tại (endorelation).
    
    Nếu không nói rõ thêm, các quan hệ hai ngôi trong phần dưới đều là quan hệ hai ngôi thuần nhất.

Ví dụ, quan hệ chia hết $\mid$ và quan hệ nhỏ hơn hoặc bằng $\leq$ trên $\mathbf{N}_+$ đều là quan hệ hai ngôi.

Khi nghiên cứu quan hệ hai ngôi, ta thường quan tâm liệu chúng có một số tính chất đặc biệt hay không. Với quan hệ hai ngôi $R$ trên tập $S$, ta định nghĩa các tính chất đặc biệt sau:

1.  Tính phản xạ (reflexive): $(\forall~a \in S)~~aRa$,
2.  Tính phi phản xạ (irreflexive, anti-reflexive): $(\forall~a \in S)~~\lnot(aRa)$,
3.  Tính đối xứng (symmetric): $(\forall~a,b \in S)~~aRb \iff bRa$,
4.  Tính phản đối xứng (antisymmetric): $(\forall~a,b \in S)~~(aRb \land bRa) \implies a=b$,
5.  Tính bất đối xứng (asymmetric): $(\forall~a,b \in S)~~aRb \implies \lnot(bRa)$,
6.  Tính bắc cầu (transitive): $(\forall~a,b,c \in S)~~(aRb \land bRc) \implies aRc$,
7.  Tính liên thông (connected): $(\forall~a,b \in S)~~a \neq b \implies (aRb \lor bRa)$,
8.  Tính có cơ sở tốt (well-founded): $(\exists~m \in S \neq \varnothing)~~(\forall~a \in S\setminus\{m\})~~\lnot(aRm)$ (tức là tập không rỗng $S$ có phần tử cực tiểu $m$),
9.  Tính bắc cầu của không so sánh được (transitive of incomparability): $(\forall~a,b,c \in S)~~(\lnot(aRb \lor bRa) \land \lnot(bRc \lor cRb)) \implies \lnot(aRc \lor cRa)$ (nếu $\lnot(aRb \lor bRa)$, ta nói $a$ và $b$ không so sánh được).

Đồng thời, ta định nghĩa một số quan hệ hai ngôi đặc biệt:

| Quan hệ hai ngôi | Tính phản xạ | Tính phi phản xạ | Tính đối xứng | Tính phản đối xứng | Tính bất đối xứng | Tính bắc cầu | Tính liên thông | Tính có cơ sở tốt | Bắc cầu của không so sánh được |
| ---------------- | ------------ | ---------------- | ------------- | ------------------ | ----------------- | ------------- | --------------- | ----------------- | ------------------------------- |
| Quan hệ tương đương (equivalence relation) | Có | | Có | | | Có | | | |
| Tiền thứ tự (preorder, quasiorder) | Có | | | | | Có | | | |
| Thứ tự bộ phận (partial order) | Có | | | Có | | Có | | | |
| Thứ tự toàn phần (total order) | Có | | | Có | | Có | Có | | |
| Thứ tự tốt (well-order) | Có | | | Có | | Có | Có | Có | |
| Tiền thứ tự nghiêm ngặt (strict preorder) | | Có | | | | Có | | | |
| Thứ tự bộ phận nghiêm ngặt (strict partial order) | | Có | | | Có | Có | | | |
| Thứ tự yếu nghiêm ngặt (strict weak order) | | Có | | | Có | Có | | | Có |
| Thứ tự toàn phần nghiêm ngặt (strict total order) | | Có | | | Có | Có | Có | | |

<span id="các-phép-toán-giữa-quan-hệ"></span>
### Các phép toán giữa quan hệ

Với hai quan hệ hai ngôi $R$ và $S$ trên tập $X$ và tập $Y$, ta có thể định nghĩa các phép toán sau:

1.  Hợp $R\cup S$ của $R$ và $S$ thỏa mãn $G(R\cup S):=\{(x,y):xRy \lor xSy\}$ (ví dụ $\leq$ là hợp của $<$ và $=$),
2.  Giao $R\cap S$ của $R$ và $S$ thỏa mãn $G(R\cap S):=\{(x,y):xRy \land xSy\}$,
3.  Phần bù $\bar{R}$ của $R$ thỏa mãn $G(\bar{R}):=\{(x,y):\lnot(xRy)\}$,
4.  Đối ngẫu $R^T$ của $R$ thỏa mãn $G(R^T):=\{(y,x):xRy\}$.

Với quan hệ hai ngôi $R$ trên tập $X$ và tập $Y$, cùng quan hệ hai ngôi $S$ trên tập $Y$ và tập $Z$, ta có thể định nghĩa hợp thành $S\circ R$ của chúng sao cho $G(S\circ R):=\{(x,z):(\exists~y\in Y)~~xRy\land ySz\}$.

<span id="tập-có-thứ-tự-bộ-phận"></span>
### Tập có thứ tự bộ phận

???+ note "Định nghĩa"
    Nếu một quan hệ hai ngôi $\preceq$ trên tập $S$ có **tính phản xạ**, **tính phản đối xứng** và **tính bắc cầu**, thì $S$ được gọi là **tập có thứ tự bộ phận** (partially ordered set, poset), còn $\preceq$ là một **thứ tự bộ phận** (partial order) trên $S$.
    
    Nếu thứ tự bộ phận $\preceq$ còn có **tính liên thông**, thì nó được gọi là **thứ tự toàn phần** (total order), và tập tương ứng được gọi là **tập có thứ tự toàn phần** (totally ordered set), **tập có thứ tự tuyến tính** (linearly ordered set, loset) hoặc **tập có thứ tự đơn giản** (simply ordered set).

Dễ thấy $\mathbf{N}$, $\mathbf{Z}$, $\mathbf{Q}$ và $\mathbf{R}$ đều tạo thành tập có thứ tự toàn phần theo $\leq$.

<span id="biểu-diễn-trực-quan-tập-có-thứ-tự-bộ-phận-biểu-đồ-hasse"></span>
### Biểu diễn trực quan tập có thứ tự bộ phận: biểu đồ Hasse

Với tập có thứ tự bộ phận hữu hạn, ta có thể dùng biểu đồ Hasse để biểu diễn trực quan quan hệ thứ tự bộ phận trên đó.

???+ note "Định nghĩa"
    Với tập có thứ tự bộ phận hữu hạn $S$ và thứ tự bộ phận $\preceq$ trên đó, định nghĩa $x\prec y\iff (x\preceq y\land x\neq y)$. **Biểu đồ Hasse** tương ứng là đồ thị $G=\langle V,E\rangle$ thỏa mãn các điều kiện sau:
    
    -   $V=S$,
    -   $E=\{(x,y)\in S\times S: x\prec y \land ((\nexists~z\in S)~~x\prec z\prec y)\}$

Ví dụ, với lũy tập $S$ của tập $\{0,1,2\}$ và quan hệ bao hàm tập hợp $\subseteq$, biểu đồ Hasse tương ứng là:

![](images/order-theory1.svg)

Vì thứ tự bộ phận có tính phản đối xứng, biểu đồ Hasse chắc chắn là [đồ thị có hướng không chu trình](../graph/dag.md). Do đó, ta có thể dựa vào [sắp xếp topo](../graph/topo.md) để xây dựng một thứ tự toàn phần cho bất kỳ tập có thứ tự bộ phận hữu hạn nào.

<span id="xích-và-phản-xích"></span>
### Xích và phản xích

???+ note "Định nghĩa"
    Với tập có thứ tự bộ phận $S$ và thứ tự bộ phận $\preceq$ trên đó, một tập con có thứ tự toàn phần của $S$ được gọi là **xích** (chain). Nếu hai phần tử phân biệt bất kỳ trong tập con $T$ của $S$ đều không so sánh được (tức là $(\forall~a,b \in T)~~a \neq b \implies (a \npreceq b \land b \npreceq a)$), thì $T$ được gọi là **phản xích** (antichain).
    
    Với tập có thứ tự bộ phận $S$ và thứ tự bộ phận $\preceq$ trên đó, độ dài phản xích dài nhất của $S$ được gọi là **độ rộng** (partial order width) của tập có thứ tự bộ phận $S$.

Ví dụ, với lũy tập $S$ của tập $\{0,1,2\}$ và quan hệ bao hàm tập hợp $\subseteq$, $\{\varnothing,\{1\},\{1,2\}\}$ là một xích, $\{\{1\},\{0,2\}\}$ là một phản xích, và độ rộng của $S$ là $3$.

<span id="các-phần-tử-đặc-biệt-trong-tập-tiền-thứ-tự"></span>
### Các phần tử đặc biệt trong tập tiền thứ tự

Trong tập tiền thứ tự, ta có thể định nghĩa các khái niệm như phần tử cực đại (cực tiểu), cận trên (cận dưới), cận trên đúng (cận dưới đúng). Các khái niệm này có thể được mở rộng sang các quan hệ thứ tự khác.

???+ note "Định nghĩa"
    Với tập tiền thứ tự $S$ và tiền thứ tự $\preceq$ trên đó, lấy phần tử $m$ trong $S$:
    
    1.  Nếu $(\forall~a \in S\setminus\{m\})~~\lnot(m\preceq a)$, thì $m$ được gọi là **phần tử cực đại** (maximal element),
    2.  Nếu với $T \subseteq S$ ta có $(\forall~t\in T)~~t\preceq m$, thì $m$ được gọi là **cận trên** (upper bound) của $T$,
    3.  Nếu với $T \subseteq S$, $m$ là cận trên của $T$ và với mọi cận trên $n$ của $T$ đều có $m \preceq n$, thì $m$ được gọi là **cận trên đúng** (supremum) của $T$.
    
    Tương tự, ta có thể định nghĩa **phần tử cực tiểu** (minimal element), **cận dưới** (lower bound) và **cận dưới đúng** (infimum).

Ví dụ, $1$ là phần tử cực tiểu và cận dưới của $\mathbf{N}_+$.

Có thể chứng minh:

-   Trong tập tiền thứ tự, phần tử cực đại (cực tiểu), cận trên (cận dưới), cận trên đúng (cận dưới đúng) không nhất thiết tồn tại; ngay cả khi tồn tại cũng không nhất thiết duy nhất.

-   Nếu tập con $T$ của tập có thứ tự bộ phận $S$ có cận trên đúng (cận dưới đúng), thì cận đó chắc chắn duy nhất.

    Ta có thể ký hiệu cận trên đúng và cận dưới đúng của $T$ lần lượt là $\sup T$ và $\inf T$. Nếu tập có thứ tự bộ phận $S$ vừa có cận trên vừa có cận dưới, ta nói $S$ là bị chặn.

Trong tập có thứ tự bộ phận vô hạn, phần tử cực đại không nhất thiết tồn tại. Có thể dùng **bổ đề Zorn** (Zorn's Lemma) để phán đoán liệu tập có thứ tự bộ phận vô hạn có phần tử cực đại hay không.

???+ note "[Bổ đề Zorn](https://en.wikipedia.org/wiki/Zorn%27s_lemma)"
    **Bổ đề Zorn** còn được gọi là **bổ đề Kuratowski-Zorn**. Nội dung của nó là: nếu mọi xích của một tập có thứ tự bộ phận không rỗng đều có cận trên, thì tập có thứ tự bộ phận đó có phần tử cực đại.

Bổ đề Zorn tương đương với **[tiên đề chọn](https://en.wikipedia.org/wiki/Axiom_of_choice)** và **[định lý thứ tự tốt](https://en.wikipedia.org/wiki/Well-ordering_theorem)**.

<span id="tập-định-hướng-và-dàn"></span>
### Tập định hướng và dàn

Ta biết rằng nếu một tập con của tập có thứ tự bộ phận có cận trên đúng (cận dưới đúng), thì cận đó chắc chắn duy nhất. Tuy nhiên, điều này không áp dụng cho phần tử cực đại (cực tiểu). Ví dụ: xét tập có thứ tự bộ phận $S=\{\{0\},\{1\},\{2\},\{0,1\},\{0,2\},\{1,2\}\}$ với thứ tự bộ phận $\subseteq$ trên đó. Dễ thấy nó có $3$ phần tử cực đại và $3$ phần tử cực tiểu.

Ta muốn thêm một số điều kiện vào tập có thứ tự bộ phận để bảo đảm rằng nếu phần tử cực đại (cực tiểu) tồn tại thì nó chắc chắn duy nhất; nhờ đó ta có thể định nghĩa khái niệm phần tử lớn nhất (nhỏ nhất).

???+ note "Tập định hướng"
    Với tập tiền thứ tự $S$ và tiền thứ tự $\preceq$ trên đó, nếu $(\forall~a,b\in S)~~(\exists~c\in S)~~a\preceq c\land b\preceq c$, thì $\preceq$ được gọi là một **hướng** (direction) của $S$, còn $S$ được gọi là **tập định hướng** (directed set) hoặc **tập lọc** (filtered set).
    
    Đôi khi tập $S$ thỏa mãn định nghĩa trên cũng được gọi là **tập định hướng lên** (upward directed set); tương tự, ta có thể định nghĩa **tập định hướng xuống** (downward directed set).

Tập định hướng cũng có thể được định nghĩa theo cách sau:

???+ note "Định nghĩa tương đương của tập định hướng"
    Với tập tiền thứ tự $S$ và tiền thứ tự $\preceq$ trên đó, nếu mọi tập con hữu hạn $T$ của $S$ đều có cận trên, thì $\preceq$ được gọi là một hướng của $S$, còn $S$ được gọi là tập định hướng.

Dễ thấy:

-   Nếu tập định hướng lên có phần tử cực đại, thì phần tử đó chắc chắn duy nhất. Ta gọi phần tử cực đại của tập định hướng lên là **phần tử lớn nhất** (greatest element).
-   Nếu tập định hướng xuống có phần tử cực tiểu, thì phần tử đó chắc chắn duy nhất. Ta gọi phần tử cực tiểu của tập định hướng xuống là **phần tử nhỏ nhất** (least element).

Trong một tập có thứ tự bộ phận có hướng, với mọi phần tử $a,b$, $\{a,b\}$ đều có cận trên. Nếu thay cận trên bằng cận trên đúng, ta thu được định nghĩa của nửa dàn hợp.

Với tập có thứ tự bộ phận $S$ và thứ tự bộ phận $\preceq$ trên đó:

???+ note "Nửa dàn hợp"
    Nếu với mọi phần tử $a,b$ trong $S$, $\{a,b\}$ đều có cận trên đúng $c$, thì $S$ được gọi là **nửa dàn hợp** (join-semilattice, upper semilattice), và ta gọi $c$ là **hợp** (join) của $a$ và $b$, ký hiệu là $a\lor b$.

???+ note "Nửa dàn giao"
    Nếu với mọi phần tử $a,b$ trong $S$, $\{a,b\}$ đều có cận dưới đúng $c$, thì $S$ được gọi là **nửa dàn giao** (meet-semilattice, lower semilattice), và ta gọi $c$ là **giao** (meet) của $a$ và $b$, ký hiệu là $a\land b$.

???+ note "Dàn"
    Nếu $S$ vừa là nửa dàn hợp vừa là nửa dàn giao, thì $S$ được gọi là **dàn** (lattice).

Ví dụ, tập $S=\{1,2,3,4,5,6,10,12,15,20,30,60\}$ gồm các ước dương của $60$ tạo thành một tập có thứ tự bộ phận theo quan hệ chia hết. Với hai số nguyên dương bất kỳ $a,b$ trong tập này, $\operatorname{lcm}(a,b)$ là hợp của $a$ và $b$, còn $\gcd(a,b)$ là giao của $a$ và $b$; do đó $S$ là một dàn.

<span id="đối-ngẫu"></span>
### Đối ngẫu

Trong lý thuyết thứ tự, đối ngẫu là một khái niệm rất thường gặp, chẳng hạn các cặp đối ngẫu đã nhắc ở trên: phần tử cực đại và phần tử cực tiểu, cận trên và cận dưới, cận trên đúng và cận dưới đúng.

Với tập có thứ tự bộ phận $P$ và thứ tự bộ phận $\preceq$ trên đó, định nghĩa tập có thứ tự bộ phận **đối ngẫu** (dual, opposite) $P^d$ của nó như sau: $x \preceq y$ đúng trong $P$ khi và chỉ khi $y \preceq x$ đúng trong $P^d$. Đảo chiều các cạnh trong biểu đồ Hasse của $P$ sẽ thu được biểu đồ Hasse của $P^d$.

<span id="định-lý-dilworth-và-định-lý-mirsky"></span>
## Định lý Dilworth và định lý Mirsky

Với tập có thứ tự bộ phận hữu hạn $S$ và thứ tự bộ phận $\preceq$ trên đó, ta có cặp định lý đối ngẫu sau:

???+ note "Định lý Dilworth"
    Độ rộng của $S$ (độ dài phản xích dài nhất) bằng số xích ít nhất cần để phủ $S$.
    
    ??? note "Chứng minh"
        Xét quy nạp toán học. Khi $|S|\leq 3$, mệnh đề hiển nhiên đúng.
        
        Giả sử mệnh đề đúng với mọi tập có thứ tự bộ phận có số phần tử nhỏ hơn $|S|$. Gọi độ rộng của $S$ là $d$. Nếu mọi phần tử trong $S$ đều đôi một không so sánh được, mệnh đề hiển nhiên đúng; nếu không, lấy trong $S$ một xích có độ dài lớn hơn $1$, gọi phần tử nhỏ nhất của xích đó là $m$ và phần tử lớn nhất là $M$.
        
        Đặt $T=S\setminus\{m,M\}$. Nếu độ rộng của $T$ không vượt quá $d-1$, thì theo giả thiết quy nạp, $T$ có thể được phủ bởi nhiều nhất $d-1$ xích; do đó $S$ có thể được phủ bởi các xích này cộng thêm xích $\{m,M\}$, và mệnh đề đúng. Ngược lại, độ rộng của $T$ cũng là $d$; gọi $A$ là một phản xích dài nhất trong $T$.
        
        Xét hai tập sau:
        
        $$
        S^+:=\{x\in S:(\exists~a\in A)~~a\preceq x\}
        $$
        
        $$
        S^-:=\{x\in S:(\exists~a\in A)~~x\preceq a\}
        $$
        
        Dễ thấy các tính chất sau:
        
        -   $S^+\cup S^-=S$,
        -   $S^+\cap S^-=A$,
        -   $|S^+|<|S|$,$|S^-|<|S|$ (vì $m\notin S^+$ và $M\notin S^-$).
        
        Áp dụng giả thiết quy nạp cho cả $S^+$ và $S^-$, số xích ít nhất cần để phủ mỗi tập này đều là $d$, và các xích đó chứa đúng một phần tử $a$ trong $A$. Gọi các xích tương ứng là $C_a^+$ và $C_a^-$. Khi đó $\{C_a^-\cup\{a\}\cup C_a^+\}_{a\in A}$ là một phủ xích tối tiểu của $S$, nên mệnh đề được chứng minh.

???+ note "Định lý Mirsky"
    Độ dài xích dài nhất của $S$ bằng số phản xích ít nhất cần để phủ $S$.
    
    ??? note "Chứng minh"
        Gọi độ dài xích dài nhất của $S$ là $d$. Theo định nghĩa, số phản xích ít nhất cần để phủ $S$ ít nhất là $d$.
        
        Gọi $f(s)$ là độ dài xích dài nhất có $s$ làm phần tử nhỏ nhất. Chú ý rằng nếu $f(s)=f(t)$ thì $s$ và $t$ không so sánh được; do đó $(\forall~n\in\mathbf{N})~~f^{-1}(\{n\})$ đều là phản xích, trong đó $f^{-1}(\{n\}):=\{a\in S:f(a)=n\}$ được gọi là [tập mức (level set)](https://en.wikipedia.org/wiki/Level_set).
        
        Vì vậy dễ suy ra $\{f^{-1}(\{i\}):1\leq i\leq d\}$ là một phủ phản xích, nên số phản xích ít nhất cần để phủ không vượt quá $d$.

Định lý Dilworth tương đương với [định lý hôn nhân Hall](../graph/graph-matching/graph-match.md#định-lý-hall).

Ta có thể dùng định lý Dilworth để chứng minh định lý sau:

???+ note "Định lý Erdős-Szekeres"
    Một dãy số thực $\{a_i\}$ có ít nhất $rs+1$ phần tử thì hoặc có một dãy con không giảm độ dài $r+1$, hoặc có một dãy con không tăng độ dài $s+1$.
    
    ??? note "Chứng minh"
        Giả sử độ dài dãy là $n\geq rs+1$. Định nghĩa tập có thứ tự bộ phận $\{(i,a_i)\}_{i=1}^{n}$, với thứ tự bộ phận $\preceq$ trên đó được định nghĩa bởi:
        
        $$
        (i,a_i)\preceq (j,a_j)\iff (i\leq j\land a_i\leq a_j)
        $$
        
        Giả sử độ rộng của tập có thứ tự bộ phận này không vượt quá $s$. Khi đó, theo định lý Dilworth, tập có thứ tự bộ phận này có thể được phủ bởi nhiều nhất $s$ xích. Nếu độ dài của mỗi xích đều không vượt quá $r$, thì số phần tử của dãy nhiều nhất là $rs$, mâu thuẫn với điều kiện.

<span id="bài-tập-ví-dụ"></span>
### Bài tập ví dụ

???+ note "[Luogu P1020 \[NOIP1999 Nhóm nâng cao\] Chặn tên lửa](https://www.luogu.com.cn/problem/P1020)"
    Để phòng thủ trước các cuộc tấn công bằng tên lửa của nước địch, một quốc gia đã phát triển một hệ thống đánh chặn tên lửa. Tuy nhiên, hệ thống này có một nhược điểm: tuy quả đạn đầu tiên có thể đạt tới độ cao bất kỳ, nhưng mỗi quả đạn sau đó không thể cao hơn độ cao của quả trước. Một ngày nọ, radar phát hiện tên lửa của địch đang bay tới. Vì hệ thống còn đang trong giai đoạn thử nghiệm nên chỉ có một bộ hệ thống, do đó có thể không đánh chặn được tất cả tên lửa.
    
    Nhập lần lượt độ cao của các tên lửa bay tới. Hãy tính số tên lửa nhiều nhất mà một bộ hệ thống này có thể đánh chặn, và nếu muốn đánh chặn tất cả tên lửa thì cần trang bị ít nhất bao nhiêu bộ hệ thống như vậy.
    
    Với toàn bộ dữ liệu, độ cao tên lửa là số nguyên dương và không vượt quá $5\times 10^4$.
    
    ??? note "Lời giải"
        Giả sử có tổng cộng $n$ tên lửa, và độ cao của tên lửa thứ $i$ là $h_i$. Khi đó tập $\{(i,h_i)\}_{i=1}^{n}$ là một tập có thứ tự bộ phận, với thứ tự bộ phận $\preceq$ trên đó được định nghĩa bởi:
        
        $$
        (i,h_i)\preceq(j,h_j) \iff (i\leq j \land h_i\geq h_j)
        $$
        
        Theo định lý Dilworth, ta có: **số dãy con không tăng ít nhất cần để phủ dãy bằng độ dài dãy con tăng dài nhất**. Vì vậy có thể giải bài này bằng [cách làm $O(n\log n)$ cho dãy con không giảm dài nhất](../dp/basic.md#thuật-toán-2).
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/math/code/order-theory/order-theory_1.cpp"
        ```

???+ note "[\[TJOI2015\] Toán tổ hợp](https://www.luogu.com.cn/problem/P3974)"
    Cho một lưới gồm $n$ hàng và $m$ cột, trong mỗi ô có một số khối châu báu. Mỗi lần xuất phát từ góc trên bên trái, chỉ được đi sang phải hoặc đi xuống, và mỗi lần đi qua một ô thì nhiều nhất chỉ có thể nhặt một khối châu báu. Hỏi cần đi ít nhất bao nhiêu lần thì mới có thể nhặt hết châu báu.
    
    $1\le n \le 1000$, $1\le m \le 1000$, số khối châu báu trong mỗi ô không vượt quá $10^6$.
    
    ??? note "Lời giải"
        Không xét trọng số đỉnh của lưới, dễ thấy đi trên lưới theo quy tắc đã cho tương đương với đi trên một DAG. Do đó ta có thể xem nó như một biểu đồ Hasse để xây dựng tập có thứ tự bộ phận; theo định lý Dilworth, ta có: **số xích ít nhất cần để phủ một DAG bằng kích thước tập đỉnh độc lập lớn nhất**.
        
        Vì vậy, thứ bài này cần tìm chính là tổng trọng số đỉnh của tập đỉnh độc lập có trọng số lớn nhất trong lưới đã cho.
        
        Gọi $a_{ij}$ là trọng số của lưới tại đỉnh $(i,j)$, và $f(i,j)$ là đáp án trong lưới con từ $(i,j)$ đến $(1,m)$. Chú ý rằng mỗi đỉnh đều không kề với các đỉnh ở góc trên bên phải của nó, nên phương trình chuyển trạng thái là:
        
        $$
        f(i,j)=\max\{f(i-1,j),f(i,j+1),f(i-1,j+1)+a_{ij}\}
        $$
        
        Đáp án là $f(n,1)$.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/math/code/order-theory/order-theory_2.cpp"
        ```

<span id="bài-tập"></span>
### Bài tập

-   [\[CTSC2008\] Tế lễ](https://www.luogu.com.cn/problem/P4298)
-   [CodeForces 590E Birthday](https://codeforces.com/problemset/problem/590/E)

<span id="ứng-dụng-trong-c"></span>
## Ứng dụng trong C++

Xem thêm: [STL liên quan đến sắp xếp - Cơ sở thuật toán](../basic/stl-sort.md).

Trong các [thuật toán và cấu trúc dữ liệu cần dùng so sánh](https://en.cppreference.com/w/cpp/named_req/Compare#Standard_library) của C++ STL, ta gặp các ứng dụng của lý thuyết thứ tự. Ta thường cần tự định nghĩa bộ so sánh trong C++; STL [yêu cầu](https://en.cppreference.com/w/cpp/named_req/Compare) bộ so sánh đó phải là **thứ tự yếu nghiêm ngặt**. Gọi $<$ là bộ so sánh tự định nghĩa, ta có thể định nghĩa:

-   $x>y$ là $y<x$;
-   $x \leq y$ là $y \nless x$;
-   $x \geq y$ là $x \nless y$;
-   $x=y$ là $x \nless y\land y \nless x$.

<span id="tài-liệu-tham-khảo-và-đọc-thêm"></span>
## Tài liệu tham khảo và đọc thêm

1.  [Order theory - From Academic Kids](https://academickids.com/encyclopedia/index.php/Order_theory)
2.  [Binary Relation - Wikipedia](https://en.wikipedia.org/wiki/Binary_relation)
3.  [Order Theory - Wikipedia](https://en.wikipedia.org/wiki/Order_theory)
4.  [Hasse diagram - Wikipedia](https://en.wikipedia.org/wiki/Hasse_diagram)
5.  [Directed set - Wikipedia](https://en.wikipedia.org/wiki/Directed_set)
6.  [Order Theory, Lecture Notes by Mark Dean for Decision Theory](http://www.columbia.edu/~md3405/DT_Order_15.pdf)
7.  Kai-Cheng Lu, Hua-Ming Lu, [Combinatorics, ấn bản thứ 3](http://www.tup.tsinghua.edu.cn/bookscenter/book_00458101.html), 2006
8.  [List of Order Theory Topics - Wikipedia](https://en.wikipedia.org/wiki/List_of_order_theory_topics)
9.  [Bàn về ứng dụng của sắp xếp bằng hoán đổi hai phần tử kề và các vấn đề cần chú ý, bởi ouuan](https://ouuan.github.io/post/%E6%B5%85%E8%B0%88%E9%82%BB%E9%A1%B9%E4%BA%A4%E6%8D%A2%E6%8E%92%E5%BA%8F%E7%9A%84%E5%BA%94%E7%94%A8%E4%BB%A5%E5%8F%8A%E9%9C%80%E8%A6%81%E6%B3%A8%E6%84%8F%E7%9A%84%E9%97%AE%E9%A2%98/)
10. [One thing you should know about comparators: Strict Weak Ordering](https://codeforces.com/blog/entry/72525)
11. [Dilworth's theorem - Wikipedia](https://en.wikipedia.org/wiki/Dilworth%27s_theorem)
12. [Dilworth's Theorem | Brilliant Math & Science Wiki](https://brilliant.org/wiki/dilworths-theorem/)
13. [Hall's marriage theorem - Wikipedia](https://en.wikipedia.org/wiki/Hall's_marriage_theorem)
14. [Hall's Marriage Theorem | Brilliant Math & Science Wiki](https://brilliant.org/wiki/hall-marriage-theorem/)
15. [Ghi chú học Dilworth - Selfish](https://www.luogu.com.cn/blog/Rolling-Code/dilworth)
