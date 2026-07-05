## Tổng quan

Muốn sử dụng các kĩ thuật ngẫu nhiên hóa, điều kiện tiên quyết là có thể sinh số ngẫu nhiên thật nhanh. Bài viết này giới thiệu các phương pháp phổ biến để sinh số ngẫu nhiên.

### Số ngẫu nhiên và số giả ngẫu nhiên

Nói rằng một số đơn lẻ là "số ngẫu nhiên" không có nhiều ý nghĩa, vì vậy bên dưới ta mặc định thảo luận về "dãy số ngẫu nhiên"; ngay cả khi nhắc tới "số ngẫu nhiên", ý nói cũng là "một phần tử trong dãy số ngẫu nhiên".

Quá trình tính toán của các máy tính hiện nay đều có tính xác định. Vì thế, chỉ dựa vào thuật toán thì không thể sinh được một dãy số ngẫu nhiên thật sự **không thể dự đoán** và **không thể lặp lại**.

Tuy nhiên, trong phần lớn trường hợp, ta không cần tính ngẫu nhiên mạnh đến vậy, mà chỉ cần dãy được sinh ra có các đặc trưng thống kê của dãy số ngẫu nhiên, chẳng hạn phân bố đều, độc lập lẫn nhau, v.v. Những dãy như vậy được gọi là dãy **giả ngẫu nhiên**.

Ví dụ về ứng dụng của số ngẫu nhiên và số giả ngẫu nhiên trong đời sống thực tế và trong thuật toán:

-   Khi điều tra lấy mẫu, thường chỉ cần dùng số giả ngẫu nhiên, vì vốn dĩ ta chỉ quan tâm đến các đặc trưng thống kê.
-   Trong an ninh mạng, thường cần dùng số ngẫu nhiên mạnh hơn loại số giả ngẫu nhiên vừa nhắc tới, vì kẻ tấn công có thể khai thác tính dự đoán được.
-   Các thuật toán ngẫu nhiên dùng trong OI/ICPC về cơ bản chỉ cần số giả ngẫu nhiên. Lý do là các thuật toán này thường đưa xác suất vào phân tích độ phức tạp bằng cách đưa số ngẫu nhiên vào, từ đó giảm độ phức tạp. Về bản chất, chúng vẫn chỉ sử dụng các đặc trưng thống kê của số ngẫu nhiên.
-   Một số thuật toán ngẫu nhiên, ví dụ [thuật toán Moser](https://en.wikipedia.org/wiki/Algorithmic_Lov%C3%A1sz_local_lemma), sử dụng các tính chất liên quan đến entropy của số ngẫu nhiên, nên bắt buộc phải dùng số ngẫu nhiên thật sự.

## Cài đặt

### `rand`

Dùng để sinh số giả ngẫu nhiên. Nhược điểm là khá chậm; khi sử dụng cần `#include<cstdlib>`.

Gọi hàm `rand()` sẽ trả về một số nguyên không âm ngẫu nhiên trong `[0,RAND_MAX]`, trong đó `RAND_MAX` là một macro trong thư viện chuẩn. Trên hệ thống Linux, `RAND_MAX` bằng $2^{31}-1$. Có thể dùng phép lấy modulo để giới hạn kích thước của số được sinh ra.

Khi dùng `rand()` cần có một hạt giống ngẫu nhiên. Có thể dùng hàm `srand(seed)` để đổi hạt giống ngẫu nhiên thành `seed`; tất nhiên cũng có thể không khởi tạo.

Nếu cùng một chương trình chạy hai lần với cùng `seed`, trên cùng máy và cùng trình biên dịch, kết quả ngẫu nhiên nhận được sẽ giống nhau.

Một lựa chọn là dùng thời gian hệ thống hiện tại làm hạt giống ngẫu nhiên: `srand(time(nullptr))`.

??? warning "Cảnh báo"
    Trên hệ thống `Windows`, miền giá trị trả về của `rand()` là $\left[0,2^{15}\right)$, tức `RAND_MAX` bằng $2^{15}-1$. Khi cần sinh số không nhỏ hơn $2^{15}$, nên dùng `(rand() << 15 | rand())` để sinh số ngẫu nhiên lớn hơn.

Về tính ngẫu nhiên của `rand()` và `rand()%n`:

-   Chuẩn C/C++ không quy định bất kì yêu cầu nào về chất lượng của các số ngẫu nhiên do `rand()` sinh ra.
-   Cách hiện thực `rand()` mà trình biên dịch GCC sử dụng bảo đảm các tính chất cơ bản như phân bố đều, nhưng có những khuyết điểm rõ rệt như chu kì của các bit thấp ngắn. Ví dụ trên máy của tác giả, dãy do `rand()%2` sinh ra có chu kì khoảng $2\cdot 10^6$.
-   Ngay cả khi giả sử `rand()` là ngẫu nhiên đều, `rand()%n` cũng không bảo đảm tính đều, vì mỗi số trong `[0,n)` có thể xuất hiện với số lần khác nhau trong `0%n,1%n,...,RAND_MAX%n`.

### Bộ sinh số ngẫu nhiên định nghĩa sẵn

Thư viện định nghĩa một số thuật toán phổ biến đặc biệt. Nếu không nói rõ thêm, tất cả đều được định nghĩa trong tệp tiêu đề `<random>`.

??? warning "Cảnh báo"
    Các bộ sinh số ngẫu nhiên định nghĩa sẵn chỉ bắt đầu được dùng từ chuẩn C++11[^ref2].

#### mt19937

Đây là một lớp bộ sinh số ngẫu nhiên, có tác dụng tương tự `rand()`. Miền giá trị ngẫu nhiên giống miền giá trị của kiểu `unsigned int`.

Ưu điểm của nó là chất lượng số ngẫu nhiên cao, ví dụ chu kì trước khi lặp dài hơn, các mặt khác cũng ít nhất không kém `rand()`, đồng thời tốc độ nhanh hơn `rand()` rất nhiều. Khi sử dụng cần `#include<random>`.

`mt19937` dựa trên Mersenne Twister 32 bit, do Matsumoto và Nishimura thiết kế năm 1998[^ref3]. Khi dùng, chỉ cần dùng nó để định nghĩa một bộ sinh số ngẫu nhiên: `std::mt19937 myrand(seed)`. Có thể bỏ qua `seed`; khi đó hạt giống ngẫu nhiên mặc định sẽ được dùng.

`mt19937` nạp chồng `operator ()`; khi cần sinh số ngẫu nhiên, gọi `myrand()` là có thể trả về một số ngẫu nhiên.

Một bộ sinh tương tự khác là `mt19937_64`, dựa trên Mersenne Twister 64 bit, do Matsumoto và Nishimura thiết kế năm 2000. Cách dùng giống `mt19937`, nhưng miền số ngẫu nhiên được mở rộng đến miền giá trị của kiểu `unsigned long long`.

??? note "Ví dụ mã nguồn"
    ```cpp
    #include <ctime>
    #include <iostream>
    #include <random>
    
    using namespace std;
    
    int main() {
      mt19937 myrand(time(nullptr));
      cout << myrand() << endl;
      return 0;
    }
    ```

#### `minstd_rand0`

Thuật toán đồng dư tuyến tính được Lewis, Goodman và Miller phát hiện năm 1969, rồi được Park và Miller chọn làm "tiêu chuẩn tối thiểu" năm 1988.

Công thức tính như sau, trong đó $A,C,M$ là các hằng số định nghĩa sẵn.

$$
s_i\equiv s_{i-1}\times A+C\mod{M}
$$

`minstd_rand()` là "tiêu chuẩn tối thiểu" mới hơn, được Park, Miller và Stockmeyer khuyến nghị năm 1993.

Với `minstd_rand0()`, kiểu của $s$ là số nguyên không dấu 32 bit, $A$ lấy 16807, $C$ lấy 0, $M$ lấy 2147483647.

Với `minstd_rand()`, kiểu của $s$ là số nguyên không dấu 32 bit, $A$ lấy 48271, $C$ lấy 0, $M$ lấy 2147483647.

### `random_shuffle`

Dùng để xáo trộn ngẫu nhiên một dãy được chỉ định. Khi sử dụng cần `#include<algorithm>`.

Khi dùng, chỉ cần truyền con trỏ hoặc iterator đầu cuối của đoạn được chỉ định, theo dạng đóng trái mở phải: `std::random_shuffle(first, last)` hoặc `std::random_shuffle(first, last, myrand)`.

Bộ sinh số ngẫu nhiên dùng bên trong mặc định là `rand()`. Tất nhiên cũng có thể truyền vào bộ sinh số ngẫu nhiên tự định nghĩa.

Về tính ngẫu nhiên của `random_shuffle`:

-   Chuẩn C++ yêu cầu `random_shuffle` chọn ngẫu nhiên **đồng xác suất** trong tất cả các hoán vị có thể, nhưng trình biên dịch GCC[^note1] **không** thực hiện nghiêm ngặt điều này.
-   Một trong các nguyên nhân gây khiếm khuyết về tính ngẫu nhiên của `random_shuffle` trong GCC là nó dùng cách viết như `rand()%n`. Như đã nói ở trên, cách này không sinh ra số nguyên ngẫu nhiên đều.
-   Nguyên nhân thứ hai là miền giá trị của `rand()` hữu hạn. Nếu độ dài đoạn truyền vào vượt quá `RAND_MAX`, sẽ tồn tại một số hoán vị **không thể** được sinh ra[^ref1].

??? warning "Cảnh báo"
    `random_shuffle` đã bị loại khỏi khuyến nghị sử dụng từ chuẩn C++14 và bị gỡ bỏ trong chuẩn C++17.

### shuffle

Tác dụng giống `random_shuffle`. Khi sử dụng cần `#include<algorithm>`.

Điểm khác biệt là bắt buộc phải dùng bộ sinh số ngẫu nhiên tự định nghĩa: `std::shuffle(first, last, myrand)`.

Hiện thực `shuffle` của GCC[^note1] đáp ứng yêu cầu của chuẩn C++, tức là chọn ngẫu nhiên đồng xác suất trong tất cả các hoán vị có thể.

Dưới đây là một bộ sinh dữ liệu viết bằng `rand()` và `random_shuffle()`. Dữ liệu được sinh là dữ liệu nhỏ ngẫu nhiên cho bài ["ZJOI2012" Thảm họa](https://www.luogu.com.cn/problem/P2597).

```cpp
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

int a[100];

int main() {
  srand(time(nullptr));
  int n = rand() % 99 + 1;
  for (int i = 1; i <= n; i++) a[i] = i;
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::random_shuffle(a + 1, a + i);
    int cnt = rand() % i;
    for (int j = 1; j <= cnt; j++) std::cout << a[j] << ' ';
    std::cout << 0 << '\n';
  }
}
```

Dưới đây là cùng bộ sinh dữ liệu đó, viết bằng `mt19937` và `shuffle()`.

```cpp
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>

int a[100];

int main() {
  std::mt19937 rng(time(nullptr));
  int n = rng() % 99 + 1;
  for (int i = 1; i <= n; i++) a[i] = i;
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::shuffle(a + 1, a + i, rng);
    int cnt = rng() % i;
    for (int j = 1; j <= cnt; j++) std::cout << a[j] << ' ';
    std::cout << 0 << '\n';
  }
}
```

Dưới đây là một cách hiện thực để tạo hoán vị ngẫu nhiên của mười số nguyên dương đầu tiên.

```cpp
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(v.begin(), v.end(), g);

  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}
```

### Bộ sinh số nguyên ngẫu nhiên phân bố đều không xác định

`random_device` là một bộ sinh số ngẫu nhiên phân bố đều dựa trên phần cứng, có thể sinh số ngẫu nhiên với tốc độ cao **trước khi cạn nguồn entropy**. Lớp này được định nghĩa trong C++11 và cần tệp tiêu đề `random`. Vì hiệu năng giảm mạnh sau khi nguồn entropy cạn, nên khuyến nghị dùng phương pháp này để sinh hạt giống cho các bộ sinh số giả ngẫu nhiên như `mt19937`, thay vì dùng trực tiếp để sinh số.

`random_device` là một bộ sinh bit ngẫu nhiên đều không tất định, mặc dù nếu việc sinh số ngẫu nhiên không tất định không được hỗ trợ, hiện thực vẫn được phép dùng một bộ sinh số giả ngẫu nhiên để hiện thực nó. Hiện tại tác giả chưa nhận được báo cáo nào nói rằng máy chấm NOIP không hỗ trợ bộ sinh số ngẫu nhiên phân bố đều dựa trên phần cứng. Tuy vậy, để thận trọng, nên dùng thuật toán này để sinh hạt giống ngẫu nhiên.

Mã tham khảo như sau.

```cpp
#include <iostream>
#include <map>
#include <random>
#include <string>

int main() {
  std::random_device rd;
  std::map<int, int> hist;
  std::uniform_int_distribution<int> dist(0, 9);
  for (int n = 0; n < 20000; ++n) {
    ++hist[dist(rd)];  // Lưu ý: chỉ dùng để minh họa. Khi nguồn entropy
                       // cạn, nhiều hiện thực random_device sẽ giảm
                       // hiệu năng rất mạnh. Trong thực tế, random_device
                       // thường chỉ dùng để gieo hạt giống cho các
                       // bộ sinh giả ngẫu nhiên như mt19937.
  }
  for (auto p : hist) {
    std::cout << p.first << " : " << std::string(p.second / 100, '*') << '\n';
  }
}
```

Kết quả có thể như sau.

```plain
0 : ********************
1 : *******************
2 : ********************
3 : ********************
4 : ********************
5 : *******************
6 : ********************
7 : ********************
8 : *******************
9 : ********************
```

### Phân bố số ngẫu nhiên

Phần này giới thiệu việc yêu cầu số ngẫu nhiên được sinh ra xuất hiện theo một xác suất nhất định, chẳng hạn xác suất bằng nhau, [phân bố Bernoulli](https://en.wikipedia.org/wiki/Bernoulli_distribution), [phân bố nhị thức](https://en.wikipedia.org/wiki/Binomial_distribution), [phân bố hình học](https://en.wikipedia.org/wiki/Geometric_distribution), [phân bố chuẩn tắc, còn gọi là Gaussian](https://en.wikipedia.org/wiki/Normal_distribution).

Tên lớp cụ thể có thể xem trong danh sách [sinh số giả ngẫu nhiên: phân bố số ngẫu nhiên](https://en.cppreference.com/w/cpp/numeric/random#Random_number_distributions).

#### Cài đặt

Chương trình dưới đây mô phỏng một con xúc xắc sáu mặt.

```cpp
#include <iostream>
#include <random>

int main() {
  std::random_device rd;   // Dùng để lấy hạt giống cho engine ngẫu nhiên
  std::mt19937 gen(rd());  // Gieo hạt giống cho mersenne_twister_engine chuẩn
  std::uniform_int_distribution<> dis(1, 6);

  for (int n = 0; n < 10; ++n)
    // Dùng dis để biến unsigned int ngẫu nhiên do gen sinh ra thành int trong [1, 6]
    std::cout << dis(gen) << ' ';
  std::cout << '\n';
}
```

### Các cách hiện thực khác

Đôi khi ta cần tự hiện thực bộ sinh số ngẫu nhiên của mình. Dưới đây là một số phương pháp sinh số ngẫu nhiên thường dùng.

#### Bộ sinh số ngẫu nhiên đồng dư tuyến tính

Dùng công thức sau để sinh dãy số ngẫu nhiên $\{R_i\}$:

$$
R_{i+1} = (A \times R_i + B) \bmod P
$$

Trong đó $A,B,P$ đều là hằng số.

Phương pháp này dễ hiện thực, nhưng dãy ngẫu nhiên được sinh ra có chu kì khá ngắn. Chu kì lớn nhất là $P$, nhưng trong đa số trường hợp sẽ ngắn hơn $P$.

??? note "Hiện thực tham khảo"
    ```cpp
    #include <iostream>
    using namespace std;
    
    struct myrand {
      int A, B, P, x;
    
      myrand(int A, int B, int P) {
        this->A = A;
        this->B = B;
        this->P = P;
      }
    
      // Sinh số ngẫu nhiên tiếp theo trong dãy ngẫu nhiên
      int next() { return x = (A * x + B) % P; }
    };
    
    myrand rnd(3, 5, 97);  // Khởi tạo một bộ sinh số ngẫu nhiên
    
    int main() {
      int x = rnd.next();
      cout << x << endl;
      return 0;
    }
    ```

#### Bộ sinh số ngẫu nhiên Fibonacci trễ

Dùng công thức sau để sinh dãy số ngẫu nhiên $\{R_i\}$, trong đó $0 < j < k$:

$$
R_i \equiv R_{i-j} \star R_{i-k} \bmod P
$$

Ở đây $P$ thường lấy là một lũy thừa của $2$, phổ biến là $2^{32}$ hoặc $2^{64}$; $\star$ biểu thị toán tử nhị phân, có thể dùng phép cộng, phép trừ, phép nhân hoặc XOR.

So với bộ sinh số ngẫu nhiên đồng dư tuyến tính truyền thống, phương pháp này có chu kì dài hơn, nhưng tính ngẫu nhiên chịu ảnh hưởng khá lớn từ điều kiện ban đầu.

??? note "Hiện thực tham khảo"
    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;
    
    struct myrand {
      vector<unsigned> vec;
      int l, j, k, cur;
    
      myrand(int l, int j, int k) {
        this->l = l;
        this->j = j;
        this->k = k;
        cur = 0;
        for (int i = 0; i < l; i++) {
          vec.push_back(rand());  // Trước tiên sinh vài phần tử đầu bằng phương pháp khác
        }
      }
    
      unsigned next() {
        vec[cur] = vec[(cur - j + l) % l] * vec[(cur - k + l) % l];
        // Dùng kiểu unsigned ở đây để tự động lấy modulo 2^32
        return vec[cur++];
      }
    };
    
    myrand rnd(11, 4, 7);
    
    int main() {
      unsigned x = rnd.next();
      cout << x << endl;
      return 0;
    }
    ```

## Tài liệu tham khảo và chú thích

[^ref1]: [Don't use rand(): a guide to random number generators in C++](https://codeforces.com/blog/entry/61587)

[^ref2]: [Sinh số giả ngẫu nhiên - cppreference.com](https://en.cppreference.com/w/cpp/numeric/random#Predefined_random_number_generators)

[^ref3]: [Mersenne Twister algorithm](https://en.wikipedia.org/wiki/Mersenne_Twister)

[^note1]: Phiên bản là GCC 9.2.0
