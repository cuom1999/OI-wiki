<span id="kiến-thức-nền"></span>
## Kiến thức nền

Máy tự động hậu tố tổng quát dựa trên các kiến thức sau:

-   [Cây từ điển (Trie)](./trie.md)
-   [Máy tự động hậu tố](./sam.md)

Hãy chắc chắn rằng bạn đã rất quen thuộc với hai chủ đề trên trước khi đọc bài này, đặc biệt là có hiểu biết nhất định về **liên kết hậu tố** trong **máy tự động hậu tố**.

<span id="dẫn-nhập"></span>
## Dẫn nhập

<span id="nguồn-gốc"></span>
### Nguồn gốc

Máy tự động hậu tố tổng quát là một cấu trúc do Liu Yanyi đề xuất trong bài luận đội tuyển quốc gia năm 2015 "Mở rộng máy tự động hậu tố trên cây từ điển"; nói ngắn gọn là xây dựng trực tiếp máy tự động hậu tố trên cây từ điển.

> Phần lớn các bài toán chuỗi có thể xử lý bằng máy tự động hậu tố đều có thể mở rộng lên cây Trie. -- Liu Yanyi

<span id="quy-ước"></span>
### Quy ước

Tham khảo [quy ước về chuỗi](./basic.md).

Số lượng chuỗi là $k$, tức $S_1, S_2, S_3 \dots S_k$.

Quy ước nút gốc của cây từ điển và máy tự động hậu tố tổng quát là nút số $0$.

<span id="tổng-quan"></span>
### Tổng quan

Máy tự động hậu tố (suffix automaton, SAM) là một công cụ mạnh để xử lý các bài toán chuỗi con của một chuỗi đơn.

Máy tự động hậu tố tổng quát (General Suffix Automaton) tích hợp máy tự động hậu tố vào cây từ điển để giải các bài toán chuỗi con trên nhiều chuỗi.

<span id="các-máy-tự-động-hậu-tố-tổng-quát-giả-thường-gặp"></span>
## Các máy tự động hậu tố tổng quát giả thường gặp

1.  Nối trực tiếp nhiều chuỗi bằng các ký hiệu đặc biệt rồi xây dựng SAM.
2.  Với từng chuỗi, tiếp tục xây dựng trên cùng một SAM, và trước mỗi lần xây dựng đặt con trỏ `last` về không.

Cách 1 và cách 2 có cài đặt đơn giản, và khi giải bài thường có thể đạt tính đúng đắn giống máy tự động hậu tố tổng quát. Vì vậy trên mạng có nhiều lời giải chọn kiểu viết này; chẳng hạn ứng dụng cuối cùng trong bài máy tự động hậu tố dùng cách 1 [xem liên kết gốc](./sam.md).

Tuy nhiên, cả cách 1 lẫn cách 2 đều có độ phức tạp thời gian khá rủi ro.

<span id="xây-dựng-máy-tự-động-hậu-tố-tổng-quát"></span>
## Xây dựng máy tự động hậu tố tổng quát

Theo mô tả trong bài luận gốc, ta nên xây dựng cây từ điển trên nhiều chuỗi trước, rồi xây dựng máy tự động hậu tố tổng quát trên cơ sở cây từ điển đó.

<span id="sử-dụng-cây-từ-điển"></span>
### Sử dụng cây từ điển

Trước hết cần tạo một cây từ điển cho nhiều chuỗi. Đây không phải việc khó; nếu bạn đã nắm chắc kiến thức nền thì có thể xây dựng nhanh chóng. Để thống nhất mã trong phần giải thích, dưới đây là một cài đặt cây từ điển khả dĩ.

??? note "Cài đặt"
    ```cpp
    constexpr int MAXN = 2000000;
    constexpr int CHAR_NUM = 30;
    
    struct Trie {
      int next[MAXN][CHAR_NUM];  // Chuyen trang thai
      int tot;                   // Tong so nut: [0, tot)
    
      void init() { tot = 1; }
    
      int insertTrie(int cur, int c) {
        if (next[cur][c]) return next[cur][c];
        return next[cur][c] = tot++;
      }
    
      void insert(const string &s) {
        int root = 0;
        for (auto ch : s) root = insertTrie(root, ch - 'a');
      }
    };
    ```

Đến đây ta đã thu được một cây từ điển được xây dựng dựa trên mảng `next`.

<span id="xây-dựng-máy-tự-động-hậu-tố"></span>
### Xây dựng máy tự động hậu tố

Nếu xem trực tiếp cây này như một máy tự động hậu tố, ta có các kết luận sau:

-   Với nút `i`, `len[i]` bằng đúng độ sâu của nó trong cây từ điển.
-   Nếu sắp xếp tô pô cây từ điển, ta nhận được một dãy có `len` không giảm. Kết quả BFS cũng như vậy.

Trong quá trình xây dựng máy tự động hậu tố, có thể xem như ta liên tục chèn các giá trị `len` tăng nghiêm ngặt, với hiệu là $1$. Vì thế có thể lấy kết quả sắp xếp tô pô của cây từ điển làm một hàng đợi, rồi lần lượt chèn vào máy tự động hậu tố theo thứ tự trong hàng đợi này.

Trong SAM thông thường, giá trị `len` của nút trước đó là cố định, chính là `len` của nút `last`. Nhưng trong máy tự động hậu tố tổng quát, hàng đợi được chèn là một dãy không giảm nhưng không nghiêm ngặt. Vì vậy, với mỗi giá trị, `last` của nó phải đã biết và cố định; trên cây từ điển, đó chính là nút cha của nó.

Vì trong cây từ điển đã có một cấu trúc gần giống máy tự động hậu tố, ta chỉ cần xử lý cấu trúc của toàn bộ cây từ điển để chuyển nó thành máy tự động hậu tố tổng quát. Có thể cập nhật từng nút trên cây từ điển theo thứ tự hàng đợi nêu trên. Cuối cùng ta thu được máy tự động hậu tố tổng quát.

Thao tác cập nhật cho mỗi điểm có thể thu được bằng cách sửa nhẹ thao tác chèn trong SAM.

Trong toàn bộ quá trình chèn, cần chú ý rằng do các nút được chèn theo thứ tự `len` không giảm, khi sao chép dữ liệu sau khi `clone`, không được sao chép dữ liệu có `len` nhỏ hơn `len` hiện tại.

<span id="quy-trình"></span>
### Quy trình

Theo logic trên, toàn bộ quá trình xây dựng có thể mô tả như sau:

1.  Chèn tất cả chuỗi vào cây từ điển.
2.  Bắt đầu BFS từ gốc cây từ điển, ghi lại thứ tự và nút cha của từng nút.
3.  Duyệt dãy BFS theo thứ tự nhận được, xây dựng cho từng nút trên cây từ điển ban đầu, chú ý không thao tác trên dữ liệu có `len` nhỏ hơn `len` hiện tại.

<span id="chứng-minh-số-thao-tác-là-tuyến-tính"></span>
### Chứng minh số thao tác là tuyến tính

Vì chỉ xử lý dãy thu được từ BFS, ta bảo đảm mỗi nút trên cây từ điển chỉ được đi qua một lần.

Trong trường hợp xấu nhất, xét khi bản thân cây từ điển có số nút lớn nhất, tức là không có hai chuỗi bất kỳ nào có tiền tố chung. Khi đó số nút là $\sum_{i=1}^{k}|S_i|$, chính là tổng độ dài mọi chuỗi.

Độ phức tạp của thao tác cập nhật trong máy tự động hậu tố đã được chứng minh trong bài [máy tự động hậu tố](./sam.md).

Do đó có thể chứng minh độ phức tạp xấu nhất là tuyến tính.

Thông thường, độ phức tạp trung bình của máy tự động hậu tố tổng quát giả ngang với độ phức tạp xấu nhất của máy tự động hậu tố tổng quát chuẩn. Khi phải xử lý lượng lớn chuỗi, hiệu suất của máy tự động hậu tố tổng quát giả kém xa cấu trúc chuẩn.

<span id="cài-đặt"></span>
### Cài đặt

Chỉ cần sửa một lượng nhỏ cần thiết trong hàm chèn là có thể thu được hàm cần dùng.

??? note "Mã tham khảo"
    ```cpp
    struct GSA {
      int len[MAXN];             // Do dai nut
      int link[MAXN];            // Lien ket hau to, link
      int next[MAXN][CHAR_NUM];  // Chuyen trang thai
      int tot;                   // Tong so nut: [0, tot)
    
      int insertSAM(int last, int c) {
        int cur = next[last][c];
        len[cur] = len[last] + 1;
        int p = link[last];
        while (p != -1) {
          if (!next[p][c])
            next[p][c] = cur;
          else
            break;
          p = link[p];
        }
        if (p == -1) {
          link[cur] = 0;
          return cur;
        }
        int q = next[p][c];
        if (len[p] + 1 == len[q]) {
          link[cur] = q;
          return cur;
        }
        int clone = tot++;
        for (int i = 0; i < CHAR_NUM; ++i)
          next[clone][i] = len[next[q][i]] != 0 ? next[q][i] : 0;
        len[clone] = len[p] + 1;
        while (p != -1 && next[p][c] == q) {
          next[p][c] = clone;
          p = link[p];
        }
        link[clone] = link[q];
        link[cur] = clone;
        link[q] = clone;
        return cur;
      }
    
      void build() {
        queue<pair<int, int>> q;
        for (int i = 0; i < CHAR_NUM; ++i)
          if (next[0][i]) q.push({i, 0});
        while (!q.empty()) {
          auto item = q.front();
          q.pop();
          auto last = insertSAM(item.second, item.first);
          for (int i = 0; i < CHAR_NUM; ++i)
            if (next[last][i]) q.push({i, last});
        }
      }
    }
    ```

-   Vì thứ tự thu được từ toàn bộ quá trình BFS có nút cha luôn thay đổi, ta không cần lưu con trỏ `last`.
-   Trong thao tác chèn, `int cur = next[last][c];` khác với `int cur = tot++;` của máy tự động hậu tố thông thường, vì nút cần chèn đã được tạo xong trong cấu trúc cây, nên chỉ cần lấy trực tiếp.
-   Khi sao chép dữ liệu sau `clone`, có kiểm tra `next[clone][i] = len[next[q][i]] != 0 ? next[q][i] : 0;`. Điều này khác với phép gán trực tiếp `next[clone][i] = next[q][i];` trong máy tự động hậu tố thông thường, nhằm tránh cập nhật các giá trị có `len` lớn hơn nút hiện tại. Trong mảng, `len` chỉ được gán khi và chỉ khi giá trị đó đã được BFS duyệt tới và chèn vào máy tự động hậu tố.

<span id="tính-chất"></span>
## Tính chất

1.  Máy tự động hậu tố tổng quát có cấu trúc nhất quán với máy tự động hậu tố; phần lớn các tính chất trên máy tự động hậu tố đều có hiệu lực trên máy tự động hậu tố tổng quát ([tính chất của máy tự động hậu tố](./sam.md)).
2.  Sau khi xây dựng máy tự động hậu tố tổng quát, cấu trúc cây từ điển thường sẽ bị phá vỡ, tức là thông thường không thể dùng máy tự động hậu tố tổng quát để giải bài toán cây từ điển. Dĩ nhiên cũng có thể chuẩn bị gấp đôi bộ nhớ và xây dựng máy tự động hậu tố trong một vùng khác.

<span id="ứng-dụng"></span>
## Ứng dụng

<span id="số-chuỗi-con-khác-nhau-trong-tất-cả-chuỗi"></span>
### Số chuỗi con khác nhau trong tất cả chuỗi

Theo tính chất của máy tự động hậu tố, số chuỗi con có nút kết thúc là điểm $i$ bằng $len[i] - len[link[i]]$.

Vì vậy có thể duyệt tất cả nút và lấy tổng.

Bài ví dụ: [[Mẫu] Máy tự động hậu tố tổng quát (SAM tổng quát)](https://www.luogu.com.cn/problem/P6139)

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/general-sam/general-sam_1.cpp"
    ```

<span id="chuỗi-con-chung-dài-nhất-giữa-nhiều-chuỗi"></span>
### Chuỗi con chung dài nhất giữa nhiều chuỗi

Ta cần xây dựng cho mỗi nút một mảng `flag` có độ dài $k$ (với bài này, có thể chỉ là mảng đánh dấu; nếu cần tính số lần xuất hiện của chuỗi con này, cần đổi thành mảng đếm).

Khi chèn chuỗi vào cây từ điển, đếm trên tất cả nút và lưu vào mảng tương ứng với chuỗi hiện tại.

Sau đó duyệt theo thứ tự `len` giảm dần, dùng liên kết hậu tố để hợp nhất `flag` của nút hiện tại vào các nút khác.

Duyệt tất cả nút, tìm một nút có `len` lớn nhất và thỏa mãn với mọi chỉ số trong $k$, giá trị `flag` của nó đều khác $0$. Khi đó $len$ của nút này là đáp án.

Bài ví dụ: [SPOJ Longest Common Substring II](https://www.spoj.com/problems/LCS2/)

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/string/code/general-sam/general-sam_2.cpp"
    ```
