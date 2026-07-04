## `set`

`set` là container kết hợp, chứa một tập đã sắp xếp các đối tượng có kiểu khóa. Các thao tác tìm kiếm, xóa và chèn có độ phức tạp logarit. Bên trong, `set` thường được cài đặt bằng [cây đỏ đen](../../ds/rbtree.md). Đặc tính của [cây nhị phân cân bằng](../../ds/bst.md) khiến `set` rất phù hợp với những bài toán cần đồng thời hỗ trợ tìm kiếm, chèn và xóa.

Tương tự tập hợp trong toán học, `set` không có hai phần tử có giá trị bằng nhau. Nếu cần một tập cho phép các phần tử trùng nhau, hãy dùng `multiset`. Cách sử dụng `multiset` về cơ bản giống với `set`.

<span id="thao-tác-chèn-và-xóa-set"></span>
### Thao tác chèn và xóa

-   `insert(x)` chèn phần tử x vào `set` nếu trong container chưa có phần tử tương đương.
-   `erase(x)` xóa **tất cả** phần tử có giá trị bằng x, trả về số phần tử đã xóa.
-   `erase(pos)` xóa phần tử tại iterator pos; iterator này phải hợp lệ.
-   `erase(first,last)` xóa tất cả phần tử có iterator nằm trong khoảng $[first,last)$.
-   `clear()` xóa rỗng `set`.

???+ note "Giá trị trả về của hàm insert"
    Kiểu trả về của hàm insert là `pair<iterator, bool>`, trong đó iterator trỏ đến phần tử vừa được chèn (hoặc trỏ đến phần tử đã tồn tại sẵn trong container và bằng với giá trị cần chèn), còn bool cho biết việc chèn có thành công hay không. Do các phần tử trong `set` có tính duy nhất, nếu trong `set` đã có phần tử bằng giá trị đó thì chèn thất bại và trả về false; ngược lại chèn thành công và trả về true. `insert` trong `map` cũng tương tự.

<span id="iterator-set"></span>
### Iterator

`set` cung cấp các loại iterator sau:

1.  `begin()/cbegin()`   
    Trả về iterator trỏ đến phần tử đầu tiên, trong đó `*begin = front`.
2.  `end()/cend()`   
    Trả về iterator trỏ đến vị trí đánh dấu cuối dãy; lưu ý vị trí này không có phần tử.
3.  `rbegin()/crbegin()`   
    Trả về reverse iterator trỏ đến phần tử đầu tiên của dãy duyệt ngược, có thể hiểu là phần tử cuối của container theo chiều xuôi.
4.  `rend()/crend()`   
    Trả về iterator trỏ đến vị trí sau phần tử cuối của dãy duyệt ngược, tương ứng với vị trí trước phần tử đầu của container; vị trí này không có phần tử.

Trong các iterator liệt kê ở trên, những hàm có chữ cái `c` trả về iterator chỉ đọc; bạn không thể dùng iterator chỉ đọc để sửa giá trị phần tử trong `set`. Nếu bản thân một `set` là chỉ đọc, iterator thông thường và iterator chỉ đọc của nó hoàn toàn tương đương. Iterator chỉ đọc được hỗ trợ từ C++11.

<span id="thao-tác-tìm-kiếm-set"></span>
### Thao tác tìm kiếm

-   `count(x)` trả về số phần tử trong `set` có khóa bằng x.
-   `find(x)` trả về iterator của phần tử có khóa bằng x nếu phần tử đó tồn tại trong `set`; nếu không, trả về `end()`.
-   `lower_bound(x)` trả về iterator trỏ đến phần tử đầu tiên không nhỏ hơn khóa đã cho. Nếu không có phần tử như vậy, trả về `end()`.
-   `upper_bound(x)` trả về iterator trỏ đến phần tử đầu tiên lớn hơn khóa đã cho. Nếu không có phần tử như vậy, trả về `end()`.
-   `empty()` trả về container có rỗng hay không.
-   `size()` trả về số phần tử trong container.

???+ warning "Độ phức tạp thời gian của `lower_bound` và `upper_bound`"
    `lower_bound` và `upper_bound` sẵn có của `set` có độ phức tạp thời gian $O(\log n)$.
    
    Nhưng nếu dùng các hàm `lower_bound` và `upper_bound` trong thư viện `algorithm` để truy vấn các phần tử trong `set`, độ phức tạp thời gian sẽ là $O(n)$.

???+ warning "Độ phức tạp thời gian của `nth_element`"
    `set` không cung cấp `nth_element` sẵn có. Nếu dùng `nth_element` trong thư viện `algorithm` để tìm phần tử lớn thứ $k$, độ phức tạp thời gian là $O(n)$.
    
    Nếu cần hiện thực chức năng tìm phần tử lớn thứ $k$ trong $O(\log n)$ như cây nhị phân cân bằng, bạn cần tự viết cây nhị phân cân bằng hoặc cây phân đoạn theo giá trị, hoặc dùng cây nhị phân cân bằng trong thư viện pb\_ds.

<span id="ví-dụ-sử-dụng-set"></span>
### Ví dụ sử dụng

<span id="dùng-set-trong-tham-lam"></span>
#### Dùng `set` trong tham lam

Trong thuật toán tham lam, ta thường cần thao tác kiểu **tìm và xóa phần tử nhỏ nhất lớn hơn hoặc bằng một giá trị nào đó**. Thao tác này có thể được thực hiện dễ dàng bằng `set`.

```cpp
// Các phần tử hiện đang khả dụng
set<int> available;
// Giá trị cần lớn hơn hoặc bằng
int x;

// Tìm phần tử nhỏ nhất lớn hơn hoặc bằng x
set<int>::iterator it = available.lower_bound(x);
if (it == available.end()) {
  // Không tồn tại phần tử như vậy, xử lý tương ứng...
} else {
  // Đã tìm thấy phần tử như vậy, xóa nó khỏi tập phần tử khả dụng
  available.erase(it);
  // Xử lý tương ứng...
}
```

## `map`

`map` là container cặp khóa-giá trị có thứ tự, trong đó khóa của các phần tử là duy nhất. Các thao tác tìm kiếm, xóa và chèn có độ phức tạp logarit. `map` thường được cài đặt bằng [cây đỏ đen](../../ds/rbtree.md).

Hãy xét tình huống sau: cần lưu một số cặp khóa-giá trị, chẳng hạn điểm tương ứng với tên học sinh: `Tom 0`, `Bob 100`, `Alan 100`. Tuy nhiên, chỉ số mảng chỉ có thể là số nguyên không âm, nên không thể dùng tên làm chỉ số để lưu trữ. Lúc này, cách đơn giản nhất là dùng `map` trong STL.

`map` nạp chồng `operator[]`, cho phép dùng bất kỳ kiểu nào đã định nghĩa `operator <` làm chỉ số (trong `map` gọi là `key`, tức là khóa hay chỉ mục):

```cpp
map<Key, T> yourMap;
```

Trong đó `Key` là kiểu của khóa, `T` là kiểu của giá trị. Dưới đây là một ví dụ sử dụng `map`:

```cpp
map<string, int> mp;
```

Trong `map` không tồn tại hai phần tử có cùng khóa; `multimap` cho phép nhiều phần tử có cùng một khóa. Cách sử dụng `multimap` về cơ bản giống với `map`.

??? warning "Cảnh báo"
    Chính vì `multimap` cho phép nhiều phần tử có cùng một khóa, `multimap` không cung cấp cách truy cập giá trị tương ứng chỉ bằng khóa.

<span id="thao-tác-chèn-và-xóa-map"></span>
### Thao tác chèn và xóa

-   Có thể truy cập trực tiếp bằng chỉ số để truy vấn hoặc chèn. Ví dụ: `mp["Alan"]=100`.
-   Có thể chèn phần tử bằng cách chèn vào `map` một giá trị có kiểu `pair<Key, T>`, ví dụ `mp.insert(pair<string,int>("Alan",100));`.
-   Hàm `erase(key)` xóa **tất cả** phần tử có khóa bằng `key`. Giá trị trả về là số phần tử đã xóa.
-   `erase(pos)`: xóa phần tử tại iterator pos; iterator này phải hợp lệ.
-   `erase(first,last)`: xóa tất cả phần tử có iterator nằm trong khoảng $[first,last)$.
-   Hàm `clear()` xóa rỗng toàn bộ container.

???+ note "Lưu ý khi truy cập bằng chỉ số"
    Khi dùng chỉ số để truy cập một phần tử trong `map`, nếu trong `map` không tồn tại phần tử có khóa tương ứng, một phần tử mới sẽ tự động được chèn vào `map`, và giá trị của nó được đặt thành giá trị mặc định (với số nguyên là 0; với kiểu có hàm tạo mặc định, hàm tạo mặc định sẽ được gọi để khởi tạo).
    
    Nếu thao tác truy cập bằng chỉ số diễn ra quá thường xuyên, container có thể sinh ra nhiều phần tử vô nghĩa, làm giảm hiệu quả của `map`. Vì vậy, thông thường nên dùng hàm `find()` để tìm phần tử có khóa cụ thể.

<span id="thao-tác-truy-vấn-map"></span>
### Thao tác truy vấn

-   `count(x)`: trả về số phần tử trong container có khóa bằng x. Độ phức tạp là $O(\log(size)+ans)$ (logarit theo kích thước container, cộng với số phần tử khớp).
-   `find(x)`: nếu trong container tồn tại phần tử có khóa bằng x, trả về iterator của phần tử đó; nếu không, trả về `end()`.
-   `lower_bound(x)`: trả về iterator trỏ đến phần tử đầu tiên không nhỏ hơn khóa đã cho.
-   `upper_bound(x)`: trả về iterator trỏ đến phần tử đầu tiên lớn hơn khóa đã cho. Nếu tất cả phần tử trong container đều nhỏ hơn hoặc bằng khóa đã cho, trả về `end()`.
-   `empty()`: trả về container có rỗng hay không.
-   `size()`: trả về số phần tử trong container.

<span id="ví-dụ-sử-dụng-map"></span>
### Ví dụ sử dụng

<span id="dùng-map-để-lưu-trạng-thái-phức-tạp"></span>
#### Dùng `map` để lưu trạng thái phức tạp

Trong tìm kiếm, đôi khi ta cần lưu một số trạng thái khá phức tạp (như tọa độ, giá trị không thể rời rạc hóa, chuỗi, v.v.) và đáp án liên quan đến chúng (như số bước tối thiểu để đến trạng thái đó). `map` có thể được dùng để hiện thực chức năng này. Khóa trong `map` là trạng thái, còn giá trị là đáp án liên quan. Ví dụ dưới đây minh họa cách dùng `map` để lưu trạng thái biểu diễn bằng `string`.

```cpp
// Lưu trạng thái và đáp án tương ứng
map<string, int> record;

// Trạng thái mới tìm được và đáp án tương ứng
string status;
int ans;
// Kiểm tra trạng thái tương ứng đã xuất hiện chưa
map<string, int>::iterator it = record.find(status);
if (it == record.end()) {
  // Chưa tìm kiếm qua trạng thái này, thêm nó vào bản ghi trạng thái
  record[status] = ans;
  // Xử lý tương ứng...
} else {
  // Đã tìm kiếm qua trạng thái này, xử lý tương ứng...
}
```

<span id="duyệt-container"></span>
## Duyệt container

Có thể dùng iterator để duyệt tất cả phần tử của container kết hợp.

```cpp
set<int> s;
using si = set<int>::iterator;
for (si it = s.begin(); it != s.end(); it++) cout << *it << endl;
```

Cần lưu ý rằng khi giải tham chiếu iterator của `map`, kết quả nhận được là một cặp khóa-giá trị có kiểu `pair<Key, T>`.

Trong C++11, vòng lặp range-for giúp mã ngắn gọn hơn nhiều:

```cpp
set<int> s;
for (auto x : s) cout << x << endl;
```

Với mọi container kết hợp, thời gian duyệt container bằng iterator đều là $O(n)$.

<span id="tùy-biến-cách-so-sánh"></span>
## Tùy biến cách so sánh

Theo mặc định, hàm so sánh của `set` là `<` (nếu là kiểu không dựng sẵn, cần [nạp chồng toán tử `<`](../op-overload.md#toán-tử-so-sánh)). Tuy nhiên, trong một số tình huống đặc biệt, ta muốn tùy biến cách so sánh bên trong `set`.

Lúc này có thể giải quyết bằng cách truyền vào một comparator tùy biến.

Cụ thể, ta cần định nghĩa một lớp và [nạp chồng toán tử `()`](../op-overload.md#toán-tử-gọi-hàm) trong lớp đó.

Ví dụ, nếu muốn duy trì một `set` lưu các số nguyên sao cho giá trị lớn hơn đứng trước, có thể hiện thực như sau:

```cpp
struct cmp {
  bool operator()(int a, int b) const { return a > b; }
};

set<int, cmp> s;
```

Với các container kết hợp khác, có thể tùy biến cách so sánh theo cách tương tự, ở đây không trình bày thêm.
