#include <cstring>
#include <iostream>
using namespace std;
// --8<-- [start:core]
constexpr int N = 100010;
constexpr int W = 100010;
constexpr int K = 100;

int n, w, k, cnt[W];

struct Element {
  int key[K];
} a[N], b[N];

void counting_sort(int p) {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) ++cnt[a[i].key[p]];
  for (int i = 1; i <= w; ++i) cnt[i] += cnt[i - 1];
  // Để bảo đảm tính ổn định của sắp xếp, vòng lặp i ở đây phải đi từ n về 1.
  // Khi hai phần tử có cùng khóa, phần tử vốn đứng sau vẫn đứng sau khi sắp xếp.
  for (int i = n; i >= 1; --i) b[cnt[a[i].key[p]]--] = a[i];
  memcpy(a, b, sizeof(a));
}

void radix_sort() {
  for (int i = k; i >= 1; --i) {
    // Dùng counting sort để sắp xếp theo khóa.
    counting_sort(i);
  }
}

// --8<-- [end:core]

int main() {
  k = 10;
  w = 9;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    unsigned x;
    cin >> x;
    for (int j = 10; j >= 1; j--) a[i].key[j] = x % 10, x /= 10;
  }
  radix_sort();
  for (int i = 1; i <= n; i++) {
    int l = 1;
    while (!a[i].key[l] && l <= k) l++;
    if (l > k)
      cout << "0";
    else
      for (; l <= k; l++) cout << a[i].key[l];
    cout << " \n"[i == n];
  }
}
