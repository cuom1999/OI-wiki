Checker, tức [Special Judge](../special-judge.md), dùng để kiểm tra đáp án có hợp lệ hay không. Dùng Testlib giúp ta không phải tự kiểm tra nhiều chi tiết, nên việc viết checker đơn giản hơn đáng kể.

Checker đọc tên tệp input, tên tệp output của thí sinh và tên tệp output chuẩn từ tham số dòng lệnh, sau đó xác định output của thí sinh có đúng hay không và trả về một kết quả đã định nghĩa trước.

Hãy đọc [Thông dụng](./general.md) trước khi đọc tiếp.

## Ví dụ đơn giản

???+ note "Đề bài"
    Cho hai số nguyên $a,b$ ($-1000 \le a,b \le 1000$), hãy in ra tổng của chúng.

Bài này rõ ràng không cần checker, đúng không? Nhưng nếu thật sự cần thì cũng có thể viết một checker như sau:

```cpp
#include "testlib.h"

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);

  int pans = ouf.readInt(-2000, 2000, "sum of numbers");

  // Giả định output chuẩn là đúng, không kiểm tra phạm vi của nó.
  // Lát nữa ta sẽ thấy điều này không hợp lý.
  int jans = ans.readInt();

  if (pans == jans)
    quitf(_ok, "The sum is correct.");
  else
    quitf(_wa, "The sum is wrong: expected = %d, found = %d", jans, pans);
}
```

## Viết hàm readAns

Giả sử bạn có một bài mà input và output đều chứa nhiều số, chẳng hạn: cho một DAG, hãy tìm đường đi dài nhất từ $s$ đến $t$ và in ra đường đi đó (có thể có nhiều đường, in ra một đường bất kỳ).

Dưới đây là một ví dụ checker **không tốt**.

### Cài đặt không tốt

```cpp
#include "testlib.h"
//
#include <map>
#include <vector>
using namespace std;

map<pair<int, int>, int> edges;

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  int n = inf.readInt();  // Không cần readSpace() hoặc readEoln()
  int m = inf.readInt();  // Vì không cần kiểm tra tính hợp lệ của input chuẩn
                          // trong checker (đã có validator)
  for (int i = 0; i < m; i++) {
    int a = inf.readInt();
    int b = inf.readInt();
    int w = inf.readInt();
    edges[make_pair(a, b)] = edges[make_pair(b, a)] = w;
  }
  int s = inf.readInt();
  int t = inf.readInt();

  // Đọc output chuẩn
  int jvalue = 0;
  vector<int> jpath;
  int jlen = ans.readInt();
  for (int i = 0; i < jlen; i++) {
    jpath.push_back(ans.readInt());
  }
  for (int i = 0; i < jlen - 1; i++) {
    jvalue += edges[make_pair(jpath[i], jpath[i + 1])];
  }

  // Đọc output của thí sinh
  int pvalue = 0;
  vector<int> ppath;
  vector<bool> used(n);
  int plen = ouf.readInt(2, n, "number of vertices");  // Ít nhất có s và t
  for (int i = 0; i < plen; i++) {
    int v = ouf.readInt(1, n, format("path[%d]", i + 1).c_str());
    if (used[v - 1])  // Kiểm tra mỗi đỉnh chỉ được dùng một lần
      quitf(_wa, "vertex %d was used twice", v);
    used[v - 1] = true;
    ppath.push_back(v);
  }
  // Kiểm tra tính hợp lệ của đỉnh đầu và đỉnh cuối
  if (ppath.front() != s)
    quitf(_wa, "path doesn't start in s: expected s = %d, found %d", s,
          ppath.front());
  if (ppath.back() != t)
    quitf(_wa, "path doesn't finish in t: expected t = %d, found %d", t,
          ppath.back());
  // Kiểm tra giữa hai đỉnh kề nhau có cạnh hay không
  for (int i = 0; i < plen - 1; i++) {
    if (edges.find(make_pair(ppath[i], ppath[i + 1])) == edges.end())
      quitf(_wa, "there is no edge (%d, %d) in the graph", ppath[i],
            ppath[i + 1]);
    pvalue += edges[make_pair(ppath[i], ppath[i + 1])];
  }

  if (jvalue != pvalue)
    quitf(_wa, "jury has answer %d, participant has answer %d", jvalue, pvalue);
  else
    quitf(_ok, "answer = %d", pvalue);
}
```

Checker này chủ yếu có hai vấn đề:

1.  Nó tin chắc output chuẩn là đúng. Nếu output của thí sinh tốt hơn output chuẩn, thí sinh sẽ bị chấm WA, điều này không ổn. Đồng thời, nếu output chuẩn không hợp lệ thì cũng sẽ sinh WA. Trong cả hai trường hợp, thao tác đúng là trả về trạng thái Fail.
2.  Phần mã đọc output chuẩn và output của thí sinh bị lặp. Với bài này, viết hai lần phần đọc không phải vấn đề lớn, vì chỉ cần một vòng `for`; nhưng nếu gặp bài có output phức tạp, checker sẽ trở nên rối. Mã lặp làm giảm mạnh khả năng bảo trì và khiến việc debug hoặc sửa định dạng khó hơn.

Cách đọc output chuẩn và output của thí sinh thực ra hoàn toàn giống nhau. Đây là lý do ta thường viết một hàm đọc nhận luồng làm tham số.

### Cài đặt tốt

```cpp
// clang-format off

#include "testlib.h"
#include <map>
#include <vector>
using namespace std;

map<pair<int, int>, int> edges;
int n, m, s, t;

// Hàm này nhận một luồng để đọc từ đó,
// kiểm tra tính hợp lệ của đường đi và trả về độ dài đường đi.
// Khi stream là ans, mọi stream.quitf(_wa, ...)
// và mọi readXxx() thất bại đều trả về _fail thay vì _wa.
// Nói cách khác, nếu output không hợp lệ, với luồng output của thí sinh
// hàm này trả về _wa, còn với luồng output chuẩn nó trả về _fail.
int readAns(InStream& stream) {
  // Đọc output
  int value = 0;
  vector<int> path;
  vector<bool> used(n);
  int len = stream.readInt(2, n, "number of vertices");
  for (int i = 0; i < len; i++) {
    int v = stream.readInt(1, n, format("path[%d]", i + 1).c_str());
    if (used[v - 1]) {
      stream.quitf(_wa, "vertex %d was used twice", v);
    }
    used[v - 1] = true;
    path.push_back(v);
  }
  if (path.front() != s)
    stream.quitf(_wa, "path doesn't start in s: expected s = %d, found %d", s,
                 path.front());
  if (path.back() != t)
    stream.quitf(_wa, "path doesn't finish in t: expected t = %d, found %d", t,
                 path.back());
  for (int i = 0; i < len - 1; i++) {
    if (edges.find(make_pair(path[i], path[i + 1])) == edges.end())
      stream.quitf(_wa, "there is no edge (%d, %d) in the graph", path[i],
                   path[i + 1]);
    value += edges[make_pair(path[i], path[i + 1])];
  }
  return value;
}

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  n = inf.readInt();
  m = inf.readInt();
  for (int i = 0; i < m; i++) {
    int a = inf.readInt();
    int b = inf.readInt();
    int w = inf.readInt();
    edges[make_pair(a, b)] = edges[make_pair(b, a)] = w;
  }
  s = inf.readInt();
  t = inf.readInt();

  int jans = readAns(ans);
  int pans = readAns(ouf);
  if (jans > pans)
    quitf(_wa, "jury has the better answer: jans = %d, pans = %d\n", jans,
          pans);
  else if (jans == pans)
    quitf(_ok, "answer = %d\n", pans);
  else  // (jans < pans)
    quitf(_fail, ":( participant has the better answer: jans = %d, pans = %d\n",
          jans, pans);
}
```

Có thể thấy cách viết này đồng thời kiểm tra cả output chuẩn có hợp lệ hay không, giúp checker ngắn hơn, dễ hiểu hơn và dễ debug hơn. Cách viết này cũng áp dụng được cho các bài có output YES (kèm một phương án nào đó), hoặc NO.

???+ note "Ghi chú"
    Một số kiểm tra ràng buộc có thể được viết gọn hơn bằng hàm `InStream::ensure/ensuref()`. Ví dụ, dòng 23 đến 25 trong ví dụ trên cũng có thể được viết tương đương như sau:
    
    ```cpp
    stream.ensuref(!used[v - 1], "vertex %d was used twice", v);
    ```

???+ warning "Cảnh báo"
    Hãy tránh gọi hàm **toàn cục** `::ensure/ensuref()` trong `readAns`, vì điều này có thể làm checker trả về `_fail` cho một số output của thí sinh đáng lẽ phải bị chấm WA, từ đó tạo ra kết quả sai.

## Khuyến nghị và lỗi thường gặp

-   Viết hàm `readAns`; nó thật sự có thể làm checker của bạn tốt hơn rất nhiều.

-   Khi đọc output của thí sinh, luôn giới hạn phạm vi rõ ràng. Nếu quên giới hạn một số biến rồi dùng chúng làm tham số, checker của bạn có thể chấm sai, RE, v.v.

    -   Ví dụ phản diện

    ```cpp
    // ....
    int k = ouf.readInt();
    vector<int> lst;
    for (int i = 0; i < k; i++)  // k = 0 và k = -5 có tác dụng như nhau ở đây (không vào vòng lặp)
      lst.push_back(ouf.readInt());
    // Nhưng ta không muốn chấp nhận một list có độ dài -5, đúng không?
    // ....
    int pos = ouf.readInt();
    int x = A[pos];
    // Có thể có người in ra -42, 2147483456 hoặc số không hợp lệ khác làm checker RE
    ```

    -   Ví dụ đúng

    ```cpp
    // ....
    int k = ouf.readInt(0, n);  // Độ dài không hợp lệ sẽ bị WA ngay, không tiếp tục check rồi RE
    vector<int> lst;
    for (int i = 0; i < k; i++) lst.push_back(ouf.readInt());
    // ....
    int pos = ouf.readInt(0, (int)A.size() - 1);  // Tránh out of range
    int x = A[pos];
    // ....
    ```

-   Dùng bí danh hạng mục.

-   Khác với validator, checker không cần cố ý kiểm tra các ký tự không trắng. Ví dụ, với một checker so sánh các số nguyên theo thứ tự, ta chỉ cần xác định các số nguyên trong output của thí sinh có lần lượt bằng các số nguyên trong đáp án hay không; checker không cần quan tâm thí sinh in mỗi số trên một dòng hay in tất cả số trên cùng một dòng.

## Cách dùng

Thông thường ta không cần chạy checker cục bộ, vì công cụ chấm/OJ sẽ làm mọi việc. Nhưng nếu cần, có thể chạy trên dòng lệnh theo định dạng sau:

```bash
./checker <input-file> <output-file> <answer-file> [<report-file> [<-appes>]]
```

## Một số checker có sẵn

Trong nhiều trường hợp, công việc checker cần làm rất đơn giản, chẳng hạn kiểm tra output là số nguyên có đúng không, hoặc output là số thực có thỏa sai số yêu cầu không. [Testlib](https://github.com/MikeMirzayanov/testlib/tree/master/checkers) đã cung cấp sẵn các cài đặt checker này, và ta có thể dùng trực tiếp.

Một số checker thường dùng:

-   ncmp: so sánh tuần tự các số nguyên 64 bit.
-   rcmp4: so sánh tuần tự các số thực, sai số chấp nhận được tối đa (sai số tuyệt đối hoặc tương đối) không vượt quá $10^{-4}$ (còn có rcmp6, rcmp9, v.v. cho các yêu cầu độ chính xác khác nhau, cách dùng tương tự rcmp4).
-   wcmp: so sánh tuần tự các chuỗi (không chứa dấu cách, xuống dòng hoặc ký tự không trắng khác).
-   yesno: so sánh YES và NO, không phân biệt chữ hoa chữ thường.

    **Bài viết này chủ yếu được dịch từ [Checkers with testlib.h - Codeforces](https://codeforces.com/blog/entry/18431). Kho GitHub của `testlib.h` là [MikeMirzayanov/testlib](https://github.com/MikeMirzayanov/testlib).**
