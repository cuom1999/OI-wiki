## Định nghĩa

DAG là [đồ thị có hướng không chu trình](../graph/dag.md). Một số quan hệ nhị phân trong bài toán thực tế có thể được mô hình hóa bằng DAG, từ đó chuyển bài toán thành bài toán đường đi dài nhất (hoặc ngắn nhất) trên DAG.

## Giải thích

Lấy bài sau làm ví dụ để phân tích quá trình mô hình hóa bằng DAG.

???+ note "Bài ví dụ [UVa 437 The Tower of Babylon](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=378)"
    Có $n (n\leqslant 30)$ loại khối hộp, biết độ dài ba cạnh của mỗi loại, và số lượng mỗi loại là vô hạn. Hãy chọn một số khối để xếp thành một tháp cao nhất có thể (mỗi khối có thể tự chọn một cạnh làm chiều cao), sao cho chiều dài và chiều rộng đáy của mỗi khối đều nhỏ hơn nghiêm ngặt so với khối nằm ngay bên dưới. Tính chiều cao lớn nhất của tháp.

## Quy trình

### Xây dựng DAG

Vì chiều dài và chiều rộng đáy của mỗi khối phải nhỏ hơn nghiêm ngặt so với khối bên dưới, ta có thể dùng quan hệ này làm cơ sở dựng đồ thị. Khi đó bài toán được chuyển thành bài toán đường đi dài nhất.

Nói cách khác, nếu khối $j$ có thể đặt lên khối $i$, thì giữa $i$ và $j$ có một cạnh $(i,j)$, và trọng số cạnh chính là chiều cao được chọn của khối $j$.

Một vấn đề khác là mỗi khối có ba cách chọn chiều cao. Dựng đồ thị thế nào cho phù hợp?

Ta có thể tách mỗi khối thành ba cách xếp, tức là xem một khối ban đầu như ba khối khác nhau, mỗi khối sau khi tách chọn một cạnh khác nhau làm chiều cao.

Điểm xuất phát ban đầu là mặt đất, có đáy coi như vô hạn, nên mặt đất có thể đi tới mọi khối. Khi viết chương trình, không cần biểu diễn riêng giá trị vô hạn này.

Giả sử có hai khối với ba cạnh lần lượt là $31,41,59$ và $33,83,27$, thì DAG tương ứng như hình dưới.

![](./images/dag-babylon.png)

Khung nét liền màu xanh biểu diễn nhóm khối thu được từ cùng một khối ban đầu. Độ dài hai cạnh đáy được viết bằng $\{\}$ vì sau khi đã chọn chiều cao, thứ tự hai cạnh đáy không còn quan trọng.

Khung nét đứt màu vàng biểu diễn phần bị tính lặp; có thể dùng [tìm kiếm có nhớ](./memo.md) để tránh lặp lại.

### Chuyển trạng thái

Bài yêu cầu chiều cao lớn nhất của tháp, và ta đã chuyển nó thành bài toán đường đi dài nhất. Điểm bắt đầu là mặt đất như đã nói ở trên; còn điểm kết thúc cũng được xác định tự nhiên: đó là khi trên một khối nào đó không thể đặt thêm khối nào khác.

Giờ xét phương trình chuyển trạng thái.

Đặt $d(i,r)$ là chiều cao lớn nhất khi khối thứ $i$ nằm ở dưới cùng và dùng cách xếp thứ $r$. Khi đó có phương trình chuyển:

$$
d(i, r) = \max\left\{d(j, r') + h\right\}
$$

Trong đó $j$ chạy qua mọi khối có thể đặt lên khối $i$ khi $i$ dùng cách xếp $r$; $r'$ là cách đặt tương ứng của $j$; $h$ là chiều cao của khối $i$ khi dùng cách xếp thứ $r$.

??? note "Cài đặt"
    ```cpp
    --8<-- "docs/dp/code/dag/dag_1.cpp"
    ```
