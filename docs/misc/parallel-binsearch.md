## Mở đầu

Trong các kỳ thi lập trình thi đấu, có một số bài có thể giải bằng chặt nhị phân. Tuy nhiên, khi dạng bài này có nhiều truy vấn và việc chặt nhị phân riêng cho từng truy vấn có thể dẫn đến TLE, nên dùng chặt nhị phân tổng thể. Ý tưởng chính của chặt nhị phân tổng thể là xử lý nhiều truy vấn cùng lúc. Vì vậy, đây là một thuật toán ngoại tuyến. Thuật ngữ này cũng thường được gọi là chặt nhị phân song song.

Những bài có thể giải bằng chặt nhị phân tổng thể cần thỏa mãn các tính chất sau[^ref1]:

1.  Đáp án của truy vấn có thể chặt nhị phân được.
2.  **Đóng góp của các phép sửa đổi vào việc kiểm tra đáp án độc lập với nhau**, hiệu quả của các phép sửa đổi không ảnh hưởng lẫn nhau.
3.  Nếu một phép sửa đổi có đóng góp vào việc kiểm tra đáp án, đóng góp đó là một giá trị xác định và không phụ thuộc vào tiêu chuẩn kiểm tra.
4.  Các đóng góp thỏa mãn tính giao hoán, tính kết hợp và có thể cộng dồn được.
5.  Bài toán cho phép dùng thuật toán ngoại tuyến.

## Giải thích

Ký hiệu $[l,r]$ là miền giá trị của đáp án, $[L,R]$ là miền xác định của đáp án. Nói cách khác, khi tìm đáp án, chỉ xét các thao tác và truy vấn có chỉ số nằm trong đoạn $[L,R]$, và đáp án của các truy vấn này nằm trong $[l,r]$.

-   Trước hết, lưu tất cả thao tác vào một mảng **theo thứ tự thời gian**, rồi bắt đầu chia để trị.
-   Ở mỗi tầng chia để trị, dùng một cấu trúc dữ liệu, thường là cây Fenwick, để thống kê quan hệ giữa đáp án của truy vấn hiện tại và $mid$.
-   Dựa trên quan hệ giữa kết quả truy vấn được và $mid$, tức nhỏ hơn hoặc bằng $mid$ hay lớn hơn $mid$, chia dãy thao tác hiện đang xử lý thành hai phần $q1$ và $q2$, rồi đệ quy xử lý từng phần.
-   Khi $l=r$, đáp án đã được xác định, chỉ cần ghi lại đáp án rồi trả về.

Cần lưu ý rằng trong quá trình chặt nhị phân tổng thể, nếu miền giá trị đang xử lý là $[l,r]$, thì thuật toán sẽ xử lý các truy vấn có phạm vi đáp án cuối cùng không nằm trong $[l,r]$ ở thời điểm khác.

## Quy trình

???+ tip "Lưu ý"
    1.  Để dễ đọc, mã trong bài có thể không dùng đúng phong cách thường gặp trong thi đấu thực tế.
    2.  Nếu thấy một đoạn mã nào đó khó hiểu, nên tham khảo trước phần giải thích của các bài trước đó; để tiết kiệm độ dài, những nội dung đã giải thích sẽ không được lặp lại.

Bắt đầu từ chặt nhị phân thông thường:

### Truy vấn phần tử nhỏ thứ k toàn cục

???+ note "Bài 1"
    Truy vấn số nhỏ thứ $k$ trong một dãy số.

??? note "Lời giải"
    Có thể sắp xếp trực tiếp. Nếu dùng chặt nhị phân thì sao? Khi đó, dùng cấu trúc dữ liệu để ghi nhận trong mỗi khoảng giá trị có bao nhiêu số, rồi dùng chặt nhị phân để đoán và dùng cấu trúc dữ liệu để kiểm tra.

???+ note "Bài 2"
    Trong một dãy số, truy vấn nhiều lần phần tử nhỏ thứ $k$.

??? note "Lời giải"
    Có thể thực hiện một lần chặt nhị phân cho mỗi truy vấn. Tuy nhiên, cũng có thể đưa tất cả truy vấn vào cùng một quá trình chặt nhị phân.
    
    Trước hết xét bản chất của chặt nhị phân: giả sử cần đoán một số trong $[l,r]$, sau khi đoán sẽ biết giá trị vừa đoán lớn hơn, nhỏ hơn hay đúng. Có thể liệt kê từ $l$ đến $r$, nhưng cách tốt hơn là chặt nhị phân: đoán đáp án là $m = \lfloor\frac{l + r}{2}\rfloor$, sau đó kiểm tra tính đúng đắn của $m$ rồi điều chỉnh biên. Như vậy, độ phức tạp cho mỗi truy vấn là $O(\log n)$. Nếu có $q$ truy vấn, độ phức tạp thời gian là $O(q\log n)$.
    
    Quay lại với tất cả truy vấn hiện tại, có thể đoán đáp án của mọi truy vấn đều là $mid$, rồi lần lượt kiểm tra đáp án của mỗi truy vấn phải nhỏ hơn hoặc bằng $mid$ hay lớn hơn $mid$, sau đó chia truy vấn thành hai phần, không lớn hơn và lớn hơn. Với mỗi phần, tiếp tục chặt nhị phân. Lưu ý: nếu đáp án của một truy vấn lớn hơn $mid$, trước khi chuyển nó sang bên phải cần cập nhật $k$ của nó. Cụ thể, nếu trong dãy hiện tại có $t$ số nhỏ hơn hoặc bằng $mid$, thì sau khi chia, truy vấn thực chất là hỏi số nhỏ thứ $k - t$ trong khoảng bên phải. Nếu một phần đã có $l = r$, quá trình chặt nhị phân của phần đó kết thúc. Dựa trên kiến thức về cây đoạn, mỗi lần chia toàn bộ khoảng mà đáp án có thể nằm trong đó $[1,n]$, giả sử đã rời rạc hóa, thành một số phần. Thuật toán thực hiện cách chia này tổng cộng $O(\log n)$ lần, và mỗi lần chia sẽ xử lý toàn bộ dãy thao tác một lần. Nếu độ phức tạp để xử lý toàn bộ dãy và hỗ trợ các truy vấn tương ứng là $O(T)$, thì độ phức tạp thời gian của chặt nhị phân tổng thể là $O(T\log n)$.

??? note "Mã tham khảo"
    ```cpp
    struct Query {
      int id, k;  // số hiệu của truy vấn này, k của truy vấn này
    };
    
    int ans[N], a[N];  // ans[i] là đáp án của truy vấn có số hiệu i, a là dãy gốc
    int val[N], cnt[N];  // sau rời rạc hóa, ghi giá trị tương ứng và số lần xuất hiện
    
    // trả về số phần tử trong dãy gốc có giá trị thuộc [l,r]
    int check(int l, int r) {
      int res = 0;
      for (int i = l; i <= r; i++) {
        res += cnt[i];
      }
      return res;
    }
    
    // chặt nhị phân tổng thể
    void solve(int l, int r, vector<Query> q) {
      int m = (l + r) / 2;
      if (l == r) {
        for (unsigned i = 0; i < q.size(); i++) ans[q[i].id] = val[l];
        return;
      }
      vector<Query> q1, q2;
      int t = check(l, m);
      for (unsigned i = 0; i < q.size(); i++) {
        if (q[i].k <= t)
          q1.push_back(q[i]);
        else
          q[i].k -= t, q2.push_back(q[i]);
      }
      solve(l, m, q1), solve(m + 1, r, q2);
      return;
    }
    ```

### Truy vấn phần tử nhỏ thứ k trên đoạn

???+ note "Bài 3"
    Trong một dãy số, truy vấn nhiều lần phần tử nhỏ thứ $k$ trên một đoạn.

??? note "Lời giải"
    Khi có truy vấn trên một đoạn cho trước, nếu tiếp tục chặt nhị phân theo cách trước thì độ phức tạp thời gian của hàm `check` sẽ bùng nổ. Vẫn xét quan hệ giữa truy vấn và trung điểm miền giá trị $m$: nếu trong đoạn truy vấn có $t$ số nhỏ hơn hoặc bằng $m$, và truy vấn hỏi số nhỏ thứ $k$ trong đoạn, thì khi $k \leq t$, đáp án phải nhỏ hơn hoặc bằng $m$; ngược lại, đáp án phải lớn hơn $m$. Cần xử lý biên cẩn thận. Lúc này cần ghi nhận số lượng phần tử trong một đoạn nhỏ hơn hoặc bằng một số được chỉ định, tức cộng điểm và truy vấn tổng đoạn, có thể xử lý nhanh bằng cây Fenwick. Để tăng hiệu quả, chỉ thống kê các số trong dãy có giá trị nằm trong khoảng miền giá trị $[l,r]$. Tức là trước khi đệ quy tiếp, không chỉ chia truy vấn mà còn chia các số hiện đang xử lý thành hai nửa theo miền giá trị.

??? note "Mã tham khảo (phần chính)"
    ```cpp
    struct Num {
      int p, x;
    };  // số ở vị trí p trong dãy có giá trị x
    
    struct Query {
      int l, r, k, id;
    };  // truy vấn có số hiệu id, hỏi số nhỏ thứ k trong [l,r]
    
    int ans[N];
    void add(int p, int x);  // cây Fenwick, cộng x tại vị trí p
    int query(int p);        // cây Fenwick, tính tổng [1,p]
    void clear();            // cây Fenwick, xóa rỗng
    
    void solve(int l, int r, vector<Num> a, vector<Query> q)
    // a chứa các số trong dãy đã cho có giá trị thuộc miền giá trị [l,r]
    {
      int m = (l + r) / 2;
      if (l == r) {
        for (unsigned i = 0; i < q.size(); i++) ans[q[i].id] = l;
        return;
      }
      vector<Num> a1, a2;
      vector<Query> q1, q2;
      for (unsigned i = 0; i < a.size(); i++)
        if (a[i].x <= m)
          a1.push_back(a[i]), add(a[i].p, 1);
        else
          a2.push_back(a[i]);
      for (unsigned i = 0; i < q.size(); i++) {
        int t = query(q[i].r) - query(q[i].l - 1);
        if (q[i].k <= t)
          q1.push_back(q[i]);
        else
          q[i].k -= t, q2.push_back(q[i]);
      }
      clear();
      solve(l, m, a1, q1), solve(m + 1, r, a2, q2);
      return;
    }
    ```

Dưới đây là cách viết thiên về phong cách thi đấu dùng chặt nhị phân tổng thể cho bài [Mẫu: Cây đoạn bền vững 2](https://www.luogu.com.cn/problem/P3834).

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/parallel-binsearch/parallel-binsearch_1.cpp"
    ```

### Truy vấn phần tử nhỏ thứ k trên đoạn có sửa đổi

???+ note "Bài 4 ([Xếp hạng động](https://www.luogu.com.cn/problem/P2617))"
    Cho một dãy số, cần hỗ trợ sửa đổi tại một điểm và truy vấn phần tử nhỏ thứ $k$ trên đoạn.

??? note "Lời giải"
    Có thể hiểu trực tiếp một thao tác sửa đổi là xóa một số khỏi dãy gốc rồi thêm một số mới. Để tiện, gọi chung truy vấn và sửa đổi là "thao tác". Vì các thao tác phía sau phụ thuộc vào các thao tác trước đó, không thể tách việc thống kê và xử lý truy vấn như Bài 3. Do đó, có thể lưu tất cả thao tác vào một mảng, dùng nhãn để phân biệt loại, rồi lần lượt xử lý từng thao tác. Để tiện xử lý cây Fenwick, thao tác sửa đổi có thể tách thành thao tác xóa và thao tác chèn.
    
    **Tối ưu**
    
    1.  Nhận thấy mỗi lần phân loại thao tác chỉ thay đổi thứ tự thao tác, nên có thể thao tác trực tiếp trên mảng gốc. Khi cài đặt cụ thể, trong lúc chặt nhị phân, thay các mảng $q, a$ ghi thao tác bằng một mảng toàn cục lớn, và thông tin được ghi khi chặt nhị phân chuyển thành $L, R$, tức đoạn nào trên mảng toàn cục là các thao tác hiện đang xử lý. Dùng mảng tạm để ghi tình trạng phân loại hiện tại, rồi trước khi đệ quy tiếp thì ghi thông tin từ mảng tạm trở lại mảng gốc.
    2.  Nếu xóa rỗng cây Fenwick mỗi lần sẽ làm độ phức tạp thời gian bùng nổ. Có thể dùng cách ghi lại các vị trí được sửa đổi mỗi khi dùng cây Fenwick, điều này đã được mảng tạm nêu ở mục 1 thực hiện, rồi sau khi thao tác lần này kết thúc, cộng $-1$ tại vị trí gốc để xóa nhanh.
    3.  Các thao tác khởi tạo dãy ban đầu có thể giản lược thành thao tác chèn.

??? note "Mã tham khảo (phần chính)"
    ```cpp
    struct Opt {
      int x, y, k, type, id;
      // Với truy vấn, type = 1; x, y là biên trái và phải của đoạn;
      // k biểu thị truy vấn phần tử nhỏ thứ k.
      // Với sửa đổi, type = 0; x là vị trí sửa đổi; y là giá trị sau sửa đổi;
      // k biểu thị thao tác hiện tại là chèn (1) hay xóa (-1), dùng khi cập nhật cây Fenwick.
      // id ghi số hiệu ban đầu của mỗi thao tác, vì thứ tự thao tác bị xáo trộn khi chặt nhị phân.
    };
    
    Opt q[N], q1[N], q2[N];
    // q là tất cả thao tác.
    // Trong quá trình chặt nhị phân, thao tác được chia sang trái lưu vào q1,
    // thao tác được chia sang phải lưu vào q2.
    int ans[N];
    void add(int p, int x);
    int query(int p);  // hàm cây Fenwick, ý nghĩa xem Bài 3
    
    void solve(int l, int r, int L, int R)
    // miền giá trị hiện tại là [l,r], đoạn thao tác đang xử lý là [L,R]
    {
      if (l > r || L > R) return;
      int cnt1 = 0, cnt2 = 0, m = (l + r) / 2;
      // cnt1, cnt2 lần lượt là số thao tác được chia sang trái và sang phải
      if (l == r) {
        for (int i = L; i <= R; i++)
          if (q[i].type == 1) ans[q[i].id] = l;
        return;
      }
      for (int i = L; i <= R; i++)
        if (q[i].type == 1) {  // là truy vấn: phân loại
          int t = query(q[i].y) - query(q[i].x - 1);
          if (q[i].k <= t)
            q1[++cnt1] = q[i];
          else
            q[i].k -= t, q2[++cnt2] = q[i];
        } else
          // là sửa đổi: cập nhật cây Fenwick và phân loại
          if (q[i].y <= m)
            add(q[i].x, q[i].k), q1[++cnt1] = q[i];
          else
            q2[++cnt2] = q[i];
      for (int i = 1; i <= cnt1; i++)
        if (q1[i].type == 0) add(q1[i].x, -q1[i].k);  // xóa rỗng cây Fenwick
      for (int i = 1; i <= cnt1; i++) q[L + i - 1] = q1[i];
      for (int i = 1; i <= cnt2; i++)
        q[L + cnt1 + i - 1] = q2[i];  // gộp phần tử trong mảng tạm về mảng gốc
      solve(l, m, L, L + cnt1 - 1), solve(m + 1, r, L + cnt1, R);
      return;
    }
    ```

### Tối ưu cho dãy tĩnh

???+ note "Bài 5 ([Mẫu: Cây đoạn bền vững 2](https://www.luogu.com.cn/problem/P3834))"
    Cho một dãy, truy vấn phần tử nhỏ thứ $k$ trên đoạn.

??? note "Lời giải"
    Cả cây lồng cây và chặt nhị phân tổng thể khi cài đặt bài toán phần tử nhỏ thứ $k$ trên đoạn có sửa đổi đều có độ phức tạp $O(n \log^2 n)$. Nhưng bài toán phần tử nhỏ thứ $k$ trên đoạn tĩnh có thể giải bằng cây đoạn bền vững trong độ phức tạp thời gian $O(n \log n)$, trong khi hầu hết mã chặt nhị phân tổng thể cho bài toán phần tử nhỏ thứ $k$ trên đoạn tĩnh đều có độ phức tạp $O(n \log^2 n)$, nên có nguy cơ TLE khi phạm vi dữ liệu lớn. Phần này mặc định miền giá trị cùng bậc với độ dài dãy; nếu miền giá trị và độ dài dãy khác bậc, có thể dùng rời rạc hóa để chuyển về trường hợp cùng bậc.
    
    **Tối ưu**
    
    1.  Trong mỗi vòng chia, nếu trong dãy hiện tại có $t$ số nhỏ hơn hoặc bằng $mid$, thì sau khi chia, truy vấn thực chất là hỏi số nhỏ thứ $k - t$ trong khoảng bên phải. Vì vậy các truy vấn được chia sang khoảng phải đã bị sửa đổi. Nếu miền giá trị ban đầu của đáp án là $[L,R]$, và miền giá trị đáp án trong một lần chia nào đó là $[l,r]$, thì với các truy vấn tham gia lần chia này, ảnh hưởng của mọi giá trị trong $[L,l)$ lên chúng đã bị loại bỏ từ trước.
    2.  Vì cần để mỗi vòng chia chỉ liên quan đến miền giá trị đáp án hiện tại $[l,r]$, cây Fenwick phải được nạp và xóa nhiều lần.
    
    Nếu việc chia không chỉ liên quan đến miền giá trị đáp án hiện tại thì sao?
    
    Từ đó có thể thu được một cách tối ưu liên quan đến dãy toàn cục: duy trì một con trỏ $pos$ để theo dõi $mid$ của mỗi vòng chia, tức tâm chia để trị, đặt chỉ số tương ứng của mọi phần tử $\leq pos$ thành $1$ trong cây Fenwick, còn các vị trí khác trong cây Fenwick đặt thành $0$. Trước mỗi lần chia, di chuyển $pos$ và cập nhật cây Fenwick. Số lần con trỏ $pos$ di chuyển cùng bậc với $n \log n$. Khi chia, với mỗi truy vấn, truy vấn giá trị của đoạn tương ứng trong cây Fenwick; nếu thỏa mãn thì chia sang khoảng trái, ngược lại chia sang khoảng phải, **không cần sửa đổi thông tin truy vấn**.
    
    Vì cần theo dõi tâm chia để trị, phải cho $pos$ cập nhật cây Fenwick chính xác. Trước khi chặt nhị phân tổng thể, sắp xếp dãy theo giá trị phần tử và ghi lại chỉ số tương ứng của từng phần tử; khi con trỏ di chuyển, sửa đổi chỉ số tương ứng trong cây Fenwick. Với phần lớn các bài **có thể giải bằng chặt nhị phân tổng thể và không có sửa đổi**, đều có thể áp dụng tối ưu này để giảm mạnh số lần sử dụng cấu trúc dữ liệu.
    
    Nhờ giảm rất nhiều thao tác nạp và xóa cây Fenwick, áp dụng tối ưu này thường cải thiện rõ rệt hiệu quả của chặt nhị phân tổng thể, dù chỉ là tối ưu hằng số. Đối với bài toán giá trị nhỏ thứ $k$ trên đoạn tĩnh, hiệu quả hoàn toàn không kém cây đoạn bền vững có độ phức tạp thời gian tốt hơn. Ngoài ra, bài toán giá trị nhỏ thứ $k$ trên đoạn tĩnh cũng có cài đặt chặt nhị phân tổng thể với độ phức tạp thời gian $O(n \log n)$.

??? note "Mã tham khảo (phần chính)"
    ```cpp
    struct Query {
      int i, l, r, k;
    };  // truy vấn thứ i hỏi giá trị nhỏ thứ k trong đoạn [l,r]
    
    Query s[200005], t1[200005], t2[200005];
    int n, m, cnt, pos, p[200005], ans[200005];
    pair<int, int> a[200005];
    
    void add(int x, int y);  // cây Fenwick, cộng y tại vị trí x
    int sum(int x);          // cây Fenwick, tổng tiền tố [1,x]
    
    // các truy vấn hiện đang xử lý là [l,r], miền giá trị đáp án là [ql,qr]
    void overall_binary(int l, int r, int ql, int qr) {
      if (l > r) return;
      if (ql == qr) {
        for (int i = l; i <= r; i++) ans[s[i].i] = ql;
        return;
      }
      int cnt1 = 0, cnt2 = 0, mid = (ql + qr) >> 1;
      // theo dõi tâm chia để trị, xem như các giá trị trong [1,pos] đã được nạp vào cây Fenwick
      while (pos <= n - 1 && a[pos + 1].first <= mid)
        add(a[pos + 1].second, 1), ++pos;
      while (pos >= 1 && a[pos].first > mid) add(a[pos].second, -1), --pos;
    
      for (int i = l; i <= r; i++) {
        int now = sum(s[i].r) - sum(s[i].l - 1);
        if (s[i].k <= now)
          t1[++cnt1] = s[i];
        else
          t2[++cnt2] = s[i];  // lưu ý: không nên sửa đổi thông tin truy vấn
      }
      for (int i = 1; i <= cnt1; i++) s[l + i - 1] = t1[i];
      for (int i = 1; i <= cnt2; i++) s[l + cnt1 + i - 1] = t2[i];
    
      overall_binary(l, l + cnt1 - 1, ql, mid);
      overall_binary(l + cnt1, r, mid + 1, qr);
    }
    
    int main() {
      scanf("%d%d", &n, &m);
      for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
        p[++cnt] = a[i].first;
      }
      sort(a + 1, a + n + 1);  // sắp xếp dãy và rời rạc hóa
      sort(p + 1, p + n + 1);
      cnt = unique(p + 1, p + n + 1) - p - 1;
      for (int i = 1; i <= n; i++)
        a[i].first = lower_bound(p + 1, p + cnt + 1, a[i].first) - p;
      // lược bỏ phần đọc truy vấn
      overall_binary(1, m, 1, cnt);
      for (int i = 1; i <= n; i++) printf("%d\n", p[ans[i]]);
      return 0;
    }
    ```

### Tiền nhiệm và kế nhiệm trên đoạn

???+ note "Bài 6"
    Trong một dãy số, truy vấn nhiều lần tiền nhiệm của $k$ trong một đoạn, tức số lớn nhất nhỏ hơn nghiêm ngặt $k$, hoặc kế nhiệm, tức số nhỏ nhất lớn hơn nghiêm ngặt $k$. Bảo đảm tồn tại số như vậy.

??? note "Lời giải"
    Lấy tiền nhiệm làm ví dụ. Cách dùng cấu trúc dữ liệu để giải dạng bài này thường là trước tiên truy vấn trong đoạn có bao nhiêu số nhỏ hơn nghiêm ngặt $k$, giả sử số lượng là $x$, rồi truy vấn số nhỏ thứ $x$ trong đoạn. Với kế nhiệm, truy vấn trong đoạn có bao nhiêu số không lớn hơn $k$, số lượng là $x$, rồi truy vấn số nhỏ thứ $x+1$ trong đoạn.
    
    Xét dùng chặt nhị phân tổng thể để giải bài này: chặt nhị phân tổng thể là một thuật toán ngoại tuyến hiệu quả để tìm phần tử nhỏ thứ $k$ trên đoạn, còn [chia để trị CDQ](./cdq-divide.md) có thể tính ngoại tuyến hiệu quả hạng trong một đoạn. Chạy chia để trị CDQ một lần để tìm hạng, sau đó có thể dùng chặt nhị phân tổng thể để thu được tiền nhiệm và kế nhiệm trong đoạn.
    
    Bài này cũng có thể giải ngoại tuyến một lần bằng chia để trị CDQ lồng cây đoạn, nhưng hiệu quả kém xa việc chạy hai lần: chia để trị CDQ rồi chặt nhị phân tổng thể.

### Xây dựng dãy có tính đơn điệu

???+ note "Bài 7 ([Dãy số](https://www.luogu.com.cn/problem/P4597))"
    Cho một dãy, mỗi thao tác có thể tăng một số nào đó thêm $1$ hoặc giảm đi $1$. Yêu cầu biến dãy thành không giảm đơn điệu, và dãy sau khi sửa chỉ được chứa các số đã xuất hiện trong dãy trước khi sửa. Cần xuất ra số thao tác ít nhất.

??? note "Lời giải"
    Dạng bài này cũng có thể giải bằng quy hoạch động hoặc tham lam có hối tiếc.
    
    Với điều kiện tối thiểu hóa số thao tác, luôn tồn tại một phương án sao cho mỗi số trong dãy cuối cùng đều là một số đã tồn tại trong dãy trước khi sửa. Kết luận này có thể chứng minh bằng quy nạp toán học. Vì bài không yêu cầu thông tin của dãy cuối cùng, bài toán chuyển thành tìm số thao tác ít nhất.
    
    Vì yêu cầu dãy cuối cùng không giảm đơn điệu, có thể dùng chặt nhị phân tổng thể. Mỗi vòng chặt nhị phân tổng thể kiểm tra miền giá trị của đoạn dãy cuối cùng $[l,r]$; lúc này miền giá trị đáp án là $[ql,qr]$. Đặt $mid=\lfloor\frac{ql + qr}{2}\rfloor$. Khi bắt đầu mỗi vòng chặt nhị phân, mặc định chia mọi số vào $[mid+1,qr]$, tức số lượng phần tử cần chia vào $[ql,mid]$ được đặt là $0$, và chi phí ban đầu là số thao tác để đặt toàn bộ đoạn dãy $[l,r]$ thành $mid+1$. Sau đó lần lượt liệt kê từng số $i$ trong đoạn $[l,r]$ và tính tổng số thao tác để đặt $[l,i]$ thành $mid$ và đặt $[i+1,r]$ thành $mid+1$. Nếu tổng này tốt hơn số thao tác trước đó, cập nhật số thao tác nhỏ nhất và số lượng phần tử cần chia vào $[ql,mid]$.
    
    Khi chia, tính đơn điệu của dãy cuối cùng đã được duy trì. Đồng thời, vì mỗi lần đều lấy số thao tác nhỏ nhất, với các phần tử cuối cùng được chia vào khoảng trái, chọn $mid$ tốt hơn chọn $mid+1$. Do đó, dãy thu được bằng chặt nhị phân tổng thể không giảm đơn điệu và có số thao tác nhỏ nhất. Chỉ cần tính số thao tác rồi xuất ra.

??? note "Mã tham khảo (phần chính)"
    ```cpp
    int a[500005], ans[500005];  // a: dãy gốc, ans: dãy được dựng
    
    void overall_binary(int l, int r, int ql, int qr) {
      if (l > r) return;
      if (ql == qr) {
        for (int i = l; i <= r; i++) ans[i] = ql;
        return;
      }
      int cnt = 0,
          mid = ql + ((qr - ql) >> 1);  // mặc định ban đầu điền mid+1, tất cả chia sang phải
      long long res = 0ll, sum = 0ll;
      for (int i = l; i <= r; i++) sum += abs(a[i] - (mid + 1));
      res = sum;
      for (int i = l; i <= r;
           i++) {  // thử đổi [l,i] từ mid+1 thành mid và chia sang trái
        sum -= abs(a[i] - (mid + 1));
        sum += abs(a[i] - mid);
        if (sum < res) cnt = i - l + 1, res = sum;  // thấy [l,i] lấy mid tốt hơn, cập nhật
      }
      overall_binary(l, l + cnt - 1, ql, mid);
      overall_binary(l + cnt, r, mid + 1, qr);
    }
    ```

### Bài tập tham khảo

-   [Đội tuyển quốc gia: Nhân ma trận](https://www.luogu.com.cn/problem/P1527)
-   [POI2011 R3 Day2: Thiên thạch](https://loj.ac/p/2169)
-   [Cây cân bằng nâng cao](https://loj.ac/p/106)
-   [BalticOI 2004: Dãy số](https://www.luogu.com.cn/problem/P4331)

## Tài liệu tham khảo và chú thích

-   Xu Haoran. Bàn về một số lời giải phi kinh điển cho bài toán cấu trúc dữ liệu. [Tập luận văn đội tuyển dự bị quốc gia Trung Quốc tham dự Olympic Tin học năm 2013](https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2013%E8%AE%BA%E6%96%87%E9%9B%86.pdf).

[^ref1]: Xu Haoran. Bàn về một số lời giải phi kinh điển cho bài toán cấu trúc dữ liệu. [Tập luận văn đội tuyển dự bị quốc gia Trung Quốc tham dự Olympic Tin học năm 2013](https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2013%E8%AE%BA%E6%96%87%E9%9B%86.pdf).
