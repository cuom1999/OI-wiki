## Về Java

Java là một ngôn ngữ lập trình máy tính được sử dụng rộng rãi, có các tính chất
**đa nền tảng**, **hướng đối tượng**, **lập trình tổng quát (generic)**, và được dùng phổ
biến trong phát triển ứng dụng Web cấp doanh nghiệp cũng như ứng dụng di động.

## Cài đặt môi trường

Xem [JDK](../tools/compiler.md#jdk).

## Cú pháp cơ bản

### Hàm chính

Tương tự C/C++, chương trình Java cần một hàm (trong hướng đối tượng gọi là
phương thức) làm điểm vào để bắt đầu thực thi.

Dạng hàm chính của Java là cố định, như sau:

```java
class Test {
    public static void main(String[] args) {
        // mã của chương trình
    }
}
```

Một chương trình Java đã đóng gói (thường có tên dạng `*.jar`) có thể có nhiều
phương thức tương tự, nhưng khi chạy chương trình, chỉ một phương thức trong số
đó được dùng làm điểm vào. Phương thức này được chỉ định trong tệp `Manifest` của
JAR; trong các kỳ thi OI thường không cần quan tâm đến phần này.

### Chú thích

Giống C/C++, Java dùng `//` và `/* */` lần lượt để chú thích một dòng và nhiều
dòng.

### Kiểu dữ liệu cơ bản

Java có tám kiểu nguyên thủy và một giá trị rỗng đặc biệt thường gặp:

| Tên | Ý nghĩa |
| :-: | :----- |
| `boolean` | kiểu luận lý |
| `byte` | số nguyên 8 bit có dấu |
| `char` | ký tự Unicode 16 bit |
| `double` | số thực dấu phẩy động độ chính xác kép |
| `float` | số thực dấu phẩy động độ chính xác đơn |
| `int` | số nguyên 32 bit có dấu |
| `long` | số nguyên 64 bit có dấu |
| `short` | số nguyên 16 bit có dấu |
| `null` | giá trị rỗng của kiểu tham chiếu, không phải kiểu nguyên thủy |

### Khai báo biến

```java
int a = 12;  // khai báo a là số nguyên và gán giá trị 12
String str = "Hello, OI-wiki";  // khai báo biến chuỗi str
char ch = 'W';
double PI = 3.1415926;
```

### Từ khóa final

Từ khóa `final` biểu thị rằng biến chỉ có thể được gán một lần; sau khi gán thì
không thể gán lại.

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
// Cách đơn giản nhất để tạo một biến chuỗi
String a = "Hello";

// Cũng có thể dùng mảng ký tự để tạo biến chuỗi
char[] stringArray = { 'H', 'e', 'l', 'l', 'o' };
String s = new String(stringArray);
```

### Gói và import gói

Các lớp (`class`) trong Java có thể được đặt trong các gói (`package`). Trong cùng
một gói không được có hai lớp trùng tên. Dòng đầu của tệp thường nêu lớp này
thuộc gói nào. Ví dụ:

```java
package org.oiwiki.tutorial;
```

Quy ước đặt tên gói thường là:
`tên_miền_cấp_cao_của_chủ_sở_hữu_dự_án.tên_miền_cấp_hai_của_chủ_sở_hữu_dự_án.tên_dự_án`.

Dùng từ khóa `import` để nhập lớp không nằm trong gói của lớp hiện tại. Ví
dụ, lớp `Scanner` được dùng bên dưới:

```java
import java.util.Scanner;
```

Nếu muốn nhập toàn bộ các lớp trong một gói, có thể thay tên lớp trước dấu chấm
phẩy cuối câu lệnh bằng `*`.

### Nhập dữ liệu

Có thể dùng lớp `Scanner` để đọc dữ liệu từ luồng nhập chuẩn.

```java
package org.oiwiki.tutorial;

import java.util.Scanner;

class Test {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // System.in là luồng nhập
        int a = scan.nextInt();
        double b = scan.nextDouble();
        String c = scan.next();
    }
}
```

### Xuất dữ liệu

Có thể xuất biến theo định dạng bằng `System.out.printf`.

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
            // thực thi đoạn mã này khi điều kiện đúng
        }
    }
}
```

-   if...else

```java
class Test {
    public static void main(String[] args) {
        if ( /* điều kiện */ ) {
            // thực thi đoạn mã này khi điều kiện đúng
        } else {
            // thực thi đoạn mã này khi điều kiện sai
        }
    }
}
```

-   if...else if...else

```java
class Test {
    public static void main(String[] args) {
        if ( /* điều kiện */ ) {
            // thực thi đoạn mã này khi điều kiện đúng
        } else if ( /* điều kiện 2 */ ) {
            // thực thi đoạn mã này khi điều kiện 2 đúng
        } else {
          // thực thi đoạn mã này khi các điều kiện trên đều sai
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
              // thực thi đoạn mã này khi biểu thức không khớp các giá trị nêu trên
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
mảng hoặc bộ chứa. Có thể xem như biến lặp trong cách trước đã được ẩn đi,
dạng như sau:

```java
class Test {
    public static void main(String[] args) {
        for ( /* kiểu phần tử X */ /* tên phần tử Y */ : /* bộ chứa Z */ ) {
            // mỗi lần lặp, phần tử Y lần lượt là một phần tử trong bộ chứa Z.
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

## Lưu ý

### Tên lớp và tên tệp phải nhất quán

Khi một lớp được khai báo là `public`, tên lớp và tên tệp nguồn Java phải trùng
nhau thì mới biên dịch được. Trong OJ, tên lớp hoặc tên tệp thường được quy định
cụ thể trong đề hoặc cấu hình ngôn ngữ.

Ví dụ:

`Add.java`

```java
public class Add {
    public static void main(String[] args) {
        // ...
    }
}
```

Vì lớp `Add` được khai báo là `public`, tệp nguồn tương ứng phải có tên
`Add.java`.
