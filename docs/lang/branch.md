Theo mặc định, một chương trình sẽ được thực thi theo thứ tự các dòng mã. Đôi khi ta cần chọn lọc để chỉ thực thi một số câu lệnh nhất định; khi đó cần dùng chức năng rẽ nhánh để thực hiện. Việc chọn câu lệnh rẽ nhánh phù hợp có thể nâng cao hiệu quả của chương trình.

## Câu lệnh if

### Câu lệnh if cơ bản

Dưới đây là cấu trúc của câu lệnh if cơ bản.

```cpp
if (dieu_kien) {
  than;
}
```

Câu lệnh if đánh giá điều kiện; nếu kết quả là đúng (khác 0), câu lệnh bên trong sẽ được thực thi, ngược lại thì không thực thi.

Nếu phần thân chỉ có một câu lệnh, có thể lược bỏ cặp dấu ngoặc nhọn.

### Câu lệnh if...else

```cpp
if (dieu_kien) {
  than1;
} else {
  than2;
}
```

Câu lệnh if...else tương tự câu lệnh if; phần else không cần viết thêm điều kiện. Khi điều kiện của câu lệnh if được thỏa mãn, các câu lệnh trong if sẽ được thực thi; khi điều kiện của if không được thỏa mãn, các câu lệnh trong else sẽ được thực thi. Tương tự, khi phần thân chỉ có một câu lệnh, có thể lược bỏ cặp dấu ngoặc nhọn.

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

Câu lệnh else if là sự kết hợp giữa if và else, dùng để xét nhiều điều kiện và chọn các nhánh câu lệnh khác nhau. Câu lệnh else cuối cùng không cần viết thêm điều kiện. Ví dụ, nếu điều kiện 1 đúng thì thực thi thân 1; nếu điều kiện 3 đúng còn điều kiện 1 và điều kiện 2 đều sai thì thực thi thân 3; chỉ khi tất cả điều kiện đều sai mới thực thi thân 4.

Thực ra, câu lệnh này tương đương với việc trong nhánh else của if đầu tiên chỉ có một câu lệnh if, rồi lược bỏ cặp dấu ngoặc nhọn và viết chúng liền nhau. Nếu các điều kiện có quan hệ ngang hàng với nhau, cách viết này có thể làm logic của mã rõ ràng hơn.

Về mặt logic, nó gần tương đương với đoạn mô tả sau:

> Khi giải phương trình bậc hai một ẩn, quan hệ giữa nghiệm của phương trình và biệt thức là:
>
> -   Nếu ($\Delta<0$)
>     phương trình vô nghiệm;
> -   Ngược lại, nếu ($\Delta=0$)
>     phương trình có hai nghiệm thực bằng nhau;
> -   Ngược lại
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

Khi câu lệnh switch được thực thi, trước tiên chương trình tính giá trị của biểu thức chọn, sau đó dựa vào giá trị đó để chọn nhãn tương ứng và bắt đầu thực thi từ vị trí nhãn ấy. Trong đó, biểu thức chọn phải là một biểu thức kiểu số nguyên, còn các nhãn đều phải là hằng kiểu số nguyên. Ví dụ:

```cpp
int i = 1;  // Kiểu dữ liệu của i ở đây là kiểu int, thỏa mãn yêu cầu của biểu thức kiểu số nguyên

switch (i) {
  case 1:
    cout << "OI WIKI" << endl;
}
```

```cpp
char i = 'A';

// Kiểu dữ liệu của i ở đây là kiểu char, nhưng char
// cũng thuộc nhóm kiểu số nguyên, nên thỏa mãn yêu cầu của biểu thức kiểu số nguyên
switch (i) {
  case 'A':
    cout << "OI WIKI" << endl;
}
```

Trong câu lệnh switch, tùy theo nhu cầu còn cần thêm câu lệnh break để ngắt; nếu không, sau khi case tương ứng được chọn, tất cả câu lệnh trong các case tiếp theo và trong default đều sẽ được chạy. Có thể xem ví dụ cụ thể bên dưới.

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

Sau khi chạy đoạn mã trên, kết quả được in ra là `WIKI` và `Hello World`. Nếu không muốn các câu lệnh ở những nhánh phía dưới được chạy, ta cần dùng break; có thể xem ví dụ cụ thể bên dưới.

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

Sau khi chạy đoạn mã trên, kết quả được in ra là WIKI. Vì có break, các câu lệnh tiếp theo sẽ không tiếp tục được thực thi. Câu lệnh cuối cùng không cần break, vì phía dưới không còn câu lệnh nào nữa.

Số hiệu của các lối vào xử lý không được trùng nhau, nhưng có thể đảo thứ tự. Nói cách khác, thứ tự của các số hiệu lối vào không quan trọng. Thứ tự xuất hiện của từng case (bao gồm cả default) có thể tùy ý. Ví dụ:

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

Trong các mệnh đề case của switch cũng có thể chọn thêm cặp dấu ngoặc nhọn. Tuy nhiên cần chú ý rằng, nếu cần định nghĩa biến trong câu lệnh switch, bắt buộc phải thêm cặp dấu ngoặc nhọn. Ví dụ:

```cpp
char i = 'B';

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
    Ở phần trên đã dùng nhiều cách nói như "mệnh đề case", "mệnh đề con case", v.v. Thực ra, ở tầng triển khai bên dưới, switch tương đương với một nhóm câu lệnh nhảy. Cũng vì vậy mới có kỹ thuật đặc biệt như Duff's Device; những ai muốn tìm hiểu thêm có thể tự nghiên cứu.
