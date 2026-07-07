author: Enter-tainer, Falicitas, HeRaNO, iamtwz, ImpleLee, Tiphereth-A, Xeonacid, Yanjun-Zhao

<span id="định-nghĩa"></span>
## Định nghĩa

Hệ tam phân cân bằng, còn gọi là hệ tam phân đối xứng, là một hệ cơ số tổng quát.

Trong hệ tam phân thông thường, các chữ số gồm `0`, `1`, `2`; còn trong hệ tam phân cân bằng, các chữ số gồm `-1`, `0`, `1`. Cơ số của nó vẫn là `3` (vì có ba giá trị có thể có). Do viết `-1` dưới dạng một chữ số không tiện, chữ cái `Z` được dùng để thay cho `-1`.

<span id="giải-thích"></span>
## Giải thích

Một vài ví dụ:

| Thập phân | Tam phân cân bằng | Thập phân | Tam phân cân bằng |
| --- | ----- | --- | ----- |
| `0` | `0`   | `5` | `1ZZ` |
| `1` | `1`   | `6` | `1Z0` |
| `2` | `1Z`  | `7` | `1Z1` |
| `3` | `10`  | `8` | `10Z` |
| `4` | `11`  | `9` | `100` |

Hệ ghi số này biểu diễn số âm rất đơn giản: chỉ cần đảo từng chữ số của số dương (`Z` thành `1`, `1` thành `Z`).

| Thập phân | Tam phân cân bằng |
| ---- | ----- |
| `-1` | `Z`   |
| `-2` | `Z1`  |
| `-3` | `Z0`  |
| `-4` | `ZZ`  |
| `-5` | `Z11` |

Chữ số cao nhất của số âm là `Z`, còn chữ số cao nhất của số dương là `1`.

<span id="quy-trình"></span>
## Quy trình

Khi chuyển đổi sang tam phân cân bằng, trước hết cần viết số đã cho `x` trong hệ tam phân chuẩn. Khi `x` được biểu diễn bằng tam phân chuẩn, mỗi chữ số của nó là `0`, `1` hoặc `2`. Bắt đầu từ chữ số thấp nhất, bỏ qua mọi `0` và `1`; nếu gặp `2`, đổi nó thành `Z` và cộng `1` vào chữ số kế tiếp. Nếu gặp chữ số `3`, đổi nó thành `0` và cộng `1` vào chữ số kế tiếp.

<span id="ví-dụ-1"></span>
### Ví dụ 1

Chuyển `64` sang tam phân cân bằng.

Trước hết viết lại số này dưới dạng tam phân chuẩn:

$$
\text 64_{10} = 02101_3
$$

Xử lý từ chữ số có ảnh hưởng nhỏ nhất lên toàn bộ số (chữ số thấp nhất):

-   bỏ qua `101` (vì `0` và `1` được phép trong tam phân cân bằng);
-   đổi `2` thành `Z`, cộng `1` vào chữ số bên trái nó, thu được `1Z101`;
-   bỏ qua `1`, thu được `1Z101`.

Kết quả cuối cùng là `1Z101`.

Chuyển ngược lại về thập phân:

$$
\texttt {1Z101}=81 \times 1 +27 \times (-1) + 9 \times 1 + 3 \times 0 + 1 \times 1 = 64_{10}
$$

<span id="ví-dụ-2"></span>
### Ví dụ 2

Chuyển `237` sang tam phân cân bằng.

Trước hết viết lại số này dưới dạng tam phân chuẩn:

$$
\text 237_{10} = 22210_3
$$

-   bỏ qua `0` và `1` (vì `0` và `1` được phép trong tam phân cân bằng);
-   đổi `2` thành `Z`, cộng `1` vào chữ số bên trái, thu được `23Z10`;
-   đổi `3` thành `0`, cộng `1` vào chữ số bên trái, thu được `30Z10`;
-   đổi `3` thành `0`, cộng `1` vào chữ số bên trái (mặc định là `0`), thu được `100Z10`;
-   bỏ qua `1`, thu được `100Z10`.

Kết quả cuối cùng là `100Z10`.

Chuyển ngược lại về thập phân:

$$
\texttt{100Z10} = 243 \cdot 1 + 81 \cdot 0 + 27 \cdot 0 + 9 \cdot (-1) + 3 \cdot 1 + 1 \cdot 0 = 237_{10}
$$

<span id="tính-chất"></span>
## Tính chất

Với một số tam phân cân bằng $X_3$, nhân từng chữ số $x_i$ với trọng số tương ứng $3^i$ sẽ nhận được duy nhất một số thập phân $Y_{10}$.

Vậy với một số thập phân $Y_{10}$, liệu có **duy nhất một số tam phân cân bằng tương ứng** hay không?

Câu trả lời là có. Tính chất này được gọi là tính duy nhất của hệ tam phân cân bằng.

???+ note "Chứng minh"
    Chứng minh bằng **phản chứng**:
    
    Giả sử một số thập phân $Y_{10}$ có hai **số tam phân cân bằng khác nhau** $A_3,B_3$ khi chuyển sang thập phân đều bằng $Y_{10}$; cần chứng minh $A_3 = B_3$. Xét các trường hợp:
    
    1.  Khi $Y_{10}=0$, suy ra $A_3 = B_3 = 0_3$, mâu thuẫn với giả thiết.
    2.  Khi $Y_{10}>0$:
    
        -   Đánh số các chữ số của $A_3$, $B_3$ từ thấp đến cao, gọi $a_i$ là chữ số thứ $i$ của $A_3$, $b_i$ là chữ số thứ $i$ của $B$. Trong $A_3,B_3$, tồn tại $i$ sao cho $a_i\neq b_i$. Các chữ số $i-1,i-2,\dots,0$ không liên quan đến chứng minh. Do đó dịch phải $A_3,B_3$ theo từng chữ số $i$ vị trí, thu được $A_3',B_3'$; bài toán ban đầu tương đương với việc chứng minh $A_3'=B_3'$.
        -   Với chữ số thứ $0$ của $A_3',B_3'$, có $a_0 \neq b_0$. Giả sử $b_0 > a_0$ (trường hợp $a_0>b_0$ tương tự), khi đó $b_0 - a_0 \in \{1,2\}$. Đóng góp của các chữ số $i=1,2,3,\dots$ trong $A_3'$ vào giá trị của $A_3'$ là $S_1 = a_1 \times 3^1 + a_2 \times 3^2+ \dots$, và đóng góp của các chữ số $i=1,2,3,\dots$ trong $B_3'$ vào giá trị của $B_3'$ là $S_2 = b_1 \times 3^1 + b_2 \times 3^2 + \dots$. Vì $A_3' = B_3'$, suy ra $S_1 - S_2 = b_0 - a_0$. Hai số $S_1,S_2$ đều có nhân tử chung $3$, trong khi $b_0 - a_0$ không chia hết cho $3$, mâu thuẫn. Do đó $A_3'\neq B_3'$.
    3.  Khi $Y_{10}<0$, chứng minh tương tự trường hợp $Y_{10}>0$.
    
    Vì vậy với mọi số thập phân $Y_{10}$, luôn có duy nhất một số tam phân cân bằng $X_3$ tương ứng.

<span id="bài-tập"></span>
## Bài tập

[Topcoder SRM 604 Lũy thừa của ba](https://archive.topcoder.com/ProblemStatement/pm/12917)

**Một phần nội dung trang này được dịch từ bài viết [Троичная сбалансированная система счисления](http://e-maxx.ru/algo/balanced_ternary) và bản dịch tiếng Anh [Balanced Ternary](https://cp-algorithms.com/algebra/balanced-ternary.html). Bản tiếng Nga dùng giấy phép Public Domain + Leave a Link; bản tiếng Anh dùng giấy phép CC-BY-SA 4.0.**
