author: sshwy, StudyingFather, orzAtalod

<span id="định-nghĩa"></span>
## Định nghĩa

Trước hết giới thiệu khái niệm phân tích Lyndon.

Xâu Lyndon: với xâu $s$, nếu thứ tự từ điển của $s$ nhỏ hơn nghiêm ngặt thứ tự từ điển của mọi hậu tố của nó, $s$ được gọi là xâu đơn giản, hay **xâu Lyndon**. Ví dụ, `a`, `b`, `ab`, `aab`, `abb`, `ababb`, `abcd` đều là xâu Lyndon. Một xâu $s$ là xâu Lyndon khi và chỉ khi thứ tự từ điển của nó nhỏ hơn nghiêm ngặt mọi xâu đẳng cấu vòng không tầm thường của nó (không tầm thường nghĩa là không rỗng và khác chính nó).

Phân tích Lyndon: phân tích Lyndon của xâu $s$ được ký hiệu là $s=w_1w_2\cdots w_k$, trong đó mọi $w_i$ đều là xâu đơn giản và thứ tự từ điển của chúng được sắp không tăng, tức $w_1\ge w_2\ge\cdots\ge w_k$. Có thể chứng minh phân tích như vậy tồn tại và là duy nhất.

<span id="thuật-toán-duval"></span>
## Thuật toán Duval

<span id="giải-thích"></span>
### Giải thích

Duval có thể tìm phân tích Lyndon của một xâu trong thời gian $O(n)$.

Trước hết giới thiệu thêm một khái niệm: nếu một xâu $t$ có thể phân tích thành dạng $t=ww\cdots\overline{w}$, trong đó $w$ là một xâu Lyndon, còn $\overline{w}$ là một tiền tố của $w$ ($\overline{w}$ có thể là xâu rỗng), thì gọi $t$ là xâu gần đơn giản (pre-simple), hay xâu gần Lyndon. Một xâu Lyndon cũng là xâu gần Lyndon.

Thuật toán Duval dùng tư tưởng tham lam. Trong quá trình chạy, chia xâu $s$ thành ba phần $s=s_1s_2s_3$, trong đó $s_1$ là một xâu Lyndon và phân tích Lyndon của nó đã được ghi lại; $s_2$ là một xâu gần Lyndon; $s_3$ là phần chưa xử lý.

<span id="quy-trình"></span>
### Quy trình

Mô tả tổng thể: mỗi lần thuật toán thử thêm ký tự đầu của $s_3$ vào cuối $s_2$. Nếu $s_2$ không còn là xâu gần Lyndon, có thể cắt ra một phần tiền tố của $s_2$ (chính là một nhân tử trong phân tích Lyndon) và nối vào cuối $s_1$.

Giải thích chi tiết hơn như sau. Định nghĩa con trỏ $i$ trỏ tới ký tự đầu của $s_2$, nên $i$ duyệt từ $1$ đến $n$ (độ dài xâu). Trong vòng lặp, định nghĩa thêm con trỏ $j$ trỏ tới ký tự đầu của $s_3$, và con trỏ $k$ trỏ tới ký tự đang xét trong $s_2$ (nghĩa là ký tự tương ứng với $j$ ở chu kỳ trước của $s_2$). Mục tiêu là thêm $s[j]$ vào cuối $s_2$, nên cần so sánh $s[j]$ với $s[k]$:

1.  Nếu $s[j]=s[k]$, việc thêm $s[j]$ vào cuối $s_2$ không ảnh hưởng đến tính gần đơn giản. Do đó chỉ cần tăng hai con trỏ $j,k$ sang vị trí tiếp theo.
2.  Nếu $s[j]>s[k]$, thì $s_2s[j]$ trở thành một xâu Lyndon. Tăng con trỏ $j$, đồng thời đưa $k$ về ký tự đầu của $s_2$, để $s_2$ trở thành một xâu Lyndon mới với số chu kỳ bằng 1.
3.  Nếu $s[j]<s[k]$, thì $s_2s[j]$ không còn là xâu gần đơn giản. Khi đó phân tích ra từ $s_2$ một xâu con Lyndon, có độ dài $j-k$, tức một chu kỳ của nó. Sau đó biến $s_2$ thành phần còn lại sau khi cắt và tiếp tục vòng lặp (chú ý rằng trong trường hợp này không thay đổi $j,k$), cho tới khi cắt hết các chu kỳ. Với phần còn lại, chỉ cần "lùi" tiến độ về đầu phần còn lại.

<span id="cài-đặt"></span>
### Cài đặt

Đoạn mã sau trả về một phương án phân tích Lyndon của xâu $s$.

=== "C++"
    ```cpp
    // duval_algorithm
    vector<string> duval(string const& s) {
      int n = s.size(), i = 0;
      vector<string> factorization;
      while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
          if (s[k] < s[j])
            k = i;
          else
            k++;
          j++;
        }
        while (i <= k) {
          factorization.push_back(s.substr(i, j - k));
          i += j - k;
        }
      }
      return factorization;
    }
    ```

=== "Python"
    ```python
    # duval_algorithm
    def duval(s):
        n, i = len(s), 0
        factorization = []
        while i < n:
            j, k = i + 1, i
            while j < n and s[k] <= s[j]:
                if s[k] < s[j]:
                    k = i
                else:
                    k += 1
                j += 1
            while i <= k:
                factorization.append(s[i : i + j - k])
                i += j - k
        return factorization
    ```

<span id="phân-tích-độ-phức-tạp"></span>
### Phân tích độ phức tạp

Tiếp theo chứng minh độ phức tạp của thuật toán.

Số lần lặp của vòng ngoài không vượt quá $n$, vì mỗi lần $i$ đều tăng. Vòng trong thứ hai cũng là $O(n)$, vì nó chỉ ghi lại phương án phân tích Lyndon. Xét vòng trong còn lại. Mỗi xâu Lyndon tìm được trong vòng ngoài dài hơn phần xâu còn lại đã được so sánh, nên tổng độ dài của các phần còn lại nhỏ hơn $n$; vì vậy vòng trong này chạy nhiều nhất $O(n)$ lần. Trên thực tế, tổng số vòng lặp không vượt quá $4n-3$, nên độ phức tạp thời gian là $O(n)$.

<span id="biểu-diễn-vòng-nhỏ-nhất"></span>
## Biểu diễn vòng nhỏ nhất

Với một xâu $s$ có độ dài $n$, có thể dùng thuật toán trên để tìm biểu diễn nhỏ nhất của xâu này.

Xây phân tích Lyndon của xâu $ss$, rồi tìm một xâu Lyndon $t$ trong phân tích đó sao cho điểm bắt đầu của nó nhỏ hơn $n$ và điểm kết thúc của nó không nhỏ hơn $n$. Có thể dùng tính chất của phân tích Lyndon để chứng minh ký tự đầu của xâu con $t$ chính là ký tự đầu của biểu diễn nhỏ nhất của $s$; tức xâu gồm $n$ ký tự bắt đầu từ đầu $t$ chính là biểu diễn nhỏ nhất của $s$.

Vì vậy trong quá trình phân tích, chỉ cần ghi lại điểm bắt đầu của xâu gần Lyndon mỗi lần.

=== "C++"
    ```cpp
    // smallest_cyclic_string
    string min_cyclic_string(string s) {
      s += s;
      int n = s.size();
      int i = 0, ans = 0;
      while (i < n / 2) {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
          if (s[k] < s[j])
            k = i;
          else
            k++;
          j++;
        }
        while (i <= k) i += j - k;
      }
      return s.substr(ans, n / 2);
    }
    ```

=== "Python"
    ```python
    # smallest_cyclic_string
    def min_cyclic_string(s):
        s += s
        n = len(s)
        i, ans = 0, 0
        while i < n / 2:
            ans = i
            j, k = i + 1, i
            while j < n and s[k] <= s[j]:
                if s[k] < s[j]:
                    k = i
                else:
                    k += 1
                j += 1
            while i <= k:
                i += j - k
        return s[ans : ans + n / 2]
    ```

<span id="bài-tập"></span>
## Bài tập

-   [UVa #719 - Glass Beads](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=660)

    **Trang này chủ yếu được dịch từ bài viết [Декомпозиция Линдона. Алгоритм Дюваля. Нахождение наименьшего циклического сдвига](http://e-maxx.ru/algo/duval_algorithm) và bản dịch tiếng Anh [Lyndon factorization](https://cp-algorithms.com/string/lyndon_factorization.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.**
