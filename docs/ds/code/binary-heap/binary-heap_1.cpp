#include <iostream>
#include <queue>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, x;
  cin >> t;
  while (t--) {
    // Heap lớn, duy trì nửa trước của các phần tử (lưu các giá trị nhỏ)
    priority_queue<int, vector<int>, less<int>> a;
    // Heap nhỏ, duy trì nửa sau của các phần tử (lưu các giá trị lớn)
    priority_queue<int, vector<int>, greater<int>> b;
    while (cin >> x, x) {
      // Nếu là thao tác truy vấn và xóa, in rồi xóa phần tử ở đỉnh heap lớn
      // vì bài này yêu cầu in trung vị nhỏ hơn (khi có chẵn số phần tử sẽ có
      // hai ứng viên trung vị).
      // Cách này hơi khác phần giải thích phần tử lớn thứ k ở trên, nhưng chỉ
      // cần biến đổi nhẹ là có thể hiểu được từ ý tưởng đó.
      if (x == -1) {
        cout << a.top() << '\n';
        a.pop();
      }
      // Nếu là thao tác chèn, chọn heap phù hợp dựa trên phần tử ở đỉnh heap lớn
      else {
        if (a.empty() || x <= a.top())
          a.push(x);
        else
          b.push(x);
      }
      // Điều chỉnh heap đối đỉnh
      if (a.size() > (a.size() + b.size() + 1) / 2) {
        b.push(a.top());
        a.pop();
      } else if (a.size() < (a.size() + b.size() + 1) / 2) {
        a.push(b.top());
        b.pop();
      }
    }
  }
  return 0;
}
