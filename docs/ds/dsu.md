author: HeRaNO, JuicyMio, Xeonacid, sailordiary, ouuan, Pig-Eat-Earth

![](images/disjoint-set.svg)

<span id="giới-thiệu"></span>

## Giới thiệu

DSU (Disjoint Set Union, cấu trúc tập hợp rời nhau) là cấu trúc dữ liệu dùng để quản lý tập hợp chứa mỗi phần tử.
Nó thường được cài đặt như một rừng, trong đó mỗi cây biểu diễn một tập hợp,
còn các nút trong cây biểu diễn các phần tử thuộc tập hợp tương ứng.

Đúng như tên gọi hợp nhất - tìm kiếm (union-find), DSU hỗ trợ hai thao tác chính:

-   Hợp nhất (unite): hợp nhất hai tập hợp chứa hai phần tử đã cho (tức hợp nhất hai cây tương ứng).
-   Tìm (find): tìm tập hợp chứa một phần tử (tức tìm nút gốc của cây tương ứng);
    thao tác này có thể dùng để kiểm tra hai phần tử có thuộc cùng một tập hợp hay không.

Sau một số biến đổi, DSU có thể hỗ trợ xóa hoặc di chuyển một phần tử riêng lẻ,
hoặc duy trì trọng số trên các cạnh của rừng.
Với cây phân đoạn mở nút động, còn có thể cài đặt
[DSU bền vững](./persistent-seg.md#mở-rộng-dsu-bền-vững-dựa-trên-cây-chủ-tịch).

???+ warning "Cảnh báo"
    DSU không thể tách một tập hợp với độ phức tạp thấp.

<span id="khởi-tạo"></span>

## Khởi tạo

Ban đầu, mỗi phần tử nằm trong một tập hợp riêng, được biểu diễn bằng một cây chỉ có một nút gốc.
Để thuận tiện, đặt cha của nút gốc là chính nó.

???+ example "Cài đặt"
    === "C++"
        ```cpp
        struct dsu {
          vector<size_t> pa;

          explicit dsu(size_t size) : pa(size) { iota(pa.begin(), pa.end(), 0); }
        };
        ```

    === "Python"
        ```python
        class Dsu:
            def __init__(self, size):
                self.pa = list(range(size))
        ```

<span id="tìm"></span>

## Tìm

Cần đi ngược lên theo cây cho đến khi gặp nút gốc.

![](images/disjoint-set-find.svg)

???+ example "Cài đặt"
    === "C++"
        ```cpp
        size_t dsu::find(size_t x) { return pa[x] == x ? x : find(pa[x]); }
        ```

    === "Python"
        ```python
        def find(self, x):
            return x if self.pa[x] == x else self.find(self.pa[x])
        ```

<span id="nén-đường-đi"></span>

### Nén đường đi

Mọi phần tử đi qua trong quá trình tìm đều thuộc cùng tập hợp,
nên có thể nối trực tiếp chúng vào nút gốc để tăng tốc các lần tìm về sau.

![](images/disjoint-set-compress.svg)

???+ example "Cài đặt"
    === "C++"
        ```cpp
        size_t dsu::find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
        ```

    === "Python"
        ```python
        def find(self, x):
            if self.pa[x] != x:
                self.pa[x] = self.find(self.pa[x])
            return self.pa[x]
        ```

<span id="hợp-nhất"></span>

## Hợp nhất

Để hợp nhất hai cây, chỉ cần nối nút gốc của một cây vào nút gốc của cây còn lại.

![](images/disjoint-set-merge.svg)

???+ example "Cài đặt"
    === "C++"
        ```cpp
        void dsu::unite(size_t x, size_t y) { pa[find(x)] = find(y); }
        ```

    === "Python"
        ```python
        def unite(self, x, y):
            self.pa[self.find(x)] = self.find(y)
        ```

<span id="hợp-nhất-theo-heuristic"></span>

### Hợp nhất theo heuristic

Khi hợp nhất, việc chọn nút gốc của cây nào làm gốc mới sẽ ảnh hưởng đến độ phức tạp của các thao tác sau.
Có thể nối cây có ít nút hơn hoặc độ sâu nhỏ hơn vào cây còn lại để tránh cấu trúc bị suy biến.

??? note "Thảo luận cụ thể về độ phức tạp"
    Vì DSU chỉ cần hỗ trợ hợp nhất và tìm,
    khi cần gộp hai tập hợp thành một, nối tập hợp nào làm con của tập hợp nào cũng cho kết quả đúng.
    Tuy vậy, các cách nối khác nhau có độ phức tạp thời gian khác nhau.
    Cụ thể, nếu nối cây biểu diễn tập hợp có số nút và độ sâu nhỏ hơn vào dưới một cây tập hợp lớn hơn,
    thì so với phương án ngược lại, các thao tác tìm sau đó sẽ tốn ít thời gian hơn
    và cho độ phức tạp xấu nhất tốt hơn.

    Không phải lúc nào cũng gặp đúng trường hợp một tập hợp vừa ít nút hơn vừa nông hơn.
    Vì hai đặc trưng số nút và độ sâu đều dễ duy trì,
    thường chọn một trong hai làm hàm đánh giá.
    Dù chọn cách nào, độ phức tạp đều là $O (m\alpha(m,n))$;
    chứng minh chi tiết có thể xem trong các bài báo được trích ở phần tài liệu tham khảo.

    Trong mã thi lập trình thực tế, ngay cả khi không dùng hợp nhất theo heuristic,
    chương trình thường vẫn chạy kịp thời gian.
    Trong bài báo của Tarjan[^tarjan1984worst],
    độ phức tạp xấu nhất khi không dùng hợp nhất theo heuristic mà chỉ dùng nén đường đi được chứng minh là $O (m \log n)$.
    Trong bài báo của Yao[^yao1985expected],
    nếu không dùng hợp nhất theo heuristic mà chỉ dùng nén đường đi,
    độ phức tạp trung bình vẫn là $O (m\alpha(m,n))$.

    Nếu chỉ dùng hợp nhất theo heuristic mà không dùng nén đường đi, độ phức tạp là $O(m\log n)$.
    Vì một lần nén đường đi có thể gây ra nhiều thay đổi, đôi khi không nên dùng kỹ thuật này.
    Ví dụ, trong DSU bền vững hoặc chia để trị trên cây phân đoạn kết hợp với DSU,
    thường dùng DSU chỉ có hợp nhất theo heuristic.

Cài đặt tham khảo cho hợp nhất theo kích thước tập hợp: (lưu ý cần điều chỉnh cách khởi tạo)

???+ example "Cài đặt"
    === "C++"
        ```cpp
        struct dsu {
          vector<size_t> pa, size;

          explicit dsu(size_t size_) : pa(size_), size(size_, 1) {
            iota(pa.begin(), pa.end(), 0);
          }

          void unite(size_t x, size_t y) {
            x = find(x), y = find(y);
            if (x == y) return;
            if (size[x] < size[y]) swap(x, y);
            pa[y] = x;
            size[x] += size[y];
          }
        };
        ```

    === "Python"
        ```python
        class Dsu:
            def __init__(self, size):
                self.pa = list(range(size))
                self.size = [1] * size

            def unite(self, x, y):
                x, y = self.find(x), self.find(y)
                if x == y:
                    return
                if self.size[x] < self.size[y]:
                    x, y = y, x
                self.pa[y] = x
                self.size[x] += self.size[y]
        ```

<span id="cài-đặt-tham-khảo"></span>

## Cài đặt tham khảo

Cài đặt đầy đủ của DSU có nén đường đi và hợp nhất theo kích thước như sau:

??? example "Bài mẫu [Luogu P3367 Mẫu DSU](https://www.luogu.com.cn/problem/P3367), cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/ds/code/dsu/dsu_0.cpp"
        ```

    === "Python"
        ```python
        --8<-- "docs/ds/code/dsu/dsu_0.py"
        ```

<span id="độ-phức-tạp"></span>

## Độ phức tạp

Sau khi dùng đồng thời nén đường đi và hợp nhất theo heuristic,
thời gian khấu hao cho mỗi thao tác của DSU chỉ là $O(\alpha(n))$.
Trong đó, $\alpha$ là hàm ngược của hàm Ackermann, tăng cực kỳ chậm.
Nói cách khác, thời gian khấu hao của một thao tác DSU có thể xem như một hằng số rất nhỏ.
Chứng minh độ phức tạp nằm ở [trang này](./dsu-complexity.md).

???+ info "Hàm Ackermann ngược"
    [Hàm Ackermann](https://en.wikipedia.org/wiki/Ackermann_function)  $A(m, n)$ được định nghĩa như sau:

    $$
    A(m, n) =
    \begin{cases}
    n+1&\text{nếu }m=0\\
    A(m-1,1)&\text{nếu }m>0\text{ và }n=0\\
    A(m-1,A(m,n-1))&\text{ngược lại}
    \end{cases}
    $$

    Còn hàm Ackermann ngược $\alpha(n)$ là hàm ngược của hàm Ackermann, tức là số nguyên lớn nhất $m$ sao cho
    $A(m, m) \leqslant n$.

Độ phức tạp bộ nhớ của DSU là $O(n)$.

<span id="thao-tác-mở-rộng"></span>

## Thao tác mở rộng

Trên nền DSU thông thường, có thể thực hiện nhiều chỉnh sửa để hỗ trợ thêm thao tác
hoặc duy trì thông tin phức tạp hơn.

<span id="dsu-hỗ-trợ-xóa"></span>

### DSU hỗ trợ xóa

DSU thông thường không hỗ trợ thao tác xóa,
vì khi xóa một nút, rất khó tránh việc làm ảnh hưởng tới toàn bộ cây con có nút đó làm gốc.
Để giải quyết vấn đề này, trong DSU hỗ trợ xóa,
có thể tạo các nút ảo để bảo đảm mọi nút thật lưu dữ liệu luôn là lá.
Vì vậy, ngay khi khởi tạo, tạo một nút ảo cho mỗi nút dữ liệu và đặt cha của nút dữ liệu là nút ảo đó.
Vì mỗi lần hợp nhất hai tập hợp chỉ nối hai gốc của cây,
từ đầu đến cuối chỉ các nút ảo mới có nút con.
Nhờ vậy, khi xóa một nút, sẽ không xóa nhầm các nút khác.

Lưu ý rằng sau khi xóa một nút riêng lẻ, cần tạo lại một nút ảo làm cha của nút đó; nếu không, các thao tác hợp nhất và
xóa về sau sẽ không còn đúng.

??? example "Bài mẫu [SPOJ JMFILTER - Junk-Mail Filter](https://www.spoj.com/problems/JMFILTER/), cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/ds/code/dsu/dsu_4.cpp"
        ```

    === "Python"
        ```python
        --8<-- "docs/ds/code/dsu/dsu_4.py"
        ```

Cách tương tự cũng có thể dùng để di chuyển một phần tử riêng lẻ giữa các tập hợp. Chi tiết cài đặt xem trong ví dụ.

<span id="dsu-có-trọng-số"></span>

### DSU có trọng số

Có thể định nghĩa trọng số trên các cạnh của DSU,
cùng với phép toán cập nhật trọng số khi nén đường đi, để giải quyết nhiều bài toán hơn.
Chẳng hạn, với bài kinh điển "NOI2001 Food Chain",
có thể duy trì nhóm cộng modulo $3$ trên trọng số cạnh.
Với các bài toán duy trì trọng số cạnh theo modulo nhỏ như vậy,
còn có thể giải bằng cách tách một điểm DSU thành nhiều trạng thái.
Kỹ thuật trong trường hợp đặc biệt này còn được gọi là "DSU phân loại" hoặc "DSU mở rộng miền".
Phần sau sẽ minh họa các cách làm này qua ví dụ.

Để duy trì trọng số cạnh trong DSU, cần đẩy trọng số cạnh xuống lưu ở nút con.
Vì vậy, mỗi nút lưu trọng số của cạnh nối nó với cha của nó.
Chỉ khi cha của một nút thay đổi thì trọng số mới cần được điều chỉnh tương ứng.
Trong trường hợp chung, điều này có thể xảy ra khi nén đường đi và khi hợp nhất hai nút.
Ví dụ, nếu trọng số cạnh là khoảng cách giữa nút hiện tại và nút cha,
thì khi nén đường đi, mỗi lần thay cha của nút hiện tại bằng nút gốc,
phải cộng khoảng cách từ cha cũ đến gốc vào trọng số đang lưu ở nút hiện tại.
Tương tự, khi hợp nhất hai tập hợp chứa hai nút,
cần tính trọng số của cạnh mới nối giữa hai nút gốc.

??? example "Bài mẫu [Library Checker - Unionfind with Potential](https://judge.yosupo.jp/problem/unionfind_with_potential), cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/ds/code/dsu/dsu_5.cpp"
        ```

    === "Python"
        ```python
        --8<-- "docs/ds/code/dsu/dsu_5.py"
        ```

<span id="ví-dụ"></span>

## Ví dụ

Trong lập trình thi đấu, các bài hỏi trực tiếp về DSU phần lớn đều cần thiết kế biến thể phù hợp với đề bài.

???+ example "[UVa11987 Almost Union-Find](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3138)"
    Cài đặt một cấu trúc dữ liệu tương tự DSU, hỗ trợ các thao tác sau:

    1.  Hợp nhất hai tập hợp chứa hai phần tử.
    2.  Di chuyển một phần tử riêng lẻ sang tập hợp chứa một phần tử khác.
    3.  Truy vấn kích thước và tổng các phần tử của tập hợp chứa một phần tử.

??? note "Lời giải"
    Trong bài này, thao tác 1 và thao tác 3 đều dễ xử lý; điểm khó nằm ở thao tác 2.
    Giả sử cần di chuyển phần tử $x$ sang tập hợp chứa phần tử $y$.
    Trong DSU thông thường, không thể trực tiếp đặt cha của phần tử $x$ thành gốc của tập hợp chứa phần tử $y$,
    vì làm như vậy sẽ di chuyển cả các phần tử trong cây con của $x$.
    Để xử lý vấn đề này, cần bảo đảm phần tử $x$ không có nút con.
    Do đó, khi xây DSU, tạo cho mỗi phần tử $x$ một nút ảo $\tilde x$,
    rồi cho cha của phần tử $x$ trỏ tới nút ảo tương ứng $\tilde x$.
    Như vậy, khi hợp nhất hai tập hợp, ta luôn nối một gốc cây vào một gốc cây khác;
    mà mọi gốc cây đều là nút ảo, nên chỉ nút ảo mới có nút con,
    còn mọi nút thật lưu phần tử đều không có nút con.
    Khi đó, việc di chuyển phần tử trở nên dễ cài đặt hơn nhiều.

??? note "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/ds/code/dsu/dsu_1.cpp"
        ```

    === "Python"
        ```python
        --8<-- "docs/ds/code/dsu/dsu_1.py"
        ```

???+ example "[Luogu P2024 NOI2001 Food Chain](https://www.luogu.com.cn/problem/P2024)"
    Trong vương quốc động vật có ba loại động vật $A,B,C$;
    chuỗi thức ăn của ba loại động vật này tạo thành một vòng thú vị.
    $A$ ăn $B$, $B$ ăn $C$, và $C$ ăn $A$.

    Hiện có $N$ con vật, được đánh số từ $1 \sim N$.
    Mỗi con vật thuộc một trong ba loại $A,B,C$, nhưng chưa biết chính xác nó thuộc loại nào.

    Có người dùng hai dạng phát biểu để mô tả quan hệ chuỗi thức ăn giữa $N$ con vật này:

    -   Phát biểu dạng thứ nhất là `1 X Y`, nghĩa là $X$ và $Y$ cùng loại.
    -   Phát biểu dạng thứ hai là `2 X Y`, nghĩa là $X$ ăn $Y$.

    Người này lần lượt đưa ra $K$ phát biểu thuộc hai dạng trên về $N$ con vật;
    trong đó có phát biểu đúng và có phát biểu sai.
    Một phát biểu là sai nếu thỏa một trong ba điều kiện sau, ngược lại là đúng.

    -   Phát biểu hiện tại mâu thuẫn với một số phát biểu đúng trước đó;
    -   Trong phát biểu hiện tại, $X$ hoặc $Y$ lớn hơn $N$;
    -   Phát biểu hiện tại nói rằng $X$ ăn chính $X$.

    Nhiệm vụ là dựa trên $N$ và $K$ phát biểu đã cho để xuất ra tổng số phát biểu sai.

??? note "Lời giải 1"
    Xét dùng DSU có trọng số để duy trì thông tin chuỗi thức ăn.
    Nếu $x$ và $y$ cùng loại, thì $x\equiv y\pmod 3$;
    nếu $x$ ăn $y$, thì $x - y \equiv 1 \pmod 3$.
    Như vậy, bài toán được chuyển về bài mẫu ở phần trước.

    Cụ thể, với mỗi phát biểu, ngoài các phát biểu sai ngay như $x>n$ hoặc $y>n$,
    cần kiểm tra $x$ và $y$ đã thuộc cùng thành phần hay chưa:
    nếu đã thuộc cùng thành phần, tính khoảng cách giữa chúng theo modulo rồi so sánh với thông tin mà phát biểu khẳng
    định; nếu chưa, hợp nhất chúng theo thông tin do phát biểu cung cấp.
    Trừ các trường hợp sai ngay,
    một phát biểu là sai khi và chỉ khi hai nút được nhắc tới đã thuộc cùng thành phần,
    và khoảng cách tương ứng mâu thuẫn với thông tin mà phát biểu khẳng định.

??? note "Cài đặt tham khảo 1"
    === "C++"
        ```cpp
        --8<-- "docs/ds/code/dsu/dsu_6.cpp"
        ```

    === "Python"
        ```python
        --8<-- "docs/ds/code/dsu/dsu_6.py"
        ```

??? note "Lời giải 2"
    Tách một phần tử $x$ thành ba trạng thái.
    Khi cài đặt cụ thể, có thể trực tiếp xem các trạng thái khác nhau là các phần tử khác nhau:

    -   Trạng thái nằm cùng tập hợp với $x$ biểu diễn cùng loài với $x$;
    -   Trạng thái nằm cùng tập hợp với $x+n$ biểu diễn loại có thể bị $x$ ăn;
    -   Trạng thái nằm cùng tập hợp với $x+2n$ biểu diễn loại có thể ăn $x$.

    Khi đó, với một phát biểu:

    -   `1 x y` là phát biểu sai khi và chỉ khi:

        1.  $x>N$ hoặc $y>N$;
        2.  $y$ nằm cùng tập hợp với một trong $x+n$ hoặc $x+2n$.
    -   `2 x y` là phát biểu sai khi và chỉ khi:

        1.  $x>N$ hoặc $y>N$;
        2.  $y$ nằm cùng tập hợp với một trong $x$ hoặc $x+2n$.
    -   Nếu là phát biểu đúng, hợp nhất các trạng thái tương ứng.

??? note "Cài đặt tham khảo 2"
    === "C++"
        ```cpp
        --8<-- "docs/ds/code/dsu/dsu_2.cpp"
        ```

    === "Python"
        ```python
        --8<-- "docs/ds/code/dsu/dsu_2.py"
        ```

???+ example "[ABC396E Min of Restricted Sum](https://atcoder.jp/contests/abc396/tasks/abc396_e)"
    Cho các số nguyên $N, M$ và ba dãy số nguyên độ dài $M$:
    $X=(X_1,X_2,\ldots,X_M)$, $Y=(Y_1,Y_2,\ldots,Y_M)$, $Z=(Z_1,Z_2,\ldots,Z_M)$.
    Bảo đảm mọi phần tử của $X$ và $Y$ đều nằm trong phạm vi từ $1$ đến $N$.

    Định nghĩa một dãy số nguyên không âm độ dài $N$, $A=(A_1,A_2,\ldots,A_N)$, là một **dãy số nguyên tốt** khi và chỉ
    khi thỏa điều kiện sau:

    -   Với mọi số nguyên $i$ thỏa $1 \leq i \leq M$,
        có $A_{X_i} \oplus A_{Y_i} = Z_i$, trong đó $\oplus$ biểu thị phép XOR.

    Cần xác định có tồn tại dãy số nguyên tốt như vậy hay không.
    Nếu tồn tại, cần tìm một dãy số nguyên tốt làm cho tổng các phần tử
    $\displaystyle \sum_{i=1}^N A_i$ nhỏ nhất và xuất dãy đó.

??? note "Lời giải"
    XOR chính là quan hệ "giống nhau" hoặc "khác nhau" trên từng bit nhị phân.
    Vì vậy, nếu xét riêng từng bit nhị phân của $A_i$,
    quan hệ XOR có thể được duy trì bằng DSU có trọng số hoặc DSU phân loại.
    Các phần tử trong cùng một thành phần liên thông tương ứng với cùng một bit của các số khác nhau trong $A$.
    Khi thống kê đáp án, các phần tử trong cùng một thành phần liên thông thường được chia thành hai nhóm;
    hai nhóm phải nhận giá trị khác nhau.
    Chỉ cần gán nhóm lớn hơn bằng $0$ và nhóm còn lại bằng $1$ là bảo đảm tổng trọng số nhỏ nhất.

??? note "Cài đặt tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/ds/code/dsu/dsu_3.cpp"
        ```

    === "Python"
        ```python
        --8<-- "docs/ds/code/dsu/dsu_3.py"
        ```

<span id="bài-tập"></span>

## Bài tập

-   [NOI2015 Program Automatic Analysis](https://uoj.ac/problem/127)
-   [JSOI2008 Star Wars](https://www.luogu.com.cn/problem/P1197)
-   [NOIP2023 Three-Valued Logic](https://www.luogu.com.cn/problem/P9869)
-   [NOI2002 Legend of Galactic Heroes](https://www.luogu.com.cn/problem/P1196)

<span id="ứng-dụng-khác"></span>

## Ứng dụng khác

Thuật toán Kruskal trong [cây khung nhỏ nhất](../graph/mst.md) và thuật toán Tarjan trong
[tổ tiên chung gần nhất](../graph/lca.md) đều dựa trên DSU.

Xem thêm chuyên đề liên quan ở [ứng dụng DSU](../topic/dsu-app.md).

<span id="tài-liệu-tham-khảo-và-đọc-thêm"></span>

## Tài liệu tham khảo và đọc thêm

1.  [Zhihu: DSU có thật sự có tối ưu nén đường đi kiểu chia đôi không?](https://www.zhihu.com/question/28410263/answer/40966441)
2.  Gabow, H. N., & Tarjan, R. E. (1985). A Linear-Time Algorithm for a Special Case of Disjoint Set Union.
    JOURNAL OF COMPUTER AND SYSTEM SCIENCES, 30, 209-221.
    [PDF](https://dl.acm.org/doi/pdf/10.1145/800061.808753)
3.  [CSDN: DSU mở rộng miền & DSU có trọng số](https://blog.csdn.net/qqqqqwerttwtwe/article/details/145440100)

[^tarjan1984worst]: Tarjan, R. E., & Van Leeuwen, J. (1984). Worst-case analysis of set union algorithms. Journal of the
    ACM (JACM), 31(2), 245-281.
    [ResearchGate PDF](https://www.researchgate.net/profile/Jan_Van_Leeuwen2/publication/220430653_Worst-case_Analysis_of_Set_Union_Algorithms/links/0a85e53cd28bfdf5eb000000/Worst-case-Analysis-of-Set-Union-Algorithms.pdf)

[^yao1985expected]: Yao, A. C. (1985). On the expected performance of path compression algorithms.
    [SIAM Journal on Computing, 14(1), 129-133.](https://epubs.siam.org/doi/abs/10.1137/0214010?journalCode=smjcat)
