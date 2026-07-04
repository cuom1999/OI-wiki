Trang này giới thiệu ngắn gọn về các thuật toán sắp xếp được cài đặt trong thư viện chuẩn C và C++.

Trừ các hàm đã được nêu riêng, các hàm liệt kê trong trang này mặc định được định nghĩa trong tệp đầu `<algorithm>`.

## qsort

Xem thêm: [`qsort`](https://zh.cppreference.com/w/c/algorithm/qsort), [`std::qsort`](https://zh.cppreference.com/w/cpp/algorithm/qsort)

Hàm này là [sắp xếp nhanh](./quick-sort.md) được cài đặt trong thư viện chuẩn C, định nghĩa trong `<stdlib.h>`. Trong thư viện chuẩn C++, hàm này được định nghĩa trong `<cstdlib>`.

### Hàm so sánh của qsort và bsearch

Hàm qsort có bốn tham số: tên mảng, số phần tử, kích thước phần tử, và quy tắc so sánh. Trong đó, quy tắc so sánh được cài đặt bằng cách chỉ định hàm so sánh; chỉ định các hàm so sánh khác nhau có thể tạo ra các quy tắc sắp xếp khác nhau.

Tham số của hàm so sánh được giới hạn là hai con trỏ kiểu const void. Giá trị trả về được quy định là số dương, số âm hoặc 0.

Một cách viết ví dụ cho hàm so sánh là:

```c
int compare(const void *p1, const void *p2)  // Hàm so sánh cho mảng kiểu int
{
  int *a = (int *)p1;
  int *b = (int *)p2;
  if (*a > *b)
    return 1;  // Trả về số dương nghĩa là a lớn hơn b
  else if (*a < *b)
    return -1;  // Trả về số âm nghĩa là a nhỏ hơn b
  else
    return 0;  // Trả về 0 nghĩa là a và b tương đương
}
```

Lưu ý: dùng hiệu của hai phần tử thay cho số dương hoặc số âm trong giá trị trả về là một cách viết sai điển hình, vì điều này có thể gây lỗi tràn số.

Dưới đây là một ví dụ sắp xếp cấu trúc:

```c
struct eg  // Cấu trúc ví dụ
{
  int e;
  int g;
};

int compare(const void *p1,
            const void *p2)  // Hàm so sánh cho mảng kiểu struct eg: sắp xếp theo thành viên e
{
  struct eg *a = (struct eg *)p1;
  struct eg *b = (struct eg *)p2;
  if (a->e > b->e)
    return 1;  // Trả về số dương nghĩa là a lớn hơn b
  else if (a->e < b->e)
    return -1;  // Trả về số âm nghĩa là a nhỏ hơn b
  else
    return 0;  // Trả về 0 nghĩa là a và b tương đương
}
```

Từ đây cũng có thể thấy rằng tương đương không có nghĩa là bằng nhau, mà chỉ biểu thị hai phần tử tương đương theo quy tắc so sánh này.

## std::sort

Xem thêm: [`std::sort`](https://zh.cppreference.com/w/cpp/algorithm/sort)

Cách dùng:

```cpp
// a[0] .. a[n - 1] là dãy cần sắp xếp
// Sắp xếp a tại chỗ theo thứ tự từ nhỏ đến lớn
std::sort(a, a + n);

// cmp là hàm so sánh tự định nghĩa
std::sort(a, a + n, cmp);
```

Lưu ý: giá trị trả về của hàm so sánh trong sort là true và false; true và false được dùng để biểu thị quan hệ lớn nhỏ (thứ tự trước sau) giữa hai phần tử. Điều này hoàn toàn khác với ngữ nghĩa của hàm so sánh ba giá trị trong qsort. Nội dung cụ thể xem trong tài liệu sort đã dẫn ở trên.

Nếu muốn chuyển một cách đơn giản từ sort sang qsort mà nhìn chung vẫn giữ nguyên thứ tự sắp xếp (không xét các phần tử tương đương), cần đổi trả về true thành -1 và trả về false thành 1.

Hàm `std::sort` là hàm so sánh trong thư viện C++ được dùng phổ biến hơn. Tham số cuối cùng của hàm này là một hàm so sánh nhị phân; nếu không chỉ định hàm `cmp`, mặc định sẽ sắp xếp theo thứ tự từ nhỏ đến lớn.

Trong các chuẩn C++ cũ, hàm này chỉ được yêu cầu đạt độ phức tạp thời gian **trung bình** $O(n\log n)$. Từ chuẩn C++11 trở đi, hàm này được yêu cầu đạt độ phức tạp thời gian **xấu nhất** $O(n\log n)$.

Chuẩn C++ không quy định chặt chẽ thuật toán cài đặt của hàm này; cài đặt cụ thể phụ thuộc vào trình biên dịch. Các cài đặt trong [libstdc++](https://github.com/mirrors/gcc/blob/master/libstdc++-v3/include/bits/stl_algo.h) và [libc++](http://llvm.org/svn/llvm-project/libcxx/trunk/include/algorithm) đều dùng [sắp xếp nội quan](./quick-sort.md#内省排序).

## std::nth\_element

Xem thêm: [`std::nth_element`](https://zh.cppreference.com/w/cpp/algorithm/nth_element)

Cách dùng:

```cpp
std::nth_element(first, nth, last);
std::nth_element(first, nth, last, cmp);
```

Hàm này sắp xếp lại các phần tử trong `[first, last)` sao cho phần tử mà `nth` trỏ tới được đổi thành phần tử sẽ xuất hiện ở vị trí đó nếu `[first, last)` được sắp xếp. Tất cả phần tử đứng trước phần tử `nth` mới đều nhỏ hơn hoặc bằng tất cả phần tử đứng sau phần tử `nth` mới.

Thuật toán cài đặt là một dạng sắp xếp nội quan chưa hoàn chỉnh.

Với cả hai cách dùng trên, chuẩn C++ yêu cầu độ phức tạp thời gian trung bình là $O(n)$, trong đó n là `std::distance(first, last)`.

Hàm này thường được dùng để xây dựng [K-D Tree](../ds/kdt.md).

## std::stable\_sort

Xem thêm: [`std::stable_sort`](https://zh.cppreference.com/w/cpp/algorithm/stable_sort)

Cách dùng:

```cpp
std::stable_sort(first, last);
std::stable_sort(first, last, cmp);
```

Đây là sắp xếp ổn định, bảo đảm vị trí tương đối của các phần tử bằng nhau sau khi sắp xếp giống với trong dãy ban đầu.

Độ phức tạp thời gian là $O(n\log^2 n)$; khi có thể dùng thêm bộ nhớ phụ, độ phức tạp là $O(n\log n)$.

## std::partial\_sort

Xem thêm: [`std::partial_sort`](https://zh.cppreference.com/w/cpp/algorithm/partial_sort)

Cách dùng:

```cpp
// mid = first + k
std::partial_sort(first, mid, last);
std::partial_sort(first, mid, last, cmp);
```

Sắp xếp tại chỗ `k` phần tử đầu của dãy theo thứ tự do `cmp` cho trước; các phần tử phía sau không được bảo đảm thứ tự. Nếu không chỉ định hàm `cmp`, mặc định sẽ sắp xếp theo thứ tự từ nhỏ đến lớn.

Độ phức tạp: khoảng $(\mathit{last}-\mathit{first})\log(\mathit{mid}-\mathit{first})$ lần áp dụng `cmp`.

Nguyên lý:

Ý tưởng của `std::partial_sort` là: thực hiện thao tác `make_heap()` trên khoảng `[first, mid)` trong container ban đầu để xây dựng một heap lớn nhất, rồi so sánh từng phần tử trong `[mid, last)` với `first`, bảo đảm phần tử tại `first` là phần tử lớn nhất trong heap. Nếu phần tử đang xét nhỏ hơn giá trị lớn nhất đó, hoán đổi vị trí hai phần tử, rồi điều chỉnh các phần tử trong `[first, mid)` để chúng tiếp tục duy trì thứ tự heap lớn nhất. Sau khi so sánh xong, thực hiện thêm một lần thao tác sắp xếp heap `sort_heap()` trên các phần tử trong `[first, mid)`, để chúng được sắp theo thứ tự tăng dần. Lưu ý rằng thứ tự heap và thứ tự tăng dần là khác nhau.

## So sánh tự định nghĩa

Xem thêm: [Nạp chồng toán tử](https://zh.cppreference.com/w/cpp/language/operators)

Các kiểu dựng sẵn (như `int`) và cấu trúc do người dùng định nghĩa đều cho phép tùy biến hàm so sánh được dùng khi gọi các hàm sắp xếp STL. Khi gọi hàm, có thể truyền vào tham số cuối cùng một hàm cài đặt phép so sánh nhị phân.

Với cấu trúc do người dùng định nghĩa, trước khi dùng các hàm sắp xếp STL trên cấu trúc đó, phải định nghĩa ít nhất một toán tử quan hệ, hoặc cung cấp một hàm so sánh nhị phân khi dùng hàm. Thông thường nên định nghĩa `operator<`.[^note1]

Ví dụ:

```cpp
int a[1009], n = 10;
// ...
std::sort(a + 1, a + 1 + n);                  // Sắp xếp từ nhỏ đến lớn
std::sort(a + 1, a + 1 + n, greater<int>());  // Sắp xếp từ lớn đến nhỏ
```

```cpp
struct data {
  int a, b;

  bool operator<(const data rhs) const {
    return (a == rhs.a) ? (b < rhs.b) : (a < rhs.a);
  }
} da[1009];

bool cmp(const data u1, const data u2) {
  return (u1.a == u2.a) ? (u1.b > u2.b) : (u1.a > u2.a);
}

// ...
std::sort(da + 1, da + 1 + 10);  // Dùng toán tử < định nghĩa trong cấu trúc, sắp xếp từ nhỏ đến lớn
std::sort(da + 1, da + 1 + 10, cmp);  // Dùng hàm cmp để so sánh, sắp xếp từ lớn đến nhỏ
```

### Thứ tự yếu nghiêm ngặt

Xem thêm: [Ứng dụng trong C++ - Lý thuyết thứ tự](../math/order-theory.md#c-中的应用)

Toán tử dùng để sắp xếp phải thỏa mãn [thứ tự yếu nghiêm ngặt](../math/order-theory.md#二元关系), nếu không có thể xuất hiện tình huống không thể dự đoán (như lỗi khi chạy, hoặc không sắp xếp đúng).

Các cách làm sai thường gặp:

-   Dùng `<=` để định nghĩa toán tử nhỏ hơn trong sắp xếp.
-   Khi gọi toán tử sắp xếp, đọc một mảng bên ngoài mà giá trị có thể thay đổi (thường gặp trong thuật toán đường đi ngắn nhất).
-   Dùng kết quả so sánh giá trị lớn nhất và nhỏ nhất của nhiều số làm toán tử sắp xếp (ví dụ lỗi kinh điển trong trò chơi quân hậu / lập lịch gia công sản xuất).

## Liên kết ngoài

-   [Bàn về ứng dụng của sắp xếp đổi chỗ phần tử kề nhau và những điểm cần lưu ý](https://ouuan.github.io/浅谈邻项交换排序的应用以及需要注意的问题/)

## Tài liệu tham khảo và chú thích

[^note1]: Vì phần lớn thuật toán chuẩn mặc định dùng `operator<` để so sánh.
