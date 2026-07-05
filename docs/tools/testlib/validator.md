Kiến thức cần biết trước: [Thông dụng](./general.md)

Trang này giới thiệu ngắn gọn khái niệm và cách dùng trình xác thực dữ liệu (validator).

## Tổng quan

Trình xác thực dữ liệu dùng để kiểm tra tính hợp lệ của dữ liệu đã tạo. Khi đã tạo xong dữ liệu cho một bài nhưng vẫn lo dữ liệu không hợp lệ (không thỏa ràng buộc của đề: tràn số, đồ thị không liên thông, không phải cây, v.v.), người ra đề thường dùng validator để kiểm tra.[^ref1]

Vì Codeforces hỗ trợ tính năng hack, mọi bài trên Codeforces đều bắt buộc phải có validator. UOJ cũng như vậy. [Polygon](../polygon.md) có sẵn hỗ trợ cho validator.

## Cách dùng

Chỉ cần nhập trực tiếp `./val` trên dòng lệnh. Dữ liệu được đưa vào qua `stdin` (đầu vào chuẩn). Nếu muốn nhập từ tệp, có thể dùng `./val < a.in`.

Nếu dữ liệu không có vấn đề, chương trình sẽ không in gì và trả về 0; nếu không, chương trình sẽ in thông báo lỗi và trả về một giá trị khác 0.

## Gợi ý

-   Khi viết validator, không được đưa ra bất kỳ giả định nào về dữ liệu đang được kiểm tra, vì nó có thể chứa bất cứ thứ gì. Vì vậy, người ra đề cần xét đủ các trường hợp không hợp lệ (Testlib sẽ đơn giản hóa đáng kể quá trình này).
    -   Ví dụ, với đầu vào là một cây có $n$ đỉnh, công việc chính là kiểm tra $n$ có nằm trong phạm vi hay không và đầu vào có thật sự là cây hay không. Tuy nhiên, tuyệt đối không được chỉ kiểm tra phạm vi của $n$ rồi bỏ qua việc kiểm tra phạm vi đầu mút của các cạnh tiếp theo, nếu không validator có thể RE.
    -   Ngay cả khi không RE, cũng không nên bỏ kiểm tra, vì thông báo lỗi sẽ không chính xác. Trong ví dụ trên, nếu không kiểm tra, lỗi có thể là "không phải cây", nhưng lỗi đúng phải là "đầu mút của cạnh không nằm trong $[1,n]$".
-   Không được đưa ra bất kỳ giả định nào về cách thí sinh đọc đầu vào. Vì vậy, dữ liệu được validator chấp nhận phải hoàn toàn tuân thủ định dạng đầu vào.
    -   Ví dụ, thí sinh có thể đọc số theo từng ký tự và chỉ đọc một dấu cách giữa hai số. Do đó, khi viết validator, mọi ký tự trắng trong dữ liệu đều phải được đọc tường minh trong validator (chẳng hạn dấu cách và xuống dòng).
-   Đừng quên gọi `inf.readEof()` khi kết thúc.
-   Nếu bài cho phép hack (nói cách khác, thông báo lỗi của validator sẽ được người khác nhìn thấy), hãy làm thông báo lỗi thân thiện nhất có thể.
    -   Dùng "bí danh hạng mục" khi đọc biến.
    -   Khi biểu thức dùng để kiểm tra không dễ hiểu, dùng `ensuref` thay vì `ensure`.

## Ví dụ

Dưới đây là validator của [CF Gym 100541A - Stock Market](https://codeforces.com/gym/100541/problem/A):

```cpp
#include "testlib.h"

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int testCount = inf.readInt(1, 10, "testCount");
  inf.readEoln();

  for (int i = 0; i < testCount; i++) {
    int n = inf.readInt(1, 100, "n");
    inf.readSpace();
    inf.readInt(1, 1000000, "w");
    inf.readEoln();

    for (int i = 0; i < n; ++i) {
      inf.readInt(1, 1000, "p_i");
      if (i < n - 1) inf.readSpace();
    }
    inf.readEoln();
  }

  inf.readEof();
}
```

## Liên kết ngoài

-   [Thêm ví dụ về validator](https://github.com/MikeMirzayanov/testlib/tree/master/validators)
-   [Kho GitHub của `testlib.h`: MikeMirzayanov/testlib](https://github.com/MikeMirzayanov/testlib)

## Tài liệu tham khảo và chú thích

[^ref1]: [Validators with testlib.h - Codeforces](https://codeforces.com/blog/entry/18426)
