author: Early0v0

<span id="kiến-thức-chuẩn-bị"></span>
## Kiến thức chuẩn bị

-   [Hàm nhân](./basic.md#hàm-nhân-tính)

<span id="định-nghĩa"></span>
## Định nghĩa

Sàng Zhouge là một phương pháp sàng có thể tính tổng tiền tố của phần lớn hàm nhân trong độ phức tạp dưới tuyến tính.

Dưới đây lấy việc tính $\displaystyle\sum_{i=1}^nf(i)$ làm ví dụ để trình bày cụ thể nguyên lý của sàng Zhouge.

<span id="quy-ước"></span>
## Quy ước

-   $\mathbb P$ biểu thị tập số nguyên tố, $p_i$ biểu thị số nguyên tố thứ $i$.
-   $m$ biểu thị số lượng số nguyên tố không vượt quá $\sqrt n$.

<span id="yêu-cầu"></span>
## Yêu cầu

Khi $p\in\mathbb P,c\in\mathbb N$, $f(p^c)$ là một đa thức bậc thấp theo $p$.

<span id="ý-tưởng"></span>
## Ý tưởng

-   Với một số nguyên bất kì trong $[1,n]$, nó có nhiều nhất một thừa số nguyên tố $>\sqrt n$.
-   Tận dụng tính chất rằng $\left\lfloor\dfrac ni\right\rfloor(i\in[1,n]\cap\mathbb N)$ chỉ có cỡ $\sqrt n$ giá trị khác nhau để giảm độ phức tạp thời gian.

<span id="quy-trình"></span>
## Quy trình

Chia mọi số nguyên trong $[1,n]$ thành hai loại theo việc có thừa số nguyên tố $>\sqrt n$ hay không:

$$
\sum_{i=1}^nf(i)=\sum_{i=1}^n\left[\exists d\in(\sqrt n,n]\cap\mathbb P,d\mid i\right]f(i)+\sum_{i=1}^n\left[\forall d\in(\sqrt n,n]\cap\mathbb P,d\nmid i\right]f(i)
$$

Với nửa đầu, liệt kê thừa số lớn nhất, rồi dùng tính chất của hàm nhân để biến đổi:

$$
\sum_{i=1}^nf(i)=\sum_{i=1}^{\sqrt n}f(i)\cdot\left(\sum_{d=\lfloor\sqrt n\rfloor+1}^{\lfloor\frac ni\rfloor}[d\in\mathbb P]f(d)\right)+\sum_{i=1}^n\left[\forall d\in(\sqrt n,n]\cap\mathbb P,d\nmid i\right]f(i)
$$

Hai phần trước và sau có thể được tính riêng.

### Phần 1

> Tính $\displaystyle\sum_{i=1}^{\sqrt n}f(i)\cdot\left(\sum_{d=\lfloor\sqrt n\rfloor+1}^{\lfloor\frac ni\rfloor}[d\in\mathbb P]f(d)\right)$.

Xét việc liệt kê $i$, sau đó tính phần trong ngoặc trong $O(1)$.

Ký hiệu $\displaystyle g(t,l)=\sum_{i=1}^l[\forall j\in[1,t],\gcd(i,p_j)=1]f(i)$, tức là tổng giá trị $f$ của các số trong $[1,l]$ cùng nguyên tố với mọi $p_1,p_2,\dots,p_t$.

Như vậy, việc tính phần 1 trở thành $\displaystyle\sum_{i=1}^{\sqrt n}f(i)\cdot g\left(m,\left\lfloor\frac ni\right\rfloor\right)$.

Biên là $g(0,l)=\sum_{i=1}^lf(i)$, chuyển trạng thái $g(t,l)=g(t-1,l)-f(p_t)\cdot g\left(t-1,\left\lfloor\frac l{p_t}\right\rfloor\right)$.

$l$ có cỡ $\sqrt n$ giá trị khác nhau, và với mỗi giá trị cần liệt kê các thừa số nguyên tố của nó, nên độ phức tạp là $\displaystyle O\left(\frac{\sqrt n}{\ln\sqrt n}\cdot\sqrt n\right)= O\left(\frac n{\log n}\right)$; cần tối ưu.

Khi $p_{t+1}^2>l$, các số thỏa điều kiện chỉ có $1$, nên khi đó $g(t,l)=f(1)=1$.

Thay vào công thức truy hồi được: khi $p_t^2>l$, $g(t,l)=g(t-1,l)-f(p_t)$.

Vì vậy, một khi phát hiện $p_t^2>l$ thì dừng chuyển trạng thái. Gọi $t$ tại thời điểm này là $t_l$, khi đó $\forall t>t_l,g(t,l)=g(t_l,l)-\sum_{i=t_l}^{t-1}f(p_i)$.

Tiền xử lý tổng tiền tố giá trị $f$ trên các số nguyên tố là có thể tính nhanh $g$, độ phức tạp thời gian được tối ưu xuống $O\left(\dfrac{n^{\frac34}}{\log n}\right)$.

### Phần 2

> Tính $\displaystyle\sum_{i=1}^n\left[\forall d\in(\sqrt n,n]\cap\mathbb P,d\nmid i\right]f(i)$.

Ký hiệu $\displaystyle h(t,l)=\sum_{i=1}^l\left[i=\prod_{j=t}^mp_j^{c_j},c_j\in\mathbb N\right]f(i)$, tức là tổng giá trị $f$ của mọi số trong $[1,l]$ chỉ chứa các thừa số nguyên tố $p_t,p_{t+1},\dots,p_m$.

Phần 2 chính là tính $h(0,n)$.

Biên là $h(m+1,l)=1$, chuyển trạng thái $\displaystyle h(t,l)=h(t+1,l)+\sum_{c\in\mathbb N^*}f(p_t^c)\cdot h\left(t+1,\left\lfloor\frac l{p_t^c}\right\rfloor\right)$.

$l$ có cỡ $\sqrt n$ giá trị khác nhau, nên chuyển trạng thái trực tiếp có độ phức tạp $\displaystyle O\left(\sqrt n\cdot\frac{\sqrt n}{\ln\sqrt n}\right)= O\left(\frac n{\log n}\right)$; cần tối ưu.

Tương tự cách tối ưu của $g$, khi $p_t>l$, những số có thể tạo bởi $p_t,p_{t+1},\dots,p_m$ chỉ có $1$, khi đó $h(t,l)=f(1)=1$.

Tương tự, suy ra $\forall p_t^2>l,h(t,l)=h(t+1,l)+f(p_t)$.

Vì vậy, một khi phát hiện $p_t^2>l$ thì dừng chuyển trạng thái. Gọi $t$ tại thời điểm này là $t_l$; về sau khi dùng $h$, chỉ cần cộng giá trị $h$ tại thời điểm đó với $\displaystyle\sum_{i=p_{t_l}}^{\min(l,\sqrt n)}[i\in\mathbb P]f(i)$.

Độ phức tạp thời gian được tối ưu xuống $O\left(\dfrac{n^{\frac34}}{\log n}\right)$.

<span id="tính-tổng"></span>
### Tính tổng

Sau khi tính được đáp án của phần 1 và phần 2, cộng chúng lại là $\displaystyle\sum_{i=1}^nf(i)$.

<span id="tham-khảo"></span>
## Tham khảo

[Ghi chú học tập về sàng tuyến tính hàm nhân / sàng Dujiao / sàng Zhouge | Bill Yang's Blog](https://blog.bill.moe/multiplicative-function-sieves-notes)
