## Phân rã trọng tâm động

Phân rã trọng tâm động dùng để giải các bài toán thống kê thông tin đường đi trên cây có **cập nhật trọng số đỉnh hoặc trọng số cạnh**.

### Cây phân rã trọng tâm

Trước hết nhắc lại quá trình tính toán của phân rã trọng tâm.

Với một đỉnh $x$, các đường đi đơn trong cây con của nó gồm hai loại: các đường đi đi qua đỉnh $x$, được tạo bởi một hoặc hai đường đi xuất phát từ $x$; và các đường đi không đi qua đỉnh $x$, tức là đã nằm trong cây con của các đỉnh con của nó.

Để tính các đường đi đơn trong một cây con, chọn một tâm phân rã $rt$, tính thông tin của các đường đi trong cây con đi qua đỉnh này. Sau đó, với mỗi đỉnh con của nó, xóa $rt$ và xem thành phần liên thông chứa đỉnh đó là một cây con để xử lý đệ quy. Các tâm phân rã được chọn có thể tạo thành một cấu trúc cây, gọi là **cây phân rã trọng tâm**. Tổng kích thước các thành phần liên thông do các đỉnh cùng tầng trong cây phân rã trọng tâm đại diện, tức các thành phần liên thông lấy đỉnh đó làm tâm phân rã, là $O(n)$. Điều này có nghĩa độ phức tạp thời gian của phân rã trọng tâm phụ thuộc vào độ sâu của cây phân rã trọng tâm. Nếu độ sâu của cây phân rã trọng tâm là $h$, độ phức tạp của phân rã trọng tâm là $O(nh)$.

Có thể chứng minh rằng nếu mỗi lần chọn trọng tâm của thành phần liên thông làm tâm phân rã, độ sâu của cây phân rã trọng tâm là nhỏ nhất và bằng $O(\log n)$. Nhờ đó, có thể thống kê thông tin của $O(n^2)$ đường đi trên cây trong độ phức tạp thời gian $O(n\log n)$.

Vì hình dạng của cây gốc không thay đổi trong quá trình phân rã trọng tâm động, hình dạng của cây phân rã trọng tâm cũng không thay đổi.

Dưới đây là mã tham khảo để xây cây phân rã trọng tâm:

```cpp
void calcsiz(int x, int f) {
  siz[x] = 1;
  maxx[x] = 0;
  for (int j = h[x]; j; j = nxt[j])
    if (p[j] != f && !vis[p[j]]) {
      calcsiz(p[j], x);
      siz[x] += siz[p[j]];
      maxx[x] = max(maxx[x], siz[p[j]]);
    }
  maxx[x] =
      max(maxx[x], sum - siz[x]);  // maxx[x] là kích thước cây con lớn nhất khi lấy x làm gốc
  if (maxx[x] < maxx[rt])
    rt = x;  // Không được viết <=, để giữ rt không đổi ở lần calcsiz thứ hai
}

void pre(int x) {
  vis[x] = true;  // Đánh dấu để về sau không xét đỉnh x nữa
  for (int j = h[x]; j; j = nxt[j])
    if (!vis[p[j]]) {
      sum = siz[p[j]];
      rt = 0;
      maxx[rt] = inf;
      calcsiz(p[j], -1);
      calcsiz(rt, -1);  // Tính hai lần, lần hai lấy kích thước các cây con khi gốc là rt
      fa[rt] = x;
      pre(rt);  // Ghi lại cha trên cây phân rã trọng tâm
    }
}

int main() {
  sum = n;
  rt = 0;
  maxx[rt] = inf;
  calcsiz(1, -1);
  calcsiz(rt, -1);
  pre(rt);
}
```

### Cài đặt cập nhật

Khi truy vấn và cập nhật, nhảy lần lượt qua các đỉnh cha trên cây phân rã trọng tâm để cập nhật trực tiếp. Vì độ sâu của cây phân rã trọng tâm nhiều nhất là $O(\log n)$, độ phức tạp của cách làm này được khống chế.

Trong quá trình phân rã trọng tâm động, cần các thông tin như khoảng cách từ một đỉnh đến các tổ tiên của nó trên cây phân rã trọng tâm. Vì mỗi đỉnh có nhiều nhất $O(\log n)$ tổ tiên, có thể tính thêm độ sâu $dep[x]$ khi xây cây phân rã trọng tâm, hoặc dùng LCA để tiền xử lý các khoảng cách này hay truy vấn trực tiếp khi cần. **Lưu ý**: khoảng cách từ một đỉnh đến các tổ tiên của nó trên cây phân rã trọng tâm không nhất thiết tăng dần, nên không thể cộng dồn!

Trong quá trình phân rã trọng tâm động, thông tin của một đỉnh có thể bị tính lặp trong thông tin của các tổ tiên của nó trên cây phân rã trọng tâm, vì vậy cần loại bỏ ảnh hưởng của phần bị tính trùng. Cách thường dùng là ghi nhận mỗi thành phần liên thông theo hai cách: một là thông tin khoảng cách của nó đến tâm phân rã, hai là thông tin khoảng cách của nó đến cha của tâm phân rã trên cây phân rã trọng tâm. Phần này sẽ được minh họa trong các ví dụ.

??? note "Ví dụ [ZJOI2007 Trốn tìm](https://www.luogu.com.cn/problem/P2056)"
    Cho một cây có $n$ đỉnh. Ban đầu tất cả các đỉnh đều có màu đen. Cần thực hiện hai loại thao tác sau:
    
    1.  Đảo màu của một đỉnh, trắng thành đen và đen thành trắng;
    2.  Hỏi khoảng cách giữa hai đỉnh đen xa nhất trên cây.
    
        $n\le 10^5,m\le 5\times 10^5$

Sau khi xây cây phân rã trọng tâm, với mỗi đỉnh $x$ duy trì hai **heap hỗ trợ xóa**. $dist[x]$ lưu thông tin khoảng cách từ mọi đỉnh đen trong thành phần liên thông do đỉnh $x$ đại diện đến $x$. $ch[x]$ biểu diễn thông tin khoảng cách từ các đỉnh đen thuộc tất cả các con của đỉnh $x$ trên cây phân rã trọng tâm và chính nó đến $x$. Do cách tham lam để tìm đáp án trong bài này, và hai đường đi đến từ cùng một cây con không thể ghép thành một đường đi hoàn chỉnh, trong heap này chỉ chèn giá trị của chính nó và giá trị lớn nhất trong mỗi cây con. Tổng của hai giá trị lớn nhất trong $ch[x]$, hoặc tổng của tất cả các giá trị nếu không đủ hai giá trị, chính là đường đi dài nhất có hai đầu đen đi qua đỉnh $x$ khi lấy $x$ làm tâm phân rã. Có thể dùng heap hỗ trợ xóa $ans$ để lưu đáp án của mọi đỉnh, khi đó giá trị lớn nhất trong heap này chính là đáp án cần tìm.

Có thể duy trì các heap hỗ trợ xóa $dist[x],ch[x],ans$ theo định nghĩa ở trên. Khi giá trị trong $dist[x]$ thay đổi, cũng có thể duy trì $ch[x],ans$ trong độ phức tạp thời gian $O(\log n)$.

Bây giờ xét xem giá trị $dist[x]$ thay đổi như thế nào khi đảo màu một đỉnh. Nếu đỉnh ban đầu là đen, cần thực hiện thao tác xóa; nếu đỉnh ban đầu là trắng, cần thực hiện thao tác chèn.

Giả sử cần đảo màu đỉnh $x$. Với mọi tổ tiên $u$ của nó, chèn hoặc xóa $dist(x,u)$ trong $dist[u]$, đồng thời duy trì các giá trị của $ch[x],ans$. Đặc biệt, cần chèn hoặc xóa giá trị $0$ trong $ch[x]$.

Mã tham khảo:

```cpp
--8<-- "docs/graph/code/dynamic-tree-divide/dynamic-tree-divide_1.cpp"
```

???+ note "Ví dụ [Luogu P6329 Mẫu cây phân rã trọng tâm | Sóng chấn động](https://www.luogu.com.cn/problem/P6329)"
    Cho một cây có $n$ đỉnh, mỗi đỉnh trên cây có trọng số $v[x]$. Cần thực hiện hai loại thao tác sau:
    
    1.  Hỏi tổng trọng số của các đỉnh có khoảng cách đến đỉnh $x$ không vượt quá $y$;
    2.  Sửa trọng số đỉnh của đỉnh $x$ thành $y$, tức $v[x]=y$.

Dùng cây đoạn trọng số cấp phát động để ghi nhận thông tin khoảng cách.

Tương tự ý tưởng của bài trước, với mỗi đỉnh duy trì cây đoạn $dist[x]$, biểu diễn thông tin khoảng cách từ mọi đỉnh trong khối phân rã $x$ đến đỉnh $x$; chỉ số là khoảng cách, còn giá trị được cộng thêm trọng số đỉnh. Cây đoạn $ch[x]$ biểu diễn thông tin khoảng cách từ mọi đỉnh trong khối phân rã $x$ đến đỉnh cha của $x$ trên cây phân rã.

Trong bài này, mọi truy vấn và cập nhật đều cần xử lý tất cả tổ tiên trên cây phân rã trọng tâm.

Lấy thao tác truy vấn làm ví dụ. Nếu cần hỏi tổng trọng số của các đỉnh có khoảng cách đến đỉnh $x$ không vượt quá $y$, trước hết cộng vào đáp án tổng giá trị trên cây đoạn $dist[x]$ với chỉ số từ $0$ đến $y$. Sau đó duyệt mọi tổ tiên $u$ của $x$, gọi tổ tiên thấp hơn một cấp của nó là $v$, đặt $d=dist(x,u)$. Nếu không đi vào cây con chứa $x$, tức cây con có gốc là $v$, cần cộng vào đáp án tổng giá trị trên cây đoạn $dist[u]$ với chỉ số từ $0$ đến $y-d$. Vì phần có gốc là $v$ đã bị tính lặp, cần trừ khỏi đáp án tổng giá trị trên cây đoạn $ch[v]$ với chỉ số từ $0$ đến $y-d$.

Khi thực hiện thao tác cập nhật, cần duy trì đồng thời $dist[x]$ và $ch[x]$.

Mã tham khảo:

```cpp
--8<-- "docs/graph/code/dynamic-tree-divide/dynamic-tree-divide_2.cpp"
```
