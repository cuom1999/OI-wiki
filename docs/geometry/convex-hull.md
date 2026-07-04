## Bao lồi hai chiều

### Định nghĩa

#### Đa giác lồi

Đa giác lồi là **đa giác đơn** mà mọi góc trong đều nằm trong khoảng $[0,\pi]$.

#### Bao lồi

Trên mặt phẳng, đa giác lồi nhỏ nhất có thể chứa tất cả các điểm đã cho được gọi là bao lồi.

Định nghĩa chính xác hơn: với tập hợp $X$ cho trước, giao của tất cả các tập lồi chứa $X$ được gọi là **bao lồi** của $X$.

Có thể hình dung bao lồi như hình dạng của một sợi dây cao su bao quanh tất cả các điểm đã cho.

Bao lồi bao quanh toàn bộ các điểm đã cho với chu vi nhỏ nhất. Nếu một đa giác lõm bao quanh tất cả các điểm, chu vi của nó chắc chắn không nhỏ nhất, như hình dưới đây. Theo bất đẳng thức tam giác, đa giác lồi chắc chắn là tối ưu về chu vi.

![](./images/ch.png)

### Thuật toán Andrew để tìm bao lồi

Các cách thường dùng để tìm bao lồi gồm Graham scan và thuật toán Andrew; ở đây chủ yếu giới thiệu thuật toán Andrew.

#### Tính chất

Độ phức tạp thời gian của thuật toán là $O(n\log n)$, trong đó $n$ là kích thước của tập điểm cần tìm bao lồi. Nút thắt độ phức tạp nằm ở việc sắp xếp tất cả các điểm theo hai khóa tọa độ.

#### Quy trình

Trước hết, sắp xếp tất cả các điểm theo hoành độ làm khóa thứ nhất và tung độ làm khóa thứ hai.

Rõ ràng phần tử nhỏ nhất và phần tử lớn nhất sau khi sắp xếp chắc chắn nằm trên bao lồi. Hơn nữa, vì đây là đa giác lồi, nếu đi ngược chiều kim đồng hồ từ một điểm, quỹ đạo luôn "rẽ trái"; một khi xuất hiện rẽ phải, điều đó cho thấy đoạn này không nằm trên bao lồi. Vì vậy, ta có thể dùng một stack đơn điệu để duy trì vỏ lồi dưới và vỏ lồi trên.

Khi nhìn từ trái sang phải, hướng quay của vỏ lồi dưới và vỏ lồi trên là khác nhau. Để stack đơn điệu phát huy tác dụng, trước hết ta **duyệt tăng dần** để tìm vỏ lồi dưới, sau đó **duyệt giảm dần** để tìm vỏ lồi trên.

Khi tìm vỏ lồi, nếu phát hiện điểm sắp được đưa vào stack ($P$) và hai điểm trên đỉnh stack ($S_1,S_2$, trong đó $S_1$ là đỉnh stack) tạo hướng di chuyển quay sang phải, tức tích có hướng nhỏ hơn $0$: $\overrightarrow{S_2S_1}\times \overrightarrow{S_1P}<0$, thì loại đỉnh stack, quay lại bước trước và tiếp tục kiểm tra, cho đến khi $\overrightarrow{S_2S_1}\times \overrightarrow{S_1P}\ge 0$ hoặc trong stack chỉ còn một phần tử.

Thông thường không cần giữ các điểm nằm trên cạnh của bao lồi, vì vậy dấu "$<$" trong điều kiện $\overrightarrow{S_2S_1}\times \overrightarrow{S_1P}<0$ ở đoạn trên có thể đổi thành $\le$ tùy tình huống, đồng thời điều kiện phía sau cần đổi thành $>$.

![Andrew](./images/andrew.svg)

#### Cài đặt

???+ note "Cài đặt"
    === "C++"
        ```cpp
        // stk[] la so nguyen, luu chi so
        // p[] luu vector hoac diem
        tp = 0;                       // khoi tao stack
        std::sort(p + 1, p + 1 + n);  // sap xep cac diem
        stk[++tp] = 1;
        // Them phan tu dau tien vao stack va khong cap nhat used, de diem 1 van
        // cap nhat stack don dieu khi khep kin bao loi cuoi cung
        for (int i = 2; i <= n; ++i) {
          while (tp >= 2  // dong tiep theo: toan tu * duoc nap chong thanh tich co huong
                 && (p[stk[tp]] - p[stk[tp - 1]]) * (p[i] - p[stk[tp]]) <= 0)
            used[stk[tp--]] = 0;
          used[i] = 1;  // used cho biet diem nam tren vo loi
          stk[++tp] = i;
        }
        int tmp = tp;  // tmp la kich thuoc vo loi duoi
        for (int i = n - 1; i > 0; --i)
          if (!used[i]) {
            // Khi tinh vo loi tren, khong anh huong den vo loi duoi
            while (tp > tmp && (p[stk[tp]] - p[stk[tp - 1]]) * (p[i] - p[stk[tp]]) <= 0)
              used[stk[tp--]] = 0;
            used[i] = 1;
            stk[++tp] = i;
          }
        for (int i = 1; i <= tp; ++i)  // sao chep sang mang moi
          h[i] = p[stk[i]];
        int ans = tp - 1;
        ```
    
    === "Python"
        ```python
        stk = []  # la so nguyen, luu chi so
        p = []  # luu vector hoac diem
        tp = 0  # khoi tao stack
        p.sort()  # sap xep cac diem
        tp = tp + 1
        stk[tp] = 1
        # Them phan tu dau tien vao stack va khong cap nhat used, de diem 1 van
        # cap nhat stack don dieu khi khep kin bao loi cuoi cung
        for i in range(2, n + 1):
            while tp >= 2 and (p[stk[tp]] - p[stk[tp - 1]]) * (p[i] - p[stk[tp]]) <= 0:
                # Dong tiep theo: toan tu * duoc nap chong thanh tich co huong
                used[stk[tp]] = 0
                tp = tp - 1
            used[i] = 1  # used cho biet diem nam tren vo loi
            tp = tp + 1
            stk[tp] = i
        tmp = tp  # tmp la kich thuoc vo loi duoi
        for i in range(n - 1, 0, -1):
            if used[i] == False:
                # Khi tinh vo loi tren, khong anh huong den vo loi duoi
                while tp > tmp and (p[stk[tp]] - p[stk[tp - 1]]) * (p[i] - p[stk[tp]]) <= 0:
                    used[stk[tp]] = 0
                    tp = tp - 1
                used[i] = 1
                tp = tp + 1
                stk[tp] = i
        for i in range(1, tp + 1):
            h[i] = p[stk[i]]
        ans = tp - 1
        ```

Theo đoạn code trên, cuối cùng trên bao lồi có $\textit{ans}$ phần tử (điểm số $1$ được lưu thêm, nên mảng $h$ có $\textit{ans}+1$ phần tử), và các điểm được sắp theo chiều ngược kim đồng hồ. Chu vi là

$$
\sum_{i=1}^{\textit{ans}}\left|\overrightarrow{h_ih_{i+1}}\right|
$$

### Graham scan

#### Tính chất

Tương tự thuật toán Andrew, độ phức tạp thời gian của Graham scan là $O(n\log n)$, nút thắt độ phức tạp cũng nằm ở việc sắp xếp tất cả các điểm.

#### Quy trình

Trước hết tìm điểm $P$ có tung độ nhỏ nhất trong tất cả các điểm. Theo định nghĩa bao lồi, ta biết điểm này chắc chắn nằm trên bao lồi. Sau đó sắp xếp tất cả các điểm theo góc cực so với điểm $P$.

![](./images/ch1.svg)

Tương tự thuật toán Andrew, xét việc đi ngược chiều kim đồng hồ trên bao lồi bắt đầu từ điểm $P$; mọi điểm ta đi qua đều phải là các lần "rẽ trái". Nói một cách hình thức, với ba điểm liên tiếp bất kỳ $P_1, P_2, P_3$ trên bao lồi theo chiều ngược kim đồng hồ, luôn có $\overrightarrow{P_1 P_2} \times \overrightarrow{P_2 P_3} \ge 0$.

Tạo một stack mới để lưu thông tin bao lồi, trước tiên đẩy $P$ vào stack, rồi lần lượt thử thêm từng điểm theo thứ tự góc cực. Nếu điểm sắp vào stack $P_0$ và hai điểm trên đỉnh stack $P_1, P_2$ (trong đó $P_1$ là đỉnh stack) tạo hướng di chuyển "rẽ phải", thì loại $P_1$ khỏi đỉnh stack. Lặp lại quá trình trên cho đến khi điểm sắp vào stack và hai điểm trên đỉnh stack thỏa điều kiện, hoặc trong stack chỉ còn một phần tử, rồi đẩy $P_0$ vào stack.

![](./images/ch2.svg)

![](./images/ch3.svg)

???+ note "Cài đặt"
    ```cpp
    struct Point {
      double x, y, ang;
    
      Point operator-(const Point& p) const { return {x - p.x, y - p.y, 0}; }
    } p[MAXN];
    
    double dis(Point p1, Point p2) {
      return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
    
    bool cmp(Point p1, Point p2) {
      if (p1.ang == p2.ang) {
        return dis(p1, p[1]) < dis(p2, p[1]);
      }
      return p1.ang < p2.ang;
    }
    
    double cross(Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }
    
    int main() {
      for (int i = 2; i <= n; ++i) {
        if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x)) {
          std::swap(p[1], p[i]);
        }
      }
      for (int i = 2; i <= n; ++i) {
        p[i].ang = atan2(p[i].y - p[1].y, p[i].x - p[1].x);
      }
      std::sort(p + 2, p + n + 1, cmp);
      sta[++top] = 1;
      for (int i = 2; i <= n; ++i) {
        while (top >= 2 &&
               cross(p[sta[top]] - p[sta[top - 1]], p[i] - p[sta[top]]) < 0) {
          top--;
        }
        sta[++top] = i;
      }
      return 0;
    }
    ```

## Tổng Minkowski

### Định nghĩa

Tổng Minkowski $P+Q$ của tập điểm $P$ và tập điểm $Q$ được định nghĩa là $P+Q=\{a+b|a\in P,b\in Q\}$. Nói cách khác, xem mỗi điểm trong tập điểm $Q$ là một vector, tịnh tiến mỗi điểm trong tập điểm $P$ theo các vector đó, thì tập hợp các kết quả cuối cùng chính là tập điểm $P+Q$. Ở đây chỉ xét tổng Minkowski của **bao lồi**.

Ví dụ: với tập điểm $P=\{(0,0),(-3,3),(2,1)\}$ và tập điểm $Q=\{(0,0),(-1,3),(1,4),(2,2)\}$,

![](./images/convex-hull1.svg)

Tịnh tiến $P$ theo từng vector của $Q$:

![](./images/convex-hull2.svg)

Dễ thấy hình mới cũng là một **bao lồi**:

![](./images/convex-hull3.svg)

### Tính chất

1.  Nếu các tập điểm $P$, $Q$ là tập lồi, thì tổng Minkowski $P+Q$ của chúng cũng là tập lồi.

    ??? note "Chứng minh"
        Giả sử $e,f\in P+Q$, khi đó tồn tại $a,b \in P$, $c,d\in Q$ sao cho $e=a+c,f=b+d$. Với mọi $t\in[0,1]$, ta có:
        
        $$
        \begin{aligned}
        te + (1-t)f &= t(a+c)+(1-t)(b+d)\\
        &=(ta+(1-t)b)+(tc+(1-t)d)\\
        &\in P+Q.
        \end{aligned}
        $$
        
        Chứng minh hoàn tất.
2.  Nếu các tập điểm $P$, $Q$ là tập lồi, thì tập cạnh của tổng Minkowski $P+Q$ là kết quả nối các cạnh của các tập lồi $P$, $Q$ sau khi sắp xếp theo góc cực.

    ??? note "Chứng minh"
        Không mất tính tổng quát, giả sử hệ số góc của mọi cạnh trong tập lồi $P$ đều khác hệ số góc của mọi cạnh trong tập lồi $Q$. Xoay hệ tọa độ sao cho một cạnh $XY$ trên $P$ song song với trục $x$ và nằm ở dưới cùng.
        
        Gọi $U$ là điểm thấp nhất của $Q$ lúc này, và $A$ là điểm **thấp nhất** đồng thời **ở bên trái nhất** của $P+Q$.
        
        Ta có $\vec{A} = \vec{X} + \vec{U}$, nên $A$ chắc chắn nằm trên biên của $P+Q$.
        
        Tương tự, với điểm $B$ **thấp nhất** đồng thời **ở bên phải nhất** trong $P+Q$, ta có $\vec{B} = \vec{Y} + \vec{U}$, nên $B$ cũng chắc chắn nằm trên biên của $P+Q$.
        
        Do đó, có $\vec{AB} = \vec{XY} + \vec{U}$.
        
        Nếu tiếp tục xoay theo thứ tự, kết quả sẽ liên tiếp tạo thành từng cạnh của $P+Q$.
        
        Chứng minh hoàn tất.

### Cài đặt

Theo tính chất 2, ta có thể sắp xếp các tập lồi $P,Q$ theo góc cực để thu được thứ tự xuất hiện của chúng trên $P+Q$. Xem $P_1+Q_1$ là điểm bắt đầu của $P+Q$, sau đó dùng cách tương tự **trộn** để lần lượt đặt các cạnh.

Độ phức tạp thời gian: $O(n+m)$

???+ note "Cài đặt"
    ```cpp
    template <class T>
    struct Point {
      T x, y;
    
      Point(T x = 0, T y = 0) : x(x), y(y) {}
    
      friend Point operator+(const Point &a, const Point &b) {
        return {a.x + b.x, a.y + b.y};
      }
    
      friend Point operator-(const Point &a, const Point &b) {
        return {a.x - b.x, a.y - b.y};
      }
    
      // Tich vo huong
      friend T operator*(const Point &a, const Point &b) {
        return a.x * b.x + a.y * b.y;
      }
    
      // Tich co huong
      friend T operator^(const Point &a, const Point &b) {
        return a.x * b.y - a.y * b.x;
      }
    };
    
    template <class T>
    vector<Point<T>> minkowski_sum(vector<Point<T>> a, vector<Point<T>> b) {
      vector<Point<T>> c{a[0] + b[0]};
      for (usz i = 0; i + 1 < a.size(); ++i) a[i] = a[i + 1] - a[i];
      for (usz i = 0; i + 1 < b.size(); ++i) b[i] = b[i + 1] - b[i];
      a.pop_back(), b.pop_back();
      c.resize(a.size() + b.size() + 1);
      merge(a.begin(), a.end(), b.begin(), b.end(), c.begin() + 1,
            [](const Point<T> &a, const Point<T> &b) { return (a ^ b) < 0; });
      for (usz i = 1; i < c.size(); ++i) c[i] = c[i] + c[i - 1];
      return c;
    }
    ```

### Ví dụ

???+ note "[Ví dụ \[JSOI2018\] War](https://loj.ac/p/2549)"
    Có hai bao lồi $P,Q$; tịnh tiến $Q$ tổng cộng $q$ lần, hỏi sau mỗi lần di chuyển hai bao lồi có giao điểm hay không. $1\le n,m\le 10^5,1\le q\le 10^5$.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/geometry/code/convex-hull/convex-hull_1.cpp"
    ```

## Bao lồi ba chiều

### Kiến thức cơ bản

> Phép nghịch đảo đường tròn: tâm nghịch đảo là $O$, bán kính nghịch đảo là $R$. Nếu đường thẳng đi qua $O$ cũng đi qua $P$,$P'$, và $OP\times OP'=R^{2}$, thì gọi $P$ và $P'$ là hai điểm nghịch đảo của nhau đối với $O$.

### Quy trình

Quy trình tìm bao lồi như sau:

-   Trước hết nhiễu loạn rất nhỏ các điểm để tránh trường hợp bốn điểm đồng phẳng.
-   Với một bao lồi đã biết, thêm một điểm mới $P$. Xem $P$ như một nguồn sáng điểm và chiếu các tia về phía bao lồi; khi đó có thể biết rằng các mặt nhìn thấy ánh sáng và các mặt không nhìn thấy ánh sáng chắc chắn bị ngăn cách bởi một số cạnh.
-   Xóa các mặt nhìn thấy ánh sáng, rồi thêm các mặt phẳng tạo bởi $P$ và các cạnh phân cách đó.
    Lặp lại quá trình này là có thể thu được kết quả. Theo [định lý Pick](./pick.md), công thức Euler (trong đa diện lồi, số đỉnh $V$, số cạnh $E$ và số mặt $F$ thỏa mãn $V-E+F=2$) và phép nghịch đảo đường tròn, độ phức tạp là $O(n^2)$.[^3d-v]

### Bài mẫu

[P4724 [Mẫu] Bao lồi ba chiều](https://www.luogu.com.cn/problem/P4724)

Lặp lại quy trình trên là có thể thu được đáp án.

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/geometry/code/3d/3d_1.cpp"
    ```

## Bài tập

-   [UVa11626 Convex Hull](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=78&page=show_problem&problem=2673)

-   ["USACO5.1" Fencing the Cows](https://www.luogu.com.cn/problem/P2742)

-   [POJ1873 The Fortified Forest](http://poj.org/problem?id=1873)

-   [POJ1113 Wall](http://poj.org/problem?id=1113)

-   [USACO22JAN Multiple Choice Test P](https://www.luogu.com.cn/problem/P8101)

-   ["SHOI2012" Credit Card Convex Hull](https://www.luogu.com.cn/problem/P3829)

## Tài liệu tham khảo và chú thích

[^3d-v]: [Ghi chép học bao lồi ba chiều](https://www.cnblogs.com/xzyxzy/p/10225804.html)
