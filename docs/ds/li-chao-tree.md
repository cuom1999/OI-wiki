## Giới thiệu

???+ note "[Luogu 4097 \[HEOI2013\]Segment](https://www.luogu.com.cn/problem/P4097)"
    Yêu cầu duy trì hai thao tác trong hệ tọa độ Descartes phẳng (bắt buộc trực tuyến):

    1.  Thêm một đoạn thẳng vào mặt phẳng. Gọi chỉ số của đoạn thẳng được chèn thứ $i$ là $i$, hai đầu mút của đoạn thẳng này lần lượt là $(x_0,y_0)$ và $(x_1,y_1)$.
    2.  Cho một số $k$, hỏi trong các đoạn thẳng cắt đường thẳng $x = k$, chỉ số của đoạn thẳng có tung độ giao điểm lớn nhất (nếu có nhiều đoạn thẳng cùng đạt tung độ giao điểm lớn nhất với đường thẳng truy vấn, xuất đoạn có chỉ số nhỏ nhất). Đặc biệt, nếu không có đoạn thẳng nào cắt đường thẳng đã cho, xuất $0$.

    Dữ liệu thỏa mãn: tổng số thao tác $1 \leq n \leq 10^5$, $1 \leq k, x_0, x_1 \leq 39989$, $1 \leq y_0, y_1 \leq 10^9$.

Ta thấy rằng cây phân đoạn truyền thống khó duy trì tốt loại thông tin này. Trong tình huống đó, **cây phân đoạn Li Chao** ra đời.

## Quá trình

Ta có thể chuyển bài toán thành việc duy trì các thao tác sau:

-   Thêm một hàm bậc nhất có miền xác định là $[l,r]$;
-   Cho $k$, trong tất cả các hàm bậc nhất có miền xác định chứa $k$, tìm hàm có giá trị lớn nhất tại $x=k$; nếu có nhiều hàm có cùng giá trị, chọn hàm có chỉ số nhỏ nhất.

???+ warning "Chú ý"
    Khi đoạn thẳng vuông góc với trục $x$, sẽ xảy ra trường hợp chia cho không. Giả sử hai đầu mút của đoạn thẳng lần lượt là $(x,y_0)$ và $(x,y_1)$, $y_0<y_1$, khi đó chèn hàm bậc nhất $f(x)=0\cdot x+y_1$ có miền xác định là $[x,x]$.

Khi gặp cập nhật đoạn, ta làm theo cách thường dùng của cây phân đoạn để giải bài toán trên đoạn: gán cho mỗi nút một nhãn lười. Nhãn lười của mỗi nút $i$ là một đoạn thẳng, ký hiệu là $l_i$, biểu thị rằng cần dùng $l_i$ để cập nhật toàn bộ đoạn mà nút đó đại diện.

Bây giờ ta cần chèn một đoạn thẳng $f$, xét một đoạn trên cây phân đoạn được đoạn thẳng mới $f$ phủ hoàn toàn. Nếu đoạn này chưa có nhãn, trực tiếp gán nhãn cập nhật bằng đoạn thẳng đó.

Nếu đoạn này đã có nhãn, do các nhãn khó hợp nhất, ta chỉ có thể đẩy nhãn xuống. Tuy nhiên các nút con cũng có nhãn riêng và cũng có thể phát sinh xung đột, nên ta phải đệ quy đẩy nhãn xuống.

![](images/li-chao-tree-1.png)

Như hình minh họa, dựa trên việc giá trị của đoạn thẳng mới $f$ có lớn hơn nhãn cũ $g$ hay không, ta có thể chia đoạn hiện tại thành hai đoạn con. Trong đó **chắc chắn có một đoạn con được nửa trái hoặc nửa phải chứa hoàn toàn**, tức là trong hai đoạn thẳng, chắc chắn có một đoạn chỉ có thể trở thành đáp án ở nửa trái, hoặc chỉ có thể trở thành đáp án ở nửa phải. Ta dùng đoạn thẳng đó để đệ quy cập nhật cây con tương ứng, và dùng đoạn thẳng còn lại làm nhãn lười để cập nhật toàn bộ đoạn; nhờ vậy đảm bảo độ phức tạp của quá trình đệ quy đẩy xuống. Một đoạn thẳng chỉ được đẩy xuống khi nó chỉ có thể trở thành đáp án ở nửa trái hoặc nửa phải, nên không cần lo bỏ sót đoạn thẳng nào.

Cụ thể, giả sử trung điểm của đoạn hiện tại là $m$, ta so sánh giá trị của đoạn thẳng mới $f$ tại trung điểm với giá trị của đoạn thẳng tối ưu cũ $g$ tại trung điểm.

Nếu đoạn thẳng mới $f$ tốt hơn, hoán đổi $f$ và $g$. Khi đó ta chỉ cần xét trường hợp tại trung điểm $f$ không tốt bằng $g$:

1.  Nếu tại đầu mút trái $f$ tốt hơn, thì $f$ và $g$ chắc chắn có giao điểm trong nửa trái; $f$ chỉ có thể tốt hơn $g$ ở nửa trái, nên đệ quy xuống con trái để đẩy nhãn.
2.  Nếu tại đầu mút phải $f$ tốt hơn, thì $f$ và $g$ chắc chắn có giao điểm trong nửa phải; $f$ chỉ có thể tốt hơn $g$ ở nửa phải, nên đệ quy xuống con phải để đẩy nhãn.
3.  Nếu tại cả hai đầu mút trái và phải $g$ đều tốt hơn, thì $f$ không thể trở thành đáp án, không cần tiếp tục đẩy xuống.

Ngoài các trường hợp trên, còn có trường hợp $f$ và $g$ giao nhau đúng tại trung điểm. Khi cài đặt, có thể xếp trường hợp này vào nhóm tại trung điểm $f$ không tốt bằng $g$; kết quả sẽ đệ quy đẩy xuống về phía đầu mút mà $f$ tốt hơn.

Cuối cùng, đặt $g$ làm nhãn lười của đoạn hiện tại.

Đẩy nhãn xuống:

???+ note "Cài đặt"
    ```cpp
    constexpr double eps = 1e-9;

    int cmp(double x, double y) {  // Do dùng số thực nên sẽ có sai số độ chính xác
      if (x - y > eps) return 1;
      if (y - x > eps) return -1;
      return 0;
    }

    //...

    void upd(int root, int cl, int cr, int u) {  // Cập nhật đoạn được đoạn thẳng phủ hoàn toàn
      int &v = s[root], mid = (cl + cr) >> 1;
      int bmid = cmp(calc(u, mid), calc(v, mid));
      if (bmid == 1 || (!bmid && u < v))  // Trong bài này cần nhớ xét chỉ số đoạn thẳng
        swap(u, v);
      int bl = cmp(calc(u, cl), calc(v, cl)), br = cmp(calc(u, cr), calc(v, cr));
      if (bl == 1 || (!bl && u < v)) upd(root << 1, cl, mid, u);
      if (br == 1 || (!br && u < v)) upd(root << 1 | 1, mid + 1, cr, u);
      // Trong hai điều kiện if trên, nhiều nhất chỉ một điều kiện đúng; điều này đảm bảo độ phức tạp của cây Li Chao
    }
    ```

Tách đoạn thẳng:

???+ note "Cài đặt"
    ```cpp
    void update(int root, int cl, int cr, int l, int r,
                int u) {  // Xác định các đoạn được đoạn thẳng cần chèn phủ hoàn toàn
      if (l <= cl && cr <= r) {
        upd(root, cl, cr, u);  // Phủ hoàn toàn đoạn hiện tại, cập nhật nhãn của đoạn hiện tại
        return;
      }
      int mid = (cl + cr) >> 1;
      if (l <= mid) update(root << 1, cl, mid, l, r, u);  // Đệ quy tách đoạn
      if (mid < r) update(root << 1 | 1, mid + 1, cr, l, r, u);
    }
    ```

Chú ý rằng nhãn lười không tương đương với đoạn thẳng có giá trị lớn nhất tại trung điểm của đoạn.

![](images/li-chao-tree-2.png)

Như hình, sau khi thêm đoạn thẳng màu vàng, chỉ nhãn của nút màu đỏ được cập nhật, còn nhãn của các nút màu xanh lá vẫn chưa thay đổi. Nhưng tại trung điểm của các đoạn màu xanh lá thứ hai, thứ ba và thứ tư, rõ ràng đoạn thẳng màu vàng có giá trị lớn nhất.

Khi truy vấn, ta có thể dùng tư tưởng vĩnh cửu hóa nhãn: trong các đoạn trên cây phân đoạn chứa $x$ (không quá $O(\log n)$ đoạn), so sánh các đoạn thẳng được lưu trong nhãn để thu được đáp án cuối cùng.

Truy vấn:

???+ note "Cài đặt"
    ```cpp
    pdi query(int root, int l, int r, int d) {  // Truy vấn
      if (r < d || d < l) return {0, 0};
      int mid = (l + r) >> 1;
      double res = calc(s[root], d);
      if (l == r) return {res, s[root]};
      return pmax({res, s[root]}, pmax(query(root << 1, l, mid, d),
                                       query(root << 1 | 1, mid + 1, r, d)));
    }
    ```

Theo mô tả trên, độ phức tạp thời gian của quá trình truy vấn rõ ràng là $O(\log n)$. Còn khi chèn, ta cần tách đoạn thẳng ban đầu vào $O(\log n)$ đoạn; với mỗi đoạn, lại cần tốn $O(\log n)$ thời gian để đệ quy đẩy nhãn xuống, do đó độ phức tạp thời gian của quá trình chèn là $O(\log^2 n)$.

??? note "[\[HEOI2013\]Segment](https://www.luogu.com.cn/problem/P4097) Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/li-chao-tree/li-chao-tree_1.cpp"
    ```

## Hợp nhất

Tương tự cách hợp nhất cây phân đoạn thông thường, ta định nghĩa quy trình sau để hợp nhất hai nút cây phân đoạn Li Chao $u,v$, lấy $u$ làm gốc mới.

1.  Nếu $v$ rỗng, kết thúc quy trình.

2.  Nếu $u$ rỗng, sao chép $v$ cho $u$.

3.  Chèn đoạn thẳng tương ứng với $v$ vào cây con có gốc là $u$.

4.  Đệ quy hợp nhất tương ứng các cây con trái và phải của $u,v$.

Nếu tổng số nút liên quan khi hợp nhất một số cây phân đoạn Li Chao là $n$, độ phức tạp của quy trình này là $O(n\log n)$: với mỗi nút tương ứng với một đoạn thẳng bất kỳ trên cây, mỗi lần cần di chuyển nó, ta hoặc làm độ sâu của nó tăng $1$, hoặc trực tiếp xóa nó khỏi cây. Cả hai thao tác đều có chi phí $O(1)$, còn độ sâu của mỗi nút nhiều nhất là $O(\log n)$, vì vậy thu được độ phức tạp như trên.

???+ note "Cài đặt"
    ```cpp
    void upd(int &root, int cl, int cr,
             int u) {  // Khi hợp nhất nhiều cây phân đoạn Li Chao, dùng cấp phát nút động.
      static int idx = 0;
      if (!root) {
        s[root = ++idx] = u;
        return;
      }
      int &v = s[root], mid = (cl + cr) >> 1;
      int bmid = cmp(calc(u, mid), calc(v, mid));
      if (bmid == 1 || (!bmid && u < v)) swap(u, v);
      int bl = cmp(calc(u, cl), calc(v, cl)), br = cmp(calc(u, cr), calc(v, cr));
      if (bl == 1 || (!bl && u < v)) upd(ls[root], cl, mid, u);
      if (br == 1 || (!br && u < v)) upd(rs[root], mid + 1, cr, u);
    }

    int merge(int &u, int &v, int l, int r) {
      if (!u || !v) {
        return u + v;
      }
      if (l == r) {
        int b = cmp(calc(s[v], l), calc(s[u], l));
        if (b == 1 || (!b && s[v] < s[u])) return v;
        return u;
      }
      upd(u, l, r, s[v]);
      int mid = (l + r) >> 1;
      ls[u] = merge(ls[u], ls[v], l, mid);
      rs[u] = merge(rs[u], rs[v], mid + 1, r);
      return u;
    }
    ```

## Bài tập

[JSOI2008 Blue Mary mở công ty](https://www.luogu.com.cn/problem/P4254)

[CodeChef TSUM2 Sum on Tree](https://www.codechef.com/problems/TSUM2)

[USACO13MAR Hill Walk G](https://www.luogu.com.cn/problem/P3081)

[CF932F Escape Through Leaf](https://codeforces.com/problemset/problem/932/F)
