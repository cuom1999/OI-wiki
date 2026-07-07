/**
 * @brief Cài đặt map dựa trên AVLTree
 * @details Map được sắp xếp theo thứ tự tự nhiên của khóa hoặc theo hàm
 *  {@code Compare} được cung cấp; cài đặt này bảo đảm chi phí thời gian
 *  log(n) cho các thao tác contains, get, insert và remove.
 */

#ifndef AVLTREE_MAP_HPP
#define AVLTREE_MAP_HPP

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

/**
 * Cài đặt map dựa trên AVLTree
 * https://en.wikipedia.org/wiki/AVL_tree
 * @tparam Key kiểu khóa được map này quản lý
 * @tparam Value kiểu giá trị được ánh xạ
 * @tparam Compare hàm so sánh
 */
template <typename Key, typename Value, typename Compare = std::less<Key> >
class AvlTreeMap {
 private:
  using USize = size_t;
  using Factor = int64_t;

  Compare compare = Compare();

 public:
  struct Entry {
    Key key;
    Value value;

    bool operator==(const Entry &rhs) const noexcept {
      return this->key == rhs.key && this->value == rhs.value;
    }

    bool operator!=(const Entry &rhs) const noexcept {
      return this->key != rhs.key || this->value != rhs.value;
    }
  };

 private:
  struct Node {
    using Ptr = std::shared_ptr<Node>;
    using Provider = const std::function<Ptr(void)> &;
    using Consumer = const std::function<void(const Ptr &)> &;

    Key key;
    Value value{};

    Ptr left = nullptr;
    Ptr right = nullptr;

    USize height = 1;

    explicit Node(Key k) : key(std::move(k)) {}

    explicit Node(Key k, Value v) : key(std::move(k)), value(std::move(v)) {}

    ~Node() = default;

    inline bool isLeaf() const noexcept {
      return this->left == nullptr && this->right == nullptr;
    }

    inline void updateHeight() noexcept {
      if (this->isLeaf()) {
        this->height = 1;
      } else if (this->left == nullptr) {
        this->height = this->right->height + 1;
      } else if (this->right == nullptr) {
        this->height = this->left->height + 1;
      } else {
        this->height = std::max(left->height, right->height) + 1;
      }
    }

    inline Factor factor() const noexcept {
      if (this->isLeaf()) {
        return 0;
      } else if (this->left == nullptr) {
        return (Factor)this->right->height;
      } else if (this->right == nullptr) {
        return (Factor) - this->left->height;
      } else {
        return (Factor)(this->right->height - this->left->height);
      }
    }

    inline Entry entry() const { return Entry{key, value}; }

    static Ptr from(const Key &k) { return std::make_shared<Node>(Node(k)); }

    static Ptr from(const Key &k, const Value &v) {
      return std::make_shared<Node>(Node(k, v));
    }
  };

  using NodePtr = typename Node::Ptr;
  using ConstNodePtr = const NodePtr &;
  using NodeProvider = typename Node::Provider;
  using NodeConsumer = typename Node::Consumer;

  NodePtr root = nullptr;
  USize count = 0;

  using K = const Key &;
  using V = const Value &;

 public:
  using EntryList = std::vector<Entry>;
  using KeyValueConsumer = const std::function<void(K, V)> &;
  using MutKeyValueConsumer = const std::function<void(K, Value &)> &;
  using KeyValueFilter = const std::function<bool(K, V)> &;

  class NoSuchMappingException : protected std::exception {
   private:
    const char *message;

   public:
    explicit NoSuchMappingException(const char *msg) : message(msg) {}

    const char *what() const noexcept override { return message; }
  };

  AvlTreeMap() noexcept = default;

  /**
   * Trả về số mục trong map này.
   * @return size_t
   */
  inline USize size() const noexcept { return this->count; }

  /**
   * Trả về true nếu tập hợp này không chứa phần tử nào.
   * @return bool
   */
  inline bool empty() const noexcept { return this->count == 0; }

  /**
   * Xóa toàn bộ phần tử khỏi map này.
   */
  void clear() noexcept {
    this->root = nullptr;
    this->count = 0;
  }

  /**
   * Trả về giá trị mà khóa chỉ định được ánh xạ tới; nếu map này không chứa
   * ánh xạ cho khóa đó, một {@code NoSuchMappingException} sẽ được ném ra.
   * @param key
   * @return AvlTreeMap<Key, Value>::Value
   * @throws NoSuchMappingException
   */
  Value get(K key) const {
    if (this->root == nullptr) {
      throw NoSuchMappingException("Invalid key");
    } else {
      NodePtr node = this->getNode(this->root, key);
      if (node != nullptr) {
        return node->value;
      } else {
        throw NoSuchMappingException("Invalid key");
      }
    }
  }

  /**
   * Trả về giá trị mà khóa chỉ định được ánh xạ tới; nếu map này không chứa
   * ánh xạ cho khóa đó, một ánh xạ mới với giá trị mặc định sẽ được chèn.
   * @param key
   * @return AvlTreeMap<Key, Value>::Value &
   */
  Value &getOrDefault(K key) {
    if (this->root == nullptr) {
      this->root = Node::from(key);
      this->count += 1;
      return this->root->value;
    } else {
      return this
          ->getNodeOrProvide(this->root, key,
                             [&key]() { return Node::from(key); })
          ->value;
    }
  }

  /**
   * Trả về true nếu map này chứa ánh xạ cho khóa chỉ định.
   * @param key
   * @return bool
   */
  bool contains(K key) const {
    return this->getNode(this->root, key) != nullptr;
  }

  /**
   * Gắn giá trị chỉ định với khóa chỉ định trong map này.
   * @param key
   * @param value
   */
  void insert(K key, V value) {
    if (this->root == nullptr) {
      this->root = Node::from(key, value);
      this->count += 1;
    } else {
      this->insert(this->root, key, value);
    }
  }

  /**
   * Nếu khóa chỉ định chưa được gắn với giá trị nào, gắn nó với giá trị đã cho
   * và trả về true; ngược lại trả về false.
   * @param key
   * @param value
   * @return bool
   */
  bool insertIfAbsent(K key, V value) {
    USize sizeBeforeInsertion = this->size();
    if (this->root == nullptr) {
      this->root = Node::from(key, value);
      this->count += 1;
    } else {
      this->insert(this->root, key, value, false);
    }
    return this->size() > sizeBeforeInsertion;
  }

  /**
   * Nếu khóa chỉ định chưa được gắn với giá trị nào, gắn nó với giá trị đã cho
   * và trả về giá trị đó; ngược lại trả về giá trị đã được gắn.
   * @param key
   * @param value
   * @return
   */
  Value &getOrInsert(K key, V value) {
    if (this->root == nullptr) {
      this->root = Node::from(key, value);
      this->count += 1;
      return root->value;
    } else {
      NodePtr node = getNodeOrProvide(this->root, key,
                                      [&]() { return Node::from(key, value); });
      return node->value;
    }
  }

  Value operator[](K key) const { return this->get(key); }

  Value &operator[](K key) { return this->getOrDefault(key); }

  /**
   * Xóa ánh xạ của một khóa khỏi map này nếu ánh xạ tồn tại;
   * trả về true nếu ánh xạ tồn tại, ngược lại trả về false.
   * @param key khóa của ánh xạ
   * @return bool
   */
  bool remove(K key) {
    if (this->root == nullptr) {
      return false;
    } else {
      return this->remove(this->root, key, [](ConstNodePtr) {});
    }
  }

  /**
   * Xóa ánh xạ của một khóa khỏi map này nếu ánh xạ tồn tại và trả về giá trị
   * được ánh xạ tới khóa đó; nếu map này không chứa ánh xạ cho khóa đó, một
   * {@code NoSuchMappingException} sẽ được ném ra.
   * @param key
   * @return AvlTreeMap<Key, Value>::Value
   * @throws NoSuchMappingException
   */
  Value getAndRemove(K key) {
    Value result;
    NodeConsumer action = [&](ConstNodePtr node) { result = node->value; };

    if (root == nullptr) {
      throw NoSuchMappingException("Invalid key");
    } else {
      if (remove(this->root, key, action)) {
        return result;
      } else {
        throw NoSuchMappingException("Invalid key");
      }
    }
  }

  /**
   * Lấy mục tương ứng với khóa chỉ định; nếu không có mục như vậy, trả về mục
   * ứng với khóa nhỏ nhất lớn hơn khóa chỉ định; nếu vẫn không có mục như vậy
   * (tức khóa lớn nhất trong cây nhỏ hơn khóa chỉ định), một
   * {@code NoSuchMappingException} sẽ được ném ra.
   * @param key
   * @return AvlTreeMap<Key, Value>::Entry
   * @throws NoSuchMappingException
   */
  Entry getCeilingEntry(K key) const {
    if (this->root == nullptr) {
      throw NoSuchMappingException("No ceiling entry in this map");
    }

    NodePtr node = this->root;
    std::stack<NodePtr> ancestors;

    while (node != nullptr) {
      if (key == node->key) {
        return node->entry();
      }

      if (compare(key, node->key)) {
        /* key < node->key */
        if (node->left != nullptr) {
          ancestors.push(node);
          node = node->left;
        } else {
          return node->entry();
        }
      } else {
        /* key > node->key */
        if (node->right != nullptr) {
          ancestors.push(node);
          node = node->right;
        } else {
          if (ancestors.empty()) {
            throw NoSuchMappingException("No ceiling entry in this map");
          }

          NodePtr parent = ancestors.top();
          ancestors.pop();

          while (node == parent->right) {
            node = parent;
            if (!ancestors.empty()) {
              parent = ancestors.top();
              ancestors.pop();
            } else {
              throw NoSuchMappingException("No ceiling entry in this map");
            }
          }

          return parent->entry();
        }
      }
    }

    throw NoSuchMappingException("No ceiling entry in this map");
  }

  /**
   * Lấy mục tương ứng với khóa chỉ định; nếu không có mục như vậy, trả về mục
   * ứng với khóa lớn nhất nhỏ hơn khóa chỉ định; nếu vẫn không có mục như vậy,
   * một {@code NoSuchMappingException} sẽ được ném ra.
   * @param key
   * @return AvlTreeMap<Key, Value>::Entry
   * @throws NoSuchMappingException
   */
  Entry getFloorEntry(K key) const {
    if (this->root == nullptr) {
      throw NoSuchMappingException("No floor entry exists in this map");
    }

    NodePtr node = this->root;
    std::stack<NodePtr> ancestors;

    while (node != nullptr) {
      if (key == node->key) {
        return node->entry();
      }

      if (compare(key, node->key)) {
        /* key < node->key */
        if (node->left != nullptr) {
          ancestors.push(node);
          node = node->left;
        } else {
          if (ancestors.empty()) {
            throw NoSuchMappingException("No floor entry exists in this map");
          }

          NodePtr parent = ancestors.top();
          ancestors.pop();

          while (node == parent->left) {
            node = parent;
            if (!ancestors.empty()) {
              parent = ancestors.top();
              ancestors.pop();
            } else {
              throw NoSuchMappingException("No floor entry exists in this map");
            }
          }

          return parent->entry();
        }
      } else {
        /* key > node->key */
        if (node->right != nullptr) {
          ancestors.push(node);
          node = node->right;
        } else {
          return node->entry();
        }
      }
    }

    throw NoSuchMappingException("No floor entry exists in this map");
  }

  /**
   * Lấy mục ứng với khóa nhỏ nhất lớn hơn khóa chỉ định; nếu không có mục như
   * vậy, một {@code NoSuchMappingException} sẽ được ném ra.
   * @param key
   * @return AvlTreeMap<Key, Value>::Entry
   * @throws NoSuchMappingException
   */
  Entry getHigherEntry(K key) {
    if (this->root == nullptr) {
      throw NoSuchMappingException("No higher entry exists in this map");
    }

    NodePtr node = this->root;
    std::stack<NodePtr> ancestors;

    while (node != nullptr) {
      if (compare(key, node->key)) {
        /* key < node->key */
        if (node->left != nullptr) {
          ancestors.push(node);
          node = node->left;
        } else {
          return node->entry();
        }
      } else {
        /* key >= node->key */
        if (node->right != nullptr) {
          ancestors.push(node);
          node = node->right;
        } else {
          if (ancestors.empty()) {
            throw NoSuchMappingException("No higher entry exists in this map");
          }

          NodePtr parent = ancestors.top();
          ancestors.pop();

          while (node == parent->right) {
            node = parent;
            if (!ancestors.empty()) {
              parent = ancestors.top();
              ancestors.pop();
            } else {
              throw NoSuchMappingException(
                  "No higher entry exists in this map");
            }
          }

          return parent->entry();
        }
      }
    }

    throw NoSuchMappingException("No higher entry exists in this map");
  }

  /**
   * Trả về mục ứng với khóa lớn nhất nhỏ hơn khóa chỉ định; nếu không có mục
   * như vậy (tức khóa nhỏ nhất trong cây lớn hơn khóa chỉ định), một
   * {@code NoSuchMappingException} sẽ được ném ra.
   * @param key
   * @return AvlTreeMap<Key, Value>::Entry
   * @throws NoSuchMappingException
   */
  Entry getLowerEntry(K key) const {
    if (this->root == nullptr) {
      throw NoSuchMappingException("No lower entry exists in this map");
    }

    NodePtr node = this->root;
    std::stack<NodePtr> ancestors;

    while (node != nullptr) {
      if (compare(key, node->key) || key == node->key) {
        /* key <= node->key */
        if (node->left != nullptr) {
          ancestors.push(node);
          node = node->left;
        } else {
          if (ancestors.empty()) {
            throw NoSuchMappingException("No lower entry exists in this map");
          }

          NodePtr parent = ancestors.top();
          ancestors.pop();

          while (node == parent->left) {
            node = parent;
            if (!ancestors.empty()) {
              parent = ancestors.top();
              ancestors.pop();
            } else {
              throw NoSuchMappingException("No lower entry exists in this map");
            }
          }

          return parent->entry();
        }
      } else {
        /* key > node->key */
        if (node->right != nullptr) {
          ancestors.push(node);
          node = node->right;
        } else {
          return node->entry();
        }
      }
    }

    throw NoSuchMappingException("No lower entry exists in this map");
  }

  /**
   * Xóa toàn bộ mục thỏa điều kiện lọc.
   * @param filter
   */
  void removeAll(KeyValueFilter filter) {
    std::vector<Key> keys;
    this->inorderTraversal([&](ConstNodePtr node) {
      if (filter(node->key, node->value)) {
        keys.push_back(node->key);
      }
    });
    for (const Key &key : keys) {
      this->remove(key);
    }
  }

  /**
   * Thực hiện hành động đã cho cho từng mục khóa và giá trị trong map này.
   * Giá trị là bất biến đối với hành động này.
   * @param action
   */
  void forEach(KeyValueConsumer action) const {
    this->inorderTraversal(
        [&](ConstNodePtr node) { action(node->key, node->value); });
  }

  /**
   * Thực hiện hành động đã cho cho từng mục khóa và giá trị trong map này.
   * Giá trị có thể thay đổi đối với hành động này.
   * @param action
   */
  void forEachMut(MutKeyValueConsumer action) {
    this->inorderTraversal(
        [&](ConstNodePtr node) { action(node->key, node->value); });
  }

  /**
   * Trả về danh sách chứa toàn bộ mục trong map này.
   * @return AvlTreeMap<Key, Value>::EntryList
   */
  EntryList toEntryList() const {
    EntryList entryList;
    this->inorderTraversal(
        [&](ConstNodePtr node) { entryList.push_back(node->entry()); });
    return entryList;
  }

 private:
  static NodePtr rotateLeft(ConstNodePtr node) {
    // clang-format off
    //     |                       |
    //     N                       S
    //    / \     xoay trái(N)    / \
    //   L   S    ==========>    N   R
    //      / \                 / \
    //     M   R               L   M
    NodePtr successor = node->right;
    // clang-format on
    node->right = successor->left;
    successor->left = node;

    node->updateHeight();
    successor->updateHeight();

    return successor;
  }

  static NodePtr rotateRight(ConstNodePtr node) {
    // clang-format off
    //       |                   |
    //       N                   S
    //      / \   xoay phải(N)  / \
    //     S   R  ==========>  L   N
    //    / \                     / \
    //   L   M                   M   R
    NodePtr successor = node->left;
    // clang-format on
    node->left = successor->right;
    successor->right = node;

    node->updateHeight();
    successor->updateHeight();

    return successor;
  }

  static void swapNode(NodePtr &lhs, NodePtr &rhs) {
    std::swap(lhs->key, rhs->key);
    std::swap(lhs->value, rhs->value);
    std::swap(lhs, rhs);
  }

  static void fixBalance(NodePtr &node) {
    if (node->factor() < -1) {
      if (node->left->factor() < 0) {
        // clang-format off
        //  Trường hợp trái-trái
        //       |
        //       C                 |
        //      /   xoay phải(C)   B
        //     B    ==========>   / \
        //    /                  A   C
        //   A
        // clang-format on
        node = rotateRight(node);
      } else {
        // clang-format off
        //  Trường hợp trái-phải
        //     |                   |
        //     C                   C                 |
        //    /   xoay trái(A)    /   xoay phải(C)   B
        //   A    ==========>    B    ==========>   / \
        //    \                 /                  A   C
        //     B               A
        // clang-format on
        node->left = rotateLeft(node->left);
        node = rotateRight(node);
      }
    } else if (node->factor() > 1) {
      if (node->right->factor() > 0) {
        // clang-format off
        //  Trường hợp phải-phải
        //   |
        //   C                     |
        //    \     xoay trái(C)   B
        //     B    ==========>   / \
        //      \                A   C
        //       A
        // clang-format on
        node = rotateLeft(node);
      } else {
        // clang-format off
        //  Trường hợp phải-trái
        //   |                 |
        //   A                 A                     |
        //    \   xoay phải(C)  \     xoay trái(A)   B
        //     C  ==========>    B    ==========>   / \
        //    /                   \                A   C
        //   B                     C
        // clang-format on
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
      }
    }
  }

  NodePtr getNodeOrProvide(NodePtr &node, K key, NodeProvider provide) {
    assert(node != nullptr);

    if (key == node->key) {
      return node;
    }

    assert(key != node->key);

    NodePtr result;

    if (compare(key, node->key)) {
      /* key < node->key */
      if (node->left == nullptr) {
        result = node->left = provide();
        this->count += 1;
        node->updateHeight();
      } else {
        result = getNodeOrProvide(node->left, key, provide);
        node->updateHeight();
        fixBalance(node);
      }
    } else {
      /* key > node->key */
      if (node->right == nullptr) {
        result = node->right = provide();
        this->count += 1;
        node->updateHeight();
      } else {
        result = getNodeOrProvide(node->right, key, provide);
        node->updateHeight();
        fixBalance(node);
      }
    }

    return result;
  }

  NodePtr getNode(ConstNodePtr node, K key) const {
    assert(node != nullptr);

    if (key == node->key) {
      return node;
    }

    if (compare(key, node->key)) {
      /* key < node->key */
      return node->left == nullptr ? nullptr : getNode(node->left, key);
    } else {
      /* key > node->key */
      return node->right == nullptr ? nullptr : getNode(node->right, key);
    }
  }

  void insert(NodePtr &node, K key, V value, bool replace = true) {
    assert(node != nullptr);

    if (key == node->key) {
      if (replace) {
        node->value = value;
      }
      return;
    }

    assert(key != node->key);

    if (compare(key, node->key)) {
      /* key < node->key */
      if (node->left == nullptr) {
        node->left = Node::from(key, value);
        this->count += 1;
        node->updateHeight();
      } else {
        insert(node->left, key, value, replace);
        node->updateHeight();
        fixBalance(node);
      }
    } else {
      /* key > node->key */
      if (node->right == nullptr) {
        node->right = Node::from(key, value);
        this->count += 1;
        node->updateHeight();
      } else {
        insert(node->right, key, value, replace);
        node->updateHeight();
        fixBalance(node);
      }
    }
  }

  bool remove(NodePtr &node, K key, NodeConsumer action) {
    assert(node != nullptr);

    if (key != node->key) {
      if (compare(key, node->key)) {
        /* key < node->key */
        NodePtr &left = node->left;
        if (left != nullptr && remove(left, key, action)) {
          node->updateHeight();
          fixBalance(node);
          return true;
        } else {
          return false;
        }
      } else {
        /* key > node->key */
        NodePtr &right = node->right;
        if (right != nullptr && remove(right, key, action)) {
          node->updateHeight();
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
      // clang-format off
      // Trường hợp 2: chỉ có con trái
      //     P
      //     |  xóa(N)     P
      //     N  ========>  |
      //    /              L
      //   L
      // clang-format on
      node = node->left;
      node->updateHeight();
    } else if (node->left == nullptr) {
      // clang-format off
      // Trường hợp 3: chỉ có con phải
      //   P
      //   |    xóa(N)     P
      //   N    ========>  |
      //    \              R
      //     R
      // clang-format on
      node = node->right;
      node->updateHeight();
    } else if (node->right->left == nullptr) {
      // clang-format off
      // Trường hợp 4: có cả con trái và con phải, con phải không có con trái
      //    |                 |
      //    N    xóa(N)       R
      //   / \   ========>   /
      //  L   R             L
      // clang-format on
      NodePtr right = node->right;
      swapNode(node, right);
      right->right = node->right;
      node = right;
      node->updateHeight();
      fixBalance(node);
    } else {
      // clang-format off
      // Trường hợp 5: có cả con trái và con phải, con phải không phải lá
      //   Bước 1. tìm nút N có khóa nhỏ nhất
      //           và cha P của nó trong cây con phải
      //   Bước 2. hoán đổi S và N
      //   Bước 3. xóa nút N như trường hợp 1 hoặc trường hợp 3
      //   Bước 4. cập nhật chiều cao cho P
      //     |                  |
      //     N                  S                 |
      //    / \                / \                S
      //   L  ..  đổi(N, S)   L  ..  xóa(N)      / \
      //       |  =========>      |  ========>  L  ..
      //       P                  P                 |
      //      / \                / \                P
      //     S  ..              N  ..              / \
      //      \                  \                R  ..
      //       R                  R
      // clang-format on

      // Bước 1
      NodePtr successor = node->right;
      NodePtr parent = node;
      while (successor->left != nullptr) {
        parent = successor;
        successor = parent->left;
      }
      // Bước 2
      swapNode(node, successor);
      // Bước 3
      parent->left = node->right;
      // Khôi phục nút
      node = successor;
      // Bước 4
      parent->updateHeight();
    }

    this->count -= 1;
    return true;
  }

  void inorderTraversal(NodeConsumer action) const {
    if (this->root == nullptr) {
      return;
    }

    std::stack<NodePtr> stack;
    NodePtr node = this->root;

    while (node != nullptr || !stack.empty()) {
      while (node != nullptr) {
        stack.push(node);
        node = node->left;
      }
      if (!stack.empty()) {
        node = stack.top();
        stack.pop();
        action(node);
        node = node->right;
      }
    }
  }
};

#endif  // AVLTREE_MAP_HPP
