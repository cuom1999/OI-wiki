<span id="nội-dung"></span>
## Nội dung

Bổ đề nâng số mũ (Lift the Exponent, LTE) là một định lý khá thường dùng trong số học sơ cấp.

Định nghĩa $\nu_p(n)$ là số mũ của thừa số nguyên tố $p$ trong phân tích chuẩn của số nguyên $n$, tức là $\nu_p(n)$ thỏa mãn $p^{\nu_p(n)}\mid n$ và $p^{\nu_p(n)+1}\nmid n$.

Vì nội dung của bổ đề nâng số mũ tương đối dài, phần trình bày được chia thành ba phần.

Trong phần dưới đây, giả sử $p$ là số nguyên tố, $x,y$ là các số nguyên thỏa mãn $p\nmid x$ và $p\nmid y$, còn $n$ là số nguyên dương.

<span id="phần-thứ-nhất"></span>
### Phần thứ nhất

Với mọi số nguyên tố $p$ và số nguyên $n$ thỏa mãn $(n,p)=1$:

1.  Nếu $p\mid x-y$, thì:

    $$
    \nu_p\left(x^n-y^n\right)=\nu_p(x-y)
    $$

2.  Nếu $p\mid x+y$, thì với $n$ lẻ:

    $$
    \nu_p\left(x^n+y^n\right)=\nu_p(x+y)
    $$

???+ note "Chứng minh"
    Nếu $p\mid x-y$, thì $p\mid x-y\iff x\equiv y\pmod p$, nên:
    
    $$
    \sum_{i=0}^{n-1}x^iy^{n-1-i}\equiv nx^{n-1}\not\equiv 0\pmod p
    $$
    
    Từ $x^n-y^n=(x-y)\sum_{i=0}^{n-1}x^iy^{n-1-i}$, suy ra mệnh đề cần chứng minh.
    
    Trường hợp $p\mid x+y$ được chứng minh tương tự.

<span id="phần-thứ-hai"></span>
### Phần thứ hai

Nếu $p$ là số nguyên tố lẻ:

1.  Nếu $p\mid x-y$, thì:

    $$
    \nu_p\left(x^n-y^n\right)=\nu_p(x-y)+\nu_p(n)
    $$

2.  Nếu $p\mid x+y$, thì với $n$ lẻ:

    $$
    \nu_p\left(x^n+y^n\right)=\nu_p(x+y)+\nu_p(n)
    $$

???+ note "Chứng minh"
    Nếu $p\mid x-y$, đặt $y=x+kp$. Chỉ cần chứng minh trường hợp $p\mid n$.
    
    -   Nếu $n=p$, theo định lý nhị thức:
    
        $$
        \begin{aligned}
            \sum_{i=0}^{p-1}x^{p-1-i}y^i&=\sum_{i=0}^{p-1}x^{p-1-i}\sum_{j=0}^i\binom{i}{j}x^j(kp)^{i-j}\\
            &\equiv px^{p-1} \pmod{p^2}\\
        \end{aligned}
        $$
    
        Do đó
    
        $$
        \nu_p\left(x^n-y^n\right)=\nu_p(x-y)+1
        $$
    -   Nếu $n=p^a$, dùng quy nạp toán học suy ra
    
        $$
        \nu_p\left(x^n-y^n\right)=\nu_p(x-y)+a
        $$
    
    Vì vậy mệnh đề được chứng minh.
    
    Trường hợp $p\mid x+y$ được chứng minh tương tự.

<span id="phần-thứ-ba"></span>
### Phần thứ ba

Nếu $p=2$ và $p\mid x-y$:

1.  Với $n$ lẻ, theo phần thứ nhất:

    $$
    \nu_p\left(x^n-y^n\right)=\nu_p(x-y)
    $$

2.  Với $n$ chẵn:

    $$
    \nu_p\left(x^n-y^n\right)=\nu_p(x-y)+\nu_p(x+y)+\nu_p(n)-1
    $$

Ngoài ra, với $x,y,n$ như trên:

Nếu $4\mid x-y$, thì:

-   $\nu_2(x+y)=1$
-   $\nu_2\left(x^n-y^n\right)=\nu_2(x-y)+\nu_2(n)$

???+ note "Chứng minh"
    Chỉ cần chứng minh trường hợp $n$ chẵn. Vì lúc này $p\nmid \dbinom{p}{2}$, không thể dùng phương pháp ở phần thứ hai.
    
    Đặt $n=2^a b$, trong đó $a=\nu_p(n)$ và $2\nmid b$. Khi đó
    
    $$
    \begin{aligned}
        \nu_p\left(x^n-y^n\right)&=\nu_p\left(x^{2^a}-y^{2^a}\right)\\
        &=\nu_p\left((x-y)(x+y)\prod_{i=1}^{a-1}\left(x^{2^i}+y^{2^i}\right)\right)
    \end{aligned}
    $$
    
    Lưu ý rằng $2\mid x-y\implies 4\mid x^2-y^2$, nên $(\forall i\geq 1),~~x^{2^i}+y^{2^i}\equiv 2\pmod 4$. Do đó biểu thức trên trở thành:
    
    $$
    \nu_p\left(x^n-y^n\right)=\nu_p(x-y)+\nu_p(x+y)+\nu_p(n)-1
    $$
    
    Vậy mệnh đề được chứng minh.

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

1.  [Lifting-the-exponent lemma - Wikipedia](https://en.wikipedia.org/wiki/Lifting-the-exponent_lemma)
