Đống có thể hợp nhất bền vững thường được dùng trong các bài toán tìm $k$ đường đi ngắn nhất.

Nếu một loại đống có thể hợp nhất có độ phức tạp được bảo đảm theo từng thao tác, thay vì chỉ theo nghĩa khấu hao,
thì sau khi bền vững hóa, độ phức tạp của một thao tác đơn lẻ vẫn được bảo đảm là $O(\log n)$.
Nói cách khác, hiệu năng không bị suy giảm trên các bộ dữ liệu đặc biệt.

## Cây lệch trái bền vững

Trước khi đọc phần này, cần nắm các kiến thức liên quan về [cây lệch trái](./leftist-tree.md).

### Quy trình

Nhắc lại quá trình hợp nhất cây lệch trái.
Giả sử cần hợp nhất hai cây lệch trái có gốc lần lượt là $x,y$,
và cây được duy trì theo tính chất đống nhỏ:

1.  Nếu một trong hai nút $x,y$ rỗng, trả về $x+y$.

2.  Chọn nút có khóa nhỏ hơn trong hai nút $x,y$ làm gốc của cây sau khi hợp nhất.

3.  Đệ quy hợp nhất cây con phải của $x$ với $y$, rồi đặt gốc sau khi hợp nhất làm con phải của $x$.

4.  Duy trì tính chất lệch trái và giá trị `dist` của cây hiện tại sau khi hợp nhất, rồi trả về nút gốc đã chọn.

Vì mỗi lần đệ quy đều làm `dist[x]+dist[y]` giảm đi một, còn `dist[x]` là $O(\log n)$,
nên một lần hợp nhất chỉ sửa nhiều nhất $O(\log n)$ nút.
Do đó, độ phức tạp thời gian là $O(\log n)$.

Bền vững hóa yêu cầu giữ lại thông tin lịch sử để các phiên bản trước đó vẫn có thể được truy cập về sau.
Với cây lệch trái, chỉ cần sao chép đường đi bị sửa đổi trong quá trình thao tác.

Vì vậy, quá trình hợp nhất của cây lệch trái bền vững như sau:

1.  Nếu một trong hai nút $x,y$ rỗng, trả về $x+y$.

2.  Chọn nút có khóa nhỏ hơn trong hai nút $x,y$, tạo một bản sao mới $p$ của nút đó, rồi dùng $p$ làm gốc của cây sau
    hợp nhất.

3.  Đệ quy hợp nhất cây con phải của $p$ với $y$, rồi đặt gốc sau khi hợp nhất làm con phải của $p$.

4.  Duy trì tính chất lệch trái và giá trị `dist` của cây có gốc $p$, rồi trả về $p$.

Vì một thao tác trên cây lệch trái chỉ sửa và tạo mới nhiều nhất $O(\log n)$ nút,
nếu số thao tác là $m$ thì độ phức tạp thời gian và không gian của cây lệch trái bền vững đều là $O(m\log n)$.

### Cài đặt tham khảo

```cpp
int merge(int x, int y) {
  if (!x || !y) return x + y;
  if (v[x] > v[y]) swap(x, y);
  int p = ++cnt;
  lc[p] = lc[x];
  v[p] = v[x];
  rc[p] = merge(rc[x], y);
  if (dist[lc[p]] < dist[rc[p]]) swap(lc[p], rc[p]);
  dist[p] = dist[rc[p]] + 1;
  return p;
}
```
