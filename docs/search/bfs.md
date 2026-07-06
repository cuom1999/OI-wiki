<span id="dẫn-nhập"></span>

## Dẫn nhập

BFS (tìm kiếm theo chiều rộng) là một thuật toán cơ bản trong lý thuyết đồ thị; xem chi tiết ở trang [BFS (đồ thị)](../graph/bfs.md). Trong **thuật toán tìm kiếm**, BFS thường chỉ phương pháp tìm kiếm dùng cấu trúc hàng đợi để mở rộng trạng thái theo từng lớp. Tư tưởng của nó nhất quán với BFS trong lý thuyết đồ thị, và đặc biệt phù hợp để giải các bài toán **đường đi ngắn nhất** hoặc **số bước ít nhất**.

<span id="giải-thích"></span>

## Giải thích

Tư tưởng cốt lõi của BFS là **mở rộng theo từng lớp**: bắt đầu từ trạng thái xuất phát, lần lượt quét các vị trí có thể đi tới theo từng lớp. Khi lần đầu gặp đích, độ dài đường đi lúc đó chính là đường đi ngắn nhất. Cách làm này bảo đảm tính phân lớp và tính tối ưu của quá trình tìm kiếm.

Khi thực thi, BFS bắt đầu từ điểm xuất phát và trước hết thăm tất cả các đỉnh có thể đi tới trực tiếp từ điểm đó; các đỉnh này tạo thành lớp tìm kiếm đầu tiên. Sau đó, thuật toán lấy các đỉnh vừa tìm được làm điểm xuất phát mới, lần lượt thăm các đỉnh kề của chúng để tạo thành lớp thứ hai. Quá trình tiếp tục mở rộng ra ngoài như vậy cho đến khi tìm thấy đỉnh đích hoặc duyệt hết tất cả các đỉnh có thể đi tới. Trong quá trình này, thuật toán dùng hàng đợi và mảng đánh dấu thăm để lần lượt đưa các đỉnh mới phát hiện ở mỗi lớp vào hàng đợi, đồng thời tránh xử lý lặp lại. Nhờ đó, thuật toán xử lý các đỉnh cùng một lớp theo đúng thứ tự phát hiện và tuân thủ chặt chẽ logic "mở rộng theo từng lớp".

BFS rất thích hợp để nhanh chóng giải các bài toán **đường đi ngắn nhất** hoặc **số bước ít nhất**. Khi thuật toán lần đầu gặp mục tiêu ở một lớp nào đó, độ dài đường đi (hay số bước) tương ứng là nhỏ nhất. Lý do là cơ chế "mở rộng theo từng lớp" của BFS bảo đảm mỗi đỉnh được thăm bằng số bước ít nhất có thể: từ điểm xuất phát, thuật toán luôn mở rộng các đường đi ngắn trước, nên không có trường hợp phải đi vòng hoặc thêm bước thừa mới tới đích. Trong nhóm bài toán này, BFS thường hiệu quả hơn DFS.

Tuy vậy, so với DFS, BFS cũng có nhược điểm. Thông thường BFS cần nhiều bộ nhớ hơn, không có quá trình quay lui tự nhiên, và việc cắt tỉa theo độ sâu kém linh hoạt hơn DFS.

<span id="bài-tập-ví-dụ"></span>

## Bài tập ví dụ

???+ example "Bài tập [Luogu B3625 Tìm đường trong mê cung](https://www.luogu.com.cn/problem/B3625)"
    Trong một ma trận mê cung kích thước $n \times m$, ký tự `.` biểu thị ô có thể đi qua, còn `#` biểu thị vật cản. Bắt đầu từ điểm $(1,1)$, mỗi lần có thể đi theo bốn hướng lên, xuống, trái, phải. Hỏi có thể đi tới điểm đích $(n,m)$ hay không.

??? note "Lời giải"
    Khi cài đặt, cần duy trì một hàng đợi để lưu các tọa độ đang chờ xử lý, đồng thời dùng mảng đánh dấu thăm để tránh xử lý lặp. Khi mở rộng một đỉnh, cần thử đi theo bốn hướng lên, xuống, trái, phải; bốn hướng đó lần lượt là $(x, y + 1)$, $(x, y - 1)$, $(x + 1, y)$, $(x - 1, y)$, và được cài đặt bằng mảng hướng trong mã. Cần tránh mở rộng tới vị trí là vật cản.

??? note "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/search/code/bfs/bfs-1.cpp"
    ```

???+ example "Bài tập [Luogu P1135 Thang máy kỳ lạ](https://www.luogu.com.cn/problem/P1135)"
    Có $n$ tầng và một thang máy. Khi thang máy ở tầng thứ $i$, nó có thể đi lên hoặc đi xuống đúng $k_i$ tầng. Nếu tầng sau khi di chuyển không hợp lệ, tức không nằm trong khoảng từ $1$ đến $n$, thao tác tương ứng không thể thực hiện. Hỏi từ tầng $a$ đến tầng $b$ cần ít nhất bao nhiêu lần thao tác thang máy? Nếu không thể đến được, in ra $-1$.

??? note "Lời giải"
    Bài này yêu cầu tính đường đi ngắn nhất, phù hợp với cách giải bằng BFS. Khi cài đặt, hàng đợi cần đồng thời lưu tầng đang chờ xử lý và khoảng cách ngắn nhất từ tầng xuất phát $a$ đến tầng hiện tại; kết hợp với mảng đánh dấu thăm để tránh đưa cùng một phần tử vào hàng đợi nhiều lần. Khi mở rộng một đỉnh $i$, cần xét hai tầng có thể đến là $i + k_i$ và $i - k_i$, đồng thời loại bỏ các tầng không hợp lệ. Khi mở rộng tới một tầng hợp lệ chưa từng đến, cần đưa nó vào hàng đợi và ghi lại khoảng cách ngắn nhất tới tầng đó bằng khoảng cách ngắn nhất tới tầng hiện tại cộng một. Khi lần đầu đến được đỉnh $b$, khoảng cách được ghi lại chính là đáp án cuối cùng.
    
    Trong mã tham khảo, mảng khoảng cách được ghi trực tiếp; dựa vào việc giá trị khoảng cách có bằng giá trị mặc định (tức $-1$) hay không để phân biệt đỉnh chưa được thăm.

??? note "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/search/code/bfs/bfs-2.cpp"
    ```

<span id="bài-tập"></span>

## Bài tập

-   [Luogu P1443 Hành trình của quân mã](https://www.luogu.com.cn/problem/P1443)
-   [Luogu P3956 \[NOIP 2017 Nhóm phổ cập\] Bàn cờ](https://www.luogu.com.cn/problem/P3956)
-   [Luogu P1126 Robot vận chuyển vật nặng](https://www.luogu.com.cn/problem/P1126)
