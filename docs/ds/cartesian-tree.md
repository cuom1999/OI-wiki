author: sshwy, zhouyuyang2002, StudyingFather, Ir1d, ouuan, Enter-tainer

## Giới thiệu

Cây Descartes là một loại cây nhị phân, trong đó mỗi nút gồm một cặp khóa-giá trị $(k,w)$. Ta yêu cầu $k$ thỏa tính chất của cây tìm kiếm nhị phân (BST), còn $w$ thỏa tính chất heap. Nếu các khóa $k,w$ của cây Descartes đã được xác định, đồng thời các $k$ đôi một khác nhau và các $w$ cũng đôi một khác nhau, thì cấu trúc của cây Descartes này là duy nhất. Ví dụ như hình sau:

![Ví dụ cây Descartes](./images/cartesian-tree1.png)

(Hình lấy từ Wikipedia)

Cây Descartes ở trên tương ứng với việc xem giá trị phần tử của mảng là khóa $w$, còn chỉ số mảng là khóa $k$. Có thể thấy khóa $k$ của cây này thỏa tính chất cây tìm kiếm nhị phân, còn khóa $w$ thỏa tính chất heap nhỏ (min-heap). Đồng thời, theo tính chất của cây tìm kiếm nhị phân, ta thấy cây Descartes đặc biệt này có đặc điểm: các chỉ số nằm trong một cây con tạo thành một đoạn liên tiếp.

Khi dùng cây Descartes trong thi đấu, ta thường lấy chỉ số mảng làm khóa $k$ trong cặp khóa-giá trị, và chỉ số mảng $k$ thỏa tính chất cây tìm kiếm nhị phân.

Trong phần sau, khi dùng $k,w$, mặc định $k$ thỏa tính chất cây tìm kiếm nhị phân và $w$ thỏa tính chất heap.

## Dựng cây Descartes bằng ngăn xếp đơn điệu

### Quy trình

Xét việc lần lượt chèn các phần tử vào cây Descartes hiện tại theo thứ tự tăng dần của $k$.

Với một cây Descartes, định nghĩa "chuỗi phải" là chuỗi thu được bằng cách bắt đầu từ nút gốc rồi liên tục đi theo con phải cho đến một nút lá. Sau khi chèn một nút, nút đó chắc chắn nằm trên chuỗi phải. Vì ta chèn theo thứ tự tăng dần của $k$, vốn là khóa thỏa tính chất cây tìm kiếm nhị phân, nên nút mới chèn chắc chắn nằm ở **đầu mút phải** của cây. Nút này không thể là con trái và cũng không có con phải.

Do đó ta thực hiện quy trình sau: so sánh $w$ của các nút trên chuỗi phải với nút hiện tại $u$ từ dưới lên. Nếu tìm được một nút $x$ trên chuỗi phải sao cho $w_x<w_u$, ta gắn $u$ làm con phải của $x$, còn cây con phải ban đầu của $x$ trở thành cây con trái của $u$.

Phần được khoanh đỏ trong hình là chuỗi phải mà ta luôn duy trì:

![Chuỗi phải khi dựng cây Descartes](./images/cartesian-tree2.png)

Rõ ràng mỗi số nhiều nhất chỉ vào và rời chuỗi phải một lần (nói cách khác, thời gian một điểm tồn tại trên chuỗi phải là một khoảng liên tục). Quy trình này có thể được duy trì bằng ngăn xếp đơn điệu: ngăn xếp lưu các nút trên chuỗi phải của cây Descartes hiện tại. Khi một điểm không còn nằm trên chuỗi phải nữa, ta bật nó khỏi ngăn xếp. Như vậy mỗi điểm nhiều nhất vào và ra một lần, nên độ phức tạp là $O(n)$.

???+ note "Cây Descartes và Treap"
    Thực ra Treap là một dạng cây Descartes, chỉ khác ở chỗ giá trị $w$ trong Treap hoàn toàn ngẫu nhiên. Treap có thuật toán dựng tuyến tính; nếu sắp xếp trước các khóa $k$, ta có thể dùng thuật toán ngăn xếp đơn điệu ở trên để hoàn thành quá trình dựng cây, chỉ là cách này hiếm khi được sử dụng.

### Cài đặt C++

```cpp
// stk duy trì chỉ số trong dãy ứng với các nút của cây Descartes
for (int i = 1; i <= n; i++) {
  int k = top;  // top là đỉnh ngăn xếp trước thao tác, k là đỉnh hiện tại
  while (k > 0 && w[stk[k]] > w[i]) k--;  // duy trì các nút trên chuỗi phải
  if (k) rs[stk[k]] = i;  // con phải của phần tử ở đỉnh ngăn xếp := phần tử hiện tại
  if (k < top) ls[i] = stk[k + 1];  // con trái của phần tử hiện tại := phần tử vừa bị bật ra trước đó
  stk[++k] = i;                     // đưa phần tử hiện tại vào ngăn xếp
  top = k;
}
```

## Bài tập ví dụ

???+ note "[HDU 1506. Largest Rectangle in a Histogram](https://acm.hdu.edu.cn/showproblem.php?pid=1506)"
    Có $n$ vị trí, chiều cao tại mỗi vị trí là $h_i$; hãy tìm hình chữ nhật con có diện tích lớn nhất. Như hình sau:

    ![Ví dụ hình chữ nhật lớn nhất trong histogram](./images/cartesian-tree3.png)

    Phần tô bóng chính là hình chữ nhật con lớn nhất trong hình.

??? note "Ý tưởng giải"
    Cụ thể, ta dùng chỉ số làm khóa $k$, dùng $h_i$ làm khóa $w$ thỏa tính chất heap nhỏ, rồi dựng một cây Descartes của các cặp $(i,h_i)$.

    Khi đó, ta duyệt từng nút $u$ và lấy $w_u$ (tức chiều cao $h$ của nút $u$) làm chiều cao của hình chữ nhật con lớn nhất tương ứng. Vì cây Descartes đã dựng thỏa tính chất heap nhỏ, mọi nút trong cây con của $u$ đều có chiều cao lớn hơn hoặc bằng $u$. Mặt khác, ta đã biết các chỉ số trong cây con của $u$ tạo thành một đoạn liên tiếp. Vì vậy, chỉ cần biết kích thước cây con là có thể tính diện tích hình chữ nhật con lớn nhất của đoạn này. Dùng giá trị tính được từ từng điểm để cập nhật đáp án. Rõ ràng việc này có thể hoàn thành bằng một lần DFS, nên độ phức tạp là $O(n)$.

??? note "Cài đặt tham khảo"
    ```cpp
    --8<-- "docs/ds/code/cartesian-tree/cartesian-tree_1.cpp"
    ```

## Tài liệu tham khảo

[Cây Descartes - Wikipedia](https://en.wikipedia.org/wiki/Cartesian_tree)
