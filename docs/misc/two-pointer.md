Trang này sẽ giới thiệu ngắn gọn về hai con trỏ.

## Mở đầu

Hai con trỏ là một kỹ thuật và tư tưởng đơn giản nhưng linh hoạt. Khi dùng riêng, nó có thể giải gọn một số bài toán đặc thù; khi kết hợp với các thuật toán khác, nó cũng phát huy được nhiều tác dụng khác nhau.

Đúng như tên gọi, hai con trỏ là việc đồng thời dùng hai con trỏ: trên cấu trúc dãy hoặc danh sách liên kết, chúng trỏ vào vị trí; trên cây hoặc đồ thị, chúng trỏ vào đỉnh. Bằng cách di chuyển cùng chiều hoặc ngược chiều, thuật toán duy trì và thống kê thông tin cần thiết.

Sau đây là một vài cách dùng cụ thể của hai con trỏ.

## Duy trì thông tin đoạn

Nếu không kết hợp với cấu trúc dữ liệu khác, mẫu đơn giản nhất khi dùng hai con trỏ để duy trì thông tin đoạn là duy trì những thông tin có tính đơn điệu nhất định và việc thêm, xóa một phần tử đều dễ xử lý, chẳng hạn tổng các số dương, tích các số nguyên dương, v.v.

### Ví dụ 1

???+ note "Ví dụ 1 [leetcode 713. Số mảng con có tích nhỏ hơn K](https://leetcode-cn.com/problems/subarray-product-less-than-k/)"
    Cho một mảng số nguyên dương $\mathit{nums}$ độ dài $n$ và một số nguyên $k$, tìm số lượng mảng con liên tiếp có tích nhỏ hơn $k$ trong mảng này.
    
    Trong đó, $1 \leq n \leq 3 \times 10^4, 1 \leq nums[i] \leq 1000, 0 \leq k \leq 10^6$.

#### Quá trình

Gọi hai con trỏ là $l,r$, đồng thời đặt một biến $\mathit{tmp}$ để ghi tích của tất cả các số trong $[l,r]$. Ban đầu $l,r$ đều nằm ở phía trái nhất. Trước hết di chuyển $r$ sang phải cho đến lần đầu tiên phát hiện $\mathit{tmp}\geq k$; lúc đó cố định $r$ và di chuyển $l$ sang phải cho đến khi $\mathit{tmp}\lt k$. Khi đó với mỗi $r$, $l$ là biên trái xa nhất mà nó có thể mở rộng tới. Nhờ tính đơn điệu của tích các số nguyên dương, số đoạn thỏa mãn điều kiện bài toán và có đầu mút phải là $r$ bằng $r-l+1$.

#### Cài đặt

```cpp
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
  long long ji = 1ll, ans = 0;
  int l = 0;
  for (int i = 0; i < nums.size(); ++i) {
    ji *= nums[i];
    while (l <= i && ji >= k) ji /= nums[l++];
    ans += i - l + 1;
  }
  return ans;
}
```

Dùng hai con trỏ để duy trì thông tin đoạn cũng có thể kết hợp với các cấu trúc dữ liệu khác, như sai phân, hàng đợi đơn điệu, cây phân đoạn, cây chủ tịch, v.v. Ngoài ra, thuật toán Mo cũng tích hợp kỹ thuật hai con trỏ: sau khi sắp xếp ngoại tuyến các truy vấn, thuật toán Mo thường dùng hai con trỏ để ghi đoạn hiện tại cần xử lý, rồi cập nhật dần thông tin của đoạn khi các con trỏ từng bước di chuyển.

### Ví dụ 2

Tiếp theo là một bài ví dụ dùng hai con trỏ trên cây và kết hợp với sai phân trên cây:

???+ note "Ví dụ 2 [luogu P3066 Running Away From the Barn G](https://www.luogu.com.cn/problem/P3066)"
    Cho một cây có gốc gồm $n$ đỉnh, các cạnh có trọng số, các đỉnh được đánh số từ 1 đến $n$, và đỉnh 1 là gốc của cây. Cho thêm một tham số $t$; với mỗi đỉnh $u$ trên cây, tính trong cây con của $u$ có bao nhiêu đỉnh mà khoảng cách từ đỉnh đó đến $u$ không vượt quá $t$. Phạm vi dữ liệu: $1\leq n \leq 2\times 10^5,1 \leq t \leq 10^{18},1 \leq p_i \lt i,1 \leq w_i \leq 10^{12}$

#### Quá trình

Duyệt DFS toàn bộ cây bắt đầu từ gốc, dùng một ngăn xếp để ghi chuỗi đỉnh trên đường từ gốc đến đỉnh hiện tại. Đặt một con trỏ $u$ trỏ vào đỉnh hiện tại, và con trỏ còn lại $p$ trỏ vào đỉnh có độ sâu nhỏ nhất trong các đỉnh có khoảng cách đến $u$ không vượt quá $t$. Ghi lại khoảng cách đến gốc, và mỗi lần dùng tìm kiếm nhị phân để xác định $p$. Khi đó $u$ đóng góp một đơn vị cho mỗi đỉnh trên đường đi từ $p$ đến $u$, có thể dùng sai phân trên cây để ghi nhận.

Cần lưu ý không thể trực tiếp di chuyển $p$ bằng vét cạn, nếu không độ phức tạp thời gian có thể suy biến thành $O(n^2)$.

### Bài tập

[leetcode 1438. Mảng con liên tiếp dài nhất có chênh lệch tuyệt đối không vượt quá giới hạn](https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

## Khớp dãy con

???+ note "Ví dụ 3 [leetcode 524. Từ dài nhất trong từ điển có thể khớp bằng cách xóa ký tự](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)"
    Cho một chuỗi $s$ và một mảng chuỗi $\mathit{dictionary}$ làm từ điển, tìm và trả về chuỗi dài nhất trong từ điển có thể nhận được bằng cách xóa một số ký tự trong $s$.

### Quá trình

Dạng bài này cần khớp chuỗi $s$ với chuỗi $t$ để kiểm tra $t$ có phải là dãy con của $s$ hay không. Để giải, chỉ cần đặt hai con trỏ: $i$ ở vị trí đầu của $s$ và $j$ ở vị trí đầu của $t$. Nếu $s[i]=t[j]$, nghĩa là ký tự thứ $j$ của $t$ đã tìm được vị trí tương ứng đầu tiên trong $s$, nên có thể tiếp tục kiểm tra phần sau; khi đó tăng đồng thời $i$ và $j$ lên một. Nếu đẳng thức trên không đúng, ký tự thứ $j$ của $t$ vẫn chưa được khớp, nên chỉ tăng $i$ lên một để tiếp tục tìm ở phần sau của $s$. Cuối cùng, nếu $j$ đã đi qua vị trí cuối, toàn bộ chuỗi đã khớp được, tức $t$ là một dãy con của $s$; ngược lại thì không phải.

### Cài đặt

```cpp
string findLongestWord(string s, vector<string>& dictionary) {
  sort(dictionary.begin(), dictionary.end());
  int mx = 0, r = 0;
  string ans = "";
  for (int i = dictionary.size() - 1; i >= 0; i--) {
    r = 0;
    for (int j = 0; j < s.length(); ++j) {
      if (s[j] == dictionary[i][r]) r++;
    }
    if (r == dictionary[i].length()) {
      if (r >= mx) {
        mx = r;
        ans = dictionary[i];
      }
    }
  }
  return ans;
}
```

Phương pháp hai con trỏ trỏ vào hai đối tượng khác nhau rồi lần lượt so khớp như trên cũng có thể dùng trong một số bài DP.

## Tận dụng tính sắp xếp của dãy

Nhiều khi việc dùng hai con trỏ trên dãy có thể đạt đúng mục tiêu là nhờ một số tính chất của dãy; thường gặp nhất là tận dụng tính sắp xếp của dãy.

???+ note "Ví dụ 4 [leetcode 167. Tổng hai số II - mảng đầu vào đã sắp xếp](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)"
    Cho một mảng số nguyên `numbers` đã được sắp xếp theo **thứ tự tăng dần**, tìm hai số trong mảng sao cho tổng của chúng bằng số mục tiêu `target`.

### Quá trình

Đây cũng là một ứng dụng kinh điển của hai con trỏ. Tìm kiếm nhị phân cũng khá tiện, nhưng độ phức tạp thời gian sẽ thêm một thừa số $\log{n}$, và mã cũng không gọn bằng.

Sau đây là cách làm bằng hai con trỏ: vì cần tìm hai số và hai số này không thể ở cùng một vị trí, nên vị trí của chúng phải là một trái một phải. Do tổng hai số cố định, trong hai số đó, nếu số nhỏ hơn càng lớn thì số lớn hơn càng nhỏ. Dựa trên các tính chất này, có thể thu hẹp dần từ hai đầu.

Trước hết giả sử đáp án là 1 và n. Nếu thấy $num[1]+num[n]\gt \mathit{target}$, điều đó cho thấy cần làm nhỏ đi một trong hai phần tử, mà $\mathit{num}[1]$ không thể nhỏ hơn được nữa, nên giảm con trỏ đang trỏ tới $n$ đi một để làm số lớn hơn nhỏ lại.

Tương tự, nếu thấy $num[1]+num[n]\lt \mathit{target}$, cần làm lớn hơn một trong hai phần tử, nhưng $\mathit{num}[n]$ không thể lớn hơn được nữa, nên tăng con trỏ đang trỏ tới 1 lên một để làm số nhỏ hơn lớn lên.

Mở rộng sang trường hợp tổng quát, nếu lúc này hai con trỏ lần lượt trỏ vào $l,r$ và $l\lt r$, khi $num[l]+num[r]\gt \mathit{target}$ thì giảm $r$ đi một; khi $num[l]+num[r]\lt \mathit{target}$ thì tăng $l$ lên một. Như vậy $l$ liên tục đi sang phải, $r$ liên tục đi sang trái, và cuối cùng hai con trỏ sẽ cùng tiến gần một đáp án.

### Cài đặt

```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
  int r = numbers.size() - 1, l = 0;
  vector<int> ans;
  ans.clear();
  while (l < r) {
    if (numbers[l] + numbers[r] > target)
      r--;
    else if (numbers[l] + numbers[r] == target) {
      ans.push_back(l + 1), ans.push_back(r + 1);
      return ans;
    } else
      l++;
  }
  return ans;
}
```

Trong sắp xếp trộn, việc trộn hai mảng đã sắp xếp trong thời gian $O(n+m)$ cũng là một cách dùng hai con trỏ dựa trên điều kiện các mảng có thứ tự.

### Bài tập

[leetcode 15. Tổng ba số](https://leetcode-cn.com/problems/3sum/)

## Tìm chu trình trong danh sách liên kết đơn

### Quá trình

Có nhiều cách tìm chu trình trong danh sách liên kết đơn, nhưng phương pháp hai con trỏ nhanh chậm là một trong những cách gọn nhất. Sau đây là mô tả phương pháp này.

Ban đầu hai con trỏ đều trỏ vào đầu danh sách liên kết. Cho một con trỏ mỗi lần đi một bước, con trỏ còn lại mỗi lần đi hai bước. Nếu chúng gặp nhau thì chứng minh có chu trình, ngược lại thì không có chu trình. Độ phức tạp thời gian là $O(n)$.

Nếu có chu trình, làm sao tìm được điểm bắt đầu của chu trình?

Viết công thức để quan sát. Giả sử tại thời điểm gặp nhau, con trỏ chậm đã đi tổng cộng $k$ bước, trong đó đi $l$ bước trên chu trình (khi hai con trỏ nhanh chậm gặp nhau trên chu trình, con trỏ chậm chưa đi hết một vòng). Con trỏ nhanh đã đi $2k$ bước. Gọi độ dài chu trình là $C$, khi đó có

$$
\begin{align}
& \ 2 k=n \times C+l+(k-l) \\
& \ k=n \times C \\
\end{align}
$$

Tại lần gặp đầu tiên, $n$ lấy số nguyên dương nhỏ nhất là 1. Nói cách khác, $k=C$. Dựa vào đẳng thức này, sau khi hai con trỏ gặp nhau, chuyển một con trỏ về đầu danh sách, để cả hai cùng đi từng bước một; vị trí chúng gặp lại chính là điểm bắt đầu của chu trình.

### Cài đặt

```cpp
--8<-- "docs/misc/code/two-pointer/two-pointer_1.cpp:core"
```

Độ phức tạp thời gian là $O(n)$.
