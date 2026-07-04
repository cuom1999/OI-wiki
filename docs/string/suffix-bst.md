<span id="&#23450;&#20041;"></span>
## Định nghĩa

Thứ tự giữa các hậu tố được định nghĩa theo thứ tự từ điển. Cây cân bằng hậu tố là một cây cân bằng dùng để duy trì thứ tự của các hậu tố này, tức là cây cân bằng hậu tố của chuỗi $T$ là tập có thứ tự gồm mọi hậu tố của $T$. Mỗi nút trên cây cân bằng hậu tố tương ứng với một hậu tố của chuỗi ban đầu.

Đặc biệt, phép duyệt trung thứ tự của cây cân bằng hậu tố chính là mảng hậu tố.

<span id="&#26500;&#36896;&#36807;&#31243;"></span>
## Quá trình xây dựng

Để xây dựng cây cân bằng hậu tố cho chuỗi $T$ có độ dài $n$, ta xét việc thêm các hậu tố vào cây cân bằng hậu tố theo thứ tự ngược.

Gọi tập mà cây cân bằng hậu tố đang duy trì là $X$, hậu tố hiện tại đang thêm là $S$. Khi thêm hậu tố tiếp theo, ta đưa $\texttt{c}S$ vào $X$ (cũng có thể hiểu rằng chuỗi đang được cây cân bằng hậu tố duy trì là $S$, và bước tiếp theo thêm một ký tự $\texttt{c}$ vào đầu $S$). Thao tác này thực chất là chèn một nút vào cây cân bằng.

Ở đây dùng một cây cân bằng có chiều cao kỳ vọng $O(\log n)$, chẳng hạn Scapegoat Tree hoặc Treap.

<span id="&#20570;&#27861;-1"></span>
### Cách 1

Khi chèn, so sánh trực tiếp hai hậu tố để xác định cần đi sang cây con nào. Như vậy, mỗi lần chèn so sánh nhiều nhất $O(\log n)$ lần, mỗi lần so sánh tốn tối đa $O(n)$, tổng cộng $O(n\log n)$.

Cần chèn tổng cộng $n$ lần, nên độ phức tạp thời gian của cách này có cận trên là $O(n^2 \log n)$.

<span id="&#20570;&#27861;-2"></span>
### Cách 2

Nhận xét rằng $\texttt{c}S$ chỉ khác $S$ ở ký tự $\texttt{c}$, và $S$ đã thuộc $X$. Có thể tận dụng điều này để tối ưu thao tác chèn.

Giả sử hiện cần so sánh hai chuỗi $\texttt{c}S$ và $A$, với $A, S \in X$. Mỗi lần so sánh, trước hết so sánh ký tự đầu của hai chuỗi. Nếu chúng khác nhau, quan hệ thứ tự đã được xác định; nếu chúng bằng nhau, chỉ cần xét quan hệ thứ tự của hai chuỗi sau khi bỏ ký tự đầu. Hai chuỗi sau khi bỏ ký tự đầu đều đã thuộc $X$, vì vậy có thể dùng thao tác tìm hạng $O(\log n)$ trên cây cân bằng để hoàn tất phần so sánh còn lại. Do đó, một lần chèn tốn nhiều nhất $O(\log^2 n)$.

Cần chèn tổng cộng $n$ lần, nên độ phức tạp thời gian của cách này có cận trên là $O(n \log^2 n)$.

<span id="&#20570;&#27861;-3"></span>
### Cách 3

Theo cách 2, nếu có thể xác định quan hệ thứ tự giữa hai nút trong cây cân bằng trong $O(1)$, ta có thể xây dựng cây cân bằng hậu tố trong thời gian $O(n \log n)$.

Gọi $val_i$ là giá trị của nút $i$. Nếu khi dựng cây cân bằng, mỗi nút duy trì thêm một nhãn $tag_i$ sao cho $tag_i > tag_j \iff val_i > val_j$, thì có thể dựa vào độ lớn của $tag_i$ để so sánh hai nút trong cây cân bằng trong $O(1)$.

Ta có thể cho mỗi nút trong cây cân bằng tương ứng với một khoảng số thực, trong đó nút gốc tương ứng với $(0, 1)$. Với nút $i$, gọi khoảng số thực tương ứng của nó là $(l, r)$, khi đó $tag_i = \frac{l + r}{2}$; cây con trái của nó tương ứng với $(l, tag_i)$, còn cây con phải tương ứng với $(tag_i, r)$. Dễ chứng minh rằng $tag_i$ thỏa mãn yêu cầu trên.

Vì dùng cây cân bằng có chiều cao kỳ vọng $O(\log n)$, độ chính xác số học được bảo đảm ở mức nhất định. Khi cài đặt thực tế cũng có thể dùng một khoảng lớn hơn, chẳng hạn cho gốc tương ứng với $(0, 10^{18})$.

<span id="&#20570;&#27861;-4"></span>
### Cách 4

Thực ra có thể xây dựng mảng hậu tố trước, rồi dựa trên mảng hậu tố để xây dựng cây cân bằng hậu tố. Khi đó nút thắt độ phức tạp nằm ở độ phức tạp xây dựng mảng hậu tố, hoặc độ phức tạp chèn một lần $n$ phần tử vào cây cân bằng được dùng.

<span id="&#21024;&#38500;&#25805;&#20316;"></span>
## Thao tác xóa

Giả sử hậu tố hiện tại được thêm là $\texttt{c}S$, còn hậu tố được thêm trước đó là $S$. Cây cân bằng hậu tố cũng hỗ trợ thao tác xóa hậu tố $\texttt{c}S$ (cũng có thể hiểu rằng chuỗi đang được cây cân bằng hậu tố duy trì là $\texttt{c}S$, và ta xóa ký tự $\texttt{c}$ ở đầu).

Tương tự thao tác chèn, có thể dựa vào thao tác xóa nút của cây cân bằng để xóa $\texttt{c}S$.

<span id="&#21518;&#32512;&#24179;&#34913;&#26641;&#30340;&#20248;&#28857;"></span>
## Ưu điểm của cây cân bằng hậu tố

-   Ý tưởng của cây cân bằng hậu tố khá rõ ràng; so với các cấu trúc hậu tố như máy tự động hậu tố, nó dễ hiểu hơn, và biết viết cây cân bằng là có thể cài đặt.
-   Độ phức tạp của cây cân bằng hậu tố không phụ thuộc vào kích thước bảng chữ cái.
-   Cây cân bằng hậu tố hỗ trợ xóa một ký tự ở đầu chuỗi.
-   Nếu dùng cây cân bằng hỗ trợ lưu phiên bản, cây cân bằng hậu tố cũng có thể lưu phiên bản.

<span id="&#20363;&#39064;"></span>
## Bài tập ví dụ

<span id="p3809&#27169;&#26495;&#21518;&#32512;&#25490;&#24207;"></span>
### [P3809 [Mẫu] Sắp xếp hậu tố](https://www.luogu.com.cn/problem/P3809)

Đây là bài mẫu về mảng hậu tố. Sau khi xây dựng cây cân bằng hậu tố, duyệt trung thứ tự để thu được mảng hậu tố.

??? note "Mã tham khảo phiên bản SGT"
    ```cpp
    --8<-- "docs/string/code/suffix-bst/suffix-bst_1.cpp"
    ```

<span id="p6164&#27169;&#26495;&#21518;&#32512;&#24179;&#34913;&#26641;"></span>
### [P6164 [Mẫu] Cây cân bằng hậu tố](https://www.luogu.com.cn/problem/P6164)

???+ note "Tóm tắt đề bài"
    Cho chuỗi ban đầu $s$ và $q$ thao tác:
    
    1.  Chèn một số ký tự vào cuối chuỗi hiện tại.
    2.  Xóa một số ký tự ở cuối chuỗi hiện tại.
    3.  Hỏi chuỗi $t$ xuất hiện bao nhiêu lần dưới dạng chuỗi con liên tiếp trong chuỗi hiện tại?
    
    Bài toán **bắt buộc online**, tổng độ dài biến đổi của chuỗi và độ dài ban đầu $\le 8 \times 10^5$, $q \le 10^5$, tổng độ dài các chuỗi truy vấn $\le 3 \times 10^6$.

Với thao tác 1 và thao tác 2, vì cây cân bằng hậu tố xử lý chèn đầu và xóa đầu thuận tiện hơn, ta biến chèn cuối và xóa cuối thành chèn đầu và xóa đầu. Nếu duy trì cây cân bằng hậu tố của chuỗi đảo của $s$, thay vì của chính $s$, phép biến đổi trên sẽ thực hiện được. Thêm và xóa trên cây cân bằng đều tốn $O(\log n)$, nên thêm hoặc xóa một ký tự tốn $O(\log n)$. Gọi tổng số ký tự được thêm và xóa là $N$, phần này có tổng độ phức tạp $O(N \log n)$.

Với thao tác 3, số lần xuất hiện của $t$ bằng số hậu tố có tiền tố là $t$, mà số hậu tố có tiền tố là $t$ bằng hạng của hậu tố kế tiếp trừ đi hạng của hậu tố đứng trước nó. Thêm một ký tự cực lớn vào sau $t$ sẽ dựng được một phần tử kế tiếp của $t$. Giảm ký tự cuối của $t$ đi $1$ sẽ dựng được một phần tử đứng trước $t$.

Bây giờ cần truy vấn hạng của một chuỗi $t$ trong cây cân bằng hậu tố. Vì không thể bảo đảm $t$ đã xuất hiện trong cây cân bằng hậu tố, mỗi lần chỉ có thể so sánh chuỗi trực tiếp. Một lần so sánh tốn $O(|t|)$, mỗi truy vấn so sánh nhiều nhất $O(\log n)$ lần, nên độ phức tạp của một truy vấn là $O(|t|\log n)$. Gọi tổng độ dài mọi chuỗi truy vấn là $L$, phần này có tổng độ phức tạp $O(L \log n)$.

??? note "Mã tham khảo phiên bản SGT"
    ```cpp
    --8<-- "docs/string/code/suffix-bst/suffix-bst_2.cpp"
    ```

<span id="&#21442;&#32771;&#36164;&#26009;"></span>
## Tài liệu tham khảo

-   Chen Lijie, "Ứng dụng của cây cân bằng theo trọng số và cây cân bằng hậu tố trong Olympic Tin học"
