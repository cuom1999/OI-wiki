C++ định nghĩa một hệ thống đầy đủ để khai báo các giá trị chỉ đọc. Mọi biến được bổ nghĩa bằng `const` đều là giá trị chỉ đọc; trình biên dịch sẽ kiểm tra xung đột trong giai đoạn biên dịch để tránh việc sửa đổi các giá trị chỉ đọc, đồng thời có thể thực hiện một số tối ưu hóa.

Trong điều kiện thông thường, nên dùng `const` cho biến và tham số nhiều nhất có thể để tăng độ vững chắc của mã.

## Bộ định tính kiểu `const`

### Hằng

Biến được bổ nghĩa bằng `const` không thể thay đổi giá trị sau khi khởi tạo.

```cpp
const int a = 0;  // kiểu của a là const int

// a = 1; // không thể sửa đổi hằng
```

### Tham chiếu hằng, con trỏ tới hằng

Tham chiếu hằng và con trỏ tới hằng đều giới hạn việc sửa đổi giá trị mà chúng trỏ tới hoặc tham chiếu tới.

```cpp
int a = 0;
const int b = 0;

int *p1 = &a;
*p1 = 1;
const int *p2 = &a;
// *p2 = 2; // không thể sửa đổi biến thông qua con trỏ tới hằng
// int *p3 = &b; // không thể dùng int* để trỏ tới biến const int
const int *p4 = &b;

int &r1 = a;
r1 = 1;
const int &r2 = a;
// r2 = 2; // không thể sửa đổi biến thông qua tham chiếu hằng
// int &p3 = b; // không thể dùng int& để tham chiếu tới biến const int
const int &r4 = b;
```

Ngoài ra cần phân biệt con trỏ tới hằng (`const t*`) với hằng con trỏ (`t* const`), chẳng hạn các khai báo sau:

```cpp
int* const p1;  // hằng con trỏ: sau khi khởi tạo không đổi được địa chỉ trỏ tới, nhưng đổi được giá trị được trỏ tới
const int* p2;  // con trỏ tới hằng: không đổi được giá trị sau khi giải tham chiếu, nhưng có thể trỏ tới biến int khác
const int* const p3;  // hằng con trỏ tới hằng: không đổi được giá trị, cũng không đổi được địa chỉ trỏ tới

// Dùng bí danh giúp cải thiện tính dễ đọc
using const_int = const int;
using ptr_to_const_int = const_int*;
using const_ptr_to_const_int = const ptr_to_const_int;
```

Dùng `const` để giới hạn kiểu tham số trong tham số hàm có thể tránh việc biến bị sửa đổi nhầm, đồng thời tăng tính dễ đọc của mã.

```cpp
void sum(const std::vector<int> &data, int &total) {
  for (auto iter = data.begin(); iter != data.end(); ++iter)
    total += *iter;  // iter là iterator, kiểu sau khi giải tham chiếu là const int
}
```

## Hàm thành viên `const`

Trong một kiểu, hàm thành viên được giới hạn bằng `const` có thể dùng để hạn chế việc sửa đổi các thành viên.

```cpp
#include <iostream>

struct ConstMember {
  int s = 0;

  void func() { std::cout << "General Function" << std::endl; }

  void constFunc1() const { std::cout << "Const Function 1" << std::endl; }

  void constFunc2(int ss) const {
    // func(); // hàm thành viên const không thể gọi hàm thành viên không const
    constFunc1();

    // s = ss; // hàm thành viên const không thể sửa đổi biến thành viên
  }
};

int main() {
  int b = 1;
  ConstMember c{};
  const ConstMember d = c;
  // d.func(); // hằng không thể gọi hàm thành viên không const
  d.constFunc2(b);
  return 0;
}
```

## Biểu thức hằng `constexpr` (C++11)

Biểu thức hằng là biểu thức có thể tính ra kết quả trong lúc biên dịch; còn `constexpr` yêu cầu trình biên dịch có thể tính giá trị của hàm hoặc biến trong lúc biên dịch.

Việc tính toán trong lúc biên dịch cho phép tối ưu hóa tốt hơn, chẳng hạn ghi cứng kết quả vào assembly để loại bỏ chi phí tính toán khi chạy. Khác với tối ưu hóa mà `const` có thể mang lại, khi biến được bổ nghĩa bằng `constexpr` thỏa điều kiện của biểu thức hằng, trình biên dịch bắt buộc phải tính kết quả trong lúc biên dịch thay vì lúc chạy.

???+ note "Cách hiểu trực quan hơn là xem `const` như \"chỉ đọc\", còn `constexpr` như \"bất biến\""
    ```cpp
    constexpr int a = 10;  // định nghĩa hằng trực tiếp
    
    constexpr int FivePlus(int x) { return 5 + x; }
    
    void test(const int x) {
      std::array<int, x> c1;            // lỗi, x không biết được trong lúc biên dịch
      std::array<int, FivePlus(6)> c2;  // hợp lệ, FivePlus biết được trong lúc biên dịch
    }
    ```

Ví dụ sau minh họa rõ sự khác nhau giữa `const` và `constexpr`. Mã dùng đệ quy để tính dãy Fibonacci rồi xuất kết quả bằng luồng điều khiển.

???+ note "Cài đặt"
    ```cpp
    #include <iostream>
    
    using namespace std;
    
    constexpr unsigned fib0(unsigned n) {
      return n <= 1 ? 1 : (fib0(n - 1) + fib0(n - 2));
    }
    
    unsigned fib1(unsigned n) { return n <= 1 ? 1 : (fib1(n - 1) + fib1(n - 2)); }
    
    int main() {
      constexpr auto v0 = fib0(9);
      const auto v1 = fib1(9);
    
      cout << v0;
      cout << ' ';
      cout << v1;
    }
    ```

???+ note "Một đoạn assembly có thể sinh ra sau khi biên dịch (dùng Compiler Explorer, Clang 19)"
    ```nasm
    fib1(unsigned int):
            push    r14
            push    rbx
            push    rax
            mov     ebx, 1
            cmp     edi, 2
            jb      .LBB0_4
            mov     r14d, edi
            xor     ebx, ebx
    .LBB0_2:
            lea     edi, [r14 - 1]
            call    fib1(unsigned int)
            add     r14d, -2
            add     ebx, eax
            cmp     r14d, 1
            ja      .LBB0_2
            inc     ebx
    .LBB0_4:
            mov     eax, ebx
            add     rsp, 8
            pop     rbx
            pop     r14
            ret
    
    main:
            push    r14
            push    rbx
            push    rax
            mov     edi, 9
            call    fib1(unsigned int) # quá trình khởi tạo `v1` đã gọi hàm
            mov     ebx, eax
            mov     r14, qword ptr [rip + std::__1::cout@GOTPCREL]
            mov     rdi, r14
            mov     esi, 55 # `v0` đã được thay bằng kết quả tính cuối cùng
            call    std::__1::basic_ostream<char, std::__1::char_traits<char>>::operator<<(unsigned int)@PLT
            mov     byte ptr [rsp + 7], 32
            lea     rsi, [rsp + 7]
            mov     edx, 1
            mov     rdi, r14
            call    std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ne200000]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)
            mov     rdi, r14
            mov     esi, ebx # đã đọc giá trị của biến
            call    std::__1::basic_ostream<char, std::__1::char_traits<char>>::operator<<(unsigned int)@PLT
            xor     eax, eax
            add     rsp, 8
            pop     rbx
            pop     r14
            ret
    ```

Hàm `fib0` được bổ nghĩa bằng `constexpr` được gọi duy nhất một lần với tham số hằng, khiến toàn bộ hàm chỉ chạy trong lúc biên dịch. Vì hàm không thực thi lúc chạy, trình biên dịch cũng xác định rằng không cần sinh mã assembly cho nó.

Đồng thời, có thể thấy trong assembly rằng `v0` không có mã khởi tạo. Trong đoạn mã gọi `cout` để xuất `v0`, `v0` đã được thay bằng kết quả tính cuối cùng, cho thấy giá trị biến đã được tính trong lúc biên dịch và phép tính lúc chạy đã bị tối ưu bỏ.
Còn quá trình khởi tạo `v1` vẫn là một lời gọi đệ quy `fib1` thông thường.

Vì vậy, có thể dùng `constexpr` để thay thế các hằng được định nghĩa bằng macro, tránh [rủi ro của định nghĩa macro](./basic.md#lệnh-define).

Trong bài toán thuật toán, có thể dùng `constexpr` để lưu các biến có quy mô dữ liệu nhỏ nhằm loại bỏ chi phí tính toán tương ứng lúc chạy. Trường hợp đặc biệt thường gặp là trong kỹ thuật "[lập bảng](../contest/dictionary.md)", dùng các vùng chứa như mảng được bổ nghĩa bằng `constexpr` để lưu đáp án.

???+ note "Lượng tính toán trong lúc biên dịch quá lớn sẽ gây lỗi biên dịch"
    Trình biên dịch sẽ giới hạn chi phí tính toán trong lúc biên dịch. Nếu lượng tính toán quá lớn khiến chương trình không thể biên dịch, nên cân nhắc dùng `const`.
    
    ```cpp
    #include <iostream>
    
    using namespace std;
    
    constexpr unsigned long long fib(unsigned long long i) {
      return i <= 2 ? i : fib(i - 2) + fib(i - 1);
    }
    
    int main() {
      // constexpr auto v = fib(32); evaluation exceeded maximum depth
      const auto v = fib(32);
      cout << v;
      return 0;
    }
    ```

???+ note "Lỗi biên dịch Clang đưa ra khi dùng constexpr"
    ```text
    <source>:10:20: error: constexpr variable 'v' must be initialized by a constant expression
        10 |     constexpr auto v = fib(32);
        |                    ^   ~~~~~~~~~~~~
    <source>:6:25: note: constexpr evaluation exceeded maximum depth of 512 calls
        6 |     return i <= 2 ? i : fib(i - 2) + fib(i - 1);
        |                         ^
    <source>:6:25: note: in call to 'fib(32)'
        6 |     return i <= 2 ? i : fib(i - 2) + fib(i - 1);
        |                         ^~~~~~~~~~
    <source>:6:25: note: in call to ...
    ```

## Tài liệu tham khảo

-   [Từ khóa C++: const](https://en.cppreference.com/w/cpp/keyword/const)
-   [Từ khóa C++: constexpr](https://en.cppreference.com/w/cpp/keyword/constexpr)
