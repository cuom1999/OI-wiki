<span id="giới-thiệu"></span>

## Giới thiệu

![](./images/stack.svg)

Ngăn xếp là một cấu trúc dữ liệu tuyến tính thường dùng trong OI. Lưu ý rằng
trang này chủ yếu nói về cấu trúc dữ liệu ngăn xếp, không phải ngăn xếp hệ
thống hay không gian ngăn xếp khi chương trình chạy.

Các thao tác sửa đổi và truy cập của ngăn xếp tuân theo nguyên tắc vào sau ra
trước. Vì vậy ngăn xếp thường được gọi là cấu trúc vào sau ra trước, viết tắt
là LIFO.

??? warning "Cảnh báo"
    LIFO mô tả việc **phần tử vào sau cùng trong container hiện tại** sẽ ra trước.

    Xét một ngăn xếp như sau:

    ```text
    push(1)
    pop(1)
    push(2)
    pop(2)
    ```

    Nếu nhìn toàn bộ quá trình, $1$ vào ngăn xếp đầu tiên và cũng ra đầu tiên,
    $2$ vào ngăn xếp cuối cùng và cũng ra cuối cùng; như vậy lại giống bảng vào
    trước ra trước, điều này là sai.

    Vì vậy, khi xét một cấu trúc dữ liệu là LIFO hay FIFO, cần xét trạng thái
    của các phần tử đang nằm trong container tại đúng thời điểm đó.

<span id="mô-phỏng-ngăn-xếp-bằng-mảng"></span>

## Mô phỏng ngăn xếp bằng mảng

Có thể dùng mảng để mô phỏng một ngăn xếp như sau:

???+ note "Cài đặt"
    === "C++"
        ```cpp
        int st[N];
        // Dùng st[0] (tức *st) để biểu thị số phần tử trong ngăn xếp,
        // đồng thời cũng là chỉ số của đỉnh ngăn xếp.

        // Đẩy vào ngăn xếp:
        st[++*st] = var1;
        // Lấy đỉnh ngăn xếp:
        int u = st[*st];
        // Pop khỏi ngăn xếp: lưu ý vượt biên, không thể pop khi *st == 0.
        if (*st) --*st;
        // Xóa rỗng ngăn xếp:
        *st = 0;
        ```

    === "Python"
        ```python
        st = [0] * N
        # Dùng st[0] để biểu thị số phần tử trong ngăn xếp,
        # đồng thời cũng là chỉ số của đỉnh ngăn xếp.

        # Đẩy vào ngăn xếp:
        st[st[0] + 1] = var1
        st[0] = st[0] + 1
        # Lấy đỉnh ngăn xếp:
        u = st[st[0]]
        # Pop khỏi ngăn xếp: lưu ý vượt biên, không thể pop khi st[0] == 0.
        if st[0]:
            st[0] = st[0] - 1
        # Xóa rỗng ngăn xếp:
        st[0] = 0
        ```

<span id="ngăn-xếp-trong-c-stl"></span>

## Ngăn xếp trong C++ STL

C++ STL cung cấp container `std::stack`; trước khi dùng cần nạp tệp tiêu đề
`<stack>`.

???+ info "Định nghĩa `stack` trong STL"
    ```cpp
    // clang-format off
    template<
        class T,
        class Container = std::deque<T>
    > class stack;
    ```

    `T` là kiểu dữ liệu cần lưu trong `stack`.

    `Container` là kiểu container nền dùng để lưu phần tử. Container này phải
    cung cấp các hàm sau với ngữ nghĩa thông thường:

    -   `back()`
    -   `push_back()`
    -   `pop_back()`

    Các container STL `std::vector`, `std::deque` và `std::list` đều thỏa mãn
    những yêu cầu này. Nếu không chỉ định, mặc định dùng `std::deque` làm
    container nền.

Container `stack` trong STL cung cấp nhiều hàm thành viên; các hàm thường dùng
gồm:

-   Truy cập phần tử
    -   `st.top()` trả về đỉnh ngăn xếp
-   Sửa đổi
    -   `st.push()` chèn tham số truyền vào lên đỉnh ngăn xếp
    -   `st.pop()` xóa phần tử ở đỉnh ngăn xếp
-   Dung lượng
    -   `st.empty()` trả về ngăn xếp có rỗng hay không
    -   `st.size()` trả về số phần tử

Ngoài ra, `std::stack` còn cung cấp một số toán tử. Toán tử thường dùng là toán
tử gán `=` để gán giá trị cho `stack`, ví dụ:

```cpp
// Tạo hai ngăn xếp st1 và st2.
std::stack<int> st1, st2;

// Đưa 1 vào st1.
st1.push(1);

// Gán st1 cho st2.
st2 = st1;

// In phần tử ở đỉnh của st2.
cout << st2.top() << endl;
// Kết quả: 1
```

<span id="mô-phỏng-ngăn-xếp-bằng-list-trong-python"></span>

## Mô phỏng ngăn xếp bằng `list` trong Python

Trong Python, có thể dùng danh sách để mô phỏng một ngăn xếp:

???+ note "Cài đặt"
    ```python
    st = [5, 1, 4]

    # Dùng append() để thêm phần tử vào đỉnh ngăn xếp.
    st.append(2)
    st.append(3)
    # >>> st
    # [5, 1, 4, 2, 3]

    # Dùng pop() để lấy phần tử ở đỉnh ngăn xếp.
    st.pop()
    # >>> st
    # [5, 1, 4, 2]

    # Dùng clear() để xóa rỗng ngăn xếp.
    st.clear()
    ```

<span id="tài-liệu-tham-khảo"></span>

## Tài liệu tham khảo

1.  [std::stack - cppreference.com](https://en.cppreference.com/w/cpp/container/stack)
