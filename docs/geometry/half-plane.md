author: wjy-yy, Ir1d, Xeonacid

## Định nghĩa

### Nửa mặt phẳng

Một đường thẳng cùng với một phía của đường thẳng đó tạo thành một nửa mặt phẳng. Nửa mặt phẳng là một tập điểm, nên nó là tập gồm đường thẳng và các điểm ở một phía của đường thẳng. Nếu bao gồm cả đường thẳng thì gọi là nửa mặt phẳng đóng; nếu không bao gồm đường thẳng thì gọi là nửa mặt phẳng mở.

Dạng giải tích thường là $Ax+By+C\ge 0$.

Trong hình học tính toán, nửa mặt phẳng thường được biểu diễn bằng vectơ; trong cùng một bài, toàn bộ nửa mặt phẳng thường được thống nhất là phía trái hoặc phía phải của vectơ.

![Nửa mặt phẳng](./images/hpi1.svg)

### Giao nửa mặt phẳng

Giao nửa mặt phẳng là giao của nhiều nửa mặt phẳng. Vì nửa mặt phẳng là tập điểm, giao của các tập điểm vẫn là một tập điểm. Trên hệ tọa độ Descartes phẳng, nó tạo thành một miền.

Điều này rất giống bài toán quy hoạch tuyến tính thông thường: giao nửa mặt phẳng thu được chính là miền khả thi trong quy hoạch tuyến tính. Trong trường hợp thường gặp, giao nửa mặt phẳng là hữu hạn, và các bài toán hay yêu cầu tính diện tích cùng các đại lượng liên quan.

Có thể hiểu nó là giao của phía phải của từng vectơ trong một tập vectơ, hoặc là tập nghiệm của hệ bất phương trình sau.

$$
\begin{cases}
A_1x+B_1y+C\ge 0\\
A_2x+B_2y+C\ge 0\\
\cdots
\end{cases}
$$

### Nhân đa giác

Nếu với một tập điểm, đoạn thẳng nối từ mỗi điểm trong tập đó tới một điểm bất kỳ trên đa giác không có giao điểm nào khác với đa giác, thì tập điểm này được gọi là nhân đa giác.

Xem mỗi cạnh của đa giác như một vectơ nối đầu-cuối liên tiếp, thì giao nửa mặt phẳng nằm về phía trong đa giác của các vectơ này chính là nhân đa giác.

## Cách giải - thuật toán S&I

### Sắp xếp theo góc cực

Ngôn ngữ C có một hàm thư viện tên là `atan2(double y,double x)`, trả về $\theta\in (-\pi,\pi]$, với $\theta =\arctan \frac{y}{x}$.

Gọi hàm này với vectơ làm đối số, rồi sắp xếp theo giá trị trả về để thu được tập cạnh, tức tập vectơ, mới.

Khi sắp xếp, nếu gặp các vectơ thẳng hàng và cùng hướng, cần giữ vectơ gần miền khả thi hơn. Ví dụ, nếu hai vectơ có cùng góc cực và cần nửa mặt phẳng bên trái vectơ, thì chỉ cần giữ vectơ nằm bên trái. Cách kiểm tra là lấy đầu hoặc cuối của một vectơ so với vectơ còn lại, rồi xét điểm đó ở bên trái hay bên phải.

### Duy trì hàng đợi đơn điệu

Vì giao nửa mặt phẳng là một đa giác lồi, cần duy trì một bao lồi. Cạnh được thêm sau chỉ có thể ảnh hưởng tới cạnh được thêm sớm nhất hoặc muộn nhất, khi bao lồi hiện tại còn liên thông. Do đó chỉ cần xóa phần tử ở đầu và cuối hàng đợi, nên dùng hàng đợi đơn điệu.

Duyệt các vectơ đã được sắp xếp, đồng thời duy trì thêm một mảng giao điểm. Khi hàng đợi có hơn 2 phần tử, các vectơ trong đó sẽ tạo ra các giao điểm.

Với vectơ hiện tại, nếu giao điểm trước đó nằm ở **phía đối diện** với nửa mặt phẳng mà vectơ này biểu diễn, thì cạnh trước đó không còn ý nghĩa.

![Hàng đợi đơn điệu](./images/hpi2.svg)

Trong hình trên, giả sử lấy nửa mặt phẳng bên trái vectơ. Sau khi sắp xếp theo góc cực, thứ tự duyệt phải là $\vec a\to\vec b\to\vec c$. Khi $\vec a$ và $\vec b$ vào hàng đợi, mảng giao điểm sẽ có một điểm $D$, trong đó mảng giao điểm lưu giao điểm của vectơ ở cùng chỉ số trong hàng đợi với vectơ đứng trước nó.

Tiếp theo khi xét đến $\vec c$, điểm $D$ nằm bên phải $\vec c$. Vì **các vectơ tạo ra**  $D$  **đều có góc cực nhỏ hơn** $\vec c$, nên vectơ tạo ra $D$, tức $\vec b$, sẽ không còn ảnh hưởng tới giao nửa mặt phẳng.

Còn một khả năng khác là khi gần kết thúc, vectơ mới thêm vào sẽ bắt đầu gây ảnh hưởng từ đầu hàng đợi.

![Ảnh hưởng ở đầu hàng đợi](./images/hpi7.svg)

Vẫn giả sử lấy nửa mặt phẳng bên trái vectơ. Sau khi thêm vectơ $\vec f$, giao điểm đầu tiên $G$ nằm bên phải $\vec f$. Đảo ngược tiêu chuẩn phán đoán ở trên, lúc này nên xóa vectơ $\vec a$, tức vectơ ở **đầu hàng đợi**.

Cuối cùng, dùng vectơ ở đầu hàng đợi để loại bỏ các vectơ thừa ở cuối hàng đợi. Lý do là vectơ ở đầu hàng đợi sẽ bị các ràng buộc phía sau hạn chế, còn vectơ ở cuối hàng đợi thì không. Khi đó các vectơ đã tạo thành một vòng, nên vectơ ở đầu có thể ràng buộc vectơ ở cuối.

### Thu được giao nửa mặt phẳng

Nếu giao nửa mặt phẳng là một đa giác lồi $n$ cạnh, cuối cùng mảng giao điểm sẽ chứa $n$ điểm. Nối chúng theo thứ tự đầu-cuối sẽ thu được một đa giác $n$ cạnh có hướng thống nhất, thuận hoặc ngược chiều kim đồng hồ.

Khi đó có thể dùng phép chia tam giác để tính diện tích. Đây là dạng bài cơ bản nhất.

Đôi khi giao nửa mặt phẳng không tồn tại hoặc có diện tích bằng 0, cần xử lý biên cẩn thận.

### Lưu ý

Khi xuất hiện một vectơ có thể đẩy toàn bộ các điểm trong hàng đợi ra ngoài, tức mọi điểm trong hàng đợi đều nằm bên phải vectơ đó, **bắt buộc** phải xử lý cuối hàng đợi trước rồi mới xử lý đầu hàng đợi. Vì vậy trong vòng lặp, cần duyệt phần `--r;` trước rồi mới duyệt phần `++l;`, nếu không sẽ sai. Lý do như sau.

![](./images/hpi4.svg)

Thông thường, khi thêm một cạnh, tức vectơ $\vec w$, vào sau hàng đợi có thứ tự $\left\{\vec{u},\vec{v}\right\}$, sẽ tạo ra một giao điểm $N$ và thu hẹp phạm vi phía sau $\vec{v}$.

![](./images/hpi5.svg)

Nhưng vì mỗi thao tác đều là thao tác tổng quát, cũng có thể xảy ra tình huống điểm $M$ bị đẩy ra ngoài.

![](./images/hpi6.svg)

Nếu lúc này xuất hiện vectơ $\vec a$ sao cho $M$ nằm bên phải $\vec a$, thì $M$ phải rời hàng đợi. Nếu khi đó duyệt `++l` từ đầu hàng đợi, phạm vi đang bị mở rộng. Thực tế, điểm $M$ do $\vec u$ và $\vec v$ cùng tạo thành, nên cần xét xem tác động tới tiến trình hiện tại đến từ $\vec u$ hay $\vec v$. Vì sau khi sắp xếp theo góc cực, các vectơ theo thứ tự ngược chiều kim đồng hồ, ảnh hưởng của $\vec v$ sẽ lớn hơn.

Như hình trên, nếu xác nhận $M$ nằm bên phải $\vec a$, thì lúc này ảnh hưởng của $\vec v$ không còn đóng góp gì cho đáp án giao nửa mặt phẳng.

Còn lý do loại bỏ đầu hàng đợi là **ràng buộc của vectơ hiện tại mạnh hơn vectơ ở đầu hàng đợi**; điều kiện này giả định trong hàng đợi có nhiều hơn hai đoạn thẳng, tức vectơ. Nếu không, sẽ xuất hiện tình huống như trên.

Vì vậy nhất định phải loại bỏ cuối hàng đợi trước rồi mới loại bỏ đầu hàng đợi.

???+ note "Mã - phần so sánh"
    ```cpp
    friend bool operator<(seg x, seg y) {
      db t1 = atan2((x.b - x.a).y, (x.b - x.a).x);
      db t2 = atan2((y.b - y.a).y, (y.b - y.a).x);  // Tính góc cực
      if (fabs(t1 - t2) > eps)                      // Nếu góc cực khác nhau
        return t1 < t2;
      return (y.a - x.a) * (y.b - x.a) >
             eps;  // Xét vectơ x nằm phía nào của y, đặt vectơ trái nhất lên trước
    }
    ```

???+ note "Mã - phần tăng dần"
    ```cpp
    // pnt its(seg a,seg b) biểu diễn việc tìm giao điểm của hai đoạn a,b
    // s[] là các vectơ sau khi sắp xếp theo góc cực
    // q[] là hàng đợi vectơ
    // t[i] là giao điểm của s[i-1] và s[i]
    // Phong cách mã: phạm vi hàng đợi là (l,r]
    // Tìm giao nửa mặt phẳng bên trái vectơ
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i)
      if (s[i] != s[i - 1]) {
        // Cần kiểm tra cuối hàng đợi trước
        while (r - l > 1 && (s[i].b - t[r]) * (s[i].a - t[r]) >
                                eps)  // Nếu giao điểm trước nằm bên phải vectơ thì loại bỏ cuối hàng đợi
          --r;
        while (r - l > 1 && (s[i].b - t[l + 2]) * (s[i].a - t[l + 2]) >
                                eps)  // Nếu giao điểm đầu nằm bên phải vectơ thì loại bỏ đầu hàng đợi
          ++l;
        q[++r] = s[i];
        if (r - l > 1) t[r] = its(q[r], q[r - 1]);  // Tính giao điểm mới
      }
    while (r - l > 1 &&
           (q[l + 1].b - t[r]) * (q[l + 1].a - t[r]) > eps)  // Xóa phần tử thừa
      --r;
    t[r + 1] = its(q[l + 1], q[r]);  // Tính thêm giao điểm mới
    ++r;
    // Không thể ++r ngay trong t tại vị trí này.
    ```

## Bài tập

[POJ 2451 Uyuw's Concert](http://poj.org/problem?id=2451) xử lý biên

[POJ 1279 Art Gallery](http://poj.org/problem?id=1279) tìm nhân đa giác

[CQOI2006 Convex Polygon](https://www.luogu.com.cn/problem/P4196)
