## Bài toán về đoạn

Bắt đầu bằng một bài toán khá đơn giản:

> Với một hoán vị của $1$ đến $n$, gọi một khoảng chỉ số có miền giá trị liên tiếp là một đoạn.
> Hỏi một hoán vị có bao nhiêu đoạn.
> Ví dụ, các đoạn của $\{5,3,4,1,2\}$ là:
> $[1,1],[2,2],[3,3],[4,4],[5,5],[2,3],[4,5],[1,3],[2,5],[1,5]$.

Nhìn vào bài toán này, có vẻ cần duy trì tập miền giá trị của đoạn, và độ phức tạp dường như không mấy thân thiện.
Cây đoạn có thể truy vấn một đoạn nào đó có phải là đoạn hay không,
nhưng không thật sự thuận tiện để đếm số lượng đoạn.

Để xử lý bài toán này, có thể dùng cấu trúc dữ liệu **cây phân hợp**.

## Đoạn liên tiếp

Trước khi giới thiệu cây phân hợp, cần đặt ra một vài tiền đề.
Do định nghĩa trong slide LCA không dễ hiểu,
phần này dùng một số định nghĩa không quá nghiêm ngặt nhưng dễ tiếp cận hơn.

### Hoán vị và đoạn liên tiếp

**Hoán vị**: Một hoán vị $P$ bậc $n$ là một dãy có kích thước $n$ sao cho các $P_i$ nhận đủ các giá trị $1,2,\cdots,n$.
Nói hình thức hơn, hoán vị $P$ bậc $n$ là một tập có thứ tự thỏa mãn:

1.  $|P|=n$.
2.  $\forall i,P_i\in[1,n]$.
3.  $\nexists i,j\in[1,n],P_i=P_j$.

    **Đoạn liên tiếp**: Với hoán vị $P$, đoạn liên tiếp $(P,[l,r])$ là một đoạn $[l,r]$
    sao cho miền giá trị của $P_{l\sim r}$ là liên tiếp.
    Nói hình thức hơn, với hoán vị $P$, một đoạn liên tiếp là một đoạn $[l,r]$ thỏa mãn:

$$
(\nexists\ x,z\in[l,r],y\notin[l,r],\ P_x<P_y<P_z)
$$

Đặc biệt, khi $l>r$, xem đây là một đoạn liên tiếp rỗng, ký hiệu là $(P,\varnothing)$.

Gọi tập tất cả các đoạn liên tiếp của hoán vị $P$ là $I_P$, và xem $(P,\varnothing)\in I_P$.

### Phép toán trên đoạn liên tiếp

Đoạn liên tiếp được định nghĩa dựa trên đoạn và miền giá trị,
vì vậy có thể định nghĩa các phép giao, hợp, hiệu trên đoạn liên tiếp.

Định nghĩa $A=(P,[a,b]),B=(P,[x,y])$, và $A,B\in I_P$. Khi đó quan hệ và phép toán trên đoạn liên tiếp có thể biểu diễn như sau:

1.  $A\subseteq B\iff x\le a\wedge b\le y$.
2.  $A=B\iff a=x\wedge b=y$.
3.  $A\cap B=(P,[\max(a,x),\min(b,y)])$.
4.  $A\cup B=(P,[\min(a,x),\max(b,y)])$.
5.  $A\setminus B=(P,\{i|i\in[a,b]\wedge i\notin[x,y]\})$.

Các phép toán này chỉ là giao, hợp, hiệu thông thường của tập hợp đặt lên các đoạn.

### Tính chất của đoạn liên tiếp

Một vài tính chất cơ bản của đoạn liên tiếp:
với $A,B\in I_P,A \cap B \neq \varnothing,A \notin B,B \notin A$,
có $A\cup B,A\cap B,A\setminus B,B\setminus A\in I_P$.

Chứng minh? Bản chất của chứng minh chính là các phép giao, hợp, hiệu của tập hợp.

## Cây phân hợp

Đến phần trọng tâm: cây phân hợp là một cây được tạo thành từ các đoạn liên tiếp.
Một hoán vị có thể có tới $O(n^2)$ đoạn liên tiếp,
nên cần rút ra các đoạn liên tiếp cơ bản hơn để tạo thành cây phân hợp.

### Đoạn nguyên thủy

Tên đầy đủ của khái niệm này là **đoạn liên tiếp nguyên thủy**.
Để ngắn gọn, phần dưới gọi là đoạn nguyên thủy.

Với hoán vị $P$, một đoạn nguyên thủy $M$ là một đoạn trong tập $I_P$
sao cho không tồn tại đoạn liên tiếp giao với nó nhưng không chứa nó.
Định nghĩa hình thức là:
$X\in I_P$ và thỏa mãn $\forall A\in I_P,\ X\cap A= (P,\varnothing)\vee X\subseteq A\vee A\subseteq X$.

Tập tất cả các đoạn nguyên thủy là $M_P$. Theo định nghĩa, $(P,\varnothing)\in M_P$.

Giữa các đoạn nguyên thủy chỉ có quan hệ rời nhau hoặc bao chứa.
Đồng thời, **một đoạn liên tiếp có thể được cấu thành từ vài đoạn nguyên thủy đôi một không giao nhau**.
Đoạn nguyên thủy lớn nhất chính là toàn bộ hoán vị, chứa tất cả các đoạn nguyên thủy khác.
Vì vậy, các đoạn nguyên thủy có thể tạo thành một cấu trúc cây, gọi là **cây phân hợp**.
Nói nghiêm ngặt hơn, cây phân hợp của hoán vị $P$ được tạo bởi **tất cả các đoạn nguyên thủy** của hoán vị $P$.

Sau các định nghĩa trên, xét hoán vị $P=\{9,1,10,3,2,5,7,6,8,4\}$ làm ví dụ.
Cây phân hợp do các đoạn nguyên thủy của nó tạo thành như sau:

![Cây phân hợp của hoán vị ví dụ](./images/div-com1.png)

Trong hình không ghi rõ các đoạn nguyên thủy. **Mỗi nút trong hình đều đại diện cho một đoạn nguyên thủy**.
Hình chỉ ghi miền giá trị của mỗi đoạn nguyên thủy.
Ví dụ, đoạn nguyên thủy mà nút $[5,8]$ đại diện là $(P,[6,9])=\{5,7,6,8\}$.
Từ đây xuất hiện câu hỏi: **nút phân tách và nút hợp nhất là gì?**

### Nút phân tách và nút hợp nhất

Trước hết đưa ra định nghĩa, sau đó sẽ thảo luận về tính đúng đắn.

1.  **Đoạn miền giá trị**: Với một nút $u$, dùng $[u_l,u_r]$ để biểu diễn đoạn miền giá trị của nút đó.
2.  **Dãy con**: Với một nút $u$ trên cây phân hợp, giả sử các nút con của nó là một dãy **có thứ tự**,
    trong đó các phần tử là các đoạn miền giá trị.
    Một số đơn lẻ $x$ có thể hiểu là đoạn $[x,x]$.
    Gọi dãy này là dãy con, ký hiệu là $S_u$.
3.  **Hoán vị con**: Với một dãy con $S_u$, rời rạc hóa các phần tử của nó thành các số nguyên dương,
    hoán vị thu được gọi là hoán vị con.
    Ví dụ, với nút $[5,8]$, dãy con của nó là $\{[5,5],[6,7],[8,8]\}$;
    sau khi sắp xếp các đoạn và đánh số, hoán vị con của nó là $\{1,2,3\}$.
    Tương tự, hoán vị con của nút $[4,8]$ là $\{2,1\}$.
    Hoán vị con của nút $u$ được ký hiệu là $P_u$.
4.  **Nút hợp nhất**: Các nút có hoán vị con là thuận thứ tự hoặc nghịch thứ tự được xem là nút hợp nhất.
    Nói hình thức hơn, nút thỏa mãn $P_u=\{1,2,\cdots,|S_u|\}$
    hoặc $P_u=\{|S_u|,|S_u-1|,\cdots,1\}$ được gọi là nút hợp nhất.
    **Nút lá không có hoán vị con cũng được xem là nút hợp nhất**.
5.  **Nút phân tách**: Nút không phải nút hợp nhất là nút phân tách.

Trong hình, chỉ có $[1,10]$ không phải nút hợp nhất, vì hoán vị con của $[1,10]$ là $\{3,1,4,2\}$.

### Tính chất của nút phân tách và nút hợp nhất

Tên gọi nút phân tách và nút hợp nhất bắt nguồn từ tính chất của chúng.
Trước hết, với bất kỳ nút $u$ nào trong cây phân hợp,
hợp của các đoạn trong dãy con chính là đoạn miền giá trị của nút $u$.
Tức là $\bigcup_{i=1}^{|S_u|}S_u[i]=[u_l,u_r]$.

Với một nút hợp nhất $u$:
bất kỳ **đoạn con** nào của dãy con đều tạo thành một **đoạn liên tiếp**.
Nói hình thức hơn, $\forall S_u[l\sim r]$, có $\bigcup_{i=l}^rS_u[i]\in I_P$.

Với một nút phân tách $u$:
bất kỳ đoạn con nào của dãy con có **độ dài lớn hơn 1**
(độ dài tại đây là số lượng phần tử trong dãy con, không phải độ dài đoạn chỉ số)
đều **không** tạo thành một **đoạn liên tiếp**.
Nói hình thức hơn, $\forall S_u[l\sim r],l<r$, có $\bigcup_{i=l}^rS_u[i]\notin I_P$.

Tính chất của nút hợp nhất khá trực tiếp.
Vì hoán vị con của nút hợp nhất hoặc là thuận thứ tự, hoặc là đảo thứ tự,
và các đoạn miền giá trị cũng nối tiếp nhau ở đầu cuối,
nên bất kỳ một dãy con liên tiếp nào cũng là một đoạn liên tiếp.

Với tính chất của nút phân tách, điểm cần làm rõ là:
tại sao **bất kỳ** đoạn con nào có độ dài lớn hơn $1$ đều không tạo thành đoạn liên tiếp?

Dùng phản chứng. Giả sử với một nút $u$, trong dãy con của nó có một đoạn **dài nhất** $S_u[l\sim r]$
tạo thành đoạn liên tiếp.
Khi đó $A=\bigcup_{i=l}^rS_u[i]\in I_P$, cũng có nghĩa $A$ là một đoạn nguyên thủy.
Vì $A$ là đoạn dài nhất trong dãy con,
không thể tìm được một đoạn liên tiếp giao với nó nhưng không chứa nó.
Như vậy cây phân hợp này chưa dùng tất cả các đoạn nguyên thủy. Mâu thuẫn.

### Xây dựng cây phân hợp

Về cách xây dựng cụ thể cây phân hợp, LCA đưa ra một thuật toán xây dựng tuyến tính[^ref1]. Dưới đây là một thuật toán $O(n\log n)$ dễ hiểu hơn.

#### Phương pháp tăng dần

Xét phương pháp tăng dần. Dùng một ngăn xếp để duy trì rừng phân hợp được tạo bởi $i-1$ phần tử đầu tiên.
Cần **nhấn mạnh** rằng rừng phân hợp nghĩa là tại mọi thời điểm,
các nút trong ngăn xếp hoặc là nút phân tách, hoặc là nút hợp nhất.
Bây giờ xét nút hiện tại $P_i$.

1.  Trước hết kiểm tra nó có thể trở thành con của nút đỉnh ngăn xếp hay không.
    Nếu có thì biến nó thành con của đỉnh ngăn xếp, rồi lấy đỉnh ngăn xếp ra làm nút hiện tại.
    Lặp lại quá trình trên cho đến khi ngăn xếp rỗng hoặc không thể trở thành con của đỉnh ngăn xếp.
2.  Nếu không thể trở thành con của đỉnh ngăn xếp,
    kiểm tra xem có thể gộp một số nút liên tiếp ở đỉnh ngăn xếp thành một nút hay không.
    Cách kiểm tra có thể gộp hay không sẽ được trình bày phía sau.
    Lấy nút sau khi gộp làm nút hiện tại.
3.  Lặp lại quá trình trên cho đến khi không thể tiếp tục. Sau đó kết thúc lần tăng này và trực tiếp đẩy nút hiện tại vào ngăn xếp.

Tiếp theo là phần giải thích chi tiết hơn.

#### Chiến lược cụ thể

Nếu nút hiện tại có thể trở thành con của nút đỉnh ngăn xếp,
thì nút đỉnh ngăn xếp là một nút hợp nhất.
Nếu là nút phân tách, sau khi gộp thì nút phân tách này sẽ tồn tại một đoạn liên tiếp con,
không thỏa mãn tính chất của nút phân tách.
Vì vậy nó nhất định là nút hợp nhất.

Nếu không thể trở thành con của nút đỉnh ngăn xếp,
kiểm tra xem một số nút liên tiếp trên đỉnh ngăn xếp có thể gộp cùng nút hiện tại hay không.
Đặt $l$ là đầu trái của đoạn chứa nút hiện tại.
Tính $L_i$ là giá trị lớn nhất trong các đầu trái $< l$ của những đoạn liên tiếp có đầu phải là $i$.
Nút hiện tại là $P_i$, nút đỉnh ngăn xếp ký hiệu là $t$.

1.  Nếu $L_i$ không tồn tại, nút hiện tại không thể gộp.
2.  Nếu $t_l=L_i$, thì đây là gộp hai nút, và sau khi gộp thu được một **nút hợp nhất**.
3.  Ngược lại, trong ngăn xếp tồn tại một nút $t'$ có đầu trái ${t'}_l=L_i$,
    khi đó có thể gộp từ nút hiện tại đến $t'$ để tạo thành một **nút phân tách**.

#### Kiểm tra có thể gộp

Cuối cùng, xét cách xử lý $L_i$.
Trên thực tế, một đoạn liên tiếp $(P,[l,r])$ tương đương với hiệu giữa giá trị lớn nhất và nhỏ nhất của đoạn
bằng độ dài đoạn trừ 1. Tức là

$$
\max_{l\le i\le r}P_i-\min_{l\le i\le r}P_i=r-l
$$

Hơn nữa, vì P là một hoán vị, nên với mọi đoạn $[l,r]$ đều có

$$
\max_{l\le i\le r}P_i-\min_{l\le i\le r}P_i\ge r-l
$$

Vì vậy, duy trì $\max_{l\le i\le r}P_i-\min_{l\le i\le r}P_i-(r-l)$;
khi đó tìm một đoạn liên tiếp tương đương với truy vấn một giá trị nhỏ nhất.

Từ ý tưởng trên, có thể xây dựng thuật toán sau.
Với chỉ số hiện tại $i$ trong quá trình tăng dần,
duy trì một mảng $Q$ biểu diễn hiệu giữa khoảng biến thiên
(giá trị lớn nhất trừ giá trị nhỏ nhất) và độ dài của đoạn $[j,i]$. Tức là

$$
Q_j=\max_{j\le k\le i}P_k-\min_{j\le k\le i}P_k-(i-j),\ \ 0<j<i
$$

Khi đó cần biết trong $1\sim i-1$ có tồn tại một $j$ nhỏ nhất sao cho $Q_j=0$ hay không.
Điều này tương đương với tìm giá trị nhỏ nhất của $Q_{1\sim i-1}$.
$j$ nhỏ nhất tìm được chính là $L_i$. Nếu không có thì $L_i=i$.

Khi lần tăng thứ $i$ kết thúc, cần nhanh chóng cập nhật mảng $Q$ sang trường hợp $i+1$.
Đoạn ban đầu từ $[j,i]$ trở thành $[j,i+1]$;
nếu $P_{i+1}>\max$ hoặc $P_{i+1}<\min$ thì đều làm $Q_j$ thay đổi.
Nếu $P_{i+1}>\max$, tương đương với việc trước hết trừ $\max$ khỏi $Q_j$,
rồi cộng $P_{i+1}$ để hoàn tất cập nhật $Q_j$.
Trường hợp $P_{i+1}<\min$ tương tự, tương đương với $Q_j=Q_j+\min-P_{i+1}$.

Nếu với một đoạn $[x,y]$,
các đoạn $P_{x\sim i},P_{x+1\sim i},P_{x+2\sim i},\cdots,P_{y\sim i}$ đều có cùng $\max$,
thì thao tác này tương đương với thực hiện một phép cộng trên đoạn.
Tương tự, khi các đoạn $P_{x\sim i},P_{x+1\sim i},\cdots,P_{y\sim i}$ đều có cùng $\min$
thì cũng là một phép cộng trên đoạn.
Đồng thời, việc cập nhật $\max$ và $\min$ độc lập với nhau, nên có thể cập nhật riêng từng phần.

Do đó việc duy trì $Q$ có thể mô tả như sau:

1.  Tìm $j$ lớn nhất sao cho $P_{j}>P_{i+1}$.
    Khi đó tất cả các số trong $P_{j+1\sim i}$ đều nhỏ hơn $P_{i+1}$,
    nên cần cập nhật giá trị lớn nhất của $Q_{j+1\sim i}$.
    Vì $P_{i},\max(P_i,P_{i-1}),\max(P_i,P_{i-1},P_{i-2}),\cdots,\max(P_i,P_{i-1},\cdots,P_{j+1})$
    là một dãy tăng đơn điệu không nghiêm ngặt,
    nên với mỗi đoạn có cùng $\max$ cần thực hiện cùng một cập nhật, tức phép cộng trên đoạn.
2.  Cập nhật $\min$ tương tự.
3.  Trừ $1$ khỏi mọi $Q_j$, vì độ dài đoạn tăng thêm $1$.
4.  Truy vấn $L_i$: tức truy vấn **chỉ số** tại đó $Q$ đạt giá trị nhỏ nhất.

Có thể dùng cây đoạn để duy trì $Q$.
Vấn đề còn lại là tìm các đoạn có cùng $\max/\min$.
Dùng hai ngăn xếp đơn điệu, lần lượt biểu diễn $\max$ và $\min$.
Khi đó, trong ngăn xếp, các đoạn có hai phần tử kề nhau làm đầu mút sẽ có cùng $\max/\min$,
vì vậy khi duy trì ngăn xếp đơn điệu thì đồng thời cập nhật cây đoạn.

Cách duy trì cụ thể xem trong mã.

Hình dưới đây minh họa quá trình duy trì $Q$ bằng cây đoạn và ngăn xếp đơn điệu.
Lưu ý hình khá dài.

![Minh họa duy trì Q bằng cây đoạn và ngăn xếp đơn điệu](./images/div-com2.jpg)

### Cài đặt

Cuối cùng là một đoạn mã cài đặt để tham khảo.
Mã được chuyển từ [blog của Đại Mễ Bính](https://www.cnblogs.com/Paul-Guderian/p/11020708.html),
có thêm một số chú thích.

```cpp
#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int N = 200010;

int n, m, a[N], st1[N], st2[N], tp1, tp2, rt;
int L[N], R[N], M[N], id[N], cnt, typ[N], bin[20], st[N], tp;

// Bài gốc của đoạn mã này là CERC2017 Intrinsic Interval
// Mảng a chính là hoán vị tương ứng trong bài gốc
// st1 và st2 lần lượt là hai ngăn xếp đơn điệu, tp1 và tp2 là đỉnh ngăn xếp tương ứng, rt là gốc của cây phân hợp
// Mảng L và R biểu diễn đầu trái và đầu phải của nút trong cây phân hợp, mảng M đã được nhắc đến khi xây dựng cây
// id lưu chỉ số nút tương ứng với một vị trí trong hoán vị, typ dùng để đánh dấu nút phân tách hay nút hợp nhất
// st là ngăn xếp lưu chỉ số nút của cây phân hợp, tp là đỉnh ngăn xếp
struct RMQ {  // Tiền xử lý RMQ (Max & Min)
  int lg[N], mn[N][17], mx[N][17];

  void chkmn(int& x, int y) {
    if (x > y) x = y;
  }

  void chkmx(int& x, int y) {
    if (x < y) x = y;
  }

  void build() {
    for (int i = bin[0] = 1; i < 20; ++i) bin[i] = bin[i - 1] << 1;
    for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; ++i) mn[i][0] = mx[i][0] = a[i];
    for (int i = 1; i < 17; ++i)
      for (int j = 1; j + bin[i] - 1 <= n; ++j)
        mn[j][i] = min(mn[j][i - 1], mn[j + bin[i - 1]][i - 1]),
        mx[j][i] = max(mx[j][i - 1], mx[j + bin[i - 1]][i - 1]);
  }

  int ask_mn(int l, int r) {
    int t = lg[r - l + 1];
    return min(mn[l][t], mn[r - bin[t] + 1][t]);
  }

  int ask_mx(int l, int r) {
    int t = lg[r - l + 1];
    return max(mx[l][t], mx[r - bin[t] + 1][t]);
  }
} D;

// Duy trì L_i

struct SEG {  // Cây đoạn
#define ls (k << 1)
#define rs (k << 1 | 1)
  int mn[N << 1], ly[N << 1];  // Cộng trên đoạn. giá trị nhỏ nhất trên đoạn

  void pushup(int k) { mn[k] = min(mn[ls], mn[rs]); }

  void mfy(int k, int v) { mn[k] += v, ly[k] += v; }

  void pushdown(int k) {
    if (ly[k]) mfy(ls, ly[k]), mfy(rs, ly[k]), ly[k] = 0;
  }

  void update(int k, int l, int r, int x, int y, int v) {
    if (l == x && r == y) {
      mfy(k, v);
      return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if (y <= mid)
      update(ls, l, mid, x, y, v);
    else if (x > mid)
      update(rs, mid + 1, r, x, y, v);
    else
      update(ls, l, mid, x, mid, v), update(rs, mid + 1, r, mid + 1, y, v);
    pushup(k);
  }

  int query(int k, int l, int r) {  // Truy vấn vị trí của 0
    if (l == r) return l;
    pushdown(k);
    int mid = (l + r) >> 1;
    if (!mn[ls])
      return query(ls, l, mid);
    else
      return query(rs, mid + 1, r);
    // Nếu không tồn tại vị trí 0 thì sẽ tự động trả về vị trí hiện đang truy vấn
  }
} T;

int o = 1, hd[N], dep[N], fa[N][18];

struct Edge {
  int v, nt;
} E[N << 1];

void add(int u, int v) {  // Thêm cạnh vào cấu trúc cây
  E[o] = Edge{v, hd[u]};
  hd[u] = o++;
}

void dfs(int u) {
  for (int i = 1; bin[i] <= dep[u]; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = hd[u]; i; i = E[i].nt) {
    int v = E[i].v;
    dep[v] = dep[u] + 1;
    fa[v][0] = u;
    dfs(v);
  }
}

int go(int u, int d) {
  for (int i = 0; i < 18 && d; ++i)
    if (bin[i] & d) d ^= bin[i], u = fa[u][i];
  return u;
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  u = go(u, dep[u] - dep[v]);
  if (u == v) return u;
  for (int i = 17; ~i; --i)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}

// Kiểm tra đoạn hiện tại có phải là đoạn liên tiếp hay không
bool judge(int l, int r) { return D.ask_mx(l, r) - D.ask_mn(l, r) == r - l; }

// Xây cây
void build() {
  for (int i = 1; i <= n; ++i) {
    // Ngăn xếp đơn điệu
    // Giá trị nhỏ nhất trên đoạn [st1[tp1-1]+1,st1[tp1]] là a[st1[tp1]]
    // Bây giờ đưa nó ra khỏi ngăn xếp, nghĩa là cần cộng lại phần Min đã trừ thừa.
    // Lá của cây đoạn tại vị trí j duy trì giá trị từ j đến i hiện tại:
    // Max{j,i}-Min{j,i}-(i-j)
    // Cộng trên đoạn chỉ là một tag.
    // Mục đích duy trì ngăn xếp đơn điệu là hỗ trợ cây đoạn cập nhật từ i-1 sang i.
    // Sau khi cập nhật đến i, chỉ cần truy vấn giá trị nhỏ nhất toàn cục là biết có lời giải hay không

    while (tp1 && a[i] <= a[st1[tp1]])  // Ngăn xếp tăng đơn điệu, duy trì Min
      T.update(1, 1, n, st1[tp1 - 1] + 1, st1[tp1], a[st1[tp1]]), tp1--;
    while (tp2 && a[i] >= a[st2[tp2]])
      T.update(1, 1, n, st2[tp2 - 1] + 1, st2[tp2], -a[st2[tp2]]), tp2--;

    T.update(1, 1, n, st1[tp1] + 1, i, -a[i]);
    st1[++tp1] = i;
    T.update(1, 1, n, st2[tp2] + 1, i, a[i]);
    st2[++tp2] = i;

    id[i] = ++cnt;
    L[cnt] = R[cnt] = i;  // L và R chỉ đầu trái và đầu phải của đoạn mà nút tương ứng
    int le = T.query(1, 1, n), now = cnt;
    while (tp && L[st[tp]] >= le) {
      if (typ[st[tp]] && judge(M[st[tp]], i)) {
        // Kiểm tra có thể trở thành con hay không, nếu có thì làm
        R[st[tp]] = i, M[st[tp]] = L[now], add(st[tp], now), now = st[tp--];
      } else if (judge(L[st[tp]], i)) {
        typ[++cnt] = 1;  // Nút hợp nhất nhất định được tạo ra theo cách này
        L[cnt] = L[st[tp]], R[cnt] = i, M[cnt] = L[now];
        // Mảng M ghi đầu trái của người con ngoài cùng bên phải của nút, dùng cho phần kiểm tra có thể trở thành con ở trên
        add(cnt, st[tp--]), add(cnt, now);
        now = cnt;
      } else {
        add(++cnt, now);  // Tạo một nút mới, thêm now làm con
        // Nếu bắt đầu từ nút hiện tại không thể tạo thành đoạn liên tiếp thì gộp.
        // Cho đến khi tìm được một nút có thể tạo thành đoạn liên tiếp.
        // Luôn tìm được một nút như vậy.
        do add(cnt, st[tp--]);
        while (tp && !judge(L[st[tp]], i));
        L[cnt] = L[st[tp]], R[cnt] = i, add(cnt, st[tp--]);
        now = cnt;
      }
    }
    st[++tp] = now;  // Kết thúc lần tăng, đẩy nút hiện tại vào ngăn xếp

    T.update(1, 1, n, 1, i, -1);  // Vì đầu phải của đoạn dịch sang phải một ô, nên toàn bộ trừ 1
  }

  rt = st[1];  // Nút còn lại cuối cùng trong ngăn xếp là nút gốc
}

// Tách lca thành nút phân tách hoặc nút hợp nhất, tại đây xem nút lá là nút phân tách
void query(int l, int r) {
  int x = id[l], y = id[r];
  int z = lca(x, y);
  if (typ[z] & 1)
    l = L[go(x, dep[x] - dep[z] - 1)], r = R[go(y, dep[y] - dep[z] - 1)];
  // Lý do cần xử lý riêng nút hợp nhất là nút hợp nhất này không nhất thiết là đoạn liên tiếp nhỏ nhất chứa l và r.
  // Vì các đoạn con của đoạn mà nút hợp nhất đại diện cũng đều là đoạn liên tiếp, nên chỉ cần một trong số đó là đủ.
  else
    l = L[z], r = R[z];
  printf("%d %d\n", l, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  D.build();
  build();
  dfs(rt);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    query(x, y);
  }
  return 0;
}

// 20190612
// Cây phân hợp
```

## Tài liệu tham khảo và liên kết

[Blog của Đại Mễ Bính - Ghi chú học tập về cây phân hợp](https://www.cnblogs.com/Paul-Guderian/p/11020708.html)

[^ref1]: Lưu Thừa Áo. Cấu trúc dữ liệu đoạn liên tiếp đơn giản. Trao đổi học viên WC2019.
