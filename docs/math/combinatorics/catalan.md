<span id="giới-thiệu"></span>
## Giới thiệu

Số Catalan thường xuất hiện trong nhiều bài toán đếm. Nhà toán học Bỉ Eugene Charles Catalan đã phát hiện dãy số này khi nghiên cứu bài toán đếm dãy ngoặc vào năm 1838, và dãy được đặt theo tên ông. Nhà toán học triều Thanh Minggatu đã phát hiện dãy này từ những năm 1730.

Số Catalan thỏa mãn hệ thức truy hồi sau:

$$
C_n = \begin{cases}
1, & n = 0, \\
\sum_{i=0}^{n-1} C_{i}C_{n-1-i}, & n > 0.
\end{cases}\tag{1}
$$

Một vài số hạng đầu của dãy là: ([OEIS: A000108](https://oeis.org/A000108), chỉ số bắt đầu từ $0$)

$$
1,1,2,5,14,42,132,429,1430,\ldots
$$

<span id="ứng-dụng"></span>
## Ứng dụng

Hệ thức truy hồi của số Catalan $C_n$ có cấu trúc đệ quy tự nhiên: một bài toán đếm quy mô $n$ ứng với $C_n$ có thể được tách thành hai bài toán con có quy mô lần lượt là $i$ và $(n-1-i)$ bằng cách duyệt điểm chia. Hệ thức này khiến số Catalan xuất hiện rộng rãi trong các bài toán có cấu trúc đệ quy tương tự.

-   <a id="path-counting"></a>**Bài toán đếm đường đi**: Cho một lưới ô vuông kích thước $n\times n$, góc trái dưới là $(0, 0)$, góc phải trên là $(n, n)$. Bắt đầu từ góc trái dưới, mỗi bước chỉ được đi sang phải hoặc đi lên một đơn vị. Số đường đi đến góc phải trên mà không đi lên phía trên đường chéo $y=x$ (nhưng được chạm vào) là $C_n$.

    ??? note "Chứng minh"
        Gọi số phương án là $T_n$. Xét trường hợp $n \ge 2$. Giả sử điểm mà đường đi **lần đầu** chạm đường chéo $y=x$ là $(k,k)~(k \in [1,n])$. Xét đoạn đường từ $(0,0)$ đến $(k,k)$ sao cho ngoài điểm đầu và điểm cuối, các điểm trung gian **không đi qua đường chéo**, tức là không được chạm vào.
        
        ![Đường đi lần đầu chạm đường chéo trong bài toán Catalan](./images/catalan-2.svg)
        
        Như hình vẽ, bước đầu tiên của các đường đi này chắc chắn là sang phải, từ $(0,0)$ đến $(1,0)$; bước cuối cùng chắc chắn là đi lên, từ $(k,k-1)$ đến $(k,k)$. Vì vậy các đường đi này chính là các đường đi từ $(1,0)$ đến $(k,k-1)$ không vượt qua đường thẳng $y=x-1$, và số đường đi như vậy là $T_{k-1}$. Đồng thời, số đường đi hợp lệ từ $(k,k)$ đến $(n,n)$ là $T_{n-k}$. Theo quy tắc nhân, số đường đi lần đầu chạm đường chéo tại $(k,k)$ là $T_{k-1} T_{n-k}$. Duyệt mọi khả năng của $k$, tổng số đường đi hợp lệ là
        
        $$
        T_n = \sum_{k=1}^n T_{k-1}T_{n-k}.
        $$
        
        Thay $k=i+1$ sẽ thấy đây chính là hệ thức truy hồi của số Catalan. Từ $T_0=1$, suy ra $T_n = C_n$.

    <!-- To make bot happy. Do NOT delete this line. -->

-   **Bài toán đếm dây cung không cắt nhau trong đường tròn**: Có $2n$ điểm trên một đường tròn. Số cách ghép các điểm thành từng cặp và nối chúng bằng $n$ đoạn thẳng sao cho các đoạn thẳng đôi một không cắt nhau là $C_n$.

    ??? note "Chứng minh"
        Ký hiệu số phương án với $2n$ điểm là $T_n$. Đánh số $2n$ điểm theo chiều kim đồng hồ là $1,2,\ldots,2n$. Vì các dây cung đôi một không cắt nhau, điểm số $1$ chỉ có thể nối với điểm có số chẵn; nếu không, số điểm lẻ nằm giữa hai điểm đó không thể được ghép cặp đôi một mà không cắt đoạn nối hai điểm. Nếu nối $1$ với $2k~(k\in[1,n])$, thì bên trái có $2k-2$ điểm, bên phải có $2n-2k$ điểm. Theo quy tắc nhân, số phương án là $T_{k-1}T_{n-k}$. Vì vậy, duyệt $k$ cho ta $T_n = \sum_{k=1}^n T_{k-1} T_{n-k}$. Đặt $k=i+1$, ta thu được hệ thức truy hồi của số Catalan. Từ $T_0=1$, suy ra $T_n=C_n$.

    <!-- To make bot happy. Do NOT delete this line. -->

-   <a id="triangulation-counting"></a>**Bài toán đếm tam giác phân**: Số cách chia một đa giác lồi $(n+2)$ cạnh thành các miền tam giác bằng các đường chéo không cắt nhau là $C_n$.

    ??? note "Chứng minh"
        Gọi số phương án tam giác phân đa giác $(n+2)$ cạnh là $T_n$. Chọn trước cạnh $(1,n+2)$ làm cạnh đáy; cạnh này chắc chắn thuộc một tam giác. Gọi đỉnh thứ ba của tam giác đó là $k~(k\in[2,n+1])$. Khi đó đa giác lồi ban đầu được chia thành ba phần:
        
        -   Tam giác $(1,k,n+2)$.
        -   Đa giác $k$ cạnh với các đỉnh $1\sim k$.
        -   Đa giác $(n+3-k)$ cạnh với các đỉnh $k\sim (n+2)$.
        
        Hai phần sau đều là bài toán con, nên có hệ thức truy hồi
        
        $$
        T_n = \sum_{k=2}^{n+1} T_{k-2}T_{n+1-k}.
        $$
        
        Đặt $k=i+2$, ta thu được hệ thức truy hồi của số Catalan. Từ $T_0=T_1=1$, suy ra $T_n=C_n$.

    <!-- To make bot happy. Do NOT delete this line. -->

-   **Bài toán đếm cây nhị phân**: Số cây nhị phân khác nhau về hình dạng có $n$ nút là $C_n$. Tương đương, số cây nhị phân đầy đủ khác nhau về hình dạng có $n$ nút không phải lá là $C_{n}$.

    ??? note "Chứng minh"
        Ký hiệu số cây nhị phân có $n$ nút là $T_n$. Chọn một nút gốc bất kỳ, rồi duyệt kích thước cây con trái và cây con phải. Giả sử cây con trái có kích thước $i\in[0,n-1]$, thì cây con phải có kích thước $(n-1-i)$. Hai cây con đều là bài toán con, nên có hệ thức truy hồi
        
        $$
        T_n = \sum_{i=0}^{n-1}T_iT_{n-1-i}.
        $$
        
        Đây chính là hệ thức truy hồi của số Catalan. Từ $T_0=T_1=1$, suy ra $T_n=C_n$.

    <!-- To make bot happy. Do NOT delete this line. -->

-   **Bài toán đếm dãy ngoặc**: Số dãy ngoặc hợp lệ tạo bởi $n$ cặp ngoặc là $C_n$.

    ??? note "Chứng minh"
        Liên hệ với bài toán đếm đường đi. Xem dấu ngoặc mở là một bước đi lên, dấu ngoặc đóng là một bước đi sang phải. Dãy ngoặc hợp lệ nghĩa là tại mọi vị trí, số ngoặc mở không ít hơn số ngoặc đóng. Điều này tương đương với bài toán đường đi trong đó tại mọi thời điểm, số bước đi lên không ít hơn số bước đi sang phải. Vì vậy tồn tại một song ánh giữa dãy ngoặc hợp lệ và đường đi hợp lệ. Số dãy ngoặc hợp lệ cũng là $C_n$.

    <!-- To make bot happy. Do NOT delete this line. -->

-   **Bài toán đếm thứ tự ra khỏi ngăn xếp**: Với một ngăn xếp kích thước vô hạn, dãy đưa vào là $1,2,3, \ldots ,n$. Số dãy lấy ra hợp lệ là $C_n$.

    ??? note "Chứng minh"
        Liên hệ với bài toán đếm dãy ngoặc. Xem thao tác đưa vào ngăn xếp là ngoặc mở, thao tác lấy ra là ngoặc đóng. Tại mọi thời điểm, số lần đưa vào không ít hơn số lần lấy ra. Vì vậy tồn tại một song ánh giữa dãy lấy ra hợp lệ và dãy ngoặc hợp lệ. Số dãy lấy ra hợp lệ cũng là $C_n$.

    <!-- To make bot happy. Do NOT delete this line. -->

-   <a id="seq-counting"></a>**Bài toán đếm dãy số**: Trong các dãy $a_1,a_2, \ldots ,a_{2n}$ gồm $n$ số $+1$ và $n$ số $-1$, số dãy có tổng tiền tố thỏa mãn $a_1+a_2+ \ldots +a_k \geq 0~(k=1,2,3, \ldots ,2n)$ là $C_n$.

    ??? note "Chứng minh"
        Liên hệ với bài toán đếm dãy ngoặc. Xem $+1$ là ngoặc mở, $-1$ là ngoặc đóng. Tại mọi thời điểm, số lượng $+1$ không ít hơn số lượng $-1$. Vì vậy tồn tại một song ánh giữa dãy hợp lệ và dãy ngoặc hợp lệ. Số dãy hợp lệ cũng là $C_n$.

Mặc dù hệ thức truy hồi này được ứng dụng rộng rãi, việc tính trực tiếp có độ phức tạp cao, nên cần tìm công thức đơn giản hơn.

<span id="các-dạng-thường-gặp"></span>
## Các dạng thường gặp

Số Catalan có các biểu thức thường gặp sau:

$$
C_n = \frac{1}{n+1}\binom{2n}{n} = \dfrac{(2n)!}{n!(n+1)!},~ n\ge 0. \tag{2}
$$

$$
C_n = \binom{2n}{n} - \binom{2n}{n+1},~n \ge 0. \tag{3}
$$

$$
C_n = \frac{(4n-2)}{n+1}C_{n-1},~ n > 0,~ C_0 = 1. \tag{4}
$$

Các dạng này của số Catalan đều có thể tính hiệu quả: hai dạng đầu chuyển bài toán thành tính giai thừa và tổ hợp, còn dạng thứ ba cho một công thức truy hồi để tính tuần tự.

Với ba dạng thường gặp này, bài viết đưa ra hai cách chứng minh.

<span id="suy-diễn-đại-số"></span>
### Suy diễn đại số

Việc suy ra các biểu thức trên của số Catalan bằng phương pháp đại số gồm hai bước. Trước hết, kiểm tra ba dạng là tương đương với nhau.

??? note "Chứng minh các biểu thức $(2)\sim(4)$ tương đương"
    Chỉ cần chứng minh biểu thức $(3)$ có thể biến đổi thành dạng giai thừa trong biểu thức $(2)$:
    
    $$
    \begin{aligned}
    C_n &= \binom{2n}{n} - \binom{2n}{n+1} \\
    &= \frac{(2n)!}{n!n!} - \frac{(2n)!}{(n-1)!(n+1)!} \\
    &= \frac{(2n)!}{n!n!}\left(1 - \frac{n!}{(n-1)!(n+1)}\right) \\
    &= \frac{(2n)!}{n!n!}\left(1- \frac{n}{n+1}\right) \\
    &= \dfrac{(2n)!}{n!(n+1)!}.
    \end{aligned}
    $$
    
    Ngoài ra, biểu thức $(4)$ cũng có thể biến đổi thành dạng giai thừa trong biểu thức $(2)$:
    
    $$
    C_n = \prod_{i=1}^n\frac{(4i-2)}{i+1} = \prod_{i=1}^n\frac{2i(2i-1)}{i(i+1)} = \dfrac{(2n)!}{n!(n+1)!}.
    $$
    
    Vì vậy ba biểu thức tương đương với nhau.

Tiếp theo, kiểm tra rằng các dạng này thật sự là nghiệm của công thức truy hồi Catalan. Để làm điều đó, xét phương pháp hàm sinh để trực tiếp tìm nghiệm của truy hồi $(1)$.

??? note "Dùng hàm sinh để giải công thức truy hồi $(1)$"
    Xét hàm sinh thường của số Catalan $C(x)=\sum_{n=0}^{\infty}C_nx^n$. Vì hệ thức truy hồi của số Catalan rất giống dạng tích chập, ta dùng tích chập để xây dựng phương trình cho $C(x)$:
    
    $$
    \begin{aligned}
    C(x)&=\sum_{n=0}^{\infty}C_nx^n\\
    &=1+\sum_{n=1}^{\infty}\left(\sum_{i=0}^{n-1}C_iC_{n-i-1}\right)x^{n}\\
    &=1+x\sum_{n=1}^{\infty}\sum_{i=0}^{n-1}C_ix^iC_{n-i-1}x^{n-i-1}\\
    &=1+x\sum_{i=0}^{\infty}C_ix^i\sum_{j=0}^{\infty}C_jx^j\\
    &=1+xC^2(x).
    \end{aligned}
    $$
    
    Ở đẳng thức áp chót, ta đổi thứ tự lấy tổng và đặt $j=n-1-i$. Từ đó giải được:
    
    $$
    C(x)=\dfrac{1\pm \sqrt{1-4x}}{2x} = \frac{2}{1\mp \sqrt{1-4x}}.
    $$
    
    Từ điều kiện đầu $C_0=1$, ta có $C(0)=1$. Thay vào kiểm tra sẽ thấy nghiệm khả thi duy nhất là
    
    $$
    C(x) = \dfrac{1- \sqrt{1-4x}}{2x}.
    $$
    
    Tiếp theo, cần khai triển nó thành chuỗi lũy thừa. Dùng [khai triển chuỗi lũy thừa](../poly/intro.md#các-khai-triển-chuỗi-lũy-thừa-thường-gặp) của $(1+x)^a$, ta có:
    
    $$
    \sqrt{1-4x} = \sum_{n=0}^{\infty} \dfrac{\left(\frac{1}{2}\right)_{-n}}{n!}(-4x)^n,
    $$
    
    trong đó $\left(\dfrac{1}{2}\right)_{-n}$ là lũy thừa giai thừa giảm:
    
    $$
    \begin{aligned}
    \left(\frac{1}{2}\right)_{-n} &= \prod_{k=0}^{n-1}\left(\dfrac{1}{2}-k\right) = \dfrac{1}{2^n}\prod_{k=1}^{n-1}(1-2k) = \dfrac{(-1)^{n-1}}{2^n}\prod_{k=1}^{n-1}(2k-1)\\
    &= \dfrac{(-1)^{n-1}}{2^{2n-1}}\prod_{k=1}^{n-1}\dfrac{(2k-1)2k}{k} = \dfrac{(-1)^{n-1}}{2^{2n-1}}\dfrac{(2n-2)!}{(n-1)!}.
    \end{aligned}
    $$
    
    Thay vào biểu thức của $C(x)$, ta được
    
    $$
    \begin{aligned}
    C(x) &= \dfrac{1}{2x}\left(1-\sum_{n=0}^{\infty} \dfrac{\left(\frac{1}{2}\right)_{-n}}{n!}(-4x)^n\right)\\
    &= -\dfrac{1}{2x}\sum_{n=1}^\infty \dfrac{(-4x)^n}{n!}\left(\frac{1}{2}\right)_{-n} \\
    &= -\dfrac{1}{2x}\sum_{n=1}^\infty \dfrac{(-4x)^n}{n!}\dfrac{(-1)^{n-1}}{2^{2n-1}}\dfrac{(2n-2)!}{(n-1)!} \\
    &= \sum_{n=1}^{\infty}\dfrac{(2n-2)!}{(n-1)!n!}x^{n-1}\\
    &= \sum_{n=0}^{\infty}\dfrac{(2n)!}{n!(n+1)!}x^n.
    \end{aligned}
    $$
    
    Từ đó thu được biểu thức $(2)$ của $C_n$.

<span id="ý-nghĩa-tổ-hợp"></span>
### Ý nghĩa tổ hợp

Vì số Catalan có ý nghĩa tổ hợp rõ ràng, chỉ dùng phương pháp đếm tổ hợp cũng có thể chứng minh các dạng trên. Phần này đưa ra một chứng minh tổ hợp cho từng biểu thức trong ba biểu thức.

??? note "Chứng minh biểu thức $(2)$"
    Xét [bài toán đếm dãy số](#seq-counting). Với một dãy bất kỳ $\{a_i\}_{i=1}^{2n}$ gồm các phần tử $\pm 1$, định nghĩa tổng tiền tố của nó là $S_i = \sum_{j=1}^{i}a_i$, và định nghĩa **độ vượt** (exceedance) là số chỉ số thỏa mãn $S_i < 0$ và $a_i = -1$. Độ vượt bằng $0$ tương đương với dãy hợp lệ; giá trị của độ vượt nằm trong $[0,n]$, gồm $(n+1)$ khả năng. Cần chứng minh rằng số dãy ứng với các giá trị độ vượt khác nhau thật ra là bằng nhau.
    
    Để làm điều này, có thể xây dựng một ánh xạ $f$ từ dãy có độ vượt $e > 0$ sang dãy có độ vượt $(e-1)$. Với một dãy $\{a_i\}$ có độ vượt $e > 0$, lấy $k$ là chỉ số nhỏ nhất sao cho $S_i = 0$ và $a_i = +1$. Hoán đổi hai phần dãy ở hai bên $a_k$, ta thu được dãy $\{a'_i\}$:
    
    $$
    a_{k+1},a_{k+2},\cdots,a_{2n},a_k,a_{1},a_{2},\cdots,a_{k-1}.
    $$
    
    Vì phần bên phải $a_k$ trong dãy ban đầu có dãy tổng tiền tố tương ứng không đổi trước và sau khi hoán đổi, đóng góp của nó vào độ vượt cũng không đổi. Với phần bên trái $a_k$ trong dãy ban đầu, các tổng tiền tố tương ứng sau khi hoán đổi đều tăng thêm $1$, nên đóng góp của chúng vào độ vượt giảm đi; số lượng giảm đúng bằng số chỉ số ở phần bên trái $a_k$ thỏa mãn $S_i=-1$ và $a_i=-1$. Cách chọn $a_k$ bảo đảm chỉ số như vậy có đúng một. Vì vậy độ vượt của dãy $\{a'_i\}$ bằng $(e-1)$. Nói cách khác, ánh xạ $f$ làm độ vượt của dãy giảm đúng $1$.
    
    Ánh xạ $f$ là khả nghịch. Chú ý rằng trong dãy $\{a'_i\}$, vị trí tương ứng với $a_k$ chính là chỉ số lớn nhất thỏa mãn $S'_k=+1$ và $a'_i = +1$. Điều này đúng vì sau khi hoán đổi, các tổng tiền tố này đều lớn hơn tổng tiền tố tương ứng trước khi hoán đổi đúng $1$, nên tổng tiền tố hiện tại bằng $+1$ tương ứng với tổng tiền tố trước khi hoán đổi bằng $0$. Nhưng theo cách chọn $k$, phần này trước khi hoán đổi, tức phần bên trái $a_k$ trong dãy ban đầu, không có chỉ số nào thỏa mãn $S_i = 0$ và $a_i = +1$.
    
    Do đó ánh xạ $f$ tạo thành một song ánh giữa các dãy có độ vượt $e>0$ và các dãy có độ vượt $(e-1)$. Điều này cho thấy số dãy ứng với các giá trị độ vượt khác nhau là bằng nhau. Vì tổng số dãy là $\dbinom{2n}{n}$, số dãy hợp lệ, tức số dãy có độ vượt $0$, bằng
    
    $$
    C_n = \dfrac{1}{n+1}\dbinom{2n}{n}.
    $$
    
    Vậy biểu thức $(2)$ của số Catalan được chứng minh.

??? note "Chứng minh biểu thức $(3)$"
    Xét [bài toán đếm đường đi](#path-counting). Đây là một bài toán đếm đường đi trên lưới điển hình và có thể giải bằng nguyên lý phản xạ. Cụ thể trong bài toán này, ta lấy tổng số đường đi trừ đi số đường đi không hợp lệ. Mỗi đường đi có tổng cộng $2n$ bước, trong đó có $n$ bước sang phải, nên số phương án là $\dbinom{2n}{n}$. Một đường đi không hợp lệ khi và chỉ khi nó chạm đường thẳng $y = x+1$. Với một đường đi bất hợp lệ bất kỳ, ta có thể tìm vị trí đầu tiên chạm đường thẳng $y = x+1$, rồi lấy đối xứng phần đường đi sau vị trí đó qua đường thẳng $y=x+1$. Khi đó, một đường đi bất hợp lệ từ $(0,0)$ đến $(n,n)$ biến thành một đường đi từ $(0,0)$ đến $(n-1,n+1)$.
    
    ![Phản xạ đường đi không hợp lệ qua đường thẳng y = x + 1](./images/catalan-1.svg)
    
    Vì mọi đường đi từ $(0,0)$ đến $(n-1,n+1)$ chắc chắn phải đi qua đường thẳng $y = x+1$, mỗi đường đi như vậy đều tương ứng với một đường đi bất hợp lệ từ $(0,0)$ đến $(n,n)$. Tương tự cách tính tổng số đường đi, tổng số đường đi bất hợp lệ là $\dbinom{2n}{n+1}$. Do đó tổng số đường đi hợp lệ là
    
    $$
    C_n = \binom{2n}{n} - \binom{2n}{n+1}.
    $$
    
    Đây chính là biểu thức $(3)$ của số Catalan.

??? note "Chứng minh biểu thức $(4)$"
    Xét [bài toán đếm tam giác phân](#triangulation-counting). Gọi $P$ là một đa giác lồi $(n+2)$ cạnh, và cố định một cạnh của nó làm cạnh đáy. Với mỗi tam giác phân của đa giác $P$, ta có thể chọn một cạnh không phải cạnh đáy, bao gồm cả cạnh mới được thêm khi tam giác phân, để đánh dấu và định hướng. Tổng cộng có $(4n+2)C_n$ phương án tam giác phân kèm đánh dấu. Gọi $Q$ là một đa giác lồi $(n+3)$ cạnh, cũng cố định một cạnh làm cạnh đáy. Với đa giác $Q$, ta có thể chọn một cạnh không phải cạnh đáy để đánh dấu, rồi thực hiện tam giác phân. Tổng cộng có $(n+2)C_{n+1}$ phương án đánh dấu kèm tam giác phân.
    
    ![](./images/catalan-triangulation.svg)
    
    Như hình vẽ, giữa hai nhóm thao tác này tồn tại một song ánh rõ ràng. Với một kết quả tam giác phân và đánh dấu của $P$, có thể mở rộng cạnh được đánh dấu thành một tam giác, mở rộng đầu mút được chỉ bởi hướng thành một cạnh mới, rồi đánh dấu cạnh mới này; ta thu được một kết quả đánh dấu và tam giác phân của $Q$. Ngược lại, với một kết quả đánh dấu và tam giác phân của $Q$, có thể co cạnh được đánh dấu thành một điểm, đánh dấu đường chéo thu được sau khi co và định hướng về phía đỉnh thu được; ta thu được một kết quả tam giác phân và đánh dấu của $P$. Vì vậy,
    
    $$
    (4n+2)C_n = (n+2)C_{n+1}.
    $$
    
    Sắp xếp lại, kết hợp với $C_0=1$, ta thu được biểu thức $(4)$ của số Catalan.

<span id="ví-dụ"></span>
## Ví dụ

???+ example "[Luogu P1044 Stack](https://www.luogu.com.cn/problem/P1044)"
    Với thứ tự đưa vào ngăn xếp là $1,2,\ldots ,n$, hãy tìm tổng số thứ tự lấy ra có thể có.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/math/code/combinatorics/catalan/catalan_1.cpp"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/math/code/combinatorics/catalan/catalan_1.py"
        ```

<span id="bài-tập"></span>
## Bài tập

-   [Luogu P2532 [AHOI2012] Treehouse Stairs](https://www.luogu.com.cn/problem/P2532)
-   [Luogu P1641 [SCOI2010] Generate Strings](https://www.luogu.com.cn/problem/P1641)
-   [Luogu P3200 [HNOI2009] Interesting Sequence](https://www.luogu.com.cn/problem/P3200)
-   [AtCoder Beginner Contest 205 E - White and Black Balls](https://atcoder.jp/contests/abc205/tasks/abc205_e)
-   [AtCoder Regular Contest 145 C - Split and Maximize](https://www.luogu.com.cn/problem/AT_arc145_c)
-   [Luogu P5014 Water Triangle (modified version)](https://www.luogu.com.cn/problem/P5014)
-   [Luogu P3978 [TJOI2015] Probability Theory](https://www.luogu.com.cn/problem/P3978)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích
