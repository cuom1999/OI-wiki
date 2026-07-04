author: liujiaxi123456, Marcythm, hsfzLZH1, Ir1d, greyqz, Anguei, billchenchina, Chrogeek, ChungZH

## Dẫn nhập

Kiến thức cần có: [hàng đợi đơn điệu](../../ds/monotonic-queue.md), [ngăn xếp đơn điệu](../../ds/monotonic-stack.md).

Hàng đợi đơn điệu chủ yếu dùng để duy trì giá trị lớn nhất/nhỏ nhất trên đoạn khi hai con trỏ biên không giảm. Ngăn xếp đơn điệu chủ yếu dùng để duy trì phần tử đầu tiên phía trước/sau lớn hơn/nhỏ hơn giá trị hiện tại.

???+ note "Chú ý"
    -   Khi cần lấy giá trị nhỏ nhất, hãy duy trì hàng đợi/ngăn xếp **tăng dần/không giảm**; chiều ngược lại tương tự.
    -   Khi duy trì tăng/giảm nghiêm ngặt, dùng so sánh **nhỏ hơn hoặc bằng/lớn hơn hoặc bằng**; khi duy trì không giảm/không tăng, dùng **nhỏ hơn/lớn hơn**.

## Các bước tối ưu bằng hàng đợi đơn điệu

-   Thêm các phần tử cần thiết: liên tục thêm phần tử vào hàng đợi đơn điệu cho tới khi phần tử hiện tại đạt biên phải của đoạn cần xét, bảo đảm mọi phần tử cần dùng đều nằm trong hàng đợi.
-   Loại bỏ đầu hàng đợi vượt biên: hàng đợi đơn điệu vốn duy trì cực trị của mọi phần tử đã chèn, nhưng ta thường cần cực trị trên một đoạn. Vì vậy, cần loại bỏ các phần tử nằm ngoài biên trái để bảo đảm mọi phần tử trong hàng đợi thuộc đoạn đang xét.
-   Lấy cực trị: trực tiếp lấy phần tử ở đầu hàng đợi làm đáp án.

## Các bước tối ưu bằng ngăn xếp đơn điệu

-   Loại bỏ đỉnh ngăn xếp không hợp lệ: so sánh phần tử hiện tại với đỉnh ngăn xếp và pop các đỉnh không thỏa tính chất đơn điệu. Ví dụ với ngăn xếp tăng nghiêm ngặt (đỉnh lớn nhất, dùng để duy trì giá trị nhỏ nhất), pop mọi phần tử trong ngăn xếp lớn hơn hoặc bằng phần tử hiện tại.
-   Thêm phần tử hiện tại: chỉ cần push phần tử hiện tại vào ngăn xếp.

## Tối ưu ba lô nhiều vật phẩm bằng hàng đợi đơn điệu

???+ note "Mô tả bài toán"
    Có $n$ loại vật phẩm; mỗi loại có trọng lượng $w_i$, giá trị $v_i$, số lượng $k_i$. Có một ba lô với giới hạn tải trọng $W$. Hãy chọn các vật phẩm sao cho không vượt quá giới hạn trọng lượng và tổng giá trị lớn nhất. Tìm giá trị lớn nhất đó.

Nếu chưa biết DP ba lô, hãy đọc trước [DP ba lô](../knapsack.md). Đặt $f_{i,j}$ là giá trị lớn nhất khi xét $i$ loại vật phẩm đầu tiên và ba lô có tải trọng $j$. Công thức chuyển đơn giản là:

$$
f_{i,j}=\max_{k=0}^{k_i}(f_{i-1,j-k\times w_i}+v_i\times k)
$$

Độ phức tạp thời gian là $O(W\sum k_i)$.

Xét tối ưu quá trình chuyển của $f_i$. Để tiện trình bày, đặt $g_{x,y}=f_{i,x\times w_i+y}$, $g'_{x,y}=f_{i-1,x\times w_i+y}$, trong đó $0\le y<w_i$. Khi đó công thức chuyển có thể viết là:

$$
g_{x,y}=\max_{k=0}^{k_i}(g'_{x-k,y}+v_i\times k)
$$

Đặt $G_{x,y}=g'_{x,y}-v_i\times x$. Khi đó:

$$
g_{x,y}=\max_{k=0}^{k_i}(G_{x-k,y})+v_i\times x
$$

Như vậy bài toán được chuyển thành dạng tối ưu kinh điển bằng hàng đợi đơn điệu. $G_{x,y}$ có thể tính trong $O(1)$, nên với $y$ cố định, ta có thể tính mọi $g_{x,y}$ trong $O\left(\left\lfloor\dfrac{W}{w_i}\right\rfloor\right)$. Do đó độ phức tạp để tính tất cả $g_{x,y}$ là $O\left(\left\lfloor\dfrac{W}{w_i}\right\rfloor\right)\times O(w_i)=O(W)$. Tổng độ phức tạp chuyển trạng thái giảm xuống $O(nW)$.

Khi cài đặt, cần duyệt $y$ trước để khi duyệt $x$ có thể dùng hàng đợi đơn điệu tối ưu. Hàng đợi đơn điệu lưu $x-k$, không lưu $k$, nên khi dùng cần lấy $G_{x-k,y}$ tương ứng bằng `f[last][q.front() * w[i] + y] - q.front() * v[i]`. Dễ thấy $x-k\in[x-k_i,x]$, vì vậy khi duyệt $x$, cần xóa khỏi hàng đợi các phần tử không nằm trong khoảng này.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/opt/monotonic-queue-stack/monotonic-queue-stack_2.cpp"
    ```

## Bài tập

???+ note "Bài ví dụ [CF372C Watching Fireworks is Fun](http://codeforces.com/problemset/problem/372/C)"
    Tóm tắt đề bài: Trong thị trấn có $n$ vị trí và có $m$ pháo hoa được bắn. Pháo hoa thứ $i$ được bắn vào thời điểm $t_i$, tại vị trí $a_i$. Nếu khi pháo hoa được bắn, bạn đang ở vị trí $x$, bạn nhận được $b_i-|a_i-x|$ điểm vui vẻ.
    
    Ban đầu bạn có thể ở bất kỳ vị trí nào. Mỗi đơn vị thời gian bạn có thể di chuyển không quá $d$ đơn vị khoảng cách. Hãy tối đa hóa tổng điểm vui vẻ nhận được.

Đặt $f_{i,j}$ là điểm vui vẻ lớn nhất có thể đạt được khi pháo hoa thứ $i$ được bắn và bạn đang ở vị trí $j$.

Phương trình chuyển trạng thái là $f_{i,j}=\max\{f_{i-1,k}+b_i-|a_i-j|\}$, trong đó $j-(t_i-t_{i-1})\times d\le k\le j+(t_i-t_{i-1})\times d$.

Thử biến đổi:

Vì trong $\max$ có hằng số xác định $b_i$, ta có thể đưa nó ra ngoài.

$f_{i,j}=\max\{f_{i-1,k}+b_i-|a_i-j|\}=\max\{f_{i-1,k}-|a_i-j|\}+b_i$

Nếu đã cố định $i$ và $j$, thì $|a_i-j|$ cũng xác định, nên cũng có thể đưa phần này ra ngoài.

Cuối cùng, công thức trở thành:

$$
f_{i,j}=\max\{f_{i-1,k}-|a_i-j|\}+b_i=\max\{f_{i-1,k}\}-|a_i-j|+b_i
$$

Tiếp theo xét tối ưu bằng hàng đợi đơn điệu. Vì $\max$ trong công thức cuối chỉ liên quan tới giá trị lớn nhất của một đoạn liên tiếp trong trạng thái trước, khi tính trạng thái cho một $i$ mới, ta chỉ cần xây dựng và duy trì hàng đợi đơn điệu từ $f_{i-1}$, để tính $\max\{f_{i-1,k}\}$ trong thời gian khấu hao $O(1)$, rồi dùng công thức tính $f_{i,j}$.

Tổng độ phức tạp thời gian là $O(nm)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/dp/code/opt/monotonic-queue-stack/monotonic-queue-stack_1.cpp"
    ```

-   [「Luogu P1886」Cửa sổ trượt](https://loj.ac/problem/10175)
-   [「NOI2005」Điệu waltz lộng lẫy](https://www.luogu.com.cn/problem/P2254)
-   [「SCOI2010」Giao dịch cổ phiếu](https://loj.ac/problem/10183)
