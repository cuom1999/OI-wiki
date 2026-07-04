author: FFjet, ChungZH, frank-xjh, hsfzLZH1, Xarfa, AndrewWayne, hcx1204

Trang này giới thiệu ngắn gọn hai thuật toán tìm kiếm hai chiều: "tìm kiếm đồng
thời hai chiều" và "meet in the middle".

## Tìm kiếm đồng thời hai chiều

### Định nghĩa

Ý tưởng cơ bản của tìm kiếm đồng thời hai chiều là bắt đầu [BFS](./bfs.md) hoặc
[DFS](./dfs.md) đồng thời từ trạng thái bắt đầu và trạng thái kết thúc trên đồ
thị trạng thái.

Nếu phát hiện hai đầu tìm kiếm gặp nhau, ta có thể xem như đã tìm được một lời
giải khả thi.

### Quy trình

Các bước của BFS hai chiều:

```text
Đưa nút bắt đầu và nút mục tiêu vào hàng đợi q
Đánh dấu nút bắt đầu là 1
Đánh dấu nút mục tiêu là 2
while (hàng đợi q không rỗng)
{
  Mở rộng q.front() ra s nút mới
  
  Nếu nút mới được mở rộng đã được đánh dấu bằng số khác
    Thì hai đầu tìm kiếm đã va vào nhau
    Khi đó kết thúc vòng lặp
  
  Nếu s nút mới được mở rộng từ nút bắt đầu
    Thì đánh dấu s nút đó là 1 và đưa vào hàng đợi q
  
  Nếu s nút mới được mở rộng từ nút mục tiêu
    Thì đánh dấu s nút đó là 2 và đưa vào hàng đợi q
}
```

### Ví dụ

???+ note "Ví dụ [Bài toán 8-puzzle](https://www.luogu.com.cn/problem/P1379)"
    Trên bàn cờ $3\times 3$ có tám quân cờ, mỗi quân ghi một số từ $1$ đến $8$.
    Trên bàn cờ còn một ô trống, biểu diễn bằng $0$. Các quân cờ xung quanh ô
    trống có thể di chuyển vào ô trống. Bài toán yêu cầu: cho một bố cục ban
    đầu và một bố cục mục tiêu (để đơn giản, đặt trạng thái mục tiêu là
    $123804765$), hãy tìm cách di chuyển với số bước ít nhất để chuyển từ bố cục
    ban đầu sang bố cục mục tiêu.

??? note "Ý tưởng giải"
    Dễ nghĩ đến BFS vét cạn. Bài này dùng BFS vét cạn cũng không quá thời gian,
    nhưng ở đây dùng nó làm ví dụ cho tìm kiếm đồng thời hai chiều. Ta có thể
    dùng hai BFS: một BFS tìm xuôi từ trạng thái bắt đầu, một BFS tìm ngược từ
    trạng thái kết thúc, rồi luân phiên dùng hai BFS. Kích thước cây tìm kiếm sẽ
    giảm rất nhiều. Khi một BFS tìm ra trạng thái mà BFS kia đã tìm được, ta có
    đáp án.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/search/code/bidirectional/bidirectional_1.cpp"
    ```

## Meet in the middle

???+ warning "Cảnh báo"
    Phần này không nói về [**tìm kiếm nhị phân**](../basic/binary.md), dù tìm
    kiếm nhị phân cũng đôi khi được gọi là "tìm kiếm chia đôi".

### Dẫn nhập

Thuật toán meet in the middle không có tên dịch chính thức; các cách dịch thường
gặp gồm "tìm kiếm chia đôi", "tìm kiếm hai chiều" hoặc "gặp nhau ở giữa".

Nó phù hợp với trường hợp dữ liệu đầu vào nhỏ, nhưng chưa nhỏ đến mức có thể
dùng vét cạn trực tiếp.

### Quy trình

Ý tưởng chính của meet in the middle là chia toàn bộ quá trình tìm kiếm thành
hai nửa, tìm kiếm riêng từng nửa, rồi cuối cùng gộp kết quả của hai nửa lại.

### Tính chất

Độ phức tạp của vét cạn thường có dạng mũ; sau khi đổi sang meet in the middle,
số mũ của độ phức tạp có thể giảm một nửa, tức từ $O(a^b)$ xuống
$O(a^{b/2})$.

### Ví dụ

???+ note "Ví dụ [USACO09NOV Lights](https://www.luogu.com.cn/problem/P2962)"
    Có $n$ bóng đèn. Mỗi bóng được nối với một số bóng khác, và trên mỗi bóng có
    một công tắc. Nếu bấm công tắc trên một bóng, trạng thái bật/tắt của bóng đó
    và tất cả bóng nối với nó sẽ thay đổi. Ban đầu tất cả bóng đều tắt; cần bật
    tất cả bóng và tìm số lần bấm công tắc nhỏ nhất.
    
    $1\le n\le 35$.

??? note "Ý tưởng giải"
    Nếu dùng DFS vét cạn để tìm trạng thái bật/tắt công tắc, độ phức tạp là
    $O(2^{n})$, rõ ràng quá thời gian. Nhưng dùng meet in the middle thì có thể
    tối ưu còn $O(n2^{n/2})$. Cụ thể, trước hết tìm một nửa trạng thái, tức tìm
    mọi trạng thái có thể đạt được chỉ bằng các công tắc đánh số từ $1$ đến
    $\mathrm{mid}$; sau đó tìm mọi trạng thái có thể đạt được bằng nửa công tắc
    còn lại. Nếu trạng thái đèn bật của nửa trước và nửa sau bù nhau, ghép hai
    nửa đó lại sẽ được một phương án bật toàn bộ đèn. Khi hiện thực, có thể lưu
    trạng thái của nửa đầu và số lần bấm công tắc ít nhất để đạt từng trạng thái
    trong `map`; khi tìm kiếm nửa sau, với mỗi phương án tìm được, ghép nó với
    phương án bù tương ứng của nửa đầu để cập nhật đáp án.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/search/code/bidirectional/bidirectional_2.cpp"
    ```

## Liên kết ngoài

-   [What is meet in the middle algorithm w.r.t. competitive programming? - Quora](https://www.quora.com/What-is-meet-in-the-middle-algorithm-w-r-t-competitive-programming)
-   [Meet in the Middle Algorithm - YouTube](https://www.youtube.com/watch?v=57SUNQL4JFA)
