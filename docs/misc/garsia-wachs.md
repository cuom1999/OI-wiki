## Giới thiệu

**Thuật toán Garsia–Wachs** (Garsia–Wachs Algorithm) là một thuật toán hiệu quả để máy tính xây dựng **cây tìm kiếm nhị phân tối ưu** và **mã Huffman chữ cái** trong **thời gian tuyến tính**. Thuật toán được đặt theo tên Adriano Garsia và Michelle L. Wachs, những người đã công bố bài báo liên quan vào năm 1977.

## Mô tả bài toán

Cho một số nguyên $n$. Với $n+1$ trọng số không âm $w_{0},w_{1},\dots ,w_{n}$, cần xây dựng một cây nhị phân có gốc, trong đó cả $n$ nút trong đều có đúng hai nút con. Điều này có nghĩa là cây có $n+1$ lá. Dãy đầu vào gồm $n+1$ phần tử được ánh xạ theo thứ tự các nút lá của cây. Mục tiêu là tìm, trong mọi cấu trúc cây có thể có với $n$ nút trong, một cây sao cho tổng có trọng số của độ dài đường đi ngoài từ gốc đến từng lá là nhỏ nhất.

### Cây tìm kiếm nhị phân tối ưu

Bài toán này có thể được hiểu là bài toán xây dựng cây tìm kiếm nhị phân cho $n$ khóa đã sắp thứ tự, với giả thiết rằng cây chỉ được dùng để tìm các giá trị không tồn tại trong cây. Khi đó, $n$ khóa chia không gian giá trị cần tìm thành $n+1$ khoảng, và trọng số của một khoảng có thể xem là xác suất giá trị cần tìm rơi vào khoảng đó. Tổng có trọng số của độ dài đường đi ngoài kiểm soát thời gian tìm kiếm kỳ vọng.

### Mã Huffman chữ cái

Bài toán này cũng có thể dùng để xây dựng mã Huffman. Đây là cách mã hóa tường minh $n+1$ giá trị cho trước bằng các dãy nhị phân có độ dài thay đổi. Theo cách hiểu này, mã của một giá trị được xác định bởi dãy bước trái và phải trên đường đi từ gốc đến lá trong cây, chẳng hạn trái là $0$ và phải là $1$. Khác với mã Huffman chuẩn, mã Huffman được xây dựng theo cách này có thứ tự chữ cái, tức là thứ tự sắp xếp của các mã nhị phân giống với thứ tự đầu vào của các giá trị. Nếu trọng số của một giá trị là tần suất của nó trong thông điệp được mã hóa, thì đầu ra của thuật toán Garsia–Wachs là một bộ mã Huffman có thứ tự chữ cái giúp nén độ dài thông điệp xuống nhỏ nhất.

## Quy trình

Thuật toán Garsia–Wachs thường gồm ba giai đoạn:

1.  Xây dựng một cây nhị phân có các giá trị nằm ở lá, lưu ý rằng thứ tự có thể chưa đúng.
2.  Tính khoảng cách từ gốc đến từng lá trong cây.
3.  Xây dựng một cây nhị phân khác có cùng khoảng cách tới các lá, nhưng thứ tự lá đúng.

![](./images/garsia-wachs.png)

Như hình trên, ở giai đoạn đầu, thuật toán xây dựng cây nhị phân bằng cách tìm các bộ ba không có thứ tự trong dãy đầu vào để gộp lại (bên trái), rồi xuất ra cây nhị phân đã sắp thứ tự đúng, trong đó chiều cao các lá giống như ở cây kia.

Nếu thêm hai giá trị lính canh $\infty$ (hoặc bất kỳ giá trị hữu hạn đủ lớn nào) vào đầu và cuối dãy đầu vào, giai đoạn đầu của thuật toán sẽ thuận tiện hơn khi mô tả. Vì vậy, khi dùng thuật toán Garsia–Wachs trong lời giải thi đấu, với một mảng $\mathit{num}$ có độ dài $n$, thường định nghĩa $\mathit{num}[0] = \mathit{num}[n+1] = \infty$.

Giai đoạn đầu duy trì một rừng gồm các cây một nút, ban đầu được tạo cho từng trọng số đầu vào không phải lính canh (non-sentinel). Mỗi cây gắn với một giá trị là tổng trọng số các lá của nó, còn mỗi trọng số đầu vào không phải lính canh tạo thành một nút cây. Để duy trì dãy các giá trị này, mỗi đầu dãy có một giá trị lính canh. Dãy ban đầu chính là dãy trọng số lá theo thứ tự đầu vào. Sau đó lặp lại các bước sau, mỗi bước làm giảm độ dài dãy đầu vào, cho đến khi chỉ còn một cây chứa tất cả lá:

-   Tìm ba giá trị trọng số liên tiếp đầu tiên $x$, $y$, $z$ trong dãy sao cho $x \leq z$. Vì giá trị lính canh ở cuối dãy lớn hơn hai giá trị hữu hạn bất kỳ đứng trước nó, nên luôn tồn tại một bộ ba như vậy.
-   Loại $x$ và $y$ khỏi dãy, rồi tạo một nút cây mới làm cha của các nút $x$ và $y$, có giá trị $x+y$.
-   Chèn lại nút mới vào bên phải giá trị gần $x$ nhất, nằm trước vị trí ban đầu của $x$, và có giá trị lớn hơn hoặc bằng $x+y$. Do có lính canh bên trái, vị trí như vậy luôn tồn tại.

Để cài đặt giai đoạn này hiệu quả, thuật toán có thể duy trì dãy giá trị hiện tại trong bất kỳ cấu trúc cây tìm kiếm nhị phân cân bằng nào. Cấu trúc như vậy cho phép loại bỏ $x$ và $y$, rồi chèn lại nút cha mới của chúng trong thời gian logarit. Ở mỗi bước, các trọng số tại chỉ số chẵn cho đến giá trị $y$ trong mảng tạo thành một dãy giảm, và các trọng số tại chỉ số lẻ tạo thành một dãy giảm khác. Vì vậy, vị trí chèn lại $x+y$ có thể được tìm bằng cách thực hiện hai lần tìm kiếm nhị phân trên cây cân bằng trong hai dãy giảm này, với thời gian logarit. Bằng cách tìm kiếm tuần tự tuyến tính bắt đầu từ giá trị $z$ của bộ ba trước đó, có thể tìm vị trí đầu tiên thỏa $x \leq z$ với tổng độ phức tạp tuyến tính.

Chứng minh cho giai đoạn thứ ba của thuật toán Garsia–Wachs, tức là chứng minh tồn tại một cây khác có cùng các khoảng cách và cây đó cho nghiệm tối ưu của bài toán, là phần quan trọng. Tuy nhiên, vì có nhiều cách chứng minh và chúng khá phức tạp, phần này được lược bỏ trong bài viết này. Với giả thiết giai đoạn thứ ba là đúng, giai đoạn thứ hai và thứ ba đều có thể cài đặt trong thời gian tuyến tính. Do đó, trên dãy đầu vào độ dài $n$, tổng độ phức tạp thời gian của thuật toán Garsia–Wachs là $O(n\log n)$.

## Ứng dụng

Gói [garsia-wachs](https://hackage.haskell.org/package/garsia-wachs) của ngôn ngữ lập trình hàm Haskell cung cấp một cài đặt hàm cho thuật toán Garsia–Wachs. Nó chủ yếu được dùng để xây dựng bảng tìm kiếm tối ưu, hoặc cân bằng cấu trúc dữ liệu [rope](https://hackage.haskell.org/package/rope) với độ phức tạp tối ưu.

???+ note "Ghi chú"
    **rope** là công cụ trong Haskell dùng để thao tác bytestring có chú thích tùy chọn, dựa trên [finger tree](../ds/finger-tree.md).

## Bài tập ví dụ

???+ note "[POJ 1738 An old Stone Game](http://poj.org/problem?id=1738)"
    Có một trò chơi xếp đá cổ. Khi trò chơi bắt đầu, người chơi xếp $n$ ($1 \leq n \leq 50000$) đống đá thành một hàng. Mục tiêu là gộp các đống đá thành một đống duy nhất, theo quy tắc sau: ở mỗi bước, người chơi có thể gộp hai đống kề nhau thành một đống mới. Điểm nhận được là tổng số viên đá trong đống mới. Cần tính giá trị nhỏ nhất của tổng điểm.

??? note "Ý tưởng lời giải"
    Bài toán gộp đá là bài toán kinh điển, thường có thể giải bằng DP đoạn. Nhưng khi dữ liệu rất lớn, chẳng hạn $n$ ($1 \leq n \leq 50000$) trong bài này, dùng thuật toán Garsia–Wachs sẽ hiệu quả hơn: bước đầu, khởi tạo một mảng $\mathit{num}[n]$ kích thước $n$, trong đó $\mathit{num}[0] = \mathit{num}[n+1] = \infty$. Bước hai, mỗi lần tìm chỉ số nhỏ nhất $i$ sao cho $\mathit{num}[i-1] \leq \mathit{num}[i+1]$, rồi gộp $\mathit{num}[i-1], \mathit{num}[i]$ thành $\mathit{temp}$; tìm chỉ số lớn nhất $j$ ở phía trước sao cho $\mathit{num}[j] > \mathit{temp}$, rồi chuyển $\mathit{temp}$ ra sau $j$. Lặp lại bước này cho đến khi số đống còn lại là $1$.
    Về yêu cầu mỗi lần chỉ được gộp hai đống đá kề nhau, vì $\mathit{num}[j]\geq \mathit{num}[i-1] + \mathit{num}[i]$, có thể xem đoạn từ $\mathit{num}[j+1]$ đến $\mathit{num}[i-2]$ như một khối $\mathit{num}[mid]$, nên $\mathit{sum}$ sẽ được gộp trước. Vì vậy không vi phạm yêu cầu của đề bài.

???+ note "[ATCODER N-Slimes](https://atcoder.jp/contests/dp/tasks/dp_n)"
    $N$ slime xếp thành một hàng. Ban đầu, slime thứ $i$ từ bên trái có kích thước $a_{i}$. Taro cố gắng gộp tất cả slime thành một slime lớn hơn. Taro lặp lại thao tác sau cho đến khi chỉ còn một slime:
    Chọn hai slime kề nhau và gộp chúng thành một slime mới. Kích thước của slime mới là $x+y$, trong đó $x$ và $y$ là kích thước của hai slime trước khi gộp. Bước này phát sinh chi phí $x+y$. Quan hệ vị trí của các slime không thay đổi khi gộp. Cần tìm tổng chi phí nhỏ nhất có thể phát sinh.

## Tài liệu tham khảo và đọc thêm

1.  [Thuật toán Garsia–Wachs - Wikipedia](https://en.wikipedia.org/wiki/Garsia%E2%80%93Wachs_algorithm)
2.  [Data.Algorithm.GarsiaWachs - Hackage Haskell](https://hackage.haskell.org/package/garsia-wachs-1.2/docs/Data-Algorithm-GarsiaWachs.html)
3.  [garsia-wachs: cài đặt hàm của thuật toán Garsia–Wachs](https://hackage.haskell.org/package/garsia-wachs)
4.  [Giá trị canh gác - Wikipedia](https://en.wikipedia.org/wiki/Sentinel_value)
5.  [Một chứng minh mới cho thuật toán Garsia–Wachs](https://www.sciencedirect.com/science/article/abs/pii/0196677488900090)
