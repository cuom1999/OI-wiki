author: HeRaNO, Ir1d, konnyakuxzy, ksyx, Xeonacid, konnyakuxzy, greyqz, sshwy, y-kx-b

## Dẫn nhập

???+ note "[SDOI2011 - Cuộc chiến tiêu hao](https://www.luogu.com.cn/problem/P2495)"
    Trong một cuộc chiến, chiến trường gồm $n$ hòn đảo và $n-1$ cây cầu. Giữa mỗi cặp đảo có đúng một đường đi duy nhất. Quân đội đã trinh sát được tổng hành dinh của địch nằm trên hòn đảo số $1$, và lực lượng địch không còn đủ năng lượng để duy trì chiến đấu; chiến thắng đã trong tầm tay. Biết rằng trên $k$ hòn đảo khác có nguồn năng lượng dồi dào. Để ngăn địch lấy được năng lượng, nhiệm vụ là phá hủy một số cây cầu sao cho địch không thể đi đến bất kỳ hòn đảo nào có năng lượng dồi dào. Do vật liệu và kết cấu của các cây cầu khác nhau, chi phí phá hủy mỗi cây cầu cũng khác nhau. Cần hoàn thành nhiệm vụ với tổng chi phí nhỏ nhất.
    
    Bộ phận trinh sát còn phát hiện quân địch có một cỗ máy bí ẩn. Ngay cả sau khi tất cả nguồn năng lượng bị cắt đứt, lực lượng địch vẫn có thể dùng cỗ máy đó. Cỗ máy không chỉ sửa lại tất cả cây cầu đã bị phá hủy, mà còn phân bố lại tài nguyên một cách ngẫu nhiên (nhưng bảo đảm tài nguyên không được phân bố lên đảo số $1$). Tuy nhiên, bộ phận trinh sát cũng phát hiện cỗ máy này chỉ có thể dùng $m$ lần, vì vậy chỉ cần hoàn thành nhiệm vụ tương ứng với từng lần sử dụng.
    
    Với mọi bộ dữ liệu, $2\le n\le 2.5\times 10^5,1\le m\le 5\times 10^5,\sum k_i\le 5\times 10^5,1\le k_i\le n-1$.

### Cách làm trực tiếp

Với bài trên, nếu số đỉnh của cây rất ít, có thể chạy DP trực tiếp.

Trước hết, gọi các đỉnh được chọn trong một truy vấn là **đỉnh then chốt**.

Đặt $Dp(i)$ biểu thị **chi phí nhỏ nhất** để $i$ không liên thông với bất kỳ đỉnh then chốt nào trong cây con của nó.

Đặt $w(a,b)$ biểu thị trọng số của cạnh giữa $a$ và $b$.

Khi duyệt các con $v$ của $i$:

-   Nếu $v$ không phải đỉnh then chốt: $Dp(i)=Dp(i) + \min \{Dp(v),w(i,v)\}$;
-   Nếu $v$ là đỉnh then chốt: $Dp(i)=Dp(i) + w(i,v)$.

Từ đó thu được một lời giải $O(nq)$.

Đây là một hướng tiếp cận trực tiếp.

### Cách tối ưu

Trên cây có rất nhiều đỉnh không đóng góp vào lời giải. Xét hình dưới:

![Cây gốc trước khi nén thành cây ảo](images/vtree-tree.svg)

Nếu các đỉnh then chốt được chọn là:

![Các đỉnh then chốt được chọn trên cây gốc](images/vtree-key-vertex.svg)

Trong hình chỉ có hai đỉnh màu đỏ là **đỉnh then chốt**, các đỉnh khác đều là đỉnh không then chốt.

Với bài này, chỉ cần bảo đảm các đỉnh màu đỏ không thể đi đến đỉnh số $1$.

Từ hình vẽ, cây con bên phải của đỉnh số $1$ (có thể có nhiều cây con; trong ví dụ này chỉ có hai cây con nên tạm gọi như vậy) không có đỉnh màu đỏ nào, **vì thế không cần chạy DP trên nó**.

Xét ràng buộc của đề bài, tổng số đỉnh màu đỏ (đỉnh then chốt) cùng bậc với $n$, tức là trong một truy vấn, các đỉnh màu đỏ trên toàn bộ cây thường rất thưa. Vì vậy sẽ tốt hơn nếu độ phức tạp được quyết định bởi số đỉnh màu đỏ.

Do đó cần **nén thông tin, biến cây lớn thành một cây nhỏ**.

## Cây ảo

Từ đó xuất hiện khái niệm **cây ảo**.

Trước tiên, xét hình dạng trực quan của cây ảo.

Trong hình dưới, các đỉnh màu đỏ là đỉnh then chốt đã chọn. Các đỉnh màu đỏ và màu đen đều là đỉnh trong cây ảo. Các cạnh màu đen là cạnh trong cây ảo.

![Ví dụ cây ảo giữ lại các đỉnh then chốt và LCA](images/vtree-vtree1.svg)

![Các cạnh trong cây ảo nối các đỉnh được giữ lại](images/vtree-vtree2.svg)

![Cây ảo sau khi loại bỏ các đỉnh không cần thiết](images/vtree-vtree3.svg)

![Cấu trúc cây ảo tương ứng với cây gốc](images/vtree-vtree4.svg)

Vì LCA của hai đỉnh then chốt bất kỳ cũng mang thông tin quan trọng, cần giữ lại LCA của chúng. Vì vậy cây ảo không bắt buộc chỉ gồm các đỉnh then chốt.

Quan hệ tổ tiên - hậu duệ trong cây ảo sẽ không thay đổi. Nghĩa là nếu trong cây gốc $a$ là tổ tiên của $b$, thì trong cây ảo $a$ không thể trở thành hậu duệ của $b$.

Tuy nhiên không thể duyệt trực tiếp $O(k^2)$ mọi cặp để tính LCA. Một cách tự nhiên là sắp xếp các đỉnh then chốt theo thứ tự DFS, sau đó tính LCA cho từng cặp đỉnh then chốt kề nhau (kề nhau nghĩa là trong dãy đã sắp xếp, trị tuyệt đối của chênh lệch chỉ số bằng $1$) và thêm LCA đó vào cây ảo.

Bước tiếp theo là xây dựng cây ảo.

Trước khi đưa ra cách làm, cần xác nhận một tính chất: trong cây ảo, chỉ cần bảo đảm quan hệ tổ tiên - hậu duệ không thay đổi thì có thể thêm các đỉnh khác khi cần.

Nghĩa là nếu muốn, có thể thêm tất cả đỉnh của cây gốc vào cây ảo mà không làm sai đáp án, dù cách đó sẽ quá chậm.

Do đó, để tiện xử lý, có thể thêm trước đỉnh số $1$ vào cây ảo, và việc này không ảnh hưởng đến đáp án.

### Cách xây dựng thứ nhất: sắp xếp hai lần + nối cạnh bằng LCA

Vì LCA của nhiều đỉnh có thể trùng nhau, không được thêm nó vào cây ảo nhiều lần.

Một cách dựng trực quan gồm các bước:

-   Sắp xếp các đỉnh then chốt theo thứ tự DFS;
-   Duyệt một lần, tính LCA của mỗi cặp đỉnh then chốt kề nhau và loại trùng;
-   Sau đó dựng cây theo quan hệ tổ tiên - hậu duệ trong cây gốc.

Trong cài đặt cụ thể, trên **dãy đỉnh then chốt**, duyệt **hai đỉnh kề nhau**, tính LCA của từng cặp và thêm vào dãy $A$.

Nhờ tính chất của thứ tự DFS, lúc này dãy $A$ đã chứa **tất cả đỉnh trong cây ảo**, nhưng có thể có phần tử lặp.

Vì vậy sắp xếp dãy $A$ theo thứ tự DFS **tăng dần và loại trùng**.

Cuối cùng, trên dãy $A$, duyệt hai **đỉnh** $x,y$ **kề nhau**, tính LCA của chúng và nối cạnh $\operatorname{LCA}(x,y),y$; sau bước này cây ảo đã được xây xong.

Tại sao nối $\operatorname{LCA}(x,y)$ với $y$ lại không bị thừa hay thiếu?

??? note "Chứng minh"
    Nếu $x$ là tổ tiên của $y$, thì nối trực tiếp $x$ đến $y$. Do thứ tự DFS bảo đảm thứ tự DFS của $x$ và $y$ kề nhau, trên đường đi từ $x$ đến $y$ không có đỉnh then chốt nào.
    
    Nếu $x$ không phải tổ tiên của $y$, thì xem $\operatorname{LCA}(x,y)$ là tổ tiên của $y$. Theo trường hợp trên, cũng có thể chứng minh trên đường đi từ $\operatorname{LCA}(x,y)$ đến $y$ không có đỉnh then chốt nào.
    
    Vì vậy nối $\operatorname{LCA}(x,y)$ với $y$ sẽ không bỏ sót và cũng không lặp lại.
    
    Ngoài ra, việc đỉnh đầu tiên không được một đỉnh nào nối tới có ảnh hưởng không? Không, vì đỉnh đầu tiên chắc chắn là gốc của cây này, nên tổng số cạnh là $m-1$.

Vì cần ít nhất hai đỉnh then chốt mới phát sinh một đỉnh phụ, cộng thêm một đỉnh gốc, số đỉnh của cây ảo không vượt quá hai lần số đỉnh then chốt.

Độ phức tạp thời gian là $O(m\log n)$, trong đó $m$ là số đỉnh then chốt, $n$ là tổng số đỉnh.

#### Cài đặt

```cpp
int dfn[MAXN];
int h[MAXN], m, a[MAXN], len;  // Lưu các đỉnh then chốt

bool cmp(int x, int y) {
  return dfn[x] < dfn[y];  // Sắp xếp theo thứ tự dfs
}

void build_virtual_tree() {
  sort(h + 1, h + m + 1, cmp);  // Sắp xếp đỉnh then chốt theo thứ tự dfs
  for (int i = 1; i < m; ++i) {
    a[++len] = h[i];
    a[++len] = lca(h[i], h[i + 1]);  // Chèn lca
  }
  a[++len] = h[m];
  sort(a + 1, a + len + 1, cmp);  // Sắp xếp mọi đỉnh trên cây ảo theo thứ tự dfs
  len = unique(a + 1, a + len + 1) - a - 1;  // Loại trùng
  for (int i = 1, lc; i < len; ++i) {
    lc = lca(a[i], a[i + 1]);
    conn(lc, a[i + 1]);  // Nối cạnh; nếu có trọng số cạnh thì là distance(lc,a[i+1])
  }
}
```

Các bước trên đã đủ để xây dựng một cây ảo.

### Cách xây dựng thứ hai: dùng ngăn xếp đơn điệu

Cách dùng ngăn xếp đơn điệu để xây dựng cây ảo như sau.

Trước tiên cần làm rõ mục tiêu: dùng ngăn xếp đơn điệu để duy trì một chuỗi trên cây ảo.

Nghĩa là hai đỉnh kề nhau trong ngăn xếp cũng kề nhau trên cây ảo, và ngăn xếp tăng đơn điệu từ đáy đến đỉnh (tức là thứ tự DFS của các đỉnh trong ngăn xếp tăng đơn điệu). Nói cách khác, cha của một đỉnh chính là đỉnh nằm ngay bên dưới nó trong ngăn xếp.

Ban đầu, thêm đỉnh $1$ vào ngăn xếp.

Sau đó lần lượt thêm các đỉnh then chốt theo thứ tự DFS tăng dần.

Nếu LCA của đỉnh hiện tại và đỉnh trên đỉnh ngăn xếp chính là đỉnh trên đỉnh ngăn xếp, điều đó cho thấy chúng nằm trên cùng một chuỗi. Khi đó chỉ cần đưa đỉnh hiện tại vào ngăn xếp.

![Thêm đỉnh hiện tại khi LCA là đỉnh trên đỉnh ngăn xếp](./images/vtree-add1.svg)

Nếu LCA của đỉnh hiện tại và đỉnh trên đỉnh ngăn xếp không phải đỉnh trên đỉnh ngăn xếp:

![Trường hợp LCA của đỉnh hiện tại và đỉnh trên ngăn xếp khác đỉnh trên ngăn xếp](./images/vtree-add2.svg)

Khi đó, chuỗi mà ngăn xếp đơn điệu đang duy trì là:

![Chuỗi hiện tại được duy trì bởi ngăn xếp đơn điệu](./images/vtree-add3.svg)

Còn chuỗi cần biến thành là:

![Chuỗi cần thu được sau khi thêm đỉnh hiện tại](./images/vtree-add4.svg)

Khi đó chỉ cần pop các đỉnh được đánh dấu bằng đường đứt nét; trước khi pop, cần nối cạnh từ đỉnh đó đến cha của nó trong cây ảo.

![Pop các đỉnh không còn nằm trên chuỗi và nối cạnh cây ảo](./images/vtree-add5.svg)

Nếu sau khi pop mà phát hiện đỉnh trên đỉnh ngăn xếp không phải LCA, cần đưa LCA vào ngăn xếp.

Sau đó đưa đỉnh hiện tại vào ngăn xếp.

Dưới đây là một ví dụ cụ thể. Giả sử cần lập cây ảo cho các đỉnh số 4, 6 và 7 trên cây sau:

![Cây gốc trong ví dụ xây cây ảo cho các đỉnh 4, 6 và 7](./images/vtree-construction1.svg)

Các bước như sau:

-   Sắp xếp 3 đỉnh then chốt $6,4,7$ theo thứ tự DFS, được dãy $[4,6,7]$.
-   Đưa $1$ vào ngăn xếp.

![Khởi tạo ngăn xếp với đỉnh gốc 1](./images/vtree-construction2.svg)

Dùng đỉnh màu đỏ để biểu thị các đỉnh đang nằm trong ngăn xếp, và đỉnh màu xanh lam nhạt để biểu thị các đỉnh đã bị pop khỏi ngăn xếp.

-   Lấy phần tử đầu tiên trong dãy làm đỉnh hiện tại, tức là $4$. Lấy tiếp phần tử trên đỉnh ngăn xếp, là $1$. Tính LCA của $1$ và $4$: $LCA(1,4)=1$.
-   Vì $LCA(1,4)=$ phần tử trên đỉnh ngăn xếp, hai đỉnh này nằm trên một chuỗi của cây ảo; do đó đưa trực tiếp đỉnh hiện tại $4$ vào ngăn xếp. Ngăn xếp hiện tại là $4,1$.

![Đưa đỉnh 4 vào ngăn xếp](./images/vtree-construction3.svg)

-   Lấy phần tử thứ hai trong dãy làm đỉnh hiện tại, là $6$. Lấy tiếp phần tử trên đỉnh ngăn xếp, là $4$. Tính LCA của $6$ và $4$: $LCA(6,4)=1$.
-   Vì $LCA(6,4)\neq$ phần tử trên đỉnh ngăn xếp, chuyển sang bước xử lý pop.
-   Trong bước xử lý pop, thứ tự DFS của đỉnh trên đỉnh ngăn xếp $4$ lớn hơn thứ tự DFS của $LCA(6,4)$, nhưng thứ tự DFS của đỉnh thứ hai từ trên xuống (đỉnh nằm ngay dưới đỉnh ngăn xếp) $1$ bằng LCA (thứ tự DFS bằng nhau nghĩa là hai đỉnh cũng bằng nhau). Điều này nghĩa là LCA đã nằm trong ngăn xếp, nên nối trực tiếp cạnh $1\to4$, tức là cạnh từ LCA đến phần tử trên đỉnh ngăn xếp, rồi pop $4$ khỏi ngăn xếp.

![Nối cạnh 1 đến 4 rồi pop đỉnh 4](./images/vtree-construction4.svg)

-   Kết thúc bước xử lý pop, đưa $6$ vào ngăn xếp. Ngăn xếp hiện tại là $6,1$.

![Đưa đỉnh 6 vào ngăn xếp](./images/vtree-construction5.svg)

-   Lấy phần tử thứ ba trong dãy làm đỉnh hiện tại, là $7$. Lấy tiếp phần tử trên đỉnh ngăn xếp, là $6$. Tính LCA của $7$ và $6$: $LCA(7,6)=3$.
-   Vì $LCA(7,6)\neq$ phần tử trên đỉnh ngăn xếp, chuyển sang bước xử lý pop.
-   Trong bước xử lý pop, thứ tự DFS của đỉnh trên đỉnh ngăn xếp $6$ lớn hơn thứ tự DFS của $LCA(7,6)$, nhưng thứ tự DFS của đỉnh thứ hai từ trên xuống (đỉnh nằm ngay dưới đỉnh ngăn xếp) $1$ nhỏ hơn LCA. Điều này nghĩa là LCA chưa từng vào ngăn xếp, nên nối trực tiếp cạnh $3\to6$, tức là cạnh từ LCA đến phần tử trên đỉnh ngăn xếp. Pop $6$ khỏi ngăn xếp, đồng thời đưa $LCA(6,7)$ vào ngăn xếp.
-   Kết thúc bước xử lý pop, đưa $7$ vào ngăn xếp. Ngăn xếp hiện tại là $1,3,7$.

![Thêm LCA 3 và đưa đỉnh 7 vào ngăn xếp](./images/vtree-construction6.svg)

-   Khi 3 đỉnh trong dãy đều đã được đưa vào ngăn xếp, thoát vòng lặp.
-   Khi đó trong ngăn xếp còn 3 đỉnh: $1,3,7$. Chúng nằm trên một chuỗi, nên nối trực tiếp các cạnh $1\to3$ và $3\to7$.
-   Cây ảo đã được xây xong!

![Nối các cạnh còn lại trên chuỗi trong ngăn xếp](./images/vtree-construction7.svg)

Tiếp theo xóa các đỉnh chưa từng vào ngăn xếp (các đỉnh không phải màu xanh lam nhạt), cây ảo tương ứng có dạng như sau:

![Cây ảo cuối cùng của ví dụ](./images/vtree-construction8.svg)

Quá trình cài đặt có một số chi tiết cần xử lý, chẳng hạn nếu dùng danh sách kề để lưu cây ảo thì cần xóa danh sách kề. Việc xóa toàn bộ danh sách kề trực tiếp sẽ rất chậm, vì vậy chỉ cần **khi một phần tử chưa từng vào ngăn xếp được đưa vào ngăn xếp, xóa danh sách kề ứng với phần tử đó**.

Độ phức tạp thời gian cũng là $O(m\log n)$ (vì có sắp xếp), trong đó $m$ là số đỉnh then chốt, $n$ là tổng số đỉnh.

#### Cài đặt

Mã C++ xây dựng cây ảo có thể viết như sau:

???+ note "Cài đặt mã"
    ```cpp
    bool cmp(const int x, const int y) { return id[x] < id[y]; }
    
    void build() {
      sort(h + 1, h + k + 1, cmp);
      sta[top = 1] = 1, g.sz = 0, g.head[1] = -1;
      // Đưa đỉnh số 1 vào ngăn xếp, xóa danh sách kề của đỉnh số 1,
      // và đặt số cạnh trong danh sách kề về 0
      for (int i = 1, l; i <= k; ++i)
        if (h[i] != 1) {
          // Nếu đỉnh số 1 là đỉnh then chốt thì không thêm lặp
          l = lca(h[i], sta[top]);
          // Tính LCA của đỉnh hiện tại và đỉnh trên đỉnh ngăn xếp
          if (l != sta[top]) {
            // Nếu LCA khác phần tử trên đỉnh ngăn xếp, đỉnh hiện tại không
            // nằm trên chuỗi mà ngăn xếp hiện tại đang lưu
            while (id[l] < id[sta[top - 1]])
              // Khi thứ tự DFS của đỉnh thứ hai từ trên xuống lớn hơn thứ tự DFS của LCA
              g.push(sta[top - 1], sta[top]), top--;
            // Nối và pop phần chuỗi không trùng với chuỗi chứa đỉnh hiện tại
            if (id[l] > id[sta[top - 1]])
              // Nếu LCA không bằng đỉnh thứ hai từ trên xuống (dấu lớn hơn về bản
              // chất tương đương với dấu không bằng)
              g.head[l] = -1, g.push(l, sta[top]), sta[top] = l;
            // LCA vào ngăn xếp lần đầu: xóa danh sách kề của nó, nối cạnh,
            // pop phần tử trên đỉnh ngăn xếp, rồi đưa LCA vào ngăn xếp
            else
              g.push(l, sta[top--]);
            // LCA chính là đỉnh thứ hai từ trên xuống, pop trực tiếp phần tử trên đỉnh
            // ngăn xếp
          }
          g.head[h[i]] = -1, sta[++top] = h[i];
          // Đỉnh hiện tại luôn vào ngăn xếp lần đầu, xóa danh sách kề rồi
          // đưa vào ngăn xếp
        }
      for (int i = 1; i < top; ++i)
        g.push(sta[i], sta[i + 1]);  // Nối chuỗi cuối còn lại
      return;
    }
    ```

Sau các bước trên, ta đã có cách xây dựng cây ảo.

Với bài Cuộc chiến tiêu hao, chỉ cần chạy DP đã nói lúc đầu trên cây ảo. Cây ảo đã loại bỏ các đỉnh không then chốt không cần thiết. Vẫn xét mọi con $v$ của $i$:

-   Nếu $v$ không phải đỉnh then chốt: $Dp(i)=Dp(i) + \min \{Dp(v),w(i,v)\}$
-   Nếu $v$ là đỉnh then chốt: $Dp(i)=Dp(i) + w(i,v)$

Từ đó bài này được giải quyết gọn gàng.

## Bài tập đề xuất

-   [SDOI2011 - Cuộc chiến tiêu hao](https://www.luogu.com.cn/problem/P2495)
-   [HEOI2014 - Công trình lớn](https://www.luogu.com.cn/problem/P4103)
-   [CF613D Kingdom and its Cities](http://codeforces.com/contest/613/problem/D/)
-   [HNOI2014 - Cây thế giới](https://www.luogu.com.cn/problem/P3233)
