author: Xeonacid, NachtgeistW, 2014CAIS01, sshwy, Chrogeek, Menci, yzy-1

Trang này chủ yếu giới thiệu cách viết spj cho một số công cụ chấm/OJ.

## Giới thiệu

**Trình chấm đặc biệt** (Special Judge, viết tắt: spj, còn gọi là checker) là chương trình dùng để kiểm tra tính hợp lệ của đáp án khi một bài có nhiều lời giải hoặc nhiều đáp án đúng.

???+ warning "Cảnh báo"
    spj cũng nên kiểm tra cuối tệp có nội dung thừa hay không, và định dạng đầu ra có đúng hay không (ví dụ đề yêu cầu các số cách nhau bằng một dấu cách, nhưng thí sinh lại dùng xuống dòng). Tuy nhiên, hiện nay việc kiểm tra cuối tệp chỉ có Testlib làm được thuận tiện, còn kiểm tra định dạng kiểu này thì hầu như không ai cố ý làm riêng.

    Khi kiểm tra số thực, cần chú ý NaN. Cách kiểm tra không hợp lý có thể dẫn đến tình huống chỉ cần xuất NaN là AC.

    Khi đọc tệp của thí sinh, nên kiểm tra xem đã đọc đúng nội dung cần thiết hay chưa, để tránh làm spj bị lỗi chạy. Một số OJ xử lý lỗi chạy của spj như lỗi hệ thống.

???+ note "Ghi chú"
    Các ví dụ bên dưới đều dùng C++ làm ngôn ngữ lập trình, với tình huống mẫu: yêu cầu sai khác giữa đáp án chuẩn và đáp án thí sinh nhỏ hơn `1e-3`, tên tệp là `num`, và điểm tối đa của một test là 10.

## Testlib

Xem thêm: [Testlib/Giới thiệu](./testlib/index.md), [Testlib/Checker](./testlib/checker.md)

Testlib là một thư viện C++ hỗ trợ người ra đề viết bài thi thuật toán bằng C++.

Các công cụ chấm/OJ bắt buộc dùng Testlib làm spj: Codeforces, Luogu, UOJ, v.v.

Các công cụ chấm/OJ có thể dùng Testlib làm spj: LibreOJ ([Lyrio](https://github.com/lyrio-dev)), Lemon, Nowcoder, v.v.

Phiên bản Testlib đã chỉnh sửa cần cho SYZOJ 2 được lưu tại [pastebin](https://pastebin.com/3GANXMG7)[^1], nhưng phiên bản này chưa chỉnh sửa chế độ tương tác. Tại [syzoj/testlib](https://github.com/syzoj/testlib) có lưu một bản Testlib có thể dùng chế độ tương tác trên SYZOJ 2.

Phiên bản Testlib đã chỉnh sửa cần cho Lemon được lưu tại [GitHub - GitPinkRabbit/Testlib-for-Lemons](https://github.com/GitPinkRabbit/Testlib-for-Lemons). Chú ý rằng khi đăng ký checker bằng phiên bản Testlib này, nên dùng `registerLemonChecker()` thay vì `registerTestlibCmd()`. Phiên bản này kế thừa từ [bản cũ của matthew99](https://paste.ubuntu.com/p/JsTspHHnmB/) và bổ sung một số chức năng mới của Testlib. Nếu bạn dùng LemonLime, có thể dùng Testlib gốc.

Phiên bản Testlib đã chỉnh sửa cần cho DOMJudge được lưu tại [cn-xcpc-tools/testlib-for-domjudge](https://github.com/cn-xcpc-tools/testlib-for-domjudge). Phiên bản Testlib này có thể dùng đồng thời làm checker cho Special Judge và interactor cho bài tương tác.

Phiên bản Testlib đã chỉnh sửa cần cho Arbiter được lưu tại [testlib-for-arbiter](https://github.com/HeRaNO/ChickenRibs/tree/master/testlib-for-arbiter).

Với đa số công cụ chấm/OJ khác, cần chỉnh sửa Testlib theo định dạng spj của hệ thống đó, rồi tải `testlib.h` lên cùng spj; hoặc đặt `testlib.h` trong thư mục include.

```cpp
#include "testlib.h"
//
#include <cmath>

int main(int argc, char *argv[]) {
  /*
   * inf: đầu vào
   * ouf: đầu ra của thí sinh
   * ans: đầu ra chuẩn
   */
  registerTestlibCmd(argc, argv);

  double pans = ouf.readDouble(), jans = ans.readDouble();

  if (abs(pans - jans) < 1e-3)
    quitf(_ok, "Good job\n");
  else
    quitf(_wa, "Too big or too small, expected %f, found %f\n", jans, pans);
}
```

## Lemon

???+ note "Ghi chú"
    Lemon có sẵn phiên bản [Testlib](#testlib) đã chỉnh sửa, nên khuyến nghị dùng Testlib.

    Phiên bản LemonLime mới nhất đã hỗ trợ dùng Testlib gốc để viết checker; nếu bạn dùng LemonLime, khuyến nghị dùng Testlib.

```cpp
#include <cmath>
#include <cstdio>

int main(int argc, char* argv[]) {
  /*
   * argv[1]: đầu vào
   * argv[2]: đầu ra của thí sinh
   * argv[3]: đầu ra chuẩn
   * argv[4]: điểm của một test
   * argv[5]: ghi điểm cuối cùng (0 ~ argv[4])
   * argv[6]: ghi báo cáo lỗi
   */
  FILE* fin = fopen(argv[1], "r");
  FILE* fout = fopen(argv[2], "r");
  FILE* fstd = fopen(argv[3], "r");
  FILE* fscore = fopen(argv[5], "w");
  FILE* freport = fopen(argv[6], "w");

  double pans, jans;
  fscanf(fout, "%lf", &pans);
  fscanf(fstd, "%lf", &jans);

  if (abs(pans - jans) < 1e-3) {
    fprintf(fscore, "%s", argv[4]);
    fprintf(freport, "Good job\n");
  } else {
    fprintf(fscore, "%d", 0);
    fprintf(freport, "Too big or too small, expected %f, found %f\n", jans,
            pans);
  }
}
```

## Cena

```cpp
#include <cmath>
#include <cstdio>

int main(int argc, char* argv[]) {
  /*
   * FILENAME.in: đầu vào
   * FILENAME.out: đầu ra của thí sinh
   * argv[1]: điểm của một test
   * argv[2]: đầu ra chuẩn
   * score.log: ghi điểm cuối cùng (0 ~ argv[1])
   * report.log: ghi báo cáo lỗi
   */
  FILE* fin = fopen("num.in", "r");
  FILE* fout = fopen("num.out", "r");
  FILE* fstd = fopen(argv[2], "r");
  FILE* fscore = fopen("score.log", "w");
  FILE* freport = fopen("report.log", "w");

  double pans, jans;
  fscanf(fout, "%lf", &pans);
  fscanf(fstd, "%lf", &jans);

  if (abs(pans - jans) < 1e-3) {
    fprintf(fscore, "%s", argv[1]);
    fprintf(freport, "Good job\n");
  } else {
    fprintf(fscore, "%d", 0);
    fprintf(freport, "Too big or too small, expected %f, found %f\n", jans,
            pans);
  }
}
```

## CCR

```cpp
#include <cmath>
#include <cstdio>

int main(int argc, char* argv[]) {
  /*
   * stdin: đầu vào
   * argv[2]: đầu ra chuẩn
   * argv[3]: đầu ra của thí sinh
   * stdout:L1: ghi tỉ lệ điểm cuối cùng (0 ~ 1)
   * stdout:L2: ghi báo cáo lỗi
   */
  FILE* fout = fopen(argv[3], "r");
  FILE* fstd = fopen(argv[2], "r");

  double pans, jans;
  fscanf(fout, "%lf", &pans);
  fscanf(fstd, "%lf", &jans);

  if (abs(pans - jans) < 1e-3) {
    printf("%d\n", 1);
    printf("Good job\n");
  } else {
    printf("%d\n", 0);
    printf("Too big or too small, expected %f, found %f\n", jans, pans);
  }
}
```

## Arbiter

```cpp
#include <cmath>
#include <cstdio>

int main(int argc, char* argv[]) {
  /*
   * argv[1]: đầu vào
   * argv[2]: đầu ra của thí sinh
   * argv[3]: đầu ra chuẩn
   * /tmp/_eval.score:L1: ghi báo cáo lỗi
   * /tmp/_eval.score:L2: ghi điểm cuối cùng
   */
  FILE* fout = fopen(argv[2], "r");
  FILE* fstd = fopen(argv[3], "r");
  FILE* fscore = fopen("/tmp/_eval.score", "w");

  double pans, jans;
  fscanf(fout, "%lf", &pans);
  fscanf(fstd, "%lf", &jans);

  if (abs(pans - jans) < 1e-3) {
    fprintf(fscore, "Good job\n");
    fprintf(fscore, "%d", 10);
  } else {
    fprintf(fscore, "Too big or too small, expected %f, found %f\n", jans,
            pans);
    fprintf(fscore, "%d", 0);
  }
}
```

## HUSTOJ

```cpp
#include <cmath>
#include <cstdio>

#define AC 0
#define WA 1

int main(int argc, char* argv[]) {
  /*
   * argv[1]: đầu vào
   * argv[2]: đầu ra chuẩn
   * argv[3]: đầu ra của thí sinh
   * exit code: trả về kết quả chấm
   */
  FILE* fin = fopen(argv[1], "r");
  FILE* fout = fopen(argv[3], "r");
  FILE* fstd = fopen(argv[2], "r");

  double pans, jans;
  fscanf(fout, "%lf", &pans);
  fscanf(fstd, "%lf", &jans);

  if (abs(pans - jans) < 1e-3)
    return AC;
  else
    return WA;
}
```

## QDUOJ

So với các hệ thống trên, QDUOJ hơi phiền hơn. Bài có spj trên QDUOJ không có đầu ra chuẩn, nên chỉ có thể viết lời giải chuẩn vào trong spj; sau khi chạy ra đầu ra chuẩn thì mới so sánh.

```cpp
#include <cmath>
#include <cstdio>

#define AC 0
#define WA 1
#define ERROR -1

double solve(...) {
  // Lời giải chuẩn
}

int main(int argc, char* argv[]) {
  /*
   * argv[1]: đầu vào
   * argv[2]: đầu ra của thí sinh
   * exit code: trả về kết quả chấm
   */
  FILE* fin = fopen(argv[1], "r");
  FILE* fout = fopen(argv[2], "r");

  double pans, jans;
  fscanf(fout, "%lf", &pans);

  jans = solve(...);
  if (abs(pans - jans) < 1e-3)
    return AC;
  else
    return WA;
}
```

## HDOJ

Tình huống của HDOJ về cơ bản giống QDUOJ: cũng cần triển khai lời giải chuẩn trong spj rồi so sánh với đầu ra của thí sinh. Tuy nhiên, khác với QDUOJ, HDOJ sẽ so sánh đáp án với nội dung mà spj xuất ra làm đầu ra chuẩn rồi đưa ra kết quả cuối cùng. Vì vậy, khi tải đầu ra lên, chỉ cần tải đầu ra của spj trong trường hợp đúng.

HDOJ yêu cầu tải lên tệp nhị phân đã biên dịch trên Windows, không phải mã nguồn.

```cpp
#include <cmath>
#include <cstdio>

double solve(FILE* fin) {
  // Lời giải chuẩn, đọc đầu vào từ fin
}

int main(int argc, char* argv[]) {
  /*
   * argv[1]: đầu vào
   * stdin: đầu ra của thí sinh
   */
  FILE* fin = fopen(argv[1], "r");

  double pans, jans;
  if (scanf("%lf", &pans) != 1) {
    printf("WA\n");
    goto finish;
  }

  jans = solve(fin);
  if (abs(pans - jans) < 1e-3)
    printf("AC\n");
  else
    printf("WA\n");

finish:
  fclose(fin);
  return 0;
}
```

Tệp đáp án tương ứng là:

```text
AC
```

## SYZOJ 2

???+ note "Ghi chú"
    SYZOJ 2 có sẵn phiên bản [Testlib](#testlib) đã chỉnh sửa, nên khuyến nghị dùng Testlib.

    Phiên bản mới nhất của LibreOJ không còn dựa trên SYZOJ nữa, mà dựa trên [Lyrio](https://github.com/lyrio-dev/lyrio). Lyrio hỗ trợ dùng Testlib gốc để viết checker; đây cũng là cách tổng quát hơn và được khuyến nghị hơn.

```cpp
#include <cmath>
#include <cstdio>

int main(int argc, char* argv[]) {
  /*
   * in: đầu vào
   * user_out: đầu ra của thí sinh
   * answer: đầu ra chuẩn
   * code: mã nguồn của thí sinh
   * stdout: ghi điểm cuối cùng (0 ~ 100)
   * stderr: ghi báo cáo lỗi
   */
  FILE* fin = fopen("input", "r");
  FILE* fout = fopen("user_out", "r");
  FILE* fstd = fopen("answer", "r");
  FILE* fcode = fopen("code", "r");

  double pans, jans;
  fscanf(fout, "%lf", &pans);
  fscanf(fstd, "%lf", &jans);

  if (abs(pans - jans) < 1e-3) {
    printf("%d", 100);
    fprintf(stderr, "Good job\n");
  } else {
    printf("%d", 0);
    fprintf(stderr, "Too big or too small, expected %f, found %f\n", jans,
            pans);
  }
}
```

## Nowcoder

???+ note "Ghi chú"
    Nowcoder có sẵn phiên bản [Testlib](#testlib) đã chỉnh sửa, nên khuyến nghị dùng Testlib.

Xem thêm: [Cách ra bài lập trình Special Judge trên Nowcoder](https://www.nowcoder.com/discuss/84666)

```cpp
#include <cmath>
#include <cstdio>

#define AC 0
#define WA 1

int main(int argc, char* argv[]) {
  /*
   * input: đầu vào
   * user_output: đầu ra của thí sinh
   * output: đầu ra chuẩn
   * exit code: trả về kết quả chấm
   */
  FILE* fin = fopen("input", "r");
  FILE* fout = fopen("user_output", "r");
  FILE* fstd = fopen("output", "r");

  double pans, jans;
  fscanf(fout, "%lf", &pans);
  fscanf(fstd, "%lf", &jans);

  if (abs(pans - jans) < 1e-3)
    return AC;
  else
    return WA;
}
```

## DOMJudge

???+ note "Ghi chú"
    DOMJudge hỗ trợ spj viết bằng bất kỳ ngôn ngữ nào; xem: [định dạng trình kiểm tra đầu ra của problemarchive.org](https://www.problemarchive.org/wiki/index.php/Output_validator).

    DOMJudge có sẵn phiên bản [Testlib](#testlib) đã chỉnh sửa, nên khuyến nghị dùng Testlib.

Tài liệu về Testlib dùng cho DOMJudge và cách import gói bài Polygon: <https://github.com/cn-xcpc-tools/testlib-for-domjudge>

[Bộ so sánh mặc định](https://github.com/Kattis/problemtools/blob/master/support/default_validator/) của DOMJudge đã có sẵn so sánh số thực kèm độ chính xác; chỉ cần thêm `float_tolerance 1e-3` vào `validator_flags` trong cấu hình bài.

```cpp
#include <cmath>
#include <cstdio>

#define AC 42
#define WA 43
char reportfile[50];

int main(int argc, char* argv[]) {
  /*
   * argv[1]: đầu vào
   * argv[2]: đầu ra chuẩn
   * argv[3]: thư mục ghi thông tin chấm
   * stdin: đầu ra của thí sinh
   */
  FILE* fin = fopen(argv[1], "r");
  FILE* fstd = fopen(argv[2], "r");
  sprintf(reportfile, "%s/judgemessage.txt", argv[3]);
  FILE* freport = fopen(reportfile, "w");

  double pans, jans;
  scanf("%lf", &pans);
  fscanf(fstd, "%lf", &jans);

  if (abs(pans - jans) < 1e-3) {
    fprintf(freport, "Good job\n");
    return AC;
  } else {
    fprintf(freport, "Too big or too small, expected %f, found %f\n", jans,
            pans);
    return WA;
  }
}
```

Cũng có thể dùng tệp tiêu đề [validate.h](https://github.com/Kattis/problemtools/blob/master/examples/different/output_validators/different_validator/validate.h) do Kattis Problem Tools cung cấp để viết, nhằm triển khai các chức năng phức tạp hơn.

## Tài liệu tham khảo

[^1]: [LibreOJ da ho tro checker testlib!](https://loj.ac/article/124)
