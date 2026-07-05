Kiến thức nền: [Thuật toán A\*](./astar.md), [Tìm kiếm sâu dần](./iterative.md)

Trang này giới thiệu ngắn gọn về thuật toán IDA\*. IDA\* chính là thuật toán A\* áp dụng chiến lược tìm kiếm sâu dần.

<span id="quy-trình"></span>
## Quy trình

IDA\* là một biến thể của tìm kiếm sâu dần. Tìm kiếm sâu dần giới hạn độ sâu tìm kiếm trong mỗi lần DFS, còn IDA\* giới hạn chi phí đường đi trong một lần DFS.

Trong một vòng lặp, thuật toán bắt đầu DFS từ đỉnh xuất phát $s$, ghi lại chi phí thực tế $g(x)$ để đi tới đỉnh hiện tại $x$, và dùng ước lượng chi phí nhỏ nhất $h(x)$ từ $x$ đến đích để cắt tỉa. Nếu tổng chi phí ước lượng để đi tới đích theo đường hiện tại

$$
f(x) = g(x) + h(x)
$$

vượt quá ngưỡng $C$, thuật toán dừng tìm kiếm trên nhánh đó.

Ngưỡng $C$ được cập nhật động giữa các vòng lặp. Ngưỡng ban đầu lấy bằng tổng chi phí ước lượng tại đỉnh xuất phát, tức $h(s)$. Trong một vòng lặp, mỗi khi dừng vì vượt ngưỡng, ta ghi lại giá trị nhỏ nhất trong các tổng chi phí ước lượng của những đỉnh kế tiếp chưa được thăm. Sau khi vòng lặp kết thúc, cập nhật ngưỡng thành giá trị nhỏ nhất này rồi tiếp tục vòng tìm kiếm kế tiếp.

<span id="tính-chất"></span>
## Tính chất

Vì IDA\* dùng cùng chiến lược cắt tỉa với A\*, các tính chất đã thảo luận cho thuật toán A\* cũng áp dụng cho IDA\*.

So với A\*, IDA\* có các ưu điểm sau:

-   Không cần kiểm tra trùng lặp, không cần sắp xếp, thuận lợi cho cắt tỉa theo chiều sâu.
-   Giảm nhu cầu bộ nhớ. Mỗi vòng lặp đều là một lần tìm kiếm theo chiều sâu, nhưng chi phí đường đi trong quá trình tìm kiếm bị giới hạn; dùng DFS giúp giảm mức tiêu thụ bộ nhớ.

Đồng thời, nó cũng có nhược điểm:

-   Tìm kiếm lặp lại. Ngay cả khi hai lần tìm kiếm liên tiếp chỉ khác nhau rất ít, mỗi lần nới lỏng giới hạn vẫn phải tìm lại từ đầu.

<span id="cài-đặt"></span>
## Cài đặt

Giả sử $h$ là một hàm ước lượng phù hợp và $s$ là đỉnh xuất phát. Quy trình đầy đủ của thuật toán có thể mô tả đại khái như sau:

$$
\begin{array}{l}
\textbf{Algorithm. }\textrm{IdaStar}():\\
\textbf{Output. }\text{The shortest path, }\textit{path}\text{, and its cost, }C\text{, if a path exists,}\\
\quad \text{and }\textrm{NOT}\_\textrm{FOUND}\text{, otherwise.}\\
\textbf{Method.}\\
\begin{array}{ll}
1  & C \gets h(s) \\
2  & path \gets [s] \\
3  & \textbf{while }\text{true}\\
4  & \quad t \gets \textrm{Search}(\textit{path},0,C)\\
5  & \quad \textbf{if } t=\text{FOUND}\textbf{ then return }(\textit{path},C) \\
6  & \quad \textbf{if } t=\infty\textbf{ then return }\textrm{NOT}\_\textrm{FOUND} \\
7  & \quad C \gets t
\end{array}\\
\\
\textbf{Sub-Algorithm. }\textrm{Search}(\textit{path},g,C):\\
\textbf{Input. }\text{The current path, }\textit{path}\text{, its cost, }g\text{, and search limit }C.\\
\textbf{Output. }\text{FOUND, if the target node has been reached; }\infty\text{, if all}\\
\quad \text{reachable nodes have been explored; otherwise, the minimum}\\
\quad \text{total cost, }t\text{, among nodes not yet explored.}\\
\textbf{Method.}\\
\begin{array}{ll}
1  & \textit{node} \gets \text{the last element in }\textit{path}\\
2  & f \gets g + h(\textit{node}) \\
3  & \textbf{if } f > C \textbf{ then return } f \\
4  & \textbf{if }\textit{node}\text{ is the target }\textbf{then return }\text{FOUND}\\
5  & \textit{min} \gets \infty \\
6  & \textbf{for }\text{each }\textit{child}\text{ of }\textit{node }\textbf{do}\\
7  & \quad \textbf{if }\textit{child}\text{ not in }\textit{path}\textbf{ then}\\
8  & \quad \quad \text{append }\textit{child}\text{ to }\textit{path}\\
9  & \quad \quad t \gets \text{Search}(\textit{path}, g + \text{Cost}(\textit{node},\textit{child}), C)\\
10 & \quad \quad \textbf{if }t = \text{FOUND}\textbf{ then return }\text{FOUND}\\
11 & \quad \quad \textbf{if }t < \textit{min}\textbf{ then }\textit{min}\gets t\\
12 & \quad \quad \text{remove the last element of }\textit{path}\\
13 & \textbf{return }\textit{min}
\end{array}
\end{array}
$$

<span id="ví-dụ"></span>
## Ví dụ

???+ example "[Phân số Ai Cập](https://www.luogu.com.cn/problem/P1763)"
    Ở Ai Cập cổ đại, người ta biểu diễn mọi số hữu tỉ bằng tổng của các phân số đơn vị đôi một khác nhau, tức các số dạng $1/a$ với $a\in\mathbf{N}_+$. Ví dụ, $\dfrac{2}{3}=\dfrac{1}{2}+\dfrac{1}{6}$, nhưng không cho phép $\dfrac{2}{3}=\dfrac{1}{3}+\dfrac{1}{3}$, vì trong các số hạng không được có hai phân số đơn vị giống nhau.
    
    Với một phân số $\dfrac{a}{b}$, có nhiều cách biểu diễn. Quy ước: trong các cách biểu diễn khác nhau của cùng một phân số, cách nào có ít số hạng hơn thì tốt hơn; nếu số hạng bằng nhau, cách nào có phân số nhỏ nhất lớn hơn thì tốt hơn. Chẳng hạn, $\dfrac{19}{45}=\dfrac{1}{5}+\dfrac{1}{6}+\dfrac{1}{18}$ là phương án tối ưu.
    
    Cho hai số nguyên $a,b$ ($0<a<b<1000$), hãy lập trình tính biểu thức tối ưu.

??? note "Hướng giải"
    Về lý thuyết, bài này có thể giải bằng quay lui, nhưng cây nghiệm sẽ rất lớn: độ sâu không có cận trên rõ ràng, và về lý thuyết lựa chọn số hạng cũng là vô hạn. Nói cách khác, nếu duyệt theo chiều rộng thì ngay cả một tầng cũng không mở rộng hết được, vì mỗi tầng đều có kích thước vô hạn.
    
    Cách giải là dùng tìm kiếm sâu dần: lần lượt liệt kê giới hạn độ sâu $C$ từ nhỏ đến lớn, mỗi lần tìm kiếm chỉ xét các đỉnh có độ sâu không vượt quá $C$. Như vậy, miễn là nghiệm có độ sâu hữu hạn, ta chắc chắn có thể liệt kê được trong thời gian hữu hạn.
    
    Giới hạn độ sâu $C$ còn có thể dùng để cắt tỉa. Mở rộng theo thứ tự mẫu số tăng dần. Nếu khi mở rộng đến tầng $i$, tổng của $i$ phân số đầu là $\dfrac{c}{d}$, và phân số thứ $i$ là $\dfrac{1}{e}$, thì tiếp theo ít nhất cần thêm
    
    $$
    h = \left(\dfrac{a}{b}-\dfrac{c}{d}\right)/\left(\dfrac{1}{e+1}\right)
    $$
    
    phân số nữa để tổng có thể đạt tới $\dfrac{a}{b}$. Ví dụ, nếu đang tìm đến $\dfrac{19}{45}=\dfrac{1}{5}+\dfrac{1}{100}+\cdots$, thì mỗi phân số phía sau lớn nhất cũng chỉ là $\dfrac{1}{101}$; do đó cần ít nhất $\left({\dfrac{19}{45}-\dfrac{1}{5}}\right)/\left({\dfrac{1}{101}}\right)=23$ số hạng để tổng đạt tới $\dfrac{19}{45}$. Vì thế, $22$ lần lặp đầu tiên hoàn toàn sẽ không xét cây con này. Điểm then chốt ở đây là: ta có thể ước lượng ít nhất còn cần bao nhiêu bước nữa mới tìm được nghiệm.
    
    Lưu ý, từ "ít nhất" ở đây cho thấy ước lượng này là "lạc quan". Giống như trong thuật toán A\*, một hàm ước lượng tốt cần phải "lạc quan", nghĩa là không được đánh giá cao hơn chi phí thực tế. Thay giới hạn độ sâu $g\le C$ trong tìm kiếm sâu dần bằng giới hạn chặt hơn $g + h \le C$ sẽ thu được thuật toán IDA\* được thảo luận trong trang này. Vì trong bài này chi phí đường đi chính là độ dài của nó, IDA\* cũng giới hạn độ dài đường đi, chỉ khác là cộng thêm ước lượng về số bước còn cần. Trong các bài toán tổng quát hơn, tùy theo loại chi phí cần tối thiểu hóa, ta có thể thiết kế các hàm ước lượng khác.
    
    Trong cài đặt, ta tiếp tục tối ưu IDA\* bằng các cắt tỉa sau:
    
    1.  Khi mở rộng đỉnh, mẫu số tiếp theo cần xét ít nhất là $\left(\dfrac{a}{b}-\dfrac{c}{d}\right)^{-1}$; có thể dùng giá trị này để cải thiện điểm bắt đầu khi liệt kê $e$.
    2.  Giới hạn chi phí đường đi của IDA\* có thể biến đổi thành
    
        $$
        e \le \left(\dfrac{a}{b}-\dfrac{c}{d}\right)^{-1}(C-g) - 1.
        $$
    
        Vì vậy, không cần liệt kê tất cả mẫu số tiếp theo rồi kiểm tra từng cái; chỉ cần liệt kê đến cận trên này.
    3.  Khi tìm đến hai phân số cuối cùng, dùng trực tiếp phương trình bậc hai để kiểm tra tính khả thi thay vì tiếp tục tìm kiếm. Cụ thể, cần tìm $e<x<y\le E_\text{max}$ sao cho
    
        $$
        \dfrac{1}{x} + \dfrac{1}{y} = \dfrac{p}{q} := \dfrac{a}{b}-\dfrac{c}{d},
        $$
    
        chỉ cần giải hệ phương trình bậc hai hai ẩn
    
        $$
        \begin{cases}
        x + y = kp,\\
        xy = kq
        \end{cases}
        $$
    
        trong đó $k\in\mathbf N_+$. Theo kiến thức về phương trình bậc hai, hệ phương trình chỉ có hai nghiệm thực phân biệt khi
    
        $$
        \Delta = k^2p^2-4kq > 0 \iff k > \dfrac{4q}{p^2}
        $$
    
        và khi đó
    
        $$
        x = \dfrac{kp - \sqrt{\Delta}}{2},~ y = \dfrac{kp + \sqrt{\Delta}}{2}.
        $$
    
        Do đó, có thể trực tiếp liệt kê mọi $k$ khả thi và kiểm tra xem có tồn tại một cặp nghiệm nguyên như vậy hay không. Cận trên khi liệt kê $k$ được xác định bằng điều kiện $y < E_\text{max}$.
    4.  Mỗi khi tìm được một đáp án, điều chỉnh cận trên mẫu số $M_e$ thành mẫu số lớn nhất trong đáp án hiện tại trừ đi một.
    
    Ngoài ra, trong cài đặt, ta trực tiếp lưu giá trị của $\dfrac{a}{b}-\dfrac{c}{d}$ và $C-g$. Tử số và mẫu số của giá trị thứ nhất lần lượt được lưu trong hai biến `a` và `b`, còn giá trị thứ hai được lưu trong biến `d`.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/search/code/idastar/idastar_1.cpp"
    ```

<span id="bài-tập"></span>
## Bài tập

-   [UVa1343 Trò chơi xoay](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4089)
