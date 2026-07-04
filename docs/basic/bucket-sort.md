Trang này giới thiệu ngắn gọn về sắp xếp theo thùng.

## Định nghĩa

Sắp xếp theo thùng (tiếng Anh: Bucket sort) là một thuật toán sắp xếp, phù hợp khi dữ liệu cần sắp xếp có miền giá trị lớn nhưng phân bố tương đối đều.

## Quy trình

Sắp xếp theo thùng được thực hiện theo các bước sau:

1.  Tạo một số lượng mảng nhất định để làm các thùng rỗng;
2.  Duyệt dãy và lần lượt đưa từng phần tử vào thùng tương ứng;
3.  Sắp xếp từng thùng không rỗng;
4.  Đưa các phần tử từ các thùng không rỗng trở lại dãy ban đầu.

## Tính chất

### Tính ổn định

Nếu dùng một thuật toán sắp xếp ổn định bên trong mỗi thùng, đồng thời không thay đổi thứ tự tương đối giữa các phần tử khi đưa chúng vào thùng, thì sắp xếp theo thùng là một thuật toán sắp xếp ổn định.

Vì số phần tử trong mỗi thùng thường không nhiều, ta thường dùng sắp xếp chèn. Khi đó sắp xếp theo thùng là một thuật toán sắp xếp ổn định.

### Độ phức tạp thời gian

Độ phức tạp thời gian trung bình của sắp xếp theo thùng là $O(n + n^2/k + k)$ (chia đều miền giá trị thành $k$ phần + sắp xếp + gộp lại các phần tử); khi $k\approx n$ thì là $O(n)$.[^ref1]

Độ phức tạp thời gian xấu nhất của sắp xếp theo thùng là $O(n^2)$.

## Cài đặt

=== "C++"
    ```cpp
    constexpr int N = 100010;
    
    int n, w, a[N];
    vector<int> bucket[N];
    
    void insertion_sort(vector<int>& A) {
      for (int i = 1; i < A.size(); ++i) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
          A[j + 1] = A[j];
          --j;
        }
        A[j + 1] = key;
      }
    }
    
    void bucket_sort() {
      int bucket_size = w / n + 1;
      for (int i = 0; i < n; ++i) {
        bucket[i].clear();
      }
      for (int i = 1; i <= n; ++i) {
        bucket[a[i] / bucket_size].push_back(a[i]);
      }
      int p = 0;
      for (int i = 0; i < n; ++i) {
        insertion_sort(bucket[i]);
        for (int j = 0; j < bucket[i].size(); ++j) {
          a[++p] = bucket[i][j];
        }
      }
    }
    ```

=== "Python"
    ```python
    N = 100010
    w = n = 0
    a = [0] * N
    bucket = [[] for i in range(N)]
    
    
    def insertion_sort(A):
        for i in range(1, len(A)):
            key = A[i]
            j = i - 1
            while j >= 0 and A[j] > key:
                A[j + 1] = A[j]
                j -= 1
            A[j + 1] = key
    
    
    def bucket_sort():
        bucket_size = int(w / n + 1)
        for i in range(0, n):
            bucket[i].clear()
        for i in range(1, n + 1):
            bucket[int(a[i] / bucket_size)].append(a[i])
        p = 0
        for i in range(0, n):
            insertion_sort(bucket[i])
            for j in range(0, len(bucket[i])):
                a[p] = bucket[i][j]
                p += 1
    ```

## Tài liệu tham khảo và chú thích

[^ref1]: [Bucket sort - Wikipedia tiếng Anh](https://en.wikipedia.org/wiki/Bucket_sort#Average-case_analysis)
