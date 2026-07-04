> Bản đọc nhanh: mẫu có sẵn ở cuối bài...

<span id="&#23450;&#20041;"></span>
## Định nghĩa

Tính toán độ chính xác tùy ý (Arbitrary-Precision Arithmetic), còn được gọi là tính toán số nguyên lớn (bignum), sử dụng một số cấu trúc và thuật toán để hỗ trợ phép toán trên các số nguyên lớn hơn kiểu số nguyên mà ngôn ngữ cung cấp sẵn.

<span id="&#24341;&#20837;"></span>
## Giới thiệu

Các bài toán độ chính xác cao có rất nhiều chi tiết nhỏ, và cách cài đặt cũng có nhiều điểm cần chú ý.

Vì vậy, hãy cùng cài đặt một máy tính đơn giản.

???+ note "Bài toán"
    Đầu vào: một biểu thức có dạng `a <op> b`.
    
    -   `a`, `b` lần lượt là các số nguyên không âm ở hệ thập phân, độ dài không vượt quá $1000$;
    -   `<op>` là một ký tự (`+`, `-`, `*` hoặc `/`), biểu thị phép toán.
    -   Giữa số nguyên và toán tử có đúng một dấu cách.
    
    Đầu ra: kết quả phép toán.
    
    -   Với các phép `+`, `-`, `*`, in một dòng là kết quả;
    -   Với phép `/`, in hai dòng lần lượt là thương và số dư.
    -   Đảm bảo mọi kết quả đều là số nguyên không âm.

<span id="&#23384;&#20648;"></span>
## Lưu trữ

Trong các cách cài đặt thông thường, số độ chính xác cao được biểu diễn bằng chuỗi, mỗi ký tự biểu diễn một chữ số thập phân. Vì thế có thể nói tính toán số độ chính xác cao thực chất là một dạng xử lý chuỗi đặc biệt.

Khi đọc chuỗi, chữ số cao nhất nằm ở đầu chuỗi (vị trí có chỉ số nhỏ). Tuy nhiên, theo thói quen, vị trí có chỉ số nhỏ nhất sẽ lưu **chữ số thấp nhất**, tức là lưu chuỗi đã đảo ngược. Lý do là độ dài của số có thể thay đổi, nhưng ta muốn các hàng có cùng trọng số luôn được căn thẳng (chẳng hạn, hàng đơn vị luôn ở chỉ số `[0]`, hàng chục luôn ở chỉ số `[1]`, ...); đồng thời, các phép cộng, trừ, nhân thường được thực hiện từ hàng đơn vị (như phép tính đặt dọc ở tiểu học). Những điều này là lý do đủ để chọn cách "lưu đảo ngược".

Từ đây trở đi, ta sẽ luôn dùng quy ước này. Định nghĩa hằng `LEN = 1004` để biểu thị độ dài lớn nhất mà chương trình chứa được.

Từ đó, không khó để viết đoạn mã đọc một số độ chính xác cao:

```cpp
void clear(int a[]) {
  for (int i = 0; i < LEN; ++i) a[i] = 0;
}

void read(int a[]) {
  static char s[LEN + 1];
  scanf("%s", s);

  clear(a);

  int len = strlen(s);
  // Như đã nói ở trên, đảo ngược
  for (int i = 0; i < len; ++i) a[len - i - 1] = s[i] - '0';
  // s[i] - '0' chính là chữ số mà s[i] biểu diễn
  // Một số bạn có thể quen hiểu theo cách ord(s[i]) - ord('0') hơn
}
```

Khi in, ta cũng in theo thứ tự ngược với cách lưu trữ. Vì không muốn in các số không đứng đầu, ở đây ta tìm chữ số khác không đầu tiên từ hàng cao nhất về xuống, rồi bắt đầu in từ đó; điều kiện dừng là `i >= 1` thay vì `i >= 0` vì khi toàn bộ số bằng $0$, ta vẫn muốn in ra một ký tự `0`.

```cpp
void print(int a[]) {
  int i;
  for (i = LEN - 1; i >= 1; --i)
    if (a[i] != 0) break;
  for (; i >= 0; --i) putchar(a[i] + '0');
  putchar('\n');
}
```

Ghép các phần lại, ta được một chương trình đọc rồi in lại hoàn chỉnh.

??? note "`copycat.cpp`"
    ```cpp
    #include <cstdio>
    #include <cstring>
    
    constexpr int LEN = 1004;
    
    int a[LEN];
    
    void clear(int a[]) {
      for (int i = 0; i < LEN; ++i) a[i] = 0;
    }
    
    void read(int a[]) {
      static char s[LEN + 1];
      scanf("%s", s);
    
      clear(a);
    
      int len = strlen(s);
      for (int i = 0; i < len; ++i) a[len - i - 1] = s[i] - '0';
    }
    
    void print(int a[]) {
      int i;
      for (i = LEN - 1; i >= 1; --i)
        if (a[i] != 0) break;
      for (; i >= 0; --i) putchar(a[i] + '0');
      putchar('\n');
    }
    
    int main() {
      read(a);
      print(a);
    
      return 0;
    }
    ```

<span id="&#22235;&#21017;&#36816;&#31639;"></span>
## Bốn phép toán cơ bản

Độ khó của bốn phép toán cơ bản cũng khác nhau. Đơn giản nhất là cộng và trừ độ chính xác cao, tiếp theo là nhân độ chính xác cao với độ chính xác đơn (kiểu `int` thông thường) và nhân hai số độ chính xác cao, cuối cùng là chia hai số độ chính xác cao.

Ta sẽ cài đặt lần lượt tất cả chức năng cần có theo thứ tự này.

<span id="&#21152;&#27861;"></span>
### Phép cộng

Cộng độ chính xác cao thực ra chính là phép cộng đặt dọc.

![](./images/plus.svg)

Nói cách khác, bắt đầu từ chữ số thấp nhất, cộng các chữ số ở cùng vị trí của hai số hạng và kiểm tra xem tổng có đạt hoặc vượt $10$ hay không. Nếu có, xử lý nhớ: tăng kết quả ở hàng cao hơn thêm $1$, và giảm kết quả ở hàng hiện tại đi $10$.

```cpp
void add(int a[], int b[], int c[]) {
  clear(c);

  // Trong cài đặt độ chính xác cao, thường đặt độ dài mảng tối đa LEN lớn hơn đầu vào có thể có
  // Rồi bỏ qua vài lần lặp cuối, nhờ đó tránh được khá nhiều xử lý biên
  // Vì đầu vào thực tế không vượt quá 1000 chữ số, lặp đến LEN - 1 = 1003 là đủ
  for (int i = 0; i < LEN - 1; ++i) {
    // Cộng các chữ số ở cùng hàng
    c[i] += a[i] + b[i];
    if (c[i] >= 10) {
      // Nhớ
      c[i + 1] += 1;
      c[i] -= 10;
    }
  }
}
```

Thử kết hợp với phần trước, ta có được một máy tính phép cộng.

??? note "`adder.cpp`"
    ```cpp
    #include <cstdio>
    #include <cstring>
    
    constexpr int LEN = 1004;
    
    int a[LEN], b[LEN], c[LEN];
    
    void clear(int a[]) {
      for (int i = 0; i < LEN; ++i) a[i] = 0;
    }
    
    void read(int a[]) {
      static char s[LEN + 1];
      scanf("%s", s);
    
      clear(a);
    
      int len = strlen(s);
      for (int i = 0; i < len; ++i) a[len - i - 1] = s[i] - '0';
    }
    
    void print(int a[]) {
      int i;
      for (i = LEN - 1; i >= 1; --i)
        if (a[i] != 0) break;
      for (; i >= 0; --i) putchar(a[i] + '0');
      putchar('\n');
    }
    
    void add(int a[], int b[], int c[]) {
      clear(c);
    
      for (int i = 0; i < LEN - 1; ++i) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
          c[i + 1] += 1;
          c[i] -= 10;
        }
      }
    }
    
    int main() {
      read(a);
      read(b);
    
      add(a, b, c);
      print(c);
    
      return 0;
    }
    ```

<span id="&#20943;&#27861;"></span>
### Phép trừ

Trừ độ chính xác cao cũng chính là phép trừ đặt dọc.

![](./images/subtraction.svg)

Bắt đầu từ hàng đơn vị và trừ từng hàng; nếu kết quả âm thì mượn $1$ từ hàng cao hơn. Ý tưởng tổng thể hoàn toàn giống phép cộng.

```cpp
void sub(int a[], int b[], int c[]) {
  clear(c);

  for (int i = 0; i < LEN - 1; ++i) {
    // Trừ từng hàng
    c[i] += a[i] - b[i];
    if (c[i] < 0) {
      // Mượn
      c[i + 1] -= 1;
      c[i] += 10;
    }
  }
}
```

Thay `add()` trong chương trình trước bằng `sub()`, ta có một máy tính phép trừ.

??? note "`subtractor.cpp`"
    ```cpp
    #include <cstdio>
    #include <cstring>
    
    constexpr int LEN = 1004;
    
    int a[LEN], b[LEN], c[LEN];
    
    void clear(int a[]) {
      for (int i = 0; i < LEN; ++i) a[i] = 0;
    }
    
    void read(int a[]) {
      static char s[LEN + 1];
      scanf("%s", s);
    
      clear(a);
    
      int len = strlen(s);
      for (int i = 0; i < len; ++i) a[len - i - 1] = s[i] - '0';
    }
    
    void print(int a[]) {
      int i;
      for (i = LEN - 1; i >= 1; --i)
        if (a[i] != 0) break;
      for (; i >= 0; --i) putchar(a[i] + '0');
      putchar('\n');
    }
    
    void sub(int a[], int b[], int c[]) {
      clear(c);
    
      for (int i = 0; i < LEN - 1; ++i) {
        c[i] += a[i] - b[i];
        if (c[i] < 0) {
          c[i + 1] -= 1;
          c[i] += 10;
        }
      }
    }
    
    int main() {
      read(a);
      read(b);
    
      sub(a, b, c);
      print(c);
    
      return 0;
    }
    ```

Thử nhập `1 2`: chương trình in ra `/9999999`. Sao **OI Wiki** lại đưa cho mình đoạn mã sai vậy...

Thực ra, đoạn mã trên chỉ xử lý được trường hợp số bị trừ $a$ lớn hơn hoặc bằng số trừ $b$. Việc xử lý khi số bị trừ nhỏ hơn số trừ, tức $a<b$, rất đơn giản.

$a-b=-(b-a)$

Để tính giá trị $b-a$, vì $b>a$, có thể gọi hàm `sub` ở trên bằng cách viết `sub(b,a,c)`. Để thu được giá trị $a-b$, chỉ cần thêm dấu trừ vào trước kết quả.

<span id="&#20056;&#27861;"></span>
### Phép nhân

<span id="&#39640;&#31934;&#24230;&#21333;&#31934;&#24230;"></span>
#### Độ chính xác cao - độ chính xác đơn

Nhân độ chính xác cao cũng là phép đặt... khoan đã!

Trước hết hãy xét một trường hợp đơn giản: một trong hai thừa số có kiểu `int` thông thường. Có cách xử lý nào đơn giản không?

Một ý tưởng trực quan là trực tiếp nhân từng chữ số của $a$ với $b$. Về mặt giá trị, cách này là đúng, nhưng nó không còn phù hợp với biểu diễn thập phân, nên cần chuẩn hóa lại thành dạng bình thường.

Cách chuẩn hóa cũng là bắt đầu từ hàng đơn vị và xử lý nhớ lên từng hàng. Tuy nhiên, phần nhớ ở đây có thể rất lớn, thậm chí lớn hơn $9$ rất nhiều, vì sau khi nhân, mỗi hàng có thể đạt cấp độ $9b$. Do đó không thể xử lý nhớ bằng cách đơn giản là trừ $10$, mà phải tính bằng thương và số dư khi chia cho $10$. Xem chi tiết trong chú thích code; cũng có thể tham khảo hình dưới đây, minh họa quá trình tính số độ chính xác cao $1337$ nhân với số độ chính xác đơn $42$.

![](./images/multiplication-short.png)

Tất nhiên, cũng vì lý do này, phương pháp này cần đặc biệt chú ý đến phạm vi của thừa số $b$. Nếu nó cùng cấp độ với $10^9$ (hoặc giới hạn trên của kiểu số nguyên tương ứng), cần thận trọng khi dùng phép nhân độ chính xác cao - độ chính xác đơn.

```cpp
void mul_short(int a[], int b, int c[]) {
  clear(c);

  for (int i = 0; i < LEN - 1; ++i) {
    // Trực tiếp nhân chữ số thứ i của a với thừa số, rồi cộng vào kết quả
    c[i] += a[i] * b;

    if (c[i] >= 10) {
      // Xử lý nhớ
      // c[i] / 10 là thương của phép chia, trở thành phần tăng thêm của nhớ
      c[i + 1] += c[i] / 10;
      // Còn c[i] % 10 là số dư của phép chia, trở thành giá trị giữ lại ở hàng hiện tại
      c[i] %= 10;
    }
  }
}
```

<span id="&#39640;&#31934;&#24230;&#39640;&#31934;&#24230;"></span>
#### Độ chính xác cao - độ chính xác cao

Nếu cả hai thừa số đều có độ chính xác cao, phép nhân đặt dọc lại phát huy tác dụng.

Nhớ lại từng bước của phép nhân đặt dọc: thực chất ta tính tổng của nhiều hạng $a \times b_i \times 10^i$. Ví dụ, khi tính $1337 \times 42$, ta đang tính $1337 \times 2 \times 10^0 + 1337 \times 4 \times 10^1$.

Vì vậy, có thể tách $b$ thành tất cả các chữ số của nó; mỗi chữ số là một số độ chính xác đơn. Lần lượt nhân chúng với $a$, dịch sang trái đến đúng vị trí tương ứng rồi cộng lại sẽ được đáp án. Tất nhiên, cuối cùng vẫn cần xử lý nhớ theo cách giống ví dụ trên.

![](./images/multiplication-long.png)

Lưu ý quá trình này không hoàn toàn giống phép nhân đặt dọc: thuật toán của ta không xử lý nhớ trong từng bước nhân, mà giữ tất cả kết quả tại vị trí tương ứng, rồi đến cuối mới xử lý nhớ một lần. Điều này không làm thay đổi kết quả.

```cpp
void mul(int a[], int b[], int c[]) {
  clear(c);

  for (int i = 0; i < LEN - 1; ++i) {
    // Ở đây tính trực tiếp hàng thứ i từ thấp lên cao của kết quả, đồng thời xử lý nhớ
    // Lần lặp thứ i cộng vào c[i] tổng các tích a[p] và b[q] với mọi p + q = i
    // Hiệu quả giống cách tính trong hình rồi cộng lại, chỉ là cách cài đặt ngắn gọn hơn
    for (int j = 0; j <= i; ++j) c[i] += a[j] * b[i - j];

    if (c[i] >= 10) {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  }
}
```

<span id="&#38500;&#27861;"></span>
### Phép chia

Một cách cài đặt phép chia độ chính xác cao là phép chia dài đặt dọc.

![](./images/division.svg)

Phép chia dài đặt dọc thực chất có thể xem là một quá trình trừ lặp. Chẳng hạn, phép tính chữ số hàng chục của thương trong hình trên có thể hiểu như sau: lấy $45$ trừ $12$ ba lần thì kết quả trở nên nhỏ hơn $12$, không thể trừ tiếp, nên chữ số ở hàng này là $3$.

Để giảm các phép tính dư thừa, ta lấy trước độ dài $l_a$ của số bị chia và độ dài $l_b$ của số chia, rồi bắt đầu từ chỉ số $l_a - l_b$ để tính thương từ hàng cao xuống hàng thấp. Điều này giống với cách khi tính tay, ta căn chữ số cao nhất của tích đầu tiên với chữ số cao nhất của số bị chia.

Chương trình tham khảo cài đặt hàm `greater_eq()` để xét xem phần số bị chia có chỉ số `last_dg` làm hàng thấp nhất còn có thể trừ thêm số chia mà vẫn không âm hay không. Sau đó, với mỗi chữ số của thương, ta liên tục gọi `greater_eq()`; khi điều kiện đúng thì dùng phép trừ độ chính xác cao để trừ số chia khỏi phần dư, qua đó mô phỏng quá trình chia đặt dọc.

```cpp
// Phan so bi chia a voi chi so last_dg lam hang thap nhat co the tru them so chia b ma van khong am hay khong
// len la do dai cua so chia b, de tranh tinh lap lai
bool greater_eq(int a[], int b[], int last_dg, int len) {
  // Phan con lai cua so bi chia co the dai hon so chia; truong hop nay nhieu nhat chi hon 1 chu so, nen kiem tra nhu vay la du
  if (a[last_dg + len] != 0) return true;
  // So sanh tung hang tu cao xuong thap
  for (int i = len - 1; i >= 0; --i) {
    if (a[last_dg + i] > b[i]) return true;
    if (a[last_dg + i] < b[i]) return false;
  }
  // Neu bang nhau thi van co the tru
  return true;
}

void div(int a[], int b[], int c[], int d[]) {
  clear(c);
  clear(d);

  int la, lb;
  for (la = LEN - 1; la > 0; --la)
    if (a[la - 1] != 0) break;
  for (lb = LEN - 1; lb > 0; --lb)
    if (b[lb - 1] != 0) break;
  if (lb == 0) {  // So chia khong duoc bang 0
    puts("> <");
    return;
  }

  // c la thuong
  // d la phan con lai cua so bi chia; sau khi thuat toan ket thuc, no tro thanh so du
  for (int i = 0; i < la; ++i) d[i] = a[i];
  for (int i = la - lb; i >= 0; --i) {
    // Tinh chu so thu i cua thuong
    while (greater_eq(d, b, i, lb)) {
      // Neu co the tru thi tru
      // Doan nay la mot phep tru do chinh xac cao
      for (int j = 0; j < lb; ++j) {
        d[i + j] -= b[j];
        if (d[i + j] < 0) {
          d[i + j + 1] -= 1;
          d[i + j] += 10;
        }
      }
      // Tang chu so nay cua thuong len 1
      c[i] += 1;
      // Quay lai dau vong lap de kiem tra lai
    }
  }
}
```

<span id="&#20837;&#38376;&#31687;&#23436;&#25104;"></span>
## Hoàn thành phần nhập môn

Kết hợp các cài đặt của bốn phép toán đã giới thiệu ở trên là có thể hoàn thành chương trình máy tính đã nêu ở đầu bài.

??? note "`calculator.cpp`"
    ```cpp
    #include <cstdio>
    #include <cstring>
    
    constexpr int LEN = 1004;
    
    int a[LEN], b[LEN], c[LEN], d[LEN];
    
    void clear(int a[]) {
      for (int i = 0; i < LEN; ++i) a[i] = 0;
    }
    
    void read(int a[]) {
      static char s[LEN + 1];
      scanf("%s", s);
    
      clear(a);
    
      int len = strlen(s);
      for (int i = 0; i < len; ++i) a[len - i - 1] = s[i] - '0';
    }
    
    void print(int a[]) {
      int i;
      for (i = LEN - 1; i >= 1; --i)
        if (a[i] != 0) break;
      for (; i >= 0; --i) putchar(a[i] + '0');
      putchar('\n');
    }
    
    void add(int a[], int b[], int c[]) {
      clear(c);
    
      for (int i = 0; i < LEN - 1; ++i) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
          c[i + 1] += 1;
          c[i] -= 10;
        }
      }
    }
    
    void sub(int a[], int b[], int c[]) {
      clear(c);
    
      for (int i = 0; i < LEN - 1; ++i) {
        c[i] += a[i] - b[i];
        if (c[i] < 0) {
          c[i + 1] -= 1;
          c[i] += 10;
        }
      }
    }
    
    void mul(int a[], int b[], int c[]) {
      clear(c);
    
      for (int i = 0; i < LEN - 1; ++i) {
        for (int j = 0; j <= i; ++j) c[i] += a[j] * b[i - j];
    
        if (c[i] >= 10) {
          c[i + 1] += c[i] / 10;
          c[i] %= 10;
        }
      }
    }
    
    bool greater_eq(int a[], int b[], int last_dg, int len) {
      if (a[last_dg + len] != 0) return true;
      for (int i = len - 1; i >= 0; --i) {
        if (a[last_dg + i] > b[i]) return true;
        if (a[last_dg + i] < b[i]) return false;
      }
      return true;
    }
    
    void div(int a[], int b[], int c[], int d[]) {
      clear(c);
      clear(d);
    
      int la, lb;
      for (la = LEN - 1; la > 0; --la)
        if (a[la - 1] != 0) break;
      for (lb = LEN - 1; lb > 0; --lb)
        if (b[lb - 1] != 0) break;
      if (lb == 0) {
        puts("> <");
        return;
      }
    
      for (int i = 0; i < la; ++i) d[i] = a[i];
      for (int i = la - lb; i >= 0; --i) {
        while (greater_eq(d, b, i, lb)) {
          for (int j = 0; j < lb; ++j) {
            d[i + j] -= b[j];
            if (d[i + j] < 0) {
              d[i + j + 1] -= 1;
              d[i + j] += 10;
            }
          }
          c[i] += 1;
        }
      }
    }
    
    int main() {
      read(a);
    
      char op[4];
      scanf("%s", op);
    
      read(b);
    
      switch (op[0]) {
        case '+':
          add(a, b, c);
          print(c);
          break;
        case '-':
          sub(a, b, c);
          print(c);
          break;
        case '*':
          mul(a, b, c);
          print(c);
          break;
        case '/':
          div(a, b, c, d);
          print(c);
          print(d);
          break;
        default:
          puts("> <");
      }
    
      return 0;
    }
    ```

<span id="&#21387;&#20301;&#39640;&#31934;&#24230;"></span>
## Độ chính xác cao gộp chữ số

<span id="&#24341;&#20837;_1"></span>
### Giới thiệu

Trong các phép cộng, trừ, nhân độ chính xác cao thông thường, ta đều tách các số tham gia phép toán thành từng chữ số riêng lẻ để tính.

Ví dụ, khi tính $8192\times 42$, nếu làm theo cách nhân độ chính xác cao với độ chính xác cao, thực chất ta đang tính $(8000+100+90+2)\times(40+2)$.

Khi số có nhiều chữ số, số lượng phần được tách ra cũng nhiều, làm hiệu suất của phép toán độ chính xác cao giảm xuống.

Có cách nào tối ưu hơn không?

Nhận thấy cách tách số không ảnh hưởng đến kết quả cuối cùng, ta có thể gộp nhiều chữ số lại với nhau.

<span id="&#36807;&#31243;"></span>
### Quá trình

Vẫn lấy ví dụ trên: nếu cứ mỗi hai chữ số ta tách thành một phần, ta có thể tách thành $(8100+92)\times 42$.

Cách tách này không ảnh hưởng đến kết quả cuối cùng, nhưng vì số lượng phần tách ra ít hơn nên hiệu suất tính toán được cải thiện.

Nhìn quá trình này từ góc độ [hệ cơ số](./numeral-sys/base.md), ta đang tính trong một hệ cơ số lớn hơn (trong ví dụ trên, mỗi hai chữ số được tách thành một phần, có thể xem là tính trong hệ cơ số $100$), nhờ đó giảm số chữ số tham gia phép toán và cải thiện hiệu suất.

Đó chính là ý tưởng của **độ chính xác cao gộp chữ số**.

Dưới đây là mã cộng độ chính xác cao gộp chữ số, dùng để minh họa thêm cách cài đặt:

??? note "Cài đặt tham khảo phép cộng độ chính xác cao gộp chữ số"
    ```cpp
    // Cac mang a,b,c o day deu la so trong he co so p
    // Khi in dap an cuoi cung can chuyen so ve he thap phan
    void add(int a[], int b[], int c[]) {
      clear(c);
    
      for (int i = 0; i < LEN - 1; ++i) {
        c[i] += a[i] + b[i];
        if (c[i] >= p) {  // Trong phep toan do chinh xac cao thong thuong, p=10
          c[i + 1] += 1;
          c[i] -= p;
        }
      }
    }
    ```

<span id="&#21387;&#20301;&#39640;&#31934;&#19979;&#30340;&#39640;&#25928;&#31446;&#24335;&#38500;&#27861;"></span>
### Phép chia đặt dọc hiệu quả khi gộp chữ số

Khi dùng độ chính xác cao gộp chữ số, nếu vẫn thử thương bằng phương pháp đã giới thiệu ở trên, số lần thử thương sẽ rất nhiều và hằng số tính toán sẽ cực lớn. Chẳng hạn trong hệ cơ số mười nghìn, trung bình mỗi vị trí cần thử thương 5000 lần; hằng số lớn như vậy là không thể chấp nhận. Vì thế ta cần một cách thử thương hiệu quả hơn.

Ta có thể dùng `double` làm trung gian. Giả sử số bị chia có 4 chữ số là $a_4,a_3,a_2,a_1$, số chia có 3 chữ số là $b_3,b_2,b_1$. Khi đó ta chỉ cần thử một chữ số của thương: trong hệ cơ số $base$, dùng biểu thức $\dfrac{a_4 base + a_3}{b_3 + b_2 base^{-1} + (b_1+1)base^{-2}}$ để ước lượng thương. Với trường hợp nhiều chữ số, chỉ cần lặp cách làm một chữ số này. Vì dùng 3 chữ số độ chính xác của số chia để tham gia ước lượng, có thể bảo đảm quan hệ giữa thương ước lượng q' và thương thực q thỏa $q-1 \le q' \le q$, nên trong trường hợp xấu nhất mỗi vị trí cũng chỉ cần thử thương hai lần. Đồng thời, phương pháp này yêu cầu $base^3$ nằm trong độ chính xác hiệu dụng của `double`, tức $base^3 < 2^{53}$. Vì vậy khi dùng cách này, không nên vượt quá hệ cơ số 32768; nếu không rất dễ sinh sai số do thiếu độ chính xác và dẫn đến kết quả sai.

Ngoài ra, vì thương ước lượng luôn nhỏ hơn hoặc bằng thương thực, vẫn còn không gian tối ưu thêm. Trong phần lớn trường hợp, mỗi vị trí chỉ cần ước lượng thương một lần. Khi ước lượng ở vị trí kế tiếp, dù kết quả có thể do sai số ở vị trí trước khiến chữ số thương thử lớn hơn hoặc bằng base, điều đó vẫn không sao; chỉ cần xử lý nhớ thống nhất ở cuối. Ví dụ, giả sử base là 10 và cần tính $395081/9876$, các bước thử thương như sau:

1.  Trước hết, thử thương được $3950/988=3$, nên $395081-(9876 \times 3 \times 10^1) = 98801$. Bước này có sai số, nhưng không cần xử lý ngay, cứ tiếp tục bước sau.
2.  Tiếp tục thử thương với phần dư 98801, được $9880/988=10$, nên $98801-(9876 \times 10 \times 10^0) = 41$. Đây chính là số dư cuối cùng.
3.  Cộng các kết quả trong quá trình thử thương rồi xử lý nhớ, tức $3 \times 10^1 + 10 \times 10^0 = 40$, ta thu được thương chính xác.

Phương pháp nhìn qua khá đơn giản, nhưng khi cài đặt cụ thể rất dễ mắc lỗi. Vì vậy dưới đây cung cấp một cài đặt đã được kiểm chứng nhiều lần để tham khảo; các chi tiết cần chú ý cũng được viết trong chú thích.

??? note "Cài đặt tham khảo phép chia đặt dọc hiệu quả cho độ chính xác cao gộp chữ số"
    ```cpp
    // Mau va cai dat day du: https://baobaobear.github.io/post/20210228-bigint1/
    // Tru ket qua cua b nhan mul roi dich trai offset, phuc vu phep chia
    BigIntSimple &sub_mul(const BigIntSimple &b, int mul, int offset) {
      if (mul == 0) return *this;
      int borrow = 0;
      // Khac voi phep tru, borrow co the rat lon, nen khong the viet nhu phep tru thong thuong
      for (size_t i = 0; i < b.v.size(); ++i) {
        borrow += v[i + offset] - b.v[i] * mul - BIGINT_BASE + 1;
        v[i + offset] = borrow % BIGINT_BASE + BIGINT_BASE - 1;
        borrow /= BIGINT_BASE;
      }
      // Neu van con muon thi tiep tuc xu ly
      for (size_t i = b.v.size(); borrow; ++i) {
        borrow += v[i + offset] - BIGINT_BASE + 1;
        v[i + offset] = borrow % BIGINT_BASE + BIGINT_BASE - 1;
        borrow /= BIGINT_BASE;
      }
      return *this;
    }
    
    BigIntSimple div_mod(const BigIntSimple &b, BigIntSimple &r) const {
      BigIntSimple d;
      r = *this;
      if (absless(b)) return d;
      d.v.resize(v.size() - b.v.size() + 1);
      // Tinh truoc nghich dao cua ba chu so cao nhat cua so chia + 1; neu ba chu so cao nhat la a3,a2,a1
      // Thi db la nghich dao cua a3+a2/base+(a1+1)/base^2; cuoi cung dung phep nhan de uoc luong tung chu so thuong
      // Cach nay dung duoc trong pham vi int32 khi BIGINT_BASE<=32768
      // Nhung ngay ca khi dung int64, cung chi dung duoc khi BIGINT_BASE<=131072 (bi gioi han boi do chinh xac cua double)
      // Co the bao dam quan he giua ket qua uoc luong q' va ket qua thuc q la q'<=q<=q'+1
      // Vi vay moi chu so trung binh chi can thu thuong mot lan; sau do chi can xu ly nho thong nhat
      // Neu muon dung base lon hon, can thay bang phuong an thu thuong khac
      double t = (b.get((unsigned)b.v.size() - 2) +
                  (b.get((unsigned)b.v.size() - 3) + 1.0) / BIGINT_BASE);
      double db = 1.0 / (b.v.back() + t / BIGINT_BASE);
      for (size_t i = v.size() - 1, j = d.v.size() - 1; j <= v.size();) {
        int rm = r.get(i + 1) * BIGINT_BASE + r.get(i);
        int m = std::max((int)(db * rm), r.get(i + 1));
        r.sub_mul(b, m, j);
        d.v[j] += m;
        if (!r.get(i + 1))  // Kiem tra chu so cao nhat da bang 0 chua, tranh truong hop cuc doan
          --i, --j;
      }
      r.trim();
      // Hieu chinh hang don vi cua ket qua
      int carry = 0;
      while (!r.absless(b)) {
        r.subtract(b);
        ++carry;
      }
      // Hieu chinh phan nho cua tung hang
      for (size_t i = 0; i < d.v.size(); ++i) {
        carry += d.v[i];
        d.v[i] = carry % BIGINT_BASE;
        carry /= BIGINT_BASE;
      }
      d.trim();
      d.sign = sign * b.sign;
      return d;
    }
    
    BigIntSimple operator/(const BigIntSimple &b) const {
      BigIntSimple r;
      return div_mod(b, r);
    }
    
    BigIntSimple operator%(const BigIntSimple &b) const {
      BigIntSimple r;
      div_mod(b, r);
      return r;
    }
    ```

<span id="karatsuba-&#20056;&#27861;"></span>
## Phép nhân Karatsuba

Gọi số chữ số của số độ chính xác cao là $n$. Khi đó, phép nhân đặt dọc giữa hai số độ chính xác cao cần thời gian $O(n^2)$. Phần này giới thiệu một thuật toán có độ phức tạp thời gian tốt hơn, do nhà toán học Liên Xô cũ (Nga) Anatoly Karatsuba đề xuất; đây là một thuật toán chia để trị.

Xét hai số nguyên lớn hệ thập phân $x$ và $y$, đều gồm $n$ chữ số (có thể có các số không ở đầu). Chọn tùy ý $0 < m < n$, đặt

$$
\begin{aligned}
x &= x_1 \cdot 10^m + x_0, \\
y &= y_1 \cdot 10^m + y_0, \\
x \cdot y &= z_2 \cdot 10^{2m} + z_1 \cdot 10^m + z_0,
\end{aligned}
$$

Trong đó $x_0, y_0, z_0, z_1 < 10^m$. Ta có

$$
\begin{aligned}
z_2 &= x_1 \cdot y_1, \\
z_1 &= x_1 \cdot y_0 + x_0 \cdot y_1, \\
z_0 &= x_0 \cdot y_0.
\end{aligned}
$$

Quan sát thấy

$$
z_1 = (x_1 + x_0) \cdot (y_1 + y_0) - z_2 - z_0,
$$

Vì vậy, để tính $z_1$, chỉ cần tính $(x_1 + x_0) \cdot (y_1 + y_0)$ rồi trừ đi $z_0$ và $z_2$.

Công thức trên chính là lõi của thuật toán Karatsuba: nó chuyển bài toán nhân độ dài $n$ thành $3$ bài toán con có độ dài nhỏ hơn. Nếu lấy $m = \left\lceil \dfrac n 2 \right\rceil$, và gọi thời gian Karatsuba cần để nhân hai số nguyên $n$ chữ số là $T(n)$, ta có $T(n) = 3 \cdot T \left(\left\lceil \dfrac n 2 \right\rceil\right) + O(n)$. Theo định lý master, suy ra $T(n) = \Theta(n^{\log_2 3}) \approx \Theta(n^{1.585})$.

Toàn bộ quá trình có thể cài đặt bằng đệ quy. Để rõ ràng, đoạn mã dưới đây dùng thuật toán Karatsuba để cài đặt phép nhân đa thức, rồi cuối cùng mới xử lý toàn bộ phần nhớ.

??? note "karatsuba_mulc.cpp"
    ```cpp
    int *karatsuba_polymul(int n, int *a, int *b) {
      if (n <= 32) {
        // Khi kich thuoc nho, tinh truc tiep de tranh mat hieu suat do tiep tuc de quy
        int *r = new int[n * 2 + 1]();
        for (int i = 0; i <= n; ++i)
          for (int j = 0; j <= n; ++j) r[i + j] += a[i] * b[j];
        return r;
      }
    
      int m = n / 2 + 1;
      int *r = new int[m * 4 + 1]();
      int *z0, *z1, *z2;
    
      z0 = karatsuba_polymul(m - 1, a, b);
      z2 = karatsuba_polymul(n - m, a + m, b + m);
    
      // Tinh z1
      // Thay doi tam thoi, tinh xong thi khoi phuc
      for (int i = 0; i + m <= n; ++i) a[i] += a[i + m];
      for (int i = 0; i + m <= n; ++i) b[i] += b[i + m];
      z1 = karatsuba_polymul(m - 1, a, b);
      for (int i = 0; i + m <= n; ++i) a[i] -= a[i + m];
      for (int i = 0; i + m <= n; ++i) b[i] -= b[i + m];
      for (int i = 0; i <= (m - 1) * 2; ++i) z1[i] -= z0[i];
      for (int i = 0; i <= (n - m) * 2; ++i) z1[i] -= z2[i];
    
      // Ket hop z0, z1, z2 de thu duoc ket qua
      for (int i = 0; i <= (m - 1) * 2; ++i) r[i] += z0[i];
      for (int i = 0; i <= (m - 1) * 2; ++i) r[i + m] += z1[i];
      for (int i = 0; i <= (n - m) * 2; ++i) r[i + m * 2] += z2[i];
    
      delete[] z0;
      delete[] z1;
      delete[] z2;
      return r;
    }
    
    void karatsuba_mul(int a[], int b[], int c[]) {
      int *r = karatsuba_polymul(LEN - 1, a, b);
      memcpy(c, r, sizeof(int) * LEN);
      for (int i = 0; i < LEN - 1; ++i)
        if (c[i] >= 10) {
          c[i + 1] += c[i] / 10;
          c[i] %= 10;
        }
      delete[] r;
    }
    ```

??? note "Về `new` và `delete`"
    Xem [memory pool](../contest/common-tricks.md#%E5%86%85%E5%AD%98%E6%B1%A0).

Tuy nhiên, cách cài đặt này có một vấn đề: trong hệ cơ số $b$, mỗi hệ số của đa thức đều có thể đạt cấp độ $n \cdot b^2$, nên trong cài đặt độ chính xác cao gộp chữ số có thể gây tràn số nguyên. Nếu xử lý nhớ ngay trong quá trình nhân đa thức, kết quả của $x_1 + x_0$ và $y_1 + y_0$ có thể đạt $2 \cdot b^m$, làm tăng thêm một chữ số (nếu dùng cách tính $x_1 - x_0$ thì lại phải xử lý riêng trường hợp số âm). Vì vậy, cần dựa vào bối cảnh ứng dụng thực tế để quyết định dùng cách cài đặt nào.

<span id="&#22522;&#20110;&#22810;&#39033;&#24335;&#30340;&#39640;&#25928;&#22823;&#25972;&#25968;&#20056;&#27861;"></span>
## Phép nhân số nguyên lớn hiệu quả dựa trên đa thức

Nếu quy mô dữ liệu đạt $10^{10^5}$ hoặc lớn hơn, phép nhân độ chính xác cao thông thường có thể bị quá thời gian. Phần này giới thiệu cách dùng đa thức để tối ưu kiểu phép nhân này.

Với một số nguyên thập phân $a$ có $n$ chữ số, có thể xem nó như một đa thức mà hệ số ở mỗi vị trí đều là số nguyên không vượt quá $10$: $A=a_{0} 10^0+a_{1} 10^1+\cdots+a_{n-1} 10^{n-1}$. Như vậy, ta chuyển phép nhân hai số nguyên thành phép nhân hai đa thức.

Phép nhân đa thức thông thường vẫn có độ phức tạp thời gian $O(n^2)$, nhưng có thể tối ưu bằng các thuật toán trong phần đa thức như [biến đổi Fourier nhanh](poly/fft.md), [biến đổi số học nhanh](poly/ntt.md). Sau khi tối ưu, độ phức tạp thời gian là $O(n\log n)$.

<span id="&#23553;&#35013;&#31867;"></span>
## Lớp đóng gói

[Tại đây](https://paste.ubuntu.com/p/7VKYzpC7dn/) có một lớp số nguyên độ chính xác cao đã được đóng gói sẵn, và [tại đây](https://github.com/Baobaobear/MiniBigInteger/blob/main/bigint_tiny.h) là một lớp cài đặt siêu nhỏ hỗ trợ độ dài động cùng bốn phép toán cơ bản.

??? note "Đây là một mẫu khác"
    ```cpp
    constexpr int MAXN = 9999;
    // MAXN la so lon nhat trong mot hang
    constexpr int MAXSIZE = 10024;
    // MAXSIZE la so chu so
    constexpr int DLEN = 4;
    
    // DLEN ghi nhan so chu so duoc gop
    struct Big {
      int a[MAXSIZE], len;
      bool flag;  // Danh dau dau '-'
    
      Big() {
        len = 1;
        memset(a, 0, sizeof a);
        flag = false;
      }
    
      Big(const int);
      Big(const char*);
      Big(const Big&);
      Big& operator=(const Big&);
      Big operator+(const Big&) const;
      Big operator-(const Big&) const;
      Big operator*(const Big&) const;
      Big operator/(const int&) const;
      // TODO: Big / Big;
      Big operator^(const int&) const;
      // TODO: Big ^ Big;
    
      // TODO: Phep toan bit cho Big;
    
      int operator%(const int&) const;
      // TODO: Big ^ Big;
      bool operator<(const Big&) const;
      bool operator<(const int& t) const;
      void print() const;
    };
    
    Big::Big(const int b) {
      int c, d = b;
      len = 0;
      // memset(a,0,sizeof a);
      CLR(a);
      while (d > MAXN) {
        c = d - (d / (MAXN + 1) * (MAXN + 1));
        d = d / (MAXN + 1);
        a[len++] = c;
      }
      a[len++] = d;
    }
    
    Big::Big(const char* s) {
      int t, k, index, l;
      CLR(a);
      l = strlen(s);
      len = l / DLEN;
      if (l % DLEN) ++len;
      index = 0;
      for (int i = l - 1; i >= 0; i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if (k < 0) k = 0;
        g(j, k, i) t = t * 10 + s[j] - '0';
        a[index++] = t;
      }
    }
    
    Big::Big(const Big& T) : len(T.len) {
      CLR(a);
      f(i, 0, len) a[i] = T.a[i];
      // TODO: Nap chong o day?
    }
    
    Big& Big::operator=(const Big& T) {
      CLR(a);
      len = T.len;
      f(i, 0, len) a[i] = T.a[i];
      return *this;
    }
    
    Big Big::operator+(const Big& T) const {
      Big t(*this);
      int big = len;
      if (T.len > len) big = T.len;
      f(i, 0, big) {
        t.a[i] += T.a[i];
        if (t.a[i] > MAXN) {
          ++t.a[i + 1];
          t.a[i] -= MAXN + 1;
        }
      }
      if (t.a[big])
        t.len = big + 1;
      else
        t.len = big;
      return t;
    }
    
    Big Big::operator-(const Big& T) const {
      int big;
      bool ctf;
      Big t1, t2;
      if (*this < T) {
        t1 = T;
        t2 = *this;
        ctf = true;
      } else {
        t1 = *this;
        t2 = T;
        ctf = false;
      }
      big = t1.len;
      int j = 0;
      f(i, 0, big) {
        if (t1.a[i] < t2.a[i]) {
          j = i + 1;
          while (t1.a[j] == 0) ++j;
          --t1.a[j--];
          // WTF?
          while (j > i) t1.a[j--] += MAXN;
          t1.a[i] += MAXN + 1 - t2.a[i];
        } else
          t1.a[i] -= t2.a[i];
      }
      t1.len = big;
      while (t1.len > 1 && t1.a[t1.len - 1] == 0) {
        --t1.len;
        --big;
      }
      if (ctf) t1.a[big - 1] = -t1.a[big - 1];
      return t1;
    }
    
    Big Big::operator*(const Big& T) const {
      Big res;
      int up;
      int te, tee;
      f(i, 0, len) {
        up = 0;
        f(j, 0, T.len) {
          te = a[i] * T.a[j] + res.a[i + j] + up;
          if (te > MAXN) {
            tee = te - te / (MAXN + 1) * (MAXN + 1);
            up = te / (MAXN + 1);
            res.a[i + j] = tee;
          } else {
            up = 0;
            res.a[i + j] = te;
          }
        }
        if (up) res.a[i + T.len] = up;
      }
      res.len = len + T.len;
      while (res.len > 1 && res.a[res.len - 1] == 0) --res.len;
      return res;
    }
    
    Big Big::operator/(const int& b) const {
      Big res;
      int down = 0;
      gd(i, len - 1, 0) {
        res.a[i] = (a[i] + down * (MAXN + 1)) / b;
        down = a[i] + down * (MAXN + 1) - res.a[i] * b;
      }
      res.len = len;
      while (res.len > 1 && res.a[res.len - 1] == 0) --res.len;
      return res;
    }
    
    int Big::operator%(const int& b) const {
      int d = 0;
      gd(i, len - 1, 0) d = (d * (MAXN + 1) % b + a[i]) % b;
      return d;
    }
    
    Big Big::operator^(const int& n) const {
      Big t(n), res(1);
      int y = n;
      while (y) {
        if (y & 1) res = res * t;
        t = t * t;
        y >>= 1;
      }
      return res;
    }
    
    bool Big::operator<(const Big& T) const {
      int ln;
      if (len < T.len) return true;
      if (len == T.len) {
        ln = len - 1;
        while (ln >= 0 && a[ln] == T.a[ln]) --ln;
        if (ln >= 0 && a[ln] < T.a[ln]) return true;
        return false;
      }
      return false;
    }
    
    bool Big::operator<(const int& t) const {
      Big tee(t);
      return *this < tee;
    }
    
    void Big::print() const {
      printf("%d", a[len - 1]);
      gd(i, len - 2, 0) { printf("%04d", a[i]); }
    }
    
    void print(const Big& s) {
      int len = s.len;
      printf("%d", s.a[len - 1]);
      gd(i, len - 2, 0) { printf("%04d", s.a[i]); }
    }
    
    char s[100024];
    ```

<span id="&#20064;&#39064;"></span>
## Bài tập

-   [NOIP 2012 - King's Game](https://loj.ac/problem/2603)
-   [SPOJ - Fast Multiplication](http://www.spoj.com/problems/MUL/en/)
-   [SPOJ - GCD2](http://www.spoj.com/problems/GCD2/)
-   [UVa - Division](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1024)
-   [UVa - Fibonacci Freeze](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=436)
-   [Codeforces - Notepad](http://codeforces.com/contest/17/problem/D)

<span id="&#21442;&#32771;&#36164;&#26009;&#19982;&#38142;&#25509;"></span>
## Tài liệu tham khảo và liên kết

1.  [Karatsuba algorithm - Wikipedia](https://en.wikipedia.org/wiki/Karatsuba_algorithm)
