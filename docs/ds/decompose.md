author: Ir1d, HeRaNO, Xeonacid

<span id="giới-thiệu"></span>
## Giới thiệu

Chia khối (sqrt decomposition) là một tư tưởng thuật toán, không phải một cấu trúc dữ liệu cụ thể.

Từ NOIP đến NOI rồi IOI, tư tưởng chia khối xuất hiện trong nhiều bài với độ khó khác nhau.

Ý tưởng cơ bản của chia khối là chia dữ liệu gốc thành các phần phù hợp,
rồi tiền xử lý một số thông tin trên mỗi khối,
qua đó đạt độ phức tạp thời gian tốt hơn thuật toán vét cạn thông thường.

Độ phức tạp thời gian của chia khối chủ yếu phụ thuộc vào độ dài khối.
Thông thường có thể dùng bất đẳng thức trung bình để tìm độ dài khối tối ưu cho một bài toán cụ thể,
cũng như độ phức tạp thời gian tương ứng.

Chia khối là một tư tưởng rất linh hoạt.
So với cây Fenwick và cây đoạn, ưu điểm của chia khối là tính tổng quát cao hơn:
nó có thể duy trì nhiều loại thông tin mà cây Fenwick và cây đoạn khó xử lý.

Nhược điểm của chia khối là độ phức tạp tiệm cận thường không tốt bằng cây đoạn hay cây Fenwick.

Tuy vậy, trong phần lớn bài toán phù hợp, chia khối vẫn là một lựa chọn hiệu quả.

Dưới đây là một vài ví dụ.

<span id="tổng-đoạn"></span>
## Tổng đoạn

??? note "Ví dụ [LibreOJ 6280 Nhập môn chia khối dãy số 4](https://loj.ac/problem/6280)"
    Cho một dãy độ dài $n$ là $\{a_i\}$, cần thực hiện $n$ thao tác. Có hai loại thao tác:
    
    1.  Cộng $x$ vào tất cả các số từ $a_l$ đến $a_r$;
    2.  Tính $\sum_{i=l}^r a_i$.
    
        $1 \leq n \leq 5 \times 10^4$

Chia dãy thành các khối, mỗi khối có $s$ phần tử,
và ghi lại tổng đoạn của mỗi khối là $b_i$.

$$
\underbrace{a_1, a_2, \ldots, a_s}_{b_1},
\underbrace{a_{s+1}, \ldots, a_{2s}}_{b_2},
\dots,
\underbrace{a_{(s-1) \times s+1}, \dots, a_n}_{b_{\frac{n}{s}}}
$$

Khối cuối có thể không đầy đủ vì $n$ rất có thể không phải bội của $s$,
nhưng điều này không ảnh hưởng nhiều đến phần thảo luận.

Trước hết xét thao tác truy vấn:

-   Nếu $l$ và $r$ nằm trong cùng một khối, chỉ cần tính tổng trực tiếp bằng vét cạn.
    Vì độ dài khối là $s$, độ phức tạp xấu nhất là $O(s)$.
-   Nếu $l$ và $r$ không nằm trong cùng một khối,
    đáp án gồm ba phần:
    khối không đầy đủ bắt đầu từ $l$,
    một vài khối đầy đủ ở giữa,
    và khối không đầy đủ kết thúc tại $r$.
    Với các khối không đầy đủ, vẫn tính trực tiếp như trên;
    với các khối đầy đủ, chỉ cần cộng trực tiếp các tổng $b_i$ đã tính sẵn.
    Trong trường hợp này, độ phức tạp xấu nhất là $O(\dfrac{n}{s}+s)$.

Tiếp theo là thao tác cập nhật:

-   Nếu $l$ và $r$ nằm trong cùng một khối, chỉ cần sửa trực tiếp bằng vét cạn.
    Vì độ dài khối là $s$, độ phức tạp xấu nhất là $O(s)$.
-   Nếu $l$ và $r$ không nằm trong cùng một khối,
    cần sửa ba phần:
    khối không đầy đủ bắt đầu từ $l$,
    một vài khối đầy đủ ở giữa,
    và khối không đầy đủ kết thúc tại $r$.
    Với các khối không đầy đủ,
    vẫn sửa giá trị từng phần tử bằng vét cạn và cập nhật tổng đoạn $b_i$;
    với các khối đầy đủ, chỉ cần sửa trực tiếp tổng khối $b_i$.
    Trong trường hợp này, độ phức tạp xấu nhất vẫn là $O(\dfrac{n}{s}+s)$.

Theo bất đẳng thức trung bình, khi $\dfrac{n}{s}=s$, tức $s=\sqrt n$, độ phức tạp thời gian cho một thao tác đạt giá trị
tối ưu $O(\sqrt n)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/decompose/decompose_1.cpp"
    ```

<span id="tổng-đoạn-2"></span>
## Tổng đoạn 2

Cách làm trước có độ phức tạp truy vấn/cập nhật là $O(\sqrt{n})$.

Phần này giới thiệu một thuật toán cập nhật $O(\sqrt{n})$, truy vấn $O(1)$.

Để truy vấn trong $O(1)$, có thể duy trì thêm các loại tổng tiền tố.

Tuy nhiên, khi có cập nhật thì việc duy trì toàn cục không thuận tiện;
thay vào đó chỉ duy trì tổng tiền tố bên trong từng khối.

Đồng thời, duy trì tổng tiền tố trên dãy các khối nguyên vẹn, trong đó mỗi khối được xem như một đơn vị.

Nếu độ dài khối là $T$, mỗi lần cập nhật tốn $O(T+\frac{n}{T})$.

Một truy vấn vẫn gồm ba phần; mỗi phần đều có thể lấy trực tiếp bằng tổng tiền tố, nên độ phức tạp thời gian là $O(1)$.

<span id="chia-khối-theo-truy-vấn"></span>
## Chia khối theo truy vấn

Vẫn là bài toán đó, bây giờ độ dài dãy là $n$ và có $m$ thao tác.

Nếu số thao tác tương đối ít,
có thể ghi lại các thao tác đó, rồi khi truy vấn thì cộng thêm ảnh hưởng của chúng.

Giả sử ghi lại tối đa $T$ thao tác, khi đó cập nhật là $O(1)$, truy vấn là $O(T)$.

Sau mỗi $T$ thao tác, tính lại tổng tiền tố, tốn $O(n)$.

Tổng độ phức tạp là $O(mT+n\frac{m}{T})$.

Khi $T=\sqrt{n}$, tổng độ phức tạp là $O(m \sqrt{n})$.

<span id="các-vấn-đề-khác"></span>
### Các vấn đề khác

Tư tưởng chia khối cũng có thể áp dụng cho nhiều bài toán liên quan đến số nguyên:
tìm số lượng phần tử bằng không,
tìm phần tử khác không đầu tiên,
đếm số phần tử thỏa mãn một tính chất nào đó, v.v.

Còn có một số bài toán khác có thể giải bằng chia khối,
chẳng hạn duy trì một tập các số cho phép thêm hoặc xóa,
kiểm tra một số có thuộc tập này hay không,
và tìm số lớn thứ $k$.
Để giải bài toán này, cần lưu các số theo thứ tự tăng dần và chia chúng thành nhiều khối,
mỗi khối chứa $\sqrt{n}$ số.
Mỗi khi thêm hoặc xóa một số,
cần chia khối lại bằng cách di chuyển các số ở biên giữa các khối kề nhau.

Một thuật toán ngoại tuyến rất nổi tiếng, [thuật toán Mo](../misc/mo-algo.md), cũng được xây dựng dựa trên tư tưởng chia
khối.

<span id="bài-tập"></span>
## Bài tập

-   [UVa - 12003 - Biến đổi mảng](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3154)
-   [UVa - 11990 Nghịch thế động](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3141)
-   [SPOJ - Cho đi](http://www.spoj.com/problems/GIVEAWAY/)
-   [Codeforces - Đến khi tôi gục ngã](http://codeforces.com/contest/786/problem/C)
-   [Codeforces - Định mệnh](http://codeforces.com/contest/840/problem/D)
-   [Codeforces - Lỗ](http://codeforces.com/contest/13/problem/E)
-   [Codeforces - XOR và con số yêu thích](https://codeforces.com/problemset/problem/617/E)
-   [Codeforces - Mảng mạnh](http://codeforces.com/problemset/problem/86/D)
-   [SPOJ - DQUERY](https://www.spoj.com/problems/DQUERY)

    **Trang này chủ yếu được dịch từ bài viết [Sqrt-декомпозиция](http://e-maxx.ru/algo/sqrt_decomposition) và bản dịch
    tiếng Anh [Phân rã căn](https://cp-algorithms.com/data_structures/sqrt_decomposition.html). Bản tiếng Nga được
    cấp phép theo Public Domain + Leave a Link; bản tiếng Anh được cấp phép theo CC-BY-SA 4.0.**
