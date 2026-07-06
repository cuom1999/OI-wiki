Đôi khi cần thực hiện cùng một nhóm câu lệnh nhiều lần. Để không phải viết lặp
lại cùng một đoạn mã, có thể dùng vòng lặp.

Trong nhiều bài toán, số lần lặp chỉ được biết khi chương trình đang chạy, nên
không thể sao chép mã nguồn nhiều lần bằng tay mà cần dùng vòng lặp.

## Câu lệnh for

Sau đây là cấu trúc của câu lệnh `for`:

```cpp
for (khoi_tao; dieu_kien_kiem_tra; cap_nhat) {
  than_vong_lap;
}
```

Thứ tự thực thi:

![](images/for-loop.svg)

Ví dụ, đọc vào $n$ số:

```cpp
for (int i = 1; i <= n; ++i) {
  cin >> a[i];
}
```

Trong ba phần của câu lệnh `for`, bất kỳ phần nào cũng có thể được bỏ qua. Nếu
bỏ qua điều kiện kiểm tra thì tương đương với việc điều kiện luôn đúng.

## Câu lệnh while

Sau đây là cấu trúc của câu lệnh `while`:

```cpp
while (dieu_kien_kiem_tra) {
  than_vong_lap;
}
```

Thứ tự thực thi:

![](images/while-loop.svg)

Ví dụ, kiểm chứng giả thuyết $3x+1$:

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

Sau đây là cấu trúc của câu lệnh `do...while`:

```cpp
do {
  than_vong_lap;
} while (dieu_kien_kiem_tra);
```

Thứ tự thực thi:

![](images/do-while-loop.svg)

Khác với câu lệnh `while`, câu lệnh `do...while` thực thi thân vòng lặp trước
rồi mới kiểm tra điều kiện. Vì vậy, thân vòng lặp của `do...while` luôn được
thực thi ít nhất một lần.

Ví dụ, liệt kê các hoán vị:

```cpp
do {
  // Xử lý hoán vị hiện tại
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

Nếu trong `statement4` không có câu lệnh `continue` (xem phần sau), hai cách
viết này là tương đương, nhưng cách viết bằng `while` sau đây rất ít khi được
dùng để thay thế trực tiếp cho `for`.

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

Nếu trong `statement1` không có câu lệnh `continue`, hai cách viết này cũng
tương đương.

```cpp
while (1) {
  // Thân vòng lặp
}

for (;;) {
  // Thân vòng lặp
}
```

Hai cách viết này đều tạo vòng lặp vô hạn. Có thể dùng `break` (xem phần sau) để
thoát.

Ba loại câu lệnh lặp có thể thay thế lẫn nhau trong nhiều tình huống, nhưng nói
chung nên chọn theo các nguyên tắc sau:

1.  Khi quá trình lặp có biến đếm hoặc bước cập nhật xác định, ví dụ liệt kê một
    dãy chỉ số, dùng câu lệnh `for`;
2.  Khi chủ yếu chỉ biết điều kiện tiếp tục hoặc điều kiện kết thúc vòng lặp,
    dùng câu lệnh `while`;
3.  Khi cần thực thi thân vòng lặp trước rồi mới kiểm tra điều kiện, dùng câu
    lệnh `do...while`. Loại này thường ít dùng hơn; một tình huống phổ biến là
    xử lý dữ liệu nhập vào rồi mới quyết định có tiếp tục hay không.

## Câu lệnh break và continue

Tác dụng của câu lệnh `break` là thoát khỏi vòng lặp gần nhất đang chứa nó.

Tác dụng của câu lệnh `continue` là bỏ qua phần còn lại của thân vòng lặp và
chuyển sang bước tiếp theo của vòng lặp. Trong `for`, chương trình sẽ thực hiện
biểu thức cập nhật rồi kiểm tra điều kiện; trong `while` và `do...while`, chương
trình sẽ chuyển tới bước kiểm tra điều kiện. Sau đây là ví dụ minh họa vị trí
mà `continue` trong câu lệnh `do...while` sẽ nhảy tới:

```cpp
do {
  // Phần trước continue
  continue;  // tương đương với goto END;
  // Phần này bị bỏ qua
END:;
} while (statement);
```

Cả hai câu lệnh `break` và `continue` đều có thể được dùng trong thân vòng lặp
của ba loại câu lệnh lặp.

Thông thường, câu lệnh `break` và `continue` có thể làm logic của mã nguồn dễ theo
dõi hơn, ví dụ:

```cpp
// Logic khó theo dõi, các tầng dấu ngoặc nhọn phức tạp

for (int i = 1; i <= n; ++i) {
  if (i != x) {
    for (int j = 1; j <= n; ++j) {
      if (j != x) {
        // Xử lý cặp (i, j)
      }
    }
  }
}

// Logic dễ theo dõi hơn, các tầng dấu ngoặc nhọn đơn giản và dễ hiểu

for (int i = 1; i <= n; ++i) {
  if (i == x) continue;
  for (int j = 1; j <= n; ++j) {
    if (j == x) continue;
    // Xử lý cặp (i, j)
  }
}
```

```cpp
// Điều kiện kiểm tra của câu lệnh for phức tạp, không thể hiện rõ bản chất "liệt kê"

for (int i = l; i <= r && i % 10 != 0; ++i) {
  // Xử lý i
}

// Câu lệnh for dùng để liệt kê, break dùng để chỉ điểm dừng

for (int i = l; i <= r; ++i) {
  if (i % 10 == 0) break;
  // Xử lý i
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
