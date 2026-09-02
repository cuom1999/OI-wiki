#include <iostream>
using namespace std;

struct myrand {
  int A, C, M, x;

  myrand(int A, int C, int M) {
    this->A = A;
    this->C = C;
    this->M = M;
    this->x = 0;
  }

  // Sinh số tiếp theo trong dãy ngẫu nhiên
  int next() { return x = ((long long)A * x + C) % M; }
};

myrand rnd(3, 5, 97);  // Khởi tạo một bộ sinh số ngẫu nhiên

int main() {
  int x = rnd.next();
  cout << x << endl;
  return 0;
}
