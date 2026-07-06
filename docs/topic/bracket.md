author: sshwy

Định nghĩa một dãy ngoặc hợp lệ/cân bằng (balanced bracket sequence) là một xâu chỉ gồm $($ và $)$, đồng thời thỏa mãn:

-   Xâu rỗng $\varepsilon$ là một dãy ngoặc hợp lệ.
-   Nếu $s$ là một dãy ngoặc hợp lệ, thì $(s)$ cũng là một dãy ngoặc hợp lệ.
-   Nếu $s,t$ đều là dãy ngoặc hợp lệ, thì $st$ cũng là một dãy ngoặc hợp lệ.

Ví dụ, $(())()$ là một dãy ngoặc hợp lệ, còn $)()$ thì không.

Đôi khi có nhiều loại ngoặc khác nhau, chẳng hạn $[()]\{\}$. Các biến thể dãy ngoặc như vậy có định nghĩa tương tự dãy ngoặc đơn giản.

Bài viết này giới thiệu các bài toán kinh điển liên quan đến dãy ngoặc.

Ghi chú: Trong tiếng Anh, ngoặc trái thường được gọi là opening bracket, còn ngoặc phải là closing bracket.

## Kiểm tra tính hợp lệ

Cách kinh điển để kiểm tra $s$ có phải là dãy ngoặc hợp lệ hay không dựa trên tư tưởng tham lam. Thuật toán này cũng áp dụng được cho các biến thể dãy ngoặc.

Duy trì một ngăn xếp và lần lượt xét $i=1,2,\ldots,|s|$:

-   Nếu $s_i$ là ngoặc phải, ngăn xếp không rỗng, và phần tử trên đỉnh ngăn xếp là ngoặc trái tương ứng với $s_i$, thì lấy phần tử đỉnh ra khỏi ngăn xếp.
-   Nếu không thỏa mãn điều kiện trên, đưa $s_i$ vào ngăn xếp.

Sau khi duyệt toàn bộ $s$, nếu ngăn xếp rỗng thì $s$ là dãy ngoặc hợp lệ, ngược lại thì không. Độ phức tạp thời gian là $O(n)$.

## Đếm dãy ngoặc hợp lệ

Xét bài toán tìm số lượng $f_n$ các dãy ngoặc hợp lệ $s$ có độ dài $2n$. Có thể liệt kê vị trí của ngoặc khớp với $s_1$, giả sử vị trí đó là $2i+2$. Vị trí này chia toàn bộ dãy thành hai dãy ngoặc hợp lệ ngắn hơn. Do đó

$$
f_n=\sum_{i=0}^{n-1}f_if_{n-i-1}
$$

Đây cũng chính là công thức truy hồi của số Catalan. Nói cách khác, $f_n=\frac{1}{n+1}\binom{2n}{n}$.

Cách đếm các biến thể dãy ngoặc hợp lệ cũng tương tự. Giả sử có $k$ loại ngoặc khác nhau, khi đó $f'_n=\frac{1}{n+1}\binom{2n}{n}k^n$.

## Phần tử kế tiếp theo thứ tự từ điển

Cho một dãy ngoặc hợp lệ $s$, cần tìm dãy ngoặc hợp lệ kế tiếp của $s$ trong danh sách tất cả các dãy ngoặc hợp lệ có độ dài $|s|$, được sắp xếp tăng dần theo thứ tự từ điển. Trong bài toán này, quy ước ngoặc trái nhỏ hơn ngoặc phải theo thứ tự từ điển, và không xét các biến thể dãy ngoặc.

Cần tìm chỉ số lớn nhất $i$ sao cho $s_i$ là ngoặc trái. Sau đó, đổi nó thành ngoặc phải và tái dựng đoạn $s[i+1,|s|]$. Ngoài ra, $i$ phải thỏa mãn: trong $s[1,i-1]$, số lượng ngoặc trái **lớn hơn** số lượng ngoặc phải.

Giả sử sau khi $s_i$ được đổi thành ngoặc phải, trong $s[1,i]$ số ngoặc trái nhiều hơn số ngoặc phải $k$ cái. Khi đó đặt $k$ ký tự cuối của $s$ thành ngoặc phải, còn $s[i+1,|s|-k]$ được điền theo dạng $((\dots(())\dots))$, vì cách điền này cho thứ tự từ điển nhỏ nhất.

Độ phức tạp thời gian của thuật toán là $O(n)$.

??? note "Cài đặt tham khảo"
    ```cpp
    bool next_balanced_sequence(string& s) {
      int n = s.size();
      int depth = 0;
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(')
          depth--;
        else
          depth++;
    
        if (s[i] == '(' && depth > 0) {
          depth--;
          int open = (n - i - 1 - depth) / 2;
          int close = n - i - 1 - open;
          string next =
              s.substr(0, i) + ')' + string(open, '(') + string(close, ')');
          s.swap(next);
          return true;
        }
      }
      return false;
    }
    ```

## Tính hạng theo thứ tự từ điển

Cho một dãy ngoặc hợp lệ $s$, cần tìm hạng của nó theo thứ tự từ điển.

Xét việc tìm số lượng dãy ngoặc $p$ có thứ tự từ điển nhỏ hơn $s$.

Giả sử $p_i<s_i$ và $\forall 1\le j<i,p_j=s_j$. Khi đó $p_i$ là ngoặc trái còn $s_i$ là ngoặc phải. Liệt kê $i$ (thỏa mãn $s_i$ là ngoặc phải); giả sử trong $p[1,i]$ số ngoặc trái nhiều hơn số ngoặc phải $k$ cái, khi đó bài toán tương đương với việc đếm số dãy ngoặc có độ dài $|s|-i$, có $k$ ngoặc phải chưa được khớp và không có ngoặc trái chưa được khớp.

Đặt $f(i,j)$ là số lượng dãy ngoặc có độ dài $i$, có $j$ ngoặc phải chưa được khớp và không có ngoặc trái chưa được khớp.

Bằng cách liệt kê ký tự đầu tiên của dãy ngoặc, thu được chuyển tiếp của $f$: $f(i,j) = f(i-1,j-1)+f(i-1,j+1)$. Giá trị khởi tạo là $f(0,0)=1$. Dãy $f$ tương ứng với [OEIS - A053121](http://oeis.org/A053121).

Như vậy, có thể tính hạng theo thứ tự từ điển trong $O(|s|^2)$.

Đối với các biến thể dãy ngoặc, phương pháp cũng tương tự, chỉ khác là với mỗi $s_i$ cần xét các ký tự nhỏ hơn nó để tính toán (trong thuật toán trên, do không tồn tại ký tự nào nhỏ hơn ngoặc trái, nên chỉ xét trường hợp $s_i$ là ngoặc phải).

Ngoài ra, bằng cách sử dụng mảng $f$, cũng có thể tìm dãy ngoặc hợp lệ có hạng $k$ theo thứ tự từ điển.

**Trang này chủ yếu được dịch từ bài viết <http://e-maxx.ru/algo/bracket_sequences> và bản dịch tiếng Anh [Balanced bracket sequences](https://cp-algorithms.com/combinatorics/bracket_sequences.html). Bản tiếng Nga được cấp phép theo Public Domain + Leave a Link; bản tiếng Anh được cấp phép theo CC-BY-SA 4.0.**
