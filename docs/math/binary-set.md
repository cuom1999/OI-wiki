Kiến thức cần có: [phép toán bit](./bit.md#phép-toán-bit), [số nguyên và chuỗi bit](./bit.md#số-nguyên-và-chuỗi-bit).

Biểu diễn nhị phân của một số có thể được xem như một tập hợp (`0` biểu thị không thuộc tập, `1` biểu thị thuộc tập). Ví dụ tập $\{1,3,4,8\}$ có thể được biểu diễn thành $(100011010)_2$. Các phép toán bit tương ứng cũng có thể được xem như phép toán trên tập hợp.

| Thao tác | Biểu diễn tập hợp | Biểu diễn bằng phép toán bit |
| ------ | :-------------: | :-------------------------: |
| Giao |   $a \cap b$    | $a \operatorname{AND} b$ |
| Hợp |   $a \cup b$    | $a \operatorname{OR} b$ |
| Bù |    $\bar{a}$    | $\operatorname{NOT} a$ (toàn tập có mọi bit nhị phân đều là 1) |
| Hiệu | $a \setminus b$ | $a \operatorname{AND} \operatorname{NOT} b$ |
| Hiệu đối xứng | $a\triangle b$  | $a \operatorname{XOR} b$  |

Trước khi giới thiệu thao tác duyệt tập con của tập hợp, hãy xem một vài ứng dụng liên quan của phép toán bit.

<span id="lấy-modulo-lũy-thừa-của-2"></span>
### Lấy modulo lũy thừa của 2

Lấy một số modulo một lũy thừa không âm của $2$ tương đương với lấy một số bit cuối trong biểu diễn nhị phân của số đó, cũng tương đương với phép AND với $mod-1$.

=== "C++"
    ```cpp
    int modPowerOfTwo(int x, int mod) { return x & (mod - 1); }
    ```

=== "Python"
    ```python
    def modPowerOfTwo(x, mod):
        return x & (mod - 1)
    ```

Do đó, một lũy thừa không âm của $2$ khi lấy modulo chính nó sẽ cho kết quả $0$. Nói cách khác, nếu $n$ là một lũy thừa không âm của $2$, kết quả AND của $n$ và $n-1$ là $0$.

Thực tế, với một số nguyên dương $n$, $n-1$ sẽ đưa bit `1` thấp nhất của $n$ về `0` và đặt toàn bộ các bit phía sau thành `1`. Vì vậy phép AND giữa $n$ và $n-1$ tương đương với việc xóa bit `1` thấp nhất của $n$.

Dựa vào đó có thể kiểm tra một số có phải là lũy thừa không âm của $2$ hay không. Khi và chỉ khi biểu diễn nhị phân của $n$ chỉ có một bit `1`, $n$ là một lũy thừa không âm của $2$.

=== "C++"
    ```cpp
    bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
    ```

=== "Python"
    ```python
    def isPowerOfTwo(n):
        return n > 0 and (n & (n - 1)) == 0
    ```

<span id="duyệt-tập-con"></span>
### Duyệt tập con

Duyệt mọi tập con của một tập được biểu diễn bằng số nhị phân tương đương với liệt kê mọi mặt nạ con của mặt nạ tương ứng.

Mặt nạ là một chuỗi bit dùng để AND với mã gốc, nhận được toán hạng mới sau khi che bớt một số bit đầu vào của mã gốc.

Mặt nạ đóng vai trò như một lớp che đối với mã gốc: bit `1` trong mặt nạ nghĩa là giữ bit tương ứng của mã gốc, còn bit `0` nghĩa là đặt bit tương ứng của mã gốc về `0`. Đổi một số bit `1` của mặt nạ thành `0` sẽ nhận được một mặt nạ con của mặt nạ; bản thân mặt nạ cũng là mặt nạ con của chính nó.

Cho một mặt nạ $m$, muốn duyệt hiệu quả mọi mặt nạ con $s$ của $m$, có thể dùng kỹ thuật bit sau.

```cpp
// Duyệt giảm dần các tập con không rỗng của m
int s = m;
while (s > 0) {
  // s là một tập con không rỗng của m
  s = (s - 1) & m;
}
```

Hoặc dùng câu lệnh `for` gọn hơn:

```cpp
// Duyệt giảm dần các tập con không rỗng của m
for (int s = m; s; s = (s - 1) & m)
// s là một tập con không rỗng của m
```

Hai đoạn mã này đều không xử lý mặt nạ con bằng $0$. Nếu muốn xử lý cả mặt nạ con bằng $0$, có thể dùng cách khác, ví dụ:

```cpp
// Duyệt giảm dần các tập con của m
for (int s = m;; s = (s - 1) & m) {
  // s là một tập con của m
  if (s == 0) break;
}
```

Tiếp theo chứng minh các đoạn mã trên thăm mọi mặt nạ con của $m$, không lặp, và theo thứ tự giảm dần.

Giả sử hiện có một mặt nạ $s$ và muốn thăm mặt nạ tiếp theo. Trừ $1$ khỏi mặt nạ $s$ tương đương với việc xóa bit được đặt ngoài cùng bên phải của $s$, rồi đổi toàn bộ bit bên phải nó thành `1`.

Để $s-1$ trở thành mặt nạ con mới, cần xóa mọi bit `1` dư không có trong mặt nạ $m$; thao tác `(s - 1) & m` thực hiện việc xóa này.

Hai bước trên tương đương với việc cắt mặt nạ $s-1$ để lấy giá trị lớn nhất có thể về mặt số học, tức mặt nạ con tiếp theo sau $s$ trong thứ tự giảm dần.

Vì vậy thuật toán sinh mọi mặt nạ con của mặt nạ theo thứ tự giảm dần, mỗi vòng lặp chỉ thực hiện hai thao tác.

Trường hợp đặc biệt là $s=0$. Sau khi thực hiện $s-1$, ta nhận được $-1$, có mọi bit đều là `1`. Sau thao tác `(s - 1) & m`, $s$ mới sẽ bằng $m$. Do đó nếu vòng lặp không kết thúc tại $s=0$, thuật toán sẽ không dừng.

Ký hiệu $\text{popcount}(m)$ là số bit `1` trong biểu diễn nhị phân của $m$. Với cách này, có thể duyệt các tập con của tập $m$ trong thời gian $O(2^{\text{popcount}(m)})$.

<span id="duyệt-submask-của-mọi-mask"></span>
### Duyệt mặt nạ con của mọi mặt nạ

Trong các bài toán DP trạng thái nén, đôi khi cần duyệt mọi mặt nạ con của mỗi mặt nạ:

```cpp
for (int m = 0; m < (1 << n); ++m)
  // Duyệt giảm dần các tập con không rỗng của m
  for (int s = m; s; s = (s - 1) & m)
// s là một tập con không rỗng của m
```

Cách này duyệt mọi tập con của từng tập con của tập có kích thước $n$.

Tiếp theo chứng minh độ phức tạp thời gian của thao tác này là $O(3^n)$, trong đó $n$ là tổng số bit của mặt nạ, tức tổng số phần tử trong tập.

Xét bit thứ $i$, tức phần tử thứ $i$ trong tập, có ba trường hợp:

- bit này bằng $0$ trong mặt nạ $m$, nên cũng bằng $0$ trong mặt nạ con $s$, tức phần tử không nằm trong cả tập lớn lẫn tập nhỏ;
- bit này bằng $1$ trong $m$ nhưng bằng $0$ trong $s$, tức phần tử chỉ nằm trong tập lớn, không nằm trong tập nhỏ;
- bit này bằng $1$ trong cả $m$ và $s$, tức phần tử đồng thời nằm trong tập lớn và tập nhỏ.

Có tổng cộng $n$ bit, nên có $3^n$ tổ hợp khác nhau.

Còn một cách chứng minh khác:

Nếu mặt nạ $m$ có $k$ bit `1`, nó có $2^k$ mặt nạ con. Với một $k$ cho trước, có $\dbinom{n}{k}$ mặt nạ $m$ tương ứng, nên tổng số mặt nạ là:

$$
\sum_{k=0}^n \dbinom{n}{k} 2^k
$$

Tổng trên bằng khai triển của $(1+2)^n$ theo định lý nhị thức, do đó có $3^n$ tổ hợp khác nhau.

<span id="tài-liệu-tham-khảo"></span>
### Tài liệu tham khảo

**Trang này chủ yếu được dịch từ bài viết [Перебор всех подмасок данной маски](http://e-maxx.ru/algo/all_submasks) và bản dịch tiếng Anh [Submask Enumeration](https://cp-algorithms.com/algebra/all-submasks.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.**

<span id="bài-tập"></span>
### Bài tập

- [Atcoder - Close Group](https://atcoder.jp/contests/abc187/tasks/abc187_f)
- [Codeforces - Nuclear Fusion](http://codeforces.com/problemset/problem/71/E)
- [Codeforces - Sandy and Nuts](http://codeforces.com/problemset/problem/599/E)
- [UVa 1439 - Exclusive Access 2](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4185)
- [UVa 11825 - Hackers' Crackdown](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2925)
