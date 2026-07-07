author: 2008verser, aofall, CoelacanthusHex, Early0v0, Great-designer, Marcythm, Persdre, shuzhouliu, Tiphereth-A, Enter-tainer, gavinliu266, gi-b716, hjsjhn, Ir1d, MegaOwIer, wjy-yy, c-forrest

Hoán vị và cách sắp xếp là những khái niệm rất thường gặp trong nhiều loại bài toán.

???+ warning "Bài này không bàn về số chỉnh hợp"
    Chủ đề của bài này là hoán vị toàn phần, không phải số chỉnh hợp trong tổ hợp. Nội dung liên quan đến số chỉnh hợp nên xem tại [Tổ hợp](./combinatorics/combination.md).

???+ info "Quy ước"
    Trong bài này, nếu không nói rõ, các tập hợp đều được xem là hữu hạn.

<span id="định-nghĩa"></span>
## Định nghĩa

Một song ánh, tức tương ứng một-một, $\sigma$ từ tập hợp $X$ đến chính nó được gọi là một **hoán vị** (permutation) của $X$. Nếu trên tập hợp $X$ còn có quan hệ [thứ tự toàn phần](./order-theory.md#quan-hệ-hai-ngôi), thì một hoán vị của nó cũng thường được gọi là một **cách sắp xếp (toàn phần)**. Thứ tự toàn phần này được gọi là thứ tự tự nhiên trên tập hợp.

??? info "\"Hoán vị\" và \"cách sắp xếp\""
    Trong tài liệu gốc tiếng Trung, "hoán vị" thường chỉ việc thay đổi thứ tự của các phần tử, còn "cách sắp xếp" thường chỉ việc xếp các phần tử thành một dãy. Khi giữa các phần tử có thứ tự tự nhiên, hai khái niệm này là một: "cách sắp xếp" có thể xem là kết quả của "hoán vị"; ngược lại, so với thứ tự tự nhiên của các phần tử, thứ tự các phần tử trong "cách sắp xếp" xác định "hoán vị". Trong bài này, khi dùng thuật ngữ "cách sắp xếp", ngầm định rằng tập hợp có thứ tự tự nhiên, nên sẽ không cố ý phân biệt hai khái niệm này.

    Các phần tử không có thứ tự tự nhiên vẫn có thể được "sắp xếp". Kiểu "sắp xếp" này thường xuất hiện trong các bài toán đếm tổ hợp. Nội dung đó nằm ngoài phạm vi bài này.

Giả sử kích thước của tập hợp $X$ là $n$. Khi đó số hoán vị trên $X$ là $n!$. Đặc biệt, $0!=1$, nghĩa là trên tập rỗng có đúng một hoán vị, chính là hoán vị rỗng.

???+ info "Ký hiệu"
    Hoán vị xét quan hệ tương ứng giữa các phần tử, và không quan tâm bản thân các phần tử cụ thể là gì. Vì vậy, khi xét một tập hợp có kích thước $n$, thường giả định tập hợp đang xét là $\{1,2,\cdots,n\}$; khi cần thứ tự tự nhiên trên tập hợp, thường dùng thứ tự tự nhiên trên các số tự nhiên.

<span id="cách-biểu-diễn"></span>
## Cách biểu diễn

Hoán vị có nhiều cách biểu diễn. Phần này dùng hoán vị sau làm ví dụ để thảo luận các cách biểu diễn khác nhau.

$$
\sigma(1) = 2,\
\sigma(2) = 6,\
\sigma(3) = 5,\
\sigma(4) = 4,\
\sigma(5) = 3,\
\sigma(6) = 1.
$$

<span id="ký-hiệu-hai-dòng"></span>
### Ký hiệu hai dòng

Một hoán vị trên tập hợp $X=\{x_1,x_2,\cdots,x_n\}$ có thể được biểu diễn thành

$$
\sigma=\begin{pmatrix}x_1&x_2&\cdots&x_n\\
x_{p_1}&x_{p_2}&\cdots&x_{p_n}
\end{pmatrix}.
$$

Ký hiệu này biểu thị rằng hoán vị $\sigma$ ánh xạ phần tử $x_i$ đến $x_{p_i}$. Điều kiện cần là $X=\{x_{p_1},x_{p_2},\cdots,x_{p_n}\}$. Trong ký hiệu hai dòng của hoán vị, thứ tự xuất hiện của các phần tử ở dòng đầu không quan trọng; điều quan trọng là quan hệ tương ứng giữa hai dòng.

Chẳng hạn, ví dụ ở trên có thể viết bằng ký hiệu hai dòng là

$$
\sigma=
\begin{pmatrix}
1 & 2 & 3 & 4 & 5 & 6 \\
2 & 6 & 5 & 4 & 3 & 1
\end{pmatrix},
$$

và cũng có thể viết là

$$
\sigma=
\begin{pmatrix}
6 & 5 & 4 & 3 & 2 & 1 \\
1 & 3 & 4 & 5 & 6 & 2
\end{pmatrix}.
$$

<span id="ký-hiệu-một-dòng"></span>
### Ký hiệu một dòng

Trong nhiều trường hợp, trên tập hợp $X$ có thứ tự tự nhiên. Nếu trong ký hiệu hai dòng, dòng đầu được ngầm định là viết theo thứ tự tự nhiên và bị bỏ qua, thì hoán vị có thể được biểu diễn thành

$$
\sigma=\sigma(1)\sigma(2)\cdots\sigma(n).
$$

Cách này gần với khái niệm sắp xếp trong ngôn ngữ tự nhiên hơn. Vì vậy, đôi khi thuật ngữ cách sắp xếp cũng được dùng để gọi bộ có thứ tự này.

Ví dụ ở trên, bằng ký hiệu một dòng, có thể viết là

$$
\sigma=265431.
$$

Ký hiệu một dòng như vậy thường được dùng để so sánh thứ tự giữa các cách sắp xếp khác nhau.

<span id="biểu-diễn-bằng-chu-trình"></span>
### Biểu diễn bằng chu trình

Hoán vị còn có một cách biểu diễn gọn hơn, gọi là biểu diễn chu trình của hoán vị. Cách này biểu diễn hoán vị thành tích của một loạt các chu trình đôi một không giao nhau. Dưới đây là các bước để viết một hoán vị cho trước dưới dạng chu trình.

Với một hoán vị $\sigma$ cho trước, có thể viết thành biểu diễn chu trình theo các bước sau:

1.  Nếu trong $X$ vẫn còn phần tử chưa được viết ra, viết một dấu ngoặc trái và viết một phần tử bất kỳ như vậy;
2.  Khi phần tử vừa viết trước đó là $x$,
    -   nếu $\sigma(x)$ đã được viết ở phía trước, viết dấu ngoặc phải và quay lại bước 1;
    -   nếu $\sigma(x)$ chưa được viết, viết $\sigma(x)$ và tiếp tục bước 2;
3.  Kết thúc khi mọi phần tử của $X$ đều đã được viết.

Mỗi cặp ngoặc là một chu trình. Số phần tử trong ngoặc được gọi là độ dài của chu trình tương ứng. Trong thực tế, các chu trình có độ dài bằng một thường được bỏ qua.

Ví dụ ở trên, bằng biểu diễn chu trình, có thể viết là

$$
\sigma=(126)(35)(4)=(126)(35).
$$

Trong phép biến đổi đồng nhất, mọi chu trình đều có độ dài bằng một, và thường được ký hiệu là $(1)$ thay vì bỏ qua tất cả.

<span id="hợp-thành"></span>
## Hợp thành

Hợp thành của các hoán vị chính là hợp thành của các ánh xạ. Hợp thành của hoán vị cũng thường được gọi là phép nhân hoán vị.

Với hai hoán vị cho trước

$$
\sigma=\begin{pmatrix}x_1&x_2&\cdots&x_n\\ x_{p_1}&x_{p_2}&\cdots&x_{p_n}\end{pmatrix},\ \pi=\begin{pmatrix}x_{p_1}&x_{p_2}&\cdots&x_{p_n}\\ x_{q_1}&x_{q_2}&\cdots&x_{q_n}\end{pmatrix},
$$

thì tích $\pi\circ\sigma$ của chúng có giá trị là

$$
\pi\circ\sigma=\begin{pmatrix}x_1&x_2&\cdots&x_n\\
x_{q_1}&x_{q_2}&\cdots&x_{q_n}\end{pmatrix}.
$$

Nói đơn giản là ánh xạ qua $\sigma$ trước, rồi ánh xạ qua $\pi$. Lưu ý rằng trong ký hiệu hai dòng ở trên, thứ tự dòng thứ hai của ánh xạ bên trong $\sigma$ trùng với thứ tự dòng đầu của ánh xạ bên ngoài $\pi$.

Vì về bản chất $\sigma$ và $\pi$ là hai ánh xạ, nên $(\pi\circ\sigma)(x)=\pi(\sigma(x))$. Thứ tự thực hiện hợp thành hoán vị là từ phải sang trái. Phép nhân hoán vị không thỏa mãn tính giao hoán, vì vậy tính theo thứ tự sai có thể dẫn đến kết quả sai.

Tích của nhiều hoán vị liên tiếp được gọi là lũy thừa của cách sắp xếp; có thể dùng [lũy thừa nhanh](./binary-exponentiation.md#hoán-vị-nhiều-lần) để tăng tốc tính toán.

<span id="hoán-vị-nghịch-đảo"></span>
### Hoán vị nghịch đảo

Vì hoán vị là song ánh, mọi hoán vị đều có hoán vị nghịch đảo tương ứng.

Với hoán vị cho trước

$$
\sigma=\begin{pmatrix}x_1&x_2&\cdots&x_n\\ x_{p_1}&x_{p_2}&\cdots&x_{p_n}\end{pmatrix},
$$

hoán vị nghịch đảo của nó là

$$
\sigma^{-1}=\begin{pmatrix}x_{p_1}&x_{p_2}&\cdots&x_{p_n}\\x_1&x_2&\cdots&x_n\end{pmatrix}.
$$

Trong biểu diễn chu trình, chỉ cần lấy nghịch đảo của từng chu trình là thu được hoán vị nghịch đảo của hoán vị ban đầu; để lấy nghịch đảo của một chu trình, chỉ cần đảo ngược thứ tự viết các phần tử. Chẳng hạn, biểu diễn chu trình của hoán vị nghịch đảo của ví dụ $\sigma$ ở trên là

$$
\sigma^{-1} = (621)(53) = (162)(35).
$$

Một cách sắp xếp của $1\sim n$ và dãy thứ hạng của từng phần tử trong cách sắp xếp đó là hai cách sắp xếp nghịch đảo của nhau.

<span id="chu-trình"></span>
## Chu trình

Bản thân **chu trình** (cycle) là một hoán vị đặc biệt. Đặc trưng của chu trình là: từ bất kỳ điểm $x$ nào trong chu trình, có thể nhận được một điểm $y$ khác trong chu trình bằng cách áp dụng lặp lại hoán vị $\sigma$. Chu trình độ dài $k$ còn được gọi là **$k$-chu trình** ($k$-cycle). Áp dụng lặp lại một $k$-chu trình $k$ lần sẽ thu được phép biến đổi đồng nhất, tức là mọi phần tử trở về vị trí ban đầu.

Biểu diễn chu trình của hoán vị có thể xem là viết hoán vị thành tích của các hoán vị đặc biệt này, tức các chu trình, nên biểu diễn chu trình của hoán vị cũng có thể xem là **phân rã chu trình** (cycle decomposition) của hoán vị. Với mỗi hoán vị, cách phân rã thành tích các chu trình là duy nhất nếu không kể thứ tự các chu trình. Có thể xem chu trình là đơn vị cơ bản cấu thành nên hoán vị.

Phân rã chu trình của hoán vị có ý nghĩa hình học trực quan. Nếu xem mỗi cặp có thứ tự $(x,\sigma(x))$ trong hoán vị trên tập hợp $S$ là một cạnh của đồ thị có hướng có tập đỉnh là $S$, thì các chu trình chính là các vòng trên đồ thị này. Nếu hoán vị $\sigma$ có thể phân rã thành $m$ chu trình, điều đó có nghĩa là đồ thị có hướng tương ứng có tổng cộng $m$ vòng, bao gồm cả khuyên. Các vòng này đôi một không giao nhau.

<span id="điểm-bất-động"></span>
### Điểm bất động

$1$-chu trình chính là **điểm bất động** (fixed point) của hoán vị. Với một hoán vị $\sigma$ trên tập hợp $X$, thường dùng $X^\sigma$ để biểu thị tập các điểm bất động của $\sigma$, tức là $X^\sigma=\{x\in X:\sigma(x)=x\}$.

<span id="phép-đổi-chỗ"></span>
### Phép đổi chỗ

$2$-chu trình cũng được gọi là **phép đổi chỗ** (transposition). Nói cách khác, phép đổi chỗ là hoán vị chỉ trao đổi vị trí của một cặp phần tử. Biểu diễn chu trình của nó là $(x_ix_j)$, biểu thị việc trao đổi vị trí của $x_i$ và $x_j$.

Mọi hoán vị đều có thể viết thành tích của một loạt các phép đổi chỗ. Điều này tương đương với việc bất kỳ cách sắp xếp theo thứ tự nào cũng có thể được khôi phục thành thứ tự đúng chỉ định bằng một loạt thao tác hoán đổi hai phần tử. Đây chính là việc các thuật toán sắp xếp dựa trên hoán đổi đang làm.

Hơn nữa, tính đúng đắn của [thuật toán sắp xếp nổi bọt](../basic/bubble-sort.md) thực chất cho thấy mọi hoán vị đều có thể viết thành tích của một loạt các phép đổi chỗ kề nhau. **Phép đổi chỗ kề nhau** (adjacent transposition) là phép đổi chỗ chỉ trao đổi hai phần tử liền kề.

<span id="tính-chất"></span>
## Tính chất

Trong ứng dụng, thường cần quan tâm đến tính chất của từng hoán vị riêng lẻ.

<span id="tính-chẵn-lẻ"></span>
### Tính chẵn lẻ

Cách phân rã một chu trình thành các phép đổi chỗ không phải là duy nhất. Ví dụ,

$$
(123)=(13)(12)=(12)(23)=(12)(13)(12)(13).
$$

Tuy nhiên, khi phân rã một hoán vị thành một loạt các phép đổi chỗ, tính chẵn lẻ của số phép đổi chỗ cần dùng là cố định. Tính chẵn lẻ của số phép đổi chỗ trong một phân rã như vậy được gọi là **tính chẵn lẻ** (parity) của hoán vị.

Hoán vị có thể phân rã thành tích của một số chẵn phép đổi chỗ được gọi là hoán vị chẵn; hoán vị có thể phân rã thành tích của một số lẻ phép đổi chỗ được gọi là hoán vị lẻ. Khi $n\ge2$, số hoán vị lẻ và số hoán vị chẵn có kích thước $n$ là bằng nhau.

<span id="dấu"></span>
### Dấu

Dựa trên tính chẵn lẻ của hoán vị, có thể định nghĩa **dấu** (sign) của hoán vị, ký hiệu là $\operatorname{sgn}\sigma$. Dấu của hoán vị chẵn được định nghĩa là $+1$, và dấu của hoán vị lẻ được định nghĩa là $-1$.

Dấu của tích các hoán vị bằng tích các dấu của chúng, tức là

$$
\operatorname{sgn}(\pi\circ\sigma)=\operatorname{sgn}
\pi\cdot\operatorname{sgn}\sigma.
$$

Nói cách khác, hợp thành của hai hoán vị có cùng tính chẵn lẻ là hoán vị chẵn, còn hợp thành của hai hoán vị có tính chẵn lẻ khác nhau là hoán vị lẻ. Kết luận này suy ra trực tiếp từ góc độ phân rã thành các phép đổi chỗ.

Đặc biệt, một phép đổi chỗ đơn lẻ nhất định làm thay đổi tính chẵn lẻ của hoán vị. Điều này cũng giải thích vì sao, dù cách phân rã thành các phép đổi chỗ không duy nhất, tính chẵn lẻ của số phép đổi chỗ cần dùng vẫn được xác định.

Dấu của hoán vị xuất hiện trong [khai triển Leibniz của định thức](../math/linear-algebra/determinant.md#khai-triển-định-thức).

<span id="bậc-của-hoán-vị"></span>
### Bậc của hoán vị

**Bậc** (order) của hoán vị là số nguyên dương nhỏ nhất $a$ thỏa mãn điều kiện sau: sau khi lặp lại hoán vị đó $a$ lần, mọi phần tử đều trở về vị trí ban đầu. Tức là

$$
\operatorname{ord}\sigma=\min\{a\in\mathbf N_+:\sigma^a=(1)\}.
$$

Trên tập hợp hữu hạn, bậc của mọi hoán vị đều hữu hạn. Điều này có nghĩa là, bắt đầu từ thứ tự ban đầu, chỉ cần lặp lại việc xáo trộn dãy cho trước theo một mẫu cố định thì trong thời gian hữu hạn, cách sắp xếp luôn có thể trở lại như cũ.

<span id="kiểu-chu-trình-của-hoán-vị"></span>
### Kiểu chu trình của hoán vị

Khi phân rã chu trình một hoán vị của $n$ phần tử, **kiểu chu trình** (cycle type) của hoán vị là đa tập hợp các độ dài chu trình trong phân rã đó. Các độ dài chu trình này tạo thành một phân hoạch nguyên của độ dài hoán vị $n$. Nếu trong phân rã thu được có tổng cộng $\alpha_k$ chu trình độ dài $k$, thì kiểu chu trình của hoán vị thường được ký hiệu là

$$
1^{\alpha_1}2^{\alpha_2}\cdots n^{\alpha_n},
$$

và các hệ số này thỏa mãn $\sum_{k=1}^nk\alpha_k=n$.

Với một kiểu chu trình cho trước, số hoán vị khác nhau là

$$
\frac{n!}{1^{\alpha_1}2^{\alpha_2}\cdots n^{\alpha_n}\alpha_1!\alpha_2!\cdots\alpha_n!}.
$$

??? note "Phân tích"
    Lý do là: với bất kỳ cách sắp xếp nào của $1\sim n$, có thể chia nó theo kiểu chu trình của hoán vị để thu được phân rã chu trình tương ứng. Tuy nhiên, thứ tự giữa các chu trình có cùng độ dài không ảnh hưởng đến hoán vị, nên tổng số cần chia cho $\prod_k\alpha_k!$. Ngoài ra, bên trong cùng một chu trình thực chất là một sắp xếp vòng tròn, việc chọn điểm bắt đầu cũng không ảnh hưởng đến hoán vị, nên cần chia cho $\prod_kk^{\alpha_k}$. Từ đó thu được công thức trên.

Nếu cố định số chu trình trong phân rã của hoán vị là $k$, thì số hoán vị khác nhau là [số Stirling loại một](./combinatorics/stirling.md#số-stirling-loại-một-stirling-number) $\begin{bmatrix}n\\ k\end{bmatrix}$. Số kiểu chu trình khác nhau bằng [số phân hoạch](./combinatorics/partition.md) $p_n$ của độ dài hoán vị $n$.

Từ kiểu chu trình của hoán vị, có thể xác định các tính chất như bậc và tính chẵn lẻ của hoán vị.

Vì bậc của một $k$-chu trình là $k$, và các chu trình khác nhau đôi một không giao nhau, bậc của hoán vị $\sigma$ là

$$
\operatorname{lcm}\{k:\alpha_k>0\}.
$$

Tương tự, vì tính chẵn lẻ của một $k$-chu trình ngược với tính chẵn lẻ của $k$, nên tính chẵn lẻ của hoán vị $\sigma$ là tính chẵn lẻ của

$$
\sum_k(k-1)\alpha_k=\sum_{k}k\alpha_k-\sum_{k}\alpha_k=n-c(\sigma)
$$

Trong đó, $c(\sigma)$ là số chu trình, bao gồm cả $1$-chu trình, tức điểm bất động.

Kiểu chu trình của hoán vị có vai trò quan trọng trong [đếm Pólya](./combinatorics/polya.md).

<span id="các-nội-dung-liên-quan-đến-cách-sắp-xếp"></span>
## Các nội dung liên quan đến cách sắp xếp

Nếu bản thân tập hợp $X$ có thứ tự tự nhiên, khi đó hoán vị $\sigma$ thường được gọi là cách sắp xếp và được biểu diễn bằng ký hiệu một dòng

$$
\sigma(1)\sigma(2)\cdots\sigma(n)
$$

Lưu ý không nhầm lẫn với chu trình.

<span id="số-nghịch-thế"></span>
### Số nghịch thế

Trong một cách sắp xếp, nếu một số lớn hơn đứng trước một số nhỏ hơn, hai số này tạo thành một **nghịch thế** (inversion), hay cặp ngược thứ tự. Việc so sánh được thực hiện theo thứ tự tự nhiên.

Tổng số nghịch thế xuất hiện trong một cách sắp xếp được gọi là **số nghịch thế** của hoán vị đó. Số nghịch thế của một cách sắp xếp là số phép đổi chỗ kề nhau tối thiểu cần thực hiện để khôi phục nó thành dãy đúng thứ tự. Vì vậy, tính chẵn lẻ của số nghịch thế của cách sắp xếp trùng với tính chẵn lẻ của hoán vị tương ứng. Điều này có thể dùng làm một định nghĩa tương đương cho tính chẵn lẻ của hoán vị.

Để tính số nghịch thế, có thể dùng [sắp xếp trộn](../basic/merge-sort.md#nghịch-thế) hoặc [cây Fenwick](../ds/fenwick.md#cặp-nghịch-thế-toàn-cục-thứ-tự-bộ-phận-hai-chiều-toàn-cục), đều có độ phức tạp thời gian $O(n\log n)$. Phần giải thích của hai thuật toán nằm ở các chương tương ứng; dưới đây là các cài đặt tham khảo.

??? example "Cài đặt tham khảo"
    === "Sắp xếp trộn"
        ```cpp
        --8<-- "docs/math/code/permutation/inversion_2.cpp"
        ```

    === "Cây Fenwick"
        ```cpp
        --8<-- "docs/math/code/permutation/inversion_1.cpp"
        ```

<span id="thứ-tự"></span>
### Thứ tự

Các cách sắp xếp có thể so sánh lớn nhỏ với nhau. Vì mỗi ký hiệu một dòng là một chuỗi, thứ tự của các cách sắp xếp chính là [thứ tự từ điển](../string/basic.md#thứ-tự-từ-điển) trên chuỗi đó.

Trong thư viện STL `<algorithm>` của C++, có thể dùng `prev_permutation` và `next_permutation` để tìm lần lượt cách sắp xếp liền trước và liền sau của cách sắp xếp hiện tại theo thứ tự từ điển.

<span id="thứ-hạng"></span>
### Thứ hạng

Nếu liệt kê các cách sắp xếp của $n$ phần tử theo thứ tự từ điển từ nhỏ đến lớn, thì vị trí của một cách sắp xếp trong dãy này chính là thứ hạng của cách sắp xếp đó. Nó thiết lập một tương ứng một-một giữa cách sắp xếp và số nguyên dương, và thường được dùng để nén trạng thái trong các bài toán liên quan đến cách sắp xếp.

Trong giới lập trình thi đấu Trung Quốc, thứ hạng này thường được gọi là "khai triển Cantor" của cách sắp xếp, nhưng tên gọi này không chuẩn xác. Cách nói chặt chẽ hơn là: **khai triển Cantor** (Cantor expansion) của thứ hạng của một cách sắp xếp tương ứng với **mã Lehmer** (Lehmer code) của chính cách sắp xếp đó.

??? info "Về \"khai triển Cantor\""
    Đúng như tên gọi gợi ý, khai triển Cantor là một phương pháp khai triển số tự nhiên thành một dãy số. Nó có thể xem là một hệ đếm đặc biệt, cũng gọi là [hệ cơ số giai thừa](./numeral-sys/base.md#hệ-cơ-số-hỗn-hợp). Trong hệ đếm này, cơ số (radix) ứng với các vị trí khác nhau không giống nhau. Chẳng hạn, số thập phân $463_{10}$ có thể được biểu diễn trong hệ cơ số giai thừa thành

    $$
    463_{10}=341010_{!}.
    $$

    Nó có nghĩa là

    $$
    463=3\times 5!+4\times 4!+1\times 3!+0\times 2!+1\times 1!+0\times 0!.
    $$

    Cantor đã nghiên cứu các hệ đếm có cơ số hỗn hợp kiểu này, vì vậy biểu diễn bằng chữ số của số tự nhiên trong hệ đếm đó cũng thường được gọi là khai triển Cantor của số tự nhiên.

??? example "Ví dụ"
    Ví dụ đơn giản này minh họa ý tưởng cơ bản của thuật toán tính thứ hạng bên dưới.

    Để tính thứ hạng của cách sắp xếp $\sigma=452631$, cần tính có bao nhiêu cách sắp xếp có thứ tự từ điển nhỏ hơn $\sigma$, rồi cộng thêm một. Tư tưởng này tương tự [DP chữ số](../dp/number.md): đều xét lần lượt từng vị trí.

    -   Cách chọn vị trí thứ $1$ phải nhỏ hơn $\sigma$, nên chỉ có thể chọn từ $\{1,2,3\}$; $5$ vị trí phía sau có thể chọn tùy ý, tổng cộng có $3\times 5!$ cách sắp xếp khả dụng;
    -   Nếu vị trí thứ $1$ cũng chọn $4$, thì cách chọn vị trí thứ $2$ phải nhỏ hơn $\sigma$, nên chỉ có thể chọn từ $\{1,2,3\}$, trong đó $4$ đã được chọn; $4$ vị trí phía sau có thể chọn tùy ý, tổng cộng có $3\times 4!$ cách sắp xếp khả dụng;
    -   Tương tự, khi cách chọn $2$ vị trí đầu trùng với $\sigma$, cách chọn vị trí thứ $3$ phải nhỏ hơn $\sigma$, nên chỉ có thể chọn từ $\{1\}$; $3$ vị trí phía sau có thể chọn tùy ý, tổng cộng có $1\times 3!$ cách sắp xếp khả dụng;
    -   Khi cách chọn $3$ vị trí đầu trùng với $\sigma$, cách chọn vị trí thứ $4$ phải nhỏ hơn $\sigma$, nên chỉ có thể chọn từ $\{1,3\}$; $2$ vị trí phía sau có thể chọn tùy ý, tổng cộng có $2\times 2!$ cách sắp xếp khả dụng;
    -   Khi cách chọn $4$ vị trí đầu trùng với $\sigma$, cách chọn vị trí thứ $5$ phải nhỏ hơn $\sigma$, nên chỉ có thể chọn từ $\{1\}$; $1$ vị trí phía sau có thể chọn tùy ý, tổng cộng có $1\times 1!$ cách sắp xếp khả dụng;
    -   Khi cách chọn $5$ vị trí đầu trùng với $\sigma$, việc chọn vị trí thứ $6$ không thể tạo ra cách sắp xếp nhỏ hơn $\sigma$, nên có tổng cộng $0\times 0!$ cách sắp xếp khả dụng.

    Do đó, thứ hạng của cách sắp xếp $\sigma$ là

    $$
    1+3\times 5!+3\times 4!+1\times 3!+2\times 2!+1\times 1!+0\times 0!=444.
    $$

    Với các cách sắp xếp khác nhau, điểm cốt lõi là xác định các hệ số đứng trước giai thừa. Các hệ số này chính là số phần tử nằm sau vị trí đang xét nhưng nhỏ hơn phần tử tại vị trí đó.

Từ ví dụ trên, thuật toán tính thứ hạng của một cách sắp xếp cho trước có thể chia thành hai bước:

1.  Chuyển cách sắp xếp độ dài $n$ cho trước thành mã Lehmer của nó, tức dãy độ dài $n$ $L_\sigma$, trong đó vị trí thứ $i$ là

    $$
    L_\sigma(i)=\#\{j>i:\sigma(j)<\sigma(i)\},
    $$

    nghĩa là số phần tử nằm sau vị trí thứ $i$ trong cách sắp xếp nhưng lại nhỏ hơn $\sigma(i)$. Giá trị này bằng thứ hạng của phần tử đã cho trong các phần tử chưa được dùng, trừ một.

2.  Xem mã Lehmer là khai triển Cantor của một số tự nhiên, tính lại số tự nhiên ban đầu, rồi cộng một. Nói cách khác, thứ hạng cuối cùng bằng

    $$
    \operatorname{rank}\sigma=1+L_\sigma(1)(n-1)!+L_\sigma(2)(n-2)!+\cdots+L_\sigma(n)0!.
    $$

Để giải bài toán ngược, tức cho thứ hạng và tìm cách sắp xếp tương ứng, chỉ cần thực hiện ngược lại quá trình trên. Tổng các chữ số trong mã Lehmer thu được trong quá trình này chính là số nghịch thế của cách sắp xếp.

Khi cài đặt, điểm quan trọng là phải tính nhanh "thứ hạng của phần tử cho trước trong các phần tử chưa được dùng" khi tính thứ hạng và "phần tử có thứ hạng cho trước trong các phần tử chưa được dùng" khi tìm cách sắp xếp. Các thao tác này đều có thể được duy trì bằng các cấu trúc dữ liệu như [cây Fenwick](../ds/fenwick.md) hoặc [cây phân đoạn](../ds/seg.md). Cả hai chiều thao tác đều có độ phức tạp thời gian $O(n\log n)$.

??? example "Cài đặt tham khảo"
    === "Tính thứ hạng của cách sắp xếp cho trước"
        ```cpp
        --8<-- "docs/math/code/permutation/perm_rank.cpp"
        ```

    === "Tìm cách sắp xếp có thứ hạng cho trước"
        ```cpp
        --8<-- "docs/math/code/permutation/rank_perm.cpp"
        ```

<span id="tài-liệu-tham-khảo-và-ghi-chú"></span>
## Tài liệu tham khảo và ghi chú

-   [Hoán vị - Wikipedia](https://en.wikipedia.org/wiki/Permutation)
-   [Mã Lehmer - Wikipedia](https://en.wikipedia.org/wiki/Lehmer_code)
-   [Hệ giai thừa - Wikipedia](https://en.wikipedia.org/wiki/Factorial_number_system)
