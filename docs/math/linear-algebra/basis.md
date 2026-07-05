author: cesonic, Enter-tainer, Great-designer, Ir1d, ksyx, lychees, MegaOwIer, RUIN-RISE, wjy-yy, rsdbkhusky, ouuan, Menci, Tiphereth-A

Nhớ lại khái niệm vectơ cơ sở trong hình học không gian ở bậc phổ thông: trong không gian Euclid ba chiều, ta có thể tìm một bộ vectơ cơ sở $\boldsymbol{i}$, $\boldsymbol{j}$, $\boldsymbol{k}$; khi đó mọi vectơ trong không gian đều có thể được biểu diễn bởi bộ vectơ cơ sở này. Nói cách khác, ta có thể **mô tả một không gian ba chiều vô hạn bằng một số hữu hạn vectơ cơ sở**, điều này đủ cho thấy tầm quan trọng của vectơ cơ sở.

Không gian Euclid ba chiều là một trường hợp đặc biệt của [không gian tuyến tính](./vector-space.md); vectơ cơ sở của không gian Euclid ba chiều được khái quát trong không gian tuyến tính thành cơ sở tuyến tính.

Trong OI, các ứng dụng liên quan đến cơ sở tuyến tính thường chỉ xét hai loại không gian tuyến tính: không gian tuyến tính thực $n$ chiều $\mathbf{R}^n$ và không gian tuyến tính $n$ chiều trên [trường Boolean](https://en.wikipedia.org/wiki/Boolean_domain) $\mathbf{Z}_2^n$. Chúng ta sẽ giới thiệu chi tiết trong phần [ứng dụng](#ứng-dụng). Nếu chưa quen với đại số tuyến tính, bạn nên bắt đầu đọc từ phần ứng dụng.

Phần dưới sẽ xuất phát từ không gian tuyến tính tổng quát để giới thiệu cơ sở tuyến tính và nêu các tính chất thường gặp của nó.

Kiến thức chuẩn bị: [không gian tuyến tính](./vector-space.md).

Cơ sở tuyến tính là một bộ cơ sở của không gian tuyến tính, là công cụ quan trọng để nghiên cứu không gian tuyến tính.

<span id="định-nghĩa"></span>
## Định nghĩa

Một hệ con độc lập tuyến tính cực đại của không gian tuyến tính $V$ được gọi là một **cơ sở Hamel** hoặc **cơ sở tuyến tính** của $V$, gọi tắt là **cơ sở**.

Quy ước rằng cơ sở của không gian tuyến tính $\{\theta\}$ là tập rỗng.

Có thể chứng minh mọi không gian tuyến tính đều tồn tại cơ sở tuyến tính[^existence_basis]. Ta định nghĩa **số chiều** của không gian tuyến tính $V$ là số phần tử (hoặc lực lượng) của một cơ sở tuyến tính, ký hiệu $\dim V$.

<span id="tính-chất"></span>
## Tính chất

1.  Với không gian tuyến tính hữu hạn chiều $V$, giả sử số chiều của nó là $n$, khi đó:

    1.  Mọi $n+1$ vectơ trong $V$ đều phụ thuộc tuyến tính.

    2.  Mọi $n$ vectơ độc lập tuyến tính trong $V$ đều là một cơ sở của $V$.

    3.  Nếu mọi vectơ trong $V$ đều có thể được biểu diễn tuyến tính bởi hệ vectơ $a_1,a_2,\dots,a_n$, thì hệ này là một cơ sở của $V$.

        ???+ note "Chứng minh"
            Lấy tùy ý một cơ sở $b_1,b_2,\dots,b_n$ của $V$. Theo giả thiết, hệ vectơ $b_1,b_2,\dots,b_n$ có thể được biểu diễn tuyến tính bởi $a_1,a_2,\dots,a_n$, nên
            
            $$
            n=\operatorname{rank}\{b_1,b_2,\dots,b_n\}\leq\operatorname{rank}\{a_1,a_2,\dots,a_n\}\leq n
            $$
            
            Do đó $\operatorname{rank}\{a_1,a_2,\dots,a_n\}=n$.

    4.  Mọi hệ vectơ độc lập tuyến tính $a_1,a_2,\dots,a_m$ trong $V$ đều có thể được mở rộng bằng cách chèn thêm một số vectơ để trở thành một cơ sở của $V$.

2.  (Công thức số chiều của không gian con) Gọi $V_1,V_2$ là các không gian tuyến tính hữu hạn chiều trên $\Bbb{P}$, đồng thời $V_1+V_2$ và $V_1\cap V_2$ cũng hữu hạn chiều. Khi đó $\dim V_1+\dim V_2=\dim(V_1+V_2)+\dim(V_1\cap V_2)$.

    ???+ note "Chứng minh"
        Giả sử $\dim V_1=n_1$,$\dim V_2=n_2$,$\dim(V_1\cap V_2)=m$.
        
        Lấy một cơ sở $a_1,a_2,\dots,a_m$ của $V_1\cap V_2$, rồi lần lượt mở rộng nó thành cơ sở của $V_1$ và $V_2$: $a_1,a_2,\dots,a_m,b_1,b_2,\dots,b_{n_1-m}$ và $a_1,a_2,\dots,a_m,c_1,c_2,\dots,c_{n_2-m}$.
        
        Tiếp theo chỉ cần chứng minh hệ vectơ $a_1,a_2,\dots,a_m,b_1,b_2,\dots,b_{n_1-m},c_1,c_2,\dots,c_{n_2-m}$ độc lập tuyến tính.
        
        Giả sử $\sum_{i=1}^m r_ia_i+\sum_{i=1}^{n_1-m} s_ib_i+\sum_{i=1}^{n_2-m} t_ic_i=\theta$.
        
        Khi đó $\sum_{i=1}^{n_2-m} t_ic_i=-\sum_{i=1}^m r_ia_i-\sum_{i=1}^{n_1-m} s_ib_i$.
        
        Chú ý rằng vế trái nằm trong $V_2$, còn vế phải nằm trong $V_1$, nên cả hai vế đều nằm trong $V_1\cap V_2$. Do đó $\sum_{i=1}^{n_2-m} t_ic_i=\sum_{i=1}^m k_ia_i$.
        
        Suy ra $t_1=t_2=\dots=t_{n_2-m}=k_1=k_2=\dots=k_m=0$, tiếp đó $r_1=r_2=\dots=r_m=s_1=s_2=\dots=s_{n_1-m}=t_1=t_2=\dots=t_{n_2-m}=0$.

3.  Gọi $V_1,V_2$ là các không gian tuyến tính hữu hạn chiều trên $\Bbb{P}$, đồng thời $V_1+V_2$ và $V_1\cap V_2$ cũng hữu hạn chiều. Các mệnh đề sau tương đương:

    1.  $V_1+V_2=V_1\oplus V_2$.

    2.  $\dim V_1+\dim V_2=\dim(V_1+V_2)$.

    3.  Nếu $a_1,a_2,\dots,a_n$ là một cơ sở của $V_1$, và $b_1,b_2,\dots,b_m$ là một cơ sở của $V_2$, thì $a_1,a_2,\dots,a_n,b_1,b_2,\dots,b_m$ là một cơ sở của $V_1+V_2$.

    ???+ note "Ghi chú"
        Hai mệnh đề 1 và 3 có thể được mở rộng sang không gian tuyến tính vô hạn chiều.

<span id="ví-dụ"></span>
## Ví dụ

Xét các cơ sở của $\Bbb{R}^2$.

1.  Như hình:

    ![](./images/basis-1.svg)

    $u,v$ là một cơ sở.

2.  Như hình:

    ![](./images/basis-2.svg)

    $u,v$ là một cơ sở.

3.  Như hình:

    ![](./images/basis-3.svg)

    $u,v$ không phải là một cơ sở, vì $u=-v$.

4.  Như hình:

    ![](./images/basis-4.svg)

    $u,v,w$ không phải là một cơ sở, vì $u+4v+6w=\theta$.

<span id="cơ-sở-trực-giao-và-cơ-sở-trực-chuẩn"></span>
## Cơ sở trực giao và cơ sở trực chuẩn

Nếu một cơ sở $B$ của không gian tuyến tính $V$ thỏa mãn $\forall b,b'\in B,~(b,b')\ne 0\iff b=b'$ (tức các vectơ đôi một trực giao), thì cơ sở này được gọi là **cơ sở trực giao**.

Nếu một cơ sở trực giao $B$ của không gian tuyến tính $V$ còn thỏa mãn $\forall b\in B,~|b|=\sqrt{(b,b)}=1$, thì cơ sở này được gọi là **cơ sở trực chuẩn**.

Mọi cơ sở của không gian tuyến tính hữu hạn chiều $V$ đều có thể được biến đổi thành cơ sở trực giao bằng [trực giao hóa Schmidt](https://en.wikipedia.org/wiki/Gram–Schmidt_process).

<span id="ứng-dụng"></span>
## Ứng dụng

Từ các nội dung phía trước, ta có thể dùng cơ sở tuyến tính để:

1.  Tìm hạng của một hệ vectơ cho trước.
2.  Với một hệ vectơ cho trước, tìm một hệ con độc lập tuyến tính cực đại (hoặc một cơ sở của không gian tuyến tính do nó sinh ra).
3.  Chèn một số vectơ vào hệ vectơ cho trước, rồi tìm một hệ con độc lập tuyến tính cực đại (hoặc một cơ sở của không gian tuyến tính do nó sinh ra) trong hệ vectơ sau khi chèn.
4.  Với một hệ con độc lập tuyến tính cực đại (hoặc cơ sở) đã tìm được, phán đoán một vectơ có thể được biểu diễn tuyến tính bởi nó hay không.
5.  Với một hệ con độc lập tuyến tính cực đại (hoặc cơ sở) đã tìm được, tìm các phần tử đặc biệt trong không gian tuyến tính do nó sinh ra, chẳng hạn phần tử lớn nhất, nhỏ nhất, v.v.

Trong OI, ta thường gọi cơ sở tuyến tính trong không gian tuyến tính thực $n$ chiều $\mathbf{R}^n$ là **cơ sở tuyến tính thực**, và cơ sở tuyến tính trong không gian tuyến tính $n$ chiều trên trường Boolean $\mathbf{Z}_2^n$ là **cơ sở tuyến tính XOR**.

???+ tip "Mẹo"
    Trong $\mathbf{Z}_2$, phép cộng là XOR, phép nhân là AND; có thể chứng minh $\mathbf{Z}_2$ là một trường.
    
    Có thể chứng minh hệ đại số $(\mathbf{Z}_2^n,+,\cdot,\mathbf{Z}_2)$ là một không gian tuyến tính, trong đó:
    
    $$
    (a_1,\dots,a_n)+(b_1,\dots,b_n):=(a_1+b_1,\dots,a_n+b_n),
    $$
    
    $$
    k\cdot(a_1,\dots,a_n):=(ka_1,\dots,ka_n).
    $$
    
    Tức phép cộng là XOR, nhân vô hướng là AND.

Lấy cơ sở tuyến tính XOR làm ví dụ. Với một hệ dãy Boolean cho trước $X=\{x_1,\dots,x_m\}$, ta có thể xây dựng một cơ sở tuyến tính XOR $B=\{b_1,\dots,b_n\}$. Cơ sở này có các tính chất sau:

1.  XOR của mọi tập con không rỗng của $B$ khác $0$.
2.  Với mọi phần tử $x$ trong $X$, có thể lấy một số phần tử trong $B$ sao cho XOR của chúng bằng $x$.
3.  Với mọi tập $B'$ thỏa mãn hai điều trên, số phần tử của nó không nhỏ hơn số phần tử của $B$.

Ta có thể dùng cơ sở tuyến tính XOR để:

1.  Kiểm tra một số có thể được biểu diễn thành XOR của một tập con của một tập số hay không.
2.  Tính số cách biểu diễn một số thành XOR của một tập con của một tập số.
3.  Tìm giá trị XOR lớn nhất/nhỏ nhất/lớn thứ $k$/nhỏ thứ $k$ của các tập con của một tập số.
4.  Tìm thứ hạng của một số trong các giá trị XOR của các tập con của một tập số.

<span id="phương-pháp-xây-dựng"></span>
### Phương pháp xây dựng

Vì cơ sở tuyến tính XOR và cơ sở tuyến tính thực không khác nhau về bản chất, phần tiếp theo sẽ lấy cơ sở tuyến tính XOR làm ví dụ; phiên bản mã cho cơ sở tuyến tính thực chỉ cần sửa đổi đơn giản.

<span id="phương-pháp-tham-lam"></span>
#### Phương pháp tham lam

Với mỗi số $p$ trong tập ban đầu, chuyển nó sang dạng nhị phân và quét từ bit cao xuống bit thấp. Với bit thứ $x$ bằng $1$, nếu $a_x$ chưa tồn tại thì gán $a_x \leftarrow p$ và kết thúc quét; nếu đã tồn tại thì gán $p\leftarrow p~\text{xor}~a_x$.

Để truy vấn giá trị lớn nhất của XOR của một số phần tử bất kỳ trong tập ban đầu, chỉ cần quét cơ sở tuyến tính từ bit cao xuống bit thấp; nếu XOR với $a_x$ hiện đang quét làm đáp án lớn hơn, thì XOR đáp án với $a_x$.

Vì sao cách này đúng? Vì khi quét từ cao xuống thấp, nếu đang quét tới bit thứ $i$, ta có thể đảm bảo bit thứ $i$ của đáp án là $1$, và về sau không còn cơ hội thay đổi bit thứ $i$ nữa.

Giá trị nhỏ nhất của XOR của một số phần tử bất kỳ trong tập ban đầu chính là phần tử nhỏ nhất trong tập cơ sở tuyến tính.

Để kiểm tra một số có thể được XOR ra hay không, làm tương tự thao tác chèn; nếu cuối cùng số $p$ cần chèn bị XOR thành $0$, thì số đó có thể được XOR ra.

??? example "Mã nguồn (Luogu P3812 [Mẫu: cơ sở tuyến tính](https://www.luogu.com.cn/problem/P3812))"
    ```cpp
    --8<-- "docs/math/code/basis/basis_1.cpp"
    ```

<span id="phương-pháp-khử-gauss"></span>
#### Phương pháp khử Gauss

Phương pháp khử Gauss tương đương với việc xây dựng cơ sở tuyến tính từ góc độ hệ phương trình tuyến tính, nên tính đúng đắn là hiển nhiên.

??? example "Mã nguồn (Luogu P3812 [Mẫu: cơ sở tuyến tính](https://www.luogu.com.cn/problem/P3812))"
    ```cpp
    --8<-- "docs/math/code/basis/basis_2.cpp"
    ```

<span id="tính-chất-1"></span>
### Tính chất

Cơ sở tuyến tính xây dựng bằng phương pháp tham lam có các tính chất sau:

-   Cơ sở tuyến tính không có tập con nào có XOR bằng $0$.
-   Các số trong cơ sở tuyến tính có bit cao nhất trong biểu diễn nhị phân đôi một khác nhau.

Cơ sở tuyến tính xây dựng bằng phương pháp khử Gauss thỏa mãn tính chất sau:

-   Ma trận sau khử Gauss là một ma trận bậc thang rút gọn theo hàng.

    > Tính chất này bao gồm cả hai tính chất của cơ sở tuyến tính xây dựng bằng phương pháp tham lam.

    Nếu chưa hiểu vì sao tính chất này đúng, có thể chuyển tới [khử Gauss](../numerical/gauss.md).

Cho một mẫu:

```text
5
633 211 169 841 1008
```

Biểu diễn nhị phân:

```text
1001111001
0011010011
0010101001
1101001001
1111110000
```

Cơ sở tuyến tính sinh bởi phương pháp tham lam:

```text
1001111001
0100110000
0011010011
0001111010
0000000000
0000010000
0000000000
0000000000
0000000000
0000000000
```

Cơ sở tuyến tính sinh bởi phương pháp khử Gauss:

```text
1000000011
0100100000
0010101001
0001101010
0000010000
0000000000
0000000000
0000000000
0000000000
0000000000
```

Đây là một tính chất rất hữu ích, giúp ta giải nhiều bài toán thuận tiện hơn. Ví dụ: cho một số số, chọn một vài số trong đó để XOR lại và tìm giá trị XOR lớn nhất. Nếu dùng phương pháp tham lam để xây dựng cơ sở tuyến tính, cần làm thêm một lần tham lam: nếu bit hiện tại của `ans` là `0`, thì XOR chắc chắn tốt hơn; nếu bit hiện tại là `1`, thì chắc chắn không tốt hơn. Còn sau khi dùng khử Gauss để xây dựng cơ sở tuyến tính, chỉ cần XOR tất cả phần tử trong cơ sở tuyến tính rồi xuất ra.

Với các bài toán kinh điển khác như truy vấn một số có thể được XOR ra hay không, truy vấn số lớn thứ $k$ có thể được XOR ra, v.v., cơ sở tuyến tính thu được từ khử Gauss cũng giải quyết thuận tiện hơn.

<span id="độ-phức-tạp-thời-gian"></span>
### Độ phức tạp thời gian

Giả sử độ dài vectơ là $n$, tổng số vectơ là $m$, khi đó độ phức tạp thời gian là $O(nm)$. Hằng số của phương pháp khử Gauss lớn hơn một chút.

Nếu là cơ sở tuyến tính thực, độ phức tạp thời gian là $O(n^2m)$.

<span id="hợp-nhất-cơ-sở-tuyến-tính"></span>
### Hợp nhất cơ sở tuyến tính

Việc hợp nhất cơ sở tuyến tính chỉ cần xử lý trực tiếp: chèn thô toàn bộ cơ sở tuyến tính cần hợp nhất vào cơ sở tuyến tính còn lại. Độ phức tạp cho một lần hợp nhất là $O(n^2)$ (cơ sở tuyến tính XOR) hoặc $O(n^3)$ (cơ sở tuyến tính thực).

<span id="tìm-giao-của-cơ-sở-tuyến-tính"></span>
### Tìm giao của cơ sở tuyến tính

Nói chặt chẽ, tìm giao của cơ sở tuyến tính là tìm một cơ sở tuyến tính của giao của hai không gian tuyến tính do chúng sinh ra. Phần này giới thiệu hai thuật toán. Cả hai thuật toán đều có độ phức tạp cho một lần tìm giao là $O(n^2)$ (cơ sở tuyến tính XOR) hoặc $O(n^3)$ (cơ sở tuyến tính thực).

<span id="thuật-toán-đơn-giản"></span>
#### Thuật toán đơn giản

Giả sử hai cơ sở tuyến tính cần tìm giao lần lượt là $\alpha$ và $\beta$. Thuật toán tìm giao của cơ sở tuyến tính chỉ cần điều chỉnh thuật toán hợp nhất thô cơ sở tuyến tính như sau (lấy cơ sở tuyến tính XOR làm ví dụ):

-   Thử chèn vectơ $\beta_j$ trong cơ sở tuyến tính $\beta$ vào $\alpha$ bằng [phương pháp tham lam](#phương-pháp-tham-lam), đồng thời khởi tạo giao $\gamma$ của các cơ sở tuyến tính là tập rỗng.
-   Khi chèn, cần ghi lại đóng góp của các phần tử trong cơ sở tuyến tính $\beta$ vào vectơ đang chèn. Cụ thể, duy trì một vectơ mới $b$, khởi tạo bằng $\beta_j$; hơn nữa, nếu vectơ đang chèn đã XOR với vectơ ở bit thứ $x$ trong cơ sở tuyến tính, thì đóng góp $b$ cũng phải XOR một lần với đóng góp $b_x$ được ghi ở bit thứ $x$.
-   Nếu chèn thành công, tức đã chèn vectơ $\beta_j'$ vào bit thứ $x$ của cơ sở tuyến tính, thì đổi $b_x$ được ghi ở bit thứ $x$ thành đóng góp $b$ của các phần tử trong cơ sở tuyến tính $\beta$ trong quá trình thu được $\beta_j'$.
-   Nếu chèn không thành công, thì chèn đóng góp $b$ của các phần tử trong cơ sở tuyến tính $\beta$ đã ghi trong quá trình đó vào $\gamma$.

Cơ sở tuyến tính $\gamma$ thu được theo cách này chính là giao cần tìm. Tất nhiên, thuật toán này đồng thời cũng tìm được tổng của các cơ sở tuyến tính.

??? note "Giải thích thuật toán"
    Giả sử cơ sở tuyến tính sau khi hợp nhất là $\{\alpha_1,\cdots,\alpha_m,\beta'_{j_1},\cdots,\beta'_{j_\ell}\}$, trong đó $\beta'_{j_k}$ là vectơ cuối cùng thu được khi chèn $\beta_{j_k}$. Khi đó $\{\alpha_1,\cdots,\alpha_m,\beta_{j_1},\cdots,\beta_{j_\ell}\}$ cũng là một cơ sở tuyến tính sau khi hợp nhất. Ký hiệu $\beta^+$ là tập $\{\beta_{j_1},\cdots,\beta_{j_\ell}\}$, thì cơ sở sau hợp nhất có thể viết là $\alpha\cup\beta^+$. Hơn nữa, mọi vectơ $c$ trong không gian tổng đều có thể được biểu diễn duy nhất dưới dạng
    
    $$
    c = a\oplus b
    $$
    
    trong đó $a\in\operatorname{span}\alpha$ và $b\in\operatorname{span}\beta^+$. Thành phần $b$ trong phân rã này chính là "đóng góp của các phần tử trong cơ sở tuyến tính $\beta$" mà thuật toán phía trước **cố gắng** ghi lại. Nói chặt chẽ hơn, đó chỉ là đóng góp của những vectơ trong $\beta$ đã được chèn thành công cuối cùng.
    
    Với một lần chèn thành công, $b$ được ghi lại cuối cùng chính là thành phần $b$ trong phân rã trên. Giả sử $\beta_j\in\beta^+$. Ban đầu, $\beta_j=0\oplus\beta_j$, đã là phân rã đúng của $\beta_j$ trên cơ sở $\alpha\cup\beta^+$. Khi cập nhật $\beta'_j=a\oplus b$ thành $\beta'_j\oplus c_x$, vì $\beta_j'\oplus c_x=(a\oplus a_x)\oplus(b\oplus b_x)$, nên chỉ cần cập nhật $b$ thành $b\oplus b_x$ là vẫn đảm bảo phân rã đúng. Vì thế theo quy nạp, khi cuối cùng chèn $\beta'_j$ vào cơ sở tuyến tính sau hợp nhất, đóng góp $b$ được ghi lại chính là thành phần $b$ trong phân rã nói trên.
    
    Với một lần chèn không thành công, biến cuối cùng cần chèn chắc chắn trở thành $0$, và đóng góp $b$ lúc này cần được chèn vào $\gamma$. Nếu lặp lại lập luận phía trên, ta sẽ thấy trong quá trình chèn vẫn luôn đảm bảo $\beta_j'=a\oplus b$, với $a\in\operatorname{span}\alpha$, chỉ là $b$ không còn thuộc $\operatorname{span}\beta^+$. Nguyên nhân là ở thời điểm khởi tạo, trong $\beta_j=0\oplus\beta_j$ thì $\beta_j\notin\beta^+$. Ngoài điểm này, các hạng tử được XOR khi cập nhật đóng góp đều thuộc $\operatorname{span}\beta^+$. Vì vậy thực ra có $b\oplus\beta_j\in\operatorname{span}\beta^+$.
    
    Vậy vì sao chèn tất cả các $b$ từ những lần chèn không thành công vào $\gamma$ lại thu được cơ sở tuyến tính của không gian giao? Trước hết, nếu chèn $\beta_j$ không thành công, cuối cùng chắc chắn thu được $0=a\oplus b$, trong đó $a\in\operatorname{span}\alpha$ và $b\in\operatorname{span}(\beta^+\cup\{\beta_j\})\subseteq\operatorname{span}\beta$. Do đó $b=a$ nhất định nằm trong không gian giao $\operatorname{span}\alpha\cap\operatorname{span}\beta$. Ngược lại, giả sử $c$ là một phần tử bất kỳ trong không gian giao. Vì $c\in\operatorname{span}\beta$, nên $c$ có thể được biểu diễn thành tổ hợp tuyến tính (XOR) của các phần tử trong $\beta$:
    
    $$
    c = \bigoplus_{\beta_j\in\beta}\lambda_j\beta_j,
    $$
    
    trong đó $\lambda_j\in\{0,1\}$. Với mỗi $\beta_j\notin\beta^+$, gọi đóng góp tương ứng được chèn vào $\gamma$ là $b_j$, ta có
    
    $$
    c\oplus\bigoplus_{\beta_j\notin\beta^+}\lambda_jb_j = \bigoplus_{\beta_j\in\beta^+}\lambda_j\beta_j+\bigoplus_{\beta_j\notin\beta^+}\lambda_j(\beta_j\oplus b_j),
    $$
    
    Chú ý rằng $b_j$ và $c$ đều nằm trong không gian giao, nên vế trái cũng nhất định nằm trong không gian giao; do đó vế trái có thể viết thành tổ hợp tuyến tính của các phần tử trong $\alpha$. Đồng thời, mọi hạng tử ở vế phải hoặc là $\beta_j\in\beta^+$, hoặc là $\beta_j\notin\beta^+$ và $\beta_j\oplus b_j\in\beta^+$; vì vậy vế phải thực chất là tổ hợp tuyến tính của các phần tử trong $\beta^+$. Nhưng $\alpha\cup\beta^+$ độc lập tuyến tính, nên mọi hệ số đều bằng $0$, tức $c=\bigoplus_{\beta_j\notin\beta^+}\lambda_jb_j\in\operatorname{span}\{b_1,\cdots,b_j\}$. Điều này chứng tỏ các đóng góp $b$ của những vectơ không thể chèn cùng nhau sinh ra không gian giao.
    
    Theo cách giải thích này, mục đích của việc duy trì đóng góp $b$ trong quá trình là để duy trì phân rã $a\oplus b$; hơn nữa khi cuối cùng chèn đóng góp vào $\gamma$ thì luôn có $a=b$. Vì vậy, dù duy trì đóng góp của các phần tử trong $\alpha$ hay trong $\beta$ (tức duy trì $a$ hay $b$), kết quả đều đúng. Nếu muốn duy trì đóng góp của các phần tử trong cơ sở tuyến tính $\alpha$, chỉ cần sửa giá trị đóng góp tương ứng lúc khởi tạo: mỗi vectơ $\alpha_i$ trong $\alpha$ ban đầu có đóng góp $\alpha_i$, còn $\beta_j$ được chèn vào có đóng góp ban đầu là $0$.

Mã mẫu cho bài toán mẫu như sau:

??? example "Mã nguồn (Library Checker [Intersection of $\mathbf F_2$ vector spaces](https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces))"
    ```cpp
    --8<-- "docs/math/code/basis/basis_intersect_1.cpp"
    ```

<span id="thuật-toán-zassenhaus"></span>
#### Thuật toán Zassenhaus

Một cách làm tương đương khác là thuật toán Zassenhaus; nó cũng có thể tính đồng thời tổng và giao của hai cơ sở tuyến tính. Độ phức tạp hoàn toàn giống phần trên.

Các bước cụ thể như sau:

-   Khởi tạo một cơ sở tuyến tính $\gamma$ rỗng có độ dài vectơ là $2n$, trong đó mỗi vectơ viết dưới dạng $(a,b)$, và $a,b$ đều có độ dài $n$.
-   Chèn mỗi phần tử $\alpha_i$ trong $\alpha$ vào $\gamma$ dưới dạng $(\alpha_i,\alpha_i)$.
-   Chèn mỗi phần tử $\beta_j$ trong $\beta$ vào $\gamma$ dưới dạng $(\beta_j,0)$.
-   Trong tất cả phần tử khác không $(c_k,d_k)$ của cơ sở tuyến tính $\gamma$ cuối cùng, tập các thành phần $c_k$ của những vectơ có $c_k$ khác không tạo thành cơ sở tuyến tính của tổng của $\alpha$ và $\beta$; tập các thành phần $d_k$ của những vectơ có $c_k$ bằng không tạo thành cơ sở tuyến tính của giao của $\alpha$ và $\beta$.

Phương pháp xây dựng cơ sở tuyến tính trong thuật toán có thể là [phương pháp tham lam](#phương-pháp-tham-lam) hoặc [phương pháp khử Gauss](#phương-pháp-khử-gauss), miễn là đảm bảo cơ sở tuyến tính trong $\gamma$ tạo thành một ma trận bậc thang theo hàng.

So sánh các bước khử trong thuật toán Zassenhaus với thuật toán đơn giản phía trên, rất dễ thấy thuật toán Zassenhaus dựa trên tham lam tương đương với thuật toán đơn giản duy trì đóng góp của các phần tử trong $\alpha$. Nếu chuyển sang chèn trước tất cả $(\alpha_i,0)$, rồi chèn tất cả $(\beta_j,\beta_j)$, thì thuật toán Zassenhaus dựa trên tham lam tương đương với thuật toán đơn giản duy trì đóng góp của các phần tử trong $\beta$. Từ tính tương đương của các bước khử, tính đúng đắn của thuật toán Zassenhaus cũng được đảm bảo.

Ngoài ra, ta cũng có thể đưa ra một chứng minh đại số độc lập và tổng quát hơn:

??? note "Chứng minh tính đúng đắn"
    Giả sử $V$ là một không gian tuyến tính, và có các không gian con $U=\operatorname{span}\alpha$ và $W=\operatorname{span}\beta$. Bản thân thuật toán tương đương với việc tìm một cơ sở $\gamma$ của không gian con
    
    $$
    H = \operatorname{span}(\{(\alpha_i,\alpha_i):\alpha_i\in\alpha\}\cup\{(\beta_j,0):\beta_j\in\beta\})
    $$
    
    bằng cách rút gọn về dạng bậc thang theo hàng. Sau cùng, các phần tử $(c_k,d_k)$ trong $\gamma$ cần được chia thành hai loại theo việc $c_k\neq 0$ hay không, nên ta xét ánh xạ chiếu $\pi:H\rightarrow V$ với $\pi(a,b)=a$. Khi đó $\pi(H)=U+W$ và dễ kiểm tra rằng
    
    $$
    \begin{aligned}
    \ker\pi &= H\cap(\{0\}\times V) = \{0\}\times(U\times W).
    \end{aligned}
    $$
    
    Theo [các định lý liên quan của ánh xạ tuyến tính](./linear-mapping.md#không-gian-hạt-nhân-và-không-gian-ảnh-của-ánh-xạ-tuyến-tính), có $\dim H = \dim\pi(H)+\dim\ker\pi = \dim(U+W)+\dim(U\cap W)$.
    
    Các cột đầu của một ma trận bậc thang theo hàng vẫn là một ma trận bậc thang theo hàng, nên số hàng có $c_k\neq 0$ đúng bằng hạng hàng của $\alpha\cup\beta$, tức $\dim(U+W)$; hơn nữa, tập các $c_k$ trong những hàng này tạo thành một cơ sở của $U+W$. Các hàng khác không còn lại đúng bằng $\dim(U\cap W)$ hàng và đều thỏa mãn $c_k=0$. Với các $d_k$ trong những hàng này, vì $(0,d_k)\in\ker\pi$, nên $d_k\in U\cap W$; hơn nữa, các $(0,d_k)$ là các hàng của một ma trận bậc thang theo hàng nên nhất định độc lập tuyến tính. Tổng hợp lại, các $d_k$ này là một hệ độc lập tuyến tính trong không gian giao $U\cap W$ có kích thước $\dim(U\cap W)$, nên chắc chắn là một cơ sở của không gian đó.

Mã mẫu cho bài toán mẫu như sau:

??? example "Mã nguồn (Library Checker [Intersection of $\mathbf F_2$ vector spaces](https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces))"
    ```cpp
    --8<-- "docs/math/code/basis/basis_intersect_2.cpp"
    ```

Chú ý rằng khi xuất, chỉ cần xét những vectơ có $n$ bit đầu đều bằng không.

<span id="mở-rộng-cơ-sở-tuyến-tính-tiền-tố"></span>
### Mở rộng: cơ sở tuyến tính tiền tố

Phần này chỉ thảo luận trường hợp cơ sở tuyến tính XOR, đồng thời giả sử một vectơ đơn lẻ có thể lưu trong không gian $O(1)$, và độ phức tạp của mỗi thao tác luôn là $O(1)$.

Với tình huống cần nhiều lần truy vấn giá trị XOR lớn nhất trên đoạn, một cách thường gặp là dùng [cat tree](../../ds/cat-tree.md) kết hợp với cơ sở tuyến tính, có độ phức tạp thời gian $O(nm\log m+n^2q)$, trong đó $n$ là độ dài vectơ, $m$ là độ dài dãy, $q$ là số truy vấn. Một cách khả thi khác là dùng cơ sở tuyến tính tiền tố (còn gọi là cơ sở tuyến tính dấu thời gian), giúp giảm độ phức tạp xuống $O(n(m+q))$.

Cơ sở tuyến tính tiền tố cho phép với mỗi tiền tố của dãy, duy trì cơ sở tuyến tính của mọi hậu tố của tiền tố đó, nhờ vậy hỗ trợ truy vấn cơ sở tuyến tính của mỗi đoạn. Chú ý rằng cơ sở tuyến tính của mọi hậu tố $[j,i]$ của một tiền tố $[1,i]$ của dãy có quan hệ chứa nhau: cơ sở tuyến tính của $[j,i]$ luôn chứa cơ sở tuyến tính của $[j+1,i]$. Vì vậy trong các cơ sở tuyến tính của những hậu tố này, nhiều nhất chỉ có $n$ loại khác nhau, và luôn có thể thu được toàn bộ cơ sở tuyến tính của các hậu tố từ $[i,i]$ đến $[1,i]$ bằng cách từng bước thêm vectơ mới vào tập rỗng. Do đó, lợi dụng tính đơn điệu này, chỉ cần với mỗi vectơ $v$ được thêm vào, đánh dấu chỉ số xuất hiện lớn nhất $t$ của nó, là có thể lưu mọi cơ sở tuyến tính của hậu tố trong không gian $O(n)$. Hơn nữa, khi truy vấn cơ sở tuyến tính tương ứng với đoạn $[j,i]$, chỉ cần trong cơ sở tuyến tính tiền tố tại $i$ giữ lại các vectơ có nhãn $t\ge j$.

Ta gọi nhãn $t$ của mỗi vectơ $v$ là dấu thời gian của nó. Một vectơ $v$ trong cơ sở tuyến tính luôn có thể được biểu diễn thành XOR của một số phần tử trong dãy ban đầu, chẳng hạn $v_{i_1}\oplus v_{i_2}\oplus\cdots\oplus v_{i_k}$. Trong tất cả các biểu diễn khả dĩ như vậy, giá trị lớn nhất của chỉ số nhỏ nhất chính là $t$, tức:

$$
t(v) = \max\{j:\exists i_1,\cdots,i_k\in[j,i]\text{ với điều kiện }v=v_{i_1}\oplus v_{i_2}\oplus\cdots\oplus v_{i_k}\}.
$$

Biểu thức này chỉ là cách viết hình thức cho mô tả ở đoạn trước. Nó gợi ý rằng để duy trì dấu thời gian của mỗi vectơ $v$ trong cơ sở tuyến tính, ta chỉ cần tham lam chọn vectơ mới nhất có thể để thay thế vectơ cũ.

Dựa trên [phương pháp tham lam](#phương-pháp-tham-lam) xây dựng cơ sở tuyến tính đã nêu ở trên, cơ sở tuyến tính tiền tố điều chỉnh quá trình xây dựng như sau:

-   Với mỗi vectơ $a_x$ được giữ trong cơ sở tuyến tính, lưu thêm một dấu thời gian $t_x$, ban đầu đều đặt là $0$.
-   Khi thêm vectơ thứ $i$ của dãy, gọi là $v$, vẫn quét từ bit cao xuống bit thấp, nhưng đồng thời cần ghi lại thời gian hiện tại $i$.
-   Nếu bit thứ $x$ của $v$ là một, so sánh dấu thời gian $t_x$ của vectơ $a_x$ đã có trong cơ sở tuyến tính với thời gian hiện tại $i$:
    -   Nếu $i>t_x$, tức vectơ cần thêm có thời gian muộn hơn, đặt $a_x$ thành $v$, cập nhật dấu thời gian thành $i$, rồi tiếp tục quá trình thêm với kết quả XOR của $a_x$ cũ và $v$, tức $a_x\oplus v$, theo thời gian $t_x$ đã ghi trước đó.
    -   Nếu $i<t_x$, tức vectơ cần thêm có thời gian sớm hơn, không cập nhật $a_x$ và $t_x$, chỉ cần XOR $v$ với $a_x$ rồi tiếp tục thêm.

Nói cách khác, nếu bit hiện tại có thể được biểu diễn bằng vectơ mới hơn, thì dùng trực tiếp vectơ mới hơn; nếu không, giữ lại vectơ ban đầu. Khi cập nhật vectơ ở vị trí $x$, không được lưu kết quả XOR $a_x\oplus v$ vào vị trí $x$, vì dấu thời gian của kết quả XOR $a_x\oplus v$ là $\min\{t(a_x)=t(v)\}=t(a_x)$, nhỏ hơn dấu thời gian $t(v)$ của biến cần thêm $v$. Cũng vì lý do này, bước cập nhật ngược lên trên trong quá trình xây dựng cơ sở tuyến tính bằng [phương pháp khử Gauss](#phương-pháp-khử-gauss) có thể phá hỏng tính chất dấu thời gian, nên không còn phù hợp để xây dựng cơ sở tuyến tính tiền tố.

Mã mẫu cho bài toán mẫu như sau:

??? example "Mã nguồn (Codeforces [1100F Ivan and Burgers](https://codeforces.com/problemset/problem/1100/F))"
    ```cpp
    --8<-- "docs/math/code/basis/prefix_basis.cpp"
    ```

Nếu cần truy vấn trực tuyến, cũng có thể dùng không gian $O(mn)$ để lưu lại cơ sở tuyến tính tiền tố tại mỗi tiền tố rồi truy vấn; cách này có thể xem như một cơ sở tuyến tính "khả bền vững". Nếu cần dùng các tính chất của cơ sở tuyến tính thu được từ khử Gauss, có thể xử lý riêng khi truy vấn.

<span id="bài-tập"></span>
### Bài tập

-   [Luogu P3812 Mẫu: cơ sở tuyến tính](https://www.luogu.com.cn/problem/P3812)
-   [Acwing 3164. Linear Basis](https://www.acwing.com/problem/content/description/3167)
-   [SGU 275 to xor or not xor](https://codeforces.com/problemsets/acmsguru/problem/99999/275)
-   [HDU 3949 XOR](https://acm.hdu.edu.cn/showproblem.php?pid=3949)
-   [HDU 6579 Operation](https://acm.hdu.edu.cn/showproblem.php?pid=6579)
-   [Luogu P4151 [WC2011] Maximum XOR Sum Path](https://www.luogu.com.cn/problem/P4151)
-   [Library Checker - Intersection of $\mathbf F_2$ vector spaces](https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces)
-   [AtCoder Grand Contest 045 A - Xor Battle](https://atcoder.jp/contests/agc045/tasks/agc045_a)
-   [Codeforces 1100F Ivan and Burgers](https://codeforces.com/problemset/problem/1100/F)
-   [Luogu P3292 [SCOI2016] Lucky Numbers](https://www.luogu.com.cn/problem/P3292)

<span id="tài-liệu-tham-khảo-và-chú-thích"></span>
## Tài liệu tham khảo và chú thích

1.  Qiu Weisheng, *Advanced Algebra (Vol. 2)*. Tsinghua University Press.
2.  [Basis (linear algebra) - Wikipedia](https://en.wikipedia.org/wiki/Basis_%28linear_algebra%29)
3.  [Vector Basis -- from Wolfram MathWorld](https://mathworld.wolfram.com/VectorBasis.html)
4.  [Zassenhaus algorithm - Wikipedia](https://en.wikipedia.org/wiki/Zassenhaus_algorithm)

[^existence_basis]: [Proof that every vector space has a basis](https://en.wikipedia.org/wiki/Basis_%28linear_algebra%29#Proof_that_every_vector_space_has_a_basis)
