## Định nghĩa

Sắp xếp trộn ([merge sort](https://en.wikipedia.org/wiki/Merge_sort)) là một thuật toán sắp xếp ổn định, hiệu quả, dựa trên so sánh.

## Tính chất

Sắp xếp trộn dựa trên tư tưởng chia để trị: chia mảng thành các đoạn, sắp xếp từng đoạn rồi trộn lại. Độ phức tạp thời gian trong trường hợp tốt nhất, xấu nhất và trung bình đều là $\Theta (n \log n)$; độ phức tạp không gian là $\Theta (n)$.

Sắp xếp trộn có thể chỉ dùng $\Theta (1)$ không gian phụ, nhưng để tiện cài đặt, ta thường dùng một mảng phụ có cùng độ dài với mảng ban đầu.

## Quy trình

### Trộn

Phần cốt lõi nhất của sắp xếp trộn là thao tác trộn (merge): trộn hai mảng đã sắp xếp `a[i]` và `b[j]` thành một mảng đã sắp xếp `c[k]`.

Duyệt `a[i]` và `b[j]` từ trái sang phải, tìm giá trị nhỏ nhất rồi đưa vào mảng `c[k]`; lặp lại quá trình trên cho đến khi một trong hai mảng `a[i]` và `b[j]` rỗng, sau đó đưa các phần tử còn lại của mảng kia vào `c[k]`.

Để bảo đảm tính ổn định của phép sắp xếp, khi phần tử đầu của đoạn trước nhỏ hơn hoặc bằng phần tử đầu của đoạn sau (`a[i] <= b[j]`), thay vì chỉ khi nhỏ hơn (`a[i] < b[j]`), ta phải đưa nó vào `c[k]` như giá trị nhỏ nhất.

#### Cài đặt

=== "C/C++"
    === "Cài đặt bằng mảng"
        ```cpp
        void merge(const int *a, size_t aLen, const int *b, size_t bLen, int *c) {
          size_t i = 0, j = 0, k = 0;
          while (i < aLen && j < bLen) {
            if (b[j] < a[i]) {  // <!> Kiểm tra b[j] < a[i] trước để đảm bảo tính ổn định
              c[k] = b[j];
              ++j;
            } else {
              c[k] = a[i];
              ++i;
            }
            ++k;
          }
          // Lúc này một mảng đã rỗng, mảng kia còn phần tử; gộp mảng chưa rỗng vào c
          for (; i < aLen; ++i, ++k) c[k] = a[i];
          for (; j < bLen; ++j, ++k) c[k] = b[j];
        }
        ```
    
    === "Cài đặt bằng con trỏ"
        ```cpp
        void merge(const int *aBegin, const int *aEnd, const int *bBegin,
                   const int *bEnd, int *c) {
          while (aBegin != aEnd && bBegin != bEnd) {
            if (*bBegin < *aBegin) {
              *c = *bBegin;
              ++bBegin;
            } else {
              *c = *aBegin;
              ++aBegin;
            }
            ++c;
          }
          for (; aBegin != aEnd; ++aBegin, ++c) *c = *aBegin;
          for (; bBegin != bEnd; ++bBegin, ++c) *c = *bBegin;
        }
        ```
    
    Cũng có thể dùng hàm `merge` trong thư viện `<algorithm>`; cách dùng giống với cách viết bằng con trỏ ở trên.

=== "Python"
    ```python
    def merge(a, b):
        i, j = 0, 0
        c = []
        while i < len(a) and j < len(b):
            # <!> Kiểm tra b[j] < a[i] trước để đảm bảo tính ổn định
            if b[j] < a[i]:
                c.append(b[j])
                j += 1
            else:
                c.append(a[i])
                i += 1
        # Lúc này một mảng đã rỗng, mảng kia còn phần tử; gộp mảng chưa rỗng vào c
        c.extend(a[i:])
        c.extend(b[j:])
        return c
    ```

### Cài đặt sắp xếp trộn bằng chia để trị

1.  Khi độ dài mảng là $1$, mảng đó đã được sắp xếp, không cần phân tách tiếp.

2.  Khi độ dài mảng lớn hơn $1$, mảng đó rất có thể chưa được sắp xếp. Khi đó, chia mảng thành hai đoạn, rồi lần lượt kiểm tra xem hai mảng con có được sắp xếp hay không (theo mục 1). Nếu đã sắp xếp thì trộn chúng thành một mảng đã sắp xếp; nếu chưa, lặp lại mục 2 với mảng chưa được sắp xếp rồi trộn lại.

Có thể chứng minh bằng quy nạp toán học rằng quy trình này biến một mảng thành mảng đã sắp xếp.

Để bảo đảm độ phức tạp của phép sắp xếp, thông thường ta chia mảng thành hai đoạn có độ dài gần bằng nhau nhất có thể ($mid = \left\lfloor \dfrac{l + r}{2} \right\rfloor$).

#### Cài đặt

Lưu ý rằng các đoạn được biểu diễn trong đoạn mã dưới đây lần lượt là $[l, r)$, $[l, mid)$, $[mid, r)$.

=== "C/C++"
    ```cpp
    void merge_sort(int *a, int l, int r) {
      if (r - l <= 1) return;
      // Phân tách
      int mid = l + ((r - l) >> 1);
      merge_sort(a, l, mid), merge_sort(a, mid, r);
      // Trộn
      int tmp[1024] = {};  // Hãy đặt độ dài mảng tmp theo tình huống thực tế
                           // (bằng a), hoặc dùng vector; trước hết đặt kết quả
                           // trộn vào tmp, rồi chép ngược về mảng a
      merge(a + l, a + mid, a + mid, a + r, tmp + l);  // pointer-style merge
      for (int i = l; i < r; ++i) a[i] = tmp[i];
    }
    ```

=== "Python"
    ```python
    def merge_sort(a, ll, rr):
        if rr - ll <= 1:
            return
        # Phân tách
        mid = (rr + ll) // 2
        merge_sort(a, ll, mid)
        merge_sort(a, mid, rr)
        # Trộn
        a[ll:rr] = merge(a[ll:mid], a[mid:rr])
    ```

### Cài đặt sắp xếp trộn bằng nhân đôi

Ta đã biết rằng khi độ dài mảng là $1$, mảng đó đã được sắp xếp.

Cắt toàn bộ mảng thành các đoạn có độ dài $1$.

Từ trái sang phải, lần lượt trộn hai đoạn đã sắp xếp có độ dài $1$, thu được một loạt đoạn đã sắp xếp có độ dài $\le 2$;

Từ trái sang phải, lần lượt trộn hai đoạn đã sắp xếp có độ dài $\le 2$, thu được một loạt đoạn đã sắp xếp có độ dài $\le 4$;

Từ trái sang phải, lần lượt trộn hai đoạn đã sắp xếp có độ dài $\le 4$, thu được một loạt đoạn đã sắp xếp có độ dài $\le 8$;

……

Lặp lại quá trình trên cho đến khi trong mảng chỉ còn một đoạn đã sắp xếp; đoạn này chính là mảng ban đầu sau khi đã sắp xếp.

???+ note "Vì sao là $\le n$ mà không phải $= n$"
    Độ dài của mảng rất có thể không phải là $2^x$, khi đó ở cuối có thể xuất hiện các đoạn không đủ độ dài, thậm chí đoạn cuối cùng có thể đứng riêng.

#### Cài đặt

=== "C/C++"
    ```cpp
    void merge_sort(int *a, size_t n) {
      int tmp[1024] = {};  // Hãy đặt độ dài mảng tmp theo tình huống thực tế
                           // (bằng a), hoặc dùng vector; trước hết đặt kết quả
                           // trộn vào tmp, rồi chép ngược về mảng a
      for (size_t seg = 1; seg < n; seg <<= 1) {
        for (size_t left1 = 0; left1 < n - seg;
             left1 += seg + seg) {  // n - seg: nếu cuối cùng chỉ còn một đoạn thì không cần trộn
          size_t right1 = left1 + seg;
          size_t left2 = right1;
          size_t right2 = std::min(left2 + seg, n);  // <!> Lưu ý biên của đoạn cuối cùng
          merge(a + left1, a + right1, a + left2, a + right2,
                tmp + left1);  // pointer-style merge
          for (size_t i = left1; i < right2; ++i) a[i] = tmp[i];
        }
      }
    }
    ```

=== "Python"
    ```python
    def merge_sort(a):
        seg = 1
        while seg < len(a):
            for l1 in range(0, len(a) - seg, seg + seg):
                r1 = l1 + seg
                l2 = r1
                r2 = l2 + seg
                a[l1:r2] = merge(a[l1:r1], a[l2:r2])
        seg <<= 1
    ```

## Nghịch thế

Bài đọc liên quan và cài đặt tham khảo: [nghịch thế](../math/permutation.md#逆序数)

Nghịch thế là cặp có thứ tự $(i, j)$ thỏa mãn $i < j$ và $a_i > a_j$.

Mảng sau khi sắp xếp không còn nghịch thế. Trong thao tác trộn của sắp xếp trộn, mỗi khi phần tử đầu của đoạn sau được lấy ra làm giá trị nhỏ nhất hiện tại, tổng số phần tử còn lại ở đoạn trước chính là số nghịch thế mà thao tác trộn đã loại bỏ; vì vậy, độ phức tạp thời gian để dùng sắp xếp trộn tính số nghịch thế là $\Theta (n \log n)$. Ngoài ra, bài toán đếm nghịch thế cũng có thể được giải bằng cây Fenwick hoặc cây phân đoạn (segment tree), với độ phức tạp thời gian cũng là $O(n \log n)$; phần giải thích chi tiết của thuật toán này nằm trong mô tả tương ứng ở trang [cây Fenwick](../ds/fenwick.md#全局逆序对全局二维偏序). Cài đặt tham khảo của cả hai thuật toán đều có trong mục [nghịch thế](../math/permutation.md#逆序数).

## Liên kết ngoài

-   [Merge Sort - GeeksforGeeks](https://www.geeksforgeeks.org/merge-sort/)
-   [Sắp xếp trộn - Wikipedia tiếng Trung](https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F)
-   [Nghịch thế - Wikipedia tiếng Trung](https://zh.wikipedia.org/wiki/%E9%80%86%E5%BA%8F%E5%AF%B9)
