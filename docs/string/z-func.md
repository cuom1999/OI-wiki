author: LeoJacob, Marcythm, minghu6

Quy ước: chỉ số xâu bắt đầu từ $0$.

<span id="định-nghĩa"></span>
## Định nghĩa

Với một xâu $s$ có độ dài $n$, định nghĩa hàm $z[i]$ là độ dài tiền tố chung dài nhất (LCP) của $s$ và $s[i,n-1]$ (tức hậu tố bắt đầu tại $s[i]$). Khi đó $z$ được gọi là **hàm Z** của $s$. Đặc biệt, $z[0] = 0$.

Ở nước ngoài, thuật toán tính mảng này thường được gọi là **thuật toán Z**; trong tài liệu Trung Quốc, nó còn được gọi là **KMP mở rộng** (exKMP).

Bài viết này giới thiệu thuật toán tính hàm Z trong thời gian $O(n)$ và một số ứng dụng của nó.

<span id="giải-thích"></span>
## Giải thích

Một vài ví dụ dưới đây minh họa hàm Z của các xâu khác nhau:

-   $z(\mathtt{aaaaa}) = [0, 4, 3, 2, 1]$
-   $z(\mathtt{aaabaab}) = [0, 2, 1, 0, 2, 1, 0]$
-   $z(\mathtt{abacaba}) = [0, 0, 1, 0, 3, 0, 1]$

<span id="thuật-toán-đơn-giản"></span>
## Thuật toán đơn giản

Thuật toán đơn giản để tính hàm Z có độ phức tạp $O(n^2)$:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        vector<int> z_function_trivial(string s) {
          int n = (int)s.length();
          vector<int> z(n);
          for (int i = 1; i < n; ++i)
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
          return z;
        }
        ```
    
    === "Python"
        ```python
        def z_function_trivial(s):
            n = len(s)
            z = [0] * n
            for i in range(1, n):
                while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                    z[i] += 1
            return z
        ```

<span id="thuật-toán-tuyến-tính"></span>
## Thuật toán tuyến tính

Giống nhiều thuật toán trong chủ đề xâu, điểm then chốt là dùng tư tưởng tự động hóa để tìm hàm chuyển trạng thái dưới các ràng buộc, từ đó tận dụng các trạng thái đã biết để tăng tốc việc tính trạng thái mới.

Trong thuật toán này, tính lần lượt các giá trị $z[i]$ từ $1$ đến $n-1$ (với $z[0]=0$). Khi tính $z[i]$, sử dụng các giá trị đã tính $z[0],\ldots,z[i-1]$.

Với một vị trí $i$, gọi đoạn $[i,i+z[i]-1]$ là **đoạn khớp** của $i$, hay còn gọi là Z-box.

Trong quá trình chạy, thuật toán duy trì đoạn khớp có đầu phải xa nhất. Để tiện, ký hiệu đoạn này là $[l,r]$. Theo định nghĩa, $s[l,r]$ là một tiền tố của $s$. Khi tính $z[i]$, luôn có $l\le i$. Ban đầu $l=r=0$.

Khi tính $z[i]$:

-   Nếu $i\le r$, theo định nghĩa của $[l,r]$ có $s[i,r] = s[i-l,r-l]$, do đó $z[i]\ge \min(z[i-l],r-i+1)$. Khi đó:
    -   Nếu $z[i-l] < r-i+1$, thì $z[i] = z[i-l]$.
    -   Ngược lại, $z[i-l]\ge r-i+1$. Đặt $z[i] = r-i+1$, rồi vét cạn các ký tự tiếp theo để mở rộng $z[i]$ cho tới khi không thể mở rộng nữa.
-   Nếu $i>r$, trực tiếp làm như thuật toán đơn giản: bắt đầu so sánh từ $s[i]$ và vét cạn để tìm $z[i]$.
-   Sau khi tìm được $z[i]$, nếu $i+z[i]-1>r$, cần cập nhật $[l,r]$, tức đặt $l=i, r=i+z[i]-1$.

Có thể xem mô phỏng quá trình tính hàm Z tại [trang này](https://personal.utdallas.edu/~besp/demo/John2010/z-algorithm.htm).

<span id="cài-đặt"></span>
### Cài đặt

=== "C++"
    ```cpp
    vector<int> z_function(string s) {
      int n = (int)s.length();
      vector<int> z(n);
      for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
          z[i] = z[i - l];
        } else {
          z[i] = max(0, r - i + 1);
          while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
      }
      return z;
    }
    ```

=== "Python"
    ```python
    def z_function(s):
        n = len(s)
        z = [0] * n
        l, r = 0, 0
        for i in range(1, n):
            if i <= r and z[i - l] < r - i + 1:
                z[i] = z[i - l]
            else:
                z[i] = max(0, r - i + 1)
                while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                    z[i] += 1
            if i + z[i] - 1 > r:
                l = i
                r = i + z[i] - 1
        return z
    ```

<span id="phân-tích-độ-phức-tạp"></span>
## Phân tích độ phức tạp

Với vòng lặp `while` bên trong, mỗi lần thực hiện đều làm $r$ dịch sang phải ít nhất $1$ vị trí, trong khi $r<n-1$, nên tổng cộng vòng lặp này chỉ chạy $n$ lần.

Vòng lặp ngoài chỉ duyệt tuyến tính một lượt.

Vì vậy tổng độ phức tạp là $O(n)$.

<span id="ứng-dụng"></span>
## Ứng dụng

Bây giờ xét các ứng dụng của hàm Z trong một số tình huống cụ thể.

Các ứng dụng này phần lớn tương tự các ứng dụng của [hàm tiền tố](./kmp.md).

<span id="khớp-mọi-lần-xuất-hiện-của-xâu-con"></span>
### Khớp mọi lần xuất hiện của xâu con

Để tránh nhầm lẫn, gọi $t$ là **văn bản** và $p$ là **mẫu**. Bài toán đặt ra là tìm mọi lần xuất hiện (occurrence) của mẫu $p$ trong văn bản $t$.

Để giải bài toán này, xây dựng một xâu mới $s = p + \diamond + t$, tức nối $p$ và $t$ lại với nhau nhưng đặt một ký tự phân tách $\diamond$ ở giữa (chọn $\diamond$ sao cho nó không xuất hiện trong $p$ hoặc $t$).

Trước hết tính hàm Z của $s$. Sau đó, với mỗi $i$ trong đoạn $[0,|t| - 1]$, xét giá trị hàm Z trong $s$ của hậu tố bắt đầu tại $t[i]$, tức $k = z[i + |p| + 1]$. Nếu $k = |p|$, có một lần xuất hiện của $p$ tại vị trí thứ $i$ của $t$; ngược lại, không có lần xuất hiện của $p$ tại vị trí đó.

Độ phức tạp thời gian (và cũng là độ phức tạp bộ nhớ) là $O(|t| + |p|)$.

<span id="số-xâu-con-khác-nhau-về-bản-chất"></span>
### Số xâu con khác nhau về bản chất

Cho một xâu $s$ có độ dài $n$, cần tính số lượng xâu con khác nhau về bản chất của $s$.

Xét cách tính phần tăng thêm: khi đã biết số xâu con khác nhau về bản chất của $s$ hiện tại, cần tính số này sau khi thêm một ký tự vào cuối $s$.

Gọi $k$ là số xâu con khác nhau về bản chất của $s$ hiện tại. Thêm một ký tự mới $c$ vào cuối $s$. Khi đó sẽ xuất hiện một số xâu con mới kết thúc bằng $c$ (những xâu con kết thúc bằng $c$ và chưa từng xuất hiện trước đó).

Gọi $t$ là xâu đảo ngược của $s+c$ (xâu đảo ngược là xâu thu được bằng cách sắp các ký tự của xâu ban đầu theo thứ tự ngược lại). Nhiệm vụ là tính có bao nhiêu tiền tố của $t$ không xuất hiện ở nơi khác trong $t$. Tính hàm Z của $t$ và lấy giá trị lớn nhất $z_{\max}$. Khi đó, đảo ngược của các tiền tố của $t$ có độ dài không vượt quá $z_{\max}$ chính là các xâu con kết thúc bằng $c$ đã từng xuất hiện trong $s$.

Vì vậy, sau khi thêm ký tự $c$ vào $s$, số xâu con mới xuất hiện là $|t| - z_{\max}$.

Thuật toán có độ phức tạp thời gian $O(n^2)$.

Với cùng phương pháp, có thể tính lại trong $O(n)$ số xâu con khác nhau về bản chất sau khi thêm một ký tự ở một đầu hoặc xóa một ký tự ở một đầu (từ cuối hoặc từ đầu).

<span id="chu-kỳ-nguyên-của-xâu"></span>
### Chu kỳ nguyên của xâu

Cho một xâu $s$ có độ dài $n$, cần tìm chu kỳ nguyên ngắn nhất của nó, tức tìm xâu ngắn nhất $t$ sao cho $s$ có thể biểu diễn bằng cách nối một số bản sao của $t$.

Tính hàm Z của $s$; độ dài chu kỳ nguyên của nó là ước nhỏ nhất $i$ của $n$ thỏa $i+z[i]=n$.

Chứng minh tính chất này giống với chứng minh khi dùng [hàm tiền tố](./kmp.md).

<span id="bài-tập"></span>
## Bài tập

-   [luogu P5410 [Mẫu] KMP mở rộng/exKMP (hàm Z)](https://www.luogu.com.cn/problem/P5410)
-   [luogu P7114 [NOIP2020] Khớp xâu](https://www.luogu.com.cn/problem/P7114)
-   [CF126B Password](http://codeforces.com/problemset/problem/126/B)
-   [UVa # 455 Periodic Strings](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=396)
-   [UVa # 11022 String Factoring](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1963)
-   [UVa 11475 - Extend to Palindrome](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2470)
-   [Codechef - Chef and Strings](https://www.codechef.com/problems/CHSTR)
-   [Codeforces - Prefixes and Suffixes](http://codeforces.com/problemset/problem/432/D)
-   [Leetcode 2223 - Sum of Scores of Built Strings](https://leetcode.com/problems/sum-of-scores-of-built-strings/)

**Trang này chủ yếu được dịch từ bài viết [Z-функция строки и её вычисление](http://e-maxx.ru/algo/z_function) và bản dịch tiếng Anh [Z-function and its calculation](https://cp-algorithms.com/string/z-function.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.**
