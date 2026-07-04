#include <cstring>
#include <iostream>
#include <random>
#include <utility>
using namespace std;

constexpr int MAXN = 505, p = (int)1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (long long)ans * a % p;
    a = (long long)a * a % p;
    b >>= 1;
  }
  return ans;
}

int A[MAXN][MAXN], B[MAXN][MAXN], t[MAXN][MAXN], id[MAXN];

// Khử Gauss O(n^3).
// Nếu truyền B thì tính ma trận nghịch đảo; nếu truyền nullptr thì chỉ tính hạng ma trận.
void Gauss(int A[][MAXN], int B[][MAXN], int n) {
  if (B) {
    memset(B, 0, sizeof(t));
    for (int i = 1; i <= n; i++) B[i][i] = 1;
  }

  for (int i = 1; i <= n; i++) {
    if (!A[i][i]) {
      for (int j = i + 1; j <= n; j++)
        if (A[j][i]) {
          swap(id[i], id[j]);
          for (int k = i; k <= n; k++) swap(A[i][k], A[j][k]);

          if (B)
            for (int k = 1; k <= n; k++) swap(B[i][k], B[j][k]);
          break;
        }

      if (!A[i][i]) continue;
    }

    int inv = qpow(A[i][i], p - 2);

    for (int j = 1; j <= n; j++)
      if (i != j && A[j][i]) {
        int t = (long long)A[j][i] * inv % p;

        for (int k = i; k <= n; k++)
          if (A[i][k]) A[j][k] = (A[j][k] - (long long)t * A[i][k]) % p;

        if (B) {
          for (int k = 1; k <= n; k++)
            if (B[i][k]) B[j][k] = (B[j][k] - (long long)t * B[i][k]) % p;
        }
      }
  }

  if (B)
    for (int i = 1; i <= n; i++) {
      int inv = qpow(A[i][i], p - 2);

      for (int j = 1; j <= n; j++)
        if (B[i][j]) B[i][j] = (long long)B[i][j] * inv % p;
    }
}

bool row_marked[MAXN] = {false}, col_marked[MAXN] = {false};

int sub_n;  // Kích thước ma trận con đầy hạng cực đại.

// Khử một hàng và một cột O(n^2).
void eliminate(int r, int c) {
  row_marked[r] = col_marked[c] = true;  // Đã bị khử.

  int inv = qpow(B[r][c], p - 2);

  for (int i = 1; i <= sub_n; i++)
    if (!row_marked[i] && B[i][c]) {
      int t = (long long)B[i][c] * inv % p;

      for (int j = 1; j <= sub_n; j++)
        if (!col_marked[j] && B[r][j])
          B[i][j] = (B[i][j] - (long long)t * B[r][j]) % p;
    }
}

int vertices[MAXN], girl[MAXN];  // girl là đỉnh được ghép, dùng để xuất phương án.

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto rng = mt19937(random_device{}());

  int n, m;
  cin >> n >> m;  // Số đỉnh và số cạnh.

  while (m--) {
    int x, y;
    cin >> x >> y;
    A[x][y] = rng() % p;
    A[y][x] = -A[x][y];  // Ma trận Tutte.
  }

  for (int i = 1; i <= n; i++)
    id[i] = i;  // Dùng để xuất phương án, vì khi khử Gauss sẽ hoán đổi cột.
  memcpy(t, A, sizeof(t));

  Gauss(A, nullptr, n);

  for (int i = 1; i <= n; i++)
    if (A[id[i]][id[i]]) vertices[++sub_n] = i;  // Tìm một ma trận con đầy hạng cực đại.

  for (int i = 1; i <= sub_n; i++)
    for (int j = 1; j <= sub_n; j++) A[i][j] = t[vertices[i]][vertices[j]];

  Gauss(A, B, sub_n);

  for (int i = 1; i <= sub_n; i++)
    if (!girl[vertices[i]])
      for (int j = i + 1; j <= sub_n; j++)
        if (!girl[vertices[j]] && t[vertices[i]][vertices[j]] && B[j][i]) {
          // Chú ý cách viết câu if phía trên; hiện t là bản sao của ma trận kề,
          // phần tử hàng j cột i trong ma trận nghịch đảo khác 0 khi và chỉ khi cạnh này hợp lệ.
          girl[vertices[i]] = vertices[j];
          girl[vertices[j]] = vertices[i];

          eliminate(i, j);
          eliminate(j, i);
          break;
        }

  cout << sub_n / 2 << '\n';
  for (int i = 1; i <= n; i++) cout << girl[i] << ' ';

  return 0;
}
