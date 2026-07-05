Trang này giới thiệu ngắn gọn về sắp xếp giải đấu.

## Định nghĩa

Sắp xếp giải đấu (tiếng Anh: Tournament sort), còn gọi là sắp xếp chọn dạng
cây, là một phiên bản tối ưu của [sắp xếp chọn](./selection-sort.md) và là một
biến thể của [sắp xếp vun đống](./heap-sort.md) (đều dùng cây nhị phân hoàn
chỉnh). Trên cơ sở sắp xếp chọn, thuật toán dùng hàng đợi ưu tiên để tìm phần
tử tiếp theo cần chọn.

## Giới thiệu

Tên của sắp xếp giải đấu bắt nguồn từ thể thức thi đấu loại trực tiếp. Trong
thể thức này, nhiều người chơi tham gia, được so sánh từng cặp, và người thắng
đi tiếp vào vòng sau. Cách loại này có thể xác định người chơi tốt nhất, nhưng
người bị loại ở vòng cuối không nhất thiết là người tốt thứ hai: người đó vẫn
có thể kém một người đã bị loại trước đó.

## Quy trình

Lấy **cây sắp xếp giải đấu nhỏ nhất** làm ví dụ:

![Ví dụ sắp xếp giải đấu 1](./images/tournament-sort1.png)

Các phần tử cần sắp xếp được đặt ở các nút lá. Cạnh màu đỏ biểu diễn đường đi
chiến thắng của phần tử nhỏ hơn trong mỗi vòng so sánh. Sau khi hoàn thành một
"giải đấu", có thể chọn ra phần tử nhỏ nhất trong một nhóm phần tử.

Sau mỗi vòng so sánh trên $n$ phần tử, thu được $\frac{n}{2}$ "người thắng";
phần tử nhỏ hơn trong mỗi cặp đi tiếp vào vòng so sánh sau. Nếu một phần tử
không ghép được thành cặp, nó trực tiếp đi tiếp vào vòng sau.

![Ví dụ sắp xếp giải đấu 2](./images/tournament-sort2.png)

Sau khi hoàn thành một "giải đấu", cần loại bỏ phần tử đã được chọn. Có thể
trực tiếp đặt nó thành $\infty$ (thao tác này tương tự
[sắp xếp vun đống](./heap-sort.md)), rồi tổ chức "giải đấu" lần nữa để chọn
phần tử nhỏ thứ hai.

Sau đó lặp lại thao tác này cho đến khi tất cả phần tử có thứ tự.

## Tính chất

### Tính ổn định

Sắp xếp giải đấu là một thuật toán sắp xếp không ổn định.

### Độ phức tạp thời gian

Độ phức tạp thời gian tốt nhất, trung bình và xấu nhất của sắp xếp giải đấu đều
là $O(n\log n)$. Thuật toán dùng $O(n)$ thời gian để khởi tạo "giải đấu", sau
đó dùng $O(\log n)$ thời gian để chọn một phần tử trong $n$ phần tử.

### Độ phức tạp bộ nhớ

Độ phức tạp bộ nhớ của sắp xếp giải đấu là $O(n)$.

## Cài đặt

=== "C++"
    ```cpp
    int n, a[MAXN], tmp[MAXN << 1];
    
    int winner(int pos1, int pos2) {
      int u = pos1 >= n ? pos1 : tmp[pos1];
      int v = pos2 >= n ? pos2 : tmp[pos2];
      if (tmp[u] <= tmp[v]) return u;
      return v;
    }
    
    void creat_tree(int &value) {
      for (int i = 0; i < n; i++) tmp[n + i] = a[i];
      for (int i = 2 * n - 1; i > 1; i -= 2) {
        int k = i / 2;
        int j = i - 1;
        tmp[k] = winner(i, j);
      }
      value = tmp[tmp[1]];
      tmp[tmp[1]] = INF;
    }
    
    void recreat(int &value) {
      int i = tmp[1];
      while (i > 1) {
        int j, k = i / 2;
        if (i % 2 == 0)
          j = i + 1;
        else
          j = i - 1;
        tmp[k] = winner(i, j);
        i = k;
      }
      value = tmp[tmp[1]];
      tmp[tmp[1]] = INF;
    }
    
    void tournament_sort() {
      int value;
      creat_tree(value);
      for (int i = 0; i < n; i++) {
        a[i] = value;
        recreat(value);
      }
    }
    ```

=== "Python"
    ```python
    n = 0
    a = [0] * MAXN
    tmp = [0] * MAXN * 2
    
    
    def winner(pos1, pos2):
        u = pos1 if pos1 >= n else tmp[pos1]
        v = pos2 if pos2 >= n else tmp[pos2]
        if tmp[u] <= tmp[v]:
            return u
        return v
    
    
    def creat_tree():
        for i in range(0, n):
            tmp[n + i] = a[i]
        for i in range(2 * n - 1, 1, -2):
            k = int(i / 2)
            j = i - 1
            tmp[k] = winner(i, j)
        value = tmp[tmp[1]]
        tmp[tmp[1]] = INF
        return value
    
    
    def recreat():
        i = tmp[1]
        while i > 1:
            j = k = int(i / 2)
            if i % 2 == 0:
                j = i + 1
            else:
                j = i - 1
            tmp[k] = winner(i, j)
            i = k
        value = tmp[tmp[1]]
        tmp[tmp[1]] = INF
        return value
    
    
    def tournament_sort():
        value = creat_tree()
        for i in range(0, n):
            a[i] = value
            value = recreat()
    ```

## Liên kết ngoài

-   [Tournament sort - Wikipedia](https://en.wikipedia.org/wiki/Tournament_sort)
