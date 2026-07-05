Generator, tức trình sinh dữ liệu. Khi dữ liệu rất lớn và việc tạo thủ công trở nên quá vất vả, ta cần generator để tự động tạo dữ liệu.

## Ví dụ đơn giản

Sinh hai số nguyên trong khoảng $[1,n]$:

```cpp
// clang-format off

#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  cout << rnd.next(1, n) << " ";
  cout << rnd.next(1, n) << endl;
}
```

## Vì sao nên dùng Testlib?

Có người cho rằng viết generator không cần dùng Testlib, vì Testlib không có nhiều tác dụng ở đây. Thực ra đây là một suy nghĩ không đúng. Một generator tốt nên thỏa tính chất sau: **với cùng một đầu vào, nó cho cùng một đầu ra trong mọi môi trường**. Khi viết generator, gần như không thể tránh khỏi việc sinh giá trị ngẫu nhiên. Các công cụ ta thường dùng như `rand()` hoặc `mt19937/uniform_int_distribution` của C++11 có thể cho đầu ra khác nhau khi hệ điều hành khác nhau, trình biên dịch khác nhau, thời điểm chạy khác nhau, v.v. (với cách dùng rất phổ biến `srand(time(nullptr))`, điều này là hiển nhiên), và điều đó tạo ra tính bất định cho dữ liệu sinh ra.

Cần lưu ý rằng một khi đã dùng Testlib, bạn không được dùng các hàm sinh số ngẫu nhiên của thư viện chuẩn như `srand()` và `rand()` nữa, nếu không sẽ gặp lỗi khi biên dịch. Vì vậy, **hãy bảo đảm mọi hàm liên quan đến ngẫu nhiên đều dùng Testlib thay vì thư viện chuẩn**.

Các hàm sinh giá trị ngẫu nhiên trong Testlib bảo đảm rằng cùng một lời gọi sẽ cho cùng một giá trị, độc lập với bản thân generator và nền tảng chạy. Ngoài ra, Testlib giúp sinh giá trị ngẫu nhiên theo nhiều yêu cầu khác nhau rất thuận tiện. Ví dụ, `rnd.next("[a-z]{1,10}")` sẽ sinh một chuỗi có độ dài trong khoảng $[1,10]$, mỗi ký tự nằm từ `a` đến `z`.

## Testlib có thể làm gì?

Trước hết, hãy gọi `registerGen(argc, argv, 1)` để khởi tạo Testlib (trong đó `1` là phiên bản generator được dùng, thông thường giữ nguyên). Sau đó, ta có thể dùng đối tượng `rnd` để sinh giá trị ngẫu nhiên. Seed ngẫu nhiên được lấy từ giá trị băm của tham số dòng lệnh. Với một generator `g.cpp`, `g 100` (Unix-Like) và `g.exe "100"` (Windows) sẽ cho cùng đầu ra, còn `g 100 0` sẽ cho đầu ra khác.

Đối tượng `rnd` có kiểu `random_t`. Bạn có thể tạo một đối tượng sinh giá trị ngẫu nhiên mới, nhưng thông thường không cần làm vậy.

Đối tượng này có nhiều hàm thành viên hữu ích. Dưới đây là một số ví dụ:

| Lời gọi                                      | Ý nghĩa                                                                                                                                                                                                                                                 |
| -------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `rnd.next(4)`                                | Sinh ngẫu nhiên đều một số nguyên trong khoảng $[0,4)$                                                                                                                                                                                                  |
| `rnd.next(4, 100)`                           | Sinh ngẫu nhiên đều một số nguyên trong khoảng $[4,100]$                                                                                                                                                                                                |
| `rnd.next(10.0)`                             | Sinh ngẫu nhiên đều một số thực dấu phẩy động trong khoảng $[0,10.0)$                                                                                                                                                                                   |
| <code>rnd.next("one \| two \| three")</code> | Trả về ngẫu nhiên đều một trong ba chuỗi `one`, `two`, `three`                                                                                                                                                                                          |
| `rnd.wnext(4, t)`                            | `wnext()` là hàm sinh theo phân phối không đều (có kỳ vọng bị lệch)[^note1]. $t$ biểu thị số lần gọi `next()` và lấy giá trị lớn nhất sinh được. Ví dụ, `rnd.wnext(3, 1)` tương đương `max({rnd.next(3), rnd.next(3)})`; `rnd.wnext(4, 2)` tương đương `max({rnd.next(4), rnd.next(4), rnd.next(4)})`. Nếu $t<0$, hàm gọi $-t$ lần và lấy giá trị nhỏ nhất; nếu $t=0$, hàm tương đương `next()`. |
| `rnd.any(container)`                         | Trả về đều tham chiếu tới một phần tử trong container có iterator truy cập ngẫu nhiên, chẳng hạn `std::vector` và `std::string`                                                                                                                        |

Phụ lục: định nghĩa hình thức của `rnd.wnext(i,t)`:

$$
\operatorname{wnext}(i,t)=
\begin{cases}
\operatorname{next}(i) & t=0 \\
\max(\operatorname{next}(i),\operatorname{wnext}(i,t-1)) & t>0 \\
\min(\operatorname{next}(i),\operatorname{wnext}(i,t+1)) & t<0
\end{cases}
$$

Ngoài ra, đừng dùng `std::random_shuffle()`; hãy dùng `shuffle()` trong Testlib. Hàm này cũng nhận một cặp iterator. Nó dùng `rnd` để xáo trộn dãy, tức thỏa yêu cầu về "generator tốt" ở trên.

## Ví dụ: sinh một cây

Dưới đây là phần mã chính để sinh một cây. Mã này nhận hai tham số: số đỉnh và độ kéo giãn. Ví dụ, khi $n=10,t=1000$, có thể sinh ra một đường đi; khi $n=10,t=-1000$, có thể sinh ra một cây hình sao.

```cpp
#define forn(i, n) for (int i = 0; i < int(n); i++)

registerGen(argc, argv, 1);

int n = atoi(argv[1]);
int t = atoi(argv[2]);

vector<int> p(n);

/* Đặt cha cho các đỉnh 1..n-1 */
forn(i, n) if (i > 0) p[i] = rnd.wnext(i, t);

printf("%d\n", n);

/* Xáo trộn các đỉnh 1..n-1 */
vector<int> perm(n);
forn(i, n) perm[i] = i;
shuffle(perm.begin() + 1, perm.end());

/* Thêm cạnh theo thứ tự đỉnh đã xáo trộn */
vector<pair<int, int>> edges;
for (int i = 1; i < n; i++)
  if (rnd.next(2))
    edges.push_back(make_pair(perm[i], perm[p[i]]));
  else
    edges.push_back(make_pair(perm[p[i]], perm[i]));

/* Xáo trộn các cạnh */
shuffle(edges.begin(), edges.end());

for (int i = 0; i + 1 < n; i++)
  printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
```

## Sinh nhiều bộ dữ liệu một lần

Tương tự khi viết mà không dùng Testlib, bạn chỉ cần chuyển hướng luồng đầu ra trước mỗi lần xuất. Tuy nhiên, Testlib cung cấp một hàm hỗ trợ `startTest(test_index)`, giúp bạn chuyển hướng luồng đầu ra tới tệp `test_index`.

## Một số lưu ý

-   Tuân thủ nghiêm ngặt yêu cầu định dạng của đề, chẳng hạn dấu cách và xuống dòng; lưu ý cuối tệp nên có một ký tự xuống dòng.
-   Với dữ liệu lớn, ưu tiên `printf` thay vì `cout` để cải thiện hiệu năng. (Không khuyến nghị tắt đồng bộ luồng khi dùng Testlib.)
-   Không dùng UB (hành vi không xác định, undefined behavior). Ví dụ, trong ví dụ đầu bài, nếu viết đầu ra thành `cout << rnd.next(1, n) << " " << rnd.next(1, n) << endl;`, thứ tự gọi `rnd.next()` là không xác định.

## Tính năng mới: phân tích tham số dòng lệnh

Trước đây, ta thường dùng mã kiểu `int n = atoi(argv[3]);`, nhưng cách này không tốt vì các lý do sau:

-   Không an toàn khi tham số dòng lệnh thứ ba không tồn tại.
-   Tham số dòng lệnh thứ ba có thể không phải một số nguyên 32 bit hợp lệ.

Hiện nay, bạn có thể viết như sau: `int n = opt<int>(3)`. Đồng thời, bạn cũng có thể dùng `int64_t m = opt<int64_t>(1);`, `bool t = opt<bool>(2);`, `string s = opt(4);`, v.v.

Ngoài ra, Testlib cũng hỗ trợ tham số có tên. Nếu có nhiều tham số, cách viết `g 10 20000 a true` sẽ khó đọc hơn `g -n10 -m200000 -t=a -increment`.

Trong trường hợp này, hiện bạn có thể dùng đoạn mã sau trong generator:

```cpp
int n = opt<int>("n");
long long n = opt<long long>("m");
string t = opt("t");
bool increment = opt<bool>("increment");
```

Bạn có thể tự do kết hợp cách đọc tham số theo chỉ số và theo tên.

Các dạng viết tham số có tên được hỗ trợ gồm:

-   `--key=value` hoặc `-key=value`;
-   `--key value` hoặc `-key value`, nếu `value` không phải phần bắt đầu của một tham số mới (không bắt đầu bằng dấu gạch nối `-`, hoặc sau một/hai dấu gạch nối không phải là chữ cái);
-   `--k12345` hoặc `-k12345`, nếu key `k` là một chữ cái và phía sau là một chữ số;
-   `-prop` hoặc `--prop`, để bật thuộc tính bool.

Dưới đây là một số ví dụ:

```text
g1 -n1
g2 --len=4 --s=oops
g3 -inc -shuffle -n=5
g4 --length 5 --total 21 -ord
```

## Thêm ví dụ

Bạn có thể tìm thấy trên [GitHub](https://github.com/MikeMirzayanov/testlib/tree/master/generators).

**Bài viết này chủ yếu được dịch từ [Генераторы на testlib.h - Codeforces](https://codeforces.com/blog/entry/18291). Phần tính năng mới được dịch từ [Testlib: Opts—parsing command line options](https://codeforces.com/blog/entry/72702). Kho GitHub của `testlib.h` là [MikeMirzayanov/testlib](https://github.com/MikeMirzayanov/testlib).**

[^note1]: Thực ra, khi `i` là số thực dấu phẩy động, `rnd.wnext(i, t)` tuân theo [phân phối Beta](https://en.wikipedia.org/wiki/Beta_distribution) trên $[0,i)$: khi $t>0$, nó tuân theo $i\cdot \mathrm{Beta}(t+1,1)$; khi $t<0$, nó tuân theo $i\cdot \mathrm{Beta}(1,t+1)$.
