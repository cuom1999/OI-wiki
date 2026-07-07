author: hydingsy, Link-cute, Ir1d, greyqz, LuoshuiTianyi, odeinjul, xyf007, GoodCoder666, paigeman, shenshuaijie, oldoldtea

Kiến thức nền: [Giới thiệu phần quy hoạch động](./index.md).

<span id="mở-đầu"></span>
## Mở đầu

Trước khi nói cụ thể "DP ba lô" là gì, xét bài ví dụ sau:

???+ note "[「USACO07 DEC」Charm Bracelet](https://www.luogu.com.cn/problem/P2871)"
    Tóm tắt đề bài: có $n$ vật phẩm và một ba lô có sức chứa $W$. Mỗi vật phẩm có hai thuộc tính là trọng lượng $w_{i}$ và giá trị $v_{i}$. Cần chọn một số vật phẩm cho vào ba lô sao cho tổng giá trị các vật phẩm trong ba lô là lớn nhất, đồng thời tổng trọng lượng không vượt quá sức chứa của ba lô.

Trong ví dụ trên, mỗi vật phẩm chỉ có hai trạng thái có thể xảy ra (chọn hoặc không chọn), tương ứng với $0$ và $1$ trong hệ nhị phân, nên loại bài toán này được gọi là "bài toán ba lô 0-1".

<span id="ba-lô-0-1"></span>
## Ba lô 0-1

<span id="giải-thích"></span>
### Giải thích

Trong bài ví dụ, các dữ kiện đã biết gồm trọng lượng $w_{i}$ của vật phẩm thứ $i$, giá trị $v_{i}$ của nó, và tổng sức chứa $W$ của ba lô.

Đặt trạng thái DP $f_{i,j}$ là tổng giá trị lớn nhất có thể đạt được với một ba lô có sức chứa $j$ khi chỉ được xét $i$ vật phẩm đầu tiên.

Xét phép chuyển trạng thái. Giả sử mọi trạng thái của $i-1$ vật phẩm đầu tiên đã được xử lý xong. Với vật phẩm thứ $i$, nếu không cho nó vào ba lô thì sức chứa còn lại không đổi và tổng giá trị trong ba lô cũng không đổi, nên giá trị lớn nhất trong trường hợp này là $f_{i-1,j}$; nếu cho nó vào ba lô thì sức chứa còn lại giảm đi $w_{i}$ và tổng giá trị tăng thêm $v_{i}$, nên giá trị lớn nhất trong trường hợp này là $f_{i-1,j-w_{i}}+v_{i}$.

Từ đó suy ra phương trình chuyển trạng thái:

$$
f_{i,j}=\max(f_{i-1,j},f_{i-1,j-w_{i}}+v_{i})
$$

Nếu trực tiếp dùng mảng hai chiều để lưu trạng thái, chương trình có thể bị MLE. Có thể cân nhắc dùng mảng cuốn để tối ưu.

Vì $f_i$ chỉ chịu ảnh hưởng từ $f_{i-1}$, có thể bỏ chiều thứ nhất và dùng trực tiếp $f_{i}$ để biểu diễn giá trị lớn nhất khi đã xử lý đến vật phẩm hiện tại và sức chứa ba lô là $i$. Khi đó thu được phương trình sau:

$$
f_j=\max \left(f_j,f_{j-w_i}+v_i\right)
$$

**Cần ghi nhớ và hiểu thật rõ phương trình chuyển trạng thái này, vì phần lớn các phương trình chuyển của bài toán ba lô đều được suy ra dựa trên nó.**

<span id="cài-đặt"></span>
### Cài đặt

Còn một điểm cần lưu ý: dễ viết ra đoạn **mã lõi sai** như sau:

=== "C++"
    ```cpp
    for (int i = 1; i <= n; i++)
      for (int l = 0; l <= W - w[i]; l++)
        f[l + w[i]] = max(f[l] + v[i], f[l + w[i]]);
    // Rut gon tu f[i][l + w[i]] =
    // max(max(f[i - 1][l + w[i]], f[i - 1][l] + v[i]), f[i][l + w[i]]);
    ```

=== "Python"
    ```python
    for i in range(1, n + 1):
        for l in range(0, W - w[i] + 1):
            f[l + w[i]] = max(f[l] + v[i], f[l + w[i]])
    # Rut gon tu f[i][l + w[i]] =
    # max(max(f[i - 1][l + w[i]], f[i - 1][l] + v[i]), f[i][l + w[i]])
    ```

Đoạn mã này sai ở đâu? Sai ở thứ tự duyệt.

Quan sát kỹ đoạn mã sẽ thấy: với vật phẩm đang xử lý $i$ và trạng thái hiện tại $f_{i,j}$, khi $j\geqslant w_{i}$, $f_{i,j}$ sẽ bị ảnh hưởng bởi $f_{i,j-w_{i}}$. Điều này tương đương với việc vật phẩm $i$ có thể được cho vào ba lô nhiều lần, không đúng với đề bài. (Về bản chất, đây chính là cách giải cho bài toán ba lô đầy đủ.)

Để tránh tình huống này, có thể đổi thứ tự duyệt, duyệt từ $W$ xuống $w_{i}$. Khi đó lỗi trên sẽ không xuất hiện, vì $f_{i,j}$ luôn được cập nhật trước $f_{i,j-w_{i}}$.

Vì vậy, mã lõi đúng là:

=== "C++"
    ```cpp
    for (int i = 1; i <= n; i++)
      for (int l = W; l >= w[i]; l--) f[l] = max(f[l], f[l - w[i]] + v[i]);
    ```

=== "Python"
    ```python
    for i in range(1, n + 1):
        for l in range(W, w[i] - 1, -1):
            f[l] = max(f[l], f[l - w[i]] + v[i])
    ```

??? note "Mã cho bài ví dụ"
    ```cpp
    --8<-- "docs/dp/code/knapsack/knapsack_1.cpp"
    ```

<span id="ba-lô-đầy-đủ"></span>
## Ba lô đầy đủ

<span id="giải-thích_1"></span>
### Giải thích

Mô hình ba lô đầy đủ tương tự ba lô 0-1; điểm khác biệt so với ba lô 0-1 là mỗi loại vật phẩm có thể được chọn vô hạn lần, chứ không chỉ được chọn một lần.

Có thể mượn ý tưởng của ba lô 0-1 để định nghĩa trạng thái: đặt $f_{i,j}$ là giá trị lớn nhất có thể đạt được với ba lô có sức chứa $j$ khi chỉ được chọn trong $i$ loại vật phẩm đầu tiên.

Cần lưu ý rằng tuy định nghĩa giống ba lô 0-1, phương trình chuyển trạng thái của nó lại không giống ba lô 0-1.

<span id="quá-trình"></span>
### Quá trình

Trước hết có thể xét một cách làm ngây thơ: với vật phẩm thứ $i$, duyệt số lượng vật phẩm đó được chọn để chuyển trạng thái. Độ phức tạp thời gian của cách làm này là $O(n^3)$.

Phương trình chuyển trạng thái như sau:

$$
f_{i,j}=\max_{k=0}^{+\infty}(f_{i-1,j-k\times w_i}+v_i\times k)
$$

Xét một tối ưu đơn giản. Với $f_{i,j}$, chỉ cần chuyển từ $f_{i,j-w_i}$ là đủ. Vì vậy phương trình chuyển trạng thái là:

$$
f_{i,j}=\max(f_{i-1,j},f_{i,j-w_i}+v_i)
$$

Lý do là khi chuyển như vậy, $f_{i,j-w_i}$ đã từng được cập nhật từ $f_{i,j-2\times w_i}$, nên $f_{i,j-w_i}$ đã là kết quả tối ưu sau khi xét đầy đủ số lần chọn vật phẩm thứ $i$. Nói cách khác, quá trình duyệt trước đó được lặp lại thông qua tính chất cấu trúc con tối ưu cục bộ, từ đó tối ưu độ phức tạp của phép duyệt.

Giống ba lô 0-1, có thể bỏ chiều thứ nhất để tối ưu độ phức tạp bộ nhớ. Nếu đã hiểu cách tối ưu của ba lô 0-1, sẽ thấy vòng lặp sau khi nén phải duyệt xuôi (chính là "tối ưu sai" đã nhắc ở trên).

??? note "[Luogu P1616 - Thu hái thảo dược điên cuồng](https://www.luogu.com.cn/problem/P1616)"
    Tóm tắt đề bài: có $n$ loại vật phẩm và một ba lô có sức chứa $W$. Mỗi loại vật phẩm có hai thuộc tính là trọng lượng $w_{i}$ và giá trị $v_{i}$. Cần chọn một số vật phẩm cho vào ba lô sao cho tổng giá trị các vật phẩm trong ba lô là lớn nhất, đồng thời tổng trọng lượng không vượt quá sức chứa của ba lô.

??? note "Mã cho bài ví dụ"
    ```cpp
    --8<-- "docs/dp/code/knapsack/knapsack_2.cpp"
    ```

<span id="ba-lô-nhiều-vật-phẩm"></span>
## Ba lô nhiều vật phẩm

Ba lô nhiều vật phẩm cũng là một biến thể của ba lô 0-1. Điểm khác biệt so với ba lô 0-1 là mỗi loại vật phẩm có $k_i$ món, chứ không phải chỉ một món.

Một ý tưởng rất ngây thơ là: biến việc "mỗi loại vật phẩm được chọn $k_i$ lần" thành "có $k_i$ vật phẩm giống hệt nhau, mỗi vật phẩm được chọn một lần". Khi đó bài toán được chuyển thành mô hình ba lô 0-1, và có thể áp dụng phương pháp đã trình bày ở trên để giải. Phương trình chuyển trạng thái như sau:

$$
f_{i,j}=\max_{k=0}^{k_i}(f_{i-1,j-k\times w_i}+v_i\times k)
$$

Độ phức tạp thời gian là $O(W\sum_{i=1}^nk_i)$.

??? note "Mã lõi"
    ```cpp
    for (int i = 1; i <= n; i++) {
      for (int weight = W; weight >= w[i]; weight--) {
        // Duyet them mot tang so luong vat pham
        for (int k = 1; k * w[i] <= weight && k <= cnt[i]; k++) {
          dp[weight] = max(dp[weight], dp[weight - k * w[i]] + k * v[i]);
        }
      }
    }
    ```

<span id="tối-ưu-bằng-phân-nhóm-nhị-phân"></span>
### Tối ưu bằng phân nhóm nhị phân

Xét tối ưu. Vẫn xét việc chuyển ba lô nhiều vật phẩm thành mô hình ba lô 0-1 để giải.

<span id="giải-thích_2"></span>
### Giải thích

Phần $O(nW)$ trong độ phức tạp không thể tối ưu thêm, nên chỉ có thể bắt đầu từ phần $O(\sum k_i)$. Để tiện trình bày, dùng $A_{i,j}$ biểu diễn vật phẩm thứ $j$ được tách ra từ loại vật phẩm thứ $i$.

Trong cách làm ngây thơ, với $\forall j\le k_i$, mọi $A_{i,j}$ đều biểu diễn cùng một loại vật phẩm. Vì vậy nguyên nhân chính khiến hiệu suất thấp là có rất nhiều việc bị lặp lại. Ví dụ, xét hai trường hợp "đồng thời chọn $A_{i,1},A_{i,2}$" và "đồng thời chọn $A_{i,2},A_{i,3}$"; hai trường hợp này hoàn toàn tương đương. Kiểu công việc trùng lặp như vậy xuất hiện rất nhiều lần. Do đó, tối ưu cách tách vật phẩm trở thành điểm then chốt để giải quyết bài toán.

<span id="quá-trình_1"></span>
### Quá trình

Có thể dùng cách "phân nhóm nhị phân" để việc tách vật phẩm đẹp hơn.

Cụ thể, cho $A_{i,j}\left(j\in\left[0,\lfloor \log_2(k_i+1)\rfloor-1\right]\right)$ lần lượt biểu diễn các vật phẩm lớn được "gói" từ $2^{j}$ vật phẩm đơn lẻ. Đặc biệt, nếu $k_i+1$ không phải là lũy thừa nguyên của $2$, cần thêm vào cuối một vật phẩm lớn được "gói" từ $k_i-2^{\lfloor \log_2(k_i+1)\rfloor-1}$ vật phẩm đơn lẻ để bù đủ.

Một vài ví dụ:

-   $6=1+2+3$
-   $8=1+2+4+1$
-   $18=1+2+4+8+3$
-   $31=1+2+4+8+16$

Với cách tách trên, có thể biểu diễn mọi cách chọn tương đương với số lượng vật phẩm $\le k_i$. Sau khi tách từng loại vật phẩm theo cách trên, chỉ cần dùng phương pháp ba lô 0-1 để giải.

Độ phức tạp thời gian là $O(W\sum_{i=1}^n\log_2k_i)$.

<span id="cài-đặt_1"></span>
### Cài đặt

??? note "Mã phân nhóm nhị phân"
    === "C++"
        ```cpp
        index = 0;
        for (int i = 1; i <= m; i++) {
          int c = 1, p, h, k;
          cin >> p >> h >> k;
          while (k > c) {
            k -= c;
            list[++index].w = c * p;
            list[index].v = c * h;
            c *= 2;
          }
          list[++index].w = p * k;
          list[index].v = h * k;
        }
        ```
    
    === "Python"
        ```python
        index = 0
        for i in range(1, m + 1):
            c = 1
            p, h, k = map(int, input().split())
            while k > c:
                k -= c
                index += 1
                list[index].w = c * p
                list[index].v = c * h
                c *= 2
            index += 1
            list[index].w = p * k
            list[index].v = h * k
        ```

<span id="tối-ưu-bằng-hàng-đợi-đơn-điệu"></span>
### Tối ưu bằng hàng đợi đơn điệu

Xem [Tối ưu bằng hàng đợi đơn điệu/ngăn xếp đơn điệu](./opt/monotonic-queue-stack.md).

Bài tập: [Luogu P1776 - Sàng lọc bảo vật, NOI Guide 2010 Advanced (02)](https://www.luogu.com.cn/problem/P1776)

<span id="ba-lô-hỗn-hợp"></span>
## Ba lô hỗn hợp

Ba lô hỗn hợp là bài toán trộn ba loại ba lô ở trên: có vật phẩm chỉ được chọn một lần, có vật phẩm được chọn vô hạn lần, và có vật phẩm chỉ được chọn $k$ lần.

Dạng bài này thoạt nhìn khá đáng sợ, nhưng chỉ cần hiểu tư tưởng cốt lõi của các loại ba lô phía trên và ghép chúng lại là được. Dưới đây là mã giả:

```plain
với mỗi loại vật phẩm {
  nếu là ba lô 0-1
    áp dụng mã ba lô 0-1;
  ngược lại nếu là ba lô đầy đủ
    áp dụng mã ba lô đầy đủ;
  ngược lại nếu là ba lô nhiều vật phẩm
    áp dụng mã ba lô nhiều vật phẩm;
}
```

<span id="bài-ví-dụ"></span>
### Bài ví dụ

???+ note "[Luogu P1833 - Hoa anh đào](https://www.luogu.com.cn/problem/P1833)"
    Có $n$ loại cây hoa anh đào và tổng thời gian dài $T$. Có loại cây chỉ có thể ngắm một lần, có loại cây được ngắm nhiều nhất $A_{i}$ lần, và có loại cây có thể ngắm vô hạn lần. Mỗi cây hoa anh đào có một giá trị thẩm mỹ $C_{i}$. Tìm cách ngắm các cây trong thời gian $T$ sao cho tổng giá trị thẩm mỹ là cao nhất.

??? note "Mã lõi"
    ```cpp
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == 0) {  // Neu so luong khong gioi han, dung ma loi cua ba lo day du
        for (int weight = w[i]; weight <= W; weight++) {
          dp[weight] = max(dp[weight], dp[weight - w[i]] + v[i]);
        }
      } else {  // Vat pham huu han: dung ma loi cua ba lo nhieu vat pham; cung xu ly duoc ba lo 0-1
        for (int weight = W; weight >= w[i]; weight--) {
          for (int k = 1; k * w[i] <= weight && k <= cnt[i]; k++) {
            dp[weight] = max(dp[weight], dp[weight - k * w[i]] + k * v[i]);
          }
        }
      }
    }
    ```

Bài tập: [HDU 5410 CRB and His Birthday](https://acm.hdu.edu.cn/showproblem.php?pid=5410)

<span id="ba-lô-với-chi-phí-hai-chiều"></span>
## Ba lô với chi phí hai chiều

???+ note "[Luogu P1855 - Vắt kiệt kkksc03](https://www.luogu.com.cn/problem/P1855)"
    Có $n$ nhiệm vụ cần hoàn thành. Hoàn thành nhiệm vụ thứ $i$ tốn $t_i$ phút và phát sinh chi phí $c_i$ đồng.
    
    Hiện có $T$ phút và $W$ đồng để xử lý các nhiệm vụ này. Hỏi tối đa có thể hoàn thành bao nhiêu nhiệm vụ.

Bài này là bài toán ba lô 0-1, nhưng điểm khác là chọn một vật phẩm sẽ tiêu hao hai loại giá trị (kinh phí và thời gian). Chỉ cần tăng thêm một chiều trong trạng thái để lưu loại giá trị thứ hai.

Lúc này cần lưu ý rằng mở thêm một chiều để lưu số thứ tự vật phẩm là không phù hợp, vì dễ bị MLE.

<span id="cài-đặt_2"></span>
### Cài đặt

=== "C++"
    ```cpp
    for (int k = 1; k <= n; k++)
      for (int i = m; i >= mi; i--)    // Duyet mot tang theo kinh phi
        for (int j = t; j >= ti; j--)  // Duyet mot tang theo thoi gian
          dp[i][j] = max(dp[i][j], dp[i - mi][j - ti] + 1);
    ```

=== "Python"
    ```python
    for k in range(1, n + 1):
        for i in range(m, mi - 1, -1):  # Duyet mot tang theo kinh phi
            for j in range(t, ti - 1, -1):  # Duyet mot tang theo thoi gian
                dp[i][j] = max(dp[i][j], dp[i - mi][j - ti] + 1)
    ```

<span id="ba-lô-theo-nhóm"></span>
## Ba lô theo nhóm

???+ note "[Luogu P1757 - Ba lô phân nhóm vươn tới trời cao](https://www.luogu.com.cn/problem/P1757)"
    Có $n$ vật phẩm và một ba lô có kích thước $m$. Giá trị của vật phẩm thứ $i$ là $w_i$, thể tích là $v_i$. Đồng thời, mỗi vật phẩm thuộc một nhóm, và trong cùng một nhóm chỉ được chọn nhiều nhất một vật phẩm. Tìm tổng giá trị lớn nhất của các vật phẩm mà ba lô có thể chứa.

Với dạng bài này nên nghĩ thế nào? Bài toán đã chuyển từ "chọn một vật phẩm trong tất cả vật phẩm" thành "chọn một vật phẩm trong nhóm hiện tại", nên chỉ cần thực hiện một lần ba lô 0-1 cho mỗi nhóm.

Nói thêm về cách lưu trữ. Có thể dùng $t_{k,i}$ để biểu diễn số thứ tự của vật phẩm thứ $i$ trong nhóm thứ $k$, rồi dùng $\mathit{cnt}_k$ để biểu diễn số vật phẩm trong nhóm thứ $k$.

<span id="cài-đặt_3"></span>
### Cài đặt

=== "C++"
    ```cpp
    for (int k = 1; k <= ts; k++)          // Duyet tung nhom
      for (int i = m; i >= 0; i--)         // Duyet suc chua ba lo
        for (int j = 1; j <= cnt[k]; j++)  // Duyet tung vat pham trong nhom nay
          if (i >= w[t[k][j]])             // Suc chua ba lo du
            dp[i] = max(dp[i],
                        dp[i - w[t[k][j]]] + c[t[k][j]]);  // Chuyen trang thai nhu ba lo 0-1
    ```

=== "Python"
    ```python
    for k in range(1, ts + 1):  # Duyet tung nhom
        for i in range(m, -1, -1):  # Duyet suc chua ba lo
            for j in range(1, cnt[k] + 1):  # Duyet tung vat pham trong nhom nay
                if i >= w[t[k][j]]:  # Suc chua ba lo du
                    dp[i] = max(
                        dp[i], dp[i - w[t[k][j]]] + c[t[k][j]]
                    )  # Chuyen trang thai nhu ba lo 0-1
    ```

Lưu ý: **tuyệt đối không được nhầm thứ tự vòng lặp**, như vậy mới bảo đảm tính đúng đắn.

<span id="ba-lô-có-phụ-thuộc"></span>
## Ba lô có phụ thuộc

???+ note "[Luogu P1064 - Phương án ngân sách của Jinming](https://www.luogu.com.cn/problem/P1064)"
    Jinming có $n$ đồng, muốn mua $m$ vật phẩm. Vật phẩm thứ $i$ có giá $v_i$ và độ quan trọng $p_i$. Một số vật phẩm là phụ kiện phụ thuộc vào một vật phẩm chính nào đó; muốn mua vật phẩm đó thì bắt buộc phải mua vật phẩm chính của nó.
    
    Mục tiêu là tối đa hóa tổng $v_i \times p_i$ của tất cả vật phẩm được mua.

Xét bằng cách chia trường hợp. Với một vật phẩm chính và một số phụ kiện của nó, có các khả năng sau: chỉ mua vật phẩm chính, hoặc mua vật phẩm chính + một số phụ kiện. Vì trong các khả năng này chỉ được chọn một, có thể xem đây là ba lô theo nhóm.

Nếu là một tập các cây đa phân, cần tính tập của các nút con trước, rồi cuối cùng mới tính tập của nút cha.

<span id="ba-lô-với-vật-phẩm-tổng-quát"></span>
## Ba lô với vật phẩm tổng quát

Loại ba lô này không có chi phí và giá trị cố định; giá trị của nó phụ thuộc vào lượng chi phí được phân bổ cho nó. Trong một bài toán ba lô có sức chứa $V$, khi phân bổ cho nó chi phí $v_i$, giá trị nhận được là $h\left(v_i\right)$. Lúc này, chỉ cần thay giá trị cố định bằng tham chiếu đến hàm.

<span id="linh-tinh"></span>
## Linh tinh

<span id="tối-ưu-nhỏ"></span>
### Tối ưu nhỏ

Theo nguyên lý tham lam, khi chi phí bằng nhau thì chỉ cần giữ vật phẩm có giá trị cao nhất; khi giá trị cố định thì chỉ cần giữ vật phẩm có chi phí thấp nhất; khi có hai vật phẩm $i,j$ mà giá trị của $i$ lớn hơn giá trị của $j$ và chi phí của $i$ nhỏ hơn chi phí của $j$, chỉ cần giữ $i$.

<span id="biến-thể-của-bài-toán-ba-lô"></span>
### Biến thể của bài toán ba lô

<span id="xuất-phương-án"></span>
#### Xuất phương án

Xuất phương án thực chất là ghi lại một trạng thái nào đó trong ba lô được suy ra như thế nào. Có thể dùng $g_{i,v}$ để biểu diễn khi vật phẩm thứ $i$ chiếm dung lượng $v$ thì có chọn vật phẩm này hay không. Sau đó, trong lúc chuyển trạng thái, ghi lại đã dùng chiến lược nào (chọn hoặc không chọn). Mã giả khi xuất:

```plain
int v = V;  // Ghi lại dung lượng lưu trữ hiện tại

// Vì vật phẩm cuối cùng lưu trạng thái cuối cùng, nên duyệt từ vật phẩm cuối về vật phẩm đầu
duyệt từ vật phẩm cuối về vật phẩm đầu {
  nếu (g[i][v]) {
    đã chọn vật phẩm thứ i;
    v -= trọng lượng của vật phẩm thứ i;
  } ngược lại {
    không chọn vật phẩm thứ i;
  }
}
```

<span id="đếm-số-phương-án"></span>
#### Đếm số phương án

Với bài toán cho trước sức chứa ba lô, chi phí vật phẩm, các quan hệ khác, v.v., cần đếm tổng số phương án đạt đến một sức chứa cụ thể.

Dạng bài này chỉ cần thay việc lấy giá trị lớn nhất bằng phép cộng là được.

Ví dụ, phương trình chuyển trạng thái của bài toán ba lô 0-1 trở thành:

$$
\mathit{dp}_j \leftarrow \mathit{dp}_j + \mathit{dp}_{j-c_i} \qquad (j \ge c_i)
$$

Điều kiện ban đầu: $\mathit{dp}_0=1$

Vì khi sức chứa bằng $0$ cũng có một phương án, tức là không cho gì vào.

<span id="đếm-tổng-số-phương-án-tối-ưu"></span>
#### Đếm tổng số phương án tối ưu

Để đếm tổng số phương án tối ưu, cần sửa nhẹ định nghĩa của mảng $\mathit{dp}$ trong ba lô 0-1: trạng thái DP $f_{i,j}$ là tổng giá trị lớn nhất có thể đạt được khi ba lô có sức chứa $j$ được "lấp đầy chính xác" và chỉ được xét $i$ vật phẩm đầu tiên.

Sau khi sửa như vậy, mỗi trạng thái DP đều có thể dùng một $g_{i,j}$ để biểu diễn số phương án.

$f_{i,j}$ biểu diễn giá trị lớn nhất khi chỉ xét $i$ vật phẩm đầu tiên và thể tích ba lô "đúng bằng" $j$.

$g_{i,j}$ biểu diễn số phương án khi chỉ xét $i$ vật phẩm đầu tiên và thể tích ba lô "đúng bằng" $j$.

Phương trình chuyển:

Nếu $f_{i,j} = f_{i-1,j}$ và $f_{i,j} \neq f_{i-1,j-v}+w$, nghĩa là lúc này không chọn vật phẩm vào ba lô tốt hơn; số phương án được chuyển từ $g_{i-1,j}$.

Nếu $f_{i,j} \neq f_{i-1,j}$ và $f_{i,j} = f_{i-1,j-v}+w$, nghĩa là lúc này chọn vật phẩm vào ba lô tốt hơn; số phương án được chuyển từ $g_{i-1,j-v}$.

Nếu $f_{i,j} = f_{i-1,j}$ và $f_{i,j} = f_{i-1,j-v}+w$, nghĩa là chọn hoặc không chọn đều đạt nghiệm tối ưu; số phương án được chuyển từ cả $g_{i-1,j}$ và $g_{i-1,j-v}$.

Điều kiện ban đầu:

```cpp
memset(f, 0xcf, sizeof(f));
// Vi can lay gia tri lon nhat, khoi tao la am vo cung de tranh chuyen trang thai khi chua lap day
// Neu can lay gia tri nho nhat, khoi tao la duong vo cung 0x3f
f[0] = 0;
g[0] = 1;  // Khong chon gi cung la mot phuong an
```

Vì thể tích lớn nhất của ba lô có thể không lấp đầy được, nghiệm tối ưu không nhất thiết là $f_{m}$.

Cuối cùng, tìm giá trị của nghiệm tối ưu, rồi cộng tất cả số phương án trong mảng $g_{j}$ tương ứng với các vị trí đạt nghiệm tối ưu.

???+ note "Cài đặt"
    ```cpp
    for (int i = 0; i < N; i++) {
      for (int j = V; j >= v[i]; j--) {
        int tmp = std::max(dp[j], dp[j - v[i]] + w[i]);
        int c = 0;
        if (tmp == dp[j]) c += cnt[j];                       // Neu chuyen tu dp[j]
        if (tmp == dp[j - v[i]] + w[i]) c += cnt[j - v[i]];  // Neu chuyen tu dp[j-v[i]]
        dp[j] = tmp;
        cnt[j] = c;
      }
    }
    int max = 0;  // Tim nghiem toi uu
    for (int i = 0; i <= V; i++) {
      max = std::max(max, dp[i]);
    }
    int res = 0;
    for (int i = 0; i <= V; i++) {
      if (dp[i] == max) {
        res += cnt[i];  // Cong so phuong an toi uu
      }
    }
    ```

<span id="nghiệm-tốt-thứ-k-của-bài-toán-ba-lô"></span>
#### Nghiệm tốt thứ $k$ của bài toán ba lô

Ba lô 0-1 thông thường yêu cầu nghiệm tối ưu. Trên phương pháp DP ba lô thông thường, chỉ cần sửa nhẹ bằng cách thêm một chiều để ghi các nghiệm tốt nhất thứ 1 đến thứ $k$ dưới trạng thái hiện tại, sẽ thu được thuật toán tìm nghiệm tốt thứ $k$ của ba lô 0-1.
Cụ thể, $\mathit{dp_{i,j,k}}$ ghi tổng giá trị lớn thứ $k$ có thể đạt được khi xét $i$ vật phẩm đầu tiên và tổng thể tích các vật phẩm được chọn là $j$. Có thể hiểu trạng thái này là mở rộng $\mathit{dp_{i,j}}$ của ba lô 0-1 thông thường, vốn chỉ cần ghi một dữ liệu, thành việc ghi một dãy nghiệm tốt có thứ tự. Khi chuyển trạng thái, cách tìm nghiệm tối ưu trong ba lô thông thường là $\mathit{dp_{i,j}}=\max(\mathit{dp_{i-1,j}},\mathit{dp_{i-1,j-v_{i}}}+w_{i})$; còn bây giờ cần hợp nhất hai dãy giảm dần có kích thước $k$, gồm $\mathit{dp_{i-1,j}}$ và $\mathit{dp_{i-1,j-v_{i}}}+w_{i}$, rồi giữ lại $k$ giá trị lớn nhất sau khi hợp nhất trong $\mathit{dp_{i,j}}$. Bước này dùng phương pháp hai con trỏ, có độ phức tạp $O(k)$; độ phức tạp thời gian tổng thể là $O(nmk)$. Về bộ nhớ, phương pháp này cũng có thể nén bỏ chiều thứ nhất như ba lô thông thường, với độ phức tạp $O(mk)$.

??? note "Bài ví dụ [HDU 2639 Bone Collector II](https://acm.hdu.edu.cn/showproblem.php?pid=2639)"
    Tìm nghiệm tốt thứ $k$ nghiêm ngặt của ba lô 0-1. $n \leq 100,v \leq 1000,k \leq 30$

??? note "Cài đặt"
    ```cpp
    memset(dp, 0, sizeof(dp));
    int i, j, p, x, y, z;
    scanf("%d%d%d", &n, &m, &K);
    for (i = 0; i < n; i++) scanf("%d", &w[i]);
    for (i = 0; i < n; i++) scanf("%d", &c[i]);
    for (i = 0; i < n; i++) {
      for (j = m; j >= c[i]; j--) {
        for (p = 1; p <= K; p++) {
          a[p] = dp[j - c[i]][p] + w[i];
          b[p] = dp[j][p];
        }
        a[p] = b[p] = -1;
        x = y = z = 1;
        while (z <= K && (a[x] != -1 || b[y] != -1)) {
          if (a[x] > b[y])
            dp[j][z] = a[x++];
          else
            dp[j][z] = b[y++];
          if (dp[j][z] != dp[j][z - 1]) z++;
        }
      }
    }
    printf("%d\n", dp[m][K]);
    ```

<span id="tài-liệu-tham-khảo-và-ghi-chú"></span>
## Tài liệu tham khảo và ghi chú

-   [Nine Lectures on the Knapsack Problem - Cui Tianyi](https://github.com/tianyicui/pack).
