Mặc định, các câu lệnh trong chương trình được thực thi theo thứ tự xuất hiện.
Trong nhiều trường hợp, một số câu lệnh chỉ được thực thi khi một điều kiện nhất
định thỏa mãn; khi đó cần dùng cấu trúc rẽ nhánh. Chọn câu lệnh rẽ nhánh phù hợp
giúp logic chương trình mạch lạc hơn.

## Câu lệnh if

### Câu lệnh if cơ bản

Sau đây là cấu trúc của câu lệnh `if` cơ bản.

```cpp
if (dieu_kien) {
  than;
}
```

Câu lệnh `if` đánh giá điều kiện; nếu điều kiện đúng, các câu lệnh trong phần
thân được thực thi, nếu không thì bị bỏ qua.

Nếu phần thân chỉ có một câu lệnh, có thể lược bỏ cặp dấu ngoặc nhọn. Tuy vậy,
khi mới học hoặc khi mã có nhiều nhánh lồng nhau, giữ lại dấu ngoặc nhọn thường
làm mã dễ đọc hơn và giảm khả năng nhầm lẫn.

### Câu lệnh if...else

```cpp
if (dieu_kien) {
  than1;
} else {
  than2;
}
```

Câu lệnh `if...else` tương tự câu lệnh `if`; phần `else` không cần viết thêm
điều kiện. Khi điều kiện của `if` thỏa mãn, phần thân của `if` sẽ được thực thi;
khi điều kiện không thỏa mãn, phần thân của `else` sẽ được thực thi. Tương tự,
nếu phần thân chỉ có một câu lệnh, có thể lược bỏ cặp dấu ngoặc nhọn.

### Câu lệnh else if

```cpp
if (dieu_kien1) {
  than1;
} else if (dieu_kien2) {
  than2;
} else if (dieu_kien3) {
  than3;
} else {
  than4;
}
```

Câu lệnh `else if` là sự kết hợp giữa `if` và `else`, dùng để xét nhiều điều kiện
và chọn một trong nhiều nhánh câu lệnh. Câu lệnh `else` cuối cùng không cần viết
thêm điều kiện. Ví dụ, nếu điều kiện 1 đúng thì thực thi thân 1; nếu điều kiện 3
đúng còn điều kiện 1 và điều kiện 2 đều sai thì thực thi thân 3; chỉ khi tất cả
điều kiện đều sai mới thực thi thân 4.

Về bản chất, câu lệnh này tương đương với việc đặt một câu lệnh `if` trong nhánh
`else` của `if` đầu tiên, rồi lược bỏ cặp dấu ngoặc nhọn và viết chúng liền nhau.
Nếu các điều kiện có quan hệ ngang hàng, cách viết này giúp logic của mã mạch lạc
hơn.

Về mặt logic, nó tương tự đoạn mô tả sau:

> Khi giải phương trình bậc hai một ẩn, quan hệ giữa nghiệm của phương trình và
> biệt thức là:
>
> -   Nếu $\Delta<0$,
>     phương trình vô nghiệm;
> -   Ngược lại, nếu $\Delta=0$,
>     phương trình có hai nghiệm thực bằng nhau;
> -   Ngược lại,
>     phương trình có hai nghiệm thực phân biệt;

## Câu lệnh switch

```cpp
switch (bieu_thuc_chon) {
  case nhan1:
    than1;
  case nhan2:
    than2;
  default:
    than3;
}
```

Khi câu lệnh `switch` được thực thi, trước tiên chương trình tính giá trị của
biểu thức chọn, sau đó dựa vào giá trị đó để chọn nhãn tương ứng và bắt đầu thực
thi từ vị trí nhãn ấy. Trong C++, biểu thức chọn thường là biểu thức kiểu số
nguyên hoặc kiểu liệt kê; các kiểu lớp chuyển đổi được sang những kiểu này cũng
hợp lệ. Các nhãn `case` phải là biểu thức hằng có thể chuyển đổi sang kiểu của
biểu thức chọn. Ví dụ:

```cpp
int i = 1;  // i có kiểu int, thỏa mãn yêu cầu của biểu thức chọn

switch (i) {
  case 1:
    cout << "OI WIKI" << endl;
}
```

```cpp
char i = 'A';

// i có kiểu char, nhưng char cũng thuộc nhóm kiểu số nguyên,
// nên thỏa mãn yêu cầu của biểu thức chọn
switch (i) {
  case 'A':
    cout << "OI WIKI" << endl;
}
```

Trong câu lệnh `switch`, có thể cần thêm câu lệnh `break` để kết thúc nhánh hiện
tại. Nếu không có `break`, sau khi `case` tương ứng được chọn, chương trình sẽ
tiếp tục chạy xuống các câu lệnh trong những `case` phía sau và cả `default`.
Đây gọi là hiện tượng rơi tiếp (`fallthrough`). Ví dụ:

```cpp
char i = 'B';

switch (i) {
  case 'A':
    cout << "OI" << endl;
    break;

  case 'B':
    cout << "WIKI" << endl;

  default:
    cout << "Hello World" << endl;
}
```

Sau khi chạy đoạn mã trên, kết quả được in ra là `WIKI` và `Hello World`. Khi
không muốn chạy tiếp các nhánh phía sau, cần dùng `break`. Ví dụ:

```cpp
char i = 'B';

switch (i) {
  case 'A':
    cout << "OI" << endl;
    break;

  case 'B':
    cout << "WIKI" << endl;
    break;

  default:
    cout << "Hello World" << endl;
}
```

Sau khi chạy đoạn mã trên, kết quả được in ra là `WIKI`. Vì có `break`, các câu
lệnh ở những nhánh tiếp theo sẽ không được thực thi. Nhánh cuối cùng không cần
`break`, vì sau đó không còn câu lệnh nào nữa.

Giá trị của các nhãn `case` không được trùng nhau, nhưng thứ tự xuất hiện của
từng `case` (bao gồm cả `default`) có thể tùy ý. Ví dụ:

```cpp
char i = 'B';

switch (i) {
  case 'B':
    cout << "WIKI" << endl;
    break;

  default:
    cout << "Hello World" << endl;
    break;

  case 'A':
    cout << "OI" << endl;
}
```

Trong các nhánh `case` của `switch` cũng có thể thêm cặp dấu ngoặc nhọn. Nếu cần
định nghĩa biến riêng trong một nhánh `case`, nên dùng cặp dấu ngoặc nhọn để tạo
phạm vi cục bộ tường minh và tránh lỗi do nhảy qua phần khởi tạo biến. Ví dụ:

```cpp
char i = 'B';
int ans = 0;

switch (i) {
  case 'A': {
    int i = 1, j = 2;
    cout << "OI" << endl;
    ans = i + j;
    break;
  }

  case 'B': {
    int qwq = 3;
    cout << "WIKI" << endl;
    ans = qwq * qwq;
    break;
  }

  default: {
    cout << "Hello World" << endl;
  }
}
```

??? note "Hiểu switch như thế nào"
    Phần trên đã dùng nhiều cách nói như "nhánh case", "mệnh đề case", v.v.
    Ở tầng triển khai thấp hơn, `switch` tương đương với một nhóm câu lệnh nhảy.
    Đây cũng là cơ sở của những kỹ thuật đặc biệt như Duff's Device; có thể tham
    khảo thêm khi cần tìm hiểu sâu hơn.
