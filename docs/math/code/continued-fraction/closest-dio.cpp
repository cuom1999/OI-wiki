#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

// Tìm biểu diễn phân số liên tục của P/Q.
auto fraction(int p, int q) {
  std::vector<int> a;
  while (q) {
    a.push_back(p / q);
    std::tie(p, q) = std::make_pair(q, p % q);
  }
  return a;
}

// Tìm các phân số hội tụ của phân số liên tục A.
// Tử số và mẫu số được lưu riêng trong P và Q.
auto convergents(std::vector<int> a) {
  std::vector<int> p = {0, 1};
  std::vector<int> q = {1, 0};
  for (auto it : a) {
    p.push_back(p.back() * it + p.end()[-2]);
    q.push_back(q.back() * it + q.end()[-2]);
  }
  return std::make_pair(p, q);
}

// --8<-- [start:core]
// Tìm (x, y) sao cho y = (A*x+B)/C,
// Cy - Ax là lớn nhất và 0 <= x <= N.
auto closest(int A, int B, int C, int N) {
  // y <= (A*x + B)/C <=> diff(x, y) <= B
  auto diff = [&](int x, int y) -> int { return C * y - A * x; };
  std::vector<int> p, q;
  std::tie(p, q) = convergents(fraction(A, C));
  int qh = 0, ph = B / C;
  for (int i = 2; i < q.size() - 1; ++i) {
    if (i % 2 == 0) {
      while (diff(qh + q[i + 1], ph + p[i + 1]) <= B) {
        int t = 1 + (diff(qh + q[i - 1], ph + p[i - 1]) - B - 1) /
                        (-diff(q[i], p[i]));
        int dp = p[i - 1] + t * p[i];
        int dq = q[i - 1] + t * q[i];
        int k = (N - qh) / dq;
        if (k == 0) {
          return std::make_pair(qh, ph);
        }
        if (diff(dq, dp) != 0) {
          k = std::min(k, (B - diff(qh, ph)) / diff(dq, dp));
        }
        qh += k * dq;
        ph += k * dp;
      }
    }
  }
  return std::make_pair(qh, ph);
}

auto solve(int A, int B, int N) {
  int x, y;
  std::tie(x, y) = closest(A, N % A, B, N / A);
  return std::make_pair(N / A - x, y);
}

// --8<-- [end:core]
int main() {
  int a, b, n, x, y;
  std::cin >> a >> b >> n;
  std::tie(x, y) = solve(a, b, n);
  std::cout << x << ' ' << y;
  return 0;
}
