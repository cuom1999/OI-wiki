## Về Java

Java là một ngôn ngữ lập trình máy tính được sử dụng rộng rãi, có các đặc tính
**đa nền tảng**, **hướng đối tượng**, **lập trình generic**, và được dùng phổ
biến trong phát triển ứng dụng Web cấp doanh nghiệp cũng như ứng dụng di động.

## Cài đặt môi trường

Xem [JDK](../tools/compiler.md#jdk).

## Cú pháp cơ bản

### Hàm chính

Java tương tự C/C++: cần một hàm (trong hướng đối tượng gọi là phương thức) làm
điểm vào để chương trình bắt đầu thực thi.

Dạng hàm chính của Java là cố định, như sau:

```java
class Test {
    public static void main(String[] args) {
        // mã của chương trình
    }
}
```

Một chương trình Java đã đóng gói (tên thường là `*.jar`) có thể có nhiều hàm
tương tự, nhưng khi chạy chương trình, chỉ một hàm trong số đó được chạy. Hàm
này được định nghĩa trong tệp `Manifest` của `Jar`; trong các kỳ thi OI thường
không cần biết đến phần này.

### Chú thích

Giống C/C++, Java dùng `//` và `/* */` lần lượt để chú thích một dòng và nhiều
dòng.

### Kiểu dữ liệu cơ bản

| Tên kiểu | Ý nghĩa |
| :------: | :-----: |
| boolean | kiểu Boolean |
| byte | kiểu byte |
| char | kiểu ký tự |
| double | số thực dấu phẩy động độ chính xác kép |
| float | số thực dấu phẩy động độ chính xác đơn |
| int | kiểu số nguyên |
| long | kiểu số nguyên dài |
| short | kiểu số nguyên ngắn |
| null | giá trị rỗng |

### Khai báo biến

```java
int a = 12; // đặt a là kiểu số nguyên và gán giá trị 12 cho a
String str = "Hello, OI-wiki"; // khai báo biến chuỗi str
char ch = 'W';
double PI = 3.1415926;
```

### Từ khóa final

`final` có nghĩa là kết quả cuối cùng, không thể thay đổi. Biến được `final` sửa
đổi chỉ có thể được gán một lần; sau khi gán thì không thay đổi nữa.

```java
final double PI = 3.1415926;
```

### Mảng

```java
// Mảng số nguyên có mười phần tử
// Cú pháp: kiểu_dữ_liệu[] tên_biến = new kiểu_dữ_liệu[kích_thước_mảng]
int[] ary = new int[10];
```

### Chuỗi

-   Chuỗi là một lớp dựng sẵn của Java.

```java
// Cách đơn giản nhất để tạo một biến chuỗi như sau
String a = "Hello";

// Cũng có thể dùng mảng ký tự để tạo một biến chuỗi
char[] stringArray = { 'H', 'e', 'l', 'l', 'o' };
String s = new String(stringArray);
```

### Package và import package

Các lớp (`Class`) trong Java đều được đặt trong các package. Trong cùng một
package không được có hai lớp trùng tên. Dòng đầu của lớp thường nêu lớp này
thuộc package nào. Ví dụ:

```java
package org.oi-wiki.tutorial;
```

Quy ước đặt tên package thường là: `tên_miền_cấp_cao_của_chủ_sở_hữu_dự_án.tên_miền_cấp_hai_của_chủ_sở_hữu_dự_án.tên_dự_án`.

Dùng từ khóa `import` để nhập lớp không nằm trong package của lớp hiện tại. Ví
dụ, lớp `Scanner` được dùng bên dưới:

```java
import java.util.Scanner;
```

Nếu muốn nhập toàn bộ lớp dưới một package, chỉ cần thay tên lớp trước dấu chấm
phẩy cuối câu lệnh bằng `*`.

### Nhập dữ liệu

Có thể dùng lớp `Scanner` để xử lý dữ liệu nhập từ dòng lệnh.

```java
package org.oiwiki.tutorial;

import java.util.Scanner;

class Test {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // System.in là luồng nhập
        int a = scan.nextInt();
        double b = scan.nextDouble();
        String c = scan.nextLine();
    }
}
```

### Xuất dữ liệu

Có thể xuất biến theo định dạng.

| Ký hiệu | Ý nghĩa |
| :----: | :-----: |
| `%f` | kiểu số thực dấu phẩy động |
| `%s` | kiểu chuỗi |
| `%d` | kiểu số nguyên |
| `%c` | kiểu ký tự |

```java
class Test {
    public static void main(String[] args) {
        int a = 12;
        char b = 'A';
        double s = 3.14;
        String str = "Hello world";
        System.out.printf("%f\n", s);
        System.out.printf("%d\n", a);
        System.out.printf("%c\n", b);
        System.out.printf("%s\n", str);
    }
}
```

### Câu lệnh điều khiển

Các câu lệnh điều khiển luồng của Java về cơ bản giống C++.

#### Rẽ nhánh

-   if

```java
class Test {
    public static void main(String[] args) {
        if ( /* điều kiện */ ){
            // thực thi mã trong này khi điều kiện đúng
        }
    }
}
```

-   if...else

```java
class Test {
    public static void main(String[] args) {
        if ( /* điều kiện */ ) {
            // thực thi mã trong này khi điều kiện đúng
        } else {
            // thực thi mã trong này khi điều kiện sai
        }
    }
}
```

-   if...else if...else

```java
class Test {
    public static void main(String[] args) {
        if ( /* điều kiện */ ) {
            // thực thi mã trong này khi điều kiện đúng
        } else if ( /* điều kiện 2 */ ) {
            // thực thi mã trong này khi điều kiện 2 đúng
        } else {
          // thực thi mã trong này khi các điều kiện trên đều sai
        }
    }
}
```

-   switch...case

```java
class Test {
    public static void main(String[] args) {
        switch ( /* biểu thức */ ){
          case /* giá trị 1 */:
              // thực thi đoạn mã này khi giá trị của biểu thức khớp giá trị 1
              break; // nếu không thêm break, chương trình sẽ chạy tiếp tuần tự đến break
          case /* giá trị 2 */:
              // thực thi đoạn mã này khi giá trị của biểu thức khớp giá trị 2
              break;
          default:
              // thực thi mã trong này khi biểu thức không khớp các giá trị nêu trên
        }
    }
}
```

#### Vòng lặp

-   for

Từ khóa `for` có hai cách dùng. Cách thứ nhất là vòng lặp `for` thông thường, có
dạng như sau:

```java
class Test {
    public static void main(String[] args) {
        for ( /* khởi tạo */; /* điều kiện lặp */; /* bước thực hiện sau mỗi vòng */ ) {
            // thực thi thân vòng lặp khi điều kiện lặp đúng
        }
    }
}
```

Cách thứ hai giống cách dùng `foreach` của C++, dùng để lặp qua dữ liệu trong
mảng hoặc collection. Có thể xem như biến lặp trong cách trước đã được ẩn đi,
dạng như sau:

```java
class Test {
    public static void main(String[] args) {
        for ( /* kiểu phần tử X */ /* tên phần tử Y */ : /* collection Z */ ) {
            // mỗi lần lặp của khối lệnh này, phần tử Y lần lượt là một phần tử trong collection Z.
        }
    }
}
```

-   while

```java
class Test {
    public static void main(String[] args) {
        while ( /* điều kiện */ ) {
            // thực thi thân vòng lặp khi điều kiện đúng
        }
    }
}
```

-   do...while

```java
class Test {
    public static void main(String[] args) {
        do {
          // mã cần thực thi
        } while ( /* điều kiện lặp */ );
    }
}
```

## Chú ý

### Tên lớp và tên tệp phải nhất quán

Khi tạo chương trình nguồn Java, tên lớp và tên tệp phải nhất quán thì mới biên
dịch được; nếu không, trình biên dịch sẽ báo không tìm thấy lớp. Thông thường
tên tệp này sẽ được chỉ định trong từng OJ cụ thể.

Ví dụ:

`Add.java`

```java
class Add {
    public static void main(String[] args) {
        // ...
    }
}
```

Trong tệp này cần dùng `Add` làm tên lớp thì mới biên dịch được.
