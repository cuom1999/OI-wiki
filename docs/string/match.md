Trang này giới thiệu ngắn gọn bài toán khớp xâu và các cách giải.

## Bài toán khớp xâu

### Định nghĩa

Còn gọi là khớp mẫu (pattern matching). Bài toán có thể tóm tắt là: "cho hai xâu $S$ và $T$, tìm xâu con $T$ trong xâu chính $S$". Xâu $T$ được gọi là xâu mẫu (pattern).

### Phân loại

-   Khớp một xâu: cho một xâu mẫu và một xâu cần khớp, tìm mọi vị trí xuất hiện của xâu mẫu trong xâu kia.
-   Khớp nhiều xâu: cho nhiều xâu mẫu và một xâu cần khớp, tìm mọi vị trí xuất hiện của các xâu mẫu trong xâu kia.
    -   Khi có nhiều xâu cần khớp, có thể nối trực tiếp chúng lại để xử lý như một xâu cần khớp.
    -   Có thể xử lý trực tiếp như nhiều lần khớp một xâu, nhưng hiệu quả không đủ cao.
-   Các kiểu khác: ví dụ khớp hậu tố bất kỳ của một xâu, khớp hậu tố bất kỳ của nhiều xâu, v.v.

## Cách vét cạn

Thường gọi tắt là thuật toán BF (Brute Force). Ý tưởng cơ bản là bắt đầu từ ký tự đầu tiên của xâu chính $S$ và so sánh với ký tự đầu tiên của xâu mẫu $T$. Nếu bằng nhau, tiếp tục so sánh các ký tự tiếp theo của cả hai; nếu không, đưa xâu mẫu $T$ quay về ký tự đầu tiên và so sánh lại với ký tự thứ hai của xâu chính $S$. Lặp lại như vậy cho tới khi so sánh xong toàn bộ ký tự trong $S$ hoặc $T$.

### Cài đặt

=== "C++"
    ```cpp
    /*
     * s: xâu chính cần khớp
     * t: xâu mẫu
     * n: độ dài xâu chính
     * m: độ dài xâu mẫu
     */
    std::vector<int> match(char *s, char *t, int n, int m) {
      std::vector<int> ans;
      int i, j;
      for (i = 0; i < n - m + 1; i++) {
        for (j = 0; j < m; j++) {
          if (s[i + j] != t[j]) break;
        }
        if (j == m) ans.push_back(i);
      }
      return ans;
    }
    ```

=== "Python"
    ```python
    def match(s, t, n, m):
        if m < 1:
            return []
    
        ans = []
        for i in range(0, n - m + 1):
            for j in range(0, m):
                if s[i + j] != t[j]:
                    break
            else:
                ans.append(i)
        return ans
    ```

### Độ phức tạp thời gian

Gọi $n$ là độ dài xâu chính, $m$ là độ dài xâu mẫu. Mặc định $m\ll n$.

Khi thuật toán BF khớp thành công, trong trường hợp tốt nhất chỉ có một lượt khớp thành công, lượt này cần $m$ lần so sánh, còn mọi lượt khớp thất bại khác đều thất bại ở ký tự đầu của xâu mẫu và cần thêm $n-m$ lần so sánh. Tổng số lần so sánh là $n$, nên độ phức tạp thời gian là $O(n)$. Trong trường hợp xấu nhất, số lượt khớp thành công cần xét là $n-m+1$, mỗi lượt cần $m$ lần so sánh, tổng cộng $m(n-m+1)$ lần, nên độ phức tạp là $O(mn)$.

Khi thuật toán BF khớp thất bại, trong trường hợp tốt nhất mọi lượt thất bại đều xảy ra ở ký tự đầu của xâu mẫu, thuật toán BF cần thực hiện $n-m+1$ lần so sánh, độ phức tạp là $O(n)$. Trong trường hợp xấu nhất, mọi lượt thất bại đều xảy ra ở ký tự cuối của xâu mẫu, thuật toán BF cần thực hiện $m(n-m+1)$ lần so sánh, độ phức tạp là $O(mn)$.

Nếu xâu mẫu có ít nhất hai ký tự khác nhau, độ phức tạp trung bình của thuật toán BF là $O(n)$. Tuy nhiên trong các bài OI, xâu được cho thường không phải dữ liệu ngẫu nhiên thuần túy.

## Phương pháp hash

Xem: [hash xâu](./hash.md)

## Thuật toán KMP

Xem: [hàm tiền tố và thuật toán KMP](./kmp.md)
