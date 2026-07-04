Phần này giới thiệu các kiến thức cơ bản của lý thuyết tính toán. Nội dung này không có vai trò lớn trong OI (nhưng vẫn có một chút tác dụng: nếu gặp một bài toán NP-hard, bạn có thể xem như nó không có lời giải với độ phức tạp đa thức), có thể đọc để mở rộng hiểu biết hoặc chuẩn bị cho việc học sau này.

Nhiều kết luận trong bài này được nêu mà không chứng minh. Nếu quan tâm, bạn có thể tự tra cứu các chứng minh liên quan.

Kiến thức cần có: [Độ phức tạp thời gian](../basic/complexity.md).

## Bài toán

### Ngôn ngữ

Một **bảng chữ cái (alphabet)** là một tập hữu hạn không rỗng. Các phần tử trong tập này được gọi là **ký hiệu/ký tự (symbol)**.

Ký hiệu $\Sigma^\ast$ là tập các xâu tạo thành bằng cách nối một số không âm ký tự trong $\Sigma$. Một **ngôn ngữ (language)** trên bảng chữ cái $\Sigma$ là một tập con của $\Sigma^\ast$.

Cần chú ý rằng "ngôn ngữ" ở đây là một khái niệm trừu tượng. Xâu theo nghĩa thông thường là ngôn ngữ, và toàn bộ các đồ thị có hướng không chu trình cũng có thể là một ngôn ngữ (có thể thiết lập song ánh giữa xâu 01 và đồ thị có hướng; không cần biết cách làm cụ thể).

Vì mọi ngôn ngữ đều có thể được chuyển thành dạng xâu 01, nên trong phần dưới, nếu không nói thêm thì $\Sigma=\{0, 1\}$.

### Bài toán quyết định

Bài toán quyết định là bài toán chỉ có thể trả lời bằng YES/NO. Về bản chất, đó là việc quyết định một xâu có thuộc một ngôn ngữ hay không, tức là: $f:\Sigma^\ast\rightarrow\{0, 1\}, f(x)=1\iff x\in L$ là một bài toán quyết định liên quan đến bảng chữ cái $\Sigma$ và ngôn ngữ $L$. Chẳng hạn, "quyết định một đồ thị có phải là đồ thị có hướng không chu trình hay không" là một bài toán quyết định.

Do tính đơn giản, bài toán quyết định thường được dùng làm đối tượng nghiên cứu trong lý thuyết tính toán. Trong bài này, nếu không nói thêm, "bài toán" đều chỉ "bài toán quyết định". Dĩ nhiên, đôi khi một số mệnh đề cũng có thể được mở rộng đơn giản sang các loại bài toán khác.

Một ngôn ngữ cũng có thể được dùng để chỉ bài toán quyết định "một xâu có thuộc ngôn ngữ này hay không", vì vậy "ngôn ngữ" và "bài toán" có thể được xem là đồng nghĩa.

### Bài toán hàm

Câu trả lời của bài toán hàm không chỉ là YES/NO, mà có thể là một số hoặc dạng khác. Chẳng hạn, "tính tổng của hai số" là một bài toán hàm.

Mọi bài toán hàm đều có thể chuyển thành một bài toán quyết định. Chẳng hạn, "tính tổng của hai số" có thể chuyển thành "quyết định tổng của hai số có bằng số thứ ba hay không".

Bài toán quyết định cũng có thể chuyển thành một bài toán hàm: tính hàm chỉ thị của bài toán quyết định đó, tức là $f$ trong định nghĩa bài toán quyết định ở trên.

## Máy Turing

### Máy Turing tất định

Nếu không nói thêm, "máy Turing" thường chỉ "máy Turing tất định"; trong bài này cũng vậy.

Máy Turing có nhiều định nghĩa khác nhau. Ở đây chọn một trong số đó; máy Turing theo các định nghĩa khác thường có năng lực tính toán tương đương với máy Turing theo định nghĩa dưới đây.

Máy Turing là một máy thao tác trên một băng giấy có thể kéo dài vô hạn theo hai chiều và được chia thành các ô. Máy có trạng thái bên trong, cùng một đầu đọc/ghi có thể sửa nội dung và di chuyển trên băng.

Nói chính thức, máy Turing là một bộ bảy $M=\langle Q,\Gamma,b,\Sigma,\delta,q_0,F\rangle$, trong đó:

-   $Q$ là một **tập trạng thái** hữu hạn không rỗng;
-   $\Gamma$ là một **bảng chữ cái băng** hữu hạn không rỗng;
-   $b\in\Gamma$ là **ký tự trắng**, là ký tự duy nhất có thể xuất hiện vô hạn lần trên băng trong quá trình tính toán;
-   $\Sigma\subseteq(\Gamma\setminus\{b\})$ là **tập ký hiệu đầu vào**, gồm các ký tự có thể xuất hiện trên băng ban đầu (tức đầu vào);
-   $q_0\in Q$ là **trạng thái ban đầu**;
-   $F\subseteq Q$ là **tập trạng thái chấp nhận**. Nếu một máy Turing dừng tại một trạng thái chấp nhận, ta nói nội dung trên băng ban đầu được máy Turing này **chấp nhận**.
-   $\delta :(Q\setminus F)\times \Gamma \not \to Q\times \Gamma \times \{L,R\}$ là một hàm riêng phần (partial function) được gọi là **hàm chuyển** (tức là hàm chỉ được định nghĩa trên một tập con của miền xác định). Nếu $\delta$ không được định nghĩa trong trạng thái hiện tại, máy Turing sẽ dừng.

Máy Turing bắt đầu từ trạng thái ban đầu và vị trí đầu băng. Ở mỗi bước, nó thao tác dựa trên trạng thái bên trong hiện tại $x$ và ký tự $y$ trong ô băng mà đầu đọc/ghi đang trỏ tới: nếu $\delta(x, y)$ không được định nghĩa thì dừng; ngược lại, nếu $\delta(x, y)=(a, b, c)$, nó đổi trạng thái bên trong thành $a$, đổi ký tự trong ô đang trỏ tới thành $b$, rồi nếu $c$ là $L$ thì di chuyển sang trái một ô, nếu là $R$ thì di chuyển sang phải một ô.

Thực ra, không cần nắm mọi chi tiết hoạt động của máy Turing; chỉ cần xây dựng trực giác là đủ.

Đầu ra của máy Turing $M$ trên đầu vào $x$ được ký hiệu là $M(x)$ ($M(x)=1$ khi và chỉ khi $M$ chấp nhận $x$; $M(x)=0$ khi và chỉ khi $M$ dừng trong hữu hạn bước trên đầu vào $x$ và $M$ không chấp nhận $x$). Trong ngoặc cũng có thể chứa nhiều tham số, phân tách bằng dấu phẩy; khi hiện thực cụ thể, có thể thêm một phần tử vào bảng chữ cái để biểu diễn dấu phẩy và phân tách các tham số.

Độ phức tạp thời gian khi máy Turing giải bài toán chỉ khác máy tính von Neumann trong phạm vi đa thức, nên khi nghiên cứu lớp độ phức tạp, ta có thể dùng máy Turing làm mô hình tính toán.

### Máy Turing không tất định

Máy Turing không tất định là một loại máy Turing. Điểm khác với máy Turing tất định là: ở mỗi bước, máy Turing tất định chỉ có thể chuyển sang một trạng thái, còn máy Turing không tất định có thể "đồng thời" chuyển sang nhiều trạng thái, từ đó tính toán song song trên nhiều "nhánh"; chỉ cần một trong các "nhánh" này dừng tại trạng thái chấp nhận thì máy Turing không tất định đó chấp nhận đầu vào.

Trên thực tế, mọi máy Turing tất định đều có thể mô phỏng hành vi trong thời gian đa thức của một máy Turing không tất định bằng cách tương tự tìm kiếm sâu lặp, với thời gian cấp số mũ.

Trong đời sống thực, máy Turing tất định tương ứng với bộ xử lý đơn nhân, chỉ hỗ trợ xử lý tuần tự; còn máy Turing không tất định tương ứng với bộ xử lý đa nhân lý tưởng, hỗ trợ xử lý song song với quy mô vô hạn.

### Máy Turing nhiều băng

Máy Turing chuẩn chỉ có thể thao tác trên một băng giấy, nhưng để tiện, trong bài này ta nghiên cứu máy Turing nhiều băng. Với một máy Turing $k$ băng, một băng là băng đầu vào chỉ đọc, còn $k-1$ băng còn lại có thể đọc ghi, và trong $k-1$ băng này còn có một băng dùng làm đầu ra.

Số băng của máy Turing nhiều băng phải là hữu hạn.

Với một máy Turing nhiều băng, không gian mà nó sử dụng là số ô mà đầu đọc/ghi đã truy cập trên các băng khác ngoài băng đầu vào.

### Mã hóa máy Turing

Máy Turing có thể được mã hóa bằng số tự nhiên, tức là tồn tại một toàn ánh $f:\mathbb{N}\to\mathbb{M}$ sao cho mỗi số tự nhiên đều tương ứng với một máy Turing, và mỗi máy Turing có vô số mã hóa. Vì vậy, một tập gồm các máy Turing có thể là một ngôn ngữ.

Ký hiệu máy Turing được mã hóa bởi số tự nhiên $\alpha$ là $M_{\alpha}$.

### Máy Turing phổ dụng

Tồn tại một máy Turing $\mathcal U$ thỏa mãn:

1.  Nếu $M_{\alpha}$ dừng trong thời gian hữu hạn trên đầu vào $x$, thì $\mathcal{U}(x, \alpha)=M_{\alpha}(x)$; nếu không, $\mathcal{U}(x, \alpha)$ sẽ không dừng trong thời gian hữu hạn;
2.  Nếu với mọi $x\in\{0, 1\}^\ast$, $M_\alpha$ dừng trong thời gian $T(|x|)$ trên đầu vào $x$, thì với mọi $x\in\{0, 1\}^\ast$, $\mathcal{U}(x, \alpha)$ dừng trong thời gian $O(T(|x|)\log T(|x|))$.

Tức là: tồn tại một máy Turing phổ dụng có thể mô phỏng bất kỳ máy Turing nào, và thời gian tiêu tốn chỉ chậm hơn máy được mô phỏng một thừa số logarit theo thời gian chạy của máy đó.

## Tính khả tính

### Bài toán không tính được

Với một bài toán quyết định, nếu tồn tại một máy Turing luôn dừng trong hữu hạn bước và có thể quyết định đúng, thì bài toán đó là một bài toán **tính được theo Turing**; nếu không, bài toán đó là một bài toán **không tính được theo Turing**.

Vì máy Turing có thể được mã hóa bằng số tự nhiên, nên số lượng máy Turing là vô hạn đếm được, còn số lượng ngôn ngữ (tức các tập xâu nhị phân) là vô hạn không đếm được. Mỗi máy Turing nhiều nhất quyết định một ngôn ngữ, vì vậy chắc chắn tồn tại bài toán không tính được theo Turing.

### Bài toán dừng

Bài toán dừng là một bài toán không tính được theo Turing kinh điển: cho $\alpha$ và $x$, quyết định $M_{\alpha}$ có dừng trong hữu hạn bước khi đầu vào là $x$ hay không.

??? note "Chứng minh bài toán dừng là không tính được theo Turing"
    Định nghĩa hàm $\mathsf{UC}:\{0,1\}^\ast\to\{0,1\}$ như sau:
    
    $$
    \mathsf{UC}(\alpha)=\begin{cases}0&M_\alpha(\alpha)=1\\1&\text{otherwise}\end{cases}
    $$
    
    Trước hết, ta chứng minh hàm $\mathsf{UC}$ là không tính được theo Turing:
    
    Giả sử tồn tại một máy Turing $M_{\beta}$ có thể tính $\mathsf{UC}$. Khi đó, theo định nghĩa của $\mathsf{UC}$, ta có $\mathsf{UC}(\beta)=1\iff M_\beta(\beta)\neq 1$, còn theo việc $M_{\beta}$ có thể tính $\mathsf{UC}$, ta có $M_{\beta}(\beta)=\mathsf{UC}(\beta)$. Điều này tạo ra mâu thuẫn, nên giả thiết không đúng, và không tồn tại máy Turing nào có thể tính $\mathsf{UC}$.
    
    Giả sử $M_{\mathsf{HALT}}$ là một máy Turing có thể giải bài toán dừng, và giá trị của $M_{\mathsf{HALT}}(x,\alpha)$ là đáp án của bài toán quyết định liệu $M_\alpha$ có dừng trong hữu hạn bước khi đầu vào là $x$ hay không. Khi đó ta có thể xây dựng một máy Turing $M_{\mathsf{UC}}$ có thể tính hàm $\mathsf{UC}$:
    
    $M_\mathsf{UC}$ trước hết gọi $M_\mathsf{HALT}(\alpha,\alpha)$. Nếu nó xuất ra $0$, thì $M_\mathsf{UC}(\alpha)=1$; nếu không, $M_\mathsf{UC}$ dùng máy Turing phổ dụng để mô phỏng tính toán và thu được đáp án.
    
    Vì hàm $\mathsf{UC}$ là không tính được theo Turing, nên $M_\mathsf{HALT}$ không tồn tại; nói cách khác, bài toán dừng là không tính được theo Turing.

## Luận đề Church-Turing

Luận đề Church-Turing phát biểu rằng nếu một lớp bài toán có một phương pháp hữu hiệu để giải, thì lớp bài toán đó có thể được giải bởi một máy Turing nào đó.

Trong đó, "phương pháp hữu hiệu" cần thỏa mãn:

1.  Chứa hữu hạn chỉ thị rõ ràng;
2.  Khi dùng phương pháp này để giải một bài toán thuộc lớp đó, phương pháp cần kết thúc trong hữu hạn bước và nhận được đáp án đúng.

Luận đề này chưa được chứng minh, nhưng nó là một tiên đề cơ bản của lý thuyết tính toán.

## Lớp độ phức tạp

Có rất nhiều lớp độ phức tạp. Bài này chỉ giới thiệu một phần nhỏ tương đối thường gặp.

### R và RE

Với ngôn ngữ $L$ và máy Turing $M$, nếu $M$ dừng trong hữu hạn bước trên mọi đầu vào, và $M(x)=1\iff x\in L$, thì ta nói $M$ có thể **quyết định** $L$.

Với ngôn ngữ $L$ và máy Turing $M$, nếu với mọi đầu vào thuộc $L$, $M$ đều dừng trong hữu hạn bước, và $M(x)=1\iff x\in L$, thì ta nói $M$ có thể **nhận biết** $L$.

Lớp độ phức tạp $\mathsf R$ biểu diễn tập các ngôn ngữ có thể được một máy Turing nào đó quyết định, tức là tất cả các ngôn ngữ tính được theo Turing.

Lớp độ phức tạp $\mathsf{RE}$ biểu diễn tập các ngôn ngữ có thể được một máy Turing nào đó nhận biết. $\mathsf{RE}$ còn được gọi là các ngôn ngữ đệ quy liệt kê được.

Từ định nghĩa có thể suy ra $\mathsf{R}\subseteq\mathsf{RE}$.

### DTIME

Nếu tồn tại một máy Turing tất định có thể quyết định một ngôn ngữ, và với mọi đầu vào $x$, máy Turing này có thể dừng trong thời gian $O(f(|x|))$, thì ngôn ngữ đó thuộc lớp $\mathsf{DTIME}(f(n))$.

### P

Lớp độ phức tạp $\mathsf P$ biểu diễn các bài toán quyết định có thể được giải bởi máy Turing tất định trong thời gian đa thức, tức là:

$$
\mathsf{P}=\bigcup\limits_{k\in\mathbb{N}}\mathsf{DTIME}(n^k)
$$

Quy hoạch tuyến tính, tính ước chung lớn nhất, và phiên bản quyết định của bài toán tìm cặp ghép cực đại trong đồ thị đều là các bài toán thuộc lớp $\mathsf P$.

### EXPTIME

Lớp độ phức tạp $\mathsf{EXPTIME}$ biểu diễn các bài toán quyết định có thể được giải bởi máy Turing tất định trong thời gian cấp số mũ, tức là:

$$
\mathsf{EXPTIME}=\bigcup\limits_{k\in\mathbb{N}}\mathsf{DTIME}(2^{n^k})
$$

Một phiên bản yếu hóa của bài toán dừng - cho mã hóa của một máy Turing và một số nguyên dương $k$, quyết định máy Turing đó có dừng trong $k$ bước hay không - là một bài toán thuộc lớp $\mathsf{EXPTIME}$. Lý do là lời giải của bài toán này cần thời gian $O(k)$, còn số $k$ có thể được mã hóa thành một xâu nhị phân có độ dài $O(\log k)$.

### NTIME

Nếu tồn tại một máy Turing không tất định có thể quyết định một ngôn ngữ, và với mọi đầu vào $x$, máy Turing này có thể dừng trong thời gian $O(f(|x|))$, thì ngôn ngữ đó thuộc lớp $\mathsf{NTIME}(f(n))$.

### NP

Lớp độ phức tạp $\mathsf{NP}$ biểu diễn các bài toán quyết định có thể được giải bởi máy Turing không tất định trong thời gian đa thức, tức là:

$$
\mathsf{NP}=\bigcup\limits_{k\in\mathbb{N}}\mathsf{NTIME}(n^k)
$$

Mọi bài toán thuộc lớp $\mathsf P$ đều là bài toán thuộc lớp $\mathsf{NP}$. Để xem thêm các bài toán thuộc lớp $\mathsf{NP}$, hãy tham khảo các bài toán NPC và NP-intermediate ở phần dưới.

#### NP-hard

Nếu mọi bài toán thuộc lớp $\mathsf{NP}$ đều có thể quy về bài toán $H$ trong thời gian đa thức, thì bài toán $H$ là NP-hard.

Nói cách khác, nếu có thể giải bài toán NP-hard $H$ trong một đơn vị thời gian, thì mọi bài toán thuộc lớp $\mathsf{NP}$ đều có thể được giải trong một số đơn vị thời gian đa thức.

#### NP-complete

Nếu một bài toán vừa thuộc lớp $\mathsf{NP}$ vừa là NP-hard, thì bài toán đó là NP hoàn toàn (NP-complete), hoặc nói cách khác là một bài toán NPC.

Một số bài toán NPC kinh điển: phiên bản quyết định của bài toán người bán hàng du lịch, phiên bản quyết định của bài toán tập độc lập lớn nhất, phiên bản quyết định của bài toán phủ đỉnh nhỏ nhất, phiên bản quyết định của bài toán đường đi dài nhất, phiên bản quyết định của bài toán quy hoạch nguyên 0-1, bài toán phủ tập, bài toán tô màu đồ thị, bài toán ba lô, bài toán ghép cặp ba chiều, phiên bản quyết định của bài toán lát cắt lớn nhất.

Phiên bản hàm của bài toán NPC thường là NP-hard. Ví dụ: "quyết định trong một đồ thị có tồn tại clique kích thước $k$ hay không" vừa là một bài toán thuộc lớp $\mathsf{NP}$ vừa là NP-hard, nên nó là một bài toán NPC; còn phiên bản hàm của nó, "tìm clique lớn nhất của một đồ thị", không phải là bài toán NPC, nhưng phiên bản hàm này vẫn là NP-hard.

Tương tự, các lớp độ phức tạp khác cũng có khái niệm "XX-complete". Chẳng hạn, mọi bài toán thuộc lớp $\mathsf{EXPTIME}$ đều có thể quy về một bài toán EXPTIME-complete trong thời gian đa thức.

#### co-NP

Một bài toán thuộc lớp $\mathsf{co-NP}$ khi và chỉ khi phần bù của nó là một bài toán thuộc lớp $\mathsf{NP}$. Nếu hiểu "bài toán" là "ngôn ngữ", còn "ngôn ngữ" là tập con của $\Sigma^\ast$, ta sẽ hiểu được "phần bù".

Ví dụ: "cho $n$ tập con, xác định có thể chọn $k$ tập trong số đó để phủ toàn bộ tập hay không" là một bài toán NPC, còn phần bù của nó, "cho $n$ tập con, xác định có phải bất kỳ cách chọn $k$ tập nào trong số đó cũng không thể phủ toàn bộ tập hay không", là một bài toán thuộc lớp $\mathsf{co-NP}$. Nếu đáp án của bài toán thứ nhất là "có", thì điều đó tương đương với việc tìm được một phản ví dụ cho bài toán thứ hai, nên đáp án của bài toán thứ hai là "không".

#### NP-intermediate

Nếu một bài toán thuộc lớp $\mathsf{NP}$ nhưng vừa không thuộc lớp $\mathsf{P}$ vừa không phải là bài toán NPC, thì nó được gọi là bài toán NP-intermediate.

Theo hiểu biết hiện nay, bài toán đẳng cấu đồ thị, bài toán logarit rời rạc và bài toán phân tích thừa số có thể là NP-intermediate.

Định lý Ladner chỉ ra rằng nếu $\mathsf{P}\ne\mathsf{NP}$, thì chắc chắn tồn tại bài toán NP-intermediate.

### NEXPTIME

Lớp độ phức tạp $\mathsf{NEXPTIME}$ biểu diễn các bài toán quyết định có thể được giải bởi máy Turing không tất định trong thời gian cấp số mũ, tức là:

$$
\mathsf{NEXPTIME}=\bigcup\limits_{k\in\mathbb{N}}\mathsf{NTIME}(2^{n^k})
$$

### #P

Các bài toán thuộc lớp $\mathsf{\#P}$ không phải là bài toán quyết định, mà là bài toán đếm liên quan đến các bài toán thuộc lớp $\mathsf{NP}$: đếm số nghiệm của một bài toán thuộc lớp $\mathsf{NP}$ là một bài toán thuộc lớp $\mathsf{\#P}$. Nói cách khác, đếm xem một xâu được chấp nhận tại bao nhiêu nhánh của một máy Turing không tất định luôn dừng trong thời gian đa thức là một bài toán thuộc lớp $\mathsf{\#P}$.

Đếm số cặp ghép hoặc cặp ghép hoàn hảo của một đồ thị thông thường hoặc đồ thị hai phía đều là #P-complete; bài toán quyết định tương ứng là "quyết định một đồ thị có tồn tại cặp ghép (hoàn hảo) hay không".

### DSPACE

Nếu tồn tại một máy Turing tất định có thể quyết định một ngôn ngữ trong không gian $O(f(|x|))$ khi đầu vào là $x$, thì ngôn ngữ đó thuộc lớp $\mathsf{DSPACE}(f(n))$.

-   $\mathsf{REG}=\mathsf{DSPACE}(O(1))$, tức là ngôn ngữ chính quy, cũng là các ngôn ngữ mà automaton có thể quyết định.

-   $\mathsf{L}=\mathsf{DSPACE}(O(\log n))$. Cần chú ý rằng không gian mà máy Turing sử dụng không bao gồm không gian do đầu vào chiếm dụng.

-   $\mathsf{PSPACE}=\bigcup\limits_{k\in\mathbb N}\mathsf{DSPACE}(n^k)$

-   $\mathsf{EXPSPACE}=\bigcup\limits_{k\in\mathbb N}\mathsf{DSPACE}(2^{n^k})$

### NSPACE

Nếu tồn tại một máy Turing không tất định có thể quyết định một ngôn ngữ trong không gian $O(f(|x|))$ khi đầu vào là $x$, thì ngôn ngữ đó thuộc lớp $\mathsf{NSPACE}(f(n))$.

-   $\mathsf{REG}=\mathsf{DSPACE}(O(1))=\mathsf{NSPACE}(O(1))$

-   $\mathsf{NL}=\mathsf{NSPACE}(O(\log n))$

-   $\mathsf{CSL}=\mathsf{NSPACE}(O(n))$, tức là ngôn ngữ phụ thuộc ngữ cảnh.

-   $\mathsf{PSPACE}=\mathsf{NPSPACE}=\bigcup\limits_{k\in\mathbb N}\mathsf{NSPACE}(n^k)$

-   $\mathsf{EXPSPACE}=\mathsf{NEXPSPACE}=\bigcup\limits_{k\in\mathbb N}\mathsf{NSPACE}(2^{n^k})$

## Thời gian đa thức

Nói đơn giản, nếu tồn tại số dương $k$ sao cho độ phức tạp thời gian của một thuật toán là $O(n^k)$ (chú ý, không phải $\Theta(n^k)$), trong đó $n$ là quy mô bài toán (độ dài đầu vào), thì thuật toán đó được gọi là có **thời gian đa thức**. Nếu một bài toán có thuật toán thời gian đa thức (trên máy Turing tất định) để giải, thì bài toán đó thuộc lớp độ phức tạp $\mathsf{P}$.

Thời gian đa thức có thể chia thành thời gian đa thức mạnh và thời gian đa thức yếu; ngoài ra còn có thời gian giả đa thức.

### Strongly polynomial time

Trước hết, ta định nghĩa một mô hình tính toán gọi là mô hình số học. Trong mô hình số học, các phép toán số học giữa các số (cộng, trừ, nhân, chia, so sánh độ lớn) có thể hoàn thành trong thời gian đơn vị (tức là trong thời gian $O(1)$, không phụ thuộc vào độ lớn của số).

Nếu số phép toán của một thuật toán trong mô hình số học là một đa thức theo số lượng các số trong đầu vào, và độ phức tạp không gian là một đa thức theo quy mô đầu vào (chứ không phải theo số lượng các số), thì thuật toán đó có **thời gian đa thức mạnh**. Vì các phép toán số học trong mô hình tính toán thông thường có thể hoàn thành trong thời gian đa thức theo quy mô đầu vào (tức là theo logarit độ lớn của số), thuật toán thời gian đa thức mạnh chắc chắn là thuật toán thời gian đa thức.

Nói chung, độ phức tạp thời gian của thuật toán thời gian đa thức mạnh không phụ thuộc vào miền giá trị.

### Weakly polynomial time

Nếu một thuật toán có thời gian đa thức nhưng không có thời gian đa thức mạnh, thì nó có **thời gian đa thức yếu**.

Ví dụ, thuật toán Euclid để tính ước chung lớn nhất có độ phức tạp thời gian $O(\log a + \log b)$ (trong đó $a$ và $b$ là độ lớn của các số đầu vào), nên là thuật toán thời gian đa thức yếu.

### Pseudo-polynomial time

Nếu thời gian chạy của một thuật toán là đa thức theo miền giá trị, thì thuật toán đó được gọi là có **thời gian giả đa thức**. Thuật toán thời gian giả đa thức có thể là thời gian đa thức hoặc cũng có thể không phải. Lý do có thể không phải thời gian đa thức là vì để biểu diễn một số nguyên dương có độ lớn $n$ thường chỉ cần $O(\log n)$ bit nhị phân, nên thuật toán có thời gian đa thức theo miền giá trị thường có thời gian cấp số mũ theo độ dài đầu vào. Tuy theo định nghĩa, thời gian giả đa thức cũng có thể là thời gian đa thức, nhưng khi nói một thuật toán có thời gian giả đa thức, thông thường ta đang nói thuật toán đó không phải là thời gian đa thức.

Ví dụ, bài toán ba lô là bài toán NP-hard, nhưng nó có lời giải thời gian giả đa thức dựa trên quy hoạch động.

Nếu một bài toán NPC/NP-hard có lời giải thời gian giả đa thức, thì bài toán đó được gọi là bài toán **NPC yếu**/**NP-hard yếu**. Nếu một bài toán NPC/NP-hard không có lời giải thời gian giả đa thức dưới giả thiết $\mathsf{P} \ne \mathsf{NP}$, thì bài toán đó được gọi là bài toán **NPC mạnh**/**NP-hard mạnh**.

## Hàm xây dựng được

### Hàm xây dựng được theo thời gian

Đôi khi ta muốn máy Turing biết nó đã dùng bao nhiêu thời gian, ví dụ như buộc máy Turing dừng sau khi thực hiện $T(n)$ bước tính toán. Nhưng nếu thời gian dùng để tính $T(n)$ đã vượt quá $T(n)$, điều này là không thể. Vì vậy, ta định nghĩa hàm xây dựng được theo thời gian để tránh rắc rối như vậy.

Nếu tồn tại máy Turing $M$ sao cho khi đầu vào là $1^n$ ($n$ ký tự 1), $M$ có thể dừng trong thời gian $O(f(n))$ và xuất ra biểu diễn nhị phân của $f(n)$ (chú ý, đầu ra của máy Turing ở đây không phải là chấp nhận/không chấp nhận, mà là một xâu; đầu ra có thể được đặt trên băng), thì $f(n)$ là một **hàm xây dựng được theo thời gian**.

Vì việc đọc đầu vào cần thời gian $O(n)$, mọi hàm không hằng thuộc $o(n)$ đều không phải là hàm xây dựng được theo thời gian.

### Hàm xây dựng được theo không gian

Tương tự, có thể định nghĩa hàm xây dựng được theo không gian.

Nếu tồn tại máy Turing $M$ sao cho khi đầu vào là $1^n$ ($n$ ký tự 1), $M$ có thể dừng trong không gian $O(f(n))$ và xuất ra biểu diễn nhị phân của $f(n)$, thì $f(n)$ là một **hàm xây dựng được theo không gian**.

## Quan hệ giữa các lớp độ phức tạp

### Định lý phân cấp thời gian

#### Định lý phân cấp thời gian tất định

Nếu $f(n)$ là một hàm xây dựng được theo thời gian, thì:

$$
\mathsf {DTIME}\left(o\left({\frac {f(n)}{\log f(n)}}\right)\right)\subsetneq \mathsf {DTIME}(f(n))
$$

Từ định lý phân cấp thời gian tất định có thể suy ra $\mathsf{P}\subsetneq\mathsf{EXPTIME}$.

??? note "Chứng minh định lý phân cấp thời gian tất định"
    Định nghĩa ngôn ngữ $L=\{(x, y)|\mathcal{U}((x, y), x)\text{ dừng và từ chối trong thời gian }f(|x|+|y|)\}$. Vì $f(n)$ là một hàm xây dựng được theo thời gian, có thể tính theo định nghĩa để quyết định $L$, với thời gian $O(f(|x|+|y|))$, nên $L\in\mathsf{DTIME}(f(n))$.
    
    Bây giờ giả sử $L\in\mathsf{DTIME}(o\left({\dfrac {f(n)}{\log f(n)}}\right))$, và đặt $M_z$ là máy Turing quyết định $L$ trong thời gian $o\left({\dfrac {f(n)}{\log f(n)}}\right)$.
    
    Gọi thời gian chạy của máy Turing phổ dụng $\mathcal{U}(x, z)$ theo $x$ là $g(|x|)$. Từ phần giới thiệu về máy Turing phổ dụng ở trên, ta có $g(n)=o(f(n))$, nên khi $y$ đủ lớn, $g(|z|+|y|)<f(|z|+|y|)$.
    
    Lấy $y'$ là một $y$ đủ lớn. Khi đó $\mathcal{U}((z, y'), z)$ chắc chắn dừng trong thời gian $f(|z|+|y'|)$, dẫn đến $M_z(z, y')\ne M_z(z, y')$, tạo ra mâu thuẫn. Vì vậy giả thiết không đúng, và định lý phân cấp thời gian tất định được chứng minh.

#### Định lý phân cấp thời gian không tất định

Nếu $g(n)$ là một hàm xây dựng được theo thời gian, và $f(n+1)=o(g(n))$, thì $\mathsf{NTIME}(f(n))\subsetneq\mathsf{NTIME}(g(n))$.

Từ định lý phân cấp thời gian không tất định có thể suy ra $\mathsf{NP}\subsetneq\mathsf{NEXPTIME}$.

### Định lý phân cấp không gian

Nếu $f(n)$ là một hàm xây dựng được theo không gian và $f(n)=\Omega(\log n)$, thì $\mathsf{SPACE}(o(f(n)))\subsetneq\mathsf{SPACE}(f(n))$.

Trong đó $\mathsf{SPACE}$ có thể thay cho $\mathsf{DSPACE}$ hoặc $\mathsf{NSPACE}$.

Từ định lý phân cấp không gian có thể suy ra $\mathsf{PSPACE}\subsetneq\mathsf{EXPSPACE}$.

### Định lý Savitch

Một máy Turing tất định có thể mô phỏng một máy Turing không tất định trong bình phương không gian mà máy không tất định tiêu thụ (dù thời gian tiêu thụ có thể lớn hơn nhiều), tức là:

Nếu $f(n)=\Omega(\log n)$, thì:

$$
\mathsf{NSPACE}\left(f\left(n\right)\right)\subseteq \mathsf {DSPACE}\left(\left(f\left(n\right)\right)^2\right)
$$

Hệ quả: $\mathsf{PSPACE}=\mathsf{NPSPACE}$, $\mathsf{EXPSPACE}=\mathsf{NEXPSPACE}$.

### P?=NP

Việc hai lớp độ phức tạp $\mathsf{P}$ và $\mathsf{NP}$ có bằng nhau hay không là một bài toán mở nổi tiếng trong lý thuyết độ phức tạp tính toán.

Nếu $\mathsf{P}=\mathsf{NP}$, có thể suy ra $\mathsf{NP}=\mathsf{co-NP}$, nhưng chiều ngược lại thì không (hiện chưa có phương pháp chứng minh $\mathsf{P}=\mathsf{NP}$ dựa trên $\mathsf{NP}=\mathsf{co-NP}$).

???+ note "Vì sao NP?=co-NP không phải là hiển nhiên?"
    Vì một bài toán $\mathsf{NP}$ và bài toán $\mathsf{co-NP}$ tương ứng có đáp án trái ngược nhau, rất dễ nảy sinh ý nghĩ này: với một bài toán $\mathsf{co-NP}$, chỉ cần đảo ngược đầu ra của máy Turing không tất định giải phần bù của nó là giải được bài toán $\mathsf{co-NP}$ đó, nên $\mathsf{NP}=\mathsf{co-NP}$.
    
    Thực ra, cách nói trên đúng là có thể giải bài toán $\mathsf{co-NP}$ đó, nhưng nó không tìm được một máy Turing không tất định để giải bài toán này: nếu việc một máy Turing làm là đảo ngược đầu ra của một máy Turing không tất định, thì máy Turing đó không phải là máy Turing không tất định. Bởi vì máy Turing không tất định chấp nhận khi có một nhánh nào đó chấp nhận, còn từ chối khi mọi nhánh đều từ chối; khi đảo ngược đầu ra của nó, việc chấp nhận biến thành xảy ra ở mọi nhánh, còn từ chối biến thành xảy ra ở một nhánh, điều này không phù hợp với định nghĩa của máy Turing không tất định. Vì vậy, việc có thể dùng máy Turing đó để giải bài toán $\mathsf{co-NP}$ này không làm cho bài toán $\mathsf{co-NP}$ này trở thành một bài toán $\mathsf{NP}$.

Nếu $\mathsf{P}=\mathsf{NP}$, còn có thể suy ra $\mathsf{EXPTIME}=\mathsf{NEXPTIME}$.

Nếu $\mathsf{P}\ne\mathsf{NP}$, có thể suy ra NP-intermediate không rỗng.

## Tài liệu tham khảo

1.  [Độ phức tạp tính toán (1): Automaton và ngôn ngữ chính quy](https://lingerois.com/p/%E8%AE%A1%E7%AE%97%E5%A4%8D%E6%9D%82%E6%80%A71-%E8%87%AA%E5%8A%A8%E6%9C%BA%E4%B8%8E%E6%AD%A3%E5%88%99%E8%AF%AD%E8%A8%80/);

2.  [Độ phức tạp tính toán (2): Máy Turing và tính khả tính](https://lingerois.com/p/%E8%AE%A1%E7%AE%97%E5%A4%8D%E6%9D%82%E6%80%A72-%E5%9B%BE%E7%81%B5%E6%9C%BA%E4%B8%8E%E5%8F%AF%E8%AE%A1%E7%AE%97%E6%80%A7/);

3.  Các mục từ liên quan trên [Wikipedia](https://en.wikipedia.org/) và tài liệu tham khảo của các mục từ đó.
