#include <cstdint>
#include <iostream>

// Kiểm tra có kiểu __int128 hoạt động được hay không.
// Clang-cl trên Windows có thể lỗi liên kết khi dùng mod/div với __int128.
#if defined(__SIZEOF_INT128__) && !(defined(__clang__) && defined(_MSC_VER))
#define HAS_WORKING_INT128 1
#else
#define HAS_WORKING_INT128 0
#endif

#if HAS_WORKING_INT128
// --8<-- [start:barrett]
// Phép nhân modulo cho int32_t bằng Barrett reduction.
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

  // Phép nhân modulo: (a * b) % m;
  // Giả sử 0 <= a, b < m.
  int32_t mul(int32_t a, int32_t b) const { return reduce((int64_t)a * b); }
};

// --8<-- [end:barrett]
#endif

// --8<-- [start:montgomery]
// Phép nhân modulo Montgomery.
// Modulo m phải là số lẻ. Hằng số r là 2^32.
class Montgomery {
  int32_t m;
  uint32_t mm, r2;

 public:
  Montgomery(int32_t m) : m(m), mm(1), r2(-m) {
    // Tính mm bằng inv(m) mod r.
    for (int i = 0; i < 5; ++i) {
      mm *= 2 - mm * m;
    }
    // Tính r2 bằng r * r mod m.
    // Nếu được phép dùng phép modulo cho uint64_t, chỉ cần dùng:
    //   r2 = (uint64_t)(-m) % m;
    r2 %= m;
    r2 <<= 1;
    if (r2 >= (uint32_t)m) r2 -= m;
    for (int i = 0; i < 5; ++i) {
      r2 = mul(r2, r2);
    }
  }

  // Montgomery reduction: x * inv(r) % m.
  // Cũng dùng để chuyển x từ không gian Montgomery về không gian thường.
  int32_t reduce(int64_t x) {
    uint32_t u = (uint32_t)x * mm;
    int32_t ans = (x - (int64_t)m * u) >> 32;
    return ans < 0 ? ans + m : ans;
  }

  // Phép nhân trong không gian Montgomery: x * y * inv(r) % m.
  int32_t mul(int32_t x, int32_t y) { return reduce((int64_t)x * y); }

  // Chuyển x từ không gian thường sang không gian Montgomery.
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
    // Bỏ qua bước kiểm tra nếu không có int128_t.
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
