# Vietnamese Translation

This fork translates **OI Wiki** into Vietnamese while keeping the upstream
MkDocs source layout intact.

## Current Scope

- `README.md`: translated and annotated for this fork.
- `docs/index.md`: translated landing page.
- `docs/intro/about.md`: translated project overview.
- `docs/contest/index.md`, `docs/lang/index.md`, `docs/basic/index.md`:
  translated section introductions.
- `docs/intro/what-oi-wiki-is-not.md`, `docs/intro/mirrors.md`,
  `docs/intro/thanks.md`: translated project policy and metadata pages.
- `docs/contest/problems.md`, `docs/contest/icpc.md`,
  `docs/contest/io.md`, `docs/contest/dictionary.md`,
  `docs/contest/common-tricks.md`: translated contest overview and technique
  pages.
- `docs/basic/complexity.md`, `docs/basic/amortized-analysis.md`,
  `docs/basic/enumerate.md`, `docs/basic/simulate.md`: translated basic
  algorithm foundation pages.
- `docs/basic/binary-lifting.md`, `docs/basic/construction.md`,
  `docs/basic/sort-intro.md`, `docs/basic/selection-sort.md`,
  `docs/basic/bubble-sort.md`, `docs/basic/insertion-sort.md`,
  `docs/basic/counting-sort.md`, `docs/basic/use-of-sort.md`: translated
  additional basic algorithm and sorting pages.
- `docs/basic/greedy.md`, `docs/basic/bucket-sort.md`,
  `docs/basic/heap-sort.md`, `docs/basic/tim-sort.md`,
  `docs/basic/tournament-sort.md`, `docs/basic/merge-sort.md`,
  `docs/basic/radix-sort.md`, `docs/basic/stl-sort.md`: translated more basic
  greedy and sorting pages.
- `docs/basic/divide-and-conquer.md`, `docs/basic/binary.md`,
  `docs/basic/prefix-sum.md`, `docs/basic/quick-sort.md`,
  `docs/basic/shell-sort.md`: translated the remaining medium-sized basic
  algorithm and sorting pages.
- `docs/contest/resources.md`, `docs/contest/roadmap.md`: translated learning
  resources and roadmap pages.
- `docs/intro/htc.md`, `docs/intro/faq.md`: translated contributor guide and
  FAQ, while preserving compatibility anchors for existing upstream links.
- `docs/contest/oi.md`, `docs/contest/common-mistakes.md`,
  `docs/intro/docker-deploy.md`, `docs/intro/symbol.md`: translated OI contest
  formats, common contest mistakes, Docker deployment instructions, and the
  mathematical symbol reference.
- `docs/contest/interaction.md`, `docs/contest/problemsetting.md`: translated
  the remaining contest pages on interactive problems and problem setting.
- `docs/lang/helloworld.md`, `docs/lang/struct.md`, `docs/lang/union.md`:
  translated the first beginner C++ language pages.
- `docs/lang/array.md`, `docs/lang/branch.md`, `docs/lang/loop.md`:
  translated beginner C++ array and control-flow pages.
- `docs/lang/basic.md`, `docs/lang/func.md`, `docs/lang/file-op.md`:
  translated beginner C++ syntax, function, and file-operation pages.
- `docs/lang/var.md`, `docs/lang/op.md`, `docs/lang/pointer.md`: translated
  beginner C++ variable, operator, and pointer pages.
- `docs/lang/namespace.md`, `docs/lang/reference.md`, `docs/lang/const.md`:
  translated C++ namespace, reference, and const/constexpr pages.
- `docs/lang/class.md`, `docs/lang/value-category.md`,
  `docs/lang/op-overload.md`: translated C++ class, value-category, and operator
  overloading pages.
- `docs/lang/new.md`, `docs/lang/lambda.md`,
  `docs/lang/cpp-other-langs.md`: translated modern C++ features, lambda
  expressions, and comparisons between C++ and other common languages.
- `docs/lang/pb-ds/index.md`, `docs/lang/pb-ds/pq.md`,
  `docs/lang/pb-ds/tree.md`, `docs/lang/optimizations.md`,
  `docs/lang/pas-cpp.md`: translated GNU pb_ds, compiler optimization, and
  Pascal-to-C++ transition pages.
- `docs/lang/python.md`, `docs/lang/java.md`, `docs/lang/java-pro.md`:
  translated Python and Java quick-start/advanced language pages.
- `docs/lang/csl/*.md`: translated the C++ standard-library/STL overview,
  container, iterator, algorithm, bitset, string, and pair pages.
- `docs/search/*.md`: translated the search algorithm pages, including DFS,
  BFS, bidirectional search, heuristic search, A*/IDA*, iterative deepening,
  backtracking, Dancing Links, Alpha-Beta pruning, and search optimization.
- `docs/dp/basic.md`, `docs/dp/memo.md`, `docs/dp/knapsack.md`,
  `docs/dp/interval.md`, `docs/dp/dag.md`, `docs/dp/tree.md`,
  `docs/dp/state.md`, `docs/dp/number.md`, `docs/dp/count.md`,
  `docs/dp/dynamic.md`, `docs/dp/probability.md`,
  `docs/dp/dp-of-dp.md`: translated the core dynamic-programming pages and
  explanatory code comments in their included snippets.
- Section introductions for search, dynamic programming, strings, mathematics,
  data structures, graph theory, computational geometry, and miscellaneous
  topics are translated.
- `mkdocs.yml`: Vietnamese project metadata and translated top-level
  navigation labels for translated sections and pages.

The rest of `docs/` is intentionally left in the upstream structure and should
be translated page by page.

## Translation Conventions

- "competitive programming" -> "lập trình thi đấu"; optionally add
  "(competitive programming)" near the first occurrence.
- "Olympiad in Informatics" -> "Olympic Tin học" or "Olympiad Tin học" based
  on context.
- "algorithm" -> "thuật toán".
- "data structure" -> "cấu trúc dữ liệu".
- "graph" -> "đồ thị".
- "dynamic programming" -> "quy hoạch động"; use "DP" after the first clear
  occurrence when the source uses DP heavily.
- "string" -> "xâu" in algorithmic contexts; use "chuỗi" only when it reads
  more naturally for programming-language discussion.
- "range query" -> "truy vấn đoạn".
- "segment tree" -> "cây phân đoạn (segment tree)" on first occurrence, then
  "cây phân đoạn".
- "binary search" -> "tìm kiếm nhị phân" or "chặt nhị phân" depending on
  context; prefer "tìm kiếm nhị phân" in headings and beginner pages.
- "sweep line" -> "đường quét (sweep line)" on first occurrence.
- Keep names of contests, online judges, libraries, programming languages,
  commands, file paths, and code identifiers unchanged unless the surrounding
  prose explicitly explains them.
- Preserve formulas, asymptotic notation, examples, admonitions, links,
  frontmatter keys, and MkDocs extension syntax.
- Use English in parentheses sparingly for terms readers are likely to search
  for in editorials or documentation.

## Workflow

1. Translate in place under the original file path so upstream changes remain
   easy to merge.
2. Keep each commit focused on a small group of related pages.
3. Run `mkdocs build -v` after structural changes or pages that touch
   frontmatter, navigation, admonitions, math, tabs, or custom HTML.
4. Do not mechanically translate code comments inside examples unless they are
   part of the explanation and the code remains valid.
5. Prefer concise Vietnamese prose over word-for-word Chinese or English
   sentence structure.

## Build

```bash
pip install uv
uv sync
./scripts/pre-build/install-theme.sh
uv run mkdocs build -v
```

The theme installation step downloads upstream theme resources, so it requires
network access.
