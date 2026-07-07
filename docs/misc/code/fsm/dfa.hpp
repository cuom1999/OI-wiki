#ifndef DETERMINISTIC_FINITE_AUTOMATON
#define DETERMINISTIC_FINITE_AUTOMATON

#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>

// --8<-- [start:dfa]
// Ô-tô-mát hữu hạn đơn định (DFA)
struct DFA {
  int m;                                // Kích thước bảng chữ cái.
  int n;                                // Số trạng thái.
  int q0;                               // Trạng thái ban đầu.
  std::vector<std::vector<int>> trans;  // Chuyển trạng thái: trans[c][q].
  std::vector<int> acc;                 // Nhãn chấp nhận của từng trạng thái:
                                        // - 0 = không chấp nhận

  DFA(int m, int n = 0, int q0 = 0)
      : m(m), n(n), q0(q0), trans(m, std::vector<int>(n)), acc(n) {}

  // Trả về DFA tối thiểu hóa bằng thuật toán Hopcroft.
  DFA hopcroft_minimize() const;
};

// --8<-- [end:dfa]
// --8<-- [start:hopcroft]
// Tối thiểu hóa DFA bằng thuật toán Hopcroft.
// Độ phức tạp: O(n * m * log(n)).
DFA DFA::hopcroft_minimize() const {
  // Xây dựng các ánh xạ chuyển ngược:
  // - pre[c] lưu các trạng thái được sắp theo đích của chuyển c.
  // - pos[c][s] là chỉ số bắt đầu trong pre[c] của các chuyển đi tới trạng thái s.
  std::vector<std::vector<int>> pre(m), pos(m);
  for (int c = 0; c < m; ++c) {
    pre[c].assign(n, 0);
    pos[c].assign(n + 1, 0);
    // Sắp xếp đếm.
    for (int i = 0; i < n; ++i) ++pos[c][trans[c][i]];
    for (int i = 0; i < n; ++i) pos[c][i + 1] += pos[c][i];
    for (int i = 0; i < n; ++i) pre[c][--pos[c][trans[c][i]]] = i;
  }

  // Cấu trúc phần tử của phép chia:
  // - os: chỉ số bắt đầu trong danh sách trạng thái.
  // - sz: số trạng thái trong lớp này.
  // - cnt: số trạng thái được đánh dấu tạm thời trong quá trình tinh chỉnh.
  struct EquivClasses {
    int os, sz, cnt;

    EquivClasses(int os, int sz, int cnt) : os(os), sz(sz), cnt(cnt) {}
  };

  // Phép chia và các cấu trúc dữ liệu phụ trợ.
  std::vector<EquivClasses> ec;  // Danh sách lớp tương đương hiện tại.
  std::vector<int> ids(n);       // Hoán vị các trạng thái, được nhóm theo lớp tương đương.
  std::vector<int> par(n);       // Ánh xạ trạng thái tới chỉ số lớp tương đương.
  std::vector<bool> tag(n);      // Đánh dấu tạm thời để tách lớp.
  std::queue<int> evidences;     // Danh sách lớp tương đương cần kiểm tra.

  // Chia ban đầu theo nhãn chấp nhận.
  std::iota(ids.begin(), ids.end(), 0);
  std::sort(ids.begin(), ids.end(),
            [&](int l, int r) { return acc[l] < acc[r]; });
  for (int l = 0, r; l < n; l = r) {
    for (r = l; r < n && acc[ids[r]] == acc[ids[l]]; ++r)
      par[ids[r]] = ec.size();
    if (l) evidences.push(ec.size());  // Đưa mọi lớp trừ lớp đầu tiên vào danh sách chờ.
    ec.emplace_back(l, r - l, 0);
  }

  // Vòng lặp tinh chỉnh.
  while (!evidences.empty()) {
    int cr = evidences.front();
    evidences.pop();
    for (int c = 0; c < m; ++c) {
      std::vector<int> todo;
      for (int i = ec[cr].os; i < ec[cr].os + ec[cr].sz; ++i) {
        for (int k = pos[c][ids[i]]; k < pos[c][ids[i] + 1]; ++k) {
          int j = pre[c][k];
          if (!tag[j]) {
            if (!ec[par[j]].cnt) todo.push_back(par[j]);
            ++ec[par[j]].cnt;
            tag[j] = true;
          }
        }
      }
      // Thực hiện tách lớp.
      for (int i : todo) {
        int ti = i;
        if (ec[i].cnt != ec[i].sz) {
          // Tách thành hai phần: đoạn lớn hơn và đoạn nhỏ hơn.
          bool majority_tagged = ec[i].cnt * 2 >= ec[i].sz;
          int mid =
              std::partition(ids.begin() + ec[i].os,
                             ids.begin() + ec[i].os + ec[i].sz,
                             [&](int x) { return tag[x] == majority_tagged; }) -
              ids.begin() - ec[i].os;

          // Gán chỉ số lớp tương đương mới cho đoạn nhỏ hơn.
          for (int j = ec[i].os + mid; j < ec[i].os + ec[i].sz; ++j)
            par[ids[j]] = ec.size();

          evidences.push(ec.size());
          if (!majority_tagged) ti = ec.size();
          ec.emplace_back(ec[i].os + mid, ec[i].sz - mid, 0);
          ec[i].sz = mid;
        }
        // Xóa bộ đếm và đánh dấu tạm thời.
        ec[i].cnt = 0;
        for (int j = ec[ti].os; j < ec[ti].os + ec[ti].sz; ++j)
          tag[ids[j]] = false;
      }
    }
  }

  // Xây dựng DFA đã tối thiểu hóa.
  DFA res(m, ec.size(), par[q0]);
  for (const auto& e : ec) {
    int i = ids[e.os];  // Trạng thái đại diện.
    res.acc[par[i]] = acc[i];
    for (int c = 0; c < m; ++c) res.trans[c][par[i]] = par[trans[c][i]];
  }
  return res;
}

// --8<-- [end:hopcroft]

#endif  // DETERMINISTIC_FINITE_AUTOMATON
