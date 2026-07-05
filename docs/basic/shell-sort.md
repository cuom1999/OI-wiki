Trang này giới thiệu ngắn gọn về sắp xếp Shell.

## Định nghĩa

Sắp xếp Shell (tiếng Anh: Shell sort), còn gọi là phương pháp sắp xếp giảm dần khoảng cách, là một phiên bản cải tiến của [sắp xếp chèn](./insertion-sort.md). Sắp xếp Shell được đặt theo tên người phát minh ra nó, Shell (tiếng Anh: Donald Shell).

## Quy trình

Thuật toán sắp xếp bằng cách so sánh và di chuyển các bản ghi không kề nhau:

1.  Chia dãy cần sắp xếp thành nhiều dãy con (các phần tử trong mỗi dãy con có cùng khoảng cách trong mảng ban đầu);
2.  Thực hiện sắp xếp chèn trên các dãy con này;
3.  Giảm khoảng cách giữa các phần tử trong mỗi dãy con, lặp lại quá trình trên cho đến khi khoảng cách giảm xuống $1$.

## Tính chất

### Tính ổn định

Sắp xếp Shell là một thuật toán sắp xếp không ổn định.

### Độ phức tạp thời gian

Độ phức tạp thời gian tốt nhất của sắp xếp Shell là $O(n)$.

Độ phức tạp thời gian trung bình và xấu nhất của sắp xếp Shell phụ thuộc vào cách chọn dãy khoảng cách. Gọi dãy khoảng cách là $H$; dưới đây là hai cách chọn kinh điển cho $H$. Cả hai cách này đều làm độ phức tạp của thuật toán sắp xếp giảm xuống bậc $o(n^2)$.

???+ note "Mệnh đề 1"
    Nếu dãy khoảng cách là $H= \{ 2^k-1\mid k=1,2,\ldots,\lfloor\log_2 n\rfloor \}$ (theo thứ tự từ lớn đến nhỏ), thì độ phức tạp thời gian của thuật toán sắp xếp Shell là $O(n^{3/2})$.

???+ note "Mệnh đề 2"
    Nếu dãy khoảng cách là $H= \{ k=2^p\cdot 3^q\mid p,q\in \mathbb N,k\le n \}$ (theo thứ tự từ lớn đến nhỏ), thì độ phức tạp thời gian của thuật toán sắp xếp Shell là $O(n\log^2 n)$.

Để chứng minh hai mệnh đề này, trước hết ta nêu và chứng minh một định lý quan trọng. Định lý này phản ánh đặc trưng chủ yếu nhất của sắp xếp Shell.

???+ note "Định lý 1"
    Chỉ cần chương trình đã thực hiện một lần $\text{InsertionSort}(h)$, thì bất kể sau đó gọi hàm $\text{InsertionSort}$ như thế nào và mảng $A$ biến đổi ra sao, tính chất sau vẫn luôn được duy trì:
    
    $$
    \begin{array}{c}
    A_1,A_{1+h},A_{1+2h},\ldots \\
    A_2,A_{2+h},A_{2+2h},\ldots \\
    \vdots \\
    A_h,A_{h+h},A_{h+2h},\ldots
    \end{array}
    $$

Tiếp theo ta chứng minh định lý 1.

Trước hết chứng minh bổ đề 1.

???+ note "Bổ đề 1"
    Với các số nguyên $n,m$, số nguyên dương $l$ và hai mảng $X(x_1,x_2,\ldots,x_{n+l}),Y(y_1,y_2,\ldots,y_{m+l})$ thỏa mãn yêu cầu sau:
    
    $$
    y_1 \le x_{n+1},y_2 \le x_{n+2},\ldots,y_l \le x_{n+l}
    $$
    
    Nếu ta sắp xếp riêng hai mảng theo thứ tự tăng dần, yêu cầu trên vẫn còn đúng.

??? note "Chứng minh bổ đề 1"
    Giả sử sau khi sắp xếp, mảng $X$ trở thành $X'(x'_1,\ldots,x'_{n+l})$ và mảng $Y$ trở thành $Y'(y'_1,\ldots,y'_{m+l})$.
    
    Với mọi $1\le i\le l$, $x'_{n+i}$ nhỏ hơn hoặc bằng $l-i$ phần tử trong mảng $X'$, và cũng nhỏ hơn hoặc bằng $l-i$ phần tử trong mảng $X$ (vì đa tập phần tử của $X$ và $X'$ là giống nhau).
    
    Khi đó trong đa tập $\{x_{n+1},\ldots,x_{n+l} \} \subset X$, số phần tử lớn hơn hoặc bằng $x'_{n+i}$ không vượt quá $l-i$.
    
    Suy ra số phần tử nhỏ hơn $x'_{n+i}$ ít nhất là $i$. Lấy ra $i$ phần tử trong số đó, giả sử chúng là $x_{n+k_1},x_{n+k_2},\ldots,x_{n+k_i}$. Khi đó có:
    
    $$
    y_{k_1}\le x_{n+k_1}\le x'_{n+i},y_{k_2}\le x_{n+k_2}\le x'_{n+i},\ldots,y_{k_i}\le x_{n+k_i}\le x'_{n+i}
    $$
    
    Vì vậy $x'_{n+i}$ lớn hơn hoặc bằng ít nhất $i$ phần tử trong $Y$, tức cũng lớn hơn hoặc bằng ít nhất $i$ phần tử trong $Y'$. Do đó hiển nhiên có $y'_i\le x'_{n+i}\,(1\le i\le l)$.

Quay lại chứng minh mệnh đề ban đầu:

Thực ra ta chỉ cần chứng minh rằng sau khi gọi xong $\text{InsertionSort}(h)$, rồi ngay ở lần gọi kế tiếp thực hiện $\text{InsertionSort}(k)$, $h$ dãy con vẫn có thứ tự. Sau đó dễ dàng dùng quy nạp để suy ra kết luận. Dưới đây chỉ xét lần gọi kế tiếp này.

Sau khi thực hiện xong $\text{InsertionSort}(h)$, các nhóm sau đã được sắp xếp:

$$
\begin{array}{c}
A_1,A_{1+h},A_{1+2h},\ldots \\
A_2,A_{2+h},A_{2+2h},\ldots \\
\vdots \\
A_h,A_{h+h},A_{h+2h},\ldots
\end{array}
$$

Sau đó thực hiện $\text{InsertionSort}(k)$ thì các nhóm sau sẽ được sắp xếp:

$$
\begin{array}{c}
A_1,A_{1+k},A_{1+2k},\ldots \\
A_2,A_{2+k},A_{2+2k}, \ldots \\
\vdots \\
A_k,A_{k+k},A_{k+2k},\ldots
\end{array}
$$

Với mỗi $i$ $(1\le i\le \min(h,k))$, xét hai nhóm sau:

$$
\begin{array}{c}
A_i,A_{i+k},A_{i+2k},\ldots \\
\ldots,A_{i+h},A_{i+h+k},A_{i+h+2k},\ldots
\end{array}
$$

Lý do thêm "$\ldots$" ở phía trước nhóm thứ hai là có thể $i+h\ge k$, nên phía trước cũng có phần tử.

Khi đó nhóm thứ hai chính là mảng $X$ trong bổ đề $1$, nhóm thứ nhất chính là mảng $Y$, $l$ là độ dài từ $i+h$ đến cuối của nhóm thứ hai, $n$ là độ dài phần "$\ldots$" ở phía trước trong nhóm thứ hai, còn $m$ là số phần tử còn lại của nhóm thứ nhất sau khi bỏ đi $l$ phần tử đầu.

Lại vì có:

$$
A_i\le A_{i+h},A_{i+k}\le A_{i+h+k},\ldots
$$

nên theo bổ đề $1$, sau khi thực hiện $\text{InsertionSort}(k)$ để sắp xếp riêng hai nhóm, quan hệ này vẫn còn đúng, tức vẫn có $A_i\le A_{i+h}\,(1\le i\le \min(h,k))$.

Nếu $i>\min(h,k)$, dễ thấy chỉ cần lấy một số nguyên dương $w$ $(1\le w\le \min(h,k))$ rồi cộng thêm một số lần $k$ là có thể thu được $i$; do đó trường hợp đã xét ở trên đã bao hàm chứng minh cho trường hợp này.

Tổng hợp các lập luận trên, sau khi thực hiện xong $\text{InsertionSort}(k)$ vẫn có $A_i\le A_{i+h}\,(1\le i\le n-h)$.

Vì vậy định lý 1 được chứng minh.

Định lý này cho thấy điểm then chốt giúp sắp xếp Shell tối ưu được độ phức tạp với một tập $H$ cụ thể: trong toàn bộ quá trình, nó có thể luôn giữ lại kết quả đã đạt được trước đó (tức $h$ dãy con lần lượt có thứ tự), từ đó làm số lần di chuyển của con trỏ $i$ trong các lời gọi sau giảm đi rất nhiều.

Tiếp theo ta tách riêng một bổ đề số học để chứng minh. Định lý này nổi tiếng trong cộng đồng OI nhờ bài [Luogu P3951 Nỗi băn khoăn của Xiao Kai](https://www.luogu.com.cn/problem/P3951). Trong chứng minh độ phức tạp của sắp xếp Shell, nó cũng giúp mở rộng định lý $1$ đáng kể.

???+ note "Bổ đề 2"
    Nếu $a,b$ đều là số nguyên dương và nguyên tố cùng nhau, thì số nguyên dương lớn nhất không thuộc tập $\{ax+by\mid x,y\in \mathbb N \}$ là $ab-a-b$.

??? note "Chứng minh bổ đề 2"
    Chứng minh theo hai bước:
    
    -   Trước hết chứng minh phương trình $ax+by=ab-a-b$ không có nghiệm mà $x,y$ đều là số nguyên không âm:
    
        Nếu bỏ điều kiện số nguyên không âm, dễ thu được hai nghiệm $(b-1,-1),(-1,a-1)$.
    
        Từ dạng nghiệm tổng quát $x=x_0+tb,y=y_0-ta$, dễ thấy hai nghiệm trên là "kề nhau" (vì $b-1-b=-1$).
    
        Khi $t$ tăng, $x$ tăng còn $y$ giảm, nên nếu phương trình có nghiệm nguyên không âm, nghiệm đó tất phải nằm giữa hai nghiệm trên. Nhưng hai nghiệm này "kề nhau", ở giữa không có nghiệm nào khác.
    
        Vì vậy không thể có nghiệm nguyên không âm.
    -   Tiếp theo chứng minh với mọi số nguyên $c > ab-a-b$, phương trình $ax+by=c$ có nghiệm nguyên không âm:
    
        Ta tìm một nghiệm $(x_0,y_0)$ thỏa mãn $0\le x_0 < b$ (từ biểu thức nghiệm tổng quát, có thể làm được điều này).
    
        Khi đó:
    
        $$
        by_0=c-ax_0\ge c-a(b-1)>ab-a-b-ab+a=-b
        $$
    
        Do đó $b(y_0+1) > 0$. Lại vì $b>0$, suy ra $y_0+1>0$, nên $y_0\ge 0$.
    
        Vì vậy $(x_0,y_0)$ là một nghiệm nguyên không âm.
    
    Tóm lại, bổ đề được chứng minh.

Định lý tiếp theo cho thấy bổ đề $2$ mở rộng định lý $1$ như thế nào.

???+ note "Định lý 2"
    Nếu $\gcd(h_{t+1},h_t)=1$, thì sau khi chương trình lần lượt thực hiện xong $\text{InsertionSort}(h_{t+1})$ và $\text{InsertionSort}(h_t)$, thời gian thực hiện $\text{InsertionSort}(h_{t-1})$ là $O\left(\dfrac{nh_{t+1}h_t}{h_{t-1}} \right)$; đồng thời với mỗi $j$, số lần di chuyển của $i$ là bậc $O\left(\dfrac{h_{t+1}h_t}{h_{t-1}} \right)$.

??? note "Chứng minh định lý 2"
    Với phần $j\le h_{t+1}h_t$, số lần di chuyển của $i$ hiển nhiên là bậc $O\left(\dfrac{h_{t+1}h_t}{h_{t-1}} \right)$.
    
    Vì vậy dưới đây giả sử $j>h_{t+1}h_t$.
    
    Với số nguyên dương tùy ý $k$ thỏa mãn $1\le k\le j-h_{t+1}h_t$, chú ý rằng: $h_{t+1}h_t-h_{t+1}-h_t<h_{t+1}h_t\le j-k\le j-1$.
    
    Lại vì $\gcd(h_{t+1},h_t)=1$, theo bổ đề $2$, tồn tại các số nguyên không âm $a,b$ sao cho: $ah_{t+1}+bh_t=j-k$.
    
    Suy ra:
    
    $$
    k=j-ah_{t+1}-bh_t
    $$
    
    Theo định lý $1$, có:
    
    $$
    A_{j-bh_t}\le A_{j-(b-1)h_t}\le \ldots\le A_{j-h_t}\le A_j
    $$
    
    và
    
    $$
    A_{j-bh_t-ah_{t+1}}\le A_{j-bh_t-(a-1)h_{t+1}}\le \ldots\le A_{j-bh_t-h_{t+1}}\le A_{j-bh_t}
    $$
    
    Kết hợp lại có: $A_k=A_{j-ah_{t+1}-bh_t}\le A_j$.
    
    Vì vậy với mọi $1\le k\le j-h_{t+1}h_t$, ta có $A_k\le A_j$.
    
    Trong mã giả Shell-Sort, con trỏ $i$ mỗi lần giảm $h_{t-1}$; sau khi giảm $O\left(\dfrac{h_{t+1}h_t}{h_{t-1}} \right)$ lần, ta có thể làm cho $i\le j-h_{t+1}h_t$, từ đó có $A_i\le A_j$, điều kiện của vòng lặp while không còn thỏa mãn và vòng lặp kết thúc.
    
    Sau khi chứng minh xong độ phức tạp di chuyển cho mỗi $j$, ta thu được tổng độ phức tạp thời gian:
    
    $$
    \sum_{j=h_{t-1}+1}^n{O\left(\frac{h_{t+1}h_t}{h_{t-1}} \right)}=O\left(\frac{nh_{t+1}h_t}{h_{t-1}}\right)
    $$
    
    Định lý được chứng minh.

Quan sát kỹ quá trình chứng minh định lý $2$, có thể thấy: định lý 1 có thể được "tổ hợp tuyến tính", tức nếu $A$ có thứ tự theo khoảng cách $h$ và cũng có thứ tự theo khoảng cách $k$, thì nó vẫn có thứ tự theo tổ hợp tuyến tính với hệ số không âm của $h$ và $k$. Tính "tuyến tính" này được bảo đảm bởi bổ đề $2$.

Có hai định lý trên, ta có thể chứng minh mệnh đề $1$ và $2$.

??? note "Chứng minh mệnh đề 1"
    Viết $H$ dưới dạng dãy:
    
    $$
    H(h_1=1,h_2=3,h_3=7,\ldots,h_{\lfloor \log_2 n\rfloor}=2^{\lfloor \log_2 n\rfloor}-1)
    $$
    
    Thứ tự thực hiện của Shell-Sort là: $\text{InsertionSort}(h_{\lfloor \log_2 n\rfloor}),\text{InsertionSort}(h_{\lfloor \log_2 n\rfloor-1}),\ldots,\text{InsertionSort}(h_2),\text{InsertionSort}(h_1)$.
    
    Chia việc phân tích độ phức tạp thành hai phần:
    
    -   Với một số hạng đầu thỏa mãn $h_t\ge \sqrt{n}$, hiển nhiên độ phức tạp thời gian của $\text{InsertionSort}(h_t)$ là $O\left(\dfrac{n^2}{h_t} \right)$.
    
        Xét hạng $h_k$ gần $\sqrt{n}$ nhất, có:
    
        $$
        O\left(\frac{n^2}{h_t} \right)=O(n^{3/2})
        $$
    
        Với $h_i$ mà $i> k$, vì có $2h_i< h_{i+1}$, suy ra:
    
        $$
        O\left(\frac{n^2}{h_i} \right)=O(n^{3/2}/2^{i-k})\,(i>k)
        $$
    
        Do đó tổng độ phức tạp thời gian của phần lớn hơn hoặc bằng $\sqrt n$ là:
    
        $$
        \sum_{i=k}^{\lfloor \log_2 n\rfloor}{O(n^{3/2}/2^{i-k})}=O(n^{3/2})
        $$
    -   Với các hạng còn lại thỏa mãn $h_t< \sqrt{n}$, độ phức tạp của hai hạng đầu vẫn là $O(n^{3/2})$; còn với các hạng phía sau $h_t$, theo định lý $2$ có độ phức tạp thời gian:
    
        $$
        O\left(\frac{nh_{t+2}h_{t+1}}{h_t} \right)=O\left(\frac{nh_{t+2}\cdot h_{t+2}/2}{h_{t+2}/4} \right)=O(nh_{t+2})
        $$
    
        Lại dùng tính chất $2h_i < h_{i+1}$, thu được tổng độ phức tạp thời gian của phần này là (trong công thức dưới, $k$ vẫn dùng theo nghĩa ở trường hợp trước):
    
        $$
        2O(n^{3/2})+\sum_{i=1}^{k-3}{O(nh_{i+1})}=O(n^{3/2})+\sum_{i=1}^{k-3}{O(nh_{k-1}/2^{k-i-3})}=O(n^{3/2})+O(nh_{k-1})=O(n^{3/2})
        $$
    
    Tóm lại, tổng độ phức tạp thời gian là $O(n^{3/2})$.

??? note "Chứng minh mệnh đề 2"
    Chú ý một sự thật: nếu đã thực hiện $\text{InsertionSort}(2)$ và $\text{InsertionSort}(3)$, thì vì $2\cdot 3-2-3=1$, theo định lý $2$, với mỗi phần tử, chỉ có phần tử đứng ngay trước nó là có thể lớn hơn nó; tất cả phần tử trước đó đều nhỏ hơn nó. Do đó con trỏ $i$ chỉ cần nhiều nhất hai lần là có thể thoát khỏi vòng lặp while. Nói cách khác, lúc này thực hiện tiếp $\text{InsertionSort}(1)$ thì độ phức tạp giảm xuống $O(n)$.
    
    Xa hơn: nếu đã thực hiện $\text{InsertionSort}(4)$ và $\text{InsertionSort}(6)$, ta xét dãy con gồm tất cả phần tử có chỉ số lẻ và dãy con gồm tất cả phần tử có chỉ số chẵn. Điều này tương đương với việc thực hiện riêng $\text{InsertionSort}(2)$ và $\text{InsertionSort}(3)$ trên hai dãy con đó. Khi ấy cũng tương tự, thực hiện tiếp $\text{InsertionSort}(2)$ tương đương với thực hiện $\text{InsertionSort}(1)$ trên từng dãy con, và chỉ cần độ phức tạp cùng bậc với tổng độ dài của hai dãy, tức $O(n)$, là có thể làm mảng có thứ tự theo khoảng cách $2$.
    
    Quy nạp liên tục, ta có thể thu được: nếu đã thực hiện $\text{InsertionSort}(2h)$ và $\text{InsertionSort}(3h)$, thì độ phức tạp khi thực hiện $\text{InsertionSort}(h)$ cũng chỉ là $O(n)$.
    
    Tiếp theo chia việc phân tích độ phức tạp thành hai phần:
    
    -   Với phần $h_t>n/3$, độ phức tạp khi thực hiện mỗi $\text{InsertionSort}(h_t)$ là $O(n^2/h_t)$.
    
        Vì $n^2/h_t<3n$, độ phức tạp của một lần sắp xếp chèn là $O(n)$.
    
        Số phần tử trong phần này là bậc $O(\log^2 n)$, nên độ phức tạp thời gian của phần này là $O(n\log^2 n)$.
    -   Với phần $h_t\le n/3$, vì $3h_t\le n$, trước đó đã thực hiện $\text{InsertionSort}(2h_t)$ và $\text{InsertionSort}(3h_t)$, nên độ phức tạp thời gian khi thực hiện $\text{InsertionSort}(h_t)$ là $O(n)$.
    
        Tương tự, số phần tử trong phần này cũng là bậc $O(\log^2 n)$, nên độ phức tạp thời gian của phần này là $O(n\log^2 n)$.
    
    Tóm lại, tổng độ phức tạp thời gian là $O(n\log^2 n)$.

### Độ phức tạp không gian

Độ phức tạp không gian của sắp xếp Shell là $O(1)$.

## Cài đặt

=== "C++[^ref1]"
    ```cpp
    template <typename T>
    void shell_sort(T array[], int length) {
      int h = 1;
      while (h < length / 3) {
        h = 3 * h + 1;
      }
      while (h >= 1) {
        for (int i = h; i < length; i++) {
          for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
            std::swap(array[j], array[j - h]);
          }
        }
        h = h / 3;
      }
    }
    ```

=== "Python"
    ```python
    def shell_sort(array, length):
        h = 1
        while h < length / 3:
            h = int(3 * h + 1)
        while h >= 1:
            for i in range(h, length):
                j = i
                while j >= h and array[j] < array[j - h]:
                    array[j], array[j - h] = array[j - h], array[j]
                    j -= h
            h = int(h / 3)
    ```

## Tài liệu tham khảo và chú thích

[^ref1]: [Shellsort - Wikipedia](https://en.wikipedia.org/wiki/Shellsort)
