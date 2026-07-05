Size Balanced Tree (SBT) là một loại cây tìm kiếm nhị phân tự cân bằng (Self-Balanced Binary Search Tree, SBBST) do tuyển thủ OI Trung Quốc Chen Qifeng đề xuất vào năm 2007. Cấu trúc này duy trì cân bằng bằng cách kiểm tra số lượng nút trong các cây con. So với các cây tìm kiếm nhị phân tự cân bằng phổ biến như cây đỏ-đen hay AVL, Size Balanced Tree hỗ trợ truy vấn thứ hạng (rank) của một khóa trong cây với độ phức tạp thời gian $O(\log n)$.

## Định nghĩa nút

So với cây tìm kiếm nhị phân thông thường, mỗi nút $N$ của SBT chỉ cần duy trì thêm một trường số nguyên `size`, dùng để lưu số nút trong cây con có gốc là $N$. Kiểu nút `Node` được định nghĩa như sau:

| Identifier | Type    | Description     |
| ---------- | ------- | --------------- |
| `left`     | `Node*` | tham chiếu tới con trái |
| `right`    | `Node*` | tham chiếu tới con phải |
| `size`     | `int`   | số nút trong cây con có gốc tại nút này |

## Tính chất

Mọi nút $N$ trong Size Balanced Tree thỏa mãn các tính chất sau:

```text
size(N.left) >= size(N.right.left)
size(N.left) >= size(N.right.right)
size(N.right) >= size(N.left.left)
size(N.right) >= size(N.left.right)
```

Diễn đạt bằng ngôn ngữ tự nhiên: `size` của một nút bất kỳ không nhỏ hơn `size` của mọi nút con của nút anh em của nó (Sibling), tức các nút cháu theo nhánh bên (Nephew).

## Duy trì cân bằng

### Phép xoay

SBT chủ yếu duy trì cân bằng bằng các phép xoay làm thay đổi chiều cao của cây. Phép xoay của nó tương tự hầu hết cây tìm kiếm nhị phân tự cân bằng khác; điểm khác biệt duy nhất là sau khi xoay xong, cần cập nhật `size` cho các nút có con trái/phải thay đổi trong quá trình xoay. Mã ví dụ như sau:

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

Thao tác chèn của SBT cần thực hiện thao tác chèn như cây tìm kiếm nhị phân thông thường, đồng thời cập nhật đệ quy trường `size` của các nút và duy trì cân bằng. Mã ví dụ như sau:

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

Theo mô tả về thao tác xóa trong bài báo của Chen Qifeng, người đề xuất Size Balanced Tree:

> It can result in a destroyed SBT. But with the insertion above, a BST is still kept at the height of $O(\log n)$ where $n$ is the total number of insertions, not the current size.

Thao tác xóa tuy có thể phá vỡ tính chất của SBT, nhưng không làm chiều cao cây tăng lên, nên không ảnh hưởng đến hiệu quả của các thao tác sau đó. Tuy nhiên trong thực tế, nếu sau một đợt chèn hàng loạt chỉ thực hiện nhiều thao tác xóa và truy vấn, cây vẫn có thể mất cân bằng và ảnh hưởng đến hiệu suất tổng thể. Vì vậy, trong cách cài đặt thao tác xóa của SBT ở bài này, ta vẫn chọn thêm bước duy trì cân bằng. Mã tham khảo như sau:

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
    // Case 1: no child
    node = nullptr;
  } else if (node->right == nullptr) {
    // Case 2: left child only
    // clang-format off
    //     P
    //     |  remove(N)  P
    //     N  ========>  |
    //    /              L
    //   L
    // clang-format on
    node = node->left;
  } else if (node->left == nullptr) {
    // Case 3: right child only
    // clang-format off
    //   P
    //   |    remove(N)  P
    //   N    ========>  |
    //    \              R
    //     R
    // clang-format on
    node = node->right;
  } else if (node->right->left == nullptr) {
    // Case 4: both left and right child, right child has no left child
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
    // Case 5: both left and right child, right child is not a leaf
    // clang-format off
    //   Step 1. find the node N with the smallest key
    //           and its parent P on the right subtree
    //   Step 2. swap S and N
    //   Step 3. remove node N like Case 1 or Case 3
    //   Step 4. update size for all nodes on the path
    //           from S to P
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

    // Step 1
    NodePtr successor = node->right;
    NodePtr parent = node;
    path.push(node);

    while (successor->left != nullptr) {
      path.push(successor);
      parent = successor;
      successor = parent->left;
    }

    // Step 2
    swapNode(node, successor);

    // Step 3
    parent->left = node->right;
    // Restore node
    node = successor;

    // Step 4
    while (!path.empty()) {
      path.top()->updateSize();
      path.pop();
    }
  }

  return true;
}
```

Cần chú ý rằng trong Case 5 của đoạn mã trên, sau khi dùng nút kế nhiệm $S$ (cũng có thể chọn nút tiền nhiệm) để thay thế nút cần xóa $N$ và xóa $N$ sau khi thay thế, cần cập nhật trường `size` của mọi nút trên đường từ nút cha $P$ của $S$ trước khi thay thế đến nút $S$ sau khi thay thế (như chú thích trong mã). Cài đặt trong bài này dùng ngăn xếp để lần lượt ghi lại các nút trên đường đi, cuối cùng bật ra theo thứ tự ngược với khi duyệt để cập nhật.

### Truy vấn thứ hạng

Vì mỗi nút SBT lưu thông tin số nút trong cây con, ta có thể truy vấn thứ hạng của một `key` (hoặc số nút lớn hơn/nhỏ hơn một `key`) trong thời gian $O(\log n)$. Mã ví dụ như sau:

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
