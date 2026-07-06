author: Ir1d, cqnuljs, akakw1, MingqiHuang, Chrogeek, henrytbtrue, Planet6174, StudyingFather

## Khái niệm về tệp

Tệp là tập hợp dữ liệu có liên quan được gom lại theo một mục đích cụ thể. C/C++
xem mỗi tệp là một luồng byte có thứ tự; khi đọc đến cuối tệp, chương trình sẽ
gặp **dấu kết thúc tệp** (EOF). Muốn thao tác với một tệp, trước hết chương trình
phải mở tệp đó. Mỗi tệp đang mở được liên kết với một luồng, và luồng này biểu
diễn dãy byte của tệp. Sau khi sử dụng xong, cần đóng tệp đã mở.

C/C++ chia tệp thành tệp văn bản và tệp nhị phân. Tệp văn bản chứa nội dung dạng
văn bản thông thường (trọng tâm của phần này); còn tệp nhị phân là các tệp có
định dạng đặc biệt, tệp thực thi, v.v.

## Các bước thao tác với tệp

1.  Mở tệp, liên kết con trỏ tệp hoặc luồng tệp với tệp đó, rồi xác định chế độ
    mở.
2.  Thực hiện thao tác đọc, ghi trên tệp. Phần này chỉ đề cập đến các thao tác
    thường dùng trong thi đấu.
3.  Sau khi dùng xong, đóng tệp.

## Hàm `freopen`

### Giới thiệu hàm

Hàm này dùng để chuyển hướng một luồng nhập/xuất sang tệp theo chế độ mở đã cho.
Hàm nằm trong tệp tiêu đề `<cstdio>` (hoặc `<stdio.h>` trong C). Nó có thể thay
đổi nguồn nhập hoặc đích xuất mà không cần sửa cấu trúc chính của chương trình,
nhưng khi sử dụng cần kiểm tra thao tác mở tệp có thành công hay không.

Hàm chủ yếu có ba cách dùng: đọc, ghi và ghi nối thêm.

### Nguyên mẫu hàm

```cpp
FILE* freopen(const char* filename, const char* mode, FILE* stream);
```

### Giải thích tham số

-   `filename`: tên tệp cần mở
-   `mode`: chế độ mở, biểu thị cách đọc/ghi tệp
-   `stream`: con trỏ tệp, thường dùng luồng đầu vào/đầu ra chuẩn (`stdin`/`stdout`)
    hoặc luồng lỗi chuẩn (`stderr`)
-   Giá trị trả về: con trỏ tệp trỏ tới tệp đã được mở; nếu thất bại thì trả về
    `NULL`

### Các chế độ mở tệp (đọc thêm)

-   `r`: mở tệp ở chế độ chỉ đọc, tệp phải tồn tại, chỉ cho phép đọc dữ liệu
    **(thường dùng)**
-   `r+`: mở tệp ở chế độ đọc/ghi, tệp phải tồn tại, cho phép đọc/ghi dữ liệu
-   `rb`: mở tệp nhị phân ở chế độ chỉ đọc, tệp phải tồn tại, chỉ cho phép đọc
    dữ liệu
-   `rb+`: mở tệp nhị phân ở chế độ đọc/ghi, tệp phải tồn tại, cho phép đọc/ghi
    dữ liệu
-   `rt+`: mở tệp văn bản ở chế độ đọc/ghi, cho phép đọc/ghi dữ liệu
-   `w`: mở tệp ở chế độ chỉ ghi; nếu tệp không tồn tại thì tạo tệp mới, nếu đã
    tồn tại thì xóa sạch nội dung; chỉ cho phép ghi dữ liệu **(thường dùng)**
-   `w+`: mở tệp ở chế độ đọc/ghi; nếu tệp không tồn tại thì tạo tệp mới, nếu đã
    tồn tại thì xóa sạch nội dung; cho phép đọc/ghi dữ liệu
-   `wb`: mở tệp nhị phân ở chế độ chỉ ghi; nếu tệp không tồn tại thì tạo tệp
    mới, nếu đã tồn tại thì xóa sạch nội dung; chỉ cho phép ghi dữ liệu
-   `wb+`: mở tệp nhị phân ở chế độ đọc/ghi; nếu tệp không tồn tại thì tạo tệp
    mới, nếu đã tồn tại thì xóa sạch nội dung; cho phép đọc/ghi dữ liệu
-   `a`: mở tệp ở chế độ ghi nối thêm; nếu tệp không tồn tại thì tạo tệp mới; dữ
    liệu ghi vào sẽ được nối thêm ở cuối tệp
-   `a+`: mở tệp ở chế độ đọc/ghi nối thêm; nếu tệp không tồn tại thì tạo tệp
    mới; dữ liệu ghi vào sẽ được nối thêm ở cuối tệp
-   `at+`: mở tệp văn bản ở chế độ đọc/ghi nối thêm; dữ liệu ghi vào sẽ được nối
    thêm ở cuối tệp
-   `ab+`: mở tệp nhị phân ở chế độ đọc/ghi nối thêm; dữ liệu ghi vào sẽ được nối
    thêm ở cuối tệp

### Cách sử dụng

Chuyển hướng đầu vào chuẩn để đọc nội dung từ tệp:

```cpp
freopen("data.in", "r", stdin);
// data.in là tên tệp cần đọc, phải đặt cùng thư mục với tệp thực thi
```

Chuyển hướng đầu ra chuẩn để ghi nội dung ra tệp:

```cpp
freopen("data.out", "w", stdout);
// data.out là tên tệp đầu ra, nằm cùng thư mục với tệp thực thi
```

Đóng luồng đầu vào/đầu ra chuẩn sau khi dùng xong:

```cpp
fclose(stdin);
fclose(stdout);
```

??? note "Ghi chú"
    Các hàm và đối tượng như `printf`/`scanf`/`cin`/`cout` mặc định sử dụng
    `stdin`/`stdout`. Sau khi chuyển hướng `stdin`/`stdout`, chúng sẽ đọc/ghi
    qua tệp tương ứng.

### Mẫu

```cpp
#include <cstdio>
#include <iostream>

int main(void) {
  if (freopen("data.in", "r", stdin) == NULL) return 1;
  if (freopen("data.out", "w", stdout) == NULL) return 1;
  /*
  Phần mã ở giữa không cần thay đổi, vẫn có thể dùng std::cin và std::cout.
  */
  fclose(stdin);
  fclose(stdout);
  return 0;
}
```

## Hàm `fopen` (đọc thêm)

Hàm này mở tệp được chỉ định và trả về con trỏ tới tệp đã mở. Khác với
`freopen`, `fopen` không chuyển hướng `stdin` hoặc `stdout`; khi đọc/ghi tệp, cần
dùng con trỏ mà hàm trả về.

### Nguyên mẫu hàm

```cpp
FILE* fopen(const char* path, const char* mode);
```

Ý nghĩa các tham số giống như trong `freopen`.

### Các hàm đọc/ghi thường dùng (cơ bản)

-   `fread/fwrite`
-   `fgetc/fputc`
-   `fscanf/fprintf`
-   `fgets/fputs`

### Cách sử dụng

```cpp
#include <cstdio>

int main(void) {
  FILE *in, *out;  // định nghĩa con trỏ tệp
  in = fopen("data.in", "r");
  out = fopen("data.out", "w");
  if (in == NULL || out == NULL) {
    if (in != NULL) fclose(in);
    if (out != NULL) fclose(out);
    return 1;
  }
  /*
  Thực hiện đọc từ in và ghi vào out
  */
  fclose(in);
  fclose(out);
  return 0;
}
```

## Luồng nhập/xuất tệp `ifstream/ofstream` trong C++

### Cách sử dụng

Mở luồng nhập để đọc nội dung từ tệp:

```cpp
std::ifstream fin("data.in");
// data.in là đường dẫn tương đối hoặc tuyệt đối đến tệp cần đọc
```

Mở luồng xuất để ghi nội dung ra tệp:

```cpp
std::ofstream fout("data.out");
// data.out là đường dẫn tương đối hoặc tuyệt đối đến tệp đầu ra
```

Đóng luồng tệp sau khi dùng xong:

```cpp
fin.close();
fout.close();
```

### Mẫu

```cpp
#include <fstream>

std::ifstream fin("data.in");
std::ofstream fout("data.out");

int main(void) {
  if (!fin || !fout) return 1;
  /*
  Trong phần mã ở giữa, đổi std::cin thành fin và std::cout thành fout.
  */
  fin.close();
  fout.close();
  return 0;
}
```

## Tài liệu tham khảo

1.  Sách hướng dẫn Olympic Tin học
