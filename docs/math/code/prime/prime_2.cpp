#include <iostream>

int p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
unsigned long long n;
unsigned long long ans,
    ans_num;  // ans la so phan nguyen to lon nhat khong vuot qua n (luon cap nhat),
              // ans_sum la so uoc cua ans.

// depth: dang liet ke den so nguyen to thu may
// temp: gia tri hien tai khi so uoc la num
// num: so uoc hien tai
// up: so mu cua so nguyen to truoc, gioi han can tren so mu hien tai
void dfs(int depth, unsigned long long temp, unsigned long long num, int up) {
  if (depth >= 16 || temp > n) return;
  if (num > ans_num) {  // cap nhat dap an
    ans = temp;
    ans_num = num;
  }
  if (num == ans_num && ans > temp) ans = temp;  // cap nhat dap an
  for (int i = 1; i <= up; i++) {
    if (temp * p[depth] > n)
      break;  // cat nhanh: neu nhan them thua so nay vuot n thi khong toi uu
    dfs(depth + 1, temp *= p[depth], num * (i + 1),
        i);  // lay them mot thua so nay, roi tim tiep voi thua so ke tiep
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
