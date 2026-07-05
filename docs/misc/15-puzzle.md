## Giới thiệu

**15-puzzle** (tiếng Anh: 15-puzzle, còn gọi là Gem Puzzle, Boss Puzzle, Game of 15, Mystic Square, N-puzzle, v.v.) là một trò chơi trượt ô (tiếng Anh: sliding puzzle). Bàn trượt có kích thước $4\times 4$ ô vuông, trong đó 15 vị trí chứa các ô được đánh số và xáo trộn, vị trí còn lại để trống. Các ô cùng hàng hoặc cùng cột với ô trống có thể di chuyển bằng cách trượt theo chiều ngang hoặc chiều dọc. Mục tiêu của trò chơi là sắp xếp các ô theo thứ tự số.

15-puzzle thường còn được gọi là **n-puzzle**, trong đó số $n$ chỉ tổng số ô vuông trong bàn. Các biến thể kích thước khác của 15-puzzle cũng dùng tên tương tự, ví dụ $8$-puzzle chỉ trò chơi có $8$ ô đặt trong bàn $3\times3$. Tuy vậy, $15$-puzzle cũng có thể được gọi là $16$-puzzle, trong đó 16 chỉ sức chứa của bàn. Các bài toán mở rộng của nó đôi khi cũng bao gồm bàn trượt kích thước $n \times m$.

15-puzzle là một bài toán kinh điển trong mô hình hóa bằng [thuật toán heuristic](../search/heuristic.md). Dạng thường gặp của bài toán sử dụng [khoảng cách Manhattan](../geometry/distance.md#khoảng-cách-manhattan) và số ô đặt sai vị trí; cả hai đều là heuristic chấp nhận được (tiếng Anh: admissible heuristic), nghĩa là chúng không bao giờ đánh giá quá cao số bước di chuyển còn lại, qua đó bảo đảm tính tối ưu của một số thuật toán tìm kiếm, chẳng hạn [thuật toán A \*](../search/astar.md).

???+ note "Ghi chú"
    **Trò chơi trượt ô** là một loại câu đố trí tuệ trong đó người chơi trượt các ô trên mặt phẳng để tạo thành một cách sắp xếp nhất định. Các trò chơi trượt ô thường gặp gồm câu đố số, Klotski và Rush Hour. Trong đó 15-puzzle là một trong những trò chơi trượt ô lâu đời nhất, do Noyes Chapman phát minh và rất thịnh hành vào thập niên 1880. Khác với các câu đố kiểu tour khác, trò chơi trượt ô cấm mọi ô rời khỏi bàn, và đặc điểm này phân biệt nó với các câu đố kiểu sắp xếp lại.

## Định nghĩa

Cho một bàn $4 \times 4$, trong đó $15$ ô được sắp xếp tùy ý. Ta cần sắp xếp nó theo thứ tự số như hình dưới. Quy tắc di chuyển là mỗi lần chỉ được hoán đổi ô trống với một ô kề nó. Các câu hỏi thường gặp là tìm số bước ít nhất để giải được bài toán, tính số ô sai vị trí, hoặc xác định liệu có thể đạt tới trạng thái có thứ tự cuối cùng hay không.

![](./images/15puzzle-1.svg)

## Chứng minh tính giải được

Johnson & Story (1879) đã chứng minh rằng nếu $m$ và $n$ đều ít nhất là $2$, thì mệnh đề đảo đúng với bàn kích thước $m\times n$: bằng quy nạp theo $m$ và $n$ bắt đầu từ $m=n=2$, mọi hoán vị chẵn đều giải được. Archer (1999) đưa ra một chứng minh khác, dựa trên các lớp tương đương được định nghĩa bằng đường đi Hamilton.

## Thuật toán

Tìm một nghiệm cho trò chơi trượt số tương đối dễ, nhưng tìm **nghiệm tối ưu** là một bài toán **NP-khó** (NP-hard). Nghiệm tối ưu của 15-Puzzle có nhiều nhất 80 bước; còn nghiệm tối ưu của 8-Puzzle có nhiều nhất 31 bước.

N-Puzzle hỗ trợ các thuật toán tìm kiếm trên đồ thị thường gặp như tìm kiếm theo chiều rộng và tìm kiếm theo chiều sâu. Tương tự, ta cũng có thể dùng thuật toán [tìm kiếm A \*](../search/astar.md) để tìm nghiệm tối ưu. Hàm heuristic $h(n)$ có thể là:

-   Số ô đặt sai vị trí.
-   Tổng khoảng cách Euclid từ mọi ô đặt sai đến vị trí đích tương ứng.
-   Tổng khoảng cách Manhattan từ mọi ô đặt sai đến vị trí đích tương ứng.

### Lý thuyết nhóm

Vì các cấu hình của trò chơi trượt số 15 ô có thể được sinh bởi các "3-cycle" (tiếng Anh: 3-cycles), có thể chứng minh rằng trò chơi trượt số 15 ô có thể được biểu diễn bằng nhóm luân phiên $A_{15}$. Trên thực tế, mọi trò chơi trượt số dùng $2\times k-1$ ô vuông cùng diện tích đều có thể được biểu diễn bằng nhóm luân phiên $A_{2k-1}$.

## Bài tập

-   [N Puzzle](https://www.hackerrank.com/challenges/n-puzzle)
-   [A. Amity Assessment](https://codeforces.com/problemset/problem/645/A)
-   [Sliding Puzzle](https://leetcode.com/problems/sliding-puzzle/)
-   [POJ 1077 - Eight](http://poj.org/problem?id=1077)

## Tài liệu tham khảo và đọc thêm

1.  [15 puzzle - Wikipedia](https://en.wikipedia.org/wiki/15_puzzle)
2.  jrdnjacobson, [How to Solve the 15 Puzzle - instructables](https://www.instructables.com/How-To-Solve-The-15-Puzzle/)
3.  Korf, R. E. (2000), ["Recent Progress in the Design and Analysis of Admissible Heuristic Functions"](https://www.researchgate.net/publication/2604757_Recent_Progress_in_the_Design_and_Analysis_of_Admissible_Heuristic_Functions), in Choueiry, B. Y.; Walsh, T. (eds.), Abstraction, Reformulation, and Approximation (PDF), SARA 2000. Lecture Notes in Computer Science, vol. 1864, Springer, Berlin, Heidelberg, pp. 45–55, doi:10.1007/3-540-44914-0\_3, ISBN 978-3-540-67839-7, retrieved 2010-04-26
4.  [Welcome to N-Puzzle - web demo](https://tristanpenman.com/demos/n-puzzle/)
