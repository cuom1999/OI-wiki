#include <iostream>
#include <vector>
using namespace std;

// --8<-- [start:core]
pair<bool, vector<int>> findCycle(
    vector<int>
        nxt)  // nxt[i] là nút mà i trỏ tới trong danh sách liên kết đơn
              // (0-indexed), -1 nghĩa là không trỏ tới nút nào
{
  int fast = 0, slow = 0;
  do  // Trước hết kiểm tra có chu trình hay không
  {
    if (nxt[fast] == -1 || nxt[nxt[fast]] == -1) {
      return make_pair(false, vector<int>());  // Không có chu trình
    }
    fast = nxt[nxt[fast]];
    slow = nxt[slow];
  } while (fast != slow);
  slow = 0;
  while (slow != fast)  // Sau đó tìm vị trí bắt đầu chu trình
  {
    slow = nxt[slow];
    fast = nxt[fast];
  }
  vector<int> cycle;
  do  // Cuối cùng liệt kê toàn bộ chu trình
  {
    cycle.push_back(slow);
    slow = nxt[slow];
  } while (slow != fast);
  return make_pair(true, cycle);
}

// --8<-- [end:core]
int main() {
  int n;
  while (cin >> n) {
    vector<int> nxt;
    nxt.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> nxt[i];
    }
    pair<bool, vector<int>> cycle = findCycle(nxt);
    if (cycle.first) {
      cout << "Cycle:";
      for (int i = 0; i < cycle.second.size(); i++) {
        cout << " " << cycle.second[i];
      }
      cout << endl;
    } else {
      cout << "No cycle.\n";
    }
  }
}
