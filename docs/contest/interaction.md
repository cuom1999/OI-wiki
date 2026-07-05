author: countercurrent-time, StudyingFather

Từ thế kỷ trước, IOI đã có các bài tương tác. Dù những năm gần đây dạng bài tương tác không xuất hiện trong các kỳ thi dưới cấp tuyển chọn tỉnh, nhưng trong hệ thống kỳ thi NOI năm 2019 đã liên tiếp xuất hiện hai bài tương tác *P5208 [WC2019] Cửa hàng của I-kun* và *P5473 [NOI2019] Cuộc thám hiểm của I-kun*. Điều này có thể cho thấy bài tương tác đang quay trở lại hệ thống kỳ thi NOI.

Bài tương tác không đòi hỏi quá nhiều thuật toán nền tảng, thường cũng không có giới hạn thời gian quá chặt; mức độ tốt của chương trình thường chỉ phụ thuộc vào giới hạn số lần tương tác. Vì vậy khi học bài tương tác, nên đi từ dễ đến khó. Nếu muốn rèn tư duy thuật toán chứ không chỉ đơn thuần học thuật toán, làm bài tương tác là một cách rất tốt. Tuy yêu cầu về các thuật toán đã nắm của thí sinh thường khá thấp, vẫn nên nắm được một số thuật toán nâng cao và thuật toán cấp tuyển chọn tỉnh rồi mới thử bài tương tác, vì lúc đó tư duy thuật toán và phạm vi kiến thức của bản thân đã đạt đến một mức nhất định. Phần giới thiệu cơ bản về bài tương tác có thể tham khảo [Giới thiệu dạng bài - Bài tương tác](./problems.md#bài-tương-tác) của **OI Wiki**.

Các lỗi đặc thù của bài tương tác:

-   Sau mỗi lần thí sinh xuất dữ liệu đều cần xả bộ đệm, nếu không sẽ gây lỗi vượt giới hạn nhàn rỗi (Idleness Limit Exceeded, ILE). Ngoài ra, nếu bài có nhiều bộ dữ liệu và chương trình có thể biết đáp án trước khi đọc hết mọi dữ liệu, vẫn phải đọc hết toàn bộ dữ liệu; nếu không, việc đọc bị rối cũng sẽ gây ILE (có thể đưa ra nhiều truy vấn một lần rồi nhận toàn bộ câu trả lời của các truy vấn đó cùng lúc). Đồng thời, cố gắng không dùng nhập nhanh.
-   Nếu chương trình truy vấn quá nhiều lần, Codeforces sẽ trả kết quả đáp án sai (Wrong Answer, WA; nhưng hệ thống chấm sẽ nêu nguyên nhân), còn UVa sẽ trả kết quả vượt giới hạn giao thức (Protocol Limit Exceeded, PLE).
-   Nếu định dạng tương tác của chương trình sai, UVa sẽ trả kết quả vi phạm giao thức (Protocol Violation, PV).

Vì nhập xuất của bài tương tác khá rườm rà, nên đóng gói riêng các hàm nhập và xuất.

Khi thi, nếu tác giả bài cho sẵn tệp tiêu đề của trình chấm (dùng để gỡ lỗi bài tương tác kiểu grader) hoặc chương trình kiểm tra đáp án (dùng để gỡ lỗi bài tương tác kiểu nhập xuất chuẩn), việc gỡ lỗi bài tương tác sẽ tương đối đơn giản, vì đối chiếu kiểm thử bài tương tác khó hơn nhiều so với bài thông thường. Khi không có `testlib.h`, thư viện tương tác nhập xuất chuẩn cho một bài có nhiều chi tiết tương tác thường đã có khoảng 3k dòng mã; cộng thêm một bộ đối chiếu dài khoảng 3k nữa thì ít nhất cần một giờ để cài đặt. Tuy nhiên, bất kể có chương trình gỡ lỗi hay không, khi gỡ lỗi mã bài tương tác, thí sinh thường phải tự mô phỏng quá trình tương tác với chương trình. Vì vậy bài tương tác đòi hỏi thí sinh thiết kế được chương trình chất lượng cao, cố gắng làm đúng ngay từ đầu, đồng thời có năng lực kiểm lỗi tĩnh tốt.

Ví dụ:

-   [CF679A Bear and Prime 100](https://codeforces.com/problemset/problem/679/A)
-   [CF843B Interactive LowerBound](https://codeforces.com/problemset/problem/843/B)
-   [UOJ206\[APIO2016\]Gap](http://uoj.ac/problem/206)
-   [CF750F New Year and Finding Roots](https://codeforces.com/problemset/problem/750/F)
-   [UVa12731 Bí ẩn trạm không gian / Mysterious Space Station](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4584)

## CF679A Bear and Prime 100

Mỗi số nguyên tố có đúng hai ước, nên ta có thể trực tiếp liệt kê các ước của số cần đoán. Vì giới hạn tối đa 20 truy vấn, và với các số lớn hơn (như 92), khi thử phân tích thừa số nguyên tố sẽ thấy cần liệt kê các số nguyên tố đến tận $\lfloor\frac{n}{2}\rfloor$ trong trường hợp xấu nhất. Vì vậy trước tiên ta sàng các số nguyên tố không vượt quá 50, rồi lần lượt hỏi tất cả các số đó.

Do bài này khá dễ đối chiếu kiểm thử, có thể trực tiếp thử mọi số trong miền giá trị. Ta sẽ thấy chương trình không xử lý hiệu quả bình phương của số nguyên tố. Vì vậy cần thêm bình phương của 2,3,5,7, tức 4,9,25,49, tổng cộng 19 số, thỏa mãn yêu cầu đề bài.

??? note "Mã tham khảo"
    ```cpp
    #include <cstdio>
    constexpr int prime[] = {2,  3,  4,  5,  7,  9,  11, 13, 17, 19,
                             23, 25, 29, 31, 37, 41, 43, 47, 49};
    int cnt = 0;
    char res[5];
    
    int main() {
      for (int i : prime) {
        printf("%d\n", i);
        fflush(stdout);
        scanf("%s", res);
        if (res[0] == 'y' && ++cnt == 2) return printf("composite"), 0;
      }
      printf("prime");
      return 0;
    }
    ```

## CF843B Interactive LowerBound

Danh sách liên kết có tối đa $5 \times 10 ^ 4$ phần tử, nhưng ta chỉ được truy vấn $1999$ lần và chỉ lấy được phần tử kế tiếp của một phần tử, nên cách duyệt toàn bộ danh sách liên kết thông thường không dùng được. Chỉ có một cách trực tiếp để tìm cách tiến gần đến vị trí của phần tử mục tiêu: rải điểm ngẫu nhiên.

Với trường hợp $n < 2000$ thì liệt kê trực tiếp. Khi $n \ge 2000$, ta rải trực tiếp 1000 điểm; lúc này khoảng cách kỳ vọng giữa các điểm này rất nhỏ, và ta có thể bắt đầu duyệt về sau từ giá trị lớn nhất nhỏ hơn $x$. Có thể chứng minh rằng trước khi đến điểm tiếp theo, ta đã thu được đáp án. Trong quá trình duyệt, hễ tìm được phần tử lớn hơn hoặc bằng $x$ thì có thể suy ra trực tiếp.

Tuy ý tưởng tổng thể đơn giản, nhưng trên thực tế nếu chưa từng học các thuật toán ngẫu nhiên không hoàn hảo như mô phỏng luyện kim, việc nghĩ ra có thể sẽ khó hơn một chút.

Đồng thời, vì Codeforces có cơ chế hack, nhiều người sẽ cố tình tạo bộ hack cho các mã không khởi tạo hạt giống ngẫu nhiên, nên trước hàm `random_shuffle()` cần gọi `srand((size_t)new char)`.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstdlib>
    constexpr int N = 50005;
    int n, start, x;
    int a[N];
    
    int main() {
      scanf("%d%d%d", &n, &start, &x);
      if (n < 2000) {
        int ans = 2e9;
        for (int i = 1; i <= n; i++) {
          printf("? %d\n", i), fflush(stdout);
          int val, next;
          scanf("%d%d", &val, &next);
          if (val >= x) ans = std::min(ans, val);
        }
        if (ans == 2e9) ans = -1;
        printf("! %d", ans), fflush(stdout);
      } else {
        srand((size_t) new char);
        int p = start, ans = 0;
        for (int i = 1; i <= n; i++) a[i] = i;
        std::random_shuffle(a + 1, a + n + 1);
        for (int i = 1; i <= 1000; i++) {
          printf("? %d\n", a[i]), fflush(stdout);
          int val, next;
          scanf("%d%d", &val, &next);
          if (val < x && val > ans) p = a[i], ans = val;
        }
        while (p != -1 && ans < x) {
          printf("? %d\n", p), fflush(stdout);
          int val, next;
          scanf("%d%d", &val, &next);
          ans = val;
          p = next;
        }
        if (ans < x) ans = -1;
        printf("! %d", ans), fflush(stdout);
      }
      return 0;
    }
    ```

## UOJ206\[APIO2016]Gap

Chia thành hai subtasks để thảo luận:

1.  Giới hạn số lần truy vấn.

    Ta xét truy vấn đầu tiên. Vì ban đầu không biết bất kỳ số nào, ta cần hỏi đoạn $[1, 10 ^ {18}]$ để nhận giá trị lớn nhất và nhỏ nhất.

    Do giới hạn số lần truy vấn vừa đúng là $\frac{N + 1}{2}$, ta xét làm thế nào để mỗi lần đều lấy được những giá trị chưa từng lấy trước đó, nhờ vậy đại khái có thể lấy được toàn bộ các số trong dãy trong giới hạn số lần. Cách làm cũng rất đơn giản: sau mỗi lần truy vấn $[s, t]$, giả sử nhận được các giá trị $mn, mx$, thì truy vấn tiếp theo là $[mn + 1, mx - 1]$.

2.  Giới hạn kích thước đoạn truy vấn.

    Vì đề bài yêu cầu tổng số lượng các số trong những đoạn được truy vấn không vượt quá $3N$, ta xét cách tối thiểu hóa đoạn truy vấn. Cách ở trên không còn dùng được, vì tổng số lượng các số trong các đoạn truy vấn có quy mô $O(N ^ 2)$. Ta có thể xét chặt nhị phân miền giá trị, nhưng cách này không đáng tin cậy, trường hợp xấu nhất có thể bị chặn đến $O(N ^ 2)$. Vì vậy cần một cách chia miền giá trị hiệu quả hơn để tránh truy vấn lặp lại các điểm trong đoạn, gây lãng phí cơ hội.

    Nhận thấy đáp án không nhỏ hơn $\lfloor\frac{a_n - a_1}{N - 1}\rfloor$, nên có thể xét chia miền giá trị theo giá trị này. Đặt $i$ ban đầu là 0, $ans$ ban đầu là giá trị vừa nêu; mỗi lần truy vấn $[i, i + ans]$ và cập nhật $ans$, sau đó lại tăng $i$ với bước nhảy là $ans$.

    Tuy nhiên cách này cũng không áp dụng tốt cho subtask 1, vì trong trường hợp xấu nhất có thể có rất nhiều truy vấn mà trong miền giá trị không chứa số nào.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    
    #include "gap.h"
    
    long long findGap(int T, int N) {
      static long long a[100005] = {}, ans = 0;
      long long s = 0, t = 1e18, s1, t1;
      if (T == 1) {
        int l = 1, r = N;
        while (l <= r) {
          MinMax(s, t, &s1, &t1);
          a[l++] = s1, a[r--] = t1;
          s = s1 + 1, t = t1 - 1;
        }
        for (int i = 2; i <= N; i++) ans = std::max(ans, a[i] - a[i - 1]);
      } else if (T == 2) {
        MinMax(s, t, &s1, &t1);
        ans = (t1 - s1) / (N - 1);
        long long l = s1 + 1, r = t1, last = s1;
        for (long long i = l; i <= r;) {
          MinMax(i, i + ans, &s1, &t1);
          i += ans + 1;
          if (s1 != -1) ans = std::max(ans, s1 - last), last = t1;
        }
      }
      return ans;
    }
    ```

## CF750F New Year and Finding Roots

Thấy yêu cầu chặt chẽ $h \le 7$, số lần truy vấn $\le 16$, ta cần tận dụng tối đa thông tin thu được từ mỗi lần thăm.

Khi $h \le 4$ có thể brute force trực tiếp. Tuy nhiên khi $h > 4$ cần một thuật toán duyệt rất hiệu quả.

Rải điểm ngẫu nhiên không phải cách tốt, vì nó không thể xác định bản thân đã đủ gần nút gốc hay chưa. Nếu chỉ rải điểm ngẫu nhiên đơn thuần, xác suất ít nhất một lần chạm nút gốc là $1 - (\frac{2 ^ h - 2}{2 ^ h - 1})$; ngay cả khi loại bỏ trường hợp rải trùng điểm, xác suất chạm nút gốc vẫn rất nhỏ.

Vì $1 \le k \le 3$ và ta không biết phía nào gần nút gốc hơn, ta xét trường hợp xấu nhất: khi $k = 3$, hai lần đầu hướng duyệt của ta đều đi xa nút gốc, lần thứ ba mới đi gần nút gốc. Vì vậy ta buộc phải duyệt theo cả ba hướng.

Xét hai cách duyệt bfs và dfs. Do cây tìm kiếm của bfs có thể rất lớn, ta ưu tiên xét dfs. Tất nhiên, nếu biết độ sâu hiện tại và độ sâu hiện tại nhỏ đến mức kích thước cây tìm kiếm trong phạm vi độ sâu đó không vượt quá số lần còn lại, ta có thể bfs trực tiếp.

Biết độ sâu của nút hiện tại và hướng đang duyệt sẽ đem lại lợi thế rất lớn. Tuy nhiên việc biết hiện tại đang đi về phía nút gốc hay đi về phía lá là rất khó. Nếu dùng dfs, chỉ khi duyệt đến nút gốc ($k = 2$) hoặc nút lá ($k = 1$) mới biết được hướng hiện tại. Vì vậy ta cần biết độ sâu của nút hiện tại nhiều nhất có thể, đồng thời không thể dùng những cách như iterative deepening rồi dừng giữa chừng trong quá trình duyệt.

Xét chọn ngẫu nhiên một nút ban đầu; xuất phát từ nút ban đầu có thể gặp trường hợp xấu nhất ở trên.

Nếu $k = 1$, ta có thể biết trực tiếp độ sâu của nút hiện tại.

Nếu $k = 2$, nút hiện tại chính là nút gốc.

Nếu $k = 3$, ta trực tiếp xét dfs theo cả ba hướng. Vì hai hướng trong đó đi thẳng về phía lá nên độ dài đường duyệt bằng nhau; hướng còn lại đi về phía nút gốc, nhưng có thể giữa chừng vô tình đi về phía lá, khiến độ dài đường duyệt lớn hơn. Khi đó ta có thể tính được độ sâu của nút hiện tại.

Khi $k = 1$ hoặc $k = 3$, ta cần xét đường duyệt dài hơn. Ta có thể biết điểm có độ sâu nhỏ nhất trên đường đi (chắc chắn nhỏ hơn độ sâu của nút ban đầu). Nếu đánh dấu các nút đã thăm và không duyệt lại, từ nút đó trở đi chỉ còn một đường duyệt. Dù đường này vẫn có thể đi về phía lá, trên đường đó chắc chắn cũng tồn tại nút có độ sâu nhỏ hơn điểm xuất phát, và ta có thể bắt đầu từ nút này để tiếp tục lặp lại các bước ở trên.

Tất nhiên, khi xét trường hợp xấu nhất với $h = 7$ (mỗi lần chỉ đi một bước về phía nút gốc rồi lập tức đi về phía lá), ta sẽ thấy nếu chỉ dfs thì trường hợp xấu nhất cần $\frac{(1 + 7) \times 7}{2} = 28$ lần truy vấn. Nhưng ta đã biết độ sâu của nút ban đầu, nên có thể tính được độ sâu của mọi nút đã duyệt, và dựa trên thảo luận về bfs ban đầu để phán đoán liệu có thể bfs trực tiếp từ nút có độ sâu nhỏ nhất hay không.

Lúc này ta có thể tính được trường hợp xấu nhất cần 17 lần. Vì vậy ta xét loại bỏ một nút khỏi cây tìm kiếm (dựa trên tính chất dfs chỉ có thể duyệt mù, ta xét bfs): khi thực hiện bfs ở độ sâu $k$, cây tìm kiếm trong trường hợp xấu nhất có $2 ^ k - 1$ nút, có thể cần $2 ^ k - 1$ lần truy vấn mới xác định được nút nào có đúng 2 hàng xóm. Tuy nhiên nếu ta đã truy vấn $2 ^ k - 2$ nút trong số đó, có thể biết chắc nút cuối cùng là nút gốc.

Khi đó lời giải tối ưu trong trường hợp xấu nhất là: với $h = 7$, bắt đầu dfs từ một nút lá; mỗi lần đều chỉ đi một bước về phía nút gốc rồi lập tức đi về phía lá. Sau 10 lần truy vấn, độ sâu của nút có độ sâu nhỏ nhất hiện đã biết là 4. Vì đã biết cha của nó, ta bfs trực tiếp từ cha của nó (độ sâu cây tìm kiếm là 3, số nút là $2 ^ 3 - 1 = 7$). Trong lúc bfs, sau khi truy vấn $2 ^ 3 - 2 = 6$ lần, xác định nút cuối cùng trên cây tìm kiếm bfs là nút gốc.

Khi đó thuật toán của ta vừa khít trường hợp xấu nhất 16 lần.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <queue>
    #include <vector>
    using namespace std;
    constexpr int N = 256 + 5;
    int T, h, chance;
    bool ok;
    vector<int> to[N], path;
    
    bool read(int x) {
      if (to[x].empty()) {
        printf("? %d\n", x), fflush(stdout);
        int k, t;
        scanf("%d", &k);
        if (k == 0) exit(0);
        for (int i = 0; i < k; i++) {
          scanf("%d", &t);
          to[x].push_back(t);
        }
        if (k == 2) {
          printf("! %d\n", x), fflush(stdout);
          return ok = true;
        }
        chance--;
      }
      return false;
    }
    
    bool dfs(int x) {
      if (to[x].empty()) path.push_back(x);
      if (read(x)) return true;
      for (int i : to[x])
        if (to[i].empty()) return dfs(i);
      return false;
    }
    
    void bfs(int s, int k) {
      queue<int> q;
      for (int i : to[s])
        if (to[i].empty()) q.push(i);
      for (int i = 1; i < k; i++) {
        int x = q.front();
        q.pop();
        if (read(x)) return;
        for (int j : to[x])
          if (to[j].empty()) q.push(j);
      }
      for (int i = 1; i < k; i++) {
        int x = q.front();
        q.pop();
        if (read(x)) return;
      }
      printf("! %d\n", q.front()), fflush(stdout);
    }
    
    int main() {
      for (scanf("%d", &T); T--;) {
        ok = false;
        for (int i = 0; i < N; i++) to[i].clear();
        chance = 16;
        scanf("%d", &h);
        if (h == 0) exit(0);
        vector<int> long_path;
        if (read(1)) continue;
        int root, dep;
        if (to[1].size() == 1)
          root = 1, dep = h;
        else {
          for (int i : to[1]) {
            path.clear();
            if (dfs(i)) break;
            if (path.size() > long_path.size()) swap(path, long_path);
          }
          if (ok) continue;
          dep = h - (path.size() + long_path.size()) / 2;
          root = long_path.at((long_path.size() - (h - dep)) - 1);
        }
        while ((1 << (dep - 1)) - 2 > chance) {
          path.clear();
          if (dfs(root)) break;
          dep = h - (h - dep + path.size()) / 2;
          root = path.at((path.size() - (h - dep)) - 1);
        }
        if (!ok) bfs(root, 1 << (dep - 2));
      }
      return 0;
    }
    ```

## UVa12731 Bí ẩn trạm không gian / Mysterious Space Station

Vì phản hồi duy nhất là khi di chuyển có va vào tường hay không, ta nên xét cách đi sát mép tường nhiều nhất có thể trong khi vẫn không để robot bị lạc. Cách này có vài lợi ích:

-   Khi đi sát mép tường, rất dễ biết mình có va vào tường hay không, nhờ đó thu được nhiều thông tin nhất có thể.
-   Các ô sát tường đều không thể là ô có cổng dịch chuyển, nhờ vậy có thể tránh để robot bị lạc.

Vì vậy, nếu đã biết robot có thể đang ở một vị trí nào đó sát tường, để xác định robot có thật sự ở vị trí này hay không, có thể dùng [phương pháp "một tay men tường"](https://en.wikipedia.org/wiki/Maze_solving_algorithm). Theo nguyên lý tô pô, trong mê cung có tường ở hai bên, nếu đi vào từ cửa vào và luôn dùng một tay men theo cùng một bên tường, có thể đảm bảo tìm được lối ra. Vì tường trong bài này khép kín, chỉ cần đi dọc theo đường sát tường là có thể đảm bảo quay về điểm xuất phát mà không va tường. Ngoài ra, vì đường sát tường là chu trình khép kín lớn nhất trên bản đồ, trong mã thực tế không cần cố tình đâm vào tường để đảm bảo robot đang ở sát tường; có thể dùng đánh dấu để chỉ ra đường sát tường trên bản đồ. Hơn nữa, một khi va vào tường thì cần nhanh chóng quay lại theo đường cũ, vừa tránh để robot bị lạc vừa giảm số bước.

Từ đó có thể suy ra phương pháp thử sai để xác định robot có ở một ô cụ thể hay không: đưa robot, trong điều kiện không đi vào ô chưa biết hoặc cổng dịch chuyển đã biết, đến đường sát tường, rồi đi một vòng quanh đường sát tường. Nếu trong quá trình này không va tường, có thể xác định robot đúng là đang ở ô cụ thể đó.

Ta có thể dùng phương pháp trên: ban đầu đánh dấu toàn bộ các ô chưa biết trong hình, sau đó lần lượt xét từng ô chưa biết từ trên xuống dưới, từ trái sang phải để phán đoán ô đó có phải cổng dịch chuyển hay không. Có thể đi đến phía trên ô chưa biết trước, sau đó đi xuống và sang trái. Rồi dùng phương pháp trên để phán đoán robot có đang ở bên trái ô chưa biết hay không. Nếu không, nghĩa là robot không ở vị trí lẽ ra phải ở, tức ô chưa biết là cổng dịch chuyển.

Sau khi tìm ra các ô chưa biết, cần phán đoán quan hệ ghép cặp của $2k$ ô chưa biết. Cách làm thực tế cũng rất đơn giản: chỉ cần ghép cặp brute force. Vì $k \le 5$, nên nhiều nhất chỉ cần $9 + 7 + 5 + 3$ lần thử sai. Để so sánh, trường hợp phán đoán toàn bộ ô chưa biết trong hình nhiều nhất cần $121 - 40$ lần thử sai.

Hiện tại, mã dưới đây chỉ qua được bài bản sao trên UOJ: [#247. Rujia Liu's Present 7: Mysterious Space Station](http://uoj.ac/problem/247), nhưng không qua được đề gốc UVa. Sau khi sửa lời giải chuẩn của Liu Rujia trên UOJ vẫn không qua, và tạm thời chưa liên hệ được với Liu Rujia. Vì vậy mã dưới đây lấy UOJ làm chuẩn.

Tuy nhiên chất lượng lời giải chuẩn của Liu Rujia vẫn cao hơn mã dưới đây rất nhiều; có thể xem [lời giải chuẩn đã qua bài bản sao UOJ](http://uoj.ac/submission/105789) trên UOJ. Với cùng một bộ dữ liệu, số lần di chuyển mà lời giải chuẩn dùng là rất ít.

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    #include <queue>
    #include <stack>
    
    #define Wall 0
    #define Unknown 1
    #define Space 2
    #define Gate 3
    #define Path 4
    
    const int N = 20;
    const int dir[8][2] = {{0, 1},  {1, 0}, {0, -1}, {-1, 0},
                           {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    const char dirs[5] = "ESWN";
    int n, m, k;
    int a[N][N], id[N][N];
    
    struct point {
      int x, y;
    
      point(int x = 0, int y = 0) : x(x), y(y) {}
    
      bool operator==(const point& tmp) const { return x == tmp.x && y == tmp.y; }
    
      bool operator!=(const point& tmp) const { return !(*this == tmp); }
    
      point side(int d) const { return point(x + dir[d][0], y + dir[d][1]); }
    
      int check(int d) { return a[x + dir[d][0]][y + dir[d][1]]; }
    
      int id() { return ::id[x][y]; }
    } start;
    
    std::vector<std::pair<point, int>> path;
    std::pair<point, point> ans[N];
    std::pair<point, bool> vis[N];
    
    bool walk(int d) {
      printf("MoveRobot %c\n", dirs[d]);
      fflush(stdout);
      int ret;
      scanf("%d", &ret);
      return ret;
    }
    
    bool walk(int d, std::stack<int>& st) {
      if (walk(d)) {
        st.push(d);
        return true;
      }
      return false;
    }
    
    bool read() {
      if (scanf("%d%d%d", &n, &m, &k) != 3) return false;
      if (n == 0) return false;
      memset(a, 0, sizeof(a));
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
          char c;
          std::cin >> c;
          if (c == 'S') start = point(i, j);
          if (c == '*')
            a[i][j] = Wall;
          else
            a[i][j] = Unknown;
        }
      return true;
    }
    
    void answer() {
      for (int i = 0; i < k; i++)
        printf("Answer %d %d\n", ans[i].first.id(), ans[i].second.id());
      fflush(stdout);
    }
    
    // Phương pháp một tay men tường: vì Path sát tường là một vòng khép kín
    // cực đại, chỉ cần trong quá trình đi dọc Path không gặp chướng ngại là đủ
    void wall_follower_init(point x, int last, int wallside, point s) {
      if (x == s && !path.empty()) return;
      if (x.check(wallside) == Path) {
        path.push_back(std::make_pair(x, wallside));
        wall_follower_init(x.side(wallside), wallside, last ^ 2, s);
      } else if (x.check(last) == Wall) {
        for (int i = 0; i < 4; i++)
          if (i != (last ^ 2) && x.check(i) != Wall) {
            path.push_back(std::make_pair(x, i));
            wall_follower_init(x.side(i), i, last, s);
            return;
          }
      } else {
        path.push_back(std::make_pair(x, last));
        wall_follower_init(x.side(last), last, wallside, s);
      }
    }
    
    void init() {
      int cnt = 1;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
          if (a[i][j] == Unknown) {
            id[i][j] = cnt++;
            for (int k = 0; k < 8; k++)
              if (point(i, j).check(k) == Wall) {
                a[i][j] = Path;
                break;
              }
          } else
            id[i][j] = 0;
        }
      path.clear();
      int wallside = 0, last = 0;
      for (int i = 0; i < 4; i++)
        if (start.check(i) == Wall) {
          wallside = i;
          break;
        }
      for (int i = 0; i < 4; i++)
        if (start.check(i) == Path && i != (wallside ^ 2)) {
          last = i;
          break;
        }
      wall_follower_init(start, last, wallside, start);
    }
    
    void undo(std::stack<int>& st) {
      while (!st.empty()) walk(st.top() ^ 2), st.pop();
    }
    
    bool wall_follower(point x) {
      std::stack<int> st;
      bool ok = true;
      int i = 0;
      while (i < path.size() && path[i].first != x) i++;
      for (int j = i; ok && j < path.size(); j++) {
        if (walk(path[j].second))
          st.push(path[j].second);
        else
          ok = false;
      }
      for (int j = 0; ok && j < i; j++) {
        if (walk(path[j].second))
          st.push(path[j].second);
        else
          ok = false;
      }
      if (!ok) undo(st);
      return ok;
    }
    
    // Xác định hiện tại mình đang ở x. Dùng cách "dò từng bước":
    // chỉ cần đi theo các hướng có thể tránh chướng ngại, ô chưa biết và cổng
    // dịch chuyển cho đến khi tới Path. Dùng khi tìm cổng và ghép cặp cổng.
    void bfs(point s, point t, std::vector<int>& v) {
      static int map[N][N] = {};
      memset(map, -1, sizeof(map));
      std::queue<point> q;
      map[s.x][s.y] = 4;
      q.push(s);
      while (!q.empty()) {
        point x = q.front();
        q.pop();
        if (x == t) break;
        for (int i = 0; i < 4; i++) {
          point y = x.side(i);
          if ((x.check(i) == Path || x.check(i) == Space) && map[y.x][y.y] == -1) {
            map[y.x][y.y] = i;
            q.push(y);
          }
        }
      }
      for (point x = t; x != s; x = x.side(map[x.x][x.y] ^ 2)) {
        v.push_back(map[x.x][x.y]);
      }
      std::reverse(v.begin(), v.end());
    }
    
    bool move(point s, point t, std::stack<int>& st) {  // Dùng khi tới gần cổng
      static std::vector<int> v;
      v.clear();
      bfs(s, t, v);
      for (int i : v)
        if (!walk(i, st)) return false;
      return true;
    }
    
    // Di chuyển về phía mép tường nhanh nhất có thể
    bool make_sure(point x, int last) {
      if (a[x.x][x.y] == Path) return wall_follower(x);
      for (int i = 0; i < 4; i++)
        if ((x.check(i) == Path || x.check(i) == Space) && i != (last ^ 2)) {
          if (!walk(i)) return false;
          bool ret = make_sure(x.side(i), i);
          walk(i ^ 2);
          return ret;
        }
      return false;
    }
    
    void find_gate() {
      int cnt = 0;
      std::stack<int> st;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (cnt == k * 2 && a[i][j] == Unknown)
            a[i][j] = Space;
          else if (a[i][j] == Unknown) {
            bool ok = true;
            if (!move(start, point(i - 1, j), st))
              ok = false;
            else if (!walk(1, st))
              ok = false;
            else if (!walk(2, st))
              ok = false;
            else if (!make_sure(point(i, j - 1), -1))
              ok = false;
            if (!ok) {
              vis[cnt++] = std::make_pair(point(i, j), false);
              a[i][j] = Gate;
              for (int k = 0; k < 8; k++) {
                point y = point(i, j).side(k);
                if (point(i, j).check(k) == Unknown) a[y.x][y.y] = Space;
              }
            } else
              a[i][j] = Space;
            undo(st);
          }
    }
    
    void make_gate_pair() {
      int cnt = 0;
      std::stack<int> st;
      for (int i = 0; i < k * 2; i++)
        if (!vis[i].second)
          for (int j = 0; !vis[i].second && j < k * 2; j++)
            if (j != i && !vis[j].second) {
              bool ok = true;
              if (!move(start, vis[i].first.side(2), st))
                ok = false;
              else if (!walk(0, st))
                ok = false;
              else if (!make_sure(vis[j].first.side(0), -1))
                ok = false;
              if (ok) {
                ans[cnt++] = std::make_pair(vis[i].first, vis[j].first);
                vis[i].second = vis[j].second = true;
              }
              undo(st);
            }
    }
    
    int main() {
      while (read()) {
        init();
        find_gate();
        make_gate_pair();
        answer();
      }
      return 0;
    }
    ```

## Bài tập

-   [Chuyên đề bài tương tác Rujia Liu's Present 7 của Liu Rujia có chất lượng rất cao, rất đáng làm thử.](https://onlinejudge.org/contests/328-9976a2e2/)
-   [P5473 [NOI2019] Cuộc thám hiểm của I-kun](https://www.luogu.com.cn/problem/P5473)
-   [P5208 [WC2019] Cửa hàng của I-kun](https://www.luogu.com.cn/problem/P5208)

## Tài liệu tham khảo và đọc thêm

-   [Dùng pipe Linux để cài đặt chức năng bài tương tác của online judge](https://www.cnblogs.com/tsreaper/p/pipe-interactive.html)
