Trang này chủ yếu giới thiệu kiến thức thuật toán liên quan đến bài toán luồng cực đại.

## Tổng quan

Các khái niệm cơ bản về luồng trên mạng có thể xem tại [Giới thiệu luồng mạng](../flow.md).

Cho $G=(V,E)$ là một mạng có nguồn và đích. Ta muốn chỉ định một luồng thích hợp $f$ trên $G$ sao cho giá trị luồng của toàn mạng $|f|$ được cực đại hóa, tức $\sum_{x \in V} f(s, x) - \sum_{x \in V} f(x, s)$. Bài toán này được gọi là bài toán luồng cực đại (Maximum flow problem).

## Tăng luồng Ford–Fulkerson

Tăng luồng Ford–Fulkerson là tên gọi chung của một lớp thuật toán tính luồng cực đại. Phương pháp này dùng tư tưởng tham lam, liên tục tìm đường tăng luồng để cập nhật và tìm luồng cực đại.

### Tổng quan

Cho mạng $G$ và một luồng $f$ trên $G$, ta định nghĩa như sau.

Với cạnh $(u, v)$, hiệu giữa dung lượng và luồng được gọi là dung lượng còn dư $c_f(u,v)$ (Residual Capacity), tức $c_f(u,v)=c(u,v)-f(u,v)$.

Đồ thị con gồm tất cả các đỉnh của $G$ và các cạnh có dung lượng còn dư lớn hơn $0$ được gọi là mạng thặng dư $G_f$ (Residual Network), tức $G_f=(V,E_f)$, trong đó $E_f=\left\{(u,v) \mid c_f(u,v)>0\right\}$.

???+ warning "Cảnh báo"
    Như sẽ nói ngay sau đây, luồng có thể nhận giá trị âm, vì vậy cạnh trong $E_f$ có thể không thuộc $E$. Sau khi đưa vào khái niệm tăng luồng, phần dưới sẽ giải thích cụ thể điểm này.

Một đường đi từ nguồn $s$ đến đích $t$ trên $G_f$ được gọi là đường tăng luồng (Augmenting Path). Với một đường tăng luồng, ta cộng cùng một lượng luồng vào mọi cạnh $(u, v)$ trên đường đó để làm tăng giá trị luồng của toàn mạng. Quá trình này được gọi là tăng luồng (Augment). Do đó, việc tìm luồng cực đại có thể được xem như chồng nhiều luồng thu được từ các lần tăng luồng.

Ngoài ra, trong quá trình tăng luồng Ford–Fulkerson, với mỗi cạnh $(u, v)$, ta tạo thêm một cạnh ngược $(v, u)$. Ta quy ước $f(u, v) = -f(v, u)$. Tính chất này có thể được đảm bảo bằng thao tác hoàn luồng trong mỗi lần tăng luồng, tức khi $f(u, v)$ tăng thì $f(v, u)$ phải giảm cùng một lượng.

???+ tip "Mẹo"
    Trong cài đặt các thuật toán luồng cực đại, ta thường cần hỗ trợ truy cập nhanh cạnh ngược. Với ma trận kề, thao tác này là hiển nhiên ($g_{u, v} \leftrightarrow g_{v, u}$). Tuy nhiên, cách cài đặt phổ biến hơn và tốt hơn là forward-star dạng danh sách liên kết. Một mẹo thường dùng là đánh số cạnh bắt đầu từ số chẵn, thường là $0$, và khi thêm cạnh luôn thêm ngay cạnh ngược của nó để hai cạnh có chỉ số kề nhau. Khi đó, cạnh có chỉ số $i$ và cạnh có chỉ số $i \oplus 1$ luôn là cạnh ngược của nhau.

Người mới tiếp xúc với phương pháp này có thể nhận thấy một tình huống trái trực giác: luồng trên cạnh ngược $f(v, u)$ có thể là số âm. Thực ra, trong quá trình tăng luồng Ford–Fulkerson, đại lượng thật sự có ý nghĩa là dung lượng còn dư $c_f$, còn trị tuyệt đối của $f(v, u)$ không quan trọng. Ta có thể xem việc giảm luồng trên cạnh ngược là làm tăng dung lượng còn dư $c_f(v, u)$ của cạnh ngược. Điều này cũng phù hợp với ý nghĩa của hoàn luồng: dung lượng còn dư trên cạnh ngược tăng lên nghĩa là sau đó ta có thể đi qua cạnh ngược để triệt tiêu lần tăng luồng theo chiều thuận trước đó, tương đương với một thao tác "hối lại".

Ví dụ sau có thể giúp bạn hiểu quá trình này. Giả sử $G$ là một mạng dung lượng đơn vị, xét quá trình sau:

-   Trên $G$ có nhiều đường tăng luồng. Trong đó, ta chọn thực hiện một lần tăng luồng đi qua $u, v$ theo thứ tự, như hình bên trái, làm giá trị luồng tăng thêm $1$.
-   Ta nhận thấy nếu thực hiện lần tăng luồng như hình giữa, luồng cực đại cục bộ không phải là $1$ mà là $2$. Nhưng do cạnh đi vào $u$ và cạnh đi ra từ $v$ đã dùng hết dung lượng trong lần tăng luồng đầu tiên, lúc này ta không thể thực hiện lần tăng luồng ở hình giữa. Điều này nghĩa là luồng hiện tại chưa đủ tốt, nhưng cục bộ có thể đã không còn đường tăng luồng nào khác nếu chỉ đi qua các cạnh của đồ thị gốc mà không đi qua cạnh ngược.
-   Bây giờ đưa vào thao tác hoàn luồng. Sau lần tăng luồng đầu tiên, hoàn luồng nghĩa là $c_f(v, u)$ tăng thêm $1$ dung lượng còn dư, tương đương với việc thêm cạnh $(v, u)$. Vì vậy ta có thể thực hiện thêm một lần tăng luồng đi qua $p, v, u, q$ theo thứ tự, như đường màu cam trong hình bên phải. Luồng trên cạnh vô hướng $(u, v)$ bị triệt tiêu qua hai lần tăng luồng, và ta thấy kết quả chồng hai lần tăng luồng thực ra tương đương với hình giữa.

![](./images/flow2.png)

Ví dụ trên cho thấy hiệu ứng "triệt tiêu" do thao tác hoàn luồng đem lại giúp ta không cần lo lắng rằng mình đã chọn đường tăng luồng theo "thứ tự sai".

Dễ thấy rằng chỉ cần trên $G_f$ còn tồn tại đường tăng luồng thì tăng luồng theo đường đó sẽ làm tổng giá trị luồng tăng lên. Nếu không còn đường tăng luồng, tổng giá trị luồng đã đạt giá trị lớn nhất có thể và quá trình kết thúc. Đây chính là quá trình tăng luồng Ford–Fulkerson.

### Định lý luồng cực đại - lát cắt nhỏ nhất

Ta đã hiểu sơ lược tư tưởng tăng luồng Ford–Fulkerson, nhưng làm thế nào để chứng minh tính đúng đắn của phương pháp này? Vì sao luồng $f$ sau khi kết thúc tăng luồng là một luồng cực đại?

Thực ra, tính đúng đắn của tăng luồng Ford–Fulkerson tương đương với định lý luồng cực đại - lát cắt nhỏ nhất (The Maxflow-Mincut Theorem). Định lý này phát biểu rằng với mọi mạng $G = (V, E)$, luồng cực đại $f$ và lát cắt nhỏ nhất $\{S, T\}$ trên mạng đó luôn thỏa mãn $|f| = ||S, T||$.

Để chứng minh định lý luồng cực đại - lát cắt nhỏ nhất, trước hết xét một bổ đề: với mạng $G = (V, E)$, lấy tùy ý một luồng $f$ và một lát cắt $\{S, T\}$, luôn có $|f| \leq ||S, T||$. Dấu bằng xảy ra khi và chỉ khi mọi cạnh trong $\{(u, v) | u \in S, v \in T\}$ đều đầy luồng, và mọi cạnh trong $\{(u, v) | u \in T, v \in S\}$ đều có luồng bằng không.

???+ note "Chứng minh"
    $$
    \begin{aligned}
    |f| & = f(s) \\
        & = \sum_{u \in S} f(u) \\
        & = \sum_{u \in S} \left( \sum_{v \in V} f(u, v) - \sum_{v \in V} f(v, u) \right) \\
        & = \sum_{u \in S} \left( \sum_{v \in T} f(u, v) + \sum_{v \in S} f(u, v) - \sum_{v \in T} f(v, u) - \sum_{v \in S} f(v, u) \right) \\
        & = \sum_{u \in S} \left( \sum_{v \in T} f(u, v) - \sum_{v \in T} f(v, u) \right) + \sum_{u \in S} \sum_{v \in S} f(u, v) - \sum_{u \in S} \sum_{v \in S} f(v, u) \\
        & = \sum_{u \in S} \left( \sum_{v \in T} f(u, v) - \sum_{v \in T} f(v, u) \right) \\
        & \leq \sum_{u \in S} \sum_{v \in T} f(u, v) \\
        & \leq \sum_{u \in S} \sum_{v \in T} c(u, v) \\
        & = ||S, T|| \\
    \end{aligned}
    $$
    
    Để đạt dấu bằng, bất đẳng thức thứ nhất cần mọi cạnh trong $\{(u, v) \mid u \in T, v \in S\}$ đều có luồng bằng không, còn bất đẳng thức thứ hai cần mọi cạnh trong $\{(u, v) \mid u \in S, v \in T\}$ đều đầy luồng. Bổ đề được chứng minh.

Vậy với một mạng bất kỳ, các điều kiện đạt dấu bằng ở trên có luôn được thỏa mãn không? Nếu câu trả lời là có, định lý luồng cực đại - lát cắt nhỏ nhất được chứng minh. Sau đây ta thử chứng minh điều đó.

???+ note "Chứng minh"
    Giả sử sau một vòng tăng luồng nào đó, ta thu được luồng $f$ sao cho trên $G_f$ không tồn tại đường tăng luồng, tức trên $G_f$ không tồn tại đường đi từ $s$ đến $t$. Khi đó, gọi $S$ là tập các đỉnh có thể đến được từ $s$, và đặt $T = V \setminus S$.
    
    Hiển nhiên, $\{S, T\}$ là một lát cắt của $G_f$, và $||S, T|| = \sum_{u \in S} \sum_{v \in T} c_f(u, v) = 0$. Vì dung lượng còn dư không âm, điều này cũng có nghĩa là với mọi $u \in S, v \in T, (u, v) \in E_f$, ta đều có $c_f(u, v) = 0$. Sau đây ta chia các cạnh này thành hai trường hợp: cạnh tồn tại trong đồ thị gốc và cạnh ngược.
    
    -   $(u, v) \in E$: khi đó $c_f(u, v) = c(u, v) - f(u, v) = 0$, nên $c(u, v) = f(u, v)$, tức mọi cạnh trong $\{(u, v) \mid u \in S, v \in T\}$ đều đầy luồng.
    -   $(v, u) \in E$: khi đó $c_f(u, v) = c(u, v) - f(u, v) = 0 - f(u, v) = f(v, u) = 0$, tức mọi cạnh trong $\{(v, u) \mid u \in S, v \in T\}$ đều có luồng bằng không.
    
    Vì vậy, sau khi tăng luồng dừng lại, luồng $f$ ở trên thỏa mãn điều kiện đạt dấu bằng. Theo quan hệ lớn nhỏ trong bổ đề, một cách tự nhiên, $f$ là một luồng cực đại của $G$, và $\{S, T\}$ là một lát cắt nhỏ nhất của $G$.

Dễ thấy định lý Kőnig là một trường hợp đặc biệt của định lý luồng cực đại - lát cắt nhỏ nhất. Thực ra, cả hai đều liên quan đến đối ngẫu trong quy hoạch tuyến tính.

### Phân tích độ phức tạp thời gian

Trên mạng $G = (V, E)$ có luồng nguyên, giả sử một cách hiển nhiên rằng lượng luồng tăng thêm mỗi lần đều là số nguyên, thì một cận trên cho độ phức tạp thời gian của tăng luồng Ford–Fulkerson là $O(|E||f|)$, trong đó $f$ là luồng cực đại trên $G$. Lý do là một vòng tăng luồng có độ phức tạp $O(|E|)$, còn mỗi lần tăng luồng đều làm tổng giá trị luồng tăng lên, nên số vòng tăng luồng không thể vượt quá $|f|$.

Các cách cài đặt khác nhau của tăng luồng Ford–Fulkerson có độ phức tạp thời gian khác nhau. Trong đó các cài đặt phổ biến hơn gồm Edmonds–Karp, Dinic, SAP, ISAP, v.v. Ta sẽ lần lượt giới thiệu ở phần sau.

### Thuật toán Edmonds–Karp

#### Ý tưởng thuật toán

Làm thế nào để tìm đường tăng luồng trong $G_f$? Khi xét một cài đặt cụ thể của tăng luồng Ford–Fulkerson, phương án tự nhiên nhất là dùng BFS. Khi đó, tăng luồng Ford–Fulkerson trở thành thuật toán Edmonds–Karp. Quy trình cụ thể như sau:

-   Nếu trên $G_f$ ta có thể BFS từ $s$ đến $t$, ta đã tìm được một đường tăng luồng mới.

-   Với đường tăng luồng $p$, ta tính giá trị nhỏ nhất của dung lượng còn dư trên các cạnh mà $p$ đi qua: $\Delta = \min_{(u, v) \in p} c_f(u, v)$. Ta cộng $\Delta$ luồng vào mỗi cạnh trên $p$, đồng thời hoàn $\Delta$ luồng trên các cạnh ngược của chúng, làm luồng cực đại tăng thêm $\Delta$.

-   Vì ta đã sửa luồng, ta thu được $G_f$ mới. Lặp lại quá trình trên trên $G_f$ mới cho đến khi không còn đường tăng luồng, khi đó giá trị luồng không tăng thêm nữa.

Thuật toán trên chính là thuật toán Edmonds–Karp.

#### Phân tích độ phức tạp thời gian

Tiếp theo ta thử phân tích độ phức tạp thời gian của thuật toán Edmonds–Karp.

Hiển nhiên, độ phức tạp thời gian của một vòng tăng luồng bằng BFS là $O(|E|)$.

Cận trên cho tổng số vòng tăng luồng là $O(|V||E|)$. Mệnh đề này thường bị chứng minh sai trên tài liệu mạng, hoặc bị lược qua một cách mơ hồ. Sau đây ta thử đưa ra một chứng minh tương đối hình thức[^ref_ek].

???+ note "Chứng minh cận trên của tổng số vòng tăng luồng"
    Trước hết, ta đưa vào một bổ đề: bổ đề khoảng cách ngắn nhất không giảm. Cụ thể, ký hiệu $d_f(u)$ là khoảng cách từ đỉnh $u$ đến nguồn $s$ trên $G_f$, tức độ dài đường đi ngắn nhất, dưới đây cũng vậy. Với một vòng tăng luồng nào đó, dùng $f$ và $f'$ lần lượt biểu diễn luồng trước và sau khi tăng. Ta khẳng định rằng với mọi đỉnh $u$, tăng luồng luôn làm $d_{f'}(u) \geq d_f(u)$. Ta sẽ chứng minh bổ đề này sau.
    
    Gọi cạnh có dung lượng còn dư nhỏ nhất trên đường tăng luồng là cạnh bão hòa, nếu có nhiều cạnh cùng nhỏ nhất thì chọn tùy ý một cạnh. Nếu một cạnh có hướng $(u, v)$ được chọn làm cạnh bão hòa, lần tăng luồng sẽ làm dung lượng còn dư của nó bằng không, khiến cạnh bão hòa biến mất, đồng thời hoàn luồng làm xuất hiện cạnh ngược, nếu trước đó cạnh ngược chưa tồn tại, tức $(u, v) \not \in E_{f'}$ và $(v, u) \in E_{f'}$. Phân tích trên cho thấy với một cạnh vô hướng $(u, v)$, hai chiều được tăng luồng của nó luôn xuất hiện xen kẽ.
    
    Khi tăng luồng dọc theo $(u, v)$ trên $G_f$, ta có $d_f(u) + 1 = d_f(v)$, sau đó mạng thặng dư trở thành $G_{f'}$. Khi tăng luồng dọc theo $(v, u)$ trên $G_{f'}$, ta có $d_{f'}(v) + 1 = d_{f'}(u)$. Theo bổ đề khoảng cách ngắn nhất không giảm lại có $d_{f'}(v) \geq d_f(v)$. Nối các đẳng thức và bất đẳng thức lại, thu được $d_{f'}(u) \geq d_{f}(u) + 2$. Nói cách khác, nếu cạnh có hướng $(u, v)$ được chọn làm cạnh bão hòa, thì so với lần trước nó được chọn làm cạnh bão hòa, khoảng cách từ $u$ đến $s$ tăng ít nhất $2$.
    
    Khoảng cách từ $s$ đến bất kỳ đỉnh nào không thể vượt quá $|V|$. Kết hợp tính chất trên, ta thấy mỗi cạnh được chọn làm cạnh bão hòa $O(|V|)$ lần. Nhân với số cạnh, ta được cận trên $O(|V||E|)$ cho tổng số vòng tăng luồng.
    
    Tiếp theo ta chứng minh bổ đề khoảng cách ngắn nhất không giảm, tức $d_{f'}(u) \geq d_f(u)$. Chứng minh này không khó, nhưng có thể hơi vòng vèo; người đọc có thể dừng lại suy nghĩ kỹ một chút.
    
    ???+ note "Chứng minh bổ đề khoảng cách ngắn nhất không giảm"
        Xét phản chứng. Với một vòng tăng luồng nào đó, giả sử tồn tại một số đỉnh mà sau vòng tăng luồng này, khoảng cách đến $s$ giảm so với trước khi tăng. Gọi $v$ là đỉnh có khoảng cách đến $s$ nhỏ nhất trong số đó, tức $v = \arg \min_{x \in V, d_{f'}(x) < d_f(x)} d_{f'}(x)$. Chú ý rằng theo giả thiết phản chứng, lúc này $d_{f'}(v) < d_f(v)$ là điều đã biết.
        
        Trên đường đi ngắn nhất từ $s$ đến $v$ trong $G_{f'}$, gọi $u$ là đỉnh ngay trước $v$, tức $d_{f'}(u) + 1 = d_{f'}(v)$.
        
        Để $u$ không phá vỡ tính chất "khoảng cách nhỏ nhất" của $v$, $u$ phải thỏa mãn $d_{f'}(u) \geq d_f(u)$.
        
        Cộng cùng một lượng vào hai vế của bất đẳng thức trên, ta được $d_{f'}(v) \geq d_f(u) + 1$. Dùng giả thiết phản chứng để chặn, ta thu được $d_f(v) > d_f(u) + 1$.
        
        Sau đây ta xét hướng tăng luồng trên $(u, v)$.
        
        -   Giả sử cạnh có hướng $(u, v) \in E_f$. Theo tính chất "duyệt theo chiều rộng" của BFS, ta có $d_f(u) + 1 \geq d_f(v)$. Đẳng thức này mâu thuẫn với kết quả chặn ở trên.
        -   Giả sử cạnh có hướng $(u, v) \not \in E_f$. Theo định nghĩa của $u$, ta đã biết $(u, v) \in E_{f'}$, nên sự tồn tại của cạnh này nhất định là kết quả của việc vòng tăng luồng hiện tại đi qua $(v, u)$ và tạo cạnh ngược do hoàn luồng, tức $d_f(v) + 1 = d_f(u)$. Đẳng thức này mâu thuẫn với kết quả chặn ở trên.
        
        Vì tăng luồng theo bất kỳ hướng nào của $(u, v)$ cũng dẫn đến mâu thuẫn, giả thiết phản chứng không đúng, và bổ đề khoảng cách ngắn nhất không giảm được chứng minh.

Nhân độ phức tạp của một vòng tăng luồng BFS với cận trên của số vòng tăng luồng, ta được độ phức tạp thời gian của thuật toán Edmonds–Karp là $O(|V||E|^2)$.

#### Cài đặt

Một cài đặt khả dĩ của thuật toán Edmonds–Karp như sau.

??? note "Mã tham khảo"
    ```cpp
    constexpr int MAXN = 250;
    constexpr int INF = 0x3f3f3f3f;
    
    struct Edge {
      int from, to, cap, flow;
    
      Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
    };
    
    struct EK {
      int n, m;             // n: số đỉnh, m: số cạnh
      vector<Edge> edges;   // edges: tập hợp tất cả các cạnh
      vector<int> G[MAXN];  // G: đỉnh x -> chỉ số các cạnh của x trong edges
      int a[MAXN], p[MAXN];  // a: đỉnh x -> lượng lớn nhất mà cạnh gần nhất
                             //    chạm tới x trong BFS có thể gán cho x
                             // p: đỉnh x -> cạnh gần nhất chạm tới x trong BFS
    
      void init(int n) {
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
      }
    
      void AddEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
      }
    
      int Maxflow(int s, int t) {
        int flow = 0;
        for (;;) {
          memset(a, 0, sizeof(a));
          queue<int> Q;
          Q.push(s);
          a[s] = INF;
          while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); i++) {  // duyệt các cạnh đi từ x
              Edge& e = edges[G[x][i]];
              if (!a[e.to] && e.cap > e.flow) {
                p[e.to] = G[x][i];  // G[x][i] là cạnh gần nhất chạm tới e.to
                a[e.to] =
                    min(a[x], e.cap - e.flow);  // lượng cạnh gần nhất gán cho e.to
                Q.push(e.to);
              }
            }
            if (a[t]) break;  // nếu đỉnh đích đã nhận lượng thì thoát BFS
          }
          if (!a[t])
            break;  // nếu đỉnh đích không nhận lượng, s và t không cùng thành phần liên thông
          for (int u = t; u != s;
               u = edges[p[u]].from) {  // lần ngược đường s -> t trong quá trình BFS qua u
            edges[p[u]].flow += a[t];      // tăng giá trị flow trên cạnh của đường
            edges[p[u] ^ 1].flow -= a[t];  // giảm giá trị flow trên đường ngược
          }
          flow += a[t];
        }
        return flow;
      }
    };
    ```

### Thuật toán Dinic

#### Ý tưởng thuật toán

Xét việc trước khi tăng luồng, ta BFS để phân tầng $G_f$, tức chia các đỉnh thành nhiều tầng theo khoảng cách $d(u)$ từ đỉnh $u$ đến nguồn $s$. Quy định luồng đi qua $u$ chỉ có thể chảy đến các đỉnh $v$ ở tầng kế tiếp, tức xóa các cạnh đi ra từ $u$ đến các đỉnh có số tầng bằng hoặc nhỏ hơn. Phần còn lại của $G_f$ được gọi là đồ thị tầng (Level Graph). Nói hình thức, $G_L = (V, E_L)$ là đồ thị tầng của $G_f = (V, E_f)$, trong đó $E_L = \left\{ (u, v) \mid (u, v) \in E_f, d(u) + 1 = d(v) \right\}$.

Nếu trên đồ thị tầng $G_L$ ta tìm được một luồng tăng cực đại $f_b$ sao cho chỉ xét trên $G_L$ thì không thể tiếp tục mở rộng $f_b$, ta gọi $f_b$ là luồng chặn (Blocking Flow) của $G_L$.

??? warning "Cảnh báo"
    Mặc dù ở trên ta chỉ định nghĩa tăng luồng/luồng tăng trên một đường tăng luồng đơn lẻ, theo nghĩa rộng, thuật ngữ "tăng luồng" không chỉ dùng cho luồng tăng trên một đường đơn, mà còn có thể dùng cho hợp của nhiều luồng tăng. Nghĩa thứ hai là nghĩa được dùng khi ta định nghĩa luồng chặn.

Sau khi định nghĩa đồ thị tầng và luồng chặn, quy trình của thuật toán Dinic như sau.

1.  BFS trên $G_f$ để tạo đồ thị tầng $G_L$.
2.  DFS trên $G_L$ để tìm luồng chặn $f_b$.
3.  Gộp $f_b$ vào luồng ban đầu $f$, tức $f \leftarrow f + f_b$.
4.  Lặp lại quá trình trên cho đến khi không còn đường đi từ $s$ đến $t$.

Lúc này $f$ là luồng cực đại.

Trước khi phân tích độ phức tạp của thuật toán này, ta cần đặc biệt giải thích quá trình "DFS trên $G_L$ để tìm luồng chặn $f_b$". Mặc dù BFS đồ thị tầng có lẽ là hiển nhiên với người đọc trang này, quá trình DFS luồng chặn cần một chút kỹ thuật: ta cần đưa vào tối ưu cung hiện tại.

Chú ý rằng trong quá trình DFS trên $G_L$, nếu đỉnh $u$ đồng thời có rất nhiều cạnh vào và cạnh ra, và mỗi khi $u$ nhận luồng từ cạnh vào đều duyệt danh sách cạnh ra để quyết định truyền luồng sang cạnh ra nào, thì độ phức tạp thời gian cục bộ tại $u$ trong trường hợp xấu nhất có thể đạt $O(|E|^2)$. Để tránh nhược điểm này, nếu tại một thời điểm ta đã biết cạnh $(u, v)$ đã được tăng luồng đến giới hạn, tức cạnh $(u, v)$ không còn dung lượng còn dư hoặc phía sau $v$ đã bị chặn, thì luồng của $u$ không cần thử chảy vào cạnh ra $(u, v)$ nữa. Vì vậy, với mỗi đỉnh $u$, ta duy trì cạnh ra đầu tiên trong danh sách cạnh ra của $u$ mà vẫn còn cần thử. Theo thói quen, con trỏ được duy trì này được gọi là cung hiện tại, và cách làm này được gọi là tối ưu cung hiện tại.

??? note "Tăng luồng nhiều đường"
    Tăng luồng nhiều đường là một tối ưu hằng số của thuật toán Dinic. Nếu ta tìm được một đường tăng luồng $p$ từ $s$ đến $t$ trên đồ thị tầng, thì tiếp theo không nhất thiết phải quay lại từ $s$ để tìm đường tăng luồng kế tiếp, mà có thể bắt đầu từ vị trí cuối cùng trên $p$ vẫn còn dung lượng còn dư để tìm một nhánh rẽ và tăng luồng. Xét sự nhất quán với dạng quay lui, tối ưu này cũng tự nhiên trong cài đặt DFS.
    
    ??? failure "Hiểu lầm thường gặp"
        Có lẽ do nhiều tài liệu mạng diễn đạt sai rồi lan truyền, khá nhiều thí sinh thích gọi tối ưu cung hiện tại và tăng luồng nhiều đường là hai tối ưu của thuật toán Dinic đặt ngang hàng nhau. Thực ra, tối ưu cung hiện tại là một phần dùng để đảm bảo tính đúng đắn của độ phức tạp thời gian của Dinic, còn tăng luồng nhiều đường chỉ là tối ưu hằng số không ảnh hưởng đến độ phức tạp.

#### Phân tích độ phức tạp thời gian

Sau khi áp dụng tối ưu cung hiện tại, phân tích độ phức tạp thời gian của thuật toán Dinic như sau.

Trước hết, ta thử chứng minh độ phức tạp thời gian của DFS tìm luồng chặn trong một vòng tăng luồng là $O(|V||E|)$.

???+ note "Chứng minh độ phức tạp thời gian của một vòng tăng luồng"
    Xét từng đường tăng luồng trong luồng chặn $f_b$. Chúng đều là kết quả của việc nhảy theo cung hiện tại trên $G_L$, và số lần nhảy mà mỗi đường tăng luồng trải qua không thể nhiều hơn $|V|$.
    
    Mỗi khi tìm được một đường tăng luồng thì có một cạnh bão hòa biến mất, tức dung lượng còn dư bị xóa về không. Xét từng đường tăng luồng trong luồng chặn $f_b$, gọi $E_1$ là tập các cạnh bão hòa bị chúng xóa về không. Do tính chất phân tầng của $G_L$, sau khi cạnh bão hòa biến mất, cạnh ngược của nó không thể được các đường tăng luồng khác đi qua trong cùng một vòng tăng luồng. Vì vậy, $E_1$ là tập con của $E_L$.
    
    Ngoài ra, với các trường hợp đã nhảy theo cung hiện tại nhưng không thu được đường tăng luồng thành công do bị chặn ở một vị trí nào đó, gọi $E_2$ là tập các cạnh cuối cùng trên những đường chưa hoàn chỉnh này. Các phần tử của $E_2$ không bão hòa, nên $E_1$ và $E_2$ không giao nhau, đồng thời $E_1 \cup E_2$ vẫn là tập con của $E_L$.
    
    Vì mỗi phần tử của $E_1 \cup E_2$ đều không tốn quá $|V|$ lần nhảy, và khi dùng tối ưu tăng luồng nhiều đường thì một số lần nhảy còn bị đếm lặp, nên tổng số lần nhảy trong quá trình DFS không thể nhiều hơn $|V||E_L|$.
    
    ??? failure "Một chứng minh sai thường gặp"
        Với mỗi đỉnh, ta duy trì cạnh tiếp theo có thể tăng luồng, còn cung hiện tại thay đổi nhiều nhất $|E|$ lần, từ đó độ phức tạp thời gian xấu nhất của một vòng tăng luồng là $O(|V||E|)$.
    
    ??? bug "Lỗi"
        "Cung hiện tại thay đổi nhiều nhất $|E|$ lần" không suy ra được "mỗi đỉnh truy cập các cạnh ra của nó nhiều nhất $|E|$ lần". Lý do là truy cập cung hiện tại không nhất thiết làm cạn dung lượng còn dư trên cung đó; đỉnh $u$ có thể truy cập cùng một cung hiện tại nhiều lần.

Chú ý rằng số tầng của đồ thị tầng hiển nhiên không thể vượt quá $|V|$. Nếu có thể chứng minh số tầng của đồ thị tầng tăng nghiêm ngặt đơn điệu trong quá trình tăng luồng, thì số vòng tăng luồng của thuật toán Dinic là $O(|V|)$. Tiếp theo ta thử chứng minh kết luận này[^ref_dinic].

???+ note "Chứng minh tính đơn điệu của số tầng đồ thị tầng"
    Ta cần đưa vào một khái niệm trong các thuật toán đẩy tiền luồng, một lớp thuật toán luồng cực đại khác: nhãn độ cao. Để thuận tiện kết hợp nhãn độ cao vào chứng minh, trong quá trình chứng minh, đặt $d_f(u)$ là khoảng cách từ đỉnh $u$ đến **đích** $t$ trên $G_f$, và phân tầng bắt đầu từ **đích** chứ không phải nguồn. Điều này không có khác biệt bản chất. Với một vòng tăng luồng nào đó, dùng $f$ và $f'$ lần lượt biểu diễn luồng trước và sau khi tăng. Sau khi tìm và thêm luồng chặn trong vòng tăng luồng này, ký hiệu đồ thị tầng chuyển từ $G_L = (V, E_L)$ thành $G'_{L} = (V, E'_L)$.
    
    Ta tạm thời định nghĩa nhãn độ cao một cách không chặt: trên mạng $G = (V, E)$, cho $h$ là một hàm từ tập đỉnh $V$ đến tập số nguyên $N$. $h$ là một nhãn độ cao hợp lệ trên $G$ khi và chỉ khi $h(u) \leq h(v) + 1$ luôn đúng với mọi $(u, v) \in E$.
    
    Xét mọi phần tử $(u, v)$ của $E_{f'}$, ta thấy lý do để $(u, v) \in E_{f'}$ là một trong hai trường hợp sau.
    
    -   $(u, v) \in E_f$, và dung lượng còn dư chưa bị dùng hết trong vòng tăng luồng này. Theo định nghĩa đường đi ngắn nhất, lúc này ta có $d_f(u) \leq d_f(v) + 1$.
    -   $(u, v) \not \in E_f$, nhưng trong vòng tăng luồng này luồng chặn đi qua $(v, u)$ và tạo cạnh ngược do hoàn luồng. Theo định nghĩa của đồ thị tầng và luồng chặn, lúc này ta có $d_f(u) + 1 = d_f(v)$.
    
    Quan sát trên cho ta một kết luận: $d_f$ là một nhãn độ cao hợp lệ trên $G_{f'}$. Tất nhiên, nó cũng hợp lệ trên đồ thị con $G'_L$ của $G_{f'}$.
    
    Bây giờ, với một đường tăng luồng $p = (s, \dots, u, v, \dots, t)$ trên $G'_L$, xét quá trình bắt đầu từ đường rỗng rồi lần lượt thêm một đỉnh theo thứ tự ngược của các đỉnh trên $p$, tức từ $t$ đến $s$. Giả sử đỉnh $v$ đã được thêm, và đỉnh $u$ đang được thêm. Ta thấy sau khi thêm $u$, theo định nghĩa đồ thị tầng, giá trị $d_{f'}(u)$ lớn hơn $d_{f'}(v)$ đúng $1$; đồng thời, vì $d_f$ là nhãn độ cao trên $G'_L$, giá trị $d_f(u)$ có thể lớn hơn $d_f(v)$ đúng $1$, cũng có thể giữ nguyên hoặc giảm. Vì vậy, sau khi toàn bộ đường được thêm xong, ta thu được $d_{f'}(s) \geq d_f(s)$. Điều kiện cần và đủ để đạt dấu bằng là $d_f(u) = d_f(v) + 1$ luôn đúng với mọi $(u, v) \in p$. Nếu bất đẳng thức này không đạt dấu bằng, thì $d_{f'}(s) > d_f(s)$, tức chính là kết luận ta muốn: số tầng của đồ thị tầng tăng nghiêm ngặt đơn điệu trong quá trình tăng luồng. Sau đây ta thử chứng minh bất đẳng thức này không thể đạt dấu bằng.
    
    Xét phản chứng, giả sử $d_{f'}(s) = d_f(s)$ đúng, và thử dẫn đến mâu thuẫn. Bây giờ ta khẳng định rằng trên $G'_L$, $p$ chứa ít nhất một cạnh $(u, v)$ không tồn tại trên $G_L$. Nếu không có cạnh như vậy, xét $d_f(s) = d_{f'}(s)$ và kết hợp định nghĩa đồ thị tầng cùng luồng chặn, việc tăng luồng trên $G_L$ đáng lẽ chưa hoàn tất. Để tránh mâu thuẫn này, khẳng định của ta phải đúng.
    
    Gọi $(u, v)$ là cạnh thỏa mãn khẳng định đó. Lý do khiến nó thỏa mãn khẳng định chỉ có thể là một trong hai trường hợp sau.
    
    -   $(u, v) \in E_f$ nhưng $d_f(u) \leq d_f(v) + 1$ không đạt dấu bằng, nên theo định nghĩa đồ thị tầng, $(u, v) \not \in E_L$, và sau khi tăng luồng được thêm vào $E'_L$ trong lần phân tầng lại mới.
    -   $(u, v) \not \in E_f$, nghĩa là cạnh $(u, v)$ được sinh ra do luồng chặn trong vòng tăng luồng hiện tại đi qua $(v, u)$ và tạo cạnh ngược do hoàn luồng, tức $d_f(u) = d_f(v) - 1$.
    
    Dù khẳng định được thỏa mãn theo cách nào, ta đều có $d_f(u) \neq d_f(v) + 1$. Tức là điều kiện cần và đủ để $d_{f'}(s) \geq d_f(s)$ đạt dấu bằng không thể được thỏa mãn, mâu thuẫn với giả thiết phản chứng $d_{f'}(s) = d_f(s)$. Mệnh đề ban đầu được chứng minh.
    
    ??? failure "Một chứng minh sai thường gặp khác"
        Xét phản chứng. Giả sử sau một vòng tăng luồng, số tầng của đồ thị tầng bằng trước đó, thì trên đồ thị tầng vẫn phải tồn tại ít nhất một đường tăng luồng từ $s$ đến $t$ sao cho hiệu số tầng giữa hai đỉnh kề nhau là $1$. Đường tăng luồng này chưa được tăng chứng tỏ vòng tăng luồng đó chưa kết thúc. Để tránh mâu thuẫn trên, mệnh đề ban đầu đúng.
    
    ??? bug "Lỗi"
        "Sau khi một vòng tăng luồng kết thúc, đường đi ngắn nhất $s$-$t$ trên đồ thị tầng mới bằng trước đó" không suy ra được "vòng tăng luồng trên đồ thị tầng cũ chưa kết thúc". Lý do là không có căn cứ nào cho thấy tập cạnh của hai đồ thị tầng là như nhau; đường đi ngắn nhất $s$-$t$ trên đồ thị tầng mới có thể đi qua cạnh không tồn tại trên đồ thị tầng cũ.

Nhân độ phức tạp thời gian của một vòng tăng luồng $O(|V||E|)$ với số vòng tăng luồng $O(|V|)$, độ phức tạp thời gian của thuật toán Dinic là $O(|V|^2|E|)$.

Nếu muốn thời gian chạy thực tế của thuật toán Dinic tiệm cận cận trên lý thuyết, ta cần xây dựng mạng đầu vào có tính chất đặc biệt. Trong thực hành thi thuật toán, phần kiểm tra kiến thức luồng mạng thường tập trung vào kỹ thuật mô hình hóa bài toán gốc thành bài toán luồng mạng. Khi đó, mô hình của ta thường không chứa các tính chất đặc biệt khiến thuật toán Dinic chạy chậm; ngược lại, Dinic có hiệu quả rất tốt trên phần lớn đồ thị. Vì vậy, phạm vi dữ liệu của bài toán luồng mạng thường khá lớn, và cách "thay giá trị $|V|, |E|$ vào $|V|^2|E|$ để ước lượng thời gian chạy" không phù hợp. Thực tế, để ước lượng chính xác, thí sinh cần có kinh nghiệm nhất định về hiệu suất thực tế của thuật toán Dinic; người đọc có thể luyện tập thêm.

#### Phân tích độ phức tạp thời gian trong các trường hợp đặc biệt

Trên một số đồ thị có tính chất tốt, thuật toán Dinic có độ phức tạp thời gian tốt hơn.

Với mạng $G = (V, E)$, nếu mọi cạnh đều có dung lượng bằng $1$, tức $c(u, v) \in \{0, 1\}$ luôn đúng với mọi $(u, v) \in E$, ta gọi $G$ là mạng dung lượng đơn vị (Unit Capacity).

Trong mạng dung lượng đơn vị, độ phức tạp thời gian của một vòng tăng luồng trong thuật toán Dinic là $O(|E|)$.

???+ note "Chứng minh"
    Lý do là mỗi lần tăng luồng đều làm mọi cạnh trên đường tăng luồng bão hòa và biến mất, nên trong một vòng tăng luồng, mỗi cạnh chỉ có thể được tăng luồng một lần.

Trong mạng dung lượng đơn vị, số vòng tăng luồng của thuật toán Dinic là $O(|E|^{\frac{1}{2}})$.

???+ note "Chứng minh"
    Phân tầng lấy nguồn $s$ làm trung tâm, ký hiệu $d_f(u)$ là khoảng cách từ đỉnh $u$ đến nguồn $s$ trên $G_f$. Ngoài ra, định nghĩa tập đỉnh $\left\{u \mid u \in V, d_f(u) = k \right\}$ là tầng số $k$, ký hiệu $D_k$, và đặt $S_k = \cup_{i \leq k} D_i$.
    
    Giả sử ta đã thực hiện $|E|^{\frac{1}{2}}$ vòng tăng luồng. Theo nguyên lý Dirichlet, tồn tại ít nhất một $k$ sao cho kích thước của tập cạnh $\left\{ (u, v) \mid u \in D_k, v \in D_{k+1}, (u, v) \in E_f \right\}$ không vượt quá $\frac {|E|} {|E|^{\frac{1}{2}}} \approx |E|^{\frac{1}{2}}$. Hiển nhiên, $\{S_k, V - S_k\}$ là một lát cắt $s$-$t$ trên $G_f$, và dung lượng lát cắt của nó không vượt quá $|E|^{\frac{1}{2}}$. Theo định lý luồng cực đại - lát cắt nhỏ nhất, luồng cực đại trên $G_f$ không vượt quá $|E|^{\frac{1}{2}}$, tức trên $G_f$ nhiều nhất còn có thể thực hiện $|E|^{\frac{1}{2}}$ vòng tăng luồng. Vì vậy tổng số vòng tăng luồng là $O(|E|^{\frac{1}{2}})$.

Trong mạng dung lượng đơn vị, số vòng tăng luồng của thuật toán Dinic là $O(|V|^{\frac{2}{3}})$.

???+ note "Chứng minh"
    Giả sử ta đã thực hiện $2 |V|^{\frac{2}{3}}$ vòng tăng luồng. Vì nhiều nhất chỉ có một nửa số tầng, tức $|V|^{\frac{2}{3}}$ tầng, chứa nhiều hơn $|V|^{\frac{1}{3}}$ đỉnh, nên bất kể ta phân bố kích thước của tất cả các tầng như thế nào, vẫn tồn tại ít nhất một $k$ sao cho hai tầng kề nhau đều chứa không quá $|V|^{\frac{1}{3}}$ đỉnh, tức $|D_k| \leq |V|^{\frac{1}{3}}$ và $|D_{k+1}| \leq |V|^{\frac{1}{3}}$.
    
    Để tối đa hóa số cạnh giữa $D_k$ và $D_{k+1}$, giả sử đây là một đồ thị hai phía đầy đủ. Khi đó kích thước của tập cạnh $\left\{ (u, v) \mid u \in D_k, v \in D_{k+1}, (u, v) \in E_f \right\}$ không vượt quá $|V|^{\frac{2}{3}}$. Hiển nhiên, $\{S_k, V - S_k\}$ là một lát cắt $s$-$t$ trên $G_f$, và dung lượng lát cắt của nó không vượt quá $|V|^{\frac{2}{3}}$. Theo định lý luồng cực đại - lát cắt nhỏ nhất, luồng cực đại trên $G_f$ không vượt quá $|V|^{\frac{2}{3}}$, tức trên $G_f$ nhiều nhất còn có thể thực hiện $|V|^{\frac{2}{3}}$ vòng tăng luồng. Vì vậy tổng số vòng tăng luồng là $O(|V|^{\frac{2}{3}})$.

Trong mạng dung lượng đơn vị, nếu ngoài nguồn và đích, mỗi đỉnh $u$ đều thỏa mãn $\mathit{deg}_{\mathit{in}}(u) = 1$ hoặc $\mathit{deg}_{\mathit{out}}(u) = 1$, thì số vòng tăng luồng của thuật toán Dinic là $O(|V|^{\frac{1}{2}})$. Trong đó, $\mathit{deg}_{\mathit{in}}(u)$ và $\mathit{deg}_{\mathit{out}}(u)$ lần lượt biểu diễn bậc vào và bậc ra của đỉnh $u$.

???+ note "Chứng minh"
    Ta đưa vào bổ đề sau: với mạng có dạng này, bất kỳ luồng nào trên nó luôn có thể phân rã thành một số đường tăng luồng có luồng đơn vị và **không giao nhau theo đỉnh**.
    
    Giả sử ta đã thực hiện $|V|^{\frac{1}{2}}$ vòng tăng luồng. Theo định nghĩa đồ thị tầng, lúc này độ dài của bất kỳ đường tăng luồng mới nào ít nhất là $|V|^{\frac{1}{2}}$.
    
    Xét phân rã thành các đường tăng luồng của luồng cực đại trên $G_f$. Số đường tăng luồng thu được không thể nhiều hơn $\frac {|V|} {|V|^{\frac{1}{2}}} \approx |V|^{\frac{1}{2}}$, nghĩa là trên $G_f$ nhiều nhất còn có thể thực hiện $|V|^{\frac{1}{2}}$ vòng tăng luồng. Vì vậy tổng số vòng tăng luồng là $O(|V|^{\frac{1}{2}})$.

Tóm lại, ta thu được một số hệ quả.

-   Trên mạng dung lượng đơn vị, tổng độ phức tạp thời gian của thuật toán Dinic là $O(|E| \min(|E|^\frac{1}{2}, |V|^{\frac{2}{3}}))$.
-   Trên mạng dung lượng đơn vị, nếu ngoài nguồn và đích, mỗi đỉnh $u$ đều thỏa mãn $\mathit{deg}_{\mathit{in}}(u) = 1$ hoặc $\mathit{deg}_{\mathit{out}}(u) = 1$, tổng độ phức tạp thời gian của thuật toán Dinic là $O(|E||V|^{\frac{1}{2}})$. Với bài toán ghép cặp cực đại trên đồ thị hai phía, ta thường dùng thuật toán Hopcroft–Karp để giải, và thuật toán này thực ra là một trường hợp đặc biệt của Dinic trên mạng dung lượng đơn vị thỏa mãn ràng buộc bậc nói trên.

#### Cài đặt

??? note "Mã tham khảo"
    ```cpp
    struct MF {
      struct edge {
        int v, nxt, cap, flow;
      } e[N];
    
      int fir[N], cnt = 0;
    
      int n, S, T;
      ll maxflow = 0;
      int dep[N], cur[N];
    
      void init() {
        memset(fir, -1, sizeof fir);
        cnt = 0;
      }
    
      void addedge(int u, int v, int w) {
        e[cnt] = {v, fir[u], w, 0};
        fir[u] = cnt++;
        e[cnt] = {u, fir[v], 0, 0};
        fir[v] = cnt++;
      }
    
      bool bfs() {
        queue<int> q;
        memset(dep, 0, sizeof(int) * (n + 1));
    
        dep[S] = 1;
        q.push(S);
        while (q.size()) {
          int u = q.front();
          q.pop();
          for (int i = fir[u]; ~i; i = e[i].nxt) {
            int v = e[i].v;
            if ((!dep[v]) && (e[i].cap > e[i].flow)) {
              dep[v] = dep[u] + 1;
              q.push(v);
            }
          }
        }
        return dep[T];
      }
    
      int dfs(int u, int flow) {
        if ((u == T) || (!flow)) return flow;
    
        int ret = 0;
        for (int& i = cur[u]; ~i; i = e[i].nxt) {
          int v = e[i].v, d;
          if ((dep[v] == dep[u] + 1) &&
              (d = dfs(v, min(flow - ret, e[i].cap - e[i].flow)))) {
            ret += d;
            e[i].flow += d;
            e[i ^ 1].flow -= d;
            if (ret == flow) return ret;
          }
        }
        return ret;
      }
    
      void dinic() {
        while (bfs()) {
          memcpy(cur, fir, sizeof(int) * (n + 1));
          maxflow += dfs(S, INF);
        }
      }
    } mf;
    ```

### Thuật toán MPM

Thuật toán **MPM** (Malhotra, Pramodh-Kumar and Maheshwari) có hai cách tìm luồng cực đại: dùng hàng đợi ưu tiên dựa trên heap với độ phức tạp thời gian $O(n^3\log n)$; hoặc cách giải BFS thường dùng với độ phức tạp thời gian $O(n^3)$. Chú ý rằng mục này chỉ tập trung phân tích thuật toán $O(n^3)$ tốt hơn và gọn hơn.

Cấu trúc tổng thể của thuật toán MPM tương tự thuật toán Dinic, cũng chạy theo từng pha. Trong mỗi pha, thuật toán tìm đường tăng luồng trong mạng phân tầng của mạng thặng dư của $G$. Khác biệt chính so với Dinic nằm ở cách tìm đường tăng luồng: phần tìm đường tăng luồng trong thuật toán MPM chỉ tốn $O(n^2)$, có độ phức tạp thời gian tốt hơn Dinic.

Thuật toán MPM cần xét dung lượng của đỉnh thay vì cạnh. Trong mạng phân tầng $L$, nếu định nghĩa dung lượng $p(v)$ của đỉnh $v$ là giá trị nhỏ hơn giữa tổng thặng dư đi vào và tổng thặng dư đi ra của nó, thì có:

$$
\begin{aligned}
p_{in}(v) &= \sum\limits_{(u,v) \in L} (c(u, v) - f(u, v)) \\
p_{out}(v) &= \sum\limits_{(v,u) \in L} (c(v, u) - f(v, u)) \\
p(v) &= \min (p_{in}(v), p_{out}(v))
\end{aligned}
$$

Ta gọi đỉnh $r$ là đỉnh tham chiếu khi và chỉ khi $p(r) = \min {p(v)}$. Với một đỉnh tham chiếu $r$, ta chắc chắn có thể làm luồng đi qua $r$ tăng thêm $p(r)$ để dung lượng của nó trở thành $0$. Lý do là $L$ là đồ thị có hướng không chu trình và dung lượng đỉnh trong $L$ ít nhất là $p(r)$, nên ta chắc chắn tìm được một đường có hướng từ $s$ đi qua $r$ đến $t$. Khi đó chỉ cần tăng luồng trên các cạnh của đường này thêm $p(r)$. Đường này chính là đường tăng luồng của pha này. Có thể dùng BFS để tìm đường tăng luồng. Sau khi tăng luồng xong, mọi cạnh đầy luồng đều có thể bị xóa khỏi $L$ vì chúng sẽ không được dùng tiếp trong pha này. Tương tự, mọi đỉnh khác $s$ và $t$ mà không có cạnh ra hoặc cạnh vào cũng có thể bị xóa.

#### Phân tích độ phức tạp thời gian

Mỗi pha của thuật toán MPM cần $O(V^2)$, vì có nhiều nhất $V$ lần lặp, do ít nhất đỉnh tham chiếu được chọn bị xóa, và trong mỗi lần lặp, ta xóa tất cả các cạnh được đi qua, ngoại trừ nhiều nhất $V$ cạnh. Lấy tổng, ta được $O(V^2+E)=O(V^2)$. Vì tổng số pha nhỏ hơn $V$, tổng thời gian chạy của thuật toán MPM là $O(V^3)$.

???+ note "Chứng minh số pha nhỏ hơn V"
    Thuật toán MPM kết thúc trong ít hơn $V$ pha. Để chứng minh điều này, trước hết ta phải chứng minh hai bổ đề.
    
    **Bổ đề 1**: sau mỗi lần lặp, khoảng cách từ $s$ đến mỗi đỉnh không giảm, tức $level_{i+1}[v] \ge level_{i}[v]$.
    
    **Chứng minh**: cố định một pha $i$ và một đỉnh $v$. Xét một đường đi ngắn nhất bất kỳ $P$ từ $s$ đến $v$ trong $G_{i}^R$. Độ dài của $P$ bằng $level_{i}[v]$. Chú ý rằng $G_{i}^R$ chỉ có thể chứa các cạnh lùi và cạnh tiến của $G_{i}^R$. Nếu $P$ không có cạnh lùi của $G_{i}^R$, thì $level_{i+1}[v] \ge level_{i}[v]$, vì $P$ cũng là một đường đi trong $G_{i}^R$. Bây giờ giả sử $P$ có ít nhất một cạnh lùi và cạnh đầu tiên như vậy là $(u,w)$. Khi đó $level_{i+1}[u] \ge level_{i}[u]$, do trường hợp thứ nhất. Cạnh $(u,w)$ không thuộc $G_{i}^R$, vì vậy $(u,w)$ chịu ảnh hưởng của đường tăng luồng ở lần lặp trước. Điều này nghĩa là $level_{i}[u] = level_{i}[w]+1$. Ngoài ra, $level_{i+1}[w] = level_{i+1}[u]+1$. Từ hai phương trình này và $level_{i+1}[u] \ge level_{i}[u]$, ta được $level_{i+1}[w] \ge level_{i}[w]+2$. Phần còn lại của đường đi cũng có thể dùng cùng ý tưởng.
    
    **Bổ đề 2**: $level_{i+1}[t] > level_{i}[t]$.
    
    **Chứng minh**: từ bổ đề 1, ta có $level_{i+1}[t] \ge level_{i}[t]$. Giả sử $level_{i+1}[t] = level_{i}[t]$. Chú ý rằng $G_{i}^R$ chỉ có thể chứa các cạnh lùi và cạnh tiến của $G_{i}^R$. Điều này nghĩa là trong $G_{i}^R$ có một đường đi ngắn nhất chưa bị đường tăng luồng chặn, dẫn đến mâu thuẫn.

#### Cài đặt

??? note "Mã tham khảo"
    ```cpp
    struct MPM {
      struct FlowEdge {
        int v, u;
        long long cap, flow;
    
        FlowEdge() {}
    
        FlowEdge(int _v, int _u, long long _cap, long long _flow)
            : v(_v), u(_u), cap(_cap), flow(_flow) {}
    
        FlowEdge(int _v, int _u, long long _cap)
            : v(_v), u(_u), cap(_cap), flow(0ll) {}
      };
    
      constexpr static long long flow_inf = 1e18;
      vector<FlowEdge> edges;
      vector<char> alive;
      vector<long long> pin, pout;
      vector<list<int>> in, out;
      vector<vector<int>> adj;
      vector<long long> ex;
      int n, m = 0;
      int s, t;
      vector<int> level;
      vector<int> q;
      int qh, qt;
    
      void resize(int _n) {
        n = _n;
        ex.resize(n);
        q.resize(n);
        pin.resize(n);
        pout.resize(n);
        adj.resize(n);
        level.resize(n);
        in.resize(n);
        out.resize(n);
      }
    
      MPM() {}
    
      MPM(int _n, int _s, int _t) {
        resize(_n);
        s = _s;
        t = _t;
      }
    
      void add_edge(int v, int u, long long cap) {
        edges.push_back(FlowEdge(v, u, cap));
        edges.push_back(FlowEdge(u, v, 0));
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
      }
    
      bool bfs() {
        while (qh < qt) {
          int v = q[qh++];
          for (int id : adj[v]) {
            if (edges[id].cap - edges[id].flow < 1) continue;
            if (level[edges[id].u] != -1) continue;
            level[edges[id].u] = level[v] + 1;
            q[qt++] = edges[id].u;
          }
        }
        return level[t] != -1;
      }
    
      long long pot(int v) { return min(pin[v], pout[v]); }
    
      void remove_node(int v) {
        for (int i : in[v]) {
          int u = edges[i].v;
          auto it = find(out[u].begin(), out[u].end(), i);
          out[u].erase(it);
          pout[u] -= edges[i].cap - edges[i].flow;
        }
        for (int i : out[v]) {
          int u = edges[i].u;
          auto it = find(in[u].begin(), in[u].end(), i);
          in[u].erase(it);
          pin[u] -= edges[i].cap - edges[i].flow;
        }
      }
    
      void push(int from, int to, long long f, bool forw) {
        qh = qt = 0;
        ex.assign(n, 0);
        ex[from] = f;
        q[qt++] = from;
        while (qh < qt) {
          int v = q[qh++];
          if (v == to) break;
          long long must = ex[v];
          auto it = forw ? out[v].begin() : in[v].begin();
          while (true) {
            int u = forw ? edges[*it].u : edges[*it].v;
            long long pushed = min(must, edges[*it].cap - edges[*it].flow);
            if (pushed == 0) break;
            if (forw) {
              pout[v] -= pushed;
              pin[u] -= pushed;
            } else {
              pin[v] -= pushed;
              pout[u] -= pushed;
            }
            if (ex[u] == 0) q[qt++] = u;
            ex[u] += pushed;
            edges[*it].flow += pushed;
            edges[(*it) ^ 1].flow -= pushed;
            must -= pushed;
            if (edges[*it].cap - edges[*it].flow == 0) {
              auto jt = it;
              ++jt;
              if (forw) {
                in[u].erase(find(in[u].begin(), in[u].end(), *it));
                out[v].erase(it);
              } else {
                out[u].erase(find(out[u].begin(), out[u].end(), *it));
                in[v].erase(it);
              }
              it = jt;
            } else
              break;
            if (!must) break;
          }
        }
      }
    
      long long flow() {
        long long ans = 0;
        while (true) {
          pin.assign(n, 0);
          pout.assign(n, 0);
          level.assign(n, -1);
          alive.assign(n, true);
          level[s] = 0;
          qh = 0;
          qt = 1;
          q[0] = s;
          if (!bfs()) break;
          for (int i = 0; i < n; i++) {
            out[i].clear();
            in[i].clear();
          }
          for (int i = 0; i < m; i++) {
            if (edges[i].cap - edges[i].flow == 0) continue;
            int v = edges[i].v, u = edges[i].u;
            if (level[v] + 1 == level[u] && (level[u] < level[t] || u == t)) {
              in[u].push_back(i);
              out[v].push_back(i);
              pin[u] += edges[i].cap - edges[i].flow;
              pout[v] += edges[i].cap - edges[i].flow;
            }
          }
          pin[s] = pout[t] = flow_inf;
          while (true) {
            int v = -1;
            for (int i = 0; i < n; i++) {
              if (!alive[i]) continue;
              if (v == -1 || pot(i) < pot(v)) v = i;
            }
            if (v == -1) break;
            if (pot(v) == 0) {
              alive[v] = false;
              remove_node(v);
              continue;
            }
            long long f = pot(v);
            ans += f;
            push(v, s, f, false);
            push(v, t, f, true);
            alive[v] = false;
            remove_node(v);
          }
        }
        return ans;
      }
    };
    ```

### ISAP

Trong thuật toán Dinic, sau mỗi lần tìm xong đường tăng luồng, ta đều phải chạy BFS để phân tầng. Có cách nào hiệu quả hơn không?

Câu trả lời chính là thuật toán ISAP được giới thiệu dưới đây.

#### Quy trình

Giống thuật toán Dinic, trước hết ta vẫn chạy BFS để phân tầng các đỉnh trên đồ thị. Tuy nhiên, hơi khác Dinic ở chỗ ta chọn chạy BFS trên đồ thị ngược, từ đỉnh $t$ về đỉnh $s$.

Sau khi thực hiện xong quá trình phân tầng, ta dùng DFS để tìm đường tăng luồng.

Quá trình tăng luồng tương tự Dinic: ta chỉ chọn các đỉnh có số tầng nhỏ hơn đỉnh hiện tại $1$ đơn vị để tăng luồng.

Khác với Dinic, ta không chạy lại BFS để phân tầng lại các đỉnh trên đồ thị, mà hoàn thành việc phân tầng lại ngay trong quá trình tăng luồng.

Cụ thể, giả sử tầng của đỉnh số $i$ là $d_i$. Khi kết thúc quá trình tăng luồng tại đỉnh số $i$, ta duyệt tất cả các cạnh ra của $i$ trên mạng thặng dư, tìm đỉnh ra $j$ có tầng nhỏ nhất, rồi đặt $d_i \gets d_j+1$. Đặc biệt, nếu trên mạng thặng dư $i$ không có cạnh ra, đặt $d_i \gets n$.

Dễ thấy khi $d_s \geq n$, trên đồ thị không tồn tại đường tăng luồng, khi đó có thể kết thúc thuật toán.

Giống Dinic, trong ISAP cũng có **tối ưu cung hiện tại**.

ISAP còn có một tối ưu khác: ta ghi lại số lượng đỉnh có tầng bằng $i$ là $num_i$. Mỗi khi cập nhật tầng của một đỉnh từ $x$ thành $y$, đồng thời cập nhật giá trị mảng $num$. Nếu sau cập nhật $num_x=0$, điều đó nghĩa là trên đồ thị xuất hiện một khoảng trống tầng, không thể tìm thêm đường tăng luồng nữa. Khi đó có thể trực tiếp kết thúc thuật toán, khi cài đặt thì trực tiếp đánh dấu $d_s$ thành $n$. Tối ưu này được gọi là **tối ưu GAP**.

#### Cài đặt

??? note "Mã tham khảo"
    ```cpp
    struct Edge {
      int from, to, cap, flow;
    
      Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
    };
    
    bool operator<(const Edge& a, const Edge& b) {
      return a.from < b.from || (a.from == b.from && a.to < b.to);
    }
    
    struct ISAP {
      int n, m, s, t;
      vector<Edge> edges;
      vector<int> G[MAXN];
      bool vis[MAXN];
      int d[MAXN];
      int cur[MAXN];
      int p[MAXN];
      int num[MAXN];
    
      void AddEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
      }
    
      bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(t);
        vis[t] = true;
        d[t] = 0;
        while (!Q.empty()) {
          int x = Q.front();
          Q.pop();
          for (int i = 0; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i] ^ 1];
            if (!vis[e.from] && e.cap > e.flow) {
              vis[e.from] = true;
              d[e.from] = d[x] + 1;
              Q.push(e.from);
            }
          }
        }
        return vis[s];
      }
    
      void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
      }
    
      int Augment() {
        int x = t, a = INF;
        while (x != s) {
          Edge& e = edges[p[x]];
          a = min(a, e.cap - e.flow);
          x = edges[p[x]].from;
        }
        x = t;
        while (x != s) {
          edges[p[x]].flow += a;
          edges[p[x] ^ 1].flow -= a;
          x = edges[p[x]].from;
        }
        return a;
      }
    
      int Maxflow(int s, int t) {
        this->s = s;
        this->t = t;
        int flow = 0;
        BFS();
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) num[d[i]]++;
        int x = s;
        memset(cur, 0, sizeof(cur));
        while (d[s] < n) {
          if (x == t) {
            flow += Augment();
            x = s;
          }
          int ok = 0;
          for (int i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if (e.cap > e.flow && d[x] == d[e.to] + 1) {
              ok = 1;
              p[e.to] = G[x][i];
              cur[x] = i;
              x = e.to;
              break;
            }
          }
          if (!ok) {
            int m = n - 1;
            for (int i = 0; i < G[x].size(); i++) {
              Edge& e = edges[G[x][i]];
              if (e.cap > e.flow) m = min(m, d[e.to]);
            }
            if (--num[d[x]] == 0) break;
            num[d[x] = m + 1]++;
            cur[x] = 0;
            if (x != s) x = edges[p[x]].from;
          }
        }
        return flow;
      }
    };
    ```

## Thuật toán đẩy tiền luồng Push-Relabel

Phương pháp này bỏ qua tính bảo toàn luồng trong quá trình giải, và mỗi lần cập nhật thông tin của một đỉnh để tìm luồng cực đại.

### Thuật toán đẩy tiền luồng tổng quát

Trước hết ta giới thiệu tư tưởng chính của thuật toán đẩy tiền luồng, cũng như một thuật toán vét cạn khả thi.

Thuật toán đẩy tiền luồng giải luồng cực đại bằng cách cập nhật từng đỉnh cho đến khi không còn đỉnh nào cần cập nhật.

Hàm luồng được duy trì trong quá trình thuật toán không nhất thiết luôn thỏa mãn bảo toàn luồng. Với một đỉnh, ta cho phép luồng đi vào đỉnh lớn hơn luồng đi ra khỏi đỉnh; phần vượt quá được gọi là **luồng dư** $e(u)$ của đỉnh $u(u\in V-\{s,t\})$:

$$
e(u)=\sum_{(x,u)\in E}f(x,u)-\sum_{(u,y)\in E}f(u,y)
$$

Nếu $e(u)>0$, gọi đỉnh $u$ là **đang hoạt động**[^note1]. Chú ý rằng khi nói đến đỉnh đang hoạt động, ta không bao gồm $s$ và $t$.

Thuật toán đẩy tiền luồng duy trì độ cao $h(u)$ của mỗi đỉnh và quy định rằng nếu đỉnh đang hoạt động $u$ muốn đẩy luồng dư, nó chỉ có thể đẩy đến các đỉnh có độ cao nhỏ hơn $u$. Nếu $u$ không có đỉnh kề nào có độ cao nhỏ hơn $u$, thì sửa độ cao của $u$, tức gán lại nhãn.

#### Hàm độ cao[^note2]

Nói chính xác, đẩy tiền luồng duy trì ánh xạ sau $h:V\to \mathbf{N}$:

-   $h(s)=|V|,h(t)=0$
-   $\forall (u,v)\in E_f,h(u)\leq h(v)+1$

Gọi $h$ là hàm độ cao của mạng thặng dư $G_f=(V_f,E_f)$.

Bổ đề 1: giả sử hàm độ cao trên $G_f$ là $h$. Với hai đỉnh bất kỳ $u,v\in V$, nếu $h(u)>h(v)+1$ thì $(u,v)$ không phải là cạnh trong $G_f$.

Thuật toán chỉ thực hiện đẩy trên các cạnh có $h(u)=h(v)+1$.

#### Đẩy (Push)

Điều kiện áp dụng: đỉnh $u$ đang hoạt động, và tồn tại đỉnh $v((u,v)\in E_f,c(u,v)-f(u,v)>0,h(u)=h(v)+1)$. Khi đó thao tác push áp dụng được cho $(u,v)$.

Vì vậy, ta cố gắng đẩy nhiều nhất có thể luồng dư từ $u$ sang $v$. Trong quá trình đẩy, ta chỉ quan tâm giá trị nhỏ nhất giữa luồng dư và $c(u,v)-f(u,v)$, không quan tâm $v$ có trở thành đỉnh đang hoạt động hay không.

Nếu $(u,v)$ đầy luồng sau khi đẩy xong, xóa nó khỏi mạng thặng dư.

#### Gán lại nhãn (Relabel)

Điều kiện áp dụng: nếu đỉnh $u$ đang hoạt động, và $\forall (u,v)\in E_f,h(u)\leq h(v)$, thì thao tác relabel áp dụng được cho $u$.

Khi đó chỉ cần cập nhật $h(u)$ thành $\min_{(u,v)\in E_f}h(v)+1$.

#### Khởi tạo

$$
\forall (u,v)\in E,~~f(u,v)=\begin{cases}
c(u,v),&u=s\\
0,&u\neq s
\end{cases}
$$

$$
\forall u\in V,~~h(u)=\begin{cases}
|V|,&u=s\\
0,&u\neq s
\end{cases}
$$

$$
e(u)=\sum_{(x,u)\in E}f(x,u)-\sum_{(u,y)\in E}f(u,y)
$$

Ở trên ta lấp đầy luồng trên các cạnh $(s,v)\in E$ và nâng $h(s)$ lên, khiến $(s,v)\notin E_f$, vì $h(s)>h(v)$, hơn nữa $(s,v)$ vốn đã đầy luồng nên không cần giữ trong mạng thặng dư. Ở trên cũng khởi tạo $e(s)$ bằng số đối của $\sum_{(s,v)\in E}f(s,v)$.

#### Quy trình

Mỗi lần ta quét toàn bộ đồ thị. Chỉ cần tồn tại đỉnh $u$ thỏa mãn điều kiện của thao tác push hoặc relabel, ta thực hiện thao tác tương ứng.

Như trong hình, giữa mỗi đỉnh biểu diễn số hiệu, góc trái dưới biểu diễn giá trị độ cao $h(u)$, góc phải dưới biểu diễn luồng dư $e(u)$, độ đậm màu của đỉnh cũng biểu diễn độ cao của đỉnh; trọng số cạnh biểu diễn $c(u,v)-f(u,v)$, cạnh màu xanh lá biểu diễn cạnh $(u,v)$ thỏa mãn $h(u)=h(v)+1$, tức cạnh của mạng thặng dư $E_f$:

![Trạng thái ban đầu của thuật toán push-relabel](./images/2148.png)

Ta xem qua toàn bộ quá trình của thuật toán. Ở đây tác giả dùng một thuật toán vét cạn, tức quét vét cạn xem có đỉnh đang hoạt động nào không; nếu có thì cập nhật.

![Quá trình chạy thuật toán push-relabel](./images/2149.gif)

Kết quả cuối cùng:

![Kết quả cuối cùng của thuật toán push-relabel](./images/2150.png)

Có thể thấy cuối cùng một phần luồng dư đã quay về $s$, và ngoài nguồn và đích, các đỉnh khác đều không còn đang hoạt động. Khi đó hàm luồng $f$ thỏa mãn bảo toàn luồng, là luồng cực đại, và giá trị luồng là $e(t)$.

Tuy nhiên, trên thực tế bài báo[^ref1] chỉ ra rằng chỉ xử lý các đỉnh đang hoạt động có độ cao nhỏ hơn $n$ cũng có thể thu được đúng giá trị luồng cực đại. Nhưng như vậy, khi thuật toán kết thúc, tiền luồng vẫn chưa thỏa mãn tính chất của hàm luồng, nên không biết được luồng thực sự trên từng cạnh.

#### Cài đặt

???+ note "Mã cốt lõi"
    ```cpp
    constexpr int N = 1e4 + 4, M = 1e5 + 5, INF = 0x3f3f3f3f;
    int n, m, s, t, maxflow, tot;
    int ht[N], ex[N];
    
    void init() {  // khởi tạo
      for (int i = h[s]; i; i = e[i].nex) {
        const int &v = e[i].t;
        ex[v] = e[i].v, ex[s] -= ex[v], e[i ^ 1].v = e[i].v, e[i].v = 0;
      }
      ht[s] = n;
    }
    
    bool push(int ed) {
      const int &u = e[ed ^ 1].t, &v = e[ed].t;
      int flow = min(ex[u], e[ed].v);
      ex[u] -= flow, ex[v] += flow, e[ed].v -= flow, e[ed ^ 1].v += flow;
      return ex[u];  // nếu u vẫn hoạt động, trả về 1
    }
    
    void relabel(int u) {
      ht[u] = INF;
      for (int i = h[u]; i; i = e[i].nex)
        if (e[i].v) ht[u] = min(ht[u], ht[e[i].t]);
      ++ht[u];
    }
    ```

### Thuật toán HLPP

Thuật toán đẩy tiền luồng nhãn cao nhất (Highest Label Preflow Push) trong thuật toán đẩy tiền luồng tổng quát ở trên luôn ưu tiên chọn đỉnh đang hoạt động có độ cao lớn nhất mỗi khi chọn đỉnh. Độ phức tạp của thuật toán là $O(n^2\sqrt m)$.

#### Quy trình

Cụ thể, quy trình của thuật toán HLPP như sau:

1.  Khởi tạo, dựa trên thuật toán đẩy tiền luồng.
2.  Chọn đỉnh $u$ có độ cao lớn nhất trong các đỉnh đang hoạt động, và thực hiện đẩy trên tất cả các cạnh có thể đẩy của nó.
3.  Nếu $u$ vẫn đang hoạt động, gán lại nhãn cho nó rồi quay lại bước 2.
4.  Nếu không có đỉnh đang hoạt động, thuật toán kết thúc.

Một bài báo kiểm thử hiệu năng thực tế của các thuật toán luồng cực đại[^ref2] cho thấy các thuật toán dựa trên tiền luồng thực ra tốn một phần đáng kể thời gian ở bước gán lại nhãn. Sau đây giới thiệu hai tối ưu từ bài báo[^ref3] có thể giảm đáng kể số lần gán lại nhãn.

#### Tối ưu BFS

Cận trên của HLPP là $O(n^2\sqrt m)$, nhưng khi sử dụng thì khá sát; ta có thể tối ưu lúc khởi tạo độ cao. Cụ thể, khởi tạo $h(u)$ là khoảng cách ngắn nhất từ $u$ đến $t$; đặc biệt $h(s)=n$.

Trong khi BFS, ta đồng thời kiểm tra tính liên thông của đồ thị để loại trường hợp không có nghiệm.

#### Tối ưu GAP

Điều kiện đẩy của HLPP là $h(u)=h(v)+1$. Nếu tại một thời điểm nào đó của thuật toán tồn tại một $k$ sao cho số đỉnh có $h(u)=k$ bằng $0$, thì các đỉnh có $h(u)>k$ sẽ mãi không thể đẩy luồng dư đến $t$, mà chỉ có thể đưa ngược về $s$. Vì vậy lúc này ta trực tiếp đặt độ cao của chúng thành ít nhất $n+1$ để nhanh chóng đẩy ngược về $s$, giảm thao tác gán lại nhãn.

Cài đặt dưới đây dùng phương pháp trong bài báo[^ref2], sử dụng $N*2-1$ xô `B`, trong đó `B[i]` ghi lại tất cả các đỉnh đang hoạt động hiện có độ cao $i$. Cài đặt đã thêm hai tối ưu nói trên, và chỉ xử lý các đỉnh đang hoạt động có độ cao nhỏ hơn $n$.

Điều đáng chú ý là xô trong bài báo[^ref2] được cài đặt bằng stack dựa trên danh sách liên kết, còn container mặc định của `stack` trong STL là `deque`. Qua kiểm thử đơn giản, `vector`, `deque`, `list` không khác biệt nhiều về hiệu suất trong quá trình chạy thực tế của bài này.

#### Cài đặt

??? note "LuoguP4722 [Mẫu] Luồng cực đại bản tăng cường / đẩy tiền luồng"
    ```cpp
    #include <cstdio>
    #include <cstring>
    #include <queue>
    #include <stack>
    using namespace std;
    constexpr int N = 1200, M = 120000, INF = 0x3f3f3f3f;
    int n, m, s, t;
    
    struct qxx {
      int nex, t;
      long long v;
    };
    
    qxx e[M * 2 + 1];
    int h[N + 1], cnt = 1;
    
    void add_path(int f, int t, long long v) {
      e[++cnt] = qxx{h[f], t, v}, h[f] = cnt;
    }
    
    void add_flow(int f, int t, long long v) {
      add_path(f, t, v);
      add_path(t, f, 0);
    }
    
    int ht[N + 1];        // độ cao
    long long ex[N + 1];  // lượng dư
    int gap[N];           // tối ưu gap. gap[i] là số đỉnh có độ cao i
    stack<int> B[N];      // bucket B[i] ghi tất cả v có ht[v] == i
    int level = 0;        // độ cao lớn nhất của đỉnh đang hoạt động
    
    int push(int u) {      // đẩy lượng dư qua các cạnh có thể đẩy nhiều nhất có thể
      bool init = u == s;  // có đang khởi tạo không
      for (int i = h[u]; i; i = e[i].nex) {
        const int &v = e[i].t;
        const long long &w = e[i].v;
        // Khi khởi tạo không xét hiệu độ cao bằng 1
        if (!w || (init == false && ht[u] != ht[v] + 1) || ht[v] == INF) continue;
        long long k = init ? w : min(w, ex[u]);
        // Lấy min của dung lượng còn dư và lượng dư. Khi khởi tạo có thể làm lượng dư của nguồn âm.
        if (v != s && v != t && !ex[v]) B[ht[v]].push(v), level = max(level, ht[v]);
        ex[u] -= k, ex[v] += k, e[i].v -= k, e[i ^ 1].v += k;  // push
        if (!ex[u]) return 0;  // nếu đã đẩy hết thì trả về
      }
      return 1;
    }
    
    void relabel(int u) {  // gán lại nhãn, tức độ cao
      ht[u] = INF;
      for (int i = h[u]; i; i = e[i].nex)
        if (e[i].v) ht[u] = min(ht[u], ht[e[i].t]);
      if (++ht[u] < n) {  // chỉ xử lý đỉnh có độ cao nhỏ hơn n
        B[ht[u]].push(u);
        level = max(level, ht[u]);
        ++gap[ht[u]];  // độ cao mới, cập nhật gap
      }
    }
    
    bool bfs_init() {
      memset(ht, 0x3f, sizeof(ht));
      queue<int> q;
      q.push(t), ht[t] = 0;
      while (q.size()) {  // BFS ngược, gặp đỉnh chưa thăm thì đưa vào hàng đợi
        int u = q.front();
        q.pop();
        for (int i = h[u]; i; i = e[i].nex) {
          const int &v = e[i].t;
          if (e[i ^ 1].v && ht[v] > ht[u] + 1) ht[v] = ht[u] + 1, q.push(v);
        }
      }
      return ht[s] != INF;  // nếu đồ thị không liên thông, trả về 0
    }
    
    // Chọn một trong các đỉnh có độ cao lớn nhất hiện tại, nếu không còn đỉnh đang hoạt động thì trả về 0
    int select() {
      while (level > -1 && B[level].size() == 0) level--;
      return level == -1 ? 0 : B[level].top();
    }
    
    long long hlpp() {            // trả về luồng cực đại
      if (!bfs_init()) return 0;  // đồ thị không liên thông
      memset(gap, 0, sizeof(gap));
      for (int i = 1; i <= n; i++)
        if (ht[i] != INF) gap[ht[i]]++;  // khởi tạo gap
      ht[s] = n;
      push(s);  // khởi tạo tiền luồng
      int u;
      while ((u = select())) {
        B[level].pop();
        if (push(u)) {  // vẫn đang hoạt động
          if (!--gap[ht[u]])
            for (int i = 1; i <= n; i++)
              if (i != s && ht[i] > ht[u] && ht[i] < n + 1)
                ht[i] = n + 1;  // các đỉnh được gán lại thành n+1 ở đây đều không đang hoạt động
          relabel(u);
        }
      }
      return ex[t];
    }
    
    int main() {
      scanf("%d%d%d%d", &n, &m, &s, &t);
      for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add_flow(u, v, w);
      }
      printf("%lld", hlpp());
      return 0;
    }
    ```

Xem qua quá trình chạy:

![Quá trình chạy HLPP với tối ưu GAP](./images/1152.png)

Trong đó từ pic13 đến pic14 thực hiện Relabel(4), đồng thời thực hiện tối ưu GAP.

## Chú thích

[^ref_ek]: <http://pisces.ck.tp.edu.tw/~peng/index.php?action=showfile&file=f6cdf7ef750d7dc79c7d599b942acbaaee86a2e3e>

[^ref_dinic]: <https://people.orie.cornell.edu/dpw/orie633/LectureNotes/lecture9.pdf>

[^ref1]: Cherkassky B V, Goldberg A V. On implementing push-relabel method for the maximum flow problem\[C]//International Conference on Integer Programming and Combinatorial Optimization. Springer, Berlin, Heidelberg, 1995: 157-171.

[^ref2]: Ahuja R K, Kodialam M, Mishra A K, et al. Computational investigations of maximum flow algorithms\[J]. European Journal of Operational Research, 1997, 97(3): 509-542.

[^ref3]: Derigs U, Meier W. Implementing Goldberg's max-flow-algorithm—A computational investigation\[J]. Zeitschrift für Operations Research, 1989, 33(6): 383-403.

[^note1]: Trong tài liệu tiếng Anh thường gọi là "active".

[^note2]: Trong tài liệu tiếng Anh, độ cao của một đỉnh thường được gọi là "distance label". Thuật ngữ "độ cao" dùng ở đây bắt nguồn từ chương liên quan trong Introduction to Algorithms.
