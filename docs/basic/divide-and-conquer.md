author: fudonglai, AngelKitty, labuladong

Trang này giới thiệu sự khác biệt giữa đệ quy và chia để trị, cũng như cách
kết hợp chúng trong thuật toán.

## Đệ quy

### Định nghĩa

Đệ quy (recursion) trong toán học và khoa học máy tính là phương pháp dùng
chính đối tượng đang được định nghĩa trong định nghĩa của nó. Riêng trong khoa
học máy tính, đệ quy còn chỉ phương pháp giải bài toán bằng cách liên tục tách
bài toán thành các bài toán con cùng loại.

### Mở đầu

> Muốn hiểu đệ quy, trước hết phải hiểu đệ quy là gì.

Ý tưởng cơ bản của đệ quy là một hàm gọi trực tiếp hoặc gián tiếp chính nó. Nhờ
đó, việc giải bài toán ban đầu được chuyển thành việc giải nhiều bài toán con
có cùng bản chất nhưng kích thước nhỏ hơn. Khi giải, ta chỉ cần quan tâm làm
thế nào để chia bài toán gốc thành các bài toán con hợp lệ, không cần đào quá
sâu vào cách từng bài toán con được giải.

Một số ví dụ giúp hiểu đệ quy:

1.  [Đệ quy là gì?](./divide-and-conquer.md)
2.  Làm thế nào để sắp xếp một dãy số? Trả lời: chia dãy thành hai nửa, sắp xếp
    nửa trái, sắp xếp nửa phải, rồi trộn lại. Còn sắp xếp nửa trái và nửa phải
    thế nào thì hãy đọc lại câu này.
3.  Năm nay bạn bao nhiêu tuổi? Trả lời: tuổi năm ngoái cộng thêm một; tôi sinh
    năm 1999.
4.  ![Một ví dụ để hiểu đệ quy](images/divide-and-conquer-1.svg)

Đệ quy rất thường gặp trong toán học. Chẳng hạn trong lý thuyết tập hợp, một
định nghĩa hình thức của số tự nhiên là: 1 là một số tự nhiên; mỗi số tự nhiên
có một số kế tiếp, và số kế tiếp đó cũng là số tự nhiên.

Hai đặc trưng quan trọng nhất của mã đệ quy là điều kiện dừng và lời gọi chính
nó. Lời gọi chính nó dùng để giải bài toán con, còn điều kiện dừng định nghĩa
đáp án của bài toán con nhỏ nhất.

```cpp
int func(giá_trị_đầu_vào) {
  if (điều_kiện_dừng) return nghiệm_bài_toán_con_nhỏ_nhất;
  return func(kích_thước_nhỏ_hơn);
}
```

### Vì sao nên viết đệ quy

1.  Cấu trúc rõ ràng, dễ đọc. Ví dụ, dưới đây là hai cách cài đặt
    [merge sort](./merge-sort.md):

    === "C++"
        ```cpp
        // merge sort không dùng đệ quy
        template <typename T>
        void merge_sort(vector<T> a) {
          int n = a.size();
          for (int seg = 1; seg < n; seg = seg + seg)
            for (int start = 0; start < n - seg; start += seg + seg)
              merge(a, start, start + seg - 1, std::min(start + seg + seg - 1, n - 1));
        }

        // merge sort dùng đệ quy
        template <typename T>
        void merge_sort(vector<T> a, int front, int end) {
          if (front >= end) return;
          int mid = front + (end - front) / 2;
          merge_sort(a, front, mid);
          merge_sort(a, mid + 1, end);
          merge(a, front, mid, end);
        }
        ```

    === "Python"
        ```python
        # merge sort không dùng đệ quy
        def merge_sort(a):
            n = len(a)
            seg, start = 1, 0
            while seg < n:
                while start < n - seg:
                    merge(a, start, start + seg - 1, min(start + seg + seg - 1, n - 1))
                    start = start + seg + seg
                seg = seg + seg


        # merge sort dùng đệ quy
        def merge_sort(a, front, end):
            if front >= end:
                return
            mid = front + (end - front) / 2
            merge_sort(a, front, mid)
            merge_sort(a, mid + 1, end)
            merge(a, front, mid, end)
        ```

    Rõ ràng phiên bản đệ quy dễ hiểu hơn phiên bản không đệ quy. Cách làm của
    phiên bản đệ quy rất trực quan: sắp xếp nửa trái, sắp xếp nửa phải, rồi
    trộn hai nửa. Phiên bản không đệ quy thì khó đọc hơn, chứa nhiều chi tiết
    tính biên khó hiểu, rất dễ lỗi và khó gỡ lỗi.

2.  Rèn luyện khả năng phân tích cấu trúc bài toán. Khi nhận ra bài toán có thể
    được tách thành các bài toán nhỏ có cùng cấu trúc, việc quen viết đệ quy sẽ
    giúp bạn phát hiện đặc điểm đó nhanh hơn và giải bài hiệu quả hơn.

### Nhược điểm của đệ quy

Trong quá trình thực thi, đệ quy được cài đặt bằng stack. Mỗi khi đi vào một
lời gọi hàm, stack thêm một stack frame; mỗi khi hàm trả về, stack bỏ bớt một
stack frame. Stack không có kích thước vô hạn, nên nếu tầng đệ quy quá sâu sẽ
dẫn đến **tràn stack**.

Rõ ràng có lúc đệ quy hiệu quả, chẳng hạn merge sort; nhưng **cũng có lúc đệ
quy kém hiệu quả**, chẳng hạn đếm số sợi lông trên người Tôn Ngộ Không. Stack
tiêu tốn thêm bộ nhớ, trong khi truy hồi hoặc vòng lặp đơn giản có thể không
tốn thêm bộ nhớ. Ví dụ sau: cho đầu một danh sách liên kết, hãy tính độ dài của
nó.

```cpp
// khung duyệt truy hồi điển hình
int size(Node *head) {
  int size = 0;
  for (Node *p = head; p != nullptr; p = p->next) size++;
  return size;
}

// cứ thích viết đệ quy: đệ quy là nhất
int size_recursion(Node *head) {
  if (head == nullptr) return 0;
  return size_recursion(head->next) + 1;
}
```

![[So sánh hai cách, trình biên dịch đặt là Clang 10.0, tối ưu đặt là O1](https://quick-bench.com/q/rZ7jWPmSdltparOO5ndLgmS9BVc)](images/divide-and-conquer-2.svg "[So sánh hai cách, trình biên dịch đặt là Clang 10.0, tối ưu đặt là O1](https://quick-bench.com/q/rZ7jWPmSdltparOO5ndLgmS9BVc)")

### Tối ưu đệ quy

Trang chính: [tối ưu tìm kiếm](../search/opt.md) và
[tìm kiếm có nhớ](../dp/memo.md)

Những cài đặt đệ quy sơ cấp có thể gọi đệ quy quá nhiều lần và dễ quá thời
gian. Khi đó cần tối ưu đệ quy.[^ref1]

## Chia để trị

### Định nghĩa

Chia để trị (divide and conquer), hiểu theo nghĩa đen là "chia ra để xử lý",
là cách tách một bài toán phức tạp thành hai hoặc nhiều bài toán con giống
hoặc tương tự nhau, cho đến khi bài toán con đủ đơn giản để giải trực tiếp.
Nghiệm của bài toán ban đầu được tạo bằng cách hợp nhất nghiệm của các bài toán
con.

### Quy trình

Tư tưởng cốt lõi của thuật toán chia để trị là "chia ra để trị".

Quy trình khái quát gồm ba bước: chia -> giải -> gộp.

1.  Chia bài toán gốc thành các bài toán con có cùng cấu trúc.
2.  Chia đến một trường hợp biên dễ giải, rồi giải đệ quy.
3.  Gộp nghiệm của các bài toán con thành nghiệm của bài toán gốc.

Những bài toán giải được bằng chia để trị thường có các đặc điểm sau:

-   Khi kích thước bài toán giảm đến một mức nhất định, bài toán có thể được
    giải dễ dàng.
-   Bài toán có thể được chia thành một số bài toán nhỏ cùng dạng; tức là bài
    toán có tính chất cấu trúc con tối ưu, và nghiệm của các bài toán con có
    thể được gộp thành nghiệm của bài toán ban đầu.
-   Các bài toán con được tách ra độc lập với nhau; giữa chúng không có bài
    toán con chung.

???+ warning "Chú ý"
    Nếu các bài toán con không độc lập, chia để trị sẽ phải giải lặp lại các
    bài toán con chung, gây nhiều công việc thừa. Khi đó vẫn có thể dùng chia
    để trị, nhưng thường dùng [quy hoạch động](../dp/basic.md) sẽ tốt hơn.

Lấy merge sort làm ví dụ. Giả sử hàm cài đặt merge sort tên là `merge_sort`.
Trước hết cần xác định rõ nhiệm vụ của hàm này: **sắp xếp mảng được truyền
vào**. Bài toán này rõ ràng có thể chia được. Sắp xếp một mảng tương đương với
sắp xếp nửa trái, sắp xếp nửa phải, rồi gộp chúng thành một mảng.

```cpp
void merge_sort(một_mảng) {
  if (có_thể_xử_lý_rất_dễ) return;
  merge_sort(nửa_trái_của_mảng);
  merge_sort(nửa_phải_của_mảng);
  merge(nửa_trái_của_mảng, nửa_phải_của_mảng);
}
```

Khi truyền cho nó nửa mảng, sau khi xử lý xong thì nửa mảng đó đã được sắp
xếp. Có thể thấy `merge_sort` rất giống mẫu duyệt hậu tự của cây nhị phân. Vì
khuôn mẫu của chia để trị là **chia -> giải (chạm đáy) -> gộp (quay lui)**:
trước hết chia trái phải, sau đó xử lý gộp; bước quay lui chính là khi stack
trả về, tương đương hậu tự.

Cách cài đặt hàm `merge` giống với việc gộp hai danh sách liên kết đã sắp xếp.

## Điểm chính

### Điểm chính khi viết đệ quy

**Hiểu nhiệm vụ của một hàm và tin rằng nó hoàn thành được nhiệm vụ đó; đừng
nhảy vào bên trong hàm để cố truy thêm chi tiết**, nếu không bạn sẽ mắc kẹt
trong vô hạn chi tiết. Bộ não con người đâu thể giữ được nhiều stack frame như
máy tính.

Lấy duyệt cây nhị phân làm ví dụ.

```cpp
void traverse(TreeNode* root) {
  if (root == nullptr) return;
  traverse(root->left);
  traverse(root->right);
}
```

Vài dòng này đã đủ để duyệt bất kỳ cây nhị phân nào. Với hàm đệ quy
`traverse(root)`, chỉ cần tin rằng khi đưa cho nó một nút gốc `root`, nó có thể
duyệt cả cây đó. Vì vậy ta chỉ cần truyền tiếp nút trái và nút phải cho hàm.

Mở rộng tương tự sang duyệt cây N phân. Cách viết gần như giống cây nhị phân,
chỉ có điều cây N phân rõ ràng không có duyệt trung tự.

```cpp
void traverse(TreeNode* root) {
  if (root == nullptr) return;
  for (auto child : root->children) traverse(child);
}
```

## Khác biệt

### Khác biệt giữa đệ quy và liệt kê

Liệt kê chia bài toán theo chiều ngang rồi lần lượt giải các bài toán con; còn
đệ quy phân rã bài toán từng tầng, tức là chia theo chiều dọc.

### Khác biệt giữa đệ quy và chia để trị

Đệ quy là một kỹ thuật lập trình và một cách tư duy giải bài toán. Chia để trị
là một tư tưởng thuật toán cụ thể hơn, phần lớn dựa trên đệ quy để giải một số
loại bài toán.

## Phân tích bài ví dụ

???+ note "[437. Path Sum III](https://leetcode-cn.com/problems/path-sum-iii/)"
    Cho một cây nhị phân, mỗi nút chứa một giá trị nguyên.

    Hãy tìm tổng số đường đi có tổng bằng giá trị cho trước.

    Đường đi không nhất thiết bắt đầu từ nút gốc, cũng không nhất thiết kết
    thúc ở nút lá, nhưng hướng đi phải là đi xuống, tức chỉ được đi từ nút cha
    đến nút con.

    Cây nhị phân có không quá 1000 nút, và giá trị nút nằm trong đoạn số nguyên
    \[-1000000,1000000].

    Ví dụ:

    ```text
    root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

          10
         /  \
        5   -3
       / \    \
      3   2   11
     / \   \
    3  -2   1

    Trả về 3. Các đường đi có tổng bằng 8 là:

    1.  5 -> 3
    2.  5 -> 2 -> 1
    3. -3 -> 11
    ```

    ```cpp
    --8<-- "docs/basic/code/divide-and-conquer/divide-and-conquer_1.h"
    ```

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/basic/code/divide-and-conquer/divide-and-conquer_1.cpp"
    ```

??? note "Phân tích bài toán"
    Đề bài trông phức tạp, nhưng mã lại cực kỳ ngắn gọn.

    Trước hết cần xác định rõ: giải bài toán trên cây bằng đệ quy chắc chắn
    phải duyệt toàn bộ cây, nên khung duyệt cây nhị phân, tức gọi đệ quy chính
    hàm đó trên cây con trái và phải, chắc chắn sẽ xuất hiện trong hàm chính
    `pathSum`. Vậy với mỗi nút, nó cần làm gì? Nó cần xem bản thân nó và các
    cây con của nó chứa bao nhiêu đường đi thỏa điều kiện. Đến đây bài toán đã
    xong.

    Theo kỹ thuật đã nói ở trên, dựa vào phân tích vừa rồi, hãy định nghĩa rõ
    từng hàm đệ quy cần làm gì:

    Hàm `PathSum`: cho một nút và một giá trị mục tiêu, trả về tổng số đường đi
    có tổng bằng giá trị mục tiêu trong cây lấy nút đó làm gốc.

    Hàm `count`: cho một nút và một giá trị mục tiêu, trả về số đường đi bắt
    đầu từ chính nút đó và có tổng bằng giá trị mục tiêu trong cây lấy nút đó
    làm gốc.

    ??? note "Mã tham khảo (có chú thích)"
        ```cpp
        int pathSum(TreeNode *root, int sum) {
          if (root == nullptr) return 0;
          int pathImLeading = count(root, sum);  // số đường đi bắt đầu từ chính nó
          int leftPathSum = pathSum(root->left, sum);  // tổng số đường đi bên trái: tin rằng hàm tính được
          int rightPathSum =
              pathSum(root->right, sum);  // tổng số đường đi bên phải: tin rằng hàm tính được
          return leftPathSum + rightPathSum + pathImLeading;
        }

        int count(TreeNode *node, int sum) {
          if (node == nullptr) return 0;
          // bản thân nó có tạo thành một đường đi riêng không?
          int isMe = (node->val == sum) ? 1 : 0;
          // bên trái có tạo được bao nhiêu đường đi có tổng sum - node.val?
          int leftNode = count(node->left, sum - node->val);
          // bên phải có tạo được bao nhiêu đường đi có tổng sum - node.val?
          int rightNode = count(node->right, sum - node->val);
          return isMe + leftNode + rightNode;  // tổng số đường đi tạo được ở đây
        }
        ```

    Vẫn là câu đó: **hãy hiểu mỗi hàm có thể làm gì, và tin rằng chúng làm
    được việc đó.**

    Tóm lại, hàm `PathSum` cung cấp khung duyệt cây nhị phân; trong quá trình
    duyệt, nó gọi hàm `count` trên mỗi nút. Ở đây dùng duyệt tiền tự, nhưng
    duyệt trung tự hoặc hậu tự cũng được. Hàm `count` cũng là một phép duyệt cây
    nhị phân, dùng để tìm các đường đi mục tiêu bắt đầu từ nút đó.

## Bài tập

-   [Chuyên đề luyện tập đệ quy trên LeetCode](https://leetcode.com/explore/learn/card/recursion-i/)
-   [Chuyên đề luyện tập chia để trị trên LeetCode](https://leetcode.com/tag/divide-and-conquer/)

## Tài liệu tham khảo và ghi chú

[^ref1]: [Ghi chú thuật toán của labuladong - giải thích chi tiết về đệ quy](https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/di-gui-xiang-jie)
