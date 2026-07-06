Trang này giới thiệu ngắn gọn khái niệm, cách cài đặt và ứng dụng của đồ thị Euler.

## Định nghĩa

Trong bài viết này chỉ xét đồ thị hữu hạn.

Trong lý thuyết đồ thị, **đường đi Euler (Eulerian path)** là một đường đi đi qua mỗi cạnh của đồ thị đúng một lần, còn **chu trình Euler (Eulerian circuit)** là một chu trình đi qua mỗi cạnh của đồ thị đúng một lần.
Nếu một đồ thị có chu trình Euler, đồ thị đó được gọi là **đồ thị Euler (Eulerian graph)**; nếu một đồ thị không có chu trình Euler nhưng có đường đi Euler, đồ thị đó được gọi là **đồ thị nửa Euler (semi-Eulerian graph)**.

??? warning "Cảnh báo"
    Dù định nghĩa trong bài dùng từ "đường đi", nói chặt chẽ hơn thì khái niệm được dùng phải là "vết (trail)". Đường đi Euler và chu trình Euler chỉ yêu cầu mỗi cạnh được dùng đúng một lần, chứ không hạn chế số lần đi qua một đỉnh.

## Tính chất

Trong phần dưới, giả sử đồ thị $G$ đang xét không có đỉnh cô lập. Giả thiết này không mất tính tổng quát, vì nếu $G$ có đỉnh cô lập thì các tính chất dưới đây vẫn đúng với đồ thị $G'$ thu được sau khi xóa các đỉnh cô lập khỏi $G$.

Với đồ thị liên thông $G$, ba tính chất sau tương đương với nhau:

1.  $G$ là đồ thị Euler;
2.  Mọi đỉnh của $G$ đều có bậc chẵn (với đồ thị có hướng, mỗi đỉnh có bậc vào bằng bậc ra);
3.  $G$ có thể được phân rã thành hợp của một số chu trình đôi một không chung cạnh.

Tiếp theo là chứng minh tính tương đương.

Nếu một đồ thị $G$ là đồ thị Euler, thì mọi đỉnh của $G$ đều có bậc chẵn: xét việc bắt đầu từ một đỉnh bất kỳ rồi đi hết một vòng theo chu trình Euler, khi đó bậc của mỗi đỉnh $v$ bằng số lần rời khỏi $v$ cộng với số lần đi đến $v$. Do quỹ đạo di chuyển là một chu trình, với mỗi đỉnh $v$, số lần rời khỏi đỉnh đó bằng số lần đi đến đỉnh đó. Nói cách khác, bậc của mỗi đỉnh đều có dạng $2k$, tức là số chẵn.
Đặc biệt, với đồ thị có hướng, theo cùng lập luận trên, mỗi đỉnh có bậc vào bằng bậc ra.

Nếu mọi đỉnh của một đồ thị $G$ đều có bậc chẵn (hoặc bậc vào bằng bậc ra), thì nó có thể được phân rã thành hợp rời cạnh của một số chu trình: bắt đầu từ một đỉnh bất kỳ $u$, chọn một cạnh ra bất kỳ $(u, v)$, đi đến đỉnh kề tương ứng $v$ rồi xóa $(u, v)$, cho đến khi quay lại đỉnh xuất phát ban đầu $u$. Quá trình này cuối cùng sẽ quay lại $u$: mỗi khi đi đến một đỉnh mới $v \neq u$, theo tính chất ở trên, bậc còn lại của đỉnh đó là số lẻ, tức là vẫn còn một cạnh ra, nên quá trình không thể kết thúc tại $v$. (Nói cách khác, quá trình sẽ dừng khi và chỉ khi quay lại $u$.) Vì số cạnh của đồ thị $G$ là hữu hạn, quá trình sẽ dừng sau hữu hạn bước, nên cuối cùng phải quay lại $u$ và thu được một chu trình. Lập luận trên chỉ dùng tính chất mọi bậc đỉnh đều chẵn, và sau khi tìm rồi xóa một chu trình, phần đồ thị còn lại vẫn thỏa tính chất này; do đó có thể lặp lại quá trình cho đến khi đồ thị còn lại rỗng, qua đó tách $G$ thành một số chu trình đôi một không chung cạnh.
Hơn nữa, mỗi chu trình cũng có thể được tách tại các đỉnh mà nó đi qua nhiều lần để trở thành hợp rời cạnh của một số chu trình đơn, nên trong tính chất trên cũng có thể thay "chu trình" bằng "chu trình đơn".

Nếu một đồ thị liên thông $G$ có thể được phân rã thành hợp rời cạnh của một số chu trình, thì $G$ là đồ thị Euler: với một tập các chu trình không chung cạnh, mỗi lần chọn hai chu trình có đỉnh chung rồi ghép chúng thành một chu trình, lặp lại cho đến khi không còn hai chu trình nào có đỉnh chung.
Khi quá trình này kết thúc, chu trình còn lại là duy nhất. Với hai chu trình không chung cạnh bất kỳ $P_1, P_2$, nếu $P_1$ và $P_2$ có đỉnh chung thì có thể ghép trực tiếp tại đỉnh chung đó; nếu không, chọn tùy ý một đỉnh $v_1$ trên $P_1$ và một đỉnh $v_2$ trên $P_2$. Do $G$ liên thông, tồn tại một đường đi nối $v_1$ với $v_2$ gồm các cạnh $e_1, e_2, \ldots, e_k$, trong đó mỗi cạnh $e_i$ nằm trong một chu trình $C_i$, đồng thời $P_1$ và $C_1$, $C_i$ và $C_{i+1}$, $C_k$ và $P_2$ đều có đỉnh chung (hoặc $C_i = C_{i+1}$, trường hợp này không ảnh hưởng đến chứng minh). Khi đó, $P_1$ và $P_2$ có thể được ghép thông qua $C_1, \ldots, C_k$. Nói cách khác, hai chu trình bất kỳ đều có thể được ghép, nên chu trình cuối cùng còn lại là duy nhất; tập cạnh tạo nên chu trình đó chính là hợp của tất cả chu trình không chung cạnh, tức là $E(G)$. Chu trình này là chu trình Euler trên $G$, do đó $G$ là đồ thị Euler.

Các tính chất trên cũng tạo thành tiêu chuẩn nhận biết đồ thị Euler. Cụ thể, một đồ thị là đồ thị Euler khi và chỉ khi các đỉnh có bậc khác không liên thông (liên thông mạnh với đồ thị có hướng) với nhau, và mọi đỉnh đều có bậc chẵn (hoặc bậc vào bằng bậc ra).

Với đồ thị nửa Euler, các tính chất tương tự đồ thị Euler: một đồ thị nửa Euler có đúng hai đỉnh bậc lẻ, và hai đỉnh này chính là hai đầu mút của đường đi Euler. Bằng cách nối hai đỉnh đó với nhau, có thể biến đồ thị nửa Euler thành đồ thị Euler. Ngược lại, xóa một cạnh bất kỳ trong đồ thị Euler sẽ thu được một đồ thị nửa Euler.
Từ đó suy ra tiêu chuẩn nhận biết đồ thị nửa Euler: một đồ thị là đồ thị nửa Euler khi và chỉ khi các đỉnh có bậc khác không liên thông (liên thông mạnh với đồ thị có hướng) với nhau, và có đúng hai đỉnh bậc lẻ. Với đồ thị có hướng, điều kiện thứ hai là tồn tại đúng hai đỉnh $u, v$ sao cho $\deg^+(u) - \deg^-(u) = 1, \deg^+(v) - \deg^-(v) = -1$, còn mọi đỉnh còn lại đều có bậc vào bằng bậc ra.

## Xây dựng chu trình Euler/đường đi Euler

Phần này giới thiệu thuật toán Hierholzer thường dùng nhất. Ý tưởng cốt lõi của thuật toán là tận dụng tính chất thứ ba của đồ thị Euler ở trên: đồ thị Euler có thể được phân rã thành hợp của một số chu trình đôi một không chung cạnh.
Phần chứng minh trên đã đưa ra một thao tác hoàn chỉnh và khả thi để ghép các chu trình không chung cạnh thành chu trình Euler; khi dùng cấu trúc dữ liệu phù hợp để lưu trữ (chẳng hạn dùng cấu trúc dạng danh sách liên kết để lưu chu trình), thao tác này khá trực tiếp.

Quy trình cụ thể của thuật toán là trước hết tìm trong đồ thị một chu trình làm chu trình hiện tại. Mỗi lần chọn một đỉnh trên chu trình hiện tại vẫn còn bậc dư khác không, xuất phát từ đỉnh đó để tìm một chu trình đơn mới, rồi ghép chu trình đơn này với chu trình hiện tại. Lặp lại quá trình cho đến khi mọi đỉnh trên chu trình hiện tại đều không còn bậc dư; khi đó chu trình hiện tại chính là chu trình Euler.

Thuật toán cũng áp dụng được cho đồ thị có hướng. Với đồ thị nửa Euler, có thể tìm trong đồ thị một đường đi nối hai đỉnh bậc lẻ làm đường đi hiện tại; mỗi lần chọn một đỉnh có bậc khác không để tìm chu trình đơn rồi ghép nó vào đường đi hiện tại, cuối cùng thu được đường đi Euler.

### Cài đặt

Mã giả của thuật toán Hierholzer như sau:

$$
\begin{array}{ll}
1 &  \textbf{Dữ liệu vào. } \text{Các cạnh của đồ thị } e, \text{ trong đó mỗi phần tử của } e \text{ là } (u, v) \\
2 &  \textbf{Kết quả. } \text{Dãy đỉnh của đường đi Euler trong đồ thị đầu vào}.\\
3 &  \textbf{Phương pháp. } \\
4 &  \textbf{Hàm } \text{Hierholzer } (v) \\
5 &  \qquad circle \gets \text{Tìm một chu trình trong } e \text{ bắt đầu từ } v \\
6 &  \qquad \textbf{nếu } circle=\varnothing \\
7 &  \qquad\qquad \textbf{trả về } v \\
8 &  \qquad e \gets e-circle \\
9 &  \qquad \textbf{với mỗi } v \in circle \\
10&  \qquad\qquad v \gets \text{Hierholzer}(v) \\
11&  \qquad \textbf{trả về } circle \\
12&  \textbf{Kết thúc hàm}\\
13&  \textbf{trả về } \text{Hierholzer}(\text{một đỉnh bất kỳ})
\end{array}
$$

### Phân tích độ phức tạp thời gian

Độ phức tạp thời gian của thuật toán Hierholzer là $O(|E| + |V|)$.

Trong phân tích tính đúng đắn ở trên, quá trình tìm chu trình đơn trong đồ thị Euler hoặc nửa Euler (hoặc đường đi ban đầu của đồ thị nửa Euler) là **không cần quay lui**: chỉ cần đi theo các cạnh còn lại thì sẽ tìm được chu trình hoặc đường đi cần thiết, và **mỗi cạnh chỉ được thăm một lần**.
Để tận dụng tính chất này, khi cài đặt nên lưu các cạnh trong đồ thị bằng cấu trúc dạng danh sách liên kết, chẳng hạn danh sách kề hoặc sao tiến, để mỗi cạnh được xóa ngay sau khi được thăm. Nếu dùng ma trận kề đơn giản để lưu trữ, mỗi lần tìm cạnh sẽ tốn $O(|V|)$, tổng độ phức tạp là $O(|V||E|)$.

???+ note "Ghi chú"
    Chính xác hơn, độ phức tạp của thuật toán nên là $O(|E|)$ chứ không phải $O(|V| + |E|)$, vì cách cài đặt thuật toán có thể phụ thuộc vào cạnh thay vì phụ thuộc vào đỉnh, bằng cách duy trì danh sách liên kết tổng thể của các cạnh còn lại để tìm chu trình ở bước tiếp theo.

Nếu cần xuất đường đi Euler hoặc chu trình Euler có thứ tự từ điển nhỏ nhất, cần sắp xếp các cạnh; độ phức tạp thời gian là $\Theta(|E|\log |E|)$ hoặc $\Theta(|E|)$ (nếu dùng sắp xếp đếm hoặc sắp xếp cơ số).

### Ứng dụng

Đồ thị Euler có hướng có thể được dùng trong giải mã bằng máy tính.

Giả sử có $m$ chữ cái và cần xây dựng một đĩa tròn có $m^n$ ô hình quạt, trên mỗi ô đặt một chữ cái, sao cho mỗi $n$ vị trí liên tiếp trên đĩa tương ứng với một xâu ký hiệu độ dài $n$. Sau khi quay hết một vòng ($m^n$ lần), thu được $m^n$ xâu ký hiệu độ dài $n$ đôi một khác nhau được tạo từ $m$ chữ cái.

![](images/euler1.svg)

Xây dựng đồ thị Euler có hướng như sau:

Đặt $S = \{a_1, a_2, \cdots, a_m\}$, xây dựng $D=\langle V, E\rangle$ như sau:

$V = \{a_{i_1}a_{i_2}\cdots a_{i_{n-1}} |a_i \in S, 1 \leq i \leq n - 1 \}$

$E = \{a_{j_1}a_{j_2}\cdots a_{j_{n-1}}|a_j \in S, 1 \leq j \leq n\}$

Quy định quan hệ liên thuộc giữa đỉnh và cạnh trong $D$ như sau:

Từ đỉnh $a_{i_1}a_{i_2}\cdots a_{i_{n-1}}$ có $m$ cạnh đi ra: $a_{i_1}a_{i_2}\cdots a_{i_{n-1}}a_r, r=1, 2, \cdots, m$.

Cạnh $a_{j_1}a_{j_2}\cdots a_{j_{n-1}}$ đi vào đỉnh $a_{j_2}a_{j_3}\cdots a_{j_{n}}$.

![](images/euler2.svg)

Đồ thị $D$ như vậy là liên thông, và mỗi đỉnh có bậc vào bằng bậc ra (đều bằng $m$), nên $D$ là đồ thị Euler có hướng.

Tìm tùy ý một chu trình Euler $C$ trong $D$, lấy chữ cái cuối cùng của mỗi cạnh trong $C$, rồi đặt chúng theo thứ tự các cạnh trong $C$ thành một vòng tròn trên đĩa.

## Bài tập mẫu

???+ note "[Luogu P2731: Riding the Fences](https://www.luogu.com.cn/problem/P2731)"
    Cho một đồ thị vô hướng có 500 đỉnh. Cần tìm một đường đi Euler hoặc chu trình Euler của đồ thị đó. Nếu có nhiều lời giải, cần xuất lời giải nhỏ nhất.
    
    Trong bài này, đường đi Euler hoặc chu trình Euler không cần đi qua mọi đỉnh.
    
    Số cạnh $m$ thỏa $1\leq m \leq 1024$.

??? note "Ý tưởng"
    Bài này là một ứng dụng trực tiếp của thuật toán Hierholzer.
    
    Có thể dùng `std::stack<int>` để lưu đáp án, vì nếu phần tìm được không phải chu trình thì phải đặt phần đó ở cuối.
    
    Không nên dùng ma trận kề để lưu đồ thị, vì độ phức tạp thời gian sẽ suy biến thành $\Theta(nm)$. Do cần sắp xếp cạnh, nên dùng sao tiến hoặc `std::vector` để lưu đồ thị. Mã mẫu dùng `std::vector`.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/graph/code/euler/euler_1.cpp"
    ```

## Bài tập

-   [SGU 101 Domino](https://codeforces.com/problemsets/acmsguru/problem/99999/101)

-   [POJ 1780 Code](http://poj.org/problem?id=1780)

-   [Luogu P1127: Chuỗi từ](https://www.luogu.com.cn/problem/P1127)

-   [Luogu P1333: Que gỗ của Ruirui](https://www.luogu.com.cn/problem/P1333)

-   [Luogu P1341: Cặp chữ cái không thứ tự](https://www.luogu.com.cn/problem/P1341)

-   [Luogu P6066 \[USACO05JAN\] Watchcow S](https://www.luogu.com.cn/problem/P6066)

-   [Luogu P6628 \[Kỳ thi liên tỉnh 2020, đề B\] Con đường hoa đinh hương](https://www.luogu.com.cn/problem/P6628)

-   [Luogu P3520 \[POI 2011\] SMI-Garbage](https://www.luogu.com.cn/problem/P3520)
