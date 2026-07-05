Bài toán cây Steiner là một bài toán tối ưu tổ hợp, tương tự cây khung nhỏ nhất và thuộc nhóm bài toán mạng ngắn nhất. Cây khung nhỏ nhất tìm một mạng ngắn nhất trên tập đỉnh và tập cạnh đã cho sao cho mọi đỉnh liên thông. Còn cây Steiner nhỏ nhất cho phép thêm các đỉnh phụ ngoài các đỉnh đã cho để tổng chi phí của mạng thu được là nhỏ nhất.

## Dẫn nhập bài toán

Đầu thế kỷ 19, Steiner, một học giả hình học nổi tiếng của Đại học Berlin, nghiên cứu một bài toán rất đơn giản nhưng giàu gợi mở: nối ba ngôi làng bằng một hệ đường có tổng chiều dài nhỏ nhất. Diễn đạt bằng toán học, với ba điểm $A$, $B$, $C$ trên mặt phẳng, hãy tìm điểm thứ tư $P$ trên mặt phẳng sao cho tổng $a+b+c$ là nhỏ nhất, trong đó $a$, $b$, $c$ lần lượt là khoảng cách từ $P$ đến $A$, $B$, $C$.

Đáp án là: nếu mọi góc trong của tam giác $\textit{ABC}$ đều nhỏ hơn $120^{\circ}$, thì $P$ là điểm sao cho các cạnh $\textit{AB}$, $\textit{BC}$, $\textit{AC}$ đều chắn tại điểm đó một góc $120^{\circ}$. Nếu tam giác $\textit{ABC}$ có một góc, chẳng hạn góc $C$, lớn hơn hoặc bằng $120^{\circ}$, thì điểm $P$ trùng với đỉnh $C$.

### Mở rộng bài toán

1.  Trong bài toán Steiner, ta được cho ba điểm cố định $A,B,C$. Một cách mở rộng tự nhiên là xét trường hợp cho $n$ điểm $A_1,A_2,\dots,A_n$; cần tìm điểm $P$ trên mặt phẳng sao cho tổng khoảng cách $a_1+a_2+\dots+a_n$ là nhỏ nhất, trong đó $a_i$ là khoảng cách $PA_i$.

2.  Khi xét thêm các yếu tố khác liên quan đến từng điểm, ta có thể đưa vào trọng số. Các yếu tố này của $n$ điểm có thể được quy đổi thành trọng số, rồi tìm điểm $P$ trên mặt phẳng sao cho tổng các tích giữa khoảng cách và trọng số $a_1\cdot w_1+a_2\cdot w_2+\dots+a_n\cdot w_n$ là nhỏ nhất, trong đó $w_i$ là trọng số của mỗi điểm.

3.  Courant (R. Courant) và Robbins (H. Robbins) cho rằng cách mở rộng trong định nghĩa đầu tiên còn hời hợt. Để có một mở rộng thật sự có giá trị cho bài toán Steiner, cần từ bỏ việc tìm một điểm đơn lẻ $P$ và thay vào đó tìm một "mạng đường" có tổng chiều dài nhỏ nhất. Diễn đạt toán học: cho $n$ điểm $A_1,A_2,\cdots,A_n$, hãy tìm một hệ các đoạn thẳng nối $n$ điểm này có tổng chiều dài nhỏ nhất, đồng thời hai điểm bất kỳ đều có thể được nối với nhau bằng một đường gấp khúc gồm các đoạn thẳng trong hệ. Họ gọi bài toán mới này là **bài toán cây Steiner**. Với $n$ điểm đã cho, có nhiều nhất $n-2$ điểm nối phụ (điểm Steiner). Qua mỗi điểm Steiner có nhiều nhất ba cạnh đi qua. Nếu có ba cạnh, chúng đôi một tạo với nhau góc $120^{\circ}$; nếu có hai cạnh, điểm Steiner đó phải là một điểm đã cho, và góc tạo bởi hai cạnh này phải lớn hơn hoặc bằng $120^{\circ}$.

Mạng ngắn nhất nối nhiều hơn ba điểm:

![Mạng ngắn nhất nối nhiều điểm trong bài toán Steiner](./images/steiner-tree-1.svg)

Trong trường hợp thứ nhất, nghiệm gồm năm đoạn thẳng, trong đó có hai điểm Steiner (màu đỏ $s_1,s_2$); tại mỗi điểm này có ba đoạn thẳng giao nhau và các góc giữa chúng đều là $120^{\circ}$. Trường hợp thứ hai có nghiệm chứa ba điểm Steiner. Trong trường hợp thứ ba, một hoặc vài điểm Steiner có thể bị suy biến, hoặc được thay bằng một hoặc vài điểm đã cho.

Ta biểu diễn mô hình bài toán cây Steiner dưới dạng đồ thị.

![Mô hình đồ thị của bài toán cây Steiner](./images/steiner-tree-2.svg)

Với dạng thứ nhất, nếu đặt tập đỉnh quan trọng là $\{1,2,3,4\}$, có thể thấy tổng trọng số cạnh nhỏ nhất khi nối trực tiếp bốn đỉnh quan trọng này là 12, rõ ràng chưa tối ưu. Nếu xét thêm đỉnh số 5, tổng trọng số cạnh nhỏ nhất trở thành 9, cho một đáp án tốt hơn.

Với dạng thứ hai, nếu đặt tập đỉnh quan trọng là $\{1,2,3,4\}$, có thể thấy một số đỉnh trong bốn đỉnh quan trọng này thậm chí không có cạnh nối trực tiếp với nhau, nên phải xét các điểm nối phụ (điểm Steiner). Khi đưa đỉnh số 5 vào xét, ta thu được tổng trọng số cạnh nhỏ nhất là 9.

Ngoài ra, có thể thấy trong cả hai đồ thị, các điểm Steiner ở vị trí đỉnh số 1 và số 4 đã bị suy biến, tức được thay bằng đỉnh số 1 hoặc số 4.

## Ví dụ

Trước hết, ta dùng một bài mẫu để làm quen với bài toán cây Steiner nhỏ nhất. Xem [Bài mẫu: Cây Steiner nhỏ nhất](https://www.luogu.com.cn/problem/P6192).

Đề bài khá rõ ràng: cho đồ thị liên thông $G$ có $n$ đỉnh và $k$ đỉnh quan trọng, hãy nối $k$ đỉnh quan trọng sao cho tổng trọng số của mọi cạnh trong cây sinh ra là nhỏ nhất.

Kết hợp với phần trên, ta biết rằng tổng trọng số khi nối trực tiếp $k$ đỉnh quan trọng chưa chắc đã nhỏ nhất, hoặc $k$ đỉnh quan trọng này không nhất thiết nối trực tiếp (kề nhau). Vì vậy cần sử dụng thêm $n-k$ đỉnh còn lại.

Ta dùng quy hoạch động nén trạng thái để giải. Gọi $f(i,S)$ là tổng trọng số cạnh nhỏ nhất của một cây gốc $i$ chứa mọi đỉnh trong tập $S$.

Xét chuyển trạng thái:

-   Trước hết, chuyển trên các tập con đã liên thông: $f(i,S)\leftarrow \min(f(i,S),f(i,T)+f(i,S-T))$.

-   Với trạng thái liên thông của tập con hiện tại, thực hiện thao tác nới lỏng cạnh: $f(i,S)\leftarrow \min(f(i,S),f(j,S)+w(j,i))$. Trong đoạn mã dưới đây, `tree[tot]` được dùng để ghi thông tin liên quan đến hai đỉnh kề nhau $i,j$.

??? note "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/graph/code/steiner-tree/steiner-tree_1.cpp"
    ```

Một ví dụ kinh điển khác là [\[WC2008\] Kế hoạch tham quan](https://www.luogu.com.cn/problem/P4294).

Bài này yêu cầu tìm cây Steiner có tổng trọng số đỉnh nhỏ nhất. Gọi $f(i,S)$ là tổng trọng số đỉnh nhỏ nhất của một cây gốc $i$ chứa mọi đỉnh trong tập $S$. $a_i$ biểu diễn trọng số đỉnh.

Xét chuyển trạng thái:

-   $f(i,S)\leftarrow \min(f(i,S),f(i,T)+f(i,S-T)-a_i)$. Khi gộp ở đây, cùng một đỉnh $a_i$ sẽ bị cộng hai lần, nên cần trừ đi một lần.

-   $f(i,S)\leftarrow \min(f(i,S),f(j,S)+w(j,i))$.

Có thể thấy chuyển trạng thái tương tự bài mẫu ở trên; phần rắc rối là xuất đáp án, vì trong quá trình DP còn phải ghi lại đường đi.

Dùng `pre[i][s]` để ghi thông tin về đỉnh và tập khi chuyển đến trạng thái có gốc $i$ và tập trạng thái liên thông là $s$. Sau khi DP kết thúc, bắt đầu từ `pre[root][S]`, tìm các đỉnh nối với những đỉnh trong tập rồi dần phân rã tập $S$. Dùng mảng `ans` để ghi các đỉnh đã được sử dụng; khi tập đã phân rã xong thì quá trình tìm kiếm cũng kết thúc.

??? note "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/graph/code/steiner-tree/steiner-tree_2.cpp"
    ```

## Bài tập

-   [Bài mẫu: Cây Steiner nhỏ nhất](https://www.luogu.com.cn/problem/P6192)
-   [\[WC2008\] Kế hoạch tham quan](https://www.luogu.com.cn/problem/P4294)
-   [\[JLOI2015\] Nối đường ống](https://loj.ac/problem/2110)
-   [\[APIO2013\] Robot](https://www.luogu.com.cn/problem/P3638)
