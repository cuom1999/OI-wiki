Cây cân bằng theo kích thước (Size Balanced Tree, SBT) là một loại cây tìm kiếm nhị phân tự cân bằng
(Self-Balanced Binary Search Tree, SBBST) do tuyển thủ OI Trung Quốc Chen Qifeng đề xuất vào năm 2007.
Cấu trúc này duy trì cân bằng bằng cách so sánh số lượng nút trong các cây con.
So với các cây tìm kiếm nhị phân tự cân bằng phổ biến như cây đỏ-đen hay AVL,
SBT hỗ trợ truy vấn thứ hạng của một khóa trong cây với độ phức tạp thời gian $O(\log n)$.

## Định nghĩa nút

So với cây tìm kiếm nhị phân thông thường, mỗi nút $N$ của SBT chỉ cần duy trì thêm một trường số nguyên `size`,
dùng để lưu số nút trong cây con có gốc tại $N$.
Kiểu nút `Node` được định nghĩa như sau:

| Định danh  | Kiểu    | Mô tả           |
| ---------- | ------- | --------------- |
| `left`     | `Node*` | tham chiếu tới con trái |
| `right`    | `Node*` | tham chiếu tới con phải |
| `size`     | `int`   | số nút trong cây con có gốc tại nút này |

## Tính chất

Mọi nút $N$ trong cây cân bằng theo kích thước phải thỏa mãn các bất đẳng thức sau:

```text
size(N.left) >= size(N.right.left)
size(N.left) >= size(N.right.right)
size(N.right) >= size(N.left.left)
size(N.right) >= size(N.left.right)
```

Diễn đạt bằng lời: `size` của một nút bất kỳ không nhỏ hơn `size` của mọi nút con thuộc nút anh em của nó (sibling),
tức các nút cháu nằm ở nhánh bên (nephew).

## Duy trì cân bằng

### Phép xoay

SBT chủ yếu duy trì cân bằng bằng các phép xoay làm thay đổi chiều cao của cây.
Phép xoay của nó tương tự hầu hết cây tìm kiếm nhị phân tự cân bằng khác.
Điểm khác biệt duy nhất là sau khi xoay xong,
cần cập nhật `size` cho các nút có con trái/phải thay đổi trong quá trình xoay.
Mã ví dụ như sau:

```cpp
void updateSize() {
  USize leftSize = this->left != nullptr ? this->left->size : 0;
  USize rightSize = this->right != nullptr ? this->right->size : 0;
  this->size = leftSize + rightSize + 1;
}

static void rotateLeft(NodePtr& node) {
  assert(node != nullptr);
  // clang-format off
  //     |                       |
  //     N                       S
  //    / \     l-rotate(N)     / \
  //   L   S    ==========>    N   R
  //      / \                 / \
  //     M   R               L   M
  // clang-format on
  NodePtr successor = node->right;
  node->right = successor->left;
  successor->left = node;

  node->updateSize();
  successor->updateSize();

  node = successor;
}

static void rotateRight(NodePtr& node) {
  assert(node != nullptr);
  // clang-format off
  //       |                   |
  //       N                   S
  //      / \   r-rotate(N)   / \
  //     S   R  ==========>  L   N
  //    / \                     / \
  //   L   M                   M   R
  // clang-format on
  NodePtr successor = node->left;
  node->left = successor->right;
  successor->right = node;

  node->updateSize();
  successor->updateSize();

  node = successor;
}
```

### Duy trì

#### Trường hợp 1

`size(N.left) < size(N.right.left)`

Nút cháu trái của cây con phải quá lớn, nên trước hết xoay phải cây con phải, rồi xoay trái nút hiện tại.

```cpp
if (size(node->right->left) > size(node->left)) {
  // clang-format off
  //     |                     |                      |
  //     N                     N                     [M]
  //    / \    r-rotate(R)    / \     l-rotate(N)    / \
  //  <L>  R   ==========>  <L> [M]   ==========>   N   R
  //      /                       \                /
  //    [M]                        R             <L>
  // clang-format on
  rotateRight(node->right);
  rotateLeft(node);
  fixBalance(node->left);
  fixBalance(node->right);
  fixBalance(node);
  return;
}
```

#### Trường hợp 2

`size(N.left) < size(N.right.right)`

Cây con phải lệch về phải quá nhiều, nên chỉ cần xoay trái nút hiện tại.

```cpp
if (size(node->right->right) > size(node->left)) {
  // clang-format off
  //     |                       |
  //     N                       R
  //    / \     l-rotate(N)     / \
  //  <L>  R    ==========>    N  [M]
  //        \                 /
  //        [M]             <L>
  // clang-format on
  rotateLeft(node);
  fixBalance(node->left);
  fixBalance(node);
  return;
}
```

#### Trường hợp 3

`size(N.right) < size(N.left.left)`

Đây là trường hợp đối xứng với trường hợp 2: cây con trái lệch về trái quá nhiều, nên xoay phải nút hiện tại.

```cpp
if (size(node->left->left) > size(node->right)) {
  // clang-format off
  //       |                       |
  //       N                       L
  //      / \     r-rotate(N)     / \
  //     L  <R>   ==========>   [M]  N
  //    /                             \
  //  [M]                             <R>
  // clang-format on
  rotateRight(node);
  fixBalance(node->right);
  fixBalance(node);
  return;
}
```

#### Trường hợp 4

`size(N.right) < size(N.left.right)`

Đây là trường hợp đối xứng với trường hợp 1: nút cháu phải của cây con trái quá lớn, nên trước hết xoay trái cây con
trái, rồi xoay phải nút hiện tại.

```cpp
if (size(node->left->right) > size(node->right)) {
  // clang-format off
  //     |                     |                      |
  //     N                     N                     [M]
  //    / \    l-rotate(L)    / \     r-rotate(N)    / \
  //   L  <R>  ==========>  [M] <R>   ==========>   L   N
  //    \                   /                            \
  //    [M]                L                             <R>
  // clang-format on
  rotateLeft(node->left);
  rotateRight(node);
  fixBalance(node->left);
  fixBalance(node->right);
  fixBalance(node);
  return;
}
```

## Thao tác

### Chèn

Thao tác chèn của SBT giống thao tác chèn trong cây tìm kiếm nhị phân thông thường,
đồng thời cập nhật đệ quy trường `size` của các nút và duy trì cân bằng.
Mã ví dụ như sau:

```cpp
if (compare(key, node->key)) {
  /* key < node->key */
  if (node->left == nullptr) {
    node->left = Node::from(key, value);
    node->updateSize();
  } else {
    insert(node->left, key, value, replace);
    node->updateSize();
    fixBalance(node);
  }
} else {
  /* key > node->key */
  if (node->right == nullptr) {
    node->right = Node::from(key, value);
    node->updateSize();
  } else {
    insert(node->right, key, value, replace);
    node->updateSize();
    fixBalance(node);
  }
}
```

### Xóa

Theo mô tả về thao tác xóa trong bài báo của Chen Qifeng, tác giả đề xuất cây cân bằng theo kích thước:

> Điều này có thể làm hỏng tính chất của SBT. Nhưng với cách chèn ở trên,
> cây tìm kiếm nhị phân vẫn giữ chiều cao $O(\log n)$,
> trong đó $n$ là tổng số lần chèn, không phải kích thước hiện tại.

Thao tác xóa tuy có thể phá vỡ tính chất của SBT, nhưng không làm chiều cao cây tăng lên,
nên theo phân tích ban đầu không ảnh hưởng đến cận độ phức tạp của các thao tác sau đó.
Tuy nhiên trong thực tế, nếu sau một đợt chèn hàng loạt chỉ thực hiện nhiều thao tác xóa và truy vấn,
cây vẫn có thể mất cân bằng và ảnh hưởng đến hiệu suất tổng thể.
Vì vậy, cách cài đặt thao tác xóa của SBT trong bài này vẫn thêm bước duy trì cân bằng.
Mã tham khảo như sau:

```cpp
bool remove(NodePtr& node, K key, NodeConsumer action) {
  assert(node != nullptr);

  if (key != node->key) {
    if (compare(key, node->key)) {
      /* key < node->key */
      NodePtr& left = node->left;
      if (left != nullptr && remove(left, key, action)) {
        node->updateSize();
        fixBalance(node);
        return true;
      } else {
        return false;
      }
    } else {
      /* key > node->key */
      NodePtr& right = node->right;
      if (right != nullptr && remove(right, key, action)) {
        node->updateSize();
        fixBalance(node);
        return true;
      } else {
        return false;
      }
    }
  }

  assert(key == node->key);
  action(node);

  if (node->isLeaf()) {
    // Trường hợp 1: không có con
    node = nullptr;
  } else if (node->right == nullptr) {
    // Trường hợp 2: chỉ có con trái
    // clang-format off
    //     P
    //     |  remove(N)  P
    //     N  ========>  |
    //    /              L
    //   L
    // clang-format on
    node = node->left;
  } else if (node->left == nullptr) {
    // Trường hợp 3: chỉ có con phải
    // clang-format off
    //   P
    //   |    remove(N)  P
    //   N    ========>  |
    //    \              R
    //     R
    // clang-format on
    node = node->right;
  } else if (node->right->left == nullptr) {
    // Trường hợp 4: có cả con trái và con phải, con phải không có con trái
    // clang-format off
    //    |                 |
    //    N    remove(N)    R
    //   / \   ========>   /
    //  L   R             L
    // clang-format on
    NodePtr right = node->right;
    swapNode(node, right);
    right->right = node->right;
    node = right;
    node->updateSize();
    fixBalance(node);
  } else {
    // Trường hợp 5: có cả con trái và con phải, con phải không phải nút lá
    // clang-format off
    //   Bước 1. tìm nút S có khóa nhỏ nhất
    //           và cha P của nó trong cây con phải
    //   Bước 2. hoán đổi S và N
    //   Bước 3. xóa nút N như Trường hợp 1 hoặc Trường hợp 3
    //   Bước 4. cập nhật size cho mọi nút trên đường đi
    //           từ S đến P
    //     |                  |
    //     N                  S                 |
    //    / \                / \                S
    //   L  ..  swap(N, S)  L  ..  remove(N)   / \
    //       |  =========>      |  ========>  L  ..
    //       P                  P                 |
    //      / \                / \                P
    //     S  ..              N  ..              / \
    //      \                  \                R  ..
    //       R                  R
    //
    // clang-format on

    std::stack<NodePtr> path;

    // Bước 1
    NodePtr successor = node->right;
    NodePtr parent = node;
    path.push(node);

    while (successor->left != nullptr) {
      path.push(successor);
      parent = successor;
      successor = parent->left;
    }

    // Bước 2
    swapNode(node, successor);

    // Bước 3
    parent->left = node->right;
    // Khôi phục node
    node = successor;

    // Bước 4
    while (!path.empty()) {
      path.top()->updateSize();
      path.pop();
    }
  }

  return true;
}
```

Trong Trường hợp 5 của đoạn mã trên,
sau khi dùng nút kế nhiệm $S$ (cũng có thể chọn nút tiền nhiệm) để thay thế nút cần xóa $N$
và xóa $N$ sau khi thay thế,
cần cập nhật trường `size` của mọi nút trên đường từ nút $S$ sau khi thay thế
đến nút cha $P$ của $S$ trước khi thay thế, như chú thích trong mã.
Cài đặt trong bài này dùng ngăn xếp để lần lượt ghi lại các nút trên đường đi,
cuối cùng lấy ra theo thứ tự ngược với khi duyệt để cập nhật.

### Truy vấn thứ hạng

Vì mỗi nút SBT lưu số nút trong cây con,
có thể truy vấn thứ hạng của một `key` (hoặc số nút lớn hơn/nhỏ hơn một `key`) trong thời gian $O(\log n)$.
Mã ví dụ như sau:

```cpp
USize countLess(ConstNodePtr node, K key, bool countEqual = false) const {
  if (node == nullptr) {
    return 0;
  } else if (key < node->key) {
    return countLess(node->left, key, countEqual);
  } else if (key > node->key) {
    return size(node->left) + 1 + countLess(node->right, key, countEqual);
  } else {
    return size(node->left) + (countEqual ? 1 : 0);
  }
}

USize countGreater(ConstNodePtr node, K key, bool countEqual = false) const {
  if (node == nullptr) {
    return 0;
  } else if (key < node->key) {
    return size(node->right) + 1 + countGreater(node->left, key, countEqual);
  } else if (key > node->key) {
    return countGreater(node->right, key, countEqual);
  } else {
    return size(node->right) + (countEqual ? 1 : 0);
  }
}
```

## Mã tham khảo

Đoạn mã dưới đây là `Map` cài đặt bằng SBT, tức một ánh xạ có thứ tự và không cho phép khóa trùng:

??? note "Mã đầy đủ"
    ```cpp
    --8<-- "docs/ds/code/size-balanced-tree/SizeBalancedTreeMap.hpp"
    ```
