author: Ir1d, ouuan, qinggniq, i-Yirannn, minghu6

## Định nghĩa

### Bảng chữ cái

Một **bảng chữ cái** $\Sigma$ là một tập hợp có quan hệ [thứ tự toàn phần](../math/order-theory.md#tập-có-thứ-tự-bộ-phận). Nói cách khác, với hai phần tử khác nhau bất kỳ $\alpha$ và $\beta$ trong $\Sigma$, luôn có thể so sánh chúng: hoặc $\alpha<\beta$, hoặc $\beta<\alpha$. Các phần tử của bảng chữ cái $\Sigma$ được gọi là ký tự.

### Xâu

Một **xâu** $S$ là một dãy gồm $n$ ký tự được sắp theo thứ tự; $n$ được gọi là độ dài của $S$, ký hiệu là $|S|$.

Nếu chỉ số xâu bắt đầu từ $1$, ký tự thứ $i$ của $S$ được viết là $S[i]$.

Nếu chỉ số xâu bắt đầu từ $0$, ký tự thứ $i$ của $S$ được viết là $S[i-1]$.

### Xâu con

**Xâu con** $S[i..j]$ của xâu $S$, với $i\le j$, biểu thị đoạn từ $i$ đến $j$ trong $S$, tức xâu tạo bởi các ký tự $S[i],S[i+1],\ldots,S[j]$ theo thứ tự.

Đôi khi cũng dùng $S[i..j]$ với $i>j$ để biểu diễn xâu rỗng.

### Dãy con

**Dãy con** của xâu $S$ là dãy thu được bằng cách lấy ra một số phần tử từ $S$ mà không thay đổi thứ tự tương đối, tức $S[p_1],S[p_2],\ldots,S[p_k]$ với $1\le p_1<p_2<\cdots<p_k\le |S|$.

### Hậu tố

**Hậu tố** là một xâu con đặc biệt bắt đầu từ một vị trí $i$ nào đó và kéo dài tới cuối xâu. Hậu tố của xâu $S$ bắt đầu tại $i$ được ký hiệu là $\textit{Suffix(S,i)}$, tức $\textit{Suffix(S,i)}=S[i..|S|-1]$.

**Hậu tố thực sự** là hậu tố của $S$ khác với chính $S$.

Ví dụ, mọi hậu tố của xâu `abcabcd` là `{d, cd, bcd, abcd, cabcd, bcabcd, abcabcd}`, còn các hậu tố thực sự là `{d, cd, bcd, abcd, cabcd, bcabcd}`.

### Tiền tố

**Tiền tố** là một xâu con đặc biệt bắt đầu từ đầu xâu và kết thúc tại một vị trí $i$ nào đó. Tiền tố của xâu $S$ kết thúc tại $i$ được ký hiệu là $\textit{Prefix(S,i)}$, tức $\textit{Prefix(S,i)}=S[0..i]$.

**Tiền tố thực sự** là tiền tố của $S$ khác với chính $S$.

Ví dụ, mọi tiền tố của xâu `abcabcd` là `{a, ab, abc, abca, abcab, abcabc, abcabcd}`, còn các tiền tố thực sự là `{a, ab, abc, abca, abcab, abcabc}`.

### Thứ tự từ điển

So sánh kích thước bằng cách lấy ký tự thứ $i$ làm khóa thứ $i$; ký tự rỗng nhỏ hơn mọi ký tự trong bảng chữ cái, tức $a<aa$.

### Xâu đối xứng

**Xâu đối xứng** là xâu đọc xuôi và đọc ngược giống nhau, tức xâu $s$ thỏa $\forall 1\le i\le |s|, s[i]=s[|s|+1-i]$.

### Khoảng cách Hamming

**Khoảng cách Hamming** là khoảng cách giữa hai xâu có cùng độ dài; nó biểu thị số vị trí mà hai xâu khác ký tự tương ứng.

Có thể hiểu đơn giản rằng nếu thực hiện phép xor trên hai xâu, số bit có kết quả bằng $1$ chính là khoảng cách Hamming của hai xâu.

## Lưu trữ xâu

-   Dùng mảng `char` để lưu, dùng ký tự rỗng `\0` để biểu thị kết thúc xâu (xâu kiểu C).
-   Dùng lớp [`string`](../lang/csl/string.md) do thư viện chuẩn C++ cung cấp.
-   Hằng xâu có thể được biểu diễn bằng literal xâu (xâu đặt trong dấu nháy kép).
