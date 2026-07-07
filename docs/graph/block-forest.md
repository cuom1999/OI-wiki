author: GitPinkRabbit, Early0v0, Backl1ght, mcendu, ksyx, iamtwz, Xeonacid, kenlig, Menci, Enter-tainer, CCXXXI, hcx2012Git

Trước khi đọc nội dung dưới đây, cần nắm chắc phần [các khái niệm liên quan đến đồ thị](./concept.md).

Đọc thêm: [đỉnh khớp và cầu](./cut.md).

## Dẫn nhập

Cây (hoặc rừng) có nhiều tính chất tốt và thuận tiện để duy trì bằng nhiều cấu trúc dữ liệu thông dụng.

Ngược lại, đồ thị tổng quát không có những tính chất tốt như vậy. Trong một số trường hợp, có thể chuyển một số bài toán trên đồ thị tổng quát về bài toán trên cây.

Cây tròn-vuông (Block forest hoặc Round-square tree) [^ref1] là một cách biến đồ thị thành cây. Bài viết này giới thiệu cách xây dựng, các tính chất và một số ứng dụng của cây tròn-vuông.

Vì giới hạn dung lượng, một số kết luận trong bài không được chứng minh; người đọc có thể tự kiểm chứng.

## Định nghĩa

Cây tròn-vuông ban đầu là một công cụ để xử lý "đồ thị cactus" (đồ thị vô hướng mà mỗi cạnh nằm trong không quá một chu trình đơn). Tuy nhiên, khi khai thác thêm các tính chất của nó, đôi khi cũng có thể dùng cấu trúc này trên đồ thị vô hướng tổng quát.

Để giới thiệu cây tròn-vuông, trước hết cần giới thiệu **thành phần song liên thông theo đỉnh**.

Một cách định nghĩa **đồ thị song liên thông theo đỉnh** là: giữa hai đỉnh phân biệt bất kỳ trong đồ thị luôn có ít nhất hai đường đi không giao nhau theo đỉnh.
"Không giao nhau theo đỉnh" vừa yêu cầu mỗi đường là đường đi đơn, vừa yêu cầu giao của hai đường chỉ gồm hai đầu mút chung; hai đầu mút này không tính vào phạm vi đang xét.

Khá khó định nghĩa đồ thị chỉ có một đỉnh có phải là một thành phần song liên thông theo đỉnh hay không; phần này tạm thời không xét các đồ thị có số đỉnh bằng $1$.

Một định nghĩa gần tương đương là: đồ thị không có đỉnh khớp.
Định nghĩa này chỉ sai trong trường hợp đồ thị có đúng hai đỉnh và một cạnh nối chúng. Đồ thị này không có đỉnh khớp, nhưng không thể tìm được hai đường đi rời nhau, vì chỉ có một đường đi.
(Cũng có thể hiểu là đường đi đó được tính hai lần; quả thật chúng không giao nhau vì không đi qua đỉnh nào khác.)

Mặc dù định nghĩa chuẩn là định nghĩa đầu tiên, để thuận tiện, bài này quy ước dùng định nghĩa thứ hai cho đồ thị song liên thông theo đỉnh.

**Thành phần song liên thông theo đỉnh** của một đồ thị là một **đồ thị con song liên thông theo đỉnh cực đại**.
Khác với thành phần liên thông mạnh và các khái niệm tương tự, một đỉnh có thể thuộc nhiều thành phần song liên thông theo đỉnh, nhưng một cạnh thuộc đúng một thành phần song liên thông theo đỉnh (nếu dùng định nghĩa đầu tiên thì có thể có cạnh không thuộc thành phần nào).

Trong cây tròn-vuông, mỗi đỉnh của đồ thị gốc tương ứng với một **đỉnh tròn**, mỗi thành phần song liên thông theo đỉnh tương ứng với một **đỉnh vuông**.
Vì vậy tổng cộng có $n+c$ đỉnh, trong đó $n$ là số đỉnh của đồ thị gốc, còn $c$ là số thành phần song liên thông theo đỉnh của đồ thị gốc.

Với mỗi thành phần song liên thông theo đỉnh, đỉnh vuông tương ứng của nó nối cạnh đến mỗi đỉnh trong thành phần đó.
Mỗi thành phần song liên thông theo đỉnh tạo thành một cấu trúc hình sao quanh đỉnh vuông tương ứng; nhiều cấu trúc như vậy được nối với nhau qua các đỉnh khớp trong đồ thị gốc, vì điểm phân tách giữa các thành phần song liên thông theo đỉnh là đỉnh khớp.

Mỗi cạnh trong cây tròn-vuông nối một đỉnh tròn với một đỉnh vuông.

Hình dưới đây cho thấy các thành phần song liên thông theo đỉnh và dạng cây tròn-vuông tương ứng của một đồ thị. [^ref2]

![](./images/block-forest1.svg)![](./images/block-forest2.svg)![](./images/block-forest3.svg)

Số đỉnh của cây tròn-vuông nhỏ hơn $2n$, vì số đỉnh khớp nhỏ hơn $n$. Do đó khi cài đặt cần khai báo các mảng với kích thước gấp đôi.

Chỉ khi đồ thị gốc liên thông thì "cây tròn-vuông" mới là một cây. Nếu đồ thị gốc có $k$ thành phần liên thông, cây tròn-vuông của nó cũng sẽ tạo thành một rừng gồm $k$ cây.

Nếu một thành phần liên thông nào đó trong đồ thị gốc chỉ có một đỉnh, cần phân tích tùy tình huống cụ thể; trong các thảo luận tiếp theo, không xét đỉnh cô lập.

## Quá trình

Với một đồ thị, làm thế nào để xây dựng cây tròn-vuông của nó? Trước hết, nếu đồ thị không liên thông, có thể tách thành từng đồ thị con liên thông để xét, vì vậy chỉ cần xét đồ thị liên thông.

Vì cây tròn-vuông dựa trên các thành phần song liên thông theo đỉnh, còn các thành phần này lại dựa trên đỉnh khớp, nên chỉ cần dùng phương pháp tương tự cách tìm đỉnh khớp.

Thuật toán thường dùng để tìm đỉnh khớp là Tarjan. Nếu đã biết thuật toán này thì nội dung bên dưới sẽ dễ hiểu; nếu chưa biết cũng không sao.

Bỏ qua phần Tarjan tìm đỉnh khớp và đi thẳng vào thuật toán dùng cho cây tròn-vuông; đây là một biến thể của Tarjan:

Thực hiện DFS trên đồ thị, đồng thời dùng hai mảng then chốt `dfn` và `low` (tương tự Tarjan).

`dfn[u]` lưu thứ tự DFS của đỉnh $u$, tức $u$ là đỉnh được thăm thứ mấy trong lần đầu tiên được thăm.
`low[u]` lưu thứ tự DFS **nhỏ nhất** của một đỉnh có thể đi tới từ một đỉnh $v$ nào đó trong cây con của $u$ trên cây DFS, bằng cách dùng **tối đa một cạnh ngược lên tổ tiên hoặc cạnh cây đi lên cha**.
Nếu chưa từng nghe về thuật toán Tarjan, điều này có thể hơi khó hiểu; xét một ví dụ:

![](./images/block-forest4.svg)

(Đồ thị này tương đương với đồ thị trong các hình bên trên.)
Trong hình, cạnh cây được vẽ bằng đường thẳng từ trên xuống dưới, cạnh ngược lên tổ tiên được vẽ bằng đường cong từ dưới lên trên. Số hiệu của đỉnh chính là thứ tự DFS của nó.

Khi đó mảng `low` như sau:

|        $i$        | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ | $8$ | $9$ |
| :---------------: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| $\mathrm{low}[i]$ | $1$ | $1$ | $1$ | $3$ | $3$ | $4$ | $3$ | $3$ | $7$ |

Điểm cần lưu ý là `low` của $9$ là $7$; giá trị này khác một vài cách tìm đỉnh khớp, vì để thuận tiện ta quy ước có thể đi lên bằng cạnh cha, nhưng ý tưởng chính vẫn giống nhau.

Có thể viết hàm DFS tính `dfn` và `low` rất gọn (ban đầu mảng `dfn` được gán bằng không):

???+ note "Cài đặt"
    === "C++"
        ```cpp
        void Tarjan(int u) {
          low[u] = dfn[u] = ++dfc;                // Khởi tạo low bằng dfn của đỉnh hiện tại
          for (int v : G[u]) {                    // Duyệt các đỉnh kề của u
            if (!dfn[v]) {                        // Nếu chưa được thăm
              Tarjan(v);                          // Đệ quy
              low[u] = std::min(low[u], low[v]);  // Lấy min với low của đỉnh chưa thăm
            } else
              low[u] = std::min(low[u], dfn[v]);  // Lấy min với dfn của đỉnh đã thăm
          }
        }
        ```
    
    === "Python"
        ```python
        def Tarjan(u):
            low[u] = dfn[u] = dfc  # Khởi tạo low bằng dfn của đỉnh hiện tại
            dfc = dfc + 1
            for v in G[u]:  # Duyệt các đỉnh kề của u
                if dfn[v] == False:  # Nếu chưa được thăm
                    Tarjan(v)  # Đệ quy
                    low[u] = min(low[u], low[v])  # Lấy min với low của đỉnh chưa thăm
                else:
                    low[u] = min(low[u], dfn[v])  # Lấy min với dfn của đỉnh đã thăm
        ```

Tiếp theo, xét mối liên hệ giữa thành phần song liên thông theo đỉnh, cây DFS và hai mảng này.

Mỗi thành phần song liên thông theo đỉnh là một cây con liên thông trên cây DFS và chứa ít nhất hai đỉnh; đặc biệt, đỉnh trên cùng chỉ nối xuống một đỉnh trong thành phần đó.

Đồng thời, mỗi cạnh cây nằm đúng trong một thành phần song liên thông theo đỉnh.

Xét đỉnh trên cùng $u$ của một thành phần song liên thông theo đỉnh trong cây DFS. Thành phần này sẽ được xác định tại $u$, vì cây con của $u$ đã chứa toàn bộ thông tin của thành phần đó.

Vì thành phần có ít nhất hai đỉnh, xét đỉnh tiếp theo $v$ của thành phần này; khi đó giữa $u$ và $v$ tồn tại một cạnh cây.

Khi đó có $\mathrm{low}[v]=\mathrm{dfn}[u]$.
Chính xác hơn, với một cạnh cây $u\to v$, hai đỉnh $u,v$ nằm trong cùng một thành phần song liên thông theo đỉnh, và $u$ là đỉnh có độ sâu nhỏ nhất trong thành phần đó **khi và chỉ khi** $\mathrm{low}[v]=\mathrm{dfn}[u]$.

Như vậy có thể xác định trong quá trình DFS những chỗ nào tồn tại thành phần song liên thông theo đỉnh, nhưng vẫn chưa thể xác định chính xác tập đỉnh của từng thành phần.

Vấn đề này có thể xử lý bằng cách duy trì một ngăn xếp trong quá trình DFS, lưu các đỉnh chưa xác định thuộc thành phần song liên thông theo đỉnh nào (có thể là nhiều thành phần).

Khi tìm thấy một thành phần song liên thông theo đỉnh, các đỉnh trong thành phần đó ngoài $u$ đều tập trung ở đầu ngăn xếp; chỉ cần liên tục pop cho đến khi pop ra $v$.

Các đỉnh bị pop ra có thể được xử lý ngay lúc đó: chỉ cần nối chúng với đỉnh vuông mới tạo. Cuối cùng còn phải nối $u$ với đỉnh vuông.

Như vậy việc xây dựng cây tròn-vuông được hoàn tất tự nhiên. Có thể đánh số các đỉnh vuông bằng các số nguyên bắt đầu từ $n+1$, nhờ đó phân biệt hiệu quả đỉnh tròn và đỉnh vuông.

Phần này có thể chưa đủ trực quan. Bên dưới là một đoạn mã kèm chú thích chi tiết, các câu lệnh in giúp theo dõi quá trình và một ví dụ. Có thể sao chép mã và tự thực hành để hiểu, vì mã nguồn thường là cách giúp nắm rõ nhất (cần bật `c++11`).

???+ note "Cài đặt"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <vector>
    
    constexpr int MN = 100005;
    
    int N, M, cnt;
    std::vector<int> G[MN], T[MN * 2];
    
    int dfn[MN], low[MN], dfc;
    int stk[MN], tp;
    
    void Tarjan(int u) {
      printf("  Enter : #%d\n", u);
      low[u] = dfn[u] = ++dfc;                // Khởi tạo low bằng dfn của đỉnh hiện tại
      stk[++tp] = u;                          // Đưa vào ngăn xếp
      for (int v : G[u]) {                    // Duyệt các đỉnh kề của u
        if (!dfn[v]) {                        // Nếu chưa được thăm
          Tarjan(v);                          // Đệ quy
          low[u] = std::min(low[u], low[v]);  // Lấy min với low của đỉnh chưa thăm
          if (low[v] == dfn[u]) {  // Đánh dấu đã tìm thấy một thành phần song liên thông theo đỉnh có gốc u
            ++cnt;                 // Tăng số đỉnh vuông
            printf("  Found a New BCC #%d.\n", cnt - N);
            // Pop các đỉnh khác u trong thành phần và nối cạnh trong cây tròn-vuông
            for (int x = 0; x != v; --tp) {
              x = stk[tp];
              T[cnt].push_back(x);
              T[x].push_back(cnt);
              printf("    BCC #%d has vertex #%d\n", cnt - N, x);
            }
            // Lưu ý rằng bản thân u cũng cần nối cạnh (nhưng không pop)
            T[cnt].push_back(u);
            T[u].push_back(cnt);
            printf("    BCC #%d has vertex #%d\n", cnt - N, u);
          }
        } else
          low[u] = std::min(low[u], dfn[v]);  // Lấy min với dfn của đỉnh đã thăm
      }
      printf("  Exit : #%d : low = %d\n", u, low[u]);
      printf("  Stack:\n    ");
      for (int i = 1; i <= tp; ++i) printf("%d, ", stk[i]);
      puts("");
    }
    
    int main() {
      scanf("%d%d", &N, &M);
      cnt = N;  // Số hiệu thành phần song liên thông theo đỉnh / đỉnh vuông bắt đầu từ N
      for (int i = 1; i <= M; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);  // Thêm cạnh hai chiều
        G[v].push_back(u);
      }
      // Xử lý đồ thị không liên thông
      for (int u = 1; u <= N; ++u)
        if (!dfn[u]) Tarjan(u), --tp;
      // Lưu ý khi thoát Tarjan, trong ngăn xếp vẫn còn một phần tử là gốc; pop nó ra
      return 0;
    }
    ```

Cung cấp một test case:

```text
13 15
1 2
2 3
1 3
3 4
3 5
4 5
5 6
4 6
3 7
3 8
7 8
7 9
10 11
11 10
11 12
```

Ví dụ này tương ứng với đồ thị sau (bao gồm cả trường hợp cạnh song song và đỉnh cô lập):

![](./images/block-forest5.svg)

## Ví dụ

Phần này trình bày một vài bài tập có thể giải bằng cây tròn-vuông.

???+ note "[APIO2018 Ba môn phối hợp Ironman](https://loj.ac/p/2587)"
    ??? note "Tóm tắt đề bài"
        Cho một đồ thị vô hướng đơn. Hỏi có bao nhiêu bộ ba $\langle s, c, f \rangle$ ($s, c, f$ đôi một khác nhau) sao cho tồn tại một đường đi đơn bắt đầu từ $s$, đi qua $c$ rồi đến $f$.
    
    ??? note "Lời giải"
        Nhắc đến đường đi đơn, cần nêu một tính chất rất tốt của thành phần song liên thông theo đỉnh: với hai đỉnh trong cùng một thành phần song liên thông theo đỉnh, hợp của các đường đi đơn giữa chúng đúng bằng toàn bộ thành phần đó.
        Tức là giữa hai đỉnh phân biệt $u,v$ trong cùng một thành phần song liên thông theo đỉnh, luôn tồn tại một đường đi đơn đi qua một đỉnh $w$ cho trước khác cùng nằm trong thành phần đó.
        
        Chứng minh tính chất này:
        
        -   Nếu đường đi đơn đi ra khỏi thành phần song liên thông theo đỉnh thì không thể quay lại thành phần đó, nếu không sẽ mâu thuẫn với định nghĩa của thành phần song liên thông theo đỉnh.
        -   Vì vậy chỉ cần chứng minh trong một đồ thị song liên thông theo đỉnh, với ba đỉnh phân biệt bất kỳ $u,v,c$, tồn tại một đường đi đơn từ $u$ đến $v$ đi qua $c$.
        -   Trước hết loại trường hợp có $2$ đỉnh: nó thỏa mãn tính chất này, nhưng không thể chọn ra $3$ đỉnh phân biệt.
        -   Với các trường hợp còn lại, xét mô hình luồng trên mạng: nguồn nối đến $c$ bằng một cạnh dung lượng $2$, $u$ và $v$ nối đến đích bằng các cạnh dung lượng $1$.
        -   Mỗi cạnh vô hướng $\langle x,y\rangle$ trong đồ thị gốc được biến thành một cạnh có hướng từ $x$ đến $y$ dung lượng $1$ và một cạnh có hướng từ $y$ đến $x$ dung lượng $1$.
        -   Cuối cùng, gán dung lượng $1$ cho mỗi đỉnh ngoài nguồn, đích và $c$; có thể thực hiện bằng tách đỉnh.
        -   Vì cạnh từ nguồn đến $c$ có dung lượng $2$, nếu luồng cực đại của mạng này bằng $2$ thì chứng minh được sự tồn tại của đường đi qua $c$.
        -   Theo định lý luồng cực đại - lát cắt nhỏ nhất, lát cắt nhỏ nhất không vượt quá $2$; tiếp theo chỉ cần chứng minh lát cắt nhỏ nhất lớn hơn $1$.
        -   Điều này tương đương với việc chứng minh cắt bỏ một cạnh bất kỳ có dung lượng $1$ không thể làm nguồn và đích mất liên thông.
        -   Nếu cắt bỏ cạnh nối $u$ hoặc $v$ với đích, theo định nghĩa thứ nhất của song liên thông theo đỉnh, vẫn tồn tại đường đi đơn từ $c$ đến đỉnh còn lại chưa bị cắt.
        -   Nếu cắt bỏ một cạnh sinh ra khi tách đỉnh, điều này tương đương với xóa một đỉnh; theo định nghĩa thứ hai của song liên thông theo đỉnh, đồ thị còn lại vẫn liên thông.
        -   Nếu cắt bỏ một cạnh được tạo từ cạnh ban đầu, điều này tương đương với xóa một cạnh; đây là thao tác yếu hơn xóa một đỉnh, nên vẫn tồn tại đường đi.
        -   Vì vậy đã chứng minh lát cắt nhỏ nhất lớn hơn $1$, tức luồng cực đại bằng $2$. Chứng minh hoàn tất.
        
        Kết luận này cho biết: xét đường đi giữa hai đỉnh tròn trên cây tròn-vuông, tập các đỉnh tròn kề với các đỉnh vuông nằm trên đường đi đó chính là tập đỉnh nằm trên các đường đi đơn giữa hai đỉnh trong đồ thị gốc.
        
        Quay lại bài toán, cố định $s$ và $f$, cần tính số lượng $c$ hợp lệ. Số lượng $c$ hợp lệ bằng số đỉnh trong hợp các đường đi đơn giữa $s,f$ trừ đi $2$ (loại chính $s,f$).
        
        Như vậy, sau khi xây dựng cây tròn-vuông của đồ thị gốc, số đỉnh trên các đường đi đơn giữa hai đỉnh sẽ liên quan đến số đỉnh vuông (thành phần song liên thông theo đỉnh) và đỉnh tròn mà đường đi giữa chúng trên cây tròn-vuông đi qua.
        
        Tiếp theo là một kỹ thuật thông dụng trên cây tròn-vuông: khi thống kê đường đi, gán trọng số phù hợp cho đỉnh.
        Trong bài này, mỗi đỉnh vuông có trọng số bằng kích thước thành phần song liên thông theo đỉnh tương ứng, còn mỗi đỉnh tròn có trọng số $-1$.
        
        Sau cách gán trọng số này, tổng trọng số trên đường đi giữa hai đỉnh tròn trong cây tròn-vuông vừa đúng bằng kích thước hợp các đường đi đơn trong đồ thị gốc trừ đi $2$.
        
        Bài toán chuyển thành thống kê $\sum$ tổng trọng số đường đi giữa mọi cặp đỉnh tròn trên cây tròn-vuông.
        
        Đổi góc nhìn, thống kê đóng góp của mỗi đỉnh vào đáp án, tức trọng số nhân với số đường đi đi qua nó; việc này có thể tính bằng DP đơn giản trên cây.
        
        Cuối cùng, cần xử lý trường hợp đồ thị không liên thông. Bên dưới là mã tương ứng:
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/graph/code/block-forest/block-forest_1.cpp"
        ```
    
    Với test case vừa rồi, đáp án của bài này là $212$.

???+ note "[Codeforces #487 E. Du khách](https://codeforces.com/contest/487/problem/E)"
    ??? note "Tóm tắt đề bài"
        Cho một đồ thị vô hướng đơn liên thông, cần hỗ trợ hai loại thao tác:
        
        1.  Sửa trọng số của một đỉnh.
        
        2.  Hỏi giá trị nhỏ nhất của trọng số đỉnh trên tất cả các đường đi đơn giữa hai đỉnh.
    
    ??? note "Lời giải"
        Tương tự, xây dựng cây tròn-vuông của đồ thị gốc, cho trọng số của đỉnh vuông bằng giá trị nhỏ nhất trong các đỉnh tròn kề với nó; bài toán chuyển thành tìm giá trị nhỏ nhất trên đường đi.
        
        Giá trị nhỏ nhất trên đường đi có thể được duy trì bằng phân rã chuỗi nặng và cây đoạn, nhưng còn thao tác sửa thì sao?
        
        Mỗi lần sửa trọng số của một đỉnh tròn, cần sửa tất cả các đỉnh vuông kề với nó; khi đó dễ chạm đến $O(n)$ lần sửa.
        
        Lúc này tận dụng tính chất cây tròn-vuông là một cây: đặt trọng số của đỉnh vuông bằng giá trị nhỏ nhất trong các đỉnh tròn con của nó. Khi sửa, chỉ cần sửa đỉnh vuông cha.
        
        Để duy trì các đỉnh vuông, chỉ cần mở một `multiset` cho mỗi đỉnh vuông để lưu tập trọng số.
        
        Khi truy vấn, nếu LCA là đỉnh vuông, còn cần xét thêm trọng số của đỉnh tròn cha của LCA.
        
        Lưu ý: số đỉnh của cây tròn-vuông phải khai báo gấp đôi số đỉnh đồ thị gốc, nếu không sẽ truy cập vượt mảng.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/graph/code/block-forest/block-forest_2.cpp"
        ```

???+ note "[SDOI2018 Trò chơi chiến lược](https://loj.ac/p/2562)"
    ??? note "Tóm tắt đề bài"
        Cho một đồ thị vô hướng đơn liên thông. Có $q$ truy vấn:
        
        Mỗi lần cho một tập đỉnh $S$ ($2 \le |S| \le n$), hỏi có bao nhiêu đỉnh $u$ thỏa mãn $u \notin S$ và sau khi xóa $u$, các đỉnh trong $S$ không còn nằm tất cả trong cùng một thành phần liên thông.
        
        Mỗi điểm kiểm thử có nhiều bộ dữ liệu.
    
    ??? note "Lời giải"
        Trước hết xây dựng cây tròn-vuông. Bài toán trở thành hỏi số đỉnh tròn trong đồ thị con liên thông tương ứng với $S$ trên cây tròn-vuông, rồi trừ đi $|S|$.
        
        Tính số đỉnh tròn trong đồ thị con liên thông như thế nào? Có một cách:
        
        Đưa trọng số của đỉnh tròn lên cạnh nối nó với đỉnh vuông cha; bài toán chuyển thành tính tổng trọng số cạnh. Bài toán này có thể tham khảo một cách giải của [SDOI2015 Săn kho báu](https://loj.ac/p/2182).
        Cụ thể, sắp xếp các đỉnh trong $S$ theo thứ tự DFS, tính tổng khoảng cách giữa hai đỉnh liền kề sau khi sắp xếp (đồng thời tính cả khoảng cách giữa đỉnh cuối và đỉnh đầu). Đáp án là một nửa tổng khoảng cách, vì mỗi cạnh chỉ được đi qua hai lần.
        
        Cuối cùng, nếu đỉnh có độ sâu nhỏ nhất trong đồ thị con là đỉnh tròn, đáp án còn phải cộng thêm $1$, vì đỉnh đó chưa được tính.
        
        Vì có nhiều bộ dữ liệu, cần khởi tạo lại mảng.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/graph/code/block-forest/block-forest_3.cpp"
        ```

## Bài tập

-   [UVa 1464 Truy vấn giao thông thời gian thực](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=447&page=show_problem&problem=4210)
-   [Luogu P4320 Gặp nhau trên đường](https://www.luogu.com.cn/problem/P4320)
-   [Luogu P10517 Quy hoạch sử dụng đất](https://www.luogu.com.cn/problem/P10517)

## Liên kết ngoài

immortalCO, [Cây tròn-vuông - công cụ sắc bén để xử lý cactus](https://immortalco.blog.uoj.ac/blog/1955), Universal OJ.

## Tài liệu tham khảo và chú thích

[^ref1]: Năm 2017, Chen Junkun đã định nghĩa và đặt tên cấu trúc cây tròn-vuông trong báo cáo đội tuyển tập huấn quốc gia Trung Quốc cho IOI2017, "Báo cáo đề bài và mở rộng của 'Đồ thị con kỳ diệu'".

[^ref2]: Chen Junkun, "Cây tròn-vuông bình thường và quy hoạch động (~~động~~) kỳ diệu", Trại đông NOI2018, trang 4.
