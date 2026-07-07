author: ChungZH, Yukimaikoriya, tigerruanyifan, isdanni, Saisyc, 383494, Tiphereth-A, XuYueming520

<span id="giới-thiệu"></span>

## Giới thiệu

**Biến đổi số học** (number-theoretic transform, NTT) là cách hiện thực biến đổi Fourier rời rạc (DFT) trên nền tảng số học; **biến đổi số học nhanh** (fast number-theoretic transform, FNTT) là cách hiện thực [biến đổi Fourier nhanh](./fft.md) (FFT) trên nền tảng số học.

**Biến đổi số học** là một thuật toán nhanh để tính tích chập (convolution). Một trong những thuật toán thường dùng nhất chính là biến đổi Fourier nhanh đã nhắc ở phần trước. Tuy nhiên, FFT có một số nhược điểm khi hiện thực: vector dữ liệu phải được xử lý bằng cách nhân với ma trận hệ số phức, mà phần thực và phần ảo của mỗi hệ số phức là các giá trị của hàm sin và cos, nên phần lớn hệ số là số thực dấu phẩy động. Nói cách khác, cần thực hiện phép toán trên số phức và số dấu phẩy động, khiến lượng tính toán lớn hơn và sai số do phép toán dấu phẩy động cũng đáng kể hơn.

NTT xử lý trường hợp nhân đa thức có lấy dư theo môđun. Có thể nói nó chịu một số ràng buộc từ môđun, và các số thường tương đối lớn. Môđun phổ biến nhất hiện nay là 998244353.

<span id="kiến-thức-cần-có"></span>

## Kiến thức cần có

Để học biến đổi số học, cần biết trước về biến đổi Fourier rời rạc, nhóm con sinh, [căn nguyên thủy](../number-theory/primitive-root.md) và logarit rời rạc. Các kiến thức liên quan có thể học ở các trang tương ứng, nên phần này không nhắc lại.

<span id="định-nghĩa"></span>

## Định nghĩa

<span id="biến-đổi-số-học"></span>

### Biến đổi số học

Trong toán học, NTT là biến đổi Fourier rời rạc (DFT) trên một [vành](../algebra/basic.md#vành) bất kì. Trong trường hợp trường hữu hạn, nó thường được gọi là biến đổi số học (NTT).

**Biến đổi số học** (NTT) thu được bằng cách chuyển biến đổi Fourier rời rạc sang $F={\mathbb {Z}/p}$, tức các số nguyên theo môđun số nguyên tố $p$. Đây là một **trường hữu hạn**. Miễn là $n$ chia hết $p-1$, sẽ tồn tại căn nguyên thủy bậc $n$, nên suy ra $p=\xi n+1$ với số nguyên dương $\xi$. Cụ thể, với số nguyên tố $p=qn+1, (n=2^m)$, căn nguyên thủy $g$ thỏa mãn $g^{qn} \equiv 1 \pmod p$; nếu xem $g_n=g^q\pmod p$ là phần tử tương ứng với $\omega_n$, thì nó thỏa mãn các tính chất tương tự, chẳng hạn $g_n^n \equiv 1 \pmod p, g_n^{n/2} \equiv -1 \pmod p$.

Vì phần này liên quan đến biến đổi số học, nên $N$ (để phân biệt với $n$ trong FFT, ký hiệu $n$ được đổi thành $N$) có thể lớn hơn $n$ trong FFT; chỉ cần xem $\frac{qN}{n}$ là $q$ trong ngữ cảnh này là đủ để tránh vấn đề về kích thước.

Các môđun thường gặp gồm:

$$
p = 167772161 = 5 \times 2^{25}+1, g=3
$$

$$
p = 469762049 = 7 \times 2^{26}+1, g=3
$$

$$
p = 754974721 = 3^2 \times 5 \times 2^{24}+1, g=11
$$

$$
p = 998244353 = 7 \times 17 \times 2^{23}+1, g=3
$$

$$
p = 1004535809 = 479 \times 2^{21}+1, g=3
$$

Tức là $g^{qn}$ tương ứng với $\mathrm{e}^{2\pi \mathrm{i} n}$.

Khi lặp đến độ dài $l$, thu được $g_l = g^{\frac{p-1}{l}}$, hoặc $\omega_n = g_l = g_N^{\frac{N}{l}} = g_N^{\frac{p-1}{l}}$.

<span id="biến-đổi-số-học-nhanh"></span>

## Biến đổi số học nhanh

**Biến đổi số học nhanh** (FNTT) là thuật toán nhanh thu được bằng cách thêm thao tác chia để trị vào biến đổi số học (NTT).

Phương pháp chia để trị mà FNTT sử dụng hoàn toàn giống với phương pháp chia để trị của FFT. Điều này có nghĩa là chỉ cần sửa đơn giản từ mã FFT là có thể thu được mã FNTT.

Trong thi lập trình, thuật ngữ NTT thường chỉ FNTT; thông thường, khi nói "biến đổi số học" thì mặc định là "biến đổi số học nhanh".

Cách viết tắt này tương tự biến đổi Fourier nhanh. Thuật ngữ "biến đổi Fourier nhanh" (FFT) vốn chỉ "biến đổi Fourier rời rạc nhanh" (FDFT), nhưng tính chất "nhanh" chỉ áp dụng cho trường hợp rời rạc, cụ thể hơn là trường hợp bậc của căn đơn vị nguyên thủy là lũy thừa của $2$, chứ không áp dụng cho trường hợp liên tục, nên từ "rời rạc" được lược bỏ. Vì vậy FDFT trở thành FFT, tức FFT luôn chỉ trường hợp rời rạc đặc biệt đó.

Biến đổi số học hoặc biến đổi số học nhanh là phép toán theo môđun, không có trường hợp liên tục, nên luôn là rời rạc và tự nhiên không cần nhắc đến từ "rời rạc".

Trong lĩnh vực thuật toán, các thao tác không được tăng tốc thường không có ý nghĩa thực tiễn. Khi giới thiệu thuật ngữ DFT trong biến đổi Fourier nhanh, lí do là DFT còn có các ứng dụng cụ thể khác trong xử lý tín hiệu và xử lý ảnh, đồng thời DFT cũng là nguyên lý hoặc kiến thức nền của FFT.

Khi không gây nhầm lẫn, NTT thường được dùng để chỉ FNTT. Để tránh nhầm lẫn trong phần trình bày tiếp theo, dưới đây hai thuật ngữ NTT và FNTT được tách riêng.

Quan hệ cụ thể giữa DFT, FFT, NTT và FNTT là:

-   Trên cơ sở DFT và NTT, thêm thao tác chia để trị để thu được FFT và FNTT. Phương pháp và nguyên lý của thao tác chia để trị có thể xem trong bài về biến đổi Fourier nhanh.

-   Trên cơ sở DFT và FFT, thay phép cộng và phép nhân số phức bằng phép cộng và phép nhân theo môđun $p$, thường giới hạn giá trị trong khoảng từ $0$ đến $p-1$; thay căn đơn vị nguyên thủy bằng căn đơn vị nguyên thủy cùng bậc theo môđun $p$, với bậc là lũy thừa của $2$, thì có thể thu được NTT và FNTT.

Vì các phép toán được thay thế chỉ gồm cộng và nhân, nên DFT, FFT, NTT và FNTT có cùng nguyên lý: đều thực hiện trên một vành thỏa mãn phép cộng và phép nhân, không cần điều kiện chặt hơn là phải có phép chia như trên trường.

Miễn là có căn nguyên thủy, tức phần tử sinh trong lý thuyết nhóm, thì NTT hoặc FNTT theo môđun đó có thể thực hiện được. Xét rằng các môđun $1$, $2$ và $4$ quá nhỏ và không có ý nghĩa thực tế, với số nguyên tố lẻ $p$ và số nguyên dương $\alpha$, khi đã có căn nguyên thủy $g$ theo môđun $p^\alpha$ và $2p^\alpha$, cùng phương pháp vẫn cho phép thực hiện NTT hoặc FNTT.

<span id="mẫu"></span>

## Mẫu

??? example "[Library Checker - Tích chập](https://judge.yosupo.jp/problem/convolution_mod)"
    ```cpp
    --8<-- "docs/math/code/poly/ntt/ntt_1.cpp"
    ```

<span id="tài-liệu-tham-khảo-và-đọc-thêm"></span>

## Tài liệu tham khảo và đọc thêm

1.  [FWT (biến đổi Walsh nhanh) giải thích chi tiết từ con số 0 qaq (ACM/OI)](https://zhuanlan.zhihu.com/p/41867199)
2.  [FFT (biến đổi Fourier nhanh) giải thích chi tiết từ cơ bản, kèm NTT (ACM/OI)](https://zhuanlan.zhihu.com/p/40505277)
3.  [Biến đổi số học (NTT) - Wikipedia](https://en.wikipedia.org/wiki/Discrete_Fourier_transform_%28general%29#Number-theoretic_transform)
4.  [Hướng dẫn FFT/NTT - biến phần khó thành đơn giản. (Phần 1)](https://codeforces.com/blog/entry/43499)
5.  [Mẫu NTT - blog CSDN của BlackJack_](https://blog.csdn.net/blackjack_/article/details/79346433)
