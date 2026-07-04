Mảng là một container lưu các đối tượng cùng kiểu. Các đối tượng trong mảng
không có tên riêng, mà được truy cập thông qua vị trí của chúng. Kích thước của
mảng là cố định, không thể tùy ý thay đổi độ dài mảng.

## Định nghĩa mảng

Khai báo mảng có dạng `a[d]`, trong đó `a` là tên mảng, còn `d` là số phần tử
trong mảng. Tại thời điểm biên dịch, `d` phải là giá trị đã biết; nói cách khác,
`d` nên là một biểu thức hằng kiểu nguyên.

```cpp
unsigned int d1 = 42;
const int d2 = 42;
int arr1[d1];  // sai: d1 không phải biểu thức hằng
int arr2[d2];  // đúng: arr2 là một mảng có độ dài 42
```

Không thể gán trực tiếp một mảng cho một mảng khác:

```cpp
int arr1[3];
int arr2 = arr1;  // sai
arr2 = arr1;      // sai
```

Nên cố gắng định nghĩa các mảng lớn thành biến toàn cục. Vì biến cục bộ được
tạo trên vùng stack, mảng quá lớn (lớn hơn kích thước stack) sẽ làm tràn stack
và dẫn đến RE. Nếu khai báo mảng ở phạm vi toàn cục, mảng sẽ được tạo trong
vùng tĩnh.

## Truy cập phần tử mảng

Có thể dùng toán tử chỉ số `[]` để truy cập phần tử trong mảng. Chỉ số của mảng
(tức giá trị trong cặp ngoặc vuông) bắt đầu từ 0. Lấy một mảng có 10 phần tử làm
ví dụ, chỉ số của nó là từ 0 đến 9, không phải từ 1 đến 10. Tuy nhiên trong OI,
để tiện sử dụng, ta thường khai báo mảng lớn hơn một chút, không dùng phần tử
đầu tiên của mảng và bắt đầu truy cập từ chỉ số 1.

Ví dụ 1: đọc một số nguyên $n$ từ chuẩn nhập, rồi đọc tiếp $n$ số và lưu vào
mảng. Trong đó, $n\leq 1000$.

```cpp
#include <iostream>
using namespace std;

int arr[1001];  // phạm vi chỉ số của mảng arr là [0, 1001)

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
}
```

Ví dụ 2: tiếp theo ví dụ 1, tính tổng các phần tử trong mảng `arr` và in tổng.
Giả sử tổng của mọi phần tử trong mảng không vượt quá $2^{31} - 1$.

```cpp
#include <iostream>
using namespace std;

int arr[1001];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += arr[i];
  }

  printf("%d\n", sum);
  return 0;
}
```

### Truy cập vượt biên

Chỉ số mảng $\mathit{idx}$ phải thỏa mãn
$0\leq \mathit{idx}< \mathit{size}$. Nếu chỉ số không nằm trong phạm vi này, đó
là hành vi không xác định và có thể sinh ra hậu quả không dự đoán được, như
segmentation fault hoặc sửa nhầm biến ngoài dự kiến, v.v.

## Mảng nhiều chiều

Bản chất của mảng nhiều chiều là "mảng của mảng", tức phần tử của mảng ngoài
cũng là mảng. Một mảng hai chiều cần hai kích thước để định nghĩa: độ dài của
mảng và độ dài của phần tử bên trong mảng. Khi truy cập mảng hai chiều, cần viết
hai chỉ số:

```cpp
int arr[3][4];  // một mảng độ dài 3, phần tử của nó là "mảng độ dài 4
                // có phần tử kiểu int"
arr[2][1] = 1;  // truy cập mảng hai chiều
```

Ta thường dùng vòng lặp `for` lồng nhau để xử lý mảng hai chiều.

Ví dụ: đọc hai số $n$ và $m$ từ chuẩn nhập, lần lượt biểu thị chiều cao và chiều
rộng của một ảnh đen trắng, thỏa mãn $n,m\leq 1000$. Trong $n$ dòng dữ liệu tiếp
theo, mỗi dòng có $m$ số cách nhau bằng khoảng trắng, biểu thị giá trị độ sáng
tại vị trí đó. Bây giờ ta đọc ảnh này và lưu vào mảng hai chiều.

```cpp
const int MAXN = 1001;
int pic[MAXN][MAXN];
int n, m;

cin >> n >> m;
for (int i = 1; i <= n; ++i)
  for (int j = 1; j <= m; ++j) cin >> pic[i][j];
```

Tương tự, bạn có thể định nghĩa mảng ba chiều, bốn chiều và các mảng có số
chiều cao hơn.
