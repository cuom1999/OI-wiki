author: 0x03A6, abc1763613206, auuuu4, CCXXXI, Conless, Enter-tainer, fanenr, happyZYM, hsfzLZH1, iamtwz, LeverImmy, leverimmy, Lhcfl, Marcythm, RIvance, Tiphereth-A, trudbot, Xeniume, Xeonacid, YBYCS, yuhuoji

Cây đỏ-đen là một loại cây tìm kiếm nhị phân tự cân bằng. Mỗi nút lưu thêm một trường màu ("RED" hoặc "BLACK"), dùng để
bảo đảm cây vẫn cân bằng khi chèn và xóa.

Cây đỏ-đen là một biến thể của cây B bậc 4 ([cây 2-3-4](https://en.wikipedia.org/wiki/2%E2%80%933%E2%80%934_tree)).[^gilbas1978]

## Tính chất

Một cây đỏ-đen hợp lệ phải tuân theo bốn tính chất sau:

1.  Mỗi nút có màu đỏ hoặc đen
2.  Nút NIL (nút lá rỗng) có màu đen
3.  Các nút con của nút đỏ đều có màu đen
4.  Trên mọi đường đi từ nút gốc đến nút NIL, số lượng nút đen là như nhau

Hình dưới đây là một cây đỏ-đen hợp lệ:

![Ví dụ cây đỏ-đen hợp lệ](images/rbtree-example.svg)

???+ note "Ghi chú"
    Một số tài liệu còn thêm tính chất thứ năm, tức nút gốc phải có màu đen.
    Tính chất này yêu cầu sau khi hoàn tất thao tác chèn, nếu nút gốc có màu đỏ thì tô nó thành đen.
    Tuy nhiên, thao tác tô đen nút gốc cũng có thể được trì hoãn đến khi thực hiện thao tác xóa,
    nên tính chất này không bắt buộc phải thỏa mãn.
    Phần cài đặt trong bài này vẫn thỏa mãn tính chất đó.
    Để chặt chẽ, dưới đây là phần dịch ý từ [Wikipedia](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#Properties):
    
    > Một số tác giả, chẳng hạn Cormen và cộng sự,[^cite_note-cormen2009-18] xem "gốc là nút đen" là yêu cầu thứ năm;
    > nhưng Mehlhorn & Sanders[^cite_note-mehlhorn2008-17] và Sedgewick & Wayne[^cite_note-algs4-16] thì không.
    > Vì luôn có thể đổi gốc từ đỏ sang đen, quy tắc này ít ảnh hưởng đến phân tích.
    > Bài viết này cũng bỏ qua quy tắc đó, vì nó làm các thuật toán và chứng minh đệ quy hơi kém gọn.

## Định nghĩa lớp cây đỏ-đen

```cpp
--8<-- "docs/ds/code/rbtree/rbtree.hpp:class-node1"
  // ...
--8<-- "docs/ds/code/rbtree/rbtree.hpp:class-node2"
```

???+ note "Ghi chú"
    Trong phần lưu trữ nút của cây đỏ-đen, dùng mảng để lưu con trỏ đến các nút con có thể tăng khả năng tái sử dụng mã.

## Thao tác

???+ note "Ghi chú"
    Thao tác chèn/xóa của cây đỏ-đen có nhiều cách cài đặt.
    Bài này dùng cách cài đặt trong *Introduction to Algorithms*,
    chia việc duy trì cân bằng sau khi chèn thành 3 trường hợp và sau khi xóa thành 4 trường hợp.

Các thao tác duyệt cây, tìm giá trị nhỏ nhất/lớn nhất, tìm kiếm phần tử, tìm hạng của phần tử, truy ngược phần tử theo
hạng, tìm tiền nhiệm/kế nhiệm, v.v. của cây đỏ-đen giống với [cây tìm kiếm nhị phân](./bst.md), nên không trình bày lại.

Ngoài ra, trong chú thích mã của phần duy trì cân bằng khi chèn/xóa bên dưới, dùng các quy ước sau:

-   Dùng `p` để biểu thị nút `p` có màu đen;
-   Dùng `[p]` để biểu thị nút `p` có màu đỏ;
-   Dùng `{p}` để biểu thị nút `p` có màu đỏ hoặc đen;
-   Dùng `|p|` để biểu thị nút `p` là nút NIL hoặc có màu đen.

### Phép xoay

Thao tác xoay là điểm mấu chốt giúp phần lớn các cây cân bằng duy trì cân bằng. Nó có thể thay đổi độ sâu của các nút
cục bộ mà không làm thay đổi kết quả duyệt trung thứ tự của một cây tìm kiếm nhị phân hợp lệ.

![Các phép xoay trong cây đỏ-đen](images/rbtree-rotate.svg)

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:rotate"
    ```

### Chèn

Thao tác chèn của cây đỏ-đen tương tự cây tìm kiếm nhị phân thông thường.
Với cây đỏ-đen, nút mới chèn ban đầu có màu đỏ.
Sau khi chèn xong, cần chỉnh sửa dựa trên trạng thái của nút vừa chèn và các nút liên quan
để thỏa mãn bốn tính chất đã nêu ở trên.

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:insert"
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:insert-leaf"
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:insert-fixup1"
        // ...
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:insert-fixup2"
    ```

### Duy trì cân bằng sau khi chèn

???+ note "Ghi chú"
    Để hiểu sâu hơn, có thể tự kiểm tra xem sau khi duy trì cân bằng thì tính chất 4 có được thỏa mãn hay không.

Vì nút được chèn, nếu không phải là nút gốc, chắc chắn là nút đỏ, nên sau khi chèn có thể vi phạm tính chất 3 và cần duy
trì cân bằng.

Gọi nút được chèn là $n$, nút cha là $p$, nút ông là $g$, nút chú là $u$. Theo tính chất 3, $g$ chắc chắn có màu đen.

Bắt đầu từ vị trí chèn và duy trì đệ quy lên trên. Nếu $p$ có màu đen thì có thể dừng; nếu không, chia thành 3 trường
hợp.

```cpp
--8<-- "docs/ds/code/rbtree/rbtree.hpp:insert-aux1"
      // ...
--8<-- "docs/ds/code/rbtree/rbtree.hpp:insert-aux2"
```

#### Trường hợp chèn 1

$p$ và $u$ đều có màu đỏ. Khi đó chỉ cần tô màu lại.

![](images/rbtree-insert-case1.svg)

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:insert-case1"
    ```

#### Trường hợp chèn 2

$p$ có màu đỏ, $u$ có màu đen, hướng của $p$ và hướng của $n$ khác nhau.

Khi đó cần xoay nút $p$ để chuyển thành trường hợp thứ ba.

![](images/rbtree-insert-case2.svg)

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:insert-case2"
    ```

#### Trường hợp chèn 3

$p$ có màu đỏ, $u$ có màu đen, hướng của $p$ và hướng của $n$ giống nhau.

Khi đó cần xoay nút $g$ để đưa $p$ thành gốc của cây con, rồi hoán đổi màu của $p$ và $g$.

![](images/rbtree-insert-case3.svg)

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:insert-case3"
    ```

### Xóa

So với cây tìm kiếm nhị phân thông thường, thao tác xóa của cây đỏ-đen có thêm một số bước. Cụ thể:

-   Nếu nút cần xóa $n$ có hai nút con, hoán đổi dữ liệu của $n$ với nút nhỏ nhất $s$ trong cây con phải,
    rồi đặt $n$ thành $s$. Khi đó $n$ không thể có hai nút con.
-   Nếu nút cần xóa $n$ có một nút con $s$, theo tính chất 4, $s$ chắc chắn có màu đỏ;
    tiếp đó theo tính chất 3, $n$ chắc chắn có màu đen.
    Vì vậy chỉ cần thay con trỏ tương ứng của $n$ trong nút cha $p$ bằng địa chỉ của $s$,
    thay con trỏ cha của $s$ bằng địa chỉ của $p$, rồi tô $s$ thành đen.
-   Nếu nút cần xóa $n$ không có nút con, và $n$ là nút gốc hoặc nút đỏ, thì có thể xóa trực tiếp.
    Ngược lại, xóa trực tiếp sẽ vi phạm tính chất 4, nên cần duy trì tính cân bằng.

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:delete"
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-leaf"
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-fixup1"
        // ...
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-fixup2"
    ```

### Duy trì cân bằng sau khi xóa

???+ note "Ghi chú"
    Để hiểu sâu hơn, có thể tự kiểm tra xem sau khi duy trì cân bằng thì tính chất 4 có được thỏa mãn hay không.

Từ phần thảo luận ở trên, $n$ là nút lá màu đen và không phải nút gốc.
Đặt nút cha của $n$ là $p$, nút anh em là $s$, các nút cháu lần lượt là $c$ và $d$.

Việc duy trì sau khi xóa cũng bắt đầu từ $n$ và duy trì đệ quy lên trên.
Nếu $n$ là nút gốc hoặc $n$ có màu đỏ thì có thể dừng; nếu không, chia thành 4 trường hợp.

```cpp
--8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-aux1"
      // Trường hợp xóa 1
      // ...
      // Các trường hợp khác
--8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-aux2"
      // ...
--8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-aux3"
```

#### Trường hợp xóa 1

$s$ có màu đỏ.

Khi đó xoay $p$, đưa $s$ thành nút gốc của cây con,
rồi hoán đổi màu của $s$ và $p$ để chuyển thành một trong ba trường hợp còn lại.

![](images/rbtree-remove-case1.svg)

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-case1"
    ```

#### Trường hợp xóa 2

Màu của $p$ chưa xác định; $s$, $c$, $d$ đều có màu đen.

Lúc này chỉ cần tô $s$ thành đỏ.

![](images/rbtree-remove-case2.svg)

Cần chú ý rằng nếu $p$ có màu đỏ thì sẽ vi phạm tính chất 3.
Tuy nhiên nếu $p$ có màu đỏ thì vòng lặp sẽ thoát trực tiếp, nên cuối cùng chỉ cần tô nó thành đen.

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-case2"
    ```

#### Trường hợp xóa 3

Màu của $p$ chưa xác định; $s$ và $d$ đều có màu đen, $c$ có màu đỏ.

Khi đó cần xoay $s$ để $c$ trở thành nút gốc của cây con tương ứng với $s$ ban đầu,
rồi hoán đổi màu của $s$ và $c$ để chuyển thành trường hợp thứ tư.

![](images/rbtree-remove-case3.svg)

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-case3"
    ```

#### Trường hợp xóa 4

Màu của $p$ và $c$ chưa xác định; $s$ có màu đen, $d$ có màu đỏ.

Khi đó cần xoay $p$ để $s$ trở thành gốc của cây con, hoán đổi màu của $s$ và $p$,
rồi tô $d$ thành đen là có thể kết thúc việc duy trì cân bằng.

![](images/rbtree-remove-case4.svg)

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:delete-case4"
    ```

## Mã tham khảo

Đoạn mã dưới đây là một `set` được cài đặt bằng cây đỏ-đen:

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:full"
    ```

??? note "Bài tập ví dụ"
    [Luogu P3369 - mẫu cây cân bằng thông thường](https://www.luogu.com.cn/problem/P3369) và
    [Luogu P6136 - mẫu cây cân bằng thông thường, bản tăng cường dữ liệu](https://www.luogu.com.cn/problem/P6136)

    ```cpp
    --8<-- "docs/ds/code/rbtree/rbtree.hpp:class"
    --8<-- "docs/ds/code/rbtree/rbtree_1.cpp:main"
    ```

## Quan hệ với cây 2-3-4

Cây 2-3-4 là cây B bậc 4. Giống như cây B nói chung, cây 2-3-4 có thể thực hiện tìm kiếm, chèn và xóa trong thời gian
$O(\log n)$. Các nút của cây 2-3-4 được chia thành ba loại: nút 2, nút 3 và nút 4, lần lượt chứa một, hai hoặc ba phần
tử dữ liệu. Tất cả các nút lá đều ở cùng một độ sâu (tầng dưới cùng), và mọi dữ liệu đều được lưu trữ có thứ tự.

Cây 2-3-4 và cây đỏ-đen là đẳng cấu; bất kỳ cây đỏ-đen nào cũng tương ứng duy nhất với một cây 2-3-4. Các thao tác chèn
và xóa trên cây 2-3-4 gây ra việc mở rộng, tách và gộp nút, tương đương với đổi màu và xoay trong cây đỏ-đen.

Hình dưới đây cho thấy các nút 2, nút 3 và nút 4 của cây 2-3-4 tương ứng với các nút trong cây đỏ-đen. Lưu ý rằng nút 3
của cây 2-3-4 tương ứng với hai trường hợp trong cây đỏ-đen: nút đỏ nghiêng trái và nút đỏ nghiêng phải. Do đó, một cây
2-3-4 có thể tương ứng với nhiều cây đỏ-đen.

![Đối ứng giữa nút 2, nút 3, nút 4 và cây đỏ-đen](images/2-3-4-tree-rbt-1.svg)

Hình dưới đây là một cây đỏ-đen và cây 2-3-4 tương ứng với nó. Nếu đưa các nút đỏ trong cây đỏ-đen lên hai phía trái
phải của nút cha để tạo thành một nút cây B, có thể thu được cây 2-3-4 tương ứng. Số nút của cây đỏ-đen bằng số phần tử
dữ liệu của cây 2-3-4.

![Cây đỏ-đen và cây 2-3-4 tương ứng](images/2-3-4-tree-rbt-2.svg)

Có thể hiểu thao tác chèn và xóa của cây đỏ-đen bằng cách đối chiếu với cây 2-3-4.[^234-vs-rbt]

## Sử dụng trong các dự án kỹ thuật thực tế

Cây đỏ-đen là một trong những cây cân bằng trong bộ nhớ có hiệu quả tổng hợp cao và được dùng rộng rãi trong công
nghiệp, nên có phạm vi ứng dụng rộng trong các dự án kỹ thuật thực tế. Dưới đây liệt kê một vài trường hợp sử dụng thực
tế, kèm liên kết mã nguồn tương ứng để tiện đối chiếu.

### Linux

Mã nguồn:

-   [`linux/lib/rbtree.c`](https://elixir.bootlin.com/linux/latest/source/lib/rbtree.c)

Trong Linux, mọi thao tác trên cây đỏ-đen đều được cài đặt bằng vòng lặp, vừa bảo đảm hiệu suất vừa bổ sung nhiều chú
thích để tăng khả năng đọc mã. Cây đỏ-đen trong nhân Linux được sử dụng rất rộng rãi; dưới đây chỉ liệt kê vài ví dụ
kinh điển.

-   [Lập lịch tác vụ không thời gian thực CFS](https://www.kernel.org/doc/html/latest/scheduler/sched-design-CFS.html)

    Sau phiên bản nhân Linux ổn định 2.6.24, bộ lập lịch mới CFS được sử dụng.
    Tất cả tiến trình runnable không thời gian thực đều được duy trì trong một cây đỏ-đen với khóa là thời gian chạy ảo,
    nhằm lập lịch mọi tác vụ công bằng và hiệu quả hơn.
    CFS bỏ active/expired array và việc tính toán động độ ưu tiên,
    không còn theo dõi thời gian ngủ của tác vụ hay phân biệt tác vụ có tương tác hay không.
    Thay vào đó, trong quá trình lập lịch, nó dùng cây đỏ-đen có khóa được tính dựa trên thời gian để chọn tác vụ tiếp
    theo, và xác định độ ưu tiên lập lịch theo trạng thái thời gian CPU mà mọi tác vụ đã chiếm dụng.

-   [epoll](https://man7.org/linux/man-pages/man7/epoll.7.html)

    Tên đầy đủ của epoll là event poll, một cách cài đặt IO multiplexing trong nhân Linux và là phiên bản cải tiến của
    poll/select ban đầu. Cài đặt epoll trong Linux chọn dùng cây đỏ-đen để lưu trữ file descriptor.

### Nginx

Mã nguồn:

-   [`nginx/src/core/ngx_rbtree.h`](https://github.com/nginx/nginx/blob/master/src/core/ngx_rbtree.h)
-   [`nginx/src/core/ngx_rbtree.c`](https://github.com/nginx/nginx/blob/master/src/core/ngx_rbtree.c)

Bộ định thời ở user space trong nginx được cài đặt bằng cây đỏ-đen. Trong nginx, mọi nút timer đều được duy trì bởi một
cây đỏ-đen; trong mỗi vòng lặp của tiến trình worker đều gọi hàm `ngx_process_events_and_timers`, và trong hàm này sẽ
gọi hàm xử lý bộ định thời `ngx_event_expire_timers`. Mỗi lần, hàm này liên tục lấy ra nút có giá trị thời gian nhỏ nhất
từ cây đỏ-đen, kiểm tra xem chúng đã timeout hay chưa, rồi thực thi hàm của chúng cho đến khi nút được lấy ra chưa
timeout.

Có nhiều tài nguyên công khai phân tích mã nguồn cây đỏ-đen trong nginx, có thể tham khảo thêm khi cần.

### C++

Mã nguồn:

-   GNU libstdc++

    -   [`libstdc++-v3/include/bits/stl_tree.h`](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/stl_tree.h)
    -   [`libstdc++-v3/src/c++98/tree.cc`](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/src/c%2B%2B98/tree.cc)

    Ngoài ra, `libstdc++` cung cấp
    [`__gnu_cxx::rb_tree`](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/ext/rb_tree) trong
    `<ext/rb_tree>`.
    Nó kế thừa `std::_Rb_tree` và có thể xem là một bí danh kiểu dành cho sử dụng bên ngoài.
    Cần chú ý rằng header này **không phải** là một phần của tiêu chuẩn C++,
    nên không khuyến nghị sử dụng nếu không thật cần thiết.

    [`pb_ds`](../lang/pb-ds/tree.md) của `libstdc++` cũng cung cấp cây đỏ-đen.

-   LLVM libcxx
    -   [`libcxx/include/__tree`](https://github.com/llvm/llvm-project/blob/main/libcxx/include/__tree)

-   Microsoft STL
    -   [`stl/inc/xtree`](https://github.com/microsoft/STL/blob/main/stl/inc/xtree)

Cấu trúc dữ liệu bên trong của `std::set` và `std::map` trong phần lớn các STL chính là cây đỏ-đen (ví dụ những cài đặt
đã nêu ở trên). Tuy nhiên, tiêu chuẩn C++ không quy định bắt buộc phải cài đặt `std::set` và `std::map` bằng cây
đỏ-đen, nên trong dự án kỹ thuật không nên sử dụng trực tiếp cấu trúc dữ liệu nội bộ của `std::set` và `std::map`.

### OpenJDK

Mã nguồn:

-   [`java.util.TreeMap<K, V>`](https://github.com/openjdk/jdk/blob/master/src/java.base/share/classes/java/util/TreeMap.java)
-   [`java.util.TreeSet<K, V>`](https://github.com/openjdk/jdk/blob/master/src/java.base/share/classes/java/util/TreeSet.java)
-   [`java.util.HashMap<K, V>`](https://github.com/openjdk/jdk/blob/master/src/java.base/share/classes/java/util/HashMap.java)

Trong JDK, `TreeMap` và `TreeSet` đều dùng cây đỏ-đen làm cấu trúc dữ liệu nền. Đồng thời, sau JDK 1.8, khi độ dài danh
sách liên kết của mỗi bucket trong bảng băm nội bộ của `HashMap` vượt quá 8, nó cũng tự động chuyển thành cây đỏ-đen để
nâng cao hiệu suất tìm kiếm.

## Tài liệu tham khảo

-   Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022).*Introduction to algorithms*. MIT press.
-   [Red-Black Tree - Wikipedia](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)
-   [Red-Black Tree Visualization](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)

[^gilbas1978]: L. J. Guibas and R. Sedgewick, "A dichromatic framework for balanced trees," *19th Annual Symposium on
    Foundations of Computer Science (sfcs 1978)*, Ann Arbor, MI, USA, 1978, pp. 8-21,
    doi:[10.1109/SFCS.1978.3](https://doi.org/10.1109%2FSFCS.1978.3).

[^cite_note-cormen2009-18]: <https://en.wikipedia.org/wiki/Red–black_tree#cite_note-Cormen2009-18>

[^cite_note-mehlhorn2008-17]: <https://en.wikipedia.org/wiki/Red–black_tree#cite_note-Mehlhorn2008-17>

[^cite_note-algs4-16]: <https://en.wikipedia.org/wiki/Red–black_tree#cite_note-Algs4-16>: 432–447

[^234-vs-rbt]: [Bài blog này](https://www.cnblogs.com/zhenbianshu/p/8185345.html) cung cấp phần mô tả chi tiết.
