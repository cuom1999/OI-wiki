Heap có thể hợp nhất bền vững thường được dùng để giải bài toán $k$ đường đi ngắn nhất.

Nếu một loại heap có thể hợp nhất có độ phức tạp không phải theo nghĩa khấu hao, thì sau khi bền vững hóa, độ phức tạp của một thao tác đơn lẻ vẫn được bảo đảm là $O(\log n)$, tức không bị suy giảm do dữ liệu đặc biệt.

## Cây leftist bền vững

Trước khi học nội dung này, hãy nắm các kiến thức liên quan về [cây leftist](./leftist-tree.md).

### Quy trình

Nhắc lại quá trình hợp nhất cây leftist. Giả sử ta cần hợp nhất hai cây leftist có gốc lần lượt là $x,y$, và cây leftist được duy trì thỏa tính chất min-heap:

1.  Nếu một trong hai nút $x,y$ rỗng, trả về $x+y$.

2.  Chọn nút có khóa nhỏ hơn trong hai nút $x,y$ làm gốc của cây leftist sau khi hợp nhất.

3.  Đệ quy hợp nhất cây con phải của $x$ với $y$, rồi đặt gốc sau khi hợp nhất làm con phải của $x$.

4.  Duy trì tính chất leftist và giá trị `dist` của cây leftist hiện tại sau khi hợp nhất, rồi trả về nút gốc đã chọn.

Vì mỗi lần đệ quy đều làm `dist[x]+dist[y]` giảm đi một, còn `dist[x]` là $O(\log n)$, một lần hợp nhất nhiều nhất chỉ sửa $O(\log n)$ nút, nên độ phức tạp thời gian là $O(\log n)$.

Bền vững hóa yêu cầu giữ lại thông tin lịch sử để các phiên bản trước đó vẫn có thể được truy cập về sau. Để bền vững hóa cây leftist, cần sao chép đường đi bị sửa đổi trong quá trình thao tác.

Vì vậy, quá trình hợp nhất của cây leftist bền vững như sau:

1.  Nếu một trong hai nút $x,y$ rỗng, trả về $x+y$.

2.  Chọn nút có khóa nhỏ hơn trong hai nút $x,y$, tạo một bản sao mới $p$ của nút đó, rồi dùng $p$ làm gốc của cây leftist sau khi hợp nhất.

3.  Đệ quy hợp nhất cây con phải của $p$ với $y$, rồi đặt gốc sau khi hợp nhất làm con phải của $p$.

4.  Duy trì tính chất leftist và giá trị `dist` của cây leftist gốc $p$, rồi trả về $p$.

Vì một thao tác trên cây leftist nhiều nhất chỉ sửa và tạo mới $O(\log n)$ nút, nếu số thao tác là $m$ thì độ phức tạp thời gian và không gian của cây leftist bền vững đều là $O(m\log n)$.

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
