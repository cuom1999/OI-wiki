author: Ir1d, CBW2007, ChungZH, xhn16729, Xeonacid, tptpp, hsfzLZH1, ouuan, Marcythm, HeRaNO, greyqz, Chrogeek, partychicken, zhb2000, xyf007, Persdre, XiaoSuan250, hhc0001, ZhangZhanhaoxiang, Taoran\_01

Trang này giới thiệu các tư tưởng cơ bản của quy hoạch động, cũng như cách thiết kế trạng thái và phương trình chuyển trạng thái trong quy hoạch động, nhằm giúp người mới học có được cái nhìn ban đầu về chủ đề này.

Các trang khác trong phần này sẽ trình bày cách xây dựng mô hình quy hoạch động cho nhiều dạng bài khác nhau, cùng một số kỹ thuật tối ưu quy hoạch động.

<span id="&#x5F15;&#x5165;"></span>
## Dẫn nhập

???+ note "[\[IOI1994\] Tam giác số](https://www.luogu.com.cn/problem/P1216)"
    Cho một tam giác số có $r$ hàng ($r \leq 1000$). Cần tìm một đường đi bắt đầu từ đỉnh cao nhất và kết thúc ở một vị trí bất kỳ ở đáy sao cho tổng các số đi qua là lớn nhất. Mỗi bước có thể đi tới điểm ở phía dưới bên trái hoặc phía dưới bên phải của điểm hiện tại.
    
    ```plain
            7 
          3   8 
        8   1   0 
      2   7   4   4 
    4   5   2   6   5 
    ```
    
    Trong ví dụ trên, đường đi tối ưu là $7 \to 3 \to 8 \to 7 \to 5$.

Cách nghĩ thô sơ nhất là thử tất cả các đường đi. Vì số đường đi có bậc $O(2^r)$, cách làm này không thể chấp nhận được.

Hãy chú ý một sự thật: với một đường đi tối ưu, mỗi quyết định trên đường đi đó cũng phải tối ưu theo phần tương ứng.

Lấy đường đi tối ưu trong ví dụ làm minh họa. Nếu chỉ xét bốn bước đầu $7 \to 3 \to 8 \to 7$, thì không tồn tại đường đi nào từ đỉnh tới số thứ $2$ ở hàng $4$ có tổng trọng số lớn hơn.

Với mỗi điểm, quyết định ở bước tiếp theo chỉ có hai khả năng: đi xuống trái hoặc đi xuống phải (nếu tồn tại). Vì vậy, chỉ cần ghi lại trọng số lớn nhất tại điểm hiện tại, rồi dùng trọng số lớn nhất đó để thực hiện quyết định tiếp theo và cập nhật trọng số lớn nhất của các điểm phía sau.

Cách làm này còn có một lợi ích khác: ta đã thu nhỏ quy mô bài toán, chia một bài toán thành nhiều bài toán nhỏ hơn. Muốn biết phương án tối ưu từ đỉnh tới hàng thứ $r$, chỉ cần biết thông tin về các phương án tối ưu từ đỉnh tới hàng thứ $r-1$.

Lúc này vẫn còn một vấn đề: giữa các bài toán con có rất nhiều phần chồng lặp, cùng một bài toán con có thể bị truy cập nhiều lần, nên hiệu quả vẫn chưa cao. Cách giải quyết là lưu lại lời giải của từng bài toán con và dùng kỹ thuật ghi nhớ để giới hạn thứ tự truy cập, bảo đảm mỗi bài toán con chỉ được truy cập một lần.

Trên đây là một số ý tưởng cơ bản của quy hoạch động. Phần dưới sẽ giới thiệu tư tưởng quy hoạch động một cách hệ thống hơn.

<span id="&#x52A8;&#x6001;&#x89C4;&#x5212;&#x539F;&#x7406;"></span>
## Nguyên lý quy hoạch động

Một bài toán có thể giải bằng quy hoạch động cần thỏa mãn ba điều kiện: cấu trúc con tối ưu, tính không hậu hiệu và các bài toán con chồng lặp.

<span id="&#x6700;&#x4F18;&#x5B50;&#x7ED3;&#x6784;"></span>
### Cấu trúc con tối ưu

Bài toán có cấu trúc con tối ưu cũng có thể phù hợp để giải bằng phương pháp tham lam.

Cần chú ý bảo đảm rằng ta đã xét tất cả các bài toán con được dùng trong lời giải tối ưu.

1.  Chứng minh thành phần đầu tiên của lời giải tối ưu cho bài toán là việc đưa ra một lựa chọn;
2.  Với một bài toán đã cho, trong các lựa chọn có thể ở bước đầu tiên, giả sử bạn đã biết lựa chọn nào sẽ dẫn tới lời giải tối ưu. Lúc này bạn không quan tâm lựa chọn đó được tìm ra cụ thể như thế nào, mà chỉ giả định rằng nó đã được biết;
3.  Sau khi đã biết lựa chọn của lời giải tối ưu có thể đạt được, xác định lựa chọn này sinh ra những bài toán con nào và cách mô tả không gian bài toán con tốt nhất;
4.  Chứng minh rằng, với vai trò là các thành phần cấu tạo nên lời giải tối ưu của bài toán gốc, lời giải của từng bài toán con chính là lời giải tối ưu của bản thân bài toán con đó. Cách chứng minh là phản chứng: giả sử lời giải của một bài toán con nào đó không phải lời giải tối ưu của chính nó, khi đó có thể thay lời giải không tối ưu hiện tại trong lời giải của bài toán gốc bằng lời giải tối ưu của bài toán con này, từ đó thu được một lời giải tốt hơn cho bài toán gốc, mâu thuẫn với giả thiết rằng lời giải ban đầu của bài toán gốc là tối ưu.

Cần giữ cho không gian bài toán con đơn giản nhất có thể, chỉ mở rộng khi thật cần thiết.

Sự khác nhau giữa các cấu trúc con tối ưu thể hiện ở hai khía cạnh:

1.  Lời giải tối ưu của bài toán gốc liên quan tới bao nhiêu bài toán con;
2.  Khi xác định lời giải tối ưu sử dụng những bài toán con nào, cần xét bao nhiêu lựa chọn.

Trong đồ thị bài toán con, mỗi đỉnh tương ứng với một bài toán con, còn các lựa chọn cần xét tương ứng với các cạnh nối tới đỉnh bài toán con.

<span id="&#x65E0;&#x540E;&#x6548;&#x6027;"></span>
### Tính không hậu hiệu

Các bài toán con đã được giải sẽ không còn bị ảnh hưởng bởi những quyết định về sau.

<span id="&#x5B50;&#x95EE;&#x9898;&#x91CD;&#x53E0;"></span>
### Bài toán con chồng lặp

Nếu có nhiều bài toán con chồng lặp, ta có thể dùng bộ nhớ để lưu lời giải của chúng, tránh giải lại cùng một bài toán con và nhờ đó nâng cao hiệu quả.

<span id="&#x57FA;&#x672C;&#x601D;&#x8DEF;"></span>
### Ý tưởng cơ bản

Với một bài toán có thể giải bằng quy hoạch động, thông thường ta xử lý theo các bước sau:

1.  Chia bài toán gốc thành một số **giai đoạn**; mỗi giai đoạn tương ứng với một số bài toán con, rồi trích xuất đặc trưng của các bài toán con đó (gọi là **trạng thái**);
2.  Tìm các **quyết định** có thể của mỗi trạng thái, hay nói cách khác là cách chuyển đổi qua lại giữa các trạng thái (mô tả bằng ngôn ngữ toán học chính là **phương trình chuyển trạng thái**).
3.  Giải lần lượt các bài toán ở từng giai đoạn theo đúng thứ tự.

Nếu hiểu theo góc nhìn đồ thị, ta xây dựng một [đồ thị có hướng không chu trình](../graph/dag.md), trong đó mỗi trạng thái tương ứng với một nút trên đồ thị, còn quyết định tương ứng với cạnh nối giữa các nút. Khi đó bài toán được chuyển thành bài toán tìm đường đi dài nhất (ngắn nhất) trên DAG (xem: [DP trên DAG](./dag.md)).

<span id="&#x6700;&#x957F;&#x516C;&#x5171;&#x5B50;&#x5E8F;&#x5217;"></span>
## Dãy con chung dài nhất

???+ note "Bài toán dãy con chung dài nhất"
    Cho một dãy $A$ độ dài $n$ và một dãy $B$ độ dài $m$ ($n,m \leq 5000$). Hãy tìm một dãy dài nhất sao cho dãy đó vừa là dãy con của $A$, vừa là dãy con của $B$.

Định nghĩa dãy con có thể xem tại [dãy con](../string/basic.md). Một ví dụ ngắn: chuỗi `abcde` và chuỗi `acde` có các dãy con chung `a`, `c`, `d`, `e`, `ac`, `ad`, `ae`, `cd`, `ce`, `de`, `acd`, `ade`, `ace`, `cde`, `acde`; độ dài dãy con chung dài nhất là 4.

Gọi $f(i,j)$ là độ dài dãy con chung dài nhất khi chỉ xét $i$ phần tử đầu của $A$ và $j$ phần tử đầu của $B$. Việc tìm độ dài dãy con chung dài nhất trong tình huống này chính là **bài toán con**. $f(i,j)$ là **trạng thái** mà ta nói tới; khi đó $f(n,m)$ là trạng thái cuối cùng cần đạt được, tức kết quả cần tìm.

Với mỗi $f(i,j)$, có ba quyết định: nếu $A_i=B_j$, ta có thể nối phần tử này vào cuối dãy con chung; hai quyết định còn lại lần lượt là bỏ qua $A_i$ hoặc bỏ qua $B_j$. Phương trình chuyển trạng thái như sau:

$$
f(i,j)=\begin{cases}f(i-1,j-1)+1&A_i=B_j\\\max(f(i-1,j),f(i,j-1))&A_i\ne B_j\end{cases}
$$

Bạn có thể tham khảo [trang tương tác LCS trên SourceForge](http://lcs-demo.sourceforge.net/) để hiểu rõ hơn quá trình cài đặt LCS.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/dp/code/basic/lcs.cpp:core"
        ```
    
    === "Python"
        ```cpp
        --8<-- "docs/dp/code/basic/lcs.py:core"
        ```

Độ phức tạp thời gian của cách làm này là $O(nm)$.

Ngoài ra, bài này còn có thuật toán $O\left(\dfrac{nm}{w}\right)$[^ref1]. Bạn đọc quan tâm có thể tự tìm hiểu thêm.

<span id="&#x6700;&#x957F;&#x4E0D;&#x4E0B;&#x964D;&#x5B50;&#x5E8F;&#x5217;"></span>
## Dãy con không giảm dài nhất

???+ note "Bài toán dãy con không giảm dài nhất"
    Cho một dãy $a$ độ dài $n$ ($n \leq 5000$). Hãy tìm một dãy con dài nhất của $a$ sao cho mỗi phần tử phía sau trong dãy con không nhỏ hơn phần tử ngay trước nó.

<span id="&#x7B97;&#x6CD5;&#x4E00;"></span>
### Thuật toán 1

Gọi $f(i)$ là độ dài dãy con không giảm dài nhất kết thúc tại $a_i$, khi đó đáp án cần tìm là $\max_{1 \leq i \leq n} f(i)$.

Khi tính $f(i)$, ta thử nối $a_i$ vào sau các dãy con không giảm dài nhất khác để cập nhật đáp án. Vì vậy có thể viết phương trình chuyển trạng thái: $f(i)=\max_{1 \leq j < i,~a_j \leq a_i} (f(j)+1)$.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/dp/code/basic/lis-1.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/dp/code/basic/lis-1.py:core"
        ```

Dễ thấy độ phức tạp thời gian của thuật toán này là $O(n^2)$.

<span id="&#x7B97;&#x6CD5;&#x4E8C;"></span>
### Thuật toán 2

Khi phạm vi của $n$ tăng lên $n \leq 10^5$, cách làm thứ nhất không còn đủ nhanh. Dưới đây là một cách làm $O(n \log n)$.

Xét trạng thái đã định nghĩa trước đó $(i, l)$, biểu thị rằng dãy con không giảm kết thúc tại phần tử thứ $i$ có độ dài lớn nhất là $l$. Khác với cách xử lý trạng thái theo $i$ cố định như thường lệ, ở đây ta trực tiếp xét xem $(i, l)$ có hợp lệ hay không:

-   Trạng thái ban đầu $(1,1)$ chắc chắn hợp lệ.
-   Với mọi $(i, l)$, nếu tồn tại $j < i$ sao cho $(j, l-1)$ hợp lệ và $a_j \le a_i$, thì $(i, l)$ hợp lệ.

Cuối cùng, chỉ cần tìm $(i,l)$ có $l$ lớn nhất trong các trạng thái hợp lệ là thu được độ dài dãy con không giảm dài nhất.

Gọi dãy ban đầu là $a_1, \cdots, a_n$. Định nghĩa mảng $d$, trong đó vị trí thứ $x$ biểu thị giá trị nhỏ nhất có thể của phần tử cuối trong một dãy con không giảm độ dài $x$. Ban đầu dãy rỗng. Cho $i$ chạy từ $1$ tới $n$, lần lượt tính độ dài dãy con không giảm dài nhất của $i$ phần tử đầu. Với phần tử hiện tại $a_i$:

-   Nếu $a_i$ lớn hơn hoặc bằng phần tử cuối cùng trong dãy $d$, trực tiếp chèn $a_i$ vào cuối dãy $d$.
    -   Giải thích: nếu $a_i$ lớn hơn hoặc bằng phần tử cuối của dãy con dài nhất hiện tại, nghĩa là tồn tại một dãy con không giảm có thể nối thêm $a_i$. Không chèn sẽ phá vỡ tính tối ưu.
-   Nếu $a_i$ nhỏ hơn nghiêm ngặt phần tử cuối cùng trong $d$, tìm phần tử **đầu tiên** lớn hơn nó và dùng $a_i$ thay thế phần tử đó.
    -   Giải thích: nếu chèn trực tiếp vào cuối, tính đơn điệu của $d$ sẽ bị phá vỡ; thao tác thay thế bảo đảm phần tử cuối của mỗi độ dài là nhỏ nhất có thể, từ đó giữ lại nhiều khả năng hơn cho các phần tử phía sau.
    -   Tối ưu: vì $d$ đơn điệu không giảm, có thể dùng tìm kiếm nhị phân để tìm trực tiếp vị trí chèn của phần tử, giảm độ phức tạp tổng thể xuống $O(n\log n)$ thay vì $O(n^2)$ khi tìm tuyến tính.

Nếu còn cần xuất ra một dãy con không giảm dài nhất cụ thể, có thể duy trì thêm mảng $d'_x$, biểu thị vị trí của phần tử cuối nhỏ nhất trong các dãy con không giảm độ dài $x$ (nếu có nhiều vị trí thì chọn tùy ý). Khi duy trì, mỗi khi chèn phần tử $a_i$ vào $d_x$, đồng thời cập nhật $d'_x$ thành $i$. Đồng thời cần ghi lại tiền nhiệm tối ưu $p_i$ của $i$ là $d'_{x-1}$. Cuối cùng, xuất phát từ một trạng thái có độ dài lớn nhất bất kỳ và lần theo các tiền nhiệm $p_i$ để truy vết, ta thu được dãy con đầy đủ.

???+ example "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/dp/code/basic/lis-2.cpp:core"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/dp/code/basic/lis-2.py:core"
        ```

Độ phức tạp thời gian của thuật toán này là $O(n\log n)$. Độ phức tạp thời gian để xuất đáp án là $O(\textit{ans})$.

???+ tip "Chú ý"
    Với bài toán dãy con **tăng** dài nhất, tương tự, có thể cho $d_i$ biểu thị giá trị nhỏ nhất của phần tử cuối trong mọi dãy con tăng dài nhất có độ dài $i$.
    
    Cần chú ý rằng ở bước 2, nếu $a_i \leq d_{len}$, do các phần tử kề nhau trong dãy con tăng dài nhất không được bằng nhau, cần tìm phần tử **đầu tiên** **không nhỏ hơn** $a_i$ trong dãy $d$ và dùng $a_i$ thay thế nó.
    
    Khi cài đặt (lấy C++ làm ví dụ), cần đổi hàm `upper_bound` thành `lower_bound`.

<span id="&#x53C2;&#x8003;&#x8D44;&#x6599;&#x4E0E;&#x6CE8;&#x91CA;"></span>
## Tài liệu tham khảo và chú thích

-   [Giải thích chi tiết thuật toán $n\log n$ cho dãy con không giảm dài nhất - lvmememe - cnblogs](https://www.cnblogs.com/itlqs/p/5743114.html)

[^ref1]: [Dùng phép toán bit để tìm dãy con chung dài nhất - -Wallace- - cnblogs](https://www.cnblogs.com/-Wallace-/p/bit-lcs.html)
