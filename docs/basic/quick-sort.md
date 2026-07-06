Trang này giới thiệu ngắn gọn về sắp xếp nhanh.

## Định nghĩa

Sắp xếp nhanh (quicksort), còn gọi là sắp xếp trao đổi phân hoạch
(partition-exchange sort), thường gọi tắt là quicksort, là một thuật toán sắp
xếp được sử dụng rộng rãi.

## Nguyên lý cơ bản và cài đặt

### Quy trình

Sắp xếp nhanh hoạt động bằng cách dùng phương pháp [chia để trị](./divide-and-conquer.md) để sắp xếp một mảng.

Sắp xếp nhanh gồm ba bước:

1.  Chia dãy số thành hai phần (cần bảo đảm quan hệ lớn nhỏ tương đối);
2.  Đệ quy sắp xếp nhanh trên hai dãy con;
3.  Không cần trộn, vì lúc này dãy đã hoàn toàn có thứ tự.

Khác với sắp xếp trộn, bước đầu tiên không trực tiếp chia thành hai dãy trước và
sau, mà trong quá trình chia phải bảo đảm quan hệ lớn nhỏ tương đối. Cụ thể,
bước đầu tiên là chia dãy số thành hai phần, đồng thời bảo đảm mọi số trong dãy
con phía trước đều nhỏ hơn mọi số trong dãy con phía sau. Để bảo đảm độ phức
tạp thời gian trung bình, thông thường chọn ngẫu nhiên một số $m$ làm mốc phân
chia giữa hai dãy con.

Sau đó, duy trì hai con trỏ $p$ và $q$ ở hai đầu, lần lượt xét xem phần tử hiện
tại đã nằm ở vị trí nên thuộc về nó hay chưa (phía trước hay phía sau). Nếu
phần tử hiện tại đặt sai, chẳng hạn con trỏ phía sau $q$ gặp một số nhỏ hơn
$m$, có thể hoán đổi các số ở vị trí $p$ và $q$, rồi dịch $p$ sang phải một vị
trí. Khi các phần tử hiện tại đã được đặt đúng phía, tiếp tục di chuyển con trỏ
để xử lý cho đến khi hai con trỏ gặp nhau.

Thực tế, sắp xếp nhanh không quy định cụ thể phải cài đặt bước đầu tiên như thế
nào; cả quá trình chọn $m$ lẫn quá trình phân hoạch đều có nhiều cách cài đặt.

Ở bước thứ ba, hai dãy con đã lần lượt có thứ tự và mọi số trong dãy thứ nhất
đều nhỏ hơn dãy thứ hai, nên chỉ cần ghép trực tiếp lại là được.

=== "C++"
    === "Cài đặt không đệ quy[^ref2]"
        ```cpp
        struct Range {
          int start, end;
        
          Range(int s = 0, int e = 0) { start = s, end = e; }
        };
        
        template <typename T>
        void quick_sort(T arr[], const int len) {
          if (len <= 0) return;
          Range r[len];
          int p = 0;
          r[p++] = Range(0, len - 1);
          while (p) {
            Range range = r[--p];
            if (range.start >= range.end) continue;
            T mid = arr[range.end];
            int left = range.start, right = range.end - 1;
            while (left < right) {
              while (arr[left] < mid && left < right) left++;
              while (arr[right] >= mid && left < right) right--;
              std::swap(arr[left], arr[right]);
            }
            if (arr[left] >= arr[range.end])
              std::swap(arr[left], arr[range.end]);
            else
              left++;
            r[p++] = Range(range.start, left - 1);
            r[p++] = Range(left + 1, range.end);
          }
        }
        ```
    
    === "Cài đặt đệ quy"
        ```cpp
        template <typename T>
        int Partition(T A[], int low, int high) {
          int pivot = A[low];
          while (low < high) {
            while (low < high && pivot <= A[high]) --high;
            A[low] = A[high];
            while (low < high && A[low] <= pivot) ++low;
            A[high] = A[low];
          }
          A[low] = pivot;
          return low;
        }
        
        template <typename T>
        void QuickSort(T A[], int low, int high) {
          if (low < high) {
            int pivot = Partition(A, low, high);
            QuickSort(A, low, pivot - 1);
            QuickSort(A, pivot + 1, high);
          }
        }
        
        template <typename T>
        void QuickSort(T A[], int len) {
          QuickSort(A, 0, len - 1);
        }
        ```

=== "Python[^ref2]"
    ```python
    def quick_sort(alist, first, last):
        if first >= last:
            return
        mid_value = alist[first]
        low = first
        high = last
        while low < high:
            while low < high and alist[high] >= mid_value:
                high -= 1
            alist[low] = alist[high]
            while low < high and alist[low] < mid_value:
                low += 1
            alist[high] = alist[low]
        alist[low] = mid_value
        quick_sort(alist, first, low - 1)
        quick_sort(alist, low + 1, last)
    ```

## Tính chất

### Tính ổn định

Sắp xếp nhanh là một thuật toán sắp xếp không ổn định.

### Độ phức tạp thời gian

Độ phức tạp thời gian tốt nhất và trung bình của sắp xếp nhanh là
$O(n\log n)$, còn độ phức tạp thời gian xấu nhất là $O(n^2)$.

Trong trường hợp tốt nhất, giá trị mốc được chọn ở mỗi lần đều là trung vị của
dãy. Khi đó độ phức tạp thời gian của thuật toán thỏa mãn truy hồi
$T(n) = 2T(\dfrac{n}{2}) + \Theta(n)$; theo định lý Master,
$T(n) = \Theta(n\log n)$.

Trong trường hợp xấu nhất, giá trị mốc được chọn ở mỗi lần đều là giá trị cực
trị của dãy. Khi đó độ phức tạp thời gian của thuật toán thỏa mãn truy hồi
$T(n) = T(n - 1) + \Theta(n)$; cộng dồn suy ra $T(n) = \Theta(n^2)$.

Trong trường hợp trung bình, giá trị mốc được chọn ở mỗi lần có thể xem là ngẫu nhiên đều.

??? note "Chứng minh"
    Sau đây là phần chứng minh độ phức tạp thời gian của thuật toán trong
    trường hợp này là $O(n\log n)$.
    
    **Bổ đề 1:** Khi sắp xếp nhanh một mảng có $n$ phần tử, giả sử tổng số phép
    so sánh trong quá trình phân hoạch phần tử là $X$, thì độ phức tạp thời
    gian của sắp xếp nhanh là $O(n + X)$.
    
    Vì trong mỗi lần phân hoạch phần tử, thuật toán sẽ chọn một phần tử làm
    mốc, nên quá trình phân hoạch phần tử xảy ra nhiều nhất $n$ lần. Hơn nữa,
    số phép so sánh và số thao tác cơ bản khác trong quá trình phân hoạch cùng
    bậc độ lớn, nên tổng độ phức tạp thời gian là $O(n + X)$.
    
    Gọi $a_i$ là số nhỏ thứ $i$ trong mảng ban đầu, định nghĩa $A_{i,j}$ là
    $\{ a_i, a_{i+1}, \dots, a_j \}$, và $X_{i,j}$ là biến ngẫu nhiên rời rạc
    nhận giá trị $0$ hoặc $1$, biểu thị trong quá trình sắp xếp $a_i$ có được
    so sánh với $a_j$ hay không.
    
    Các giá trị mốc được chọn ở mỗi lần là khác nhau, và phần tử chỉ
    được so sánh với mốc, nên tổng số phép so sánh là
    
    $$
    \begin{aligned} X = \sum \limits _ {i = 1} ^ {n - 1} \sum \limits _ {j = i + 1} ^ n X_{i,j} \end{aligned}
    $$
    
    Theo tính tuyến tính của kỳ vọng,
    
    $$
    \begin{aligned}
    E[X] & = E \left[ \sum \limits _ {i = 1} ^ {n - 1} \sum \limits _ {j = i + 1} ^ n X_{i,j} \right] \\
         & = \sum \limits _ {i = 1} ^ {n - 1} \sum \limits _ {j = i + 1} ^ n E[X_{i,j}] \\
         & = \sum \limits _ {i = 1} ^ {n - 1} \sum \limits _ {j = i + 1} ^ n P(a_i\ \text{và}\ a_j\ \text{được so sánh})
    \end{aligned}
    $$
    
    **Bổ đề 2:** Điều kiện cần và đủ để $a_i$ và $a_j$ được so sánh là $a_i$
    hoặc $a_j$ là giá trị mốc đầu tiên được chọn trong tập $A_{i,j}$.
    
    Trước hết chứng minh tính cần thiết: nếu cả $a_i$ và $a_j$ đều không phải
    giá trị mốc đầu tiên được chọn trong tập $A_{i,j}$, thì $a_i$ không được so
    sánh với $a_j$.
    
    Nếu cả $a_i$ và $a_j$ đều không phải giá trị mốc đầu tiên được chọn trong
    tập $A_{i,j}$, thì tồn tại một $x$ thỏa mãn $i < x < j$ sao cho
    $a_x$ là giá trị mốc đầu tiên được chọn trong $A_{i,j}$. Trong lần phân
    hoạch lấy $a_x$ làm mốc, $a_i$ và $a_j$ bị chia vào hai dãy con khác nhau
    của mảng, nên về sau $a_i$ và $a_j$ không được so sánh. Lại vì
    phần tử chỉ so sánh với mốc, nên $a_i$ và $a_j$ cũng không được so sánh
    trước và trong lần phân hoạch này. Do đó $a_i$ không được so sánh với
    $a_j$.
    
    Tiếp theo chứng minh tính đủ: nếu $a_i$ hoặc $a_j$ là giá trị mốc đầu tiên
    được chọn trong tập $A_{i,j}$, thì $a_i$ và $a_j$ được so sánh.
    
    Không mất tính tổng quát, giả sử $a_i$ là giá trị mốc đầu tiên được chọn
    trong tập $A_{i,j}$. Vì chưa có số nào khác trong $A_{i,j}$ được chọn làm
    mốc, các phần tử trong $A_{i,j}$ đều nằm trong cùng một dãy con của mảng.
    Trong lần phân hoạch lấy $a_i$ làm mốc, $a_i$ được so sánh với mọi phần tử
    trong dãy con hiện tại, nên $a_i$ được so sánh với $a_j$.
    
    Xét cách tính $P(a_i\ \text{và}\ a_j\ \text{được so sánh})$. Trước khi một
    phần tử nào đó trong $A_{i,j}$ được chọn làm mốc, các phần tử của
    $A_{i,j}$ đều nằm trong cùng một dãy con của mảng. Vì vậy mỗi phần tử trong
    $A_{i,j}$ đều có xác suất bằng nhau để trở thành giá trị mốc đầu tiên được
    chọn. Do $A_{i,j}$ có $j - i + 1$ phần tử, theo bổ đề 2,
    
    $$
    P(a_i \text{và} a_j \text{được so sánh}) = P(a_i \text{hoặc} a_j \text{là mốc đầu tiên được chọn trong tập} A_{i,j}) = \dfrac{2}{j-i+1}
    $$
    
    Do đó
    
    $$
    \begin{aligned}
    E[X] & = \sum \limits _ {i = 1} ^ {n - 1} \sum \limits _ {j = i + 1} ^ n P(a_i\ \text{và}\ a_j\ \text{được so sánh}) \\
         & = \sum \limits _ {i = 1} ^ {n - 1} \sum \limits _ {j = i + 1} ^ n \dfrac{2}{j - i + 1} \\
         & = \sum \limits _ {i = 1} ^ {n - 1} \sum \limits _ {k = 2} ^ {n - i + 1} \dfrac{2}{k} \\
         & = \sum \limits _ {i = 1} ^ {n - 1} O(\log n) \\
         & = O(n \log n)
    \end{aligned}
    $$
    
    Từ đó, độ phức tạp thời gian kỳ vọng của sắp xếp nhanh là $O(n \log n)$.

Trong thực tế, gần như không thể gặp trường hợp xấu nhất, còn truy cập bộ nhớ
của sắp xếp nhanh tuân theo nguyên lý cục bộ, nên trong đa số trường hợp sắp
xếp nhanh hoạt động tốt hơn đáng kể so với sắp xếp vun đống và các thuật toán
sắp xếp khác có độ phức tạp $O(n \log n)$.[^ref1]

## Tối ưu hóa

### Ý tưởng tối ưu hóa đơn giản

Nếu chỉ cài đặt sắp xếp nhanh theo ý tưởng cơ bản đã nêu ở trên (hoặc chép
nguyên mẫu cài đặt), rất có thể sẽ không được chấp nhận ở bài mẫu
[Luogu P1177 - Mẫu sắp xếp nhanh](https://www.luogu.com.cn/problem/P1177), vì
có dữ liệu ác ý có thể làm sắp xếp nhanh đơn giản suy biến thành $O(n^2)$.

Vì vậy, cần tối ưu hóa ý tưởng sắp xếp nhanh đơn giản. Các hướng tối ưu hóa
thường gặp gồm ba loại sau[^ref3].

-   Dùng phương pháp **lấy trung vị của ba số (tức chọn trung vị trong ba phần
    tử đầu, cuối và giữa)** để chọn phần tử phân chia hai dãy con (tức pivot).
    Cách này tránh suy biến do dữ liệu cực đoan, chẳng hạn dãy tăng hoặc dãy
    giảm;
-   Khi dãy ngắn, dùng **sắp xếp chèn** sẽ hiệu quả hơn;
-   Sau mỗi lượt sắp xếp, **gom các phần tử bằng phần tử mốc quanh phần tử
    mốc**, từ đó tránh suy biến do dữ liệu cực đoan, chẳng hạn phần lớn phần tử
    trong dãy đều bằng nhau.

Sau đây là một số cách tối ưu hóa sắp xếp nhanh tương đối hoàn thiện.

### Sắp xếp nhanh ba đường

#### Định nghĩa

Sắp xếp nhanh ba đường (3-way radix quicksort) là sự kết hợp giữa sắp xếp nhanh
và [sắp xếp cơ số](./radix-sort.md). Ý tưởng thuật toán của nó dựa trên lời giải
của
[bài toán quốc kỳ Hà Lan](https://en.wikipedia.org/wiki/Dutch_national_flag_problem).

#### Quy trình

Khác với sắp xếp nhanh nguyên bản, sau khi chọn ngẫu nhiên điểm mốc $m$, sắp
xếp nhanh ba đường chia dãy cần sắp xếp thành ba phần: nhỏ hơn $m$, bằng $m$ và
lớn hơn $m$. Nhờ vậy, nó đạt được hiệu quả gom các phần tử bằng phần tử mốc
quanh phần tử mốc.

#### Tính chất

Khi xử lý mảng có nhiều giá trị trùng lặp, sắp xếp nhanh ba đường hiệu quả hơn
rất nhiều so với sắp xếp nhanh nguyên bản. Độ phức tạp thời gian tốt nhất của
nó là $O(n)$.

#### Cài đặt

Sắp xếp nhanh ba đường rất dễ cài đặt; sau đây là một cài đặt C++ của sắp xếp
nhanh ba đường.

=== "C++"
    ```cpp
    // Tham số mẫu T biểu thị kiểu của phần tử; kiểu này cần định nghĩa toán tử nhỏ hơn (<)
    template <typename T>
    // arr là mảng cần được sắp xếp, len là độ dài mảng
    void quick_sort(T arr[], const int len) {
      if (len <= 1) return;
      // Chọn ngẫu nhiên pivot
      const T pivot = arr[rand() % len];
      // i: chỉ số của phần tử đang xử lý
      // arr[0, j): lưu các phần tử nhỏ hơn pivot
      // arr[k, len): lưu các phần tử lớn hơn pivot
      int i = 0, j = 0, k = len;
      // Hoàn thành một lượt quicksort ba đường, chia dãy thành:
      // phần tử nhỏ hơn pivot | phần tử bằng pivot | phần tử lớn hơn pivot
      while (i < k) {
        if (arr[i] < pivot)
          swap(arr[i++], arr[j++]);
        else if (pivot < arr[i])
          swap(arr[i], arr[--k]);
        else
          i++;
      }
      // Đệ quy hoàn tất sắp xếp nhanh trên hai dãy con
      quick_sort(arr, j);
      quick_sort(arr + k, len - k);
    }
    ```

=== "Python[^ref2]"
    ```python
    def quick_sort(arr, l, r):
        if l >= r:
            return
        random_index = random.randint(l, r)
        pivot = arr[random_index]
        arr[l], arr[random_index] = arr[random_index], arr[l]
        i = l + 1
        j = l
        k = r + 1
        while i < k:
            if arr[i] < pivot:
                arr[i], arr[j + 1] = arr[j + 1], arr[i]
                j += 1
                i += 1
            elif arr[i] > pivot:
                arr[i], arr[k - 1] = arr[k - 1], arr[i]
                k -= 1
            else:
                i += 1
        arr[l], arr[j] = arr[j], arr[l]
        quick_sort(arr, l, j - 1)
        quick_sort(arr, k, r)
    ```

### Sắp xếp nội quan

#### Định nghĩa

Sắp xếp nội quan (introsort hoặc introspective sort)[^ref4] là sự kết hợp giữa
sắp xếp nhanh và [sắp xếp vun đống](./heap-sort.md), do David Musser phát minh
năm 1997. Sắp xếp nội quan thực chất là một dạng tối ưu hóa của sắp xếp nhanh,
bảo đảm độ phức tạp thời gian xấu nhất là $O(n\log n)$.

#### Tính chất

Sắp xếp nội quan giới hạn độ sâu đệ quy tối đa của sắp xếp nhanh ở
$\lfloor \log_2n \rfloor$; nếu vượt quá giới hạn thì chuyển sang sắp xếp vun
đống. Cách này vừa giữ được tính cục bộ trong truy cập bộ nhớ của sắp xếp
nhanh, vừa ngăn sắp xếp nhanh suy giảm hiệu năng thành $O(n^2)$ trong một số
trường hợp.

#### Cài đặt

Từ tháng 6 năm 2000, phần cài đặt hàm `sort()` trong `stl_algo.h` của SGI C++
STL đã sử dụng thuật toán sắp xếp nội quan.

## Tìm tuyến tính phần tử hạng k

Trong ví dụ mã sau, phần tử hạng $k$ được định nghĩa là số ở vị trí thứ $k$ khi
dãy được sắp xếp tăng dần (đánh số từ 0).

Để tìm phần tử hạng $k$ (K-th order statistic), cách đơn giản nhất là sắp xếp
trước rồi trực tiếp lấy phần tử ở vị trí hạng $k$. Cách làm này có độ phức tạp
thời gian $O(n\log n)$, không hiệu quả đối với bài toán này.

Có thể mượn ý tưởng của sắp xếp nhanh để giải bài toán. Xét quá trình phân
hoạch của sắp xếp nhanh: sau khi quá trình "phân hoạch" kết thúc, dãy
$A_{p} \cdots A_{r}$ được chia thành $A_{p} \cdots A_{q}$ và
$A_{q+1} \cdots A_{r}$. Khi đó có thể dựa vào số lượng phần tử bên trái
($q - p + 1$) và quan hệ lớn nhỏ với $k$ để quyết định chỉ đệ quy giải ở bên
trái hay chỉ ở bên phải.

Giống như sắp xếp nhanh, độ phức tạp thời gian của phương pháp này phụ thuộc
vào giá trị mốc được chọn trong mỗi lần phân hoạch. Nếu chọn mốc ngẫu nhiên, có
thể chứng minh theo nghĩa kỳ vọng rằng độ phức tạp thời gian của chương trình
là $O(n)$.

### Cài đặt (C++)

```cpp
// Tham số mẫu T biểu thị kiểu của phần tử; kiểu này cần định nghĩa toán tử nhỏ hơn (<)
template <typename T>
// arr là mảng trong phạm vi tìm kiếm, rk là hạng cần tìm (tính từ 0), len là độ dài mảng
T find_kth_element(T arr[], int rk, const int len) {
  if (len <= 1) return arr[0];
  // Chọn ngẫu nhiên pivot
  const T pivot = arr[rand() % len];
  // i: chỉ số của phần tử đang xử lý
  // arr[0, j): lưu các phần tử nhỏ hơn pivot
  // arr[k, len): lưu các phần tử lớn hơn pivot
  int i = 0, j = 0, k = len;
  // Hoàn thành một lượt quicksort ba đường, chia dãy thành:
  // phần tử nhỏ hơn pivot | phần tử bằng pivot | phần tử lớn hơn pivot
  while (i < k) {
    if (arr[i] < pivot)
      swap(arr[i++], arr[j++]);
    else if (pivot < arr[i])
      swap(arr[i], arr[--k]);
    else
      i++;
  }
  // Dựa vào hạng cần tìm và vị trí của hai đường phân cách để đệ quy tìm phần tử hạng k trong đoạn tương ứng
  // Nếu số phần tử nhỏ hơn pivot nhiều hơn k, thì phần tử hạng k là một phần tử nhỏ hơn pivot
  if (rk < j) return find_kth_element(arr, rk, j);
  // Ngược lại, nếu tổng số phần tử nhỏ hơn pivot và bằng pivot vẫn không nhiều đến k,
  // thì phần tử hạng k là một phần tử lớn hơn pivot
  else if (rk >= k)
    return find_kth_element(arr + k, rk - k, len - k);
  // Nếu không, pivot chính là phần tử hạng k
  return pivot;
}
```

### Cải tiến: trung vị của các trung vị

Trung vị của các trung vị (median of medians) cung cấp một cách chọn
giá trị mốc xác định trong quá trình phân hoạch, nhờ đó thuật toán tìm phần tử
hạng $k$ cũng đạt độ phức tạp thời gian tuyến tính trong trường hợp xấu nhất.

Quy trình của thuật toán như sau:

1.  Chia toàn bộ dãy thành $\left \lfloor \dfrac{n}{5} \right \rfloor$ nhóm, mỗi nhóm có không quá 5 phần tử;
2.  Tìm trung vị của mỗi nhóm phần tử (vì số phần tử ít, có thể dùng trực tiếp
    các thuật toán như [sắp xếp chèn](./insertion-sort.md)).
3.  Tìm trung vị trong các trung vị của
    $\left \lfloor \dfrac{n}{5} \right \rfloor$ nhóm phần tử này. Dùng phần tử
    đó làm giá trị mốc trong mỗi lần phân hoạch của thuật toán nói trên.

#### Chứng minh độ phức tạp thời gian

Sau đây là phần chứng minh thuật toán này có độ phức tạp thời gian xấu nhất là
$O(n)$. Gọi $T(n)$ là lượng tính toán cần thiết để giải bài toán có kích thước
$n$.

Trước hết phân tích hai bước đầu: chia nhóm và tìm trung vị. Vì số phần tử
trong mỗi nhóm sau khi chia rất ít, có thể xem thời gian tìm trung vị của một
nhóm phần tử là $O(1)$. Do đó thời gian tìm ra trung vị của tất cả
$\left \lfloor \dfrac{n}{5} \right \rfloor$ nhóm phần tử là $O(n)$.

Tiếp theo phân tích bước thứ ba: quá trình đệ quy. Bước này thực hiện hai lời
gọi đệ quy: lần thứ nhất tìm trung vị của các trung vị trong từng nhóm, với chi
phí tương ứng là $T(\dfrac{n}{5})$; lần thứ hai đi vào phần bên trái hoặc bên
phải của giá trị mốc. Theo phần tử phân hoạch đã chọn, có
$\dfrac{1}{2} \times \left \lfloor \dfrac{n}{5} \right \rfloor =
\left \lfloor \dfrac{n}{10} \right \rfloor$ nhóm có trung vị nhỏ hơn giá trị
mốc. Trong các nhóm này, những phần tử nhỏ hơn trung vị cũng nhỏ hơn
giá trị mốc, nên trong toàn bộ dãy có ít nhất
$3 \times \left \lfloor \dfrac{n}{10} \right \rfloor =
\left \lfloor \dfrac{3n}{10} \right \rfloor$ phần tử nhỏ hơn giá trị mốc.
Tương tự, toàn bộ dãy cũng có ít nhất
$\left \lfloor \dfrac{3n}{10} \right \rfloor$ phần tử lớn hơn giá trị mốc. Vì
vậy, bên trái hoặc bên phải của giá trị mốc có nhiều nhất $\dfrac{7n}{10}$ phần
tử, và cận trên cho chi phí thời gian của lần đệ quy này là
$T(\dfrac{7n}{10})$.

Tổng hợp lại, có thể viết bất đẳng thức:

$$
T(n) \leq T(\dfrac{n}{5}) + T(\dfrac{7n}{10}) + O(n)
$$

Giả sử $T(n) = O(n)$ đúng khi kích thước bài toán đủ nhỏ. Theo định nghĩa, khi
đó có $T(n) \leq cn$, trong đó $c$ là một hằng số dương. Thay tất cả $T(n)$ ở
vế phải của bất đẳng thức:

$$
\begin{aligned}
T(n) & \leq T(\dfrac{n}{5}) + T(\dfrac{7n}{10}) + O(n)\\
     & \leq \dfrac{cn}{5} + \dfrac{7cn}{10} + O(n)\\
     & \leq \dfrac{9cn}{10} + O(n)\\
     & = O(n)
\end{aligned}
$$

Đến đây đã chứng minh thuật toán này cũng có độ phức tạp thời gian $O(n)$ trong
trường hợp xấu nhất.

## Tài liệu tham khảo và chú thích

[^ref1]: [Nguyên lý cục bộ trong hiệu năng C++ - I'm Root lee !](http://irootlee.com/juicer_locality/)

[^ref2]: [Algorithm Implementation / Sorting / Quicksort - Wikibooks](https://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort)

[^ref3]: [Ba dạng sắp xếp nhanh và tối ưu hóa sắp xếp nhanh](https://blog.csdn.net/insistGoGo/article/details/7785038)

[^ref4]: [introsort](https://en.wikipedia.org/wiki/Introsort)
