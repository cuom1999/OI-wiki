#include <iostream>
#include <vector>

// Một hoán vị.
class Permutation {
  std::vector<int> perm;

  void shrink() {
    int m = perm.size();
    for (; m && perm[m - 1] == m - 1; --m);
    perm.resize(m);
  }

 public:
  Permutation() {}

  Permutation(const std::vector<int>& vec) : perm(vec) { shrink(); }

  int operator[](int i) const { return i < perm.size() ? perm[i] : i; }

  bool empty() const { return perm.empty(); }

  // Thực hiện vế trái trước, rồi đến vế phải.
  Permutation operator*(const Permutation& rhs) const {
    Permutation res;
    res.perm.resize(std::max(perm.size(), rhs.perm.size()));
    for (int i = 0; i < res.perm.size(); ++i) {
      res.perm[i] = rhs[(*this)[i]];
    }
    res.shrink();
    return res;
  }

  // Thực hiện nghịch đảo của vế trái trước, rồi đến vế phải.
  Permutation operator/(const Permutation& rhs) const {
    Permutation res;
    res.perm.resize(std::max(perm.size(), rhs.perm.size()));
    for (int i = 0; i < res.perm.size(); ++i) {
      res.perm[(*this)[i]] = rhs[i];
    }
    res.shrink();
    return res;
  }

  // Hoán vị nghịch đảo.
  Permutation inv() const {
    Permutation res;
    res.perm.resize(perm.size());
    for (int i = 0; i < res.perm.size(); ++i) {
      res.perm[(*this)[i]] = i;
    }
    return res;
  }
};

// Một chuỗi ổn định hóa (còn gọi là BSGS) của một nhóm.
class PermutationGroup {
  size_t n, k;
  std::vector<bool> orbit;               // Quỹ đạo của điểm thứ n.
  std::vector<Permutation> generators;   // Các phần tử sinh.
  std::vector<Permutation> transversal;  // Nghịch đảo của đại diện lớp kề.
  PermutationGroup* next;                // Nhóm ổn định hóa.

  // Sàng một hoán vị.
  void sift(Permutation& h) const {
    if (!n) return;
    int i = h[n - 1];
    if (!orbit[i]) return;
    h = h * transversal[i];
    next->sift(h);
  }

  // Thêm một phần tử vào hệ đại diện lớp kề.
  void extend_transversal(Permutation t) {
    int i = t[n - 1];
    if (!orbit[i]) {
      ++k;
      orbit[i] = true;
      transversal[i] = t.inv();
      for (const auto& s : generators) {
        extend_transversal(t * s);
      }
    } else {
      next->extend(t * transversal[i]);
    }
  }

 public:
  PermutationGroup(int n)
      : n(n), k(1), orbit(n), transversal(n), next(nullptr) {
    if (!n) return;
    // Khởi tạo tầng hiện tại.
    orbit[n - 1] = true;
    next = new PermutationGroup(n - 1);
  }

  // Hàm hủy.
  ~PermutationGroup() {
    if (next) delete next;
  }

  // Thêm một hoán vị vào nhóm.
  void extend(Permutation g) {
    sift(g);
    if (g.empty()) return;
    generators.emplace_back(g);
    for (int i = 0; i < n; ++i) {
      if (orbit[i]) {
        extend_transversal(transversal[i] / g);
      }
    }
  }

  // Kiểm tra một hoán vị có thuộc nhóm hay không.
  bool membership_test(Permutation h) const {
    sift(h);
    return h.empty();
  }

  // Trả về kích thước của nhóm.
  long long size() const { return n ? next->size() * k : 1LL; }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  PermutationGroup group(n);
  // Đọc các hoán vị và thêm chúng vào nhóm.
  std::vector<int> vec(n);
  for (; m; --m) {
    for (int& x : vec) {
      std::cin >> x;
      --x;  // Chỉ số bắt đầu từ 0.
    }
    group.extend(Permutation(vec));
  }
  // In kích thước của nhóm.
  std::cout << group.size();
  return 0;
}
