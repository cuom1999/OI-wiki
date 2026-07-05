author: johnvp22, Ir1d

## `string` là gì

`std::string` là một lớp được cung cấp trong thư viện chuẩn `<string>` (chú ý
không phải thư viện `<string.h>` của ngôn ngữ C); về bản chất nó là bí danh của
`std::basic_string<char>`.

## Vì sao nên dùng `string`

Trong ngôn ngữ C, có các thao tác xử lý chuỗi, nhưng chỉ có thể cài đặt chuỗi
bằng mảng ký tự. Còn `string` là một lớp đơn giản, dễ dùng và được sử dụng rộng
rãi trong các cuộc thi OI. So với các bộ chứa STL khác, chi phí hằng số của
`string` khá tốt, gần như không thua mảng ký tự.

### `string` có thể cấp phát bộ nhớ động

Giống nhiều bộ chứa STL khác, `string` có thể cấp phát bộ nhớ động, nhờ đó có
thể dùng trực tiếp `std::cin` để nhập, dù cách nhập này vẫn chậm. Điều này cũng
giúp giảm nhu cầu tự quản lý bộ nhớ.

### `string` nạp chồng toán tử cộng và toán tử so sánh

Toán tử cộng của `string` có thể nối trực tiếp hai chuỗi, hoặc một chuỗi với một
ký tự. Tương tự `std::vector`, `string` nạp chồng toán tử so sánh theo thứ tự từ
điển, nên có thể gọi trực tiếp `std::sort` để sắp xếp nhiều chuỗi.

## Cách dùng

Dưới đây giới thiệu các thao tác cơ bản của `string`; chi tiết có thể xem trong
[tài liệu C++](https://en.cppreference.com/w/cpp/string/basic_string).

### Khai báo

```cpp
std::string s;
```

### Chuyển sang mảng `char`

Trong ngôn ngữ C cũng có nhiều hàm xử lý chuỗi, nhưng tham số của chúng đều là
kiểu con trỏ `char`. Để tiện dùng, `string` có hai hàm thành viên trả về con trỏ
đến dữ liệu ký tự bên trong: `data()`/`c_str()`. Từ C++11 trở đi, hai hàm này
đều trả về vùng dữ liệu kết thúc bằng ký tự rỗng; nếu cần tương thích với chuẩn
cũ hơn, nên ưu tiên dùng `c_str()`. Ví dụ:

```cpp
printf("%s", s);          // lỗi biên dịch
printf("%s", s.data());   // biên dịch được từ C++11 trở đi
printf("%s", s.c_str());  // chắc chắn xuất đúng
```

### Lấy độ dài

Nhiều hàm có thể trả về độ dài của một `string`:

```cpp
printf("độ dài của s là %zu", s.size());
printf("độ dài của s là %zu", s.length());
printf("độ dài của s là %zu", strlen(s.c_str()));
```

???+ note "Độ phức tạp của các hàm này"
    Độ phức tạp của `strlen()` chắc chắn tuyến tính theo độ dài chuỗi.
    
    Độ phức tạp của `size()` và `length()` không được chỉ định trong C++98, và
    được chỉ định là hằng số trong C++11. Nhưng trên các trình biên dịch phổ
    biến, ngay cả với C++98, độ phức tạp của hai hàm này cũng là hằng số.

???+ warning "Cảnh báo"
    Kiểu trả về của ba hàm này (và hàm `find` sẽ nhắc tới ở phần sau) đều là
    `size_t` (một kiểu số nguyên không dấu). Vì vậy, các giá trị trả về này
    không nên so sánh hoặc tính toán trực tiếp với số âm; nên ép kiểu khi cần.

### Tìm vị trí xuất hiện đầu tiên của ký tự/chuỗi

Hàm `find(str, pos)` có thể dùng để tìm vị trí xuất hiện đầu tiên của một ký tự
hoặc chuỗi trong chuỗi, bắt đầu từ vị trí `pos` (bao gồm `pos`; nếu không truyền
tham số `pos` thì mặc định là `0`). Nếu không xuất hiện thì trả về
`string::npos` (được định nghĩa là `-1`, nhưng kiểu vẫn là
`size_t`/`unsigned long`).

Ví dụ:

```cpp
string s = "OI Wiki", t = "OI", u = "i";
int pos = 5;
printf("ký tự I xuất hiện lần đầu ở vị trí %zu trong s\n", s.find('I'));
printf("ký tự a xuất hiện lần đầu ở vị trí %zu trong s\n", s.find('a'));
printf("ký tự a xuất hiện lần đầu ở vị trí %d trong s\n", (int)s.find('a'));
printf("chuỗi t xuất hiện lần đầu ở vị trí %zu trong s\n", s.find(t));
printf("trong s, chuỗi u xuất hiện lần đầu từ vị trí pos ở vị trí %zu",
       s.find(u, pos));
```

Kết quả:

```text
ký tự I xuất hiện lần đầu ở vị trí 1 trong s
ký tự a xuất hiện lần đầu ở vị trí 18446744073709551615 trong s // tức size_t(-1), giá trị cụ thể phụ thuộc nền tảng.
ký tự a xuất hiện lần đầu ở vị trí -1 trong s // ép sang kiểu int thì nhận được -1
chuỗi t xuất hiện lần đầu ở vị trí 0 trong s
trong s, chuỗi u xuất hiện lần đầu từ vị trí pos ở vị trí 6
```

### Cắt chuỗi con

Hàm `substr(pos, len)` trả về chuỗi gồm tối đa `len` ký tự được cắt từ vị trí
`pos` (nếu hậu tố bắt đầu từ `pos` có độ dài nhỏ hơn `len` thì cắt toàn bộ hậu
tố đó).

Ví dụ:

```cpp
string s = "OI Wiki", t = "OI";
printf("chuỗi con gồm tối đa ba ký tự bắt đầu từ vị trí thứ tư của s là %s\n",
       s.substr(3, 3).c_str());
printf("chuỗi con gồm tối đa ba ký tự bắt đầu từ vị trí thứ hai của t là %s",
       t.substr(1, 3).c_str());
```

Kết quả:

```text
chuỗi con gồm tối đa ba ký tự bắt đầu từ vị trí thứ tư của s là Wik
chuỗi con gồm tối đa ba ký tự bắt đầu từ vị trí thứ hai của t là I
```

### Chèn/xóa ký tự hoặc chuỗi

`insert(index, count, ch)` và `insert(index, str)` là hai hàm chèn thường gặp.
Chúng lần lượt biểu thị chèn liên tiếp `count` lần ký tự `ch` tại `index`, và
chèn chuỗi `str` tại `index`.

Hàm `erase(index, count)` xóa `count` ký tự bắt đầu từ vị trí `index` của chuỗi
(bao gồm `index`; nếu không truyền tham số `count` thì xóa toàn bộ ký tự từ
`index` trở đi).

Ví dụ:

```cpp
string s = "OI Wiki", t = " Wiki";
char u = '!';
s.erase(2);
printf("sau khi xóa mọi ký tự từ vị trí thứ ba của s, chuỗi thu được là %s\n",
       s.c_str());
s.insert(2, t);
printf("sau khi chèn chuỗi t vào vị trí thứ ba của s, chuỗi thu được là %s\n",
       s.c_str());
s.insert(7, 3, u);
printf("sau khi chèn liên tiếp 3 lần ký tự u vào vị trí thứ tám của s, "
       "chuỗi thu được là %s",
       s.c_str());
```

Kết quả:

```text
sau khi xóa mọi ký tự từ vị trí thứ ba của s, chuỗi thu được là OI
sau khi chèn chuỗi t vào vị trí thứ ba của s, chuỗi thu được là OI Wiki
sau khi chèn liên tiếp 3 lần ký tự u vào vị trí thứ tám của s, chuỗi thu được là OI Wiki!!!
```

### Thay thế ký tự hoặc chuỗi

`replace(pos, count, str)` và `replace(first, last, str)` là hai hàm thay thế
thường gặp. Chúng lần lượt biểu thị thay chuỗi con gồm `count` ký tự bắt đầu từ
`pos` bằng `str`, và thay chuỗi con bắt đầu từ `first` (bao gồm) đến `last`
(không bao gồm) bằng `str`, trong đó `first` và `last` đều là bộ lặp.

Ví dụ:

```cpp
string s = "OI Wiki";
s.replace(2, 5, "");
printf("sau khi thay các vị trí từ 3 đến 7 của s bằng chuỗi rỗng, "
       "chuỗi thu được là %s\n",
       s.c_str());
s.replace(s.begin(), s.begin() + 2, "NOI");
printf("sau khi thay hai vị trí đầu của s bằng NOI, chuỗi thu được là %s",
       s.c_str());
```

Kết quả:

```text
sau khi thay các vị trí từ 3 đến 7 của s bằng chuỗi rỗng, chuỗi thu được là OI
sau khi thay hai vị trí đầu của s bằng NOI, chuỗi thu được là NOI
```
