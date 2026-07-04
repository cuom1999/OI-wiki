## Cây chủ tịch

Cây chủ tịch là tên gọi thường dùng của cây phân đoạn theo giá trị có tính bền vững. Xem thêm [thảo luận trên Zhihu](https://www.zhihu.com/question/59195374).

???+ warning "Về cây phân đoạn hàm"
    **Cây phân đoạn hàm** là cây phân đoạn được xây dựng theo tư tưởng lập trình hàm. Trong lập trình hàm, phép tính của máy tính được xem như hàm toán học, đồng thời tránh trạng thái hoặc biến có thể thay đổi. Không khó để thấy cây phân đoạn hàm là [hoàn toàn bền vững](persistent.md#hoàn-toàn-bền-vững-fully-persistent).

## Dẫn nhập

Trước hết xét một bài toán: cho dãy $a$ gồm $n$ số nguyên, với mỗi khoảng đóng $[l, r]$ được chỉ định, hãy truy vấn giá trị nhỏ thứ $k$ trong khoảng đó.

Bạn sẽ giải quyết như thế nào?

Một phương án khả thi là dùng cây chủ tịch.
Ý tưởng chính của cây chủ tịch là lưu lại phiên bản lịch sử sau mỗi thao tác chèn, để tiện truy vấn phần tử nhỏ thứ $k$ trong một đoạn.

Lưu như thế nào? Cách đơn giản thô bạo là mỗi lần tạo một cây phân đoạn mới.
Vậy chẳng phải bộ nhớ sẽ nổ tung sao?

## Giải thích

Phân tích một chút, ta thấy số nút bị sửa đổi trong mỗi thao tác sửa là như nhau.
(Ví dụ trong hình dưới, ta sửa nút tương ứng với giá trị 1 trong $[1,8]$; các nút màu đỏ là các nút bị thay đổi.)
![](./images/persistent-seg.png)

Mỗi lần chỉ thay đổi $O(\log{n})$ nút và các nút đó tạo thành một chuỗi; nói cách khác, số nút thay đổi mỗi lần bằng chiều cao của cây.
Chú ý rằng cây chủ tịch không thể dùng cách lưu kiểu heap, tức không thể dùng $x\times 2$ và $x\times 2+1$ để biểu diễn con trái/phải. Thay vào đó, cần cấp phát nút động và lưu chỉ số con trái/phải của từng nút.
Vì vậy, chỉ cần lưu nút gốc tại thời điểm chèn từng số, trên cơ sở đã lưu con trái/phải, là có thể đạt được tính bền vững.

Đơn giản hóa bài toán: mỗi lần chỉ cần tìm giá trị nhỏ thứ $k$ trong khoảng $[1,r]$.
Làm thế nào? Chỉ cần tìm phiên bản nút gốc sau khi đã chèn đến $r$, rồi xử lý như trên cây phân đoạn theo giá trị thông thường (còn gọi là cây phân đoạn khóa/miền giá trị).

Điều này khá dễ hiểu. Quay lại bài toán ban đầu: tìm giá trị nhỏ thứ $k$ trong khoảng $[l,r]$.
Ở đây ta liên hệ đến một kiến thức khác: **tổng tiền tố**.
Kỹ thuật nhỏ này khéo léo tận dụng tính chất trừ đoạn, nhờ tiền xử lý để trả lời mỗi truy vấn trong $O(1)$.

Ta có thể thấy thông tin thống kê trong cây chủ tịch cũng thỏa tính chất này.
Vì vậy, nếu cần lấy thông tin thống kê của $[l,r]$, chỉ cần lấy thông tin của $[1,r]$ trừ đi thông tin của $[1,l - 1]$.

Đến đây, bài toán đã được giải quyết.

Về vấn đề không gian, phân tích như sau: vì ta cấp phát nút động, nên một cây phân đoạn chỉ có $2n-1$ nút.
Sau đó có $n$ lần sửa, mỗi lần nhiều nhất tăng thêm $\lceil\log_2{n}\rceil+1$ nút. Do đó trong trường hợp xấu nhất, tổng số nút sau $n$ lần sửa đạt $2n-1+n(\lceil\log_2{n}\rceil+1)$.
Trong bài này $n \leq 10^5$, mỗi lần sửa nhiều nhất tăng thêm $\lceil\log_2{10^5}\rceil+1 = 18$ nút, nên tổng số nút sau $n$ lần sửa là $2\times 10^5-1+18\times 10^5$; bỏ qua $-1$ thì xấp xỉ $20\times 10^5$.

Cuối cùng là một lời khuyên: đừng quá tiết kiệm không gian (trong đa số bài, giới hạn bộ nhớ khá rộng, nên thường không cần quá lo vượt bộ nhớ). Cứ mạnh dạn cấp $2^5\times 10^5$, gần gấp đôi dung lượng ước tính ban đầu, tức `n << 5`.

## Cài đặt

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
constexpr int MAXN = 1e5;  // Gioi han du lieu
int tot, n, m;
int sum[(MAXN << 5) + 10], rt[MAXN + 10], ls[(MAXN << 5) + 10],
    rs[(MAXN << 5) + 10];
int a[MAXN + 10], ind[MAXN + 10], len;

int getid(const int &val) {  // Roi rac hoa
  return lower_bound(ind + 1, ind + len + 1, val) - ind;
}

int build(int l, int r) {  // Xay cay
  int root = ++tot;
  if (l == r) return root;
  int mid = l + r >> 1;
  ls[root] = build(l, mid);
  rs[root] = build(mid + 1, r);
  return root;  // Tra ve nut goc cua cay con nay
}

int update(int k, int l, int r, int root) {  // Thao tac chen
  int dir = ++tot;
  ls[dir] = ls[root], rs[dir] = rs[root], sum[dir] = sum[root] + 1;
  if (l == r) return dir;
  int mid = l + r >> 1;
  if (k <= mid)
    ls[dir] = update(k, l, mid, ls[dir]);
  else
    rs[dir] = update(k, mid + 1, r, rs[dir]);
  return dir;
}

int query(int u, int v, int l, int r, int k) {  // Thao tac truy van
  int mid = l + r >> 1,
      x = sum[ls[v]] - sum[ls[u]];  // So gia tri nam trong con trai, tinh bang phep tru doan
  if (l == r) return l;
  if (k <= x)  // Neu k <= x, so nho thu k nam trong con trai
    return query(ls[u], ls[v], l, mid, k);
  else  // Nguoc lai, no nam trong con phai
    return query(rs[u], rs[v], mid + 1, r, k - x);
}

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  memcpy(ind, a, sizeof ind);
  sort(ind + 1, ind + n + 1);
  len = unique(ind + 1, ind + n + 1) - ind - 1;
  rt[0] = build(1, len);
  for (int i = 1; i <= n; ++i) rt[i] = update(getid(a[i]), 1, len, rt[i - 1]);
}

int l, r, k;

void work() {
  while (m--) {
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", ind[query(rt[l - 1], rt[r], 1, len, k)]);  // Tra loi truy van
  }
}

int main() {
  init();
  work();
  return 0;
}
```

## Mở rộng: DSU bền vững dựa trên cây chủ tịch

Cây chủ tịch là một cách thuận tiện để cài đặt DSU bền vững. Dưới đây cũng cung cấp một ví dụ cài đặt DSU bền vững dựa trên cây chủ tịch.

```cpp
--8<-- "docs/ds/code/persistent-seg/persistent-seg_1.cpp"
```

## Tài liệu tham khảo

<https://en.wikipedia.org/wiki/Persistent_data_structure>

<https://www.cnblogs.com/zinthos/p/3899565.html>
