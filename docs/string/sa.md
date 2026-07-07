<span id="một-số-quy-ước"></span>
## Một số quy ước

Các định nghĩa liên quan đến xâu được trình bày trong [Cơ sở về xâu](./basic.md).

Chỉ số của xâu bắt đầu từ $1$.

Độ dài của xâu $s$ là $n$.

"Hậu tố $i$" là hậu tố bắt đầu từ ký tự thứ $i$; khi lưu trữ, chỉ số $i$ đại diện cho hậu tố $s[i\dots n]$ của xâu $s$.

<span id="mảng-hậu-tố-là-gì"></span>
## Mảng hậu tố là gì?

Mảng hậu tố (Suffix Array) chủ yếu xoay quanh hai mảng: $sa$ và $rk$.

Trong đó, $sa[i]$ là chỉ số của hậu tố nhỏ thứ $i$ sau khi sắp xếp tất cả hậu tố. Đây chính là mảng hậu tố; các phần sau cũng gọi là mảng chỉ số $sa$.

$rk[i]$ là thứ hạng của hậu tố $i$, một mảng phụ quan trọng; các phần sau cũng gọi là mảng thứ hạng $rk$.

Hai mảng này thỏa tính chất: $sa[rk[i]]=rk[sa[i]]=i$.

<span id="diễn-giải"></span>
### Diễn giải

Ví dụ về mảng hậu tố:

[![](./images/sa1.png)][2]

<span id="tính-mảng-hậu-tố-như-thế-nào"></span>
## Tính mảng hậu tố như thế nào?

<span id="cách-on2log-n"></span>
### Cách $O(n^2\log n)$

Ý tưởng trực tiếp là đưa tất cả hậu tố vào một mảng rồi sắp xếp bằng `sort`. Việc sắp xếp cần $O(n\log n)$ lần so sánh xâu, mỗi lần so sánh xâu tốn $O(n)$ phép so sánh ký tự, nên độ phức tạp thời gian là $O(n^2\log n)$.

<span id="cách-onlog2-n"></span>
### Cách $O(n\log^2 n)$

Cách này dùng ý tưởng nhân đôi.

Trước hết, sắp xếp tất cả xâu con độ dài $1$ của xâu $s$, tức từng ký tự, để thu được mảng chỉ số đã sắp xếp $sa_1$ và mảng thứ hạng $rk_1$.

Quá trình nhân đôi:

1.  Dùng thứ hạng của hai xâu con độ dài $1$, tức $rk_1[i]$ và $rk_1[i+1]$, làm khóa thứ nhất và thứ hai để sắp xếp mỗi xâu con độ dài $2$ của $s$: $\{s[i\dots \min(i+1, n)]\ |\ i \in [1,\ n]\}$, thu được $sa_2$ và $rk_2$.

2.  Tiếp theo, dùng thứ hạng của hai xâu con độ dài $2$, tức $rk_2[i]$ và $rk_2[i+2]$, làm hai khóa sắp xếp để sắp xếp mỗi xâu con độ dài $4$ của $s$: $\{s[i\dots \min(i+3, n)]\ |\ i \in [1,\ n]\}$, thu được $sa_4$ và $rk_4$.

3.  Lặp lại quá trình nhân đôi: dùng thứ hạng của hai xâu con độ dài $w/2$, tức $rk_{w/2}[i]$ và $rk_{w/2}[i+w/2]$, làm hai khóa sắp xếp để sắp xếp mỗi xâu con độ dài $w$ của $s$, là $s[i\dots \min(i+w-1,\ n)]$, thu được $sa_w$ và $rk_w$. Tương tự quy tắc thứ tự từ điển, khi $i+w>n$ thì xem $rk_w[i+w]$ là âm vô cực.

4.  $rk_w[i]$ chính là thứ hạng của xâu con $s[i\dots i + w - 1]$. Khi $w \geqslant n$, mảng chỉ số $sa_w$ thu được chính là mảng hậu tố cần tìm.

<span id="quá-trình"></span>
#### Quá trình

Sơ đồ minh họa sắp xếp bằng nhân đôi:

[![](./images/sa2.png)][2]

Quá trình nhân đôi có $O(\log n)$ vòng. Trong mỗi vòng, dùng `sort` để sắp xếp các xâu con tốn $O(n\log n)$, còn mỗi lần so sánh xâu con chỉ cần $2$ phép so sánh ký tự.

Sau khi `sort` ở mỗi vòng còn có thao tác cập nhật $rk$ tốn thêm $O(n)$, nhưng phần chi phí này không ảnh hưởng đến độ phức tạp tổng thể so với $O(n\log n)$.

Vì vậy độ phức tạp thời gian của thuật toán là $O(n\log^2 n)$.

??? note "Cài đặt"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    
    using namespace std;
    
    constexpr int N = 1000010;
    
    char s[N];
    int n, w, sa[N], rk[N << 1], oldrk[N << 1];
    
    // Dùng mảng gấp đôi để tránh truy cập vượt biên khi đọc rk[i + w].
    // Cũng có thể kiểm tra biên trước khi truy cập, nhưng cấp phát gấp đôi tiện hơn.
    
    int main() {
      int i, p;
    
      scanf("%s", s + 1);
      n = strlen(s + 1);
      for (i = 1; i <= n; ++i) sa[i] = i, rk[i] = s[i];
    
      for (w = 1; w < n; w <<= 1) {
        sort(sa + 1, sa + n + 1, [](int x, int y) {
          return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
        });  // Dùng lambda để so sánh hai khóa.
        memcpy(oldrk, rk, sizeof(rk));
        // Vì rk cũ sẽ bị ghi đè khi tính rk mới, cần sao chép trước
        // Nếu hai xâu con bằng nhau, rk tương ứng của chúng cũng phải bằng nhau, nên cần loại trùng
        for (p = 0, i = 1; i <= n; ++i) {
          if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
              oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) {
            rk[sa[i]] = p;
          } else {
            rk[sa[i]] = ++p;
          }
        }
      }
    
      for (i = 1; i <= n; ++i) printf("%d ", sa[i]);
    
      return 0;
    }
    ```

<span id="cách-onlog-n"></span>
### Cách $O(n\log n)$

Trong cách $O(n\log^2 n)$ ở trên, mỗi lần sắp xếp tốn $O(n\log n)$. Nếu thay bước sắp xếp bằng một thuật toán $O(n)$, mảng hậu tố sẽ được tính trong $O(n\log n)$.

Kiến thức chuẩn bị: [sắp xếp đếm](../basic/counting-sort.md), [sắp xếp cơ số](../basic/radix-sort.md).

Trong quá trình tính mảng hậu tố, khóa sắp xếp là thứ hạng, có miền giá trị $O(n)$, và phép sắp xếp dùng hai khóa. Do đó có thể dùng sắp xếp cơ số để tối ưu xuống $O(n)$.

??? note "Cài đặt"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    
    using namespace std;
    
    constexpr int N = 1000010;
    
    char s[N];
    int n, sa[N], rk[N << 1], oldrk[N << 1], id[N], cnt[N];
    
    int main() {
      int i, m, p, w;
    
      scanf("%s", s + 1);
      n = strlen(s + 1);
      m = 127;
      for (i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
      for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
      for (i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
      memcpy(oldrk + 1, rk + 1, n * sizeof(int));
      for (p = 0, i = 1; i <= n; ++i) {
        if (oldrk[sa[i]] == oldrk[sa[i - 1]]) {
          rk[sa[i]] = p;
        } else {
          rk[sa[i]] = ++p;
        }
      }
    
      for (w = 1; w < n; w <<= 1, m = n) {
        // Sắp xếp đếm theo khóa thứ hai: id[i] + w
        memset(cnt, 0, sizeof(cnt));
        memcpy(id + 1, sa + 1,
               n * sizeof(int));  // id lưu một bản sao của sa, về bản chất tương đương oldsa
        for (i = 1; i <= n; ++i) ++cnt[rk[id[i] + w]];
        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[rk[id[i] + w]]--] = id[i];
    
        // Sắp xếp đếm theo khóa thứ nhất: id[i]
        memset(cnt, 0, sizeof(cnt));
        memcpy(id + 1, sa + 1, n * sizeof(int));
        for (i = 1; i <= n; ++i) ++cnt[rk[id[i]]];
        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];
    
        memcpy(oldrk + 1, rk + 1, n * sizeof(int));
        for (p = 0, i = 1; i <= n; ++i) {
          if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
              oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) {
            rk[sa[i]] = p;
          } else {
            rk[sa[i]] = ++p;
          }
        }
      }
    
      for (i = 1; i <= n; ++i) printf("%d ", sa[i]);
    
      return 0;
    }
    ```

<span id="một-số-tối-ưu-hằng-số"></span>
### Một số tối ưu hằng số

Nếu nộp đoạn mã trên lên [LOJ #111: Suffix Sorting](https://loj.ac/problem/111):

![](./images/sa3.png)

Nguyên nhân là hằng số của đoạn mã trên thực sự khá lớn.

<span id="khóa-thứ-hai-không-cần-sắp-xếp-đếm"></span>
#### Khóa thứ hai không cần sắp xếp đếm

Xét bản chất của việc sắp xếp theo khóa thứ hai: chỉ cần đưa các $sa[i]$ vượt khỏi phạm vi xâu (tức $sa[i] + w > n$) lên đầu mảng $sa$, rồi đưa phần còn lại vào theo thứ tự cũ:

```cpp
int cur = 0;
for (int i = n - w + 1; i <= n; i++) id[++cur] = i;
for (int i = 1; i <= n; i++)
  if (sa[i] > w) id[++cur] = sa[i] - w;
```

<span id="tối-ưu-miền-giá-trị-của-sắp-xếp-đếm"></span>
#### Tối ưu miền giá trị của sắp xếp đếm

Sau mỗi lần cập nhật $rk$, luôn thu được một giá trị $p$; đây chính là miền giá trị của $rk$, nên chỉ cần đặt miền giá trị thành $p$.

<span id="nếu-mọi-thứ-hạng-đều-khác-nhau-thì-có-thể-tạo-ngay-mảng-hậu-tố"></span>
#### Nếu mọi thứ hạng đều khác nhau thì có thể tạo ngay mảng hậu tố

Xét mảng $rk$ mới: nếu miền giá trị của nó là $[1,n]$ thì mọi thứ hạng đều khác nhau, khi đó không cần sắp xếp tiếp.

??? note "Cài đặt"
    ```cpp
    #include <algorithm>
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    
    using namespace std;
    
    constexpr int N = 1000010;
    
    char s[N];
    int n;
    int m, p, rk[N * 2], oldrk[N], sa[N * 2], id[N], cnt[N];
    
    int main() {
      scanf("%s", s + 1);
      n = strlen(s + 1);
      m = 128;
    
      for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
      for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
      for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
    
      for (int w = 1;; w <<= 1, m = p) {  // m = p là tối ưu miền giá trị
        int cur = 0;
        for (int i = n - w + 1; i <= n; i++) id[++cur] = i;
        for (int i = 1; i <= n; i++)
          if (sa[i] > w) id[++cur] = sa[i] - w;
    
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) cnt[rk[i]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];
    
        p = 0;
        memcpy(oldrk, rk, sizeof(oldrk));
        for (int i = 1; i <= n; i++) {
          if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
              oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
            rk[sa[i]] = p;
          else
            rk[sa[i]] = ++p;
        }
    
        if (p == n) break;  // Khi p = n thì không cần sắp xếp tiếp
      }
    
      for (int i = 1; i <= n; i++) printf("%d ", sa[i]);
    
      return 0;
    }
    ```

<span id="cách-on"></span>
### Cách $O(n)$

Trong đa số bài toán thông thường, cách nhân đôi với hằng số nhỏ đã đủ dùng. Những phần khác ngoài việc tính mảng hậu tố cũng thường có độ phức tạp $O(n\log n)$, nên bước tính mảng hậu tố bằng nhân đôi không trở thành nút thắt.

Với các bài đặc biệt, giới hạn thời gian chặt, hoặc yêu cầu thời gian chạy ngắn hơn nữa, cần dùng các phương pháp xây dựng mảng hậu tố trong $O(n)$.

#### SA-IS

Tham khảo [sắp xếp cảm ứng và thuật toán SA-IS](https://riteme.site/blog/2016-6-19/sais.html); [trang bình luận](https://github.com/riteme/riteme.github.io/issues/28) của bài viết này cũng có giá trị tham khảo.

#### DC3

Tham khảo [[2009] Suffix Array: A Powerful Tool for String Processing, by Luo Suiqian][2].

<span id="ứng-dụng-của-mảng-hậu-tố"></span>
## Ứng dụng của mảng hậu tố

<span id="tìm-vị-trí-dịch-vòng-nhỏ-nhất"></span>
### Tìm vị trí dịch vòng nhỏ nhất

Sao chép xâu $S$ một lần để thu được $SS$, bài toán sẽ chuyển thành bài toán sắp xếp hậu tố.

Ví dụ: [JSOI2007 - Character Encryption](https://www.luogu.com.cn/problem/P4051).

<span id="tìm-xâu-con-trong-xâu"></span>
### Tìm xâu con trong xâu

Nhiệm vụ là tìm xâu mẫu $S$ trong xâu chính $T$ theo kiểu trực tuyến. "Trực tuyến" nghĩa là xâu chính $T$ đã biết trước, nhưng xâu mẫu $S$ chỉ được biết khi có truy vấn. Có thể xây dựng trước mảng hậu tố của $T$, rồi tìm xâu con $S$. Nếu $S$ xuất hiện trong $T$, nó phải là tiền tố của một số hậu tố của $T$. Vì tất cả hậu tố đã được sắp xếp, có thể nhị phân $S$ trên mảng $p$. Mỗi lần so sánh $S$ với hậu tố hiện tại tốn $O(|S|)$, nên độ phức tạp tìm xâu con là $O(|S|\log |T|)$. Nếu xâu con xuất hiện nhiều lần trong $T$, các lần xuất hiện đó sẽ nằm liên tiếp trong mảng $p$. Vì vậy có thể nhị phân thêm để tìm số lần xuất hiện, và việc in ra mọi vị trí xuất hiện cũng đơn giản.

<span id="lấy-ký-tự-từ-hai-đầu-để-tối-thiểu-hóa-thứ-tự-từ-điển"></span>
### Lấy ký tự từ hai đầu để tối thiểu hóa thứ tự từ điển

Ví dụ: [USACO07DEC - Best Cow Line](https://www.luogu.com.cn/problem/P2870).

Đề bài: Cho một xâu. Mỗi lần lấy một ký tự ở đầu hoặc cuối để tạo xâu mới. Cần tìm xâu có thứ tự từ điển nhỏ nhất trong tất cả các xâu có thể tạo được.

??? note "Lời giải"
    Cách vét cạn là mỗi lần tốn tối đa $O(n)$ để quyết định nên lấy đầu hay lấy cuối, tức so sánh xâu nhận được khi lấy đầu với xâu đảo tương ứng khi lấy cuối. Cần tối ưu bước quyết định này.
    
    Vì cần so sánh trong tập gồm các hậu tố của xâu gốc và hậu tố của xâu đảo, có thể nối xâu đảo vào sau xâu gốc, thêm ở giữa một ký tự chưa từng xuất hiện (như `#`; trong code có thể dùng trực tiếp ký tự rỗng), rồi xây dựng mảng hậu tố. Khi đó mỗi lần quyết định chỉ tốn $O(1)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/sa/sa_1.cpp"
    ```

<span id="mảng-height"></span>
## Mảng height

<span id="lcp-tiền-tố-chung-dài-nhất"></span>
### LCP (tiền tố chung dài nhất)

LCP của hai xâu $S$ và $T$ là giá trị lớn nhất $x$ ($x\le \min(|S|, |T|)$) sao cho $S_i=T_i\ (\forall\ 1\le i\le x)$.

Trong phần sau, $lcp(i,j)$ biểu thị độ dài tiền tố chung dài nhất của hậu tố $i$ và hậu tố $j$.

<span id="định-nghĩa-mảng-height"></span>
### Định nghĩa mảng height

$height[i]=lcp(sa[i],sa[i-1])$, tức tiền tố chung dài nhất của hậu tố hạng $i$ và hậu tố đứng ngay trước nó.

Quy ước $height[1]$ là $0$.

<span id="bổ-đề-cần-dùng-để-tính-mảng-height-trong-on"></span>
### Bổ đề cần dùng để tính mảng height trong $O(n)$

$height[rk[i]]\ge height[rk[i-1]]-1$

???+ note "Chứng minh"
    Khi $height[rk[i-1]]\le1$, bất đẳng thức đúng vì vế phải không lớn hơn $0$.
    
    Khi $height[rk[i-1]]>1$:
    
    Theo định nghĩa của $height$, có $lcp(sa[rk[i-1]], sa[rk[i-1]-1]) = height[rk[i-1]] > 1$.
    
    Vì hậu tố $i-1$ và hậu tố $sa[rk[i-1]-1]$ có tiền tố chung dài nhất độ dài $height[rk[i-1]]$,
    
    ký hiệu tiền tố chung dài nhất này là $aA$, trong đó $a$ là một ký tự, còn $A$ là một xâu không rỗng có độ dài $height[rk[i-1]]-1$.
    
    Khi đó hậu tố $i-1$ có thể viết thành $aAD$, còn hậu tố $sa[rk[i-1]-1]$ có thể viết thành $aAB$, với $B < D$, $B$ có thể rỗng và $D$ không rỗng.
    
    Suy ra hậu tố $i$ có dạng $AD$, đồng thời tồn tại hậu tố $(sa[rk[i-1]-1]+1)$ có dạng $AB$.
    
    Vì hậu tố $sa[rk[i]-1]$ đứng ngay trước hậu tố $sa[rk[i]]$, tức hậu tố $i$, trong thứ tự sắp xếp, và $AB < AD$,
    
    nên $AB \leqslant$ hậu tố $sa[rk[i]-1] < AD$. Vì vậy, hậu tố $i$ và hậu tố $sa[rk[i]-1]$ có tiền tố chung $A$.
    
    Do đó $lcp(i,sa[rk[i]-1])$ ít nhất là $height[rk[i-1]]-1$, tức $height[rk[i]]\ge height[rk[i-1]]-1$.

<span id="cài-đặt-tính-mảng-height-trong-on"></span>
### Cài đặt tính mảng height trong $O(n)$

Dùng bổ đề trên để tính trực tiếp:

```cpp
for (i = 1, k = 0; i <= n; ++i) {
  if (rk[i] == 0) continue;
  if (k) --k;
  while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
  height[rk[i]] = k;
}
```

$k$ không vượt quá $n$ và giảm nhiều nhất $n$ lần, nên cũng tăng nhiều nhất $2n$ lần. Tổng độ phức tạp là $O(n)$.

<span id="ứng-dụng-của-mảng-height"></span>
## Ứng dụng của mảng height

<span id="tiền-tố-chung-dài-nhất-của-hai-xâu-con"></span>
### Tiền tố chung dài nhất của hai xâu con

$lcp(sa[i],sa[j])=\min\{height[i+1..j]\}$

Trực giác: nếu $height$ luôn lớn hơn một giá trị nào đó, thì bấy nhiêu ký tự đầu vẫn không đổi; ngược lại, vì các hậu tố đã được sắp xếp, sau khi đã thay đổi thì không thể quay lại trạng thái cũ.

Chứng minh chặt chẽ được trình bày trong [[2004] Suffix Array, by Xu Zhilei][1].

Với định lý này, bài toán tìm tiền tố chung dài nhất của hai xâu con được chuyển thành [bài toán RMQ](../topic/rmq.md).

<span id="so-sánh-thứ-tự-của-hai-xâu-con-trong-một-xâu"></span>
### So sánh thứ tự của hai xâu con trong một xâu

Giả sử cần so sánh thứ tự của $A=S[a..b]$ và $B=S[c..d]$.

Nếu $lcp(a, c)\ge\min(|A|, |B|)$, thì $A<B\iff |A|<|B|$.

Ngược lại, $A<B\iff rk[a]< rk[c]$.

<span id="số-lượng-xâu-con-khác-nhau"></span>
### Số lượng xâu con khác nhau

Xâu con chính là tiền tố của một hậu tố, nên có thể duyệt từng hậu tố, tính tổng số tiền tố rồi trừ đi phần trùng lặp.

"Tổng số tiền tố" chính là số xâu con, bằng $n(n+1)/2$.

Nếu duyệt các hậu tố theo thứ tự đã sắp xếp, những xâu con mới được thêm ở mỗi bước chính là các tiền tố còn lại sau khi bỏ phần LCP với hậu tố trước đó. Các tiền tố này đều mới; nếu không, tính chất $lcp(sa[i],sa[j])=\min\{height[i+1..j]\}$ sẽ bị mâu thuẫn. Chỉ các tiền tố này là mới, vì phần LCP đã được tính khi duyệt hậu tố trước.

Vì vậy đáp án là:

$\frac{n(n+1)}{2}-\sum\limits_{i=2}^nheight[i]$

<span id="độ-dài-lớn-nhất-của-xâu-con-xuất-hiện-ít-nhất-k-lần"></span>
### Độ dài lớn nhất của xâu con xuất hiện ít nhất $k$ lần

Ví dụ: [USACO06DEC - Milk Patterns](https://www.luogu.com.cn/problem/P2852).

??? note "Lời giải"
    Xuất hiện ít nhất $k$ lần nghĩa là sau khi sắp xếp hậu tố, tồn tại ít nhất $k$ hậu tố liên tiếp cùng nhận xâu con này làm tiền tố chung.
    
    Do đó, lấy giá trị nhỏ nhất trong mỗi nhóm $k-1$ phần tử $height$ liên tiếp, rồi lấy giá trị lớn nhất trong các giá trị nhỏ nhất đó sẽ được đáp án.
    
    Có thể dùng hàng đợi đơn điệu để giải trong $O(n)$, nhưng các cách khác cũng đủ để AC.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/sa/sa_2.cpp"
    ```

<span id="kiểm-tra-một-xâu-có-xuất-hiện-ít-nhất-hai-lần-không-chồng-lấp-trong-văn-bản-hay-không"></span>
### Kiểm tra một xâu có xuất hiện ít nhất hai lần không chồng lấp trong văn bản hay không

Có thể nhị phân độ dài $|s|$ của xâu mục tiêu, chia mảng $h$ thành các đoạn liên tiếp có LCP lớn hơn hoặc bằng $|s|$, rồi dùng RMQ để tìm chỉ số lớn nhất và nhỏ nhất xuất hiện trong từng đoạn. Nếu khoảng cách giữa hai chỉ số đó thỏa điều kiện, tồn tại một xâu độ dài $|s|$ xuất hiện hai lần không chồng lấp.

<span id="một-số-xâu-con-giống-nhau-liên-tiếp"></span>
### Một số xâu con giống nhau liên tiếp

Có thể duyệt độ dài $|s|$ của chuỗi lặp liên tiếp, chia toàn bộ xâu thành các khối theo $|s|$, rồi truy vấn LCP và LCS tại đầu của hai khối kề nhau. Chi tiết xem [[2009] Suffix Array: A Powerful Tool for String Processing][2].

Ví dụ: [NOI2016 - Excellent Splitting](https://loj.ac/p/2083).

<span id="kết-hợp-với-dsu"></span>
### Kết hợp với DSU

Một số bài yêu cầu chia mảng hậu tố thành các đoạn liên tiếp có độ dài LCP lớn hơn hoặc bằng một giá trị nào đó; tương đương với việc chia mảng $h$ thành các đoạn liên tiếp có giá trị nhỏ nhất lớn hơn hoặc bằng giá trị đó, rồi thống kê đáp án cho từng đoạn. Nếu có nhiều truy vấn, có thể xử lý ngoại tuyến. Quan sát rằng khi giá trị cho trước giảm đơn điệu, số đoạn thỏa điều kiện chỉ càng ít đi; đoạn mới đều được tạo bằng cách nối hai hoặc nhiều đoạn cũ, và các phần không thuộc đoạn cũ trong đoạn mới có giá trị $h$ đúng bằng giá trị vừa giảm tới. Vì vậy chỉ cần duy trì một DSU, mỗi lần hợp nhất hai đoạn kề nhau và cập nhật thông tin thống kê.

Bài kinh điển: [NOI2015 - Wine Tasting Conference](https://uoj.ac/problem/131).

<span id="kết-hợp-với-cây-phân-đoạn"></span>
### Kết hợp với cây phân đoạn

Một số bài yêu cầu tìm vài số đầu tiên thỏa điều kiện, trong khi các số đó lại nằm trong một đoạn của thứ tự sắp xếp hậu tố. Khi đó có thể dùng tính chất của sắp xếp trộn để hợp nhất thông tin của hai nút, rồi dùng cây phân đoạn để duy trì và truy vấn đáp án trên đoạn.

<span id="kết-hợp-với-ngăn-xếp-đơn-điệu"></span>
### Kết hợp với ngăn xếp đơn điệu

Ví dụ: [AHOI2013 - Difference](https://loj.ac/problem/2377).

??? note "Lời giải"
    Hai hạng đầu của biểu thức cần cộng có thể xử lý trực tiếp, bằng $n(n-1)(n+1)/2$ (mỗi hậu tố xuất hiện $n-1$ lần, tổng độ dài hậu tố là $n(n+1)/2$). Điểm chính là hạng cuối, tức LCP của từng cặp hậu tố.
    
    Có $lcp(i,j)=k$ tương đương với $\min\{height[i+1..j]\}=k$. Vì vậy có thể quy phần đóng góp của $lcp(i,j)$ vào $\min\{x|i+1\le x\le j, height[x]=lcp(i,j)\}$.
    
    Xét một vị trí đóng góp cho LCP của những cặp hậu tố nào: thực chất là chọn một hậu tố trong đoạn liên tiếp bên trái có $height$ lớn hơn nó, và chọn một hậu tố trong đoạn liên tiếp bên phải có $height$ không nhỏ hơn nó. Phần này có thể tính bằng [ngăn xếp đơn điệu](../ds/monotonic-stack.md).
    
    Phần ngăn xếp đơn điệu tương tự [Luogu P2659 - Beautiful Sequence](https://www.luogu.com.cn/problem/P2659) và [phương pháp đường treo](../misc/hoverline.md).

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/sa/sa_3.cpp"
    ```

Bài tương tự: [HAOI2016 - Find Identical Characters](https://loj.ac/problem/2064).

<span id="bài-tập"></span>
## Bài tập

-   [UVa 760 - DNA Sequencing](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=701)
-   [UVa 1223 - Editor](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3664)
-   [Codechef - Tandem](https://www.codechef.com/problems/TANDEM)
-   [Codechef - Substrings and Repetitions](https://www.codechef.com/problems/ANUSAR)
-   [Codechef - Entangled Strings](https://www.codechef.com/problems/TANGLED)
-   [Codeforces - Martian Strings](http://codeforces.com/problemset/problem/149/E)
-   [Codeforces - Little Elephant and Strings](http://codeforces.com/problemset/problem/204/E)
-   [SPOJ - Ada and Terramorphing](http://www.spoj.com/problems/ADAPHOTO/)
-   [SPOJ - Ada and Substring](http://www.spoj.com/problems/ADASTRNG/)
-   [UVa - 1227 - The longest constant gene](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3668)
-   [SPOJ - Longest Common Substring](http://www.spoj.com/problems/LCS/en/)
-   [UVa 11512 - GATTACA](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2507)
-   [QOJ 11240 - Suffixes and Palindromes](https://qoj.ac/problem/11240)
-   [GYM - Por Costel and the Censorship Committee](http://codeforces.com/gym/100923/problem/D)
-   [UVa 1254 - Top 10](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3695)
-   [UVa 12191 - File Recover](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3343)
-   [UVa 12206 - Stammering Aliens](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3358)
-   [Codechef - Jarvis and LCP](https://www.codechef.com/problems/INSQ16F)
-   [Luogu P8617 - Repeated Pattern](https://www.luogu.com.cn/problem/P8617)
-   [UVa 11107 - Life Forms](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2048)
-   [UVa 12974 - Exquisite Strings](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=862&page=show_problem&problem=4853)
-   [UVa 10526 - Intellectual Property](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1467)
-   [UVa 12338 - Anti-Rhyme Pairs](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3760)
-   [DevSkills Reconstructing Blue Print of Life](https://devskill.com/CodingProblems/ViewProblem/328)
-   [UVa 12191 - File Recover](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3343)
-   [SPOJ - Suffix Array](http://www.spoj.com/problems/SARRAY/)
-   [Gym 102470J - Stammering Aliens](https://codeforces.com/gym/102470/problem/J)
-   [SPOJ - LCS2](http://www.spoj.com/problems/LCS2/)
-   [Codeforces - Fake News (hard)](http://codeforces.com/contest/802/problem/I)
-   [SPOJ - Longest Commong Substring](http://www.spoj.com/problems/LONGCS/)
-   [SPOJ - Lexicographical Substring Search](http://www.spoj.com/problems/SUBLEX/)
-   [Codeforces - Forbidden Indices](http://codeforces.com/contest/873/problem/F)
-   [Codeforces - Tricky and Clever Password](http://codeforces.com/contest/30/problem/E)
-   [Gym 101470B - Circle of digits](https://codeforces.com/gym/101470/problem/B)

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

Các phần trên trang này được đưa vào từ commit [4070a9b](https://github.com/OI-wiki/OI-wiki/pull/950/commits/4070a9b3db8576db16c74d3ec33806ad10476eef), chủ yếu dịch từ bài viết [Суффиксный массив](http://e-maxx.ru/algo/suffix_array) và bản dịch tiếng Anh [mảng hậu tố](https://cp-algorithms.com/string/suffix-array.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.

Bài báo:

1.  [[2004] Suffix Array, by Xu Zhilei][1]

2.  [[2009] Suffix Array: A Powerful Tool for String Processing, by Luo Suiqian][2]

[1]: https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2004%E8%AE%BA%E6%96%87%E9%9B%86/%E8%AE%B8%E6%99%BA%E7%A3%8A--%E5%90%8E%E7%BC%80%E6%95%B0%E7%BB%84.pdf "[2004] Suffix Array, by Xu Zhilei"

[2]: https://github.com/OI-wiki/libs/blob/master/%E9%9B%86%E8%AE%AD%E9%98%9F%E5%8E%86%E5%B9%B4%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2009%E8%AE%BA%E6%96%87%E9%9B%86/11.%E7%BD%97%E7%A9%97%E9%AA%9E%E3%80%8A%E5%90%8E%E7%BC%80%E6%95%B0%E7%BB%84%E2%80%94%E2%80%94%E5%A4%84%E7%90%86%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%89%E5%8A%9B%E5%B7%A5%E5%85%B7%E3%80%8B/%E5%90%8E%E7%BC%80%E6%95%B0%E7%BB%84%E2%80%94%E2%80%94%E5%A4%84%E7%90%86%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%89%E5%8A%9B%E5%B7%A5%E5%85%B7.pdf "[2009] Suffix Array: A Powerful Tool for String Processing, by Luo Suiqian"
