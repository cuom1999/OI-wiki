Trước khi đọc bài này, nên đọc [luồng cực đại](./max-flow.md) và nắm vững thuật toán luồng cực đại.

## Tổng quan

Luồng mạng có cận trên và cận dưới là bài toán đặt đồng thời cận trên $c(u,v)$
và cận dưới $b(u,v)$ cho mỗi cạnh của mạng luồng.
Nói cách khác, một luồng khả thi phải thỏa mãn $b(u,v) \leq f(u,v) \leq c(u,v)$.
Đồng thời, mọi đỉnh ngoài đỉnh nguồn và đỉnh đích phải thỏa mãn cân bằng luồng.

Tùy theo yêu cầu đề bài, có thể dùng luồng mạng có cận trên và cận dưới để giải nhiều loại bài toán khác nhau.

## Luồng khả thi có cận trên và cận dưới, không có nguồn và đích

Cho một mạng luồng $G$ không có nguồn và đích.
Hỏi có tồn tại cách gán luồng cho mỗi cạnh sao cho luồng trên mỗi cạnh thỏa mãn cận trên, cận dưới,
đồng thời mọi đỉnh đều cân bằng luồng hay không.

Có thể giả sử mỗi cạnh đã có sẵn lượng luồng $b(u,v)$, gọi đó là luồng ban đầu.
Đồng thời, trong đồ thị mới thêm cạnh từ $u$ đến $v$ với dung lượng $c(u,v)-b(u,v)$.
Sau đó chỉ cần xét phần luồng điều chỉnh trên đồ thị mới này.

Luồng điều chỉnh có cận dưới bằng $0$, nhưng luồng ban đầu vừa xây dựng có thể chưa cân bằng.
Giả sử tại một đỉnh, lượng luồng vào ban đầu trừ lượng luồng ra ban đầu bằng $M$.

Nếu $M=0$, đỉnh này đã cân bằng luồng và không cần cạnh phụ.

Nếu $M>0$, luồng vào ban đầu đang lớn hơn luồng ra.
Cần nối một cạnh phụ có dung lượng $M$ từ nguồn phụ $S'$ đến đỉnh đó;
để bảo toàn luồng trong đồ thị mới, phần luồng này phải được đẩy ra ngoài qua các cạnh điều chỉnh.

Nếu $M<0$, luồng ra ban đầu đang lớn hơn luồng vào.
Cần nối một cạnh phụ có dung lượng $-M$ từ đỉnh đó đến đích phụ $T'$;
điều này buộc đồ thị mới phải đưa đủ phần luồng thiếu vào đỉnh đó qua các cạnh điều chỉnh.

Nếu cạnh phụ tương ứng được bão hòa, điều đó cho thấy điều kiện cân bằng luồng của đỉnh này có thể được thỏa mãn;
ngược lại thì không.
Lý do là đồ thị ban đầu chỉ cân bằng sau khi cộng thêm phần luồng điều chỉnh này.

Sau khi dựng xong đồ thị, chạy luồng cực đại từ $S'$ đến $T'$.
Nếu mọi cạnh đi ra từ $S'$ đều bão hòa thì tồn tại luồng khả thi, ngược lại thì không tồn tại.

### Ví dụ

???+ note "[Luogu P14578 - Mẫu: luồng khả thi có cận trên và cận dưới, không có nguồn và đích](https://www.luogu.com.cn/problem/P14578)"
    Cho một đồ thị có hướng $G$ gồm $n$ đỉnh và $m$ cạnh có hướng. Mỗi cạnh có cận dưới luồng $l_i$ và cận trên luồng $r_i$.
    
    Cần xây dựng một phương án sao cho luồng $w_i$ trên mỗi cạnh thỏa mãn ràng buộc $l_i\leq w_i\leq r_i$,
    đồng thời mọi đỉnh đều cân bằng luồng, tức tổng luồng vào của mỗi đỉnh bằng tổng luồng ra.
    Nếu không có nghiệm thì báo vô nghiệm.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/flow/bound/bound_1.cpp"
    ```

## Luồng khả thi có cận trên và cận dưới, có nguồn và đích

Cho một mạng luồng $G$ có nguồn và đích.
Hỏi có tồn tại cách gán luồng cho mỗi cạnh sao cho luồng trên mỗi cạnh thỏa mãn cận trên, cận dưới,
đồng thời mọi đỉnh ngoài nguồn và đích đều cân bằng luồng hay không.

Giả sử đỉnh nguồn là $S$ và đỉnh đích là $T$.

Khi đó có thể thêm một cạnh từ $T$ đến $S$ có cận trên là $\infty$ và cận dưới là $0$,
từ đó chuyển bài toán về luồng khả thi có cận trên và cận dưới, không có nguồn và đích.

Nếu có nghiệm, giá trị luồng khả thi từ $S$ đến $T$ bằng lượng luồng trên cạnh phụ từ $T$ đến $S$.

## Luồng cực đại có cận trên và cận dưới, có nguồn và đích

Cho một mạng luồng $G$ có nguồn và đích.
Hỏi có tồn tại cách gán luồng cho mỗi cạnh sao cho luồng trên mỗi cạnh thỏa mãn cận trên, cận dưới,
đồng thời mọi đỉnh ngoài nguồn và đích đều cân bằng luồng hay không.
Nếu tồn tại, hỏi giá trị luồng lớn nhất thỏa mãn cách gán đó.

Tìm một luồng khả thi bất kỳ trên mạng. Nếu không tìm được nghiệm thì có thể kết thúc ngay.

Ngược lại, xét mạng dư sau khi xóa toàn bộ các cạnh phụ và điều chỉnh trên mạng đó.

Chạy thêm một lần luồng cực đại từ $S$ đến $T$ trên mạng dư.
Lấy giá trị luồng khả thi cộng với giá trị luồng cực đại vừa tìm được sẽ cho đáp án.

??? warning "Một điểm rất dễ sai"
    Luồng cực đại từ $S$ đến $T$ phải được chạy trực tiếp trên mạng dư sau khi đã chạy xong bước tìm luồng khả thi có cận trên, cận dưới, nguồn và đích.
    
    Tuyệt đối không chạy trên mạng luồng ban đầu.

## Luồng cực tiểu có cận trên và cận dưới, có nguồn và đích

Cho một mạng luồng $G$ có nguồn và đích.
Hỏi có tồn tại cách gán luồng cho mỗi cạnh sao cho luồng trên mỗi cạnh thỏa mãn cận trên, cận dưới,
đồng thời mọi đỉnh ngoài nguồn và đích đều cân bằng luồng hay không.
Nếu tồn tại, hỏi giá trị luồng nhỏ nhất thỏa mãn cách gán đó.

Tương tự, xét việc đẩy trả phần luồng không cần thiết trong mạng dư.

Tìm một luồng khả thi bất kỳ trên mạng. Nếu không tìm được nghiệm thì có thể kết thúc ngay.

Ngược lại, xét mạng dư sau khi xóa toàn bộ các cạnh phụ.

Chạy thêm một lần luồng cực đại từ $T$ đến $S$ trên mạng dư.
Lấy giá trị luồng khả thi trừ đi giá trị luồng cực đại vừa tìm được sẽ cho đáp án.

??? note "[AHOI 2014 - Side Story](https://loj.ac/problem/2226)"
    Với mỗi cạnh cốt truyện từ $x$ đến $y$ có chi phí $v$, đặt cận trên là $\infty$ và cận dưới là $1$.
    
    Với mỗi đỉnh, nối đến $T$ một cạnh có chi phí $c$, cận trên $\infty$ và cận dưới $1$.
    
    Đỉnh $S$ là đỉnh số $1$.
    
    Chỉ cần chạy một lần luồng khả thi chi phí nhỏ nhất có cận trên, cận dưới, nguồn và đích.
    
    Vì cách giải luồng khả thi chi phí nhỏ nhất tương tự luồng khả thi nhỏ nhất, phần này không trình bày thêm.
