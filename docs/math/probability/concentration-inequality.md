Trong thi đấu thuật toán, đôi khi ta dùng [thuật toán ngẫu nhiên hóa](../../misc/rand-technique.md). Tính đúng đắn và độ phức tạp thời gian - không gian của các thuật toán này thường dựa trên tiền đề rằng "xác suất một số biến cố ngẫu nhiên xảy ra là rất nhỏ". Ví dụ, độ phức tạp của quicksort phụ thuộc vào việc biến cố "phần tử `pivot` được chọn gần như là phần tử nhỏ nhất hoặc lớn nhất" hiếm khi xảy ra.

Bài viết này giới thiệu ngắn gọn một số công cụ dùng để phân tích thuật toán ngẫu nhiên hóa và đưa ra vài ví dụ ứng dụng đơn giản.

## Union Bound

Ký hiệu $A_1, \cdots, A_m$ là các biến cố ngẫu nhiên, khi đó

$$
P\left\{ \bigcup_{i=1}^m A_i \right\} \leq \sum_{i=1}^m P\{A_i\}
$$

Nói cách khác: xác suất có ít nhất một biến cố trong một nhóm biến cố xảy ra không vượt quá tổng xác suất xảy ra của từng biến cố.

Thực ra, kết luận này còn có thể được tăng cường thêm một chút:

-   Xác suất có ít nhất một biến cố trong một nhóm biến cố xảy ra **không nhỏ hơn** tổng xác suất xảy ra của từng biến cố, trừ đi tổng xác suất các cặp biến cố cùng xảy ra.
-   Xác suất có ít nhất một biến cố trong một nhóm biến cố xảy ra **không vượt quá** tổng xác suất xảy ra của từng biến cố, trừ đi tổng xác suất các cặp biến cố cùng xảy ra, rồi cộng thêm tổng xác suất các bộ ba biến cố cùng xảy ra.
-   ...

Khi số tầng tăng dần, các cận trên và cận dưới xuất hiện luân phiên cũng ngày càng chặt hơn. Chuỗi kết luận này có hình thức tương tự nguyên lý bao hàm - loại trừ, và cách chứng minh cũng tương tự bao hàm - loại trừ; ở đây lược bỏ.

<span id="markov-&#19981;&#31561;&#24335;"></span>
## Bất đẳng thức Markov

Giả sử $X$ là một biến ngẫu nhiên nhận giá trị không âm, khi đó với mọi số thực dương $a$ ta có

$$
P\{ X \geq a \} \leq \frac{EX}{a}
$$

Trên thực tế, vì bản thân bất đẳng thức Markov không dùng bất kỳ thông tin nào liên quan đến phân phối của biến ngẫu nhiên ngoài kỳ vọng, nên ràng buộc thu được khi áp dụng trực tiếp bất đẳng thức này thường khá lỏng.

<span id="&#35777;&#26126;"></span>
### Chứng minh

Ký hiệu $I$ là hàm chỉ báo của biến cố $X \geq a$, khi đó

$$
I \leq \frac{X}{a}
$$

Do đó

$$
P\{ X \geq a \} = EI \leq E \left[ \frac{X}{a} \right] = \frac{EX}{a}
$$

<span id="chebyshev-&#19981;&#31561;&#24335;"></span>
## Bất đẳng thức Chebyshev

Giả sử $X$ là một biến ngẫu nhiên, khi đó với mọi $a > 0$ ta đều có

$$
P \{ |X - EX| \geq a \} \leq \frac{DX}{a^2}
$$

Đặc biệt, khi lấy $a$ bằng $k\sigma$, ta có

$$
P \{ |X - EX| \geq k\sigma \} \leq \frac{1}{k^2}
$$

trong đó $\sigma$ là độ lệch chuẩn của $X$.

<span id="&#35777;&#26126;_1"></span>
### Chứng minh

Từ giả thiết, ta có

$$
P \{ |X - EX| \geq a \} = P \{ (X - EX)^2 \geq a^2 \}
$$

Nhận thấy $(X - EX)^2$ không âm, nên theo bất đẳng thức Markov,

$$
P \{ (X - EX)^2 \geq a^2 \} \leq \frac{E(X - EX)^2}{a^2} = \frac{DX}{a^2}
$$

<span id="chernoff-&#19981;&#31561;&#24335;"></span>
## Bất đẳng thức Chernoff

Bất đẳng thức Chernoff tổng quát có thể được suy ra bằng cách áp dụng trực tiếp bất đẳng thức Markov cho biến ngẫu nhiên $\mathrm{e}^{tX}$:

Giả sử $X$ là một biến ngẫu nhiên, khi đó với mọi $t > 0$ ta đều có

$$
P\{ X \geq a \} = P\{ \mathrm{e}^{tX} > \mathrm{e}^{ta} \} \leq \frac{E \mathrm{e}^{tX}}{\mathrm{e}^{ta}}
$$

Tương tự, khi $t < 0$, ta có

$$
P\{ X \leq a \} = P\{ \mathrm{e}^{tX} > \mathrm{e}^{ta} \} \leq \frac{E \mathrm{e}^{tX}}{\mathrm{e}^{ta}}
$$

<span id="poisson-&#35797;&#39564;&#20043;&#21644;&#30340;-chernoff-&#19981;&#31561;&#24335;"></span>
### Bất đẳng thức Chernoff cho tổng các phép thử Poisson

Các biến ngẫu nhiên xuất hiện trong thi đấu thuật toán thường không "tổng quát" đến vậy; ta có thể mô tả chúng bằng các phép thử Poisson trong xác suất.

Cái gọi là phép thử Poisson là một phép thử ngẫu nhiên chỉ có hai kết quả có thể xảy ra.

Kết quả của một phép thử Poisson có thể được mô tả bằng một biến ngẫu nhiên $X$ nhận giá trị $0$ hoặc $1$, với phân phối xác suất

$$
P\{ X = i \} = \begin{cases}
    p_i, & i = 1 \\
    1 - p_1, & i = 0
\end{cases}
$$

Đối với phép thử Poisson, ta có kết luận sau:

Với $n$ phép thử Poisson độc lập $X_1, X_2, \cdots, X_n$, đặt $X = \sum_{i=1}^{n} X_i$ và $\mu = EX$, khi đó với mọi $0 < \epsilon < 1$ ta có

$$
P\left\{ |X - \mu| \geq \epsilon \mu \right\} \leq 2 \exp\left( - \frac{1}{3} \mu \epsilon^2 \right)
$$

<span id="hoeffding-&#19981;&#31561;&#24335;"></span>
## Bất đẳng thức Hoeffding

Nếu $X_1, \cdots, X_n$ là các biến ngẫu nhiên thực độc lập lẫn nhau và $X_i\in [a_i,b_i]$, ký hiệu biến ngẫu nhiên $X=\sum\limits_{i=1}^n X_i$, thì

$$
P\{ |X - EX| \geq \epsilon \} \leq 2\exp \left( \frac {-2\epsilon^2}{\sum\limits_{i=1}^n (b_i-a_i)^2} \right)
$$

Cả bất đẳng thức Chernoff và bất đẳng thức Hoeffding đều giới hạn mức độ một biến ngẫu nhiên lệch khỏi kỳ vọng của nó. Chứng minh của hai bất đẳng thức này khá dài; bạn đọc quan tâm có thể tham khảo các chương liên quan trong sách Probability and Computing.

Theo kinh nghiệm, nếu $EX$ không quá gần $a_1+\cdots+a_n$, thì cận do bất đẳng thức này đưa ra thường tương đối chặt; nếu rất gần (chẳng hạn trong [UOJ #72 cách làm hoàn toàn mới](https://matthew99.blog.uoj.ac/blog/5511)), thì cận thu được thường rất lỏng, lúc này lựa chọn tốt hơn là dùng bất đẳng thức Chernoff.

<span id="&#24212;&#29992;&#20030;&#20363;"></span>
## Ví dụ ứng dụng

<span id="&#20363;&#65306;&#38543;&#26426;&#25746;&#28857;&#20272;&#31639;&#22278;&#21608;&#29575;"></span>
### Ví dụ: ước lượng số pi bằng cách gieo điểm ngẫu nhiên

Xét thuật toán sau để ước lượng giá trị chính xác của hằng số $\pi$:

Sinh ngẫu nhiên $n$ điểm trong miền hình vuông $[-1, 1]^2$. Gọi $m$ là số điểm trong đó rơi vào đĩa tròn đơn vị $x^2 + y^2 \leq 1$, khi đó có thể lấy $\dfrac{4m}{n}$ làm giá trị xấp xỉ của $\pi$.

Câu hỏi: để đảm bảo thuật toán trên trả về kết quả có sai số tương đối không vượt quá $\epsilon$ với xác suất ít nhất $(1 - \delta)$, cần chọn $n$ như thế nào?

??? note "Lời giải"
    Ký hiệu $X_i$ biểu diễn biến cố "điểm thứ $i$ được sinh ngẫu nhiên nằm trong đĩa tròn đơn vị", khi đó tổng số điểm trong đĩa tròn là $X = \sum_{i=1}^{n} X_i$. Ta cần tìm một $n$ thích hợp sao cho
    
    $$
    P\left\{ \left| \frac{4X}{n} - \pi \right| \geq \epsilon \pi \right\} \leq \delta
    $$
    
    Bất đẳng thức trên tương đương với
    
    $$
    P\left\{ \left| X - \frac{\pi}{4}n \right| \geq \epsilon \cdot \frac{\pi}{4}n  \right\} \leq \delta
    $$
    
    Theo bất đẳng thức Chernoff, ta chỉ cần đặt
    
    $$
    2 \exp\left( - \frac{1}{3} \epsilon^2 \cdot \frac{\pi}{4}n \right) \leq \delta
    $$
    
    là đủ; từ đó giải được
    
    $$
    n \geq \frac{12}{\pi} \epsilon^{-2} \ln \frac{2}{\delta}
    $$
    
    Tức là khi $n = \Omega(\epsilon^{-2} \ln \frac{1}{\delta})$, ta có thể đạt được độ chính xác cần thiết.

<span id="&#20363;&#65306;&#25277;&#22870;&#38382;&#39064;"></span>
### Ví dụ: bài toán rút thưởng

Trong một hộp có $n$ quả bóng, trong đó đúng $k$ quả bóng tương ứng với giải thưởng lớn. Bạn sẽ thực hiện một số lần rút ngẫu nhiên độc lập, đều xác suất; sau mỗi lần rút sẽ đặt bóng trở lại hộp. Hỏi cần rút bao nhiêu lần để đảm bảo với xác suất ít nhất $(1 - \epsilon)$ rằng **mỗi** quả bóng trúng thưởng đều được rút ra ít nhất một lần?

??? note "Lời giải"
    Nếu chỉ có một quả bóng trúng thưởng, thì rút $M=n\log\epsilon^{-1}$ lần là đủ, vì xác suất không trúng lần nào trong $M$ lần là
    
    $$
    \Big(1-\dfrac 1n\Big)^{n\log\epsilon^{-1}}\leq e^{\log\epsilon}=\epsilon
    $$
    
    Bây giờ có $k>1$ quả bóng trúng thưởng. Theo Union Bound, ta chỉ cần đảm bảo xác suất mỗi quả bóng trúng thưởng bị bỏ sót đều không vượt quá $\dfrac \epsilon k$. Do đó đáp án là $n \log \dfrac{k}{\epsilon}$.

<span id="&#20363;&#65306;&#38543;&#26426;&#36873;&#21462;&#19968;&#21322;&#20803;&#32032;"></span>
### Ví dụ: chọn ngẫu nhiên một nửa số phần tử

Hãy đưa ra một thuật toán chọn ngẫu nhiên đều xác suất một tập con có kích thước $\dfrac{n}{2}$ từ $n$ phần tử, đảm bảo $n$ là số chẵn. Nguồn ngẫu nhiên duy nhất bạn có thể dùng là một đồng xu công bằng; đồng thời hãy cố gắng giảm số lần tung đồng xu (không yêu cầu tối thiểu).

??? note "Lời giải"
    Trước hết có thể nghĩ đến thuật toán sau:
    
    -   Bằng cách tung đồng xu $n$ lần, ta có thể chọn ngẫu nhiên đều xác suất một tập con trong tất cả các tập con.
    -   Lặp lại quá trình này cho đến khi kích thước tập con được chọn đúng bằng $\dfrac n2$.
        -   Lưu ý rằng các tập con có kích thước $\dfrac n2$ chiếm ít nhất $\dfrac 1n$ trong tất cả các tập con, nên kỳ vọng số lần lặp $\leq n$.
    
    Thuật toán này cần tung đồng xu $n^2$ lần theo kỳ vọng.
    
    Một thuật toán khác:
    
    -   Ta có thể thực hiện chọn ngẫu nhiên 1 trong $n$ phần tử bằng cách tung đồng xu $2\lceil\log_2 n\rceil$ lần theo kỳ vọng.
        -   Cách làm cụ thể: sinh ngẫu nhiên một số nhị phân có $\lceil\log_2 n\rceil$ bit; nếu số đó lớn hơn hoặc bằng $n$ thì sinh lại, nếu không thì chọn phần tử có chỉ số tương ứng (đánh số từ 0) và kết thúc quá trình.
    -   Sau đó ta chọn một phần tử từ tất cả các phần tử, rồi chọn thêm một phần tử từ các phần tử còn lại, cứ như vậy cho đến khi chọn được $\dfrac n2$ phần tử.
    
    Thuật toán này cần tung đồng xu $n\lceil\log_2 n\rceil$ lần theo kỳ vọng.
    
    Ghép hai thuật toán lại với nhau:
    
    -   Trước tiên dùng thuật toán thứ nhất để lấy ngẫu nhiên một tập con.
    -   Nếu kích thước tập con này nhỏ hơn $\dfrac n2$, thì dùng thuật toán thứ hai để liên tục thêm phần tử cho đến khi bù kích thước lên $\dfrac n2$.
    -   Nếu kích thước tập con này lớn hơn $\dfrac n2$, thì dùng thuật toán thứ hai để liên tục xóa phần tử cho đến khi giảm kích thước xuống $\dfrac n2$.
    
    Thử phân tích số thao tác cần thiết ở bước hai và bước ba (tức số lần thêm/xóa phần tử):
    
    -   Ký hiệu biến ngẫu nhiên 0-1 $X_i$ biểu diễn việc $i$ có được chọn vào tập con ban đầu hay không, và đặt $X:=X_1+\cdots+X_n$ biểu diễn kích thước tập con. Khi đó số thao tác cần ở bước hai và bước ba bằng $\big|X-\mathrm{E}[X]\big|$. Trong bất đẳng thức Hoeffding, lấy $t=c\cdot\sqrt n$ (trong đó $c$ là hằng số tùy ý), ta được $\mathrm{Pr}\Big[\big|X-\mathrm{E}[X]\big|\geq t\Big]\leq 2\mathrm{e}^{-c^2}$. Nói cách khác, bằng cách cho phép độ lệch ở mức $\Theta(\sqrt n)$, ta có thể thu được xác suất thất bại nhỏ tùy ý ở cấp hằng số.
    
    Đến đây ta đã chứng minh rằng: với xác suất rất lớn, thuật toán này có thể đảm bảo số lần tung đồng xu không vượt quá $n+\Theta(\sqrt n\log n)$.
    
    -   Trong đó $n$ đến từ số lần tung đồng xu để thu được tập con ban đầu; $\Theta(\sqrt n\log n)$ là tổng chi phí của $\Theta(\sqrt n)$ lần thêm/xóa phần tử.
    
    ??? note "Tính độ phức tạp kỳ vọng"
        Ta tiếp tục phân tích từ một góc nhìn khác, thử tính số lần tung đồng xu kỳ vọng của thuật toán này.
        
        Dùng bất đẳng thức Hoeffding để tìm cận trên cho kỳ vọng số thao tác trong bước hai và bước ba:
        
        $$
        E|X - EX| = \int_0^\infty P\{ |X - E[X]| \geq t \} \mathrm{d}t \leq 
        2 \int_0^\infty \exp \left(-\frac {t^2}{n}\right) \mathrm{d}t=\sqrt{\pi n}
        $$
        
        Do đó kỳ vọng số lần tung đồng xu cần cho bước hai và bước ba là $\sqrt{\pi n}\cdot2\lceil\log_2 n\rceil$.
        
        Tóm lại, thuật toán này cần tung đồng xu $n+2\sqrt{\pi n}\lceil\log_2 n\rceil$ lần theo kỳ vọng.

<span id="&#32451;&#20064;&#65306;balls-and-bins"></span>
### Bài tập: Balls and Bins

$n$ quả bóng được ném độc lập ngẫu nhiên vào $n$ hộp. Hãy chứng minh: số bóng trong hộp chứa nhiều bóng nhất không nhỏ hơn $\Omega \left( \dfrac{\log n}{\log \log n} \right)$ với xác suất $1 - \dfrac{1}{n}$.
