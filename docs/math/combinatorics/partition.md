Phân hoạch: biểu diễn số tự nhiên $n$ thành tổng các số nguyên dương không tăng.

$$
n=r_1+r_2+\ldots+r_k \quad r_1 \ge r_2 \ge \ldots \ge r_k \ge 1
$$

Mỗi số nguyên dương trong tổng được gọi là một phần.

Số phân hoạch: $p_n$, là số cách phân hoạch số tự nhiên $n$.

Các số phân hoạch bắt đầu từ $0$:

| n     | 0 | 1 | 2 | 3 | 4 | 5 | 6  | 7  | 8  |
| ----- | - | - | - | - | - | - | -- | -- | -- |
| $p_n$ | 1 | 1 | 2 | 3 | 5 | 7 | 11 | 15 | 22 |

<span id="k-&#x90E8;&#x5206;&#x62C6;&#x6570;"></span>
## Số phân hoạch thành $k$ phần

Phân hoạch chia $n$ thành đúng $k$ phần được gọi là phân hoạch $k$ phần, kí hiệu là $p(n,k)$.

Rõ ràng số phân hoạch $k$ phần $p(n,k)$ cũng là số nghiệm của phương trình sau:

$$
n-k=y_1+y_2+\ldots+y_k\quad y_1\ge y_2\ge\ldots\ge y_k\ge 0
$$

Nếu phương trình này có đúng $j$ phần khác $0$, thì có đúng $p(n-k,j)$ nghiệm. Vì vậy:

$$
p(n,k)=\sum_{j=0}^k p(n-k,j)
$$

Lấy hiệu hai công thức tổng kề nhau, ta được:

$$
p(n,k)=p(n-1,k-1)+p(n-k,k)
$$

Nếu lập bảng, giá trị trong mỗi ô bằng giá trị ở góc trái trên cộng với các giá trị trong cùng cột phía trên nó, lấy đúng bằng số thứ tự cột của ô đó.

| k        | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| -------- | - | - | - | - | - | - | - | - | - |
| $p(0,k)$ | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| $p(1,k)$ | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| $p(2,k)$ | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| $p(3,k)$ | 0 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| $p(4,k)$ | 0 | 1 | 2 | 1 | 1 | 0 | 0 | 0 | 0 |
| $p(5,k)$ | 0 | 1 | 2 | 2 | 1 | 1 | 0 | 0 | 0 |
| $p(6,k)$ | 0 | 1 | 3 | 3 | 2 | 1 | 1 | 0 | 0 |
| $p(7,k)$ | 0 | 1 | 3 | 4 | 3 | 2 | 1 | 1 | 0 |
| $p(8,k)$ | 0 | 1 | 4 | 5 | 5 | 3 | 2 | 1 | 1 |

<span id="&#x4F8B;&#x9898;"></span>
### Ví dụ

???+ note "Tính số phân hoạch thành k phần"
    Tính số phân hoạch $k$ phần $p(n,k)$. Có nhiều bộ dữ liệu vào, trong đó cận trên của $n$ là $10000$, cận trên của $k$ là $1000$, lấy kết quả modulo $1000007$.
    
    Quan sát bảng và công thức truy hồi, cập nhật theo cột sẽ thuận lợi hơn cho việc lưu trữ. Chương trình có thể viết như sau:
    
    ```cpp
    #include <cstdio>
    #include <cstring>
    
    int p[10005][1005]; /* So cach phan hoach so tu nhien n thanh k phan */
    
    int main() {
      int n, k;
      while (~scanf("%d%d", &n, &k)) {
        memset(p, 0, sizeof(p));
        p[0][0] = 1;
        int i;
        for (i = 1; i <= n; ++i) {
          int j;
          for (j = 1; j <= k; ++j) {
            if (i - j >= 0) /* Moi phan trong p[i-j][j] deu lon hon 1 */
            {
              p[i][j] = (p[i - j][j] + p[i - 1][j - 1]) %
                        1000007; /* p[i-1][j-1] co it nhat mot phan bang 1. */
            }
          }
        }
        printf("%d\n", p[n][k]);
      }
    }
    ```

<span id="&#x751F;&#x6210;&#x51FD;&#x6570;"></span>
### Hàm sinh

Từ công thức tổng cấp số nhân, ta có:

$$
\frac{1}{1-x^k}=1+x^k+x^{2k}+x^{3k}+\ldots
$$

$$
1+p_1 x+p_2 x^2+p_3 x^3+\ldots=\frac{1}{1-x}  \frac{1}{1-x^2}  \frac{1}{1-x^3}\ldots
$$

Với số phân hoạch $k$ phần, hàm sinh phức tạp hơn một chút. Cụ thể:

$$
\sum_{n,k=0}^\infty {p(n,k) x^n y^k }=\frac{1}{1-xy}  \frac{1}{1-x^2 y}  \frac{1}{1-x^3 y}\ldots
$$

<span id="ferrers-&#x56FE;"></span>
### Biểu đồ Ferrers

Biểu đồ Ferrers: biểu diễn mỗi phần của một phân hoạch bằng một hàng gồm các điểm. Số điểm trong hàng bằng kích thước của phần đó.

Theo định nghĩa phân hoạch, các hàng khác nhau trong biểu đồ Ferrers được xếp theo thứ tự giảm dần; hàng dài nhất nằm trên cùng.

Ví dụ: biểu đồ Ferrers của phân hoạch $12=5+4+2+1$.

![](./images/ferrers.jpg)

Lật một biểu đồ Ferrers qua đường chéo sẽ thu được một biểu đồ Ferrers mới, gọi là liên hợp của biểu đồ ban đầu; phân hoạch mới gọi là liên hợp của phân hoạch ban đầu. Rõ ràng quan hệ liên hợp là đối xứng.

Ví dụ, liên hợp của phân hoạch $12=5+4+2+1$ ở trên là phân hoạch $12=4+3+2+2+1$.

Số phân hoạch có phần lớn nhất bằng $k$: số phân hoạch của số tự nhiên $n$ mà phần lớn nhất là $k$.

Từ định nghĩa liên hợp, ta có kết luận hiển nhiên:

Số phân hoạch có phần lớn nhất bằng $k$ bằng số phân hoạch $k$ phần, đều là $p(n,k)$.

<span id="&#x4E92;&#x5F02;&#x5206;&#x62C6;&#x6570;"></span>
## Số phân hoạch thành các phần phân biệt

Số phân hoạch phân biệt: $pd_n$, là số cách phân hoạch số tự nhiên $n$ sao cho mọi phần đôi một khác nhau (Different).

| n      | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| ------ | - | - | - | - | - | - | - | - | - |
| $pd_n$ | 1 | 1 | 1 | 2 | 2 | 3 | 4 | 5 | 6 |

Tương tự, định nghĩa số phân hoạch phân biệt $k$ phần $pd(n,k)$ là số phân hoạch phân biệt tách ra đúng $k$ phần; đó là số nghiệm của phương trình:

$$
n=r_1+r_2+\ldots+r_k\quad r_1>r_2>\ldots>r_k\ge 1
$$

Hoàn toàn tương tự, nó cũng là số nghiệm của phương trình:

$$
n-k=y_1+y_2+\ldots+y_k\quad y_1>y_2>\ldots>y_k\ge 0
$$

Điểm khác với phần trên là do các phần phân biệt, trong phương trình mới có nhiều nhất một phần bằng không. Kết luận không đổi: nếu có đúng $j$ phần khác $0$ thì có đúng $pd(n-k,j)$ nghiệm; ở đây $j$ chỉ có thể là $k$ hoặc $k-1$. Vì vậy trực tiếp có truy hồi:

$$
pd(n,k)=pd(n-k,k-1)+pd(n-k,k)
$$

Cũng có thể lập bảng giống như với số tổ hợp. Mỗi ô bằng tổng các giá trị trong cột trước, phía trên ô đó, lấy đúng bằng số thứ tự cột, cộng với các giá trị trong cùng cột phía trên ô đó, cũng lấy đúng bằng số thứ tự cột.

| k         | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| --------- | - | - | - | - | - | - | - | - | - |
| $pd(0,k)$ | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| $pd(1,k)$ | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| $pd(2,k)$ | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| $pd(3,k)$ | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| $pd(4,k)$ | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| $pd(5,k)$ | 0 | 1 | 2 | 0 | 0 | 0 | 0 | 0 | 0 |
| $pd(6,k)$ | 0 | 1 | 2 | 1 | 0 | 0 | 0 | 0 | 0 |
| $pd(7,k)$ | 0 | 1 | 3 | 1 | 0 | 0 | 0 | 0 | 0 |
| $pd(8,k)$ | 0 | 1 | 3 | 2 | 0 | 0 | 0 | 0 | 0 |

<span id="&#x4F8B;&#x9898;_1"></span>
### Ví dụ

???+ note "Tính số phân hoạch phân biệt"
    Tính số phân hoạch phân biệt $pd_n$. Có nhiều bộ dữ liệu vào, trong đó cận trên của $n$ là $50000$, lấy kết quả modulo $1000007$.
    
    Quan sát bảng và công thức truy hồi, cập nhật theo cột sẽ thuận lợi hơn cho việc lưu trữ. Trong mã, chỉ giữ hai mục kề nhau để giảm không gian.
    
    ```cpp
    #include <cstdio>
    #include <cstring>
    
    int pd[50005][2]; /* So cach phan hoach n thanh k phan phan biet */
    
    int main() {
      int n;
      while (~scanf("%d", &n)) {
        memset(pd, 0, sizeof(pd));
        pd[0][0] = 1;
        int ans = 0;
        int j;
        for (j = 1; j < 350; ++j) {
          int i;
          for (i = 0; i < 350; ++i) {
            pd[i][j & 1] = 0; /* pd[i][j] chi lien quan den pd[][j] va pd[][j-1] */
          }
          for (i = 0; i <= n; ++i) {
            if (i - j >= 0) /* Moi phan trong pd[i-j][j] deu lon hon 1 */
            {
              pd[i][j & 1] = (pd[i - j][j & 1] + pd[i - j][(j - 1) & 1]) %
                             1000007; /* pd[i-j][j-1] co it nhat mot phan bang 1. */
            }
          }
          ans = (ans + pd[n][j & 1]) % 1000007;
        }
        printf("%d\n", ans);
      }
    }
    ```

<span id="&#x5947;&#x5206;&#x62C6;&#x6570;"></span>
### Số phân hoạch lẻ

Số phân hoạch lẻ: $po_n$, là số cách phân hoạch số tự nhiên $n$ sao cho mọi phần đều là số lẻ (Odd).

Có một đẳng thức hiển nhiên:

$$
\prod_{i=1}^\infty (1+x^i ) =\frac{\prod_{i=1}^\infty (1-x^{2i} ) }{\prod_{i=1}^\infty (1-x^i ) }=\prod_{i=1}^\infty \frac{1}{1-x^{2i-1} }
$$

Vế trái là hàm sinh của số phân hoạch phân biệt, còn vế phải là hàm sinh của số phân hoạch lẻ. Hệ số tương ứng của hai vế bằng nhau, do đó số phân hoạch lẻ bằng số phân hoạch phân biệt:

$$
po_n=pd_n
$$

Nhưng rõ ràng số phân hoạch lẻ $k$ phần và số phân hoạch phân biệt $k$ phần không phải cùng một khái niệm, nên không liệt kê ở đây.

Giới thiệu thêm hai khái niệm:

Số phân hoạch phân biệt có số phần chẵn: $pde_n$, là số cách phân hoạch phân biệt của số tự nhiên $n$ với số phần là chẵn (Even).

Số phân hoạch phân biệt có số phần lẻ: $pdo_n$, là số cách phân hoạch phân biệt của số tự nhiên $n$ với số phần là lẻ (Odd).

Do đó:

$$
pd_n=pde_n+pdo_n
$$

Cũng có các khái niệm $k$ phần tương ứng. Vì chúng quá phức tạp nên không liệt kê ở đây.

<span id="&#x4E94;&#x8FB9;&#x5F62;&#x6570;&#x5B9A;&#x7406;"></span>
## Định lý số ngũ giác

Xét riêng phần mẫu số trong hàm sinh của số phân hoạch:

$$
\prod_{i=1}^\infty (1-x^i ) 
$$

Khi khai triển phần này, ta có thể liên hệ với phân hoạch phân biệt và tính chẵn lẻ của số phần được tách ra trong phân hoạch phân biệt.

Cụ thể, phân hoạch phân biệt có số phần chẵn được đếm với dấu dương trong khai triển, còn phân hoạch phân biệt có số phần lẻ được đếm với dấu âm. Vì vậy hệ số của mỗi hạng trong khai triển là hiệu của hai số cách đó:

$$
\sum_{i=0}^\infty ({pde}_n-{pdo}_n ) x^n =\prod_{i=1}^\infty (1-x^i ) 
$$

Tiếp theo, ta chỉ ra rằng trong đa số trường hợp hai số cách trên bằng nhau, nên hệ số trong khai triển là $0$; chỉ tại một số ít vị trí, hai số cách chênh nhau $1$ hoặc $-1$.

Ở đây có thể dùng cách xây dựng một song ánh.

Vẽ biểu đồ Ferrers của mỗi phân hoạch phân biệt. Hàng cuối cùng gọi là đáy của biểu đồ, số điểm trên đáy kí hiệu là $b$ (Bottom); đoạn chéo dài nhất góc $45$ độ nối điểm cuối cùng của hàng trên cùng với một điểm trong biểu đồ gọi là sườn, số điểm trên sườn kí hiệu là $s$ (Slide).

![](./images/bottom_slide.jpg)

Để xây dựng song ánh giữa các phân hoạch phân biệt có số phần chẵn và có số phần lẻ, ta cần định nghĩa phép biến đổi sao cho vẫn giữ điều kiện các phần phân biệt, đồng thời số hàng thay đổi đúng $1$:

Biến đổi A: khi $b \le s$, chuyển đáy sang bên phải để trở thành một sườn mới.

Biến đổi B: khi $b > s$, chuyển sườn xuống dưới để trở thành một đáy mới.

Với hầu hết các phân hoạch phân biệt của hầu hết $n$, đúng một trong hai biến đổi trên có thể thực hiện, từ đó tạo được song ánh giữa hai loại phân hoạch. Hai phần đã được ghép song ánh có số lượng bằng nhau, nên hệ số của hạng $n$ trong khai triển khi đó bằng $0$.

Tuy nhiên với một số $n$, tồn tại đúng một phân hoạch phân biệt không thể thực hiện các biến đổi trên.

-   Trường hợp 1: $b=s$ và đáy với sườn có một điểm chung, khi đó biến đổi A không thực hiện được. Lúc này

$$
n=s+(s+1)+\ldots+(s+s-1)=\frac{s(3s-1)}{2}
$$

Hạng thứ $n$ trong khai triển phụ thuộc vào tính chẵn lẻ của số phần, bằng $(-1)^s x^n$.

-   Trường hợp 2: $b=s+1$ và đáy với sườn có một điểm chung, khi đó biến đổi B không thực hiện được. Lúc này

$$
n=(s+1)+(s+2)+\ldots+(s+s)=\frac{s(3s+1)}{2}
$$

Hạng thứ $n$ trong khai triển là $(-1)^s x^n$.

Thay $s$ trong công thức trên bằng $-s$, ta được $n=\frac{s(3s-1)}{2}$, trong đó $s$ là số nguyên âm, và hạng thứ $n$ trong khai triển vẫn là $(-1)^s x^n$.

Vì hai trường hợp không xảy ra đồng thời với cùng một $n$, ta có thể gộp hai điều kiện lại: $n$ cần thỏa mãn

$$
\exists k\in\mathbb{Z},n=\frac{k(3k-1)}{2}
$$

Đến đây, ta đã chứng minh:

$$
(1-x)(1-x^2 )(1-x^3 )\ldots=\sum_{k=-\infty}^{+\infty} (-1)^k x^{\frac{k(3k-1)}{2}} =\ldots+x^{26}-x^{15}+x^7-x^2+1-x+x^5-x^{12}+x^{22}-\ldots
$$

Nhắc lại: công thức này là nghịch đảo của hàm sinh số phân hoạch, vì vậy tích của nó với hàm sinh số phân hoạch bằng $1$. Sắp xếp lại và so sánh hệ số hai vế, ta thu được công thức truy hồi cho dãy số phân hoạch.

$$
(1+p_1 x+p_2 x^2+p_3 x^3+\ldots)(1-x-x^2+x^5+x^7-x^{12}-x^{15}+x^{22}+x^{26}-\ldots)=1
$$

$$
p_n=p_{n-1}+p_{n-2}-p_{n-5}-p_{n-7}+\ldots
$$

Công thức truy hồi này có vô hạn hạng, nhưng nếu quy ước số phân hoạch của số âm là $0$ (số phân hoạch của $0$ đã được định nghĩa là $1$), thì nó rút gọn thành hữu hạn hạng.

<span id="&#x4F8B;&#x9898;_2"></span>
### Ví dụ

???+ note "Tính số phân hoạch"
    Tính số phân hoạch $p_n$. Có nhiều bộ dữ liệu vào, trong đó cận trên của $n$ là $50000$, lấy kết quả modulo $1000007$.
    
    Dùng phương pháp từ định lý số ngũ giác. Mã như sau:
    
    ```cpp
    #include <cstdio>
    
    long long a[100010];
    long long p[50005];
    
    int main() {
      p[0] = 1;
      p[1] = 1;
      p[2] = 2;
      int i;
      for (i = 1; i < 50005;
           i++) /* He so truy hoi 1,2,5,7,12,15,22,26... i*(3*i-1)/2, i*(3*i+1)/2 */
      {
        a[2 * i] = i * (i * 3 - 1) / 2; /* So ngu giac 1,5,12,22... i*(3*i-1)/2 */
        a[2 * i + 1] = i * (i * 3 + 1) / 2;
      }
      for (
          i = 3; i < 50005;
          i++) /* p[n]=p[n-1]+p[n-2]-p[n-5]-p[n-7]+p[12]+p[15]-...+p[n-i*[3i-1]/2]+p[n-i*[3i+1]/2] */
      {
        p[i] = 0;
        int j;
        for (j = 2; a[j] <= i; j++) /* Co the bi am, nen cong them 1000007 */
        {
          if (j & 2) {
            p[i] = (p[i] + p[i - a[j]] + 1000007) % 1000007;
          } else {
            p[i] = (p[i] - p[i - a[j]] + 1000007) % 1000007;
          }
        }
      }
      int n;
      while (~scanf("%d", &n)) {
        printf("%lld\n", p[n]);
      }
    }
    ```
