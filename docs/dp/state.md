## Giới thiệu

DP nén trạng thái là một dạng quy hoạch động trong đó ta chuyển tập trạng thái thành số nguyên và lưu trực tiếp trong trạng thái DP để thực hiện chuyển trạng thái.

Để đạt độ phức tạp thời gian thấp hơn, thường cần tìm cách biểu diễn với số trạng thái ít hơn. Phần lớn bài toán tận dụng trạng thái nhị phân, dùng một số nhị phân $n$ bit để biểu diễn $n$ trạng thái nhị phân độc lập.

Nén trạng thái thường liên quan tới thao tác bit; xem thêm các thao tác bit cơ bản ở trang [thao tác bit](../math/bit.md).

## Ví dụ 1

???+ note "[「SCOI2005」Không xâm phạm nhau](https://loj.ac/problem/2153)"
    Đặt $K$ quân vua trên bàn cờ $N\times N$ ($1 \leq N \leq 9, 1 \leq K \leq N \times N$) sao cho chúng không tấn công nhau. Hỏi có bao nhiêu cách đặt.
    
    Một quân vua có thể tấn công một ô kề nó theo tám hướng: trên, dưới, trái, phải, trái trên, trái dưới, phải trên, phải dưới.

### Giải thích

Đặt $f(i,j,l)$ là số phương án hợp lệ khi xét $i$ hàng đầu, trạng thái hàng thứ $i$ là $j$, và đã đặt $l$ quân vua trên bàn cờ.

Với trạng thái có số hiệu $j$, dùng số nhị phân $sit(j)$ để biểu diễn cách đặt vua. Một bit bằng $0$ nghĩa là vị trí tương ứng không đặt vua, còn bit bằng $1$ nghĩa là đặt vua tại vị trí đó. Gọi $sta(j)$ là số quân vua trong trạng thái này, tức là số bit $1$ trong $sit(j)$. Ví dụ, trạng thái trong hình dưới có thể biểu diễn bằng số nhị phân $100101$ (phía trái bàn cờ ứng với bit thấp), nên $sit(j)=100101_{(2)}=37, sta(j)=3$.

![](./images/SCOI2005-%E4%BA%92%E4%B8%8D%E4%BE%B5%E7%8A%AF.png)

Giả sử trạng thái hàng hiện tại là $j$, trạng thái hàng trước là $x$, ta có phương trình chuyển: $f(i,j,l) = \sum f(i-1,x,l-sta(j))$.

Với số hiệu trạng thái hàng trước là $x$, trong điều kiện hàng hiện tại và hàng trước không xung đột, ta duyệt mọi $x$ có thể để chuyển trạng thái:

$$
f(i,j,l) = \sum f(i-1,x,l-sta(j))
$$

### Cài đặt

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/state/state_1.cpp"
    ```

## Ví dụ 2

???+ note "[\[POI2004\] PRZ](https://www.luogu.com.cn/problem/P5911)"
    Có $n$ người cần qua cầu. Người thứ $i$ có cân nặng $w_i$ và thời gian qua cầu là $t_i$. Khi qua cầu, họ được chia thành nhiều nhóm; chỉ khi toàn bộ người trong một nhóm đã qua cầu thì nhóm tiếp theo mới được qua. Tải trọng tối đa của cầu là $W$. Hỏi thời gian ngắn nhất để tất cả mọi người qua cầu.
    
    $100\le W \le 400$，$1\le n\le 16$，$1\le t_i\le 50$，$10\le w_i\le 100$.

### Giải thích

Dùng $S$ để biểu diễn một tập con của tập tất cả mọi người. Đặt $t(S)$ là thời gian qua cầu lớn nhất trong $S$, $w(S)$ là tổng cân nặng của mọi người trong $S$, và $f(S)$ là thời gian ngắn nhất để tất cả người trong $S$ qua cầu. Khi đó:

$$
\begin{cases}
    f(\varnothing)=0,\\
    f(S)=\min\limits_{T\subseteq S;~w(T)\leq W}\left\{t(T)+f(S\setminus T)\right\}.
\end{cases}
$$

Cần chú ý rằng không nên duyệt trực tiếp các tập rồi kiểm tra có phải tập con hay không. Thay vào đó, hãy dùng [duyệt tập con](../math/binary-set.md#%E9%81%8D%E5%8E%86%E6%89%80%E6%9C%89%E6%8E%A9%E7%A0%81%E7%9A%84%E5%AD%90%E6%8E%A9%E7%A0%81), nhờ đó độ phức tạp thời gian là $O(3^n)$.

### Cài đặt

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/state/state_2.cpp"
    ```

## Bài tập

-   [「NOI2001」Trận địa pháo binh](https://loj.ac/problem/10173)
-   [「USACO06NOV」Corn Fields](https://www.luogu.com.cn/problem/P1879)
-   [「Kỳ thi liên tỉnh 2018」Một cặp quân cờ gỗ](https://loj.ac/problem/2471)
