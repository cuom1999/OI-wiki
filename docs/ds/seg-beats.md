Bài viết này giải thích cách dùng cây phân đoạn để xử lý cực trị lịch sử trên đoạn,
dựa trên hướng tiếp cận được Ji Ruyi nhắc tới trong
[luận văn đội tuyển quốc gia năm 2016][national-training-2016].

## Cực trị đoạn

Nói một cách khái quát, thao tác cực trị đoạn là lấy $\max$ hoặc $\min$ với $x$
cho toàn bộ các số trong đoạn $[l,r]$,
tức $a_i=\max(a_i,x)$ hoặc $a_i=\min(a_i,x)$.

???+ note "[HDU5306 Dãy số tuyệt đẹp](https://acm.hdu.edu.cn/showproblem.php?pid=5306)"
    Duy trì một dãy $a$, thực hiện các thao tác sau:

    1.  `0 l r t` $\forall l\le i\le r,~ a_i=\min(a_i,t)$.
    2.  `1 l r` xuất $\max\limits_{i=l}^r a_i$.
    3.  `2 l r` xuất $\sum\limits_{i=l}^r a_i$.

    Có nhiều bộ dữ liệu, thỏa $T\le 100,~\sum n,\sum m\le 10^6$.

Lấy $\min$ trên đoạn nghĩa là chỉ những số lớn hơn $t$ mới bị thay đổi.
Vì vậy đối tượng của thao tác không còn là toàn bộ đoạn,
mà là "các số lớn hơn $t$ trong đoạn này".
Từ đó có thể duy trì, tại mỗi nút, giá trị lớn nhất $Max$, giá trị lớn thứ hai $Se$,
tổng đoạn $Sum$ và số lượng giá trị lớn nhất $Cnt$ trong đoạn tương ứng.
Tiếp theo, xét thao tác lấy $\min$ với $t$ trên đoạn.

1.  Nếu $Max\le t$, $t$ không có tác dụng, trả về ngay.
2.  Nếu $Se<t < Max$, thì $t$ có thể cập nhật các giá trị lớn nhất trong đoạn hiện tại.
    Cộng $Cnt(t-Max)$ vào tổng đoạn, rồi cập nhật $Max$ thành $t$ và gắn một nhãn.
3.  Nếu $t\le Se$, lúc này chưa biết có bao nhiêu số sẽ bị cập nhật.
    Chiến lược là đệ quy xuống dưới, rồi đẩy thông tin lên.

Độ phức tạp của thuật toán này là bao nhiêu?
Dùng phân tích thế năng có thể chứng minh độ phức tạp là $O(m\log n)$.
Quá trình phân tích cụ thể có thể xem trong luận văn.

```cpp
--8<-- "docs/ds/code/seg-beats/seg-beats_1.cpp"
```

???+ note "[BZOJ4695 Nữ tuyển thủ giả nhất](https://loj.ac/p/6565)"
    Duy trì một dãy $a$, thực hiện các thao tác sau:

    1.  `1 l r x` $\forall l\le i\le r,~ a_i=a_i+x$.
    2.  `2 l r x` $\forall l\le i\le r,~ a_i=\max(a_i,x)$.
    3.  `3 l r x` $\forall l\le i\le r,~ a_i=\min(a_i,x)$.
    4.  `4 l r` xuất $\sum\limits_{i=l}^r a_i$.
    5.  `5 l r` xuất $\max\limits_{i=l}^r a_i$.
    6.  `6 l r` xuất $\min\limits_{i=l}^r a_i$.

    $n,m\le 5\times 10^5,~|a_i|\le 10^8$. Mọi thao tác loại $1$ có $|x|\le 10^3$,
    các thao tác còn lại thỏa $|x|\le 10^8$.

Với cùng phương pháp, cần duy trì giá trị lớn nhất, lớn thứ hai, số lượng giá trị lớn nhất,
giá trị nhỏ nhất, nhỏ thứ hai, số lượng giá trị nhỏ nhất và tổng đoạn.
Ngoài các thông tin này, còn cần duy trì các nhãn cộng đoạn, $\max$ đoạn và $\min$ đoạn.
So với bài trước, vấn đề mới nằm ở thứ tự đẩy nhãn xuống.
Chiến lược xử lý như sau:

1.  Xem nhãn cộng đoạn là nhãn có độ ưu tiên cao nhất, hai loại nhãn còn lại ngang hàng.
2.  Khi gắn một nhãn cộng $v$ cho một nút,
    ngoài việc dùng $v$ để cập nhật thông tin phụ và nhãn cộng đoạn của nút hiện tại,
    còn dùng $v$ để cập nhật các nhãn $\max$ đoạn và $\min$ đoạn.
3.  Khi lấy $\min$ với $v$ cho một nút
    (trong bước này bỏ qua quá trình đi xuống tìm nút, giả sử nhãn thỏa điều kiện để được gắn),
    ngoài việc cập nhật thông tin phụ, cần so sánh với nhãn $\max$ đoạn.
    Nếu $v$ nhỏ hơn nhãn $\max$ đoạn, thì cuối cùng mọi số đều sẽ trở thành $v$,
    nên cũng đổi nhãn $\max$ đoạn thành $v$.
    Nếu không thì bỏ qua.
4.  Lấy $\max$ với $v$ trên đoạn cũng tương tự.

Khi duy trì thông tin, với đoạn chỉ có một hoặc hai số,
có thể xảy ra hiện tượng các tập giá trị trùng nhau,
chẳng hạn một số vừa là giá trị lớn nhất vừa là giá trị nhỏ thứ hai; cần xử lý riêng.

```cpp
--8<-- "docs/ds/code/seg-beats/seg-beats_2.cpp"
```

Thầy Ji đã chứng minh độ phức tạp của thuật toán này là $O(m\log^2 n)$.

???+ note "Mzl loves segment tree"
    Có hai dãy $A,B$; ban đầu mọi số trong $B$ đều là $0$. Cần duy trì các thao tác:

    1.  Lấy $\min$ trên đoạn của $A$
    2.  Lấy $\max$ trên đoạn của $A$
    3.  Cộng đoạn trên $A$
    4.  Hỏi tổng đoạn của $B$

    Sau mỗi thao tác, nếu giá trị của $A_i$ thay đổi thì cộng $1$ vào $B_i$. $n,m\le 3\times 10^5$.

Trước hết xét thao tác cộng đoạn đơn giản nhất.
Chỉ cần $x\neq 0$ thì mọi số trong đoạn đều thay đổi,
nên chỉ việc cộng đoạn một lần cho $B$.

Với thao tác lấy cực trị trên đoạn, việc gắn nhãn và đẩy nhãn xuống tương ứng một-một với cách
cập nhật mảng $B$.
Về bản chất, chia các số của dãy thành ba loại:
giá trị lớn nhất, giá trị nhỏ nhất và không phải cực trị,
rồi duy trì riêng từng loại.
Dù không thật sự dựng ra tập cực trị cụ thể, điều đó không cản trở việc duy trì.
Vì vậy khi gắn nhãn, có thể đồng thời cập nhật thông tin cho $B$
(lưu ý: không phải gắn nhãn cho $B$, mà là cập nhật thông tin).
Khi truy vấn, truy vấn trên $A$; lúc đẩy nhãn xuống thì đồng thời cập nhật thông tin cho $B$.
Sau khi tìm được nút cần thiết, trả về thông tin của $B$.
Về bản chất, thao tác này giao việc duy trì thông tin cực trị cho $B$.
Ngoài ra vẫn phải xử lý vấn đề các tập giá trị bị trùng.

???+ note "[CTSN yêu cây phân đoạn](https://www.luogu.com.cn/problem/U180387)"
    Duy trì hai dãy $a,b$, thực hiện các thao tác sau:

    1.  `1 l r x` $\forall l\le i\le r,~ a_i=\min(a_i,x)$.
    2.  `2 l r x` $\forall l\le i\le r,~ b_i=\min(b_i,x)$.
    3.  `3 l r x` $\forall l\le i\le r,~ a_i=a_i+x$.
    4.  `4 l r x` $\forall l\le i\le r,~ b_i=b_i+x$.
    5.  `5 l r` xuất $\max\limits_{i=l}^r (a_i+b_i)$.

    $n,m\le 3\times 10^5,~|a_i|,|b_i|,|x|\le 10^9$.

Chia các ứng viên đáp án $A_i+B_i$ trong đoạn $[l,r]$ thành bốn loại:
cả $A_i,B_i$ đều không phải giá trị lớn nhất trên đoạn của dãy $A,B$;
$A_i$ là giá trị lớn nhất trên đoạn của dãy $A$ nhưng $B_i$ không phải giá trị lớn nhất trên đoạn của dãy $B$;
$A_i$ không phải giá trị lớn nhất trên đoạn của dãy $A$ nhưng $B_i$ là giá trị lớn nhất trên đoạn của dãy $B$;
cả $A_i,B_i$ đều là giá trị lớn nhất trên đoạn của dãy $A,B$.
Gọi lần lượt là $C_{0,0},C_{1,0},C_{0,1},C_{1,1}$.
Ngoài ra vẫn duy trì bình thường giá trị lớn nhất và lớn thứ hai trên đoạn của hai dãy $A,B$.
Khi đẩy nhãn cộng đoạn và nhãn $\min$ xuống,
cách xử lý giá trị lớn nhất và lớn thứ hai của $A,B$ giống hai ví dụ trên.
Nhãn $\min$ của $A$ sẽ ảnh hưởng tới $C_{1,1}$ và $C_{1,0}$,
còn nhãn của $B$ sẽ ảnh hưởng tới $C_{1,1}$ và $C_{0,1}$.
Phép cộng trên $A,B$ sẽ ảnh hưởng tới cả $C_{0,0},C_{1,0},C_{0,1},C_{1,1}$.
Chỉ cần lưu ý các trường hợp biên khi $C_{0,0},C_{1,0},C_{0,1}$ không tồn tại
(ví dụ đoạn $[i,i]$ chỉ có giá trị lớn nhất của $A,B$ và $C_{1,1}$ tồn tại).

Tiếp theo cần xét cách duy trì $C_{0,0},C_{1,0},C_{0,1},C_{1,1}$ khi đẩy thông tin lên.
Có thể xét sau khi đã cập nhật giá trị lớn nhất của $A,B$,
rồi thảo luận xem giá trị lớn nhất của $A,B$ ở con trái và con phải
có bằng giá trị lớn nhất của $A,B$ ở nút hiện tại hay không.
Lấy con trái làm ví dụ; con phải xử lý tương tự:

-   Khi giá trị lớn nhất của $A,B$ ở con trái đều bằng giá trị lớn nhất của $A,B$ ở nút hiện tại,
    các giá trị $C_{0,0},C_{1,0},C_{0,1},C_{1,1}$ của con trái
    sẽ lần lượt đóng góp cho $C_{0,0},C_{1,0},C_{0,1},C_{1,1}$ của nút hiện tại.
-   Khi giá trị lớn nhất của $A$ ở con trái bằng giá trị lớn nhất của $A$ ở nút hiện tại,
    nhưng giá trị lớn nhất của $B$ thì không bằng,
    $C_{1,0},C_{1,1}$ của con trái sẽ đóng góp cho $C_{1,0}$ của nút này,
    còn $C_{0,0},C_{0,1}$ sẽ đóng góp cho $C_{0,0}$ của nút này.
-   Khi giá trị lớn nhất của $A$ ở con trái không bằng giá trị lớn nhất của $A$ ở nút hiện tại,
    nhưng giá trị lớn nhất của $B$ thì bằng,
    $C_{0,1},C_{1,1}$ của con trái sẽ đóng góp cho $C_{0,1}$ của nút này,
    còn $C_{0,0},C_{1,0}$ sẽ đóng góp cho $C_{0,0}$ của nút này.
-   Khi giá trị lớn nhất của $A,B$ ở con trái đều không bằng giá trị lớn nhất của $A,B$ ở nút hiện tại,
    $C_{0,0},C_{1,0},C_{0,1},C_{1,1}$ của con trái chỉ đóng góp cho $C_{0,0}$ của nút này.

$\max(C_{0,0},C_{1,0},C_{0,1},C_{1,1})$ của kết quả truy vấn đoạn chính là đáp án cần tìm.

Do cần đồng thời duy trì $\min$ đoạn và cộng đoạn, độ phức tạp vẫn là $O(m\log^2 n)$.

```cpp
--8<-- "docs/ds/code/seg-beats/seg-beats_4.cpp"
```

### Tổng kết

Phần này đã đưa ra bốn bài ví dụ,
lần lượt giải thích cách duy trì thao tác cực trị đoạn cơ bản,
cách xử lý độ ưu tiên của nhiều nhãn,
tư tưởng phân loại tập giá trị và cách duy trì nhiều loại phân lớp.
Về bản chất, tư tưởng cơ bản khi xử lý cực trị đoạn là duy trì thông tin theo phân loại tập giá trị
và hợp nhất hiệu quả.
Phần tiếp theo thảo luận các vấn đề liên quan đến cực trị lịch sử trên đoạn.

## Bài toán cực trị lịch sử

### Cực trị lịch sử không phải là tính bền vững

Lưu ý, bài toán cực trị lịch sử được nhắc tới trong phần này khác với cấu trúc dữ liệu bền vững.
Gọi riêng lớp bài toán đặc biệt này là bài toán cực trị lịch sử.
Bài toán cực trị lịch sử có thể chia thành ba loại.

#### Cực đại lịch sử

Hiểu đơn giản, cực đại lịch sử của một vị trí là giá trị lớn nhất từng xuất hiện tại vị trí đó.
Định nghĩa hình thức như sau: định nghĩa một mảng phụ $B$, ban đầu hoàn toàn giống $A$.
Sau mỗi thao tác trên $A$, lấy $\max$ cho toàn bộ mảng:

$$
\forall i\in[1,n],\ B_i=\max(B_i,A_i)
$$

Khi đó, $B_i$ được gọi là cực đại lịch sử của vị trí này.

#### Cực tiểu lịch sử

Định nghĩa tương tự cực đại lịch sử.
Sau mỗi thao tác trên $A$, lấy $\min$ cho toàn bộ mảng.
Khi đó, $B_i$ được gọi là cực tiểu lịch sử của vị trí này.

#### Tổng các phiên bản lịch sử

Mảng phụ $B$ ban đầu toàn là $0$.
Sau mỗi thao tác, cộng toàn bộ mảng $A$ vào mảng $B$:

$$
\forall i\in[1,n], \ B_i=B_i+A_i
$$

$B_i$ được gọi là tổng các phiên bản lịch sử tại vị trí $i$.

Tiếp theo, chia bài toán cực trị lịch sử thành bốn loại để thảo luận.

### Các bài toán có thể xử lý bằng nhãn

???+ note "[Giám sát CPU](https://www.luogu.com.cn/problem/P4314)"
    Hai dãy $A,B$ ban đầu giống nhau:

    1.  Gán đoạn của $A$ thành $x$
    2.  Cộng $x$ vào đoạn của $A$
    3.  Hỏi $\max$ đoạn của $A$
    4.  Hỏi $\max$ đoạn của $B$

    Sau mỗi thao tác, cập nhật một lần:
    $\forall i\in [1,n],\ B_i=\max(B_i,A_i)$.
    $n,m\le 10^5$.

Trước hết chưa xét thao tác 1.
Khi chỉ có thao tác cộng đoạn, duy trì nhãn $Add$ biểu thị giá trị được cộng vào đoạn hiện tại;
nhãn này có thể giải quyết bài toán $\max$ đoạn.
Tiếp theo xét $\max$ đoạn lịch sử.
Định nghĩa nhãn $Pre$ với ý nghĩa:
trong vòng đời của nhãn này, đó là giá trị lớn nhất lịch sử của nhãn $Add$.

Định nghĩa này chưa thật trực quan, nên trước hết cần giải thích vòng đời của một nhãn.
Một nhãn sẽ trải qua quá trình sau:

1.  Được tạo tại nút $u$.
2.  Khi nút $u$ nhận một số nhãn mới, nó hợp nhất với nhãn mới (xét các nhãn cùng loại).
3.  Nhãn của nút $u$ được đẩy xuống các con của $u$, rồi nhãn của $u$ bị xóa.

Xem khoảng thời gian từ bước 1 đến trước bước 3 trong quá trình này là vòng đời của nhãn tại nút $u$.
Sau khi hai nhãn được hợp nhất và trở thành cùng một nhãn,
vòng đời của chúng cũng được hợp nhất
(tức lấy thời điểm tạo sớm hơn làm thời điểm bắt đầu vòng đời).
Nói cách khác, đó là khoảng thời gian từ lần cuối cùng đẩy nhãn của nút này xuống đến thời điểm hiện tại.

Vì sao cần định nghĩa vòng đời?
Dựa vào khái niệm này, có thể chứng minh:
trong vòng đời của nhãn tại một nút,
các nút con của nó đều không thay đổi và vẫn giữ trạng thái trước vòng đời này.
Lý do là trong khoảng thời gian đó không có thao tác đẩy nhãn xuống.

Do đó giá trị lớn nhất lịch sử của $Add$ trong vòng đời của nhãn hiện tại
có thể được cập nhật vào nhãn và thông tin của các nút con,
vì nhãn và thông tin của nút con trong khoảng thời gian này đều không thay đổi.
Khi đẩy nhãn của $u$ xuống con $s$ của nó, có:

$$
Pre_s=\max(Pre_s,Pre_u+Add_s),Add_s=Add_u+Add_s
$$

Việc cập nhật thông tin cũng tương tự: dùng nhãn tương ứng để cập nhật.

Tiếp theo xét thao tác 1.

Thao tác gán đoạn sẽ biến mọi số thành cùng một số.
Sau đó, dù tiếp tục cộng/trừ đoạn hay gán đoạn, mọi số trong cả đoạn vẫn là cùng một số
(trừ khi kết thúc vòng đời của nhãn hiện tại và đẩy nhãn xuống).
Vì vậy có thể xem mọi nhãn sau thao tác gán đoạn đầu tiên đều là nhãn gán đoạn.
Nói cách khác, vòng đời của một nhãn có thể chia thành hai giai đoạn:

1.  Giai đoạn hợp nhất một số nhãn cộng/trừ, chưa từng nhận nhãn gán.
2.  Giai đoạn nhãn gán, không còn nhãn cộng/trừ theo nghĩa riêng nữa (nhãn cộng/trừ được chuyển hóa thành nhãn gán).

Do đó tách nhãn Pre của nút này thành $(P_1,P_2)$.
$P_1$ biểu thị nhãn cộng/trừ lớn nhất trong giai đoạn thứ nhất;
$P_2$ biểu thị nhãn gán lớn nhất trong giai đoạn thứ hai.
Dùng phương pháp tương tự, có thể đẩy nhãn và cập nhật thông tin cho trường hợp này.
Độ phức tạp thời gian là $O(m\log n)$;
bài này không có thao tác lấy cực trị với $x$ trên đoạn.

```cpp
--8<-- "docs/ds/code/seg-beats/seg-beats_3.cpp"
```

[national-training-2016]: https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2016%E8%AE%BA%E6%96%87%E9%9B%86.pdf
