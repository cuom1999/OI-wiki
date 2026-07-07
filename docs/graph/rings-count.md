## Đếm chu trình thông thường

???+ note "[Bài mẫu 1: Codeforces Beta Round 11 D. Một nhiệm vụ đơn giản](https://codeforces.com/problemset/problem/11/D)"
    Cho một đồ thị đơn, cần tính số chu trình đơn trong đồ thị. Chu trình đơn là chu trình không có đỉnh hoặc cạnh lặp lại.
    
    Số đỉnh $1\leq n\leq 19$.

??? note "Ý tưởng giải"
    Xét quy hoạch động nén trạng thái. Gọi $f(s,i)$ là số đường đi thỏa mãn tập đỉnh hiện đã đi qua là $s$, hiện đang ở đỉnh $i$, và đỉnh đầu tiên là đỉnh có **số thứ tự nhỏ nhất** trong tập đỉnh $s$.
    
    Với trạng thái $f(s,i)$, liệt kê đỉnh tiếp theo $u$. Nếu $u$ thuộc tập $s$ và là đỉnh có số thứ tự nhỏ nhất trong tập đó (tức là đỉnh xuất phát), thì cộng $f(s,i)$ vào đáp án $A$. Nếu $u$ không thuộc $s$, thì cộng $f(s,i)$ vào $f(s\cup\{u\},u)$.
    
    Cách này cũng tính cả chu trình độ dài $2$ (tức cạnh song song), đồng thời mỗi chu trình không phải chu trình độ dài $2$ sẽ bị tính hai lần (vì khi cố định đỉnh xuất phát, có thể đi theo hai hướng). Vì vậy đáp án là $\dfrac{A-m}2$, trong đó $m$ là số cạnh. Độ phức tạp thời gian là $O(2^nm)$.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/graph/code/rings-count/rings-count_1.cpp"
    ```

## Đếm chu trình ba đỉnh

**Chu trình ba đỉnh** là một bộ ba không thứ tự $(u,\ v,\ w)$ trong một đồ thị đơn $G$ sao cho tồn tại ba cạnh lần lượt nối $(u,\ v)$, $(v,\ w)$ và $(w,\ u)$. **Bài toán đếm chu trình ba đỉnh** yêu cầu tính số chu trình ba đỉnh trong đồ thị.

Trước hết, định hướng tất cả các cạnh. Quy ước cạnh đi từ đỉnh có bậc nhỏ hơn đến đỉnh có bậc lớn hơn; nếu hai bậc bằng nhau thì đi từ đỉnh có số thứ tự nhỏ hơn đến đỉnh có số thứ tự lớn hơn. Khi đó đồ thị thu được là một đồ thị có hướng không chu trình (DAG).

??? note "Chứng minh đồ thị không có chu trình"
    Dùng phản chứng. Giả sử tồn tại một chu trình, khi đó bậc của các đỉnh trên chu trình phải tăng dần. Để tạo thành chu trình, bậc của tất cả các đỉnh phải bằng nhau, nhưng số thứ tự của chúng phải khác nhau, mâu thuẫn.
    
    Vì vậy đồ thị sau khi định hướng không có chu trình.
    
    Có thể dựa vào quy tắc định hướng trên để xây dựng một [thứ tự bộ phận](../math/order-theory.md#quan-hệ-hai-ngôi), nên đồ thị được xây dựng theo quy tắc này (tức [biểu đồ Hasse](../math/order-theory.md#biểu-diễn-trực-quan-tập-có-thứ-tự-bộ-phận-biểu-đồ-hasse) của thứ tự bộ phận đó) là một DAG.

Liệt kê $u$ và các đỉnh $v$ mà $u$ trỏ tới, rồi trong các đỉnh mà $v$ trỏ tới tiếp tục liệt kê $w$; cuối cùng chỉ cần kiểm tra $u$ có nối với $w$ hay không.

Độ phức tạp thời gian của thuật toán này là $O(m\sqrt m)$.

???+ note "Chứng minh độ phức tạp thời gian"
    Với phần định hướng, cần duyệt tất cả các cạnh, nên độ phức tạp thời gian là $O(n+m)$.
    
    Với mỗi cặp $(v,\ w)$, số lượng $u$ không vượt quá bậc vào $d^-(v)$ của $v$.
    
    Nếu $d^-(v)\leq\sqrt m$, do số lượng $w$ nhiều nhất là $n$, phần này có độ phức tạp thời gian $O(n\sqrt m)$.
    
    Nếu $d^-(v) > \sqrt m$, do $v$ trỏ tới $w$, theo quy tắc định hướng có $d(v) \leq d(w)$, suy ra $d(w) > \sqrt m$. Nhưng tổng số cạnh chỉ là $m$, nên số lượng $w$ như vậy nhiều nhất là $\sqrt m$; do đó độ phức tạp thời gian là $O(m\sqrt m)$.
    
    Tổng độ phức tạp thời gian là $O(n+m+n\sqrt m+m\sqrt m)=O(m\sqrt m)$.
    
    Nếu định hướng cạnh từ đỉnh có bậc lớn hơn đến đỉnh có bậc nhỏ hơn, độ phức tạp vẫn giữ nguyên. Chỉ cần hoán đổi hai đỉnh $u,\ w$, chứng minh trên vẫn áp dụng được.

???+ note "Mã mẫu ([Luogu P1989 Đếm chu trình ba đỉnh trong đồ thị vô hướng](https://www.luogu.com.cn/problem/P1989))"
    ```cpp
    --8<-- "docs/graph/code/rings-count/rings-count_2.cpp"
    ```

### Bài mẫu 2

???+ note "[HDU 6184 Đếm sao](https://acm.hdu.edu.cn/showproblem.php?pid=6184)"
    Cho một đồ thị vô hướng có $n$ đỉnh và $m$ cạnh, cần tính số lần xuất hiện của hình dưới đây.
    
    ![](./images/rings-count1.svg)
    
    $2\leq n\leq 10^5$, $1\leq m\leq\min\left\{2\times 10^5,\ \dfrac{n(n-1)}2\right\}$.

??? note "Ý tưởng giải"
    Hình này được tạo bởi hai chu trình ba đỉnh dùng chung một cạnh. Vì vậy trước hết chạy thuật toán đếm chu trình ba đỉnh một lần, thống kê số chu trình ba đỉnh chứa từng cạnh. Sau đó liệt kê cạnh dùng chung; giả sử có $x$ chu trình ba đỉnh chứa cạnh này, thì đóng góp vào đáp án là $\dbinom x2$.
    
    Độ phức tạp thời gian là $O(m\sqrt m)$.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/graph/code/rings-count/rings-count_3.cpp"
    ```

## Đếm chu trình bốn đỉnh

Tương tự, **chu trình bốn đỉnh** là bốn đỉnh $a,\ b,\ c,\ d$ sao cho các cặp $(a,\ b)$, $(b,\ c)$, $(c,\ d)$ và $(d,\ a)$ đều có cạnh nối.

Trước hết, xét việc sắp xếp các đỉnh: đỉnh có bậc nhỏ hơn đứng trước, đỉnh có bậc lớn hơn đứng sau.

Xét việc liệt kê đỉnh $a$ đứng sau cùng. Khi đó, với mỗi đỉnh $c$ đứng trước $a$, chỉ cần tính có bao nhiêu đỉnh $b$ cũng đứng trước $a$ và thỏa mãn $(a,\ b)$, $(b,\ c)$ đều có cạnh. Sau đó, chọn bất kỳ hai đỉnh trong các đỉnh $b$ này đều có thể tạo thành một chu trình bốn đỉnh. Để tính số lượng $b$, chỉ cần duyệt một lượt các đỉnh $b$ và $c$.

Độ phức tạp của phép liệt kê này về bản chất tương đương với việc liệt kê chu trình ba đỉnh, nên độ phức tạp thời gian cũng là $O(m\sqrt m)$ (giả sử $n,\ m$ cùng bậc).

Cần phân biệt rằng $(a,\ b,\ c,\ d)$ và $(a,\ c,\ b,\ d)$ có thể là hai chu trình bốn đỉnh khác nhau.

Ngoài ra, các đỉnh có cùng bậc vẫn phải có thứ hạng khác nhau, và cần kiểm tra $a\neq c$.

???+ note "Mã mẫu ([LibreOJ P191 Đếm chu trình bốn đỉnh trong đồ thị vô hướng](https://loj.ac/p/191))"
    ```cpp
    --8<-- "docs/graph/code/rings-count/rings-count_4.cpp"
    ```

### Bài mẫu 3

???+ note "[Gym 102028L Đồ thị con liên thông](https://codeforces.com/gym/102028/problem/L)"
    Cho một đồ thị vô hướng có $n$ đỉnh và $m$ cạnh, cần tính số cách chọn bốn cạnh sao cho đồ thị con do chúng sinh ra là liên thông.
    
    $4\leq n\leq 10^5$, $4\leq m\leq 2\times 10^5$.

??? note "Ý tưởng giải"
    Có thể chia các trường hợp thành năm loại: hình sao, chu trình bốn đỉnh, một đỉnh trên chu trình ba đỉnh nối thêm một cạnh ra ngoài, một đỉnh ở giữa của đường đi gồm bốn đỉnh nối thêm một cạnh ra ngoài, và đường đi gồm năm đỉnh.
    
    Với hình sao, chỉ cần liệt kê bậc của các đỉnh rồi dùng tổ hợp. Chu trình bốn đỉnh có thể được tính trực tiếp bằng thuật toán ở trên. Với phần chu trình ba đỉnh, chỉ cần liệt kê chu trình ba đỉnh $(u,\ v,\ w)$; khi đó đóng góp vào đáp án là $[d(u)-2]+[d(v)-2]+[d(w)-2]$.
    
    Tiếp theo xét trường hợp thứ tư. Liệt kê đỉnh $x$ đóng vai trò đỉnh bậc $2$, rồi liệt kê một đỉnh $y$ kề với nó làm đỉnh bậc $3$. Lúc này đóng góp vào đáp án là $[d(x)-1]\cdot\dbinom{d(y)-1}2$. Tuy nhiên, đỉnh kề của $y$ có thể trùng với đỉnh kề của $x$; khi đó hình thu được tương đương với trường hợp thứ ba. Mỗi trường hợp thứ ba bị tính thừa như vậy sẽ bị tính thừa hai lần (vì có hai đỉnh bậc $3$), nên cần trừ đi hai lần số lượng trường hợp thứ ba.
    
    Với trường hợp cuối cùng, trước hết liệt kê đỉnh ở giữa $x$. Khi đó đóng góp vào đáp án là
    
    $$
    \sum_{y\in son_x}\sum_{z\in son_x}[d(y)-1]\cdot[d(z)-1].
    $$
    
    Tương tự, trong đó cũng có các phần bị tính thừa. Gọi đỉnh kề của $y$ là $s$, đỉnh kề của $z$ là $t$; sau khi phân tích, các trường hợp bị tính thừa gồm:
    
    1.  $y$ trùng với $t$, nhưng $s$ không trùng với $z$: tương đương với trường hợp thứ ba;
    2.  $s$ trùng với $z$, nhưng $y$ không trùng với $t$: cũng tương đương với trường hợp thứ ba;
    3.  $y$ trùng với $t$ và $s$ trùng với $z$: tương đương với một chu trình ba đỉnh;
    4.  $s$ trùng với $t$: tương đương với một chu trình bốn đỉnh (trường hợp thứ hai).
    
    Xét thấy trong trường hợp thứ ba, khi hai đỉnh bậc $2$ lần lượt được chọn làm $x$, chúng vừa khớp với hai kiểu tính thừa 1 và 2 ở trên. Vì vậy cần trừ thêm hai lần số lượng trường hợp thứ ba. Với một chu trình ba đỉnh, cả ba đỉnh đều có thể làm $x$, nên bị tính thừa $3$ lần. Tương tự, trường hợp chu trình bốn đỉnh bị tính thừa $4$ lần.
    
    Như vậy thu được thuật toán cho tất cả các trường hợp, với độ phức tạp thời gian $O(n+m\sqrt m)$.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/graph/code/rings-count/rings-count_5.cpp"
    ```

## Bài tập

[Luogu P3547 \[POI2013\] CEN-Bảng giá](https://www.luogu.com.cn/problem/P3547)

[CodeForces 985G Người chơi trong đội](https://codeforces.com/contest/985/problem/G) (nguyên lý bao hàm - loại trừ)
