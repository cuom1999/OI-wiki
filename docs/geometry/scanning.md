## Dẫn nhập

Đường quét thường được dùng trong các bài toán hình học. Ý nghĩa của nó khá giống tên gọi: có một đường thẳng quét qua lại trên toàn bộ hình. Kỹ thuật này thường được dùng để giải các bài toán về diện tích hình, chu vi hình và đếm điểm hai chiều.

## Bài toán diện tích hợp hình chữ nhật hai chiều

Trên hệ tọa độ hai chiều, cho tọa độ góc trái dưới và góc phải trên của nhiều hình chữ nhật. Cần tính diện tích hình tạo bởi hợp của tất cả các hình chữ nhật.

### Quá trình

Từ hình vẽ, với dữ liệu nhỏ, tổng diện tích có thể được tính trực tiếp bằng vét cạn. Khi dữ liệu lớn, cần dùng thuật toán **đường quét**.

Xét một đường thẳng bắt đầu quét từ dưới lên:

![](./images/scanning.svg)

Như hình vẽ, toàn bộ hình chữ nhật được chia thành các hình chữ nhật nhỏ có màu khác nhau. Chiều cao của mỗi hình chữ nhật nhỏ là khoảng cách mà đường quét đã đi qua, còn chiều rộng theo phương ngang của hình chữ nhật thì luôn thay đổi.

Đánh dấu cạnh dưới và cạnh trên của mỗi hình chữ nhật: cạnh dưới có nhãn 1, cạnh trên có nhãn -1. Mỗi khi gặp một cạnh ngang, cộng trọng số của cạnh đó trên đoạn chiếu của cạnh lên trục hoành với nhãn của cạnh.

???+ note "Ghi chú"
    Thao tác này giống như duyệt một dãy ngoặc: gặp ngoặc mở thì cộng 1, gặp ngoặc đóng thì trừ 1. "Trọng số" tương ứng với độ sâu tại vị trí hiện tại; việc "trọng số" có lớn hơn 0 hay không tương ứng với việc hiện tại có đang nằm trong cặp ngoặc hay không, tức đoạn này có được tính vào chiều rộng của hình chữ nhật nhỏ hay không.

Chiều rộng của hình chữ nhật nhỏ, không nhất thiết chỉ có một hình, chính là tổng độ dài các đoạn trên toàn trục số có trọng số lớn hơn 0.

### Cài đặt

Dùng cây đoạn để duy trì độ dài của hình chữ nhật, tức các điểm trên toàn trục số có số lần phủ lớn hơn 0. Các yêu cầu cần hỗ trợ như sau:

-   Cộng 1 hoặc trừ 1 cho trọng số của một đoạn.
-   Thống kê trên toàn trục số "tổng độ dài các đoạn" có trọng số lớn hơn 0.

Nếu cài đặt trực tiếp bằng mẫu cây đoạn thông thường, sẽ có một vài vướng mắc. Cụ thể, khi cộng trên đoạn, ngay cả khi đoạn sửa đổi trùng với đoạn mà một nút quản lý, vẫn không thể biết số lần phủ thay đổi như thế nào trong thời gian hằng số. Lý do là không thể biết trực tiếp trong phạm vi quản lý có tổng độ dài bao nhiêu sẽ chuyển từ 1 thành 0 hoặc từ 0 thành 1.

Bài này chỉ cần chia để trị đơn giản là cài đặt được: tại mỗi nút, duy trì hai thông tin là "số lần phủ hoàn toàn đoạn `v[]`", tương tự một thẻ lười không cần đẩy xuống, và "độ dài đã được phủ `w[]`".

Cần [rời rạc hóa](../misc/discrete.md).

??? note "[Luogu P5490 Mẫu: quét đường thẳng và diện tích hợp các hình chữ nhật](https://www.luogu.com.cn/problem/P5490) mã tham khảo"
    ```cpp
    --8<-- "docs/geometry/code/scanning/scanning_1.cpp"
    ```

??? note "[POJ 1151 Atlantis](http://poj.org/problem?id=1151) mã tham khảo"
    ```cpp
    --8<-- "docs/geometry/code/scanning/scanning_2.cpp"
    ```

### Luyện tập

-   [POJ 1177 Picture](http://poj.org/problem?id=1177)
-   [POJ 3832 Posters](http://poj.org/problem?id=3832)
-   [Luogu P1856 IOI 1998 USACO 5.5 Rectangle Perimeter Picture](https://www.luogu.com.cn/problem/P1856)
    -   Đóng góp của cạnh ngang chính là độ biến thiên của độ dài được phủ.
    -   Tính riêng theo hai hướng có thể tránh phải thảo luận cạnh thẳng đứng.
    -   Khi sắp xếp các thao tác, cần xử lý trường hợp cạnh của hai hình chữ nhật trùng nhau.
    -   Phạm vi dữ liệu cho phép không dùng cây đoạn, mà mô phỏng trực tiếp trong thời gian bình phương.

## Phạm vi trực giao B chiều

Phạm vi trực giao B chiều là tập điểm bên trong một hệ tọa độ vuông góc B chiều, trong đó tọa độ chiều thứ $i$ nằm trong một khoảng nguyên $[l_i,r_i]$.

Thông thường, phạm vi trực giao một chiều gọi tắt là đoạn, phạm vi trực giao hai chiều gọi tắt là hình chữ nhật, phạm vi trực giao ba chiều gọi tắt là hình hộp. Bài toán đếm điểm hai chiều thường nói đến chính là phạm vi trực giao hai chiều.

Với một bài toán hai chiều tĩnh, có thể dùng đường quét để quét một chiều, còn cấu trúc dữ liệu duy trì chiều còn lại.
Trong quá trình đường quét đi từ trái sang phải, trên chiều được cấu trúc dữ liệu duy trì sẽ phát sinh một số thao tác sửa đổi và truy vấn.
Nếu thông tin truy vấn có thể tách bằng hiệu, dùng hiệu trực tiếp; nếu không thì cần dùng chia để trị. Phần hiệu thường được duy trì bằng cây Fenwick hoặc cây đoạn, nhưng vì cây Fenwick dễ viết và có hằng số nhỏ nên đa số sẽ chọn cây Fenwick. Chia để trị thường là chia để trị CDQ, nhưng phần này không bàn đến chia để trị.

Một góc nhìn khác dễ hiểu hơn là nhìn bài toán từ góc độ dãy, thay vì từ mặt phẳng hai chiều. Nếu nhìn như vậy, đường quét thực chất đang liệt kê đầu mút phải $r=1\cdots n$, duy trì một cấu trúc dữ liệu hỗ trợ truy vấn: với $r$ hiện tại và một giá trị $l$ cho trước, đáp án trên đoạn từ $l$ đến $r$ là gì. Nói cách khác, đường quét quét qua đầu mút phải của truy vấn, còn cấu trúc dữ liệu duy trì đáp án cho mọi đầu mút trái; cũng có thể hiểu là duyệt một chiều và dùng cấu trúc dữ liệu duy trì chiều còn lại.

Độ phức tạp thường là $O((n+m)\log n)$.

## Đếm điểm hai chiều

Cho một dãy độ dài $n$, có $m$ truy vấn. Mỗi truy vấn hỏi số phần tử trong đoạn $[l,r]$ có giá trị nằm trong $[x,y]$.

Bài toán này được gọi là đếm điểm hai chiều, tương đương với việc truy vấn số điểm nằm trong một hình chữ nhật trên mặt phẳng hai chiều. Phần này trình bày cách xử lý đơn giản nhất cho bài toán này: đường quét + cây Fenwick.

Đây là một bài toán hai chiều tĩnh. Bằng đường quét, có thể chuyển bài toán hai chiều tĩnh thành bài toán một chiều động. Để duy trì bài toán một chiều động, dùng cấu trúc dữ liệu trên dãy; cây Fenwick là một lựa chọn phù hợp.

Trước hết rời rạc hóa tất cả truy vấn, dùng cây Fenwick để duy trì trọng số. Với mỗi truy vấn có $l$ và $r$, khi liệt kê đến $l-1$, thống kê số lượng hiện tại của các giá trị nằm trong đoạn $[x,y]$, gọi là $a$; tiếp tục liệt kê về sau, khi đến $r$ thì thống kê số lượng hiện tại của các giá trị nằm trong đoạn $[x,y]$, gọi là $b$. Khi đó $b-a$ là đáp án của truy vấn này.

### Ví dụ

???+ note "[Luogu P2163 SHOI 2007 Gardener's Trouble](https://www.luogu.com.cn/problem/P2163)"
    Trước hết rời rạc hóa. Gọi $ans_{x, y}$ là số điểm nằm trong hình chữ nhật có góc trái dưới $(0, 0)$ và góc phải trên $(x, y)$. Khi đó đáp án của truy vấn có thể được tách bằng hiệu thành $ans_{c, d} - ans_{a - 1, d} - ans_{c, b - 1} + ans_{a - 1, b - 1}$.
    
    ??? note "Mã nguồn"
        ```cpp
        --8<-- "docs/geometry/code/scanning/scanning_3.cpp"
        ```

???+ note "[Luogu P1908 Inversion Count](https://www.luogu.com.cn/problem/P1908)"
    Nghịch thế cũng có thể được giải bằng tư duy đường quét. Xét việc chuyển bài toán đếm số nghịch thế thành: liệt kê từng vị trí $i$ từ sau ra trước, rồi tìm số điểm trong đoạn vị trí $[i+1,n]$ có giá trị thuộc đoạn $[0,a_i]$. Phạm vi dữ liệu của đề là $10^9$, nên cần rời rạc hóa trước. Duyệt mảng từ sau ra trước; mỗi khi duyệt đến một số thì cập nhật cây Fenwick, hoặc cây đoạn, rồi thống kê hiện có bao nhiêu số nhỏ hơn số đang liệt kê. Vì duyệt từ sau ra trước, số lượng số nhỏ hơn giá trị hiện tại chính là số nghịch thế do nó tạo ra. Có thể dùng cây Fenwick hoặc cây đoạn để sửa một điểm và truy vấn đoạn.
    
    ??? note "Mã nguồn"
        ```cpp
        --8<-- "docs/geometry/code/scanning/scanning_4.cpp"
        ```

???+ note "[Luogu P1972 SDOI 2009 HH's Necklace](https://www.luogu.com.cn/problem/P1972)"
    Tóm tắt đề: cho một dãy, nhiều lần hỏi trong đoạn $[l,r]$ có bao nhiêu giá trị khác nhau.
    
    Với loại bài toán này, có thể suy luận tính chất, rồi dùng đường quét liệt kê tất cả đầu mút phải và cấu trúc dữ liệu duy trì đáp án cho mỗi đầu mút trái. Cũng có thể chuyển bài toán lên mặt phẳng hai chiều, biến nó thành bài toán truy vấn thông tin trong hình chữ nhật.
    
    Trong bài này, đặt $pre_i$ là vị trí xuất hiện trước đó của $a_i$ trong dãy; nếu $a_i$ chưa từng xuất hiện thì $pre_i = 0$. Theo đề bài, nếu một giá trị xuất hiện nhiều lần trong đoạn thì nó chỉ đóng góp một lần. Có thể xem vị trí sinh đóng góp của mỗi giá trị là lần xuất hiện đầu tiên của nó trong đoạn; khi đó tổng đóng góp chính là số lượng $pre_x \le l - 1$, có thể chứng minh bằng phản chứng.
    
    Bài toán hiện trở thành: cho một dãy $pre$, nhiều lần truy vấn trong đoạn $[l,r]$ có bao nhiêu $pre_i \le l - 1$.
    
    Xem $pre_i$ là điểm trên mặt phẳng hai chiều: $i$ là hoành độ, $pre_i$ là tung độ. Khi đó bài toán chuyển thành đếm điểm hai chiều: mỗi truy vấn hỏi trong hình chữ nhật có góc trái dưới $(l,0)$ và góc phải trên $(r,l - 1)$ có bao nhiêu điểm.
    
    Truy vấn này có thể tách bằng hiệu: số điểm trong hình chữ nhật có góc trái dưới $(0,0)$ và góc phải trên $(r,l - 1)$ trừ đi số điểm trong hình chữ nhật có góc trái dưới $(0,0)$ và góc phải trên $(l - 1,l - 1)$. Cách tách này thuận tiện cho việc dùng đường quét.
    
    Độ phức tạp của một thao tác là $O(\log n)$. Có tổng cộng $n$ thao tác thêm điểm và $2m$ thao tác truy vấn, nên tổng độ phức tạp thời gian là $O((n + m) \log n)$.
    
    ??? note "Mã nguồn"
        ```cpp
        --8<-- "docs/geometry/code/scanning/scanning_5.cpp"
        ```

### Luyện tập

-   [Luogu P8593 KDOI-02 Projectile](https://www.luogu.com.cn/problem/P8593), ứng dụng của nghịch thế.
-   [AcWing 4709. Triples](https://www.acwing.com/problem/content/4712/), phiên bản yếu hơn của bài trên, cũng là ứng dụng của nghịch thế.
-   [Luogu P8773 Lanqiao Cup 2022 Provincial A Choose Numbers XOR](https://www.luogu.com.cn/problem/P8773), biến thể của HH's Necklace.
-   [Luogu P8844 Chuanzhi Cup #4 Preliminary Round: Xiao Ka and Falling Leaves](https://www.luogu.com.cn/problem/P8844), chuyển bài toán trên cây thành bài toán trên dãy rồi đếm điểm hai chiều.

Tóm lại, ý tưởng chính của đếm điểm hai chiều là dùng cấu trúc dữ liệu duy trì một chiều, rồi liệt kê chiều còn lại.

## Tài liệu tham khảo

-   [cnblogs/Yang1208: explanation of sweep line with dynamic segment tree](https://www.cnblogs.com/yangsongyi/p/8378629.html)
-   [csdn/riba2534: solution for POJ 1151 Atlantis](https://blog.csdn.net/riba2534/article/details/76851233)
-   [csdn/winddreams: solution for POJ 1151 Atlantis](https://blog.csdn.net/winddreams/article/details/38495093)
-   [A brief discussion of sweep line](https://www.luogu.com.cn/article/f8q5bmnz)
