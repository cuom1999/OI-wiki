author: hsfzLZH1, Ir1d, JosephusW

k-D Tree(KDT, k-Dimension Tree) là một cấu trúc dữ liệu có thể **xử lý hiệu quả thông tin trong không gian k chiều**.

Khi số nút $n$ lớn hơn rất nhiều so với $2^k$, hiệu quả thời gian khi áp dụng k-D Tree là rất tốt.

Trong các bài toán thi lập trình, thường có $k=2$. Khi phân tích độ phức tạp thời gian trên trang này, ta xem $k$ là hằng số.

## Xây cây

k-D Tree có hình thái của cây tìm kiếm nhị phân. Mỗi nút trên cây tìm kiếm nhị phân tương ứng với một điểm trong không gian k chiều. Các điểm trong mỗi cây con đều nằm trong một siêu hình hộp chữ nhật k chiều, và tất cả các điểm bên trong siêu hình hộp chữ nhật đó cũng đều nằm trong cây con này.

Giả sử ta đã biết tọa độ của $n$ điểm phân biệt trong không gian k chiều. Để xây chúng thành một k-D Tree, thực hiện như sau:

1.  Nếu siêu hình hộp chữ nhật hiện tại chỉ có một điểm, trả về điểm đó.

2.  Chọn một chiều, rồi chia siêu hình hộp chữ nhật hiện tại thành hai siêu hình hộp chữ nhật theo chiều đó.

3.  Chọn điểm cắt: trên chiều đã chọn, chọn một điểm. Những điểm có giá trị ở chiều này nhỏ hơn điểm đó được đưa vào một siêu hình hộp chữ nhật, tức cây con trái; các điểm còn lại được đưa vào siêu hình hộp chữ nhật kia, tức cây con phải.

4.  Lấy điểm đã chọn làm gốc của cây con này, đệ quy xây cây con trái và cây con phải trên hai siêu hình hộp chữ nhật đã tách ra, đồng thời duy trì thông tin của cây con.

Để dễ hiểu hơn, xét ví dụ khi $k=2$.

![](./images/kdt1.jpg)

Hình thái k-D Tree được xây ra có thể như sau:

![](./images/kdt2.jpg)

Trong đó, tọa độ trên mỗi nút của cây là tọa độ của điểm chia được chọn; ký hiệu $x$ hoặc $y$ bên cạnh nút không phải lá là chiều cắt được chọn.

Độ phức tạp của cách làm này chưa được bảo đảm. Với bước $2,3$, ta đưa ra hai tối ưu:

1.  Luân phiên chọn trong $k$ chiều, để bảo đảm trong bất kỳ $k$ tầng liên tiếp nào thì mỗi chiều đều được dùng để cắt.
2.  Mỗi lần chọn điểm cắt trên một chiều, chọn **trung vị** trên chiều đó, nhờ đó kích thước hai cây con trái và phải sau mỗi lần chia sẽ cân bằng nhất có thể.

Có thể thấy sau khi dùng tối ưu $2$, chiều cao của k-D Tree được xây ra nhiều nhất là $\log n+O(1)$.

Lúc này, nút thắt về độ phức tạp thời gian khi xây k-D Tree nằm ở việc nhanh chóng chọn ra trung vị trên một chiều, rồi đặt các phần tử có giá trị trên chiều đó nhỏ hơn trung vị sang bên trái trung vị, các phần tử còn lại sang bên phải. Nếu mỗi lần đều dùng hàm `sort` để sắp xếp theo chiều đó, độ phức tạp thời gian là $O(n\log^2 n)$. Thực ra, việc tìm trung vị trong $n$ phần tử một lần và đặt trung vị vào đúng vị trí sau khi sắp xếp có thể đạt độ phức tạp $O(n)$.

Ta cùng nhắc lại ý tưởng của quicksort. Mỗi lần ta chọn ra một số, đặt các số nhỏ hơn nó sang bên trái, các số lớn hơn nó sang bên phải, bảo đảm số đó nằm ở đúng vị trí sau khi sắp xếp, rồi đệ quy sắp xếp các giá trị ở bên trái và bên phải. Độ phức tạp kỳ vọng của cách này là $O(n\log n)$. Nhưng vì k-D Tree chỉ yêu cầu trung vị nằm ở đúng vị trí sau khi sắp xếp, ta chỉ cần đệ quy sắp xếp **một phía** chứa trung vị. Có thể chứng minh độ phức tạp kỳ vọng khi đó là $O(n)$. Trong thư viện `algorithm`, có hàm `nth_element()` hiện thực chức năng tương tự. Để tìm giá trị nằm ở vị trí `s[mid]` sau khi các giá trị giữa `s[l]` và `s[r]` được sắp xếp theo quy tắc `cmp`, đồng thời bảo đảm các giá trị bên trái `s[mid]` nhỏ hơn `s[mid]` và các giá trị bên phải lớn hơn `s[mid]`, chỉ cần viết `nth_element(s+l,s+mid,s+r+1,cmp)`.

Nhờ ý tưởng này, độ phức tạp thời gian để xây k-D Tree là $O(n\log n)$.

## Thao tác trên không gian nhiều chiều

Khi truy vấn một số thông tin của tất cả các điểm trong vùng hình chữ nhật nhiều chiều, ta ghi lại giá trị tọa độ lớn nhất và nhỏ nhất trên từng chiều trong cây con của mỗi nút. Nếu hình chữ nhật tương ứng với cây con hiện tại không giao với hình chữ nhật cần truy vấn, không tiếp tục tìm kiếm trong cây con đó; nếu hình chữ nhật tương ứng với cây con hiện tại nằm hoàn toàn trong hình chữ nhật cần truy vấn, trả về tổng trọng số của tất cả các điểm trong cây con hiện tại; ngược lại, xét điểm hiện tại có nằm trong hình chữ nhật cần truy vấn hay không, cập nhật đáp án rồi đệ quy tìm đáp án trong cây con trái và phải.

??? note "Cài đặt"
    ```cpp
    int query(int p) {
      if (!p) return 0;
      bool flag{false};
      for (int k : {0, 1}) flag |= (!(l.x[k] <= t[p].L[k] && t[p].R[k] <= h.x[k]));
      if (!flag) return t[p].sum;
      for (int k : {0, 1})
        if (t[p].R[k] < l.x[k] || h.x[k] < t[p].L[k]) return 0;
      int ans{0};
      flag = false;
      for (int k : {0, 1}) flag |= (!(l.x[k] <= t[p].x[k] && t[p].x[k] <= h.x[k]));
      if (!flag) ans = t[p].v;
      return ans += query(t[p].l) + query(t[p].r);
    }
    ```

### Phân tích độ phức tạp

Trước hết xét trường hợp hai chiều. Khi truy vấn hình chữ nhật $R$, ta chia các nút trên k-D Tree thành ba loại:

1.  Không giao với $R$.
2.  Bị $R$ chứa hoàn toàn.
3.  Bị $R$ chứa một phần.

Rõ ràng độ phức tạp của một truy vấn là số nút loại $3$. Chú ý rằng hình chữ nhật của các nút loại ba hoặc chứa hoàn toàn $R$, hoặc không chứa lẫn nhau. Trường hợp trước hiển nhiên chỉ có $O(h)=O(\log n)$ nút, nên bây giờ ta phân tích số lượng của trường hợp sau.

Trước hết, ta có thể dịch tất cả các cạnh của hình chữ nhật đi một lượng $\epsilon$, sao cho hình chữ nhật truy vấn không đi qua bất kỳ điểm nào đã có. Việc này hiển nhiên không ảnh hưởng đến tập điểm mà truy vấn hình chữ nhật bao phủ.

Chú ý rằng với hình chữ nhật tương ứng với các nút loại $3$ không chứa lẫn nhau, chắc chắn có một cạnh của $R$ đi xuyên qua nó. Vì vậy ta chỉ cần tính số hình chữ nhật mà mỗi cạnh của $R$ đi qua, tức một đoạn thẳng bất kỳ nhiều nhất đi qua bao nhiêu hình chữ nhật tương ứng với các nút.

Xét một nút $u$. Nó có bốn cháu, và từ nó đến mỗi cháu đều đã chia một lần trên từng chiều trong hai chiều. Quan sát thấy rằng nếu dùng cách này để chia một hình chữ nhật thành bốn hình chữ nhật con, một đoạn thẳng song song với trục tọa độ nhiều nhất đi qua hai vùng. Nói cách khác, truy vấn xuất phát từ $u$ nhiều nhất đi xuống hai cháu mà vẫn còn điểm loại $3$. Nếu đoạn thẳng vừa khít trùng với biên chia thì chưa chắc, nhưng thao tác dịch biên hình chữ nhật truy vấn đã loại bỏ tình huống này.

Do khi xây cây, mỗi điểm là trung vị của toàn bộ cây con theo chiều chia hiện tại, kích thước cây con chắc chắn giảm một nửa. Vì vậy, nếu kích thước cây con của $u$ là $n$, ta viết được hệ thức truy hồi sau:

$$
T(n)=2T(n/4)+O(1)
$$

Theo định lý chính, $T(n)=O(\sqrt{n})$.

Mở rộng hệ thức truy hồi sang $k$ chiều, tức $T(n)=2^{k-1}T(n/2^k)+O(1)$, suy ra $T(n)=O(n^{1-\frac1k})$, với $k$ được xem là hằng số.

### Chèn/xóa

Nếu tập điểm k chiều cần duy trì là động, tức có thể chèn hoặc xóa một số điểm, lúc này tính cân bằng của k-D Tree không được bảo đảm. Do cấu trúc của k-D Tree, ta không thể hỗ trợ phép xoay; ưu tiên ngẫu nhiên tương tự FHQ Treap cũng không thể bảo đảm độ phức tạp. Với vấn đề này, có hai phương pháp duy trì khá thường gặp.

???+ note "Ghi chú"
    Nhiều thí sinh dùng cấu trúc scapegoat tree để duy trì. Tuy nhiên, chú ý rằng trong phân tích độ phức tạp vừa rồi, ta yêu cầu kích thước cây con của con phải giảm đúng một nửa, tức chiều cao cây phải là $\log n+O(1)$ một cách chặt chẽ, còn scapegoat tree chỉ thỏa mãn chiều cao $O(\log n)$, nên độ phức tạp truy vấn không được bảo đảm.

#### Tái xây dựng căn bậc hai

Khi chèn, trước hết lưu lại điểm cần chèn; cứ sau mỗi $B$ lần chèn thì tái xây dựng một lần.

Khi xóa, chỉ cần đánh dấu. Nếu yêu cầu tương đối nghiêm ngặt, có thể duy trì số lượng điểm đã bị xóa trong cây, đạt đến $B$ thì tái xây dựng.

Độ phức tạp sửa đổi trung bình là $O(n\log n/B)$, truy vấn là $O(B+n^{1-\frac1k})$. Nếu số lượng hai loại thao tác cùng bậc thì chọn $B=O(\sqrt{n\log n})$ là tối ưu, khi đó sửa đổi $O(\sqrt{n\log n})$, truy vấn $O(\sqrt{n\log n}+n^{1-\frac1k})$.

#### Nhóm nhị phân

Xét việc duy trì một số k-D Tree có kích thước là lũy thừa tự nhiên của $2$, sao cho tổng kích thước của các cây này là $n$.

Khi chèn, thêm một k-D Tree mới có kích thước $1$, rồi liên tục gộp các cây có cùng kích thước, bằng cách trải phẳng rồi tái xây dựng trực tiếp. Khi hiện thực, có thể chỉ cần tái xây dựng một lần.

Dễ thấy kích thước của các cây cần gộp chắc chắn bắt đầu từ $2^0$ và có chỉ số mũ liên tiếp. Độ phức tạp tương tự phép cộng nhị phân, là trung bình $O(n\log^2 n)$, vì bản thân việc tái xây dựng có thêm một nhân tử $\log$.

Khi truy vấn, trực tiếp truy vấn riêng trên từng cây, độ phức tạp là $O\left(\sum_{i\geq0} (\frac n{2^i})^{1-\frac1k}\right)=O(n^{1-\frac1k})$.

### Ví dụ

???+ note "[Luogu P4148 Bài toán đơn giản](https://www.luogu.com.cn/problem/P4148)"
    Trên một ma trận hai chiều $n\times n$ có giá trị ban đầu toàn là $0$, thực hiện $q$ thao tác. Mỗi thao tác thuộc một trong hai loại sau:
    
    1.  `1 x y A`: cộng $A$ vào số tại tọa độ $(x,y)$.
    2.  `2 x1 y1 x2 y2`: xuất tổng các số trong hình chữ nhật có $(x1,y1)$ là góc dưới trái và $(x2,y2)$ là góc trên phải, bao gồm cả biên hình chữ nhật.
    
    Bắt buộc online. Giới hạn bộ nhớ `20M`. Bảo đảm đáp án và tất cả đại lượng trung gian đều nằm trong phạm vi `int`.
    
    $1\le n\le 500000, 1\le q\le 200000$

Giới hạn bộ nhớ 20M loại bỏ tất cả các cấu trúc cây lồng cây, yêu cầu online bắt buộc loại bỏ CDQ divide and conquer, nên chỉ có thể dùng k-D Tree.

Dưới đây là mã tham khảo cho nhóm nhị phân.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/kdt/kdt_3.cpp"
    ```

## Truy vấn lân cận

???+ warning "Cảnh báo"
    Độ phức tạp thời gian tệ nhất của một lần truy vấn điểm gần nhất bằng k-D Tree vẫn là $O(n)$, nhưng đây vẫn là một thuật toán kiếm điểm rất tốt. Khi sử dụng cần lưu ý điều này. Phần giải thích về truy vấn lân cận ở đây chỉ nhằm tăng cường hiểu biết về cấu trúc k-D Tree.

???+ note "Ví dụ [Luogu P1429 Cặp điểm gần nhất trên mặt phẳng, bản nâng cao](https://www.luogu.com.cn/problem/P1429)"
    Cho $n$ điểm $(x_i,y_i)$ trên mặt phẳng, hãy tìm [khoảng cách Euclid](../geometry/distance.md#khoảng-cách-euclid) giữa cặp điểm gần nhất trên mặt phẳng.
    
    $2\le n\le 200000, 0\le x_i,y_i\le 10^9$

Trước hết xây 2-D Tree cho $n$ điểm này.

Duyệt từng nút. Với mỗi nút, tìm điểm khác nút đó và có khoảng cách nhỏ nhất, từ đó tính được đáp án. Nếu mỗi lần duyệt thô tất cả các nút trên 2-D Tree thì độ phức tạp thời gian là $O(n)$, nên cần cắt tỉa. Ta có thể duy trì giá trị tọa độ nhỏ nhất và lớn nhất trên từng chiều của tất cả các nút trong một cây con. Giả sử khoảng cách của cặp điểm gần nhất hiện đã tìm được là $ans$. Nếu khoảng cách **gần nhất** từ điểm truy vấn đến hình chữ nhật chứa tất cả các điểm trong cây con lớn hơn hoặc bằng $ans$, thì chắc chắn không có đáp án trong cây con này, và khi tìm kiếm ta không đi vào cây con đó.

Ngoài ra, còn có thể dùng một phương pháp tìm kiếm heuristic: nếu hai cây con của một nút đều có khả năng chứa đáp án, hãy tìm kiếm trước trong cây con gần điểm truy vấn hơn. Có thể xem **khoảng cách gần nhất từ điểm truy vấn đến hình chữ nhật tương ứng với cây con chính là hàm đánh giá của bài này**.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/kdt/kdt_1.cpp"
    ```

???+ note "Ví dụ [CQOI2016 K cặp điểm xa thứ k](https://loj.ac/problem/2043)"
    Cho $n$ điểm $(x_i,y_i)$ trên mặt phẳng, hãy tìm khoảng cách giữa cặp điểm không thứ tự xa thứ $k$ theo khoảng cách Euclid.
    
    $n\le 100000, 1\le k\le 100, 0\le x_i,y_i<2^{31}$

Tương tự ví dụ trước, bài toán chuyển từ cặp điểm gần nhất sang cặp điểm xa thứ $k$, và hàm đánh giá đổi thành khoảng cách xa nhất từ điểm truy vấn đến vùng hình chữ nhật tương ứng với cây con. Dùng một heap nhỏ để duy trì khoảng cách của $k$ cặp điểm xa nhất đã tìm được hiện tại. Nếu khoảng cách của cặp điểm vừa tìm được lớn hơn đỉnh heap, pop đỉnh heap rồi chèn khoảng cách này. Tương tự, dùng khoảng cách ở đỉnh heap để cắt tỉa.

Vì đề bài nhấn mạnh cặp điểm không thứ tự, tức sau khi hoán đổi thứ tự hai điểm vẫn là cùng một cặp điểm, mỗi cặp điểm có thứ tự sẽ bị tính hai lần. Vì vậy $k$ đọc vào phải nhân với $2$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/kdt/kdt_2.cpp"
    ```

## Bài tập

[SDOI2010 Trốn tìm](https://www.luogu.com.cn/problem/P2479)

[Violet Thiên sứ búp bê/SJY đặt quân cờ](https://www.luogu.com.cn/problem/P4169)

[Đội tuyển tập huấn quốc gia JZPFAR](https://www.luogu.com.cn/problem/P2093)

[BOI2007 Mokia](https://www.luogu.com.cn/problem/P4390)

[Luogu P4475 Vương quốc chocolate](https://www.luogu.com.cn/problem/P4475)

[CH tỉnh yếu Huce R2 TATT](https://www.luogu.com.cn/problem/P3769)
