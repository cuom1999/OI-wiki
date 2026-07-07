author: Persdre

Kiến thức chuẩn bị: [clique](./concept.md)

## Dẫn nhập

Trong khoa học máy tính, bài toán clique là bài toán tìm một clique trong đồ thị đã cho, tức một tập con các đỉnh mà mọi cặp đỉnh đều kề nhau, còn được gọi là đồ thị con đầy đủ.

Bài toán clique cũng xuất hiện trong đời sống thực tế. Ví dụ, xét một mạng xã hội trong đó các đỉnh của đồ thị biểu thị người dùng, còn cạnh của đồ thị biểu thị hai người dùng được nối bởi cạnh đó quen biết nhau. Khi tìm được một clique, có thể xác định một nhóm người đôi một quen biết nhau.

Nếu muốn tìm nhóm người quen biết lẫn nhau có kích thước lớn nhất trong mạng xã hội này, cần tìm clique có kích thước lớn nhất.

Khái niệm [clique cực đại](./concept.md) đã được giới thiệu trước đó. Clique lớn nhất là clique cực đại có số đỉnh nhiều nhất.

## Giải thích

Ý tưởng là dùng đệ quy và quay lui, lưu các đỉnh bằng một danh sách; mỗi lần thêm một đỉnh mới vào thì kiểm tra xem các đỉnh này có còn tạo thành một clique hay không. Nếu sau khi thêm đỉnh này vào mà không còn là clique, thuật toán quay lui về trạng thái còn thỏa mãn điều kiện và thử thêm đỉnh khác.

Lý do sử dụng chiến lược quay lui là không thể biết trước một đỉnh $v$ nào đó **cuối cùng** có phải là thành viên của clique lớn nhất hay không. Nếu thuật toán đệ quy chọn $v$ làm thành viên của clique lớn nhất nhưng không tìm được clique lớn nhất, thì cần quay lui và tìm nghiệm không chứa $v$ trong clique lớn nhất.

## Quy trình

Thuật toán **Bron–Kerbosch** là một cách hiện thực hiệu quả cho ý tưởng này. Dạng cơ bản của thuật toán là tìm kiếm đệ quy trên ba tập $R$, $P$, $X$. Các bước như sau:

1.  Khởi tạo hai tập $R,X$ là rỗng, còn tập $P$ là tập tất cả các đỉnh trong đồ thị.
2.  Mỗi lần lấy một đỉnh $v$ từ tập $P$; khi trong tập không còn đỉnh nào, có hai trường hợp:
    1.  Tập $R$ là một clique cực đại, khi đó tập $X$ rỗng
    2.  $R$ không tạo ra clique cực đại mới, khi đó quay lui
3.  Với mỗi đỉnh $v$ lấy từ tập $P$, xử lý như sau:
    1.  Thêm đỉnh $v$ vào tập $R$, rồi đệ quy trên các tập $R,P,X$
    2.  Xóa đỉnh $v$ khỏi tập $P$, và thêm đỉnh $v$ vào tập $X$
    3.  Nếu cả hai tập $P,X$ đều rỗng, thì tập $R$ chính là một clique cực đại

Phương pháp này còn có thể tiếp tục tối ưu. Để tiết kiệm thời gian và giúp thuật toán quay lui nhanh hơn, có thể tìm kiếm bằng cách chọn đỉnh chốt (pivot vertex). Một hướng tối ưu khác là sắp xếp tất cả các đỉnh ngay từ đầu, rồi khi liệt kê thì đi theo thứ tự chỉ số để tránh lặp.

## Hiện thực

### Mã giả

```text
R := {}
P := node set of G
X := {}

BronKerbosch1(R, P, X):
    nếu P và X đều rỗng:
        báo cáo R là một clique cực đại
    với mỗi đỉnh v trong P:
        BronKerbosch1(R ⋃ {v}, P ⋂ N(v), X ⋂ N(v))
        P := P \ {v}
        X := X ⋃ {v}
```

### Hiện thực C++

??? note "Mã hiện thực"
    ```cpp
    --8<-- "docs/graph/code/max-clique/max-clique_1.cpp"
    ```

## Ví dụ

???+ note "[POJ 2989: All Friends](http://poj.org/problem?id=2989)"
    Tóm tắt đề bài: Cho $n$ người, trong đó có $m$ cặp người quen biết nhau. Yêu cầu tính số lượng clique cực đại.

Ý tưởng: Bài toán điển hình, cần dùng thuật toán Bron–Kerbosch.

Mã giả:

```text
 BronKerbosch(All, Some, None):
     nếu Some và None đều rỗng:
        báo cáo All là một clique cực đại // Tất cả các đỉnh đã được chọn, và không còn đỉnh nào cần loại trừ; cộng vào đáp án
     với mỗi đỉnh v trong Some: // Liệt kê từng phần tử trong Some
         BronKerbosch1(All ⋃ {v}, Some ⋂ N(v), None ⋂ N(v))
        // Thêm v vào All; chỉ các đỉnh kề với v mới còn có thể là ứng viên, và trong None cũng chỉ các đỉnh kề với v mới ảnh hưởng đến bước tìm kiếm tiếp theo
         Some := Some - {v} // Đã tìm kiếm xong; xóa khỏi Some và thêm vào None
         None := None ⋃ {v}
```

Để tiết kiệm thời gian và giúp thuật toán quay lui nhanh hơn, có thể tối ưu bằng cách chọn đỉnh chốt (pivot vertex) $v$.

Thuật toán trên có thể tính lặp nhiều clique cực đại đã xét trước đó, rồi sau đó quay lui.

Lấy ba tập $R$, $P$, $X$ đã nhắc ở trên làm ví dụ:

Xét bài toán sau: chọn một đỉnh $u$ trong tập $P\cup X$ để cùng với tập $R$ tạo thành một clique cực đại. Khi dùng $u$ làm chốt, chỉ cần xét các đỉnh trong $P\setminus N(u)$ ($N(u)$ biểu thị các đỉnh kề với $u$).

Nếu sau khi chọn $u$, tiếp tục chọn một đỉnh $v$ kề với $u$ và $v$ cũng có thể được thêm vào clique cực đại, thì chỉ chọn $u$ là đủ. Cách làm này có thể giảm các tính toán lặp lại về sau đối với $v$. Vì vậy chỉ cần nhánh trên các đỉnh trong $P\setminus N(u)$.

Hiện thực C++ sau khi thêm tối ưu hóa:

??? note "Mã hiện thực"
    ```cpp
    --8<-- "docs/graph/code/max-clique/max-clique_2.cpp"
    ```

## Bài tập

-   [ZOJ 1492 Maximum Clique](https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?page=4&problemSetProblemId=91827364991)
-   [POJ 1419 Clique lớn nhất trên đồ thị vô hướng](http://poj.org/problem?id=1419)
-   [POJ 1129 Đài phát thanh](http://poj.org/problem?id=1129)

## Tài liệu tham khảo

-   [Bài toán clique - Wikipedia](https://en.wikipedia.org/wiki/Clique_problem)
-   [Clique cực đại và clique lớn nhất trong đồ thị vô hướng (thuật toán Bron–Kerbosch)](https://blog.csdn.net/yo_bc/article/details/77453478)
-   [Bài toán clique lớn nhất - thuật toán Bron–Kerbosch](https://hallelujahjeff.github.io/2018/04/12/34/)
-   [Bài toán clique lớn nhất](https://www.cnblogs.com/zhj5chengfeng/archive/2013/07/29/3224092.html)
