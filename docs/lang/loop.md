Đôi khi, chúng ta cần làm một việc nhiều lần. Để không phải viết quá nhiều đoạn mã lặp lại, ta cần dùng vòng lặp.

Đôi khi, số lần lặp không phải là một hằng số, nên ta không thể viết lặp lại mã nguồn nhiều lần mà bắt buộc phải dùng vòng lặp.

## Câu lệnh for

Sau đây là cấu trúc của câu lệnh for:

```cpp
for (khoi_tao; dieu_kien_kiem_tra; cap_nhat) {
  than_vong_lap;
}
```

Thứ tự thực thi:

![](images/for-loop.svg)

Ví dụ, đọc vào n số:

```cpp
for (int i = 1; i <= n; ++i) {
  cin >> a[i];
}
```

Trong ba phần của câu lệnh for, bất kỳ phần nào cũng có thể được bỏ qua. Trong đó, nếu bỏ qua điều kiện kiểm tra thì tương đương với việc điều kiện luôn đúng.

## Câu lệnh while

Sau đây là cấu trúc của câu lệnh while:

```cpp
while (dieu_kien_kiem_tra) {
  than_vong_lap;
}
```

Thứ tự thực thi:

![](images/while-loop.svg)

Ví dụ, kiểm chứng giả thuyết 3x+1:

```cpp
while (x > 1) {
  if (x % 2 == 1) {
    x = 3 * x + 1;
  } else {
    x = x / 2;
  }
}
```

## Câu lệnh do...while

Sau đây là cấu trúc của câu lệnh do...while:

```cpp
do {
  than_vong_lap;
} while (dieu_kien_kiem_tra);
```

Thứ tự thực thi:

![](images/do-while-loop.svg)

Điểm khác với câu lệnh while là câu lệnh do...while thực thi thân vòng lặp trước rồi mới kiểm tra điều kiện.

Ví dụ, liệt kê các hoán vị:

```cpp
do {
  // làm gì đó...
} while (next_permutation(a + 1, a + n + 1));
```

## Mối liên hệ giữa ba loại câu lệnh

```cpp
// Câu lệnh for

for (statement1; statement2; statement3) {
  statement4;
}

// Câu lệnh while

statement1;
while (statement2) {
  statement4;
  statement3;
}
```

Khi trong statement4 không có câu lệnh `continue` (xem bên dưới), hai cách viết này là tương đương, nhưng cách viết bên dưới rất ít khi được dùng.

```cpp
// Câu lệnh while

statement1;
while (statement2) {
  statement1;
}

// Câu lệnh do...while

do {
  statement1;
} while (statement2);
```

Khi trong statement1 không có câu lệnh `continue`, hai cách viết này cũng tương đương.

```cpp
while (1) {
  // làm gì đó...
}

for (;;) {
  // làm gì đó...
}
```

Hai cách viết này đều tạo vòng lặp vô hạn. (Có thể dùng `break` (xem bên dưới) để thoát.)

Có thể thấy ba loại câu lệnh có thể thay thế lẫn nhau, nhưng nói chung việc lựa chọn câu lệnh nên tuân theo các nguyên tắc sau:

1.  Khi trong quá trình lặp có một bước tăng cố định (thường gặp nhất là liệt kê), dùng câu lệnh for;
2.  Khi chỉ xác định điều kiện kết thúc vòng lặp, dùng câu lệnh while;
3.  Khi dùng câu lệnh while nhưng cần thực thi thân vòng lặp trước rồi mới kiểm tra điều kiện, dùng câu lệnh do...while. Loại này thường ít dùng, tình huống phổ biến là xử lý dữ liệu người dùng nhập vào.

## Câu lệnh break và continue

Tác dụng của câu lệnh break là thoát khỏi vòng lặp.

Tác dụng của câu lệnh continue là bỏ qua phần còn lại của thân vòng lặp. Dưới đây là ví dụ về cách dùng câu lệnh continue trong câu lệnh do...while:

```cpp
do {
  // làm gì đó...
  continue;  // tương đương với goto END;
// làm gì đó...
END:;
} while (statement);

```

Cả hai câu lệnh break và continue đều có thể được dùng trong thân vòng lặp của ba loại câu lệnh lặp.

Nói chung, câu lệnh break và continue được dùng để làm cho logic của mã nguồn rõ ràng hơn, ví dụ:

```cpp
// Logic chưa rõ ràng, các tầng dấu ngoặc nhọn phức tạp

for (int i = 1; i <= n; ++i) {
  if (i != x) {
    for (int j = 1; j <= n; ++j) {
      if (j != x) {
        // làm gì đó...
      }
    }
  }
}

// Logic rõ ràng hơn, các tầng dấu ngoặc nhọn đơn giản và dễ hiểu

for (int i = 1; i <= n; ++i) {
  if (i == x) continue;
  for (int j = 1; j <= n; ++j) {
    if (j == x) continue;
    // làm gì đó...
  }
}
```

```cpp
// Điều kiện kiểm tra của câu lệnh for phức tạp, không thể hiện bản chất "liệt kê"

for (int i = l; i <= r && i % 10 != 0; ++i) {
  // làm gì đó...
}

// Câu lệnh for dùng để liệt kê, break dùng để chỉ "dừng ở đâu"

for (int i = l; i <= r; ++i) {
  if (i % 10 == 0) break;
  // làm gì đó...
}
```

```cpp
// Câu lệnh bị lặp lại, thứ tự không tự nhiên

statement1;
while (statement3) {
  statement2;
  statement1;
}

// Không có câu lệnh lặp lại, thứ tự tự nhiên

while (1) {
  statement1;
  if (!statement3) break;
  statement2;
}
```
