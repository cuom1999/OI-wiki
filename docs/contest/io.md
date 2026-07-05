author: Marcythm, YZircon, Chaigidel, Tiger3018, voidge, H-J-Granger, ouuan, Enter-tainer, lcfsih, Xeonacid, Ir1d

Bài viết này giới thiệu cách tối ưu I/O dựa trên stream và I/O kiểu C.

???+ note "Chú ý"
    Tốc độ thực tế của I/O dựa trên stream và I/O kiểu C sẽ thay đổi theo môi trường (như trình biên dịch, hệ điều hành và cấu hình phần cứng). Nếu muốn phân tích sâu hơn, hãy lấy kết quả thực nghiệm làm chuẩn. Tuy nhiên, cần chú ý kiểm soát biến trong thí nghiệm, tránh để nhiều biến cùng ảnh hưởng dẫn tới kết luận sai.

## I/O dựa trên stream

Với I/O dựa trên stream (như `std::cin` và `std::cout`), cách tối ưu thường dùng nhất là tắt đồng bộ với stream của C và bỏ liên kết giữa stream nhập và stream xuất.

### Tắt đồng bộ

Dùng hàm [`std::ios::sync_with_stdio(false)`](https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio) để tắt đồng bộ với stream của C. Để tương thích với C, tức để đảm bảo chương trình không bị lẫn lộn khi dùng đồng thời `printf` và `std::cout`, C++ đã đồng bộ hai loại stream này. Các stream C++ được đồng bộ đảm bảo an toàn luồng.

Thực chất đây là một biện pháp thận trọng mà C++ dùng để tương thích. Nếu bật đồng bộ, trong mỗi thao tác I/O, stream C++ sẽ lập tức áp dụng thao tác đó lên bộ đệm C tương ứng; nếu trong mã không liên quan đến I/O kiểu C thì thao tác này là dư thừa. Vì vậy có thể tắt đồng bộ với stream của C trước khi thực hiện I/O, nhưng sau khi làm vậy cần chú ý rằng phần mã phía sau không được dùng đồng thời `std::cin` và `scanf`, cũng không được dùng đồng thời `std::cout` và `printf`; tuy nhiên vẫn có thể dùng đồng thời `std::cin` và `printf`, cũng như `scanf` và `std::cout`.

### Bỏ liên kết

Dùng hàm [`tie()`](https://en.cppreference.com/w/cpp/io/basic_ios/tie) để bỏ liên kết giữa stream nhập và stream xuất.

Mặc định, `std::cin` được liên kết với `&std::cout`, nên mỗi lần thực hiện nhập có định dạng đều sẽ gọi `std::cout.flush()` để xả bộ đệm đầu ra; việc này làm tăng chi phí I/O. Có thể dùng `std::cin.tie(nullptr)` để bỏ liên kết, từ đó tăng thêm hiệu suất thực thi.

???+ warning "Chú ý"
    Khi sử dụng không được bỏ qua tham số và viết thành `std::cin.tie()`: cách này không bỏ liên kết, mà trả về stream xuất đang liên kết với `std::cin`. Ngoài ra cũng không cần gọi `std::cout.tie(nullptr)`, vì mặc định không có stream xuất nào khác liên kết với `std::cout`.

### Mã cài đặt

```cpp
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
```

???+ note "Chú ý"
    Sau khi thực hiện đồng thời hai thao tác trên, chương trình phải tự `flush` thủ công để đảm bảo nội dung mỗi lần `std::cout` hiển thị có thể xuất hiện trước `std::cin`. Nguyên nhân là trong trường hợp này, khi gọi `std::cin`, `std::cout` sẽ không tự động xả bộ đệm. Ví dụ:

    ```cpp
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << "Vui lòng nhập tên của bạn: "
              << std::flush;  // Hoặc: std::endl;
                              // vì mỗi lần gọi std::endl đều xả bộ đệm đầu ra,
                              // còn \n thì không.
    // Nếu bỏ std::flush, thông báo sẽ không hiển thị trước khi nhập tên
    std::cin >> name;
    ```

## I/O kiểu C

`scanf` và `printf` vẫn còn không gian để cải thiện hiệu suất; các phương pháp cải thiện đều dựa trên chuyển đổi giữa số nguyên và xâu.

???+ note "Chú ý"
    Các tối ưu đọc và ghi được giới thiệu trên trang này đều nhắm vào dữ liệu số nguyên. Tối ưu đọc và ghi số thực rất phức tạp; về tối ưu đọc có thể tham khảo [thuật toán Bellerophon](https://dl.acm.org/doi/10.1145/93542.93557), còn về tối ưu ghi có thể tham khảo [thuật toán Ryū](https://dl.acm.org/doi/10.1145/3192366.3192369).

### Thiết kế cài đặt

???+ note "Chú ý"
    Các phương pháp tối ưu hiện tại tập trung vào I/O nhanh hơn, còn quá trình chuyển đổi dữ liệu đều dùng phương pháp đơn giản và chưa tận dụng đầy đủ đặc tính phần cứng. Ngày nay phần lớn CPU kiến trúc x86 đều hỗ trợ tập lệnh AVX2, có thể dùng SIMD để tăng tốc chuyển đổi giữa số nguyên và xâu. Các hàm thư viện chuẩn chưa tận dụng tối ưu SIMD; ví dụ [cài đặt](https://github.com/gcc-mirror/gcc/blob/releases/gcc-14.3.0/libstdc%2B%2B-v3/include/bits/charconv.h#L81) của libstdc++ chuyển đổi liên tiếp hai chữ số mỗi lần và dùng bảng tra để chuyển thành ký tự. Vì vậy tối ưu quá trình chuyển đổi dữ liệu cũng có thể đem lại lợi ích. Nhưng trong phạm vi thi đấu, các phương pháp tối ưu được nêu trong bài này đã đủ để xử lý tuyệt đại đa số tình huống.

#### Tối ưu đọc

Mỗi số nguyên gồm hai phần: dấu và chữ số, và phần dấu luôn đứng trước phần chữ số, nên trước hết sẽ đọc phần dấu. Với phần dấu, dấu `+` của số nguyên dương thường được lược bỏ và không ảnh hưởng đến giá trị mà phần chữ số phía sau biểu diễn, còn dấu `-` thì không thể lược bỏ, vì vậy cần kiểm tra. Nếu dữ liệu vào không chứa số nguyên âm, có thể bỏ qua phần kiểm tra này. Phần chữ số chỉ chứa các chữ số từ 0 đến 9, nên khi đọc được ký tự không thể thuộc về số nguyên (thường là khoảng trắng), có thể xác định rằng số nguyên này đã được đọc xong.

Khi đọc, vì các chữ số được đọc từ trái sang phải, ta có thể tận dụng thuật toán Horner để chuyển đổi số nguyên. Do đó toàn bộ quá trình chuyển đổi có thể kết hợp trực tiếp với quá trình nhập.

Trong quá trình đọc phần chữ số, cần xác định ký tự đọc được có phải ký tự chữ số thập phân hay không. Có thể dùng điều kiện đơn giản `ch >= '0' && ch <= '9'`, hoặc dùng hàm [`isdigit()`](https://en.cppreference.com/w/cpp/string/byte/isdigit).

#### Tối ưu ghi

Khi xuất, cần chuyển số nguyên thành xâu. Thông thường dùng thuật toán đơn giản: trực tiếp tính từng chữ số của số nguyên từ thấp lên cao, chuyển thành ký tự rồi xuất theo thứ tự ngược lại.

### Chi tiết cài đặt

#### Vấn đề tràn số nguyên

Khi cài đặt cần chú ý vấn đề tràn số nguyên. Ví dụ trong tối ưu ghi, việc lấy số đối không đúng cách có thể khiến giá trị nhỏ nhất của kiểu số nguyên sau khi đổi dấu vượt quá giá trị lớn nhất mà kiểu đó biểu diễn được, dẫn đến xuất sai. Khi đọc giá trị nhỏ nhất của kiểu số nguyên cũng có thể xảy ra tràn tương tự, nhưng trong trường hợp này chưa chắc làm dữ liệu đọc vào sai, vì giá trị thu được sau tràn có thể bằng với giá trị đầu vào thực tế.

Tràn số nguyên có dấu là hành vi không xác định. Khi cài đặt có thể dựa vào tính chất phép chia số nguyên âm trong C làm tròn về phía không để tránh vấn đề trên. Tuy nhiên, nếu không cần nhập xuất số âm, hoặc không thể nhập xuất giá trị nhỏ nhất của kiểu số nguyên này, thì vấn đề đó sẽ không xuất hiện.

#### Nâng cao tính tổng quát của cài đặt

Nếu chương trình dùng nhiều kiểu biến số nguyên, có thể cần cài đặt nhiều hàm nhập xuất có kiểu khác nhau nhưng logic giống nhau. Lúc này có thể dùng [`template`](https://en.cppreference.com/w/cpp/language/templates.html) trong C++ để cài đặt tối ưu nhập xuất cho mọi kiểu số nguyên. Ví dụ, dưới chuẩn C++11 dùng

```cpp
template <typename T>
typename std::enable_if<std::is_integral<T>::value &&
                        std::is_signed<T>::value>::type
read(T &x);
```

hoặc dưới chuẩn C++20 dùng

```cpp
template <std::signed_integral T>
void read(T &x);
```

để định nghĩa hàm.

Để tiện đọc, các cài đặt bên dưới giả định chỉ cần đọc số nguyên kiểu `int`; các cài đặt này đã đủ đáp ứng nhu cầu của phần lớn bài toán.

### Cài đặt

Các cài đặt chủ đạo chỉ khác nhau ở hàm đọc/ghi được sử dụng; logic chuyển đổi số nguyên đều giống nhau. Dưới đây giới thiệu theo các hàm đọc/ghi mà từng cài đặt sử dụng.

#### Cài đặt bằng `getchar` và `putchar`

Mã cốt lõi như sau.

```cpp
--8<-- "docs/contest/code/io/io_1.cpp:core"
```

#### Cài đặt bằng `fread` và `fwrite`

Có thể dùng `fread` và `fwrite` để nhập xuất nhanh hơn. Chữ ký hàm như sau.

```cpp
std::size_t fread(void* buffer, std::size_t size, std::size_t count,
                  std::FILE* stream);
std::size_t fwrite(const void* buffer, std::size_t size, std::size_t count,
                   std::FILE* stream);
```

Ví dụ `fread(Buf, 1, SIZE, stdin)` nghĩa là đọc `SIZE` khối dữ liệu kích thước 1 byte từ đầu vào chuẩn vào `Buf`. Giá trị trả về cho biết đã đọc thành công bao nhiêu byte dữ liệu.

Vì `fread` và `fwrite` đọc và ghi theo từng đoạn, chúng có lợi thế về tốc độ so với `getchar()` và `putchar()`. Nếu bộ đệm đủ lớn, có thể đọc toàn bộ tệp trong một lần. Nhưng nếu bộ đệm không đủ lớn, cần đọc nhiều lần để đảm bảo đọc hết toàn bộ nội dung đầu vào. Để thực hiện chức năng này, chỉ cần định nghĩa lại `getchar`.

```cpp
char buf[1 << 20], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
```

Xuất cũng tương tự đọc: trước hết đưa nội dung cần xuất vào một bộ đệm, cuối cùng dùng `fwrite` một lần để ghi toàn bộ nội dung bộ đệm ra.

Mã cốt lõi như sau.

```cpp
--8<-- "docs/contest/code/io/io_2.cpp:core"
```

Khi dùng phương pháp này cần chú ý:

-   Khi tắt cờ gỡ lỗi thì dùng `fread()`, `fwrite()`, và khi thoát sẽ tự động gọi hàm hủy để thực thi `fwrite()`. Khi bật cờ gỡ lỗi thì dùng `getchar()`, `putchar()` để tiện gỡ lỗi.
-   Nếu cần đọc ghi tệp, phải thêm `freopen()` trước mọi thao tác đọc ghi.

#### Cài đặt bằng `mmap`

`mmap` là lời gọi hệ thống (system call) của Linux, có thể ánh xạ toàn bộ tệp vào bộ nhớ trong một lần, tương tự một vùng bộ nhớ có thể tham chiếu bằng con trỏ, và trong một số tình huống có tốc độ tốt hơn. Chữ ký hàm như sau:

```c
void *mmap(void addr[.length], size_t length, int prot, int flags, int fd,
           off_t offset);
```

???+ warning "Chú ý"
    `mmap` không thể dùng trong môi trường Windows (ví dụ hệ thống chấm của CodeForces và HDU), đồng thời cũng không khuyến nghị dùng trong phòng thi chính thức. Trên thực tế, dùng `fread` đã đủ nhanh; nếu dùng `mmap` để lặp đi lặp lại việc đọc một tệp nhỏ, chi phí thực hiện ánh xạ bộ nhớ một lần và chi phí nhân hệ điều hành xử lý lỗi trang (page fault) sẽ lớn hơn nhiều so với chi phí dùng `fread`.

Trước hết cần lấy bộ mô tả tệp (file descriptor) `fd`, sau đó dùng `fstat` để lấy kích thước tệp, rồi dùng `mmap` để thu được con trỏ `*pc` trỏ tới tệp đã ánh xạ vào bộ nhớ. Sau đó có thể trực tiếp dùng `*pc++` thay cho `getchar()` để đọc tệp.

Nếu cần đọc từ đầu vào chuẩn, có thể đặt `fd` là `0`. **Tuy nhiên, dùng mmap trên đầu vào chuẩn là hành vi cực kỳ nguy hiểm, đồng thời không thể nhập từ thiết bị đầu cuối; có thể chọn cách chuyển hướng tệp vào đầu vào chuẩn.**

???+ note "Ví dụ: [Luogu P10815 Mẫu: đọc nhanh](https://www.luogu.com.cn/problem/P10815)"
    Đọc $n$ số nguyên trong phạm vi $[-n, n]$, tính tổng và xuất ra. Trong đó $n \leq 10^8$. Dữ liệu đảm bảo với mọi tiền tố của dãy, tổng của tiền tố đó nằm trong phạm vi lưu trữ của số nguyên có dấu $32$ bit.

Mã tham khảo như sau.

```cpp
--8<-- "docs/contest/code/io/io_3.cpp"
```

## Tham khảo

[Dùng cin.tie và sync\_with\_stdio để tăng tốc nhập xuất - Mã Nông Trường](https://www.hankcs.com/program/cpp/cin-tie-with-sync_with_stdio-acceleration-input-and-output.html)

[Tăng tốc C++ - Heavy Watal](https://heavywatal.github.io/cxx/speed.html)

['Re: mmap/mlock performance versus read' - MARC](https://marc.info/?l=linux-kernel&m=95496636207616&w=2)
