<span id="&#x5B9A;&#x4E49;"></span>

## Định nghĩa

Nguyên lý ngăn kéo, còn gọi là nguyên lý chuồng bồ câu (the pigeonhole principle).

Nó thường được dùng trong các chứng minh tồn tại và trong việc tìm lời giải ở trường hợp xấu nhất.

<span id="&#x7B80;&#x5355;&#x60C5;&#x51B5;"></span>

## Trường hợp đơn giản

Nếu đưa $n+1$ vật vào $n$ nhóm, thì tồn tại ít nhất một nhóm có hai vật trở lên.

Định lý này khá hiển nhiên. Ta có thể chứng minh bằng phản chứng: nếu mỗi nhóm có nhiều nhất $1$ vật, tổng số vật tối đa chỉ là $1\times n$, trong khi thực tế có $n+1$ vật, mâu thuẫn.

<span id="&#x63A8;&#x5E7F;"></span>

## Mở rộng

Nếu đưa $n$ vật vào $k$ nhóm, thì tồn tại ít nhất một nhóm chứa không ít hơn $\left \lceil \dfrac{n}{k} \right \rceil$ vật.

Dạng mở rộng cũng có thể chứng minh bằng phản chứng: nếu mỗi nhóm chứa ít hơn $\left \lceil \dfrac{n}{k} \right \rceil$ vật, thì tổng số vật $S\leq (\left \lceil \dfrac{n}{k} \right \rceil -1 ) \times k=k\left\lceil \dfrac{n}{k} \right\rceil-k < k(\dfrac{n}{k}+1)-k=n$, mâu thuẫn.

Ngoài ra, có thể thay phân hoạch bằng phủ mà kết luận vẫn không đổi.<br>
Cho tập $S$, xét một họ các tập con khác rỗng của $S$: $\{A_1,A_2\ldots A_k\}$.

-   Nếu thỏa $\bigcup_{i=1}^k A_i=S$, ta gọi đó là một phủ (cover) của $S$.
-   Nếu một phủ còn thỏa $i\neq j\to A_i\cap A_j=\varnothing$, ta gọi đó là một phân hoạch của $S$.

Nguyên lý chuồng bồ câu có thể được phát biểu như sau: với một phủ $\{A_1,A_2\ldots A_k\}$ của $S$, tồn tại ít nhất một tập $A_i$ thỏa $\left\vert A_i \right\vert \geq \left\lceil \dfrac{\left\vert S \right\vert}{k} \right\rceil$.

<span id="&#x53C2;&#x8003;&#x6587;&#x732E;"></span>

## Tài liệu tham khảo

-   [Wikipedia: Pigeonhole principle](https://en.wikipedia.org/wiki/Pigeonhole_principle)
-   *Discrete Mathematics and Its Applications*: Chapter 6, Section 1
