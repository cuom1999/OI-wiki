author: 2323122, aofall, AtomAlpaca, Bocity, CoelacanthusHex, countercurrent-time, Early0v0, Enter-tainer, fearlessxjdx, Great-designer, H-J-Granger, hsfzLZH1, iamtwz, Ir1d, ksyx, Marcythm, NachtgeistW, ouuan, Persdre, shuzhouliu, StudyingFather, SukkaW, Tiphereth-A, wsyhb, Yesphet, yuhuoji, lingkerio, bililateral, q-wind

## Định nghĩa

Cây tìm kiếm nhị phân (binary search tree, viết tắt là BST) là một cấu trúc cây nhị phân được định nghĩa như sau:

1.  Cây rỗng là một cây tìm kiếm nhị phân.

2.  Nếu cây con trái của một cây tìm kiếm nhị phân không rỗng, mọi khóa trong cây con trái đều nhỏ hơn khóa của nút gốc.

3.  Nếu cây con phải của một cây tìm kiếm nhị phân không rỗng, mọi khóa trong cây con phải đều lớn hơn khóa của nút gốc.

4.  Hai cây con trái và phải của một cây tìm kiếm nhị phân cũng đều là cây tìm kiếm nhị phân.

Thời gian của các thao tác cơ bản trên cây tìm kiếm nhị phân tỉ lệ với chiều cao của cây.
Với một cây có $n$ nút, độ phức tạp tốt nhất của các thao tác này là $O(\log n)$, còn xấu nhất là $O(n)$.
Nếu xây dựng cây tìm kiếm nhị phân theo thứ tự ngẫu nhiên, chiều cao kỳ vọng là $O(\log n)$.

## Quy trình

### Định nghĩa nút của cây tìm kiếm nhị phân

???+ note "Cài đặt"
    ```cpp
    struct TreeNode {
      int key;
      TreeNode* left;
      TreeNode* right;
      // Duy trì các thông tin khác, như chiều cao, số nút, ...
      int size;   // Kích thước cây con có nút hiện tại làm gốc
      int count;  // Số lần xuất hiện của khóa tại nút hiện tại
    
      TreeNode(int value)
          : key(value), size(1), count(1), left(nullptr), right(nullptr) {}
    };
    ```

### Duyệt cây tìm kiếm nhị phân

Từ định nghĩa đệ quy của cây tìm kiếm nhị phân,
dãy khóa thu được khi duyệt trung thứ tự (inorder traversal) là một dãy không giảm.
Độ phức tạp thời gian là $O(n)$.

Đoạn mã duyệt một cây tìm kiếm nhị phân như sau:

???+ note "Cài đặt"
    ```cpp
    void inorderTraversal(TreeNode* root) {
      if (root == nullptr) {
        return;
      }
      inorderTraversal(root->left);
      std::cout << root->key << " ";
      inorderTraversal(root->right);
    }
    ```

### Tìm giá trị nhỏ nhất/lớn nhất

Theo tính chất của cây tìm kiếm nhị phân, giá trị nhỏ nhất nằm ở nút cuối của đường đi liên tục sang trái,
còn giá trị lớn nhất nằm ở nút cuối của đường đi liên tục sang phải.
Độ phức tạp thời gian là $O(h)$.

???+ note "Cài đặt"
    ```cpp
    int findMin(TreeNode* root) {
      if (root == nullptr) {
        return -1;
      }
      while (root->left != nullptr) {
        root = root->left;
      }
      return root->key;
    }
    
    int findMax(TreeNode* root) {
      if (root == nullptr) {
        return -1;
      }
      while (root->right != nullptr) {
        root = root->right;
      }
      return root->key;
    }
    ```

### Tìm kiếm phần tử

Tìm một nút có giá trị `value` trong cây tìm kiếm nhị phân gốc `root`.

Xét các trường hợp sau:

-   Nếu `root` rỗng, trả về `false`.
-   Nếu khóa của `root` bằng `value`, trả về `true`.
-   Nếu khóa của `root` lớn hơn `value`, tiếp tục tìm trong cây con trái của `root`.
-   Nếu khóa của `root` nhỏ hơn `value`, tiếp tục tìm trong cây con phải của `root`.

Độ phức tạp thời gian là $O(h)$.

???+ note "Cài đặt"
    ```cpp
    bool search(TreeNode* root, int target) {
      if (root == nullptr) {
        return false;
      }
      if (root->key == target) {
        return true;
      } else if (target < root->key) {
        return search(root->left, target);
      } else {
        return search(root->right, target);
      }
    }
    ```

Các thao tác chèn, xóa và cập nhật thường đều cần tìm kiếm trong cây tìm kiếm nhị phân trước.

### Chèn một phần tử

Chèn một nút có giá trị `value` vào cây tìm kiếm nhị phân gốc `root`.

Xét các trường hợp sau:

-   Nếu `root` rỗng, trả về trực tiếp một nút mới có giá trị `value`.

-   Nếu khóa của `root` bằng `value`, tăng trường phụ lưu số lần xuất hiện của giá trị này thêm $1$.

-   Nếu khóa của `root` lớn hơn `value`, chèn nút có khóa `value` vào cây con trái của `root`.

-   Nếu khóa của `root` nhỏ hơn `value`, chèn nút có khóa `value` vào cây con phải của `root`.

Độ phức tạp thời gian là $O(h)$.

???+ note "Cài đặt"
    ```cpp
    TreeNode* insert(TreeNode* root, int value) {
      if (root == nullptr) {
        return new TreeNode(value);
      }
      if (value < root->key) {
        root->left = insert(root->left, value);
      } else if (value > root->key) {
        root->right = insert(root->right, value);
      } else {
        root->count++;  // Khóa bằng nhau, tăng số lần xuất hiện
      }
      root->size = root->count + (root->left ? root->left->size : 0) +
                   (root->right ? root->right->size : 0);  // Cập nhật kích thước cây con
      return root;
    }
    ```

### Xóa một phần tử

Xóa một nút có giá trị `value` khỏi cây tìm kiếm nhị phân gốc `root`.

Trước tiên tìm nút có khóa `value` trong cây tìm kiếm nhị phân, rồi xét các trường hợp sau:

-   Nếu trường phụ `count` của nút này lớn hơn $1$, chỉ cần giảm `count`.

-   Nếu trường phụ `count` của nút này bằng $1$:

    -   Nếu `root` là nút lá, chỉ cần xóa nút đó.

    -   Nếu `root` chỉ có một nút con, trả về nút con đó.

    -   Nếu `root` có cả hai con không rỗng, thông thường thay nó bằng giá trị lớn nhất trong cây con trái
        (nút ngoài cùng bên phải của cây con trái) hoặc giá trị nhỏ nhất trong cây con phải
        (nút ngoài cùng bên trái của cây con phải), rồi xóa nút thay thế đó.

Độ phức tạp thời gian là $O(h)$.

???+ note "Cài đặt"
    Gọi `root = remove(root, 1)` nghĩa là xóa nút có giá trị 1 trong cây gốc `root`, rồi trả về gốc mới.
    
    ```cpp
    // Trả về gốc mới sau khi xóa value
    TreeNode* remove(TreeNode* root, int value) {
      if (root == nullptr) {
        return root;
      }
      if (value < root->key) {
        root->left = remove(root->left, value);
      } else if (value > root->key) {
        root->right = remove(root->right, value);
      } else {
        if (root->count > 1) {
          root->count--;  // Có nhiều bản sao, giảm số lần xuất hiện
        } else {
          if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
          } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
          } else {
            TreeNode* successor = findMinNode(root->right);
            root->key = successor->key;
            root->count = successor->count;  // Cập nhật số lần xuất hiện
            // Khi successor->count > 1, vẫn cần xóa nút này;
            // nếu không, lần xóa tiếp theo chỉ giảm số lần xuất hiện.
            successor->count = 1;
            root->right = remove(root->right, successor->key);
          }
        }
      }
      // Tiếp tục duy trì size, không viết thành --root->size;
      // vì value có thể không tồn tại trong cây, nên có thể không xóa gì.
      root->size = root->count + (root->left ? root->left->size : 0) +
                   (root->right ? root->right->size : 0);
      return root;
    }
    
    // Ví dụ này dùng giá trị nhỏ nhất trong cây con phải
    TreeNode* findMinNode(TreeNode* root) {
      while (root->left != nullptr) {
        root = root->left;
      }
      return root;
    }
    ```

### Tính thứ hạng của phần tử

Thứ hạng được định nghĩa là số phần tử đứng trước phần tử đầu tiên bằng nó trong dãy đã sắp xếp tăng dần, cộng thêm một.

Để tìm thứ hạng của một phần tử, bắt đầu từ gốc và đi xuống nút chứa phần tử đó.
Mỗi khi đi sang phải, cộng vào đáp án kích thước cây con trái và số lần xuất hiện của nút hiện tại.
Cuối cùng, cộng thêm kích thước cây con trái của nút đích và $1$.

Độ phức tạp thời gian là $O(h)$.

???+ note "Cài đặt"
    ```cpp
    int queryRank(TreeNode* root, int v) {
      if (root == nullptr) return 0;
      if (root->key == v) return (root->left ? root->left->size : 0) + 1;
      if (root->key > v) return queryRank(root->left, v);
      return queryRank(root->right, v) + (root->left ? root->left->size : 0) +
             root->count;
    }
    ```

### Tìm phần tử có thứ hạng k

Trong một cây con, thứ hạng của nút gốc phụ thuộc vào kích thước cây con trái của nó.

-   Nếu kích thước cây con trái lớn hơn hoặc bằng $k$, phần tử nằm trong cây con trái.

-   Nếu thứ hạng $k$ rơi vào phần các khóa bằng nút gốc
    (`count` là số lần xuất hiện của giá trị ở nút hiện tại), phần tử cần tìm chính là nút gốc của cây con.

-   Nếu kích thước cây con trái nhỏ hơn $k-\textit{count}$, phần tử nằm trong cây con phải.

Độ phức tạp thời gian là $O(h)$.

???+ note "Cài đặt"
    ```cpp
    int querykth(TreeNode* root, int k) {
      if (root == nullptr) return -1;  // Hoặc trả về giá trị phù hợp khác
      if (root->left) {
        if (root->left->size >= k) return querykth(root->left, k);
        if (root->left->size + root->count >= k) return root->key;
      } else {
        if (k <= root->count) return root->key;
      }
      return querykth(root->right,
                      k - (root->left ? root->left->size : 0) - root->count);
    }
    ```

## Giới thiệu về cây cân bằng

Một mục đích của việc dùng cây tìm kiếm là rút ngắn thời gian chèn, xóa, cập nhật và tìm kiếm nút.
Trong đó, các thao tác chèn, xóa, cập nhật đều bao gồm bước tìm kiếm.

Về hiệu quả tìm kiếm, nếu chiều cao của cây là $h$, trong trường hợp xấu nhất cần so sánh $h$ lần để tìm một khóa.
Độ phức tạp tìm kiếm, cũng là độ dài tìm kiếm trung bình ASL (Average Search Length), không vượt quá $O(h)$.
Với một cây tìm kiếm nhị phân lý tưởng, mọi thao tác có thể đạt $O(\log n)$, trong đó $n$ là tổng số nút.

Tuy nhiên, độ phức tạp $O(\log n)$ chỉ là tình huống lý tưởng.
Trong trường hợp xấu nhất, cây tìm kiếm có thể suy biến thành danh sách liên kết.
Chẳng hạn, nếu một cây tìm kiếm nhị phân có mỗi nút chỉ có con phải, nó hoạt động giống danh sách liên kết,
và mọi thao tác (chèn, xóa, sửa, tìm) đều mất $O(n)$.

Độ phức tạp của thao tác liên quan trực tiếp đến chiều cao $h$ của cây.
Vì vậy cần dùng cây cân bằng: dùng một số thao tác điều chỉnh để duy trì chiều cao,
hay tính cân bằng của cây, từ đó giảm độ phức tạp thao tác.

### Định nghĩa tính cân bằng

Việc một cây tìm kiếm có được xem là "**cân bằng**" hay không phụ thuộc vào định nghĩa của từng loại cây cân bằng.
Chẳng hạn, với một cây tìm kiếm nhị phân gốc $T$, nếu chiều cao cây con trái và cây con phải chênh lệch rất lớn,
hoặc số nút trong cây con trái lớn hơn rất nhiều so với cây con phải, thì cây đó không cân bằng.

Với cây tìm kiếm nhị phân, một định nghĩa cân bằng thường gặp là:
trong cây gốc $T$, tại mọi nút, độ chênh lệch chiều cao giữa cây con trái và cây con phải không vượt quá 1.

-   Trong [cây splay](splay.md), mỗi thao tác truy cập đến một nút bất kỳ (tìm kiếm, chèn hoặc xóa) đều đưa nút được
    truy cập lên vị trí gốc của cây.

-   [Cây AVL](avl.md) lưu thông tin chiều cao của cây gốc $N$ tại mỗi nút $N$.
    Định nghĩa cân bằng của cây AVL: $T$ là một cây AVL khi và chỉ khi hai cây con trái/phải cũng là cây AVL
    và $|height(T->left) - height(T->right)| \leq 1$.

-   [Cây cân bằng theo kích thước](sbt.md) duy trì `size`, tức số nút trong cây gốc $N$, tại mỗi nút $N$.
    Định nghĩa cân bằng: `size` của một nút bất kỳ không nhỏ hơn `size` của mọi nút cháu đi qua nút anh em của nó
    (nephew qua sibling).

Ngoài ra, với các cây tìm kiếm chứa cùng một tập giá trị, trạng thái cân bằng có thể không duy nhất.
Nói cách khác, có thể tồn tại hai cây tìm kiếm khác nhau, chứa cùng tập giá trị, và cả hai đều cân bằng.

### Quá trình điều chỉnh cân bằng

Với một cây tìm kiếm không thỏa điều kiện cân bằng,
có thể thực hiện các thao tác điều chỉnh để đưa cây trở lại trạng thái cân bằng.

Với cây nhị phân cân bằng, thao tác điều chỉnh cân bằng gồm hai loại:
**xoay trái (Left Rotate hoặc zag)** và **xoay phải (Right Rotate hoặc zig)**.
Khi điều chỉnh cây nhị phân cân bằng, cần giữ nguyên thứ tự duyệt trung thứ tự;
cả hai phép xoay này đều không làm thay đổi dãy trung thứ tự.

Trước hết xét phép xoay phải, còn gọi là "xoay đơn phải" hoặc "xoay cân bằng LL".
Xoay phải tại nút $A$ nghĩa là đưa con trái $B$ của $A$ lên trên để thay $A$ làm gốc,
đưa $A$ xuống thành gốc của cây con phải của $B$,
và cây con phải ban đầu của $B$ trở thành cây con trái của $A$.

![Phép xoay trong cây nhị phân cân bằng](images/bst-rotate.svg)

Phép xoay phải chỉ thay đổi ba nhóm liên kết giữa các nút, tương đương một phép hoán vị vòng trên ba cạnh;
vì vậy cần tạm lưu một nút rồi cập nhật lần lượt.

Thứ tự cập nhật thường dùng cho xoay phải là:
tạm lưu nút $B$ (gốc mới), cho con trái của $A$ trỏ đến cây con phải $T2$ của $B$,
cho con phải của $B$ trỏ đến $A$, rồi cuối cùng cho cha của $A$ trỏ đến $B$ đã tạm lưu.

Phép xoay trái hoàn toàn tương tự, còn được gọi là "xoay đơn trái" hoặc "xoay cân bằng RR".
Xoay trái là ảnh gương của xoay phải.

Mã cho xoay trái và xoay phải như sau.

???+ note "Cài đặt"
    ```cpp
    TreeNode* rotateLeft(TreeNode* root) {
      TreeNode* newRoot = root->right;
      root->right = newRoot->left;
      newRoot->left = root;
      // Cập nhật thông tin của các nút liên quan
      updateHeight(root);
      updateHeight(newRoot);
      return newRoot;  // Trả về gốc mới
    }
    
    TreeNode* rotateRight(TreeNode* root) {
      TreeNode* newRoot = root->left;
      root->left = newRoot->right;
      newRoot->right = root;
      updateHeight(root);
      updateHeight(newRoot);
      return newRoot;
    }
    ```

Với đoạn mã ví dụ này, khi gọi cần lưu nút cha `pre` của `root`.
Hàm trả về con trỏ đến gốc mới, nên chỉ cần cho `pre` trỏ đến gốc mới đó.

#### Bốn trường hợp phá vỡ cân bằng

Dù các loại cây nhị phân cân bằng có định nghĩa khác nhau,
khác biệt chủ yếu nằm ở thông tin được duy trì tại mỗi nút và cách cập nhật thông tin đó sau khi xoay.
Có đúng bốn kiểu phá vỡ cân bằng trong cây nhị phân cân bằng.
Các thao tác điều chỉnh cân bằng chỉ gồm xoay trái và xoay phải.
Phần dưới đây giới thiệu bốn trường hợp trước, rồi so sánh giữa các loại cây nhị phân cân bằng khác nhau.

Kiểu LL: cây con trái của con trái của $T$ quá dài, làm phá vỡ cân bằng.

Cách điều chỉnh: xoay phải tại nút $T$.

![Trường hợp mất cân bằng LL](images/bst-LL.svg)

Kiểu RR: tương tự kiểu LL, cây con phải của con phải của $T$ quá dài, làm phá vỡ cân bằng.

Cách điều chỉnh: xoay trái tại nút $T$.

![Trường hợp mất cân bằng RR](images/bst-RR.svg)

Kiểu LR: cây con phải của con trái của $T$ quá dài, làm phá vỡ cân bằng.

Cách điều chỉnh: xoay trái tại nút $L$ trước để chuyển thành kiểu LL, rồi xoay phải tại nút $T$.

![Trường hợp mất cân bằng LR](images/bst-LR.svg)

Kiểu RL: tương tự kiểu LR, cây con trái của con phải của $T$ quá dài, làm phá vỡ cân bằng.

Cách điều chỉnh: xoay phải tại nút $R$ trước để chuyển thành kiểu RR, rồi xoay trái tại nút $T$.

![Trường hợp mất cân bằng RL](images/bst-RL.svg)
