author: c-forrest, Enter-tainer, giiiiiithub, hly1204, iamtwz, Ir1d, kigawas, ksyx, luxuryspark567, mgt, orzAtalod, sandyzikun, SunsetGlow95, Tiphereth-A, current2020, untitledunrevised, yuhuoji

Cây đỏ-đen nghiêng trái là một biến thể của [cây đỏ-đen](./rbtree.md). Nó đặt thêm một số ràng buộc lên vị trí của cạnh đỏ (hoặc nút đỏ), nhờ đó các thao tác chèn và xóa có thể tương ứng một-một với [cây 2-3](https://en.wikipedia.org/wiki/2%E2%80%933_tree).

Chúng tôi giả sử người đọc đã nắm được ít nhất một loại cây cân bằng dựa trên phép xoay, vì vậy bài viết này sẽ không giải thích riêng thao tác xoay.

## Cây đỏ-đen

### Tính chất

Một cây đỏ-đen thỏa mãn các tính chất sau:

1.  Mỗi nút có màu đỏ hoặc đen.
2.  Nút NIL (nút lá rỗng) có màu đen.
3.  Mọi con của nút đỏ đều phải có màu đen, tức là trên mọi đường đi từ mỗi lá đến gốc không được có hai nút đỏ liên tiếp.
4.  Trên mọi đường đi đơn từ một nút bất kỳ đến từng lá trong cây con của nó đều có cùng số lượng nút đen. Đây là cân bằng chiều cao đen.

Các tính chất này đảm bảo đường đi dài nhất từ gốc đến một lá bất kỳ, trong trường hợp màu đỏ và đen xen kẽ, không vượt quá hai lần đường đi ngắn nhất, trong trường hợp toàn nút đen. Nhờ đó cây vẫn được cân bằng.

Việc duy trì các tính chất này khá phức tạp. Khi chèn một nút, trước hết nút đó chắc chắn phải được tô màu đỏ, nếu không sẽ phá vỡ tính chất 4. Nhưng ngay cả như vậy, ta vẫn có thể phá vỡ tính chất 3, nên cần thực hiện điều chỉnh. Xóa nút còn rắc rối hơn: tương tự như khi chèn, ta không thể xóa trực tiếp một nút đen, nếu không cân bằng chiều cao đen sẽ bị phá vỡ. Làm thế nào để giải quyết những vấn đề này một cách thuận tiện?

## Cây đỏ-đen nghiêng trái (left-leaning red-black tree)

### Giải thích

Cây đỏ-đen nghiêng trái, hay LLRB, là một biến thể cây đỏ-đen dễ cài đặt.

Trong các sơ đồ cây đỏ-đen nghiêng trái bên dưới, màu được gán cho cạnh chứ không phải cho nút. Theo thói quen, ta dùng màu của một nút để chỉ màu của cạnh nối từ cha của nó đến nó.

Cây đỏ-đen nghiêng trái đặt thêm ràng buộc lên cây đỏ-đen. Với hai con trái và phải của một nút đen:

-   Hoặc cả hai đều là màu đen.
-   Hoặc con trái là màu đỏ, con phải là màu đen.

Các trường hợp hợp lệ:

![Biểu diễn 3-node hợp lệ trong cây đỏ-đen nghiêng trái](./images/llrbt-1.png)

Các trường hợp không hợp lệ:

![Các biểu diễn không hợp lệ trong cây đỏ-đen nghiêng trái](./images/llrbt-2.png)

Đây chính là tính chất "nghiêng trái" của LLRB: cạnh đỏ chỉ được phép nghiêng về bên trái.

### Quy trình

#### Chèn

Trước hết, ta dùng cách chèn BST thông thường để chèn một nút lá màu đỏ ở đáy cây. Sau đó, thông qua các điều chỉnh từ dưới lên, ta bảo đảm cây sau khi chèn vẫn thỏa mãn các tính chất của cây đỏ-đen nghiêng trái. Quy trình điều chỉnh được mô tả dưới đây:

![Các khả năng sau khi chèn nút đỏ](./images/llrbt-3.png)

Sau khi chèn, có thể xuất hiện một cạnh đỏ nghiêng phải, vì vậy trong trường hợp cạnh đỏ nghiêng phải ta cần thực hiện một phép xoay trái:

![Xoay trái để sửa cạnh đỏ nghiêng phải](./images/llrbt-4.png)

Sau phép xoay trái, có thể xuất hiện hai cạnh đỏ nghiêng trái liên tiếp:

![Xoay phải để sửa hai cạnh đỏ nghiêng trái liên tiếp](./images/llrbt-5.png)

Vì vậy ta cần thực hiện một phép xoay phải. Với trạng thái sau phép xoay phải, ta nên gọi `color_flip`, tức là đảo màu của nút đó và hai con của nó.

![Đảo màu sau khi xoay phải](./images/llrbt-6.png)

Nhờ đó cạnh đỏ nghiêng phải bị loại bỏ.

??? note "Mã tham khảo (một phần)"
    ```cpp
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::fix_up(
        Set::Node *root) const {
      if (is_red(root->rc) && !is_red(root->lc))  // fix right leaned red link
        root = rotate_left(root);
      if (is_red(root->lc) &&
          is_red(root->lc->lc))  // fix doubly linked left leaned red link
        // if (root->lc == nullptr), then the second expr won't be evaluated
        root = rotate_right(root);
      if (is_red(root->lc) && is_red(root->rc))
        // break up 4 node
        color_flip(root);
      root->size = size(root->lc) + size(root->rc) + 1;
      return root;
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node_Set<Key, Compare>::insert(
        Set::Node_root, const Key &key) const {
      if (root == nullptr) return new Node(key, kRed, 1);
      if (root->key == key)
        ;
      else if (cmp\_(key, root->key))  // if (key < root->key)
        root->lc = insert(root->lc, key);
      else
        root->rc = insert(root->rc, key);
      return fix_up(root);
    }
    ```

#### Xóa

Thao tác xóa dựa trên ý tưởng sau: ta không thể xóa một nút đen, vì làm vậy sẽ phá vỡ chiều cao đen. Do đó ta cần bảo đảm nút cuối cùng bị xóa là nút đỏ.

##### Xóa nút nhỏ nhất

Trước hết, hãy thử xóa giá trị nhỏ nhất trong toàn bộ cây.

Làm thế nào để bảo đảm nút cuối cùng bị xóa là màu đỏ? Trong quá trình đệ quy đi xuống, ta cần duy trì một tính chất: nếu nút hiện tại là `h`, thì phải bảo đảm `h` là màu đỏ, hoặc `h->lc` là màu đỏ.

Hãy xét tính đúng đắn của cách làm này. Nếu ta có thể duy trì thành công tính chất trên bằng các phép xoay và thao tác đảo màu, thì khi đi đến nút nhỏ nhất `h_min`, ta có `h_min` là màu đỏ, hoặc cây con trái của `h_min` là màu đỏ. Nhưng `h_min` hoàn toàn không có cây con trái. Vì vậy điều này bảo đảm nút nhỏ nhất chắc chắn là màu đỏ. Vì nó là màu đỏ, ta có thể xóa nó một cách trực tiếp, rồi dùng cùng ý tưởng điều chỉnh như thao tác chèn để chỉnh lại cây.

Bây giờ ta xét cách thỏa mãn tính chất này. Lưu ý rằng trong lúc đệ quy đi xuống, ta sẽ **tạm thời** phá vỡ một số tính chất của cây đỏ-đen nghiêng trái, nhưng khi quay lui khỏi đệ quy thì sẽ khôi phục chúng.

Như hình dưới mô tả, đây là một trường hợp tương đối đơn giản. Lúc này `h->rc->lc` là màu đen, ta chỉ cần đảo màu một lần:

![Trường hợp đơn giản khi xóa nút nhỏ nhất với h->rc->lc màu đen](./images/llrbt-7.png)

Hơn nữa, sau phép đảo màu như trên, `h->rc` và `h->rc->lc` sẽ không tạo thành các cạnh đỏ liên tiếp.

Nhưng nếu `h->rc->lc` là màu đỏ thì tình huống phức tạp hơn:

![Trường hợp khó khi xóa nút nhỏ nhất với h->rc->lc màu đỏ](./images/llrbt-8.png)

Nếu chỉ đảo màu, các cạnh đỏ liên tiếp sẽ xuất hiện. Khi xét quá trình quay lui khỏi đệ quy, ta không thể sửa được tình huống như vậy, nên cần xử lý thêm.

Sau đó ta có thể thực hiện xóa:

??? note "Mã tham khảo (một phần)"
    ```cpp
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::move_red_left(
        Set::Node *root) const {
      color_flip(root);
      if (is_red(root->rc->lc)) {
        // assume that root->rc != nullptr when calling this function
        root->rc = rotate_right(root->rc);
        root = rotate_left(root);
        color_flip(root);
      }
      return root;
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::delete_min(
        Set::Node *root) const {
      if (root->lc == nullptr) {
        delete root;
        return nullptr;
      }
      if (!is_red(root->lc) && !is_red(root->lc->lc)) {
        // make sure either root->lc or root->lc->lc is red
        // thus make sure we will delete a red node in the end
        root = move_red_left(root);
      }
      root->lc = delete_min(root->lc);
      return fix_up(root);
    }
    ```

##### Xóa nút bất kỳ

Trước hết ta xét việc xóa lá. Tương tự như xóa giá trị nhỏ nhất, trong quá trình xóa một giá trị bất kỳ ta cũng cần duy trì một tính chất. Tuy nhiên lần này có điểm đặc biệt: ta không chỉ đi sang trái, mà có thể đi theo cả hai hướng trái và phải. Vì vậy tính chất cần duy trì trong quá trình xóa là: nếu đi sang trái và nút hiện tại là `h`, thì cần bảo đảm `h` là màu đỏ, hoặc `h->lc` là màu đỏ; nếu đi sang phải và nút hiện tại là `h`, thì cần bảo đảm `h` là màu đỏ, hoặc `h->rc` là màu đỏ. Như vậy ta có thể bảo đảm cuối cùng luôn xóa một nút đỏ.

Tiếp theo xét việc xóa nút không phải lá. Ta chỉ cần tìm nút nhỏ nhất trong cây con phải của nó, nếu có, rồi dùng giá trị của nút nhỏ nhất trong cây con phải để thay thế giá trị của nút đó. Cuối cùng xóa nút nhỏ nhất trong cây con phải.

![Xóa nút bất kỳ bằng cách thay bằng nút kế tiếp](./images/llrbt-9.png)

Vậy nếu không có cây con phải thì sao? Ta cần xoay cây con trái lên, như vậy vấn đề này sẽ không xuất hiện.

??? note "Mã tham khảo (một phần)"
    ```cpp
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::delete_arbitrary(
        Set::Node *root, Key key) const {
      if (cmp_(key, root->key)) {
        // key < root->key
        if (!is_red(root->lc) && !(is_red(root->lc->lc)))
          root = move_red_left(root);
        // ensure the invariant: either root->lc or root->lc->lc (or root and
        // root->lc after dive into the function) is red, to ensure we will
        // eventually delete a red node. therefore we will not break the black
        // height balance
        root->lc = delete_arbitrary(root->lc, key);
      } else {
        // key >= root->key
        if (is_red(root->lc)) root = rotate_right(root);
        if (key == root->key && root->rc == nullptr) {
          delete root;
          return nullptr;
        }
        if (!is_red(root->rc) && !is_red(root->rc->lc)) root = move_red_right(root);
        if (key == root->key) {
          root->key = get_min(root->rc);
          root->rc = delete_min(root->rc);
        } else {
          root->rc = delete_arbitrary(root->rc, key);
        }
      }
      return fix_up(root);
    }
    ```

## Cài đặt

Đoạn mã dưới đây là một `Set` được cài đặt bằng cây đỏ-đen nghiêng trái, tức là một tập hợp có thứ tự và không chứa phần tử trùng lặp:

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <memory>
    #include <vector>
    
    template <class Key, class Compare = std::less<Key>>
    class Set {
     private:
      enum NodeColor { kBlack = 0, kRed = 1 };
    
      struct Node {
        Key key;
        Node *lc{nullptr}, *rc{nullptr};
        size_t size{0};
        NodeColor color;  // the color of the parent link
    
        Node(Key key, NodeColor color, size_t size)
            : key(key), color(color), size(size) {}
    
        Node() = default;
      };
    
      void destroyTree(Node *root) const {
        if (root != nullptr) {
          destroyTree(root->lc);
          destroyTree(root->rc);
          root->lc = root->rc = nullptr;
          delete root;
        }
      }
    
      bool is_red(const Node *nd) const {
        return nd == nullptr ? false : nd->color;  // kRed == 1, kBlack == 0
      }
    
      size_t size(const Node *nd) const { return nd == nullptr ? 0 : nd->size; }
    
      Node *rotate_left(Node *node) const {
        // left rotate a red link
        //          <1>                   <2>
        //        /    \\               //    \
        //       *      <2>    ==>     <1>     *
        //             /   \          /   \
        //            *     *        *     *
        Node *res = node->rc;
        node->rc = res->lc;
        res->lc = node;
        res->color = node->color;
        node->color = kRed;
        res->size = node->size;
        node->size = size(node->lc) + size(node->rc) + 1;
        return res;
      }
    
      Node *rotate_right(Node *node) const {
        // right rotate a red link
        //            <1>               <2>
        //          //    \           /    \\
        //         <2>     *   ==>   *      <1>
        //        /   \                    /   \
        //       *     *                  *     *
        Node *res = node->lc;
        node->lc = res->rc;
        res->rc = node;
        res->color = node->color;
        node->color = kRed;
        res->size = node->size;
        node->size = size(node->lc) + size(node->rc) + 1;
        return res;
      }
    
      NodeColor neg_color(NodeColor n) const { return n == kBlack ? kRed : kBlack; }
    
      void color_flip(Node *node) const {
        node->color = neg_color(node->color);
        node->lc->color = neg_color(node->lc->color);
        node->rc->color = neg_color(node->rc->color);
      }
    
      Node *insert(Node *root, const Key &key) const;
      Node *delete_arbitrary(Node *root, Key key) const;
      Node *delete_min(Node *root) const;
      Node *move_red_right(Node *root) const;
      Node *move_red_left(Node *root) const;
      Node *fix_up(Node *root) const;
      const Key &get_min(Node *root) const;
      void serialize(Node *root, std::vector<Key> *) const;
      void print_tree(Set::Node *root, int indent) const;
      Compare cmp_ = Compare();
      Node *root_{nullptr};
    
     public:
      using KeyType = Key;
      using ValueType = Key;
      using SizeType = std::size_t;
      using DifferenceType = std::ptrdiff_t;
      using KeyCompare = Compare;
      using ValueCompare = Compare;
      using Reference = Key &;
      using ConstReference = const Key &;
    
      Set() = default;
    
      Set(Set &) = default;
    
      Set(Set &&) noexcept = default;
    
      ~Set() { destroyTree(root_); }
    
      SizeType size() const;
    
      SizeType count(const KeyType &key) const;
    
      SizeType erase(const KeyType &key);
    
      void clear();
    
      void insert(const KeyType &key);
    
      bool empty() const;
    
      std::vector<Key> serialize() const;
    
      void print_tree() const;
    };
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::SizeType Set<Key, Compare>::count(
        ConstReference key) const {
      Node *x = root_;
      while (x != nullptr) {
        if (key == x->key) return 1;
        if (cmp_(key, x->key))  // if (key < x->key)
          x = x->lc;
        else
          x = x->rc;
      }
      return 0;
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::SizeType Set<Key, Compare>::erase(
        const KeyType &key) {
      if (count(key) > 0) {
        if (!is_red(root_->lc) && !(is_red(root_->rc))) root_->color = kRed;
        root_ = delete_arbitrary(root_, key);
        if (root_ != nullptr) root_->color = kBlack;
        return 1;
      } else {
        return 0;
      }
    }
    
    template <class Key, class Compare>
    void Set<Key, Compare>::clear() {
      destroyTree(root_);
      root_ = nullptr;
    }
    
    template <class Key, class Compare>
    void Set<Key, Compare>::insert(const KeyType &key) {
      root_ = insert(root_, key);
      root_->color = kBlack;
    }
    
    template <class Key, class Compare>
    bool Set<Key, Compare>::empty() const {
      return size(root_) == 0;
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::insert(
        Set::Node *root, const Key &key) const {
      if (root == nullptr) return new Node(key, kRed, 1);
      if (root->key == key)
        ;
      else if (cmp_(key, root->key))  // if (key < root->key)
        root->lc = insert(root->lc, key);
      else
        root->rc = insert(root->rc, key);
      return fix_up(root);
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::delete_min(
        Set::Node *root) const {
      if (root->lc == nullptr) {
        delete root;
        return nullptr;
      }
      if (!is_red(root->lc) && !is_red(root->lc->lc)) {
        // make sure either root->lc or root->lc->lc is red
        // thus make sure we will delete a red node in the end
        root = move_red_left(root);
      }
      root->lc = delete_min(root->lc);
      return fix_up(root);
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::move_red_right(
        Set::Node *root) const {
      color_flip(root);
      if (is_red(root->lc->lc)) {  // assume that root->lc != nullptr when calling
                                   // this function
        root = rotate_right(root);
        color_flip(root);
      }
      return root;
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::move_red_left(
        Set::Node *root) const {
      color_flip(root);
      if (is_red(root->rc->lc)) {
        // assume that root->rc != nullptr when calling this function
        root->rc = rotate_right(root->rc);
        root = rotate_left(root);
        color_flip(root);
      }
      return root;
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::fix_up(
        Set::Node *root) const {
      if (is_red(root->rc) && !is_red(root->lc))  // fix right leaned red link
        root = rotate_left(root);
      if (is_red(root->lc) &&
          is_red(root->lc->lc))  // fix doubly linked left leaned red link
        // if (root->lc == nullptr), then the second expr won't be evaluated
        root = rotate_right(root);
      if (is_red(root->lc) && is_red(root->rc))
        // break up 4 node
        color_flip(root);
      root->size = size(root->lc) + size(root->rc) + 1;
      return root;
    }
    
    template <class Key, class Compare>
    const Key &Set<Key, Compare>::get_min(Set::Node *root) const {
      Node *x = root;
      // will crash as intended when root == nullptr
      for (; x->lc != nullptr; x = x->lc);
      return x->key;
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::SizeType Set<Key, Compare>::size() const {
      return size(root_);
    }
    
    template <class Key, class Compare>
    typename Set<Key, Compare>::Node *Set<Key, Compare>::delete_arbitrary(
        Set::Node *root, Key key) const {
      if (cmp_(key, root->key)) {
        // key < root->key
        if (!is_red(root->lc) && !(is_red(root->lc->lc)))
          root = move_red_left(root);
        // ensure the invariant: either root->lc or root->lc->lc (or root and
        // root->lc after dive into the function) is red, to ensure we will
        // eventually delete a red node. therefore we will not break the black
        // height balance
        root->lc = delete_arbitrary(root->lc, key);
      } else {
        // key >= root->key
        if (is_red(root->lc)) root = rotate_right(root);
        if (key == root->key && root->rc == nullptr) {
          delete root;
          return nullptr;
        }
        if (!is_red(root->rc) && !is_red(root->rc->lc)) root = move_red_right(root);
        if (key == root->key) {
          root->key = get_min(root->rc);
          root->rc = delete_min(root->rc);
        } else {
          root->rc = delete_arbitrary(root->rc, key);
        }
      }
      return fix_up(root);
    }
    
    template <class Key, class Compare>
    std::vector<Key> Set<Key, Compare>::serialize() const {
      std::vector<int> v;
      serialize(root_, &v);
      return v;
    }
    
    template <class Key, class Compare>
    void Set<Key, Compare>::serialize(Set::Node *root,
                                      std::vector<Key> *res) const {
      if (root == nullptr) return;
      serialize(root->lc, res);
      res->push_back(root->key);
      serialize(root->rc, res);
    }
    
    template <class Key, class Compare>
    void Set<Key, Compare>::print_tree(Set::Node *root, int indent) const {
      if (root == nullptr) return;
      print_tree(root->lc, indent + 4);
      std::cout << std::string(indent, '-') << root->key << std::endl;
      print_tree(root->rc, indent + 4);
    }
    
    template <class Key, class Compare>
    void Set<Key, Compare>::print_tree() const {
      print_tree(root_, 0);
    }
    ```

## Quan hệ với cây 2-3

Cây 2-3 là cây B bậc 3. Mỗi nút là nút 2 hoặc nút 3, lưu trữ một hoặc hai phần tử dữ liệu. Nút 2 và nút 3 không phải lá lần lượt chỉ có thể có hai hoặc ba con. Ngoài ra, tất cả dữ liệu được lưu trong cây 2-3 đều có thứ tự.

Về bản chất, cây 2-3 và cây đỏ-đen nghiêng trái là tương đương. Trong cây 2-3, một nút có thể lưu 1 phần tử hoặc 2 phần tử, còn một nút trong cây đỏ-đen chỉ có thể lưu một phần tử. Như hình dưới đây, nút 2 của cây 2-3 tương ứng với một nút đen, còn nút 3 tương ứng với một nút đỏ và một nút đen. Có thể xem `b` và `c` là song song.

![Nút 2 của cây 2-3 tương ứng với nút đen](images/2-3-tree-rbt-1.svg)

![Nút 3 của cây 2-3 tương ứng với liên kết đỏ nghiêng trái](images/2-3-tree-rbt-2.svg)

Hình dưới đây là cây đỏ-đen nghiêng trái tương ứng với một cây 2-3.

![Cây 2-3 và cây đỏ-đen nghiêng trái tương ứng](images/2-3-tree-rbt-3.svg)

Các thao tác chèn và xóa của cây 2-3 và cây đỏ-đen nghiêng trái tương ứng một-một với nhau.[^23-vs-llrbt]

## Tài liệu tham khảo và đọc thêm

-   [Left-Leaning Red-Black Trees](https://sedgewick.io/wp-content/themes/sedgewick/papers/2008LLRB.pdf)-  Robert Sedgewick Princeton University
-   [Balanced Search Trees](https://algs4.cs.princeton.edu/lectures/keynote/33BalancedSearchTrees-2x2.pdf)-\_Algorithms\_Robert Sedgewick | Kevin Wayne

[^23-vs-llrbt]: [Bài viết này](https://riteme.site/blog/2016-3-12/2-3-tree-and-red-black-tree.html) cung cấp mô tả chi tiết. "Cây đỏ-đen" trong bài viết đó thực chất chỉ "cây đỏ-đen nghiêng trái".
