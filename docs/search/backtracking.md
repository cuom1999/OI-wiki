Trang này giới thiệu ngắn gọn khái niệm và ứng dụng của phương pháp quay lui.

## Giới thiệu

Quay lui là một kỹ thuật thường được dùng trong [tìm kiếm theo chiều sâu
(DFS)](./dfs.md) và [tìm kiếm theo chiều rộng (BFS)](./bfs.md).

Bản chất của nó là: đi không được thì quay lại.

## Quy trình

1.  Xây dựng cây không gian trạng thái.

2.  Duyệt cây.

3.  Nếu gặp điều kiện biên, không tìm tiếp xuống dưới mà chuyển sang nhánh khác.

4.  Khi đạt điều kiện mục tiêu, xuất kết quả.

## Ví dụ

???+ example "[USACO 1.5.4 Thử thách đặt hậu](https://www.luogu.com.cn/problem/P1219)"
    Có một bàn cờ dạng $6 \times 6$ như sau. Sáu quân cờ được đặt trên bàn sao
    cho mỗi hàng, mỗi cột, mỗi đường chéo (bao gồm mọi đường chéo thuộc hai họ
    đường chéo chính) có nhiều nhất một quân cờ.
    
    ```plain
    0   1   2   3   4   5   6
      -------------------------
    1 |   | O |   |   |   |   |
      -------------------------
    2 |   |   |   | O |   |   |
      -------------------------
    3 |   |   |   |   |   | O |
      -------------------------
    4 | O |   |   |   |   |   |
      -------------------------
    5 |   |   | O |   |   |   |
      -------------------------
    6 |   |   |   |   | O |   |
      -------------------------
    ```
    
    Bố cục trên có thể được mô tả bằng dãy $\{2,4,6,1,3,5\}$: số thứ $i$ cho
    biết ở hàng thứ $i$, cột thứ $a_i$ có một quân cờ, như sau:
    
    Số hiệu hàng $i$: $\{1,2,3,4,5,6\}$
    
    Số hiệu cột $a_i$: $\{2,4,6,1,3,5\}$
    
    Đây chỉ là một phương án đặt quân. Yêu cầu là viết chương trình tìm mọi
    phương án và xuất chúng theo cách biểu diễn bằng dãy như trên, theo thứ tự
    từ điển. Chỉ cần xuất $3$ lời giải đầu tiên và ở dòng cuối xuất tổng số lời
    giải. Đặc biệt lưu ý: cần tối ưu chương trình để bảo đảm hiệu suất với kích
    thước bàn cờ lớn hơn.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/search/code/backtracking/backtracking_1.cpp"
    ```

???+ example "[Mê cung](https://www.luogu.com.cn/problem/P1605)"
    Có một mê cung kích thước $N \times M$, trong đó có $T$ vị trí chướng ngại,
    không thể đi qua. Cho tọa độ điểm bắt đầu và điểm kết thúc, mỗi ô nhiều nhất
    được đi qua một lần. Hỏi có bao nhiêu cách đi từ điểm bắt đầu đến điểm kết
    thúc. Trong mê cung có thể di chuyển lên, xuống, trái, phải; mỗi lần chỉ di
    chuyển một ô. Dữ liệu bảo đảm điểm bắt đầu không nằm trên chướng ngại.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/search/code/backtracking/backtracking_2.cpp"
    ```
