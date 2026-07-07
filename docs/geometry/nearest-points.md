## Dẫn nhập

Cho $n$ điểm trên mặt phẳng hai chiều, tìm một cặp điểm có khoảng cách Euclid nhỏ nhất.

Phần dưới đây giới thiệu một thuật toán chia để trị có độ phức tạp thời gian $O(n\log n)$ để giải bài toán này. Thuật toán này được [Franco P. Preparata](https://en.wikipedia.org/wiki/Franco_P._Preparata) đề xuất vào năm 1975; Preparata và [Michael Ian Shamos](https://en.wikipedia.org/wiki/Michael_Ian_Shamos) đã chứng minh thuật toán này là tối ưu trong mô hình cây quyết định.

## Quá trình

Giống như các thuật toán chia để trị thông thường, chia tập gồm $n$ điểm này thành hai tập có kích thước bằng nhau $S_1, S_2$, rồi tiếp tục đệ quy. Tuy nhiên, xuất hiện một khó khăn: hợp nhất như thế nào? Nói cách khác, làm sao tìm được cặp điểm gần nhất trong đó một điểm thuộc $S_1$ và điểm còn lại thuộc $S_2$? Trước hết, giả sử thao tác hợp nhất có độ phức tạp thời gian $O(n)$; khi đó tổng độ phức tạp của thuật toán là $T(n) = 2T(\frac{n}{2}) + O(n) = O(n\log n)$.

Trước tiên, sắp xếp tất cả các điểm theo $x_i$ làm khóa thứ nhất và $y_i$ làm khóa thứ hai. Sau đó lấy điểm $p_m (m = \lfloor \frac{n}{2} \rfloor)$ làm điểm phân chia, tách tập điểm thành $A_1,A_2$:

$$
\begin{aligned}
A_1 &= \{p_i \ \big | \ i = 0 \ldots m \}\\
A_2 &= \{p_i \ \big | \ i = m + 1 \ldots n-1 \}
\end{aligned}
$$

Tiếp tục đệ quy, tìm cặp điểm gần nhất trong từng tập con. Giả sử hai khoảng cách tương ứng là $h_1,h_2$, lấy giá trị nhỏ hơn và gọi là $h$.

Bây giờ cần hợp nhất kết quả. Cần tìm các cặp điểm sao cho một điểm thuộc $A_1$, điểm còn lại thuộc $A_2$, và khoảng cách giữa chúng nhỏ hơn $h$. Vì vậy, đưa tất cả các điểm có hiệu hoành độ với $x_m$ nhỏ hơn $h$ vào tập $B$:

$$
B = \{ p_i \ \big | \ \lvert x_i - x_m \rvert < h \}
$$

Kết hợp với hình vẽ, đường thẳng $m$ chia các điểm thành hai phần. Bên trái $m$ là tập điểm $A_1$, bên phải là tập điểm $A_2$.

Sau đó, theo quy tắc $B = \{ p_i \ \big | \ \lvert x_i - x_m \rvert < h \}$, thu được tập điểm $B$ gồm các điểm màu xanh lá. ![Dải phân chia trong bài cặp điểm gần nhất](./images/nearest-points1.png)

Với mỗi điểm $p_i$ trong $B$, mục tiêu hiện tại là tìm một điểm cũng thuộc $B$ và có khoảng cách đến nó nhỏ hơn $h$. Để tránh xét một cặp điểm hai lần, chỉ xét các điểm có tung độ nhỏ hơn $y_i$. Với một điểm hợp lệ $p_j$, cần có $y_i - y_j < h$. Vì vậy, thu được tập $C(p_i)$:

$$
C(p_i) = \{ p_j\ \big |\ p_j \in B,\ y_i - h < y_j \le y_i \}
$$

Chọn một điểm $p_i$ trong tập $B$; theo quy tắc $C(p_i) = \{ p_j\ \big |\ p_j \in B,\ y_i - h < y_j \le y_i \}$, thu được tập điểm $C$ gồm các điểm màu vàng trong khung đỏ.

![Tập điểm ứng viên trong bài cặp điểm gần nhất](./images/nearest-points2.png)

Nếu sắp xếp các điểm trong $B$ theo $y_i$, thì $C(p_i)$ thu được rất nhanh: đó là vài điểm liên tiếp nằm ngay cạnh $p_i$.

Từ đó có các bước hợp nhất:

1.  Xây dựng tập $B$.
2.  Sắp xếp các điểm trong $B$ theo $y_i$. Cách thông thường mất $O(n\log n)$, nhưng có thể thay đổi chiến lược để tối ưu xuống $O(n)$ (sẽ giải thích ở dưới).
3.  Với mỗi $p_i \in B$, xét các $p_j \in C(p_i)$; với mỗi cặp $(p_i,p_j)$, tính khoảng cách và cập nhật đáp án, tức là cặp điểm gần nhất trong tập hiện tại.

Lưu ý rằng ở trên đã nhắc đến việc sắp xếp hai lần. Vì tọa độ các điểm không thay đổi trong toàn bộ quá trình, lần sắp xếp đầu tiên chỉ cần thực hiện một lần trước khi bắt đầu chia để trị. Mỗi lần đệ quy trả về kết quả của tập điểm hiện tại đã được sắp xếp theo $y_i$; với lần sắp xếp thứ hai, tầng trên chỉ cần trộn hai tập điểm đã được sắp xếp từ tầng dưới.

Thoạt nhìn thuật toán này dường như vẫn chưa tối ưu, vì $|C(p_i)|$ có thể ở bậc $O(n)$, khiến tổng độ phức tạp không đúng. Tuy nhiên, kích thước lớn nhất của nó là $7$. Chứng minh như sau:

## Chứng minh độ phức tạp

Tung độ của mọi điểm trong $C(p_i)$ đều nằm trong khoảng $(y_i-h,y_i]$; đồng thời mọi điểm trong $C(p_i)$ và cả chính $p_i$ đều có hoành độ nằm trong khoảng $(x_m-h,x_m+h)$. Các điểm này tạo thành một hình chữ nhật kích thước $2h \times h$.

Tiếp theo, chia hình chữ nhật này thành hai hình vuông $h \times h$. Không tính $p_i$, các điểm trong một hình vuông là $C(p_i) \cap A_1$, còn trong hình vuông kia là $C(p_i) \cap A_2$. Khoảng cách giữa hai điểm bất kỳ trong cùng một hình vuông đều lớn hơn $h$, vì chúng đến từ cùng một nhánh đệ quy ở tầng dưới.

Chia một hình vuông $h \times h$ thành bốn hình vuông nhỏ kích thước $\frac{h}{2} \times \frac{h}{2}$. Mỗi hình vuông nhỏ chứa nhiều nhất $1$ điểm: vì khoảng cách lớn nhất giữa hai điểm bất kỳ trong hình vuông nhỏ là độ dài đường chéo, tức $\frac{h}{\sqrt 2}$, nhỏ hơn $h$.

![Chứng minh đóng gói cho bài cặp điểm gần nhất](./images/nearest-points3.png)

Do đó, mỗi hình vuông chứa nhiều nhất $4$ điểm, hình chữ nhật chứa nhiều nhất $8$ điểm. Bỏ đi chính $p_i$, có $\max(C(p_i))=7$.

???+ example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/geometry/code/nearest-points/nearest-points_1.cpp"
    ```

## Mở rộng: tam giác có chu vi nhỏ nhất trên mặt phẳng

Thuật toán trên có thể được mở rộng một cách thú vị cho bài toán sau: trong một tập điểm cho trước, chọn ba điểm sao cho tổng khoảng cách từng đôi một giữa chúng là nhỏ nhất.

Ý tưởng thuật toán nhìn chung không đổi. Mỗi lần cần tìm một tam giác có chu vi nhỏ hơn đáp án hiện tại $d$, đưa tất cả các điểm có hiệu hoành độ với $x_m$ nhỏ hơn $\frac{d}{2}$ vào tập $B$, rồi thử cập nhật đáp án. Cạnh dài nhất của một tam giác có chu vi $d$ nhỏ hơn $\frac{d}{2}$.

## Thuật toán không chia để trị

Ngoài thuật toán chia để trị ở trên, còn có một thuật toán không chia để trị với cùng độ phức tạp thời gian $O(n \log n)$.

Có thể xét một ý tưởng thường gặp trong thống kê trên dãy: với mỗi phần tử, cộng đóng góp của nó với tất cả các phần tử bên trái vào đáp án. Bài toán cặp điểm gần nhất trên mặt phẳng cũng có thể dùng ý tưởng này.

Cụ thể, sắp xếp tất cả các điểm theo $x_i$ làm khóa thứ nhất và $y_i$ làm khóa thứ hai, rồi xây dựng một `multiset` lấy $y_i$ làm khóa. Với mỗi vị trí $i$, thực hiện các thao tác sau:

1.  Xóa khỏi tập tất cả các điểm thỏa mãn $x_i - x_j \ge d$. Chúng sẽ không còn đóng góp cho đáp án.
2.  Với tất cả các điểm trong tập thỏa mãn $\lvert y_i - y_j \rvert < d$, tính khoảng cách giữa chúng và $p_i$.
3.  Chèn $p_i$ vào tập.

Vì mỗi điểm được chèn và xóa nhiều nhất một lần, độ phức tạp thời gian cho phần chèn và xóa điểm là $O(n \log n)$. Phần tính đáp án có chứng minh độ phức tạp tương tự như trong thuật toán chia để trị; người đọc có thể tự thử chứng minh.

??? example "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/geometry/code/nearest-points/nearest-points_2.cpp"
    ```

## Cách làm kỳ vọng tuyến tính

Ngoài các cách làm có độ phức tạp thời gian $O(n \log n)$ đã nêu, còn có một thuật toán có độ phức tạp **kỳ vọng** là $O(n)$.

Trước hết, [xáo trộn ngẫu nhiên](../misc/random.md#shuffle) các điểm. Duy trì đáp án của tập điểm tiền tố. Xét việc từ đáp án của $i - 1$ điểm đầu tiên suy ra đáp án khi thêm điểm thứ $i$.

Gọi khoảng cách của cặp điểm gần nhất trong $i - 1$ điểm đầu tiên là $s$. Chia mặt phẳng thành các ô lưới có cạnh dài $s$, lưu các điểm trong từng ô lưới bằng [bảng băm](../ds/hash.md), rồi kiểm tra tất cả các điểm trong chín ô lưới xung quanh ô chứa điểm thứ $i$ và cập nhật đáp án. Lưu ý rằng số điểm cần kiểm tra là $O(1)$, vì khoảng cách của cặp điểm gần nhất trong $i - 1$ điểm đầu tiên là $s$, nên mỗi ô lưới chứa không quá $4$ điểm.

Nếu trong quá trình này đáp án được cập nhật, xây dựng lại lưới; ngược lại thì không xây dựng lại. Trong $i$ điểm đầu tiên, xác suất cặp điểm gần nhất chứa điểm $i$ là $O\left(\frac{1}{i}\right)$, còn chi phí xây dựng lại lưới là $O(i)$. Vì vậy, chi phí kỳ vọng cho điểm thứ $i$ là $O(1)$. Do đó, với $n$ điểm, thuật toán này có độ phức tạp kỳ vọng $O(n)$.

## Bài tập

-   [UVa 10245 "Bài toán cặp gần nhất" \[độ khó: thấp\]](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1186)
-   [SPOJ #8725 CLOPPAIR "Cặp điểm gần nhất" \[độ khó: thấp\]](https://www.spoj.com/problems/CLOPPAIR/)
-   [Codeforces Team Olympiad Saratov - 2011 "Lượng nhỏ nhất" \[độ khó: trung bình\]](http://codeforces.com/contest/120/problem/J)
-   [SPOJ #7029 CLOSEST "Bộ ba gần nhất" \[độ khó: trung bình\]](https://www.spoj.com/problems/CLOSEST/)
-   [Google Code Jam 2009 Final "Chu vi nhỏ nhất" \[độ khó: trung bình\]](https://github.com/google/coding-competitions-archive/blob/main/codejam/2009/world_finals/min_perimeter/statement.pdf)

## Tài liệu tham khảo và đọc thêm

**Phần thuật toán chia để trị trong trang này chủ yếu được dịch từ bài viết [Нахождение пары ближайших точек](http://e-maxx.ru/algo/nearest_points) và bản dịch tiếng Anh của nó, [Finding the nearest pair of points](https://github.com/e-maxx-eng/e-maxx-eng/blob/master/src/geometry/nearest_points.md). Phiên bản tiếng Nga được cấp phép theo Public Domain + Leave a Link; phiên bản tiếng Anh được cấp phép theo CC-BY-SA 4.0.**

[Chuyên mục Zhihu: hình học tính toán - bài toán cặp điểm gần nhất](https://zhuanlan.zhihu.com/p/74905629)
