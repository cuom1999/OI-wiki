Trước khi đọc bài này, hãy đọc trước [tự động hữu hạn](../misc/fsm.md).

<span id="&#23450;&#20041;"></span>
## Định nghĩa

Sequence automaton là tự động chỉ chấp nhận các dãy con của một xâu duy nhất.

Trong bài này, dùng $s$ để chỉ xâu đó.

<span id="&#29366;&#24577;"></span>
### Trạng thái

Nếu $s$ chứa $n$ ký tự, sequence automaton có $n+1$ trạng thái.

Gọi $t$ là một dãy con của $s$, khi đó $\delta(start, t)$ là vị trí kết thúc khi $t$ xuất hiện lần đầu trong $s$.

Nói cách khác, trạng thái $i$ biểu diễn hiệu của tập dãy con của tiền tố $s[1..i]$ và tập dãy con của tiền tố $s[1..i-1]$.

Mọi trạng thái trên sequence automaton đều là trạng thái chấp nhận.

<span id="&#36716;&#31227;"></span>
### Chuyển trạng thái

Từ định nghĩa trạng thái, ta có $\delta(u, c)=\min\{i|i>u,s[i]=c\}$, tức vị trí xuất hiện tiếp theo của ký tự $c$.

Tại sao là vị trí xuất hiện "tiếp theo"? Vì nếu $i>j$, tập dãy con của hậu tố $s[i..|s|]$ là tập con của tập dãy con của hậu tố $s[j..|s|]$; chọn vị trí càng sớm càng tốt là tối ưu.

<span id="&#23454;&#29616;"></span>
## Cài đặt

Quét từ sau ra trước, trong quá trình đó duy trì vị trí xuất hiện sớm nhất của mỗi ký tự:

$$
\begin{array}{ll}
1 & \textbf{Input. } \text{A string } S\\
2 & \textbf{Output. } \text{The state transition of the sequence automaton of }S \\
3 & \textbf{Method. }  \\
4 & \textbf{for }c\in\Sigma\\
5 & \qquad next[c]\gets null\\
6 & \textbf{for }i\gets|S|\textbf{ downto }1\\
7 & \qquad next[S[i]]\gets i\\
8 & \qquad \textbf{for }c\in\Sigma\\
9 & \qquad\qquad \delta(i-1,c)\gets next[c]\\
10 & \textbf{return }\delta
\end{array}
$$

Độ phức tạp xây dựng như vậy là $O(n|\Sigma|)$.

<span id="&#20363;&#39064;"></span>
## Ví dụ

???+ example "[HEOI2015] Xâu con không chung ngắn nhất](https://loj.ac/problem/2123)"
    Cho hai xâu $A$ và $B$ gồm chữ cái tiếng Anh thường ($1\le |A|, |B|\le 2000$), hãy tìm:
    
    1.  một xâu con liên tiếp ngắn nhất của $A$ không phải xâu con liên tiếp của $B$;
    2.  một xâu con liên tiếp ngắn nhất của $A$ không phải dãy con của $B$;
    3.  một dãy con ngắn nhất của $A$ không phải xâu con liên tiếp của $B$;
    4.  một dãy con ngắn nhất của $A$ không phải dãy con của $B$.

??? note "Lời giải"
    Câu 1 và câu 3 của bài cần hậu tố tự động, hơn nữa cách làm tương tự nhau; ở đây chỉ giải thích câu 2 và câu 4.
    
    Câu 2 khá đơn giản: duyệt các xâu con liên tiếp của $A$ rồi đưa vào sequence automaton của $B$; nếu không được chấp nhận thì cập nhật đáp án.
    
    Câu 4 cần quy hoạch động. Gọi $f(i, j)$ là số ký tự tối thiểu cần thêm để không còn là dãy con chung, khi đang ở trạng thái $i$ trong sequence automaton của $A$ và trạng thái $j$ trong sequence automaton của $B$. Phương trình chuyển trạng thái là:
    
    $$
    f(i, j)=\min_{\delta_A(i,c)\ne \textit{null}}f(\delta_A(i, c), \delta_B(j, c))+1.
    $$
    
    Điểm bắt đầu chuyển là $f(i, \textit{null})=0$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/seq-automaton/seq-automaton_1.cpp"
    ```
