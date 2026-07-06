Trang này giới thiệu ngắn gọn về danh sách liên kết.

<span id="giới-thiệu"></span>

## Giới thiệu

Danh sách liên kết là một cấu trúc dữ liệu dùng để lưu trữ dữ liệu, trong đó
các phần tử được nối với nhau bằng con trỏ giống như các mắt xích. Đặc điểm của
nó là chèn và xóa dữ liệu rất thuận tiện, nhưng tìm kiếm và đọc dữ liệu lại kém
hiệu quả hơn.

<span id="khác-biệt-với-mảng"></span>

## Khác biệt với mảng

Cả danh sách liên kết và mảng đều có thể dùng để lưu trữ dữ liệu. Khác với danh
sách liên kết, mảng lưu toàn bộ phần tử liên tiếp theo thứ tự. Cấu trúc lưu trữ
khác nhau khiến chúng có những ưu điểm khác nhau:

Nhờ cấu trúc dạng chuỗi, danh sách liên kết có thể xóa và chèn dữ liệu thuận
tiện, số thao tác là $O(1)$. Nhưng cũng vì vậy, hiệu quả tìm kiếm và đọc dữ liệu
không cao bằng mảng; khi truy cập ngẫu nhiên, số thao tác là $O(n)$.

Mảng có thể tìm kiếm và đọc dữ liệu thuận tiện, với số thao tác khi truy cập
ngẫu nhiên là $O(1)$. Nhưng số thao tác để xóa và chèn là $O(n)$.

<span id="xây-dựng-danh-sách-liên-kết"></span>

## Xây dựng danh sách liên kết

???+ tip "Mẹo"
    Khi xây dựng danh sách liên kết, phần sử dụng con trỏ khá trừu tượng. Chỉ
    đọc mô tả bằng chữ và mã nguồn có thể khó hiểu, nên kết hợp vẽ hình để nắm
    rõ hơn.

<span id="danh-sách-liên-kết-đơn"></span>

### Danh sách liên kết đơn

Danh sách liên kết đơn gồm vùng dữ liệu và vùng con trỏ. Vùng dữ liệu dùng để
lưu dữ liệu, còn vùng con trỏ dùng để nối nút hiện tại với nút tiếp theo.

![](images/list.svg)

???+ note "Cài đặt"
    === "C++"
        ```cpp
        struct Node {
          int value;
          Node *next;
        };
        ```
    
    === "Python"
        ```python
        class Node:
            def __init__(self, value=None, next=None):
                self.value = value
                self.next = next
        ```

<span id="danh-sách-liên-kết-đôi"></span>

### Danh sách liên kết đôi

Danh sách liên kết đôi cũng có vùng dữ liệu và vùng con trỏ. Điểm khác biệt là
vùng con trỏ được chia thành trái và phải, hoặc nút trước và nút sau, dùng để
nối nút trước, nút hiện tại và nút sau.

![](images/double-list.svg)

???+ note "Cài đặt"
    === "C++"
        ```cpp
        struct Node {
          int value;
          Node *left;
          Node *right;
        };
        ```
    
    === "Python"
        ```python
        class Node:
            def __init__(self, value=None, left=None, right=None):
                self.value = value
                self.left = left
                self.right = right
        ```

<span id="chèn-ghi-dữ-liệu-vào-danh-sách-liên-kết"></span>

## Chèn dữ liệu vào danh sách liên kết

<span id="danh-sách-liên-kết-đơn_1"></span>

### Danh sách liên kết đơn

Quy trình đại khái như sau:

1.  Khởi tạo dữ liệu cần chèn `node`;
2.  Cho con trỏ `next` của `node` trỏ đến nút kế tiếp của `p`;
3.  Cho con trỏ `next` của `p` trỏ đến `node`.

Có thể tham khảo quá trình cụ thể trong các hình dưới đây:

1.  ![](./images/list-insert-1.svg)
2.  ![](./images/list-insert-2.svg)
3.  ![](./images/list-insert-3.svg)

Mã cài đặt như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        void insertNode(int i, Node *p) {
          Node *node = new Node;
          node->value = i;
          node->next = p->next;
          p->next = node;
        }
        ```
    
    === "Python"
        ```python
        def insertNode(i, p):
            node = Node()
            node.value = i
            node.next = p.next
            p.next = node
        ```

<span id="danh-sách-liên-kết-vòng-đơn"></span>

### Danh sách liên kết vòng đơn

Nối đầu và cuối danh sách liên kết lại với nhau thì danh sách liên kết sẽ trở
thành danh sách liên kết vòng. Vì đầu và cuối danh sách liên kết được nối với
nhau, khi chèn dữ liệu cần kiểm tra danh sách ban đầu có rỗng hay không: nếu
rỗng thì nút tự trỏ về chính nó, nếu không rỗng thì chèn dữ liệu như bình
thường.

Quy trình đại khái như sau:

1.  Khởi tạo dữ liệu cần chèn `node`;
2.  Kiểm tra danh sách liên kết cho trước `p` có rỗng hay không;
3.  Nếu rỗng, cho con trỏ `next` của `node` và `p` đều trỏ đến chính `node`;
4.  Ngược lại, cho con trỏ `next` của `node` trỏ đến nút kế tiếp của `p`;
5.  Cho con trỏ `next` của `p` trỏ đến `node`.

Có thể tham khảo quá trình cụ thể trong các hình dưới đây:

1.  ![](./images/list-insert-cyclic-1.svg)
2.  ![](./images/list-insert-cyclic-2.svg)
3.  ![](./images/list-insert-cyclic-3.svg)

Mã cài đặt như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        void insertNode(int i, Node *&p) {
          Node *node = new Node;
          node->value = i;
          node->next = NULL;
          if (p == NULL) {
            p = node;
            node->next = node;
          } else {
            node->next = p->next;
            p->next = node;
          }
        }
        ```
    
    === "Python"
        ```python
        def insertNode(i, p):
            node = Node()
            node.value = i
            node.next = None
            if p == None:
                p = node
                node.next = node
            else:
                node.next = p.next
                p.next = node
            return p
        ```

<span id="danh-sách-liên-kết-vòng-đôi"></span>

### Danh sách liên kết vòng đôi

Khi chèn dữ liệu vào danh sách liên kết vòng đôi, ngoài việc kiểm tra danh sách
cho trước có rỗng hay không, còn phải đồng thời sửa cả hai con trỏ trái và phải.

Quy trình đại khái như sau:

1.  Khởi tạo dữ liệu cần chèn `node`;
2.  Kiểm tra danh sách liên kết cho trước `p` có rỗng hay không;
3.  Nếu rỗng, cho hai con trỏ `left` và `right` của `node`, cũng như `p`, đều
    trỏ đến chính `node`;
4.  Ngược lại, cho con trỏ `left` của `node` trỏ đến `p`;
5.  Cho con trỏ `right` của `node` trỏ đến nút bên phải của `p`;
6.  Cho con trỏ `left` của nút bên phải của `p` trỏ đến `node`;
7.  Cho con trỏ `right` của `p` trỏ đến `node`.

Mã cài đặt như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        void insertNode(int i, Node *&p) {
          Node *node = new Node;
          node->value = i;
          if (p == NULL) {
            p = node;
            node->left = node;
            node->right = node;
          } else {
            node->left = p;
            node->right = p->right;
            p->right->left = node;
            p->right = node;
          }
        }
        ```
    
    === "Python"
        ```python
        def insertNode(i, p):
            node = Node()
            node.value = i
            if p == None:
                p = node
                node.left = node
                node.right = node
            else:
                node.left = p
                node.right = p.right
                p.right.left = node
                p.right = node
            return p
        ```

<span id="xóa-dữ-liệu-khỏi-danh-sách-liên-kết"></span>

## Xóa dữ liệu khỏi danh sách liên kết

<span id="danh-sách-liên-kết-đơn-vòng"></span>

### Danh sách liên kết đơn (vòng)

Giả sử nút cần xóa là `p`. Khi xóa nó khỏi danh sách liên kết, chỉ cần dùng giá
trị của nút kế tiếp `p->next` để ghi đè lên `p`, đồng thời cập nhật nút sau nữa
của `p`.

Quy trình đại khái như sau:

1.  Gán giá trị của nút kế tiếp của `p` cho `p`, để xóa đi `p->value`;
2.  Tạo một nút tạm `t` để lưu địa chỉ của `p->next`;
3.  Cho con trỏ `next` của `p` trỏ đến nút sau nữa của `p`, để xóa đi `p->next`;
4.  Xóa `t`. Lúc này tuy địa chỉ của nút ban đầu `p` vẫn đang được dùng và địa
    chỉ bị xóa là địa chỉ của nút ban đầu `p->next`, nhưng dữ liệu của `p` đã bị
    `p->next` ghi đè, nên `p` thực chất không còn tồn tại như ban đầu nữa.

Có thể tham khảo quá trình cụ thể trong các hình dưới đây:

1.  ![](./images/list-delete-1.svg)
2.  ![](./images/list-delete-2.svg)
3.  ![](./images/list-delete-3.svg)

Mã cài đặt như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        void deleteNode(Node *p) {
          p->value = p->next->value;
          Node *t = p->next;
          p->next = p->next->next;
          delete t;
        }
        ```
    
    === "Python"
        ```python
        def deleteNode(p):
            p.value = p.next.value
            p.next = p.next.next
        ```

<span id="danh-sách-liên-kết-vòng-đôi_1"></span>

### Danh sách liên kết vòng đôi

Quy trình đại khái như sau:

1.  Cho con trỏ phải của nút bên trái của `p` trỏ đến nút bên phải của `p`;
2.  Cho con trỏ trái của nút bên phải của `p` trỏ đến nút bên trái của `p`;
3.  Tạo một nút tạm `t` để lưu địa chỉ của `p`;
4.  Gán địa chỉ nút bên phải của `p` cho `p`, để tránh việc `p` trở thành con trỏ treo;
5.  Xóa `t`.

Mã cài đặt như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        void deleteNode(Node *&p) {
          p->left->right = p->right;
          p->right->left = p->left;
          Node *t = p;
          p = p->right;
          delete t;
        }
        ```
    
    === "Python"
        ```python
        def deleteNode(p):
            p.left.right = p.right
            p.right.left = p.left
            p = p.right
            return p
        ```

<span id="kỹ-thuật"></span>

## Kỹ thuật

<span id="danh-sách-liên-kết-xor"></span>

### Danh sách liên kết XOR

Danh sách liên kết XOR (XOR linked list) về bản chất vẫn là **danh sách liên kết
đôi**, nhưng nó tận dụng giá trị XOR theo bit để thực hiện chức năng của danh
sách liên kết đôi chỉ với lượng bộ nhớ bằng một con trỏ.

Trong cấu trúc `Node`, định nghĩa `lr = left ^ right`, tức là **giá trị XOR theo
bit** của địa chỉ hai phần tử trước và sau. Khi duyệt xuôi, lấy địa chỉ của phần
tử trước XOR với `lr` của nút hiện tại sẽ thu được địa chỉ của phần tử sau; khi
duyệt ngược, lấy địa chỉ của phần tử sau XOR với `lr` của nút hiện tại sẽ thu
được địa chỉ của phần tử trước. Nhờ vậy, có thể dùng một nửa bộ nhớ mà vẫn thực
hiện được chức năng tương tự danh sách liên kết đôi.
