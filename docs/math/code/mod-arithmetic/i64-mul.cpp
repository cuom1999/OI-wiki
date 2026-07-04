#include <cfloat>
#include <iostream>

// Kiem tra co kieu __int128 hoat dong duoc hay khong.
// Clang-cl tren Windows co the loi lien ket khi dung mod/div voi __int128.
#if defined(__SIZEOF_INT128__) && !(defined(__clang__) && defined(_MSC_VER))
#define HAS_WORKING_INT128 1
#else
#define HAS_WORKING_INT128 0
#endif

namespace LongDoubleMul {

#if LDBL_MANT_DIG >= 64  // Chi kiem tra khi long double co it nhat 80 bit.

// --8<-- [start:ld-mul]
long long mul(long long a, long long b, long long m) {
  long long c = (unsigned long long)a * b -
                (unsigned long long)((long double)a / m * b + 0.5L) * m;
  return c < 0 ? c + m : c;
}

// --8<-- [end:ld-mul]
#else

long long mul(long long a, long long b, long long m) { return -1; }

#endif

};  // namespace LongDoubleMul

namespace Int128Mul {

#if HAS_WORKING_INT128  // Chi kiem tra khi co __int128.

// --8<-- [start:i128-mul]
long long mul(long long a, long long b, long long m) {
  return (__int128)a * b % m;
}

// --8<-- [end:i128-mul]
#else

long long mul(long long a, long long b, long long m) { return -1; }

#endif

};  // namespace Int128Mul

bool check(long long output, long long answer) {
  return output == -1 || output == answer;
}

int main() {
  int t;
  std::cin >> t;
  for (; t; --t) {
    long long a, b, m, c;
    std::cin >> a >> b >> m >> c;
    std::cout << check(LongDoubleMul::mul(a, b, m), c)
              << check(Int128Mul::mul(a, b, m), c) << '\n';
  }
  return 0;
}
