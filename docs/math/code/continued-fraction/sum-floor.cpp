#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

// Tìm các phân số tiệm cận của liên phân số A.
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

// Tìm [ah, ph, qh] sao cho các điểm r[i]=(ph[i], qh[i]) tạo thành bao lồi trên
// của các điểm nguyên thỏa 0 <= x <= N và 0 <= y <= r * x,
// trong đó r = [a0, a1, a2, ...] và có ah[i]-1 điểm nguyên trên đoạn
// giữa r[i] và r[i+1].
auto hull(std::vector<int> a, int N) {
  std::vector<int> p, q;
  std::tie(p, q) = convergents(a);
  int t = N / q.back();
  std::vector<int> ah = {t};
  std::vector<int> ph = {0, t * p.back()};
  std::vector<int> qh = {0, t * q.back()};

  for (int i = q.size() - 1; i; --i) {
    if (i % 2) {
      while (qh.back() + q[i - 1] <= N) {
        t = (N - qh.back() - q[i - 1]) / q[i];
        int dp = p[i - 1] + t * p[i];
        int dq = q[i - 1] + t * q[i];
        int k = (N - qh.back()) / dq;
        ah.push_back(k);
        ph.push_back(ph.back() + k * dp);
        qh.push_back(qh.back() + k * dq);
      }
    }
  }
  return make_tuple(ah, ph, qh);
}

// --8<-- [start:core]
// Tìm tổng floor(k * x) với k trong [1, N] và x = [a0; a1, a2, ...]
int sum_floor(std::vector<int> a, int N) {
  N++;
  std::vector<int> ah, ph, qh;
  std::tie(ah, ph, qh) = hull(a, N);

  // Số điểm nguyên bên trong hình thang vuông đứng có các đỉnh
  // (0; 0) - (0; y1) - (dx; y2) - (dx; 0), với a+1 điểm nguyên
  // trên đoạn (0; y1) - (dx; y2).
  auto picks = [](int y1, int y2, int dx, int a) -> int {
    int b = y1 + y2 + a + dx;
    int A = (y1 + y2) * dx;
    return (A + b) / 2 - y2;  // = (A - b + 2) // 2 + b - (y2 + 1)
  };

  int ans = 0;
  for (size_t i = 1; i < qh.size(); i++) {
    ans += picks(ph[i - 1], ph[i], qh[i] - qh[i - 1], ah[i - 1]);
  }
  return ans - N;
}

// --8<-- [end:core]
// Get the continued fraction of e.
auto cf_e(int N) {
  int q = 0, qq = 1;
  std::vector<int> res;
  for (int i = 0; q <= N; ++i) {
    int a = i ? (i % 3 == 2 ? (i + 1) / 3 * 2 : 1) : 2;
    res.emplace_back(a);
    qq += a * q;
    std::swap(q, qq);
  }
  return res;
}

int main() {
  int N;
  std::cin >> N;
  std::cout << sum_floor(cf_e(N), N);
  return 0;
}
