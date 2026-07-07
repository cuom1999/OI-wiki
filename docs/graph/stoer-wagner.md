author: DanJoshua, opsiff, yzy-1, yingqi-z20

## Định nghĩa

Vì bài toán không còn cố định **điểm nguồn** và **điểm đích**, ta cần định nghĩa lại khái niệm **lát cắt**.

Định nghĩa lát cắt trong phần luồng mạng không hoàn toàn trùng với định nghĩa trên Wikipedia.
Vì các lát cắt thường gặp trong thi đấu lập trình thường thuộc "bài toán lát cắt nhỏ nhất có nguồn và đích", cách hiểu đó dần trở thành quy ước.

### Lát cắt

Một tập cạnh được gọi là lát cắt của đồ thị nếu khi xóa toàn bộ các cạnh trong tập đó, đồ thị không còn liên thông nữa, tức bị chia thành ít nhất hai thành phần liên thông.

Cụ thể: trong đồ thị vô hướng $G = (V, E)$, giả sử $C$ là một tập gồm một số cạnh của $G$. Nếu xóa tất cả các cạnh trong $C$ khỏi $G$ khiến $G$ không còn là đồ thị liên thông, thì gọi $C$ là một lát cắt của đồ thị $G$.

### Bài toán lát cắt nhỏ nhất có nguồn và đích

Theo định nghĩa trong [lát cắt nhỏ nhất](./flow/min-cut.md).

### Bài toán lát cắt nhỏ nhất không có nguồn và đích

Đây là bài toán tìm lát cắt có tổng trọng số các cạnh nhỏ nhất. Bài toán này còn gọi là bài toán lát cắt nhỏ nhất toàn cục.

Việc chạy trực tiếp thuật toán luồng mạng cho mọi cặp đỉnh thường không chấp nhận được về độ phức tạp.

***

## Thuật toán Stoer-Wagner

### Dẫn nhập

Thuật toán Stoer-Wagner được *Mechthild Stoer* và *Frank Wagner* đề xuất năm 1995. Đây là một thuật toán giải bài toán lát cắt nhỏ nhất toàn cục trên **đồ thị vô hướng có trọng số dương** bằng cách **co đỉnh lặp lại**.

### Tính chất

Độ phức tạp của thuật toán là $O(|V||E| + |V|^{2}\log|V|)$, thường có thể xấp xỉ là $O(|V|^3)$.

Cài đặt của thuật toán dựa trên nhận xét cơ bản sau: giả sử trong đồ thị $G$ có hai đỉnh bất kỳ $S, T$.
Khi đó, với mọi lát cắt $C$ của $G$, hoặc $S, T$ nằm trong cùng một thành phần liên thông sau khi xóa $C$, hoặc $C$ là một lát cắt $S$-$T$.

### Quy trình

1.  Trong đồ thị $G$, chọn hai đỉnh $s, t$, rồi xem chúng là nguồn và đích để tìm lát cắt nhỏ nhất $s$-$t$ của đồ thị $G$ (gọi là *phase cut*), sau đó cập nhật đáp án hiện tại.
2.  Co hai đỉnh $s, t$ thành một đỉnh. Nếu $|V|$ của đồ thị $G$ còn lớn hơn $1$, quay lại bước đầu tiên.
3.  Xuất giá trị nhỏ nhất trong tất cả các *phase cut*.

Co hai đỉnh $s, t$: xóa cạnh nối $(s, t)$ giữa chúng. Với mỗi đỉnh $k$ bất kỳ trong $G \setminus \{s, t\}$, xóa cạnh $(t, k)$, rồi cộng trọng số cạnh đó $d(t, k)$ vào $d(s, k)$.

Giải thích: nếu $s, t$ nằm trong cùng một thành phần liên thông, xét một đỉnh $k$ trong $G \setminus \{s, t\}$. Giả sử $(k, s) \in C_{\min}$, khi đó $(k, t) \in C_{\min}$ cũng phải thuộc lát cắt.

Nếu không, do $s, t$ liên thông và $k, t$ liên thông, suy ra $s, k$ cũng nằm trong cùng một thành phần liên thông; khi đó $C = C_{\min} \setminus \{(t, k)\}$ sẽ tốt hơn $C_{\min}$.
Chiều ngược lại tương tự, nên có thể xem $s, t$ như cùng một đỉnh.

Bước 1 xét trường hợp $s, t$ không nằm trong cùng một thành phần liên thông, còn bước 2 xét các trường hợp còn lại.
Vì mỗi lần thực hiện bước 2 đều làm $|V|$ giảm đi $1$, thuật toán sẽ kết thúc sau $|V| - 1$ lần thực hiện.

### Cách tìm lát cắt nhỏ nhất S-T

Không sử dụng luồng mạng cho bước này.

Giả sử sau một số lần co đỉnh, đồ thị hiện tại là $G'=(V', E')$, và đang thực hiện bước 1.

Xây dựng một tập $A$, ban đầu đặt $A = \varnothing$.

Mỗi lần, trong tất cả các đỉnh của $V'$, chọn một đỉnh thỏa mãn $i \notin A$ và có hàm trọng số $w(A, i)$ lớn nhất để thêm vào $A$, cho đến khi $|A| = |V'|$.

Hàm trọng số được định nghĩa như sau:

$w(A, i) = \sum_{j \in A} d(i, j)$

Nếu $(i, j) \notin E'$, thì $d(i, j) = 0$.

Theo quy tắc chọn trên, thứ tự thêm các đỉnh vào $A$ là xác định sau khi cố định cách xử lý hòa.
Gọi $\operatorname{ord}(i)$ là đỉnh thứ $i$ được thêm vào $A$, $t = \operatorname{ord}(|V'|)$.
Gọi $\operatorname{pos}(v)$ là kích thước của $A$ ngay sau khi thêm $v$, tức thứ tự mà $v$ được thêm vào.

Khi đó, với một đỉnh $s$ bất kỳ khác $t$, lát cắt tách $t$ khỏi các đỉnh còn lại là một lát cắt $s$-$t$, và trọng số của nó là $w(t)$.

### Chứng minh

Định nghĩa một đỉnh $v$ là được kích hoạt khi và chỉ khi, vào lúc thêm $v$ vào $A$, đỉnh $u$ được thêm ngay trước $v$ không nằm cùng thành phần liên thông với $v$ trong đồ thị $G'' = (V', E'/C)$.

![Đỉnh được kích hoạt trong chứng minh thuật toán Stoer-Wagner](./images/Stoer-Wagner1.png)

Như hình vẽ, vùng màu xanh lam và vùng màu vàng là hai thành phần liên thông khác nhau; các số trong ngoặc vuông là thứ tự thêm vào $A$. Đỉnh màu xám là đỉnh được kích hoạt, còn đỉnh màu trắng thì không.

Định nghĩa $A_v = \{u \mid \operatorname{pos}(u) < \operatorname{pos}(v)\}$, tức tập các đỉnh được thêm vào $A$ nghiêm ngặt trước $v$.
Gọi $E_v$ là tập cạnh của đồ thị con cảm sinh bởi tập đỉnh $A_v \cup\{v\}$ trong $E'$.
Lưu ý rằng tập đỉnh này có chứa $v$.

Định nghĩa lát cắt cảm sinh $C_v$ là $C \cap E_v$. Khi đó $w(C_v) = \sum_{(i,j) \in C_v} d(i, j)$.

???+ note "Bổ đề 1"
    Với mọi đỉnh được kích hoạt $v$, có $w(A_v, v) \le w(C_v)$.
    
    Chứng minh: dùng quy nạp toán học.
    
    Với đỉnh đầu tiên được kích hoạt $v_0$, theo định nghĩa có $w(A_{v_0}, v_0) = w(C_{v_0})$.
    
    Với hai đỉnh được kích hoạt tiếp theo $u, v$, giả sử $\operatorname{pos}(v) < \operatorname{pos}(u)$, khi đó:
    
    $w(A_u, u) = w(A_v, u) + w(A_u - A_v, u)$
    
    Mặt khác, đã biết:
    
    $w(A_v, u) \le w(A_v, v)$ và $w(A_v, v) \le w(C_v)$. Kết hợp hai bất đẳng thức này, thu được:
    
    $w(A_u, u) \le w(C_v) + w(A_u - A_v, u)$
    
    Vì $w(A_u \setminus A_v, u)$ có đóng góp vào $w(C_u)$ nhưng không đóng góp vào $w(C_v)$, trong trường hợp mọi cạnh đều có trọng số dương, có thể suy ra:
    
    $w(A_u,u) \le w(C_u)$
    
    Theo quy nạp, bổ đề được chứng minh.

Vì $\operatorname{pos}(s) < \operatorname{pos}(t)$, đồng thời $s, t$ không nằm trong cùng một thành phần liên thông, nên $t$ sẽ được kích hoạt. Do đó, có $w(A_t, t) \le w(C_t) = w(C)$.

??? note "[P5632 [Mẫu] Thuật toán Stoer-Wagner](https://www.luogu.com.cn/problem/P5632)"
    ```cpp
    --8<-- "docs/graph/code/stoer-wagner/stoer-wagner_1.cpp"
    ```

***

### Phân tích độ phức tạp và tối ưu hóa

Độ phức tạp của một pha co đỉnh là $O(|E| + |V|\log|V|)$.

Tổng cộng có $O(|V|)$ pha co đỉnh, nên tổng độ phức tạp là $O(|E||V| + |V|^2\log|V|)$.

Theo kinh nghiệm từ [đường đi ngắn nhất](./shortest-path.md), nút thắt của thuật toán nằm ở việc tìm đỉnh có trọng số lớn nhất.

Trong một pha co đỉnh, cần lấy đỉnh khỏi heap $|V|$ lần và tăng trọng số $|E|$ lần.

Heap Fibonacci có thể đảm nhiệm việc tìm đỉnh lớn nhất trong $O(\log|V|)$ và tăng trọng số trong $O(1)$, nhờ đó độ phức tạp lý thuyết có thể đạt $O(|E| + |V|\log|V|)$.
Tuy nhiên, vì heap Fibonacci có hằng số quá lớn và lượng mã nhiều, giá trị ứng dụng thực tế tương đối thấp.

Trong thử nghiệm thực tế, ngay cả khi bật O2, việc được chấp nhận vẫn có thể phụ thuộc vào dao động của trình chấm.
