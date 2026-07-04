#include <iostream>
#include <vector>
using namespace std;
// --8<-- [start:core]
constexpr unsigned MAXN = 1000;  // Số lượng phần tử cần sắp xếp.
constexpr unsigned RADIX = 10;   // Cơ số.
constexpr unsigned powRADIX[10] = {1,         10,        100,     1000,
                                   10000,     100000,    1000000, 10000000,
                                   100000000, 1000000000};  // Các lũy thừa của RADIX.

unsigned get_digit(unsigned value, int digit)  // Trích chữ số thứ digit.
{
  return (value / powRADIX[digit]) % RADIX;
}

void MSD_radix_sort(unsigned* begin, unsigned* end, int digit)
// Các phần tử trong [begin,end) hiện có một số chữ số đầu giống nhau
// trong hệ thập phân.
// Chỉ digit chữ số cuối cùng, từ digit-1 đến 0, còn cần được sắp xếp.
// Ví dụ gọi: MSD_radix_sort(a,a+n,9)
{
  if (begin >= end)  // Đoạn rỗng.
  {
    return;
  }
  /** Counting sort; cách viết này chỉ để tham khảo. **/
  static unsigned cnt[RADIX + 1],
      tmp[MAXN + 5];  // Các tầng đệ quy khác nhau không dùng cnt/tmp đồng thời
                      // (mỗi tầng dùng xong mới gọi tầng tiếp theo), nên dùng
                      // static để tiết kiệm bộ nhớ.
  vector<unsigned> beg;
  beg.resize(RADIX + 1);  // Tránh xung đột truy cập beg bằng biến cục bộ.
  for (int i = 0; i <= RADIX; i++) {
    cnt[i] = beg[i] = 0;  // Xóa về 0 là thói quen tốt.
  }
  for (unsigned* it = begin; it != end; it++)  // Đếm.
  {
    int bitVal = get_digit(*it, digit - 1);
    cnt[bitVal] += 1;
  }
  beg[0] = 0;  // Tính vị trí bắt đầu lưu mỗi chữ số (offset).
  for (int i = 1; i <= RADIX; i++) {
    beg[i] = beg[i - 1] + cnt[i - 1];
  }
  // Tính thêm beg[RADIX] để có thể định nghĩa trực tiếp đoạn ứng với i là
  // [beg[i],beg[i+1]) mà không lo beg[i+1] vượt biên.
  for (int i = 0; i < RADIX; i++) {
    cnt[i] = 0;
  }
  for (unsigned* it = begin; it != end; it++)  // Đưa kết quả counting sort vào tmp.
  {
    unsigned bitVal = get_digit(*it, digit - 1);  // Trích chữ số thứ bit-1.
    tmp[beg[bitVal] + cnt[bitVal]] =
        *it;  // Vì duyệt ngược nên phần tử hiện tại là phần tử thứ
              // cnt[bitVal]+1 có chữ số thứ bit-1 bằng cnt[bitVal].
    cnt[bitVal]++;
  }
  for (unsigned* it = begin; it != end; it++)  // Sao chép tmp về mảng gốc.
  {
    *it = tmp[it - begin];
  }
  /** Tính đệ quy. **/
  if (digit == 1)  // Đã đến chữ số thấp nhất.
  {
    return;
  }
  for (int i = 0; i < RADIX; i++)  // Đệ quy sắp xếp chữ số tiếp theo.
  {
    MSD_radix_sort(begin + beg[i], begin + beg[i + 1], digit - 1);
  }
}

// --8<-- [end:core]
unsigned a[MAXN + 5];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  MSD_radix_sort(a + 1, a + n + 1, 9);
  for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}
