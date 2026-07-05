author: Estrella-Explore, H-J-Granger, orzAtalod, ksyx, Ir1d, Chrogeek, Enter-tainer, yiyangit, shuzhouliu, broken-paint, CarvingAn

Trang này liệt kê một số lỗi rất nhiều người thường gặp trong thi đấu.

## Lỗi do môi trường khác nhau

-   Dùng định dạng `%I64d` với `scanf` hoặc `printf` có thể gây lỗi định dạng
    nhập xuất trên Linux.

## Lỗi gây CE

Nhóm lỗi này phần lớn là lỗi từ vựng, cú pháp hoặc ngữ nghĩa. Nguyên nhân
thường đơn giản và tương đối dễ sửa.

Ví dụ:

-   Gõ sai chính tả, chẳng hạn viết `int main()` thành `int mian()`.

-   Quên dấu chấm phẩy sau khi viết xong `struct` hoặc `class`.

-   Khai báo mảng quá lớn, dùng hàm không hợp lệ trên OJ (ví dụ đa luồng), hoặc
    khai báo hàm nhưng không định nghĩa, gây lỗi liên kết.

-   Kiểu tham số hàm không khớp.

    -   Ví dụ: khi dùng hàm `max` trong tệp tiêu đề `<algorithm>`, truyền vào một
        tham số kiểu `int` và một tham số kiểu `long long`.

        ```cpp
        // query là hàm tự định nghĩa trả về long long
        printf("%lld\n", max(0, query(1, 1, n, l, r));

        // lỗi: không có overload "std::max" khớp với danh sách tham số
        ```

-   Khi dùng `goto` và `switch-case`, nhảy qua phần khởi tạo của một số biến
    cục bộ.

<span id="lỗi-không-gây-ce-nhưng-gây-warning"></span>

## Lỗi không gây CE nhưng gây cảnh báo

Chương trình mắc các lỗi này vẫn biên dịch được, nhưng rất có khả năng cho kết
quả chạy sai. Trình biên dịch có thể chỉ ra những lỗi này khi dùng tùy chọn
`-W{loại_cảnh_báo}`.

-   Nhầm toán tử gán `=` với toán tử so sánh `==`.

    -   Ví dụ:

        ```cpp
        std::srand(std::time(nullptr));
        int n = std::rand();
        if (n = 1)
          printf("Yes");
        else
          printf("No");

        // Dù n nhận giá trị ngẫu nhiên nào, kết quả chắc chắn là Yes.
        // Cảnh báo: toán tử không đúng, gán hằng trong ngữ cảnh Boolean.
        // Nên cân nhắc dùng "==".
        ```

    -   Nếu thật sự muốn dùng `=` trong câu lệnh vốn thường dùng `==`, chẳng
        hạn `while (foo = bar)`, và không muốn nhận cảnh báo, có thể dùng
        **hai cặp ngoặc**: `while ((foo = bar))`.

-   Lỗi do độ ưu tiên toán tử.

    -   Ví dụ:

        ```cpp
        // Sai
        // std::cout << (1 << 1 + 1);
        // Đúng
        std::cout << ((1 << 1) + 1);

        // Cảnh báo: kiểm tra khả năng lỗi độ ưu tiên của toán tử "<<";
        // dùng ngoặc để làm rõ độ ưu tiên.
        ```

-   Dùng từ khóa bổ trợ `static` không đúng.

-   Khi dùng `scanf` để đọc, quên toán tử lấy địa chỉ `&`.

-   Khi dùng `scanf` hoặc `printf`, kiểu tham số không khớp với định dạng.

-   Dùng đồng thời phép bit và toán tử logic `==` mà không thêm ngoặc.
    -   Ví dụ: `(x >> j) & 3 == 2`

-   Hằng trực tiếp kiểu `int` bị tràn.

    -   Ví dụ: `long long x = 0x7f7f7f7f7f7f7f7f`, `1<<62`.

-   Biến cục bộ chưa khởi tạo.

    ???+ note "Biến chưa khởi tạo sẽ xảy ra chuyện gì?"
        Nguồn gốc: <https://loj.ac/d/3679> bởi @hly1204

        Ví dụ, trong C++ ta khai báo `int a;` nhưng không khởi tạo. Đôi khi có
        thể nghĩ rằng `a` là một giá trị "ngẫu nhiên" (thực ra chưa chắc là
        ngẫu nhiên thật), hoặc xem nó như một giá trị cố định, nhưng thực tế
        không phải vậy.

        Với đoạn mã kiểm thử đơn giản:

        <https://wandbox.org/permlink/T2uiVe4n9Hg4EyWT>

        Mã là:

        ```cpp
        #include <iostream>

        int main() {
          int a;
          std::cout << std::boolalpha << (a < 0 || a == 0 || a > 0);
          return 0;
        }
        ```

        Trên một số trình biên dịch và môi trường, sau khi bật tối ưu, chương trình
        in ra `false`.

        Nếu quan tâm, bạn có thể đọc
        <https://www.ralfj.de/blog/2019/07/14/uninit.html>. Dù bài viết dùng
        Rust để thử nghiệm, bản chất vấn đề là như nhau.

-   Biến cục bộ trùng tên với biến toàn cục, khiến biến toàn cục bị che khuất
    ngoài ý muốn. Bật `-Wshadow` có thể kiểm tra loại lỗi này.

-   Lỗi xuất phát từ nạp chồng toán tử.
    -   Ví dụ:

        ```cpp
        // Ý định ban đầu: << thứ nhất là toán tử đã nạp chồng, biểu thị xuất;
        // << thứ hai là toán tử dịch bit, biểu thị dịch 1 sang trái 1 bit.
        // Nhưng vì quên thêm ngoặc, trình biên dịch cũng xem << thứ hai là toán tử
        // xuất, khiến kết quả khác dự kiến.
        // Sai:  std::cout << 1 << 1;
        // Đúng:
        std::cout << (1 << 1);
        ```

<span id="lỗi-không-gây-ce-cũng-không-gây-warning"></span>

## Lỗi không gây CE cũng không gây cảnh báo

Những lỗi này trình biên dịch không phát hiện được, chỉ có thể tự tìm.

### Lỗi dẫn đến WA

-   Sau khi xử lý xong một bộ dữ liệu, trước khi đọc bộ dữ liệu tiếp theo, quên
    xóa mảng.

-   Tối ưu đọc vào không xét số âm.

-   Kiểu dữ liệu dùng không đủ độ rộng bit, dẫn đến tràn.
    -   Đây là tình huống được mô tả bằng câu quen thuộc "ba năm OI thành công
        cốc, không dùng `long long` là gặp tổ tiên". Thí sinh không dùng
        `long long` ở đúng chỗ, dẫn đến đáp án sai và mất điểm.

-   Khi lưu đồ thị, chỉ số đỉnh trong chương trình bắt đầu từ 0, nhưng hai đầu
    mút của cạnh trong đề bắt đầu từ 1, và khi đọc quên trừ 1.

-   Gõ sai hoặc đảo ngược dấu lớn hơn/nhỏ hơn.

-   Sau khi gọi `ios::sync_with_stdio(false);`, trộn hai kiểu IO
    `scanf/printf` và `std::cin/std::cout`, dẫn đến nhập/xuất lẫn lộn.

    -   Ví dụ:

        ```cpp
        // Ví dụ này minh họa hậu quả của việc trộn hai cách IO sau khi tắt
        // đồng bộ với stdio. Nên chạy từng bước để quan sát hiệu ứng.
        #include <cstdio>
        #include <iostream>

        int main() {
          // Sau khi tắt đồng bộ, cin/cout dùng bộ đệm độc lập thay vì đồng bộ
          // đầu ra với bộ đệm của scanf/printf, nhờ đó giảm thời gian IO.
          std::ios::sync_with_stdio(false);
          // Với cout, khi dùng '\n', nội dung được đưa vào bộ đệm và không in ngay.
          std::cout << "a\n";
          // '\n' của printf sẽ flush bộ đệm của printf, làm thứ tự đầu ra lệch.
          printf("b\n");
          std::cout << "c\n";
          // Khi chương trình kết thúc, bộ đệm của cout mới được in ra.
          return 0;
        }
        ```

-   Lỗi do macro mở rộng nhưng không thêm ngoặc.

    -   Ví dụ: macro sau trả về $2+2\times 2+2 = 8$, không phải $4^2 = 16$.

        ```cpp
        #define square(x) x* x
        printf("%d", square(2 + 2));
        ```

-   Khi hash không dùng `unsigned`, dẫn đến lỗi tính toán.
    -   Dịch phải số âm sẽ bù 1 ở bit cao nhất. Xem thêm:
        [toán tử bit](../lang/op.md#toán-tử-bit).

-   Quên xóa hoặc chú thích câu lệnh xuất gỡ lỗi.

-   Thêm nhầm `;`.

    -   Ví dụ:

        ```cpp
        /* clang-format off */
        while (1);
            printf("OI Wiki!\n");
        ```

-   Đặt sentinel sai, chẳng hạn nút `0` trong cây cân bằng.

-   Khi dùng `:` trong constructor của class hoặc struct để khởi tạo biến, thứ
    tự khai báo biến không phù hợp với quan hệ phụ thuộc khi khởi tạo.

    -   Thứ tự khởi tạo biến thành viên phụ thuộc vào thứ tự khai báo trong
        class, không phụ thuộc vào thứ tự trong initializer list. Xem mục
        "Initialization order" của
        [constructor và member initializer list](https://en.cppreference.com/w/cpp/language/constructor).
    -   Ví dụ:

        ```cpp
        #include <iostream>

        class Foo {
         public:
          int a, b;

          // a được khởi tạo trước b, nên giá trị của b lúc này không xác định.
          Foo(int x) : b(x), a(b + 1) {}
        };

        int main() {
          Foo bar(1, 2);
          std::cout << bar.a << ' ' << bar.b;
        }

        // Một kết quả có thể xảy ra: -858993459 1
        ```

-   Khi hợp nhất tập hợp trong DSU, không hợp nhất tổ tiên của hai phần tử.

    -   Ví dụ:

        ```cpp
        f[a] = b;              // Sai
        f[find(a)] = find(b);  // Đúng
        ```

-   Dùng `freopen` với chế độ `a` để ghi nối tiếp.
    -   Môi trường kiểm tra của CCF không xóa tệp đầu ra; dùng `a` có thể làm
        đầu ra của thí sinh trước cũng bị máy chấm đọc vào, gây WA.

#### Khác biệt ký tự xuống dòng

???+ warning "Cảnh báo"
    Trong thi chính thức, ban tổ chức sẽ cố gắng bảo đảm môi trường làm bài và
    môi trường kiểm thử cuối cùng giống nhau.

    Phần này chỉ áp dụng cho các tình huống như cuộc thi mô phỏng. Chúng tôi
    cũng khuyến nghị người ra đề cố gắng để dữ liệu tuân thủ
    [định dạng dữ liệu](problemsetting.md#định-dạng-dữ-liệu).

Các hệ điều hành khác nhau dùng ký hiệu khác nhau để đánh dấu xuống dòng. Dưới
đây là một số ký tự xuống dòng thường gặp:

-   LF (biểu diễn bằng `\n`): `Unix` hoặc hệ tương thích `Unix`

-   CR+LF (biểu diễn bằng `\r\n`): `Windows`

-   CR (biểu diễn bằng `\r`): `Mac OS` phiên bản 9 trở về trước

C/C++ dùng chuỗi thoát `\n` để xuống dòng. Điều này có thể khiến ta tưởng
rằng ký tự xuống dòng trong dữ liệu vào cũng nhất định được biểu diễn bằng `\n`, rồi
chỉ đọc một ký tự làm xuống dòng, dẫn đến chưa đọc hết tệp dữ liệu vào.

Một số cách xử lý:

-   Gọi `getchar()` nhiều lần cho đến khi đọc được ký tự mong muốn.

-   Dùng `cin` để đọc, **cách này có thể làm tăng hằng số thời gian**.

-   Dùng `scanf("%s",str)` để đọc một xâu, rồi lấy `str[0]` làm ký tự đọc vào.

-   Dùng `scanf(" %c",&c)` để lọc bỏ mọi ký tự trắng.

### Lỗi dẫn đến kết quả không xác định

Hành vi không xác định (UB) có thể dẫn đến kết quả không xác định, có thể là WA, RE,...
Trình biên dịch thường giả định chương trình của bạn không có hành vi không xác định, vì
vậy có thể xuất hiện tình huống bật O2 và không bật O2 cho hành vi khác nhau.

-   Chia cho 0, hoặc tính nghịch đảo của 0.

    ???+ warning "Ví dụ"
        ```cpp
        cout << x / 0 << endl;
        ```

-   Truy cập mảng vượt biên.

    Ví dụ:

    -   Không đặt đúng giá trị đầu của vòng lặp, dẫn đến truy cập chỉ số -1.

    -   Danh sách cạnh của đồ thị vô hướng không cấp phát gấp đôi.

    -   Cây phân đoạn không cấp phát gấp 4 lần.

    -   Nhìn nhầm giới hạn dữ liệu, thiếu một số 0.

    -   Ước lượng sai độ phức tạp bộ nhớ của thuật toán.

    -   Khi viết cây phân đoạn, gọi `pushup` hoặc `pushdown` ở nút lá.

        Cách đúng: đừng vượt biên; nhớ kiểm tra mã để chỉ số truy cập `x` nằm
        trong miền chỉ số đã định nghĩa.

-   Hàm có giá trị trả về, ngoài `main`, chạy đến cuối mà không thực hiện câu
    lệnh `return`.

    Ngay cả khi một nhánh có giá trị trả về nhưng các nhánh khác không có, kết
    quả vẫn là hành vi không xác định.

    Có thể thêm `-Wall` vào tùy chọn biên dịch để kiểm tra trình biên dịch có cảnh báo
    về hàm thiếu `return` hay không.

-   Thử sửa chuỗi literal.

    ???+ warning "Ví dụ"
        ```cpp
        char *p = "OI-wiki";
        p[0] = 'o';
        p[1] = 'i';
        ```

    Thử sửa chuỗi literal như vậy dẫn đến **hành vi không xác định**. Nên dùng
    kiểu dữ liệu **phù hợp** khác, chẳng hạn `std::string` hoặc `char[]`.

-   Giải phóng nhiều lần hoặc dereference vùng nhớ không hợp lệ.

    Ví dụ:

    -   Dereference con trỏ khi chưa khởi tạo.

    -   Vùng nhớ mà con trỏ trỏ tới đã được giải phóng.

        Khi dùng `erase`, `delete` hoặc `free`, cần chú ý không dùng nhiều lần
        trên cùng một địa chỉ/đối tượng.

-   Thử giải phóng một phần của khối nhớ được cấp phát bằng `new []`.

    Ví dụ:

    ```cpp
    object *pool = new object[POOL_SIZE];

    object *pointer = pool + 10;

    // Lỗi!
    delete pointer;
    ```

    Thường gặp khi dùng memory pool để cấp phát trước một khối nhớ lớn, rồi thử
    dùng `delete` hoặc `free()` để giải phóng một đối tượng đơn lẻ lấy từ pool.

-   Dereference con trỏ null hoặc con trỏ rác.

    Với con trỏ null: trước hết nên kiểm tra con trỏ, có thể dùng
    `p == nullptr` hoặc `!p`.

    Với con trỏ rác: có thể đặt con trỏ về `nullptr` khi giải phóng để tránh.

-   Tràn số có dấu.

    Ví dụ, ta có biểu thức `x+1 > x`.

    Bình thường kết quả phải là `true`, nhưng khi `x` bằng `INT_MAX`, kết quả
    có thể là `false`; đây gọi là `signed integer overflow`.

    Có thể dùng kiểu dữ liệu lớn hơn, chẳng hạn `long long` hoặc `__int128`,
    hoặc kiểm tra tràn. Nếu bảo đảm không có số âm, cũng có thể dùng số nguyên
    không dấu.

    Tràn số nguyên có dấu có thể ảnh hưởng đến tối ưu biên dịch. Ví dụ:

    ```cpp
    int foo(int x) {
      if (x > x + 1) return 1;
      return 0;
    }
    ```

    Có thể bị trình biên dịch tối ưu trực tiếp thành:

    ```cpp
    int foo(int x) { return 0; }
    ```

    Vì trình biên dịch có thể giả định số nguyên có dấu không bao giờ tràn, nên
    `x > x + 1` không bao giờ đúng.

-   Dùng biến chưa khởi tạo.

    ???+ warning "Ví dụ"
        ```cpp
        int foo(int a) {
          int t; /* chưa khởi tạo */
          if (/* sử dụng */ t > 3) return a;
          return 0;
        }
        ```

### Lỗi dẫn đến RE

-   Không xóa thao tác tệp (trên một số OJ).

-   Hàm so sánh khi sắp xếp sai. `std::sort` yêu cầu hàm so sánh là thứ tự yếu
    nghiêm ngặt: `a<a` là `false`; nếu `a<b` là `true` thì `b<a` là `false`;
    nếu `a<b` là `true` và `b<c` là `true` thì `a<c` là `true`. Cần đặc biệt
    chú ý điều kiện thứ hai.

    Nếu không thỏa các yêu cầu trên, khi sắp xếp rất dễ RE.

    Ví dụ, khi viết thứ tự lẻ/chẵn cho Mo's algorithm, cách viết sau là sai:

    ```cpp
    bool operator<(const int a, const int b) {
      if (block[a.l] == block[b.l])
        return (block[a.l] & 1) ^ (a.r < b.r);
      else
        return block[a.l] < block[b.l];
    }
    ```

    Trong mã trên, `(block[a.l]&1)^(a.r<b.r)` không thỏa yêu cầu thứ hai. Sửa
    thành cách sau thì đúng:

    ```cpp
    bool operator<(const int a, const int b) {
      if (block[a.l] == block[b.l])
        // Sai: không thỏa yêu cầu thứ tự yếu nghiêm ngặt
        // return (block[a.l] & 1) ^ (a.r < b.r);
        // Đúng
        return (block[a.l] & 1) ? (a.r < b.r) : (a.r > b.r);
      else
        return block[a.l] < block[b.l];
    }
    ```

-   Trên Windows, stack không đủ gây tràn stack. Windows gửi tín hiệu SIGSEGV
    cho chương trình, chương trình kết thúc và trả về 3221225725, tức
    `0xC00000FD`, trong NTSTATUS là `STATUS_STACK_OVERFLOW`.

    Nếu dùng trình biên dịch GCC, có thể thêm tùy chọn `-Wl,--stack=SIZE` khi biên
    dịch để chỉ định giới hạn kích thước stack, trong đó `SIZE` là số byte.

    Trên Linux, stack không đủ gây tràn stack; Linux sẽ ghi bừa `head_info` vào
    vùng stack/heap. Thao tác này trong đa số trường hợp làm chương trình thoát
    ngay và hiển thị thông báo như `segmentation fault (core dumped)`.

    Có thể dùng `ulimit -s SIZE` trong trình dòng lệnh để sửa giới hạn stack của
    phiên trình dòng lệnh hiện tại, trong đó `SIZE` là số KB.

    **Lưu ý: nếu đặt giới hạn stack quá lớn, đệ quy vô hạn có thể làm stack đệ
    quy quá lớn và khiến hệ thống sập.**

### Lỗi dẫn đến TLE

-   Chia để trị không kiểm tra biên, dẫn đến đệ quy vô hạn.

-   Vòng lặp vô hạn.

    -   Tên biến vòng lặp trùng nhau.

    -   Hướng vòng lặp bị ngược.

-   Khi BFS, không đánh dấu trạng thái đã được thăm hay chưa.

-   Viết `min`/`max` bằng macro.

    Lỗi này có thể làm thời gian chạy tăng mạnh, thậm chí ảnh hưởng trực tiếp
    đến độ phức tạp thời gian của mã. Nó đặc biệt thường gặp khi người mới học
    viết cây phân đoạn.

    Cách viết sai thường gặp:

    ```cpp
    #define Min(x, y) ((x) < (y) ? (x) : (y))
    #define Max(x, y) ((x) > (y) ? (x) : (y))
    ```

    Cách viết này không sai về tính đúng đắn nếu tham số là biểu thức đơn giản.
    Nhưng nếu lấy max trực tiếp từ giá trị trả về của hàm, chẳng hạn
    `a = Max(func1(), func2())`, và hàm chạy lâu, hiệu năng sẽ bị ảnh hưởng lớn
    vì sau khi macro mở rộng ta có dạng
    `a = func1() > func2() ? func1() : func2()`, tức gọi hàm ba lần, nhiều hơn
    hàm `max` bình thường một lần. Lưu ý, nếu `func1()` trả về kết quả khác
    nhau ở mỗi lần gọi, cách viết `max` này còn cho kết quả sai. Ví dụ
    `func1()` là `return ++a;` và `a` là biến toàn cục.

    Ví dụ: mã sau có thể bị hack thành mỗi truy vấn $\Theta(n)$ và dẫn đến TLE.

    ```cpp
    #define max(x, y) ((x) > (y) ? (x) : (y))

    int query(int t, int l, int r, int ql, int qr) {
      if (ql <= l && qr >= r) {
        ++ti[t];  // ghi số lần truy cập nút để tiện gỡ lỗi
        return vi[t];
      }

      int mid = (l + r) >> 1;
      if (mid >= qr) return query(lt(t), l, mid, ql, qr);
      if (mid < ql) return query(rt(t), mid + 1, r, ql, qr);
      return max(query(lt(t), l, mid, ql, qr), query(rt(t), mid + 1, r, ql, qr));
    }
    ```

-   Dùng toán tử `+` để thêm ký tự vào `std::string`.

    Lỗi này tạo một biến `string` tạm thời, sửa xong rồi gán lại cho biến gốc.
    Trình biên dịch không thể tối ưu lỗi này; khi dữ liệu lớn, độ phức tạp có thể suy
    giảm.

    Cách viết sai thường gặp:

    ```cpp
    std::string a;
    char b = 'c';
    a = a + b;
    ```

    Khi chạy đoạn mã này, chương trình trước hết tạo một biến `string` tạm,
    sau đó sao chép giá trị của `a` vào biến tạm, thêm `b` vào cuối, rồi gán
    lại vào `a`.

    Từ [kết quả assembly](https://godbolt.org/z/Eo9vn7or5), có thể thấy
    `a = a + b` gọi ba chức năng trong `std::__cxx11::basic_string`: lần lượt
    là `operator+`, `operator=` và tạo biến.

    Cách viết đúng nên là:

    ```cpp
    std::string a;
    char b = 'c';
    a += b;
    ```

    [Cách viết này](https://godbolt.org/z/eGh33Grf3) thêm trực tiếp ký tự `b`
    vào xâu `a`, chỉ gọi một lần `operator+=`. Có thể xem so sánh hiệu năng chi
    tiết hơn tại [bài đo kiểm](https://quick-bench.com/q/JNDGl7HgOszNG-bo7AgVc42owv4).

-   Không xóa thao tác tệp (trên một số OJ).

-   Trong vòng lặp `for/while`, lặp lại việc gọi một hàm có độ phức tạp không
    phải $O(1)$. Nói chặt chẽ, điều này có thể làm thay đổi độ phức tạp thời
    gian.

-   Khi tìm kiếm nhị phân, công thức tính trung điểm hoặc điều kiện dừng sai.

### Lỗi dẫn đến MLE

-   Mảng quá lớn.

    ??? note "Giải thích chỉ số bộ nhớ trên Linux"
        > Bản ngắn gọn: nếu trong kỳ thi thuộc hệ CCF bạn khai báo một mảng
        > tĩnh toàn cục đặc biệt lớn, cần hết sức thận trọng. Vì mảng do
        > chương trình khai báo sẽ được tính toàn bộ vào mức sử dụng bộ nhớ
        > (khác với đa số nền tảng chấm trực tuyến, vốn chỉ tính phần thật sự
        > được dùng), trong một số trường hợp có thể khiến cả bài bị MLE.

        -   Về RSS và VSZ[^ref1][^ref2]

            1.  VSZ (Virtual Memory Size, kích thước bộ nhớ ảo)[^ref3]

                VSZ biểu thị **kích thước bộ nhớ ảo** của tiến trình, tức tổng
                kích thước không gian địa chỉ ảo mà tiến trình có thể truy cập,
                thường hiển thị theo KB.

                Bộ nhớ ảo là một khái niệm logic, thường lớn hơn bộ nhớ thật
                đang dùng rất nhiều.

                Trên Linux, bạn có thể dùng lệnh `top` để xem thành phần sử
                dụng bộ nhớ của một tiến trình; cột `VIRT` chính là bộ nhớ ảo
                mà tiến trình chiếm.

                Bộ nhớ ảo thường bao gồm không gian địa chỉ mà tiến trình đã
                cấp phát nhưng chưa thật sự dùng. Nói ngắn gọn, xin cấp phát
                bao nhiêu thì bộ nhớ ảo xấp xỉ tăng bấy nhiêu.

                Cần đặc biệt chú ý rằng các nền tảng chấm trực tuyến thường
                chỉ thống kê bộ nhớ vật lý. Nhưng **môi trường chấm của CCF
                thống kê bộ nhớ ảo**, nghĩa là nếu bạn khai báo một mảng tĩnh
                toàn cục lớn, dù chỉ dùng một phần nhỏ, nó vẫn chiếm rất nhiều
                bộ nhớ.
            2.  RSS (Resident Set Size, kích thước tập thường trú)[^ref4]

                RSS biểu thị **kích thước bộ nhớ vật lý** mà tiến trình thật sự
                chiếm, tức kích thước các page frame đang thường trú trong RAM,
                thường hiển thị theo KB.

                Tương tự, bạn có thể dùng `top` và xem cột `RES` để biết bộ
                nhớ vật lý của một tiến trình.

                RSS thường chỉ bao gồm phần thật sự được nạp vào bộ nhớ vật
                lý. Nói cách khác, dùng bao nhiêu thì tính bấy nhiêu.
        -   Phân tích hành vi sử dụng bộ nhớ

            Giả sử khai báo mảng sau:

            ```cpp
            const int SIZE = 1e8;
            int arr[SIZE];  // chiếm: 4 byte * 100 triệu = 400 MB
            ```

            Đây là một mảng tĩnh, được cấp phát trong vùng dữ liệu toàn cục.
            Nếu mảng chưa được khởi tạo tường minh, nó thường nằm trong BSS
            segment; nếu khởi tạo tường minh, chẳng hạn toàn 0 hoặc giá trị
            khác, thì nằm trong DATA segment.

            -   Khi hoàn toàn không dùng mảng (giả sử trình biên dịch không tối ưu bỏ
                mảng)

                -   Bộ nhớ vật lý: nếu mảng chưa được truy cập, cơ chế demand
                    paging sẽ khiến các trang bộ nhớ chưa được nạp vào bộ nhớ
                    vật lý. Bộ nhớ vật lý không tăng, hoặc chỉ tăng rất ít
                    (có thể nạp một số trang metadata).
                -   Bộ nhớ ảo: kích thước mảng được tính vào bộ nhớ ảo (tăng
                    `400MB`), vì toàn bộ không gian địa chỉ ảo của mảng đã được
                    cấp phát.
            -   Khi dùng một phần mảng

                Giả sử chỉ dùng một số ít phần tử, ví dụ:

                ```cpp
                arr[0] = 1;
                arr[999999] = 2;
                ```

                -   Bộ nhớ ảo: bộ nhớ ảo không đổi, vẫn là `400MB`.
                -   Bộ nhớ vật lý: mỗi lần truy cập một phần tử của mảng, trang
                    ảo tương ứng được nạp vào bộ nhớ vật lý. Giả sử kích thước
                    trang là `4KB`, mỗi trang chứa
                    $4 \text{KB} ÷ 4 \text{B} = 1024$ phần tử `int`. Hai lần
                    truy cập mảng có thể nạp 2 trang, tức tăng khoảng
                    $2 \times 4 \text{KB} = 8 \text{KB}$ bộ nhớ vật lý.
            -   Khi phần lớn mảng được dùng

                Giả sử gán giá trị cho $50,000,000$ phần tử đầu:

                ```cpp
                for (int i = 0; i < 50000000; ++i) {
                  arr[i] = i;
                }
                ```

                -   Bộ nhớ ảo (VSZ): VSZ vẫn là `400MB`, không đổi.
                -   Bộ nhớ vật lý (RSS): lúc này truy cập liên tục, tức
                    $50,000,000$ phần tử được truy cập nằm kề nhau trong bộ
                    nhớ. Số trang cần nạp là
                    $\left\lceil \dfrac{50,000,000}{1024} \right\rceil = 48,828$.

                    Giả sử mỗi trang có kích thước `4KB`, tổng cộng là
                    $48,828 \times 4 \text{KB} \approx 190 \text{MB}$, bộ nhớ
                    vật lý tăng lên khoảng `190MB`.

                    Ghi chú: nếu gán giá trị cho mảng theo chỉ số ngẫu nhiên,
                    mức sử dụng bộ nhớ vật lý có thể lệch khá nhiều so với dự
                    đoán, vì trang bộ nhớ được nạp theo địa chỉ; gán ngẫu
                    nhiên có thể làm nạp rất nhiều trang.

                Tóm tắt: khi tỉ lệ phần được truy cập tăng lên, bộ nhớ vật lý
                dần tiến gần bộ nhớ ảo, giả sử không có page reclaim.
-   Chèn quá nhiều phần tử vào container STL.

    -   Thường là vì vòng lặp chèn vào STL bị lặp vô hạn.

    -   Cũng có thể là bị hack.

### Lỗi làm hằng số quá lớn

-   Khi định nghĩa modulo, không định nghĩa là hằng số.

    -   Ví dụ:

        ```cpp
        // int mod = 998244353;      // Sai
        const int mod = 998244353;  // Đúng, giúp trình biên dịch xử lý như hằng số
        ```

-   Dùng đệ quy không cần thiết, trừ đệ quy đuôi (tail recursion).

-   Khi chuyển đệ quy thành lặp, đưa thêm quá nhiều phép tính phụ.

### Lỗi chỉ ảnh hưởng khi chạy chương trình cục bộ

-   Các lỗi có thể xảy ra với thao tác tệp:

    -   Khi đối chiếu chương trình, chưa đóng con trỏ tệp bằng `fclose(fp)` đã gán
        lại `fp = fopen()`. Điều này khiến tiến trình có nhiều con trỏ tệp rác.

    -   Tên tệp trong `freopen()` thiếu `.in`/`.out`.

-   Sau khi dùng bộ nhớ heap, quên `delete` hoặc `free`.

## Tài liệu tham khảo và ghi chú

[^ref1]: [What is RSS and VSZ in Linux memory management - Stack Overflow](https://stackoverflow.com/questions/7880784/what-is-rss-and-vsz-in-linux-memory-management)

[^ref2]: [Need explanation on Resident Set Size/Virtual Size - Stack Overflow](https://unix.stackexchange.com/questions/35129/need-explanation-on-resident-set-size-virtual-size)

[^ref3]: [Virtual memory](https://en.wikipedia.org/wiki/Virtual_memory)

[^ref4]: [Resident set size](https://en.wikipedia.org/wiki/Resident_set_size)
