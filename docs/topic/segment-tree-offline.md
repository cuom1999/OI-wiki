author: xiezheyuan

Các bài toán kết hợp cây đoạn với truy vấn ngoại tuyến cũng xuất hiện trong OI. Kỹ thuật này còn được gọi là chia để trị bằng cây đoạn.

Nếu cần duy trì một số thông tin chỉ tồn tại trong từng khoảng thời gian, và cần trả lời hợp các thông tin tại một thời điểm nào đó trong bối cảnh ngoại tuyến, có thể cân nhắc dùng kỹ thuật chia để trị bằng cây đoạn.

Trong thực tế, chia để trị bằng cây đoạn thường có các công dụng sau:

1.  Dùng một cấu trúc dữ liệu vốn không hỗ trợ xóa, nhưng hỗ trợ khôi phục trạng thái, để mô phỏng thao tác xóa. Ví dụ, DSU thông thường không thể hỗ trợ xóa cạnh một cách hiệu quả.
2.  Tính riêng dữ liệu theo các thuộc tính khác nhau. Ví dụ, cần tính đáp án của các dữ liệu có màu khác sau khi loại trừ một màu nào đó.

Nếu hiện tại chưa rõ cũng không sao, hai công dụng này sẽ được minh họa trong các ví dụ.

## Quy trình

Trước hết, xây dựng một cây đoạn để quản lý trục thời gian. Mỗi nút duy trì một `vector` để lưu các thông tin tồn tại trên đoạn thời gian tương ứng.

Chèn một thông tin vào cây đoạn tương tự như thao tác cập nhật đoạn trên cây đoạn thông thường.

Sau đó xét cách xử lý hợp thông tin của mỗi khoảng thời gian. Bắt đầu chia để trị từ nút gốc, duy trì hợp thông tin hiện tại; mỗi khi đi đến một nút, hợp nhất tất cả thông tin lưu trong nút đó. Khi quay lui, khôi phục phần đóng góp này. Khi đến nút lá, hợp thông tin hiện tại chính là đáp án tương ứng.

Nếu độ phức tạp thời gian để thay đổi thông tin là $O(T(n))$, có thể dùng một ngăn xếp để ghi lại các thay đổi và khôi phục với độ phức tạp $O(T(n))$. Khi khôi phục, không được dựa vào độ phức tạp trung bình khấu hao.

Toàn bộ quá trình chia để trị có tổng độ phức tạp thời gian là $O(n\log n(T(n) + M(n)))$, trong đó $O(M(n))$ là độ phức tạp thời gian để hợp nhất thông tin; độ phức tạp không gian là $O(n\log n)$.

??? note "Cài đặt"
    ```cpp
    #define ls (i << 1)
    #define rs (i << 1 | 1)
    #define mid ((l + r) >> 1)
    
    vector<Object> tree[N << 2];  // cây đoạn
    
    void update(int ql, int qr, Object obj, int i, int l, int r) {  // chèn
      if (ql <= l && r <= qr) {
        tree[i].push_back(obj);
        return;
      }
      if (ql <= mid) update(ql, qr, obj, ls, l, mid);
      if (qr > mid) update(ql, qr, obj, rs, mid + 1, r);
    }
    
    stack<Object> sta;  // ngăn xếp để khôi phục
    Object now;         // hợp thông tin hiện tại
    Object ans[N];      // đáp án
    
    void solve(int i, int l, int r) {
      auto lvl = sta.size();  // ghi lại mốc cần khôi phục về
      for (Object x : tree[i]) sta.push(now), now = Merge(now, x);  // hợp nhất thông tin
      if (l == r)
        ans[i] = now;  // ghi lại đáp án
      else
        solve(ls, l, mid), solve(rs, mid + 1, r);  // chia để trị
      while (sta.size() != lvl) {                  // khôi phục thông tin
        now = sta.top();
        sta.pop();
      }
    }
    ```

## Ví dụ

???+ note "[luogu P5787 Đồ thị hai phía / [Mẫu] Chia để trị bằng cây đoạn](https://www.luogu.com.cn/problem/P5787)"
    Cần duy trì một đồ thị vô hướng có $n$ đỉnh và $m$ cạnh. Cạnh thứ $i$ là $(x_i,y_i)$, xuất hiện trong khoảng thời gian $[l_i,r_i)$ và biến mất ở các thời điểm còn lại.
    
    Với mỗi thời điểm, nếu đồ thị lúc đó là đồ thị hai phía thì in `Yes`, ngược lại in `No`.
    
    ??? note "Ý tưởng giải"
        Dùng DSU duy trì tính chẵn lẻ để kiểm tra một đồ thị có phải là đồ thị hai phía hay không, sau đó áp dụng trực tiếp chia để trị bằng cây đoạn.
        
        Chú ý DSU có thể khôi phục trạng thái không được nén đường, chỉ có thể hợp nhất theo hạng.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/topic/code/segment-tree-offline/segment-tree-offline_1.cpp"
        ```

???+ note "Ràng buộc màu"
    Cho một đồ thị vô hướng có $n$ đỉnh và $m$ cạnh, có $k$ màu được đánh số từ $0\sim k-1$, mỗi cạnh có một màu.
    
    Với mỗi màu, hãy xác định rằng nếu xóa tất cả cạnh có màu đó thì đồ thị thu được có liên thông không? Có phải là một cây không?
    
    In ra số lượng màu sao cho sau khi xóa, đồ thị vẫn liên thông, và số lượng màu sao cho sau khi xóa, đồ thị là một cây.
    
    ??? note "Ý tưởng giải"
        Với mỗi màu, tạo một thời điểm; tại thời điểm này không có cạnh nào mang màu đó, còn các cạnh khác đều tồn tại. Khi đó chỉ cần dùng một DSU để duy trì.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/topic/code/segment-tree-offline/segment-tree-offline_2.cpp"
        ```

???+ note "[luogu P4219 \[BJOI2014\] Đại dung hợp](https://www.luogu.com.cn/problem/P4219)"
    Cần duy trì một rừng có $n$ đỉnh, ban đầu là các đỉnh rời rạc.
    
    Có $q$ thao tác, hỗ trợ:
    
    -   `A x y` nối cạnh $(x,y)$.
    -   `Q x y` in số đường đi đi qua cạnh $(x,y)$.
    
    Cho phép xử lý ngoại tuyến.
    
    ??? note "Ý tưởng giải"
        Vì cho phép xử lý ngoại tuyến, có thể nghĩ đến chia để trị bằng cây đoạn.
        
        Tiếp theo xét cách hỗ trợ thao tác `Q`. Nếu cạnh $(x,y)$ không tồn tại, đáp án chính là kích thước thành phần liên thông chứa $x$ nhân với kích thước thành phần liên thông chứa $y$. Giá trị này có thể được duy trì bằng DSU.
        
        Vì vậy, có thể tách một thao tác `Q` thành ba thời điểm $k-1,k,k+1$. Trong đó $k-1$ là thời điểm kết thúc của cạnh này, còn $k+1$ là thời điểm bắt đầu của cạnh này. Khi đó tại thời điểm $k$ không có cạnh này, vừa đúng để trả lời truy vấn.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/topic/code/segment-tree-offline/segment-tree-offline_3.cpp"
        ```

???+ note "[luogu P2056 \[ZJOI2007\] Trốn tìm](https://www.luogu.com.cn/problem/P2056)"
    Cho một cây có $n$ đỉnh, mỗi đỉnh có một trong hai màu đen và trắng. Ban đầu mỗi đỉnh đều có màu đen. Có $q$ thao tác, hỗ trợ:
    
    -   `C x` đảo màu của đỉnh thứ $x$.
    -   `G` hỏi khoảng cách xa nhất giữa hai đỉnh đen trên cây. Đặc biệt, nếu không tồn tại đỉnh đen nào, in $-1$.
    
    Cho phép xử lý ngoại tuyến.
    
    ??? note "Ý tưởng giải"
        Trước hết xét cách duy trì đường kính của một tập đỉnh trên cây. Có suy luận sau:
        
        > Với một tập $S$ và tập chỉ có một điểm $\{P\}$. Nếu đường kính của tập $S$ là $(U,V)$, thì đường kính của tập đỉnh $S\cap\{P\}$ chỉ có thể là $(U,V),(U,P)$ hoặc $(V,P)$.
        
        Sau đó quay lại bài toán gốc. Có thể duy trì tập các đỉnh đen, đồng thời duy trì các khoảng thời gian mà mỗi đỉnh nằm trong tập đỉnh đen. Cụ thể, chỉ cần mở một mảng xô để ghi lại thời điểm lần gần nhất đỉnh đó đi vào tập đỉnh đen.
        
        Khi đó có thể xử lý ngoại tuyến một cách tự nhiên: chèn tất cả khoảng thời gian vào cây đoạn. Sau đó chia để trị trên cây đoạn; mỗi nút trên cây đoạn ghi lại các đỉnh được thêm vào tập đỉnh trong đoạn thời gian hiện tại. Với các đỉnh mới thêm, có thể dùng suy luận trên để tìm hai đầu mút đường kính của tập đỉnh mới.
        
        Việc khôi phục trạng thái rất trực tiếp: chỉ cần dùng một ngăn xếp để ghi lại các thay đổi của hai đầu mút đường kính.
    
    ??? note "Mã tham khảo"
        ```cpp
        --8<-- "docs/topic/code/segment-tree-offline/segment-tree-offline_4.cpp"
        ```

## Bài tập

-   [CF601E A Museum Robbery](https://codeforces.com/problemset/problem/601/E) chia để trị bằng cây đoạn + quy hoạch động ba lô.
-   [CF19E Fairy](https://codeforces.com/problemset/problem/19/E) chia để trị bằng cây đoạn + DSU duy trì tính chẵn lẻ.
-   [luogu P5227 \[AHOI2013\] Đồ thị liên thông](https://www.luogu.com.cn/problem/P5227) chia để trị bằng cây đoạn + DSU.
-   [luogu P4319 Những con đường thay đổi](https://www.luogu.com.cn/problem/P4319) chia để trị bằng cây đoạn + cây Link-Cut để duy trì cây khung nhỏ nhất.
-   [luogu P3733 \[HAOI2017\] Tám tung tám hoành](https://www.luogu.com.cn/problem/P3733) chia để trị bằng cây đoạn + cơ sở tuyến tính.

**Một phần nội dung của trang này tham khảo từ bài viết [Deleting from a data structure](https://cp-algorithms.com/data_structures/deleting_in_log_n.html), với giấy phép CC-BY-SA 4.0.**
