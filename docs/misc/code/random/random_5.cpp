constexpr int SEED = 5497u;

// --8<-- [start:header]
#include <iostream>
#include <random>
// --8<-- [end:header]

// --8<-- [start:real-using]
using std::cout;
using std::mt19937;

// --8<-- [end:real-using]

template <class Ty = int>
class uniform_int_distribution {
 private:
  int a, b;

 public:
  uniform_int_distribution(int _a, int _b) : a(_a), b(_b) {}

  template <class Rng>
  int operator()(Rng &rng) {
    return rng() % (b - a + 1) + a;
  }
};

namespace fake_using {
// --8<-- [start:fake-using]
using std::uniform_int_distribution;
// --8<-- [end:fake-using]
}  // namespace fake_using

// --8<-- [start:main]
int main() {
  mt19937 gen(SEED);  // Gieo hạt cho mersenne_twister_engine chuẩn
  uniform_int_distribution<> dis(1, 6);

  for (int n = 0; n < 10; ++n)
    // Dùng dis đổi unsigned int ngẫu nhiên của gen thành int trong [1, 6]
    cout << dis(gen) << ' ';
  cout << '\n';
  return 0;
}

// --8<-- [end:main]
