author: HeRaNO, konnyakuxzy, littlefrog

![./images/kuaizhuanglianbiao.png](./images/kuaizhuanglianbiao.png "./images/kuaizhuanglianbiao.png")

Danh sách liên kết chia khối đại khái có dạng như vậy.

Không khó thấy danh sách liên kết chia khối thực chất là một danh sách liên kết, trong đó mỗi nút trỏ tới một mảng.
Ta chia mảng ban đầu có độ dài $n$ thành $\sqrt{n}$ nút, mỗi nút tương ứng với một mảng có kích thước $\sqrt{n}$.
Vì vậy có thể định nghĩa cấu trúc như sau.
Trong đó `sqn` biểu thị `sqrt(n)`, tức $\sqrt{n}$; `pb` biểu thị `push_back`, tức thêm một phần tử vào `node` này.

???+ note "Cài đặt"
    ```cpp
    struct node {
      node* nxt;
      int size;
      char d[(sqn << 1) + 5];
    
      node() { size = 0, nxt = NULL, memset(d, 0, sizeof(d)); }
    
      void pb(char c) { d[size++] = c; }
    };
    ```

Danh sách liên kết chia khối tối thiểu nên hỗ trợ: tách, chèn và tìm kiếm.
Tách là gì? Tách nghĩa là chia một `node` thành hai `node` nhỏ hơn, để bảo đảm kích thước của mỗi `node` đều gần $\sqrt{n}$ (nếu không, cấu trúc có thể suy biến thành mảng thông thường). Khi kích thước của một `node` vượt quá $2\times \sqrt{n}$, ta thực hiện thao tác tách.

Thao tác tách được làm như sau: trước hết tạo một nút mới, rồi `copy` $\sqrt{n}$ giá trị cuối của nút cần tách sang nút mới; sau đó xóa $\sqrt{n}$ giá trị cuối khỏi nút cũ (`size--`), cuối cùng chèn nút mới vào ngay sau nút bị tách.

Mọi thao tác của danh sách liên kết chia khối đều có độ phức tạp cỡ $\sqrt{n}$.

Còn một điểm cần nói thêm.
Khi chèn (hoặc xóa) phần tử, $n$ thay đổi, nên $\sqrt{n}$ cũng thay đổi. Như vậy kích thước khối sẽ thay đổi; chẳng lẽ mỗi lần ta đều phải bảo trì lại kích thước khối?

Thực ra không cần. Chỉ cần đặt $\sqrt{n}$ thành một hằng số cố định. Chẳng hạn nếu phạm vi đề bài cho là $10^6$, ta đặt $\sqrt{n}$ thành hằng số kích thước $10^3$ và không cần thay đổi nó.

```cpp
list<vector<char>> orz_list;
```

<span id="libstdc-&#x4E2D;&#x7684;-rope"></span>

## `rope` trong libstdc++

<span id="&#x5BFC;&#x5165;"></span>

### Nhập thư viện

`rope` trong libstdc++ cũng có thể đóng vai trò của danh sách liên kết chia khối. Nó được cài đặt bằng cây cân bằng khả tồn, hỗ trợ truy cập ngẫu nhiên, chèn và xóa phần tử.

Do `rope` không thật sự được cài đặt bằng danh sách liên kết chia khối, độ phức tạp thời gian của nó không giống danh sách liên kết chia khối, mà tương đương độ phức tạp của cây cân bằng khả tồn (tức $O(\log n)$).

Có thể đưa vào chương trình như sau:

```cpp
#include <ext/rope>
using namespace __gnu_cxx;
```

???+ warning "Về các hàm thư viện bắt đầu bằng hai dấu gạch dưới"
    Trong OI, việc có được dùng các hàm thư viện bắt đầu bằng hai dấu gạch dưới hay không từng không rõ ràng. Năm 2021, CCF công bố [thuyết minh bổ sung về hạn chế sử dụng ngôn ngữ lập trình trong chuỗi hoạt động NOI](https://www.noi.cn/xw/2021-09-01/735729.shtml), trong đó nêu rằng được phép dùng các hàm thư viện hoặc macro bắt đầu bằng dấu gạch dưới, trừ các hàm thư viện và macro có thao tác bị cấm rõ ràng. Vì vậy hiện nay `rope` có thể dùng bình thường trong OI.

<span id="&#x57FA;&#x672C;&#x64CD;&#x4F5C;"></span>

### Thao tác cơ bản

|             Thao tác            |                    Tác dụng                    |
| :-----------------------------: | :--------------------------------------------: |
|          `rope<int> a`          | Khởi tạo `rope` (rất giống các container như `vector`) |
|         `a.push_back(x)`        |           Thêm phần tử `x` vào cuối `a`        |
|        `a.insert(pos, x)`       |       Thêm phần tử `x` vào vị trí `pos` của `a` |
|        `a.erase(pos, x)`        |    Xóa `x` phần tử bắt đầu từ vị trí `pos` của `a` |
|        `a.at(x)` hoặc `a[x]`    |           Truy cập phần tử thứ `x` của `a`     |
|    `a.length()` hoặc `a.size()` |              Lấy kích thước của `a`            |

<span id="&#x4F8B;&#x9898;"></span>

## Bài mẫu

[POJ2887 Big String](http://poj.org/problem?id=2887)

Lời giải:
Đây là một bài mẫu rất đơn giản. Mã như sau:

```cpp
--8<-- "docs/ds/code/block-list/block-list_1.cpp"
```
