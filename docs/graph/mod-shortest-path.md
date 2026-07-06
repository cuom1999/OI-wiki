Khi gặp các bài toán dạng "cho $n$ số nguyên, hỏi $n$ số nguyên này có thể ghép được bao nhiêu số nguyên khác (mỗi số trong $n$ số có thể lấy lặp lại)", "cho $n$ số nguyên, hỏi số nguyên nhỏ nhất (lớn nhất) không thể ghép được từ $n$ số nguyên này", hoặc "ít nhất phải ghép bao nhiêu lần để tạo ra một số có dư $p$ khi chia cho $K$", có thể dùng phương pháp đường đi ngắn nhất theo đồng dư.

Đường đi ngắn nhất theo đồng dư dùng các lớp đồng dư để xây dựng trạng thái, nhờ đó có thể tối ưu độ phức tạp bộ nhớ.

Tương tự phương pháp [ràng buộc hiệu](./diff-constraints.md), các trạng thái được xây dựng bằng đồng dư có thể xem là các đỉnh trong bài toán đường đi ngắn nhất một nguồn. Chuyển trạng thái của đường đi ngắn nhất theo đồng dư thường có dạng $f(i+y) = f(i) + y$, tương tự $f(v) = f(u) + edge(u,v)$ trong đường đi ngắn nhất một nguồn.

## Ví dụ

### Ví dụ 1

???+ note "[P3403 Máy nhảy tầng](https://www.luogu.com.cn/problem/P3403)"
    Tóm tắt đề bài: cho $x,y,z,h$, hỏi với $k \in [1,h]$, có bao nhiêu giá trị $k$ thỏa mãn $ax+by+cz=k$. ($0\leq a,b,c$, $1\le x,y,z\le 10^5$, $h\le 2^{63}-1$)

Không mất tính tổng quát, giả sử $x < y < z$.

Gọi $d_i$ là tầng thấp nhất $p$ có thể đạt được chỉ bằng **thao tác 2** và **thao tác 3**, đồng thời thỏa $p\bmod x = i$. Nói cách khác, $d_i$ là số nhỏ nhất đồng dư với $i$ theo modulo $x$ có thể thu được sau khi thực hiện **thao tác 2** và **thao tác 3**; giá trị này dùng để tính số lượng số trong lớp đồng dư đó thỏa điều kiện.

Có hai phép chuyển trạng thái:

-   $i \xrightarrow{y} (i+y) \bmod x$

-   $i \xrightarrow{z} (i+z) \bmod x$

Thường chọn số nhỏ nhất trong tập $a_i$ để lấy modulo, tức là $x$ trong ví dụ này, nhằm giảm tối đa độ phức tạp bộ nhớ (hệ thặng dư nhỏ nhất).

Khi đó, về bản chất đang thực hiện thao tác xây cạnh trong bài toán đường đi ngắn nhất:

`add(i, (i+y) % x, y)`

`add(i, (i+z) % x, z)`

Tiếp theo chỉ cần tìm $d_0, d_1, d_2, \dots, d_{x-1}$; chạy một lần đường đi ngắn nhất là có thể thu được các $d_i$ tương ứng.

??? example "Cài đặt dựa trên đường đi ngắn nhất"
    ```cpp
    --8<-- "docs/graph/code/mod-shortest-path/mod-shortest-path_1.cpp"
    ```

Tuy nhiên, không nhất thiết phải giải đường đi ngắn nhất theo cách thông thường. Hai tính chất đặc biệt sau cho phép tối ưu:

Thứ nhất, chỉ có hai loại trọng số cạnh; với mỗi đường đi, do tính giao hoán của phép cộng, thứ tự đi qua hai loại trọng số không ảnh hưởng đến kết quả. Vì vậy có thể xét chạy đường đi ngắn nhất hai lần, mỗi lần chỉ xây các cạnh thuộc một loại trọng số.

Thứ hai, với đồ thị chỉ có một loại trọng số cạnh, mỗi đỉnh $u$ đều có một cạnh vào (từ $(u-y) \bmod x$) và một cạnh ra (đến $(u+y) \bmod x$), nên toàn bộ đồ thị gồm một số chu trình. Hơn nữa, có thể chứng minh có đúng $\gcd(x,y)$ chu trình cùng độ dài.

???+ note "Chứng minh"
    Đặt $d=\gcd(x,y)$, $x=da,y=db$, khi đó $\gcd(a,b)=1$.
    
    Xét việc xuất phát từ $u$ và đi $k$ bước, đến $(u+ky) \bmod x$. Nếu tạo thành chu trình thì $ky \equiv 0 \pmod x$, tức là $kb \equiv 0 \pmod a$.
    
    Do $\gcd(a,b)=1$, giá trị nhỏ nhất của $k$ là $a$, tức độ dài chu trình là $a = \dfrac{x}{d}$. Vì có thể bắt đầu từ một đỉnh bất kỳ, mọi chu trình khả dĩ đều có cùng độ dài, và số lượng chu trình là $d$.

Ngoài ra, vì trọng số cạnh là dương, sau khi đi vòng quanh chu trình hai lần thì không còn phép nới lỏng mới. Chỉ cần cập nhật một vòng trực tiếp là đủ. Cách xử lý này không bị giới hạn bởi độ phức tạp của thuật toán đường đi ngắn nhất và có thể đạt $O(x)$.

Tương tự bài toán ràng buộc hiệu, khi tồn tại một nghiệm $\{a_1,a_2,\cdots,a_n\}$, thì $\{a_1+d,a_2+d,\cdots,a_n+d\}$ cũng là một nghiệm. Vì vậy, trong bài này chọn $i=1$ làm nguồn; khi đó $dis_{1}=1$ tại nguồn là nhỏ nhất trong phạm vi đã biết, nên nghiệm thu được cũng là một nghiệm nhỏ nhất.

Đáp án là:

$$
\sum_{i=0}^{x-1}\left(\frac{h-d_i}{x} + 1\right)
$$

Cộng thêm 1 vì tầng chứa $d_i$ cũng được tính một lần.

Khi cài đặt, phạm vi của $h$ là $h \leq 2^{63}-1$, nên trước khi giải đường đi ngắn nhất, giá trị khởi tạo của $d_i$ nên ít nhất là $2^{63}$, vượt quá giá trị lớn nhất của `long long` trong C++. Vì vậy có thể dùng `unsigned long long`, hoặc trước hết đặt $h \gets h - 1$, rồi coi tầng thấp nhất là tầng $0$; các phần mã khác không đổi.

??? example "Cài đặt dựa trên tối ưu chu trình"
    ```cpp
    --8<-- "docs/graph/code/mod-shortest-path/mod-shortest-path_2.cpp"
    ```

### Ví dụ 2

???+ note "[ARC084B Small Multiple](https://atcoder.jp/contests/arc084/tasks/arc084_b)"
    Tóm tắt đề bài: cho $n$, cần tìm tổng chữ số của bội số của $n$ có tổng chữ số nhỏ nhất. ($1\le n\le 10^5$)

Bài này có thể giải trong $O(n\log^2 n)$ bằng ba lô đầy đủ tối ưu bằng tích chập vòng, nhưng có thể tìm một thuật toán tuyến tính.

Quan sát rằng mọi số nguyên dương đều có thể được tạo ra từ $1$ bằng cách thực hiện các thao tác nhân $10$ và cộng $1$ theo một thứ tự nào đó; số lần thực hiện thao tác cộng $1$ chính là tổng chữ số của số đó. Điều này gợi ý dùng đường đi ngắn nhất.

Với mọi $0\le k\le n-1$, nối một cạnh trọng số $0$ từ $k$ đến $10k$, và một cạnh trọng số $1$ từ $k$ đến $k+1$. (Mọi chỉ số đỉnh đều xét theo modulo $n$.)

Mỗi bội số của $n$ đều tương ứng với một đường đi từ đỉnh $1$ đến đỉnh $0$ trong đồ thị này, nên chỉ cần tìm đường đi ngắn nhất từ $1$ đến $0$. Một số đường đi không hợp lệ (chẳng hạn đi liên tiếp $10$ cạnh trọng số $1$), nhưng đáp án do các đường đi này tạo ra không thể tối ưu, nên không ảnh hưởng đến đáp án.

Độ phức tạp thời gian là $O(n)$.

## Bài tập

[Luogu P3403 Máy nhảy tầng](https://www.luogu.com.cn/problem/P3403)

[Luogu P2662 Hàng rào trang trại bò](https://www.luogu.com.cn/problem/P2662)

[\[Đội tuyển tập huấn quốc gia\] Phương trình của Momo](https://www.luogu.com.cn/problem/P2371)

[NOIP2018 Hệ thống tiền tệ](https://loj.ac/problem/2951)

[AGC057D - Sum Avoidance](https://atcoder.jp/contests/agc057/tasks/agc057_d)

[THUPC 2023 Vòng sơ khảo Knapsack](https://loj.ac/p/6872)
