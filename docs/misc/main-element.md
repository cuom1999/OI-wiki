author: SDLTF, Ethkuil

## Giới thiệu bài toán

Cho một dãy có $n$ phần tử, bảo đảm có một phần tử $a$ xuất hiện **lớn hơn** $n/2$ lần. Hãy tìm phần tử đó.

## Cách làm

### Thuật toán offline

Nếu biết toàn bộ dãy ngay từ đầu, một ý tưởng tự nhiên là thống kê số lần xuất hiện của từng phần tử trong dãy; phần tử có số lần xuất hiện lớn hơn $n/2$ chính là phần tử đa số. Có thể tạo một mảng đếm để thống kê số lần xuất hiện của từng giá trị, rồi xuất ra phần tử xuất hiện nhiều hơn $n/2$ lần.

Tuy nhiên, cách trên dùng thêm mảng đếm nên hiệu quả bộ nhớ không tốt. Rõ ràng, nếu dãy có phần tử đa số, thì sau khi sắp xếp, phần tử thứ $\lfloor n/2\rfloor+1$ của dãy chắc chắn là phần tử đa số. Ta có thể dùng [`nth_element`](https://en.cppreference.com/w/cpp/algorithm/nth_element.html) để tìm phần tử này. Như vậy, không cần thêm bộ nhớ phụ đáng kể mà vẫn tìm được phần tử đa số với độ phức tạp tuyến tính.

### Thuật toán online

Trong một số trường hợp, ta cần xử lý dữ liệu dạng luồng theo thời gian thực. Khi đó cần một thuật toán không cần biết trước toàn bộ dữ liệu, mà chỉ dùng dữ liệu hiện có để dần dần tìm đáp án. **Thuật toán bỏ phiếu đa số** [^ref1] là một thuật toán có thể giải bài toán phần tử đa số theo cách online.

Vì phần tử đa số xuất hiện nhiều hơn $n/2$ lần, nên với một dãy đầy đủ, nếu liên tục loại bỏ một phần tử đa số cùng một phần tử khác nó, cuối cùng chắc chắn còn lại phần tử đa số. Dựa trên quan sát này, ta có thể thiết kế một thuật toán online thực hiện thao tác khử như vậy. Gọi hai biến `val` và `cnt` lần lượt là ứng viên phần tử đa số hiện tại và số lượng ứng viên còn lại sau các thao tác khử giả định. Ban đầu đặt `cnt` bằng $0$. Mỗi lần lấy một phần tử từ luồng dữ liệu, nếu `cnt` hiện bằng $0$, điều đó nghĩa là ứng viên phần tử đa số đã bị khử hết, `val` hiện tại chắc chắn không còn là phần tử đa số trong phần còn lại, nên đặt phần tử hiện tại làm ứng viên mới. Sau đó kiểm tra phần tử hiện tại có bằng ứng viên hay không. Nếu có, tăng `cnt` thêm $1$; nếu không, phần tử này sẽ bị khử cùng một ứng viên, nên giảm `cnt` đi $1$. Lặp lại đến khi đọc hết luồng dữ liệu, `val` chính là phần tử đa số.

???+ warning "Chú ý"
    Khi dữ liệu ban đầu không có phần tử đa số, kết quả do thuật toán này trả về là sai. Nếu cần xác định dãy có phần tử đa số hay không, cần đọc lại luồng dữ liệu, thống kê số lần xuất hiện của `val`, rồi kiểm tra số đó có vượt quá $n/2$ hay không.
    
    Để đọc lại luồng dữ liệu, có thể đặt lại con trỏ vị trí nhập, chẳng hạn dùng các hàm thư viện như [`std::basic_istream<CharT,Traits>::seekg`](https://en.cppreference.com/w/cpp/io/basic_istream/seekg) với nhập dạng stream, hoặc [`rewind`](https://en.cppreference.com/w/c/io/rewind), [`fseek`](https://en.cppreference.com/w/c/io/fseek) với nhập kiểu C.

## Bài tập ví dụ

???+ example "[Luogu P2397 yyy loves Maths VI (mode)](https://www.luogu.com.cn/problem/P2397)"
    Tìm phần tử đa số của dãy đã cho.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/main-element/main-element_1.cpp"
    ```

???+ example "[LeetCode 229. Phần tử đa số II](https://leetcode.cn/problems/majority-element-ii)"
    Cho một mảng số nguyên kích thước $n$, hãy tìm tất cả các phần tử xuất hiện nhiều hơn $\lfloor n/3\rfloor$ lần.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/main-element/main-element_2.cpp:core"
    ```

## Tài liệu tham khảo

[^ref1]: [Thuật toán bỏ phiếu đa số - Wikipedia](https://zh.wikipedia.org/zh-cn/%E5%A4%9A%E6%95%B0%E6%8A%95%E7%A5%A8%E7%AE%97%E6%B3%95)
