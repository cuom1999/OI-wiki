---
author: Ir1d, LeoJacob, Xeonacid, greyqz, StudyingFather, Marcythm, minghu6, Backl1ght
---

<span id="định-nghĩa-tiền-tố-và-hậu-tố-của-chuỗi"></span>
## Định nghĩa tiền tố và hậu tố của chuỗi

Về định nghĩa tiền tố, tiền tố thực sự, hậu tố và hậu tố thực sự của chuỗi, xem chi tiết tại [Cơ sở về chuỗi](./basic.md).

<span id="hàm-tiền-tố"></span>
## Hàm tiền tố

<span id="định-nghĩa"></span>
### Định nghĩa

Cho một chuỗi $s$ có độ dài $n$, **hàm tiền tố** của nó được định nghĩa là một mảng $\pi$ có độ dài $n$.
Trong đó $\pi[i]$ được định nghĩa như sau:

1.  Nếu xâu con $s[0\dots i]$ có một cặp tiền tố thực sự và hậu tố thực sự bằng nhau: $s[0\dots k-1]$ và $s[i - (k - 1) \dots i]$, thì $\pi[i]$ là độ dài của tiền tố thực sự bằng nhau đó (hoặc hậu tố thực sự, vì chúng bằng nhau), tức là $\pi[i]=k$;
2.  Nếu có nhiều hơn một cặp như vậy, thì $\pi[i]$ là độ dài của cặp dài nhất trong số đó;
3.  Nếu không có cặp nào bằng nhau, thì $\pi[i]=0$.

Nói ngắn gọn, $\pi[i]$ là độ dài của tiền tố thực sự dài nhất đồng thời là hậu tố thực sự của xâu con $s[0\dots i]$.

Biểu diễn bằng ngôn ngữ toán học như sau:

$$
\pi[i] = \max_{k = 0 \dots i}\{k: s[0 \dots k - 1] = s[i - (k - 1) \dots i]\}
$$

Đặc biệt, quy ước $\pi[0]=0$.

<span id="quá-trình"></span>
### Quá trình

Ví dụ, với chuỗi `abcabcd`,

$\pi[0]=0$, vì `a` không có tiền tố thực sự và hậu tố thực sự, nên theo quy ước là 0.

$\pi[1]=0$, vì `ab` không có tiền tố thực sự và hậu tố thực sự bằng nhau.

$\pi[2]=0$, vì `abc` không có tiền tố thực sự và hậu tố thực sự bằng nhau.

$\pi[3]=1$, vì `abca` chỉ có một cặp tiền tố thực sự và hậu tố thực sự bằng nhau: `a`, độ dài là 1.

$\pi[4]=2$, vì tiền tố thực sự và hậu tố thực sự bằng nhau của `abcab` chỉ là `ab`, độ dài là 2.

$\pi[5]=3$, vì tiền tố thực sự và hậu tố thực sự bằng nhau của `abcabc` chỉ là `abc`, độ dài là 3.

$\pi[6]=0$, vì `abcabcd` không có tiền tố thực sự và hậu tố thực sự bằng nhau.

Tương tự, có thể tính được hàm tiền tố của chuỗi `aabaaab` là $[0, 1, 0, 1, 2, 2, 3]$.

<span id="thuật-toán-ngây-thơ-để-tính-hàm-tiền-tố"></span>
## Thuật toán ngây thơ để tính hàm tiền tố

<span id="quá-trình_1"></span>
### Quá trình

Một thuật toán trực tiếp tính hàm tiền tố theo đúng định nghĩa có quy trình như sau:

-   Trong một vòng lặp, tính các giá trị của hàm tiền tố $\pi[i]$ theo thứ tự $i = 1\to n - 1$ ($\pi[0]$ được gán bằng $0$).
-   Để tính giá trị hàm tiền tố hiện tại $\pi[i]$, cho biến $j$ bắt đầu thử từ độ dài tiền tố thực sự lớn nhất là $i$.
-   Nếu với độ dài hiện tại, tiền tố thực sự và hậu tố thực sự bằng nhau, thì độ dài đó chính là $\pi[i]$; nếu không, giảm j đi 1 và tiếp tục so khớp cho đến khi $j=0$.
-   Nếu $j = 0$ mà vẫn không có lần so khớp nào thành công, đặt $\pi[i] = 0$ rồi chuyển sang chỉ số tiếp theo $i + 1$.

???+ note "Cài đặt"
    Cài đặt cụ thể như sau:
    
    === "C++"
        ```cpp
        // Lưu ý:
        // string substr (size_t pos = 0, size_t len = npos) const;
        vector<int> prefix_function(string s) {
          int n = (int)s.length();
          vector<int> pi(n);
          for (int i = 1; i < n; i++)
            for (int j = i; j >= 0; j--)
              if (s.substr(0, j) == s.substr(i - j + 1, j)) {
                pi[i] = j;
                break;
              }
          return pi;
        }
        ```
    
    === "Python"
        ```python
        def prefix_function(s):
            n = len(s)
            pi = [0] * n
            for i in range(1, n):
                for j in range(i, -1, -1):
                    if s[0:j] == s[i - j + 1 : i + 1]:
                        pi[i] = j
                        break
            return pi
        ```
    
    === "Java"
        ```java
        static int[] prefix_function(String s) {
            int n = s.length();
            int[] pi = new int[n];
            for (int i = 1; i < n; i++) {
                for (int j = i; j >= 0; j--) {
                    if (s.substring(0, j).equals(s.substring(i - j + 1, i + 1))) {
                        pi[i] = j;
                        break;
                    }
                }
            }
            return pi;
        }
        ```

Thuật toán này có độ phức tạp thời gian $O(n^3)$, nên còn rất nhiều không gian để cải tiến.

<span id="thuật-toán-hiệu-quả-để-tính-hàm-tiền-tố"></span>
## Thuật toán hiệu quả để tính hàm tiền tố

<span id="tối-ưu-thứ-nhất"></span>
### Tối ưu thứ nhất

Quan sát quan trọng đầu tiên là **hai giá trị hàm tiền tố kề nhau tăng nhiều nhất $1$**.

Tham khảo hình dưới đây, chỉ cần lập luận như sau: khi lấy một giá trị $\pi[i+1]$ lớn nhất có thể, ký tự mới thêm $s[i+1]$ bắt buộc cũng phải khớp với ký tự tương ứng, tức là $s[i+1]=s[\pi[i]]$; khi đó $\pi[i+1] = \pi[i]+1$.

$$
\underbrace{\overbrace{s_0 ~ s_1 ~ s_2}^{\pi[i] = 3} ~ s_3}_{\pi[i+1] = 4} ~ \dots ~ \underbrace{\overbrace{s_{i-2} ~ s_{i-1} ~ s_{i}}^{\pi[i] = 3} ~ s_{i+1}}_{\pi[i+1] = 4}
$$

Vì vậy khi chuyển sang vị trí tiếp theo, giá trị của hàm tiền tố hoặc tăng thêm một, hoặc giữ nguyên, hoặc giảm đi.

???+ note "Cài đặt"
    Thuật toán đã cải tiến ở thời điểm này là:
    
    === "C++"
        ```cpp
        vector<int> prefix_function(string s) {
          int n = (int)s.length();
          vector<int> pi(n);
          for (int i = 1; i < n; i++)
            for (int j = pi[i - 1] + 1; j >= 0; j--)  // improved: j=i => j=pi[i-1]+1
              if (s.substr(0, j) == s.substr(i - j + 1, j)) {
                pi[i] = j;
                break;
              }
          return pi;
        }
        ```
    
    === "Python"
        ```python
        def prefix_function(s):
            n = len(s)
            pi = [0] * n
            for i in range(1, n):
                for j in range(pi[i - 1] + 1, -1, -1):
                    if s[0:j] == s[i - j + 1 : i + 1]:
                        pi[i] = j
                        break
            return pi
        ```
    
    === "Java"
        ```java
        static int[] prefix_function(String s) {
            int n = s.length();
            int[] pi = new int[n];
            for (int i = 1; i < n; i++) {
                for (int j = pi[i - 1] + 1; j >= 0; j--) {
                    if (s.substring(0, j).equals(s.substring(i - j + 1, i + 1))) {
                        pi[i] = j;
                        break;
                    }
                }
            }
            return pi;
        }
        ```

Trong thuật toán cải tiến sơ bộ này, khi tính mỗi $\pi[i]$, trường hợp tốt nhất là lần so sánh chuỗi đầu tiên đã khớp; tức là số lần so sánh chuỗi cơ bản là $n-1$.

Do ràng buộc `j = pi[i-1]+1` (`pi[0]=0`) lên số lần so sánh chuỗi tối đa, chỉ trong trường hợp tốt nhất mỗi bước mới tích lũy thêm $1$ vào cận trên của số lần so sánh chuỗi, còn mỗi phép so sánh vượt quá một lần sẽ tiêu hao phần tăng trưởng của các bước về sau.

Từ đó có thể suy ra một tình huống đạt số lần so sánh chuỗi nhiều nhất: ít nhất $1$ lần so sánh bị tiêu hao và nhiều nhất $n-2$ lần so sánh được tích lũy; khi đó số lần so sánh chuỗi là $n-1 + n-2 = 2n-3$.

Như vậy sau tối ưu này, việc tính hàm tiền tố chỉ cần thực hiện $O(n)$ lần so sánh chuỗi, và tổng độ phức tạp giảm xuống $O(n^2)$.

<span id="tối-ưu-thứ-hai"></span>
### Tối ưu thứ hai

Trong tối ưu thứ nhất đã thảo luận trường hợp tốt nhất khi tính $\pi[i+1]$: $s[i+1]=s[\pi[i]]$, khi đó $\pi[i+1] = \pi[i]+1$. Tiếp tục xét cách nhảy khi $s[i+1] \neq s[\pi[i]]$.

![](images/prefix_str_1.svg)

Như hình trên, khi xảy ra không khớp, cần tìm độ dài lớn thứ hai $j$ sau $\pi[i]$ đối với xâu con $s[0\dots i]$, sao cho tính chất tiền tố tại vị trí $i$ vẫn được giữ, tức là $s[0 \dots j - 1] = s[i - j + 1 \dots i]$:

$$
\overbrace{\underbrace{s_0 ~ s_1}_j ~ s_2 ~ s_3}^{\pi[i]} ~ \dots ~ \overbrace{s_{i-3} ~ s_{i-2} ~ \underbrace{s_{i-1} ~ s_{i}}_j}^{\pi[i]} ~ s_{i+1}
$$

Nếu tìm được một độ dài $j$ như vậy, chỉ cần so sánh lại $s[i + 1]$ với $s[j]$. Nếu chúng bằng nhau, có $\pi[i + 1] = j + 1$. Nếu không, cần tìm độ dài lớn thứ hai $j^{(2)}$ sau $j$ của xâu con $s[0\dots i]$ sao cho tính chất tiền tố vẫn được giữ, rồi lặp lại như vậy cho đến khi $j = 0$. Nếu $s[i + 1] \neq s[0]$, thì $\pi[i + 1] = 0$. Sơ đồ cho lần so sánh thứ hai như sau:

![](images/prefix_str_2.svg)

Từ hình trên, do $s[0\dots \pi[i]-1] = s[i-\pi[i]+1\dots i]$, độ dài lớn thứ hai $j$ của $s[0\dots i]$ có tính chất:

$$
s[0 \dots j - 1] = s[i - j + 1 \dots i]= s[\pi[i]-j\dots \pi[i]-1]
$$

Sơ đồ của công thức này như sau:

![](images/prefix_str_3.svg)

Nói cách khác, $j$ tương đương với giá trị hàm tiền tố của xâu con $s[\pi[i]-1]$, ứng với phần dưới của hình trên, tức là $j=\pi[\pi[i]-1]$. Tương tự, độ dài lớn thứ hai sau $j$ tương đương với giá trị hàm tiền tố của $s[j-1]$, $j^{(2)}=\pi[j-1]$.

Có thể thu được phương trình chuyển trạng thái theo $j$: $j^{(n)}=\pi[j^{(n-1)}-1], \ \ (j^{(n-1)}>0)$.

<span id="thuật-toán-cuối-cùng"></span>
### Thuật toán cuối cùng

Vì vậy cuối cùng có thể xây dựng một thuật toán không cần thực hiện bất kỳ phép so sánh chuỗi nào và chỉ thực hiện $O(n)$ thao tác.

Hơn nữa, phần cài đặt của thuật toán này ngắn và trực quan một cách bất ngờ:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        vector<int> prefix_function(string s) {
          int n = (int)s.length();
          vector<int> pi(n);
          for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
          }
          return pi;
        }
        ```
    
    === "Python"
        ```python
        def prefix_function(s):
            n = len(s)
            pi = [0] * n
            for i in range(1, n):
                j = pi[i - 1]
                while j > 0 and s[i] != s[j]:
                    j = pi[j - 1]
                if s[i] == s[j]:
                    j += 1
                pi[i] = j
            return pi
        ```
    
    === "Java"
        ```java
        static int[] prefix_function(String s) {
            int n = s.length();
            int[] pi = new int[n];
            for (int i = 1; i < n; i++) {
                int j = pi[i - 1];
                while (j > 0 && s.charAt(i) != s.charAt(j)) {
                    j = pi[j - 1];
                }
                if (s.charAt(i) == s.charAt(j)) {
                    j++;
                }
                pi[i] = j;
            }
            return pi;
        }
        ```

Đây là một thuật toán **trực tuyến**, tức là nó xử lý dữ liệu khi dữ liệu đến. Chẳng hạn, có thể đọc chuỗi từng ký tự một và xử lý ngay để tính giá trị hàm tiền tố cho từng ký tự. Thuật toán vẫn cần lưu trữ chính chuỗi và các giá trị hàm tiền tố đã tính trước đó; nhưng nếu biết trước giá trị lớn nhất có thể của hàm tiền tố của chuỗi là $M$, thì chỉ cần lưu $M + 1$ ký tự đầu của chuỗi và các giá trị hàm tiền tố tương ứng.

<span id="ứng-dụng"></span>
## Ứng dụng

<span id="tìm-xâu-con-trong-chuỗi-thuật-toán-knuth-morris-pratt"></span>
### Tìm xâu con trong chuỗi: thuật toán Knuth-Morris-Pratt

Thuật toán này được Knuth, Pratt và Morris cùng công bố vào năm 1977[^kmp]. Đây là một ứng dụng điển hình của hàm tiền tố.

<span id="quá-trình_2"></span>
#### Quá trình

Cho một văn bản $t$ và một chuỗi $s$, cần tìm và hiển thị tất cả các lần xuất hiện (occurrence) của $s$ trong $t$.

Để đơn giản, dùng $n$ để chỉ độ dài của chuỗi $s$, và $m$ để chỉ độ dài của văn bản $t$.

Xây dựng chuỗi $s + \# + t$, trong đó $\#$ là một ký tự phân tách không xuất hiện trong $s$ cũng như trong $t$. Tiếp theo, tính hàm tiền tố của chuỗi này. Bây giờ xét ý nghĩa của các giá trị hàm tiền tố sau khi bỏ đi $n + 1$ giá trị đầu tiên (tức là các giá trị thuộc chuỗi $s$ và ký tự phân tách). Theo định nghĩa, $\pi[i]$ là độ dài xâu con thực sự dài nhất có đầu mút phải tại $i$ và đồng thời là một tiền tố; trong trường hợp cụ thể này, giá trị đó là độ dài xâu con dài nhất có đầu mút phải tại $i$ và trùng với một tiền tố của $s$. Do có ký tự phân tách, độ dài này không thể vượt quá $n$. Nếu đẳng thức $\pi[i] = n$ đúng, điều đó có nghĩa là $s$ xuất hiện trọn vẹn tại vị trí này (tức là đầu mút phải của nó nằm ở vị trí $i$). Lưu ý rằng chỉ số này được tính trên chuỗi $s + \# + t$.

Vì vậy nếu tại một vị trí $i$ có $\pi[i] = n$, thì chuỗi $s$ xuất hiện trong chuỗi $t$ tại vị trí $i - (n - 1) - (n + 1) = i - 2n$. Hình dưới đây minh họa cách đánh chỉ số.

![](./images/strstr_kmp_indices.svg)

Như đã đề cập khi tính hàm tiền tố, nếu biết giá trị hàm tiền tố không bao giờ vượt quá một giá trị nhất định, thì không cần lưu toàn bộ chuỗi và toàn bộ hàm tiền tố, mà chỉ cần lưu phần đầu của cả hai. Trong trường hợp này, điều đó có nghĩa là chỉ cần lưu chuỗi $s + \#$ cùng các giá trị hàm tiền tố tương ứng. Có thể đọc từng ký tự của chuỗi $t$ và tính giá trị hàm tiền tố tại vị trí hiện tại.

Do đó thuật toán Knuth-Morris-Pratt (viết tắt là KMP) giải bài toán này trong thời gian $O(n + m)$ và bộ nhớ $O(n)$.

???+ note "Cài đặt"
    === "C++"
        ```cpp
        vector<int> find_occurrences(string text, string pattern) {
          string cur = pattern + '#' + text;
          int sz1 = text.size(), sz2 = pattern.size();
          vector<int> v;
          vector<int> lps = prefix_function(cur);
          for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
            if (lps[i] == sz2) v.push_back(i - 2 * sz2);
          }
          return v;
        }
        ```
    
    === "Python"
        ```python
        def find_occurrences(t, s):
            cur = s + "#" + t
            sz1, sz2 = len(t), len(s)
            ret = []
            lps = prefix_function(cur)
            for i in range(sz2 + 1, sz1 + sz2 + 1):
                if lps[i] == sz2:
                    ret.append(i - 2 * sz2)
            return ret
        ```
    
    === "Java"
        ```java
        static List<Integer> find_occurrences(String text, String pattern) {
            String cur = pattern + '#' + text;
            int sz1 = text.length(), sz2 = pattern.length();
            List<Integer> v = new ArrayList<>();
            int[] lps = prefix_function(cur);
            for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
                if (lps[i] == sz2) {
                    v.add(i - 2 * sz2);
                }
            }
            return v;
        }
        ```

<span id="chu-kỳ-của-chuỗi"></span>
### Chu kỳ của chuỗi

Với chuỗi $s$ và $0 < p \le |s|$, nếu $s[i] = s[i+p]$ đúng với mọi $i \in [0, |s| - p - 1]$, thì gọi $p$ là một chu kỳ của $s$.

Với chuỗi $s$ và $0 \le r < |s|$, nếu tiền tố độ dài $r$ của $s$ bằng hậu tố độ dài $r$ của $s$, thì tiền tố độ dài $r$ đó được gọi là một border của $s$.

Từ việc $s$ có một border độ dài $r$, có thể suy ra $|s|-r$ là một chu kỳ của $s$.

Theo định nghĩa của hàm tiền tố, có thể nhận được mọi độ dài border của $s$, tức là $\pi[n-1],\pi[\pi[n-1]-1], \ldots$.[^ref1]

Vì vậy, dựa vào hàm tiền tố, có thể tính mọi chu kỳ của $s$ trong thời gian $O(n)$. Trong đó, vì $\pi[n-1]$ là độ dài border dài nhất của $s$, nên $n - \pi[n-1]$ là chu kỳ nhỏ nhất của $s$.

<span id="đếm-số-lần-xuất-hiện-của-mỗi-tiền-tố"></span>
### Đếm số lần xuất hiện của mỗi tiền tố

Phần này thảo luận đồng thời hai bài toán. Cho một chuỗi $s$ có độ dài $n$; ở biến thể thứ nhất, cần đếm số lần xuất hiện của mỗi tiền tố $s[0 \dots i]$ trong chính chuỗi đó; ở biến thể thứ hai, cần đếm số lần xuất hiện của mỗi tiền tố $s[0 \dots i]$ trong một chuỗi $t$ cho trước khác.

Trước hết giải bài toán thứ nhất. Xét giá trị hàm tiền tố $\pi[i]$ tại vị trí $i$. Theo định nghĩa, nó có nghĩa là một tiền tố độ dài $\pi[i]$ của chuỗi $s$ xuất hiện tại vị trí $i$ và có đầu mút phải là $i$, đồng thời không tồn tại tiền tố dài hơn nào thỏa mãn định nghĩa trên. Trong khi đó, các tiền tố ngắn hơn vẫn có thể có đầu mút phải tại vị trí này. Khi đó gặp lại câu hỏi đã được trả lời khi tính hàm tiền tố: cho một tiền tố độ dài $j$ đồng thời là hậu tố có đầu mút phải tại $i$, độ dài tiền tố nhỏ hơn tiếp theo $k < j$ là bao nhiêu? Tiền tố có độ dài đó cũng phải đồng thời là một hậu tố có đầu mút phải tại $i$. Vì vậy, với đầu mút phải tại vị trí $i$, có tiền tố độ dài $\pi[i]$, tiền tố độ dài $\pi[\pi[i] - 1]$, tiền tố độ dài $\pi[\pi[\pi[i] - 1] - 1]$, v.v. cho đến khi độ dài trở thành $0$. Do đó có thể tính đáp án theo cách sau.

???+ note "Cài đặt"
    === "C++"
        ```cpp
        vector<int> ans(n + 1);
        for (int i = 0; i < n; i++) ans[pi[i]]++;
        for (int i = n - 1; i > 0; i--) ans[pi[i - 1]] += ans[i];
        for (int i = 0; i <= n; i++) ans[i]++;
        ```
    
    === "Python"
        ```python
        ans = [0] * (n + 1)
        for i in range(0, n):
            ans[pi[i]] += 1
        for i in range(n - 1, 0, -1):
            ans[pi[i - 1]] += ans[i]
        for i in range(0, n + 1):
            ans[i] += 1
        ```

<span id="giải-thích"></span>
#### Giải thích

Trong đoạn mã trên, trước hết đếm mỗi giá trị hàm tiền tố xuất hiện bao nhiêu lần trong mảng $\pi$, rồi tính đáp án cuối cùng: nếu biết tiền tố độ dài $i$ xuất hiện đúng $\text{ans}[i]$ lần, thì giá trị này phải được cộng dồn vào số lần xuất hiện của xâu con dài nhất vừa là hậu tố vừa là tiền tố của nó. Cuối cùng, để tính cả chính các tiền tố ban đầu, cộng thêm $1$ vào mỗi kết quả.

Tiếp theo xét bài toán thứ hai. Áp dụng thủ thuật từ Knuth-Morris-Pratt: xây dựng chuỗi $s + \# + t$ và tính hàm tiền tố của nó. Điểm khác biệt duy nhất so với bài toán thứ nhất là chỉ quan tâm đến các giá trị hàm tiền tố liên quan đến chuỗi $t$, tức là các $\pi[i]$ với $i \ge n + 1$. Sau khi có các giá trị này, có thể áp dụng cùng thuật toán như trong bài toán thứ nhất để giải bài toán.

<span id="số-xâu-con-khác-nhau-trong-một-chuỗi"></span>
### Số xâu con khác nhau trong một chuỗi

Cho một chuỗi $s$ có độ dài $n$, cần tính số xâu con khác nhau của nó.

Bài toán này được giải theo cách lặp. Nói cách khác, khi đã biết số xâu con khác nhau hiện tại, cần tìm cách tính lại số đó sau khi thêm một ký tự vào cuối $s$.

Gọi $k$ là số xâu con khác nhau hiện tại của $s$. Thêm một ký tự mới $c$ vào $s$. Khi đó sẽ có một số xâu con mới kết thúc bằng ký tự $c$. Cần đếm các xâu con kết thúc bằng ký tự này mà trước đó chưa từng gặp.

Xây dựng chuỗi $t = s + c$ rồi đảo ngược nó để được chuỗi $t^{\sim}$. Khi đó nhiệm vụ trở thành tính xem có bao nhiêu tiền tố của $t^{\sim}$ không xuất hiện ở bất kỳ vị trí nào khác trong $t^{\sim}$. Nếu tính giá trị lớn nhất của hàm tiền tố của $t^{\sim}$ là $\pi_{\max}$, thì tiền tố dài nhất xuất hiện trong $s$ có độ dài $\pi_{\max}$. Mọi tiền tố ngắn hơn cũng đã xuất hiện.

Vì vậy, sau khi thêm một ký tự mới, số xâu con mới xuất hiện là $|s| + 1 - \pi_{\max}$.

Do đó với mỗi ký tự được thêm vào, có thể tính số xâu con mới trong thời gian $O(n)$, nên độ phức tạp cuối cùng là $O(n^2)$.

Ngoài ra, cũng có thể tính lại số xâu con khác nhau khi thêm một ký tự vào đầu, hoặc khi xóa một ký tự ở cuối hay ở đầu.

<span id="nén-chuỗi"></span>
### Nén chuỗi

Cho một chuỗi $s$ có độ dài $n$, cần tìm biểu diễn "nén" ngắn nhất của nó, tức là cần tìm một chuỗi $t$ ngắn nhất sao cho $s$ có thể biểu diễn bằng cách ghép một hoặc nhiều bản sao của $t$.

Chỉ cần tìm độ dài của $t$. Khi đã biết độ dài đó, đáp án của bài toán chính là tiền tố của $s$ có độ dài bằng giá trị này.

Tính hàm tiền tố của $s$. Dùng giá trị cuối cùng của hàm này $\pi[n - 1]$, định nghĩa $k = n - \pi[n - 1]$. Cần chứng minh rằng nếu $k$ là ước của $n$, thì $k$ chính là đáp án; nếu không, không tồn tại một cách nén hợp lệ, nên đáp án là $n$.

Giả sử $n$ chia hết cho $k$. Khi đó có thể chia chuỗi thành các khối độ dài $k$. Theo định nghĩa của hàm tiền tố, tiền tố độ dài $n - k$ của chuỗi bằng hậu tố của nó. Nhưng điều này có nghĩa là khối cuối cùng bằng khối áp chót, khối áp chót bằng khối ngay trước nó, và cứ tiếp tục như vậy. Kết quả là mọi khối đều bằng nhau, do đó có thể nén chuỗi $s$ xuống độ dài $k$.

???+ note "Chứng minh"
    Vẫn cần chứng minh giá trị này là tối ưu. Nếu tồn tại một biểu diễn nén ngắn hơn $k$, thì giá trị cuối cùng của hàm tiền tố $\pi[n - 1]$ phải lớn hơn $n - k$. Vì vậy $k$ chính là đáp án.
    
    Bây giờ giả sử $n$ không chia hết cho $k$, chứng minh bằng phản chứng rằng điều này có nghĩa đáp án là $n$[^1]. Giả sử biểu diễn nén nhỏ nhất của nó là $r$ có độ dài $p$ ($p$ là ước của $n$), và chuỗi $s$ được chia thành $n / p \ge 2$ khối. Khi đó giá trị cuối cùng của hàm tiền tố $\pi[n - 1]$ phải lớn hơn $n - p$ (nếu bằng thì $n$ sẽ chia hết cho $k$), tức là hậu tố mà nó biểu diễn sẽ phủ một phần lên khối đầu tiên. Tiếp theo xét khối thứ hai của chuỗi. Khối này có hai cách diễn giải: cách thứ nhất là $r_0 r_1 \dots r_{p - 1}$, cách thứ hai là $r_{p - k} r_{p - k + 1} \dots r_{p - 1} r_0 r_1 \dots r_{p - k - 1}$. Vì hai cách diễn giải tương ứng với cùng một chuỗi, thu được một hệ gồm $p$ phương trình, có thể viết gọn là $r_{(i + k) \bmod p} = r_{i \bmod p}$, trong đó $\cdot \bmod p$ biểu thị phần dư không âm nhỏ nhất theo môđun $p$.
    
    $$
    \begin{gathered}
    \overbrace{r_0 ~ r_1 ~ r_2 ~ r_3 ~ r_4 ~ r_5}^p ~ \overbrace{r_0 ~ r_1 ~ r_2 ~ r_3 ~ r_4 r_5}^p \\
    r_0 ~ r_1 ~ r_2 ~ r_3 ~ \underbrace{\overbrace{r_0 ~ r_1 ~ r_2 ~ r_3 ~ r_4 ~ r_5}^p ~ r_0 ~ r_1}_{\pi[11] = 8}
    \end{gathered}
    $$
    
    Theo thuật toán Euclid mở rộng, có thể tìm được một cặp $x$ và $y$ sao cho $xk + yp = \gcd(k, p)$. Bằng cách cộng thêm thích hợp đẳng thức $pk - kp = 0$, có thể thu được một cặp $x' > 0$ và $y' < 0$ sao cho $x'k + y'p = \gcd(k, p)$. Điều này có nghĩa là bằng cách liên tục áp dụng các phương trình trong hệ trên, có thể thu được hệ phương trình mới $r_{(i + \gcd(k, p)) \bmod p} = r_{i \bmod p}$.
    
    Vì $\gcd(k, p)$ là ước của $p$, điều này có nghĩa $\gcd(k, p)$ là một chu kỳ của $r$. Lại vì $\pi[n - 1] > n - p$, nên $n - \pi[n - 1] = k < p$; do đó $\gcd(k, p)$ là một chu kỳ của $r$ nhỏ hơn $p$. Vì thế chuỗi $s$ có một biểu diễn nén độ dài $\gcd(k, p) < p$, mâu thuẫn với tính nhỏ nhất của $p$.
    
    Tóm lại, không tồn tại biểu diễn nén nào có độ dài nhỏ hơn $k$, vì vậy đáp án là $k$.

[^1]: Phần chứng minh này trong bản tiếng Nga và bản tiếng Anh đều có vẻ có sai sót. Phần chứng minh trong bài viết này do tác giả tự bổ sung.

<span id="xây-dựng-một-ô-tô-mát-từ-hàm-tiền-tố"></span>
### Xây dựng một ô-tô-mát từ hàm tiền tố

Quay lại chuỗi mới được tạo bằng cách nối hai chuỗi qua một ký tự phân tách. Với các chuỗi $s$ và $t$, tính hàm tiền tố của $s + \# + t$. Vì $\#$ là một ký tự phân tách, giá trị hàm tiền tố không bao giờ vượt quá $|s|$. Do đó chỉ cần lưu chuỗi $s + \#$ và các giá trị hàm tiền tố tương ứng của nó; sau đó có thể tính động giá trị hàm tiền tố cho mọi ký tự tiếp theo:

$$
\underbrace{s_0 ~ s_1 ~ \dots ~ s_{n-1} ~ \#}_{\text{cần lưu}} ~ \underbrace{t_0 ~ t_1 ~ \dots ~ t_{m-1}}_{\text{không cần lưu}}
$$

Trong trường hợp này, chỉ cần biết ký tự tiếp theo $c$ của $t$ và giá trị hàm tiền tố ở vị trí trước đó là đủ để tính giá trị hàm tiền tố ở vị trí tiếp theo, không cần dùng đến bất kỳ ký tự nào khác của $t$ hay giá trị hàm tiền tố tương ứng của chúng.

Nói cách khác, có thể xây dựng một **ô-tô-mát** (một máy trạng thái hữu hạn): trạng thái của nó là giá trị hàm tiền tố hiện tại, còn chuyển tiếp từ trạng thái này sang trạng thái khác được xác định bởi ký tự tiếp theo.

Vì vậy, ngay cả khi không có chuỗi $t$, vẫn có thể áp dụng thuật toán xây dựng bảng chuyển tiếp để tạo một bảng chuyển tiếp $( \text { old } \pi , c ) \rightarrow \text { new } _ { - } \pi$:

???+ note "Cài đặt"
    ```cpp
    void compute_automaton(string s, vector<vector<int>>& aut) {
      s += '#';
      int n = s.size();
      vector<int> pi = prefix_function(s);
      aut.assign(n, vector<int>(26));
      for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
          int j = i;
          while (j > 0 && 'a' + c != s[j]) j = pi[j - 1];
          if ('a' + c == s[j]) j++;
          aut[i][c] = j;
        }
      }
    }
    ```

Tuy nhiên ở dạng này, với bảng chữ cái chữ thường, độ phức tạp thời gian của thuật toán là $O(|\Sigma|n^2)$. Có thể áp dụng quy hoạch động để tận dụng các phần đã tính trong bảng. Mỗi khi chuyển từ giá trị $j$ sang $\pi[j - 1]$, thực chất đang nói rằng chuyển tiếp $(j, c)$ đi đến cùng trạng thái với chuyển tiếp $(\pi[j - 1], c)$, mà đáp án này trước đó đã được tính chính xác.

???+ note "Cài đặt"
    ```cpp
    void compute_automaton(string s, vector<vector<int>>& aut) {
      s += '#';
      int n = s.size();
      vector<int> pi = prefix_function(s);
      aut.assign(n, vector<int>(26));
      for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
          if (i > 0 && 'a' + c != s[i])
            aut[i][c] = aut[pi[i - 1]][c];
          else
            aut[i][c] = i + ('a' + c == s[i]);
        }
      }
    }
    ```

Cuối cùng, có thể xây dựng ô-tô-mát này trong độ phức tạp thời gian $O(|\Sigma|n)$.

Ô-tô-mát này hữu ích khi nào? Trước hết, phần lớn thời gian hàm tiền tố của chuỗi $s + \# + t$ được dùng cho một mục đích: tìm mọi lần xuất hiện của chuỗi $s$ trong chuỗi $t$.

Vì vậy lợi ích trực tiếp nhất của việc dùng ô-tô-mát này là **tăng tốc việc tính hàm tiền tố của chuỗi $s + \# + t$**.

Bằng cách xây dựng ô-tô-mát của $s + \#$, không còn cần lưu chuỗi $s$ và các giá trị hàm tiền tố tương ứng của nó. Mọi chuyển tiếp đã được tính sẵn trong bảng.

Ngoài ra còn có một ứng dụng thứ hai ít trực tiếp hơn. Có thể dùng ô-tô-mát này để tăng tốc tính toán khi chuỗi $t$ là **một chuỗi khổng lồ được xây dựng theo một số quy tắc**. Chuỗi Gray, hoặc một chuỗi được tạo bằng cách tổ hợp đệ quy một số chuỗi đầu vào ngắn, là các ví dụ như vậy.

Để đầy đủ, xét bài toán sau: cho một số $k \le 10^5$ và một chuỗi $s$ có độ dài $\le 10^5$, cần tính số lần xuất hiện của $s$ trong chuỗi Gray thứ $k$. Nhắc lại rằng chuỗi Gray được định nghĩa như sau:

$$
\begin{aligned}
g_1 &= \mathtt{a}\\
g_2 &= \mathtt{aba}\\
g_3 &= \mathtt{abacaba}\\
g_4 &= \mathtt{abacabadabacaba}
\end{aligned}
$$

Do độ dài lớn đến mức thiên văn, trong trường hợp này ngay cả việc dựng chuỗi $t$ cũng là không thể: chuỗi Gray thứ $k$ có $2^k - 1$ ký tự. Tuy nhiên có thể tính hiệu quả giá trị hàm tiền tố ở cuối chuỗi này khi chỉ biết một số giá trị hàm tiền tố ban đầu.

Bên cạnh ô-tô-mát, còn cần tính giá trị $G[i][j]$: trạng thái của ô-tô-mát sau khi xử lý $g_i$ bắt đầu từ trạng thái $j$, và giá trị $K[i][j]$: số lần xuất hiện của $s$ trong $g_i$ khi xử lý $g_i$ bắt đầu từ trạng thái $j$. Thực chất, $K[i][j]$ là số lần trong quá trình thực hiện mà giá trị hàm tiền tố bằng $|s|$. Đáp án của bài toán là $K[k][0]$.

Các giá trị này được tính như thế nào? Trước hết, theo định nghĩa, điều kiện ban đầu là $G[0][j] = j$ và $K[0][j] = 0$. Sau đó có thể tính mọi giá trị từ các giá trị trước đó bằng ô-tô-mát. Để tính giá trị tương ứng cho một $i$ nào đó, nhớ rằng chuỗi $g_i$ được tạo bằng cách ghép $g_{i - 1}$, ký tự thứ $i$ trong bảng chữ cái, và $g_{i - 1}$. Vì vậy ô-tô-mát sẽ đi qua các trạng thái sau:

$$
\begin{gathered}
\text{mid} = \text{aut}[G[i - 1][j]][i] \\
G[i][j] = G[i - 1][\text{mid}]
\end{gathered}
$$

Cũng có thể tính giá trị $K[i][j]$ một cách đơn giản.

$$
K[i][j] = K[i - 1][j] + [\text{mid} == |s|] + K[i - 1][\text{mid}]
$$

Trong đó $[\cdot]$ có giá trị $1$ khi biểu thức bên trong là đúng, ngược lại có giá trị $0$. Tóm lại, đã có thể giải bài toán về chuỗi Gray, cũng như một lớp lớn các bài toán tương tự. Chẳng hạn, có thể áp dụng cùng phương pháp để giải bài toán sau: cho một chuỗi $s$ và một số mẫu $t_i$, trong đó mỗi mẫu được cho theo cách sau: mẫu gồm các ký tự thông thường, đồng thời có thể chèn đệ quy các chuỗi trước đó dưới dạng $t_{k}^{\text{cnt}}$, tức là tại vị trí đó phải chèn chuỗi $t_k$ đúng $\text{cnt}$ lần. Dưới đây là một ví dụ về các mẫu như vậy:

$$
\begin{aligned}
t_1 &= \mathtt{abdeca} \\
t_2 &= \mathtt{abc} + t_1^{30} + \mathtt{abd} \\
t_3 &= t_2^{50} + t_1^{100} \\
t_4 &= t_2^{10} + t_3^{100}
\end{aligned}
$$

Việc thay thế đệ quy sẽ khiến độ dài chuỗi tăng bùng nổ; độ dài của chúng thậm chí có thể đạt cỡ $100^{100}$. Cần tìm số lần xuất hiện của chuỗi $s$ trong từng chuỗi.

Bài toán này cũng có thể giải bằng cách xây dựng ô-tô-mát của hàm tiền tố. Tương tự như trước, tận dụng các kết quả đã tính để tính chuyển tiếp cho mỗi mẫu rồi thống kê đáp án tương ứng.

<span id="bài-tập"></span>
## Bài tập

-   [UVa 455 "Periodic Strings"](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=396)
-   [UVa 11022 "String Factoring"](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1963)
-   [UVa 11452 "Dancing the Cheeky-Cheeky"](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2447)
-   [UVa 12604 - Caesar Cipher](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4282)
-   [UVa 12467 - Secret Word](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3911)
-   [UVa 11019 - Matrix Matcher](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1960)
-   [SPOJ - Pattern Find](http://www.spoj.com/problems/NAJPF/)
-   [Codeforces - Anthem of Berland](http://codeforces.com/contest/808/problem/G)
-   [Codeforces - MUH and Cube Walls](http://codeforces.com/problemset/problem/471/D)

<span id="tài-liệu-tham-khảo-và-ghi-chú"></span>
## Tài liệu tham khảo và ghi chú

**Trang này chủ yếu được dịch từ bài viết [Префикс-функция. Алгоритм Кнута-Морриса-Пратта](http://e-maxx.ru/algo/prefix_function) và bản dịch tiếng Anh của nó, [Prefix function. Knuth-Morris-Pratt algorithm](https://cp-algorithms.com/string/prefix-function.html). Giấy phép của bản tiếng Nga là Public Domain + Leave a Link; giấy phép của bản tiếng Anh là CC-BY-SA 4.0.**

[^ref1]: [Jin Ce - Bài giảng chuyên đề thuật toán chuỗi](https://github.com/hzwer/shareOI/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%AE%97%E6%B3%95%E9%80%89%E8%AE%B2_%E9%87%91%E7%AD%96.pdf)

[^kmp]: Knuth, Donald E., James H. Morris, Jr, and Vaughan R. Pratt. "Fast pattern matching in strings." SIAM journal on computing 6.2 (1977): 323-350.[doi: 10.1137/0206024](https://epubs.siam.org/doi/abs/10.1137/0206024)
