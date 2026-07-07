Khi cần xác định một số cây có đẳng cấu hay không, thường có thể chuyển các cây đó thành giá trị băm rồi lưu lại để giảm độ phức tạp.

Băm cây rất linh hoạt, có thể thiết kế nhiều cách băm khác nhau. Tuy nhiên, nếu thiết kế tùy tiện thì dễ sai hoặc bị dữ liệu đối kháng phá. Dưới đây giới thiệu một lớp phương pháp dễ cài đặt và khó bị phá.

## Phương pháp

Lớp phương pháp này cần một hàm băm cho đa tập. Giá trị băm của cây con gốc tại một đỉnh bằng giá trị băm của đa tập gồm các giá trị băm của những cây con gốc tại các con của nó, tức là:

$$
h_x = f(\{ h_i \mid i \in son(x) \})
$$

Trong đó $h_x$ biểu thị giá trị băm của cây con gốc tại $x$, còn $f$ là hàm băm của đa tập.

Lấy hàm băm được dùng trong mã làm ví dụ:

$$
f(S) = \left( c + \sum_{x \in S} g(x) \right) \bmod m
$$

Trong đó $c$ là hằng số, thường chỉ cần dùng $1$. $m$ là mô-đun; thông thường dùng $2^{32}$ hoặc $2^{64}$ để tận dụng tràn tự nhiên, cũng có thể dùng một số nguyên tố lớn. $g$ là một ánh xạ từ số nguyên sang số nguyên; trong mã dùng xor shift, cũng có thể chọn hàm khác, nhưng không khuyến nghị dùng đa thức. Để đề phòng dữ liệu được tạo nhằm phá xor hash, còn có thể xor thêm một hằng số ngẫu nhiên trước và sau ánh xạ.

Cách băm này dễ viết. Nếu cần đổi gốc, trong lượt DP thứ hai chỉ cần trừ phần băm của cây con tương ứng.

## Bài tập ví dụ

### [UOJ #763. Băm cây](https://uoj.ac/problem/763)

Đây là một bài khuôn mẫu. Không cần nói thêm nhiều, chỉ cần lấy $1$ làm gốc và chạy một lần DFS.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-hash/tree-hash_1.cpp"
    ```

### [\[BJOI2015\] Đẳng cấu của cây](https://www.luogu.com.cn/problem/P5043)

Đẳng cấu trong bài này là đẳng cấu của cây vô hướng không gốc, còn phương pháp nêu trên áp dụng cho cây có gốc. Vì vậy, hai cây không gốc đẳng cấu chỉ có giá trị băm giống nhau khi chọn cùng một gốc tương ứng. Do giới hạn dữ liệu nhỏ, có thể vét cạn tính giá trị băm khi lấy từng đỉnh làm gốc, sau đó sắp xếp rồi so sánh.

Nếu giới hạn dữ liệu lớn hơn, cũng có thể dùng DP đổi gốc, duyệt cây hai lượt để tính giá trị băm khi lấy mỗi đỉnh làm gốc. Ngoài ra có thể tận dụng hàm băm đa tập ở trên: đưa tất cả giá trị băm ứng với từng đỉnh được chọn làm gốc vào một đa tập, rồi tính giá trị băm của đa tập đó để so sánh (cách làm một).

Cũng có thể tối ưu độ phức tạp bằng cách tìm trọng tâm của cây. Một cây có nhiều nhất hai trọng tâm, nên chỉ cần tính giá trị băm khi lấy trọng tâm đó (hoặc các trọng tâm đó) làm gốc. Sau đó, có thể so sánh riêng các giá trị băm này (cách làm hai), hoặc nếu chỉ có một trọng tâm thì lấy giá trị băm của nó làm giá trị băm của cả cây, còn nếu có hai trọng tâm thì lấy giá trị nhỏ hơn (hoặc lớn hơn) trong hai giá trị đó.

??? note "Cách làm một"
    ```cpp
    --8<-- "docs/graph/code/tree-hash/tree-hash_2.cpp"
    ```

??? note "Cách làm hai"
    ```cpp
    --8<-- "docs/graph/code/tree-hash/tree-hash_3.cpp"
    ```

### [HDU 6647 Bracket Sequences on Tree](https://acm.hdu.edu.cn/showproblem.php?pid=6647)

Bài toán yêu cầu đếm số phương án sinh ra các dãy ngoặc khác nhau về bản chất khi duyệt một cây không gốc.

Trước hết, hai cây có gốc không đẳng cấu sẽ không sinh ra cùng một dãy ngoặc. Xét trước số phương án sinh ra các dãy ngoặc khác nhau về bản chất khi duyệt một cây có gốc. Giả sử gốc của cây con đang xét là $u$, ký hiệu $f(u)$ là số phương án của cây con này. Khi bắt đầu từ $u$ và duyệt xuống dưới, thứ tự duyệt các con có thể chọn tùy ý, tạo ra $|son(u)|!$ hoán vị. Với mỗi đỉnh con $v$, trong cây con của $v$ có $f(v)$ phương án, do đó có $f(u)=|son(u)|! \cdot \prod_{v \in son(u)} f(v)$. Tuy nhiên, các cây con đẳng cấu sẽ tạo ra kết quả trùng lặp, nên $f(u)$ cần chia cho tích các giai thừa của số lần xuất hiện của từng loại cây con khác nhau về bản chất, tương tự như hoán vị của một đa tập.

Thông qua DP trên, có thể tính được số phương án của đỉnh gốc. Sau đó dùng DP đổi gốc để chuyển giá trị băm và thông tin số phương án từ đỉnh cha sang đỉnh con, từ đó tính được giá trị băm và số phương án khi lấy từng đỉnh làm gốc. Mỗi loại cây con khác nhau chỉ cần được đếm một lần.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/tree-hash/tree-hash_4.cpp"
    ```

## Tài liệu tham khảo

Phương pháp băm trong bài được tham khảo và mở rộng từ blog [Một cách băm cây dễ viết và khó bị phá](https://peehs-moorhsum.blog.uoj.ac/blog/7891).
