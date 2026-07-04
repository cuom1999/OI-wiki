author: Ir1d, cqnuljs, akakw1, MingqiHuang, Chrogeek, henrytbtrue, Planet6174, StudyingFather

## Khái niệm về tệp

Tệp là tập hợp dữ liệu có liên quan được gom lại theo một mục đích cụ thể. C/C++ xem mỗi tệp là một luồng byte có thứ tự; mỗi tệp đều kết thúc bằng **dấu kết thúc tệp** (EOF). Nếu muốn thao tác với một tệp, trước hết chương trình phải mở tệp đó. Mỗi khi một tệp được mở (hãy nhớ đóng tệp đã mở), tệp ấy sẽ được liên kết với một luồng; luồng ở đây thực chất là một dãy byte.

C/C++ chia tệp thành tệp văn bản và tệp nhị phân. Tệp văn bản là các tệp văn bản đơn giản (trọng tâm của phần này); còn tệp nhị phân là các tệp có định dạng đặc biệt, tệp mã thực thi, v.v.

## Các bước thao tác với tệp

1. Mở tệp, trỏ con trỏ tệp tới tệp và xác định kiểu mở tệp;
2. Thực hiện thao tác đọc, ghi trên tệp (đây là các thao tác chủ yếu dùng trong thi đấu; các thao tác khác tạm thời không đề cập);
3. Sau khi dùng xong tệp, đóng tệp.

## Hàm `freopen`

### Giới thiệu hàm

Hàm này dùng để chuyển hướng luồng nhập/xuất được chỉ định sang tệp theo một chế độ chỉ định. Hàm nằm trong tệp tiêu đề `stdio.h (cstdio)`. Nó có thể thay đổi môi trường nhập/xuất mà không cần thay đổi cấu trúc ban đầu của mã, nhưng khi sử dụng cần bảo đảm luồng là đáng tin cậy.

Hàm chủ yếu có ba cách dùng: đọc, ghi và ghi nối thêm.

### Cú pháp lệnh

```cpp
FILE* freopen(const char* filename, const char* mode, FILE* stream);
```

### Giải thích tham số

-   `filename`: tên tệp cần mở
-   `mode`: chế độ mở tệp, biểu thị quyền truy cập tệp
-   `stream`: con trỏ tệp, thường dùng luồng tệp chuẩn (`stdin/stdout`) hoặc luồng lỗi chuẩn (`stderr`)
-   Giá trị trả về: con trỏ tệp, trỏ tới tệp đã được mở

### Các chế độ mở tệp (đọc thêm)

-   `r`: mở tệp ở chế độ chỉ đọc, tệp phải tồn tại, chỉ cho phép đọc dữ liệu **(thường dùng)**
-   `r+`: mở tệp ở chế độ đọc/ghi, tệp phải tồn tại, cho phép đọc/ghi dữ liệu
-   `rb`: mở tệp nhị phân ở chế độ chỉ đọc, tệp phải tồn tại, chỉ cho phép đọc dữ liệu
-   `rb+`: mở tệp nhị phân ở chế độ đọc/ghi, tệp phải tồn tại, cho phép đọc/ghi dữ liệu
-   `rt+`: mở tệp văn bản ở chế độ đọc/ghi, cho phép đọc/ghi dữ liệu
-   `w`: mở tệp ở chế độ chỉ ghi; nếu tệp không tồn tại thì tạo tệp mới, nếu không thì xóa sạch nội dung; chỉ cho phép ghi dữ liệu **(thường dùng)**
-   `w+`: mở tệp ở chế độ đọc/ghi; nếu tệp không tồn tại thì tạo tệp mới, nếu không thì xóa sạch nội dung; cho phép đọc/ghi dữ liệu
-   `wb`: mở tệp nhị phân ở chế độ chỉ ghi; nếu tệp không tồn tại thì tạo tệp mới, nếu không thì xóa sạch nội dung; chỉ cho phép ghi dữ liệu
-   `wb+`: mở tệp nhị phân ở chế độ đọc/ghi; nếu tệp không tồn tại thì tạo tệp mới, nếu không thì xóa sạch nội dung; cho phép đọc/ghi dữ liệu
-   `a`: mở tệp ở chế độ chỉ ghi; nếu tệp không tồn tại thì tạo tệp mới; dữ liệu ghi vào sẽ được nối thêm ở cuối tệp (giữ lại ký hiệu EOF)
-   `a+`: mở tệp ở chế độ đọc/ghi; nếu tệp không tồn tại thì tạo tệp mới; dữ liệu ghi vào sẽ được nối thêm ở cuối tệp (không giữ lại ký hiệu EOF)
-   `at+`: mở tệp văn bản ở chế độ đọc/ghi; dữ liệu ghi vào sẽ được nối thêm ở cuối tệp
-   `ab+`: mở tệp nhị phân ở chế độ đọc/ghi; dữ liệu ghi vào sẽ được nối thêm ở cuối tệp

### Cách sử dụng

Đọc nội dung từ tệp:

```cpp
freopen("data.in", "r", stdin);
// data.in là tên tệp cần đọc, phải đặt cùng thư mục với tệp thực thi
```

Xuất ra tệp:

```cpp
freopen("data.out", "w", stdout);
// data.out là tên tệp xuất, nằm cùng thư mục với tệp thực thi
```

Đóng luồng nhập/xuất chuẩn

```cpp
fclose(stdin);
fclose(stdout);
```

??? note "Ghi chú"
    Các hàm như `printf/scanf/cin/cout` mặc định sử dụng `stdin/stdout`. Sau khi chuyển hướng `stdin/stdout`, các hàm này sẽ nhập/xuất từ tệp được chuyển hướng.

### Mẫu

```cpp
#include <cstdio>
#include <iostream>

int main(void) {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  /*
  Phần mã ở giữa không cần thay đổi, có thể dùng trực tiếp cin và cout
  */
  fclose(stdin);
  fclose(stdout);
  return 0;
}
```

## Hàm `fopen` (đọc thêm)

Hàm này về cơ bản giống `freopen`: nó mở tệp được chỉ định và trả về con trỏ tới tệp đã mở.

### Nguyên mẫu hàm

```cpp
FILE* fopen(const char* path, const char* mode)
```

Ý nghĩa các tham số giống với `freopen`.

### Các hàm đọc/ghi có thể dùng (cơ bản)

-   `fread/fwrite`
-   `fgetc/fputc`
-   `fscanf/fprintf`
-   `fgets/fputs`

### Cách sử dụng

```cpp
FILE *in, *out;  // Định nghĩa con trỏ tệp
in = fopen("data.in", "r");
out = fopen("data.out", "w");
/*
Làm những gì bạn cần làm
*/
fclose(in);
fclose(out);
```

## Luồng nhập/xuất tệp `ifstream/ofstream` trong C++

### Cách sử dụng

Đọc nội dung từ tệp:

```cpp
ifstream fin("data.in");
// data.in là đường dẫn tương đối hoặc tuyệt đối của tệp cần đọc
```

Xuất ra tệp:

```cpp
ofstream fout("data.out");
// data.out là đường dẫn tương đối hoặc tuyệt đối của tệp xuất
```

Đóng luồng nhập/xuất chuẩn

```cpp
fin.close();
fout.close();
```

### Mẫu

```cpp
#include <fstream>
using namespace std;  // Cả hai kiểu đều nằm trong không gian tên std

ifstream fin("data.in");
ofstream fout("data.out");

int main(void) {
  /*
  Trong phần mã ở giữa, chỉ cần đổi cin thành fin và cout thành fout
  */
  fin.close();
  fout.close();
  return 0;
}
```

## Tài liệu tham khảo

1.  Sách hướng dẫn Olympic Tin học
