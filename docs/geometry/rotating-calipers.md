Trang này chủ yếu giới thiệu thuật toán thước kẹp quay.

## Dẫn nhập

Thuật toán thước kẹp quay, tiếng Anh là Rotating Calipers, dựa trên bao lồi. Khi liệt kê một cạnh nào đó trên bao lồi, thuật toán đồng thời duy trì các điểm cần thiết khác, nhờ đó có thể giải các bài toán liên quan đến tính chất của bao lồi, như đường kính bao lồi hoặc hình chữ nhật phủ nhỏ nhất, trong thời gian tuyến tính.

???+ note "Tên gọi của thuật toán"
    Tên tiếng Việt trong bản dịch này là "thước kẹp quay". Có thể hiểu như sau: ứng với cạnh đang được liệt kê, từ mỗi điểm đang duy trì, vẽ một đường thẳng song song hoặc vuông góc với cạnh đó. Để bảo đảm tính tối ưu đối với cạnh hiện tại, các đường thẳng này cần vừa kẹp sát bao lồi. Các cạnh thường được liệt kê theo thứ tự quay về một hướng, nên toàn bộ quá trình giống như một chiếc thước kẹp đang quay quanh bao lồi.
    
    Tên tiếng Anh "rotating calipers" có thể dịch sát là "thước kẹp quay", trong đó "calipers" là thước kẹp. Bài báo đầu tiên đề xuất thuật ngữ này[^ref1] có ý tưởng dùng một chiếc thước kẹp có thể điều chỉnh động để kẹp bao lồi, rồi quay chiếc thước kẹp đó quanh bao lồi.

## Tìm đường kính bao lồi

???+ note "Ví dụ 1: [Luogu P1452 Cuộc thi sắc đẹp G](https://www.luogu.com.cn/problem/P1452)"
    Cho $n$ điểm trên mặt phẳng, tìm khoảng cách lớn nhất giữa mọi cặp điểm. ($2\leq n \leq 50000,|x|,|y| \leq 10^4$)

### Quá trình

Trước hết dùng một thuật toán bao lồi bất kỳ để tìm bao lồi của tất cả các điểm đã cho. Có thể chọn một cặp điểm đạt khoảng cách lớn nhất trên bao lồi. Do hình dạng của bao lồi, khi duyệt ngược chiều kim đồng hồ qua các cạnh của bao lồi và với mỗi cạnh tìm điểm xa cạnh đó nhất, điểm xa nhất tương ứng cũng quay ngược chiều kim đồng hồ theo cạnh, không quay ngược lại. Điều này có nghĩa là khi liệt kê các cạnh của bao lồi theo chiều ngược kim đồng hồ, chỉ cần ghi lại và duy trì một điểm xa nhất hiện tại, rồi liên tục tính và cập nhật đáp án.

Sau khi tìm bao lồi, mảng thu được tự nhiên được sắp theo thứ tự quay ngược chiều kim đồng hồ. Tuy nhiên cần nhớ thêm trước đỉnh số 1 ở góc trái dưới vào cuối mảng, để khi lần lượt liệt kê các cạnh $(i,i+1)$ thì có thể duyệt đủ mọi cạnh.

![](images/rotating-calipers1.png)

Trong quá trình liệt kê, với mỗi cạnh, kiểm tra khoảng cách từ $j+1$ đến cạnh $(i,i+1)$ có lớn hơn từ $j$ hay không. Nếu có thì tăng $j$ thêm một, nếu không thì $j$ là điểm tối ưu của cạnh này. Khi so sánh khoảng cách từ điểm đến cạnh, có thể dùng tích có hướng để tính diện tích của hai tam giác, như hai tam giác cùng đáy màu vàng và màu xanh trong hình, rồi so sánh trực tiếp.

### Cài đặt

???+ note "Mã lõi"
    === "C++"
        ```cpp
        int sta[N], top;  // Lưu số hiệu các đỉnh trên bao lồi trong ngăn xếp; đỉnh đầu và đỉnh cuối trùng nhau.
        
        ll pf(ll x) { return x * x; }
        
        ll dis(int p, int q) { return pf(a[p].x - a[q].x) + pf(a[p].y - a[q].y); }
        
        ll sqr(int p, int q, int y) { return abs((a[q] - a[p]) * (a[y] - a[q])); }
        
        ll mx;
        
        void get_longest() {  // Tìm đường kính bao lồi.
          int j = 3;
          if (top < 4) {
            mx = dis(sta[1], sta[2]);
            return;
          }
          for (int i = 1; i < top; ++i) {
            while (sqr(sta[i], sta[i + 1], sta[j]) <=
                   sqr(sta[i], sta[i + 1], sta[j % top + 1]))
              j = j % top + 1;
            mx = max(mx, max(dis(sta[i + 1], sta[j]), dis(sta[i], sta[j])));
          }
        }
        ```
    
    === "Python"
        ```python
        sta = [0] * N
        top = 0  # Lưu số hiệu các đỉnh trên bao lồi trong ngăn xếp; đỉnh đầu và đỉnh cuối trùng nhau.
        
        
        def pf(x):
            return x * x
        
        
        def dis(p, q):
            return pf(a[p].x - a[q].x) + pf(a[p].y - a[q].y)
        
        
        def sqr(p, q, y):
            return abs((a[q] - a[p]) * (a[y] - a[q]))
        
        
        def get_longest():  # Tìm đường kính bao lồi.
            j = 3
            if top < 4:
                mx = dis(sta[1], sta[2])
                return
            for i in range(1, top):
                while sqr(sta[i], sta[i + 1], sta[j]) <= sqr(
                    sta[i], sta[i + 1], sta[j % top + 1]
                ):
                    j = j % top + 1
                mx = max(mx, max(dis(sta[i + 1], sta[j]), dis(sta[i], sta[j])))
        ```

## Tìm hình chữ nhật phủ nhỏ nhất

[Luogu P3187 Hình chữ nhật phủ nhỏ nhất](https://www.luogu.com.cn/problem/P3187)

Cho tọa độ một số điểm, tìm hình chữ nhật có diện tích nhỏ nhất có thể phủ tất cả các điểm. ($3\leq n \leq 50000$)

### Quá trình

Dựa trên bài trước, ý tưởng trực quan của bài này vẫn là dùng thước kẹp quay. Tuy nhiên lần này cần tối ưu diện tích; nếu chỉ duy trì một điểm tối ưu như bài trước thì chỉ xác định được một cặp đường thẳng song song có khoảng cách nhỏ nhất, trong khi còn cần xác định biên trái và biên phải của hình chữ nhật. Vì vậy lần này cần duy trì ba điểm: một điểm nằm đối diện đường thẳng đang liệt kê và hai điểm nằm ở hai phía khác nhau. Điểm tối ưu ở phía đối diện vẫn được so sánh bằng diện tích tính bởi tích có hướng; lúc này so sánh diện tích chính là so sánh một cạnh của hình chữ nhật. Hai điểm tối ưu ở hai phía được so sánh bằng tích vô hướng, vì so sánh tích vô hướng chính là so sánh độ dài hình chiếu, và tổng hai độ dài hình chiếu trái phải có thể biểu diễn cạnh còn lại của hình chữ nhật. Tính tối ưu của hai cạnh này độc lập với nhau, nên khi tìm được vị trí của ba điểm tối ưu, có thể xác định hình chữ nhật có diện tích nhỏ nhất phủ mọi điểm khi đường thẳng chứa cạnh hiện tại là một cạnh của hình chữ nhật.

![](images/rotating-calipers2.png)

Khi thống kê đáp án cuối cùng, nếu đề bài không yêu cầu tìm cả bốn đỉnh, có một cách khá khéo để tính trực tiếp diện tích hình chữ nhật bằng tích có hướng và tích vô hướng. Gọi hai lần diện tích phần màu tím là $S$, diện tích cuối cùng là

$$
S\times (|\overrightarrow{AD}\cdot \overrightarrow{AB}|+|\overrightarrow{BC}\cdot \overrightarrow{BA}|-|\overrightarrow{AB}\cdot \overrightarrow{BA}|)/|\overrightarrow{AB}\cdot \overrightarrow{BA}|
$$

### Cài đặt

Phần tìm bao lồi cần thiết được lược bỏ; dưới đây là mã lõi của bài này:

???+ note "Mã lõi"
    === "C++"
        ```cpp
        void get_biggest() {
          int j = 3, l = 2, r = 2;
          double t1, t2, t3, ans = 2e10;
          for (int i = 1; i < top; ++i) {
            while (sqr(sta[i], sta[i + 1], sta[j]) <=
                   sqr(sta[i], sta[i + 1], sta[j % top + 1]))
              j = j % top + 1;
            while (dot(sta[i + 1], sta[r % top + 1], sta[i]) >=
                   dot(sta[i + 1], sta[r], sta[i]))
              r = r % top + 1;
            if (i == 1) l = r;
            while (dot(sta[i + 1], sta[l % top + 1], sta[i]) <=
                   dot(sta[i + 1], sta[l], sta[i]))
              l = l % top + 1;
            t1 = sqr(sta[i], sta[i + 1], sta[j]);
            t2 = dot(sta[i + 1], sta[r], sta[i]) + dot(sta[i + 1], sta[l], sta[i]);
            t3 = dot(sta[i + 1], sta[i + 1], sta[i]);
            ans = min(ans, t1 * t2 / t3);
          }
        }
        ```
    
    === "Python"
        ```python
        def get_biggest():
            j = 3
            l = 2
            r = 2
            ans = 2e10
            for i in range(1, top):
                while sqr(sta[i], sta[i + 1], sta[j]) <= sqr(
                    sta[i], sta[i + 1], sta[j % top + 1]
                ):
                    j = j % top + 1
                while dot(sta[i + 1], sta[r % top + 1], sta[i]) >= dot(
                    sta[i + 1], sta[r], sta[i]
                ):
                    r = r % top + 1
                if i == 1:
                    l = r
                while dot(sta[i + 1], sta[l % top + 1], sta[i]) <= dot(
                    sta[i + 1], sta[l], sta[i]
                ):
                    l = l % top + 1
                t1 = sqr(sta[i], sta[i + 1], sta[j])
                t2 = dot(sta[i + 1], sta[r], sta[i]) + dot(sta[i + 1], sta[l], sta[i])
                t3 = dot(sta[i + 1], sta[i + 1], sta[i])
                ans = min(ans, t1 * t2 / t3)
        ```

## Luyện tập

-   [POJ 3608. Cầu nối qua các đảo](http://poj.org/problem?id=3608)
-   [2011 ACM-ICPC World Finals, Bài K. Dọn rác](https://codeforces.com/gym/101175)
-   [ICPC WF Moscow Invitational Contest - bản thi trực tuyến, Bài F. Đóng khung tranh](https://codeforces.com/contest/1578/problem/F)

## Tài liệu tham khảo và chú thích

[^ref1]: Toussaint, Godfried T. (1983). "Solving geometric problems with the rotating calipers". Proc. MELECON '83, Athens. CiteSeerX 10.1.1.155.5671

-   <https://en.wikipedia.org/wiki/Rotating_calipers>

-   <http://www-cgrl.cs.mcgill.ca/~godfried/research/calipers.html>

-   Shamos, Michael (1978). "Computational Geometry" (PDF). Yale University. pp. 76-81.
