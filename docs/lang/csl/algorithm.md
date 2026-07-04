STL cung cấp khoảng 100 hàm template hiện thực thuật toán; phần lớn nằm trong
`<algorithm>`, một phần khác nằm trong `<numeric>` và `<functional>`. Danh sách
hàm đầy đủ có thể [xem trong sổ tay tham khảo](https://en.cppreference.com/w/cpp/algorithm);
các hàm liên quan đến sắp xếp có thể xem thêm ở [trang tương ứng về sắp xếp](../../basic/stl-sort.md).

-   `find`: tìm kiếm tuần tự. `find(v.begin(), v.end(), value)`, trong đó
    `value` là giá trị cần tìm.

-   `reverse`: đảo ngược mảng hoặc chuỗi. `reverse(v.begin(), v.end())` hoặc
    `reverse(a + begin, a + end)`.

-   `unique`: loại bỏ các phần tử trùng nhau liền kề trong container.
    `unique(ForwardIterator first, ForwardIterator last)` trả về iterator trỏ
    đến cuối container **sau khi loại trùng**, còn kích thước container gốc
    không đổi. Kết hợp với `sort` có thể loại trùng toàn bộ container.

-   `random_shuffle`: xáo trộn ngẫu nhiên mảng. `random_shuffle(v.begin(),
    v.end())` hoặc `random_shuffle(v + begin, v + end)`.

    ???+ warning "Hàm `random_shuffle` đã bị loại bỏ khỏi chuẩn C++ mới nhất"
        `random_shuffle` bị deprecated từ C++14 và bị loại bỏ từ C++17.
        
        Trong C++11 và các chuẩn mới hơn, bạn có thể dùng hàm `shuffle` thay
        cho `random_shuffle` cũ. Cách dùng là `shuffle(v.begin(), v.end(), rng)`;
        tham số cuối truyền vào bộ sinh số ngẫu nhiên, thường dùng Mersenne
        Twister [`mt19937`](https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine)
        được seed bằng bộ sinh số ngẫu nhiên thật [`random_device`](https://en.cppreference.com/w/cpp/numeric/random/random_device).
        
        ```cpp
        // #include <random>
        std::mt19937 rng(std::random_device{}());
        std::shuffle(v.begin(), v.end(), rng);
        ```

-   `sort`: sắp xếp. `sort(v.begin(), v.end(), cmp)` hoặc
    `sort(a + begin, a + end, cmp)`, trong đó `end` là vị trí sau phần tử cuối
    của mảng cần sắp xếp, còn `cmp` là hàm so sánh tự định nghĩa.

-   `stable_sort`: sắp xếp ổn định, cách dùng giống `sort()`.

-   `nth_element`: phân hoạch theo phạm vi chỉ định, tức tìm phần tử lớn thứ $n$
    trong dãy sao cho các phần tử bên trái đều nhỏ hơn nó và các phần tử bên
    phải đều lớn hơn nó. `nth_element(v.begin(), v.begin() + n, v.end(), cmp)`
    hoặc `nth_element(a + begin, a + begin + n, a + end, cmp)`.

-   `binary_search`: tìm kiếm nhị phân. `binary_search(v.begin(), v.end(),
    value)`, trong đó `value` là giá trị cần tìm.

-   `merge`: **gộp có thứ tự** hai dãy đã sắp xếp vào **insertion iterator** của
    dãy thứ ba. `merge(v1.begin(), v1.end(), v2.begin(), v2.end(),
    back_inserter(v3))`.

-   `inplace_merge`: **gộp tại chỗ thành một dãy có thứ tự** hai phạm vi đã được
    sắp theo toán tử nhỏ hơn: `[first,middle), [middle,last)`.
    `inplace_merge(v.begin(), v.begin() + middle, v.end())`.

-   `lower_bound`: tìm kiếm nhị phân trong một dãy có thứ tự, trả về iterator
    trỏ đến vị trí của phần tử đầu tiên **lớn hơn hoặc bằng** $x$. Nếu không tồn
    tại phần tử như vậy thì trả về iterator cuối. `lower_bound(v.begin(),
    v.end(), x)`.

-   `upper_bound`: tìm kiếm nhị phân trong một dãy có thứ tự, trả về iterator
    trỏ đến vị trí của phần tử đầu tiên **lớn hơn** $x$. Nếu không tồn tại phần
    tử như vậy thì trả về iterator cuối. `upper_bound(v.begin(), v.end(), x)`.

    ???+ warning "Độ phức tạp thời gian của `lower_bound` và `upper_bound`"
        Trên mảng thông thường, độ phức tạp thời gian của hai hàm này đều là
        $O(\log n)$. Nhưng trong container kết hợp như `set`, gọi trực tiếp
        `lower_bound(s.begin(), s.end(), val)` có độ phức tạp $O(n)$.
        
        Các container kết hợp như `set` đã đóng gói các hàm như `lower_bound`
        (ví dụ `s.lower_bound(val)`); gọi theo cách này có độ phức tạp
        $O(\log n)$.

-   `next_permutation`: đổi hoán vị hiện tại thành **hoán vị kế tiếp trong toàn
    bộ các hoán vị**. Nếu hoán vị hiện tại đã là **hoán vị cuối cùng** (các phần
    tử xếp hoàn toàn giảm dần), hàm trả về `false` và đổi hoán vị thành **hoán
    vị đầu tiên** (các phần tử xếp hoàn toàn tăng dần); ngược lại, hàm trả về
    `true`. `next_permutation(v.begin(), v.end())` hoặc
    `next_permutation(v + begin, v + end)`.

-   `prev_permutation`: đổi hoán vị hiện tại thành **hoán vị trước đó trong toàn
    bộ các hoán vị**. Cách dùng giống `next_permutation`.

-   `partial_sum`: tính tổng tiền tố. Giả sử container nguồn là $x$, container
    đích là $y$, khi đó đặt $y[i]=x[0]+x[1]+\dots+x[i]$.
    `partial_sum(src.begin(), src.end(), back_inserter(dst))`.

### Ví dụ sử dụng

-   Dùng `next_permutation` sinh toàn bộ hoán vị của $1$ đến $9$. Bài ví dụ:
    [Luogu P1706 Toàn hoán vị](https://www.luogu.com.cn/problem/P1706)

    ???+ note "Hiện thực"
        ```cpp
        int N = 9, a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        do {
          for (int i = 0; i < N; i++) cout << a[i] << " ";
          cout << endl;
        } while (next_permutation(a, a + N));
        ```
-   Dùng `lower_bound` và `upper_bound` tìm ranh giới giữa các phần tử nhỏ hơn
    $x$, bằng $x$, và lớn hơn $x$ trong mảng có thứ tự $a$.

    ???+ note "Hiện thực"
        ```cpp
        int N = 10, a[] = {1, 1, 2, 4, 5, 5, 7, 7, 9, 9}, x = 5;
        int i = lower_bound(a, a + N, x) - a, j = upper_bound(a, a + N, x) - a;
        // a[0] ~ a[i - 1] là các phần tử nhỏ hơn x, a[i] ~ a[j - 1] là các phần tử bằng x,
        // a[j] ~ a[N - 1] là các phần tử lớn hơn x
        cout << i << " " << j << endl;
        ```
-   Dùng `partial_sum` tính tổng tiền tố các phần tử trong $src$ và lưu vào
    $dst$.

    ???+ note "Hiện thực"
        ```cpp
        vector<int> src = {1, 2, 3, 4, 5}, dst;
        // Tính tổng tiền tố của các phần tử trong src, dst[i] = src[0] + ... + src[i]
        // Hàm back_inserter tác động lên container dst và cung cấp một iterator
        partial_sum(src.begin(), src.end(), back_inserter(dst));
        for (unsigned int i = 0; i < dst.size(); i++) cout << dst[i] << " ";
        ```
-   Dùng `lower_bound` tìm phần tử gần $x$ nhất trong mảng có thứ tự $a$. Bài ví
    dụ: [UVa10487 Closest Sums](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1428)

    ???+ note "Hiện thực"
        ```cpp
        int N = 10, a[] = {1, 1, 2, 4, 5, 5, 8, 8, 9, 9}, x = 6;
        // lower_bound trả về địa chỉ của phần tử đầu tiên trong a lớn hơn hoặc bằng x; i là chỉ số tính được
        int i = lower_bound(a, a + N, x) - a;
        // Trong hai trường hợp sau, a[i] (phần tử đầu tiên trong a lớn hơn hoặc bằng x) là đáp án:
        // 1. Phần tử nhỏ nhất trong a cũng lớn hơn hoặc bằng x;
        // 2. Trong a tồn tại phần tử lớn hơn hoặc bằng x, và phần tử đầu tiên lớn hơn hoặc bằng x (a[i])
        // gần x hơn phần tử đầu tiên nhỏ hơn x (a[i - 1]);
        // Ngược lại, a[i - 1] (phần tử đầu tiên trong a nhỏ hơn x) là đáp án
        if (i == 0 || (i < N && a[i] - x < x - a[i - 1]))
          cout << a[i];
        else
          cout << a[i - 1];
        ```
-   Dùng `sort` và `unique` tìm **giá trị nhỏ thứ $k$** trong mảng $a$ (chú ý:
    giá trị lặp lại chỉ tính một lần, nên bài này không phải tìm phần tử nhỏ thứ
    $k$). Bài ví dụ: [Luogu P1138 Số nguyên nhỏ thứ k](https://www.luogu.com.cn/problem/P1138)

    ???+ note "Hiện thực"
        ```cpp
        int N = 10, a[] = {1, 3, 3, 7, 2, 5, 1, 2, 4, 6}, k = 3;
        sort(a, a + N);
        // unique trả về địa chỉ sau phần tử cuối của mảng sau khi loại trùng; cnt là độ dài mảng sau loại trùng
        int cnt = unique(a, a + N) - a;
        cout << a[k - 1];
        ```
