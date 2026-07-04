#include <cstdint>
#include <vector>
using i32 = int32_t;
using u32 = uint32_t;

class dsu {
  // Khi p[i] < 0, i là nút gốc và kích thước cây con tương ứng là -p[i]
  // Khi p[i] >= 0, i không phải nút gốc và chỉ số nút cha là p[i]
  std::vector<i32> p;

 public:
  // Các nút được đánh số từ 0 đến sz-1
  explicit dsu(u32 sz) : p(sz, -1) {}

  i32 find(u32 x) { return p[x] < 0 ? (i32)x : p[x] = find((u32)p[x]); }

  u32 size(u32 x) { return (u32)-p[(u32)find(x)]; }

  bool same_root(u32 x, u32 y) { return find(x) == find(y); }

  bool merge(u32 x, u32 y) {
    if ((x = (u32)find(x)) == (y = (u32)find(y))) return false;
    if (p[x] > p[y]) std::swap(x, y);  // Gộp theo heuristic
    p[x] += p[y], p[y] = (i32)x;
    return true;
  }
};
