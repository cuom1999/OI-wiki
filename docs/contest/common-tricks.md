author: H-J-Granger, Ir1d, ChungZH, Marcythm, StudyingFather, billchenchina, Suyun514, Psycho7, greyqz, Xeonacid, partychicken

Trang này chủ yếu liệt kê một số mẹo nhỏ trong thi đấu.

## Tận dụng tính cục bộ

Tính cục bộ là xu hướng chương trình tham chiếu tới các mục dữ liệu nằm gần những mục dữ liệu vừa được tham chiếu gần đây, hoặc tham chiếu lại chính các mục dữ liệu vừa được tham chiếu gần đây. Tính cục bộ được chia thành tính cục bộ theo thời gian và tính cục bộ theo không gian.

Có thể xem cụ thể hơn ở các phần [mở vòng lặp (loop unroll)](../lang/optimizations.md#mở-vòng-lặp-loop-unroll), [tối ưu hóa bố cục mã](../lang/optimizations.md#tối-ưu-hóa-bố-cục-mã-code-layout-optimizations), v.v.

## Định nghĩa macro cho vòng lặp

Đoạn mã sau có thể dùng macro để rút gọn:

```cpp
for (int i = 0; i < N; i++) {
  // Nội dung vòng lặp được lược bỏ
}

// Dùng macro để rút gọn
#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)

// Khi viết vòng lặp như vậy, có thể rút gọn thành `f(i, 0, N)`. Ví dụ:
// a là một STL container
f(i, 0, a.size()) { ... }
```

Ngoài ra, có thể khuyến nghị một macro khá hữu ích:

```cpp
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
```

## Tận dụng namespace

Dùng namespace có thể giúp chương trình dễ đọc hơn và thuận tiện cho việc gỡ lỗi.

??? note "Ví dụ: NOI 2018 Chiến binh diệt rồng"
    ```cpp
    // Mã lấy 40 điểm thành phần của NOI 2018 Chiến binh diệt rồng
    #include <algorithm>
    #include <cmath>
    #include <cstring>
    #include <iostream>
    using namespace std;
    long long n, m, a[100005], p[100005], aw[100005], atk[100005];

    namespace one_game {
    // Thực ra trong namespace cũng có thể khai báo biến
    void solve() {
      for (int y = 0;; y++)
        if ((a[1] + p[1] * y) % atk[1] == 0) {
          cout << (a[1] + p[1] * y) / atk[1] << endl;
          return;
        }
    }
    }  // namespace one_game

    namespace p_1 {
    void solve() {
      if (atk[1] == 1) {  // giải 1-2
        sort(a + 1, a + n + 1);
        cout << a[n] << endl;
        return;
      } else if (m == 1) {  // giải 3-4
        long long k = atk[1], kt = ceil(a[1] * 1.0 / k);
        for (int i = 2; i <= n; i++)
          k = aw[i - 1], kt = max(kt, (long long)ceil(a[i] * 1.0 / k));
        cout << k << endl;
      }
    }
    }  // namespace p_1

    int main() {
      int T;
      cin >> T;
      while (T--) {
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));
        memset(aw, 0, sizeof(aw));
        memset(atk, 0, sizeof(atk));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> aw[i];
        for (int i = 1; i <= m; i++) cin >> atk[i];
        if (n == 1 && m == 1)
          one_game::solve();  // giải 8-13
        else if (p[1] == 1)
          p_1::solve();  // giải 1-4 hoặc 14-15
        else
          cout << -1 << endl;
      }
      return 0;
    }
    ```

## Dùng macro để gỡ lỗi

Khi kiểm thử cục bộ, lập trình viên thường cần thêm một số câu lệnh gỡ lỗi. Nhưng khi cần nộp lên OJ, để đầu ra của các câu lệnh gỡ lỗi không ảnh hưởng đến việc hệ thống phán định kết quả chương trình, ta phải xóa hết chúng, khá tốn thời gian. Trong tình huống này, có thể tiết kiệm thời gian bằng cách định nghĩa macro. Khung chương trình đại khái như sau:

```cpp
#define DEBUG
#ifdef DEBUG
// Làm gì đó khi DEBUG được định nghĩa
#endif
// or
#ifndef DEBUG
// Làm gì đó khi DEBUG không được định nghĩa
#endif
```

`#ifdef` sẽ kiểm tra trong chương trình có định nghĩa định danh tương ứng bằng `#define` hay không; nếu có định nghĩa thì thực thi các câu lệnh phía sau. Còn `#ifndef` sẽ thực thi các câu lệnh phía sau khi không có định nghĩa định danh tương ứng.

Như vậy, chỉ cần viết mã gỡ lỗi trong `#ifdef DEBUG` và viết mã thật để nộp trong `#ifndef DEBUG`, ta có thể kiểm thử cục bộ thuận tiện. Khi nộp chương trình, chỉ cần chú thích dòng `#define DEBUG` là được. Cũng có thể không định nghĩa định danh trong chương trình, mà dùng tùy chọn biên dịch `-DDEBUG` để định nghĩa định danh `DEBUG` lúc biên dịch. Cách này giúp không cần sửa chương trình khi nộp.

Nhiều OJ đều bật tùy chọn biên dịch `-DONLINE_JUDGE`; tận dụng tốt đặc tính này có thể tiết kiệm khá nhiều thời gian.

## Đối chiếu chương trình

Đối chiếu chương trình (stress test) là một phương pháp kiểm nghiệm hoặc gỡ lỗi bằng cách so sánh đầu ra của hai chương trình để kiểm tra tính đúng đắn của chương trình. Có thể so sánh đầu ra của chương trình của mình với đầu ra của chương trình khác, từ đó phán đoán chương trình của mình có đúng hay không.

Quá trình đối chiếu cần thực hiện nhiều lần, vì vậy cần dùng phương pháp xử lý hàng loạt để tự động hóa.

Cụ thể, đối chiếu chương trình cần một [bộ sinh dữ liệu](../tools/testlib/generator.md) và hai chương trình cần so sánh kết quả đầu ra.

Mỗi lần chạy bộ sinh dữ liệu sẽ ghi dữ liệu được sinh ra vào tệp đầu vào. Sau đó dùng chuyển hướng để cho hai chương trình đọc dữ liệu và ghi đầu ra vào các tệp chỉ định, cuối cùng dùng lệnh `fc` trên Windows (trên Linux là lệnh `diff`) để so sánh tệp và kiểm tra tính đúng đắn của chương trình. Nếu phát hiện chương trình sai, có thể trực tiếp dùng dữ liệu vừa sinh ra để gỡ lỗi.

Khung đại khái của chương trình đối chiếu như sau:

```cpp
#include <cstdio>
#include <cstdlib>

int main() {
  // Dành cho Windows
  // Khi đối chiếu không bật nhập xuất tệp
  // Tất nhiên, đoạn chương trình này cũng có thể viết lại thành tập lệnh batch
  while (true) {
    system("gen > test.in");  // Bộ sinh dữ liệu ghi dữ liệu sinh ra vào tệp đầu vào
    system("test1.exe < test.in > a.out");  // Lấy đầu ra chương trình 1
    system("test2.exe < test.in > b.out");  // Lấy đầu ra chương trình 2
    if (system("fc a.out b.out")) {
      // Câu lệnh này so sánh các tệp đầu ra
      // Khi fc trả về 0 nghĩa là đầu ra giống nhau, ngược lại là có chỗ khác
      system("pause");  // Tiện xem chỗ khác nhau
      return 0;
      // Dữ liệu đầu vào này đã được lưu trong tệp test.in, có thể dùng trực tiếp để gỡ lỗi
    }
  }
}
```

## Vùng nhớ cấp phát sẵn (memory pool)

Khi cấp phát bộ nhớ động, việc thường xuyên dùng `new`/`malloc` sẽ tốn rất nhiều thời gian và không gian, thậm chí tạo ra nhiều mảnh bộ nhớ rời rạc làm giảm hiệu năng chương trình, có thể khiến chương trình vốn đúng bị TLE/MLE.

Lúc này cần dùng kỹ thuật "memory pool": trước khi thật sự sử dụng bộ nhớ, cấp phát trước một vùng bộ nhớ kích thước nhất định để dự phòng. Khi cần cấp phát động, chỉ cần lấy trực tiếp một khối từ vùng bộ nhớ dự phòng đó.

Trong phần lớn bài OI, có thể tính trước lượng bộ nhớ tối đa cần dùng và cấp phát một lần.

Ví dụ:

```cpp
// Cấp phát động mảng số nguyên có dấu 32 bit:
int* newarr(int sz) {
  static int pool[MAXN], *allocp = pool;
  return allocp += sz, allocp - sz;
}

// Mã cấp phát nút động cho cây phân đoạn (segment tree):
Node* newnode() {
  static Node pool[MAXN << 1], *allocp = pool - 1;
  return ++allocp;
}
```

## Tài liệu tham khảo

[Luogu Daily #86](https://studyingfather.blog.luogu.org/some-coding-tips-for-oiers)

*Bài tập và lời giải chọn lọc cho Nhập môn kinh điển về lập trình thi đấu*
