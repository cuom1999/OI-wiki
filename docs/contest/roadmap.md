???+ note "Gợi ý"
    Bài viết này đang được chỉnh sửa và thảo luận; mọi bổ sung về lộ trình học nâng cao hơn hoặc ý kiến trong phần bình luận đều được hoan nghênh!

Bài viết này sẽ giới thiệu lộ trình học lập trình thi đấu.

Lộ trình này vừa là hướng dẫn cho người mới học kiến thức lập trình thi đấu, vừa là một danh sách ôn tập.

## 1 Nền tảng ngôn ngữ C++

Nên bắt đầu từ cú pháp C++, từng bước một.

### 1.1 Hello, World!

Bước đầu của hành trình lập trình thi đấu là một dòng `Hello, World!`.

Đồng thời, cần tìm hiểu khung cơ bản của một chương trình nguồn C++.

-   [Hello, World!](../lang/helloworld.md)
-   [Nền tảng cú pháp C++](../lang/basic.md)

### 1.2 Biến và phép toán

Mục đích ban đầu của máy tính khi ra đời là tính toán. Vì vậy, trước hết cần học cách hoàn thành một số nhiệm vụ tính toán đơn giản.

-   [Biến](../lang/var.md)
-   [Phép toán](../lang/op.md)

### 1.3 Điều khiển luồng

#### 1.3.1 Cấu trúc rẽ nhánh

Đôi khi cần chọn thực hiện các câu lệnh khác nhau trong những điều kiện khác nhau; khi đó cần dùng đến câu lệnh rẽ nhánh.

-   [Rẽ nhánh](../lang/branch.md)

Câu lệnh rẽ nhánh gồm các loại sau:

-   câu lệnh if
-   câu lệnh if-else
-   câu lệnh if-elif-else
-   câu lệnh switch

#### 1.3.2 Cấu trúc vòng lặp

Khi cần lặp lại một số câu lệnh nhiều lần, câu lệnh vòng lặp sẽ được dùng.

-   [Vòng lặp](../lang/loop.md)

Câu lệnh vòng lặp gồm các loại sau:

-   câu lệnh for
-   câu lệnh while
-   câu lệnh do-while

### 1.4 Mảng và struct

Mảng dùng để lưu trữ lượng lớn dữ liệu cùng kiểu. Struct có thể gộp nhiều biến lại với nhau.

-   [Mảng](../lang/array.md)
-   [Struct](../lang/struct.md)

### 1.5 Hàm và đệ quy

Dùng hàm để mô-đun hóa chương trình và giảm chi phí cài đặt.

Đệ quy là một ngưỡng khó với người mới. “Tự gọi chính mình” nghe có vẻ không dễ hiểu, nhưng xét kỹ bản chất thì “tự gọi chính mình” và “gọi người khác” không có khác biệt căn bản.

-   [Hàm](../lang/func.md)
-   [Đệ quy & chia để trị](../basic/divide-and-conquer.md)

## 2 CSP-J mức nhập môn

### 2.1 Liệt kê và mô phỏng

Đến giai đoạn này, người học đã có thể dùng C++ để hoàn thành một số nhiệm vụ đơn giản, nhưng như vậy còn xa mới đủ.

Để làm đúng một số bài đơn giản, cần học cách cài đặt mã bằng cách liệt kê hoặc mô phỏng logic trong đầu. Cách này trông không hiệu quả lắm, nhưng đôi khi rất hữu dụng.

-   [Liệt kê](../basic/enumerate.md)
-   [Mô phỏng](../basic/simulate.md)

### 2.2 Đệ quy và chia để trị

Đệ quy là phương pháp trong đó định nghĩa của hàm liên tục gọi chính hàm đó; còn chia để trị là thao tác liên tục phân rã một bài toán thành nhiều bài toán con, giải chúng rồi hợp nhất kết quả.

-   [Đệ quy & chia để trị](../basic/divide-and-conquer.md)

### 2.3 Xâu

Khi làm bài Tin học, một kiểu dữ liệu thường gặp là xâu; người học cần nắm một số hàm STL dùng để thao tác trên xâu. Mô phỏng cũng là một cách tốt để giải các bài về xâu.

-   [Nền tảng xâu](../string/basic.md)
-   [Hàm STL](../string/lib-func.md)

### 2.4 Sắp xếp

Khi có một nhóm dữ liệu, làm thế nào để biến chúng từ không có thứ tự thành có thứ tự cũng là một vấn đề rất quan trọng. Khi chưa có ý tưởng, có thể cân nhắc sắp xếp mảng. Đây cũng là nền tảng cho nhiều thuật toán tiếp theo.

Số lượng phương pháp sắp xếp khá nhiều, nhưng sau khi hiểu thì việc ghi nhớ chúng không quá nặng.

-   [Giới thiệu về sắp xếp](../basic/sort-intro.md)
-   [Sắp xếp chọn](../basic/selection-sort.md)
-   [Sắp xếp nổi bọt](../basic/bubble-sort.md)
-   [Sắp xếp chèn](../basic/insertion-sort.md)
-   [Sắp xếp đếm](../basic/counting-sort.md)
-   [Sắp xếp cơ số](../basic/radix-sort.md)
-   [Sắp xếp nhanh](../basic/quick-sort.md)
-   [Sắp xếp trộn](../basic/merge-sort.md)
-   [Sắp xếp vun đống](../basic/heap-sort.md)
-   [Sắp xếp thùng](../basic/bucket-sort.md)
-   [STL liên quan đến sắp xếp](../basic/stl-sort.md)

Trong đề cương NOI, mức nhập môn chỉ yêu cầu học sắp xếp chọn, sắp xếp nổi bọt và sắp xếp chèn, tổng cộng ba thuật toán sắp xếp; nhưng các thuật toán còn lại cũng không quá khó và có thể xuất hiện trong vòng sơ khảo, nên được liệt kê cùng.

### 2.5 Tìm kiếm nhị phân và nhân đôi

Tìm kiếm nhị phân về bản chất là áp dụng tư tưởng chia để trị, liên tục thu hẹp phạm vi tìm kiếm cho đến khi tìm được đáp án. Tuy nhiên cần lưu ý rằng cách tìm này phải được áp dụng trên cấu trúc dữ liệu có thứ tự.

-   [Tìm kiếm nhị phân](../basic/binary.md)

Nhân đôi thì khác: nó liên tục tăng gấp đôi để chuyển việc xử lý trong phạm vi tuyến tính thành cấp logarit, nhờ đó tối ưu mạnh độ phức tạp thời gian. (Kiến thức này cần một chút nền tảng toán học; tạm thời bỏ qua cũng không sao)

-   [Nhân đôi](../basic/binary-lifting.md)

### 2.6 Tìm kiếm

Ở nhóm nhập môn, bài tìm kiếm thường xuất hiện trong các bài kiểu mê cung, thường có dữ liệu dạng bản đồ. Ngoài ra, tìm kiếm cũng rất hay được dùng để liệt kê hiệu quả các trường hợp xây dựng nghiệm hợp lệ, và cũng có thể dùng để lấy một phần điểm.

#### 2.6.1 Tìm kiếm theo chiều sâu (DFS)

Tìm kiếm theo chiều sâu là thuật toán dùng hàm đệ quy để cài đặt vét cạn một cách thuận tiện. Nó có một số điểm tương tự với thuật toán DFS trong lý thuyết đồ thị, nhưng không hoàn toàn giống nhau.

-   [DFS (tìm kiếm)](../search/dfs.md)

#### 2.6.2 Tìm kiếm theo chiều rộng (BFS)

Thiết kế mỗi trạng thái thành một đỉnh trong đồ thị, từ đó có thể mở rộng tìm kiếm theo kiểu trải đều.

-   [BFS (tìm kiếm)](../search/bfs.md)

#### 2.6.3 Tối ưu tìm kiếm

Nhiều bài có thể giải bằng DFS, nhưng độ phức tạp của thuật toán này thường vượt quá giới hạn. Vì vậy cần một số tối ưu để nó chạy nhanh hơn. Những tối ưu như vậy có thể giảm các thử nghiệm không có khả năng thành công, gọi là “cắt tỉa”. Tối ưu liên quan đến BFS linh hoạt hơn, nhưng tư tưởng cơ bản cũng tương tự.

-   [Tối ưu cắt tỉa DFS](../search/opt.md)

### 2.7 Nhập môn cấu trúc dữ liệu

#### 2.7.1 Cấu trúc dữ liệu tuyến tính

Mảng, danh sách liên kết, hàng đợi và ngăn xếp đều là cấu trúc tuyến tính. Khéo dùng các cấu trúc này có thể làm được nhiều việc thuận tiện.

-   [Ngăn xếp](../ds/stack.md)
-   [Hàng đợi](../ds/queue.md)
-   [Danh sách liên kết](../ds/linked-list.md)

#### 2.7.2 Cấu trúc dữ liệu phức tạp

-   [Cây và cây nhị phân](../graph/tree-basic.md)
-   [Khái niệm đồ thị](../graph/concept.md)
-   [Lưu trữ đồ thị](../graph/save.md)

### 2.8 Nhập môn quy hoạch động

Quy hoạch động (Dynamic Programming, DP) là phương pháp giải các bài toán phức tạp bằng cách phân rã bài toán gốc thành những bài toán con đơn giản hơn.

Vì quy hoạch động không phải một thuật toán cụ thể mà là một phương pháp giải một lớp bài toán nhất định, nó sẽ xuất hiện trong đủ loại cấu trúc dữ liệu, và các dạng bài liên quan cũng phức tạp hơn.

-   [Giới thiệu quy hoạch động](../dp/index.md)

#### 2.8.1 Bài toán cái túi

Tức là cho một chiếc túi có sức chứa hữu hạn, chọn đưa vào một số vật phẩm có kích thước và giá trị, rồi tìm cách đặt sao cho tổng giá trị lớn nhất. Đây là ngưỡng khó đầu tiên cản trở nhiều OIer; từ đây trở đi, thuật toán bắt đầu có phần khó hiểu.

-   [DP cái túi](../dp/knapsack.md)

#### 2.8.2 Quy hoạch động tuyến tính

Trong quy hoạch động, một trong những phần khó nhất là thiết kế trạng thái, cần dùng các kỹ thuật liên quan đến xây dựng. Sau khi viết được trạng thái và công thức chuyển trạng thái, hoàn thành một bài quy hoạch động sẽ không còn quá khó.

-   [Xây dựng](../basic/construction.md)
-   [Nền tảng quy hoạch động](../dp/basic.md)

Tìm kiếm có nhớ là cách cài đặt tìm kiếm ghi lại thông tin của các trạng thái đã duyệt, nhờ đó tránh duyệt lặp lại cùng một trạng thái. Một số bài cũng có thể dùng tìm kiếm có nhớ để giảm độ khó tư duy.

Vì tìm kiếm có nhớ bảo đảm mỗi trạng thái chỉ được truy cập một lần, nó cũng là một cách cài đặt quy hoạch động thường gặp.

-   [Tìm kiếm có nhớ](../dp/memo.md)

#### 2.8.3 Quy hoạch động phức tạp

Quy hoạch động theo đoạn là mở rộng của quy hoạch động tuyến tính. Khi phân chia bài toán theo giai đoạn, nó có liên hệ rất lớn với thứ tự xuất hiện của các phần tử trong giai đoạn và việc chúng được hợp nhất từ những phần tử nào của giai đoạn trước.

-   [DP đoạn](../dp/interval.md)

### 2.9 Toán học

#### 2.9.1 Thuật toán độ chính xác cao

Nếu ngay cả long long (hoặc int64) vẫn không đủ thì sao? Dùng thuật toán độ chính xác cao. Về bản chất, đó là mô phỏng bốn phép toán số học.

-   [Tính toán độ chính xác cao](../math/bignum.md)

#### 2.9.2 Chuyển đổi cơ số

Trong máy tính, ngoài hệ nhị phân, các hệ thường dùng còn có hệ bát phân và hệ thập lục phân. Đôi khi biết áp dụng đúng hệ cơ số cũng giúp ích rất nhiều cho việc giải bài.

-   [Hệ cơ số](../math/numeral-sys/base.md)

#### 2.9.3 Thao tác bit

Thao tác bit là các phép toán dựa trên biểu diễn nhị phân của số nguyên. Vì bên trong máy tính dữ liệu được lưu trữ bằng nhị phân, thao tác bit khá nhanh.

Các thao tác bit cơ bản có 6 loại: AND bit, OR bit, XOR bit, NOT bit, dịch trái và dịch phải.

-   [Thao tác bit](../math/bit.md)

#### 2.9.4 Lý thuyết số

-   [Nền tảng lý thuyết số](../math/number-theory/basic.md)
-   [Số nguyên tố](../math/number-theory/prime.md)
-   [Sàng](../math/number-theory/sieve.md)
-   [Ước chung lớn nhất](../math/number-theory/gcd.md)
-   [Hàm Euler](../math/number-theory/euler-totient.md)
-   [Phân tích thừa số nguyên tố](../math/number-theory/pollard-rho.md)

#### 2.9.5 Đếm tổ hợp

-   [Hoán vị và tổ hợp](../math/combinatorics/combination.md)
-   [Nguyên lý Dirichlet](../math/combinatorics/drawer-principle.md)
-   [Nguyên lý bao hàm - loại trừ](../math/combinatorics/inclusion-exclusion-principle.md)

***

Đến đây, người học đã hoàn thành toàn bộ các thuật toán trong phạm vi nhóm nhập môn, nhưng để nắm vững chúng, cần tiếp tục làm đủ nhiều bài để củng cố các kiến thức đã học.
