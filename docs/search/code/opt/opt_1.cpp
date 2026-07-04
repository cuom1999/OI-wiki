#include <iostream>
constexpr int N = 16;
int is_working[N] = {0};  // Một công việc đã được phân công hay chưa
int tm[N][N];             // Thời gian cần để hoàn thành một công việc
int cost_time_total_min;  // Tổng thời gian nhỏ nhất để hoàn thành n công việc

// i biểu thị người thứ mấy, count biểu thị tổng chi phí công việc
void work(int i, int count, int n) {
  // Nếu i vượt quá số công việc tối đa có thể phân công, nghĩa là phân công đã
  // hoàn tất; nếu count nhỏ hơn cost_time_total_min hiện tại thì cập nhật nó.
  if (i > n && count < cost_time_total_min) {
    cost_time_total_min = count;
    return;
  }
  // Tư tưởng quay lui
  if (count < cost_time_total_min) {
    // j biểu thị công việc thứ mấy
    for (int j = 1; j <= n; j++) {
      // Nếu công việc chưa được phân công thì is_working = 0
      if (is_working[j] == 0) {
        // Phân công công việc, đặt is_working = 1
        is_working[j] = 1;
        // Giao công việc cho người thứ i + 1
        work(i + 1, count + tm[i][j], n);
        // Sau một vòng lặp, quay về người trước đó để phân công lại công việc này
        // và đặt is_working[j] về 0
        is_working[j] = 0;
      }
    }
  }
}

using std::cin;
using std::cout;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> tm[i][j];
    }
    cost_time_total_min += tm[i][i];
  }
  work(1, 0, n);
  cout << cost_time_total_min << '\n';
  return 0;
}
