Kiến thức cần có: [ma trận](../math/linear-algebra/matrix.md), [phân rã cây theo chuỗi nặng nhẹ](../graph/hld.md).

Dynamic DP là một kỹ thuật được Mao Kun trình bày tại WC2018, thường dùng để giải các bài toán DP trên cây có thao tác sửa trọng số đỉnh (hoặc cạnh).

## Ví dụ

Dùng bài mẫu sau để minh họa quá trình dynamic DP.

???+ note "Bài ví dụ [Luogu P4719 [Mẫu] Dynamic DP](https://www.luogu.com.cn/problem/P4719)"
    Cho một cây có $n$ đỉnh, mỗi đỉnh có trọng số. Có $m$ thao tác, mỗi thao tác cho $x,y$ nghĩa là sửa trọng số của đỉnh $x$ thành $y$. Sau mỗi thao tác, cần tính trọng số của tập độc lập có trọng số lớn nhất trên cây.

### Phép nhân ma trận tổng quát

Định nghĩa phép nhân ma trận tổng quát $A\times B=C$ như sau:

$$
C_{i,j}=\max_{k=1}^{n}(A_{i,k}+B_{k,j})
$$

Nó tương đương với việc thay phép nhân trong nhân ma trận thông thường bằng phép cộng, và thay phép cộng bằng phép $\max$.

Phép nhân ma trận tổng quát vẫn thỏa mãn tính kết hợp, nên có thể dùng lũy thừa ma trận nhanh.

### Không có thao tác sửa

Đặt $f_{i,0}$ là đáp án lớn nhất khi không chọn $i$, và $f_{i,1}$ là đáp án lớn nhất khi chọn $i$.

Khi đó có phương trình DP:

$$
\begin{cases}f_{i,0}=\sum_{son}\max(f_{son,0},f_{son,1})\\f_{i,1}=w_i+\sum_{son}f_{son,0}\end{cases}
$$

Đáp án là $\max(f_{root,0},f_{root,1})$.

### Có thao tác sửa

Trước hết phân rã cây theo chuỗi nặng nhẹ. Giả sử có một chuỗi nặng như sau:

![](./images/dynamic.png)

Đặt $g_{i,0}$ là đáp án lớn nhất khi không chọn $i$ và chỉ cho phép chọn trong các cây con của con nhẹ của $i$; đặt $g_{i,1}$ là đáp án lớn nhất khi chọn $i$ nhưng không xét $son_i$; trong đó $son_i$ là con nặng của $i$.

Giả sử đã biết $g_{i,0/1}$, phương trình DP là:

$$
\begin{cases}f_{i,0}=g_{i,0}+\max(f_{son_i,0},f_{son_i,1})\\f_{i,1}=g_{i,1}+f_{son_i,0}\end{cases}
$$

Đáp án là $\max(f_{root,0},f_{root,1})$.

Có thể dựng ma trận:

$$
\begin{bmatrix}
g_{i,0} & g_{i,0}\\
g_{i,1} & -\infty
\end{bmatrix}\times 
\begin{bmatrix}
f_{son_i,0}\\f_{son_i,1}
\end{bmatrix}=
\begin{bmatrix}
f_{i,0}\\f_{i,1}
\end{bmatrix}
$$

Lưu ý rằng phần này dùng quy tắc nhân tổng quát.

Khi sửa, chỉ cần sửa $g_{i,1}$ và các chuỗi nặng đi lên phía trên.

### Ý tưởng cụ thể

1.  Dùng DFS tiền xử lý để tính $f_{i,0/1}$ và $g_{i,0/1}$.

2.  Phân rã cây theo chuỗi nặng nhẹ. Lưu ý: vì khi truy vấn một đỉnh cần tính tích ma trận trên đoạn từ đỉnh đó tới cuối chuỗi nặng chứa nó, với mỗi đỉnh ghi $End_i$ là số hiệu đỉnh cuối của chuỗi nặng chứa $i$. Trên mỗi chuỗi nặng dựng một cây phân đoạn; cây phân đoạn duy trì ma trận $g$ và tích đoạn của các ma trận $g$.

3.  Khi sửa, trước hết sửa $g_{i,1}$ và ma trận của đỉnh $i$ trong cây phân đoạn, tính lượng thay đổi của ma trận $top_i$, rồi cập nhật vào ma trận của $fa_{top_i}$.

4.  Khi truy vấn, lấy tích đoạn từ đỉnh $1$ tới cuối chuỗi nặng chứa nó, rồi lấy $\max$ là được.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/dp/code/dynamic/dynamic_1.cpp"
    ```

## Bài tập

-   [SPOJ GSS3 - Can you answer these queries III](https://www.spoj.com/problems/GSS3/)
-   [「NOIP2018」Bảo vệ vương quốc](https://loj.ac/p/2955)
-   [「SDOI2017」Trò chơi cắt cây](https://loj.ac/p/2269)
