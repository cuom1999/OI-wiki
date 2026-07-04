#include <array>
#include <iostream>
#include <vector>

int main() {
  // Hàm hỗ trợ chuyển trạng thái như đã giải thích ở trên.
  auto calc = [](int x0, int y0, int x) -> int {
    return x == x0 ? 0
                   : ((x < x0 && x < y0) || (x > x0 && x > y0)
                          ? x
                          : (x0 < y0 ? x - 1 : x + 1));
  };

  int t;
  std::cin >> t;
  for (; t; --t) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;

    // dp[i][j][0] = giá trị x duy nhất sao cho
    //     f_{i-1,j}(x, a_j) = 0
    // tức trò chơi trên đoạn [i, j] ở trạng thái P
    // khi gắn thêm một đống có kích thước x vào BÊN TRÁI.
    //
    // dp[i][j][1] = giá trị y duy nhất sao cho
    //     f_{i,j+1}(a_i, y) = 0
    // tức trò chơi trên đoạn [i, j] ở trạng thái P
    // khi gắn thêm một đống có kích thước y vào BÊN PHẢI.
    std::vector<std::vector<std::array<int, 2>>> dp(
        n, std::vector<std::array<int, 2>>(n));

    // Cơ sở: đoạn chỉ có một phần tử [i, i].
    // Giá trị đống "trái" và "phải" đều bằng a[i].
    for (int i = 0; i < n; ++i) dp[i][i][0] = dp[i][i][1] = a[i];

    // Xây dựng các đoạn theo độ dài d tăng dần.
    for (int d = 1; d < n; ++d) {
      for (int i = 0; i + d < n; ++i) {
        dp[i][i + d][0] =
            calc(dp[i][i + d - 1][1], dp[i][i + d - 1][0], a[i + d]);
        dp[i][i + d][1] = calc(dp[i + 1][i + d][0], dp[i + 1][i + d][1], a[i]);
      }
    }

    // Trò chơi ban đầu tương ứng với việc không gắn gì ở bên trái.
    // Đây là trạng thái P khi và chỉ khi giá trị y duy nhất thỏa
    //     f_{-1, n-1}(0, y) = 0
    // là y = 0.
    std::cout << (dp[0][n - 1][0] != 0) << '\n';
  }
  return 0;
}
