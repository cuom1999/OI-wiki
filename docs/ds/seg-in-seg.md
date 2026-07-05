author: Chrogeek, HeRaNO, Dev-XYS, Dev-jqe

## Công dụng thường gặp

Trong lập trình thi đấu, đôi khi cần duy trì thông tin nhiều chiều. Trường hợp đó thường có thể dùng cấu trúc
"cây lồng cây" để ghi lại thông tin.

## Nguyên lý cài đặt

Xét cách dùng cây lồng cây để thực hiện sửa một điểm và truy vấn vùng trên mặt phẳng hai chiều. Có thể đặt cây
phân đoạn ở tầng ngoài; các cây con tại $1$ đến $n$ nút lá lần lượt biểu diễn cây phân đoạn của hàng thứ $1$ đến
hàng thứ $n$. Khi đó, nút cha tương ứng của các nút lá này biểu diễn vùng hợp của hai vùng con.

## Tính chất

### Độ phức tạp không gian

Thông thường, không thể xây một cây phân đoạn con cho mọi nút của cây phân đoạn ngoài, vì yêu cầu không gian quá
lớn. Cây lồng cây thường dùng chiến lược mở nút động. Một lần sửa đi qua $\log{n}$ nút của cây phân đoạn ngoài; với
mỗi nút đó, cây con tương ứng lại đi qua $\log{n}$ nút, nên không gian phát sinh bởi một lần sửa nhiều nhất là
$\log^2{n}$.

### Độ phức tạp thời gian

Với thao tác truy vấn, cần thực hiện $\log{n}$ thao tác trên cây phân đoạn ngoài; mỗi thao tác lại thực hiện
$\log{n}$ thao tác trên một cây phân đoạn trong, nên độ phức tạp thời gian là $\log^2{n}$.
Thao tác sửa có cùng độ phức tạp với truy vấn, cũng là $\log^2{n}$.

## Bài ví dụ kinh điển

[Mạch thượng hoa khai](https://www.luogu.com.cn/problem/P3810) sắp xếp theo chiều thứ nhất, rồi dùng cây lồng cây để
duy trì chiều thứ hai và chiều thứ ba.

## Mã ví dụ

Truy vấn chiều thứ hai

```cpp
int tree_query(int k, int l, int r, int x) {
  if (k == 0) return 0;
  if (1 <= l && r <= sec[x].y) return vec_query(ou_root[k], 1, p, 1, sec[x].z);
  int mid = l + r >> 1, res = 0;
  if (1 <= mid) res += tree_query(ou_ch[k][0], l, mid, x);
  if (sec[x].y > mid) res += tree_query(ou_ch[k][1], mid + 1, r, x);
  return res;
}
```

Sửa chiều thứ hai

```cpp
void tree_insert(int &k, int l, int r, int x) {
  if (k == 0) k = ++ou_tot;
  vec_insert(ou_root[k], 1, p, sec[x].z);
  if (l == r) return;
  int mid = l + r >> 1;
  if (sec[x].y <= mid)
    tree_insert(ou_ch[k][0], l, mid, x);
  else
    tree_insert(ou_ch[k][1], mid + 1, r, x);
}
```

Truy vấn chiều thứ ba

```cpp
int vec_query(int k, int l, int r, int x, int y) {
  if (k == 0) return 0;
  if (x <= l && r <= y) return data[k];
  int mid = l + r >> 1, res = 0;
  if (x <= mid) res += vec_query(ch[k][0], l, mid, x, y);
  if (y > mid) res += vec_query(ch[k][1], mid + 1, r, x, y);
  return res;
}
```

Sửa chiều thứ ba

```cpp
void vec_insert(int &k, int l, int r, int loc) {
  if (k == 0) k = ++tot;
  data[k]++;
  if (l == r) return;
  int mid = l + r >> 1;
  if (loc <= mid) vec_insert(ch[k][0], l, mid, loc);
  if (loc > mid) vec_insert(ch[k][1], mid + 1, r, loc);
}
```

## Thuật toán liên quan

Khi gặp bài toán có thông tin nhiều chiều, nếu đề không bắt buộc xử lý trực tuyến, có thể cân nhắc các thuật toán chia
để trị như **chia để trị CDQ** hoặc **nhị phân song song** để tránh dùng cấu trúc dữ liệu nâng cao và giảm độ khó cài
đặt.
