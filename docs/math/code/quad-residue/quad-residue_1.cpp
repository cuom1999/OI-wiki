#include <iostream>
#include <random>

long long p, v;  // Lần lượt là modulo và giá trị r^2 - a

struct Poly {
  long long a, b;

  Poly(long long _a = 0, long long _b = 0) : a(_a), b(_b) {}
};

Poly operator*(const Poly& x, const Poly& y) {
  // Nạp chồng phép nhân; tham khảo phần giải thích tính chất phép toán ở trên
  return Poly((x.a * y.a + v * (x.b * y.b % p)) % p,
              (x.a * y.b + x.b * y.a) % p);
}

// Lũy thừa nhanh cho đa thức, dùng để tính đáp án
Poly modpow(Poly a, long long b) {
  Poly res(1, 0);
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

// Lũy thừa nhanh thông thường, dùng để kiểm tra bất thặng dư bậc hai
long long modpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}

// Dùng để sinh số ngẫu nhiên
std::mt19937 rng(std::random_device{}());

long long cipolla(long long a, long long _p) {
  p = _p;
  if (a == 0)
    return 0;  // Xử lý riêng trường hợp 0
  else if (modpow(a, (p - 1) / 2) == p - 1)
    return -1;  // Là bất thặng dư bậc hai, nên vô nghiệm
  else {
    // Chọn ngẫu nhiên r sao cho r^2 - a là bất thặng dư bậc hai
    long long r;
    for (r = rng() % p;; r = rng() % p) {
      if (modpow((r * r - a + p) % p, (p - 1) / 2) == p - 1) break;
    }
    v = (r * r - a + p) % p;
    return modpow(Poly(r, 1), (p + 1) / 2).a;  // Tính kết quả theo công thức kết luận
  }
}

int main() {
  int t, a, p;
  std::cin >> t;
  while (t--) {
    std::cin >> a >> p;
    int ans = cipolla(a, p);
    if (ans == -1)
      std::cout << "Hola!" << std::endl;
    else if (ans == 0)
      std::cout << 0 << std::endl;
    else {
      // Số đối modulo là nghiệm còn lại
      int ans2 = (p - ans) % p;
      if (ans2 < ans) std::swap(ans, ans2);
      std::cout << ans << " " << ans2 << std::endl;
    }
  }
  return 0;
}
