author: Xeonacid, ksyx, Early0v0

<span id="ngăn-xếp"></span>

## Ngăn xếp

STL [ngăn xếp](../../ds/stack.md) (`std::stack`) là một bộ chuyển đổi bộ chứa
theo nguyên tắc vào sau ra trước (LIFO, Last In, First Out). Nó chỉ cho phép xem
hoặc xóa phần tử được thêm vào sau cùng (phần tử đỉnh ngăn xếp), không hỗ trợ
truy cập ngẫu nhiên. Để giữ đúng thứ tự LIFO, `std::stack` cũng không cung cấp
bộ lặp.

<span id="tệp-tiêu-đề-ngăn-xếp"></span>

### Tệp tiêu đề

```cpp
#include <stack>
```

<span id="định-nghĩa-ngăn-xếp"></span>

### Định nghĩa

```cpp
std::stack<TypeName> s;             // dùng deque làm bộ chứa cơ sở mặc định, kiểu dữ liệu là TypeName
std::stack<TypeName, Container> s;  // dùng Container làm bộ chứa cơ sở
std::stack<TypeName> s2(s1);        // sao chép s1 để xây dựng s2
```

<span id="hàm-thành-viên-ngăn-xếp"></span>

### Hàm thành viên

**Tất cả các hàm sau đều có độ phức tạp hằng số**

-   `top()` truy cập phần tử ở đỉnh ngăn xếp (nếu ngăn xếp rỗng thì thao tác này
    gây lỗi)
-   `push(x)` chèn phần tử `x` vào ngăn xếp
-   `pop()` xóa phần tử đỉnh ngăn xếp
-   `size()` trả về số lượng phần tử trong bộ chứa
-   `empty()` trả về `true` nếu bộ chứa rỗng, ngược lại trả về `false`

<span id="ví-dụ-đơn-giản-ngăn-xếp"></span>

### Ví dụ đơn giản

```cpp
std::stack<int> s1;
s1.push(2);
s1.push(1);
std::stack<int> s2(s1);
s1.pop();
std::cout << s1.size() << " " << s2.size() << std::endl;  // 1 2
std::cout << s1.top() << " " << s2.top() << std::endl;    // 2 1
s1.pop();
std::cout << s1.empty() << " " << s2.empty() << std::endl;  // 1 0
```

<span id="hàng-đợi"></span>

## Hàng đợi

STL [hàng đợi](../../ds/queue.md) (`std::queue`) là một bộ chuyển đổi bộ chứa
theo nguyên tắc vào trước ra trước (FIFO, First In, First Out). Nó chỉ cho phép
xem hoặc xóa phần tử được thêm vào đầu tiên (phần tử đầu hàng đợi), không hỗ trợ
truy cập ngẫu nhiên. Để giữ đúng thứ tự FIFO, `std::queue` cũng không cung cấp
bộ lặp.

<span id="tệp-tiêu-đề-hàng-đợi"></span>

### Tệp tiêu đề

```cpp
#include <queue>
```

<span id="định-nghĩa-hàng-đợi"></span>

### Định nghĩa

```cpp
std::queue<TypeName> q;             // dùng deque làm bộ chứa cơ sở mặc định, kiểu dữ liệu là TypeName
std::queue<TypeName, Container> q;  // dùng Container làm bộ chứa cơ sở

std::queue<TypeName> q2(q1);  // sao chép q1 để xây dựng q2
```

<span id="hàm-thành-viên-hàng-đợi"></span>

### Hàm thành viên

**Tất cả các hàm sau đều có độ phức tạp hằng số**

-   `front()` truy cập phần tử đầu hàng đợi (nếu hàng đợi rỗng thì thao tác này
    gây lỗi)
-   `push(x)` chèn phần tử `x` vào hàng đợi
-   `pop()` xóa phần tử đầu hàng đợi
-   `size()` trả về số lượng phần tử trong bộ chứa
-   `empty()` trả về `true` nếu bộ chứa rỗng, ngược lại trả về `false`

<span id="ví-dụ-đơn-giản-hàng-đợi"></span>

### Ví dụ đơn giản

```cpp
std::queue<int> q1;
q1.push(2);
q1.push(1);
std::queue<int> q2(q1);
q1.pop();
std::cout << q1.size() << " " << q2.size() << std::endl;    // 1 2
std::cout << q1.front() << " " << q2.front() << std::endl;  // 1 2
q1.pop();
std::cout << q1.empty() << " " << q2.empty() << std::endl;  // 1 0
```

<span id="hàng-đợi-ưu-tiên"></span>

## Hàng đợi ưu tiên

Hàng đợi ưu tiên `std::priority_queue` là một dạng [heap](../../ds/heap.md),
thường là [heap nhị phân](../../ds/binary-heap.md).

<span id="tệp-tiêu-đề-hàng-đợi-ưu-tiên"></span>

### Tệp tiêu đề

```cpp
#include <queue>
```

<span id="định-nghĩa-hàng-đợi-ưu-tiên"></span>

### Định nghĩa

```cpp
std::priority_queue<TypeName> q;             // kiểu dữ liệu là TypeName
std::priority_queue<TypeName, Container> q;  // dùng Container làm bộ chứa cơ sở
std::priority_queue<TypeName, Container, Compare> q;
// dùng Container làm bộ chứa cơ sở, dùng Compare làm kiểu so sánh

// Mặc định dùng vector làm bộ chứa cơ sở
// Kiểu so sánh là less<TypeName> (khi đó top() trả về giá trị lớn nhất)
// Nếu muốn top() trả về giá trị nhỏ nhất, có thể đặt kiểu so sánh là greater<TypeName>
// Lưu ý: muốn truyền Compare thì vẫn phải ghi rõ Container

// Từ C++11 trở đi, nếu dùng biểu thức lambda để tự định nghĩa Compare
// thì cần truyền nó vào dưới dạng tham số của hàm khởi tạo, ví dụ:
auto cmp = [](const std::pair<int, int> &l, const std::pair<int, int> &r) {
  return l.second < r.second;
};
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    decltype(cmp)>
    pq(cmp);
```

<span id="hàm-thành-viên-hàng-đợi-ưu-tiên"></span>

### Hàm thành viên

**Tất cả các hàm sau đều có độ phức tạp hằng số**

-   `top()` truy cập phần tử ở đỉnh heap (lúc này hàng đợi ưu tiên không được rỗng)
-   `empty()` trả về `true` nếu bộ chứa rỗng, ngược lại trả về `false`
-   `size()` trả về số lượng phần tử trong bộ chứa

**Tất cả các hàm sau đều có độ phức tạp logarit**

-   `push(x)` chèn phần tử rồi điều chỉnh lại heap trong bộ chứa cơ sở
-   `pop()` xóa phần tử ở đỉnh heap (lúc này hàng đợi ưu tiên không được rỗng)

<span id="ví-dụ-đơn-giản-hàng-đợi-ưu-tiên"></span>

### Ví dụ đơn giản

```cpp
std::priority_queue<int> q1;
std::priority_queue<int, std::vector<int>> q2;
// Sau C++11 có thể bỏ khoảng trắng
std::priority_queue<int, std::deque<int>, std::greater<int>> q3;
// q3 là heap nhỏ nhất
for (int i = 1; i <= 5; i++) q1.push(i);
// Các phần tử trong q1: [1, 2, 3, 4, 5]
std::cout << q1.top() << std::endl;
// Kết quả xuất ra: 5
q1.pop();
// Các phần tử trong q1: [1, 2, 3, 4]
std::cout << q1.size() << std::endl;
// Kết quả xuất ra: 4
for (int i = 1; i <= 5; i++) q3.push(i);
// Các phần tử trong q3: [1, 2, 3, 4, 5]
std::cout << q3.top() << std::endl;
// Kết quả xuất ra: 1
```
