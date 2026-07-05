## Cây chủ tịch

Cây chủ tịch là tên gọi thường dùng của cây phân đoạn bền vững trên miền giá trị.
Xem thêm [thảo luận trên Zhihu](https://www.zhihu.com/question/59195374).

???+ warning "Về cây phân đoạn hàm"
    **Cây phân đoạn hàm** là cây phân đoạn được xây dựng theo tư tưởng lập trình hàm.
    Trong lập trình hàm, phép tính của máy tính được xem như hàm toán học,
    đồng thời tránh trạng thái hoặc biến có thể thay đổi.
    Có thể thấy cây phân đoạn hàm là [hoàn toàn bền vững](persistent.md#hoàn-toàn-bền-vững-fully-persistent).

## Dẫn nhập

Trước hết xét một bài toán:
cho dãy $a$ gồm $n$ số nguyên,
với mỗi khoảng đóng $[l, r]$ được chỉ định,
truy vấn giá trị nhỏ thứ $k$ trong khoảng đó.

Một phương án khả thi là dùng cây chủ tịch.
Ý tưởng chính của cây chủ tịch là lưu lại phiên bản lịch sử sau mỗi thao tác chèn, từ đó truy vấn phần tử nhỏ thứ $k$
trong một đoạn.

Cách đơn giản nhất là mỗi lần tạo một cây phân đoạn mới.
Tuy nhiên, cách này tiêu tốn bộ nhớ quá lớn.

## Giải thích

Phân tích kỹ hơn, có thể thấy số nút bị sửa đổi trong mỗi thao tác sửa là như nhau.
(Ví dụ trong hình dưới, sửa nút tương ứng với giá trị 1 trong $[1,8]$;
các nút màu đỏ là các nút bị thay đổi.)
![](./images/persistent-seg.png)

Mỗi lần chỉ thay đổi $O(\log{n})$ nút và các nút đó tạo thành một đường từ gốc xuống lá. Nói cách khác, số nút thay đổi
mỗi lần bằng chiều cao của cây.
Chú ý rằng cây chủ tịch không thể dùng cách lưu kiểu heap,
tức không thể dùng $x\times 2$ và $x\times 2+1$ để biểu diễn con trái/phải.
Thay vào đó, cần cấp phát nút động và lưu chỉ số con trái/phải của từng nút.
Vì vậy, trên cơ sở đã lưu con trái/phải, chỉ cần lưu nút gốc tại thời điểm chèn từng số là có thể đạt được tính bền
vững.

Đơn giản hóa bài toán: mỗi lần chỉ cần tìm giá trị nhỏ thứ $k$ trong khoảng $[1,r]$.
Chỉ cần tìm phiên bản nút gốc sau khi đã chèn đến $r$,
rồi xử lý như trên cây phân đoạn theo giá trị thông thường
(còn gọi là cây phân đoạn khóa/miền giá trị).

Điều này khá dễ hiểu. Quay lại bài toán ban đầu: tìm giá trị nhỏ thứ $k$ trong khoảng $[l,r]$.
Lúc này liên hệ đến một kiến thức khác: **tổng tiền tố**.
Kỹ thuật nhỏ này tận dụng tính chất trừ đoạn: sau khi tiền xử lý, mỗi truy vấn có thể được trả lời trong $O(1)$.

Thông tin thống kê trong cây chủ tịch cũng thỏa tính chất này.
Vì vậy, nếu cần lấy thông tin thống kê của $[l,r]$, chỉ cần lấy thông tin của $[1,r]$ trừ đi thông tin của $[1,l - 1]$.

Đến đây, bài toán đã được giải quyết.

Về vấn đề không gian, phân tích như sau:
vì cấp phát nút động, một cây phân đoạn chỉ có $2n-1$ nút.
Sau đó có $n$ lần sửa, mỗi lần nhiều nhất tăng thêm $\lceil\log_2{n}\rceil+1$ nút.
Do đó trong trường hợp xấu nhất,
tổng số nút sau $n$ lần sửa đạt $2n-1+n(\lceil\log_2{n}\rceil+1)$.
Trong bài này $n \leq 10^5$,
mỗi lần sửa nhiều nhất tăng thêm $\lceil\log_2{10^5}\rceil+1 = 18$ nút,
nên tổng số nút sau $n$ lần sửa là $2\times 10^5-1+18\times 10^5$;
bỏ qua $-1$ thì xấp xỉ $20\times 10^5$.

Cuối cùng là một lưu ý thực tế: không nên cấp phát quá sát giới hạn ước tính.
Trong đa số bài, giới hạn bộ nhớ khá rộng nên thường không cần quá lo vượt bộ nhớ.
Có thể cấp $2^5\times 10^5$, gần gấp đôi dung lượng ước tính ban đầu, tức `n << 5`.

## Cài đặt

```cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
constexpr int MAXN = 1e5;  // Giới hạn dữ liệu
int tot, n, m;
int sum[(MAXN << 5) + 10], rt[MAXN + 10], ls[(MAXN << 5) + 10],
    rs[(MAXN << 5) + 10];
int a[MAXN + 10], ind[MAXN + 10], len;

int getid(const int &val) {  // Rời rạc hóa
  return lower_bound(ind + 1, ind + len + 1, val) - ind;
}

int build(int l, int r) {  // Xây cây
  int root = ++tot;
  if (l == r) return root;
  int mid = l + r >> 1;
  ls[root] = build(l, mid);
  rs[root] = build(mid + 1, r);
  return root;  // Trả về nút gốc của cây con này
}

int update(int k, int l, int r, int root) {  // Thao tác chèn
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

int query(int u, int v, int l, int r, int k) {  // Thao tác truy vấn
  int mid = l + r >> 1,
      x = sum[ls[v]] - sum[ls[u]];  // Số giá trị nằm trong con trái, tính bằng phép trừ đoạn
  if (l == r) return l;
  if (k <= x)  // Nếu k <= x, số nhỏ thứ k nằm trong con trái
    return query(ls[u], ls[v], l, mid, k);
  else  // Ngược lại, nó nằm trong con phải
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
    printf("%d\n", ind[query(rt[l - 1], rt[r], 1, len, k)]);  // Trả lời truy vấn
  }
}

int main() {
  init();
  work();
  return 0;
}
```

## Mở rộng: DSU bền vững dựa trên cây chủ tịch

Cây chủ tịch là một cách thuận tiện để cài đặt DSU bền vững. Dưới đây là một ví dụ cài đặt DSU bền vững dựa trên cây chủ
tịch.

```cpp
--8<-- "docs/ds/code/persistent-seg/persistent-seg_1.cpp"
```

## Tài liệu tham khảo

<https://en.wikipedia.org/wiki/Persistent_data_structure>

<https://www.cnblogs.com/zinthos/p/3899565.html>
