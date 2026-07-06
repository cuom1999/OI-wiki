<span id="ma-trận-sơ-cấp"></span>
## Ma trận sơ cấp

Ba loại ma trận vuông sau được gọi là ma trận sơ cấp.

<span id="ma-trận-nhân-bội"></span>
### Ma trận nhân bội

Ma trận nhân bội là một dạng đặc biệt của ma trận đường chéo.

$$
D_i(k)=\operatorname{diag}\{1,\cdots,1,k,1,\cdots,1\}
$$

Biểu thức này biểu thị một ma trận đường chéo, trong đó phần tử thứ $i$ trên đường chéo chính là $k$; quy ước $k$ không được bằng $0$, còn mọi phần tử khác đều là $1$.

Đặc biệt, khi $k$ bằng $1$, $D_i(1)$ chính là ma trận đơn vị $I$.

<span id="ma-trận-hoán-đổi"></span>
### Ma trận hoán đổi

Ma trận hoán đổi là một dạng đặc biệt của ma trận đối xứng.

$$
P_{ij}=\begin{pmatrix}
I_{i-1} &  &  &  & \\
 & 0 &  & 1 & \\
 &  & I_{j-i-1} &  & \\
 & 1 &  & 0 & \\
 &  &  &  & I_{n-j}\\
\end{pmatrix}
$$

Các phần tử của ma trận hoán đổi đều là $1$ và $0$. Những phần tử còn lại trên đường chéo chính đều là $1$, chỉ phần tử thứ $i$ và thứ $j$ là $0$, còn hai phần tử ở hàng $i$ cột $j$ và hàng $j$ cột $i$ là $1$.

Ma trận hoán đổi yêu cầu $i$ và $j$ khác nhau.

<span id="ma-trận-cộng-bội"></span>
### Ma trận cộng bội

Ma trận cộng bội được tạo từ ma trận đơn vị $I$ bằng cách đặt phần tử ở hàng $i$ cột $j$ bằng $k$.

$$
T_{ij}(k)=\begin{pmatrix}
1 &  &  &  &  &  & \\
 & \ddots &  &  &  &  & \\
 &  & 1 & \cdots & k &  & \\
 &  &  & \ddots & \vdots &  & \\
 &  &  &  & 1 &  & \\
 &  &  &  &  & \ddots & \\
 &  &  &  &  &  & 1\\
\end{pmatrix}
$$

Ma trận cộng bội yêu cầu $i$ và $j$ khác nhau. Nếu $k$ bằng $0$, thì $T_{ij}(0)$ suy biến thành ma trận đơn vị $I$.

Ma trận cộng bội là một ma trận tam giác trên hoặc tam giác dưới.

<span id="định-thức-của-ma-trận-sơ-cấp"></span>
### Định thức của ma trận sơ cấp

Ba loại ma trận sơ cấp có định thức:

$$
|D_i(k)|=k
$$

$$
|P_{ij}|=-1
$$

$$
|T_{ij}(k)|=1
$$

Vì định thức của tích các ma trận vuông bằng tích các định thức, nhờ tính tương đương giữa biến đổi sơ cấp và phép nhân ma trận ở phần dưới, tính chất này của ma trận sơ cấp có thể dùng để tính định thức.

<span id="biến-đổi-sơ-cấp"></span>
## Biến đổi sơ cấp

Không chỉ với ma trận vuông, với ma trận tổng quát $A$ cũng có thể thực hiện biến đổi sơ cấp trên hàng và biến đổi sơ cấp trên cột; gọi chung là biến đổi sơ cấp.

Biến đổi sơ cấp trên hàng và trên cột đều có 3 loại: nhân bội (multiplication), hoán đổi (switching), cộng bội (addition). Trước hết giới thiệu biến đổi sơ cấp trên hàng:

-   Nhân hàng thứ $i$ với số khác không $k$: $B\mapsto D_i(k)B$.
-   Hoán đổi hàng thứ $i$ và hàng thứ $j$: $B\mapsto P_{ij}B$.
-   Nhân hàng thứ $j$ với $k$ rồi cộng vào hàng thứ $i$: $B\mapsto T_{ij}(k)B$.

Thay "hàng" trong các thao tác trên bằng "cột" thì thu được các biến đổi sơ cấp trên cột.

Trong các biến đổi sơ cấp, phép hoán đổi có thể được thực hiện bằng phép nhân bội và cộng bội. Phép cộng bội không thể được thực hiện bằng phép nhân bội và hoán đổi. Nhờ kiến thức về định thức, cùng với tính tương đương giữa biến đổi sơ cấp và phép nhân ma trận ở phần dưới, cũng có thể giải thích rằng phép nhân bội không thể được thực hiện bằng phép cộng bội và hoán đổi.

Vì vậy, so với phép hoán đổi, phép nhân bội và cộng bội là các thao tác bản chất hơn. Phép hoán đổi được đưa vào như một thao tác phụ trợ để bảo đảm thứ tự khử trong phương pháp khử.

<span id="biến-đổi-sơ-cấp-và-phép-nhân-ma-trận"></span>
## Biến đổi sơ cấp và phép nhân ma trận

Ba loại ma trận sơ cấp đều là kết quả của việc thực hiện đúng một biến đổi tương ứng trên ma trận đơn vị $I$. Trong phần biến đổi tuyến tính về sau sẽ chỉ ra rằng biến đổi tuyến tính và ma trận có quan hệ tương ứng, tương tự quan hệ này.

Bất kể ma trận $A$ có vuông hay không, thực hiện biến đổi sơ cấp trên hàng của $A$ tương đương với nhân trái $A$ bởi một ma trận sơ cấp. Thực hiện biến đổi sơ cấp trên cột của $A$ tương đương với nhân phải $A$ bởi một ma trận sơ cấp.

<span id="thao-tác-nhân-bội"></span>
### Thao tác nhân bội

Nhân trái với một ma trận nhân bội $D_i(k)$ tương đương với biến hàng thứ $i$ thành $k$ lần chính nó. Nhân phải với một ma trận nhân bội $D_i(k)$ tương đương với biến cột thứ $i$ thành $k$ lần chính nó.

Tích của hai ma trận đường chéo vẫn là ma trận đường chéo; khi nhân các ma trận đường chéo, các phần tử tương ứng trên đường chéo chính được nhân với nhau. Vì ma trận đơn vị là một ma trận nhân bội đặc biệt, còn ma trận nhân bội yêu cầu $k$ khác $0$, chỉ cần mọi phần tử trên đường chéo chính của ma trận đường chéo đều khác $0$, nó có thể được phân tích thành tích của các ma trận nhân bội.

Với ma trận đường chéo tổng quát, bất kể các phần tử có bằng $0$ hay không, cũng có kết luận tương ứng. Nhân trái với ma trận đường chéo tương đương với nhân các hàng tương ứng lên một số lần, hệ số đúng bằng phần tử tương ứng trên đường chéo chính của ma trận đường chéo. Nhân phải với ma trận đường chéo là thao tác tương tự trên các cột tương ứng.

Vì định thức của ma trận nhân bội $D_i(k)$ là $k$, sau khi thực hiện thao tác nhân bội trên một hàng hoặc một cột của ma trận vuông, định thức tương ứng của ma trận vuông trở thành $k$ lần ban đầu. Định thức của ma trận đường chéo bằng tích các phần tử trên đường chéo chính.

Phép nhân các ma trận nhân bội có tính giao hoán, và phép nhân các ma trận đường chéo cũng có tính giao hoán; khi phép nhân chỉ gồm các ma trận đường chéo, thứ tự có thể sắp xếp tùy ý.

Thao tác nhân bội tương ứng với ma trận đơn vị là giữ nguyên ma trận $A$; trong ứng dụng thực tế không thực hiện thao tác như vậy.

<span id="thao-tác-hoán-đổi"></span>
### Thao tác hoán đổi

Nhân trái với một ma trận hoán đổi $P_{ij}$ tương đương với hoán đổi hàng thứ $i$ và hàng thứ $j$. Nhân phải với một ma trận hoán đổi $P_{ij}$ tương đương với hoán đổi cột thứ $i$ và cột thứ $j$.

Tương tự quan hệ giữa ma trận nhân bội và ma trận đường chéo, phần này đưa vào khái niệm ma trận hoán vị. Ma trận hoán vị là một ma trận vuông, trong đó mỗi hàng và mỗi cột đều có đúng một phần tử $1$, các vị trí còn lại đều là $0$. Ma trận đơn vị $I$ cũng là một ma trận hoán vị đặc biệt.

Ma trận hoán vị trùng với kết quả của việc hoán vị các hàng của ma trận đơn vị $I$, và cũng trùng với kết quả của việc hoán vị các cột của ma trận đơn vị $I$. Bản thân ma trận đơn vị $I$ tương ứng với biến đổi đồng nhất.

Nhân trái với một ma trận hoán vị tương đương với hoán vị các hàng của ma trận gốc; nhân phải với một ma trận hoán vị tương đương với hoán vị các cột của ma trận gốc. Cách hoán vị tương ứng giống với thao tác hoán vị hàng hoặc cột trên ma trận đơn vị $I$.

Ma trận hoán vị và hoán vị tương ứng hoàn toàn với nhau; nhóm nhân do các ma trận hoán vị tạo thành đẳng cấu với nhóm hoán vị. Vì có định lý rằng, nếu xem biến đổi đồng nhất là tích của không phép hoán đổi, thì mọi hoán vị đều có thể phân tích thành tích các phép hoán đổi; do đó mọi ma trận hoán vị cũng có thể phân tích thành tích các ma trận hoán đổi.

Vì định thức của ma trận hoán đổi là $-1$, sau khi thực hiện thao tác hoán đổi trên một hàng hoặc một cột của ma trận vuông, định thức tương ứng của ma trận vuông trở thành $-1$ lần ban đầu.

Phép nhân các ma trận hoán đổi không có tính giao hoán, và phép nhân các ma trận hoán vị cũng không có tính giao hoán.

Định thức của ma trận hoán vị là ${(-1)}^p$, trong đó $p$ là số nghịch thế của hoán vị tương ứng với ma trận hoán vị, tức số phép hoán đổi trong một phân tích của hoán vị đó thành tích các phép hoán đổi.

<span id="thao-tác-cộng-bội"></span>
### Thao tác cộng bội

Nhân trái với ma trận cộng bội $T_{ij}(k)$ tương đương với cộng $k$ lần hàng thứ $j$ vào hàng thứ $i$. Nhân phải với ma trận cộng bội $T_{ij}(k)$ tương đương với cộng $k$ lần cột thứ $i$ vào cột thứ $j$.

Nếu khó nhớ, có thể quan sát ma trận cộng bội $T_{ij}(k)$ được tạo ra từ ma trận đơn vị $I$ bằng thao tác nào. Hai thao tác này tương ứng với nhau: nhân trái là thao tác trên hàng, nhân phải là thao tác trên cột, phù hợp với khẩu quyết "trái hàng, phải cột".

Vì định thức của ma trận cộng bội là $1$, sau khi thực hiện thao tác cộng bội trên ma trận vuông, định thức tương ứng của ma trận vuông không đổi.

Phép nhân các ma trận cộng bội không có tính giao hoán.

Thao tác cộng bội tương ứng với ma trận đơn vị là giữ nguyên ma trận $A$; trong ứng dụng thực tế không thực hiện thao tác như vậy.

<span id="ma-trận-tam-giác-trên"></span>
#### Ma trận tam giác trên

Ma trận cộng bội là một ma trận tam giác trên hoặc tam giác dưới. Vì hai loại ma trận này đối xứng qua đường chéo chính, phần này chỉ xét ma trận tam giác trên. Trong ví dụ này chỉ cần biến đổi sơ cấp trên hàng, không cần biến đổi trên cột.

Nếu mọi phần tử trên đường chéo chính của một ma trận tam giác trên đều là $1$, thì nó có thể được phân tích thành tích của một dãy ma trận cộng bội. Thứ tự phân tích là: trước hết thực hiện các thao tác cộng bội trên hàng thứ nhất của ma trận đơn vị $I$, rồi trên hàng thứ hai, cứ như vậy cho đến khi mọi hàng đều đã được xử lý.

Vì phép nhân ma trận cộng bội không có tính giao hoán, các thao tác trên không thể đổi thứ tự.

Nếu mọi phần tử trên đường chéo chính của một ma trận tam giác trên đều khác $0$, thì nó có thể được phân tích thành tích của một dãy ma trận cộng bội và ma trận nhân bội. Khi xử lý từng hàng của ma trận đơn vị $I$, có thể trước hết thực hiện thao tác nhân bội trên hàng đó, để phần tử đường chéo chính trở thành giá trị khác không đã chỉ định.

Nếu đường chéo chính của một ma trận tam giác trên có phần tử $0$, thì nó không thể được phân tích thành tích của một dãy ma trận sơ cấp.

Bất kể đường chéo chính của ma trận tam giác trên có phần tử $0$ hay không, định thức của ma trận tam giác trên đều bằng tích các phần tử trên đường chéo chính, giống như ma trận đường chéo.

<span id="dùng-thao-tác-cộng-bội-để-đưa-ma-trận-vuông-về-ma-trận-đường-chéo"></span>
#### Dùng thao tác cộng bội để đưa ma trận vuông về ma trận đường chéo

Chỉ dùng thao tác cộng bội cũng có thể đưa một ma trận vuông bất kỳ về ma trận đường chéo. Ví dụ này cần cả biến đổi sơ cấp trên hàng lẫn trên cột.

Nếu hàng thứ nhất và cột thứ nhất của ma trận vuông có phần tử khác không, có thể dùng phép cộng bội để làm cho phần tử góc trên bên trái khác không; sau đó dùng biến đổi sơ cấp trên hàng và trên cột để biến mọi phần tử ở hàng thứ nhất và cột thứ nhất, trừ phần tử góc trên bên trái, thành $0$.

Nếu hàng thứ nhất và cột thứ nhất đều đã toàn là $0$, thì xét trực tiếp hàng thứ hai và cột thứ hai.

Nhờ cách này, thậm chí có thể quy định rằng các phần tử khác không của ma trận đường chéo đều nằm ở góc trên bên trái.

Nếu hàng thứ nhất và cột thứ nhất đều đã toàn là $0$, xét phần hàng và cột còn lại có phần tử khác không hay không. Chỉ cần còn phần tử khác không, có thể dùng thao tác cộng bội để làm cho một phần tử nào đó ở hàng thứ nhất hoặc cột thứ nhất trở thành khác $0$, rồi quy về trường hợp ban đầu để phần tử góc trên bên trái khác $0$.

Chỉ khi phần hàng và cột còn lại cũng đều không có phần tử khác không thì góc trên bên trái mới không thể trở thành phần tử khác không; khi đó ma trận vuông còn lại đã là ma trận không.

<span id="ma-trận-dạng-chuẩn"></span>
#### Ma trận dạng chuẩn

Nhờ biến đổi sơ cấp, có thể đưa một ma trận bất kỳ, bất kể hình dạng, về ma trận dạng chuẩn.

Ma trận dạng chuẩn có một ma trận đơn vị $I$ làm ma trận con ở góc trên bên trái, còn các phần khác đều là $0$. Cách đưa về tương tự thao tác đưa ma trận vuông về ma trận đường chéo, đồng thời cần dùng thao tác nhân bội để biến các phần tử khác không ở góc trên bên trái thành $1$.

Sau khi ma trận được đưa về dạng chuẩn, số phần tử bằng $1$ đúng bằng hạng của ma trận.

<span id="ma-trận-khả-nghịch"></span>
## Ma trận khả nghịch

Giả sử $A$ là một ma trận bậc $n$. Nếu tồn tại một ma trận bậc $n$ $B$ sao cho $AB=BA=I$, thì $A$ được gọi là ma trận khả nghịch hoặc ma trận không suy biến, $B$ được gọi là ma trận nghịch đảo của $A$, ký hiệu là $A^{-1}$.

Nếu ma trận $A$ khả nghịch, thì ma trận nghịch đảo của $A$ được xác định duy nhất bởi $A$.

Nghịch đảo $A^{-1}$ của ma trận khả nghịch $A$ cũng khả nghịch, và nghịch đảo của $A^{-1}$ chính là $A$.

Tích $AB$ của hai ma trận khả nghịch $A$ và $B$ cũng khả nghịch, và nghịch đảo của nó là $B^{-1}A^{-1}$.

Ma trận chuyển vị $A^T$ của ma trận khả nghịch $A$ cũng khả nghịch, và nghịch đảo của chuyển vị bằng chuyển vị của nghịch đảo.

<span id="nghịch-đảo-của-ma-trận-sơ-cấp"></span>
### Nghịch đảo của ma trận sơ cấp

Mọi ma trận sơ cấp đều khả nghịch, và nghịch đảo của chúng vẫn là ma trận sơ cấp cùng loại:

$$
{D_i(k)}^{-1}=D_i\left(\frac{1}{k}\right)
$$

$$
P_{ij}^{-1}=P_{ij}
$$

$$
T_{ij}(k)^{-1}=T_{ij}(-k)
$$

Ma trận đơn vị $I$ khả nghịch, và nghịch đảo của nó vẫn là $I$.

Biến đổi sơ cấp bảo toàn tính khả nghịch của ma trận: trước và sau biến đổi, ma trận hoặc đồng thời khả nghịch, hoặc đồng thời không khả nghịch.

Ma trận $A$ khả nghịch khi và chỉ khi $A$ có thể viết thành tích của các ma trận sơ cấp, tức có thể biến thành ma trận đơn vị $I$ bằng các biến đổi sơ cấp.

Sau khi đưa vào định thức, sẽ có:

Ma trận $A$ khả nghịch khi và chỉ khi hạng của $A$ là $n$, khi và chỉ khi định thức của $A$ khác $0$.

Một cách ghi nhớ đơn giản là: ký hiệu $E_{ij}$ là ma trận $n\times n$ có phần tử ở hàng $i$ cột $j$ bằng $1$, còn các phần tử khác bằng không, khi đó

-   $D_i(k)=I_n+(k-1)E_{ii}$
-   $P_{ij}=I_n-E_{ii}-E_{jj}+E_{ij}+E_{ji}$
-   $T_{ij}(k)=I_n+kE_{ij}$

Cách ký hiệu này cũng có thể áp dụng cho các ma trận nghịch đảo của chúng.

<span id="ứng-dụng"></span>
## Ứng dụng

<span id="giải-hệ-phương-trình-tuyến-tính"></span>
### Giải hệ phương trình tuyến tính

Với một hệ phương trình tuyến tính, các hệ số đứng trước ẩn tạo thành ma trận hệ số; nếu ghép thêm cột hằng số của hệ phương trình vào bên phải ma trận hệ số, thu được ma trận bổ sung.

Dùng biến đổi sơ cấp trên hàng, có thể đưa ma trận bổ sung tương ứng với hệ phương trình tuyến tính trước hết về ma trận bậc thang hàng, rồi về ma trận hàng rút gọn, từ đó hoàn thành việc giải hệ phương trình tuyến tính. Phương pháp này gọi là khử để giải hệ phương trình tuyến tính; thuật toán khử Gauss-Jordan ở phần sau là thuật toán khử theo một thứ tự nhất định.

<span id="tính-định-thức"></span>
### Tính định thức

Vì định thức của tích các ma trận vuông bằng tích các định thức của chúng, định thức của ma trận sơ cấp dễ tính, và biến đổi sơ cấp tương đương với phép nhân ma trận sơ cấp, nên trong tính định thức cũng thường dùng biến đổi sơ cấp.

Do thực hiện biến đổi sơ cấp theo một thứ tự nhất định thuận tiện hơn cho việc viết chương trình, tính định thức cũng có thể dùng thuật toán khử Gauss-Jordan ở phần sau.
