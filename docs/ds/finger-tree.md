author: isdanni

???+ warning "Chú ý"
    Chương này là nội dung đọc thêm. Trước khi đọc, hãy chắc chắn rằng bạn đã có hiểu biết nhất định về lập trình hàm (Functional Programming).

## Giới thiệu

**Cây ngón tay** (Finger Tree) là một cấu trúc dữ liệu **thuần hàm** do Ralf Hinze và Ross Paterson đề xuất.

## Vì sao cần cây ngón tay

Trong lập trình hàm, danh sách là một kiểu dữ liệu rất phổ biến. Với các thao tác dựa trên dãy, bao gồm thêm và xóa phần tử ở hai đầu (thao tác hàng đợi hai đầu), chèn vào một nút bất kỳ, nối, xóa, tìm một phần tử thỏa điều kiện, và tách dãy thành các dãy con, hầu như mọi ngôn ngữ hàm đều hỗ trợ. Tuy nhiên, các ngôn ngữ này khó thực hiện thêm nhiều thao tác một cách hiệu quả. Ngay cả khi có cách cài đặt tương ứng, chúng thường rất phức tạp và khó dùng trong thực tế.

Finger Tree cung cấp một cấu trúc dữ liệu dãy thuần hàm: nó có thể thực hiện các thao tác như truy cập, thêm vào đầu và cuối dãy trong thời gian hằng số khấu hao (amortized constant time), đồng thời thực hiện phép nối và truy cập ngẫu nhiên trong thời gian lôgarit (logarithmic time). Ngoài các cận tiệm cận tốt về thời gian chạy, cây ngón tay còn rất linh hoạt: khi kết hợp với nhãn monoid ([monoidal tag](https://en.wikipedia.org/wiki/Monoidal_category)) trên các phần tử, cây ngón tay có thể dùng để cài đặt hiệu quả dãy truy cập ngẫu nhiên, dãy có thứ tự, cây khoảng và hàng đợi ưu tiên.

## Cấu trúc cơ bản

Cây ngón tay lưu dữ liệu tại các "ngón tay" (lá) của cây, với thời gian truy cập khấu hao là hằng số. Ngón tay là một điểm có thể truy cập một phần của cấu trúc dữ liệu. Trong ngôn ngữ mệnh lệnh (imperative language), khái niệm này được gọi là con trỏ. Trong cây ngón tay, "ngón tay" là cấu trúc trỏ tới đầu mút của dãy hoặc tới nút lá. Cây ngón tay cũng lưu trong mỗi nút trong kết quả của việc áp dụng một số phép toán kết hợp lên các hậu duệ của nút đó. Dữ liệu được lưu trong các nút trong có thể dùng để cung cấp những chức năng ngoài phạm vi của một cấu trúc dữ liệu dạng cây.

1.  Độ sâu của cây ngón tay được tính từ dưới lên trên.
2.  Cấp thứ nhất của cây ngón tay, tức các nút lá của cây, chỉ chứa giá trị và có độ sâu $0$. Cấp thứ hai có độ sâu $1$. Cấp thứ ba có độ sâu $2$, và cứ tiếp tục như vậy.
3.  Càng gần gốc, các nút càng trỏ tới các cây con sâu hơn của cây ban đầu (trước khi nó trở thành cây ngón tay). Vì vậy, đi xuống dọc theo cây tương ứng với việc đi từ lá tới gốc của cây, ngược với cấu trúc cây điển hình. Để có được cấu trúc này, ta phải bảo đảm rằng cây ban đầu có độ sâu đồng nhất. Khi khai báo đối tượng nút, cần tham số hóa nó bằng kiểu của các nút con. Các nút trên xương sống có độ sâu từ $1$ trở lên trỏ tới các cây; nhờ cách tham số hóa này, chúng có thể được biểu diễn bằng các nút lồng nhau.

### Biến một cây thành cây ngón tay

???+ note "Ghi chú"
    **Cây 2-3** là một cấu trúc dữ liệu dạng cây, trong đó mỗi nút có nút con (nút trong) có hai nút con (nút $2$) và một phần tử dữ liệu, hoặc có ba nút con (nút $3$) và hai phần tử dữ liệu. Cây 2-3 là cây B bậc $3$. Các nút ngoài của cây (nút lá) không có nút con và có một hoặc hai phần tử dữ liệu.

Ta sẽ bắt đầu quá trình này từ một cây 2-3 cân bằng. Để cây ngón tay hoạt động đúng, tất cả các nút lá cần nằm trên cùng một mức. Như hình dưới đây (hình lấy từ bài báo về cây ngón tay):

![](./images/finger-tree-1.png)

Ngón tay là "một cấu trúc cho phép truy cập hiệu quả tới các nút của cây ở gần một vị trí cụ thể". Để tạo cây ngón tay, ta cần đặt các ngón tay ở hai đầu trái và phải của cây, lấy các nút trong ngoài cùng bên trái và ngoài cùng bên phải của cây rồi kéo chúng lên, để phần còn lại của cây treo giữa chúng. Điều này cho ta thời gian truy cập hằng số khấu hao tới các đầu mút của dãy.

![](./images/finger-tree-2.png)

Cấu trúc dữ liệu mới này được gọi là cây ngón tay. Cây ngón tay gồm nhiều tầng (các khung màu xanh bên dưới) phân bố dọc theo xương sống của cây (đường màu nâu):

![](./images/finger-tree-3.png)

```haskell
data FingerTree a = Empty
                  | Single a
                  | Deep (Digit a) (FingerTree (Node a)) (Digit a)

data Digit a = One a | Two a a | Three a a a | Four a a a a
data Node a = Node2 a a | Node3 a a a
```

Các Digit trong ví dụ là các nút có chữ cái. Mỗi danh sách được chia bởi tiền tố hoặc hậu tố của từng nút trên xương sống của cây. Trong cây 2-3 sau khi chuyển đổi, các danh sách Digit ở tầng trên cùng dường như có thể có độ dài hai hoặc ba, còn ở các tầng thấp hơn chỉ có độ dài một hoặc hai. Để một số ứng dụng của cây ngón tay có thể chạy hiệu quả như vậy, cây ngón tay cho phép có từ $1$ tới $4$ cây con ở mỗi cấp. Các Digit của cây ngón tay có thể được chuyển thành một danh sách, chẳng hạn:

```haskell
type Digit a = One a | Two a a | Three a a a | Four a a a a
```

Tầng trên cùng có các phần tử kiểu $a$; tầng tiếp theo có các phần tử kiểu nút $a$, vì đây là các nút nằm giữa xương sống và lá. Điều này thường có nghĩa là tầng thứ $n$ của cây có kiểu phần tử là $Node^{n}$ $a$, hoặc là các cây 2-3 có độ sâu $n$. Vì vậy, một dãy gồm $n$ phần tử được biểu diễn bằng một cây có độ sâu `Θ(log n)`. Phần tử cách đầu mút gần nhất một khoảng $d$ được lưu trong cây ở độ sâu `Θ(log d)`.

### Thao tác hàng đợi hai đầu

Cây ngón tay cũng có thể tạo ra một hàng đợi hai đầu hiệu quả. Dù cấu trúc có tính bền vững (persistent) hay không, mọi thao tác đều cần thời gian `Θ(1)`. Có thể xem nó là một phần mở rộng của hàng đợi hai đầu ẩn[^okasaki1999purely]:

1.  Thay thế cặp bằng các nút 2-3 cung cấp đủ độ linh hoạt để hỗ trợ phép nối hiệu quả. (Để giữ các thao tác hàng đợi hai đầu trong thời gian hằng số, cần mở rộng Digit thành bốn.)
2.  Chú thích các nút trong bằng monoid cho phép tách hiệu quả.

```haskell
data ImplicitDeque a = Empty
                     | Single a
                     | Deep (Digit a) (ImplicitDeque (a, a)) (Digit a)

data Digit a = One a | Two a a | Three a a a
```

## Độ phức tạp thời gian

Cây ngón tay cung cấp truy cập thời gian hằng số khấu hao tới các "ngón tay" (lá) của cây, nơi lưu dữ liệu, đồng thời cung cấp phép nối và tách trong thời gian lôgarit theo kích thước của phần nhỏ hơn. Nó cũng lưu trong mỗi nút trong kết quả của việc áp dụng một số phép toán kết hợp lên các hậu duệ của nút đó. Dữ liệu "tóm tắt" lưu trong các nút trong có thể dùng để cung cấp chức năng của những cấu trúc dữ liệu khác ngoài cây.

| Thao tác                      | Cây ngón tay             | Cây 2-3 có chú thích (annotated 2-3 tree) | Danh sách (list)     | Vector     |
| ----------------------------- | ------------------------ | ----------------------------------------- | -------------------- | ---------- |
| `const`,`snoc`                | $O(1)$                   | $O(\log n)$                               | $O(1)$/$O(n)$        | $O(n)$     |
| `viewl`,`viewr`               | $O(1)$                   | $O(\log n)$                               | $O(1)$/$O(n)$        | $O(1)$     |
| `measure`/`length`            | $O(1)$                   | $O(1)$                                    | $O(n)$               | $O(1)$     |
| `append`                      | $O(\log \min(l1, l2))$   | $O(\log n)$                               | $O(n)$               | $O(m+n)$   |
| `split`                       | $O(\log \min(n, l-n))$   | $O(\log n)$                               | $O(n)$               | $O(1)$     |
| `replicate`                   | $O(\log n)$              | $O(\log n)$                               | $O(n)$               | $O(n)$     |
| `fromList`,`toList`,`reverse` | $O(l)$/$O(l)$/$O(l)$     | $O(l)$                                    | $O(1)$/$O(1)$/$O(n)$ | $O(n)$     |
| `index`                       | $O(\log \min(n, l-n))$   | $O(\log n)$                               | $O(n)$               | $O(1)$     |

## Ứng dụng

Cây ngón tay có thể dùng để xây dựng các cây khác. Ví dụ, có thể cài đặt hàng đợi ưu tiên bằng cách đánh dấu các nút trong theo độ ưu tiên nhỏ nhất của các nút con trong cây, hoặc cài đặt danh sách/mảng có chỉ số bằng cách đánh dấu nút theo số lượng lá trong các nút con của nó. Các ứng dụng khác bao gồm dãy truy cập ngẫu nhiên (như mô tả dưới đây), dãy có thứ tự và cây khoảng.

Cây ngón tay có thể cung cấp thao tác đẩy, đảo ngược và lấy ra với thời gian trung bình $O(1)$, cùng với nối và tách trong $O(\log n)$; đồng thời có thể thích nghi với dãy được đánh chỉ số hoặc được sắp thứ tự. Giống như mọi cấu trúc dữ liệu hàm, về bản chất nó có tính bền vững (persistent); nghĩa là các phiên bản cũ của cây luôn được giữ lại.

Về cài đặt mã, cài đặt dãy hữu hạn `Seq` trong thư viện lõi Haskell sử dụng cây ngón tay 2-3 ([Data.Sequence](https://hackage.haskell.org/package/containers-0.6.5.1/docs/Data-Sequence.html)); [cài đặt](https://ocaml-batteries-team.github.io/batteries-included/hdoc2/BatFingerTree.html) mô-đun `BatFingerTree` trong OCaml cũng sử dụng cấu trúc dữ liệu cây ngón tay tổng quát. Cây ngón tay có thể được cài đặt có hoặc không có đánh giá lười, nhưng tính lười cho phép một cài đặt đơn giản hơn.

## Tài liệu tham khảo và đọc thêm

1.  Ralf Hinze and Ross Paterson, "[Finger trees: a simple general-purpose data structure](http://www.staff.city.ac.uk/~ross/papers/FingerTree.html)", Journal of Functional Programming 16:2 (2006) pp 197-217.
2.  [Finger Tree - Wikipedia](https://en.wikipedia.org/wiki/Finger_tree)

[^okasaki1999purely]: [Purely Functional Data Structures](https://www.cambridge.org/us/academic/subjects/computer-science/programming-languages-and-applied-logic/purely-functional-data-structures), Chris Okasaki (1999)
