Kiến thức cần có: [khái niệm cơ bản của đại số trừu tượng](./basic.md), [lý thuyết nhóm](./group-theory.md), [lý thuyết vành](./ring-theory.md)

<span id="giới-thiệu"></span>

## Giới thiệu

**Lý thuyết trường** (field theory) là ngành nghiên cứu các trường.

Bài này chủ yếu trình bày lý thuyết mở rộng trường. Trường là một cấu trúc đại số đóng dưới các phép cộng, trừ, nhân và chia. Trong lập trình thi đấu, thường tính modulo một số nguyên tố $p$, điều này tương đương với tính toán trên trường hữu hạn $\mathbf F_p$. Tương tự như với trường số thực $\mathbf R$, có những bài toán thuận tiện hơn nếu tính trong một trường lớn hơn, chẳng hạn trường số phức $\mathbf C$; ví dụ quen thuộc là dùng [biến đổi Fourier nhanh](../poly/fft.md) để tăng tốc phép nhân đa thức hệ số thực. Với trường hữu hạn, cũng có thể làm những thao tác tương tự. Vì phần lớn độc giả ít quen với mở rộng của trường hữu hạn, việc hiểu lý thuyết mở rộng trên trường tổng quát là hữu ích. Cuối bài có một số ứng dụng thuật toán cần mở rộng trường hữu hạn, đồng thời thảo luận ngắn gọn về mở rộng trên vành số nguyên có thể gặp trong một số ứng dụng.

Liên quan chặt chẽ với lý thuyết trường là lý thuyết Galois. Lý thuyết này liên hệ mở rộng trường với nhóm tự đẳng cấu của nó, nhờ đó có thể dùng công cụ của lý thuyết nhóm để hiểu tính chất của mở rộng trường. Tuy đây thường là nội dung trung tâm trong các môn đại số liên quan, nó khá xa lập trình thi đấu, nên bài này không trình bày sâu. Độc giả quan tâm nên đọc các sách chuyên ngành.

???+ info "Ký hiệu"
    Khi không gây nhầm lẫn, bài này có thể lược bỏ ký hiệu phép nhân của vành và trường, viết vành $(R,+,\cdot)$ là vành $R$, viết trường $(F,+,\cdot)$ là trường $F$. Phần tử đơn vị của phép cộng trong vành và trường gọi là phần tử không, phần tử đơn vị của phép nhân gọi là phần tử một. Ngoài ra, trong bài này $p$ luôn là số nguyên tố, còn $q$ luôn là lũy thừa của một số nguyên tố, có thể viết thành $p^n$, trong đó $n$ là số nguyên dương.

<span id="mở-rộng-trường"></span>

## Mở rộng trường

Tương tự như với nhóm và vành, có thể xây dựng khái niệm trường con và đồng cấu trường.

???+ abstract "Trường con"
    Với trường $F$, nếu một vành con $E$ của nó cũng là trường, thì $E$ được gọi là **trường con** (subfield) của trường $F$.

Trong phần này, bất kể định nghĩa vành và vành con xử lý phần tử một như thế nào, trường con $E$ nhất định chứa phần tử một của trường $F$[^subfield-one].

???+ abstract "Đồng cấu trường"
    Một đồng cấu vành $\varphi:F\rightarrow E$ từ trường $F$ đến trường $E$ cũng được gọi là **đồng cấu trường** (field homomorphism) từ trường $F$ đến trường $E$.

??? info "Cách xử lý phần tử một trong đồng cấu trường"
    Nếu theo một định nghĩa khác với định nghĩa trong bài này, đồng cấu vành được yêu cầu ánh xạ phần tử một sang phần tử một, thì đồng cấu trường tự nhiên cũng có yêu cầu đó. Nếu không, phần tử một cũng có thể bị ánh xạ sang phần tử không.

Vì trường chỉ có các iđêan tầm thường, một đồng cấu trường hoặc ánh xạ toàn bộ trường về phần tử không, hoặc nhất định là một phép nhúng. Điều này cho thấy việc thảo luận đồng cấu trường có thể chuyển thành thảo luận về trường con.

Trong bối cảnh trường, trường nhỏ hơn thường quen thuộc hơn, nên thường lấy trường con làm điểm xuất phát để khảo sát trường lớn hơn. Đây chính là khái niệm mở rộng trường.

???+ abstract "Mở rộng trường"
    Với trường $F$, nếu $F$ là trường con của $E$, thì trường $E$ được gọi là **mở rộng** (extension) của trường $F$, ký hiệu là $E/F$.

???+ info "Ký hiệu mở rộng trường"
    Dù ký hiệu có hình thức giống nhau, khái niệm mở rộng trường không liên quan đến vành thương; không nên nhầm lẫn hai khái niệm này.

???+ example "Ví dụ"
    Trường số phức $\mathbf C$ là mở rộng của trường số thực $\mathbf R$, còn trường số thực $\mathbf R$ lại là mở rộng của trường số hữu tỉ $\mathbf Q$.

<span id="bậc-của-mở-rộng-trường"></span>

### Bậc của mở rộng trường

Với mở rộng trường $E/F$, trường $E$ luôn là một [không gian tuyến tính](../linear-algebra/vector-space.md) trên trường $F$. Số chiều của không gian tuyến tính này chính là bậc của mở rộng.

???+ abstract "Bậc của mở rộng trường"
    **Bậc** (degree) của mở rộng trường $E/F$ là số chiều của $E$ khi xem như không gian tuyến tính trên trường $F$, tức $\dim_F(E)$, ký hiệu là $[E:F]$. Nếu bậc của mở rộng trường là hữu hạn, đó được gọi là **mở rộng hữu hạn** (finite extension); nếu không, gọi là **mở rộng vô hạn** (infinite extension).

???+ example "Ví dụ"
    Bậc của mở rộng trường $\mathbf C/\mathbf R$ là $[\mathbf C:\mathbf R]=2$, nên đây là mở rộng hữu hạn. Mở rộng trường $\mathbf R/\mathbf Q$ là mở rộng vô hạn.

Bậc của mở rộng trường thỏa mãn nguyên lý nhân.

???+ note "Định lý"
    Giả sử $F\subseteq K\subseteq E$ đều là các trường, khi đó bậc mở rộng giữa chúng thỏa mãn $[E:F]=[E:K][K:F]$.

??? note "Chứng minh"
    Với trường hợp bậc mở rộng vô hạn, kết luận đúng trực tiếp từ định nghĩa. Ngược lại, nếu $\{\alpha_i\}$ là một cơ sở của $E$ như không gian tuyến tính trên $K$, và $\{\beta_j\}$ là một cơ sở của $K$ như không gian tuyến tính trên $F$, thì có thể kiểm tra rằng $\{\alpha_i\beta_j\}$ là một cơ sở của $E$ như không gian tuyến tính trên $F$.

Các trường hợp được thảo luận trong bài này chủ yếu là các mở rộng hữu hạn.

<span id="đặc-trưng-của-trường"></span>

### Đặc trưng của trường

Khi nghiên cứu mở rộng trường, có một điểm xuất phát tự nhiên: trường con nhỏ nhất chứa phần tử một của trường $F$. Trường này còn được gọi là **trường con nguyên tố** (prime subfield) của $F$.

Cấu trúc của trường con nguyên tố được xác định duy nhất bởi tính chất của phần tử một trong trường. Đặc trưng của trường tóm tắt tính chất đó.

???+ abstract "Đặc trưng của trường"
    **Đặc trưng** (characteristic) của trường $F$ là số nguyên dương nhỏ nhất $n$ sao cho $n\cdot 1=0$; nếu không tồn tại $n$ như vậy, trường $F$ được nói là có đặc trưng $0$. Trong đó, $n\cdot 1$ là tổng của $n$ phần tử một $1$. Nếu đặc trưng của trường $F$ khác $0$, $F$ được nói là có **đặc trưng hữu hạn** (finite characteristic).

Đặc trưng của trường có thể được hiểu qua đồng cấu vành. Vành số nguyên $\mathbf Z$ chính là cấu trúc đóng thu được từ $0$ và $1$ bằng cách lặp lại cộng, trừ, nhân. Nó có thể được xem như một "nguyên mẫu"; mọi vành chứa phần tử một đều nên "kế thừa" một phần cấu trúc của vành số nguyên[^initial-object-ring]. Vì vậy, với trường $F$, xét đồng cấu vành $\varphi:\mathbf Z\rightarrow F$ và yêu cầu $\varphi(1)=1$. Đồng cấu như vậy được xác định duy nhất: nó ánh xạ $n\in\mathbf N_+$ sang $n\cdot 1$, tức tổng của $n$ phần tử một. Ảnh $\varphi(\mathbf Z)$ được nhúng vào trường $F$, nhất định chứa phần tử một, giao hoán và không có ước của không, nên là miền nguyên. Do đó hạt nhân $\ker\varphi$ nhất định là iđêan nguyên tố. Các iđêan nguyên tố của vành số nguyên $\mathbf Z$ chỉ có dạng $(n)$, trong đó $n=0$ hoặc $n$ là số nguyên tố. Số $n$ thu được theo cách này chính là đặc trưng của trường.

Đặc trưng của trường xác định cấu trúc của trường con nguyên tố:

1.  Khi đặc trưng bằng $0$, đồng cấu $\varphi$ là đơn ánh, vành số nguyên $\mathbf Z$ được nhúng vào trường $F$. Trường số hữu tỉ $\mathbf Q$, là trường nhỏ nhất chứa vành số nguyên, tất yếu cũng có thể được nhúng vào trường $F$; nó chính là trường con nguyên tố của $F$.
2.  Khi đặc trưng là số nguyên tố $p$, ảnh của đồng cấu $\varphi$ là $\mathbf Z/p\mathbf Z$ được nhúng vào trường $F$. Lúc này $\mathbf Z/p\mathbf Z$ đã là trường, ký hiệu $\mathbf F_p$, và nó chính là trường con nguyên tố của $F$.

Các thảo luận này thực chất cho thấy kết luận sau:

???+ note "Định lý"
    Đặc trưng của trường $F$ chỉ có thể là $0$ hoặc một số nguyên tố $p$. Trường có đặc trưng $0$ có trường con nguyên tố là $\mathbf Q$; trường có đặc trưng là số nguyên tố $p$ có trường con nguyên tố là $\mathbf F_p$.

Các trường $\mathbf Q$ và $\mathbf F_p$ trong định lý còn được gọi là **trường nguyên tố** (prime field), tức trường mà trường con duy nhất là chính nó. Trường hữu hạn nhất định có đặc trưng hữu hạn, vì một trường đặc trưng $0$ ít nhất chứa trường con $\mathbf Q$.

Trường có đặc trưng hữu hạn và trường có đặc trưng $0$ thường có tính chất khác nhau. Chẳng hạn, trường có đặc trưng hữu hạn có tính chất sau:

???+ note "Định lý"
    Giả sử $F$ có đặc trưng $p$, khi đó:
    
    1.  Trong nhóm cộng của trường $F$, mọi phần tử khác không đều có bậc $p$, tức với mọi $x\in F$ đều có $px=0$.
    2.  "Giấc mơ của sinh viên năm nhất" (freshman's dream): với mọi $x,y\in F$ đều có $(x+y)^p=x^p+y^p$. Hơn nữa, ánh xạ $x\mapsto x^p$ là một tự đồng cấu đơn ánh trên $F$, gọi là **tự đồng cấu Frobenius** (tiếng Anh: Frobenius endomorphism).

??? note "Chứng minh"
    Với tính chất thứ nhất, chỉ cần dùng $px=(p1)x=0x=0$. Với tính chất thứ hai, trong khai triển nhị thức của $(x+y)^p$, mọi hệ số của các hạng tử khác $x^p$ và $y^p$ đều là bội của $p$, nên theo tính chất thứ nhất có $(x+y)^p=x^p+y^p$. Để kiểm tra $x\mapsto x^p$ là tự đồng cấu, chỉ cần kiểm tra thêm $(xy)^p=x^py^p$, điều này đúng vì phép nhân trong trường giao hoán. Cuối cùng, đồng cấu vành giữa các trường ánh xạ phần tử một sang phần tử một thì nhất định là đơn ánh.

Với trường hữu hạn, tự đồng cấu Frobenius nhất định cũng toàn ánh, do đó là tự đẳng cấu của trường.

<span id="mở-rộng-đơn"></span>

### Mở rộng đơn

Tương tự việc mở rộng trường số thực thành trường số phức, nhiều mở rộng có thể được thực hiện bằng cách thêm phần tử mới vào trường và quy định các phép toán với nó. Trong trường hợp tổng quát, để tránh rắc rối do tự định nghĩa phép toán, xét việc thêm các phần tử của $E\setminus F$ vào $F$ bên trong một mở rộng trường $E/F$. Khi đó quy tắc phép toán giữa các phần tử mới này và các phần tử của $F$ đã được xác định sẵn trong trường lớn hơn $E$.

???+ abstract "Mở rộng trường sinh bởi một tập con"
    Giả sử $E/F$ là mở rộng trường và $S\subseteq E$. **Mở rộng của $F$ sinh bởi $S$** (extension generated by $S$ over $F$) là trường con nhỏ nhất của $E$ đồng thời chứa $F$ và $S$, ký hiệu là $F(S)$.

Trường hợp đơn giản nhất là khi tập $S$ có rất ít phần tử.

???+ abstract "Mở rộng hữu hạn sinh"
    Giả sử $E/F$ là mở rộng trường. Nếu tồn tại tập hữu hạn $S=\{\alpha_1,\cdots,\alpha_n\}\subseteq E$ sao cho $E=F(S)$, thì $E$ được gọi là **mở rộng hữu hạn sinh** (finitely generated extension) của trường $F$, cũng ký hiệu là $F(\alpha_1,\cdots,\alpha_n)$.

???+ abstract "Mở rộng đơn"
    Giả sử $E/F$ là mở rộng trường. Nếu tồn tại $\alpha\in E$ sao cho $E=F(\alpha)$, thì trường $E$ được gọi là **mở rộng đơn** (simple extension) của trường $F$. Phần tử $\alpha$ được gọi là **phần tử nguyên thủy** (primitive element) của mở rộng đơn này.

???+ example "Ví dụ"
    Các ví dụ sau đều thu được bằng cách thêm phần tử của $\mathbf C$ vào $\mathbf Q$.
    
    1.  Với số nguyên không chứa nhân tử chính phương $D\neq 0,1$, trường bậc hai $\mathbf Q(\sqrt D)$ là mở rộng đơn thu được bằng cách thêm $\sqrt D\in\mathbf C\setminus\mathbf Q$ vào trường $\mathbf Q$. Bậc mở rộng của nó là $2$, vì $\{1,\sqrt D\}$ tạo thành một cơ sở.
    2.  Trường $\mathbf Q(\sqrt 2,\sqrt 3)$ là mở rộng thu được bằng cách thêm $\sqrt 2$ và $\sqrt 3$ vào trường $\mathbf Q$. Khi đó $\mathbf Q(\sqrt 2,\sqrt 3)=\mathbf Q(\sqrt 2)(\sqrt 3)=\mathbf Q(\sqrt 3)(\sqrt 2)$, tức mở rộng cuối cùng không phụ thuộc vào thứ tự và cách thêm phần tử. Đây cũng là mở rộng đơn, vì $\mathbf Q(\sqrt 2,\sqrt 3)=\mathbf Q(\sqrt 2+\sqrt 3)$. Bậc mở rộng của nó là $4$, vì $\{1,\sqrt 2,\sqrt 3,\sqrt 6\}$ tạo thành một cơ sở.
    3.  Trường $\mathbf Q(\pi)$ cũng là mở rộng đơn, trong đó $\pi$ là số pi. Đây là mở rộng vô hạn, vì $\mathbf Q[\pi]\subseteq \mathbf Q(\pi)$ đã có một cơ sở $\{1,\pi,\pi^2,\cdots\}$.
    4.  Trường $\mathbf Q(\pi,\mathrm e)$ là mở rộng hữu hạn sinh, nhưng không phải mở rộng đơn. Trong đó $\pi$ là số pi, còn $\mathrm e$ là cơ số của logarit tự nhiên.

Các ví dụ này cho thấy tính chất của mở rộng đơn có thể rất khác nhau. Điều này phụ thuộc vào tính chất của phần tử được thêm vào.

<span id="mở-rộng-đại-số"></span>

### Mở rộng đại số

Để phân tích mọi khả năng khi thêm phần tử vào một trường, có thể bắt chước thảo luận ở trên về đặc trưng của trường và xét đồng cấu vành từ vành đa thức $F[x]$ đến mở rộng $E/F$. Trong lập luận này, $F[x]$ đóng vai trò tương tự vành số nguyên $\mathbf Z$ ở trên: nó chính là "nguyên mẫu" của cấu trúc thu được sau khi thêm biến không xác định $x$ vào trường $F$ và đóng dưới các phép cộng, trừ, nhân[^polynomial-universal].

Giả sử đồng cấu vành $\varphi:F[x]\rightarrow E$ thỏa mãn $\varphi$ khi hạn chế trên $F$ là ánh xạ đồng nhất, và $\varphi(x)=\alpha$, tức ánh xạ biến không xác định đến một phần tử nào đó trong mở rộng $E$. Khi đó, vì ảnh $\varphi(F[x])=F[\alpha]$ nhất định là miền nguyên, hạt nhân $\ker\varphi$ nhất định là iđêan nguyên tố của vành đa thức $F[x]$. Vành đa thức trên trường là miền iđêan chính, nên hạt nhân tất yếu có dạng $(f(x))$, trong đó $f(x)=0$ hoặc $f(x)$ là phần tử bất khả quy trong $F[x]$. Phân tích như sau:

1.  Khi hạt nhân $\ker\varphi=\{0\}$, vành đa thức $F[x]$ được nhúng vào $E$, và ảnh $F[\alpha]$ của nó là miền nguyên. Vì vậy, trường nhỏ nhất trong $E$ đồng thời chứa $F$ và $\alpha$ chính là trường phân thức của $F[\alpha]$, tức $F(\alpha)$. Ký hiệu này vừa có thể hiểu là kết quả thay biến không xác định trong trường hàm hữu tỉ $F(x)$ bằng $\alpha$, vừa có thể hiểu là mở rộng đơn trên trường $F$ sinh bởi $\alpha$; trong ngữ cảnh này hai cách hiểu cho cùng một kết quả.

2.  Khi hạt nhân $\ker\varphi=(f(x))$ và $f(x)$ là phần tử bất khả quy, có $\varphi(f(x))=f(\alpha)=0$, tức $\alpha\in E$ là nghiệm của đa thức $f(x)$ trên $F$. Vì $F$ là trường, có thể giả sử $f(x)$ là đa thức monic. Lúc này ảnh của đồng cấu $\varphi$ là trường $F(\alpha)$, do đó

    $$
    F[x]/(f(x))\cong F(\alpha).
    $$

    Lại có thể chia thành hai trường hợp:

    1.  Nếu $f(x)$ là đa thức bậc nhất, tức $f(x)=x-\alpha$, thì $\alpha\in F$, nên mở rộng $F(\alpha)=F$ là tầm thường.
    2.  Trong các trường hợp còn lại, $f(x)$ là đa thức bất khả quy bậc lớn hơn một, và $\alpha\in E\setminus F$. Lúc này ảnh $F[\alpha]$ đã là trường chứa $F$ và $\alpha$, nên nó chính là $F(\alpha)$, tức mở rộng trên $F$ sinh bởi $\alpha$, và $F(\alpha)\supset F$ không tầm thường.

Các thảo luận này gợi ra các định nghĩa sau:

???+ abstract "Phần tử đại số và phần tử siêu việt"
    Với mở rộng $E/F$, nếu phần tử $\alpha\in E$ là nghiệm của một đa thức khác không $f(x)$ trên $F$, thì $\alpha$ được gọi là **phần tử đại số** (algebraic element) trên $F$; ngược lại, $\alpha$ được gọi là **phần tử siêu việt** (transcendental element) trên $F$.

???+ abstract "Đa thức tối tiểu"
    Với phần tử đại số $\alpha$ trên trường $F$, đa thức monic có bậc nhỏ nhất nhận $\alpha$ làm nghiệm được gọi là **đa thức tối tiểu** (minimal polynomial) của $\alpha$.

Đa thức tối tiểu trong ngữ cảnh này chính là đa thức bất khả quy $f(x)$ trong phân tích ở trên. Cũng có thể chứng minh trực tiếp rằng đa thức tối tiểu luôn bất khả quy. Tính tối tiểu của đa thức tối tiểu $f(x)$ có nghĩa là: hễ một đa thức trên trường $F$ nhận $\alpha$ làm nghiệm, nó nhất định chia hết cho nhân tử $f(x)$.

???+ example "Ví dụ"
    1.  $\sqrt 2$ là phần tử đại số trên $\mathbf Q$, đa thức tối tiểu là $x^2-2$.
    2.  $\sqrt 2$ là phần tử đại số trên $\mathbf R$, đa thức tối tiểu là $x-\sqrt 2$.
    3.  $\pi$ là phần tử siêu việt trên $\mathbf Q$.
    4.  Thông thường, các phần tử đại số trên $\mathbf Q$ được gọi là **số đại số** (algebraic number), còn phần tử siêu việt được gọi là **số siêu việt** (transcendental number). Đặc biệt, nếu đa thức tối tiểu của một số đại số là đa thức monic hệ số nguyên, số đó được gọi là **số nguyên đại số** (algebraic integer). Tập tất cả các số nguyên đại số trong một mở rộng đại số tạo thành một vành. Chẳng hạn, các số nguyên đại số trong trường bậc hai $\mathbf Q(\sqrt{D})$ tạo thành vành số nguyên bậc hai $\mathbf Z[\omega]$. Ý nghĩa ký hiệu này xem trang [vành số nguyên bậc hai](./ring-theory.md#ví-dụ-vành-số-nguyên-bậc-hai).

???+ abstract "Mở rộng đại số và mở rộng siêu việt"
    Với mở rộng $E/F$, nếu mọi phần tử của trường $E$ đều là phần tử đại số trên $F$, thì trường $E$ được gọi là **mở rộng đại số** (algebraic extension) của $F$; ngược lại, $E$ được gọi là **mở rộng siêu việt** (transcendental extension) của $F$.

Kết quả của mở rộng đơn có thể chia thành hai loại tùy theo tính chất của phần tử được thêm vào. Khi phần tử được thêm là phần tử siêu việt, mở rộng đơn luôn đẳng cấu với trường hàm hữu tỉ; khi đó không còn khả năng rút gọn thêm. Nhưng khi phần tử được thêm là phần tử đại số, mở rộng đơn thực chất là $F[\alpha]$, tức kết quả thay trực tiếp biến không xác định $x$ trong vành đa thức $F[x]$ bằng $\alpha$. Nhìn từ góc độ sơ cấp, so với trường hợp phần tử siêu việt, lúc này các phần tử trong trường mở rộng có thể viết không cần mẫu số; điều này có nghĩa quá trình tương tự "hữu tỉ hóa mẫu" trong số học sơ cấp luôn thực hiện được trong mở rộng đơn đại số. Vì các mở rộng trường xuất hiện trong lập trình thi đấu chủ yếu là mở rộng đơn đại số, mục tiếp theo sẽ thảo luận chi tiết hơn cách tính toán trên chúng.

Tầm quan trọng của mở rộng đơn đại số cũng thể hiện qua định lý sau:

???+ note "Định lý"
    Một mở rộng trường là mở rộng hữu hạn khi và chỉ khi nó là mở rộng đại số hữu hạn sinh.

??? note "Chứng minh"
    Giả sử $F$ là trường, $E=F(\alpha_1,\cdots,\alpha_n)$ là mở rộng đại số hữu hạn sinh, tức mọi $\alpha_i$ đều là phần tử đại số trên $F$. Đặt $E_i=F(\alpha_1,\cdots,\alpha_i)$, khi đó $E_0=F$ và $E_n=E$. Với mỗi $i$, $\alpha_i$ nhất định là phần tử đại số trên $E_{i-1}$, vì đa thức tối tiểu của $\alpha_i$ trên trường $F$ cũng là đa thức trên $E_{i-1}$; hơn nữa bậc đa thức tối tiểu của $\alpha_i$ trên $E_{i-1}$ không vượt quá bậc đa thức tối tiểu của $\alpha_i$ trên trường $F$. Do đó $[E_i:E_{i-1}]$ nhất định hữu hạn, và theo nguyên lý nhân của bậc mở rộng trường, $[E:F]=\prod_{i=1}^n[E_i:E_{i-1}]$ cũng hữu hạn. Ngược lại, bắt đầu từ $E_0=F$, với $E_i$ đã xây dựng, mỗi lần chọn một phần tử $\alpha_{i+1}$ trong $E\setminus E_i$ và thêm vào $E_i$, thu được trường mở rộng $E_{i+1}=E_i(\alpha_{i+1})$, cho đến khi $E_n=E$. Vì bậc mở rộng liên tục giảm, quá trình này nhất định dừng sau hữu hạn bước. Vì vậy mở rộng hữu hạn nhất định là mở rộng đại số hữu hạn sinh.

Điều này có nghĩa để hiểu tính chất của mở rộng hữu hạn, chỉ cần hiểu mở rộng đơn đại số. Bởi vì mọi mở rộng hữu hạn luôn có thể thu được từ hữu hạn nhiều mở rộng đơn đại số.

<span id="cấu-trúc-và-tính-toán-của-mở-rộng-đơn-đại-số"></span>

### Cấu trúc và tính toán của mở rộng đơn đại số

Trong mục này, giả sử $F$ là một trường, $E$ là trường mở rộng của nó, và $\alpha\in E\setminus F$ là phần tử đại số trên trường $F$. Giả sử đa thức tối tiểu của $\alpha$ là $f(x)$, và $f(x)$ là đa thức monic bậc $n$, tức

$$
f(x)=x^n+a_{n-1}x^{n-1}+\cdots+a_1x+a_0,
$$

trong đó $a_0,a_1,\cdots,a_{n-1}\in F$ và $f(x)$ bất khả quy trên $F$.

Đẳng cấu $F(\alpha)\cong F[x]/(f(x))$ cho thấy phép toán trong trường mở rộng $F(\alpha)$ chính là phép tính đa thức modulo $f(x)$. Theo phép chia đa thức có dư, chỉ cần xét các lớp đồng dư của mọi đa thức có bậc nhỏ hơn $n=\deg f(x)$. Với các đa thức này, một cơ sở tự nhiên là $\{1,\alpha,\cdots,\alpha^{n-1}\}$. Vì vậy có kết luận sau:

???+ note "Định lý"
    Dưới giả thiết của mục này, trường mở rộng $F(\alpha)$ có thể viết thành
    
    $$
    F(\alpha)=\{\lambda(\alpha)=\lambda_0+\lambda_1\alpha+\cdots+\lambda_{n-1}\alpha^{n-1}:\lambda_0,\lambda_1,\cdots,\lambda_{n-1}\in F\}.
    $$
    
    Trong đó $\lambda(x)$ chạy qua toàn bộ các đa thức bậc nhỏ hơn $n$. Vì vậy bậc mở rộng $[F(\alpha):F]=n$, tức bằng bậc của đa thức tối tiểu của $\alpha$. Trong trường mở rộng, phép cộng của hai phần tử $\lambda(\alpha)$ và $\mu(\alpha)$ chính là phép cộng đa thức, tức cộng các hệ số tương ứng. Phép nhân của $\lambda(\alpha)$ và $\mu(\alpha)$ có thể viết thành $\rho(\alpha)$, trong đó $\rho(x)$ là phần dư khi chia tích $\lambda(x)\mu(x)$ cho $f(x)$.

Vì đây là trường, cũng có thể tính phép chia trong $F(\alpha)$. Theo quá trình nhân trong định lý, điều này tương đương với giải [phương trình đồng dư tuyến tính](../number-theory/linear-equation.md) trên vành đa thức. Tương tự cách làm với số nguyên, để tính thương $\lambda(\alpha)/\mu(\alpha)$, có thể trước hết tìm nghịch đảo nhân của $\mu(\alpha)$, rồi nhân với $\lambda(\alpha)$. Để tính nghịch đảo nhân của $\mu(\alpha)$, chỉ cần giải phương trình đồng dư $\mu(x)\xi(x)\equiv 1\pmod{f(x)}$. Việc này có thể thực hiện bằng thuật toán Euclid mở rộng.

Dưới đây là vài ví dụ cụ thể để làm rõ cách tính.

???+ example "Ví dụ"
    Xét trường mở rộng $\mathbf Q(\alpha)$, trong đó $\alpha$ là một nghiệm của phương trình $x^3-2x-2=0$. Cần tính giá trị
    
    $$
    \frac{1+\alpha}{1+\alpha+\alpha^2}.
    $$
    
    Bước đầu tiên là tính nghịch đảo của $1+\alpha+\alpha^2$, tức cần giải phương trình đồng dư
    
    $$
    (x^2+x+1)\xi(x)+(x^3-2x-2)\nu(x)=1.
    $$
    
    Áp dụng thuật toán Euclid mở rộng. Trước hết thực hiện phép chia Euclid:
    
    $$
    \begin{aligned}
    x^3-2x-2 &= (x-1)(x^2+x+1)+(-2x-1),\\
    x^2+x+1 &= \left(-\frac12x-\frac14\right)(-2x-1)+\frac34,\\
    -2x-1 &= \left(-\frac{8}{3}x-\frac{4}{3}\right)\frac{3}{4}.
    \end{aligned}
    $$
    
    Sau đó tính ngược các hệ số trong phương trình đồng dư:
    
    $$
    \begin{aligned}
    \frac{3}{4}
    &=(x^2+x+1)+\left(\frac12x+\frac14\right)(-2x-1)\\
    &=(x^2+x+1)+\left(\frac12x+\frac14\right)\left((x^3-2x-2)-(x-1)(x^2+x+1)\right)\\
    &=\left(-\frac12x^2+\frac14x+\frac54\right)(x^2+x+1)+\left(\frac12x+\frac14\right)(x^3-2x-2).
    \end{aligned}
    $$
    
    Do đó nghiệm của phương trình là
    
    $$
    \xi(x)=-\frac23x^2+\frac13x+\frac53,\ \nu(x)=\frac23x+\frac13.
    $$
    
    Điều này cho thấy nghịch đảo của $1+\alpha+\alpha^2$ là
    
    $$
    -\frac23\alpha^2+\frac13\alpha+\frac53.
    $$
    
    Bước thứ hai là nhân nghịch đảo này với $1+\alpha$. Có
    
    $$
    \begin{aligned}
    (1+\alpha)\left(-\frac23\alpha^2+\frac13\alpha+\frac53\right)
    &=-\frac23\alpha^3-\frac13\alpha^2+2\alpha+\frac53\\
    &=-\frac23(2\alpha+2)-\frac13\alpha^2+2\alpha+\frac53\\
    &=-\frac13\alpha^2+\frac23\alpha+\frac13.
    \end{aligned}
    $$
    
    Đây là đáp án cuối cùng.

Trong ví dụ, chỉ dùng điều kiện $\alpha$ là một nghiệm của phương trình, nhưng không chỉ rõ nó là nghiệm cụ thể nào. Đa thức $x^3-2x-2=0$ có một nghiệm thực và một cặp nghiệm phức liên hợp trong trường số phức $\mathbf C$. Thêm bất kỳ nghiệm nào trong ba nghiệm đó vào trường số hữu tỉ $\mathbf Q$ đều thu được các trường mở rộng đẳng cấu. Nói cách khác, dưới góc nhìn đại số, ba nghiệm phân biệt này không khác nhau.

Trong trường hợp tổng quát, với một đa thức bất khả quy $f(x)$ trên trường $F$, nếu trong trường mở rộng có các nghiệm khác nhau $\alpha\neq\beta$, thì các nghiệm này biểu hiện cùng tính chất đại số khi lần lượt sinh mở rộng đơn của $F$. Các nghiệm như vậy được gọi là **liên hợp** (conjugate) của nhau. Liên hợp thông thường trên trường số phức là trường hợp đặc biệt của khái niệm này đối với mở rộng trường $\mathbf C/\mathbf R$.

???+ example "Ví dụ"
    Xét trường mở rộng $\mathbf F_2(\alpha)$, trong đó $\alpha$ là một nghiệm của phương trình $x^2+x+1=0$. Với $a+b\alpha$ và $c+d\alpha$, có quy tắc tính
    
    $$
    \begin{aligned}
    (a+b\alpha)+(c+d\alpha)&=(a+c)+(b+d)\alpha,\\
    (a+b\alpha)(c+d\alpha)&=ac+(ad+bc)\alpha+bd\alpha^2\\
    &=(ac+bd)+(ad+bc+bd)\alpha.
    \end{aligned}
    $$
    
    Điều này cung cấp quy tắc tính tương tự trường số phức. Phần lớn độc giả có thể chưa quen với một nghiệm $\alpha$ như vậy, nhưng điều đó không cản trở việc tính toán các phần tử trong trường này. Hơn nữa, $[\mathbf F_2(\alpha):\mathbf F_2]=2$, nên với tư cách không gian tuyến tính, $|\mathbf F_2(\alpha)|=4$, tức trường thu được là một trường hữu hạn có kích thước $4$. Phần sau sẽ thấy mọi trường hữu hạn đều được xây dựng như vậy.

Khi tính toán quy mô nhỏ, phép lấy modulo đa thức monic $f(x)$ thường có thể thực hiện bằng cách thay

$$
x^n=-a_{n-1}x^{n-1}-\cdots-a_1x-a_0
$$

để hạ bậc đa thức mục tiêu. Ngoài ra, với mở rộng bậc thấp, thường có thể trực tiếp tính ra quy tắc phép toán trên hệ số, dùng cách cài đặt tương tự lớp số phức mà không cần mỗi lần đều thực hiện phép lấy modulo.

Như một ví dụ về mở rộng đơn đại số, có thể xem [triển khai tham khảo](#triển-khai-tham-khảo) cho trường hữu hạn ở phần dưới.

Các thuật toán mô tả trong phần này chỉ xử lý được trường hợp bậc mở rộng tương đối thấp; điều này đủ cho tuyệt đại đa số ứng dụng trong lập trình thi đấu. Nếu bậc mở rộng lớn đến mức trở thành nút thắt độ phức tạp, nên dùng các kỹ thuật đa thức thích hợp như [biến đổi Fourier nhanh](../poly/fft.md), [biến đổi số học nhanh](../poly/ntt.md), [lấy dư đa thức nhanh](../poly/elementary-func.md#chia-đa-thức-và-lấy-dư), [Euclid đa thức](../poly/intro.md#phân-tích-nhân-tử-và-euclid), v.v. để tăng tốc phép toán.

<span id="trường-phân-rã"></span>

### Trường phân rã

Phần trên đã thảo luận chi tiết cấu trúc của mở rộng đơn đại số. Tuy nhiên, mở rộng như vậy thường chưa đủ:

???+ example "Ví dụ"
    Xét mở rộng $\mathbf Q(\sqrt[3]{2})/\mathbf Q$. Phần tử đại số $\sqrt[3]{2}$ có đa thức tối tiểu trên trường $\mathbf Q$ là $x^3-2$. Trong trường số phức $\mathbf C$, đa thức $x^3-2$ có ba nghiệm, là $\sqrt[3]{2},\sqrt[3]{2}\omega,\sqrt[3]{2}\omega^2$, trong đó $\omega=\mathrm{e}^{2\pi\mathrm{i}/3}$ là căn nguyên thủy bậc ba của $1$. Tuy $\mathbf Q(\sqrt[3]{2})\cong\mathbf Q(\sqrt[3]{2}\omega)\cong\mathbf Q(\sqrt[3]{2}\omega^2)$, nhưng $\mathbf Q(\sqrt[3]{2})$ không chứa hai nghiệm còn lại, khiến những phép toán như $\sqrt[3]{2}+\sqrt[3]{2}\omega$ không thể thực hiện. Nếu muốn khảo sát đầy đủ ba nghiệm này, cần mở rộng tiếp trường $\mathbf Q(\sqrt[3]{2})$, tức mở rộng đến $\mathbf Q(\sqrt[3]{2},\sqrt[3]{2}\omega,\sqrt[3]{2}\omega^2)$.
    
    Phần trước đã nói rằng để xây dựng mở rộng như vậy, chỉ cần thực hiện mở rộng đơn lần lượt theo từng phần tử. Cần lưu ý rằng đa thức tối tiểu của $\sqrt[3]{2}\omega$ trong trường $\mathbf Q$ và trong trường $\mathbf Q(\sqrt[3]{2})$ không giống nhau: cái trước là $x^3-2\in\mathbf Q[x]$, còn cái sau là $x^2+\sqrt[3]{2}x+\sqrt[3]{4}\in \mathbf Q(\sqrt[3]{2})[x]$, vì
    
    $$
    x^3-2 = (x-\sqrt[3]{2})(x^2+\sqrt[3]{2}x+\sqrt[3]{4}).
    $$
    
    Sau khi mở rộng trường, đa thức tối tiểu ban đầu đã tách ra một nhân tử bậc nhất, nên đa thức tối tiểu của các nghiệm còn lại có bậc thấp hơn đa thức tối tiểu trên trường ban đầu. Quá trình mở rộng trường liên tục chính là quá trình đa thức liên tục "phân rã". Vì vậy, mỗi lần thực hiện mở rộng đơn đều cần xác định lại đa thức tối tiểu.

Thêm toàn bộ các nghiệm của một đa thức vào trường sẽ thu được trường phân rã của đa thức đó.

???+ abstract "Phân rã"
    Giả sử $F$ là trường. Nếu đa thức $f(x)$ có thể phân tích trong $F[x]$ thành tích của các nhân tử bậc nhất, đa thức $f(x)$ được nói là **phân rã** (split) trong trường $F$.

???+ abstract "Trường phân rã"
    Với đa thức $f(x)$ trên trường $F$, nếu mở rộng $E/F$ thỏa mãn $f(x)$ phân rã trong trường $E$ nhưng không phân rã trong bất kỳ trường con thực sự nào của $E$, thì trường $E$ được gọi là **trường phân rã** (splitting field) của đa thức $f(x)$.

Có thể chứng minh, tương tự mở rộng đơn, trường phân rã của một đa thức cho trước là duy nhất đến đẳng cấu, không phụ thuộc vào cách xây dựng cụ thể. Trường phân rã luôn là mở rộng hữu hạn.

???+ abstract "Mở rộng chuẩn tắc"
    Với mở rộng đại số $E/F$, nếu với mọi $\alpha\in E$, đa thức tối tiểu của $\alpha$ đều phân rã trong $E$, thì trường $E$ được gọi là **mở rộng chuẩn tắc** (normal extension) của trường $F$.

Mở rộng chuẩn tắc đóng vai trò cơ sở trong lý thuyết Galois.

<span id="trường-đóng-đại-số"></span>

### Trường đóng đại số

Về nguyên tắc, phần lớn các khái niệm mở rộng nói trên cần được xét bên trong một trường mở rộng lớn hơn. Với mở rộng đơn, có thể dùng vành đa thức để xây dựng mở rộng trường mà không phụ thuộc vào một trường lớn có sẵn; nhưng trong trường hợp tổng quát thì không có công cụ trực tiếp như vậy. Với trường số hữu tỉ $\mathbf Q$ và trường số thực $\mathbf R$, luôn có thể giả định mở rộng đại số nằm trong trường số phức $\mathbf C$. Với trường hữu hạn thì không có một trường quen thuộc tương tự. Tuy vậy, với mọi trường đều tồn tại bao đóng đại số, nhờ đó mọi mở rộng đại số trên trường đều có thể giả định diễn ra trong bao đóng đại số. Điều này giải quyết triệt để vấn đề trên.

???+ abstract "Bao đóng đại số"
    Với trường $F$, nếu trường $\overline F$ là mở rộng đại số của $F$, và mọi $f(x)\in F[x]$ đều phân rã trong $\overline F$, thì trường $\overline F$ được gọi là **bao đóng đại số** (algebraic closure) của trường $F$.

Bao đóng đại số là mở rộng chuẩn tắc của trường. Về cơ bản, cách xây dựng của nó là thêm vào trường mọi nghiệm có thể có của mọi đa thức. Hơn nữa, giống trường phân rã, bao đóng đại số của một trường cũng là duy nhất đến đẳng cấu.

???+ note "Định lý"
    Mọi trường $F$ đều có bao đóng đại số.

??? note "Chứng minh"
    Khó khăn của chứng minh đến từ lý thuyết tập hợp. Dưới đây trình bày một chứng minh của Artin.
    
    Phần đầu của chứng minh bắt đầu từ $F$, xây dựng mở rộng $K_1/F$ sao cho mọi đa thức trên $F$ đều có ít nhất một nghiệm trong $K_1$. Với trường $F$, xét vành đa thức nhiều biến[^multi-poly-ring] $R=F[\cdots,x_f,\cdots]$, trong đó chỉ số của biến không xác định $x_f$ chạy qua mọi đa thức monic trên $F$. Ký hiệu $I$ là iđêan sinh bởi mọi $f(x_f)$. Trước hết, $I\neq R$, nên tồn tại iđêan cực đại $M\supseteq I$. Nếu không, nếu $1\in I$, thì phải tồn tại hữu hạn nhiều đa thức monic $f_i$ trên trường $F$ và các phần tử tương ứng $g_i$ trong vành $R$ sao cho $g_1f_1(x_{f_1})+\cdots+g_kf_k(x_{f_k})=1$. Gọi $F(\alpha_1,\cdots,\alpha_k)$ là mở rộng đại số thu được sau khi thêm vào $F$ các nghiệm $\alpha_i$ của $f_i(x)$. Trong $F(\alpha_1,\cdots,\alpha_k)$, thay mọi $x_{f_i}$ trong đẳng thức trên bằng $\alpha_i$, còn các biến không xác định khác $x_f$ xuất hiện trong các $g_i$ bằng $0$, thu được đẳng thức $0=1$, mâu thuẫn. Do đó $I\neq R$, việc xây dựng iđêan cực đại $M$ là hợp lệ. Khi đó vành thương $R/M$ là trường, ký hiệu là $K_1$, và mọi đa thức monic $f(x)$ trên $F$ đều có nghiệm $\overline{x_f}$ trong $K_1$.
    
    Phần thứ hai của chứng minh xây dựng quy nạp một trường đóng đại số $K$ chứa $F$ (định nghĩa xem bên dưới). Lặp lại cách xây dựng trên: dựa trên trường $K_i$ có thể xây dựng trường $K_{i+1}$ sao cho mọi đa thức trên $K_i$ đều có ít nhất một nghiệm trong $K_{i+1}$. Hơn nữa, $K_i$ nhúng tự nhiên vào $K_{i+1}$, nên có thể định nghĩa hợp $K=\bigcup_{i=1}^\infty K_i$. Dễ kiểm tra đây cũng là trường, và mọi đa thức trên $K$ có toàn bộ hệ số nằm trong một $K_i$ nào đó, nên một nghiệm của nó nằm trong $K_{i+1}\subseteq K$. Điều này cho thấy mọi đa thức trên $K$ đều có ít nhất một nghiệm trong $K$, do đó $K$ là trường đóng đại số.
    
    Cuối cùng, ký hiệu $\overline F$ là tập gồm mọi phần tử của $K$ đại số trên $F$. Nó là trường: với mọi $\alpha,\beta\in\overline F$, có $\alpha\pm\beta,\alpha\beta,\alpha/\beta\in F(\alpha,\beta)\subseteq\overline F$. Nó cũng là mở rộng đại số của $F$, vì mọi phần tử của nó đều là phần tử đại số trên $F$. Với đa thức $f(x)$ trên $F$, mọi nghiệm của nó đều là phần tử đại số trên $F$, nên cũng nằm trong $\overline F$, do đó đa thức nhất định phân rã thành tích của các nhân tử bậc nhất. Điều này chứng tỏ $\overline F$ là bao đóng đại số của $F$.

???+ example "Ví dụ"
    1.  Bao đóng đại số của trường số thực $\mathbf R$ là trường số phức $\mathbf C$.
    2.  Bao đóng đại số của trường số hữu tỉ $\mathbf Q$ là tập toàn bộ số đại số, tức các phần tử đại số trong mở rộng trường $\mathbf C/\mathbf Q$, ký hiệu là $\overline{\mathbf Q}$.

Mọi mở rộng đại số của bao đóng đại số đều tầm thường. Những trường như vậy được gọi là trường đóng đại số.

???+ abstract "Trường đóng đại số"
    Nếu mọi đa thức không hằng $f(x)$ trên trường $F$ đều có ít nhất một nghiệm $\alpha\in F$, thì trường $F$ được gọi là **trường đóng đại số** (algebraically closed field).

Khái niệm này có các định nghĩa tương đương sau:

???+ note "Định lý"
    Với trường $F$, các tính chất sau là tương đương:
    
    1.  Trường $F$ là trường đóng đại số.
    2.  Mọi đa thức $f(x)$ trên trường $F$ đều phân rã.
    3.  Các đa thức bất khả quy trên trường $F$ chỉ có đa thức bậc nhất.
    4.  Trường $F$ không có mở rộng đại số không tầm thường.
    5.  Trường $F$ không có mở rộng hữu hạn không tầm thường.
    6.  Trường $F$ là bao đóng đại số của một trường nào đó.

??? note "Chứng minh"
    Tính tương đương của năm tính chất đầu suy ra từ định nghĩa. Với tính chất thứ sáu, trường đóng đại số là bao đóng đại số của chính nó, vì nó không có mở rộng đại số không tầm thường. Ngược lại, cần chứng minh bao đóng đại số của trường $F$ nhất định là trường đóng đại số. Giả sử $\overline F$ là bao đóng đại số của trường $F$, và $f(x)$ là đa thức trên $\overline F$. Gọi $\alpha$ là một nghiệm của $f(x)$ trong trường phân rã của $f(x)$, và gọi $S\subseteq\overline F$ là tập các hệ số khác không của $f(x)$. Khi đó, vì $F(S)(\alpha)=F(S\cup\{\alpha\})$ là mở rộng hữu hạn, $\alpha$ nhất định cũng là phần tử đại số trên $F$. Theo định nghĩa bao đóng đại số, đa thức tối tiểu của $\alpha$ trên $F$ phân rã trong trường $\overline F$, nên $\alpha\in\overline F$. Điều này cho thấy mọi đa thức trên $\overline F$ đều có ít nhất một nghiệm.

Cuối cùng, [định lý cơ bản của đại số](../poly/fundamental.md)[^fundamental-algebra] cho biết $\mathbf C$ là trường đóng đại số. Các đa thức bất khả quy trên trường số thực $\mathbf R$ có bậc không quá hai, hay tương đương, các mở rộng đại số của nó có bậc không quá hai, là vì trường lớn nhất thu được bằng mở rộng đại số chính là $\mathbf C$.

<span id="mở-rộng-tách-được"></span>

### Mở rộng tách được

Khái niệm trường phân rã bảo đảm rằng với mọi đa thức trên mọi trường, luôn có trường mở rộng chứa tất cả các nghiệm của nó, và trường phân rã chính là trường mở rộng nhỏ nhất như vậy. Tính chất của đa thức liên hệ chặt chẽ với tính chất của trường phân rã của nó. Tuy nhiên, nếu muốn nghiên cứu tính chất đa thức thông qua trường phân rã, vấn đề đầu tiên là trường phân rã của đa thức không ghi nhận bội số của các nghiệm. Vì vậy, nếu có thể, nên xét một "biểu diễn tối giản" nào đó của đa thức. Từ ý tưởng này, gọi các đa thức không có nghiệm bội ngay cả trong bao đóng đại số của trường là đa thức tách được.

???+ abstract "Đa thức tách được"
    Với đa thức $f(x)$ trên trường $F$, nếu $f(x)$ không có nghiệm bội trong bao đóng đại số $\overline F$ của $F$, tức khi phân tích thành tích các nhân tử bậc nhất không có nhân tử lặp, thì $f(x)$ được gọi là **tách được** (separable).

Vì luôn phải mở rộng đến bao đóng đại số của trường $F$ để thảo luận, việc xác định đa thức tách được không phụ thuộc vào cách chọn trường mở rộng. Tuy nhiên, do hệ số của đa thức nằm trong $F$, nên có một phương pháp phán đoán ngay trên trường $F$, không cần xây dựng tường minh trường mở rộng của nó.

Độc giả quen với giải tích biết rằng nghiệm bội của hàm đa thức có thể được nhận biết qua đạo hàm: nghiệm bội của hàm đa thức cũng là nghiệm của đạo hàm. Dù đa thức và hàm đa thức không phải là cùng một khái niệm, phương pháp nhận biết nghiệm bội của hàm đa thức có thể được chuyển sang đa thức bằng phép tương tự. Đạo hàm của đa thức có thể được định nghĩa hình thức như sau:

???+ abstract "Đạo hàm hình thức"
    Với đa thức trên trường $F$
    
    $$
    f(x)=a_0+a_1x+a_2x^2+\cdots+a_{n-1}x^{n-1}+a_nx^n=\sum_{i=0}^na_ix^i,
    $$
    
    **đạo hàm hình thức** (derivative), ký hiệu $Df(x)$, được định nghĩa là đa thức
    
    $$
    Df(x)=a_1+2a_2x+\cdots+(n-1)a_{n-1}x^{n-2}+na_nx^{n-1}=\sum_{i=1}^n ia_ix^{i-1}.
    $$

Định nghĩa này áp dụng cho đa thức trên mọi trường, không phụ thuộc vào bất kỳ cấu trúc tô pô nào; toán tử đạo hàm $D$ trong ngữ cảnh này chỉ ánh xạ một đa thức sang một đa thức khác. Hơn nữa, có thể so sánh hệ số để kiểm tra rằng các quy tắc đạo hàm quen thuộc, chẳng hạn $D(f(x)g(x))=(Df(x))g(x)+f(x)(Dg(x))$, vẫn đúng với đạo hàm hình thức.

Tiếp theo, để kiểm tra $f(x)$ và đạo hàm $Df(x)$ có nghiệm chung trong trường phân rã hay không, không cần xây dựng tường minh trường phân rã đó, mà chỉ cần xét ước chung lớn nhất của chúng. Lý do là nghiệm của đa thức luôn xuất hiện trong đa thức tối tiểu của nó, và nghiệm lặp nghĩa là nhân tử đa thức tối tiểu tương ứng cũng lặp. Do đó có quy tắc nhận biết nghiệm bội như sau:

???+ note "Định lý"
    Với đa thức $f(x)$ trên trường $F$, nếu $f(x)$ có nghiệm bội $\alpha$, thì đạo hàm $Df(x)$ cũng có nghiệm $\alpha$. Hơn nữa, điều kiện cần và đủ để $f(x)$ tách được là $f(x)$ và đạo hàm $Df(x)$ nguyên tố cùng nhau, tức $\gcd(f(x),Df(x))=1$.

??? note "Chứng minh"
    Trước hết, vì phép chia có dư vẫn được bảo toàn trong trường mở rộng, kết quả của thuật toán Euclid cũng không phụ thuộc vào cách chọn trường mở rộng, nên chỉ cần thảo luận ước chung trong trường phân rã. Gọi $\alpha$ là nghiệm bội $k>1$ của $f(x)$, khi đó trong trường phân rã có phân tích $f(x)=(x-\alpha)^kg(x)$, nên đạo hàm $Df(x)=k(x-\alpha)^{k-1}g(x)+(x-\alpha)^kDg(x)$ nhất định cũng có nghiệm $\alpha$. Ngược lại, nếu $f(x)$ và $Df(x)$ đều có nghiệm $\alpha$, thì với phân tích $f(x)=(x-\alpha)g(x)$ trong trường phân rã, có $Df(x)=(x-\alpha)Dg(x)+g(x)$, nên $\alpha$ cũng là nghiệm của $g(x)$, do đó $\alpha$ là nghiệm bội của $f(x)$. Điều này chứng minh phần đầu của định lý. Hơn nữa, $f(x)$ có nghiệm bội $\alpha$ tương đương với $x-\alpha$ là nhân tử của $\gcd(f(x),Df(x))$. Vì vậy $f(x)$ không tách được tương đương với $\gcd(f(x),Df(x))$ có bậc ít nhất một.

Đa thức trên trường luôn có thể phân tích thành tích của một số đa thức bất khả quy. Vì các đa thức bất khả quy khác nhau (theo nghĩa liên kết) luôn có các nghiệm khác nhau, nghiệm lặp tự nhiên liên hệ với việc các nhân tử đa thức tương ứng bị lặp. Vậy nếu trong phân tích của một đa thức không có nhân tử bất khả quy lặp, liệu có thể kết luận đa thức tách được hay không? Nói cách khác, có phải mọi đa thức bất khả quy đều tách được không? Đáng tiếc, trong trường hợp tổng quát không thể trả lời khẳng định. Vấn đề xuất hiện ở các trường có đặc trưng hữu hạn.

Với đa thức bất khả quy $f(x)$ trên trường $F$, đa thức $\gcd(f(x),Df(x))$ là nhân tử của $f(x)$, nên chỉ có hai khả năng: $1$ hoặc $f(x)$. Trong trường hợp đầu, $f(x)$ tự nhiên tách được; vấn đề nằm ở trường hợp sau. Nhưng do định nghĩa đạo hàm đã bảo đảm $Df(x)=0$ hoặc $\deg Df(x)<\deg f(x)$, việc $f(x)$ là nhân tử của $Df(x)$ chỉ có thể xảy ra khi $Df(x)=0$. Điều này có thể xảy ra trong trường có đặc trưng hữu hạn.

Với trường $F$ có đặc trưng $p$, nếu $Df(x)=0$, thì mọi hệ số khác không của đa thức chỉ có thể xuất hiện ở các hạng tử có bậc là bội của $p$, tức đa thức $f(x)$ có thể viết thành

$$
f(x)=a_0+a_px^p+a_{2p}x^{2p}+\cdots+a_{(k-1)p}x^{(k-1)p}+a_{kp}x^{kp}.
$$

Nếu thực sự tồn tại đa thức $f(x)$ trên trường $F$ vừa bất khả quy vừa không tách được, nó chỉ có thể có dạng này. Nhưng nếu mọi phần tử của trường $F$ luôn có căn bậc $p$, tức với mỗi hệ số $a_{jp}$ đều tồn tại $b_j\in F$ sao cho $a_{jp}=b_j^p$, thì theo tự đồng cấu Frobenius luôn có

$$
\begin{aligned}
f(x)&=a_0+a_px^p+a_{2p}x^{2p}+\cdots+a_{(k-1)p}x^{(k-1)p}+a_{kp}x^{kp}\\
&=b_0^p+b_1^px^p+b_2^px^{2p}+\cdots+b_{k-1}^px^{(k-1)p}+b_k^px^{kp}\\
&=\left(b_0+b_1x+b_2x^2+\cdots+b_{k-1}x^{k-1}+b_kx^k\right)^p.
\end{aligned}
$$

Do đó trên một trường $F$ như vậy không tồn tại đa thức bất khả quy có dạng trên. Vì vậy trên trường này, mọi đa thức bất khả quy đều tách được. Trường như vậy được gọi là trường hoàn hảo.

???+ abstract "Trường hoàn hảo"
    Nếu mọi đa thức bất khả quy trên trường $F$ đều là đa thức tách được, thì $F$ được gọi là **trường hoàn hảo** (perfect field).

Với trường hoàn hảo, khái niệm đa thức tách được tương đương với khái niệm đa thức không chứa nhân tử bình phương trong phân tích duy nhất.

???+ note "Định lý"
    Giả sử trường $F$ là trường hoàn hảo. Khi đó đa thức trên $F$ tách được khi và chỉ khi nó có thể viết thành tích của các đa thức bất khả quy khác nhau (theo nghĩa liên kết).

Thảo luận trong mục này đã đủ để đưa ra phương pháp loại bỏ nhân tử lặp trong đa thức; đây là bước then chốt trong thuật toán phân tích nhân tử đa thức. Nhưng nội dung đó vượt ra ngoài phạm vi bài này, nên độc giả quan tâm có thể tham khảo tài liệu liên quan ở cuối bài.

Các thảo luận này cũng đưa ra đặc trưng hóa trường hoàn hảo:

???+ note "Định lý"
    Trường $F$ là trường hoàn hảo khi và chỉ khi đặc trưng của $F$ bằng không, hoặc đặc trưng của $F$ là $p$ và mọi phần tử $x\in F$ đều có căn bậc $p$ (tức tự đồng cấu Frobenius cũng là tự đẳng cấu).

Trường số hữu tỉ $\mathbf Q$ và trường hữu hạn $\mathbf F_q$ sẽ thảo luận bên dưới đều là trường hoàn hảo.

Khi trường không hoàn hảo, quả thật tồn tại đa thức bất khả quy không tách được.

??? example "Ví dụ"
    Xét đa thức $x^2-t$ trên trường hàm hữu tỉ $\mathbf F_2(t)$ của $\mathbf F_2$. Vì $\mathbf F_2(t)$ là trường phân thức của miền phân tích duy nhất $\mathbf F_2[t]$, và $t$ là phần tử nguyên tố trong $\mathbf F_2[t]$, áp dụng tiêu chuẩn Eisenstein với phần tử nguyên tố $t$ cho thấy $x^2-t$ bất khả quy trong $\mathbf F_2[t]$, nên cũng bất khả quy trong $\mathbf F_2(t)$. Nhưng đạo hàm của nó bằng $0$, do đó $x^2-t$ không tách được. Trong mở rộng $\mathbf F_2(t)(\sqrt t)$, nó có nghiệm kép $\sqrt t$.

Cuối cùng quay lại thảo luận về mở rộng trường.

???+ abstract "Mở rộng tách được"
    Với mở rộng đại số $E/F$, nếu với mọi $\alpha\in E$, đa thức tối tiểu của $\alpha$ đều là đa thức tách được, thì trường $E$ được gọi là **mở rộng tách được** (separable extension) của trường $F$.

Mọi mở rộng đại số trên trường hoàn hảo đều là mở rộng tách được. Điều này cũng có thể dùng làm định nghĩa tương đương của trường hoàn hảo.

Nếu một mở rộng đại số vừa là mở rộng chuẩn tắc vừa là mở rộng tách được, nó còn được gọi là mở rộng Galois. Trong mở rộng Galois, mọi đa thức bất khả quy đều không có nghiệm bội, và số nghiệm đúng bằng bậc của đa thức, nên các hoán vị của nghiệm có thể phản ánh đầy đủ tính chất của mở rộng trường và đa thức. Những mở rộng như vậy là nền tảng để xây dựng lý thuyết Galois. Độc giả quan tâm có thể tham khảo các tài liệu liên quan ở cuối bài.

<span id="trường-cyclotomic"></span>

## Trường cyclotomic

Như một ví dụ đơn giản về mở rộng trường, mục này thảo luận trường cyclotomic. Một ví dụ đơn giản khác về mở rộng trường là [trường bậc hai](../number-theory/quadratic.md).

<span id="nhóm-căn-đơn-vị"></span>

### Nhóm căn đơn vị

Trong trường số phức $\mathbf C$, các nghiệm của đa thức $x^n=1$ được gọi là **căn đơn vị bậc $n$** ($n$-th root of unity). Ký hiệu $\zeta_n=\mathrm{e}^{2\pi\mathrm{i}/n}$. Khi đó toàn bộ căn đơn vị bậc $n$ là tập $C_n=\{\zeta_n^k:k\in\mathbf Z\}$. Dưới phép nhân, $C_n$ tạo thành nhóm cyclic bậc $n$, có thể ký hiệu là $\langle\zeta_n\rangle$, gọi là nhóm căn đơn vị bậc $n$. Các phần tử sinh của nhóm $C_n$, tức các phần tử có bậc đúng bằng $n$, được gọi là **căn đơn vị nguyên thủy bậc $n$** (primitive $n$-th root of unity). Tập các căn đơn vị nguyên thủy bậc $n$ là $P_n=\{\zeta_n^k:k\in\mathbf Z,k\perp n\}$, có đúng $\varphi(n)$ phần tử; trong đó $\varphi(n)$ là [hàm Euler](../number-theory/euler-totient.md). Phân loại các phần tử của nhóm căn đơn vị $C_n$ theo bậc của chúng, có phân rã sau:

$$
C_n=\bigcup_{d|n}P_d.
$$

Đếm số phần tử hai vế thu được đẳng thức $n=\sum_{d\mid n}\varphi(d)$.

<span id="trường-cyclotomic-chi-tiết"></span>

### Trường cyclotomic

Trường cyclotomic là trường mở rộng thu được bằng cách thêm căn đơn vị vào trường số hữu tỉ.

???+ abstract "Trường cyclotomic"
    Trường mở rộng $\mathbf Q(\zeta_n)$ thu được bằng cách thêm căn đơn vị phức bậc $n$, $\zeta_n=\mathrm{e}^{2\pi\mathrm{i}/n}$, vào trường số hữu tỉ $\mathbf Q$ được gọi là **trường cyclotomic bậc $n$** ($n$-th cyclotomic field).

Vì toàn bộ căn đơn vị bậc $n$ tạo thành nhóm cyclic $\langle\zeta_n\rangle$ dưới phép nhân, trường cyclotomic $\mathbf Q(\zeta_n)$ cũng chứa tất cả các căn đơn vị bậc $n$ này. Cụ thể, $\mathbf Q(\zeta_n)$ chính là trường phân rã của đa thức $x^n-1$ trên trường $\mathbf Q$.

???+ note "Định lý"
    Trường cyclotomic $\mathbf Q(\zeta_n)$ là trường phân rã của đa thức $x^n-1$ trên trường số hữu tỉ $\mathbf Q$.

??? note "Chứng minh"
    Gọi $F$ là trường phân rã của đa thức $x^n-1$ trên trường số hữu tỉ $\mathbf Q$. Vì trên $\mathbf Q(\zeta_n)$ có toàn bộ nghiệm phức của đa thức $x^n-1$, nên $F\subseteq\mathbf Q(\zeta_n)$. Ngược lại, vì $\zeta_n\in F$, nhất định có $\mathbf Q(\zeta_n)=F$. Do đó $F=\mathbf Q(\zeta_n)$.

Điều này có thể xem là một định nghĩa tương đương của trường cyclotomic. Hơn nữa, thêm bất kỳ căn đơn vị nguyên thủy bậc $n$ nào vào trường số hữu tỉ cũng đều thu được $\mathbf Q(\zeta_n)$.

<span id="đa-thức-cyclotomic"></span>

### Đa thức cyclotomic

Trường cyclotomic $\mathbf Q(\zeta_n)$ là mở rộng đơn đại số của trường số hữu tỉ $\mathbf Q$. Theo phân tích ở trên, trường như vậy luôn đẳng cấu với vành thương của một vành đa thức nào đó. Để có đẳng cấu này, cần phân tích đa thức tối tiểu $f(x)$ của $\zeta_n$. Vì $\zeta_n$ là nghiệm của $x^n-1$, nên $f(x)$ nhất định là một nhân tử của $x^n-1$. Điều này yêu cầu khảo sát phân tích nhân tử của đa thức $x^n-1$ trong $\mathbf Q[x]$. Theo bổ đề Gauss, nó nhất định có thể phân tích trong $\mathbf Z[x]$ thành tích của một số đa thức monic bất khả quy hệ số nguyên.

Vì $\mathbf Q(\zeta_n)$ là trường phân rã, đa thức $x^n-1$ có phân tích:

$$
x^n-1=\prod_{\zeta\in C_n}(x-\zeta)=\prod_{d\mid n}\prod_{\zeta\in P_d}(x-\zeta).
$$

Do các căn đơn vị có bậc khác nhau có tính chất đại số khác nhau, chúng nhất định không phải là nghiệm của cùng một đa thức bất khả quy. Vì vậy, để khảo sát đa thức tối tiểu của $\zeta_n$, chỉ cần xét nhân tử sau trong phân tích trên:

$$
\Phi_n(x)=\prod_{\zeta\in P_n}(x-\zeta).
$$

Đa thức tối tiểu của căn đơn vị $\zeta_n$ nhất định là một nhân tử của $\Phi_n(x)$. Hơn nữa, $\Phi_n(x)$ được định nghĩa như vậy có các tính chất sau:

???+ note "Định lý"
    $\Phi_n(x)$ là đa thức monic hệ số nguyên và bất khả quy trong $\mathbf Z[x]$.

??? note "Chứng minh"
    Theo định nghĩa, $\Phi_n(x)$ là đa thức monic. Trước hết cần chứng minh $\Phi_n(x)\in\mathbf Z[x]$. Theo bổ đề Gauss, đa thức $x^n-1$ có cùng phân tích trong $\mathbf Z[x]$ và $\mathbf Q[x]$, và mỗi nhân tử đều là đa thức monic hệ số nguyên. Trong phân tích này, mỗi nhân tử $f(x)$ đều bất khả quy trên $\mathbf Q[x]$ và phân rã trong $\mathbf Q(\zeta_n)$; mọi nghiệm của nó đều là căn đơn vị bậc $n$ và nhất định có cùng bậc, nên toàn bộ các nghiệm này phải thuộc một $P_d$ nào đó chứ không thể nằm rải rác trong nhiều $P_d$. Điều này có nghĩa mỗi nhân tử $f(x)$ đều là nhân tử của một $\Phi_d(x)$ nào đó. Vì vậy $\Phi_n(x)$ có thể viết thành tích của một số đa thức monic hệ số nguyên, nên nó cũng là đa thức monic hệ số nguyên.
    
    Tiếp theo cần chứng minh $\Phi_n(x)$ bất khả quy trong $\mathbf Z[x]$. Giả sử nó có phân tích $f(x)g(x)$, và $f(x)$ bất khả quy trong $\mathbf Z[x]$. Chỉ cần chứng minh $f(x)$ chứa mọi căn đơn vị nguyên thủy bậc $n$. Nói cách khác, giả sử $\zeta$ là một nghiệm của $f(x)$, cần chứng minh với mọi $k\perp n$, $\zeta^k$ cũng là nghiệm của $f(x)$. Vì $k$ luôn có thể phân tích thành tích các số nguyên tố, chỉ cần chứng minh với mọi số nguyên tố $p\perp n$, $\zeta^p$ là nghiệm của $f(x)$. Giả sử ngược lại, $\zeta^p$ là nghiệm của $g(x)$. Khi đó $\zeta$ là nghiệm chung của hai đa thức $f(x)$ và $g(x^p)$ trong $\mathbf Z[x]$. Vì $f(x)$ là đa thức tối tiểu của $\zeta$ trên $\mathbf Q$, nhất định $f(x)$ chia hết $g(x^p)$; tức tồn tại $h(x)\in\mathbf Z[x]$ sao cho $g(x^p)=f(x)h(x)$. Lấy modulo $p$ hai vế, thu được đẳng thức trên $\mathbf F_p[x]$: $\overline{g}(x^p)=\overline{f}(x)\overline{h}(x)$. Dùng tự đồng cấu Frobenius, $\overline{g}(x)^p=\overline{f}(x)\overline{h}(x)$. Vì $\mathbf F_p[x]$ cũng là miền phân tích duy nhất, $\overline{g}(x)$ và $\overline{f}(x)$ nhất định có ước chung không tầm thường, nên $x^n-\overline 1=\overline{f}(x)\overline{g}(x)$ không tách được trên $\mathbf F_p$. Nhưng vì $p\perp n$, đạo hàm hình thức $nx^{n-1}$ của nó nguyên tố cùng nhau với chính nó, mâu thuẫn với việc không tách được. Do đó có thể chứng minh $\zeta^p$ nhất định vẫn là nghiệm của $f(x)$, nên $f(x)$ chứa mọi căn đơn vị nguyên thủy bậc $n$, tức $f(x)=\Phi_n(x)$.

Điều này cho thấy nó chính là đa thức tối tiểu của $\zeta_n$, còn được gọi là **đa thức cyclotomic bậc $n$** ($n$-th cyclotomic polynomial). Công thức định nghĩa ở trên cho biết nó có $\varphi(n)$ nghiệm phức, và các nghiệm phức này chính là toàn bộ căn đơn vị nguyên thủy bậc $n$; trong đó $\varphi(n)$ là [hàm Euler](../number-theory/euler-totient.md). Điều này cũng cho thấy $\mathbf Q(\zeta_n)/\mathbf Q$ là mở rộng có bậc $\varphi(n)$.

Vành số nguyên đại số trong trường cyclotomic $\mathbf Q(\zeta_n)$ là $\mathbf Z[\zeta_n]$. Ngoài ra, khi $\varphi(n)=2$, trường cyclotomic là [mở rộng bậc hai](../number-theory/quadratic.md). Cụ thể, $\mathbf Q(\zeta_4)$ là trường bậc hai $\mathbf Q(\sqrt{-1})$; $\mathbf Q(\zeta_3)$ và $\mathbf Q(\zeta_6)$ giống nhau, đều là trường bậc hai $\mathbf Q(\sqrt{-3})$.

Dùng đa thức cyclotomic, đa thức $x^n-1$ có phân tích duy nhất trong $\mathbf Z[x]$:

$$
x^n-1=\prod_{d\mid n}\Phi_d(x).
$$

Vì vậy $(x^d-1)\mid(x^n-1)$ khi và chỉ khi $d\mid n$. Hơn nữa, áp dụng [nghịch đảo Möbius](../number-theory/mobius.md) cho công thức này thu được

$$
\Phi_n(x)=\prod_{d\mid n}(x^d-1)^{\mu(n/d)}.
$$

Dùng biểu thức này, có thể tính đệ quy toàn bộ đa thức cyclotomic. Dưới đây là vài đa thức cyclotomic đầu tiên để độc giả làm quen.

???+ example "Đa thức cyclotomic"
    $10$ đa thức cyclotomic đầu tiên như sau:
    
    $$
    \begin{aligned}
    \Phi_1(x) &= x-1,\\
    \Phi_2(x) &= x+1,\\
    \Phi_3(x) &= x^2+x+1,\\
    \Phi_4(x) &= x^2+1,\\
    \Phi_5(x) &= x^4+x^3+x^2+x+1,\\
    \Phi_6(x) &= x^2-x+1,\\
    \Phi_7(x) &= x^6+x^5+x^4+x^3+x^2+x+1,\\
    \Phi_8(x) &= x^4+1,\\
    \Phi_9(x) &= x^6+x^3+1,\\
    \Phi_{10}(x) &= x^4-x^3+x^2-x+1.
    \end{aligned}
    $$
    
    Một sự thật thú vị là tuy nhìn qua có vẻ hệ số của các đa thức cyclotomic này chỉ có thể là $0$ và $\pm1$, nhưng với $n$ tổng quát kết luận này không đúng. Phản ví dụ đầu tiên xuất hiện ở $\Phi_{105}(x)$; hơn nữa có thể chứng minh rằng khi $n$ tăng, hệ số của nó có thể đạt giá trị lớn tùy ý.

Dùng công thức nghịch đảo Möbius ở trên, có thể tổng kết các tính chất sau để đơn giản hóa việc tính $\Phi_n(x)$:

???+ note "Tính chất"
    Với đa thức cyclotomic $\Phi_n(x)$, có:
    
    1.  Nếu số nguyên tố $p\mid n$, thì $\Phi_{pn}(x)=\Phi_n(x^p)$.
    2.  Nếu số nguyên tố $p\perp n$, thì $\Phi_{pn}(x)=\dfrac{\Phi_n(x^p)}{\Phi_n(x)}$.
    3.  Đặc biệt, nếu $n$ là số lẻ, thì $\Phi_{2n}(x)=\Phi_n(-x)$.
    4.  Với số nguyên tố $p$, có $\Phi_{p}(x)=1+x+\cdots+x^{p-1}$.
    5.  Đặc biệt, $\Phi_{2^k}(x)=x^{2^{k-1}}+1$.

Các tính chất này cho thấy trọng tâm của việc tính đa thức cyclotomic nằm ở trường hợp bậc là số lẻ không chứa nhân tử chính phương. Với trường hợp này, có thể dùng tính chất thứ hai để thêm từng nhân tử nguyên tố; mỗi lần thêm một nhân tử nguyên tố chỉ cần thực hiện một phép chia đa thức.

Đa thức cyclotomic còn có nhiều tính chất khác.

???+ note "Định lý"
    Giả sử $\Phi_n(x)$ là đa thức cyclotomic bậc $n>1$, và bậc đa thức là $\varphi(n)$. Khi đó:
    
    1.  Đa thức $\Phi_n(x)$ là đa thức đối xứng, hệ số của hạng tử bậc $j$ bằng hệ số của hạng tử bậc $\varphi(n)-j$, tức $\Phi_n(x)=x^{\varphi(n)}\Phi_n(1/x)$.
    2.  Hệ số của hạng tử bậc $\varphi(n)-1$ bằng $-\mu(n)$, với $\mu$ là hàm Möbius.
    3.  Nếu $n$ là lũy thừa của số nguyên tố $p^k$, thì $\Phi_n(1)=p$; ngược lại, $\Phi_n(1)=1$.
    4.  Giả sử $b>1$ và $p$ là nhân tử nguyên tố của $\Phi_n(b)$. Khi đó $p\mid n$, hoặc $n$ là bậc của $b$ trong nhóm nhân $(\mathbf Z/p\mathbf Z)^\times$, và hai trường hợp này không thể xảy ra đồng thời.

??? note "Chứng minh"
    Với ba tính chất đầu, chỉ cần dùng nghịch đảo Möbius. Với 1, trực tiếp xét dạng nghịch đảo Möbius của $\Phi_n(x)$, tức $\Phi_n(x)=\prod_{d\mid n}(x^d-1)^{\mu(n/d)}$. Với 2, đặt $f(n)$ là hệ số của hạng tử bậc $\varphi(n)-1$ trong $\Phi_n(x)$, so sánh hệ số của hạng tử bậc $n-1$ ở hai vế của đẳng thức $x^n-1=\prod_{d\mid n}\Phi_d(x)$ được $\sum_{d\mid n}f(d)=-[n=1]$, rồi dùng nghịch đảo Möbius. Với 3, chia hai vế của $x^n-1=\prod_{d\mid n}\Phi_d(x)$ cho $\Phi_1(x)=x-1$, rồi thay $x=1$, có $n=\prod_{d\mid n,d\neq 1}\Phi_d(1)$, sau đó dùng nghịch đảo Möbius.
    
    Dưới đây chứng minh tính chất thứ tư. Trước hết, nếu $n$ là bậc của $b$ trong nhóm nhân $(\mathbf Z/p\mathbf Z)^\times$, thì $n$ là số nguyên dương nhỏ nhất thỏa mãn $p\mid b^n-1$, do đó $p\mid\Phi_n(b)$. Ngược lại, nếu $p\mid\Phi_n(b)$, thì $b^n\equiv 1\pmod p$. Nếu $n$ không phải bậc của $b$ trong nhóm nhân $(\mathbf Z/p\mathbf Z)^\times$, gọi bậc đó là $k$, nhất định có $k\mid n$ và $p\mid\Phi_k(b)$. Khi đó $\Phi_k(x)$ và $\Phi_n(x)$ có nghiệm chung $b$ trong trường $\mathbf F_p$, cho thấy $x^n-1$ có nghiệm bội $b$. Điều này suy ra $p\mid n$; nếu không, $x^n-1$ nguyên tố cùng nhau với đạo hàm của nó, nên tách được trên $\mathbf F_p$, không thể có nghiệm bội. Vì vậy nhân tử nguyên tố $p$ của $\Phi_n(b)$ chỉ có hai khả năng: $p\mid n$, hoặc $n$ là bậc của $b$ trong nhóm nhân $(\mathbf Z/p\mathbf Z)^\times$. Hai khả năng này loại trừ nhau, vì khả năng sau kéo theo $n\mid p-1$.

Đa thức cyclotomic còn có thể dùng để giải một số bài toán số học và đại số. Chẳng hạn, độ dài chu kỳ của một phân số khi viết thành số thập phân trong một cơ số nào đó có liên hệ mật thiết với đa thức cyclotomic. Với các ứng dụng cụ thể này, độc giả quan tâm có thể tham khảo tài liệu cuối bài.

<span id="trường-hữu-hạn"></span>

## Trường hữu hạn

**Trường hữu hạn** (finite field), còn gọi là **trường Galois** (Galois field), là trường chỉ có hữu hạn phần tử. Cấu trúc của trường hữu hạn được xác định duy nhất bởi số phần tử của nó, và số phần tử này nhất định là lũy thừa của một số nguyên tố.

???+ note "Định lý"
    Trường có kích thước $q$ tồn tại khi và chỉ khi $q$ có dạng lũy thừa nguyên tố $p^n$. Hơn nữa, trường như vậy là duy nhất đến đẳng cấu, ký hiệu là $\mathbf F_q$. Số nguyên tố $p$ là đặc trưng của trường $\mathbf F_q$, số nguyên dương $n$ là bậc của mở rộng trường $\mathbf F_q/\mathbf F_p$. Cuối cùng, $\mathbf F_q$ là trường phân rã của đa thức $x^q-x$ trên $\mathbf F_p$, và chứa đúng $q$ nghiệm phân biệt của $x^q-x$.

??? note "Chứng minh"
    Giả sử $F$ là trường hữu hạn. Đặc trưng của trường $F$ nhất định hữu hạn, ký hiệu là $p$; do đó $F$ có trường con nguyên tố $\mathbf F_p$. Hơn nữa, $F$ nhất định là mở rộng hữu hạn của $\mathbf F_p$, gọi bậc mở rộng là $n$. Với tư cách không gian vectơ $n$ chiều trên $\mathbf F_p$, trường $F$ có $q=p^n$ phần tử. Toàn bộ các phần tử khác không của trường $F$ tạo thành nhóm $F^\times$ có bậc $q-1$, nên có $x^{q-1}=1$. Vì vậy mọi phần tử của $F=F^\times\cup\{0\}$ đều thỏa mãn $x^q=x$, tức chúng là $q$ nghiệm phân biệt của đa thức $x^q-x$. Do đó trong trường $F$, đa thức $x^q-x$ có nhân tử $\prod_{\alpha\in F}(x-\alpha)$; nhưng nhân tử này đã có bậc $q$ và hệ số đầu bằng $1$, nên $x^q-x=\prod_{\alpha\in F}(x-\alpha)$. Điều này cho thấy $x^q-x$ phân rã trong $F$. Với bất kỳ trường nào làm $x^q-x$ phân rã, do $x^q-x$ có $q$ nghiệm phân biệt, trường đó nhất định có ít nhất $q$ phần tử. Điều này chứng tỏ $F$ là trường nhỏ nhất làm $x^q-x$ phân rã, tức là trường phân rã của $x^q-x$. Tóm lại, trường hữu hạn kích thước $q$ nhất định là trường phân rã của đa thức $x^q-x$ trên trường con nguyên tố của nó. Vì trường phân rã là duy nhất đến đẳng cấu, trường kích thước $q$ cũng nhất định duy nhất.
    
    Ngược lại, cho số nguyên tố $p$ và lũy thừa $q=p^n$ của nó, cần chứng minh trường phân rã của đa thức $x^q-x$ trên $\mathbf F_p$ có đúng $q$ phần tử, từ đó chứng minh mọi trường có kích thước $q$ với $q$ là lũy thừa nguyên tố đều tồn tại. Vì trường phân rã của đa thức $x^q-x$ trên $\mathbf F_p$ luôn tồn tại, gọi $F$ là tập tất cả các nghiệm của $x^q-x$ trong trường phân rã đó. Bây giờ cần chứng minh $F$ là trường, khi đó nó chính là trường phân rã của đa thức $x^q-x$. Nhưng lặp tự đồng cấu Frobenius $n$ lần cho biết $x\mapsto x^q$ cũng là tự đồng cấu, nên với mọi $\alpha,\beta\in F$ đều có $(\alpha\pm\beta)^q=\alpha^q\pm\beta^q$, $(\alpha\beta)^q=\alpha^q\beta^q$ và $(\alpha^{-1})^q=(\alpha^q)^{-1}$. Vì vậy tập $F$ đóng dưới các phép cộng, trừ, nhân, chia; nó là trường. Điều này chứng tỏ $F$ chính là trường phân rã của đa thức $x^q-x$ trên $\mathbf F_p$.

???+ note "Hệ quả"
    Trong trường hữu hạn $\mathbf F_q$ với $q>2$, tổng của toàn bộ phần tử khác không là $0$, và tích của chúng là $-1$.

??? note "Chứng minh"
    Toàn bộ phần tử khác không của trường hữu hạn chính là $q-1$ nghiệm của đa thức $x^{q-1}-1$. Áp dụng định lý Vieta là đủ.

Trong trường nguyên tố $\mathbf F_p$, kết luận về tích trong hệ quả này chính là một phần của [định lý Wilson](../number-theory/factorial.md#định-lý-wilson) trong số học.

<span id="cấu-trúc-nhân"></span>

### Cấu trúc nhân

Nhóm nhân $\mathbf F^\times=\mathbf F\setminus\{0\}$ của trường hữu hạn nhất định là nhóm cyclic.

???+ note "Định lý"
    Mọi nhóm con hữu hạn của nhóm nhân của một trường đều là nhóm cyclic.

??? note "Chứng minh"
    Giả sử $G$ là nhóm con của nhóm nhân của trường $F$ và $|G|=n$. Khi đó $G$ là nhóm Abel hữu hạn. Theo định lý cơ bản về nhóm Abel hữu hạn, nhóm $G$ có phân tích theo nhân tử bất biến $C_{n_1}\times\cdots\times C_{n_s}$ với $n_1\mid\cdots\mid n_s$. Vì vậy, với mọi phần tử $x$ trong $G$ đều có $x^{n_s}=1$. Nói cách khác, các phần tử của nhóm $G$ đều là nghiệm của đa thức $x^{n_s}-1$ trên trường $F$. Nhưng đa thức $x^{n_s}-1$ có nhiều nhất $n_s$ nghiệm phân biệt, tức $n\le n_s$. Mặt khác $n_s\le n$, nên suy ra $n_s=n$. Điều này cho thấy $G\cong C_{n_s}$, tức $G$ là nhóm cyclic.

???+ note "Hệ quả"
    Nhóm nhân của trường hữu hạn $\mathbf F_q$ thỏa mãn $\mathbf F_q^\times\cong C_{q-1}$.

Trong nhóm cyclic $\mathbf F_q^\times$ có $\varphi(q-1)$ phần tử sinh, chúng được gọi là phần tử nguyên thủy của trường hữu hạn; trong đó $\varphi(n)$ là [hàm Euler](../number-theory/euler-totient.md).

???+ abstract "Phần tử nguyên thủy"
    Phần tử sinh của nhóm nhân của trường hữu hạn $\mathbf F_q$ được gọi là **phần tử nguyên thủy** (primitive element) của $\mathbf F_q$.

??? warning "Phần tử nguyên thủy trong mở rộng đơn và trong trường hữu hạn không giống nhau"
    Dù phần tử nguyên thủy trong mở rộng đơn và phần tử nguyên thủy trong trường hữu hạn có cùng tên, chúng không giống nhau. Phần tử nguyên thủy trong mở rộng đơn là phần tử sinh của mở rộng đơn tương ứng, còn phần tử nguyên thủy trong trường hữu hạn là phần tử sinh của nhóm nhân tương ứng (với tư cách nhóm cyclic). Phần tử nguyên thủy của trường hữu hạn khi xem nó là mở rộng đơn của trường con nguyên tố không nhất thiết là phần tử nguyên thủy của chính trường hữu hạn đó. Chẳng hạn trong $\mathbf F_{25}\cong\mathbf F_5[x]/(x^2+x+1)$, $\overline x$ là phần tử nguyên thủy của mở rộng trường, nhưng không phải phần tử nguyên thủy của trường $\mathbf F_{25}$, vì bậc của nó là $3$.

??? warning "Phần tử nguyên thủy trong $\mathbf F_{q}$ và căn nguyên thủy modulo $q$ cũng không giống nhau"
    Với trường hữu hạn $\mathbf F_{q}$ có đặc trưng lẻ, luôn tồn tại [căn nguyên thủy](./ring-theory.md#ứng-dụng-nhóm-nhân-của-các-lớp-đồng-dư-số-nguyên) modulo $q$ (primitive root). Tuy nhiên, không nên nhầm nó với phần tử nguyên thủy (primitive element) trong trường hữu hạn $\mathbf F_{q}$. Tuy cả hai đều là phần tử sinh của cấu trúc nhân tương ứng khi cấu trúc đó là nhóm cyclic, $(\mathbf Z/q\mathbf Z)^\times$ và $\mathbf F_q$ không giống nhau khi $q$ không phải số nguyên tố. Chẳng hạn, bậc của nhóm trước là $\varphi(q)$ còn bậc của nhóm sau là $q-1$, nên kích thước của hai nhóm nhân đã khác nhau.

Giả sử $\alpha$ là phần tử nguyên thủy của trường hữu hạn $\mathbf F_q$. Khi đó, với mọi $x\in\mathbf F_q^\times$ đều tồn tại duy nhất số tự nhiên $k<q-1$ sao cho $x=\alpha^k$; số $k$ này được gọi là **logarit rời rạc** (discrete logarithm) của phần tử $x$ theo cơ số $\alpha$ trên $\mathbf F_q$. Tương tự trường hợp trên $\mathbf F_p$, [thuật toán logarit rời rạc](../number-theory/discrete-logarithm.md) thường có độ phức tạp khá cao.

Thông qua phép nhân, phần tử nguyên thủy đã có thể sinh toàn bộ phần tử khác không của trường. Điều này cho thấy trường hữu hạn, khi được xem là mở rộng của một trường con, nhất định là mở rộng đơn.

???+ note "Định lý"
    Với trường hữu hạn $\mathbf F_q$, giả sử $F$ là trường con của $\mathbf F_q$, thì $\mathbf F_q$ là mở rộng đơn đại số trên $F$; nếu $\alpha$ là phần tử nguyên thủy của $\mathbf F_q$, thì $\mathbf F_q=F(\alpha)$.

Đa thức tối tiểu của phần tử nguyên thủy là đa thức bất khả quy trên trường con của trường hữu hạn.

<span id="quan-hệ-bao-hàm"></span>

### Quan hệ bao hàm

Trường con của trường hữu hạn cũng là trường hữu hạn. Quan hệ bao hàm giữa các trường hữu hạn cũng hoàn toàn được xác định bởi kích thước của chúng.

???+ note "Định lý"
    Giả sử $\mathbf F_q$ và $\mathbf F_r$ là các trường hữu hạn. Khi đó $\mathbf F_r$ là trường con của $\mathbf F_q$ khi và chỉ khi tồn tại $k$ sao cho $q=r^k$. Nói cách khác, $\mathbf F_{p^d}$ là trường con của $\mathbf F_{p^n}$ khi và chỉ khi $d\mid n$.

??? note "Chứng minh"
    Nếu $\mathbf F_r$ là trường con của $\mathbf F_q$, hai trường nhất định có cùng đặc trưng $p$. Các mở rộng trường $\mathbf F_q/\mathbf F_r$, $\mathbf F_r/\mathbf F_p$ và $\mathbf F_q/\mathbf F_p$ đều là mở rộng đơn đại số; lần lượt gọi bậc mở rộng là $k,d,n$, khi đó bậc mở rộng nhất định thỏa mãn $n=kd$. Hơn nữa $r=p^d$ và $q=p^n$, nên $q=p^n=p^{kd}=(p^d)^k=r^k$.
    
    Ngược lại, cần chứng minh với mọi $d\mid n$, $\mathbf F_{p^d}$ đều là trường con của $\mathbf F_{p^n}$. Đặt $r=p^d$ và $q=p^n$. Gọi $F$ là tập toàn bộ nghiệm của phương trình $x^r-x=0$ trong trường hữu hạn $\mathbf F_q$. Dùng tự đồng cấu Frobenius có thể chứng minh tập $F$ nhất định tạo thành trường; điểm then chốt là chứng minh các nghiệm như vậy có đúng $r$ phần tử, khi đó mới có $F\cong\mathbf F_r$. Vì $d\mid n$, nên $(p^d-1)\mid(p^n-1)$, do đó $(x^{p^d-1}-1)\mid(x^{p^n-1}-1)$, tức $(x^r-x)\mid (x^q-x)$. Vì vậy $x^r-x$ phân rã trên $\mathbf F_q$, nên có $r$ nghiệm khác nhau trong $\mathbf F_q$. Điều này chứng tỏ $F\cong\mathbf F_r$ là trường con của $\mathbf F_q$.

Định lý này cho thấy quan hệ bao hàm của trường hữu hạn $\mathbf F_{p^n}$ tương ứng với quan hệ chia hết giữa các số mũ $n$ trong kích thước trường $p^n$. Dàn tạo bởi tất cả các trường hữu hạn đặc trưng $p$, $\mathbf F_{p^n}$, cũng đẳng cấu với dàn các số nguyên $n$ dưới quan hệ chia hết. Để các phép toán như giao của các trường hữu hạn $\mathbf F_{p^n}$ có ý nghĩa, cần nhúng mọi trường đặc trưng $p$ vào bao đóng đại số của $\mathbf F_p$.

???+ note "Định lý"
    Giả sử $F$ là bao đóng đại số của $\mathbf F_p$, và tập nghiệm trong $F$ của đa thức $x^{p^n}-x$ tạo thành trường hữu hạn $\mathbf F_{p^n}$. Khi đó:
    
    1.  $F=\bigcup_{n=1}^\infty\mathbf F_{p^n}$, tức bao đóng đại số của $\mathbf F_p$ chính là hợp của mọi trường hữu hạn đặc trưng $p$.
    2.  Dàn của tất cả các trường hữu hạn đặc trưng $p$, $\mathbf F_{p^n}$, dưới quan hệ bao hàm đẳng cấu với dàn các số nguyên $n$ dưới quan hệ chia hết. Đặc biệt, giao của $\mathbf F_{p^n}$ và $\mathbf F_{p^m}$ là $\mathbf F_{p^n}\cap\mathbf F_{p^m}=\mathbf F_{p^{\gcd(n,m)}}$, còn trường nhỏ nhất đồng thời chứa $\mathbf F_{p^n}$ và $\mathbf F_{p^m}$ là $\mathbf F_{p^n}\mathbf F_{p^m}=\mathbf F_{p^{\operatorname{lcm}(n,m)}}$.

??? note "Chứng minh"
    Điểm then chốt là chứng minh phần thứ nhất, tức $\bigcup_{n=1}^\infty\mathbf F_{p^n}$ là bao đóng đại số của $\mathbf F_p$. Phần thứ hai là hệ quả đơn giản của định lý về trường con của trường hữu hạn ở trên.
    
    Với bất kỳ $\alpha\in\bigcup_{n=1}^\infty\mathbf F_{p^n}$, nhất định tồn tại $n\in\mathbf N_+$ sao cho $\alpha\in\mathbf F_{p^n}$, nên $\alpha$ là phần tử đại số trên $\mathbf F_p$. Vì vậy $\bigcup_{n=1}^\infty\mathbf F_{p^n}$ là mở rộng đại số của $\mathbf F_p$. Với mọi đa thức bậc $m$ trên $\mathbf F_p$, $f(x)$, nó có nhiều nhất $m$ nghiệm khác nhau $\{\alpha_i\}_{i=1}^m$ trong bao đóng đại số $F$. Gọi $n_i$ là bậc đa thức tối tiểu của nghiệm $\alpha_i$, khi đó $\alpha_i$ nhất định nằm trong trường $\mathbf F_{p^{n_i}}$. Do đó mọi nghiệm của $f(x)$ đều nằm trong $\bigcup_{n=1}^\infty\mathbf F_{p^n}$, tức $f(x)$ phân rã trên $\bigcup_{n=1}^\infty\mathbf F_{p^n}$. Theo định nghĩa bao đóng đại số, $\bigcup_{n=1}^\infty\mathbf F_{p^n}$ chính là bao đóng đại số của $\mathbf F_p$.

<span id="nhóm-tự-đẳng-cấu"></span>

### Nhóm tự đẳng cấu

Các trường con của trường hữu hạn $\mathbf F_q$ đều là tập nghiệm của một đa thức dạng $x^r-x$. Nói cách khác, chúng đều là tập điểm bất động của một ánh xạ nào đó $x\mapsto x^r$. Điều này hé lộ một tương ứng sâu sắc giữa trường con của trường hữu hạn và nhóm con của nhóm tự đẳng cấu.

Trên trường có đặc trưng $p$ luôn có tự đồng cấu Frobenius $\sigma_p:x\mapsto x^p$. Với trường hữu hạn $\mathbf F_q$, đây cũng là tự đẳng cấu; điều này cho thấy mọi trường hữu hạn $\mathbf F_q$ đều là trường hoàn hảo. Nhóm tự đẳng cấu của trường $\mathbf F_q$ là nhóm cyclic bậc $n$, $\langle \sigma_p\rangle$, trong đó một phần tử sinh là tự đồng cấu Frobenius $\sigma_p$.

???+ note "Định lý"
    Nhóm tự đẳng cấu của trường hữu hạn $\mathbf F_q$, $\operatorname{Aut}(\mathbf F_q)=\langle\sigma_p\rangle$, là nhóm cyclic bậc $n$, và phần tử sinh $\sigma_p$ là tự đồng cấu Frobenius $x\mapsto x^p$.

??? note "Chứng minh"
    Trước hết, tự đồng cấu Frobenius $\sigma_p$ trên trường hữu hạn $\mathbf F_q$ là tự đẳng cấu, vì đơn ánh trên tập hữu hạn nhất định cũng toàn ánh. Do đó $\sigma_p\in\operatorname{Aut}(\mathbf F_q)$.
    
    Tiếp theo, bậc của $\sigma_p$ là $n$. Lý do là với mọi $x\in\mathbf F_q$ đều có $\sigma_p^n(x)=x^{p^n}=x$, nên $\sigma_p^n$ là ánh xạ đồng nhất. Hơn nữa, với mọi $k<n$, $\sigma_p^k$ không phải ánh xạ đồng nhất; nếu không, mọi phần tử của $\mathbf F_q$ đều là nghiệm của $x^{p^k}-x$, điều này không thể xảy ra.
    
    Cuối cùng, $\operatorname{Aut}(\mathbf F_q)$ có nhiều nhất $n$ phần tử. Gọi $\alpha$ là một phần tử nguyên thủy của $\mathbf F_q$, khi đó tự đẳng cấu $\sigma\in \operatorname{Aut}(\mathbf F_q)$ được xác định duy nhất bởi giá trị của nó tại $\alpha$, tức $\sigma(\alpha)$. Nhưng $\sigma$ phải ánh xạ $\alpha$ đến một phần tử liên hợp của nó; nếu không, $\alpha$ và $\sigma(\alpha)$ sẽ không còn là nghiệm của cùng một đa thức tối tiểu. Các phần tử liên hợp như vậy chỉ có $n$ phần tử, nên $\operatorname{Aut}(\mathbf F_q)$ cũng có nhiều nhất $n$ phần tử.
    
    Vì vậy $n$ phần tử trong $\operatorname{Aut}(\mathbf F_q)$ chính là $\langle\sigma_p\rangle$. Định lý được chứng minh.

Các nhóm con của nhóm tự đẳng cấu $\operatorname{Aut}(\mathbf F_q)$ tương ứng một-một với các trường con của trường hữu hạn $\mathbf F_q$.

???+ note "Định lý"
    Giả sử $\mathbf F_q$ là trường hữu hạn, $\mathcal F$ là tập mọi trường con của nó, và $\mathcal G$ là tập mọi nhóm con của nhóm tự đẳng cấu $\operatorname{Aut}(\mathbf F_q)$. Khi đó:
    
    1.  Với $F\in\mathcal F$, đặt $\operatorname{Aut}(\mathbf F_q/F)$ là tập các tự đẳng cấu trong $\operatorname{Aut}(\mathbf F_q)$ giữ nguyên $F$, tức $\operatorname{Aut}(\mathbf F_q/F)=\{\sigma\in\operatorname{Aut}(\mathbf F_q):\forall x\in F(\sigma(x)=x)\}$, khi đó $\operatorname{Aut}(\mathbf F_q/F)\le\operatorname{Aut}(\mathbf F_q)$.
    2.  Với $G\in\mathcal G$, đặt $F^G$ là giao của tập điểm bất động của mọi tự đẳng cấu trong $G$, tức $F^G=\{x\in\mathbf F_q:\forall\sigma\in G(\sigma(x)=x)\}$, khi đó $F^G$ là trường con của $\mathbf F_q$.
    3.  Ánh xạ $F\rightarrow\operatorname{Aut}(\mathbf F_q/F)$ và ánh xạ $G\rightarrow F^G$ là nghịch đảo của nhau, và tạo thành một tương ứng một-một giữa $\mathcal F$ và $\mathcal G$.
    4.  Tương ứng một-một này ánh xạ quan hệ mở rộng giữa các trường con thành quan hệ bao hàm giữa các nhóm con: với mọi $F_1\subseteq F_2$, đều có $\operatorname{Aut}(\mathbf F_q/F_2)\le\operatorname{Aut}(\mathbf F_q/F_1)$.

Kết luận này là một trường hợp đặc biệt của định lý cơ bản trong lý thuyết Galois tổng quát. Nó liên hệ mở rộng trường với lý thuyết nhóm, nhờ đó có thể dùng phương pháp của lý thuyết nhóm để giải quyết vấn đề về mở rộng trường.

<span id="đa-thức-bất-khả-quy"></span>

### Đa thức bất khả quy

Đa thức bất khả quy trên trường hữu hạn $\mathbf F_q$ dễ đặc trưng. Vì mỗi đa thức bất khả quy bậc $n$ trên $\mathbf F_q$ tương ứng với mở rộng đại số bậc $n$, mà mở rộng như vậy là duy nhất, nên nghiệm của mọi đa thức bất khả quy bậc $n$ đều có thể tìm thấy trong $\mathbf F_{q^n}$. Điều này cho thấy đa thức bất khả quy bậc $n$ trên $\mathbf F_q$ phải là nhân tử của $x^{q^n}-x$. Để xác định toàn bộ đa thức bất khả quy bậc $n$ trên trường hữu hạn $\mathbf F_q$, cần khảo sát phân tích nhân tử của $x^{q^n}-x$ trên $\mathbf F_q$. Điều này rất giống trường hợp đa thức cyclotomic.

Các phần tử đại số trên trường hữu hạn $\mathbf F_q$ có thể được phân loại theo bậc đa thức tối tiểu. Gọi $P_n$ là tập các phần tử có đa thức tối tiểu bậc đúng bằng $n$, khi đó

$$
\mathbf F_{q^n} = \bigcup_{d\mid n}P_d.
$$

Điều này tương ứng với phân tích nhân tử

$$
x^{q^n}-x = \prod_{d|n}\prod_{\zeta\in P_d}(x-\zeta).
$$

Vì đa thức bất khả quy bậc $n$ có $n$ nghiệm, và mọi nghiệm này đều có đa thức tối tiểu bậc $n$, nên đa thức bất khả quy bậc $n$ nhất định là nhân tử của đa thức

$$
\prod_{\zeta\in P_n}(x-\zeta) = \prod_{d\mid n}\left(x^{q^d}-x\right)^{\mu(n/d)}.
$$

Biểu thức này thu được bằng cách áp dụng [nghịch đảo Möbius](../number-theory/mobius.md) cho phân tích nhân tử ở trên. Vì bậc của đa thức này là

$$
\sum_{d\mid n}\mu(d)q^{n/d},
$$

nên số đa thức monic bất khả quy bậc $n$ trên $\mathbf F_q$ là

$$
\frac1n\sum_{d\mid n}\mu(d)q^{n/d}.
$$

Đây đúng bằng số loại vòng cổ độ dài $n$ dùng $q$ màu, không phân biệt các cấu hình chỉ khác nhau bởi phép quay ([chứng minh](../combinatorics/polya.md#nhóm-cyclic)), nên còn được gọi là đa thức vòng cổ (necklace polynomial).

???+ note "Định lý"
    Trên trường hữu hạn $\mathbf F_q$ tồn tại đa thức bất khả quy với mọi bậc.

Vì đa thức bất khả quy trên trường hữu hạn có cấu trúc đơn giản, việc phân tích nhân tử đa thức trên trường hữu hạn trở nên khá thuận tiện. Chẳng hạn, để xác định toàn bộ nhân tử bất khả quy bậc $n$ của một đa thức cho trước, chỉ cần tính ước chung lớn nhất của đa thức đó với $x^{q^n}-x$[^ddf]. Tương tự, chỉ cần một đa thức bậc $n$ nguyên tố cùng nhau với mọi đa thức $x^{q^k}-1$ với $k<n$, có thể kết luận đa thức bậc $n$ đó bất khả quy trên $\mathbf F_q$.

Phần trước đã chỉ ra rằng nghiệm của đa thức bất khả quy trên trường hữu hạn không nhất thiết là phần tử nguyên thủy của trường mở rộng tương ứng với tư cách trường hữu hạn. Đa thức tối tiểu của phần tử nguyên thủy của trường hữu hạn $\mathbf F_q$ trên trường con nguyên tố $\mathbf F_p$ còn được gọi là **đa thức nguyên thủy**[^prim-poly] (primitive polynomial) trên trường $\mathbf F_p$. Dùng đa thức như vậy để cài đặt mở rộng trường có thể bảo đảm $\overline x$ nhất định là phần tử nguyên thủy trong trường mở rộng. Các đa thức nguyên thủy bậc $n$ trên trường $\mathbf F_p$ có thể thu được bằng cách phân tích nhân tử đa thức cyclotomic $\Phi_n(x)$ trên $\mathbf F_p$.

???+ note "Định lý"
    Giả sử $p$ là số nguyên tố, $n$ là số nguyên dương, và $p\perp n$. Lại giả sử $d$ là bậc của phần tử $p$ trong nhóm nhân $(\mathbf Z/n\mathbf Z)^\times$. Khi đó đa thức cyclotomic $\Phi_n(x)$ phân tích trên trường $\mathbf F_p$ thành tích của $\dfrac{\varphi(n)}{d}$ đa thức nguyên thủy bậc $d$ trên $\mathbf F_p$. Đặc biệt, đa thức cyclotomic $\Phi_n(x)$ bất khả quy trên trường $\mathbf F_p$ khi và chỉ khi $p$ là căn nguyên thủy modulo $n$.

??? note "Chứng minh"
    Dựa trên việc nghiệm của đa thức cyclotomic bậc $n$ là mọi căn đơn vị nguyên thủy bậc $n$ của $\mathbf F_p$, và bậc đa thức tối tiểu của một căn đơn vị nguyên thủy bậc $n$ chính là số lượng phần tử liên hợp của nó (bao gồm chính nó), cũng bằng độ dài quỹ đạo của nó dưới nhóm tự đẳng cấu $\langle\sigma_p\rangle$, suy ra $d$ là độ dài quỹ đạo của nhóm cyclic sinh bởi ánh xạ $\zeta^i\mapsto\zeta^{ip}$ trên $\{\zeta^i:i\perp n\}$, tức là bậc của phần tử $p$ trong nhóm nhân $(\mathbf Z/n\mathbf Z)^\times$. Nếu không muốn dựa vào lý thuyết Galois, cũng có thể chứng minh điều này bằng cách chỉ ra $d$ là số nguyên dương nhỏ nhất sao cho $(x^n-1)\mid(x^{p^d-1}-1)$. Các kết luận còn lại suy ra trực tiếp từ các định nghĩa.

Dù đa thức bất khả quy rất quan trọng đối với việc cài đặt trường hữu hạn, không có phương pháp tất định tốt để tìm một đa thức bất khả quy bậc $n$ trên trường hữu hạn $\mathbf F_q$. Trong trường hợp tổng quát, có thể dùng phương pháp ngẫu nhiên để sinh đa thức bất khả quy như vậy. Vì trong tất cả các đa thức monic bậc $n$, tỉ lệ đa thức bất khả quy là $\Theta(1/n)$, có thể sinh ngẫu nhiên một đa thức monic bậc $n$ rồi kiểm tra nó có khả quy hay không. Làm như vậy kỳ vọng tìm được một đa thức bất khả quy sau khi sinh $\Theta(n)$ đa thức monic. Tuy nhiên, đa thức bất khả quy sinh theo cách này không nhất thiết là đa thức nguyên thủy, hệ số cũng không nhất thiết đơn giản. Trong thực tế, nếu kích thước trường hữu hạn được cho trước, thường có thể tra bảng[^list-prim-poly] để tìm đa thức nguyên thủy có hệ số đơn giản, thuận tiện cho tính toán về sau.

<span id="triển-khai-tham-khảo"></span>

### Triển khai tham khảo

Mục này cung cấp một cài đặt trường hữu hạn đơn giản, chỉ để tham khảo. Mã có cài đặt phương pháp sinh ngẫu nhiên đa thức bất khả quy.

??? example "Triển khai tham khảo"
    ```cpp
    --8<-- "docs/math/code/finite-field/finite-field_1.cpp"
    ```

Trường hữu hạn được dùng nhiều nhất trong mật mã học là trường có đặc trưng $2$. Với loại trường hữu hạn này, có thể lưu các phần tử trong trường dưới dạng chuỗi 01 và dùng phép toán bit để cài đặt các phép toán của trường.

<span id="ứng-dụng"></span>

## Ứng dụng

Mục này liệt kê một số ứng dụng của mở rộng trường trong lập trình thi đấu. Tình huống quan trọng nhất là khi tính một biểu thức số học trên trường, quá trình trung gian cần đưa vào một số phần tử không tồn tại trong trường ban đầu để phép tính trực tiếp trở nên khả thi. Độc giả hẳn đã quen với việc dùng số phức để giải bài toán số thực; đó là một ví dụ về mở rộng trên trường số thực. Điều độc giả có thể ít quen hơn là mở rộng trên trường hữu hạn. Vì vậy, phần này chủ yếu thảo luận mở rộng trên trường hữu hạn, đặc biệt là mở rộng trên trường nguyên tố $\mathbf F_p$.

Trong một số trường hợp, mở rộng trường có thể giảm độ phức tạp tính toán nên là cần thiết, ví dụ [biến đổi Fourier nhanh](../poly/fft.md) trên trường số thực. Trong một số trường hợp khác, mở rộng trường chỉ là một trong nhiều cách giải, và thường có phương pháp có độ phức tạp tương tự nhưng tránh dùng mở rộng trường, ví dụ phép tính dãy Fibonacci sẽ nói ngay sau đây. Khi tìm hiểu các ứng dụng này, độc giả nên so sánh ưu nhược điểm của các phương pháp khác nhau để chọn phương pháp phù hợp khi giải bài.

<span id="dãy-fibonacci"></span>

### Dãy Fibonacci

Để tính [dãy Fibonacci](../combinatorics/fibonacci.md), các phương pháp thường gặp là truy hồi tuyến tính $O(n)$ và lũy thừa ma trận nhanh $O(\log n)$. Ngoài ra, cũng có thể giải bằng phương pháp mở rộng trường, với độ phức tạp thời gian cũng là $O(\log n)$. Dãy Fibonacci có công thức tổng quát:

$$
f(n) = \frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^n-\left(\frac{1-\sqrt{5}}{2}\right)^n\right).
$$

Bây giờ cần tính giá trị của $f(n)$ modulo số nguyên tố $p\neq 5$[^fib-p5]. Chuyển bài toán này thành phép tính trên trường hữu hạn $\mathbf F_p$, vấn đề đầu tiên cần giải quyết là ý nghĩa của $\sqrt 5$ trong $\mathbf F_p$. Từ góc nhìn đại số, nó chính là căn bậc hai của phần tử $5$. Vì vậy, nếu trong $\mathbf F_p$ tồn tại căn bậc hai của $5$, tức $5$ là thặng dư bậc hai modulo $p$, có thể trực tiếp tính thặng dư bậc hai đó rồi thay vào công thức; ngược lại, cần tính trong trường mở rộng $\mathbf F_p(\sqrt 5)\cong\mathbf F_p[x]/(x^2-5)$.

Khi tính trong trường mở rộng, không nhất thiết phải thêm $\sqrt 5$. Chẳng hạn với dãy Fibonacci, cũng có thể đặt $\phi$ là nghiệm của đa thức $x^2-x-1$, khi đó $f(n)$ có thể viết thành

$$
f(n)=\frac{\phi^n-(-\phi)^{-n}}{2\phi-1}=\frac{\phi^n-(1-\phi)^n}{2\phi-1}.
$$

Nếu $5$ không phải thặng dư bậc hai modulo $p$, đa thức $x^2-x-1$ là bất khả quy. Khi đó có thể tính trên trường mở rộng $\mathbf F_p(\theta)\cong\mathbf F_p[x]/(x^2-x-1)$, và thu được kết quả nhất quán với cách trên.

Phương pháp tính dãy Fibonacci cũng có thể mở rộng sang các tình huống khác. Nhưng cần lưu ý một điểm: tính bất khả quy của đa thức trên trường hữu hạn không giống trên trường số hữu tỉ. Chẳng hạn $x^4-10x^2+1$ bất khả quy trên $\mathbf Q$, trường phân rã tương ứng là $\mathbf Q(\sqrt 2+\sqrt 3)=\mathbf Q(\sqrt 2,\sqrt 3)$; nhưng trong $\mathbf F_p$, nếu cả $2$ và $3$ đều không phải thặng dư bậc hai modulo $p$, thì nó là tích của hai đa thức bất khả quy, tức trong mở rộng $\mathbf F_p(\sqrt 2)$ đã tồn tại căn bậc hai $\sqrt{3}$ và không cần mở rộng thêm.

<span id="mở-rộng-sang-mở-rộng-trên-vành"></span>

### Mở rộng sang "mở rộng" trên vành

Như mục trước đã cho thấy, mở rộng trường có nhiều hạn chế. Với việc tính dãy Fibonacci, nếu chỉ dùng phương pháp mở rộng trường thì chỉ xử lý trực tiếp được trường hợp modulo $p$ là số nguyên tố và $5$ không phải thặng dư bậc hai modulo $p$. Tuy nhiên cần lưu ý rằng thảo luận trong mục [mở rộng đại số](#mở-rộng-đại-số) cho thấy nếu không yêu cầu thực hiện phép chia trong cấu trúc sau khi mở rộng, có thể mở rộng vành[^ring-extension]. Mục này lấy ví dụ tính dãy Fibonacci dưới modulo bất kỳ $n$ để thảo luận ngắn gọn phương pháp này. Các tình huống thường gặp khác không liên quan quá nhiều đến phép chia, bao gồm tính định thức, biến đổi Fourier nhanh, v.v.; khi cần cũng có thể thử áp dụng phương pháp này.

Gọi $m$ là số nguyên dương bất kỳ, $f(n)$ là số hạng thứ $n$ của dãy Fibonacci. Bài toán là tính $f(n)\bmod m$. Về nguyên tắc, cần tính trên $\mathbf Z/m\mathbf Z$. Nhưng như mục trước đã chỉ ra, dưới các modulo khác nhau, tính khả quy và tình huống có nghiệm bội của đa thức $x^2-x-1$ không giống nhau, nên công thức tổng quát của dãy Fibonacci có thể rất khác. Hơn nữa, nếu bản thân $\mathbf Z/m\mathbf Z$ không phải trường, phần tử sau khi mở rộng cũng thường không có nghịch đảo hợp lệ (ví dụ modulo $5$, mẫu số $\sqrt 5$ trực tiếp bằng không). Tuy có nhiều vấn đề như vậy, khi các hệ số được lấy modulo $m$, chỉ cần tính hạng tử hằng của phần dư

$$
(1-x)^n-x^n\mod{x^2-x-1}.
$$

So với công thức tổng quát ở trên, tính hợp lý của cách làm này đến từ việc nó dường như đang tính trong "mở rộng" $(\mathbf Z/m\mathbf Z)[x]/(x^2-x-1)$ giá trị

$$
f(n)=\frac{(1-\phi)^n-\phi^n}{1-2\phi},
$$

trong đó $\phi$ là nghiệm của $x^2-x-1$.

Dù không trực tiếp như vậy, cách làm này vẫn hợp lệ. Trong mở rộng của trường số hữu tỉ $\mathbf Q(\phi)\cong\mathbf Q[x]/(x^2-x-1)$, công thức tổng quát đúng. Điều này cho thấy trong $\mathbf Q[x]$,

$$
(1-x)^n-x^n \equiv f(n)(1-2x) \pmod{x^2-x-1}
$$

đúng. Công thức này chỉ liên quan đến đa thức hệ số nguyên, nên cũng đúng trong $\mathbf Z[x]$. Viết thành phép chia có dư, rồi lấy hệ số hai vế modulo $m$, thu được đẳng thức đồng nhất trên $(\mathbf Z/m\mathbf Z)[x]$. Kết luận này đúng với mọi $m$.

Trong trường hợp tổng quát, nếu một biểu thức có thể được tính trong trường mở rộng của trường số hữu tỉ $\mathbf Q$, thì nhất định có thể khử mẫu để thu được kết luận trên $\mathbf Z[x]$, rồi lấy modulo $m$ để thu được kết luận trên $(\mathbf Z/m\mathbf Z)[x]$. Mấu chốt để tư duy này hoạt động là bước khử mẫu không được gây ra hậu quả "không thể cứu vãn". Chẳng hạn với việc tính dãy Fibonacci, nếu không dùng hệ số của hạng tử hằng mà dùng hệ số của hạng tử bậc nhất, thì do hệ số có nhân tử $2$, khi $m$ chẵn thì $2$ không có nghịch đảo modulo $m$, không có cách khôi phục giá trị $f(n)$. Lại chẳng hạn, cũng trong việc tính dãy Fibonacci, nếu dùng công thức tổng quát có hạng tử $(-\phi)^{-n}$, bước khử mẫu sẽ đưa vào nhân tử khó xử lý, khiến không thể suy ra kết luận từ kết quả sau khi lấy dư. Vì vậy, việc chọn quá trình tính toán là điểm then chốt để áp dụng kỹ thuật này.

<span id="thuật-toán-cipolla"></span>

### Thuật toán Cipolla

Đây là ví dụ điển hình về việc dùng mở rộng của trường hữu hạn để tính toán. Với thặng dư bậc hai $a$ modulo $p\neq 2$, cần tìm căn bậc hai của nó, tức tìm $x$ sao cho $x^2\equiv a\pmod p$. Dù đây là bài toán trên $\mathbf F_p$, [thuật toán Cipolla](../number-theory/quad-residue.md#thuật-toán-cipolla) tính trong trường hữu hạn $\mathbf F_{p^2}$. Mục này dùng ngôn ngữ lý thuyết trường để giải thích thuật toán. Chứng minh số học sơ cấp có thể xem trong liên kết đã cho.

Cụ thể, thuật toán Cipolla trước hết chọn $r$ sao cho $r^2-a$ là bất thặng dư bậc hai modulo $p$. Điều này có nghĩa $x^2-(r^2-a)$ là đa thức bất khả quy. Vì vậy, đặt $u=r^2-a$, có thể xét trường mở rộng $\mathbf F_p(\sqrt u)$. Vì tự đồng cấu Frobenius chỉ có thể ánh xạ một phần tử đến phần tử liên hợp của nó, mà trong mở rộng bậc hai phần tử liên hợp như vậy là duy nhất, nên $(r-\sqrt u)^p=r+\sqrt u$. Do đó $(r-\sqrt u)^{p+1}=(r+\sqrt u)(r-\sqrt u)=r^2-u=a$. Vì vậy để xác định căn bậc hai, chỉ cần tính $(r-\sqrt u)^{(p+1)/2}$. Giá trị này nhất định nằm trong $\mathbf F_p$, vì trường phân rã của $x^2-a$ chính là $\mathbf F_p$.

<span id="bài-tập"></span>

## Bài tập

Cuối cùng, dưới đây là một số bài toán áp dụng trực tiếp nội dung bài này để củng cố hiểu biết. Tuy nhiên cần lưu ý, nhiều nội dung không phải là điểm kiến thức thường gặp trong lập trình thi đấu.

-   Đa thức cyclotomic:
    -   [Luogu P1520 Factorization](https://www.luogu.com.cn/problem/P1520)
    -   [Gym102114C Call It What You Want](https://codeforces.com/gym/102114/problem/C)
-   Trường hữu hạn:
    -   [Luogu P3923 University Math Problem](https://www.luogu.com.cn/problem/P3923)
    -   [\[COTS 2021\] Cai Jelo](https://www.luogu.com.cn/problem/P11192)
    -   [CF1310F. Bad Cryptography](https://codeforces.com/problemset/problem/1310/F)
    -   [LOJ 178. Polynomial Root Finding](https://loj.ac/p/178)
-   Mở rộng trường:
    -   [\[Oleksandr Kulkov Contest 2\] Problem A. Square Root Partitioning](https://codeforces.com/gym/102354/problem/A)
    -   [CF1103E. Radix Sum](https://codeforces.com/problemset/problem/1103/E)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>

## Tài liệu tham khảo và chú thích

-   Dummitt, D.S. và Foote, R.M. (2004) Đại số trừu tượng. Ấn bản thứ 3, John Wiley & Sons, Inc.
-   [Milne, J.S. Trường và lý thuyết Galois.](https://www.jmilne.org/math/CourseNotes/FT.pdf)
-   [Phân tích đa thức thành nhân tử - Wikipedia](https://en.wikipedia.org/wiki/Factorization_of_polynomials)
-   [Phân tích đa thức trên trường hữu hạn thành nhân tử - Wikipedia](https://en.wikipedia.org/wiki/Factorization_of_polynomials_over_finite_fields)
-   [Đa thức cyclotomic - Wikipedia](https://en.wikipedia.org/wiki/Cyclotomic_polynomial)
-   [Ghi chú của Brett Porter về đa thức cyclotomic](https://www.whitman.edu/documents/academics/majors/mathematics/2015/Final%20Project%20-%20Porter%2C%20Brett.pdf)
-   [Ghi chú của Jordan Bell về đa thức cyclotomic](https://jordanbell.info/LaTeX/mathematics/cyclotomic/cyclotomic.pdf)
-   [Michel Waldschmidt. Nhập môn lý thuyết trường hữu hạn](https://webusers.imj-prg.fr/~michel.waldschmidt/articles/pdf/FiniteFields.pdf)
-   [Số học trường hữu hạn - Wikipedia](https://en.wikipedia.org/wiki/Finite_field_arithmetic)

[^subfield-one]: Điều này là vì phần tử một $1_E$ của trường $E$ nhất định thỏa mãn quan hệ $x^2-x=0$ trên $F$, mà quan hệ này trong trường $F$ chỉ có hai nghiệm $0_F$ và $1_F$. Do định nghĩa trường yêu cầu $1_E\neq 0_E$, nhất định có $1_E=1_F$ và $0_E=0_F$.

[^initial-object-ring]: Nói bằng ngôn ngữ phạm trù, $\mathbf Z$ là [đối tượng khởi đầu](https://en.wikipedia.org/wiki/Initial_and_terminal_objects) của phạm trù vành có đơn vị.

[^polynomial-universal]: Nói nghiêm ngặt, trong ngữ cảnh này chỉ [tính chất phổ dụng](https://en.wikipedia.org/wiki/Polynomial_ring#Polynomial_evaluation) (universal property) của vành đa thức $R[x]$.

[^multi-poly-ring]: Vành đa thức trong phần này có vô hạn biến không xác định. Để định nghĩa vành đa thức như vậy, trước hết cần định nghĩa đơn thức. Giả sử tập biến không xác định là $X$, khi đó đơn thức trên nó là toàn bộ các hàm $\alpha:X\rightarrow\mathbf N$ chỉ nhận giá trị khác không tại hữu hạn nhiều biến, có thể ký hiệu là $x_{i_1}^{\alpha(i_i)}\cdots x_{i_k}^{\alpha(i_k)}$, trong đó $i_1,\cdots,i_k$ là các chỉ số của mọi biến mà $\alpha$ nhận giá trị khác không. Đa thức là tổ hợp tuyến tính của hữu hạn nhiều đơn thức. Chúng tạo thành vành dưới phép cộng và phép nhân được định nghĩa tương ứng. Với trường hợp hữu hạn biến không xác định, có thể chứng minh định nghĩa này nhất quán với kết quả thu được từ định nghĩa đệ quy trong mục [vành đa thức nhiều biến](./ring-theory.md#vành-đa-thức-nhiều-biến).

[^fundamental-algebra]: Dù tên là định lý cơ bản của đại số, kết luận này không thuần đại số, vì việc xây dựng trường số thực cần thông qua cấu trúc tô pô.

[^ddf]: Cách nói này chưa thật chặt chẽ, vì còn có thể thu được các nhân tử bất khả quy có bậc $d\mid n$. Nhưng khi cài đặt thuật toán, thường tách nhân tử theo bậc nhỏ trước; khi tách nhân tử bất khả quy bậc $n$, các nhân tử bậc nhỏ hơn đáng lẽ đã được tách xong, nên cách nói này vẫn chấp nhận được.

[^prim-poly]: Không nên nhầm tên gọi trong phần này với đa thức nguyên thủy trong lý thuyết đa thức, tức đa thức có ước chung lớn nhất của mọi hệ số bằng một.

[^list-prim-poly]: Chẳng hạn, phụ lục của [Hansen, T., & Mullen, G. L. (1992). Primitive polynomials over finite fields. Mathematics of computation, 59(200), 639-643](https://www.ams.org/journals/mcom/1992-59-200/S0025-5718-1992-1134730-7/S0025-5718-1992-1134730-7.pdf) cung cấp danh sách như vậy.

[^fib-p5]: Khi $p=5$, phương trình đặc trưng $x^2-x-1=0$ của dãy Fibonacci có nghiệm kép $x=3$, nên trong $\mathbf F_5$, công thức tổng quát của dãy Fibonacci là $f(n)=n3^{n-1}$.

[^ring-extension]: "Mở rộng trên vành" thường có hai nghĩa: một là [khái quát của mở rộng nhóm](https://en.wikipedia.org/wiki/Algebra_extension), hai là [khái quát của mở rộng trường](https://en.wikipedia.org/wiki/Subring#Ring_extensions). Bài này dùng nghĩa thứ hai. Cụ thể hơn, các mở rộng liên quan trong mục này đều là [mở rộng nguyên](https://en.wikipedia.org/wiki/Integral_element#Integral_extensions) trên vành giao hoán có đơn vị, là khái quát của khái niệm mở rộng đại số trên trường sang vành giao hoán có đơn vị.
