author: mwsht, sshwy, ouuan, Ir1d, Henry-ZHR, hsfzLZH1

## Giới thiệu

Phương pháp đường treo có phạm vi áp dụng là một trường hợp đặc biệt của ngăn xếp đơn điệu. Cụ thể, có thể áp dụng phương pháp đường treo cho các bài toán thỏa mãn các điều kiện sau:

-   Cần duy trì thông tin đơn điệu khi quét dãy;
-   Có thể giải bằng ngăn xếp đơn điệu;
-   Không cần tìm kiếm nhị phân trên ngăn xếp đơn điệu.

Thoạt nhìn, phương pháp đường treo có thể được thay thế và không quá hữu dụng. Tuy vậy, khái niệm của nó đơn giản hơn ngăn xếp đơn điệu, phù hợp hơn để người mới học OI hiểu và giải các bài như hình chữ nhật con lớn nhất.

## Ví dụ

???+ note "[SPOJ HISTOGRA - Largest Rectangle in a Histogram](https://www.spoj.com/problems/HISTOGRA)"
    Tóm tắt: Trên một đường thẳng nằm ngang có $n$ hình chữ nhật, mỗi hình rộng $1$. Cần tìm diện tích hình chữ nhật con lớn nhất nằm trong các hình chữ nhật đó.

Đường treo là một đoạn thẳng đứng. Đoạn thẳng này có hai thuộc tính là vị trí ban đầu và chiều cao; nó có thể di chuyển sang trái hoặc phải miễn là đầu trên của nó không vượt quá chiều cao hình chữ nhật tại vị trí hiện tại.

Với một đường treo, di chuyển nó sang trái và phải trong điều kiện đầu trên không vượt quá chiều cao hình chữ nhật tại vị trí hiện tại và không ra khỏi biên, từ đó tìm vị trí xa nhất mà nó có thể mở rộng sang trái và sang phải. Khi đó diện tích mà đường treo quét qua chính là hình chữ nhật lớn nhất có thể chứa đường treo này. Hình chữ nhật con lớn nhất luôn chứa một đường treo có vị trí ban đầu là $i$ và chiều cao là $h_i$. Nếu mô phỏng bằng cách liệt kê thì độ phức tạp là $O(n ^ 2)$, nhưng có thể dùng phương pháp đường treo để tối ưu xuống $O(n)$.

Xét cách nhanh chóng tìm vị trí ngoài cùng bên trái mà đường treo có thể chạm tới.

### Quy trình

Định nghĩa $l_i$ là vị trí ngoài cùng bên trái hiện tìm được mà đường treo tại vị trí $i$ có thể mở rộng tới. Ban đầu $l_i=i$; tiếp theo cần kiểm tra xem nó còn có thể mở rộng thêm sang trái hay không.

-   Nếu hiện tại $l_i = 1$, đường treo đã mở rộng tới biên, nên không thể mở rộng thêm.
-   Nếu hiện tại $a_i > a_{l_i - 1}$, đường treo không thể mở rộng thêm sang trái từ vị trí hiện tại.
-   Nếu hiện tại $a_i \le a_{l_i - 1}$, đường treo vẫn có thể mở rộng sang trái; hơn nữa, vị trí ngoài cùng bên trái mà đường treo tại $l_i - 1$ có thể mở rộng tới thì đường treo tại $i$ cũng mở rộng tới được. Vì vậy cập nhật $l_i$ thành $l_{l_i - 1}$ rồi tiếp tục kiểm tra.

Bằng phân tích khấu hao, có thể chứng minh mỗi $l_i$ nhiều nhất chỉ bị các $l_j$ khác duyệt tới một lần, nên độ phức tạp thời gian là $O(n)$.

### Cài đặt

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/hoverline/hoverline_1.cpp"
    ```

???+ note "[UVa1619 Feel Good](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4494)"
    Với một dãy số độ dài $n$, cần tìm một đoạn con sao cho tích giữa giá trị nhỏ nhất trong đoạn và tổng các phần tử trong đoạn là lớn nhất. Khi cùng đạt giá trị thoải mái lớn nhất, yêu cầu đoạn có độ dài nhỏ nhất; nếu vẫn còn hòa, chọn đoạn có chỉ số đầu trái nhỏ nhất.

Trong bài này, có thể xét liệt kê giá trị nhỏ nhất: xem số $a_i$ ở mỗi vị trí là giá trị nhỏ nhất, rồi mở rộng từ $i$ sang hai bên để tìm đoạn $[l, r]$ mở rộng xa nhất sao cho $\min\limits _ {j = l} ^ r a_j = a_i$. Như vậy bài toán được chuyển thành mô hình đường treo.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/hoverline/hoverline_2.cpp"
    ```

## Hình chữ nhật con lớn nhất

???+ note "[P4147 Yu Chan Gong](https://www.luogu.com.cn/problem/P4147)"
    Cho một ma trận $n \times m$ gồm các ký tự `'F'` và `'R'`. Cần tìm diện tích của ma trận con lớn nhất chỉ gồm toàn ký tự `'F'`, rồi nhân diện tích đó với $3$.

Mô hình của bài này rất giống bài đầu tiên. Phân tích kỹ hơn, nếu mỗi lần chỉ xét tất cả phần tử trên một hàng, rồi lấy khoảng cách mà phần tử tại vị trí $(x, y)$ có thể mở rộng lên trên xa nhất làm độ dài đường treo tại vị trí đó, thì ma trận con lớn nhất là một trong các hình chữ nhật lớn nhất thu được bằng cách mở rộng các đường treo này sang trái và phải.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/hoverline/hoverline_3.cpp"
    ```

## Bài tập

-   [P1169 \[ZJOI2007\] Làm bàn cờ](https://www.luogu.com.cn/problem/P1169)
