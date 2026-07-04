// divide-and-conquer_1.h
// Định nghĩa nút cây nhị phân
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
