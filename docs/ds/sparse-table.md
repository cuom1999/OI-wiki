## Định nghĩa

![Sơ đồ minh họa bảng ST](images/st.svg)

Bảng ST (Sparse Table, bảng thưa) là cấu trúc dữ liệu dùng để giải các **bài toán có đóng góp lặp lại**.

???+ note "Bài toán có đóng góp lặp lại là gì?"
    **Bài toán có đóng góp lặp lại** là bài toán mà phép toán $\operatorname{opt}$ thỏa mãn
    $x\operatorname{opt} x=x$. Khi đó, truy vấn đoạn tương ứng cho phép một phần tử được "đóng góp" nhiều lần mà kết quả
    không đổi. Ví dụ, phép lấy giá trị lớn nhất có $\max(x,x)=x$, phép gcd có $\operatorname{gcd}(x,x)=x$, nên RMQ và
    GCD trên đoạn đều thuộc loại này. Ngược lại, tổng trên đoạn không có tính chất đó: nếu các đoạn đã tiền xử lý bị
    chồng lấn khi tính tổng, phần chồng lấn sẽ bị cộng hai lần. Ngoài ra, $\operatorname{opt}$ còn phải thỏa mãn tính
    kết hợp thì mới có thể dùng bảng ST để giải.

???+ note "RMQ là gì?"
    RMQ thường là viết tắt của Range Minimum Query, tức truy vấn giá trị nhỏ nhất trên đoạn. Trong nhiều tài liệu thi
    lập trình, thuật ngữ này cũng được dùng rộng hơn cho Range Maximum/Minimum Query, tức truy vấn giá trị lớn
    nhất/nhỏ nhất trên đoạn. Có nhiều cách giải bài toán RMQ; có thể tham khảo [chuyên đề RMQ](../topic/rmq.md).

## Dẫn nhập

???+ example "[Luogu P3865【Mẫu】Bảng ST & bài toán RMQ](https://www.luogu.com.cn/problem/P3865)"
    Cho $n$ ($1\le n\le 10^5$) số nguyên và $m$ ($1\le m\le 2\times 10^6$) truy vấn. Với mỗi truy vấn, cần trả lời giá
    trị lớn nhất trong đoạn $[l,r]$.

Xét cách làm vét cạn: với mỗi truy vấn, quét toàn bộ đoạn $[l,r]$ để tìm giá trị lớn nhất.

Cách này không đáp ứng được giới hạn thời gian.

## Bảng ST

Bảng ST dựa trên tư tưởng [nhân đôi](../basic/binary-lifting.md), có thể tiền xử lý trong $\Theta(n\log n)$ và trả lời
mỗi truy vấn trong $\Theta(1)$. Tuy nhiên, cấu trúc này không hỗ trợ thao tác cập nhật.

Dựa trên tư tưởng nhân đôi, xét cách tìm giá trị lớn nhất trên đoạn. Nếu làm theo quy trình nhân đôi thông thường, mỗi
lần nhảy $2^i$ bước, độ phức tạp truy vấn vẫn là $\Theta(\log n)$. Mức này không tốt hơn cây phân đoạn, trong khi bước
tiền xử lý còn chậm hơn cây phân đoạn.

Vì $\max(x,x)=x$, bài toán giá trị lớn nhất trên đoạn có tính chất "đóng góp lặp lại". Do đó, ngay cả khi các đoạn tiền
xử lý dùng để trả lời truy vấn có phần chồng lấn, miễn là hợp của chúng đúng bằng đoạn cần hỏi, đáp án cuối cùng vẫn
chính xác.

Từ cách phủ này, nhiều nhất hai đoạn đã tiền xử lý là đủ để bao phủ đoạn truy vấn. Do đó, độ phức tạp truy vấn có thể
giảm xuống $\Theta(1)$, rất hiệu quả trong các bài có nhiều truy vấn.

Cách cài đặt cụ thể như sau:

Gọi $f(i,j)$ là giá trị lớn nhất trong đoạn $[i,i+2^j-1]$.

Theo định nghĩa, $f(i,0)=a_i$.

Theo định nghĩa, chiều thứ hai tương ứng với việc "nhảy $2^j-1$ bước" trong nhân đôi. Dựa trên tư tưởng nhân đôi, có
phương trình chuyển trạng thái: $f(i,j)=\max(f(i,j-1),f(i+2^{j-1},j-1))$.

![](./images/st-preprocess-lift.svg)

Đó là phần tiền xử lý. Phần truy vấn có thể cài đặt như sau:

Với mỗi truy vấn $[l,r]$, chia nó thành hai phần: $[l,l+2^s-1]$ và $[r-2^s+1,r]$, trong đó
$s=\left\lfloor\log_2(r-l+1)\right\rfloor$. Giá trị lớn nhất của kết quả trên hai phần này chính là đáp án.

![Quá trình truy vấn của bảng ST](./images/st-query.svg)

Theo lập luận về "bài toán có đóng góp lặp lại", phép lấy giá trị lớn nhất không bị ảnh hưởng bởi phần chồng lấn. Đồng
thời, hai đoạn nói trên phủ hoàn toàn $[l,r]$, nên đáp án thu được là đúng.

???+ example "[Luogu P3865【Mẫu】Bảng ST & bài toán RMQ](https://www.luogu.com.cn/problem/P3865) Cài đặt tham khảo"
    === "Phong cách C"
        ```cpp
        --8<-- "docs/ds/code/sparse-table/sparse-table_1.cpp"
        ```
    
    === "Phong cách C++"
        ```cpp
        --8<-- "docs/ds/code/sparse-table/sparse-table_2.cpp"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/ds/code/sparse-table/sparse-table_1.py"
        ```

## Lưu ý

1.  Dữ liệu vào/ra thường rất lớn, nên bật tối ưu nhập xuất.

2.  Khi tiền xử lý bảng ST, thường cần tạo một mảng có một chiều kích thước $\log n$ và chiều còn lại kích thước $n$.
    Khi đó nên ưu tiên đặt chiều có kích thước $\log n$ làm chiều thứ nhất để cải thiện tính cục bộ bộ nhớ đệm.

3.  Không đáng để dùng [std::log](https://en.cppreference.com/w/cpp/numeric/math/log) tính lại giá trị logarit mỗi lần.
    Nên dùng các hàm nội tại như `__builtin_clz` hoặc `__lg` để tính. Nếu không dùng được các hàm này, có thể tiền xử
    lý giá trị logarit như sau:

$$
\begin{cases}
\texttt{Logn}[1] \gets 0, \\
\texttt{Logn}\left[i\right] \gets \texttt{Logn}\left[\frac{i}{2}\right] + 1.
\end{cases}
$$

## Dùng bảng ST để duy trì thông tin khác

Ngoài RMQ, còn có các "bài toán có đóng góp lặp lại" khác. Chẳng hạn, "phép AND bit trên đoạn", "phép OR bit trên
đoạn", "GCD trên đoạn" đều có thể được giải hiệu quả bằng bảng ST.

Cần lưu ý rằng với "GCD trên đoạn", độ phức tạp truy vấn của bảng ST không tốt hơn cây phân đoạn. Gọi miền giá trị là
$w$, độ phức tạp truy vấn của bảng ST là $\Theta(\log w)$, còn cây phân đoạn là $\Theta(\log n+\log w)$, và miền giá
trị thường lớn hơn $n$. Tuy nhiên, độ phức tạp tiền xử lý của bảng ST cũng không kém hơn cây phân đoạn, trong khi độ
phức tạp cài đặt của bảng ST đơn giản hơn cây phân đoạn rất nhiều.

Nếu phân tích sâu hơn, các "bài toán có đóng góp lặp lại" thường chứa một thành phần tương tự RMQ. Ví dụ, "AND bit
trên đoạn" tương đương với lấy giá trị nhỏ nhất trên từng bit, còn "GCD trên đoạn" tương đương với lấy số mũ nhỏ nhất
của từng thừa số nguyên tố.

## Tổng kết

Bảng ST duy trì tốt các thông tin trên đoạn có tính chất "đóng góp lặp lại" (đồng thời cũng cần thỏa mãn tính kết hợp),
có độ phức tạp thời gian thấp và lượng mã tương đối nhỏ so với nhiều thuật toán khác. Tuy vậy, loại thông tin mà bảng
ST duy trì được khá hạn chế, khó mở rộng tốt, và không hỗ trợ thao tác cập nhật.

## Bài tập

-   [SCOI2007 Lượng mưa](https://loj.ac/p/2279)

-   [\[USACO07JAN\] Đội hình cân bằng Balanced Lineup](https://www.luogu.com.cn/problem/P2880)

## Phụ lục: Phân tích độ phức tạp thời gian khi dùng bảng ST tìm GCD trên đoạn

Khi thuật toán chạy, có thể cần trải qua $\Theta(\log n)$ lần lặp. Mỗi lần lặp đều có thể gọi đệ quy hàm GCD. Gọi miền
giá trị là $w$, độ phức tạp thời gian của hàm GCD trong trường hợp lớn nhất là $\Omega(\log w)$, nên thoạt nhìn tổng độ
phức tạp có vẻ là $O(n\log n\log w)$.

Tuy nhiên, trong quá trình tính GCD, mỗi lần đệ quy (ngoại trừ lần đệ quy cuối cùng) đều làm cho một số nào đó trong dãy
giảm ít nhất một nửa. Tổng số lần các số trong dãy có thể bị giảm một nửa nhiều nhất là
$\log_2 (w^n)=\Theta(n\log w)$. Vì vậy, phần đệ quy của GCD nhiều nhất chỉ chạy $O(n\log w)$ lần. Cộng thêm phần vòng
lặp (và tầng đệ quy cuối cùng) có độ phức tạp $\Theta(n\log n)$, độ phức tạp thời gian cuối cùng là
$O(n(\log w+\log n))$. Do có thể xây dựng dữ liệu khiến độ phức tạp đạt $\Omega(n(\log w+\log n))$, độ phức tạp cuối
cùng là $\Theta(n(\log w+\log n))$.

Độ phức tạp của phần truy vấn dễ phân tích hơn. Xét trường hợp xấu nhất, tức mỗi truy vấn đều hỏi đúng một cặp số xấu
nhất, độ phức tạp là $\Theta(\log w)$. Do đó, khi bảng ST duy trì "GCD trên đoạn", độ phức tạp tiền xử lý là
$\Theta(n(\log n+\log w))$, và mỗi truy vấn là $\Theta(\log w)$.

Với cây phân đoạn, các thao tác tương ứng có độ phức tạp tiền xử lý $\Theta(n\log w)$ và mỗi truy vấn
$\Theta(\log n+\log w)$.

Đây chưa phải một chứng minh toán học chặt chẽ; phần chặt chẽ hơn được trình bày bên dưới:

??? note "Chứng minh chặt chẽ hơn"
    Để hiểu đoạn này, có thể cần kiến thức về "phân tích thế năng" trong [độ phức tạp thời gian](../basic/complexity.md).
    
    Trước hết phân tích độ phức tạp thời gian của phần tiền xử lý:
    
    Gọi "dãy đang xét" là dãy ở lớp vòng lặp hiện tại khi tiền xử lý bảng ST. Ví dụ, dãy ở lớp thứ 0 chính là dãy ban
    đầu; dãy ở lớp thứ nhất là dãy ở lớp thứ 0 sau một lần lặp, tức `st[1..n][1]`; ký hiệu dãy này là $A$.

    Hàm thế năng được định nghĩa là logarit cơ số hai của tích tất cả các số trong "dãy đang xét". Tức là:
    $\Phi(A)=\log_2\left(\prod\limits_{i=1}^n A_i\right)$.

    Trong một lần lặp, thời gian tiêu tốn bằng tổng thời gian của vòng lặp và thời gian tính GCD. Trong đó, thời gian
    tính GCD có thể dài hoặc ngắn: ngắn nhất có thể chỉ cần hai lần, thậm chí một lần đệ quy, còn dài nhất có thể cần
    $O(\log w)$ lần đệ quy. Nhưng trong quá trình tính GCD, ngoại trừ tầng đầu tiên và tầng cuối cùng, mỗi lần đệ quy
    đều làm cho một kết quả nào đó trong "dãy đang xét" giảm ít nhất một nửa. Nói cách khác, $\Phi(A)$ giảm ít nhất
    $1$, nên thời gian của tầng đệ quy đó có thể được khấu hao bằng hàm thế năng.

    Đồng thời, có thể thấy giá trị ban đầu của $\Phi(A)$ lớn nhất là $\log_2 (w^n)=\Theta(n\log w)$, và $\Phi(A)$
    không tăng. Vì vậy, độ phức tạp thời gian của phần tiền xử lý bảng ST là $O(n(\log w+\log n))$.
