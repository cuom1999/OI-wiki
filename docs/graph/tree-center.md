author: littleparrot12345

## Định nghĩa

Trong một cây, nếu khi chọn đỉnh $x$ làm gốc, đường đi dài nhất xuất phát từ $x$ là ngắn nhất có thể, thì $x$ được gọi là tâm của cây.

## Tính chất

-   Tâm của cây không nhất thiết là duy nhất, nhưng có nhiều nhất $2$ tâm, và nếu có hai tâm thì chúng kề nhau.
-   Tâm của cây nằm trên đường kính của cây.
-   Với mọi đỉnh trên cây, đường đi từ đỉnh đó đến đỉnh xa nhất của nó đều giao nhau tại tâm của cây.
-   Khi lấy tâm của cây làm gốc, hai đường đi từ tâm đến hai đầu mút của đường kính lần lượt là đường dài nhất và đường dài thứ hai.
-   Khi nối hai cây bằng một cạnh để gộp thành một cây, nối hai tâm của hai cây sẽ làm đường kính của cây mới nhỏ nhất.
-   Khoảng cách từ tâm của cây đến bất kỳ đỉnh nào khác không vượt quá một nửa đường kính của cây.

## Cách tìm

Tìm một đỉnh $x$ sao cho khi chọn nó làm gốc, độ dài đường đi dài nhất là nhỏ nhất.

### Các bước cụ thể

1.  Duy trì $len1_x$, biểu thị đường đi dài nhất trong cây con của đỉnh $x$.
2.  Duy trì $len2_x$, biểu thị đường đi dài nhất không trùng với $len1_x$.
3.  Duy trì $up_x$, biểu thị đường đi dài nhất nằm ngoài cây con của đỉnh $x$; đường đi này đi qua cha của $x$.
4.  Tìm đỉnh $x$ sao cho $\max(len1_x, up_x)$ nhỏ nhất; khi đó $x$ chính là tâm của cây.

???+ note "Mã tham khảo"
    ```cpp
    // Đoạn mã này giả định các đỉnh được đánh số từ 1, tức i thuộc [1,n], và dùng vector để lưu đồ thị
    int d1[N], d2[N], up[N], x, y, mini = 1e9;  // d1,d2 tương ứng với len1,len2 ở trên
    
    struct node {
      int to, val;  // to là đỉnh mà cạnh trỏ tới, val là trọng số cạnh
    };
    
    vector<node> nbr[N];
    
    void dfsd(int cur, int fa) {  // Tính len1 và len2
      for (node nxtn : nbr[cur]) {
        int nxt = nxtn.to, w = nxtn.val;  // nxt là đỉnh mà cạnh này đi tới, val là trọng số cạnh
        if (nxt == fa) {
          continue;
        }
        dfsd(nxt, cur);
        if (d1[nxt] + w > d1[cur]) {  // Có thể cập nhật đường đi dài nhất
          d2[cur] = d1[cur];
          d1[cur] = d1[nxt] + w;
        } else if (d1[nxt] + w > d2[cur]) {  // Không cập nhật được đường dài nhất, nhưng cập nhật được đường dài thứ hai
          d2[cur] = d1[nxt] + w;
        }
      }
    }
    
    void dfsu(int cur, int fa) {
      for (node nxtn : nbr[cur]) {
        int nxt = nxtn.to, w = nxtn.val;
        if (nxt == fa) {
          continue;
        }
        up[nxt] = up[cur] + w;
        if (d1[nxt] + w != d1[cur]) {  // Nếu đường dài nhất trong cây con hiện tại không nằm trong cây con nxt
          up[nxt] = max(up[nxt], d1[cur] + w);
        } else {  // Đường dài nhất trong cây con hiện tại nằm trong cây con nxt, nên chỉ có thể dùng đường dài thứ hai
          up[nxt] = max(up[nxt], d2[cur] + w);
        }
        dfsu(nxt, cur);
      }
    }
    
    void GetTreeCenter() {  // Tìm tâm của cây, lưu vào x và y nếu có
      dfsd(1, 0);
      dfsu(1, 0);
      for (int i = 1; i <= n; i++) {
        if (max(d1[i], up[i]) < mini) {  // Tìm được đỉnh hiện tại có max(len1[x],up[x]) nhỏ nhất
          mini = max(d1[i], up[i]);
          x = i;
          y = 0;
        } else if (max(d1[i], up[i]) == mini) {  // Tâm còn lại
          y = i;
        }
      }
    }
    ```

### Ví dụ

Giả sử có một cây như sau:

```text
           A
          / \
         B   C
        / \   \
       D   E   F
```

-   Đường kính của cây là $D \rightarrow B \rightarrow A \rightarrow C \rightarrow F$. Độ dài đường kính là $4$.
-   Tâm của cây là đỉnh $A$, vì đường đi dài nhất xuất phát từ $A$ (đến $D$ hoặc $F$) đều có độ dài $2$.
-   Nếu chọn $B$ hoặc $C$ làm gốc của cây, đường đi dài nhất xuất phát từ các đỉnh đó sẽ dài hơn, nên chúng không phải là tâm của cây.

### Độ phức tạp thời gian

Độ phức tạp thời gian của thuật toán trên là $O(n)$, trong đó $n$ là số lượng đỉnh trong cây.

## Tham khảo

-   [TutorialsPoint: tâm của cây](https://www.tutorialspoint.com/centers-of-a-tree)
-   [ProofWiki: định nghĩa tâm của cây](https://proofwiki.org/wiki/Definition:Center_of_Tree)
-   [Wikipedia: cây (lý thuyết đồ thị)](https://en.wikipedia.org/wiki/Tree_%28graph_theory%29#Properties)
