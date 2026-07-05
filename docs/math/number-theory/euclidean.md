author: sshwy, FFjet, qz-cqy

<span id="mở-đầu"></span>
## Mở đầu

Thuật toán Euclid tương tự là nội dung do Hong Huadun đề xuất trong buổi trao đổi trại viên tại Winter Camp 2016. Nó thường được dùng để giải các bài toán tính tổng của những dãy số (chỉ số là $i$) có cấu trúc dạng

$$
\left\lfloor\dfrac{ai+b}{c}\right\rfloor
$$

Ý tưởng chính của nó là tận dụng cấu trúc đệ quy của chính phân số để chuyển bài toán thành bài toán quy mô nhỏ hơn rồi giải đệ quy. Vì cấu trúc đệ quy của phân số có [liên hệ](./continued-fraction.md#cách-tìm-biểu-diễn-liên-phân-số) trực tiếp với [thuật toán Euclid](./gcd.md#thuật-toán-euclid), phương pháp tính tổng này cũng được gọi là thuật toán Euclid tương tự.

Do các phương pháp như [liên phân số](./continued-fraction.md) và [cây Stern-Brocot](./stern-brocot.md) cũng mô tả cấu trúc đệ quy của phân số, những bài toán có thể giải bằng thuật toán Euclid tương tự thường cũng có thể giải bằng các phương pháp đó. So với chúng, thuật toán Euclid tương tự thường dễ hiểu hơn và cài đặt cũng ngắn gọn hơn.

<span id="thuật-toán-euclid-tương-tự"></span>
## Thuật toán Euclid tương tự

Ví dụ đơn giản nhất là bài toán tính tổng:

$$
f(a,b,c,n)=\sum_{i=0}^n\left\lfloor \frac{ai+b}{c} \right\rfloor,
$$

trong đó $a,b,c,n$ đều là số nguyên dương.

<span id="cách-giải-đại-số"></span>
### Cách giải đại số

Trước hết, lấy phần dư của $a,b$ theo $c$ để đơn giản hóa bài toán, đưa nó về trường hợp $0\le a,b<c$:

$$
\begin{aligned}
f(a,b,c,n)&=\sum_{i=0}^n\left\lfloor \frac{ai+b}{c} \right\rfloor\\
&=\sum_{i=0}^n\left\lfloor
\frac{\left(\left\lfloor\frac{a}{c}\right\rfloor c+(a\bmod c)\right)i+\left(\left\lfloor\frac{b}{c}\right\rfloor c+(b\bmod c)\right)}{c}\right\rfloor\\
&=\sum_{i=0}^n\left(\left\lfloor\frac{a}{c}\right\rfloor i+\left\lfloor\frac{b}{c}\right\rfloor+\left\lfloor\frac{\left(a\bmod c\right)i+\left(b\bmod c\right)}{c}
\right\rfloor\right)\\
&=\frac{n(n+1)}{2}\left\lfloor\frac{a}{c}\right\rfloor
+(n+1)\left\lfloor\frac{b}{c}\right\rfloor+f(a\bmod c,b\bmod c,c,n).
\end{aligned}
$$

Bây giờ xét bài toán sau khi đã biến đổi. Đặt

$$
m = \left\lfloor \frac{an+b}{c} \right\rfloor.
$$

Khi đó, bài toán ban đầu có thể viết thành một tổng hai lớp:

$$
\sum_{i=0}^n\left\lfloor \frac{ai+b}{c} \right\rfloor
=\sum_{i=0}^n\sum_{j=0}^{m-1}\left[j<\left\lfloor \frac{ai+b}{c} \right\rfloor\right].
$$

Đổi thứ tự lấy tổng; việc này cần tính miền giá trị của $i$ thỏa mãn điều kiện với mỗi $j$. Ta biến đổi điều kiện:

$$
\begin{aligned}
&j<\left\lfloor \frac{ai+b}{c} \right\rfloor = \left\lceil \frac{ai+b+1}{c} \right\rceil-1\\
&\iff j + 1 < \left\lceil \frac{ai+b+1}{c} \right\rceil
\iff j+1< \frac{ai+b+1}{c} \\
&\iff \dfrac{cj+c-b-1}{a} < i
\iff \left\lfloor\dfrac{cj+c-b-1}{a}\right\rfloor < i.
\end{aligned}
$$

Trong quá trình biến đổi ta nhiều lần dùng tính chất của [hàm lấy phần nguyên](./basic.md#hàm-lấy-phần-nguyên). Thay điều kiện đã biến đổi vào, biểu thức ban đầu trở thành:

$$
\begin{aligned}
f(a,b,c,n)&=\sum_{j=0}^{m-1}
\sum_{i=0}^n\left[i>\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor \right]\\
&=\sum_{j=0}^{m-1}\left(n-\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor\right)\\
&=nm-f\left(c,c-b-1,a,m-1\right).
\end{aligned}
$$

Đặt $(a',b',c',n')=(c,c-b-1,a,m-1)$, ta lại quay về trường hợp $a'>c'$ đã thảo luận ở trên.

Kết hợp hai bước biến đổi này, có thể thấy trong quá trình đó $(a,c)$ liên tục được lấy modulo rồi hoán đổi vị trí cho đến khi $a=0$. Điều này tương tự phép chia Euclid trên $(a,c)$, và cũng là nguồn gốc tên gọi thuật toán Euclid tương tự. Độ phức tạp thời gian là $O(\log\min\{a,c\})$.

Trong quá trình tính, có thể xuất hiện trường hợp $m=0$; khi đó lời gọi đệ quy bên trong sẽ có $n=-1$. Điều này không ảnh hưởng kết quả cuối cùng. Tuy nhiên, nếu yêu cầu thuật toán dừng ngay khi $m=0$, độ phức tạp thời gian có thể cải thiện thành $O(\log\min\{a,c,n\})$.

??? note "Giải thích về độ phức tạp"
    Từ sự tương đồng giữa thuật toán này và thuật toán Euclid, rất dễ chứng minh độ phức tạp thời gian là $O(\log\min\{a,c\})$. Vì vậy, chỉ cần chứng minh rằng nếu dừng thuật toán khi $m=0$ thì độ phức tạp cũng là $O(\log n)$.
    
    Đặt $m=\lfloor(an+b)/c\rfloor$, đồng thời ký hiệu $S=mn$, $k=m/n$; trong trực giác hình học (xem phần tiếp theo), chúng lần lượt tương ứng với diện tích của lưới điểm và hệ số góc của đường thẳng. Với $n$ đủ lớn, xấp xỉ có $k\doteq a/c$.
    
    Xét sự thay đổi của $S$ và $k$ trong quá trình thuật toán. Ở bước lấy modulo đầu tiên, $n$ không đổi, $k$ xấp xỉ chuyển từ $a/c$ thành $(a\bmod c)/c$, tương đương hệ số góc chuyển từ $k$ thành $k-\lfloor k\rfloor$, còn $S$ cũng xấp xỉ trở thành $(k-\lfloor k\rfloor)$ lần giá trị cũ. Ở bước thứ hai, khi hoán đổi trục hoành và trục tung, $S$ xấp xỉ không đổi, còn $k$ trở thành nghịch đảo của nó. Vì vậy, nếu sau hai bước thao tác, cặp $(k,S)$ biến thành $(k',S')$, thì $k'=(k-\lfloor k\rfloor)^{-1}$ và $S'=(k-\lfloor k\rfloor)S$.
    
    Vì $1\le\lfloor k'\rfloor\le k'<\lfloor k'\rfloor+1$, nên sau hai vòng đệ quy, hệ số giảm nhỏ nhất của tích là
    
    $$
    (k'-\lfloor k'\rfloor)(k-\lfloor k\rfloor) = 1-\dfrac{\lfloor k'\rfloor}{k'} < 1-\dfrac{\lfloor k'\rfloor}{\lfloor k'\rfloor+1} = \dfrac{1}{\lfloor k'\rfloor+1}\le \dfrac{1}{2}.
    $$
    
    Do đó sau nhiều nhất $O(\log S)$ vòng, thuật toán chắc chắn dừng. Từ vòng thứ hai trở đi, $S$ ở đầu mỗi vòng luôn không vượt quá $S$ sau khi kết thúc bước lấy modulo của vòng trước; giá trị sau này xấp xỉ $kn^2$ và $k<1$, nên $O(\log S)\subseteq O(\log n)$. Điều này cho ta kết luận trên.

Cài đặt tham khảo cho bài mẫu như sau:

??? example "Cài đặt bài mẫu ([Library Checker - Sum of Floor of Linear](https://judge.yosupo.jp/problem/sum_of_floor_of_linear))"
    ```cpp
    --8<-- "docs/math/code/euclidean/euclidean-0.cpp:full-text"
    ```

<span id="trực-giác-hình-học"></span>
### Trực giác hình học

Thuật toán này cũng có thể được hiểu từ góc nhìn hình học. Những bài toán mà thuật toán Euclid tương tự xử lý chủ yếu là bài toán đếm điểm nguyên nằm dưới một đường thẳng.

Như phần ngoài cùng bên trái trong hình dưới, tổng này tương đương với việc đếm số điểm lưới nằm dưới đường thẳng

$$
y = \dfrac{ax+b}{c}
$$

nằm phía trên trục $x$ (không tính trục $x$), và có hoành độ trong đoạn $[0,n]$.

![](./images/euclidean-1.svg)

Trước hết, loại bỏ phần nguyên trong hệ số góc và tung độ gốc. Bước này tương đương với việc tính riêng số lượng điểm màu xanh ở phần giữa của hình trên. Khi hệ số góc và tung độ gốc đều là số nguyên, các điểm màu xanh chắc chắn tạo thành một mảng hình thang, tức số điểm lưới trong các cột khác nhau tạo thành cấp số cộng, nên số lượng các điểm này rất dễ tính. Sau khi loại bỏ chúng, số điểm lưới còn lại trùng với số điểm đỏ ở phần ngoài cùng bên phải của hình trên. Bài toán được chuyển thành trường hợp hệ số góc và tung độ gốc đều nhỏ hơn một. Vì chiều cao của hình thang là $n+1$ và độ dài hai đáy lần lượt là $\lfloor b/c\rfloor$ và $(\lfloor a/c\rfloor n+\lfloor b/c\rfloor)$, dùng công thức diện tích hình thang, bước này có thể quy về công thức

$$
f(a,b,c,n) = f(a\bmod c,b\bmod c,c,n) + \dfrac{1}{2}(n+1)\left(\left\lfloor\dfrac{b}{c}\right\rfloor+\left(\left\lfloor\dfrac{a}{c}\right\rfloor n+\left\lfloor\dfrac{b}{c}\right\rfloor\right)\right).
$$

Sau đó, lật trục hoành và trục tung. Như phần ngoài cùng bên trái trong hình dưới, các điểm đỏ và điểm xanh trong hình tạo thành một lưới điểm hình chữ nhật có chiều ngang $n$ và chiều dọc $m=\lfloor(an+b)/c\rfloor$. Để tính số điểm đỏ, chỉ cần tính số điểm xanh rồi lấy số điểm của lưới chữ nhật trừ đi số điểm xanh. Sau khi lật, lưới điểm xanh ở nửa trái của hình trên trở thành lưới điểm đỏ nằm dưới một đường thẳng nào đó. Hơn nữa, sau khi lật, hệ số góc lớn hơn một, tức lại quay về trường hợp đã xử lý ở trên.

![](./images/euclidean-2.svg)

Điểm mấu chốt là tính phương trình đường thẳng nằm phía trên lưới điểm đỏ mới. Lật trục hoành và trục tung của phần ngoài cùng bên trái trong hình trên, ta được phần giữa. Đường thẳng nằm phía trên lưới điểm đỏ sau khi lật (đường liền ở phần giữa) không tương ứng với đường thẳng trước khi lật (đường liền ở phần ngoài cùng bên trái), mà tương ứng với kết quả tịnh tiến đường thẳng trước khi lật một chút về phía trên bên trái (đường nét đứt ở phần ngoài cùng bên trái). Lý do là nếu lật trực tiếp đường thẳng (đường liền ở phần ngoài cùng bên trái), ta sẽ nhận được đường nét đứt ở phần giữa, nhưng theo định nghĩa, các điểm lưới dưới nó bao gồm cả những điểm nằm đúng trên đường thẳng, dẫn tới đếm lặp các điểm trên đường thẳng. Để tránh điều này, cần tịnh tiến đường thẳng thu được sau khi lật $y=(ax+b)/c$, tức $y=(cx-b)/a$, xuống dưới một chút, nhận được đường thẳng $y=(cx-b-1)/a$; khi đó lưới điểm dưới nó mới đúng là lưới điểm xanh trước khi lật.

Còn một chi tiết khác cần xử lý. Tung độ gốc của đường thẳng ở phần giữa của hình trên là số âm, nghĩa là ta vẫn chưa quay lại dạng ban đầu. Để đưa tung độ gốc về không âm, chỉ cần tịnh tiến đường thẳng (đường liền ở phần giữa) sang trái một đơn vị. Thao tác này không bỏ sót điểm lưới nào, vì trong lưới điểm xanh trước khi lật không có điểm nào có tung độ bằng không, nên sau khi lật cũng không có điểm nào có hoành độ bằng không. Cuối cùng, phương trình đường thẳng trở thành $y=(cx+c-b-1)/a$; đồng thời, cận trên của hoành độ trong lưới điểm cũng chuyển từ $m$ thành $m-1$. Bước này có thể quy về công thức

$$
f(a,b,c,n) = mn - f(c,c-b-1,a,m-1).
$$

Thuật toán đệ quy này hoạt động được chủ yếu vì hai lý do:

-   Thứ nhất, hệ số góc của đường thẳng liên tục được lấy phần thập phân rồi lấy nghịch đảo, điều này tương đương với việc tính [khai triển liên phân số](./continued-fraction.md#cách-tìm-biểu-diễn-liên-phân-số) của hệ số góc $k=a/c$. Vì độ dài khai triển liên phân số của một phân số hữu tỉ là $O(\log\min\{a,c\})$, quá trình này chắc chắn kết thúc sau $O(\log\min\{a,c\})$ bước;
-   Thứ hai, mỗi lần lật trục tọa độ thì hệ số góc của đường thẳng đều nhỏ hơn một, nên trực giác cho thấy phải có $m<n$, tức sau một vòng lặp như vậy, phạm vi hoành độ luôn thu nhỏ. Phần phân tích độ phức tạp ở trên đã chứng minh chặt chẽ rằng sau mỗi hai vòng lặp, $n$ nhiều nhất giảm còn một nửa, nên quá trình này chắc chắn kết thúc sau $O(\log n)$ bước.

Đây cũng là lý do độ phức tạp của thuật toán Euclid tương tự khi hệ số góc là số hữu tỉ là $O(\log\min\{a,c,n\})$.

Dùng trực giác hình học tương tự, có thể mở rộng thuật toán Euclid tương tự cho trường hợp hệ số góc là số vô tỉ; phân tích cụ thể xem trong bài ví dụ phía sau.

<span id="ví-dụ"></span>
### Ví dụ

???+ example "[Bài mẫu - Thuật toán Euclid tương tự](https://www.luogu.com.cn/problem/P5170)"
    Có nhiều truy vấn. Cho các số nguyên dương $a,b,c,n$, hãy tính
    
    $$
    \begin{aligned}
    f(a,b,c,n) &= \sum_{i=0}^n\left\lfloor \frac{ai+b}{c} \right\rfloor,\\
    g(a,b,c,n) &= \sum_{i=0}^ni\left\lfloor \frac{ai+b}{c} \right\rfloor,\\
    h(a,b,c,n) &= \sum_{i=0}^n\left\lfloor \frac{ai+b}{c} \right\rfloor^2.
    \end{aligned}
    $$

??? note "Lời giải 1"
    Tương tự cách suy ra công thức cho $f$, ta có thể nhận được các biểu thức đệ quy cho $g,h$.
    
    Trước hết, dùng phép lấy modulo để chuyển bài toán về trường hợp $0\le a,b<c$:
    
    $$
    \begin{aligned}
    g(a,b,c,n)
    &=g(a\bmod c,b\bmod c,c,n)+\left\lfloor\frac{a}{c}\right\rfloor\frac{n(n+1)(2n+1)}{6}+\left\lfloor\frac{b}{c}\right\rfloor\frac{n(n+1)}{2}, \\
    h(a,b,c,n)&=h(a\bmod c,b\bmod c,c,n)\\
    &\quad+2\left\lfloor\frac{b}{c}\right\rfloor f(a\bmod c,b\bmod c,c,n)
    +2\left\lfloor\frac{a}{c}\right\rfloor g(a\bmod c,b\bmod c,c,n)\\
    &\quad+\left\lfloor\frac{a}{c}\right\rfloor^2\frac{n(n+1)(2n+1)}{6}+\left\lfloor\frac{b}{c}\right\rfloor^2(n+1)
    +\left\lfloor\frac{a}{c}\right\rfloor\left\lfloor\frac{b}{c}\right\rfloor n(n+1).
    \end{aligned}
    $$
    
    Sau đó, dùng đổi thứ tự lấy tổng để tiếp tục biến đổi. Tương tự, đặt
    
    $$
    m = \left\lfloor \frac{an+b}{c} \right\rfloor.
    $$
    
    Khi đó, với tổng $g$, ta có
    
    $$
    \begin{aligned}
    g(a,b,c,n)&=\sum_{i=0}^ni\left\lfloor \frac{ai+b}{c} \right\rfloor\\
    &=\sum_{i=0}^n \sum_{j=0}^{m-1}i
    \left[j<\left\lfloor\frac{ai+b}{c}\right\rfloor\right] \\
    &=\sum_{j=0}^{m-1}\sum_{i=0}^n i\left[i>\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor \right]\\
    &=\sum_{j=0}^{m-1}\dfrac{1}{2}\left(\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor+n+1\right)\left(n-\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor\right)\\
    &=\dfrac{1}{2}mn(n+1) - \dfrac{1}{2}\sum_{j=0}^{m-1}\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor - \dfrac{1}{2}\sum_{j=0}^{m-1}\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor^2\\
    &=\dfrac{1}{2}mn(n+1) - \dfrac{1}{2}f(c,c-b-1,a,m-1) - \dfrac{1}{2}h(c,c-b-1,a,m-1).
    \end{aligned}
    $$
    
    Với tổng $h$, ta có
    
    $$
    \begin{aligned}
    h(a,b,c,n)&=\sum_{i=0}^n\left\lfloor \frac{ai+b}{c} \right\rfloor^2\\
    &=\sum_{i=0}^n\sum_{j=0}^{m-1}(2j+1)\left[j<\left\lfloor\frac{ai+b}{c}\right\rfloor\right]\\
    &=\sum_{j=0}^{m-1}\sum_{i=0}^n(2j+1)\left[i>\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor \right]\\
    &=\sum_{j=0}^{m-1}(2j+1)\left(n-\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor\right)\\
    &=nm^2 - \sum_{j=0}^{m-1}\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor - 2\sum_{j=0}^{m-1}j\left\lfloor\frac{cj+c-b-1}{a}\right\rfloor\\
    &=nm^2 - f(c,c-b-1,a,m-1) - 2g(c,c-b-1,a,m-1).
    \end{aligned}
    $$
    
    Từ góc nhìn trực giác hình học, những tổng phi tuyến này tương đương với việc gán cho mỗi điểm $(i,j)$ trong miền một trọng số tương ứng $w(i,j)$. Ngoài các trọng số này, phần còn lại của quá trình tính là hoàn toàn giống nhau. Với cách chọn trọng số, nói chung ta có
    
    $$
    \sum_{i=0}^ni^r\left\lfloor \frac{ai+b}{c} \right\rfloor^s = \sum_{i=0}^n\sum_{j=0}^{m-1} i^r\left((j+1)^s-j^s\right)\left[j<\left\lfloor\frac{ai+b}{c}\right\rfloor\right].
    $$
    
    Một đặc điểm khác của bài này là $g$ và $h$ khi tính đệ quy sẽ đan xen với nhau. Vì vậy, cần xem $(f,g,h)$ là một bộ ba và đệ quy đồng thời.
    
    ```cpp
    --8<-- "docs/math/code/euclidean/euclidean-1.cpp"
    ```

???+ example "[Tsinghua Training 2014 - Sum](https://www.luogu.com.cn/problem/P5172)"
    Có nhiều truy vấn. Cho các số nguyên dương $n$ và $r$, hãy tính
    
    $$
    \sum_{d=1}^n(-1)^{\lfloor d\sqrt{r}\rfloor}.
    $$

??? note "Lời giải 1"
    Nếu $r$ là số chính phương, thì khi $\sqrt{r}$ chẵn, tổng bằng $n$; ngược lại, tổng luân phiên giữa $0$ và $-1$ tùy theo tính chẵn lẻ của $n$. Sau đây xét trường hợp $r$ không phải số chính phương.
    
    Để áp dụng thuật toán Euclid tương tự, trước hết chuyển tổng về dạng quen thuộc:
    
    $$
    \begin{aligned}
    \sum_{d=1}^n(-1)^{\lfloor d\sqrt{r}\rfloor} &= \sum_{d=1}^n\left(1 - 2(\lfloor d\sqrt{r}\rfloor\bmod 2)\right)\\
    &= n - 2\sum_{d=1}^n\left(\lfloor d\sqrt{r}\rfloor - 2\left\lfloor\dfrac{\lfloor d\sqrt{r}\rfloor}{2}\right\rfloor\right) \\
    &= n - 2\sum_{d=1}^n\lfloor d\sqrt{r}\rfloor + 4 \sum_{d=1}^n\left\lfloor\dfrac{d\sqrt{r}}{2}\right\rfloor\\
    &= n - 2f(n,1,0,1) + 4f(n,1,0,2)
    \end{aligned}
    $$
    
    Hàm $f$ ở đây có dạng
    
    $$
    f(a,b,c,n) = \sum_{i=1}^n\left\lfloor\dfrac{a\sqrt{r}+b}{c}i\right\rfloor.
    $$
    
    Khác với thuật toán trong phần chính, hệ số góc ở đây không còn là số hữu tỉ. Đặt hệ số góc
    
    $$
    k = \dfrac{a\sqrt{r}+b}{c}.
    $$
    
    Tương tự, ta chia thành hai trường hợp. Nếu $k\ge 1$, thì
    
    $$
    \begin{aligned}
    f(a,b,c,n) &= \sum_{i=1}^n \lfloor ki\rfloor = \sum_{i=1}^n \lfloor(k-\lfloor k\rfloor)i\rfloor + \lfloor k\rfloor \sum_{i=1}^ni\\
    &= \lfloor k\rfloor\dfrac{n(n+1)}{2} + f(a,b-c\lfloor k\rfloor,c,n).
    \end{aligned}
    $$
    
    Bài toán được chuyển về trường hợp hệ số góc nhỏ hơn một. Nếu $k<1$, đặt $m=\lfloor nk\rfloor$, ta có
    
    $$
    \begin{aligned}
    f(a,b,c,n) &= \sum_{i=1}^n \lfloor ki\rfloor = \sum_{i=1}^n\sum_{j=1}^m[j\le\lfloor ki\rfloor]\\
    &= \sum_{j=1}^m\sum_{i=1}^n[i>\lfloor k^{-1}j\rfloor] = nm - \sum_{j=1}^m\sum_{i=1}^n[i\le\lfloor k^{-1}j\rfloor].
    \end{aligned}
    $$
    
    Trong suy luận này, điều kiện để hoán đổi $i$ và $j$ đơn giản hơn trường hợp ở phần chính, vì đường thẳng $y=kx$ không có điểm lưới nào ngoài gốc tọa độ nằm trên nó. Mấu chốt là viết tổng sau khi hoán đổi về dạng $f(a,b,c,n)$, tương đương với việc yêu cầu $a',b',c'$ thỏa mãn
    
    $$
    k^{-1} = \dfrac{a'\sqrt{r}+b'}{c'}.
    $$
    
    Điều này không khó; chỉ cần hữu tỉ hóa mẫu số, ta được
    
    $$
    k^{-1} = \dfrac{c}{a\sqrt{r}+b} = \dfrac{ca\sqrt{r}-cb}{a^2r-b^2}.
    $$
    
    Do đó,
    
    $$
    a'=ca,~b'=-cb,~c'=a^2r-b^2.
    $$
    
    Suy ra
    
    $$
    f(a,b,c,n) = nm - f(ca,-cb,a^2r-b^2,m).
    $$
    
    Để tránh tràn số nguyên, mỗi lần cần chia đồng thời $a,b,c$ cho ước chung lớn nhất của chúng. Vì quá trình tính này hoàn toàn giống quá trình tính liên phân số của $k$, theo [lý thuyết liên phân số](./continued-fraction.md#số-vô-tỉ-bậc-hai), chỉ cần bảo đảm $\gcd(a,b,c)=1$ thì trong quá trình tính chúng chắc chắn nằm trong phạm vi kiểu số nguyên. Ngoài ra, dù $(a,b,c,n)$ không bị tràn, trong phạm vi dữ liệu của bài này, $f(a,b,c,n)$ có thể vượt quá phạm vi số nguyên $64$ bit; cứ để tràn tự nhiên, không cần xử lý thêm, vì kết quả cuối cùng chắc chắn nằm trong $[-n,n]$.
    
    Dù hệ số góc không bao giờ trở thành không, độ phức tạp của thuật toán vẫn là $O(\log n)$; điều này dễ thấy từ lập luận về độ phức tạp thuật toán ở trên.
    
    ```cpp
    --8<-- "docs/math/code/euclidean/euclidean-2.cpp"
    ```

???+ example "[Fraction](https://www.luogu.com.cn/problem/P5179)"
    Cho các số nguyên dương $a,b,c,d$, hãy tìm trong tất cả các phân số tối giản $p/q$ thỏa mãn $a/b<p/q<c/d$ phân số có thứ tự từ điển của $(q,p)$ nhỏ nhất.

??? note "Lời giải"
    Bài này cũng là một ứng dụng kinh điển của [cây Stern-Brocot](./stern-brocot.md); lời giải liên quan có thể tìm ở [đây](./continued-fraction.md#cây-của-liên-phân-số). Vì nó chỉ phụ thuộc vào cấu trúc đệ quy của phân số, nó cũng có thể được giải bằng phương pháp tương tự thuật toán Euclid, nên cũng có thể xem là một ứng dụng của thuật toán Euclid tương tự.
    
    Nếu giữa $a/b$ và $c/d$ (không tính hai đầu mút) tồn tại ít nhất một số tự nhiên, có thể lấy trực tiếp $(q,p)=(1,\lfloor a/b\rfloor+1)$. Nếu không, chắc chắn có
    
    $$
    \left\lfloor\dfrac{a}{b}\right\rfloor \le \dfrac{a}{b} <\dfrac{p}{q} <\dfrac{c}{d}\le\left\lfloor\dfrac{a}{b}\right\rfloor+1.
    $$
    
    Từ bất đẳng thức này có thể thấy phần nguyên của $p/q$ được xác định là $\lfloor a/b\rfloor$; loại bỏ trực tiếp phần nguyên đó rồi lấy nghịch đảo toàn bộ để xác định phần thập phân của nó. Đây chính là [phương pháp cơ bản](./continued-fraction.md#cách-tìm-biểu-diễn-liên-phân-số) để xác định liên phân số của $p/q$. Nếu đáp án cuối cùng là $p/q$, độ phức tạp thời gian của thuật toán là $O(\log\min\{p,q\})$.
    
    Ở đây có một chi tiết cần xử lý: sau khi lấy nghịch đảo, phân số nhỏ nhất theo thứ tự từ điển có còn là phân số nhỏ nhất theo thứ tự từ điển trước khi lấy nghịch đảo hay không. Nói cách khác, trong các phân số $p/q$ thỏa mãn $a/b<p/q<c/d$, phân số có thứ tự từ điển $(q,p)$ nhỏ nhất có đồng thời là phân số có thứ tự từ điển $(p,q)$ nhỏ nhất hay không. Giả sử ngược lại, đặt $p/q$ là phân số nhỏ nhất theo thứ tự từ điển $(q,p)$, nhưng $r/s\neq p/q$ là phân số nhỏ nhất theo thứ tự từ điển $(r,s)$. Khi đó chắc chắn có $r<p$ và $q<s$. Nhưng điều này cho thấy
    
    $$
    \dfrac{a}{b} < \dfrac{r}{s} < \dfrac{r}{q} < \dfrac{p}{q} < \dfrac{c}{d}.
    $$
    
    Do đó $r/q$ theo bất kỳ thứ tự từ điển nào cũng đều nhỏ hơn nghiêm ngặt lời giải hiện tại. Điều này mâu thuẫn với giả thiết. Vì vậy thuật toán trên là đúng.
    
    ```cpp
    --8<-- "docs/math/code/euclidean/euclidean-3.cpp"
    ```

<span id="thuật-toán-euclid-vạn-năng"></span>
## Thuật toán Euclid vạn năng

Phần trước đã thảo luận cách suy ra thuật toán Euclid tương tự; quá trình đó thường khá rườm rà, và những tổng mà nó giải được chủ yếu là các tổng có thể chuyển thành bài toán đếm điểm nguyên (có trọng số) dưới một đường thẳng. Phần này thảo luận một phương pháp tổng quát hơn, trừu tượng hóa thêm quá trình trên để giải được nhiều bài toán hơn. Vì vậy, phương pháp này cũng được gọi là thuật toán Euclid vạn năng. Nó cũng tận dụng cấu trúc đệ quy của phân số để giải bài toán, nhưng cách rút gọn bài toán hơi khác với thuật toán Euclid tương tự.

Vẫn xét bài toán tính tổng kinh điển:

$$
f(a,b,c,n)=\sum_{i=1}^n\left\lfloor \frac{ai+b}{c} \right\rfloor,
$$

trong đó $a,b,c,n$ đều là số nguyên dương.

<span id="chuyển-hóa-bài-toán"></span>
### Chuyển hóa bài toán

Xét đoạn thẳng có tham số $(a,b,c,n)$:

$$
y = \frac{ax+b}{c},~0< x\le n.
$$

Với đoạn thẳng này, có thể định nghĩa một chuỗi gồm $U$ và $R$ theo cách sau; chuỗi này cũng được gọi là **dãy thao tác**:

-   Chuỗi có đúng $n$ ký tự $R$ và $m=\lfloor(an+b)/c\rfloor$ ký tự $U$;
-   Số ký tự $U$ đứng trước ký tự $R$ thứ $i$ đúng bằng $\lfloor(ai+b)/c\rfloor$, với $i=1,\cdots,n$.

Từ trực giác hình học, điều này gần tương đương với việc bắt đầu từ gốc tọa độ: mỗi lần đi sang phải qua một đường lưới dọc thì ghi một $R$, mỗi lần đi lên qua một đường lưới ngang thì ghi một $U$. Như hình dưới:

![](./images/euclidean-universal.svg)

Dĩ nhiên, định nghĩa như vậy còn cần xét một loạt trường hợp đặc biệt:

-   Khi đi qua điểm nguyên (tức đồng thời đi lên và đi sang phải), cần ghi $U$ trước rồi mới ghi $R$;
-   Ở đầu chuỗi, ngoài số lần đi lên qua đường lưới trong khoảng $(0,1]$, còn cần bổ sung thêm $\lfloor b/c\rfloor$ ký tự $U$;
-   Ở cuối chuỗi, không được có thêm ký tự $U$ dư.

Nếu phần mô tả trực giác hình học còn chỗ nào chưa rõ, có thể đối chiếu với định nghĩa trong phương pháp đại số ở trên. Mô tả trực giác hình học giúp hiểu quá trình thuật toán phía dưới.

Ý tưởng cơ bản của thuật toán Euclid vạn năng là xem $U$ và $R$ trong dãy thao tác đều là phần tử của một [vị nhóm](../algebra/basic.md#nhóm), xem toàn bộ dãy thao tác là tích của các phần tử trong vị nhóm, và đáp án cuối cùng của bài toán liên quan đến tích này.

Ví dụ trong bài này, có thể định nghĩa vector trạng thái $v = (1,y,\sum y)$, biểu thị trạng thái hiện tại sau khi bắt đầu từ gốc tọa độ và trải qua một số lần đi lên, đi sang phải qua đường lưới. Trong đó, thành phần thứ nhất là hằng số, thành phần thứ hai là tung độ $y$, thành phần thứ ba là tổng cần tìm. Ban đầu, $v=(1,0,0)$. Mỗi lần đi lên qua một đường lưới ngang, tung độ tăng thêm một, tương đương với việc nhân phải vector trạng thái với ma trận

$$
U = \begin{pmatrix}1 & 1 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1\end{pmatrix}.
$$

Mỗi lần đi sang phải qua một đường lưới dọc, tổng cộng thêm một lần tung độ hiện tại, tương đương với việc nhân phải vector trạng thái với ma trận

$$
R = \begin{pmatrix}1 & 0 & 0 \\ 0 & 1 & 1 \\ 0 & 0 & 1\end{pmatrix}.
$$

Do đó trạng thái cuối cùng là tích $(1,0,0)S$, trong đó $S$ được hiểu là tích của các ma trận nói trên. Đáp án cần tìm chính là thành phần thứ ba của trạng thái cuối cùng.

Ngoài việc định nghĩa các phần tử trong vị nhóm là ma trận, ta cũng có thể định nghĩa chúng là đóng góp của một đoạn dãy thao tác vào kết quả cuối cùng, rồi định nghĩa tích của hai thao tác là phép hợp nhất đóng góp của hai đoạn dãy thao tác.

Trong bài này, có thể định nghĩa đóng góp của mỗi đoạn dãy thao tác là $(x,y,\sum y)$. Để giải thích chặt chẽ các ký hiệu này, có thể xem các thành phần đều là hàm của dãy thao tác, tức với dãy thao tác $S$, đóng góp của nó có thể viết là $(x(S),y(S),(\sum y)(S))$. Trong đó, $x(S)$ và $y(S)$ lần lượt tương ứng với số ký tự $R$ và $U$ trong dãy thao tác $S$, tức số lần đoạn thẳng đi sang phải và đi lên qua đường lưới. Với ký hiệu tổng ở thành phần cuối, nói chung ta định nghĩa như sau: với một hàm $f(S)$ trên dãy thao tác, có thể định nghĩa $(\sum f)(S)$, hoặc ký hiệu $\sum_S f$, là biểu thức

$$
\sum_S f := \sum\{f(S_{[1,r]}):S_r=R\}.
$$

Trong đó, $S_r$ là ký tự thứ $r$ trong $S$, còn $S_{[1,r]}$ là tiền tố gồm $r$ ký tự đầu của $S$. Nói cách khác, ký hiệu tổng này có thể xem là phép lấy tổng trên tất cả các tiền tố của dãy thao tác $S$ kết thúc bằng $R$. Ví dụ,

$$
\sum_S 1 = x,~ \sum_S x = \dfrac{1}{2}x(x+1).
$$

Một ví dụ khác, $\sum y$ chính là tổng số lần đi lên qua đường lưới trước mỗi lần đi sang phải qua đường lưới trong dãy thao tác. Với cả dãy thao tác, giá trị của $y$ tại mọi tiền tố kết thúc bằng $R$ chính là các giá trị $\lfloor(ai+b)/c\rfloor$ tại $i=1,\cdots,n$. Vì vậy, $\sum y$ tính trên cả dãy thao tác chính là lượng cần tìm của bài toán này.

Ban đầu, $U=(0,1,0)$, $R=(1,0,0)$. Tiếp đó, có thể định nghĩa tích của hai phần tử $(x_1,y_1,s_1)$ và $(x_2,y_2,s_2)$ là

$$
(x_1,y_1,s_1)\cdot (x_2,y_2,s_2) = (x_1+x_2,y_1+y_2,s_1+s_2+x_2y_1).
$$

Trong đó, kết quả hợp nhất của hạng đóng góp cuối cùng có thể nhận được bằng tính toán sau:

$$
\sum_{S_1+S_2}y = \sum_{S_1}y + \sum_{S_2}(y+y_1) = \sum_{S_1}y + \sum_{S_2}y + y_1\sum_{S_2}1 = s_1+s_2+x_2y_1.
$$

Dễ kiểm tra rằng phép nhân này thỏa mãn luật kết hợp và có đơn vị là $(0,0,0)$, nên các phần tử này tạo thành một vị nhóm dưới phép nhân đó. Đáp án cần tìm chính là thành phần thứ ba của tích.

Cả hai cách đều cho kết quả đúng. Tuy nhiên, vì giữ lại khá nhiều thông tin dư thừa, hằng số của phép toán ma trận lớn hơn, nên cách thứ hai thực dụng hơn khi xử lý bài toán thực tế.

<span id="quá-trình-thuật-toán"></span>
### Quá trình thuật toán

Khác với thuật toán Euclid tương tự, vốn rút gọn bài toán một cách tổng thể, thuật toán Euclid vạn năng rút gọn bài toán bằng cách gộp các thao tác theo từng nhóm. Ký hiệu tích của các thao tác tương ứng với chuỗi là

$$
F(a,b,c,n,U,R).
$$

Quá trình rút gọn cụ thể như sau:

-   Khi $b\ge c$, ở đầu dãy thao tác có $\lfloor b/c\rfloor$ ký tự $U$; tính trực tiếp tích của chúng và loại các $U$ này khỏi dãy thao tác. Khi đó, số ký tự $U$ đứng trước ký tự $R$ thứ $i$ bằng

    $$
    \left\lfloor\dfrac{ai+b}{c}\right\rfloor - \left\lfloor\dfrac{b}{c}\right\rfloor = \left\lfloor\dfrac{ai+(b\bmod c)}{c}\right\rfloor.
    $$

    Vì vậy, điều này tương đương với việc biến đổi tham số đoạn thẳng từ $(a,b,c,n)$ thành $(a,b\bmod c,c,n)$. Trong trường hợp này, ta có

    $$
    F(a,b,c,n,U,R) = U^{\lfloor b/c\rfloor}F(a,b\bmod c,c,n,U,R).
    $$

-   Khi $a\ge c$, trước mỗi ký tự $R$ trong dãy thao tác đều có ít nhất $\lfloor a/c\rfloor$ ký tự $U$, nên có thể gộp chúng vào $R$. Nói cách khác, có thể thay $R$ bằng $U^{\lfloor a/c\rfloor}R$. Trong chuỗi sau khi gộp, số ký tự $U$ đứng trước ký tự $R$ thứ $i$ bằng

    $$
    \left\lfloor\dfrac{ai+b}{c}\right\rfloor - \left\lfloor\dfrac{a}{c}\right\rfloor i = \left\lfloor\dfrac{(a\bmod c)i+b}{c}\right\rfloor.
    $$

    Vì vậy, điều này tương đương với việc biến đổi tham số đoạn thẳng từ $(a,b,c,n)$ thành $(a\bmod c,b,c,n)$. Trong trường hợp này, ta có

    $$
    F(a,b,c,n,U,R) = F(a\bmod c,b,c,n,U,U^{\lfloor a/c\rfloor}R).
    $$

-   Với trường hợp còn lại, cần lật trục hoành và trục tung; về cơ bản đây là hoán đổi $U$ và $R$, chỉ có điều tham số của đoạn thẳng sau khi lật cần được tính cẩn thận. Kết hợp với định nghĩa dãy thao tác, ta cần xác định các hệ số $(a',b',c',n')$ sao cho trong dãy thao tác trước khi biến đổi, số ký tự $R$ đứng trước ký tự $U$ thứ $j$ đúng bằng $\lfloor(a'j+b')/c'\rfloor$ và tổng cộng có $n'$ ký tự $U$. Theo định nghĩa,

    $$
    n'=\left\lfloor\dfrac{an+b}{c}\right\rfloor = m,
    $$

    còn số ký tự $R$ đứng trước ký tự $U$ thứ $j$ bằng giá trị lớn nhất của $i$ sao cho

    $$
    \begin{aligned}
    \left\lfloor\dfrac{ai+b}{c}\right\rfloor < j 
    &\iff \dfrac{ai+b}{c} < j \iff i < \dfrac{cj-b}{a} \\
    &\iff i < \left\lceil\dfrac{cj-b}{a}\right\rceil = \left\lfloor\dfrac{cj-b - 1}{a}\right\rfloor + 1.
    \end{aligned}
    $$

    Do đó, $i = \lfloor(cj-b-1)/a\rfloor$. Quá trình suy luận này tương tự suy luận của thuật toán Euclid tương tự ở trên, và cũng dùng các tính chất của hàm làm tròn lên, làm tròn xuống.

    Có hai chi tiết cần xử lý:

    -   Hạng tung độ gốc $-(b+1)/a$ là số âm. Chú ý rằng nếu tịnh tiến đoạn thẳng sang trái một đơn vị, có thể đưa tung độ gốc về không âm, vì luôn có $(c-b-1)/a\ge 0$. Do đó, có thể tách đoạn đầu $R^{\lfloor(c-b-1)/a\rfloor}U$ trước khi hoán đổi, và chỉ hoán đổi $U$ với $R$ trong phần dãy thao tác còn lại;
    -   Sau khi hoán đổi $U$ và $R$, ở cuối tồn tại ký tự $U$ dư. Vì vậy, trước khi hoán đổi $U$ và $R$, cần tách đoạn $R$ cuối cùng ra trước, và chỉ hoán đổi $U$ với $R$ trong phần dãy thao tác còn lại. Số lượng ký tự $R$ trong đoạn này là $n-\lfloor(cm-b-1)/a\rfloor$.

    Sau khi bỏ một số ký tự ở đầu và cuối, số ký tự $R$ đứng trước ký tự $U$ thứ $j$ trở thành:

    $$
    \left\lfloor\dfrac{c(j+1)-b-1}{a}\right\rfloor - \left\lfloor\dfrac{c-b-1}{a}\right\rfloor = \left\lfloor\dfrac{cj+(c-b-1)\bmod a}{a}\right\rfloor.
    $$

    Nhắc lại, số lượng ký tự $U$ trong chuỗi trước khi hoán đổi là $m = \lfloor(an+b)/c\rfloor$. Thao tác tịnh tiến sang trái một đơn vị nói trên yêu cầu phải có ít nhất một ký tự $U$ trước khi hoán đổi, tức $m>0$. Dựa vào điều kiện này, ta chia thành hai trường hợp:

    -   Với trường hợp $m>0$, sau khi xử lý hai điểm trên, dãy thao tác sau khi hoán đổi $U$ và $R$ là dãy hợp lệ ứng với đoạn thẳng có tham số $(c,(c-b-1)\bmod a,a,m-1)$. Vì vậy,

        $$
        F(a,b,c,n,U,R) = R^{\lfloor(c-b-1)/a\rfloor}UF(c,(c-b-1)\bmod a,a,m-1,R,U)R^{n-\lfloor(cm-b-1)/a\rfloor}.
        $$

    -   Riêng với trường hợp $m=0$, dãy thao tác trước khi hoán đổi chỉ chứa $n$ ký tự $R$, không cần hoán đổi, có thể trả về trực tiếp:

        $$
        F(a,b,c,n,U,R) = R^n.
        $$

        Khác với thuật toán Euclid tương tự, trường hợp đặc biệt này của thuật toán Euclid vạn năng phải được xử lý riêng, nếu không sẽ liên quan đến lũy thừa âm và không thể tính đúng.

Dựa trên các thảo luận này, ta có thể giải bài toán bằng đệ quy.

Giả sử thời gian cho một phép nhân giữa các phần tử trong vị nhóm là $O(1)$. Khi các phép lũy thừa của những phần tử này trong quá trình tính đều dùng [lũy thừa nhị phân](../binary-exponentiation.md), độ phức tạp cuối cùng của thuật toán là $O(\log\max\{a,c\}+\log(b/c))$[^complexity].

??? note "Giải thích về độ phức tạp"
    So với thuật toán Euclid (tương tự), thuật toán Euclid vạn năng chỉ có thêm bước tính lũy thừa nhanh. Độ phức tạp của phần còn lại tương tự thuật toán Euclid tương tự, đã được chứng minh là $O(\log\min\{a,c,n\})$. Bây giờ cần tính tổng độ phức tạp của các phép lũy thừa nhanh này.
    
    Ngoài vòng lặp đầu tiên, luôn có $b<c$, nên mỗi vòng lặp này đều liên quan đến ba lần tính lũy thừa nhanh; tổng độ phức tạp là:
    
    $$
    O\left(\log\left\lfloor\dfrac{a}{c}\right\rfloor+\log\left\lfloor\dfrac{c-b_1-1}{a_1}\right\rfloor+\log\left(n-\left\lfloor\dfrac{cm-b_1-1}{a_1}\right\rfloor\right)\right),
    $$
    
    trong đó $a_1=a\bmod c$, $b_1=b\bmod c$ và $m=\lfloor(a_1n+b_1)/c\rfloor$. Hai hạng sau lần lượt có các ước lượng:
    
    $$
    \begin{aligned}
    \dfrac{c-b_1-1}{a_1} &\le \dfrac{c}{a_1},\\
    n-\left\lfloor\dfrac{cm-b_1-1}{a_1}\right\rfloor &\le n - \dfrac{cm-b_1-1}{a_1} + 1 \\
    &\le n - \dfrac{c((a_1n+b_1)/c-1)-b_1-1}{a_1} +1 \\
    &= \dfrac{c+1}{a_1}+1.
    \end{aligned}
    $$
    
    Vì vậy, độ phức tạp của hai hạng này đều là $O(\log(c/a_1))$.
    
    Trong mỗi vòng lặp, tham số của đoạn thẳng biến đổi từ $(a,\cdot,c,\cdot)$ thành $(c,\cdot,a\bmod c,\cdot)$, và tổng độ phức tạp của vòng đó là
    
    $$
    O\left(\log\dfrac{a}{c}+\log\dfrac{c}{a\bmod c}\right).
    $$
    
    Xét toàn bộ các vòng đệ quy, những hạng này có thể triệt tiêu dạng telescoping, nên tổng độ phức tạp cuối cùng là $O(\log a+\log c)=O(\log\max\{a,c\})$.
    
    Cuối cùng, cộng thêm độ phức tạp $O(\log(b/c))$ của lũy thừa nhanh $U^{\lfloor b/c\rfloor}$ trong vòng lặp đầu tiên, ta nhận được tổng độ phức tạp $O(\log\max\{a,c\}+\log(b/c))$.

Quy trình của thuật toán Euclid vạn năng có thể viết thành một mẫu thống nhất; khi xử lý bài toán cụ thể, chỉ cần thay đổi phần cài đặt của kiểu mẫu `T`.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/math/code/euclidean/euclidean-4.cpp:euclidean"
    ```

Dùng thuật toán Euclid vạn năng, ta có cài đặt cho bài mẫu như sau:

??? example "Cài đặt bài mẫu ([Library Checker - Sum of Floor of Linear](https://judge.yosupo.jp/problem/sum_of_floor_of_linear))"
    ```cpp
    --8<-- "docs/math/code/euclidean/euclidean-4.cpp:full-text"
    ```

<span id="ví-dụ_1"></span>
### Ví dụ

???+ example "[Bài mẫu - Thuật toán Euclid tương tự](https://www.luogu.com.cn/problem/P5170)"
    Có nhiều truy vấn. Cho các số nguyên dương $a,b,c,n$, hãy tính
    
    $$
    \begin{aligned}
    f(a,b,c,n) &= \sum_{i=0}^n\left\lfloor \frac{ai+b}{c} \right\rfloor,\\
    g(a,b,c,n) &= \sum_{i=0}^ni\left\lfloor \frac{ai+b}{c} \right\rfloor,\\
    h(a,b,c,n) &= \sum_{i=0}^n\left\lfloor \frac{ai+b}{c} \right\rfloor^2.
    \end{aligned}
    $$

??? note "Lời giải 2"
    Để áp dụng mẫu của thuật toán Euclid vạn năng, trước hết tách riêng hạng $i=0$ để xét độc lập. Với phần còn lại, có thể xem là tính lần lượt $\sum y,\sum xy,\sum y^2$ trên đoạn thẳng có tham số $(a,b,c,n)$. Như phần chính đã nói, có hai cách chuyển dãy thao tác thành phần tử của vị nhóm.
    
    **Phép toán ma trận**: định nghĩa vector trạng thái là $(1,x,y,xy,y^2,\sum y,\sum xy,\sum y^2)$. Trạng thái ban đầu là $(1,0,0,0,0,0,0,0)$, hai thao tác lần lượt là
    
    $$
    U =
    \begin{pmatrix}
    1 & 0 & 1 & 0 & 1 & 0 & 0 & 0 \\
    0 & 1 & 0 & 1 & 0 & 0 & 0 & 0 \\
    0 & 0 & 1 & 0 & 2 & 0 & 0 & 0 \\
    0 & 0 & 0 & 1 & 0 & 0 & 0 & 0 \\
    0 & 0 & 0 & 0 & 1 & 0 & 0 & 0 \\
    0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 \\
    0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 \\
    0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 
    \end{pmatrix},~
    R = 
    \begin{pmatrix}
    1 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\
    0 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\
    0 & 0 & 1 & 1 & 0 & 1 & 1 & 0 \\
    0 & 0 & 0 & 1 & 0 & 0 & 1 & 0 \\
    0 & 0 & 0 & 0 & 1 & 0 & 0 & 1 \\
    0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 \\
    0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 \\
    0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 
    \end{pmatrix}.
    $$
    
    Đáp án cuối cùng là ba thành phần cuối của vector thu được khi nhân phải trạng thái ban đầu với tích của các ma trận thao tác này.
    
    Cách làm này có hằng số rất lớn và không thể qua bài này; ở đây chỉ đưa chi tiết để hỗ trợ hiểu bài.
    
    **Hợp nhất đóng góp**: định nghĩa đóng góp của một đoạn dãy thao tác là $(x,y,\sum y,\sum xy,\sum y^2)$. Hai thao tác lần lượt là
    
    $$
    U = (0,1,0,0,0),~ R = (1,0,0,0,0).
    $$
    
    Khi hợp nhất đóng góp, ta có
    
    $$
    \begin{aligned}
    \sum_{S_1+S_2} y 
    &= \sum_{S_1}y + \sum_{S_2}(y+y_1) = \sum_{S_1}y + \sum_{S_2}y + x_2y_1,\\
    \sum_{S_1+S_2} xy
    &= \sum_{S_1}xy + \sum_{S_2}(x+x_1)(y+y_1) \\
    &= \sum_{S_1}xy + \sum_{S_2}xy + x_1\sum_{S_2}y + y_1\sum_{S_2}x + x_1y_1\sum_{S_2}1\\
    &= \sum_{S_1}xy + \sum_{S_2}xy + x_1\sum_{S_2}y + \dfrac{1}{2}x_2(x_2+1)y_1 + x_1x_2y_1,\\
    \sum_{S_1+S_2}y^2
    &= \sum_{S_1}y^2 + \sum_{S_2}(y+y_1)^2 \\
    &= \sum_{S_1}y^2 + \sum_{S_2}y^2 + 2y_1\sum_{S_2}y + y_1^2\sum_{S_2}1  \\
    &= \sum_{S_1}y^2 + \sum_{S_2}y^2 + 2y_1\sum_{S_2}y + x_2y_1^2.
    \end{aligned}
    $$
    
    Điều này cho thấy nên định nghĩa phép nhân của thao tác là
    
    $$
    \begin{aligned}
    &(x_1,y_1,s_1,t_1,u_1)\cdot(x_2,y_2,s_2,t_2,u_2)\\
    &= (x_1+x_2,y_1+y_2,s_1+s_2+x_2y_1,\\
    &\qquad t_1+t_2+x_1s_2+(1/2)x_2(x_2+1)y_1+x_1x_2y_1,\\
    &\qquad u_1+u_2+2y_1s_2+x_2y_1^2).
    \end{aligned}
    $$
    
    Dù kiểm tra trực tiếp khá rườm rà, vector đóng góp được định nghĩa ở trên đúng là tạo thành một vị nhóm dưới phép nhân này, với đơn vị là $(0,0,0,0,0)$.
    
    Với trường hợp tổng quát, ta có
    
    $$
    \begin{aligned}
    \sum_{S_1+S_2}x^ry^s &= \sum_{S_1}x^ry^s + \sum_{S_2}(x+x_1)^r(y+y_1)^s \\
    &= \sum_{S_1}x^ry^s + \sum_{i=0}^r\sum_{j=0}^s\binom{r}{i}\binom{s}{j}x_1^{r-i}y_1^{s-j}\sum_{S_2}x^iy^j.
    \end{aligned}
    $$
    
    Chỉ cần duy trì tốt mọi đóng góp có bậc thấp hơn, ta có thể tính tổng trong trường hợp tổng quát.
    
    ```cpp
    --8<-- "docs/math/code/euclidean/euclidean-5.cpp"
    ```

???+ example "[Tsinghua Training 2014 - Sum](https://www.luogu.com.cn/problem/P5172)"
    Có nhiều truy vấn. Cho các số nguyên dương $n$ và $r$, hãy tính
    
    $$
    \sum_{d=1}^n(-1)^{\lfloor d\sqrt{r}\rfloor}.
    $$

??? note "Lời giải 2"
    Trước hết, xử lý riêng trường hợp $r$ là số chính phương, hoàn toàn giống phần trước nên bỏ qua. Ở đây chỉ xét trường hợp $r$ không phải số chính phương.
    
    Có nhiều cách áp dụng thuật toán Euclid vạn năng cho bài này. Chẳng hạn, có thể định nghĩa một biến đổi tuyến tính cho mỗi thao tác:
    
    $$
    U(x) = -x,~ R(x) = x + 1.
    $$
    
    Phép nhân của thao tác được định nghĩa là phép hợp thành các biến đổi tuyến tính. Khi đó, đáp án cuối cùng là giá trị tại $x=0$ của hàm thu được bằng cách hợp thành các biến đổi tương ứng với dãy thao tác.
    
    Cũng có thể định nghĩa đóng góp cho mỗi đoạn dãy thao tác. Đóng góp có thể định nghĩa là $((-1)^y,\sum(-1)^y)$. Khi đó, hai thao tác lần lượt lấy
    
    $$
    U = (0,-1),~ R = (1,1).
    $$
    
    Phép hợp nhất đóng góp được định nghĩa là
    
    $$
    (u_1,v_1)\cdot(u_2,v_2) = (u_1u_2,v_1+u_1v_2).
    $$
    
    Dễ kiểm tra rằng dưới phép nhân này, mọi thao tác tạo thành một vị nhóm, và đơn vị là $(0,1)$. Đáp án cuối cùng chính là thành phần thứ hai của tích tất cả phần tử.
    
    Hai cách này là nhất quán, vì nếu viết biến đổi tuyến tính dưới dạng $f(x)=u+vx$, thì sự thay đổi của các hệ số khi hợp thành biến đổi tuyến tính đúng bằng phép nhân thao tác nói trên. Nói cách khác, hai vị nhóm này đẳng cấu.
    
    Trong bài này, tham số của đoạn thẳng là $(k,n)$, trong đó $k\in\mathbf R$ là hệ số góc của đường thẳng. Đặt tích tương ứng với dãy thao tác là $F(k,n,U,R)$. Khi đó có thuật toán đệ quy sau:
    
    -   Nếu $k\ge 1$, trước mỗi ký tự $R$ trong dãy thao tác đều có ít nhất $\lfloor k\rfloor$ ký tự $U$, nên
    
        $$
        F(k,n,U,R) = F(k-\lfloor k\rfloor,n,U,U^{\lfloor k\rfloor} R).
        $$
    -   Nếu $k<1$, hoán đổi $U$ và $R$ trong dãy thao tác, đồng thời bỏ ký tự $U$ ở cuối (tức $R$ trước khi hoán đổi), nên
    
        $$
        F(k,n,U,R) = F(k^{-1},m,R,U)R^{n-\lfloor k^{-1}m\rfloor}.
        $$
    
    Trong thuật toán, quá trình lặp của $k$ thực chất là quá trình tìm khai triển liên phân số của $\sqrt{r}$. Vì vậy, có thể áp dụng [thuật toán PQa](./pell-equation.md#thuật-toán-pqa). Quá trình tìm liên phân số và quá trình lặp của thuật toán Euclid vạn năng có thể được thực hiện đồng thời.
    
    Tương tự trường hợp của thuật toán Euclid tương tự, độ phức tạp của thuật toán vẫn là $O(\log n)$.
    
    ```cpp
    --8<-- "docs/math/code/euclidean/euclidean-6.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

Bài mẫu:

-   [Library Checker - Sum of Floor of Linear](https://judge.yosupo.jp/problem/sum_of_floor_of_linear)
-   [Luogu P5170 - Bài mẫu: Thuật toán Euclid tương tự](https://www.luogu.com.cn/problem/P5170)
-   [Luogu P5171 Earthquake](https://www.luogu.com.cn/problem/P5171)
-   [Luogu P5172 - Tsinghua Training 2014: Sum](https://www.luogu.com.cn/problem/P5172)
-   [Luogu P4132 - BJOI2012: Phương trình không tính ra được](https://www.luogu.com.cn/problem/P4132)
-   [LOJ 138. Thuật toán Euclid tương tự](https://loj.ac/p/138)
-   [LOJ 6440. Euclid vạn năng](https://loj.ac/p/6440)
-   [Luogu P5179 Fraction](https://www.luogu.com.cn/problem/P5179)
-   [Codeforces 1182 F. Maximum Sine](https://codeforces.com/problemset/problem/1182/F)

Bài ứng dụng:

-   [Luogu P4433 - COCI 2009/2010 #1: ALADIN](https://www.luogu.com.cn/problem/P4433)
-   [AtCoder Beginner Contest 372 G - Ax + By < C](https://atcoder.jp/contests/abc372/tasks/abc372_g)
-   [AtCoder Beginner Contest 313 G - Redistribution of Piles](https://atcoder.jp/contests/abc313/tasks/abc313_g)
-   [AtCoder Beginner Contest 283 Ex - Popcount Sum](https://atcoder.jp/contests/abc283/tasks/abc283_h)
-   [Codeforces 1098 E. Fedya the Potter](https://codeforces.com/problemset/problem/1098/E)
-   [Codeforces 868 G. El Toll Caves](https://codeforces.com/problemset/problem/868/G)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

[^complexity]: Trong những bài toán thường xét, $b$ thường cùng bậc với $a$, nên hạng $O(\log(b/c))$ có thể bỏ qua. Hơn nữa, nếu trước khi gọi thuật toán Euclid vạn năng ta thực hiện một vòng lấy modulo của thuật toán Euclid tương tự để loại bỏ ảnh hưởng của $b$, thì có thể tránh độ phức tạp của phép lũy thừa nhanh ở hạng này. Thực chất là vì trong các bài toán thông thường, dạng ban đầu của $U$ khá đặc biệt, lũy thừa của nó có dạng đơn giản hơn và không cần tính bằng lũy thừa nhanh. Chẳng hạn trong ví dụ ở phần chính, kết quả của $U^{\lfloor b/a\rfloor}$ chỉ là thay số $1$ không nằm trên đường chéo trong $U$ bằng $\lfloor b/a\rfloor$, không cần dùng lũy thừa nhanh.
