author: pw384, s0cks5, Watersail2005, Xeonacid

Định lý ma trận cây giải quyết bài toán đếm số cây khung của một đồ thị.

## Quy ước ký hiệu trong bài này

Trong bài này, đồ thị, dù vô hướng hay có hướng, đều cho phép cạnh bội, nhưng mặc định không có khuyên.

??? note "Trường hợp có khuyên"
    Khuyên không ảnh hưởng đến số cây khung,
    cũng không ảnh hưởng đến cách tính ma trận Laplace bên dưới,
    nên định lý ma trận cây vẫn đúng trong trường hợp có khuyên.
    Khi tính toán không cần xóa khuyên.
    Nếu xóa khuyên, việc áp dụng định lý ma trận cây dựa trên định lý BEST
    để đếm số chu trình Euler trong đồ thị có hướng sẽ bị ảnh hưởng.

### Trường hợp đồ thị vô hướng

Giả sử $G$ là đồ thị vô hướng có $n$ đỉnh. Định nghĩa ma trận bậc $D(G)$ bởi

$$
D_{ii}(G) = \mathrm{deg}(i),\ D_{ij} = 0,\ i\neq j.
$$

Gọi $\#e(i,j)$ là số cạnh nối đỉnh $i$ và đỉnh $j$, và định nghĩa ma trận kề $A$ bởi

$$
A_{ij}(G)=A_{ji}(G)=\#e(i,j),\ i\neq j.
$$

Định nghĩa ma trận Laplace, còn gọi là ma trận Kirchhoff, $L$ bởi

$$
L(G) = D(G) - A(G).
$$

Ký hiệu số cây khung của đồ thị $G$ là $t(G)$.

### Trường hợp đồ thị có hướng

Giả sử $G$ là đồ thị có hướng có $n$ đỉnh. Định nghĩa ma trận bậc ra $D^{out}(G)$ bởi

$$
D^\mathrm{out}_{ii}(G) = \mathrm{deg}^\mathrm{out}(i),\ D^\mathrm{out}_{ij} = 0,\ i\neq j.
$$

Tương tự, định nghĩa ma trận bậc vào $D^\mathrm{in}(G)$.

Gọi $\#e(i,j)$ là số cạnh có hướng từ đỉnh $i$ đến đỉnh $j$, và định nghĩa ma trận kề $A$ bởi

$$
A_{ij}(G)=\#e(i,j),\ i\neq j.
$$

Định nghĩa ma trận Laplace bậc ra $L^\mathrm{out}$ bởi

$$
L^\mathrm{out}(G) = D^\mathrm{out}(G) - A(G).
$$

Định nghĩa ma trận Laplace bậc vào $L^\mathrm{in}$ bởi

$$
L^\mathrm{in}(G) = D^\mathrm{in}(G) - A(G).
$$

Ký hiệu số cây khung có hướng lấy $k$ làm gốc và hướng về gốc của đồ thị $G$
là $t^\mathrm{root}(G,k)$.
Cây khung có hướng hướng về gốc nghĩa là đồ thị nền của nó là một cây,
và mọi cạnh đều hướng về phía cha.

Ký hiệu số cây khung có hướng lấy $k$ làm gốc và hướng ra lá của đồ thị $G$
là $t^\mathrm{leaf}(G,k)$.
Cây khung có hướng ra lá nghĩa là đồ thị nền của nó là một cây,
và mọi cạnh đều hướng về phía con.

## Phát biểu định lý

Định lý ma trận cây có nhiều dạng.

Định nghĩa $[n]=\{1,2,\cdots,n\}$.
Với ma trận $A$, ma trận con $A_{S,T}$ là ma trận thu được
bằng cách chọn các phần tử $A_{i,j}\pod{i\in S,j\in T}$.

???+ note "Định lý 1 (định lý ma trận cây, đồ thị vô hướng, dạng định thức)"
    Với đồ thị vô hướng $G$ và $k$ bất kỳ, có

    $$
    t(G) = \det L(G)_{[n]\setminus\{k\},[n]\setminus\{k\}}.
    $$

    Nói cách khác, mọi định thức con chính cấp $n-1$ của ma trận Laplace của đồ thị vô hướng đều bằng nhau, và đều bằng số cây khung của đồ thị.

???+ note "Hệ quả 1 (định lý ma trận cây, đồ thị vô hướng, dạng trị riêng)"
    Giả sử $\lambda_1\ge\lambda_2\ge\cdots\ge\lambda_{n-1}\ge\lambda_n=0$ là $n$ trị riêng của $L(G)$. Khi đó

    $$
    t(G) = \frac{1}{n}\lambda_1\lambda_2\cdots\lambda_{n-1}.
    $$

???+ note "Định lý 2 (định lý ma trận cây, cây hướng về gốc trong đồ thị có hướng, dạng định thức)"
    Với đồ thị có hướng $G$ và $k$ bất kỳ, có

    $$
    t^\mathrm{root}(G,k) = \det L^\mathrm{out}(G)_{[n]\setminus\{k\},[n]\setminus\{k\}}.
    $$

    Nói cách khác, định thức con chính thu được từ ma trận Laplace bậc ra
    của đồ thị có hướng sau khi xóa hàng $k$ và cột $k$
    bằng số cây khung có hướng lấy $k$ làm gốc và hướng về gốc.

Vì vậy, nếu muốn đếm tất cả cây khung có hướng hướng về gốc của một đồ thị,
chỉ cần duyệt mọi gốc $k$ và lấy tổng các giá trị $t^\mathrm{root}(G,k)$.

???+ note "Định lý 3 (định lý ma trận cây, cây hướng ra lá trong đồ thị có hướng, dạng định thức)"
    Với đồ thị có hướng $G$ và $k$ bất kỳ, có

    $$
    t^\mathrm{leaf}(G,k) = \det L^\mathrm{in}(G)_{[n]\setminus\{k\},[n]\setminus\{k\}}.
    $$

    Nói cách khác, định thức con chính thu được từ ma trận Laplace bậc vào
    của đồ thị có hướng sau khi xóa hàng $k$ và cột $k$
    bằng số cây khung có hướng lấy $k$ làm gốc và hướng ra lá.

Vì vậy, nếu muốn đếm tất cả cây khung có hướng hướng ra lá của một đồ thị,
chỉ cần duyệt mọi gốc $k$ và lấy tổng các giá trị $t^\mathrm{leaf}(G,k)$.

???+ note "Ghi chú"
    Cây khung có hướng hướng về gốc cũng được gọi là cây hướng vào.
    Tuy nhiên, vì việc tính cây hướng vào lại dùng bậc ra,
    để tránh nhầm lẫn giữa $\mathrm{in}$ và $\mathrm{out}$,
    bài này dùng cách gọi hướng về gốc.

## Chứng minh định lý

Các phát biểu trên rất giống nhau.
Phần này đưa ra một cách chứng minh thống nhất,
đồng thời mở rộng các kết luận trước đó sang đồ thị có trọng số.

Ý tưởng chính của chứng minh như sau:

-   Trước hết, mọi trường hợp đều có thể chuyển về bài toán đếm cây khung có hướng hướng về gốc trên đồ thị có hướng;
-   Dùng ngôn ngữ ma trận để mô tả điều kiện cần và đủ để một số cạnh được chọn tạo thành cây khung có hướng hướng về gốc;
-   Liên hệ thao tác chọn cạnh với định thức của ma trận Laplace bằng công thức Cauchy-Binet;
-   Cuối cùng, chuyển kết luận dạng định thức thành kết luận dạng trị riêng.

### Bổ đề: công thức Cauchy-Binet

???+ note "Bổ đề 1 (Cauchy-Binet)"
    Cho ma trận $A$ kích thước $n\times m$ và ma trận $B$ kích thước $m\times n$. Khi đó

    $$
    \det(AB)=\sum_{S\subset[m];~|S|=n}\det A_{[n],S}\det B_{S,[n]},
    $$

    trong đó ký hiệu tổng nghĩa là $S$ chạy qua mọi tập con kích thước $n$ của $[m]$.
    Nếu $n>m$ thì $\det(AB)=0$.

??? note "Chứng minh (góc nhìn tổ hợp)"
    Tham khảo mô hình trong bài [NOI2021 - Giao điểm đường đi](https://loj.ac/p/3533).
    Trước hết xét ý nghĩa tổ hợp sau của định thức.
    Với ma trận vuông $C$ cấp $n\times n$, dựng đồ thị có hướng không chu trình $G=(V,E)$.
    Trong đó, tập đỉnh là $V=[2]\times[n]\subset\mathbb R^2$,
    tức hai cột điểm trên mặt phẳng.
    Ký hiệu cột điểm bên trái là $L=\{l_i=(1,i):i\in[n]\}$,
    cột điểm bên phải là $R=\{r_i=(2,i):i\in[n]\}$.
    Tập cạnh có hướng là $E=\{(l_i,r_j):i,j\in[n]\}$,
    với trọng số cạnh $w(l_i,r_j)=C_{i,j}$.
    Trong đồ thị, gọi một tập con cạnh $E^\sigma\subset E$ có kích thước $n$
    là một nhóm đường đi nếu các điểm đầu đôi một khác nhau và các điểm cuối cũng đôi một khác nhau.
    Các nhóm đường đi $E^\sigma$ tương ứng một-một với các hoán vị $\sigma$ trên $[n]$.
    Khi vẽ một nhóm đường đi trên mặt phẳng,
    các cạnh có thể cắt nhau từng đôi một,
    và số giao điểm đó, tính cả bội, chính bằng số nghịch thế của $\sigma$.
    Lý do là cạnh $(l_i,r_{\sigma(i)})$ và cạnh $(l_j,r_{\sigma(j)})$ cắt nhau
    khi và chỉ khi $(i-j)(\sigma(i)-\sigma(j))< 0$,
    tức đó là một cặp nghịch thế.
    Để tiện, gọi tính chẵn lẻ của số nghịch thế của hoán vị tương ứng,
    hay tương đương tính chẵn lẻ của số giao điểm của nhóm đường đi,
    là tính chẵn lẻ của nhóm đường đi.
    Do đó, nếu đếm các nhóm đường đi theo trọng số,
    rồi lấy số nhóm có số giao điểm chẵn trừ đi số nhóm có số giao điểm lẻ,
    sẽ thu được khai triển Leibniz của định thức:

    $$
    \det(C)=\sum_{\sigma\in S_n}\mathrm{sgn}(\sigma)\prod_{i\in[n]}C_{i,\sigma(i)},
    $$

    trong đó $S_n$ là nhóm hoán vị trên $[n]$,
    còn $\mathrm{sgn}(\sigma)$ là dấu của hoán vị $\sigma$.
    Nó bằng $1$ khi số nghịch thế chẵn và bằng $-1$ khi số nghịch thế lẻ.

    Sau khi hiểu ý nghĩa tổ hợp của định thức,
    có thể dùng mô hình tổ hợp sau để chứng minh công thức Cauchy-Binet.
    Với ma trận $A$ cấp $n\times m$ và ma trận $B$ cấp $m\times n$,
    dựng đồ thị có hướng không chu trình $G=(V,E)$.
    Trong đó, tập đỉnh là $V=L\cup D\cup R$,
    với $L=\{l_i=(1,i):i\in[n]\}$,
    $D=\{d_i=(2,i):i\in[m]\}$ và $R=\{r_i=(3,i):i\in[n]\}$.
    Tập cạnh có hướng là $E=E_L\cup E_R$,
    trong đó $E_L=\{(l_i,d_j):i\in[n],j\in[m]\}$
    và $E_R=\{(d_j,r_i):j\in[m],i\in[n]\}$.
    Hai lớp cạnh này lần lượt có trọng số
    $w(l_i,d_j)=A_{i,j}$ và $w(d_j,r_i)=B_{j,i}$.
    Tương tự, xét các nhóm đường đi từ $L$ qua $D$ đến $R$
    mà các đường đi đôi một không dùng chung đỉnh.
    Đếm chúng theo trọng số, rồi lấy số nhóm có số giao điểm chẵn
    trừ đi số nhóm có số giao điểm lẻ.
    Hai vế của công thức Cauchy-Binet sẽ tính số này theo hai cách.

    Với vế trái, dựa trên đồ thị $G$ mô tả ở trên,
    dựng đồ thị mới $G'$ có tập đỉnh $V'=L\cup R$
    và tập cạnh $E'=\{(l_i,r_j):i,j\in[n]\}$.
    Gán cho cạnh $(l_i,r_j)$ trọng số $\sum_{k\in[m]}A_{i,k}B_{k,j}$,
    tức số đếm có trọng số của các đường đi đơn từ $l_i$ đến $r_j$ trong đồ thị gốc $G$.
    Trọng số cạnh này chính là $(AB)_{i,j}$.
    Điều này tương đương với việc rút gọn đồ thị ba lớp ở trên thành đồ thị hai lớp.

    Tuy nhiên, các nhóm đường đi trong đồ thị hai lớp $G'$,
    khi tính theo trọng số, không tương ứng một-một với các nhóm đường đi trong đồ thị ba lớp $G$.
    Trong đồ thị hai lớp, mỗi đường đi tương ứng với nhiều đường đi đơn trong đồ thị ba lớp.
    Vì vậy khi đếm nhóm đường đi của đồ thị hai lớp phải nhân các trọng số,
    tương đương với việc ghép các tập đường đi tương ứng trong đồ thị ba lớp.
    Phép ghép này tạo ra các trường hợp dùng chung điểm trung gian.

    Các cặp đường đi dùng chung điểm trung gian không đóng góp vào đáp án cuối cùng.
    Thật vậy, với $i_1< i_2$, $j_1< j_2$ và điểm trung gian $d$ bất kỳ,
    luôn tồn tại hai cặp đường đi đơn
    $(l_{i_1}\rightarrow d\rightarrow r_{j_1}, l_{i_2}\rightarrow d\rightarrow r_{j_2})$
    và
    $(l_{i_1}\rightarrow d\rightarrow r_{j_2}, l_{i_2}\rightarrow d\rightarrow r_{j_1})$.
    Hai nhóm đường đi này trong đồ thị ba lớp có tính chẵn lẻ số giao điểm đối nhau,
    vì nếu chỉ nhìn điểm đầu và điểm cuối thì hai nhóm đã hoán đổi điểm cuối.
    Do đó, khi đếm trên đồ thị hai lớp đã rút gọn,
    các đường đi dùng chung điểm trung gian sẽ triệt tiêu theo từng cặp.

    Với những trường hợp còn lại, nếu cố định điểm đầu và điểm cuối của hai đường đi,
    thì bất kể chọn các điểm trung gian thế nào,
    miễn là không chọn cùng một điểm, tính chẵn lẻ của số giao điểm của hai đường đi không đổi.
    Do đó, mọi nhóm đường đi trong đồ thị gốc $G$ tương ứng với cùng một nhóm đường đi trong $G'$
    đều có cùng tính chẵn lẻ.
    Vì thế, $\det(AB)$ cung cấp một cách tính hiệu số nhóm đường đi nói trên.

    Với vế phải, nó tương đương với việc duyệt mọi tổ hợp điểm trung gian có thể.
    Cho một tập điểm trung gian bất kỳ $S\subset D=[m]$ với $|S|=n$,
    xét riêng nhóm đường đi từ $L$ đến $S$ và nhóm đường đi từ $S$ đến $R$.
    Ghép chúng lại sẽ thu được nhóm đường đi từ $L$ đến $R$.
    Hợp thành của hai hoán vị ứng với hai nhóm đường đi trước
    chính là hoán vị ứng với nhóm đường đi sau,
    nên tích tính chẵn lẻ của hai nhóm đường đi trước
    bằng tính chẵn lẻ của nhóm đường đi sau.
    Do đó, với mọi nhóm đường đi có tập điểm trung gian là $S$,
    hiệu số đếm được đúng bằng tích của hiệu số đếm nhóm đường đi từ $L$ đến $S$
    và hiệu số đếm nhóm đường đi từ $S$ đến $R$.
    Lấy tổng trên mọi $S$ có thể, thu được vế phải,
    và nó chính là hiệu số nhóm đường đi đã nêu ở trên.

??? note "Chứng minh (góc nhìn đại số)"
    Chứng minh tổ hợp ở trên có thể dịch gần như từng câu thành chứng minh đại số.
    Phần này đưa ra một chứng minh đại số khác có tính kỹ thuật hơn,
    nhưng dùng vài kết quả quen thuộc.
    Khi $m< n$, định thức bằng không, vì

    $$
    \mathrm{rank}(AB)\le \min\{\mathrm{rank}(A),\mathrm{rank}(B)\}\le m< n.
    $$

    Khi $m=n$, công thức Cauchy-Binet chính là mệnh đề định thức của tích hai ma trận vuông bằng tích các định thức của chúng.

    Khi $m>n$, dùng đẳng thức

    $$
    x^{m-n}\det(xI_n+AB) = \det(xI_m+BA).
    $$

    Lại dùng kết quả đã biết:
    hệ số của $x^{n-k}$ trong $\det(xI_n+C)$
    là tổng mọi định thức con chính cấp $k$ của $C$.
    Vì vậy, so sánh hệ số hai vế của đẳng thức trên, có

    $$
    \det(AB) = \sum_{S\subset[m];~|S|=n}\det(BA)_{S,S} = \sum_{S\subset[m];~|S|=n}\det(B)_{S,[n]}\det(A)_{[n],S} = \sum_{S\subset[m];~|S|=n}\det(A)_{[n],S}\det(B)_{S,[n]}.
    $$

    Dấu bằng thứ hai dùng kết quả của trường hợp $m=n$.

### Mô tả cấu trúc đồ thị bằng ma trận liên thuộc

Với đồ thị có hướng $G=(V,E)$, số đỉnh là $n$, số cạnh là $m$,
và cạnh $e$ có trọng số $w(e)$.
Từ đó, có thể định nghĩa ma trận liên thuộc bậc ra cấp $m\times n$

$$
M^\mathrm{out}_{ij}=\begin{cases}
\sqrt{w(e_i)},&\exists u(e_i=(v_j,u)),\\
0,&\textrm{trường hợp còn lại},
\end{cases}
$$

và ma trận liên thuộc bậc vào cấp $m\times n$

$$
M^\mathrm{in}_{ij}=\begin{cases}
\sqrt{w(e_i)},&\exists u(e_i=(u,v_j)),\\
0,&\textrm{trường hợp còn lại}.
\end{cases}
$$

Mỗi hàng của chúng ghi lại một cạnh:
ma trận liên thuộc bậc ra $M^\mathrm{out}$ ghi lại điểm đầu của cạnh,
còn ma trận liên thuộc bậc vào $M^\mathrm{in}$ ghi lại điểm cuối của cạnh.

Tính toán đơn giản cho thấy

$$
D^\mathrm{out}(G) = (M^\mathrm{out})^T M^\mathrm{out},\ A(G) = (M^\mathrm{out})^T M^\mathrm{in},\ D^\mathrm{in}(G) = (M^\mathrm{in})^T M^\mathrm{in}.
$$

Do đó

$$
L^\mathrm{out}(G) = (M^\mathrm{out})^T (M^\mathrm{out}-M^\mathrm{in}),\ L^\mathrm{in}(G) = (M^\mathrm{in}-M^\mathrm{out})^T M^\mathrm{in}.
$$

Công thức Cauchy-Binet ở trên cho thấy định thức con chính của ma trận Laplace
thực chất là tổng của một loạt cấu trúc con.
Mỗi cấu trúc con phản ánh tính chất của đồ thị con tương ứng.

???+ note "Bổ đề 2"
    Với một đồ thị con $(W,S)$ của $G$, nếu nó thỏa mãn $|W|=|S|\le n$,
    thì đồ thị con $T=(V,S)$ là một rừng hướng về gốc với tập gốc $V\setminus W$
    khi và chỉ khi biểu thức tương ứng

    $$
    \det(M^\mathrm{out}_{S,W})\det(M^\mathrm{out}_{S,W}-M^\mathrm{in}_{S,W})
    $$

    khác không.
    Hơn nữa, khi biểu thức này khác không,
    nó nhất định bằng $\prod_{e\in S}w(e)$, ký hiệu là $w(T)$.

??? note "Chứng minh"
    Không mất tính tổng quát, giả sử $w(e)=1$.
    Điều này suy ra từ tính đa tuyến tính của định thức:
    từ mỗi hàng của mỗi định thức đều có thể tách ra một thừa số $\sqrt{w(e)}$,
    và tích các thừa số này là $w(T)$.

    Trước hết phân tích điều kiện để hai nhân tử bằng không.
    Nhân tử thứ nhất $\det(M^\mathrm{out}_{S,W})$ có mỗi hàng chứa nhiều nhất một số khác không,
    tức $+1$.
    Nếu có hàng nào toàn số không, định thức này bằng không.
    Do đó, định thức này khác không khi và chỉ khi mỗi hàng có đúng một $+1$.
    Nói cách khác, mỗi điểm trong $W$ đúng là điểm đầu của một cạnh trong $S$,
    và không có hai cạnh dùng chung cùng một điểm đầu.
    Để $T$ là rừng hướng về gốc với tập gốc $V\setminus W$,
    một điều kiện cần là mọi đỉnh không phải gốc có đúng một cha;
    điều này làm nhân tử trên khác không.
    Nhưng chiều ngược lại chưa đủ, vì còn phải bảo đảm không có chu trình,
    nên cần xét nhân tử thứ hai.
    Điểm cuối của các cạnh trong $S$ không bắt buộc nằm trong $W$.

    Giả sử nhân tử thứ nhất khác không.
    Khi đó, đồ thị con $T$ là rừng hướng về gốc khi và chỉ khi trong $T$ không có chu trình.
    Lúc này, mỗi hàng của hạng tử sau
    $\det(M^\mathrm{out}_{S,W}-M^\mathrm{in}_{S,W})$
    đều có một $+1$, nhưng có thể có một hoặc không có $-1$.
    Với cạnh có điểm cuối cũng nằm trong $W$,
    nếu điểm cuối của $e_i$ là điểm đầu của $e_j$,
    thì cộng hàng ứng với $e_j$ vào hàng ứng với $e_i$
    có thể khử $-1$ trong hàng của $e_i$.
    Có thể hình dung rằng khi đó hàng này mô tả đường đi đơn nối tiếp đầu-cuối $e_i$ và $e_j$.
    Nếu hàng này xuất hiện một $-1$ mới,
    điều đó nghĩa là điểm cuối của $e_j$ cũng nằm trong $W$,
    và vị trí của $-1$ chính là điểm cuối của $e_j$.
    Khi đó có thể tiếp tục tìm cạnh có điểm đầu là điểm cuối của $e_j$,
    rồi cộng tiếp hàng đó vào hàng hiện tại.
    Cạnh như vậy luôn tồn tại,
    vì đoạn trước đã chỉ ra rằng mỗi điểm trong $W$ đúng là điểm đầu của một cạnh trong $S$.

    Quá trình này tiếp tục cho đến khi hàng đó không còn xuất hiện $-1$,
    tương đương với việc liên tục thêm cạnh mới vào đường đi đơn
    $e_i\rightarrow e_j\rightarrow \cdots\rightarrow e_k$.
    Khi đó, nếu hàng chỉ còn một $+1$,
    nghĩa là điểm cuối của $e_k$ không thuộc tập đỉnh đã chọn $W$,
    và quá trình dừng lại.
    Nếu cạnh vừa thêm vào đúng lúc triệt tiêu $+1$ hiện có,
    tức hàng chỉ còn toàn số không,
    nghĩa là điểm cuối của cạnh mới $e_k$ chính là điểm đầu của cạnh ban đầu $e_i$,
    tức đã xuất hiện một chu trình.
    Vì vậy, điều kiện cần và đủ để không có chu trình
    là định thức này có thể được biến đổi bằng các thao tác trên
    về dạng mỗi hàng đều có đúng một $+1$.
    Vì vị trí các $+1$ này là điểm đầu của cạnh tương ứng với từng hàng,
    ma trận thu được thực chất chính là $\det(M^\mathrm{out}_{S,W})$.

    Tóm lại, nếu $T$ không phải rừng hướng về gốc,
    thì hoặc $\det(M^\mathrm{out}_{S,W})=0$,
    hoặc $\det(M^\mathrm{out}_{S,W}-M^\mathrm{in}_{S,W})=0$.
    Ngược lại, cả hai đều khác không,
    và tích của chúng bằng $\left(\det(M^\mathrm{out}_{S,W})\right)^2=1$.

### Định lý ma trận cây cho đồ thị có hướng có trọng số

Bây giờ có thể chứng minh kết quả chính của bài viết.
Các dạng định lý ma trận cây đã nêu ở trên đều là trường hợp đặc biệt của định lý này.

???+ note "Định lý 4 (định lý ma trận cây, cây hướng về gốc trong đồ thị có hướng có trọng số, dạng định thức)"
    Với $k$ bất kỳ, có

    $$
    \sum_{T\in\mathcal T^\mathrm{root}(G,k)}w(T)=\det L^\mathrm{out}(G)_{[n]\setminus\{k\},[n]\setminus\{k\}}.
    $$

    Trong đó, $\mathcal T^\mathrm{root}(G,k)$ là tập các cây khung có hướng của $G$ lấy $k$ làm gốc và hướng về gốc.

??? note "Chứng minh"
    Ký hiệu $W=[n]\setminus\{k\}$ là tập các đỉnh còn lại sau khi bỏ đỉnh $k$.
    Theo công thức Cauchy-Binet, vế phải có thể viết thành

    $$
    \det L^\mathrm{out}(G)_{W,W} = \sum_{S\subset[m];~|S|=n-1}\det(M^\mathrm{out}_{S,W})\det(M^\mathrm{out}_{S,W}-M^\mathrm{in}_{S,W}).
    $$

    Duyệt mọi $S$.
    Theo Bổ đề 2, khi và chỉ khi $T=(V,S)$ tạo thành một rừng hướng về gốc
    với tập gốc $V\setminus W=\{k\}$,
    tức $T$ là cây khung có hướng lấy $k$ làm gốc và hướng về gốc,
    vế phải cộng thêm một lượng $w(T)$.

Khi $w(e)=1$, trọng số của mỗi cây đều là $1$,
nên vế trái chính là số đếm tất cả các cây, tức $t^\mathrm{root}(G,k)$.
Như vậy thu được Định lý 2.
Tương tự như trên, có thể mở rộng trực tiếp kết luận sang cây khung có hướng hướng ra lá,
từ đó thu được Định lý 3.
Cuối cùng, để đếm cây khung trên đồ thị vô hướng, có thể dùng hệ quả sau.

???+ note "Hệ quả 4 (định lý ma trận cây, đồ thị vô hướng có trọng số, dạng định thức)"
    Với đồ thị vô hướng $G$ và $k$ bất kỳ, có

    $$
    \sum_{T\in\mathcal T(G)}w(T) = \det L(G)_{[n]\setminus\{k\},[n]\setminus\{k\}}.
    $$

    Trong đó, $\mathcal T(G)$ là tập các cây khung của $G$.
    Điều này cũng cho thấy mọi định thức con chính cấp $(n-1)$ của $L(G)$ đều bằng nhau.

??? note "Chứng minh"
    Với đồ thị vô hướng $G=(V,E)$, có thể xây dựng đồ thị có hướng $G'=(V,E')$,
    trong đó
    $E'=\{(v_i,v_j):(v_i,v_j)\in E\}\cup\{(v_j,v_i):(v_i,v_j)\in E\}$.
    Tức là mỗi cạnh vô hướng trong $G$ được tách thành hai cạnh có hướng ngược chiều nhau.
    Chọn một $k$ bất kỳ.
    Khi đó, cây khung có hướng lấy $k$ làm gốc và hướng về gốc trong $G'$
    tương ứng một-một với cây khung trong $G$.
    Từ đối tượng trước sang đối tượng sau, chỉ cần bỏ hướng cạnh và bỏ lựa chọn gốc.
    Từ đối tượng sau sang đối tượng trước,
    chỉ cần bắt đầu từ gốc đã chọn $k$ và định hướng từng cạnh theo chiều hướng về gốc.
    Do đó, lúc này

    $$
    \sum_{T\in\mathcal T(G)}w(T) = \sum_{T\in\mathcal T^\mathrm{root}(G',k)}w(T) = \det L^\mathrm{out}(G')_{[n]\setminus\{k\},[n]\setminus\{k\}} = \det L(G)_{[n]\setminus\{k\},[n]\setminus\{k\}}.
    $$

    Bước này dùng kết luận $L^\mathrm{out}(G')=L(G)$, điều này có thể kiểm tra trực tiếp.

### Dạng trị riêng

Vẫn bắt đầu bằng kết luận trên đồ thị có hướng.

???+ note "Định lý 5"
    Với đồ thị có hướng $G$, định nghĩa đa thức nhiều biến

    $$
    \chi(x_1,\cdots,x_n)=\det(\mathrm{diag}(x_1,\cdots,x_n)-L^\mathrm{out}(G)).
    $$

    Trong đó, $\mathrm{diag}(x_1,\cdots,x_n)$ chỉ ma trận đường chéo
    có các phần tử đường chéo là $x_1,\cdots,x_n$.
    Khi đó,

    $$
    (-1)^{n-r}[x_{k_1},\cdots,x_{k_r}]\chi(x_1,\cdots,x_n)
    $$

    bằng số đếm có trọng số của các rừng hướng về gốc của $G$ với tập gốc $\{k_1,\cdots,k_r\}$.

??? note "Chứng minh"
    Làm tương tự chứng minh Định lý 4.
    Nếu đặt $W=[n]\setminus\{k_1,\cdots,k_r\}$,
    thì hệ số trong định lý chính là $\det L^\mathrm{out}(G)_{W,W}$.
    Điều này suy ra trực tiếp từ khai triển Leibniz của định thức.
    Theo công thức Cauchy-Binet, nó bằng

    $$
    \det L^\mathrm{out}(G)_{W,W} = \sum_{S\subset[m];~|S|=n-r}\det(M^\mathrm{out}_{S,W})\det(M^\mathrm{out}_{S,W}-M^\mathrm{in}_{S,W}).
    $$

    Duyệt mọi $S$.
    Theo Bổ đề 2, khi và chỉ khi $T=(V,S)$ tạo thành một rừng hướng về gốc
    với tập gốc $V\setminus W=\{k_1,\cdots,k_r\}$,
    vế phải cộng thêm một lượng $w(T)$.

Thay $x$ vào mọi biến chưa biết, thu được đa thức đặc trưng của ma trận Laplace

$$
P(x) = \det(xI-L^\mathrm{out}(G)) = \chi(x,\cdots,x).
$$

???+ note "Bổ đề 3"
    Ma trận Laplace $L^\mathrm{out}(G)$ có ít nhất một trị riêng bằng không.

??? note "Chứng minh"
    Chỉ cần chứng minh định thức của nó bằng không.
    Tương tự chứng minh Định lý 4 và 5, lấy $W=\varnothing$.
    Khi đó độ lớn của định thức này đáng lẽ bằng số rừng hướng về gốc có không cây nào.
    Đối tượng này không tồn tại, nên định thức bằng không.

???+ note "Hệ quả 5"
    Với đồ thị có hướng $G$, tổng trọng số của mọi rừng hướng về gốc gồm $k$ cây bằng hệ số

    $$
    (-1)^{n-k}[x^k]P(x).
    $$

??? note "Chứng minh"
    Chỉ cần lấy tổng trên mọi cách chọn $k$ gốc.

Định nghĩa rừng khung $k$ thành phần là một đồ thị con khung của đồ thị,
sao cho đồ thị con này có $k$ thành phần liên thông và không có chu trình.

???+ note "Hệ quả 6"
    Ký hiệu tập các rừng khung $k$ thành phần của đồ thị vô hướng $G$ là $\mathcal T_k(G)$. Khi đó

    $$
    \sum_{T\in\mathcal T_k(G)}w(T)Q(T) = (-1)^{n-k}[x^k]P(x).
    $$

    Trong đó, $Q(T)$ là tích số đỉnh của từng thành phần liên thông trong rừng $T$.
    Đặc biệt, khi $k=1$, có $Q(T)=n$, nên

    $$
    n\sum_{T\in\mathcal T(G)}w(T) = \lambda_1\lambda_2\cdots\lambda_{n-1}.
    $$

??? note "Chứng minh"
    Làm tương tự chứng minh Hệ quả 4, có thể dùng trực tiếp kết luận của Hệ quả 5.
    Mỗi rừng hướng về gốc gồm $k$ cây trong đồ thị có hướng
    đều tương ứng với một rừng khung $k$ thành phần trong đồ thị vô hướng.
    Tuy nhiên, do mỗi rừng khung $k$ thành phần $T$ có $Q(T)$ cách chọn gốc,
    nó sẽ xuất hiện trong $Q(T)$ rừng hướng về gốc của đồ thị có hướng.

## Ứng dụng

### Công thức Cayley

???+ note "Hệ quả 7 (Cayley)"
    Số cây không gốc có nhãn kích thước $n$ là $n^{n-2}$.

??? note "Chứng minh"
    Tương đương, chỉ cần tính số cây khung của đồ thị đầy đủ trên $n$ đỉnh là $n^{n-2}$.
    Để làm điều này, viết ma trận Laplace

    $$
    L(G) = \left(\begin{matrix} n-1 & -1 & \cdots & -1 \\ -1 & n-1 & \cdots & -1 \\ \vdots & \vdots & \ddots & \vdots \\ -1 & -1 & \cdots & n-1  \end{matrix}\right)_{n\times n}.
    $$

    Tính một định thức con chính bất kỳ của nó, có

    $$
    \det(nI_{n-1}-{\bf 1}{\bf 1}^T) = n^{n-1}\det(I_{n-1}-n^{-1}{\bf 1}{\bf 1}^T) = n^{n-1}(1-n^{-1}{\bf 1}^T{\bf 1}) = n^{n-1}(1-(n-1)/n) = n^{n-2}.
    $$

    Áp dụng Định lý 1 sẽ thu được kết luận.

### Định lý BEST

Kiến thức chuẩn bị: [đồ thị Euler](./euler.md)

Định lý này liên hệ số chu trình Euler trong đồ thị Euler có hướng
với số cây khung có hướng hướng về gốc của đồ thị đó.
Từ đó có thể giải quyết bài toán đếm chu trình Euler trong đồ thị có hướng.
Bài toán đếm chu trình Euler trong đồ thị vô hướng bất kỳ là NP-đầy đủ.

Khi cài đặt thuật toán này, trước hết nên kiểm tra đồ thị đã cho có phải đồ thị Euler hay không,
loại bỏ mọi đỉnh bậc không,
sau đó dựng đồ thị để tính số cây khung có hướng hướng về gốc,
rồi dùng định lý BEST để lấy số chu trình Euler.
Nếu số chu trình Euler cần tìm yêu cầu bắt đầu từ một đỉnh cho trước,
cần nhân đáp án thêm với bậc ra của đỉnh đó,
tương đương với việc duyệt cạnh đầu tiên trong chu trình.

Trước khi chứng minh định lý BEST, cần biết kết luận sau.

???+ note "Tính chất (điều kiện để đồ thị có hướng có chu trình Euler)"
    Một đồ thị có hướng có chu trình Euler khi và chỉ khi các đỉnh có bậc khác không liên thông mạnh, và mọi đỉnh đều có bậc ra bằng bậc vào.

Với đồ thị Euler, vì bậc ra và bậc vào bằng nhau,
có thể bỏ chỉ số trên và ký hiệu là $\mathrm{deg}(v)$.
Định lý BEST có thể phát biểu như sau.

???+ note "Định lý 6 (định lý BEST)"
    Giả sử $G$ là đồ thị Euler có hướng, và $k$ là đỉnh bất kỳ.
    Khi đó tổng số chu trình Euler khác nhau của $G$, ký hiệu $\mathrm{ec}(G)$, là

    $$
    \mathrm{ec}(G) = t^\mathrm{root}(G,k)\prod_{v\in V}(\deg (v) - 1)!.
    $$

    Điều này cũng cho thấy với mọi hai đỉnh $k, k'$ của đồ thị Euler $G$,
    đều có $t^\mathrm{root}(G,k)=t^\mathrm{root}(G,k')$.

??? note "Chứng minh"
    Ý tưởng chính của chứng minh là xây dựng một tương ứng giữa
    chu trình Euler bắt đầu từ $k$,
    cây khung có hướng lấy $k$ làm gốc và hướng về gốc,
    cùng các hoán vị của các cạnh ra tại từng đỉnh.
    Sau khi chỉ định đỉnh bắt đầu của chu trình Euler,
    số cần chứng minh phải bằng

    $$
    \mathrm{deg}(k)\mathrm{ec}(G) = t^\mathrm{root}(G,k)\deg(k)!\prod_{v\neq k}(\deg (v) - 1)!.
    $$

    Ý nghĩa tổ hợp của số đếm này ứng với cấu trúc sau.
    Với một chu trình Euler bắt đầu tại $k$,
    dựa trên thứ tự xuất hiện của từng cạnh trong chu trình, có thể xây dựng

    -   một cây khung có hướng lấy $k$ làm gốc và hướng về gốc, gồm các cạnh ra cuối cùng tại mọi đỉnh không phải gốc, tức $t^\mathrm{root}(G,k)$,
    -   thứ tự hoán vị của mọi cạnh ra tại gốc $k$, tức $\mathrm{deg}(k)!$, và
    -   thứ tự hoán vị của mọi cạnh ra còn lại tại đỉnh không phải gốc $v\neq k$ sau khi bỏ cạnh ra cuối cùng, tức $(\mathrm{deg}(v)-1)!$.

    Cần chỉ ra rằng ánh xạ do cấu trúc này tạo ra là song ánh.

    Một mặt, cho một chu trình Euler,
    cần chứng minh các cạnh ra cuối cùng tại mọi đỉnh không phải gốc
    tạo thành một cây khung có hướng hướng về gốc.
    Theo cách dựng, trong cây mỗi đỉnh không phải gốc đúng là chỉ có một cạnh ra,
    nên chỉ cần chứng minh các cạnh ra này không tạo chu trình.
    Nếu sắp xếp tất cả đỉnh theo thứ tự xuất hiện lần cuối trong chu trình Euler,
    thì cạnh ra cuối cùng của một đỉnh không phải gốc
    trỏ tới một đỉnh xuất hiện muộn hơn nó trong thứ tự này.
    Nếu tồn tại chu trình, thì trong chu trình đó có một đỉnh đứng sau cùng theo thứ tự;
    vì nó nằm trong chu trình, nó lại trỏ đến một đỉnh không đứng sau nó,
    mâu thuẫn với lập luận trên.
    Vì vậy, các cạnh ra cuối cùng của các đỉnh không phải gốc
    tạo thành cây khung có hướng hướng về gốc.

    Mặt khác, cho một cây khung có hướng hướng về gốc bất kỳ
    và thứ tự hoán vị của các cạnh ra còn lại,
    có thể khôi phục một chu trình Euler sao cho sau khi áp dụng cấu trúc trên,
    chu trình Euler đó cho lại đúng cây khung có hướng và thứ tự cạnh ra đã cho.
    Để làm điều này, chỉ cần xuất phát từ gốc $k$.
    Mỗi khi đến một đỉnh, dựa trên thứ tự hoán vị các cạnh ra đã cho tại đỉnh đó,
    chọn cạnh ra chưa đi qua và đứng sớm nhất làm cạnh lần này của chu trình Euler.
    Nếu mọi cạnh ra trong hoán vị tại đỉnh đó đều đã đi qua,
    thì chọn cạnh ra của đỉnh đó trong cây khung có hướng làm cạnh lần này.
    Vì đồ thị là đồ thị Euler, bậc vào của mỗi đỉnh bằng bậc ra,
    nên quá trình này không dừng ở đỉnh không phải gốc,
    tức đường đi thu được đúng là một chu trình.
    Để chứng minh đường đi thu được là chu trình Euler hợp lệ,
    chỉ cần chứng minh quá trình này có thể đi qua mọi cạnh.

    Nếu không, tồn tại một cạnh ra nào đó của một đỉnh $v$ chưa được đi qua.
    Xét đỉnh $v$.
    Đỉnh $v$ không thể là gốc, vì cuối cùng quá trình dừng ở gốc;
    nếu gốc vẫn còn cạnh ra chưa dùng, điều đó mâu thuẫn với việc quá trình đã dừng.
    Vì vậy, $v$ không phải gốc.
    Theo quá trình mô tả ở trên,
    chỉ cần đỉnh không phải gốc $v$ còn bất kỳ cạnh ra nào chưa dùng,
    thì cạnh ra $e$ của đỉnh không phải gốc đó trong cây vẫn chưa dùng.
    Ký hiệu $e=(v,u)$.
    Vì có một cạnh vào của $u$ chưa được đi qua,
    và bậc ra của $u$ bằng bậc vào,
    suy ra $u$ có một cạnh ra chưa được đi qua.
    Sau đó, có thể xét đỉnh $u$ theo cách tương tự.
    Lập luận này chuyển đỉnh đang xét từ $v$ sang $u$,
    tức đi một bước dọc theo cây khung có hướng về phía gốc của cây.
    Bằng quy nạp, lúc này tồn tại một cạnh ra của gốc $k$ chưa được đi qua.
    Ở trên đã chỉ ra điều này là không thể, nên thu được mâu thuẫn.
    Điều này chứng minh đường đi ở đoạn trước đúng là chu trình Euler hợp lệ.

    Có thể kiểm tra các ánh xạ này đều là đơn ánh, nên chúng cũng là song ánh. Mệnh đề được chứng minh.

## Cài đặt

Dựa vào đồ thị, viết ma trận Laplace, xóa một hàng và một cột,
rồi tính định thức của ma trận thu được.
Có thể tính định thức bằng khử Gauss-Jordan.

Ví dụ, số cây khung của một đồ thị hình vuông:

$$
\begin{pmatrix}
2 & 0 & 0 & 0 \\
0 & 2 & 0 & 0 \\
0 & 0 & 2 & 0 \\
0 & 0 & 0 & 2 \end{pmatrix}-\begin{pmatrix}
0 & 1 & 0 & 1 \\
1 & 0 & 1 & 0 \\
0 & 1 & 0 & 1 \\
1 & 0 & 1 & 0 \end{pmatrix}=\begin{pmatrix}
2 & -1 & 0 & -1 \\
-1 & 2 & -1 & 0 \\
0 & -1 & 2 & -1 \\
-1 & 0 & -1 & 2 \end{pmatrix}
$$

$$
\begin{vmatrix}
2 & -1 & 0 \\
-1 & 2 & -1 \\
0 & -1 & 2 \end{vmatrix} = 4
$$

Có thể dùng khử Gauss-Jordan để giải, độ phức tạp thời gian là $O(n^3)$.

??? note "Cài đặt"
    ```cpp
    #include <algorithm>
    #include <cassert>
    #include <cmath>
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    using namespace std;
    constexpr int MOD = 100000007;
    constexpr double eps = 1e-7;

    struct matrix {
      static constexpr int MAXN = 20;
      int n, m;
      double mat[MAXN][MAXN];

      matrix() { memset(mat, 0, sizeof(mat)); }

      void print() {
        cout << "MATRIX " << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            cout << mat[i][j] << "\t";
          }
          cout << endl;
        }
      }

      void random(int n) {
        this->n = n;
        this->m = n;
        for (int i = 0; i < n; i++)
          for (int j = 0; j < n; j++) mat[i][j] = rand() % 100;
      }

      void initSquare() {
        this->n = 4;
        this->m = 4;
        memset(mat, 0, sizeof(mat));
        mat[0][1] = mat[0][3] = 1;
        mat[1][0] = mat[1][2] = 1;
        mat[2][1] = mat[2][3] = 1;
        mat[3][0] = mat[3][2] = 1;
        mat[0][0] = mat[1][1] = mat[2][2] = mat[3][3] = -2;
        this->n--;  // xóa một hàng
        this->m--;  // xóa một cột
      }

      double gauss() {
        double ans = 1;
        for (int i = 0; i < n; i++) {
          int sid = -1;
          for (int j = i; j < n; j++)
            if (abs(mat[j][i]) > eps) {
              sid = j;
              break;
            }
          if (sid == -1) continue;
          if (sid != i) {
            for (int j = 0; j < n; j++) {
              swap(mat[sid][j], mat[i][j]);
              ans = -ans;
            }
          }
          for (int j = i + 1; j < n; j++) {
            double ratio = mat[j][i] / mat[i][i];
            for (int k = 0; k < n; k++) {
              mat[j][k] -= mat[i][k] * ratio;
            }
          }
        }
        for (int i = 0; i < n; i++) ans *= mat[i][i];
        return abs(ans);
      }
    };

    int main() {
      srand(1);
      matrix T;
      // T.random(2);
      T.initSquare();
      T.print();
      double ans = T.gauss();
      T.print();
      cout << ans << endl;
    }
    ```

## Bài tập ví dụ

???+ note "Ví dụ 1: [HEOI2015 - Phòng của Z nhỏ](https://loj.ac/problem/2122)"
    **Lời giải** Đây là bài áp dụng trực tiếp định lý ma trận cây.
    Xem mỗi phòng trống là một nút, dựng đồ thị theo thông tin đầu vào,
    thu được ma trận Laplace rồi xóa một hàng $i$ và cột $i$ bất kỳ của $L$.
    Sau đó tính định thức của định thức con này.
    Cách tính định thức là khử Gauss về ma trận tam giác trên rồi lấy tích đường chéo.
    Ngoài ra, bài này cần khử Gauss trên vành số nguyên modulo $k$, tức $\mathbb{Z}_k$,
    nên có thể dùng thuật toán Euclid.

???+ note "Ví dụ 2: [FJOI2007 - Virus hình bánh xe](https://www.luogu.com.cn/problem/P2144)"
    **Lời giải** Bài này có nhiều cách giải;
    dùng định lý ma trận cây là cách trực tiếp nhất.
    Khi đầu vào là $n$, có thể viết ma trận Laplace cấp $n+1$ của nó như sau:

    $$
    L_n = \begin{bmatrix}
    n&  -1&  -1&  -1&  \cdots&  -1&  -1\\
    -1&  3&  -1&  0&  \cdots&  0&  -1\\
    -1&  -1&  3&  -1&  \cdots&  0&  0\\
    -1&  0&  -1&  3&  \cdots&  0&  0\\
    \vdots&  \vdots&  \vdots&  \vdots&  \ddots&  \vdots&  \vdots\\
    -1&  0&  0&  0&  \cdots&  3&  -1\\
    -1&  -1&  0&  0&  \cdots&  -1&  3\\
    \end{bmatrix}_{n+1}
    $$

    Chỉ cần tính định thức con cấp $n$ của nó; phần còn lại là tính toán số lớn.

??? note "Ví dụ 2+"
    Tăng cường dữ liệu của Ví dụ 2: yêu cầu $n\leq 100000$, nhưng đáp án lấy modulo 1000007. Bài này cần một số kiến thức đại số tuyến tính.

    **Lời giải** Sau khi suy ra công thức truy hồi, dùng lũy thừa ma trận nhanh là có thể tính đáp án.

    Quá trình suy ra công thức truy hồi:

    Ma trận thu được sau khi xóa hàng 1 và cột 1 của $L_n$ có quy luật đều đặn, nên thực chất đang tính định thức của ma trận

    $$
    M_n = \begin{bmatrix}
    3&  -1&  0&  \cdots&  0&  -1\\
    -1&  3&  -1&  \cdots&  0&  0\\
    0&  -1&  3&  \cdots&  0&  0\\
    \vdots&  \vdots&  \vdots&  \ddots&  \vdots&  \vdots\\
    0&  0&  0&  \cdots&  3&  -1\\
    -1&  0&  0&  \cdots&  -1&  3\\
    \end{bmatrix}_{n}
    $$

    Khai triển định thức của $M_n$ theo cột đầu tiên, thu được

    $$
    \det M_n = 3\det \begin{bmatrix}
    3&  -1&  \cdots&  0&  0\\
    -1&  3&  \cdots&  0&  0\\
    \vdots&  \vdots&  \ddots&  \vdots&  \vdots\\
    0&  0&  \cdots&  3&  -1\\
    0&  0&  \cdots&  -1&  3\\
    \end{bmatrix}_{n-1} + \det\begin{bmatrix}
    -1&  0&  \cdots&  0&  -1\\
    -1&  3&  \cdots&  0&  0\\
    \vdots&  \vdots&  \ddots&  \vdots&  \vdots\\
    0&  0&  \cdots&  3&  -1\\
    0&  0&  \cdots&  -1&  3\\
    \end{bmatrix}_{n-1} + (-1)^n \det\begin{bmatrix}
    -1&  0&  \cdots&  0&  -1\\
    3&  -1&  \cdots&  0&  0\\
    -1&  3&  \cdots&  0&  0\\
    \vdots&  \vdots&  \ddots&  \vdots&  \vdots\\
    0&  0&  \cdots&  3&  -1\\
    \end{bmatrix}_{n-1}
    $$

    Ký hiệu định thức của ba ma trận trên lần lượt là $d_{n-1}, a_{n-1}, b_{n-1}$.

    Vì $d_n$ là định thức ba đường chéo,
    dùng cách khai triển tương tự có thể thu được công thức truy hồi $d_n=3d_{n-1}-d_{n-2}$.
    Tương tự, khai triển cũng cho $a_{n-1}=-d_{n-2}-1$
    và $(-1)^n b_{n-1}=-d_{n-2}-1$.
    Thay các công thức truy hồi này vào biểu thức trên, thu được:

    $$
    \det M_n = 3d_{n-1}-2d_{n-2}-2
    $$

    $$
    d_n = 3d_{n-1}-d_{n-2}
    $$

    Từ đó đoán rằng $\det M_n$ cũng là một truy hồi tuyến tính bậc hai không thuần nhất.
    Dùng phương pháp hệ số bất định, thu được công thức truy hồi cuối cùng:

    $$
    \det M_n = 3\det M_{n-1} - \det M_{n-2} + 2
    $$

    Viết lại thành $(\det M_n+2) = 3(\det M_{n-1}+2) - (\det M_{n-2} + 2)$,
    rồi dùng lũy thừa ma trận nhanh để tính đáp án.

???+ note "Ví dụ 3: [BZOJ3659 - WHICH DREAMED IT](https://hydro.ac/p/bzoj-P3659)"
    **Lời giải** Bài này áp dụng trực tiếp định lý BEST.
    Do đề bài quy định hai cách hoàn thành nhiệm vụ được xem là khác nhau
    khi và chỉ khi thứ tự sử dụng chìa khóa khác nhau,
    với mỗi chu trình Euler, phòng số 1 có thể xuất phát theo bất kỳ cạnh ra nào.
    Vì vậy đáp án còn phải nhân với bậc ra của phòng số 1.

???+ note "Ví dụ 4: [Liên tuyển tỉnh 2020 A - Bài tập](https://loj.ac/p/3304)"
    **Lời giải** Trước hết cần dùng đảo ngược Mobius
    để chuyển thành bài toán tính tổng trọng số cạnh của mọi cây khung.
    Vì phần này không liên quan nhiều đến bài viết nên lược bỏ.

    Viết các hạng tử của định thức dưới dạng $w_ix+1$.
    Đáp án cuối cùng là hệ số bậc nhất của định thức,
    vì về bản chất đáp án là tổng của số cây khung sau khi chỉ định một cạnh
    nhân với trọng số của cạnh đó.
    Khi đó cạnh được nhân vào hệ số bậc nhất chính là cạnh được chỉ định.
    Lúc này có thể bỏ qua các hạng tử bậc cao hơn một, độ phức tạp $O(n^3)$.

    [Tập huấn tuyển chọn tỉnh Bắc Kinh 2019 - Đếm cây khung](https://www.luogu.com.cn/problem/P5296)
    là trường hợp tổng quát hơn:
    tính tổng lũy thừa bậc $k$ của tổng trọng số cây khung.
    Có thể dùng cách tương tự để xây dựng các hạng tử của định thức;
    xem lời giải trên Luogu để biết chi tiết.
