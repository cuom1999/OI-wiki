Nếu đã nắm các kiến thức liên quan đến số phức, có thể bỏ qua trang này.

Việc học số phức cần một phần nền tảng về vectơ; nếu chưa học về vectơ, nên đọc [trang vectơ](../math/linear-algebra/vector.md) trước.

## Số phức

### Dẫn nhập

???+ note "Chú thích"
    Cách dẫn nhập dưới đây lấy từ sách Toán trung học phổ thông bản A bắt buộc 2 của Nhân giáo bản.

Nhìn từ góc độ phương trình, việc một số thực âm có căn bậc hai hay không chính là việc phương trình $x^2+a=0 (a>0)$ có nghiệm hay không; tiếp đó có thể quy về việc phương trình $x^2+1=0$ có nghiệm hay không.

Nhìn lại quá trình mở rộng các tập số đã biết, mỗi lần mở rộng đều gắn chặt với nhu cầu thực tế. Chẳng hạn, để giải quyết việc đo đường chéo hình vuông, cũng như vấn đề phương trình $x^2-2=0$ không có nghiệm trong tập số hữu tỉ, tập số hữu tỉ đã được mở rộng thành tập số thực. Sau khi mở rộng tập số, phép cộng và phép nhân được quy định trong tập số thực vẫn tương thích với phép cộng và phép nhân vốn có trong tập số hữu tỉ; đồng thời phép cộng và phép nhân đều thỏa mãn tính giao hoán và tính kết hợp, còn phép nhân phân phối đối với phép cộng.

Theo tư tưởng đó, để giải quyết vấn đề phương trình $x^2+1=0$ không có nghiệm trong tập số thực, có thể hình dung việc đưa vào một số mới $\mathrm{i}$ sao cho $x=\mathrm{i}$ là nghiệm của phương trình $x^2+1=0$, tức là $\mathrm{i}^2=-1$.

Khi thêm số mới $\mathrm{i}$ vào tập số thực, cần giữ cho $\mathrm{i}$ và các số thực vẫn có thể thực hiện phép cộng và phép nhân giống như giữa các số thực; đồng thời mong muốn phép cộng và phép nhân đều thỏa mãn tính giao hoán, tính kết hợp, và phép nhân phân phối đối với phép cộng. Vậy sau khi tập số thực được mở rộng, tập số mới gồm những số nào?

Theo giả thiết trên, nhân số thực $b$ với $\mathrm{i}$, kết quả được viết là $b\mathrm{i}$; cộng số thực $a$ với $b\mathrm{i}$, kết quả được viết là $a+b\mathrm{i}$. Mọi số thực và cả $\mathrm{i}$ đều có thể viết dưới dạng $a+b\mathrm{i}(a,b\in \mathbf{R})$, vì thế các số này đều nằm trong tập số mới sau khi mở rộng.

### Định nghĩa

Định nghĩa các số có dạng $a+b\mathrm{i}$, trong đó $a,b\in \mathbf{R}$, là **số phức**; $\mathrm{i}$ được gọi là **đơn vị ảo**. Tập hợp tất cả các số phức được gọi là **tập số phức**, ký hiệu $\mathbf{C}$.

Số phức thường được ký hiệu bằng $z$, tức $z=a+b\mathrm{i}$. Dạng này được gọi là **dạng đại số của số phức**. Trong đó $a$ được gọi là **phần thực** của số phức $z$, ký hiệu $\operatorname{Re}(z)$; $b$ được gọi là **phần ảo** của số phức $z$, ký hiệu $\operatorname{Im}(z)$. Nếu không nói gì thêm, luôn có $a,b\in \mathbf{R}$.

Với một số phức $z$, nó là số thực khi và chỉ khi $b=0$; nó là số ảo khi $b\not = 0$; và nó là số thuần ảo khi $a=0$ đồng thời $b\not = 0$.

Quan hệ giữa số thuần ảo, số ảo, số thực và số phức được minh họa trong hình sau.

![](./images/complex-relation.svg)

## Tính chất và phép toán

### Ý nghĩa hình học

Những số có dạng tương tự $a+b\mathrm{i}$ đã được gọi là số phức, đồng thời đã có định nghĩa và phân loại; tiếp theo có thể khai thác các tính chất sâu hơn.

Khi đặt mọi số thực lên trục số, các điểm trên trục số tương ứng một-một với các số thực. Có thể xử lý số phức theo cách tương tự.

Trước hết, định nghĩa **hai số phức bằng nhau**: hai số phức $z_1=a+b\mathrm{i},z_2=c+d\mathrm{i}$ bằng nhau khi và chỉ khi $a=c$ và $b=d$.

Định nghĩa này xuất phát trực tiếp từ dạng đại số của số phức.

Nói cách khác, có thể dùng duy nhất một cặp số thực có thứ tự $(a,b)$ để biểu diễn một số phức $z=a+b\mathrm{i}$. Từ đó, liên hệ với hệ tọa độ Descartes trong mặt phẳng cho thấy **tập số phức tương ứng một-một với tập các điểm trong hệ tọa độ Descartes phẳng**. Như vậy, thu được một ý nghĩa hình học của số phức.

Khi đó hệ tọa độ Descartes phẳng này không còn hoàn toàn thông thường, vì các điểm trong đó mang ý nghĩa đặc biệt: chúng biểu diễn số phức. Do đó hệ tọa độ Descartes phẳng như vậy được gọi là **mặt phẳng phức**, trục $x$ là **trục thực**, trục $y$ là **trục ảo**. Nói thêm: **tập số phức tương ứng một-một với tập hợp tất cả các điểm trong mặt phẳng phức**.

Xét kiến thức đã học về vectơ phẳng, biểu diễn tọa độ của vectơ cũng là một cặp số thực có thứ tự $(a,b)$. Số phức $z=a+b\mathrm{i}$ tương ứng với điểm $Z(a,b)$ trong mặt phẳng phức, và cũng tương ứng với vectơ phẳng $\overrightarrow{OZ}=(a,b)$. Vì thế thu được một ý nghĩa hình học khác của số phức: **tập số phức tương ứng một-một với tập hợp các vectơ trong mặt phẳng phức (số thực $0$ tương ứng với vectơ không)**.

Do đó, chuyển kiến thức về vectơ sang số phức, định nghĩa **môđun của số phức** là độ dài của vectơ tương ứng với số phức đó. Môđun của số phức $z=a+b\mathrm{i}$ là $|z|=\sqrt{a^2+b^2}$.

Để thuận tiện, thường gọi số phức $z=a+b\mathrm{i}$ là điểm $Z$ hoặc vectơ $\overrightarrow {OZ}$, và quy ước các vectơ bằng nhau biểu diễn cùng một số phức.

Từ kiến thức vectơ cũng suy ra các số ảo không thể so sánh lớn nhỏ (nhưng các số thực thì có thể).

### Phép cộng và phép trừ

Với các số phức $z_1=a+b\mathrm{i},z_2=c+d\mathrm{i}$, định nghĩa quy tắc cộng như sau:

$$
z_1+z_2=(a+c)+(b+d)\mathrm{i}
$$

Tổng của hai số phức vẫn là số phức.

Xét phép cộng vectơ cho thấy phép cộng số phức phù hợp với quy tắc cộng vectơ; điều này cũng chứng minh tính đúng đắn của ý nghĩa hình học của số phức.

Tương tự có thể kiểm chứng rằng phép cộng số phức thỏa mãn **tính giao hoán** và **tính kết hợp**. Tức là:

$$
\begin{aligned}
z_1+z_2&=z_2+z_1\\
(z_1+z_2)+z_3&=z_1+(z_2+z_3)
\end{aligned}
$$

Phép trừ là phép toán ngược của phép cộng. Có thể suy ra quy tắc trừ từ quy tắc cộng và định nghĩa bằng nhau của số phức:

$$
z_1-z_2=(a-c)+(b-d)\mathrm{i}
$$

Điều này cũng phù hợp với phép trừ vectơ.

### Phép nhân, phép chia và liên hợp

Với các số phức $z_1=a+b\mathrm{i},z_2=c+d\mathrm{i}$, định nghĩa quy tắc nhân như sau:

$$
\begin{aligned}
z_1z_2&=(a+b\mathrm{i})(c+d\mathrm{i})\\
&=ac+bc\mathrm{i}+ad\mathrm{i}+bd\mathrm{i}^2\\
&=(ac-bd)+(bc+ad)\mathrm{i}
\end{aligned}
$$

Phép nhân hai số phức tương tự phép nhân hai đa thức: chỉ cần thay $\mathrm{i}^2$ bằng $-1$, rồi gộp riêng phần thực và phần ảo.

Phép nhân số phức có dạng tương tự tích vectơ của vectơ.

Phép nhân số phức thỏa mãn **tính giao hoán**, **tính kết hợp** và **tính phân phối đối với phép cộng**, tức:

-   $z_1z_2=z_2z_1$
-   $(z_1z_2)z_3=z_1(z_2z_3)$
-   $z_1(z_2+z_3)=z_1z_2+z_1z_3$

Vì các luật phép toán được thỏa mãn, các **hằng đẳng thức nhân trong trường số thực cũng áp dụng được trong trường số phức**.

Phép chia là phép toán ngược của phép nhân. Có thể suy ra như sau:

$$
\begin{aligned}
\frac{a+b\mathrm{i}}{c+d\mathrm{i}}&=\frac{(a+b\mathrm{i})(c-d\mathrm{i})}{(c+d\mathrm{i})(c-d\mathrm{i})}\\
&=\frac{ac+bd}{c^2+d^2}+\frac{bc-ad}{c^2+d^2}\mathrm{i} &(c+d\mathrm{i}\not =0)
\end{aligned}
$$

Vì vectơ không có phép chia, phần này không bàn về quan hệ với vectơ.

Để hữu tỉ hóa mẫu số, đã nhân thêm $c-d\mathrm{i}$; biểu thức này có ý nghĩa quan trọng.

Với số phức $z=a+b\mathrm{i}$, gọi $a-b\mathrm{i}$ là **số phức liên hợp** của $z$, thường ký hiệu là $\bar z$. Nếu hai số phức liên hợp với nhau thì chúng **đối xứng qua trục thực**.

Với các số phức $z,w$, phép liên hợp phức có các tính chất sau:

-   $z\cdot\bar{z}=|z|^2$
-   $\overline{\overline{z}}=z$
-   $\operatorname{Re}(z)=\dfrac{z+\bar{z}}{2}$, $\operatorname{Im}(z)=\dfrac{z-\bar{z}}{2}$
-   $\overline{z\pm w}=\bar{z}\pm\bar{w}$
-   $\overline{zw}=\bar{z}\bar{w}$
-   $\overline{z/w}=\bar{z}/\bar{w}$

### Argument và giá trị chính của argument

Nếu lấy đơn vị thực $1$ làm hướng ngang dương và đơn vị ảo $\mathrm{i}$ làm hướng thẳng đứng dương, sẽ thu được mặt phẳng phức dưới góc nhìn tọa độ Descartes.

Cũng có thể xác định vị trí của số phức $z$ nhờ tọa độ cực $(r, \theta)$. Phần trên đã nêu $r$ là môđun của số phức $z$.

Góc $\theta$ từ chiều dương của trục thực đến vectơ tương ứng với số phức **khác không** $z=x+\mathrm{i}y$ thỏa mãn quan hệ:

$$
\tan \theta=\frac{y}{x}
$$

Góc này được gọi là **argument** của số phức $z$, ký hiệu:

$$
\theta= \arg z
$$

Một số phức **khác không** $z$ có vô số argument, nên $\arg z$ thực chất là một tập hợp. Dùng $\operatorname{Arg} z$ viết hoa chữ đầu để biểu diễn **một giá trị cụ thể trong đó**, thỏa mãn điều kiện:

$$
-\pi<\operatorname{Arg} z \le \pi
$$

Gọi $\operatorname{Arg} z$ là **giá trị chính của argument** hoặc **argument chính**. Argument là giá trị chính cộng thêm một số nguyên lần (có thể bằng không hoặc là số nguyên âm) của $2k\pi$, tức $\arg z = \{\operatorname{Arg} z + 2k\pi \mid k\in \mathbf Z\}$.

Tổng của hai giá trị chính của argument không nhất thiết vẫn là giá trị chính của argument, còn tổng của hai argument thì luôn là một argument hợp lệ.

Số phức có môđun nhỏ hơn $1$ tạo thành hình **đĩa đơn vị** trên mặt phẳng phức. Số phức có môđun bằng $1$ được gọi là **số phức đơn vị**; toàn bộ các số phức đơn vị tạo thành **đường tròn đơn vị** trên mặt phẳng phức. Khi không gây nhầm lẫn, đôi khi đường tròn đơn vị cũng được gọi tắt là vòng tròn đơn vị.

Dưới góc nhìn tọa độ cực, phép nhân và phép chia số phức trở nên rất đơn giản. Khi nhân số phức, môđun được nhân với nhau, argument được cộng với nhau. Khi chia số phức, môđun được chia cho nhau, argument được trừ cho nhau.

<span id="công-thức-euler"></span>

### Công thức Euler

???+ note "Công thức Euler (Euler's formula)[^ref1]"
    Với mọi số thực $x$, có
    
    $$
    \mathrm{e}^{\mathrm{i}x}=\cos x+\mathrm{i}\sin x
    $$
    
    Sau khi bổ sung định nghĩa của [hàm mũ phức và hàm lượng giác phức](#hàm-mũ-và-hàm-lượng-giác), công thức này có thể mở rộng cho toàn bộ số phức.

<span id="hàm-mũ-và-hàm-lượng-giác"></span>

### Hàm mũ và hàm lượng giác

Với số phức $z=x+\mathrm{i}y$, hàm $f(z)=\mathrm{e}^x(\cos y+\mathrm{i}\sin y)$ thỏa mãn $f(z_1+z_2)=f(z_1)f(z_2)$. Từ đó, định nghĩa **hàm mũ phức** như sau:

$$
\exp z=\mathrm{e}^x(\cos y+\mathrm{i}\sin y)
$$

Hàm mũ phức hoàn toàn nhất quán với định nghĩa của hàm mũ thực trên tập số thực. Trên mặt phẳng phức, nó có các tính chất:

-   Môđun luôn dương: $|\exp z|=\exp x>0$.
-   Argument: $\arg(\exp z)=\{y + 2k\pi \mid k\in\mathbf Z\}$.
-   Định lý cộng: $\exp (z_1+z_2)=\exp (z_1)\exp (z_2)$.
-   Tính tuần hoàn: $\exp z$ là hàm tuần hoàn có chu kỳ cơ bản $2\pi \mathrm{i}$. Nếu chu kỳ của một hàm $f(z)$ là bội nguyên của một chu kỳ nào đó, chu kỳ đó được gọi là **chu kỳ cơ bản**.

**Hàm lượng giác phức** (cũng gọi tắt là **hàm lượng giác**) được định nghĩa như sau:

$$
\cos z=\frac{\exp (\mathrm{i}z)+\exp (-\mathrm{i}z)}{2}
$$

$$
\sin z=\frac{\exp (\mathrm{i}z)-\exp (-\mathrm{i}z)}{2\mathrm{i}}
$$

Nếu lấy $z\in\mathbf{R}$, thì từ [công thức Euler](#công-thức-euler) có:

$$
\cos z=\operatorname{Re}\left(\mathrm{e}^{\mathrm{i}z}\right)
$$

$$
\sin z=\operatorname{Im}\left(\mathrm{e}^{\mathrm{i}z}\right)
$$

Hàm lượng giác phức hoàn toàn nhất quán với định nghĩa của hàm lượng giác thực trên tập số thực. Trên mặt phẳng phức, chúng có các tính chất:

-   Tính chẵn lẻ: hàm sin là hàm lẻ, hàm cos là hàm chẵn.
-   Đồng nhất thức lượng giác: các đồng nhất thức lượng giác thông thường đều đúng, ví dụ tổng bình phương bằng $1$, hoặc các công thức cộng trừ góc.
-   Tính tuần hoàn: hàm sin và hàm cos có chu kỳ cơ bản $2\pi$.
-   Nghiệm không: toàn bộ nghiệm không của hàm sin thực và hàm cos thực tạo thành toàn bộ nghiệm không của hàm sin phức và hàm cos phức. Phép mở rộng này không đưa thêm nghiệm không mới.
-   Môđun không bị chặn: môđun của hàm sin phức và hàm cos phức có thể lớn hơn bất kỳ số dương cho trước nào, không còn bị giới hạn trong phạm vi $1$ như hàm sin thực và hàm cos thực.

## Ba dạng của số phức

Nhờ góc nhìn hệ tọa độ Descartes và hệ tọa độ cực, có thể viết số phức dưới ba dạng.

**Dạng đại số** của số phức dùng để biểu diễn số phức bất kỳ.

$$
z=x+y\mathrm{i}
$$

Dạng đại số thuận tiện cho việc tính bốn phép toán cộng, trừ, nhân, chia số phức.

**Dạng lượng giác** và **dạng mũ** của số phức dùng để biểu diễn số phức khác không.

$$
z=r(\cos \theta +\mathrm{i}\sin \theta)=r \exp (\mathrm{i}\theta)
$$

Hai dạng này thuận tiện hơn cho việc tính hai phép toán nhân, chia và các phép toán phía sau. Nếu chỉ dùng các hàm đã gặp ở bậc phổ thông, có thể dùng dạng lượng giác. Nếu đã đưa vào hàm mũ phức, viết dưới dạng mũ tương đương sẽ thuận tiện hơn.

<span id="căn-đơn-vị"></span>

## Căn đơn vị

Xét nghiệm của phương trình $x^n=1$ trong trường số phức. Phương trình này có $n$ nghiệm; $n$ nghiệm này đều được gọi là **căn đơn vị (phức) bậc $n$** ($n$-th root of unity). Theo kiến thức về mặt phẳng phức, các căn đơn vị bậc $n$ chia đều đường tròn đơn vị thành $n$ phần.

Đặt $\omega_n=\exp\dfrac{2\pi \mathrm{i}}{n}$ (tức là số phức đơn vị có argument $2\pi/n$), thì tập nghiệm của $x^n=1$ được biểu diễn là $\{\omega_n^k\mid k=0,1\cdots,n-1\}$, trong đó,

$$
w_n^k = \exp\dfrac{2\pi k \mathrm{i}}{n} = \cos\dfrac{2\pi k}{n} + \mathrm{i}\sin\dfrac{2\pi k}{n}.
$$

Nếu không nói rõ, căn đơn vị bậc $n$ trong các phát biểu thông thường chỉ nghiệm đầu tiên tính từ $1$ theo chiều ngược chiều kim đồng hồ, tức $\omega_n$ ở trên; các nghiệm khác đều có thể biểu diễn bằng lũy thừa của $\omega_n$.

???+ tip "Vì sao khi nhắc đến căn đơn vị bậc $n$, thường chỉ xét nghiệm đầu tiên?"
    Chủ yếu là để thuận tiện khi áp dụng. Tất cả các căn đơn vị bậc $n$ đều có thể biểu diễn thành lũy thừa của căn đơn vị bậc $n$ đầu tiên $\omega_n$; hơn nữa, với mọi $k < n$, số phức $\omega_n$ đều không phải là căn đơn vị bậc $k$.

### Căn đơn vị nguyên thủy

Trong các căn đơn vị bậc $n$, không chỉ $\omega_n$ có tính chất tương tự. Gọi các phần tử trong tập

$$
\{\omega_n^k\mid 0\le k<n,~\gcd(n,k)=1\}
$$

là **căn đơn vị nguyên thủy bậc $n$** ($n$-th primitive root of unity). Theo biểu thức trên, toàn bộ căn đơn vị nguyên thủy bậc $n$ có $\varphi(n)$ phần tử, trong đó $\varphi(n)$ là [hàm Euler](./number-theory/euler-totient.md).

Một căn đơn vị nguyên thủy bất kỳ $\omega$ đều có cùng tính chất với $\omega_n$ ở trên: với mọi $0<k<n$, lũy thừa bậc $k$ của $\omega$ không bằng $1$, nói cách khác, $\omega$ không phải là căn đơn vị bậc $k$. Vì vậy, từ một căn đơn vị nguyên thủy bất kỳ có thể sinh ra toàn bộ các căn đơn vị.

Để hiểu cấu trúc của căn đơn vị nguyên thủy bậc $n$, cần xét tính chất sau của căn đơn vị:

???+ note "Tính chất"
    Với các số nguyên $n$ và $k$, đặt $d=\gcd(n,k)$, có $\omega_n^k = \omega_{n/d}^{k/d}$.

??? note "Chứng minh"
    Tính trực tiếp được
    
    $$
    w_n^k = \exp\dfrac{2\pi k\mathrm{i}}{n} = \exp\dfrac{2\pi (k/d)\mathrm{i}}{n/d} = \omega_{n/d}^{k/d}.
    $$

Điều này cho thấy, chỉ cần $\gcd(n,k)\neq 1$, thì $\omega_n^k$ là căn đơn vị (nguyên thủy) bậc $\dfrac{n}{\gcd(n,k)}$. Vì vậy, căn đơn vị $\omega_n^k$ thỏa mãn tính chất nói trên phải thỏa mãn $\gcd(n,k)=1$. Đây chính là lý do căn đơn vị nguyên thủy có định nghĩa trên.

Ngoài ra, như một hệ quả đơn giản của các phân tích này, có:

???+ note "Định lý"
    Khi $k$ chạy qua các ước của $n$, toàn bộ căn đơn vị nguyên thủy bậc $k$ vừa đúng tạo thành một phân hoạch của các căn đơn vị bậc $n$. Hơn nữa, với $\ell\perp n$, ánh xạ $x\mapsto x^\ell$ cho một song ánh giữa các căn đơn vị bậc $n$, và giữ nguyên phân hoạch trên: nó vẫn ánh xạ căn đơn vị nguyên thủy bậc $k\mid n$ sang căn đơn vị nguyên thủy bậc $k$.

Dù có nhiều lựa chọn cho căn đơn vị nguyên thủy, do căn đầu tiên $\omega_n$ có dạng đơn giản nhất, trong lập trình thi đấu $\omega_n$ vẫn được dùng phổ biến nhất. Trong một số tình huống, để nâng cao hiệu suất tính toán, cũng có thể cân nhắc dùng [căn đơn vị nguyên thủy](./number-theory/residue.md#căn-đơn-vị) dưới một môđun nào đó thay cho $\omega_n$ trong trường số phức.

## Số phức trong ngôn ngữ lập trình

### Số phức trong C

Trong chuẩn C99, có tệp tiêu đề `<complex.h>`.

Trong tệp tiêu đề `<complex.h>`, có ba kiểu `double complex`, `float complex` và `long double complex`.

Các toán tử số học '+', '-', '\*' và '/' có thể dùng cho mọi tổ hợp giữa số chấm động và số phức. Khi một trong hai vế của biểu thức là số phức, kết quả tính toán là số phức.

Tệp tiêu đề `<complex.h>` cung cấp đơn vị ảo `I`; khi đưa tệp tiêu đề này vào, chữ cái viết hoa `I` không thể dùng làm tên biến.

Đối với một số phức đơn lẻ, `<complex.h>` cung cấp một số thao tác: hàm `creal` dùng để trích phần thực, hàm `cimag` dùng để trích phần ảo, hàm `cabs` dùng để tính môđun, hàm `carg` dùng để tính giá trị chính của argument.

Mỗi hàm đều có ba phiên bản tùy theo kiểu. Ví dụ hàm `creal` có ba phiên bản `creal`, `crealf`, `creall`, dùng để xử lý ba kiểu tương ứng là `double`, `float` và `long double`. Phiên bản không có hậu tố ở cuối mặc định xử lý kiểu `double`. Tất cả các hàm dưới đây đều tuân theo quy luật này, nên không giải thích riêng nữa.

Giá trị trả về của các hàm này đều là số chấm động thông thường. Có thể gán trực tiếp số chấm động thông thường cho số phức, nhưng không thể gán trực tiếp số phức cho số chấm động; khi đó cần dùng các thao tác trích xuất nói trên.

Hàm `conj` dùng để tính số phức liên hợp, giá trị trả về là số phức.

Hàm `cexp` tính hàm mũ phức, `clog` tính giá trị chính của logarit, `csin` tính sin, `ccos` tính cos, `ctan` tính tang.

Hàm `cpow` tính hàm lũy thừa, `csqrt` tính căn bậc hai, `casin` tính arcsin, `cacos` tính arccos, `catan` tính arctan. Các hàm trong phần này đều tính giá trị chính của các hàm đa trị.

### Số phức trong C++

Trong C, `<ctype.h>` khi sang C++ sẽ trở thành `<cctype>`; gần như mọi tệp tiêu đề đều tuân theo quy tắc đặt tên này.

Tuy nhiên, `<complex.h>` không tuân theo quy tắc đó: C++ không có tệp tiêu đề `<ccomplex>`. Số phức trong C++ trực tiếp nằm trong `<complex>`, và nội dung bên trong hoàn toàn khác với C.

Khác biệt này xuất phát từ lịch sử của hai ngôn ngữ: ngay từ phiên bản đầu tiên của C++, C++98, đã có `<complex>`, còn ngôn ngữ C đến C99 mới thêm số phức.

Trong C++, kiểu số phức được định nghĩa bằng `complex<float>`, `complex<double>` và `complex<long double>`. Do tính đa hình của lập trình hướng đối tượng, tên các hàm dưới đây đều là duy nhất, không cần hậu tố f hoặc l.

Một đối tượng số phức có các hàm thành viên `real` và `imag`, dùng để truy cập phần thực và phần ảo.

Một đối tượng số phức có các hàm không phải thành viên `real`, `imag`, `abs`, `arg`, trả về phần thực, phần ảo, môđun và argument.

Một đối tượng số phức còn có các hàm không phải thành viên: `norm` là bình phương môđun, `conj` là số phức liên hợp.

Một đối tượng số phức còn có các hàm không phải thành viên `exp`, `log` (giá trị chính của logarit cơ số $\mathrm{e}$), `log10` (giá trị chính của logarit cơ số 10, không có trong C), `pow`, `sqrt`, `sin`, `cos`, `tan`; ý nghĩa giống như trong C.

Trong C++14 và các phiên bản sau, [toán tử literal `std::literals::complex_literals::""if, ""i, ""il`](https://en.cppreference.com/w/cpp/numeric/complex/operator%2522%2522i.html) đã được định nghĩa. Ví dụ nhập `100if`, `100i` và `100il`, ba biểu thức này lần lượt trả về `std::complex<float>{0.0f, 100.0f}`, `std::complex<double>{0.0, 100.0}` và `std::complex<long double>{0.0l, 100.0l}`. Nhờ vậy có thể viết thuận tiện các khai báo số phức như `auto z = 4.0 + 3i`.

## Tài liệu tham khảo và liên kết

-   [Complex number - Wikipedia](https://en.wikipedia.org/wiki/Complex_number)
-   [Euler's formula - Wikipedia](https://en.wikipedia.org/wiki/Euler's_formula)
-   [Complex number arithmetic - cppreference.com](https://en.cppreference.com/w/c/numeric/complex)
-   [std::complex - cppreference.com](https://en.cppreference.com/w/cpp/numeric/complex)

[^ref1]: Để biết thêm về công thức Euler, có thể tham khảo hai video: [công thức Euler và lý thuyết nhóm sơ cấp](https://www.bilibili.com/video/BV1fx41187tZ), [nhập môn phương trình vi phân - Chương 5: hiểu $\mathrm{e}^{\mathrm{i}\pi}$ trong 3.14 phút](https://www.bilibili.com/video/BV1G4411D7kZ).
