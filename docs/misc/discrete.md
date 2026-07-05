author: GavinZhengOI, PlanariaIce

## Giới thiệu

Rời rạc hóa là một kỹ thuật xử lý dữ liệu. Về bản chất, có thể xem nó như một dạng [hash](../string/hash.md), bảo đảm dữ liệu sau khi hash vẫn giữ nguyên quan hệ [thứ tự toàn phần hoặc thứ tự bộ phận](../math/order-theory.md) ban đầu.

Nói một cách đơn giản, khi một số dữ liệu quá lớn hoặc có kiểu không hỗ trợ dùng trực tiếp làm chỉ số mảng, nhưng kết quả cuối cùng chỉ phụ thuộc vào quan hệ thứ tự tương đối giữa các phần tử, ta có thể xử lý bài toán bằng thứ hạng của dữ liệu ban đầu. Đó chính là rời rạc hóa.

Dữ liệu được rời rạc hóa có thể là số nguyên lớn, số thực, chuỗi, v.v.

## Cài đặt

Rời rạc hóa một mảng và thực hiện truy vấn trên mảng đó là một tình huống ứng dụng khá thường gặp.

### Cách 1

Thông thường mảng ban đầu có thể chứa các phần tử trùng lặp. Nhìn chung, các phần tử bằng nhau sẽ được rời rạc hóa thành cùng một giá trị.

Cách làm như sau:

1.  Tạo một bản sao của mảng ban đầu.

2.  Sắp xếp các giá trị trong bản sao theo thứ tự tăng dần.

3.  Loại bỏ các giá trị trùng lặp trong bản sao đã sắp xếp.

4.  Tìm vị trí của từng phần tử trong mảng ban đầu trên bản sao; vị trí đó chính là thứ hạng, và được dùng làm giá trị sau khi rời rạc hóa.

```cpp
// arr[i] là mảng ban đầu, phạm vi chỉ số là [1, n]

for (int i = 1; i <= n; ++i)  // step 1
  tmp[i] = arr[i];
std::sort(tmp + 1, tmp + n + 1);                          // step 2
int len = std::unique(tmp + 1, tmp + n + 1) - (tmp + 1);  // step 3
for (int i = 1; i <= n; ++i)                              // step 4
  arr[i] = std::lower_bound(tmp + 1, tmp + len + 1, arr[i]) - tmp;
```

Các thuật toán STL được dùng trong mã tham khảo có thể xem tại [Thuật toán STL](../lang/csl/algorithm.md).

Tương tự, ta cũng có thể rời rạc hóa [std::vector](../lang/csl/sequence-container.md#vector):

```cpp
// std::vector<int> arr;
std::vector<int> tmp(arr);  // tmp là một bản sao của arr
std::sort(tmp.begin(), tmp.end());
tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
for (int i = 0; i < n; ++i)
  arr[i] = std::lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
```

### Cách 2

Tùy yêu cầu của bài toán, đôi khi các phần tử bằng nhau cần được rời rạc hóa thành các giá trị khác nhau theo thứ tự xuất hiện trong đầu vào.

Lúc này việc dùng hàm `std::lower_bound()` để cài đặt sẽ hơi khó, nên cần đổi sang một cách nghĩ khác:

1.  Tạo một bản sao của mảng ban đầu, đồng thời ghi lại vị trí xuất hiện của mỗi phần tử.

2.  Sắp xếp bản sao theo giá trị tăng dần; nếu giá trị bằng nhau, sắp xếp theo thứ tự xuất hiện tăng dần.

3.  Ghi các số sau khi rời rạc hóa trở lại mảng ban đầu.

```cpp
struct Data {
  int idx, val;

  bool operator<(const Data& o) const {
    if (val == o.val)
      return idx < o.idx;  // Nếu giá trị bằng nhau, phần tử xuất hiện trước có giá trị rời rạc hóa nhỏ hơn
    return val < o.val;
  }
} tmp[MAXN];  // Cũng có thể dùng std::pair

for (int i = 1; i <= n; ++i) tmp[i] = Data{i, arr[i]};
std::sort(tmp + 1, tmp + n + 1);
for (int i = 1; i <= n; ++i) arr[tmp[i].idx] = i;
```

### Độ phức tạp

Với cách 1, độ phức tạp loại trùng là $O(n)$, độ phức tạp sắp xếp là $O(n \log n)$, và $n$ lần tìm kiếm cuối cùng có độ phức tạp $O(n \log n)$.

Với cách 2, độ phức tạp sắp xếp là $O(n \log n)$.

Vì vậy tổng độ phức tạp thời gian của cả hai cách đều là $O(n \log n)$.

Độ phức tạp không gian là $O(n)$.

## Bài tập

-   [\[HAOI2014\] Dán áp phích](https://www.luogu.com.cn/problem/P3740)
-   [\[NOI2015\] Phân tích tự động chương trình](https://www.luogu.com.cn/problem/P1955)
