author: abc1763613206, cesonic, Ir1d, MingqiHuang, xinchengo, xiaofu-15191, hsefz-ChenJunJie

## Giới thiệu

Thuật toán theo kinh nghiệm là gì?

Thuật toán theo kinh nghiệm là cách tối ưu một số thuật toán dựa trên kinh nghiệm và trực giác của con người.

Ví dụ thường gặp nhất là gộp theo kinh nghiệm trong DSU. Mã như sau:

```cpp
void merge(int x, int y) {
  int xx = find(x), yy = find(y);
  if (size[xx] < size[yy]) swap(xx, yy);
  fa[yy] = xx;
  size[xx] += size[yy];
}
```

Trong đoạn mã này, với hai tập có kích thước khác nhau, tập nhỏ được gộp vào tập lớn, thay vì gộp tập lớn vào tập nhỏ.

Vì sao lại làm vậy? Trong trường hợp thông thường, kích thước của tập có thể được xem như chiều cao của tập. Việc gộp cây có chiều cao nhỏ vào cây có chiều cao lớn giúp thao tác tìm cha nhanh hơn.

Cho cây có chiều cao nhỏ trở thành cây con của cây có chiều cao lớn hơn là một cách tối ưu gọi là thuật toán gộp theo kinh nghiệm.

## Nội dung thuật toán

Gộp theo kinh nghiệm trên cây, hay DSU on tree, là một thuật toán cho một số bài toán ngoại tuyến trên cây. Nó có tốc độ không kém đa số thuật toán khác, đồng thời dễ hiểu và dễ cài đặt hơn.

Xét bài toán sau: [Đếm số màu trên cây](https://www.luogu.com.cn/problem/U41492).

???+ note "Bài toán dẫn nhập"
    Cho một cây có $n$ đỉnh, gốc là $1$. Màu của đỉnh $u$ là $c_u$. Với mỗi đỉnh $u$, trả lời trong cây con gốc $u$ có tất cả bao nhiêu màu khác nhau.
    
    $n\le 2\times 10^5$.

![Ví dụ cây có màu cho bài toán đếm số màu trên cây con](./images/dsu-on-tree-1.svg)

Với dạng bài này, nhiều lời giải thường dùng các cấu trúc dữ liệu nặng như cây lồng cây. Nếu có thể xử lý ngoại tuyến, liệu có cách nào đơn giản hơn không?

## Quy trình

Vì bài toán cho phép xử lý ngoại tuyến, có thể nghĩ đến việc tiền xử lý rồi xuất mỗi đáp án trong $O(1)$.

Nếu tiền xử lý trực tiếp bằng vét cạn, độ phức tạp thời gian là $O(n^2)$: với mỗi đỉnh, duyệt các đỉnh trong cây con của nó. Mỗi lần duyệt có thể cùng bậc với $n$, và có $n$ đỉnh, nên tổng độ phức tạp là $O(n^2)$.

Đáp án của mỗi đỉnh được xác định bởi các cây con của nó và chính nó. Có thể tận dụng tính chất này để xử lý bài toán.

Trước hết, tiền xử lý kích thước cây con của mỗi đỉnh và con nặng của nó. Giống như trong phân rã nặng-nhẹ, con nặng là đỉnh con có cây con chứa nhiều đỉnh nhất. Quá trình này có thể hoàn thành trong $O(n)$.

Dùng $cnt_i$ để biểu diễn số lần xuất hiện của màu $i$, và $ans_u$ để biểu diễn đáp án của đỉnh $u$.

Khi duyệt một đỉnh $u$, thực hiện theo các bước sau:

1.  Trước tiên duyệt các con nhẹ, tức các con không nặng, của $u$ và tính đáp án, nhưng **không giữ lại ảnh hưởng của lần duyệt đó lên mảng $cnt$**.
2.  Duyệt con nặng của nó và **giữ lại ảnh hưởng của con nặng lên mảng $cnt$**.
3.  Duyệt lại các đỉnh trong cây con của các con nhẹ của $u$, thêm đóng góp của các đỉnh này để thu được đáp án của $u$.

![Quy trình xử lý cây con nhẹ và cây con nặng trong DSU on tree](./images/dsu-on-tree-2.svg)

Hình trên là một ví dụ.

Bằng cách này, đối với một đỉnh, cây con nặng được duyệt một lần và các cây con không nặng được duyệt hai lần; đây là cách có lợi nhất.

Sau khi thực hiện quy trình này, thu được đáp án cho tất cả các cây con của đỉnh đó.

Vì sao không gộp bước đầu tiên và bước thứ ba? Vì mảng $cnt$ không thể được dùng lại theo cách đó, nếu không dung lượng bộ nhớ sẽ quá lớn. Thuật toán cần hoàn thành trong không gian $O(n)$.

Nếu một đỉnh $u$ được duyệt $x$ lần, thì con nặng của nó cũng được duyệt $x$ lần, còn các con nhẹ, nếu có, sẽ được duyệt $2x$ lần.

Lưu ý rằng ngoài con nặng, sau mỗi lần duyệt cần xóa ảnh hưởng trong $cnt$.

## Chứng minh

Định nghĩa cạnh nặng và cạnh nhẹ giống như trong phân rã nặng-nhẹ: cạnh nối tới con nặng là cạnh nặng, các cạnh còn lại là cạnh nhẹ. Với một cây có $n$ đỉnh, định nghĩa về con nặng và cạnh nặng có thể xem trong hình dưới đây.

Số cạnh nhẹ trên đường đi từ gốc đến bất kỳ đỉnh nào trên cây không vượt quá $\log n$. Giả sử từ gốc đến đỉnh đó có $x$ cạnh nhẹ và kích thước cây con của đỉnh đó là $y$. Cây con của đỉnh con được nối bởi một cạnh nhẹ có kích thước nhỏ hơn một nửa kích thước cây con của cha, vì nếu lớn hơn một nửa thì nó sẽ không phải là cạnh nhẹ. Do đó $y<n/2^x$, suy ra $n>2^x$, nên $x<\log n$.

Ngoài ra, nếu một đỉnh là con nặng của cha nó, thì cây con của nó là lớn nhất trong các cây con của anh em nó. Vì vậy, khi tính đáp án, mọi đỉnh cha nối bằng cạnh nặng trên đường từ một đỉnh bất kỳ lên gốc sẽ không duyệt tới đỉnh đó. Do đó số lần một đỉnh được duyệt bằng số cạnh nhẹ trên đường từ nó đến gốc $+1$, trong đó cộng thêm $1$ vì bản thân đỉnh đó cũng cần được duyệt. Vậy số lần một đỉnh được duyệt là $\log n+1$, và tổng độ phức tạp thời gian là $O(n(\log n+1))=O(n\log n)$. Việc xuất đáp án tốn $O(m)$.

![Cạnh nặng và con nặng trong chứng minh độ phức tạp DSU on tree](./images/dsu-on-tree-3.svg)

*Các cạnh được tô đậm trong hình là cạnh nặng; đỉnh con mà cạnh nặng nối tới là con nặng.*

## Tối ưu

Trong phần chứng minh đã nhắc đến việc DSU on tree dùng khái niệm con nặng và con nhẹ trong phân rã nặng-nhẹ để tăng tốc quá trình gộp. Vì vậy, cũng có thể trực tiếp dùng thứ tự DFS thu được từ phân rã nặng-nhẹ, chuyển đệ quy thành lặp để tiếp tục tối ưu hằng số của DSU on tree.

Bản thân thứ tự DFS có tính chất sau: cây con của một đỉnh luôn là một đoạn liên tiếp trên thứ tự DFS. Vì vậy, có thể duyệt mảng thứ tự DFS theo chiều ngược lại. Cách này bảo đảm rằng khi duyệt tới một đỉnh, các đỉnh khác trong cây con của nó đều đã được xử lý.

Thứ tự DFS thu được từ phân rã nặng-nhẹ còn có một tính chất tốt: mỗi chuỗi nặng luôn liên tiếp trên thứ tự DFS. Do đó, khi duyệt các đỉnh theo thứ tự DFS ngược, với đỉnh ở đầu một chuỗi nặng, đỉnh được duyệt tiếp theo không phải là cha của nó, nên cần xóa ảnh hưởng của nó. Ngoài trường hợp đó, với các đỉnh không nằm ở đầu chuỗi nặng, đỉnh được duyệt ngay trước đó hoặc là con nặng của chính nó, hoặc là một đỉnh thuộc nhánh khác đã được xóa ảnh hưởng, nên có thể trực tiếp kế thừa ảnh hưởng đó. Trên cơ sở này, tiếp tục dùng thứ tự DFS để thống kê nhanh ảnh hưởng của tất cả các con nhẹ và ghi lại đáp án.

Quy trình trên được gọi là cài đặt không đệ quy hoặc cài đặt lặp của DSU on tree, cũng được gọi là cài đặt DSU on tree bằng thứ tự DFS. So với cài đặt đệ quy ban đầu, nó giảm chi phí thời gian và không gian của các lời gọi hàm đệ quy, đem lại tối ưu hằng số đáng kể, **đặc biệt có lợi rõ rệt về không gian ngăn xếp khi xử lý các cây chứa nhiều cấu trúc dạng chuỗi.**

## Cài đặt

??? example "Cài đặt tham khảo"
    === "Cài đặt đệ quy"
        ```cpp
        --8<-- "docs/graph/code/dsu-on-tree/dsu-on-tree_1.cpp"
        ```
    
    === "Cài đặt không đệ quy"
        ```cpp
        --8<-- "docs/graph/code/dsu-on-tree/dsu-on-tree_2.cpp"
        ```

## Ứng dụng

1.  Một số bài mà lời giải chuẩn do người ra đề đặt ra là DSU on tree

    Ví dụ [CF741D](http://codeforces.com/problemset/problem/741/D). Cho một cây, trọng số của mỗi đỉnh là một chữ cái từ 'a' đến 'v'. Mỗi truy vấn yêu cầu tìm trong một cây con một đường đi sao cho sau khi sắp xếp các ký tự trên đường đi đó, chúng tạo thành một xâu đối xứng.

    Vì xét xâu sau khi sắp xếp có thể trở thành xâu đối xứng, nên một ký tự xuất hiện hai lần tương đương với không xuất hiện. Nói cách khác, đường đi này thỏa mãn điều kiện **nhiều nhất một ký tự xuất hiện số lần lẻ**.

    Cách làm thông thường là DFS từ mỗi đỉnh. Mỗi khi đi tới một đỉnh, vét cạn tất cả chữ cái để tìm các đường đi mà sau khi XOR với trạng thái hiện tại có số bit bằng $1$ lớn hơn $1$, rồi lấy giá trị dài nhất. Cách này có độ phức tạp $O(n^2\log n)$, và có thể dùng DSU on tree để tối ưu xuống $O(n\log^2n)$. Cách làm cụ thể có thể tham khảo phần đọc thêm bên dưới.

2.  Các bài có thể dùng DSU để xử lý linh hoạt

    Có thể lấy điểm một phần ở một số bài vốn dùng cây lồng cây, khi không có thao tác cập nhật. Hơn nữa, độ phức tạp của DSU tốt hơn Mo trên cây với $O(n\sqrt{m})$.

## Bài tập

[CF600E Lomsat gelral](http://codeforces.com/problemset/problem/600/E)

Tóm tắt đề bài: các đỉnh của cây có màu. Một màu chiếm lĩnh một cây con khi và chỉ khi không có màu nào khác xuất hiện trong cây con đó nhiều lần hơn nó. Tính tổng tất cả các màu chiếm lĩnh từng cây con.

[UOJ284 Gà chơi game vui vẻ](https://uoj.ac/problem/284)

[CF1709E XOR Tree](https://codeforces.com/contest/1709/problem/E)

## Tài liệu tham khảo và đọc thêm

[DSU on tree do tác giả CF741D giới thiệu](http://codeforces.com/blog/entry/44351)

[Lời giải của tác giả này](http://codeforces.com/blog/entry/48871)
