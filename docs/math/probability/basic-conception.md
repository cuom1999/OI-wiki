<span id="tổng-quan"></span>
## Tổng quan

Khi nghiên cứu một hiện tượng ngẫu nhiên cụ thể, các yếu tố sau thường được xét:

-   Không gian mẫu $\Omega$, chỉ rõ tất cả các kết quả có thể xảy ra của hiện tượng ngẫu nhiên.
-   Trường biến cố $\mathcal{F}$, biểu thị tất cả các biến cố được xét.
-   Xác suất $P$, mô tả mức độ khả năng xảy ra của mỗi biến cố.

<span id="không-gian-mẫu-và-biến-cố-ngẫu-nhiên"></span>
## Không gian mẫu và biến cố ngẫu nhiên

<span id="định-nghĩa"></span>
### Định nghĩa

Trong một hiện tượng ngẫu nhiên, một kết quả có thể xảy ra và không thể chia nhỏ thêm được gọi là **điểm mẫu**. Tập hợp tất cả các điểm mẫu được gọi là **không gian mẫu**, thường được ký hiệu là $\Omega$.

Một **biến cố ngẫu nhiên** là một tập con của không gian mẫu $\Omega$. Nó gồm một số điểm mẫu và được ký hiệu bằng các chữ cái in hoa $A, B, C, \cdots$.

Với kết quả $\omega$ của một hiện tượng ngẫu nhiên và một biến cố ngẫu nhiên $A$, biến cố $A$ được xem là **xảy ra** khi và chỉ khi $\omega \in A$.

Ví dụ, số chấm thu được khi gieo một con xúc xắc một lần là một hiện tượng ngẫu nhiên; không gian mẫu của nó có thể viết là $\Omega=\{1,2,3,4,5,6\}$. Giả sử biến cố ngẫu nhiên $A$ là "số chấm thu được lớn hơn $4$", khi đó $A = \{ 5, 6 \}$. Nếu trong một lần gieo xúc xắc số chấm thu được là $\omega = 3$, thì do $\omega \notin A$, biến cố $A$ không xảy ra.

<span id="các-phép-toán-trên-biến-cố"></span>
### Các phép toán trên biến cố

Do biến cố ngẫu nhiên được định nghĩa là tập con của không gian mẫu $\Omega$, các phép toán trên tập hợp, như giao, hợp, phần bù, v.v., có thể được chuyển sang các biến cố ngẫu nhiên. Ký hiệu được giữ nhất quán với các phép toán tập hợp.

Đặc biệt, hợp của hai biến cố $A \cup B$ cũng có thể viết là $A + B$, còn giao của hai biến cố $A \cap B$ cũng có thể viết là $AB$; khi đó chúng lần lượt cũng được gọi là **biến cố tổng** và **biến cố tích**.

<span id="trường-biến-cố"></span>
## Trường biến cố

Khi nghiên cứu một hiện tượng ngẫu nhiên cụ thể, cần xác định rõ những biến cố nào là đối tượng quan tâm. Theo định nghĩa của biến cố ngẫu nhiên, luôn có $\mathcal{F} \subset 2^{\Omega}$, trong đó ký hiệu $2^{\Omega}$ chỉ tập lũy thừa của $\Omega$, nhưng không nhất thiết phải có $\mathcal{F} = 2^{\Omega}$. Khi không gian mẫu $\Omega$ là hữu hạn, điều này có thể hơi khó hiểu, vì dù $2^{\Omega}$ lớn hơn nhưng vẫn hữu hạn. Tuy nhiên, khi $\Omega$ là một tập vô hạn, lực lượng của $2^{\Omega}$ trở nên lớn hơn nhiều; trong đó khó tránh khỏi một số biến cố có "tính chất không thuận lợi" và cũng không thuộc phạm vi quan tâm. Khi ấy, việc hy sinh một số tính chất mong muốn chỉ để bao quát các biến cố này là không đáng.

Dù $\mathcal{F} = 2^{\Omega}$ không phải là bắt buộc, điều đó không có nghĩa là bất kỳ tập con nào của $2^{\Omega}$ cũng có thể trở thành trường biến cố. Vì thường cần xét xác suất của các biến cố thu được sau khi thực hiện một số phép toán trên biến cố, trường biến cố $\mathcal{F}$ cần thỏa mãn các điều kiện sau:

-   $\varnothing \in \mathcal{F}$;
-   Nếu $A \in \mathcal{F}$, thì biến cố bù $\bar{A} \in \mathcal{F}$;
-   Nếu có một dãy biến cố $A_n \in \mathcal{F}, n = 1, 2, 3\dots$, thì $\bigcup A_n \in \mathcal{F}$.

Nói ngắn gọn, trường biến cố $\mathcal{F}$ đóng dưới phép lấy phần bù và phép hợp đếm được, đồng thời chứa phần tử $\varnothing$.

Có thể chứng minh rằng trường biến cố $\mathcal{F}$ thỏa mãn ba điều kiện trên cũng đóng dưới phép giao đếm được.

Lấy ví dụ gieo xúc xắc. Khi không gian mẫu được viết là $\Omega=\{1,2,3,4,5,6\}$, hai tập hợp sau có thể trở thành trường biến cố:

-   $\mathcal{F}_1 = \{ \varnothing, \Omega \}$
-   $\mathcal{F}_2 = \{ \varnothing, \{1, 3, 5\}, \{2, 4, 6\}, \Omega \}$

Nhưng hai tập hợp sau thì không:

-   $\mathcal{F}_3 = \{ \varnothing, \{1\}, \Omega \}$ (không đóng dưới phép lấy phần bù)
-   $\mathcal{F}_4 = \{ \{1, 3, 5\}, \{2, 4, 6\} \}$ (không chứa $\varnothing$ và không đóng dưới phép hợp)

<span id="xác-suất"></span>
## Xác suất

<span id="định-nghĩa_1"></span>
### Định nghĩa

<span id="định-nghĩa-cổ-điển"></span>
#### Định nghĩa cổ điển

Trong giai đoạn đầu của lý thuyết xác suất, các hiện tượng ngẫu nhiên được xét còn tương đối đơn giản: cụ thể là không gian mẫu $\Omega$ là tập hữu hạn, và về trực giác mọi điểm mẫu đều có khả năng xuất hiện như nhau. Vì thế đã hình thành định nghĩa sau:

Nếu một hiện tượng ngẫu nhiên thỏa mãn:

-   Chỉ có hữu hạn kết quả cơ bản;
-   Mỗi kết quả cơ bản có cùng khả năng xuất hiện;

thì với mỗi biến cố $A$, xác suất của nó được định nghĩa là

$$
P(A)=\frac{\#(A)}{\#(\Omega)}
$$

trong đó $\#(\cdot)$ biểu thị phép đo kích thước của một biến cố ngẫu nhiên, tức một tập hợp.

Về sau, định nghĩa này được nhận thấy có thể mở rộng trực tiếp sang một số tình huống mà $\Omega$ là vô hạn, từ đó dẫn tới [mô hình xác suất hình học](https://baike.baidu.com/item/%E5%87%A0%E4%BD%95%E6%A6%82%E5%9E%8B/4035773).

<span id="định-nghĩa-tiên-đề-hóa"></span>
#### Định nghĩa tiên đề hóa

Định nghĩa dựa trên nhận thức trực giác nói trên có một lỗ hổng logic lớn: khi định nghĩa khái niệm "xác suất", nó lại dùng đến cách nói "khả năng", dẫn đến vấn đề định nghĩa vòng quanh. Đồng thời, "đồng khả năng" cũng trở nên nhập nhằng khi không gian mẫu là vô hạn; từ đó phát sinh một loạt vấn đề, trong đó có [nghịch lý Bertrand](https://baike.baidu.com/item/%E8%B4%9D%E7%89%B9%E6%9C%97%E6%82%96%E8%AE%BA/9241081).

Sau quá trình tìm tòi liên tục, nhà toán học Liên Xô Kolmogorov lần đầu tiên đưa ra định nghĩa tiên đề hóa của xác suất trong cuốn *Cơ sở của lý thuyết xác suất* của ông vào năm 1933:

Hàm xác suất $P$ là một ánh xạ từ trường biến cố $\mathcal{F}$ vào khoảng đóng $[0, 1]$, và thỏa mãn:

-   **Tính chuẩn hóa**: xác suất của biến cố $\Omega$ bằng $1$, tức $P(\Omega)=1$.
-   **Tính cộng được đếm được**: nếu một dãy biến cố $A_1, A_2, \cdots$ đôi một rời nhau, thì $P\left( \bigcup_{i \geq 1} A_i \right) = \sum_{i \geq 1} P(A_i)$.

<span id="tính-chất-của-hàm-xác-suất"></span>
### Tính chất của hàm xác suất

Với mọi biến cố ngẫu nhiên $A, B \in \mathcal{F}$, các tính chất sau đúng:

-   **Tính đơn điệu**: nếu $A \subset B$, thì $P(A) \leq P(B)$.
-   **Nguyên lý bao hàm - loại trừ**: $P(A+B) = P(A) + P(B) - P(AB)$.
-   $P(A - B) = P(A) - P(AB)$, trong đó $A - B$ biểu thị hiệu tập hợp.

<span id="không-gian-xác-suất"></span>
## Không gian xác suất

Như đã nêu từ đầu, khi nghiên cứu một hiện tượng ngẫu nhiên cụ thể, các đối tượng thường được xét là không gian mẫu $\Omega$, trường biến cố $\mathcal{F}$ và hàm xác suất $P$. Bộ ba $(\Omega, \mathcal{F}, P)$ được gọi là một không gian xác suất.

Việc thảo luận về xác suất chỉ có ý nghĩa trong một không gian xác suất đã xác định. Về bản chất, nghịch lý Bertrand đã nhắc ở trên phát sinh do không gian mẫu $\Omega$ được định nghĩa một cách mơ hồ.

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

-   [Lý thuyết xác suất (nhánh toán học) - Baidu Baike](https://baike.baidu.com/item/%E6%A6%82%E7%8E%87%E8%AE%BA/829122)
-   [Probability - Wikipedia](https://en.wikipedia.org/wiki/Probability)
