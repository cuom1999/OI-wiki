## Dẫn nhập

Trang này liệt kê một số phương pháp tối ưu quy hoạch động (dynamic programming, DP) thường gặp. Tối ưu DP là việc dùng các kỹ thuật để giảm độ phức tạp thời gian, vì nhiều bài DP tuy dễ viết phương trình chuyển trạng thái đơn giản nhưng tính trực tiếp lại quá chậm.

Các phương pháp này có liên hệ chặt chẽ với nhau, thường chứa những ý tưởng tương tự và nhiều khi cần kết hợp nhiều kỹ thuật. Vì vậy, trang này chỉ phân loại sơ lược và tập trung giới thiệu các ý tưởng cơ bản nhất.

## Tối ưu bằng kỹ thuật thường gặp

Chuyển trạng thái của nhiều bài DP có thể được tối ưu bằng các thuật toán và cấu trúc dữ liệu quen thuộc.

Nhóm kỹ thuật này có hai tình huống phổ biến. Trong tình huống thứ nhất, bài DP có phương trình chuyển trạng thái dạng:

$$
f(i) = F(a_i,\{f(j) : j < i\}).
$$

Trong đó, việc tính trạng thái hiện tại $f(i)$ phụ thuộc vào đầu vào hiện tại $a_i$ và toàn bộ các trạng thái trước đó $\{f(j):j<i\}$. Do đó, có thể duy trì một cấu trúc dữ liệu, xem mỗi lần tính $f(i)$ như một truy vấn; sau khi nhận được trạng thái hiện tại $f(i)$, thực hiện một lần cập nhật để cấu trúc dữ liệu phục vụ các chuyển trạng thái sau.

Trong tình huống thứ hai, bài DP có phương trình chuyển trạng thái dạng:

$$
f(i,\cdot) = F(a_i,f(i-1,\cdot)).
$$

Ở đây, mỗi $f(i,\cdot)$ là một mảng hoặc một đối tượng phức tạp hơn. Vì vậy, dù $f(i,\cdot)$ chỉ phụ thuộc vào một trạng thái trước đó, một lần chuyển vẫn có độ phức tạp cao và cần tối ưu bằng cấu trúc dữ liệu hoặc kỹ thuật tương tự.

### Tối ưu DP bằng tổng tiền tố

Trang liên quan: [tổng tiền tố](../../basic/prefix-sum.md#%E5%89%8D%E7%BC%80%E5%92%8C)

Nếu việc tính trạng thái hiện tại phụ thuộc vào tổng một đoạn con của các trạng thái trước, có thể duy trì tổng tiền tố để tăng tốc. Một nhóm bài liên quan tới tổng tiền tố nhiều chiều còn được gọi là [SOS DP](../../basic/prefix-sum.md#%E7%89%B9%E4%BE%8B%E5%AD%90%E9%9B%86%E5%92%8C-dp).

Bài tập:

-   [Luogu P2513 \[HAOI2009\] Dãy số nghịch thế](https://www.luogu.com.cn/problem/P2513)
-   [AtCoder Educational DP Contest M - Candies](https://atcoder.jp/contests/dp/tasks/dp_m)

### Tối ưu DP bằng hàng đợi/ngăn xếp đơn điệu

Trang chính: [tối ưu bằng hàng đợi/ngăn xếp đơn điệu](./monotonic-queue-stack.md)

Nếu trạng thái hiện tại phụ thuộc vào thông tin như cực trị trên đoạn của các trạng thái trước, có thể duy trì hàng đợi đơn điệu hoặc ngăn xếp đơn điệu để tăng tốc.

### Tối ưu DP bằng cây phân đoạn/cây Fenwick

Trang liên quan: [cây phân đoạn](../../ds/seg.md), [cây Fenwick](../../ds/fenwick.md)

Nếu mỗi lần chuyển trạng thái đều cần truy vấn tổng, cực trị hoặc thông tin tương tự trên một đoạn, hoặc một lần cập nhật liên quan tới cập nhật đoạn, có thể duy trì cây phân đoạn hoặc cây Fenwick để tăng tốc.

Bài tập:

-   [AtCoder Educational DP Contest Q - Flowers](https://atcoder.jp/contests/dp/tasks/dp_q)
-   [AtCoder Educational DP Contest W - Intervals](https://atcoder.jp/contests/dp/tasks/dp_w)
-   [Codeforces 115 E. Linear Kingdom Races](https://codeforces.com/problemset/problem/115/E)

### Tối ưu DP bằng chia để trị CDQ

Trang chính: [tối ưu DP bằng chia để trị CDQ](../../misc/cdq-divide.md#chia-để-trị-cdq-tối-ưu-chuyển-trạng-thái-của-quy-hoạch-động-1d1d)

Tương tự phần trên, xem toàn bộ quá trình DP như một chuỗi truy vấn và cập nhật. Với một số bài, tính tuần tự có độ phức tạp quá cao; có thể đưa toàn bộ truy vấn và cập nhật về dạng offline rồi dùng chia để trị CDQ để tăng tốc.

Tối ưu DP bằng chia để trị CDQ cũng thường xuất hiện trong các nhóm bài sau:

-   [Tối ưu DP bằng độ dốc dựa trên chia để trị CDQ](./slope.md#%E4%BA%8C%E5%88%86cdq%E5%B9%B3%E8%A1%A1%E6%A0%91%E4%BC%98%E5%8C%96-dp)
-   [Chia để trị tối ưu DP có đơn điệu quyết định](./quadrangle.md#%E5%88%86%E6%B2%BB)

### Tối ưu DP bằng nhân đôi

Trang liên quan: [nhân đôi](../../basic/binary-lifting.md)

Trong một số bài, cần đặt trạng thái $f(i)$ là kết quả sau khi bắt đầu từ trạng thái ban đầu và thực hiện $2^i$ lần chuyển. Cách này dùng tư tưởng nhân đôi để biến đổi bài toán, nên thường được gọi là tối ưu DP bằng nhân đôi.

Đôi khi, các bài DP có phương trình chuyển trạng thái dạng:

$$
f(i,j) = f(i-1,f(i-1,j))
$$

cũng được gọi là DP nhân đôi hoặc DP tối ưu bằng nhân đôi.

Bài tập:

-   [Luogu P1081 \[NOIP 2012 nâng cao\] Du lịch bằng xe](https://www.luogu.com.cn/problem/P1081)
-   [Luogu P1613 Chạy đường](https://www.luogu.com.cn/problem/P1613)
-   [Luogu P4739 \[CERC2017\] Donut Drone](https://www.luogu.com.cn/problem/P4739)

## Tối ưu bằng cấu trúc của bài toán

Nhiều bài DP có các tính chất cấu trúc như tính lồi, tính đơn điệu. Khai thác hợp lý các tính chất này có thể giúp giải nhanh.

### Tối ưu DP bằng độ dốc

Trang chính: [tối ưu bằng độ dốc](./slope.md)

Tương tự các phương pháp tối ưu ở phần trước, khi khai thác tính lồi của bài toán, có thể duy trì bao lồi để tăng tốc một lần chuyển.

### Tối ưu DP bằng bất đẳng thức tứ giác

Trang chính: [tối ưu bằng bất đẳng thức tứ giác](./quadrangle.md)

Các bài DP có hàm liên quan thỏa bất đẳng thức tứ giác thường thỏa một dạng đơn điệu quyết định. Khai thác tính chất này, có nhiều phương pháp chuyên biệt để giảm độ phức tạp. Các kiểu bài thường gặp gồm bài toán đơn điệu quyết định một chiều, bài toán chia đoạn, bài toán gộp đoạn, v.v.

### Tối ưu DP bằng Slope Trick

Trang chính: [Slope Trick](./slope-trick.md)

Trong một số bài, hiệu sai phân của hàm trạng thái (tức độ dốc) dễ duy trì hơn trong quá trình chuyển trạng thái. Kiểu tối ưu này cũng thường cần bài toán có tính lồi.

### WQS nhị phân / tối ưu DP lồi

Trang chính: [WQS nhị phân](./wqs-binary-search.md)

Với các bài DP tối ưu hóa có ràng buộc về số lượng, nếu bỏ qua ràng buộc số lượng thì bài toán dễ giải hơn, và giá trị tối ưu là một hàm lồi theo ràng buộc đó, có thể dùng WQS nhị phân để đơn giản hóa tính toán.

## Tối ưu bằng phương pháp toán học

Chuyển trạng thái của nhiều bài DP có thể được tăng tốc bằng công cụ toán học.

### Tối ưu DP bằng lũy thừa ma trận nhanh

Trang liên quan: [lũy thừa nhanh](../../math/binary-exponentiation.md)

Nếu phương trình chuyển trạng thái của bài DP có thể viết ở dạng tự trị:

$$
f(i) = F(f(i-1)),
$$

tức trạng thái hiện tại $f(i)$ chỉ phụ thuộc vào trạng thái trước $f(i-1)$, không phụ thuộc vào đầu vào khác, thì có thể trực tiếp dùng lũy thừa nhanh để tính:

$$
f(n) = F^n(f(0))
$$

và thu được đáp án cuối. Vì một thao tác $F$ thường có thể viết dưới dạng ma trận, phương pháp này thường được gọi là tối ưu DP bằng lũy thừa ma trận nhanh. Trên thực tế, mọi phép biến đổi thỏa tính kết hợp (tức mọi phần tử trong một [monoid](../../math/algebra/basic.md#%E7%BE%A4)) đều có thể dùng phương pháp này để tăng tốc.

Bài tập:

-   [Luogu P1397 \[NOI2013\] Trò chơi ma trận](https://www.luogu.com.cn/problem/P1397)
-   [Luogu P3176 \[HAOI2015\] Tách chuỗi số](https://www.luogu.com.cn/problem/P3176)
-   [Codeforces 576 D. Flights for Regular Customers](https://codeforces.com/problemset/problem/576/D)
-   [Luogu P6772 \[NOI2020\] Người sành ăn](https://www.luogu.com.cn/problem/P6772)

### Tối ưu DP bằng FFT

Trang liên quan: [FFT](../../math/poly/fft.md)

Nếu phương trình chuyển trạng thái của bài DP có dạng tích chập, có thể cân nhắc dùng FFT để tăng tốc chuyển. Tùy bài cụ thể, cũng có thể cần các kỹ thuật đa thức khác.

Bài tập:

-   [Codeforces 553 E. Kyoya and Train](https://codeforces.com/contest/553/problem/E)
-   [Codeforces 1784 D. Wooden Spoon](https://codeforces.com/problemset/problem/1784/D)

### Tối ưu DP bằng nội suy Lagrange

Trang liên quan: [nội suy Lagrange](../../math/numerical/interp.md#lagrange-%E6%8F%92%E5%80%BC%E6%B3%95)

Trong một số bài DP, hàm trạng thái $f(i,j)$ là đa thức bậc $k$ theo $j$. Khi đó có thể tính trực tiếp giá trị của nó tại $k+1$ điểm, rồi dùng nội suy Lagrange để tìm biểu thức của $f(i,\cdot)$, từ đó tối ưu chuyển trạng thái hoặc thậm chí trực tiếp lấy đáp án.

Bài tập:

-   [Luogu P5223 Function](https://www.luogu.com.cn/problem/P5223)
-   [Luogu P4463 \[Kiểm tra chéo đội tuyển 2012\] calc](https://www.luogu.com.cn/problem/P4463)
-   [Luogu P5469 \[NOI2019\] Robot](https://www.luogu.com.cn/problem/P5469)

## Tối ưu bằng cách đơn giản hóa trạng thái

Bên cạnh tối ưu chuyển trạng thái, cũng có thể giảm độ phức tạp bằng cách đơn giản hóa trạng thái.

### DP lồng DP và tối thiểu hóa DFA

Trang chính: [DP lồng DP](../dp-of-dp.md), [tối thiểu hóa DFA](../../misc/fsm.md#tối-thiểu-hóa-dfa)

Một số bài DP có hàm trạng thái dạng $f(i,x)$, nhưng bản thân chuyển trạng thái của $x$ khá phức tạp, thậm chí có thể phụ thuộc vào một bài DP khác. Với kiểu bài này, có thể trước hết xây dựng tự động hóa cho chuyển trạng thái của $x$, dùng tối thiểu hóa DFA để giảm số trạng thái, rồi thực hiện DP bên ngoài.

### Tối ưu DP bằng thiết kế trạng thái

Trang chính: [tối ưu bằng thiết kế trạng thái](./state.md)

Một số bài đặc biệt có thể giảm mạnh số trạng thái bằng cách thiết kế trạng thái khéo léo.

## Đọc thêm

-   [Tổng hợp các phương pháp tối ưu DP by Alex Wei](https://www.cnblogs.com/alex-wei/p/DP_Involution.html)
