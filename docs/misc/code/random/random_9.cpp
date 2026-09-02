
constexpr int SEED = 5489;

// --8<-- [start:core]

#include <iostream>
#include <random>
#include <vector>

using namespace std;

struct myrand {
  vector<unsigned int> vec;
  int l, j, k, cur;

  template <class URBG>
  myrand(int l, int j, int k, URBG &&rng) {
    this->l = l;
    this->j = j;
    this->k = k;
    cur = 0;
    for (int i = 0; i < l; i++) {
      vec.push_back(rng());  // Trước hết dùng cách khác sinh vài phần tử đầu
    }
  }

  unsigned int next() {
    vec[cur] = vec[(cur - j + l) % l] * vec[(cur - k + l) % l];
    // Dùng kiểu unsigned để tự động lấy môđun 2^32
    return vec[cur++];
  }
};

// Có thể thay bộ sinh cuối bằng bộ sinh khác và tự đặt hạt giống
myrand rnd(11, 4, 7, mt19937(SEED));

int main() {
  unsigned int x = rnd.next();
  cout << x << endl;
  return 0;
}

// --8<-- [end:core]
