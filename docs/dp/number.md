Bài này giới thiệu ngắn gọn về DP chữ số.

<span id="dẫn-nhập"></span>

## Dẫn nhập

Chữ số là cách tách một số theo từng vị trí như hàng đơn vị, hàng chục, hàng trăm, hàng nghìn, v.v. rồi quan tâm đến chữ số nằm ở mỗi vị trí đó. Nếu đang xét số thập phân thì mỗi chữ số nằm trong $0\sim 9$; với các hệ cơ số khác có thể suy luận tương tự như hệ thập phân.

DP chữ số dùng để giải một lớp bài toán đặc thù, thường dễ nhận ra, nhìn chung có các đặc điểm sau:

1.  Cần thống kê số lượng các số thỏa một điều kiện nào đó, tức mục tiêu cuối cùng là đếm.

2.  Sau khi biến đổi, các điều kiện này có thể được hiểu và kiểm tra bằng tư duy theo "chữ số".

3.  Đầu vào cung cấp một khoảng số, đôi khi chỉ cung cấp cận trên, làm giới hạn cho việc thống kê.

4.  Cận trên rất lớn, chẳng hạn $10^{18}$, nên duyệt vét cạn rồi kiểm tra sẽ quá thời gian.

Nguyên lý cơ bản của DP chữ số:

Xét cách con người đếm số. Cách đếm thô sơ nhất là bắt đầu từ nhỏ đến lớn, mỗi lần tăng thêm một. Nhưng với các số có nhiều chữ số, quá trình này có rất nhiều phần lặp lại. Ví dụ, quá trình đếm từ 7000 đến 7999, từ 8000 đến 8999 và từ 9000 đến 9999 rất giống nhau: ba chữ số cuối đều chạy từ 000 đến 999, chỉ khác chữ số hàng nghìn. Vì vậy, có thể gộp những quá trình này lại, đồng thời lưu các giá trị đếm phát sinh trong một mảng dùng chung. Mảng này được thiết kế trạng thái theo yêu cầu cụ thể của đề, rồi chuyển trạng thái bằng truy hồi hoặc DP.

Trong DP chữ số, thường dùng các kỹ thuật quen thuộc của bài toán đếm, chẳng hạn tách đáp án trên một khoảng thành hiệu của hai phần: $\mathit{ans}_{[l, r]} = \mathit{ans}_{[0, r]}-\mathit{ans}_{[0, l - 1]}$.

Khi đã có mảng đáp án dùng chung, bước tiếp theo là thống kê đáp án. Có thể dùng tìm kiếm có nhớ, hoặc dùng vòng lặp để truy hồi/qui hoạch động. Để thống kê không trùng và không sót tất cả đáp án không vượt quá cận trên, duyệt từng chữ số từ cao xuống thấp, xét mỗi vị trí có thể điền những chữ số nào, rồi dùng mảng đáp án dùng chung để cộng kết quả.

Tiếp theo, xét cụ thể một vài bài toán.

<span id="ví-dụ-1"></span>

## Ví dụ 1

???+ note "Ví dụ 1 [Luogu P2602 Đếm chữ số](https://www.luogu.com.cn/problem/P2602)"
    Tóm tắt đề bài: Cho hai số nguyên dương $a,b$, cần tính trong tất cả các số nguyên thuộc $[a,b]$, mỗi chữ số (digit) xuất hiện bao nhiêu lần.

<span id="cách-1"></span>

### Cách 1

<span id="giải-thích"></span>

#### Giải thích

Nhận thấy với tất cả các số đủ $i$ chữ số, số lần xuất hiện của mọi chữ số là như nhau. Do đó đặt mảng $\mathit{dp}_i$ là số lần xuất hiện của mỗi chữ số trong các số đủ $i$ chữ số; lúc này tạm thời chưa xử lý số 0 ở đầu. Có $\mathit{dp}_i=10 \times \mathit{dp}_{i−1}+10^{i−1}$. Trong đó, phần thứ nhất là đóng góp từ $i-1$ chữ số trước, phần thứ hai là đóng góp từ chữ số thứ $i$.

Khi đã có mảng $\mathit{dp}$, xét cách thống kê đáp án. Tách cận trên theo từng chữ số rồi duyệt từ cao xuống thấp. Khi không bị ép sát cận trên, các chữ số phía sau có thể chọn tùy ý. Khi đang ép sát cận trên, phần phía sau chỉ có thể lấy từ $0$ đến cận trên tương ứng; chia thành hai phần để tính đóng góp. Cuối cùng xét số 0 ở đầu: khi chữ số thứ $i$ là số 0 dẫn đầu, các vị trí từ $1$ đến $\mathit{i-1}$ cũng đều là $0$, tức đã đếm thừa đáp án của phần điền đủ $i-1$ chữ số, nên cần trừ thêm.

<span id="cài-đặt"></span>

#### Cài đặt

???+ note "Mã tham khảo"
    ```cpp
    #include <cstdio>
    using namespace std;
    constexpr int N = 15;
    using ll = long long;
    ll l, r, dp[N], mi[N];
    ll ans1[N], ans2[N];
    int a[N];
    
    void solve(ll n, ll *ans) {
      ll tmp = n;
      int len = 0;
      while (n) a[++len] = n % 10, n /= 10;
      for (int i = len; i >= 1; --i) {
        for (int j = 0; j < 10; j++) ans[j] += dp[i - 1] * a[i];
        for (int j = 0; j < a[i]; j++) ans[j] += mi[i - 1];
        tmp -= mi[i - 1] * a[i], ans[a[i]] += tmp + 1;
        ans[0] -= mi[i - 1];
      }
    }
    
    int main() {
      scanf("%lld%lld", &l, &r);
      mi[0] = 1ll;
      for (int i = 1; i <= 13; ++i) {
        dp[i] = dp[i - 1] * 10 + mi[i - 1];
        mi[i] = 10ll * mi[i - 1];
      }
      solve(r, ans1), solve(l - 1, ans2);
      for (int i = 0; i < 10; ++i) printf("%lld ", ans1[i] - ans2[i]);
      return 0;
    }
    ```

<span id="cách-2"></span>

### Cách 2

<span id="giải-thích_1"></span>

#### Giải thích

Bài này cũng có thể dùng tìm kiếm có nhớ. $\mathit{dp}_i$ biểu thị đáp án với độ dài $i$ khi không bị ép sát cận trên và không có số 0 ở đầu.

Xem chi tiết trong chú thích của mã.

<span id="quy-trình"></span>

#### Quy trình

???+ note "Mã tham khảo"
    ```cpp
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    using namespace std;
    using ll = long long;
    constexpr int N = 50005;
    ll a, b;
    ll f[15], ksm[15], p[15], now[15];
    
    ll dfs(int u, int x, bool f0,
           bool lim) {  // u là số chữ số, f0 có số 0 ở đầu không, lim có đang ép sát cận trên không
      if (!u) {
        if (f0) f0 = false;
        return 0;
      }
      if (!lim && !f0 && (~f[u])) return f[u];
      ll cnt = 0;
      int lst = lim ? p[u] : 9;
      for (int i = 0; i <= lst; i++) {  // Duyệt chữ số cần điền ở vị trí này
        if (f0 && i == 0)
          cnt += dfs(u - 1, x, 1, lim && i == lst);  // Xử lý số 0 ở đầu
        else if (i == x && lim && i == lst)
          cnt += now[u - 1] + 1 +
                 dfs(u - 1, x, 0,
                     lim && i == lst);  // Các chữ số đã duyệt phía trước đều ép sát cận trên đã cho.
        else if (i == x)
          cnt += ksm[u - 1] + dfs(u - 1, x, 0, lim && i == lst);
        else
          cnt += dfs(u - 1, x, 0, lim && i == lst);
      }
      if ((!lim) && (!f0)) f[u] = cnt;  // Chỉ ghi nhớ khi không ép sát cận trên và không có số 0 ở đầu
      return cnt;
    }
    
    ll gans(ll d, int dig) {
      int len = 0;
      memset(f, -1, sizeof(f));
      while (d) {
        p[++len] = d % 10;
        d /= 10;
        now[len] = now[len - 1] + p[len] * ksm[len - 1];
      }
      return dfs(len, dig, 1, 1);
    }
    
    int main() {
      scanf("%lld%lld", &a, &b);
      ksm[0] = 1;
      for (int i = 1; i <= 12; i++) ksm[i] = ksm[i - 1] * 10ll;
      for (int i = 0; i < 9; i++) printf("%lld ", gans(b, i) - gans(a - 1, i));
      printf("%lld\n", gans(b, 9) - gans(a - 1, 9));
      return 0;
    }
    ```

<span id="ví-dụ-2"></span>

## Ví dụ 2

???+ note "Ví dụ 2 [HDU 2089 Không có 62](https://acm.hdu.edu.cn/showproblem.php?pid=2089)"
    Tóm tắt đề bài: Đếm trong một khoảng có bao nhiêu số mà trong các chữ số không chứa 4 và cũng không chứa cặp liên tiếp 62.

<span id="giải-thích_2"></span>

### Giải thích

Với điều kiện không có 4, chỉ cần kiểm tra khi duyệt và không duyệt chữ số 4 là trạng thái đã hợp lệ, nên ràng buộc này không cần ghi nhớ. Còn với 62, vì liên quan đến hai chữ số, số cách đếm sẽ khác nhau tùy chữ số trước đó có phải là 6 hay không, nên cần dùng trạng thái để ghi lại các số phương án khác nhau. $\mathit{dp}_{\mathit{pos},\mathit{sta}}$ biểu thị trạng thái tại chữ số thứ $\mathit{pos}$, trong đó $\mathit{sta}$ cho biết chữ số trước có phải là 6 hay không. Trong bài này, $\mathit{sta}$ chỉ cần lấy hai trạng thái 0 và 1; mọi trường hợp "không phải 6" có thể xem là cùng một loại vì không ảnh hưởng đến việc đếm.

<span id="cài-đặt_1"></span>

### Cài đặt

???+ note "Mã tham khảo"
    ```cpp
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    using namespace std;
    int x, y, dp[15][3], p[50];
    
    void pre() {
      memset(dp, 0, sizeof(dp));
      dp[0][0] = 1;
      for (int i = 1; i <= 10; i++) {
        dp[i][0] = dp[i - 1][0] * 9 - dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1] + dp[i - 1][0];
      }
    }
    
    int cal(int x) {
      int cnt = 0, ans = 0, tmp = x;
      while (x) {
        p[++cnt] = x % 10;
        x /= 10;
      }
      bool flag = false;
      p[cnt + 1] = 0;
      for (int i = cnt; i; i--) {  // Duyệt các chữ số từ cao xuống thấp
        ans += p[i] * dp[i - 1][2];
        if (flag)
          ans += p[i] * dp[i - 1][0];
        else {
          if (p[i] > 4) ans += dp[i - 1][0];
          if (p[i] > 6) ans += dp[i - 1][1];
          if (p[i] > 2 && p[i + 1] == 6) ans += dp[i][1];
          if (p[i] == 4 || (p[i] == 2 && p[i + 1] == 6)) flag = true;
        }
      }
      return tmp - ans;
    }
    
    int main() {
      pre();
      while (~scanf("%d%d", &x, &y)) {
        if (!x && !y) break;
        if (x > y) swap(x, y);
        printf("%d\n", cal(y + 1) - cal(x));
      }
      return 0;
    }
    ```

<span id="ví-dụ-3"></span>

## Ví dụ 3

???+ note "Ví dụ 3 [SCOI2009 Số windy](https://loj.ac/problem/10165)"
    Tóm tắt đề bài: Cho một khoảng $[l,r]$, cần tính số lượng các số trong đó thỏa điều kiện **không có số 0 ở đầu và hai chữ số kề nhau chênh lệch ít nhất $2$**.

<span id="giải-thích_3"></span>

### Giải thích

Trước hết, chuyển bài toán sang một dạng đơn giản hơn. Đặt $\mathit{ans}_i$ là số lượng các số thỏa điều kiện trong khoảng $[1,i]$, khi đó đáp án cần tìm là $\mathit{ans}_r-\mathit{ans}_{l-1}$.

Với một số nhỏ hơn $n$, nếu xét từ cao xuống thấp thì sẽ tồn tại một vị trí nào đó mà chữ số tại vị trí này nhỏ hơn chữ số tương ứng của $n$. Tất cả các vị trí trước đó đều bằng các chữ số tương ứng của $n$.

Dựa vào tính chất này, có thể định nghĩa $f(i,st,op)$ là số lượng các số khi vị trí hiện tại cần xét là chữ số thứ $i$ tính từ cao xuống thấp, trạng thái hiện tại của tiền tố là $st$, và quan hệ lớn nhỏ giữa tiền tố với số đang xét là $op$ ($op=1$ nghĩa là bằng, $op=0$ nghĩa là nhỏ hơn). Trong bài này, trạng thái của tiền tố chính là giá trị của chữ số trước đó, vì các chữ số mà vị trí hiện tại không được chọn chỉ phụ thuộc vào chữ số trước. Trong các bài khác, giá trị này có thể là tổng chữ số của tiền tố, $\gcd$ của tất cả chữ số trong tiền tố, phần dư của tiền tố theo một môđun nào đó, hoặc cũng có thể là tổ hợp của hai hay nhiều loại trạng thái.

Viết **phương trình chuyển trạng thái**: $f(i,st,op)=\sum_{k=1}^{\mathit{maxx}} f(i+1,k,op=1~ \text{và}~ k=\mathit{maxx} )\quad (|\mathit{st}-k|\ge 2)$

Trong công thức này, $k$ là giá trị của chữ số tiếp theo đang được duyệt, còn $\mathit{maxx}$ là chữ số lớn nhất hiện có thể chọn. Nếu $\mathit{op}=1$, giá trị chọn ở vị trí này không được lớn hơn chữ số tương ứng của số đang xét; nếu không thì không có giới hạn này.

Nhận thấy dù trạng thái tiền tố đã chọn có thể khác nhau, miễn ba tham số của $f$ giống nhau thì đáp án sẽ giống nhau. Để tránh tính cùng một đáp án nhiều lần, có thể dùng [tìm kiếm có nhớ](./memo.md).

<span id="cài-đặt_2"></span>

### Cài đặt

???+ note "Mã tham khảo"
    ```cpp
    int dfs(int x, int st, int op)  // op=1 =; op=0 <
    {
      if (!x) return 1;
      if (!op && ~f[x][st]) return f[x][st];
      int maxx = op ? dim[x] : 9, ret = 0;
      for (int i = 0; i <= maxx; i++) {
        if (abs(st - i) < 2) continue;
        if (st == 11 && i == 0)
          ret += dfs(x - 1, 11, op & (i == maxx));
        else
          ret += dfs(x - 1, i, op & (i == maxx));
      }
      if (!op) f[x][st] = ret;
      return ret;
    }
    
    int solve(int x) {
      memset(f, -1, sizeof f);
      dim.clear();
      dim.push_back(-1);
      int t = x;
      while (x) {
        dim.push_back(x % 10);
        x /= 10;
      }
      return dfs(dim.size() - 1, 11, 1);
    }
    ```

<span id="ví-dụ-4"></span>

## Ví dụ 4

???+ note "Ví dụ 4 [SPOJMYQ10](https://www.spoj.com/problems/MYQ10/en/)"
    Tóm tắt đề bài: Nếu viết tay tất cả các số nguyên trong $[n,m]$, có bao nhiêu số nhìn giống hệt chính nó trong gương? ($n,m<10^{44}, T<10^5$)

<span id="giải-thích_4"></span>

### Giải thích

Lưu ý: do phần này đang xét ảnh trong gương, chỉ có ảnh gương của $0,1,8$ là chính chúng. Vì vậy, "giống hệt" trong ngữ cảnh này không phải là xâu đối xứng theo nghĩa truyền thống, mà là xâu đối xứng chỉ gồm $0,1,8$.

Trước hết, trong quá trình DP chữ số, chỉ có $0,1,8$ được chọn.

Tiếp theo, vì giá trị vượt quá phạm vi của `long long`, công thức $[n,m]=[1,m]-[1,n-1]$ không còn phù hợp do so sánh số lớn khá rườm rà. Thay vào đó, cần kiểm tra riêng xem $n$ có hợp lệ hay không, từ đó có: $[n,m]=[1,m]-[1,n]+\mathrm{check}(n)$.

Vấn đề ảnh gương đã được xử lý, còn làm sao kiểm tra đối xứng?

Cần dùng một mảng nhỏ để ghi lại các giá trị trước đó. Khi chưa đi quá nửa độ dài, chỉ cần không vượt cận trên là được; khi đã đi quá nửa độ dài, còn cần kiểm tra xem chữ số hiện tại có bằng chữ số ở vị trí "đối xứng qua gương" hay không.

Cần lưu ý thêm rằng phần ghi nhớ của bài này không được dùng `memset`, nếu không sẽ dẫn đến quá thời gian.

<span id="cài-đặt_3"></span>

### Cài đặt

???+ note "Mã tham khảo"
    ```cpp
    int check(char cc[]) {  // Trường hợp đặc biệt của n
      int strc = strlen(cc);
      for (int i = 0; i < strc; ++i) {
        if (!(cc[i] == cc[strc - i - 1] &&
              (cc[i] == '1' || cc[i] == '8' || cc[i] == '0')))
          return 0ll;
      }
      return 1ll;
    }
    
    // now: vị trí hiện tại, eff: số chữ số hiệu lực, fulc: có ép sát cận trên không, ful0: có toàn số 0 không
    int dfs(int now, int eff, bool ful0, bool fulc) {
      if (now == 0) return 1ll;
      if (!fulc && f[now][eff][ful0] != -1)  // Ghi nhớ
        return f[now][eff][ful0];
    
      int res = 0, maxk = fulc ? dig[now] : 9;
      for (int i = 0; i <= maxk; ++i) {
        if (i != 0 && i != 1 && i != 8) continue;
        b[now] = i;
        if (ful0 && i == 0)  // Toàn là số 0 ở đầu
          res += dfs(now - 1, eff - 1, 1, 0);
        else if (now > eff / 2)                                  // Chưa đi quá nửa độ dài
          res += dfs(now - 1, eff, 0, fulc && (dig[now] == i));  // Đã đi quá nửa độ dài
        else if (b[now] == b[eff - now + 1])
          res += dfs(now - 1, eff, 0, fulc && (dig[now] == i));
      }
      if (!fulc) f[now][eff][ful0] = res;
      return res;
    }
    
    char cc1[100], cc2[100];
    int strc, ansm, ansn;
    
    int get(char cc[]) {  // Xử lý đóng gói
      strc = strlen(cc);
      for (int i = 0; i < strc; ++i) dig[strc - i] = cc[i] - '0';
      return dfs(strc, strc, 1, 1);
    }
    
    scanf("%s%s", cc1, cc2);
    printf("%lld\n", get(cc2) - get(cc1) + check(cc1));
    ```

<span id="ví-dụ-5"></span>

## Ví dụ 5

???+ note "Ví dụ 5 [P3311 Đếm số](https://www.luogu.com.cn/problem/P3311)"
    Đề bài: Một số nguyên dương $x$ được gọi là số may mắn khi và chỉ khi biểu diễn thập phân của nó không chứa bất kỳ phần tử nào trong tập xâu chữ số $S$ làm xâu con. Ví dụ, khi $S = \{22, 333, 0233\}$, $233233$ là số may mắn, còn $23332333$, $2023320233$, $32233223$ không phải là số may mắn. Cho $n$ và $S$, cần tính số lượng số may mắn không lớn hơn $n$. Đáp án lấy theo môđun $10^9 + 7$.
    
    $1 \leq n<10^{1201}, 1 \leq m \leq 100, 1 \leq \sum_{i = 1}^m |s_i| \leq 1500, \min_{i = 1}^m |s_i| \geq 1$, trong đó $|s_i|$ biểu thị độ dài của xâu $s_i$. $n$ không có số 0 ở đầu, nhưng $s_i$ có thể có số 0 ở đầu.

<span id="giải-thích_5"></span>

### Giải thích

Đọc đề sẽ thấy nếu xem số như một xâu, bài toán cần thực hiện ghép nhiều mẫu, nên rất tự nhiên nghĩ đến automaton AC. Trong DP chữ số thông thường, duyệt chữ số từ cao xuống thấp rồi duyệt mỗi vị trí điền gì. Ở bài này, cũng có thể chuyển thành duyệt số vị trí đã điền, sau đó duyệt hiện đang dừng ở nút nào trên automaton AC, rồi chuyển từ nút hiện tại sang nút con của nó trên automaton AC.

Đặt $f(i,j,0/1)$ biểu thị trạng thái khi từ cao xuống thấp đã điền $i$ chữ số, tức đã đi qua $i$ cạnh trên automaton AC; hiện đang dừng ở nút có chỉ số $j$; và hiện có đang ép sát cận trên hay không.

Với điều kiện "không chứa" trong đề, chỉ cần đánh dấu các nút kết thúc của mọi xâu mẫu trên automaton AC; trong quá trình DP, hễ gặp những nút kết thúc này thì bỏ qua.

Chuyển trạng thái không khó nghĩ, xem chi tiết trong phần hàm chính của mã.

<span id="cài-đặt_4"></span>

### Cài đặt

???+ note "Mã tham khảo"
    ```cpp
    #include <cstdio>
    #include <cstring>
    #include <queue>
    using namespace std;
    using ll = long long;
    constexpr int N = 1505;
    constexpr int mod = 1000000007;
    int n, m;
    char s[N], c[N];
    int ch[N][10], fail[N], ed[N], tot, len;
    
    void insert() {
      int now = 0;
      int L = strlen(s);
      for (int i = 0; i < L; ++i) {
        if (!ch[now][s[i] - '0']) ch[now][s[i] - '0'] = ++tot;
        now = ch[now][s[i] - '0'];
      }
      ed[now] = 1;
    }
    
    queue<int> q;
    
    void build() {
      for (int i = 0; i < 10; ++i)
        if (ch[0][i]) q.push(ch[0][i]);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 10; ++i) {
          if (ch[u][i]) {
            fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]),
            ed[ch[u][i]] |= ed[fail[ch[u][i]]];
          } else
            ch[u][i] = ch[fail[u]][i];
        }
      }
      ch[0][0] = 0;
    }
    
    ll f[N][N][2], ans;
    
    void add(ll &x, ll y) { x = (x + y) % mod; }
    
    int main() {
      scanf("%s", c);
      n = strlen(c);
      scanf("%d", &m);
      for (int i = 1; i <= m; ++i) scanf("%s", s), insert();
      build();
      f[0][0][1] = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= tot; ++j) {
          if (ed[j]) continue;
          for (int k = 0; k < 10; ++k) {
            if (ed[ch[j][k]]) continue;
            add(f[i + 1][ch[j][k]][0], f[i][j][0]);
            if (k < c[i] - '0') add(f[i + 1][ch[j][k]][0], f[i][j][1]);
            if (k == c[i] - '0') add(f[i + 1][ch[j][k]][1], f[i][j][1]);
          }
        }
      }
      for (int j = 0; j <= tot; ++j) {
        if (ed[j]) continue;
        add(ans, f[n][j][0]);
        add(ans, f[n][j][1]);
      }
      printf("%lld\n", ans - 1);
      return 0;
    }
    ```

Bài này rất hữu ích để hiểu nguyên lý của DP chữ số.

<span id="bài-tập"></span>

## Bài tập

[Ahoi2009 self Phân bố đồng loại](https://www.luogu.com.cn/problem/P4127)

[Luogu P3413 SAC#1 - Số dễ thương](https://www.luogu.com.cn/problem/P3413)

[HDU 6148 Số thung lũng](https://acm.hdu.edu.cn/showproblem.php?pid=6148)

[CF55D Các số đẹp](http://codeforces.com/problemset/problem/55/D)

[CF628D Các số ma thuật](http://codeforces.com/problemset/problem/628/D)
