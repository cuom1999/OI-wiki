author: Dev-jqe, HeRaNO, huaruoji

## Công dụng thường gặp

Trong lập trình thi đấu, đôi khi cần duy trì thông tin nhiều chiều. Trường hợp đó thường có thể dùng cấu trúc
"cây lồng cây" để ghi lại thông tin. Khi cần duy trì tiền nhiệm, kế nhiệm, phần tử lớn thứ $k$, thứ hạng của một số,
hoặc thao tác chèn/xóa, tầng trong có thể dùng cây cân bằng; cấu trúc thu được là cây phân đoạn lồng cây cân bằng.

## Quy trình

Dùng bài **cây cân bằng thông thường nâng cao** làm ví dụ để giải thích nguyên lý cài đặt.

Khi xây cây lồng cây, tầng ngoài vẫn là cây phân đoạn như bình thường. Với mỗi nút trên cây phân đoạn, xây một cây
cân bằng chứa đoạn dãy mà nút đó bao phủ. Khi cài đặt, có thể lần lượt chèn từng phần tử của dãy; mỗi khi đi qua một
nút cây phân đoạn, thêm phần tử đó vào cây cân bằng của nút này.

Thao tác 1, tìm thứ hạng của một giá trị trong một khoảng: thực hiện truy vấn bình thường trên cây phân đoạn ngoài.
Với cây cân bằng của các nút nằm trong khoảng cần xét, trả về số phần tử nhỏ hơn giá trị đó. Khi gộp các đoạn, chỉ
cần cộng các số lượng phần tử nhỏ hơn. Cuối cùng lấy giá trị trả về cộng $1$, đó là thứ hạng của giá trị trong khoảng.

Thao tác 2, tìm giá trị có thứ hạng $k$ trong một khoảng: có thể dùng chiến lược nhị phân. Vì một phần tử có thể xuất
hiện nhiều lần, thứ hạng của nó là một đoạn, và một số giá trị có thể không tồn tại trong dãy ban đầu. Do đó dùng ý
tưởng tương tự thao tác 1: lấy số phần tử nhỏ hơn giá trị đang xét làm căn cứ nhị phân, từ đó tìm được đáp án.

Thao tác 3, thay một số bằng một số khác: chỉ cần xóa số cũ khỏi mọi cây cân bằng chứa nó, rồi chèn số mới vào. Tầng
ngoài vẫn thao tác trên cây phân đoạn như bình thường.

Thao tác 4, tìm tiền nhiệm của một giá trị trong một khoảng: thực hiện truy vấn bình thường trên cây phân đoạn ngoài.
Với cây cân bằng của các nút nằm trong khoảng cần xét, trả về tiền nhiệm của giá trị đó. Khi gộp kết quả của các đoạn
cây phân đoạn, lấy giá trị lớn nhất.

## Tính chất

### Độ phức tạp không gian

Mỗi phần tử được thêm vào $O(\log n)$ cây cân bằng, nên độ phức tạp không gian là $O((n + q)\log{n})$.

### Độ phức tạp thời gian

-   Với các thao tác 1, 3, 4, cần thực hiện $O(\log{n})$ thao tác trên cây phân đoạn ngoài; mỗi thao tác lại thực hiện
    $O(\log{n})$ thao tác trên một cây cân bằng trong, nên độ phức tạp thời gian là $O(\log^2{n})$.
-   Với thao tác 2, có thêm một quá trình nhị phân, nên độ phức tạp là $O(\log^3{n})$.

## Bài ví dụ kinh điển

[Cây cân bằng thông thường nâng cao](https://loj.ac/problem/106): tầng ngoài là cây phân đoạn, tầng trong là cây cân bằng.

## Cài đặt

Mã phần cây cân bằng có thể tham khảo các mục khác như [Splay](./splay.md).

Thao tác 1:

```cpp
int vec_rank(int k, int l, int r, int x, int y, int t) {
  if (x <= l && r <= y) {
    return spy[k].chk_rank(t);
  }
  int mid = l + r >> 1;
  int res = 0;
  if (x <= mid) res += vec_rank(k << 1, l, mid, x, y, t);
  if (y > mid) res += vec_rank(k << 1 | 1, mid + 1, r, x, y, t);
  if (x <= mid && y > mid) res--;
  return res;
}
```

Thao tác 2:

```cpp
int el = 0, er = 100000001, emid;
while (el != er) {
  emid = el + er >> 1;
  if (vec_rank(1, 1, n, tl, tr, emid) - 1 < tk)
    el = emid + 1;
  else
    er = emid;
}
printf("%d\n", el - 1);
```

Thao tác 3:

```cpp
void vec_chg(int k, int l, int r, int loc, int x) {
  int t = spy[k].find(dat[loc]);
  spy[k].dele(t);
  spy[k].insert(x);
  if (l == r) return;
  int mid = l + r >> 1;
  if (loc <= mid) vec_chg(k << 1, l, mid, loc, x);
  if (loc > mid) vec_chg(k << 1 | 1, mid + 1, r, loc, x);
}
```

Thao tác 4:

```cpp
int vec_front(int k, int l, int r, int x, int y, int t) {
  if (x <= l && r <= y) return spy[k].chk_front(t);
  int mid = l + r >> 1;
  int res = 0;
  if (x <= mid) res = max(res, vec_front(k << 1, l, mid, x, y, t));
  if (y > mid) res = max(res, vec_front(k << 1 | 1, mid + 1, r, x, y, t));
  return res;
}
```

## Thuật toán liên quan

Khi gặp bài toán có thông tin nhiều chiều, nếu đề không bắt buộc xử lý trực tuyến, có thể cân nhắc các thuật toán chia
để trị như [chia để trị CDQ](../misc/cdq-divide.md) hoặc [nhị phân song song](../misc/parallel-binsearch.md) để tránh
dùng cấu trúc dữ liệu nâng cao và giảm độ khó cài đặt.
