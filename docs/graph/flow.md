Trang này giới thiệu các kiến thức cơ bản liên quan đến luồng mạng.

## Tổng quan

Mạng là một đồ thị có hướng đặc biệt $G=(V,E)$. Điểm khác biệt so với đồ thị có hướng thông thường là mạng có dung lượng và hai đỉnh nguồn, đỉnh đích.

-   Mỗi cạnh $(u, v)$ trong $E$ có một trọng số gọi là dung lượng, ký hiệu là $c(u, v)$. Khi $(u,v)\notin E$, có thể giả sử $c(u,v)=0$.

-   Trong $V$ có hai đỉnh đặc biệt: đỉnh nguồn $s$ và đỉnh đích $t$ ($s \neq t$).

Với mạng $G=(V, E)$, luồng là một hàm từ tập cạnh $E$ đến tập số nguyên hoặc tập số thực, thỏa mãn các tính chất sau.

1.  Ràng buộc dung lượng: với mỗi cạnh, lượng luồng đi qua cạnh đó không được vượt quá dung lượng của cạnh, tức là $0 \leq f(u,v) \leq c(u,v)$.
2.  Bảo toàn luồng: ngoài đỉnh nguồn và đỉnh đích, luồng ròng của mọi đỉnh $u$ đều bằng $0$. Trong định nghĩa này, luồng ròng của $u$ là $f(u) = \sum_{x \in V} f(u, x) - \sum_{x \in V} f(x, u)$.

Với mạng $G = (V, E)$ và một luồng $f$ trên mạng đó, giá trị luồng $|f|$ được định nghĩa là luồng ròng $f(s)$ của đỉnh nguồn $s$. Từ tính bảo toàn luồng, giá trị này cũng bằng số đối của luồng ròng tại đỉnh đích, tức $-f(t)$.

Với mạng $G = (V, E)$, nếu $\{S, T\}$ là một phân hoạch của $V$ (tức $S \cup T = V$ và $S \cap T = \varnothing$), đồng thời thỏa mãn $s \in S, t \in T$, thì $\{S, T\}$ được gọi là một lát cắt $s$-$t$ của $G$. Dung lượng của lát cắt $s$-$t$ $\{S, T\}$ được định nghĩa là $||S, T|| = \sum_{u \in S} \sum_{v \in T} c(u, v)$.

## Các bài toán thường gặp

Các bài toán luồng mạng thường gặp bao gồm, nhưng không chỉ giới hạn ở, những dạng sau.

-   Bài toán luồng cực đại: với mạng $G = (V, E)$, gán lượng luồng cho mỗi cạnh để thu được một luồng hợp lệ $f$ sao cho giá trị luồng của $f$ lớn nhất có thể. Khi đó $f$ được gọi là luồng cực đại của $G$.
-   Bài toán lát cắt nhỏ nhất: với mạng $G = (V, E)$, tìm một lát cắt $s$-$t$ thích hợp $\{S, T\}$ sao cho tổng dung lượng của $\{S, T\}$ nhỏ nhất có thể. Khi đó tổng dung lượng của $\{S, T\}$ được gọi là lát cắt nhỏ nhất của $G$.
-   Bài toán luồng cực đại chi phí nhỏ nhất: trên mạng $G = (V, E)$, mỗi cạnh có một trọng số $w(u, v)$ gọi là chi phí, biểu thị chi phí để một đơn vị luồng đi qua $(u, v)$. Trong tất cả các luồng cực đại có thể có của $G$, luồng có tổng chi phí nhỏ nhất được gọi là luồng cực đại chi phí nhỏ nhất.

Các bài toán này sẽ được trình bày chi tiết hơn trong các phần sau.

## Ví dụ: 24 bài toán luồng mạng

24 bài toán luồng mạng là một danh sách bài tập được lưu truyền rộng rãi trên Internet tiếng Trung ([LibreOJ](https://loj.ac/problems/tag/30)/[Luogu](https://www.luogu.com.cn/problem/list?tag=332)) và đã tồn tại ít nhất từ khoảng năm 2010. Danh sách này giới thiệu một số kỹ thuật kinh điển để mô hình hóa các bài toán khác thành bài toán luồng mạng. Do giới hạn của bối cảnh thời kỳ đó, các bài trong danh sách này không nhất thiết là những bài toán luồng mạng tiêu biểu nhất, nhưng vẫn rất đáng đọc đối với độc giả quan tâm đến lập trình thi đấu.
