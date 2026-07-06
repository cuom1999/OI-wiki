author: ouuan, Henry-ZHR, StudyingFather, ChungZH, xyf007, Cryflmind, oierlinch, xk2013awa

## Chuẩn bị trước khi ra đề

### Có một trình độ nhất định

Một mặt, khi tự ra đề, rất khó để tạo ra bài có độ khó vượt quá trình độ của chính mình; một nền tảng OI nhất định sẽ giúp nghĩ ra ý tưởng chất lượng hơn và tìm được lời giải tốt hơn. Mặt khác, trình độ OI ở một mức nào đó cũng phản ánh kinh nghiệm OI: những thí sinh đã gặp nhiều bài hơn thường sẽ có quan điểm riêng về thế nào là một "bài hay".

### Có thái độ nghiêm túc và có trách nhiệm

Ra đề là để người khác làm. So với việc thể hiện bản thân, mục tiêu quan trọng hơn là phục vụ người khác. Thi đấu thuật toán là cuộc thi giữa các thí sinh, không phải cuộc đối đầu giữa người ra đề và người làm bài. Vì vậy, ra đề không nên lấy việc "đánh gục" thí sinh làm mục tiêu (dĩ nhiên, chống AK hợp lý và độ phân hóa tốt cũng rất quan trọng), mà nên giúp thí sinh thu được điều gì đó trong cuộc thi. Việc dành đủ thời gian và công sức để học cách ra đề, rồi ra đề một cách nghiêm túc và có trách nhiệm, là rất quan trọng.

### Sẵn sàng bỏ ra rất nhiều thời gian

Nếu muốn ra đề nghiêm túc, cần dành rất nhiều thời gian. Nếu không chuẩn bị tâm lý trước, việc chuẩn bị cuộc thi có thể trở nên vội vàng, chất lượng không đạt; hoặc sau đó người ra đề có thể hối tiếc vì đã không dành thời gian ấy cho việc học. Tuy nhiên, ra đề cũng có thể mang lại rất nhiều kỷ niệm đẹp. Nếu thật sự có hứng thú với việc ra đề và đã chuẩn bị tâm lý đầy đủ, những gì thu được từ việc ra đề có thể bù đắp cho thời gian đã bỏ ra.

### Đọc kỹ nội dung bài viết này

Bài viết này giới thiệu toàn bộ quy trình ra đề từ hai góc độ: ra đề như thế nào và làm sao để ra đề hay. Với những ai muốn ra đề, đọc kỹ bài viết này sẽ có ích.

## Nội dung bài toán

Để ra một bài, ý tưởng, tức nội dung cốt lõi của bài toán, là linh hồn của bài và cũng là bước đầu tiên của việc ra đề.

### Nguồn gốc của ý tưởng

1.  Được gợi cảm hứng từ các bài đã có (nhưng không được sao chép hoặc tăng cường một cách vô nghĩa, chẳng hạn: chuyển một bài về dãy lên cactus).
2.  Được gợi cảm hứng từ các kiến thức đã học (nhưng không được ghép các kiến thức rời rạc một cách vô liên quan).
3.  Được gợi cảm hứng từ đời sống/trò chơi (nhưng chú ý đừng biến trò chơi thành một bài mô phỏng lớn).
4.  Không rõ vì sao, tự nhiên nghĩ ra một bài.

### Những ý tưởng như thế nào là không tốt

#### Về bài gốc

Bài gốc có thể được chia đại khái thành ba loại: hoàn toàn giống nhau, gần như giống nhau và lời giải giống nhau.

-   Hoàn toàn giống nhau: mã AC của một bài có thể AC bài còn lại.
-   Gần như giống nhau: việc sửa mã AC của một bài thành mã AC của bài còn lại có thể được thực hiện bởi một người chưa biết bài đó.
-   Lời giải giống nhau: ý tưởng cốt lõi và cách làm giống nhau, nhưng khác nhau ở phần cài đặt hoặc một vài chi tiết không quá then chốt.

Ba loại bài gốc này có quan hệ bao hàm từ dưới lên trên.

Những tình huống sau không nên xuất hiện:

1.  Ra bài gốc trong khi biết rõ đã có bài gốc "gần như giống nhau".
2.  Vì không dùng công cụ tìm kiếm để tra cứu nên không biết có bài gốc, từ đó ra một bài gốc "gần như giống nhau".
3.  Ra bài gốc khi bài gốc "lời giải giống nhau" đã rất nổi tiếng (ví dụ: đề gốc NOIP, NOI).
4.  Xuất hiện bài gốc "lời giải giống nhau" trong một bài không phải bài cho điểm dễ của kỳ thi có tính tuyển chọn.

Những tình huống sau tốt nhất cũng không nên xuất hiện:

1.  Ra bài gốc trong khi biết rõ đã có bài gốc ít nhất là "lời giải giống nhau".
2.  Vì không dùng công cụ tìm kiếm để tra cứu nên không biết có bài gốc, từ đó ra một bài gốc "lời giải giống nhau".
3.  Ra bài gốc "gần như giống nhau" trong bất kỳ hoàn cảnh nào.

Các ngoại lệ có thể nới lỏng yêu cầu:

1.  Thi thử trong trường.
2.  Thi thử nhằm mục đích luyện tập chuyên đề.
3.  Cuộc thi có độ khó thấp, hoặc bài được định vị là bài cho điểm dễ.

#### Về bài "độc"

"Bài độc" là một khái niệm rất mơ hồ và chủ quan. Phần này chỉ trích dẫn một số thảo luận của những người đi trước về vấn đề này, kèm theo một vài cách hiểu của người viết. Chủ đề này rất mở, hoan nghênh mọi người nêu quan điểm của mình.

> Một bài hay không nên là hai bài ghép lại với nhau; một bài hay sẽ có ý tưởng riêng của nó, và nó nên làm nổi bật ý tưởng ấy mà không cần quá nhiều lớp vỏ bọc.
>
> Một bài hay nên mới mẻ. Bài thật sự hay nên là bài có thể mở ra một cách nghĩ mới cho người đọc.
>
> --[vfk, *Nguồn gốc tinh thần của UOJ*][1]

Ví dụ: [XR-1: Gia tộc Conan](https://www.luogu.com.cn/problem/P5346), hai nửa trước sau của lời giải hoàn toàn tách rời. Nửa đầu là [Mẫu: sắp xếp hậu tố trên cây](https://www.luogu.com.cn/problem/P5353), nửa sau là một bài toán kinh điển trên cây. Ngay cả khi nhập tùy ý trọng số các đỉnh của cây, vẫn có thể làm phần thứ hai; hai phần trước sau không có liên hệ.

> Một loại bài OI lấy toán học làm chính; dù là mô tả đề hay lời giải đều mang đặc trưng của bài toán học, và lời giải không chứa kiến thức liên quan đến thuật toán. Những bài OI kiểu này được gọi chung là bài thuần toán.
>
> --[Wang Tianyi, *Bàn về tác hại của đề lệch*][2]

Ví dụ kinh điển: [NOIP2017 Nỗi băn khoăn của Xiao Kai](https://uoj.ac/problem/329)

Điểm khác biệt giữa bài toán học trong OI và các bài toán học khác, cũng là một đặc điểm thể hiện bản chất của OI, là trọng tâm của bài toán học trong OI thường không nằm ở đáp án **là gì**, mà nằm ở cách **tăng tốc** việc tính đáp án. Nếu trọng tâm khảo sát của một bài là "tính như thế nào" thay vì "làm sao tính nhanh", thì dạng bài toán học như vậy thường không phù hợp để đưa vào OI.

> Một số bài lệch hướng có liên quan đến nội dung vật lý đại học, khiến thí sinh khi đối mặt với những kiến thức vật lý chưa từng tiếp xúc trở nên lúng túng, tạo ra rào cản về kiến thức.
>
> --[Wang Tianyi, *Bàn về tác hại của đề lệch*][2]

Ví dụ kinh điển: [Tập huấn Thanh Hoa 2015: Đa giác xuống biển](https://uoj.ac/problem/159)

Không chỉ vật lý, bài OI cũng không nên liên quan quá nhiều đến kiến thức của các môn học khác. Nếu có liên quan, cần giải thích chi tiết, và không nên để kiến thức của môn khác trở thành trở ngại lớn trong việc giải bài.

> Một bài hay, bất kể độ khó thế nào, đều nên có độ khó tư duy riêng, cần thí sinh suy nghĩ và phát hiện một số tính chất.
>
> Mã của một bài hay có thể dài, nhưng nhất định không phải dài vì cố tình lồng ghép hoặc thêm điều kiện một cách gượng ép; nó phải dài một cách tự nhiên, khiến người đọc cảm thấy mã của bài này vốn nên dài như vậy.
>
> --[Wang Tianyi, *Bàn về tác hại của đề lệch*][2]

Ví dụ kinh điển: [SDOI2010: Sát Trư Quốc](https://loj.ac/problem/2885), [Kiểm tra chéo đội tuyển tập huấn 2015: Chương trình tương lai - bản sửa](https://uoj.ac/problem/98)

Trong các cuộc thi OI thông thường, độ khó tư duy nên chiếm phần chủ yếu. Những bài kỹ thuật như Day 2+ của THUWC/THUSC cũng có lý do tồn tại của chúng: mục đích của trại trải nghiệm không chỉ là kiểm tra năng lực thiết kế thuật toán của thí sinh, mà còn kiểm tra khả năng viết mã kỹ thuật và học tài liệu để nối tiếp với việc học ở đại học. Nhưng trong các cuộc thi OI thông thường, điều cần khảo sát nhiều hơn vẫn nên là thiết kế thuật toán và năng lực tư duy.

## Đề bài

### Dùng LaTeX để viết công thức

Trên mạng có rất nhiều hướng dẫn LaTeX, chẳng hạn:

-   [Nhập môn LaTeX](../tools/latex.md)
-   [Tổng hợp công thức toán LaTeX](https://www.luogu.com.cn/blog/IowaBattleship/latex-gong-shi-tai-quan)
-   [Các lệnh và ký hiệu LaTeX](https://blog.csdn.net/anxiaoxi45/article/details/39449445)

Khi sử dụng, cần chú ý [yêu cầu định dạng công thức LaTeX](../intro/format.md).

### Bối cảnh bài toán

Bối cảnh bài toán tốt nhất nên càng ngắn gọn càng tốt. Khi bối cảnh tương đối dài, nên tách riêng với phần mô tả bài toán.

Cần tuyệt đối tránh việc bối cảnh ảnh hưởng nghiêm trọng đến việc hiểu ý đề.

Khi cần thiết, có thể cung cấp hai phiên bản mô tả: một phiên bản kết hợp với bối cảnh và một phiên bản mô tả ngắn gọn.

### Mô tả bài toán

Nói ngắn gọn, mô tả bài toán cần **mạch lạc, dễ hiểu**.

Mọi định nghĩa trong đề có khả năng không được hiểu đều cần được giải thích; không nên đột ngột xuất hiện khái niệm chưa được định nghĩa. Ví dụ: trong [CF1172D Nauuo and Portals](https://codeforces.com/problemset/problem/1172/D), đề phải giải thích "portal" là gì.

Mỗi khái niệm xuất hiện trong đề nên được mô tả bằng một từ duy nhất. Ví dụ: không nên lúc thì nói "chi phí", lúc lại nói "giá".

Không nên dùng một từ với nghĩa khác nghĩa gốc hoặc nghĩa thông dụng mà không giải thích. Ví dụ: không nên dùng "đường đi" để chỉ một cạnh nếu không nói rõ.

Cần tránh để đề bài tự mâu thuẫn. Ví dụ: trong [CF1173A Nauuo and Votes](https://codeforces.com/problemset/problem/1173/A), dấu "?" không được coi là một loại "kết quả", vì ý nghĩa của "?" là "có nhiều hơn một kết quả khả dĩ".

Cần tránh để đề bài có cách hiểu sai nhưng vẫn tự hợp lý hóa được, kể cả khi cách hiểu đó trái với lẽ thường và gần như không ai sẽ nghĩ như vậy. Ví dụ: trong [CF1172D Nauuo and Portals](https://codeforces.com/problemset/problem/1172/D), lý do phải định nghĩa rườm rà "đi vào" và phân biệt với "dịch chuyển" là để ngăn cách hiểu như sau: đi qua portal có thể tới một portal khác, mà tới portal thì sẽ dịch chuyển, nên sẽ nhảy qua lại vô hạn.

Đọc xuôi phần mô tả bài toán nên hiểu được từng câu, đồng thời hiểu nhiệm vụ và yêu cầu của bài. Ít nhất, nếu có thắc mắc thì thắc mắc đó phải được giải thích ngay ở đoạn tiếp theo, chứ không phải đợi vài đoạn sau mới được giải thích, hoặc phải đọc phần định dạng vào ra mới hiểu ý đề, thậm chí phải dựa vào ví dụ để đoán đề. Ví dụ: trong [GuOJ Round #1: Bữa tiệc băng tuyết của Cirno](https://github.com/OI-wiki/problemset/blob/master/contest/online/GuOJ/OI%20Archive%20-%20GuOJ1171.pdf), mục tiêu của bài "lượng nước lớn nhất mà Hồ Sương Mù cuối cùng có thể nhận được" lần đầu tiên mới xuất hiện trong phần định dạng đầu ra; cộng thêm câu "Reimu có thể nhanh chóng tính ra tổng chi phí sau khi dọn sạch toàn bộ suối nhỏ" mang tính gây hiểu nhầm, càng dễ khiến người đọc hiểu sai ý đề. Điều này không nên xảy ra; mục tiêu của bài nên được nêu ngay trong mô tả bài toán. (Trong ví dụ này còn có vấn đề bối cảnh bài toán ảnh hưởng nghiêm trọng đến việc hiểu ý đề.) Lỗi tương tự cũng xuất hiện trong [CF1423(4)N Bubblesquare Tokens](https://codeforces.com/problemset/problem/1423/N), khi mục tiêu của bài "các cặp thân thiết và số token mỗi người nhận được nhờ quan hệ đó" lần đầu tiên mới xuất hiện ở phần định dạng đầu ra.

### Định dạng vào ra

Định dạng vào ra chỉ cần mạch lạc và **đầy đủ**, không có yêu cầu cứng nhắc. Cá nhân người viết khuyên nên tham khảo cách viết đề của CF; chi tiết có thể xem [những điều người ra đề CF cần biết][3].

Để thuận tiện cho thí sinh làm bài, trong định dạng vào ra tốt nhất nên giải thích ý nghĩa cụ thể của từng biến, trừ khi ý nghĩa của biến rất dài và không thể nói rõ trong một câu (lúc này có thể viết "ý nghĩa xem trong mô tả bài toán").

Cần đặc biệt chú ý rằng nếu đầu ra có số thập phân, nên cố gắng dùng [SPJ](#special-judge) để giới hạn độ lớn sai số, thay vì yêu cầu "giữ lại x chữ số sau dấu thập phân".

"Giữ lại x chữ số sau dấu thập phân" có thể tạo ra yêu cầu độ chính xác vô hạn. Ví dụ: yêu cầu giữ lại ba chữ số sau dấu thập phân, đáp án thật là $0.0015$. Khi đó chỉ cần có sai số bất kỳ khiến đáp án tính được nhỏ hơn $0.0015$, dù đáp án tính được là $0.00149999\cdots$ thì cũng sẽ in ra đáp án sai.

Nếu không thể dùng SPJ, cần quy định yêu cầu về độ chính xác là hữu hạn. Ví dụ: in kết quả sau khi làm tròn đáp án đến ba chữ số sau dấu thập phân. Gọi đáp án chuẩn là $ans$, dữ liệu thỏa mãn rằng với mọi $x$ có $\frac{|x-ans|}{\max(1,ans)}<10^{-9}$, kết quả sau khi làm tròn của $x$ giống với kết quả sau khi làm tròn của $ans$.

Một số câu có thể tham khảo:

```latex
Dòng đầu tiên của dữ liệu vào chứa ba số nguyên dương $n$, $m$, $k$ ($1\le n,m\le 2\cdot 10^5$, $1\le k\le 100$) - $n$ biểu thị độ dài của dãy, $m$ biểu thị số thao tác, ý nghĩa của $k$ xem trong mô tả bài toán.
```

```latex
Dòng thứ hai của dữ liệu vào chứa $n$ số nguyên không âm $a_1,a_2,\ldots,a_n$ ($1\le a_i\le 10^9$) - dãy số được cho trong bài.
```

```latex
Dòng thứ $i$ trong $m$ dòng tiếp theo chứa hai số nguyên dương $l_i$ và $r_i$ ($1\le l_i\le r_i\le n$), biểu thị thao tác thứ $i$ được thực hiện trên đoạn $[l_i,r_i]$.
```

```latex
Mỗi dòng trong $n-1$ dòng tiếp theo chứa hai số nguyên dương $u$ và $v$ ($1\le u,v\le n$), biểu thị có một cạnh nối giữa $u$ và $v$.

Dữ liệu thỏa mãn rằng các cạnh được cho tạo thành một cây.
```

```latex
Dòng duy nhất của dữ liệu vào chứa một xâu không rỗng gồm các chữ cái tiếng Anh thường, độ dài không vượt quá $10^6$.
```

```latex
Dòng thứ hai của dữ liệu vào chứa một số thực $x$ có không quá ba chữ số sau dấu thập phân ($-10^6\le x\le 10^6$), ý nghĩa xem trong mô tả bài toán.
```

```latex
Đầu ra chứa một số thực. Nếu sai số tuyệt đối hoặc sai số tương đối giữa đầu ra của thí sinh và đáp án chuẩn nhỏ hơn $10^{-6}$ thì được coi là đúng.
```

```latex
Dòng thứ hai của đầu ra chứa $n$ số nguyên dương, biểu thị một phương án được xây dựng - trong đó số thứ $i$ biểu thị mã số lá bài thứ $i$ được đánh ra.

Nếu có nhiều đáp án hợp lệ, có thể in ra bất kỳ một đáp án nào.
```

???+ note "Sinh dữ liệu vào bằng bộ sinh số ngẫu nhiên trong mã của thí sinh"
    Một số bài do dữ liệu vào quá lớn, để tránh thời gian đọc dữ liệu quá lâu, sẽ yêu cầu thí sinh sinh dữ liệu trong mã bằng bộ sinh dữ liệu được cho, thay cho việc đọc dữ liệu qua chuẩn vào hoặc qua tệp.
    
    Cần cân nhắc thận trọng khi dùng cách này, vì nó có nhiều nhược điểm:
    
    -   Có thể đưa vào tính ngẫu nhiên của dữ liệu mà lời giải đúng không cần, hoặc khiến việc dựng dữ liệu trở nên khó khăn.
    -   Có thể làm tăng độ khó khi hiểu định dạng vào.
    -   Nếu bộ sinh số ngẫu nhiên được đóng gói không tốt, chỉ riêng việc hiểu cách dùng bộ sinh dữ liệu cũng có thể đã khó.
    -   Nếu thí sinh không dùng ngôn ngữ được người ra đề khuyến nghị, họ có thể phải tự viết một bộ sinh dữ liệu.
    
    Cách làm này thường được dùng để tránh thời gian đọc dữ liệu quá lâu. Vì vậy, một phương án thay thế khả dĩ là phát một mẫu [tối ưu đọc, ghi](./io.md) đủ tốt về hiệu năng, để cố gắng giữ thời gian đọc dữ liệu của mọi người gần như nhau; như vậy ngay cả khi thời gian đọc rất lâu, nó cũng không ảnh hưởng đến chênh lệch thời gian giữa các thí sinh. Một phương án khác là đóng gói bài thành bài tương tác kiểu gọi hàm (thay vì kiểu IO). Dù trong quá trình thuật toán không có tương tác, bài tương tác vẫn có thể dùng để thống nhất thời gian đọc dữ liệu; IOI đã dùng phương án mọi bài đều là bài tương tác. Tuy nhiên, cả hai phương án này đều hạn chế ngôn ngữ mà thí sinh có thể dùng, và người ra đề cần hỗ trợ thủ công từng ngôn ngữ được phép sử dụng.
    
    Quay lại bản chất vấn đề, cũng có thể cân nhắc xem dữ liệu vào quá lớn có thật sự cần thiết hay không, liệu có thể dùng dữ liệu vào nhỏ hơn để đạt mục đích hay không, và liệu có cần thiết phải chặn những lời giải có độ phức tạp chỉ kém lời giải đúng một chút hay không.

### Giới hạn dữ liệu

Theo yêu cầu của CF, giới hạn dữ liệu phải được viết trong phần định dạng vào, nhưng ở Trung Quốc, giới hạn dữ liệu thường được viết ở cuối đề.

Lỗi dễ mắc nhất trong giới hạn dữ liệu là không đầy đủ. Mỗi con số, mỗi xâu trong dữ liệu vào đều phải có ràng buộc cụ thể. Trong các ví dụ về định dạng vào ra ở trên đã có một số cách viết giới hạn dữ liệu đúng.

Những thiếu sót thường gặp trong giới hạn dữ liệu:

1.  Thiếu chữ "nguyên" trong "số nguyên".
2.  Đề chỉ nói là "số nguyên" mà không nói là "số nguyên dương", đồng thời trong giới hạn dữ liệu chỉ có cận trên mà không có cận dưới.
3.  Xâu không nói rõ bảng chữ cái.
4.  Số thực không nói rõ số chữ số sau dấu thập phân.
5.  Một số biến không có giới hạn.

Cần chắc rằng lời giải chuẩn có thể chạy qua **bất kỳ bộ dữ liệu nào** thỏa mãn giới hạn được nêu trong đề.

???+ note "Về việc 'dữ liệu được sinh ngẫu nhiên'"
    Một số bài sẽ ghi rằng "dữ liệu được sinh ngẫu nhiên". Trong rất nhiều trường hợp, ràng buộc như vậy không phải là phương án tối ưu, vì "sinh ngẫu nhiên" không đưa ra giới hạn cụ thể cho dữ liệu, gây khó khăn cho việc xác định phạm vi dữ liệu cụ thể và cung cấp dữ liệu hack.
    
    Nói chung, câu "dữ liệu được sinh ngẫu nhiên" có thể được thay bằng tính chất dữ liệu mà lời giải cần. Ví dụ, sinh ngẫu nhiên một cây thường có thể được thay bằng giới hạn chiều cao của cây.
    
    Nếu nhất định phải yêu cầu dữ liệu được sinh ngẫu nhiên, cần chỉ rõ thao tác sinh ngẫu nhiên cụ thể. Ví dụ, khi sinh một cây, là chọn ngẫu nhiên đỉnh cha hay sinh ngẫu nhiên dãy Prüfer.
    
    Cần chú ý rằng thuật toán không tất định và thuật toán phụ thuộc vào tính ngẫu nhiên của dữ liệu là khác nhau. Loại trước có thể cho lời giải đúng với xác suất rất cao trên dữ liệu bất kỳ, còn loại sau đúng với phần lớn dữ liệu nhưng không thể đúng trên một số dữ liệu đặc biệt.

### Ví dụ

Ví dụ nên có độ mạnh nhất định, có thể phát hiện một số lỗi đơn giản. Người đọc sai ý đề nên có thể thông qua ví dụ để nhận ra mình đã hiểu sai.

Với bài có nhiều loại thao tác, mỗi loại thao tác đều nên xuất hiện trong ví dụ.

Với bài có nhiều loại đầu ra (như [CF1173A Nauuo and Votes](https://codeforces.com/problemset/problem/1173/A)), mỗi loại đầu ra đều nên xuất hiện trong ví dụ. Ngoại lệ: bài thực tế không thể vô nghiệm, nhưng yêu cầu phán đoán có nghiệm hay không.

### Giải thích ví dụ

Mô tả bài càng phức tạp, càng khó hiểu thì càng nên có giải thích ví dụ chi tiết.

Độ khó của bài càng đơn giản thì càng nên có giải thích ví dụ chi tiết.

Giải thích ví dụ chi tiết có thể kèm hình ảnh.

Ví dụ lớn có thể không cần giải thích.

Để quan tâm đến người có khiếm khuyết nhận biết màu sắc, tốt nhất không nên khiến màu sắc trở thành yếu tố bắt buộc để hiểu giải thích ví dụ. Có thể dùng hình màu để làm đẹp phần giải thích, nhưng nếu nhất định phải dùng màu để truyền tải thông tin cần thiết, tốt nhất không nên đồng thời dùng đỏ-vàng hoặc đỏ-xanh lá.

## Giới hạn thời gian, giới hạn bộ nhớ và điểm thành phần

Mục đích của giới hạn thời gian và giới hạn bộ nhớ là chặn các lời giải sai về độ phức tạp. Ngoài ra, chúng cũng dùng để tránh thời gian chấm quá dài; ví dụ, bài tương tác chỉ giới hạn số lần tương tác mà không giới hạn độ phức tạp thời gian cũng vẫn có giới hạn thời gian.

Vì vậy, về nguyên tắc, giới hạn thời gian nên được chọn lớn nhất có thể trong khi vẫn không để lời giải sai vượt qua.

Thông thường, giới hạn thời gian nên thỏa mãn các yêu cầu sau:

1.  Ít nhất bằng hai lần thời gian chạy của lời giải chuẩn (std) trong trường hợp xấu nhất.
2.  Nếu cuộc thi cho phép dùng Java, phải để Java có thể qua.
3.  Không nên để lời giải sai vượt qua (trừ khi thật sự không chặn được, hoặc muốn cho một loại lời giải sai nào đó qua).

Để vừa cho qua các lời giải có hằng số lớn vừa chặn được lời giải sai, thường có thể đồng thời tăng giới hạn dữ liệu và giới hạn thời gian. Nhưng cần chú ý rằng đôi khi lời giải đúng (do các vấn đề khó đoán như cache) sẽ có hằng số tăng rất lớn khi giới hạn dữ liệu tăng; lúc này tăng giới hạn dữ liệu chưa chắc đã làm tăng khoảng cách thời gian giữa lời giải đúng và lời giải sai.

Trong thể thức có điểm thành phần, còn có thể dùng các bộ dữ liệu có phân tầng, hoặc dữ liệu có giới hạn nhỏ hơn một chút, để khiến các lời giải sai tương đối tốt và lời giải đúng có hằng số lớn không qua toàn bộ, nhưng vẫn nhận được điểm thành phần khá cao.

Cần chú ý rằng khi giới hạn dữ liệu nhỏ hơn $5\cdot 10^5$, nên cân nhắc liệu có thể dùng [tối ưu bằng tập lệnh CPU](https://ouuan.github.io/post/n%E6%96%B9%E8%BF%87%E7%99%BE%E4%B8%87-%E6%9A%B4%E5%8A%9B%E7%A2%BE%E6%A0%87%E7%AE%97%E2%80%94%E2%80%94%E6%8C%87%E4%BB%A4%E9%9B%86%E4%BC%98%E5%8C%96%E7%9A%84%E5%9F%BA%E7%A1%80%E4%BD%BF%E7%94%A8) để vượt qua hay không.

Thông thường, giới hạn bộ nhớ nên đặt đủ lớn, trừ khi lời giải có độ phức tạp bộ nhớ tốt hơn thật sự rất khéo và đáng để chặn các lời giải dùng nhiều bộ nhớ. Trong trường hợp này có thể cân nhắc đặt một phần điểm với giới hạn bộ nhớ rộng hơn. Cần lưu ý rằng nếu không muốn chặn các lời giải tiêu tốn nhiều bộ nhớ, các bài về cấu trúc dữ liệu thường cần đặt giới hạn bộ nhớ lớn hơn.

> Một bài hay nên có tính tuyển chọn, có đủ độ phân hóa. Nên có ít nhất 4 mức điểm thành phần, để người mới có thể lấy điểm và người giỏi có thể thể hiện năng lực.
>
> --vfk, *Nguồn gốc tinh thần của UOJ*

Điểm thành phần thường được chia thành hai loại: giới hạn dữ liệu nhỏ hơn và tính chất đặc biệt.

Giới hạn dữ liệu nhỏ hơn thường nên được chia thành nhiều mức. Ngay cả khi chưa nghĩ ra lời giải có độ phức tạp nào đó, cũng có thể cân nhắc cho độ phức tạp ấy một mức điểm. Nói chung, để tránh kẹt hằng số, có thể đặt một mức điểm bằng một nửa dữ liệu cực hạn.

"Dữ liệu có phân tầng" tốt nhất nên được thay bằng nhiều mức điểm thành phần.

Việc đặt điểm thành phần cho tính chất đặc biệt cần tùy theo bài cụ thể. Điểm thành phần cho tính chất đặc biệt lý tưởng nên có khả năng dẫn dắt thí sinh suy nghĩ về lời giải đúng. Khác với điểm thành phần theo giới hạn dữ liệu nhỏ hơn, nếu chưa biết lời giải cho một tính chất đặc biệt nào đó, tốt nhất đừng cho tính chất ấy một mức điểm. Ví dụ: mức điểm $k=1$ của [CTS2019: Lập phương ngẫu nhiên](https://loj.ac/problem/3119) đã bị nhiều người phàn nàn khi giảng bài, cho rằng mức điểm này cản trở việc suy nghĩ lời giải đúng.

Nếu cách tính điểm của bài khác với mặc định (ví dụ: trong một cuộc thi theo thể thức OI thông thường nhưng chấm theo bài con buộc chặt), nhất định phải nói rõ trong đề.

Không khuyến nghị dùng cách nói "$XX$% dữ liệu thỏa mãn XX", đặc biệt khi giới hạn dữ liệu có nhiều biến. Ví dụ, "$30\%$ dữ liệu thỏa mãn $n \le 1000$" và "$40\%$ dữ liệu thỏa mãn $m \le 100$" có thể đang mô tả tính chất của $70\%$ dữ liệu, cũng có thể chỉ mô tả tính chất của $40\%$ dữ liệu. Nói chung, bài con (subtask) hoặc bảng giới hạn dữ liệu là lựa chọn tốt hơn.

## Tạo dữ liệu

Sinh dữ liệu là một bước cần thiết trong quá trình ra đề, cũng là điều bắt buộc khi đối chiếu chương trình. Nắm được một số kỹ thuật sinh dữ liệu sẽ giúp quá trình tạo dữ liệu nhẹ nhàng hơn và dữ liệu tạo ra có độ mạnh cao hơn.

### Sinh dữ liệu ngẫu nhiên

#### Sinh số ngẫu nhiên

Tham khảo trang [hàm ngẫu nhiên](../misc/random.md).

Cần đặc biệt nhắc rằng khi sinh một số có miền giá trị lớn hơn giá trị trả về của hàm ngẫu nhiên, **đừng** dùng cách viết như `rand() * rand()`, vì số ngẫu nhiên sinh ra theo cách này rất không đều.

Ngoài ra, khi ra đề nên dùng [Testlib](../tools/testlib/generator.md) để tạo dữ liệu. Cách này giúp cùng một hạt giống (seed) sinh ra cùng một dãy số ngẫu nhiên trên các nền tảng khác nhau, và hạt giống sẽ được tự động sinh theo tham số dòng lệnh.

#### Sinh hoán vị ngẫu nhiên

Có thể dùng hàm `std::shuffle` trong STL, dạng như `std::shuffle(a, a + n, rng)`, trong đó `rng` là một bộ sinh số ngẫu nhiên, chẳng hạn `std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count())`.

**Đừng** dùng `std::random_shuffle`; nó đã bị loại bỏ dần từ C++14 và bị xóa trong C++17.

#### Sinh đoạn ngẫu nhiên

Cách sai thường gặp: sinh ngẫu nhiên đầu trái $l$ trong $[1,n]$, rồi sinh ngẫu nhiên đầu phải $r$ trong $[l, n]$. Khi đó các đoạn được sinh sẽ thiên về bên phải.

Cách tương đối đúng (khuyến nghị): sinh ngẫu nhiên hai số trong $[1, n]$, lấy số nhỏ hơn làm đầu trái và số lớn hơn làm đầu phải.

Cách ngẫu nhiên đều thật sự: sinh một số ngẫu nhiên $x$ trong $[0, n]$; nếu $x = 0$, lại sinh một số ngẫu nhiên $y$ trong $[1, n]$, đoạn là $[y, y]$; nếu không thì sinh theo "cách tương đối đúng".

#### Sinh cây ngẫu nhiên

Cách thường dùng là với mỗi đỉnh $i$ từ $2\sim n$, chọn ngẫu nhiên một đỉnh cha trong $[1,i-1]$. Làm như vậy thì cây sinh ra không ngẫu nhiên đều, và chiều cao kỳ vọng là $O(\log n)$.

Còn một cách ngẫu nhiên khác: chọn ngẫu nhiên cha của $i$ trong $[i\cdot low, i\cdot high]$. Nếu đặt $low$ và $high$ phù hợp, có thể tạo ra cây có độ mạnh cao.

Cách ngẫu nhiên đều thật sự là dùng [dãy Prüfer](../graph/prufer.md): trước hết sinh ngẫu nhiên một dãy Prüfer, rồi sinh cây từ dãy đó. Làm như vậy thì chiều cao kỳ vọng của cây là $O(\sqrt n)$.

Ngoài ra, có thể sinh ngẫu nhiên một hoán vị để đánh lại số đỉnh hoặc xáo trộn thứ tự các cạnh.

### Dựng dữ liệu

#### Bài liên quan đến đoạn

Cấu trúc thường dùng: độ dài đặc biệt nhỏ (đặc biệt là toàn bộ đều là đoạn một điểm), độ dài đặc biệt lớn (đặc biệt là toàn bộ đều là cả dãy).

#### Bài cần phân tích thừa số

Số thừa số nguyên tố có lặp càng nhiều càng tốt: lũy thừa của $2$.

Số thừa số nguyên tố sau khi loại trùng càng nhiều càng tốt: tích của một số lượng các số nguyên tố nhỏ nhất.

Số ước càng nhiều càng tốt: có thể tham khảo dãy [A002182](http://oeis.org/A002182) trên OEIS.

#### Bài cần tìm ước chung lớn nhất

Cho hai số cần tìm ước chung lớn nhất là hai số hạng kề nhau của [dãy Fibonacci](../math/combinatorics/fibonacci.md), có thể khiến thuật toán Euclid đạt độ phức tạp thời gian xấu nhất.

#### Bài toán trên cây

Cấu trúc thường dùng:

-   Đường thẳng
-   Cây sao
-   Cây nhị phân hoàn chỉnh
-   Thay mỗi đỉnh của cây nhị phân hoàn chỉnh bằng một đường thẳng độ dài $\sqrt n$
-   Treo một đường thẳng lên cây sao
-   Treo một số đỉnh đơn lên đường thẳng
-   Một cây có chiều cao $d$ và $d>1$, gốc có hai con; cây con trái là một đường thẳng độ dài $d-1$, cây con phải là một cây cùng dạng có chiều cao $d-1$.

Nếu không phải đang ở trong phòng thi, còn có thể dùng [Tree-Generator](https://github.com/ouuan/Tree-Generator) để sinh nhiều loại cây khác nhau.

### Sinh dữ liệu hàng loạt

Người viết khuyến nghị dùng phương pháp tham số dòng lệnh + bat/sh.

Ví dụ:

`gen.cpp`:

```cpp
#include "testlib.h"

using namespace std;

int n, m, k;
vector<int> p;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  int i;

  n = atoi(argv[1]);
  m = atoi(argv[2]);
  k = rnd.next(1, n);

  for (i = 1; i <= n; ++i) p.push_back(i);

  shuffle(p.begin(), p.end());
  // Dùng rnd.next() để xáo trộn

  printf("%d %d %d\n", n, m, k);
  for (i = 0; i < n; ++i) {
    printf("%d%c", p[i], " \n"[i == n - 1]);
    // Dùng chuỗi như mảng: ở giữa là dấu cách, cuối dòng là xuống dòng;
    // đây là một mẹo thường dùng khi tạo dữ liệu
  }

  return 0;
}
```

`gen_scripts.bat`:

```bat
gen 10 10 > 1.in
gen 1 1 > 2.in
gen 100 200 > 3.in
gen 2000 1000 > 4.in
gen 100000 100000 > 5.in
```

Lợi ích của cách này là với các bộ dữ liệu khác nhau, chỉ cần viết một bộ sinh dữ liệu, đồng thời có thể sửa tham số của một bộ kiểm thử nào đó một cách thuận tiện.

### Yêu cầu đối với dữ liệu

Dữ liệu nên bao gồm giá trị nhỏ nhất và lớn nhất của từng tham số.

Dữ liệu nên bao gồm các trường hợp biên khác nhau.

Khi dùng bài con (subtask), dữ liệu (bao gồm đầu vào và đầu ra) tốt nhất nên bao phủ các khoảng khác nhau trong miền giá trị, chứ không chỉ có giá trị lớn nhất của giới hạn dữ liệu.

Để tránh lời giải xét riêng cấu trúc đặc biệt qua được, có thể kết hợp nhiều cấu trúc khác nhau trong một bộ kiểm thử, hoặc để phần lớn dữ liệu là dữ liệu dựng, xen lẫn một phần nhỏ dữ liệu ngẫu nhiên.

Dữ liệu nên bao gồm nhiều loại cấu trúc khác nhau, ngay cả khi chưa biết lời giải sai nào sẽ chết trên cấu trúc đó. (Trong thể thức tính điểm theo bộ kiểm thử cần cân nhắc xử lý.)

Nếu biết một lời giải sai về tính đúng đắn mà người bình thường có thể nghĩ ra và viết ra, nên cố gắng chặn nó.

Cần đặc biệt nhắc rằng nếu có khả năng tràn số nguyên, nhất định phải chặn các lời giải sẽ bị tràn. Trong thể thức có điểm thành phần, không nên để người không dùng long long nhận điểm bằng với brute force, thậm chí thấp hơn.

Nếu có bộ kiểm thử sơ bộ (pretests), các bộ này nên mạnh hết mức có thể (đồng thời càng ít càng tốt). Nói cách khác, cần đưa tất cả các điểm yếu đã biết của bài vào bộ kiểm thử sơ bộ bằng số lượng bộ kiểm thử ít nhất có thể.

Nếu kỳ vọng có một lượng nhỏ FST chứ không phải không có FST, vẫn cần giữ độ mạnh của bộ kiểm thử sơ bộ, vì trong cuộc thi thật rất có thể xuất hiện những lỗi ngoài dự kiến, khiến số lượng FST cao hơn dự kiến rất nhiều.

### Định dạng dữ liệu

Phần này cung cấp một số yêu cầu định dạng đầu vào thường gặp, có thể dùng làm tham khảo trong trường hợp thông thường:

> 1.  Dùng định dạng xuống dòng của môi trường chấm.
> 2.  Cuối dòng cuối cùng của tệp có ký tự xuống dòng, tức ký tự cuối cùng của toàn bộ tệp cần là `\n`.
> 3.  Đầu và cuối bất kỳ dòng nào đều không có ký tự trắng.
> 4.  Không có quá 1 dấu cách liên tiếp.

Dữ liệu sinh trong môi trường Windows thường có định dạng xuống dòng `\r\n`, trong khi các hệ thống chấm phổ biến đều chạy trên môi trường Linux, với định dạng xuống dòng `\n`. Nếu đọc dữ liệu xuống dòng kiểu Windows trong môi trường Linux, có thể khiến việc xử lý xuống dòng khi đọc xâu bị bất thường, từ đó dẫn đến kết quả chạy khác nhau giữa các môi trường. Nếu trong môi trường Linux so sánh đầu ra sinh trong môi trường Linux với đầu ra chuẩn sinh trong môi trường Windows, có thể phát sinh khác biệt do định dạng xuống dòng khác nhau. Để giữ hành vi chương trình nhất quán, định dạng xuống dòng của toàn bộ dữ liệu phải được chuyển sang định dạng xuống dòng của môi trường chạy chương trình.

Thông thường có thể sinh dữ liệu có xuống dòng kiểu Linux bằng các cách sau:

1.  Trực tiếp sinh dữ liệu trong môi trường Linux.
2.  Dùng công cụ [`dos2unix`](https://dos2unix.sourceforge.io/) để chuyển đổi tệp đầu vào/đầu ra; công cụ này có trong các bộ công cụ như Cygwin, MinGW.
3.  Mở tệp đầu ra ở chế độ nhị phân và dùng định dạng xuống dòng `\n`.
4.  Tham khảo mã `dos2unix.cpp` trong [trang này](https://help.luogu.com.cn/manual/luogu/problem/testcase-format#%E9%99%84%E5%BD%95windows-%E7%8E%AF%E5%A2%83%E4%B8%8B%E9%80%A0%E6%95%B0%E6%8D%AE%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9) để tự viết công cụ.

## Trình chấm đặc biệt

[Hướng dẫn viết SPJ](../tools/special-judge.md)

Bài yêu cầu in phương án và bài yêu cầu in số thực là hai dạng bài khá thường gặp cần dùng SPJ; các bài khác cũng có thể cần dùng SPJ tùy tình huống. Trên CF, mọi bài đều phải dùng checker dựa trên Testlib. Ví dụ: khi bài yêu cầu in một vài số nguyên, dùng checker `ncmp` có sẵn của Testlib; thí sinh có thể in ký tự trắng tùy ý (có thể là dấu cách hoặc xuống dòng).

Checker thường được viết bằng Testlib. Vì checker phải xử lý đủ loại đầu ra không hợp lệ, nó cần độ vững rất cao; nếu không dùng Testlib thì rất khó viết checker tốt.

Khi viết checker cần chú ý hai điểm sau:

1.  Cần xử lý mọi loại đầu ra không hợp lệ, vì vậy phải kiểm tra từng biến đọc vào có nằm trong phạm vi hợp lệ hay không (`readInt(minvalue, maxvalue)`). Ví dụ: khi đọc một biến sẽ được dùng làm chỉ số mảng trong quá trình kiểm tra, bắt buộc phải kiểm tra phạm vi của nó, nếu không có thể gây vượt biên mảng; đôi khi điều này dẫn đến RE, đôi khi lại có thể bị chấm là AC.
2.  Về nguyên tắc, không nên kiểm tra ký tự trắng trong checker (tức không nên dùng `readSpace()`, `readEoln()`, `readEof()`; đáng nói là Testlib sẽ tự động kiểm tra có đầu ra thừa hay không).

## Lời giải

Mục tiêu của lời giải là để tất cả những người dự kiến tham gia cuộc thi đều có thể hiểu được. Vì vậy, mức độ chi tiết yêu cầu của lời giải chính thức sẽ cao hơn lời giải thông thường.

### Về điểm thành phần

Trong các bài có điểm thành phần, có thể cân nhắc viết các cách làm cho điểm thành phần trong lời giải.

### Về kiến thức

Các kiến thức dùng trong lời giải nên được chỉ ra cụ thể. Với một số kiến thức có độ khó tương đương độ khó của bài, tốt nhất nên cung cấp tài liệu học kiến thức đó (chẳng hạn địa chỉ một bài blog).

### Về định nghĩa

Trong lời giải không nên đột ngột xuất hiện các khái niệm không được giải thích.

Ví dụ: lời giải dp phải giải thích rõ định nghĩa trạng thái.

### Về chi tiết

Nếu chi tiết cài đặt cụ thể tương đối khéo, tốt nhất nên viết ra; nếu không, viết "xem mã" cũng được. Nếu viết "xem mã", tốt nhất nên thêm một lượng chú thích nhất định trong mã.

### Lời giải chuẩn

Trong lời giải chuẩn, tốt nhất nên bỏ các phần dư thừa. Ví dụ, một số lời giải giữ lại toàn bộ mẫu và macro `define` (để tăng tốc độ làm bài, chứa rất nhiều `define` và hàm thường dùng, thường dùng trong các cuộc thi trực tuyến như CF), và phần lớn trong đó không được dùng đến; điều này là không tốt.

Nếu có liên quan đến một số chi tiết cài đặt không được giải thích kỹ trong lời giải, tốt nhất nên thêm lượng chú thích vừa phải.

## Cuộc thi

### Độ khó bài trong thông báo cuộc thi cần đúng với thực tế

> Cần nhớ rằng tác giả thường đánh giá thấp độ khó của bài mình.
>
> --Lời nhắc trên trang PROPOSE A PROBLEM của Codeforces

Người ra đề rất có thể đánh giá sai độ khó của bài. Vì vậy, nếu muốn ghi độ khó cuộc thi trong thông báo, cần cân nhắc thận trọng; tốt nhất nên mời người thử đề trước và đánh giá.

### Phân bổ độ khó của bài

Trong các kỳ thi thử kiểu OI Trung Quốc, thường chỉ cần tổng thể độ khó của ba bài tương đương với độ khó cuộc thi.

Trong các cuộc thi trực tuyến kiểu CF/ATC, cần cố gắng giữ độ khó tăng dần (mặc dù do đánh giá sai độ khó nên nhiều khi không thật sự làm được), đồng thời cố gắng tránh xuất hiện khoảng cách độ khó lớn. Có thể giảm khoảng cách độ khó bằng cách tách một bài thành hai phiên bản dễ/khó (hai bài con), nhưng việc chia bài con cần được cân nhắc thận trọng. Cũng có nhiều người không thích bài con trong thể thức CF ([Are subtasks evil?](https://codeforces.com/blog/entry/71700)), với các lý do bao gồm nhưng không giới hạn ở:

-   Do thể thức thi, làm phiên bản dễ trước rồi làm phiên bản khó có thể bị phạt thời gian ít hơn và tổng điểm cao hơn.
-   Điểm của bài con thường không tỉ lệ thuận với độ khó của bài.
-   Rất nhiều khi phiên bản dễ không phải là một bài đạt chuẩn (không thú vị).
-   Rất nhiều khi lời giải của phiên bản dễ không giúp ích cho việc nghĩ lời giải đúng của phiên bản khó.

### Phân bổ kiến thức của bài

Một cuộc thi nên cố gắng bao phủ phạm vi kiến thức tương đối rộng (tất nhiên trừ các cuộc thi luyện tập chuyên đề).

Phản ví dụ kinh điển: CTS2019, bao phủ nhiều kiến thức như quy hoạch động, kỳ vọng, đếm tổ hợp, nguyên lý bao hàm-loại trừ, đa thức, v.v.

> Tôi phải chọn sáu bài từ năm bài, tôi cũng bất lực lắm chứ.
>
> --Lý do do người phối đề CTS2019 đưa ra: không nhận đủ bài gửi đến.

## Nền tảng ra đề

### Polygon

Polygon là một nền tảng ra đề hợp tác nhiều người rất mạnh. Nó có thể là lựa chọn ưu tiên để ra đề cộng tác nhiều người cho bất kỳ trang web nào (dùng chức năng gói để xuất sang những trang web không hỗ trợ Polygon), và cũng là lựa chọn khá tốt khi ra đề một mình (đặc biệt là khi ra đề trên nhiều thiết bị khác nhau). Cách sử dụng xem [Giới thiệu Polygon](../tools/polygon.md).

### Codeforces

Codeforces là một trong những trang web thi đấu thuật toán nổi tiếng nhất thế giới, chất lượng bài tương đối cao, rất phù hợp với người ra đề đã có một ít kinh nghiệm và muốn nâng cao trình độ ra đề hơn nữa, muốn ra một bộ bài chất lượng cao. Điểm chưa thuận lợi là tốc độ duyệt khá chậm (thường mất vài tháng), nhưng cũng có thể bắt đầu chuẩn bị bài trong thời gian chờ duyệt (dù có rủi ro bài bị từ chối khiến công chuẩn bị trở nên vô ích).

#### Tư cách ra đề

-   Tên xanh lam và đã tham gia ít nhất 25 cuộc thi được tính rating;
-   Tên tím và đã tham gia ít nhất 15 cuộc thi được tính rating;
-   Tên cam và đã tham gia ít nhất 5 cuộc thi được tính rating;
-   Tên đỏ hoặc đen-đỏ.

#### Gửi đề xuất cuộc thi

Sau khi có tư cách ra đề, ở thanh bên có thể thấy nút [Propose a contest/problems](http://codeforces.com/proposals/new-contest).

Nhấn vào đó, trước hết viết một đề xuất cuộc thi (viết trong PROPOSE A CONTEST), sau đó viết đề xuất bài và thêm vào cuộc thi.

Sau khi đã quyết định xong các bài, có thể gửi đề xuất cuộc thi để xét duyệt.

#### Chuẩn bị bài trên Polygon

Tham khảo [Giới thiệu Polygon](../tools/polygon.md).

#### Liên hệ với quản trị

Liên hệ với quản trị có hai tác dụng:

1.  Đẩy nhanh tốc độ xét duyệt.
2.  Sau khi vào giai đoạn chuẩn bị, quản trị sẽ đưa ra góp ý và hỗ trợ.

Cách liên hệ chính quy là gửi đơn trong hệ thống đề xuất dưới dạng đề xuất; sau khi quản trị bắt đầu xét duyệt, thảo luận ở bên dưới đề xuất dưới dạng bình luận.

Trên thực tế, nếu đề xuất lâu không được duyệt, có thể cân nhắc nhắn tin riêng cho quản trị (thật ra trên CF có viết "Đừng gửi tin nhắn riêng hoặc email cho điều phối viên", nhưng 300iq trong [bình luận](http://codeforces.com/blog/entry/64077#comment-478933) nói rằng có thể nhắn tin riêng cho anh ấy).

### Comet OJ

[Liên kết Comet OJ](https://www.cometoj.com/)

Đã không còn hoạt động sôi nổi (tính đến tháng 11 năm 2021, cuộc thi cuối cùng là vào tháng 1 năm 2020).

Đăng ký ra đề: <https://info.cometoj.com/contests/Questionnaire_IssuerInfo/>

### CodeChef

Nền tảng thi đấu thuật toán của Ấn Độ, có ba thể thức: Long Challenge kéo dài 10 ngày và có challenge, Cook-Off kiểu ICPC 2.5h, LunchTime kiểu IOI 3h.

FAQ cho người ra đề: <https://www.codechef.com/wiki/faq-problem-setters>

Hướng dẫn ra đề: <https://www.codechef.com/problemsetting>

### AtCoder

Nền tảng thi đấu thuật toán của Nhật Bản, liên hệ ra đề: <contest@atcoder.jp>.

### UOJ & LOJ

Các OJ ở Trung Quốc không có nhiều cuộc thi.

### Luogu

Nhân sự tham gia ra đề cần có cấp chứng nhận giải thưởng nhất định; sau khi tạo cuộc thi, người phụ trách gửi yêu cầu trong [hệ thống ticket](https://www.luogu.com.cn/ticket).

Quy chuẩn cuộc thi công khai: <https://help.luogu.com.cn/rules/academic/opencontest-standard>

## Tài liệu tham khảo

1.  [vfk, *Nguồn gốc tinh thần của UOJ*][1]

2.  [Wang Tianyi, *Bàn về tác hại của đề lệch*][2]

3.  [Những điều người ra đề CF cần biết][3] ([bản ảnh có thể truy cập tại Trung Quốc](https://github.com/OI-wiki/libs/blob/master/topic/rules.jpg))

4.  [Tự tu dưỡng của người ra đề CF][4]

Bài viết này được chính tác giả chuyển sang từ [quy chuẩn ra đề của ouuan](https://ouuan.github.io/post/ouuan-%E7%9A%84%E5%87%BA%E9%A2%98%E8%A7%84%E8%8C%83/), có chỉnh sửa và bổ sung.

[1]: https://vfleaking.blog.uoj.ac/blog/909 "vfk, Nguồn gốc tinh thần của UOJ"

[2]: https://github.com/OI-wiki/libs/blob/master/topic/7-%E7%8E%8B%E5%A4%A9%E6%87%BF-%E8%AE%BA%E5%81%8F%E9%A2%98%E7%9A%84%E5%8D%B1%E5%AE%B3.ppt "Wang Tianyi, Bàn về tác hại của đề lệch"

[3]: https://docs.google.com/document/d/e/2PACX-1vRhazTXxSdj7JEIC7dp-nOWcUFiY8bXi9lLju-k6vVMKf4IiBmweJoOAMI-ZEZxatXF08I9wMOQpMqC/pub "Những điều người ra đề CF cần biết"

[4]: https://github.com/OI-wiki/libs/blob/master/topic/CF%E5%87%BA%E9%A2%98%E4%BA%BA%E7%9A%84%E8%87%AA%E6%88%91%E4%BF%AE%E5%85%BB.md "Tự tu dưỡng của người ra đề CF"
