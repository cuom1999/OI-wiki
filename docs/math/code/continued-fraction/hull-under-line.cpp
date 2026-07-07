#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

// Tìm biểu diễn liên phân số của P/Q.
auto fraction(int p, int q) {
  std::vector<int> a;
  while (q) {
    a.push_back(p / q);
    std::tie(p, q) = std::make_pair(q, p % q);
  }
  return a;
}

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

// --8<-- [start:core]
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

// --8<-- [end:core]
int main() {
  int p, q, N;
  std::cin >> p >> q >> N;
  std::vector<int> ah, ph, qh;
  std::tie(ah, ph, qh) = hull(fraction(p, q), N);
  for (int i = 1; i < ph.size(); ++i) {
    std::cout << qh[i] << ' ' << ph[i] << ' ' << ah[i - 1] << std::endl;
  }
  return 0;
}
