<span id="&#24341;&#20837;"></span>

## Dẫn nhập

DFS (tìm kiếm theo chiều sâu) là một khái niệm trong lý thuyết đồ thị; xem chi tiết ở trang [DFS (đồ thị)](../graph/dfs.md). Trong **thuật toán tìm kiếm**, thuật ngữ này thường chỉ các thuật toán dùng hàm đệ quy để cài đặt vét cạn một cách thuận tiện. Cách làm này có một số điểm tương đồng với DFS trong lý thuyết đồ thị, nhưng không hoàn toàn giống nhau.

<span id="&#35299;&#37322;"></span>

## Giải thích

Xét ví dụ sau:

???+ note "Bài toán ví dụ"
    Phân tích số nguyên dương $n$ thành $3$ số nguyên dương, chẳng hạn $6=1+2+3$. Số đứng sau phải lớn hơn hoặc bằng số đứng trước. Hãy in ra tất cả các phương án.

Với bài toán này, nếu chưa biết tìm kiếm thì nên làm thế nào? Tất nhiên có thể dùng ba vòng lặp lồng nhau; mã tham khảo như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        for (int i = 1; i <= n; ++i)
          for (int j = i; j <= n; ++j)
            for (int k = j; k <= n; ++k)
              if (i + j + k == n) printf("%d = %d + %d + %d\n", n, i, j, k);
        ```
    
    === "Python"
        ```python
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                for k in range(j, n + 1):
                    if i + j + k == n:
                        print("%d = %d + %d + %d" % (n, i, j, k))
        ```
    
    === "Java"
        ```Java
        for (int i = 1; i < n + 1; i++) {
            for (int j = i; j < n + 1; j++) {
                for (int k = j; k < n + 1; k++) {
                    if (i + j + k == n) System.out.printf("%d = %d + %d + %d%n", n, i, j, k);
                }
            }
        }
        ```

Vậy nếu cần phân tích thành bốn số nguyên thì sao? Thêm một vòng lặp nữa? Nếu cần phân tích thành không quá $m$ số nguyên thì sao?

Lúc này ta cần dùng tìm kiếm đệ quy. Đặc điểm của lớp thuật toán tìm kiếm này là chia mục tiêu cần tìm thành nhiều "tầng"; mỗi tầng dựa trên trạng thái của các tầng trước đó để đưa ra quyết định, cho đến khi đạt tới trạng thái mục tiêu.

Xét lại bài toán trên: phân tích số nguyên dương $n$ thành tổng của không quá $m$ số nguyên dương, trong đó số đứng sau phải lớn hơn hoặc bằng số đứng trước, rồi in ra tất cả các phương án.

Giả sử một phương án phân tích số nguyên dương $n$ thành tổng của $k$ số nguyên dương $a_1, a_2, \ldots, a_k$. Ta chia bài toán thành các tầng, trong đó tầng thứ $i$ quyết định $a_i$. Để ra quyết định ở tầng thứ $i$, ta cần ghi lại ba biến trạng thái: $n-\sum_{j=1}^i{a_j}$, biểu thị tổng các số nguyên dương còn lại; $a_{i-1}$, biểu thị số nguyên dương ở tầng trước, để bảo đảm dãy không giảm; và $i$, để bảo đảm ta in ra tối đa $m$ số nguyên dương. Để ghi lại phương án, ta dùng mảng `arr`, trong đó phần tử thứ $i$ biểu thị $a_i$. Lưu ý rằng `arr` về bản chất là một ngăn xếp có độ dài $i$.

Mã như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        int m, arr[103];  // arr dùng để ghi lại phương án
        
        void dfs(int n, int i, int a) {
          if (n == 0) {
            for (int j = 1; j <= i - 1; ++j) printf("%d ", arr[j]);
            printf("\n");
          }
          if (i <= m) {
            for (int j = a; j <= n; ++j) {
              arr[i] = j;
              dfs(n - j, i + 1, j);  // Hãy suy nghĩ kỹ ý nghĩa của dòng này.
            }
          }
        }
        
        // Hàm chính
        scanf("%d%d", &n, &m);
        dfs(n, 1, 1);
        ```
    
    === "Python"
        ```python
        arr = [0] * 103  # arr dùng để ghi lại phương án
        
        
        def dfs(n, i, a):
            if n == 0:
                print(arr[1:i])
            if i <= m:
                for j in range(a, n + 1):
                    arr[i] = j
                    dfs(n - j, i + 1, j)  # Hãy suy nghĩ kỹ ý nghĩa của dòng này.
        
        
        # Hàm chính
        n, m = map(int, input().split())
        dfs(n, 1, 1)
        ```
    
    === "Java"
        ```Java
        static int m;
        
        // arr dùng để ghi lại phương án
        static int[] arr = new int[103];
        
        public static void dfs(int n, int i, int a) {
            if (n == 0) {
                for (int j = 1; j <= i - 1; j++) System.out.printf("%d ", arr[j]);
                System.out.println();
            }
            if (i <= m) {
                for (int j = a; j <= n; ++j) {
                    arr[i] = j;
                    dfs(n - j, i + 1, j); // Hãy suy nghĩ kỹ ý nghĩa của dòng này.
                }
            }
        }
        
        // Hàm chính
        final int N = new Scanner(System.in).nextInt();
        m = new Scanner(System.in).nextInt();
        dfs(N, 1, 1);
        ```

<span id="&#20363;&#39064;"></span>

## Bài tập ví dụ

???+ note "[Luogu P1706 Bài toán hoán vị toàn phần](https://www.luogu.com.cn/problem/P1706)"
    ```cpp
    --8<-- "docs/search/code/dfs/dfs_1.cpp"
    ```
