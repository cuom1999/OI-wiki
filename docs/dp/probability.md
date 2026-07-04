author: Tiphereth-A, ShaoChenHeng, Enter-tainer, ksyx, c-forrest, StudyingFather, H-J-Granger, iamtwz, imp2002, Ir1d, kenlig, LeBronGod, Marcythm, MegaOwIer, NachtgeistW, ouuan, Patchouliys, Soohti, TianKong-y, sun2snow

<span id="&#x5F15;&#x5165;"></span>
## Dẫn nhập

DP xác suất được dùng để giải các bài toán về xác suất và kỳ vọng. Nên có hiểu biết nhất định về nội dung [xác suất & kỳ vọng](../math/probability/exp-var.md) trước khi học phần này. Thông thường, khi giải bài toán xác suất ta cần duyệt theo thứ tự xuôi, còn khi giải bài toán kỳ vọng ta dùng thứ tự ngược. Nếu phương trình chuyển trạng thái được định nghĩa có vấn đề hậu hiệu, cần dùng thêm [khử Gauss](../math/numerical/gauss.md) để tối ưu. DP xác suất cũng thường được kết hợp với các kiến thức khác để kiểm tra, chẳng hạn [nén trạng thái](./state.md), chuyển DP trên cây, v.v.

<span id="&#x6982;&#x7387;-dp"></span>
## DP xác suất

Dạng bài này dùng cách đẩy xuôi, tức là đẩy từ trạng thái ban đầu tới kết quả. Tương tự DP nói chung, điểm khó vẫn là mô tả phương trình chuyển trạng thái; chỉ có điều dạng bài này được bọc trong kiến thức xác suất.

<span id="&#x4F8B;&#x9898;"></span>
### Ví dụ

???+ example "[Codeforces 148D Bag of mice](https://codeforces.com/problemset/problem/148/D)"
    Trong túi có $w$ con chuột trắng và $b$ con chuột đen. Công chúa và rồng lần lượt bắt chuột trong túi. Ai bắt được chuột trắng trước thì thắng; nếu trong túi không còn chuột và không ai bắt được chuột trắng thì tính là rồng thắng. Mỗi lượt công chúa bắt một con chuột; sau mỗi lần rồng bắt một con chuột sẽ có một con chuột chạy ra ngoài. Con chuột được bắt và con chuột chạy ra đều là ngẫu nhiên. Công chúa bắt trước. Hỏi xác suất công chúa thắng.

??? note "Lời giải"
    Gọi $f_{i,j}$ là xác suất công chúa thắng khi tới lượt công chúa và trong túi có $i$ con chuột trắng, $j$ con chuột đen. Khởi tạo biên: $f_{0,j}=0$ vì không còn chuột trắng thì tính là rồng thắng, $f_{i,0}=1$ vì bắt một con chắc chắn là chuột trắng nên công chúa thắng.
    Xét chuyển trạng thái của $f_{i,j}$:
    
    -   Công chúa bắt được một con chuột trắng, công chúa thắng. Xác suất là $\dfrac{i}{i+j}$.
    -   Công chúa bắt được một con chuột đen, rồng bắt được một con chuột trắng, rồng thắng. Xác suất là $\dfrac{j}{i+j}\cdot\dfrac{i}{i+j-1}$.
    -   Công chúa bắt được một con chuột đen, rồng bắt được một con chuột đen, một con chuột đen chạy ra, chuyển tới $f_{i,j-3}$. Xác suất là $\dfrac{j}{i+j}\cdot\dfrac{j-1}{i+j-1}\cdot\dfrac{j-2}{i+j-2}$.
    -   Công chúa bắt được một con chuột đen, rồng bắt được một con chuột đen, một con chuột trắng chạy ra, chuyển tới $f_{i-1,j-2}$. Xác suất là $\dfrac{j}{i+j}\cdot\dfrac{j-1}{i+j-1}\cdot\dfrac{i}{i+j-2}$.
    
    Vì ta xét xác suất công chúa thắng, trường hợp thứ hai không tham gia vào phép tính. Đồng thời cần bảo đảm hai trường hợp sau hợp lệ, nên còn phải kiểm tra kích thước của $i,j$: trường hợp thứ ba cần có ít nhất 3 con chuột đen, còn trường hợp thứ tư cần có 1 con chuột trắng và 2 con chuột đen.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/probability/probability_1.cpp"
    ```

<span id="&#x4E60;&#x9898;"></span>
### Bài tập

-   [POJ3071 Football](http://poj.org/problem?id=3071)
-   [CodeForces 768D Jon and Orbs](https://codeforces.com/problemset/problem/768/D)

<span id="&#x671F;&#x671B;-dp"></span>
## DP kỳ vọng

<span id="&#x4F8B;&#x9898;_1"></span>
### Ví dụ

???+ example "[POJ2096 Collecting Bugs](http://poj.org/problem?id=2096)"
    Một phần mềm có $s$ hệ thống con và có thể sinh ra $n$ loại bug. Mỗi ngày một người phát hiện một bug; bug này thuộc một loại bug nào đó và cũng thuộc một hệ thống con nào đó. Xác suất mỗi bug thuộc một hệ thống con cụ thể là $\dfrac{1}{s}$, và xác suất thuộc một loại bug cụ thể là $\dfrac{1}{n}$. Hãy tính số ngày kỳ vọng để phát hiện đủ $n$ loại bug và mỗi trong $s$ hệ thống con đều đã có bug được tìm thấy.

??? note "Lời giải"
    Gọi $f_{i,j}$ là số ngày kỳ vọng để đạt trạng thái mục tiêu khi đã tìm được $i$ loại bug và bug trong $j$ hệ thống con. Trạng thái mục tiêu ở đây là tìm đủ $n$ loại bug và bug trong đủ $s$ hệ thống con. Khi đó $f_{n,s}=0$, vì đã đạt trạng thái mục tiêu nên không cần thêm ngày nào để phát hiện bug nữa. Do đó ta bắt đầu truy hồi từ trạng thái mục tiêu, và đáp án là $f_{0,0}$.
    
    Xét chuyển trạng thái của $f_{i,j}$:
    
    -   $f_{i,j}$, phát hiện một bug thuộc một trong $i$ loại bug đã phát hiện và một trong $j$ hệ thống con đã phát hiện, xác suất là $p_1=\dfrac{i}{n}\cdot\dfrac{j}{s}$.
    -   $f_{i,j+1}$, phát hiện một bug thuộc một trong $i$ loại bug đã phát hiện, nhưng không thuộc hệ thống con đã phát hiện, xác suất là $p_2=\dfrac{i}{n}\cdot(1-\dfrac{j}{s})$.
    -   $f_{i+1,j}$, phát hiện một bug không thuộc loại bug đã phát hiện, nhưng thuộc một trong $j$ hệ thống con đã phát hiện, xác suất là $p_3=(1-\dfrac{i}{n})\cdot\dfrac{j}{s}$.
    -   $f_{i+1,j+1}$, phát hiện một bug không thuộc loại bug đã phát hiện và cũng không thuộc hệ thống con đã phát hiện, xác suất là $p_4=(1-\dfrac{i}{n})\cdot(1-\dfrac{j}{s})$.
    
    Theo tính tuyến tính của kỳ vọng, ta thu được phương trình chuyển trạng thái:
    
    $$
    \begin{aligned}
    f_{i,j} &= p_1\cdot f_{i,j}+p_2\cdot f_{i,j+1}+p_3\cdot f_{i+1,j}+p_4\cdot f_{i+1,j+1} + 1\\
    &= \dfrac{p_2\cdot f_{i,j+1}+p_3\cdot f_{i+1,j}+p_4\cdot f_{i+1,j+1}+1}{1-p_1}
    \end{aligned}
    $$

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/probability/probability_2.cpp"
    ```

???+ example "[「NOIP2016」Đổi phòng học](http://uoj.ac/problem/262)"
    Niu Niu phải học trong $n$ khoảng thời gian. Khoảng thời gian thứ $i$ học ở phòng số $c_i$, và có thể xin đổi sang phòng số $d_i$, với xác suất xin đổi thành công là $p_i$. Nhiều nhất có thể xin đổi $m$ tiết học. Sau khi học xong tiết ở khoảng thời gian thứ $i$, cậu phải đi tới phòng học của khoảng thời gian thứ $i+1$. Cho một đồ thị gồm $v$ phòng học và $e$ con đường; việc di chuyển sẽ tiêu hao thể lực. Cần chọn những môn nào để xin đổi sao cho giá trị kỳ vọng của tổng thể lực tiêu hao do di chuyển giữa các phòng học là nhỏ nhất, tức là tìm tổng quãng đường kỳ vọng nhỏ nhất.

??? note "Lời giải"
    Với đồ thị vô hướng liên thông này, trước tiên dùng Floyd để tìm đường đi ngắn nhất, thuận tiện cho các chuyển trạng thái phía sau. Lấy mỗi lần di chuyển làm một giai đoạn (từ khoảng thời gian thứ $i$ tới khoảng thời gian thứ $i+1$ là di chuyển một bước). Khi đó ở mỗi bước, với xác suất $p_i$ ta tới $d_i$, nhưng trong tất cả các $d_i$ chỉ được chọn $m$ cái; với xác suất $1-p_i$ ta tới $c_i$. Cần tìm tổng quãng đường kỳ vọng nhỏ nhất sau khi đi hết $n$ giai đoạn.
    
    Định nghĩa $f_{i,j,0/1}$ là tổng quãng đường kỳ vọng nhỏ nhất ở khoảng thời gian thứ $i$, khi tính cả khoảng thời gian này đã dùng $j$ cơ hội đổi phòng, và ở khoảng thời gian này đổi phòng (1) hoặc không đổi phòng (0). Khi đó đáp án là $\min \{f_{n,i,0},f_{n,i,1}\} ,i\in[0,m]$. Chú ý biên $f_{1,0,0}=f_{1,1,1}=0$.
    
    Xét chuyển trạng thái của $f_{i,j,0/1}$:
    
    -   Nếu giai đoạn này không đổi, tức $f_{i,j,0}$. Nó có thể chuyển từ trạng thái lần trước không đổi, khi đó là $f_{i-1,j,0}+w_{c_{i-1},c_{i}}$; cũng có thể chuyển từ trạng thái lần trước có đổi. Ở đây, kết hợp kiến thức xác suất có điều kiện và xác suất toàn phần, ta thu được $f_{i-1,j,1}+w_{d_{i-1},c_{i}}\cdot p_{i-1}+w_{c_{i-1},c_{i}}\cdot (1-p_{i-1})$. Phương trình chuyển trạng thái là:
    
    $$
    \begin{aligned}
    f_{i,j,0}=min(f_{i-1,j,0}+w_{c_{i-1},c_{i}},f_{i-1,j,1}+w_{d_{i-1},c_{i}}\cdot p_{i-1}+w_{c_{i-1},c_{i}}\cdot (1-p_{i-1}))
    \end{aligned}
    $$
    
    -   Nếu giai đoạn này đổi, tức $f_{i,j,1}$. Tương tự, nó có thể chuyển từ trạng thái lần trước không đổi, cũng có thể chuyển từ trạng thái lần trước có đổi. Khi gặp trường hợp không đổi thì nhân với $(1-p_i)$, gặp trường hợp đổi thì nhân với $p_i$; liệt kê tất cả các khả năng có thể xảy ra rồi tính là được. Ở đây không trình bày dài dòng từng trường hợp chuyển nữa; tin rằng sau ví dụ giai đoạn phía trên, phương trình chuyển trạng thái ở đây có thể được viết ra khá dễ dàng.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/probability/probability_3.cpp"
    ```

So sánh hai bài toán này có thể thấy: trong các bài dùng DP để tính kỳ vọng, việc bài toán yêu cầu tính một giá trị cụ thể hay tối ưu hóa sẽ ảnh hưởng phần nào tới cách thu được phương trình chuyển trạng thái. Nhưng dù là dùng DP để tính xác suất hay tính kỳ vọng, ta luôn không thể tách khỏi kiến thức xác suất và các bước liệt kê, rút gọn công thức tính toán; những chi tiết cần suy nghĩ khi viết phương trình chuyển trạng thái cũng tương tự nhau.

<span id="&#x4E60;&#x9898;_1"></span>
### Bài tập

-   [HDU3853 LOOPS](https://acm.hdu.edu.cn/showproblem.php?pid=3853)
-   [HDU4035 Maze](https://acm.hdu.edu.cn/showproblem.php?pid=4035)
-   [「SCOI2008」Cửa thưởng](https://www.luogu.com.cn/problem/P2473)

<span id="&#x6709;&#x540E;&#x6548;&#x6027;-dp"></span>
## DP có hậu hiệu

<span id="&#x4F8B;&#x9898;_2"></span>
### Ví dụ

???+ example "[CodeForces 24D Broken robot](https://codeforces.com/problemset/problem/24/D)"
    Cho một vùng ma trận $n \times m$. Một robot ban đầu ở hàng thứ $x$, cột thứ $y$. Ở mỗi bước, robot chọn với xác suất bằng nhau một trong các hành động: đứng yên, đi sang trái một ô, đi sang phải một ô, đi xuống một ô. Nếu robot đang ở biên thì nó sẽ không đi ra ngoài vùng. Hỏi số bước kỳ vọng để robot tới hàng cuối cùng.

??? note "Lời giải"
    Khi $m=1$, mỗi lần có xác suất $\dfrac{1}{2}$ đứng yên và xác suất $\dfrac{1}{2}$ đi xuống một ô, nên đáp án là $2\cdot (n-x)$.
    Gọi $f_{i,j}$ là số bước kỳ vọng để robot xuất phát từ hàng thứ $i$, cột thứ $j$ và tới được hàng thứ $n$; trạng thái cuối là $f_{n,j}=0$.
    Vì robot chọn với xác suất bằng nhau giữa đứng yên, đi trái một bước, đi phải một bước và đi xuống một bước, xét chuyển trạng thái của $f_{i,j}$:
    
    -   $f_{i,1}=\dfrac{1}{3}\cdot(f_{i+1,1}+f_{i,2}+f_{i,1})+1$
    -   $f_{i,j}=\dfrac{1}{4}\cdot(f_{i,j}+f_{i,j-1}+f_{i,j+1}+f_{i+1,j})+1$
    -   $f_{i,m}=\dfrac{1}{3}\cdot(f_{i,m}+f_{i,m-1}+f_{i+1,m})+1$
    
    Giữa các hàng, vì robot chỉ có thể đi xuống nên thỏa mãn tính không hậu hiệu. Giữa các cột, robot có thể đi trái phải, trong quá trình di chuyển có thể sinh ra chu trình, nên không thỏa mãn tính không hậu hiệu.
    Sau khi biến đổi phương trình, ta được:
    
    -   $2f_{i,1}-f_{i,2}=3+f_{i+1,1}$
    -   $3f_{i,j}-f_{i,j-1}-f_{i,j+1}=4+f_{i+1,j}$
    -   $2f_{i,m}-f_{i,m-1}=3+f_{i+1,m}$
    
    Vì đây là truy hồi theo thứ tự ngược, mỗi $f_{i+1,j}$ đều đã biết.
    Do có $m$ cột, vế phải tương đương với một vector cột $m$ hàng, còn vế trái là một ma trận $m$ hàng, $m$ cột. Dùng ma trận mở rộng, bài toán trở thành một ma trận $m$ hàng, $m+1$ cột; sau đó dùng [khử Gauss](../math/numerical/gauss.md) là có thể giải ra đáp án.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/probability/probability_4.cpp"
    ```

<span id="&#x4E60;&#x9898;_2"></span>
### Bài tập

-   [HDU 4418 Time Travel](https://acm.hdu.edu.cn/showproblem.php?pid=4418)
-   [「HNOI2013」Đi dạo](https://loj.ac/problem/2383)

<span id="&#x53C2;&#x8003;&#x6587;&#x732E;"></span>
## Tài liệu tham khảo

[Tổng kết DP xác suất của kuangbin](https://www.cnblogs.com/kuangbin/archive/2012/10/02/2710606.html)
