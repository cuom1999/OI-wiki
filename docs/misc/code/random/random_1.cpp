constexpr int SEED = 5489u;

// --8<-- [start:core]

#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main() {
  mt19937 myrand(SEED);  // Thay SEED bằng số nguyên bất kỳ hoặc time(nullptr)
  cout << myrand() << endl;
  return 0;
}

// --8<-- [end:core]
