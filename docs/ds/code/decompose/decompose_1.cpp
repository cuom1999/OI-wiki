#include <cmath>
#include <iostream>
using namespace std;
int id[50005], len;
// id lưu chỉ số khối, len = sqrt(n), tức s trong lời giải trên; độ phức tạp
// tối ưu khi lấy căn bậc hai.
long long a[50005], b[50005], s[50005];

// a là mảng dữ liệu; b ghi phần cộng toàn khối, tương tự tag lười; s lưu tổng
// các phần tử trong khối.
void add(int l, int r, long long x) {  // Cộng trên đoạn
  int sid = id[l], eid = id[r];
  if (sid == eid) {  // Nằm trong cùng một khối
    for (int i = l; i <= r; i++) a[i] += x, s[sid] += x;
    return;
  }
  for (int i = l; id[i] == sid; i++) a[i] += x, s[sid] += x;
  for (int i = sid + 1; i < eid; i++)
    b[i] += x, s[i] += len * x;  // Cập nhật tổng đoạn cho các khối đầy đủ
  for (int i = r; id[i] == eid; i--) a[i] += x, s[eid] += x;
  // Các khối không đầy đủ ở hai biên được xử lý trực tiếp.
}

long long query(int l, int r, long long p) {  // Truy vấn đoạn
  int sid = id[l], eid = id[r];
  long long ans = 0;
  if (sid == eid) {  // Trong một khối thì tính tổng trực tiếp
    for (int i = l; i <= r; i++) ans = (ans + a[i] + b[sid]) % p;
    return ans;
  }
  for (int i = l; id[i] == sid; i++) ans = (ans + a[i] + b[sid]) % p;
  for (int i = sid + 1; i < eid; i++) ans = (ans + s[i]) % p;
  for (int i = r; id[i] == eid; i--) ans = (ans + a[i] + b[eid]) % p;
  // Cùng ý tưởng với cập nhật đoạn ở trên.
  return ans;
}

int main() {
  int n;
  cin >> n;
  len = sqrt(n);  // Theo bất đẳng thức trung bình, căn n là tối ưu.
  for (int i = 1; i <= n; i++) {  // Theo yêu cầu đề bài
    cin >> a[i];
    id[i] = (i - 1) / len + 1;
    s[id[i]] += a[i];
  }
  for (int i = 1; i <= n; i++) {
    int op, l, r, c;
    cin >> op >> l >> r >> c;
    if (op == 0)
      add(l, r, c);
    else
      cout << query(l, r, c + 1) << endl;
  }
  return 0;
}

/*
https://loj.ac/s/1151495
 */
