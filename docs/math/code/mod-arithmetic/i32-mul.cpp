#include <cstdint>
#include <iostream>

// Kiem tra co kieu __int128 hoat dong duoc hay khong.
// Clang-cl tren Windows co the loi lien ket khi dung mod/div voi __int128.
#if defined(__SIZEOF_INT128__) && !(defined(__clang__) && defined(_MSC_VER))
#define HAS_WORKING_INT128 1
#else
#define HAS_WORKING_INT128 0
#endif

#if HAS_WORKING_INT128
// --8<-- [start:barrett]
// Phep nhan modulo cho int32_t bang Barrett reduction.
class Barrett {
  int32_t m;
  uint64_t r;

 public:
  Barrett(int32_t m) : m(m), r((uint64_t)(-m) / m + 1) {}

  // Barrett reduction: a % m.
  int32_t reduce(int64_t a) const {
    int64_t q = (__int128)a * r >> 64;
    a -= q * m;
    return a >= m ? a - m : a;
  }

  // Phep nhan modulo: (a * b) % m;
  // Gia su 0 <= a, b < m.
  int32_t mul(int32_t a, int32_t b) const { return reduce((int64_t)a * b); }
};

// --8<-- [end:barrett]
#endif

// --8<-- [start:montgomery]
// Phep nhan modulo Montgomery.
// Modulo m phai la so le. Hang so r la 2^32.
class Montgomery {
  int32_t m;
  uint32_t mm, r2;

 public:
  Montgomery(int32_t m) : m(m), mm(1), r2(-m) {
    // Tinh mm bang inv(m) mod r.
    for (int i = 0; i < 5; ++i) {
      mm *= 2 - mm * m;
    }
    // Tinh r2 bang r * r mod m.
    // Neu duoc phep dung phep modulo cho uint64_t, chi can dung:
    //   r2 = (uint64_t)(-m) % m;
    r2 %= m;
    r2 <<= 1;
    if (r2 >= (uint32_t)m) r2 -= m;
    for (int i = 0; i < 5; ++i) {
      r2 = mul(r2, r2);
    }
  }

  // Montgomery reduction: x * inv(r) % m.
  // Cung dung de chuyen x tu khong gian Montgomery ve khong gian thuong.
  int32_t reduce(int64_t x) {
    uint32_t u = (uint32_t)x * mm;
    int32_t ans = (x - (int64_t)m * u) >> 32;
    return ans < 0 ? ans + m : ans;
  }

  // Phep nhan trong khong gian Montgomery: x * y * inv(r) % m.
  int32_t mul(int32_t x, int32_t y) { return reduce((int64_t)x * y); }

  // Chuyen x tu khong gian thuong sang khong gian Montgomery.
  int32_t init(int32_t x) { return mul(x, r2); }
};

// --8<-- [end:montgomery]
int main() {
  int t;
  std::cin >> t;
  for (; t; --t) {
    int n, m;
    std::cin >> n >> m;
    int ans0 = 1;
    for (int i = 1; i <= n; ++i) {
      ans0 = (long long)ans0 * i % m;
    }
#if HAS_WORKING_INT128
    Barrett barrett(m);
    int ans1 = 1;
    for (int i = 1; i <= n; ++i) {
      ans1 = barrett.mul(ans1, i);
    }
#else
    // Bo qua buoc kiem tra neu khong co int128_t.
    int ans1 = ans0;
#endif
    Montgomery montgomery(m);
    int ans2 = montgomery.init(1);
    for (int i = 1; i <= n; ++i) {
      ans2 = montgomery.mul(ans2, montgomery.init(i));
    }
    ans2 = montgomery.reduce(ans2);
    std::cout << (ans0 == ans1) << (ans0 == ans2) << '\n';
  }
  return 0;
}
