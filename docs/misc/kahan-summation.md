## Dẫn nhập

Thuật toán **cộng Kahan** (Kahan summation), còn gọi là thuật toán cộng bù hoặc cộng có bù sai số, là một thuật toán dùng để **giảm sai số của tổng tích lũy trên một dãy số thực dấu phẩy động có độ chính xác hữu hạn**. Thuật toán chủ yếu làm việc này bằng cách giữ một biến riêng để tích lũy sai số, thường dùng tên biến $c$.

Thuật toán này chủ yếu do William Kahan phát hiện vào thập niên 1960. Vì Ivo Babuška cũng từng độc lập đề xuất một thuật toán tương tự, thuật toán cộng Kahan còn được gọi là thuật toán cộng Kahan–Babuška (Kahan–Babuška summation).

## Sai số làm tròn

Trong chương trình máy tính, cần biểu diễn xấp xỉ số thực bằng một số hữu hạn chữ số. Ngày nay, hầu hết máy tính dùng số dấu phẩy động theo chuẩn [IEEE-754](https://en.wikipedia.org/wiki/IEEE_754) cho biểu diễn xấp xỉ này. Với $\frac{1}{3}$, vì không thể biểu diễn chính xác nó bằng hữu hạn chữ số, nên khi dùng biểu diễn IEEE-754, một phần giá trị bắt buộc phải được làm tròn hoặc cắt bỏ (truncate). **Sai số làm tròn** (Rounding off error) này là một đặc trưng của tính toán dấu phẩy động.

Trong phép cộng dấu phẩy động, tính giao hoán (commutativity) đúng, nhưng tính kết hợp (associativity) không đúng. Nói cách khác, $a+b = b+a$ nhưng $(a+b)+c \neq a+(b+c)$. Vì vậy, khi cộng một dãy số dấu phẩy động, có thể cộng lần lượt từ trái sang phải, hoặc giữ nguyên thứ tự ban đầu rồi ghép các phần tử thành từng cặp để cộng. Thuật toán thứ hai thường chậm hơn và cần nhiều bộ nhớ hơn, cũng thường được một số hàm tính tổng chuyên dụng của các ngôn ngữ sử dụng, nhưng kết quả tương đối chính xác hơn.

Để thu được kết quả cộng tích lũy dấu phẩy động chính xác hơn, cần dùng thuật toán cộng Kahan.

Khi tính $S_{new}=S_{old}+a$ (trong đó $a$ là một giá trị của dãy dấu phẩy động), định nghĩa giá trị thực sự được cộng vào $S$ là $a_{eff}=S_{new}-S_{old}$. Nếu $a_{eff}$ lớn hơn $a$, nghĩa là có sai số làm tròn lên; nếu $a_{eff}$ nhỏ hơn $a$, nghĩa là có sai số làm tròn xuống. Khi đó sai số làm tròn được định nghĩa là $E_{roundoff} = a_{eff} - a$. Giá trị dùng để hiệu chỉnh phần sai số làm tròn này là $a-a_{eff}$, tức là giá trị đối của $E_{roundoff}$. Gọi $c$ là biến bù cho các bit thấp bị mất trong phép tính, suy ra $c_{new} = c_{old} + (a - a_{eff})$.

## Quy trình

Thuật toán cộng Kahan chủ yếu dùng một biến riêng để tích lũy sai số. Như đoạn mã tham khảo dưới đây, $sum$ là kết quả tổng cuối cùng được trả về. $c$ là biến bù cho các bit thấp bị mất trong phép tính (phần đã bị loại bỏ), và cũng là biến cần thiết trong thuật toán cộng Kahan.

Vì $sum$ lớn còn $y$ nhỏ, các bit thấp của $y$ bị mất. $(t - sum)$ triệt tiêu phần bậc cao của $y$, rồi trừ $y$ sẽ khôi phục giá trị âm, tức phần bậc thấp của $y$. Do đó, về mặt đại số, $c$ luôn bằng không. Trong vòng lặp tiếp theo, phần bit thấp bị mất sẽ được cập nhật và cộng vào $y$.

## Cài đặt

??? note "Mã tham khảo"
    ```cpp
    float kahanSum(vector<float> nums) {
      float sum = 0.0f;
      float c = 0.0f;
      for (auto num : nums) {
        float y = num - c;
        float t = sum + y;
        c = (t - sum) - y;
        sum = t;
      }
      return sum;
    }
    ```

## Bài tập

Trong OI, cộng Kahan chủ yếu tồn tại như một công cụ phụ trợ, cung cấp giá trị có sai số nhỏ hơn cho kết quả tính toán.

???+ note "Ví dụ [CodeForces Contest 800 Problem A. Voltage Keepsake](https://codeforces.com/contest/800/problem/A)"
    Có $n$ thiết bị đang được sử dụng đồng thời. Thiết bị thứ $i$ tiêu thụ $a_{i}$ đơn vị năng lượng mỗi giây. Việc tiêu thụ này là liên tục. Nghĩa là trong $\lambda$ giây, thiết bị sẽ tiêu thụ $\lambda \times a_{i}$ đơn vị năng lượng. Thiết bị thứ $i$ hiện lưu trữ $b_{i}$ đơn vị điện năng. Mọi thiết bị đều có thể lưu trữ lượng điện bất kỳ. Có một bộ sạc có thể cắm vào bất kỳ một thiết bị đơn lẻ nào. Mỗi giây, bộ sạc bổ sung $p$ đơn vị điện năng cho thiết bị. Việc sạc cũng là liên tục. Nghĩa là nếu cắm thiết bị trong $\lambda$ giây, nó sẽ nhận được $\lambda \times p$ đơn vị năng lượng. Có thể chuyển thiết bị đang được sạc tại bất kỳ thời điểm nào, kể cả thời điểm thực, và thời gian chuyển đổi được bỏ qua. Cần tìm thời gian dài nhất có thể sử dụng các thiết bị trước khi một thiết bị nào đó đạt mức $0$ đơn vị năng lượng.

???+ note "Ví dụ [CodeForces Contest 504 Problem B. Misha and Permutations Summation](https://codeforces.com/problemset/problem/504/B)"
    Định nghĩa tổng của hai hoán vị $p$ và $q$ của các số $0, 1, \cdots, (n - 1)$ là $Perm((Ord(p)+Ord(q))\bmod n!)$, trong đó $Perm(x)$ là hoán vị theo thứ tự từ điển thứ $x$ của các số $0, 1, \cdots, (n-1)$, tính từ $0$, còn $Ord(p)$ là số thứ tự từ điển của hoán vị $p$. Ví dụ, $Perm(0) = (0, 1, \cdots , n - 2, n - 1)$, $Perm(n! - 1) = (n - 1, n-2,\cdots, 1,0))$. Misha có hai hoán vị $p$ và $q$; cần tìm tổng của chúng.

## Phép tính tổng trong các ngôn ngữ lập trình

Thư viện chuẩn Python cung cấp hàm [fsum](https://docs.python.org/3/library/math.html#math.fsum) để tính tổng làm tròn chính xác, dùng để trả về tổng dấu phẩy động chính xác của các giá trị trong một đối tượng khả lặp. Hàm này tránh mất độ chính xác bằng cách dùng thuật toán Shewchuk để theo dõi nhiều tổng trung gian từng phần.

Trong Julia, cài đặt mặc định của hàm [sum](https://docs.julialang.org/en/v1/base/collections/#Base.sum) là cộng theo cặp để đạt độ chính xác cao và hiệu năng tốt. Đồng thời, hàm thư viện ngoài [sum\_kbn](http://www.jlhub.com/julia/manual/en/function/sum_kbn) cung cấp cài đặt biến thể Neumaier cho các trường hợp cần độ chính xác cao hơn; xem thêm [KahanSummation.jl](https://github.com/JuliaMath/KahanSummation.jl).

## Tài liệu tham khảo và chú thích

1.  [Thuật toán cộng Kahan - Wikipedia](https://en.wikipedia.org/wiki/Kahan_summation_algorithm)
2.  [Cộng Kahan - Rosetta Code](https://rosettacode.org/wiki/Kahan_summation)
3.  [Thông báo VK Cup vòng 2 + Codeforces Round 409](https://codeforces.com/blog/entry/51577)
4.  [Lỗi làm tròn trong Java - GeeksforGeeks](https://www.geeksforgeeks.org/rounding-off-errors-java/)
