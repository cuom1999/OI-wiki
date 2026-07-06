Các kỹ thuật liên quan đến tối ưu không gian không quá thường gặp trong lập trình thi đấu, nhưng vẫn đáng để thảo luận.

## Entropy thông tin

Entropy thông tin mô tả cận dưới của không gian cần để lưu trữ dữ liệu. Nếu không gian thực tế có thể dùng thấp hơn cận dưới này, thông tin sẽ bị mất.

???+ note "Định nghĩa"
    Với biến ngẫu nhiên $X$, định nghĩa entropy thông tin là
    
    $$
    H(X)=-\sum_{x}P(X=x)\log_2 P(X=x).
    $$

Trong định nghĩa, cơ số của logarit là $2$ vì mỗi bit thông tin được lưu trong máy tính chỉ có $2$ giá trị có thể nhận: $0$ và $1$.

Ví dụ, giả sử $X$ tuân theo phân phối đều trên $\{1,2,\dots,n\}$, thì entropy thông tin của nó là

$$
H(X)=-\sum_{i=1}^n\frac{1}{n}\log_2\frac{1}{n}=\log_2 n,
$$

vì vậy cần ít nhất $\log_2 n$ bit để lưu một số nguyên từ $1$ đến $n$.

### Bài tập ví dụ

???+ note "[\[WC2022\] Đoán từ](https://www.luogu.com.cn/problem/P8079)"
    Bài tương tác, cần đoán một từ gồm 5 chữ cái trong số lần hữu hạn. Mỗi lần đoán phải đoán một từ tồn tại trong từ điển. Nếu đoán đúng, trò chơi kết thúc; sau mỗi lần đoán sai, thư viện tương tác sẽ trả về những chữ cái nào ở đúng vị trí, và những chữ cái nào xuất hiện trong từ cần đoán nhưng ở sai vị trí.
    
    ??? note "Lời giải"
        Tham khảo [Giải câu đố Wordle bằng lý thuyết thông tin - 3Blue1Brown](https://www.bilibili.com/video/BV1zZ4y1k7Jw).
        
        Xét việc tính entropy thông tin. Mỗi lần đoán chọn từ có entropy thông tin cao sẽ làm số lần đoán kỳ vọng nhỏ nhất có thể.
        
        Vì bài này cho biết chữ cái đầu của đáp án trước khi đoán, có thể tiền xử lý lựa chọn đoán tối ưu cho từng chữ cái đầu.
        
        Ngoài ra, nếu số từ còn lại rất ít, có thể ưu tiên xuất ra những từ có khả năng là đáp án, từ đó giảm số lần đoán.

## Kỹ thuật thường gặp

### Tránh lưu dữ liệu không cần thiết

Ví dụ:

-   Trong [cây đoạn bền vững](../ds/persistent-seg.md), vì mỗi lần sửa đổi chỉ sinh ra $O(\log n)$ nút mới, không cần lưu trữ đầy đủ cây đoạn của mọi phiên bản, mà chỉ cần ghi lại các nút mới.
-   Xét [lưu trữ đồ thị](../graph/save.md), với đồ thị thưa, nếu dùng ma trận kề thì sẽ lưu rất nhiều số $0$ vô dụng, nên thông thường dùng danh sách kề để lưu đồ thị thưa.
-   Mỗi phần tử của mảng `bool` đều chiếm một byte bộ nhớ. Khi cần, có thể thay bằng `std::vector<bool>` hoặc [bitset](../lang/csl/bitset.md), trong đó mỗi phần tử chỉ chiếm một bit.
-   Trong [DP ba lô](../dp/knapsack.md), với ba lô 01, mỗi lần tính giá trị DP chỉ dùng dữ liệu của lần tính trước, nên có thể dùng mảng cuốn để tối ưu không gian và chỉ cần ghi lại giá trị DP hiện tại.

### Tận dụng đặc tính dữ liệu

Xét [DSU](../ds/dsu.md) hỗ trợ nén đường đi và gộp theo kinh nghiệm. Cách làm truyền thống cần hai mảng, lần lượt ghi lại chỉ số nút cha và kích thước cây con.

Lưu ý:

1.  Sau khi áp dụng nén đường đi, với một cây trong DSU, chỉ cần ghi lại kích thước cây con tương ứng với nút gốc.
2.  Cha của nút gốc là chính nó.

Có thể tận dụng đặc tính của số nguyên có dấu: dùng số âm để biểu diễn nút gốc, số dương để biểu diễn nút không phải gốc. Vì vậy chỉ cần một mảng là có thể cài đặt DSU hỗ trợ nén đường đi và gộp theo kinh nghiệm.

???+ note "Cài đặt"
    ```cpp
    --8<-- "docs/misc/code/space-optimization/space-optimization_1.cpp"
    ```

## Bài tập

-   [QOJ 6669 Mapa](https://qoj.ac/problem/6669)
-   [\[SDOI/SXOI2022\] Không nơi lưu trữ](https://www.luogu.com.cn/problem/P8353)

## Tài liệu tham khảo và đọc thêm

1.  Chen Zhixuan. "Bàn về các vấn đề tối ưu không gian trong thi đấu tin học". 2022 National Training Team Paper
2.  [Information theory - Wikipedia](https://en.wikipedia.org/wiki/Information_theory)
3.  [Nhập môn lý thuyết thông tin - Luogu Column](https://www.luogu.com.cn/article/i65ca8i5)
