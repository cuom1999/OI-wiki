<span id="&#25551;&#36848;"></span>
## Mô tả

Cho một xâu $s$ có độ dài $n$, hãy tìm mọi cặp $(i, j)$ sao cho xâu con $s[i \dots j]$ là một xâu đối xứng. Một xâu $t$ là xâu đối xứng khi $t = t_{\text{rev}}$, trong đó $t_{\text{rev}}$ là xâu đảo ngược của $t$.

<span id="&#35299;&#37322;"></span>
## Giải thích

Rõ ràng trong trường hợp xấu nhất có thể có $O(n^2)$ xâu đối xứng, nên thoạt nhìn bài toán dường như không có thuật toán tuyến tính.

Tuy nhiên thông tin về các xâu đối xứng có thể được biểu diễn bằng **một cách gọn hơn**: với mỗi vị trí $i = 0 \dots n - 1$, ta tìm hai giá trị $d_1[i]$ và $d_2[i]$. Chúng lần lượt biểu thị số xâu đối xứng độ dài lẻ và độ dài chẵn có tâm tại vị trí $i$. Nhìn theo cách khác, chúng cũng biểu thị bán kính của xâu đối xứng dài nhất có tâm tại $i$ (bán kính $d_1[i]$, $d_2[i]$ đều là số ký tự tính từ vị trí $i$ đến đầu phải của xâu đối xứng, có tính cả ký tự đầu phải).

Ví dụ, xâu $s = \mathtt{abababc}$ có ba xâu đối xứng độ dài lẻ với tâm tại $s[3] = b$; xâu đối xứng dài nhất có bán kính $3$, tức $d_1[3] = 3$:

$$
a\ \overbrace{b\ a\ \underset{s_3}{b}\ a\ b}^{d_1[3]=3}\ c
$$

Xâu $s = \mathtt{cbaabd}$ có hai xâu đối xứng độ dài chẵn với tâm tại $s[3] = a$; xâu đối xứng dài nhất có bán kính $2$, tức $d_2[3] = 2$:

$$
c\ \overbrace{b\ a\ \underset{s_3}{a}\ b}^{d_2[3]=2}\ d
$$

Vì vậy ý tưởng then chốt là: nếu có một xâu đối xứng độ dài $l$ với tâm tại vị trí $i$, thì cũng có các xâu đối xứng cùng tâm có độ dài $l-2$, $l-4$, v.v. Do đó hai mảng $d_1[i]$ và $d_2[i]$ đã đủ để biểu diễn thông tin về mọi xâu con đối xứng trong xâu.

Một sự thật đáng chú ý là tồn tại một thuật toán tuyến tính và khá đơn giản để tính hai "mảng tính chất đối xứng" $d_1[]$ và $d_2[]$ nói trên. Bài viết này mô tả chi tiết thuật toán đó.

<span id="&#35299;&#27861;"></span>
## Cách giải

Nhìn chung, bài toán này có nhiều cách giải: dùng hash xâu có thể giải trong $O(n \log n)$, còn dùng mảng hậu tố và LCA nhanh có thể giải trong $O(n)$.

Tuy nhiên thuật toán mô tả ở đây **đơn giản hơn hẳn**, đồng thời có hằng số nhỏ hơn về cả thời gian lẫn bộ nhớ. Thuật toán này do **Glenn K. Manacher** đề xuất năm 1975.

<span id="&#26420;&#32032;&#31639;&#27861;"></span>
## Thuật toán đơn giản

Để tránh mơ hồ trong phần sau, trước hết nêu rõ "thuật toán đơn giản" là gì.

Thuật toán này làm việc như sau: với mỗi vị trí tâm $i$, sau khi so sánh một cặp ký tự tương ứng, nếu còn có thể mở rộng thì tăng đáp án thêm $1$.

Thuật toán này chậm: nó chỉ tính được đáp án trong thời gian $O(n^2)$.

Cài đặt thuật toán đơn giản như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        vector<int> d1(n), d2(n);
        for (int i = 0; i < n; i++) {
          d1[i] = 1;
          while (0 <= i - d1[i] && i + d1[i] < n && s[i - d1[i]] == s[i + d1[i]]) {
            d1[i]++;
          }
        
          d2[i] = 0;
          while (0 <= i - d2[i] - 1 && i + d2[i] < n &&
                 s[i - d2[i] - 1] == s[i + d2[i]]) {
            d2[i]++;
          }
        }
        ```
    
    === "Python"
        ```python
        d1 = [0] * n
        d2 = [0] * n
        for i in range(0, n):
            d1[i] = 1
            while 0 <= i - d1[i] and i + d1[i] < n and s[i - d1[i]] == s[i + d1[i]]:
                d1[i] += 1
        
            d2[i] = 0
            while 0 <= i - d2[i] - 1 and i + d2[i] < n and s[i - d2[i] - 1] == s[i + d2[i]]:
                d2[i] += 1
        ```

<span id="Manacher-&#31639;&#27861;"></span>
## Thuật toán Manacher

Ở đây chỉ mô tả trường hợp tìm mọi xâu con đối xứng có độ dài lẻ, tức chỉ tính $d_1[]$; thuật toán tìm mọi xâu con đối xứng độ dài chẵn (tức tính mảng $d_2[]$) chỉ cần sửa một chút từ trường hợp lẻ.

Để tính nhanh, ta duy trì **biên $[l, r]$** của xâu con đối xứng đã tìm được có đầu phải xa nhất (tức xâu đối xứng có giá trị $r$ lớn nhất, trong đó $l$ và $r$ lần lượt là vị trí biên trái và biên phải của xâu đối xứng đó). Ban đầu đặt $l = 0$ và $r = -1$ (`-1` ở đây cần phân biệt với chỉ số đảo ngược; chỉ cần là một số âm bất kỳ để thuận tiện khi khởi tạo vòng lặp).

<span id="&#36807;&#31243;"></span>
### Quy trình

Giả sử cần tính $d_1[i]$ cho vị trí tiếp theo $i$, và mọi giá trị trước đó của $d_1[]$ đã được tính. Ta tính như sau:

-   Nếu $i$ nằm ngoài xâu con đối xứng hiện tại, tức $i > r$, ta gọi thuật toán đơn giản.

    Khi đó liên tục tăng $d_1[i]$, đồng thời ở mỗi bước kiểm tra xâu con hiện tại $[i - d_1[i] \dots i + d_1[i]]$ ($d_1[i]$ biểu thị bán kính, dưới đây cũng vậy) có phải xâu đối xứng hay không. Nếu gặp cặp ký tự đầu tiên khác nhau, hoặc chạm biên của $s$, thuật toán dừng. Trong cả hai trường hợp, $d_1[i]$ đã được tính xong. Sau đó vẫn cần nhớ cập nhật $(l, r)$.

-   Bây giờ xét trường hợp $i \le r$. Ta sẽ cố gắng lấy một phần thông tin từ các giá trị $d_1[]$ đã tính. Trước hết phản chiếu vị trí $i$ trong xâu con đối xứng $(l, r)$, thu được $j = l + (r - i)$. Xét giá trị $d_1[j]$. Vì vị trí $j$ đối xứng với vị trí $i$, ta **gần như luôn** có thể đặt $d_1[i] = d_1[j]$. Ý tưởng được minh họa như sau (có thể hiểu là xâu đối xứng tâm $j$ được "sao chép" sang vị trí tâm $i$):

    $$
    \ldots\
    \overbrace{
        s_l\ \ldots\
        \underbrace{
            s_{j-d_1[j]+1}\ \ldots\ s_j\ \ldots\ s_{j+d_1[j]-1}
        }_\text{palindrome}\
        \ldots\
        \underbrace{
            s_{i-d_1[j]+1}\ \ldots\ s_i\ \ldots\ s_{i+d_1[j]-1}
        }_\text{palindrome}\
        \ldots\ s_r
    }^\text{palindrome}\
    \ldots
    $$

    Tuy nhiên có một **trường hợp khó** cần xử lý đúng: khi xâu đối xứng "bên trong" chạm biên của xâu đối xứng "bên ngoài", tức $j - d_1[j] + 1 \le l$ (hoặc tương đương $i + d_1[j] - 1 \ge r$). Vì tính đối xứng ngoài phạm vi xâu đối xứng "bên ngoài" không được bảo đảm, đặt thẳng $d_1[i] = d_1[j]$ là không đúng: ta không có đủ thông tin để khẳng định xâu đối xứng tại vị trí $i$ có cùng độ dài.

    Thực tế, để xử lý đúng trường hợp này, cần "cắt ngắn" độ dài xâu đối xứng, tức đặt $d_1[i] = r - i + 1$. Sau đó chạy thuật toán đơn giản để cố gắng tăng $d_1[i]$ nhiều nhất có thể.

    Trường hợp này được minh họa như sau (xâu đối xứng tâm $j$ đã bị cắt ngắn để nằm trong xâu đối xứng "bên ngoài"):

    $$
    \ldots\
    \overbrace{
        \underbrace{
            s_l\ \ldots\ s_j\ \ldots\ s_{j+(j-l)}
        }_\text{palindrome}\
        \ldots\
        \underbrace{
            s_{i-(r-i)}\ \ldots\ s_i\ \ldots\ s_r
        }_\text{palindrome}
    }^\text{palindrome}\
    \underbrace{
        \ldots \ldots \ldots \ldots \ldots
    }_\text{try moving here}
    $$

    Hình này cho thấy dù xâu đối xứng tâm $j$ có thể dài hơn và vượt ra ngoài xâu đối xứng "bên ngoài", tại vị trí $i$ ta chỉ có thể dùng phần hoàn toàn nằm trong xâu đối xứng "bên ngoài". Tuy nhiên đáp án tại vị trí $i$ có thể lớn hơn giá trị này, nên tiếp theo ta chạy thuật toán đơn giản để thử mở rộng ra ngoài xâu đối xứng "bên ngoài", tức vùng được đánh dấu "try moving here".

Cuối cùng, cần nhắc lại rằng sau khi tính xong mỗi $d_1[i]$, phải nhớ cập nhật $(l, r)$.

Đồng thời, nhắc lại một lần nữa: thuật toán tính mảng xâu đối xứng độ dài chẵn $d_2[]$ rất giống với thuật toán tính mảng xâu đối xứng độ dài lẻ $d_1[]$ ở trên.

<span id="Manacher-&#31639;&#27861;&#30340;&#22797;&#26434;&#24230;"></span>
## Độ phức tạp của thuật toán Manacher

Vì khi tính đáp án cho một vị trí cụ thể ta luôn chạy thuật toán đơn giản, thoạt nhìn không hiển nhiên rằng thuật toán có thời gian tuyến tính.

Tuy nhiên phân tích kỹ hơn cho thấy thuật toán có độ phức tạp tuyến tính. Cần lưu ý rằng [thuật toán tính hàm Z](./z-func.md) khá giống thuật toán này và cũng có độ phức tạp thời gian tuyến tính.

Thực tế, mỗi lần lặp của thuật toán đơn giản đều làm $r$ tăng thêm $1$, và $r$ không bao giờ giảm trong quá trình thuật toán chạy. Hai quan sát này cho thấy thuật toán đơn giản chỉ thực hiện tổng cộng $O(n)$ lần lặp.

Phần còn lại của thuật toán Manacher hiển nhiên cũng tuyến tính, nên tổng độ phức tạp là $O(n)$.

<span id="Manacher-&#31639;&#27861;&#30340;&#23454;&#29616;"></span>
## Cài đặt thuật toán Manacher

<span id="&#20998;&#31867;&#35752;&#35770;"></span>
### Tách hai trường hợp

Để tính $d_1[]$, ta có đoạn mã sau:

=== "C++"
    ```cpp
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
      while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
      }
      d1[i] = k--;
      if (i + k > r) {
        l = i - k;
        r = i + k;
      }
    }
    ```

=== "Python"
    ```python
    d1 = [0] * n
    l, r = 0, -1
    for i in range(0, n):
        k = 1 if i > r else min(d1[l + r - i], r - i + 1)
        while 0 <= i - k and i + k < n and s[i - k] == s[i + k]:
            k += 1
        d1[i] = k
        k -= 1
        if i + k > r:
            l = i - k
            r = i + k
    ```

Mã tính $d_2[]$ rất giống, chỉ khác một chút trong các biểu thức số học:

=== "C++"
    ```cpp
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
      while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
      }
      d2[i] = k--;
      if (i + k > r) {
        l = i - k - 1;
        r = i + k;
      }
    }
    ```

=== "Python"
    ```python
    d2 = [0] * n
    l, r = 0, -1
    for i in range(0, n):
        k = 0 if i > r else min(d2[l + r - i + 1], r - i + 1)
        while 0 <= i - k - 1 and i + k < n and s[i - k - 1] == s[i + k]:
            k += 1
        d2[i] = k
        k -= 1
        if i + k > r:
            l = i - k - 1
            r = i + k
    ```

<span id="&#32479;&#19968;&#22788;&#29702;"></span>
### Xử lý thống nhất

Mặc dù trong phần giải thích và cài đặt ở trên ta tách riêng việc tính $d_1[]$ và $d_2[]$, trên thực tế có thể dùng một mẹo để quy cả hai về việc tính $d_1[]$.

Cho một xâu $s$ có độ dài $n$, chèn ký tự phân tách $\#$ vào $n+1$ khoảng trống của nó để xây một xâu $s'$ có độ dài $2n+1$. Ví dụ, với xâu $s = \mathtt{abababc}$, xâu tương ứng là $s' = \mathtt{\#a\#b\#a\#b\#a\#b\#c\#}$.

Ký tự $\#$ giữa các chữ cái có ý nghĩa là "khoảng trống" tương ứng trong $s$. Hai ký tự $\#$ ở hai đầu dùng để thuận tiện khi cài đặt.

Chú ý rằng sau khi tính $d_1[]$ cho $s'$, với một vị trí $i$, xâu con đối xứng dài nhất mà $d_1[i]$ mô tả nhất định kết thúc bằng $\#$ (nếu kết thúc bằng chữ cái, vì hai bên chữ cái đều có một $\#$, nó có thể mở rộng thêm một bước để dài hơn). Do đó, với một xâu con đối xứng cực đại trong $s$ có tâm là chữ cái và độ dài $m+1$, nó tương ứng trong $s'$ với một xâu con đối xứng cực đại có tâm là chữ cái tương ứng và độ dài $2m+3$; còn với một xâu con đối xứng cực đại trong $s$ có tâm là khoảng trống và độ dài $m$, nó tương ứng trong $s'$ với một xâu con đối xứng cực đại có tâm là ký tự $\#$ biểu diễn khoảng trống đó và độ dài $2m+1$ (trong cả hai trường hợp, $m$ đều là số chẵn, nhưng tính chất này không ảnh hưởng đến kết luận). Kết hợp các quan sát trên với một chút tính toán, ta được rằng trong $s'$, $d_1[i]$ biểu thị **tổng độ dài cộng một** của xâu con đối xứng cực đại trong $s$ có tâm tại vị trí tương ứng.

Kết luận trên thiết lập quan hệ giữa $d_1[]$ của $s'$ với $d_1[]$ và $d_2[]$ của $s$.

Vì cách xử lý thống nhất này về bản chất là tính $d_1[]$ của $s'$, nên sau khi có $s'$, mã giống hệt phần tính $d_1[]$ ở trên.

<span id="&#32451;&#20064;&#39064;&#30446;"></span>
## Bài tập

-   [UVa #11475 "Extend to Palindrome"](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2470)
-   [[Đội tuyển quốc gia] Xâu đối xứng kép dài nhất](https://www.luogu.com.cn/problem/P4555)
-   [CF1326D2. Labyrinth](https://codeforces.com/contest/1326/problem/D2)

**Trang này chủ yếu được dịch từ bài viết [Нахождение всех подпалиндромов](http://e-maxx.ru/algo/palindromes_count) và bản dịch tiếng Anh [Finding all sub-palindromes in $O(N)$](https://cp-algorithms.com/string/manacher.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.**
