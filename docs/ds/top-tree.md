author:F7487

<span id="self-adjusting-top-tree"></span>
## Top tree tự điều chỉnh (self-adjusting top tree)

### Giới thiệu

Top tree tự điều chỉnh (Self-Adjusting Top Tree, viết tắt là SATT) là một cấu trúc dữ liệu dựa trên lý thuyết top tree để duy trì rừng động hoàn toàn, được Tarjan và Werneck đề xuất năm 2005 trong bài báo Self-Adjusting Top Trees.

Top tree tự điều chỉnh có thể thực hiện các thao tác cập nhật/truy vấn trên đường đi, cập nhật/truy vấn trên cây con, cũng như tìm kiếm phi cục bộ trong bất kỳ cây nào của rừng.

Splay Tree là nền tảng của SATT, nhưng Splay Tree dùng trong SATT khác Splay thông thường ở một số chi tiết, vì nó được mở rộng thêm.

### Đặt vấn đề

Duy trì một rừng, hỗ trợ các thao tác sau:

-   Xóa hoặc thêm một cạnh, bảo đảm trước và sau thao tác vẫn là một rừng.

-   Cập nhật trọng số trên một đường đi đơn trong một cây.

-   Cập nhật trọng số của cây con gốc tại một đỉnh.

-   Truy vấn tổng trọng số trên một đường đi đơn trong một cây.

-   Truy vấn tổng trọng số của cây con gốc tại một đỉnh.

### Co rút cây

Với một cây bất kỳ, có thể dùng lý thuyết **co rút cây** để co nó thành một cạnh.

Cụ thể, co rút cây có hai thao tác cơ bản: **nén** (Compress) và **gom lá** (Rake). Thao tác nén chọn một đỉnh $x$ có bậc $2$; gọi hai đỉnh kề với $x$ là $y$ và $z$, rồi nối một cạnh mới $yz$. Thông tin của đỉnh $x$, cạnh $xz$ và cạnh $xy$ được lưu vào $yz$, sau đó các đối tượng cũ bị xóa. Minh họa như hình dưới.

![](./images/top-tree1.svg)

Thao tác gom lá chọn một đỉnh $x$ có bậc $1$, đồng thời đỉnh $y$ kề với $x$ phải có bậc lớn hơn $1$. Gọi một đỉnh kề khác của $y$ là $z$, rồi đưa thông tin của đỉnh $x$ và cạnh $xy$ vào cạnh $yz$, sau đó xóa chúng. Minh họa như hình dưới.

![](./images/top-tree2.svg)

Có thể chứng minh rằng mọi cây đều co được thành một cạnh chỉ bằng các thao tác nén và gom lá, như hình dưới.

![](./images/top-tree3.svg)

### Cụm

Để diễn đạt thuận tiện, gọi cây ban đầu trước mọi thao tác là $T$. Sau khi thực hiện một số thao tác co rút cây trên $T$ (cũng có thể không thực hiện thao tác nào), gọi cây thu được là $T_x$.

Xét trạng thái thông tin được chứa trong một cạnh nào đó của một $T_x$.

Ngoài thông tin của chính cạnh đó (nếu cạnh này không tồn tại trong $T$ thì nó không có thông tin của bản thân), cạnh còn có thể chứa thông tin của các đỉnh và cạnh khác đã được gộp vào thông qua thao tác nén/gom lá. Trước hết, chọn một cạnh trong quá trình co rút cây ở hình sau và xem thông tin mà nó chứa đại diện cho những đỉnh, cạnh nào trong $T$.

![](./images/top-tree4.svg)

Trong hình, cạnh được chọn và đồ thị tương ứng đã được khoanh bằng đường đỏ.

Các đỉnh và cạnh trong $T$ mà thông tin của cạnh này đại diện tạo thành một phần liên thông. Từ đó suy ra, với bất kỳ cạnh nào trong bất kỳ $T_x$ nào, thông tin được lưu trong cạnh đó, khi nhìn tổng thể trong $T$, đều biểu diễn một đồ thị con liên thông. Đồ thị con liên thông như vậy được gọi là **cụm (Cluster)**.

Tuy nhiên, cụm là một **đồ thị con không đầy đủ**: nó chứa một số cạnh mà đầu mút của các cạnh đó không được chính cụm chứa. Do đó, các đầu mút này được gọi là **đầu mút (Endpoint)** của cụm; các đỉnh thuộc đồ thị con liên thông mà cụm chứa được gọi là **đỉnh trong (Internal Node)**; các cạnh của đồ thị con liên thông được gọi là **cạnh trong (Internal Edge)**.

Với mọi cụm, có các tính chất sau:

1.  Cụm chỉ lưu trữ và duy trì thông tin của các đỉnh trong và cạnh trong.

2.  Cụm có hai đầu mút. Hai đầu mút này chính là hai đỉnh kề với cạnh đại diện cho cụm đó trong $T_x$. Đường đi giữa hai đầu mút được gọi là **đường cụm (Cluster Path)**. Nếu hai đầu mút của một cụm lần lượt là $x$ và $y$, bên dưới dùng $C(x,y)$ để biểu diễn cụm này.

3.  Đỉnh trong chỉ kề với đầu mút hoặc đỉnh trong.

Đặc biệt, mỗi cạnh trong $T$ tự nó là một cụm độc lập (chỉ chứa thông tin của chính cạnh đó); loại cụm này được gọi là **cụm cơ sở (Base Cluster)**. Khi $T$ đã được co đến $T_x$ cuối cùng chỉ còn một cạnh, cụm do cạnh đó đại diện chứa thông tin của toàn bộ $T$ trừ hai đầu mút; cụm này được gọi là **cụm gốc (Root Cluster)**.

![](./images/top-tree5.svg)

Trong hình, các cụm cơ sở nói trên đã được đánh dấu bằng đường đỏ.

Nhìn thao tác nén/gom lá từ góc độ cụm, hai thao tác này đều "gộp hai cụm thành một", chỉ còn lại một cụm mới. Vì vậy, quá trình co rút cây cũng là quá trình gộp tất cả cụm cơ sở thành một cụm.

Do đó, hình sau là một cách biểu diễn khác của một chuỗi thao tác co rút cây.

![](./images/top-tree6.svg)

### Top tree

Bây giờ cần biểu diễn toàn bộ quá trình co rút cây của một cây nào đó.

Hai cách ở trên đều có thể biểu diễn quá trình này, nhưng khá rườm rà: nếu quá trình co rút cây có $n$ bước, cần dùng $n$ cây để biểu diễn toàn bộ quá trình.

Để có một cách biểu diễn gọn hơn cho quá trình co rút cây trên một cây, đưa vào khái niệm **top tree**.

![](./images/top-tree7.jpg)

Hình trên là một top tree dựa trên cây ban đầu và phương pháp co rút đã nêu.

Top tree có các tính chất sau:

1.  Một top tree tương ứng với một cây ban đầu và một cách co rút cây trên nó. Mỗi nút của top tree biểu diễn một cạnh nào đó trong một $T_x$, tức là một cụm được hình thành trong quá trình co rút cây. Trong hình, các nút dạng $N_x$ biểu diễn cụm được tạo bởi thao tác `compress(x)`.

2.  Một nút trong top tree có hai con, mỗi con đều đại diện cho một cụm. Cụm do nút này đại diện là cụm mới thu được bằng cách gộp hai cụm con thông qua thao tác nén hoặc gom lá.

3.  Lá của top tree là các cụm cơ sở, còn gốc của nó là cụm gốc. Vì vậy, nếu chia một top tree theo thứ tự topo thành các tầng, mỗi tầng của nó biểu diễn một cây $T_x$.

### Duy trì thông tin bằng top tree tự điều chỉnh tam bậc hóa

#### Nguyên lý

Top tree giản lược đáng kể quá trình co rút cây, từ đó cho thấy có thể duy trì thông tin trên cây bằng cách duy trì quá trình co rút cây. SATT duy trì thông tin trên cây dựa trên nguyên lý này.

Quá trình co rút cây cũng là quá trình thông tin trên cây liên tục được thêm vào. Khi thực hiện một lần `compress(x)`, thông tin của đỉnh $x$ bắt đầu xuất hiện trong một cụm kể từ thời điểm đó và ảnh hưởng đến kết quả thống kê.

Giả sử hiện tại dùng top tree để duy trì một cây $T$, mỗi đỉnh và cạnh trên cây đều có trọng số, và cần duy trì tổng trọng số của $T$.

Khi cần sửa trọng số của một đỉnh $x$ trong $T$, phải thay đổi thông tin của tất cả các nút trong top tree mà cụm của chúng chứa $x$. Cách làm này có độ phức tạp thời gian mỗi lần ở mức $O(n)$.

Tuy nhiên, nếu đỉnh được chọn xuất hiện trong rất ít nút cụm của top tree, nói cách khác làm cho thông tin của nó được thêm vào cụm càng muộn càng tốt, thì độ phức tạp mỗi thao tác sẽ được cải thiện đáng kể. Minh họa như hình.

![](./images/top-tree8.jpg)

SATT duy trì thông tin trên cây bằng cách thay đổi thứ tự mà thông tin của **một đỉnh/một đường đi** được thêm vào cụm trong quá trình co rút cây, nhằm giảm độ phức tạp mỗi lần khi thông tin đó bị sửa.

### Cấu trúc thực tế

Trước hết, gốc hóa cây ban đầu $T$ theo tầng. Sau đó xét cụm gốc của một top tree ứng với một thứ tự co rút cây nào đó. Cụm gốc có hai đầu mút; chọn một trong hai đầu mút đó làm gốc của cây ban đầu, đầu mút còn lại chọn bất kỳ.

![](./images/top-tree9.jpg)

Như hình, chọn một cặp đầu mút cho cụm gốc; khi đánh dấu cụm, cả đầu mút cũng được khoanh vào.

Từ các thao tác cơ bản của co rút cây, thông tin của các đỉnh và cạnh trên đường cụm $(j,h,c,jh,hc)$ cuối cùng được thêm vào $C(k,g)$ thông qua thao tác nén, còn thông tin của các đỉnh và cạnh không nằm trên đường cụm $(a,b,i,f,g,e,ig,\cdots)$ được thêm vào $C(k,g)$ thông qua thao tác gom lá.

Tách riêng đường cụm ra. Đây là một cây có hình dạng đặc biệt, cụ thể là một dây chuyền, và dựng một top tree cho cây này với thứ tự co rút cây bất kỳ.

![](./images/top-tree10.jpg)

Cấu trúc này được gọi là **cây nén** (Compress Tree), vì trong top tree này, hai con của bất kỳ nút nào được gộp thành cha của chúng bằng thao tác nén.

Các nút trong cây nén được gọi là **nút nén** (Compress Node). Nếu chỉ xét đường cụm hiện tại, một nút nén không phải lá đại diện cho một quá trình nén: nó gộp thông tin của con trái và con phải, rồi thêm thông tin của chính đỉnh $x$ được lưu bởi `compress(x)`. Cây nén này duy trì thông tin của đường cụm của $C(k,g)$.

Ngoài ra, trong cây nén còn đặt thêm một số ràng buộc lên top tree được sử dụng. Cây nén duy trì một dây chuyền gồm các đỉnh trong $T$ có độ sâu đôi một khác nhau. Quy định rằng thứ tự duyệt trung thứ tự của các cụm cơ sở trong cây nén phải nhất quán với độ sâu của các cạnh tương ứng trong $T$, và thứ tự trung thứ tự càng nhỏ thì độ sâu càng nông. Quan hệ của `compress(x)` ứng với mỗi đỉnh $x$ cũng tương tự.

Bây giờ xét cách duy trì thông tin không nằm trên đường cụm. Giả sử các đỉnh và cạnh không nằm trên đường cụm đã hình thành từng cụm cực đại, và các cụm cực đại này được tạo ra bằng cách gom lá lẫn nhau giữa các cụm nhỏ hơn được khoanh bằng đường xanh. Quá trình gộp một số cụm nhỏ hơn thành một cụm cực đại được biểu diễn bằng một cây tam phân. Cấu trúc này được gọi là **cây gom lá** (Rake Tree), và các nút trong cây gom lá tương ứng được gọi là **nút gom lá** (Rake Node). Mỗi nút gom lá đều đại diện cho một cụm, được hình thành bằng cách gom lá con trái và con phải vào cụm nhỏ hơn do con giữa đại diện. Cụ thể xem hình dưới; mỗi nút trong cây gom lá đều đại diện cho một cụm nhỏ hơn có cùng đầu mút trong $T$.

![](./images/top-tree11.jpg)

Trong hình, đường xanh khoanh các cụm cực đại, đường vàng khoanh các cụm nhỏ hơn.

Với các cụm nhỏ hơn đó, xử lý tương tự: chọn đường cụm cho chúng, dựng cây nén, rồi tiếp tục đệ quy như vậy. Khi đó dựng được nhiều cây nén và cây gom lá biểu diễn quá trình co rút cây.

![](./images/top-tree12.jpg)

Hình trên là cây gom lá - nén của cây ban đầu (vì mỗi nút gom lá đều nối với một cây nén, nên nó có dạng một cây gom lá nối với nhiều cây nén) và cây nén đại diện cho đường cụm gốc.

Xét việc ghép các cây này với nhau theo một cách nào đó để chúng tạo thành một tổng thể có thứ tự. Gọi $x$ là đầu mút chung của tập các cụm nhỏ nhất mà một cây gom lá đại diện. Thêm đầu mút còn lại, không phải $x$, vào các con giữa của những nút gom lá này (một tập cây nén), đồng thời vẫn giữ nguyên thứ tự trung thứ tự và các tính chất cơ bản của top tree, như hình.

![](./images/top-tree13.jpg)

Bước này tương đương với việc để thao tác gom lá thêm một đỉnh nào đó trong $T$ xảy ra trực tiếp trong cây nén. Điều này không chỉ giúp duy trì đúng thông tin của nút gom lá (chỉ cần gộp thông tin của ba con), mà còn làm cho cấu trúc cây nén đầy đủ hơn. Tiếp theo, đổi cây nén thành cây tam phân. Nếu đầu mút chung của một cây gom lá là đỉnh $x$, treo cây gom lá đó vào con giữa của `compress(x)`, như hình.

![](./images/top-tree14.jpg)

Lúc này, đỉnh `compress(x)` sau khi tam phân hóa có ý nghĩa là trước tiên gom lá con giữa vào đường cụm, rồi thống kê thông tin của con trái, con phải và đỉnh $x$.

Cuối cùng, xử lý cây nén của đường cụm gốc: giống như mọi cây nén khác, thêm hai đầu mút của nó theo thứ tự trung thứ tự, để gốc của nó lưu thông tin của toàn bộ $T$.

Như vậy, có thể dùng top tree tự điều chỉnh tam bậc hóa để duy trì thông tin của một cây.

![](./images/top-tree15.jpg)

Tóm lại, SATT có các tính chất sau:

1.  SATT gồm cây nén và cây gom lá. Cây nén là một top tree đặc biệt; cây gom lá là một cây tam phân. Cả hai đều tương ứng với quá trình co rút cây của một cây.

2.  Một nút trong cây nén có nhiều nhất ba con. Cây nén có thể thực hiện các phép xoay tương tự cây Splay, miễn là bảo đảm thứ tự trung thứ tự không đổi; khi xoay một nút, giữ nguyên con giữa của nó.

3.  Một nút trong cây gom lá luôn có một con giữa. Cây gom lá có thể thực hiện các phép xoay tương tự cây Splay, miễn là bảo đảm thứ tự trung thứ tự không đổi; khi xoay một nút, giữ nguyên con giữa của nó.

4.  Thứ tự topo của SATT phản ánh thứ tự co rút cây của cây ban đầu $T$.

Phía trên đã nhắc đến việc "thay đổi thứ tự mà thông tin của một đỉnh/một đường đi được thêm vào cụm trong quá trình co rút cây". SATT có thể thực hiện điều này.

Trong SATT có thao tác `access(x)`. Tác dụng của nó là làm cho đỉnh $x$ trở thành đầu mút không phải gốc của cụm gốc, đồng thời làm cho `compress(x)` trở thành gốc của SATT.

Thông qua thao tác `access(x)`, có thể đưa nút đại diện cho `compress(x)` trong SATT lên gốc của toàn bộ SATT với độ phức tạp khấu hao $O(\log n)$. Theo tính chất thứ tư của SATT, thứ tự thao tác `compress(x)` đã được đổi để nó được thực hiện muộn nhất, nên thông tin của đỉnh $x$ cũng được thêm vào muộn nhất. Nhờ đó, khi cần sửa thông tin của đỉnh $x$, chỉ cần cập nhật `compress(x)`.

### Cài đặt

#### Các hàm đẩy (push)

Trước hết xét việc đẩy thông tin lên, tức hàm `Pushup(x)`. Khi duy trì thông tin cho một nút nào đó của SATT, đầu tiên cần xét nút này nằm trong cây nén hay cây gom lá. Lý do đã được trình bày ở trên, nên không lặp lại nữa. Dưới đây lấy ví dụ duy trì kích thước cây con của một đỉnh.

```cpp
// ls(x) con trái của x
// rs(x) con phải của x
// ms(x) con giữa của x
// type==0 là nút nén
// type==1 là nút gom lá
void pushup(int x, int type) {
  if (type == 0)
    size[x] = size[rs(x)] + size[ms(x)] + 1;
  else
    size[x] = size[rs(x)] + size[ms(x)] + size[ls(x)];
  return;
}
```

Để truy vấn kích thước cây con của đỉnh $x$, đưa nó Access lên gốc SATT; đáp án là size của con giữa cộng $1$, vì theo phần trên, sau Access, con giữa mới là cây con thật của nó.

Tiếp theo xét việc đẩy thông tin xuống, tức hàm `Pushdown(x)`. Nếu muốn cập nhật toàn bộ một cây con trong cây ban đầu, một ý tưởng rất tự nhiên là: đưa trực tiếp nút này Access lên gốc SATT, rồi đánh dấu vào con giữa của nó. Tương tự, truy vấn cây con thì sau Access trực tiếp truy vấn con giữa.

Nếu muốn cập nhật toàn bộ một đường đi trong cây ban đầu, cần expose hai đầu mút của đường đi. Trong ngữ cảnh này, `expose(x, y)` được hiểu là làm cho đỉnh $x$ trở thành gốc của $T$, và làm cho đỉnh $y$ trở thành đầu mút còn lại của cụm gốc. Tương ứng trên SATT, lúc này cây nén của cụm gốc chính là đường đi từ $x$ đến $y$. Vì vậy, chỉ cần đánh dấu vào cây nén của cụm gốc. Tương tự, truy vấn đường đi thì expose rồi truy vấn nút gốc.

Như vậy, các thao tác trong phần đặt vấn đề đều đã có cách xử lý.

```cpp
void pushdown(int x, int type) {
  if (type == 0) {
    // xử lý đường đi
    chain[ls(x)] += chain[x] chain[rs(x)] += chain[x];
    val[ls(x)] += chain[x];
    val[rs(x)] += chain[x];
    // xử lý cây con
    subtree[ls(x)] += subtree[x];
    subtree[rs(x)] += subtree[x];
    subtree[ms(x)] += subtree[x];
    val[ls(x)] += subtree[x];
    val[rs(x)] += subtree[x];
    val[ms(x)] += subtree[x];
    subtree[x] = 0;
  } else {
    subtree[ls(x)] += subtree[x];
    subtree[rs(x)] += subtree[x];
    subtree[ms(x)] += subtree[x];
    val[ls(x)] += subtree[x];
    val[rs(x)] += subtree[x];
    val[ms(x)] += subtree[x];
    subtree[x] = 0;
  }
  return;
}

// đẩy dấu xuống
void pushall(int x, int type) {
  if (!isroot(x)) pushall(father[x], type);
  pushdown(x, type);
  return;
}
```

#### Các hàm splay

Cây gom lá và cây nén trong SATT đều có thể xoay, tức là có thể dùng Splay để duy trì chúng. Do đó có thể viết mã sau:

```cpp
// là con giữa của một nút hoặc không có cha
// ls con trái của một nút SATT
// rs con phải của một nút SATT
// ms con giữa của một nút SATT
// type==1 nằm trong cây gom lá
// type==0 nằm trong cây nén
bool isroot(int x) { return rs(father[x]) != x && ls(father[x]) != x; }

bool direction(int x) { return rs(father[x]) == x; }

void rotate(int x, int type) {
  int y = father[x], z = father[y], d = direction(x), w = son[x][d ^ 1];
  if (z) son[z][ms(z) == y ? 2 : direction(y)] = x;
  son[x][d ^ 1] = y;
  son[y][d] = w;
  if (w) father[w] = y;
  father[y] = x;
  father[x] = z;
  pushup(y, type);
  pushup(x, type);
  return;
}

void splay(int x, int type, int goal = 0) {
  pushall(x, ty);  // đẩy dấu xuống
  for (int y; y = father[x], (!isroot(x)) && y != goal; rotate(x, ty)) {
    if (father[y] != goal && (!isroot(y))) {
      rotate(direction(x) ^ diretion(y) ? x : y, type);
    }
  }
  return;
}
```

Hai hàm `direction` và `isroot` khác với Splay thông thường, vì dù nút này xoay thế nào thì con giữa của nó cũng không thay đổi.

#### Các hàm access

Ý nghĩa của `access(x)` là: xoay đỉnh $x$ lên gốc của toàn bộ SATT, làm cho đỉnh $x$ trở thành một trong hai đầu mút của cụm gốc (đầu mút còn lại là gốc của $T$), đồng thời không làm thay đổi cấu trúc của cây ban đầu và gốc của cây ban đầu.

Để thực hiện `access(x)`, trước hết xoay nó lên gốc của cây nén mà nó đang thuộc về, rồi bỏ con phải của đỉnh $x$, khiến đỉnh $x$ trở thành đầu mút của cụm tương ứng với cây nén đó.

```cpp
if (rs(x)) {
  int y = new_node();
  setfather(ms(x), y, 0);
  setfather(rs(x), y, 2);
  rs(x) = 0;
  setfather(y, x, 2);
  pushup(y, 1);
  pushup(x, 0);
}
```

Nếu lúc này đỉnh $x$ đã ở gốc thì thoát. Nếu chưa, thực hiện các bước sau để nó vượt qua cây gom lá phía trên:

1.  Đưa nút cha của nó (luôn là một nút gom lá) splay lên gốc của cây gom lá của nó.

2.  Đưa nút ông của $x$ (luôn là một nút nén) splay lên gốc của cây nén của nó.

3.  Nếu nút ông của $x$ có một con phải, hoán đổi đỉnh x với con phải của nút ông, cập nhật thông tin, rồi thoát.

4.  Nếu nút ông không có con phải, trước hết cho đỉnh $x$ trở thành con phải của nút ông. Lúc này nút cha ban đầu của đỉnh $x$ không có con giữa; theo tính chất của nút gom lá ở trên, nó không thể tồn tại. Do đó gọi hàm `Delete` để xóa nó, rồi thoát.

Hai bước 1 và 2 được gọi chung là **splay cục bộ** (Local Splay). Hai bước 3 và 4 được gọi chung là **nối tách** (Splice). Để thuận tiện, toàn bộ được viết trong hàm `Splice(x)`.

Hàm `Delete(x)` nói trên hoạt động như sau:

1.  Kiểm tra xem đỉnh $x$ sắp bị xóa có con trái hay không. Nếu có, tiếp tục xoay cây con của con trái xuống dưới đỉnh $x$ (trở thành con trái mới), rồi biến con phải (nếu có) thành con phải của con trái. Khi đó con trái của đỉnh $x$ thay thế đỉnh $x$. Điều này tương đương thao tác gộp trong Splay.

2.  Nếu không có con trái, trực tiếp cho con phải thay thế đỉnh $x$.

`Splice(x)` đã thay đổi cách chọn đầu mút của một số cụm trong cây ban đầu. Sau khi hoàn thành một lần nối tách, lấy nút cha của đỉnh $x$ làm đỉnh $x$ mới và thực hiện lần nối tách tiếp theo.

Cuối cùng, đỉnh $x$ ban đầu cần thao tác nằm ở đầu phải nhất của cây nén của cụm gốc. Chỉ cần thực hiện một lần **splay toàn cục** (Global Splay) cuối cùng để xoay nó lên gốc SATT.

```cpp
// ls con trái của một nút SATT
// rs con phải của một nút SATT
// ms con giữa của một nút SATT
// son[x][0] ls
// son[x][1] rs
// son[x][2] ms
// type==1 nằm trong cây gom lá
// type==0 nằm trong cây nén
int new_node() {
  if (top) {
    top--;
    return Stack[top + 1];
  }
  return ++tot;
}

void setfather(int x, int fa, int type) {
  if (x) father[x] = fa;
  son[fa][type] = x;
}

void Delete(int x) {
  setfather(ms(x), father[x], 1);
  if (ls(x)) {
    int p = ls(x);
    pushdown(p, 1);
    while (rs(p)) p = rs(p), pushdown(p, 1);
    splay(p, 1, x);
    setfather(rs(x), p, 1);
    setfather(p, father[x], 2);
    pushup(p, 1);
    pushup(father[x], 0);
  } else
    setfather(rs(x), father[x], 2);
  Clear(x);
}

void splice(int x) {
  // local splay
  splay(x, 1);
  int y = father[x];
  splay(y, 0);
  pushdown(x, 1);
  // splice
  if (rs(y)) {
    swap(father[ms(x)], father[rs(y)]);
    swap(ms(x), rs(y));
  } else
    Delete(x);
  pushup(x, 1);
  pushup(y, 0);
}

void access(int x) {
  splay(x, 0);
  if (rs(x)) {
    int y = new_node();
    setfather(ms(x), y, 0);
    setfather(rs(x), y, 2);
    rs(x) = 0;
    setfather(y, x, 2);
    pushup(y, 1);
    pushup(x, 0);
  }
  while (father[x]) {
    splice(father[x]);
    x = father[x];
    pushup(x, 0);
  }
  splay(x, 0)  // global splay
}
```

Nếu muốn làm cho một đỉnh trở thành gốc của cây ban đầu, Access đỉnh $x$ lên gốc SATT. Khi đó đỉnh $x$ đã là một đầu mút của cụm ở trạng thái cuối cùng. Từ tính chất duyệt trung thứ tự của cây nén, nếu đảo trái phải cây nén chứa đỉnh $x$ (hoán đổi con trái và con phải của mọi nút), thì đỉnh $x$ trở thành gốc của cây ban đầu. Trong cài đặt cụ thể, đánh dấu đảo cho đỉnh $x$, sau đó đẩy dấu xuống để thực hiện quá trình này.

```cpp
void makeroot(int x) {
  access(x);
  push_rev(x);
}
```

Như vậy `expose(x, y)` có dạng:

```cpp
void expose(int x, int y) {
  makeroot(x);
  access(y);
}
```

<span id="link-cut"></span>
### Nối và cắt (link & cut)

Bây giờ xét thao tác nối một cạnh giữa hai đỉnh không liên thông trong cây ban đầu. Trước hết cho một trong hai đỉnh, $x$, trở thành gốc của cây ban đầu, rồi xoay đỉnh còn lại $y$ lên gốc. Khi đó cần làm cho đỉnh $y$ trở thành con phải của đỉnh $x$. Sau đó treo cạnh này vào con phải của đỉnh $y$ (nếu SATT chỉ cần duy trì đỉnh thì bước này có thể bỏ qua).

```cpp
void Link(int x, int y, int z) {
  // z đại diện cho cạnh nối x, y
  access(x);
  makeroot(y);
  setfather(y, x, 1);
  setfather(z, y, 0);
  pushup(x, 0);
  pushup(y, 0);
}
```

Nguyên lý của `Cut` gần giống `Link`.

```cpp
void cut(int x, int y) {
  expose(x, y);
  clear(rs(x));  // xóa cụm cơ sở xy này
  father[x] = ls(y) = rs(x);
  pushup(y, 0);
}
```

### Mã hoàn chỉnh

??? note "[Luogu P3690, Bài mẫu: cây động](https://www.luogu.com.cn/problem/P3690)"
    ```cpp
    --8<-- "docs/ds/code/top-tree/top-tree_1.cpp"
    ```

### Chứng minh độ phức tạp thời gian của SATT

Giả sử trong một SATT có $n$ nút, hàm thế năng của trạng thái hiện tại $x$ là

$$
\varphi(x)= \sum_{i=1}^{n} r(i)
$$

trong đó $r(i) = \lceil \log_2 \text{siz}(i) \rceil$. $\text{siz}(i)$ là kích thước cây con gốc tại $i$.

Khi đó độ phức tạp khấu hao của splay trong SATT vẫn là $3n\log n + 1$, kể cả khi SATT là một cây tam phân.

Vì vậy với SATT, chỉ cần chứng minh độ phức tạp của hàm Access là đúng thì sẽ chứng minh được độ phức tạp của SATT.

Phân tích từng bước độ phức tạp khấu hao của Access.

Trước hết cần xoay đỉnh $x$ lên gốc của cây nén chứa nó. Độ phức tạp khấu hao của bước này là

$$
a \leq  3\log n +1
$$

Tiếp theo cần làm cho đỉnh $x$ không có con phải. Độ phức tạp khấu hao của bước này là

$$
a = 1 + r'(\gamma)- 0 \leq \log n +1
$$

![](./images/top-tree16.jpg)

Hình trên minh họa quá trình bỏ con phải của đỉnh $x$.

Sau đó là quá trình splay cục bộ và nối tách diễn ra luân phiên. Sau một số lần nối tách, đỉnh $x$ được xoay lên gốc SATT. Xét một cặp splay cục bộ, nối tách:

![](./images/top-tree17.jpg)

![](./images/top-tree18.jpg)

![](./images/top-tree19.jpg)

Các hình trên thể hiện quá trình thực hiện một lần nối tách đối với đỉnh $x$, chưa bao gồm phần xoay trái đỉnh $x$ cuối cùng.

Để diễn đạt thuận tiện, đặt $r_x(i)$ là giá trị $r$ của đỉnh $i$ ở trạng thái $x$.

Từ hình, thao tác từ trạng thái 1 sang trạng thái 2 (splay cục bộ đưa cha của đỉnh $x$ lên gốc cây gom lá của nó) có độ phức tạp khấu hao

$$
a \leq  3(r_2(\gamma)- r_1(\gamma))+1
$$

Từ hình, thao tác từ trạng thái 2 sang trạng thái 3 (splay cục bộ đưa nút ông của đỉnh $x$ lên gốc cây nén của nó) có độ phức tạp khấu hao

$$
a \leq  3(r_3(B)- r_2(B))+1
$$

Tập trung phân tích thao tác từ trạng thái 3 sang trạng thái 4 (nối tách):

$$
a = r_4(\gamma) -r_3(\gamma) +1
$$

Có $r_4(\gamma) \leq r_3(B)$.

Vì vậy độ phức tạp khấu hao của thao tác này là

$$
\begin{aligned}
a &\leq r_3(B)- r_3(\gamma)+1\\
&\leq 3(r_3(B)- r_3(\gamma))+1\\
\end{aligned}
$$

Tổng hợp các bước trên, độ phức tạp của một lần nối tách là

$$
a\leq 3r_3(B)+3r_3(B)+3r_2(\gamma)-3r_3(\gamma)-3r_2(B)-3r_1(\gamma)+3
$$

Gọi điểm của lần nối tách tiếp theo là $X$ (tức điểm $B$ trong trạng thái 4), giá trị $r$ của nó là $r'(X)$. Đồng thời do $r_3(\gamma),r_1(\gamma) \ge r_1(X)$, $r_3(B),r_2(\gamma) \leq r'(X)$ và $r_3(B)=r_2(B)$, nên

$$
a\leq  9(r'(X)-r(X))+3
$$

Ngoài độ phức tạp trên, trong thao tác nối tách còn có thể có phần độ phức tạp khấu hao phát sinh do `delete(x)`. Ký hiệu phần này là $a' \leq 3\log n +1$.

Tạm thời bỏ qua phần $a'$. Mỗi lần nối tách có $r'(X)$ bằng $r(X)$ của lần tiếp theo, và $r(X)$ của lần nối tách đầu tiên bằng $r(X)$ khi ban đầu xoay đỉnh $x$ lên gốc cây nén của nó. Vì vậy, với độ phức tạp của một lần `access(x)` nếu không tính `delete(x)`, có:

$$
a \leq 9(r'(x)-r(x))+ 3k + 1
$$

trong đó $k$ là số lần nối tách.

Thoạt nhìn, $a$ có thêm hạng $3k+1$, khiến độ phức tạp khấu hao dường như khó phân tích. Có thể xử lý bằng cách dùng khấu hao cho các phép xoay zig-zig/zig-zag như sau

$$
\begin{aligned}
a &\leq 3(r'(X)-r(X)) + q\\
&\leq 3(q-1)(r'(X)-r(X))
\end{aligned}
$$

Nếu tìm được đủ nhiều thao tác zig-zig, zig-zag, có thể phân bổ $3k+1$ này vào các thao tác đó để triệt tiêu nó.

Trong splay toàn cục có đủ nhiều thao tác zig-zig, zag-zig để dùng, vì số nút trong splay toàn cục lớn hơn $k$, còn số nút trên đường từ đỉnh $x$ đến gốc splay toàn cục không nhỏ hơn $k$. Nói cách khác, trong một lần `access(x)` có ít nhất $\dfrac k2$ thao tác zig-zag. Tính thêm độ phức tạp khấu hao của splay toàn cục là $a \leq 3\log n +1$, độ phức tạp khấu hao của một lần `access(x)` khi không tính `delete(x)` là

$$
\begin{aligned}
a&\leq 9(r'(X)-r(X)) + 3k + 1 + 18(r''(X)-r'(X)) -S+1 +3 \log n +1,S \ge 3k\\
a&\leq 18(r''(X)-r(X)) +2 +3\log n+1\\
a&\leq 21(r''(X)-r(X)) +3
\end{aligned}
$$

Bây giờ tính cả $a'$, viết công thức tổng cho $m$ lần thao tác `access(x)`.

$$
\sum_{i=1}^m a_i' + \sum_{i=1}^m a_i = \sum_{i=1}^m c_i + \varphi(x_n) -\varphi(x_0)
$$

Cần độ phức tạp thực tế:

$$
\begin{aligned}
\sum_{i=1}^m c_i &= \sum_{i=1}^m a_i +\sum_{i=1}^m a_i' - \varphi(x_n) +\varphi(x_0)\\
&\le \sum_{i=1}^m a_i' + 21m\log n +n\log n +3m
\end{aligned}
$$

Bản chất của thao tác `delete(x)` là xóa một nút gom lá, nhưng trong $m$ lần thao tác, nhiều nhất chỉ thêm $m$ nút gom lá. Theo định nghĩa của nút gom lá, ban đầu có nhiều nhất $n$ nút gom lá, tức tổng cộng chỉ thực hiện nhiều nhất $m+n$ lần `delete(x)`. Từ $a' \leq 3\log n +1$ suy ra

$$
\sum_{i=1}^m c_i \leq 3(m+n)\log n + 21m\log n +n\log n +4m +n
$$

Do đó đã chứng minh được độ phức tạp của Access; các hàm khác hoặc dựa trên Access, hoặc có độ phức tạp thời gian mỗi lần là hằng số, nên cũng chứng minh được độ phức tạp của SATT.

Nhân tiện, nếu giống LCT mà bỏ qua quá trình splay toàn cục, đổi thành trong mỗi lần nối tách thì trực tiếp xoay đỉnh cần Access một lần, độ phức tạp thời gian vẫn đúng. Theo đo thực nghiệm, phiên bản bỏ splay toàn cục nhanh hơn rất nhiều và có thể chạy ngang ngửa LCT trên Luogu P3690.

### Bài tập ví dụ

#### Ví dụ 1

???+ note "[CEOI 2019 Dynamic Diameter](https://loj.ac/p/3163)"
    Cho một cây có $n$ nút, mỗi cạnh có trọng số cạnh. Có $q$ lần cập nhật, mỗi lần sửa trọng số của một cạnh và truy vấn đường kính của cây. Bắt buộc xử lý trực tuyến.

Duy trì đường kính động. Sau khi dựng SATT, chỉ cần duy trì đáp án của mỗi nút trong `Pushup(x)`, rồi cuối cùng truy vấn đáp án của nút gốc (tức đường kính của cả cây).

```cpp
void pushup(int x, int op) {
  if (op == 0) {
    // là nút nén
    len[x] = len[ls(x)] + len[rs(x)];
    diam[x] = maxs[ls(x)][1] + maxs[rs(x)][0];
    diam[x] =
        max(diam[x], max(maxs[ls(x)][1], maxs[rs(x)][0]) + maxs[ms(x)][0]);
    diam[x] = max(diam[x], max(max(diam[ls(x)], diam[rs(x)]), diam[ms(x)]));
    maxs[x][0] =
        max(maxs[ls(x)][0], len[ls(x)] + max(maxs[ms(x)][0], maxs[rs(x)][0]));
    maxs[x][1] =
        max(maxs[rs(x)][1], len[rs(x)] + max(maxs[ms(x)][0], maxs[ls(x)][1]));
  } else {
    // là nút gom lá
    diam[x] = maxs[ls(x)][0] + maxs[rs(x)][0];
    diam[x] =
        max(diam[x], maxs[ms(x)][0] + max(maxs[ls(x)][0], maxs[rs(x)][0]));
    diam[x] = max(max(diam[x], diam[ms(x)]), max(diam[ls(x)], diam[rs(x)]));
    maxs[x][0] = max(maxs[ms(x)][0], max(maxs[ls(x)][0], maxs[rs(x)][0]));
  }
  return;
}
```

Trong đó $diam$ là đáp án của nút hiện tại, tức đường kính của cụm do nút này đại diện. $len$ biểu diễn độ dài đường cụm của nút nén hiện tại, còn $maxs_{0/1}$ biểu diễn khoảng cách lớn nhất từ nút nén đến đỉnh trong và đầu mút của cụm khi không chọn con đường cụm/không chọn cha. Nếu là nút gom lá thì chỉ lưu $maxs_0$, tức khoảng cách lớn nhất từ đầu mút trên của cụm hiện tại đến đỉnh trong và đầu mút của cụm. Mỗi lần truy vấn chỉ cần lấy $diam$ của nút gốc SATT.

Cần sửa `Pushrev(x)` đôi chút.

```cpp
void pushrev(int x) {
  if (!x) return;
  r[x] ^= 1;
  swap(ls(x), rs(x));
  swap(maxs[x][0], maxs[x][1]);
}
```

#### Ví dụ 2

???+ note "[CSP-S 2019, Trọng tâm của cây](https://loj.ac/p/3213)"
    Cho một cây. Với mỗi cạnh của cây, xóa riêng cạnh đó rồi lấy hai cây con tách ra; cần tính tổng các chỉ số trọng tâm của hai cây con đó, cộng trên mọi cạnh.

Nếu có thể duy trì động trọng tâm của cây trong $O(\log n)$, bài này sẽ được giải quyết.

SATT hỗ trợ duy trì động trọng tâm của cây trong $O(\log n)$. Để làm được điều này cần **tìm kiếm phi cục bộ** (Non-local Search).

Với một tính chất trên cây, nếu một đỉnh/một cạnh có tính chất đó trong toàn cây và cũng có tính chất đó trong mọi cây con chứa nó, tính chất này được gọi là **cục bộ (Local)**; ngược lại gọi là **phi cục bộ (Non-local)**. Thông tin cục bộ thường có thể duy trì bằng `pushup(x)`.

Ví dụ, giá trị trọng số nhỏ nhất là cục bộ, vì nếu một đỉnh/một cạnh có trọng số nhỏ nhất trong toàn cây thì trong mọi cây con chứa nó, nó cũng có trọng số nhỏ nhất. Còn trọng số nhỏ thứ hai là phi cục bộ.

$diam$ được duy trì ở trên cũng là thông tin cục bộ.

Quay lại vấn đề chính, trọng tâm là thông tin phi cục bộ, không thể duy trì bằng `pushup(x)` đơn giản. Xét cách tìm kiếm trên SATT:

Tìm kiếm bắt đầu từ nút gốc của SATT, tức cụm gốc. Trọng tâm có một tính chất rất tốt: nếu một phía của một cạnh có số đỉnh lớn hơn hoặc bằng phía còn lại, thì phía đó của cạnh có ít nhất một trọng tâm (trọng tâm có thể có hai).

Gọi $sum$ là số đỉnh của một cụm, $maxs$ là giá trị $sum$ lớn nhất trong các con giữa của mọi nút gom lá thuộc một cây gom lá.

```cpp
void pushup(int x, int op) {
  if (op == 0) {
    // là nút nén
    sum[x] = sum[ls(x)] + sum[rs(x)] + sum[ms(x)] + 1;
  } else {
    // là nút gom lá
    maxs[x] = max(maxs[ls(x)], max(maxs[rs(x)], sum[ms(x)]));
    sum[x] = sum[ls(x)] + sum[rs(x)] + sum[ms(x)];
  }
}
```

![](./images/top-tree20.jpg)

Hình trên là SATT khi thực hiện tìm kiếm phi cục bộ và cây ban đầu $T$ tương ứng.

Thực hiện các phép so sánh sau:

1.  So sánh giá trị $sum$ của cụm $compress(Y)$ với giá trị $sum$ của hợp giữa cụm $compress(Z)$, cụm $A$ và đỉnh $X$ (tạm gọi là cụm $\alpha$). Nếu $sum$ của $compress(Y)$ lớn hơn hoặc bằng vế sau, nghĩa là có ít nhất một trọng tâm trong cây con của $compress(Y)$, đệ quy tìm kiếm vào $compress(Y)$. Nếu hai vế bằng nhau, đỉnh $X$ cũng là một trọng tâm và cần ghi nhận.

2.  So sánh giá trị $sum$ của cụm $compress(Z)$ với giá trị $sum$ của hợp giữa cụm $compress(Y)$, cụm $A$ và đỉnh $X$ (tạm gọi là cụm $\beta$). Nếu $sum$ của $compress(Z)$ lớn hơn hoặc bằng vế sau, nghĩa là có ít nhất một trọng tâm trong cây con của $compress(Z)$, đệ quy tìm kiếm vào $compress(Z)$. Nếu hai vế bằng nhau, đỉnh $X$ cũng là một trọng tâm và cần ghi nhận.

3.  So sánh giá trị $sum$ của cụm nhỏ hơn có $sum$ lớn nhất trong cây gom lá là con giữa của điểm $x$ với giá trị $sum$ của hợp giữa cụm $compress(Y)$, cụm $A$, đỉnh $X$ và các cụm nhỏ hơn còn lại (tạm gọi là cụm $Y$). Nếu giá trị $sum$ của cụm nhỏ hơn đó lớn hơn hoặc bằng vế sau, nghĩa là có ít nhất một trọng tâm trong cây con của cụm nhỏ hơn đó, đệ quy tìm kiếm vào nó. Nếu hai vế bằng nhau, đỉnh $X$ cũng là một trọng tâm và cần ghi nhận.

4.  Nếu các phép so sánh trên đều không đệ quy, thì đỉnh $X$ là một trọng tâm; ghi nhận rồi thoát.

Bước tìm kiếm đầu tiên là đúng. Vấn đề là các bước sau cần tìm như thế nào.

Giả sử đệ quy vào $Y$. Lúc này thông tin mà $Y$ lưu không đầy đủ, vì $compress(Y)$ chỉ lưu thông tin của chính cụm đó, trong khi cần trọng tâm của cả cây. Cách giải quyết là ghi lại thông tin của cụm trước đó, rồi khi so sánh tính toán tại đỉnh $Y$, gộp thông tin của cụm trước với thông tin của chính đỉnh $Y$. Cài đặt cụ thể như sau:

```cpp
void non_local_search(int x, int lv, int rv, int op) {
  // lv và rv đều là thông tin của cụm trước đó trong tìm kiếm
  if (!x) return;
  psd(x, 0);
  if (op == 0) {
    if (maxs[ms(x)] >=
        sum[ms(x)] - maxs[ms(x)] + sum[rs(x)] + sum[ls(x)] + lv + 1 + rv) {
      if (maxs[ms(x)] ==
          sum[ms(x)] - maxs[ms(x)] + sum[rs(x)] + sum[ls(x)] + lv + 1 + rv) {
        if (ans1)
          ans2 = x;
        else
          ans1 = x;
      }
      non_local_search(
          ms(x),
          sum[ms(x)] - maxs[ms(x)] + sum[rs(x)] + sum[ls(x)] + 1 + lv + rv, 0,
          1);
      return;
    }
    if (ss[rs(x)] + rv >= ss[ms(x)] + ss[ls(x)] + lv + 1) {
      if (ss[rs(x)] + rv == ss[ms(x)] + ss[ls(x)] + lv + 1) {
        if (ans1)
          ans2 = x;
        else
          ans1 = x;
      }
      non_local_search(rs(x), sum[ms(x)] + 1 + sum[ls(x)] + lv, rv, 0);
      return;
    }
    if (sum[ls(x)] + lv >= sum[ms(x)] + sum[rs(x)] + 1 + rv) {
      if (sum[ls(x)] + lv == sum[ms(x)] + sum[rs(x)] + 1 + rv) {
        if (ans1)
          ans2 = x;
        else
          ans1 = x;
      }
      non_local_search(ls(x), lv, rv + sum[ms(x)] + 1 + sum[rs(x)], 0);
      return;
    }
  } else {
    if (maxs[ls(x)] == maxs[x]) {
      non_local_search(ls(x), lv, rv, 1);
      return;
    }
    if (maxs[rs(x)] == maxs[x]) {
      non_local_search(rs(x), lv, rv, 1);
      return;
    }
    non_local_search(ms(x), lv, rv, 0);
    return;
  }
  if (ans1)
    ans2 = x;
  else
    ans1 = x;
}
```

??? note "Mã ví dụ"
    ```cpp
    --8<-- "docs/ds/code/top-tree/top-tree_2.cpp"
    ```

### Tài liệu tham khảo

1.  Robert E. Tarjan and Renato F. Werneck. 2005. Self-adjusting top trees. In Proceedings of the sixteenth annual ACM-SIAM symposium on Discrete algorithms (SODA '05). Society for Industrial and Applied Mathematics, USA, 813-822. DOI 10.5555/1070432.1070547

2.  [Blog của negiizhao](https://negiizhao.blog.uoj.ac/blog/4912)
