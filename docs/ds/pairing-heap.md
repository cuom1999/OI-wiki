<span id="&#x5F15;&#x5165;"></span>

## Mở đầu

Heap ghép cặp là một cấu trúc dữ liệu hỗ trợ các thao tác chèn, truy vấn/xóa phần tử nhỏ nhất, hợp nhất, sửa phần tử, v.v. Đây là một loại heap có thể hợp nhất. Nó có ưu điểm là nhanh và có cấu trúc đơn giản, nhưng vì độ phức tạp khấu hao của nó dựa trên phân tích thế năng nên không thể làm bền vững hóa.

<span id="&#x5B9A;&#x4E49;"></span>

## Định nghĩa

Heap ghép cặp là một cây đa phân có trọng số thỏa mãn tính chất heap (như hình dưới), tức là trọng số của mỗi nút đều nhỏ hơn hoặc bằng trọng số của mọi nút con của nó (ở đây xét min-heap, các phần sau cũng vậy).

![](./images/pairingheap1.jpg)

Thông thường, ta dùng biểu diễn con - anh em để lưu một heap ghép cặp (như hình dưới). Tất cả các nút con của một nút tạo thành một danh sách liên kết đơn. Mỗi nút lưu con trỏ tới nút con đầu tiên, tức nút đầu của danh sách liên kết, và con trỏ tới anh em bên phải của nó.

Cách này thuận tiện cho việc cài đặt heap ghép cặp, đồng thời cũng giúp phân tích độ phức tạp dễ hơn.

![](./images/pairingheap2.jpg)

```cpp
struct Node {
  T v;  // T là kiểu của trọng số
  Node *child, *sibling;
  // child trỏ tới nút con đầu tiên của nút này, sibling trỏ tới anh em kế tiếp của nút này.
  // Nếu nút này không có con/anh em kế tiếp thì con trỏ trỏ tới nullptr.
};
```

Từ định nghĩa có thể thấy, so với các cấu trúc heap thường gặp khác, heap ghép cặp không duy trì thêm bất kỳ thông tin nào như kích thước cây, độ sâu, hạng, v.v. (heap nhị phân cũng không duy trì thông tin phụ, nhưng nó đảm bảo độ phức tạp thao tác bằng cách giữ một cấu trúc cây nhị phân hoàn chỉnh nghiêm ngặt). Hơn nữa, bất kỳ cây nào thỏa mãn tính chất heap cũng là một heap ghép cặp hợp lệ. Chính cấu trúc đơn giản nhưng rất linh hoạt này là nền tảng cho hiệu quả tốt của heap ghép cặp trong thực tế. Để so sánh, hằng số lớn của heap Fibonacci xuất phát từ việc nó phải duy trì rất nhiều thông tin phụ.

Heap ghép cặp đảm bảo tổng độ phức tạp thông qua một trình tự thao tác được thiết kế cẩn thận. Bài báo gốc[^ref1] gọi nó là "một heap tự điều chỉnh (Self Adjusting Heap)". Ở khía cạnh này, nó khá giống cây Splay (trong bài báo gốc được gọi là "Self Adjusting Binary Tree").

<span id="&#x8FC7;&#x7A0B;"></span>

## Quy trình

<span id="&#x67E5;&#x8BE2;&#x6700;&#x5C0F;&#x503C;"></span>

### Truy vấn phần tử nhỏ nhất

Từ định nghĩa của heap ghép cặp, có thể thấy trọng số của nút gốc luôn là nhỏ nhất, vì vậy chỉ cần trả về nút gốc.

<span id="&#x5408;&#x5E76;"></span>

### Hợp nhất

Thao tác hợp nhất hai heap ghép cặp rất đơn giản: trước hết chọn nút gốc nhỏ hơn trong hai nút gốc làm nút gốc mới, sau đó chèn nút gốc lớn hơn vào làm con của nó (xem hình dưới).

![](./images/pairingheap3.jpg)

Cần lưu ý rằng danh sách con của một nút được sắp theo thời điểm chèn: nút ngoài cùng bên phải trở thành con của nút cha sớm nhất, còn nút ngoài cùng bên trái trở thành con của nút cha gần đây nhất.

???+ note "Cài đặt"
    ```cpp
    Node* meld(Node* x, Node* y) {
      // Nếu một heap rỗng thì trả về heap còn lại
      if (x == nullptr) return y;
      if (y == nullptr) return x;
      if (x->v > y->v) std::swap(x, y);  // sau khi swap, x là heap có trọng số nhỏ hơn, y là heap có trọng số lớn hơn
      // Đặt y làm con của x
      y->sibling = x->child;
      x->child = y;
      return x;  // nút gốc mới là x
    }
    ```

<span id="&#x63D2;&#x5165;"></span>

### Chèn

Khi đã có thao tác hợp nhất, thao tác chèn chỉ cần xem phần tử mới như một heap ghép cặp mới rồi hợp nhất với heap ban đầu.

<span id="&#x5220;&#x9664;&#x6700;&#x5C0F;&#x503C;"></span>

### Xóa phần tử nhỏ nhất

Trước hết cần nhắc rằng vài thao tác ở trên đều khá "lười", hầu như không bảo trì cấu trúc dữ liệu, nên ta phải thiết kế cẩn thận thao tác xóa phần tử nhỏ nhất để đảm bảo tổng độ phức tạp không gặp vấn đề.

Nút gốc chính là phần tử nhỏ nhất, nên nút cần xóa là nút gốc. Hãy xét điều gì xảy ra sau khi lấy nút gốc đi: toàn bộ các con ban đầu của nút gốc tạo thành một rừng; trong khi heap ghép cặp phải là một cây, vì vậy ta cần hợp nhất toàn bộ các nút con này theo một thứ tự nào đó.

Một ý tưởng rất tự nhiên là dùng hàm `meld` để lần lượt hợp nhất các con từ trái sang phải. Làm như vậy thì tính đúng đắn là hiển nhiên, nhưng độ phức tạp của một thao tác có thể suy giảm thành $O(n)$.

Để đảm bảo tổng độ phức tạp khấu hao, cần dùng một phương pháp hợp nhất "hai bước":

1.  Ghép các con thành từng cặp, rồi dùng thao tác `meld` để hợp nhất hai con trong cùng một cặp (xem hình 1 bên dưới).
2.  Hợp nhất lần lượt các heap mới sinh ra **từ phải sang trái** (tức theo hướng từ các con cũ đến các con mới) (xem hình 2 bên dưới).

![](./images/pairingheap4.jpg)

![](./images/pairingheap5.jpg)

Trước hết cài đặt một hàm phụ trợ `merges`, có tác dụng hợp nhất toàn bộ anh em của một nút.

???+ note "Cài đặt"
    ```cpp
    Node* merges(Node* x) {
      if (x == nullptr || x->sibling == nullptr)
        return x;  // Nếu cây rỗng hoặc không có anh em kế tiếp thì không cần hợp nhất nữa, return.
      Node* y = x->sibling;                // y là anh em kế tiếp của x
      Node* c = y->sibling;                // c là anh em tiếp theo nữa
      x->sibling = y->sibling = nullptr;   // tách rời
      return meld(merges(c), meld(x, y));  // phần cốt lõi
    }
    ```

Câu cuối cùng là phần cốt lõi của hàm này, gồm ba phần:

1.  `meld(x,y)` "ghép cặp" x và y.
2.  `merges(c)` đệ quy hợp nhất c và các anh em của nó.
3.  Hợp nhất hai cây mới sinh ra từ hai thao tác trên.

Cần chú ý rằng ở trên đã nêu hướng hợp nhất trong bước thứ hai là có yêu cầu (hợp nhất từ phải sang trái). Cài đặt đệ quy của hàm này đã đảm bảo thứ tự đó; nếu người đọc muốn tự cài đặt phiên bản lặp thì nhất định phải đảm bảo thứ tự này, nếu không độ phức tạp sẽ mất bảo đảm.

Khi đã có hàm `merges`, thao tác `delete-min` trở nên hiển nhiên.

???+ note "Cài đặt"
    ```cpp
    Node* delete_min(Node* x) {
      Node* t = merges(x->child);
      delete x;  // nếu cần thu hồi bộ nhớ
      return t;
    }
    ```

<span id="&#x51CF;&#x5C0F;&#x4E00;&#x4E2A;&#x5143;&#x7D20;&#x7684;&#x503C;"></span>

### Giảm khóa của một phần tử

Để cài đặt thao tác này, cần thêm cho nút một con trỏ "cha". Khi nút có anh em bên trái, con trỏ này trỏ tới anh em bên trái thay vì nút cha thật sự; nếu không, nó trỏ tới nút cha của nút đó.

Trước hết, định nghĩa nút được sửa thành:

???+ note "Cài đặt"
    ```cpp
    struct Node {
      LL v;
      int id;
      Node *child, *sibling;
      Node *father;  // thêm mới: con trỏ cha; nếu nút này là nút gốc thì trỏ tới nút rỗng nullptr
    };
    ```

Thao tác `meld` được sửa thành:

???+ note "Cài đặt"
    ```cpp
    Node* meld(Node* x, Node* y) {
      if (x == nullptr) return y;
      if (y == nullptr) return x;
      if (x->v > y->v) std::swap(x, y);
      if (x->child != nullptr) {  // thêm mới: duy trì con trỏ cha
        x->child->father = y;
      }
      y->sibling = x->child;
      y->father = x;  // thêm mới: duy trì con trỏ cha
      x->child = y;
      return x;
    }
    ```

Thao tác `merges` được sửa thành:

???+ note "Cài đặt"
    ```cpp
    Node *merges(Node *x) {
      if (x == nullptr) return nullptr;
      x->father = nullptr;  // thêm mới: duy trì con trỏ cha
      if (x->sibling == nullptr) return x;
      Node *y = x->sibling, *c = y->sibling;
      y->father = nullptr;  // thêm mới: duy trì con trỏ cha
      x->sibling = y->sibling = nullptr;
      return meld(merges(c), meld(x, y));
    }
    ```

Bây giờ ta xét cách cài đặt thao tác `decrease-key`.

Trước hết ta thấy rằng sau khi giảm trọng số của nút `x`, cây con gốc `x` vẫn thỏa mãn tính chất heap ghép cặp, nhưng giữa cha của `x` và `x` có thể không còn thỏa mãn tính chất heap.

Do đó, ta tách cả cây con gốc `x` ra. Lúc này hai cây đều thỏa mãn tính chất heap ghép cặp, rồi chỉ cần hợp nhất chúng lại là hoàn thành toàn bộ thao tác.

???+ note "Cài đặt"
    ```cpp
    // root là gốc của heap, x là nút cần thao tác, v là trọng số mới; khi gọi cần đảm bảo v <= x->v
    // Giá trị trả về là nút gốc mới
    Node *decrease_key(Node *root, Node *x, LL v) {
      x->v = v;                 // cập nhật trọng số
      if (x == root) return x;  // nếu x là gốc thì trả về trực tiếp
      // Tách x khỏi các nút con của cha; ở đây cần xét vị trí của x.
      if (x->father->child == x) {
        x->father->child = x->sibling;
      } else {
        x->father->sibling = x->sibling;
      }
      if (x->sibling != nullptr) {
        x->sibling->father = x->father;
      }
      x->sibling = nullptr;
      x->father = nullptr;
      return meld(root, x);  // hợp nhất lại x và nút gốc
    }
    ```

<span id="&#x590D;&#x6742;&#x5EA6;&#x5206;&#x6790;"></span>

## Phân tích độ phức tạp

Cấu trúc và cài đặt của heap ghép cặp đều đơn giản, nhưng phân tích độ phức tạp thời gian của nó thì không dễ.

Bài báo gốc[^ref1] chỉ phân tích được rằng các thao tác `meld` và `delete-min` đều có độ phức tạp khấu hao $O(\log n)$, nhưng đưa ra phỏng đoán rằng mọi thao tác của nó đều có độ phức tạp giống heap Fibonacci.

Đáng tiếc là các nghiên cứu sau đó phát hiện rằng với heap ghép cặp không duy trì thông tin phụ, trong một số chuỗi thao tác nhất định, cận dưới độ phức tạp khấu hao của thao tác `decrease-key` ít nhất là $\Omega (\log \log n)$[^ref2].

Hiện nay, một vài ước lượng tốt hơn về cận trên độ phức tạp gồm có: kết quả của Iacono với `meld` $O(1)$ và `decrease-key` $O(\log n)$[^ref3]; kết quả của Pettie với `meld` và `decrease-key` $O(2^{2 \sqrt{\log \log n}})$[^ref4]. Cần lưu ý rằng các độ phức tạp nói trên đều là độ phức tạp khấu hao, vì vậy không thể lấy giá trị nhỏ nhất riêng lẻ giữa các kết quả.

<span id="&#x53C2;&#x8003;&#x6587;&#x732E;"></span>

## Tài liệu tham khảo

[^ref1]: [The pairing heap: a new form of self-adjusting heap](http://www.cs.cmu.edu/~sleator/papers/pairing-heaps.pdf)

[^ref2]: [On the efficiency of pairing heaps and related data structures](https://dl.acm.org/doi/10.1145/320211.320214)

[^ref3]: [Improved upper bounds for pairing heaps](https://arxiv.org/abs/1110.4428)

[^ref4]: [Towards a Final Analysis of Pairing Heaps](http://web.eecs.umich.edu/~pettie/papers/focs05.pdf)

-   <https://en.wikipedia.org/wiki/Pairing_heap>
-   <https://brilliant.org/wiki/pairing-heap/>
