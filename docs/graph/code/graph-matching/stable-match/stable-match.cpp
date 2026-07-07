#include <iostream>
#include <queue>
#include <vector>

// Bộ giải cho bài toán ghép cặp ổn định.
// Giả sử thứ tự ưu tiên là nghiêm ngặt và các danh sách có thể không đầy đủ.
struct StableMatching {
  int nx, ny;
  std::vector<std::vector<int>> pref_x,
      pref_y;  // Thứ tự ưu tiên: ưu tiên hơn đứng trước, chỉ gồm các cặp chấp nhận được.
  std::vector<int> match_x, match_y;  // Ghép cặp: -1 nghĩa là chưa ghép.

  StableMatching(int nx, int ny)
      : nx(nx),
        ny(ny),
        pref_x(nx),
        pref_y(ny),
        match_x(nx, -1),
        match_y(ny, -1) {}

  // Thuật toán Gale-Shapley.
  // Độ phức tạp: O(nx * ny).
  void solve() {
    // Tính thứ hạng của X theo từng phần tử trong Y.
    std::vector<std::vector<int>> ranks(ny, std::vector<int>(nx));
    for (int j = 0; j != ny; ++j) {
      for (int i = 0; i != pref_y[j].size(); ++i) {
        ranks[j][pref_y[j][i]] = nx - i;
      }
    }
    // Khởi tạo.
    std::vector<int> waitlist(ny);  // Thứ hạng lời cầu hôn tốt nhất cho j trong Y.
    std::vector<int> ids(nx);       // j tiếp theo trong Y mà i trong X sẽ cầu hôn.
    std::queue<int> q;              // Các i trong X đang hoạt động.
    for (int i = 0; i != nx; ++i) q.push(i);
    // Loop.
    while (!q.empty()) {
      auto i = q.front();
      q.pop();
      auto j = pref_x[i][ids[i]++];
      if (ranks[j][i] > waitlist[j]) {
        if (waitlist[j]) q.push(pref_y[j][nx - waitlist[j]]);
        waitlist[j] = ranks[j][i];
      } else {
        q.push(i);
      }
    }
    // Xuất dữ liệu.
    for (int j = 0; j != ny; ++j) {
      if (waitlist[j]) {
        int i = pref_y[j][nx - waitlist[j]];
        match_x[i] = j;
        match_y[j] = i;
      }
    }
  }
};

void solve() {
  // Nhập dữ liệu.
  int n;
  std::cin >> n;
  StableMatching solver(n, n);
  for (int j = 0, x; j < n; ++j) {
    auto& cur = solver.pref_y[j];
    std::cin >> x;
    for (int i = 0; i < n; ++i) {
      std::cin >> x;
      cur.push_back(x - 1);
    }
  }
  for (int i = 0, y; i < n; ++i) {
    auto& cur = solver.pref_x[i];
    std::cin >> y;
    for (int j = 0; j < n; ++j) {
      std::cin >> y;
      cur.push_back(y - 1);
    }
  }
  // Giải bài toán.
  solver.solve();
  // Xuất dữ liệu.
  for (int i = 0; i < n; ++i) {
    std::cout << (i + 1) << ' ' << (solver.match_x[i] + 1) << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  for (; t; --t) {
    solve();
  }
  return 0;
}
