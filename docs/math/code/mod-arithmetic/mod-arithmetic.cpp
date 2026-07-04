#include <iostream>

// --8<-- [start:core]
// Một cài đặt ModInt đơn giản.
template <int M>
struct ModInt {
  struct skip_mod {};

  ModInt(int v, skip_mod) : v(v) {}

  int v;

  ModInt() : v(0) {}

  // Khởi tạo: tìm số dư.
  // Tương đương với: v = int((x % M + M) % M)
  ModInt(long long x) {
    x %= M;
    if (x < 0) x += M;
    v = int(x);
  }

  // Phép cộng.
  // Tương đương với: ModInt((l.v + r.v) % M)
  friend ModInt operator+(ModInt l, ModInt r) {
    int res = l.v + r.v;
    if (res >= M) res -= M;
    return ModInt(res, skip_mod{});
  }

  // Phép trừ.
  // Tương đương với: ModInt((l.v - r.v + M) % M)
  friend ModInt operator-(ModInt l, ModInt r) {
    int res = l.v - r.v;
    if (res < 0) res += M;
    return ModInt(res, skip_mod{});
  }

  // Phép nhân.
  friend ModInt operator*(ModInt l, ModInt r) {
    return ModInt(1LL * l.v * r.v % M, skip_mod{});
  }

  // Phép lũy thừa.
  ModInt pow(long long b) const {
    ModInt res{1}, po{*this};
    for (; b; b >>= 1) {
      if (b & 1) res = res * po;
      po = po * po;
    }
    return res;
  }
};

// --8<-- [end:core]
template <int M>
std::ostream& operator<<(std::ostream& os, const ModInt<M>& m) {
  return os << m.v;
}

using mint = ModInt<1000000007>;

int main() {
  // Kiểm tra chuẩn hóa trong constructor
  std::cout << mint(10) << "\n";
  std::cout << mint(-10) << "\n";
  std::cout << mint(1000000007) << "\n";
  std::cout << mint(-1000000007) << "\n";

  // Kiểm tra phép cộng
  std::cout << (mint(1000000006) + mint(2)) << "\n";

  // Kiểm tra phép trừ
  std::cout << (mint(3) - mint(5)) << "\n";

  // Kiểm tra phép nhân
  std::cout << (mint(123456) * mint(789012)) << "\n";

  // Kiểm tra pow
  std::cout << mint(2).pow(10) << "\n";
  std::cout << mint(2).pow(0) << "\n";
  std::cout << mint(2).pow(1000000006) << "\n";

  return 0;
}
