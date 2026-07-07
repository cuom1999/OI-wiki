???+ warning "Lưu ý"
    Nội dung dưới đây được viết dựa trên Java JDK 8. Ở các phiên bản cao hơn có thể có một vài thay đổi.

<span id="nhập-xuất-nhanh-hơn"></span>
## Nhập xuất nhanh hơn

`Scanner` và `System.out.print` hoạt động tốt với dữ liệu nhỏ, nhưng khi xử lý dữ
liệu lớn chúng trở nên kém hiệu quả. Vì vậy cần dùng một số cách để tăng tốc IO.

<span id="dùng-kattio-stringtokenizer-để-nhập-dữ-liệu"></span>
### Dùng Kattio + StringTokenizer để nhập dữ liệu

Một cách phổ biến là dùng [Kattio.java](https://github.com/Kattis/kattio/blob/master/Kattio.java)
từ Kattis để cải thiện hiệu suất IO.[^ref1] Cách này gói `StringTokenizer` và
`PrintWriter` vào cùng một lớp để tiện sử dụng. Khi giải bài, nếu cuộc thi hoặc
hệ thống cho phép, có thể dùng trực tiếp mẫu này.

Dưới đây là mẫu IO cần đưa vào mã nguồn. Vì Kattio gốc của Kattis có một số chức
năng không thường dùng, mẫu dưới đây đã được điều chỉnh lại. Kattio gốc dùng
giấy phép MIT.

```java
class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;
    // IO chuẩn
    public Kattio() { this(System.in, System.out); }
    public Kattio(InputStream i, OutputStream o) {
        super(o);
        r = new BufferedReader(new InputStreamReader(i));
    }
    // IO tệp
    public Kattio(String intput, String output) throws IOException {
        super(output);
        r = new BufferedReader(new FileReader(intput));
    }
    // Trả về null khi không còn dữ liệu nhập
    public String next() {
        try {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(r.readLine());
            return st.nextToken();
        } catch (Exception e) {}
        return null;
    }
    public int nextInt() { return Integer.parseInt(next()); }
    public double nextDouble() { return Double.parseDouble(next()); }
    public long nextLong() { return Long.parseLong(next()); }
}
```

Đoạn mã dưới đây minh họa cách dùng Kattio:

```java
class Test {
    public static void main(String[] args) {
        Kattio io = new Kattio();
        // Nhập chuỗi
        String str = io.next();
        // Nhập int
        int num = io.nextInt();
        // Xuất
        io.println("Result");
        // Nhớ đóng luồng IO để bảo đảm dữ liệu xuất được ghi đúng
        io.close();
    }
}
```

<span id="dùng-streamtokenizer-để-nhập-dữ-liệu"></span>
### Dùng StreamTokenizer để nhập dữ liệu

Trong một số trường hợp, dùng `StringTokenizer` có thể gây MLE (Memory Limit Exceeded, vượt giới hạn bộ nhớ). Khi đó cần dùng `StreamTokenizer` để nhập dữ liệu.

```java
import java.io.*;
public class Main {
    // Mã IO
    public static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in), 32768));
    public static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static double nextDouble() throws IOException { in.nextToken(); return in.nval; }
    public static float nextFloat() throws IOException { in.nextToken(); return (float)in.nval; }
    public static int nextInt() throws IOException { in.nextToken(); return (int)in.nval; }
    public static String next() throws IOException { in.nextToken(); return in.sval; }
    public static long nextLong() throws Exception { in.nextToken(); return (long)in.nval;}
    
    // Ví dụ sử dụng
    public static void main(String[] args) throws Exception {
        int n = nextInt();
        out.println(n);
        out.close();
    }
}
```

<span id="phân-tích-và-so-sánh-kattio-stringtokenizer-với-streamtokenizer"></span>
### Phân tích và so sánh Kattio + StringTokenizer với StreamTokenizer

1.  `StreamTokenizer` dùng ít bộ nhớ hơn `StringTokenizer`. Khi chương trình
    chuẩn Java bị MLE, có thể thử `StreamTokenizer`, nhưng `StreamTokenizer` có
    thể làm mất độ chính xác và gặp lỗi khi đọc một số kiểu dữ liệu.
    -   Trong mã nguồn của `StreamTokenizer` có `Type`; `Type` này quyết định
        kiểu dựa trên nội dung đầu vào. Nếu nhập một chuỗi bắt đầu bằng chữ số
        như `123oi`, nó sẽ cưỡng ép coi kiểu là `double`, nên khi đọc dữ liệu
        kiểu `String` bằng kiểu `double` sẽ phát sinh ngoại lệ.
    -   `StreamTokenizer` sẽ mất độ chính xác khi đọc các số có độ lớn từ `1e14` trở lên.
2.  Khi dùng `PrintWriter`, cần lưu ý gọi `close()` để đóng luồng xuất ở cuối
    chương trình, hoặc gọi `flush()` khi cần xuất ngay bộ đệm; nếu không nội dung
    sẽ không được ghi ra console hoặc tệp.
3.  `Kattio` kế thừa từ `PrintWriter`, nên đối tượng của nó có sẵn chức năng của
    `PrintWriter` và có thể gọi trực tiếp các hàm xuất của `PrintWriter`; đồng
    thời nó dùng `StringTokenizer` làm biến thành viên. Cách thứ hai trong lớp
    `Main` lại dùng `StreamTokenizer` và `PrintWriter` làm biến thành viên riêng,
    nên cách gọi hàm nhập và xuất khác với `Kattio`.

Tóm lại, trong đa số trường hợp `StringTokenizer` thuận tiện hơn
`StreamTokenizer`. Chỉ nên thử `StreamTokenizer` trong các trường hợp MLE cực
đoan; ngoài ra, `StreamTokenizer` không xử lý tốt dữ liệu vượt phạm vi `int`.

<span id="biginteger-và-số-học"></span>
## BigInteger và số học

`BigInteger` là lớp tính toán độ chính xác cao do Java cung cấp, hữu ích khi
giải các bài toán số lớn.

<span id="biginteger-khởi-tạo"></span>
### Khởi tạo

Có hai cách tạo `BigInteger` thường dùng:

```java
import java.io.PrintWriter;
import java.math.BigInteger;

class Main {
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) {
        BigInteger a = new BigInteger("12345678910");  // Tạo đối tượng BigInteger từ chuỗi ở hệ thập phân
        out.println(a);  // Giá trị của a là 12345678910
        BigInteger b = new BigInteger("1E", 16);  // Tạo đối tượng BigInteger từ chuỗi ở hệ cơ số được chỉ định
        out.println(b);  // Giá trị của b là 30
        out.close();
    }
}

```

<span id="biginteger-phép-toán-cơ-bản"></span>
### Phép toán cơ bản

Dưới đây dùng `this` để chỉ `BigInteger` hiện tại:

|             Tên hàm             |                         Chức năng                         |
| :-----------------------------: | :--------------------------------------------------------: |
|             `abs()`             |              Trả về giá trị tuyệt đối của `this`           |
|           `negate()`            |              Trả về số đối của `this`                      |
|      `add(BigInteger val)`      |              Trả về tổng của `this` và `val`               |
|   `subtract(BigInteger val)`    |              Trả về hiệu của `this` và `val`               |
|   `multiply(BigInteger val)`    |              Trả về tích của `this` và `val`               |
|    `divide(BigInteger val)`     |              Trả về thương của `this` và `val`             |
|  `remainder(BigInteger val)`    |              Trả về phần dư khi `this` chia cho `val`      |
|      `mod(BigInteger val)`      |              Trả về `this` modulo `val`                    |
|          `pow(int val)`         |              Trả về `this` mũ `val`                        |
|      `and(BigInteger val)`      |              Trả về phép AND bit của `this` và `val`       |
|       `or(BigInteger val)`      |              Trả về phép OR bit của `this` và `val`        |
|             `not()`             |              Trả về phép NOT bit của `this`                |
|      `xor(BigInteger val)`      |              Trả về phép XOR bit của `this` và `val`       |
|        `shiftLeft(int n)`       |              Trả về `this` dịch trái `n` bit               |
|       `shiftRight(int n)`       |              Trả về `this` dịch phải `n` bit               |
|      `max(BigInteger val)`      |              Trả về giá trị lớn hơn giữa `this` và `val`   |
|      `min(BigInteger val)`      |              Trả về giá trị nhỏ hơn giữa `this` và `val`   |
|          `bitCount()`           | Trả về số bit `1` trong biểu diễn nhị phân của `this`, không tính bit dấu |
|         `bitLength()`           | Trả về độ dài biểu diễn nhị phân của `this`, không tính bit dấu |
|       `getLowestSetBit()`       |              Trả về vị trí bit `1` thấp nhất của `this`    |
|   `compareTo(BigInteger val)`   |              So sánh giá trị của `this` và `val`           |
|          `toString()`           |              Trả về biểu diễn chuỗi thập phân của `this`   |
|      `toString(int radix)`      |              Trả về biểu diễn chuỗi của `this` ở hệ `radix` |

Ví dụ sử dụng:

```java
import java.io.PrintWriter;
import java.math.BigInteger;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static BigInteger a, b;
    
    static void abs() {
        out.println("abs:");
        a = new BigInteger("-123");
        out.println(a.abs());  // In ra 123
        a = new BigInteger("123");
        out.println(a.abs());  // In ra 123
    }
    
    static void negate() {
        out.println("negate:");
        a = new BigInteger("-123");
        out.println(a.negate());  // In ra 123
        a = new BigInteger("123");
        out.println(a.negate());  // In ra -123
    }
    
    static void add() {
        out.println("add:");
        a = new BigInteger("123");
        b = new BigInteger("123");
        out.println(a.add(b));  // In ra 246
    }
    
    static void subtract() {
        out.println("subtract:");
        a = new BigInteger("123");
        b = new BigInteger("123");
        out.println(a.subtract(b));  // In ra 0
    }
    
    static void multiply() {
        out.println("multiply:");
        a = new BigInteger("12");
        b = new BigInteger("12");
        out.println(a.multiply(b));  // In ra 144
    }
    
    static void divide() {
        out.println("divide:");
        a = new BigInteger("12");
        b = new BigInteger("11");
        out.println(a.divide(b));  // In ra 1
    }
    
    static void remainder() {
        out.println("remainder:");
        a = new BigInteger("12");
        b = new BigInteger("10");
        out.println(a.remainder(b));  // In ra 2
        a = new BigInteger("-12");
        b = new BigInteger("10");
        out.println(a.remainder(b));  // In ra -2
    }
    
    static void mod() {
        out.println("mod:");
        a = new BigInteger("12");
        b = new BigInteger("10");
        out.println(a.mod(b));  // In ra 2
        a = new BigInteger("-12");
        b = new BigInteger("10");
        out.println(a.mod(b));  // In ra 8
    }
    
    static void pow() {
        out.println("pow:");
        a = new BigInteger("2");
        out.println(a.pow(10));  // In ra 1024
    }
    
    static void and() {
        out.println("and:");
        a = new BigInteger("3");  // 11
        b = new BigInteger("5");  // 101
        out.println(a.and(b));  // In ra 1
    }
    
    static void or() {
        out.println("or:");
        a = new BigInteger("2");  // 10
        b = new BigInteger("5");  // 101
        out.println(a.or(b));  // In ra 7
    }
    
    static void not() {
        out.println("not:");
        a = new BigInteger("2147483647");  // 01111111 11111111 11111111 11111111
        out.println(a.not());  // In ra -2147483648, nhị phân là: 10000000 00000000 00000000 00000000
    }
    
    static void xor() {
        out.println("xor:");
        a = new BigInteger("6");  // 110
        b = new BigInteger("5");  // 101
        out.println(a.xor(b));  // 011, in ra 3
    }
    
    static void shiftLeft() {
        out.println("shiftLeft:");
        a = new BigInteger("1");
        out.println(a.shiftLeft(10));  // In ra 1024
    }
    
    static void shiftRight() {
        out.println("shiftRight:");
        a = new BigInteger("1024");
        out.println(a.shiftRight(8));  // In ra 4
    }
    
    static void max() {
        out.println("max:");
        a = new BigInteger("6");
        b = new BigInteger("5");
        out.println(a.max(b));  // In ra 6
    }
    
    static void min() {
        out.println("min:");
        a = new BigInteger("6");
        b = new BigInteger("5");
        out.println(a.min(b));  // In ra 5
    }
    
    static void bitCount() {
        out.println("bitCount:");
        a = new BigInteger("6");  // 110
        out.println(a.bitCount());  // In ra 2
    }
    
    static void bitLength() {
        out.println("bitLength:");
        a = new BigInteger("6");  // 110
        out.println(a.bitLength());  // In ra 3
    }
    
    static void getLowestSetBit() {
        out.println("getLowestSetBit:");
        a = new BigInteger("8");  // 1000
        out.println(a.getLowestSetBit());  // In ra 3
    }
    
    static void compareTo() {
        out.println("compareTo:");
        a = new BigInteger("8");
        b = new BigInteger("9");
        out.println(a.compareTo(b));  // In ra -1
        a = new BigInteger("8");
        b = new BigInteger("8");
        out.println(a.compareTo(b));  // In ra 0
        a = new BigInteger("8");
        b = new BigInteger("7");
        out.println(a.compareTo(b));  // In ra 1
    }
    
    static void toStringTest() {
        out.println("toString:");
        a = new BigInteger("15");
        out.println(a.toString());  // In ra 15
        out.println(a.toString(16));  // In ra f
    }
    
    public static void main(String[] args) {
        abs();
        negate();
        add();
        subtract();
        multiply();
        divide();
        remainder();
        mod();
        pow();
        and();
        or();
        not();
        xor();
        shiftLeft();
        shiftRight();
        max();
        min();
        bitCount();
        bitLength();
        getLowestSetBit();
        compareTo();
        toStringTest();
        out.close();
    }
}
```

<span id="biginteger-phép-toán-toán-học"></span>
### Phép toán toán học

Dưới đây dùng `this` để chỉ `BigInteger` hiện tại:

|                  Tên hàm                 |                            Chức năng                            |
| :--------------------------------------: | :--------------------------------------------------------------: |
|           `gcd(BigInteger val)`          | Trả về ước chung lớn nhất của giá trị tuyệt đối của `this` và `val` |
|        `isProbablePrime(int val)`        | Trả về giá trị boolean biểu thị `this` có phải số nguyên tố hay không |
|           `nextProbablePrime()`          | Trả về số nguyên tố đầu tiên lớn hơn `this`                      |
|   `modPow(BigInteger b, BigInteger p)`   | Trả về `this` mũ `b` modulo `p`                                  |
|        `modInverse(BigInteger p)`        | Trả về nghịch đảo nhân của `this` theo môđun `p`                |

Ví dụ sử dụng:

```java
import java.io.PrintWriter;
import java.math.BigInteger;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static BigInteger a, b, p;
    
    static void gcd() {  // Ước chung lớn nhất
        a = new BigInteger("120032414321432144212100");
        b = new BigInteger("240231431243123412432140");
        out.println(String.format("gcd(%s,%s)=%s", a.toString(), b.toString(), a.gcd(b).toString()));  // gcd(120032414321432144212100,240231431243123412432140)=20
    }
    
    static void isPrime() {  // Dùng Miller-Rabin để kiểm tra số nguyên tố; tham số càng lớn càng chính xác nhưng độ phức tạp càng cao. Độ chính xác là (1-1/(val*2))
        a = new BigInteger("1200324143214321442127");
        out.println("a:" + a.toString());
        out.println(a.isProbablePrime(10) ? "a is prime" : "a is not prime");  // a is not prime
    }
    
    static void nextPrime() {  // Tìm số nguyên tố kế tiếp của số này
        a = new BigInteger("1200324143214321442127");
        out.println("a:" + a.toString());
        out.println(String.format("a nextPrime is %s", a.nextProbablePrime().toString()));  // a nextPrime is 1200324143214321442199
    }
    
    static void modPow() {  // Lũy thừa nhanh, nhanh hơn phiên bản thông thường vì có tối ưu toán học bên trong
        a = new BigInteger("2");
        b = new BigInteger("10");
        p = new BigInteger("1000");
        out.println(String.format("a:%s b:%s p:%s", a, b, p));
        out.println(String.format("a^b mod p:%s", a.modPow(b, p).toString()));//  24
    }
    
    static void modInverse() {  // Nghịch đảo
        a = new BigInteger("10");
        b = new BigInteger("3");
        out.println(a.modInverse(b));  // a ^ (p-2) mod p = 1
    }
    
    public static void main(String[] args) {
        gcd();
        isPrime();
        nextPrime();
        modPow();
        modInverse();
        out.close();
    }
}
```

Có thể xem thêm kiến thức liên quan đến Miller-Rabin tại [kiểm tra tính nguyên tố
Miller-Rabin](../math/number-theory/prime.md#kiểm-tra-tính-nguyên-tố-miller-rabin).

<span id="kiểu-dữ-liệu-nguyên-thủy-và-kiểu-bao"></span>
## Kiểu dữ liệu nguyên thủy và kiểu bao

<span id="kiểu-bao-giới-thiệu"></span>
### Giới thiệu

Vì kiểu nguyên thủy không có đặc trưng hướng đối tượng, để chúng tham gia vào lập
trình hướng đối tượng, Java cung cấp các lớp bao tương ứng cho tám kiểu nguyên
thủy: `Byte`, `Double`, `Float`, `Integer`, `Long`, `Short`, `Character` và
`Boolean`. Quan hệ tương ứng như sau:

| Kiểu dữ liệu nguyên thủy | Kiểu dữ liệu bao |
| :---------------------: | :--------------: |
|         `byte`          |      `Byte`      |
|        `short`          |     `Short`      |
|       `boolean`         |    `Boolean`     |
|         `char`          |   `Character`    |
|         `int`           |    `Integer`     |
|         `long`          |      `Long`      |
|        `float`          |     `Float`      |
|       `double`          |     `Double`     |

<span id="kiểu-bao-khác-biệt"></span>
### Khác biệt

Phần này lấy `int` và `Integer` làm ví dụ:

1.  `Integer` là lớp bao của `int`, còn `int` là kiểu dữ liệu nguyên thủy của Java.
2.  Giá trị kiểu `Integer` là một đối tượng; giá trị kiểu `int` thì không cần tạo
    đối tượng.
3.  Biến kiểu `Integer` lưu tham chiếu đến đối tượng. Khi gọi `new Integer(...)`,
    thực tế là tạo một đối tượng; còn `int` lưu trực tiếp dữ liệu.
4.  Giá trị mặc định của `Integer` là `null`, có thể nhận `null` hoặc một giá trị
    `int`; giá trị mặc định của `int` là 0 và không thể nhận `null`.
5.  Với `Integer`, dùng `==` để so sánh hai biến có thể cho kết quả sai; nên dùng
    `equals()`. Với `int`, có thể dùng trực tiếp `==`.

<span id="boxing-và-unboxing"></span>
### Đóng hộp và mở hộp

Phần này lấy `int` và `Integer` làm ví dụ:

Bản chất của `Integer` là đối tượng, còn `int` là kiểu nguyên thủy, nên không thể
gán trực tiếp giữa hai kiểu nếu không có bước chuyển đổi. Chuyển từ kiểu nguyên
thủy sang kiểu bao gọi là đóng hộp (boxing); chiều ngược lại gọi là mở hộp
(unboxing).

```java
// Kiểu nguyên thủy
int value1 = 1;
// Đóng hộp: chuyển sang kiểu bao
Integer integer = Integer.valueOf(value1);
// Mở hộp: chuyển về kiểu nguyên thủy
int value2 = integer.intValue();
```

Java 5 đưa vào cơ chế tự động đóng hộp (autoboxing) và tự động mở hộp (auto-unboxing):

```java
Integer integer = 1;
int value = integer;
```

???+ warning "Lưu ý"
    Dù JDK đã thêm cơ chế tự động đóng hộp và tự động mở hộp, vẫn cần chọn kiểu
    phù hợp khi khai báo biến. Kiểu bao `Integer` có thể nhận `null`, còn kiểu
    nguyên thủy `int` thì không. Vì vậy, khi mở hộp một kiểu bao đang có giá trị
    `null`, chương trình sẽ ném ngoại lệ. Đoạn mã sau minh họa hành vi này.
    
    ```java
    Integer integer = Integer.valueOf(null);
    integer.intValue();  // Ném ngoại lệ java.lang.NumberFormatException
    
    Integer integer = null;
    integer.intValue();  // Ném ngoại lệ java.lang.NullPointerException
    ```

<span id="kế-thừa"></span>
## Kế thừa

Trong lập trình hướng đối tượng, kế thừa cho phép tạo một lớp mới dựa trên một
lớp đã có. Lớp mới tự động nhận các thành viên của lớp cơ sở, gồm biến thành viên
và phương thức, với các mức truy cập khác nhau như `public`, `protected` hay
`private`. Nhờ đó, định nghĩa lớp mới bằng kế thừa thường nhanh và gọn hơn viết
lại từ đầu. Đây là một trong những cơ chế quan trọng để tái sử dụng mã.

Trong Java, từ khóa dùng cho kế thừa lớp là `extends`. Java chỉ hỗ trợ đơn kế
thừa lớp, nhưng một lớp có thể triển khai nhiều giao diện.

Trong Java, mọi lớp đều là lớp con của lớp `Object`.

Lớp con kế thừa lớp cha; mọi thành viên của lớp cha, gồm biến và phương thức, đều
trở thành thành viên của lớp con, ngoại trừ constructor. Constructor thuộc riêng
lớp cha vì tên của chúng chính là tên lớp, nên constructor của lớp cha không tồn
tại trong lớp con. Ngoài điểm này, lớp con nhận được tất cả thành viên của lớp
cha.

Mỗi thành viên có một mức truy cập riêng. Lớp con kế thừa mọi thành viên của lớp
cha, nhưng mức truy cập quyết định lớp con có thể dùng chúng như thế nào: một số
thành viên trở thành giao diện công khai của lớp con, còn một số thành viên bị ẩn
đến mức ngay cả lớp con cũng không thể truy cập.

Bảng dưới đây liệt kê mức truy cập của các thành viên lớp cha khi ở trong lớp con:

| Mức truy cập thành viên lớp cha | Ý nghĩa trong lớp cha | Ý nghĩa trong lớp con |
| :----------------------------: | :-------------------: | :-------------------: |
|            `public`            | Mở cho mọi lớp | Mở cho mọi lớp |
|          `protected`           | Chỉ các lớp cùng gói, chính nó và lớp con được truy cập | Chỉ các lớp cùng gói, chính nó và lớp con được truy cập |
| Mặc định (`default`) | Chỉ các lớp cùng gói được truy cập | Nếu lớp con và lớp cha cùng gói thì chỉ các lớp cùng gói được truy cập; nếu không thì tương đương `private`, không thể truy cập |
|           `private`            | Chỉ chính nó được truy cập | Không thể truy cập |

<span id="đa-hình"></span>
## Đa hình

Trong Java, khi gán một đối tượng cho một biến, kiểu của đối tượng phải tương
thích với kiểu của biến. Nhờ kế thừa, quy tắc này có thể mở rộng thành: **một
biến có thể lưu đối tượng thuộc kiểu khai báo của nó hoặc bất kỳ kiểu con nào của
kiểu đó**.

Nếu một kiểu triển khai một giao diện, nó cũng có thể được xem là kiểu con của
giao diện đó.

Biến lưu đối tượng trong Java có tính đa hình. Nói cách khác, một biến có thể lưu
đối tượng thuộc nhiều kiểu khác nhau: kiểu khai báo của biến hoặc bất kỳ kiểu con
nào của kiểu đó.

Biến đa hình:

1.  Biến đối tượng trong Java là đa hình; chúng có thể lưu đối tượng thuộc nhiều hơn một kiểu.
2.  Chúng có thể lưu đối tượng thuộc kiểu khai báo, hoặc đối tượng thuộc lớp con của kiểu khai báo.
3.  Khi gán đối tượng của lớp con cho biến của lớp cha, upcasting xảy ra.

<span id="generics"></span>
## Kiểu tổng quát (generic, kiểu tham số hóa)

Kiểu tổng quát (generic) nghĩa là khi định nghĩa lớp, ta không cố định kiểu cụ
thể của thuộc tính hoặc tham số phương thức, mà chỉ xác định kiểu khi sử dụng lớp
hoặc tạo đối tượng. Bản chất của generic là kiểu tham số hóa: kiểu dữ liệu được
thao tác được truyền vào như một tham số.

Generic cung cấp cơ chế kiểm tra an toàn kiểu tại thời điểm biên dịch, nhờ đó
phát hiện được kiểu không hợp lệ trước khi chạy chương trình.

<span id="interface"></span>
## Giao diện (interface)

<span id="interface-giới-thiệu"></span>
### Giới thiệu

Giao diện (interface) trong Java là một kiểu trừu tượng, thường được khai báo
bằng từ khóa `interface`. Nó mô tả một tập phương thức mà lớp triển khai giao diện
phải cung cấp.

Giao diện không phải là lớp. Cú pháp của giao diện khá giống lớp, nhưng hai khái
niệm này khác nhau: lớp mô tả thuộc tính và phương thức của đối tượng, còn giao
diện mô tả các phương thức mà lớp phải triển khai.

Trừ khi là lớp trừu tượng, một lớp triển khai giao diện phải định nghĩa tất cả
phương thức trong giao diện đó.

Giao diện không thể được khởi tạo trực tiếp, nhưng có thể được triển khai bởi lớp
khác. Một lớp triển khai giao diện phải định nghĩa mọi phương thức được mô tả
trong giao diện, nếu không thì phải khai báo là lớp trừu tượng. Ngoài ra, trong
Java, kiểu giao diện có thể dùng để khai báo biến; biến đó có thể là `null` hoặc
tham chiếu tới một đối tượng triển khai giao diện này.

<span id="khác-biệt-với-lớp"></span>
### Khác biệt với lớp

1.  Giao diện không thể dùng để khởi tạo đối tượng.
2.  Giao diện không có constructor.
3.  Theo mặc định, phương thức trong giao diện là phương thức trừu tượng; từ Java
    8, giao diện có thể có phương thức không trừu tượng với từ khóa `default`.
4.  Giao diện không thể chứa biến thành viên, ngoại trừ biến `static` và `final`.
5.  Giao diện không được lớp kế thừa, mà được lớp triển khai.
6.  Giao diện hỗ trợ đa kế thừa, còn lớp thì không.

<span id="khai-báo-interface"></span>
### Khai báo

```java
[pham_vi_hien_thi] interface TenInterface [extends InterfaceKhac] {
        // Khai báo biến
        // Phương thức trừu tượng
}
```

<span id="hiện-thực-interface"></span>
### Triển khai

```java
...implements TenInterface[, TenInterfaceKhac, TenInterfaceKhac..., ...] ...
```

<span id="biểu-thức-lambda"></span>
## Biểu thức lambda

<span id="lambda-giới-thiệu"></span>
### Giới thiệu

Biểu thức lambda cũng có thể được xem như một dạng closure; đây là một trong những
tính năng mới quan trọng nhất của Java 8.

Biểu thức lambda cho phép truyền hành vi vào phương thức như một đối số.

Dùng biểu thức lambda có thể làm mã ngắn gọn và rõ ý hơn.

<span id="cú-pháp-lambda"></span>
### Cú pháp

-   Khai báo kiểu tùy chọn: không cần khai báo kiểu tham số nếu trình biên dịch
    có thể suy luận từ ngữ cảnh.
-   Dấu ngoặc tròn tham số tùy chọn: một tham số không cần ngoặc tròn, nhưng nhiều tham số thì cần.
-   Dấu ngoặc nhọn tùy chọn: nếu thân chỉ chứa một câu lệnh thì không cần dùng ngoặc nhọn.
-   Từ khóa trả về tùy chọn: nếu thân chỉ có một biểu thức trả về giá trị, trình
    biên dịch sẽ tự động trả về; nếu dùng ngoặc nhọn thì cần viết rõ câu lệnh
    `return`.

Cách khai báo biểu thức lambda như sau:

```java
// 1. Không cần tham số, trả về 5
() -> 5

// 2. Nhận một tham số kiểu số, trả về giá trị gấp 2 lần
x -> 2 * x

// 3. Nhận 2 tham số kiểu số và trả về hiệu của chúng
(x, y) -> x - y

// 4. Nhận 2 số nguyên kiểu int và trả về tổng của chúng
(int x, int y) -> x + y

// 5. Nhận một đối tượng String và in ra console, không trả về giá trị nào
(String s) -> System.out.print(s)
```

Lấy ví dụ comparator tùy chỉnh để sắp xếp mảng chuỗi theo độ dài, biểu thức lambda có thể được áp dụng như sau.

```java
import java.util.Arrays;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void main(String[] args) {
        String[] plants = {"Mercury", "venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
        Arrays.sort(plants, (String first, String second) -> (first.length() - second.length()));
        for (String word : plants) {
            out.print(word + " ");
        }
        out.close();
    }
}
```

Cũng có thể dùng nhiều câu lệnh trong biểu thức lambda như ví dụ dưới đây.

```java
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void main(String[] args) {
        String[] plants = {"Mercury", "venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
        Arrays.sort(plants, (first, second) ->
        {
            // Không viết kiểu tham số; có thể suy luận từ ngữ cảnh
            int result = first.length() - second.length();
            return result;
        });
        for (String word : plants) {
            out.print(word + " ");
        }
        out.close();
    }
}
```

Trong đó, `->` là ký hiệu của lambda: phần bên trái nhận tham số, phần bên phải
mô tả biểu thức hoặc khối lệnh sẽ thực thi.

<span id="functional-interface"></span>
### Giao diện hàm (functional interface)

1.  Là một giao diện, phù hợp với định nghĩa giao diện của Java.
2.  Chỉ chứa một phương thức trừu tượng.
3.  Vì chỉ có một phương thức trừu tượng, biểu thức lambda có thể cung cấp phần
    triển khai cho phương thức đó.

Cách dùng giao diện hàm như sau:

???+ example "Xuất các chuỗi có độ dài là bội số của 2"
    ```java
    import java.io.PrintWriter;
    
    public class Main {
        static PrintWriter out = new PrintWriter(System.out);
        
        public static void main(String[] args) {
            String[] plants = {"Mercury", "venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
            Test test = s -> {  // Biểu thức lambda làm thực thể của giao diện hàm
                if (s.length() % 2 == 0) {
                    return true;
                }
                return false;
            };
            for (String word : plants) {
                if (test.check(word)) {
                    out.print(word + " ");
                }
            }
            out.close();
        }
    }
    
    interface Test {
        public boolean check(String s);
    }
    ```

???+ example "Hiện thực bốn phép toán cộng, trừ, nhân, chia"
    ```java
    import java.io.PrintWriter;
    
    public class Main {
        static PrintWriter out = new PrintWriter(System.out);
        
        public static double calc(double a, double b, Calculator util) {
            return util.operation(a, b);
        }
        
        public static void main(String[] args) {
            Calculator util[] = new Calculator[4];  // Định nghĩa mảng giao diện hàm
            util[0] = (a, b) -> a + b;
            util[1] = (a, b) -> a - b;
            util[2] = (a, b) -> a * b;
            util[3] = (a, b) -> a / b;
            double a = 20, b = 15;
            for (Calculator c : util) {
                System.out.println(calc(a, b, c));
            }
            out.close();
        }
    }
    
    interface Calculator {
        public double operation(double a, double b);
    }
    ```

## Tập hợp

`Collection` là giao diện trong Java, được nhiều giao diện bộ chứa tổng quát kế
thừa. Trong phần này, `Collection` chỉ các cấu trúc dữ liệu dùng để lưu kiểu đối
tượng.

Trong Java, kiểu phần tử của `Collection` phải là kiểu đối tượng, không thể là
kiểu dữ liệu nguyên thủy.

Các nội dung dưới đây đều dựa trên tính đa hình của Java và được thể hiện thông
qua các lớp triển khai giao diện.

Các giao diện thường dùng gồm `List`, `Queue`, `Set` và `Map`.

<span id="định-nghĩa-container"></span>
### Định nghĩa bộ chứa

Khi định nghĩa bộ chứa generic, cần chỉ định kiểu dữ liệu ngay lúc khai báo. Nếu
không chỉ định kiểu, Java sẽ xem đó là kiểu thô dựa trên `Object`; khi thêm dữ
liệu tùy ý, Java 8 vẫn có thể biên dịch nhưng sẽ sinh nhiều cảnh báo và rủi ro.

Ví dụ, cách định nghĩa dưới đây là an toàn; bộ chứa chỉ nhận kiểu `Integer`.

```java
List<Integer> list1 = new LinkedList<>();
```

Còn cách định nghĩa dưới đây sẽ sinh cảnh báo.

```java
List list = new ArrayList<>();
list.add(1);
list.add(true);
list.add(1.01);
list.add(1L);
list.add("I am String");
```

Vì vậy, nếu không có nhu cầu đặc biệt thì không nên dùng cách thứ hai. Trình biên
dịch không thể giúp kiểm tra tính hợp lệ của dữ liệu đưa vào. Khi lấy giá trị bằng
`list.get(index)`, kiểu dữ liệu không rõ vì mọi giá trị lấy ra đều là `Object`;
cần tự ép kiểu về kiểu ban đầu, và chỉ cần sơ suất là có thể gặp ngoại lệ ép kiểu
sai.

Nếu đã xác định kiểu như `List<Integer>`, trình biên dịch sẽ kiểm tra kiểu dữ liệu
đưa vào và chỉ cho phép thêm số nguyên. Khi khai báo biến tập hợp, chỉ có thể dùng
kiểu bao như `List<Integer>` hoặc lớp tự định nghĩa, không thể dùng kiểu nguyên
thủy như `List<int>`.

### List

#### ArrayList

`ArrayList` là mảng có thể tăng kích thước động theo nhu cầu; độ dài ban đầu mặc
định là 10. Nếu vượt quá độ dài hiện tại, nó sẽ mở rộng thêm $\dfrac{3}{2}$.

<span id="arraylist-khởi-tạo"></span>
##### Khởi tạo

```java
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void main(String[] args) {
        List<Integer> list1 = new ArrayList<>();  // Tạo mảng tự tăng tên list1, độ dài ban đầu là mặc định (10)
        List<Integer> list2 = new ArrayList<>(30);  // Tạo mảng tự tăng tên list2, độ dài ban đầu là 30
        List<Integer> list3 = new ArrayList<>(list2);  // Tạo mảng tự tăng tên list3, dùng phần tử và size của list2 làm giá trị ban đầu
    }
}
```

#### LinkedList

`LinkedList` là danh sách liên kết đôi.

<span id="linkedlist-list-khởi-tạo"></span>
##### Khởi tạo

```java
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void main(String[] args) {
        List<Integer> list1 = new LinkedList<>();  // Tạo danh sách liên kết đôi tên list1
        List<Integer> list2 = new LinkedList<>(list1);  // Tạo list2 và sao chép mọi phần tử trong list1
    }
}
```

<span id="list-phương-thức-thường-dùng"></span>
#### Phương thức thường dùng

Dưới đây dùng `this` để chỉ `List<Integer>` hiện tại:

|           Tên hàm            |                              Chức năng                              |
| :--------------------------: | :-----------------------------------------------------------------: |
|           `size()`           |                     Trả về độ dài của `this`                        |
|      `add(Integer val)`      |                     Chèn phần tử `val` vào cuối `this`              |
|  `add(int idx, Integer e)`   |                     Chèn phần tử `e` vào vị trí `idx` của `this`    |
|        `get(int idx)`        | Trả về giá trị tại vị trí `idx` trong `this`; nếu vượt biên thì ném ngoại lệ |
|  `set(int idx, Integer e)`   |                     Đổi giá trị tại vị trí `idx` trong `this` thành `e` |

Ví dụ sử dụng và so sánh khác biệt:

```java
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static List<Integer> array = new ArrayList<>();
    static List<Integer> linked = new LinkedList<>();
    
    static void add() {
        array.add(1);  // Độ phức tạp thời gian O(1)
        linked.add(1);  // Độ phức tạp thời gian O(1)
    }
    
    static void get() {
        array.get(10);  // Độ phức tạp thời gian O(1)
        linked.get(10);  // Độ phức tạp thời gian O(11)
    }
    
    static void addIdx() {
        array.add(0, 2);  // Trường hợp xấu nhất có độ phức tạp thời gian O(n)
        linked.add(0, 2);  // Trường hợp xấu nhất có độ phức tạp thời gian O(n)
    }
    
    static void size() {
        array.size();  // Độ phức tạp thời gian O(1)
        linked.size();  // Độ phức tạp thời gian O(1)
    }
    
    static void set() {  // Giá trị trả về của phương thức này là giá trị phần tử ban đầu ở vị trí đó
        array.set(0, 1);  // Độ phức tạp thời gian O(1)
        linked.set(0, 1);  // Trường hợp xấu nhất có độ phức tạp thời gian O(n)
    }

}
```

<span id="list-duyệt"></span>
#### Duyệt

```java
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static List<Integer> array = new ArrayList<>();
    static List<Integer> linked = new LinkedList<>();
    
    static void function1() {  // Duyệt đơn giản
        for (int i = 0; i < array.size(); i++) {
            out.println(array.get(i));  // Duyệt mảng tự tăng, độ phức tạp O(n)
        }
        for (int i = 0; i < linked.size(); i++) {
            out.println(linked.get(i));  // Duyệt LinkedList theo chỉ số, tổng độ phức tạp O(n^2)
        }
    }
    
    static void function2() {  // Duyệt bằng vòng lặp for-each
        for (int e : array) {
            out.println(e);
        }
        for (int e : linked) {
            out.println(e);  // Đều có độ phức tạp O(n)
        }
    }
    
    static void function3() {  // Duyệt bằng iterator
        Iterator<Integer> iterator1 = array.iterator();
        Iterator<Integer> iterator2 = linked.iterator();
        while (iterator1.hasNext()) {
            out.println(iterator1.next());
        }
        while (iterator2.hasNext()) {
            out.println(iterator2.next());
        }  // Đều có độ phức tạp O(n)
    }

}
```

???+ warning "Lưu ý"
    Không xóa phần tử trong quá trình duyệt `List` bằng `for` hoặc `foreach`;
    nếu làm vậy, chương trình có thể ném ngoại lệ.
    
    Lý do là `list.size()` đã thay đổi, nhưng biến đếm của vòng lặp không biết
    đến thay đổi đó. Sau khi xóa một phần tử, phần tử vốn nằm ở `index` tiếp theo
    sẽ dồn về `index` hiện tại; ở lượt kế tiếp, vòng lặp lại nhảy sang vị trí sau
    nữa. Kết quả là phần tử được xử lý không còn đúng như mong đợi.

### Queue

#### LinkedList

Có thể dùng `LinkedList` để triển khai hàng đợi thông thường; ví dụ dưới đây dùng
danh sách liên kết để mô phỏng hàng đợi.

<span id="linkedlist-queue-khởi-tạo"></span>
##### Khởi tạo

```java
Queue<Integer> q = new LinkedList<>();
```

`LinkedList` triển khai cả giao diện `List` và `Deque`; `Deque` lại kế thừa từ
`Queue`, nên `LinkedList` có thể dùng đồng thời như `List` và `Queue`.

#### ArrayDeque

Có thể dùng `ArrayDeque` để triển khai hàng đợi thông thường; ví dụ dưới đây dùng
mảng động để mô phỏng hàng đợi.

<span id="arraydeque-queue-khởi-tạo"></span>
##### Khởi tạo

```java
Queue<Integer> q = new ArrayDeque<>();
```

`ArrayDeque` triển khai giao diện `Deque`; `Deque` lại kế thừa từ `Queue`, nên
`ArrayDeque` có thể dùng như một `Queue`.

<span id="khác-biệt-giữa-linkedlist-và-arraydeque-khi-hiện-thực-queue"></span>
#### Khác biệt giữa LinkedList và ArrayDeque khi triển khai Queue

1.  Cấu trúc dữ liệu: `ArrayDeque` và `LinkedList` đều triển khai giao diện hàng
    đợi hai đầu `Deque` của Java. Tuy nhiên, `ArrayDeque` không triển khai giao
    diện danh sách `List`, nên không có thao tác theo vị trí chỉ số.
2.  An toàn luồng: `ArrayDeque` và `LinkedList` đều không xử lý đồng bộ luồng, nên không bảo đảm thread-safe.
3.  Cấu trúc bên dưới: `ArrayDeque` dựa trên mảng động, còn `LinkedList` dựa trên
    danh sách liên kết đôi.
4.  Tốc độ duyệt: `ArrayDeque` dùng vùng bộ nhớ liên tục, nên theo nguyên lý
    locality sẽ dễ trúng cache line CPU hơn; `LinkedList` dùng các nút rời rạc nên
    kém thân thiện với cache hơn.
5.  Tốc độ thao tác: thao tác stack và queue của `ArrayDeque` và `LinkedList` đều
    có độ phức tạp thời gian $O(1)$. Thao tác push/enqueue của `ArrayDeque` có thể
    kích hoạt mở rộng mảng, nhưng theo phân tích amortized vẫn là $O(1)$.
6.  Bộ nhớ phụ: `ArrayDeque` có thể còn vùng trống ngoài con trỏ đầu và con trỏ
    cuối của mảng, còn `LinkedList` cần thêm con trỏ trước và sau trên mỗi nút.

#### PriorityQueue

`PriorityQueue` là hàng đợi ưu tiên; mặc định là heap nhỏ.

<span id="priorityqueue-khởi-tạo"></span>
##### Khởi tạo

```java
Queue<Integer> q1 = new PriorityQueue<>();  // Heap nhỏ
Queue<Integer> q2 = new PriorityQueue<>((x, y) -> {return y - x;});  // Heap lớn
```

<span id="queue-phương-thức-thường-dùng"></span>
#### Phương thức thường dùng

Trong bảng dưới đây, hàng đợi được định nghĩa là `Queue<Integer>`.

|         Tên hàm          |                                       Chức năng                                       |
| :----------------------: | :-----------------------------------------------------------------------------------: |
|         `size()`         |                                Trả về độ dài hàng đợi hiện tại                         |
|    `add(Integer val)`    | Chèn `val` vào hàng đợi; nếu vi phạm giới hạn dung lượng của hàng đợi khi chèn thì ném ngoại lệ |
|   `offer(Integer val)`   | Chèn `val` vào hàng đợi; nếu vi phạm giới hạn dung lượng của hàng đợi khi chèn thì chèn thất bại nhưng không ném ngoại lệ |
|        `isEmpty()`       |                                Kiểm tra hàng đợi có rỗng không; rỗng thì trả về `true` |
|         `peek()`         |                                Trả về phần tử đầu hàng đợi; nếu hàng đợi rỗng thì trả về `null` |
|         `poll()`         |                                Trả về và xóa phần tử đầu hàng đợi; nếu hàng đợi rỗng thì trả về `null` |

Ví dụ sử dụng và so sánh khác biệt:

```java
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static Queue<Integer> q1 = new LinkedList<>();
    static Queue<Integer> q2 = new PriorityQueue<>();
    
    static void add() {  // add và offer cùng chèn phần tử; khác nhau ở cách báo lỗi
        q1.add(1);  // Độ phức tạp thời gian O(1)
        q2.add(1);  // Độ phức tạp thời gian O(logn)
    }
    
    static void isEmpty() {
        q1.isEmpty();  // Độ phức tạp thời gian O(1)
        q2.isEmpty();  // Độ phức tạp thời gian O(1)
    }
    
    static void size() {
        q1.size();  // Độ phức tạp thời gian O(1)
        q2.size();  // Trả về độ dài của q2
    }
    
    static void peek() {
        q1.peek();  // Độ phức tạp thời gian O(1)
        q2.peek();  // Độ phức tạp thời gian O(logn)
    }
    
    static void poll() {
        q1.poll();  // Độ phức tạp thời gian O(1)
        q2.poll();  // Độ phức tạp thời gian O(logn)
    }
}
```

<span id="queue-duyệt"></span>
#### Duyệt

```java
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static Queue<Integer> q1 = new LinkedList<>();
    static Queue<Integer> q2 = new PriorityQueue<>();
    
    static void test() {
        while (!q1.isEmpty()) {  // Độ phức tạp O(n)
            out.println(q1.poll());
        }
        while (!q2.isEmpty()) {  // Độ phức tạp O(nlogn)
            out.println(q2.poll());
        }
    }

}
```

### Deque

`Deque` là hàng đợi hai đầu trong Java; thường dùng cho cả thao tác hàng đợi và
thao tác stack.

<span id="deque-hàm-chính"></span>
#### Hàm chính

Trong bảng dưới đây, hàng đợi được định nghĩa là `Deque<Integer>`.

|           Tên hàm            |                                       Chức năng                                       |
| :--------------------------: | :-----------------------------------------------------------------------------------: |
|   `addFirst(Integer val)`    | Chèn `val` vào đầu hàng đợi; nếu vi phạm giới hạn dung lượng của hàng đợi khi chèn thì ném ngoại lệ |
|  `offerFirst(Integer val)`   | Chèn `val` vào đầu hàng đợi; nếu vi phạm giới hạn dung lượng của hàng đợi khi chèn thì chèn thất bại nhưng không ném ngoại lệ |
|       `removeFirst()`        | Trả về và xóa phần tử đầu hàng đợi; nếu hàng đợi rỗng thì ném ngoại lệ |
|        `pollFirst()`         | Trả về và xóa phần tử đầu hàng đợi; nếu hàng đợi rỗng thì trả về `null` |
|        `peekFirst()`         | Trả về phần tử đầu hàng đợi; nếu hàng đợi rỗng thì trả về `null` |
|      `push(Integer val)`     | Chèn `val` vào đầu hàng đợi, tương đương `addFirst` |
|           `pop()`            | Trả về và xóa phần tử đầu hàng đợi, tương đương `removeFirst` |
|         `remove()`           | Xóa phần tử đầu hàng đợi, tương đương `removeFirst` |
|          `poll()`            | Xóa phần tử đầu hàng đợi, tương đương `pollFirst` |
|    `addLast(Integer val)`    | Chèn `val` vào cuối hàng đợi; nếu vi phạm giới hạn dung lượng của hàng đợi khi chèn thì ném ngoại lệ |
|   `offerLast(Integer val)`   | Chèn `val` vào cuối hàng đợi; nếu vi phạm giới hạn dung lượng của hàng đợi khi chèn thì chèn thất bại nhưng không ném ngoại lệ |
|       `removeLast()`         | Trả về và xóa phần tử cuối hàng đợi; nếu hàng đợi rỗng thì ném ngoại lệ |
|        `pollLast()`          | Trả về và xóa phần tử cuối hàng đợi; nếu hàng đợi rỗng thì trả về `null` |
|        `peekLast()`          | Trả về phần tử cuối hàng đợi; nếu hàng đợi rỗng thì trả về `null` |
|      `add(Integer val)`      | Chèn `val` vào cuối hàng đợi, tương đương `addLast` |
|     `offer(Integer val)`     | Chèn `val` vào cuối hàng đợi, tương đương `offerLast` |

<span id="thao-tác-stack"></span>
#### Thao tác stack

```java
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    static Deque<Integer> stack = new ArrayDeque<>();
    static int[] a = {1, 2, 3, 4, 5};
    
    public static void main(String[] args) {
        for (int v : a) {
            stack.push(v);
        }
        while (!stack.isEmpty()) { // In ra 5 4 3 2 1
            System.out.println(stack.pop()); 
        }
    }
}

```

<span id="thao-tác-hàng-đợi-hai-đầu"></span>
#### Thao tác hàng đợi hai đầu

```java
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    static Deque<Integer> deque = new ArrayDeque<>();
    
    static void insert() {
        deque.addFirst(1);
        deque.addFirst(2);
        deque.addLast(3);
        deque.addLast(4);
    }
    
    public static void main(String[] args) {
        insert();
        while (!deque.isEmpty()) { // In ra 2 1 3 4
            System.out.println(deque.poll());
        }
        insert();
        while (!deque.isEmpty()) { // In ra 4 3 1 2
            System.out.println(deque.pollLast());
        }
    }
}
```

### Set

`Set` là cấu trúc dữ liệu giữ cho các phần tử trong bộ chứa không bị trùng lặp.

#### HashSet

`Set` chèn ở vị trí ngẫu nhiên.

<span id="hashset-khởi-tạo"></span>
##### Khởi tạo

```java
Set<Integer> s1 = new HashSet<>();
```

#### LinkedHashSet

`Set` giữ thứ tự chèn.

<span id="linkedhashset-khởi-tạo"></span>
##### Khởi tạo

```java
Set<Integer> s2 = new LinkedHashSet<>();
```

#### TreeSet

`Set` giữ các phần tử trong bộ chứa có thứ tự; mặc định là tăng dần.

<span id="treeset-khởi-tạo"></span>
##### Khởi tạo

```java
Set<Integer> s3 = new TreeSet<>();
Set<Integer> s4 = new TreeSet<>((x, y) -> {return y - x;});  // Giảm dần
```

<span id="sử-dụng-treeset-nâng-cao"></span>
##### Sử dụng TreeSet nâng cao

Các phương thức này được `TreeSet` tạo và hiện thực riêng; không thể gọi các phương thức dưới đây qua giao diện `Set`, nên cách tạo là:

```java
TreeSet<Integer> s3 = new TreeSet<>();
TreeSet<Integer> s4 = new TreeSet<>((x, y) -> {return y - x;});  // Giảm dần
```

Dưới đây dùng `this` để chỉ `TreeSet<Integer>` hiện tại.

|          Tên hàm          |                                  Chức năng                                  |
| :-----------------------: | :-------------------------------------------------------------------------: |
|         `first()`         | Trả về phần tử đầu tiên trong `this`; nếu không có thì trả về `null`         |
|          `last()`         | Trả về phần tử cuối cùng trong `this`; nếu không có thì trả về `null`        |
|   `floor(Integer val)`    | Trả về phần tử đầu tiên trong `this` nhỏ hơn hoặc bằng `val`; nếu không có thì trả về `null` |
|  `ceiling(Integer val)`   | Trả về phần tử đầu tiên trong `this` lớn hơn hoặc bằng `val`; nếu không có thì trả về `null` |
|   `higher(Integer val)`   | Trả về phần tử đầu tiên trong `this` lớn hơn `val`; nếu không có thì trả về `null` |
|   `lower(Integer val)`    | Trả về phần tử đầu tiên trong `this` nhỏ hơn `val`; nếu không có thì trả về `null` |
|       `pollFirst()`       | Trả về và xóa phần tử đầu tiên trong `this`; nếu không có thì trả về `null`  |
|       `pollLast()`        | Trả về và xóa phần tử cuối cùng trong `this`; nếu không có thì trả về `null` |

Ví dụ mã:

```java
import java.util.TreeSet;

public class Main {
    static int[] a = {4,7,1,2,3,6};
    
    public static void main(String[] args) {
        TreeSet<Integer> set = new TreeSet<>();
        for(int v:a) {
            set.add(v);
        }
        Integer a2 = set.first();
        System.out.println(a2); // Trả về 1
        Integer a3 = set.last();
        System.out.println(a3); // Trả về 7
        Integer a4 = set.floor(5);
        System.out.println(a4); // Trả về 4
        Integer a5 = set.ceiling(6);
        System.out.println(a5); // Trả về 6
        Integer a6 = set.higher(7);
        System.out.println(a6); // Trả về null
        Integer a7 = set.lower(2);
        System.out.println(a7); // Trả về 1
        Integer a8 = set.pollFirst();
        System.out.println(a8); // Trả về 1
        Integer a9 = set.pollLast();
        System.out.println(a9); // Trả về 7
    }
}
```

<span id="set-phương-thức-thường-dùng"></span>
#### Phương thức thường dùng của Set

|           Tên hàm            |                                  Chức năng                                  |
| :--------------------------: | :-------------------------------------------------------------------------: |
|           `size()`           | Trả về kích thước tập hợp hiện tại |
|      `add(Integer val)`      | Chèn `val` vào tập hợp |
|   `contains(Integer val)`    | Kiểm tra tập hợp có phần tử `val` hay không |
|    `addAll(Collection e)`    | Thêm toàn bộ phần tử trong bộ chứa `e` vào tập hợp hiện tại |
|  `retainAll(Collection e)`   | Xóa các phần tử trong tập hợp hiện tại không xuất hiện trong bộ chứa `e`, tức lấy giao của tập hợp hiện tại và `e` |
|  `removeAll(Collection e)`   | Xóa các phần tử trong tập hợp hiện tại xuất hiện trong bộ chứa `e`, tức lấy hiệu của tập hợp hiện tại và `e` |

```java
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static Set<Integer> s1 = new HashSet<>();
    static Set<Integer> s2 = new LinkedHashSet<>();
    
    static void add() {
        s1.add(1);
    }
    
    static void contains() {  // Kiểm tra trong set có phần tử giá trị 2 hay không; có thì trả về true, không thì trả về false
        s1.contains(2);
    }
    
    static void test1() {  // Hợp của s1 và s2
        Set<Integer> res = new HashSet<>();
        res.addAll(s1);
        res.addAll(s2);
    }
    
    static void test2() {  // Giao của s1 và s2
        Set<Integer> res = new HashSet<>();
        res.addAll(s1);
        res.retainAll(s2);
    }
    
    static void test3() {  // Hiệu: s1 - s2
        Set<Integer> res = new HashSet<>();
        res.addAll(s1);
        res.removeAll(s2);
    }
}
```

<span id="set-duyệt"></span>
#### Duyệt

```java
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static Set<Integer> s1 = new HashSet<>();
    static Set<Integer> s2 = new LinkedHashSet<>();
    
    static void test() {
        for (int key : s1) {
            out.println(key);
        }
        out.close();
    }
}
```

### Map

`Map` là cấu trúc dữ liệu duy trì các cặp khóa-giá trị `<Key, Value>`, trong đó `Key` là duy nhất.

#### HashMap

`Map` chèn ở vị trí ngẫu nhiên.

<span id="hashmap-khởi-tạo"></span>
##### Khởi tạo

```java
Map<Integer, Integer> map1 = new HashMap<>();
```

#### LinkedHashMap

`Map` giữ thứ tự chèn.

<span id="linkedhashmap-khởi-tạo"></span>
##### Khởi tạo

```java
Map<Integer, Integer> map2 = new LinkedHashMap<>();
```

#### TreeMap

`Map` giữ `key` có thứ tự; mặc định là tăng dần.

<span id="treemap-khởi-tạo"></span>
##### Khởi tạo

```java
Map<Integer, Integer> map3 = new TreeMap<>();
Map<Integer, Integer> map4 = new TreeMap<>((x, y) -> {return y - x;});  // Giảm dần
```

<span id="map-phương-thức-thường-dùng"></span>
#### Phương thức thường dùng

Dưới đây dùng `this` để chỉ `Map<Integer, Integer>` hiện tại:

|                Tên hàm                 |                         Chức năng                         |
| :------------------------------------: | :-------------------------------------------------------: |
|  `put(Integer key, Integer value)`     | Chèn `<key, value>` vào `this`                            |
|               `size()`                 | Trả về kích thước của `this`                              |
|      `containsKey(Integer key)`        | Kiểm tra trong `this` có khóa của phần tử nào là `key` hay không |
|          `get(Integer key)`            | Trả về giá trị tương ứng với phần tử có khóa là `key` trong `this` |
|              `keySet()`                | Trả về tập hợp gồm khóa của tất cả phần tử trong `this`    |

Ví dụ sử dụng:

```java
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.TreeMap;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    
    static Map<Integer, Integer> map1 = new HashMap<>();
    static Map<Integer, Integer> map2 = new LinkedHashMap<>();
    static Map<Integer, Integer> map3 = new TreeMap<>();
    static Map<Integer, Integer> map4 = new TreeMap<>((x,y)->{return y-x;});
    
    static void put(){  // Trả về phần tử có key là 1, value là 1
        map1.put(1, 1);
    }
    static void get(){  // Trả về value có key là 1
        map1.get(1);
    }
    static void containsKey(){  // Kiểm tra có cặp key-value với key là 1 hay không
        map1.containsKey(1);
    }
    static void KeySet(){
        map1.keySet();
    }
}
```

<span id="map-duyệt"></span>
#### Duyệt

```java
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    
    static Map<Integer, Integer> map1 = new HashMap<>();
    
    static void print() {
        for (int key : map1.keySet()) {
            out.println(key + " " + map1.get(key));
        }
    }
}
```

Kiểu của khóa và giá trị cũng có thể thay đổi. Ví dụ, có thể định nghĩa `Map`
như sau:

```java
Map<String, Set<Integer>> map = new HashMap<>();
```

## Arrays (lớp tiện ích mảng)

`Arrays` là một lớp tiện ích trong `java.util` dùng để thao tác với mảng. Các
phương thức của nó đều là phương thức tĩnh, có thể gọi trực tiếp bằng tên lớp.

### Arrays.sort()

`Arrays.sort()` là phương thức sắp xếp mảng. Các overload chính như sau:

```java
import java.util.Arrays;
import java.util.Comparator;

public class Main {
    static int[] a = new int[10];
    static Integer[] b = new Integer[10];
    static int firstIdx, lastIdx;
    
    public static void main(String[] args) {
        Arrays.sort(a);  // 1
        Arrays.sort(a, firstIdx, lastIdx);  // 2
        Arrays.sort(b, new Comparator<Integer>() {  // 3
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        Arrays.sort(b, firstIdx, lastIdx, new Comparator<Integer>() {  // 4
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        // Vì sau Java 8 có biểu thức Lambda, overload thứ ba và thứ tư cũng có thể viết là
        Arrays.sort(b, (x, y) -> {  // 5
            return y - x;
        });
        Arrays.sort(b, (x, y) -> {  // 6
            return y - x;
        });
    }
}
```

Ý nghĩa của các overload theo số thứ tự:

1.  Sắp xếp mảng `a`, mặc định tăng dần.
2.  Sắp xếp đoạn chỉ định của mảng `a`, mặc định tăng dần; đoạn sắp xếp là nửa
    kín nửa mở `[firstIdx, lastIdx)`.
3.  Sắp xếp mảng `a` theo cách tùy chỉnh. Nếu comparator trả về tham số thứ hai
    trừ tham số thứ nhất thì kết quả giảm dần; nếu trả về tham số thứ nhất trừ
    tham số thứ hai thì kết quả tăng dần. Khi dùng comparator tùy chỉnh, kiểu phần
    tử mảng phải là kiểu đối tượng.
4.  Sắp xếp tùy chỉnh đoạn chỉ định của mảng `a`; đoạn sắp xếp là nửa kín nửa mở
    `[firstIdx, lastIdx)`. Khi dùng comparator tùy chỉnh, kiểu phần tử mảng phải
    là kiểu đối tượng.
5.  Tương tự 3, dùng biểu thức Lambda để rút gọn mã.
6.  Tương tự 4, dùng biểu thức Lambda để rút gọn mã.

???+ note "Cài đặt bên trong của `Arrays.sort()`"
    1.  Khi kiểu phần tử của mảng truyền vào `Arrays.sort` là kiểu dữ liệu nguyên
        thủy (`byte`, `short`, `char`, `int`, `long`, `double`, `float`), mặc định
        dùng `DualPivotQuicksort` (sắp xếp nhanh hai chốt), độ phức tạp xấu nhất
        có thể đạt $O(n^2)$.
    2.  Khi kiểu phần tử của mảng truyền vào `Arrays.sort` không phải kiểu dữ liệu
        nguyên thủy, mặc định dùng `legacyMergeSort` và `TimSort` (sắp xếp trộn),
        độ phức tạp là $O(n\log n)$.

Có thể kiểm chứng bằng đoạn mã sau:

???+ example "[Codeforces 1646B - Quality vs Quantity](https://codeforces.com/problemset/problem/1646/B)"
    Có $n$ số nguyên. Cần chia chúng thành hai nhóm và kiểm tra liệu có tồn tại
    một nhóm có độ dài nhỏ hơn nhóm kia nhưng tổng lại lớn hơn hay không.

??? note "Mã bài ví dụ"
    ```java
    import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.io.PrintWriter;
    import java.util.Arrays;
    import java.util.StringTokenizer;
    
    public class Main {
        static class FastReader {
            StringTokenizer st;
            BufferedReader br;
            
            public FastReader() {
                br = new BufferedReader(new InputStreamReader(System.in));
            }
            
            String next() {
                while (st == null || !st.hasMoreElements()) {
                    try {
                        st = new StringTokenizer(br.readLine());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                return st.nextToken();
            }
            
            int nextInt() {
                return Integer.parseInt(next());
            }
            
            long nextLong() {
                return Long.parseLong(next());
            }
            
            double nextDouble() {
                return Double.parseDouble(next());
            }
            
            String nextLine() {
                String str = "";
                try {
                    str = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return str;
            }
        }
        
        static PrintWriter out = new PrintWriter(System.out);
        static FastReader in = new FastReader();
        
        static void solve() {
            int n = in.nextInt();
            // Nếu đổi kiểu mảng này từ Integer thành int thì sẽ gây TLE
            Integer[] a = new Integer[n + 10];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a, 1, n + 1);
            long left = a[1];
            long right = 0;
            int x = n;
            for (int i = 2; i < x; i++, x--) {
                left = left + a[i];
                right = right + a[x];
                if (right > left) {
                    out.println("YES");
                    return;
                }
            }
            out.println("NO");
        }
        
        public static void main(String[] args) {
            int t = in.nextInt();
            while (t-- > 0) {
                solve();
            }
            out.close();
        }
    }
    ```

### Arrays.binarySearch()

`Arrays.binarySearch()` là phương thức tìm kiếm nhị phân trên một đoạn liên tiếp
của mảng. Điều kiện cần là mảng phải có thứ tự. Độ phức tạp thời gian là
$O(\log n)$. Các overload chính như sau:

```java
import java.util.Arrays;

public class Main {
    static int[] a = new int[10];
    static Integer[] b = new Integer[10];
    static int firstIdx, lastIdx;
    static int key;
    
    public static void main(String[] args) {
        Arrays.binarySearch(a, key);  // 1
        Arrays.binarySearch(a, firstIdx, lastIdx, key);  // 2
    }
}
```

Mã nguồn như sau:

```java
private static int binarySearch0(int[] a, int fromIndex, int toIndex, int key) {
    int low = fromIndex;
    int high = toIndex - 1;
    
    while (low <= high) {
        int mid = (low + high) >>> 1;
        int midVal = a[mid];
        
        if (midVal < key)
            low = mid + 1;
        else if (midVal > key)
            high = mid - 1;
        else
            return mid; // key found
    }
    return -(low + 1);  // key not found.
}
```

Ý nghĩa của các overload theo số thứ tự:

1.  Tìm nhị phân trong mảng `a` xem có tồn tại `key` hay không. Nếu có thì trả về
    chỉ số của nó; nếu không tồn tại thì trả về một số âm.
2.  Tìm nhị phân trong đoạn nửa kín nửa mở `[firstIdx,lastIdx)` của mảng `a`. Nếu
    tìm thấy `key` thì trả về chỉ số của nó; nếu không tồn tại thì trả về một số
    âm.

### Arrays.fill()

Phương thức `Arrays.fill()` gán cùng một giá trị cho các phần tử trong một đoạn
liên tiếp của mảng. Tham số của nó gồm mảng, `fromIndex`, `toIndex` và giá trị cần
điền. Sau khi phương thức chạy, mọi phần tử trong đoạn nửa kín nửa mở
`[firstIdx,lastIdx)` của mảng đều có giá trị cần điền.

## Collections (lớp tiện ích tập hợp)

`Collections` là một lớp tiện ích trong `java.util` dùng để thao tác với tập hợp.
Các phương thức của nó đều là phương thức tĩnh, có thể gọi trực tiếp bằng tên lớp.

### Collections.sort()

Về cơ bản, `Collections.sort()` chuyển toàn bộ phần tử trong tập hợp thành mảng
rồi gọi `Arrays.sort()`. Sau khi sắp xếp xong, nó gán kết quả trở lại tập hợp ban
đầu. Vì trong Java, kiểu phần tử của `Collection` luôn là kiểu đối tượng, phương
thức này dùng sắp xếp trộn để xử lý.

Phương thức này không thể sắp xếp một đoạn chỉ định của tập hợp.

Mã nguồn tương ứng:

```java
default void sort(Comparator<? super E> c) {
    Object[] a = this.toArray();
    Arrays.sort(a, (Comparator) c);
    ListIterator<E> i = this.listIterator();
    for (Object e : a) {
        i.next();
        i.set((E) e);
    }
}
```

### Collections.binarySearch()

`Collections.binarySearch()` thực hiện tìm kiếm nhị phân trên tập hợp; chức năng
tương tự `Arrays.binarySearch()`.

```java
Collections.binarySearch(list, key);
```

Phương thức này không thể tìm kiếm trên một đoạn chỉ định.

### Collections.swap()

`Collections.swap()` dùng để hoán đổi hai phần tử ở hai vị trí chỉ định trong tập
hợp.

```java
 Collections.swap(list, i, j);
```

<span id="khác"></span>
## Khác

<span id="vấn-đề-so-sánh-số"></span>
### Vấn đề so sánh số

Trong Java, nếu xét kiểu số thực nguyên thủy thì `-0.0 == 0.0`. Nếu dùng kiểu đối
tượng thì `-0.0` và `0.0` có thể được xem là hai giá trị khác nhau khi so sánh đối
tượng. Khi dùng `Set` để đếm số lượng hệ số góc, khác biệt này có thể gây rắc
rối. Cách xử lý là cộng thêm `0.0` vào mọi hệ số góc trước khi đưa vào `Set`.

```java
import java.io.PrintWriter;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    
    static void A() {
        Double a = 0.0;
        Double b = -0.0;
        out.println(a.equals(b));  // false
    }
    
    static void B() {
        Double a = 0.0;
        Double b = -0.0 + 0.0;
        out.println(a.equals(b));  // true
    }
    
    static void C() {
        double a = 0.0;
        double b = -0.0;
        out.println(a == b);  // true
    }
    
    
    public static void main(String[] args) {
        A();
        B();
        C();
        out.close();
    }
}
```

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

[^ref1]: [Input & Output - USACO Guide](https://usaco.guide/general/input-output?lang=java#method-3---io-template)
