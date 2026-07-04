#include <iostream>

int p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
unsigned long long n;
unsigned long long ans,
    ans_num;  // ans là số phản nguyên tố lớn nhất không vượt quá n (luôn cập nhật),
              // ans_sum là số ước của ans.

// depth: đang liệt kê đến số nguyên tố thứ mấy
// temp: giá trị hiện tại khi số ước là num
// num: số ước hiện tại
// up: số mũ của số nguyên tố trước, giới hạn cận trên số mũ hiện tại
void dfs(int depth, unsigned long long temp, unsigned long long num, int up) {
  if (depth >= 16 || temp > n) return;
  if (num > ans_num) {  // cập nhật đáp án
    ans = temp;
    ans_num = num;
  }
  if (num == ans_num && ans > temp) ans = temp;  // cập nhật đáp án
  for (int i = 1; i <= up; i++) {
    if (temp * p[depth] > n)
      break;  // cắt nhánh: nếu nhân thêm thừa số này vượt n thì không tối ưu
    dfs(depth + 1, temp *= p[depth], num * (i + 1),
        i);  // lấy thêm một thừa số này, rồi tìm tiếp với thừa số kế tiếp
  }
  return;
}

using std::cin;
using std::cout;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  while (cin >> n) {
    ans_num = 0;
    dfs(0, 1, 1, 60);
    cout << ans << '\n';
  }
  return 0;
}
