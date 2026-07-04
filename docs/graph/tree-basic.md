## Giới thiệu

Cây trong lý thuyết đồ thị trông giống cây trong đời thực, chỉ khác là khi xử lý bài toán, ta thường đặt gốc cây ở phía trên để xét. Cấu trúc dữ liệu này nhìn giống một cái cây bị treo ngược, nên được gọi là cây.

## Định nghĩa

Một cây không có nút gốc cố định được gọi là **cây không gốc** (unrooted tree). Cây không gốc có một số định nghĩa hình thức tương đương:

-   Đồ thị vô hướng liên thông có $n$ nút và $n-1$ cạnh.

-   Đồ thị vô hướng, không có chu trình và liên thông.

-   Đồ thị vô hướng trong đó giữa hai nút bất kỳ có đúng một đường đi đơn.

-   Đồ thị liên thông mà mọi cạnh đều là cầu.

-   Đồ thị không có chu trình, và nếu thêm một cạnh giữa hai điểm khác nhau bất kỳ thì đồ thị thu được chứa đúng một chu trình.

Trên cơ sở cây không gốc, nếu chỉ định một nút làm **gốc** thì ta thu được một **cây có gốc** (rooted tree). Cây có gốc trong nhiều trường hợp vẫn được biểu diễn bằng đồ thị vô hướng, chỉ là có quy ước quan hệ trên dưới giữa các nút. Xem chi tiết ở phần dưới.

## Các định nghĩa liên quan đến cây

### Áp dụng cho cây không gốc và cây có gốc

-   **Rừng** (forest): đồ thị mà mỗi thành phần liên thông đều là một cây. Theo định nghĩa, một cây cũng là một rừng.

-   **Cây khung** (spanning tree): đồ thị con sinh của một đồ thị vô hướng liên thông, đồng thời phải là một cây. Nói cách khác, chọn $n - 1$ cạnh từ tập cạnh của đồ thị để làm cho tất cả các đỉnh liên thông.

-   **Nút lá của cây không gốc** (leaf node): nút có bậc không vượt quá $1$.

    ???+ question "Tại sao không phải bậc đúng bằng $1$?"
        Hãy xét $n = 1$.

-   **Nút lá của cây có gốc** (leaf node): nút không có nút con.

### Chỉ áp dụng cho cây có gốc

-   **Cha** (parent node): với mỗi nút ngoài gốc, được định nghĩa là nút thứ hai trên đường đi từ nút đó đến gốc.
    Nút gốc không có nút cha.
-   **Tổ tiên** (ancestor): các nút trên đường đi từ một nút đến nút gốc, ngoại trừ chính nó.
    Tập tổ tiên của nút gốc là rỗng.
-   **Nút con** (child node): nếu $u$ là cha của $v$, thì $v$ là nút con của $u$.
    Thứ tự của các nút con thường không được phân biệt, ngoại trừ cây nhị phân.
-   **Độ sâu của nút** (depth): số cạnh trên đường đi đến nút gốc.
-   **Chiều cao của cây** (height): giá trị lớn nhất trong các độ sâu của mọi nút.
-   **Anh em** (sibling): nhiều nút con có cùng một cha là anh em của nhau.
-   **Hậu duệ** (descendant): nút con và các hậu duệ của nút con.
    Cũng có thể hiểu là: nếu $u$ là tổ tiên của $v$, thì $v$ là hậu duệ của $u$.

![tree-definition.svg](images/tree-definition.svg)

-   **Cây con** (subtree): sau khi xóa cạnh nối với cha, đó là đồ thị con chứa nút này.

    ![tree-definition-subtree.svg](images/tree-definition-subtree.svg)

## Các loại cây đặc biệt

-   **Chuỗi/đồ thị đường đi** (chain/path graph): cây trong đó số cạnh kề với mỗi nút không vượt quá $2$ được gọi là chuỗi.

-   **Cây sao** (star): cây mà tồn tại một nút $u$ sao cho mọi nút khác $u$ đều kề với $u$ được gọi là cây sao.

-   **Cây nhị phân có gốc** (rooted binary tree): cây có gốc mà mỗi nút có nhiều nhất hai con được gọi là cây nhị phân. Thường phân biệt thứ tự của hai nút con, lần lượt gọi là nút con trái và nút con phải.
    Trong phần lớn trường hợp, thuật ngữ **cây nhị phân** đều chỉ cây nhị phân có gốc.

-   **Cây nhị phân đầy đủ** (full/proper binary tree): cây nhị phân trong đó số nút con của mỗi nút đều là 0 hoặc 2. Nói cách khác, mỗi nút hoặc là lá, hoặc có cả cây con trái và cây con phải đều không rỗng.

    ![](images/tree-binary-proper.svg)

-   **Cây nhị phân hoàn chỉnh** (complete binary tree): chỉ các nút ở hai tầng dưới cùng có thể có bậc nhỏ hơn 2, và các nút ở tầng dưới cùng đều tập trung tại các vị trí liên tiếp ngoài cùng bên trái của tầng đó.

    ![](images/tree-binary-complete.svg)

-   **Cây nhị phân hoàn hảo** (perfect binary tree): cây nhị phân trong đó mọi nút lá có cùng độ sâu, và mọi nút không phải lá đều có đúng 2 nút con được gọi là cây nhị phân hoàn hảo.

    ![](images/tree-binary-perfect.svg)

???+ warning "Cảnh báo"
    Cách dịch proper binary tree không thống nhất; ngoài ra, định nghĩa của complete binary tree và full binary tree cũng khác nhau giữa các giáo trình. Khi gặp các thuật ngữ này, cần phán đoán theo ngữ cảnh.

Trong cộng đồng OI, cách gọi full binary tree thường chỉ perfect binary tree.

## Lưu trữ

### Chỉ ghi lại nút cha

Dùng một mảng `parent[N]` để ghi nút cha của mỗi nút.

Cách này cung cấp được khá ít thông tin, không thuận tiện cho việc duyệt từ trên xuống. Nó thường được dùng trong các bài toán quy hoạch truy hồi từ dưới lên.

### Danh sách kề

-   Với cây không gốc: tạo một danh sách tuyến tính cho mỗi nút để ghi lại mọi nút kề với nó.
    ```cpp
    std::vector<int> adj[N];
    ```
-   Với cây có gốc:
    -   Cách 1: nếu dữ liệu cho là đồ thị vô hướng, vẫn có thể lưu bằng dạng trên. Phần dưới sẽ giới thiệu cách phân biệt quan hệ trên dưới giữa các nút.
    -   Cách 2: nếu dữ liệu đầu vào có thể đảm bảo quan hệ trên dưới giữa các nút, thì có thể tận dụng thông tin này. Tạo một danh sách tuyến tính cho mỗi nút để ghi lại tất cả nút con của nó; nếu cần, cũng có thể ghi nút cha của nó trong một mảng khác.
        ```cpp
        std::vector<int> children[N];
        int parent[N];
        ```
        Tất nhiên cũng có thể dùng cách khác, chẳng hạn danh sách liên kết, để thay thế `std::vector`.

### Biểu diễn con trái, anh em phải

#### Quy trình

Với cây có gốc, tồn tại một cách biểu diễn đơn giản.

Trước hết, xác định một thứ tự tùy ý cho tất cả nút con của mỗi nút.

Sau đó, với mỗi nút, ghi lại hai giá trị: **nút con đầu tiên** `child[u]` của nó và **nút anh em kế tiếp** `sib[u]` của nó. Nếu không có nút con thì `child[u]` rỗng; nếu nút đó là nút con cuối cùng của nút cha, thì `sib[u]` rỗng.

#### Cài đặt

Có thể duyệt tất cả nút con của một nút như sau.

```cpp
int v = child[u];  // Bat dau tu nut con dau tien
while (v != EMPTY_NODE) {
  // ...
  // Xu ly nut con v
  // ...
  v = sib[v];  // Chuyen sang nut con ke tiep, tuc mot anh em cua v
}
```

Cũng có thể viết gọn thành dạng sau.

```cpp
for (int v = child[u]; v != EMPTY_NODE; v = sib[v]) {
  // ...
  // Xu ly nut con v
  // ...
}
```

### Cây nhị phân

Cần ghi lại nút con trái và nút con phải của mỗi nút.

???+ note "Cài đặt"
    ```cpp
    int parent[N];
    int lch[N], rch[N];
    // -- or --
    int child[N][2];
    ```

## Duyệt cây

### DFS trên cây

DFS trên cây là một quá trình như sau: trước tiên thăm nút gốc, sau đó lần lượt thăm cây con của từng con của nút gốc.

Có thể dùng để tìm độ sâu, nút cha và các thông tin khác của mỗi nút.

### Duyệt DFS trên cây nhị phân

#### Duyệt tiền thứ tự

![preorder](images/tree-basic-preorder.svg)

Duyệt cây nhị phân theo thứ tự **gốc, trái, phải**.

???+ note "Cài đặt"
    ```cpp
    void preorder(BiTree* root) {
      if (root) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
      }
    }
    ```

#### Duyệt trung thứ tự

![inorder](images/tree-basic-inorder.svg)

Duyệt cây nhị phân theo thứ tự **trái, gốc, phải**.

???+ note "Cài đặt"
    ```cpp
    void inorder(BiTree* root) {
      if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
      }
    }
    ```

#### Duyệt hậu thứ tự

![postorder](images/tree-basic-postorder.svg)

Duyệt cây nhị phân theo thứ tự **trái, phải, gốc**.

???+ note "Cài đặt"
    ```cpp
    void postorder(BiTree* root) {
      if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
      }
    }
    ```

#### Suy ngược

Khi đã biết dãy duyệt trung thứ tự và một dãy duyệt khác, có thể suy ra dãy duyệt thứ ba.

![reverse](images/tree-basic-reverse.svg)

1.  Phần tử đầu tiên của tiền thứ tự là `root`, phần tử cuối cùng của hậu thứ tự là `root`.
2.  Trước hết xác định nút gốc, sau đó dựa vào duyệt trung thứ tự: phần nằm bên trái gốc là cây con trái, phần nằm bên phải gốc là cây con phải.
3.  Với mỗi cây con, có thể xem nó là một cây hoàn toàn mới và vẫn tuân theo quy luật trên.

### BFS trên cây

Bắt đầu từ gốc cây và thăm các nút nghiêm ngặt theo từng tầng.

Trong quá trình BFS, cũng có thể đồng thời tìm độ sâu và nút cha của từng nút.

#### Duyệt cây theo mức

Duyệt cây theo mức là duyệt ngang từng nút theo từng tầng, dựa trên quan hệ tầng từ nút gốc đến nút lá. Theo định nghĩa của BFS, ta biết thứ tự duyệt thu được bằng BFS chính là một dạng duyệt theo mức. Tuy nhiên, duyệt theo mức yêu cầu phân biệt các tầng khác nhau, nên kết quả thường được biểu diễn dưới dạng mảng hai chiều.

Ví dụ, kết quả duyệt theo mức của cây trong hình dưới là `[[1], [2, 3, 4], [5, 6]]`, với mỗi tầng đi từ trái sang phải.

![tree-basic-levelOrder](images/tree-basic-levelOrder.svg)

???+ note "Cài đặt"
    ```cpp
    vector<vector<int>> levelOrder(Node* root) {
      if (!root) {
        return {};
      }
      vector<vector<int>> res;
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        int currentLevelSize = q.size();  // Số nút của tầng hiện tại
        res.push_back(vector<int>());
        for (int i = 0; i < currentLevelSize; ++i) {
          Node* cur = q.front();
          q.pop();
          res.back().push_back(cur->val);
          for (Node* child : cur->children) {  // Đưa tất cả nút con vào hàng đợi
            q.push(child);
          }
        }
      }
      return res;
    }
    ```

### Duyệt Morris trên cây nhị phân

Vấn đề cốt lõi khi duyệt cây nhị phân là: sau khi duyệt các nút con của nút hiện tại, làm thế nào để quay lại nút hiện tại và tiếp tục duyệt. Cả phương pháp đệ quy và phương pháp không đệ quy để duyệt cây nhị phân đều dùng cấu trúc ngăn xếp để ghi lại đường quay về, nhờ đó thực hiện việc di chuyển từ tầng dưới lên tầng trên. Độ phức tạp không gian của chúng tốt nhất là $O(\log n)$, xấu nhất là $O(n)$ khi cây nhị phân có dạng tuyến tính.

Bản chất của duyệt Morris là tránh dùng ngăn xếp, tận dụng con trỏ `right` đang rỗng của các nút tầng dưới để trỏ ngược về một nút nào đó ở tầng trên, từ đó hoàn thành việc di chuyển từ tầng dưới lên tầng trên.

#### Quy trình duyệt Morris

Giả sử ta đang ở nút hiện tại `cur`; ban đầu `cur` ở vị trí nút gốc.

1.  Nếu `cur` rỗng thì dừng duyệt, nếu không thì thực hiện các bước sau.
2.  Nếu `cur` không có cây con trái, di chuyển `cur` sang phải (`cur = cur->right`).
3.  Nếu `cur` có cây con trái, tìm nút ngoài cùng bên phải trên cây con trái, gọi là `mostRight`.
    -   Nếu con trỏ `right` của `mostRight` trỏ đến rỗng, cho nó trỏ đến `cur`, rồi di chuyển `cur` sang trái (`cur = cur->left`).
    -   Nếu con trỏ `right` của `mostRight` trỏ đến `cur`, đổi nó thành `null`, rồi di chuyển `cur` sang phải (`cur = cur->right`).

Ví dụ, `cur` bắt đầu thăm từ nút 1.

![tree-basic-morris-1](images/tree-basic-morris-1.svg)

Khi `cur` thăm nút 2 lần đầu, tìm nút ngoài cùng bên phải trên cây con trái là 4, rồi cho con trỏ `right` của 4 trỏ đến `cur`, tức nút 2.

![tree-basic-morris-2](images/tree-basic-morris-2.svg)

`cur` thông qua con trỏ `right` của 4 để quay lại tầng trên. Khi thăm nút 2 lần thứ hai, tìm nút ngoài cùng bên phải trên cây con trái là 4, đổi con trỏ `right` của 4 thành `null`, rồi tiếp tục thăm cây con phải. Các bước sau được lược bỏ.

![tree-basic-morris-1](images/tree-basic-morris-1.svg)

Thứ tự thăm toàn bộ cây là `1242513637`. Có thể thấy các nút có cây con trái được thăm hai lần, còn các nút không có cây con trái chỉ được thăm một lần.

???+ note "Cài đặt"
    ```cpp
    void morris(TreeNode* root) {
      TreeNode* cur = root;
      while (cur) {
        if (!cur->left) {
          // Nếu nút hiện tại không có nút con trái, in giá trị của nó rồi vào cây con phải
          std::cout << cur->val << " ";
          cur = cur->right;
          continue;
        }
        // Tìm nút ngoài cùng bên phải của cây con trái của nút hiện tại
        TreeNode* mostRight = cur->left;
        while (mostRight->right && mostRight->right != cur) {
          mostRight = mostRight->right;
        }
        if (!mostRight->right) {
          // Nếu con trỏ right của nút ngoài cùng bên phải rỗng, cho nó trỏ đến nút hiện tại rồi vào cây con trái
          mostRight->right = cur;
          cur = cur->left;
        } else {
          // Nếu con trỏ right của nút ngoài cùng bên phải trỏ đến nút hiện tại, cây con trái đã được duyệt xong; in giá trị của nút hiện tại rồi vào cây con phải
          mostRight->right = nullptr;
          std::cout << cur->val << " ";
          cur = cur->right;
        }
      }
    }
    ```

### Cây không gốc

#### Quy trình

Duyệt cây nói chung là duyệt theo chiều sâu. Trong quá trình này, điều quan trọng nhất cần chú ý là tránh thăm lặp lại các nút.

Vì cây là đồ thị không có chu trình, chỉ cần ghi lại nút hiện tại được thăm từ nút nào, rồi sau đó đi vào tất cả các nút kề ngoại trừ nút đó, là có thể tránh thăm lặp lại.

???+ note "Cài đặt"
    ```cpp
    void dfs(int u, int from) {
      // Đệ quy vào tất cả nút con ngoại trừ from
      // Với nút xuất phát, from rỗng, nên mọi nút kề đều được thăm; điều này đúng với mong đợi
      for (int v : adj[u])
        if (v != from) {
          dfs(v, u);
        }
    }
    
    // Khi bắt đầu duyệt
    int EMPTY_NODE = -1;  // Một chỉ số không tồn tại
    int root = 0;         // Chọn tùy ý một nút làm điểm xuất phát
    dfs(root, EMPTY_NODE);
    ```

### Cây có gốc

Với cây có gốc, cần phân biệt quan hệ trên dưới giữa các nút.

Xét quá trình duyệt ở trên: nếu bắt đầu duyệt từ gốc, thì khi thăm đến một nút, giá trị của `from` chính là chỉ số của nút cha của nó.

Thông qua cách này, với đầu vào vô hướng, ta có thể tìm được nút cha của mọi nút, cũng như danh sách nút con.

**Một phần nội dung của trang này được trích dẫn từ bài viết [Cây nhị phân: duyệt tiền thứ tự, duyệt trung thứ tự, duyệt hậu thứ tự](https://blog.csdn.net/weixin_43357638/article/details/99730284), tuân theo giấy phép CC 4.0 BY-SA.**
