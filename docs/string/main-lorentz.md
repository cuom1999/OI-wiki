<span id="&#37325;&#20018;"></span>
## Xâu lặp kép

<span id="&#23450;&#20041;"></span>
### Định nghĩa

Cho một xâu $s$ có độ dài $n$.

Ta gọi xâu mới thu được bằng cách viết liên tiếp hai lần cùng một xâu là **xâu lặp kép (tandem repetition)**. Để diễn đạt chính xác, phần dưới gọi xâu được lặp lại là xâu gốc. Nói cách khác, một xâu lặp kép tương đương với một cặp chỉ số $(i, j)$ sao cho $s[i \dots j]$ được tạo bằng cách nối hai xâu giống nhau.

Mục tiêu là tìm tất cả xâu lặp kép trong xâu $s$ đã cho. Hoặc, giải một bài toán đơn giản hơn: tìm một xâu lặp kép bất kỳ hoặc xâu lặp kép dài nhất trong $s$.

Thuật toán dưới đây do Michael Main và Richard J. Lorentz đề xuất năm 1982.

???+ note "Quy ước"
    Mọi chỉ số xâu trong phần dưới bắt đầu từ $0$.
    
    Ký hiệu $\overline{s}$ là xâu đảo ngược của $s$. Ví dụ $\overline{\tt abc} = \tt cba$.

<span id="&#35299;&#37322;"></span>
### Giải thích

Xét xâu $\tt acababaee$. Xâu này có ba xâu lặp kép:

-   $s[2 \dots 5] = \tt abab$
-   $s[3 \dots 6] = \tt baba$
-   $s[7 \dots 8] = \tt ee$

Một ví dụ khác là xâu $\tt abaaba$, chỉ có hai xâu lặp kép:

-   $s[0 \dots 5] = \tt abaaba$
-   $s[2 \dots 3] = \tt aa$

<span id="&#37325;&#20018;&#30340;&#20010;&#25968;"></span>
### Số lượng xâu lặp kép

Một xâu độ dài $n$ có thể có tới $O(n^2)$ xâu lặp kép; ví dụ hiển nhiên là xâu gồm $n$ ký tự giống nhau, khi đó mọi xâu con có độ dài chẵn đều là xâu lặp kép. Nói chung, một xâu tuần hoàn với chu kỳ nhỏ thường có rất nhiều xâu lặp kép.

Điều này không ngăn ta tính số lượng xâu lặp kép trong thời gian $O(n \log n)$, vì thuật toán biểu diễn một xâu lặp kép dưới dạng nén nào đó, cho phép nén nhiều xâu lặp kép thành một biểu diễn.

Một vài kết luận thú vị về số lượng xâu lặp kép:

-   Nếu xâu gốc của một xâu lặp kép không phải là xâu lặp kép, ta gọi xâu lặp kép đó là **xâu lặp kép nguyên thủy (primitive repetition)**. Có thể chứng minh số xâu lặp kép nguyên thủy nhiều nhất là $O(n \log n)$.
-   Nếu nén một xâu lặp kép bằng bộ ba Crochemore $(i, p, r)$, trong đó $i$ là vị trí bắt đầu của xâu lặp kép, $p$ là độ dài của một chu kỳ nào đó của xâu lặp kép (chú ý không phải độ dài xâu gốc), và $r$ là số lần chu kỳ đó lặp lại, thì mọi xâu lặp kép của một xâu có thể được biểu diễn bằng $O(n \log n)$ bộ ba Crochemore.
-   Xâu Fibonacci được định nghĩa như sau:

$$
\begin{align} t_0 &= a, \\ t_1 &= b, \\ t_i &= t_{i-1} + t_{i-2}, \end{align}
$$

Có thể thấy xâu Fibonacci có tính chu kỳ rất cao. Với xâu Fibonacci $t_i$ có độ dài $f_i$, ngay cả khi nén bằng bộ ba Crochemore, vẫn có $O(f_i \log f_i)$ bộ ba. Số xâu lặp kép nguyên thủy của nó cũng là $O(f_i \log f_i)$.

<span id="Main-Lorentz-&#31639;&#27861;"></span>
## Thuật toán Main-Lorentz

<span id="&#35299;&#37322;"></span>
### Giải thích

Ý tưởng cốt lõi của thuật toán Main-Lorentz là **chia để trị**.

Thuật toán chia xâu thành hai phần trái và phải; trước hết tính số xâu lặp kép nằm hoàn toàn trong phần trái (hoặc phần phải), sau đó tính số xâu lặp kép có vị trí bắt đầu ở phần trái và kết thúc ở phần phải. Phần dưới gọi loại xâu lặp kép này là **xâu lặp kép cắt ngang**.

Tính số lượng xâu lặp kép cắt ngang là điểm then chốt của thuật toán Main-Lorentz, và sẽ được thảo luận chi tiết dưới đây.

<span id="&#36807;&#31243;"></span>
### Quy trình

<span id="&#23547;&#25214;&#20132;&#21449;&#37325;&#20018;"></span>
#### Tìm xâu lặp kép cắt ngang

Gọi phần trái của một xâu là $u$, phần phải là $v$. Khi đó $s = u + v$, và độ dài của $u, v$ xấp xỉ một nửa độ dài của $s$.

Với một xâu lặp kép bất kỳ, xét ký tự giữa của nó. Ở đây gọi ký tự đầu tiên của nửa phải xâu lặp kép là ký tự giữa; nói cách khác, nếu $s[i...j]$ là xâu lặp kép, thì ký tự giữa của nó là $s[(i + j + 1)/2]$. Nếu ký tự giữa của một xâu lặp kép nằm trong $u$, gọi xâu lặp kép đó là **lệch trái (left)**; ngược lại gọi là **lệch phải (right)**.

Tiếp theo sẽ xem cách tìm tất cả xâu lặp kép lệch trái.

Gọi độ dài của một xâu lặp kép lệch trái là $2l$. Xét ký tự đầu tiên của xâu lặp kép này rơi vào $v$ (tức $s[|u|]$); ký tự đó nhất định bằng một ký tự $u[\textit{cntr}]$ nào đó trong $u$.

Ta cố định $\textit{cntr}$ và tìm mọi xâu lặp kép thỏa điều kiện. Ví dụ, với xâu $\tt c \; \underset{\textit{cntr}}{a} \; c \; | \; a \; d \; a$ (dấu $\tt |$ dùng để phân tách trái/phải), nếu cố định $cntr = 1$, ta thấy xâu lặp kép $\tt caca$ thỏa điều kiện.

Rõ ràng, một khi cố định $\textit{cntr}$, ta cũng cố định giá trị của $l$. Nếu biết cách tìm mọi xâu lặp kép, ta có thể duyệt $\textit{cntr}$ từ $0$ đến $|u|-1$ và tìm tất cả xâu lặp kép thỏa điều kiện.

<span id="&#24038;&#20559;&#37325;&#20018;&#30340;&#21028;&#23450;"></span>
#### Kiểm tra xâu lặp kép lệch trái

Ngay cả sau khi cố định $\textit{cntr}$, vẫn có thể có nhiều xâu lặp kép thỏa điều kiện. Làm thế nào để tìm tất cả chúng?

Xét ví dụ xâu lặp kép $\overbrace{\tt a}^{l_1} \overbrace{\underset{\textit{cntr}}{\tt b} \tt c}^{l_2} \overbrace{\tt a}^{l_1}  \; | \; \overbrace{\tt b \; \tt c}^{l_2}$ trong xâu $\tt abcabcac$. Gọi $l_1$ là độ dài xâu con từ ký tự đầu của xâu lặp kép đến $s[\textit{cntr} - 1]$, và $l_2$ là độ dài xâu con từ $s[\textit{cntr}]$ đến ký tự cuối của xâu gốc bên trái trong xâu lặp kép.

Khi đó có thể đưa ra **điều kiện cần và đủ** để một xâu con độ dài $2l = 2(l_1 + l_2) = 2(|u| - \textit{cntr})$ là xâu lặp kép:

Gọi $k_1$ là số nguyên lớn nhất thỏa $u[\textit{cntr} - k_1 \dots \textit{cntr} - 1] = u[|u| - k_1 \dots |u| - 1]$, và $k_2$ là số nguyên lớn nhất thỏa $u[\textit{cntr} \dots \textit{cntr} + k_2 - 1] = v[0 \dots k_2 - 1]$. Khi đó với mọi cặp $(l_1, l_2)$ thỏa $l_1 \leq k_1$, $l_2 \leq k_2$, ta tìm được đúng một xâu lặp kép tương ứng.

Tóm lại:

-   Cố định một $\textit{cntr}$.
-   Khi đó mọi xâu lặp kép cần tìm đều có độ dài $2l = 2(|u| - \textit{cntr})$. Vẫn có thể có nhiều xâu lặp kép thỏa điều kiện, phụ thuộc vào giá trị của $l_1$ và $l_2$.
-   Tính $k_1$, $k_2$ như đã nêu ở trên.
-   Mọi xâu lặp kép thỏa điều kiện phải thỏa:

$$
\begin{align} l_1 + l_2 &= l = |u| - \textit{cntr} \\ l_1 &\le k_1, \\ l_2 &\le k_2. \\ \end{align}
$$

Tiếp theo chỉ còn cần xét cách tính nhanh $k_1$ và $k_2$. Nhờ [hàm Z](./z-func.md), ta có thể tính chúng trong $O(1)$:

-   Tính $k_1$: chỉ cần tính hàm Z của $\overline{u}$.
-   Tính $k_2$: chỉ cần tính hàm Z của $v + \# + u$, trong đó $\#$ là một ký tự không xuất hiện trong $u$ hoặc $v$.

<span id="&#21491;&#20559;&#37325;&#20018;"></span>
#### Xâu lặp kép lệch phải

Cách tính xâu lặp kép lệch phải gần như giống với cách tính xâu lặp kép lệch trái. Xét ký tự đầu tiên của xâu lặp kép rơi vào $u$ (tức $s[|u| - 1]$); ký tự đó nhất định bằng một ký tự nào đó trong $v$, gọi vị trí của ký tự này trong $v$ là $\textit{cntr}$.

Gọi $k_1$ là số nguyên lớn nhất thỏa $v[\textit{cntr} - k_1 + 1 \dots \textit{cntr}] = u[|u| - k_1 \dots |u| - 1]$, và $k_2$ là số nguyên lớn nhất thỏa $v[\textit{cntr} + 1 \dots \textit{cntr} + k_2] = v[0 \dots k_2 - 1]$. Khi đó có thể tính $k_1$ và $k_2$ lần lượt bằng hàm Z của $\overline{u} + \# + \overline{v}$ và của $v$.

Duyệt $\textit{cntr}$ và dùng phương pháp tương tự để tìm các xâu lặp kép lệch phải.

<span id="&#23454;&#29616;"></span>
### Cài đặt

Thuật toán Main-Lorentz đưa ra tất cả xâu lặp kép dưới dạng bộ bốn $(\textit{cntr}, l, k_1, k_2)$. Nếu chỉ cần tính số lượng xâu lặp kép, hoặc chỉ cần tìm xâu lặp kép dài nhất, thông tin trong bộ bốn này là đủ. Theo [định lý chính](../basic/complexity.md#%E4%B8%BB%E5%AE%9A%E7%90%86-master-theorem), độ phức tạp thời gian của thuật toán Main-Lorentz là $O(n \log n)$.

Chú ý rằng nếu muốn dùng các bộ bốn này để tìm mọi vị trí bắt đầu và kết thúc của xâu lặp kép, độ phức tạp thời gian trong trường hợp xấu nhất sẽ đạt $O(n^2)$. Chương trình dưới đây thực hiện điều đó, lưu mọi vị trí bắt đầu và kết thúc của xâu lặp kép vào `repetitions`.

```cpp
vector<int> z_function(string const& s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

int get_z(vector<int> const& z, int i) {
  if (0 <= i && i < (int)z.size())
    return z[i];
  else
    return 0;
}

vector<pair<int, int>> repetitions;

void convert_to_repetitions(int shift, bool left, int cntr, int l, int k1,
                            int k2) {
  for (int l1 = max(1, l - k2); l1 <= min(l, k1); l1++) {
    if (left && l1 == l) break;
    int l2 = l - l1;
    int pos = shift + (left ? cntr - l1 : cntr - l - l1 + 1);
    repetitions.emplace_back(pos, pos + 2 * l - 1);
  }
}

void find_repetitions(string s, int shift = 0) {
  int n = s.size();
  if (n == 1) return;

  int nu = n / 2;
  int nv = n - nu;
  string u = s.substr(0, nu);
  string v = s.substr(nu);
  string ru(u.rbegin(), u.rend());
  string rv(v.rbegin(), v.rend());

  find_repetitions(u, shift);
  find_repetitions(v, shift + nu);

  vector<int> z1 = z_function(ru);
  vector<int> z2 = z_function(v + '#' + u);
  vector<int> z3 = z_function(ru + '#' + rv);
  vector<int> z4 = z_function(v);

  for (int cntr = 0; cntr < n; cntr++) {
    int l, k1, k2;
    if (cntr < nu) {
      l = nu - cntr;
      k1 = get_z(z1, nu - cntr);
      k2 = get_z(z2, nv + 1 + cntr);
    } else {
      l = cntr - nu + 1;
      k1 = get_z(z3, nu + 1 + nv - 1 - (cntr - nu));
      k2 = get_z(z4, (cntr - nu) + 1);
    }
    if (k1 + k2 >= l) convert_to_repetitions(shift, cntr < nu, cntr, l, k1, k2);
  }
}
```

**Trang này chủ yếu được dịch từ bài viết [Поиск всех тандемных повторов в строке. Алгоритм Мейна-Лоренца](http://e-maxx.ru/algo/string_tandems) và bản dịch tiếng Anh [Finding repetitions](https://cp-algorithms.com/string/main_lorentz.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.**
