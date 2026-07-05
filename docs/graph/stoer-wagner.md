author: DanJoshua, opsiff, yzy-1, yingqi-z20

## Định nghĩa

Vì không còn cố định khái niệm **điểm nguồn và điểm đích**, ta cần định nghĩa lại khái niệm **lát cắt**.

Thật ra, định nghĩa về lát cắt trong phần luồng mạng không hoàn toàn trùng với định nghĩa trên Wikipedia. Chỉ vì các lát cắt ta thường gặp đều thuộc "bài toán lát cắt nhỏ nhất có nguồn và đích", nên cách hiểu đó dần trở thành quy ước.

### Lát cắt

Một tập cạnh mà khi xóa toàn bộ các cạnh trong đó thì làm cho một đồ thị luồng mạng không còn liên thông nữa, tức bị chia thành hai đồ thị con, được gọi là một lát cắt của đồ thị.

Cụ thể: trong đồ thị vô hướng $G = (V, E)$, giả sử $C$ là một tập gồm một số cạnh của $G$. Nếu xóa tất cả các cạnh trong $C$ khỏi $G$ khiến $G$ không còn là đồ thị liên thông, thì gọi $C$ là một lát cắt của đồ thị $G$.

### Bài toán lát cắt nhỏ nhất có nguồn và đích

Theo định nghĩa trong [lát cắt nhỏ nhất](./flow/min-cut.md).

### Bài toán lát cắt nhỏ nhất không có nguồn và đích

Đây là lát cắt có tổng trọng số các cạnh chứa trong nó nhỏ nhất. Bài toán này còn gọi là bài toán lát cắt nhỏ nhất toàn cục.

Rõ ràng, chạy trực tiếp luồng mạng là không khả thi về độ phức tạp.

***

## Thuật toán Stoer-Wagner

### Dẫn nhập

Thuật toán Stoer-Wagner được *Mechthild Stoer* và *Frank Wagner* đề xuất năm 1995. Đây là một thuật toán giải bài toán lát cắt nhỏ nhất toàn cục trên **đồ thị vô hướng có trọng số dương** bằng cách **co đỉnh lặp lại**.

### Tính chất

Độ phức tạp của thuật toán là $O(|V||E| + |V|^{2}\log|V|)$, thường có thể xấp xỉ là $O(|V|^3)$.

Cài đặt của thuật toán dựa trên sự thật cơ bản sau: giả sử trong đồ thị $G$ có hai đỉnh bất kỳ $S, T$. Khi đó, với bất kỳ lát cắt $C$ nào của đồ thị $G$, hoặc $S, T$ nằm trong cùng một thành phần liên thông, hoặc $C$ là một lát cắt ${S-T}$.

### Quy trình

1.  Trong đồ thị $G$, chọn tùy ý hai đỉnh $s, t$, rồi xem chúng là điểm nguồn và điểm đích để tìm lát cắt nhỏ nhất $S-T$ của đồ thị $G$ (gọi là *cut of phase*), sau đó cập nhật đáp án hiện tại.
2.  "Gộp" hai đỉnh $s, t$. Nếu $|V|$ của đồ thị $G$ còn lớn hơn $1$, quay lại bước đầu tiên.
3.  Xuất giá trị nhỏ nhất trong tất cả các *cut of phase*.

Gộp hai đỉnh $s, t$: xóa cạnh nối $(s, t)$ giữa chúng. Với mỗi đỉnh $k$ bất kỳ trong $G \setminus \{s, t\}$, xóa cạnh $(t, k)$, rồi cộng trọng số cạnh đó $d(t, k)$ vào $d(s, k)$.

Giải thích: nếu $s, t$ nằm trong cùng một thành phần liên thông, với một đỉnh $k$ trong $G \setminus \{s, t\}$, giả sử $(k, s) \in C_{\min}$ thì $(k, t) \in C_{\min}$ cũng nhất định đúng. Nếu không, vì $s, t$ liên thông và $k, t$ liên thông, ta sẽ suy ra $s, k$ nằm trong cùng một thành phần liên thông; khi đó $C = C_{\min} \setminus \{(t, k)\}$ sẽ tốt hơn $C_{\min}$. Chiều ngược lại cũng tương tự. Vì vậy, $s, t$ có thể được xem như cùng một đỉnh.

Bước 1 xét trường hợp $s,t$ không nằm trong cùng một thành phần liên thông, còn bước 2 xét các trường hợp còn lại. Vì mỗi lần thực hiện bước 2 đều làm $|V|$ giảm đi $1$, thuật toán sẽ kết thúc sau $|V| - 1$ lần thực hiện.

### Cách tìm lát cắt nhỏ nhất S-T

Rõ ràng không dùng luồng mạng.

Giả sử sau một số lần gộp, đồ thị hiện tại là $G'=(V', E')$, và ta đang thực hiện bước 1.

Ta xây dựng một tập $A$, ban đầu đặt $A = \varnothing$.

Mỗi lần, trong tất cả các đỉnh của $V'$, ta chọn đỉnh thỏa mãn $i \notin A$ và có hàm trọng số $w(A, i)$ lớn nhất để thêm vào tập $A$, cho đến khi $|A| = |V'|$.

Hàm trọng số được định nghĩa như sau:

$w(A, i) = \sum_{j \in A} d(i, j)$

Nếu $(i, j) \notin E'$, thì $d(i, j) = 0$.

Dễ thấy thứ tự thêm tất cả các đỉnh vào $A$ là cố định. Gọi $\operatorname{ord}(i)$ là đỉnh thứ $i$ được thêm vào $A$, $t = \operatorname{ord}(|V'|)$; gọi $\operatorname{pos}(v)$ là kích thước của $|A|$ ngay sau khi $v$ được thêm vào, tức thứ tự mà $v$ được thêm.

Khi đó, với một đỉnh $s$ bất kỳ khác $t$, lát cắt tách $t$ khỏi các đỉnh còn lại là một lát cắt $s$-$t$, và trọng số của nó là $w(t)$.

### Chứng minh

Định nghĩa một đỉnh $v$ là được kích hoạt khi và chỉ khi, vào lúc thêm $v$ vào $A$, đỉnh cuối cùng $u$ trong $A$ tại thời điểm đó được thêm vào tập sớm hơn $v$, đồng thời trong đồ thị $G'' = (V', E'/C)$, $u$ và $v$ không nằm trong cùng một thành phần liên thông.

![Stoer-Wagner1](./images/Stoer-Wagner1.png)

Như hình vẽ, vùng màu xanh lam và vùng màu vàng là hai thành phần liên thông khác nhau; các số trong ngoặc vuông là thứ tự thêm vào $A$. Đỉnh màu xám là đỉnh được kích hoạt, còn đỉnh màu trắng thì không.

Định nghĩa $A_v = \{u \mid \operatorname{pos}(u) < \operatorname{pos}(v)\}$, tức tập các đỉnh được thêm vào $A$ nghiêm ngặt trước $v$. Gọi $E_v$ là tập cạnh của đồ thị con cảm sinh của $E'$ với tập đỉnh $A_v \cup\{v\}$. Lưu ý rằng tập đỉnh này có chứa $v$.

Định nghĩa lát cắt cảm sinh $C_v$ là $C \cap E_v$. Khi đó $w(C_v) = \sum_{(i,j) \in C_v} d(i, j)$.

???+ note "Bổ đề 1"
    Với mọi đỉnh được kích hoạt $v$, ta có $w(A_v, v) \le w(C_v)$.
    
    Chứng minh: dùng quy nạp toán học.
    
    Với đỉnh đầu tiên được kích hoạt $v_0$, theo định nghĩa ta có $w(A_{v_0}, v_0) = w(C_{v_0})$.
    
    Với hai đỉnh được kích hoạt tiếp theo $u, v$, giả sử $\operatorname{pos}(v) < \operatorname{pos}(u)$, khi đó:
    
    $w(A_u, u) = w(A_v, u) + w(A_u - A_v, u)$
    
    Mặt khác, ta đã biết:
    
    $w(A_v, u) \le w(A_v, v)$ và $w(A_v, v) \le w(C_v)$. Kết hợp hai bất đẳng thức này, ta được:
    
    $w(A_u, u) \le w(C_v) + w(A_u - A_v, u)$
    
    Vì $w(A_u - A_v, u)$ có đóng góp vào $w(C_u)$ nhưng không đóng góp vào $w(C_v)$, trong trường hợp mọi cạnh đều có trọng số dương, có thể suy ra:
    
    $w(A_u,u) \le w(C_u)$
    
    Theo quy nạp, bổ đề được chứng minh.

Vì $\operatorname{pos}(s) < \operatorname{pos}(t)$, đồng thời $s, t$ không nằm trong cùng một thành phần liên thông, nên $t$ sẽ được kích hoạt. Do đó, ta có $w(A_t, t) \le w(C_t) = w(C)$.

??? note "[P5632 [Mẫu] Thuật toán Stoer-Wagner](https://www.luogu.com.cn/problem/P5632)"
    ```cpp
    --8<-- "docs/graph/code/stoer-wagner/stoer-wagner_1.cpp"
    ```

***

### Phân tích độ phức tạp và tối ưu hóa

Độ phức tạp của thao tác *contract* là $O(|E| + |V|\log|V|)$.

Tổng cộng có $O(|V|)$ lần *contract*, nên tổng độ phức tạp là $O(|E||V| + |V|^2\log|V|)$.

Theo kinh nghiệm từ [đường đi ngắn nhất](./shortest-path.md), nút thắt của thuật toán nằm ở việc tìm đỉnh có trọng số lớn nhất.

Trong một lần *contract*, cần lấy đỉnh heap $|V|$ lần và tăng trọng số $|E|$ lần.

Heap Fibonacci có thể đảm nhiệm việc tìm đỉnh heap trong $O(\log|V|)$ và tăng trọng số trong $O(1)$, nhờ đó độ phức tạp lý thuyết có thể đạt $O(|E| + |V|\log|V|)$. Tuy nhiên, vì heap Fibonacci có hằng số quá lớn và lượng mã nhiều, giá trị ứng dụng thực tế tương đối thấp.

Trong thử nghiệm thực tế, ngay cả bật O2 vẫn phải phụ thuộc vào dao động của trình chấm mới qua được.
