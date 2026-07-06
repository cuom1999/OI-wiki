Trình kiểm tra đáp án (checker), tức [trình chấm đặc biệt](../special-judge.md),
dùng để kiểm tra đáp án có hợp lệ hay không. Dùng Testlib giúp giảm bớt nhiều
chi tiết cần tự kiểm tra, nên việc viết trình kiểm tra đơn giản hơn đáng kể.

Trình kiểm tra đọc tên tệp đầu vào, tên tệp đầu ra của thí sinh và tên tệp đầu
ra chuẩn qua tham số dòng lệnh, sau đó xác định đầu ra của thí sinh có đúng hay
không và trả về một kết quả chấm đã định nghĩa trước.

Nên đọc [Thông dụng](./general.md) trước khi đọc tiếp.

## Ví dụ đơn giản

???+ note "Đề bài"
    Cho hai số nguyên $a,b$ ($-1000 \le a,b \le 1000$), cần in ra tổng của chúng.

Bài này không cần trình kiểm tra. Tuy nhiên, nếu cần thì vẫn có thể viết một
trình kiểm tra như sau:

```cpp
#include "testlib.h"

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);

  int pans = ouf.readInt(-2000, 2000, "sum of numbers");

  // Giả định đầu ra chuẩn là đúng, không kiểm tra phạm vi của nó.
  // Phần sau sẽ chỉ ra vì sao điều này không hợp lý.
  int jans = ans.readInt();

  if (pans == jans)
    quitf(_ok, "The sum is correct.");
  else
    quitf(_wa, "The sum is wrong: expected = %d, found = %d", jans, pans);
}
```

## Viết hàm readAns

Giả sử có một bài mà đầu vào và đầu ra đều chứa nhiều số, chẳng hạn: cho một DAG,
cần tìm đường đi dài nhất từ $s$ đến $t$ và in ra đường đi đó (có thể có nhiều
đường, in ra một đường bất kỳ).

Dưới đây là một ví dụ về trình kiểm tra **chưa tốt**.

### Cài đặt chưa tốt

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
  int m = inf.readInt();  // Vì không cần kiểm tra tính hợp lệ của đầu vào chuẩn
                          // trong trình kiểm tra đáp án (đã có trình xác thực dữ liệu)
  for (int i = 0; i < m; i++) {
    int a = inf.readInt();
    int b = inf.readInt();
    int w = inf.readInt();
    edges[make_pair(a, b)] = edges[make_pair(b, a)] = w;
  }
  int s = inf.readInt();
  int t = inf.readInt();

  // Đọc đầu ra chuẩn
  int jvalue = 0;
  vector<int> jpath;
  int jlen = ans.readInt();
  for (int i = 0; i < jlen; i++) {
    jpath.push_back(ans.readInt());
  }
  for (int i = 0; i < jlen - 1; i++) {
    jvalue += edges[make_pair(jpath[i], jpath[i + 1])];
  }

  // Đọc đầu ra của thí sinh
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

Trình kiểm tra này có hai vấn đề chính:

1.  Nó mặc định đầu ra chuẩn là đúng. Nếu đầu ra của thí sinh tốt hơn đầu ra
    chuẩn, thí sinh sẽ bị chấm WA, điều này không ổn. Đồng thời, nếu đầu ra chuẩn
    không hợp lệ thì cũng sẽ dẫn đến WA. Trong cả hai trường hợp, thao tác đúng
    là trả về trạng thái Fail.
2.  Phần mã đọc đầu ra chuẩn và đầu ra của thí sinh bị lặp. Với bài này, viết
    hai lần phần đọc không phải vấn đề lớn, vì chỉ cần một vòng `for`; nhưng nếu
    gặp bài có đầu ra phức tạp, trình kiểm tra sẽ trở nên rối. Mã lặp làm giảm
    mạnh khả năng bảo trì và khiến việc gỡ lỗi hoặc sửa định dạng khó hơn.

Cách đọc đầu ra chuẩn và đầu ra của thí sinh hoàn toàn giống nhau. Vì vậy, người
ta thường viết một hàm đọc nhận luồng làm tham số.

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
// Khi luồng stream là ans, mọi stream.quitf(_wa, ...)
// và mọi readXxx() thất bại đều trả về _fail thay vì _wa.
// Nói cách khác, nếu đầu ra không hợp lệ, với luồng đầu ra của thí sinh
// hàm này trả về _wa, còn với luồng đầu ra chuẩn nó trả về _fail.
int readAns(InStream& stream) {
  // Đọc đầu ra
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

Cách viết này đồng thời kiểm tra cả đầu ra chuẩn có hợp lệ hay không, giúp trình kiểm tra ngắn hơn, dễ hiểu hơn và dễ gỡ lỗi hơn. Cách viết này cũng áp dụng được cho các bài có đầu ra YES (kèm một phương án nào đó), hoặc NO.

???+ note "Ghi chú"
    Một số kiểm tra ràng buộc có thể được viết gọn hơn bằng hàm `InStream::ensure/ensuref()`. Ví dụ, dòng 23 đến 25 trong ví dụ trên cũng có thể được viết tương đương như sau:
    
    ```cpp
    stream.ensuref(!used[v - 1], "vertex %d was used twice", v);
    ```

???+ warning "Cảnh báo"
    Tránh gọi hàm **toàn cục** `::ensure/ensuref()` trong `readAns`, vì điều này có thể làm trình kiểm tra trả về `_fail` cho một số đầu ra của thí sinh đáng lẽ phải bị chấm WA, từ đó tạo ra kết quả sai.

## Khuyến nghị và lỗi thường gặp

-   Viết hàm `readAns`; cách này giúp trình kiểm tra rõ ràng và chắc chắn hơn.

-   Khi đọc đầu ra của thí sinh, luôn giới hạn phạm vi cụ thể. Nếu quên giới hạn một số biến rồi dùng chúng làm đối số, trình kiểm tra có thể chấm sai, RE, v.v.

    -   Ví dụ phản diện

    ```cpp
    // ....
    int k = ouf.readInt();
    vector<int> lst;
    for (int i = 0; i < k; i++)  // k = 0 và k = -5 có tác dụng như nhau trong đoạn này (không vào vòng lặp)
      lst.push_back(ouf.readInt());
    // Nhưng trình kiểm tra đáp án không nên chấp nhận một danh sách có độ dài -5.
    // ....
    int pos = ouf.readInt();
    int x = A[pos];
    // Có thể có người in ra -42, 2147483456 hoặc số không hợp lệ khác làm trình kiểm tra đáp án RE
    ```

    -   Ví dụ đúng

    ```cpp
    // ....
    int k = ouf.readInt(0, n);  // Độ dài không hợp lệ sẽ bị WA ngay, không tiếp tục kiểm tra rồi RE
    vector<int> lst;
    for (int i = 0; i < k; i++) lst.push_back(ouf.readInt());
    // ....
    int pos = ouf.readInt(0, (int)A.size() - 1);  // Tránh vượt phạm vi
    int x = A[pos];
    // ....
    ```

-   Dùng bí danh cho hạng mục.

-   Khác với trình xác thực dữ liệu, trình kiểm tra không cần cố ý kiểm tra các ký tự không trắng. Ví dụ, với một trình kiểm tra so sánh các số nguyên theo thứ tự, chỉ cần xác định các số nguyên trong đầu ra của thí sinh có lần lượt bằng các số nguyên trong đáp án hay không; trình kiểm tra không cần quan tâm thí sinh in mỗi số trên một dòng hay in tất cả số trên cùng một dòng.

## Cách dùng

Thông thường không cần chạy trình kiểm tra cục bộ, vì công cụ chấm/OJ sẽ xử lý
các bước cần thiết. Nhưng nếu cần, có thể chạy trên dòng lệnh theo định dạng sau:

```bash
./checker <input-file> <output-file> <answer-file> [<report-file> [<-appes>]]
```

## Một số trình kiểm tra có sẵn

Trong nhiều trường hợp, công việc của trình kiểm tra khá đơn giản, chẳng hạn
kiểm tra đầu ra có đúng là số nguyên không, hoặc đầu ra là số thực có thỏa sai số
yêu cầu không. [Testlib](https://github.com/MikeMirzayanov/testlib/tree/master/checkers)
đã cung cấp sẵn các cài đặt trình kiểm tra này, và có thể dùng trực tiếp.

Một số trình kiểm tra thường dùng:

-   ncmp: so sánh tuần tự các số nguyên 64 bit.
-   rcmp4: so sánh tuần tự các số thực, sai số chấp nhận được tối đa (sai số tuyệt đối hoặc tương đối) không vượt quá $10^{-4}$ (còn có rcmp6, rcmp9, v.v. cho các yêu cầu độ chính xác khác nhau, cách dùng tương tự rcmp4).
-   wcmp: so sánh tuần tự các chuỗi (không chứa dấu cách, xuống dòng hoặc ký tự không trắng khác).
-   yesno: so sánh YES và NO, không phân biệt chữ hoa chữ thường.

    **Bài viết này chủ yếu được dịch từ [Checkers with testlib.h - Codeforces](https://codeforces.com/blog/entry/18431). Kho GitHub của `testlib.h` là [MikeMirzayanov/testlib](https://github.com/MikeMirzayanov/testlib).**
