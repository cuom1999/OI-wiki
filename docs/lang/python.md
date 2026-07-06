author: cmpute, Henry-ZHR, ranwen, abc1763613206, billchenchina, chinggg, ChungZH, CoelacanthusHex, countercurrent-time, Dong Tsing-hsuen, Early0v0, Enter-tainer, F1shAndCat, Great-designer, hensier, HeRaNO, Hszzzx, imba-tjd, Ir1d, ksyx, lingxier, LovelyBuggies, Marcythm, mgt, Mooos-MoSheng, NachtgeistW, ouuan, Rottenwooood, shawlleyw, shuzhouliu, sshwy, SukkaW, Suyun514, Tiphereth-A, tLLWtG, wineee, wxh06, Xeonacid, yusancky, zyouxam, zzjjbb, jiangmuran, CuriosityQiu

<a id="về-python"></a>

## Về Python

Python là một ngôn ngữ thông dịch được sử dụng rộng rãi. Ngôn ngữ này cung cấp
các cấu trúc dữ liệu bậc cao hiệu quả, hỗ trợ lập trình hướng đối tượng gọn gàng
mà mạnh mẽ, đồng thời cũng có thể dùng trong lập trình thi đấu.

<a id="ưu-điểm-của-python"></a>

### Ưu điểm của Python

-   Python là một ngôn ngữ **thông dịch**: không cần biên dịch và liên kết trước,
    nên giảm được nhiều thao tác khi chạy chương trình.
-   Python là một ngôn ngữ **tương tác**: trình thông dịch Python hỗ trợ thao tác
    tương tác, có thể nhập và chạy lệnh ngay trong dòng lệnh.
-   Python **dễ học, dễ dùng**: Python cung cấp nhiều cấu trúc dữ liệu tiện lợi
    và vẫn phù hợp để phát triển chương trình lớn.
-   Python **tương thích tốt**: Python hỗ trợ Windows, macOS và các hệ điều hành Unix.
-   Python **thực dụng**: từ nhập xuất cơ bản, tính toán khoa học cho đến các ứng
    dụng web lớn đều có thể viết bằng Python.
-   Chương trình Python **ngắn gọn và dễ đọc**: mã Python thường ngắn hơn mã của
    các ngôn ngữ khác khi thực hiện cùng một chức năng.
-   Python **hỗ trợ mở rộng**: Python được phát triển bằng C (tức CPython), hỗ trợ
    liên kết trình thông dịch Python với ứng dụng viết bằng C, nhờ đó có thể dùng
    Python để mở rộng và điều khiển ứng dụng đó.

<a id="lưu-ý-khi-học-python"></a>

### Lưu ý khi học Python

-   Phiên bản Python được dùng chủ yếu hiện nay là Python 3.7 trở lên. Python 2
    và Python 3.6 trở về trước đã [không còn được hỗ trợ](https://devguide.python.org/versions/#unsupported-versions),
    nhưng vẫn có thể xuất hiện trong một số hệ thống và mã cũ. Bài này sẽ
    **giới thiệu các phiên bản Python mới hơn**. Nếu gặp mã Python 2, có thể thử
    dùng chương trình [`2to3`](https://docs.python.org/3/library/2to3.html) để
    chuyển mã Python 2 sang Python 3.
-   Tư tưởng thiết kế và cấu trúc cú pháp của Python **khác đáng kể so với một
    số ngôn ngữ khác**. Python che giấu nhiều chi tiết tầng thấp, vì vậy mang
    phong cách thực dụng và gọn gàng.
-   Python là ngôn ngữ thông dịch có tính động cao, nên **tốc độ chạy chương
    trình chậm**, đặc biệt khi dùng vòng lặp `for` thuần Python. Khi dùng Python,
    nên tận dụng các hàm dựng sẵn như `filter`, `map`, hoặc dùng
    [biểu thức sinh danh sách](https://www.pythonforbeginners.com/basics/list-comprehensions-in-python)
    để cải thiện hiệu năng.

<a id="thiết-lập-môi-trường"></a>

## Thiết lập môi trường

Xem [Python 3](../tools/compiler.md#python-3). Hoặc:

-   Windows: cũng có thể cài Python miễn phí qua Microsoft Store.

-   macOS/Linux: thông thường, phần lớn bản phân phối Linux đã cài sẵn Python.
    Nếu chỉ muốn học cú pháp Python và không có nhu cầu phát triển khác, không
    nhất thiết phải cài thêm Python.

    ???+ warning "Lưu ý"
        Trên một số hệ thống cài Python mặc định (tức cài bằng trình quản lý
        gói), chẳng hạn các hệ Unix, nên chạy `python3` trong trình dòng lệnh để
        mở trình thông dịch Python 3.[^ref1]

Ngoài ra, cũng có thể dùng các công cụ như venv, conda, Nix để quản lý bộ công cụ
Python và các gói Python, tạo môi trường ảo độc lập và tránh lỗi phụ thuộc.

Là một ngôn ngữ thông dịch, cách thực thi Python khác với C++. Sự khác biệt này
thường không lộ rõ khi lập trình bằng IDE, nên cần nhấn mạnh các cách chạy
chương trình.

Khi gõ `python3` trên dòng lệnh hoặc vừa mở IDLE, môi trường lập trình tương tác
sẽ được mở ra; môi trường này còn gọi là "REPL" (vòng lặp "đọc - đánh giá - in
kết quả"). Người mới học có thể nhập lệnh tại đây và thấy kết quả ngay, rất phù
hợp để kiểm tra nhanh cú pháp. Phần sau cũng sẽ thường dùng hình thức này.

Nhưng nếu muốn viết một chương trình hoàn chỉnh, tốt hơn hết là tạo một tệp văn
bản mới (thường có đuôi `.py`), sau đó chạy `python3 filename.py` trên dòng lệnh
để xem kết quả.

<a id="một-số-phiên-bản-python-trên-các-nền-tảng"></a>

### Một số phiên bản Python trên các nền tảng

| Tên hệ thống/phiên bản      | Phiên bản Python              |
| --------------------------- | ----------------------------- |
| NOI Linux 2.0               | 3.8.0, có requests            |
| Máy chấm Luogu              | 3.11.5, NumPy 1.25.2          |
| OJ dựa trên Hydro           | 3.8.0+, có NumPy              |
| Ubuntu 22.04 (cài sẵn)      | 3.10.4                        |
| Microsoft Store             | Bản ổn định mới nhất          |

???+ warning "Lưu ý"
    Bảng này đúng tại thời điểm bài viết được soạn (2025/01/15); nên kiểm tra lại
    trên các nền tảng liên quan.

Nên tải Python từ [trang tải chính thức](https://www.python.org/downloads/) hoặc
trình quản lý gói của hệ điều hành. Nếu tốc độ tải không ổn định, có thể chọn
một máy chủ phản chiếu đáng tin cậy gần khu vực sử dụng.

<a id="cài-thư-viện-bên-thứ-ba-bằng-pip"></a>

## Cài thư viện bên thứ ba bằng `pip`

Sức sống của Python phần lớn đến từ hệ sinh thái thư viện bên thứ ba phong phú.
Khi viết các tiện ích thực dụng, việc "gọi thư viện" là thao tác thường gặp,
và `pip` là chương trình cài thư viện bên thứ ba được ưu tiên. Từ Python 3.4,
`pip` được kèm sẵn trong bộ cài nhị phân Python.

Thư viện bên thứ ba trong `pip` chủ yếu được lưu trên [Python Package Index
(PyPI)](https://pypi.org/), nhưng cũng có thể chỉ định các nền tảng lưu trữ thư
viện khác. Nếu cần dùng máy chủ phản chiếu, nên chọn nguồn đáng tin cậy và khớp
với chính sách mạng đang dùng; có thể xem thêm danh sách máy chủ phản chiếu PyPI
trên [MirrorZ](https://mirrorz.org/list/pypi).

???+ info "Cài một gói bằng chỉ mục PyPI tùy chọn"
    ```sh
    pip install -i <index-url> <some-package>
    ```

<a id="cú-pháp-cơ-bản"></a>

## Cú pháp cơ bản

Cú pháp Python ngắn gọn và dễ hiểu, đồng thời có nhiều tài liệu và giáo trình cả
chính thức lẫn bên thứ ba. Phần này chỉ giới thiệu một số đặc điểm ngôn ngữ hữu
ích với người học OI. Có thể đọc thêm các bài học Python trên
[tài liệu Python](https://docs.python.org/3/) và
[Python Wiki](https://wiki.python.org/moin/).

<a id="chú-thích"></a>

### Chú thích

Thêm chú thích không ảnh hưởng đến việc chạy mã, nhưng giúp mã dễ đọc và dễ bảo
trì hơn.

```python
# Dòng bắt đầu bằng ký tự # là chú thích một dòng

"""
Chuỗi nhiều dòng được bao bằng ba dấu nháy
(ba dấu nháy đơn hoặc ba dấu nháy kép),
nhưng nó cũng thường được dùng làm chú thích
"""
```

Chú thích không làm thay đổi hành vi của chương trình. Nên thêm chú thích vừa đủ
để người đọc hiểu được ý định của đoạn mã.

<a id="kiểu-dữ-liệu-cơ-bản"></a>

### Kiểu dữ liệu cơ bản

<a id="mọi-thứ-đều-là-đối-tượng"></a>

#### Mọi thứ đều là đối tượng

Trong Python, không cần khai báo trước tên biến và kiểu của nó; thao tác gán sẽ
tạo biến thuộc kiểu tương ứng với giá trị được gán:

```pycon
>>> x = -3  # Cuối câu lệnh không cần dấu chấm phẩy
>>> x
-3
>>> f = 3.1415926535897932384626; f  # Nếu thật sự muốn thêm chấm phẩy thì vẫn được; dòng này tiết kiệm một dòng
3.141592653589793
>>> s1 = "O"
>>> s1  # Trong Python, dấu nháy kép và dấu nháy đơn có tác dụng như nhau
'O'
>>> b = 'A' == 65  # 'A' và 65 không cùng kiểu dữ liệu, nên không bằng nhau
>>> b  # True và False đều viết hoa chữ cái đầu
False
>>> True + 1 == 2 and not False != 0  # Biểu thức Python chủ yếu dùng từ, nhưng cũng hỗ trợ ký hiệu
True
```

Điều này không có nghĩa Python không có khái niệm kiểu. Thực tế, trình thông dịch
sẽ tự động xác định kiểu biến theo phép gán hoặc phép tính. Có thể dùng hàm dựng
sẵn `type()` để xem kiểu của các biến này:

```pycon
>>> type(x)
<class 'int'>
>>> type(f)
<class 'float'>
>>> type(s1)  # Lưu ý: đừng đặt tên chuỗi là str, nếu không đối tượng str sẽ bị ghi đè
<class 'str'>
>>> type(b)
<class 'bool'>
```

???+ note "[**Hàm dựng sẵn**](https://docs.python.org/3/library/functions.html) là gì?"
    Trong C/C++, nhiều hàm thường dùng nằm rải rác trong các tệp tiêu đề khác
    nhau. Còn trình thông dịch Python tích hợp sẵn nhiều hàm thực dụng và tổng
    quát; có thể dùng ngay mà không cần quan tâm chúng nằm ở đâu. Điều này cũng
    tạo ra một vấn đề nhỏ: tên các hàm dựng sẵn thường là từ thông dụng, vì vậy
    cần tránh đặt biến trùng tên, nếu không có thể sinh ra kết quả khó hiểu.

Python có sẵn các kiểu số nguyên, số thực dấu phẩy động, chuỗi và luận lý, có thể
đối chiếu với `int`, `float`, `string` và `bool` trong C++. Nhưng có một số khác
biệt đáng lưu ý: Python không có kiểu ký tự `char`, cũng không có kiểu `double`
(nhưng `float` tương ứng với số chính xác kép trong C). Nếu cần phép tính dấu
phẩy động chính xác hơn, có thể dùng mô-đun
[decimal](https://docs.python.org/3/library/decimal.html) trong thư viện chuẩn.
Nếu cần số phức, Python có sẵn kiểu `complex` (tốt nhất là không đặt biến tên
`complex`).

Các kiểu này đều bắt đầu bằng `class`, và đây là điểm cốt lõi khiến Python khác
C++: mọi dữ liệu trong chương trình Python được biểu diễn bằng đối tượng hoặc
quan hệ giữa các đối tượng. Hàm là đối tượng, bản thân kiểu cũng là đối tượng:

```pycon
>>> type(int)
<class 'type'>
>>> type(pow)  # Hàm dựng sẵn tính lũy thừa, phần sau sẽ giới thiệu
<class 'builtin_function_or_method'>
>>> type(type)  # type() cũng là hàm dựng sẵn, nhưng tương đối đặc biệt; ai quan tâm có thể tự tra cứu
<class 'type'>
```

Các khái niệm này ban đầu có thể khó hiểu và chưa hữu ích, nên phần này chưa đi
sâu. Qua các ví dụ sau, có thể dần cảm nhận được rằng đối tượng Python cung cấp
nhiều phương thức mạnh. Khi lập trình, nên ưu tiên suy nghĩ thao tác quanh đối
tượng thay vì quanh từng bước thủ tục; mã sẽ gọn và rõ hơn.

<a id="phép-toán-số-học"></a>

#### Phép toán số học

Có thể xem Python cài trên máy như một chiếc máy tính đa năng; cách hiểu này khá
đúng. Trong chế độ tương tác, có thể nhập một biểu thức sau dấu nhắc `>>>`, dùng
các toán tử `+`, `-`, `*`, `/`, `%` để tính toán trên số như phần lớn ngôn ngữ
khác (ví dụ C++), và dùng `()` để nhóm theo thứ tự kết hợp. Có thể tự thử các
phép toán này; phần này chỉ trình bày những điểm khác C++ rõ hơn:

```pycon
>>> 5.0 * 6  # Kết quả phép tính với số thực là số thực
30.0
>>> 15 / 3  # Khác C/C++, phép chia luôn trả về kiểu float
5.0
>>> 5 / 100000  # Quá nhiều chữ số, kết quả hiện theo dạng ký pháp khoa học
5e-05
>>> 5 // 3  # Chia nguyên (floor division) sẽ làm tròn xuống và xuất kiểu số nguyên
1
>>> -5 // 3  # Vẫn theo nguyên tắc làm tròn xuống; lưu ý khác C/C++
-2
>>> 5 % 3  # Lấy phần dư
2
>>> -5 % 3  # Phần dư của số âm luôn không âm; điểm này cũng khác C/C++, nhưng đều thỏa (a//b)*b+(a%b)==a
1
>>> x = abs(-1e4)  # Hàm dựng sẵn tính giá trị tuyệt đối
>>> x += 1  # Không có toán tử tăng/giảm một đơn vị
>>> x  # Ký pháp khoa học mặc định là float
10001.0
```

Từ các thử nghiệm trên, phép chia (`/`) luôn trả về kiểu dấu phẩy động (trong
Python 2 thì có thể trả về số nguyên). Nếu muốn kết quả số nguyên hoặc làm tròn
xuống, dùng chia nguyên (`//`). Tương tự C++, có thể dùng modulo (`%`) để tính
phần dư, và dạng ký pháp khoa học cũng giống nhau.

Đặc biệt, Python dùng `**` để tính lũy thừa, và cung cấp cài đặt hiệu quả của
[lũy thừa nhanh](../math/binary-exponentiation.md) qua hàm dựng sẵn
`pow(a, b, mod)`.

```pycon
>>> 3 ** 4  # Lũy thừa
81
>>> 2 ** 512
13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096
>>> pow(2, 512, int(1e4))  # Cài đặt nhanh của 2**512 % 10000; 1e4 là float nên cần ép sang int
4096
>>> 2048 ** 2048  # Thử số nguyên lớn trong IDLE?
>>> 0.1 + 0.1 + 0.1 - 0.3 == 0.  # Như C/C++, cần cẩn thận: không nên so sánh trực tiếp số thực bằng nhau
False
```

<a id="kiểm-tra-kiểu-dữ-liệu"></a>

#### Kiểm tra kiểu dữ liệu

Với một biến, có thể dùng `type(object)` để trả về kiểu của biến. Ví dụ, giá trị
của `type(8)` và `type('a')` lần lượt là `<class 'int'>` và `<class 'str'>`.

<a id="nhập-xuất-cơ-bản"></a>

#### [Nhập xuất cơ bản](https://docs.python.org/3/tutorial/inputoutput.html)

Nhập xuất trong Python chủ yếu thực hiện qua hai hàm dựng sẵn `input()` và
`print()`. Cách dùng `print()` dễ theo dõi:

```pycon
>>> a = [1,2,3]; print(a[-1])  # Mặc định xuống dòng ở cuối khi in
3
>>> print(ans[0], ans[1])  # Có thể xuất bao nhiêu biến tùy ý, mặc định cách nhau bằng dấu cách
1 2
>>> print(a[0], a[1], end='')  # Đặt end='' để cuối dòng không xuống dòng
1 2>>>
>>> print(a[0], a[1], sep=', ')  # Đặt sep=', ' để đổi kiểu phân cách
1, 2
>>> print(str(a[0]) + ', ' + str(a[1]))  # Kết quả như trên, nhưng ghép bằng tay thành một chuỗi
```

Hành vi của hàm `input()` gần với `getline()` trong C++: đọc cả một dòng thành
chuỗi và không gồm ký tự xuống dòng ở cuối.

```pycon
>>> s = input('Nhập dãy số: '); s  # Khi tự gỡ lỗi, có thể truyền chuỗi vào input() làm lời nhắc
Nhập dãy số: 1 2 3 4 5 6
'1 2 3 4 5 6'
```

<a id="chuỗi"></a>

#### Chuỗi

Python 3 cung cấp kiểu chuỗi dựa trên
[Unicode](https://docs.python.org/3/howto/unicode.html#unicode-howto) với nhiều
tính năng, cách dùng gần với `string` trong C++. Nhiều khái niệm như ký tự thoát
cũng tương tự. Ngoài phép cộng để nối chuỗi và truy cập bằng chỉ số, Python còn
hỗ trợ nhân với số `*` để lặp chuỗi và toán tử `in`.

```pycon
>>> s1 = "O"  # Dấu nháy đơn và dấu nháy kép đều bao được chuỗi; đôi khi giúp tiết kiệm ký tự thoát
>>> s1 += 'I-Wiki'  # Để đồng bộ với C++, nên dùng dấu nháy kép
>>> 'OI' in s1  # Kiểm tra chuỗi con
True
>>> len(s1)  # Gần như s.length() trong C++, nhưng tổng quát hơn
7
>>> s2 = """ cam on ban
... chao mung dong gop!"""   # Chuỗi dùng ba dấu nháy có thể trải qua nhiều dòng
>>> s1 + s2
'OI-Wiki cam on ban\nchao mung dong gop!'
>>> print(s1 + s2)  # Dùng hàm print() để in chuỗi
OI-Wiki cam on ban
chao mung dong gop!
>>> s2[1:4] + s2[-1]  # Chỉ số âm đếm từ bên phải; cộng lên len(s) tương đương đưa về modulo n
'cam!'
>>> s1[0] = 'o'  # str là kiểu bất biến, không thể sửa tại chỗ; += cũng tạo đối tượng mới
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'str' object does not support item assignment
```

Ngoài truy cập bằng chỉ số, chuỗi còn hỗ trợ *phép cắt lát* linh hoạt. Dạng
chung là `s[chi_so_trai_dong:chi_so_phai_mo:buoc]`:

```pycon
>>> s = 'OI-Wiki cam on ban\nchao mung dong gop!'
>>> s[:8]  # Bỏ qua chỉ số trái đóng thì bắt đầu từ đầu
'OI-Wiki '
>>> s[8:18]  # Thiết kế trái đóng phải mở: độ dài là 18-8=10, và ghép liền mạch với đoạn trước
'cam on ban'
>>> s[-9:]  # Bỏ qua chỉ số phải mở thì lấy đến hết
'dong gop!'
>>> s[8:18:2]  # Bước nhảy bằng 2
'cmo a'
>>> s[::-1]  # Khi bước nhảy là -1, thu được chuỗi đảo ngược
'!pog gnod gnum oahc\nnab no mac ikiW-IO'
>>> s  # Nhưng chuỗi gốc không đổi
'OI-Wiki cam on ban\nchao mung dong gop!'
```

Trong các phiên bản Python 3 mới, chuỗi được mã hóa bằng Unicode, nghĩa là chuỗi
Python hỗ trợ đa ngôn ngữ.[^ref2] Trong Python, có thể dùng hàm dựng sẵn `ord()`
để chuyển một ký tự Unicode sang mã Unicode tương ứng; chiều ngược lại dùng
`chr()`. Trong C/C++, kiểu `char` cũng có thể chuyển qua lại với mã ASCII tương
ứng.

Nếu muốn chuyển số thành chuỗi tương ứng, có thể dùng hàm dựng sẵn `str()`; chiều
ngược lại có thể dùng `int()` và `float()`. Có thể xem như ép kiểu trong C/C++,
nhưng ngoặc không đặt sau kiểu mà là một phần của lời gọi hàm.

Kiểu chuỗi của Python cung cấp nhiều phương thức mạnh, bao gồm tìm chỉ số và số
lần xuất hiện của một ký tự, đổi hoa thường, v.v. Phần này không liệt kê từng
cái; nên đọc
[tài liệu chính thức](https://docs.python.org/3/library/stdtypes.html#text-sequence-type-str)
để làm quen các phương thức thường dùng. Khi gặp thao tác chuỗi, nên nghĩ đến
các phương thức sẵn có trước khi tự viết lại.

<a id="tạo-mảng"></a>

### Tạo mảng

Người chuyển từ C++ sang có thể bối rối về cách tạo mảng trong Python. Phần này
giới thiệu cú pháp "mô phỏng mảng" trong Python. Cần nhấn mạnh rằng phần này đang
nói về một số [kiểu tuần tự](https://docs.python.org/3/library/stdtypes.html#iterator-types),
khác bản chất với mảng C và gần với `vector` trong C++ hơn.

<a id="dùng-list"></a>

#### Dùng `list`

Danh sách (`list`) có lẽ là kiểu tuần tự thường dùng và mạnh nhất trong Python.
Danh sách có thể chứa phần tử thuộc bất kỳ kiểu nào, kể cả danh sách lồng nhau,
phù hợp với định nghĩa "danh sách tổng quát" trong cấu trúc dữ liệu. Lưu ý đừng
nhầm với danh sách liên kết đôi [`list`](./csl/sequence-container.md#list) trong
C++ STL; vì vậy bài này sẽ gọi là "danh sách" thay vì `list` khi cần tránh hiểu
nhầm.

```pycon
>>> []  # Tạo danh sách rỗng; lưu ý danh sách dùng ngoặc vuông
[]
>>> nums = [0, 1, 2, 3, 5, 8, 13]; nums  # Khởi tạo danh sách; có thể in trực tiếp cả danh sách
[0, 1, 2, 3, 5, 8, 13]
>>> nums[0] = 1; nums  # Hỗ trợ truy cập chỉ số và sửa phần tử
[1, 1, 2, 3, 5, 8, 13]
>>> nums.append(nums[-2]+nums[-1]); nums  # append() giống push_back() của vector, đều không có giá trị trả về
[1, 1, 2, 3, 5, 8, 13, 21]
>>> nums.pop()  # Lấy ra và trả về phần tử cuối, có thể dùng như stack; cũng có thể chỉ định vị trí, mặc định là cuối
21
>>> nums.insert(0, 1); nums  # Giống insert(position, val) của vector
[1, 1, 1, 2, 3, 5, 8, 13]
>>> nums.remove(1); nums  # Xóa theo giá trị (chỉ xóa lần xuất hiện đầu tiên), nếu không tồn tại sẽ báo lỗi
[1, 1, 2, 3, 5, 8, 13]
>>> len(nums)  # Lấy độ dài danh sách, gần với size() của vector, nhưng len() là hàm dựng sẵn
7
>>> nums.reverse(); nums  # Đảo ngược tại chỗ
[13, 8, 5, 3, 2, 1, 1]
>>> sorted(nums)  # Lấy danh sách đã sắp xếp
[1, 1, 2, 3, 5, 8, 13]
>>> nums  # Nhưng danh sách gốc chưa được sắp xếp
[13, 8, 5, 3, 2, 1, 1]
>>> nums.sort(); nums  # Sắp xếp tại chỗ, có thể chỉ định tham số key làm tiêu chí sắp xếp
[1, 1, 2, 3, 5, 8, 13]
>>> nums.count(1)  # Gần với std::count()
2
>>> nums.index(1)  # Trả về chỉ số của lần xuất hiện đầu tiên; nếu không tồn tại sẽ báo lỗi
0
>>> nums.clear(); nums  # Giống clear() của vector
```

Ví dụ trên cho thấy danh sách có nhiều điểm giống `vector`: các thao tác thường
dùng trong `vector` thường cũng có phương thức tương ứng trong danh sách. Tuy
nhiên, một số thao tác như `len()`, `sorted()` xuất hiện dưới dạng hàm dựng sẵn;
còn các hàm trong nhóm thuật toán STL như `find()`, `count()`, `max_element()`,
`sort()`, `reverse()` lại trở thành phương thức của đối tượng trong Python. Khi
dùng cần phân biệt. Xem thêm
[mô tả chi tiết về `list`](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)
trong tài liệu chính thức. Sau đây là một số tính năng mạnh của danh sách với
vai trò kiểu tuần tự cơ bản của Python:

```pycon
>>> lst = [1, '1'] + ["2", 3.0]  # Cộng hai danh sách để tạo danh sách mới
>>> lst  # Chứa nhiều kiểu khác nhau chỉ để minh họa rằng có thể làm vậy; đây không phải thực hành tốt
[1, '1', '2', 3.0]
>>> 3 in lst  # Kiểm tra thành viên hữu ích; chuỗi cũng có thao tác này và còn hỗ trợ kiểm tra chuỗi con
True
>>> [1, '1'] in lst  # Chỉ hỗ trợ kiểm tra một phần tử, không phát hiện "dãy con"
False
>>> lst[1:3] = [2, 3]; lst  # Cắt lát và gán, danh sách gốc bị sửa
[1, 2, 3, 3.0]
>>> lst[::-1]  # Lấy danh sách mới đã đảo ngược
[3.0, 3, 2, 1]
>>> lst *= 2; lst  # Nhân để nối lặp
[1, 2, 3, 3.0, 1, 2, 3, 3.0]
>>> del lst[4:]; lst  # Cũng có thể viết lst[4:] = []; câu lệnh del không chỉ dùng để xóa phần tử trong kiểu tuần tự
[1, 2, 3, 3.0]
```

Ví dụ trên cho thấy một số thao tác thường dùng của danh sách như một kiểu tuần
tự. Nhiều thao tác, như cắt lát, dùng chung ý tưởng với chuỗi. Nhưng chuỗi là
"kiểu tuần tự bất biến", còn danh sách là "kiểu tuần tự khả biến", nên có thể
linh hoạt sửa danh sách bằng phép cắt lát. Trong C/C++, thường xử lý mảng ký tự
bằng vòng lặp; sau đây minh họa cách dùng
[biểu thức sinh danh sách](https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions)
để chuyển đổi giữa chuỗi và danh sách:

```pycon
>>> # Tạo mảng số nguyên trên đoạn [65, 70); range cũng là một kiểu, có thể xem như khoảng trái đóng phải mở, tham số thứ ba là bước và có thể bỏ qua
>>> nums = list(range(65,70))  # Nhớ bọc range bằng list()
[65, 66, 67, 68, 69]
>>> lst = [chr(x) for x in nums]  # Cấu trúc điển hình của biểu thức sinh danh sách: [exp for var in iterable if cond]
>>> lst  # Hai câu trên có thể gộp thành [chr(x) for x in range(65,70)]
['A', 'B', 'C', 'D', 'E']
>>> s = ''.join(lst); s  # Dùng chuỗi rỗng '' để nối các phần tử danh sách thành chuỗi mới
'ABCDE'
>>> list(s)  # Tạo danh sách ký tự từ chuỗi
['A', 'B', 'C', 'D', 'E']
>>> # Nếu không biết phương thức s.lower(), có thể viết một biểu thức "rượu cũ bình mới" như sau
>>> ''.join([chr(ord(ch) - 65 + 97) for ch in s if ch >= 'A' and ch <= 'Z'])
'abcde'
```

Sau đây là vài tình huống thường gặp hơn trong OI, chẳng hạn "mảng" hai chiều:

```pycon
>>> vis = [[0] * 3] * 3  # Tạo mảng 3*3 toàn 0
>>> vis
[[0, 0, 0], [0, 0, 0], [0, 0, 0]]
>>> vis[0][0] = 1; vis  # Sao các dòng khác cũng bị sửa?
[[1, 0, 0], [1, 0, 0], [1, 0, 0]]
>>> # Trước hết xem phép gán danh sách một chiều
>>> a1 = [0, 0, 0]; a2 = a1; a3 = a1[:]  # Danh sách có thể gán trực tiếp cho biến mới
>>> a1[0] = 1; a1  # Sửa danh sách a1, trông có vẻ bình thường
[1, 0, 0]
>>> a2  # Sao a2 cũng đổi?
[1, 0, 0]
>>> a3  # a3 không đổi
[0, 0, 0]
>>> id(a1) == id(a2) and id(a1) != id(a3)  # id() cho biết định danh đối tượng
True
>>> vis2 = vis[:]  # Sao chép một danh sách hai chiều
>>> vis[0][1] = 2; vis  # vis bị sửa hàng loạt
>>> [[1, 2, 0], [1, 2, 0], [1, 2, 0]]
>>> vis2  # Nhưng vis2 được sao chép bằng cắt lát vẫn bị sửa
>>> [[1, 2, 0], [1, 2, 0], [1, 2, 0]]
>>> id(vis) != id(vis2)  # vis và vis2 không phải cùng một đối tượng
True
>>> # Tuy vis2 không phải tham chiếu của vis, các dòng tương ứng bên trong vẫn trỏ đến cùng đối tượng
>>> [id(vis[i]) == id(vis2[i]) for i in range(3)]
[True, True, True]
>>> # Nhìn lại bản thân danh sách hai chiều
>>> [id(x) for x in vis]  # Con số cụ thể sẽ khác, nhưng ba giá trị giống nhau, cho thấy đó là ba lần lặp của cùng đối tượng
[139760373248192, 139760373248192, 139760373248192]
```

Có một sự thật quan trọng: phép gán trong Python chỉ truyền tham chiếu, không tạo
giá trị mới. Có thể tạo biến thuộc nhiều kiểu khác nhau rồi gán cho biến mới, sau
đó kiểm tra thấy định danh của hai biến giống nhau. Đến đây mới giới thiệu danh
sách, một kiểu khả biến; khi gán giá trị mới cho các kiểu bất biến như số và
chuỗi, thực tế Python tạo đối tượng mới, nên hai biến trước sau không ảnh hưởng
nhau. Nhưng danh sách là kiểu khả biến, nên khi sửa phần tử của một danh sách,
danh sách kia cũng bị sửa vì cùng trỏ đến một đối tượng.

Tạo mảng hai chiều cũng tương tự: trong ví dụ, dùng phép nhân để tạo danh sách
hai chiều tương đương với việc lặp lại danh sách một chiều `[0]*3` ba lần, nên
thao tác trên một dòng sẽ đồng thời ảnh hưởng hai dòng còn lại. Tệ hơn nữa, khi
gán danh sách hai chiều cho biến khác, ngay cả dùng phép cắt lát để sao chép cũng
chỉ là "sao chép nông"; các phần tử bên trong vẫn trỏ đến cùng đối tượng. Để giải
quyết, cần dùng [`deepcopy`](https://docs.python.org/3/library/copy.html) trong
thư viện chuẩn, hoặc cố gắng tránh gán cả danh sách hai chiều. May là có thể tạo
danh sách hai chiều không lặp lại cùng một danh sách bằng biểu thức sinh danh
sách.

```pycon
>>> vis1 = [[0] * 3 for _ in range(3)]  # _ thường dùng cho biến đếm bỏ qua
>>> # Trong REPL, _ mặc định chỉ kết quả trước đó; cũng có thể dùng __
>>> vis1
[[0, 0, 0], [0, 0, 0], [0, 0, 0]]
>>> [id(x) for x in vis1]  # Ba giá trị khác nhau, tức là ba đối tượng khác nhau
[139685508981248, 139685508981568, 139685508981184]
>>> vis1[0][0] = 1
[[1, 0, 0], [0, 0, 0], [0, 0, 0]]
>>> a2[0][0] = 10  # Truy cập và gán mảng hai chiều
```

Biểu thức sinh danh sách được giới thiệu trước vòng lặp vì Python là ngôn ngữ
thông dịch có tính động cao, nên việc chạy chương trình có nhiều chi phí phụ. Đặc
biệt, **vòng lặp `for` thuần Python thường chậm**. Vì vậy, khi dùng Python mà
muốn đạt hiệu năng cao, nên cân nhắc biểu thức sinh danh sách hoặc các hàm dựng
sẵn như `filter`, `map` để thao tác trên cả kiểu tuần tự, qua đó giảm số vòng lặp
viết tay. Dù vậy, vẫn phải tùy bài toán cụ thể.

<a id="dùng-numpy"></a>

#### Dùng NumPy

??? note "NumPy là gì"
    [NumPy](https://numpy.org/) là thư viện tính toán khoa học nổi tiếng của
    Python, cung cấp phép tính số học và ma trận hiệu năng cao. Khi thử nghiệm
    mẫu thuật toán, có thể dùng NumPy để tránh tự viết các thuật toán sắp xếp,
    tìm min/max, v.v. Cấu trúc dữ liệu cốt lõi của NumPy là `ndarray`, tức mảng
    n chiều; nó được lưu liên tục trong bộ nhớ và có độ dài cố định. Ngoài ra,
    phần lõi của NumPy được viết bằng C nên hiệu suất cao. Cần lưu ý NumPy không
    phải một phần của thư viện chuẩn; có thể cài bằng `pip install numpy`, nhưng
    không bảo đảm môi trường thi OI có sẵn (xem
    [phiên bản Python](#mot-so-phien-ban-python-tren-cac-nen-tang) ở đầu bài).

Đoạn mã sau giới thiệu cách dùng NumPy để tạo mảng nhiều chiều và truy cập chúng.

```pycon
>>> import numpy as np  # Tự tìm hiểu ý nghĩa và cách dùng import
>>> np.empty(3)  # Tạo mảng rỗng dung lượng 3; lưu ý không khởi tạo bằng 0
array([0.00000000e+000, 0.00000000e+000, 2.01191014e+180])
>>> np.zeros((3, 3))  # Tạo mảng 3*3 và khởi tạo bằng 0
array([[0., 0., 0.],
       [0., 0., 0.],
       [0., 0., 0.]])
>>> a1 = np.zeros((3, 3), dtype=int)  # Tạo mảng số nguyên 3x3
>>> a1[0][0] = 1  # Truy cập và gán
>>> a1[0, 0] = 1  # Cú pháp gọn hơn
>>> a1.shape  # Hình dạng của mảng
(3, 3)

>>> a1[:2, :2]  # Lấy ma trận con gồm hai dòng đầu, hai cột đầu, không sao chép
array([[1, 0],
       [0, 0]])

>>> a1[:, [0, 2]]  # Lấy cột 1 và 3, không sao chép
array([[1, 0],
       [0, 0],
       [0, 0]])
>>> np.max(a1)  # Lấy giá trị lớn nhất của mảng
1
>>> a1.flatten()  # Trải phẳng mảng
array([1, 0, 0, 0, 0, 0, 0, 0, 0])

>>> np.sort(a1, axis = 1)  # Sắp xếp mảng theo chiều dòng, trả về kết quả sắp xếp
array([[0, 0, 1],
       [0, 0, 0],
       [0, 0, 0]])
>>> a1.sort(axis = 1)  # Sắp xếp tại chỗ theo chiều dòng
```

<a id="dùng-array"></a>

#### Dùng `array`

[`array`](https://docs.python.org/3/library/array.html) là một kiểu mảng số hiệu
quả do thư viện chuẩn Python cung cấp. Nó biểu diễn mảng các giá trị kiểu cơ bản
một cách gọn trong bộ nhớ, nhưng không hỗ trợ lồng mảng và cũng hiếm khi được
dùng trong OI; phần này chỉ nhắc qua.

Nếu không nói gì thêm, "mảng" trong phần sau thường chỉ "danh sách".

<a id="nhập-xuất"></a>

### [Nhập xuất](https://docs.python.org/3/tutorial/inputoutput.html)

Nhập xuất trong Python chủ yếu thực hiện bằng các hàm dựng sẵn `input()` và
`print()`. Phần trước đã giới thiệu cơ bản; sau đây là cách dùng nâng cao hơn.

<a id="xuất-định-dạng"></a>

#### Xuất định dạng

Trong lập trình thi đấu, thông thường chỉ xuất số và chuỗi cơ bản, nên `print()`
thường đã đủ. Chỉ khi cần khống chế số chữ số của số thực mới cần xuất chuỗi định
dạng. Có ba cách định dạng: cách thứ nhất và cũ nhất là dùng toán tử `%` theo
phong cách `printf()`; cách khác là dùng
[hàm `format`](https://docs.python.org/3/library/string.html#formatstrings); cách
thứ ba là
[f-string](https://docs.python.org/3/tutorial/inputoutput.html#formatted-string-literals)
thêm từ Python 3.6, ngắn gọn hơn nhưng không bảo đảm phiên bản Python trong phòng
thi đủ mới. Có thể xem giải thích chi tiết hơn tại
[trang này](https://www.python-course.eu/python3_formatted_output.php). Tuy
thường nên dùng phương thức `format()`, để có trải nghiệm gần với C, sau đây chỉ
minh họa cách cũ tương tự `printf()`:

```pycon
>>> pi = 3.1415926; print('%.4f' % pi)   # Định dạng: %[flags][width][.precision]type
3.1416
>>> '%.4f - %8f = %d' % (pi, 0.1416, 3)  # Nếu bên phải có nhiều tham số, dùng () bao lại; sau này sẽ thấy đây là tuple
'3.1416 - 0.141600 = 3'
```

<a id="hàm-split"></a>

#### Hàm `split()`

Hành vi của hàm `input()` gần với `getline()` trong C++: đọc cả một dòng thành
chuỗi và không gồm ký tự xuống dòng ở cuối. Nhưng trong lập trình thi đấu, dạng
nhập thường gặp là một dòng có nhiều số, nên cần dùng phương thức `split()` của
chuỗi kết hợp với biểu thức sinh danh sách để lấy danh sách chứa các giá trị số.
Sau đây minh họa bằng bài nhập n số và tính trung bình:

```pycon
>>> s = input('Nhập dãy số: '); s  # Khi tự gỡ lỗi, có thể truyền chuỗi vào input() làm lời nhắc
Nhập dãy số: 1 2 3 4 5 6
'1 2 3 4 5 6'
>>> a = s.split(); a
['1', '2', '3', '4', '5', '6']
>>> a = [int(x) for x in a]; a
[1, 2, 3, 4, 5, 6]
>>> # Quá trình nhập trên có thể viết một dòng: a = [int(x) for x in input().split()]
>>> sum(a) / len(a)  # sum() là hàm dựng sẵn
3.5
```

Đôi khi mỗi dòng nhập của đề bài có số lượng giá trị cố định, chẳng hạn đỉnh đầu,
đỉnh cuối và trọng số của cạnh. Nếu chỉ dùng cách trên, mỗi lần phải đọc vào mảng
rồi gán theo chỉ số. Lúc này có thể dùng tính năng "mở gói" của Python để gán
nhiều biến một lần:

```pycon
>>> u, v, w = [int(x) for x in input().split()]
1 2 4
>>> print(u,v,w)
1 2 4
```

Trong đề bài thường gặp trường hợp nhập N dòng. Phần này chưa nói về câu lệnh
vòng lặp cơ bản, nhưng các thao tác trên kiểu tuần tự mạnh của Python có thể xử
lý nhập nhiều dòng mà không cần viết vòng lặp riêng. Sau đây giả sử đọc riêng
điểm đầu, điểm cuối và trọng số của các cạnh vào ba mảng:

```pycon
>>> N = 4; mat = [[int(x) for x in input().split()] for i in range(N)]
1 3 3
1 4 1
2 3 4
3 4 1
>>> mat  # Trước hết đọc theo dòng thành mảng hai chiều
[[1, 3, 3], [1, 4, 1], [2, 3, 4], [3, 4, 1]]
>>> u, v, w = map(list, zip(*mat))
# * mở gói mat để lấy các danh sách bên trong
# zip() gom các phần tử cùng vị trí của nhiều danh sách thành tuple, tạo một bộ lặp
# map(list, iterable) chuyển các phần tử trong kiểu tuần tự (trong ví dụ này là tuple) thành list
>>> print(u, v, w)  # Mở gói bộ lặp do map() tạo ra
[1, 1, 2, 3] [3, 4, 3, 4] [3, 1, 4, 1]
```

Chương trình trên tương đương với việc đọc trước một ma trận N dòng 3 cột, sau đó
chuyển vị thành ma trận 3 dòng N cột, tức danh sách ngoài lồng 3 danh sách, cuối
cùng gán riêng 3 danh sách đại diện điểm đầu, điểm cuối và trọng số cho `u`, `v`,
`w`. Hàm dựng sẵn [`zip()`](https://docs.python.org/3/library/functions.html#zip)
có thể ghép các phần tử tương ứng trong nhiều kiểu tuần tự cùng độ dài vào
`tuple` để tạo kiểu tuần tự mới. Còn `map()` là một thao tác lập trình hàm: áp
dụng một hàm cho từng phần tử của kiểu tuần tự do `zip()` sinh ra; trong ví dụ này
dùng `list()` để biến `tuple` thành `list`.

Có thể tự luyện tập với `*`, [`zip()`](https://docs.python.org/3/library/functions.html#zip)
và [`map()`](https://docs.python.org/3/library/functions.html#map) để hiểu ý
nghĩa. Cần lưu ý trong Python 3, `zip()` và `map()` không còn trả về `list` mà
trả về bộ lặp. Phần này chưa giải thích khác biệt giữa chúng; có thể hiểu bộ lặp
là thứ có thể sinh ra từng phần tử của `list`, và dùng `list()` bọc bộ lặp sẽ tạo
ra `list`.

<a id="đọc-ghi-tệp"></a>

#### [Đọc ghi tệp](https://docs.python.org/3/reference/compound_stmts.html#the-with-statement)

Hàm dựng sẵn [`open()`](https://docs.python.org/3/library/functions.html#open) của
Python dùng để đọc ghi tệp. Để tránh lỗi trong quá trình đọc ghi khiến tệp không
được đóng đúng cách, phần này chỉ giới thiệu cách đọc ghi an toàn bằng câu lệnh
[`with`](https://docs.python.org/3/reference/compound_stmts.html#the-with-statement):

```python
a = []
with open("in.txt") as f:
    N = int(f.readline())  # Đọc N ở dòng đầu tiên
    a[len(a) :] = [[int(x) for x in f.readline().split()] for i in range(N)]

with open("out.txt", "w") as f:
    f.write("1\n")
```

Có nhiều hàm liên quan đến đọc ghi tệp, phù hợp với các tình huống khác nhau. Vì
nhiều kỳ thi OI chưa hỗ trợ dùng Python làm ngôn ngữ chính thức, phần này không
đi sâu.

<a id="luồng-điều-khiển"></a>

### [Luồng điều khiển](https://docs.python.org/3/tutorial/controlflow.html)

Tuy đã học nhiều tính năng của Python, đến lúc này các đoạn mã Python được trình
bày đều là câu lệnh một dòng. Điều đó che đi khác biệt lớn giữa Python và C về
phong cách mã: thứ nhất, Python không dùng `{}` mà dùng thụt lề để biểu diễn khối
lệnh; nếu thụt lề không thẳng hàng sẽ báo lỗi ngay, nếu trộn tab và dấu cách cũng
sẽ báo lỗi. Thứ hai, nơi bắt đầu khối lệnh, chẳng hạn dòng `if` và `for`, phải
kết thúc bằng dấu hai chấm `:`. Điều này giúp mã dễ đọc hơn, nhưng đôi khi vẫn
khiến người quen C thấy kém tự do hơn, vì khi sao chép và dán làm mất thụt lề thì
phải căn lại bằng tay.

<a id="cấu-trúc-vòng-lặp"></a>

#### Cấu trúc vòng lặp

Biểu thức sinh danh sách có thể thực hiện thao tác hàng loạt hiệu quả trong một
dòng, nhưng đôi khi việc ép mọi thứ vào một dòng trở nên gượng ép. Nhiều tình
huống vẫn cần dùng cấu trúc vòng lặp, nên phần này tiếp tục lấy ví dụ đọc nhiều
dòng dữ liệu để minh họa cách viết vòng lặp trong Python:

```python
# Lưu ý từ đây trở đi không dùng REPL nữa; cần tự sao chép dữ liệu nhiều dòng
u, v, w = ([] for i in range(3))  # Gán nhiều biến
for i in range(4):  # Giả sử nhập 4 dòng dữ liệu
    _u, _v, _w = [int(x) for x in input().split()]
    u.append(_u), v.append(_v), w.append(_w)
    # Không thể làm kiểu cin >> u[i] >> v[i] >> w[i], vì sẽ vượt quá độ dài hiện tại của danh sách
    # Có thể khởi tạo danh sách toàn 0 độ dài MAXN, nhưng cần nhớ độ dài thật và xóa phần dư
print(u, v, w)
```

Cần lưu ý vòng lặp `for` trong Python khác C/C++ đáng kể. Vai trò của nó gần với
[vòng lặp dựa trên range của C++11](./new.md#vòng-lặp-for-dựa-trên-phạm-vi): về
bản chất là lặp qua các phần tử trong một kiểu tuần tự. Ví dụ, nếu muốn lặp qua
chỉ số mảng, cần lặp qua `range(len(lst))`, chứ không phải thật sự định nghĩa
điều kiện bắt đầu và kết thúc. Vì vậy nó không linh hoạt như C/C++.

Sau đây dùng vòng lặp `while` để minh họa cách nhập khi số dòng không cố định:

```python
u, v, w = [], [], []  # Gán nhiều biến, tương tự như trên
s = input()  # Lưu ý câu lệnh gán trong Python không thể đặt trong biểu thức điều kiện
while s:  # Không thể viết như C: while(!scanf())
    # Dùng cắt lát để nối, tránh append(); lưu ý trong biểu thức sinh danh sách lại lồng danh sách
    u[len(u) :], v[len(v) :], w[len(w) :] = [[int(x)] for x in s.split()]
    s = input()
# Từ Python 3.8 có toán tử hải tượng, có thể tiết kiệm hai dòng, nhưng môi trường thi có thể không hỗ trợ
while s := input():
    u[len(u) :], v[len(v) :], w[len(w) :] = [[int(x)] for x in s.split()]
print(u, v, w)
```

<a id="cấu-trúc-rẽ-nhánh"></a>

#### Cấu trúc rẽ nhánh

Nhìn chung cấu trúc rẽ nhánh gần với C/C++; các khác biệt về hình thức được minh
họa trong ví dụ sau. Ngoài ra cần lưu ý biểu thức điều kiện không cho phép dùng
toán tử gán thông thường (Python 3.8 trở lên có thể dùng
[`:=`](https://www.python.org/dev/peps/pep-0572/)), và
[không có câu lệnh switch](https://docs.python.org/3/faq/design.html#why-isn-t-there-a-switch-or-case-statement-in-python).

```python
# Biểu thức điều kiện không cần ngoặc hai bên
if 4 >= 3 > 2 and 3 != 5 == 5 != 7:
    print("Có thể viết liên tiếp các toán tử quan hệ")
    x = None or [] or -2
    print("&&  ||  !", "and  or  not", "and or not", sep="\n")
    print("Dùng khéo and/or có thể tiết kiệm số dòng")
    if not x:
        print("Số âm cũng là True, nên câu này không chạy")
    elif x & 1:
        print("Dùng elif thay vì else if\n" "Toán tử bit gần với C; số chẵn&1 bằng 0, nên câu này không chạy")
    else:
        print("Cũng có toán tử ba ngôi") if x else print("Lưu ý cấu trúc")
```

<a id="xử-lý-ngoại-lệ"></a>

#### Xử lý ngoại lệ

Tuy C++ có [khối `try`](https://en.cppreference.com/w/cpp/language/try_catch) để
xử lý ngoại lệ, trong thi đấu thông thường ít dùng. Còn trong Python, phong cách
[EAFP](https://docs.python.org/3/glossary.html#term-eafp) khá phổ biến, nên trong
mã có thể dùng nhiều câu lệnh
[`try-except`](https://docs.python.org/3/reference/compound_stmts.html#the-try-statement).
Phần sau khi giới thiệu `dict` cũng sẽ dùng đến; đoạn dưới minh họa trước:

```python
s = "OI-wiki"
pat = "NOIP"
x = s.find(pat)  # find() không tìm thấy thì trả về -1
try:
    y = s.index(pat)  # index() không tìm thấy thì ném lỗi
    print(y)  # Câu này bị bỏ qua
except ValueError:
    print("Không tìm thấy")
    try:
        print(y)  # Lúc này y chưa được định nghĩa, nên lại ném lỗi
    except NameError as e:
        print("Không thể xuất y")
        print("Lý do:", e)
```

<a id="container-dựng-sẵn"></a>

### Kiểu chứa dựng sẵn

Python có sẵn nhiều kiểu chứa mạnh. Chỉ khi dùng thành thạo và hiểu đặc điểm của
chúng, Python mới thật sự hữu ích trong lập trình thi đấu. Ngoài `list` (danh
sách) đã giới thiệu kỹ, còn có `tuple` (bộ),
[`dict`](https://docs.python.org/3/library/stdtypes.html#mapping-types-dict) (từ
điển) và `set` (tập hợp).

Có thể hiểu `tuple` như một danh sách bất biến, nhưng cần lưu ý ý nghĩa của "bất
biến": nếu một phần tử trong `tuple` là kiểu khả biến như `list`, giá trị của
`list` đó vẫn có thể sửa. `tuple` lưu tham chiếu đến `list`, nên bản thân `tuple`
không thay đổi. Ưu điểm của `tuple` là chi phí phụ nhỏ và có thể băm được, điểm
sau hữu ích khi tạo `dict` và `set`.

```python
tup = tuple([[1, 2], 4])  # Tạo tuple từ list
# Tương đương tup = ([1,2], 4)
tup[0].append(3)
print(tup)
a, b = 0, "I-Wiki"  # Gán nhiều biến là mở gói tuple
print(id(a), id(b))
b, a = a, b
print(id(a), id(b))  # id của a, b đã hoán đổi
# Điều này cho thấy biến trong Python giống như tên gọi:
# phép gán chỉ làm tên đó trỏ đến đối tượng
```

`dict` giống [`map`](./csl/associative-container.md#map) trong C++ STL (lưu ý
phân biệt với hàm dựng sẵn [`map()`](https://docs.python.org/3/library/functions.html#map)
của Python), dùng để lưu cặp khóa-giá trị. Hình thức gần với
[JSON](https://docs.python.org/3/library/json.html),
nhưng khóa trong JSON phải là chuỗi đặt trong dấu nháy kép, còn `dict` linh
hoạt và mạnh hơn: mọi đối tượng có thể băm được đều có thể làm khóa. Cần lưu ý
sau nhiều lần cập nhật phiên bản Python, tính chất của `dict` đã thay đổi đáng
kể, bao gồm thứ tự các phần tử; có thể tự tìm hiểu thêm.

```python
dic = {"key": "value"}  # Dạng cơ bản
dic = {chr(i): i for i in range(65, 91)}  # Ánh xạ chữ cái in hoa sang mã ASCII tương ứng; lưu ý ngắt dòng
dic = dict(zip([chr(i) for i in range(65, 91)], range(65, 91)))  # Hiệu quả như trên
dic = {dic[k]: k for k in dic}  # Đảo ngược cặp khóa-giá trị; for k in dic lặp qua các khóa
dic = {v: k for k, v in dic.items()}  # Tác dụng giống dòng trên; dic.items() lưu từng cặp khóa-giá trị bằng tuple
dic = {
    k: v for k, v in sorted(dic.items(), key=lambda x: -x[1])
}  # Sắp xếp dict giảm dần theo giá trị, dùng biểu thức lambda

print(dic["A"])  # Trả về mục trong dic có khóa 'A', giá trị là 65
dic["a"] = 97  # Gán giá trị cho khóa; nếu dict chưa có khóa thì chèn trực tiếp
if "b" in dic:  # Phong cách LBYL (Look Before You Leap)
    print(dic["b"])  # Nếu dict không có khóa này sẽ lỗi, nên kiểm tra trước
else:
    dic["b"] = 98

# Tình huống kinh điển: đếm số lần xuất hiện
# Khóa mới không tồn tại trong dict gốc, cần xử lý thêm
try:  # Phong cách EAFP (Easier to Ask for Forgiveness than Permission)
    cnter[key] += 1
except KeyError:
    cnter[key] = 1
```

`set` giống [`set`](./csl/associative-container.md#set) trong C++ STL: không lưu
phần tử lặp, có thể xem như `dict` chỉ lưu khóa. Cần lưu ý `set` và `dict` đều
dùng `{}` bao lại, nhưng riêng `{}` sẽ tạo `dict` rỗng chứ không phải `set` rỗng.
Phần này không đưa thêm ví dụ.

<a id="viết-hàm"></a>

### Viết hàm

Trong Python, định nghĩa hàm không cần chỉ định kiểu tham số và kiểu trả về, nên
lượng mã phải viết khi thi OI thường ít hơn.

```python
def add(a, b):
    return a + b  # Lợi thế của kiểu động: a và b cũng có thể là chuỗi


def add_no_swap(a, b):
    print("in func #1:", id(a), id(b))
    a += b
    b, a = a, b
    print("in func #2:", id(a), id(b))  # a, b đã hoán đổi
    return a, b  # Trả về nhiều giá trị, tức trả về tuple, có thể mở gói khi nhận


lst1 = [1, 2]
lst2 = [3, 4]
print("outside func #1:", id(lst1), id(lst2))
add_no_swap(lst1, lst2)
# Bên ngoài hàm, lst1 và lst2 chưa hoán đổi
print("outside func #2:", id(lst1), id(lst2))
# Nhưng giá trị thực sự đã thay đổi
print(lst1, lst2)
```

<a id="tham-số-mặc-định"></a>

#### Tham số mặc định

Tham số hàm trong Python linh hoạt, có tham số từ khóa, tham số biến đổi, v.v.
Nhưng trong lập trình thi đấu, các tính năng này không quá hữu dụng. Phần này chỉ
giới thiệu tham số mặc định, vì C++ cũng có tham số mặc định, và trong Python
tham số mặc định dễ gây lỗi. Ví dụ đoạn mã sau:

```python
def append_to(element, to=[]):
    to.append(element)
    return to


lst1 = append_to(12)
lst2 = append_to(42)
print(lst1, lst2)

# Có thể nghĩ kết quả là [12] [42]
# Nhưng kết quả thực tế là [12, 42] [12, 42]
```

Kết quả trên xảy ra vì giá trị tham số mặc định chỉ được gán một lần tại thời
điểm định nghĩa hàm. Với đối tượng khả biến (như `list`, `dict`, `set`), mỗi lần
gọi hàm sẽ dùng chung cùng một đối tượng. `lst1` và `lst2` đều trỏ đến cùng một
`list` mặc định trong bộ nhớ. Vì vậy sau lần gọi thứ hai, nội dung `list` dùng
chung thành `[12, 42]`. Do đó, giá trị tham số mặc định của hàm nên là đối tượng
bất biến; dùng `None` làm giá trị giữ chỗ là thực hành tốt:

```python
def append_to(element, to=None):
    if to is None:
        to = []
    to.append(element)
    return to


lst1 = append_to(12)
lst2 = append_to(42)
print(lst1, lst2)

# Kết quả chạy là [12] [42]
```

<a id="type-hint"></a>

#### Gợi ý kiểu (type hint)

Python là ngôn ngữ kiểm tra kiểu động: xử lý kiểu một cách linh hoạt nhưng ngầm
định. Trình thông dịch Python chỉ kiểm tra kiểu khi chạy, và cho phép thay đổi
kiểu biến trong lúc chạy. Vì vậy, một số lỗi trong chương trình có thể chỉ lộ ra
lúc chạy:

```pycon
>>> if False:
...     1 + "two"  # Dòng này không bao giờ chạy, nên không phát sinh TypeError
... else:
...     1 + 2
...
3

>>> 1 + "two"  # Bây giờ được kiểm tra kiểu, và phát sinh TypeError
TypeError: unsupported operand type(s) for +: 'int' and 'str'
```

Từ Python 3.5, gợi ý kiểu được thêm vào, cho phép đặt kiểu cho tham số hàm và giá
trị trả về. Tuy nhiên, chúng chỉ là gợi ý, không có tác dụng ràng buộc thực tế;
cần công cụ kiểm tra tĩnh mới phát hiện loại lỗi này, ví dụ
[PyCharm](https://www.jetbrains.com/pycharm/) và [Mypy](http://mypy-lang.org/).
Vì vậy tính năng này không thật thiết yếu với OIer, biết khái niệm là đủ. Có thể
gán gợi ý kiểu cho tham số và giá trị trả về của hàm như sau:

```python
def headline(
    text,  # type: str
    width=80,  # type: int
    fill_char="-",  # type: str
):  # type: (...) -> str
    return f"{text.title()}".center(width, fill_char)


print(headline("type comments work", width=40))
```

Ngoài tham số hàm, biến cũng có thể có gợi ý kiểu. Có thể gọi `__annotations__`
để xem mọi gợi ý kiểu trong hàm. Gợi ý kiểu cho biến đem lại cho Python một phần
tính chất của ngôn ngữ tĩnh: khai báo và gán giá trị tách nhau.

```pycon
>>> nothing: str
>>> nothing
NameError: name 'nothing' is not defined

>>> __annotations__
{'nothing': <class 'str'>}
```

<a id="decorator"></a>

## Hàm trang trí (decorator)

Hàm trang trí là một hàm nhận một hàm hoặc phương thức làm tham số duy nhất và
trả về một hàm hoặc phương thức mới, trong đó tích hợp hàm/phương thức đã được
trang trí và có thêm một số chức năng. Nói ngắn gọn, hàm trang trí cho phép tăng
cường chức năng của hàm mà không sửa mã của hàm đó. Có thể tham khảo
[tài liệu chính thức](https://docs.python.org/3/glossary.html#term-decorator).

Một số hàm trang trí hữu dụng trong thi đấu, chẳng hạn
[`lru_cache`](https://docs.python.org/3/library/functools.html#functools.lru_cache).
Nó có thể tự động thêm khả năng ghi nhớ kết quả cho hàm, thiết thực trong thuật
toán đệ quy:

`@lru_cache(maxsize=128,typed=False)`

-   Có 2 tham số truyền vào: `maxsize` và `typed`. Nếu không truyền, giá trị mặc
    định của `maxsize` là 128, của `typed` là `False`.
-   Tham số `maxsize` biểu thị dung lượng bộ nhớ đệm LRU, tức số lượng kết quả tối
    đa mà phương thức được trang trí có thể lưu. Nếu giá trị này là 128, phương
    thức đó tối đa lưu đệm 128 kết quả trả về; nếu `maxsize` là `None`, số kết
    quả được lưu đệm không bị giới hạn.
-   Nếu `typed` đặt thành `True`, các tham số hàm có kiểu khác nhau sẽ được lưu
    đệm riêng. Ví dụ, `f(3)` và `f(3.0)` sẽ được lưu đệm hai lần.

Sau đây là ví dụ dùng `lru_cache` để tối ưu tính dãy Fibonacci:

```python
@lru_cache(maxsize=None)
def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)
```

<a id="thư-viện-chuẩn-thường-dùng"></a>

## Thư viện chuẩn thường dùng

Phần này giới thiệu một số thư viện chuẩn có thể dùng khi viết thuật toán. Cách
dùng cụ thể có thể tự tìm hoặc đọc
[tài liệu chính thức](https://docs.python.org/3/library/index.html).

| Tên thư viện                                                        | Công dụng                                      |
| ------------------------------------------------------------------- | ---------------------------------------------- |
| [`array`](https://docs.python.org/3/library/array.html)             | Mảng độ dài cố định                            |
| [`argparse`](https://docs.python.org/3/library/argparse.html)       | Xử lý tham số dòng lệnh                        |
| [`bisect`](https://docs.python.org/3/library/bisect.html)           | Tìm kiếm nhị phân                              |
| [`collections`](https://docs.python.org/3/library/collections.html) | Từ điển có thứ tự, `deque` và các cấu trúc dữ liệu khác |
| [`fractions`](https://docs.python.org/3/library/fractions.html)     | Số hữu tỷ                                      |
| [`heapq`](https://docs.python.org/3/library/heapq.html)             | Hàng đợi ưu tiên dựa trên đống                 |
| [`io`](https://docs.python.org/3/library/io.html)                   | Luồng tệp, luồng bộ nhớ                        |
| [`itertools`](https://docs.python.org/3/library/itertools.html)     | Bộ lặp                                         |
| [`math`](https://docs.python.org/3/library/math.html)               | Hàm toán học                                   |
| [`os.path`](https://docs.python.org/3/library/os.html)              | Đường dẫn hệ thống, v.v.                       |
| [`random`](https://docs.python.org/3/library/random.html)           | Số ngẫu nhiên                                  |
| [`re`](https://docs.python.org/3/library/re.html)                   | Biểu thức chính quy                            |
| [`struct`](https://docs.python.org/3/library/struct.html)           | Chuyển đổi struct và dữ liệu nhị phân          |
| [`sys`](https://docs.python.org/3/library/sys.html)                 | Thông tin hệ thống                             |

<a id="đối-chiếu-c-và-python-qua-bài-mẫu"></a>

## Đối chiếu C++ và Python qua bài mẫu

??? note "[Bài mẫu Luogu P4779: Mẫu đường đi ngắn nhất đơn nguồn (bản chuẩn)](https://www.luogu.com.cn/problem/P4779)"
    Cho một đồ thị có hướng gồm $n(1 \leq n \leq 10^5)$ đỉnh và
    $m(1 \leq m \leq 2\times 10^5)$ cạnh có trọng số không âm. Tính khoảng cách
    từ $s$ đến mọi đỉnh. Dữ liệu bảo đảm có thể đi từ $s$ đến mọi đỉnh.

<a id="khai-báo-hằng-số"></a>

### Khai báo hằng số

=== "C++"
    ```cpp
    #include <cstdio>
    #include <cstring>
    #include <queue>
    #include <vector>
    using namespace std;
    constexpr int N = 1e5 + 5, M = 2e5 + 5;
    ```

=== "Python"
    ```python
    try:  # Nạp mô-đun hàng đợi ưu tiên
        import Queue as pq  # Phiên bản Python < 3.0
    except ImportError:
        import queue as pq  # Python 3.*

    N = int(1e5 + 5)
    M = int(2e5 + 5)
    INF = 0x3F3F3F3F
    ```

<a id="khai-báo-struct-sao-tiến-và-các-biến-khác"></a>

### Khai báo cấu trúc sao tiến và các biến khác

=== "C++"
    ```cpp
    struct qxx {
      int nex, t, v;
    };

    qxx e[M];
    int h[N], cnt;

    void add_path(int f, int t, int v) { e[++cnt] = qxx{h[f], t, v}, h[f] = cnt; }

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int dist[N];
    ```

=== "Python"
    ```python
    class qxx:  # Lớp sao tiến (struct)
        def __init__(self):
            self.nex = 0
            self.t = 0
            self.v = 0


    e = [qxx() for i in range(M)]  # Danh sách liên kết
    h = [0 for i in range(N)]
    cnt = 0

    dist = [INF for i in range(N)]
    q = pq.PriorityQueue()  # Định nghĩa hàng đợi ưu tiên; mặc định là heap nhỏ nhất theo phần tử đầu


    def add_path(f, t, v):  # Thêm cạnh vào sao tiến
        # Nếu muốn sửa biến toàn cục, phải khai báo bằng global
        global cnt, e, h
        # Câu lệnh xuất khi gỡ lỗi; nhiều biến dùng tuple
        # print("add_path(%d,%d,%d)" % (f,t,v))
        cnt += 1
        e[cnt].nex = h[f]
        e[cnt].t = t
        e[cnt].v = v
        h[f] = cnt
    ```

<a id="thuật-toán-dijkstra"></a>

### Thuật toán Dijkstra

=== "C++"
    ```cpp
    void dijkstra(int s) {
      memset(dist, 0x3f, sizeof(dist));
      dist[s] = 0, q.push(make_pair(0, s));
      while (q.size()) {
        pii u = q.top();
        q.pop();
        if (dist[u.second] < u.first) continue;
        for (int i = h[u.second]; i; i = e[i].nex) {
          const int &v = e[i].t, &w = e[i].v;
          if (dist[v] <= dist[u.second] + w) continue;
          dist[v] = dist[u.second] + w;
          q.push(make_pair(dist[v], v));
        }
      }
    }
    ```

=== "Python"
    ```python
    def nextedgeid(u):  # Bộ sinh, có thể dùng trong vòng lặp for
        i = h[u]
        while i:
            yield i
            i = e[i].nex


    def dijkstra(s):
        dist[s] = 0
        q.put((0, s))
        while not q.empty():
            u = q.get()  # Hàm get tiện thể xóa phần tử tương ứng trong heap
            if dist[u[1]] < u[0]:
                continue
            for i in nextedgeid(u[1]):
                v = e[i].t
                w = e[i].v
                if dist[v] <= dist[u[1]] + w:
                    continue
                dist[v] = dist[u[1]] + w
                q.put((dist[v], v))
    ```

<a id="hàm-main"></a>

### Hàm main

=== "C++"
    ```cpp
    int n, m, s;

    int main() {
      scanf("%d%d%d", &n, &m, &s);
      for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_path(u, v, w);
      }
      dijkstra(s);
      for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
      return 0;
    }
    ```

=== "Python"
    ```python
    if __name__ == "__main__":
        # Đọc nhiều số nguyên trên một dòng. Lưu ý nó đọc cả dòng vào
        n, m, s = map(int, input().split())
        for i in range(m):
            u, v, w = map(int, input().split())
            add_path(u, v, w)

        dijkstra(s)

        for i in range(1, n + 1):
            print(dist[i], end=" ")

        print()
    ```

<a id="mã-hoàn-chỉnh"></a>

### Mã hoàn chỉnh

=== "C++"
    ```cpp
    #include <cstdio>
    #include <cstring>
    #include <queue>
    #include <vector>
    using namespace std;
    constexpr int N = 1e5 + 5, M = 2e5 + 5;

    struct qxx {
      int nex, t, v;
    };

    qxx e[M];
    int h[N], cnt;

    void add_path(int f, int t, int v) { e[++cnt] = qxx{h[f], t, v}, h[f] = cnt; }

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int dist[N];

    void dijkstra(int s) {
      memset(dist, 0x3f, sizeof(dist));
      dist[s] = 0, q.push(make_pair(0, s));
      while (q.size()) {
        pii u = q.top();
        q.pop();
        if (dist[u.second] < u.first) continue;
        for (int i = h[u.second]; i; i = e[i].nex) {
          const int &v = e[i].t, &w = e[i].v;
          if (dist[v] <= dist[u.second] + w) continue;
          dist[v] = dist[u.second] + w;
          q.push(make_pair(dist[v], v));
        }
      }
    }

    int n, m, s;

    int main() {
      scanf("%d%d%d", &n, &m, &s);
      for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_path(u, v, w);
      }
      dijkstra(s);
      for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
      return 0;
    }
    ```

=== "Python"
    ```python
    try:  # Nạp mô-đun hàng đợi ưu tiên
        import Queue as pq  # Phiên bản Python < 3.0
    except ImportError:
        import queue as pq  # Python 3.*

    N = int(1e5 + 5)
    M = int(2e5 + 5)
    INF = 0x3F3F3F3F


    class qxx:  # Lớp sao tiến (struct)
        def __init__(self):
            self.nex = 0
            self.t = 0
            self.v = 0


    e = [qxx() for i in range(M)]  # Danh sách liên kết
    h = [0 for i in range(N)]
    cnt = 0

    dist = [INF for i in range(N)]
    q = pq.PriorityQueue()  # Định nghĩa hàng đợi ưu tiên; mặc định là heap nhỏ nhất theo phần tử đầu


    def add_path(f, t, v):  # Thêm cạnh vào sao tiến
        # Nếu muốn sửa biến toàn cục, phải khai báo bằng global
        global cnt, e, h
        # Câu lệnh xuất khi gỡ lỗi; nhiều biến dùng tuple
        # print("add_path(%d,%d,%d)" % (f,t,v))
        cnt += 1
        e[cnt].nex = h[f]
        e[cnt].t = t
        e[cnt].v = v
        h[f] = cnt


    def nextedgeid(u):  # Bộ sinh, có thể dùng trong vòng lặp for
        i = h[u]
        while i:
            yield i
            i = e[i].nex


    def dijkstra(s):
        dist[s] = 0
        q.put((0, s))
        while not q.empty():
            u = q.get()
            if dist[u[1]] < u[0]:
                continue
            for i in nextedgeid(u[1]):
                v = e[i].t
                w = e[i].v
                if dist[v] <= dist[u[1]] + w:
                    continue
                dist[v] = dist[u[1]] + w
                q.put((dist[v], v))


    # Nếu chạy trực tiếp tệp Python này (không phải import như mô-đun) thì thực thi lệnh
    if __name__ == "__main__":
        # Đọc nhiều số nguyên trên một dòng. Lưu ý nó đọc cả dòng vào
        n, m, s = map(int, input().split())
        for i in range(m):
            u, v, w = map(int, input().split())
            add_path(u, v, w)

        dijkstra(s)

        for i in range(1, n + 1):
            # Hai cú pháp xuất sau đây đều dùng được
            print("{}".format(dist[i]), end=" ")
            # print("%d" % dist[i],end=' ')

        print()  # Xuống dòng ở cuối
    ```

<a id="tài-liệu-tham-khảo"></a>

## Tài liệu tham khảo

1.  [Python Documentation](https://www.python.org/doc/)
2.  [Python tutorial chính thức bằng tiếng Anh](https://docs.python.org/3/tutorial/)
3.  [Learn Python3 In Y Minutes](https://learnxinyminutes.com/docs/python3/)
4.  [Real Python Tutorials](https://realpython.com/)
5.  [Python tutorial của Liao Xuefeng](https://www.liaoxuefeng.com/wiki/1016959663602400/)
6.  [GeeksforGeeks: Python Tutorials](https://www.geeksforgeeks.org/python-programming-language/)

<a id="tài-liệu-và-chú-thích-tham-khảo"></a>

## Tài liệu và chú thích tham khảo

[^ref1]: [2. Trình thông dịch Python - Tài liệu Python 3](https://docs.python.org/3/tutorial/interpreter.html#id1)

[^ref2]: [Hướng dẫn Unicode - Tài liệu Python 3](https://docs.python.org/3/howto/unicode.html#the-string-type)
