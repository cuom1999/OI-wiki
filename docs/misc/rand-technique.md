author: Ir1d, partychicken, ouuan, Marcythm, TianyiQ

## Tổng quan

Kiến thức nền: [hàm ngẫu nhiên](../misc/random.md) và [xác suất sơ cấp](../math/probability/basic-conception.md)

Bài viết này phân loại sơ bộ các kỹ thuật liên quan đến ngẫu nhiên hóa trong OI/ICPC, đồng thời giới thiệu từng nhóm. Bài viết cũng nhắc đến một số phương pháp ít dùng trong OI/ICPC, nhưng khá gần với OI/ICPC về phong cách; các mục đó sẽ được đánh dấu bằng `(*)`.

Cách phân loại này không phải đồng thuận rộng rãi, và chắc chắn không bao quát hết mọi khả năng, vì vậy chỉ nên xem như tài liệu tham khảo.

**Ký hiệu và quy ước**:

-   $\mathrm{Pr}[A]$ biểu thị xác suất sự kiện $A$ xảy ra.
-   $\mathrm{E}[X]$ biểu thị kỳ vọng của biến ngẫu nhiên $X$.
-   Dấu gán $:=$ biểu thị việc giới thiệu một đại lượng mới; ví dụ $Y:=1926$ nghĩa là giới thiệu đại lượng $Y$ có giá trị $1926$.

## Dùng tập ngẫu nhiên để bao phủ phần tử mục tiêu

Trong không gian lời giải khổng lồ có một hoặc nhiều nghiệm cần tìm. Có thể thử "quăng lưới" nhiều lần; chỉ cần một lần bắt trúng nghiệm mục tiêu là thành công.

### Ví dụ: nhận định đồ thị ba phía

???+ note "Bài toán"
    Cho một đơn đồ thị vô hướng có $n$ đỉnh và $m$ cạnh. Cần tô mỗi đỉnh bằng một trong ba màu RGB sao cho mọi cặp đỉnh kề nhau có màu khác nhau, hoặc báo không có nghiệm.

Với mỗi đỉnh $v$, chọn độc lập và đều một màu $C_v$ trong $\{R,G,B\}$, rồi quy định rằng $v$ **không** được tô màu $C_v$. Xác suất một nghiệm tối ưu tình cờ thỏa đúng các ràng buộc này là $\big(\frac 23\big)^n$.

Dưới các ràng buộc đó, với một cặp đỉnh kề nhau $(u,v)$, yêu cầu "$u,v$ khác màu" tương đương với quan hệ "kéo theo" sau:

-   Với mọi màu $X$ khác $C_u,C_v$, nếu $u$ được tô màu $X$, thì $v$ được tô màu $\{R,G,B\}\setminus\{X,C_v\}$.

Do đó có thể gán cho mỗi $v$ một biến Boolean $B_v$, giá trị của nó biểu thị $v$ được tô bằng màu nào trong hai màu còn lại. Khi đó có thể dùng mô hình 2-SAT để giải bài toán trong $O(n+m)$.

Làm như vậy, xác suất đúng của một lần chạy là $\big(\frac 23\big)^n$. Lặp lại thuật toán $-\big(\frac 32\big)^n\log \epsilon$ lần; chỉ cần một lần tìm được nghiệm thì in ra. Như vậy có thể bảo đảm xác suất đúng $1-\epsilon$. Xem thêm phần "Phân tích cận trên xác suất" bên dưới.

***

**Nhìn lại**: trong bài này, "không gian lời giải" là tập $\{R,G,B\}^n$. Mỗi lần áp đặt ngẫu nhiên một số ràng buộc để tìm "nghiệm mục tiêu" trong một phạm vi đã thu hẹp, tức là một phương án tô màu hợp lệ.

### Ví dụ: [CodeChef SELEDGE](https://www.codechef.com/problems/SELEDGE)

???+ note "Tóm tắt đề bài"
    Cho một đồ thị vô hướng có trọng số không âm trên cả đỉnh và cạnh. Tìm một tập cạnh $S$ có kích thước $\leq K$ để tối đa hóa tổng trọng số của các đỉnh liên thông với $S$ trừ đi tổng trọng số các cạnh trong $S$. Trọng số của một đỉnh chỉ được tính một lần.

Nhận xét: nếu trong các cạnh đã chọn có ba cạnh tạo thành một đường đi, thì xóa cạnh ở giữa chắc chắn không tệ hơn; nếu trong các cạnh đã chọn có một số cạnh tạo thành chu trình, thì xóa bất kỳ cạnh nào cũng không tệ hơn.

Hệ quả: tập cạnh được chọn trong nghiệm tối ưu chắc chắn tạo thành một số đồ thị hoa cúc rời nhau, tức là các cây có đường kính không quá 2.

Hệ quả: tập cạnh được chọn trong nghiệm tối ưu chắc chắn tạo thành một đồ thị hai phía.

Tô mỗi đỉnh độc lập và đều bằng một trong hai màu đen/trắng, và yêu cầu cách tô màu này trùng với cách tô hai phía của đồ thị hai phía tương ứng với nghiệm tối ưu.

Thử tính xác suất nghiệm tối ưu thỏa yêu cầu này:

-   Xét một đồ thị hoa cúc có $n$ đỉnh. Nó có 2 cách tô màu, nên xác suất tô đúng màu là $\dfrac 2{2^n}=2^{1-n}$.
-   Giả sử số đỉnh của từng hoa cúc trong nghiệm tối ưu lần lượt là $a_1,\cdots,a_l$. Khi đó chắc chắn có $(a_1-1)+\cdots+(a_l-1)\leq K$, trong đó $K$ là số cạnh tối đa có thể chọn.
-   Suy ra xác suất tất cả các hoa cúc đều được tô đúng màu là $2^{1-a_1}\cdots 2^{1-a_l}\geq 2^{-K}$.

Dưới yêu cầu trên, thử lập mô hình luồng chi phí để tính đáp án tối ưu:

-   Lập đồ thị hai phía: đỉnh trắng ở bên trái và nối với $S$, đỉnh đen ở bên phải và nối với $T$.
    -   Với đỉnh trắng $v$, nối một cạnh từ $S$ đến nó có dung lượng 1 và chi phí $-A_v$, cùng một cạnh có dung lượng $\infty$ và chi phí 0.
    -   Với đỉnh đen $v$, nối một cạnh từ nó đến $T$ có dung lượng 1 và chi phí $-A_v$, cùng một cạnh có dung lượng $\infty$ và chi phí 0.
-   Với cạnh $(u,v,B)$ trong đồ thị gốc sao cho $u$ màu trắng và $v$ màu đen, nối một cạnh từ $u$ đến $v$ có dung lượng 1 và chi phí $B$.
-   Giới hạn luồng trong đồ thị này không vượt quá $K$; khi đó số đối của chi phí nhỏ nhất chính là đáp án.

Nếu dùng SPFA cho luồng chi phí, độ phức tạp là $O\big(K^2(n+m)\big)$. Chứng minh:

-   Trước hết, số lần chạy SPFA không vượt quá $K$.
-   Sau đó, trong một lần SPFA, mỗi đỉnh vào hàng đợi tối đa $O(K)$ lần. Lý do:
    -   Tại bất kỳ thời điểm nào, số cạnh có luồng không vượt quá $3K$; nếu không, trong đồ thị gốc đã chọn hơn $K$ cạnh.
    -   Với bất kỳ đường tăng luồng dài $L$, trong đó có ít nhất $\dfrac L2-2$ cạnh là cạnh ngược của một cạnh có luồng, vì các cạnh thuận đều đi từ trái sang phải của đồ thị, và chỉ các cạnh ngược này mới đi từ phải sang trái.
    -   Kết hợp hai ý trên, độ dài của bất kỳ đường tăng luồng nào không vượt quá $6K+4$.
-   Tóm lại, độ phức tạp là $O\big(K^2(n+m)\big)$.

Tương tự bài trước, cần lặp lại toàn bộ quá trình $-2^K \log\epsilon$ lần để đạt xác suất đúng $1-\epsilon$. Tổng độ phức tạp là $O\big(2^KK^2(n+m)\cdot -\log\epsilon\big)$.

## Dùng phần tử ngẫu nhiên để đánh trúng tập mục tiêu

Cần xác định bất kỳ một phần tử nào trong một tập; vì vậy chọn phần tử ngẫu nhiên, hy vọng chọn trúng tập này.

### Ví dụ: [Gym 101550I](https://codeforces.com/gym/101550/attachments)

???+ note "Tóm tắt đề bài"
    Có một đồ thị có dạng: hai chuỗi song song, cộng thêm hai cạnh song song nối giữa hai chuỗi. Cho một số đường đi đơn trên đồ thị này, mỗi đường đi biểu thị một cuộc gọi. Cần chọn ít cạnh nhất để đặt thiết bị nghe lén, sao cho trên mỗi đường đi đã cho đều có ít nhất một thiết bị nghe lén.

Toàn bộ đồ thị có thể tách thành một chu trình cộng với bốn chuỗi mọc từ chu trình đó. Với bất kỳ một trong bốn chuỗi này, ký hiệu là $C$, xét cách đặt thiết bị nghe lén trên chuỗi này. Dễ dàng dùng tham lam để thu được phương án thỏa các điều kiện sau:

-   Với điều kiện chặn được mọi cuộc gọi nằm hoàn toàn trong $C$, số thiết bị nghe lén được dùng là ít nhất.
-   Dưới điều kiện trên, khoảng cách ngắn nhất từ thiết bị nghe lén trên $C$ đến chu trình là nhỏ nhất có thể.
    -   Mục đích của yêu cầu này là chặn nhiều nhất các cuộc gọi có đúng một đầu mút nằm trong $C$.

Tiếp theo xét tổng cộng 4 cạnh nối giữa chuỗi và chu trình, và vét cạn xem trên các cạnh này có đặt thiết bị nghe lén hay không. Nếu muốn chặn các cuộc gọi cắt qua giữa chuỗi và chu trình, đặt thiết bị nghe lén trên 4 cạnh này chắc chắn là tối ưu. Bây giờ có thể chia các đường gọi thành các loại sau:

1.  Đường gọi nằm hoàn toàn trên chuỗi. Các đường này chắc chắn đã bị chặn, nên có thể bỏ qua.
2.  Đường gọi cắt qua chuỗi và chu trình, và đã bị chặn. Chúng có thể bị bỏ qua.
3.  Đường gọi cắt qua chuỗi và chu trình, nhưng chưa bị chặn. Có thể cắt bỏ phần trên chuỗi của nó, vì cách đặt thiết bị trên chuỗi đã cố định, và chỉ giữ lại phần trên chu trình.
4.  Đường gọi nằm hoàn toàn trên chu trình.

Đến đây, bài toán được chuyển thành bài toán trên chu trình.

Giả sử trong nghiệm tối ưu, tập cạnh trên chu trình có đặt thiết bị nghe lén là $S$. Nếu đã xác định được bất kỳ một phần tử $e$ nào trong $S$, có thể:

-   Cắt chu trình tại $e$ thành một chuỗi.
-   Sau đó tham lam bắt đầu từ $e$, liên tục tìm cạnh tiếp theo để đặt thiết bị nghe lén. Chú ý rằng nếu tiền xử lý thích hợp, mỗi bước tham lam có thể làm trong $O(1)$.
-   Từ đó giải bài toán trong $O(|S|)$.

Xét việc chọn ngẫu nhiên một cạnh $e'$ trên chu trình, quy định $e'\in S$, rồi thực hiện quá trình trên; lặp lại nhiều lần và lấy kết quả tốt nhất.

Phân tích độ phức tạp một lần:

-   Nhận xét: ký hiệu $S'$ là nghiệm tối ưu trong tất cả các phương án đã chọn $e'$, khi đó $|S'|\leq |S|+1$.
-   Vì vậy độ phức tạp một lần là $O(|S'|)=O(|S|)$.

Phân tích xác suất đúng:

-   Xác suất đúng một lần là $\dfrac {|S|}n$, trong đó $n$ là độ dài chu trình.
-   Do đó cần lặp lại $-\dfrac n{|S|}\log\epsilon$ lần để đạt xác suất đúng $1-\epsilon$.

Tổng hợp lại, độ phức tạp của thuật toán là $O\big(|S|\cdot -\dfrac n{|S|}\log\epsilon\big)=O(-n\log\epsilon)$.

### Ví dụ: [CSES 1685 New Flight Routes](https://cses.fi/problemset/task/1685)

???+ note "Tóm tắt đề bài"
    Cho một đồ thị có hướng. Cần thêm ít cạnh nhất để đồ thị liên thông mạnh, và phải **in ra phương án**.

Trước hết co đồ thị gốc theo các thành phần liên thông mạnh. Mục tiêu là làm cho mỗi đỉnh đích có thể đi đến mỗi đỉnh nguồn.

Có thể chứng minh rằng chỉ cần nối cạnh từ đỉnh đích đến đỉnh nguồn, vì mọi cạnh nối khác đều có thể tương ứng với một cạnh từ đỉnh đích đến đỉnh nguồn không yếu hơn nó.

Một thao tác cốt lõi là chọn đỉnh đích $t$ và đỉnh nguồn $s$ (không nhất thiết nằm trong cùng một thành phần liên thông yếu), rồi nối cạnh $t\to s$ để **làm cho cả $s$ và $t$ không còn là đỉnh nguồn hoặc đỉnh đích** (gọi là mục tiêu I). Lý tưởng thì mỗi thao tác như vậy giảm được một đỉnh đích và một đỉnh nguồn; liên tục thao tác cho đến khi chỉ còn một đỉnh đích hoặc chỉ còn một đỉnh nguồn, và trường hợp đó rất đơn giản. Từ đó đoán đáp án là số lớn hơn giữa số đỉnh nguồn và số đỉnh đích.

Điều kiện cần và đủ để thao tác trên đạt mục tiêu I là: $t$ có một tiền nhiệm khác $s$, và $s$ có một hậu nhiệm khác $t$. Có thể chứng minh (lát nữa sẽ đưa ra chứng minh) rằng với bất kỳ DAG nào có ít nhất hai đỉnh nguồn và ít nhất hai đỉnh đích, luôn tồn tại cặp $(s,t)$ như vậy; nhưng kết luận tồn tại không giúp xây dựng phương án, nên cần phân tích thêm.

-   Dùng điều kiện cần và đủ này vẫn khó suy ra thuật toán trực tiếp, chủ yếu vì sau khi nối cạnh $t\to s$, tính hợp lệ của các cặp $(s',t')$ khác có thể bị ảnh hưởng, điều này khá khó xử lý.

Chú ý rằng quan hệ giữa đỉnh nguồn và đỉnh đích được biết rất ít (thực ra ngay cả truy vấn nhanh một cặp $s-t$ có thể đi tới nhau hay không cũng cần tiền xử lý dfs + bitset, mà giới hạn thời gian không cho phép). Điều này gợi ý rằng cần một tính chất rất tổng quát và mạnh.

Nhận xét: số cặp $(s,t)$ không thỏa mục tiêu I nhiều nhất là $n+m-1$, trong đó $n$ là số đỉnh nguồn và $m$ là số đỉnh đích.

-   Lý do: với mỗi cặp $(s,t)$ như vậy, nếu xem nó như một cạnh giữa $s$ và $t$, thì đồ thị tạo bởi tất cả các cạnh này có dạng một số chuỗi rời nhau, nên số cạnh không vượt quá số đỉnh trừ một.
-   Động cơ của nhận xét này là: để áp dụng một kết quả tồn tại vào thuật toán, bước tiền đề thường là tăng cường kết quả định tính thành kết quả định lượng.

Hệ quả: chọn đều ngẫu nhiên $(s,t)$, xác suất thỏa yêu cầu trên $\geq \dfrac {(n-1)(m-1)}{nm}$.

-   Chú ý rằng kết luận này mạnh hơn nghiêm ngặt so với kết luận tồn tại đã nêu trước đó.

Hệ quả: chọn độc lập và đều ngẫu nhiên liên tiếp $\dfrac {\min(n,m)}2$ cặp $(s,t)$ không có phần tử chung, và **lần lượt** thao tác trên chúng (tức là nối cạnh $t\to s$), thì xác suất tất cả các thao tác đều thỏa mục tiêu I là $\geq \dfrac 14$.

-   Lý do:

$$
\begin{aligned}
&\phantom{=\ }\dfrac {(n-1)(m-1)}{nm}\cdot\dfrac{(n-2)(m-2)}{(n-1)(m-1)}\cdots\dfrac{(n-k)(m-k)}{(n-k+1)(m-k+1)}\\
&=\dfrac{(n-k)(m-k)}{nm}\\
&\geq \dfrac 14
\end{aligned}
$$

Sau khi chọn liên tiếp $k$ cặp $(s,t)$, việc kiểm tra chúng có tất cả thỏa mục tiêu I hay không rất đơn giản: chỉ cần chạy lại phép co thành phần liên thông mạnh và kiểm tra $n,m$ có đều giảm $k$ hay không. Chú ý rằng nếu mỗi lần giảm $k=\dfrac{\min(n,m)}2$, thì $\min(n,m)$ sẽ trở thành 1 trong $O\big(\log(n+m)\big)$ vòng, tức là chuyển về trường hợp đơn giản.

???+ note "Mã giả của thuật toán"
    ```text
    trong khi n>1 và m>1:
        chọn ngẫu nhiên k=min(n,m)/2 cặp (s,t)
        thêm cạnh t->s cho tất cả các cặp này
        nếu new_n>n-k hoặc new_m>m-k:
            roll_back()
    solve_trivial()
    ```

Độ phức tạp $O\big((|V|+|E|) \log |V|\big)$.

***

**Nhìn lại**: cần xác định bất kỳ cặp $(s,t)$ nào có thể đạt mục tiêu I, nên chọn ngẫu nhiên $(s,t)$.

## Dùng ngẫu nhiên hóa để thu được tính chất của dữ liệu ngẫu nhiên

Nếu dữ liệu của một bài toán được sinh ngẫu nhiên, có thể lợi dụng tính chất của dữ liệu ngẫu nhiên để giải. Trong một số trường hợp, ngay cả khi dữ liệu không được sinh ngẫu nhiên, cũng có thể dùng ngẫu nhiên hóa để trao cho nó một số tính chất của dữ liệu ngẫu nhiên, từ đó hỗ trợ giải bài toán.

### Ví dụ: phương pháp gia tăng ngẫu nhiên

Một dãy phần tử sinh ngẫu nhiên có thể có các tính chất như "số lần nghiệm tối ưu của tiền tố thay đổi có kỳ vọng rất nhỏ"; phương pháp gia tăng ngẫu nhiên thu được các tính chất đó bằng cách xáo trộn ngẫu nhiên dãy đầu vào.

Xem chi tiết tại [phương pháp gia tăng ngẫu nhiên](../geometry/random-incremental.md).

### Ví dụ: lời giải ngẫu nhiên hóa cho [TopCoder MagicMolecule](https://archive.topcoder.com/ProblemStatement/pm/11705)

???+ note "Tóm tắt đề bài"
    Cho một đồ thị vô hướng có $n$ đỉnh, mỗi đỉnh có trọng số. Trong tất cả các clique có kích thước không nhỏ hơn $\dfrac {2n}3$, cần tìm clique có tổng trọng số lớn nhất.
    
    $n\leq 50$

Kỹ thuật gặp nhau ở giữa là hướng tiếp cận tự nhiên. Chia đều tập đỉnh thành hai nửa trái/phải $V_L,V_R$ (mỗi bên có kích thước $\dfrac n2$), tính mảng $f_{L,k}$ biểu thị tổng trọng số lớn nhất của mọi clique có kích thước $\geq k$ trong tập đỉnh $L\subseteq V_L$. Sau đó liệt kê mỗi clique $C_R$ ở nửa phải, tính các đỉnh bên trái nối với tất cả đỉnh trong $C_R$ (ký hiệu tập này là $N_L$), và dùng $f_{N_L,\frac 23 n-|C_R|}+\textit{value}(C_R)$ để cập nhật đáp án.

-   Chú ý có thể chuyển trạng thái mỗi $f_{L,k}$ trong $O(1)$. Cụ thể, lấy $d$ là một phần tử bất kỳ trong $L$, rồi chia trường hợp:
    -   Giả sử trong nghiệm tối ưu $d$ không nằm trong clique, thì chuyển từ $f_{L\setminus \{d\},k}$.
    -   Giả sử trong nghiệm tối ưu $d$ nằm trong clique, thì chuyển từ $f_{L\cap N(d),k}+\textit{value}(d)$, trong đó $N(d)$ là tập đỉnh kề của $d$.
    -   Đừng quên dùng $f_{L,k+1}$ để cập nhật $f_{L,k}$.

Cách giải này sẽ quá thời gian. Thử tối ưu:

-   Khi chia đôi tập đỉnh, chia đều một cách ngẫu nhiên. Khi đó tập đỉnh của nghiệm tối ưu $C_{res}$ cũng được chia đúng đôi với xác suất đáng kể, tức là $|C_{res}\cap V_L|=|C_{res}\cap V_R|$.
    -   Tất nhiên, $|C_{res}|$ có thể là số lẻ. Để đơn giản, phần này giả sử nó là số chẵn; trường hợp lẻ không làm thay đổi bản chất lời giải.
    -   Thực nghiệm cho thấy thử ngẫu nhiên khoảng 20 lần là với xác suất rất cao sẽ có ít nhất một lần thỏa tính chất này. Nói cách khác, nếu thuật toán dựa vào tính chất "$C_{res}$ được chia đôi", thì lặp lại thuật toán 20 lần và lấy kết quả tốt nhất cũng bảo đảm xác suất đúng rất cao.
-   Có tính chất này, có thể quy định trực tiếp kích thước của clique bên trái $L$ và clique bên phải $C_R$ đều $\geq \dfrac n3$. Điều này đem lại hai cải tiến về độ phức tạp:
    -   $f$ không cần lưu chiều kích thước.
    -   Vì chỉ cần xét các clique có kích thước $\geq \dfrac n3$, số lượng clique bên trái $L$ và clique bên phải $C_R$ cần xét cũng giảm mạnh, xuống khoảng $1.8\cdot 10^6$.
-   Nút thắt hiện tại trở thành việc tính tổng trọng số của một tập con ở một phía, vì việc này cần tiền xử lý $O\big(2^{|V_L|}+2^{|V_R|}\big)$.
    -   Cách giải: tiếp tục chia đôi bên trong $V_L,V_R$; khi truy vấn tổng trọng số của một tập con, tách tập con đó thành hai nửa để truy vấn, rồi cộng đáp án.
-   Như vậy là có thể qua bài này.

***

**Nhìn lại**: một tập ngẫu nhiên có tính chất "số lượng phần tử trong hai nửa được chia ra không chênh nhau quá lớn", và tính chất này thu được bằng cách chia ngẫu nhiên.

## Ngẫu nhiên hóa cho băm

### Ví dụ: [UOJ #207 Covalent Master Tours Changsha](https://uoj.ac/problem/207)

???+ note "Tóm tắt đề bài"
    Duy trì một cây thay đổi động và một tập cặp đỉnh thay đổi động. Cần hỗ trợ:
    
    -   Xóa cạnh, thêm cạnh. Bảo đảm kết quả vẫn là một cây.
    -   Thêm/xóa một cặp đỉnh.
    -   Cho một cạnh $e$, kiểm tra xem với mọi cặp đỉnh $(s,t)$ trong tập, $e$ có nằm trên đường đi đơn giữa $s,t$ hay không.

Với mỗi cạnh $e$ trong đồ thị, định nghĩa tập $S_e$ là tập các đường đi quan trọng đi qua cạnh đó, tức các cặp $(a,b)$ trong đề. Xét duy trì động giá trị băm của tập $S_e$ cho mỗi cạnh, khi đó có thể phán định $S_e$ có bằng toàn tập hay không, tức là $e$ có phải "cạnh bắt buộc phải đi qua" hay không.

Cách băm là: với mỗi $(a,b)$, gán một số nguyên không âm ngẫu nhiên $H_{(a,b)}$ nhỏ hơn $2^{64}$; giá trị băm của một tập là xor của các giá trị $H$ của phần tử trong tập.

Khi đó, giá trị băm của bất kỳ tập cố định nào đều tuân theo phân bố đều trên $R:=\left\{0,1,\cdots,2^{64}-1\right\}$, nói cách khác miền giá trị của băm là $R$ và xác suất lấy mỗi giá trị là bằng nhau. Lý do:

1.  Một $H_{(a,b)}$ riêng lẻ tuân theo phân bố đều.
2.  Xor của hai biến ngẫu nhiên độc lập và đều trên $R$ chắc chắn cũng đều trên $R$. Có thể chứng minh trực tiếp.

Do đó xác suất đúng của thuật toán này được bảo đảm.

Còn cách duy trì giá trị băm này thì dùng LCT là đủ.

### Ví dụ: [CodeChef PANIC](https://www.codechef.com/problems/PANIC) và phân tích tỉ lệ sai

Hướng giải đại khái của bài này:

1.  Có thể chứng minh[^ref1] rằng $S(N)$ tuân theo một truy hồi tuyến tính bậc $O(K)$ theo $N$.
2.  Dùng thuật toán BM để tìm truy hồi đó.
3.  Dựa vào truy hồi, dùng định lý Cayley-Hamilton để tính $S(N)$.

Phần này chỉ tập trung vào phần thứ hai, tức là cách tìm truy hồi của một dãy ma trận. Vì vậy chỉ cần xét bài toán sau:

???+ note "Bài toán"
    Cho một dãy ma trận. Dãy này, theo modulo $P:=998244353$, tuân theo một truy hồi tuyến tính thuần nhất (phép nhân vô hướng và phép cộng trong truy hồi được định nghĩa là phép nhân vô hướng và phép cộng ma trận). Cần tìm truy hồi ngắn nhất.

Nếu một dãy ma trận tuân theo một truy hồi $F$, thì mỗi phần tử của ma trận cũng chắc chắn tuân theo $F$. Tuy nhiên, nếu tìm truy hồi ngắn nhất $F'$ cho một vị trí nào đó, $F'$ có thể ngắn hơn $F$, gây ra vấn đề.

Cách xử lý: gán cho mỗi vị trí $(i,j)$ của ma trận một trọng số ngẫu nhiên $x_{i,j}<P$. Sau đó với mỗi ma trận trong dãy, tính tổng có trọng số của tất cả các vị trí theo modulo $P$, nối các số tính được từ mỗi ma trận thành một dãy số, cuối cùng chạy thuật toán BM trên dãy số thu được.

Phân tích tỉ lệ sai:

-   Giả sử cách làm trên tìm được một truy hồi bậc $l$ là $F'$, khác $F$ và không dài hơn $F$.
-   Vì dãy ma trận không tuân theo $F'$, nên chắc chắn tồn tại một vị trí $(i,j)$ trong ma trận sao cho dãy số tương ứng với vị trí đó, $S_{i,j}$, không tuân theo $F'$ tại một $N$ nào đó. Tức là:

$$
S(N)_{i,j}-F'_1S(N-1)_{i,j}-\cdots-F'_lS(N-l)_{i,j}\not\equiv 0\pmod {P}
$$

-   Giả sử $(i,j)$ là vị trí duy nhất không tuân theo, khi đó chắc chắn có:

$$
T_{i,j}:=\Big(x_{i,j}\cdot\big(S(N)_{i,j}-F'_1S(N-1)_{i,j}-\cdots-F'_lS(N-l)_{i,j}\big)\bmod P\Big)=0
$$

-   Điều này chỉ xảy ra khi $x_{i,j}=0$, với xác suất $P^{-1}$.
-   Nếu có nhiều vị trí không tuân theo thì sao?
    -   Với mỗi vị trí $(i,j)$ như vậy, dễ chứng minh $T_{i,j}$ tuân theo phân bố đều trên $R:=\{0,1,\cdots,P-1\}$.
    -   Tổng theo modulo của một số biến ngẫu nhiên độc lập và đều trên $R$ vẫn tuân theo phân bố đều trên $R$. Có thể chứng minh trực tiếp.
    -   Do đó tỉ lệ sai trong trường hợp này cũng là $P^{-1}$.

### Ví dụ: [UOJ #552 Isomorphism Checking Duck](https://uoj.ac/problem/552) và phân tích tỉ lệ sai

???+ note "Tóm tắt đề bài"
    Cho hai đồ thị có hướng $G_0,G_1$ có trọng số cạnh là các chữ cái thường. Với mỗi đồ thị, cần tính "đa tập các xâu tương ứng với tất cả đường đi" (có thể là tập vô hạn), và phán định hai đa tập này có bằng nhau hay không. Nếu không bằng nhau, cần đưa ra một xâu ngắn nhất sao cho số lần xuất hiện của nó trong hai đa tập là khác nhau.

Đặt $f_{K,i,j}$ là giá trị băm của đa tập gồm tất cả xâu tương ứng với mọi đường đi dài $j$ bắt đầu từ đỉnh $i$ trong đồ thị $G_K$. Xét mỗi trạng thái theo thứ tự tăng dần của $j$; khi chuyển trạng thái, liệt kê các cạnh ra của $i$ và quy định cạnh đó là cạnh đầu tiên trên đường đi.

Để phán định có tồn tại xâu xấu có độ dài $=L$ hay không, chỉ cần "tổng hợp" riêng các tập $\{f_{0,*,L}\}$ và $\{f_{1,*,L}\}$ rồi so sánh (ký tự đại diện `*` trong ngữ cảnh này biểu thị mọi đỉnh; ví dụ $\{f_{0,*,L}\}$ biểu thị tập tất cả $f_{0,i,L}$, trong đó $i$ chạy qua mọi đỉnh). Lời giải chính thức[^ref2] chứng minh độ dài xâu xấu ngắn nhất, nếu tồn tại, chắc chắn không vượt quá $n_1+n_2$, nên độ phức tạp của cách giải này đủ tin cậy.

Tiếp theo xét cách băm cụ thể. Chú ý rằng cách băm thông thường, tức là ánh xạ xâu $a_1a_2\cdots a_k$ thành $\big(a_1+Pa_2+P^2a_3+\cdots+P^{k-1}a_k\big)\bmod Q$, rồi đặt giá trị băm của đa tập là tổng giá trị băm các phần tử theo modulo $Q$, không dùng được trong bài toán này. Một phản ví dụ là tập `{"ab","cd"}` và tập `{"cb","ad"}` có giá trị băm như nhau, bất kể chọn $P,Q$ thế nào.

Vấn đề của cách làm trên nằm ở chỗ giá trị băm của một xâu là một tổng, nên mỗi hạng tử có thể bị tách ra và ghép lại. Để tránh vấn đề này, xét đổi giá trị băm thành dạng tích. Ngoài ra, tính giao hoán của phép nhân sẽ khiến các vị trí khác nhau không phân biệt được, nên cần gán trọng số khác nhau cho các vị trí khác nhau.

Với mỗi cặp $(c,j)$, trong đó $c$ là ký tự và $j$ là số nguyên biểu thị vị trí thứ mấy của $c$ trong một xâu, sinh trước một số ngẫu nhiên $x_{c,j}$. Sau đó ánh xạ xâu $a_1a_2\cdots a_k$ thành $x_{a_1,1}x_{a_2,2}\cdots x_{a_k,k}\bmod Q$ (trong đó $Q$ là một số nguyên tố **được chọn ngẫu nhiên**), rồi đặt giá trị băm của đa tập là tổng giá trị băm các phần tử theo modulo $Q$. Tiếp theo phân tích tỉ lệ sai.

???+ note "(*) Bổ đề Schwartz-Zippel"
    Cho $f\in F[z_1,\cdots,z_k]$ là một đa thức khác không bậc $d$ với $k$ biến trên trường $F$, và $S$ là một tập con hữu hạn của $F$. Khi đó có nhiều nhất $d\cdot |S|^{k-1}$ bộ $(z_1,\cdots,z_k)\in S^k$ thỏa $f(z_1,\cdots,z_k)=0$.
    
    ??? note "Nếu chưa biết trường là gì"
        Chỉ cần nhớ hai thứ sau đều là trường:
        
        1.  Hệ thặng dư modulo một số nguyên tố, cùng các phép toán trên đó.
        2.  Tập số thực, cùng các phép toán trên đó.
    
    Hệ quả: nếu $z_1,\cdots,z_k$ đều được chọn độc lập và đều ngẫu nhiên trong $S$, thì $\mathrm{Pr}\big[f(z_1,\cdots,z_k)=0\big]\leq \dfrac d{|S|}$.

Ký hiệu $F$ là trường ứng với hệ thặng dư modulo $Q$. Khi đó, với một $L\leq n_1+n_2$, $\sum\limits_i f_{0,i,L}$ và $\sum\limits_i f_{1,i,L}$ lần lượt tương ứng với hai đa thức nhiều biến bậc $L$ trên $F$ theo tập biến $\{x_{*,*}\}$. Gọi hai đa thức này là $P_0,P_1$.

Nếu giá trị băm của hai đa tập xâu khác nhau lại bằng nhau, có hai khả năng:

1.  $P_0\equiv P_1\pmod {Q}$, tức là hệ số của mỗi hạng tử trong $P_0,P_1$ đều bằng nhau theo modulo $Q$.
2.  $P_0\not\equiv P_1\pmod {Q}, P_0(x_{*,*})\equiv P_1(x_{*,*})\pmod {Q}$, tức là tuy $P_0,P_1$ không đồng nhất, bộ $\{x_{*,*}\}$ được chọn lại tình cờ làm giá trị tại điểm này của chúng bằng nhau.

Phân tích xác suất của trường hợp đầu:

-   Nhận xét: với bất kỳ $A\neq B; A,B\leq N$ và số nguyên tố $Q\leq Q_{\max}$ được chọn ngẫu nhiên, chắc chắn có:

$$
\mathrm{Pr}\big[A\equiv B\pmod {Q}\big]=O\Big(\dfrac{\log N \log Q_{max}}{Q_{max}}\Big)
$$

-   Lý do: để $A\equiv B$ đúng, $Q$ chắc chắn phải thỏa $Q\big|(A-B)$. Số lượng $Q$ như vậy là $\omega(A-B)\leq \log_2 N$; theo định lý số nguyên tố, số số nguyên tố khác nhau không vượt quá $Q_{\max}$ là $\Theta\Big(\dfrac {Q_{\max}}{\log Q_{\max}}\Big)$. Chia hai đại lượng này sẽ được công thức trên.
-   Trong nhận xét trên, lấy $A,B$ (với $A\neq B$) là hệ số của một hạng tử cụ thể trong $P_0,P_1$ (cũng bằng số lần xuất hiện của xâu ứng với hạng tử đó trong $G_0,G_1$). Khi đó $A,B\leq (m_1+m_2)^{L}$, suy ra:

$$
\mathrm{Pr}\big[A\equiv B\pmod {Q}\big]=O\Big(\dfrac{L\log (m_1+m_2) \log Q_{max}}{Q_{max}}\Big)
$$

-   Vì vậy chọn $Q_{\max}\approx 10^{12}$ là quá đủ. Nếu máy không hỗ trợ phép toán số nguyên lớn như vậy, có thể thay bằng băm đôi.

Phân tích xác suất của trường hợp sau:

-   Trong bổ đề Schwartz-Zippel:
    -   Lấy trường $F$ là trường ứng với hệ thặng dư modulo $Q$.
    -   Lấy $f(x_{*,*})=P_0(x_{*,*})-P_1(x_{*,*})$ là đa thức khác không bậc $L$.
    -   Lấy $S=F$.
-   Suy ra xác suất cần tìm $\leq \dfrac LQ$.

Chú ý rằng cần bảo đảm tính đúng cho mọi $L$, nên nếu muốn lập luận chặt chẽ thì cần dùng thêm Union Bound (xem bên dưới).

Trong thực hành không nhất thiết phải chọn modulo ngẫu nhiên, vì chẳng hạn dùng ngày sinh làm modulo thì trên thực tế cũng đã tương đương một số ngẫu nhiên.

### Ví dụ: (*) số lượng phần tử khác nhau trong ma trận con

???+ note "Bài toán"
    Cho ma trận $n\times m$, có $q$ truy vấn hỏi số lượng phần tử khác nhau trong một ma trận con liên tiếp. Yêu cầu thuật toán trực tuyến.
    
    Cho phép sai số tương đối $\epsilon$ và tỉ lệ sai $\delta$. Nói cách khác, cần trả lời ít nhất $(1-\delta)q$ truy vấn với sai số tương đối không vượt quá $\epsilon$ so với đáp án đúng.
    
    $n\cdot m\leq 2\cdot10^5;q\leq 10^6;\epsilon=0.5,\delta=0.2$

Bổ đề: cho $X_{1\cdots k}$ là các biến ngẫu nhiên độc lập, và có giá trị phân bố đều trong $[0,1]$. Khi đó $\mathrm{E}\big[\min\limits_i X_i\big]=\dfrac 1{k+1}$.

-   Chứng minh: xét một đường tròn đơn vị, trên đó có $k+1$ điểm có **vị trí tương đối** được chọn đều ngẫu nhiên, lần lượt ở các vị trí $0,X_1,X_2,\cdots,X_k$. Khi đó $\min\limits_i X_i$ bằng độ dài của một khoảng trống cụ thể trong $k+1$ khoảng trống. Vì các khoảng trống này "đối xứng" với nhau, kỳ vọng độ dài của bất kỳ khoảng trống cụ thể nào cũng là $\dfrac 1{k+1}$.

Lấy $k$ là số lượng phần tử khác nhau, và dựa vào bổ đề trên để suy ngược $k$ từ $\min\limits_i X_i$.

Xét dùng một hàm băm nào đó, ánh xạ mỗi phần tử trong ma trận một cách đều và độc lập vào số thực trong $[0,1]$, đồng thời các phần tử bằng nhau sẽ được ánh xạ đến cùng một số thực. Khi đó các số thực tương ứng với mọi phần tử trong một ma trận con, sau khi loại trùng, đúng là một thực thể của tập $\{X_1,\cdots,X_k\}$ ở trên, trong đó $k$ bằng số lượng phần tử khác nhau trong ma trận con.

Do đó có thuật toán:

1.  Gán giá trị băm trong $[0,1]$ cho các phần tử của ma trận. Để bảo đảm tính ngẫu nhiên, hàm băm có thể được hiện thực trực tiếp bằng `map` và bộ sinh số ngẫu nhiên: mỗi khi gặp một giá trị mới chưa từng xuất hiện thì gán cho nó một giá trị băm ngẫu nhiên.
2.  Khi trả lời truy vấn, tìm cách lấy giá trị băm nhỏ nhất $M$ trong ma trận con, và in $\dfrac 1M-1$.

Tuy nhiên, thuật toán này chưa đáp ứng mong muốn. Kỳ vọng của giá trị xuất ra là $\mathrm{E}\Big[\dfrac 1{\min\limits_i X_i}-1\Big]$, nhưng thực ra giá trị này không bằng $\dfrac 1{\mathrm{E}\big[\min\limits_i X_i\big]}-1=k$, mà có thể chứng minh là bằng $\infty$.

Nói cách khác, không thể trực tiếp đưa một giá trị lấy mẫu đơn lẻ của $\min\limits_i X_i$ vào mẫu số; phải tính kỳ vọng của nó trước, rồi mới đưa kỳ vọng đó vào mẫu số.

Tính kỳ vọng bằng cách nào? Lấy trung bình qua nhiều lần ngẫu nhiên.

Dùng $C$ nhóm hàm băm khác nhau để thực hiện riêng quá trình trên. Khi trả lời truy vấn, tính ra $C$ giá trị $M$ khác nhau, lấy trung bình $\overline M$, rồi in $\big(\overline M\big)^{-1}-1$.

Thực nghiệm cho thấy lấy $C\approx 80$ là đủ thỏa yêu cầu. Chứng minh chặt chẽ rất dài dòng, nên được lược bỏ.

Cuối cùng, làm sao tìm giá trị nhỏ nhất trong ma trận con? Dùng bảng S-T hai chiều là đủ, tiền xử lý $O(nm\log n\log m)$, trả lời truy vấn $O(1)$.

## Các ứng dụng khác của ngẫu nhiên hóa trong thuật toán

Những vai trò khác của ngẫu nhiên hóa còn bao gồm:

-   Tránh bị người tạo test dùng dữ liệu có chủ đích để làm hack. Ví dụ, khi tìm kiếm thì xáo trộn ngẫu nhiên thứ tự các đỉnh kề.
-   Bảo đảm các "thao tác" trong quá trình thuật toán có tính đều theo một ý nghĩa nào đó. Ví dụ thuật toán [mô phỏng luyện kim](../misc/simulated-annealing.md).

Trong các bối cảnh này, ngẫu nhiên hóa thường, nhưng không phải lúc nào cũng, gắn với các cách làm thử nghiệm hoặc lấy điểm một phần.

### Ví dụ: ["TJOI2015" Linear Algebra](https://loj.ac/problem/2100)

Thuật toán chuẩn của bài này là luồng mạng, nhưng phần này dùng cách làm thử nghiệm sau:

-   Mỗi lần chọn ngẫu nhiên một vị trí, lật giá trị tại vị trí đó, rồi tính giá trị và cập nhật đáp án.

??? note "Mã"
    ```cpp
    #include <algorithm>
    #include <cstdlib>
    #include <iostream>
    
    int n;
    
    int a[510], b[510], c[510][510], d[510];
    int p[510], q[510];
    
    int maxans = 0;
    
    void check() {
      memset(d, 0, sizeof d);
      int nowans = 0;
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) d[i] += a[j] * c[i][j];
      for (int i = 1; i <= n; i++) nowans += (d[i] - b[i]) * a[i];
      maxans = std::max(maxans, nowans);
    }
    
    int main() {
      srand(19260817);
      std::cin >> n;
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) std::cin >> c[i][j];
      for (int i = 1; i <= n; i++) std::cin >> b[i];
      for (int i = 1; i <= n; i++) a[i] = 1;
      check();
      for (int T = 1000; T; T--) {
        int tmp = rand() % n + 1;
        a[tmp] ^= 1;
        check();
      }
      std::cout << maxans << '\n';
    }
    ```

### Ví dụ: (*) heap ngẫu nhiên[^ref3]

Cách viết heap gộp được thường gặp nhất có lẽ là cây nghiêng trái, bảo đảm độ phức tạp của phép gộp bằng cách duy trì chiều cao để cây nghiêng trái. Tuy nhiên duy trì chiều cao hơi phiền, nên có thể muốn tránh việc này nếu có thể.

Vậy có thể xét dùng heap ngẫu nhiên: không đổi con theo chiều cao, mà đổi ngẫu nhiên.

???+ note "Mã"
    ```cpp
    struct Node {
      int child[2];
      long long val;
    } nd[100010];
    
    int root[100010];
    
    int merge(int u, int v) {
      if (!(u && v)) return u | v;
      int x = rand() & 1, p = nd[u].val > nd[v].val ? u : v;
      nd[p].child[x] = merge(nd[p].child[x], u + v - p);
      return p;
    }
    
    void pop(int &now) { now = merge(nd[now].child[0], nd[now].child[1]); }
    ```

Heap ngẫu nhiên không đặt bất kỳ yêu cầu cứng hay mềm nào lên hình dạng của heap; độ phức tạp kỳ vọng của phép gộp đúng cho bất kỳ hai heap nào, khi chúng là tham số của hàm `merge`. Chứng minh như sau.

???+ note "Chứng minh độ phức tạp kỳ vọng"
    Sẽ chứng minh rằng với bất kỳ heap $A$ nào, nếu bắt đầu từ nút gốc và mỗi lần chọn ngẫu nhiên đi sang trái hoặc phải cho đến khi không còn đường, thì kỳ vọng độ dài đường đi (tức số nút trên đường đi) là $h(A)\leq\log_2 (|A|+1)$.
    
    -   Chú ý trong quá trình trên, độ phức tạp kỳ vọng khi gộp hai heap $A,B$ là $O\big(h(A)+h(B)\big)$, nên kết luận trên bảo đảm độ phức tạp kỳ vọng của heap ngẫu nhiên.
    
    Chứng minh bằng quy nạp toán học. Trường hợp cơ sở là $A$ rỗng, kết luận đúng ngay. Giả sử $A$ không rỗng.
    
    Giả sử hai cây con của $A$ lần lượt là $L,R$, khi đó:
    
    $$
    \begin{align} h(A)
    &=1+\frac{h(L)+h(R)}2
    \\&\leq1+\frac{\log_2(|L|+1)+\log_2(|R|+1)}2
    \\&=\log_2{2\sqrt{(|L|+1)(|R|+1)}}
    \\&\leq\log_2{\frac{2\big((|L|+1)+(|R|+1)\big)}2}
    \\&=\log_2{(|A|+1)} \end{align}
    $$
    
    Chứng minh xong.

## Các kỹ thuật chứng minh liên quan đến tính ngẫu nhiên

Sau đây liệt kê một vài kỹ thuật khá hữu ích.

Vài mục ít ỏi này không thể là tất cả; nếu biết một kỹ thuật chưa được liệt kê, có thể bổ sung thêm.

### Phân tích cận trên xác suất

Xem chi tiết ở trang [bất đẳng thức xác suất](../math/probability/concentration-inequality.md).

Ngoài các bất đẳng thức đã nhắc trong trang trên, quá trình suy diễn cũng thường dùng kết luận sau:

**Sử dụng hằng số tự nhiên**: $\Big(1-\dfrac{1}{n}\Big)^n\leq \dfrac{1}{\mathrm{e}},\forall n\geq1$

-   Vế trái tăng đơn điệu theo $n\geq 1$ và có giới hạn tại $+\infty$ là $\dfrac{1}{\mathrm{e}}$, nên có kết luận này.
-   Điều này cho biết: nếu $n$ sự kiện độc lập với nhau, mỗi sự kiện xảy ra với xác suất $1-\dfrac 1n$, thì xác suất tất cả cùng xảy ra nhiều nhất là $\dfrac{1}{\mathrm{e}}$.

### Tư tưởng ghép cặp

Tư tưởng ghép cặp thường dùng để xử lý đồng thời hơn một đối tượng có tính ngẫu nhiên, hoặc xử lý đồng thời đối tượng ngẫu nhiên và đối tượng tất định.

#### Dẫn nhập: tính liên thông của đồ thị ngẫu nhiên

???+ note "Bài toán"
    Với $n \in \mathbf{N}^*; p,q\in [0,1]$ và $q\leq p$, cần chứng minh: kỳ vọng số thành phần liên thông của đồ thị ngẫu nhiên $G_1(n,p)$ không vượt quá kỳ vọng số thành phần liên thông của đồ thị ngẫu nhiên $G_2(n,q)$. Trong đó $G(n,\alpha)$ biểu thị một đơn đồ thị vô hướng $G$ có $n$ đỉnh, trong đó mỗi cạnh trong $\dfrac {n(n-1)}2$ cạnh có thể xuất hiện với xác suất $\alpha$, và các xác suất này độc lập với nhau.

Kết luận này trông rất tự nhiên, nhưng chứng minh nghiêm ngặt lại không dễ như vậy.

???+ note "Ý tưởng chứng minh"
    Tưởng tượng hai đồ thị này lần lượt dùng một bộ sinh số ngẫu nhiên 01 để biết mỗi cạnh có tồn tại hay không. Bộ sinh $T_1$ của $G_1$ mỗi lần xuất ra 1 với xác suất $p$, bộ sinh $T_2$ của $G_2$ mỗi lần xuất ra 1 với xác suất $q$. Như vậy, để xây dựng một đồ thị, chỉ cần chạy bộ sinh tương ứng $\dfrac {n(n-1)}2$ lần.
    
    Bây giờ gộp hai bộ sinh thành một. Xét bộ sinh số ngẫu nhiên $T$, mỗi lần xuất ra 0 với xác suất $q$, xuất ra 1 với xác suất $p-q$, và xuất ra 2 với xác suất $1-p$. Nếu chạy $T$ $\dfrac {n(n-1)}2$ lần, có thể đồng thời xây dựng $G_1$ và $G_2$. Cụ thể, nếu kết quả là 0 thì xem như cả $G_1$ và $G_2$ đều không có cạnh đang xét; nếu kết quả là 1 thì xem như chỉ $G_1$ có cạnh đang xét; nếu kết quả là 2 thì xem như cả $G_1$ và $G_2$ đều có cạnh đang xét.
    
    Dễ kiểm tra rằng $G_1$ và $G_2$ sinh ra như vậy phù hợp với định nghĩa của chúng, và trong mọi trường hợp cụ thể, tập cạnh của $G_2$ đều là tập con của tập cạnh của $G_1$. Vì thế trong mọi trường hợp cụ thể, số thành phần liên thông của $G_2$ không nhỏ hơn số thành phần liên thông của $G_1$; khi đó kỳ vọng tự nhiên cũng thỏa cùng quan hệ lớn nhỏ.

Tư tưởng được dùng trong đoạn chứng minh này gọi là "ghép cặp"; có thể hiểu theo nghĩa mặt chữ. Trong ví dụ này, nó thể hiện ở việc gộp hai quá trình ngẫu nhiên vốn độc lập thành một.

#### Ứng dụng: [NERC 2019 Problem G: Game Relics](https://codeforces.com/contest/1267/problem/G)

???+ note "Tóm tắt đề bài"
    Có một số vật phẩm, mỗi vật phẩm có giá $c_i$. Cần sở hữu tất cả vật phẩm, và có thể tùy ý thực hiện hai thao tác:
    
    1.  Chọn một vật phẩm $i$ chưa sở hữu, trả $c_i$ tiền để mua nó.
    2.  Trả $x$ tiền để rút đều ngẫu nhiên một vật phẩm trong tất cả vật phẩm (kể cả đã sở hữu). Nếu chưa sở hữu vật phẩm đó thì nhận được nó ngay; nếu đã sở hữu thì không nhận được gì, nhưng được hoàn lại $\dfrac x2$ tiền. $x$ là hằng số đầu vào.
    
    Hỏi chi phí kỳ vọng dưới chiến lược tối ưu.

Nhận xét: nếu chọn rút vật phẩm, thì chắc chắn sẽ tiếp tục rút cho đến khi nhận được vật phẩm mới.

-   Lý do: nếu rút một lần mà không nhận được vật phẩm mới, trạng thái mới giống hệt trạng thái trước khi rút. Vì vậy nếu hành động tối ưu ở trạng thái cũ là "rút một lần", thì hành động tối ưu ở trạng thái mới chắc chắn cũng là "rút thêm một lần".

Có thể tính $f_k$ biểu thị: nếu hiện đã sở hữu $k$ vật phẩm khác nhau, thì kỳ vọng cần tốn bao nhiêu tiền để rút được vật phẩm mới. Theo nhận xét vừa rồi, có thể xem trực tiếp $f_k$ như một chi phí cố định, tức là chuyển thành "mỗi lần trả $f_k$ tiền để nhận ngẫu nhiên một vật phẩm mới".

???+ note "Tính chi phí kỳ vọng"
    Có $f_k=\dfrac x2 \cdot (R-1)+x$, trong đó $R$ biểu thị số lần rút kỳ vọng để nhận được vật phẩm mới.
    
    Bổ đề: nếu một đồng xu có xác suất $p$ ra mặt ngửa, thì số lần tung kỳ vọng để lần đầu ra mặt ngửa là $\dfrac 1p$.
    
    -   Hiểu trực giác: $\dfrac 1p \cdot p = 1$, nên tung bấy nhiêu lần thì kỳ vọng thu được 1 lần mặt ngửa, nghe có vẻ hợp lý.
    -   Cách hiểu trực giác này có thể làm chặt chẽ bằng [luật số lớn](https://en.wikipedia.org/wiki/Law_of_large_numbers), bằng cách xét $n\to \infty$ thí nghiệm "liên tục tung đồng xu cho đến khi ra mặt ngửa". Chi tiết suy diễn được lược bỏ.
    -   Một cách chứng minh khả thi khác là đưa trực tiếp định nghĩa kỳ vọng vào và tính. Chi tiết suy diễn được lược bỏ.
    
    Xác suất rút một lần được vật phẩm mới là $\dfrac {n-k}n$, nên $R=\dfrac n{n-k}$.

Kết luận: chiến lược tối ưu chắc chắn là rút một số lần trước, rồi mua hết các vật phẩm chưa rút được.

Kết luận này phù hợp trực giác, vì $f_k$ tăng theo $k$, nên rút sớm có vẻ thực sự tốt hơn rút muộn.

???+ note "Chứng minh"
    Trước hết chứng minh một trường hợp đặc biệt. Sẽ chứng minh:
    
    -   Quá trình ngẫu nhiên $A$: mua vật phẩm $x$ trước, sau đó liên tục rút cho đến khi có tất cả vật phẩm.
    -   ... chắc chắn không tốt hơn ...
    -   Quá trình ngẫu nhiên $B$: liên tục rút cho đến khi có tất cả vật phẩm trừ $x$, sau đó nếu vẫn chưa có $x$ thì mua nó.
    
    Cho hai quá trình ngẫu nhiên $A$ và $B$ dùng cùng một bộ sinh số ngẫu nhiên. Tức là lần rút đầu tiên của $A$ và lần rút đầu tiên của $B$ sẽ rút trúng cùng một phần tử, lần thứ hai, thứ ba, ... cũng vậy.
    
    Khi đó số lần rút của $A$ và $B$ chắc chắn bằng nhau. Với một vật phẩm $y\neq x$ được $A$ rút trúng, quan sát thấy:
    
    -   Số vật phẩm đã sở hữu khi $A$ rút trúng $y$ chắc chắn lớn hơn hoặc bằng số vật phẩm đã sở hữu khi $B$ rút trúng $y$.
    
    Vì vậy chi phí một lần rút của $B$ không cao hơn của $A$, và tổng chi phí rút cũng không cao hơn của $A$.
    
    Chi phí mua của $B$ cũng không cao hơn của $A$. Tóm lại, $B$ chắc chắn không tệ hơn $A$.
    
    Sau đó có thể dùng quy nạp toán học để mở rộng kết luận này sang trường hợp tổng quát. Cụ thể, mỗi lần tìm lần mua cuối cùng trong chiến lược hiện tại, rồi theo kết luận trên, dời lần mua này về cuối chắc chắn không tệ hơn. Chi tiết lược bỏ.

Dựa trên kết luận này, lại chuyển đổi tương đương bài toán: thay thao tác "chọn một vật phẩm và trả giá tương ứng để mua" bằng "chọn ngẫu nhiên một vật phẩm chưa sở hữu và trả giá tương ứng để mua". Lý do tương đương là: vì mua chỉ dùng để dọn phần còn lại, chọn trúng vật phẩm nào cũng không quan trọng.

Bây giờ "rút" và "mua" về bản chất đã trở thành cùng một thao tác, chỉ khác giá tiền phải trả. Việc chọn mua hay rút không ảnh hưởng đến thứ tự nhận được vật phẩm, và mọi thứ tự nhận vật phẩm đều đồng khả năng.

Nhận xét: tại một thời điểm, nên chọn mua khi và chỉ khi chi phí lần rút tiếp theo (được xác định bởi số vật phẩm đã rút được) lớn hơn giá trung bình của các vật phẩm còn lại (nếu bằng nhau thì chọn cách nào cũng được).

-   Có thể chứng minh rằng theo thời gian, tốc độ tăng của chi phí rút chắc chắn không thấp hơn tốc độ tăng của giá trung bình các vật phẩm còn lại. Điều này cho thấy chỉ có một "điểm tới hạn" từ rút sang mua, và tiếp tục xác nhận kết luận trước đó.

Cuối cùng, liệt kê mọi trạng thái có thể, tức tập các phần tử đã sở hữu; tính xác suất xuất hiện của trạng thái đó (số hoán vị của các phần tử đã có chia cho tổng số phương án), nhân với chi phí của quyết định tối ưu ở trạng thái hiện tại (được xác định bởi số phần tử đã sở hữu và tổng giá các vật phẩm còn lại), rồi cộng lại. Quá trình này có thể tối ưu bằng quy hoạch động kiểu ba lô, như vậy là qua được bài này.

***

**Nhìn lại**: có thể thấy kỹ thuật ghép cặp được dùng hai lần trong bài này. Lần đầu là trong chứng minh, cho hai quá trình ngẫu nhiên dùng chung một nguồn ngẫu nhiên; lần thứ hai là chuyển việc mua thành mua ngẫu nhiên (tức đưa thêm nguồn ngẫu nhiên), từ đó làm cho hai thao tác mua và rút về bản chất được "ghép cặp" thành cùng một thao tác, tức là cho thao tác rút và mua chia sẻ cùng một nguồn ngẫu nhiên.

## Tài liệu tham khảo

[^ref1]: [PANIC - Editorial](https://discuss.codechef.com/t/panic-editorial/80145)

[^ref2]: [UOJ NOI Round #4 Day2 Editorial](https://peehs-moorhsum.blog.uoj.ac/blog/6375)

[^ref3]: [Anna Gambin and Adam Malinowski, Randomized Meldable Priority Queues](https://www.researchgate.net/publication/2801527_Randomized_Meldable_Priority_Queues)
