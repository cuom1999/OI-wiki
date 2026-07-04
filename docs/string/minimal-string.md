<span id="&#23450;&#20041;"></span>
## Định nghĩa

Biểu diễn nhỏ nhất là phương pháp dùng để giải bài toán biểu diễn nhỏ nhất của xâu.

<span id="&#23383;&#31526;&#20018;&#30340;&#26368;&#23567;&#34920;&#31034;"></span>
## Biểu diễn nhỏ nhất của xâu

<span id="&#24490;&#29615;&#21516;&#26500;"></span>
### Đẳng cấu vòng

Nếu có thể chọn một vị trí $i$ trong xâu $S$ sao cho

$$
S[i\cdots n]+S[1\cdots i-1]=T
$$

thì gọi $S$ và $T$ là đẳng cấu vòng.

<span id="&#26368;&#23567;&#34920;&#31034;"></span>
### Biểu diễn nhỏ nhất

Biểu diễn nhỏ nhất của xâu $S$ là xâu có thứ tự từ điển nhỏ nhất trong tất cả các xâu đẳng cấu vòng với $S$.

<span id="simple-&#30340;&#26292;&#21147;"></span>
## Cách vét cạn đơn giản

Mỗi lần ta so sánh hai xâu đẳng cấu vòng bắt đầu tại $i$ và $j$, đồng thời dùng $k$ để ghi vị trí đang so sánh. Mỗi khi gặp hai ký tự khác nhau, ta bỏ qua điểm bắt đầu cho xâu lớn hơn; điểm còn lại cuối cùng chính là nghiệm tối ưu.

<span id="&#23454;&#29616;"></span>
### Cài đặt

=== "C++"
    ```cpp
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
      if (sec[(i + k) % n] == sec[(j + k) % n]) {
        ++k;
      } else {
        if (sec[(i + k) % n] > sec[(j + k) % n])
          ++i;
        else
          ++j;
        k = 0;
        if (i == j) i++;
      }
    }
    i = min(i, j);
    ```

=== "Python"
    ```python
    k, i, j = 0, 0, 1
    while k < n and i < n and j < n:
        if sec[(i + k) % n] == sec[(j + k) % n]:
            k += 1
        else:
            if sec[(i + k) % n] > sec[(j + k) % n]:
                i += 1
            else:
                j += 1
            k = 0
            if i == j:
                i += 1
    i = min(i, j)
    ```

<span id="&#35299;&#37322;"></span>
### Giải thích

Cách cài đặt này chạy tốt trên dữ liệu ngẫu nhiên, nhưng có thể bị chặn bằng dữ liệu đặc biệt.

Ví dụ, với $\texttt{aaa}\cdots\texttt{aab}$, không khó thấy độ phức tạp của thuật toán suy biến thành $O(n^2)$.

Ta nhận thấy khi trong xâu có nhiều đoạn con lặp liên tiếp, hiệu suất của thuật toán giảm xuống; vì vậy cần tối ưu quá trình này.

<span id="&#26368;&#23567;&#34920;&#31034;&#27861;"></span>
## Thuật toán biểu diễn nhỏ nhất

<span id="&#31639;&#27861;&#26680;&#24515;"></span>
### Ý tưởng cốt lõi

Xét một cặp xâu $A,B$ có vị trí bắt đầu trong xâu gốc $S$ lần lượt là $i,j$, và $k$ ký tự đầu của chúng đều giống nhau, tức

$$
S[i \cdots i+k-1]=S[j \cdots j+k-1].
$$

Trước hết xét trường hợp $S[i+k]>S[j+k]$. Khi đó mọi xâu có vị trí bắt đầu $l$ thỏa $i\le l\le i+k$ đều không thể là đáp án, vì với mọi xâu $S_{i+p}$ (xâu bắt đầu tại $i+p$, $p \in [0, k]$), luôn tồn tại xâu $S_{j+p}$ tốt hơn nó.

Vì vậy khi so sánh, ta có thể bỏ qua các chỉ số $l\in [i,i+k]$ và trực tiếp so sánh tiếp từ $S_{i+k+1}$.

Như vậy ta đã tối ưu được cách vét cạn ở trên.

<span id="&#26102;&#38388;&#22797;&#26434;&#24230;"></span>
### Độ phức tạp thời gian

$O(n)$

<span id="&#36807;&#31243;"></span>
### Quy trình

1.  Khởi tạo con trỏ $i=0$, $j=1$; khởi tạo độ dài khớp $k=0$.
2.  So sánh ký tự thứ $k$ và nhảy con trỏ tương ứng theo kết quả so sánh. Nếu sau khi nhảy hai con trỏ trùng nhau, tăng tùy ý một con trỏ để bảo đảm hai xâu đang so sánh khác nhau.
3.  Lặp lại quá trình trên cho tới khi so sánh kết thúc.
4.  Đáp án là giá trị nhỏ hơn trong $i,j$.

<span id="&#23454;&#29616;"></span>
### Cài đặt

=== "C++"
    ```cpp
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
      if (sec[(i + k) % n] == sec[(j + k) % n]) {
        k++;
      } else {
        sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
        if (i == j) i++;
        k = 0;
      }
    }
    i = min(i, j);
    ```

=== "Python"
    ```python
    k, i, j = 0, 0, 1
    while k < n and i < n and j < n:
        if sec[(i + k) % n] == sec[(j + k) % n]:
            k += 1
        else:
            if sec[(i + k) % n] > sec[(j + k) % n]:
                i = i + k + 1
            else:
                j = j + k + 1
            if i == j:
                i += 1
            k = 0
    i = min(i, j)
    ```
