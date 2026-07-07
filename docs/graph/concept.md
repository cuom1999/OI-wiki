Trang này tóm lược một số khái niệm trong lý thuyết đồ thị. Không phải khái niệm nào cũng thường gặp trong OI; với OIer, nắm phần cơ bản trong trang này là đủ. Khi gặp khái niệm chưa rõ trong quá trình học, có thể quay lại tra cứu.

??? warning "Cảnh báo"
    Các định nghĩa liên quan đến lý thuyết đồ thị thường khác nhau giữa các giáo trình. Khi gặp chúng, cần phán đoán theo ngữ cảnh.

## Đồ thị

**Đồ thị (graph)** là một cặp có thứ tự $G=(V(G), E(G))$, trong đó $V(G)$ là một tập không rỗng, gọi là **tập đỉnh (vertex set)**. Mỗi phần tử của $V(G)$ được gọi là **đỉnh (vertex)** hoặc **nút (node)**; khi không gây nhầm lẫn, bài viết cũng gọi tắt là **điểm**. $E(G)$ là tập các cạnh giữa các đỉnh của $V(G)$, gọi là **tập cạnh (edge set)**.

Thường dùng $G=(V,E)$ để biểu diễn đồ thị.

Khi $V,E$ đều là tập hữu hạn, $G$ được gọi là **đồ thị hữu hạn**.

Khi $V$ hoặc $E$ là tập vô hạn, $G$ được gọi là **đồ thị vô hạn**.

Có nhiều loại đồ thị, bao gồm **đồ thị vô hướng (undirected graph)**, **đồ thị có hướng (directed graph)**, **đồ thị hỗn hợp (mixed graph)**, v.v.

Nếu $G$ là đồ thị vô hướng, mỗi phần tử trong $E$ là một cặp không thứ tự $(u, v)$, gọi là **cạnh vô hướng (undirected edge)**, gọi tắt là **cạnh (edge)**, trong đó $u, v \in V$. Đặt $e = (u, v)$, khi đó $u$ và $v$ được gọi là các **đầu mút (endpoint)** của $e$.

Nếu $G$ là đồ thị có hướng, mỗi phần tử trong $E$ là một cặp có thứ tự $(u, v)$, đôi khi cũng viết là $u \to v$, gọi là **cạnh có hướng (directed edge)** hoặc **cung (arc)**; khi không gây nhầm lẫn cũng có thể gọi là **cạnh (edge)**. Đặt $e = u \to v$, khi đó $u$ được gọi là **điểm đầu (tail)** của $e$, $v$ được gọi là **điểm cuối (head)** của $e$; điểm đầu và điểm cuối cũng được gọi là các **đầu mút (endpoint)** của $e$. Đồng thời, $u$ là tiền nhiệm trực tiếp của $v$, còn $v$ là kế nhiệm trực tiếp của $u$.

???+ note "Vì sao điểm đầu là tail, điểm cuối là head?"
    Cạnh thường được biểu diễn bằng mũi tên, mà mũi tên đi từ "đuôi" đến "đầu".

Nếu $G$ là đồ thị hỗn hợp, trong $E$ vừa có **cạnh có hướng** vừa có **cạnh vô hướng**.

Nếu mỗi cạnh $e_k=(u_k,v_k)$ của $G$ đều được gán một số làm **trọng số** của cạnh đó, thì $G$ được gọi là **đồ thị có trọng số**. Nếu các trọng số đều là số thực dương, $G$ được gọi là **đồ thị trọng số dương**.

Số đỉnh $\left| V(G) \right|$ của đồ thị $G$ cũng được gọi là **cấp (order)** của đồ thị $G$.

Nói một cách trực quan, đồ thị được tạo thành từ một số điểm và các cạnh nối giữa các điểm.

## Kề

Trong đồ thị vô hướng $G = (V, E)$, nếu đỉnh $v$ là một đầu mút của cạnh $e$, thì $v$ và $e$ được gọi là **liên thuộc (incident)**. Với hai đỉnh $u$ và $v$, nếu tồn tại cạnh $(u, v)$, thì $u$ và $v$ được gọi là **kề nhau (adjacent)**.

**Lân cận (neighborhood)** của một đỉnh $v \in V$ là tập tất cả các đỉnh kề với nó, ký hiệu là $N(v)$.

Lân cận của một tập đỉnh $S$ là tập tất cả các đỉnh kề với ít nhất một đỉnh trong $S$, ký hiệu là $N(S)$, tức là:

$$
N(S) = \bigcup_{v \in S} N(v)
$$

## Đồ thị đơn

**Khuyên (loop)**: với cạnh $e = (u, v)$ trong $E$, nếu $u = v$, thì $e$ được gọi là một khuyên.

**Cạnh song song (multiple edge)**: nếu trong $E$ tồn tại hai phần tử (cạnh) hoàn toàn giống nhau $e_1, e_2$, thì chúng được gọi là một cặp cạnh song song.

**Đồ thị đơn (simple graph)**: nếu một đồ thị không có khuyên và cạnh song song, nó được gọi là đồ thị đơn. Trong đồ thị vô hướng đơn có ít nhất hai đỉnh, luôn tồn tại hai đỉnh có cùng bậc. ([Nguyên lý Dirichlet](../math/combinatorics/drawer-principle.md))

Nếu một đồ thị có khuyên hoặc cạnh song song, nó được gọi là **đa đồ thị (multigraph)**.

??? warning "Cảnh báo"
    Trong đồ thị vô hướng, $(u, v)$ và $(v, u)$ được tính là một cặp cạnh song song; còn trong đồ thị có hướng, $u \to v$ và $v \to u$ không phải là cạnh song song.

??? warning "Cảnh báo"
    Trong đề bài, nếu không có mô tả đặc biệt, khuyên và cạnh song song có thể tồn tại, nên khi giải bài cần xét riêng.

## Bậc

Số cạnh liên thuộc với một đỉnh $v$ được gọi là **bậc (degree)** của đỉnh đó, ký hiệu là $d(v)$. Đặc biệt, với cạnh $(v, v)$, mỗi cạnh như vậy đóng góp $2$ vào $d(v)$.

Với đồ thị vô hướng đơn, có $d(v) = \left| N(v) \right|$.

Định lý bắt tay, còn gọi là định lý cơ bản của lý thuyết đồ thị: với mọi đồ thị vô hướng $G = (V, E)$, có $\sum_{v \in V} d(v) = 2 \left| E \right|$.

Hệ quả: trong mọi đồ thị, số đỉnh có bậc lẻ luôn là số chẵn.

Nếu $d(v) = 0$, thì $v$ được gọi là **đỉnh cô lập (isolated vertex)**.

Nếu $d(v) = 1$, thì $v$ được gọi là **đỉnh lá (leaf vertex)**/**đỉnh treo (pendant vertex)**.

Nếu $2 \mid d(v)$, thì $v$ được gọi là **đỉnh chẵn (even vertex)**.

Nếu $2 \nmid d(v)$, thì $v$ được gọi là **đỉnh lẻ (odd vertex)**. Số đỉnh lẻ trong một đồ thị là số chẵn.

Nếu $d(v) = \left| V \right| - 1$, thì $v$ được gọi là **đỉnh phổ quát (universal vertex)**.

Với một đồ thị, giá trị nhỏ nhất trong bậc của mọi đỉnh được gọi là **bậc nhỏ nhất (minimum degree)** của $G$, ký hiệu là $\delta (G)$; giá trị lớn nhất được gọi là **bậc lớn nhất (maximum degree)**, ký hiệu là $\Delta (G)$. Tức là $\delta (G) = \min_{v \in V(G)} d(v)$ và $\Delta (G) = \max_{v \in V(G)} d(v)$.

Trong đồ thị có hướng $G = (V, E)$, số cạnh có điểm đầu là một đỉnh $v$ được gọi là **bậc ra (out-degree)** của đỉnh đó, ký hiệu là $d^+(v)$. Số cạnh có điểm cuối là một đỉnh $v$ được gọi là **bậc vào (in-degree)** của đỉnh đó, ký hiệu là $d^-(v)$. Khi đó $d^+(v)+d^-(v)=d(v)$.

Với mọi đồ thị có hướng $G = (V, E)$, có:

$$
\sum_{v \in V} d^+(v) = \sum_{v \in V} d^-(v) = \left| E \right|
$$

Nếu với một đồ thị vô hướng $G = (V, E)$, bậc của mọi đỉnh đều là một hằng số cố định $k$, thì $G$ được gọi là **đồ thị $k$-chính quy ($k$-regular graph)**.

Nếu với một dãy $a$ tồn tại một đồ thị $G$ nhận dãy đó làm dãy bậc, thì $a$ được gọi là **dãy đồ thị hóa được**.

Nếu với một dãy $a$ tồn tại một đồ thị đơn $G$ nhận dãy đó làm dãy bậc, thì $a$ được gọi là **dãy đơn đồ thị hóa được**.

## Đường đi

**Hành trình (walk)**: hành trình là một dãy các cạnh nối một chuỗi đỉnh, có thể có độ dài hữu hạn hoặc vô hạn. Nói một cách hình thức, một hành trình hữu hạn $w$ là một dãy cạnh $e_1, e_2, \ldots, e_k$ sao cho tồn tại một dãy đỉnh $v_0, v_1, \ldots, v_k$ thỏa mãn $e_i = (v_{i-1}, v_i)$, với $i \in [1, k]$. Hành trình như vậy có thể viết gọn là $v_0 \to v_1 \to v_2 \to \cdots \to v_k$. Thông thường, số cạnh $k$ được gọi là **độ dài** của hành trình này (nếu cạnh có trọng số, độ dài thường là tổng trọng số các cạnh trên hành trình; trong đề bài cũng có thể có định nghĩa khác).

**Vết (trail)**: với một hành trình $w$, nếu $e_1, e_2, \ldots, e_k$ đôi một khác nhau, thì $w$ được gọi là một vết.

**Đường đi (path)**, còn gọi là **đường đi đơn (simple path)**: với một vết $w$, nếu các đỉnh trong dãy đỉnh mà nó nối đôi một khác nhau, thì $w$ được gọi là một đường đi.

**Mạch (circuit)**: với một vết $w$, nếu $v_0 = v_k$, thì $w$ được gọi là một mạch.

**Chu trình/vòng (cycle)**, còn gọi là **mạch đơn/chu trình đơn (simple circuit)**: với một mạch $w$, nếu $v_0 = v_k$ là lần lặp đỉnh duy nhất trong dãy đỉnh, thì $w$ được gọi là một chu trình.

??? warning "Cảnh báo"
    Định nghĩa về đường đi có thể khác nhau giữa các tài liệu. Ví dụ, "đường đi" có thể chỉ "hành trình" trong bài này, còn "chu trình" có thể chỉ "mạch" trong bài này. Nếu trong đề bài gặp các thuật ngữ tương tự mà không có mô tả đặc biệt như "đường đi đơn"/"đường đi không đơn" (tức là "hành trình" trong bài này), tốt nhất nên xác định rõ nghĩa theo ngữ cảnh.

## Đồ thị con

Với một đồ thị $G = (V, E)$, nếu tồn tại một đồ thị khác $H = (V', E')$ thỏa mãn $V' \subseteq V$ và $E' \subseteq E$, thì $H$ được gọi là **đồ thị con (subgraph)** của $G$, ký hiệu là $H \subseteq G$.

Nếu với $H \subseteq G$, với mọi $u, v \in V'$, từ $(u, v) \in E$ luôn suy ra $(u, v) \in E'$, thì $H$ được gọi là **đồ thị con cảm sinh/đồ thị con sinh bởi đỉnh (induced subgraph)** của $G$.

Một đồ thị con cảm sinh chỉ được xác định bởi tập đỉnh của đồ thị con. Vì vậy, đồ thị con cảm sinh có tập đỉnh là $V'$ ($V' \subseteq V$) được gọi là đồ thị con do $V'$ cảm sinh, ký hiệu là $G \left[ V' \right]$.

Nếu $H \subseteq G$ thỏa mãn $V' = V$, thì $H$ được gọi là **đồ thị con bao trùm (spanning subgraph)** của $G$.

$G$ là đồ thị con, đồ thị con bao trùm và đồ thị con cảm sinh của chính nó; [đồ thị không cạnh](#do-thi-dac-biet) là một đồ thị con bao trùm của $G$. Đồ thị gốc $G$ và đồ thị không cạnh đều là các đồ thị con tầm thường của $G$.

Nếu một đồ thị vô hướng $G$ có một đồ thị con bao trùm $F$ là đồ thị $k$-chính quy, thì $F$ được gọi là một **$k$-nhân tử ($k$-factor)** của $G$.

Nếu đồ thị con cảm sinh $H = G \left[ V^\ast \right]$ của đồ thị có hướng $G = (V, E)$ thỏa mãn: với mọi $v \in V^\ast$, nếu $(v, u) \in E$ thì $u \in V^\ast$, thì $H$ được gọi là một **đồ thị con đóng (closed subgraph)** của $G$.

## Liên thông

### Đồ thị vô hướng

Với một đồ thị vô hướng $G = (V, E)$, với $u, v \in V$, nếu tồn tại một hành trình sao cho $v_0 = u, v_k = v$, thì $u$ và $v$ được gọi là **liên thông (connected)**. Theo định nghĩa, mọi đỉnh liên thông với chính nó, và hai đầu mút của mọi cạnh liên thông với nhau.

Nếu đồ thị vô hướng $G = (V, E)$ thỏa mãn mọi cặp đỉnh bất kỳ đều liên thông, thì $G$ được gọi là **đồ thị liên thông (connected graph)**; tính chất này của $G$ được gọi là **tính liên thông (connectivity)**.

Nếu $H$ là một đồ thị con liên thông của $G$, và không tồn tại $F$ thỏa mãn $H\subsetneq F \subseteq G$ đồng thời $F$ là đồ thị liên thông, thì $H$ là một **thành phần liên thông (connected component)** của $G$ (đồ thị con liên thông cực đại).

### Đồ thị có hướng

Với một đồ thị có hướng $G = (V, E)$, với $u, v \in V$, nếu tồn tại một hành trình sao cho $v_0 = u, v_k = v$, thì $u$ được gọi là **đến được** $v$. Theo định nghĩa, mọi đỉnh đến được chính nó, và điểm đầu của mọi cạnh đến được điểm cuối. (Liên thông trong đồ thị vô hướng cũng có thể xem là đến được hai chiều.)

Nếu các đỉnh của một đồ thị có hướng đôi một đến được nhau theo cả hai chiều, thì đồ thị đó được gọi là **liên thông mạnh (strongly connected)**.

Nếu sau khi thay các cạnh của một đồ thị có hướng bằng cạnh vô hướng mà thu được một đồ thị liên thông, thì đồ thị có hướng ban đầu được gọi là **liên thông yếu (weakly connected)**.

Tương tự thành phần liên thông, cũng có **thành phần liên thông yếu (weakly connected component)** (đồ thị con liên thông yếu cực đại) và **thành phần liên thông mạnh (strongly connected component)** (đồ thị con liên thông mạnh cực đại).

Xem thuật toán liên quan tại [thành phần liên thông mạnh](./scc.md).

### Cắt

Xem thuật toán liên quan tại [đỉnh cắt và cầu](./cut.md) cũng như [thành phần song liên thông](./bcc.md).

Trong phần này, "liên thông" của đồ thị có hướng thường chỉ "liên thông mạnh".

Với đồ thị liên thông $G = (V, E)$, nếu $V'\subseteq V$ và $G\left[V\setminus V'\right]$ (tức là xóa các điểm trong $V'$ khỏi $G$) không phải là đồ thị liên thông, thì $V'$ là một **tập cắt đỉnh (vertex cut/separating set)** của đồ thị $G$. Tập cắt đỉnh có kích thước một còn được gọi là **đỉnh cắt (cut vertex)**.

Với đồ thị liên thông $G = (V, E)$ và số nguyên $k$, nếu $|V|\ge k+1$ và $G$ không tồn tại tập cắt đỉnh có kích thước $k-1$, thì đồ thị $G$ được gọi là **$k$-liên thông đỉnh ($k$-vertex-connected)**; giá trị lớn nhất của $k$ để mệnh đề trên đúng được gọi là **độ liên thông đỉnh (vertex connectivity)** của đồ thị $G$, ký hiệu là $\kappa(G)$. (Với đồ thị không đầy đủ, độ liên thông đỉnh chính là kích thước của tập cắt đỉnh nhỏ nhất; còn độ liên thông đỉnh của đồ thị đầy đủ $K_n$ là $n-1$.)

Với đồ thị $G = (V, E)$ và $u, v\in V$ thỏa mãn $u\ne v$, $u$ và $v$ không kề nhau, $u$ đến được $v$, nếu $V'\subseteq V$, $u, v\notin V'$, và trong $G\left[V\setminus V'\right]$ thì $u$ và $v$ không liên thông, thì $V'$ được gọi là tập cắt đỉnh từ $u$ đến $v$. Kích thước của tập cắt đỉnh nhỏ nhất từ $u$ đến $v$ được gọi là **độ liên thông đỉnh cục bộ (local connectivity)** từ $u$ đến $v$, ký hiệu là $\kappa(u, v)$.

Có định nghĩa tương tự cho cạnh:

Với đồ thị liên thông $G = (V, E)$, nếu $E'\subseteq E$ và $G' = (V, E\setminus E')$ (tức là xóa các cạnh trong $E'$ khỏi $G$) không phải là đồ thị liên thông, thì $E'$ là một **tập cắt cạnh (edge cut)** của đồ thị $G$. Tập cắt cạnh có kích thước một còn được gọi là **cầu (bridge)**.

Với đồ thị liên thông $G = (V, E)$ và số nguyên $k$, nếu $G$ không tồn tại tập cắt cạnh có kích thước $k-1$, thì đồ thị $G$ được gọi là **$k$-liên thông cạnh ($k$-edge-connected)**; giá trị lớn nhất của $k$ để mệnh đề trên đúng được gọi là **độ liên thông cạnh (edge connectivity)** của đồ thị $G$, ký hiệu là $\lambda(G)$. (Với mọi đồ thị, độ liên thông cạnh chính là kích thước của tập cắt cạnh nhỏ nhất.)

Với đồ thị $G = (V, E)$ và $u, v\in V$ thỏa mãn $u\ne v$, $u$ đến được $v$, nếu $E'\subseteq E$, và trong $G'=(V, E\setminus E')$ thì $u$ và $v$ không liên thông, thì $E'$ được gọi là tập cắt cạnh từ $u$ đến $v$. Kích thước của tập cắt cạnh nhỏ nhất từ $u$ đến $v$ được gọi là **độ liên thông cạnh cục bộ (local edge-connectivity)** từ $u$ đến $v$, ký hiệu là $\lambda(u, v)$.

**Song liên thông đỉnh (biconnected)** gần như hoàn toàn giống **$2$-liên thông đỉnh**, ngoại trừ đồ thị gồm hai điểm nối với nhau bằng một cạnh: nó là song liên thông đỉnh nhưng không phải là $2$-liên thông đỉnh. Nói cách khác, đồ thị liên thông không có đỉnh cắt là song liên thông đỉnh.

**Song liên thông cạnh ($2$-edge-connected)** hoàn toàn giống **$2$-liên thông cạnh**. Nói cách khác, đồ thị liên thông không có cầu là song liên thông cạnh.

Tương tự thành phần liên thông, cũng có **thành phần song liên thông đỉnh (biconnected component)** (đồ thị con song liên thông đỉnh cực đại) và **thành phần song liên thông cạnh ($2$-edge-connected component)** (đồ thị con song liên thông cạnh cực đại).

**Định lý Whitney**: với mọi đồ thị $G$, có $\kappa(G)\le \lambda(G)\le \delta(G)$. (Ba hạng trong bất đẳng thức lần lượt là độ liên thông đỉnh, độ liên thông cạnh và bậc nhỏ nhất.)

## Đồ thị thưa/đồ thị dày

Nếu số cạnh của một đồ thị nhỏ hơn rất nhiều so với bình phương số đỉnh của nó, thì đó là một **đồ thị thưa (sparse graph)**.

Nếu số cạnh của một đồ thị gần với bình phương số đỉnh của nó, thì đó là một **đồ thị dày (dense graph)**.

Hai khái niệm này không có định nghĩa nghiêm ngặt, thường được dùng để thảo luận sự khác biệt về hiệu quả giữa thuật toán có [độ phức tạp thời gian](../basic/complexity.md) $O(|V|^2)$ và thuật toán $O(|E|)$ (trên đồ thị dày, hiệu quả của hai loại thuật toán này tương đương; còn trên đồ thị thưa, thuật toán $O(|E|)$ hiệu quả hơn rõ rệt).

## Đồ thị bù

Với đồ thị vô hướng đơn $G = (V, E)$, **đồ thị bù (complement graph)** của nó là đồ thị được ký hiệu là $\bar G$, thỏa mãn $V \left( \bar G \right) = V \left( G \right)$, và với mọi cặp đỉnh $(u, v)$, $(u, v) \in E \left( \bar G \right)$ khi và chỉ khi $(u, v) \notin E \left( G \right)$.

## Đồ thị chuyển vị

Với đồ thị có hướng $G = (V, E)$, **đồ thị chuyển vị (transpose graph)** của nó là đồ thị giữ nguyên tập đỉnh và đảo chiều mọi cạnh, tức là: nếu đồ thị chuyển vị của $G$ là $G'=(V, E')$, thì $E'=\{(v, u)|(u, v)\in E\}$.

## Đồ thị đặc biệt {#do-thi-dac-biet}

Nếu đồ thị vô hướng đơn $G$ thỏa mãn giữa mọi cặp đỉnh khác nhau đều có cạnh, thì $G$ được gọi là **đồ thị đầy đủ (complete graph)**; đồ thị đầy đủ cấp $n$ được ký hiệu là $K_n$. Nếu đồ thị có hướng $G$ thỏa mãn giữa mọi cặp đỉnh khác nhau đều có hai cạnh khác hướng, thì $G$ được gọi là **đồ thị có hướng đầy đủ (complete digraph)**.

Đồ thị có tập cạnh rỗng được gọi là **đồ thị không cạnh (edgeless graph)**, **đồ thị rỗng (empty graph)** hoặc **đồ thị không (null graph)**; đồ thị không cạnh cấp $n$ được ký hiệu là $\overline{K}_n$ hoặc $N_n$. $N_n$ và $K_n$ là đồ thị bù của nhau.

??? warning "Cảnh báo"
    **Đồ thị không (null graph)** cũng có thể chỉ **đồ thị cấp không (order-zero graph)** $K_0$, tức là đồ thị có cả tập đỉnh và tập cạnh đều rỗng.

Nếu đồ thị có hướng đơn $G$ thỏa mãn giữa mọi cặp đỉnh khác nhau có đúng một cạnh một chiều, thì $G$ được gọi là **đồ thị đấu loại (tournament graph)**.

Nếu các cạnh của đồ thị vô hướng đơn $G = \left( V, E \right)$ vừa đúng tạo thành một chu trình, thì $G$ được gọi là **đồ thị chu trình/vòng (cycle graph)**; đồ thị chu trình cấp $n$ ($n \geq 3$) được ký hiệu là $C_n$. Điều kiện cần và đủ để một đồ thị là đồ thị chu trình là nó là đồ thị liên thông $2$-chính quy.

Nếu đồ thị vô hướng đơn $G = \left( V, E \right)$ thỏa mãn tồn tại một đỉnh $v$ là đỉnh phổ quát và giữa các đỉnh còn lại không có cạnh nối, thì $G$ được gọi là **đồ thị sao/đồ thị hoa cúc (star graph)**; đồ thị sao cấp $n + 1$ ($n \geq 1$) được ký hiệu là $S_n$.

Nếu đồ thị vô hướng đơn $G = \left( V, E \right)$ thỏa mãn tồn tại một đỉnh $v$ là đỉnh phổ quát và các đỉnh còn lại tạo thành một chu trình, thì $G$ được gọi là **đồ thị bánh xe (wheel graph)**; đồ thị bánh xe cấp $n + 1$ ($n \geq 3$) được ký hiệu là $W_n$.

Nếu các cạnh của đồ thị vô hướng đơn $G = \left( V, E \right)$ vừa đúng tạo thành một đường đi đơn, thì $G$ được gọi là **chuỗi (chain/path graph)**; chuỗi cấp $n$ được ký hiệu là $P_n$. Một chuỗi có thể thu được bằng cách xóa một cạnh khỏi một đồ thị chu trình.

Nếu một đồ thị vô hướng liên thông không chứa chu trình, thì nó được gọi là một **cây (tree)**. Xem nội dung liên quan tại [cơ sở về cây](./tree-basic.md).

Nếu một đồ thị vô hướng liên thông chứa đúng một chu trình, thì nó được gọi là một **cây đơn chu trình (pseudotree)**.

Nếu một đồ thị có hướng liên thông yếu có bậc vào của mọi đỉnh đều bằng $1$, thì nó được gọi là một **cây đơn chu trình hướng ra**.

Nếu một đồ thị có hướng liên thông yếu có bậc ra của mọi đỉnh đều bằng $1$, thì nó được gọi là một **cây đơn chu trình hướng vào**.

Nhiều cây có thể tạo thành một **rừng (forest)**; nhiều cây đơn chu trình có thể tạo thành **rừng đơn chu trình (pseudoforest)**; nhiều cây đơn chu trình hướng ra có thể tạo thành **rừng đơn chu trình hướng ra**; nhiều cây đơn chu trình hướng vào có thể tạo thành **rừng đơn chu trình hướng vào (functional graph)**.

Nếu trong một đồ thị vô hướng liên thông, mỗi cạnh xuất hiện trong nhiều nhất một chu trình, thì nó được gọi là một **xương rồng (cactus)**. Nhiều xương rồng có thể tạo thành một **sa mạc**.

Nếu tập đỉnh của một đồ thị có thể được chia thành hai phần sao cho bên trong mỗi phần đều không có cạnh nối, thì đồ thị đó là một **đồ thị hai phía (bipartite graph)**. Nếu trong đồ thị hai phía, giữa mọi cặp đỉnh không cùng một phần đều có cạnh nối, thì đồ thị đó là một **đồ thị hai phía đầy đủ (complete bipartite graph/biclique)**; đồ thị hai phía đầy đủ có hai phần lần lượt gồm $n$ đỉnh và $m$ đỉnh được ký hiệu là $K_{n, m}$. Xem nội dung liên quan tại [đồ thị hai phía](./bi-graph.md).

Nếu một đồ thị có thể vẽ trên một mặt phẳng sao cho không có hai cạnh nào cắt nhau tại điểm không phải đầu mút, thì đồ thị đó là một **đồ thị phẳng (planar graph)**. Với đồ thị phẳng liên thông đơn $G=(V, E)$ và $|V|\ge 3$, có $|E|\le 3|V|-6$.

**Định lý Kuratowski**: một đồ thị là đồ thị phẳng khi và chỉ khi nó không chứa đồ thị con **đồng phôi (homeomorphic)** với $K_5$ hoặc $K_{3, 3}$. Trong ngữ cảnh này, đồ thị $G$ và đồ thị $G'$ đồng phôi nghĩa là cả hai đều có thể trở thành cùng một đồ thị bằng cách thêm một số đỉnh bậc $2$ trên các cạnh[^ref1].

## Đẳng cấu

Hai đồ thị $G$ và $H$ được gọi là **đẳng cấu (isomorphic)**, ký hiệu là $G \cong H$, nếu tồn tại một song ánh $f : V(G) \to V(H)$ thỏa mãn $(u,v)\in E(G)$ khi và chỉ khi $(f(u),f(v))\in E(H)$. Khi đó, $f$ được gọi là một **đẳng cấu (isomorphism)** từ $G$ đến $H$.

Từ định nghĩa suy ra, nếu $G \cong H$ thì phải thỏa mãn:

-   $|V(G)|=|V(H)|,|E(G)|=|E(H)|$
-   Dãy bậc của các đỉnh trong $G$ và $H$, sắp theo thứ tự không tăng, là như nhau
-   $G$ và $H$ có các đồ thị con cảm sinh đẳng cấu

## Phép toán hai ngôi trên đồ thị vô hướng đơn

Với đồ thị vô hướng đơn, có thể định nghĩa các phép toán hai ngôi sau:

**Giao (intersection)**: giao của hai đồ thị $G = \left( V_1, E_1 \right), H = \left( V_2, E_2 \right)$ được định nghĩa là đồ thị $G \cap H = \left( V_1 \cap V_2, E_1 \cap E_2 \right)$.

Giao của hai đồ thị vô hướng đơn vẫn là đồ thị vô hướng đơn.

**Hợp (union)**: hợp của hai đồ thị $G = \left( V_1, E_1 \right), H = \left( V_2, E_2 \right)$ được định nghĩa là đồ thị $G \cup H = \left( V_1 \cup V_2, E_1 \cup E_2 \right)$.

**Tổng (sum)/tổng trực tiếp (direct sum)**: với $G = \left( V_1, E_1 \right), H = \left( V_2, E_2 \right)$, dựng một đồ thị $H' \cong H$ sao cho $V \left( H' \right) \cap V_1 = \varnothing$ ($H'$ có thể bằng $H$ nếu hai tập đỉnh vốn đã rời nhau). Khi đó, bất kỳ đồ thị nào đẳng cấu với $G \cup H'$ được gọi là tổng/tổng trực tiếp/hợp rời của $G$ và $H$, ký hiệu là $G + H$ hoặc $G \oplus H$.

Nếu tập đỉnh của $G$ và $H$ vốn đã rời nhau, thì $G \cup H = G + H$.

Ví dụ, rừng có thể được định nghĩa là tổng của một số cây.

???+ note "Khác nhau giữa hợp và tổng"
    "Hợp" gộp các điểm và cạnh "cùng tên" trong hai đồ thị, còn "tổng" thì không.

## Tập đỉnh/tập cạnh đặc biệt

### Tập thống trị

Với đồ thị vô hướng $G=(V, E)$, nếu $V'\subseteq V$ và với mọi $v\in(V\setminus V')$ tồn tại cạnh $(u, v)\in E$ thỏa mãn $u\in V'$, thì $V'$ là một **tập thống trị (dominating set)** của đồ thị $G$.

Kích thước của tập thống trị nhỏ nhất của đồ thị vô hướng $G$ được ký hiệu là $\gamma(G)$. Tìm tập thống trị nhỏ nhất của một đồ thị là bài toán [NP-khó](../misc/cc-basic.md#np-hard).

Với đồ thị có hướng $G=(V, E)$, nếu $V'\subseteq V$ và với mọi $v\in(V\setminus V')$ tồn tại cạnh $(u, v)\in E$ thỏa mãn $u\in V'$, thì $V'$ là một **tập thống trị ra (out-dominating set)** của đồ thị $G$. Tương tự, có thể định nghĩa **tập thống trị vào (in-dominating set)** của đồ thị có hướng.

Kích thước của tập thống trị ra nhỏ nhất của đồ thị có hướng $G$ được ký hiệu là $\gamma^+(G)$, kích thước của tập thống trị vào nhỏ nhất được ký hiệu là $\gamma^-(G)$.

### Tập thống trị cạnh

Với đồ thị $G=(V, E)$, nếu $E'\subseteq E$ và với mọi $e\in(E\setminus E')$ tồn tại một cạnh trong $E'$ có chung đầu mút với nó, thì $E'$ được gọi là một **tập thống trị cạnh (edge dominating set)** của đồ thị $G$.

Tìm tập thống trị cạnh nhỏ nhất của một đồ thị là bài toán [NP-khó](../misc/cc-basic.md#np-hard).

### Tập độc lập

Với đồ thị $G=(V, E)$, nếu $V'\subseteq V$ và mọi cặp điểm trong $V'$ đều không kề nhau, thì $V'$ là một **tập độc lập (independent set)** của đồ thị $G$.

Kích thước của tập độc lập lớn nhất của đồ thị $G$ được ký hiệu là $\alpha(G)$. Tìm tập độc lập lớn nhất của một đồ thị là bài toán [NP-khó](../misc/cc-basic.md#np-hard).

### Ghép cặp

Với đồ thị $G=(V, E)$, nếu $E'\subseteq E$, mọi cặp cạnh khác nhau trong $E'$ đều không có đầu mút chung, và không có cạnh nào trong $E'$ là khuyên, thì $E'$ là một **ghép cặp (matching)** của đồ thị $G$, cũng có thể gọi là **tập cạnh độc lập (independent edge set)**. Nếu một đỉnh là đầu mút của một cạnh nào đó trong ghép cặp, thì đỉnh đó được gọi là **được ghép (matched)/bão hòa (saturated)**; ngược lại được gọi là **không được ghép (unmatched)**.

Ghép cặp có số cạnh nhiều nhất được gọi là **ghép cặp lớn nhất theo số cạnh (maximum-cardinality matching)** của một đồ thị. Kích thước của ghép cặp lớn nhất của đồ thị $G$ được ký hiệu là $\nu(G)$.

Nếu cạnh có trọng số, thì ghép cặp có tổng trọng số lớn nhất được gọi là **ghép cặp trọng số lớn nhất (maximum-weight matching)** của một đồ thị.

Nếu sau khi thêm bất kỳ cạnh nào vào một ghép cặp thì nó không còn là ghép cặp nữa, thì ghép cặp này là một **ghép cặp cực đại (maximal matching)**. Ghép cặp cực đại có kích thước lớn nhất chính là ghép cặp lớn nhất; mọi ghép cặp lớn nhất đều là ghép cặp cực đại. Ghép cặp cực đại luôn là tập thống trị cạnh, nhưng tập thống trị cạnh không phải lúc nào cũng là ghép cặp. Kích thước của ghép cặp cực đại có kích thước nhỏ nhất bằng kích thước của tập thống trị cạnh nhỏ nhất, nhưng tập thống trị cạnh nhỏ nhất không phải lúc nào cũng là ghép cặp. Tìm ghép cặp cực đại có kích thước nhỏ nhất là bài toán NP-khó.

Nếu trong một ghép cặp, mọi đỉnh đều được ghép, thì ghép cặp đó là một **ghép cặp hoàn hảo (perfect matching)**. Nếu trong một ghép cặp chỉ có một đỉnh không được ghép, thì ghép cặp đó là một **ghép cặp gần hoàn hảo (near-perfect matching)**.

Đếm số ghép cặp hoặc ghép cặp hoàn hảo của một đồ thị thông thường hay đồ thị hai phía đều là bài toán [#P-đầy đủ](../misc/cc-basic.md#p_1).

Với một ghép cặp $M$, nếu một đường đi bắt đầu từ một đỉnh chưa được ghép, và trong mỗi cặp cạnh kề nhau có đúng một cạnh thuộc ghép cặp còn cạnh kia không thuộc ghép cặp, thì đường đi đó được gọi là một **đường luân phiên (alternating path)**; một đường luân phiên kết thúc ở một đỉnh chưa được ghép được gọi là một **đường tăng (augmenting path)**.

**Định lý Tutte**: đồ thị vô hướng $G$ cấp $n$ có ghép cặp hoàn hảo khi và chỉ khi với mọi $V' \subset V(G)$, $p_{\text{odd}}(G-V')\leq |V'|$, trong đó $p_{\text{odd}}$ biểu thị số thành phần liên thông có cấp lẻ.

**Định lý Tutte (hệ quả)**: mọi đồ thị $3$-chính quy không có cầu đều có ghép cặp hoàn hảo.

### Phủ đỉnh

Với đồ thị $G=(V, E)$, nếu $V'\subseteq V$ và với mọi $e\in E$, ít nhất một đầu mút của $e$ nằm trong $V'$, thì $V'$ được gọi là một **phủ đỉnh (vertex cover)** của đồ thị $G$.

Trong đồ thị không có đỉnh cô lập, mọi phủ đỉnh đều là tập thống trị; tuy nhiên, một phủ đỉnh tối tiểu theo bao hàm không phải lúc nào cũng là một tập thống trị tối tiểu theo bao hàm.

Điều kiện cần và đủ để một tập đỉnh là phủ đỉnh là phần bù của nó là tập độc lập. Do đó, phần bù của phủ đỉnh nhỏ nhất là tập độc lập lớn nhất. Tìm phủ đỉnh nhỏ nhất của một đồ thị là bài toán [NP-khó](../misc/cc-basic.md#np-hard).

Kích thước của bất kỳ ghép cặp nào trong một đồ thị đều không vượt quá kích thước của bất kỳ phủ đỉnh nào của nó. Ghép cặp lớn nhất và phủ đỉnh nhỏ nhất của đồ thị hai phía đầy đủ $K_{n, m}$ đều có kích thước $\min(n, m)$.

### Phủ cạnh

Với đồ thị $G=(V, E)$, nếu $E'\subseteq E$ và với mọi $v\in V$, $v$ kề với ít nhất một cạnh trong $E'$, thì $E'$ được gọi là một **phủ cạnh (edge cover)** của đồ thị $G$.

Kích thước của phủ cạnh nhỏ nhất được ký hiệu là $\rho(G)$, có thể thu được bằng cách mở rộng tham lam từ ghép cặp lớn nhất: với mọi đỉnh chưa được ghép, thêm một cạnh kề với nó vào ghép cặp lớn nhất, khi đó thu được một phủ cạnh nhỏ nhất.

Ghép cặp lớn nhất cũng có thể thu được từ phủ cạnh nhỏ nhất: với mỗi cặp cạnh có chung đầu mút trong phủ cạnh nhỏ nhất, xóa một trong hai cạnh.

Kích thước của phủ cạnh nhỏ nhất của một đồ thị cộng với kích thước của ghép cặp lớn nhất bằng số đỉnh của đồ thị, tức là $\rho(G)+\nu(G)=|V(G)|$.

Kích thước của ghép cặp lớn nhất của một đồ thị không vượt quá kích thước của phủ cạnh nhỏ nhất, tức là $\nu(G)\le\rho(G)$. Đặc biệt, ghép cặp hoàn hảo luôn là một phủ cạnh nhỏ nhất, và đây cũng là trường hợp duy nhất để đẳng thức trên xảy ra.

Kích thước của bất kỳ tập độc lập nào trong một đồ thị đều không vượt quá kích thước của bất kỳ phủ cạnh nào của nó. Tập độc lập lớn nhất và phủ cạnh nhỏ nhất của đồ thị hai phía đầy đủ $K_{n, m}$ đều có kích thước $\max(n, m)$.

### Clique

Với đồ thị $G=(V, E)$, nếu $V'\subseteq V$ và mọi cặp đỉnh khác nhau trong $V'$ đều kề nhau, thì $V'$ là một **clique** của đồ thị $G$. Đồ thị con cảm sinh bởi một clique là đồ thị đầy đủ.

Nếu sau khi thêm bất kỳ đỉnh nào vào một clique thì nó không còn là clique nữa, thì clique đó là một **clique cực đại (maximal clique)**.

Kích thước của clique lớn nhất của một đồ thị được ký hiệu là $\omega(G)$; kích thước của clique lớn nhất bằng kích thước của tập độc lập lớn nhất trong đồ thị bù của nó, tức là $\omega(G)=\alpha(\bar{G})$. Tìm clique lớn nhất của một đồ thị là bài toán [NP-khó](../misc/cc-basic.md#np-hard).

## Tài liệu tham khảo

[Trạm trung chuyển OI - Tổng hợp khái niệm lý thuyết đồ thị](https://yhx-12243.github.io/OI-transit/memos/14.html)

[Wikipedia](https://en.wikipedia.org/wiki/Glossary_of_graph_theory_terms) (và các mục tương ứng của những khái niệm liên quan)

Discrete Mathematics, revised edition, Tian Wencheng and Zhou Luxin, eds., Tianjin Literature Press, pp. 184-187

Dai Yiqi, Hu Guanzhang, Chen Wei. Graph Theory and Algebraic Structures [M]. Beijing: Tsinghua University Press, 1995.

[^ref1]: Thao tác này còn được gọi là chia nhỏ (subdivision).
