Trang này giới thiệu ngắn gọn về thuật toán tham lam.

## Mở đầu

Thuật toán tham lam (greedy algorithm) là quá trình dùng máy tính mô phỏng một
người "tham lam" ra quyết định: ở mỗi bước luôn chọn thao tác tốt nhất theo một
tiêu chí nào đó. Đồng thời người này cũng thiển cận: chỉ nhìn lợi ích trước mắt
và không xét ảnh hưởng có thể xảy ra về sau.

Có thể hình dung rằng không phải lúc nào tham lam cũng cho nghiệm tối ưu. Vì
vậy khi dùng thuật toán tham lam, thường cần chứng minh được tính đúng đắn của
nó.

## Giải thích

### Phạm vi áp dụng

Thuật toán tham lam đặc biệt hiệu quả với những bài toán có cấu trúc con tối
ưu. Cấu trúc con tối ưu nghĩa là có thể tách bài toán thành các bài toán con,
rồi từ nghiệm tối ưu của các bài toán con suy ra nghiệm tối ưu của bài toán ban
đầu.[^ref1]

### Chứng minh

Có hai cách chứng minh thuật toán tham lam thường gặp: phản chứng và quy nạp.
Thông thường, một bài dùng một trong hai cách là đủ.

1.  Phản chứng: nếu sau khi đổi chỗ hai phần tử bất kỳ hoặc hai phần tử kề
    nhau trong phương án mà đáp án không tốt hơn, có thể suy ra nghiệm hiện tại
    đã là tối ưu.
2.  Quy nạp: trước hết tính nghiệm tối ưu $F_1$ của trường hợp biên, chẳng hạn
    $n = 1$, rồi chứng minh với mọi $n$, $F_{n+1}$ có thể được suy ra từ
    $F_n$.

## Điểm chính

### Dạng bài thường gặp

Trong các bài không quá nâng cao, hai dạng tham lam thường gặp nhất là:

-   "Sắp xếp XXX theo một thứ tự nào đó, rồi chọn theo một thứ tự nào đó, chẳng
    hạn từ nhỏ đến lớn."
-   "Mỗi lần lấy phần tử lớn nhất/nhỏ nhất trong XXX, rồi cập nhật XXX." Đôi
    khi phần "phần tử lớn nhất/nhỏ nhất trong XXX" có thể được cải thiện, ví dụ
    dùng hàng đợi ưu tiên để duy trì.

Khác biệt giữa hai dạng là: dạng đầu là xử lý ngoại tuyến, xử lý trước rồi chọn;
dạng sau là xử lý trực tuyến, vừa xử lý vừa chọn.

### Lời giải bằng sắp xếp

Tình huống thường gặp của phương pháp sắp xếp là: đầu vào là một mảng chứa vài
trọng số, thường là một hoặc hai trọng số, sau đó sắp xếp rồi duyệt mô phỏng để
tính giá trị tối ưu.

### Lời giải hối tiếc

Tư tưởng là tạm chấp nhận lựa chọn hiện tại bất kể nó có phải tối ưu hay không,
sau đó so sánh. Nếu sau khi chọn mà phương án không còn tối ưu, thuật toán
"hối tiếc" và loại bỏ lựa chọn này; nếu không thì chính thức chấp nhận. Lặp lại
quá trình đó.

## Khác biệt

### Khác với quy hoạch động

Điểm khác biệt giữa thuật toán tham lam và quy hoạch động là: tham lam đưa ra
lựa chọn cho mỗi bài toán con và không quay lui. Quy hoạch động thì lưu kết quả
tính toán trước đó, rồi dựa vào các kết quả đó để chọn ở trạng thái hiện tại,
nên có khả năng quay lui theo nghĩa rộng.

## Phân tích bài ví dụ

### Ví dụ dùng phương pháp đổi chỗ phần tử kề

???+ note "[NOIP 2012 Trò chơi nhà vua](https://www.luogu.com.cn/problem/P1080)"
    Đúng dịp quốc khánh nước H, nhà vua mời $n$ đại thần chơi một trò chơi có
    thưởng. Trước hết, ông yêu cầu mỗi đại thần viết một số nguyên lên tay trái
    và một số nguyên lên tay phải; bản thân nhà vua cũng viết một số nguyên lên
    mỗi tay. Sau đó, $n$ đại thần xếp thành một hàng, nhà vua đứng ở đầu hàng.
    Khi đã xếp xong, mọi đại thần đều nhận được một số đồng vàng do nhà vua
    thưởng. Số đồng vàng của mỗi đại thần bằng tích các số trên tay trái của
    tất cả những người đứng trước đại thần đó, chia cho số trên tay phải của
    chính đại thần đó, rồi lấy phần nguyên xuống.

    Nhà vua không muốn một đại thần nào nhận được phần thưởng đặc biệt lớn, nên
    muốn sắp xếp lại thứ tự hàng sao cho số vàng lớn nhất mà một đại thần nhận
    được là nhỏ nhất có thể. Lưu ý rằng vị trí của nhà vua luôn ở đầu hàng.

??? note "Ý tưởng giải"
    Giả sử sau khi sắp xếp, hai số trên tay trái và tay phải của đại thần thứ
    $i$ lần lượt là $a_i, b_i$. Xét cách suy ra chiến lược tham lam bằng phương
    pháp đổi chỗ hai phần tử kề.

    Gọi $s$ là tích các $a_i$ của tất cả những người đứng trước đại thần thứ
    $i$. Khi đó phần thưởng của đại thần thứ $i$ là $\dfrac{s}{b_i}$, còn phần
    thưởng của đại thần thứ $i+1$ là $\dfrac{s\cdot a_i}{b_{i+1}}$.

    Nếu đổi chỗ đại thần thứ $i$ và thứ $i+1$, khi đó phần thưởng của đại thần
    mới ở vị trí $i$ là $\dfrac{s}{b_{i+1}}$, còn phần thưởng của đại thần mới
    ở vị trí $i+1$ là $\dfrac{s\cdot a_{i+1}}{b_i}$.

    Thứ tự trước khi đổi tốt hơn khi và chỉ khi

    $$
    \max \left(\dfrac{s} {b_i}, \dfrac{s \cdot a_i} {b_{i+1}}\right)  < \max \left(\dfrac{s} {b_{i+1}}, \dfrac{s \cdot a_{i+1}} {b_i}\right)
    $$

    Tách nhân tử chung $s$ và rút gọn, thu được

    $$
    \max \left(\dfrac{1} {b_i}, \dfrac{a_i} {b_{i+1}}\right)  < \max \left(\dfrac{1} {b_{i+1}}, \dfrac{a_{i+1}} {b_i}\right)
    $$

    Chuyển phân thức thành biểu thức nguyên, thu được

    $$
    \max (b_{i+1}, a_i\cdot b_i)  < \max (b_i, a_{i+1}\cdot b_{i+1})
    $$

    Khi cài đặt, lưu hai số đầu vào bằng một struct và nạp chồng toán tử:

    ```cpp
    struct uv {
      int a, b;

      bool operator<(const uv &x) const {
        return max(x.b, a * b) < max(b, x.a * x.b);
      }
    };
    ```

### Ví dụ dùng phương pháp hối tiếc

???+ note "[USACO09OPEN Work Scheduling](https://www.luogu.com.cn/problem/P2949)"
    Ngày làm việc của John bắt đầu từ thời điểm $0$ và có $10^9$ đơn vị thời
    gian. Ở mỗi đơn vị thời gian, anh có thể chọn hoàn thành một trong $N$ công
    việc được đánh số từ $1$ đến $N$ với $N(1 \leq N \leq 10^5)$. Công việc
    $i$ có hạn chót $D_i(1 \leq D_i \leq 10^9)$ và lợi nhuận sau khi hoàn thành
    là $P_i(1\leq P_i\leq 10^9)$. Với lợi nhuận và hạn chót đã cho, tính lợi
    nhuận lớn nhất John có thể đạt được.

??? note "Ý tưởng giải"
    1.  Trước hết giả sử mọi công việc đều được làm, sắp xếp các công việc theo
        hạn chót rồi đưa vào hàng đợi.
    2.  Khi xét công việc thứ `i` có làm hay không, nếu hạn chót của nó thỏa
        điều kiện, so sánh nó với phần tử có thù lao nhỏ nhất trong hàng đợi.
        Nếu công việc thứ `i` có thù lao cao hơn, tức là nên "hối tiếc" lựa
        chọn trước đó, cập nhật `ans += a[i].p - q.top()`.
        Dùng hàng đợi ưu tiên dạng min-heap để duy trì phần tử nhỏ nhất ở đầu.
    3.  Điều kiện `a[i].d<=q.size()` có thể hiểu như sau: từ thời điểm 0 đến
        `a[i].d` chỉ có thể làm `a[i].d` công việc. Nếu `q.size()>=a[i].d`,
        nghĩa là thời gian cần để hoàn thành `q.size()` công việc đã lớn hơn
        hoặc bằng `a[i].d`. Vì vậy khi công việc thứ `i` có lợi nhuận lớn hơn,
        nên thay công việc nhỏ nhất trong hàng đợi ưu tiên ra ngoài.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/basic/code/greedy/greedy_1.cpp"
        ```

    === "Python"
        ```python
        --8<-- "docs/basic/code/greedy/greedy_1.py"
        ```

??? note "Phân tích độ phức tạp"
    -   Độ phức tạp bộ nhớ: khi nhập $n$ công việc, dùng $n$ phần tử mảng `a`.
        Trong trường hợp bất lợi nhất, hàng đợi ưu tiên cũng lưu $n$ phần tử,
        nên độ phức tạp bộ nhớ là $O(n)$.
    -   Độ phức tạp thời gian: `std::sort` có độ phức tạp $O(n\log n)$, việc
        duy trì hàng đợi ưu tiên cũng có độ phức tạp $O(n\log n)$. Tổng hợp
        lại, độ phức tạp thời gian là $O(n\log n)$.

## Bài tập

-   [P1209\[USACO1.3\] Barn Repair - Luogu](https://www.luogu.com.cn/problem/P1209)
-   [P2123 Trò chơi hoàng hậu - Luogu](https://www.luogu.com.cn/problem/P2123)
-   [Các bài có nhãn greedy trên LeetCode](https://leetcode-cn.com/tag/greedy/)

## Tài liệu tham khảo và ghi chú

[^ref1]: [Greedy algorithm - Wikipedia](https://en.wikipedia.org/wiki/Greedy_algorithm)
