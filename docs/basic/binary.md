Trang này giới thiệu ngắn gọn về tìm kiếm nhị phân, tìm kiếm tam phân phát sinh từ phương pháp chia đôi, và nhị phân đáp án.

## Tìm kiếm nhị phân

### Định nghĩa

Tìm kiếm nhị phân (binary search), còn gọi là tìm kiếm chia đôi (half-interval search) hay tìm kiếm logarit (logarithmic search), là thuật toán dùng để tìm một phần tử trong một mảng đã được sắp xếp.

### Quy trình

Lấy ví dụ tìm một số trong mảng tăng dần.

Mỗi lần thuật toán xét phần tử ở giữa phần hiện tại của mảng. Nếu phần tử giữa đúng là giá trị cần tìm thì kết thúc quá trình tìm kiếm; nếu phần tử giữa nhỏ hơn giá trị cần tìm, các phần tử bên trái chỉ có thể nhỏ hơn nữa nên chắc chắn không chứa giá trị cần tìm, chỉ cần tìm ở bên phải; nếu phần tử giữa lớn hơn giá trị cần tìm thì tương tự, chỉ cần tìm ở bên trái.

### Tính chất

#### Độ phức tạp thời gian

Độ phức tạp thời gian tốt nhất của tìm kiếm nhị phân là $O(1)$.

Độ phức tạp thời gian trung bình và xấu nhất của tìm kiếm nhị phân đều là $O(\log n)$. Vì trong quá trình tìm kiếm nhị phân, thuật toán luôn giảm một nửa đoạn đang xét, nên với một mảng độ dài $n$, số lần tìm kiếm nhiều nhất là $O(\log n)$.

#### Độ phức tạp không gian

Phiên bản lặp của tìm kiếm nhị phân có độ phức tạp không gian $O(1)$.

Phiên bản đệ quy (không khử gọi đuôi) của tìm kiếm nhị phân có độ phức tạp không gian $O(\log n)$.

### Cài đặt

```cpp
int binary_search(int start, int end, int key) {
  int ret = -1;  // Không tìm thấy thì trả về chỉ số -1
  int mid;
  while (start <= end) {
    mid = start + ((end - start) >> 1);  // Lấy trung bình trực tiếp có thể tràn số
    if (arr[mid] < key)
      start = mid + 1;
    else if (arr[mid] > key)
      end = mid - 1;
    else {  // Kiểm tra bằng nhau sau cùng vì đa số trường hợp là lớn hơn hoặc nhỏ hơn
      ret = mid;
      break;
    }
  }
  return ret;  // Một điểm thoát duy nhất
}
```

???+ note "Ghi chú"
    Tham khảo [tối ưu biên dịch #dùng dịch bit thay cho phép nhân](../lang/optimizations.md#dùng-dịch-bit-thay-cho-phép-nhân). Với trường hợp $n$ là số có dấu, khi có thể bảo đảm $n\ge 0$, `n >> 1` dùng ít lệnh hơn `n / 2`.

### Tối thiểu hóa giá trị lớn nhất

Cần chú ý rằng "có thứ tự" ở đây là có thứ tự theo nghĩa rộng. Nếu một phía của mảng đều thỏa một điều kiện nào đó, còn phía còn lại đều không thỏa điều kiện đó, ta cũng có thể xem đó là một dạng có thứ tự (nếu xem thỏa điều kiện là $1$, không thỏa là $0$, thì ít nhất theo chiều của điều kiện này nó là có thứ tự). Nói cách khác, tìm kiếm nhị phân có thể dùng để tìm giá trị lớn nhất (nhỏ nhất) thỏa một điều kiện nào đó.

Với bài toán yêu cầu giá trị nhỏ nhất có thể của một giá trị lớn nhất thỏa điều kiện (tối thiểu hóa giá trị lớn nhất), ý tưởng đầu tiên là liệt kê "giá trị lớn nhất" được xem là đáp án từ nhỏ đến lớn, rồi kiểm tra nó có hợp lệ không. Nếu đáp án có tính đơn điệu, có thể dùng tìm kiếm nhị phân để tìm đáp án nhanh hơn. Vì vậy, để dùng tìm kiếm nhị phân giải dạng bài "tối thiểu hóa giá trị lớn nhất", cần thỏa ba điều kiện sau:

1.  Đáp án nằm trong một đoạn cố định;
2.  Có thể việc tìm trực tiếp một giá trị thỏa điều kiện không dễ, nhưng cần có thể kiểm tra tương đối dễ xem một giá trị có thỏa điều kiện hay không;
3.  Các nghiệm khả thi có tính đơn điệu trên đoạn. Nói cách khác, nếu $x$ thỏa điều kiện thì $x + 1$ hoặc $x - 1$ cũng thỏa điều kiện. (Như vậy sẽ có tính đơn điệu đã nói ở trên.)

Tất nhiên, tối đa hóa giá trị nhỏ nhất cũng tương tự.

### Tìm kiếm nhị phân trong STL

Thư viện chuẩn C++ cung cấp hàm [`std::lower_bound`](https://en.cppreference.com/w/cpp/algorithm/lower_bound) để tìm phần tử đầu tiên không nhỏ hơn giá trị cho trước, và hàm [`std::upper_bound`](https://en.cppreference.com/w/cpp/algorithm/upper_bound) để tìm phần tử đầu tiên lớn hơn giá trị cho trước. Cả hai đều được định nghĩa trong tệp tiêu đề `<algorithm>`.

Cả hai đều được cài đặt bằng nhị phân, nên trước khi gọi phải bảo đảm các phần tử đã được sắp xếp.

### bsearch

Hàm bsearch là tìm kiếm nhị phân do thư viện chuẩn C cung cấp, được định nghĩa trong `<stdlib.h>`. Trong thư viện chuẩn C++, hàm này được định nghĩa trong `<cstdlib>`. qsort và bsearch là hai hàm kiểu thuật toán duy nhất trong ngôn ngữ C.

So với bốn tham số của qsort ([STL liên quan đến sắp xếp](./stl-sort.md)), hàm bsearch thêm tham số "địa chỉ của phần tử cần tìm" ở ngoài cùng bên trái. Lý do truyền theo dạng địa chỉ là để tiện dùng trực tiếp cùng một hàm so sánh với qsort, từ đó có thể tìm ngay sau khi sắp xếp. Vì vậy tham số này không thể truyền trực tiếp một giá trị cụ thể, mà cần lưu giá trị cần tìm vào một biến rồi truyền địa chỉ của biến đó.

Như vậy, bsearch có tổng cộng năm tham số: địa chỉ của phần tử cần tìm, tên mảng, số lượng phần tử, kích thước phần tử, và quy tắc so sánh. Quy tắc so sánh vẫn được thực hiện bằng cách chỉ định hàm so sánh; xem chi tiết ở [STL liên quan đến sắp xếp](./stl-sort.md).

Giá trị trả về của bsearch là địa chỉ của phần tử tìm được; địa chỉ này có kiểu void.

Chú ý: bsearch khác lower\_bound và upper\_bound ở hai điểm:

-   Khi có nhiều phần tử trùng nhau cùng thỏa điều kiện, nó trả về phần tử thỏa điều kiện đầu tiên gặp trong quá trình tìm kiếm nhị phân, nên phần tử đó có thể nằm ở giữa nhóm các phần tử trùng nhau.
-   Khi không tìm thấy phần tử tương ứng, nó trả về NULL.

Có thể dùng lower\_bound để thực hiện đúng chức năng của bsearch, nên những bài có thể AC bằng bsearch đều có thể viết lại trực tiếp bằng lower\_bound. Tuy nhiên, do điểm khác biệt thứ hai ở trên, chẳng hạn khi tìm 3 trong dãy 1, 2, 4, 5, 6, việc dùng bsearch để thực hiện chức năng của lower\_bound trở nên khó khăn.

Dùng bsearch để thực hiện chức năng của lower\_bound có khó, vậy có nhất thiết là không làm được không? Câu trả lời là không; tồn tại một kỹ thuật khá tricky. Dựa vào đặc tính trình biên dịch xử lý hàm so sánh: tham số thứ nhất luôn trỏ tới phần tử cần tìm, tham số thứ hai trỏ tới phần tử trong mảng cần tìm. Nhờ đó cũng có thể dùng bsearch để thực hiện lower\_bound và upper\_bound như ví dụ dưới đây. Tuy nhiên, cách này yêu cầu mảng cần tìm phải là mảng toàn cục, để có thể truyền trực tiếp địa chỉ đầu.

```cpp
int A[100005];  // Mảng toàn cục ví dụ

// Tìm địa chỉ của phần tử đầu tiên không nhỏ hơn phần tử cần tìm
int lower(const void *p1, const void *p2) {
  int *a = (int *)p1;
  int *b = (int *)p2;
  if ((b == A || compare(a, b - 1) > 0) && compare(a, b) > 0)
    return 1;
  else if (b != A && compare(a, b - 1) <= 0)
    return -1;  // Có dùng phép trừ địa chỉ, nên phải chỉ định kiểu phần tử
  else
    return 0;
}

// Tìm địa chỉ của phần tử đầu tiên lớn hơn phần tử cần tìm
int upper(const void *p1, const void *p2) {
  int *a = (int *)p1;
  int *b = (int *)p2;
  if ((b == A || compare(a, b - 1) >= 0) && compare(a, b) >= 0)
    return 1;
  else if (b != A && compare(a, b - 1) < 0)
    return -1;  // Có dùng phép trừ địa chỉ, nên phải chỉ định kiểu phần tử
  else
    return 0;
}
```

Vì hiện nay thí sinh OI hiếm khi viết C thuần và phương pháp này có phạm vi ứng dụng hạn chế, đây không phải trọng điểm. Với người mới học, nên dùng đúng các hàm lower\_bound và upper\_bound trong C++.

### Nhị phân đáp án

Khi giải bài, ta thường nghĩ tới việc liệt kê đáp án rồi kiểm tra giá trị được liệt kê có đúng hay không. Nếu thỏa tính đơn điệu, điều kiện để dùng phương pháp nhị phân được đáp ứng. Thay việc liệt kê ở đây bằng nhị phân, ta có "nhị phân đáp án".

???+ note "[Luogu P1873 Chặt cây](https://www.luogu.com.cn/problem/P1873)"
    Người thợ đốn gỗ Mirko cần chặt được $M$ mét gỗ. Đây là công việc rất dễ với Mirko, vì anh có một chiếc máy cưa mới rất tốt, có thể đốn rừng nhanh như lửa lan. Tuy nhiên, Mirko chỉ được phép chặt một hàng cây.
    
    Cách máy cưa của Mirko hoạt động như sau: Mirko đặt một tham số độ cao $H$ (mét), máy cưa nâng một lưỡi cưa khổng lồ lên độ cao $H$, rồi cưa bỏ tất cả phần cây cao hơn $H$ (dĩ nhiên, phần cây không cao hơn $H$ mét được giữ nguyên). Mirko nhận được phần cây bị cưa xuống.
    
    Ví dụ, nếu chiều cao một hàng cây lần lượt là $20,~15,~10,~17$, Mirko nâng lưỡi cưa lên độ cao $15$ mét. Sau khi cắt, chiều cao còn lại của cây sẽ là $15,~15,~10,~15$, và Mirko nhận được $5$ mét gỗ từ cây thứ $1$, $2$ mét gỗ từ cây thứ $4$, tổng cộng $7$ mét gỗ.
    
    Mirko rất quan tâm tới bảo vệ môi trường, nên anh sẽ không chặt quá nhiều gỗ. Đó là lý do anh đặt lưỡi cưa cao nhất có thể. Nhiệm vụ của bạn là giúp Mirko tìm độ cao nguyên lớn nhất $H$ của lưỡi cưa sao cho anh nhận được ít nhất $M$ mét gỗ. Tức là nếu nâng lưỡi cưa thêm $1$ mét, anh sẽ không nhận đủ $M$ mét gỗ.

??? note "Ý tưởng giải"
    Ta có thể liệt kê đáp án từ $1$ đến $10^9$, nhưng cách ngây thơ này chắc chắn không đạt điểm tối đa, vì liệt kê từ $1$ tới $10^9$ quá tốn thời gian. Ta có thể nhị phân trên đoạn $[1,~10^9]$ để chọn đáp án, rồi kiểm tra tính khả thi của từng đáp án (thường dùng tham lam). **Đó chính là nhị phân đáp án.**

??? note "Mã tham khảo"
    ```cpp
    int a[1000005];
    int n, m;
    
    bool check(int k) {  // Kiểm tra tính khả thi, k là độ cao lưỡi cưa
      long long sum = 0;
      for (int i = 1; i <= n; i++)       // Kiểm tra từng cây
        if (a[i] > k)                    // Nếu cây cao hơn độ cao lưỡi cưa
          sum += (long long)(a[i] - k);  // Cộng thêm chiều dài gỗ
      return sum >= m;                   // Đạt chiều dài tối thiểu thì khả thi
    }
    
    int find() {
      int l = 1, r = 1e9 + 1;   // Vì dùng đoạn đóng trái mở phải, nên 10^9 cần cộng 1
      while (l + 1 < r) {       // Nếu hai điểm chưa kề nhau
        int mid = (l + r) / 2;  // Lấy giá trị giữa
        if (check(mid))         // Nếu khả thi
          l = mid;              // Nâng độ cao lưỡi cưa
        else
          r = mid;  // Ngược lại hạ độ cao lưỡi cưa
      }
      return l;  // Trả về giá trị bên trái
    }
    
    int main() {
      cin >> n >> m;
      for (int i = 1; i <= n; i++) cin >> a[i];
      cout << find();
      return 0;
    }
    ```
    
    Sau khi đọc đoạn mã trên, chắc chắn bạn sẽ có hai câu hỏi:
    
    1.  Vì sao đoạn tìm kiếm là đóng trái mở phải?
    
        Vì khi tìm đến cuối, nó sẽ như sau (lấy giá trị hợp lệ lớn nhất làm ví dụ):
    
        ![](./images/binary-final-1.svg)
    
        Sau đó sẽ
    
        ![](./images/binary-final-2.svg)
    
        Trường hợp giá trị hợp lệ nhỏ nhất thì ngược lại.
    2.  Vì sao trả về giá trị bên trái?
    
        Tương tự như trên.

## Tìm kiếm tam phân

### Dẫn nhập

Phương pháp nhị phân có thể dùng để xấp xỉ nghiệm của hàm số. Nếu cần tìm điểm cực trị của một hàm đơn đỉnh, thường cần dùng tìm kiếm tam phân (ternary search).

Với một hàm $f(x)$, nếu tồn tại $x^*$ sao cho $f(x)$ tăng đơn điệu khi $x<x^*$ và giảm đơn điệu khi $x>x^*$, thì gọi $f(x)$ là hàm đơn đỉnh (unimodal function). Hiển nhiên, $x^*$ là điểm đạt giá trị lớn nhất, còn $f(x^*)$ là giá trị lớn nhất của hàm.

??? note "Vì sao không tìm điểm cực trị bằng cách tìm nghiệm của đạo hàm?"
    Về mặt khách quan, sau khi lấy đạo hàm, dùng nhị phân để tìm nghiệm của đạo hàm (do hàm là đơn đỉnh, nghiệm của đạo hàm trong cùng một phạm vi là duy nhất) để thu được điểm cực trị của hàm đơn đỉnh là khả thi.
    
    Nhưng trước hết, với một số hàm, quá trình và kết quả lấy đạo hàm khá phức tạp.
    
    Thứ hai, trong một số bài, hàm đơn đỉnh cần tìm điểm cực trị không phải là một hàm riêng lẻ, mà là hàm thu được từ nhiều hàm qua một phép toán đặc biệt (chẳng hạn tìm giá trị lớn nhất của giá trị nhỏ nhất của nhiều hàm bậc nhất có tính đơn điệu không hoàn toàn giống nhau). Khi đó đạo hàm của hàm có thể là hàm từng đoạn, và tại một số điểm có thể không khả vi.

???+ warning "Chú ý"
    Tìm kiếm tam phân vừa có thể tìm giá trị lớn nhất của hàm đơn đỉnh, vừa có thể tìm giá trị nhỏ nhất của "hàm đơn đáy". Để tiện trình bày, trừ khi nói rõ khác đi, phần dưới đều lấy bài toán tìm giá trị lớn nhất của hàm đơn đỉnh làm ví dụ.

### Quy trình

Tư tưởng cơ bản của tìm kiếm tam phân tương tự phương pháp nhị phân, nhưng mỗi thao tác cần chọn hai điểm bất kỳ $lmid < rmid$ trong đoạn hiện tại $[l,r]$ (giữa hai điểm màu cam trong hình dưới; hai điểm màu xanh là hai điểm được chọn). Như hình dưới, nếu $f(lmid)<f(rmid)$, thì trên đoạn $[l,lmid)$ (phần màu đỏ trong hình) hàm chắc chắn tăng đơn điệu, điểm đạt giá trị lớn nhất (điểm màu xanh lá trong hình) chắc chắn không nằm trong đoạn này, nên có thể loại bỏ đoạn này. Tuy nhiên, không thể loại trừ khả năng điểm cực đại nằm bên phải $rmid$, nên không thể loại bỏ nhiều hơn. Trường hợp ngược lại cũng tương tự.

![](images/ternary.svg)

Tính đúng đắn của tìm kiếm tam phân không phụ thuộc vào cách chọn $lmid$ và $rmid$; thông thường có thể chọn hai điểm chia ba. Tuy nhiên, cách chọn chúng thật sự ảnh hưởng tới hiệu suất của tìm kiếm tam phân. Nguyên nhân là mỗi thao tác của tam phân sẽ loại bỏ một trong hai đoạn ở hai bên. Để giảm số thao tác tam phân, nên làm cho hai đoạn hai bên lớn nhất có thể. Vì vậy, trong mỗi thao tác, chọn $lmid$ và $rmid$ lần lượt là $mid-\varepsilon$ và $mid+\varepsilon$ là một lựa chọn tốt. Thực tế, cách lấy $mid\pm \varepsilon$ tương đương với việc tính đạo hàm xấp xỉ tại $mid$, tức $\dfrac{f(mid+\varepsilon)-f(mid-\varepsilon)}{2\varepsilon}$, rồi xét dấu để xác định điểm cực trị nằm về phía nào của $mid$.

### Cài đặt

Mã giả như sau:

$$
\begin{array}{l}
\textbf{Thuật toán }\operatorname{TernarySearch}(f,l,r):\\
\textbf{Đầu vào. } \text{Hàm đơn đỉnh } f(x) \text{ và miền xác định } [l,r].  \\
\textbf{Đầu ra. } \text{Điểm đạt cực đại }x^*\text{, với sai số không quá }\varepsilon\text{, và giá trị } f(x^*). \\
\textbf{Phương pháp. } \\
\begin{array}{ll}
1 & \textbf{while } r - l > \varepsilon\\
2 & \qquad mid\gets (l+r)/2\\
3 & \qquad lmid\gets mid - \varepsilon / 3 \\
4 & \qquad rmid\gets mid + \varepsilon / 3 \\
5 & \qquad \textbf{if } f(lmid) < f(rmid) \\
6 & \qquad \qquad l\gets lmid \\
7 & \qquad \textbf{else } \\
8 & \qquad \qquad r\gets rmid \\
9 & x^* \gets (l+r)/2 \\
10& \textbf{return } x^*,~ f(x^*)
\end{array}
\end{array}
$$

???+ tip "Cách chọn điểm chia"
    Trong mã, điểm chia được chọn là $mid \pm \varepsilon / 3$ để bảo đảm điểm chia luôn nằm giữa $l$ và $r$ hiện tại, từ đó tránh rơi vào vòng lặp vô hạn.

???+ info "Trường hợp số nguyên"
    Nếu miền xác định của hàm $f(x)$ là số nguyên, thì tìm kiếm tam phân nói trên và phương pháp lát cắt vàng ở phần sau đều nên dừng khi $r-l$ còn rất nhỏ. Với trường hợp $r-l$ rất nhỏ, cần duyệt vét cạn để tìm điểm đạt giá trị lớn nhất.

### Tối ưu: phương pháp lát cắt vàng

Nếu chi phí cho một lần gọi $f(x)$ rất cao, cần giảm thêm số lần gọi $f(x)$, có thể dùng phương pháp lát cắt vàng (golden-section search) để cải thiện hằng số của tìm kiếm tam phân. Đây cũng là nội dung quan trọng trong phương pháp tối ưu do Hoa La Canh đề xuất.

Trong tìm kiếm tam phân, mỗi vòng lặp cần hai lần gọi hàm, và sau một vòng lặp, độ dài đoạn nhiều nhất giảm còn $1/2$ ban đầu. Điều này có nghĩa là để đạt độ chính xác $\varepsilon$, cần ít nhất

$$
2\log_2\dfrac{r-l}{\varepsilon}
$$

lần gọi hàm. Đây là kết quả tốt nhất mà tìm kiếm tam phân có thể đạt được. Nếu chọn các điểm chia khác, chẳng hạn hai điểm chia ba, số lần gọi sẽ tăng thêm vì đoạn thu hẹp chậm hơn sau mỗi vòng lặp.

Ý tưởng cải tiến của phương pháp lát cắt vàng là tái sử dụng điểm chia đã tính ở vòng trước. Như vậy, ngoài vòng lặp đầu tiên cần hai lần gọi hàm, các vòng lặp còn lại chỉ cần một lần gọi hàm. Gọi tỉ lệ lát cắt vàng là

$$
\phi = \dfrac{\sqrt{5}-1}{2} \approx 0.618.
$$

Trong mỗi vòng lặp, hai điểm chia được chọn là hai điểm lát cắt vàng trái và phải:

$$
m^l = \phi l +(1-\phi)r,~m^r = (1-\phi)l+\phi r.
$$

Các điểm lát cắt vàng chia đoạn thẳng theo cấu trúc tự đồng dạng. Nói cách khác, $m^l$ là điểm lát cắt vàng trái của đoạn $[l,r]$, đồng thời cũng là điểm lát cắt vàng phải của đoạn $[l,m^r]$. Lợi ích của cách chọn điểm chia này là trong các điểm chia được chọn ở vòng lặp thứ $k>1$, luôn có một điểm đã được tính trước đó và có thể tái sử dụng trực tiếp kết quả tính toán trước.

![](./images/golden-section-search.svg)

Sau khi chọn điểm chia như vậy, để đạt độ chính xác $\varepsilon$, chỉ cần

$$
1 + \log_{\phi^{-1}}\dfrac{r-l}{\varepsilon} \approx 1 + 1.44\log_2\dfrac{r-l}{\varepsilon}
$$

lần gọi hàm. Theo nghĩa tiệm cận, số lần gọi hàm ít hơn.

Mã giả như sau:

$$
\begin{array}{l}
\textbf{Thuật toán }\operatorname{GoldenSectionSearch}(f,l,r):\\
\textbf{Đầu vào. } \text{Hàm đơn đỉnh } f(x) \text{ và miền xác định } [l,r].  \\
\textbf{Đầu ra. } \text{Điểm đạt cực đại }x^*\text{, với sai số không quá }\varepsilon\text{, và giá trị } f(x^*). \\
\textbf{Phương pháp. } \\
\begin{array}{ll}
1 & lmid \gets \phi l + (1-\phi)r \\
2 & rmid \gets (1-\phi)l + \phi r \\
3 & lval \gets f(lmid) \\
4 & rval \gets f(rmid) \\
5 & \textbf{while } r - l > \varepsilon \\
6 & \qquad \textbf{if } lval > rval \\
7 & \qquad \qquad r \gets rmid \\
8 & \qquad \qquad rmid \gets lmid \\
9 & \qquad \qquad rval \gets lval \\
10& \qquad \qquad lmid \gets \phi l + (1-\phi)r \\
11& \qquad \qquad lval \gets f(lmid) \\
12& \qquad \textbf{else} \\
13& \qquad \qquad l \gets lmid \\
14& \qquad \qquad lmid \gets rmid \\
15& \qquad \qquad lval \gets rval \\
16& \qquad \qquad rmid \gets (1-\phi)l + \phi r \\
17& \qquad \qquad rval \gets f(rmid) \\
18& x^* \gets (l+r)/2 \\
19& \textbf{return }x^*,~f(x^*)
\end{array}
\end{array}
$$

### Bài mẫu

???+ note "[Luogu P3382 - Tam phân](https://www.luogu.com.cn/problem/P3382)"
    Cho một hàm bậc $N$ và khoảng $[l, r]$, hãy tìm giá trị duy nhất của $x$ sao cho hàm tăng đơn điệu trên $[l, x]$ và giảm đơn điệu trên $[x, r]$.

??? note "Ý tưởng giải"
    Bài này yêu cầu tìm giá trị của biến độc lập khi hàm bậc $N$ đạt giá trị lớn nhất trên $[l, r]$; rõ ràng có thể dùng tìm kiếm tam phân.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/basic/code/binary/binary_1.cpp"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/basic/code/binary/binary_1.py"
        ```

### Bài tập

-   [UVa 1476 - Error Curves](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=447&page=show_problem&problem=4222)
-   [UVa 10385 - Duathlon](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=15&page=show_problem&problem=1326)
-   [UOJ 162 - Tập huấn Thanh Hoa 2015: Kiểm tra bóng đèn](https://uoj.ac/problem/162)
-   [Luogu P7579 - RdOI R2: Cân khối lượng (weigh)](https://www.luogu.com.cn/problem/P7579)

## Quy hoạch phân số

Xem: [quy hoạch phân số](../misc/frac-programming.md)

Quy hoạch phân số thường mô tả bài toán sau: mỗi vật phẩm có hai thuộc tính $c_i$, $d_i$; cần chọn một số vật phẩm theo một cách nào đó sao cho $\frac{\sum{c_i}}{\sum{d_i}}$ lớn nhất hoặc nhỏ nhất.

Các ví dụ kinh điển gồm chu trình tỉ lệ tối ưu, cây khung tỉ lệ tối ưu, v.v.

Quy hoạch phân số có thể được giải bằng phương pháp nhị phân.

## Tài liệu tham khảo

-   [Ternary search - Wikipedia](https://en.wikipedia.org/wiki/Ternary_search)
-   [Golden-section search - Wikipedia](https://en.wikipedia.org/wiki/Golden-section_search)
-   [Ternary search - CP Algortihms](https://cp-algorithms.com/num_methods/ternary_search.html)
