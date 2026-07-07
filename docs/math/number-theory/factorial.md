author: aofall, c-forrest, CoelacanthusHex, Early0v0, Enter-tainer, Great-designer, iamtwz, Marcythm, Persdre, shuzhouliu, Tiphereth-A, wsyhb, Xeonacid

<span id="mở-đầu"></span>
## Mở đầu

Bài viết này thảo luận các kết quả liên quan đến việc tính giai thừa theo một môđun, đồng thời đưa ra một phương pháp có độ phức tạp thời gian tuyến tính theo kích thước môđun. Vì vậy, phương pháp này chủ yếu phù hợp khi môđun không quá lớn ($\sim 10^6$). Ngoài phương pháp được trình bày tại đây, tùy ngữ cảnh cũng có thể dùng [kỹ thuật đa thức](../poly/shift.md#giai-thừa-theo-modulo-số-nguyên-tố) để tính nhanh.

Theo [định lý số dư Trung Hoa](./crt.md), bài toán lấy dư giai thừa theo môđun có thể chuyển về trường hợp môđun là lũy thừa nguyên tố $p^\alpha$. Khi xử lý dạng bài này, với số nguyên tố $p$ và số nguyên dương $n$, thường cần tách toàn bộ các thừa số $p$ trong giai thừa $n!$ ra, từ đó thu được phân tích:

$$
n! = p^{\nu_p(n!)}(n!)_p.
$$

Trong đó, $\nu_p(n!)$ biểu thị số mũ của $p$ trong phân tích thừa số nguyên tố của $n!$, còn $(n!)_p$ biểu thị số nguyên thu được sau khi loại bỏ mọi lũy thừa của $p$ khỏi giá trị của $n!$. Bài viết này sẽ thảo luận phần dư của $(n!)_p$ theo môđun số nguyên tố hoặc lũy thừa nguyên tố, cũng như cách tính cụ thể số mũ $\nu_p(n!)$.

Phân tích này đặc biệt hữu ích khi giai thừa xuất hiện đồng thời ở tử số và mẫu số của biểu thức cần tính, chẳng hạn khi [tính hệ số nhị thức theo một môđun](./lucas.md). Với những bài toán như vậy, số mũ của $p$ ở tử và mẫu có thể trừ trực tiếp cho nhau; còn phần nguyên tố cùng nhau với $p$, tức $(n!)_p$, có thể xử lý bằng [nghịch đảo nhân](./inverse.md).

Bài viết cũng giới thiệu định lý Wilson và mở rộng của nó, công thức Legendre, định lý Kummer cùng một số nội dung liên quan.

<span id="định-lý-wilson"></span>
## Định lý Wilson

Định lý Wilson cho một điều kiện cần và đủ để kiểm tra một số tự nhiên có phải số nguyên tố hay không.

???+ note "Định lý Wilson"
    Với số tự nhiên $n>1$, có $(n-1)!\equiv -1\pmod n$ khi và chỉ khi $n$ là số nguyên tố.

??? note "Chứng minh"
    Trước hết, chứng minh rằng với số nguyên tố $p$ thì $(p-1)!\equiv -1\pmod{p}$. Điều này có thể được chứng minh ngắn gọn bằng [phương trình đồng dư](./congruence-equation.md#hệ-quả-2) hoặc [căn nguyên thủy](./primitive-root.md); phần này không trình bày hai cách đó. Sau đây là một chứng minh cần ít kiến thức chuẩn bị hơn.
    
    Khi $p=2$, mệnh đề đúng. Xét $p\geq 3$. Cần chứng minh tích của tất cả phần tử khác không trong $\mathbf{Z}_p$ (tức các lớp đồng dư khác không) bằng $\overline{-1}$. Vì mọi phần tử khác không $\overline{a}$ trong $\mathbf{Z}_p$ đều có nghịch đảo $\overline{a}^{-1}$, tích của các cặp phần tử nghịch đảo nhau trong $\mathbf{Z}_p$ bằng $\overline{1}$. Tuy nhiên, cần lưu ý rằng $\overline{a}$ có thể bằng $\overline{a}^{-1}$: $\overline{a}=\overline{a}^{-1}$ khi và chỉ khi $a^2\equiv 1\pmod p$, tức là
    
    $$
    0\equiv a^2-1\equiv (a+1)(a-1)\pmod p
    $$
    
    Do đó $a\equiv 1\pmod p$ hoặc $a\equiv -1\pmod p$. Điều này cho thấy tích của tất cả phần tử trong $\mathbf{Z}_p\setminus\{\overline{0},\overline{1},\overline{-1}\}$ bằng $\overline{1}$, suy ra tích của tất cả phần tử khác không trong $\mathbf{Z}_p$ bằng $\overline{-1}$.
    
    Ngược lại, với trường hợp $n$ là hợp số, cần chứng minh $(n-1)!\not\equiv-1\pmod{n}$. Dùng phản chứng, giả sử $(n-1)!\equiv -1\pmod{n}$, tức tồn tại số nguyên $q$ sao cho $(n-1)!=qn-1$. Vì $n$ là hợp số, tồn tại số nguyên tố $p<n$ sao cho $n=pm$, nên $(n-1)!=qpm-1\equiv -1\pmod{p}$. Nhưng trong tích $(n-1)!$ đã có thừa số $p$, do đó $(n-1)!\equiv 0\pmod{p}$. Mâu thuẫn này chứng minh $(n-1)!\not\equiv-1\pmod{n}$.

Theo ký hiệu của bài viết này, định lý Wilson có thể viết thành $(p!)_p\equiv -1\pmod{p}$.

<span id="mở-rộng"></span>
### Mở rộng

Định lý Wilson có thể được mở rộng cho môđun tổng quát.

???+ note "Định lý (Gauss)"
    Với số tự nhiên $m>1$, có
    
    $$
    \prod_{1\le k<m,\ k\perp m} k \equiv \pm 1 \pmod{m}.
    $$
    
    Hơn nữa, giá trị $\pm 1$ của phần dư bằng $-1$ khi và chỉ khi [căn nguyên thủy theo môđun $m$ tồn tại](./primitive-root.md#định-lí-tồn-tại-căn-nguyên-thủy), tức $m=2,4,p^\alpha,2p^\alpha$, trong đó $p$ là số nguyên tố lẻ và $\alpha$ là số nguyên dương.

??? note "Chứng minh"
    Định lý này có thể được chứng minh ngắn gọn bằng cấu trúc của [nhóm nhân các lớp đồng dư nguyên theo môđun $n$](../algebra/ring-theory.md#ứng-dụng-nhóm-nhân-của-các-lớp-đồng-dư-số-nguyên). Dưới đây là một chứng minh có ý tưởng tương tự nhưng sơ cấp hơn.
    
    Với $m=2$, có $1!=1\equiv -1\pmod{2}$. Với các trường hợp còn lại có căn nguyên thủy, gọi một căn nguyên thủy là $g$. Khi đó mọi số nguyên dương $k<m$ và nguyên tố cùng nhau với $m$ đều có thể biểu diễn duy nhất dưới dạng $g^i\bmod m$, trong đó $0\le i<\varphi(m)$ và $\varphi(m)$ là [hàm Euler](./euler-totient.md). Kiểm tra trực tiếp cho thấy $\varphi(m)$ luôn chẵn. Vì $g^i$ và $g^{\varphi(m)-i}$ là nghịch đảo nhân của nhau, ghép cặp chúng trong tích sẽ cho
    
    $$
    \prod_{1\le k<m,\ k\perp m} k \equiv \prod_{i=0}^{\varphi(m)-1}g^i = g^{\varphi(m)/2}\prod_{i=1}^{\varphi(m)/2-1}g^{i}g^{\varphi(m)-i} \equiv g^{\varphi(m)/2} \pmod{m}.
    $$
    
    Vì $g^{\varphi(m)/2}\bmod m$ là phần tử duy nhất khác $1\bmod{m}$ và có nghịch đảo nhân bằng chính nó, nên nó bằng $-1\bmod{m}$. Do đó phần dư trong trường hợp này bằng $-1$.
    
    Khi môđun $m$ không có căn nguyên thủy, cần chứng minh phần dư bằng $1$. Trước hết phân tích thừa số nguyên tố $m=p_1^{e_1}p_2^{e_2}\cdots p_s^{e_s}$, rồi áp dụng [định lý số dư Trung Hoa](./crt.md). Khi đó chỉ cần chứng minh
    
    $$
    \prod_{1\le k<m,\ k\perp m} k\equiv 1\pmod{p_j^{e_j}}
    $$
    
    với mọi thừa số $p_j^{e_j}$. Định lý số dư Trung Hoa cho biết mỗi tổ hợp phần dư khả dĩ $(r_1,r_2,\cdots,r_s)$, trong đó $1\le r_j<p_j^{e_j}$ và $p_j\perp r_j$, tương ứng duy nhất với một số $1\le k<m$ thỏa mãn $k\perp m$ và $k\equiv r_j\pmod{p_j^{e_j}}$. Vì vậy, với một phần dư $r_j$ cố định, có đúng ${\varphi(m)}/{\varphi(p_j^{e_j})}$ số $k$ sao cho $k\equiv r_j\pmod{p_j^{e_j}}$. Dùng điều này để nhóm tích, có
    
    $$
    \prod_{1\le k<m,\ k\perp m} k\equiv\left(\prod_{1\le r_j<p_j^{e_j},\ r_j\perp p_j} r_j\right)^{{\varphi(m)}/{\varphi(p_j^{e_j})}}\pmod{p_j^{e_j}}.
    $$
    
    Để số mũ ${\varphi(m)}/{\varphi(p_j^{e_j})}=\varphi(m/p_j^{e_j})$ là số lẻ thì bắt buộc $m/p_j^{e_j}=1,2$, vì hàm Euler $\varphi(n)$ là số chẵn với mọi $n\ge 3$. Nếu $p_j$ là số nguyên tố lẻ, do môđun $m$ không có căn nguyên thủy, có $m/p_j^{e_j}\neq 1,2$. Nếu $p_j^{e_j}=2,4$, cũng do môđun $m$ không có căn nguyên thủy, $m/p_j^{e_j}$ chứa một thừa số nguyên tố lẻ, nên lớn hơn $2$. Trong cả hai trường hợp, số mũ ${\varphi(m)}/{\varphi(p_j^{e_j})}$ đều chẵn. Mặt khác, thừa số trong ngoặc ở công thức trên đã được chứng minh có phần dư $-1$ theo môđun $p_j^{e_j}$, nên lũy thừa đó có phần dư $1$ theo môđun $p_j^{e_j}$. Trường hợp còn lại chỉ là $p_j=2$ và $e_j>2$; với trường hợp này, có thể chứng minh trực tiếp rằng
    
    $$
    \prod_{1\le r_j<2^{e_j},\ r_j\perp 2}r_j \equiv 1\pmod{2^{e_j}}.
    $$
    
    Tương tự ý tưởng chứng minh ở trên, ghép cặp các số lẻ $r_j$ thỏa $1\le r_j<2^{e_j}$ với nghịch đảo của chúng. Những số không ghép cặp được phải là nghiệm của phương trình $x^2\equiv 1\pmod{2^{e_j}}$. Phương trình này có nghĩa là $2^{e_j}\mid (x-1)(x+1)$. Đặt $x=2y+1$, có $2^{e_j-2}\mid y(y+1)$. Vì $y$ và $y+1$ luôn có một số lẻ, một số chẵn, nên $y=t2^{e_j-2}$ hoặc $y=t2^{e_j-2}-1$. Do đó $x=t2^{e_j-1}\pm 1$, với $t$ là số nguyên. Trong các phần dư theo môđun $2^{e_j}$, chỉ có bốn giá trị $\pm 1$ và $2^{e_j-1}\pm 1$. Vì thế
    
    $$
    \prod_{1\le r_j<2^{e_j},\ r_j\perp 2}r_j \equiv (-1)(2^{e_j-1}-1)(2^{e_j-1}+1) \equiv 1\pmod{2^{e_j}}.
    $$
    
    Như vậy mọi trường hợp đều đã được chứng minh.

Trong tính toán, trường hợp môđun là lũy thừa nguyên tố đặc biệt quan trọng:

???+ note "Hệ quả"
    Với số nguyên tố $p$ và số nguyên dương $\alpha$, có
    
    $$
    \prod_{1\le k<p^\alpha,\ k\perp p}k \equiv 
    \begin{cases}
    1, & p=2\text{ và }\alpha\ge3,\\
    -1, &\text{ngược lại}
    \end{cases}
    \pmod{p^\alpha}.
    $$

Lưu ý rằng vế trái không phải $(p^\alpha!)_p$, vì biểu thức sau còn cần tính cả đóng góp của các bội của $p$.

<span id="tính-phần-dư-của-giai-thừa"></span>
## Tính phần dư của giai thừa

Phần này thảo luận cách tính phần dư $(n!)_p\bmod p^{\alpha}$.

<span id="trường-hợp-modulo-số-nguyên-tố"></span>
### Trường hợp môđun số nguyên tố

Biểu thức $(n!)_p$ có cấu trúc đệ quy. Trước hết xét một ví dụ cụ thể:

???+ example "Ví dụ"
    Để tính $(32!)_5 \bmod{5}$, có thể thực hiện phép tính đệ quy như sau:
    
    $$
    \begin{aligned}
    (32!)_5 &= 1\times 2\times 3 \times 4\times \underbrace{1}_{5}\times 6 \times 7 \times 8\times 9 \times \underbrace{2}_{10} \\
    &\quad\times 11 \times 12 \times 13 \times 14\times \underbrace{3}_{15}\times 16 \times 17\times 18\times 19\times \underbrace{4}_{20} \\
    &\quad\times 21 \times 22 \times 23 \times 24\times \underbrace{1}_{25}\times 26 \times 27\times 28\times 29\times \underbrace{6}_{30} \times 31 \times 32 \\
    &\equiv 1\times 2\times 3 \times 4\times \underbrace{1}_{5}\times 1 \times 2 \times 3\times 4 \times \underbrace{2}_{10} \\
    &\quad\times 1 \times 2 \times 3 \times 4\times \underbrace{3}_{15}\times 1 \times 2\times 3\times 4\times \underbrace{4}_{20} \\
    &\quad\times 1 \times 2 \times 3 \times 4\times \underbrace{1}_{25}\times 1 \times 2\times 3\times 4\times \underbrace{1}_{30}\times 1\times 2\\
    &= (1\times 2\times 3\times 4)^{6}\times(1\times 2)\times(\underbrace{1}_{5}\times \underbrace{2}_{10}\times \underbrace{3}_{15} \times \underbrace{4}_{20}\times \underbrace{1}_{25}\times \underbrace{1}_{30}) \pmod{5}
    \end{aligned}
    $$
    
    Nhờ tính chu kỳ của phần dư theo môđun $5$, tích này được chia thành các khối độ dài $5$; điểm khác nhau duy nhất giữa các khối là phần dư của phần tử cuối. Vì $32$ chia cho $5$ được thương $6$ và dư $2$, tích này gồm $6$ khối đầy đủ và một đoạn cuối không đầy đủ có độ dài $2$. Do đó, tách phần trước phần tử cuối của $6$ khối đầu tiên ra (phần này được xử lý đúng bằng định lý Wilson), nhân thêm tích của khối cuối không đầy đủ, rồi nhân với tích các phần tử cuối của $6$ khối đầu tiên. Mỗi phần tử cuối của một khối đều là bội của $5$; sau khi bỏ các lũy thừa của $5$, tích của chúng đúng bằng $(6!)_{5}\pmod{5}$. Nhờ vậy, bài toán ban đầu được chuyển thành một bài toán nhỏ hơn.

Tổng quát hóa cấu trúc đệ quy trong ví dụ này, thu được công thức truy hồi sau:

???+ note "Công thức truy hồi"
    Với số nguyên tố $p$ và số nguyên dương $n$, có
    
    $$
    (n!)_p \equiv (-1)^{\left\lfloor n/p\right\rfloor}\cdot (n\bmod p)!\cdot\left(\left\lfloor n/p\right\rfloor!\right)_p\pmod{p}.
    $$

??? note "Chứng minh"
    Ký hiệu $(n)_p$ là kết quả sau khi loại bỏ mọi lũy thừa của $p$ trong phân tích thừa số nguyên tố của $n$. Khi đó
    
    $$
    \begin{aligned}
    (n!)_p &= \prod_{k=1}^n(k)_p = \left(\prod_{1\le k\le n,\ k\perp p}(k)_p\right)\left(\prod_{1\le k\le\lfloor n/p\rfloor}(pk)_p\right) \\
    &= \left(\prod_{i=0}^{\lfloor n/p\rfloor-1}\prod_{j=1}^{p-1}(ip+j)\right)\left(\prod_{j=1}^{n\bmod p}(\lfloor n/p\rfloor p+j)\right)\left(\prod_{1\le k\le\lfloor n/p\rfloor}(k)_p\right) \\
    &\equiv\left(\prod_{j=1}^{p-1}j\right)^{\lfloor n/p\rfloor}\left(\prod_{j=1}^{n\bmod p}j\right)(\lfloor n/p\rfloor!)_p \\
    &\equiv (-1)^{\lfloor n/p\rfloor}\cdot(n\bmod p)!\cdot(\lfloor n/p\rfloor!)_p \pmod p.
    \end{aligned}
    $$
    
    Như vậy công thức đã được chứng minh. Sau đây là một cách giải thích cụ thể hơn cho dạng chứng minh này.
    
    Cần tính giá trị của $(n!)_p\bmod p$. Tương tự ví dụ ở trên, có
    
    $$
    \begin{aligned}
    (n!)_p &= 1 \cdot 2 \cdot 3 \cdot \ldots \cdot (p-2) \cdot (p-1) \cdot \underbrace{1}_{p} \cdot (p+1) \cdot (p+2) \cdot \ldots \cdot (2p-1) \cdot \underbrace{2}_{2p} \\
    &\quad \cdot (2p+1) \cdot \ldots \cdot (p^2-1) \cdot \underbrace{1}_{p^2} \cdot (p^2 +1) \cdot \ldots \cdot n \pmod{p} \\
    &= 1 \cdot 2 \cdot 3 \cdot \ldots \cdot (p-2) \cdot (p-1) \cdot \underbrace{1}_{p} \cdot 1 \cdot 2 \cdot \ldots \cdot (p-1) \cdot \underbrace{2}_{2p} \cdot 1 \cdot 2 \\
    &\quad \cdot \ldots \cdot (p-1) \cdot \underbrace{1}_{p^2} \cdot 1 \cdot 2 \cdot \ldots \cdot (n \bmod p) \pmod{p}.
    \end{aligned}
    $$
    
    Ngoài khối cuối cùng, giai thừa được chia thành nhiều khối đầy đủ có cùng độ dài.
    
    $$
    \begin{aligned}
    (n!)_p&= \underbrace{1 \cdot 2 \cdot 3 \cdot \ldots \cdot (p-2) \cdot (p-1) \cdot 1}_{\text{lần 1}} \cdot \underbrace{1 \cdot 2 \cdot 3 \cdot \ldots \cdot (p-2) \cdot (p-1) \cdot 2}_{\text{lần 2}} \cdot \ldots \\
    &\quad \cdot \underbrace{1 \cdot 2 \cdot 3 \cdot \ldots \cdot (p-2) \cdot (p-1) \cdot 1}_{\text{lần }p} \cdot \ldots \cdot \quad \underbrace{1 \cdot 2 \cdot \ldots \cdot (n \bmod p)}_{\text{đuôi}} \pmod{p}.
    \end{aligned}
    $$
    
    Ngoại trừ phần tử cuối của mỗi khối, phần chính của mỗi khối đầy đủ là $(p-1)!\bmod p$, có thể tính bằng định lý Wilson:
    
    $$
    (p-1)!\equiv -1\pmod p.
    $$
    
    Tổng cộng có $\left\lfloor \dfrac{n}{p} \right\rfloor$ khối đầy đủ, nên cần đưa $\left\lfloor \dfrac{n}{p} \right\rfloor$ lên làm số mũ của $-1$.
    
    Giá trị của khối cuối không đầy đủ là $(n\bmod p)!\bmod p$, có thể tính riêng.
    
    Phần còn lại là phần tử cuối của mỗi khối. Nếu ẩn các phần tử đã xử lý, sẽ thấy mẫu sau:
    
    $$
    (n!)_p = \underbrace{ \ldots \cdot 1 } \cdot \underbrace{ \ldots \cdot 2} \cdot \ldots \cdot \underbrace{ \ldots \cdot (p-1)} \cdot \underbrace{ \ldots \cdot 1 } \cdot \underbrace{ \ldots \cdot 1} \cdot \underbrace{ \ldots \cdot 2} \cdots
    $$
    
    Đây cũng là một giai thừa đã chỉnh sửa, chỉ có độ dài ngắn hơn nhiều. Nó là:
    
    $$
    \left(\left\lfloor \frac{n}{p} \right\rfloor !\right)_p.
    $$
    
    Nhân các phần lại với nhau, thu được công thức truy hồi ở trên.

Dùng công thức truy hồi này, độ sâu đệ quy là $O(\log_p n)$. Nếu mỗi lần đều tính lại hạng tử ở giữa, độ phức tạp mỗi tầng là $O(p)$, nên tổng độ phức tạp thời gian là $O(p\log_p n)$. Nếu tiền xử lý trước mọi giá trị $n!\bmod p$ với $n=0,1,\cdots,p-1$, độ phức tạp tiền xử lý là $O(p)$, mỗi tầng tính trong $O(1)$, và tổng độ phức tạp là $O(p+\log_p n)$.

Khi cài đặt, vì đây là đệ quy đuôi nên có thể viết bằng vòng lặp. Cài đặt dưới đây tiền xử lý giai thừa của các giá trị từ $0$ đến $p-1$; nếu cần gọi nhiều lần, có thể đưa phần tiền xử lý ra ngoài hàm.

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/factorial/fact-mod-p.cpp:core"
    ```

Nếu bộ nhớ hạn chế và không thể lưu toàn bộ giai thừa, cũng có thể chỉ tính các giá trị $n$ thực sự được dùng trong những lần gọi hàm cho $n!\bmod p$, sau đó sắp xếp chúng để tính tất cả các giai thừa cần thiết trong một lượt cuối cùng và gộp vào kết quả, tránh phải lưu mọi giá trị giai thừa.

<span id="trường-hợp-modulo-lũy-thừa-nguyên-tố"></span>
### Trường hợp môđun lũy thừa nguyên tố

Với trường hợp môđun là lũy thừa nguyên tố, có thể giải tương tự trường hợp môđun số nguyên tố, chỉ cần thay định lý Wilson bằng dạng mở rộng của nó. Trong hai kết quả của phần này, ký hiệu $\pm 1$ luôn được hiểu theo định nghĩa sau: lấy $1$ khi môđun có $p=2$ và $\alpha\ge 3$, còn các trường hợp khác lấy $-1$.

???+ note "Công thức truy hồi"
    Với số nguyên tố $p$ và các số nguyên dương $\alpha,n$, có
    
    $$
    (n!)_{p} \equiv (\pm 1)^{\lfloor n/p^\alpha\rfloor}\cdot\left(\prod_{1\le j\le (n\bmod p^\alpha),\ j\perp p}j\right)\cdot(\lfloor n/p\rfloor!)_p\pmod{p^\alpha}.
    $$
    
    Trong đó, giá trị của $\pm 1$ được quy định như trong [mở rộng của định lý Wilson](#mở-rộng).

??? note "Chứng minh"
    Ý tưởng chứng minh hoàn toàn giống trường hợp môđun số nguyên tố. Ký hiệu $(k)_p$ là kết quả sau khi loại bỏ mọi lũy thừa của $p$ trong phân tích thừa số nguyên tố của $k$. Khi đó
    
    $$
    \begin{aligned}
    (n!)_p
    &= \prod_{1\le k\le n}(k)_p = \left(\prod_{1\le k\le n,\ k\perp p}(k)_p\right)\left(\prod_{1\le k\le\lfloor n/p\rfloor}(pk)_p\right) \\
    &= \left(\prod_{i=0}^{\lfloor n/p^\alpha\rfloor-1}\prod_{1\le j\le p^\alpha,\ j\perp p}(ip^\alpha+j)_p\right)\left(\prod_{1\le j\le (n\bmod p^\alpha),\ j\perp p}(\lfloor n/p^\alpha\rfloor p^\alpha+j)_p\right)\left(\prod_{1\le k\le\lfloor n/p\rfloor}(k)_p\right)\\
    &\equiv \left(\prod_{1\le j\le p^\alpha,\ j\perp p}j\right)^{\lfloor n/p^\alpha\rfloor}\cdot\left(\prod_{1\le j\le (n\bmod p^\alpha),\ j\perp p}j\right)\cdot(\lfloor n/p\rfloor!)_p\\
    &\equiv (\pm 1)^{\lfloor n/p^\alpha\rfloor}\cdot\left(\prod_{1\le j\le (n\bmod p^\alpha),\ j\perp p}j\right)\cdot(\lfloor n/p\rfloor!)_p \pmod{p^\alpha}.
    \end{aligned}
    $$

Khác với trường hợp môđun số nguyên tố, ngoài việc $-1$ có thể cần thay bằng $\pm 1$, dữ liệu tiền xử lý cũng khác. Với môđun lũy thừa nguyên tố, cần tiền xử lý tích của mọi số nguyên dương từ $1$ đến $n$ nhưng không phải bội của $p$, với mọi $n$ không vượt quá $p^\alpha$, tức là

$$
\prod_{1\le k\le n,\ k\perp p} k\bmod{p^\alpha}.
$$

Trong trường hợp môđun số nguyên tố và $0\le n<p$, biểu thức này suy biến thành $n!\bmod p$, nhưng với lũy thừa nguyên tố tổng quát thì không còn dùng được biểu thức đó.

Dưới đây là ví dụ tính phần dư giai thừa theo môđun lũy thừa nguyên tố, giúp hiểu phương pháp trên:

???+ example "Ví dụ"
    Để tính $(32!)_3\bmod 9$, có thể thực hiện phép tính đệ quy như sau:
    
    $$
    \begin{aligned}
    (32!)_3 
    &= 1\times 2\times \underbrace{1}_{3} \times 4\times 5\times \underbrace{2}_{6}\times 7\times 8\times\underbrace{1}_{9}\\
    &\quad\times 10\times 11\times\underbrace{4}_{12}\times 13\times 14\times\underbrace{5}_{15}\times 16\times 17\times\underbrace{2}_{18}\\
    &\quad\times 19\times 20\times\underbrace{7}_{21}\times 22\times 23\times\underbrace{8}_{24}\times 25\times 26\times\underbrace{1}_{27}\\
    &\quad\times 28\times 29\times\underbrace{10}_{30}\times 31\times 32\\
    &\equiv 1\times 2\times \underbrace{1}_{3} \times 4\times 5\times \underbrace{2}_{6}\times 7\times 8\times\underbrace{1}_{9}\\
    &\quad\times 1\times 2\times\underbrace{4}_{12}\times 4\times 5\times\underbrace{5}_{15}\times 7\times 8\times\underbrace{2}_{18}\\
    &\quad\times 1\times 2\times\underbrace{7}_{21}\times 4\times 5\times\underbrace{8}_{24}\times 7\times 8\times\underbrace{1}_{27}\\
    &\quad\times 1\times 2\times\underbrace{1}_{30}\times 4\times 5\\
    &=(1\times 2\times 4\times 5\times 7\times 8)^{3}\times (1\times 2\times 4\times 5)\\
    &\quad\times\left(\underbrace{1}_{3}\times\underbrace{2}_{6}\times\underbrace{1}_{9}\times\underbrace{4}_{12}\times\underbrace{5}_{15}\times\underbrace{2}_{18}\right.\\
    &\quad\left.\times\underbrace{7}_{21}\times\underbrace{8}_{24}\times\underbrace{1}_{27}\times\underbrace{1}_{30}\right)\pmod{9}.
    \end{aligned}
    $$
    
    Kết quả phân tách biểu thức $(32!)_3\bmod 9$ cũng gồm ba phần:
    
    -   Các khối đầy đủ: tích của mọi số nguyên từ $1$ đến $9$ không chia hết cho $3$, có tổng cộng $\lfloor 32/9\rfloor=3$ khối;
    -   Khối cuối không đầy đủ: tích của các số nguyên không chia hết cho $3$ từ $1$ đến $32\bmod 9$;
    -   Tích của mọi số nguyên chia hết cho $3$. So với kết quả ở dấu bằng áp chót, đây chính là $10$ hạng tử đầu của nó, tức $(\lfloor 32/3\rfloor!)_3\bmod 9$.
    
    Chỉ cần tiếp tục giải đệ quy phần trong ngoặc cuối cùng, bài toán ban đầu sẽ được chuyển thành bài toán nhỏ hơn.

Từ đó, thu được kết quả truy hồi sau:

???+ note "Kết quả truy hồi"
    Với số nguyên tố $p$ và các số nguyên dương $\alpha,n$, có
    
    $$
    (n!)_p \equiv (\pm 1)^{\sum_{j\ge\alpha}\lfloor{n}/{p^j}\rfloor}\prod_{j\ge 0}F(\lfloor n/p^j\rfloor\bmod p^\alpha)\pmod{p^\alpha},
    $$
    
    trong đó $F(m) = \prod_{1\le k\le m,\ k\perp p} k\bmod{p^\alpha}$ và giá trị của $\pm 1$ giống như đã nêu ở trên.

Cài đặt cho trường hợp môđun lũy thừa nguyên tố tương tự trường hợp môđun số nguyên tố, chỉ khác một vài chi tiết. Tương tự phần trên, cũng có thể đưa tiền xử lý ra ngoài hàm.

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/factorial/fact-mod-pa.cpp:core"
    ```

Độ phức tạp tiền xử lý là $O(p^\alpha)$, độ phức tạp cho mỗi truy vấn là $O(\log_p n)$.

<span id="tính-số-mũ"></span>
## Tính số mũ

Phần này thảo luận cách tính số mũ $\nu_p(n!)$ của $p$ trong giai thừa $n!$, có thể dùng để tính phần dư của hệ số nhị thức. Vì trong hệ số nhị thức, cả tử và mẫu đều chứa giai thừa, việc thừa số nguyên tố $p$ ở tử và mẫu có triệt tiêu được nhau hay không trở thành yếu tố quan trọng quyết định phần dư cuối cùng.

<span id="công-thức-legendre"></span>
### Công thức Legendre

Số mũ của số nguyên tố $p$ trong giai thừa $n!$ có thể được tính bằng công thức Legendre, và có liên quan đến biểu diễn của $n$ trong hệ cơ số $p$.

???+ note "Công thức Legendre"
    Với số nguyên dương $n$, số mũ $\nu_p(n!)$ của số nguyên tố $p$ trong giai thừa $n!$ là
    
    $$
    \nu_p(n!) = \sum_{i=1}^{\infty} \left\lfloor \dfrac{n}{p^i} \right\rfloor = \dfrac{n-S_p(n)}{p-1},
    $$
    
    trong đó $S_p(n)$ là tổng các chữ số của $n$ trong hệ cơ số $p$. Đặc biệt, số mũ của $2$ trong giai thừa là $\nu_2(n!)=n-S_2(n)$.

??? note "Chứng minh"
    Vì
    
    $$
    n! = 1\times 2\times \cdots \times p\times \cdots \times 2p\times \cdots \times \lfloor n/p\rfloor p\times \cdots \times n.
    $$
    
    Tích các bội của $p$ là $p\times 2p\times \cdots \times \lfloor n/p\rfloor p=p^{\lfloor n/p\rfloor }\lfloor n/p\rfloor !$, còn $\lfloor n/p\rfloor !$ có thể tiếp tục chứa các bội của $p$. Vì vậy, với số mũ có quan hệ truy hồi:
    
    $$
    \nu_p(n!) = \lfloor n/p\rfloor + \nu_p(\lfloor n/p\rfloor!).
    $$
    
    Khai triển quan hệ này sẽ cho công thức Legendre.
    
    Để chứng minh dấu bằng thứ hai, trước hết khai triển $n$ trong hệ cơ số $p$, tức viết nó thành tổng:
    
    $$
    n = n_\ell p^{\ell} + \cdots + n_1 p + n_0 = \sum_{k=0}^\ell n_kp^k.
    $$
    
    Do đó
    
    $$
    \begin{aligned}
    \nu_p(n!)
    &= \sum_{i=1}^{\ell}\left\lfloor\dfrac{n}{p^i}\right\rfloor 
    = \sum_{i=1}^\ell\sum_{k=i}^{\ell}n_kp^{k-i}
    = \sum_{k=1}^\ell n_k\sum_{i=1}^kp^{k-i} \\
    &= \sum_{k=1}^\ell n_k\dfrac{p^k-1}{p-1} 
    = \dfrac{\sum_{k=0}^\ell n_kp^k - \sum_{k=0}^\ell n_k}{p-1} 
    = \dfrac{n - S_p(n)}{p-1}.
    \end{aligned}
    $$

Cài đặt tham khảo để tính số mũ của số nguyên tố trong giai thừa như sau:

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/factorial/multiplicity.cpp:core"
    ```

Độ phức tạp thời gian là $O(\log n)$.

<span id="định-lý-kummer"></span>
### Định lý Kummer

Kết quả lấy dư hệ số nhị thức theo môđun thường tạo thành cấu trúc phân hình; ví dụ tam giác Sierpinski có thể thu được từ hệ số nhị thức theo môđun $2$.

Nếu phân tích kỹ, việc $p$ có chia hết hệ số nhị thức hay không liên quan đến việc phép trừ hai chỉ số trong hệ cơ số $p$ có cần mượn hay không. Từ đó có **định lý Kummer**.

???+ note "Định lý Kummer"
    Với $0\le n\le m$, số mũ của số nguyên tố $p$ trong hệ số nhị thức $\dbinom{m}{n}$ đúng bằng số lần cần mượn khi lấy $m$ trừ $n$ trong hệ cơ số $p$, tức là
    
    $$
    \nu_p\left(\dbinom{m}{n}\right)=\frac{S_p(n)+S_p(m-n)-S_p(m)}{p-1}.
    $$
    
    Đặc biệt, số mũ của $2$ trong hệ số nhị thức là $\nu_2\left(\dbinom{m}{n}\right)=S_2(n)+S_2(m-n)-S_2(m)$.

??? note "Chứng minh"
    Trước hết chứng minh biểu thức dưới đây. Dùng công thức Legendre, có
    
    $$
    \begin{aligned}
    \nu_p\left(\dbinom{m}{n}\right)
    &=\nu_p(m!)-\nu_p(n!)-\nu_p((m-n)!)\\
    &=\sum_{i=1}^\infty\left(\left\lfloor\dfrac{m}{p^i}\right\rfloor-\left\lfloor\dfrac{n}{p^i}\right\rfloor-\left\lfloor\dfrac{m-n}{p^i}\right\rfloor\right)\\
    &=\frac{S_p(n)+S_p(m-n)-S_p(m)}{p-1}.
    \end{aligned}
    $$
    
    Biểu thức này có thể hiểu là số lần cần mượn khi lấy $m$ trừ $n$ trong hệ cơ số $p$. Nếu sau khi xử lý $i$ chữ số thấp nhất xuất hiện một lần mượn sang phần còn lại, thì phần còn lại của hiệu, tức $\left\lfloor\dfrac{m-n}{p^i}\right\rfloor$, thực chất bằng phần còn lại của $m$, tức $\left\lfloor\dfrac{m}{p^i}\right\rfloor$, trừ đi một (đơn vị đã mượn), rồi trừ tiếp phần còn lại của $n$, tức $\left\lfloor\dfrac{n}{p^i}\right\rfloor$. Vì vậy hiệu
    
    $$
    \left\lfloor\dfrac{m}{p^i}\right\rfloor-\left\lfloor\dfrac{n}{p^i}\right\rfloor-\left\lfloor\dfrac{m-n}{p^i}\right\rfloor = 1
    $$
    
    khi và chỉ khi có một lần mượn xảy ra; nếu không, hiệu này bằng $0$. Do đó tổng ở biểu thức trên chính là số lần mượn. Đây là phát biểu bằng lời của định lý Kummer.

<span id="bài-tập-ví-dụ"></span>
## Bài tập ví dụ

???+ example "Bài tập [HDU 2973 - YAPTCHA](https://acm.hdu.edu.cn/showproblem.php?pid=2973)"
    Cho $n$, tính
    
    $$
    \sum_{k=1}^n\left\lfloor\frac{(3k+6)!+1}{3k+7}-\left\lfloor\frac{(3k+6)!}{3k+7}\right\rfloor\right\rfloor
    $$

??? note "Ý tưởng giải"
    Nếu $3k+7$ là số nguyên tố, thì
    
    $$
    (3k+6)!\equiv-1\pmod{3k+7}
    $$
    
    Đặt $(3k+6)!+1=q(3k+7)$.
    
    Khi đó
    
    $$
    \left\lfloor\frac{(3k+6)!+1}{3k+7}-\left\lfloor\frac{(3k+6)!}{3k+7}\right\rfloor\right\rfloor=\left\lfloor q-\left\lfloor q-\frac{1}{3k+7}\right\rfloor\right\rfloor=1
    $$
    
    Nếu $3k+7$ không phải số nguyên tố, thì $(3k+7)\mid(3k+6)!$, tức
    
    $$
    (3k+6)!\equiv 0\pmod{3k+7}
    $$
    
    Đặt $(3k+6)!=q(3k+7)$, có
    
    $$
    \left\lfloor\frac{(3k+6)!+1}{3k+7}-\left\lfloor\frac{(3k+6)!}{3k+7}\right\rfloor\right\rfloor=\left\lfloor q+\frac{1}{3k+7}-q\right\rfloor=0
    $$
    
    Vì vậy
    
    $$
    \sum_{k=1}^n\left\lfloor\frac{(3k+6)!+1}{3k+7}-\left\lfloor\frac{(3k+6)!}{3k+7}\right\rfloor\right\rfloor=\sum_{k=1}^n[3k+7\text{ là số nguyên tố}]
    $$

??? example "Mã tham khảo"
    ```cpp
    --8<-- "docs/math/code/factorial/wilson_1.cpp"
    ```

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

-   Feng Keqin, *Elementary Number Theory and Its Applications*.
-   [Wilson's theorem - Wikipedia](https://en.wikipedia.org/wiki/Wilson%27s_theorem)
-   [Legendre's formula - Wikipedia](https://en.wikipedia.org/wiki/Legendre%27s_formula)

**Trang này chủ yếu được dịch từ bài viết [Вычисление факториала по модулю](http://e-maxx.ru/algo/modular_factorial) và bản dịch tiếng Anh [Factorial modulo p](https://cp-algorithms.com/algebra/factorial-modulo.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0. Nội dung đã được chỉnh sửa.**
