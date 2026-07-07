author: LeverImmy, 383494

Trang này giới thiệu bài toán phủ chính xác, bài toán phủ lặp, thuật toán X dùng để giải hai bài toán đó, và danh sách liên kết chữ thập hai chiều Dancing Links dùng để tối ưu thuật toán X. Trang cũng trình bày cách phối hợp DLX với bước mô hình hóa để giải một số bài tìm kiếm.

<span id="bài-toán-phủ-chính-xác"></span>
## Bài toán phủ chính xác

<span id="định-nghĩa"></span>
### Định nghĩa

Bài toán phủ chính xác (tiếng Anh: Exact Cover Problem) là bài toán: cho nhiều tập hợp $S_i (1 \le i \le n)$ và một tập hợp $X$, tìm một bộ nhiều phần tử không xét thứ tự $(T_1, T_2, \cdots , T_m)$ thỏa mãn các điều kiện sau:

1.  $\forall i, j \in [1, m],T_i\bigcap T_j = \varnothing (i \neq j)$
2.  $X = \bigcup\limits_{i = 1}^{m}T_i$
3.  $\forall i \in[1, m], T_i \in \{S_1, S_2, \cdots, S_n\}$

<span id="giải-thích"></span>
### Giải thích

Ví dụ, nếu cho

$$
\begin{aligned}
  & S_1 = \{5, 9, 17\} \\
  & S_2 = \{1, 8, 119\} \\
  & S_3 = \{3, 5, 17\} \\
  & S_4 = \{1, 8\} \\
  & S_5 = \{3, 119\} \\
  & S_6 = \{8, 9, 119\} \\
  & X = \{1, 3, 5, 8, 9, 17, 119\}
\end{aligned}
$$

thì $(S_1, S_4, S_5)$ là một nghiệm hợp lệ.

<span id="chuyển-đổi-bài-toán"></span>
### Chuyển đổi bài toán

Rời rạc hóa tất cả các số trong $\bigcup\limits_{i = 1}^{n}S_i$, thu được mô hình sau:

> Cho một ma trận 0-1. Cần chọn một số hàng (row), sao cho cuối cùng mỗi cột (column)[^note1] đều có đúng một ô bằng 1.
> Chẳng hạn, mô hình hóa ví dụ phía trên sẽ cho ma trận sau:

$$
\begin{pmatrix}
0 & 0 & 1 & 0 & 1 & 1 & 0 \\
1 & 0 & 0 & 1 & 0 & 0 & 1 \\
0 & 1 & 1 & 0 & 0 & 1 & 0 \\
1 & 0 & 0 & 1 & 0 & 0 & 0 \\
0 & 1 & 0 & 0 & 0 & 0 & 1 \\
0 & 0 & 0 & 1 & 1 & 0 & 1
\end{pmatrix}
$$

> Trong đó, hàng thứ $i$ biểu diễn $S_i$, còn từng số trên hàng này lần lượt biểu diễn $[1 \in S_i],[3 \in S_i],[5 \in S_i],\cdots,[119 \in S_i]$.

<span id="cài-đặt"></span>
### Cài đặt

<span id="vét-cạn-1"></span>
#### Vét cạn 1

Một cách làm là liệt kê những hàng được chọn, rồi kiểm tra phương án đó có hợp lệ hay không.

Vì mỗi hàng có hai trạng thái chọn hoặc không chọn, độ phức tạp thời gian để liệt kê các hàng là $O(2^n)$;

mỗi lần kiểm tra cần $O(nm)$ thời gian. Vì vậy độ phức tạp tổng cộng là $O(nm\cdot2^n)$.

??? note "Cài đặt"
    ```cpp
    int ok = 0;
    for (int state = 0; state < 1 << n; ++state) {  // Liệt kê xem từng hàng có được chọn không
      for (int i = 1; i <= n; ++i)
        if ((1 << i - 1) & state)
          for (int j = 1; j <= m; ++j) a[i][j] = 1;
      int flag = 1;
      for (int j = 1; j <= m; ++j)
        for (int i = 1, bo = 0; i <= n; ++i)
          if (a[i][j]) {
            if (bo)
              flag = 0;
            else
              bo = 1;
          }
      if (!flag)
        continue;
      else {
        ok = 1;
        for (int i = 1; i <= n; ++i)
          if ((1 << i - 1) & state) printf("%d ", i);
        puts("");
      }
      memset(a, 0, sizeof(a));
    }
    if (!ok) puts("No solution.");
    ```

<span id="vét-cạn-2"></span>
#### Vét cạn 2

Xét tính chất đặc biệt của ma trận 0-1, có thể xem mỗi hàng như một số nhị phân $m$ bit.

Do đó, bài toán ban đầu được chuyển thành:

> Cho $n$ số nhị phân $m$ bit. Cần chọn một vài số sao cho phép AND của hai số bất kỳ đều bằng 0, và phép OR của tất cả các số được chọn bằng $2^m - 1$. `tmp` biểu diễn giá trị OR của các số nhị phân đã được chọn cho tới thời điểm hiện tại.

Vì mỗi hàng có hai trạng thái chọn hoặc không chọn, độ phức tạp thời gian để liệt kê các hàng là $O(2^n)$;

mỗi lần tính `tmp` cần $O(n)$ thời gian. Vì vậy độ phức tạp tổng cộng là $O(n\cdot2^n)$.

??? note "Cài đặt"
    ```cpp
    int ok = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = m; j >= 1; --j) num[i] = num[i] << 1 | a[i][j];
    for (int state = 0; state < 1 << n; ++state) {
      int tmp = 0;
      bool flag = true;
      for (int i = 1; i <= n; ++i)
        if ((1 << i - 1) & state) {
          if (tmp & num[i]) {
            flag = false;
            break;
          }
          tmp |= num[i];
        }
      if (flag && tmp == (1 << m) - 1) {
        ok = 1;
        for (int i = 1; i <= n; ++i)
          if ((1 << i - 1) & state) printf("%d ", i);
        puts("");
      }
    }
    if (!ok) puts("No solution.");
    ```

<span id="bài-toán-phủ-lặp"></span>
## Bài toán phủ lặp

Bài toán phủ lặp tương tự bài toán phủ chính xác, nhưng không hạn chế việc một phần tử được phủ nhiều lần. [Thuật toán X](#thuật-toán-x) được trình bày bên dưới vốn dành cho bài toán phủ chính xác, nhưng sau một vài chỉnh sửa và tối ưu (đã được ghi chú trong phần tương ứng), nó cũng có thể giải hiệu quả bài toán phủ lặp.

<span id="thuật-toán-x"></span>
## Thuật toán X

Donald E. Knuth đề xuất thuật toán X. Ý tưởng của nó khá giống cách vét cạn phía trên, nhưng thuận tiện hơn cho việc tối ưu.

<span id="quy-trình"></span>
### Quy trình

Tiếp tục dùng ví dụ ở trên, có ma trận 0-1 sau:

$$
\begin{pmatrix}
  0 & 0 & 1 & 0 & 1 & 1 & 0 \\
  1 & 0 & 0 & 1 & 0 & 0 & 1 \\
  0 & 1 & 1 & 0 & 0 & 1 & 0 \\
  1 & 0 & 0 & 1 & 0 & 0 & 0 \\
  0 & 1 & 0 & 0 & 0 & 0 & 1 \\
  0 & 0 & 0 & 1 & 1 & 0 & 1
\end{pmatrix}
$$

1.  Lúc này hàng thứ nhất có $3$ số $1$, hàng thứ hai có $3$ số $1$, hàng thứ ba có $3$ số $1$, hàng thứ tư có $2$ số $1$, hàng thứ năm có $2$ số $1$, hàng thứ sáu có $3$ số $1$. Chọn hàng thứ nhất, xóa nó, rồi đánh dấu tất cả các cột chứa số $1$ trên hàng đó;

    $$
    \begin{pmatrix}
      \color{Blue}0 & \color{Blue}0 & \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}1 & \color{Blue}0 \\
      1 & 0 & \color{Red}0 & 1 & \color{Red}0 & \color{Red}0 & 1 \\
      0 & 1 & \color{Red}1 & 0 & \color{Red}0 & \color{Red}1 & 0 \\
      1 & 0 & \color{Red}0 & 1 & \color{Red}0 & \color{Red}0 & 0 \\
      0 & 1 & \color{Red}0 & 0 & \color{Red}0 & \color{Red}0 & 1 \\
      0 & 0 & \color{Red}0 & 1 & \color{Red}1 & \color{Red}0 & 1
      \end{pmatrix}
    $$

2.  Chọn tất cả các cột đã được đánh dấu, xóa chúng, rồi đánh dấu các hàng có số $1$ trong những cột đó (với bài toán phủ lặp thì không cần đánh dấu);

    $$
    \begin{pmatrix}
      \color{Blue}0 & \color{Blue}0 & \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}1 & \color{Blue}0 \\
      1 & 0 & \color{Blue}0 & 1 & \color{Blue}0 & \color{Blue}0 & 1 \\
      \color{Red}0 & \color{Red}1 & \color{Blue}1 & \color{Red}0 & \color{Blue}0 & \color{Blue}1 & \color{Red}0 \\
      1 & 0 & \color{Blue}0 & 1 & \color{Blue}0 & \color{Blue}0 & 0 \\
      0 & 1 & \color{Blue}0 & 0 & \color{Blue}0 & \color{Blue}0 & 1 \\
      \color{Red}0 & \color{Red}0 & \color{Blue}0 & \color{Red}1 & \color{Blue}1 & \color{Blue}0 & \color{Red}1
    \end{pmatrix}
    $$

3.  Chọn tất cả các hàng đã được đánh dấu và xóa chúng;

    $$
    \begin{pmatrix}
      \color{Blue}0 & \color{Blue}0 & \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}1 & \color{Blue}0 \\
      1 & 0 & \color{Blue}0 & 1 & \color{Blue}0 & \color{Blue}0 & 1 \\
      \color{Blue}0 & \color{Blue}1 & \color{Blue}1 & \color{Blue}0 & \color{Blue}0 & \color{Blue}1 & \color{Blue}0 \\
      1 & 0 & \color{Blue}0 & 1 & \color{Blue}0 & \color{Blue}0 & 0 \\
      0 & 1 & \color{Blue}0 & 0 & \color{Blue}0 & \color{Blue}0 & 1 \\
      \color{Blue}0 & \color{Blue}0 & \color{Blue}0 & \color{Blue}1 & \color{Blue}1 & \color{Blue}0 & \color{Blue}1
    \end{pmatrix}
    $$

    **Điều này biểu thị rằng hàng này đã được chọn, và tất cả các cột chứa số $1$ trên hàng đó không được phép có số $1$ nào khác**.

    Khi đó thu được một ma trận 0-1 nhỏ hơn:

    $$
    \begin{pmatrix}
      1 & 0 & 1 & 1 \\
      1 & 0 & 1 & 0 \\
      0 & 1 & 0 & 1
    \end{pmatrix}
    $$

4.  Lúc này hàng thứ nhất (hàng thứ hai ban đầu) có $3$ số $1$, hàng thứ hai (hàng thứ tư ban đầu) có $2$ số $1$, hàng thứ ba (hàng thứ năm ban đầu) có $2$ số $1$. Chọn hàng thứ nhất (hàng thứ hai ban đầu), xóa nó, rồi đánh dấu tất cả các cột chứa số $1$ trên hàng đó;

    $$
    \begin{pmatrix}
      \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}1 \\
      \color{Red}1 & 0 & \color{Red}1 & \color{Red}0 \\
      \color{Red}0 & 1 & \color{Red}0 & \color{Red}1
    \end{pmatrix}
    $$

5.  Chọn tất cả các cột đã được đánh dấu, xóa chúng, rồi đánh dấu các hàng có số $1$ trong những cột đó;

    $$
    \begin{pmatrix}
      \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}1 \\
      \color{Blue}1 & \color{Red}0 & \color{Blue}1 & \color{Blue}0 \\
      \color{Blue}0 & \color{Red}1 & \color{Blue}0 & \color{Blue}1
    \end{pmatrix}
    $$

6.  Chọn tất cả các hàng đã được đánh dấu và xóa chúng;

    $$
    \begin{pmatrix}
      \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}1 \\
      \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}0 \\
      \color{Blue}0 & \color{Blue}1 & \color{Blue}0 & \color{Blue}1
    \end{pmatrix}
    $$

    Như vậy thu được một ma trận rỗng. Tuy nhiên, hàng vừa bị xóa ở lần trước là `1 0 1 1`, không phải hàng toàn $1$, nên lựa chọn này sai;

    $$
    \begin{pmatrix}
    \end{pmatrix}
    $$

7.  Quay lui về bước 4, xét việc chọn hàng thứ hai (hàng thứ tư ban đầu), xóa nó, rồi đánh dấu tất cả các cột chứa số $1$ trên hàng đó;

    $$
    \begin{pmatrix}
      \color{Red}1 & 0 & \color{Red}1 & 1 \\
      \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}0 \\
      \color{Red}0 & 1 & \color{Red}0 & 1
    \end{pmatrix}
    $$

8.  Chọn tất cả các cột đã được đánh dấu, xóa chúng, rồi đánh dấu các hàng có số $1$ trong những cột đó;

    $$
    \begin{pmatrix}
      \color{Blue}1 & \color{Red}0 & \color{Blue}1 & \color{Red}1 \\
      \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}0 \\
      \color{Blue}0 & 1 & \color{Blue}0 & 1
    \end{pmatrix}
    $$

9.  Chọn tất cả các hàng đã được đánh dấu và xóa chúng;

    $$
    \begin{pmatrix}
      \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}1 \\
      \color{Blue}1 & \color{Blue}0 & \color{Blue}1 & \color{Blue}0 \\
      \color{Blue}0 & 1 & \color{Blue}0 & 1
      \end{pmatrix}
    $$

    Khi đó thu được ma trận sau:

    $$
    \begin{pmatrix}
      1 & 1
    \end{pmatrix}
    $$

10. Lúc này hàng thứ nhất (hàng thứ năm ban đầu) có $2$ số $1$. Xóa toàn bộ chúng để thu được một ma trận rỗng:

    $$
    \begin{pmatrix}
    \end{pmatrix}
    $$

11. Ở lần xóa trước đó, hàng bị xóa là hàng toàn $1$, nên thuật toán thành công và kết thúc.

    Đáp án chính là ba hàng đã bị xóa: $1, 4, 5$.

Việc tự mô phỏng một lần quá trình xóa ma trận, khôi phục và quay lui sẽ giúp phần dưới dễ theo dõi hơn.

Từ các bước trên, có thể tóm tắt quy trình của thuật toán X như sau:

1.  Với ma trận hiện tại $M$, chọn và đánh dấu một hàng $r$, rồi thêm $r$ vào $S$;
2.  Nếu đã thử tất cả các $r$ mà vẫn không có nghiệm, thuật toán kết thúc và xuất ra không có nghiệm;
3.  Đánh dấu các hàng $r_i$ và các cột $c_i$ liên quan đến $r$ (hàng và cột liên quan được định nghĩa giống bước 2 trong phần [thuật toán X](#quy-trình); bên dưới cũng dùng cùng nghĩa này);
4.  Xóa tất cả các hàng và cột đã đánh dấu, thu được ma trận mới $M'$;
5.  Nếu $M'$ rỗng và $r$ là hàng toàn $1$, thuật toán kết thúc, xuất ra tập $S$ gồm các hàng đã bị xóa;

    Nếu $M'$ rỗng nhưng $r$ không phải hàng toàn $1$, khôi phục các hàng $r_i$ và các cột $c_i$ liên quan đến $r$, rồi nhảy về bước 1;

    Nếu $M'$ không rỗng, nhảy về bước 1.

Thuật toán X cần rất nhiều thao tác "xóa hàng", "xóa cột", "khôi phục hàng" và "khôi phục cột".

Một ý tưởng đơn giản là dùng mảng hai chiều để lưu ma trận, rồi dùng bốn mảng để lưu chỉ số các hàng lân cận của mỗi hàng; khi xóa và khôi phục chỉ cần cập nhật các phần tử trong bốn mảng đó. Tuy nhiên, trong ma trận của các bài toán thông thường, số lượng ô 0 thường nhiều hơn rất nhiều so với số lượng ô 1, nên độ phức tạp bộ nhớ của cách làm này khó chấp nhận.

Donald E. Knuth nghĩ đến việc dùng danh sách liên kết chữ thập hai chiều để duy trì các thao tác này.

Quá trình liên tục nhảy qua lại trên danh sách liên kết chữ thập hai chiều được ví như một điệu nhảy, vì vậy cấu trúc danh sách liên kết chữ thập hai chiều dùng để tối ưu thuật toán X còn được gọi là "Dancing Links".

<span id="thuật-toán-x-tối-ưu-bằng-dancing-links"></span>
## Thuật toán X tối ưu bằng Dancing Links

<span id="lệnh-tiền-xử-lý"></span>
### Lệnh tiền xử lý

```cpp
#define IT(i, A, x) for (i = A[x]; i != x; i = A[i])
```

### Định nghĩa

Trong danh sách liên kết chữ thập hai chiều có bốn miền con trỏ, lần lượt trỏ tới phần tử phía trên, phía dưới, bên trái và bên phải. Mỗi phần tử $i$ trong toàn bộ hệ danh sách liên kết chữ thập hai chiều đều tương ứng với một ô, nên còn cần biểu diễn cột và hàng chứa $i$, như hình sau:

![Các con trỏ của một nút trong Dancing Links](./images/dlx-1.svg)

Một danh sách liên kết hai chiều cỡ lớn sẽ phức tạp hơn:

![Danh sách liên kết chữ thập hai chiều trong Dancing Links](./images/dlx-2.svg)

Mỗi hàng có một chỉ thị đầu hàng, mỗi cột có một chỉ thị cột.

Chỉ thị đầu hàng là `first[]`; chỉ thị cột là $c + 1$ nút lính canh được tạo mới. Cần lưu ý rằng **chỉ thị đầu hàng không phải là nút lính canh trong danh sách liên kết**. Nó là phần tử ảo, tương tự mảng `first[]` trong danh sách kề, và **trỏ trực tiếp** tới phần tử đầu tiên của hàng đó.

Đồng thời, mỗi cột có một `siz[]` biểu diễn số phần tử trong cột đó.

Đặc biệt, nút số $0$ không có nút bên phải tương đương với việc Dancing Links này rỗng.

```cpp
constexpr int MS = 1e5 + 5;
int n, m, idx, first[MS], siz[MS];
int L[MS], R[MS], U[MS], D[MS];
int col[MS], row[MS];
```

### Quy trình

<span id="thao-tác-remove"></span>
#### Thao tác remove

`remove(c)` biểu diễn việc xóa cột thứ $c$ và các hàng, cột liên quan đến nó trong Dancing Links.

Trước hết xóa $c$. Khi đó:

-   Nút bên trái của $c$ phải có nút bên phải là nút bên phải của $c$.
-   Nút bên phải của $c$ phải có nút bên trái là nút bên trái của $c$.

Tức là `L[R[c]] = L[c], R[L[c]] = R[c];`.

![Xóa chỉ thị cột trong thao tác remove](./images/dlx-3.svg)

Sau đó đi xuống dọc theo cột này, xóa từng hàng đi qua.

Để xóa từng hàng, liệt kê con trỏ $j$ trên hàng hiện tại. Khi đó:

-   Nút phía trên của $j$ phải có nút phía dưới là nút phía dưới của $j$.
-   Nút phía dưới của $j$ phải có nút phía trên là nút phía trên của $j$.

Lưu ý phải cập nhật số phần tử của từng cột.

Tức là `U[D[j]] = U[j], D[U[j]] = D[j], --siz[col[j]];`.

![Xóa các nút trên hàng liên quan trong thao tác remove](./images/dlx-4.svg)

Mã cài đặt hàm `remove` như sau:

???+ note "Cài đặt"
    ```cpp
    void remove(const int &c) {
      int i, j;
      L[R[c]] = L[c], R[L[c]] = R[c];
      // Duyệt từ trên xuống dưới theo cột này
      IT(i, D, c)
      // Duyệt từ trái sang phải theo hàng này
      IT(j, R, i)
      U[D[j]] = U[j], D[U[j]] = D[j], --siz[col[j]];
    }
    ```

<span id="thao-tác-recover"></span>
#### Thao tác recover

`recover(c)` biểu diễn việc khôi phục cột thứ $c$ và các hàng, cột liên quan đến nó trong Dancing Links.

`recover(c)` chính là thao tác ngược của `remove(c)`, nên phần này không nhắc lại chi tiết.

**Cần lưu ý rằng** mọi thao tác trong `recover(c)` **có thứ tự đúng ngược lại với** các thao tác trong `remove(c)`.

Mã cài đặt `recover(c)` như sau:

???+ note "Cài đặt"
    ```cpp
    void recover(const int &c) {
      int i, j;
      IT(i, U, c) IT(j, L, i) U[D[j]] = D[U[j]] = j, ++siz[col[j]];
      L[R[c]] = R[L[c]] = c;
    }
    ```

<span id="thao-tác-build"></span>
#### Thao tác xây dựng

`build(r, c)` biểu diễn việc tạo mới một Dancing Links kích thước $r \times c$, tức có $r$ hàng và $c$ cột.

Tạo mới $c + 1$ nút làm chỉ thị cột.

Nút thứ $i$ có nút bên trái là $i - 1$, nút bên phải là $i + 1$, nút phía trên là $i$, nút phía dưới là $i$. Đặc biệt, nút $0$ có nút bên trái là $c$, còn nút $c$ có nút bên phải là $0$.

Như vậy thu được một danh sách liên kết hai chiều dạng vòng:

![Danh sách vòng của các chỉ thị cột sau khi xây dựng](./images/dlx-5.svg)

Vậy là đã khởi tạo xong một Dancing Links.

Mã cài đặt `build(r, c)` như sau:

???+ note "Cài đặt"
    ```cpp
    void build(const int &r, const int &c) {
      n = r, m = c;
      for (int i = 0; i <= c; ++i) {
        L[i] = i - 1, R[i] = i + 1;
        U[i] = D[i] = i;
      }
      L[0] = c, R[c] = 0, idx = c;
      memset(first, 0, sizeof(first));
      memset(siz, 0, sizeof(siz));
    }
    ```

<span id="thao-tác-insert"></span>
#### Thao tác insert

`insert(r, c)` biểu diễn việc chèn một nút vào hàng thứ $r$, cột thứ $c$.

Thao tác chèn được chia thành hai trường hợp:

-   Nếu hàng thứ $r$ chưa có phần tử nào, trực tiếp chèn một phần tử và cho `first[r]` trỏ tới phần tử đó.

    Có thể thực hiện điều này bằng `first[r] = L[idx] = R[idx] = idx;`.

-   Nếu hàng thứ $r$ đã có phần tử, nối phần tử mới này với $c$ và `first(r)` theo một cách đặc biệt.

    Giả sử phần tử mới này là $idx$, sau đó:

    -   Chèn $idx$ ngay bên dưới $c$. Khi đó:

        -   Nút phía dưới của $idx$ là nút phía dưới ban đầu của $c$;
        -   Nút phía trên của nút phía dưới $idx$ (tức nút phía dưới ban đầu của $c$) là $idx$;
        -   Nút phía trên của $idx$ là $c$;
        -   Nút phía dưới của $c$ là $idx$.

        Lưu ý ghi lại cột và hàng chứa $idx$, đồng thời cập nhật số phần tử của cột này.

        ```cpp
        col[++idx] = c, row[idx] = r, ++siz[c];
        U[idx] = c, D[idx] = D[c], U[D[c]] = idx, D[c] = idx;
        ```

        Cần nắm chắc thứ tự của các bước này trước khi xét phần tiếp theo.

    -   Chèn $idx$ ngay bên phải `first(r)`. Khi đó:

        -   Nút bên phải của $idx$ là nút bên phải ban đầu của `first(r)`;
        -   Nút bên trái của nút bên phải ban đầu của `first(r)` là $idx$;
        -   Nút bên trái của $idx$ là `first(r)`;
        -   Nút bên phải của `first(r)` là $idx$.

        ```cpp
        L[idx] = first[r], R[idx] = R[first[r]];
        L[R[first[r]]] = idx, R[first[r]] = idx;
        ```

        Cần nắm chắc thứ tự của các bước này trước khi xét phần tiếp theo.

Có thể dùng hình sau để hỗ trợ hiểu thao tác `insert(r, c)`:

![Chèn một nút vào hàng và cột trong Dancing Links](./images/dlx-6.svg)

Lưu ý hướng của các mũi tên cong.

Mã cài đặt `insert(r, c)` như sau:

???+ note "Cài đặt"
    ```cpp
    void insert(const int &r, const int &c) {
      row[++idx] = r, col[idx] = c, ++siz[c];
      U[idx] = c, D[idx] = D[c], U[D[c]] = idx, D[c] = idx;
      if (!first[r])
        first[r] = L[idx] = R[idx] = idx;
      else {
        L[idx] = first[r], R[idx] = R[first[r]];
        L[R[first[r]]] = idx, R[first[r]] = idx;
      }
    }
    ```

<span id="thao-tác-dance"></span>
#### Thao tác dance

`dance()` chính là quá trình đệ quy xóa và khôi phục các hàng, cột.

1.  Nếu nút số $0$ không có nút bên phải, ma trận rỗng; ghi nhận đáp án rồi trả về;
2.  Chọn cột có số phần tử ít nhất, rồi xóa cột đó;
3.  Duyệt tất cả các hàng có số $1$ trong cột này, liệt kê xem hàng đó có được chọn hay không;
4.  Gọi đệ quy `dance()`; nếu khả thi thì trả về, nếu không khả thi thì khôi phục hàng đã chọn;
5.  Nếu vô nghiệm thì trả về.

Mã cài đặt `dance()` như sau:

???+ note "Cài đặt"
    ```cpp
    bool dance(int dep) {
      int i, j, c = R[0];
      if (!R[0]) {
        ans = dep;
        return true;
      }
      IT(i, R, 0) if (siz[i] < siz[c]) c = i;
      remove(c);
      IT(i, D, c) {
        stk[dep] = row[i];
        IT(j, R, i) remove(col[j]);
        if (dance(dep + 1)) return true;
        IT(j, L, i) recover(col[j]);
      }
      recover(c);
      return false;
    }
    ```

Trong đó `stk[]` dùng để ghi đáp án.

Lưu ý rằng mỗi lần chương trình ưu tiên chọn cột có số phần tử ít nhất để xóa. Như vậy chương trình có một mức độ theo kinh nghiệm nhất định, làm số nhánh của cây tìm kiếm nhỏ nhất.

Với bài toán phủ lặp, khi tìm kiếm có thể dùng hàm đánh giá (tương tự trong [A\*](astar.md)) để cắt tỉa: nếu trong trường hợp tốt nhất hiện tại, số hàng đã chọn vẫn vượt quá nghiệm tối ưu hiện có, có thể trả về ngay.

<span id="mẫu"></span>
## Mẫu

??? note "[Mã mẫu](https://www.luogu.com.cn/problem/P4929)"
    ```cpp
    --8<-- "docs/search/code/dlx/dlx_1.cpp"
    ```

<span id="tính-chất"></span>
## Tính chất

Số lần đệ quy và quay lui của DLX liên quan đến số lượng ô $1$ trong ma trận, không liên quan đến các tham số như $r, c$ của ma trận. Vì vậy, độ phức tạp thời gian của nó là **cấp số mũ**; độ phức tạp lý thuyết xấp xỉ $O(c^n)$, trong đó $c$ là một hằng số rất gần $1$, còn $n$ là số lượng ô $1$ trong ma trận.

Tuy nhiên trong thực tế, DLX hoạt động tốt và thường giải được phần lớn các bài toán.

<span id="mô-hình-hóa"></span>
## Mô hình hóa

Khó khăn của DLX không hoàn toàn nằm ở việc xây dựng danh sách liên kết, mà nằm ở bước mô hình hóa.

Phần dưới giả định rằng mẫu DLX đã được nắm vững.

Khi gặp một bài toán, nên xét ý nghĩa mà hàng và cột biểu diễn:

-   Hàng biểu diễn *quyết định*, vì mỗi hàng tương ứng với một tập hợp, tức tương ứng với việc chọn hoặc không chọn;

-   Cột biểu diễn *trạng thái*, vì cột thứ $i$ tương ứng với một điều kiện $P_i$.

Đối với một hàng, do giá trị ở các cột khác nhau không giống nhau, cần **định nghĩa một quyết định thông qua các trạng thái khác nhau**.

<span id="ví-dụ-1-p1784-sudoku"></span>
### Ví dụ 1 [P1784 Sudoku](https://www.luogu.com.cn/problem/P1784)

??? note "Ý tưởng giải"
    Trước hết xét quyết định là gì.
    
    Trong bài này, có thể biểu diễn mỗi quyết định bằng bộ ba có thứ tự dạng $(r, c, w)$.
    
    Lưu ý rằng "khối" không phải là tham số của quyết định, vì **mỗi cặp $(r, c)$ cụ thể đều xác định được nó**.
    
    Vì vậy có $9 \times 9 \times 9 = 729$ hàng.
    
    Tiếp theo xét trạng thái là gì.
    
    Xét ảnh hưởng của quyết định $(r, c, w)$. Gọi $b$ là khối chứa ô $(r, c)$.
    
    1.  Hàng thứ $r$ đã dùng một số $w$ (biểu diễn bằng $9 \times 9 = 81$ cột);
    2.  Cột thứ $c$ đã dùng một số $w$ (biểu diễn bằng $9 \times 9 = 81$ cột);
    3.  Khối thứ $b$ đã dùng một số $w$ (biểu diễn bằng $9 \times 9 = 81$ cột);
    4.  Một số đã được điền vào ô $(r, c)$ (biểu diễn bằng $9 \times 9 = 81$ cột).
    
    Vì vậy có $81 \times 4 = 324$ cột, tổng cộng $729 \times 4 = 2916$ ô $1$.
    
    Đến đây, bài toán Sudoku $9 \times 9$ đã được chuyển thành một bài toán phủ chính xác **có $729$ hàng, $324$ cột, tổng cộng $2916$ ô $1$**.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/search/code/dlx/dlx_2.cpp"
    ```

<span id="ví-dụ-2-sudoku-có-trọng-số-theo-hình-bia"></span>
### Ví dụ 2 [Sudoku có trọng số theo hình bia](https://www.luogu.com.cn/problem/P1074)

??? note "Ý tưởng giải"
    Mô hình của bài này **hoàn toàn giống** với [Sudoku](https://www.luogu.com.cn/problem/P1784); khác biệt chính nằm ở cách cập nhật đáp án.
    
    Bài này có thể dùng một mảng trọng số. Mỗi khi tìm được một nghiệm Sudoku,
    
    chỉ cần nhân số ở từng vị trí với trọng số tương ứng rồi cộng vào đáp án.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/search/code/dlx/dlx_3.cpp"
    ```

<span id="ví-dụ-3-noi2005-trò-chơi-smart-beads"></span>
### Ví dụ 3 ["NOI2005" Trò chơi Smart Beads](https://www.luogu.com.cn/problem/P4205)

??? note "Ý tưởng giải"
    Định nghĩa: hình dạng Smart Bead mà đề bài cho được gọi là *hình dạng chuẩn* của Smart Bead đó.
    
    Có thể thay đổi hình dạng của Smart Bead bằng cách thay đổi hai tham số $d$ (biểu thị số lần xoay thuận chiều kim đồng hồ $90^{\circ}$) và $f$ (có lật ngang hay không).
    
    Vẫn như trước, xét quyết định là gì.
    
    Trong bài này, có thể biểu diễn mỗi quyết định bằng bộ năm có thứ tự dạng $(v, d, f, i)$.
    
    Nó biểu thị vị trí góc trên bên trái của *hình dạng chuẩn* của Smart Bead thứ $i$, có số thứ tự là $v$, sau khi đã xoay thuận chiều kim đồng hồ $90^{\circ}$ tổng cộng $d$ lần.
    
    Có thể quy ước $f = 1$ nghĩa là không lật ngang, $f = -1$ nghĩa là lật ngang, từ đó đơn giản hóa mã.
    
    Vì vậy có $55 \times 4 \times 2 \times 12 = 5280$ hàng.
    
    Cần lưu ý rằng do có một số cách đặt không hợp lệ, chẳng hạn $(1, 0, 1, 4)$,
    
    nên **trong cài đặt thực tế, bàn Smart Beads rỗng cũng chỉ cần xây dựng $2730$ hàng**.
    
    Tiếp theo xét trạng thái là gì.
    
    Trạng thái của bài này tương đối đơn giản.
    
    Xét ảnh hưởng của quyết định $(v, d, f, i)$.
    
    1.  Một số ô bị chiếm (biểu diễn bằng $55$ cột);
    2.  Smart Bead thứ $i$ đã được dùng (biểu diễn bằng $12$ cột).
    
    Vì vậy có $55 + 12 = 67$ cột, tổng cộng $5280 \times (5 + 1) = 31680$ ô $1$.
    
    Đến đây, trò chơi Smart Beads đã được chuyển thành một bài toán phủ chính xác **có $5280$ hàng, $67$ cột, tổng cộng $31680$ ô $1$**.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/search/code/dlx/dlx_4.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

-   [SUDOKU - Sudoku](https://www.spoj.com/problems/SUDOKU/)
-   [Chuyên đề 3 Dancing Links trong chuỗi "kuangbin đưa bạn bay"](https://vjudge.net/contest/65998#overview)

<span id="liên-kết-ngoài"></span>
## Liên kết ngoài

-   [Dancing Links và bài toán phủ chính xác](https://www.cnblogs.com/grenet/p/3145800.html)
-   [Tìm kiếm: thuật toán DLX](https://www.cnblogs.com/aininot260/p/9629926.html)
-   [Huấn luyện thi lập trình: sách hướng dẫn luyện tập](https://book.douban.com/subject/35431537/)

<span id="chú-thích"></span>
## Chú thích

[^note1]: Ghi chú thuật ngữ giữa các vùng dùng tiếng Trung: Đài Loan dùng "vertical line" cho column và "horizontal row" cho row.
