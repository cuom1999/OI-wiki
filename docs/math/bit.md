Thao tác bit là các phép toán một ngôi và hai ngôi trên biểu diễn nhị phân của số nguyên, gồm hai nhóm: **phép toán bit** và **dịch bit**. Đây là một trong những loại phép tính cơ bản nhất trong CPU, nên thường có tốc độ rất nhanh.

<span id="số-nguyên-và-chuỗi-bit"></span>

## Số nguyên và chuỗi bit

Xem thêm: [kiểu số nguyên](../lang/var.md#kiểu-số-nguyên), [phương pháp biểu diễn bù](./numeral-sys/base.md#phương-pháp-bù)

Một dãy có độ dài cố định chỉ gồm `0` và `1` được gọi là chuỗi bit. Bit ngoài cùng bên trái được gọi là bit cao nhất, bit ngoài cùng bên phải được gọi là bit thấp nhất.

Máy tính dùng chuỗi bit để biểu diễn các số nguyên trong một phạm vi nhất định. Một chuỗi bit độ dài $N$ chỉ có $2^N$ khả năng, nên nó chỉ có thể tạo quan hệ một-một với $2^N$ số nguyên. Quan hệ một-một này có thể chia thành hai loại: **có dấu** và **không dấu**. Có dấu nghĩa là các số nguyên tương ứng có thể có số âm; không dấu nghĩa là tất cả số nguyên tương ứng đều không âm.

-   Với cách biểu diễn không dấu, có thể dùng trực tiếp biểu diễn nhị phân của số nguyên làm chuỗi bit; nếu chưa đủ độ dài thì thêm `0` vào các bit cao.

    Theo cách biểu diễn không dấu, chuỗi bit độ dài $N$ có thể biểu diễn các số nguyên trong $[0,2^N-1]$.

-   Với cách biểu diễn có dấu, có hai quy tắc biểu diễn: **mã bù một** (ones' complement) và **mã bù hai** (two's complement).

    Với số nguyên không âm, quy tắc biểu diễn giống trường hợp không dấu. Với số nguyên âm, lấy chuỗi bit tương ứng với số đối của nó rồi **đảo từng bit** (biến `0` thành `1`, biến `1` thành `0`) thì thu được mã bù một. Nếu xem mã bù một như một số không dấu, cộng thêm một, rồi chuyển ngược lại thành chuỗi bit theo quy tắc không dấu và bỏ phần vượt quá độ dài ban đầu, thu được mã bù hai.

    Theo cách biểu diễn bằng mã bù một, chuỗi bit độ dài $N$ có thể biểu diễn các số nguyên trong $[-2^{N-1}+1,2^{N-1}-1]$.

    Theo cách biểu diễn bằng mã bù hai, chuỗi bit độ dài $N$ có thể biểu diễn các số nguyên trong $[-2^{N-1},2^{N-1}-1]$.

Ví dụ với chuỗi bit $3$ bit:

| Chuỗi bit | Số nguyên không dấu | Số nguyên có dấu (mã bù một) | Số nguyên có dấu (mã bù hai) |
| ----- | ----- | --------- | --------- |
| `000` | $0$   | $0$       | $0$       |
| `001` | $1$   | $1$       | $1$       |
| `010` | $2$   | $2$       | $2$       |
| `011` | $3$   | $3$       | $3$       |
| `100` | $4$   | $-3$      | $-4$      |
| `101` | $5$   | $-2$      | $-3$      |
| `110` | $6$   | $-1$      | $-2$      |
| `111` | $7$   | $-0$      | $-1$      |

Vấn đề lớn nhất của mã bù một là xuất hiện $-0$, một "số âm" thực tế không tồn tại; vì vậy thông thường chỉ dùng mã bù hai. Khi biểu diễn số nguyên có dấu, dấu âm hay dương chỉ do bit cao nhất của chuỗi bit quyết định, nên bit này được gọi là **bit dấu**.

Chuyển chuỗi bit về số nguyên cũng rất đơn giản: với số không âm thì không cần thao tác đặc biệt; với mã bù một, đảo bit sẽ thu được số đối tương ứng; với mã bù hai, đảo bit rồi cộng một sẽ thu được số đối tương ứng.

<span id="phép-toán-bit"></span>

## Phép toán bit

Phép toán bit là phép toán áp dụng một [hàm Boolean](./boolean-algebra.md#hàm-boolean) nào đó trên từng bit của chuỗi bit. Một cách hình thức, với hàm Boolean $f:\mathbf{B}^k\to \mathbf{B}$, phép toán bit là hàm có dạng

$$
\begin{aligned}
    F:\left(\mathbf{B}^m\right)^k&\to \mathbf{B}^m\\
    ((p_{1,1},\dots,p_{m,1}),\dots,(p_{1,k},\dots,p_{m,k}))&\mapsto (f(p_{1,1},\dots,p_{1,k}),\dots,f(p_{m,1},\dots,p_{m,k}))
\end{aligned}
$$

trong đó $m$ là độ dài của chuỗi bit. Tương tự, thường chỉ xét các phép toán bit một ngôi và hai ngôi. Nếu không nói rõ thêm, các phép toán bit ở phần sau chỉ giới hạn trong hai trường hợp này.

Thông thường, **đảo bit**, **AND bit**, **OR bit**, **XOR bit** được xem là các phép toán bit cơ bản; các phép toán bit khác đều có thể được tạo bằng cách kết hợp những phép toán này.

| Phép toán bit | Ký hiệu toán học                | Hàm Boolean tương ứng | Toán tử C++       | Giải thích |
| ---- | ----------------------------- | -------- | --------------- | ----------------------- |
| Đảo bit | $\operatorname{NOT}$          | $\lnot$  | `~`             | $0$ thành $1$, $1$ thành $0$ |
| AND bit | $\operatorname{AND}$          | $\land$  | `&`             | Chỉ bằng $1$ khi cả hai bit tương ứng đều là $1$ |
| OR bit  | $\operatorname{OR}$           | $\lor$   | <code>\|</code> | Bằng $1$ nếu ít nhất một trong hai bit tương ứng là $1$ |
| XOR bit | $\oplus$, $\operatorname{XOR}$ | $\oplus$ | `^`             | Chỉ bằng $1$ khi hai bit tương ứng khác nhau |

???+ warning "Cảnh báo"
    Cần phân biệt phép toán bit với hàm Boolean.

Ví dụ:

-   $\operatorname{NOT} 01010111=10101000$,
-   $01010011 \operatorname{AND} 00110010=00010010$,
-   $01010011 \operatorname{OR}  00110010=01110011$,
-   $01010011 \operatorname{XOR} 00110010=01100001$.

Vì trong bốn phép toán bit trên, phép tính trên mỗi bit độc lập với nhau, bốn phép toán này có thể kế thừa trực tiếp các tính chất của hàm Boolean tương ứng.

Để tiện lợi, khi đã biết độ dài chuỗi bit, cũng có thể thực hiện phép toán bit trực tiếp trên số nguyên, ví dụ:

$$
\begin{aligned}
    \operatorname{NOT} 5&=-6,\\
    \operatorname{NOT} (-5)&=4,\\
    5 \operatorname{AND} 6 &=4,\\
    5 \operatorname{OR} 6 &=7,\\
    5 \operatorname{XOR} 6 &=3.
\end{aligned}
$$

Giả sử $x,y\geq 0$, cũng có thể biểu diễn các phép toán bit bằng tổng:

$$
\begin{aligned}
    \operatorname{NOT} x&=\sum_{n=0}^{\lfloor\log_{2}x\rfloor}2^n\left(\left(\left\lfloor\frac{x}{2^n}\right\rfloor\bmod 2+1\right)\bmod 2\right)\\
    &=\sum_{n=0}^{\lfloor\log_{2}x\rfloor}\left(2^{\left\lfloor\log_{2}x\right\rfloor +1}-1-x\right)\\
    x\operatorname{AND} y&=\sum_{n=0}^{\lfloor\log_{2}\max\{x,y\}\rfloor}2^n\left(\left\lfloor\frac{x}{2^n}\right\rfloor\bmod 2\right)\left(\left\lfloor{\frac{y}{2^n}}\right\rfloor\bmod 2\right)\\
    x\operatorname{OR} y&=\sum_{n=0}^{\lfloor\log_{2}\max\{x,y\}\rfloor}2^n\left(\left(\left\lfloor\frac{x}{2^n}\right\rfloor\bmod 2\right)+\left(\left\lfloor{\frac{y}{2^n}}\right\rfloor\bmod 2\right)-\left(\left\lfloor\frac{x}{2^n}\right\rfloor\bmod 2\right)\left(\left\lfloor{\frac{y}{2^n}}\right\rfloor\bmod 2\right)\right)\\
    x\operatorname{XOR} y&=\sum_{n=0}^{\lfloor\log_{2}\max\{x,y\}\rfloor}2^n\left(\left(\left(\left\lfloor\frac{x}{2^n}\right\rfloor\bmod 2\right)+\left(\left\lfloor{\frac{y}{2^n}}\right\rfloor\bmod 2\right)\right)\bmod 2\right)\\
    &=\sum_{n=0}^{\lfloor\log_{2}\max\{x,y\}\rfloor}2^n\left(\left(\left\lfloor\frac{x}{2^n}\right\rfloor +\left\lfloor\frac{y}{2^n}\right\rfloor\right)\bmod 2\right)
\end{aligned}
$$

Khi không gây nhầm lẫn, từ phần sau sẽ lược bỏ từ "bit".

<span id="dịch-bit"></span>

## Dịch bit

Xem thêm: [toán tử bit trong C++](../lang/op.md#toán-tử-bit).

Dịch bit là một lớp phép toán hai ngôi "di chuyển chuỗi bit sang trái hoặc sang phải theo từng bit"; tham số thứ nhất là chuỗi bit, tham số thứ hai thường là một số nguyên không âm. Dịch sang trái được gọi là **dịch trái**, dịch sang phải được gọi là **dịch phải**. Dựa trên cách lấp các vị trí trống sau khi dịch, thao tác dịch bit có thể chia thành **dịch số học**, **dịch logic**, và **dịch vòng**. Trong đó:

-   Dịch logic lấp các vị trí trống bằng 0.
-   Dịch phải số học lấp các vị trí trống bằng bit dấu; dịch trái số học giống dịch trái logic.
-   Dịch vòng lấp các vị trí trống bằng các bit bị tràn ra ngoài.

Ví dụ với chuỗi bit $8$ bit `10 01 01 10`:

| Thao tác | Kết quả |
| ---------- | ------------- |
| Dịch trái số học $2$ bit | `01 01 10 00` |
| Dịch phải số học $2$ bit | `11 10 01 01` |
| Dịch trái logic $2$ bit | `01 01 10 00` |
| Dịch phải logic $2$ bit | `00 10 01 01` |
| Dịch vòng trái $2$ bit | `01 01 10 10` |
| Dịch vòng phải $2$ bit | `10 10 01 01` |

Trong C++, dùng `a << b` để biểu diễn dịch trái và `a >> b` để biểu diễn dịch phải; quy tắc dịch cụ thể được áp dụng ra sao thì xem [toán tử bit trong C++](../lang/op.md#toán-tử-bit).

Có thể dùng đoạn mã sau để thực hiện dịch vòng:

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/math/code/bit/bit_1.cpp:core"
    ```

<span id="ứng-dụng-của-thao-tác-bit"></span>

## Ứng dụng của thao tác bit

Thao tác bit thường có ba công dụng:

1.  Thực hiện một số phép tính hiệu quả hơn, thay cho các cách kém hiệu quả hơn. Xem [tối ưu biên dịch #giảm độ mạnh phép toán](../lang/optimizations.md#giảm-độ-mạnh-phép-toán-strength-reduction).
2.  [Biểu diễn tập hợp](./binary-set.md) (thường dùng trong [DP nén trạng thái](../dp/state.md)).
3.  Bản thân bài toán yêu cầu thực hiện thao tác bit.

Cần lưu ý rằng việc dùng thao tác bit để thay thế các phép tính khác trong nhiều trường hợp không tối ưu được bao nhiêu, mà còn làm mã nguồn phức tạp hơn; cần cân nhắc khi sử dụng.

<span id="các-ứng-dụng-liên-quan-đến-lũy-thừa-của-2"></span>

### Các ứng dụng liên quan đến lũy thừa của 2

Vì thao tác bit làm việc trên biểu diễn nhị phân, có thể suy ra nhiều ứng dụng liên quan đến lũy thừa nguyên của 2.

Nhân (chia) một số với lũy thừa nguyên không âm của 2:

=== "C++"
    ```cpp
    --8<-- "docs/math/code/bit/bit_2.cpp:mul"
    ```

=== "Python"
    ```python
    --8<-- "docs/math/code/bit/bit_2.py:mul"
    ```

??? warning "Cảnh báo"
    Phép chia thường viết được làm tròn về $0$, còn dịch phải trong trường hợp này được làm tròn xuống (cần lưu ý sự khác nhau này). Nghĩa là khi số lớn hơn hoặc bằng $0$ thì hai cách tương đương, còn khi số nhỏ hơn $0$ thì sẽ khác nhau, ví dụ: `-1 / 2` có giá trị là $0$, còn `-1 >> 1` có giá trị là $-1$.

<span id="lấy-giá-trị-tuyệt-đối"></span>

### Lấy giá trị tuyệt đối

Trên một số máy, cách này hiệu quả hơn `n > 0 ? n : -n`.

=== "C++"
    ```cpp
    --8<-- "docs/math/code/bit/bit_2.cpp:abs"
    ```

=== "Python"
    ```python
    --8<-- "docs/math/code/bit/bit_2.py:abs"
    ```

<span id="lấy-giá-trị-lớn-nhất-nhỏ-nhất-của-hai-số"></span>

### Lấy giá trị lớn nhất/nhỏ nhất của hai số

Trên một số máy, cách này hiệu quả hơn `a > b ? a : b`.

=== "C++"
    ```cpp
    --8<-- "docs/math/code/bit/bit_2.cpp:minmax"
    ```

=== "Python"
    ```python
    --8<-- "docs/math/code/bit/bit_2.py:minmax"
    ```

<span id="kiểm-tra-hai-số-khác-không-có-cùng-dấu-hay-không"></span>

### Kiểm tra hai số khác không có cùng dấu hay không

=== "C++"
    ```cpp
    --8<-- "docs/math/code/bit/bit_2.cpp:sgn"
    ```

=== "Python"
    ```python
    --8<-- "docs/math/code/bit/bit_2.py:sgn"
    ```

<span id="hoán-đổi-hai-số"></span>

### Hoán đổi hai số

???+ note "Phương pháp này có giới hạn"
    Cách này chỉ có thể dùng để hoán đổi hai số nguyên, phạm vi sử dụng khá hạn chế.

    Với thao tác hoán đổi trong trường hợp tổng quát, nên gọi trực tiếp hàm `std::swap` trong thư viện `algorithm`.

```cpp
--8<-- "docs/math/code/bit/bit_2.cpp:swap"
```

<span id="thao-tác-trên-các-bit-nhị-phân-của-một-số"></span>

### Thao tác trên các bit nhị phân của một số

Lấy một bit trong biểu diễn nhị phân của một số:

=== "C++"
    ```cpp
    --8<-- "docs/math/code/bit/bit_2.cpp:get_bit"
    ```

=== "Python"
    ```python
    --8<-- "docs/math/code/bit/bit_2.py:get_bit"
    ```

Đặt một bit trong biểu diễn nhị phân của một số thành $0$:

=== "C++"
    ```cpp
    --8<-- "docs/math/code/bit/bit_2.cpp:unset_bit"
    ```

=== "Python"
    ```python
    --8<-- "docs/math/code/bit/bit_2.py:unset_bit"
    ```

Đặt một bit trong biểu diễn nhị phân của một số thành $1$:

=== "C++"
    ```cpp
    --8<-- "docs/math/code/bit/bit_2.cpp:set_bit"
    ```

=== "Python"
    ```python
    --8<-- "docs/math/code/bit/bit_2.py:set_bit"
    ```

Đảo một bit trong biểu diễn nhị phân của một số:

=== "C++"
    ```cpp
    --8<-- "docs/math/code/bit/bit_2.cpp:flap_bit"
    ```

=== "Python"
    ```python
    --8<-- "docs/math/code/bit/bit_2.py:flap_bit"
    ```

Những thao tác này tương đương với việc xem một biến số nguyên $32$ bit như một mảng Boolean có độ dài $32$.

<span id="trọng-số-hamming"></span>

## Trọng số Hamming

Trọng số Hamming là số ký hiệu trong một chuỗi ký hiệu khác với ký hiệu không (zero-symbol, được định nghĩa trên bộ ký tự đang dùng). Với một số nhị phân, trọng số Hamming của nó chính là số lượng bit $1$ (tức `popcount`).

Có thể tính trọng số Hamming của một số bằng vòng lặp: liên tục loại bỏ bit cuối cùng trong biểu diễn nhị phân của số đó (tức dịch phải $1$ bit), duy trì một biến đáp án, và trong quá trình đó cập nhật đáp án theo việc bit thấp nhất có phải là $1$ hay không.

Mã nguồn như sau:

```cpp
--8<-- "docs/math/code/bit/bit_2.cpp:popcnt1"
```

Có thể tính trọng số Hamming của một số bằng thao tác `lowbit`: liên tục trừ `lowbit`[^note1] của số đó cho đến khi nó trở thành $0$.

Mã nguồn như sau:

```cpp
--8<-- "docs/math/code/bit/bit_2.cpp:popcnt2"
```

<span id="xây-dựng-hoán-vị-có-trọng-số-hamming-tăng-dần"></span>

### Xây dựng hoán vị có trọng số Hamming tăng dần

Trong [DP nén trạng thái](../dp/state.md), việc liệt kê theo thứ tự `popcount` tăng dần đôi khi có thể tránh liệt kê lặp trạng thái. Đây là một ứng dụng quan trọng của việc xây dựng hoán vị có trọng số Hamming tăng dần.

Sau đây là cách xây dựng một hoán vị có trọng số Hamming tăng dần trong thời gian $O(n)$.

Số nguyên nhỏ nhất có trọng số Hamming bằng $n$ là $2^n-1$. Nếu có thể xây dựng trong thời gian hằng số phần tử kế tiếp có cùng trọng số Hamming với một số nguyên, thì bằng cách liệt kê trọng số Hamming, bắt đầu từ $2^n-1$ và liên tục tìm số tiếp theo, có thể xây dựng trong thời gian $O(n)$ một hoán vị của $0\sim n$ thỏa mãn yêu cầu.

Ý tưởng tìm phần tử kế tiếp có cùng trọng số Hamming với một số $x$ như sau; lấy $(10110)_2$ làm ví dụ:

-   Dịch bit $1$ ngoài cùng bên phải của $(10110)_2$ sang trái; nếu không dịch được thì dịch bit $1$ bên trái nó, và cứ tiếp tục như vậy, thu được $(11010)_2$.

-   Đưa tất cả các bit $1$ từ vị trí ban đầu của bit $1$ vừa được dịch cuối cùng trong $(11010)_2$ cho đến bit thấp nhất về phía ngoài cùng bên phải. Bit $1$ vừa được dịch cuối cùng ban đầu nằm ở vị trí thứ ba, nên ba bit cuối $010$ cần biến thành $001$, thu được $(11001)_2$.

Quá trình này có thể được tối ưu bằng thao tác bit:

```cpp
--8<-- "docs/math/code/bit/bit_3.cpp:hamming1"
```

-   Ở bước đầu tiên, cộng số $x$ với `lowbit` của nó. Trên biểu diễn nhị phân, thao tác này tương đương với việc thay đoạn bit $1$ liên tiếp ngoài cùng bên phải của $x$ bằng một bit $1$ ở bên trái đoạn này. Theo số nhị phân vừa nêu $(10110)_2$, sau khi cộng với `lowbit` của nó thu được $(11000)_2$. Đây thực chất là nửa đầu của đáp án.
-   Tiếp theo cần bổ sung các bit $1$ ở phần sau của đáp án. `lowbit` của $t$ là vị trí sau khi bit $1$ bên trái nhất trong đoạn bit $1$ liên tiếp ngoài cùng bên phải của $x$ được dịch, còn `lowbit` của $x$ là vị trí bit $1$ bên phải nhất trong đoạn đó. Vẫn với ví dụ $(10110)_2$, có $t = (11000)_2$, $\operatorname{lowbit}(t) = (01000)_2$, $\operatorname{lowbit}(x)=(00010)_2$.
-   Phép chia tiếp theo là phần khó hiểu nhất trong thủ thuật bit này, nhưng cũng là phần then chốt. Giả sử bit $1$ cao nhất trong đoạn bit $1$ liên tiếp ngoài cùng bên phải của **số ban đầu** nằm ở bit thứ $r$ (đánh số bit từ $0$), còn bit $1$ thấp nhất nằm ở bit thứ $l$. Khi đó `lowbit` của $t$ bằng `1 << (r+1)`, `lowbit` của $x$ bằng `1 << l`, và `(((t&-t)/(x&-x))>>1)` cho kết quả `(1<<(r+1))/(1<<l)/2 = (1<<r)/(1<<l) = 1<<(r-l)`, tức trên biểu diễn nhị phân là một bit $1$ theo sau bởi $r-l$ bit $0$; số bit $0$ này đúng bằng số lượng bit $1$ liên tiếp trừ đi $1$. Với ví dụ ở trên, $\frac{\operatorname{lowbit(t)/2}}{\operatorname{lowbit(x)}} = \frac{(00100)_2}{(00010)_2} = (00010)_2$. Trừ số này đi $1$ sẽ thu được các bit thấp cần bổ sung, rồi OR với số ban đầu là được đáp án.

Do đó, mã nguồn đầy đủ để liệt kê hoán vị của $0\sim n$ theo thứ tự trọng số Hamming tăng dần là:

```cpp
--8<-- "docs/math/code/bit/bit_3.cpp:hamming2_begin"
--8<-- "docs/math/code/bit/bit_3.cpp:hamming2_end"
```

Trong đó cần lưu ý xử lý riêng $0$, vì $0$ không có phần tử kế tiếp có cùng trọng số Hamming.

<span id="các-lớp-và-hàm-liên-quan-trong-c"></span>

## Các lớp và hàm liên quan trong C++

<span id="hàm-nội-tại-của-gcc"></span>

### Hàm nội tại của GCC

GCC còn có một số hàm nội tại dùng cho thao tác bit:

-   `int __builtin_ffs(int x)`: trả về vị trí của bit $1$ cuối cùng ở phần đuôi biểu diễn nhị phân của $x$; vị trí được đánh số từ $1$ (bit thấp nhất có chỉ số $1$). Khi $x$ bằng $0$, hàm trả về $0$.
-   `int __builtin_clz(unsigned int x)`: trả về số lượng bit $0$ ở đầu biểu diễn nhị phân của $x$. Khi $x$ bằng $0$, kết quả không được định nghĩa.
-   `int __builtin_ctz(unsigned int x)`: trả về số lượng bit $0$ liên tiếp ở cuối biểu diễn nhị phân của $x$. Khi $x$ bằng $0$, kết quả không được định nghĩa.
-   `int __builtin_clrsb(int x)`: nếu bit dấu của $x$ là $0$, trả về số lượng bit $0$ ở đầu biểu diễn nhị phân của $x$ trừ một; ngược lại, trả về số lượng bit $1$ ở đầu biểu diễn nhị phân của $x$ trừ một.
-   `int __builtin_popcount(unsigned int x)`: trả về số lượng bit $1$ trong biểu diễn nhị phân của $x$.
-   `int __builtin_parity(unsigned int x)`: kiểm tra tính chẵn lẻ của số lượng bit $1$ trong biểu diễn nhị phân của $x$.

Tất cả các hàm này đều có thể thêm `l` hoặc `ll` vào cuối tên hàm (ví dụ `__builtin_popcountll`) để đổi kiểu tham số thành (`unsigned`)`long` hoặc (`unsigned`)`long long` (giá trị trả về vẫn có kiểu `int`).
Chẳng hạn, đôi khi cần tính logarit cơ số hai của một số; nếu không xét riêng trường hợp `0`, giá trị đó tương đương với số bit trong biểu diễn nhị phân của số này `-1`. Số bit trong biểu diễn nhị phân của một số nguyên `n` có `N` bit có thể được biểu diễn bằng `N - __builtin_clz(n)`, nên `N - 1 - __builtin_clz(n)` có thể tính được logarit cơ số hai của `n`.

Vì các hàm này là hàm nội tại và đã được trình biên dịch tối ưu mạnh, tốc độ chạy của chúng rất nhanh (một số hàm thậm chí chỉ cần một lệnh máy).

<span id="nhiều-bit-hơn"></span>

### Nhiều bit hơn

Nếu cần thao tác trên chuỗi bit rất dài, có thể dùng [`std::bitset`](../lang/csl/bitset.md).

<span id="bài-tập-gợi-ý"></span>

## Bài tập gợi ý

-   [Luogu P1225 Trò chơi cờ đen trắng](https://www.luogu.com.cn/problem/P1225)

<span id="tài-liệu-tham-khảo-và-ghi-chú"></span>

## Tài liệu tham khảo và ghi chú

1.  [Bit hacks](https://graphics.stanford.edu/~seander/bithacks.html)
2.  [Bit Operation Builtins (Using the GNU Compiler Collection (GCC))](https://gcc.gnu.org/onlinedocs/gcc/Bit-Operation-Builtins.html)
3.  [Bitwise operation - Wikipedia](https://en.wikipedia.org/wiki/Bitwise_operation)

[^note1]: `lowbit` của một số là bit $1$ đầu tiên tính từ thấp lên cao trong biểu diễn nhị phân của số đó, kèm các bit $0$ phía sau; ví dụ `lowbit` của $(1010)_2$ là $(0010)_2$. Xem thêm [Fenwick tree](../ds/fenwick.md).
