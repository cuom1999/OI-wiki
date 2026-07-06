## Mở đầu

**Bài toán ghép cặp ổn định** là một bài toán kinh điển trong tối ưu tổ hợp và lý thuyết trò chơi hợp tác. So với các bài toán ghép cặp đồ thị truyền thống, ghép cặp ổn định đưa thêm các ràng buộc về sở thích cá nhân và tính ổn định, khiến thiết kế thuật toán phụ thuộc nhiều hơn vào thứ tự ưu tiên thay vì chỉ vào cấu trúc đồ thị. Trong mô hình của bài toán ghép cặp ổn định, mỗi cá thể có sở thích đối với các đối tượng ghép cặp tiềm năng, và bài toán yêu cầu thiết lập một quan hệ ghép cặp ổn định giữa họ. Trong một ghép cặp ổn định, không tồn tại bất kỳ nhóm cá thể nào có thể cùng rời bỏ kết quả ghép cặp hiện tại vì họ có lựa chọn tốt hơn. Ghép cặp ổn định và các bài toán liên quan được ứng dụng rộng rãi trong thị trường lao động, tuyển sinh, phân bổ tài nguyên y tế và nhiều bối cảnh khác.

Trong lập trình thi đấu, bài toán ghép cặp ổn định thường gặp nhất là ghép cặp một-một trong thị trường hai phía, tức bài toán hôn nhân ổn định. Bài viết này tập trung giới thiệu bài toán hôn nhân ổn định và thuật toán của nó.

## Bài toán hôn nhân ổn định

Bài toán hôn nhân ổn định là bài toán ghép cặp ổn định được nghiên cứu sớm nhất. Tương tự ghép cặp trong đồ thị hai phía, nó có thể được mô tả như bài toán ghép cặp trong thị trường hôn nhân: giả sử có một số nam và nữ, mỗi người đều có một thứ tự ưu tiên đối với người khác giới, mục tiêu là tìm một cách ghép cặp sao cho không có một cặp nam nữ nào muốn bỏ đối tượng hiện tại của mình để chọn nhau.

### Mô tả bài toán

Thị trường ghép cặp gồm một số nam $M$ và một số nữ $W$. Mỗi người đều có một thứ tự ưu tiên nghiêm ngặt đối với người khác giới:

-   Với mỗi nam $m\in M$, tồn tại một thứ tự toàn phần nghiêm ngặt $\preceq_m$ trên tập $W\cup\{m\}$;
-   Với mỗi nữ $w\in W$, tồn tại một thứ tự toàn phần nghiêm ngặt $\preceq_w$ trên tập $M\cup\{w\}$.

Ngoài việc so sánh giữa những người khác giới, mỗi người còn đưa chính mình vào thứ tự ưu tiên này. Điều đó biểu thị rằng người này chỉ chấp nhận ghép cặp với những người khác giới được xếp cao hơn chính mình; các đối tượng này được gọi là **chấp nhận được**. Thứ tự ưu tiên giữa các đối tượng không chấp nhận được không còn quan trọng; về nguyên tắc, chỉ cần đưa ra thứ tự ưu tiên giữa các đối tượng chấp nhận được. Vì vậy, các sở thích có tồn tại đối tượng không chấp nhận được cũng được gọi là sở thích với danh sách không đầy đủ.

???+ example "Ví dụ"
    Giả sử $m$ là một nam, $w_1,w_2,w_3$ là ba nữ, và có quan hệ ưu tiên $w_1\prec_m m \prec_m w_2\prec_m w_3$. Khi đó, nam $m$ thích độc thân hơn là ghép cặp với nữ $w_1$; thích ghép cặp với nữ $w_2$ hơn là độc thân; và thích ghép cặp với nữ $w_3$ hơn là ghép cặp với nữ $w_2$. Đối với nam $m$, nữ $w_1$ là không chấp nhận được, còn nữ $w_2,w_3$ là chấp nhận được.

Một **ghép cặp** $\mu:M\cup W\rightarrow M\cup W$ trên thị trường cần thỏa các tính chất sau:

-   Mỗi người chỉ có thể được ghép với người khác giới hoặc với chính mình, tức là với mọi $m\in M$ có $\mu(m)\in W\cup\{m\}$ và với mọi $w\in W$ có $\mu(w)\in M\cup\{w\}$.
-   Ghép cặp là tương hỗ, tức là với mọi $i\in M\cup W$ có $i = \mu(\mu(i))$.

Trong một ghép cặp $\mu$, có thể tồn tại hai loại yếu tố gây bất ổn:

-   Nếu tồn tại một cá thể $i\in M\cup W$ sao cho $\mu(i)\prec_i i$, tức là so với đối tượng ghép cặp hiện tại, cá thể $i$ thà độc thân hơn, thì $i$ được gọi là **cá thể chặn** của ghép cặp $\mu$.
-   Nếu tồn tại một cặp khác giới $m\in M$ và $w\in W$ sao cho $\mu(m)\prec_m w$ và $\mu(w)\prec_w m$, tức là so với đối tượng hiện tại của mỗi người, nam $m$ và nữ $w$ đều muốn ghép cặp với nhau hơn, thì $(m,w)$ được gọi là **cặp chặn** của ghép cặp $\mu$.

Nếu một ghép cặp $\mu$ không có cá thể chặn cũng không có cặp chặn, thì $\mu$ được gọi là **ổn định**. Trong một ghép cặp ổn định, không cá thể nào có thể phá vỡ trạng thái hiện tại: người độc thân không tìm được đối tượng nào sẵn lòng ghép cặp với mình; người đã ghép cặp không muốn trở lại độc thân, cũng không tìm được đối tượng nào sẵn lòng rời bỏ đối tượng hiện tại để ghép cặp với mình.

Bài toán ghép cặp ổn định đặt ra câu hỏi: với bất kỳ bộ thứ tự ưu tiên cho trước nào, liệu luôn tồn tại một ghép cặp ổn định hay không? Nếu có, làm thế nào để tìm được một ghép cặp như vậy?

### Thuật toán Gale–Shapley

Gale và Shapley đã đề xuất **thuật toán chấp nhận trì hoãn** vào năm 1962, có thể tìm một ghép cặp ổn định cho bất kỳ bộ thứ tự ưu tiên cho trước nào. Do đó, ghép cặp ổn định luôn tồn tại.

Thuật toán Gale–Shapley có hai phiên bản đối xứng, lần lượt là phiên bản nam cầu hôn và phiên bản nữ cầu hôn. Với phiên bản nam cầu hôn, quy trình thuật toán như sau:

1.  Khi thuật toán bắt đầu, mỗi nữ được xem như đang giữ lời cầu hôn của chính mình, và mỗi nam được đánh dấu là đang hoạt động.
2.  Một nam đang hoạt động sẽ cầu hôn người nữ mà người đó thích nhất trong số những người nữ chấp nhận được nhưng chưa từng được cầu hôn; nếu không tồn tại người nữ như vậy thì không thực hiện thao tác nào. Dù có cầu hôn hay không, sau đó đánh dấu tất cả nam là không hoạt động.
3.  Người nữ nhận được lời cầu hôn mới sẽ so sánh chúng với lời cầu hôn đang giữ trước đó, chỉ giữ lại lời cầu hôn mà mình thích nhất (có thể là chính mình), rồi từ chối mọi lời cầu hôn còn lại. Các nam bị từ chối được đánh dấu lại là đang hoạt động.
4.  Lặp lại hai bước trước cho đến khi không còn nam nào đang hoạt động. Khi đó, các nữ chấp nhận lời cầu hôn mà họ đang giữ. Kết quả ghép cặp thu được là một ghép cặp ổn định.

Vì mỗi nam cầu hôn mỗi nữ nhiều nhất một lần, thuật toán kết thúc sau không quá $|M||W|$ lời cầu hôn, với độ phức tạp $O(|M||W|)$.

Cài đặt tham khảo như sau:

??? example "Bài mẫu [SPOJ STABLEMP - Stable Marriage Problem](https://www.spoj.com/problems/STABLEMP/) cài đặt tham khảo"
    ```cpp
    --8<-- "docs/graph/code/graph-matching/stable-match/stable-match.cpp"
    ```

### Tính chất của ghép cặp ổn định

Ghép cặp ổn định có những tính chất lý thuyết tốt. Trước hết, thuật toán Gale–Shapley chứng minh một cách xây dựng rằng ghép cặp ổn định luôn tồn tại.

???+ note "Định lý 1 (Gale và Shapley, 1962)"
    Kết quả của thuật toán Gale–Shapley là một ghép cặp ổn định. Do đó, ghép cặp ổn định tồn tại.

??? note "Chứng minh"
    Nam không cầu hôn những nữ mà họ không chấp nhận, và nữ cũng lập tức từ chối lời cầu hôn từ những nam mà họ không chấp nhận. Vì vậy, những nam và nữ được ghép với nhau ở cuối thuật toán đều chấp nhận lẫn nhau, nên không thể tồn tại cá thể chặn. Để chứng minh đó là ghép cặp ổn định, chỉ cần chứng minh không tồn tại cặp chặn.
    
    Chứng minh phản chứng. Giả sử $(m,w)$ là một cặp chặn. Khi đó, trước khi nam $m$ cầu hôn $\mu(m)$, $m$ đã phải cầu hôn $w$. Nhưng vì nữ $w$ đã từ chối $m$, $w$ đã nhận được lời cầu hôn của một người $m'$ mà mình thích hơn. Nếu $m'\neq \mu(w)$, thì nữ $w$ chỉ có thể thích đối tượng ghép cặp cuối cùng $\mu(w)$ hơn $m'$. Do đó, so với $m$, nữ $w$ thích đối tượng ghép cặp cuối cùng $\mu(w)$ hơn. Điều này mâu thuẫn với việc $(m,w)$ là cặp chặn. Vì vậy, ghép cặp là ổn định.

???+ note "Hệ quả"
    Nếu $|M|=|W|$ và mọi người khác giới đều chấp nhận được, thì tồn tại một ghép cặp hoàn hảo ổn định.

Trong thuật toán Gale–Shapley, có thể để nam cầu hôn hoặc nữ cầu hôn. Hai phiên bản này của thuật toán Gale–Shapley thường không cho cùng một ghép cặp ổn định. Thực tế, ghép cặp ổn định do thuật toán Gale–Shapley nam cầu hôn thu được là ghép cặp có lợi nhất cho nam trong tất cả các ghép cặp ổn định; chiều ngược lại cũng đúng.

???+ note "Định lý 2 (Gale và Shapley, 1962)"
    Gọi $\mu_M$ và $\mu_W$ lần lượt là các ghép cặp ổn định thu được từ thuật toán Gale–Shapley nam cầu hôn và nữ cầu hôn. Với mọi ghép cặp ổn định $\mu$, có $\mu(m)\preceq_m\mu_M(m)$ với mọi $m\in M$, và $\mu(w)\preceq_w\mu_W(w)$ với mọi $w\in W$.

??? note "Chứng minh"
    Theo tính đối xứng, chỉ cần chứng minh $\mu(m)\preceq_m\mu_M(m)$ với mọi $m\in M$. Xét thuật toán Gale–Shapley nam cầu hôn, và ký hiệu $k(m,w)$ là vòng lặp của thuật toán khi nữ $w$ từ chối lời cầu hôn của nam $m$. Vòng lặp này được định nghĩa tốt với mọi $(m,w)$ thỏa $\mu_M(m)\prec_m w$.
    
    Giả sử $\mu_M$ không phải là ghép cặp có lợi nhất cho tất cả nam, tức là tồn tại một ghép cặp ổn định $\mu$ và một nam $m\in M$ sao cho $\mu_M(m)\prec_m\mu(m)$. Vì ghép cặp $\mu_M$ là ổn định, có $m\preceq_m\mu_M(m)\prec_m\mu(m)$, nên $\mu(m)$ là một nữ, và $k(m,\mu(m))$ được định nghĩa tốt. Do đó, không mất tính tổng quát, chọn $m$ là nam có $k(m,\mu(m))$ nhỏ nhất trong số tất cả các nam như vậy. Giả sử trong quá trình thuật toán, khi nữ $w=\mu(m)$ từ chối nam $m$, $w$ giữ lời cầu hôn của nam $m'$, tức là $m=\mu(w)\prec_w m'$. Vì $\mu$ là ghép cặp ổn định, $(w,m')$ không thể là cặp chặn; lại có $\mu(m')\neq w$, nên $w\prec_{m'}\mu(m')$. Vì trong thuật toán Gale–Shapley, nữ $w$ không nhất thiết giữ lời cầu hôn của $m'$ đến cuối, nên $\mu_M(m')\preceq_{m'}w\prec_{m'}\mu(m')$. Khi đó, $k(m',\mu(m'))$ được định nghĩa tốt. Hơn nữa, do $w\prec_{m'}\mu(m')$, nữ $\mu(m')$ phải từ chối lời cầu hôn của $m'$ trước khi $w$ giữ lời cầu hôn của $m'$, tức là $k(m',\mu(m')) < k(m,\mu(m))$. Điều này mâu thuẫn với cách chọn $m$. Vì vậy, theo phản chứng, $\mu_M$ là ghép cặp ổn định có lợi nhất cho tất cả nam.

Một thị trường ghép cặp có thể có số lượng ghép cặp ổn định cấp số mũ. Gọi $\mathcal S$ là tập tất cả các ghép cặp ổn định. Trên tập này có thể định nghĩa hai thứ tự bộ phận:

-   $\mu_1\preceq_M\mu_2$ khi và chỉ khi $\mu_1(m)\preceq_m\mu_2(m)$ đúng với mọi $m\in M$;
-   $\mu_1\preceq_W\mu_2$ khi và chỉ khi $\mu_1(w)\preceq_w\mu_2(w)$ đúng với mọi $w\in W$.

Hai thứ tự bộ phận này lần lượt biểu thị rằng kết quả ghép cặp tốt hơn cho tất cả nam và cho tất cả nữ. Hai ghép cặp ổn định không nhất thiết so sánh được với nhau. Tuy nhiên, bất kỳ hai ghép cặp ổn định nào cũng cảm sinh một phép phân rã như hình dưới, sao cho trong ba phần thu được từ phân rã, lần lượt có $\mu_1\preceq_M\mu_2$, $\mu_1=\mu_2$ và $\mu_2\preceq_M\mu_1$. Dù không được vẽ trực tiếp, phần $\mu_1=\mu_2$ vẫn bao gồm cả trường hợp ghép với chính mình (tức là chưa được ghép cặp).

![](./images/stable-match-decompose.svg)

Phép phân rã này dựa trên bổ đề sau:

???+ note "Bổ đề (Knuth, 1976)"
    Gọi $\mu_1$ và $\mu_2$ là hai ghép cặp ổn định. Gọi $M(\mu_i)=\{m\in M : \mu_j(m)\prec_m\mu_i(m)\}$ và $W(\mu_i)=\{w\in W:\mu_j(w)\prec_w\mu_i(w)\}$ lần lượt là tập các nam và nữ thích kết quả ghép cặp trong $\mu_i$ hơn, trong đó $i,j=1,2$ và $i\neq j$. Khi đó, cả $\mu_1$ và $\mu_2$ đều là song ánh giữa $M(\mu_1)$ và $W(\mu_2)$, đồng thời cũng là song ánh giữa $M(\mu_2)$ và $W(\mu_1)$.

??? note "Chứng minh"
    Xét $m\in M(\mu_1)$. Vì $m\preceq_m \mu_2(m)\prec_m\mu_1(m)$, nên $\mu_1(m)\in W$. Đặt $w=\mu_1(m)$. Do $\mu_2(w)\neq m$, và $\mu_2(w)\prec_w m$ sẽ kéo theo $(m,w)$ là cặp chặn của $\mu_2$, nên phải có $\mu_1(w)=m\prec_w\mu_2(w)$. Nói cách khác, $w\in W(\mu_2)$. Suy ra $\mu_1(M(\mu_1))\subseteq W(\mu_2)$. Theo tính đối xứng, cũng có thể thiết lập $\mu_2(W(\mu_2))\subseteq M(\mu_1)$. Vì $\mu_1$ và $\mu_2$ đều là đơn ánh, nên $|M(\mu_1)|=|W(\mu_2)|$ và hai ánh xạ này đều là toàn ánh. Do đó, $\mu_1$ và $\mu_2$ đều là song ánh giữa $M(\mu_1)$ và $W(\mu_2)$. Tương tự, chúng cũng đều là song ánh giữa $M(\mu_2)$ và $W(\mu_1)$.

Bổ đề này cho thấy hai tập thứ tự bộ phận $(\mathcal S,\preceq_M)$ và $(\mathcal S,\preceq_W)$ là [đối ngẫu](../../math/order-theory.md#đối-ngẫu). Hơn nữa, dưới mỗi thứ tự bộ phận, tập $\mathcal S$ đều tạo thành một [dàn](../../math/order-theory.md#tập-định-hướng-và-dàn). Vì $\mathcal S$ là hữu hạn, hai dàn này đều có phần tử lớn nhất và phần tử nhỏ nhất. Hai phần tử cực trị này chính là các ghép cặp ổn định thu được từ hai phiên bản của thuật toán Gale–Shapley đã nêu.

???+ note "Định lý 3 (Conway và Knuth, 1976)"
    Các tập thứ tự bộ phận $(\mathcal S,\preceq_M)$ và $(\mathcal S,\preceq_W)$ là hai dàn đối ngẫu của nhau. Hơn nữa, $\mu_M$ và $\mu_W$ lần lượt là phần tử lớn nhất và nhỏ nhất của $(\mathcal S,\preceq_M)$, đồng thời lần lượt là phần tử nhỏ nhất và lớn nhất của $(\mathcal S,\preceq_W)$.

??? note "Chứng minh"
    Theo bổ đề, hai tập thứ tự bộ phận là đối ngẫu. Nếu $\mu_1\preceq_M\mu_2$, suy ra $M(\mu_1)=\varnothing$; theo bổ đề, $W(\mu_2)=\varnothing$, tức là $\mu_2\preceq_W\mu_1$. Chiều ngược lại cũng tương tự. Vì vậy, hai thứ tự này đối ngẫu với nhau. Kết hợp với định lý 2 ở trên, thu được $\mu_M$ và $\mu_W$ là các phần tử cực trị của hai tập thứ tự bộ phận. Điều còn cần chứng minh trong mệnh đề là hai tập thứ tự bộ phận đều là dàn. Theo tính đối xứng, chỉ cần chứng minh $(\mathcal S,\preceq_M)$ là dàn. Lại theo tính đối xứng của phép gặp và phép hợp, chỉ cần chứng minh hợp của hai ghép cặp ổn định vẫn là ghép cặp ổn định. Nói một cách hình thức, với mọi $\mu_1,\mu_2\in\mathcal S$, cần chứng minh rằng ghép cặp $\mu=\mu_1\lor_M\mu_2$ thỏa $\mu(m)=\mu_1(m)\lor_m\mu_2(m)$ với mọi $m\in M$ là ghép cặp ổn định, trong đó $\lor_m$ là phép hợp dưới thứ tự toàn phần $\preceq_m$ (tức là đối tượng mà $m$ thích hơn trong hai đối tượng).
    
    Tiếp tục dùng ký hiệu trong bổ đề. Với $i\in M(\mu_1)\cup W(\mu_2)$, có $\mu(i)=\mu_1(i)$; ngược lại, có $\mu(i)=\mu_2(i)$. Vì $\mu_1$ và $\mu_2$ đều ổn định và không có cá thể chặn, $\mu$ cũng không có cá thể chặn. Giả sử $(m,w)$ là một cặp chặn của $\mu$. Nếu $m\in M(\mu_1)$, thì $\mu_2(m)\prec_m\mu_1(m)=\mu(m)\prec_m w$. Khi đó, nếu $w\in W(\mu_2)$, có $\mu_1(w)=\mu(w)\prec_w m$, nên $(m,w)$ là cặp chặn của $\mu_1$, mâu thuẫn; nếu không, $w\in W\setminus W(\mu_2)$, có $\mu_2(w)=\mu(w)\prec_w m$, nên $(m,w)$ là cặp chặn của $\mu_2$, cũng mâu thuẫn. Tương tự, trường hợp $m\in M\setminus M(\mu_1)$ cũng chỉ dẫn đến mâu thuẫn. Theo phản chứng, không tồn tại cặp chặn như vậy. Vì vậy, $\mu_1\lor_M\mu_2$ là ghép cặp ổn định. Mệnh đề được chứng minh.

Cuối cùng, trong tất cả các ghép cặp ổn định, tập nam và nữ chưa được ghép cặp là cố định.

???+ note "Định lý 4 (McVitie và Wilson, 1970)"
    Gọi $\mu_1$ và $\mu_2$ là hai ghép cặp ổn định. Khi đó, tập điểm bất động của $\mu_1$ và $\mu_2$ là như nhau.

??? note "Chứng minh"
    Giả sử tồn tại $m\in M$ sao cho $\mu_1(m)=m$ và $\mu_2(m)\neq m$ với một cặp $\mu_1,\mu_2\in\mathcal S$ nào đó. Khi đó, $m\in M(\mu_2)$. Theo bổ đề, $m=\mu_1(m)\in W(\mu_1)$, mâu thuẫn với $m\in M$. Vì vậy, không tồn tại nam $m\in M$ như vậy. Tương tự, cũng không tồn tại nữ $w\in W$ như vậy. Do đó, tập điểm bất động của bất kỳ hai ghép cặp ổn định nào cũng giống nhau.

Ngoài các tính chất được thảo luận trong phần này, ghép cặp ổn định còn có một số tính chất chiến lược tốt. Các tài liệu ở cuối bài trình bày thêm về các nội dung này.

## Các vấn đề liên quan

Ghép cặp ổn định và các bài toán tương tự còn xuất hiện trong nhiều bối cảnh khác.

### Bài toán tuyển sinh đại học

Nếu nới lỏng ràng buộc ghép cặp một-một trong bài toán hôn nhân ổn định và cho phép ghép cặp nhiều-một, thu được **bài toán tuyển sinh đại học**. Khi đó, một trường đại học có thể tuyển nhiều sinh viên, miễn là không vượt quá chỉ tiêu tuyển sinh; nhưng mỗi sinh viên vẫn chỉ được phép vào học nhiều nhất một trường. Các tình huống tương tự cũng xuất hiện trong tuyển dụng công ty, bệnh viện tuyển bác sĩ nội trú và các bối cảnh khác.

Với loại bài toán này, thuật toán Gale–Shapley vẫn áp dụng được. Chẳng hạn, trong thuật toán Gale–Shapley do sinh viên nộp đơn, trường đại học có thể duy trì một danh sách chờ có độ dài không vượt quá chỉ tiêu; mỗi khi số lượng đơn vượt quá chỉ tiêu, chỉ cần từ chối đơn của sinh viên kém nhất. Những thảo luận ở trên về tính chất của ghép cặp ổn định vẫn áp dụng cho bối cảnh này. Đặc biệt, phiên bản tương ứng của định lý 4 là: trong tất cả các ghép cặp ổn định, số sinh viên mà mỗi trường tuyển được là cố định. Điều này còn được gọi là **định lý bệnh viện nông thôn**. Tên gọi này xuất phát từ hệ quả rằng dù thay đổi cơ chế ghép cặp thế nào, miễn là kết quả thu được ổn định, những bệnh viện nông thôn vốn không tuyển đủ bác sĩ vẫn không tuyển đủ người.

### Bài toán ghép phòng ổn định

Nếu nới lỏng điều kiện trong bài toán hôn nhân ổn định rằng chỉ có thể ghép cặp với người khác giới, thu được **bài toán ghép phòng ổn định**. Khi đó, ban đầu chỉ có một số sinh viên và cần ghép họ thành từng cặp ở chung phòng. Với loại bài toán này, ghép cặp ổn định không nhất thiết tồn tại. Irving đã đề xuất vào năm 1985 một thuật toán giải bài toán này trong thời gian $O(n^2)$.

### Bài toán phân bổ nhà ở

Trong bài toán hôn nhân ổn định, hai nhóm cá thể có sở thích đối với nhau, nên đó là bài toán ghép cặp hai phía. Ngoài ra, cũng có thể xét bài toán ghép cặp một phía. Một bối cảnh thường gặp là **bài toán phân bổ nhà ở**. Có $n$ cư dân, mỗi người sở hữu một căn nhà. Mỗi người có một sở thích nghiêm ngặt đối với tất cả các căn nhà. Yêu cầu là phân bổ lại các căn nhà này cho các cư dân sao cho mỗi cư dân không nhận căn nhà tệ hơn căn ban đầu của mình, và không tồn tại bất kỳ nhóm cư dân nào có thể tự trao đổi nhà với nhau để thu được kết quả hài lòng hơn. Có thể giải bài toán này bằng thuật toán Top Trading Cycle trong thời gian $O(n^2)$. Các bài toán thuộc loại này cũng xuất hiện trong bối cảnh ghép thận và những tình huống tương tự.

## Bài tập

-   [UOJ 41. Tsinghua Training Camp 2014 - Matrix Transform](https://uoj.ac/problem/41)
-   [Codeforces 1147 F. Zigzag Game](https://codeforces.com/problemset/problem/1147/F)

## Tài liệu tham khảo và chú thích

-   [Thuật toán là gì: cách tìm một ghép cặp hôn nhân ổn định - Matrix67](https://matrix67.com/blog/archives/2976)
-   [Thuật toán Gale–Shapley: tìm ghép cặp ổn định trong đồ thị hai phía](https://reimuyk.github.io/2021-03-24-Gale-Shapley-Algorithm/)
-   [Stable matching problem - Wikipedia](https://en.wikipedia.org/wiki/Stable_matching_problem)
-   [Lattice of stable matchings - Wikipedia](https://en.wikipedia.org/wiki/Lattice_of_stable_matchings)
-   [Stable roommates problem - Wikipedia](https://en.wikipedia.org/wiki/Stable_roommates_problem)
-   [Top trading cycle - Wikipedia](https://en.wikipedia.org/wiki/Top_trading_cycle)
-   [Stable matching: Theory, evidence, and practical design - the 2012 Nobel Prize in Economics](https://www.nobelprize.org/uploads/2018/06/popular-economicsciences2012.pdf)
-   [Notes on Matching and Market Design by Xiang Sun](https://www.xiangsun.org/wp-content/uploads/2013/02/notes-2015-matching.pdf)
-   Gale, David, and Lloyd S. Shapley. "College admissions and the stability of marriage." The American mathematical monthly 69, no. 1 (1962): 9-15.
-   Irving, Robert W. "An efficient algorithm for the stable roommates problem." Journal of Algorithms 6, no. 4 (1985): 577-595.
-   Knuth, Donald Ervin. "Marriages stables." Technical report (1976).
-   McVitie, David G., and Leslie B. Wilson. "Stable marriage assignment for unequal sets." BIT Numerical Mathematics 10, no. 3 (1970): 295-309.
-   Roth, Alvin E., and Marilda Sotomayor. "Two-sided matching." Handbook of game theory with economic applications 1 (1992): 485-541.
-   Roth, Alvin E. "Deferred acceptance algorithms: History, theory, practice, and open questions." international Journal of game Theory 36, no. 3-4 (2008): 537-569.
