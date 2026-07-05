author: MingqiHuang, Xeonacid, greyqz, i-Yirannn, ChenZ01

## `vector`

`std::vector` là cấu trúc mảng **có bộ nhớ liên tục**, **độ dài thay đổi được** (cũng có thể xem là một danh sách) do STL cung cấp. Nó hỗ trợ chèn và xóa với độ phức tạp tuyến tính, đồng thời hỗ trợ truy cập ngẫu nhiên với độ phức tạp hằng số.

<span id="vì-sao-nên-dùng-vector"></span>

### Vì sao nên dùng `vector`

Với OIer, yêu cầu về hiệu năng chương trình thường cao hơn rất nhiều so với độ ổn định ở mức dự án phần mềm. Do `vector` xử lý bộ nhớ động, trong một số trường hợp hiệu năng thời gian của nó kém hơn mảng tĩnh, và còn tệ hơn nếu máy chủ OJ không bật tối ưu hóa đầy đủ. Vì vậy khi chỉ cần lưu trữ dữ liệu thông thường, ta thường không chọn `vector`. Dưới đây là một số đặc tính nổi bật của `vector`; khi cần dùng đến các đặc tính này, `vector` có thể giúp ích rất nhiều.

<span id="vector-có-thể-cấp-phát-bộ-nhớ-động"></span>

#### `vector` có thể cấp phát bộ nhớ động

Nhiều khi ta không thể mở sẵn một vùng nhớ lớn như vậy (ví dụ: tiền xử lý tất cả ước của các số từ 1 đến n). Dù biết tổng lượng dữ liệu vẫn nằm trong giới hạn bộ nhớ, từng phần dữ liệu riêng lẻ vẫn có thể rất lớn; khi đó ta cần `vector` để khống chế mức sử dụng bộ nhớ trong phạm vi phù hợp. `vector` cũng hỗ trợ mở rộng dung lượng động, đặc tính này rất hữu ích khi bộ nhớ thật sự căng thẳng.

<span id="vector-nạp-chồng-toán-tử-so-sánh-và-toán-tử-gán"></span>

#### `vector` nạp chồng toán tử so sánh và toán tử gán

`vector` nạp chồng sáu toán tử so sánh, được cài đặt theo thứ tự từ điển. Điều này giúp ta dễ dàng kiểm tra hai container có bằng nhau hay không (độ phức tạp tuyến tính theo kích thước container). Chẳng hạn có thể dùng `vector<char>` để so sánh xâu (tất nhiên, dùng `std::string` vẫn nhanh và tiện hơn). Ngoài ra, `vector` cũng nạp chồng toán tử gán, giúp việc sao chép mảng thuận tiện hơn.

<span id="khởi-tạo-vector-thuận-tiện"></span>

#### Khởi tạo `vector` thuận tiện

Vì `vector` nạp chồng toán tử `=`, ta có thể thực hiện phép gán toàn bộ `vector` một cách thuận tiện. Ngoài ra, từ C++11, `vector` còn hỗ trợ [khởi tạo bằng danh sách](https://en.cppreference.com/w/cpp/language/list_initialization), ví dụ `vector<int> data {1, 2, 3};`.

<span id="cách-dùng-vector"></span>

### Cách dùng `vector`

Dưới đây giới thiệu các cách dùng thường gặp; nội dung chi tiết [xem tại tài liệu C++](https://en.cppreference.com/w/cpp/container/vector).

<span id="hàm-khởi-tạo-vector"></span>

#### Hàm khởi tạo

Ví dụ cách dùng như đoạn mã sau (giả sử bạn đã `using` các kiểu liên quan trong namespace `std`):

```cpp
// 1. Tạo vector rỗng; độ phức tạp hằng số
vector<int> v0;
// 1+. Câu lệnh này bảo đảm khi chèn 3 phần tử đầu tiên vào vector,
//     độ phức tạp thời gian vẫn là hằng số
v0.reserve(3);
// 2. Tạo vector có kích thước ban đầu là 3, giá trị mặc định của mỗi phần tử là 0; độ phức tạp tuyến tính
vector<int> v1(3);
// 3. Tạo vector có kích thước ban đầu là 3, giá trị mặc định của mỗi phần tử là 2; độ phức tạp tuyến tính
vector<int> v2(3, 2);
// 4. Tạo vector có kích thước ban đầu là 3, giá trị mặc định của mỗi phần tử là 1,
// và dùng bộ cấp phát bộ nhớ của v2; độ phức tạp tuyến tính
vector<int> v3(3, 1, v2.get_allocator());
// 5. Tạo vector v4 là bản sao của v2, các phần tử giống v2; độ phức tạp tuyến tính
vector<int> v4(v2);
// 6. Tạo vector v5 là bản sao một đoạn của v4, nội dung là {v4[1], v4[2]}; độ phức tạp tuyến tính
vector<int> v5(v4.begin() + 1, v4.begin() + 3);
// 7. Di chuyển v2 sang vector v6 mới tạo, không sao chép; độ phức tạp hằng số; cần C++11
vector<int> v6(std::move(v2));  // hoặc v6 = std::move(v2);
```

??? note "Mã kiểm thử"
    ```cpp
    // Dưới đây là mã kiểm thử; bạn nào quan tâm có thể tự biên dịch và chạy thử.
    cout << "v1 = ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "v2 = ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "v3 = ";
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "v4 = ";
    copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "v5 = ";
    copy(v5.begin(), v5.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "v6 = ";
    copy(v6.begin(), v6.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    ```

Dùng các cách trên là đủ để tạo một `vector` cho nhu cầu thông thường.

<span id="truy-cập-phần-tử-vector"></span>

#### Truy cập phần tử

`vector` cung cấp các cách sau để truy cập phần tử:

1.  `at()`

    `v.at(pos)` trả về tham chiếu đến phần tử có chỉ số `pos` trong container. Nếu vượt biên mảng, nó ném ngoại lệ kiểu `std::out_of_range`.

2.  `operator[]`

    `v[pos]` trả về tham chiếu đến phần tử có chỉ số `pos` trong container. Không kiểm tra vượt biên.

3.  `front()`

    `v.front()` trả về tham chiếu đến phần tử đầu tiên.

4.  `back()`

    `v.back()` trả về tham chiếu đến phần tử cuối cùng.

5.  `data()`

    `v.data()` trả về con trỏ đến phần tử đầu tiên trong vùng bộ nhớ liên tục mà `v` dùng để lưu dữ liệu nội bộ.

<span id="iterator-vector"></span>

#### Iterator (bộ lặp)

`vector` cung cấp các loại [iterator](./iterator.md) sau:

1.  `begin()/cbegin()`

    Trả về iterator trỏ đến phần tử đầu tiên, trong đó `*begin = front`.

2.  `end()/cend()`

    Trả về iterator trỏ đến vị trí lính canh ở cuối container; lưu ý vị trí này không có phần tử.

3.  `rbegin()/crbegin()`

    Trả về reverse iterator trỏ đến phần tử đầu tiên của dãy đảo ngược, có thể hiểu là phần tử cuối của container theo chiều xuôi.

4.  `rend()/crend()`

    Trả về iterator trỏ đến vị trí sau phần tử cuối của dãy đảo ngược, tương ứng với vị trí trước phần tử đầu của container; vị trí này không có phần tử.

Trong các iterator liệt kê trên, những hàm có ký tự `c` trả về iterator chỉ đọc; bạn không thể dùng iterator chỉ đọc để sửa giá trị phần tử trong `vector`. Nếu bản thân một `vector` là chỉ đọc, iterator thông thường và iterator chỉ đọc của nó hoàn toàn tương đương. Iterator chỉ đọc được hỗ trợ từ C++11.

<span id="độ-dài-và-dung-lượng-vector"></span>

#### Độ dài và dung lượng

`vector` có các hàm sau liên quan đến độ dài và dung lượng container. Lưu ý, độ dài (size) của `vector` là số phần tử hợp lệ, còn dung lượng (capacity) là độ dài vùng nhớ thực tế đã cấp phát; chi tiết xem phần về cách cài đặt ở bên dưới.

**Liên quan đến độ dài**:

-   `empty()` trả về một giá trị `bool`, tức `v.begin() == v.end()`; `true` nghĩa là rỗng, `false` nghĩa là không rỗng.

-   `size()` trả về độ dài container (số phần tử), tức `std::distance(v.begin(), v.end())`.

-   `resize(n)` thay đổi độ dài của `vector` thành `n`. Nếu `n` lớn hơn độ dài hiện tại, các phần tử sẽ được bổ sung; nếu tham số có cung cấp giá trị cần bổ sung thì dùng giá trị đó, nếu không thì dùng giá trị mặc định. Nếu `n` nhỏ hơn độ dài hiện tại, giữ lại `n` phần tử đầu và xóa các phần tử phía sau.

-   `max_size()` trả về độ dài tối đa có thể có của container.

**Liên quan đến dung lượng**:

-   `reserve()` yêu cầu `vector` dự trữ một lượng bộ nhớ nhất định, tránh cấp phát và sao chép bộ nhớ không cần thiết.

-   `capacity()` trả về dung lượng container, tức số phần tử mà `vector` hiện đã cấp phát đủ chỗ.

-   `shrink_to_fit()` làm cho dung lượng của `vector` bằng độ dài, loại bỏ phần dung lượng chưa dùng đến.

<span id="thêm-xóa-và-sửa-phần-tử-vector"></span>

### Thêm, xóa và sửa phần tử

-   `clear()` xóa tất cả phần tử.
-   `insert()` hỗ trợ chèn một hoặc nhiều phần tử tại một vị trí iterator. **Độ phức tạp tuyến tính theo khoảng cách từ `pos` đến cuối, không phải hằng số**.
-   `erase()` xóa một phần tử tại iterator hoặc một đoạn phần tử, trả về iterator sau phần tử cuối cùng bị xóa. Độ phức tạp giống `insert`.
-   `push_back()` chèn một phần tử vào cuối; độ phức tạp khấu hao là **hằng số**, trường hợp xấu nhất là tuyến tính.
-   `pop_back()` xóa phần tử cuối, độ phức tạp hằng số.
-   `swap()` trao đổi với một container khác; thao tác này có **độ phức tạp hằng số**, không phải tuyến tính.

<span id="chi-tiết-cài-đặt-của-vector"></span>

### Chi tiết cài đặt của `vector`

Tầng dưới của `vector` thực ra vẫn là mảng có độ dài cố định. Lý do nó mở rộng động được là vì có thêm thao tác để tránh tràn số lượng. Trước hết cần nói rõ: số phần tử (độ dài) $n$ trong `vector` và số phần tử tối đa mà vùng nhớ đã cấp phát có thể chứa (dung lượng) $N$ không nhất thiết giống nhau; `vector` lưu riêng hai đại lượng này. Khi thêm phần tử vào `vector`, nếu thấy $n>N$, container sẽ cấp phát một mảng kích thước $2N$, sao chép dữ liệu cũ từ vị trí ban đầu sang mảng mới, rồi giải phóng vùng nhớ cũ. Dù độ phức tạp tiệm cận của thao tác này là $O(n)$, có thể chứng minh độ phức tạp khấu hao của nó là $O(1)$. Xóa phần tử ở cuối và truy cập phần tử vẫn tốn chi phí $O(1)$.
Vì vậy, chỉ cần ước lượng kích thước `vector` hợp lý và tận dụng `resize()` cùng `reserve()`, hiệu năng của `vector` sẽ không thua mảng có độ dài cố định quá nhiều.

## `vector<bool>`

Thư viện chuẩn cung cấp riêng một chuyên biệt hóa `vector` cho `bool`: mỗi "`bool`" chỉ chiếm 1 bit và vẫn hỗ trợ tăng kích thước động. Tuy nhiên kiểu trả về của `operator[]` không phải `bool&` mà là `vector<bool>::reference`. Vì vậy cần thận trọng khi dùng `vector<bool>`; có thể cân nhắc thay bằng `deque<bool>` hoặc `vector<char>`. Nếu bạn cần tiết kiệm bộ nhớ, hãy dùng trực tiếp [`bitset`](./bitset.md).

## `array`(C++11)

`std::array` là cấu trúc mảng **có bộ nhớ liên tục**, **độ dài cố định** do STL cung cấp. Bản chất của nó là lớp bọc trực tiếp quanh mảng nguyên thủy.

<span id="vì-sao-nên-dùng-array"></span>

### Vì sao nên dùng `array`

`array` thực chất là lớp bọc mảng của STL. So với `vector`, nó hy sinh đặc tính mở rộng động, đổi lại hiệu năng gần như tương đương mảng nguyên thủy (với điều kiện bật tối ưu hóa đầy đủ). Vì vậy nếu có thể dùng đặc tính C++11, gần như mọi nơi dùng được mảng nguyên thủy đều có thể thay mảng độ dài cố định bằng `array`, còn mảng cấp phát động có thể thay bằng `vector`.

<span id="hàm-thành-viên-array"></span>

### Hàm thành viên

<span id="hàm-thành-viên-được-định-nghĩa-ngầm-định-array"></span>

#### Hàm thành viên được định nghĩa ngầm định

| Hàm          | Tác dụng                                                        |
| ------------ | --------------------------------------------------------------- |
| `operator=` | Ghi đè từng phần tử từ một `array` khác lên phần tử tương ứng của `array` |

<span id="truy-cập-phần-tử-array"></span>

#### Truy cập phần tử

| Hàm          | Tác dụng                                             |
| ------------ | ---------------------------------------------------- |
| `at`         | Truy cập phần tử chỉ định, đồng thời kiểm tra vượt biên |
| `operator[]` | Truy cập phần tử chỉ định, **không** kiểm tra vượt biên |
| `front`      | Truy cập phần tử đầu tiên                            |
| `back`       | Truy cập phần tử cuối cùng                           |
| `data`       | Trả về con trỏ đến phần tử đầu tiên của mảng trong bộ nhớ |

`at` sẽ ném `std::out_of_range` nếu gặp trường hợp `pos >= size()`.

<span id="dung-lượng-array"></span>

#### Dung lượng

| Hàm        | Tác dụng                         |
| ---------- | -------------------------------- |
| `empty`    | Kiểm tra container có rỗng không |
| `size`     | Trả về số phần tử đang chứa      |
| `max_size` | Trả về số phần tử tối đa có thể chứa |

Vì mỗi `array` đều là container kích thước cố định, giá trị `size()` trả về bằng giá trị `max_size()` trả về.

<span id="thao-tác-array"></span>

### Thao tác

| Hàm    | Tác dụng                         |
| ------ | -------------------------------- |
| `fill` | Điền container bằng giá trị chỉ định |
| `swap` | Trao đổi nội dung                |

**Lưu ý, trao đổi hai `array` có độ phức tạp $\Theta(\text{size})$, không phải $O(1)$ như các container STL thông thường.**

<span id="hàm-không-phải-thành-viên-array"></span>

### Hàm không phải thành viên

| Hàm             | Tác dụng                              |
| --------------- | ------------------------------------- |
| `operator==` và tương tự | So sánh các giá trị trong `array` theo thứ tự từ điển |
| `std::get`     | Truy cập một phần tử của `array`       |
| `std::swap`    | Thuật toán `std::swap` đã được chuyên biệt hóa |

Dưới đây là một ví dụ sử dụng `array`:

```cpp
// 1. Tạo array rỗng, độ dài là 3; độ phức tạp hằng số
std::array<int, 3> v0;
// 2. Tạo array bằng các hằng số chỉ định; độ phức tạp hằng số
std::array<int, 3> v1{1, 2, 3};

v0.fill(1);  // điền mảng

// Truy cập mảng
for (int i = 0; i != arr.size(); ++i) cout << arr[i] << " ";
```

## `deque`

`std::deque` là cấu trúc [hàng đợi hai đầu](../../ds/queue.md#hàng-đợi-hai-đầu) do STL cung cấp. Nó hỗ trợ chèn và xóa với độ phức tạp tuyến tính, đồng thời hỗ trợ truy cập ngẫu nhiên với độ phức tạp hằng số.

<span id="cách-dùng-deque"></span>

### Cách dùng `deque`

Dưới đây giới thiệu các cách dùng thường gặp; nội dung chi tiết [xem tại tài liệu C++](https://en.cppreference.com/w/cpp/container/deque). Các hàm iterator của `deque` giống `vector`, nên không trình bày chi tiết.

<span id="hàm-khởi-tạo-deque"></span>

#### Hàm khởi tạo

Xem đoạn mã sau (giả sử bạn đã `using` các kiểu liên quan trong namespace `std`):

```cpp
// 1. Định nghĩa hàng đợi hai đầu rỗng kiểu int tên v0
deque<int> v0;
// 2. Định nghĩa hàng đợi hai đầu kiểu int tên v1, đặt kích thước ban đầu là 10; độ phức tạp tuyến tính
deque<int> v1(10);
// 3. Định nghĩa hàng đợi hai đầu kiểu int tên v2, khởi tạo bằng 10 phần tử 1; độ phức tạp tuyến tính
deque<int> v2(10, 1);
// 4. Sao chép hàng đợi hai đầu v1 đã có; độ phức tạp tuyến tính
deque<int> v3(v1);
// 5. Tạo deque v4 là bản sao một đoạn của v2, nội dung từ v2[0] đến v2[2]; độ phức tạp tuyến tính
deque<int> v4(v2.begin(), v2.begin() + 3);
// 6. Di chuyển v2 sang deque v5 mới tạo, không sao chép; độ phức tạp hằng số; cần C++11
deque<int> v5(std::move(v2));
```

<span id="truy-cập-phần-tử-deque"></span>

#### Truy cập phần tử

Giống `vector`, nhưng không thể truy cập bộ nhớ tầng dưới. Tốc độ truy cập phần tử hiệu quả của nó được giải thích trong phần chi tiết cài đặt.

-   `at()` trả về tham chiếu đến phần tử tại vị trí chỉ định trong container, có kiểm tra vượt biên, **độ phức tạp hằng số**.
-   `operator[]` trả về tham chiếu đến phần tử tại vị trí chỉ định trong container. Không kiểm tra vượt biên, **độ phức tạp hằng số**.
-   `front()` trả về tham chiếu đến phần tử đầu tiên.
-   `back()` trả về tham chiếu đến phần tử cuối cùng.

<span id="iterator-deque"></span>

#### Iterator (bộ lặp)

Giống `vector`.

<span id="độ-dài-deque"></span>

#### Độ dài

Giống `vector`, nhưng không có hàm `reserve()` và `capacity()`. (Vẫn có hàm `shrink_to_fit()`.)

<span id="thêm-xóa-và-sửa-phần-tử-deque"></span>

#### Thêm, xóa và sửa phần tử

Giống `vector`, và có thêm các hàm chèn phần tử vào đầu hàng đợi.

-   `clear()` xóa tất cả phần tử.
-   `insert()` hỗ trợ chèn một hoặc nhiều phần tử tại một vị trí iterator. **Độ phức tạp tuyến tính theo khoảng cách nhỏ hơn giữa `pos` và hai đầu**.
-   `erase()` xóa một phần tử tại iterator hoặc một đoạn phần tử, trả về iterator sau phần tử cuối cùng bị xóa. Độ phức tạp giống `insert`.
-   `push_front()` chèn một phần tử vào đầu, **độ phức tạp hằng số**.
-   `pop_front()` xóa phần tử đầu, **độ phức tạp hằng số**.
-   `push_back()` chèn một phần tử vào cuối, **độ phức tạp hằng số**.
-   `pop_back()` xóa phần tử cuối, **độ phức tạp hằng số**.
-   `swap()` trao đổi với một container khác; thao tác này có **độ phức tạp hằng số**, không phải tuyến tính.

<span id="chi-tiết-cài-đặt-của-deque"></span>

### Chi tiết cài đặt của `deque`

Tầng dưới của `deque` thường được cài đặt bằng nhiều buffer không liên tục, nhưng bộ nhớ bên trong mỗi buffer là liên tục. Mỗi buffer còn ghi lại con trỏ đầu và con trỏ cuối để đánh dấu đoạn dữ liệu hợp lệ. Khi một buffer đầy, `deque` sẽ cấp phát buffer mới ở phía trước hoặc phía sau để lưu thêm dữ liệu. Có thể tham khảo giải thích chi tiết hơn tại bài [nguyên lý cài đặt `deque` trong "STL source code analysis"](https://www.cnblogs.com/q1076452761/p/16903229.html).

## `list`

`std::list` là cấu trúc [danh sách liên kết đôi](../../ds/linked-list.md) do STL cung cấp. Có thể truy cập phần tử bằng cách duyệt tuyến tính, còn thao tác chèn và xóa có độ phức tạp hằng số.

<span id="cách-dùng-list"></span>

### Cách dùng `list`

Cách dùng `list` về cơ bản giống `deque`, nhưng độ phức tạp của thao tác thêm xóa và truy cập khác nhau. Nội dung chi tiết [xem tại tài liệu C++](https://en.cppreference.com/w/cpp/container/list). Các hàm liên quan đến iterator, độ dài, thêm xóa và sửa phần tử của `list` giống `deque`, nên không trình bày chi tiết.

<span id="truy-cập-phần-tử-list"></span>

#### Truy cập phần tử

Vì `list` được cài đặt bằng danh sách liên kết, nó không cung cấp giao diện truy cập ngẫu nhiên. Nếu cần truy cập phần tử ở giữa, cần dùng iterator.

-   `front()` trả về tham chiếu đến phần tử đầu tiên.
-   `back()` trả về tham chiếu đến phần tử cuối cùng.

<span id="thao-tác-list"></span>

#### Thao tác

Kiểu `list` còn cung cấp một số hàm thuật toán STL được cài đặt riêng theo đặc tính của nó. Vì các thuật toán này cần [random-access iterator](./iterator.md), `list` cung cấp các phiên bản đặc biệt để tiện sử dụng. Các thuật toán này gồm `splice()`, `remove()`, `sort()`, `unique()`, `merge()` và các hàm tương tự.

## `forward_list` (C++11)

`std::forward_list` là cấu trúc [danh sách liên kết đơn](../../ds/linked-list.md) do STL cung cấp; so với `std::list`, nó giảm chi phí bộ nhớ.

<span id="cách-dùng-forward-list"></span>

### Cách dùng `forward_list`

Cách dùng `forward_list` gần như giống `list`, nhưng iterator chỉ là một chiều, nên ở đây không trình bày chi tiết. Nội dung chi tiết [xem tại tài liệu C++](https://en.cppreference.com/w/cpp/container/forward_list).
