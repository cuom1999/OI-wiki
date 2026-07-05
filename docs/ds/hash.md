<span id="mở-đầu"></span>

## Mở đầu

![](images/hashtable.svg)

Bảng băm còn được gọi là bảng phân tán, là một cấu trúc dữ liệu lưu trữ dữ liệu theo dạng khóa-giá trị. Lưu trữ theo dạng khóa-giá trị nghĩa là mỗi khóa `key` bất kỳ sẽ tương ứng duy nhất với một vị trí nào đó trong bộ nhớ. Chỉ cần nhập khóa cần tìm, ta có thể nhanh chóng tìm được `value` tương ứng. Có thể xem bảng băm như một loại mảng nâng cao, trong đó chỉ số của mảng có thể là số nguyên rất lớn, số thực, chuỗi, thậm chí là cấu trúc.

<span id="hàm-băm"></span>

## Hàm băm

Để ánh xạ khóa vào một vị trí trong bộ nhớ, ta cần tính chỉ số cho khóa, tức là tính xem dữ liệu này nên được đặt ở đâu. Hàm dùng khóa để tính chỉ số như vậy được gọi là hàm băm. Ví dụ, nếu khóa là số căn cước của một người, hàm băm có thể lấy bốn chữ số cuối của số đó, tất nhiên cũng có thể lấy bốn chữ số đầu. Trong đời sống, cách gọi "bốn số cuối của số điện thoại" cũng là một dạng hàm băm. Trong ứng dụng thực tế, khóa có thể phức tạp hơn, chẳng hạn số thực, chuỗi, cấu trúc, v.v.; khi đó cần thiết kế hàm băm phù hợp với từng trường hợp cụ thể. Hàm băm nên dễ tính, đồng thời cố gắng làm cho các chỉ số tính được phân bố đều.

Sau khi có thể tính chỉ số cho `key`, ta sẽ biết giá trị `value` tương ứng với mỗi khóa nên được đặt ở đâu. Giả sử dùng mảng `a` để lưu dữ liệu và hàm băm là `f`, thì cặp khóa-giá trị `(key, value)` nên được đặt tại `a[f(key)]`. Dù khóa có kiểu gì và phạm vi lớn đến đâu, `f(key)` vẫn là một số nguyên trong phạm vi chấp nhận được, có thể dùng làm chỉ số mảng.

Trong OI, trường hợp thường gặp nhất có lẽ là khóa là số nguyên. Khi phạm vi khóa nhỏ, có thể trực tiếp dùng khóa làm chỉ số mảng; nhưng khi phạm vi khóa lớn, chẳng hạn dùng số nguyên trong phạm vi $10^9$ làm khóa, ta cần dùng bảng băm. Thông thường, ta lấy khóa modulo một số nguyên tố lớn để làm chỉ số, tức là dùng $f(x)=x \bmod M$ làm hàm băm.

Một trường hợp khá thường gặp khác là `key` là chuỗi. Vì không thể dùng chuỗi làm chỉ số mảng, đồng thời chuyển chuỗi thành số để lưu trữ cũng giúp tránh phải so sánh chuỗi nhiều lần, nên trong OI ta thường không trực tiếp dùng chuỗi làm khóa, mà trước tiên tính giá trị băm của chuỗi, rồi dùng giá trị băm đó làm khóa để chèn vào bảng băm. Với giá trị băm của chuỗi, ta thường dùng tư tưởng hệ cơ số, xem chuỗi như một số ở hệ cơ số $127$. Khi đó, với mỗi chuỗi $s$ có độ dài $n$, ta có:

$x = s_0 \cdot 127^0 + s_1 \cdot 127^1 + s_2 \cdot 127^2 + \dots + s_n \cdot 127^n$

Ta có thể lấy $x$ thu được modulo $2^{64}$ (tức giá trị lớn nhất của `unsigned long long`). Khi đó hiện tượng tràn tự nhiên của `unsigned long long` tương đương với phép lấy modulo, giúp thao tác thuận tiện hơn.

Phương pháp này tuy đơn giản nhưng không hoàn hảo. Có thể xây dựng dữ liệu khiến phương pháp này xảy ra va chạm (tức là hai chuỗi có cùng kết quả sau khi lấy $x$ modulo $2^{64}$).
Ta có thể dùng băm kép: chọn hai số nguyên tố lớn $a,b$. Chỉ khi giá trị băm của hai chuỗi sau khi lấy modulo $a$ và modulo $b$ đều bằng nhau, ta mới xem hai chuỗi đó là bằng nhau. Cách này có thể giảm mạnh xác suất va chạm băm.

<span id="va-chạm"></span>

## Va chạm

Nếu với mọi khóa, chỉ số do hàm băm tính ra đều khác nhau, ta chỉ cần dựa vào chỉ số để đặt `(key, value)` vào vị trí tương ứng. Nhưng trên thực tế, thường sẽ có hai khóa khác nhau cho ra cùng một chỉ số sau khi qua hàm băm. Khi đó cần một số phương pháp để xử lý va chạm. Trong OI, phương pháp thường dùng nhất là phương pháp nối chuỗi.

<span id="phương-pháp-nối-chuỗi"></span>

### Phương pháp nối chuỗi

Phương pháp nối chuỗi còn được gọi là băm mở (open hashing).

Phương pháp nối chuỗi tạo một danh sách liên kết tại mỗi vị trí lưu dữ liệu. Nếu nhiều khóa được ánh xạ tới cùng một vị trí, chỉ cần đưa tất cả chúng vào danh sách liên kết ở vị trí đó. Khi truy vấn, cần duyệt toàn bộ danh sách liên kết tại vị trí tương ứng và so sánh khóa của từng phần tử với khóa đang truy vấn. Nếu phạm vi chỉ số là $1\ldots M$ và kích thước bảng băm là $N$, thì một lần chèn/truy vấn cần kỳ vọng $O(\frac{N}{M})$ phép so sánh.

<span id="cài-đặt"></span>

#### Cài đặt

=== "C++"
    ```cpp
    constexpr int SIZE = 1000000;
    constexpr int M = 999997;
    
    struct HashTable {
      struct Node {
        int next, value, key;
      } data[SIZE];
    
      int head[M], size;
    
      int f(int key) { return (key % M + M) % M; }
    
      int get(int key) {
        for (int p = head[f(key)]; p; p = data[p].next)
          if (data[p].key == key) return data[p].value;
        return -1;
      }
    
      int modify(int key, int value) {
        for (int p = head[f(key)]; p; p = data[p].next)
          if (data[p].key == key) return data[p].value = value;
      }
    
      int add(int key, int value) {
        if (get(key) != -1) return -1;
        data[++size] = Node{head[f(key)], value, key};
        head[f(key)] = size;
        return value;
      }
    };
    ```

=== "Python"
    ```python
    M = 999997
    SIZE = 1000000
    
    
    class Node:
        def __init__(self, next=None, value=None, key=None):
            self.next = next
            self.value = value
            self.key = key
    
    
    data = [Node() for _ in range(SIZE)]
    head = [0] * M
    size = 0
    
    
    def f(key):
        return key % M
    
    
    def get(key):
        p = head[f(key)]
        while p:
            if data[p].key == key:
                return data[p].value
            p = data[p].next
        return -1
    
    
    def modify(key, value):
        p = head[f(key)]
        while p:
            if data[p].key == key:
                data[p].value = value
                return data[p].value
            p = data[p].next
    
    
    def add(key, value):
        if get(key) != -1:
            return -1
        size = size + 1
        data[size] = Node(head[f(key)], value, key)
        head[f(key)] = size
        return value
    ```

Sau đây là một mẫu đã được đóng gói, có thể dùng giống như `map` và cũng khá ngắn.

```cpp
struct hash_map {  // Mẫu bảng băm

  struct data {
    long long u;
    int v, nex;
  };  // Cấu trúc sao tiến

  data e[SZ << 1];  // SZ là const int biểu thị kích thước
  int h[SZ], cnt;

  int hash(long long u) { return (u % SZ + SZ) % SZ; }

  // Ở đây dùng (u % SZ + SZ) % SZ thay vì u % SZ vì
  // phép toán % trong C++ không thể chuyển số âm thành số dương

  int& operator[](long long u) {
    int hu = hash(u);  // Lấy con trỏ đầu
    for (int i = h[hu]; i; i = e[i].nex)
      if (e[i].u == u) return e[i].v;
    return e[++cnt] = data{u, -1, h[hu]}, h[hu] = cnt, e[cnt].v;
  }

  hash_map() {
    cnt = 0;
    memset(h, 0, sizeof(h));
  }
};
```

Ở đây, hàm `hash` được thiết kế theo kiểu của khóa và trả về một con trỏ đầu của danh sách liên kết để phục vụ truy vấn. Trong mẫu này, ta viết một bảng băm có kiểu cặp khóa-giá trị là `(long long, int)`, và khi truy vấn một khóa không tồn tại thì trả về `-1`. Hàm `hash_map()` dùng để khởi tạo khi định nghĩa.

<span id="băm-đóng"></span>

### Băm đóng

Băm đóng lưu trực tiếp mọi bản ghi trong bảng băm; nếu xảy ra va chạm thì tiếp tục thăm dò theo một cách nào đó.

Ví dụ với thăm dò tuyến tính: nếu xảy ra va chạm tại `d`, thì lần lượt kiểm tra `d + 1`, `d + 2`, ...

<span id="cài-đặt_1"></span>

#### Cài đặt

```cpp
constexpr int N = 360007;  // N là số phần tử tối đa có thể lưu trữ

class Hash {
 private:
  int keys[N];
  int values[N];

 public:
  Hash() { memset(values, 0, sizeof(values)); }

  int& operator[](int n) {
    // Trả về một tham chiếu trỏ tới Hash[Key] tương ứng
    // Giá trị 0 được xem là rỗng; khi dùng cần sửa thành giá trị khác 0
    int idx = (n % N + N) % N, cnt = 1;
    while (keys[idx] != n && values[idx] != 0) {
      idx = (idx + cnt * cnt) % N;
      cnt += 1;
    }
    keys[idx] = n;
    return values[idx];
  }
};
```

<span id="ví-dụ"></span>

## Ví dụ

[JLOI2011 Các số không lặp lại](https://www.luogu.com.cn/problem/P4305)
