Trang này giới thiệu các cấu trúc dữ liệu liên quan đến hàng đợi và ứng dụng
của chúng.

![](./images/queue.svg)

<span id="dẫn-nhập"></span>
## Dẫn nhập

Hàng đợi (queue) là một dạng danh sách có tính chất "phần tử vào hàng đợi trước
sẽ ra khỏi hàng đợi trước". Vì tính chất này, hàng đợi thường được gọi là cấu
trúc vào trước ra trước (first in, first out), viết tắt là FIFO.

<span id="cài-đặt"></span>
## Cài đặt

<span id="mô-phỏng-hàng-đợi-bằng-mảng"></span>
### Mô phỏng hàng đợi bằng mảng

Thông thường, có thể dùng một mảng để mô phỏng hàng đợi, cùng hai biến đánh dấu
đầu và cuối hàng đợi.

```cpp
int q[SIZE], ql = 1, qr;
```

Các thao tác trên hàng đợi tương ứng với đoạn mã sau:

-   Chèn phần tử: `q[++qr] = x;`
-   Xóa phần tử: `ql++;`
-   Truy cập đầu hàng đợi: `q[ql]`
-   Truy cập cuối hàng đợi: `q[qr]`
-   Xóa rỗng hàng đợi: `ql = 1; qr = 0;`

??? example "[Luogu B3616【Mẫu】Hàng đợi](https://www.luogu.com.cn/problem/B3616) Cài đặt tham khảo bằng mô phỏng mảng"
    ```cpp
    --8<-- "docs/ds/code/queue/queue_1.cpp"
    ```

<span id="mô-phỏng-hàng-đợi-bằng-hai-ngăn-xếp"></span>
### Mô phỏng hàng đợi bằng hai ngăn xếp

Còn một cách ít phổ biến hơn là dùng hai [ngăn xếp](./stack.md) để mô phỏng một
hàng đợi.

Cách này dùng hai ngăn xếp $F$ và $S$ để mô phỏng một hàng đợi, trong đó $F$ là
ngăn xếp ở phía cuối hàng đợi, còn $S$ biểu diễn phía đầu hàng đợi. Cách cài đặt
này hỗ trợ thao tác đưa vào cuối hàng đợi (`push`) và lấy khỏi đầu hàng đợi
(`pop`):

-   `push`: chèn phần tử vào ngăn xếp $F$.
-   `pop`: nếu $S$ không rỗng thì lấy phần tử khỏi $S$; nếu không, chuyển ngược
    các phần tử của $F$ sang $S$ (thực chất là lấy rồi chèn từng phần tử, sau
    khi làm xong thứ tự đầu cuối bị đảo ngược), rồi lấy phần tử khỏi $S$.

Dễ chứng minh rằng mỗi phần tử chỉ được đưa vào, chuyển sang ngăn xếp kia, và
lấy ra một lần; do đó độ phức tạp khấu hao là $O(1)$.

??? example "[Luogu B3616【Mẫu】Hàng đợi](https://www.luogu.com.cn/problem/B3616) Cài đặt tham khảo bằng mô phỏng hai ngăn xếp"
    ```cpp
    --8<-- "docs/ds/code/queue/queue_2.cpp"
    ```

<span id="hàng-đợi-trong-c-stl"></span>
## Hàng đợi trong C++ STL

C++ cung cấp bộ điều hợp bộ chứa `std::queue` trong STL. Trước khi dùng, cần
nạp tệp tiêu đề `<queue>`.

???+ info "Định nghĩa `queue` trong STL"
    ```cpp
    // clang-format off
    template<
        class T,
        class Container = std::deque<T>
    > class queue;
    ```
    
    `T` là kiểu dữ liệu của các phần tử được lưu trong `queue`.
    
    `Container` là kiểu bộ chứa nền dùng để lưu phần tử. Bộ chứa nền này phải
    cung cấp các hàm sau với ngữ nghĩa thông thường:
    
    -   `back()`
    -   `front()`
    -   `push_back()`
    -   `pop_front()`
    
    Các bộ chứa STL `std::deque` và `std::list` thỏa mãn các yêu cầu này. Nếu
    không chỉ định, `std::deque` sẽ được dùng làm bộ chứa nền mặc định.

Bộ điều hợp `queue` trong STL cung cấp nhiều hàm thành viên; những hàm thường
dùng gồm:

-   Truy cập phần tử
    -   `q.front()` trả về phần tử đầu hàng đợi
    -   `q.back()` trả về phần tử cuối hàng đợi
-   Sửa đổi
    -   `q.push()` chèn phần tử vào cuối hàng đợi
    -   `q.pop()` xóa phần tử đầu hàng đợi
-   Dung lượng
    -   `q.empty()` kiểm tra hàng đợi có rỗng hay không
    -   `q.size()` trả về số phần tử trong hàng đợi

Ngoài ra, `queue` còn cung cấp một số toán tử. Toán tử thường dùng là toán tử
gán `=` để gán giá trị cho `queue`, ví dụ:

```cpp
std::queue<int> q1, q2;

// Chèn 1 vào cuối hàng đợi q1.
q1.push(1);

// Gán q1 cho q2.
q2 = q1;

// In phần tử đầu hàng đợi của q2.
std::cout << q2.front() << std::endl;
// Kết quả: 1
```

<span id="các-hàng-đợi-đặc-biệt"></span>
## Các hàng đợi đặc biệt

<span id="hàng-đợi-hai-đầu"></span>
### Hàng đợi hai đầu

Hàng đợi hai đầu là hàng đợi cho phép chèn hoặc xóa phần tử ở cả đầu và cuối
hàng đợi. Có thể xem nó như sự kết hợp giữa chức năng của ngăn xếp và hàng đợi.
Cụ thể, hàng đợi hai đầu hỗ trợ bốn thao tác:

-   Chèn một phần tử ở đầu hàng đợi
-   Chèn một phần tử ở cuối hàng đợi
-   Xóa một phần tử ở đầu hàng đợi
-   Xóa một phần tử ở cuối hàng đợi

Cách dùng mảng để mô phỏng hàng đợi hai đầu giống với hàng đợi thông thường.

Tương tự, cũng có thể dùng ý tưởng mô phỏng hàng đợi bằng hai ngăn xếp để duy
trì hàng đợi hai đầu. Tuy nhiên, khi một ngăn xếp rỗng, việc truy vấn luân phiên
đầu và cuối hàng đợi sẽ làm phân tích khấu hao mất hiệu lực. Khi cần chuyển phần
tử, chỉ chuyển một nửa số phần tử của ngăn xếp không rỗng sang ngăn xếp rỗng,
đồng thời giữ đúng tính chất của ngăn xếp phía đầu và phía cuối hàng đợi. Sau
cách xử lý này, các thao tác chèn và xóa vẫn có thời gian hằng số khấu hao.

??? note "Chứng minh ngắn gọn"
    Vì thao tác chèn chỉ đóng góp độ phức tạp hằng số, tiếp theo xét thao tác
    lấy phần tử ra. Giả sử ban đầu hàng đợi có $m$ phần tử; xét độ phức tạp
    thời gian để lấy toàn bộ phần tử ra (bất kể từ đầu hay từ cuối). Lần cân
    bằng đầu tiên có độ phức tạp $O(m)$. Sau đó, mỗi ngăn xếp có
    $\frac{m}{2}$ phần tử. Lúc này cần $O(\frac{m}{2})$ thời gian để làm rỗng
    một trong hai ngăn xếp, rồi lại kích hoạt một thao tác cân bằng có độ phức
    tạp $O(\frac{m}{2})$, cứ tiếp tục như vậy cho đến khi toàn bộ phần tử được
    lấy ra. Vì vậy, tổng độ phức tạp là
    
    $$
    T(m)=T\left(\frac{m}{2}\right)+O(m)
    $$
    
    Theo định lý Master, giải được $T(m)=O(m)$. Do đó tổng độ phức tạp của cách
    duy trì này vẫn là hằng số khấu hao.

??? example "[Luogu B3656【Mẫu】Hàng đợi hai đầu 1](https://www.luogu.com.cn/problem/B3656) Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/queue/queue_3.cpp"
    ```

<span id="hàng-đợi-hai-đầu-trong-c-stl"></span>
#### Hàng đợi hai đầu trong C++ STL

C++ cũng cung cấp bộ chứa `std::deque` trong STL. Trước khi dùng, cần nạp tệp
tiêu đề `<deque>`.

??? info "Định nghĩa `deque` trong STL"
    ```cpp
    // clang-format off
    template<
        class T,
        class Allocator = std::allocator<T>
    > class deque;
    ```
    
    `T` là kiểu dữ liệu của các phần tử được lưu trong `deque`.
    
    `Allocator` là bộ cấp phát; phần này không giải thích sâu, thông thường cứ
    giữ giá trị mặc định.

Container `deque` trong STL cung cấp nhiều hàm thành viên; những hàm thường dùng
gồm:

-   Truy cập phần tử
    -   `q.front()` trả về phần tử đầu hàng đợi
    -   `q.back()` trả về phần tử cuối hàng đợi
-   Sửa đổi
    -   `q.push_back()` chèn phần tử vào cuối hàng đợi
    -   `q.pop_back()` lấy phần tử cuối hàng đợi ra
    -   `q.push_front()` chèn phần tử vào đầu hàng đợi
    -   `q.pop_front()` xóa phần tử đầu hàng đợi
    -   `q.insert()` chèn phần tử trước vị trí chỉ định (truyền vào bộ lặp và
        phần tử)
    -   `q.erase()` xóa phần tử ở vị trí chỉ định (truyền vào bộ lặp)
-   Dung lượng
    -   `q.empty()` kiểm tra hàng đợi có rỗng hay không
    -   `q.size()` trả về số phần tử trong hàng đợi

Ngoài ra, `deque` còn cung cấp một số toán tử. Những toán tử thường dùng gồm:

-   Dùng toán tử gán `=` để gán giá trị cho `deque`, tương tự `queue`.
-   Dùng `[]` để truy cập phần tử, tương tự `vector`.

Tệp tiêu đề `<queue>` còn cung cấp hàng đợi ưu tiên `std::priority_queue`. Vì
cấu trúc này giống với [đống](./heap.md) hơn, trang này không giới thiệu sâu.

<span id="hàng-đợi-hai-đầu-trong-python"></span>
#### Hàng đợi hai đầu trong Python

Trong Python, hàng đợi hai đầu được cung cấp bởi `collections.deque`.

Ví dụ như sau:

???+ note "Cài đặt"
    ```python
    from collections import deque
    
    # Tạo một deque mới, khởi tạo nội dung là [1, 2, 3].
    queue = deque([1, 2, 3])
    
    # Chèn phần tử 4 vào cuối hàng đợi.
    queue.append(4)
    
    # Chèn phần tử 0 vào đầu hàng đợi.
    queue.appendleft(0)
    
    # Truy cập hàng đợi
    # >>> queue
    # deque([0, 1, 2, 3, 4])
    ```

<span id="hàng-đợi-vòng"></span>
### Hàng đợi vòng

Dùng mảng để mô phỏng hàng đợi có thể gây ra một vấn đề: theo thời gian, toàn bộ
hàng đợi dịch dần về phía cuối mảng. Khi đã đến cuối mảng, dù phía đầu mảng vẫn
còn vị trí trống, thao tác enqueue tiếp theo vẫn gây tràn. Hiện tượng mảng thực
tế vẫn còn vị trí trống nhưng lại báo tràn như vậy được gọi là "tràn giả".

Cách giải quyết tràn giả là tổ chức mảng lưu phần tử hàng đợi theo dạng vòng,
tức xem vị trí có chỉ số 0 của mảng là phần tử kế tiếp của vị trí cuối cùng.
(Với phần tử có chỉ số mảng là `x`, phần tử kế tiếp của nó là
`(x + 1) % SIZE`.) Như vậy sẽ có hàng đợi vòng.

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

1.  [std::queue - cppreference.com](https://en.cppreference.com/w/cpp/container/queue)
2.  [std::deque - cppreference.com](https://en.cppreference.com/w/cpp/container/deque)
