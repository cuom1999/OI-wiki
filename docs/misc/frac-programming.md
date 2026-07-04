author: greyqz, Ir1d, hsfzLZH1, huaruoji, banglee13

Quy hoạch phân thức dùng để tìm cực trị của một biểu thức dạng phân thức. Phát biểu hình thức là: cho $a_i$ và $b_i$, cần tìm một bộ $w_i\in\{0,1\}$ để cực tiểu hóa hoặc cực đại hóa

$$
\displaystyle\frac{\sum\limits_{i=1}^na_i\times w_i}{\sum\limits_{i=1}^nb_i\times w_i}
$$

Nói một cách trực quan, loại bài này có dạng: mỗi vật có hai trọng số $a$ và $b$, chọn một số vật sao cho $\displaystyle\frac{\sum a}{\sum b}$ nhỏ nhất hoặc lớn nhất.

Thông thường, bài toán quy hoạch phân thức còn có một số ràng buộc đặc biệt, chẳng hạn "mẫu số ít nhất là $W$".

## Cách giải

### Tìm kiếm nhị phân

Phương pháp phổ biến cho quy hoạch phân thức là nhị phân đáp án. Giả sử đáp án đang xét là $\textit{mid}$, khi đó một bộ $\{w_i\}$ hợp lệ sẽ làm cho giá trị không nhỏ hơn $\textit{mid}$. Từ điều kiện này, ta lập bất đẳng thức và biến đổi:

$$
\displaystyle
\begin{aligned}
&\frac{\sum a_i\times w_i}{\sum b_i\times w_i}\ge mid\\
\Longrightarrow&\sum a_i\times w_i-mid\times \sum b_i\cdot w_i\ge 0\\
\Longrightarrow&\sum w_i\times(a_i-mid\times b_i)\ge 0
\end{aligned}
$$

Vì vậy chỉ cần tìm giá trị lớn nhất của vế trái. Nếu giá trị lớn nhất lớn hơn $0$ thì $mid$ khả thi, ngược lại là không khả thi. Khó khăn chính của quy hoạch phân thức nằm ở cách tìm giá trị lớn nhất hoặc nhỏ nhất của $\displaystyle \sum w_i\times(a_i-mid\times b_i)$.

### Thuật toán Dinkelbach

Ý tưởng khái quát của thuật toán Dinkelbach[^note1] là ở mỗi vòng lặp dùng đáp án của vòng trước làm $L$ mới để đưa vào, rồi tiếp tục lặp cho đến khi đáp án hội tụ.

## Ví dụ

???+ example "[LOJ 149 01 Quy hoạch phân thức](https://loj.ac/p/149)"
    Có $n$ vật, mỗi vật có hai trọng số $a$ và $b$. Tìm một bộ $w_i\in\{0,1\}$ sao cho trong các $w_i$ có đúng $k$ giá trị bằng $1$, đồng thời cực đại hóa giá trị $\displaystyle\frac{\sum a_i\times w_i}{\sum b_i\times w_i}$.

??? note "Lời giải"
    Lấy $a_i-mid\times b_i$ làm trọng số của vật thứ $i$, rồi tham lam chọn $k$ vật có trọng số lớn nhất. Nếu tổng trọng số lớn hơn $0$ thì khả thi, ngược lại là không khả thi.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/frac-programming/frac-1.cpp"
    ```

???+ example "[Luogu 4377 Talent Show G](https://www.luogu.com.cn/problem/P4377)"
    Có $n$ vật, mỗi vật có hai trọng số $a$ và $b$.
    
    Bạn cần xác định một bộ $w_i\in\{0,1\}$ sao cho $\displaystyle\frac{\sum w_i\times a_i}{\sum w_i\times b_i}$ lớn nhất.
    
    Yêu cầu $\displaystyle\sum w_i\times b_i \geq W$.

??? note "Lời giải"
    Bài này có thêm ràng buộc mẫu số ít nhất là $W$, nên không thể tiếp tục dùng thuật toán tham lam của bài trước.
    
    Có thể xét bài toán ba lô 01. Lấy $b_i$ làm khối lượng của vật thứ $i$, $a_i-mid\times b_i$ làm giá trị của vật thứ $i$, khi đó bài toán được chuyển thành ba lô. Khi ấy $dp[n][W]$ chính là giá trị lớn nhất.
    
    Trong quá trình DP, tổng khối lượng các vật có thể vượt quá $W$; khi đó chỉ cần xem trực tiếp là $W$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/frac-programming/frac-2.cpp"
    ```

???+ example "[POJ2728 Desert King](http://poj.org/problem?id=2728)"
    Mỗi cạnh có hai trọng số $a_i$ và $b_i$. Hãy tìm một cây khung $T$ sao cho $\displaystyle\frac{\sum_{e\in T}a_e}{\sum_{e\in T}b_e}$ nhỏ nhất.

??? note "Lời giải"
    Lấy $a_i-mid\times b_i$ làm trọng số của mỗi cạnh, khi đó cây khung nhỏ nhất cho ta giá trị nhỏ nhất. Bài này cần tìm cây khung nhỏ nhất trên một đồ thị đầy đủ, nên dùng thuật toán Prim để giải.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/frac-programming/frac-3.cpp"
    ```

???+ example "[\[HNOI2009\] Vòng nhỏ nhất](https://www.luogu.com.cn/problem/P3199)"
    Mỗi cạnh có trọng số $w$. Hãy tìm một chu trình $C$ sao cho $\displaystyle\frac{\sum_{e\in C}w}{|C|}$ nhỏ nhất.

??? note "Lời giải"
    Lấy $a_i-mid$ làm trọng số cạnh, khi đó chu trình có tổng trọng số nhỏ nhất chính là giá trị nhỏ nhất.
    
    Vì ta chỉ cần kiểm tra giá trị nhỏ nhất có nhỏ hơn $0$ hay không, nên chỉ cần kiểm tra trong đồ thị có tồn tại chu trình âm hay không.
    
    Ngoài ra, bài này còn có một thuật toán độ phức tạp $O(nm)$; nếu quan tâm, bạn có thể đọc [bài viết này](https://www.cnblogs.com/y-clever/p/7043553.html).

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/frac-programming/frac-4.cpp"
    ```

## Bài tập

-   [JSOI2016 Nhóm tốt nhất](https://loj.ac/problem/2071)
-   [SDOI2017 Vũ hội tân sinh](https://loj.ac/problem/2003)
-   [UVa1389 Hard Life](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4135)
-   [Luogu P2868 \[USACO07DEC\] Sightseeing Cows G](https://www.luogu.com.cn/problem/P2868)
-   [AtCoder Beginner Contest 324 F - Beautiful Path](https://atcoder.jp/contests/abc324/tasks/abc324_f)

## Tài liệu tham khảo và chú thích

[^note1]: [Dinkelbach, Werner. "On nonlinear fractional programming." Management science 13.7 (1967): 492-498.](https://doi.org/10.1287/mnsc.13.7.492)
