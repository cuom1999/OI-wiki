author: Ir1d, Anguei, hsfzLZH1, siger-young, HeRaNO, c8ef

Bài toán tính giá trị biểu thức thường nhận vào một chuỗi biểu diễn biểu thức và yêu cầu xuất ra giá trị của nó. Cũng có nhiều biến thể, chẳng hạn biểu thức có chứa ngoặc hay không, có phép lũy thừa hay không, có bao nhiêu biến, kiểm tra nhiều biểu thức có tương đương hay không, v.v.

Thông thường, biểu thức cần được phân tích cú pháp (grammar parsing) trước rồi mới tính giá trị; cũng có thể vừa phân tích vừa tính. Vai trò của phân tích cú pháp là kiểm tra chuỗi đầu vào có phải một biểu thức hợp lệ hay không, thường được giải quyết bằng một bộ phân tích cú pháp (parser).

Biểu thức gồm hai loại ký tự: toán hạng và toán tử. Với biểu thức có độ dài $n$, nếu dùng phương pháp phân tích phù hợp, có thể hoàn thành việc phân tích và tính giá trị trong độ phức tạp thời gian $O(n)$.

## Cây biểu thức và ký pháp Ba Lan ngược

Một cách phân tích biểu thức bằng đệ quy là xem biểu thức như các quy tắc ngữ pháp thông thường để phân tích. Sau khi phân tích, biểu thức được tách thành cây biểu thức như hình dưới, rồi thực hiện phép tính trên cấu trúc cây theo thứ tự từ dưới lên. ![](./images/bet.png)

Thực hiện [duyệt cây](../graph/tree-basic.md#duyệt-cây) trên cây biểu thức có thể thu được các loại biểu thức khác nhau. Biểu thức số học được chia thành ba loại: biểu thức tiền tố, biểu thức trung tố và biểu thức hậu tố. Biểu thức trung tố là dạng được dùng phổ biến nhất trong đời sống hằng ngày; biểu thức hậu tố là dạng máy tính dễ xử lý.

-   Duyệt tiền thứ tự tương ứng với biểu thức tiền tố (ký pháp Ba Lan)
-   Duyệt trung thứ tự tương ứng với biểu thức trung tố
-   Duyệt hậu thứ tự tương ứng với biểu thức hậu tố (ký pháp Ba Lan ngược)

Ký pháp Ba Lan ngược (biểu thức hậu tố) là một cách viết biểu thức toán học trong đó toán tử đứng sau các toán hạng của nó. Ví dụ, biểu thức sau:

$$
a+b*c*d+(e-f)*(g*h+i)
$$

có thể được viết bằng ký pháp Ba Lan ngược như sau:

$$
abc*d*+ef-gh*i+*+
$$

Do đó, ký pháp Ba Lan ngược tương ứng một-một với cây biểu thức. Ký pháp Ba Lan ngược không cần dùng ngoặc; thứ tự tính toán của nó được xác định duy nhất.

Điểm tiện lợi của ký pháp Ba Lan ngược là có thể tính nó trong thời gian tuyến tính. Ví dụ: trong biểu thức Ba Lan ngược $3~2~*~1~-$, trước hết tính $3 \times 2 = 6$ (dùng toán tử cuối cùng, tức toán tử ở đỉnh ngăn xếp), rồi tính $6 - 1 = 5$. Với một biểu thức Ba Lan ngược, chỉ cần **duy trì một ngăn xếp số; mỗi khi gặp một toán tử, lấy ra hai phần tử trên đỉnh ngăn xếp, rồi đẩy kết quả phép tính trở lại ngăn xếp**. Cuối cùng, phần tử duy nhất còn lại trong ngăn xếp chính là kết quả của biểu thức Ba Lan ngược đó. Thuật toán này có độ phức tạp thời gian $O(n)$.

Việc phân tích biểu thức bằng phương pháp đệ quy có thành công hay không phụ thuộc vào thiết kế quy tắc ngữ pháp có hợp lý hay không, tức là có thể thu được đúng cây biểu thức mong muốn hay không. Ví dụ:

$$
a+b*c
$$

Do độ ưu tiên của phép cộng và phép nhân khác nhau, biểu thức trung tố này có thể được chuyển thành hai cây biểu thức khác nhau. Việc thiết kế quy tắc ngữ pháp phụ thuộc rất nhiều vào độ ưu tiên của toán tử. Thiết kế các quy tắc ngữ pháp đệ quy tương ứng dựa trên độ ưu tiên của toán tử không đơn giản.

Phương pháp được giới thiệu dưới đây xem toán tử và độ ưu tiên của nó như một chỉnh thể, dùng cách không đệ quy để phân tích và tính biểu thức trực tiếp theo độ ưu tiên của toán tử.

## Biểu thức có ngoặc chỉ gồm toán tử nhị phân kết hợp trái

Xét một bài toán đơn giản hóa. Giả sử mọi toán tử đều là toán tử nhị phân: mỗi toán tử đều có hai đối số. Đồng thời, mọi toán tử đều kết hợp trái: nếu các toán tử có cùng độ ưu tiên thì thực hiện từ trái sang phải. Cho phép dùng ngoặc.

Để tính loại biểu thức trung tố này, có thể chuyển nó thành biểu thức hậu tố rồi tính. Định nghĩa hai [ngăn xếp](../ds/stack.md) để lần lượt lưu toán tử và toán hạng; mỗi khi gặp một số thì đưa trực tiếp vào ngăn xếp toán hạng. Mỗi khối toán tử tương ứng với một cặp ngoặc, và ngăn xếp toán tử chỉ đơn điệu bên trong từng khối toán tử. Mỗi khi gặp một toán tử, cần xét các phần tử trong khối toán tử trên cùng của ngăn xếp toán tử; bên trong khối đó, thực hiện thao tác pop phù hợp sao cho các toán tử được giữ theo thứ tự giảm dần của độ ưu tiên, đồng thời tính giá trị của biểu thức con tương ứng với toán tử được pop ra.

Trong phần dưới đây, "xuất" nghĩa là xuất ra biểu thức hậu tố: tức là đặt số đó lên ngăn xếp toán hạng, hoặc pop một toán tử và hai toán hạng, tính xong rồi đẩy kết quả trở lại ngăn xếp toán hạng. Quét biểu thức trung tố từ trái sang phải:

1.  Nếu gặp số, xuất trực tiếp số đó.
2.  Nếu gặp dấu ngoặc trái, đưa nó vào ngăn xếp toán tử.
3.  Nếu gặp dấu ngoặc phải, liên tục xuất phần tử trên đỉnh ngăn xếp cho đến khi gặp dấu ngoặc trái, rồi pop dấu ngoặc trái. Nói cách khác, thực hiện mọi toán tử bên trong cặp ngoặc đó.
4.  Nếu gặp toán tử khác, liên tục xuất tất cả các toán tử có độ ưu tiên lớn hơn hoặc bằng toán tử hiện tại. Cuối cùng, đưa toán tử mới vào ngăn xếp toán tử.
5.  Sau khi xử lý hết toàn bộ chuỗi, một số toán tử có thể vẫn còn trong ngăn xếp, vì vậy lần lượt xuất các ký hiệu còn lại trong ngăn xếp; quá trình chuyển đổi biểu thức kết thúc.

Dưới đây là hiện thực của phương pháp này cho bốn toán tử $+$, $-$, $*$, $/$:

??? note "Mã ví dụ"
    ```cpp
    
    bool delim(char c) { return c == ' '; }
    
    bool is_op(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }
    
    int priority(char op) {
      if (op == '+' || op == '-') return 1;
      if (op == '*' || op == '/') return 2;
      return -1;
    }
    
    void process_op(stack<int>& st, char op) {  // Cũng có thể dùng để tính biểu thức hậu tố
      int r = st.top();                         // Lấy phần tử đỉnh ngăn xếp, lưu ý thứ tự
      st.pop();
      int l = st.top();
      st.pop();
      switch (op) {
        case '+':
          st.push(l + r);
          break;
        case '-':
          st.push(l - r);
          break;
        case '*':
          st.push(l * r);
          break;
        case '/':
          st.push(l / r);
          break;
      }
    }
    
    int evaluate(string& s) {  // Cũng có thể sửa thành chuyển biểu thức trung tố sang hậu tố
      stack<int> st;
      stack<char> op;
      for (int i = 0; i < (int)s.size(); i++) {
        if (delim(s[i])) continue;
    
        if (s[i] == '(') {
          op.push('(');  // 2. Nếu gặp dấu ngoặc trái, đưa nó vào ngăn xếp toán tử
        } else if (s[i] == ')') {  // 3. Nếu gặp dấu ngoặc phải, thực hiện mọi toán tử trong cặp ngoặc
          while (op.top() != '(') {
            process_op(st, op.top());
            op.pop();  // Liên tục xuất phần tử đỉnh ngăn xếp cho đến khi gặp dấu ngoặc trái
          }
          op.pop();                // Pop dấu ngoặc trái
        } else if (is_op(s[i])) {  // 4. Nếu gặp toán tử khác
          char cur_op = s[i];
          while (!op.empty() && priority(op.top()) >= priority(cur_op)) {
            process_op(st, op.top());
            op.pop();  // Liên tục xuất mọi toán tử có độ ưu tiên lớn hơn hoặc bằng toán tử hiện tại
          }
          op.push(cur_op);  // Đưa toán tử mới vào ngăn xếp toán tử
        } else {            // 1. Nếu gặp số, xuất trực tiếp số đó
          int number = 0;
          while (i < (int)s.size() && isalnum(s[i]))
            number = number * 10 + s[i++] - '0';
          --i;
          st.push(number);
        }
      }
    
      while (!op.empty()) {
        process_op(st, op.top());
        op.pop();
      }
      return st.top();
    }
    
    ```

Thuật toán tính giá trị biểu thức bằng cách dùng ngầm ký pháp Ba Lan ngược này có độ phức tạp thời gian $O(n)$. Chỉ cần sửa nhẹ hiện thực trên, cũng có thể thu được ký pháp Ba Lan ngược ở dạng tường minh.

### Toán tử một ngôi và toán tử kết hợp phải

Bây giờ giả sử biểu thức còn chứa toán tử một ngôi, tức toán tử chỉ có một đối số. Dấu cộng một ngôi và dấu trừ một ngôi là các ví dụ thường gặp về toán tử một ngôi.

Một điểm khác biệt trong tình huống này là cần xác định toán tử hiện tại là toán tử một ngôi hay toán tử nhị phân.

Lưu ý rằng trước một toán tử một ngôi thường là một toán tử khác hoặc dấu ngoặc mở; nếu toán tử một ngôi nằm ở đầu biểu thức thì không có gì đứng trước nó. Trước toán tử nhị phân thì luôn có một toán hạng hoặc dấu ngoặc phải. Vì vậy, có thể đánh dấu liệu toán tử tiếp theo có thể là toán tử một ngôi hay không.

Ngoài ra, cần thực hiện toán tử một ngôi và toán tử nhị phân theo các cách khác nhau, đồng thời đặt độ ưu tiên của toán tử một ngôi cao hơn mọi toán tử nhị phân. Cần lưu ý rằng một số toán tử một ngôi, chẳng hạn cộng một ngôi và trừ một ngôi, thực chất là kết hợp phải.

Kết hợp phải nghĩa là mỗi khi độ ưu tiên bằng nhau, các toán tử phải được tính từ phải sang trái.

Như đã nói ở trên, toán tử một ngôi thường kết hợp phải. Một ví dụ khác về toán tử kết hợp phải là toán tử lũy thừa. Với $a \wedge b \wedge c$, thông thường nó được xem là $a^{b^c}$ chứ không phải $(a^b)^c$.

Để xử lý đúng loại toán tử này, thay đổi tương ứng là: nếu độ ưu tiên bằng nhau, cần trì hoãn thao tác pop toán tử ra khỏi ngăn xếp.

Đoạn mã cần thay đổi như sau. Thay:

```cpp

while (!op.empty() && priority(op.top()) >= priority(cur_op)) 
```

bằng

```cpp

while (!op.empty() &&
       ((left_assoc(cur_op) && priority(op.top()) >= priority(cur_op)) ||
        (!left_assoc(cur_op) && priority(op.top()) > priority(cur_op))))

```

trong đó left\_assoc là một hàm quyết định toán tử có kết hợp trái hay không.

Dưới đây là hiện thực cho các toán tử nhị phân $+$, $-$, $*$, $/$ và các toán tử một ngôi $+$, $-$:

??? note "Mã ví dụ"
    ```cpp
    
    bool delim(char c) { return c == ' '; }
    
    bool is_op(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }
    
    bool is_unary(char c) { return c == '+' || c == '-'; }
    
    int priority(char op) {
      if (op < 0)  // toán tử một ngôi
        return 3;
      if (op == '+' || op == '-') return 1;
      if (op == '*' || op == '/') return 2;
      return -1;
    }
    
    void process_op(stack<int>& st, char op) {
      if (op < 0) {
        int l = st.top();
        st.pop();
        switch (-op) {
          case '+':
            st.push(l);
            break;
          case '-':
            st.push(-l);
            break;
        }
      } else {  // Lấy phần tử đỉnh ngăn xếp, lưu ý thứ tự
        int r = st.top();
        st.pop();
        int l = st.top();
        st.pop();
        switch (op) {
          case '+':
            st.push(l + r);
            break;
          case '-':
            st.push(l - r);
            break;
          case '*':
            st.push(l * r);
            break;
          case '/':
            st.push(l / r);
            break;
        }
      }
    }
    
    int evaluate(string& s) {
      stack<int> st;
      stack<char> op;
      bool may_be_unary = true;
      for (int i = 0; i < (int)s.size(); i++) {
        if (delim(s[i])) continue;
    
        if (s[i] == '(') {
          op.push('(');  // 2. Nếu gặp dấu ngoặc trái, đưa nó vào ngăn xếp toán tử
          may_be_unary = true;
        } else if (s[i] == ')') {  // 3. Nếu gặp dấu ngoặc phải, thực hiện mọi toán tử trong cặp ngoặc
          while (op.top() != '(') {
            process_op(st, op.top());
            op.pop();  // Liên tục xuất phần tử đỉnh ngăn xếp cho đến khi gặp dấu ngoặc trái
          }
          op.pop();  // Pop dấu ngoặc trái
          may_be_unary = false;
        } else if (is_op(s[i])) {  // 4. Nếu gặp toán tử khác
          char cur_op = s[i];
          if (may_be_unary && is_unary(cur_op)) cur_op = -cur_op;
          while (!op.empty() &&
                 ((cur_op >= 0 && priority(op.top()) >= priority(cur_op)) ||
                  (cur_op < 0 && priority(op.top()) > priority(cur_op)))) {
            process_op(st, op.top());
            op.pop();  // Liên tục xuất mọi toán tử có độ ưu tiên lớn hơn hoặc bằng toán tử hiện tại
          }
          op.push(cur_op);  // Đưa toán tử mới vào ngăn xếp toán tử
          may_be_unary = true;
        } else {  // 1. Nếu gặp số, xuất trực tiếp số đó
          int number = 0;
          while (i < (int)s.size() && isalnum(s[i]))
            number = number * 10 + s[i++] - '0';
          --i;
          st.push(number);
          may_be_unary = false;
        }
      }
    
      while (!op.empty()) {
        process_op(st, op.top());
        op.pop();
      }
      return st.top();
    }
    
    ```

## Tài liệu tham khảo

**Trang này chủ yếu được dịch từ bài viết [Разбор выражений. Обратная польская нотация](https://e-maxx.ru/algo/expressions_parsing) và bản dịch tiếng Anh của nó, [Expression parsing](https://cp-algorithms.com/string/expression_parsing.html). Phiên bản tiếng Nga được cấp phép theo Public Domain + Leave a Link; phiên bản tiếng Anh được cấp phép theo CC-BY-SA 4.0.**

## Đọc thêm

1.  [Bộ phân tích cú pháp theo độ ưu tiên toán tử](https://en.wikipedia.org/wiki/Operator-precedence_parser)
2.  [Thuật toán shunting yard](https://en.wikipedia.org/wiki/Shunting_yard_algorithm)

## Bài tập

1.  [NOIP2013 nhóm phổ thông: Đánh giá biểu thức](https://www.luogu.com.cn/problem/P1981)
2.  [Biểu thức hậu tố](https://www.luogu.com.cn/problem/P1449)
3.  [Biến đổi biểu thức](https://www.spoj.com/problems/ONP/)
