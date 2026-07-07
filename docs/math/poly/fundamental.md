<span id="định-nghĩa"></span>

## Định nghĩa

Mọi phương trình đa thức một biến bậc $n$ với hệ số phức, trong đó $n$ ít nhất bằng $1$, đều có ít nhất một nghiệm trên trường số phức.

Từ đó suy ra, một phương trình đa thức bậc $n$ với hệ số phức có đúng $n$ nghiệm trong trường số phức, tính cả nghiệm bội theo bội số.

Đôi khi định lý này cũng được phát biểu là:

Mọi đa thức một biến khác không bậc $n$ với hệ số phức đều có đúng $n$ nghiệm phức.

Chứng minh định lý cơ bản của đại số thường dùng đến hàm biến phức hoặc đại số hiện đại, vì vậy nó thường được sử dụng trực tiếp như một kết quả đã biết.

Theo định lý cơ bản của đại số, một đa thức hệ số phức $f(x)=a_nx^n+a_{n-1}x^{n-1}+\ldots+a_0$ nhất định có thể phân tích duy nhất thành:

$$
f(x)=a_n{(x-x_1)}^{k_1}{(x-x_2)}^{k_2}\ldots{(x-x_t)}^{k_t}
$$

trong đó mọi nghiệm đều là số phức, và $k_1+k_2+\ldots+k_t=n$.

<span id="định-lý-nghiệm-ảo-xuất-hiện-thành-cặp"></span>

## Định lý nghiệm ảo xuất hiện thành cặp

Định lý cơ bản của đại số nghiên cứu các đa thức hệ số phức. Khi nghiên cứu đa thức hệ số thực, tuy vẫn có thể phân tích ra nghiệm phức, nhưng cần mở rộng phạm vi nghiên cứu, nên không tiện lợi.

Nghiệm ảo: nghiệm không phải số thực.

Định lý: nếu một số phức là nghiệm của đa thức hệ số thực, thì số phức liên hợp của nó cũng là nghiệm của đa thức đó.

Chứng minh: chỉ cần lấy liên hợp hai vế của đẳng thức trong định lý cơ bản của đại số là xong.

Nếu bản thân nghiệm là số thực, lấy liên hợp vẫn là chính nó, nên không bị ảnh hưởng.

Nếu nghiệm là nghiệm ảo, thì số phức liên hợp của nghiệm ảo đó cũng là nghiệm của đa thức ban đầu. Như vậy hai nghiệm ảo có thể ghép thành một cặp.

Định lý: các nghiệm ảo liên hợp của phương trình hệ số thực nhất định xuất hiện thành cặp, và bội số của hai nghiệm ảo liên hợp bằng nhau.

Chứng minh: giả sử một nghiệm là $a+b\mathrm{i}$, khi đó nghiệm còn lại là $a-b\mathrm{i}$. Điều này có nghĩa là trong phân tích nhân tử tồn tại hai nhân tử:

$$
(x-a-b\mathrm{i})(x-a+b\mathrm{i})=x^2-2ax+a^2+b^2
$$

Khi nhân hai nhân tử này với nhau, mọi hệ số đều trở thành số thực. Tam thức bậc hai hệ số thực ở vế phải của đẳng thức này chia hết đa thức ban đầu.

Vậy trong đẳng thức của định lý cơ bản của đại số, chia đồng thời hai vế cho tam thức bậc hai này, vẫn thu được một đẳng thức của đa thức hệ số thực. Lặp lại thao tác này với đẳng thức mới; khi bậc giảm dần, sau hữu hạn lần sẽ không còn nghiệm ảo.

Do đó bội số của mỗi cặp nghiệm ảo liên hợp bằng nhau. Chứng minh hoàn tất.

Sau đây là các hệ quả của định lý nghiệm ảo xuất hiện thành cặp:

-   Đa thức hệ số thực bậc lẻ có ít nhất một nghiệm thực, và tổng số nghiệm thực là số lẻ.
-   Đa thức hệ số thực bậc chẵn có thể không có nghiệm thực, và tổng số nghiệm thực là số chẵn.

Gọi tam thức bậc hai nói trên $x^2-2ax+a^2+b^2=x^2+px+q$ là nhân tử bất khả quy bậc hai hệ số thực. "Bất khả quy" nghĩa là không thể phân tích tiếp trong phạm vi số thực.

Định lý: mọi đa thức hệ số thực nhất định là tích của các nhân tử bất khả quy hệ số thực bậc một hoặc bậc hai.

Chứng minh:

Mỗi khi đa thức hệ số thực có một nghiệm thực $c$, sẽ có một nhân tử hệ số thực $x-c$ tương ứng; mỗi khi có một cặp nghiệm ảo $a\pm b\mathrm{i}$, sẽ có một nhân tử hệ số thực $x^2-2ax+a^2+b^2$ tương ứng.

Vì vậy, chỉ cần dùng định lý nghiệm ảo xuất hiện thành cặp để ghép cặp trong phân tích theo định lý cơ bản của đại số ban đầu là chứng minh xong.

Theo định lý nghiệm ảo xuất hiện thành cặp, một đa thức hệ số thực $f(x)=a_nx^n+a_{n-1}x^{n-1}+\ldots+a_0$ nhất định có thể phân tích duy nhất thành:

$$
f(x)=a_n{(x-x_1)}^{k_1}{(x-x_2)}^{k_2}\ldots{(x-x_t)}^{k_t}{(x^2+p_1x+q_1)}^{l_1}{(x^2+p_2x+q_2)}^{l_2}\ldots{(x^2+p_sx+q_s)}^{l_s}
$$

trong đó mọi hệ số đều là số thực, và $k_1+k_2+\ldots+k_t+2(l_1+l_2+\ldots+l_s)=n$.

<span id="thuật-toán-lin-shie"></span>

## Thuật toán Lin Shie

<span id="giới-thiệu"></span>

### Giới thiệu

Làm thế nào để thực hiện phân tích theo định lý cơ bản của đại số cho đa thức hệ số thực? Nếu mở rộng trường số sang số phức thì việc này sẽ phức tạp.

Nếu chỉ phân tích trong phạm vi số thực, khi bậc lớn hơn $2$, luôn tồn tại một nhân tử tam thức bậc hai hệ số thực.

Lý do là: nếu đa thức có nghiệm ảo, chỉ cần ghép trực tiếp một cặp nghiệm ảo liên hợp. Nếu đa thức chỉ có nghiệm thực, lấy hai nhân tử bậc một bất kỳ tương ứng với hai nghiệm thực và nhân chúng lại, cũng thu được một tam thức bậc hai hệ số thực.

Sau khi tìm được nhân tử tam thức bậc hai, việc giải nghiệm thực hoặc nghiệm phức từ phương trình bậc hai là trực tiếp. Vì vậy có phương pháp tính nghiệm phức của phương trình bằng cách lần lượt **tìm ra một nhân tử bậc hai**; phương pháp này tránh được các phép tính với số phức.

Vào tháng 8 năm 1940, tháng 8 năm 1943 và tháng 7 năm 1947, Lin Shie lần lượt chính thức công bố ba bài báo về phương pháp tính nghiệm phức của phương trình bậc cao trên tạp chí *Mathematical Physics* do MIT xuất bản[^note1], mỗi lần đều có cải tiến.

Ngày nay phương pháp này vẫn được dùng để tính nhanh trong máy tính hiện đại; nguyên lý của các chương trình tìm nghiệm đa thức trong các gói phần mềm máy tính, chẳng hạn MATLAB, cũng dựa trên thuật toán này.

<span id="quá-trình"></span>

### Quá trình

Muốn tìm một nhân tử tam thức bậc hai, cần phân tích đa thức thành:

$$
f(x)=(x^2+p_1x+q_1)g(x)
$$

Vì không thể tìm ngay nhân tử tam thức bậc hai, theo ý tưởng giải lặp, với giá trị ban đầu có:

$$
f(x)=(x^2+px+q)g(x)+rx+s
$$

sẽ sinh ra một đa thức bậc một làm số dư. Chỉ cần số dư đủ nhỏ, có thể gần đúng tìm được nhân tử cần tìm.

Nghiệm cuối cùng được kỳ vọng là giá trị ban đầu cộng thêm một hiệu chỉnh độ lệch:

$$
p_1=p+dp
$$

$$
q_1=q+dq
$$

Hai số $(r, s)$ trong số dư do các hệ số cho trước $(p, q)$ của đa thức chia quyết định. Có quan hệ đạo hàm riêng:

$$
dr=\frac{\partial r}{\partial p}dp+\frac{\partial r}{\partial q}dq
$$

$$
ds=\frac{\partial s}{\partial p}dp+\frac{\partial s}{\partial q}dq
$$

Trong đẳng thức ban đầu, đa thức bị chia $f(x)$ đã cho sẵn; thương $g(x)$ và số dư $rx+s$ thay đổi theo đa thức chia $x^2+px+q$. Do đó có quan hệ đạo hàm riêng

$$
0=xg(x)+\frac{\partial g(x)}{\partial p}(x^2+px+q)+\frac{\partial r}{\partial p}x+\frac{\partial s}{\partial p}
$$

$$
0=g(x)+\frac{\partial g(x)}{\partial q}(x^2+px+q)+\frac{\partial r}{\partial q}x+\frac{\partial s}{\partial q}
$$

Đạo hàm riêng chỉ là một giá trị số, không phụ thuộc vào biến $x$. Do đó có quan hệ chia hết

$$
xg(x)=-\frac{\partial g(x)}{\partial p}(x^2+px+q)-\frac{\partial r}{\partial p}x-\frac{\partial s}{\partial p}
$$

$$
g(x)=-\frac{\partial g(x)}{\partial q}(x^2+px+q)-\frac{\partial r}{\partial q}x-\frac{\partial s}{\partial q}
$$

Kết luận thu được là: các đạo hàm riêng cần tìm chính là số dư khi tiếp tục chia thương. Phép chia đa thức cho tam thức bậc hai đã cho có thể tính trực tiếp. Từ đó tìm được bốn đạo hàm riêng.

Cần để $s$ và $r$ cộng với các độ lệch $ds$ và $dr$ thành $0$, tức $ds$ và $dr$ là các số đối của $s$ và $r$. Vì vậy cần giải hệ phương trình:

$$
-\frac{\partial r}{\partial p}dp-\frac{\partial r}{\partial q}dq=r
$$

$$
-\frac{\partial s}{\partial p}dp-\frac{\partial s}{\partial q}dq=s
$$

Giải hệ phương trình trên sẽ thu được các độ lệch $dp$ và $dq$ tương ứng với $p$ và $q$; có thể giải trực tiếp bằng định thức cấp hai.

<span id="cài-đặt"></span>

### Cài đặt

```C
// a là đa thức ban đầu, n là bậc của đa thức, p là hệ số bậc một cần tìm, q là hằng số cần tìm
void Shie(double a[], int n, double *p, double *q) {
  // mảng b là thương khi chia đa thức a cho tam thức bậc hai hiện tại của vòng lặp
  memset(b, 0, sizeof(b));
  // mảng c là thương khi nhân đa thức b với x bình phương rồi chia cho tam thức bậc hai hiện tại của vòng lặp
  memset(c, 0, sizeof(c));
  *p = 0;
  *q = 0;
  double dp = 1;
  double dq = 1;
  while (dp > eps || dp < -eps || dq > eps || dq < -eps)  // eps tự đặt
  {
    double p0 = p;
    double q0 = q;
    b[n - 2] = a[n];
    c[n - 2] = b[n - 2];
    b[n - 3] = a[n - 1] - p0 * b[n - 2];
    c[n - 3] = b[n - 3] - p0 * b[n - 2];
    int j;
    for (j = n - 4; j >= 0; j--) {
      b[j] = a[j + 2] - p0 * b[j + 1] - q0 * b[j + 2];
      c[j] = b[j] - p0 * c[j + 1] - q0 * c[j + 2];
    }
    double r = a[1] - p0 * b[0] - q0 * b[1];
    double s = a[0] - q0 * b[0];
    double rp = c[1];
    double sp = b[0] - q0 * c[2];
    double rq = c[0];
    double sq = -q0 * c[1];
    dp = (rp * s - r * sp) / (rp * sq - rq * sp);
    dq = (r * sq - rq * s) / (rp * sq - rq * sp);
    *p += dp;
    *q += dq;
  }
}
```

<span id="tài-liệu-tham-khảo-và-ghi-chú"></span>

## Tài liệu tham khảo và ghi chú

[^note1]: [Lin Shie. Về ứng dụng của phương pháp tách nhân tử để giải nghiệm của phương trình đặc trưng bậc cao. Advances in Mathematics, 1963(03):207-217.](https://cnki.net/kcms/detail/detail.aspx?filename=SXJZ196303000&dbcode=CJFD&dbname=CJFD1979)
