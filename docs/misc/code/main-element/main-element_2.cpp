#include <cstdio>
#include <vector>
using namespace std;

// --8<-- [start:core]
class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    // Biến thao tác "triệt tiêu 2 phần tử khác nhau" của thuật toán bỏ phiếu đa số
    // thành "triệt tiêu 3 phần tử đôi một khác nhau"
    int maj1, maj2;
    int cnt1 = 0, cnt2 = 0;
    for (int num : nums) {
      if (num == maj1) {
        ++cnt1;
      } else if (num == maj2) {
        ++cnt2;
      } else if (cnt1 == 0) {
        maj1 = num;
        ++cnt1;
      } else if (cnt2 == 0) {
        maj2 = num;
        ++cnt2;
      } else {
        --cnt1;
        --cnt2;
      }
    }

    // Vì đề bài không bảo đảm tồn tại 2 phần tử xuất hiện quá floor(n/3) lần,
    // cần kiểm tra lại
    vector<int> ans;
    cnt1 = 0, cnt2 = 0;
    for (int num : nums) {
      if (num == maj1)
        ++cnt1;
      else if (num == maj2)
        ++cnt2;
    }
    int n = nums.size();
    if (cnt1 > n / 3) ans.push_back(maj1);
    if (cnt2 > n / 3) ans.push_back(maj2);

    return ans;
  }
};

// --8<-- [end:core]
int main() {
  int n;
  scanf("%d", &n);
  vector<int> nums(n);
  for (int& i : nums) scanf("%d", &i);
  Solution sol;
  vector<int> ans = sol.majorityElement(nums);
  for (int i = 0; i < ans.size(); i++)
    printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
  return 0;
}
