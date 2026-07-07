<span id="định-nghĩa"></span>
## Định nghĩa

Trie, hay cây từ điển, đúng như tên gọi: đây là một cấu trúc cây giống như một cuốn từ điển.

<span id="giới-thiệu"></span>
## Giới thiệu

Trước hết xem hình sau:

![Ví dụ cây trie biểu diễn các xâu](./images/trie1.png)

Cây trie này dùng cạnh để biểu diễn chữ cái, và đường đi từ gốc đến một đỉnh nào đó trên cây biểu diễn một xâu. Ví dụ, $1\to4\to 8\to 12$ biểu diễn xâu `caa`.

Cấu trúc trie dễ hiểu. Dùng $\delta(u,c)$ để chỉ đỉnh tiếp theo mà ký tự $c$ của đỉnh $u$ trỏ đến; nói cách khác, đó là đỉnh của xâu thu được khi thêm một ký tự $c$ vào sau xâu mà đỉnh $u$ biểu diễn. (Phạm vi giá trị của $c$ phụ thuộc vào kích thước bảng chữ cái, không nhất thiết là $0\sim 26$.)

Đôi khi cần đánh dấu những xâu nào đã được chèn vào trie. Khi chèn xong, chỉ cần đánh dấu tại đỉnh biểu diễn xâu đó.

<span id="cài-đặt"></span>
## Cài đặt

Một mẫu cài đặt đóng gói bằng struct:

=== "C++"
    ```cpp
    struct trie {
      int nex[100000][26], cnt;
      bool exist[100000];  // Có xâu nào kết thúc tại đỉnh này hay không
    
      void insert(char *s, int l) {  // Chèn xâu
        int p = 0;
        for (int i = 0; i < l; i++) {
          int c = s[i] - 'a';
          if (!nex[p][c]) nex[p][c] = ++cnt;  // Nếu chưa có thì thêm đỉnh
          p = nex[p][c];
        }
        exist[p] = true;
      }
    
      bool find(char *s, int l) {  // Tìm xâu
        int p = 0;
        for (int i = 0; i < l; i++) {
          int c = s[i] - 'a';
          if (!nex[p][c]) return 0;
          p = nex[p][c];
        }
        return exist[p];
      }
    };
    ```

=== "Python"
    ```python
    class trie:
        def __init__(self):
            self.nex = [[0 for i in range(26)] for j in range(100000)]
            self.cnt = 0
            self.exist = [False] * 100000  # Có xâu nào kết thúc tại đỉnh này hay không
    
        def insert(self, s):  # Chèn xâu
            p = 0
            for i in s:
                c = ord(i) - ord("a")
                if not self.nex[p][c]:
                    self.cnt += 1
                    self.nex[p][c] = self.cnt  # Nếu chưa có thì thêm đỉnh
                p = self.nex[p][c]
            self.exist[p] = True
    
        def find(self, s):  # Tìm xâu
            p = 0
            for i in s:
                c = ord(i) - ord("a")
                if not self.nex[p][c]:
                    return False
                p = self.nex[p][c]
            return self.exist[p]
    ```

=== "Java"
    ```java
    public class Trie {
        int[][] tree = new int[10000][26];
        int cnt = 0;
        boolean[] end = new boolean[10000];
        
        public void insert(String word) {
            int p = 0;
            char[] chars = word.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                int c = chars[i] - 'a';
                if (tree[p][c] == 0) {
                    tree[p][c] = ++cnt;
                }
                p = tree[p][c];
            }
            end[p] = true;
        }
        
        public boolean find(String word) {
            int p = 0;
            char[] chars = word.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                int c = chars[i] - 'a';
                if (tree[p][c] == 0) {
                    return false;
                }
                p = tree[p][c];
            }
            return end[p];
        }
    }
    ```

<span id="ứng-dụng"></span>
## Ứng dụng

<span id="truy-vấn-xâu"></span>
### Truy vấn xâu

Ứng dụng cơ bản nhất của trie là kiểm tra một xâu có từng xuất hiện trong "từ điển" hay không.

???+ note "[Bài điểm danh sai của anh ấy](https://www.luogu.com.cn/problem/P2580)"
    Cho $n$ xâu tên, sau đó thực hiện $m$ lần điểm danh. Mỗi lần cần trả lời một trong ba trạng thái: "tên không tồn tại", "lần đầu điểm đến tên này", hoặc "tên này đã được điểm".
    
    $1\le n\le 10^4$, $1\le m\le 10^5$, mọi xâu có độ dài không quá $50$.
    
    ??? note "Lời giải"
        Xây trie cho tất cả các tên. Khi truy vấn, kiểm tra xâu có tồn tại trong trie không và đã được điểm danh chưa; nếu là lần đầu thì đánh dấu là đã điểm danh.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/string/code/trie/trie_1.cpp"
        ```

<span id="máy-tự-động-ac"></span>
### Máy tự động AC

Trie là một phần của [máy tự động AC](./ac-automaton.md).

<span id="duy-trì-cực-trị-xor"></span>
### Duy trì cực trị xor

Nếu xem biểu diễn nhị phân của một số như một xâu, có thể xây dựng một trie với bảng chữ cái $\{0,1\}$.

???+ note "[BZOJ1954 Đường đi xor dài nhất](https://hydro.ac/p/bzoj-P1954)"
    Cho một cây có trọng số trên cạnh. Tìm $(u, v)$ sao cho tổng xor các trọng số cạnh trên đường đi từ $u$ đến $v$ là lớn nhất, và in ra giá trị lớn nhất đó. Trong bài này, tổng xor là phép xor của tất cả trọng số cạnh trên đường đi.
    
    Số đỉnh không quá $10^5$, trọng số cạnh nằm trong $[0,2^{31})$.
    
    ??? note "Lời giải"
        Chọn tùy ý một gốc $root$. Gọi $T(u, v)$ là tổng xor các trọng số cạnh trên đường đi giữa $u$ và $v$. Khi đó $T(u,v)=T(root, u)\oplus T(root,v)$, vì phần nằm phía trên [LCA](../graph/lca.md) bị xor hai lần và triệt tiêu nhau.
        
        Nếu chèn tất cả $T(root, u)$ vào một trie, thì với mỗi $T(root, u)$ có thể nhanh chóng tìm $T(root, v)$ sao cho giá trị xor với nó là lớn nhất:
        
        Bắt đầu từ gốc của trie. Nếu có thể đi sang cây con có bit khác với bit hiện tại của $T(root, u)$ thì đi theo hướng đó; nếu không thì không có lựa chọn nào khác.
        
        Tính đúng đắn của tham lam: nếu đi như vậy, bit hiện tại sẽ bằng $1$; nếu không, bit hiện tại sẽ bằng $0$. Các bit cao cần được ưu tiên làm lớn nhất.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/string/code/trie/trie_2.cpp"
        ```

<span id="duy-trì-tổng-xor"></span>
### Duy trì tổng xor

01-trie là trie có bảng chữ cái $\{0,1\}$. 01-trie có thể dùng để duy trì tổng xor của một tập số, hỗ trợ sửa đổi (xóa + chèn lại) và cộng một toàn cục (tức là tăng tất cả các giá trị đang được duy trì lên `1`; về bản chất đây là một thao tác sửa đổi đặc biệt).

Nếu cần duy trì tổng xor, cần xây trie theo giá trị từ bit thấp đến bit cao.

**Quy ước**: trong phần này, hướng **lên trên** từ đỉnh hiện tại là đường đi từ đỉnh hiện tại đến gốc; hướng **xuống dưới** là cây con của đỉnh hiện tại.

<span id="chèn--xóa"></span>
#### Chèn & xóa

Để duy trì tổng xor, **chỉ cần** biết **tính chẵn lẻ** của số lượng `0` và `1` trên từng bit. Nói cách khác, đối với bit `1`, bit kết quả chỉ bằng `1` khi và chỉ khi số lượng bit `1` tại vị trí đó là lẻ. Vì vậy, nếu chỉ duy trì tổng xor, chỉ cần biết số lượng `1` trên từng bit, không cần biết trie đang duy trì chính xác những số nào.

Với mỗi đỉnh, cần ghi lại ba giá trị sau:

-   `ch[o][0/1]` chỉ hai con của đỉnh `o`; `ch[o][0]` chỉ đỉnh ứng với bit tiếp theo là `0`, và tương tự `ch[o][1]` chỉ bit tiếp theo là `1`.
-   `w[o]` chỉ số lượng giá trị (trọng số) trên cạnh từ đỉnh `o` đến cha của nó. Mỗi khi chèn một số `x`, sau khi tách `x` thành nhị phân, trọng số trên đường đi tương ứng trong trie đều tăng `+1`.
-   `xorv[o]` chỉ tổng xor được duy trì trong cây con gốc `o`.

Mã duy trì cụ thể cho một đỉnh như sau.

```cpp
void maintain(int o) {
  w[o] = xorv[o] = 0;
  if (ch[o][0]) {
    w[o] += w[ch[o][0]];
    xorv[o] ^= xorv[ch[o][0]] << 1;
  }
  if (ch[o][1]) {
    w[o] += w[ch[o][1]];
    xorv[o] ^= (xorv[ch[o][1]] << 1) | (w[ch[o][1]] & 1);
  }
  // w[o] = w[o] & 1;
  // Chỉ cần biết tính chẵn lẻ, không cần giá trị cụ thể. Dòng này có thể bỏ vì phía trên chỉ dùng tính chẵn lẻ của nó.
}
```

Mã chèn và xóa rất giống nhau.

Những điểm cần lưu ý:

-   `MAXH` là độ sâu của trie, tức là bắt buộc khoảng cách từ mọi lá đến gốc đều bằng `MAXH`. Với một số giá trị nhỏ, đôi khi không cần xây sâu đến vậy (ví dụ: nếu chèn số `4`, tách thành nhị phân là `100`, thì từ gốc chỉ cần chèn ba bit `001`), nhưng vẫn bắt buộc chèn `MAXH` bit. Mục đích là để xử lý nhớ bit khi cộng `+1` toàn cục. Ví dụ: số ban đầu là `3` (`11`), sau khi tăng thành `4` (`100`); nếu lúc chèn `3` chỉ chèn `2` bit thì phần nhớ này sẽ bị mất.

-   Khi chèn và xóa, chỉ cần sửa `w[]` tại đỉnh lá, rồi duy trì lại trên đường quay lui.

???+ note "Cài đặt"
    ```cpp
    namespace trie {
    constexpr int MAXH = 21;
    int ch[_ * (MAXH + 1)][2], w[_ * (MAXH + 1)], xorv[_ * (MAXH + 1)];
    int tot = 0;
    
    int mknode() {
      ++tot;
      ch[tot][1] = ch[tot][0] = w[tot] = xorv[tot] = 0;
      return tot;
    }
    
    void maintain(int o) {
      w[o] = xorv[o] = 0;
      if (ch[o][0]) {
        w[o] += w[ch[o][0]];
        xorv[o] ^= xorv[ch[o][0]] << 1;
      }
      if (ch[o][1]) {
        w[o] += w[ch[o][1]];
        xorv[o] ^= (xorv[ch[o][1]] << 1) | (w[ch[o][1]] & 1);
      }
      w[o] = w[o] & 1;
    }
    
    void insert(int &o, int x, int dp) {
      if (!o) o = mknode();
      if (dp > MAXH) return (void)(w[o]++);
      insert(ch[o][x & 1], x >> 1, dp + 1);
      maintain(o);
    }
    
    void erase(int o, int x, int dp) {
      if (dp > 20) return (void)(w[o]--);
      erase(ch[o][x & 1], x >> 1, dp + 1);
      maintain(o);
    }
    }  // namespace trie
    ```

<span id="cộng-một-toàn-cục"></span>
#### Cộng một toàn cục

Cộng một toàn cục nghĩa là tăng tất cả các giá trị trong trie lên `+1`.

Nói một cách hình thức, giả sử các giá trị đang được duy trì trong trie là $V_1, V_2, V_3 \dots V_n$, sau khi cộng một toàn cục, các giá trị được duy trì sẽ trở thành $V_1+1, V_2+1, V_3+1 \dots V_n+1$.

```cpp
void addall(int o) {
  swap(ch[o][0], ch[o][1]);
  if (ch[o][0]) addall(ch[o][0]);
  maintain(o);
}
```

<span id="quá-trình"></span>
##### Quá trình

Xem trong hệ nhị phân thao tác `+1` diễn ra như thế nào.

Chỉ cần tìm bit `0` đầu tiên từ bit thấp lên bit cao, đổi nó thành `1`, rồi đổi tất cả các bit `1` phía sau vị trí đó thành `0`.

Dưới đây là vài ví dụ để hình dung: (số trong ngoặc là giá trị thập phân tương ứng)

    1000(8)  + 1 = 1001(9)  ;
    10011(19) + 1 = 10100(20) ;
    11111(31) + 1 = 100000(32);
    10101(21) + 1 = 10110(22) ;
    100000000111111(16447) + 1 = 100000001000000(16448);

Tương ứng với thao tác trên trie, thực chất chỉ là hoán đổi hai con trái/phải, rồi đệ quy xuống theo cạnh `0` **sau khi đã hoán đổi**.

Nhắc lại định nghĩa của `w[o]`: `w[o]` chỉ số lượng giá trị (trọng số) trên cạnh từ đỉnh `o` đến cha của nó.

Định nghĩa này hơi lạ. Nếu lưu trọng số của hai cạnh đến các con tại đỉnh cha thì có vẻ quen thuộc hơn. Tuy nhiên trong trường hợp này, khi hoán đổi hai con, việc lưu khoảng cách đến cha tại đỉnh con tiện hơn.

<span id="hợp-nhất-01-trie"></span>
### Hợp nhất 01-trie

Đây là thao tác hợp nhất hai 01-trie nói trên, đồng thời hợp nhất các thông tin được duy trì.

Có lẽ không có nhiều bài viết về hợp nhất trie. Ý tưởng hợp nhất trie rất giống hợp nhất cây phân đoạn; có thể tìm "hợp nhất cây phân đoạn" để học cách hợp nhất trie.

Hợp nhất trie khá đơn giản. Xét một hàm `int merge(int a, int b)`: hàm này nhận vào chỉ số hai đỉnh nằm cùng một vị trí tương đối trong hai trie, và trả về chỉ số đỉnh sau khi hợp nhất xong.

<span id="quá-trình_1"></span>
#### Quá trình

Xét cách cài đặt.

Có ba trường hợp:

-   Nếu `a` không có đỉnh ở vị trí này, đỉnh mới sau khi hợp nhất chính là `b`.
-   Nếu `b` không có đỉnh ở vị trí này, đỉnh mới sau khi hợp nhất chính là `a`.
-   Nếu cả `a` và `b` đều tồn tại, hợp nhất thông tin của `b` vào `a`; đỉnh mới sau khi hợp nhất là `a`, sau đó đệ quy xử lý hai con của `a`.

    **Gợi ý**: nếu cần hợp nhất `a` và `b` vào một cây mới, có thể tạo đỉnh mới rồi hợp nhất vào đỉnh mới đó. Phần mã này chỉ hợp nhất thông tin của `b` vào `a`.

<span id="cài-đặt_1"></span>
#### Cài đặt

```cpp
int merge(int a, int b) {
  if (!a) return b;  // Nếu a không có đỉnh ở vị trí này, trả về b
  if (!b) return a;  // Nếu b không có đỉnh ở vị trí này, trả về a
  /*
    Nếu cả `a` và `b` đều tồn tại,
    hợp nhất thông tin của `b` vào `a`.
  */
  w[a] = w[a] + w[b];
  xorv[a] ^= xorv[b];
  /* Không dùng maintain(),
    vì maintain() hợp nhất thông tin của hai con của a,
    còn trong hàm này cần hợp nhất thông tin của hai đỉnh a và b.
   */
  ch[a][0] = merge(ch[a][0], ch[b][0]);
  ch[a][1] = merge(ch[a][1], ch[b][1]);
  return a;
}
```

Trie nào cũng có thể hợp nhất. Nói cách khác, thao tác hợp nhất trie không chỉ giới hạn ở 01-trie.

???+ note "[luogu-P6018 Ynoi2010 Fusion tree](https://www.luogu.com.cn/problem/P6018)"
    Cho một cây $n$ đỉnh, mỗi đỉnh có trọng số. Có $m$ thao tác.
    Cần hỗ trợ các thao tác sau.
    
    -   Tăng trọng số của các đỉnh có khoảng cách bằng $1$ đến một đỉnh $x$ trên cây lên $+1$. Khoảng cách giữa hai đỉnh trên cây được định nghĩa là số cạnh trên đường đi ngắn nhất từ một đỉnh đến đỉnh kia.
    
    -   Giảm trọng số trên một đỉnh $x$ đi $v$.
    
    -   Hỏi tổng xor trọng số của tất cả các đỉnh có khoảng cách bằng $1$ đến một đỉnh $x$ trên cây.
        Với $100\%$ dữ liệu, $1\le n \le 5\times 10^5$, $1\le m \le 5\times 10^5$, $0\le a_i \le 10^5$, $1 \le x \le n$, $opt\in\{1,2,3\}$.
        Bảo đảm tại mọi thời điểm, trọng số của mọi đỉnh đều không âm.
    
    ??? note "Lời giải"
        Với mỗi đỉnh, xây một trie để duy trì trọng số của các con của nó; trie cần hỗ trợ cộng một toàn cục.
        Có thể đặt đánh dấu lười trên mỗi đỉnh để ghi lại lượng tăng của trọng số các con.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/string/code/trie/trie_3.cpp"
        ```

???+ note "[luogu-P6623 Tree](https://www.luogu.com.cn/problem/P6623)"
    Cho một cây có gốc $T$ gồm $n$ đỉnh, các đỉnh được đánh số từ $1$, gốc là đỉnh $1$, mỗi đỉnh có một trọng số nguyên dương $v_i$.
    Gọi các đỉnh trong cây con của đỉnh $x$ (bao gồm chính $x$) là $c_1,c_2,\dots,c_k$, định nghĩa giá trị của $x$ là:
    $val(x)=(v_{c_1}+d(c_1,x)) \oplus (v_{c_2}+d(c_2,x)) \oplus \cdots \oplus (v_{c_k}+d(c_k, x))$ trong đó $d(x,y)$
    biểu diễn số cạnh trên đường đi đơn giản duy nhất giữa đỉnh $x$ và đỉnh $y$ trên cây, $d(x,x) = 0$. $\oplus$ biểu diễn phép xor.
    Tính giá trị của $\sum\limits_{i=1}^n val(i)$.
    
    ??? note "Lời giải"
        Xét đóng góp của mỗi đỉnh lên tất cả các tổ tiên của nó.
        Với mỗi đỉnh, xây một trie; ban đầu chỉ lưu trọng số của đỉnh này, sau đó hợp nhất trie trên các con theo thứ tự từ dưới lên trên, tiếp theo cộng một toàn cục, cuối cùng thống kê đáp án.
    
    ??? note "Mã tham khảo"
        ```cpp
        constexpr int _ = 526010;
        int n;
        int V[_];
        int debug = 0;
        
        namespace trie {
        constexpr int MAXH = 21;
        int ch[_ * (MAXH + 1)][2], w[_ * (MAXH + 1)], xorv[_ * (MAXH + 1)];
        int tot = 0;
        
        int mknode() {
          ++tot;
          ch[tot][1] = ch[tot][0] = w[tot] = xorv[tot] = 0;
          return tot;
        }
        
        void maintain(int o) {
          w[o] = xorv[o] = 0;
          if (ch[o][0]) {
            w[o] += w[ch[o][0]];
            xorv[o] ^= xorv[ch[o][0]] << 1;
          }
          if (ch[o][1]) {
            w[o] += w[ch[o][1]];
            xorv[o] ^= (xorv[ch[o][1]] << 1) | (w[ch[o][1]] & 1);
          }
          w[o] = w[o] & 1;
        }
        
        void insert(int &o, int x, int dp) {
          if (!o) o = mknode();
          if (dp > MAXH) return (void)(w[o]++);
          insert(ch[o][x & 1], x >> 1, dp + 1);
          maintain(o);
        }
        
        int merge(int a, int b) {
          if (!a) return b;
          if (!b) return a;
          w[a] = w[a] + w[b];
          xorv[a] ^= xorv[b];
          ch[a][0] = merge(ch[a][0], ch[b][0]);
          ch[a][1] = merge(ch[a][1], ch[b][1]);
          return a;
        }
        
        void addall(int o) {
          swap(ch[o][0], ch[o][1]);
          if (ch[o][0]) addall(ch[o][0]);
          maintain(o);
        }
        }  // namespace trie
        
        int rt[_];
        long long Ans = 0;
        vector<int> E[_];
        
        void dfs0(int o) {
          for (int i = 0; i < E[o].size(); i++) {
            int node = E[o][i];
            dfs0(node);
            rt[o] = trie::merge(rt[o], rt[node]);
          }
          trie::addall(rt[o]);
          trie::insert(rt[o], V[o], 0);
          Ans += trie::xorv[rt[o]];
        }
        
        int main() {
          n = read();
          for (int i = 1; i <= n; i++) V[i] = read();
          for (int i = 2; i <= n; i++) E[read()].push_back(i);
          dfs0(1);
          printf("%lld", Ans);
          return 0;
        }
        ```

<span id="trie-bền-vững"></span>
### Trie bền vững

Xem thêm [trie bền vững](../ds/persistent-trie.md).
