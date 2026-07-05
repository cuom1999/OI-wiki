author: codewasp942, Tiphereth-A

Không gian tuyến tính là một khái quát của không gian Euclid $d$ chiều ($0\leq d\leq 3$), v.v. Có thể xem quan hệ giữa các khái niệm liên quan ở [quan hệ giữa không gian Euclid và không gian tuyến tính](#%E6%AC%A7%E6%B0%8F%E7%A9%BA%E9%97%B4%E4%B8%8E%E7%BA%BF%E6%80%A7%E7%A9%BA%E9%97%B4%E7%9A%84%E5%85%B3%E7%B3%BB).

Kiến thức chuẩn bị: nhóm Abel, trường.

Nói một cách trực quan, nếu một tập hợp đóng với một phép toán nào đó và thỏa mãn tính kết hợp, có phần tử đơn vị và phần tử nghịch đảo thì nó tạo thành một nhóm. Nếu còn thỏa mãn tính giao hoán thì nó tạo thành một nhóm Abel.

Nếu một tập hợp đóng với bốn phép toán số học thì nó tạo thành một trường. Định nghĩa liên quan được trình bày chi tiết trong [các khái niệm cơ bản của đại số trừu tượng](../algebra/basic.md#trường).

<span id="&#23450;&#20041;"></span>
## Định nghĩa

Không gian tuyến tính (không gian vectơ) là một khái niệm cơ bản và là đối tượng nghiên cứu quan trọng của đại số tuyến tính. Không gian tuyến tính là một cấu trúc đại số dạng mô-đun gồm tập vectơ $V$, trường $\Bbb{P}$, phép cộng $+$ và phép nhân vô hướng (nhân với số).

Cụ thể, giả sử $(V,+)$ là một nhóm Abel, và $\Bbb{P}$ là một trường.

Định nghĩa một phép toán đại số giữa số trong $\Bbb{P}$ và phần tử trong $V$, gọi là **nhân vô hướng**: $\cdot:\Bbb{P}\times V\mapsto V$, ký hiệu là $p\cdot v$ hoặc $pv$, trong đó $p$ thuộc trường $\Bbb{P}$ và $v$ thuộc nhóm Abel $V$. Yêu cầu phép nhân vô hướng này đóng, tức kết quả phép toán luôn có nghĩa và vẫn thuộc nhóm $V$.

Đồng thời thỏa mãn các điều kiện sau:

1.  **Luật phân phối của nhân vô hướng đối với cộng vectơ**: với $\mathbf u,\mathbf v\in V,a\in \Bbb{P}$, $a(\mathbf u+\mathbf v)=a\mathbf u+a\mathbf v$.
2.  **Luật phân phối của nhân vô hướng đối với cộng vô hướng**: với $a,b\in \Bbb{P},\mathbf u\in V$, $(a+b)\mathbf u=a\mathbf u+b\mathbf u$.
3.  **Luật kết hợp của nhân vô hướng (phù hợp với phép nhân trong trường)**: với $a,b\in \Bbb{P},\mathbf u\in V$, $a(b\mathbf u)=(ab)\mathbf u$.
4.  **Phần tử đơn vị của nhân vô hướng**: gọi $1\in \Bbb{P}$ là phần tử đơn vị của phép nhân trong $\Bbb{P}$, thì với $u\in V$, $1\mathbf u=\mathbf u$.

Khi đó hệ đại số $(V,+,\cdot,\mathbb{P})$ được gọi là một **không gian tuyến tính** trên $\Bbb{P}$ do $V$ cùng với $+,\cdot$ tạo thành; $\Bbb{P}$ là **trường cơ sở** của không gian tuyến tính; các phần tử của $V$ gọi là **vectơ**, còn các phần tử của $\Bbb{P}$ gọi là **vô hướng**. Khi trường $\Bbb{P}$ là trường số thực, ta gọi đó là không gian tuyến tính thực. Khi trường $\Bbb{P}$ là trường số phức, ta gọi đó là không gian tuyến tính phức.

Dù là một dãy số, một mũi tên hay một đối tượng khác, miễn thỏa mãn các tiên đề trên thì đều có thể được xem là vectơ, và do đó có thể được nghiên cứu bằng lý thuyết đại số tuyến tính.

Phần tử không trong nhóm cộng được gọi là vectơ không, ký hiệu là $\mathbf 0$ hoặc $\mathbf\theta$.

Phép cộng trừ vectơ trong nhóm Abel ban đầu, cùng với phép nhân vô hướng mới định nghĩa trong không gian tuyến tính, được gọi chung là **phép toán tuyến tính**.

???+ note "Ghi chú"
    Để tiện trình bày, trong phần dưới:
    
    1.  Các phần tử của $V$ sẽ không được in đậm.
    2.  Hệ đại số $(V,+,\cdot,\mathbb{P})$ thỏa mãn định nghĩa không gian tuyến tính cũng sẽ được gọi tắt là không gian tuyến tính.
    
    Cần chú ý phân biệt theo ngữ cảnh.

<span id="&#30452;&#35266;&#29702;&#35299;"></span>
### Cách hiểu trực quan

Nói không hoàn toàn chặt chẽ, nhân vô hướng tương ứng với một kiểu "**co giãn**"; phần tử trong trường cơ sở $\Bbb{P}$ biểu thị "**tỉ lệ**" co giãn đó; còn cộng vectơ tương ứng với "**chồng cộng**". Đồng thời, phần tử của $\Bbb{P}$ cũng biểu thị phạm vi giá trị của "**tọa độ**" của vectơ.

Các điều kiện 1-4 mô tả quan hệ giữa "co giãn" và "chồng cộng". Có thể hiểu chúng thông qua các mũi tên trên mặt phẳng hai chiều.

<span id="&#31616;&#21333;&#24615;&#36136;"></span>
### Một số tính chất đơn giản

???+ note "Ghi chú"
    Các tính chất sau có thể tìm thấy trong lý thuyết nhóm, v.v.

Với không gian tuyến tính $(V,+,\cdot,\Bbb{P})$:

1.  $\theta$ là duy nhất.
2.  $\forall\alpha\in V$,$-\alpha$ là duy nhất.
3.  $\exists 0\in\mathbb{P}$,$\forall\alpha\in V$, có $0\alpha=\theta$.
4.  $\forall k\in\mathbb{P}$, có $k\theta=\theta$.
5.  $(-1)\alpha=-\alpha,~\forall\alpha\in V$.
6.  Không có ước không: $\forall\alpha\in V,k\in\mathbb{P}$, có $k\alpha=\theta\implies k=0\lor\alpha=\theta$.
7.  Luật khử của phép cộng: $\forall\alpha,\beta,\gamma\in V$, có $\alpha+\beta=\alpha+\gamma\implies\beta=\gamma$.

    > Thật ra, luật khử của phép cộng là tính chất của nhóm Abel.

<span id="&#20363;&#23376;"></span>
### Ví dụ

1.  $\Bbb{P}^n$ với phép cộng và phép nhân trên trường số $\Bbb{P}$ tạo thành một không gian tuyến tính trên $\Bbb{P}$. Ví dụ $\Bbb{P}$ có thể là $\Bbb{R}$, $\Bbb{C}$, $\Bbb{N}_p$ ($p$ là số nguyên tố), v.v.
2.  Tập các ma trận cấp $n\times m$ trên trường số $\Bbb{P}$, tức $\Bbb{P}^{n\times m}$, với phép cộng ma trận và nhân vô hướng tạo thành một không gian tuyến tính trên $\Bbb{P}$.
3.  Vành đa thức một biến $\Bbb{P}[x]$ trên trường số $\Bbb{P}$ với phép cộng đa thức và nhân vô hướng tạo thành một không gian tuyến tính trên $\Bbb{P}$.
4.  Tập tất cả hàm liên tục trên đoạn $[a,b]$ (ký hiệu $C[a,b]$) với "phép cộng hàm" và "nhân giá trị với hàm liên tục" tạo thành một không gian tuyến tính trên miền giá trị.

<span id="&#30456;&#20851;&#27010;&#24565;"></span>
## Các khái niệm liên quan

<span id="&#32447;&#24615;&#30456;&#20851;&#12289;&#32447;&#24615;&#26080;&#20851;"></span>
### Phụ thuộc tuyến tính và độc lập tuyến tính

Với không gian tuyến tính $(V,+,\cdot,\Bbb{P})$:

1.  $a_1,a_2,\dots,a_n\in V$ được gọi là một **hệ vectơ** của $V$.
2.  Với $k_1,k_2,\dots,k_n\in\Bbb{P}$, $\sum_{i=1}^nk_ia_i$ được gọi là một **tổ hợp tuyến tính** của hệ vectơ $a_1,a_2,\dots,a_n$.
3.  Nếu vectơ $\beta\in V$ có thể được biểu diễn thành một tổ hợp tuyến tính của hệ vectơ $a_1,a_2,\dots,a_n$, ta nói $\beta$ có thể được **biểu diễn tuyến tính** bởi hệ vectơ $a_1,a_2,\dots,a_n$.
4.  Với $k_1,k_2,\dots,k_n\in\Bbb{P}$, nếu hệ vectơ $a_1,a_2,\dots,a_n$ thỏa mãn $\sum_{i=1}^nk_ia_i=\theta\iff k_i=0, i=1,2,\dots,n$, thì hệ vectơ $a_1,a_2,\dots,a_n$ được gọi là **độc lập tuyến tính**; ngược lại gọi là **phụ thuộc tuyến tính**.

Quy ước rằng vectơ không phụ thuộc tuyến tính với mọi vectơ.

Biểu thức biểu diễn tuyến tính hoặc phụ thuộc tuyến tính có thể viết dưới dạng phép nhân ma trận:

$$
\beta=k_1a_1+k_2a_2+\cdots+k_ra_r=(a_1,a_2,\cdots,a_r)\begin{pmatrix} k_1 \\ k_2 \\ \vdots \\ k_r \end{pmatrix}
$$

Theo thói quen, các vectơ $a$ được viết cạnh nhau theo thứ tự ở bên trái; các vô hướng $k$ được viết dọc theo thứ tự ở bên phải, tạo thành một "vectơ cột".

Chú ý: "vectơ cột" tạo bởi các vô hướng ở đây chỉ là ký hiệu hình thức cho tiện, không thuộc không gian $V$, và về bản chất khác với các vectơ ở bên trái. Nếu các vectơ bên trái tình cờ là vectơ cột, việc ghép chúng cạnh nhau có thể hình thức tạo thành một "ma trận"; tích trên khi đó đúng là dạng "ma trận nhân trái với vectơ cột" thường gặp trong ma trận.

Phần sau sẽ chỉ ra rằng biểu diễn tuyến tính ở đây cũng tương đương với việc vectơ $\beta$ nằm trong không gian ảnh của ma trận $(a_1,a_2\cdots,a_r)$.

Theo định nghĩa bên dưới, vectơ không chắc chắn nằm trong không gian ảnh. Nếu nhìn từ góc độ ánh xạ tuyến tính, phụ thuộc tuyến tính tương đương với việc có nhiều vectơ sau biến đổi đi tới vectơ không, còn độc lập tuyến tính tương đương với việc chỉ bản thân vectơ không đi tới vectơ không.

<span id="&#24615;&#36136;"></span>
#### Tính chất

Với không gian tuyến tính $(V,+,\cdot,\Bbb{P})$:

1.  Nếu một phần của hệ vectơ phụ thuộc tuyến tính thì cả hệ vectơ phụ thuộc tuyến tính. Nếu hệ vectơ độc lập tuyến tính thì mọi phần không rỗng của nó đều độc lập tuyến tính. Có thể nhớ ngắn gọn: **"hệ lớn độc lập thì hệ nhỏ độc lập"; "hệ nhỏ phụ thuộc thì hệ lớn phụ thuộc"**.
2.  Hệ vectơ chứa $\theta$ phụ thuộc tuyến tính.
3.  Hệ vectơ phụ thuộc tuyến tính khi và chỉ khi một vectơ nào đó trong hệ có thể được biểu diễn tuyến tính bởi các vectơ còn lại.
4.  Nếu vectơ $\beta$ có thể được biểu diễn tuyến tính bởi hệ vectơ $a_1,a_2,\dots,a_n$, thì cách biểu diễn là duy nhất khi và chỉ khi hệ vectơ $a_1,a_2,\dots,a_n$ độc lập tuyến tính.
5.  Nếu hệ vectơ $a_1,a_2,\dots,a_n$ độc lập tuyến tính, thì vectơ $\beta$ có thể được biểu diễn tuyến tính bởi hệ vectơ $a_1,a_2,\dots,a_n$ khi và chỉ khi hệ vectơ $a_1,a_2,\dots,a_n,\beta$ phụ thuộc tuyến tính.

<span id="&#26497;&#22823;&#32447;&#24615;&#26080;&#20851;&#32452;&#12289;&#31209;"></span>
### Hệ con độc lập tuyến tính cực đại và hạng

Phụ thuộc tuyến tính có thể hiểu là "dư thừa": bên trong hệ vectơ có một số vectơ có thể được biểu diễn bởi các vectơ khác, nên có thể xóa đi. Sau khi xóa hết phần dư thừa, phần còn lại là một hệ con độc lập tuyến tính cực đại.

Với không gian tuyến tính $(V,+,\cdot,\Bbb{P})$:

1.  Với hệ vectơ $b_1,b_2,\dots,b_m$, đặt $\{a_1,a_2,\dots,a_n\}\subseteq\{b_1,b_2,\dots,b_m\}$. Nếu:

    -   Hệ vectơ $a_1,a_2,\dots,a_n$ độc lập tuyến tính.
    -   $\forall\beta\in\{b_1,b_2,\dots,b_m\}\setminus\{a_1,a_2,\dots,a_n\}$, hệ vectơ $a_1,a_2,\dots,a_n,\beta$ phụ thuộc tuyến tính.

    thì hệ vectơ $a_1,a_2,\dots,a_n$ được gọi là một **hệ con độc lập tuyến tính cực đại** của hệ vectơ $b_1,b_2,\dots,b_m$. Tương tự, có thể định nghĩa hệ con độc lập tuyến tính cực đại của không gian tuyến tính $V$.

    Quy ước hệ con độc lập tuyến tính cực đại của hệ vectơ $\theta,\theta,\dots,\theta$ là tập rỗng; vì thế hệ vectơ tương ứng với ma trận toàn $0$ không có hệ con độc lập tuyến tính cực đại không rỗng.

    Cách xóa vectơ khỏi hệ vectơ không duy nhất, nên hệ con độc lập tuyến tính cực đại cũng không duy nhất. Theo thói quen, ta xóa theo thứ tự từ trái sang phải.

    Một điều khá thú vị là nếu xóa theo thứ tự, các vectơ còn lại đúng là các cột chứa phần tử $1$ trong ma trận dạng bậc thang rút gọn sau khử Gauss khi nhìn theo quan điểm "theo hàng".

    Kích thước của hệ con độc lập tuyến tính cực đại của hệ vectơ $b_1,b_2,\dots,b_m$ được gọi là **hạng** của hệ vectơ, ký hiệu $\operatorname{rank}\{b_1,b_2,\dots,b_m\}$. Quy ước $\operatorname{rank}\{\theta,\theta,\dots,\theta\}=0$.

    Do đó, định nghĩa hạng của hệ vectơ hoàn toàn nhất quán với định nghĩa hạng của ma trận.

2.  Nếu hệ vectơ $a_1,a_2,\dots,a_n$ có thể biểu diễn tuyến tính mọi vectơ trong hệ $b_1,b_2,\dots,b_m$, ta nói hệ vectơ $b_1,b_2,\dots,b_m$ có thể được biểu diễn tuyến tính bởi hệ vectơ $a_1,a_2,\dots,a_n$.

3.  Nếu hệ vectơ $a_1,a_2,\dots,a_n$ có thể được biểu diễn tuyến tính bởi hệ vectơ $b_1,b_2,\dots,b_m$, đồng thời hệ vectơ $b_1,b_2,\dots,b_m$ có thể được biểu diễn tuyến tính bởi hệ vectơ $a_1,a_2,\dots,a_n$, thì hai hệ vectơ được gọi là **tương đương**, ký hiệu $\{a_1,a_2,\dots,a_n\}\cong\{b_1,b_2,\dots,b_m\}$.

    **Tương đương** của hệ vectơ nghĩa là các không gian do chúng sinh ra là như nhau. Các hệ vectơ sinh ra cùng một không gian thì tương đương với nhau; các hệ vectơ sinh ra các không gian khác nhau thì không tương đương.

    Điều kiện tương đương của hệ vectơ mạnh hơn điều kiện tương đương của ma trận: không chỉ yêu cầu hạng bằng nhau, mà còn yêu cầu không gian hoàn toàn giống nhau. Vì vậy, khi ghép hai ma trận **theo chiều ngang**, hạng không được thay đổi.

    Tương đương ma trận chỉ yêu cầu hạng bằng nhau, nên tương đương ma trận biểu thị rằng ma trận hoặc không gian phía trước có thể đi tới ma trận hoặc không gian phía sau thông qua một biến đổi khả nghịch.

<span id="&#24615;&#36136;_1"></span>
#### Tính chất

Với không gian tuyến tính $(V,+,\cdot,\Bbb{P})$:

1.  Giả sử hệ vectơ $a_1,a_2,\dots,a_n$ có thể được biểu diễn tuyến tính bởi hệ vectơ $b_1,b_2,\dots,b_m$.
    -   Nếu $n>m$, thì hệ vectơ $a_1,a_2,\dots,a_n$ phụ thuộc tuyến tính.
    -   Nếu hệ vectơ $a_1,a_2,\dots,a_n$ độc lập tuyến tính, thì $n\leq m$.

2.  Các hệ vectơ độc lập tuyến tính tương đương có cùng kích thước.

    Mọi hệ con độc lập tuyến tính cực đại của một hệ vectơ đều có cùng kích thước.

3.  Hệ vectơ độc lập tuyến tính khi và chỉ khi hạng của nó bằng kích thước của nó.

4.  Nếu hệ vectơ $a_1,a_2,\dots,a_n$ có thể được biểu diễn tuyến tính bởi hệ vectơ $b_1,b_2,\dots,b_m$, thì $\operatorname{rank}\{a_1,a_2,\dots,a_n\}\leq\operatorname{rank}\{b_1,b_2,\dots,b_m\}$.

5.  Các hệ vectơ tương đương có hạng bằng nhau.

<span id="&#32447;&#24615;&#21253;"></span>
### Bao tuyến tính

Với không gian tuyến tính $(V,+,\cdot,\Bbb{P})$, tập $\left\{v=\sum_{i=1}^nk_ia_i:a_i\in V,k_i\in\Bbb{P},i=1,2,\dots,n\right\}$ cũng tạo thành một không gian tuyến tính, gọi là không gian tuyến tính **sinh bởi** hệ vectơ $a_1,a_2,\dots,a_n$ (hoặc **bao tuyến tính**), ký hiệu $\operatorname{span}\{a_1,a_2,\dots,a_n\}$.

$n$ vectơ $a$ ở đây không nhất thiết độc lập tuyến tính.

<span id="&#32447;&#24615;&#23376;&#31354;&#38388;"></span>
### Không gian con tuyến tính

Với không gian tuyến tính $(V,+,\cdot,\Bbb{P})$, nếu hệ đại số $(V_1,+,\cdot,\Bbb{P})$ thỏa mãn:

1.  $\varnothing\ne V_1$
2.  $V_1\subseteq V$
3.  $V_1$ cùng với $+,\cdot$ tạo thành một không gian tuyến tính trên $\mathbb{P}$

thì $V_1$ được gọi là không gian con tuyến tính của $V$, gọi tắt là không gian con, ký hiệu $V_1\leq V$.

Mọi không gian $V$ đều có hai **không gian con tầm thường**: chính nó $V$ và không gian con không. Không gian con không chỉ chứa vectơ không, không chứa vectơ độc lập tuyến tính nào.

Nếu thay $\subseteq$ trong điều 2 bằng $\subset$, thì $V_1$ được gọi là không gian con tuyến tính thực sự của $V$, ký hiệu $V_1<V$.

Không khó để chứng minh: tập con không rỗng $V_1$ của không gian tuyến tính $V$ là không gian con tuyến tính của nó khi và chỉ khi các phép toán tuyến tính đóng trên $V_1$, tức:

1.  $\forall u,v\in V_1$,$u+v\in V_1$.
2.  $\forall v\in V_1$,$\forall k\in \Bbb{P}$,$kv\in V_1$.

<span id="&#20132;&#12289;&#21644;&#19982;&#30452;&#21644;&#12289;&#30452;&#31215;"></span>
### Giao, tổng, tổng trực tiếp và tích trực tiếp

Với các không gian tuyến tính $(V_1,+,\cdot,\Bbb{P})$ và $(V_2,+,\cdot,\Bbb{P})$:

1.  Không khó kiểm tra rằng phép cộng và nhân vô hướng đóng trên $V_1\cap V_2$, nên $V_1\cap V_2$ được gọi là **giao** của các không gian tuyến tính $V_1$ và $V_2$.

    Tương tự, có thể định nghĩa giao của nhiều không gian tuyến tính $\bigcap_{i=1}^m V_i$.

2.  Nếu không gian tuyến tính $V$ thỏa mãn $V=\{u+v|u\in V_1,v\in V_2\}$, thì $V$ được gọi là **tổng** của các không gian tuyến tính $V_1$ và $V_2$, ký hiệu $V=V_1+V_2$.

    Có thể kiểm tra rằng $V_1+V_2$ là không gian con nhỏ nhất chứa $V_1\cup V_2$.

    Tương tự, có thể định nghĩa tổng của nhiều không gian tuyến tính $\sum_{i=1}^m V_i$.

3.  Giả sử $V=V_1+V_2$. Nếu mọi phần tử $v$ trong không gian tuyến tính $V$ chỉ có duy nhất một cặp vectơ $v_1,v_2$ thỏa mãn $v=v_1+v_2$, thì $V$ được gọi là **tổng trực tiếp** (direct sum) của các không gian tuyến tính $V_1$ và $V_2$, ký hiệu $V_1\oplus V_2$.

    Tương tự, có thể định nghĩa tổng trực tiếp của nhiều không gian tuyến tính $\bigoplus_{i=1}^m V_i$.

4.  **Tích trực tiếp** $V_1\times V_2$ của $V_1$ và $V_2$ được định nghĩa là tích Descartes của chúng, cùng với phép cộng và nhân vô hướng sau đây, tạo thành một không gian tuyến tính trên $\Bbb{P}$:

    1.  $+:(V_1\times V_2)\times(V_1\times V_2)\mapsto V_1\times V_2; ((u_1,v_1),(u_2,v_2))\to (u_1+u_2,v_1+v_2)$
    2.  $\cdot:\Bbb{P}\times(V_1\times V_2)\mapsto V_1\times V_2; (k,(u,v))\to (ku,kv)$

    Tương tự, có thể định nghĩa tích trực tiếp của nhiều không gian tuyến tính $\prod_{i=1}^m V_i$.

<span id="&#20363;&#23376;_1"></span>
#### Ví dụ

Với không gian tuyến tính $V=\Bbb{R}^3$, xét các không gian tuyến tính:

-   $V_1:=\{(x,0,0)|x\in\Bbb{R}\}$
-   $V_2:=\{(x,y,0)|x,y\in\Bbb{R}\}$
-   $V_3:=\{(0,y,z)|y,z\in\Bbb{R}\}$
-   $V_4:=\{(x,0,z)|x,z\in\Bbb{R}\}$

Khi đó:

1.  $V_1<V_2<V$,$V_3<V$.
2.  $V_2=V_1+V_2$.
3.  $V=V_1\oplus V_3=V_2+V_3$.
4.  $V_2\oplus V_3=V_4$,$V_2\oplus V_4=V_3$,$V_3\oplus V_4=V_2$.
5.  $V_2+V_3\leq V$.

<span id="&#24615;&#36136;_2"></span>
#### Tính chất

1.  Gọi $V_1,V_2,V_3$ là các không gian tuyến tính trên $\Bbb{P}$. Tương tự giao của tập hợp, giao của không gian tuyến tính thỏa mãn:
    1.  Tính giao hoán: $V_1\cap V_2=V_2\cap V_1$.
    2.  Tính kết hợp: $V_1\cap(V_2\cap V_3)=(V_1\cap V_2)\cap V_3$.
2.  Gọi $V_1,V_2,V_3$ là các không gian tuyến tính trên $\Bbb{P}$. Tương tự hợp của tập hợp, tổng của không gian tuyến tính thỏa mãn:
    1.  Tính giao hoán: $V_1+V_2=V_2+V_1$.
    2.  Tính kết hợp: $V_1+(V_2+V_3)=(V_1+V_2)+V_3$.
3.  Gọi $V_1,V_2,V_3$ là các không gian tuyến tính trên $\Bbb{P}$. Giao và tổng của không gian tuyến tính có quan hệ:
    1.  $V_1\cap (V_2+V_3)\supseteq (V_1\cap V_2)+(V_1\cap V_3)$
    2.  $V_1+(V_2\cap V_3)\subseteq (V_1+V_2)\cap (V_1+V_3)$
4.  $\operatorname{span}\{a_1,a_2,\dots,a_n\}+\operatorname{span}\{b_1,b_2,\dots,b_m\}=\operatorname{span}\{a_1,a_2,\dots,a_n,b_1,b_2,\dots,b_m\}$
5.  Gọi $V_1,V_2$ là các không gian tuyến tính trên $\Bbb{P}$, các mệnh đề sau tương đương:

    1.  $V_1+V_2=V_1\oplus V_2$

    2.  $\exists \beta\in V_1+V_2$ sao cho cách tách thành tổng của một vectơ trong $V_1$ và một vectơ trong $V_2$ là duy nhất (từ "mọi" có thể đổi thành "tồn tại").

    3.  Cách tách $\theta$ thành tổng của một vectơ trong $V_1$ và một vectơ trong $V_2$ là duy nhất.

    4.  $V_1\cap V_2=\{\theta\}$

    ???+ note "Chứng minh"
        $1\implies 2$: suy ra trực tiếp từ định nghĩa.
        
        $2 \implies 3$:
        
        Gọi $\beta=\beta_1+\beta_2$, trong đó $\beta_1\in V_1, \beta_2\in V_2$. Nếu $\theta=\alpha_1+\alpha_2$,$\theta\ne\alpha_1\in V_1,\alpha_2\in V_2$, thì $\beta=\beta+\theta=(\beta_1+\alpha_1)+(\beta_2+\alpha_2)$.
        
        Mà $\beta_1\ne\beta_1+\alpha_1$, mâu thuẫn với điều kiện.
        
        $3 \implies 4$:
        
        Lấy một vectơ khác không $\alpha$ trong $V_1$ và $V_2$, khi đó $\theta=\alpha+(-\alpha)=(-\alpha)+\alpha$, mâu thuẫn với điều kiện.
        
        $4 \implies 1$:
        
        Nếu $V_1+V_2$ không phải tổng trực tiếp, thì tồn tại $\beta\in V_1+V_2$ sao cho $\beta=\beta_1+\beta_2=\gamma_1+\gamma_2$, trong đó $\beta_1,\gamma_1\in V_1,\beta_2,\gamma_2\in V_2$ và $\beta_1,\beta_2,\gamma_1,\gamma_2$ đôi một khác nhau.
        
        Suy ra $\theta\ne\beta_1-\gamma_1=\gamma_2-\beta_2\in V_1\cap V_2$, mâu thuẫn với điều kiện.

<span id="&#21516;&#26500;"></span>
### Đẳng cấu

Giả sử $V,V'$ đều là không gian tuyến tính trên trường $\Bbb{P}$. Nếu tồn tại song ánh $\sigma:V\mapsto V'$ bảo toàn phép cộng và nhân vô hướng, tức với $\forall u,v\in V$,$\forall k\in\Bbb{P}$ thỏa mãn:

1.  $\sigma(u+v)=\sigma(u)+\sigma(v)$
2.  $\sigma(ku)=k\sigma(u)$

thì $\sigma$ được gọi là **ánh xạ đẳng cấu** từ $V$ tới $V'$. Khi đó $V$ và $V'$ được gọi là **đẳng cấu**, ký hiệu $V\cong V'$.

???+ note "Ghi chú"
    Nếu $\sigma$ là đơn ánh thì có thể định nghĩa **đơn đồng cấu**; nếu $\sigma$ là toàn ánh thì có thể định nghĩa **toàn đồng cấu**.

<span id="&#24615;&#36136;_3"></span>
#### Tính chất

1.  Hai không gian tuyến tính trên trường $\Bbb{P}$ đẳng cấu khi và chỉ khi chúng có cùng số chiều. (Định nghĩa số chiều xem ở [cơ sở tuyến tính](./basis.md).)
2.  (Hệ quả của 1) Không gian tuyến tính $n$ chiều trên trường $\Bbb{P}$ đẳng cấu với không gian tuyến tính $\Bbb{P}^n$.

    ???+ note "Ghi chú"
        Tính chất này cho thấy về cơ bản ta có thể xem tọa độ và vectơ như nhau.

<span id="&#27431;&#27663;&#31354;&#38388;&#19982;&#32447;&#24615;&#31354;&#38388;&#30340;&#20851;&#31995;"></span>
## Quan hệ giữa không gian Euclid và không gian tuyến tính

Lấy không gian Euclid ba chiều quen thuộc nhất làm ví dụ, một số khái niệm liên quan của nó tương ứng với không gian tuyến tính như bảng sau:

| Không gian Euclid ba chiều | Không gian tuyến tính |
| -------------------------- | --------------------- |
| Vectơ                      | Vectơ                 |
| Vuông góc                  | Trực giao (tức tích trong bằng $0$) |
| Ba vectơ thẳng hàng/đồng phẳng | $k$ vectơ phụ thuộc tuyến tính |
| Ba vectơ không đồng phẳng  | $k$ vectơ độc lập tuyến tính |
| Vectơ cơ sở                | [Cơ sở tuyến tính](./basis.md) |
| Số chiều của không gian    | Số chiều của không gian |

<span id="&#24212;&#29992;"></span>
## Ứng dụng

Từ phần này trở đi chủ yếu trình bày quan điểm "nhìn theo cột" đối với hệ phương trình tuyến tính.

Bản thân ma trận $A$ cũng được tạo bởi các vectơ cột. Hãy xem $A$ như một hệ vectơ cột, còn $x$ là các hệ số chưa biết, và xét liệu hệ vectơ cột trong $A$ có thể phối hợp với các ẩn để tạo ra vectơ cột $b$ hay không. Lúc này vectơ cột $x$ hoàn toàn chưa biết.

Phương trình đang xét $Ax=b$ được viết lại thành:

$$
\alpha_1 x_1 +\alpha_2 x_2 +\cdots+\alpha_n x_n=b 
$$

Khi đó trong phép nhân ma trận, ma trận $A$ ở bên trái có thể được xem là một hệ vectơ, tức một hệ vectơ cột. Hệ vectơ cột này, với vai trò một hệ cơ sở, sinh ra một không gian; ta xét xem vectơ cột $b$ có nằm trong không gian đó hay không.

<span id="&#25353;&#21015;&#30475;&#24453;&#32447;&#24615;&#26041;&#31243;&#32452;&#30340;&#35299;"></span>
### Nhìn nghiệm của hệ phương trình tuyến tính theo cột

Hạng là số vectơ trong hệ con độc lập tuyến tính cực đại, đại diện cho "ràng buộc". Các vectơ còn lại đem lại bậc tự do cho nghiệm, tức cho phép gán các vectơ dư thừa ở những hướng khác.

Nếu ký hiệu $n$ là số cột của ma trận $A$, tức số vectơ cột mà nó chứa, và ký hiệu $r(A)$ là hạng của ma trận A, thì bậc tự do $S$ là:

$$
S=n-r(A)
$$

Tập tất cả nghiệm của hệ phương trình cũng tạo thành một hệ vectơ; bậc tự do $S$ chính là hạng của hệ vectơ nghiệm của $Ax=0$, tức số chiều của không gian hạt nhân bên dưới.

<span id="&#26041;&#31243;&#32452;&#30340;&#21516;&#35299;"></span>
### Hệ phương trình tương đương nghiệm

Nghiệm chung của hai hệ phương trình được định nghĩa là giao của hai tập nghiệm.

Hai hệ phương trình **tương đương nghiệm** nghĩa là tập nghiệm của chúng bằng nhau. Hai hệ có tập nghiệm bằng nhau thì tương đương nghiệm; hai hệ có tập nghiệm không bằng nhau thì không tương đương nghiệm.

Tương đương nghiệm của hệ phương trình cũng mạnh hơn điều kiện tương đương ma trận: không chỉ yêu cầu hạng bằng nhau, mà còn yêu cầu sau khi ghép hai ma trận **theo chiều dọc**, hạng vẫn không thay đổi.

So sánh với tương đương của hệ vectơ: tương đương của hệ vectơ yêu cầu ghép ma trận theo chiều ngang mà hạng không đổi. Do đó có quan hệ sau:

Tương đương ma trận không nhất thiết kéo theo tương đương hệ vectơ hoặc tương đương nghiệm của hệ phương trình; nhưng nếu có tương đương hệ vectơ hoặc tương đương nghiệm của hệ phương trình thì chắc chắn có tương đương ma trận tương ứng (hạng bằng nhau).

Nếu hệ vectơ tương ứng với ma trận là tương đương, thì sau khi chuyển vị ma trận, hệ phương trình tương ứng là tương đương nghiệm, và ngược lại.

<span id="&#30697;&#38453;&#30340;&#26680;&#31354;&#38388;&#19982;&#20687;&#31354;&#38388;"></span>
### Không gian hạt nhân và không gian ảnh của ma trận

Phần này trình bày không gian hạt nhân và không gian ảnh từ góc độ không gian tuyến tính.

Với ma trận $A$, gọi $W$ là tập tất cả nghiệm $x$ của phương trình $Ax=0$. Khi đó $W$ là một không gian tuyến tính, và trường vô hướng của $W$ giống với trường chứa các phần tử của $A$.

Khi đó $W$ được gọi là **không gian hạt nhân** của ma trận $A$, ký hiệu $N(A)$.

Không gian hạt nhân $N(A)$ của ma trận $A$ chính là **không gian nghiệm** của phương trình $Ax=0$. Theo định nghĩa cơ sở ở phần sau, **hệ nghiệm cơ bản** của phương trình này chính là một cơ sở của không gian hạt nhân.

Nếu ma trận $A$ là ma trận khả nghịch, thì không gian hạt nhân $N(A)$ của $A$ chỉ chứa vectơ không.

Với ma trận $A$, gọi $n$ cột của nó là các vectơ $\alpha$. Không gian sinh bởi $n$ vectơ cột $\alpha$ được gọi là **không gian ảnh** của $A$, hoặc **không gian cột**, ký hiệu:

$$
R(A)=\operatorname{span}\{\alpha_1,\alpha_2,\cdots,\alpha_n\}
$$

Theo định nghĩa số chiều ở phần sau, số chiều của không gian ảnh bằng hạng của ma trận $A$.

Theo định nghĩa, với mỗi phần tử $y$ trong không gian ảnh $R(A)$, đều có một biểu diễn tương ứng:

$$
y=k_1\alpha_1+k_2\alpha_2+\cdots+k_n\alpha_n=(\alpha_1,\alpha_2,\cdots,\alpha_n)\begin{pmatrix}k_1\\k_2\\\vdots\\k_n\end{pmatrix}=A\begin{pmatrix}k_1\\k_2\\\vdots\\k_n\end{pmatrix}
$$

Do đó không gian ảnh $R(A)$ chính là **miền giá trị** của $Ax$ khi $x$ chạy qua mọi vectơ.

Tương tự, có thể định nghĩa **không gian hàng** của $A$, tức miền giá trị $R(A^T)$ của ma trận chuyển vị của $A$.

Vì hạng hàng của ma trận bằng hạng cột, số chiều của không gian hàng cũng bằng hạng của ma trận. Do đó phép chuyển vị làm thay đổi không gian ảnh, nhưng không làm thay đổi số chiều của không gian ảnh.

Tại đây có thể liên hệ với phần trước:

Tương đương của hệ vectơ tương đương với việc không gian ảnh $R(A)$ của ma trận tương ứng là như nhau.

Tương đương nghiệm của hệ phương trình tương đương với việc không gian hàng $R(A^T)$ của ma trận tương ứng là như nhau.

<span id="&#21442;&#32771;&#36164;&#26009;&#19982;&#27880;&#37322;"></span>
## Tài liệu tham khảo và chú thích

1.  Qiu Weisheng, *Advanced Algebra (Vol. 2)*. Tsinghua University Press.
2.  [Vector space](https://en.wikipedia.org/w/index.php?title=Vector_space&oldid=1108546097). *Wikipedia, The Free Encyclopedia*.
