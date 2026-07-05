author: AntiLeaf

Thuật toán Berlekamp–Massey là thuật toán dùng để tìm hệ thức truy hồi ngắn nhất của một dãy số. Cho một dãy có độ dài $n$, nếu bậc của hệ thức truy hồi ngắn nhất là $m$, thì thuật toán Berlekamp–Massey có thể tìm hệ thức truy hồi ngắn nhất của từng tiền tố của dãy trong thời gian $O(nm)$. Trong trường hợp xấu nhất $m = O(n)$, vì vậy độ phức tạp xấu nhất của thuật toán là $O(n^2)$.

<span id="định-nghĩa"></span>

### Định nghĩa

Định nghĩa một hệ thức truy hồi của dãy $\{a_0 \dots a_{n - 1} \}$ là dãy $\{r_0\dots r_m\}$ thỏa mãn:

$\sum_{j = 0} ^ m r_j a_{i - j} = 0, \forall i \ge m$

trong đó $r_0 = 1$. $m$ được gọi là **bậc** của hệ thức truy hồi này.

Hệ thức truy hồi ngắn nhất của dãy $\{a_i\}$ là hệ thức truy hồi có bậc nhỏ nhất.

<span id="cách-làm"></span>

### Cách làm

Hơi khác với định nghĩa ở trên, ở đây ta định nghĩa một bộ hệ số truy hồi mới $\{f_0 \dots f_{m - 1}\}$, thỏa mãn:

$a_i = \sum_{j = 0} ^ {m - 1} f_j a_{i - j - 1}, \forall i \ge m$

Dễ thấy $f_i = -r_{i + 1}$, và bậc $m$ vẫn giống với định nghĩa trước đó.

Ta có thể tìm hệ thức truy hồi theo kiểu tăng dần: xét lần lượt từng phần tử của $\{a_i\}$, và khi kết quả truy hồi bị sai thì điều chỉnh các hệ số truy hồi $\{f_i\}$. Để thuận tiện, dưới đây ký hiệu hệ thức truy hồi ngắn nhất của $i$ phần tử đầu là $F_i = \{f_{i, j}\}$.

Hiển nhiên ban đầu có $F_0 = \{\}$. Giả sử các hệ số truy hồi $F_{i - 1}$ đều đúng với $i - 1$ phần tử đầu của dãy $\{a_i\}$; khi đó với phần tử thứ $i$ có hai trường hợp:

1.  Các hệ số truy hồi cũng đúng với $a_i$. Khi đó không cần điều chỉnh gì, chỉ cần đặt $F_i = F_{i - 1}$.
2.  Các hệ số truy hồi không đúng với $a_i$. Khi đó cần điều chỉnh $F_{i - 1}$ để thu được $F_i$ mới.

Đặt $\Delta_i = a_i - \sum_{j = 0} ^ m f_{i - 1, j} a_{i - j - 1}$, tức là hiệu giữa $a_i$ và kết quả truy hồi do $F_{i - 1}$ sinh ra.

Nếu đây là lần đầu tiên sửa các hệ số truy hồi, điều đó cho thấy $a_i$ là phần tử khác $0$ đầu tiên trong dãy. Khi đó chỉ cần đặt $F_i$ là $i$ số $0$; rõ ràng đây là một hệ thức truy hồi ngắn nhất hợp lệ.

Ngược lại, giả sử ở lần sửa hệ số truy hồi trước đó, số phần tử $\{a_i\}$ đã được xét là $k$. Nếu tồn tại một dãy $G = \{g_0 \dots g_{m' - 1}\}$ thỏa mãn:

$\sum_{j = 0} ^ {m' - 1} g_j a_{i' - j - 1} = 0, \forall i' \in [m', i)$

và $\sum_{j = 0} ^ {m' - 1} g_j a_{i - j - 1} = \Delta_i$, thì không khó nhận ra rằng cộng từng vị trí $F_k$ với $G$ sẽ cho một bộ hệ số truy hồi hợp lệ $F_i$.

Xét cách xây dựng $G$. Một cách xây dựng khả thi là đặt

$G = \{0, 0, \dots, 0, \frac{\Delta_i}{\Delta_k}, -\frac{\Delta_i}{\Delta_k}F_{k-1}\}$

trong đó phía trước có tổng cộng $i - k - 1$ số $0$, còn $-\frac{\Delta_i}{\Delta_k} F_{k-1}$ ở cuối biểu thị việc nhân từng phần tử của $F_{k-1}$ với $-\frac{\Delta_i}{\Delta_k}$ rồi nối vào sau dãy.

Không khó kiểm chứng rằng lúc này $\sum_{j = 0} ^ {m' - 1} g_j a_{i - j - 1} = \Delta_k \frac{\Delta_i}{\Delta_k} = \Delta_i$, nên $G$ được xây dựng như vậy là hợp lệ. Chỉ cần gán $F_i$ bằng kết quả cộng từng phần tử của $F_k$ và $G$.

Nếu cần hệ thức truy hồi $\{r_i\}$ phù hợp với định nghĩa ban đầu, chỉ cần đổi dấu toàn bộ $\{f_j\}$ rồi chèn $r_0 = 1$ vào đầu.

Từ quy trình thuật toán trên có thể thấy, nếu bậc của hệ thức truy hồi ngắn nhất của dãy là $m$, thì độ phức tạp của thuật toán là $O(nm)$. Trong trường hợp xấu nhất $m = O(n)$, vì vậy độ phức tạp xấu nhất của thuật toán là $O(n^2)$.

Khi cài đặt thuật toán, do mỗi lần điều chỉnh hệ số truy hồi chỉ cần dùng đến các hệ số truy hồi $F_k$ tại lần điều chỉnh trước, nên nếu chỉ cần tìm hệ thức truy hồi ngắn nhất của toàn bộ dãy, ta có thể chỉ lưu các hệ số truy hồi hiện tại và các hệ số truy hồi ở lần điều chỉnh trước. Độ phức tạp bộ nhớ là $O(n)$.

??? note "Cài đặt tham khảo"
    ```cpp
    vector<int> berlekamp_massey(const vector<int> &a) {
      vector<int> v, last;  // v is the answer, 0-based, p is the module
      int k = -1, delta = 0;
    
      for (int i = 0; i < (int)a.size(); i++) {
        int tmp = 0;
        for (int j = 0; j < (int)v.size(); j++)
          tmp = (tmp + (long long)a[i - j - 1] * v[j]) % p;
    
        if (a[i] == tmp) continue;
    
        if (k < 0) {
          k = i;
          delta = (a[i] - tmp + p) % p;
          v = vector<int>(i + 1);
    
          continue;
        }
    
        vector<int> u = v;
        int val = (long long)(a[i] - tmp + p) * power(delta, p - 2) % p;
    
        if (v.size() < last.size() + i - k) v.resize(last.size() + i - k);
    
        (v[i - k - 1] += val) %= p;
    
        for (int j = 0; j < (int)last.size(); j++) {
          v[i - k + j] = (v[i - k + j] - (long long)val * last[j]) % p;
          if (v[i - k + j] < 0) v[i - k + j] += p;
        }
    
        if ((int)u.size() - i < (int)last.size() - k) {
          last = u;
          k = i;
          delta = a[i] - tmp;
          if (delta < 0) delta += p;
        }
      }
    
      for (auto &x : v) x = (p - x) % p;
      v.insert(v.begin(), 1);
    
      return v;  // $\forall i, \sum_{j = 0} ^ m a_{i - j} v_j = 0$
    }
    ```

Thuật toán Berlekamp–Massey đơn giản giải hệ thức truy hồi ngắn nhất của một dãy có số hạng hữu hạn. Nếu dãy cần tìm hệ thức truy hồi có vô hạn số hạng, nhưng đã biết cận trên của bậc hệ thức truy hồi ngắn nhất, thì chỉ cần lấy $2m$ số hạng đầu của dãy là có thể tìm được hệ thức truy hồi ngắn nhất của toàn bộ dãy. (Lược bỏ chứng minh)

<span id="ứng-dụng"></span>

### Ứng dụng

Do tính ổn định số của thuật toán Berlekamp–Massey khá kém, thuật toán này thường hiếm khi được dùng để xử lý các bài toán trên số thực. Để tiện trình bày, dưới đây đều giả định các phép toán được thực hiện trong hệ thặng dư theo một số nguyên tố $p$.

<span id="tìm-hệ-thức-truy-hồi-ngắn-nhất-của-dãy-vector-hoặc-dãy-ma-trận"></span>

#### Tìm hệ thức truy hồi ngắn nhất của dãy vector hoặc dãy ma trận

Nếu cần tìm hệ thức truy hồi ngắn nhất của dãy vector $\boldsymbol{v}_i$, giả sử chiều của vector là $n$, ta có thể chọn ngẫu nhiên một vector hàng $n$ chiều $\mathbf u^T$, rồi tính hệ thức truy hồi ngắn nhất của dãy vô hướng $\{\boldsymbol{u}^T\boldsymbol{v}_i\}$. Theo bổ đề Schwartz–Zippel, hệ thức truy hồi ngắn nhất của hai dãy trùng nhau với xác suất ít nhất $1 - \frac n p$.

Việc tìm hệ thức truy hồi ngắn nhất của dãy ma trận $\{A_i\}$ cũng tương tự. Giả sử kích thước ma trận là $n \times m$, ta chỉ cần chọn ngẫu nhiên một vector hàng $1 \times n$ $\mathbf u^T$ và một vector cột $m \times 1$ $\boldsymbol{v}$, rồi tính hệ thức truy hồi ngắn nhất của dãy vô hướng $\{\boldsymbol{u}^T A_i \boldsymbol{v}\}$. Từ bổ đề Schwartz–Zippel cũng có thể suy ra tương tự rằng xác suất hai hệ thức truy hồi trùng nhau ít nhất là $1 - \frac{n + m} p$.

<span id="tối-ưu-lũy-thừa-nhanh-ma-trận"></span>

#### Tối ưu lũy thừa nhanh ma trận

Giả sử $\boldsymbol{f}_i$ là một vector cột $n$ chiều, và phép chuyển trạng thái thỏa mãn $\boldsymbol{f}_i = A \boldsymbol{f}_{i - 1}$. Khi đó có thể thấy $\{\boldsymbol{f}_i\}$ là một dãy vector truy hồi tuyến tính bậc không quá $n$. (Lược bỏ chứng minh)

Ta có thể trực tiếp tính vét cạn $\boldsymbol{f}_0 \dots \boldsymbol{f}_{2n - 1}$, sau đó dùng cách đã nêu ở trên để tìm hệ thức truy hồi ngắn nhất của $\{\boldsymbol{f}_i\}$, rồi gọi [truy hồi tuyến tính thuần nhất hệ số hằng](./poly/linear-recurrence.md).

Nếu vector cần tìm là $\boldsymbol{f}_m$, độ phức tạp của thuật toán là $O(n^3 + n\log n \log m)$. Nếu $A$ là ma trận thưa chỉ có $k$ phần tử khác $0$, độ phức tạp có thể giảm xuống $O(nk + n\log n \log m)$. Tuy nhiên, vì thuật toán ít nhất cần thời gian tiền xử lý $O(nk)$, nên khi giới hạn không quá chặt cũng có thể dùng thuật toán truy hồi tuyến tính $O(n^2 \log m)$; độ phức tạp này vẫn chấp nhận được.

<span id="tìm-đa-thức-tối-tiểu-của-ma-trận"></span>

#### Tìm đa thức tối tiểu của ma trận

Đa thức tối tiểu của ma trận vuông $A$ là đa thức $f$ có bậc nhỏ nhất và thỏa mãn $f(A) = 0$.

Thực ra đa thức tối tiểu chính là hệ thức truy hồi tối tiểu của $\{A^i\}$, nên chỉ cần gọi trực tiếp thuật toán Berlekamp–Massey. Nếu $A$ là ma trận vuông cấp $n$, thì hiển nhiên bậc của đa thức tối tiểu không vượt quá $n$.

Nút thắt nằm ở việc tính $A^i$, vì nếu mỗi lần đều nhân ma trận trực tiếp thì độ phức tạp sẽ lên tới $O(n^4)$. Nhưng xét rằng khi tìm hệ thức truy hồi ngắn nhất của dãy ma trận, thực chất ta đang tìm hệ thức truy hồi ngắn nhất của $\{\boldsymbol{u}^T A^i \boldsymbol{v}\}$, nên ta chỉ cần tính $A^i \boldsymbol{v}$.

Giả sử $A$ có $k$ phần tử khác $0$, độ phức tạp là $O(kn + n^2)$.

<span id="tìm-định-thức-của-ma-trận-thưa"></span>

#### Tìm định thức của ma trận thưa

Nếu có thể tìm đa thức đặc trưng của ma trận vuông $A$, thì hạng tử tự do nhân với $(-1)^n$ chính là định thức. Tuy nhiên, đa thức tối tiểu không nhất thiết là đa thức đặc trưng.

Thực ra nếu nhân $A$ với một ma trận đường chéo ngẫu nhiên $B$, thì đa thức tối tiểu của $AB$ là đa thức đặc trưng với xác suất ít nhất $1 - \frac {2n^2 - n} p$. Cuối cùng chỉ cần chia cho $\text{det}\;B$.

Giả sử $A$ là ma trận vuông cấp $n$ và có $k$ phần tử khác $0$, độ phức tạp là $O(kn + n ^ 2)$.

<span id="tìm-hạng-của-ma-trận-thưa"></span>

#### Tìm hạng của ma trận thưa

Giả sử $A$ là ma trận $n\times m$. Trước hết chọn ngẫu nhiên một ma trận đường chéo $n\times n$ $P$ và một ma trận đường chéo $m\times m$ $Q$, sau đó tính đa thức tối tiểu của $Q A P A^T Q$.

Thực ra không cần gọi phép nhân ma trận, vì khi tìm đa thức tối tiểu ta cần nhân $Q A P A^T Q$ với một vector, nên chỉ cần lần lượt nhân các ma trận này vào vector. Đáp án chính là bậc còn lại sau khi loại bỏ toàn bộ nhân tử $x$ khỏi đa thức tối tiểu.

Giả sử $A$ có $k$ phần tử khác $0$ và $n \le m$, độ phức tạp là $O(kn + n ^ 2)$.

<span id="giải-hệ-phương-trình-thưa"></span>

#### Giải hệ phương trình thưa

**Bài toán**: Biết $A \mathbf x = \mathbf b$, trong đó $A$ là một ma trận thưa $n \times n$ **đầy hạng**, còn $\mathbf b$ và $\mathbf x$ là các vector cột $1\times n$. Đã biết $A, \mathbf b$, cần giải $x$ với độ phức tạp thấp hơn $n^\omega$.

**Cách làm**: Hiển nhiên $\mathbf x = A^{-1} \mathbf b$. Nếu ta có thể tìm hệ thức truy hồi tối tiểu $\{r_0 \dots r_{m - 1}\}$($m \le n$) của $\{A^i \mathbf b\}$($i \ge 0$), thì có kết luận

$A^{-1} \mathbf b = -\frac 1 {r_{m - 1}} \sum_{i = 0} ^ {m - 2} A^i \mathbf b r_{m - 2 - i}$

(Lược bỏ chứng minh)

Vì $A$ là ma trận thưa, chỉ cần truy hồi trực tiếp theo định nghĩa để tính $\mathbf b \dots A^{2n - 1} \mathbf b$.

Tương tự, giả sử $A$ có $k$ phần tử khác $0$, độ phức tạp là $O(kn + n^2)$.

??? note "Cài đặt tham khảo"
    ```cpp
    vector<int> solve_sparse_equations(const vector<tuple<int, int, int>> &A,
                                       const vector<int> &b) {
      int n = (int)b.size();  // 0-based
    
      vector<vector<int>> f({b});
    
      for (int i = 1; i < 2 * n; i++) {
        vector<int> v(n);
        auto &u = f.back();
    
        for (auto [x, y, z] : A)  // [x, y, value]
          v[x] = (v[x] + (long long)u[y] * z) % p;
    
        f.push_back(v);
      }
    
      vector<int> w(n);
      mt19937 gen;
      for (auto &x : w) x = uniform_int_distribution<int>(1, p - 1)(gen);
    
      vector<int> a(2 * n);
      for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < n; j++) a[i] = (a[i] + (long long)f[i][j] * w[j]) % p;
    
      auto c = berlekamp_massey(a);
      int m = (int)c.size();
    
      vector<int> ans(n);
    
      for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < n; j++)
          ans[j] = (ans[j] + (long long)c[m - 2 - i] * f[i][j]) % p;
    
      int inv = power(p - c[m - 1], p - 2);
    
      for (int i = 0; i < n; i++) ans[i] = (long long)ans[i] * inv % p;
    
      return ans;
    }
    ```

<span id="bài-tập-ví-dụ"></span>

### Bài tập ví dụ

1.  [LibreOJ #163. Khử Gauss 2](https://loj.ac/p/163)
2.  [ICPC 2021 Đài Bắc Gym103443E. Composition with Large Red Plane, Yellow, Black, Gray, and Blue](https://codeforces.com/gym/103443/problem/E)
