author: Alex-McAvoy, lingkerio, LvCGame

## Độ dài đường đi có trọng số của cây

Giả sử một cây nhị phân có $n$ nút lá có trọng số.
Tổng các tích giữa độ dài đường đi từ nút gốc đến từng nút lá
và trọng số tương ứng của nút lá đó được gọi là
**độ dài đường đi có trọng số của cây** (tiếng Anh: weighted path length of tree, WPL).

Gọi $w_i$ là trọng số của nút lá thứ $i$ trong cây nhị phân,
$l_i$ là độ dài đường đi từ nút gốc đến nút lá thứ $i$.
Khi đó công thức tính WPL như sau:

$$
WPL=\sum_{i=1}^nw_il_i
$$

![](./images/huffman-tree-1.svg)

Như hình trên, quá trình tính WPL và kết quả như sau:

$$
WPL=2*2+3*2+4*2+7*2=4+6+8+14=32
$$

## Cấu trúc

Với một tập nút lá có trọng số xác định cho trước,
có thể xây dựng nhiều cây nhị phân khác nhau.
Trong đó, **cây nhị phân có WPL nhỏ nhất** được gọi là **cây Huffman**.

Đối với cây Huffman, nút lá có trọng số càng nhỏ thì càng xa gốc,
nút lá có trọng số càng lớn thì càng gần gốc.
Ngoài ra, chỉ các nút lá của nó có bậc bằng $0$,
còn bậc của các nút khác đều bằng $2$.

## Thuật toán Huffman

Thuật toán Huffman xây dựng một cây Huffman theo các bước sau:

1.  **Khởi tạo**: Từ $n$ trọng số cho trước, xây dựng $n$ cây nhị phân,
    mỗi cây chỉ có một nút gốc, thu được một tập cây nhị phân $F$.
2.  **Chọn và gộp**: Từ tập cây nhị phân $F$,
    chọn **hai cây** có trọng số nút gốc nhỏ nhất làm cây con trái và cây con phải
    để xây dựng một cây nhị phân mới.
    Trọng số nút gốc của cây nhị phân mới này bằng tổng trọng số nút gốc của cây con trái và cây con phải.
3.  **Xóa và thêm**: Xóa khỏi $F$ hai cây nhị phân được dùng làm cây con trái và cây con phải,
    rồi thêm cây nhị phân mới tạo vào $F$.
4.  Lặp lại bước 2 và 3.
    Khi trong tập chỉ còn một cây nhị phân, cây nhị phân đó chính là cây Huffman.

![](./images/huffman-tree-2.svg)

### Chứng minh tính đúng đắn

???+ note "Bổ đề"
    Trong cây mã tiền tố tối ưu (cây Huffman),
    hai nút lá có trọng số nhỏ nhất luôn có thể được chọn là hai nút lá sâu nhất
    và là hai nút anh em mà không phá vỡ tính tối ưu của cây mã hóa.

??? note "Chứng minh"
    Xét một cây mã tiền tố tối ưu bất kỳ.
    Lấy hai nút lá sâu nhất là một cặp anh em trong cây đó,
    rồi gọi hai nút lá có trọng số nhỏ nhất là $a$ và $b$.
    Nếu $a$ hoặc $b$ chưa nằm ở vị trí sâu nhất,
    có thể hoán đổi nó với một trong hai nút lá sâu nhất.
    Vì trọng số của $a$ và $b$ không lớn hơn trọng số của nút bị hoán đổi,
    WPL sau khi hoán đổi không tăng.

    Sau tối đa hai lần hoán đổi, hai trọng số nhỏ nhất nằm ở hai nút lá sâu nhất
    và hai nút này là anh em.
    Do WPL không tăng mà cây ban đầu đã tối ưu, cây thu được vẫn tối ưu.
    Bổ đề được chứng minh.

???+ note "Định lý"
    Cây mã tiền tố thu được từ thuật toán Huffman là cây mã tiền tố tối ưu.

??? note "Chứng minh"
    Dùng quy nạp toán học để chứng minh định lý này.

    -   **Trường hợp cơ sở**: Khi số chữ cái $n = 2$,
        trực tiếp gộp hai chữ cái thành một cây chính là cây mã hóa tối ưu.
    -   **Giả thiết quy nạp**: Giả sử khi số chữ cái $n = k$ ($k \geq 2$),
        thuật toán Huffman có thể thu được cây mã tiền tố tối ưu.
    -   **Bước quy nạp**: Với số chữ cái $n = k + 1$,
        chọn hai chữ cái có trọng số nhỏ nhất trong $k+1$ chữ cái,
        gộp chúng thành một cây con,
        rồi xem gốc của cây con là một chữ cái ảo (nút ảo).
        Theo bổ đề, thao tác này không phá vỡ tính tối ưu của cây mã tiền tố.
        Lúc này, chữ cái ảo cùng với $k-1$ chữ cái còn lại tạo thành $k$ chữ cái.
        Theo giả thiết quy nạp, với $k$ chữ cái,
        thuật toán Huffman có thể thu được cây mã tiền tố tối ưu.

    Vì vậy, bằng quy nạp toán học,
    thuật toán Huffman có thể thu được cây mã tiền tố tối ưu với mọi số chữ cái $n$.
    Định lý được chứng minh.

## Mã Huffman

Khi lập trình, mỗi ký tự thường được gán một mã riêng để biểu diễn một tập ký tự;
đó gọi là **mã hóa**.

Khi mã hóa nhị phân, nếu mọi mã đều có độ dài bằng nhau,
để biểu diễn $n$ ký tự khác nhau cần $\left \lceil \log_2 n \right \rceil$ bit.
Cách này được gọi là **mã hóa độ dài cố định**.

Nếu **tần suất sử dụng** của mỗi ký tự bằng nhau,
mã hóa độ dài cố định là phương pháp mã hóa có hiệu quả không gian cao nhất.
Nhưng nếu tần suất xuất hiện của các ký tự khác nhau,
có thể cho ký tự có tần suất cao dùng mã ngắn nhất có thể,
ký tự có tần suất thấp dùng mã dài nhất có thể,
từ đó xây dựng một kiểu **mã hóa độ dài thay đổi** để đạt hiệu quả không gian tốt hơn.

Khi thiết kế mã hóa độ dài thay đổi, cần xét đến tính duy nhất khi giải mã.
Nếu trong một tập mã, không có mã nào là tiền tố của bất kỳ mã nào khác,
thì tập mã đó được gọi là **mã tiền tố**;
điều này bảo đảm tính duy nhất khi giải mã.

Có thể dùng cây Huffman để xây dựng **mã tiền tố ngắn nhất**,
tức **mã Huffman**.
Các bước xây dựng như sau:

1.  Giả sử tập ký tự cần mã hóa là: $d_1,d_2,\dots,d_n$, tần suất xuất hiện của chúng trong chuỗi là: $w_1,w_2,\dots,w_n$.
2.  Dùng $d_1,d_2,\dots,d_n$ làm các nút lá, $w_1,w_2,\dots,w_n$ làm trọng số của các nút lá, rồi xây dựng một cây Huffman.
3.  Quy định nhánh trái của cây mã hóa Huffman biểu diễn $0$,
    nhánh phải biểu diễn $1$.
    Khi đó, dãy gồm các $0$ và $1$ trên đường đi từ nút gốc đến mỗi nút lá
    chính là mã của ký tự tương ứng với nút lá đó.

![](./images/huffman-tree-3.svg)

## Mã mẫu

??? note "Xây dựng cây Huffman"
    ```cpp
    struct HNode {
      int weight;
      HNode *lchild, *rchild;
    };
    
    using Htree = HNode *;
    
    Htree createHuffmanTree(int arr[], int n) {
      Htree forest[N];
      Htree root = NULL;
      for (int i = 0; i < n; i++) {  // Đưa tất cả các nút vào rừng
        Htree temp;
        temp = (Htree)malloc(sizeof(HNode));
        temp->weight = arr[i];
        temp->lchild = temp->rchild = NULL;
        forest[i] = temp;
      }
    
      for (int i = 1; i < n; i++) {  // Lặp n-1 lần để xây dựng cây Huffman
        int minn = -1, minnSub;  // minn là chỉ số gốc cây nhỏ nhất, minnSub là chỉ số gốc cây nhỏ thứ hai
        for (int j = 0; j < n; j++) {
          if (forest[j] != NULL && minn == -1) {
            minn = j;
            continue;
          }
          if (forest[j] != NULL) {
            minnSub = j;
            break;
          }
        }
    
        for (int j = minnSub; j < n; j++) {  // Cập nhật minn và minnSub
          if (forest[j] != NULL) {
            if (forest[j]->weight < forest[minn]->weight) {
              minnSub = minn;
              minn = j;
            } else if (forest[j]->weight < forest[minnSub]->weight) {
              minnSub = j;
            }
          }
        }
    
        // Xây dựng cây mới
        root = (Htree)malloc(sizeof(HNode));
        root->weight = forest[minn]->weight + forest[minnSub]->weight;
        root->lchild = forest[minn];
        root->rchild = forest[minnSub];
    
        forest[minn] = root;     // Gán con trỏ trỏ đến cây mới vào vị trí minn
        forest[minnSub] = NULL;  // Vị trí minnSub để trống
      }
      return root;
    }
    ```

??? note "Tính WPL của cây Huffman đã tạo"
    ```cpp
    struct HNode {
      int weight;
      HNode *lchild, *rchild;
    };
    
    using Htree = HNode *;
    
    int getWPL(Htree root, int len) {  // Cài đặt đệ quy để tính WPL của cây Huffman đã xây dựng
      if (root == NULL)
        return 0;
      else {
        if (root->lchild == NULL && root->rchild == NULL)  // Nút lá
          return root->weight * len;
        else {
          int left = getWPL(root->lchild, len + 1);
          int right = getWPL(root->rchild, len + 1);
          return left + right;
        }
      }
    }
    ```

??? note "Tính trực tiếp WPL khi chưa xây dựng cây Huffman"
    ```cpp
    int getWPL(int arr[], int n) {  // Tính trực tiếp WPL khi chưa xây dựng cây Huffman
      priority_queue<int, vector<int>, greater<int>> huffman;  // Đống nhỏ
      for (int i = 0; i < n; i++) huffman.push(arr[i]);
    
      int res = 0;
      for (int i = 0; i < n - 1; i++) {
        int x = huffman.top();
        huffman.pop();
        int y = huffman.top();
        huffman.pop();
        int temp = x + y;
        res += temp;
        huffman.push(temp);
      }
      return res;
    }
    ```

??? note "Tính mã Huffman cho dãy cho trước"
    ```cpp
    struct HNode {
      int weight;
      HNode *lchild, *rchild;
    };
    
    using Htree = HNode *;
    
    void huffmanCoding(Htree root, int len, int arr[]) {  // Tính mã Huffman
      if (root != NULL) {
        if (root->lchild == NULL && root->rchild == NULL) {
          printf("Mã của ký tự tại nút %d là: ", root->weight);
          for (int i = 0; i < len; i++) printf("%d", arr[i]);
          printf("\n");
        } else {
          arr[len] = 0;
          huffmanCoding(root->lchild, len + 1, arr);
          arr[len] = 1;
          huffmanCoding(root->rchild, len + 1, arr);
        }
      }
    }
    ```
